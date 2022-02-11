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
static T_1 F_5 ( T_1 V_3 )
{
if ( V_3 < V_4 )
return 8 + ( 2 * V_3 ) ;
else
return V_3 ;
}
static int F_6 ( void )
{
T_1 V_5 , V_6 ;
F_7 ( V_7 , V_5 , V_6 ) ;
return V_5 & V_8 ? 1 : 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
T_1 V_5 , V_6 ;
T_1 V_11 = 0 ;
do {
if ( V_11 ++ > 10000 ) {
F_9 ( L_1 ) ;
return 1 ;
}
F_7 ( V_7 , V_5 , V_6 ) ;
} while ( V_5 & V_8 );
V_10 -> V_12 = V_6 & V_13 ;
V_10 -> V_14 = V_5 & V_15 ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
F_11 ( ( 1 << V_10 -> V_16 ) * 10 ) ;
return;
}
static void F_12 ( struct V_9 * V_10 )
{
F_11 ( V_10 -> V_17 * V_18 ) ;
return;
}
static void F_13 ( void )
{
T_1 V_5 , V_6 ;
T_2 V_3 , V_19 ;
F_7 ( V_7 , V_5 , V_6 ) ;
V_19 = V_6 & V_13 ;
V_3 = V_5 & V_15 ;
V_5 = V_3 | ( V_19 << V_20 ) ;
V_6 = V_21 ;
F_9 ( L_2 , F_14 () , V_5 , V_6 ) ;
F_15 ( V_22 , V_5 , V_6 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_1 V_3 )
{
T_1 V_5 ;
T_1 V_23 = V_10 -> V_12 ;
T_1 V_11 = 0 ;
if ( ( V_3 & V_24 ) || ( V_10 -> V_12 & V_25 ) ) {
F_17 (KERN_ERR PFX L_3 ) ;
return 1 ;
}
V_5 = V_3 ;
V_5 |= ( V_10 -> V_12 << V_20 ) ;
V_5 |= V_26 ;
F_9 ( L_4 ,
V_3 , V_5 , V_10 -> V_27 * V_28 ) ;
do {
F_15 ( V_22 , V_5 , V_10 -> V_27 * V_28 ) ;
if ( V_11 ++ > 100 ) {
F_17 (KERN_ERR PFX
L_5
L_6 ) ;
return 1 ;
}
} while ( F_8 ( V_10 ) );
F_10 ( V_10 ) ;
if ( V_23 != V_10 -> V_12 ) {
F_17 (KERN_ERR PFX
L_7 ,
savevid, data->currvid) ;
return 1 ;
}
if ( V_3 != V_10 -> V_14 ) {
F_17 (KERN_ERR PFX
L_8 , fid,
data->currfid) ;
return 1 ;
}
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , T_1 V_19 )
{
T_1 V_5 ;
T_1 V_29 = V_10 -> V_14 ;
int V_11 = 0 ;
if ( ( V_10 -> V_14 & V_24 ) || ( V_19 & V_25 ) ) {
F_17 (KERN_ERR PFX L_9 ) ;
return 1 ;
}
V_5 = V_10 -> V_14 ;
V_5 |= ( V_19 << V_20 ) ;
V_5 |= V_26 ;
F_9 ( L_10 ,
V_19 , V_5 , V_30 ) ;
do {
F_15 ( V_22 , V_5 , V_30 ) ;
if ( V_11 ++ > 100 ) {
F_17 (KERN_ERR PFX L_11
L_12
L_13 ) ;
return 1 ;
}
} while ( F_8 ( V_10 ) );
if ( V_29 != V_10 -> V_14 ) {
F_17 (KERN_ERR PFX L_14
L_15 ,
savefid, data->currfid) ;
return 1 ;
}
if ( V_19 != V_10 -> V_12 ) {
F_17 (KERN_ERR PFX L_16
L_17 ,
vid, data->currvid) ;
return 1 ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 ,
T_1 V_31 , T_1 V_32 )
{
if ( ( V_10 -> V_12 - V_31 ) > V_32 )
V_31 = V_10 -> V_12 - V_32 ;
if ( F_18 ( V_10 , V_31 ) )
return 1 ;
F_12 ( V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 ,
T_1 V_33 , T_1 V_31 )
{
if ( F_21 ( V_10 , V_31 , V_33 ) )
return 1 ;
if ( F_22 ( V_10 , V_33 ) )
return 1 ;
if ( F_23 ( V_10 , V_31 ) )
return 1 ;
if ( F_8 ( V_10 ) )
return 1 ;
if ( ( V_33 != V_10 -> V_14 ) || ( V_31 != V_10 -> V_12 ) ) {
F_17 (KERN_ERR PFX L_18
L_19 ,
smp_processor_id(),
reqfid, reqvid, data->currfid, data->currvid) ;
return 1 ;
}
F_9 ( L_20 ,
F_14 () , V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
T_1 V_31 , T_1 V_33 )
{
T_1 V_34 = V_10 -> V_35 ;
T_1 V_29 = V_10 -> V_14 ;
T_1 V_36 , V_5 , V_37 = 1 ;
F_9 ( L_21
L_22 ,
F_14 () ,
V_10 -> V_14 , V_10 -> V_12 , V_31 , V_10 -> V_35 ) ;
if ( ( V_29 < V_38 ) && ( V_33 < V_38 ) )
V_37 = 2 ;
V_34 *= V_37 ;
F_7 ( V_7 , V_5 , V_36 ) ;
V_36 = 0x1f & ( V_36 >> 16 ) ;
F_9 ( L_23 , V_36 ) ;
if ( V_31 < V_36 )
V_31 = V_36 ;
while ( V_10 -> V_12 > V_31 ) {
F_9 ( L_24 ,
V_10 -> V_12 , V_31 ) ;
if ( F_19 ( V_10 , V_31 , V_10 -> V_39 ) )
return 1 ;
}
while ( ( V_34 > 0 ) &&
( ( V_37 * V_10 -> V_35 + V_10 -> V_12 ) > V_31 ) ) {
if ( V_10 -> V_12 == V_36 ) {
V_34 = 0 ;
} else {
F_9 ( L_25 ,
V_10 -> V_12 - 1 ) ;
if ( F_19 ( V_10 , V_10 -> V_12 - 1 , 1 ) )
return 1 ;
V_34 -- ;
}
}
if ( F_8 ( V_10 ) )
return 1 ;
if ( V_29 != V_10 -> V_14 ) {
F_17 (KERN_ERR PFX L_26 ,
data->currfid) ;
return 1 ;
}
F_9 ( L_27 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , T_1 V_33 )
{
T_1 V_40 , V_41 , V_42 ;
T_1 V_43 , V_23 = V_10 -> V_12 ;
if ( V_10 -> V_14 == V_33 ) {
F_17 (KERN_ERR PFX L_28 ,
data->currfid) ;
return 0 ;
}
F_9 ( L_29
L_30 ,
F_14 () ,
V_10 -> V_14 , V_10 -> V_12 , V_33 ) ;
V_40 = F_5 ( V_33 ) ;
V_41 = F_5 ( V_10 -> V_14 ) ;
V_42 = V_41 > V_40 ? V_41 - V_40
: V_40 - V_41 ;
if ( ( V_33 <= V_38 ) && ( V_10 -> V_14 <= V_38 ) )
V_42 = 0 ;
while ( V_42 > 2 ) {
( V_10 -> V_14 & 1 ) ? ( V_43 = 1 ) : ( V_43 = 2 ) ;
if ( V_33 > V_10 -> V_14 ) {
if ( V_10 -> V_14 > V_38 ) {
if ( F_16 ( V_10 ,
V_10 -> V_14 + V_43 ) )
return 1 ;
} else {
if ( F_16
( V_10 ,
2 + F_5 ( V_10 -> V_14 ) ) )
return 1 ;
}
} else {
if ( F_16 ( V_10 , V_10 -> V_14 - V_43 ) )
return 1 ;
}
V_41 = F_5 ( V_10 -> V_14 ) ;
V_42 = V_41 > V_40 ? V_41 - V_40
: V_40 - V_41 ;
}
if ( F_16 ( V_10 , V_33 ) )
return 1 ;
if ( F_8 ( V_10 ) )
return 1 ;
if ( V_10 -> V_14 != V_33 ) {
F_17 (KERN_ERR PFX
L_31
L_32 ,
data->currfid, reqfid) ;
return 1 ;
}
if ( V_23 != V_10 -> V_12 ) {
F_17 (KERN_ERR PFX L_33 ,
savevid, data->currvid) ;
return 1 ;
}
F_9 ( L_34 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_9 * V_10 ,
T_1 V_31 )
{
T_1 V_29 = V_10 -> V_14 ;
T_1 V_44 = V_31 ;
F_9 ( L_35 ,
F_14 () ,
V_10 -> V_14 , V_10 -> V_12 ) ;
if ( V_31 != V_10 -> V_12 ) {
if ( F_18 ( V_10 , V_31 ) )
return 1 ;
if ( V_29 != V_10 -> V_14 ) {
F_17 (KERN_ERR PFX
L_36 ,
savefid, data->currfid) ;
return 1 ;
}
if ( V_10 -> V_12 != V_31 ) {
F_17 (KERN_ERR PFX
L_37
L_38 ,
reqvid, data->currvid) ;
return 1 ;
}
}
if ( F_8 ( V_10 ) )
return 1 ;
if ( V_44 != V_10 -> V_12 ) {
F_9 ( L_39 , V_10 -> V_12 ) ;
return 1 ;
}
if ( V_29 != V_10 -> V_14 ) {
F_9 ( L_40 ,
V_10 -> V_14 ) ;
return 1 ;
}
F_9 ( L_41 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static void F_24 ( void * V_45 )
{
T_1 V_46 , V_47 , V_48 , V_49 ;
int * V_50 = V_45 ;
* V_50 = - V_51 ;
V_46 = F_25 ( V_52 ) ;
if ( ( V_46 & V_53 ) == V_54 ) {
if ( ( ( V_46 & V_55 ) != V_55 ) ||
( ( V_46 & V_56 ) > V_57 ) ) {
F_17 (KERN_INFO PFX
L_42 , eax) ;
return;
}
V_46 = F_25 ( V_58 ) ;
if ( V_46 < V_59 ) {
F_17 (KERN_INFO PFX
L_43 ) ;
return;
}
F_26 ( V_59 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( ( V_49 & V_60 )
!= V_60 ) {
F_17 (KERN_INFO PFX
L_44 ) ;
return;
}
* V_50 = 0 ;
}
}
static int F_27 ( struct V_9 * V_10 , struct V_61 * V_62 ,
T_2 V_36 )
{
unsigned int V_63 ;
T_2 V_64 = 0xff ;
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( V_62 [ V_63 ] . V_19 > V_66 ) {
F_17 (KERN_ERR FW_BUG PFX L_45 ,
j, pst[j].vid) ;
return - V_67 ;
}
if ( V_62 [ V_63 ] . V_19 < V_10 -> V_35 ) {
F_17 (KERN_ERR FW_BUG PFX L_46
L_47 , j) ;
return - V_51 ;
}
if ( V_62 [ V_63 ] . V_19 < V_36 + V_10 -> V_35 ) {
F_17 (KERN_ERR FW_BUG PFX L_48
L_47 , j) ;
return - V_51 ;
}
if ( V_62 [ V_63 ] . V_3 > V_68 ) {
F_17 (KERN_ERR FW_BUG PFX L_49
L_47 , j) ;
return - V_51 ;
}
if ( V_63 && ( V_62 [ V_63 ] . V_3 < V_4 ) ) {
F_17 (KERN_ERR FW_BUG PFX L_50
L_51 , j, pst[j].fid) ;
return - V_67 ;
}
if ( V_62 [ V_63 ] . V_3 < V_64 )
V_64 = V_62 [ V_63 ] . V_3 ;
}
if ( V_64 & 1 ) {
F_17 (KERN_ERR FW_BUG PFX L_52 ) ;
return - V_67 ;
}
if ( V_64 > V_38 )
F_17 (KERN_INFO FW_BUG PFX
L_53 ) ;
return 0 ;
}
static void F_28 ( struct V_69 * V_70 ,
unsigned int V_71 )
{
V_70 [ V_71 ] . V_72 = V_73 ;
}
static void F_29 ( struct V_9 * V_10 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( V_10 -> V_70 [ V_63 ] . V_72 !=
V_73 ) {
F_17 (KERN_INFO PFX
L_54 ,
data->powernow_table[j].index & 0xff ,
data->powernow_table[j].frequency/1000 ,
data->powernow_table[j].index >> 8 ) ;
}
}
if ( V_10 -> V_74 )
F_17 (KERN_INFO PFX L_55 ,
data->batps) ;
}
static int F_30 ( struct V_9 * V_10 ,
struct V_61 * V_62 , T_2 V_36 )
{
struct V_69 * V_70 ;
unsigned int V_63 ;
if ( V_10 -> V_74 ) {
F_17 (KERN_WARNING PFX
L_56
L_57 , data->batps) ;
V_10 -> V_65 = V_10 -> V_74 ;
}
for ( V_63 = 1 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( V_62 [ V_63 - 1 ] . V_3 >= V_62 [ V_63 ] . V_3 ) {
F_17 (KERN_ERR PFX L_58 ) ;
return - V_67 ;
}
}
if ( V_10 -> V_65 < 2 ) {
F_17 (KERN_ERR PFX L_59 ) ;
return - V_51 ;
}
if ( F_27 ( V_10 , V_62 , V_36 ) )
return - V_67 ;
V_70 = F_31 ( ( sizeof( struct V_69 )
* ( V_10 -> V_65 + 1 ) ) , V_75 ) ;
if ( ! V_70 ) {
F_17 (KERN_ERR PFX L_60 ) ;
return - V_76 ;
}
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
int V_77 ;
V_70 [ V_63 ] . V_78 = V_62 [ V_63 ] . V_3 ;
V_70 [ V_63 ] . V_78 |= ( V_62 [ V_63 ] . V_19 << 8 ) ;
V_77 = F_4 ( V_62 [ V_63 ] . V_3 ) ;
V_70 [ V_63 ] . V_72 = V_77 ;
}
V_70 [ V_10 -> V_65 ] . V_72 = V_79 ;
V_70 [ V_10 -> V_65 ] . V_78 = 0 ;
if ( F_8 ( V_10 ) ) {
F_32 ( V_70 ) ;
return - V_80 ;
}
F_9 ( L_61 , V_10 -> V_14 , V_10 -> V_12 ) ;
V_10 -> V_70 = V_70 ;
if ( F_33 ( F_1 ( V_10 -> V_2 ) ) == V_10 -> V_2 )
F_29 ( V_10 ) ;
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ )
if ( ( V_62 [ V_63 ] . V_3 == V_10 -> V_14 ) &&
( V_62 [ V_63 ] . V_19 == V_10 -> V_12 ) )
return 0 ;
F_9 ( L_62 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_81 * V_82 ;
unsigned int V_11 ;
T_1 V_83 ;
T_2 V_36 ;
T_1 V_84 = 0 ;
T_1 V_85 ;
for ( V_11 = 0xc0000 ; V_11 < 0xffff0 ; V_11 += 0x10 ) {
V_82 = F_35 ( V_11 ) ;
if ( memcmp ( V_82 , V_86 , V_87 ) != 0 )
continue;
F_9 ( L_63 , V_82 ) ;
F_9 ( L_64 , V_82 -> V_88 ) ;
if ( V_82 -> V_88 != V_89 ) {
F_17 (KERN_ERR FW_BUG PFX L_65 ) ;
return - V_51 ;
}
F_9 ( L_66 , V_82 -> V_90 ) ;
if ( V_82 -> V_90 ) {
F_17 (KERN_ERR FW_BUG PFX L_67 ) ;
return - V_51 ;
}
V_10 -> V_17 = V_82 -> V_17 ;
F_9 ( L_68 ,
V_10 -> V_17 ) ;
F_9 ( L_69 , V_82 -> V_91 ) ;
V_10 -> V_35 = V_82 -> V_91 & 3 ;
V_10 -> V_16 = ( ( V_82 -> V_91 ) >> 2 ) & 3 ;
V_83 = ( ( V_82 -> V_91 ) >> 4 ) & 3 ;
V_10 -> V_39 = 1 << V_83 ;
V_10 -> V_74 = ( ( V_82 -> V_91 ) >> 6 ) & 3 ;
F_9 ( L_70 , V_10 -> V_35 ) ;
F_9 ( L_71 , V_10 -> V_16 ) ;
F_9 ( L_72 , V_83 , V_10 -> V_39 ) ;
F_9 ( L_73 , V_82 -> V_92 ) ;
V_84 = V_82 -> V_92 ;
if ( ( V_82 -> F_26 == 0x00000fc0 ) ||
( V_82 -> F_26 == 0x00000fe0 ) ) {
V_85 = F_25 ( V_52 ) ;
if ( ( V_85 == 0x00000fc0 ) ||
( V_85 == 0x00000fe0 ) )
V_84 = 1 ;
}
if ( V_84 != 1 ) {
F_17 (KERN_ERR FW_BUG PFX L_74 ) ;
return - V_51 ;
}
V_10 -> V_27 = V_82 -> V_93 ;
F_9 ( L_75 , V_82 -> V_93 ) ;
F_9 ( L_76 , V_82 -> V_94 ) ;
F_9 ( L_77 , V_82 -> V_36 ) ;
V_36 = V_82 -> V_36 ;
V_10 -> V_65 = V_82 -> V_65 ;
F_9 ( L_78 , V_10 -> V_65 ) ;
return F_30 ( V_10 ,
(struct V_61 * ) ( V_82 + 1 ) , V_36 ) ;
}
F_17 (KERN_ERR FW_BUG PFX L_79 ) ;
F_17 (KERN_ERR PFX L_80
L_81 ) ;
return - V_51 ;
}
static void F_36 ( struct V_9 * V_10 ,
unsigned int V_78 )
{
T_3 V_95 ;
if ( ! V_10 -> V_96 . V_97 )
return;
V_95 = V_10 -> V_96 . V_98 [ V_78 ] . V_95 ;
V_10 -> V_16 = ( V_95 >> V_99 ) & V_100 ;
V_10 -> V_35 = ( V_95 >> V_101 ) & V_102 ;
V_10 -> V_103 = ( V_95 >> V_104 ) & V_105 ;
V_10 -> V_27 = ( V_95 >> V_106 ) & V_107 ;
V_10 -> V_39 = 1 << ( ( V_95 >> V_108 ) & V_109 ) ;
V_10 -> V_17 = ( V_95 >> V_110 ) & V_111 ;
}
static int F_37 ( struct V_9 * V_10 )
{
struct V_69 * V_70 ;
int V_112 = - V_51 ;
T_3 V_95 , V_113 ;
if ( F_38 ( & V_10 -> V_96 , V_10 -> V_2 ) ) {
F_9 ( L_82 ) ;
return - V_80 ;
}
if ( V_10 -> V_96 . V_97 <= 1 ) {
F_9 ( L_83 ) ;
goto V_114;
}
V_95 = V_10 -> V_96 . V_115 . V_116 ;
V_113 = V_10 -> V_96 . V_117 . V_116 ;
if ( ( V_95 != V_118 ) ||
( V_113 != V_118 ) ) {
F_9 ( L_84 ,
V_95 , V_113 ) ;
goto V_114;
}
V_70 = F_31 ( ( sizeof( struct V_69 )
* ( V_10 -> V_96 . V_97 + 1 ) ) , V_75 ) ;
if ( ! V_70 ) {
F_9 ( L_60 ) ;
goto V_114;
}
V_10 -> V_65 = V_10 -> V_96 . V_97 ;
F_36 ( V_10 , 0 ) ;
V_112 = F_39 ( V_10 , V_70 ) ;
if ( V_112 )
goto V_119;
V_70 [ V_10 -> V_96 . V_97 ] . V_72 =
V_79 ;
V_70 [ V_10 -> V_96 . V_97 ] . V_78 = 0 ;
V_10 -> V_70 = V_70 ;
if ( F_33 ( F_1 ( V_10 -> V_2 ) ) == V_10 -> V_2 )
F_29 ( V_10 ) ;
F_40 ( V_120 ) ;
if ( ! F_41 ( & V_10 -> V_96 . V_121 , V_75 ) ) {
F_17 (KERN_ERR PFX
L_85 ) ;
V_112 = - V_76 ;
goto V_119;
}
return 0 ;
V_119:
F_32 ( V_70 ) ;
V_114:
F_42 ( & V_10 -> V_96 , V_10 -> V_2 ) ;
V_10 -> V_96 . V_97 = 0 ;
return V_112 ;
}
static int F_39 ( struct V_9 * V_10 ,
struct V_69 * V_70 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_96 . V_97 ; V_11 ++ ) {
T_1 V_3 ;
T_1 V_19 ;
T_1 V_77 , V_78 ;
T_3 V_113 , V_95 ;
if ( V_10 -> V_103 ) {
V_113 = V_10 -> V_96 . V_98 [ V_11 ] . V_113 ;
V_3 = V_113 & V_122 ;
V_19 = ( V_113 >> V_123 ) & V_124 ;
} else {
V_95 = V_10 -> V_96 . V_98 [ V_11 ] . V_95 ;
V_3 = V_95 & V_125 ;
V_19 = ( V_95 >> V_123 ) & V_126 ;
}
F_9 ( L_86 , V_11 , V_3 , V_19 ) ;
V_78 = V_3 | ( V_19 << 8 ) ;
V_70 [ V_11 ] . V_78 = V_78 ;
V_77 = F_4 ( V_3 ) ;
V_70 [ V_11 ] . V_72 = V_77 ;
if ( ( V_77 > ( V_127 * 1000 ) ) || ( V_77 < ( V_128 * 1000 ) ) ) {
F_9 ( L_87 , V_77 ) ;
F_28 ( V_70 , V_11 ) ;
continue;
}
if ( V_19 == V_129 ) {
F_9 ( L_88 , V_19 ) ;
F_28 ( V_70 , V_11 ) ;
continue;
}
if ( V_77 != ( V_10 -> V_96 . V_98 [ V_11 ] . V_130 * 1000 ) ) {
F_17 (KERN_INFO PFX L_89
L_90 , freq,
(unsigned int)
(data->acpi_data.states[i].core_frequency
* 1000)) ;
F_28 ( V_70 , V_11 ) ;
continue;
}
}
return 0 ;
}
static void F_43 ( struct V_9 * V_10 )
{
if ( V_10 -> V_96 . V_97 )
F_42 ( & V_10 -> V_96 ,
V_10 -> V_2 ) ;
F_44 ( V_10 -> V_96 . V_121 ) ;
}
static int F_45 ( struct V_9 * V_10 )
{
int V_131 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_96 . V_97 ; V_11 ++ ) {
int V_132 = V_10 -> V_96 . V_98 [ V_11 ] . V_133
+ V_10 -> V_96 . V_98 [ V_11 ] . V_134 ;
if ( V_132 > V_131 )
V_131 = V_132 ;
}
if ( V_131 == 0 ) {
F_46 (FW_WARN PFX L_91 ) ;
V_131 = 1 ;
}
return 1000 * V_131 ;
}
static int F_47 ( struct V_9 * V_10 ,
unsigned int V_78 )
{
T_1 V_3 = 0 ;
T_1 V_19 = 0 ;
int V_135 , V_11 ;
struct V_136 V_137 ;
F_9 ( L_92 , F_14 () , V_78 ) ;
V_3 = V_10 -> V_70 [ V_78 ] . V_78 & 0xFF ;
V_19 = ( V_10 -> V_70 [ V_78 ] . V_78 & 0xFF00 ) >> 8 ;
F_9 ( L_93 , V_3 , V_19 ) ;
if ( F_8 ( V_10 ) )
return 1 ;
if ( ( V_10 -> V_12 == V_19 ) && ( V_10 -> V_14 == V_3 ) ) {
F_9 ( L_94 ,
V_3 , V_19 ) ;
return 0 ;
}
F_9 ( L_95 ,
F_14 () , V_3 , V_19 ) ;
V_137 . V_138 = F_4 ( V_10 -> V_14 ) ;
V_137 . V_139 = F_4 ( V_3 ) ;
F_48 (i, data->available_cores) {
V_137 . V_2 = V_11 ;
F_49 ( & V_137 , V_140 ) ;
}
V_135 = F_20 ( V_10 , V_3 , V_19 ) ;
if ( V_135 )
return V_135 ;
V_137 . V_139 = F_4 ( V_10 -> V_14 ) ;
F_48 (i, data->available_cores) {
V_137 . V_2 = V_11 ;
F_49 ( & V_137 , V_141 ) ;
}
return V_135 ;
}
static long F_50 ( void * V_142 )
{
struct V_143 * V_144 = V_142 ;
struct V_145 * V_146 = V_144 -> V_146 ;
unsigned V_147 = V_144 -> V_147 ;
unsigned V_148 = V_144 -> V_148 ;
struct V_9 * V_10 = F_51 ( V_149 , V_146 -> V_2 ) ;
T_1 V_150 ;
T_1 V_151 ;
unsigned int V_152 ;
int V_153 ;
if ( ! V_10 )
return - V_67 ;
V_150 = V_10 -> V_14 ;
V_151 = V_10 -> V_12 ;
if ( F_6 () ) {
F_17 (KERN_ERR PFX L_96 ) ;
return - V_80 ;
}
F_9 ( L_97 ,
V_146 -> V_2 , V_147 , V_146 -> V_154 , V_146 -> V_155 , V_148 ) ;
if ( F_8 ( V_10 ) )
return - V_80 ;
F_9 ( L_98 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
if ( ( V_151 != V_10 -> V_12 ) ||
( V_150 != V_10 -> V_14 ) ) {
F_52 ( V_156
L_99 ,
V_150 , V_10 -> V_14 ,
V_151 , V_10 -> V_12 ) ;
}
if ( F_53 ( V_146 , V_10 -> V_70 ,
V_147 , V_148 , & V_152 ) )
return - V_80 ;
F_54 ( & V_157 ) ;
F_36 ( V_10 , V_152 ) ;
V_153 = F_47 ( V_10 , V_152 ) ;
if ( V_153 ) {
F_17 (KERN_ERR PFX L_100 ) ;
F_55 ( & V_157 ) ;
return 1 ;
}
F_55 ( & V_157 ) ;
V_146 -> V_158 = F_4 ( V_10 -> V_14 ) ;
return 0 ;
}
static int F_56 ( struct V_145 * V_146 ,
unsigned V_147 , unsigned V_148 )
{
struct V_143 V_144 = { . V_146 = V_146 , . V_147 = V_147 ,
. V_148 = V_148 } ;
return F_57 ( V_146 -> V_2 , F_50 , & V_144 ) ;
}
static int F_58 ( struct V_145 * V_146 )
{
struct V_9 * V_10 = F_51 ( V_149 , V_146 -> V_2 ) ;
if ( ! V_10 )
return - V_67 ;
return F_59 ( V_146 , V_10 -> V_70 ) ;
}
static void T_4 F_60 ( void * V_159 )
{
struct V_160 * V_160 = V_159 ;
if ( F_6 () ) {
F_17 (KERN_ERR PFX L_101 ) ;
V_160 -> V_50 = - V_51 ;
return;
}
if ( F_8 ( V_160 -> V_10 ) ) {
V_160 -> V_50 = - V_51 ;
return;
}
F_13 () ;
V_160 -> V_50 = 0 ;
}
static int T_4 F_61 ( struct V_145 * V_146 )
{
struct V_9 * V_10 ;
struct V_160 V_160 ;
int V_50 ;
if ( ! F_62 ( V_146 -> V_2 ) )
return - V_51 ;
F_63 ( V_146 -> V_2 , F_24 , & V_50 , 1 ) ;
if ( V_50 )
return - V_51 ;
V_10 = F_64 ( sizeof( struct V_9 ) , V_75 ) ;
if ( ! V_10 ) {
F_17 (KERN_ERR PFX L_102 ) ;
return - V_76 ;
}
V_10 -> V_2 = V_146 -> V_2 ;
if ( F_37 ( V_10 ) ) {
if ( F_65 () != 1 ) {
F_66 ( V_161 ) ;
goto V_114;
}
if ( V_146 -> V_2 != 0 ) {
F_17 (KERN_ERR FW_BUG PFX L_103
L_104
L_105 ) ;
goto V_114;
}
V_50 = F_34 ( V_10 ) ;
if ( V_50 )
goto V_114;
V_146 -> V_162 . V_133 = (
( ( V_10 -> V_35 + 8 ) * V_10 -> V_17 * V_18 ) +
( ( 1 << V_10 -> V_16 ) * 30 ) ) * 1000 ;
} else
V_146 -> V_162 . V_133 = F_45 ( V_10 ) ;
V_160 . V_10 = V_10 ;
F_63 ( V_10 -> V_2 , F_60 ,
& V_160 , 1 ) ;
V_50 = V_160 . V_50 ;
if ( V_50 != 0 )
goto V_163;
F_67 ( V_146 -> V_164 , F_1 ( V_146 -> V_2 ) ) ;
V_10 -> V_165 = V_146 -> V_164 ;
V_146 -> V_158 = F_4 ( V_10 -> V_14 ) ;
F_9 ( L_106 , V_146 -> V_158 ) ;
if ( F_68 ( V_146 , V_10 -> V_70 ) ) {
F_17 (KERN_ERR FW_BUG PFX L_107 ) ;
F_43 ( V_10 ) ;
F_32 ( V_10 -> V_70 ) ;
F_32 ( V_10 ) ;
return - V_67 ;
}
F_69 ( V_10 -> V_70 , V_146 -> V_2 ) ;
F_9 ( L_108 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
F_51 ( V_149 , V_146 -> V_2 ) = V_10 ;
return 0 ;
V_163:
F_43 ( V_10 ) ;
V_114:
F_32 ( V_10 ) ;
return - V_51 ;
}
static int T_5 F_70 ( struct V_145 * V_146 )
{
struct V_9 * V_10 = F_51 ( V_149 , V_146 -> V_2 ) ;
if ( ! V_10 )
return - V_67 ;
F_43 ( V_10 ) ;
F_71 ( V_146 -> V_2 ) ;
F_32 ( V_10 -> V_70 ) ;
F_32 ( V_10 ) ;
F_51 ( V_149 , V_146 -> V_2 ) = NULL ;
return 0 ;
}
static void F_72 ( void * V_166 )
{
int * V_167 = V_166 ;
struct V_9 * V_10 = F_73 ( V_149 ) ;
* V_167 = F_8 ( V_10 ) ;
}
static unsigned int F_74 ( unsigned int V_2 )
{
struct V_9 * V_10 = F_51 ( V_149 , V_2 ) ;
unsigned int V_168 = 0 ;
int V_167 ;
if ( ! V_10 )
return 0 ;
F_63 ( V_2 , F_72 , & V_167 , true ) ;
if ( V_167 )
goto V_169;
V_168 = F_4 ( V_10 -> V_14 ) ;
V_169:
return V_168 ;
}
static int T_4 F_75 ( void )
{
unsigned int V_11 , V_170 = 0 ;
int V_171 ;
if ( F_76 ( V_172 ) ) {
F_77 ( V_156 L_109 ) ;
F_78 ( L_110 ) ;
return - V_51 ;
}
if ( ! F_79 ( V_173 ) )
return - V_51 ;
F_80 (i) {
int V_50 ;
F_63 ( V_11 , F_24 , & V_50 , 1 ) ;
if ( V_50 == 0 )
V_170 ++ ;
}
if ( V_170 != F_65 () )
return - V_51 ;
V_171 = F_81 ( & V_174 ) ;
if ( ! V_171 )
F_52 ( V_156 L_111 V_175 L_112 ,
F_82 () , V_176 . V_177 ,
V_170 ) ;
return V_171 ;
}
static void T_6 F_83 ( void )
{
F_9 ( L_113 ) ;
F_84 ( & V_174 ) ;
}
