Данная программа является моей выпускной квалификационной работой. Тема работы: "Информационная система для создания и архивации документов, необходимых для процедуры 
аккредитации". В современном мире работа с документами играет важную роль во многих сферах деятельности, особенно в высших учебных заведениях. При прохождении вузом процедуры 
аккредитации проверке подлежит огромное количество документов. При их подготовке становится очень удобным держать их всех в одном месте. 

Так целью работы является разработка прикладного программного обеспечения, предназначенного для:
•	автоматизации процесса управления документооборотом;
•	учета и хранения документов;
•	поиска необходимых документов в единой базе.
Автоматизации подлежат операции добавления документов, удаления и создания новых документов по шаблону. Также предусмотрена функция архивации данных.

При написании данной работы использовались следующие программные средства: 
•	Visual Studio.  В данной работе используется для написания функционала разрабатываемого приложения. 
•	Qt Designer. Он используется для написания  графического интерфейса пользователя, то есть для создания графической оболочки управления приложением.

Структура системы состоит из 2 модулей:
•	Модуль приложения представляет собой программу на базе платформы Windows с пользовательским интерфейсом для обмена данными между пользователем и СУБД.
•	Модуль хранения данных (СУБД) представляет собой сервер реляционной базы данных MySQL, который осуществляет хранение и передачу данных в приложение.

Функционал разработанного приложения разбивается на 3 части:
1)	Функционал главного окна представляет собой:
    •	описание главной таблицы приложения, куда выводятся все документы, т.е. информация о них: имя документа, тип, дата добавления и путь.
    •	описание всех кнопок, расположенных в главном окне, таких как открыть документ, удалить, добавить в архив и т.д.
    •	описание функций добавления и изменения данных в главной таблице.
2)	Функционал окна создания по шаблону представляет собой описание кнопок, имеющихся в данном окне, описания функций добавления новых типов документов и новых шаблонов,
    а также описание формирования структуры с выбранными пользователем данными при создании нового документа.
3)	Функционал окна добавления представляет собой также описание работы кнопок окна добавления и описания формирования структуры с данными, введенными пользователем при 
    добавлении нового документа.


Там то представлены скрины разработанного приложения. Для наглядности приложения при наведении мыши на кнопки они меняют цвет, то же происходит и при нажатии на строку в 
главной таблице. Для открытия файла пользователю достаточно лишь выбрать строку с документом и нажать на соответствующую кнопку «Открыть». Точно также дело обстоит с кнопками
удалить и добавить в архив, при этом, когда пользователь добавляет документ в архив, запись с этим документом удаляется из главной таблицы, а сам документ помещается в общий 
архив. 
Для осуществления поиска пользователю достаточно будет ввести в специальное поле искомое слово или его часть и нажать на кнопку «Поиск». После этого главная таблица обновится, 
и в ней будут выведены только найденные строки.
Пользователю предоставлена возможность редактировать данные о документе в главной таблице. Для этого ему нужно выбрать нужное поле двойным нажатием мыши, отредактировать данные 
и нажать на кнопку «Изменить». При этом если пользователь отредактировал данные в строке, но не нажал на кнопку изменить, введенные данные не сохраняться. Такой подход позволяет
избежать случайных ошибок.

Для создания нового документа пользователь должен нажать на кнопку «Создать по шаблону», расположенную в главном окне. После этого он должен   выбрать шаблон из выпадающего 
списка, который он будет использовать, выбрать тип, который будет присвоен документу и ввести имя создаваемого документа. При этом предусмотрена возможность добавления новых 
шаблонов и типов документов с помощью кнопок, расположенных справа от выпадающих списков.

Для добавления документа пользователь должен нажать на кнопку «Добавить», расположенную в главном окне. Далее он должен выбрать тип документа, после чего выбрать сам документ 
посредством специальной кнопки. После нажатия на кнопку «ОК» создается структура с введенными пользователем данными, которая передается в главное окно. Затем в главной таблице 
появляется строка с новым документом. 

Таким образом, полученное приложение позволяет оперативно осуществлять работу с документами. Использование такого приложения может облегчить сотрудникам ВУЗа работу с большим 
количеством документов, а при процедуре аккредитации ускорить поиск и предоставление комиссии необходимых документов. 



