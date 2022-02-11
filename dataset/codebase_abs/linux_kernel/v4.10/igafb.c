static inline unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
return F_3 ( V_2 , V_3 + 1 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned char V_5 ,
unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_2 ( V_2 , V_5 , V_3 + 1 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_6 ;
#if 0
(void) pci_inb(par, 0x3DA);
pci_outb(par, IGA_IDX_VGA_OVERSCAN, IGA_ATTR_CTL);
(void) pci_inb(par, IGA_ATTR_CTL+1);
pci_outb(par, 0x38, IGA_ATTR_CTL);
pci_outb(par, 0x20, IGA_ATTR_CTL);
#endif
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ )
F_4 ( V_2 , 0 , V_7 , V_8 + V_6 ) ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_2 ;
unsigned int V_13 , V_14 , V_15 = 0 ;
unsigned long V_16 = 0 ;
int V_6 ;
if ( ! V_2 -> V_17 )
return - V_18 ;
V_13 = V_12 -> V_19 - V_12 -> V_20 ;
for ( V_14 = 0 ; V_14 < V_13 ; ) {
V_15 = 0 ;
for ( V_6 = 0 ; V_2 -> V_17 [ V_6 ] . V_13 ; V_6 ++ ) {
unsigned long V_21 = V_2 -> V_17 [ V_6 ] . V_22 ;
unsigned long V_23 = V_21 + V_2 -> V_17 [ V_6 ] . V_13 ;
unsigned long V_24 = ( V_12 -> V_25 << V_26 ) + V_14 ;
if ( V_21 > V_24 )
continue;
if ( V_24 >= V_23 )
continue;
V_15 = V_2 -> V_17 [ V_6 ] . V_13 - ( V_24 - V_21 ) ;
V_16 = V_2 -> V_17 [ V_6 ] . V_27 + ( V_24 - V_21 ) ;
break;
}
if ( ! V_15 ) {
V_14 += V_28 ;
continue;
}
if ( V_14 + V_15 > V_13 )
V_15 = V_13 - V_14 ;
F_7 ( V_12 -> V_29 ) &= ~ ( V_2 -> V_17 [ V_6 ] . V_30 ) ;
F_7 ( V_12 -> V_29 ) |= V_2 -> V_17 [ V_6 ] . V_31 ;
if ( F_8 ( V_12 , V_12 -> V_20 + V_14 ,
V_16 >> V_26 , V_15 , V_12 -> V_29 ) )
return - V_32 ;
V_14 += V_15 ;
}
if ( ! V_15 )
return - V_33 ;
V_12 -> V_34 |= V_35 ;
return 0 ;
}
static int F_9 ( unsigned V_36 , unsigned V_37 , unsigned V_38 ,
unsigned V_39 , unsigned V_40 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_2 ;
if ( V_36 >= V_10 -> V_41 . V_42 )
return 1 ;
F_2 ( V_2 , V_36 , V_43 ) ;
F_2 ( V_2 , V_37 , V_44 ) ;
F_2 ( V_2 , V_38 , V_44 ) ;
F_2 ( V_2 , V_39 , V_44 ) ;
if ( V_36 < 16 ) {
switch ( V_10 -> V_45 . V_46 ) {
case 16 :
( ( V_47 * ) ( V_10 -> V_48 ) ) [ V_36 ] =
( V_36 << 10 ) | ( V_36 << 5 ) | V_36 ;
break;
case 24 :
( ( V_49 * ) ( V_10 -> V_48 ) ) [ V_36 ] =
( V_36 << 16 ) | ( V_36 << 8 ) | V_36 ;
break;
case 32 :
{ int V_6 ;
V_6 = ( V_36 << 8 ) | V_36 ;
( ( V_49 * ) ( V_10 -> V_48 ) ) [ V_36 ] = ( V_6 << 16 ) | V_6 ;
}
break;
}
}
return 0 ;
}
static int T_1 F_10 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
char V_50 = F_1 ( V_2 , V_7 , V_51 )
& V_52 ;
int V_53 ;
switch ( V_50 ) {
case V_54 :
V_10 -> V_55 . V_56 = 0x100000 ;
break;
case V_57 :
V_10 -> V_55 . V_56 = 0x200000 ;
break;
case V_58 :
case V_59 :
V_10 -> V_55 . V_56 = 0x400000 ;
break;
}
if ( V_10 -> V_45 . V_46 > 8 )
V_53 = 16 ;
else
V_53 = 256 ;
V_10 -> V_60 = & V_61 ;
V_10 -> V_62 = V_63 ;
F_11 ( & V_10 -> V_41 , V_53 , 0 ) ;
if ( F_12 ( V_10 ) < 0 )
return 0 ;
V_9 ( V_10 , L_1 ,
V_10 -> V_55 . V_64 , V_2 -> V_65 , V_10 -> V_55 . V_56 >> 20 ) ;
F_5 ( V_2 ) ;
return 1 ;
}
static int T_1 F_13 ( void )
{
struct V_9 * V_10 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
unsigned long V_68 ;
int V_13 , V_69 = 0 ;
if ( F_14 ( L_2 , NULL ) )
return - V_70 ;
V_67 = F_15 ( V_71 ,
V_72 , 0 ) ;
if ( V_67 == NULL ) {
V_67 = F_15 ( V_71 , 0x2000 , 0 ) ;
if( V_67 == NULL ) {
return - V_18 ;
}
V_69 = 1 ;
}
V_13 = sizeof( struct V_1 ) + sizeof( V_49 ) * 16 ;
V_10 = F_16 ( V_13 , & V_67 -> V_73 ) ;
if ( ! V_10 ) {
F_17 ( L_3 ) ;
F_18 ( V_67 ) ;
return - V_74 ;
}
V_2 = V_10 -> V_2 ;
if ( ( V_68 = V_67 -> V_75 [ 0 ] . V_21 ) == 0 ) {
F_17 ( L_4 ) ;
F_19 ( V_10 ) ;
F_18 ( V_67 ) ;
return - V_18 ;
}
if ( ( V_10 -> V_76 = F_20 ( V_68 , 1024 * 1024 * 2 ) ) == 0 ) {
F_17 ( L_5 , V_68 ) ;
F_19 ( V_10 ) ;
F_18 ( V_67 ) ;
return - V_18 ;
}
V_2 -> V_65 = V_68 & V_77 ;
#ifdef F_21
if ( V_69 ) {
V_78 . V_79 = V_2 -> V_65 | 0x00800000 ;
} else {
V_78 . V_79 = 0x30000000 ;
}
if ( ( V_2 -> V_80 = ( int ) F_20 ( V_78 . V_79 , V_78 . V_56 ) ) == 0 ) {
F_17 ( L_6 , V_78 . V_79 ) ;
F_22 ( ( void * ) V_10 -> V_76 ) ;
F_19 ( V_10 ) ;
F_18 ( V_67 ) ;
return - V_18 ;
}
V_2 -> V_17 = F_23 ( 4 * sizeof( * V_2 -> V_17 ) , V_81 ) ;
if ( ! V_2 -> V_17 ) {
F_17 ( L_7 ) ;
F_22 ( ( void * ) V_2 -> V_80 ) ;
F_22 ( V_10 -> V_76 ) ;
F_19 ( V_10 ) ;
F_18 ( V_67 ) ;
return - V_74 ;
}
{
struct V_82 * V_83 = F_24 ( V_67 ) ;
int V_84 = V_83 -> V_84 ;
int V_85 = F_25 ( V_84 , L_8 , 1024 ) ;
int V_86 = F_25 ( V_84 , L_9 , 768 ) ;
int V_87 = F_25 ( V_84 , L_10 , 8 ) ;
switch ( V_85 ) {
case 1024 :
if ( V_86 == 768 )
V_88 = V_89 ;
break;
case 1152 :
if ( V_86 == 900 )
V_88 = V_90 ;
break;
case 1280 :
if ( V_86 == 1024 )
V_88 = V_91 ;
break;
default:
break;
}
switch ( V_87 ) {
case 8 :
V_88 . V_46 = 8 ;
break;
case 16 :
V_88 . V_46 = 16 ;
break;
case 24 :
V_88 . V_46 = 24 ;
break;
case 32 :
V_88 . V_46 = 32 ;
break;
default:
break;
}
}
#endif
V_78 . V_92 = ( unsigned long ) V_10 -> V_76 ;
V_78 . V_93 = V_88 . V_94 * ( V_88 . V_46 / 8 ) ;
V_78 . V_95 = V_88 . V_46 <= 8 ? V_96 : V_97 ;
V_10 -> V_45 = V_88 ;
V_10 -> V_55 = V_78 ;
V_10 -> V_48 = ( void * ) ( V_2 + 1 ) ;
if ( ! F_10 ( V_10 , V_2 ) ) {
F_22 ( ( void * ) V_2 -> V_80 ) ;
F_22 ( V_10 -> V_76 ) ;
F_19 ( V_2 -> V_17 ) ;
F_19 ( V_10 ) ;
return - V_70 ;
}
#ifdef F_21
V_2 -> V_17 [ 0 ] . V_22 = 0x0 ;
V_2 -> V_17 [ 0 ] . V_27 = V_2 -> V_65 & V_98 ;
V_2 -> V_17 [ 0 ] . V_13 = V_10 -> V_55 . V_56 & V_98 ;
V_2 -> V_17 [ 0 ] . V_30 = V_99 ;
V_2 -> V_17 [ 0 ] . V_31 = V_100 ;
V_2 -> V_17 [ 1 ] . V_22 = V_2 -> V_65 & V_98 ;
V_2 -> V_17 [ 1 ] . V_27 = V_10 -> V_55 . V_92 & V_98 ;
V_2 -> V_17 [ 1 ] . V_13 = V_28 * 2 ;
V_2 -> V_17 [ 1 ] . V_30 = V_99 ;
V_2 -> V_17 [ 1 ] . V_31 = V_100 ;
#endif
return 0 ;
}
static int T_1 F_26 ( char * V_101 )
{
char * V_102 ;
if ( ! V_101 || ! * V_101 )
return 0 ;
while ( ( V_102 = F_27 ( & V_101 , L_11 ) ) != NULL ) {
}
return 0 ;
}
