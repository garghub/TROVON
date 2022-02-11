static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_3 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
if ( V_2 -> V_13 [ V_3 ] ) {
V_10 = & V_2 -> V_13 [ V_3 ] -> V_10 ;
V_10 -> V_14 = V_8 -> V_15 -> V_14 ;
V_10 -> V_16 = V_2 -> V_16 ++ ;
V_12 = & V_10 -> V_12 ;
if ( V_8 -> V_17 == V_18 )
memcpy ( F_2 ( V_12 , 0 ) , V_5 -> V_19 ,
V_5 -> V_20 ) ;
V_12 -> V_21 = F_3 () ;
F_4 ( V_12 , V_22 ) ;
}
V_2 -> V_3 = ! V_3 ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_3 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_23 * V_23 ;
unsigned long V_24 ;
F_6 ( & V_8 -> V_25 , V_24 ) ;
V_23 = V_8 -> V_23 ;
F_7 ( & V_8 -> V_25 , V_24 ) ;
if ( ! V_23 ) {
F_8 ( 1 , L_1 ) ;
return;
}
if ( V_5 -> V_19 ) {
F_9 ( V_8 -> V_23 , V_5 -> V_20 ,
V_5 -> V_19 , V_5 -> V_26 ) ;
V_5 -> V_19 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_27 = V_3 ? V_28 [ V_2 -> V_29 ] : V_30 [ V_2 -> V_29 ] ;
unsigned int V_31 ;
void * V_19 ;
F_8 ( V_2 -> V_6 [ V_3 ] . V_19 ,
L_2 ) ;
V_31 = ( V_2 -> V_32 * V_2 -> V_33 * V_2 -> V_34 -> V_35 ) >> 3 ;
V_19 = F_11 ( V_8 -> V_23 , V_31 ,
& V_2 -> V_6 [ V_3 ] . V_26 ) ;
if ( ! V_19 ) {
F_12 ( & V_8 -> V_36 ,
L_3 ,
V_2 -> V_29 , V_3 ? L_4 : L_5 ) ;
return - V_37 ;
}
V_2 -> V_6 [ V_3 ] . V_20 = V_31 ;
V_2 -> V_6 [ V_3 ] . V_19 = V_19 ;
F_13 ( V_8 , V_27 , V_2 -> V_6 [ V_3 ] . V_26 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_38 * V_39 ;
while ( ! F_15 ( & V_2 -> V_40 ) ) {
V_39 = F_16 ( & V_2 -> V_40 ,
struct V_38 , V_41 ) ;
F_17 ( & V_39 -> V_41 ) ;
V_2 -> V_13 [ V_3 ] = V_39 ;
return;
}
V_2 -> V_13 [ V_3 ] = NULL ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_38 * V_39 ;
while ( ! F_15 ( & V_2 -> V_40 ) ) {
T_1 V_27 = V_3 ? V_28 [ V_2 -> V_29 ] : V_30 [ V_2 -> V_29 ] ;
T_2 V_26 ;
V_39 = F_16 ( & V_2 -> V_40 ,
struct V_38 , V_41 ) ;
F_17 ( & V_39 -> V_41 ) ;
V_26 = F_19 ( & V_39 -> V_10 . V_12 , 0 ) ;
F_13 ( V_2 -> V_8 , V_27 , V_26 ) ;
V_39 -> V_10 . V_12 . V_42 = V_43 ;
V_2 -> V_13 [ V_3 ] = V_39 ;
return;
}
V_2 -> V_13 [ V_3 ] = NULL ;
}
static int F_20 ( struct V_44 * V_45 ,
struct V_38 * V_39 ,
unsigned int V_46 )
{
struct V_47 * V_48 = F_21 ( & V_39 -> V_10 . V_12 , 0 ) ;
unsigned int V_31 , V_49 ;
struct V_50 * V_51 ;
int V_52 , V_53 ;
memset ( V_45 , 0 , V_54 ) ;
V_53 = 0 ;
F_22 (vbuf->sgl, sg, vbuf->nents, i) {
T_2 V_26 = F_23 ( V_51 ) ;
V_31 = F_24 ( V_51 ) ;
while ( V_31 && V_46 ) {
if ( V_53 == V_55 )
return - V_37 ;
V_49 = F_25 (unsigned int, len,
TW686X_MAX_SG_ENTRY_SIZE) ;
V_49 = F_25 (unsigned int, entry_len, buf_len) ;
V_45 [ V_53 ] . V_26 = F_26 ( V_26 ) ;
V_45 [ V_53 ++ ] . V_56 =
F_26 ( F_27 ( 30 ) | V_49 ) ;
V_26 += V_49 ;
V_31 -= V_49 ;
V_46 -= V_49 ;
}
if ( ! V_46 )
return 0 ;
}
return - V_37 ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_38 * V_39 ;
while ( ! F_15 ( & V_2 -> V_40 ) ) {
unsigned int V_46 ;
V_39 = F_16 ( & V_2 -> V_40 ,
struct V_38 , V_41 ) ;
F_17 ( & V_39 -> V_41 ) ;
V_46 = ( V_2 -> V_32 * V_2 -> V_33 * V_2 -> V_34 -> V_35 ) >> 3 ;
if ( F_20 ( V_2 -> V_57 [ V_3 ] , V_39 , V_46 ) ) {
F_12 ( & V_8 -> V_36 ,
L_6 ,
V_2 -> V_29 , V_3 ? L_4 : L_5 ) ;
F_4 ( & V_39 -> V_10 . V_12 , V_58 ) ;
continue;
}
V_39 -> V_10 . V_12 . V_42 = V_43 ;
V_2 -> V_13 [ V_3 ] = V_39 ;
return;
}
V_2 -> V_13 [ V_3 ] = NULL ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_3 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
if ( V_5 -> V_20 ) {
F_9 ( V_8 -> V_23 , V_5 -> V_20 ,
V_5 -> V_19 , V_5 -> V_26 ) ;
V_5 -> V_19 = NULL ;
}
V_2 -> V_57 [ V_3 ] = NULL ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ V_3 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_27 = V_3 ? V_59 [ V_2 -> V_29 ] :
V_60 [ V_2 -> V_29 ] ;
void * V_19 ;
if ( V_5 -> V_20 ) {
V_19 = F_11 ( V_8 -> V_23 , V_5 -> V_20 ,
& V_5 -> V_26 ) ;
if ( ! V_19 ) {
F_12 ( & V_8 -> V_36 ,
L_3 ,
V_2 -> V_29 , V_3 ? L_4 : L_5 ) ;
return - V_37 ;
}
V_5 -> V_19 = V_19 ;
F_13 ( V_8 , V_27 , V_5 -> V_26 ) ;
} else {
V_19 = V_8 -> V_61 [ 0 ] . V_6 [ V_3 ] . V_19 +
V_2 -> V_29 * V_54 ;
}
V_2 -> V_57 [ V_3 ] = V_19 ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 )
{
unsigned int V_62 , V_3 , V_29 , V_63 ;
if ( F_32 ( V_8 ) ) {
V_63 = F_33 ( V_8 ) ;
V_62 = V_54 ;
} else {
V_63 = 1 ;
V_62 = F_33 ( V_8 ) * V_54 ;
}
for ( V_29 = 0 ; V_29 < V_63 ; V_29 ++ ) {
struct V_1 * V_2 = & V_8 -> V_61 [ V_29 ] ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
V_2 -> V_6 [ V_3 ] . V_20 = V_62 ;
}
return 0 ;
}
static unsigned int F_34 ( unsigned int V_64 , unsigned int V_65 )
{
unsigned long V_66 ;
if ( ! V_64 || V_64 >= F_35 ( V_67 ) )
return V_65 ;
V_66 = F_36 ( V_65 - 1 , 0 ) ;
return F_37 ( V_67 [ V_64 ] & V_66 ) ;
}
static unsigned int F_38 ( unsigned int V_68 , unsigned int V_65 )
{
unsigned int V_69 , V_70 ;
int V_71 ;
V_69 = ( 12 + 15 * V_68 ) / V_65 ;
if ( ! V_69 )
return 1 ;
V_70 = F_34 ( V_69 , V_65 ) ;
V_71 = V_70 - V_68 ;
if ( V_71 < - 1 )
V_69 ++ ;
else if ( V_71 > 1 )
V_69 -- ;
if ( V_69 >= 15 )
return 0 ;
return V_69 ;
}
static void F_39 ( struct V_1 * V_2 ,
unsigned int V_68 )
{
unsigned int V_52 ;
V_52 = F_38 ( V_68 , F_40 ( V_2 -> V_72 ) ) ;
F_13 ( V_2 -> V_8 , V_73 [ V_2 -> V_29 ] , V_67 [ V_52 ] ) ;
V_2 -> V_68 = F_34 ( V_52 , F_40 ( V_2 -> V_72 ) ) ;
}
static const struct V_74 * F_41 ( unsigned int V_75 )
{
unsigned int V_76 ;
for ( V_76 = 0 ; V_76 < F_35 ( V_77 ) ; V_76 ++ )
if ( V_77 [ V_76 ] . V_75 == V_75 )
return & V_77 [ V_76 ] ;
return NULL ;
}
static int F_42 ( struct V_78 * V_79 ,
unsigned int * V_80 , unsigned int * V_81 ,
unsigned int V_82 [] , struct V_83 * V_84 [] )
{
struct V_1 * V_2 = F_43 ( V_79 ) ;
unsigned int V_85 =
( V_2 -> V_32 * V_2 -> V_33 * V_2 -> V_34 -> V_35 ) >> 3 ;
if ( V_79 -> V_86 + * V_80 < 3 )
* V_80 = 3 - V_79 -> V_86 ;
if ( * V_81 ) {
if ( * V_81 != 1 || V_82 [ 0 ] < V_85 )
return - V_87 ;
return 0 ;
}
V_82 [ 0 ] = V_85 ;
* V_81 = 1 ;
return 0 ;
}
static void F_44 ( struct V_11 * V_10 )
{
struct V_1 * V_2 = F_43 ( V_10 -> V_78 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_23 * V_23 ;
unsigned long V_24 ;
struct V_9 * V_48 = F_45 ( V_10 ) ;
struct V_38 * V_39 =
F_46 ( V_48 , struct V_38 , V_10 ) ;
F_6 ( & V_8 -> V_25 , V_24 ) ;
V_23 = V_8 -> V_23 ;
F_7 ( & V_8 -> V_25 , V_24 ) ;
if ( ! V_23 ) {
F_4 ( & V_39 -> V_10 . V_12 , V_58 ) ;
return;
}
F_6 ( & V_2 -> V_88 , V_24 ) ;
F_47 ( & V_39 -> V_41 , & V_2 -> V_40 ) ;
F_7 ( & V_2 -> V_88 , V_24 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
enum V_89 V_42 )
{
unsigned int V_3 ;
while ( ! F_15 ( & V_2 -> V_40 ) ) {
struct V_38 * V_39 ;
V_39 = F_16 ( & V_2 -> V_40 ,
struct V_38 , V_41 ) ;
F_17 ( & V_39 -> V_41 ) ;
F_4 ( & V_39 -> V_10 . V_12 , V_42 ) ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
if ( V_2 -> V_13 [ V_3 ] )
F_4 ( & V_2 -> V_13 [ V_3 ] -> V_10 . V_12 , V_42 ) ;
V_2 -> V_13 [ V_3 ] = NULL ;
}
}
static int F_49 ( struct V_78 * V_79 , unsigned int V_53 )
{
struct V_1 * V_2 = F_43 ( V_79 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_23 * V_23 ;
unsigned long V_24 ;
int V_3 , V_90 ;
F_6 ( & V_8 -> V_25 , V_24 ) ;
V_23 = V_8 -> V_23 ;
F_7 ( & V_8 -> V_25 , V_24 ) ;
if ( ! V_23 ) {
V_90 = - V_91 ;
goto V_92;
}
F_6 ( & V_2 -> V_88 , V_24 ) ;
if ( V_8 -> V_17 == V_18 &&
( ! V_2 -> V_6 [ 0 ] . V_19 || ! V_2 -> V_6 [ 1 ] . V_19 ) ) {
F_7 ( & V_2 -> V_88 , V_24 ) ;
F_12 ( & V_8 -> V_36 ,
L_7 ,
V_2 -> V_93 ) ;
V_90 = - V_37 ;
goto V_92;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
V_8 -> V_15 -> V_94 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_88 , V_24 ) ;
V_2 -> V_16 = 0 ;
V_2 -> V_3 = 0 ;
F_6 ( & V_8 -> V_25 , V_24 ) ;
F_50 ( V_8 , V_2 -> V_29 ) ;
F_7 ( & V_8 -> V_25 , V_24 ) ;
F_51 ( & V_8 -> V_95 , V_96 + F_52 ( 100 ) ) ;
return 0 ;
V_92:
F_6 ( & V_2 -> V_88 , V_24 ) ;
F_48 ( V_2 , V_97 ) ;
F_7 ( & V_2 -> V_88 , V_24 ) ;
return V_90 ;
}
static void F_53 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_43 ( V_79 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_23 * V_23 ;
unsigned long V_24 ;
F_6 ( & V_8 -> V_25 , V_24 ) ;
V_23 = V_8 -> V_23 ;
F_7 ( & V_8 -> V_25 , V_24 ) ;
if ( V_23 )
F_54 ( V_8 , V_2 -> V_29 ) ;
F_6 ( & V_2 -> V_88 , V_24 ) ;
F_48 ( V_2 , V_58 ) ;
F_7 ( & V_2 -> V_88 , V_24 ) ;
}
static int F_55 ( struct V_11 * V_10 )
{
struct V_1 * V_2 = F_43 ( V_10 -> V_78 ) ;
unsigned int V_20 =
( V_2 -> V_32 * V_2 -> V_33 * V_2 -> V_34 -> V_35 ) >> 3 ;
if ( F_56 ( V_10 , 0 ) < V_20 )
return - V_87 ;
F_57 ( V_10 , 0 , V_20 ) ;
return 0 ;
}
static int F_58 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
unsigned int V_29 ;
V_2 = F_46 ( V_99 -> V_100 , struct V_1 ,
V_101 ) ;
V_8 = V_2 -> V_8 ;
V_29 = V_2 -> V_29 ;
switch ( V_99 -> V_102 ) {
case V_103 :
F_13 ( V_8 , V_104 [ V_29 ] , V_99 -> V_105 & 0xff ) ;
return 0 ;
case V_106 :
F_13 ( V_8 , V_107 [ V_29 ] , V_99 -> V_105 ) ;
return 0 ;
case V_108 :
F_13 ( V_8 , V_109 [ V_29 ] , V_99 -> V_105 ) ;
F_13 ( V_8 , V_110 [ V_29 ] , V_99 -> V_105 ) ;
return 0 ;
case V_111 :
F_13 ( V_8 , V_112 [ V_29 ] , V_99 -> V_105 & 0xff ) ;
return 0 ;
}
return - V_87 ;
}
static int F_59 ( struct V_113 * V_113 , void * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
V_116 -> V_117 . V_118 . V_32 = V_2 -> V_32 ;
V_116 -> V_117 . V_118 . V_33 = V_2 -> V_33 ;
V_116 -> V_117 . V_118 . V_14 = V_8 -> V_15 -> V_14 ;
V_116 -> V_117 . V_118 . V_119 = V_2 -> V_34 -> V_75 ;
V_116 -> V_117 . V_118 . V_120 = V_121 ;
V_116 -> V_117 . V_118 . V_122 = ( V_116 -> V_117 . V_118 . V_32 * V_2 -> V_34 -> V_35 ) / 8 ;
V_116 -> V_117 . V_118 . V_123 = V_116 -> V_117 . V_118 . V_33 * V_116 -> V_117 . V_118 . V_122 ;
return 0 ;
}
static int F_61 ( struct V_113 * V_113 , void * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_124 = F_62 ( V_2 -> V_72 ) ;
const struct V_74 * V_34 ;
V_34 = F_41 ( V_116 -> V_117 . V_118 . V_119 ) ;
if ( ! V_34 ) {
V_34 = & V_77 [ 0 ] ;
V_116 -> V_117 . V_118 . V_119 = V_34 -> V_75 ;
}
if ( V_116 -> V_117 . V_118 . V_32 <= V_125 / 2 )
V_116 -> V_117 . V_118 . V_32 = V_125 / 2 ;
else
V_116 -> V_117 . V_118 . V_32 = V_125 ;
if ( V_116 -> V_117 . V_118 . V_33 <= V_124 / 2 )
V_116 -> V_117 . V_118 . V_33 = V_124 / 2 ;
else
V_116 -> V_117 . V_118 . V_33 = V_124 ;
V_116 -> V_117 . V_118 . V_122 = ( V_116 -> V_117 . V_118 . V_32 * V_34 -> V_35 ) / 8 ;
V_116 -> V_117 . V_118 . V_123 = V_116 -> V_117 . V_118 . V_33 * V_116 -> V_117 . V_118 . V_122 ;
V_116 -> V_117 . V_118 . V_120 = V_121 ;
V_116 -> V_117 . V_118 . V_14 = V_8 -> V_15 -> V_14 ;
return 0 ;
}
static int F_63 ( struct V_113 * V_113 , void * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_105 , V_32 , V_126 , V_33 ;
unsigned long V_127 ;
int V_90 , V_3 ;
if ( F_64 ( & V_2 -> V_128 ) )
return - V_129 ;
V_127 = V_2 -> V_32 * V_2 -> V_33 * V_2 -> V_34 -> V_35 ;
V_90 = F_61 ( V_113 , V_114 , V_116 ) ;
if ( V_90 )
return V_90 ;
V_2 -> V_34 = F_41 ( V_116 -> V_117 . V_118 . V_119 ) ;
V_2 -> V_32 = V_116 -> V_117 . V_118 . V_32 ;
V_2 -> V_33 = V_116 -> V_117 . V_118 . V_33 ;
if ( V_8 -> V_15 -> V_130 &&
V_127 != V_2 -> V_32 * V_2 -> V_33 * V_2 -> V_34 -> V_35 ) {
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
V_8 -> V_15 -> free ( V_2 , V_3 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_90 = V_8 -> V_15 -> V_130 ( V_2 , V_3 ) ;
if ( V_90 ) {
if ( V_3 > 0 )
V_8 -> V_15 -> free ( V_2 , 0 ) ;
return V_90 ;
}
}
}
V_105 = F_65 ( V_2 -> V_8 , V_131 [ V_2 -> V_29 ] ) ;
if ( V_2 -> V_32 <= V_125 / 2 )
V_105 |= F_27 ( 23 ) ;
else
V_105 &= ~ F_27 ( 23 ) ;
if ( V_2 -> V_33 <= F_62 ( V_2 -> V_72 ) / 2 )
V_105 |= F_27 ( 24 ) ;
else
V_105 &= ~ F_27 ( 24 ) ;
V_105 &= ~ 0x7ffff ;
if ( V_8 -> V_17 == V_132 ) {
T_1 V_133 , V_134 ;
V_133 = F_32 ( V_8 ) ?
0 : V_2 -> V_29 * V_55 ;
V_134 = V_133 + V_55 - 1 ;
V_105 |= ( V_134 << 10 ) | V_133 ;
}
V_105 &= ~ ( 0x7 << 20 ) ;
V_105 |= V_2 -> V_34 -> V_135 << 20 ;
F_13 ( V_2 -> V_8 , V_131 [ V_2 -> V_29 ] , V_105 ) ;
V_32 = ( V_2 -> V_32 * 2 ) & 0x7ff ;
V_33 = V_2 -> V_33 / 2 ;
V_126 = ( V_2 -> V_32 * 2 ) & 0x7ff ;
V_105 = ( V_33 << 22 ) | ( V_126 << 11 ) | V_32 ;
F_13 ( V_2 -> V_8 , V_136 [ V_2 -> V_29 ] , V_105 ) ;
return 0 ;
}
static int F_66 ( struct V_113 * V_113 , void * V_114 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_67 ( V_138 -> V_139 , L_8 , sizeof( V_138 -> V_139 ) ) ;
F_67 ( V_138 -> V_140 , V_8 -> V_141 , sizeof( V_138 -> V_140 ) ) ;
snprintf ( V_138 -> V_142 , sizeof( V_138 -> V_142 ) ,
L_9 , F_68 ( V_8 -> V_23 ) ) ;
V_138 -> V_143 = V_144 | V_145 |
V_146 ;
V_138 -> V_147 = V_138 -> V_143 | V_148 ;
return 0 ;
}
static int F_69 ( struct V_113 * V_113 , void * V_114 , T_3 V_102 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_115 V_116 ;
T_1 V_105 , V_149 ;
if ( V_2 -> V_72 == V_102 )
return 0 ;
if ( F_64 ( & V_2 -> V_128 ) )
return - V_129 ;
if ( V_102 & V_150 )
V_105 = 0 ;
else if ( V_102 & V_151 )
V_105 = 1 ;
else if ( V_102 & V_152 )
V_105 = 2 ;
else if ( V_102 & V_153 )
V_105 = 3 ;
else if ( V_102 & V_154 )
V_105 = 4 ;
else if ( V_102 & V_155 )
V_105 = 5 ;
else if ( V_102 & V_156 )
V_105 = 6 ;
else
return - V_87 ;
V_2 -> V_72 = V_102 ;
F_13 ( V_2 -> V_8 , V_157 [ V_2 -> V_29 ] , V_105 ) ;
V_105 = F_65 ( V_2 -> V_8 , V_158 ) ;
if ( V_102 & V_159 )
V_105 &= ~ ( 1 << ( V_160 + V_2 -> V_29 ) ) ;
else
V_105 |= ( 1 << ( V_160 + V_2 -> V_29 ) ) ;
F_13 ( V_2 -> V_8 , V_158 , V_105 ) ;
V_149 = F_59 ( V_113 , V_114 , & V_116 ) ;
if ( ! V_149 )
F_63 ( V_113 , V_114 , & V_116 ) ;
F_39 ( V_2 , V_2 -> V_68 ) ;
return 0 ;
}
static int F_70 ( struct V_113 * V_113 , void * V_114 , T_3 * V_161 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_162 , V_163 = 0 ;
unsigned long V_164 ;
if ( F_71 ( & V_2 -> V_128 ) )
return - V_129 ;
V_162 = F_65 ( V_8 , V_157 [ V_2 -> V_29 ] ) ;
F_13 ( V_8 , V_157 [ V_2 -> V_29 ] , 0x7 ) ;
F_13 ( V_8 , V_165 [ V_2 -> V_29 ] , 0xff ) ;
V_164 = V_96 + F_52 ( 500 ) ;
while ( F_72 ( V_164 ) ) {
V_163 = F_65 ( V_8 , V_157 [ V_2 -> V_29 ] ) ;
if ( ! ( V_163 & F_27 ( 7 ) ) )
break;
F_73 ( 100 ) ;
}
F_13 ( V_8 , V_157 [ V_2 -> V_29 ] , V_162 ) ;
if ( V_163 & F_27 ( 7 ) )
return 0 ;
V_163 = ( V_163 >> 4 ) & 0x7 ;
switch ( V_163 ) {
case V_166 :
* V_161 &= V_150 ;
break;
case V_167 :
* V_161 &= V_153 ;
break;
case V_168 :
* V_161 &= V_154 ;
break;
case V_169 :
* V_161 &= V_156 ;
break;
case V_170 :
* V_161 &= V_151 ;
break;
case V_171 :
* V_161 &= V_155 ;
break;
case V_172 :
* V_161 &= V_152 ;
break;
default:
* V_161 = 0 ;
}
return 0 ;
}
static int F_74 ( struct V_113 * V_113 , void * V_114 , T_3 * V_102 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
* V_102 = V_2 -> V_72 ;
return 0 ;
}
static int F_75 ( struct V_113 * V_113 , void * V_114 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_175 * V_176 = & V_174 -> V_177 . V_178 ;
if ( V_174 -> type != V_179 )
return - V_87 ;
V_174 -> V_177 . V_178 . V_180 = 3 ;
V_176 -> V_181 = V_182 ;
V_176 -> V_183 . V_184 = 1 ;
V_176 -> V_183 . V_185 = V_2 -> V_68 ;
return 0 ;
}
static int F_76 ( struct V_113 * V_113 , void * V_114 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
struct V_175 * V_176 = & V_174 -> V_177 . V_178 ;
unsigned int V_185 = V_176 -> V_183 . V_185 ;
unsigned int V_184 = V_176 -> V_183 . V_184 ;
unsigned int V_68 ;
if ( F_64 ( & V_2 -> V_128 ) )
return - V_129 ;
V_68 = ( ! V_184 || ! V_185 ) ? 0 : V_185 / V_184 ;
if ( V_2 -> V_68 != V_68 )
F_39 ( V_2 , V_68 ) ;
return F_75 ( V_113 , V_114 , V_174 ) ;
}
static int F_77 ( struct V_113 * V_113 , void * V_114 ,
struct V_186 * V_116 )
{
if ( V_116 -> V_64 >= F_35 ( V_77 ) )
return - V_87 ;
V_116 -> V_119 = V_77 [ V_116 -> V_64 ] . V_75 ;
return 0 ;
}
static int F_78 ( struct V_113 * V_113 , void * V_114 , unsigned int V_52 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
T_1 V_105 ;
if ( V_52 >= V_187 )
return - V_87 ;
if ( V_52 == V_2 -> V_188 )
return 0 ;
if ( F_64 ( & V_2 -> V_128 ) )
return - V_129 ;
V_2 -> V_188 = V_52 ;
V_105 = F_65 ( V_2 -> V_8 , V_131 [ V_2 -> V_29 ] ) ;
V_105 &= ~ ( 0x3 << 30 ) ;
V_105 |= V_52 << 30 ;
F_13 ( V_2 -> V_8 , V_131 [ V_2 -> V_29 ] , V_105 ) ;
return 0 ;
}
static int F_79 ( struct V_113 * V_113 , void * V_114 , unsigned int * V_52 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
* V_52 = V_2 -> V_188 ;
return 0 ;
}
static int F_80 ( struct V_113 * V_113 , void * V_114 ,
struct V_189 * V_52 )
{
struct V_1 * V_2 = F_60 ( V_113 ) ;
unsigned int V_190 ;
if ( V_52 -> V_64 >= V_187 )
return - V_87 ;
snprintf ( V_52 -> V_141 , sizeof( V_52 -> V_141 ) , L_10 , V_52 -> V_64 ) ;
V_52 -> type = V_191 ;
V_52 -> V_161 = V_2 -> V_83 -> V_192 ;
V_52 -> V_147 = V_193 ;
V_190 = F_65 ( V_2 -> V_8 , V_194 [ V_2 -> V_29 ] ) ;
V_52 -> V_195 = 0 ;
if ( V_190 & V_196 )
V_52 -> V_195 |= V_197 ;
if ( ! ( V_190 & V_198 ) )
V_52 -> V_195 |= V_199 ;
return 0 ;
}
void F_81 ( struct V_7 * V_8 , unsigned long V_200 ,
unsigned int V_201 , unsigned int V_202 ,
unsigned int * V_203 )
{
struct V_1 * V_2 ;
unsigned long V_24 ;
unsigned int V_29 , V_3 ;
F_82 (ch, &requests, max_channels(dev)) {
V_2 = & V_8 -> V_61 [ V_29 ] ;
if ( V_2 -> V_204 && ! ( V_202 & F_27 ( V_29 ) ) ) {
F_83 ( V_205 , & V_8 -> V_36 ,
L_11 , V_2 -> V_93 ) ;
V_2 -> V_204 = false ;
* V_203 |= F_27 ( V_29 ) ;
V_2 -> V_3 = 0 ;
continue;
}
V_2 -> V_204 = ! ! ( V_202 & F_27 ( V_29 ) ) ;
if ( ! V_2 -> V_204 ) {
T_1 V_206 , V_207 ;
V_206 = ( V_202 >> 24 ) & F_27 ( V_29 ) ;
V_207 = ( V_202 >> 16 ) & F_27 ( V_29 ) ;
if ( V_206 || V_207 ) {
F_83 ( V_205 , & V_8 -> V_36 ,
L_12 , V_2 -> V_93 ) ;
* V_203 |= F_27 ( V_29 ) ;
V_2 -> V_3 = 0 ;
continue;
}
}
V_3 = ! ! ( V_201 & F_27 ( V_29 ) ) ;
if ( V_2 -> V_3 != V_3 ) {
F_83 ( V_205 , & V_8 -> V_36 ,
L_13 ,
V_2 -> V_93 ) ;
* V_203 |= F_27 ( V_29 ) ;
V_2 -> V_3 = 0 ;
continue;
}
F_6 ( & V_2 -> V_88 , V_24 ) ;
F_1 ( V_2 , V_3 ) ;
V_8 -> V_15 -> V_94 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_88 , V_24 ) ;
}
}
void F_84 ( struct V_7 * V_8 )
{
unsigned int V_29 , V_3 ;
for ( V_29 = 0 ; V_29 < F_33 ( V_8 ) ; V_29 ++ ) {
struct V_1 * V_2 = & V_8 -> V_61 [ V_29 ] ;
if ( V_2 -> V_83 )
F_85 ( V_2 -> V_83 ) ;
if ( V_8 -> V_15 -> free )
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
V_8 -> V_15 -> free ( V_2 , V_3 ) ;
}
}
int F_86 ( struct V_7 * V_8 )
{
unsigned int V_29 , V_105 , V_3 ;
int V_90 ;
if ( V_8 -> V_17 == V_18 )
V_8 -> V_15 = & V_208 ;
else if ( V_8 -> V_17 == V_209 )
V_8 -> V_15 = & V_210 ;
else if ( V_8 -> V_17 == V_132 )
V_8 -> V_15 = & V_211 ;
else
return - V_87 ;
V_90 = F_87 ( & V_8 -> V_23 -> V_8 , & V_8 -> V_36 ) ;
if ( V_90 )
return V_90 ;
if ( V_8 -> V_15 -> V_212 ) {
V_90 = V_8 -> V_15 -> V_212 ( V_8 ) ;
if ( V_90 )
return V_90 ;
}
for ( V_29 = 0 ; V_29 < F_33 ( V_8 ) ; V_29 ++ ) {
struct V_1 * V_2 = & V_8 -> V_61 [ V_29 ] ;
struct V_213 * V_214 ;
F_88 ( & V_2 -> V_215 ) ;
F_89 ( & V_2 -> V_88 ) ;
F_90 ( & V_2 -> V_40 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_34 = & V_77 [ 0 ] ;
V_2 -> V_72 = V_150 ;
V_2 -> V_32 = V_125 ;
V_2 -> V_33 = F_62 ( V_2 -> V_72 ) ;
V_2 -> V_188 = 0 ;
F_13 ( V_2 -> V_8 , V_157 [ V_29 ] , 0 ) ;
F_39 ( V_2 , 30 ) ;
F_13 ( V_8 , V_216 [ V_29 ] , 0x14 ) ;
F_13 ( V_8 , V_217 [ V_29 ] , 0xd0 ) ;
F_13 ( V_8 , V_218 [ V_29 ] , 0 ) ;
if ( V_8 -> V_15 -> V_130 ) {
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_90 = V_8 -> V_15 -> V_130 ( V_2 , V_3 ) ;
if ( V_90 )
goto error;
}
}
V_2 -> V_128 . V_219 = V_220 | V_221 | V_222 ;
V_2 -> V_128 . type = V_179 ;
V_2 -> V_128 . V_223 = V_2 ;
V_2 -> V_128 . V_224 = sizeof( struct V_38 ) ;
V_2 -> V_128 . V_225 = & V_226 ;
V_2 -> V_128 . V_227 = V_8 -> V_15 -> V_227 ;
V_2 -> V_128 . V_228 = V_229 ;
V_2 -> V_128 . V_230 = 2 ;
V_2 -> V_128 . V_25 = & V_2 -> V_215 ;
V_2 -> V_128 . V_231 = V_232 ;
V_2 -> V_128 . V_8 = & V_8 -> V_23 -> V_8 ;
V_90 = F_91 ( & V_2 -> V_128 ) ;
if ( V_90 ) {
F_12 ( & V_8 -> V_36 ,
L_14 , V_29 ) ;
goto error;
}
V_90 = F_92 ( & V_2 -> V_101 , 4 ) ;
if ( V_90 ) {
F_12 ( & V_8 -> V_36 ,
L_15 , V_29 ) ;
goto error;
}
F_93 ( & V_2 -> V_101 , & V_233 ,
V_103 , - 128 , 127 , 1 , 0 ) ;
F_93 ( & V_2 -> V_101 , & V_233 ,
V_106 , 0 , 255 , 1 , 100 ) ;
F_93 ( & V_2 -> V_101 , & V_233 ,
V_108 , 0 , 255 , 1 , 128 ) ;
F_93 ( & V_2 -> V_101 , & V_233 ,
V_111 , - 128 , 127 , 1 , 0 ) ;
V_90 = V_2 -> V_101 . error ;
if ( V_90 )
goto error;
V_90 = F_94 ( & V_2 -> V_101 ) ;
if ( V_90 )
goto error;
V_214 = F_95 () ;
if ( ! V_214 ) {
F_12 ( & V_8 -> V_36 ,
L_16 , V_29 ) ;
V_90 = - V_37 ;
goto error;
}
snprintf ( V_214 -> V_141 , sizeof( V_214 -> V_141 ) , L_17 , V_8 -> V_141 ) ;
V_214 -> V_234 = & V_235 ;
V_214 -> V_236 = & V_237 ;
V_214 -> V_238 = V_239 ;
V_214 -> V_36 = & V_8 -> V_36 ;
V_214 -> V_240 = & V_2 -> V_128 ;
V_214 -> V_192 = V_159 | V_241 ;
V_214 -> V_242 = - 1 ;
V_214 -> V_25 = & V_2 -> V_215 ;
V_214 -> V_101 = & V_2 -> V_101 ;
V_2 -> V_83 = V_214 ;
F_96 ( V_214 , V_2 ) ;
V_90 = F_97 ( V_214 , V_243 , - 1 ) ;
if ( V_90 < 0 )
goto error;
V_2 -> V_93 = V_214 -> V_93 ;
}
V_105 = V_244 ;
for ( V_29 = 0 ; V_29 < F_33 ( V_8 ) ; V_29 ++ )
V_105 |= V_8 -> V_15 -> V_245 << ( 16 + V_29 * 2 ) ;
F_13 ( V_8 , V_246 , V_105 ) ;
F_13 ( V_8 , V_247 [ 0 ] , 0xe7 ) ;
F_13 ( V_8 , V_248 [ 0 ] , 0xcc ) ;
F_13 ( V_8 , V_249 [ 0 ] , 0xa5 ) ;
if ( F_33 ( V_8 ) > 4 ) {
F_13 ( V_8 , V_248 [ 1 ] , 0xcc ) ;
F_13 ( V_8 , V_249 [ 1 ] , 0xa5 ) ;
F_13 ( V_8 , V_247 [ 1 ] , 0xe7 ) ;
}
return 0 ;
error:
F_84 ( V_8 ) ;
return V_90 ;
}
