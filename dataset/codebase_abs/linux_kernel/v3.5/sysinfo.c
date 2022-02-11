static inline int F_1 ( void )
{
int V_1 = F_2 ( NULL , 0 , 0 , 0 ) ;
return V_1 == - V_2 ? V_1 : ( ( ( unsigned int ) V_1 ) >> 28 ) ;
}
static int F_3 ( struct V_3 * V_4 , char * V_5 , int V_6 )
{
if ( F_2 ( V_4 , 1 , 1 , 1 ) == - V_2 )
return V_6 ;
F_4 ( V_4 -> V_7 , sizeof( V_4 -> V_7 ) ) ;
F_4 ( V_4 -> type , sizeof( V_4 -> type ) ) ;
F_4 ( V_4 -> V_8 , sizeof( V_4 -> V_8 ) ) ;
F_4 ( V_4 -> V_9 , sizeof( V_4 -> V_9 ) ) ;
F_4 ( V_4 -> V_10 , sizeof( V_4 -> V_10 ) ) ;
F_4 ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ) ;
F_4 ( V_4 -> V_12 , sizeof( V_4 -> V_12 ) ) ;
F_4 ( V_4 -> V_13 , sizeof( V_4 -> V_13 ) ) ;
V_6 += sprintf ( V_5 + V_6 , L_1 ,
V_4 -> V_7 ) ;
V_6 += sprintf ( V_5 + V_6 , L_2 ,
V_4 -> type ) ;
if ( V_4 -> V_8 [ 0 ] != '\0' )
V_6 += sprintf ( V_5 + V_6 ,
L_3 ,
V_4 -> V_11 , V_4 -> V_8 ) ;
else
V_6 += sprintf ( V_5 + V_6 , L_4 ,
V_4 -> V_11 ) ;
V_6 += sprintf ( V_5 + V_6 , L_5 ,
V_4 -> V_9 ) ;
V_6 += sprintf ( V_5 + V_6 , L_6 ,
V_4 -> V_10 ) ;
V_6 += sprintf ( V_5 + V_6 , L_7 ,
V_4 -> V_11 , * ( V_14 * ) V_4 -> V_15 ) ;
if ( V_4 -> V_12 [ 0 ] != '\0' )
V_6 += sprintf ( V_5 + V_6 ,
L_8 ,
V_4 -> V_12 ,
* ( V_14 * ) V_4 -> V_16 ) ;
if ( V_4 -> V_13 [ 0 ] != '\0' )
V_6 += sprintf ( V_5 + V_6 ,
L_9 ,
V_4 -> V_13 ,
* ( V_14 * ) V_4 -> V_17 ) ;
if ( V_4 -> V_18 ) {
V_6 += sprintf ( V_5 + V_6 ,
L_10 ,
V_4 -> V_18 ) ;
V_6 += sprintf ( V_5 + V_6 , L_11 ,
V_4 -> V_19 ) ;
}
return V_6 ;
}
static int F_5 ( struct V_20 * V_4 , char * V_5 , int V_6 )
{
static int V_21 ;
int V_22 , V_1 ;
V_6 += sprintf ( V_5 + V_6 , L_12 ) ;
if ( ! V_23 )
return V_6 ;
if ( V_21 ) {
F_2 ( V_4 , 15 , 1 , V_21 ) ;
} else {
for ( V_21 = 6 ; V_21 > 1 ; V_21 -- ) {
V_1 = F_2 ( V_4 , 15 , 1 , V_21 ) ;
if ( V_1 != - V_2 )
break;
}
}
V_6 += sprintf ( V_5 + V_6 , L_13 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ )
V_6 += sprintf ( V_5 + V_6 , L_14 , V_4 -> V_25 [ V_22 ] ) ;
V_6 += sprintf ( V_5 + V_6 , L_12 ) ;
#ifdef F_6
F_7 ( V_4 ) ;
V_6 += sprintf ( V_5 + V_6 , L_15 ) ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ )
V_6 += sprintf ( V_5 + V_6 , L_14 , V_4 -> V_25 [ V_22 ] ) ;
V_6 += sprintf ( V_5 + V_6 , L_12 ) ;
#endif
return V_6 ;
}
static int F_8 ( struct V_26 * V_4 , char * V_5 , int V_6 )
{
struct V_27 * V_28 ;
int V_22 ;
if ( F_2 ( V_4 , 1 , 2 , 2 ) == - V_2 )
return V_6 ;
V_28 = (struct V_27 * )
( ( unsigned long ) V_4 + V_4 -> V_29 ) ;
V_6 += sprintf ( V_5 + V_6 , L_16 ,
V_4 -> V_30 ) ;
V_6 += sprintf ( V_5 + V_6 , L_17 ,
V_4 -> V_31 ) ;
V_6 += sprintf ( V_5 + V_6 , L_18 ,
V_4 -> V_32 ) ;
V_6 += sprintf ( V_5 + V_6 , L_19 ,
V_4 -> V_33 ) ;
if ( V_4 -> V_34 == 1 ) {
V_6 += sprintf ( V_5 + V_6 , L_20 ,
V_4 -> V_35 , V_28 -> V_36 ) ;
for ( V_22 = 2 ; V_22 <= V_4 -> V_30 ; V_22 ++ )
V_6 += sprintf ( V_5 + V_6 ,
L_21 ,
V_22 , V_4 -> V_37 [ V_22 - 2 ] ,
V_28 -> V_38 [ V_22 - 2 ] ) ;
} else {
V_6 += sprintf ( V_5 + V_6 , L_22 ,
V_4 -> V_35 ) ;
for ( V_22 = 2 ; V_22 <= V_4 -> V_30 ; V_22 ++ )
V_6 += sprintf ( V_5 + V_6 ,
L_23 ,
V_22 , V_4 -> V_37 [ V_22 - 2 ] ) ;
}
if ( V_4 -> V_39 != 0 )
V_6 += sprintf ( V_5 + V_6 , L_24 ,
V_4 -> V_39 ) ;
return V_6 ;
}
static int F_9 ( struct V_40 * V_4 , char * V_5 , int V_6 )
{
if ( F_2 ( V_4 , 2 , 2 , 2 ) == - V_2 )
return V_6 ;
F_4 ( V_4 -> V_41 , sizeof( V_4 -> V_41 ) ) ;
V_6 += sprintf ( V_5 + V_6 , L_12 ) ;
V_6 += sprintf ( V_5 + V_6 , L_25 ,
V_4 -> V_42 ) ;
V_6 += sprintf ( V_5 + V_6 , L_26 ) ;
if ( V_4 -> V_43 & V_44 )
V_6 += sprintf ( V_5 + V_6 , L_27 ) ;
if ( V_4 -> V_43 & V_45 )
V_6 += sprintf ( V_5 + V_6 , L_28 ) ;
if ( V_4 -> V_43 & V_46 )
V_6 += sprintf ( V_5 + V_6 , L_29 ) ;
V_6 += sprintf ( V_5 + V_6 , L_12 ) ;
V_6 += sprintf ( V_5 + V_6 , L_30 ,
V_4 -> V_41 ) ;
V_6 += sprintf ( V_5 + V_6 , L_31 ,
V_4 -> V_47 ) ;
V_6 += sprintf ( V_5 + V_6 , L_32 ,
V_4 -> V_30 ) ;
V_6 += sprintf ( V_5 + V_6 , L_33 ,
V_4 -> V_31 ) ;
V_6 += sprintf ( V_5 + V_6 , L_34 ,
V_4 -> V_32 ) ;
V_6 += sprintf ( V_5 + V_6 , L_35 ,
V_4 -> V_33 ) ;
V_6 += sprintf ( V_5 + V_6 , L_36 ,
V_4 -> V_48 ) ;
V_6 += sprintf ( V_5 + V_6 , L_37 ,
V_4 -> V_49 ) ;
return V_6 ;
}
static int F_10 ( struct V_50 * V_4 , char * V_5 , int V_6 )
{
int V_22 ;
if ( F_2 ( V_4 , 3 , 2 , 2 ) == - V_2 )
return V_6 ;
for ( V_22 = 0 ; V_22 < V_4 -> V_51 ; V_22 ++ ) {
F_4 ( V_4 -> V_52 [ V_22 ] . V_41 , sizeof( V_4 -> V_52 [ V_22 ] . V_41 ) ) ;
F_4 ( V_4 -> V_52 [ V_22 ] . V_53 , sizeof( V_4 -> V_52 [ V_22 ] . V_53 ) ) ;
V_6 += sprintf ( V_5 + V_6 , L_12 ) ;
V_6 += sprintf ( V_5 + V_6 , L_38 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_41 ) ;
V_6 += sprintf ( V_5 + V_6 , L_39 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_53 ) ;
V_6 += sprintf ( V_5 + V_6 , L_40 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_47 ) ;
V_6 += sprintf ( V_5 + V_6 , L_41 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_30 ) ;
V_6 += sprintf ( V_5 + V_6 , L_42 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_31 ) ;
V_6 += sprintf ( V_5 + V_6 , L_43 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_32 ) ;
V_6 += sprintf ( V_5 + V_6 , L_44 ,
V_22 , V_4 -> V_52 [ V_22 ] . V_33 ) ;
}
return V_6 ;
}
static int F_11 ( char * V_5 , char * * V_54 ,
T_1 V_55 , int V_51 ,
int * V_56 , void * V_57 )
{
unsigned long V_4 = F_12 ( V_58 ) ;
int V_59 , V_6 ;
if ( ! V_4 )
return 0 ;
V_6 = 0 ;
V_59 = F_1 () ;
if ( V_59 >= 1 )
V_6 = F_3 ( (struct V_3 * ) V_4 , V_5 , V_6 ) ;
if ( V_59 >= 1 )
V_6 = F_5 ( (struct V_20 * ) V_4 , V_5 , V_6 ) ;
if ( V_59 >= 1 )
V_6 = F_8 ( (struct V_26 * ) V_4 , V_5 , V_6 ) ;
if ( V_59 >= 2 )
V_6 = F_9 ( (struct V_40 * ) V_4 , V_5 , V_6 ) ;
if ( V_59 >= 3 )
V_6 = F_10 ( (struct V_50 * ) V_4 , V_5 , V_6 ) ;
F_13 ( V_4 ) ;
return V_6 ;
}
static T_2 int F_14 ( void )
{
F_15 ( L_45 , 0444 , NULL ,
F_11 , NULL ) ;
return 0 ;
}
int F_16 ( struct V_60 * V_61 )
{
struct V_60 * V_62 ;
F_17 ( & V_63 ) ;
F_18 (ptr, &service_level_list, list)
if ( V_62 == V_61 ) {
F_19 ( & V_63 ) ;
return - V_64 ;
}
F_20 ( & V_61 -> V_65 , & V_66 ) ;
F_19 ( & V_63 ) ;
return 0 ;
}
int F_21 ( struct V_60 * V_61 )
{
struct V_60 * V_62 , * V_67 ;
int V_1 = - V_68 ;
F_17 ( & V_63 ) ;
F_22 (ptr, next, &service_level_list, list) {
if ( V_62 != V_61 )
continue;
F_23 ( & V_62 -> V_65 ) ;
V_1 = 0 ;
break;
}
F_19 ( & V_63 ) ;
return V_1 ;
}
static void * F_24 ( struct V_69 * V_70 , T_3 * V_71 )
{
F_25 ( & V_63 ) ;
return F_26 ( & V_66 , * V_71 ) ;
}
static void * F_27 ( struct V_69 * V_70 , void * V_72 , T_3 * V_71 )
{
return F_28 ( V_72 , & V_66 , V_71 ) ;
}
static void F_29 ( struct V_69 * V_70 , void * V_72 )
{
F_30 ( & V_63 ) ;
}
static int F_31 ( struct V_69 * V_70 , void * V_72 )
{
struct V_60 * V_61 ;
V_61 = F_32 ( V_72 , struct V_60 , V_65 ) ;
V_61 -> V_73 ( V_70 , V_61 ) ;
return 0 ;
}
static int F_33 ( struct V_74 * V_74 , struct V_75 * V_75 )
{
return F_34 ( V_75 , & V_76 ) ;
}
static void F_35 ( struct V_69 * V_70 ,
struct V_60 * V_61 )
{
char * V_77 , * V_78 ;
V_77 = F_36 ( 1024 , V_58 | V_79 ) ;
if ( ! V_77 )
return;
F_37 ( L_46 , V_77 , 1024 , NULL ) ;
V_78 = strchr ( V_77 , '\n' ) ;
if ( V_78 )
* V_78 = 0 ;
F_38 ( V_70 , L_47 , V_77 ) ;
F_39 ( V_77 ) ;
}
static T_2 int F_40 ( void )
{
F_41 ( L_48 , 0 , NULL , & V_80 ) ;
if ( V_81 )
F_16 ( & V_82 ) ;
return 0 ;
}
void F_42 ( void )
{
struct V_26 * V_4 ;
const unsigned int V_83 = 0x4b189680 ;
F_43 ( V_84 ) ; F_43 ( V_85 ) ; F_43 ( V_86 ) ;
V_87 ;
unsigned int V_35 ;
V_4 = ( void * ) F_12 ( V_58 ) ;
if ( ! V_4 )
return;
if ( F_2 ( V_4 , 1 , 2 , 2 ) != - V_2 ) {
F_44 ( V_84 , & V_83 ) ;
if ( ( V_4 -> V_35 >> 23 ) == 0 )
F_45 ( V_85 , ( long ) V_4 -> V_35 , 64 , long ) ;
else
F_44 ( V_85 , & V_4 -> V_35 ) ;
F_46 ( V_86 , V_84 , V_85 ) ;
F_47 ( V_35 , V_86 , 32 , 0 ) ;
} else
V_35 = 42 ;
V_88 = V_35 * ( 500000 / V_89 ) ;
F_13 ( ( unsigned long ) V_4 ) ;
}
void T_4 F_48 ( void )
{
F_42 () ;
F_49 ( V_90 L_49
L_50 , V_88 / ( 500000 / V_89 ) ,
( V_88 / ( 5000 / V_89 ) ) % 100 ) ;
}
