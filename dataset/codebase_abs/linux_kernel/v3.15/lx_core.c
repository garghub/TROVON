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
static void F_11 ( struct V_13 * V_14 , enum V_15 V_16 )
{
F_12 ( V_16 >= V_17 ) ;
V_14 -> V_16 [ 0 ] = V_18 [ V_16 ] . V_19 ;
V_14 -> V_20 = V_18 [ V_16 ] . V_21 ;
V_14 -> V_22 = V_18 [ V_16 ] . V_23 ;
V_14 -> V_24 = V_18 [ V_16 ] . V_25 ;
V_14 -> V_26 = V_16 ;
memset ( & V_14 -> V_16 [ 1 ] , 0 , ( V_27 - 1 ) * sizeof( T_2 ) ) ;
#ifdef F_13
memset ( V_14 -> V_28 , 0 , V_27 * sizeof( T_2 ) ) ;
#endif
#ifdef F_14
V_14 -> V_26 = V_16 ;
#endif
}
static void F_15 ( struct V_13 * V_14 )
{
T_3 V_29 = V_14 -> V_26 ;
int V_10 ;
F_16 ( V_30 L_1 , V_18 [ V_29 ] . V_31 ) ;
for ( V_10 = 0 ; V_10 != V_14 -> V_20 ; ++ V_10 )
F_16 ( V_30 L_2 , V_10 , V_14 -> V_16 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 != V_14 -> V_22 ; ++ V_10 )
F_16 ( V_30 L_3 , V_10 , V_14 -> V_28 [ V_10 ] ) ;
F_16 ( L_4 ) ;
}
static inline void F_15 ( struct V_13 * V_14 )
{}
static int F_17 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
T_2 V_32 = V_33 ;
int V_34 ;
if ( F_2 ( V_2 , V_35 ) & ( V_36 | V_37 ) ) {
F_18 ( V_2 -> V_38 -> V_39 , L_5 , V_32 ) ;
return - V_40 ;
}
F_7 ( V_2 , V_41 , V_14 -> V_16 , V_14 -> V_20 ) ;
F_5 ( V_2 , V_35 , V_36 ) ;
for ( V_34 = 0 ; V_34 != V_42 * 1000 ; ++ V_34 ) {
if ( F_2 ( V_2 , V_35 ) & V_37 ) {
if ( V_14 -> V_24 == 0 )
V_32 = F_2 ( V_2 , V_41 ) ;
else
V_32 = 0 ;
goto V_43;
} else
F_19 ( 1 ) ;
}
F_20 ( V_2 -> V_38 -> V_39 , L_6
L_7 ) ;
V_43:
if ( ( V_32 & V_44 ) == 0 ) {
if ( V_14 -> V_22 ) {
F_12 ( V_14 -> V_22 >= ( V_27 - 1 ) ) ;
F_4 ( V_2 , V_45 , V_14 -> V_28 ,
V_14 -> V_22 ) ;
}
} else
F_18 ( V_2 -> V_38 -> V_39 , L_8 , V_32 ) ;
F_5 ( V_2 , V_35 , 0 ) ;
switch ( V_32 ) {
case V_33 :
F_20 ( V_2 -> V_38 -> V_39 , L_9 ) ;
return - V_46 ;
case V_47 :
F_20 ( V_2 -> V_38 -> V_39 , L_10 ) ;
return - V_48 ;
}
F_15 ( V_14 ) ;
return V_32 ;
}
int F_21 ( struct V_1 * V_2 , T_2 * V_49 )
{
T_4 V_50 ;
unsigned long V_51 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_53 ) ;
V_50 = F_17 ( V_2 , & V_2 -> V_14 ) ;
* V_49 = V_2 -> V_14 . V_28 [ 1 ] ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_50 ;
}
int F_24 ( struct V_1 * V_2 , T_2 * V_54 )
{
T_4 V_50 = 0 ;
unsigned long V_51 ;
T_2 V_55 = 0 ;
T_2 V_56 = 0 ;
T_2 V_57 = 0 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_53 ) ;
V_50 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( V_50 == 0 ) {
V_55 = V_2 -> V_14 . V_28 [ 0 ] >> V_58 ;
V_56 = V_55 & V_59 ;
if ( ( V_56 < V_60 ) ||
( V_56 > V_61 ) )
V_57 = 0 ;
else if ( V_56 >= V_62 )
V_57 = 44100 ;
else
V_57 = 48000 ;
}
F_23 ( & V_2 -> V_52 , V_51 ) ;
* V_54 = V_57 * V_2 -> V_63 ;
return V_50 ;
}
int F_25 ( struct V_1 * V_2 )
{
T_2 V_64 , V_65 ;
V_64 = F_2 ( V_2 , V_66 ) & 0x00FFFFFF ;
V_65 = F_2 ( V_2 , V_67 ) & 0x00FFFFFF ;
V_2 -> V_68 [ 5 ] = ( ( T_3 * ) ( & V_65 ) ) [ 0 ] ;
V_2 -> V_68 [ 4 ] = ( ( T_3 * ) ( & V_65 ) ) [ 1 ] ;
V_2 -> V_68 [ 3 ] = ( ( T_3 * ) ( & V_65 ) ) [ 2 ] ;
V_2 -> V_68 [ 2 ] = ( ( T_3 * ) ( & V_64 ) ) [ 0 ] ;
V_2 -> V_68 [ 1 ] = ( ( T_3 * ) ( & V_64 ) ) [ 1 ] ;
V_2 -> V_68 [ 0 ] = ( ( T_3 * ) ( & V_64 ) ) [ 2 ] ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_69 )
{
unsigned long V_51 ;
int V_50 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_70 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_69 ;
V_50 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_50 ;
}
int F_27 ( struct V_1 * V_2 , T_2 * V_8 )
{
unsigned long V_51 ;
int V_50 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_71 ) ;
V_2 -> V_14 . V_22 = 9 ;
V_50 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( ! V_50 )
memcpy ( V_8 , V_2 -> V_14 . V_28 , V_2 -> V_14 . V_22 * sizeof( T_2 ) ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_50 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
int V_74 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_77 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_2 -> V_14 . V_16 [ 0 ] |= V_74 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
if ( V_75 != 0 )
F_18 ( V_2 -> V_38 -> V_39 , L_11 ) ;
return V_75 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_78 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
T_2 * V_79 , T_2 * V_80 , T_2 * V_81 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
#ifdef F_13
if ( V_81 )
memset ( V_81 , 0 , sizeof( T_2 ) * V_82 ) ;
#endif
* V_79 = 0 ;
* V_80 = 0 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_83 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( ! V_75 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_82 ; ++ V_10 ) {
T_2 V_28 = V_2 -> V_14 . V_28 [ V_10 ] ;
if ( V_28 & ( V_84 << V_85 ) ) {
* V_80 += 1 ;
if ( V_81 )
V_81 [ V_10 ] = V_28 & V_86 ;
} else if ( ( V_28 & ( V_87 << V_85 ) )
== 0 )
* V_79 += 1 ;
}
#if 0
dev_dbg(chip->card->dev,
"CMD_08_ASK_BUFFERS: needed %d, freed %d\n",
*r_needed, *r_freed);
for (i = 0; i < MAX_STREAM_BUFFER; ++i) {
for (i = 0; i != chip->rmh.stat_len; ++i)
dev_dbg(chip->card->dev,
" stat[%d]: %x, %x\n", i,
chip->rmh.stat[i],
chip->rmh.stat[i] & MASK_DATA_SIZE);
}
#endif
}
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_32 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_88 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
static int F_33 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_89 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
int V_75 ;
V_75 = F_35 ( V_2 , V_72 , V_73 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_33 ( V_2 , V_72 , V_73 ) ;
return V_75 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
int V_75 = 0 ;
V_75 = F_37 ( V_2 , V_72 , V_73 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_33 ( V_2 , V_72 , V_73 ) ;
return V_75 ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
T_5 * V_90 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_91 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_2 -> V_14 . V_22 = 2 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( V_75 != 0 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_12 ) ;
else {
* V_90 = ( ( T_5 ) ( V_2 -> V_14 . V_28 [ 0 ] & V_92 )
<< 24 )
+ V_2 -> V_14 . V_28 [ 1 ] ;
}
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_39 ( struct V_1 * V_2 , T_2 V_72 , int V_73 , T_4 * V_93 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_91 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( V_75 != 0 )
F_18 ( V_2 -> V_38 -> V_39 , L_13 ) ;
else
* V_93 = ( V_2 -> V_14 . V_28 [ 0 ] >> V_94 ) & 0x0F ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_72 ,
int V_73 , T_4 V_95 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 != 50 ; ++ V_10 ) {
T_4 V_96 ;
int V_75 = F_39 ( V_2 , V_72 , V_73 , & V_96 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_96 == V_95 )
return 0 ;
F_41 ( 1 ) ;
}
return - V_46 ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
return F_40 ( V_2 , V_72 , V_73 , V_97 ) ;
}
int F_35 ( struct V_1 * V_2 , T_2 V_72 , int V_73 )
{
return F_40 ( V_2 , V_72 , V_73 , V_98 ) ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_72 ,
int V_73 , enum V_99 V_95 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_100 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_2 -> V_14 . V_16 [ 0 ] |= V_95 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_43 ( struct V_1 * V_2 , struct V_101 * V_102 ,
T_2 V_72 , int V_73 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
T_2 V_74 = V_102 -> V_74 ;
if ( V_102 -> V_74 != V_74 )
F_18 ( V_2 -> V_38 -> V_39 , L_14 ,
V_102 -> V_74 , V_74 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_103 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
if ( V_102 -> V_104 == 16 )
V_2 -> V_14 . V_16 [ 0 ] |= ( V_105 << V_106 ) ;
if ( F_44 ( V_102 -> V_107 ) )
V_2 -> V_14 . V_16 [ 0 ] |= ( V_108 << V_106 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_74 - 1 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
int * V_93 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_109 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
* V_93 = ( V_2 -> V_14 . V_28 [ 0 ] & V_110 ) ? V_111 : V_112 ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_46 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
T_5 * V_113 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_109 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
* V_113 = ( ( T_5 ) ( V_2 -> V_14 . V_28 [ 0 ] & V_92 )
<< 32 )
+ V_2 -> V_14 . V_28 [ 1 ] ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_47 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
T_2 V_114 , T_2 V_115 , T_2 V_116 ,
T_2 * V_117 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_118 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_2 -> V_14 . V_16 [ 0 ] |= V_119 ;
V_2 -> V_14 . V_16 [ 1 ] = V_114 & V_86 ;
V_2 -> V_14 . V_16 [ 2 ] = V_115 ;
if ( V_116 ) {
V_2 -> V_14 . V_20 = 4 ;
V_2 -> V_14 . V_16 [ 3 ] = V_116 ;
V_2 -> V_14 . V_16 [ 0 ] |= V_120 ;
}
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( V_75 == 0 ) {
* V_117 = V_2 -> V_14 . V_28 [ 0 ] ;
goto V_121;
}
if ( V_75 == V_122 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_15 ) ;
if ( V_75 == V_123 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_16 ) ;
if ( V_75 == V_124 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_17 ) ;
V_121:
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_48 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
T_2 * V_125 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_126 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_2 -> V_14 . V_16 [ 0 ] |= V_127 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( V_75 == 0 )
* V_125 = V_2 -> V_14 . V_28 [ 0 ] & V_86 ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_49 ( struct V_1 * V_2 , T_2 V_72 , int V_73 ,
T_2 V_128 )
{
int V_75 ;
unsigned long V_51 ;
T_2 V_76 = F_29 ( V_73 , V_72 ) ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_126 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= V_76 ;
V_2 -> V_14 . V_16 [ 0 ] |= V_128 ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_50 ( struct V_1 * V_2 , int V_73 , int V_129 )
{
int V_75 ;
unsigned long V_51 ;
T_5 V_130 = V_129 ? 0 : 0xFFFFFFFFFFFFFFFFLLU ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
F_11 ( & V_2 -> V_14 , V_131 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= F_29 ( V_73 , 0 ) ;
V_2 -> V_14 . V_16 [ 1 ] = ( T_2 ) ( V_130 >> ( T_5 ) 32 ) ;
V_2 -> V_14 . V_16 [ 2 ] = ( T_2 ) ( V_130 & ( T_5 ) 0xFFFFFFFF ) ;
F_51 ( V_2 -> V_38 -> V_39 ,
L_18 , V_2 -> V_14 . V_16 [ 0 ] , V_2 -> V_14 . V_16 [ 1 ] ,
V_2 -> V_14 . V_16 [ 2 ] ) ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
int F_52 ( struct V_1 * V_2 , int V_73 , int V_74 ,
T_2 * V_132 )
{
int V_75 = 0 ;
unsigned long V_51 ;
int V_10 ;
F_22 ( & V_2 -> V_52 , V_51 ) ;
for ( V_10 = 0 ; V_10 < V_74 ; V_10 += 4 ) {
T_2 V_133 , V_134 , V_135 , V_136 ;
F_11 ( & V_2 -> V_14 , V_137 ) ;
V_2 -> V_14 . V_16 [ 0 ] |= F_29 ( V_73 , V_10 ) ;
V_75 = F_17 ( V_2 , & V_2 -> V_14 ) ;
if ( V_75 == 0 ) {
V_133 = V_138 [ V_2 -> V_14 . V_28 [ 0 ] & 0x0F ] ;
V_134 = V_138 [ ( V_2 -> V_14 . V_28 [ 0 ] >> 4 ) & 0xf ] ;
V_135 = V_138 [ ( V_2 -> V_14 . V_28 [ 0 ] >> 8 ) & 0xf ] ;
V_136 = V_138 [ ( V_2 -> V_14 . V_28 [ 0 ] >> 12 ) & 0xf ] ;
} else
V_133 = V_134 = V_135 = V_136 = 0 ;
V_132 [ 0 ] = V_133 ;
V_132 [ 1 ] = V_134 ;
V_132 [ 2 ] = V_135 ;
V_132 [ 3 ] = V_136 ;
V_132 += 4 ;
}
F_23 ( & V_2 -> V_52 , V_51 ) ;
return V_75 ;
}
static T_2 F_53 ( struct V_1 * V_2 )
{
T_2 V_139 = F_9 ( V_2 , V_140 ) ;
if ( V_139 & V_141 ) {
T_2 V_142 ;
V_139 = V_143 ;
while ( ( V_142 = F_9 ( V_2 , V_144 ) ) ) {
V_139 |= V_142 ;
F_10 ( V_2 , V_144 , V_142 ) ;
}
return V_139 ;
}
return V_143 ;
}
static int F_54 ( struct V_1 * V_2 , T_2 * V_145 ,
int * V_146 , int * V_147 )
{
T_2 V_148 ;
T_2 V_149 = F_53 ( V_2 ) ;
if ( V_149 == V_143 )
return 0 ;
* V_145 = V_149 ;
V_148 = V_149 & V_150 ;
if ( V_148 & V_151 ) {
V_148 &= ~ V_151 ;
* V_147 = 1 ;
}
if ( V_148 ) {
* V_146 = 1 ;
}
return 1 ;
}
static int F_55 ( struct V_1 * V_2 , T_2 V_149 ,
int * V_152 ,
T_5 * V_153 ,
T_5 * V_154 )
{
int V_75 ;
T_2 V_28 [ 9 ] ;
T_5 V_155 ;
T_5 V_156 ;
#if 0
int has_underrun = (irqsrc & MASK_SYS_STATUS_URUN) ? 1 : 0;
int has_overrun = (irqsrc & MASK_SYS_STATUS_ORUN) ? 1 : 0;
#endif
int V_157 = ( V_149 & V_158 ) ? 1 : 0 ;
int V_159 = ( V_149 & V_160 ) ? 1 : 0 ;
* V_152 = ( V_149 & V_161 ) ? 1 : 0 ;
V_75 = F_27 ( V_2 , V_28 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_159 ) {
* V_153 = ( ( T_5 ) V_28 [ 3 ] << 32 )
+ V_28 [ 4 ] ;
F_51 ( V_2 -> V_38 -> V_39 , L_19 ,
* V_153 ) ;
}
if ( V_157 ) {
* V_154 = ( ( T_5 ) V_28 [ 1 ] << 32 )
+ V_28 [ 2 ] ;
F_51 ( V_2 -> V_38 -> V_39 , L_20 ,
* V_154 ) ;
}
V_155 = ( ( T_5 ) V_28 [ 7 ] << 32 ) + V_28 [ 8 ] ;
V_156 = ( ( T_5 ) V_28 [ 5 ] << 32 ) + V_28 [ 6 ] ;
return V_75 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_162 * V_162 )
{
struct V_163 * V_164 = V_162 -> V_165 ;
const unsigned int V_73 = V_162 -> V_73 ;
int V_75 ;
unsigned long V_51 ;
const T_2 V_74 = V_164 -> V_102 -> V_74 ;
const T_2 V_166 = V_74 * 3 ;
const T_2 V_167 = V_164 -> V_102 -> V_167 ;
const T_2 V_168 = V_167 * V_166 ;
const T_2 V_169 = V_162 -> V_170 ;
const T_2 V_171 = ( ( V_169 + 1 ) == V_164 -> V_102 -> V_172 ) ?
0 : V_169 + 1 ;
T_6 V_173 = V_164 -> V_174 . V_175 + V_169 * V_168 ;
T_2 V_176 = 0 ;
T_2 V_177 = 0 ;
T_2 V_128 = 0 ;
T_2 V_178 , V_179 ;
T_2 V_81 [ V_82 ] ;
F_51 ( V_2 -> V_38 -> V_39 , L_21 ) ;
F_22 ( & V_2 -> V_180 , V_51 ) ;
V_75 = F_31 ( V_2 , 0 , V_73 , & V_178 , & V_179 , V_81 ) ;
F_51 ( V_2 -> V_38 -> V_39 ,
L_22 , V_178 , V_179 ) ;
F_57 ( V_173 , & V_177 , & V_176 ) ;
V_75 = F_47 ( V_2 , 0 , V_73 , V_168 , V_177 , V_176 ,
& V_128 ) ;
F_51 ( V_2 -> V_38 -> V_39 ,
L_23 ,
V_128 , ( unsigned long ) V_173 , V_168 ) ;
V_162 -> V_170 = V_171 ;
F_23 ( & V_2 -> V_180 , V_51 ) ;
return V_75 ;
}
void F_58 ( unsigned long V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
struct V_162 * V_162 = & V_2 -> V_181 ;
int V_75 ;
F_51 ( V_2 -> V_38 -> V_39 , L_24 ) ;
V_75 = F_56 ( V_2 , V_162 ) ;
if ( V_75 < 0 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_25 ) ;
F_59 ( V_162 -> V_165 ) ;
}
void F_60 ( unsigned long V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
struct V_162 * V_162 = & V_2 -> V_182 ;
int V_75 ;
F_51 ( V_2 -> V_38 -> V_39 , L_26 ) ;
V_75 = F_56 ( V_2 , V_162 ) ;
if ( V_75 < 0 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_27 ) ;
F_59 ( V_162 -> V_165 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
T_5 V_183 ,
T_5 V_184 )
{
int V_75 = 0 ;
if ( V_183 ) {
F_51 ( V_2 -> V_38 -> V_39 ,
L_28 ) ;
F_62 ( & V_2 -> V_185 ) ;
}
if ( V_184 ) {
F_51 ( V_2 -> V_38 -> V_39 ,
L_29 ) ;
F_62 ( & V_2 -> V_186 ) ;
}
return V_75 ;
}
T_7 F_63 ( int V_187 , void * V_188 )
{
struct V_1 * V_2 = V_188 ;
int V_189 , V_190 ;
T_2 V_149 ;
F_64 ( & V_2 -> V_180 ) ;
F_51 ( V_2 -> V_38 -> V_39 ,
L_30 ) ;
if ( ! F_54 ( V_2 , & V_149 , & V_189 , & V_190 ) ) {
F_65 ( & V_2 -> V_180 ) ;
F_51 ( V_2 -> V_38 -> V_39 , L_31 ) ;
return V_191 ;
}
if ( V_149 & V_192 )
goto exit;
#if 0
if (irqsrc & MASK_SYS_STATUS_EOBI)
dev_dgg(chip->card->dev, "interrupt: EOBI\n");
if (irqsrc & MASK_SYS_STATUS_EOBO)
dev_dbg(chip->card->dev, "interrupt: EOBO\n");
if (irqsrc & MASK_SYS_STATUS_URUN)
dev_dbg(chip->card->dev, "interrupt: URUN\n");
if (irqsrc & MASK_SYS_STATUS_ORUN)
dev_dbg(chip->card->dev, "interrupt: ORUN\n");
#endif
if ( V_189 ) {
T_5 V_183 = 0 ;
T_5 V_184 = 0 ;
int V_193 ;
int V_75 ;
V_75 = F_55 ( V_2 , V_149 ,
& V_193 ,
& V_183 ,
& V_184 ) ;
if ( V_75 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_32 ) ;
V_75 = F_61 ( V_2 ,
V_183 ,
V_184
) ;
if ( V_75 )
F_18 ( V_2 -> V_38 -> V_39 ,
L_33 ) ;
}
if ( V_190 ) {
#if 0
dev_dbg(chip->card->dev, "interrupt requests escmd handling\n");
#endif
}
exit:
F_65 ( & V_2 -> V_180 ) ;
return V_194 ;
}
static void F_66 ( struct V_1 * V_2 , int V_195 )
{
T_2 V_32 = F_9 ( V_2 , V_140 ) ;
if ( V_195 )
V_32 |= ( V_196 | V_197 ) ;
else
V_32 &= ~ ( V_196 | V_197 ) ;
F_10 ( V_2 , V_140 , V_32 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_38 -> V_39 , L_34 ) ;
F_66 ( V_2 , 1 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_38 -> V_39 , L_35 ) ;
F_66 ( V_2 , 0 ) ;
}
