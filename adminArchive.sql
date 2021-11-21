INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Ciencia da Computacao',8,1);
INSERT INTO `subjects` (`id`,`name`,`period`) VALUES (NULL,'PIF',2);
INSERT INTO `professor` (`id`,`name`,`slack`,`email`,`whatsapp`,`contact`) VALUES (NULL,'Pamela','@pamela','pamela@cesar.school','81999999999',1);
INSERT INTO `professor_course` (`id`,`professor_id`,`course_id`) VALUES (NULL,1,1);
INSERT INTO `professor_class` (`id`,`professor_id`,`subject_id`) VALUES (NULL,1,1);
INSERT INTO `professor_periods` (`id`,`professor_id`,`periods`) VALUES (NULL,1,2);
INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (NULL,1,2,'https://cesar.zoom.us/j/4937670523');
INSERT INTO `classroom_code` (`id`,`subject_id`,`class_id`,`classroom_id`) VALUES (NULL,1,1,'PIF#123');
