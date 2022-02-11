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
( F_3 ( V_9 ) == V_16 || F_3 ( V_9 ) == V_17 ) )
V_10 = 1 ;
else if ( V_7 -> V_13 [ 0 ] == V_18 ) {
T_2 * V_19 = F_4 ( V_9 -> V_20 ) ;
if ( ! V_7 -> error ) {
V_4 -> V_21 = V_19 [ 2 ] & 0x0F ;
V_4 -> V_22 = V_19 [ 12 ] ;
V_4 -> V_23 = V_19 [ 13 ] ;
V_4 -> V_24 = V_19 [ 15 ] & 0x80 ?
( V_25 ) F_5 ( ( V_25 * ) & V_19 [ 16 ] ) : 0x10000 ;
if ( V_1 -> V_12 )
F_2 ( V_26 , L_2 ,
V_1 -> V_12 -> V_13 [ 0 ] ) ;
F_2 ( V_27 , L_3
L_4 , V_4 -> V_21 ,
V_4 -> V_22 , V_4 -> V_23 ) ;
} else
F_6 (KERN_ERR PFX L_5
L_6 ) ;
}
if ( F_7 ( V_9 ) )
V_9 -> V_28 = V_10 ? 0 : V_29 ;
return V_10 ;
}
static void F_8 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
if ( V_4 -> V_21 == 0x02 &&
V_4 -> V_22 == 0x3a &&
V_4 -> V_23 == 0x00 )
return;
F_6 (KERN_ERR PFX L_7
L_8 ,
floppy->drive->name, pc->c[0], floppy->sense_key,
floppy->asc, floppy->ascq) ;
}
static T_3 F_9 ( T_1 * V_1 ,
struct V_30 * V_31 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_1 -> V_12 == NULL &&
V_7 -> V_13 [ 0 ] != V_18 )
V_1 -> V_12 = V_7 ;
V_1 -> V_7 = V_7 ;
if ( V_7 -> V_32 > V_33 ) {
unsigned int V_34 = F_10 ( V_1 -> V_35 -> V_9 ) ;
if ( ! ( V_7 -> V_36 & V_37 ) )
F_8 ( V_4 , V_7 ) ;
V_7 -> error = V_29 ;
V_1 -> V_12 = NULL ;
V_1 -> V_38 ( V_1 , 0 ) ;
F_11 ( V_1 , - V_39 , V_34 ) ;
return V_40 ;
}
F_2 ( V_11 , L_9 , V_7 -> V_32 ) ;
V_7 -> V_32 ++ ;
return F_12 ( V_1 , V_31 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_7 ) ;
V_7 -> V_13 [ 0 ] = V_41 ;
V_7 -> V_13 [ 7 ] = 255 ;
V_7 -> V_13 [ 8 ] = 255 ;
V_7 -> V_42 = 255 ;
}
void F_15 ( struct V_6 * V_7 , T_2 V_43 )
{
V_25 V_44 = 8 ;
F_14 ( V_7 ) ;
V_7 -> V_13 [ 0 ] = V_45 ;
V_7 -> V_13 [ 1 ] = 0 ;
V_7 -> V_13 [ 2 ] = V_43 ;
switch ( V_43 ) {
case V_46 :
V_44 += 12 ;
break;
case V_47 :
V_44 += 32 ;
break;
default:
F_6 (KERN_ERR PFX L_10 , __func__) ;
}
F_16 ( F_17 ( V_44 ) , ( V_25 * ) & V_7 -> V_13 [ 7 ] ) ;
V_7 -> V_42 = V_44 ;
}
static void F_18 ( T_1 * V_1 ,
struct V_6 * V_7 , struct V_8 * V_9 ,
unsigned long V_48 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_49 = V_48 / V_4 -> V_50 ;
int V_51 = F_19 ( V_9 ) / V_4 -> V_50 ;
int V_31 = F_20 ( V_9 ) ;
F_2 ( V_11 , L_11 , V_49 , V_51 ) ;
F_14 ( V_7 ) ;
V_7 -> V_13 [ 0 ] = V_31 == V_52 ? V_14 : V_15 ;
F_16 ( F_17 ( V_51 ) , ( unsigned short * ) & V_7 -> V_13 [ 7 ] ) ;
F_16 ( F_21 ( V_49 ) , ( unsigned int * ) & V_7 -> V_13 [ 2 ] ) ;
memcpy ( F_22 ( V_9 ) -> V_31 , V_7 -> V_13 , 12 ) ;
V_7 -> V_9 = V_9 ;
if ( V_31 == V_53 )
V_7 -> V_36 |= V_54 ;
V_7 -> V_36 |= V_55 ;
}
static void F_23 ( struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_8 * V_9 )
{
F_14 ( V_7 ) ;
memcpy ( V_7 -> V_13 , F_22 ( V_9 ) -> V_31 , sizeof( V_7 -> V_13 ) ) ;
V_7 -> V_9 = V_9 ;
if ( F_10 ( V_9 ) ) {
V_7 -> V_36 |= V_55 ;
if ( F_20 ( V_9 ) == V_53 )
V_7 -> V_36 |= V_54 ;
}
}
static T_3 F_24 ( T_1 * V_1 ,
struct V_8 * V_9 , T_4 V_49 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_30 V_31 ;
struct V_6 * V_7 ;
F_2 ( V_11 , L_12 , V_9 -> V_31 [ 0 ] ) ;
if ( V_1 -> V_56 & V_57 )
F_25 ( V_9 , ( V_9 -> V_58
? V_9 -> V_58 -> V_59
: L_13 ) ) ;
if ( V_9 -> V_28 >= V_60 ) {
if ( V_1 -> V_12 ) {
F_8 ( V_4 , V_1 -> V_12 ) ;
V_1 -> V_12 = NULL ;
} else
F_6 (KERN_ERR PFX L_14 , drive->name) ;
if ( F_7 ( V_9 ) ) {
V_9 -> V_28 = 0 ;
F_11 ( V_1 , 0 , F_10 ( V_9 ) ) ;
return V_40 ;
} else
goto V_61;
}
switch ( F_3 ( V_9 ) ) {
default:
if ( ( ( long ) F_26 ( V_9 ) % V_4 -> V_50 ) ||
( F_19 ( V_9 ) % V_4 -> V_50 ) ) {
F_6 (KERN_ERR PFX L_15 ,
drive->name) ;
goto V_61;
}
V_7 = & V_4 -> V_62 ;
F_18 ( V_1 , V_7 , V_9 , ( unsigned long ) V_49 ) ;
break;
case V_16 :
case V_17 :
V_7 = & V_4 -> V_62 ;
F_23 ( V_4 , V_7 , V_9 ) ;
break;
case V_63 :
case V_64 :
switch ( F_27 ( V_9 ) -> type ) {
case V_65 :
case V_66 :
V_7 = (struct V_6 * ) V_9 -> V_67 ;
break;
default:
F_28 () ;
}
}
F_29 ( V_1 , V_9 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( F_20 ( V_9 ) )
V_31 . V_68 |= V_69 ;
V_31 . V_9 = V_9 ;
if ( ! F_30 ( V_9 ) || F_10 ( V_9 ) ) {
F_31 ( & V_31 , F_10 ( V_9 ) ) ;
F_32 ( V_1 , & V_31 ) ;
}
V_7 -> V_9 = V_9 ;
return F_9 ( V_1 , & V_31 , V_7 ) ;
V_61:
V_1 -> V_12 = NULL ;
if ( F_30 ( V_9 ) && V_9 -> V_28 == 0 )
V_9 -> V_28 = - V_39 ;
F_11 ( V_1 , - V_39 , F_10 ( V_9 ) ) ;
return V_40 ;
}
static int F_33 ( T_1 * V_1 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_70 * V_71 = V_4 -> V_71 ;
T_2 * V_72 , V_19 [ 40 ] ;
int V_73 , V_74 ;
V_25 V_75 , V_76 , V_77 , V_78 ;
T_2 V_79 , V_80 ;
F_15 ( V_7 , V_47 ) ;
if ( F_34 ( V_1 , V_71 , V_7 , V_19 , V_7 -> V_42 ) ) {
F_6 (KERN_ERR PFX L_16 ) ;
return 1 ;
}
if ( V_19 [ 3 ] & 0x80 )
V_1 -> V_81 |= V_82 ;
else
V_1 -> V_81 &= ~ V_82 ;
F_35 ( V_71 , ! ! ( V_1 -> V_81 & V_82 ) ) ;
V_72 = & V_19 [ 8 ] ;
V_75 = F_36 ( ( V_83 * ) & V_19 [ 8 + 2 ] ) ;
V_76 = F_36 ( ( V_83 * ) & V_19 [ 8 + 6 ] ) ;
V_77 = F_36 ( ( V_83 * ) & V_19 [ 8 + 8 ] ) ;
V_78 = F_36 ( ( V_83 * ) & V_19 [ 8 + 28 ] ) ;
V_79 = V_19 [ 8 + 4 ] ;
V_80 = V_19 [ 8 + 5 ] ;
V_73 = V_77 * V_79 * V_80 * V_76 ;
if ( memcmp ( V_72 , & V_4 -> V_84 , 32 ) )
F_6 (KERN_INFO PFX L_17
L_18 ,
drive->name, capacity / 1024 , cyls, heads,
sectors, transfer_rate / 8 , sector_size, rpm) ;
memcpy ( & V_4 -> V_84 , V_72 , 32 ) ;
V_1 -> V_85 = V_77 ;
V_1 -> V_86 = V_79 ;
V_1 -> V_87 = V_80 ;
V_74 = V_4 -> V_51 * V_4 -> V_88 ;
if ( V_73 < V_74 ) {
F_6 (KERN_NOTICE PFX L_19
L_20 ,
drive->name, lba_capacity, capacity) ;
V_4 -> V_51 = V_4 -> V_88 ?
V_73 / V_4 -> V_88 : 0 ;
V_1 -> V_89 = V_4 -> V_51 * V_4 -> V_50 ;
}
return 0 ;
}
static int F_37 ( T_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_70 * V_71 = V_4 -> V_71 ;
struct V_6 V_7 ;
T_2 * V_90 ;
T_2 V_91 [ 256 ] , V_92 , V_93 ;
int V_94 , V_95 = 1 , V_51 , V_44 ;
F_2 ( V_11 , L_1 ) ;
V_1 -> V_85 = 0 ;
V_1 -> V_86 = V_1 -> V_87 = 0 ;
V_4 -> V_51 = 0 ;
V_4 -> V_50 = 1 ;
V_1 -> V_89 = 0 ;
F_13 ( & V_7 ) ;
if ( F_34 ( V_1 , V_71 , & V_7 , V_91 , V_7 . V_42 ) ) {
F_6 (KERN_ERR PFX L_21 ) ;
return 1 ;
}
V_92 = V_91 [ 3 ] ;
V_90 = & V_91 [ 4 ] ;
V_93 = V_92 / 8 ;
for ( V_94 = 0 ; V_94 < V_93 ; V_94 ++ ) {
unsigned int V_96 = 4 + V_94 * 8 ;
V_51 = F_38 ( ( V_97 * ) & V_91 [ V_96 ] ) ;
V_44 = F_36 ( ( V_83 * ) & V_91 [ V_96 + 6 ] ) ;
F_2 ( V_98 , L_22
L_23 ,
V_94 , V_51 * V_44 / 1024 ,
V_51 , V_44 ) ;
if ( V_94 )
continue;
switch ( V_91 [ V_96 + 4 ] & 0x03 ) {
case V_99 :
if ( ! ( V_1 -> V_100 & V_101 ) )
break;
case V_102 :
if ( memcmp ( V_90 , & V_4 -> V_90 , 8 ) )
F_6 (KERN_INFO PFX L_24
L_25 ,
drive->name, blocks * length / 1024 ,
blocks, length) ;
memcpy ( & V_4 -> V_90 , V_90 , 8 ) ;
if ( ! V_44 || V_44 % 512 ) {
F_6 (KERN_NOTICE PFX L_26
L_27 , drive->name, length) ;
} else {
V_4 -> V_51 = V_51 ;
V_4 -> V_88 = V_44 ;
V_4 -> V_50 = V_44 / 512 ;
if ( V_4 -> V_50 != 1 )
F_6 (KERN_NOTICE PFX L_28
L_29
L_30 ,
drive->name) ;
V_1 -> V_89 =
V_4 -> V_51 * V_4 -> V_50 ;
V_95 = 0 ;
}
break;
case V_103 :
F_6 (KERN_ERR PFX L_31 ,
drive->name) ;
break;
case V_104 :
F_6 (KERN_ERR PFX L_32
L_33 , drive->name) ;
break;
}
F_2 ( V_98 , L_34 ,
V_91 [ V_96 + 4 ] & 0x03 ) ;
}
if ( ! ( V_1 -> V_100 & V_101 ) )
( void ) F_33 ( V_1 , & V_7 ) ;
return V_95 ;
}
static void F_39 ( T_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_25 * V_105 = V_1 -> V_105 ;
V_1 -> V_38 = F_1 ;
if ( F_40 ( ( char * ) & V_105 [ V_106 ] , L_35 ) ) {
V_1 -> V_100 |= V_107 ;
V_1 -> V_108 = V_109 ;
F_41 ( V_1 -> V_110 , 64 ) ;
}
if ( F_40 ( ( char * ) & V_105 [ V_106 ] , L_36 ) ) {
F_41 ( V_1 -> V_110 , 64 ) ;
V_1 -> V_100 |= V_101 ;
V_1 -> V_81 &= ~ V_111 ;
}
( void ) F_37 ( V_1 ) ;
F_42 ( V_1 , V_4 -> V_112 ) ;
V_1 -> V_81 |= V_113 ;
}
static void F_43 ( T_1 * V_1 )
{
}
static int F_44 ( T_1 * V_1 , struct V_70 * V_71 )
{
int V_114 = 0 ;
if ( F_45 ( V_1 , V_71 ) )
F_46 ( V_1 , V_71 , 1 ) ;
V_114 = F_37 ( V_1 ) ;
F_47 ( V_71 , F_48 ( V_1 ) ) ;
return V_114 ;
}
