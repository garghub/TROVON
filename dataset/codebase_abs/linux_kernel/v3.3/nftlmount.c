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
V_25 = F_2 ( V_14 , V_5 * V_2 -> V_17 , V_9 ,
& V_7 , V_8 ) ;
if ( V_7 != V_9 ) {
static int V_26 = 5 ;
if ( V_26 ) {
F_3 ( V_27 L_1 ,
V_5 * V_2 -> V_17 , V_2 -> V_15 . V_14 -> V_28 , V_25 ) ;
if ( ! -- V_26 )
F_3 ( V_27 L_2 ) ;
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
if ( ( V_25 = F_4 ( V_14 , V_5 * V_2 -> V_17 +
V_9 + 8 , 8 , & V_7 ,
( char * ) & V_4 ) < 0 ) ) {
F_3 ( V_27 L_4 ,
V_5 * V_2 -> V_17 , V_2 -> V_15 . V_14 -> V_28 , V_25 ) ;
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
F_3 ( V_29 L_5 ,
V_2 -> V_22 * V_2 -> V_17 , V_5 * V_2 -> V_17 ) ;
if ( V_6 < 2 ) {
return - 1 ;
}
continue;
}
if ( V_6 == 1 )
V_2 -> V_24 = V_5 ;
V_2 -> V_30 [ V_5 ] = V_31 ;
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
V_2 -> V_32 = F_5 ( V_11 -> V_33 ) ;
if ( ( V_2 -> V_32 + 2 ) >= V_2 -> V_19 ) {
F_3 ( V_29 L_6 ) ;
F_3 ( V_29 L_7 ,
V_2 -> V_32 , V_2 -> V_19 ) ;
return - 1 ;
}
V_2 -> V_34 = F_6 ( V_11 -> V_35 ) / V_2 -> V_17 ;
if ( V_2 -> V_34 > ( V_2 -> V_19 - V_2 -> V_32 - 2 ) ) {
F_3 ( V_29 L_6 ) ;
F_3 ( V_29 L_8 ,
V_2 -> V_34 , V_2 -> V_19 , V_2 -> V_32 ) ;
return - 1 ;
}
V_2 -> V_15 . V_21 = V_2 -> V_34 * ( V_2 -> V_17 / V_9 ) ;
V_2 -> V_19 = F_5 ( V_11 -> V_36 ) + F_5 ( V_11 -> V_33 ) ;
V_2 -> V_37 = V_2 -> V_19 - 1 ;
V_2 -> V_38 = F_7 ( V_2 -> V_19 * sizeof( V_39 ) , V_40 ) ;
if ( ! V_2 -> V_38 ) {
F_3 ( V_29 L_9 ) ;
return - V_41 ;
}
V_2 -> V_30 = F_7 ( V_2 -> V_19 * sizeof( V_39 ) , V_40 ) ;
if ( ! V_2 -> V_30 ) {
F_8 ( V_2 -> V_38 ) ;
F_3 ( V_29 L_10 ) ;
return - V_41 ;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_32 ; V_16 ++ )
V_2 -> V_30 [ V_16 ] = V_31 ;
for (; V_16 < V_2 -> V_19 ; V_16 ++ ) {
V_2 -> V_30 [ V_16 ] = V_42 ;
}
V_2 -> V_30 [ V_5 ] = V_31 ;
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
if ( F_9 ( V_2 -> V_15 . V_14 ,
V_16 * V_2 -> V_17 ) )
V_2 -> V_30 [ V_16 ] = V_31 ;
}
V_2 -> V_22 = V_5 ;
V_6 ++ ;
}
return V_6 ? 0 : - 1 ;
}
static int F_10 ( void * V_43 , int V_44 , int V_45 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
if ( V_44 != ( ( unsigned char * ) V_43 ) [ V_16 ] )
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_46 , int V_47 ,
int V_48 )
{
T_2 V_8 [ V_9 + V_2 -> V_15 . V_14 -> V_49 ] ;
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
T_1 V_7 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 += V_9 ) {
if ( F_2 ( V_14 , V_46 , V_9 , & V_7 , V_8 ) )
return - 1 ;
if ( F_10 ( V_8 , 0xff , V_9 ) != 0 )
return - 1 ;
if ( V_48 ) {
if( F_4 ( V_14 , V_46 , V_14 -> V_49 ,
& V_7 , & V_8 [ V_9 ] ) < 0 )
return - 1 ;
if ( F_10 ( V_8 + V_9 , 0xff , V_14 -> V_49 ) != 0 )
return - 1 ;
}
V_46 += V_9 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_7 ;
unsigned int V_50 , V_51 ;
struct V_3 V_52 ;
struct V_53 * V_54 = & V_2 -> V_54 ;
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
if ( F_4 ( V_14 , V_5 * V_2 -> V_17 + V_9 + 8 ,
8 , & V_7 , ( char * ) & V_52 ) < 0 )
goto V_55;
V_51 = F_5 ( ( V_52 . V_56 | V_52 . V_57 ) ) ;
if ( V_51 != V_58 ) {
V_55:
V_52 . V_56 = F_13 ( V_58 ) ;
V_52 . V_57 = F_13 ( V_58 ) ;
V_52 . V_59 = F_14 ( 0 ) ;
}
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
V_54 -> V_14 = V_2 -> V_15 . V_14 ;
V_54 -> V_60 = V_5 * V_2 -> V_17 ;
V_54 -> V_47 = V_2 -> V_17 ;
F_15 ( V_14 , V_54 ) ;
if ( V_54 -> V_61 == V_62 ) {
F_3 ( L_11 , V_5 ) ;
goto V_63;
}
V_50 = F_6 ( V_52 . V_59 ) ;
V_50 ++ ;
if ( V_50 == 0 )
V_50 = 1 ;
if ( F_11 ( V_2 , V_54 -> V_60 , V_2 -> V_17 , 1 ) != 0 )
goto V_63;
V_52 . V_59 = F_6 ( V_50 ) ;
if ( F_16 ( V_14 , V_5 * V_2 -> V_17 + V_9 +
8 , 8 , & V_7 , ( char * ) & V_52 ) < 0 )
goto V_63;
return 0 ;
V_63:
F_17 ( V_2 -> V_15 . V_14 , V_54 -> V_60 ) ;
return - 1 ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
unsigned int V_5 , V_16 , V_65 ;
struct V_66 V_67 ;
int V_68 ;
T_1 V_7 ;
V_68 = V_2 -> V_17 / V_9 ;
V_5 = V_64 ;
for (; ; ) {
for ( V_16 = 0 ; V_16 < V_68 ; V_16 ++ ) {
if ( F_4 ( V_14 ,
V_5 * V_2 -> V_17 + V_16 * V_9 ,
8 , & V_7 , ( char * ) & V_67 ) < 0 )
V_65 = V_69 ;
else
V_65 = V_67 . V_70 | V_67 . V_71 ;
switch( V_65 ) {
case V_72 :
if ( F_10 ( & V_67 , 0xff , 8 ) != 0 ||
F_11 ( V_2 , V_5 * V_2 -> V_17 + V_16 * V_9 ,
V_9 , 0 ) != 0 ) {
F_3 ( L_12
L_13 ,
V_16 , V_5 ) ;
V_67 . V_70 = V_69 ;
V_67 . V_71 = V_69 ;
F_16 ( V_14 , V_5 *
V_2 -> V_17 +
V_16 * V_9 , 8 ,
& V_7 , ( char * ) & V_67 ) ;
}
break;
default:
break;
}
}
V_5 = V_2 -> V_30 [ V_5 ] ;
if ( ! ( V_5 == V_23 || V_5 < V_2 -> V_19 ) )
F_3 ( L_14 , V_5 ) ;
if ( V_5 == V_23 || V_5 >= V_2 -> V_19 )
break;
}
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_64 )
{
unsigned int V_73 = 0 , V_5 = V_64 ;
for (; ; ) {
V_73 ++ ;
if ( V_73 >= V_2 -> V_19 ) {
F_3 ( L_15 , V_73 ) ;
break;
}
V_5 = V_2 -> V_30 [ V_5 ] ;
if ( ! ( V_5 == V_23 || V_5 < V_2 -> V_19 ) )
F_3 ( L_14 , V_5 ) ;
if ( V_5 == V_23 || V_5 >= V_2 -> V_19 )
break;
}
return V_73 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_64 )
{
unsigned int V_5 = V_64 , V_74 ;
F_3 ( L_16 , V_64 ) ;
for (; ; ) {
V_74 = V_2 -> V_30 [ V_5 ] ;
F_3 ( L_17 , V_5 ) ;
if ( F_12 ( V_2 , V_5 ) < 0 ) {
V_2 -> V_30 [ V_5 ] = V_31 ;
} else {
V_2 -> V_30 [ V_5 ] = V_75 ;
}
V_5 = V_74 ;
if ( ! ( V_5 == V_23 || V_5 < V_2 -> V_19 ) )
F_3 ( L_14 , V_5 ) ;
if ( V_5 == V_23 || V_5 >= V_2 -> V_19 )
break;
}
}
static int F_21 ( struct V_1 * V_2 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
struct V_3 V_4 ;
unsigned int V_51 ;
T_1 V_7 ;
if ( F_4 ( V_14 , V_5 * V_2 -> V_17 + V_9 + 8 , 8 ,
& V_7 , ( char * ) & V_4 ) < 0 )
return - 1 ;
V_51 = F_5 ( ( V_4 . V_56 | V_4 . V_57 ) ) ;
if ( V_51 != V_58 ) {
if ( F_11 ( V_2 , V_5 * V_2 -> V_17 , V_2 -> V_17 , 1 ) != 0 )
return - 1 ;
V_4 . V_56 = F_13 ( V_58 ) ;
V_4 . V_57 = F_13 ( V_58 ) ;
V_4 . V_59 = F_14 ( 0 ) ;
if ( F_16 ( V_14 ,
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
static int F_22 ( struct V_1 * V_2 , unsigned int V_5 )
{
struct V_13 * V_14 = V_2 -> V_15 . V_14 ;
struct V_76 V_52 ;
T_1 V_7 ;
if ( F_4 ( V_14 , V_5 * V_2 -> V_17 + 2 * V_9 + 8 ,
8 , & V_7 , ( char * ) & V_52 ) < 0 )
return 0 ;
return F_5 ( ( V_52 . V_77 | V_52 . V_78 ) ) ;
}
int F_23 ( struct V_1 * V_79 )
{
int V_16 ;
unsigned int V_80 , V_81 , V_82 , V_50 , V_51 ;
unsigned int V_5 , V_64 , V_83 ;
int V_84 , V_85 ;
struct V_86 V_87 ;
struct V_3 V_4 ;
struct V_13 * V_14 = V_79 -> V_15 . V_14 ;
T_1 V_7 ;
if ( F_1 ( V_79 ) < 0 ) {
F_3 ( L_18 ) ;
return - 1 ;
}
for ( V_16 = 0 ; V_16 < V_79 -> V_19 ; V_16 ++ ) {
V_79 -> V_38 [ V_16 ] = V_23 ;
}
V_80 = 0 ;
for ( V_64 = 0 ; V_64 < V_79 -> V_19 ; V_64 ++ ) {
if ( V_79 -> V_30 [ V_64 ] == V_42 ) {
V_5 = V_64 ;
V_84 = 0 ;
V_85 = 0 ;
for (; ; ) {
if ( F_4 ( V_14 ,
V_5 * V_79 -> V_17 + 8 , 8 ,
& V_7 , ( char * ) & V_87 ) < 0 ||
F_4 ( V_14 ,
V_5 * V_79 -> V_17 +
V_9 + 8 , 8 ,
& V_7 , ( char * ) & V_4 ) < 0 ) {
V_79 -> V_30 [ V_5 ] = V_23 ;
V_85 = 1 ;
break;
}
V_81 = F_5 ( ( V_87 . V_88 | V_87 . V_89 ) ) ;
V_82 = F_5 ( ( V_87 . V_90 | V_87 . V_91 ) ) ;
V_50 = F_6 ( V_4 . V_59 ) ;
V_51 = F_5 ( ( V_4 . V_56 | V_4 . V_57 ) ) ;
V_83 = ! ( V_81 >> 15 ) ;
V_81 = V_81 & 0x7fff ;
if ( V_51 != V_58 || V_81 >= V_79 -> V_19 ) {
if ( V_84 == 0 ) {
if ( F_21 ( V_79 , V_5 ) < 0 ) {
F_3 ( L_17 , V_5 ) ;
if ( F_12 ( V_79 , V_5 ) < 0 ) {
V_79 -> V_30 [ V_5 ] = V_31 ;
} else {
V_79 -> V_30 [ V_5 ] = V_75 ;
}
} else {
V_79 -> V_30 [ V_5 ] = V_75 ;
}
goto V_92;
} else {
F_3 ( L_19 ,
V_5 , V_64 ) ;
V_79 -> V_30 [ V_5 ] = V_23 ;
V_85 = 1 ;
break;
}
}
if ( V_84 == 0 ) {
if ( ! V_83 )
goto V_92;
V_80 = V_81 ;
} else {
if ( V_81 != V_80 ) {
F_3 ( L_20 ,
V_5 , V_81 , V_80 ) ;
V_85 = 1 ;
}
if ( V_83 ) {
if ( F_22 ( V_79 , V_5 ) != V_93 ||
V_82 != 0xffff ) {
F_3 ( L_21 ,
V_5 ) ;
V_85 = 1 ;
} else {
F_3 ( L_22 ,
V_5 ) ;
}
}
}
V_84 ++ ;
if ( V_82 == 0xffff ) {
V_79 -> V_30 [ V_5 ] = V_23 ;
break;
} else if ( V_82 >= V_79 -> V_19 ) {
F_3 ( L_23 ,
V_5 , V_82 ) ;
V_85 = 1 ;
V_79 -> V_30 [ V_5 ] = V_23 ;
break;
} else if ( V_79 -> V_30 [ V_82 ] != V_42 ) {
if ( V_79 -> V_30 [ V_82 ] == V_23 &&
V_79 -> V_38 [ V_80 ] == V_82 &&
F_22 ( V_79 , V_64 ) == V_93 ) {
F_3 ( L_22 ,
V_82 ) ;
V_79 -> V_30 [ V_5 ] = V_82 ;
V_79 -> V_38 [ V_80 ] = V_23 ;
} else {
F_3 ( L_24 ,
V_5 , V_82 ) ;
V_85 = 1 ;
V_79 -> V_30 [ V_5 ] = V_23 ;
}
break;
} else {
V_79 -> V_30 [ V_5 ] = V_82 ;
V_5 = V_82 ;
}
}
if ( V_85 ) {
F_20 ( V_79 , V_64 ) ;
} else {
unsigned int V_94 , V_95 , V_96 ;
int V_97 ;
V_97 = F_22 ( V_79 , V_64 ) ;
if ( V_97 == 0 ) {
F_3 ( L_25 , V_64 ) ;
F_20 ( V_79 , V_64 ) ;
} else {
if ( V_97 == V_93 )
F_18 ( V_79 , V_64 ) ;
V_94 = V_79 -> V_38 [ V_80 ] ;
if ( V_94 != V_23 ) {
V_96 = F_19 ( V_79 , V_94 ) ;
F_3 ( L_26 ,
V_94 , V_96 , V_64 , V_84 ) ;
if ( V_84 >= V_96 ) {
V_95 = V_94 ;
V_79 -> V_38 [ V_80 ] = V_64 ;
} else {
V_95 = V_64 ;
}
F_20 ( V_79 , V_95 ) ;
} else {
V_79 -> V_38 [ V_80 ] = V_64 ;
}
}
}
}
V_92: ;
}
V_79 -> V_98 = 0 ;
V_79 -> V_99 = F_5 ( V_79 -> V_12 . V_33 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_19 ; V_5 ++ ) {
if ( V_79 -> V_30 [ V_5 ] == V_42 ) {
F_3 ( L_27 , V_5 ) ;
if ( F_12 ( V_79 , V_5 ) < 0 )
V_79 -> V_30 [ V_5 ] = V_31 ;
else
V_79 -> V_30 [ V_5 ] = V_75 ;
}
if ( V_79 -> V_30 [ V_5 ] == V_75 ) {
V_79 -> V_98 ++ ;
V_79 -> V_99 = V_5 ;
}
}
return 0 ;
}
