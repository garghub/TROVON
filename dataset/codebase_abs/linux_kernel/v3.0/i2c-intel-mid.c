static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
int V_6 = 0 ;
int V_7 , V_8 ;
static const T_1 V_9 [ V_10 ] = { 100 , 25 , 3 } ;
F_3 ( 0 , V_4 -> V_11 + V_12 ) ;
F_4 ( & V_2 -> V_13 , L_1 ) ;
while ( ( V_7 = F_5 ( V_4 -> V_11 + V_14 ) & 0x1 )
|| ( V_8 = F_5 ( V_4 -> V_11 + V_15 ) & 0x1 ) ) {
F_6 ( V_9 [ V_4 -> V_16 ] ) ;
F_3 ( 0 , V_4 -> V_11 + V_12 ) ;
F_4 ( & V_2 -> V_13 , L_2 ,
V_6 , V_4 -> V_16 ) ;
if ( V_6 ++ > 10 ) {
V_5 = - V_17 ;
break;
}
}
F_5 ( V_4 -> V_11 + V_18 ) ;
F_5 ( V_4 -> V_11 + V_19 ) ;
F_5 ( V_4 -> V_11 + V_20 ) ;
F_5 ( V_4 -> V_11 + V_21 ) ;
F_5 ( V_4 -> V_11 + V_22 ) ;
F_5 ( V_4 -> V_11 + V_23 ) ;
F_5 ( V_4 -> V_11 + V_24 ) ;
F_5 ( V_4 -> V_11 + V_25 ) ;
F_5 ( V_4 -> V_11 + V_26 ) ;
F_5 ( V_4 -> V_11 + V_27 ) ;
F_3 ( 0x0000 , V_4 -> V_11 + V_28 ) ;
return V_5 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_5 ;
static const T_1 V_29 [ V_30 ] [ V_10 ] = {
{ 0x75 , 0x15 , 0x07 } ,
{ 0x04c , 0x10 , 0x06 }
} ;
static const T_1 V_31 [ V_30 ] [ V_10 ] = {
{ 0x7C , 0x21 , 0x0E } ,
{ 0x053 , 0x19 , 0x0F }
} ;
V_5 = F_1 ( & V_4 -> V_2 ) ;
if ( V_5 )
return V_5 ;
F_3 ( ( V_4 -> V_16 + 1 ) << 1 | V_32 | V_33 | V_34 ,
V_4 -> V_11 + V_35 ) ;
F_3 ( V_29 [ V_4 -> V_36 ] [ V_4 -> V_16 ] ,
V_4 -> V_11 + ( V_37 + ( V_4 -> V_16 << 3 ) ) ) ;
F_3 ( V_31 [ V_4 -> V_36 ] [ V_4 -> V_16 ] ,
V_4 -> V_11 + ( V_38 + ( V_4 -> V_16 << 3 ) ) ) ;
F_3 ( 0x0 , V_4 -> V_11 + V_39 ) ;
F_3 ( 0x0 , V_4 -> V_11 + V_40 ) ;
return 0 ;
}
static T_2 F_8 ( struct V_1 * V_41 )
{
return V_42 | V_43 | V_44 ;
}
static inline bool F_9 ( const struct V_45 * V_46 ,
const struct V_45 * V_47 )
{
if ( V_46 -> V_48 != V_47 -> V_48 )
return 1 ;
if ( ( V_46 -> V_49 ^ V_47 -> V_49 ) & V_50 )
return 1 ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
int abort = V_4 -> abort ;
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( abort & V_51 )
F_11 ( & V_2 -> V_13 ,
L_3 ) ;
if ( abort & V_52 )
F_11 ( & V_2 -> V_13 ,
L_4 ) ;
if ( abort & V_53 ) {
F_11 ( & V_2 -> V_13 ,
L_5 ) ;
F_3 ( ~ V_53 , V_4 -> V_11 + V_54 ) ;
F_3 ( V_33 , V_4 -> V_11 + V_35 ) ;
F_3 ( ~ V_55 , V_4 -> V_11 + V_56 ) ;
}
if ( abort & V_57 )
F_11 ( & V_2 -> V_13 ,
L_6 ) ;
if ( abort & V_58 )
F_4 ( & V_2 -> V_13 ,
L_7 ) ;
if ( abort & V_59 )
F_4 ( & V_2 -> V_13 ,
L_8 ) ;
if ( abort & V_60 )
F_4 ( & V_2 -> V_13 ,
L_9 ) ;
if ( abort & V_61 )
F_4 ( & V_2 -> V_13 ,
L_10 ) ;
F_5 ( V_4 -> V_11 + V_22 ) ;
V_4 -> V_62 = V_63 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned char * V_64 , int V_65 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_66 = V_65 ;
int V_5 ;
if ( V_65 >= 256 ) {
F_11 ( & V_2 -> V_13 ,
L_11 ) ;
return - V_67 ;
}
F_13 ( V_4 -> V_68 ) ;
F_5 ( V_4 -> V_11 + V_18 ) ;
F_3 ( 0x0044 , V_4 -> V_11 + V_28 ) ;
V_4 -> V_62 = V_69 ;
while ( V_66 -- )
F_3 ( V_70 , V_4 -> V_11 + V_71 ) ;
V_4 -> V_62 = V_69 ;
V_5 = F_14 ( & V_4 -> V_68 , V_72 ) ;
if ( ! V_5 ) {
F_11 ( & V_2 -> V_13 , L_12 ) ;
F_7 ( V_4 ) ;
return - V_17 ;
}
if ( V_4 -> V_62 == V_73 )
return 0 ;
else
return - V_74 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned char * V_64 , int V_65 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_66 , V_5 ;
if ( V_65 >= 256 ) {
F_11 ( & V_2 -> V_13 ,
L_11 ) ;
return - V_67 ;
}
F_13 ( V_4 -> V_68 ) ;
F_5 ( V_4 -> V_11 + V_18 ) ;
F_3 ( 0x0050 , V_4 -> V_11 + V_28 ) ;
V_4 -> V_62 = V_75 ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ )
F_3 ( ( T_1 ) ( * ( V_64 + V_66 ) ) , V_4 -> V_11 + V_71 ) ;
V_4 -> V_62 = V_75 ;
V_5 = F_14 ( & V_4 -> V_68 , V_72 ) ;
if ( ! V_5 ) {
F_11 ( & V_2 -> V_13 , L_12 ) ;
F_7 ( V_4 ) ;
return - V_17 ;
} else {
if ( V_4 -> V_62 == V_76 )
return 0 ;
else
return - V_74 ;
}
}
static int F_16 ( struct V_1 * V_2 , struct V_45 * V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_2 V_78 ;
T_2 V_79 ;
T_2 V_80 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_11 ( & V_2 -> V_13 ,
L_13 ) ;
return V_5 ;
}
V_80 = ( 1 + V_4 -> V_16 ) << 1 ;
V_78 = F_5 ( V_4 -> V_11 + V_35 ) ;
if ( ( V_78 & 0x06 ) != V_80 ) {
F_4 ( & V_2 -> V_13 , L_14 , V_4 -> V_16 ) ;
F_3 ( ( V_78 & ~ 0x6 ) | V_80 , V_4 -> V_11 + V_35 ) ;
}
V_78 = F_5 ( V_4 -> V_11 + V_35 ) ;
if ( V_77 -> V_49 & V_50 ) {
if ( ( V_78 & V_81 ) != V_81 ) {
F_4 ( & V_2 -> V_13 , L_15 ) ;
F_3 ( V_78 | V_81 , V_4 -> V_11 + V_35 ) ;
}
} else {
if ( ( V_78 & V_81 ) != 0x0 ) {
F_4 ( & V_2 -> V_13 , L_16 ) ;
F_3 ( V_78 & ~ V_81 , V_4 -> V_11 + V_35 ) ;
}
}
V_78 = F_5 ( V_4 -> V_11 + V_35 ) ;
if ( ( V_78 & V_33 ) != V_33 ) {
F_4 ( & V_2 -> V_13 , L_17 ) ;
F_3 ( V_78 | V_33 , V_4 -> V_11 + V_35 ) ;
}
V_78 = F_5 ( V_4 -> V_11 + V_35 ) ;
F_4 ( & V_2 -> V_13 , L_18 , V_78 ) ;
F_3 ( V_78 | V_34 , V_4 -> V_11 + V_35 ) ;
if ( ( V_78 & V_32 ) != V_32 ) {
F_4 ( & V_2 -> V_13 , L_19 ) ;
F_3 ( V_78 | V_32 , V_4 -> V_11 + V_35 ) ;
F_4 ( & V_2 -> V_13 , L_18 , V_78 ) ;
}
V_78 = F_5 ( V_4 -> V_11 + V_56 ) ;
V_79 = V_55 | V_82 ;
if ( ( V_78 & V_79 ) != 0x0 ) {
F_4 ( & V_2 -> V_13 ,
L_20 ) ;
F_3 ( V_78 & ~ V_79 , V_4 -> V_11 + V_56 ) ;
}
F_4 ( & V_2 -> V_13 ,
L_21 ,
V_77 -> V_48 ) ;
F_3 ( V_77 -> V_48 | ( V_77 -> V_49 & V_50 ? V_83 : 0 ) ,
V_4 -> V_11 + V_56 ) ;
F_3 ( V_84 , V_4 -> V_11 + V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_45 * V_77 ,
int V_85 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_66 , V_5 = 0 ;
if ( V_85 == 0 )
return 0 ;
F_18 ( V_4 -> V_13 ) ;
F_19 ( & V_4 -> V_86 ) ;
F_4 ( & V_2 -> V_13 , L_22 , V_85 ) ;
F_4 ( & V_2 -> V_13 , L_23 , V_77 -> V_48 ) ;
if ( V_4 -> V_62 != V_87 ) {
F_11 ( & V_2 -> V_13 , L_24 ,
V_2 -> V_88 ) ;
F_20 ( & V_4 -> V_86 ) ;
F_21 ( V_4 -> V_13 ) ;
return - 1 ;
}
for ( V_66 = 1 ; V_66 < V_85 ; V_66 ++ ) {
if ( F_22 ( F_9 ( & V_77 [ 0 ] , & V_77 [ V_66 ] ) ) ) {
F_11 ( & V_2 -> V_13 , L_25 , V_66 ) ;
F_20 ( & V_4 -> V_86 ) ;
F_21 ( V_4 -> V_13 ) ;
return - V_89 ;
}
}
if ( F_16 ( V_2 , V_77 ) ) {
F_20 ( & V_4 -> V_86 ) ;
F_21 ( V_4 -> V_13 ) ;
return - V_89 ;
}
for ( V_66 = 0 ; V_66 < V_85 ; V_66 ++ ) {
V_4 -> V_90 = V_77 ;
V_4 -> V_62 = V_87 ;
if ( V_77 -> V_49 & V_91 ) {
F_4 ( & V_2 -> V_13 , L_26 ) ;
V_5 = F_12 ( V_2 , V_77 -> V_64 , V_77 -> V_92 ) ;
} else {
F_4 ( & V_2 -> V_13 , L_27 ) ;
V_5 = F_15 ( V_2 , V_77 -> V_64 , V_77 -> V_92 ) ;
}
if ( V_5 < 0 )
break;
F_4 ( & V_2 -> V_13 , L_28 , V_66 ) ;
V_77 ++ ;
}
F_3 ( 0x0000 , V_4 -> V_11 + V_28 ) ;
F_5 ( V_4 -> V_11 + V_18 ) ;
V_4 -> V_62 = V_87 ;
F_20 ( & V_4 -> V_86 ) ;
F_21 ( V_4 -> V_13 ) ;
return V_5 ;
}
static int F_23 ( struct V_93 * V_13 )
{
struct V_94 * V_95 = F_24 ( V_13 ) ;
struct V_3 * V_4 = F_25 ( V_95 ) ;
struct V_1 * V_2 = F_26 ( V_13 ) ;
int V_5 ;
if ( V_4 -> V_62 != V_87 )
return - 1 ;
F_1 ( V_2 ) ;
V_5 = F_27 ( V_95 ) ;
if ( V_5 ) {
F_11 ( V_13 , L_29 ) ;
return V_5 ;
}
V_5 = F_28 ( V_95 , V_96 ) ;
if ( V_5 ) {
F_11 ( V_13 , L_30 ) ;
return V_5 ;
}
V_4 -> V_62 = V_97 ;
return 0 ;
}
static int F_29 ( struct V_93 * V_13 )
{
struct V_94 * V_95 = F_24 ( V_13 ) ;
struct V_3 * V_4 = F_25 ( V_95 ) ;
int V_5 ;
if ( V_4 -> V_62 != V_97 )
return 0 ;
F_28 ( V_95 , V_98 ) ;
F_30 ( V_95 ) ;
V_5 = F_31 ( V_95 ) ;
if ( V_5 ) {
F_11 ( V_13 , L_31 ) ;
return V_5 ;
}
V_4 -> V_62 = V_87 ;
F_7 ( V_4 ) ;
return V_5 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_45 * V_90 = V_4 -> V_90 ;
int V_99 ;
T_2 V_92 ;
T_3 * V_64 ;
if ( ! ( V_90 -> V_49 & V_91 ) )
return;
if ( V_4 -> V_62 != V_100 ) {
V_92 = V_90 -> V_92 ;
V_64 = V_90 -> V_64 ;
} else {
V_92 = V_4 -> V_101 ;
V_64 = V_4 -> V_102 ;
}
V_99 = F_5 ( V_4 -> V_11 + V_103 ) ;
for (; V_92 > 0 && V_99 > 0 ; V_92 -- , V_99 -- )
* V_64 ++ = F_5 ( V_4 -> V_11 + V_71 ) ;
if ( V_92 > 0 ) {
V_4 -> V_62 = V_100 ;
V_4 -> V_101 = V_92 ;
V_4 -> V_102 = V_64 ;
} else
V_4 -> V_62 = V_73 ;
return;
}
static T_4 F_33 ( int V_104 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
T_2 V_105 = F_5 ( V_4 -> V_11 + V_106 ) ;
if ( ! V_105 )
return V_107 ;
F_4 ( & V_4 -> V_2 . V_13 , L_32 , V_108 , V_105 ) ;
V_105 &= 0x54 ;
if ( V_4 -> V_62 != V_75 &&
V_4 -> V_62 != V_69 &&
V_4 -> V_62 != V_100 )
goto V_5;
if ( V_105 & V_109 )
V_4 -> abort = F_5 ( V_4 -> V_11 + V_54 ) ;
F_5 ( V_4 -> V_11 + V_18 ) ;
if ( V_105 & V_109 ) {
F_10 ( V_4 ) ;
goto exit;
}
if ( V_105 & V_110 ) {
F_32 ( V_4 ) ;
goto exit;
}
if ( V_105 & V_111 ) {
if ( F_5 ( V_4 -> V_11 + V_15 ) & 0x4 )
V_4 -> V_62 = V_76 ;
}
exit:
if ( V_4 -> V_62 == V_73 ||
V_4 -> V_62 == V_76 ||
V_4 -> V_62 == V_63 ) {
F_5 ( V_4 -> V_11 + V_18 ) ;
F_3 ( 0 , V_4 -> V_11 + V_28 ) ;
V_68 ( & V_4 -> V_68 ) ;
}
V_5:
return V_112 ;
}
static int T_5 F_34 ( struct V_94 * V_13 ,
const struct V_113 * V_114 )
{
struct V_3 * V_115 ;
unsigned long V_116 , V_92 ;
int V_5 , V_117 ;
void T_6 * V_11 = NULL ;
F_4 ( & V_13 -> V_13 , L_33 ) ;
V_5 = F_31 ( V_13 ) ;
if ( V_5 ) {
F_11 ( & V_13 -> V_13 , L_34 ,
V_5 ) ;
goto exit;
}
V_116 = F_35 ( V_13 , 0 ) ;
V_92 = F_36 ( V_13 , 0 ) ;
if ( ! V_116 || V_92 == 0 ) {
F_11 ( & V_13 -> V_13 , L_35 ) ;
V_5 = - V_118 ;
goto exit;
}
F_4 ( & V_13 -> V_13 , L_36 ,
V_119 , V_116 , V_92 ) ;
V_5 = F_37 ( V_13 , 0 , V_120 ) ;
if ( V_5 ) {
F_11 ( & V_13 -> V_13 , L_37
L_38 , V_116 ,
( unsigned long ) F_38 ( V_13 , 0 ) ) ;
goto exit;
}
V_11 = F_39 ( V_116 , V_92 ) ;
if ( ! V_11 ) {
F_11 ( & V_13 -> V_13 , L_39 ) ;
V_5 = - V_121 ;
goto V_122;
}
V_115 = F_40 ( sizeof( struct V_3 ) , V_123 ) ;
if ( V_115 == NULL ) {
F_11 ( & V_13 -> V_13 , L_40 ) ;
V_5 = - V_121 ;
goto V_124;
}
snprintf ( V_115 -> V_2 . V_125 , sizeof( V_115 -> V_2 . V_125 ) ,
L_41 , V_116 ) ;
V_115 -> V_2 . V_126 = V_127 ;
V_115 -> V_2 . V_128 = & V_129 ;
V_115 -> V_2 . V_13 . V_130 = & V_13 -> V_13 ;
V_115 -> V_13 = & V_13 -> V_13 ;
V_115 -> V_11 = V_11 ;
V_115 -> V_16 = V_131 ;
V_115 -> abort = 0 ;
V_115 -> V_101 = 0 ;
V_115 -> V_62 = V_87 ;
F_41 ( V_13 , V_115 ) ;
F_42 ( & V_115 -> V_2 , V_115 ) ;
V_115 -> V_2 . V_88 = V_117 = V_114 -> V_132 ;
if ( V_13 -> V_93 <= 0x0804 )
V_115 -> V_36 = V_133 ;
else
V_115 -> V_36 = V_134 ;
F_4 ( & V_13 -> V_13 , L_42 , V_117 ) ;
if ( V_135 > V_117 ) {
if ( V_136 [ V_117 ] < 0 || V_136 [ V_117 ] >= V_10 )
F_43 ( & V_13 -> V_13 , L_43 ,
V_136 [ V_117 ] ) ;
else
V_115 -> V_16 = V_136 [ V_117 ] ;
}
V_5 = F_7 ( V_115 ) ;
if ( V_5 < 0 ) {
F_11 ( & V_13 -> V_13 , L_44 ) ;
goto V_137;
}
F_44 ( & V_115 -> V_86 ) ;
F_45 ( & V_115 -> V_68 ) ;
F_5 ( V_115 -> V_11 + V_18 ) ;
F_3 ( 0x0000 , V_115 -> V_11 + V_28 ) ;
V_5 = F_46 ( V_13 -> V_138 , F_33 , V_139 ,
V_115 -> V_2 . V_125 , V_115 ) ;
if ( V_5 ) {
F_11 ( & V_13 -> V_13 , L_45
L_46 , V_115 -> V_2 . V_125 ) ;
goto V_137;
}
V_5 = F_47 ( & V_115 -> V_2 ) ;
if ( V_5 ) {
F_11 ( & V_13 -> V_13 , L_47 ,
V_115 -> V_2 . V_125 ) ;
goto V_140;
}
F_4 ( & V_13 -> V_13 , L_48 ,
( V_115 -> V_36 == V_133 ) ? L_49 : L_50 ,
V_117 ) ;
F_48 ( & V_13 -> V_13 ) ;
return 0 ;
V_140:
F_49 ( V_13 -> V_138 , V_115 ) ;
V_137:
F_41 ( V_13 , NULL ) ;
F_50 ( V_115 ) ;
V_124:
F_51 ( V_11 ) ;
V_122:
F_52 ( V_13 , 0 ) ;
exit:
return V_5 ;
}
static void T_7 F_53 ( struct V_94 * V_13 )
{
struct V_3 * V_115 = F_25 ( V_13 ) ;
F_1 ( & V_115 -> V_2 ) ;
if ( F_54 ( & V_115 -> V_2 ) )
F_11 ( & V_13 -> V_13 , L_51 ) ;
F_49 ( V_13 -> V_138 , V_115 ) ;
F_41 ( V_13 , NULL ) ;
F_51 ( V_115 -> V_11 ) ;
F_50 ( V_115 ) ;
F_52 ( V_13 , 0 ) ;
}
static int T_8 F_55 ( void )
{
return F_56 ( & V_141 ) ;
}
static void T_9 F_57 ( void )
{
F_58 ( & V_141 ) ;
}
