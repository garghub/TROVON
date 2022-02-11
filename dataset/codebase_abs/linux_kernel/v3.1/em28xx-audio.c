static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! F_3 () )
F_4 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
else
F_5 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
F_6 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
V_2 -> V_5 . V_6 [ V_3 ] = NULL ;
F_7 ( V_2 -> V_5 . V_7 [ V_3 ] ) ;
V_2 -> V_5 . V_7 [ V_3 ] = NULL ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
int V_3 ;
unsigned int V_9 ;
int V_10 = 0 ;
int V_11 ;
unsigned char * V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
switch ( V_6 -> V_11 ) {
case 0 :
case - V_18 :
break;
case - V_19 :
case - V_20 :
case - V_21 :
return;
default:
F_2 ( L_2 , V_6 -> V_11 ) ;
break;
}
if ( F_9 ( & V_2 -> V_22 ) == 0 )
return;
if ( V_2 -> V_5 . V_23 ) {
V_15 = V_2 -> V_5 . V_23 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_24 >> 3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_25 ; V_3 ++ ) {
int V_26 =
V_6 -> V_27 [ V_3 ] . V_28 / V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 +
V_6 -> V_27 [ V_3 ] . V_29 ;
if ( ! V_26 )
continue;
V_9 = V_2 -> V_5 . V_30 ;
if ( V_9 + V_26 >= V_17 -> V_31 ) {
unsigned int V_32 =
V_17 -> V_31 - V_9 ;
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_32 * V_13 ) ;
memcpy ( V_17 -> V_33 , V_12 + V_32 * V_13 ,
V_26 * V_13 - V_32 * V_13 ) ;
} else {
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_26 * V_13 ) ;
}
F_10 ( V_15 ) ;
V_2 -> V_5 . V_30 += V_26 ;
if ( V_2 -> V_5 . V_30 >=
V_17 -> V_31 )
V_2 -> V_5 . V_30 -=
V_17 -> V_31 ;
V_2 -> V_5 . V_34 += V_26 ;
if ( V_2 -> V_5 . V_34 >=
V_17 -> V_35 ) {
V_2 -> V_5 . V_34 -=
V_17 -> V_35 ;
V_10 = 1 ;
}
F_11 ( V_15 ) ;
}
if ( V_10 )
F_12 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_13 ( V_6 , V_36 ) ;
if ( V_11 < 0 ) {
F_14 ( L_3 ,
V_11 ) ;
}
return;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 , V_37 ;
const int V_38 = V_39 *
V_40 ;
F_2 ( L_4 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_41 , V_42 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_16 ( V_38 , V_36 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_43 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_38 ) ;
V_6 = F_17 ( V_39 , V_36 ) ;
if ( ! V_6 ) {
F_14 ( L_5 ) ;
for ( V_41 = 0 ; V_41 < V_3 ; V_41 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_41 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_41 ] ) ;
}
return - V_43 ;
}
V_6 -> V_2 = V_2 -> V_44 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_45 = F_18 ( V_2 -> V_44 , 0x83 ) ;
V_6 -> V_46 = V_47 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_48 = 1 ;
V_6 -> V_49 = F_8 ;
V_6 -> V_25 = V_39 ;
V_6 -> V_50 = V_38 ;
for ( V_41 = V_42 = 0 ; V_41 < V_39 ;
V_41 ++ , V_42 += V_40 ) {
V_6 -> V_27 [ V_41 ] . V_29 = V_42 ;
V_6 -> V_27 [ V_41 ] . V_26 =
V_40 ;
}
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_37 = F_13 ( V_2 -> V_5 . V_6 [ V_3 ] , V_36 ) ;
if ( V_37 ) {
F_14 ( L_6 ) ;
F_1 ( V_2 ) ;
F_19 ( & V_2 -> V_22 , 0 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_20 ( struct V_14 * V_51 ,
T_1 V_52 )
{
struct V_16 * V_17 = V_51 -> V_17 ;
F_2 ( L_7 ) ;
if ( V_17 -> V_33 ) {
if ( V_17 -> V_53 > V_52 )
return 0 ;
F_21 ( V_17 -> V_33 ) ;
}
V_17 -> V_33 = F_22 ( V_52 ) ;
if ( ! V_17 -> V_33 )
return - V_43 ;
V_17 -> V_53 = V_52 ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_54 = 0 ;
F_2 ( L_8 ) ;
if ( ! V_2 ) {
F_25 ( L_9
L_10 ) ;
return - V_55 ;
}
V_17 -> V_56 = V_57 ;
if ( ( V_2 -> V_58 == 0 || V_2 -> V_59 ) && V_2 -> V_5 . V_60 == 0 ) {
if ( V_2 -> V_59 )
V_2 -> V_58 = 1 ;
else
V_2 -> V_58 = 7 ;
F_2 ( L_11 ,
V_2 -> V_59 , V_2 -> V_58 ) ;
F_26 ( V_2 -> V_44 , V_2 -> V_59 , V_2 -> V_58 ) ;
V_2 -> V_61 = 0 ;
F_27 ( & V_2 -> V_62 ) ;
V_54 = F_28 ( V_2 ) ;
if ( V_54 < 0 )
goto V_63;
V_2 -> V_5 . V_60 ++ ;
F_29 ( & V_2 -> V_62 ) ;
}
F_30 ( V_17 , V_64 ) ;
V_2 -> V_5 . V_23 = V_15 ;
V_17 -> V_65 = V_2 ;
return 0 ;
V_63:
F_29 ( & V_2 -> V_62 ) ;
F_25 ( L_12 ) ;
return V_54 ;
}
static int F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
F_2 ( L_13 ) ;
V_2 -> V_61 = 1 ;
F_27 ( & V_2 -> V_62 ) ;
V_2 -> V_5 . V_60 -- ;
if ( F_9 ( & V_2 -> V_22 ) > 0 ) {
F_19 ( & V_2 -> V_22 , 0 ) ;
F_32 ( & V_2 -> V_66 ) ;
}
F_28 ( V_2 ) ;
if ( V_15 -> V_17 -> V_33 ) {
F_2 ( L_14 ) ;
F_21 ( V_15 -> V_17 -> V_33 ) ;
V_15 -> V_17 -> V_33 = NULL ;
}
F_29 ( & V_2 -> V_62 ) ;
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_67 * V_68 )
{
unsigned int V_69 , V_70 , V_71 ;
int V_54 ;
F_2 ( L_15 ) ;
V_54 = F_20 ( V_15 ,
F_34 ( V_68 ) ) ;
if ( V_54 < 0 )
return V_54 ;
V_71 = F_35 ( V_68 ) ;
V_70 = F_36 ( V_68 ) ;
V_69 = F_37 ( V_68 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
F_2 ( L_16 ) ;
if ( F_9 ( & V_2 -> V_22 ) > 0 ) {
F_19 ( & V_2 -> V_22 , 0 ) ;
F_32 ( & V_2 -> V_66 ) ;
}
return 0 ;
}
static int F_39 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
V_2 -> V_5 . V_30 = 0 ;
V_2 -> V_5 . V_34 = 0 ;
return 0 ;
}
static void F_40 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_41 ( V_73 , struct V_1 , V_66 ) ;
if ( F_9 ( & V_2 -> V_22 ) ) {
F_2 ( L_17 ) ;
F_15 ( V_2 ) ;
} else {
F_2 ( L_18 ) ;
F_1 ( V_2 ) ;
}
}
static int F_42 ( struct V_14 * V_15 ,
int V_74 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
int V_75 = 0 ;
switch ( V_74 ) {
case V_76 :
case V_77 :
case V_78 :
F_19 ( & V_2 -> V_22 , 1 ) ;
break;
case V_79 :
case V_80 :
case V_81 :
F_19 ( & V_2 -> V_22 , 0 ) ;
break;
default:
V_75 = - V_82 ;
}
F_32 ( & V_2 -> V_66 ) ;
return V_75 ;
}
static T_2 F_43 ( struct V_14
* V_15 )
{
unsigned long V_83 ;
struct V_1 * V_2 ;
T_2 V_84 ;
V_2 = F_24 ( V_15 ) ;
F_44 ( & V_2 -> V_5 . V_85 , V_83 ) ;
V_84 = V_2 -> V_5 . V_30 ;
F_45 ( & V_2 -> V_5 . V_85 , V_83 ) ;
return V_84 ;
}
static struct V_86 * F_46 ( struct V_14 * V_51 ,
unsigned long V_29 )
{
void * V_87 = V_51 -> V_17 -> V_33 + V_29 ;
return F_47 ( V_87 ) ;
}
static int F_48 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
V_91 -> type = V_92 ;
V_91 -> V_93 = 2 ;
V_91 -> V_94 . integer . V_95 = 0 ;
V_91 -> V_94 . integer . V_96 = 0x1f ;
return 0 ;
}
static int F_49 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_50 ( V_89 ) ;
T_3 V_98 = ( 0x1f - ( V_94 -> V_94 . integer . V_94 [ 0 ] & 0x1f ) ) |
( 0x1f - ( V_94 -> V_94 . integer . V_94 [ 1 ] & 0x1f ) ) << 8 ;
int V_99 ;
F_27 ( & V_2 -> V_62 ) ;
V_99 = F_51 ( V_2 , V_89 -> V_100 ) ;
if ( V_99 < 0 )
goto V_63;
V_98 |= V_99 & 0x8000 ;
V_99 = F_52 ( V_2 , V_89 -> V_100 , V_98 ) ;
if ( V_99 < 0 )
goto V_63;
F_2 ( L_19 ,
( V_98 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
V_63:
F_29 ( & V_2 -> V_62 ) ;
return V_99 ;
}
static int F_53 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_50 ( V_89 ) ;
int V_98 ;
F_27 ( & V_2 -> V_62 ) ;
V_98 = F_51 ( V_2 , V_89 -> V_100 ) ;
F_29 ( & V_2 -> V_62 ) ;
if ( V_98 < 0 )
return V_98 ;
F_2 ( L_22 ,
( V_98 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
V_94 -> V_94 . integer . V_94 [ 0 ] = 0x1f - ( V_98 & 0x1f ) ;
V_94 -> V_94 . integer . V_94 [ 1 ] = 0x1f - ( ( V_98 << 8 ) & 0x1f ) ;
return 0 ;
}
static int F_54 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_50 ( V_89 ) ;
T_3 V_98 = V_94 -> V_94 . integer . V_94 [ 0 ] ;
int V_99 ;
F_27 ( & V_2 -> V_62 ) ;
V_99 = F_51 ( V_2 , V_89 -> V_100 ) ;
if ( V_99 < 0 )
goto V_63;
if ( V_98 )
V_99 &= 0x1f1f ;
else
V_99 |= 0x8000 ;
V_99 = F_52 ( V_2 , V_89 -> V_100 , V_99 ) ;
if ( V_99 < 0 )
goto V_63;
F_2 ( L_19 ,
( V_98 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
V_63:
F_29 ( & V_2 -> V_62 ) ;
return V_99 ;
}
static int F_55 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_50 ( V_89 ) ;
int V_98 ;
F_27 ( & V_2 -> V_62 ) ;
V_98 = F_51 ( V_2 , V_89 -> V_100 ) ;
F_29 ( & V_2 -> V_62 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( V_98 & 0x8000 )
V_94 -> V_94 . integer . V_94 [ 0 ] = 0 ;
else
V_94 -> V_94 . integer . V_94 [ 0 ] = 1 ;
F_2 ( L_22 ,
( V_98 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
return 0 ;
}
static int F_56 ( struct V_101 * V_102 , struct V_1 * V_2 ,
char * V_103 , int V_104 )
{
int V_63 ;
char V_105 [ 44 ] ;
struct V_88 * V_106 ;
struct V_107 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_109 = V_110 ,
V_108 . V_100 = V_104 ,
V_108 . V_103 = V_105 ,
sprintf ( V_105 , L_23 , V_103 ) ;
V_108 . V_111 = F_55 ;
V_108 . V_112 = F_54 ;
V_108 . V_91 = V_113 ;
V_106 = F_57 ( & V_108 , V_2 ) ;
V_63 = F_58 ( V_102 , V_106 ) ;
if ( V_63 < 0 )
return V_63 ;
F_2 ( L_24 ,
V_105 , V_104 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_109 = V_110 ,
V_108 . V_100 = V_104 ,
V_108 . V_103 = V_105 ,
sprintf ( V_105 , L_25 , V_103 ) ;
V_108 . V_111 = F_53 ;
V_108 . V_112 = F_49 ;
V_108 . V_91 = F_48 ;
V_108 . V_114 . V_115 = V_116 ,
V_106 = F_57 ( & V_108 , V_2 ) ;
V_63 = F_58 ( V_102 , V_106 ) ;
if ( V_63 < 0 )
return V_63 ;
F_2 ( L_24 ,
V_105 , V_104 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_117 * V_5 = & V_2 -> V_5 ;
struct V_118 * V_119 ;
struct V_101 * V_102 ;
static int V_120 ;
int V_63 ;
if ( ! V_2 -> V_121 || V_2 -> V_59 < 0 ) {
return 0 ;
}
F_60 ( V_122 L_26 ) ;
F_60 ( V_122 L_27
L_28 ) ;
F_60 ( V_122 L_29 ) ;
V_63 = F_61 ( V_123 [ V_120 ] , L_30 , V_124 , 0 ,
& V_102 ) ;
if ( V_63 < 0 )
return V_63 ;
F_62 ( & V_5 -> V_85 ) ;
V_63 = F_63 ( V_102 , L_30 , 0 , 0 , 1 , & V_119 ) ;
if ( V_63 < 0 ) {
F_64 ( V_102 ) ;
return V_63 ;
}
F_65 ( V_119 , V_125 , & V_126 ) ;
V_119 -> V_127 = 0 ;
V_119 -> V_65 = V_2 ;
strcpy ( V_119 -> V_103 , L_31 ) ;
F_66 ( V_102 , & V_2 -> V_44 -> V_2 ) ;
strcpy ( V_102 -> V_128 , L_32 ) ;
strcpy ( V_102 -> V_129 , L_30 ) ;
strcpy ( V_102 -> V_130 , L_33 ) ;
F_67 ( & V_2 -> V_66 , F_40 ) ;
if ( V_2 -> V_131 . V_132 != V_133 ) {
F_56 ( V_102 , V_2 , L_34 , V_134 ) ;
F_56 ( V_102 , V_2 , L_35 , V_135 ) ;
F_56 ( V_102 , V_2 , L_36 , V_136 ) ;
F_56 ( V_102 , V_2 , L_37 , V_136 ) ;
F_56 ( V_102 , V_2 , L_38 , V_137 ) ;
F_56 ( V_102 , V_2 , L_39 , V_138 ) ;
F_56 ( V_102 , V_2 , L_40 , V_139 ) ;
F_56 ( V_102 , V_2 , L_41 , V_140 ) ;
F_56 ( V_102 , V_2 , L_42 , V_141 ) ;
F_56 ( V_102 , V_2 , L_43 , V_142 ) ;
F_56 ( V_102 , V_2 , L_44 , V_143 ) ;
F_56 ( V_102 , V_2 , L_45 , V_144 ) ;
}
V_63 = F_68 ( V_102 ) ;
if ( V_63 < 0 ) {
F_64 ( V_102 ) ;
return V_63 ;
}
V_5 -> V_145 = V_102 ;
V_5 -> V_44 = V_2 -> V_44 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_121 != 1 ) {
return 0 ;
}
if ( V_2 -> V_5 . V_145 ) {
F_64 ( V_2 -> V_5 . V_145 ) ;
V_2 -> V_5 . V_145 = NULL ;
}
return 0 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_146 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_146 ) ;
}
