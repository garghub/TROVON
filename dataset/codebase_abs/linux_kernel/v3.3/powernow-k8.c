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
if ( F_27 ( V_66 . V_67 ) != V_68 )
return;
V_60 = F_28 ( V_69 ) ;
if ( ( ( V_60 & V_70 ) != V_71 ) &&
( ( V_60 & V_70 ) < V_72 ) )
return;
if ( ( V_60 & V_70 ) == V_71 ) {
if ( ( ( V_60 & V_73 ) != V_73 ) ||
( ( V_60 & V_74 ) > V_75 ) ) {
F_18 (KERN_INFO PFX
L_42 , eax) ;
return;
}
V_60 = F_28 ( V_76 ) ;
if ( V_60 < V_77 ) {
F_18 (KERN_INFO PFX
L_43 ) ;
return;
}
F_29 ( V_77 , & V_60 , & V_61 , & V_62 , & V_63 ) ;
if ( ( V_63 & V_78 )
!= V_78 ) {
F_18 (KERN_INFO PFX
L_44 ) ;
return;
}
} else {
F_29 ( V_77 , & V_60 , & V_61 , & V_62 , & V_63 ) ;
if ( ( V_63 & V_79 ) == V_79 )
V_12 = V_13 ;
else
return;
}
* V_64 = 0 ;
}
static int F_30 ( struct V_16 * V_5 , struct V_80 * V_81 ,
T_2 V_50 )
{
unsigned int V_82 ;
T_2 V_83 = 0xff ;
for ( V_82 = 0 ; V_82 < V_5 -> V_23 ; V_82 ++ ) {
if ( V_81 [ V_82 ] . V_32 > V_84 ) {
F_18 (KERN_ERR FW_BUG PFX L_45 ,
j, pst[j].vid) ;
return - V_85 ;
}
if ( V_81 [ V_82 ] . V_32 < V_5 -> V_49 ) {
F_18 (KERN_ERR FW_BUG PFX L_46
L_47 , j) ;
return - V_65 ;
}
if ( V_81 [ V_82 ] . V_32 < V_50 + V_5 -> V_49 ) {
F_18 (KERN_ERR FW_BUG PFX L_48
L_47 , j) ;
return - V_65 ;
}
if ( V_81 [ V_82 ] . V_3 > V_86 ) {
F_18 (KERN_ERR FW_BUG PFX L_49
L_47 , j) ;
return - V_65 ;
}
if ( V_82 && ( V_81 [ V_82 ] . V_3 < V_9 ) ) {
F_18 (KERN_ERR FW_BUG PFX L_50
L_51 , j, pst[j].fid) ;
return - V_85 ;
}
if ( V_81 [ V_82 ] . V_3 < V_83 )
V_83 = V_81 [ V_82 ] . V_3 ;
}
if ( V_83 & 1 ) {
F_18 (KERN_ERR FW_BUG PFX L_52 ) ;
return - V_85 ;
}
if ( V_83 > V_52 )
F_18 (KERN_INFO FW_BUG PFX
L_53 ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_87 ,
unsigned int V_88 )
{
V_87 [ V_88 ] . V_8 = V_89 ;
}
static void F_32 ( struct V_16 * V_5 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_5 -> V_23 ; V_82 ++ ) {
if ( V_5 -> V_87 [ V_82 ] . V_8 !=
V_89 ) {
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
if ( V_5 -> V_90 )
F_18 (KERN_INFO PFX L_56 ,
data->batps) ;
}
static T_1 F_33 ( T_1 V_3 , T_1 V_91 )
{
T_1 V_92 = 0 ;
if ( V_21 . V_22 == 0x10 )
V_92 = ( 100 * ( V_3 + 0x10 ) ) >> V_91 ;
else if ( V_21 . V_22 == 0x11 )
V_92 = ( 100 * ( V_3 + 8 ) ) >> V_91 ;
else
F_34 () ;
return V_92 * 1000 ;
}
static int F_35 ( struct V_16 * V_5 ,
struct V_80 * V_81 , T_2 V_50 )
{
struct V_4 * V_87 ;
unsigned int V_82 ;
if ( V_5 -> V_90 ) {
F_18 (KERN_WARNING PFX
L_57
L_58 , data->batps) ;
V_5 -> V_23 = V_5 -> V_90 ;
}
for ( V_82 = 1 ; V_82 < V_5 -> V_23 ; V_82 ++ ) {
if ( V_81 [ V_82 - 1 ] . V_3 >= V_81 [ V_82 ] . V_3 ) {
F_18 (KERN_ERR PFX L_59 ) ;
return - V_85 ;
}
}
if ( V_5 -> V_23 < 2 ) {
F_18 (KERN_ERR PFX L_60 ) ;
return - V_65 ;
}
if ( F_30 ( V_5 , V_81 , V_50 ) )
return - V_85 ;
V_87 = F_36 ( ( sizeof( struct V_4 )
* ( V_5 -> V_23 + 1 ) ) , V_93 ) ;
if ( ! V_87 ) {
F_18 (KERN_ERR PFX L_61 ) ;
return - V_94 ;
}
for ( V_82 = 0 ; V_82 < V_5 -> V_23 ; V_82 ++ ) {
int V_95 ;
V_87 [ V_82 ] . V_96 = V_81 [ V_82 ] . V_3 ;
V_87 [ V_82 ] . V_96 |= ( V_81 [ V_82 ] . V_32 << 8 ) ;
V_95 = F_4 ( V_81 [ V_82 ] . V_3 ) ;
V_87 [ V_82 ] . V_8 = V_95 ;
}
V_87 [ V_5 -> V_23 ] . V_8 = V_97 ;
V_87 [ V_5 -> V_23 ] . V_96 = 0 ;
if ( F_9 ( V_5 ) ) {
F_37 ( V_87 ) ;
return - V_98 ;
}
F_10 ( L_62 , V_5 -> V_27 , V_5 -> V_25 ) ;
V_5 -> V_87 = V_87 ;
if ( F_38 ( F_1 ( V_5 -> V_2 ) ) == V_5 -> V_2 )
F_32 ( V_5 ) ;
for ( V_82 = 0 ; V_82 < V_5 -> V_23 ; V_82 ++ )
if ( ( V_81 [ V_82 ] . V_3 == V_5 -> V_27 ) &&
( V_81 [ V_82 ] . V_32 == V_5 -> V_25 ) )
return 0 ;
F_10 ( L_63 ) ;
return 0 ;
}
static int F_39 ( struct V_16 * V_5 )
{
struct V_99 * V_100 ;
unsigned int V_17 ;
T_1 V_101 ;
T_2 V_50 ;
T_1 V_102 = 0 ;
T_1 V_103 ;
for ( V_17 = 0xc0000 ; V_17 < 0xffff0 ; V_17 += 0x10 ) {
V_100 = F_40 ( V_17 ) ;
if ( memcmp ( V_100 , V_104 , V_105 ) != 0 )
continue;
F_10 ( L_64 , V_100 ) ;
F_10 ( L_65 , V_100 -> V_106 ) ;
if ( V_100 -> V_106 != V_107 ) {
F_18 (KERN_ERR FW_BUG PFX L_66 ) ;
return - V_65 ;
}
F_10 ( L_67 , V_100 -> V_108 ) ;
if ( V_100 -> V_108 ) {
F_18 (KERN_ERR FW_BUG PFX L_68 ) ;
return - V_65 ;
}
V_5 -> V_30 = V_100 -> V_30 ;
F_10 ( L_69 ,
V_5 -> V_30 ) ;
F_10 ( L_70 , V_100 -> V_109 ) ;
V_5 -> V_49 = V_100 -> V_109 & 3 ;
V_5 -> V_29 = ( ( V_100 -> V_109 ) >> 2 ) & 3 ;
V_101 = ( ( V_100 -> V_109 ) >> 4 ) & 3 ;
V_5 -> V_53 = 1 << V_101 ;
V_5 -> V_90 = ( ( V_100 -> V_109 ) >> 6 ) & 3 ;
F_10 ( L_71 , V_5 -> V_49 ) ;
F_10 ( L_72 , V_5 -> V_29 ) ;
F_10 ( L_73 , V_101 , V_5 -> V_53 ) ;
F_10 ( L_74 , V_100 -> V_110 ) ;
V_102 = V_100 -> V_110 ;
if ( ( V_100 -> F_29 == 0x00000fc0 ) ||
( V_100 -> F_29 == 0x00000fe0 ) ) {
V_103 = F_28 ( V_69 ) ;
if ( ( V_103 == 0x00000fc0 ) ||
( V_103 == 0x00000fe0 ) )
V_102 = 1 ;
}
if ( V_102 != 1 ) {
F_18 (KERN_ERR FW_BUG PFX L_75 ) ;
return - V_65 ;
}
V_5 -> V_40 = V_100 -> V_111 ;
F_10 ( L_76 , V_100 -> V_111 ) ;
F_10 ( L_77 , V_100 -> V_112 ) ;
F_10 ( L_78 , V_100 -> V_50 ) ;
V_50 = V_100 -> V_50 ;
V_5 -> V_23 = V_100 -> V_23 ;
F_10 ( L_79 , V_5 -> V_23 ) ;
return F_35 ( V_5 ,
(struct V_80 * ) ( V_100 + 1 ) , V_50 ) ;
}
F_18 (KERN_ERR FW_BUG PFX L_80 ) ;
F_18 (KERN_ERR PFX L_81
L_82 ) ;
return - V_65 ;
}
static void F_41 ( struct V_16 * V_5 ,
unsigned int V_96 )
{
T_3 V_113 ;
if ( ! V_5 -> V_114 . V_115 || ( V_12 == V_13 ) )
return;
V_113 = V_5 -> V_114 . V_116 [ V_96 ] . V_113 ;
V_5 -> V_29 = ( V_113 >> V_117 ) & V_118 ;
V_5 -> V_49 = ( V_113 >> V_119 ) & V_120 ;
V_5 -> V_121 = ( V_113 >> V_122 ) & V_123 ;
V_5 -> V_40 = ( V_113 >> V_124 ) & V_125 ;
V_5 -> V_53 = 1 << ( ( V_113 >> V_126 ) & V_127 ) ;
V_5 -> V_30 = ( V_113 >> V_128 ) & V_129 ;
}
static int F_42 ( struct V_16 * V_5 )
{
struct V_4 * V_87 ;
int V_130 = - V_65 ;
T_3 V_113 , V_131 ;
if ( F_43 ( & V_5 -> V_114 , V_5 -> V_2 ) ) {
F_10 ( L_83 ) ;
return - V_98 ;
}
if ( V_5 -> V_114 . V_115 <= 1 ) {
F_10 ( L_84 ) ;
goto V_132;
}
V_113 = V_5 -> V_114 . V_133 . V_134 ;
V_131 = V_5 -> V_114 . V_135 . V_134 ;
if ( ( V_113 != V_136 ) ||
( V_131 != V_136 ) ) {
F_10 ( L_85 ,
V_113 , V_131 ) ;
goto V_132;
}
V_87 = F_36 ( ( sizeof( struct V_4 )
* ( V_5 -> V_114 . V_115 + 1 ) ) , V_93 ) ;
if ( ! V_87 ) {
F_10 ( L_61 ) ;
goto V_132;
}
V_5 -> V_23 = V_5 -> V_114 . V_115 ;
F_41 ( V_5 , 0 ) ;
if ( V_12 == V_13 )
V_130 = F_44 ( V_5 , V_87 ) ;
else
V_130 = F_45 ( V_5 , V_87 ) ;
if ( V_130 )
goto V_137;
V_87 [ V_5 -> V_114 . V_115 ] . V_8 =
V_97 ;
V_87 [ V_5 -> V_114 . V_115 ] . V_96 = 0 ;
V_5 -> V_87 = V_87 ;
if ( F_38 ( F_1 ( V_5 -> V_2 ) ) == V_5 -> V_2 )
F_32 ( V_5 ) ;
F_46 ( V_138 ) ;
if ( ! F_47 ( & V_5 -> V_114 . V_139 , V_93 ) ) {
F_18 (KERN_ERR PFX
L_86 ) ;
V_130 = - V_94 ;
goto V_137;
}
return 0 ;
V_137:
F_37 ( V_87 ) ;
V_132:
F_48 ( & V_5 -> V_114 , V_5 -> V_2 ) ;
V_5 -> V_114 . V_115 = 0 ;
return V_130 ;
}
static int F_44 ( struct V_16 * V_5 ,
struct V_4 * V_87 )
{
int V_17 ;
T_1 V_11 = 0 , V_10 = 0 ;
F_8 ( V_140 , V_10 , V_11 ) ;
V_5 -> V_141 = ( V_10 & V_142 ) >> V_143 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_114 . V_115 ; V_17 ++ ) {
T_1 V_96 ;
V_96 = V_5 -> V_114 . V_116 [ V_17 ] . V_113 & V_19 ;
if ( V_96 > V_5 -> V_141 ) {
F_18 (KERN_ERR PFX L_87
L_88 , i, index) ;
F_18 (KERN_ERR PFX L_89
L_90 ) ;
F_31 ( V_87 , V_17 ) ;
continue;
}
V_7 [ V_96 ] = V_17 ;
if ( ( V_21 . V_22 == 0x10 && V_21 . V_144 < 10 )
|| V_21 . V_22 == 0x11 ) {
F_8 ( V_145 + V_96 , V_10 , V_11 ) ;
if ( ! ( V_11 & V_146 ) ) {
F_10 ( L_91 , V_96 ) ;
F_31 ( V_87 , V_17 ) ;
continue;
}
V_87 [ V_17 ] . V_8 =
F_33 ( V_10 & 0x3f , ( V_10 >> 6 ) & 7 ) ;
} else
V_87 [ V_17 ] . V_8 =
V_5 -> V_114 . V_116 [ V_17 ] . V_147 * 1000 ;
V_87 [ V_17 ] . V_96 = V_96 ;
}
return 0 ;
}
static int F_45 ( struct V_16 * V_5 ,
struct V_4 * V_87 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_114 . V_115 ; V_17 ++ ) {
T_1 V_3 ;
T_1 V_32 ;
T_1 V_95 , V_96 ;
T_3 V_131 , V_113 ;
if ( V_5 -> V_121 ) {
V_131 = V_5 -> V_114 . V_116 [ V_17 ] . V_131 ;
V_3 = V_131 & V_148 ;
V_32 = ( V_131 >> V_149 ) & V_150 ;
} else {
V_113 = V_5 -> V_114 . V_116 [ V_17 ] . V_113 ;
V_3 = V_113 & V_151 ;
V_32 = ( V_113 >> V_149 ) & V_152 ;
}
F_10 ( L_92 , V_17 , V_3 , V_32 ) ;
V_96 = V_3 | ( V_32 << 8 ) ;
V_87 [ V_17 ] . V_96 = V_96 ;
V_95 = F_4 ( V_3 ) ;
V_87 [ V_17 ] . V_8 = V_95 ;
if ( ( V_95 > ( V_153 * 1000 ) ) || ( V_95 < ( V_154 * 1000 ) ) ) {
F_10 ( L_93 , V_95 ) ;
F_31 ( V_87 , V_17 ) ;
continue;
}
if ( V_32 == V_155 ) {
F_10 ( L_94 , V_32 ) ;
F_31 ( V_87 , V_17 ) ;
continue;
}
if ( V_95 != ( V_5 -> V_114 . V_116 [ V_17 ] . V_147 * 1000 ) ) {
F_18 (KERN_INFO PFX L_95
L_96 , freq,
(unsigned int)
(data->acpi_data.states[i].core_frequency
* 1000)) ;
F_31 ( V_87 , V_17 ) ;
continue;
}
}
return 0 ;
}
static void F_49 ( struct V_16 * V_5 )
{
if ( V_5 -> V_114 . V_115 )
F_48 ( & V_5 -> V_114 ,
V_5 -> V_2 ) ;
F_50 ( V_5 -> V_114 . V_139 ) ;
}
static int F_51 ( struct V_16 * V_5 )
{
int V_156 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_114 . V_115 ; V_17 ++ ) {
int V_157 = V_5 -> V_114 . V_116 [ V_17 ] . V_158
+ V_5 -> V_114 . V_116 [ V_17 ] . V_159 ;
if ( V_157 > V_156 )
V_156 = V_157 ;
}
if ( V_156 == 0 ) {
if ( V_21 . V_22 < 0x11 )
F_18 (KERN_ERR FW_WARN PFX L_97
L_98 ) ;
V_156 = 1 ;
}
return 1000 * V_156 ;
}
static int F_52 ( struct V_16 * V_5 ,
unsigned int V_96 )
{
T_1 V_3 = 0 ;
T_1 V_32 = 0 ;
int V_160 , V_17 ;
struct V_161 V_162 ;
F_10 ( L_99 , F_15 () , V_96 ) ;
V_3 = V_5 -> V_87 [ V_96 ] . V_96 & 0xFF ;
V_32 = ( V_5 -> V_87 [ V_96 ] . V_96 & 0xFF00 ) >> 8 ;
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
V_162 . V_163 = F_4 ( V_5 -> V_27 ) ;
V_162 . V_164 = F_4 ( V_3 ) ;
F_53 (i, data->available_cores) {
V_162 . V_2 = V_17 ;
F_54 ( & V_162 , V_165 ) ;
}
V_160 = F_22 ( V_5 , V_3 , V_32 ) ;
if ( V_160 )
return V_160 ;
V_162 . V_164 = F_4 ( V_5 -> V_27 ) ;
F_53 (i, data->available_cores) {
V_162 . V_2 = V_17 ;
F_54 ( & V_162 , V_166 ) ;
}
return V_160 ;
}
static int F_55 ( struct V_16 * V_5 ,
unsigned int V_96 )
{
T_1 V_6 = 0 ;
int V_160 , V_17 ;
struct V_161 V_162 ;
F_10 ( L_99 , F_15 () , V_96 ) ;
V_6 = V_96 & V_19 ;
if ( V_6 > V_5 -> V_141 )
return - V_85 ;
V_162 . V_163 = F_5 ( V_5 -> V_87 ,
V_5 -> V_20 ) ;
V_162 . V_164 = F_5 ( V_5 -> V_87 , V_6 ) ;
F_53 (i, data->available_cores) {
V_162 . V_2 = V_17 ;
F_54 ( & V_162 , V_165 ) ;
}
V_160 = F_21 ( V_5 , V_6 ) ;
V_162 . V_164 = F_5 ( V_5 -> V_87 , V_6 ) ;
F_53 (i, data->available_cores) {
V_162 . V_2 = V_17 ;
F_54 ( & V_162 , V_166 ) ;
}
return V_160 ;
}
static int F_56 ( struct V_167 * V_168 ,
unsigned V_169 , unsigned V_170 )
{
T_4 V_171 ;
struct V_16 * V_5 = F_57 ( V_172 , V_168 -> V_2 ) ;
T_1 V_173 ;
T_1 V_174 ;
unsigned int V_175 ;
int V_176 = - V_98 ;
if ( ! V_5 )
return - V_85 ;
V_173 = V_5 -> V_27 ;
V_174 = V_5 -> V_25 ;
if ( ! F_58 ( & V_171 , V_93 ) )
return - V_94 ;
F_59 ( V_171 , F_60 ( V_177 ) ) ;
F_61 ( V_177 , F_2 ( V_168 -> V_2 ) ) ;
if ( F_15 () != V_168 -> V_2 ) {
F_18 (KERN_ERR PFX L_103 , pol->cpu) ;
goto V_132;
}
if ( F_7 () ) {
F_18 (KERN_ERR PFX L_104 ) ;
goto V_132;
}
F_10 ( L_105 ,
V_168 -> V_2 , V_169 , V_168 -> V_178 , V_168 -> V_179 , V_170 ) ;
if ( F_9 ( V_5 ) )
goto V_132;
if ( V_12 != V_13 ) {
F_10 ( L_106 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
if ( ( V_174 != V_5 -> V_25 ) ||
( V_173 != V_5 -> V_27 ) ) {
F_18 (KERN_INFO PFX
L_107
L_108 ,
checkfid, data->currfid,
checkvid, data->currvid) ;
}
}
if ( F_62 ( V_168 , V_5 -> V_87 ,
V_169 , V_170 , & V_175 ) )
goto V_132;
F_63 ( & V_180 ) ;
F_41 ( V_5 , V_175 ) ;
if ( V_12 == V_13 )
V_176 = F_55 ( V_5 ,
V_5 -> V_87 [ V_175 ] . V_96 ) ;
else
V_176 = F_52 ( V_5 , V_175 ) ;
if ( V_176 ) {
F_18 (KERN_ERR PFX L_109 ) ;
V_176 = 1 ;
F_64 ( & V_180 ) ;
goto V_132;
}
F_64 ( & V_180 ) ;
if ( V_12 == V_13 )
V_168 -> V_181 = F_5 ( V_5 -> V_87 ,
V_5 -> V_87 [ V_175 ] . V_96 ) ;
else
V_168 -> V_181 = F_4 ( V_5 -> V_27 ) ;
V_176 = 0 ;
V_132:
F_61 ( V_177 , V_171 ) ;
F_50 ( V_171 ) ;
return V_176 ;
}
static int F_65 ( struct V_167 * V_168 )
{
struct V_16 * V_5 = F_57 ( V_172 , V_168 -> V_2 ) ;
if ( ! V_5 )
return - V_85 ;
return F_66 ( V_168 , V_5 -> V_87 ) ;
}
static void T_5 F_67 ( void * V_182 )
{
struct V_183 * V_183 = V_182 ;
if ( F_7 () ) {
F_18 (KERN_ERR PFX L_110 ) ;
V_183 -> V_64 = - V_65 ;
return;
}
if ( F_9 ( V_183 -> V_5 ) ) {
V_183 -> V_64 = - V_65 ;
return;
}
if ( V_12 == V_184 )
F_14 () ;
V_183 -> V_64 = 0 ;
}
static int T_5 F_68 ( struct V_167 * V_168 )
{
static const char V_185 [] =
V_186 V_187 V_188 L_111
V_187 V_188 L_112 ;
struct V_16 * V_5 ;
struct V_183 V_183 ;
int V_64 ;
struct V_189 * V_190 = & F_69 ( V_168 -> V_2 ) ;
if ( ! F_70 ( V_168 -> V_2 ) )
return - V_65 ;
F_71 ( V_168 -> V_2 , F_26 , & V_64 , 1 ) ;
if ( V_64 )
return - V_65 ;
V_5 = F_72 ( sizeof( struct V_16 ) , V_93 ) ;
if ( ! V_5 ) {
F_18 (KERN_ERR PFX L_113 ) ;
return - V_94 ;
}
V_5 -> V_2 = V_168 -> V_2 ;
V_5 -> V_20 = V_191 ;
if ( F_42 ( V_5 ) ) {
if ( F_73 () != 1 ) {
F_74 ( V_185 ) ;
goto V_132;
}
if ( V_168 -> V_2 != 0 ) {
F_18 (KERN_ERR FW_BUG PFX L_114
L_115
L_116 ) ;
goto V_132;
}
V_64 = F_39 ( V_5 ) ;
if ( V_64 )
goto V_132;
V_168 -> V_192 . V_158 = (
( ( V_5 -> V_49 + 8 ) * V_5 -> V_30 * V_31 ) +
( ( 1 << V_5 -> V_29 ) * 30 ) ) * 1000 ;
} else
V_168 -> V_192 . V_158 = F_51 ( V_5 ) ;
V_183 . V_5 = V_5 ;
F_71 ( V_5 -> V_2 , F_67 ,
& V_183 , 1 ) ;
V_64 = V_183 . V_64 ;
if ( V_64 != 0 )
goto V_193;
if ( V_12 == V_13 )
F_59 ( V_168 -> V_194 , F_2 ( V_168 -> V_2 ) ) ;
else
F_59 ( V_168 -> V_194 , F_1 ( V_168 -> V_2 ) ) ;
V_5 -> V_195 = V_168 -> V_194 ;
if ( V_12 == V_13 )
V_168 -> V_181 = F_5 ( V_5 -> V_87 ,
V_5 -> V_20 ) ;
else
V_168 -> V_181 = F_4 ( V_5 -> V_27 ) ;
F_10 ( L_117 , V_168 -> V_181 ) ;
if ( F_75 ( V_168 , V_5 -> V_87 ) ) {
F_18 (KERN_ERR FW_BUG PFX L_118 ) ;
F_49 ( V_5 ) ;
F_37 ( V_5 -> V_87 ) ;
F_37 ( V_5 ) ;
return - V_85 ;
}
if ( F_76 ( V_190 , V_196 ) )
V_197 . V_198 = V_199 ;
F_77 ( V_5 -> V_87 , V_168 -> V_2 ) ;
if ( V_12 == V_13 )
F_10 ( L_119 ,
V_5 -> V_20 ) ;
else
F_10 ( L_120 ,
V_5 -> V_27 , V_5 -> V_25 ) ;
F_57 ( V_172 , V_168 -> V_2 ) = V_5 ;
return 0 ;
V_193:
F_49 ( V_5 ) ;
V_132:
F_37 ( V_5 ) ;
return - V_65 ;
}
static int T_6 F_78 ( struct V_167 * V_168 )
{
struct V_16 * V_5 = F_57 ( V_172 , V_168 -> V_2 ) ;
if ( ! V_5 )
return - V_85 ;
F_49 ( V_5 ) ;
F_79 ( V_168 -> V_2 ) ;
F_37 ( V_5 -> V_87 ) ;
F_37 ( V_5 ) ;
F_57 ( V_172 , V_168 -> V_2 ) = NULL ;
return 0 ;
}
static void F_80 ( void * V_200 )
{
int * V_201 = V_200 ;
struct V_16 * V_5 = F_27 ( V_172 ) ;
* V_201 = F_9 ( V_5 ) ;
}
static unsigned int F_81 ( unsigned int V_2 )
{
struct V_16 * V_5 = F_57 ( V_172 , V_2 ) ;
unsigned int V_202 = 0 ;
int V_201 ;
if ( ! V_5 )
return 0 ;
F_71 ( V_2 , F_80 , & V_201 , true ) ;
if ( V_201 )
goto V_203;
if ( V_12 == V_13 )
V_202 = F_5 ( V_5 -> V_87 ,
V_5 -> V_20 ) ;
else
V_202 = F_4 ( V_5 -> V_27 ) ;
V_203:
return V_202 ;
}
static void F_82 ( bool V_204 )
{
int V_2 ;
F_83 () ;
F_84 ( V_205 , V_206 , V_207 ) ;
F_53 (cpu, cpu_online_mask) {
struct V_208 * V_209 = F_85 ( V_207 , V_2 ) ;
if ( V_204 )
V_209 -> V_210 &= ~ F_86 ( 25 ) ;
else
V_209 -> V_210 |= F_86 ( 25 ) ;
}
F_87 ( V_205 , V_206 , V_207 ) ;
F_88 () ;
}
static void F_89 ( bool V_204 )
{
if ( ! V_211 )
return;
if ( V_204 && ! V_212 ) {
V_212 = true ;
F_82 ( V_204 ) ;
F_18 (KERN_INFO PFX L_121 ) ;
} else if ( ! V_204 && V_212 ) {
V_212 = false ;
F_82 ( V_204 ) ;
F_18 (KERN_INFO PFX L_122 ) ;
}
}
static T_7 F_90 ( struct V_167 * V_213 , const char * V_214 ,
T_8 V_215 )
{
int V_176 = - V_85 ;
unsigned long V_216 = 0 ;
V_176 = F_91 ( V_214 , 10 , & V_216 ) ;
if ( ! V_176 && ( V_216 == 0 || V_216 == 1 ) && V_211 )
F_89 ( V_216 ) ;
else
return - V_85 ;
return V_215 ;
}
static T_7 F_92 ( struct V_167 * V_213 , char * V_214 )
{
return sprintf ( V_214 , L_123 , V_212 ) ;
}
static int F_93 ( struct V_217 * V_218 , unsigned long V_219 ,
void * V_220 )
{
unsigned V_2 = ( long ) V_220 ;
T_1 V_10 , V_11 ;
switch ( V_219 ) {
case V_221 :
case V_222 :
if ( ! V_212 ) {
F_94 ( V_2 , V_206 , & V_10 , & V_11 ) ;
V_10 |= F_86 ( 25 ) ;
F_95 ( V_2 , V_206 , V_10 , V_11 ) ;
}
break;
case V_223 :
case V_224 :
F_94 ( V_2 , V_206 , & V_10 , & V_11 ) ;
V_10 &= ~ F_86 ( 25 ) ;
F_95 ( V_2 , V_206 , V_10 , V_11 ) ;
break;
default:
break;
}
return V_225 ;
}
static int T_5 F_96 ( void )
{
unsigned int V_17 , V_226 = 0 , V_2 ;
int V_227 ;
F_97 (i) {
int V_64 ;
F_71 ( V_17 , F_26 , & V_64 , 1 ) ;
if ( V_64 == 0 )
V_226 ++ ;
}
if ( V_226 != F_73 () )
return - V_65 ;
F_18 (KERN_INFO PFX L_124 VERSION L_125 ,
num_online_nodes(), boot_cpu_data.x86_model_id, supported_cpus) ;
if ( F_98 ( V_228 ) ) {
V_211 = true ;
V_207 = F_99 () ;
if ( ! V_207 ) {
F_18 ( V_186 L_126 , V_229 ) ;
return - V_94 ;
}
F_100 ( & V_230 ) ;
F_84 ( V_205 , V_206 , V_207 ) ;
F_53 (cpu, cpu_online_mask) {
struct V_208 * V_209 = F_85 ( V_207 , V_2 ) ;
V_212 |= ! ( ! ! ( V_209 -> V_210 & F_86 ( 25 ) ) ) ;
}
F_18 (KERN_INFO PFX L_127 ,
(cpb_enabled ? L_128 : L_129)) ;
}
V_227 = F_101 ( & V_197 ) ;
if ( V_227 < 0 && F_98 ( V_228 ) ) {
F_102 ( & V_230 ) ;
F_103 ( V_207 ) ;
V_207 = NULL ;
}
return V_227 ;
}
static void T_9 F_104 ( void )
{
F_10 ( L_130 ) ;
if ( F_98 ( V_228 ) ) {
F_103 ( V_207 ) ;
V_207 = NULL ;
F_102 ( & V_230 ) ;
}
F_105 ( & V_197 ) ;
}
