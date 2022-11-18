typedef struct hospital Hospital;

Hospital* hospital_sistema(void);

typedef struct lista Lista;

typedef struct fila Fila;

Fila* fila_cria(void);

void cadastra_pacientes(Fila * f);

void paciente_prioritario(Fila * f);

void exclui_pacientes(Fila* f);

void imprime_pacientes(Fila *f);

void busca_pacientes(Fila *f);

void edita_pacientes(Fila *f);

void vagas_leitos(Fila *f, Hospital *H);

void quantidade_pacientes(Fila *f);

void fila_libera(Fila *f);

int fila_vazia(Fila *f);

void ordena(Fila* f);