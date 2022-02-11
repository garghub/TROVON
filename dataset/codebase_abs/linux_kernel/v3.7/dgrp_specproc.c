void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
V_3 = NULL ;
V_4 = NULL ;
V_5 = NULL ;
V_6 = NULL ;
if ( V_2 ) {
F_3 ( V_2 -> V_7 ,
V_2 -> V_8 ) ;
V_2 = NULL ;
}
}
void F_4 ( void )
{
V_2 = F_5 ( L_1 , V_9 , NULL ,
& V_10 ) ;
F_6 ( V_1 , V_2 ) ;
}
static int F_7 ( int V_11 , const char * V_7 , struct V_12 * V_13 )
{
if ( ! V_13 || ! V_13 -> V_14 )
return 0 ;
if ( V_13 -> V_15 != V_11 )
return 0 ;
return ! memcmp ( V_7 , V_13 -> V_7 , V_11 ) ;
}
static void F_6 ( struct V_16 * V_17 ,
struct V_12 * V_18 )
{
struct V_12 * V_13 ;
int V_11 ;
T_1 V_19 ;
if ( V_17 == NULL )
return;
for (; V_17 -> V_20 ; V_17 ++ ) {
if ( ! V_17 -> V_7 )
continue;
if ( ! V_17 -> V_21 &&
! V_17 -> V_22 ) {
F_8 ( L_2 ,
V_17 -> V_7 ) ;
continue;
}
V_11 = strlen ( V_17 -> V_7 ) ;
V_19 = V_17 -> V_19 ;
V_13 = NULL ;
if ( ! V_17 -> V_22 )
V_19 |= V_23 ;
else {
V_19 |= V_9 ;
for ( V_13 = V_18 -> V_24 ; V_13 ; V_13 = V_13 -> V_25 ) {
if ( F_7 ( V_11 , V_17 -> V_7 , V_13 ) )
break;
}
}
if ( ! V_13 ) {
V_13 = F_9 ( V_17 -> V_7 , V_19 , V_18 ) ;
if ( ! V_13 )
continue;
V_13 -> V_26 = ( void * ) V_17 ;
if ( ! V_17 -> V_22 ) {
V_13 -> V_27 = & V_28 ;
if ( V_17 -> V_21 )
V_13 -> V_29 = V_17 -> V_21 ;
else
V_13 -> V_29 = & V_10 ;
}
}
V_17 -> V_13 = V_13 ;
if ( V_13 -> V_19 & V_9 )
F_6 ( V_17 -> V_22 , V_13 ) ;
if ( V_17 -> V_20 == V_30 )
V_3 = V_13 ;
if ( V_17 -> V_20 == V_31 )
V_4 = V_13 ;
if ( V_17 -> V_20 == V_32 )
V_5 = V_13 ;
if ( V_17 -> V_20 == V_33 )
V_6 = V_13 ;
}
}
static void F_2 ( struct V_16 * V_17 ,
struct V_12 * V_18 )
{
struct V_12 * V_13 ;
struct V_34 * V_35 ;
if ( V_17 == NULL )
return;
F_10 (tmp, &nd_struct_list, list) {
if ( ( V_17 == V_36 ) && ( V_35 -> V_37 ) ) {
F_11 ( V_35 -> V_37 ) ;
F_12 ( V_35 ) ;
}
if ( ( V_17 == V_38 ) && ( V_35 -> V_39 ) )
F_11 ( V_35 -> V_39 ) ;
if ( ( V_17 == V_40 ) && ( V_35 -> V_41 ) )
F_11 ( V_35 -> V_41 ) ;
if ( ( V_17 == V_42 ) && ( V_35 -> V_43 ) )
F_11 ( V_35 -> V_43 ) ;
}
for (; V_17 -> V_20 ; V_17 ++ ) {
V_13 = V_17 -> V_13 ;
if ( ! V_13 )
continue;
if ( V_13 -> V_19 & V_9 ) {
if ( ! V_17 -> V_22 ) {
F_13 ( L_3 ) ;
continue;
}
F_2 ( V_17 -> V_22 , V_13 ) ;
if ( V_13 -> V_24 )
continue;
}
if ( ( F_14 ( & V_13 -> V_44 ) ) != 1 ) {
F_13 ( L_4 ,
V_13 -> V_7 ) ;
continue;
}
F_3 ( V_13 -> V_7 , V_13 -> V_8 ) ;
V_17 -> V_13 = NULL ;
}
}
static int F_15 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_12 * V_13 ;
struct V_16 * V_47 ;
int V_48 = 0 ;
V_13 = (struct V_12 * ) F_16 ( V_46 -> V_49 -> V_50 ) ;
if ( ! V_13 || ! V_13 -> V_26 ) {
V_48 = - V_51 ;
goto V_52;
}
V_47 = (struct V_16 * ) V_13 -> V_26 ;
if ( ! V_47 ) {
V_48 = - V_51 ;
goto V_52;
}
F_17 ( & V_47 -> V_53 ) ;
if ( V_47 -> V_54 )
V_48 = - V_55 ;
else
V_47 -> V_54 ++ ;
F_18 ( & V_47 -> V_53 ) ;
V_52:
return V_48 ;
}
static int F_19 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_12 * V_13 ;
struct V_16 * V_47 ;
V_13 = (struct V_12 * ) F_16 ( V_46 -> V_49 -> V_50 ) ;
if ( ! V_13 || ! V_13 -> V_26 )
goto V_52;
V_47 = (struct V_16 * ) V_13 -> V_26 ;
if ( ! V_47 )
goto V_52;
F_17 ( & V_47 -> V_53 ) ;
if ( V_47 -> V_54 )
V_47 -> V_54 = 0 ;
F_18 ( & V_47 -> V_53 ) ;
V_52:
return 0 ;
}
static void * F_20 ( struct V_56 * V_57 , T_2 * V_58 )
{
return F_21 ( & V_59 , * V_58 ) ;
}
static void * F_22 ( struct V_56 * V_60 , void * V_61 , T_2 * V_58 )
{
return F_23 ( V_61 , & V_59 , V_58 ) ;
}
static void F_24 ( struct V_56 * V_57 , void * V_61 )
{
}
static int F_25 ( struct V_56 * V_57 , void * V_61 )
{
struct V_34 * V_62 ;
char V_63 [ 4 ] ;
if ( V_61 == & V_59 ) {
F_26 ( V_57 , L_5 ) ;
F_26 ( V_57 , L_6 ) ;
F_26 ( V_57 , L_7 ) ;
return 0 ;
}
V_62 = F_27 ( V_61 , struct V_34 , V_64 ) ;
F_28 ( V_62 -> V_65 , V_63 ) ;
F_29 ( V_57 , L_8 ,
V_63 ,
V_62 -> V_66 ,
F_30 ( V_62 -> V_67 ) ,
V_62 -> V_68 ) ;
return 0 ;
}
static int F_31 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_32 ( V_46 , & V_69 ) ;
}
static T_3 F_33 ( struct V_46 * V_46 , const char T_4 * V_70 ,
T_5 V_44 , T_2 * V_58 )
{
T_3 V_71 ;
char * V_72 , * V_73 ;
char * line , * V_74 ;
if ( V_44 > 32768 )
return - V_75 ;
V_72 = V_73 = F_34 ( V_44 + 1 ) ;
if ( ! V_72 )
return - V_76 ;
if ( F_35 ( V_72 , V_70 , V_44 ) ) {
V_71 = - V_77 ;
goto V_52;
}
V_72 [ V_44 ] = 0 ;
V_74 = L_9 ;
line = strpbrk ( V_73 , V_74 ) ;
while ( line ) {
* line = 0 ;
V_71 = F_36 ( V_73 ) ;
if ( V_71 )
goto V_52;
V_73 = line + 1 ;
line = strpbrk ( V_73 , V_74 ) ;
}
V_71 = V_44 ;
V_52:
F_37 ( V_72 ) ;
return V_71 ;
}
static inline char * F_38 ( const char * V_78 )
{
while ( ( * V_78 ) && ! isspace ( * V_78 ) )
++ V_78 ;
return F_39 ( V_78 ) ;
}
static int F_40 ( char * * V_79 , char * V_80 )
{
int V_35 = * * V_79 ;
if ( isalnum ( V_35 ) || ( V_35 == '_' ) )
V_80 [ 0 ] = V_35 ;
else
return - V_75 ;
( * V_79 ) ++ ; V_35 = * * V_79 ;
if ( isalnum ( V_35 ) || ( V_35 == '_' ) ) {
V_80 [ 1 ] = V_35 ;
( * V_79 ) ++ ;
} else
V_80 [ 1 ] = 0 ;
return 0 ;
}
static int F_41 ( char * V_81 )
{
char * V_79 = V_81 ;
int V_71 ;
char V_80 [ 2 ] ;
long V_82 ;
V_79 = F_38 ( V_79 ) ;
V_71 = F_40 ( & V_79 , V_80 ) ;
if ( V_71 < 0 )
return V_71 ;
V_82 = F_42 ( V_80 ) ;
V_79 = F_38 ( V_79 ) ;
return F_43 ( V_82 ) ;
}
static int F_44 ( char * V_81 )
{
char * V_79 = V_81 ;
int V_71 ;
struct V_34 * V_62 ;
char V_80 [ 2 ] ;
long V_82 ;
long V_83 ;
V_79 = F_38 ( V_79 ) ;
V_71 = F_40 ( & V_79 , V_80 ) ;
if ( V_71 < 0 )
return V_71 ;
V_82 = F_42 ( V_80 ) ;
V_79 = F_38 ( V_79 ) ;
V_71 = F_45 ( V_79 , 10 , & V_83 ) ;
if ( V_71 )
return V_71 ;
V_62 = F_46 ( V_83 ) ;
if ( ! V_62 )
return - V_75 ;
if ( ( V_62 -> V_66 != V_83 ) || ( V_62 -> V_65 != V_82 ) )
return - V_75 ;
return F_47 ( V_62 ) ;
}
static int F_48 ( char * V_81 )
{
return - V_75 ;
}
static int F_36 ( char * V_81 )
{
int V_71 ;
switch ( V_81 [ 0 ] ) {
case '+' :
V_71 = F_41 ( V_81 ) ;
break;
case '-' :
V_71 = F_44 ( V_81 ) ;
break;
case '*' :
V_71 = F_48 ( V_81 ) ;
break;
default:
V_71 = - V_75 ;
}
return V_71 ;
}
static int F_49 ( struct V_56 * V_57 , void * V_61 )
{
F_29 ( V_57 , L_10 , V_84 ) ;
F_26 ( V_57 , L_11 ) ;
F_29 ( V_57 , L_12 ,
V_85 , V_85 ) ;
F_29 ( V_57 , L_13 ,
V_86 , V_86 ) ;
return 0 ;
}
static int F_50 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_51 ( V_46 , F_49 , NULL ) ;
}
static void * F_52 ( struct V_56 * V_57 , T_2 * V_58 )
{
return F_21 ( & V_59 , * V_58 ) ;
}
static void * F_53 ( struct V_56 * V_60 , void * V_61 , T_2 * V_58 )
{
return F_23 ( V_61 , & V_59 , V_58 ) ;
}
static void F_54 ( struct V_56 * V_57 , void * V_61 )
{
}
static int F_55 ( struct V_56 * V_57 , void * V_61 )
{
struct V_34 * V_62 ;
char V_87 [ 8 ] ;
char V_88 [ 8 ] ;
char V_63 [ 4 ] ;
if ( V_61 == & V_59 ) {
F_26 ( V_57 , L_5 ) ;
F_26 ( V_57 , L_14 ) ;
F_26 ( V_57 , L_15 ) ;
return 0 ;
}
V_62 = F_27 ( V_61 , struct V_34 , V_64 ) ;
F_28 ( V_62 -> V_65 , V_63 ) ;
if ( V_62 -> V_67 == V_89 ) {
sprintf ( V_87 , L_16 , ( V_62 -> V_90 >> 8 ) & 0xff ,
V_62 -> V_90 & 0xff ) ;
sprintf ( V_88 , L_16 , ( V_62 -> V_91 >> 8 ) & 0xff ,
V_62 -> V_91 & 0xff ) ;
F_29 ( V_57 , L_17 ,
V_63 ,
F_30 ( V_62 -> V_67 ) ,
V_87 ,
V_62 -> V_92 ,
V_88 ,
V_62 -> V_93 ) ;
} else {
F_29 ( V_57 , L_18 ,
V_63 ,
F_30 ( V_62 -> V_67 ) ) ;
}
return 0 ;
}
static int F_56 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_32 ( V_46 , & V_94 ) ;
}
static int F_43 ( long V_20 )
{
struct V_34 * V_62 ;
int V_48 ;
int V_95 ;
V_62 = F_57 ( sizeof( struct V_34 ) , V_96 ) ;
if ( ! V_62 )
return - V_76 ;
V_62 -> V_66 = 0 ;
V_62 -> V_65 = V_20 ;
F_58 ( & V_62 -> V_97 ) ;
F_59 ( & V_62 -> V_98 ) ;
F_59 ( & V_62 -> V_99 ) ;
F_59 ( & V_62 -> V_100 ) ;
for ( V_95 = 0 ; V_95 < V_101 ; V_95 ++ )
F_59 ( & V_62 -> V_102 [ V_95 ] ) ;
V_48 = F_60 ( V_62 ) ;
if ( V_48 )
goto V_103;
V_62 -> V_66 = V_62 -> V_104 -> V_83 ;
V_48 = F_61 ( V_62 ) ;
if ( V_48 )
goto V_103;
F_62 ( V_62 , V_3 , V_105 ) ;
F_62 ( V_62 , V_4 , V_106 ) ;
F_62 ( V_62 , V_5 , V_107 ) ;
F_62 ( V_62 , V_6 ,
V_108 ) ;
return 0 ;
V_103:
F_63 ( V_62 ) ;
return V_48 ;
}
static int F_47 ( struct V_34 * V_62 )
{
int V_48 ;
if ( V_62 -> V_109 )
return - V_55 ;
if ( V_62 -> V_37 ) {
F_11 ( V_62 -> V_37 ) ;
F_12 ( V_62 ) ;
}
if ( V_62 -> V_39 )
F_11 ( V_62 -> V_39 ) ;
if ( V_62 -> V_43 )
F_11 ( V_62 -> V_43 ) ;
if ( V_62 -> V_41 )
F_11 ( V_62 -> V_41 ) ;
F_64 ( V_62 ) ;
V_48 = F_65 ( V_62 ) ;
if ( V_48 )
return V_48 ;
F_63 ( V_62 ) ;
return 0 ;
}
static void F_62 ( struct V_34 * V_110 ,
struct V_12 * V_18 ,
void (* F_66)( struct V_12 * V_13 ) )
{
char V_81 [ 3 ] ;
struct V_12 * V_13 ;
F_28 ( V_110 -> V_65 , V_81 ) ;
V_13 = F_9 ( V_81 , 0600 | V_23 , V_18 ) ;
if ( ! V_13 )
return;
V_13 -> V_26 = ( void * ) V_110 ;
if ( F_66 )
F_66 ( V_13 ) ;
}
static void F_11 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
if ( ( F_14 ( & V_13 -> V_44 ) ) != 1 ) {
F_13 ( L_19 ,
V_111 , V_13 -> V_7 ) ;
return;
}
F_3 ( V_13 -> V_7 , V_13 -> V_8 ) ;
V_13 = NULL ;
}
