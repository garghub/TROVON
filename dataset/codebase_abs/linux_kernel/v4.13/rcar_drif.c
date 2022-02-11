static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
F_6 (i, &sdr->cur_ch_mask)
if ( V_7 -> V_2 [ V_8 ] -> V_9 ) {
F_7 ( V_7 -> V_2 [ V_8 ] -> V_9 ) ;
V_7 -> V_2 [ V_8 ] -> V_9 = NULL ;
}
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_10 V_11 ;
unsigned int V_8 ;
int V_12 = - V_13 ;
F_6 (i, &sdr->cur_ch_mask) {
struct V_1 * V_2 = V_7 -> V_2 [ V_8 ] ;
V_2 -> V_9 = F_9 ( & V_2 -> V_14 -> V_15 , L_1 ) ;
if ( ! V_2 -> V_9 ) {
F_10 ( V_7 , L_2 , V_8 ) ;
goto V_16;
}
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_17 = ( V_18 ) ( V_2 -> V_19 + V_20 ) ;
V_11 . V_21 = V_22 ;
V_12 = F_11 ( V_2 -> V_9 , & V_11 ) ;
if ( V_12 ) {
F_10 ( V_7 , L_3 , V_8 ) ;
goto V_16;
}
}
return 0 ;
V_16:
F_5 ( V_7 ) ;
return V_12 ;
}
static void F_12 ( struct V_6 * V_7 ,
enum V_23 V_24 )
{
struct V_25 * V_26 , * V_27 ;
unsigned long V_28 ;
F_13 ( & V_7 -> V_29 , V_28 ) ;
F_14 (fbuf, tmp, &sdr->queued_bufs, list) {
F_15 ( & V_26 -> V_30 ) ;
F_16 ( & V_26 -> V_31 . V_32 , V_24 ) ;
}
F_17 ( & V_7 -> V_29 , V_28 ) ;
}
static inline void F_18 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
F_6 (i, &sdr->cur_ch_mask) {
F_1 ( V_7 -> V_2 [ V_8 ] , V_33 ,
V_34 ) ;
F_1 ( V_7 -> V_2 [ V_8 ] , V_35 , V_7 -> V_36 ) ;
F_19 ( V_7 , L_4 ,
V_8 , F_3 ( V_7 -> V_2 [ V_8 ] , V_35 ) ) ;
}
}
static int F_20 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
F_19 ( V_7 , L_5 ,
V_7 -> V_37 -> V_38 , V_7 -> V_37 -> V_39 , V_7 -> V_37 -> V_40 ) ;
if ( V_7 -> V_37 -> V_40 > V_7 -> V_41 ) {
F_10 ( V_7 , L_6 ,
V_7 -> V_37 -> V_40 , V_7 -> V_41 ) ;
return - V_42 ;
}
F_6 (i, &sdr->cur_ch_mask) {
T_1 V_43 ;
V_43 = F_21 ( 2 ) |
F_22 ( V_7 -> V_37 -> V_38 ) |
F_23 ( V_7 -> V_37 -> V_39 ) ;
F_1 ( V_7 -> V_2 [ V_8 ] , V_44 , V_43 ) ;
V_43 = F_22 ( V_7 -> V_37 -> V_38 ) |
F_23 ( V_7 -> V_37 -> V_39 ) ;
F_1 ( V_7 -> V_2 [ V_8 ] , V_45 , V_43 ) ;
F_19 ( V_7 , L_7 ,
V_8 , F_3 ( V_7 -> V_2 [ V_8 ] , V_44 ) ,
F_3 ( V_7 -> V_2 [ V_8 ] , V_45 ) ) ;
}
return 0 ;
}
static void F_24 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
F_6 (i, &sdr->cur_ch_mask) {
struct V_1 * V_2 = V_7 -> V_2 [ V_8 ] ;
if ( V_2 -> V_46 [ 0 ] . V_47 ) {
F_25 ( & V_2 -> V_14 -> V_15 ,
V_7 -> V_48 * V_49 ,
V_2 -> V_46 [ 0 ] . V_47 , V_2 -> V_50 ) ;
V_2 -> V_46 [ 0 ] . V_47 = NULL ;
}
}
}
static int F_26 ( struct V_6 * V_7 )
{
int V_12 = - V_51 ;
unsigned int V_8 , V_52 ;
void * V_47 ;
F_6 (i, &sdr->cur_ch_mask) {
struct V_1 * V_2 = V_7 -> V_2 [ V_8 ] ;
V_47 = F_27 ( & V_2 -> V_14 -> V_15 ,
V_7 -> V_48 * V_49 ,
& V_2 -> V_50 , V_53 ) ;
if ( ! V_47 ) {
F_10 ( V_7 ,
L_8 ,
V_8 , V_49 , V_7 -> V_48 ) ;
goto error;
}
for ( V_52 = 0 ; V_52 < V_49 ; V_52 ++ ) {
V_2 -> V_46 [ V_52 ] . V_47 = V_47 + ( V_52 * V_7 -> V_48 ) ;
V_2 -> V_46 [ V_52 ] . V_54 = 0 ;
}
}
return 0 ;
error:
return V_12 ;
}
static int F_28 ( struct V_55 * V_56 ,
unsigned int * V_57 , unsigned int * V_58 ,
unsigned int V_59 [] , struct V_60 * V_61 [] )
{
struct V_6 * V_7 = F_29 ( V_56 ) ;
if ( V_56 -> V_57 + * V_57 < 16 )
* V_57 = 16 - V_56 -> V_57 ;
* V_58 = 1 ;
V_59 [ 0 ] = F_30 ( V_7 -> V_37 -> V_62 ) ;
F_19 ( V_7 , L_9 , * V_57 , V_59 [ 0 ] ) ;
return 0 ;
}
static void F_31 ( struct V_63 * V_31 )
{
struct V_64 * V_65 = F_32 ( V_31 ) ;
struct V_6 * V_7 = F_29 ( V_31 -> V_55 ) ;
struct V_25 * V_26 =
F_33 ( V_65 , struct V_25 , V_31 ) ;
unsigned long V_28 ;
F_19 ( V_7 , L_10 , V_31 -> V_66 ) ;
F_13 ( & V_7 -> V_29 , V_28 ) ;
F_34 ( & V_26 -> V_30 , & V_7 -> V_67 ) ;
F_17 ( & V_7 -> V_29 , V_28 ) ;
}
static struct V_25 *
F_35 ( struct V_6 * V_7 )
{
struct V_25 * V_26 ;
unsigned long V_28 ;
F_13 ( & V_7 -> V_29 , V_28 ) ;
V_26 = F_36 ( & V_7 -> V_67 , struct
V_25 , V_30 ) ;
if ( ! V_26 ) {
F_19 ( V_7 , L_11 , V_7 -> V_68 ) ;
F_17 ( & V_7 -> V_29 , V_28 ) ;
return NULL ;
}
F_15 ( & V_26 -> V_30 ) ;
F_17 ( & V_7 -> V_29 , V_28 ) ;
return V_26 ;
}
static inline bool F_37 ( struct V_69 * * V_46 )
{
return ( V_46 [ 0 ] -> V_54 & V_46 [ 1 ] -> V_54 & V_70 ) ;
}
static inline bool F_38 ( struct V_69 * * V_46 )
{
return ( ( V_46 [ 0 ] -> V_54 | V_46 [ 1 ] -> V_54 ) & V_71 ) ;
}
static inline void F_39 ( struct V_69 * * V_46 ,
unsigned int V_72 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_73 ; V_8 ++ )
V_46 [ V_8 ] -> V_54 &= ~ V_72 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_74 )
{
T_1 V_75 ;
V_2 -> V_46 [ V_74 ] . V_54 |= V_70 ;
V_75 = F_3 ( V_2 , V_76 ) ;
if ( F_41 ( V_75 & V_77 ) ) {
F_1 ( V_2 , V_76 , V_75 ) ;
V_2 -> V_46 [ V_74 ] . V_54 |= V_71 ;
}
}
static void F_42 ( void * V_78 )
{
struct V_1 * V_2 = V_78 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_69 * V_46 [ V_73 ] ;
struct V_25 * V_26 ;
bool V_79 = false ;
T_1 V_74 , V_68 ;
unsigned int V_8 ;
F_43 ( & V_7 -> V_80 ) ;
if ( ! F_44 ( & V_7 -> V_81 ) ) {
F_45 ( & V_7 -> V_80 ) ;
return;
}
V_74 = V_7 -> V_68 % V_49 ;
F_40 ( V_2 , V_74 ) ;
if ( V_7 -> V_41 == V_73 ) {
V_46 [ 0 ] = V_2 -> V_82 ? F_46 ( V_7 , V_2 -> V_82 , V_74 ) :
& V_2 -> V_46 [ V_74 ] ;
V_46 [ 1 ] = V_2 -> V_82 ? & V_2 -> V_46 [ V_74 ] :
F_46 ( V_7 , V_2 -> V_82 , V_74 ) ;
if ( ! F_37 ( V_46 ) ) {
F_45 ( & V_7 -> V_80 ) ;
return;
}
F_39 ( V_46 , V_70 ) ;
if ( F_38 ( V_46 ) ) {
V_79 = true ;
F_39 ( V_46 , V_71 ) ;
}
} else {
V_46 [ 0 ] = & V_2 -> V_46 [ V_74 ] ;
if ( V_46 [ 0 ] -> V_54 & V_71 ) {
V_79 = true ;
V_46 [ 0 ] -> V_54 &= ~ V_71 ;
}
}
V_68 = V_7 -> V_68 ++ ;
F_45 ( & V_7 -> V_80 ) ;
F_19 ( V_7 , L_12 , V_2 -> V_82 , V_68 ) ;
V_26 = F_35 ( V_7 ) ;
if ( ! V_26 )
return;
for ( V_8 = 0 ; V_8 < V_73 ; V_8 ++ )
memcpy ( F_47 ( & V_26 -> V_31 . V_32 , 0 ) +
V_8 * V_7 -> V_48 , V_46 [ V_8 ] -> V_47 , V_7 -> V_48 ) ;
V_26 -> V_31 . V_83 = V_84 ;
V_26 -> V_31 . V_85 = V_68 ;
V_26 -> V_31 . V_32 . V_86 = F_48 () ;
F_49 ( & V_26 -> V_31 . V_32 , 0 , V_7 -> V_37 -> V_62 ) ;
F_16 ( & V_26 -> V_31 . V_32 ,
V_79 ? V_87 : V_88 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_47 = V_2 -> V_50 ;
struct V_89 * V_90 ;
T_3 V_91 ;
int V_12 = - V_92 ;
V_90 = F_51 ( V_2 -> V_9 , V_47 ,
V_7 -> V_48 * V_49 ,
V_7 -> V_48 , V_93 ,
V_94 | V_95 ) ;
if ( ! V_90 ) {
F_10 ( V_7 , L_13 , V_2 -> V_82 ) ;
return V_12 ;
}
V_90 -> V_96 = F_42 ;
V_90 -> V_97 = V_2 ;
V_91 = F_52 ( V_90 ) ;
if ( F_53 ( V_91 ) ) {
F_10 ( V_7 , L_14 , V_2 -> V_82 ) ;
return V_12 ;
}
F_54 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_55 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
T_1 V_98 ;
int V_12 ;
F_6 (i, &sdr->cur_ch_mask) {
V_98 = F_3 ( V_7 -> V_2 [ V_8 ] , V_99 ) ;
V_98 |= ( V_100 |
V_101 ) ;
F_1 ( V_7 -> V_2 [ V_8 ] , V_99 , V_98 ) ;
}
F_6 (i, &sdr->cur_ch_mask) {
V_12 = F_56 ( V_7 -> V_2 [ V_8 ] -> V_5 + V_99 ,
V_98 , V_98 & V_101 , 7 , 100000 ) ;
if ( V_12 ) {
F_10 ( V_7 , L_15 , V_8 ,
F_3 ( V_7 -> V_2 [ V_8 ] , V_99 ) ) ;
break;
}
}
return V_12 ;
}
static void F_57 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
T_1 V_98 ;
int V_12 ;
F_6 (i, &sdr->cur_ch_mask) {
V_98 = F_3 ( V_7 -> V_2 [ V_8 ] , V_99 ) ;
V_98 &= ~ V_101 ;
F_1 ( V_7 -> V_2 [ V_8 ] , V_99 , V_98 ) ;
}
F_6 (i, &sdr->cur_ch_mask) {
V_12 = F_56 ( V_7 -> V_2 [ V_8 ] -> V_5 + V_99 ,
V_98 , ! ( V_98 & V_101 ) , 7 , 100000 ) ;
if ( V_12 )
F_58 ( & V_7 -> V_102 -> V_15 ,
L_16 ,
V_8 , F_3 ( V_7 -> V_2 [ V_8 ] , V_99 ) ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_103 , 0x00000000 ) ;
F_60 ( V_2 -> V_9 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
F_57 ( V_7 ) ;
F_6 (i, &sdr->cur_ch_mask)
F_59 ( V_7 -> V_2 [ V_8 ] ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_98 , V_75 ;
int V_12 ;
F_1 ( V_2 , V_99 , V_104 ) ;
V_12 = F_56 ( V_2 -> V_5 + V_99 , V_98 ,
! ( V_98 & V_104 ) , 7 , 100000 ) ;
if ( V_12 ) {
F_10 ( V_7 , L_17 ,
V_2 -> V_82 , F_3 ( V_2 , V_99 ) ) ;
return V_12 ;
}
V_12 = F_50 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_75 = V_105 | V_106 | V_107 |
V_108 | V_77 ;
F_1 ( V_2 , V_76 , V_75 ) ;
F_1 ( V_2 , V_103 , 0x00009000 ) ;
return V_12 ;
}
static int F_63 ( struct V_6 * V_7 )
{
unsigned long V_109 = 0 ;
unsigned int V_8 ;
int V_12 ;
F_6 (i, &sdr->cur_ch_mask) {
V_12 = F_62 ( V_7 -> V_2 [ V_8 ] ) ;
if ( V_12 )
goto V_110;
V_109 |= F_64 ( V_8 ) ;
}
V_12 = F_55 ( V_7 ) ;
if ( V_12 )
goto V_111;
V_7 -> V_68 = 0 ;
return V_12 ;
V_111:
F_57 ( V_7 ) ;
V_110:
F_6 (i, &enabled)
F_59 ( V_7 -> V_2 [ V_8 ] ) ;
return V_12 ;
}
static int F_65 ( struct V_55 * V_56 , unsigned int V_112 )
{
struct V_6 * V_7 = F_29 ( V_56 ) ;
unsigned long V_109 = 0 ;
unsigned int V_8 ;
int V_12 ;
F_66 ( & V_7 -> V_113 ) ;
F_6 (i, &sdr->cur_ch_mask) {
V_12 = F_67 ( V_7 -> V_2 [ V_8 ] -> V_114 ) ;
if ( V_12 )
goto error;
V_109 |= F_64 ( V_8 ) ;
}
F_18 ( V_7 ) ;
V_12 = F_20 ( V_7 ) ;
if ( V_12 )
goto error;
if ( V_7 -> V_41 == V_73 )
V_7 -> V_48 = V_7 -> V_37 -> V_62 / V_73 ;
else
V_7 -> V_48 = V_7 -> V_37 -> V_62 ;
F_19 ( V_7 , L_18 ,
V_49 , V_7 -> V_48 ) ;
V_12 = F_8 ( V_7 ) ;
if ( V_12 )
goto error;
V_12 = F_26 ( V_7 ) ;
if ( V_12 )
goto error;
V_12 = F_63 ( V_7 ) ;
if ( V_12 )
goto error;
F_68 ( & V_7 -> V_113 ) ;
return V_12 ;
error:
F_12 ( V_7 , V_115 ) ;
F_24 ( V_7 ) ;
F_5 ( V_7 ) ;
F_6 (i, &enabled)
F_69 ( V_7 -> V_2 [ V_8 ] -> V_114 ) ;
F_68 ( & V_7 -> V_113 ) ;
return V_12 ;
}
static void F_70 ( struct V_55 * V_56 )
{
struct V_6 * V_7 = F_29 ( V_56 ) ;
unsigned int V_8 ;
F_66 ( & V_7 -> V_113 ) ;
F_61 ( V_7 ) ;
F_12 ( V_7 , V_87 ) ;
F_24 ( V_7 ) ;
F_5 ( V_7 ) ;
F_6 (i, &sdr->cur_ch_mask)
F_69 ( V_7 -> V_2 [ V_8 ] -> V_114 ) ;
F_68 ( & V_7 -> V_113 ) ;
}
static int F_71 ( struct V_116 * V_116 , void * V_117 ,
struct V_118 * V_119 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
F_73 ( V_119 -> V_120 , V_121 , sizeof( V_119 -> V_120 ) ) ;
F_73 ( V_119 -> V_122 , V_7 -> V_102 -> V_123 , sizeof( V_119 -> V_122 ) ) ;
snprintf ( V_119 -> V_124 , sizeof( V_119 -> V_124 ) , L_19 ,
V_7 -> V_102 -> V_123 ) ;
return 0 ;
}
static int F_74 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_75 ( V_125 ) ; V_8 ++ ) {
if ( V_7 -> V_126 == V_125 [ V_8 ] . V_40 ) {
V_7 -> V_37 = & V_125 [ V_8 ] ;
V_7 -> V_127 = V_7 -> V_128 ;
V_7 -> V_41 = V_7 -> V_126 ;
F_76 ( V_7 -> V_15 , L_20 ,
V_8 , V_7 -> V_127 , V_7 -> V_41 ) ;
return 0 ;
}
}
return - V_42 ;
}
static int F_77 ( struct V_116 * V_116 , void * V_129 ,
struct V_130 * V_131 )
{
if ( V_131 -> V_66 >= F_75 ( V_125 ) )
return - V_42 ;
V_131 -> V_132 = V_125 [ V_131 -> V_66 ] . V_132 ;
return 0 ;
}
static int F_78 ( struct V_116 * V_116 , void * V_129 ,
struct V_133 * V_131 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
V_131 -> V_37 . V_7 . V_132 = V_7 -> V_37 -> V_132 ;
V_131 -> V_37 . V_7 . V_62 = V_7 -> V_37 -> V_62 ;
return 0 ;
}
static int F_79 ( struct V_116 * V_116 , void * V_129 ,
struct V_133 * V_131 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
struct V_55 * V_134 = & V_7 -> V_81 ;
unsigned int V_8 ;
if ( F_80 ( V_134 ) )
return - V_135 ;
for ( V_8 = 0 ; V_8 < F_75 ( V_125 ) ; V_8 ++ ) {
if ( V_125 [ V_8 ] . V_132 == V_131 -> V_37 . V_7 . V_132 )
break;
}
if ( V_8 == F_75 ( V_125 ) )
V_8 = 0 ;
V_7 -> V_37 = & V_125 [ V_8 ] ;
V_131 -> V_37 . V_7 . V_132 = V_7 -> V_37 -> V_132 ;
V_131 -> V_37 . V_7 . V_62 = V_125 [ V_8 ] . V_62 ;
memset ( V_131 -> V_37 . V_7 . V_136 , 0 , sizeof( V_131 -> V_37 . V_7 . V_136 ) ) ;
if ( V_125 [ V_8 ] . V_40 < V_7 -> V_126 ) {
V_7 -> V_127 = F_64 ( 0 ) ;
V_7 -> V_41 = V_125 [ V_8 ] . V_40 ;
} else {
V_7 -> V_127 = V_7 -> V_128 ;
V_7 -> V_41 = V_7 -> V_126 ;
}
F_19 ( V_7 , L_21 ,
V_8 , V_7 -> V_127 , V_7 -> V_41 ) ;
return 0 ;
}
static int F_81 ( struct V_116 * V_116 , void * V_129 ,
struct V_133 * V_131 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_75 ( V_125 ) ; V_8 ++ ) {
if ( V_125 [ V_8 ] . V_132 == V_131 -> V_37 . V_7 . V_132 ) {
V_131 -> V_37 . V_7 . V_62 = V_125 [ V_8 ] . V_62 ;
return 0 ;
}
}
V_131 -> V_37 . V_7 . V_132 = V_125 [ 0 ] . V_132 ;
V_131 -> V_37 . V_7 . V_62 = V_125 [ 0 ] . V_62 ;
memset ( V_131 -> V_37 . V_7 . V_136 , 0 , sizeof( V_131 -> V_37 . V_7 . V_136 ) ) ;
return 0 ;
}
static int F_82 ( struct V_116 * V_116 , void * V_129 ,
struct V_137 * V_138 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
return F_83 ( V_7 -> V_139 . V_140 , V_141 , V_142 , V_138 ) ;
}
static int F_84 ( struct V_116 * V_116 , void * V_129 ,
struct V_143 * V_131 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
return F_83 ( V_7 -> V_139 . V_140 , V_141 , V_144 , V_131 ) ;
}
static int F_85 ( struct V_116 * V_116 , void * V_129 ,
const struct V_143 * V_131 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
return F_83 ( V_7 -> V_139 . V_140 , V_141 , V_145 , V_131 ) ;
}
static int F_86 ( struct V_116 * V_116 , void * V_129 ,
struct V_146 * V_147 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
return F_83 ( V_7 -> V_139 . V_140 , V_141 , V_148 , V_147 ) ;
}
static int F_87 ( struct V_116 * V_116 , void * V_129 ,
const struct V_146 * V_147 )
{
struct V_6 * V_7 = F_72 ( V_116 ) ;
return F_83 ( V_7 -> V_139 . V_140 , V_141 , V_149 , V_147 ) ;
}
static int F_88 ( struct V_6 * V_7 )
{
int V_12 ;
V_7 -> V_102 = F_89 () ;
if ( ! V_7 -> V_102 )
return - V_51 ;
snprintf ( V_7 -> V_102 -> V_123 , sizeof( V_7 -> V_102 -> V_123 ) , L_22 ) ;
V_7 -> V_102 -> V_150 = & V_151 ;
V_7 -> V_102 -> V_152 = & V_153 ;
V_7 -> V_102 -> V_154 = V_155 ;
V_7 -> V_102 -> V_156 = & V_7 -> V_113 ;
V_7 -> V_102 -> V_157 = & V_7 -> V_81 ;
V_7 -> V_102 -> V_157 -> V_156 = & V_7 -> V_158 ;
V_7 -> V_102 -> V_159 = & V_7 -> V_160 ;
V_7 -> V_102 -> V_161 = & V_7 -> V_161 ;
V_7 -> V_102 -> V_162 = V_163 | V_164 |
V_165 | V_166 ;
F_90 ( V_7 -> V_102 , V_7 ) ;
V_12 = F_91 ( V_7 -> V_102 , V_167 , - 1 ) ;
if ( V_12 ) {
V_155 ( V_7 -> V_102 ) ;
V_7 -> V_102 = NULL ;
F_92 ( V_7 -> V_15 , L_23 , V_12 ) ;
}
return V_12 ;
}
static void F_93 ( struct V_6 * V_7 )
{
F_94 ( V_7 -> V_102 ) ;
V_7 -> V_102 = NULL ;
}
static int F_95 ( struct V_168 * V_169 ,
struct V_170 * V_140 ,
struct V_171 * V_172 )
{
struct V_6 * V_7 =
F_33 ( V_169 , struct V_6 , V_169 ) ;
if ( V_7 -> V_139 . V_172 . V_173 . V_174 . V_174 !=
F_96 ( V_140 -> V_15 -> V_175 ) ) {
F_10 ( V_7 , L_24 , V_140 -> V_123 ) ;
return - V_42 ;
}
F_97 ( V_140 , V_7 ) ;
V_7 -> V_139 . V_140 = V_140 ;
F_19 ( V_7 , L_25 , V_140 -> V_123 ) ;
return 0 ;
}
static void F_98 ( struct V_168 * V_169 ,
struct V_170 * V_140 ,
struct V_171 * V_172 )
{
struct V_6 * V_7 =
F_33 ( V_169 , struct V_6 , V_169 ) ;
if ( V_7 -> V_139 . V_140 != V_140 ) {
F_10 ( V_7 , L_26 , V_140 -> V_123 ) ;
return;
}
F_99 ( & V_7 -> V_160 ) ;
V_7 -> V_161 . V_159 = NULL ;
V_7 -> V_139 . V_140 = NULL ;
F_93 ( V_7 ) ;
F_19 ( V_7 , L_27 , V_140 -> V_123 ) ;
}
static int F_100 ( struct V_168 * V_169 )
{
struct V_6 * V_7 =
F_33 ( V_169 , struct V_6 , V_169 ) ;
int V_12 ;
V_12 = F_101 ( & V_7 -> V_160 , 10 ) ;
if ( V_12 )
return - V_51 ;
V_7 -> V_161 . V_159 = & V_7 -> V_160 ;
V_12 = F_102 ( & V_7 -> V_161 ) ;
if ( V_12 ) {
F_10 ( V_7 , L_28 , V_12 ) ;
goto error;
}
V_12 = F_103 ( & V_7 -> V_160 ,
V_7 -> V_139 . V_140 -> V_159 , NULL ) ;
if ( V_12 ) {
F_10 ( V_7 , L_29 , V_12 ) ;
goto error;
}
V_12 = F_88 ( V_7 ) ;
if ( V_12 )
goto error;
return V_12 ;
error:
F_99 ( & V_7 -> V_160 ) ;
return V_12 ;
}
static void F_104 ( struct V_6 * V_7 ,
struct V_176 * V_174 )
{
T_1 V_177 ;
V_7 -> V_36 = V_178 | V_179 |
V_180 | V_181 ;
if ( ! F_105 ( V_174 , L_30 , & V_177 ) )
V_7 -> V_36 |= V_177 ? V_182 :
V_183 ;
else
V_7 -> V_36 |= V_182 ;
F_76 ( V_7 -> V_15 , L_31 , V_7 -> V_36 ) ;
}
static int F_106 ( struct V_6 * V_7 )
{
struct V_168 * V_169 = & V_7 -> V_169 ;
struct V_176 * V_174 , * V_139 ;
V_169 -> V_184 = F_107 ( V_7 -> V_15 , sizeof( * V_169 -> V_184 ) ,
V_53 ) ;
if ( ! V_169 -> V_184 )
return - V_51 ;
V_139 = F_108 ( F_96 ( V_7 -> V_15 -> V_175 ) ,
NULL ) ;
if ( ! V_139 )
return 0 ;
V_169 -> V_184 [ V_169 -> V_185 ] = & V_7 -> V_139 . V_172 ;
V_174 = F_109 ( V_139 ) ;
if ( ! V_174 ) {
F_58 ( V_7 -> V_15 , L_32 ) ;
F_110 ( V_139 ) ;
return - V_42 ;
}
V_7 -> V_139 . V_172 . V_173 . V_174 . V_174 = V_174 ;
V_7 -> V_139 . V_172 . V_186 = V_187 ;
V_169 -> V_185 ++ ;
F_104 ( V_7 , V_139 ) ;
F_110 ( V_174 ) ;
F_110 ( V_139 ) ;
return 0 ;
}
static bool F_111 ( struct V_188 * V_14 )
{
return F_112 ( V_14 -> V_15 . V_175 , L_33 ) ;
}
static struct V_189 * F_113 ( struct V_188 * V_190 )
{
struct V_189 * V_191 ;
V_191 = F_114 ( V_190 -> V_15 . V_175 , L_34 , 0 ) ;
if ( V_191 && F_115 ( V_191 ) )
return V_191 ;
return NULL ;
}
static int F_116 ( struct V_6 * V_7 ,
struct V_189 * V_191 )
{
struct V_188 * V_14 ;
struct V_1 * V_2 ;
int V_12 = 0 ;
V_14 = F_117 ( V_191 ) ;
if ( ! V_14 ) {
F_92 ( V_7 -> V_15 , L_35 ) ;
return - V_13 ;
}
F_118 ( & V_14 -> V_15 ) ;
V_2 = F_119 ( V_14 ) ;
if ( V_2 ) {
V_2 -> V_7 = V_7 ;
V_7 -> V_2 [ V_2 -> V_82 ] = V_2 ;
V_7 -> V_128 |= F_64 ( V_2 -> V_82 ) ;
} else {
F_120 ( V_7 -> V_15 , L_36 ) ;
V_12 = - V_192 ;
}
F_121 ( & V_14 -> V_15 ) ;
F_122 ( & V_14 -> V_15 ) ;
return V_12 ;
}
static int F_123 ( struct V_6 * V_7 )
{
int V_12 ;
V_12 = F_74 ( V_7 ) ;
if ( V_12 ) {
F_92 ( V_7 -> V_15 , L_37 ) ;
return V_12 ;
}
V_7 -> V_48 = V_193 ;
F_124 ( & V_7 -> V_113 ) ;
F_124 ( & V_7 -> V_158 ) ;
F_125 ( & V_7 -> V_29 ) ;
F_125 ( & V_7 -> V_80 ) ;
F_126 ( & V_7 -> V_67 ) ;
V_7 -> V_81 . type = V_194 ;
V_7 -> V_81 . V_195 = V_196 | V_197 | V_198 ;
V_7 -> V_81 . V_199 = V_7 ;
V_7 -> V_81 . V_200 = sizeof( struct V_25 ) ;
V_7 -> V_81 . V_201 = & V_202 ;
V_7 -> V_81 . V_203 = & V_204 ;
V_7 -> V_81 . V_205 = V_206 ;
V_12 = F_127 ( & V_7 -> V_81 ) ;
if ( V_12 ) {
F_92 ( V_7 -> V_15 , L_38 , V_12 ) ;
return V_12 ;
}
V_12 = F_128 ( V_7 -> V_15 , & V_7 -> V_161 ) ;
if ( V_12 ) {
F_92 ( V_7 -> V_15 , L_39 , V_12 ) ;
return V_12 ;
}
V_12 = F_106 ( V_7 ) ;
if ( V_12 )
goto error;
V_7 -> V_169 . V_207 = F_95 ;
V_7 -> V_169 . V_208 = F_98 ;
V_7 -> V_169 . V_209 = F_100 ;
V_12 = F_129 ( & V_7 -> V_161 , & V_7 -> V_169 ) ;
if ( V_12 < 0 ) {
F_92 ( V_7 -> V_15 , L_40 , V_12 ) ;
goto error;
}
return V_12 ;
error:
F_130 ( & V_7 -> V_161 ) ;
return V_12 ;
}
static void F_131 ( struct V_6 * V_7 )
{
F_132 ( & V_7 -> V_169 ) ;
F_130 ( & V_7 -> V_161 ) ;
}
static int F_133 ( struct V_188 * V_14 )
{
struct V_6 * V_7 ;
struct V_189 * V_191 ;
struct V_1 * V_2 ;
struct V_210 * V_211 ;
int V_12 ;
V_2 = F_107 ( & V_14 -> V_15 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_114 = F_134 ( & V_14 -> V_15 , L_41 ) ;
if ( F_135 ( V_2 -> V_114 ) ) {
V_12 = F_136 ( V_2 -> V_114 ) ;
F_92 ( & V_14 -> V_15 , L_42 , V_12 ) ;
return V_12 ;
}
V_211 = F_137 ( V_14 , V_212 , 0 ) ;
V_2 -> V_5 = F_138 ( & V_14 -> V_15 , V_211 ) ;
if ( F_135 ( V_2 -> V_5 ) ) {
V_12 = F_136 ( V_2 -> V_5 ) ;
F_92 ( & V_14 -> V_15 , L_43 , V_12 ) ;
return V_12 ;
}
V_2 -> V_19 = V_211 -> V_19 ;
F_139 ( V_14 , V_2 ) ;
V_191 = F_113 ( V_14 ) ;
if ( V_191 ) {
if ( ! F_111 ( V_14 ) ) {
V_2 -> V_82 = 1 ;
F_140 ( V_191 ) ;
return 0 ;
}
}
V_7 = F_107 ( & V_14 -> V_15 , sizeof( * V_7 ) , V_53 ) ;
if ( ! V_7 ) {
F_140 ( V_191 ) ;
return - V_51 ;
}
V_2 -> V_7 = V_7 ;
V_7 -> V_15 = & V_14 -> V_15 ;
V_7 -> V_2 [ V_2 -> V_82 ] = V_2 ;
V_7 -> V_128 = F_64 ( V_2 -> V_82 ) ;
if ( V_191 ) {
V_12 = F_116 ( V_7 , V_191 ) ;
F_140 ( V_191 ) ;
if ( V_12 )
return V_12 ;
}
V_7 -> V_126 = F_141 ( V_7 -> V_128 ) ;
return F_123 ( V_7 ) ;
}
static int F_142 ( struct V_188 * V_14 )
{
struct V_1 * V_2 = F_119 ( V_14 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_82 )
return 0 ;
F_131 ( V_7 ) ;
return 0 ;
}
static int T_4 F_143 ( struct V_60 * V_15 )
{
return 0 ;
}
static int T_4 F_144 ( struct V_60 * V_15 )
{
return 0 ;
}
