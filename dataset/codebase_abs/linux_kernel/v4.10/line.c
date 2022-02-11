static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
if ( line )
F_2 ( line , V_1 ) ;
return V_4 ;
}
static int F_3 ( struct line * line )
{
int V_5 ;
if ( line -> V_6 == NULL )
return V_7 - 1 ;
V_5 = line -> V_8 - line -> V_9 ;
if ( V_5 <= 0 )
V_5 += V_7 ;
return V_5 - 1 ;
}
int F_4 ( struct V_10 * V_11 )
{
struct line * line = V_11 -> V_12 ;
unsigned long V_13 ;
int V_14 ;
F_5 ( & line -> V_15 , V_13 ) ;
V_14 = F_3 ( line ) ;
F_6 ( & line -> V_15 , V_13 ) ;
return V_14 ;
}
int F_7 ( struct V_10 * V_11 )
{
struct line * line = V_11 -> V_12 ;
unsigned long V_13 ;
int V_16 ;
F_5 ( & line -> V_15 , V_13 ) ;
V_16 = V_7 - ( F_3 ( line ) + 1 ) ;
F_6 ( & line -> V_15 , V_13 ) ;
return V_16 ;
}
static int F_8 ( struct line * line , const char * V_17 , int V_18 )
{
int V_19 , V_14 ;
if ( line -> V_6 == NULL ) {
line -> V_6 = F_9 ( V_7 , V_20 ) ;
if ( line -> V_6 == NULL ) {
F_10 ( V_21 L_1
L_2 ) ;
return 0 ;
}
line -> V_8 = line -> V_6 ;
line -> V_9 = line -> V_6 ;
}
V_14 = F_3 ( line ) ;
V_18 = ( V_18 > V_14 ) ? V_14 : V_18 ;
V_19 = line -> V_6 + V_7 - line -> V_9 ;
if ( V_18 < V_19 ) {
memcpy ( line -> V_9 , V_17 , V_18 ) ;
line -> V_9 += V_18 ;
}
else {
memcpy ( line -> V_9 , V_17 , V_19 ) ;
V_17 += V_19 ;
memcpy ( line -> V_6 , V_17 , V_18 - V_19 ) ;
line -> V_9 = line -> V_6 + V_18 - V_19 ;
}
return V_18 ;
}
static int F_11 ( struct line * line )
{
int V_5 , V_22 ;
if ( ( line -> V_6 == NULL ) || ( line -> V_8 == line -> V_9 ) )
return 1 ;
if ( line -> V_9 < line -> V_8 ) {
V_22 = line -> V_6 + V_7 - line -> V_8 ;
V_5 = F_12 ( line -> V_23 , line -> V_8 , V_22 ,
line -> V_24 -> V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 == V_22 ) {
line -> V_8 = line -> V_6 ;
} else {
line -> V_8 += V_5 ;
return 0 ;
}
}
V_22 = line -> V_9 - line -> V_8 ;
V_5 = F_12 ( line -> V_23 , line -> V_8 , V_22 ,
line -> V_24 -> V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
line -> V_8 += V_5 ;
return line -> V_8 == line -> V_9 ;
}
void F_13 ( struct V_10 * V_11 )
{
struct line * line = V_11 -> V_12 ;
unsigned long V_13 ;
F_5 ( & line -> V_15 , V_13 ) ;
F_11 ( line ) ;
F_6 ( & line -> V_15 , V_13 ) ;
}
void F_14 ( struct V_10 * V_11 )
{
F_13 ( V_11 ) ;
}
int F_15 ( struct V_10 * V_11 , unsigned char V_26 )
{
return F_16 ( V_11 , & V_26 , sizeof( V_26 ) ) ;
}
int F_16 ( struct V_10 * V_11 , const unsigned char * V_17 , int V_18 )
{
struct line * line = V_11 -> V_12 ;
unsigned long V_13 ;
int V_5 , V_16 = 0 ;
F_5 ( & line -> V_15 , V_13 ) ;
if ( line -> V_8 != line -> V_9 )
V_16 = F_8 ( line , V_17 , V_18 ) ;
else {
V_5 = F_12 ( line -> V_23 , V_17 , V_18 ,
line -> V_24 -> V_25 ) ;
if ( V_5 < 0 ) {
V_16 = V_5 ;
goto V_27;
}
V_18 -= V_5 ;
V_16 += V_5 ;
if ( V_18 > 0 )
V_16 += F_8 ( line , V_17 + V_5 , V_18 ) ;
}
V_27:
F_6 ( & line -> V_15 , V_13 ) ;
return V_16 ;
}
void F_17 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
}
void F_18 ( struct V_10 * V_11 )
{
struct line * line = V_11 -> V_12 ;
F_19 ( line -> V_30 , line -> V_24 -> V_31 ) ;
line -> V_32 = 1 ;
}
void F_20 ( struct V_10 * V_11 )
{
struct line * line = V_11 -> V_12 ;
line -> V_32 = 0 ;
F_2 ( line , line -> V_24 -> V_31 ) ;
if ( ! line -> V_32 )
F_21 ( line -> V_30 , line -> V_24 -> V_31 ) ;
}
static T_1 F_22 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
int V_33 ;
F_23 ( & line -> V_15 ) ;
V_33 = F_11 ( line ) ;
if ( V_33 == 0 ) {
F_24 ( & line -> V_15 ) ;
return V_34 ;
} else if ( V_33 < 0 ) {
line -> V_8 = line -> V_6 ;
line -> V_9 = line -> V_6 ;
}
F_24 ( & line -> V_15 ) ;
F_25 ( & line -> V_35 ) ;
return V_4 ;
}
int F_26 ( int V_36 , int V_37 , int V_38 , struct line * line , void * V_2 )
{
const struct V_39 * V_24 = line -> V_24 ;
int V_33 = 0 ;
if ( V_37 )
V_33 = F_27 ( V_24 -> V_31 , V_36 , V_40 ,
F_1 , V_41 ,
V_24 -> V_42 , V_2 ) ;
if ( V_33 )
return V_33 ;
if ( V_38 )
V_33 = F_27 ( V_24 -> V_25 , V_36 , V_43 ,
F_22 , V_41 ,
V_24 -> V_44 , V_2 ) ;
return V_33 ;
}
static int F_28 ( struct V_45 * V_35 , struct V_10 * V_11 )
{
int V_16 ;
struct line * line = V_11 -> V_12 ;
V_16 = F_29 ( line ) ;
if ( V_16 )
return V_16 ;
if ( ! line -> V_46 ) {
F_30 ( line -> V_23 , V_35 ) ;
line -> V_46 = 1 ;
}
F_31 ( line , & V_11 -> V_47 . V_48 ,
& V_11 -> V_47 . V_49 ) ;
return 0 ;
}
static void F_32 ( struct V_45 * V_35 )
{
struct V_10 * V_11 = F_33 ( V_35 ) ;
struct line * line = V_11 -> V_12 ;
if ( line -> V_46 ) {
F_34 ( V_11 ) ;
line -> V_46 = 0 ;
}
}
int F_35 ( struct V_10 * V_11 , struct V_50 * V_51 )
{
struct line * line = V_11 -> V_12 ;
return F_36 ( & line -> V_35 , V_11 , V_51 ) ;
}
int F_37 ( struct V_52 * V_24 , struct V_10 * V_11 ,
struct line * line )
{
int V_16 ;
V_16 = F_38 ( V_24 , V_11 ) ;
if ( V_16 )
return V_16 ;
V_11 -> V_12 = line ;
return 0 ;
}
void F_39 ( struct V_10 * V_11 , struct V_50 * V_51 )
{
struct line * line = V_11 -> V_12 ;
F_40 ( & line -> V_35 , V_11 , V_51 ) ;
}
void F_41 ( struct V_10 * V_11 )
{
struct line * line = V_11 -> V_12 ;
F_42 ( & line -> V_35 ) ;
}
void F_43 ( struct line * V_53 , int V_54 )
{
int V_55 ;
for( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
F_44 ( & V_53 [ V_55 ] ) ;
}
int F_45 ( struct line * V_53 , int V_5 , char * V_56 ,
const struct V_57 * V_58 , char * * V_59 )
{
struct line * line = & V_53 [ V_5 ] ;
struct V_52 * V_24 = line -> V_24 -> V_24 ;
int V_33 = - V_60 ;
if ( line -> V_35 . V_22 ) {
* V_59 = L_3 ;
goto V_61;
}
if ( ! strcmp ( V_56 , L_4 ) ) {
if ( line -> V_62 ) {
line -> V_62 = 0 ;
F_46 ( line -> V_63 ) ;
F_47 ( V_24 , V_5 ) ;
F_48 ( NULL , line , V_5 , V_58 , V_59 ) ;
V_33 = 0 ;
}
} else {
char * V_64 = F_49 ( V_56 , V_65 ) ;
if ( ! V_64 ) {
* V_59 = L_5 ;
return - V_66 ;
}
if ( line -> V_62 ) {
F_47 ( V_24 , V_5 ) ;
F_46 ( line -> V_63 ) ;
}
line -> V_63 = V_64 ;
line -> V_62 = 1 ;
V_33 = F_48 ( V_64 , line , V_5 , V_58 , V_59 ) ;
if ( ! V_33 ) {
struct V_67 * V_68 = F_50 ( & line -> V_35 ,
V_24 , V_5 , NULL ) ;
if ( F_51 ( V_68 ) ) {
* V_59 = L_6 ;
V_33 = F_52 ( V_68 ) ;
F_48 ( NULL , line , V_5 , V_58 , V_59 ) ;
}
}
if ( V_33 ) {
line -> V_63 = NULL ;
line -> V_62 = 0 ;
F_46 ( V_64 ) ;
}
}
V_61:
return V_33 ;
}
int F_53 ( char * * V_69 , unsigned int V_70 , char * * V_71 ,
char * V_56 , char * V_72 )
{
char * error ;
if ( * V_56 == '=' ) {
* V_71 = V_56 + 1 ;
} else {
char * V_19 ;
unsigned V_5 = F_54 ( V_56 , & V_19 , 0 ) ;
if ( * V_19 != '=' ) {
error = L_7 ;
goto V_61;
}
if ( V_5 >= V_70 ) {
error = L_8 ;
goto V_61;
}
V_69 [ V_5 ] = V_19 + 1 ;
}
return 0 ;
V_61:
F_10 ( V_21 L_9
L_10 , V_72 , V_56 , error ) ;
return - V_60 ;
}
int F_55 ( struct line * V_53 , unsigned int V_70 , char * V_73 ,
const struct V_57 * V_58 , char * * V_59 )
{
char * V_19 ;
int V_5 ;
if ( * V_73 == '=' ) {
* V_59 = L_11 ;
return - V_60 ;
}
V_5 = F_54 ( V_73 , & V_19 , 0 ) ;
if ( * V_19 ++ != '=' ) {
* V_59 = L_7 ;
return - V_60 ;
}
if ( V_5 >= V_70 ) {
* V_59 = L_8 ;
return - V_60 ;
}
return F_45 ( V_53 , V_5 , V_19 , V_58 , V_59 ) ;
}
int F_56 ( char * V_72 , struct line * V_53 , unsigned int V_70 , char * V_73 ,
int V_74 , char * * V_59 )
{
struct line * line ;
char * V_19 ;
int V_75 , V_5 = 0 ;
V_75 = F_54 ( V_72 , & V_19 , 0 ) ;
if ( ( * V_19 != '\0' ) || ( V_19 == V_72 ) ) {
* V_59 = L_12 ;
return 0 ;
}
if ( ( V_75 < 0 ) || ( V_75 >= V_70 ) ) {
* V_59 = L_13 ;
return 0 ;
}
line = & V_53 [ V_75 ] ;
if ( ! line -> V_62 )
F_57 ( V_73 , V_74 , V_5 , L_4 , 1 ) ;
else {
struct V_10 * V_11 = F_33 ( & line -> V_35 ) ;
if ( V_11 == NULL ) {
F_57 ( V_73 , V_74 , V_5 , line -> V_63 , 1 ) ;
} else {
V_5 = F_58 ( line , V_73 , V_74 , V_59 ) ;
F_59 ( V_11 ) ;
}
}
return V_5 ;
}
int F_60 ( char * * V_73 , int * V_76 , int * V_77 )
{
char * V_19 ;
int V_5 ;
V_5 = F_54 ( * V_73 , & V_19 , 0 ) ;
if ( ( * V_19 != '\0' ) || ( V_19 == * V_73 ) )
return - 1 ;
* V_73 = V_19 ;
* V_76 = V_5 ;
* V_77 = V_5 ;
return V_5 ;
}
int F_61 ( struct line * V_53 , unsigned int V_70 , int V_5 , char * * V_59 )
{
if ( V_5 >= V_70 ) {
* V_59 = L_8 ;
return - V_60 ;
}
return F_45 ( V_53 , V_5 , L_4 , NULL , V_59 ) ;
}
int F_62 ( struct V_39 * V_39 ,
const struct V_78 * V_79 ,
struct line * V_53 , int V_54 )
{
struct V_52 * V_24 = F_63 ( V_54 ) ;
int V_33 ;
int V_55 ;
if ( ! V_24 )
return - V_66 ;
V_24 -> V_80 = V_39 -> V_72 ;
V_24 -> V_72 = V_39 -> V_81 ;
V_24 -> V_82 = V_39 -> V_82 ;
V_24 -> V_83 = V_39 -> V_83 ;
V_24 -> type = V_39 -> type ;
V_24 -> V_84 = V_39 -> V_84 ;
V_24 -> V_13 = V_85 | V_86 ;
V_24 -> V_87 = V_88 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
F_64 ( & V_53 [ V_55 ] . V_35 ) ;
V_53 [ V_55 ] . V_35 . V_79 = & V_89 ;
F_65 ( & V_53 [ V_55 ] . V_15 ) ;
V_53 [ V_55 ] . V_24 = V_39 ;
F_66 ( & V_53 [ V_55 ] . V_90 ) ;
}
F_67 ( V_24 , V_79 ) ;
V_33 = F_68 ( V_24 ) ;
if ( V_33 ) {
F_10 ( V_21 L_14 ,
V_39 -> V_72 ) ;
F_69 ( V_24 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
F_70 ( & V_53 [ V_55 ] . V_35 ) ;
return V_33 ;
}
V_39 -> V_24 = V_24 ;
F_71 ( & V_39 -> V_91 ) ;
return 0 ;
}
static void F_72 ( struct V_92 * V_93 )
{
struct V_94 * V_94 = F_73 ( V_93 , struct V_94 , V_93 ) ;
F_74 ( V_95 , V_94 ) ;
if ( V_94 -> V_96 != - 1 )
F_75 ( V_94 -> V_96 , 1 ) ;
if ( V_94 -> V_97 != 0 )
F_76 ( V_94 -> V_97 , 0 ) ;
F_46 ( V_94 ) ;
}
static void F_77 ( struct V_94 * V_94 )
{
int V_36 = V_94 -> V_36 ;
V_94 -> V_36 = - 1 ;
if ( V_36 != - 1 )
F_78 ( V_36 ) ;
F_79 ( & V_94 -> V_98 ) ;
F_72 ( & V_94 -> V_93 ) ;
}
static T_1 F_80 ( int V_1 , void * V_2 )
{
struct V_94 * V_94 = V_2 ;
struct V_10 * V_11 ;
struct line * line ;
int V_36 = V_94 -> V_36 ;
int V_33 ;
char V_99 ;
struct V_96 * V_100 ;
if ( V_36 != - 1 ) {
V_33 = F_81 ( V_36 , & V_99 , NULL ) ;
if ( V_33 < 0 ) {
if ( V_33 != - V_101 ) {
V_94 -> V_36 = - 1 ;
F_79 ( & V_94 -> V_98 ) ;
F_78 ( V_36 ) ;
F_10 ( V_21 L_15
L_16 , - V_33 ) ;
F_10 ( V_21 L_17
L_18 , V_94 -> V_102 ) ;
F_82 ( & V_94 -> V_93 , F_72 ) ;
F_83 ( & V_94 -> V_93 ) ;
return V_4 ;
}
goto V_61;
}
}
V_11 = F_33 ( V_94 -> V_35 ) ;
if ( V_11 != NULL ) {
line = V_11 -> V_12 ;
if ( line != NULL ) {
F_31 ( line , & V_11 -> V_47 . V_48 ,
& V_11 -> V_47 . V_49 ) ;
V_100 = F_84 ( V_11 ) ;
if ( V_100 )
F_85 ( V_100 , V_103 , 1 ) ;
F_86 ( V_100 ) ;
}
F_59 ( V_11 ) ;
}
V_61:
if ( V_94 -> V_36 != - 1 )
F_87 ( V_94 -> V_36 , V_95 ) ;
return V_4 ;
}
void F_88 ( int V_36 , int V_102 , int V_96 , struct V_45 * V_35 ,
unsigned long V_97 )
{
struct V_94 * V_94 ;
V_94 = F_9 ( sizeof( * V_94 ) , V_65 ) ;
if ( V_94 == NULL ) {
F_10 ( V_21 L_19 ) ;
goto V_104;
}
* V_94 = ( (struct V_94 ) { . V_98 = F_89 ( V_94 -> V_98 ) ,
. V_36 = V_36 ,
. V_102 = V_102 ,
. V_96 = V_96 ,
. V_35 = V_35 ,
. V_97 = V_97 } ) ;
if ( F_27 ( V_95 , V_36 , V_40 , F_80 ,
V_41 , L_20 , V_94 ) < 0 ) {
F_10 ( V_21 L_21
L_22 ) ;
goto V_105;
}
F_23 ( & V_106 ) ;
F_90 ( & V_94 -> V_98 , & V_107 ) ;
F_24 ( & V_106 ) ;
return;
V_105:
F_46 ( V_94 ) ;
V_104:
F_75 ( V_96 , 1 ) ;
F_78 ( V_36 ) ;
if ( V_97 != 0 )
F_76 ( V_97 , 0 ) ;
}
static void F_34 ( struct V_10 * V_11 )
{
struct V_108 * V_109 , * V_110 ;
struct V_94 * V_94 ;
struct V_10 * V_111 ;
F_23 ( & V_106 ) ;
F_91 (ele, next, &winch_handlers) {
V_94 = F_92 ( V_109 , struct V_94 , V_98 ) ;
V_111 = F_33 ( V_94 -> V_35 ) ;
if ( V_111 == V_11 ) {
F_77 ( V_94 ) ;
break;
}
F_59 ( V_111 ) ;
}
F_24 ( & V_106 ) ;
}
static void F_93 ( void )
{
struct V_108 * V_109 , * V_110 ;
struct V_94 * V_94 ;
F_23 ( & V_106 ) ;
F_91 (ele, next, &winch_handlers) {
V_94 = F_92 ( V_109 , struct V_94 , V_98 ) ;
F_77 ( V_94 ) ;
}
F_24 ( & V_106 ) ;
}
char * F_94 ( char * V_112 )
{
char * V_113 , * V_114 ;
int V_18 ;
V_113 = F_95 () ;
if ( * V_113 == '\0' )
return V_112 ;
V_18 = strlen ( V_112 ) + strlen ( L_23 ) + strlen ( V_113 ) + 1 ;
V_114 = F_9 ( V_18 , V_65 ) ;
if ( V_114 == NULL ) {
F_10 ( V_21 L_24 ) ;
return V_112 ;
}
snprintf ( V_114 , V_18 , L_25 , V_112 , V_113 ) ;
return V_114 ;
}
