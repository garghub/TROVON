static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
if ( line )
F_2 ( & line -> V_4 , & line -> V_5 , line -> V_6 , V_1 ) ;
return V_7 ;
}
static void F_3 ( struct V_8 * V_9 )
{
struct line * line = F_4 ( V_9 , struct line , V_5 . V_9 ) ;
if ( ! line -> V_10 )
F_2 ( & line -> V_4 , & line -> V_5 , line -> V_6 ,
line -> V_11 -> V_12 ) ;
}
static int F_5 ( struct line * line )
{
int V_13 ;
if ( line -> V_14 == NULL )
return V_15 - 1 ;
V_13 = line -> V_16 - line -> V_17 ;
if ( V_13 <= 0 )
V_13 += V_15 ;
return V_13 - 1 ;
}
int F_6 ( struct V_18 * V_6 )
{
struct line * line = V_6 -> V_19 ;
unsigned long V_20 ;
int V_21 ;
F_7 ( & line -> V_22 , V_20 ) ;
V_21 = F_5 ( line ) ;
F_8 ( & line -> V_22 , V_20 ) ;
return V_21 ;
}
int F_9 ( struct V_18 * V_6 )
{
struct line * line = V_6 -> V_19 ;
unsigned long V_20 ;
int V_23 ;
F_7 ( & line -> V_22 , V_20 ) ;
V_23 = V_15 - ( F_5 ( line ) + 1 ) ;
F_8 ( & line -> V_22 , V_20 ) ;
return V_23 ;
}
static int F_10 ( struct line * line , const char * V_24 , int V_25 )
{
int V_26 , V_21 ;
if ( line -> V_14 == NULL ) {
line -> V_14 = F_11 ( V_15 , V_27 ) ;
if ( line -> V_14 == NULL ) {
F_12 ( V_28 L_1
L_2 ) ;
return 0 ;
}
line -> V_16 = line -> V_14 ;
line -> V_17 = line -> V_14 ;
}
V_21 = F_5 ( line ) ;
V_25 = ( V_25 > V_21 ) ? V_21 : V_25 ;
V_26 = line -> V_14 + V_15 - line -> V_17 ;
if ( V_25 < V_26 ) {
memcpy ( line -> V_17 , V_24 , V_25 ) ;
line -> V_17 += V_25 ;
}
else {
memcpy ( line -> V_17 , V_24 , V_26 ) ;
V_24 += V_26 ;
memcpy ( line -> V_14 , V_24 , V_25 - V_26 ) ;
line -> V_17 = line -> V_14 + V_25 - V_26 ;
}
return V_25 ;
}
static int F_13 ( struct line * line )
{
int V_13 , V_29 ;
if ( ( line -> V_14 == NULL ) || ( line -> V_16 == line -> V_17 ) )
return 1 ;
if ( line -> V_17 < line -> V_16 ) {
V_29 = line -> V_14 + V_15 - line -> V_16 ;
V_13 = F_14 ( & line -> V_4 , line -> V_16 , V_29 ,
line -> V_11 -> V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == V_29 ) {
line -> V_16 = line -> V_14 ;
} else {
line -> V_16 += V_13 ;
return 0 ;
}
}
V_29 = line -> V_17 - line -> V_16 ;
V_13 = F_14 ( & line -> V_4 , line -> V_16 , V_29 ,
line -> V_11 -> V_30 ) ;
if ( V_13 < 0 )
return V_13 ;
line -> V_16 += V_13 ;
return line -> V_16 == line -> V_17 ;
}
void F_15 ( struct V_18 * V_6 )
{
struct line * line = V_6 -> V_19 ;
unsigned long V_20 ;
F_7 ( & line -> V_22 , V_20 ) ;
F_13 ( line ) ;
F_8 ( & line -> V_22 , V_20 ) ;
}
void F_16 ( struct V_18 * V_6 )
{
F_15 ( V_6 ) ;
}
int F_17 ( struct V_18 * V_6 , unsigned char V_31 )
{
return F_18 ( V_6 , & V_31 , sizeof( V_31 ) ) ;
}
int F_18 ( struct V_18 * V_6 , const unsigned char * V_24 , int V_25 )
{
struct line * line = V_6 -> V_19 ;
unsigned long V_20 ;
int V_13 , V_23 = 0 ;
F_7 ( & line -> V_22 , V_20 ) ;
if ( line -> V_16 != line -> V_17 )
V_23 = F_10 ( line , V_24 , V_25 ) ;
else {
V_13 = F_14 ( & line -> V_4 , V_24 , V_25 ,
line -> V_11 -> V_30 ) ;
if ( V_13 < 0 ) {
V_23 = V_13 ;
goto V_32;
}
V_25 -= V_13 ;
V_23 += V_13 ;
if ( V_25 > 0 )
V_23 += F_10 ( line , V_24 + V_13 , V_25 ) ;
}
V_32:
F_8 ( & line -> V_22 , V_20 ) ;
return V_23 ;
}
void F_19 ( struct V_18 * V_6 , struct V_33 * V_34 )
{
}
int F_20 ( struct V_18 * V_6 , unsigned int V_35 ,
unsigned long V_36 )
{
int V_23 ;
int V_37 ;
V_23 = 0 ;
switch( V_35 ) {
#ifdef F_21
case F_21 :
case V_38 :
case V_39 :
#endif
#ifdef F_22
case F_22 :
case V_40 :
#endif
#ifdef F_23
case F_23 :
case V_41 :
#endif
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
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return - V_59 ;
#if 0
case TCwhatever:
break;
#endif
default:
for ( V_37 = 0 ; V_37 < F_24 ( V_60 ) ; V_37 ++ )
if ( V_35 == V_60 [ V_37 ] . V_35 )
break;
if ( V_37 == F_24 ( V_60 ) ) {
F_12 ( V_28 L_3 ,
V_61 , V_6 -> V_62 , V_35 ) ;
}
V_23 = - V_59 ;
break;
}
return V_23 ;
}
void F_25 ( struct V_18 * V_6 )
{
struct line * line = V_6 -> V_19 ;
F_26 ( & line -> V_4 , line -> V_11 -> V_12 ) ;
line -> V_10 = 1 ;
}
void F_27 ( struct V_18 * V_6 )
{
struct line * line = V_6 -> V_19 ;
line -> V_10 = 0 ;
F_2 ( & line -> V_4 , & line -> V_5 , V_6 ,
line -> V_11 -> V_12 ) ;
if ( ! line -> V_10 )
F_28 ( & line -> V_4 , line -> V_11 -> V_12 ) ;
}
static T_1 F_29 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct line * line = V_3 -> line ;
struct V_18 * V_6 = line -> V_6 ;
int V_63 ;
F_30 ( & line -> V_22 ) ;
V_63 = F_13 ( line ) ;
if ( V_63 == 0 ) {
return V_64 ;
} else if ( V_63 < 0 ) {
line -> V_16 = line -> V_14 ;
line -> V_17 = line -> V_14 ;
}
F_31 ( & line -> V_22 ) ;
if ( V_6 == NULL )
return V_64 ;
F_32 ( V_6 ) ;
return V_7 ;
}
int F_33 ( int V_65 , int V_66 , int V_67 , struct line * line , void * V_2 )
{
const struct V_68 * V_11 = line -> V_11 ;
int V_63 = 0 , V_20 = V_69 | V_70 | V_71 ;
if ( V_66 )
V_63 = F_34 ( V_11 -> V_12 , V_65 , V_72 ,
F_1 , V_20 ,
V_11 -> V_73 , V_2 ) ;
if ( V_63 )
return V_63 ;
if ( V_67 )
V_63 = F_34 ( V_11 -> V_30 , V_65 , V_74 ,
F_29 , V_20 ,
V_11 -> V_75 , V_2 ) ;
line -> V_76 = 1 ;
return V_63 ;
}
int F_35 ( struct line * V_77 , struct V_18 * V_6 )
{
struct line * line = & V_77 [ V_6 -> V_78 ] ;
int V_63 = - V_79 ;
F_30 ( & line -> V_80 ) ;
if ( ! line -> V_81 )
goto V_82;
V_63 = 0 ;
if ( line -> V_29 ++ )
goto V_82;
F_36 ( V_6 -> V_19 ) ;
V_6 -> V_19 = line ;
line -> V_6 = V_6 ;
F_31 ( & line -> V_80 ) ;
V_63 = F_37 ( line ) ;
if ( V_63 )
return V_63 ;
F_38 ( & line -> V_5 , F_3 ) ;
if ( ! line -> V_83 ) {
F_39 ( & line -> V_4 , V_6 ) ;
line -> V_83 = 1 ;
}
F_40 ( & line -> V_4 , & V_6 -> V_84 . V_85 ,
& V_6 -> V_84 . V_86 ) ;
return 0 ;
V_82:
F_31 ( & line -> V_80 ) ;
return V_63 ;
}
void F_41 ( struct V_18 * V_6 , struct V_87 * V_88 )
{
struct line * line = V_6 -> V_19 ;
if ( line == NULL )
return;
F_13 ( line ) ;
F_30 ( & line -> V_80 ) ;
F_36 ( ! line -> V_81 ) ;
if ( -- line -> V_29 )
goto V_82;
line -> V_6 = NULL ;
V_6 -> V_19 = NULL ;
F_31 ( & line -> V_80 ) ;
if ( line -> V_83 ) {
F_42 ( V_6 ) ;
line -> V_83 = 0 ;
}
return;
V_82:
F_31 ( & line -> V_80 ) ;
}
void F_43 ( struct line * V_77 , int V_89 )
{
int V_37 ;
for( V_37 = 0 ; V_37 < V_89 ; V_37 ++ )
F_44 ( & V_77 [ V_37 ] . V_4 , 0 ) ;
}
static int F_45 ( struct line * V_77 , int V_13 , char * V_90 , int V_91 ,
char * * V_92 )
{
struct line * line = & V_77 [ V_13 ] ;
int V_63 = - V_93 ;
F_30 ( & line -> V_80 ) ;
if ( line -> V_29 ) {
* V_92 = L_4 ;
goto V_94;
}
if ( line -> V_95 <= V_91 ) {
line -> V_95 = V_91 ;
if ( ! strcmp ( V_90 , L_5 ) )
line -> V_81 = 0 ;
else {
line -> V_96 = V_90 ;
line -> V_81 = 1 ;
}
}
V_63 = 0 ;
V_94:
F_31 ( & line -> V_80 ) ;
return V_63 ;
}
int F_46 ( struct line * V_77 , unsigned int V_97 , char * V_90 ,
char * * V_92 )
{
int V_37 , V_13 , V_63 ;
char * V_26 ;
if ( * V_90 == '=' ) {
V_13 = - 1 ;
}
else {
V_13 = F_47 ( V_90 , & V_26 , 0 ) ;
if ( * V_26 != '=' ) {
* V_92 = L_6 ;
return - V_93 ;
}
V_90 = V_26 ;
}
V_90 ++ ;
if ( V_13 >= ( signed int ) V_97 ) {
* V_92 = L_7 ;
return - V_93 ;
}
else if ( V_13 >= 0 ) {
V_63 = F_45 ( V_77 , V_13 , V_90 , V_98 , V_92 ) ;
if ( V_63 )
return V_63 ;
}
else {
for( V_37 = 0 ; V_37 < V_97 ; V_37 ++ ) {
V_63 = F_45 ( V_77 , V_37 , V_90 , V_99 ,
V_92 ) ;
if ( V_63 )
return V_63 ;
}
}
return V_13 == - 1 ? V_97 : V_13 ;
}
int F_48 ( struct line * V_77 , unsigned int V_97 , char * V_100 ,
const struct V_101 * V_102 , char * * V_92 )
{
struct line * line ;
char * V_103 ;
int V_13 ;
if ( * V_100 == '=' ) {
* V_92 = L_8 ;
return - V_93 ;
}
V_103 = F_49 ( V_100 , V_104 ) ;
if ( V_103 == NULL ) {
* V_92 = L_9 ;
return - V_105 ;
}
V_13 = F_46 ( V_77 , V_97 , V_103 , V_92 ) ;
if ( V_13 < 0 )
return V_13 ;
line = & V_77 [ V_13 ] ;
return F_50 ( line -> V_96 , line , V_13 , V_102 , V_92 ) ;
}
int F_51 ( char * V_62 , struct line * V_77 , unsigned int V_97 , char * V_100 ,
int V_106 , char * * V_92 )
{
struct line * line ;
char * V_26 ;
int V_107 , V_13 = 0 ;
V_107 = F_47 ( V_62 , & V_26 , 0 ) ;
if ( ( * V_26 != '\0' ) || ( V_26 == V_62 ) ) {
* V_92 = L_10 ;
return 0 ;
}
if ( ( V_107 < 0 ) || ( V_107 >= V_97 ) ) {
* V_92 = L_11 ;
return 0 ;
}
line = & V_77 [ V_107 ] ;
F_30 ( & line -> V_80 ) ;
if ( ! line -> V_81 )
F_52 ( V_100 , V_106 , V_13 , L_5 , 1 ) ;
else if ( line -> V_6 == NULL )
F_52 ( V_100 , V_106 , V_13 , line -> V_96 , 1 ) ;
else V_13 = F_53 ( & line -> V_4 , V_100 , V_106 , V_92 ) ;
F_31 ( & line -> V_80 ) ;
return V_13 ;
}
int F_54 ( char * * V_100 , int * V_108 , int * V_109 )
{
char * V_26 ;
int V_13 ;
V_13 = F_47 ( * V_100 , & V_26 , 0 ) ;
if ( ( * V_26 != '\0' ) || ( V_26 == * V_100 ) )
return - 1 ;
* V_100 = V_26 ;
* V_108 = V_13 ;
* V_109 = V_13 ;
return V_13 ;
}
int F_55 ( struct line * V_77 , unsigned int V_97 , int V_13 , char * * V_92 )
{
int V_63 ;
char V_110 [ sizeof( L_12 ) ] ;
sprintf ( V_110 , L_13 , V_13 ) ;
V_63 = F_46 ( V_77 , V_97 , V_110 , V_92 ) ;
if ( V_63 >= 0 )
V_63 = 0 ;
return V_63 ;
}
struct V_111 * F_56 ( struct V_68 * V_68 ,
const struct V_112 * V_113 ,
struct line * V_77 , int V_89 )
{
int V_37 ;
struct V_111 * V_11 = F_57 ( V_89 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_114 = V_68 -> V_62 ;
V_11 -> V_62 = V_68 -> V_115 ;
V_11 -> V_116 = V_68 -> V_116 ;
V_11 -> V_117 = V_68 -> V_117 ;
V_11 -> type = V_68 -> type ;
V_11 -> V_118 = V_68 -> V_118 ;
V_11 -> V_20 = V_119 ;
V_11 -> V_120 = V_121 ;
F_58 ( V_11 , V_113 ) ;
if ( F_59 ( V_11 ) ) {
F_12 ( V_28 L_14 ,
V_68 -> V_62 ) ;
F_60 ( V_11 ) ;
return NULL ;
}
for( V_37 = 0 ; V_37 < V_89 ; V_37 ++ ) {
if ( ! V_77 [ V_37 ] . V_81 )
F_61 ( V_11 , V_37 ) ;
}
F_62 ( & V_68 -> V_122 ) ;
return V_11 ;
}
void F_63 ( struct line * V_77 , int V_89 , struct V_101 * V_102 )
{
struct line * line ;
char * error ;
int V_37 ;
for( V_37 = 0 ; V_37 < V_89 ; V_37 ++ ) {
line = & V_77 [ V_37 ] ;
F_64 ( & line -> V_4 ) ;
if ( line -> V_96 == NULL )
continue;
line -> V_96 = F_49 ( line -> V_96 , V_104 ) ;
if ( line -> V_96 == NULL )
F_12 ( V_28 L_15 ) ;
if ( F_50 ( line -> V_96 , line , V_37 , V_102 , & error ) ) {
F_12 ( V_28 L_16
L_17 , V_37 , error ) ;
line -> V_81 = 0 ;
}
}
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_123 * V_123 = F_4 ( V_9 , struct V_123 , V_9 ) ;
F_66 ( V_124 , V_123 ) ;
if ( V_123 -> V_125 != - 1 )
F_67 ( V_123 -> V_125 , 1 ) ;
if ( V_123 -> V_126 != 0 )
F_68 ( V_123 -> V_126 , 0 ) ;
F_69 ( V_123 ) ;
}
static void F_70 ( struct V_123 * V_123 )
{
int V_65 = V_123 -> V_65 ;
V_123 -> V_65 = - 1 ;
if ( V_65 != - 1 )
F_71 ( V_65 ) ;
F_72 ( & V_123 -> V_127 ) ;
F_65 ( & V_123 -> V_9 ) ;
}
static T_1 F_73 ( int V_1 , void * V_2 )
{
struct V_123 * V_123 = V_2 ;
struct V_18 * V_6 ;
struct line * line ;
int V_65 = V_123 -> V_65 ;
int V_63 ;
char V_128 ;
if ( V_65 != - 1 ) {
V_63 = F_74 ( V_65 , & V_128 , NULL ) ;
if ( V_63 < 0 ) {
if ( V_63 != - V_129 ) {
V_123 -> V_65 = - 1 ;
F_72 ( & V_123 -> V_127 ) ;
F_71 ( V_65 ) ;
F_12 ( V_28 L_18
L_19 , - V_63 ) ;
F_12 ( V_28 L_20
L_21 , V_123 -> V_130 ) ;
F_75 ( & V_123 -> V_9 , F_65 ) ;
F_76 ( & V_123 -> V_9 ) ;
return V_7 ;
}
goto V_94;
}
}
V_6 = V_123 -> V_6 ;
if ( V_6 != NULL ) {
line = V_6 -> V_19 ;
if ( line != NULL ) {
F_40 ( & line -> V_4 , & V_6 -> V_84 . V_85 ,
& V_6 -> V_84 . V_86 ) ;
F_77 ( V_6 -> V_131 , V_132 , 1 ) ;
}
}
V_94:
if ( V_123 -> V_65 != - 1 )
F_78 ( V_123 -> V_65 , V_124 ) ;
return V_7 ;
}
void F_79 ( int V_65 , int V_130 , int V_125 , struct V_18 * V_6 ,
unsigned long V_126 )
{
struct V_123 * V_123 ;
V_123 = F_11 ( sizeof( * V_123 ) , V_104 ) ;
if ( V_123 == NULL ) {
F_12 ( V_28 L_22 ) ;
goto V_133;
}
* V_123 = ( (struct V_123 ) { . V_127 = F_80 ( V_123 -> V_127 ) ,
. V_65 = V_65 ,
. V_130 = V_130 ,
. V_125 = V_125 ,
. V_6 = V_6 ,
. V_126 = V_126 } ) ;
if ( F_34 ( V_124 , V_65 , V_72 , F_73 ,
V_69 | V_70 | V_71 ,
L_23 , V_123 ) < 0 ) {
F_12 ( V_28 L_24
L_25 ) ;
goto V_134;
}
F_30 ( & V_135 ) ;
F_81 ( & V_123 -> V_127 , & V_136 ) ;
F_31 ( & V_135 ) ;
return;
V_134:
F_69 ( V_123 ) ;
V_133:
F_67 ( V_125 , 1 ) ;
F_71 ( V_65 ) ;
if ( V_126 != 0 )
F_68 ( V_126 , 0 ) ;
}
static void F_42 ( struct V_18 * V_6 )
{
struct V_137 * V_138 , * V_139 ;
struct V_123 * V_123 ;
F_30 ( & V_135 ) ;
F_82 (ele, next, &winch_handlers) {
V_123 = F_83 ( V_138 , struct V_123 , V_127 ) ;
if ( V_123 -> V_6 == V_6 ) {
F_70 ( V_123 ) ;
break;
}
}
F_31 ( & V_135 ) ;
}
static void F_84 ( void )
{
struct V_137 * V_138 , * V_139 ;
struct V_123 * V_123 ;
F_30 ( & V_135 ) ;
F_82 (ele, next, &winch_handlers) {
V_123 = F_83 ( V_138 , struct V_123 , V_127 ) ;
F_70 ( V_123 ) ;
}
F_31 ( & V_135 ) ;
}
char * F_85 ( char * V_140 )
{
char * V_141 , * V_142 ;
int V_25 ;
V_141 = F_86 () ;
if ( * V_141 == '\0' )
return V_140 ;
V_25 = strlen ( V_140 ) + strlen ( L_26 ) + strlen ( V_141 ) + 1 ;
V_142 = F_11 ( V_25 , V_104 ) ;
if ( V_142 == NULL ) {
F_12 ( V_28 L_27 ) ;
return V_140 ;
}
snprintf ( V_142 , V_25 , L_28 , V_140 , V_141 ) ;
return V_142 ;
}
