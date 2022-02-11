static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
struct V_4 * V_5 = F_2 ( & line -> V_6 ) ;
if ( line )
F_3 ( line , V_5 , V_1 ) ;
F_4 ( V_5 ) ;
return V_7 ;
}
static int F_5 ( struct line * line )
{
int V_8 ;
if ( line -> V_9 == NULL )
return V_10 - 1 ;
V_8 = line -> V_11 - line -> V_12 ;
if ( V_8 <= 0 )
V_8 += V_10 ;
return V_8 - 1 ;
}
int F_6 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
unsigned long V_14 ;
int V_15 ;
F_7 ( & line -> V_16 , V_14 ) ;
V_15 = F_5 ( line ) ;
F_8 ( & line -> V_16 , V_14 ) ;
return V_15 ;
}
int F_9 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
unsigned long V_14 ;
int V_17 ;
F_7 ( & line -> V_16 , V_14 ) ;
V_17 = V_10 - ( F_5 ( line ) + 1 ) ;
F_8 ( & line -> V_16 , V_14 ) ;
return V_17 ;
}
static int F_10 ( struct line * line , const char * V_18 , int V_19 )
{
int V_20 , V_15 ;
if ( line -> V_9 == NULL ) {
line -> V_9 = F_11 ( V_10 , V_21 ) ;
if ( line -> V_9 == NULL ) {
F_12 ( V_22 L_1
L_2 ) ;
return 0 ;
}
line -> V_11 = line -> V_9 ;
line -> V_12 = line -> V_9 ;
}
V_15 = F_5 ( line ) ;
V_19 = ( V_19 > V_15 ) ? V_15 : V_19 ;
V_20 = line -> V_9 + V_10 - line -> V_12 ;
if ( V_19 < V_20 ) {
memcpy ( line -> V_12 , V_18 , V_19 ) ;
line -> V_12 += V_19 ;
}
else {
memcpy ( line -> V_12 , V_18 , V_20 ) ;
V_18 += V_20 ;
memcpy ( line -> V_9 , V_18 , V_19 - V_20 ) ;
line -> V_12 = line -> V_9 + V_19 - V_20 ;
}
return V_19 ;
}
static int F_13 ( struct line * line )
{
int V_8 , V_23 ;
if ( ( line -> V_9 == NULL ) || ( line -> V_11 == line -> V_12 ) )
return 1 ;
if ( line -> V_12 < line -> V_11 ) {
V_23 = line -> V_9 + V_10 - line -> V_11 ;
V_8 = F_14 ( line -> V_24 , line -> V_11 , V_23 ,
line -> V_25 -> V_26 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 == V_23 ) {
line -> V_11 = line -> V_9 ;
} else {
line -> V_11 += V_8 ;
return 0 ;
}
}
V_23 = line -> V_12 - line -> V_11 ;
V_8 = F_14 ( line -> V_24 , line -> V_11 , V_23 ,
line -> V_25 -> V_26 ) ;
if ( V_8 < 0 )
return V_8 ;
line -> V_11 += V_8 ;
return line -> V_11 == line -> V_12 ;
}
void F_15 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
unsigned long V_14 ;
F_7 ( & line -> V_16 , V_14 ) ;
F_13 ( line ) ;
F_8 ( & line -> V_16 , V_14 ) ;
}
void F_16 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
}
int F_17 ( struct V_4 * V_5 , unsigned char V_27 )
{
return F_18 ( V_5 , & V_27 , sizeof( V_27 ) ) ;
}
int F_18 ( struct V_4 * V_5 , const unsigned char * V_18 , int V_19 )
{
struct line * line = V_5 -> V_13 ;
unsigned long V_14 ;
int V_8 , V_17 = 0 ;
F_7 ( & line -> V_16 , V_14 ) ;
if ( line -> V_11 != line -> V_12 )
V_17 = F_10 ( line , V_18 , V_19 ) ;
else {
V_8 = F_14 ( line -> V_24 , V_18 , V_19 ,
line -> V_25 -> V_26 ) ;
if ( V_8 < 0 ) {
V_17 = V_8 ;
goto V_28;
}
V_19 -= V_8 ;
V_17 += V_8 ;
if ( V_19 > 0 )
V_17 += F_10 ( line , V_18 + V_8 , V_19 ) ;
}
V_28:
F_8 ( & line -> V_16 , V_14 ) ;
return V_17 ;
}
void F_19 ( struct V_4 * V_5 , struct V_29 * V_30 )
{
}
void F_20 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
F_21 ( line -> V_31 , line -> V_25 -> V_32 ) ;
line -> V_33 = 1 ;
}
void F_22 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
line -> V_33 = 0 ;
F_3 ( line , V_5 , line -> V_25 -> V_32 ) ;
if ( ! line -> V_33 )
F_23 ( line -> V_31 , line -> V_25 -> V_32 ) ;
}
static T_1 F_24 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
struct V_4 * V_5 ;
int V_34 ;
F_25 ( & line -> V_16 ) ;
V_34 = F_13 ( line ) ;
if ( V_34 == 0 ) {
F_26 ( & line -> V_16 ) ;
return V_35 ;
} else if ( V_34 < 0 ) {
line -> V_11 = line -> V_9 ;
line -> V_12 = line -> V_9 ;
}
F_26 ( & line -> V_16 ) ;
V_5 = F_2 ( & line -> V_6 ) ;
if ( V_5 == NULL )
return V_35 ;
F_27 ( V_5 ) ;
F_4 ( V_5 ) ;
return V_7 ;
}
int F_28 ( int V_36 , int V_37 , int V_38 , struct line * line , void * V_2 )
{
const struct V_39 * V_25 = line -> V_25 ;
int V_34 = 0 ;
if ( V_37 )
V_34 = F_29 ( V_25 -> V_32 , V_36 , V_40 ,
F_1 , V_41 ,
V_25 -> V_42 , V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_38 )
V_34 = F_29 ( V_25 -> V_26 , V_36 , V_43 ,
F_24 , V_41 ,
V_25 -> V_44 , V_2 ) ;
return V_34 ;
}
static int F_30 ( struct V_45 * V_6 , struct V_4 * V_5 )
{
int V_17 ;
struct line * line = V_5 -> V_13 ;
V_17 = F_31 ( line ) ;
if ( V_17 )
return V_17 ;
if ( ! line -> V_46 ) {
F_32 ( line -> V_24 , V_5 ) ;
line -> V_46 = 1 ;
}
F_33 ( line , & V_5 -> V_47 . V_48 ,
& V_5 -> V_47 . V_49 ) ;
return 0 ;
}
int F_34 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
struct line * line = V_5 -> V_13 ;
return F_35 ( & line -> V_6 , V_5 , V_51 ) ;
}
int F_36 ( struct V_52 * V_25 , struct V_4 * V_5 ,
struct line * line )
{
int V_17 ;
V_17 = F_37 ( V_25 , V_5 ) ;
if ( V_17 )
return V_17 ;
V_5 -> V_13 = line ;
return 0 ;
}
void F_38 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
if ( line -> V_46 ) {
F_39 ( V_5 ) ;
line -> V_46 = 0 ;
}
}
void F_40 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
struct line * line = V_5 -> V_13 ;
F_41 ( & line -> V_6 , V_5 , V_51 ) ;
}
void F_42 ( struct V_4 * V_5 )
{
struct line * line = V_5 -> V_13 ;
F_43 ( & line -> V_6 ) ;
}
void F_44 ( struct line * V_53 , int V_54 )
{
int V_55 ;
for( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
F_45 ( & V_53 [ V_55 ] ) ;
}
int F_46 ( struct line * V_53 , int V_8 , char * V_56 ,
const struct V_57 * V_58 , char * * V_59 )
{
struct line * line = & V_53 [ V_8 ] ;
struct V_52 * V_25 = line -> V_25 -> V_25 ;
int V_34 = - V_60 ;
if ( line -> V_6 . V_23 ) {
* V_59 = L_3 ;
goto V_61;
}
if ( ! strcmp ( V_56 , L_4 ) ) {
if ( line -> V_62 ) {
line -> V_62 = 0 ;
F_47 ( line -> V_63 ) ;
F_48 ( V_25 , V_8 ) ;
F_49 ( NULL , line , V_8 , V_58 , V_59 ) ;
V_34 = 0 ;
}
} else {
char * V_64 = F_50 ( V_56 , V_65 ) ;
if ( ! V_64 ) {
* V_59 = L_5 ;
return - V_66 ;
}
if ( line -> V_62 ) {
F_48 ( V_25 , V_8 ) ;
F_47 ( line -> V_63 ) ;
}
line -> V_63 = V_64 ;
line -> V_62 = 1 ;
V_34 = F_49 ( V_64 , line , V_8 , V_58 , V_59 ) ;
if ( ! V_34 ) {
struct V_67 * V_68 = F_51 ( & line -> V_6 ,
V_25 , V_8 , NULL ) ;
if ( F_52 ( V_68 ) ) {
* V_59 = L_6 ;
V_34 = F_53 ( V_68 ) ;
F_49 ( NULL , line , V_8 , V_58 , V_59 ) ;
}
}
if ( V_34 ) {
line -> V_63 = NULL ;
line -> V_62 = 0 ;
F_47 ( V_64 ) ;
}
}
V_61:
return V_34 ;
}
int F_54 ( char * * V_69 , unsigned int V_70 , char * * V_71 ,
char * V_56 , char * V_72 )
{
char * error ;
if ( * V_56 == '=' ) {
* V_71 = V_56 + 1 ;
} else {
char * V_20 ;
unsigned V_8 = F_55 ( V_56 , & V_20 , 0 ) ;
if ( * V_20 != '=' ) {
error = L_7 ;
goto V_61;
}
if ( V_8 >= V_70 ) {
error = L_8 ;
goto V_61;
}
V_69 [ V_8 ] = V_20 + 1 ;
}
return 0 ;
V_61:
F_12 ( V_22 L_9
L_10 , V_72 , V_56 , error ) ;
return - V_60 ;
}
int F_56 ( struct line * V_53 , unsigned int V_70 , char * V_73 ,
const struct V_57 * V_58 , char * * V_59 )
{
char * V_20 ;
int V_8 ;
if ( * V_73 == '=' ) {
* V_59 = L_11 ;
return - V_60 ;
}
V_8 = F_55 ( V_73 , & V_20 , 0 ) ;
if ( * V_20 ++ != '=' ) {
* V_59 = L_7 ;
return - V_60 ;
}
if ( V_8 >= V_70 ) {
* V_59 = L_8 ;
return - V_60 ;
}
return F_46 ( V_53 , V_8 , V_20 , V_58 , V_59 ) ;
}
int F_57 ( char * V_72 , struct line * V_53 , unsigned int V_70 , char * V_73 ,
int V_74 , char * * V_59 )
{
struct line * line ;
char * V_20 ;
int V_75 , V_8 = 0 ;
V_75 = F_55 ( V_72 , & V_20 , 0 ) ;
if ( ( * V_20 != '\0' ) || ( V_20 == V_72 ) ) {
* V_59 = L_12 ;
return 0 ;
}
if ( ( V_75 < 0 ) || ( V_75 >= V_70 ) ) {
* V_59 = L_13 ;
return 0 ;
}
line = & V_53 [ V_75 ] ;
if ( ! line -> V_62 )
F_58 ( V_73 , V_74 , V_8 , L_4 , 1 ) ;
else {
struct V_4 * V_5 = F_2 ( & line -> V_6 ) ;
if ( V_5 == NULL ) {
F_58 ( V_73 , V_74 , V_8 , line -> V_63 , 1 ) ;
} else {
V_8 = F_59 ( line , V_73 , V_74 , V_59 ) ;
F_4 ( V_5 ) ;
}
}
return V_8 ;
}
int F_60 ( char * * V_73 , int * V_76 , int * V_77 )
{
char * V_20 ;
int V_8 ;
V_8 = F_55 ( * V_73 , & V_20 , 0 ) ;
if ( ( * V_20 != '\0' ) || ( V_20 == * V_73 ) )
return - 1 ;
* V_73 = V_20 ;
* V_76 = V_8 ;
* V_77 = V_8 ;
return V_8 ;
}
int F_61 ( struct line * V_53 , unsigned int V_70 , int V_8 , char * * V_59 )
{
if ( V_8 >= V_70 ) {
* V_59 = L_8 ;
return - V_60 ;
}
return F_46 ( V_53 , V_8 , L_4 , NULL , V_59 ) ;
}
int F_62 ( struct V_39 * V_39 ,
const struct V_78 * V_79 ,
struct line * V_53 , int V_54 )
{
struct V_52 * V_25 = F_63 ( V_54 ) ;
int V_34 ;
int V_55 ;
if ( ! V_25 )
return - V_66 ;
V_25 -> V_80 = V_39 -> V_72 ;
V_25 -> V_72 = V_39 -> V_81 ;
V_25 -> V_82 = V_39 -> V_82 ;
V_25 -> V_83 = V_39 -> V_83 ;
V_25 -> type = V_39 -> type ;
V_25 -> V_84 = V_39 -> V_84 ;
V_25 -> V_14 = V_85 | V_86 ;
V_25 -> V_87 = V_88 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
F_64 ( & V_53 [ V_55 ] . V_6 ) ;
V_53 [ V_55 ] . V_6 . V_79 = & V_89 ;
F_65 ( & V_53 [ V_55 ] . V_16 ) ;
V_53 [ V_55 ] . V_25 = V_39 ;
F_66 ( & V_53 [ V_55 ] . V_90 ) ;
}
F_67 ( V_25 , V_79 ) ;
V_34 = F_68 ( V_25 ) ;
if ( V_34 ) {
F_12 ( V_22 L_14 ,
V_39 -> V_72 ) ;
F_69 ( V_25 ) ;
return V_34 ;
}
V_39 -> V_25 = V_25 ;
F_70 ( & V_39 -> V_91 ) ;
return 0 ;
}
static void F_71 ( struct V_92 * V_93 )
{
struct V_94 * V_94 = F_72 ( V_93 , struct V_94 , V_93 ) ;
F_73 ( V_95 , V_94 ) ;
if ( V_94 -> V_96 != - 1 )
F_74 ( V_94 -> V_96 , 1 ) ;
if ( V_94 -> V_97 != 0 )
F_75 ( V_94 -> V_97 , 0 ) ;
F_47 ( V_94 ) ;
}
static void F_76 ( struct V_94 * V_94 )
{
int V_36 = V_94 -> V_36 ;
V_94 -> V_36 = - 1 ;
if ( V_36 != - 1 )
F_77 ( V_36 ) ;
F_78 ( & V_94 -> V_98 ) ;
F_71 ( & V_94 -> V_93 ) ;
}
static T_1 F_79 ( int V_1 , void * V_2 )
{
struct V_94 * V_94 = V_2 ;
struct V_4 * V_5 ;
struct line * line ;
int V_36 = V_94 -> V_36 ;
int V_34 ;
char V_99 ;
if ( V_36 != - 1 ) {
V_34 = F_80 ( V_36 , & V_99 , NULL ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_100 ) {
V_94 -> V_36 = - 1 ;
F_78 ( & V_94 -> V_98 ) ;
F_77 ( V_36 ) ;
F_12 ( V_22 L_15
L_16 , - V_34 ) ;
F_12 ( V_22 L_17
L_18 , V_94 -> V_101 ) ;
F_81 ( & V_94 -> V_93 , F_71 ) ;
F_82 ( & V_94 -> V_93 ) ;
return V_7 ;
}
goto V_61;
}
}
V_5 = V_94 -> V_5 ;
if ( V_5 != NULL ) {
line = V_5 -> V_13 ;
if ( line != NULL ) {
F_33 ( line , & V_5 -> V_47 . V_48 ,
& V_5 -> V_47 . V_49 ) ;
F_83 ( V_5 -> V_102 , V_103 , 1 ) ;
}
}
V_61:
if ( V_94 -> V_36 != - 1 )
F_84 ( V_94 -> V_36 , V_95 ) ;
return V_7 ;
}
void F_85 ( int V_36 , int V_101 , int V_96 , struct V_4 * V_5 ,
unsigned long V_97 )
{
struct V_94 * V_94 ;
V_94 = F_11 ( sizeof( * V_94 ) , V_65 ) ;
if ( V_94 == NULL ) {
F_12 ( V_22 L_19 ) ;
goto V_104;
}
* V_94 = ( (struct V_94 ) { . V_98 = F_86 ( V_94 -> V_98 ) ,
. V_36 = V_36 ,
. V_101 = V_101 ,
. V_96 = V_96 ,
. V_5 = V_5 ,
. V_97 = V_97 } ) ;
if ( F_29 ( V_95 , V_36 , V_40 , F_79 ,
V_41 , L_20 , V_94 ) < 0 ) {
F_12 ( V_22 L_21
L_22 ) ;
goto V_105;
}
F_25 ( & V_106 ) ;
F_87 ( & V_94 -> V_98 , & V_107 ) ;
F_26 ( & V_106 ) ;
return;
V_105:
F_47 ( V_94 ) ;
V_104:
F_74 ( V_96 , 1 ) ;
F_77 ( V_36 ) ;
if ( V_97 != 0 )
F_75 ( V_97 , 0 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
struct V_108 * V_109 , * V_110 ;
struct V_94 * V_94 ;
F_25 ( & V_106 ) ;
F_88 (ele, next, &winch_handlers) {
V_94 = F_89 ( V_109 , struct V_94 , V_98 ) ;
if ( V_94 -> V_5 == V_5 ) {
F_76 ( V_94 ) ;
break;
}
}
F_26 ( & V_106 ) ;
}
static void F_90 ( void )
{
struct V_108 * V_109 , * V_110 ;
struct V_94 * V_94 ;
F_25 ( & V_106 ) ;
F_88 (ele, next, &winch_handlers) {
V_94 = F_89 ( V_109 , struct V_94 , V_98 ) ;
F_76 ( V_94 ) ;
}
F_26 ( & V_106 ) ;
}
char * F_91 ( char * V_111 )
{
char * V_112 , * V_113 ;
int V_19 ;
V_112 = F_92 () ;
if ( * V_112 == '\0' )
return V_111 ;
V_19 = strlen ( V_111 ) + strlen ( L_23 ) + strlen ( V_112 ) + 1 ;
V_113 = F_11 ( V_19 , V_65 ) ;
if ( V_113 == NULL ) {
F_12 ( V_22 L_24 ) ;
return V_111 ;
}
snprintf ( V_113 , V_19 , L_25 , V_111 , V_112 ) ;
return V_113 ;
}
