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
return V_5 [ V_6 ] . V_7 ;
}
static T_1 F_6 ( T_1 V_3 )
{
if ( V_3 < V_8 )
return 8 + ( 2 * V_3 ) ;
else
return V_3 ;
}
static int F_7 ( void )
{
T_1 V_9 , V_10 ;
if ( V_11 == V_12 )
return 0 ;
F_8 ( V_13 , V_9 , V_10 ) ;
return V_9 & V_14 ? 1 : 0 ;
}
static int F_9 ( struct V_15 * V_5 )
{
T_1 V_9 , V_10 ;
T_1 V_16 = 0 ;
if ( V_11 == V_12 ) {
F_8 ( V_17 , V_9 , V_10 ) ;
V_16 = V_9 & V_18 ;
V_5 -> V_19 = V_16 ;
if ( ( V_20 . V_21 == 0x11 ) && ( V_16 >= V_5 -> V_22 ) )
V_5 -> V_19 = V_23 ;
return 0 ;
}
do {
if ( V_16 ++ > 10000 ) {
F_10 ( L_1 ) ;
return 1 ;
}
F_8 ( V_13 , V_9 , V_10 ) ;
} while ( V_9 & V_14 );
V_5 -> V_24 = V_10 & V_25 ;
V_5 -> V_26 = V_9 & V_27 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_5 )
{
F_12 ( ( 1 << V_5 -> V_28 ) * 10 ) ;
return;
}
static void F_13 ( struct V_15 * V_5 )
{
F_12 ( V_5 -> V_29 * V_30 ) ;
return;
}
static void F_14 ( void )
{
T_1 V_9 , V_10 ;
T_2 V_3 , V_31 ;
F_8 ( V_13 , V_9 , V_10 ) ;
V_31 = V_10 & V_25 ;
V_3 = V_9 & V_27 ;
V_9 = V_3 | ( V_31 << V_32 ) ;
V_10 = V_33 ;
F_10 ( L_2 , F_15 () , V_9 , V_10 ) ;
F_16 ( V_34 , V_9 , V_10 ) ;
}
static int F_17 ( struct V_15 * V_5 , T_1 V_3 )
{
T_1 V_9 ;
T_1 V_35 = V_5 -> V_24 ;
T_1 V_16 = 0 ;
if ( ( V_3 & V_36 ) || ( V_5 -> V_24 & V_37 ) ) {
F_18 (KERN_ERR PFX L_3 ) ;
return 1 ;
}
V_9 = V_3 ;
V_9 |= ( V_5 -> V_24 << V_32 ) ;
V_9 |= V_38 ;
F_10 ( L_4 ,
V_3 , V_9 , V_5 -> V_39 * V_40 ) ;
do {
F_16 ( V_34 , V_9 , V_5 -> V_39 * V_40 ) ;
if ( V_16 ++ > 100 ) {
F_18 (KERN_ERR PFX
L_5
L_6 ) ;
return 1 ;
}
} while ( F_9 ( V_5 ) );
F_11 ( V_5 ) ;
if ( V_35 != V_5 -> V_24 ) {
F_18 (KERN_ERR PFX
L_7 ,
savevid, data->currvid) ;
return 1 ;
}
if ( V_3 != V_5 -> V_26 ) {
F_18 (KERN_ERR PFX
L_8 , fid,
data->currfid) ;
return 1 ;
}
return 0 ;
}
static int F_19 ( struct V_15 * V_5 , T_1 V_31 )
{
T_1 V_9 ;
T_1 V_41 = V_5 -> V_26 ;
int V_16 = 0 ;
if ( ( V_5 -> V_26 & V_36 ) || ( V_31 & V_37 ) ) {
F_18 (KERN_ERR PFX L_9 ) ;
return 1 ;
}
V_9 = V_5 -> V_26 ;
V_9 |= ( V_31 << V_32 ) ;
V_9 |= V_38 ;
F_10 ( L_10 ,
V_31 , V_9 , V_42 ) ;
do {
F_16 ( V_34 , V_9 , V_42 ) ;
if ( V_16 ++ > 100 ) {
F_18 (KERN_ERR PFX L_11
L_12
L_13 ) ;
return 1 ;
}
} while ( F_9 ( V_5 ) );
if ( V_41 != V_5 -> V_26 ) {
F_18 (KERN_ERR PFX L_14
L_15 ,
savefid, data->currfid) ;
return 1 ;
}
if ( V_31 != V_5 -> V_24 ) {
F_18 (KERN_ERR PFX L_16
L_17 ,
vid, data->currvid) ;
return 1 ;
}
return 0 ;
}
static int F_20 ( struct V_15 * V_5 ,
T_1 V_43 , T_1 V_44 )
{
if ( ( V_5 -> V_24 - V_43 ) > V_44 )
V_43 = V_5 -> V_24 - V_44 ;
if ( F_19 ( V_5 , V_43 ) )
return 1 ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_5 , T_1 V_6 )
{
F_16 ( V_45 , V_6 , 0 ) ;
V_5 -> V_19 = V_6 ;
return 0 ;
}
static int F_22 ( struct V_15 * V_5 ,
T_1 V_46 , T_1 V_43 )
{
if ( F_23 ( V_5 , V_43 , V_46 ) )
return 1 ;
if ( F_24 ( V_5 , V_46 ) )
return 1 ;
if ( F_25 ( V_5 , V_43 ) )
return 1 ;
if ( F_9 ( V_5 ) )
return 1 ;
if ( ( V_46 != V_5 -> V_26 ) || ( V_43 != V_5 -> V_24 ) ) {
F_18 (KERN_ERR PFX L_18
L_19 ,
smp_processor_id(),
reqfid, reqvid, data->currfid, data->currvid) ;
return 1 ;
}
F_10 ( L_20 ,
F_15 () , V_5 -> V_26 , V_5 -> V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_15 * V_5 ,
T_1 V_43 , T_1 V_46 )
{
T_1 V_47 = V_5 -> V_48 ;
T_1 V_41 = V_5 -> V_26 ;
T_1 V_49 , V_9 , V_50 = 1 ;
F_10 ( L_21
L_22 ,
F_15 () ,
V_5 -> V_26 , V_5 -> V_24 , V_43 , V_5 -> V_48 ) ;
if ( ( V_41 < V_51 ) && ( V_46 < V_51 ) )
V_50 = 2 ;
V_47 *= V_50 ;
F_8 ( V_13 , V_9 , V_49 ) ;
V_49 = 0x1f & ( V_49 >> 16 ) ;
F_10 ( L_23 , V_49 ) ;
if ( V_43 < V_49 )
V_43 = V_49 ;
while ( V_5 -> V_24 > V_43 ) {
F_10 ( L_24 ,
V_5 -> V_24 , V_43 ) ;
if ( F_20 ( V_5 , V_43 , V_5 -> V_52 ) )
return 1 ;
}
while ( ( V_47 > 0 ) &&
( ( V_50 * V_5 -> V_48 + V_5 -> V_24 ) > V_43 ) ) {
if ( V_5 -> V_24 == V_49 ) {
V_47 = 0 ;
} else {
F_10 ( L_25 ,
V_5 -> V_24 - 1 ) ;
if ( F_20 ( V_5 , V_5 -> V_24 - 1 , 1 ) )
return 1 ;
V_47 -- ;
}
}
if ( F_9 ( V_5 ) )
return 1 ;
if ( V_41 != V_5 -> V_26 ) {
F_18 (KERN_ERR PFX L_26 ,
data->currfid) ;
return 1 ;
}
F_10 ( L_27 ,
V_5 -> V_26 , V_5 -> V_24 ) ;
return 0 ;
}
static int F_24 ( struct V_15 * V_5 , T_1 V_46 )
{
T_1 V_53 , V_54 , V_55 ;
T_1 V_56 , V_35 = V_5 -> V_24 ;
if ( V_5 -> V_26 == V_46 ) {
F_18 (KERN_ERR PFX L_28 ,
data->currfid) ;
return 0 ;
}
F_10 ( L_29
L_30 ,
F_15 () ,
V_5 -> V_26 , V_5 -> V_24 , V_46 ) ;
V_53 = F_6 ( V_46 ) ;
V_54 = F_6 ( V_5 -> V_26 ) ;
V_55 = V_54 > V_53 ? V_54 - V_53
: V_53 - V_54 ;
if ( ( V_46 <= V_51 ) && ( V_5 -> V_26 <= V_51 ) )
V_55 = 0 ;
while ( V_55 > 2 ) {
( V_5 -> V_26 & 1 ) ? ( V_56 = 1 ) : ( V_56 = 2 ) ;
if ( V_46 > V_5 -> V_26 ) {
if ( V_5 -> V_26 > V_51 ) {
if ( F_17 ( V_5 ,
V_5 -> V_26 + V_56 ) )
return 1 ;
} else {
if ( F_17
( V_5 ,
2 + F_6 ( V_5 -> V_26 ) ) )
return 1 ;
}
} else {
if ( F_17 ( V_5 , V_5 -> V_26 - V_56 ) )
return 1 ;
}
V_54 = F_6 ( V_5 -> V_26 ) ;
V_55 = V_54 > V_53 ? V_54 - V_53
: V_53 - V_54 ;
}
if ( F_17 ( V_5 , V_46 ) )
return 1 ;
if ( F_9 ( V_5 ) )
return 1 ;
if ( V_5 -> V_26 != V_46 ) {
F_18 (KERN_ERR PFX
L_31
L_32 ,
data->currfid, reqfid) ;
return 1 ;
}
if ( V_35 != V_5 -> V_24 ) {
F_18 (KERN_ERR PFX L_33 ,
savevid, data->currvid) ;
return 1 ;
}
F_10 ( L_34 ,
V_5 -> V_26 , V_5 -> V_24 ) ;
return 0 ;
}
static int F_25 ( struct V_15 * V_5 ,
T_1 V_43 )
{
T_1 V_41 = V_5 -> V_26 ;
T_1 V_57 = V_43 ;
F_10 ( L_35 ,
F_15 () ,
V_5 -> V_26 , V_5 -> V_24 ) ;
if ( V_43 != V_5 -> V_24 ) {
if ( F_19 ( V_5 , V_43 ) )
return 1 ;
if ( V_41 != V_5 -> V_26 ) {
F_18 (KERN_ERR PFX
L_36 ,
savefid, data->currfid) ;
return 1 ;
}
if ( V_5 -> V_24 != V_43 ) {
F_18 (KERN_ERR PFX
L_37
L_38 ,
reqvid, data->currvid) ;
return 1 ;
}
}
if ( F_9 ( V_5 ) )
return 1 ;
if ( V_57 != V_5 -> V_24 ) {
F_10 ( L_39 , V_5 -> V_24 ) ;
return 1 ;
}
if ( V_41 != V_5 -> V_26 ) {
F_10 ( L_40 ,
V_5 -> V_26 ) ;
return 1 ;
}
F_10 ( L_41 ,
V_5 -> V_26 , V_5 -> V_24 ) ;
return 0 ;
}
static void F_26 ( void * V_58 )
{
T_1 V_59 , V_60 , V_61 , V_62 ;
int * V_63 = V_58 ;
* V_63 = - V_64 ;
if ( F_27 ( V_65 . V_66 ) != V_67 )
return;
V_59 = F_28 ( V_68 ) ;
if ( ( ( V_59 & V_69 ) != V_70 ) &&
( ( V_59 & V_69 ) < V_71 ) )
return;
if ( ( V_59 & V_69 ) == V_70 ) {
if ( ( ( V_59 & V_72 ) != V_72 ) ||
( ( V_59 & V_73 ) > V_74 ) ) {
F_18 (KERN_INFO PFX
L_42 , eax) ;
return;
}
V_59 = F_28 ( V_75 ) ;
if ( V_59 < V_76 ) {
F_18 (KERN_INFO PFX
L_43 ) ;
return;
}
F_29 ( V_76 , & V_59 , & V_60 , & V_61 , & V_62 ) ;
if ( ( V_62 & V_77 )
!= V_77 ) {
F_18 (KERN_INFO PFX
L_44 ) ;
return;
}
} else {
F_29 ( V_76 , & V_59 , & V_60 , & V_61 , & V_62 ) ;
if ( ( V_62 & V_78 ) == V_78 )
V_11 = V_12 ;
else
return;
}
* V_63 = 0 ;
}
static int F_30 ( struct V_15 * V_5 , struct V_79 * V_80 ,
T_2 V_49 )
{
unsigned int V_81 ;
T_2 V_82 = 0xff ;
for ( V_81 = 0 ; V_81 < V_5 -> V_22 ; V_81 ++ ) {
if ( V_80 [ V_81 ] . V_31 > V_83 ) {
F_18 (KERN_ERR FW_BUG PFX L_45 ,
j, pst[j].vid) ;
return - V_84 ;
}
if ( V_80 [ V_81 ] . V_31 < V_5 -> V_48 ) {
F_18 (KERN_ERR FW_BUG PFX L_46
L_47 , j) ;
return - V_64 ;
}
if ( V_80 [ V_81 ] . V_31 < V_49 + V_5 -> V_48 ) {
F_18 (KERN_ERR FW_BUG PFX L_48
L_47 , j) ;
return - V_64 ;
}
if ( V_80 [ V_81 ] . V_3 > V_85 ) {
F_18 (KERN_ERR FW_BUG PFX L_49
L_47 , j) ;
return - V_64 ;
}
if ( V_81 && ( V_80 [ V_81 ] . V_3 < V_8 ) ) {
F_18 (KERN_ERR FW_BUG PFX L_50
L_51 , j, pst[j].fid) ;
return - V_84 ;
}
if ( V_80 [ V_81 ] . V_3 < V_82 )
V_82 = V_80 [ V_81 ] . V_3 ;
}
if ( V_82 & 1 ) {
F_18 (KERN_ERR FW_BUG PFX L_52 ) ;
return - V_84 ;
}
if ( V_82 > V_51 )
F_18 (KERN_INFO FW_BUG PFX
L_53 ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_86 ,
unsigned int V_87 )
{
V_86 [ V_87 ] . V_7 = V_88 ;
}
static void F_32 ( struct V_15 * V_5 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_5 -> V_22 ; V_81 ++ ) {
if ( V_5 -> V_86 [ V_81 ] . V_7 !=
V_88 ) {
if ( V_11 == V_12 ) {
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
if ( V_5 -> V_89 )
F_18 (KERN_INFO PFX L_56 ,
data->batps) ;
}
static T_1 F_33 ( T_1 V_3 , T_1 V_90 )
{
T_1 V_91 = 0 ;
if ( V_20 . V_21 == 0x10 )
V_91 = ( 100 * ( V_3 + 0x10 ) ) >> V_90 ;
else if ( V_20 . V_21 == 0x11 )
V_91 = ( 100 * ( V_3 + 8 ) ) >> V_90 ;
else
F_34 () ;
return V_91 * 1000 ;
}
static int F_35 ( struct V_15 * V_5 ,
struct V_79 * V_80 , T_2 V_49 )
{
struct V_4 * V_86 ;
unsigned int V_81 ;
if ( V_5 -> V_89 ) {
F_18 (KERN_WARNING PFX
L_57
L_58 , data->batps) ;
V_5 -> V_22 = V_5 -> V_89 ;
}
for ( V_81 = 1 ; V_81 < V_5 -> V_22 ; V_81 ++ ) {
if ( V_80 [ V_81 - 1 ] . V_3 >= V_80 [ V_81 ] . V_3 ) {
F_18 (KERN_ERR PFX L_59 ) ;
return - V_84 ;
}
}
if ( V_5 -> V_22 < 2 ) {
F_18 (KERN_ERR PFX L_60 ) ;
return - V_64 ;
}
if ( F_30 ( V_5 , V_80 , V_49 ) )
return - V_84 ;
V_86 = F_36 ( ( sizeof( struct V_4 )
* ( V_5 -> V_22 + 1 ) ) , V_92 ) ;
if ( ! V_86 ) {
F_18 (KERN_ERR PFX L_61 ) ;
return - V_93 ;
}
for ( V_81 = 0 ; V_81 < V_5 -> V_22 ; V_81 ++ ) {
int V_94 ;
V_86 [ V_81 ] . V_95 = V_80 [ V_81 ] . V_3 ;
V_86 [ V_81 ] . V_95 |= ( V_80 [ V_81 ] . V_31 << 8 ) ;
V_94 = F_4 ( V_80 [ V_81 ] . V_3 ) ;
V_86 [ V_81 ] . V_7 = V_94 ;
}
V_86 [ V_5 -> V_22 ] . V_7 = V_96 ;
V_86 [ V_5 -> V_22 ] . V_95 = 0 ;
if ( F_9 ( V_5 ) ) {
F_37 ( V_86 ) ;
return - V_97 ;
}
F_10 ( L_62 , V_5 -> V_26 , V_5 -> V_24 ) ;
V_5 -> V_86 = V_86 ;
if ( F_38 ( F_1 ( V_5 -> V_2 ) ) == V_5 -> V_2 )
F_32 ( V_5 ) ;
for ( V_81 = 0 ; V_81 < V_5 -> V_22 ; V_81 ++ )
if ( ( V_80 [ V_81 ] . V_3 == V_5 -> V_26 ) &&
( V_80 [ V_81 ] . V_31 == V_5 -> V_24 ) )
return 0 ;
F_10 ( L_63 ) ;
return 0 ;
}
static int F_39 ( struct V_15 * V_5 )
{
struct V_98 * V_99 ;
unsigned int V_16 ;
T_1 V_100 ;
T_2 V_49 ;
T_1 V_101 = 0 ;
T_1 V_102 ;
for ( V_16 = 0xc0000 ; V_16 < 0xffff0 ; V_16 += 0x10 ) {
V_99 = F_40 ( V_16 ) ;
if ( memcmp ( V_99 , V_103 , V_104 ) != 0 )
continue;
F_10 ( L_64 , V_99 ) ;
F_10 ( L_65 , V_99 -> V_105 ) ;
if ( V_99 -> V_105 != V_106 ) {
F_18 (KERN_ERR FW_BUG PFX L_66 ) ;
return - V_64 ;
}
F_10 ( L_67 , V_99 -> V_107 ) ;
if ( V_99 -> V_107 ) {
F_18 (KERN_ERR FW_BUG PFX L_68 ) ;
return - V_64 ;
}
V_5 -> V_29 = V_99 -> V_29 ;
F_10 ( L_69 ,
V_5 -> V_29 ) ;
F_10 ( L_70 , V_99 -> V_108 ) ;
V_5 -> V_48 = V_99 -> V_108 & 3 ;
V_5 -> V_28 = ( ( V_99 -> V_108 ) >> 2 ) & 3 ;
V_100 = ( ( V_99 -> V_108 ) >> 4 ) & 3 ;
V_5 -> V_52 = 1 << V_100 ;
V_5 -> V_89 = ( ( V_99 -> V_108 ) >> 6 ) & 3 ;
F_10 ( L_71 , V_5 -> V_48 ) ;
F_10 ( L_72 , V_5 -> V_28 ) ;
F_10 ( L_73 , V_100 , V_5 -> V_52 ) ;
F_10 ( L_74 , V_99 -> V_109 ) ;
V_101 = V_99 -> V_109 ;
if ( ( V_99 -> F_29 == 0x00000fc0 ) ||
( V_99 -> F_29 == 0x00000fe0 ) ) {
V_102 = F_28 ( V_68 ) ;
if ( ( V_102 == 0x00000fc0 ) ||
( V_102 == 0x00000fe0 ) )
V_101 = 1 ;
}
if ( V_101 != 1 ) {
F_18 (KERN_ERR FW_BUG PFX L_75 ) ;
return - V_64 ;
}
V_5 -> V_39 = V_99 -> V_110 ;
F_10 ( L_76 , V_99 -> V_110 ) ;
F_10 ( L_77 , V_99 -> V_111 ) ;
F_10 ( L_78 , V_99 -> V_49 ) ;
V_49 = V_99 -> V_49 ;
V_5 -> V_22 = V_99 -> V_22 ;
F_10 ( L_79 , V_5 -> V_22 ) ;
return F_35 ( V_5 ,
(struct V_79 * ) ( V_99 + 1 ) , V_49 ) ;
}
F_18 (KERN_ERR FW_BUG PFX L_80 ) ;
F_18 (KERN_ERR PFX L_81
L_82 ) ;
return - V_64 ;
}
static void F_41 ( struct V_15 * V_5 ,
unsigned int V_95 )
{
T_3 V_112 ;
if ( ! V_5 -> V_113 . V_114 || ( V_11 == V_12 ) )
return;
V_112 = V_5 -> V_113 . V_115 [ V_95 ] . V_112 ;
V_5 -> V_28 = ( V_112 >> V_116 ) & V_117 ;
V_5 -> V_48 = ( V_112 >> V_118 ) & V_119 ;
V_5 -> V_120 = ( V_112 >> V_121 ) & V_122 ;
V_5 -> V_39 = ( V_112 >> V_123 ) & V_124 ;
V_5 -> V_52 = 1 << ( ( V_112 >> V_125 ) & V_126 ) ;
V_5 -> V_29 = ( V_112 >> V_127 ) & V_128 ;
}
static int F_42 ( struct V_15 * V_5 )
{
struct V_4 * V_86 ;
int V_129 = - V_64 ;
T_3 V_112 , V_130 ;
if ( F_43 ( & V_5 -> V_113 , V_5 -> V_2 ) ) {
F_10 ( L_83 ) ;
return - V_97 ;
}
if ( V_5 -> V_113 . V_114 <= 1 ) {
F_10 ( L_84 ) ;
goto V_131;
}
V_112 = V_5 -> V_113 . V_132 . V_133 ;
V_130 = V_5 -> V_113 . V_134 . V_133 ;
if ( ( V_112 != V_135 ) ||
( V_130 != V_135 ) ) {
F_10 ( L_85 ,
V_112 , V_130 ) ;
goto V_131;
}
V_86 = F_36 ( ( sizeof( struct V_4 )
* ( V_5 -> V_113 . V_114 + 1 ) ) , V_92 ) ;
if ( ! V_86 ) {
F_10 ( L_61 ) ;
goto V_131;
}
V_5 -> V_22 = V_5 -> V_113 . V_114 ;
F_41 ( V_5 , 0 ) ;
if ( V_11 == V_12 )
V_129 = F_44 ( V_5 , V_86 ) ;
else
V_129 = F_45 ( V_5 , V_86 ) ;
if ( V_129 )
goto V_136;
V_86 [ V_5 -> V_113 . V_114 ] . V_7 =
V_96 ;
V_86 [ V_5 -> V_113 . V_114 ] . V_95 = 0 ;
V_5 -> V_86 = V_86 ;
if ( F_38 ( F_1 ( V_5 -> V_2 ) ) == V_5 -> V_2 )
F_32 ( V_5 ) ;
F_46 ( V_137 ) ;
if ( ! F_47 ( & V_5 -> V_113 . V_138 , V_92 ) ) {
F_18 (KERN_ERR PFX
L_86 ) ;
V_129 = - V_93 ;
goto V_136;
}
return 0 ;
V_136:
F_37 ( V_86 ) ;
V_131:
F_48 ( & V_5 -> V_113 , V_5 -> V_2 ) ;
V_5 -> V_113 . V_114 = 0 ;
return V_129 ;
}
static int F_44 ( struct V_15 * V_5 ,
struct V_4 * V_86 )
{
int V_16 ;
T_1 V_10 = 0 , V_9 = 0 ;
F_8 ( V_139 , V_9 , V_10 ) ;
V_5 -> V_140 = ( V_9 & V_141 ) >> V_142 ;
for ( V_16 = 0 ; V_16 < V_5 -> V_113 . V_114 ; V_16 ++ ) {
T_1 V_95 ;
V_95 = V_5 -> V_113 . V_115 [ V_16 ] . V_112 & V_18 ;
if ( V_95 > V_5 -> V_140 ) {
F_18 (KERN_ERR PFX L_87
L_88 , i, index) ;
F_18 (KERN_ERR PFX L_89
L_90 ) ;
F_31 ( V_86 , V_16 ) ;
continue;
}
F_8 ( V_143 + V_95 , V_9 , V_10 ) ;
if ( ! ( V_10 & V_144 ) ) {
F_10 ( L_91 , V_95 ) ;
F_31 ( V_86 , V_16 ) ;
continue;
}
V_86 [ V_16 ] . V_95 = V_95 ;
if ( ( V_20 . V_21 == 0x10 && V_20 . V_145 < 10 )
|| V_20 . V_21 == 0x11 ) {
V_86 [ V_16 ] . V_7 =
F_33 ( V_9 & 0x3f , ( V_9 >> 6 ) & 7 ) ;
} else
V_86 [ V_16 ] . V_7 =
V_5 -> V_113 . V_115 [ V_16 ] . V_146 * 1000 ;
}
return 0 ;
}
static int F_45 ( struct V_15 * V_5 ,
struct V_4 * V_86 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_5 -> V_113 . V_114 ; V_16 ++ ) {
T_1 V_3 ;
T_1 V_31 ;
T_1 V_94 , V_95 ;
T_3 V_130 , V_112 ;
if ( V_5 -> V_120 ) {
V_130 = V_5 -> V_113 . V_115 [ V_16 ] . V_130 ;
V_3 = V_130 & V_147 ;
V_31 = ( V_130 >> V_148 ) & V_149 ;
} else {
V_112 = V_5 -> V_113 . V_115 [ V_16 ] . V_112 ;
V_3 = V_112 & V_150 ;
V_31 = ( V_112 >> V_148 ) & V_151 ;
}
F_10 ( L_92 , V_16 , V_3 , V_31 ) ;
V_95 = V_3 | ( V_31 << 8 ) ;
V_86 [ V_16 ] . V_95 = V_95 ;
V_94 = F_4 ( V_3 ) ;
V_86 [ V_16 ] . V_7 = V_94 ;
if ( ( V_94 > ( V_152 * 1000 ) ) || ( V_94 < ( V_153 * 1000 ) ) ) {
F_10 ( L_93 , V_94 ) ;
F_31 ( V_86 , V_16 ) ;
continue;
}
if ( V_31 == V_154 ) {
F_10 ( L_94 , V_31 ) ;
F_31 ( V_86 , V_16 ) ;
continue;
}
if ( V_94 != ( V_5 -> V_113 . V_115 [ V_16 ] . V_146 * 1000 ) ) {
F_18 (KERN_INFO PFX L_95
L_96 , freq,
(unsigned int)
(data->acpi_data.states[i].core_frequency
* 1000)) ;
F_31 ( V_86 , V_16 ) ;
continue;
}
}
return 0 ;
}
static void F_49 ( struct V_15 * V_5 )
{
if ( V_5 -> V_113 . V_114 )
F_48 ( & V_5 -> V_113 ,
V_5 -> V_2 ) ;
F_50 ( V_5 -> V_113 . V_138 ) ;
}
static int F_51 ( struct V_15 * V_5 )
{
int V_155 = 0 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_5 -> V_113 . V_114 ; V_16 ++ ) {
int V_156 = V_5 -> V_113 . V_115 [ V_16 ] . V_157
+ V_5 -> V_113 . V_115 [ V_16 ] . V_158 ;
if ( V_156 > V_155 )
V_155 = V_156 ;
}
if ( V_155 == 0 ) {
if ( V_20 . V_21 < 0x11 )
F_18 (KERN_ERR FW_WARN PFX L_97
L_98 ) ;
V_155 = 1 ;
}
return 1000 * V_155 ;
}
static int F_52 ( struct V_15 * V_5 ,
unsigned int V_95 )
{
T_1 V_3 = 0 ;
T_1 V_31 = 0 ;
int V_159 , V_16 ;
struct V_160 V_161 ;
F_10 ( L_99 , F_15 () , V_95 ) ;
V_3 = V_5 -> V_86 [ V_95 ] . V_95 & 0xFF ;
V_31 = ( V_5 -> V_86 [ V_95 ] . V_95 & 0xFF00 ) >> 8 ;
F_10 ( L_100 , V_3 , V_31 ) ;
if ( F_9 ( V_5 ) )
return 1 ;
if ( ( V_5 -> V_24 == V_31 ) && ( V_5 -> V_26 == V_3 ) ) {
F_10 ( L_101 ,
V_3 , V_31 ) ;
return 0 ;
}
F_10 ( L_102 ,
F_15 () , V_3 , V_31 ) ;
V_161 . V_162 = F_4 ( V_5 -> V_26 ) ;
V_161 . V_163 = F_4 ( V_3 ) ;
F_53 (i, data->available_cores) {
V_161 . V_2 = V_16 ;
F_54 ( & V_161 , V_164 ) ;
}
V_159 = F_22 ( V_5 , V_3 , V_31 ) ;
if ( V_159 )
return V_159 ;
V_161 . V_163 = F_4 ( V_5 -> V_26 ) ;
F_53 (i, data->available_cores) {
V_161 . V_2 = V_16 ;
F_54 ( & V_161 , V_165 ) ;
}
return V_159 ;
}
static int F_55 ( struct V_15 * V_5 ,
unsigned int V_95 )
{
T_1 V_6 = 0 ;
int V_159 , V_16 ;
struct V_160 V_161 ;
F_10 ( L_99 , F_15 () , V_95 ) ;
V_6 = V_95 & V_18 ;
if ( V_6 > V_5 -> V_140 )
return - V_84 ;
V_161 . V_162 = F_5 ( V_5 -> V_86 ,
V_5 -> V_19 ) ;
V_161 . V_163 = F_5 ( V_5 -> V_86 , V_6 ) ;
F_53 (i, data->available_cores) {
V_161 . V_2 = V_16 ;
F_54 ( & V_161 , V_164 ) ;
}
V_159 = F_21 ( V_5 , V_6 ) ;
V_161 . V_163 = F_5 ( V_5 -> V_86 , V_6 ) ;
F_53 (i, data->available_cores) {
V_161 . V_2 = V_16 ;
F_54 ( & V_161 , V_165 ) ;
}
return V_159 ;
}
static int F_56 ( struct V_166 * V_167 ,
unsigned V_168 , unsigned V_169 )
{
T_4 V_170 ;
struct V_15 * V_5 = F_57 ( V_171 , V_167 -> V_2 ) ;
T_1 V_172 ;
T_1 V_173 ;
unsigned int V_174 ;
int V_175 = - V_97 ;
if ( ! V_5 )
return - V_84 ;
V_172 = V_5 -> V_26 ;
V_173 = V_5 -> V_24 ;
if ( ! F_58 ( & V_170 , V_92 ) )
return - V_93 ;
F_59 ( V_170 , F_60 ( V_176 ) ) ;
F_61 ( V_176 , F_2 ( V_167 -> V_2 ) ) ;
if ( F_15 () != V_167 -> V_2 ) {
F_18 (KERN_ERR PFX L_103 , pol->cpu) ;
goto V_131;
}
if ( F_7 () ) {
F_18 (KERN_ERR PFX L_104 ) ;
goto V_131;
}
F_10 ( L_105 ,
V_167 -> V_2 , V_168 , V_167 -> V_177 , V_167 -> V_178 , V_169 ) ;
if ( F_9 ( V_5 ) )
goto V_131;
if ( V_11 != V_12 ) {
F_10 ( L_106 ,
V_5 -> V_26 , V_5 -> V_24 ) ;
if ( ( V_173 != V_5 -> V_24 ) ||
( V_172 != V_5 -> V_26 ) ) {
F_18 (KERN_INFO PFX
L_107
L_108 ,
checkfid, data->currfid,
checkvid, data->currvid) ;
}
}
if ( F_62 ( V_167 , V_5 -> V_86 ,
V_168 , V_169 , & V_174 ) )
goto V_131;
F_63 ( & V_179 ) ;
F_41 ( V_5 , V_174 ) ;
if ( V_11 == V_12 )
V_175 = F_55 ( V_5 , V_174 ) ;
else
V_175 = F_52 ( V_5 , V_174 ) ;
if ( V_175 ) {
F_18 (KERN_ERR PFX L_109 ) ;
V_175 = 1 ;
F_64 ( & V_179 ) ;
goto V_131;
}
F_64 ( & V_179 ) ;
if ( V_11 == V_12 )
V_167 -> V_180 = F_5 ( V_5 -> V_86 ,
V_174 ) ;
else
V_167 -> V_180 = F_4 ( V_5 -> V_26 ) ;
V_175 = 0 ;
V_131:
F_61 ( V_176 , V_170 ) ;
F_50 ( V_170 ) ;
return V_175 ;
}
static int F_65 ( struct V_166 * V_167 )
{
struct V_15 * V_5 = F_57 ( V_171 , V_167 -> V_2 ) ;
if ( ! V_5 )
return - V_84 ;
return F_66 ( V_167 , V_5 -> V_86 ) ;
}
static void T_5 F_67 ( void * V_181 )
{
struct V_182 * V_182 = V_181 ;
if ( F_7 () ) {
F_18 (KERN_ERR PFX L_110 ) ;
V_182 -> V_63 = - V_64 ;
return;
}
if ( F_9 ( V_182 -> V_5 ) ) {
V_182 -> V_63 = - V_64 ;
return;
}
if ( V_11 == V_183 )
F_14 () ;
V_182 -> V_63 = 0 ;
}
static int T_5 F_68 ( struct V_166 * V_167 )
{
static const char V_184 [] =
V_185 V_186 V_187 L_111
V_186 V_187 L_112 ;
struct V_15 * V_5 ;
struct V_182 V_182 ;
int V_63 ;
struct V_188 * V_189 = & F_69 ( V_167 -> V_2 ) ;
if ( ! F_70 ( V_167 -> V_2 ) )
return - V_64 ;
F_71 ( V_167 -> V_2 , F_26 , & V_63 , 1 ) ;
if ( V_63 )
return - V_64 ;
V_5 = F_72 ( sizeof( struct V_15 ) , V_92 ) ;
if ( ! V_5 ) {
F_18 (KERN_ERR PFX L_113 ) ;
return - V_93 ;
}
V_5 -> V_2 = V_167 -> V_2 ;
V_5 -> V_19 = V_190 ;
if ( F_42 ( V_5 ) ) {
if ( F_73 () != 1 ) {
F_74 ( V_184 ) ;
goto V_131;
}
if ( V_167 -> V_2 != 0 ) {
F_18 (KERN_ERR FW_BUG PFX L_114
L_115
L_116 ) ;
goto V_131;
}
V_63 = F_39 ( V_5 ) ;
if ( V_63 )
goto V_131;
V_167 -> V_191 . V_157 = (
( ( V_5 -> V_48 + 8 ) * V_5 -> V_29 * V_30 ) +
( ( 1 << V_5 -> V_28 ) * 30 ) ) * 1000 ;
} else
V_167 -> V_191 . V_157 = F_51 ( V_5 ) ;
V_182 . V_5 = V_5 ;
F_71 ( V_5 -> V_2 , F_67 ,
& V_182 , 1 ) ;
V_63 = V_182 . V_63 ;
if ( V_63 != 0 )
goto V_192;
if ( V_11 == V_12 )
F_59 ( V_167 -> V_193 , F_2 ( V_167 -> V_2 ) ) ;
else
F_59 ( V_167 -> V_193 , F_1 ( V_167 -> V_2 ) ) ;
V_5 -> V_194 = V_167 -> V_193 ;
if ( V_11 == V_12 )
V_167 -> V_180 = F_5 ( V_5 -> V_86 ,
V_5 -> V_19 ) ;
else
V_167 -> V_180 = F_4 ( V_5 -> V_26 ) ;
F_10 ( L_117 , V_167 -> V_180 ) ;
if ( F_75 ( V_167 , V_5 -> V_86 ) ) {
F_18 (KERN_ERR FW_BUG PFX L_118 ) ;
F_49 ( V_5 ) ;
F_37 ( V_5 -> V_86 ) ;
F_37 ( V_5 ) ;
return - V_84 ;
}
if ( F_76 ( V_189 , V_195 ) )
V_196 . V_197 = V_198 ;
F_77 ( V_5 -> V_86 , V_167 -> V_2 ) ;
if ( V_11 == V_12 )
F_10 ( L_119 ,
V_5 -> V_19 ) ;
else
F_10 ( L_120 ,
V_5 -> V_26 , V_5 -> V_24 ) ;
F_57 ( V_171 , V_167 -> V_2 ) = V_5 ;
return 0 ;
V_192:
F_49 ( V_5 ) ;
V_131:
F_37 ( V_5 ) ;
return - V_64 ;
}
static int T_6 F_78 ( struct V_166 * V_167 )
{
struct V_15 * V_5 = F_57 ( V_171 , V_167 -> V_2 ) ;
if ( ! V_5 )
return - V_84 ;
F_49 ( V_5 ) ;
F_79 ( V_167 -> V_2 ) ;
F_37 ( V_5 -> V_86 ) ;
F_37 ( V_5 ) ;
F_57 ( V_171 , V_167 -> V_2 ) = NULL ;
return 0 ;
}
static void F_80 ( void * V_199 )
{
int * V_200 = V_199 ;
struct V_15 * V_5 = F_27 ( V_171 ) ;
* V_200 = F_9 ( V_5 ) ;
}
static unsigned int F_81 ( unsigned int V_2 )
{
struct V_15 * V_5 = F_57 ( V_171 , V_2 ) ;
unsigned int V_201 = 0 ;
int V_200 ;
if ( ! V_5 )
return 0 ;
F_71 ( V_2 , F_80 , & V_200 , true ) ;
if ( V_200 )
goto V_202;
if ( V_11 == V_12 )
V_201 = F_5 ( V_5 -> V_86 ,
V_5 -> V_19 ) ;
else
V_201 = F_4 ( V_5 -> V_26 ) ;
V_202:
return V_201 ;
}
static void F_82 ( bool V_203 )
{
int V_2 ;
F_83 () ;
F_84 ( V_204 , V_205 , V_206 ) ;
F_53 (cpu, cpu_online_mask) {
struct V_207 * V_208 = F_85 ( V_206 , V_2 ) ;
if ( V_203 )
V_208 -> V_209 &= ~ F_86 ( 25 ) ;
else
V_208 -> V_209 |= F_86 ( 25 ) ;
}
F_87 ( V_204 , V_205 , V_206 ) ;
F_88 () ;
}
static void F_89 ( bool V_203 )
{
if ( ! V_210 )
return;
if ( V_203 && ! V_211 ) {
V_211 = true ;
F_82 ( V_203 ) ;
F_18 (KERN_INFO PFX L_121 ) ;
} else if ( ! V_203 && V_211 ) {
V_211 = false ;
F_82 ( V_203 ) ;
F_18 (KERN_INFO PFX L_122 ) ;
}
}
static T_7 F_90 ( struct V_166 * V_212 , const char * V_213 ,
T_8 V_214 )
{
int V_175 = - V_84 ;
unsigned long V_215 = 0 ;
V_175 = F_91 ( V_213 , 10 , & V_215 ) ;
if ( ! V_175 && ( V_215 == 0 || V_215 == 1 ) && V_210 )
F_89 ( V_215 ) ;
else
return - V_84 ;
return V_214 ;
}
static T_7 F_92 ( struct V_166 * V_212 , char * V_213 )
{
return sprintf ( V_213 , L_123 , V_211 ) ;
}
static int F_93 ( struct V_216 * V_217 , unsigned long V_218 ,
void * V_219 )
{
unsigned V_2 = ( long ) V_219 ;
T_1 V_9 , V_10 ;
switch ( V_218 ) {
case V_220 :
case V_221 :
if ( ! V_211 ) {
F_94 ( V_2 , V_205 , & V_9 , & V_10 ) ;
V_9 |= F_86 ( 25 ) ;
F_95 ( V_2 , V_205 , V_9 , V_10 ) ;
}
break;
case V_222 :
case V_223 :
F_94 ( V_2 , V_205 , & V_9 , & V_10 ) ;
V_9 &= ~ F_86 ( 25 ) ;
F_95 ( V_2 , V_205 , V_9 , V_10 ) ;
break;
default:
break;
}
return V_224 ;
}
static int T_5 F_96 ( void )
{
unsigned int V_16 , V_225 = 0 , V_2 ;
int V_226 ;
F_97 (i) {
int V_63 ;
F_71 ( V_16 , F_26 , & V_63 , 1 ) ;
if ( V_63 == 0 )
V_225 ++ ;
}
if ( V_225 != F_73 () )
return - V_64 ;
F_18 (KERN_INFO PFX L_124 VERSION L_125 ,
num_online_nodes(), boot_cpu_data.x86_model_id, supported_cpus) ;
if ( F_98 ( V_227 ) ) {
V_210 = true ;
V_206 = F_99 () ;
if ( ! V_206 ) {
F_18 ( V_185 L_126 , V_228 ) ;
return - V_93 ;
}
F_100 ( & V_229 ) ;
F_84 ( V_204 , V_205 , V_206 ) ;
F_53 (cpu, cpu_online_mask) {
struct V_207 * V_208 = F_85 ( V_206 , V_2 ) ;
V_211 |= ! ( ! ! ( V_208 -> V_209 & F_86 ( 25 ) ) ) ;
}
F_18 (KERN_INFO PFX L_127 ,
(cpb_enabled ? L_128 : L_129)) ;
}
V_226 = F_101 ( & V_196 ) ;
if ( V_226 < 0 && F_98 ( V_227 ) ) {
F_102 ( & V_229 ) ;
F_103 ( V_206 ) ;
V_206 = NULL ;
}
return V_226 ;
}
static void T_9 F_104 ( void )
{
F_10 ( L_130 ) ;
if ( F_98 ( V_227 ) ) {
F_103 ( V_206 ) ;
V_206 = NULL ;
F_102 ( & V_229 ) ;
}
F_105 ( & V_196 ) ;
}
