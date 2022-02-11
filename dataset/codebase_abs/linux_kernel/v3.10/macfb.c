static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
static int V_7 = - 1 ;
unsigned long V_8 ;
F_2 ( V_8 ) ;
if ( V_1 != V_7 + 1 ) {
int V_9 ;
F_3 ( 0 , & V_10 -> V_11 ) ;
F_4 () ;
for ( V_9 = 0 ; V_9 < V_1 ; V_9 ++ ) {
F_5 ( V_6 -> V_12 . V_2 [ V_9 ] >> 8 ,
& V_10 -> V_13 ) ;
F_4 () ;
F_5 ( V_6 -> V_12 . V_3 [ V_9 ] >> 8 ,
& V_10 -> V_13 ) ;
F_4 () ;
F_5 ( V_6 -> V_12 . V_4 [ V_9 ] >> 8 ,
& V_10 -> V_13 ) ;
F_4 () ;
}
}
F_5 ( V_2 , & V_10 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_10 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_10 -> V_13 ) ;
F_6 ( V_8 ) ;
V_7 = V_1 ;
return 0 ;
}
static int F_7 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
unsigned int V_14 = V_6 -> V_15 . V_16 ;
unsigned long V_8 ;
if ( V_14 > 8 )
return 1 ;
F_2 ( V_8 ) ;
V_1 = ( V_1 << ( 8 - V_14 ) ) | ( 0xFF >> V_14 ) ;
F_5 ( V_1 , & V_17 -> V_18 ) ;
F_4 () ;
F_5 ( V_2 , & V_17 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_17 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_17 -> V_13 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
unsigned long V_8 ;
if ( V_6 -> V_15 . V_16 > 8 )
return 1 ;
F_2 ( V_8 ) ;
V_1 += 256 - ( 1 << V_6 -> V_15 . V_16 ) ;
F_5 ( 0xFF , & V_19 -> V_20 ) ;
F_4 () ;
F_5 ( V_1 , & V_19 -> V_18 ) ;
F_4 () ;
F_5 ( V_2 , & V_19 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_19 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_19 -> V_13 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_9 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 = V_23 ;
unsigned long V_8 ;
F_2 ( V_8 ) ;
F_5 ( V_1 , & V_22 -> V_18 ) ;
F_4 () ;
F_5 ( V_2 , & V_22 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_22 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_22 -> V_13 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_10 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
struct V_24 * V_22 = V_23 ;
unsigned int V_14 = V_6 -> V_15 . V_16 ;
unsigned long V_8 ;
V_2 = ~ V_2 ;
V_3 = ~ V_3 ;
V_4 = ~ V_4 ;
V_1 = ( V_1 << ( 8 - V_14 ) ) | ( 0xFF >> V_14 ) ;
F_2 ( V_8 ) ;
F_5 ( V_1 , & V_22 -> V_18 ) ;
F_4 () ;
F_5 ( V_2 , & V_22 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_22 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_22 -> V_13 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_11 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
struct V_25 * V_22 = V_23 ;
unsigned long V_8 ;
F_2 ( V_8 ) ;
F_5 ( V_1 , & V_22 -> V_18 ) ;
F_4 () ;
F_5 ( V_2 , & V_22 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_22 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_22 -> V_13 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_12 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
unsigned long V_8 ;
int V_26 ;
if ( V_6 -> V_15 . V_16 > 8 )
return 1 ;
F_2 ( V_8 ) ;
F_5 ( V_1 , & V_27 -> V_18 ) ;
F_4 () ;
V_26 = F_13 ( & V_27 -> V_28 ) ;
if ( ( V_26 & 0x0008 ) == 0 )
{
#if 0
if ((clut_status & 0x000D) != 0)
{
nubus_writeb(0x00, &civic_cmap_regs->lut);
nop();
nubus_writeb(0x00, &civic_cmap_regs->lut);
nop();
}
#endif
F_5 ( V_2 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( 0x00 , & V_27 -> V_13 ) ;
}
else
{
unsigned char V_29 ;
V_29 = F_13 ( & V_27 -> V_13 ) ;
F_4 () ;
V_29 = F_13 ( & V_27 -> V_13 ) ;
F_4 () ;
V_29 = F_13 ( & V_27 -> V_13 ) ;
F_4 () ;
V_29 = F_13 ( & V_27 -> V_13 ) ;
F_4 () ;
if ( ( V_26 & 0x000D ) != 0 )
{
F_5 ( 0x00 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( 0x00 , & V_27 -> V_13 ) ;
F_4 () ;
}
F_5 ( V_2 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( V_3 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( V_4 , & V_27 -> V_13 ) ;
F_4 () ;
F_5 ( V_29 , & V_27 -> V_13 ) ;
}
F_6 ( V_8 ) ;
return 0 ;
}
static int F_14 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 ,
struct V_5 * V_6 )
{
unsigned long V_8 ;
F_2 ( V_8 ) ;
F_15 ( 1 ) ;
F_5 ( V_1 , & V_30 -> V_31 ) ;
F_5 ( V_2 , & V_30 -> V_32 ) ;
F_5 ( V_3 , & V_30 -> V_32 ) ;
F_5 ( V_4 , & V_30 -> V_32 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_16 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_33 ,
struct V_5 * V_5 )
{
if ( V_1 >= V_5 -> V_12 . V_34 )
return 1 ;
if ( V_5 -> V_15 . V_16 <= 8 ) {
switch ( V_5 -> V_15 . V_16 ) {
case 1 :
break;
case 2 :
case 4 :
case 8 :
if ( V_35 )
V_35 ( V_1 , V_2 >> 8 , V_3 >> 8 ,
V_4 >> 8 , V_5 ) ;
else
return 1 ;
break;
}
} else if ( V_1 < 16 ) {
switch ( V_5 -> V_15 . V_16 ) {
case 16 :
if ( V_5 -> V_15 . V_2 . V_36 == 10 ) {
( ( V_37 * ) ( V_5 -> V_38 ) ) [ V_1 ] =
( ( V_2 & 0xf800 ) >> 1 ) |
( ( V_3 & 0xf800 ) >> 6 ) |
( ( V_4 & 0xf800 ) >> 11 ) |
( ( V_33 != 0 ) << 15 ) ;
} else {
( ( V_37 * ) ( V_5 -> V_38 ) ) [ V_1 ] =
( ( V_2 & 0xf800 ) >> 0 ) |
( ( V_3 & 0xfc00 ) >> 5 ) |
( ( V_4 & 0xf800 ) >> 11 ) ;
}
break;
case 24 :
case 32 :
V_2 >>= 8 ;
V_3 >>= 8 ;
V_4 >>= 8 ;
( ( V_37 * ) ( V_5 -> V_38 ) ) [ V_1 ] =
( V_2 << V_5 -> V_15 . V_2 . V_36 ) |
( V_3 << V_5 -> V_15 . V_3 . V_36 ) |
( V_4 << V_5 -> V_15 . V_4 . V_36 ) ;
break;
}
}
return 0 ;
}
static void T_1 F_17 ( char * V_39 )
{
char * V_40 ;
if ( ! V_39 || ! * V_39 )
return;
while ( ( V_40 = F_18 ( & V_39 , L_1 ) ) != NULL ) {
if ( ! * V_40 )
continue;
if ( ! strcmp ( V_40 , L_2 ) )
V_41 = 1 ;
else
if ( ! strcmp ( V_40 , L_3 ) )
V_42 = 1 ;
}
}
static void T_1 F_19 ( void )
{
if ( V_10 )
F_20 ( V_10 ) ;
if ( V_17 )
F_20 ( V_17 ) ;
if ( V_19 )
F_20 ( V_19 ) ;
if ( V_27 )
F_20 ( V_27 ) ;
if ( V_30 )
F_20 ( V_30 ) ;
}
static int T_1 F_21 ( void )
{
int V_43 , V_44 = 0 ;
struct V_45 * V_46 = NULL ;
char * V_47 = NULL ;
int V_48 ;
if ( F_22 ( L_4 , & V_47 ) )
return - V_49 ;
F_17 ( V_47 ) ;
if ( ! V_50 )
return - V_49 ;
if ( V_51 . V_52 == V_53 ||
V_51 . V_52 == V_54 )
return - V_49 ;
V_55 . V_56 = V_51 . V_57 & 0xFFFF ;
V_55 . V_58 = V_51 . V_57 >> 16 ;
V_55 . V_16 = V_51 . V_59 ;
V_60 . V_61 = V_51 . V_62 ;
V_60 . V_63 = V_60 . V_61 * V_55 . V_58 ;
V_60 . V_64 = V_51 . V_65 ;
V_5 . V_66 = F_23 ( V_51 . V_65 ,
V_60 . V_63 ) ;
if ( ! V_5 . V_66 )
return - V_49 ;
F_24 ( L_5 ,
V_60 . V_64 , V_5 . V_66 ,
V_60 . V_63 / 1024 ) ;
F_24 ( L_6 ,
V_55 . V_56 , V_55 . V_58 ,
V_55 . V_16 , V_60 . V_61 ) ;
V_55 . V_67 = V_55 . V_56 ;
V_55 . V_68 = V_55 . V_58 ;
V_55 . V_69 = F_25 ( V_55 . V_58 ) ;
V_55 . V_70 = F_25 ( V_55 . V_56 ) ;
V_55 . V_71 = 10000000 / V_55 . V_56 *
1000 / V_55 . V_58 ;
V_55 . V_72 = ( V_55 . V_56 / 8 ) & 0xf8 ;
V_55 . V_73 = ( V_55 . V_56 / 8 ) & 0xf8 ;
switch ( V_55 . V_16 ) {
case 1 :
V_55 . V_2 . V_74 = V_55 . V_16 ;
V_55 . V_3 . V_74 = V_55 . V_16 ;
V_55 . V_4 . V_74 = V_55 . V_16 ;
V_43 = 2 ;
V_60 . V_75 = V_76 ;
break;
case 2 :
case 4 :
case 8 :
V_55 . V_2 . V_74 = V_55 . V_16 ;
V_55 . V_3 . V_74 = V_55 . V_16 ;
V_55 . V_4 . V_74 = V_55 . V_16 ;
V_43 = 1 << V_55 . V_16 ;
V_60 . V_75 = V_77 ;
break;
case 16 :
V_55 . V_33 . V_36 = 15 ;
V_55 . V_33 . V_74 = 1 ;
V_55 . V_2 . V_36 = 10 ;
V_55 . V_2 . V_74 = 5 ;
V_55 . V_3 . V_36 = 5 ;
V_55 . V_3 . V_74 = 5 ;
V_55 . V_4 . V_36 = 0 ;
V_55 . V_4 . V_74 = 5 ;
V_43 = 16 ;
V_60 . V_75 = V_78 ;
break;
case 24 :
case 32 :
V_55 . V_2 . V_36 = 16 ;
V_55 . V_2 . V_74 = 8 ;
V_55 . V_3 . V_36 = 8 ;
V_55 . V_3 . V_74 = 8 ;
V_55 . V_4 . V_36 = 0 ;
V_55 . V_4 . V_74 = 8 ;
V_43 = 16 ;
V_60 . V_75 = V_78 ;
break;
default:
F_26 ( L_7 ,
V_55 . V_16 ) ;
V_48 = - V_79 ;
goto V_80;
}
while ( ( V_46 = F_27 ( V_81 ,
V_82 , V_46 ) ) )
{
unsigned long V_83 = V_46 -> V_84 -> V_23 ;
if ( V_51 . V_65 < V_83 ||
V_51 . V_65 - V_83 > 0xFFFFFF )
continue;
V_44 = 1 ;
V_23 = ( unsigned char * ) V_83 ;
switch( V_46 -> V_85 ) {
case V_86 :
strcpy ( V_60 . V_52 , L_8 ) ;
V_35 = F_9 ;
V_55 . V_87 = V_88 ;
break;
case V_89 :
strcpy ( V_60 . V_52 , L_9 ) ;
V_35 = F_10 ;
V_55 . V_87 = V_88 ;
break;
case V_90 :
strcpy ( V_60 . V_52 , L_10 ) ;
V_35 = F_11 ;
V_55 . V_87 = V_88 ;
break;
default:
strcpy ( V_60 . V_52 , L_11 ) ;
break;
}
}
if ( ! V_44 )
switch ( V_51 . V_52 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
strcpy ( V_60 . V_52 , L_12 ) ;
V_35 = F_1 ;
V_10 = F_23 ( V_103 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
case V_104 :
strcpy ( V_60 . V_52 , L_13 ) ;
V_35 = F_7 ;
V_17 = F_23 ( V_105 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
case V_106 :
case V_107 :
case V_108 :
strcpy ( V_60 . V_52 , L_14 ) ;
V_35 = F_7 ;
V_17 = F_23 ( V_105 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
strcpy ( V_60 . V_52 , L_15 ) ;
V_35 = F_7 ;
V_17 = F_23 ( V_105 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
case V_113 :
case V_114 :
strcpy ( V_60 . V_52 , L_16 ) ;
V_35 = F_8 ;
V_19 = F_23 ( V_105 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
case V_115 :
case V_116 :
strcpy ( V_60 . V_52 , L_17 ) ;
V_35 = F_12 ;
V_27 = F_23 ( V_117 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
case V_118 :
strcpy ( V_60 . V_52 , L_18 ) ;
if ( V_42 ) {
V_35 = F_7 ;
V_17 =
F_23 ( V_105 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
}
break;
case V_119 :
strcpy ( V_60 . V_52 , L_19 ) ;
if ( V_42 ) {
V_35 = F_7 ;
V_17 =
F_23 ( V_105 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
}
break;
case V_120 :
strcpy ( V_60 . V_52 , L_20 ) ;
break;
case V_121 :
case V_122 :
strcpy ( V_60 . V_52 , L_21 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
strcpy ( V_60 . V_52 , L_22 ) ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
strcpy ( V_60 . V_52 , L_23 ) ;
break;
case V_132 :
case V_133 :
strcpy ( V_60 . V_52 , L_24 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
strcpy ( V_60 . V_52 , L_25 ) ;
V_35 = F_14 ;
V_30 = F_23 ( V_140 , 0x1000 ) ;
V_55 . V_87 = V_88 ;
break;
default:
strcpy ( V_60 . V_52 , L_26 ) ;
break;
}
V_5 . V_141 = & V_142 ;
V_5 . V_15 = V_55 ;
V_5 . V_143 = V_60 ;
V_5 . V_38 = V_38 ;
V_5 . V_8 = V_144 ;
V_48 = F_28 ( & V_5 . V_12 , V_43 , 0 ) ;
if ( V_48 )
goto V_80;
V_48 = F_29 ( & V_5 ) ;
if ( V_48 )
goto V_145;
F_24 ( L_27 ,
V_5 . V_146 , V_5 . V_143 . V_52 ) ;
return 0 ;
V_145:
F_30 ( & V_5 . V_12 ) ;
V_80:
F_20 ( V_5 . V_66 ) ;
F_19 () ;
return V_48 ;
}
