static int F_1 ( T_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_10 = V_7 -> error ? 0 : 1 ;
F_2 ( V_11 , L_1 ) ;
if ( V_1 -> V_12 == V_7 )
V_1 -> V_12 = NULL ;
if ( V_7 -> V_13 [ 0 ] == V_14 || V_7 -> V_13 [ 0 ] == V_15 ||
V_9 -> V_16 == V_17 )
V_10 = 1 ;
else if ( V_7 -> V_13 [ 0 ] == V_18 ) {
T_2 * V_19 = F_3 ( V_9 -> V_20 ) ;
if ( ! V_7 -> error ) {
V_4 -> V_21 = V_19 [ 2 ] & 0x0F ;
V_4 -> V_22 = V_19 [ 12 ] ;
V_4 -> V_23 = V_19 [ 13 ] ;
V_4 -> V_24 = V_19 [ 15 ] & 0x80 ?
( V_25 ) F_4 ( ( V_25 * ) & V_19 [ 16 ] ) : 0x10000 ;
if ( V_1 -> V_12 )
F_2 ( V_26 , L_2 ,
V_1 -> V_12 -> V_13 [ 0 ] ) ;
F_2 ( V_27 , L_3
L_4 , V_4 -> V_21 ,
V_4 -> V_22 , V_4 -> V_23 ) ;
} else
F_5 (KERN_ERR PFX L_5
L_6 ) ;
}
if ( V_9 -> V_16 == V_28 )
V_9 -> V_29 = V_10 ? 0 : V_30 ;
return V_10 ;
}
static void F_6 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
if ( V_4 -> V_21 == 0x02 &&
V_4 -> V_22 == 0x3a &&
V_4 -> V_23 == 0x00 )
return;
F_5 (KERN_ERR PFX L_7
L_8 ,
floppy->drive->name, pc->c[0], floppy->sense_key,
floppy->asc, floppy->ascq) ;
}
static T_3 F_7 ( T_1 * V_1 ,
struct V_31 * V_32 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_1 -> V_12 == NULL &&
V_7 -> V_13 [ 0 ] != V_18 )
V_1 -> V_12 = V_7 ;
V_1 -> V_7 = V_7 ;
if ( V_7 -> V_33 > V_34 ) {
unsigned int V_35 = F_8 ( V_1 -> V_36 -> V_9 ) ;
if ( ! ( V_7 -> V_37 & V_38 ) )
F_6 ( V_4 , V_7 ) ;
V_7 -> error = V_30 ;
V_1 -> V_12 = NULL ;
V_1 -> V_39 ( V_1 , 0 ) ;
F_9 ( V_1 , - V_40 , V_35 ) ;
return V_41 ;
}
F_2 ( V_11 , L_9 , V_7 -> V_33 ) ;
V_7 -> V_33 ++ ;
return F_10 ( V_1 , V_32 ) ;
}
void F_11 ( struct V_6 * V_7 )
{
F_12 ( V_7 ) ;
V_7 -> V_13 [ 0 ] = V_42 ;
V_7 -> V_13 [ 7 ] = 255 ;
V_7 -> V_13 [ 8 ] = 255 ;
V_7 -> V_43 = 255 ;
}
void F_13 ( struct V_6 * V_7 , T_2 V_44 )
{
V_25 V_45 = 8 ;
F_12 ( V_7 ) ;
V_7 -> V_13 [ 0 ] = V_46 ;
V_7 -> V_13 [ 1 ] = 0 ;
V_7 -> V_13 [ 2 ] = V_44 ;
switch ( V_44 ) {
case V_47 :
V_45 += 12 ;
break;
case V_48 :
V_45 += 32 ;
break;
default:
F_5 (KERN_ERR PFX L_10 , __func__) ;
}
F_14 ( F_15 ( V_45 ) , ( V_25 * ) & V_7 -> V_13 [ 7 ] ) ;
V_7 -> V_43 = V_45 ;
}
static void F_16 ( T_1 * V_1 ,
struct V_6 * V_7 , struct V_8 * V_9 ,
unsigned long V_49 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_50 = V_49 / V_4 -> V_51 ;
int V_52 = F_17 ( V_9 ) / V_4 -> V_51 ;
int V_32 = F_18 ( V_9 ) ;
F_2 ( V_11 , L_11 , V_50 , V_52 ) ;
F_12 ( V_7 ) ;
V_7 -> V_13 [ 0 ] = V_32 == V_53 ? V_14 : V_15 ;
F_14 ( F_15 ( V_52 ) , ( unsigned short * ) & V_7 -> V_13 [ 7 ] ) ;
F_14 ( F_19 ( V_50 ) , ( unsigned int * ) & V_7 -> V_13 [ 2 ] ) ;
memcpy ( V_9 -> V_32 , V_7 -> V_13 , 12 ) ;
V_7 -> V_9 = V_9 ;
if ( V_9 -> V_54 & V_55 )
V_7 -> V_37 |= V_56 ;
V_7 -> V_37 |= V_57 ;
}
static void F_20 ( struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_8 * V_9 )
{
F_12 ( V_7 ) ;
memcpy ( V_7 -> V_13 , V_9 -> V_32 , sizeof( V_7 -> V_13 ) ) ;
V_7 -> V_9 = V_9 ;
if ( F_8 ( V_9 ) ) {
V_7 -> V_37 |= V_57 ;
if ( F_18 ( V_9 ) == V_58 )
V_7 -> V_37 |= V_56 ;
}
}
static T_3 F_21 ( T_1 * V_1 ,
struct V_8 * V_9 , T_4 V_50 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_31 V_32 ;
struct V_6 * V_7 ;
F_2 ( V_11 , L_12 , V_9 -> V_32 [ 0 ] ) ;
if ( V_1 -> V_59 & V_60 )
F_22 ( V_9 , ( V_9 -> V_61
? V_9 -> V_61 -> V_62
: L_13 ) ) ;
if ( V_9 -> V_29 >= V_63 ) {
if ( V_1 -> V_12 ) {
F_6 ( V_4 , V_1 -> V_12 ) ;
V_1 -> V_12 = NULL ;
} else
F_5 (KERN_ERR PFX L_14 , drive->name) ;
if ( V_9 -> V_16 == V_28 ) {
V_9 -> V_29 = 0 ;
F_9 ( V_1 , 0 , F_8 ( V_9 ) ) ;
return V_41 ;
} else
goto V_64;
}
switch ( V_9 -> V_16 ) {
case V_65 :
if ( ( ( long ) F_23 ( V_9 ) % V_4 -> V_51 ) ||
( F_17 ( V_9 ) % V_4 -> V_51 ) ) {
F_5 (KERN_ERR PFX L_15 ,
drive->name) ;
goto V_64;
}
V_7 = & V_4 -> V_66 ;
F_16 ( V_1 , V_7 , V_9 , ( unsigned long ) V_50 ) ;
break;
case V_28 :
case V_67 :
V_7 = (struct V_6 * ) V_9 -> V_68 ;
break;
case V_17 :
V_7 = & V_4 -> V_66 ;
F_20 ( V_4 , V_7 , V_9 ) ;
break;
default:
F_24 () ;
}
F_25 ( V_1 , V_9 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
if ( F_18 ( V_9 ) )
V_32 . V_69 |= V_70 ;
V_32 . V_9 = V_9 ;
if ( V_9 -> V_16 == V_65 || F_8 ( V_9 ) ) {
F_26 ( & V_32 , F_8 ( V_9 ) ) ;
F_27 ( V_1 , & V_32 ) ;
}
V_7 -> V_9 = V_9 ;
return F_7 ( V_1 , & V_32 , V_7 ) ;
V_64:
V_1 -> V_12 = NULL ;
if ( V_9 -> V_16 != V_65 && V_9 -> V_29 == 0 )
V_9 -> V_29 = - V_40 ;
F_9 ( V_1 , - V_40 , F_8 ( V_9 ) ) ;
return V_41 ;
}
static int F_28 ( T_1 * V_1 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_71 * V_72 = V_4 -> V_72 ;
T_2 * V_73 , V_19 [ 40 ] ;
int V_74 , V_75 ;
V_25 V_76 , V_77 , V_78 , V_79 ;
T_2 V_80 , V_81 ;
F_13 ( V_7 , V_48 ) ;
if ( F_29 ( V_1 , V_72 , V_7 , V_19 , V_7 -> V_43 ) ) {
F_5 (KERN_ERR PFX L_16 ) ;
return 1 ;
}
if ( V_19 [ 3 ] & 0x80 )
V_1 -> V_82 |= V_83 ;
else
V_1 -> V_82 &= ~ V_83 ;
F_30 ( V_72 , ! ! ( V_1 -> V_82 & V_83 ) ) ;
V_73 = & V_19 [ 8 ] ;
V_76 = F_31 ( ( V_84 * ) & V_19 [ 8 + 2 ] ) ;
V_77 = F_31 ( ( V_84 * ) & V_19 [ 8 + 6 ] ) ;
V_78 = F_31 ( ( V_84 * ) & V_19 [ 8 + 8 ] ) ;
V_79 = F_31 ( ( V_84 * ) & V_19 [ 8 + 28 ] ) ;
V_80 = V_19 [ 8 + 4 ] ;
V_81 = V_19 [ 8 + 5 ] ;
V_74 = V_78 * V_80 * V_81 * V_77 ;
if ( memcmp ( V_73 , & V_4 -> V_85 , 32 ) )
F_5 (KERN_INFO PFX L_17
L_18 ,
drive->name, capacity / 1024 , cyls, heads,
sectors, transfer_rate / 8 , sector_size, rpm) ;
memcpy ( & V_4 -> V_85 , V_73 , 32 ) ;
V_1 -> V_86 = V_78 ;
V_1 -> V_87 = V_80 ;
V_1 -> V_88 = V_81 ;
V_75 = V_4 -> V_52 * V_4 -> V_89 ;
if ( V_74 < V_75 ) {
F_5 (KERN_NOTICE PFX L_19
L_20 ,
drive->name, lba_capacity, capacity) ;
V_4 -> V_52 = V_4 -> V_89 ?
V_74 / V_4 -> V_89 : 0 ;
V_1 -> V_90 = V_4 -> V_52 * V_4 -> V_51 ;
}
return 0 ;
}
static int F_32 ( T_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_71 * V_72 = V_4 -> V_72 ;
struct V_6 V_7 ;
T_2 * V_91 ;
T_2 V_92 [ 256 ] , V_93 , V_94 ;
int V_95 , V_96 = 1 , V_52 , V_45 ;
F_2 ( V_11 , L_1 ) ;
V_1 -> V_86 = 0 ;
V_1 -> V_87 = V_1 -> V_88 = 0 ;
V_4 -> V_52 = 0 ;
V_4 -> V_51 = 1 ;
V_1 -> V_90 = 0 ;
F_11 ( & V_7 ) ;
if ( F_29 ( V_1 , V_72 , & V_7 , V_92 , V_7 . V_43 ) ) {
F_5 (KERN_ERR PFX L_21 ) ;
return 1 ;
}
V_93 = V_92 [ 3 ] ;
V_91 = & V_92 [ 4 ] ;
V_94 = V_93 / 8 ;
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ ) {
unsigned int V_97 = 4 + V_95 * 8 ;
V_52 = F_33 ( ( V_98 * ) & V_92 [ V_97 ] ) ;
V_45 = F_31 ( ( V_84 * ) & V_92 [ V_97 + 6 ] ) ;
F_2 ( V_99 , L_22
L_23 ,
V_95 , V_52 * V_45 / 1024 ,
V_52 , V_45 ) ;
if ( V_95 )
continue;
switch ( V_92 [ V_97 + 4 ] & 0x03 ) {
case V_100 :
if ( ! ( V_1 -> V_101 & V_102 ) )
break;
case V_103 :
if ( memcmp ( V_91 , & V_4 -> V_91 , 8 ) )
F_5 (KERN_INFO PFX L_24
L_25 ,
drive->name, blocks * length / 1024 ,
blocks, length) ;
memcpy ( & V_4 -> V_91 , V_91 , 8 ) ;
if ( ! V_45 || V_45 % 512 ) {
F_5 (KERN_NOTICE PFX L_26
L_27 , drive->name, length) ;
} else {
V_4 -> V_52 = V_52 ;
V_4 -> V_89 = V_45 ;
V_4 -> V_51 = V_45 / 512 ;
if ( V_4 -> V_51 != 1 )
F_5 (KERN_NOTICE PFX L_28
L_29
L_30 ,
drive->name) ;
V_1 -> V_90 =
V_4 -> V_52 * V_4 -> V_51 ;
V_96 = 0 ;
}
break;
case V_104 :
F_5 (KERN_ERR PFX L_31 ,
drive->name) ;
break;
case V_105 :
F_5 (KERN_ERR PFX L_32
L_33 , drive->name) ;
break;
}
F_2 ( V_99 , L_34 ,
V_92 [ V_97 + 4 ] & 0x03 ) ;
}
if ( ! ( V_1 -> V_101 & V_102 ) )
( void ) F_28 ( V_1 , & V_7 ) ;
return V_96 ;
}
static void F_34 ( T_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_25 * V_106 = V_1 -> V_106 ;
V_1 -> V_39 = F_1 ;
if ( ! strncmp ( ( char * ) & V_106 [ V_107 ] , L_35 , 20 ) ) {
V_1 -> V_101 |= V_108 ;
V_1 -> V_109 = V_110 ;
F_35 ( V_1 -> V_111 , 64 ) ;
}
if ( strncmp ( ( char * ) & V_106 [ V_107 ] , L_36 , 11 ) == 0 ) {
F_35 ( V_1 -> V_111 , 64 ) ;
V_1 -> V_101 |= V_102 ;
V_1 -> V_82 &= ~ V_112 ;
}
( void ) F_32 ( V_1 ) ;
F_36 ( V_1 , V_4 -> V_113 ) ;
V_1 -> V_82 |= V_114 ;
}
static void F_37 ( T_1 * V_1 )
{
}
static int F_38 ( T_1 * V_1 , struct V_71 * V_72 )
{
int V_115 = 0 ;
if ( F_39 ( V_1 , V_72 ) )
F_40 ( V_1 , V_72 , 1 ) ;
V_115 = F_32 ( V_1 ) ;
F_41 ( V_72 , F_42 ( V_1 ) ) ;
return V_115 ;
}
