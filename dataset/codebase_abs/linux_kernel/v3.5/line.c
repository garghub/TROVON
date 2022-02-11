static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
if ( line )
F_2 ( line , line -> V_4 , V_1 ) ;
return V_5 ;
}
static int F_3 ( struct line * line )
{
int V_6 ;
if ( line -> V_7 == NULL )
return V_8 - 1 ;
V_6 = line -> V_9 - line -> V_10 ;
if ( V_6 <= 0 )
V_6 += V_8 ;
return V_6 - 1 ;
}
int F_4 ( struct V_11 * V_4 )
{
struct line * line = V_4 -> V_12 ;
unsigned long V_13 ;
int V_14 ;
F_5 ( & line -> V_15 , V_13 ) ;
V_14 = F_3 ( line ) ;
F_6 ( & line -> V_15 , V_13 ) ;
return V_14 ;
}
int F_7 ( struct V_11 * V_4 )
{
struct line * line = V_4 -> V_12 ;
unsigned long V_13 ;
int V_16 ;
F_5 ( & line -> V_15 , V_13 ) ;
V_16 = V_8 - ( F_3 ( line ) + 1 ) ;
F_6 ( & line -> V_15 , V_13 ) ;
return V_16 ;
}
static int F_8 ( struct line * line , const char * V_17 , int V_18 )
{
int V_19 , V_14 ;
if ( line -> V_7 == NULL ) {
line -> V_7 = F_9 ( V_8 , V_20 ) ;
if ( line -> V_7 == NULL ) {
F_10 ( V_21 L_1
L_2 ) ;
return 0 ;
}
line -> V_9 = line -> V_7 ;
line -> V_10 = line -> V_7 ;
}
V_14 = F_3 ( line ) ;
V_18 = ( V_18 > V_14 ) ? V_14 : V_18 ;
V_19 = line -> V_7 + V_8 - line -> V_10 ;
if ( V_18 < V_19 ) {
memcpy ( line -> V_10 , V_17 , V_18 ) ;
line -> V_10 += V_18 ;
}
else {
memcpy ( line -> V_10 , V_17 , V_19 ) ;
V_17 += V_19 ;
memcpy ( line -> V_7 , V_17 , V_18 - V_19 ) ;
line -> V_10 = line -> V_7 + V_18 - V_19 ;
}
return V_18 ;
}
static int F_11 ( struct line * line )
{
int V_6 , V_22 ;
if ( ( line -> V_7 == NULL ) || ( line -> V_9 == line -> V_10 ) )
return 1 ;
if ( line -> V_10 < line -> V_9 ) {
V_22 = line -> V_7 + V_8 - line -> V_9 ;
V_6 = F_12 ( line -> V_23 , line -> V_9 , V_22 ,
line -> V_24 -> V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 == V_22 ) {
line -> V_9 = line -> V_7 ;
} else {
line -> V_9 += V_6 ;
return 0 ;
}
}
V_22 = line -> V_10 - line -> V_9 ;
V_6 = F_12 ( line -> V_23 , line -> V_9 , V_22 ,
line -> V_24 -> V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
line -> V_9 += V_6 ;
return line -> V_9 == line -> V_10 ;
}
void F_13 ( struct V_11 * V_4 )
{
struct line * line = V_4 -> V_12 ;
unsigned long V_13 ;
F_5 ( & line -> V_15 , V_13 ) ;
F_11 ( line ) ;
F_6 ( & line -> V_15 , V_13 ) ;
}
void F_14 ( struct V_11 * V_4 )
{
F_13 ( V_4 ) ;
}
int F_15 ( struct V_11 * V_4 , unsigned char V_26 )
{
return F_16 ( V_4 , & V_26 , sizeof( V_26 ) ) ;
}
int F_16 ( struct V_11 * V_4 , const unsigned char * V_17 , int V_18 )
{
struct line * line = V_4 -> V_12 ;
unsigned long V_13 ;
int V_6 , V_16 = 0 ;
F_5 ( & line -> V_15 , V_13 ) ;
if ( line -> V_9 != line -> V_10 )
V_16 = F_8 ( line , V_17 , V_18 ) ;
else {
V_6 = F_12 ( line -> V_23 , V_17 , V_18 ,
line -> V_24 -> V_25 ) ;
if ( V_6 < 0 ) {
V_16 = V_6 ;
goto V_27;
}
V_18 -= V_6 ;
V_16 += V_6 ;
if ( V_18 > 0 )
V_16 += F_8 ( line , V_17 + V_6 , V_18 ) ;
}
V_27:
F_6 ( & line -> V_15 , V_13 ) ;
return V_16 ;
}
void F_17 ( struct V_11 * V_4 , struct V_28 * V_29 )
{
}
int F_18 ( struct V_11 * V_4 , unsigned int V_30 ,
unsigned long V_31 )
{
int V_16 ;
int V_32 ;
V_16 = 0 ;
switch( V_30 ) {
#ifdef F_19
case F_19 :
case V_33 :
case V_34 :
#endif
#ifdef F_20
case F_20 :
case V_35 :
#endif
#ifdef F_21
case F_21 :
case V_36 :
#endif
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return - V_54 ;
#if 0
case TCwhatever:
break;
#endif
default:
for ( V_32 = 0 ; V_32 < F_22 ( V_55 ) ; V_32 ++ )
if ( V_30 == V_55 [ V_32 ] . V_30 )
break;
if ( V_32 == F_22 ( V_55 ) ) {
F_10 ( V_21 L_3 ,
V_56 , V_4 -> V_57 , V_30 ) ;
}
V_16 = - V_54 ;
break;
}
return V_16 ;
}
void F_23 ( struct V_11 * V_4 )
{
struct line * line = V_4 -> V_12 ;
F_24 ( line -> V_58 , line -> V_24 -> V_59 ) ;
line -> V_60 = 1 ;
}
void F_25 ( struct V_11 * V_4 )
{
struct line * line = V_4 -> V_12 ;
line -> V_60 = 0 ;
F_2 ( line , V_4 , line -> V_24 -> V_59 ) ;
if ( ! line -> V_60 )
F_26 ( line -> V_58 , line -> V_24 -> V_59 ) ;
}
static T_1 F_27 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
struct V_11 * V_4 = line -> V_4 ;
int V_61 ;
F_28 ( & line -> V_15 ) ;
V_61 = F_11 ( line ) ;
if ( V_61 == 0 ) {
F_29 ( & line -> V_15 ) ;
return V_62 ;
} else if ( V_61 < 0 ) {
line -> V_9 = line -> V_7 ;
line -> V_10 = line -> V_7 ;
}
F_29 ( & line -> V_15 ) ;
if ( V_4 == NULL )
return V_62 ;
F_30 ( V_4 ) ;
return V_5 ;
}
int F_31 ( int V_63 , int V_64 , int V_65 , struct line * line , void * V_2 )
{
const struct V_66 * V_24 = line -> V_24 ;
int V_61 = 0 , V_13 = V_67 | V_68 ;
if ( V_64 )
V_61 = F_32 ( V_24 -> V_59 , V_63 , V_69 ,
F_1 , V_13 ,
V_24 -> V_70 , V_2 ) ;
if ( V_61 )
return V_61 ;
if ( V_65 )
V_61 = F_32 ( V_24 -> V_25 , V_63 , V_71 ,
F_27 , V_13 ,
V_24 -> V_72 , V_2 ) ;
return V_61 ;
}
int F_33 ( struct line * V_73 , struct V_11 * V_4 )
{
struct line * line = & V_73 [ V_4 -> V_74 ] ;
int V_61 = - V_75 ;
F_34 ( & line -> V_76 ) ;
if ( ! line -> V_77 )
goto V_78;
V_61 = 0 ;
if ( line -> V_22 ++ )
goto V_78;
F_35 ( V_4 -> V_12 ) ;
V_4 -> V_12 = line ;
line -> V_4 = V_4 ;
V_61 = F_36 ( line ) ;
if ( V_61 )
goto V_78;
if ( ! line -> V_79 ) {
F_37 ( line -> V_23 , V_4 ) ;
line -> V_79 = 1 ;
}
F_38 ( line , & V_4 -> V_80 . V_81 ,
& V_4 -> V_80 . V_82 ) ;
V_78:
F_39 ( & line -> V_76 ) ;
return V_61 ;
}
void F_40 ( struct V_11 * V_4 , struct V_83 * V_84 )
{
struct line * line = V_4 -> V_12 ;
if ( line == NULL )
return;
F_11 ( line ) ;
F_34 ( & line -> V_76 ) ;
F_35 ( ! line -> V_77 ) ;
if ( -- line -> V_22 )
goto V_78;
line -> V_4 = NULL ;
V_4 -> V_12 = NULL ;
if ( line -> V_79 ) {
F_41 ( V_4 ) ;
line -> V_79 = 0 ;
}
V_78:
F_39 ( & line -> V_76 ) ;
}
void F_42 ( struct line * V_73 , int V_85 )
{
int V_32 ;
for( V_32 = 0 ; V_32 < V_85 ; V_32 ++ )
F_43 ( & V_73 [ V_32 ] ) ;
}
int F_44 ( struct line * V_73 , int V_6 , char * V_86 ,
const struct V_87 * V_88 , char * * V_89 )
{
struct line * line = & V_73 [ V_6 ] ;
struct V_90 * V_24 = line -> V_24 -> V_24 ;
int V_61 = - V_91 ;
F_34 ( & line -> V_76 ) ;
if ( line -> V_22 ) {
* V_89 = L_4 ;
goto V_92;
}
if ( ! strcmp ( V_86 , L_5 ) ) {
if ( line -> V_77 ) {
line -> V_77 = 0 ;
F_45 ( line -> V_93 ) ;
F_46 ( V_24 , V_6 ) ;
F_47 ( NULL , line , V_6 , V_88 , V_89 ) ;
V_61 = 0 ;
}
} else {
char * V_94 = F_48 ( V_86 , V_95 ) ;
if ( ! V_94 ) {
* V_89 = L_6 ;
return - V_96 ;
}
if ( line -> V_77 ) {
F_46 ( V_24 , V_6 ) ;
F_45 ( line -> V_93 ) ;
}
line -> V_93 = V_94 ;
line -> V_77 = 1 ;
V_61 = F_47 ( V_94 , line , V_6 , V_88 , V_89 ) ;
if ( ! V_61 ) {
struct V_97 * V_98 = F_49 ( V_24 , V_6 , NULL ) ;
if ( F_50 ( V_98 ) ) {
* V_89 = L_7 ;
V_61 = F_51 ( V_98 ) ;
F_47 ( NULL , line , V_6 , V_88 , V_89 ) ;
}
}
if ( V_61 ) {
line -> V_93 = NULL ;
line -> V_77 = 0 ;
F_45 ( V_94 ) ;
}
}
V_92:
F_39 ( & line -> V_76 ) ;
return V_61 ;
}
int F_52 ( char * * V_99 , unsigned int V_100 , char * * V_101 ,
char * V_86 , char * V_57 )
{
char * error ;
if ( * V_86 == '=' ) {
* V_101 = V_86 + 1 ;
} else {
char * V_19 ;
unsigned V_6 = F_53 ( V_86 , & V_19 , 0 ) ;
if ( * V_19 != '=' ) {
error = L_8 ;
goto V_92;
}
if ( V_6 >= V_100 ) {
error = L_9 ;
goto V_92;
}
V_99 [ V_6 ] = V_19 + 1 ;
}
return 0 ;
V_92:
F_10 ( V_21 L_10
L_11 , V_57 , V_86 , error ) ;
return - V_91 ;
}
int F_54 ( struct line * V_73 , unsigned int V_100 , char * V_102 ,
const struct V_87 * V_88 , char * * V_89 )
{
char * V_19 ;
int V_6 ;
if ( * V_102 == '=' ) {
* V_89 = L_12 ;
return - V_91 ;
}
V_6 = F_53 ( V_102 , & V_19 , 0 ) ;
if ( * V_19 ++ != '=' ) {
* V_89 = L_8 ;
return - V_91 ;
}
if ( V_6 >= V_100 ) {
* V_89 = L_9 ;
return - V_91 ;
}
return F_44 ( V_73 , V_6 , V_19 , V_88 , V_89 ) ;
}
int F_55 ( char * V_57 , struct line * V_73 , unsigned int V_100 , char * V_102 ,
int V_103 , char * * V_89 )
{
struct line * line ;
char * V_19 ;
int V_104 , V_6 = 0 ;
V_104 = F_53 ( V_57 , & V_19 , 0 ) ;
if ( ( * V_19 != '\0' ) || ( V_19 == V_57 ) ) {
* V_89 = L_13 ;
return 0 ;
}
if ( ( V_104 < 0 ) || ( V_104 >= V_100 ) ) {
* V_89 = L_14 ;
return 0 ;
}
line = & V_73 [ V_104 ] ;
F_34 ( & line -> V_76 ) ;
if ( ! line -> V_77 )
F_56 ( V_102 , V_103 , V_6 , L_5 , 1 ) ;
else if ( line -> V_4 == NULL )
F_56 ( V_102 , V_103 , V_6 , line -> V_93 , 1 ) ;
else V_6 = F_57 ( line , V_102 , V_103 , V_89 ) ;
F_39 ( & line -> V_76 ) ;
return V_6 ;
}
int F_58 ( char * * V_102 , int * V_105 , int * V_106 )
{
char * V_19 ;
int V_6 ;
V_6 = F_53 ( * V_102 , & V_19 , 0 ) ;
if ( ( * V_19 != '\0' ) || ( V_19 == * V_102 ) )
return - 1 ;
* V_102 = V_19 ;
* V_105 = V_6 ;
* V_106 = V_6 ;
return V_6 ;
}
int F_59 ( struct line * V_73 , unsigned int V_100 , int V_6 , char * * V_89 )
{
if ( V_6 >= V_100 ) {
* V_89 = L_9 ;
return - V_91 ;
}
return F_44 ( V_73 , V_6 , L_5 , NULL , V_89 ) ;
}
int F_60 ( struct V_66 * V_66 ,
const struct V_107 * V_108 ,
struct line * V_73 , int V_85 )
{
struct V_90 * V_24 = F_61 ( V_85 ) ;
int V_61 ;
int V_32 ;
if ( ! V_24 )
return - V_96 ;
V_24 -> V_109 = V_66 -> V_57 ;
V_24 -> V_57 = V_66 -> V_110 ;
V_24 -> V_111 = V_66 -> V_111 ;
V_24 -> V_112 = V_66 -> V_112 ;
V_24 -> type = V_66 -> type ;
V_24 -> V_113 = V_66 -> V_113 ;
V_24 -> V_13 = V_114 | V_115 ;
V_24 -> V_116 = V_117 ;
for ( V_32 = 0 ; V_32 < V_85 ; V_32 ++ ) {
F_62 ( & V_73 [ V_32 ] . V_15 ) ;
F_63 ( & V_73 [ V_32 ] . V_76 ) ;
V_73 [ V_32 ] . V_24 = V_66 ;
F_64 ( & V_73 [ V_32 ] . V_118 ) ;
}
F_65 ( V_24 , V_108 ) ;
V_61 = F_66 ( V_24 ) ;
if ( V_61 ) {
F_10 ( V_21 L_15 ,
V_66 -> V_57 ) ;
F_67 ( V_24 ) ;
return V_61 ;
}
V_66 -> V_24 = V_24 ;
F_68 ( & V_66 -> V_119 ) ;
return 0 ;
}
static void F_69 ( struct V_120 * V_121 )
{
struct V_122 * V_122 = F_70 ( V_121 , struct V_122 , V_121 ) ;
F_71 ( V_123 , V_122 ) ;
if ( V_122 -> V_124 != - 1 )
F_72 ( V_122 -> V_124 , 1 ) ;
if ( V_122 -> V_125 != 0 )
F_73 ( V_122 -> V_125 , 0 ) ;
F_45 ( V_122 ) ;
}
static void F_74 ( struct V_122 * V_122 )
{
int V_63 = V_122 -> V_63 ;
V_122 -> V_63 = - 1 ;
if ( V_63 != - 1 )
F_75 ( V_63 ) ;
F_76 ( & V_122 -> V_126 ) ;
F_69 ( & V_122 -> V_121 ) ;
}
static T_1 F_77 ( int V_1 , void * V_2 )
{
struct V_122 * V_122 = V_2 ;
struct V_11 * V_4 ;
struct line * line ;
int V_63 = V_122 -> V_63 ;
int V_61 ;
char V_127 ;
if ( V_63 != - 1 ) {
V_61 = F_78 ( V_63 , & V_127 , NULL ) ;
if ( V_61 < 0 ) {
if ( V_61 != - V_128 ) {
V_122 -> V_63 = - 1 ;
F_76 ( & V_122 -> V_126 ) ;
F_75 ( V_63 ) ;
F_10 ( V_21 L_16
L_17 , - V_61 ) ;
F_10 ( V_21 L_18
L_19 , V_122 -> V_129 ) ;
F_79 ( & V_122 -> V_121 , F_69 ) ;
F_80 ( & V_122 -> V_121 ) ;
return V_5 ;
}
goto V_92;
}
}
V_4 = V_122 -> V_4 ;
if ( V_4 != NULL ) {
line = V_4 -> V_12 ;
if ( line != NULL ) {
F_38 ( line , & V_4 -> V_80 . V_81 ,
& V_4 -> V_80 . V_82 ) ;
F_81 ( V_4 -> V_130 , V_131 , 1 ) ;
}
}
V_92:
if ( V_122 -> V_63 != - 1 )
F_82 ( V_122 -> V_63 , V_123 ) ;
return V_5 ;
}
void F_83 ( int V_63 , int V_129 , int V_124 , struct V_11 * V_4 ,
unsigned long V_125 )
{
struct V_122 * V_122 ;
V_122 = F_9 ( sizeof( * V_122 ) , V_95 ) ;
if ( V_122 == NULL ) {
F_10 ( V_21 L_20 ) ;
goto V_132;
}
* V_122 = ( (struct V_122 ) { . V_126 = F_84 ( V_122 -> V_126 ) ,
. V_63 = V_63 ,
. V_129 = V_129 ,
. V_124 = V_124 ,
. V_4 = V_4 ,
. V_125 = V_125 } ) ;
if ( F_32 ( V_123 , V_63 , V_69 , F_77 ,
V_67 | V_68 ,
L_21 , V_122 ) < 0 ) {
F_10 ( V_21 L_22
L_23 ) ;
goto V_133;
}
F_28 ( & V_134 ) ;
F_85 ( & V_122 -> V_126 , & V_135 ) ;
F_29 ( & V_134 ) ;
return;
V_133:
F_45 ( V_122 ) ;
V_132:
F_72 ( V_124 , 1 ) ;
F_75 ( V_63 ) ;
if ( V_125 != 0 )
F_73 ( V_125 , 0 ) ;
}
static void F_41 ( struct V_11 * V_4 )
{
struct V_136 * V_137 , * V_138 ;
struct V_122 * V_122 ;
F_28 ( & V_134 ) ;
F_86 (ele, next, &winch_handlers) {
V_122 = F_87 ( V_137 , struct V_122 , V_126 ) ;
if ( V_122 -> V_4 == V_4 ) {
F_74 ( V_122 ) ;
break;
}
}
F_29 ( & V_134 ) ;
}
static void F_88 ( void )
{
struct V_136 * V_137 , * V_138 ;
struct V_122 * V_122 ;
F_28 ( & V_134 ) ;
F_86 (ele, next, &winch_handlers) {
V_122 = F_87 ( V_137 , struct V_122 , V_126 ) ;
F_74 ( V_122 ) ;
}
F_29 ( & V_134 ) ;
}
char * F_89 ( char * V_139 )
{
char * V_140 , * V_141 ;
int V_18 ;
V_140 = F_90 () ;
if ( * V_140 == '\0' )
return V_139 ;
V_18 = strlen ( V_139 ) + strlen ( L_24 ) + strlen ( V_140 ) + 1 ;
V_141 = F_9 ( V_18 , V_95 ) ;
if ( V_141 == NULL ) {
F_10 ( V_21 L_25 ) ;
return V_139 ;
}
snprintf ( V_141 , V_18 , L_26 , V_139 , V_140 ) ;
return V_141 ;
}
