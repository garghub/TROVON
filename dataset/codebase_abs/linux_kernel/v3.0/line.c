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
int V_31 ;
F_7 ( & line -> V_22 , V_20 ) ;
V_31 = F_13 ( line ) ;
F_8 ( & line -> V_22 , V_20 ) ;
}
void F_16 ( struct V_18 * V_6 )
{
F_15 ( V_6 ) ;
}
int F_17 ( struct V_18 * V_6 , unsigned char V_32 )
{
return F_18 ( V_6 , & V_32 , sizeof( V_32 ) ) ;
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
goto V_33;
}
V_25 -= V_13 ;
V_23 += V_13 ;
if ( V_25 > 0 )
V_23 += F_10 ( line , V_24 + V_13 , V_25 ) ;
}
V_33:
F_8 ( & line -> V_22 , V_20 ) ;
return V_23 ;
}
void F_19 ( struct V_18 * V_6 , struct V_34 * V_35 )
{
}
int F_20 ( struct V_18 * V_6 , unsigned int V_36 ,
unsigned long V_37 )
{
int V_23 ;
int V_38 ;
V_23 = 0 ;
switch( V_36 ) {
#ifdef F_21
case F_21 :
case V_39 :
case V_40 :
#endif
#ifdef F_22
case F_22 :
case V_41 :
#endif
#ifdef F_23
case F_23 :
case V_42 :
#endif
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
case V_59 :
return - V_60 ;
#if 0
case TCwhatever:
break;
#endif
default:
for ( V_38 = 0 ; V_38 < F_24 ( V_61 ) ; V_38 ++ )
if ( V_36 == V_61 [ V_38 ] . V_36 )
break;
if ( V_38 == F_24 ( V_61 ) ) {
F_12 ( V_28 L_3 ,
V_62 , V_6 -> V_63 , V_36 ) ;
}
V_23 = - V_60 ;
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
int V_31 ;
F_30 ( & line -> V_22 ) ;
V_31 = F_13 ( line ) ;
if ( V_31 == 0 ) {
return V_64 ;
} else if ( V_31 < 0 ) {
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
int V_31 = 0 , V_20 = V_69 | V_70 | V_71 ;
if ( V_66 )
V_31 = F_34 ( V_11 -> V_12 , V_65 , V_72 ,
F_1 , V_20 ,
V_11 -> V_73 , V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_67 )
V_31 = F_34 ( V_11 -> V_30 , V_65 , V_74 ,
F_29 , V_20 ,
V_11 -> V_75 , V_2 ) ;
line -> V_76 = 1 ;
return V_31 ;
}
int F_35 ( struct line * V_77 , struct V_18 * V_6 )
{
struct line * line = & V_77 [ V_6 -> V_78 ] ;
int V_31 = - V_79 ;
F_30 ( & line -> V_80 ) ;
if ( ! line -> V_81 )
goto V_82;
V_31 = 0 ;
if ( V_6 -> V_29 > 1 )
goto V_82;
F_31 ( & line -> V_80 ) ;
V_6 -> V_19 = line ;
line -> V_6 = V_6 ;
V_31 = F_36 ( line ) ;
if ( V_31 )
return V_31 ;
F_37 ( & line -> V_5 , F_3 ) ;
if ( ! line -> V_83 ) {
F_38 ( & line -> V_4 , V_6 ) ;
line -> V_83 = 1 ;
}
F_39 ( & line -> V_4 , & V_6 -> V_84 . V_85 ,
& V_6 -> V_84 . V_86 ) ;
return V_31 ;
V_82:
F_31 ( & line -> V_80 ) ;
return V_31 ;
}
void F_40 ( struct V_18 * V_6 , struct V_87 * V_88 )
{
struct line * line = V_6 -> V_19 ;
if ( line == NULL )
return;
F_13 ( line ) ;
F_30 ( & line -> V_80 ) ;
if ( ! line -> V_81 )
goto V_82;
if ( V_6 -> V_29 > 1 )
goto V_82;
F_31 ( & line -> V_80 ) ;
line -> V_6 = NULL ;
V_6 -> V_19 = NULL ;
if ( line -> V_83 ) {
F_41 ( V_6 ) ;
line -> V_83 = 0 ;
}
return;
V_82:
F_31 ( & line -> V_80 ) ;
}
void F_42 ( struct line * V_77 , int V_89 )
{
int V_38 ;
for( V_38 = 0 ; V_38 < V_89 ; V_38 ++ )
F_43 ( & V_77 [ V_38 ] . V_4 , 0 ) ;
}
static int F_44 ( struct line * V_77 , int V_13 , char * V_90 , int V_91 ,
char * * V_92 )
{
struct line * line = & V_77 [ V_13 ] ;
int V_31 = - V_93 ;
F_30 ( & line -> V_80 ) ;
if ( line -> V_6 != NULL ) {
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
V_31 = 0 ;
V_94:
F_31 ( & line -> V_80 ) ;
return V_31 ;
}
int F_45 ( struct line * V_77 , unsigned int V_97 , char * V_90 ,
char * * V_92 )
{
int V_38 , V_13 , V_31 ;
char * V_26 ;
if ( * V_90 == '=' ) {
V_13 = - 1 ;
}
else {
V_13 = F_46 ( V_90 , & V_26 , 0 ) ;
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
V_31 = F_44 ( V_77 , V_13 , V_90 , V_98 , V_92 ) ;
if ( V_31 )
return V_31 ;
}
else {
for( V_38 = 0 ; V_38 < V_97 ; V_38 ++ ) {
V_31 = F_44 ( V_77 , V_38 , V_90 , V_99 ,
V_92 ) ;
if ( V_31 )
return V_31 ;
}
}
return V_13 == - 1 ? V_97 : V_13 ;
}
int F_47 ( struct line * V_77 , unsigned int V_97 , char * V_100 ,
const struct V_101 * V_102 , char * * V_92 )
{
struct line * line ;
char * V_103 ;
int V_13 ;
if ( * V_100 == '=' ) {
* V_92 = L_8 ;
return - V_93 ;
}
V_103 = F_48 ( V_100 , V_104 ) ;
if ( V_103 == NULL ) {
* V_92 = L_9 ;
return - V_105 ;
}
V_13 = F_45 ( V_77 , V_97 , V_103 , V_92 ) ;
if ( V_13 < 0 )
return V_13 ;
line = & V_77 [ V_13 ] ;
return F_49 ( line -> V_96 , line , V_13 , V_102 , V_92 ) ;
}
int F_50 ( char * V_63 , struct line * V_77 , unsigned int V_97 , char * V_100 ,
int V_106 , char * * V_92 )
{
struct line * line ;
char * V_26 ;
int V_107 , V_13 = 0 ;
V_107 = F_46 ( V_63 , & V_26 , 0 ) ;
if ( ( * V_26 != '\0' ) || ( V_26 == V_63 ) ) {
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
F_51 ( V_100 , V_106 , V_13 , L_5 , 1 ) ;
else if ( line -> V_6 == NULL )
F_51 ( V_100 , V_106 , V_13 , line -> V_96 , 1 ) ;
else V_13 = F_52 ( & line -> V_4 , V_100 , V_106 , V_92 ) ;
F_31 ( & line -> V_80 ) ;
return V_13 ;
}
int F_53 ( char * * V_100 , int * V_108 , int * V_109 )
{
char * V_26 ;
int V_13 ;
V_13 = F_46 ( * V_100 , & V_26 , 0 ) ;
if ( ( * V_26 != '\0' ) || ( V_26 == * V_100 ) )
return - 1 ;
* V_100 = V_26 ;
* V_108 = V_13 ;
* V_109 = V_13 ;
return V_13 ;
}
int F_54 ( struct line * V_77 , unsigned int V_97 , int V_13 , char * * V_92 )
{
int V_31 ;
char V_110 [ sizeof( L_12 ) ] ;
sprintf ( V_110 , L_13 , V_13 ) ;
V_31 = F_45 ( V_77 , V_97 , V_110 , V_92 ) ;
if ( V_31 >= 0 )
V_31 = 0 ;
return V_31 ;
}
struct V_111 * F_55 ( struct V_68 * V_68 ,
const struct V_112 * V_113 ,
struct line * V_77 , int V_89 )
{
int V_38 ;
struct V_111 * V_11 = F_56 ( V_89 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_114 = V_68 -> V_63 ;
V_11 -> V_63 = V_68 -> V_115 ;
V_11 -> V_116 = V_68 -> V_116 ;
V_11 -> V_117 = V_68 -> V_117 ;
V_11 -> type = V_68 -> type ;
V_11 -> V_118 = V_68 -> V_118 ;
V_11 -> V_20 = V_119 ;
V_11 -> V_120 = V_121 ;
F_57 ( V_11 , V_113 ) ;
if ( F_58 ( V_11 ) ) {
F_12 ( V_28 L_14 ,
V_68 -> V_63 ) ;
F_59 ( V_11 ) ;
return NULL ;
}
for( V_38 = 0 ; V_38 < V_89 ; V_38 ++ ) {
if ( ! V_77 [ V_38 ] . V_81 )
F_60 ( V_11 , V_38 ) ;
}
F_61 ( & V_68 -> V_122 ) ;
return V_11 ;
}
void F_62 ( struct line * V_77 , int V_89 , struct V_101 * V_102 )
{
struct line * line ;
char * error ;
int V_38 ;
for( V_38 = 0 ; V_38 < V_89 ; V_38 ++ ) {
line = & V_77 [ V_38 ] ;
F_63 ( & line -> V_4 ) ;
if ( line -> V_96 == NULL )
continue;
line -> V_96 = F_48 ( line -> V_96 , V_104 ) ;
if ( line -> V_96 == NULL )
F_12 ( V_28 L_15 ) ;
if ( F_49 ( line -> V_96 , line , V_38 , V_102 , & error ) ) {
F_12 ( V_28 L_16
L_17 , V_38 , error ) ;
line -> V_81 = 0 ;
}
}
}
static void F_64 ( struct V_123 * V_123 , int V_124 )
{
if ( V_124 )
F_65 ( V_125 , V_123 ) ;
F_66 ( & V_123 -> V_126 ) ;
if ( V_123 -> V_127 != - 1 )
F_67 ( V_123 -> V_127 , 1 ) ;
if ( V_123 -> V_65 != - 1 )
F_68 ( V_123 -> V_65 ) ;
if ( V_123 -> V_128 != 0 )
F_69 ( V_123 -> V_128 , 0 ) ;
F_70 ( V_123 ) ;
}
static T_1 F_71 ( int V_1 , void * V_2 )
{
struct V_123 * V_123 = V_2 ;
struct V_18 * V_6 ;
struct line * line ;
int V_31 ;
char V_129 ;
if ( V_123 -> V_65 != - 1 ) {
V_31 = F_72 ( V_123 -> V_65 , & V_129 , NULL ) ;
if ( V_31 < 0 ) {
if ( V_31 != - V_130 ) {
F_12 ( V_28 L_18
L_19 , - V_31 ) ;
F_12 ( V_28 L_20
L_21 , V_123 -> V_131 ) ;
F_64 ( V_123 , 0 ) ;
return V_7 ;
}
goto V_94;
}
}
V_6 = V_123 -> V_6 ;
if ( V_6 != NULL ) {
line = V_6 -> V_19 ;
if ( line != NULL ) {
F_39 ( & line -> V_4 , & V_6 -> V_84 . V_85 ,
& V_6 -> V_84 . V_86 ) ;
F_73 ( V_6 -> V_132 , V_133 , 1 ) ;
}
}
V_94:
if ( V_123 -> V_65 != - 1 )
F_74 ( V_123 -> V_65 , V_125 ) ;
return V_7 ;
}
void F_75 ( int V_65 , int V_131 , int V_127 , struct V_18 * V_6 ,
unsigned long V_128 )
{
struct V_123 * V_123 ;
V_123 = F_11 ( sizeof( * V_123 ) , V_104 ) ;
if ( V_123 == NULL ) {
F_12 ( V_28 L_22 ) ;
goto V_134;
}
* V_123 = ( (struct V_123 ) { . V_126 = F_76 ( V_123 -> V_126 ) ,
. V_65 = V_65 ,
. V_131 = V_131 ,
. V_127 = V_127 ,
. V_6 = V_6 ,
. V_128 = V_128 } ) ;
if ( F_34 ( V_125 , V_65 , V_72 , F_71 ,
V_69 | V_70 | V_71 ,
L_23 , V_123 ) < 0 ) {
F_12 ( V_28 L_24
L_25 ) ;
goto V_135;
}
F_30 ( & V_136 ) ;
F_77 ( & V_123 -> V_126 , & V_137 ) ;
F_31 ( & V_136 ) ;
return;
V_135:
F_70 ( V_123 ) ;
V_134:
F_67 ( V_127 , 1 ) ;
F_68 ( V_65 ) ;
if ( V_128 != 0 )
F_69 ( V_128 , 0 ) ;
}
static void F_41 ( struct V_18 * V_6 )
{
struct V_138 * V_139 , * V_140 ;
struct V_123 * V_123 ;
F_30 ( & V_136 ) ;
F_78 (ele, next, &winch_handlers) {
V_123 = F_79 ( V_139 , struct V_123 , V_126 ) ;
if ( V_123 -> V_6 == V_6 ) {
F_64 ( V_123 , 1 ) ;
break;
}
}
F_31 ( & V_136 ) ;
}
static void F_80 ( void )
{
struct V_138 * V_139 , * V_140 ;
struct V_123 * V_123 ;
F_30 ( & V_136 ) ;
F_78 (ele, next, &winch_handlers) {
V_123 = F_79 ( V_139 , struct V_123 , V_126 ) ;
F_64 ( V_123 , 1 ) ;
}
F_31 ( & V_136 ) ;
}
char * F_81 ( char * V_141 )
{
char * V_142 , * V_143 ;
int V_25 ;
V_142 = F_82 () ;
if ( * V_142 == '\0' )
return V_141 ;
V_25 = strlen ( V_141 ) + strlen ( L_26 ) + strlen ( V_142 ) + 1 ;
V_143 = F_11 ( V_25 , V_104 ) ;
if ( V_143 == NULL ) {
F_12 ( V_28 L_27 ) ;
return V_141 ;
}
snprintf ( V_143 , V_25 , L_28 , V_141 , V_142 ) ;
return V_143 ;
}
