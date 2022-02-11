void F_1 ( void )
{
V_1 = NULL ;
V_2 = NULL ;
V_3 = NULL ;
V_4 = NULL ;
if ( V_5 ) {
F_2 ( V_6 , V_5 ) ;
F_3 ( V_5 -> V_7 ,
V_5 -> V_8 ) ;
V_5 = NULL ;
}
}
void F_4 ( void )
{
V_5 = F_5 ( L_1 , V_9 , NULL ,
& V_10 ) ;
F_6 ( V_6 , V_5 ) ;
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
if ( V_18 == NULL )
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
V_1 = V_13 ;
if ( V_17 -> V_20 == V_31 )
V_2 = V_13 ;
if ( V_17 -> V_20 == V_32 )
V_3 = V_13 ;
if ( V_17 -> V_20 == V_33 )
V_4 = V_13 ;
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
V_13 = (struct V_12 * ) F_16 ( F_17 ( V_46 ) ) ;
if ( ! V_13 || ! V_13 -> V_26 ) {
V_48 = - V_49 ;
goto V_50;
}
V_47 = (struct V_16 * ) V_13 -> V_26 ;
if ( ! V_47 ) {
V_48 = - V_49 ;
goto V_50;
}
F_18 ( & V_47 -> V_51 ) ;
if ( V_47 -> V_52 )
V_48 = - V_53 ;
else
V_47 -> V_52 ++ ;
F_19 ( & V_47 -> V_51 ) ;
V_50:
return V_48 ;
}
static int F_20 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
struct V_12 * V_13 ;
struct V_16 * V_47 ;
V_13 = (struct V_12 * ) F_16 ( F_17 ( V_46 ) ) ;
if ( ! V_13 || ! V_13 -> V_26 )
goto V_50;
V_47 = (struct V_16 * ) V_13 -> V_26 ;
if ( ! V_47 )
goto V_50;
F_18 ( & V_47 -> V_51 ) ;
if ( V_47 -> V_52 )
V_47 -> V_52 = 0 ;
F_19 ( & V_47 -> V_51 ) ;
V_50:
return 0 ;
}
static void * F_21 ( struct V_54 * V_55 , T_2 * V_56 )
{
return F_22 ( & V_57 , * V_56 ) ;
}
static void * F_23 ( struct V_54 * V_58 , void * V_59 , T_2 * V_56 )
{
return F_24 ( V_59 , & V_57 , V_56 ) ;
}
static void F_25 ( struct V_54 * V_55 , void * V_59 )
{
}
static int F_26 ( struct V_54 * V_55 , void * V_59 )
{
struct V_34 * V_60 ;
char V_61 [ 4 ] ;
if ( V_59 == & V_57 ) {
F_27 ( V_55 , L_5 ) ;
F_27 ( V_55 , L_6 ) ;
F_27 ( V_55 , L_7 ) ;
return 0 ;
}
V_60 = F_28 ( V_59 , struct V_34 , V_62 ) ;
F_29 ( V_60 -> V_63 , V_61 ) ;
F_30 ( V_55 , L_8 ,
V_61 ,
V_60 -> V_64 ,
F_31 ( V_60 -> V_65 ) ,
V_60 -> V_66 ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_33 ( V_46 , & V_67 ) ;
}
static T_3 F_34 ( struct V_46 * V_46 ,
const char T_4 * V_68 ,
T_5 V_44 , T_2 * V_56 )
{
T_3 V_69 ;
char * V_70 , * V_71 ;
char * line , * V_72 ;
if ( V_44 > 32768 )
return - V_73 ;
V_70 = V_71 = F_35 ( V_44 + 1 ) ;
if ( ! V_70 )
return - V_74 ;
if ( F_36 ( V_70 , V_68 , V_44 ) ) {
V_69 = - V_75 ;
goto V_50;
}
V_70 [ V_44 ] = 0 ;
V_72 = L_9 ;
line = strpbrk ( V_71 , V_72 ) ;
while ( line ) {
* line = 0 ;
V_69 = F_37 ( V_71 ) ;
if ( V_69 )
goto V_50;
V_71 = line + 1 ;
line = strpbrk ( V_71 , V_72 ) ;
}
V_69 = V_44 ;
V_50:
F_38 ( V_70 ) ;
return V_69 ;
}
static inline char * F_39 ( const char * V_76 )
{
while ( ( * V_76 ) && ! isspace ( * V_76 ) )
++ V_76 ;
return F_40 ( V_76 ) ;
}
static int F_41 ( char * * V_77 , char * V_78 )
{
int V_35 = * * V_77 ;
if ( isalnum ( V_35 ) || ( V_35 == '_' ) )
V_78 [ 0 ] = V_35 ;
else
return - V_73 ;
( * V_77 ) ++ ; V_35 = * * V_77 ;
if ( isalnum ( V_35 ) || ( V_35 == '_' ) ) {
V_78 [ 1 ] = V_35 ;
( * V_77 ) ++ ;
} else
V_78 [ 1 ] = 0 ;
return 0 ;
}
static int F_42 ( char * V_79 )
{
char * V_77 = V_79 ;
int V_69 ;
char V_78 [ 2 ] ;
long V_80 ;
V_77 = F_39 ( V_77 ) ;
V_69 = F_41 ( & V_77 , V_78 ) ;
if ( V_69 < 0 )
return V_69 ;
V_80 = F_43 ( V_78 ) ;
V_77 = F_39 ( V_77 ) ;
return F_44 ( V_80 ) ;
}
static int F_45 ( char * V_79 )
{
char * V_77 = V_79 ;
int V_69 ;
struct V_34 * V_60 ;
char V_78 [ 2 ] ;
long V_80 ;
long V_81 ;
V_77 = F_39 ( V_77 ) ;
V_69 = F_41 ( & V_77 , V_78 ) ;
if ( V_69 < 0 )
return V_69 ;
V_80 = F_43 ( V_78 ) ;
V_77 = F_39 ( V_77 ) ;
V_69 = F_46 ( V_77 , 10 , & V_81 ) ;
if ( V_69 )
return V_69 ;
V_60 = F_47 ( V_81 ) ;
if ( ! V_60 )
return - V_73 ;
if ( ( V_60 -> V_64 != V_81 ) || ( V_60 -> V_63 != V_80 ) )
return - V_73 ;
return F_48 ( V_60 ) ;
}
static int F_49 ( char * V_79 )
{
return - V_73 ;
}
static int F_37 ( char * V_79 )
{
int V_69 ;
switch ( V_79 [ 0 ] ) {
case '+' :
V_69 = F_42 ( V_79 ) ;
break;
case '-' :
V_69 = F_45 ( V_79 ) ;
break;
case '*' :
V_69 = F_49 ( V_79 ) ;
break;
default:
V_69 = - V_73 ;
}
return V_69 ;
}
static int F_50 ( struct V_54 * V_55 , void * V_59 )
{
F_30 ( V_55 , L_10 , V_82 ) ;
F_27 ( V_55 , L_11 ) ;
F_30 ( V_55 , L_12 ,
V_83 , V_83 ) ;
return 0 ;
}
static int F_51 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_52 ( V_46 , F_50 , NULL ) ;
}
static void * F_53 ( struct V_54 * V_55 , T_2 * V_56 )
{
return F_22 ( & V_57 , * V_56 ) ;
}
static void * F_54 ( struct V_54 * V_58 , void * V_59 , T_2 * V_56 )
{
return F_24 ( V_59 , & V_57 , V_56 ) ;
}
static void F_55 ( struct V_54 * V_55 , void * V_59 )
{
}
static int F_56 ( struct V_54 * V_55 , void * V_59 )
{
struct V_34 * V_60 ;
char V_84 [ 8 ] ;
char V_85 [ 8 ] ;
char V_61 [ 4 ] ;
if ( V_59 == & V_57 ) {
F_27 ( V_55 , L_5 ) ;
F_27 ( V_55 , L_13 ) ;
F_27 ( V_55 , L_14 ) ;
return 0 ;
}
V_60 = F_28 ( V_59 , struct V_34 , V_62 ) ;
F_29 ( V_60 -> V_63 , V_61 ) ;
if ( V_60 -> V_65 == V_86 ) {
sprintf ( V_84 , L_15 , ( V_60 -> V_87 >> 8 ) & 0xff ,
V_60 -> V_87 & 0xff ) ;
sprintf ( V_85 , L_15 , ( V_60 -> V_88 >> 8 ) & 0xff ,
V_60 -> V_88 & 0xff ) ;
F_30 ( V_55 , L_16 ,
V_61 ,
F_31 ( V_60 -> V_65 ) ,
V_84 ,
V_60 -> V_89 ,
V_85 ,
V_60 -> V_90 ) ;
} else {
F_30 ( V_55 , L_17 ,
V_61 ,
F_31 ( V_60 -> V_65 ) ) ;
}
return 0 ;
}
static int F_57 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_33 ( V_46 , & V_91 ) ;
}
static int F_44 ( long V_20 )
{
struct V_34 * V_60 ;
int V_48 ;
int V_92 ;
V_60 = F_58 ( sizeof( struct V_34 ) , V_93 ) ;
if ( ! V_60 )
return - V_74 ;
V_60 -> V_64 = 0 ;
V_60 -> V_63 = V_20 ;
F_59 ( & V_60 -> V_94 ) ;
F_60 ( & V_60 -> V_95 ) ;
F_60 ( & V_60 -> V_96 ) ;
F_60 ( & V_60 -> V_97 ) ;
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ )
F_60 ( & V_60 -> V_99 [ V_92 ] ) ;
V_48 = F_61 ( V_60 ) ;
if ( V_48 )
goto V_100;
V_60 -> V_64 = V_60 -> V_101 -> V_81 ;
V_48 = F_62 ( V_60 ) ;
if ( V_48 )
goto V_100;
F_63 ( V_60 , V_1 , V_102 ) ;
F_63 ( V_60 , V_2 , V_103 ) ;
F_63 ( V_60 , V_3 , V_104 ) ;
F_63 ( V_60 , V_4 ,
V_105 ) ;
return 0 ;
V_100:
F_64 ( V_60 ) ;
return V_48 ;
}
static int F_48 ( struct V_34 * V_60 )
{
int V_48 ;
if ( V_60 -> V_106 )
return - V_53 ;
if ( V_60 -> V_37 ) {
F_11 ( V_60 -> V_37 ) ;
F_12 ( V_60 ) ;
}
F_11 ( V_60 -> V_39 ) ;
F_11 ( V_60 -> V_43 ) ;
F_11 ( V_60 -> V_41 ) ;
F_65 ( V_60 ) ;
V_48 = F_66 ( V_60 ) ;
if ( V_48 )
return V_48 ;
F_64 ( V_60 ) ;
return 0 ;
}
static void F_63 ( struct V_34 * V_107 ,
struct V_12 * V_18 ,
void (* F_67)( struct V_12 * V_13 ) )
{
char V_79 [ 3 ] ;
struct V_12 * V_13 ;
F_29 ( V_107 -> V_63 , V_79 ) ;
V_13 = F_9 ( V_79 , 0600 | V_23 , V_18 ) ;
if ( ! V_13 )
return;
V_13 -> V_26 = ( void * ) V_107 ;
if ( F_67 )
F_67 ( V_13 ) ;
}
static void F_11 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
if ( ( F_14 ( & V_13 -> V_44 ) ) != 1 ) {
F_13 ( L_18 ,
V_108 , V_13 -> V_7 ) ;
return;
}
F_3 ( V_13 -> V_7 , V_13 -> V_8 ) ;
V_13 = NULL ;
}
