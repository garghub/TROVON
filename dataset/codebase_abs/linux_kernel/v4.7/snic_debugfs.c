int
F_1 ( void )
{
int V_1 = - 1 ;
struct V_2 * V_3 = NULL ;
V_3 = F_2 ( L_1 , NULL ) ;
if ( ! V_3 ) {
F_3 ( L_2 ) ;
return V_1 ;
}
V_4 -> V_5 = V_3 ;
V_3 = F_2 ( L_3 , V_4 -> V_5 ) ;
if ( ! V_3 ) {
F_3 ( L_4 ) ;
return V_1 ;
}
V_4 -> V_6 = V_3 ;
V_1 = 0 ;
return V_1 ;
}
void
F_4 ( void )
{
F_5 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
F_5 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
}
static int
F_6 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
F_7 ( ! V_7 -> V_10 ) ;
V_9 -> V_11 = V_7 -> V_10 ;
return 0 ;
}
static T_1
F_8 ( struct V_8 * V_9 ,
char T_2 * V_12 ,
T_3 V_13 ,
T_4 * V_14 )
{
struct V_15 * V_15 = (struct V_15 * ) V_9 -> V_11 ;
char V_16 [ 64 ] ;
int V_17 ;
V_17 = sprintf ( V_16 , L_5 , V_15 -> V_18 ) ;
return F_9 ( V_12 , V_13 , V_14 , V_16 , V_17 ) ;
}
static T_1
F_10 ( struct V_8 * V_9 ,
const char T_2 * V_12 ,
T_3 V_13 ,
T_4 * V_14 )
{
struct V_15 * V_15 = (struct V_15 * ) V_9 -> V_11 ;
struct V_19 * V_20 = & V_15 -> V_21 ;
T_5 * V_22 = ( T_5 * ) & V_20 -> V_23 ;
T_5 * V_24 = ( T_5 * ) & V_20 -> V_25 ;
char V_16 [ 64 ] ;
unsigned long V_26 ;
int V_27 ;
if ( V_13 >= sizeof( V_16 ) )
return - V_28 ;
if ( F_11 ( & V_16 , V_12 , V_13 ) )
return - V_29 ;
V_16 [ V_13 ] = '\0' ;
V_27 = F_12 ( V_16 , 10 , & V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
V_15 -> V_18 = V_26 ;
if ( V_15 -> V_18 ) {
F_13 ( & V_15 -> V_30 ,
F_14 ( & V_20 -> V_23 . V_31 ) ) ;
memset ( & V_20 -> V_32 , 0 , sizeof( struct V_33 ) ) ;
memset ( & V_20 -> V_34 , 0 , sizeof( struct V_35 ) ) ;
memset ( & V_20 -> V_36 , 0 , sizeof( struct V_37 ) ) ;
memset ( V_22 + 1 ,
0 ,
sizeof( struct V_38 ) - sizeof( T_5 ) ) ;
memset ( V_24 + 1 ,
0 ,
sizeof( struct V_39 ) - sizeof( T_5 ) ) ;
}
( * V_14 ) ++ ;
F_15 ( V_15 -> V_40 , L_6 ) ;
return V_13 ;
}
static int
F_16 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
V_9 -> V_11 = NULL ;
return 0 ;
}
static int
F_17 ( struct V_41 * V_42 , void * V_43 )
{
struct V_15 * V_15 = (struct V_15 * ) V_42 -> V_44 ;
struct V_19 * V_20 = & V_15 -> V_21 ;
struct V_45 V_46 , V_47 ;
T_5 V_48 ;
int V_49 ;
F_18 ( V_42 ,
L_7
L_8
L_7 ) ;
V_48 = ( T_5 ) F_14 ( & V_20 -> V_23 . V_50 ) ;
F_18 ( V_42 ,
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_31 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_51 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_52 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_53 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_54 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_55 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_56 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_57 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_58 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_59 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_60 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_61 ) ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_62 ) ,
V_48 ,
F_19 ( V_48 ) ) ;
F_20 ( V_42 , L_23 ) ;
for ( V_49 = 0 ; V_49 < V_63 ; V_49 ++ ) {
F_18 ( V_42 ,
L_24 ,
( T_5 ) F_14 ( & V_20 -> V_23 . V_64 [ V_49 ] ) ) ;
if ( ( V_49 + 1 ) % 8 == 0 )
F_20 ( V_42 , L_25 ) ;
}
F_18 ( V_42 ,
L_26
L_27
L_28 ) ;
F_18 ( V_42 ,
L_29
L_30
L_31
L_32
L_33
L_34 ,
( T_5 ) F_14 ( & V_20 -> V_32 . V_65 ) ,
( T_5 ) F_14 ( & V_20 -> V_32 . V_54 ) ,
( T_5 ) F_14 ( & V_20 -> V_32 . V_66 ) ,
( T_5 ) F_14 ( & V_20 -> V_32 . V_67 ) ,
( T_5 ) F_14 ( & V_20 -> V_32 . V_55 ) ,
( T_5 ) F_14 ( & V_20 -> V_32 . V_68 ) ) ;
F_18 ( V_42 ,
L_26
L_35
L_28 ) ;
F_18 ( V_42 ,
L_36
L_37
L_38 ,
( T_5 ) F_14 ( & V_20 -> V_34 . V_69 ) ,
( T_5 ) F_14 ( & V_20 -> V_34 . V_70 ) ,
( T_5 ) F_14 ( & V_20 -> V_34 . V_71 ) ) ;
F_18 ( V_42 ,
L_26
L_39
L_28 ) ;
F_18 ( V_42 ,
L_40
L_41
L_42
L_43
L_44 ,
( T_5 ) F_14 ( & V_20 -> V_25 . V_72 ) ,
( T_5 ) F_14 ( & V_20 -> V_25 . V_73 ) ,
( T_5 ) F_14 ( & V_20 -> V_25 . V_74 ) ,
( T_5 ) F_14 ( & V_20 -> V_25 . V_75 ) ,
( T_5 ) F_14 ( & V_20 -> V_25 . V_76 ) ) ;
F_18 ( V_42 ,
L_45
L_46
L_45 ) ;
F_21 ( V_20 -> V_36 . V_77 , & V_46 ) ;
F_21 ( V_20 -> V_36 . V_78 , & V_47 ) ;
F_18 ( V_42 ,
L_47
L_48
L_49
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62 ,
( T_5 ) V_20 -> V_36 . V_77 ,
V_46 . V_79 , V_46 . V_80 ,
( T_5 ) V_20 -> V_36 . V_78 ,
V_47 . V_79 , V_47 . V_80 ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_81 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_82 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_83 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_84 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_85 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_86 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_87 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_88 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_89 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_90 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_91 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_92 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_93 ) ,
( T_5 ) F_14 ( & V_20 -> V_36 . V_94 ) ) ;
return 0 ;
}
static int
F_22 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
return F_23 ( V_9 , F_17 , V_7 -> V_10 ) ;
}
int
F_24 ( struct V_15 * V_15 )
{
int V_1 = - 1 ;
char V_95 [ 16 ] ;
struct V_2 * V_3 = NULL ;
snprintf ( V_95 , sizeof( V_95 ) , L_63 , V_15 -> V_40 -> V_96 ) ;
if ( ! V_4 -> V_6 ) {
F_3 ( L_64 ) ;
return V_1 ;
}
V_3 = F_2 ( V_95 , V_4 -> V_6 ) ;
if ( ! V_3 ) {
F_3 ( L_65 ) ;
return V_1 ;
}
V_15 -> V_97 = V_3 ;
V_3 = F_25 ( L_66 ,
V_98 | V_99 ,
V_15 -> V_97 ,
V_15 ,
& V_100 ) ;
if ( ! V_3 ) {
F_3 ( L_67 ) ;
return V_1 ;
}
V_15 -> V_101 = V_3 ;
V_3 = F_25 ( L_68 ,
V_98 | V_99 | V_102 ,
V_15 -> V_97 ,
V_15 ,
& V_103 ) ;
if ( ! V_3 ) {
F_3 ( L_69 ) ;
return V_1 ;
}
V_15 -> V_104 = V_3 ;
V_1 = 0 ;
return V_1 ;
}
void
F_26 ( struct V_15 * V_15 )
{
F_5 ( V_15 -> V_101 ) ;
V_15 -> V_101 = NULL ;
F_5 ( V_15 -> V_104 ) ;
V_15 -> V_104 = NULL ;
F_5 ( V_15 -> V_97 ) ;
V_15 -> V_97 = NULL ;
}
static void *
F_27 ( struct V_41 * V_42 , T_4 * V_105 )
{
return & V_4 -> V_106 ;
}
static void *
F_28 ( struct V_41 * V_42 , void * V_43 , T_4 * V_105 )
{
return NULL ;
}
static void
F_29 ( struct V_41 * V_42 , void * V_43 )
{
}
static int
F_30 ( struct V_41 * V_42 , void * V_43 )
{
char V_16 [ V_107 ] ;
if ( F_31 ( V_16 , V_107 ) > 0 )
F_18 ( V_42 , L_70 , V_16 ) ;
return 0 ;
}
static int
F_32 ( struct V_7 * V_7 , struct V_8 * V_9 )
{
return F_33 ( V_9 , & V_108 ) ;
}
int
F_34 ( void )
{
struct V_2 * V_3 = NULL ;
int V_27 = - 1 ;
if ( ! V_4 -> V_5 ) {
F_35 ( L_71 ) ;
return V_27 ;
}
V_3 = F_36 ( L_72 ,
V_98 | V_99 | V_102 ,
V_4 -> V_5 ,
& V_4 -> V_106 . V_109 ) ;
if ( ! V_3 ) {
F_35 ( L_73 ) ;
return V_27 ;
}
V_4 -> V_106 . V_110 = V_3 ;
V_3 = F_25 ( L_74 ,
V_98 | V_99 | V_102 ,
V_4 -> V_5 ,
NULL ,
& V_111 ) ;
if ( ! V_3 ) {
F_35 ( L_75 ) ;
return V_27 ;
}
V_4 -> V_106 . V_112 = V_3 ;
V_27 = 0 ;
return V_27 ;
}
void
F_37 ( void )
{
F_5 ( V_4 -> V_106 . V_112 ) ;
V_4 -> V_106 . V_112 = NULL ;
F_5 ( V_4 -> V_106 . V_110 ) ;
V_4 -> V_106 . V_110 = NULL ;
}
