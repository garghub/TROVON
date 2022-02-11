static void T_1 * F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
return V_4 + V_6 [ V_3 ] * 4 ;
}
unsigned long F_2 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_7 = F_1 ( V_2 , V_3 ) ;
return F_3 ( V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , T_2 * V_8 ,
T_2 V_9 )
{
T_2 T_1 * V_7 = F_1 ( V_2 , V_3 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 != V_9 ; ++ V_10 )
V_8 [ V_10 ] = F_3 ( V_7 + V_10 ) ;
}
void F_5 ( struct V_1 * V_2 , int V_3 , unsigned V_8 )
{
void T_1 * V_7 = F_1 ( V_2 , V_3 ) ;
F_6 ( V_8 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 ,
const T_2 * V_8 , T_2 V_9 )
{
T_2 T_1 * V_7 = F_1 ( V_2 , V_3 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 != V_9 ; ++ V_10 )
F_6 ( V_8 [ V_10 ] , V_7 + V_10 ) ;
}
static void T_1 * F_8 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_11 ;
return V_4 + V_12 [ V_3 ] ;
}
unsigned long F_9 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_7 = F_8 ( V_2 , V_3 ) ;
return F_3 ( V_7 ) ;
}
void F_10 ( struct V_1 * V_2 , int V_3 , T_2 V_8 )
{
void T_1 * V_7 = F_8 ( V_2 , V_3 ) ;
F_6 ( V_8 , V_7 ) ;
}
T_2 F_11 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
switch ( V_13 ) {
case 1 :
V_14 = V_15 ; break;
case 2 :
V_14 = V_16 ; break;
case 3 :
V_14 = V_17 ; break;
case 4 :
V_14 = V_18 ; break;
case 5 :
V_14 = V_19 ; break;
case 6 :
V_14 = V_20 ; break;
case 7 :
V_14 = V_21 ; break;
case 0 :
F_12 () ;
default:
return 0xdeadbeef ;
}
return F_9 ( V_2 , V_14 ) ;
}
int F_13 ( struct V_1 * V_2 , int V_13 , T_2 V_22 )
{
int V_14 = - 1 ;
switch ( V_13 ) {
case 1 :
V_14 = V_15 ; break;
case 3 :
V_14 = V_17 ; break;
case 4 :
V_14 = V_18 ; break;
case 5 :
V_14 = V_19 ; break;
case 6 :
V_14 = V_20 ; break;
case 7 :
V_14 = V_21 ; break;
case 0 :
case 2 :
F_12 () ;
return - V_23 ;
}
F_10 ( V_2 , V_14 , V_22 ) ;
return 0 ;
}
static void F_14 ( struct V_24 * V_25 , enum V_26 V_27 )
{
F_15 ( V_27 >= V_28 ) ;
V_25 -> V_27 [ 0 ] = V_29 [ V_27 ] . V_30 ;
V_25 -> V_31 = V_29 [ V_27 ] . V_32 ;
V_25 -> V_33 = V_29 [ V_27 ] . V_34 ;
V_25 -> V_35 = V_29 [ V_27 ] . V_36 ;
V_25 -> V_37 = V_27 ;
memset ( & V_25 -> V_27 [ 1 ] , 0 , ( V_38 - 1 ) * sizeof( T_2 ) ) ;
#ifdef F_16
memset ( V_25 -> V_39 , 0 , V_38 * sizeof( T_2 ) ) ;
#endif
#ifdef F_17
V_25 -> V_37 = V_27 ;
#endif
}
static void F_18 ( struct V_24 * V_25 )
{
T_3 V_40 = V_25 -> V_37 ;
int V_10 ;
F_19 ( V_41 L_1 , V_29 [ V_40 ] . V_42 ) ;
for ( V_10 = 0 ; V_10 != V_25 -> V_31 ; ++ V_10 )
F_19 ( V_41 L_2 , V_10 , V_25 -> V_27 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 != V_25 -> V_33 ; ++ V_10 )
F_19 ( V_41 L_3 , V_10 , V_25 -> V_39 [ V_10 ] ) ;
F_19 ( L_4 ) ;
}
static inline void F_18 ( struct V_24 * V_25 )
{}
static int F_20 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
T_2 V_43 = V_44 ;
int V_45 ;
if ( F_2 ( V_2 , V_46 ) & ( V_47 | V_48 ) ) {
F_19 (KERN_ERR LXP L_5 , reg) ;
return - V_49 ;
}
F_7 ( V_2 , V_50 , V_25 -> V_27 , V_25 -> V_31 ) ;
F_5 ( V_2 , V_46 , V_47 ) ;
for ( V_45 = 0 ; V_45 != V_51 * 1000 ; ++ V_45 ) {
if ( F_2 ( V_2 , V_46 ) & V_48 ) {
if ( V_25 -> V_35 == 0 )
V_43 = F_2 ( V_2 , V_50 ) ;
else
V_43 = 0 ;
goto V_52;
} else
F_21 ( 1 ) ;
}
F_19 (KERN_WARNING LXP L_6
L_7 ) ;
V_52:
if ( ( V_43 & V_53 ) == 0 ) {
if ( V_25 -> V_33 ) {
F_15 ( V_25 -> V_33 >= ( V_38 - 1 ) ) ;
F_4 ( V_2 , V_54 , V_25 -> V_39 ,
V_25 -> V_33 ) ;
}
} else
F_19 ( V_55 L_8 , V_43 ) ;
F_5 ( V_2 , V_46 , 0 ) ;
switch ( V_43 ) {
case V_44 :
F_19 (KERN_WARNING LXP L_9 ) ;
return - V_56 ;
case V_57 :
F_19 (KERN_WARNING LXP L_10 ) ;
return - V_58 ;
}
F_18 ( V_25 ) ;
return V_43 ;
}
int T_4 F_22 ( struct V_1 * V_2 , T_2 * V_59 )
{
T_5 V_60 ;
unsigned long V_61 ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_63 ) ;
V_60 = F_20 ( V_2 , & V_2 -> V_25 ) ;
* V_59 = V_2 -> V_25 . V_39 [ 1 ] ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_60 ;
}
int F_25 ( struct V_1 * V_2 , T_2 * V_64 )
{
T_5 V_60 = 0 ;
unsigned long V_61 ;
T_2 V_65 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_63 ) ;
V_60 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( V_60 == 0 ) {
V_65 = V_2 -> V_25 . V_39 [ 0 ] >> V_68 ;
V_66 = V_65 & V_69 ;
if ( ( V_66 < V_70 ) ||
( V_66 > V_71 ) )
V_67 = 0 ;
else if ( V_66 >= V_72 )
V_67 = 44100 ;
else
V_67 = 48000 ;
}
F_24 ( & V_2 -> V_62 , V_61 ) ;
* V_64 = V_67 * V_2 -> V_73 ;
return V_60 ;
}
int F_26 ( struct V_1 * V_2 )
{
T_2 V_74 , V_75 ;
V_74 = F_2 ( V_2 , V_76 ) & 0x00FFFFFF ;
V_75 = F_2 ( V_2 , V_77 ) & 0x00FFFFFF ;
V_2 -> V_78 [ 5 ] = ( ( T_3 * ) ( & V_75 ) ) [ 0 ] ;
V_2 -> V_78 [ 4 ] = ( ( T_3 * ) ( & V_75 ) ) [ 1 ] ;
V_2 -> V_78 [ 3 ] = ( ( T_3 * ) ( & V_75 ) ) [ 2 ] ;
V_2 -> V_78 [ 2 ] = ( ( T_3 * ) ( & V_74 ) ) [ 0 ] ;
V_2 -> V_78 [ 1 ] = ( ( T_3 * ) ( & V_74 ) ) [ 1 ] ;
V_2 -> V_78 [ 0 ] = ( ( T_3 * ) ( & V_74 ) ) [ 2 ] ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_79 )
{
unsigned long V_61 ;
int V_60 ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_80 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_79 ;
V_60 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_60 ;
}
int F_28 ( struct V_1 * V_2 , T_2 * V_8 )
{
unsigned long V_61 ;
int V_60 ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_81 ) ;
V_2 -> V_25 . V_33 = 9 ;
V_60 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( ! V_60 )
memcpy ( V_8 , V_2 -> V_25 . V_39 , V_2 -> V_25 . V_33 * sizeof( T_2 ) ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_60 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 != V_82 ; ++ V_10 ) {
T_2 V_83 = F_2 ( V_2 , V_84 ) ;
if ( ( V_83 & V_85 ) == 0 )
return 0 ;
F_21 ( 1 ) ;
}
return - V_56 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
int V_88 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_91 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_2 -> V_25 . V_27 [ 0 ] |= V_88 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
if ( V_89 != 0 )
F_19 ( V_92 L_11 ) ;
return V_89 ;
}
int F_32 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_93 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
T_2 * V_94 , T_2 * V_95 , T_2 * V_96 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
#ifdef F_16
if ( V_96 )
memset ( V_96 , 0 , sizeof( T_2 ) * V_97 ) ;
#endif
* V_94 = 0 ;
* V_95 = 0 ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_98 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( ! V_89 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_97 ; ++ V_10 ) {
T_2 V_39 = V_2 -> V_25 . V_39 [ V_10 ] ;
if ( V_39 & ( V_99 << V_100 ) ) {
* V_95 += 1 ;
if ( V_96 )
V_96 [ V_10 ] = V_39 & V_101 ;
} else if ( ( V_39 & ( V_102 << V_100 ) )
== 0 )
* V_94 += 1 ;
}
#if 0
snd_printdd(LXP "CMD_08_ASK_BUFFERS: needed %d, freed %d\n",
*r_needed, *r_freed);
for (i = 0; i < MAX_STREAM_BUFFER; ++i) {
for (i = 0; i != chip->rmh.stat_len; ++i)
snd_printdd(" stat[%d]: %x, %x\n", i,
chip->rmh.stat[i],
chip->rmh.stat[i] & MASK_DATA_SIZE);
}
#endif
}
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_103 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_104 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
int V_89 ;
V_89 = F_37 ( V_2 , V_86 , V_87 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_35 ( V_2 , V_86 , V_87 ) ;
return V_89 ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
int V_89 = 0 ;
V_89 = F_39 ( V_2 , V_86 , V_87 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_35 ( V_2 , V_86 , V_87 ) ;
return V_89 ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
T_6 * V_105 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_106 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_2 -> V_25 . V_33 = 2 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( V_89 != 0 )
F_19 ( V_92
L_12 ) ;
else {
* V_105 = ( ( T_6 ) ( V_2 -> V_25 . V_39 [ 0 ] & V_107 )
<< 24 )
+ V_2 -> V_25 . V_39 [ 1 ] ;
}
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_41 ( struct V_1 * V_2 , T_2 V_86 , int V_87 , T_5 * V_108 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_106 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( V_89 != 0 )
F_19 ( V_92 L_13 ) ;
else
* V_108 = ( V_2 -> V_25 . V_39 [ 0 ] >> V_109 ) & 0x0F ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
static int F_42 ( struct V_1 * V_2 , T_2 V_86 ,
int V_87 , T_5 V_110 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 != 50 ; ++ V_10 ) {
T_5 V_111 ;
int V_89 = F_41 ( V_2 , V_86 , V_87 , & V_111 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_111 == V_110 )
return 0 ;
F_43 ( 1 ) ;
}
return - V_56 ;
}
int F_39 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
return F_42 ( V_2 , V_86 , V_87 , V_112 ) ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_86 , int V_87 )
{
return F_42 ( V_2 , V_86 , V_87 , V_113 ) ;
}
int F_44 ( struct V_1 * V_2 , T_2 V_86 ,
int V_87 , enum V_114 V_110 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_115 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_2 -> V_25 . V_27 [ 0 ] |= V_110 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_45 ( struct V_1 * V_2 , struct V_116 * V_117 ,
T_2 V_86 , int V_87 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
T_2 V_88 = V_117 -> V_88 ;
if ( V_117 -> V_88 != V_88 )
F_19 (KERN_ERR LXP L_14 ,
runtime->channels, channels) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_118 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
if ( V_117 -> V_119 == 16 )
V_2 -> V_25 . V_27 [ 0 ] |= ( V_120 << V_121 ) ;
if ( F_46 ( V_117 -> V_122 ) )
V_2 -> V_25 . V_27 [ 0 ] |= ( V_123 << V_121 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_88 - 1 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_47 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
int * V_108 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_124 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
* V_108 = ( V_2 -> V_25 . V_39 [ 0 ] & V_125 ) ? V_126 : V_127 ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_48 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
T_6 * V_128 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_124 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
* V_128 = ( ( T_6 ) ( V_2 -> V_25 . V_39 [ 0 ] & V_107 )
<< 32 )
+ V_2 -> V_25 . V_39 [ 1 ] ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_49 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
T_2 V_129 , T_2 V_130 , T_2 V_131 ,
T_2 * V_132 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_133 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_2 -> V_25 . V_27 [ 0 ] |= V_134 ;
V_2 -> V_25 . V_27 [ 1 ] = V_129 & V_101 ;
V_2 -> V_25 . V_27 [ 2 ] = V_130 ;
if ( V_131 ) {
V_2 -> V_25 . V_31 = 4 ;
V_2 -> V_25 . V_27 [ 3 ] = V_131 ;
V_2 -> V_25 . V_27 [ 0 ] |= V_135 ;
}
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( V_89 == 0 ) {
* V_132 = V_2 -> V_25 . V_39 [ 0 ] ;
goto V_136;
}
if ( V_89 == V_137 )
F_19 ( V_55 L_15 ) ;
if ( V_89 == V_138 )
F_19 ( V_55 L_16 ) ;
if ( V_89 == V_139 )
F_19 ( V_55 L_17 ) ;
V_136:
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_50 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
T_2 * V_140 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_141 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_2 -> V_25 . V_27 [ 0 ] |= V_142 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( V_89 == 0 )
* V_140 = V_2 -> V_25 . V_39 [ 0 ] & V_101 ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_51 ( struct V_1 * V_2 , T_2 V_86 , int V_87 ,
T_2 V_143 )
{
int V_89 ;
unsigned long V_61 ;
T_2 V_90 = F_31 ( V_87 , V_86 ) ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_141 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= V_90 ;
V_2 -> V_25 . V_27 [ 0 ] |= V_143 ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_52 ( struct V_1 * V_2 , int V_87 , int V_144 )
{
int V_89 ;
unsigned long V_61 ;
T_6 V_145 = V_144 ? 0 : 0xFFFFFFFFFFFFFFFFLLU ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( & V_2 -> V_25 , V_146 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= F_31 ( V_87 , 0 ) ;
V_2 -> V_25 . V_27 [ 1 ] = ( T_2 ) ( V_145 >> ( T_6 ) 32 ) ;
V_2 -> V_25 . V_27 [ 2 ] = ( T_2 ) ( V_145 & ( T_6 ) 0xFFFFFFFF ) ;
F_19 ( L_18 , V_2 -> V_25 . V_27 [ 0 ] , V_2 -> V_25 . V_27 [ 1 ] ,
V_2 -> V_25 . V_27 [ 2 ] ) ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
int F_53 ( struct V_1 * V_2 , int V_87 , int V_88 ,
T_2 * V_147 )
{
int V_89 = 0 ;
unsigned long V_61 ;
int V_10 ;
F_23 ( & V_2 -> V_62 , V_61 ) ;
for ( V_10 = 0 ; V_10 < V_88 ; V_10 += 4 ) {
T_2 V_148 , V_149 , V_150 , V_151 ;
F_14 ( & V_2 -> V_25 , V_152 ) ;
V_2 -> V_25 . V_27 [ 0 ] |= F_31 ( V_87 , V_10 ) ;
V_89 = F_20 ( V_2 , & V_2 -> V_25 ) ;
if ( V_89 == 0 ) {
V_148 = V_153 [ V_2 -> V_25 . V_39 [ 0 ] & 0x0F ] ;
V_149 = V_153 [ ( V_2 -> V_25 . V_39 [ 0 ] >> 4 ) & 0xf ] ;
V_150 = V_153 [ ( V_2 -> V_25 . V_39 [ 0 ] >> 8 ) & 0xf ] ;
V_151 = V_153 [ ( V_2 -> V_25 . V_39 [ 0 ] >> 12 ) & 0xf ] ;
} else
V_148 = V_149 = V_150 = V_151 = 0 ;
V_147 [ 0 ] = V_148 ;
V_147 [ 1 ] = V_149 ;
V_147 [ 2 ] = V_150 ;
V_147 [ 3 ] = V_151 ;
V_147 += 4 ;
}
F_24 ( & V_2 -> V_62 , V_61 ) ;
return V_89 ;
}
static T_2 F_54 ( struct V_1 * V_2 )
{
T_2 V_154 = F_9 ( V_2 , V_155 ) ;
if ( V_154 & V_156 ) {
T_2 V_157 ;
V_154 = V_158 ;
while ( ( V_157 = F_9 ( V_2 , V_159 ) ) ) {
V_154 |= V_157 ;
F_10 ( V_2 , V_159 , V_157 ) ;
}
return V_154 ;
}
return V_158 ;
}
static int F_55 ( struct V_1 * V_2 , T_2 * V_160 ,
int * V_161 , int * V_162 )
{
T_2 V_163 ;
T_2 V_164 = F_54 ( V_2 ) ;
if ( V_164 == V_158 )
return 0 ;
* V_160 = V_164 ;
V_163 = V_164 & V_165 ;
if ( V_163 & V_166 ) {
V_163 &= ~ V_166 ;
* V_162 = 1 ;
}
if ( V_163 ) {
* V_161 = 1 ;
}
return 1 ;
}
static int F_56 ( struct V_1 * V_2 , T_2 V_164 ,
int * V_167 ,
T_6 * V_168 ,
T_6 * V_169 )
{
int V_89 ;
T_2 V_39 [ 9 ] ;
T_6 V_170 ;
T_6 V_171 ;
#if 0
int has_underrun = (irqsrc & MASK_SYS_STATUS_URUN) ? 1 : 0;
int has_overrun = (irqsrc & MASK_SYS_STATUS_ORUN) ? 1 : 0;
#endif
int V_172 = ( V_164 & V_173 ) ? 1 : 0 ;
int V_174 = ( V_164 & V_175 ) ? 1 : 0 ;
* V_167 = ( V_164 & V_176 ) ? 1 : 0 ;
V_89 = F_28 ( V_2 , V_39 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_174 ) {
* V_168 = ( ( T_6 ) V_39 [ 3 ] << 32 )
+ V_39 [ 4 ] ;
F_57 ( V_55 L_19 ,
* V_168 ) ;
}
if ( V_172 ) {
* V_169 = ( ( T_6 ) V_39 [ 1 ] << 32 )
+ V_39 [ 2 ] ;
F_57 ( V_55 L_20 ,
* V_169 ) ;
}
V_170 = ( ( T_6 ) V_39 [ 7 ] << 32 ) + V_39 [ 8 ] ;
V_171 = ( ( T_6 ) V_39 [ 5 ] << 32 ) + V_39 [ 6 ] ;
return V_89 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_177 * V_177 )
{
struct V_178 * V_179 = V_177 -> V_180 ;
const unsigned int V_87 = V_177 -> V_87 ;
int V_89 ;
unsigned long V_61 ;
const T_2 V_88 = V_179 -> V_117 -> V_88 ;
const T_2 V_181 = V_88 * 3 ;
const T_2 V_182 = V_179 -> V_117 -> V_182 ;
const T_2 V_183 = V_182 * V_181 ;
const T_2 V_184 = V_177 -> V_185 ;
const T_2 V_186 = ( ( V_184 + 1 ) == V_179 -> V_117 -> V_187 ) ?
0 : V_184 + 1 ;
T_7 V_188 = V_179 -> V_189 . V_190 + V_184 * V_183 ;
T_2 V_191 = 0 ;
T_2 V_192 = 0 ;
T_2 V_143 = 0 ;
T_2 V_193 , V_194 ;
T_2 V_96 [ V_97 ] ;
F_57 ( L_21 ) ;
F_23 ( & V_2 -> V_195 , V_61 ) ;
V_89 = F_33 ( V_2 , 0 , V_87 , & V_193 , & V_194 , V_96 ) ;
F_57 ( V_55 L_22 , V_193 , V_194 ) ;
F_59 ( V_188 , & V_192 , & V_191 ) ;
V_89 = F_49 ( V_2 , 0 , V_87 , V_183 , V_192 , V_191 ,
& V_143 ) ;
F_57 ( V_55 L_23 ,
V_143 , ( void * ) V_188 , V_183 ) ;
V_177 -> V_185 = V_186 ;
F_24 ( & V_2 -> V_195 , V_61 ) ;
return V_89 ;
}
void F_60 ( unsigned long V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
struct V_177 * V_177 = & V_2 -> V_196 ;
int V_89 ;
F_57 ( L_24 ) ;
V_89 = F_58 ( V_2 , V_177 ) ;
if ( V_89 < 0 )
F_19 (KERN_ERR LXP
L_25 ) ;
F_61 ( V_177 -> V_180 ) ;
}
void F_62 ( unsigned long V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
struct V_177 * V_177 = & V_2 -> V_197 ;
int V_89 ;
F_57 ( L_26 ) ;
V_89 = F_58 ( V_2 , V_177 ) ;
if ( V_89 < 0 )
F_19 (KERN_ERR LXP
L_27 ) ;
F_61 ( V_177 -> V_180 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
T_6 V_198 ,
T_6 V_199 )
{
int V_89 = 0 ;
if ( V_198 ) {
F_57 ( V_55 L_28 ) ;
F_64 ( & V_2 -> V_200 ) ;
}
if ( V_199 ) {
F_57 ( V_55 L_29 ) ;
F_64 ( & V_2 -> V_201 ) ;
}
return V_89 ;
}
T_8 F_65 ( int V_202 , void * V_203 )
{
struct V_1 * V_2 = V_203 ;
int V_204 , V_205 ;
T_2 V_164 ;
F_66 ( & V_2 -> V_195 ) ;
F_57 ( L_30 ) ;
if ( ! F_55 ( V_2 , & V_164 , & V_204 , & V_205 ) ) {
F_67 ( & V_2 -> V_195 ) ;
F_57 ( L_31 ) ;
return V_206 ;
}
if ( V_164 & V_207 )
goto exit;
#if 0
if (irqsrc & MASK_SYS_STATUS_EOBI)
snd_printdd(LXP "interrupt: EOBI\n");
if (irqsrc & MASK_SYS_STATUS_EOBO)
snd_printdd(LXP "interrupt: EOBO\n");
if (irqsrc & MASK_SYS_STATUS_URUN)
snd_printdd(LXP "interrupt: URUN\n");
if (irqsrc & MASK_SYS_STATUS_ORUN)
snd_printdd(LXP "interrupt: ORUN\n");
#endif
if ( V_204 ) {
T_6 V_198 = 0 ;
T_6 V_199 = 0 ;
int V_208 ;
int V_89 ;
V_89 = F_56 ( V_2 , V_164 ,
& V_208 ,
& V_198 ,
& V_199 ) ;
if ( V_89 )
F_19 (KERN_ERR LXP
L_32 ) ;
V_89 = F_63 ( V_2 ,
V_198 ,
V_199
) ;
if ( V_89 )
F_19 (KERN_ERR LXP
L_33 ) ;
}
if ( V_205 ) {
#if 0
snd_printdd("lx6464es: interrupt requests escmd handling\n");
#endif
}
exit:
F_67 ( & V_2 -> V_195 ) ;
return V_209 ;
}
static void F_68 ( struct V_1 * V_2 , int V_210 )
{
T_2 V_43 = F_9 ( V_2 , V_155 ) ;
if ( V_210 )
V_43 |= ( V_211 | V_212 ) ;
else
V_43 &= ~ ( V_211 | V_212 ) ;
F_10 ( V_2 , V_155 , V_43 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_57 ( L_34 ) ;
F_68 ( V_2 , 1 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_57 ( L_35 ) ;
F_68 ( V_2 , 0 ) ;
}
