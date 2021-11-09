void insertCourse(struct Queue *queue);
void insertClass(struct Queue *queue);
void insertProfessor(struct Queue *queue);
void insertSubject(struct Queue *queue);
void insertClassroomCode(struct Queue *queue);
void insertProfSubject(struct Queue *queue, int subjectId, char *professorId);
void insertProfCourse(struct Queue *queue, int courseId, char *professorId);