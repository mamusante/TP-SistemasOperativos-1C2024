#ifndef PCB_H_
#define PCB_H_

#include "cpu_gestor.h"
#include "direccion.h"
#include "../../entradasalida/src/io_gestor.h"

typedef enum
{
	I_SET,
	I_MOV_IN,
	I_MOV_OUT,
    I_SUM,
    I_SUB,
    I_JNZ,
    I_RESIZE,
    I_COPY_STRING,
    I_WAIT,
    I_SIGNAL,
	I_IO_GEN_SLEEP,
    I_IO_STDIN_READ,
    I_IO_STDOUT_WRITE,
    I_IO_FS_CREATE,
    I_IO_FS_DELETE,
    I_IO_FS_TRUNCATE,
    I_IO_FS_WRITE,
    I_IO_FS_READ,
	I_EXIT
}enum_instrucciones;

// Ver que mas le falta a la estructura de instrucciones 
typedef struct 
{
    int pid;
    char* instruccion;
    int tamanio;
} t_instruccion;

void recibir_pcb(t_buffer* buffer, pcb** pcb_recibido);
void enviar_pcb(int conexion, pcb *proceso, op_code codigo, char* recurso);
// void recibir_instruccion(t_list *paquete, t_instruccion *proceso);

void iniciar_diccionario_instrucciones(void);
void iniciar_diccionario_registros(registros_cpu* registro);
void destruir_diccionarios(void); 
void interpretar_instruccion_de_memoria(t_buffer* buffer);

void instruccion_set(char **parte);
void instruccion_mov_in (char **parte);
void generar_instruccion(pcb* proceso, t_instruccion* instruccion_proceso, char* instruccion);
void instruccion_mov_out (char **parte);
void instruccion_sum(char **parte);
void instruccion_sub(char **parte);
void instruccion_jnz(char **parte);
void instruccion_resize(char **parte);
void instruccion_copy_string(char **parte);
void instruccion_io_gen_sleep(char **parte);
void solicitar_sleep_io(const char *interfaz, int unidades_trabajo, int pid);
void intruccion_io_fs_create(char **parte);
void intruccion_io_fs_delete(char **parte);
void intruccion_io_fs_truncate(char **parte);
void intruccion_io_fs_write(char **parte);
void intruccion_io_fs_read(char **parte);
void instruccion_io_stdin_read(char** parte);
void instruccion_io_stdout_write(char** parte); 
void instruccion_exit(char** parsed); 
void instruccion_wait(char** parte);
void instruccion_signal(char **parte);

void error_exit(char** parte);
void solicitar_instrucciones_a_memoria(int socket_cliente_cpu, pcb** pcb_recibido); 
// void recibir_instruccion_de_memoria(int socket_servidor_memoria);
void enviar_instruccion(int conexion, t_instruccion* instruccion, op_code codigo);
int copiar_bytes(uint32_t direccion_origen, uint32_t direccion_destino, int tamanio);

#endif