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
static int F_25 ( struct V_67 * V_68 , unsigned char * V_69 , T_2 V_70 )
{
int V_14 ;
F_26 ( V_68 ) ;
F_27 ( V_68 , V_71 ) ;
F_28 ( V_68 , V_72 ) ;
F_28 ( V_68 , V_73 ) ;
F_28 ( V_68 , V_70 ) ;
V_14 = F_22 ( V_74 , V_68 -> V_11 , sizeof V_68 -> V_11 ) ;
if ( ! V_14 )
memcpy ( V_69 , V_68 -> V_11 + V_72 , V_70 ) ;
return V_14 ;
}
static int F_29 ( unsigned char * V_69 , int V_70 )
{
struct V_67 * V_68 ;
int V_14 ;
V_68 = F_3 ( sizeof *V_68 , V_6 ) ;
if ( ! V_68 )
return - V_7 ;
V_14 = F_25 ( V_68 , V_69 , V_70 ) ;
F_10 ( V_68 ) ;
return V_14 ;
}
static int F_30 ( const int V_75 )
{
unsigned char V_76 [ V_29 ] ;
int V_14 ;
if ( ! F_31 ( V_77 ) )
return - V_66 ;
V_14 = F_29 ( V_76 , V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_32 ( V_74 , V_75 , V_76 ) ? - V_24 : 0 ;
}
static int F_33 ( struct V_67 * V_68 , struct V_78 * V_79 ,
const unsigned char * V_17 , T_3 type , T_2 V_80 )
{
unsigned char V_39 [ V_31 ] ;
unsigned char V_34 [ V_31 ] ;
int V_14 ;
V_14 = F_25 ( V_68 , V_34 , V_31 ) ;
if ( V_14 < 0 )
return V_14 ;
F_26 ( V_68 ) ;
F_27 ( V_68 , V_71 ) ;
F_28 ( V_68 , V_81 ) ;
F_28 ( V_68 , V_82 ) ;
F_27 ( V_68 , type ) ;
F_28 ( V_68 , V_80 ) ;
F_34 ( V_68 , V_34 , V_31 ) ;
V_14 = F_22 ( V_74 , V_68 -> V_11 , V_83 ) ;
if ( V_14 < 0 )
return V_14 ;
V_79 -> V_80 = F_18 ( V_68 -> V_11 , V_84 ) ;
memcpy ( V_79 -> V_39 , & ( V_68 -> V_11 [ V_84 + sizeof( T_2 ) ] ) ,
V_31 ) ;
memcpy ( V_39 , & ( V_68 -> V_11 [ V_84 + sizeof( T_2 ) +
V_31 ] ) , V_31 ) ;
return F_11 ( V_79 -> V_85 , V_17 , V_29 , V_31 ,
V_39 , V_31 , V_34 , 0 , 0 ) ;
}
static int F_35 ( struct V_67 * V_68 , T_2 * V_80 , unsigned char * V_86 )
{
int V_14 ;
F_26 ( V_68 ) ;
F_27 ( V_68 , V_71 ) ;
F_28 ( V_68 , V_87 ) ;
F_28 ( V_68 , V_88 ) ;
V_14 = F_22 ( V_74 , V_68 -> V_11 , V_83 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_80 = F_18 ( V_68 -> V_11 , V_84 ) ;
memcpy ( V_86 , & V_68 -> V_11 [ V_84 + sizeof( T_2 ) ] ,
V_31 ) ;
return 0 ;
}
static int F_36 ( struct V_67 * V_68 , T_3 V_89 ,
T_2 V_90 , const unsigned char * V_91 ,
const unsigned char * V_11 , T_2 V_12 ,
unsigned char * V_92 , T_2 * V_93 ,
const unsigned char * V_94 ,
const unsigned char * V_95 , T_2 V_96 )
{
struct V_78 V_97 ;
struct V_98 * V_99 ;
unsigned char V_100 ;
T_2 V_37 ;
T_2 V_101 ;
T_2 V_102 ;
int V_103 ;
int V_104 ;
int V_105 ;
int V_14 ;
int V_106 ;
V_99 = F_3 ( sizeof *V_99 , V_6 ) ;
if ( ! V_99 )
return - V_7 ;
V_14 = F_33 ( V_68 , & V_97 , V_91 , V_89 , V_90 ) ;
if ( V_14 < 0 )
goto V_23;
F_37 ( & V_97 ) ;
memcpy ( V_99 -> V_107 , V_97 . V_85 , V_29 ) ;
memcpy ( V_99 -> V_107 + V_29 , V_97 . V_39 , V_29 ) ;
V_14 = F_5 ( V_99 -> V_107 , V_29 * 2 , V_99 -> V_108 ) ;
if ( V_14 < 0 )
goto V_23;
V_14 = F_25 ( V_68 , V_99 -> V_109 , V_31 ) ;
if ( V_14 < 0 )
goto V_23;
V_37 = F_38 ( V_110 ) ;
V_102 = F_38 ( V_12 ) ;
V_101 = F_38 ( V_96 ) ;
V_100 = 0 ;
for ( V_106 = 0 ; V_106 < V_29 ; ++ V_106 )
V_99 -> V_111 [ V_106 ] = V_99 -> V_108 [ V_106 ] ^ V_94 [ V_106 ] ;
if ( V_96 == 0 ) {
V_14 = F_16 ( V_99 -> V_112 , V_97 . V_85 , V_29 ,
V_97 . V_39 , V_99 -> V_109 , V_100 ,
sizeof( T_2 ) , & V_37 , V_29 ,
V_99 -> V_111 , sizeof( T_2 ) , & V_101 ,
sizeof( T_2 ) , & V_102 , V_12 , V_11 , 0 ,
0 ) ;
} else {
V_14 = F_16 ( V_99 -> V_112 , V_97 . V_85 , V_29 ,
V_97 . V_39 , V_99 -> V_109 , V_100 ,
sizeof( T_2 ) , & V_37 , V_29 ,
V_99 -> V_111 , sizeof( T_2 ) , & V_101 ,
V_96 , V_95 , sizeof( T_2 ) ,
& V_102 , V_12 , V_11 , 0 , 0 ) ;
}
if ( V_14 < 0 )
goto V_23;
F_26 ( V_68 ) ;
F_27 ( V_68 , V_113 ) ;
F_28 ( V_68 , V_114 + V_96 + V_12 ) ;
F_28 ( V_68 , V_110 ) ;
F_28 ( V_68 , V_90 ) ;
F_34 ( V_68 , V_99 -> V_111 , V_29 ) ;
F_28 ( V_68 , V_96 ) ;
F_34 ( V_68 , V_95 , V_96 ) ;
F_28 ( V_68 , V_12 ) ;
F_34 ( V_68 , V_11 , V_12 ) ;
F_28 ( V_68 , V_97 . V_80 ) ;
F_34 ( V_68 , V_99 -> V_109 , V_31 ) ;
F_39 ( V_68 , V_100 ) ;
F_34 ( V_68 , V_99 -> V_112 , V_29 ) ;
V_14 = F_22 ( V_74 , V_68 -> V_11 , V_83 ) ;
if ( V_14 < 0 )
goto V_23;
V_103 = F_18 ( V_68 -> V_11 , V_84 + sizeof( T_2 ) ) ;
V_104 = F_18 ( V_68 -> V_11 , V_84 + sizeof( T_2 ) +
sizeof( T_2 ) + V_103 ) ;
V_105 = sizeof( T_2 ) + sizeof( T_2 ) + V_103 +
sizeof( T_2 ) + V_104 ;
V_14 = F_17 ( V_68 -> V_11 , V_37 , V_99 -> V_109 , V_97 . V_85 ,
V_29 , V_105 , V_84 , 0 ,
0 ) ;
if ( ! V_14 ) {
memcpy ( V_92 , V_68 -> V_11 + V_84 , V_105 ) ;
* V_93 = V_105 ;
}
V_23:
F_10 ( V_99 ) ;
return V_14 ;
}
static int F_40 ( struct V_67 * V_68 ,
T_2 V_90 , const unsigned char * V_91 ,
const unsigned char * V_92 , int V_93 ,
const unsigned char * V_94 ,
unsigned char * V_11 , unsigned int * V_12 )
{
unsigned char V_109 [ V_31 ] ;
unsigned char V_53 [ V_31 ] ;
unsigned char V_56 [ V_31 ] ;
unsigned char V_55 [ V_29 ] ;
unsigned char V_58 [ V_29 ] ;
T_2 V_115 = 0 ;
T_2 V_116 = 0 ;
unsigned char V_100 = 0 ;
T_2 V_37 ;
T_2 V_117 ;
int V_14 ;
V_14 = F_35 ( V_68 , & V_115 , V_53 ) ;
if ( V_14 < 0 ) {
F_7 ( L_2 , V_14 ) ;
return V_14 ;
}
V_14 = F_35 ( V_68 , & V_116 , V_56 ) ;
if ( V_14 < 0 ) {
F_7 ( L_2 , V_14 ) ;
return V_14 ;
}
V_37 = F_38 ( V_118 ) ;
V_117 = F_38 ( V_119 ) ;
V_14 = F_25 ( V_68 , V_109 , V_31 ) ;
if ( V_14 < 0 ) {
F_7 ( L_3 , V_14 ) ;
return V_14 ;
}
V_14 = F_16 ( V_55 , V_91 , V_31 ,
V_53 , V_109 , V_100 , sizeof( T_2 ) ,
& V_37 , V_93 , V_92 , 0 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_16 ( V_58 , V_94 , V_31 ,
V_56 , V_109 , V_100 , sizeof( T_2 ) ,
& V_37 , V_93 , V_92 , 0 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
F_26 ( V_68 ) ;
F_27 ( V_68 , V_120 ) ;
F_28 ( V_68 , V_121 + V_93 ) ;
F_28 ( V_68 , V_118 ) ;
F_28 ( V_68 , V_90 ) ;
F_34 ( V_68 , V_92 , V_93 ) ;
F_28 ( V_68 , V_115 ) ;
F_34 ( V_68 , V_109 , V_31 ) ;
F_39 ( V_68 , V_100 ) ;
F_34 ( V_68 , V_55 , V_29 ) ;
F_28 ( V_68 , V_116 ) ;
F_34 ( V_68 , V_109 , V_31 ) ;
F_39 ( V_68 , V_100 ) ;
F_34 ( V_68 , V_58 , V_29 ) ;
V_14 = F_22 ( V_74 , V_68 -> V_11 , V_83 ) ;
if ( V_14 < 0 ) {
F_7 ( L_4 , V_14 ) ;
return V_14 ;
}
* V_12 = F_18 ( V_68 -> V_11 , V_84 ) ;
V_14 = F_21 ( V_68 -> V_11 , V_37 , V_109 ,
V_91 , V_29 ,
V_94 , V_29 ,
sizeof( T_2 ) , V_84 ,
* V_12 , V_84 + sizeof( T_2 ) , 0 ,
0 ) ;
if ( V_14 < 0 ) {
F_7 ( L_5 , V_14 ) ;
return V_14 ;
}
memcpy ( V_11 , V_68 -> V_11 + V_84 + sizeof( T_2 ) , * V_12 ) ;
return 0 ;
}
static int F_41 ( struct V_122 * V_123 ,
struct V_124 * V_125 )
{
struct V_67 * V_68 ;
int V_14 ;
V_68 = F_42 ( sizeof *V_68 , V_6 ) ;
if ( ! V_68 )
return - V_7 ;
V_123 -> V_17 [ V_123 -> V_126 ] = V_123 -> V_127 ;
V_14 = F_36 ( V_68 , V_125 -> V_89 , V_125 -> V_90 , V_125 -> V_91 ,
V_123 -> V_17 , V_123 -> V_126 + 1 , V_123 -> V_92 , & V_123 -> V_128 ,
V_125 -> V_94 , V_125 -> V_95 , V_125 -> V_129 ) ;
if ( V_14 < 0 )
F_7 ( L_6 , V_14 ) ;
F_10 ( V_68 ) ;
return V_14 ;
}
static int F_43 ( struct V_122 * V_123 ,
struct V_124 * V_125 )
{
struct V_67 * V_68 ;
int V_14 ;
V_68 = F_42 ( sizeof *V_68 , V_6 ) ;
if ( ! V_68 )
return - V_7 ;
V_14 = F_40 ( V_68 , V_125 -> V_90 , V_125 -> V_91 , V_123 -> V_92 , V_123 -> V_128 ,
V_125 -> V_94 , V_123 -> V_17 , & V_123 -> V_126 ) ;
if ( V_14 < 0 )
F_7 ( L_7 , V_14 ) ;
else
V_123 -> V_127 = V_123 -> V_17 [ -- V_123 -> V_126 ] ;
F_10 ( V_68 ) ;
return V_14 ;
}
static int F_44 ( char * V_30 , struct V_122 * V_130 ,
struct V_124 * V_131 )
{
T_6 args [ V_132 ] ;
char * V_123 = V_30 ;
int V_133 ;
int V_134 ;
unsigned long V_80 ;
unsigned long V_135 ;
while ( ( V_123 = F_45 ( & V_30 , L_8 ) ) ) {
if ( * V_123 == '\0' || * V_123 == ' ' || * V_123 == '\t' )
continue;
V_133 = F_46 ( V_123 , V_136 , args ) ;
switch ( V_133 ) {
case V_137 :
V_131 -> V_129 = strlen ( args [ 0 ] . V_138 ) / 2 ;
if ( V_131 -> V_129 > V_139 )
return - V_24 ;
F_47 ( V_131 -> V_95 , args [ 0 ] . V_138 , V_131 -> V_129 ) ;
break;
case V_140 :
V_134 = F_48 ( args [ 0 ] . V_138 , 16 , & V_80 ) ;
if ( V_134 < 0 )
return - V_24 ;
V_131 -> V_89 = V_141 ;
V_131 -> V_90 = V_80 ;
break;
case V_142 :
if ( strlen ( args [ 0 ] . V_138 ) != 2 * V_29 )
return - V_24 ;
F_47 ( V_131 -> V_91 , args [ 0 ] . V_138 , V_29 ) ;
break;
case V_143 :
if ( strlen ( args [ 0 ] . V_138 ) != 2 * V_29 )
return - V_24 ;
F_47 ( V_131 -> V_94 , args [ 0 ] . V_138 , V_29 ) ;
break;
case V_144 :
if ( * args [ 0 ] . V_138 == '0' )
V_130 -> V_127 = 0 ;
else
return - V_24 ;
break;
case V_145 :
V_134 = F_48 ( args [ 0 ] . V_138 , 10 , & V_135 ) ;
if ( V_134 < 0 )
return - V_24 ;
V_131 -> F_30 = V_135 ;
break;
default:
return - V_24 ;
}
}
return 0 ;
}
static int F_49 ( char * V_146 , struct V_122 * V_123 ,
struct V_124 * V_125 )
{
T_6 args [ V_132 ] ;
long V_18 ;
int V_14 = - V_24 ;
int V_147 ;
char * V_30 ;
V_30 = F_45 ( & V_146 , L_8 ) ;
if ( ! V_30 )
return - V_24 ;
V_147 = F_46 ( V_30 , V_136 , args ) ;
switch ( V_147 ) {
case V_148 :
V_30 = F_45 ( & V_146 , L_8 ) ;
if ( ! V_30 )
return - V_24 ;
V_14 = F_50 ( V_30 , 10 , & V_18 ) ;
if ( V_14 < 0 || V_18 < V_149 || V_18 > V_150 )
return - V_24 ;
V_123 -> V_126 = V_18 ;
V_14 = F_44 ( V_146 , V_123 , V_125 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_148 ;
break;
case V_151 :
V_30 = F_45 ( & V_146 , L_8 ) ;
if ( ! V_30 )
return - V_24 ;
V_123 -> V_128 = strlen ( V_30 ) / 2 ;
if ( V_123 -> V_128 > V_152 )
return - V_24 ;
F_47 ( V_123 -> V_92 , V_30 , V_123 -> V_128 ) ;
V_14 = F_44 ( V_146 , V_123 , V_125 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_151 ;
break;
case V_153 :
V_14 = F_44 ( V_146 , V_123 , V_125 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_153 ;
break;
case V_154 :
return - V_24 ;
break;
}
return V_14 ;
}
static struct V_124 * F_51 ( void )
{
struct V_124 * V_155 ;
V_155 = F_42 ( sizeof *V_155 , V_6 ) ;
if ( V_155 ) {
V_155 -> V_89 = V_156 ;
V_155 -> V_90 = V_119 ;
}
return V_155 ;
}
static struct V_122 * F_52 ( struct V_17 * V_17 )
{
struct V_122 * V_123 = NULL ;
int V_14 ;
V_14 = F_53 ( V_17 , sizeof *V_123 ) ;
if ( V_14 < 0 )
return V_123 ;
V_123 = F_42 ( sizeof *V_123 , V_6 ) ;
if ( V_123 )
V_123 -> V_127 = 1 ;
return V_123 ;
}
static int F_54 ( struct V_17 * V_17 , const void * V_11 ,
T_5 V_12 )
{
struct V_122 * V_157 = NULL ;
struct V_124 * V_155 = NULL ;
char * V_146 ;
int V_14 = 0 ;
int V_147 ;
if ( V_12 <= 0 || V_12 > 32767 || ! V_11 )
return - V_24 ;
V_146 = F_3 ( V_12 + 1 , V_6 ) ;
if ( ! V_146 )
return - V_7 ;
memcpy ( V_146 , V_11 , V_12 ) ;
V_146 [ V_12 ] = '\0' ;
V_155 = F_51 () ;
if ( ! V_155 ) {
V_14 = - V_7 ;
goto V_23;
}
V_157 = F_52 ( V_17 ) ;
if ( ! V_157 ) {
V_14 = - V_7 ;
goto V_23;
}
V_147 = F_49 ( V_146 , V_157 , V_155 ) ;
if ( V_147 < 0 ) {
V_14 = V_147 ;
goto V_23;
}
F_55 ( V_157 ) ;
F_56 ( V_155 ) ;
switch ( V_147 ) {
case V_151 :
V_14 = F_43 ( V_157 , V_155 ) ;
F_55 ( V_157 ) ;
F_56 ( V_155 ) ;
if ( V_14 < 0 )
F_7 ( L_9 , V_14 ) ;
break;
case V_148 :
V_14 = F_29 ( V_157 -> V_17 , V_157 -> V_126 ) ;
if ( V_14 < 0 ) {
F_7 ( L_10 , V_14 ) ;
goto V_23;
}
V_14 = F_41 ( V_157 , V_155 ) ;
if ( V_14 < 0 )
F_7 ( L_11 , V_14 ) ;
break;
default:
V_14 = - V_24 ;
goto V_23;
}
if ( ! V_14 && V_155 -> F_30 )
V_14 = F_30 ( V_155 -> F_30 ) ;
V_23:
F_10 ( V_146 ) ;
F_10 ( V_155 ) ;
if ( ! V_14 )
F_57 ( V_17 -> V_157 . V_11 , V_157 ) ;
else
F_10 ( V_157 ) ;
return V_14 ;
}
static void F_58 ( struct V_158 * V_159 )
{
struct V_122 * V_123 ;
V_123 = F_59 ( V_159 , struct V_122 , V_159 ) ;
memset ( V_123 -> V_17 , 0 , V_123 -> V_126 ) ;
F_10 ( V_123 ) ;
}
static int F_60 ( struct V_17 * V_17 , const void * V_11 , T_5 V_12 )
{
struct V_122 * V_123 = V_17 -> V_157 . V_11 ;
struct V_122 * V_160 ;
struct V_124 * V_161 ;
char * V_146 ;
int V_14 = 0 ;
if ( ! V_123 -> V_127 )
return - V_66 ;
if ( V_12 <= 0 || V_12 > 32767 || ! V_11 )
return - V_24 ;
V_146 = F_3 ( V_12 + 1 , V_6 ) ;
if ( ! V_146 )
return - V_7 ;
V_161 = F_51 () ;
if ( ! V_161 ) {
V_14 = - V_7 ;
goto V_23;
}
V_160 = F_52 ( V_17 ) ;
if ( ! V_160 ) {
V_14 = - V_7 ;
goto V_23;
}
memcpy ( V_146 , V_11 , V_12 ) ;
V_146 [ V_12 ] = '\0' ;
V_14 = F_49 ( V_146 , V_160 , V_161 ) ;
if ( V_14 != V_153 ) {
V_14 = - V_24 ;
F_10 ( V_160 ) ;
goto V_23;
}
V_160 -> V_127 = V_123 -> V_127 ;
V_160 -> V_126 = V_123 -> V_126 ;
memcpy ( V_160 -> V_17 , V_123 -> V_17 , V_123 -> V_126 ) ;
F_55 ( V_123 ) ;
F_55 ( V_160 ) ;
V_14 = F_41 ( V_160 , V_161 ) ;
if ( V_14 < 0 ) {
F_7 ( L_11 , V_14 ) ;
F_10 ( V_160 ) ;
goto V_23;
}
if ( V_161 -> F_30 ) {
V_14 = F_30 ( V_161 -> F_30 ) ;
if ( V_14 < 0 ) {
F_7 ( L_12 , V_14 ) ;
F_10 ( V_160 ) ;
goto V_23;
}
}
F_57 ( V_17 -> V_157 . V_11 , V_160 ) ;
F_61 ( & V_123 -> V_159 , F_58 ) ;
V_23:
F_10 ( V_146 ) ;
F_10 ( V_161 ) ;
return V_14 ;
}
static long F_62 ( const struct V_17 * V_17 , char T_7 * V_32 ,
T_5 V_64 )
{
struct V_122 * V_123 ;
char * V_162 ;
char * V_163 ;
int V_106 ;
V_123 = F_63 ( V_17 ) ;
if ( ! V_123 )
return - V_24 ;
if ( ! V_32 || V_64 <= 0 )
return 2 * V_123 -> V_128 ;
V_162 = F_3 ( 2 * V_123 -> V_128 , V_6 ) ;
if ( ! V_162 )
return - V_7 ;
V_163 = V_162 ;
for ( V_106 = 0 ; V_106 < V_123 -> V_128 ; V_106 ++ )
V_163 = F_64 ( V_163 , V_123 -> V_92 [ V_106 ] ) ;
if ( ( F_65 ( V_32 , V_162 , 2 * V_123 -> V_128 ) ) != 0 ) {
F_10 ( V_162 ) ;
return - V_164 ;
}
F_10 ( V_162 ) ;
return 2 * V_123 -> V_128 ;
}
static void F_66 ( struct V_17 * V_17 )
{
struct V_122 * V_123 = V_17 -> V_157 . V_11 ;
if ( ! V_123 )
return;
memset ( V_123 -> V_17 , 0 , V_123 -> V_126 ) ;
F_10 ( V_17 -> V_157 . V_11 ) ;
}
static void F_67 ( void )
{
if ( V_15 )
F_68 ( V_15 ) ;
if ( V_21 )
F_68 ( V_21 ) ;
}
static int T_8 F_69 ( void )
{
int V_14 ;
V_21 = F_70 ( V_22 , 0 , V_165 ) ;
if ( F_6 ( V_21 ) ) {
F_7 ( L_13 ,
V_22 ) ;
return F_8 ( V_21 ) ;
}
V_15 = F_70 ( V_16 , 0 , V_165 ) ;
if ( F_6 ( V_15 ) ) {
F_7 ( L_13 ,
V_16 ) ;
V_14 = F_8 ( V_15 ) ;
goto V_166;
}
return 0 ;
V_166:
F_68 ( V_21 ) ;
return V_14 ;
}
static int T_8 F_71 ( void )
{
int V_14 ;
V_14 = F_69 () ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_72 ( & V_167 ) ;
if ( V_14 < 0 )
F_67 () ;
return V_14 ;
}
static void T_9 F_73 ( void )
{
F_67 () ;
F_74 ( & V_167 ) ;
}
