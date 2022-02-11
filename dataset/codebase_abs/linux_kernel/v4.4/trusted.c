static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
int V_4 ;
V_4 = sizeof( struct V_5 ) + F_2 ( V_3 ) ;
V_1 = F_3 ( V_4 , V_6 ) ;
if ( ! V_1 )
return F_4 ( - V_7 ) ;
V_1 -> V_8 . V_9 = V_3 ;
V_1 -> V_8 . V_10 = 0x0 ;
return V_1 ;
}
static int F_5 ( const unsigned char * V_11 , unsigned int V_12 ,
unsigned char * V_13 )
{
struct V_1 * V_1 ;
int V_14 ;
V_1 = F_1 ( V_15 ) ;
if ( F_6 ( V_1 ) ) {
F_7 ( L_1 , V_16 ) ;
return F_8 ( V_1 ) ;
}
V_14 = F_9 ( & V_1 -> V_8 , V_11 , V_12 , V_13 ) ;
F_10 ( V_1 ) ;
return V_14 ;
}
static int F_11 ( unsigned char * V_13 , const unsigned char * V_17 ,
unsigned int V_18 , ... )
{
struct V_1 * V_1 ;
T_1 V_19 ;
unsigned int V_20 ;
unsigned char * V_11 ;
int V_14 ;
V_1 = F_1 ( V_21 ) ;
if ( F_6 ( V_1 ) ) {
F_7 ( L_1 , V_22 ) ;
return F_8 ( V_1 ) ;
}
V_14 = F_12 ( V_21 , V_17 , V_18 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_13 ( & V_1 -> V_8 ) ;
if ( V_14 < 0 )
goto V_23;
va_start ( V_19 , V_18 ) ;
for (; ; ) {
V_20 = va_arg (argp, unsigned int) ;
if ( V_20 == 0 )
break;
V_11 = va_arg (argp, unsigned char *) ;
if ( V_11 == NULL ) {
V_14 = - V_24 ;
break;
}
V_14 = F_14 ( & V_1 -> V_8 , V_11 , V_20 ) ;
if ( V_14 < 0 )
break;
}
va_end ( V_19 ) ;
if ( ! V_14 )
V_14 = F_15 ( & V_1 -> V_8 , V_13 ) ;
V_23:
F_10 ( V_1 ) ;
return V_14 ;
}
static int F_16 ( unsigned char * V_13 , const unsigned char * V_17 ,
unsigned int V_18 , unsigned char * V_25 ,
unsigned char * V_26 , unsigned char V_27 , ... )
{
unsigned char V_28 [ V_29 ] ;
struct V_1 * V_1 ;
unsigned int V_20 ;
unsigned char * V_11 ;
unsigned char V_30 ;
int V_14 ;
T_1 V_19 ;
V_1 = F_1 ( V_15 ) ;
if ( F_6 ( V_1 ) ) {
F_7 ( L_1 , V_16 ) ;
return F_8 ( V_1 ) ;
}
V_30 = V_27 ;
V_14 = F_13 ( & V_1 -> V_8 ) ;
if ( V_14 < 0 )
goto V_23;
va_start ( V_19 , V_27 ) ;
for (; ; ) {
V_20 = va_arg (argp, unsigned int) ;
if ( V_20 == 0 )
break;
V_11 = va_arg (argp, unsigned char *) ;
if ( ! V_11 ) {
V_14 = - V_24 ;
break;
}
V_14 = F_14 ( & V_1 -> V_8 , V_11 , V_20 ) ;
if ( V_14 < 0 )
break;
}
va_end ( V_19 ) ;
if ( ! V_14 )
V_14 = F_15 ( & V_1 -> V_8 , V_28 ) ;
if ( ! V_14 )
V_14 = F_11 ( V_13 , V_17 , V_18 , V_29 ,
V_28 , V_31 , V_25 ,
V_31 , V_26 , 1 , & V_30 , 0 , 0 ) ;
V_23:
F_10 ( V_1 ) ;
return V_14 ;
}
static int F_17 ( unsigned char * V_32 ,
const T_2 V_33 ,
const unsigned char * V_34 ,
const unsigned char * V_17 ,
unsigned int V_18 , ... )
{
T_2 V_35 ;
T_3 V_36 ;
T_2 V_37 ;
T_2 V_38 ;
unsigned char * V_39 ;
unsigned char * V_40 ;
unsigned char * V_41 ;
unsigned char V_42 [ V_29 ] ;
unsigned char V_28 [ V_29 ] ;
struct V_1 * V_1 ;
unsigned int V_20 ;
unsigned int V_43 ;
T_1 V_19 ;
int V_14 ;
V_35 = F_18 ( V_32 , V_44 ) ;
V_36 = F_19 ( V_32 , 0 ) ;
V_37 = V_33 ;
V_38 = F_20 ( V_32 , V_45 ) ;
if ( V_36 == V_46 )
return 0 ;
if ( V_36 != V_47 )
return - V_24 ;
V_41 = V_32 + V_35 - V_29 ;
V_40 = V_41 - 1 ;
V_39 = V_40 - V_31 ;
V_1 = F_1 ( V_15 ) ;
if ( F_6 ( V_1 ) ) {
F_7 ( L_1 , V_16 ) ;
return F_8 ( V_1 ) ;
}
V_14 = F_13 ( & V_1 -> V_8 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_14 ( & V_1 -> V_8 , ( const V_48 * ) & V_38 ,
sizeof V_38 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_14 ( & V_1 -> V_8 , ( const V_48 * ) & V_37 ,
sizeof V_37 ) ;
if ( V_14 < 0 )
goto V_23;
va_start ( V_19 , V_18 ) ;
for (; ; ) {
V_20 = va_arg (argp, unsigned int) ;
if ( V_20 == 0 )
break;
V_43 = va_arg (argp, unsigned int) ;
V_14 = F_14 ( & V_1 -> V_8 , V_32 + V_43 , V_20 ) ;
if ( V_14 < 0 )
break;
}
va_end ( V_19 ) ;
if ( ! V_14 )
V_14 = F_15 ( & V_1 -> V_8 , V_28 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_11 ( V_42 , V_17 , V_18 , V_29 , V_28 ,
V_31 , V_39 , V_31 , V_34 ,
1 , V_40 , 0 , 0 ) ;
if ( V_14 < 0 )
goto V_23;
if ( memcmp ( V_42 , V_41 , V_29 ) )
V_14 = - V_24 ;
V_23:
F_10 ( V_1 ) ;
return V_14 ;
}
static int F_21 ( unsigned char * V_32 ,
const T_2 V_33 ,
const unsigned char * V_34 ,
const unsigned char * V_49 ,
unsigned int V_50 ,
const unsigned char * V_51 ,
unsigned int V_52 , ... )
{
T_2 V_35 ;
T_3 V_36 ;
T_2 V_37 ;
T_2 V_38 ;
unsigned char * V_53 ;
unsigned char * V_54 ;
unsigned char * V_55 ;
unsigned char * V_56 ;
unsigned char * V_57 ;
unsigned char * V_58 ;
unsigned char V_59 [ V_29 ] ;
unsigned char V_60 [ V_29 ] ;
unsigned char V_28 [ V_29 ] ;
struct V_1 * V_1 ;
unsigned int V_20 ;
unsigned int V_43 ;
T_1 V_19 ;
int V_14 ;
V_35 = F_18 ( V_32 , V_44 ) ;
V_36 = F_19 ( V_32 , 0 ) ;
V_37 = V_33 ;
V_38 = F_20 ( V_32 , V_45 ) ;
if ( V_36 == V_46 )
return 0 ;
if ( V_36 != V_61 )
return - V_24 ;
V_55 = V_32 + V_35 - ( V_29 + 1
+ V_29 + V_29 ) ;
V_58 = V_32 + V_35 - ( V_29 ) ;
V_54 = V_55 - 1 ;
V_57 = V_58 - 1 ;
V_53 = V_54 - V_31 ;
V_56 = V_57 - V_31 ;
V_1 = F_1 ( V_15 ) ;
if ( F_6 ( V_1 ) ) {
F_7 ( L_1 , V_16 ) ;
return F_8 ( V_1 ) ;
}
V_14 = F_13 ( & V_1 -> V_8 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_14 ( & V_1 -> V_8 , ( const V_48 * ) & V_38 ,
sizeof V_38 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_14 ( & V_1 -> V_8 , ( const V_48 * ) & V_37 ,
sizeof V_37 ) ;
if ( V_14 < 0 )
goto V_23;
va_start ( V_19 , V_52 ) ;
for (; ; ) {
V_20 = va_arg (argp, unsigned int) ;
if ( V_20 == 0 )
break;
V_43 = va_arg (argp, unsigned int) ;
V_14 = F_14 ( & V_1 -> V_8 , V_32 + V_43 , V_20 ) ;
if ( V_14 < 0 )
break;
}
va_end ( V_19 ) ;
if ( ! V_14 )
V_14 = F_15 ( & V_1 -> V_8 , V_28 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_11 ( V_59 , V_49 , V_50 , V_29 ,
V_28 , V_31 , V_53 ,
V_31 , V_34 , 1 , V_54 , 0 , 0 ) ;
if ( V_14 < 0 )
goto V_23;
if ( memcmp ( V_59 , V_55 , V_29 ) ) {
V_14 = - V_24 ;
goto V_23;
}
V_14 = F_11 ( V_60 , V_51 , V_52 , V_29 ,
V_28 , V_31 , V_56 ,
V_31 , V_34 , 1 , V_57 , 0 , 0 ) ;
if ( V_14 < 0 )
goto V_23;
if ( memcmp ( V_60 , V_58 , V_29 ) )
V_14 = - V_24 ;
V_23:
F_10 ( V_1 ) ;
return V_14 ;
}
static int F_22 ( const T_4 V_62 , unsigned char * V_63 ,
T_5 V_64 )
{
int V_65 ;
F_23 ( V_63 ) ;
V_65 = F_24 ( V_62 , V_63 , V_64 ) ;
F_23 ( V_63 ) ;
if ( V_65 > 0 )
V_65 = - V_66 ;
return V_65 ;
}
static int F_25 ( const int V_67 )
{
unsigned char V_68 [ V_29 ] ;
int V_14 ;
if ( ! F_26 ( V_69 ) )
return - V_66 ;
V_14 = F_27 ( V_70 , V_68 , V_29 ) ;
if ( V_14 != V_29 )
return V_14 ;
return F_28 ( V_70 , V_67 , V_68 ) ? - V_24 : 0 ;
}
static int F_29 ( struct V_71 * V_72 , struct V_73 * V_74 ,
const unsigned char * V_17 , T_3 type , T_2 V_75 )
{
unsigned char V_39 [ V_31 ] ;
unsigned char V_34 [ V_31 ] ;
int V_14 ;
V_14 = F_27 ( V_70 , V_34 , V_31 ) ;
if ( V_14 != V_31 )
return V_14 ;
F_30 ( V_72 ) ;
F_31 ( V_72 , V_76 ) ;
F_32 ( V_72 , V_77 ) ;
F_32 ( V_72 , V_78 ) ;
F_31 ( V_72 , type ) ;
F_32 ( V_72 , V_75 ) ;
F_33 ( V_72 , V_34 , V_31 ) ;
V_14 = F_22 ( V_70 , V_72 -> V_11 , V_79 ) ;
if ( V_14 < 0 )
return V_14 ;
V_74 -> V_75 = F_18 ( V_72 -> V_11 , V_80 ) ;
memcpy ( V_74 -> V_39 , & ( V_72 -> V_11 [ V_80 + sizeof( T_2 ) ] ) ,
V_31 ) ;
memcpy ( V_39 , & ( V_72 -> V_11 [ V_80 + sizeof( T_2 ) +
V_31 ] ) , V_31 ) ;
return F_11 ( V_74 -> V_81 , V_17 , V_29 , V_31 ,
V_39 , V_31 , V_34 , 0 , 0 ) ;
}
static int F_34 ( struct V_71 * V_72 , T_2 * V_75 , unsigned char * V_82 )
{
int V_14 ;
F_30 ( V_72 ) ;
F_31 ( V_72 , V_76 ) ;
F_32 ( V_72 , V_83 ) ;
F_32 ( V_72 , V_84 ) ;
V_14 = F_22 ( V_70 , V_72 -> V_11 , V_79 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_75 = F_18 ( V_72 -> V_11 , V_80 ) ;
memcpy ( V_82 , & V_72 -> V_11 [ V_80 + sizeof( T_2 ) ] ,
V_31 ) ;
return 0 ;
}
static int F_35 ( struct V_71 * V_72 , T_3 V_85 ,
T_2 V_86 , const unsigned char * V_87 ,
const unsigned char * V_11 , T_2 V_12 ,
unsigned char * V_88 , T_2 * V_89 ,
const unsigned char * V_90 ,
const unsigned char * V_91 , T_2 V_92 )
{
struct V_73 V_93 ;
struct V_94 * V_95 ;
unsigned char V_96 ;
T_2 V_37 ;
T_2 V_97 ;
T_2 V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
int V_14 ;
int V_102 ;
V_95 = F_3 ( sizeof *V_95 , V_6 ) ;
if ( ! V_95 )
return - V_7 ;
V_14 = F_29 ( V_72 , & V_93 , V_87 , V_85 , V_86 ) ;
if ( V_14 < 0 )
goto V_23;
F_36 ( & V_93 ) ;
memcpy ( V_95 -> V_103 , V_93 . V_81 , V_29 ) ;
memcpy ( V_95 -> V_103 + V_29 , V_93 . V_39 , V_29 ) ;
V_14 = F_5 ( V_95 -> V_103 , V_29 * 2 , V_95 -> V_104 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_27 ( V_70 , V_95 -> V_105 , V_31 ) ;
if ( V_14 != V_31 )
goto V_23;
V_37 = F_37 ( V_106 ) ;
V_98 = F_37 ( V_12 ) ;
V_97 = F_37 ( V_92 ) ;
V_96 = 0 ;
for ( V_102 = 0 ; V_102 < V_29 ; ++ V_102 )
V_95 -> V_107 [ V_102 ] = V_95 -> V_104 [ V_102 ] ^ V_90 [ V_102 ] ;
if ( V_92 == 0 ) {
V_14 = F_16 ( V_95 -> V_108 , V_93 . V_81 , V_29 ,
V_93 . V_39 , V_95 -> V_105 , V_96 ,
sizeof( T_2 ) , & V_37 , V_29 ,
V_95 -> V_107 , sizeof( T_2 ) , & V_97 ,
sizeof( T_2 ) , & V_98 , V_12 , V_11 , 0 ,
0 ) ;
} else {
V_14 = F_16 ( V_95 -> V_108 , V_93 . V_81 , V_29 ,
V_93 . V_39 , V_95 -> V_105 , V_96 ,
sizeof( T_2 ) , & V_37 , V_29 ,
V_95 -> V_107 , sizeof( T_2 ) , & V_97 ,
V_92 , V_91 , sizeof( T_2 ) ,
& V_98 , V_12 , V_11 , 0 , 0 ) ;
}
if ( V_14 < 0 )
goto V_23;
F_30 ( V_72 ) ;
F_31 ( V_72 , V_109 ) ;
F_32 ( V_72 , V_110 + V_92 + V_12 ) ;
F_32 ( V_72 , V_106 ) ;
F_32 ( V_72 , V_86 ) ;
F_33 ( V_72 , V_95 -> V_107 , V_29 ) ;
F_32 ( V_72 , V_92 ) ;
F_33 ( V_72 , V_91 , V_92 ) ;
F_32 ( V_72 , V_12 ) ;
F_33 ( V_72 , V_11 , V_12 ) ;
F_32 ( V_72 , V_93 . V_75 ) ;
F_33 ( V_72 , V_95 -> V_105 , V_31 ) ;
F_38 ( V_72 , V_96 ) ;
F_33 ( V_72 , V_95 -> V_108 , V_29 ) ;
V_14 = F_22 ( V_70 , V_72 -> V_11 , V_79 ) ;
if ( V_14 < 0 )
goto V_23;
V_99 = F_18 ( V_72 -> V_11 , V_80 + sizeof( T_2 ) ) ;
V_100 = F_18 ( V_72 -> V_11 , V_80 + sizeof( T_2 ) +
sizeof( T_2 ) + V_99 ) ;
V_101 = sizeof( T_2 ) + sizeof( T_2 ) + V_99 +
sizeof( T_2 ) + V_100 ;
V_14 = F_17 ( V_72 -> V_11 , V_37 , V_95 -> V_105 , V_93 . V_81 ,
V_29 , V_101 , V_80 , 0 ,
0 ) ;
if ( ! V_14 ) {
memcpy ( V_88 , V_72 -> V_11 + V_80 , V_101 ) ;
* V_89 = V_101 ;
}
V_23:
F_10 ( V_95 ) ;
return V_14 ;
}
static int F_39 ( struct V_71 * V_72 ,
T_2 V_86 , const unsigned char * V_87 ,
const unsigned char * V_88 , int V_89 ,
const unsigned char * V_90 ,
unsigned char * V_11 , unsigned int * V_12 )
{
unsigned char V_105 [ V_31 ] ;
unsigned char V_53 [ V_31 ] ;
unsigned char V_56 [ V_31 ] ;
unsigned char V_55 [ V_29 ] ;
unsigned char V_58 [ V_29 ] ;
T_2 V_111 = 0 ;
T_2 V_112 = 0 ;
unsigned char V_96 = 0 ;
T_2 V_37 ;
T_2 V_113 ;
int V_14 ;
V_14 = F_34 ( V_72 , & V_111 , V_53 ) ;
if ( V_14 < 0 ) {
F_7 ( L_2 , V_14 ) ;
return V_14 ;
}
V_14 = F_34 ( V_72 , & V_112 , V_56 ) ;
if ( V_14 < 0 ) {
F_7 ( L_2 , V_14 ) ;
return V_14 ;
}
V_37 = F_37 ( V_114 ) ;
V_113 = F_37 ( V_115 ) ;
V_14 = F_27 ( V_70 , V_105 , V_31 ) ;
if ( V_14 != V_31 ) {
F_7 ( L_3 , V_14 ) ;
return V_14 ;
}
V_14 = F_16 ( V_55 , V_87 , V_31 ,
V_53 , V_105 , V_96 , sizeof( T_2 ) ,
& V_37 , V_89 , V_88 , 0 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_16 ( V_58 , V_90 , V_31 ,
V_56 , V_105 , V_96 , sizeof( T_2 ) ,
& V_37 , V_89 , V_88 , 0 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
F_30 ( V_72 ) ;
F_31 ( V_72 , V_116 ) ;
F_32 ( V_72 , V_117 + V_89 ) ;
F_32 ( V_72 , V_114 ) ;
F_32 ( V_72 , V_86 ) ;
F_33 ( V_72 , V_88 , V_89 ) ;
F_32 ( V_72 , V_111 ) ;
F_33 ( V_72 , V_105 , V_31 ) ;
F_38 ( V_72 , V_96 ) ;
F_33 ( V_72 , V_55 , V_29 ) ;
F_32 ( V_72 , V_112 ) ;
F_33 ( V_72 , V_105 , V_31 ) ;
F_38 ( V_72 , V_96 ) ;
F_33 ( V_72 , V_58 , V_29 ) ;
V_14 = F_22 ( V_70 , V_72 -> V_11 , V_79 ) ;
if ( V_14 < 0 ) {
F_7 ( L_4 , V_14 ) ;
return V_14 ;
}
* V_12 = F_18 ( V_72 -> V_11 , V_80 ) ;
V_14 = F_21 ( V_72 -> V_11 , V_37 , V_105 ,
V_87 , V_29 ,
V_90 , V_29 ,
sizeof( T_2 ) , V_80 ,
* V_12 , V_80 + sizeof( T_2 ) , 0 ,
0 ) ;
if ( V_14 < 0 ) {
F_7 ( L_5 , V_14 ) ;
return V_14 ;
}
memcpy ( V_11 , V_72 -> V_11 + V_80 + sizeof( T_2 ) , * V_12 ) ;
return 0 ;
}
static int F_40 ( struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_71 * V_72 ;
int V_14 ;
V_72 = F_41 ( sizeof *V_72 , V_6 ) ;
if ( ! V_72 )
return - V_7 ;
V_119 -> V_17 [ V_119 -> V_122 ] = V_119 -> V_123 ;
V_14 = F_35 ( V_72 , V_121 -> V_85 , V_121 -> V_86 , V_121 -> V_87 ,
V_119 -> V_17 , V_119 -> V_122 + 1 , V_119 -> V_88 , & V_119 -> V_124 ,
V_121 -> V_90 , V_121 -> V_91 , V_121 -> V_125 ) ;
if ( V_14 < 0 )
F_7 ( L_6 , V_14 ) ;
F_10 ( V_72 ) ;
return V_14 ;
}
static int F_42 ( struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_71 * V_72 ;
int V_14 ;
V_72 = F_41 ( sizeof *V_72 , V_6 ) ;
if ( ! V_72 )
return - V_7 ;
V_14 = F_39 ( V_72 , V_121 -> V_86 , V_121 -> V_87 , V_119 -> V_88 , V_119 -> V_124 ,
V_121 -> V_90 , V_119 -> V_17 , & V_119 -> V_122 ) ;
if ( V_14 < 0 )
F_7 ( L_7 , V_14 ) ;
else
V_119 -> V_123 = V_119 -> V_17 [ -- V_119 -> V_122 ] ;
F_10 ( V_72 ) ;
return V_14 ;
}
static int F_43 ( char * V_30 , struct V_118 * V_126 ,
struct V_120 * V_127 )
{
T_6 args [ V_128 ] ;
char * V_119 = V_30 ;
int V_129 ;
int V_130 ;
unsigned long V_75 ;
unsigned long V_131 ;
while ( ( V_119 = F_44 ( & V_30 , L_8 ) ) ) {
if ( * V_119 == '\0' || * V_119 == ' ' || * V_119 == '\t' )
continue;
V_129 = F_45 ( V_119 , V_132 , args ) ;
switch ( V_129 ) {
case V_133 :
V_127 -> V_125 = strlen ( args [ 0 ] . V_134 ) / 2 ;
if ( V_127 -> V_125 > V_135 )
return - V_24 ;
V_130 = F_46 ( V_127 -> V_91 , args [ 0 ] . V_134 ,
V_127 -> V_125 ) ;
if ( V_130 < 0 )
return - V_24 ;
break;
case V_136 :
V_130 = F_47 ( args [ 0 ] . V_134 , 16 , & V_75 ) ;
if ( V_130 < 0 )
return - V_24 ;
V_127 -> V_85 = V_137 ;
V_127 -> V_86 = V_75 ;
break;
case V_138 :
if ( strlen ( args [ 0 ] . V_134 ) != 2 * V_29 )
return - V_24 ;
V_130 = F_46 ( V_127 -> V_87 , args [ 0 ] . V_134 ,
V_29 ) ;
if ( V_130 < 0 )
return - V_24 ;
break;
case V_139 :
if ( strlen ( args [ 0 ] . V_134 ) != 2 * V_29 )
return - V_24 ;
V_130 = F_46 ( V_127 -> V_90 , args [ 0 ] . V_134 ,
V_29 ) ;
if ( V_130 < 0 )
return - V_24 ;
break;
case V_140 :
if ( * args [ 0 ] . V_134 == '0' )
V_126 -> V_123 = 0 ;
else
return - V_24 ;
break;
case V_141 :
V_130 = F_47 ( args [ 0 ] . V_134 , 10 , & V_131 ) ;
if ( V_130 < 0 )
return - V_24 ;
V_127 -> F_25 = V_131 ;
break;
default:
return - V_24 ;
}
}
return 0 ;
}
static int F_48 ( char * V_142 , struct V_118 * V_119 ,
struct V_120 * V_121 )
{
T_6 args [ V_128 ] ;
long V_18 ;
int V_14 = - V_24 ;
int V_143 ;
char * V_30 ;
V_30 = F_44 ( & V_142 , L_8 ) ;
if ( ! V_30 )
return - V_24 ;
V_143 = F_45 ( V_30 , V_132 , args ) ;
switch ( V_143 ) {
case V_144 :
V_30 = F_44 ( & V_142 , L_8 ) ;
if ( ! V_30 )
return - V_24 ;
V_14 = F_49 ( V_30 , 10 , & V_18 ) ;
if ( V_14 < 0 || V_18 < V_145 || V_18 > V_146 )
return - V_24 ;
V_119 -> V_122 = V_18 ;
V_14 = F_43 ( V_142 , V_119 , V_121 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_144 ;
break;
case V_147 :
V_30 = F_44 ( & V_142 , L_8 ) ;
if ( ! V_30 )
return - V_24 ;
V_119 -> V_124 = strlen ( V_30 ) / 2 ;
if ( V_119 -> V_124 > V_148 )
return - V_24 ;
V_14 = F_46 ( V_119 -> V_88 , V_30 , V_119 -> V_124 ) ;
if ( V_14 < 0 )
return - V_24 ;
V_14 = F_43 ( V_142 , V_119 , V_121 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_147 ;
break;
case V_149 :
V_14 = F_43 ( V_142 , V_119 , V_121 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_149 ;
break;
case V_150 :
return - V_24 ;
break;
}
return V_14 ;
}
static struct V_120 * F_50 ( void )
{
struct V_120 * V_151 ;
int V_152 ;
V_152 = F_51 ( V_70 ) ;
if ( V_152 < 0 )
return NULL ;
V_151 = F_41 ( sizeof *V_151 , V_6 ) ;
if ( V_151 ) {
V_151 -> V_85 = V_153 ;
if ( ! V_152 )
V_151 -> V_86 = V_115 ;
}
return V_151 ;
}
static struct V_118 * F_52 ( struct V_17 * V_17 )
{
struct V_118 * V_119 = NULL ;
int V_14 ;
V_14 = F_53 ( V_17 , sizeof *V_119 ) ;
if ( V_14 < 0 )
return V_119 ;
V_119 = F_41 ( sizeof *V_119 , V_6 ) ;
if ( V_119 )
V_119 -> V_123 = 1 ;
return V_119 ;
}
static int F_54 ( struct V_17 * V_17 ,
struct V_154 * V_155 )
{
struct V_118 * V_156 = NULL ;
struct V_120 * V_151 = NULL ;
T_5 V_12 = V_155 -> V_12 ;
char * V_142 ;
int V_14 = 0 ;
int V_143 ;
T_5 V_122 ;
int V_152 ;
V_152 = F_51 ( V_70 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_12 <= 0 || V_12 > 32767 || ! V_155 -> V_11 )
return - V_24 ;
V_142 = F_3 ( V_12 + 1 , V_6 ) ;
if ( ! V_142 )
return - V_7 ;
memcpy ( V_142 , V_155 -> V_11 , V_12 ) ;
V_142 [ V_12 ] = '\0' ;
V_151 = F_50 () ;
if ( ! V_151 ) {
V_14 = - V_7 ;
goto V_23;
}
V_156 = F_52 ( V_17 ) ;
if ( ! V_156 ) {
V_14 = - V_7 ;
goto V_23;
}
V_143 = F_48 ( V_142 , V_156 , V_151 ) ;
if ( V_143 < 0 ) {
V_14 = V_143 ;
goto V_23;
}
if ( ! V_151 -> V_86 ) {
V_14 = - V_24 ;
goto V_23;
}
F_55 ( V_156 ) ;
F_56 ( V_151 ) ;
switch ( V_143 ) {
case V_147 :
if ( V_152 )
V_14 = F_57 ( V_70 , V_156 , V_151 ) ;
else
V_14 = F_42 ( V_156 , V_151 ) ;
F_55 ( V_156 ) ;
F_56 ( V_151 ) ;
if ( V_14 < 0 )
F_7 ( L_9 , V_14 ) ;
break;
case V_144 :
V_122 = V_156 -> V_122 ;
V_14 = F_27 ( V_70 , V_156 -> V_17 , V_122 ) ;
if ( V_14 != V_122 ) {
F_7 ( L_10 , V_14 ) ;
goto V_23;
}
if ( V_152 )
V_14 = F_58 ( V_70 , V_156 , V_151 ) ;
else
V_14 = F_40 ( V_156 , V_151 ) ;
if ( V_14 < 0 )
F_7 ( L_11 , V_14 ) ;
break;
default:
V_14 = - V_24 ;
goto V_23;
}
if ( ! V_14 && V_151 -> F_25 )
V_14 = F_25 ( V_151 -> F_25 ) ;
V_23:
F_10 ( V_142 ) ;
F_10 ( V_151 ) ;
if ( ! V_14 )
F_59 ( V_17 , V_156 ) ;
else
F_10 ( V_156 ) ;
return V_14 ;
}
static void F_60 ( struct V_157 * V_158 )
{
struct V_118 * V_119 ;
V_119 = F_61 ( V_158 , struct V_118 , V_158 ) ;
memset ( V_119 -> V_17 , 0 , V_119 -> V_122 ) ;
F_10 ( V_119 ) ;
}
static int F_62 ( struct V_17 * V_17 , struct V_154 * V_155 )
{
struct V_118 * V_119 ;
struct V_118 * V_159 ;
struct V_120 * V_160 ;
T_5 V_12 = V_155 -> V_12 ;
char * V_142 ;
int V_14 = 0 ;
if ( F_63 ( V_161 , & V_17 -> V_10 ) )
return - V_162 ;
V_119 = V_17 -> V_156 . V_11 [ 0 ] ;
if ( ! V_119 -> V_123 )
return - V_66 ;
if ( V_12 <= 0 || V_12 > 32767 || ! V_155 -> V_11 )
return - V_24 ;
V_142 = F_3 ( V_12 + 1 , V_6 ) ;
if ( ! V_142 )
return - V_7 ;
V_160 = F_50 () ;
if ( ! V_160 ) {
V_14 = - V_7 ;
goto V_23;
}
V_159 = F_52 ( V_17 ) ;
if ( ! V_159 ) {
V_14 = - V_7 ;
goto V_23;
}
memcpy ( V_142 , V_155 -> V_11 , V_12 ) ;
V_142 [ V_12 ] = '\0' ;
V_14 = F_48 ( V_142 , V_159 , V_160 ) ;
if ( V_14 != V_149 ) {
V_14 = - V_24 ;
F_10 ( V_159 ) ;
goto V_23;
}
if ( ! V_160 -> V_86 ) {
V_14 = - V_24 ;
F_10 ( V_159 ) ;
goto V_23;
}
V_159 -> V_123 = V_119 -> V_123 ;
V_159 -> V_122 = V_119 -> V_122 ;
memcpy ( V_159 -> V_17 , V_119 -> V_17 , V_119 -> V_122 ) ;
F_55 ( V_119 ) ;
F_55 ( V_159 ) ;
V_14 = F_40 ( V_159 , V_160 ) ;
if ( V_14 < 0 ) {
F_7 ( L_11 , V_14 ) ;
F_10 ( V_159 ) ;
goto V_23;
}
if ( V_160 -> F_25 ) {
V_14 = F_25 ( V_160 -> F_25 ) ;
if ( V_14 < 0 ) {
F_7 ( L_12 , V_14 ) ;
F_10 ( V_159 ) ;
goto V_23;
}
}
F_59 ( V_17 , V_159 ) ;
F_64 ( & V_119 -> V_158 , F_60 ) ;
V_23:
F_10 ( V_142 ) ;
F_10 ( V_160 ) ;
return V_14 ;
}
static long F_65 ( const struct V_17 * V_17 , char T_7 * V_32 ,
T_5 V_64 )
{
struct V_118 * V_119 ;
char * V_163 ;
char * V_164 ;
int V_102 ;
V_119 = F_66 ( V_17 ) ;
if ( ! V_119 )
return - V_24 ;
if ( ! V_32 || V_64 <= 0 )
return 2 * V_119 -> V_124 ;
V_163 = F_3 ( 2 * V_119 -> V_124 , V_6 ) ;
if ( ! V_163 )
return - V_7 ;
V_164 = V_163 ;
for ( V_102 = 0 ; V_102 < V_119 -> V_124 ; V_102 ++ )
V_164 = F_67 ( V_164 , V_119 -> V_88 [ V_102 ] ) ;
if ( ( F_68 ( V_32 , V_163 , 2 * V_119 -> V_124 ) ) != 0 ) {
F_10 ( V_163 ) ;
return - V_165 ;
}
F_10 ( V_163 ) ;
return 2 * V_119 -> V_124 ;
}
static void F_69 ( struct V_17 * V_17 )
{
struct V_118 * V_119 = V_17 -> V_156 . V_11 [ 0 ] ;
if ( ! V_119 )
return;
memset ( V_119 -> V_17 , 0 , V_119 -> V_122 ) ;
F_10 ( V_17 -> V_156 . V_11 [ 0 ] ) ;
}
static void F_70 ( void )
{
if ( V_15 )
F_71 ( V_15 ) ;
if ( V_21 )
F_71 ( V_21 ) ;
}
static int T_8 F_72 ( void )
{
int V_14 ;
V_21 = F_73 ( V_22 , 0 , V_166 ) ;
if ( F_6 ( V_21 ) ) {
F_7 ( L_13 ,
V_22 ) ;
return F_8 ( V_21 ) ;
}
V_15 = F_73 ( V_16 , 0 , V_166 ) ;
if ( F_6 ( V_15 ) ) {
F_7 ( L_13 ,
V_16 ) ;
V_14 = F_8 ( V_15 ) ;
goto V_167;
}
return 0 ;
V_167:
F_71 ( V_21 ) ;
return V_14 ;
}
static int T_8 F_74 ( void )
{
int V_14 ;
V_14 = F_72 () ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_75 ( & V_168 ) ;
if ( V_14 < 0 )
F_70 () ;
return V_14 ;
}
static void T_9 F_76 ( void )
{
F_70 () ;
F_77 ( & V_168 ) ;
}
