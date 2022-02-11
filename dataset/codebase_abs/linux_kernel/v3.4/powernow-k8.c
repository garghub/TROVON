static inline const struct V_1 * F_1 ( int V_2 )
{
return F_2 ( 0 ) ;
}
static T_1 F_3 ( T_1 V_3 )
{
return 800 + ( V_3 * 100 ) ;
}
static T_1 F_4 ( T_1 V_3 )
{
return 1000 * F_3 ( V_3 ) ;
}
static T_1 F_5 ( struct V_4 * V_5 ,
T_1 V_6 )
{
return V_5 [ V_7 [ V_6 ] ] . V_8 ;
}
static T_1 F_6 ( T_1 V_3 )
{
if ( V_3 < V_9 )
return 8 + ( 2 * V_3 ) ;
else
return V_3 ;
}
static int F_7 ( void )
{
T_1 V_10 , V_11 ;
if ( V_12 == V_13 )
return 0 ;
F_8 ( V_14 , V_10 , V_11 ) ;
return V_10 & V_15 ? 1 : 0 ;
}
static int F_9 ( struct V_16 * V_5 )
{
T_1 V_10 , V_11 ;
T_1 V_17 = 0 ;
if ( V_12 == V_13 ) {
F_8 ( V_18 , V_10 , V_11 ) ;
V_17 = V_10 & V_19 ;
V_5 -> V_20 = V_17 ;
if ( ( V_21 . V_22 == 0x11 ) && ( V_17 >= V_5 -> V_23 ) )
V_5 -> V_20 = V_24 ;
return 0 ;
}
do {
if ( V_17 ++ > 10000 ) {
F_10 ( L_1 ) ;
return 1 ;
}
F_8 ( V_14 , V_10 , V_11 ) ;
} while ( V_10 & V_15 );
V_5 -> V_25 = V_11 & V_26 ;
V_5 -> V_27 = V_10 & V_28 ;
return 0 ;
}
static void F_11 ( struct V_16 * V_5 )
{
F_12 ( ( 1 << V_5 -> V_29 ) * 10 ) ;
return;
}
static void F_13 ( struct V_16 * V_5 )
{
F_12 ( V_5 -> V_30 * V_31 ) ;
return;
}
static void F_14 ( void )
{
T_1 V_10 , V_11 ;
T_2 V_3 , V_32 ;
F_8 ( V_14 , V_10 , V_11 ) ;
V_32 = V_11 & V_26 ;
V_3 = V_10 & V_28 ;
V_10 = V_3 | ( V_32 << V_33 ) ;
V_11 = V_34 ;
F_10 ( L_2 , F_15 () , V_10 , V_11 ) ;
F_16 ( V_35 , V_10 , V_11 ) ;
}
static int F_17 ( struct V_16 * V_5 , T_1 V_3 )
{
T_1 V_10 ;
T_1 V_36 = V_5 -> V_25 ;
T_1 V_17 = 0 ;
if ( ( V_3 & V_37 ) || ( V_5 -> V_25 & V_38 ) ) {
F_18 (KERN_ERR PFX L_3 ) ;
return 1 ;
}
V_10 = V_3 ;
V_10 |= ( V_5 -> V_25 << V_33 ) ;
V_10 |= V_39 ;
F_10 ( L_4 ,
V_3 , V_10 , V_5 -> V_40 * V_41 ) ;
do {
F_16 ( V_35 , V_10 , V_5 -> V_40 * V_41 ) ;
if ( V_17 ++ > 100 ) {
F_18 (KERN_ERR PFX
L_5
L_6 ) ;
return 1 ;
}
} while ( F_9 ( V_5 ) );
F_11 ( V_5 ) ;
if ( V_36 != V_5 -> V_25 ) {
F_18 (KERN_ERR PFX
L_7 ,
savevid, data->currvid) ;
return 1 ;
}
if ( V_3 != V_5 -> V_27 ) {
F_18 (KERN_ERR PFX
L_8 , fid,
data->currfid) ;
return 1 ;
}
return 0 ;
}
static int F_19 ( struct V_16 * V_5 , T_1 V_32 )
{
T_1 V_10 ;
T_1 V_42 = V_5 -> V_27 ;
int V_17 = 0 ;
if ( ( V_5 -> V_27 & V_37 ) || ( V_32 & V_38 ) ) {
F_18 (KERN_ERR PFX L_9 ) ;
return 1 ;
}
V_10 = V_5 -> V_27 ;
V_10 |= ( V_32 << V_33 ) ;
V_10 |= V_39 ;
F_10 ( L_10 ,
V_32 , V_10 , V_43 ) ;
do {
F_16 ( V_35 , V_10 , V_43 ) ;
if ( V_17 ++ > 100 ) {
F_18 (KERN_ERR PFX L_11
L_12
L_13 ) ;
return 1 ;
}
} while ( F_9 ( V_5 ) );
if ( V_42 != V_5 -> V_27 ) {
F_18 (KERN_ERR PFX L_14
L_15 ,
savefid, data->currfid) ;
return 1 ;
}
if ( V_32 != V_5 -> V_25 ) {
F_18 (KERN_ERR PFX L_16
L_17 ,
vid, data->currvid) ;
return 1 ;
}
return 0 ;
}
static int F_20 ( struct V_16 * V_5 ,
T_1 V_44 , T_1 V_45 )
{
if ( ( V_5 -> V_25 - V_44 ) > V_45 )
V_44 = V_5 -> V_25 - V_45 ;
if ( F_19 ( V_5 , V_44 ) )
return 1 ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_5 , T_1 V_6 )
{
F_16 ( V_46 , V_6 , 0 ) ;
V_5 -> V_20 = V_6 ;
return 0 ;
}
static int F_22 ( struct V_16 * V_5 ,
T_1 V_47 , T_1 V_44 )
{
if ( F_23 ( V_5 , V_44 , V_47 ) )
return 1 ;
if ( F_24 ( V_5 , V_47 ) )
return 1 ;
if ( F_25 ( V_5 , V_44 ) )
return 1 ;
if ( F_9 ( V_5 ) )
return 1 ;
if ( ( V_47 != V_5 -> V_27 ) || ( V_44 != V_5 -> V_25 ) ) {
F_18 (KERN_ERR PFX L_18
L_19 ,
smp_processor_id(),
reqfid, reqvid, data->currfid, data->currvid) ;
return 1 ;
}
F_10 ( L_20 ,
F_15 () , V_5 -> V_27 , V_5 -> V_25 ) ;
return 0 ;
}
static int F_23 ( struct V_16 * V_5 ,
T_1 V_44 , T_1 V_47 )
{
T_1 V_48 = V_5 -> V_49 ;
T_1 V_42 = V_5 -> V_27 ;
T_1 V_50 , V_10 , V_51 = 1 ;
F_10 ( L_21
L_22 ,
F_15 () ,
V_5 -> V_27 , V_5 -> V_25 , V_44 , V_5 -> V_49 ) ;
if ( ( V_42 < V_52 ) && ( V_47 < V_52 ) )
V_51 = 2 ;
V_48 *= V_51 ;
F_8 ( V_14 , V_10 , V_50 ) ;
V_50 = 0x1f & ( V_50 >> 16 ) ;
F_10 ( L_23 , V_50 ) ;
if ( V_44 < V_50 )
V_44 = V_50 ;
while ( V_5 -> V_25 > V_44 ) {
F_10 ( L_24 ,
V_5 -> V_25 , V_44 ) ;
if ( F_20 ( V_5 , V_44 , V_5 -> V_53 ) )
return 1 ;
}
while ( ( V_48 > 0 ) &&
( ( V_51 * V_5 -> V_49 + V_5 -> V_25 ) > V_44 ) ) {
if ( V_5 -> V_25 == V_50 ) {
V_48 = 0 ;
} else {
F_10 ( L_25 ,
V_5 -> V_25 - 1 ) ;
if ( F_20 ( V_5 , V_5 -> V_25 - 1 , 1 ) )
return 1 ;
V_48 -- ;
}
}
if ( F_9 ( V_5 ) )
return 1 ;
if ( V_42 != V_5 -> V_27 ) {
F_18 (KERN_ERR PFX L_26 ,
data->currfid) ;
return 1 ;
}
F_10 ( L_27 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
return 0 ;
}
static int F_24 ( struct V_16 * V_5 , T_1 V_47 )
{
T_1 V_54 , V_55 , V_56 ;
T_1 V_57 , V_36 = V_5 -> V_25 ;
if ( V_5 -> V_27 == V_47 ) {
F_18 (KERN_ERR PFX L_28 ,
data->currfid) ;
return 0 ;
}
F_10 ( L_29
L_30 ,
F_15 () ,
V_5 -> V_27 , V_5 -> V_25 , V_47 ) ;
V_54 = F_6 ( V_47 ) ;
V_55 = F_6 ( V_5 -> V_27 ) ;
V_56 = V_55 > V_54 ? V_55 - V_54
: V_54 - V_55 ;
if ( ( V_47 <= V_52 ) && ( V_5 -> V_27 <= V_52 ) )
V_56 = 0 ;
while ( V_56 > 2 ) {
( V_5 -> V_27 & 1 ) ? ( V_57 = 1 ) : ( V_57 = 2 ) ;
if ( V_47 > V_5 -> V_27 ) {
if ( V_5 -> V_27 > V_52 ) {
if ( F_17 ( V_5 ,
V_5 -> V_27 + V_57 ) )
return 1 ;
} else {
if ( F_17
( V_5 ,
2 + F_6 ( V_5 -> V_27 ) ) )
return 1 ;
}
} else {
if ( F_17 ( V_5 , V_5 -> V_27 - V_57 ) )
return 1 ;
}
V_55 = F_6 ( V_5 -> V_27 ) ;
V_56 = V_55 > V_54 ? V_55 - V_54
: V_54 - V_55 ;
}
if ( F_17 ( V_5 , V_47 ) )
return 1 ;
if ( F_9 ( V_5 ) )
return 1 ;
if ( V_5 -> V_27 != V_47 ) {
F_18 (KERN_ERR PFX
L_31
L_32 ,
data->currfid, reqfid) ;
return 1 ;
}
if ( V_36 != V_5 -> V_25 ) {
F_18 (KERN_ERR PFX L_33 ,
savevid, data->currvid) ;
return 1 ;
}
F_10 ( L_34 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_5 ,
T_1 V_44 )
{
T_1 V_42 = V_5 -> V_27 ;
T_1 V_58 = V_44 ;
F_10 ( L_35 ,
F_15 () ,
V_5 -> V_27 , V_5 -> V_25 ) ;
if ( V_44 != V_5 -> V_25 ) {
if ( F_19 ( V_5 , V_44 ) )
return 1 ;
if ( V_42 != V_5 -> V_27 ) {
F_18 (KERN_ERR PFX
L_36 ,
savefid, data->currfid) ;
return 1 ;
}
if ( V_5 -> V_25 != V_44 ) {
F_18 (KERN_ERR PFX
L_37
L_38 ,
reqvid, data->currvid) ;
return 1 ;
}
}
if ( F_9 ( V_5 ) )
return 1 ;
if ( V_58 != V_5 -> V_25 ) {
F_10 ( L_39 , V_5 -> V_25 ) ;
return 1 ;
}
if ( V_42 != V_5 -> V_27 ) {
F_10 ( L_40 ,
V_5 -> V_27 ) ;
return 1 ;
}
F_10 ( L_41 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
return 0 ;
}
static void F_26 ( void * V_59 )
{
T_1 V_60 , V_61 , V_62 , V_63 ;
int * V_64 = V_59 ;
* V_64 = - V_65 ;
V_60 = F_27 ( V_66 ) ;
if ( ( V_60 & V_67 ) == V_68 ) {
if ( ( ( V_60 & V_69 ) != V_69 ) ||
( ( V_60 & V_70 ) > V_71 ) ) {
F_18 (KERN_INFO PFX
L_42 , eax) ;
return;
}
V_60 = F_27 ( V_72 ) ;
if ( V_60 < V_73 ) {
F_18 (KERN_INFO PFX
L_43 ) ;
return;
}
F_28 ( V_73 , & V_60 , & V_61 , & V_62 , & V_63 ) ;
if ( ( V_63 & V_74 )
!= V_74 ) {
F_18 (KERN_INFO PFX
L_44 ) ;
return;
}
} else {
F_28 ( V_73 , & V_60 , & V_61 , & V_62 , & V_63 ) ;
if ( ( V_63 & V_75 ) == V_75 )
V_12 = V_13 ;
else
return;
}
* V_64 = 0 ;
}
static int F_29 ( struct V_16 * V_5 , struct V_76 * V_77 ,
T_2 V_50 )
{
unsigned int V_78 ;
T_2 V_79 = 0xff ;
for ( V_78 = 0 ; V_78 < V_5 -> V_23 ; V_78 ++ ) {
if ( V_77 [ V_78 ] . V_32 > V_80 ) {
F_18 (KERN_ERR FW_BUG PFX L_45 ,
j, pst[j].vid) ;
return - V_81 ;
}
if ( V_77 [ V_78 ] . V_32 < V_5 -> V_49 ) {
F_18 (KERN_ERR FW_BUG PFX L_46
L_47 , j) ;
return - V_65 ;
}
if ( V_77 [ V_78 ] . V_32 < V_50 + V_5 -> V_49 ) {
F_18 (KERN_ERR FW_BUG PFX L_48
L_47 , j) ;
return - V_65 ;
}
if ( V_77 [ V_78 ] . V_3 > V_82 ) {
F_18 (KERN_ERR FW_BUG PFX L_49
L_47 , j) ;
return - V_65 ;
}
if ( V_78 && ( V_77 [ V_78 ] . V_3 < V_9 ) ) {
F_18 (KERN_ERR FW_BUG PFX L_50
L_51 , j, pst[j].fid) ;
return - V_81 ;
}
if ( V_77 [ V_78 ] . V_3 < V_79 )
V_79 = V_77 [ V_78 ] . V_3 ;
}
if ( V_79 & 1 ) {
F_18 (KERN_ERR FW_BUG PFX L_52 ) ;
return - V_81 ;
}
if ( V_79 > V_52 )
F_18 (KERN_INFO FW_BUG PFX
L_53 ) ;
return 0 ;
}
static void F_30 ( struct V_4 * V_83 ,
unsigned int V_84 )
{
V_83 [ V_84 ] . V_8 = V_85 ;
}
static void F_31 ( struct V_16 * V_5 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_5 -> V_23 ; V_78 ++ ) {
if ( V_5 -> V_83 [ V_78 ] . V_8 !=
V_85 ) {
if ( V_12 == V_13 ) {
F_18 (KERN_INFO PFX
L_54 , j,
data->powernow_table[j].index,
data->powernow_table[j].frequency/1000 ) ;
} else {
F_18 (KERN_INFO PFX
L_55 ,
data->powernow_table[j].index & 0xff ,
data->powernow_table[j].frequency/1000 ,
data->powernow_table[j].index >> 8 ) ;
}
}
}
if ( V_5 -> V_86 )
F_18 (KERN_INFO PFX L_56 ,
data->batps) ;
}
static T_1 F_32 ( T_1 V_3 , T_1 V_87 )
{
T_1 V_88 = 0 ;
if ( V_21 . V_22 == 0x10 )
V_88 = ( 100 * ( V_3 + 0x10 ) ) >> V_87 ;
else if ( V_21 . V_22 == 0x11 )
V_88 = ( 100 * ( V_3 + 8 ) ) >> V_87 ;
else
F_33 () ;
return V_88 * 1000 ;
}
static int F_34 ( struct V_16 * V_5 ,
struct V_76 * V_77 , T_2 V_50 )
{
struct V_4 * V_83 ;
unsigned int V_78 ;
if ( V_5 -> V_86 ) {
F_18 (KERN_WARNING PFX
L_57
L_58 , data->batps) ;
V_5 -> V_23 = V_5 -> V_86 ;
}
for ( V_78 = 1 ; V_78 < V_5 -> V_23 ; V_78 ++ ) {
if ( V_77 [ V_78 - 1 ] . V_3 >= V_77 [ V_78 ] . V_3 ) {
F_18 (KERN_ERR PFX L_59 ) ;
return - V_81 ;
}
}
if ( V_5 -> V_23 < 2 ) {
F_18 (KERN_ERR PFX L_60 ) ;
return - V_65 ;
}
if ( F_29 ( V_5 , V_77 , V_50 ) )
return - V_81 ;
V_83 = F_35 ( ( sizeof( struct V_4 )
* ( V_5 -> V_23 + 1 ) ) , V_89 ) ;
if ( ! V_83 ) {
F_18 (KERN_ERR PFX L_61 ) ;
return - V_90 ;
}
for ( V_78 = 0 ; V_78 < V_5 -> V_23 ; V_78 ++ ) {
int V_91 ;
V_83 [ V_78 ] . V_92 = V_77 [ V_78 ] . V_3 ;
V_83 [ V_78 ] . V_92 |= ( V_77 [ V_78 ] . V_32 << 8 ) ;
V_91 = F_4 ( V_77 [ V_78 ] . V_3 ) ;
V_83 [ V_78 ] . V_8 = V_91 ;
}
V_83 [ V_5 -> V_23 ] . V_8 = V_93 ;
V_83 [ V_5 -> V_23 ] . V_92 = 0 ;
if ( F_9 ( V_5 ) ) {
F_36 ( V_83 ) ;
return - V_94 ;
}
F_10 ( L_62 , V_5 -> V_27 , V_5 -> V_25 ) ;
V_5 -> V_83 = V_83 ;
if ( F_37 ( F_1 ( V_5 -> V_2 ) ) == V_5 -> V_2 )
F_31 ( V_5 ) ;
for ( V_78 = 0 ; V_78 < V_5 -> V_23 ; V_78 ++ )
if ( ( V_77 [ V_78 ] . V_3 == V_5 -> V_27 ) &&
( V_77 [ V_78 ] . V_32 == V_5 -> V_25 ) )
return 0 ;
F_10 ( L_63 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_5 )
{
struct V_95 * V_96 ;
unsigned int V_17 ;
T_1 V_97 ;
T_2 V_50 ;
T_1 V_98 = 0 ;
T_1 V_99 ;
for ( V_17 = 0xc0000 ; V_17 < 0xffff0 ; V_17 += 0x10 ) {
V_96 = F_39 ( V_17 ) ;
if ( memcmp ( V_96 , V_100 , V_101 ) != 0 )
continue;
F_10 ( L_64 , V_96 ) ;
F_10 ( L_65 , V_96 -> V_102 ) ;
if ( V_96 -> V_102 != V_103 ) {
F_18 (KERN_ERR FW_BUG PFX L_66 ) ;
return - V_65 ;
}
F_10 ( L_67 , V_96 -> V_104 ) ;
if ( V_96 -> V_104 ) {
F_18 (KERN_ERR FW_BUG PFX L_68 ) ;
return - V_65 ;
}
V_5 -> V_30 = V_96 -> V_30 ;
F_10 ( L_69 ,
V_5 -> V_30 ) ;
F_10 ( L_70 , V_96 -> V_105 ) ;
V_5 -> V_49 = V_96 -> V_105 & 3 ;
V_5 -> V_29 = ( ( V_96 -> V_105 ) >> 2 ) & 3 ;
V_97 = ( ( V_96 -> V_105 ) >> 4 ) & 3 ;
V_5 -> V_53 = 1 << V_97 ;
V_5 -> V_86 = ( ( V_96 -> V_105 ) >> 6 ) & 3 ;
F_10 ( L_71 , V_5 -> V_49 ) ;
F_10 ( L_72 , V_5 -> V_29 ) ;
F_10 ( L_73 , V_97 , V_5 -> V_53 ) ;
F_10 ( L_74 , V_96 -> V_106 ) ;
V_98 = V_96 -> V_106 ;
if ( ( V_96 -> F_28 == 0x00000fc0 ) ||
( V_96 -> F_28 == 0x00000fe0 ) ) {
V_99 = F_27 ( V_66 ) ;
if ( ( V_99 == 0x00000fc0 ) ||
( V_99 == 0x00000fe0 ) )
V_98 = 1 ;
}
if ( V_98 != 1 ) {
F_18 (KERN_ERR FW_BUG PFX L_75 ) ;
return - V_65 ;
}
V_5 -> V_40 = V_96 -> V_107 ;
F_10 ( L_76 , V_96 -> V_107 ) ;
F_10 ( L_77 , V_96 -> V_108 ) ;
F_10 ( L_78 , V_96 -> V_50 ) ;
V_50 = V_96 -> V_50 ;
V_5 -> V_23 = V_96 -> V_23 ;
F_10 ( L_79 , V_5 -> V_23 ) ;
return F_34 ( V_5 ,
(struct V_76 * ) ( V_96 + 1 ) , V_50 ) ;
}
F_18 (KERN_ERR FW_BUG PFX L_80 ) ;
F_18 (KERN_ERR PFX L_81
L_82 ) ;
return - V_65 ;
}
static void F_40 ( struct V_16 * V_5 ,
unsigned int V_92 )
{
T_3 V_109 ;
if ( ! V_5 -> V_110 . V_111 || ( V_12 == V_13 ) )
return;
V_109 = V_5 -> V_110 . V_112 [ V_92 ] . V_109 ;
V_5 -> V_29 = ( V_109 >> V_113 ) & V_114 ;
V_5 -> V_49 = ( V_109 >> V_115 ) & V_116 ;
V_5 -> V_117 = ( V_109 >> V_118 ) & V_119 ;
V_5 -> V_40 = ( V_109 >> V_120 ) & V_121 ;
V_5 -> V_53 = 1 << ( ( V_109 >> V_122 ) & V_123 ) ;
V_5 -> V_30 = ( V_109 >> V_124 ) & V_125 ;
}
static int F_41 ( struct V_16 * V_5 )
{
struct V_4 * V_83 ;
int V_126 = - V_65 ;
T_3 V_109 , V_127 ;
if ( F_42 ( & V_5 -> V_110 , V_5 -> V_2 ) ) {
F_10 ( L_83 ) ;
return - V_94 ;
}
if ( V_5 -> V_110 . V_111 <= 1 ) {
F_10 ( L_84 ) ;
goto V_128;
}
V_109 = V_5 -> V_110 . V_129 . V_130 ;
V_127 = V_5 -> V_110 . V_131 . V_130 ;
if ( ( V_109 != V_132 ) ||
( V_127 != V_132 ) ) {
F_10 ( L_85 ,
V_109 , V_127 ) ;
goto V_128;
}
V_83 = F_35 ( ( sizeof( struct V_4 )
* ( V_5 -> V_110 . V_111 + 1 ) ) , V_89 ) ;
if ( ! V_83 ) {
F_10 ( L_61 ) ;
goto V_128;
}
V_5 -> V_23 = V_5 -> V_110 . V_111 ;
F_40 ( V_5 , 0 ) ;
if ( V_12 == V_13 )
V_126 = F_43 ( V_5 , V_83 ) ;
else
V_126 = F_44 ( V_5 , V_83 ) ;
if ( V_126 )
goto V_133;
V_83 [ V_5 -> V_110 . V_111 ] . V_8 =
V_93 ;
V_83 [ V_5 -> V_110 . V_111 ] . V_92 = 0 ;
V_5 -> V_83 = V_83 ;
if ( F_37 ( F_1 ( V_5 -> V_2 ) ) == V_5 -> V_2 )
F_31 ( V_5 ) ;
F_45 ( V_134 ) ;
if ( ! F_46 ( & V_5 -> V_110 . V_135 , V_89 ) ) {
F_18 (KERN_ERR PFX
L_86 ) ;
V_126 = - V_90 ;
goto V_133;
}
return 0 ;
V_133:
F_36 ( V_83 ) ;
V_128:
F_47 ( & V_5 -> V_110 , V_5 -> V_2 ) ;
V_5 -> V_110 . V_111 = 0 ;
return V_126 ;
}
static int F_43 ( struct V_16 * V_5 ,
struct V_4 * V_83 )
{
int V_17 ;
T_1 V_11 = 0 , V_10 = 0 ;
F_8 ( V_136 , V_10 , V_11 ) ;
V_5 -> V_137 = ( V_10 & V_138 ) >> V_139 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_110 . V_111 ; V_17 ++ ) {
T_1 V_92 ;
V_92 = V_5 -> V_110 . V_112 [ V_17 ] . V_109 & V_19 ;
if ( V_92 > V_5 -> V_137 ) {
F_18 (KERN_ERR PFX L_87
L_88 , i, index) ;
F_18 (KERN_ERR PFX L_89
L_90 ) ;
F_30 ( V_83 , V_17 ) ;
continue;
}
V_7 [ V_92 ] = V_17 ;
if ( ( V_21 . V_22 == 0x10 && V_21 . V_140 < 10 )
|| V_21 . V_22 == 0x11 ) {
F_8 ( V_141 + V_92 , V_10 , V_11 ) ;
if ( ! ( V_11 & V_142 ) ) {
F_10 ( L_91 , V_92 ) ;
F_30 ( V_83 , V_17 ) ;
continue;
}
V_83 [ V_17 ] . V_8 =
F_32 ( V_10 & 0x3f , ( V_10 >> 6 ) & 7 ) ;
} else
V_83 [ V_17 ] . V_8 =
V_5 -> V_110 . V_112 [ V_17 ] . V_143 * 1000 ;
V_83 [ V_17 ] . V_92 = V_92 ;
}
return 0 ;
}
static int F_44 ( struct V_16 * V_5 ,
struct V_4 * V_83 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_110 . V_111 ; V_17 ++ ) {
T_1 V_3 ;
T_1 V_32 ;
T_1 V_91 , V_92 ;
T_3 V_127 , V_109 ;
if ( V_5 -> V_117 ) {
V_127 = V_5 -> V_110 . V_112 [ V_17 ] . V_127 ;
V_3 = V_127 & V_144 ;
V_32 = ( V_127 >> V_145 ) & V_146 ;
} else {
V_109 = V_5 -> V_110 . V_112 [ V_17 ] . V_109 ;
V_3 = V_109 & V_147 ;
V_32 = ( V_109 >> V_145 ) & V_148 ;
}
F_10 ( L_92 , V_17 , V_3 , V_32 ) ;
V_92 = V_3 | ( V_32 << 8 ) ;
V_83 [ V_17 ] . V_92 = V_92 ;
V_91 = F_4 ( V_3 ) ;
V_83 [ V_17 ] . V_8 = V_91 ;
if ( ( V_91 > ( V_149 * 1000 ) ) || ( V_91 < ( V_150 * 1000 ) ) ) {
F_10 ( L_93 , V_91 ) ;
F_30 ( V_83 , V_17 ) ;
continue;
}
if ( V_32 == V_151 ) {
F_10 ( L_94 , V_32 ) ;
F_30 ( V_83 , V_17 ) ;
continue;
}
if ( V_91 != ( V_5 -> V_110 . V_112 [ V_17 ] . V_143 * 1000 ) ) {
F_18 (KERN_INFO PFX L_95
L_96 , freq,
(unsigned int)
(data->acpi_data.states[i].core_frequency
* 1000)) ;
F_30 ( V_83 , V_17 ) ;
continue;
}
}
return 0 ;
}
static void F_48 ( struct V_16 * V_5 )
{
if ( V_5 -> V_110 . V_111 )
F_47 ( & V_5 -> V_110 ,
V_5 -> V_2 ) ;
F_49 ( V_5 -> V_110 . V_135 ) ;
}
static int F_50 ( struct V_16 * V_5 )
{
int V_152 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_110 . V_111 ; V_17 ++ ) {
int V_153 = V_5 -> V_110 . V_112 [ V_17 ] . V_154
+ V_5 -> V_110 . V_112 [ V_17 ] . V_155 ;
if ( V_153 > V_152 )
V_152 = V_153 ;
}
if ( V_152 == 0 ) {
if ( V_21 . V_22 < 0x11 )
F_18 (KERN_ERR FW_WARN PFX L_97
L_98 ) ;
V_152 = 1 ;
}
return 1000 * V_152 ;
}
static int F_51 ( struct V_16 * V_5 ,
unsigned int V_92 )
{
T_1 V_3 = 0 ;
T_1 V_32 = 0 ;
int V_156 , V_17 ;
struct V_157 V_158 ;
F_10 ( L_99 , F_15 () , V_92 ) ;
V_3 = V_5 -> V_83 [ V_92 ] . V_92 & 0xFF ;
V_32 = ( V_5 -> V_83 [ V_92 ] . V_92 & 0xFF00 ) >> 8 ;
F_10 ( L_100 , V_3 , V_32 ) ;
if ( F_9 ( V_5 ) )
return 1 ;
if ( ( V_5 -> V_25 == V_32 ) && ( V_5 -> V_27 == V_3 ) ) {
F_10 ( L_101 ,
V_3 , V_32 ) ;
return 0 ;
}
F_10 ( L_102 ,
F_15 () , V_3 , V_32 ) ;
V_158 . V_159 = F_4 ( V_5 -> V_27 ) ;
V_158 . V_160 = F_4 ( V_3 ) ;
F_52 (i, data->available_cores) {
V_158 . V_2 = V_17 ;
F_53 ( & V_158 , V_161 ) ;
}
V_156 = F_22 ( V_5 , V_3 , V_32 ) ;
if ( V_156 )
return V_156 ;
V_158 . V_160 = F_4 ( V_5 -> V_27 ) ;
F_52 (i, data->available_cores) {
V_158 . V_2 = V_17 ;
F_53 ( & V_158 , V_162 ) ;
}
return V_156 ;
}
static int F_54 ( struct V_16 * V_5 ,
unsigned int V_92 )
{
T_1 V_6 = 0 ;
int V_156 , V_17 ;
struct V_157 V_158 ;
F_10 ( L_99 , F_15 () , V_92 ) ;
V_6 = V_92 & V_19 ;
if ( V_6 > V_5 -> V_137 )
return - V_81 ;
V_158 . V_159 = F_5 ( V_5 -> V_83 ,
V_5 -> V_20 ) ;
V_158 . V_160 = F_5 ( V_5 -> V_83 , V_6 ) ;
F_52 (i, data->available_cores) {
V_158 . V_2 = V_17 ;
F_53 ( & V_158 , V_161 ) ;
}
V_156 = F_21 ( V_5 , V_6 ) ;
V_158 . V_160 = F_5 ( V_5 -> V_83 , V_6 ) ;
F_52 (i, data->available_cores) {
V_158 . V_2 = V_17 ;
F_53 ( & V_158 , V_162 ) ;
}
return V_156 ;
}
static int F_55 ( struct V_163 * V_164 ,
unsigned V_165 , unsigned V_166 )
{
T_4 V_167 ;
struct V_16 * V_5 = F_56 ( V_168 , V_164 -> V_2 ) ;
T_1 V_169 ;
T_1 V_170 ;
unsigned int V_171 ;
int V_172 = - V_94 ;
if ( ! V_5 )
return - V_81 ;
V_169 = V_5 -> V_27 ;
V_170 = V_5 -> V_25 ;
if ( ! F_57 ( & V_167 , V_89 ) )
return - V_90 ;
F_58 ( V_167 , F_59 ( V_173 ) ) ;
F_60 ( V_173 , F_2 ( V_164 -> V_2 ) ) ;
if ( F_15 () != V_164 -> V_2 ) {
F_18 (KERN_ERR PFX L_103 , pol->cpu) ;
goto V_128;
}
if ( F_7 () ) {
F_18 (KERN_ERR PFX L_104 ) ;
goto V_128;
}
F_10 ( L_105 ,
V_164 -> V_2 , V_165 , V_164 -> V_174 , V_164 -> V_175 , V_166 ) ;
if ( F_9 ( V_5 ) )
goto V_128;
if ( V_12 != V_13 ) {
F_10 ( L_106 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
if ( ( V_170 != V_5 -> V_25 ) ||
( V_169 != V_5 -> V_27 ) ) {
F_18 (KERN_INFO PFX
L_107
L_108 ,
checkfid, data->currfid,
checkvid, data->currvid) ;
}
}
if ( F_61 ( V_164 , V_5 -> V_83 ,
V_165 , V_166 , & V_171 ) )
goto V_128;
F_62 ( & V_176 ) ;
F_40 ( V_5 , V_171 ) ;
if ( V_12 == V_13 )
V_172 = F_54 ( V_5 ,
V_5 -> V_83 [ V_171 ] . V_92 ) ;
else
V_172 = F_51 ( V_5 , V_171 ) ;
if ( V_172 ) {
F_18 (KERN_ERR PFX L_109 ) ;
V_172 = 1 ;
F_63 ( & V_176 ) ;
goto V_128;
}
F_63 ( & V_176 ) ;
if ( V_12 == V_13 )
V_164 -> V_177 = F_5 ( V_5 -> V_83 ,
V_5 -> V_83 [ V_171 ] . V_92 ) ;
else
V_164 -> V_177 = F_4 ( V_5 -> V_27 ) ;
V_172 = 0 ;
V_128:
F_60 ( V_173 , V_167 ) ;
F_49 ( V_167 ) ;
return V_172 ;
}
static int F_64 ( struct V_163 * V_164 )
{
struct V_16 * V_5 = F_56 ( V_168 , V_164 -> V_2 ) ;
if ( ! V_5 )
return - V_81 ;
return F_65 ( V_164 , V_5 -> V_83 ) ;
}
static void T_5 F_66 ( void * V_178 )
{
struct V_179 * V_179 = V_178 ;
if ( F_7 () ) {
F_18 (KERN_ERR PFX L_110 ) ;
V_179 -> V_64 = - V_65 ;
return;
}
if ( F_9 ( V_179 -> V_5 ) ) {
V_179 -> V_64 = - V_65 ;
return;
}
if ( V_12 == V_180 )
F_14 () ;
V_179 -> V_64 = 0 ;
}
static int T_5 F_67 ( struct V_163 * V_164 )
{
static const char V_181 [] =
V_182 V_183 V_184 L_111
V_183 V_184 L_112 ;
struct V_16 * V_5 ;
struct V_179 V_179 ;
int V_64 ;
struct V_185 * V_186 = & F_68 ( V_164 -> V_2 ) ;
if ( ! F_69 ( V_164 -> V_2 ) )
return - V_65 ;
F_70 ( V_164 -> V_2 , F_26 , & V_64 , 1 ) ;
if ( V_64 )
return - V_65 ;
V_5 = F_71 ( sizeof( struct V_16 ) , V_89 ) ;
if ( ! V_5 ) {
F_18 (KERN_ERR PFX L_113 ) ;
return - V_90 ;
}
V_5 -> V_2 = V_164 -> V_2 ;
V_5 -> V_20 = V_187 ;
if ( F_41 ( V_5 ) ) {
if ( F_72 () != 1 ) {
F_73 ( V_181 ) ;
goto V_128;
}
if ( V_164 -> V_2 != 0 ) {
F_18 (KERN_ERR FW_BUG PFX L_114
L_115
L_116 ) ;
goto V_128;
}
V_64 = F_38 ( V_5 ) ;
if ( V_64 )
goto V_128;
V_164 -> V_188 . V_154 = (
( ( V_5 -> V_49 + 8 ) * V_5 -> V_30 * V_31 ) +
( ( 1 << V_5 -> V_29 ) * 30 ) ) * 1000 ;
} else
V_164 -> V_188 . V_154 = F_50 ( V_5 ) ;
V_179 . V_5 = V_5 ;
F_70 ( V_5 -> V_2 , F_66 ,
& V_179 , 1 ) ;
V_64 = V_179 . V_64 ;
if ( V_64 != 0 )
goto V_189;
if ( V_12 == V_13 )
F_58 ( V_164 -> V_190 , F_2 ( V_164 -> V_2 ) ) ;
else
F_58 ( V_164 -> V_190 , F_1 ( V_164 -> V_2 ) ) ;
V_5 -> V_191 = V_164 -> V_190 ;
if ( V_12 == V_13 )
V_164 -> V_177 = F_5 ( V_5 -> V_83 ,
V_5 -> V_20 ) ;
else
V_164 -> V_177 = F_4 ( V_5 -> V_27 ) ;
F_10 ( L_117 , V_164 -> V_177 ) ;
if ( F_74 ( V_164 , V_5 -> V_83 ) ) {
F_18 (KERN_ERR FW_BUG PFX L_118 ) ;
F_48 ( V_5 ) ;
F_36 ( V_5 -> V_83 ) ;
F_36 ( V_5 ) ;
return - V_81 ;
}
if ( F_75 ( V_186 , V_192 ) )
V_193 . V_194 = V_195 ;
F_76 ( V_5 -> V_83 , V_164 -> V_2 ) ;
if ( V_12 == V_13 )
F_10 ( L_119 ,
V_5 -> V_20 ) ;
else
F_10 ( L_120 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
F_56 ( V_168 , V_164 -> V_2 ) = V_5 ;
return 0 ;
V_189:
F_48 ( V_5 ) ;
V_128:
F_36 ( V_5 ) ;
return - V_65 ;
}
static int T_6 F_77 ( struct V_163 * V_164 )
{
struct V_16 * V_5 = F_56 ( V_168 , V_164 -> V_2 ) ;
if ( ! V_5 )
return - V_81 ;
F_48 ( V_5 ) ;
F_78 ( V_164 -> V_2 ) ;
F_36 ( V_5 -> V_83 ) ;
F_36 ( V_5 ) ;
F_56 ( V_168 , V_164 -> V_2 ) = NULL ;
return 0 ;
}
static void F_79 ( void * V_196 )
{
int * V_197 = V_196 ;
struct V_16 * V_5 = F_80 ( V_168 ) ;
* V_197 = F_9 ( V_5 ) ;
}
static unsigned int F_81 ( unsigned int V_2 )
{
struct V_16 * V_5 = F_56 ( V_168 , V_2 ) ;
unsigned int V_198 = 0 ;
int V_197 ;
if ( ! V_5 )
return 0 ;
F_70 ( V_2 , F_79 , & V_197 , true ) ;
if ( V_197 )
goto V_199;
if ( V_12 == V_13 )
V_198 = F_5 ( V_5 -> V_83 ,
V_5 -> V_20 ) ;
else
V_198 = F_4 ( V_5 -> V_27 ) ;
V_199:
return V_198 ;
}
static void F_82 ( bool V_200 )
{
int V_2 ;
F_83 () ;
F_84 ( V_201 , V_202 , V_203 ) ;
F_52 (cpu, cpu_online_mask) {
struct V_204 * V_205 = F_85 ( V_203 , V_2 ) ;
if ( V_200 )
V_205 -> V_206 &= ~ F_86 ( 25 ) ;
else
V_205 -> V_206 |= F_86 ( 25 ) ;
}
F_87 ( V_201 , V_202 , V_203 ) ;
F_88 () ;
}
static void F_89 ( bool V_200 )
{
if ( ! V_207 )
return;
if ( V_200 && ! V_208 ) {
V_208 = true ;
F_82 ( V_200 ) ;
F_18 (KERN_INFO PFX L_121 ) ;
} else if ( ! V_200 && V_208 ) {
V_208 = false ;
F_82 ( V_200 ) ;
F_18 (KERN_INFO PFX L_122 ) ;
}
}
static T_7 F_90 ( struct V_163 * V_209 , const char * V_210 ,
T_8 V_211 )
{
int V_172 = - V_81 ;
unsigned long V_212 = 0 ;
V_172 = F_91 ( V_210 , 10 , & V_212 ) ;
if ( ! V_172 && ( V_212 == 0 || V_212 == 1 ) && V_207 )
F_89 ( V_212 ) ;
else
return - V_81 ;
return V_211 ;
}
static T_7 F_92 ( struct V_163 * V_209 , char * V_210 )
{
return sprintf ( V_210 , L_123 , V_208 ) ;
}
static int F_93 ( struct V_213 * V_214 , unsigned long V_215 ,
void * V_216 )
{
unsigned V_2 = ( long ) V_216 ;
T_1 V_10 , V_11 ;
switch ( V_215 ) {
case V_217 :
case V_218 :
if ( ! V_208 ) {
F_94 ( V_2 , V_202 , & V_10 , & V_11 ) ;
V_10 |= F_86 ( 25 ) ;
F_95 ( V_2 , V_202 , V_10 , V_11 ) ;
}
break;
case V_219 :
case V_220 :
F_94 ( V_2 , V_202 , & V_10 , & V_11 ) ;
V_10 &= ~ F_86 ( 25 ) ;
F_95 ( V_2 , V_202 , V_10 , V_11 ) ;
break;
default:
break;
}
return V_221 ;
}
static int T_5 F_96 ( void )
{
unsigned int V_17 , V_222 = 0 , V_2 ;
int V_223 ;
if ( ! F_97 ( V_224 ) )
return - V_65 ;
F_98 (i) {
int V_64 ;
F_70 ( V_17 , F_26 , & V_64 , 1 ) ;
if ( V_64 == 0 )
V_222 ++ ;
}
if ( V_222 != F_72 () )
return - V_65 ;
F_18 (KERN_INFO PFX L_124 VERSION L_125 ,
num_online_nodes(), boot_cpu_data.x86_model_id, supported_cpus) ;
if ( F_99 ( V_225 ) ) {
V_207 = true ;
V_203 = F_100 () ;
if ( ! V_203 ) {
F_18 ( V_182 L_126 , V_226 ) ;
return - V_90 ;
}
F_101 ( & V_227 ) ;
F_84 ( V_201 , V_202 , V_203 ) ;
F_52 (cpu, cpu_online_mask) {
struct V_204 * V_205 = F_85 ( V_203 , V_2 ) ;
V_208 |= ! ( ! ! ( V_205 -> V_206 & F_86 ( 25 ) ) ) ;
}
F_18 (KERN_INFO PFX L_127 ,
(cpb_enabled ? L_128 : L_129)) ;
}
V_223 = F_102 ( & V_193 ) ;
if ( V_223 < 0 && F_99 ( V_225 ) ) {
F_103 ( & V_227 ) ;
F_104 ( V_203 ) ;
V_203 = NULL ;
}
return V_223 ;
}
static void T_9 F_105 ( void )
{
F_10 ( L_130 ) ;
if ( F_99 ( V_225 ) ) {
F_104 ( V_203 ) ;
V_203 = NULL ;
F_103 ( & V_227 ) ;
}
F_106 ( & V_193 ) ;
}
