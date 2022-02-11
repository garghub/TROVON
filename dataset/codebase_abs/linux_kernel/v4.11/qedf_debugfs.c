void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
char V_7 [ 32 ] ;
struct V_8 * V_9 = NULL ;
F_2 ( V_2 , V_10 , L_1 ) ;
sprintf ( V_7 , L_2 , V_2 -> V_11 ) ;
V_2 -> V_12 = F_3 ( V_7 , V_13 ) ;
if ( ! V_2 -> V_12 )
return;
while ( V_4 ) {
if ( ! ( V_4 -> V_14 ) )
break;
V_9 = F_4 ( V_4 -> V_14 , 0600 ,
V_2 -> V_12 , V_2 ,
V_6 ) ;
if ( ! V_9 ) {
F_2 ( V_2 , V_10 ,
L_3 ,
V_4 -> V_14 ) ;
F_5 ( V_2 -> V_12 ) ;
return;
}
V_4 ++ ;
V_6 ++ ;
}
}
void
F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_10 , L_4
L_5 ) ;
F_5 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
void
F_7 ( char * V_15 )
{
F_2 ( NULL , V_10 , L_6 ) ;
V_13 = F_3 ( V_15 , NULL ) ;
if ( ! V_13 )
F_2 ( NULL , V_10 , L_7
L_8 ) ;
}
void
F_8 ( void )
{
F_2 ( NULL , V_10 , L_9
L_5 ) ;
F_5 ( V_13 ) ;
V_13 = NULL ;
}
static T_1
F_9 ( struct V_16 * V_17 , char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
T_3 V_21 = 0 ;
int V_22 ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_25 =
(struct V_1 * ) V_17 -> V_26 ;
struct V_27 * V_2 = F_10 ( V_25 ,
struct V_27 , V_28 ) ;
F_2 ( V_25 , V_10 , L_10 ) ;
V_21 = sprintf ( V_18 , L_11 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_29 ; V_22 ++ ) {
V_24 = & ( V_2 -> V_30 [ V_22 ] ) ;
if ( V_24 -> V_31 == V_32 )
continue;
V_21 += sprintf ( ( V_18 + V_21 ) , L_12 , V_22 ,
V_24 -> V_33 ) ;
}
V_21 = F_11 ( int , V_19 , V_21 - * V_20 ) ;
* V_20 += V_21 ;
return V_21 ;
}
static T_1
F_12 ( struct V_16 * V_17 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
if ( ! V_19 || * V_20 )
return 0 ;
return V_19 ;
}
static T_1
F_13 ( struct V_16 * V_17 , char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
int V_21 ;
struct V_1 * V_2 =
(struct V_1 * ) V_17 -> V_26 ;
F_2 ( V_2 , V_10 , L_10 ) ;
V_21 = sprintf ( V_18 , L_13 , V_34 ) ;
V_21 = F_11 ( int , V_19 , V_21 - * V_20 ) ;
* V_20 += V_21 ;
return V_21 ;
}
static T_1
F_14 ( struct V_16 * V_17 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
T_5 V_35 ;
void * V_36 ;
int V_37 ;
struct V_1 * V_2 =
(struct V_1 * ) V_17 -> V_26 ;
if ( ! V_19 || * V_20 )
return 0 ;
V_36 = F_15 ( V_18 , V_19 ) ;
if ( F_16 ( V_36 ) )
return F_17 ( V_36 ) ;
V_37 = F_18 ( V_36 , 10 , & V_35 ) ;
F_19 ( V_36 ) ;
if ( V_37 )
return V_37 ;
if ( V_35 == 1 )
V_34 = V_38 ;
else
V_34 = V_35 ;
F_2 ( V_2 , V_10 , L_14 , V_35 ) ;
return V_19 ;
}
static T_1
F_20 ( struct V_16 * V_17 , char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
int V_21 ;
struct V_1 * V_25 =
(struct V_1 * ) V_17 -> V_26 ;
struct V_27 * V_2 = F_10 ( V_25 ,
struct V_27 , V_28 ) ;
F_2 ( V_25 , V_10 , L_10 ) ;
V_21 = sprintf ( V_18 , L_15 ,
V_2 -> V_39 ? L_16 : L_17 ) ;
V_21 = F_11 ( int , V_19 , V_21 - * V_20 ) ;
* V_20 += V_21 ;
return V_21 ;
}
static T_1
F_21 ( struct V_16 * V_17 ,
const char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
void * V_36 ;
struct V_1 * V_25 =
(struct V_1 * ) V_17 -> V_26 ;
struct V_27 * V_2 = F_10 ( V_25 , struct V_27 ,
V_28 ) ;
F_2 ( V_25 , V_10 , L_10 ) ;
if ( ! V_19 || * V_20 )
return 0 ;
V_36 = F_15 ( V_18 , 6 ) ;
if ( F_16 ( V_36 ) )
return F_17 ( V_36 ) ;
if ( strncmp ( V_36 , L_17 , 5 ) == 0 )
V_2 -> V_39 = false ;
else if ( strncmp ( V_36 , L_16 , 4 ) == 0 )
V_2 -> V_39 = true ;
else if ( strncmp ( V_36 , L_18 , 3 ) == 0 )
F_22 ( V_40 , & V_2 -> V_41 ) ;
F_19 ( V_36 ) ;
return V_19 ;
}
static int
F_23 ( struct V_42 * V_43 , void * V_44 )
{
int V_45 , V_46 = 0 ;
struct V_27 * V_2 = V_43 -> V_47 ;
struct V_1 * V_25 = & V_2 -> V_28 ;
struct V_48 * V_49 ;
unsigned long V_41 ;
if ( ! V_50 ) {
F_24 ( V_43 , L_19 ) ;
goto V_51;
}
F_2 ( V_25 , V_10 , L_10 ) ;
F_25 ( & V_2 -> V_52 , V_41 ) ;
V_46 = V_2 -> V_53 ;
for ( V_45 = 0 ; V_45 < V_54 ; V_45 ++ ) {
V_49 = & V_2 -> V_55 [ V_46 ] ;
F_26 ( V_43 , L_20 , V_49 -> V_56 ) ;
F_26 ( V_43 , L_21 , V_49 -> V_57 ) ;
F_26 ( V_43 , L_22 , V_49 -> V_58 ) ;
F_26 ( V_43 , L_20 , V_49 -> V_59 ) ;
F_26 ( V_43 , L_23 , V_49 -> V_60 ) ;
F_26 ( V_43 , L_24 , V_49 -> V_61 [ 0 ] ,
V_49 -> V_61 [ 1 ] , V_49 -> V_61 [ 2 ] , V_49 -> V_61 [ 3 ] ) ;
F_26 ( V_43 , L_20 , V_49 -> V_62 ) ;
F_26 ( V_43 , L_20 , V_49 -> V_63 ) ;
F_26 ( V_43 , L_25 , V_49 -> V_64 ) ;
F_26 ( V_43 , L_26 , V_49 -> V_65 ) ;
F_26 ( V_43 , L_20 , V_49 -> V_66 ) ;
F_26 ( V_43 , L_20 , V_49 -> V_67 ) ;
F_26 ( V_43 , L_20 , V_49 -> V_68 ) ;
F_26 ( V_43 , L_20 , V_49 -> V_69 ) ;
F_26 ( V_43 , L_27 , V_49 -> V_70 ) ;
V_46 ++ ;
if ( V_46 == V_54 )
V_46 = 0 ;
}
F_27 ( & V_2 -> V_52 , V_41 ) ;
V_51:
return 0 ;
}
static int
F_28 ( struct V_71 * V_71 , struct V_16 * V_16 )
{
struct V_1 * V_25 = V_71 -> V_72 ;
struct V_27 * V_2 = F_10 ( V_25 ,
struct V_27 , V_28 ) ;
return F_29 ( V_16 , F_23 , V_2 ) ;
}
static int
F_30 ( struct V_42 * V_43 , void * V_44 )
{
struct V_27 * V_2 = V_43 -> V_47 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_26 ( V_43 , L_28 ,
F_31 ( & V_2 -> V_77 -> V_78 ) ) ;
F_26 ( V_43 , L_29 , V_2 -> V_79 ) ;
F_26 ( V_43 , L_30 , V_2 -> V_80 ) ;
F_26 ( V_43 , L_31 , V_2 -> V_81 ) ;
F_24 ( V_43 , L_32 ) ;
F_32 () ;
F_33 (fcport, &qedf->fcports, peers) {
V_76 = V_74 -> V_76 ;
if ( V_76 == NULL )
continue;
F_26 ( V_43 , L_33 ,
V_76 -> V_82 . V_58 , F_31 ( & V_74 -> V_83 ) ,
F_31 ( & V_74 -> V_84 ) ) ;
}
F_34 () ;
return 0 ;
}
static int
F_35 ( struct V_71 * V_71 , struct V_16 * V_16 )
{
struct V_1 * V_25 = V_71 -> V_72 ;
struct V_27 * V_2 = F_10 ( V_25 ,
struct V_27 , V_28 ) ;
return F_29 ( V_16 , F_30 , V_2 ) ;
}
static T_1
F_36 ( struct V_16 * V_17 , char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
int V_21 = 0 ;
V_21 = F_11 ( int , V_19 , V_21 - * V_20 ) ;
* V_20 += V_21 ;
return V_21 ;
}
static T_1
F_37 ( struct V_16 * V_17 ,
const char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
struct V_1 * V_25 =
(struct V_1 * ) V_17 -> V_26 ;
struct V_27 * V_2 = F_10 ( V_25 , struct V_27 ,
V_28 ) ;
F_2 ( V_25 , V_10 , L_34 ) ;
if ( ! V_19 || * V_20 )
return 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_80 = 0 ;
V_2 -> V_81 = 0 ;
return V_19 ;
}
static int
F_38 ( struct V_42 * V_43 , void * V_44 )
{
struct V_27 * V_2 = V_43 -> V_47 ;
struct V_85 * V_86 ;
V_86 = F_39 ( sizeof( struct V_85 ) , V_87 ) ;
if ( ! V_86 ) {
F_40 ( & ( V_2 -> V_28 ) , L_35
L_36 ) ;
goto V_51;
}
V_88 -> V_89 ( V_2 -> V_90 , V_86 ) ;
F_26 ( V_43 , L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49 ,
V_86 -> V_91 ,
V_86 -> V_92 ,
V_86 -> V_93 ,
V_86 -> V_94 ,
V_86 -> V_95 ,
V_86 -> V_96 ,
V_86 -> V_97 ,
V_86 -> V_98 ,
V_86 -> V_99 ,
V_86 -> V_100 ,
V_86 -> V_101 ,
V_86 -> V_102 ,
V_86 -> V_103 ) ;
F_19 ( V_86 ) ;
V_51:
return 0 ;
}
static int
F_41 ( struct V_71 * V_71 , struct V_16 * V_16 )
{
struct V_1 * V_25 = V_71 -> V_72 ;
struct V_27 * V_2 = F_10 ( V_25 ,
struct V_27 , V_28 ) ;
return F_29 ( V_16 , F_38 , V_2 ) ;
}
