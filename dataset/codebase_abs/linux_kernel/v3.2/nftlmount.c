static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned int V_5 , V_6 = 0 ;
T_1 V_7 ;
T_2 V_8 [ V_9 ] ;
struct V_10 * V_11 = & V_2 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
unsigned int V_16 ;
V_2 -> V_17 = V_2 -> V_15 . V_14 -> V_18 ;
V_2 -> V_19 = ( V_20 ) V_2 -> V_15 . V_14 -> V_21 / V_2 -> V_17 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_23 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_19 ; V_5 ++ ) {
int V_25 ;
V_25 = V_14 -> V_26 ( V_14 , V_5 * V_2 -> V_17 , V_9 ,
& V_7 , V_8 ) ;
if ( V_7 != V_9 ) {
static int V_27 = 5 ;
if ( V_27 ) {
F_2 ( V_28 L_1 ,
V_5 * V_2 -> V_17 , V_2 -> V_15 . V_14 -> V_29 , V_25 ) ;
if ( ! -- V_27 )
F_2 ( V_28 L_2 ) ;
}
continue;
}
if ( V_7 < 6 || memcmp ( V_8 , L_3 , 6 ) ) {
#if 0
printk(KERN_DEBUG "ANAND header not found at 0x%x in mtd%d\n",
block * nftl->EraseSize, nftl->mbd.mtd->index);
#endif
continue;
}
if ( ( V_25 = F_3 ( V_14 , V_5 * V_2 -> V_17 +
V_9 + 8 , 8 , & V_7 ,
( char * ) & V_4 ) < 0 ) ) {
F_2 ( V_28 L_4 ,
V_5 * V_2 -> V_17 , V_2 -> V_15 . V_14 -> V_29 , V_25 ) ;
continue;
}
#if 0
if (le16_to_cpu(h1.EraseMark | h1.EraseMark1) != ERASE_MARK) {
printk(KERN_NOTICE "ANAND header found at 0x%x in mtd%d, but erase mark not present (0x%04x,0x%04x instead)\n",
block * nftl->EraseSize, nftl->mbd.mtd->index,
le16_to_cpu(h1.EraseMark), le16_to_cpu(h1.EraseMark1));
continue;
}
if ((ret = mtd->read(mtd, block * nftl->EraseSize, SECTORSIZE,
&retlen, buf) < 0)) {
printk(KERN_NOTICE "ANAND header found at 0x%x in mtd%d, but ECC read failed (err %d)\n",
block * nftl->EraseSize, nftl->mbd.mtd->index, ret);
continue;
}
if (memcmp(buf, "ANAND", 6)) {
printk(KERN_NOTICE "ANAND header found at 0x%x in mtd%d, but went away on reread!\n",
block * nftl->EraseSize, nftl->mbd.mtd->index);
printk(KERN_NOTICE "New data are: %02x %02x %02x %02x %02x %02x\n",
buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
continue;
}
#endif
if ( V_6 ) {
if ( memcmp ( V_11 , V_8 , sizeof( struct V_10 ) ) ) {
F_2 ( V_30 L_5 ,
V_2 -> V_22 * V_2 -> V_17 , V_5 * V_2 -> V_17 ) ;
if ( V_6 < 2 ) {
return - 1 ;
}
continue;
}
if ( V_6 == 1 )
V_2 -> V_24 = V_5 ;
V_2 -> V_31 [ V_5 ] = V_32 ;
V_6 ++ ;
continue;
}
memcpy ( V_11 , V_8 , sizeof( struct V_10 ) ) ;
#if 0
The new DiskOnChip driver scans the MediaHeader itself, and presents a virtual
erasesize based on UnitSizeFactor. So the erasesize we read from the mtd
device is already correct.
if (mh->UnitSizeFactor == 0) {
printk(KERN_NOTICE "NFTL: UnitSizeFactor 0x00 detected. This violates the spec but we think we know what it means...\n");
} else if (mh->UnitSizeFactor < 0xfc) {
printk(KERN_NOTICE "Sorry, we don't support UnitSizeFactor 0x%02x\n",
mh->UnitSizeFactor);
return -1;
} else if (mh->UnitSizeFactor != 0xff) {
printk(KERN_NOTICE "WARNING: Support for NFTL with UnitSizeFactor 0x%02x is experimental\n",
mh->UnitSizeFactor);
nftl->EraseSize = nftl->mbd.mtd->erasesize << (0xff - mh->UnitSizeFactor);
nftl->nb_blocks = (u32)nftl->mbd.mtd->size / nftl->EraseSize;
}
#endif
V_2 -> V_33 = F_4 ( V_11 -> V_34 ) ;
if ( ( V_2 -> V_33 + 2 ) >= V_2 -> V_19 ) {
F_2 ( V_30 L_6 ) ;
F_2 ( V_30 L_7 ,
V_2 -> V_33 , V_2 -> V_19 ) ;
return - 1 ;
}
V_2 -> V_35 = F_5 ( V_11 -> V_36 ) / V_2 -> V_17 ;
if ( V_2 -> V_35 > ( V_2 -> V_19 - V_2 -> V_33 - 2 ) ) {
F_2 ( V_30 L_6 ) ;
F_2 ( V_30 L_8 ,
V_2 -> V_35 , V_2 -> V_19 , V_2 -> V_33 ) ;
return - 1 ;
}
V_2 -> V_15 . V_21 = V_2 -> V_35 * ( V_2 -> V_17 / V_9 ) ;
V_2 -> V_19 = F_4 ( V_11 -> V_37 ) + F_4 ( V_11 -> V_34 ) ;
V_2 -> V_38 = V_2 -> V_19 - 1 ;
V_2 -> V_39 = F_6 ( V_2 -> V_19 * sizeof( V_40 ) , V_41 ) ;
if ( ! V_2 -> V_39 ) {
F_2 ( V_30 L_9 ) ;
return - V_42 ;
}
V_2 -> V_31 = F_6 ( V_2 -> V_19 * sizeof( V_40 ) , V_41 ) ;
if ( ! V_2 -> V_31 ) {
F_7 ( V_2 -> V_39 ) ;
F_2 ( V_30 L_10 ) ;
return - V_42 ;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_33 ; V_16 ++ )
V_2 -> V_31 [ V_16 ] = V_32 ;
for (; V_16 < V_2 -> V_19 ; V_16 ++ ) {
V_2 -> V_31 [ V_16 ] = V_43 ;
}
V_2 -> V_31 [ V_5 ] = V_32 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_19 ; V_16 ++ ) {
#if 0
The new DiskOnChip driver already scanned the bad block table. Just query it.
if ((i & (SECTORSIZE - 1)) == 0) {
if ((ret = mtd->read(nftl->mbd.mtd, block * nftl->EraseSize +
i + SECTORSIZE, SECTORSIZE, &retlen,
buf)) < 0) {
printk(KERN_NOTICE "Read of bad sector table failed (err %d)\n",
ret);
kfree(nftl->ReplUnitTable);
kfree(nftl->EUNtable);
return -1;
}
}
if (buf[i & (SECTORSIZE - 1)] != 0xff)
nftl->ReplUnitTable[i] = BLOCK_RESERVED;
#endif
if ( V_2 -> V_15 . V_14 -> V_44 ( V_2 -> V_15 . V_14 , V_16 * V_2 -> V_17 ) )
V_2 -> V_31 [ V_16 ] = V_32 ;
}
V_2 -> V_22 = V_5 ;
V_6 ++ ;
}
return V_6 ? 0 : - 1 ;
}
static int F_8 ( void * V_45 , int V_46 , int V_47 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ ) {
if ( V_46 != ( ( unsigned char * ) V_45 ) [ V_16 ] )
return 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_48 , int V_49 ,
int V_50 )
{
T_2 V_8 [ V_9 + V_2 -> V_15 . V_14 -> V_51 ] ;
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
T_1 V_7 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_49 ; V_16 += V_9 ) {
if ( V_14 -> V_26 ( V_14 , V_48 , V_9 , & V_7 , V_8 ) )
return - 1 ;
if ( F_8 ( V_8 , 0xff , V_9 ) != 0 )
return - 1 ;
if ( V_50 ) {
if( F_3 ( V_14 , V_48 , V_14 -> V_51 ,
& V_7 , & V_8 [ V_9 ] ) < 0 )
return - 1 ;
if ( F_8 ( V_8 + V_9 , 0xff , V_14 -> V_51 ) != 0 )
return - 1 ;
}
V_48 += V_9 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_7 ;
unsigned int V_52 , V_53 ;
struct V_3 V_54 ;
struct V_55 * V_56 = & V_2 -> V_56 ;
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
if ( F_3 ( V_14 , V_5 * V_2 -> V_17 + V_9 + 8 ,
8 , & V_7 , ( char * ) & V_54 ) < 0 )
goto V_57;
V_53 = F_4 ( ( V_54 . V_58 | V_54 . V_59 ) ) ;
if ( V_53 != V_60 ) {
V_57:
V_54 . V_58 = F_11 ( V_60 ) ;
V_54 . V_59 = F_11 ( V_60 ) ;
V_54 . V_61 = F_12 ( 0 ) ;
}
memset ( V_56 , 0 , sizeof( struct V_55 ) ) ;
V_56 -> V_14 = V_2 -> V_15 . V_14 ;
V_56 -> V_62 = V_5 * V_2 -> V_17 ;
V_56 -> V_49 = V_2 -> V_17 ;
V_14 -> V_63 ( V_14 , V_56 ) ;
if ( V_56 -> V_64 == V_65 ) {
F_2 ( L_11 , V_5 ) ;
goto V_66;
}
V_52 = F_5 ( V_54 . V_61 ) ;
V_52 ++ ;
if ( V_52 == 0 )
V_52 = 1 ;
if ( F_9 ( V_2 , V_56 -> V_62 , V_2 -> V_17 , 1 ) != 0 )
goto V_66;
V_54 . V_61 = F_5 ( V_52 ) ;
if ( F_13 ( V_14 , V_5 * V_2 -> V_17 + V_9 +
8 , 8 , & V_7 , ( char * ) & V_54 ) < 0 )
goto V_66;
return 0 ;
V_66:
V_2 -> V_15 . V_14 -> V_67 ( V_2 -> V_15 . V_14 , V_56 -> V_62 ) ;
return - 1 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_68 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
unsigned int V_5 , V_16 , V_69 ;
struct V_70 V_71 ;
int V_72 ;
T_1 V_7 ;
V_72 = V_2 -> V_17 / V_9 ;
V_5 = V_68 ;
for (; ; ) {
for ( V_16 = 0 ; V_16 < V_72 ; V_16 ++ ) {
if ( F_3 ( V_14 ,
V_5 * V_2 -> V_17 + V_16 * V_9 ,
8 , & V_7 , ( char * ) & V_71 ) < 0 )
V_69 = V_73 ;
else
V_69 = V_71 . V_74 | V_71 . V_75 ;
switch( V_69 ) {
case V_76 :
if ( F_8 ( & V_71 , 0xff , 8 ) != 0 ||
F_9 ( V_2 , V_5 * V_2 -> V_17 + V_16 * V_9 ,
V_9 , 0 ) != 0 ) {
F_2 ( L_12
L_13 ,
V_16 , V_5 ) ;
V_71 . V_74 = V_73 ;
V_71 . V_75 = V_73 ;
F_13 ( V_14 , V_5 *
V_2 -> V_17 +
V_16 * V_9 , 8 ,
& V_7 , ( char * ) & V_71 ) ;
}
break;
default:
break;
}
}
V_5 = V_2 -> V_31 [ V_5 ] ;
if ( ! ( V_5 == V_23 || V_5 < V_2 -> V_19 ) )
F_2 ( L_14 , V_5 ) ;
if ( V_5 == V_23 || V_5 >= V_2 -> V_19 )
break;
}
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_68 )
{
unsigned int V_77 = 0 , V_5 = V_68 ;
for (; ; ) {
V_77 ++ ;
if ( V_77 >= V_2 -> V_19 ) {
F_2 ( L_15 , V_77 ) ;
break;
}
V_5 = V_2 -> V_31 [ V_5 ] ;
if ( ! ( V_5 == V_23 || V_5 < V_2 -> V_19 ) )
F_2 ( L_14 , V_5 ) ;
if ( V_5 == V_23 || V_5 >= V_2 -> V_19 )
break;
}
return V_77 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_68 )
{
unsigned int V_5 = V_68 , V_78 ;
F_2 ( L_16 , V_68 ) ;
for (; ; ) {
V_78 = V_2 -> V_31 [ V_5 ] ;
F_2 ( L_17 , V_5 ) ;
if ( F_10 ( V_2 , V_5 ) < 0 ) {
V_2 -> V_31 [ V_5 ] = V_32 ;
} else {
V_2 -> V_31 [ V_5 ] = V_79 ;
}
V_5 = V_78 ;
if ( ! ( V_5 == V_23 || V_5 < V_2 -> V_19 ) )
F_2 ( L_14 , V_5 ) ;
if ( V_5 == V_23 || V_5 >= V_2 -> V_19 )
break;
}
}
static int F_17 ( struct V_1 * V_2 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
struct V_3 V_4 ;
unsigned int V_53 ;
T_1 V_7 ;
if ( F_3 ( V_14 , V_5 * V_2 -> V_17 + V_9 + 8 , 8 ,
& V_7 , ( char * ) & V_4 ) < 0 )
return - 1 ;
V_53 = F_4 ( ( V_4 . V_58 | V_4 . V_59 ) ) ;
if ( V_53 != V_60 ) {
if ( F_9 ( V_2 , V_5 * V_2 -> V_17 , V_2 -> V_17 , 1 ) != 0 )
return - 1 ;
V_4 . V_58 = F_11 ( V_60 ) ;
V_4 . V_59 = F_11 ( V_60 ) ;
V_4 . V_61 = F_12 ( 0 ) ;
if ( F_13 ( V_14 ,
V_5 * V_2 -> V_17 + V_9 + 8 , 8 ,
& V_7 , ( char * ) & V_4 ) < 0 )
return - 1 ;
} else {
#if 0
for (i = 0; i < nftl->EraseSize; i += SECTORSIZE) {
if (check_free_sectors (nftl, block * nftl->EraseSize + i,
SECTORSIZE, 0) != 0)
return -1;
if (nftl_read_oob(mtd, block * nftl->EraseSize + i,
16, &retlen, buf) < 0)
return -1;
if (i == SECTORSIZE) {
if (memcmpb(buf, 0xff, 8))
return -1;
} else {
if (memcmpb(buf, 0xff, 16))
return -1;
}
}
#endif
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_5 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
struct V_80 V_54 ;
T_1 V_7 ;
if ( F_3 ( V_14 , V_5 * V_2 -> V_17 + 2 * V_9 + 8 ,
8 , & V_7 , ( char * ) & V_54 ) < 0 )
return 0 ;
return F_4 ( ( V_54 . V_81 | V_54 . V_82 ) ) ;
}
int F_19 ( struct V_1 * V_83 )
{
int V_16 ;
unsigned int V_84 , V_85 , V_86 , V_52 , V_53 ;
unsigned int V_5 , V_68 , V_87 ;
int V_88 , V_89 ;
struct V_90 V_91 ;
struct V_3 V_4 ;
struct V_13 * V_14 = V_83 -> V_15 . V_14 ;
T_1 V_7 ;
if ( F_1 ( V_83 ) < 0 ) {
F_2 ( L_18 ) ;
return - 1 ;
}
for ( V_16 = 0 ; V_16 < V_83 -> V_19 ; V_16 ++ ) {
V_83 -> V_39 [ V_16 ] = V_23 ;
}
V_84 = 0 ;
for ( V_68 = 0 ; V_68 < V_83 -> V_19 ; V_68 ++ ) {
if ( V_83 -> V_31 [ V_68 ] == V_43 ) {
V_5 = V_68 ;
V_88 = 0 ;
V_89 = 0 ;
for (; ; ) {
if ( F_3 ( V_14 ,
V_5 * V_83 -> V_17 + 8 , 8 ,
& V_7 , ( char * ) & V_91 ) < 0 ||
F_3 ( V_14 ,
V_5 * V_83 -> V_17 +
V_9 + 8 , 8 ,
& V_7 , ( char * ) & V_4 ) < 0 ) {
V_83 -> V_31 [ V_5 ] = V_23 ;
V_89 = 1 ;
break;
}
V_85 = F_4 ( ( V_91 . V_92 | V_91 . V_93 ) ) ;
V_86 = F_4 ( ( V_91 . V_94 | V_91 . V_95 ) ) ;
V_52 = F_5 ( V_4 . V_61 ) ;
V_53 = F_4 ( ( V_4 . V_58 | V_4 . V_59 ) ) ;
V_87 = ! ( V_85 >> 15 ) ;
V_85 = V_85 & 0x7fff ;
if ( V_53 != V_60 || V_85 >= V_83 -> V_19 ) {
if ( V_88 == 0 ) {
if ( F_17 ( V_83 , V_5 ) < 0 ) {
F_2 ( L_17 , V_5 ) ;
if ( F_10 ( V_83 , V_5 ) < 0 ) {
V_83 -> V_31 [ V_5 ] = V_32 ;
} else {
V_83 -> V_31 [ V_5 ] = V_79 ;
}
} else {
V_83 -> V_31 [ V_5 ] = V_79 ;
}
goto V_96;
} else {
F_2 ( L_19 ,
V_5 , V_68 ) ;
V_83 -> V_31 [ V_5 ] = V_23 ;
V_89 = 1 ;
break;
}
}
if ( V_88 == 0 ) {
if ( ! V_87 )
goto V_96;
V_84 = V_85 ;
} else {
if ( V_85 != V_84 ) {
F_2 ( L_20 ,
V_5 , V_85 , V_84 ) ;
V_89 = 1 ;
}
if ( V_87 ) {
if ( F_18 ( V_83 , V_5 ) != V_97 ||
V_86 != 0xffff ) {
F_2 ( L_21 ,
V_5 ) ;
V_89 = 1 ;
} else {
F_2 ( L_22 ,
V_5 ) ;
}
}
}
V_88 ++ ;
if ( V_86 == 0xffff ) {
V_83 -> V_31 [ V_5 ] = V_23 ;
break;
} else if ( V_86 >= V_83 -> V_19 ) {
F_2 ( L_23 ,
V_5 , V_86 ) ;
V_89 = 1 ;
V_83 -> V_31 [ V_5 ] = V_23 ;
break;
} else if ( V_83 -> V_31 [ V_86 ] != V_43 ) {
if ( V_83 -> V_31 [ V_86 ] == V_23 &&
V_83 -> V_39 [ V_84 ] == V_86 &&
F_18 ( V_83 , V_68 ) == V_97 ) {
F_2 ( L_22 ,
V_86 ) ;
V_83 -> V_31 [ V_5 ] = V_86 ;
V_83 -> V_39 [ V_84 ] = V_23 ;
} else {
F_2 ( L_24 ,
V_5 , V_86 ) ;
V_89 = 1 ;
V_83 -> V_31 [ V_5 ] = V_23 ;
}
break;
} else {
V_83 -> V_31 [ V_5 ] = V_86 ;
V_5 = V_86 ;
}
}
if ( V_89 ) {
F_16 ( V_83 , V_68 ) ;
} else {
unsigned int V_98 , V_99 , V_100 ;
int V_101 ;
V_101 = F_18 ( V_83 , V_68 ) ;
if ( V_101 == 0 ) {
F_2 ( L_25 , V_68 ) ;
F_16 ( V_83 , V_68 ) ;
} else {
if ( V_101 == V_97 )
F_14 ( V_83 , V_68 ) ;
V_98 = V_83 -> V_39 [ V_84 ] ;
if ( V_98 != V_23 ) {
V_100 = F_15 ( V_83 , V_98 ) ;
F_2 ( L_26 ,
V_98 , V_100 , V_68 , V_88 ) ;
if ( V_88 >= V_100 ) {
V_99 = V_98 ;
V_83 -> V_39 [ V_84 ] = V_68 ;
} else {
V_99 = V_68 ;
}
F_16 ( V_83 , V_99 ) ;
} else {
V_83 -> V_39 [ V_84 ] = V_68 ;
}
}
}
}
V_96: ;
}
V_83 -> V_102 = 0 ;
V_83 -> V_103 = F_4 ( V_83 -> V_12 . V_34 ) ;
for ( V_5 = 0 ; V_5 < V_83 -> V_19 ; V_5 ++ ) {
if ( V_83 -> V_31 [ V_5 ] == V_43 ) {
F_2 ( L_27 , V_5 ) ;
if ( F_10 ( V_83 , V_5 ) < 0 )
V_83 -> V_31 [ V_5 ] = V_32 ;
else
V_83 -> V_31 [ V_5 ] = V_79 ;
}
if ( V_83 -> V_31 [ V_5 ] == V_79 ) {
V_83 -> V_102 ++ ;
V_83 -> V_103 = V_5 ;
}
}
return 0 ;
}
