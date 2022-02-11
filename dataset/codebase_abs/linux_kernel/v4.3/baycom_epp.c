static inline int F_1 ( const unsigned char * V_1 , int V_2 )
{
return ( F_2 ( 0xffff , V_1 , V_2 ) & 0xffff ) == 0xf0b8 ;
}
static inline int F_3 ( const unsigned char * V_1 , int V_2 )
{
return ( F_2 ( 0xffff , V_1 , V_2 ) ^ 0xffff ) & 0xffff ;
}
static inline void F_4 ( struct V_3 * V_4 )
{
#ifdef F_5
unsigned long V_5 = V_6 ;
V_4 -> V_7 . V_8 ++ ;
if ( F_6 ( V_5 , V_4 -> V_7 . V_9 + V_10 ) ) {
V_4 -> V_7 . V_9 = V_5 ;
V_4 -> V_7 . V_11 = V_4 -> V_7 . V_8 ;
V_4 -> V_7 . V_8 = 0 ;
V_4 -> V_7 . V_12 = V_4 -> V_7 . V_13 ;
V_4 -> V_7 . V_13 = 0 ;
}
#endif
}
static int F_7 ( struct V_3 * V_4 )
{
char V_14 [ 256 ] ;
char V_15 [ 16 ] ;
char * V_16 [] = { V_17 , L_1 , L_2 , V_15 , L_3 , V_14 ,
NULL } ;
sprintf ( V_14 , L_4 ,
V_4 -> V_18 . V_19 ? L_5 : L_6 ,
V_4 -> V_18 . V_20 ? L_6 : L_5 , V_4 -> V_18 . V_21 , V_4 -> V_18 . V_22 ,
( V_4 -> V_18 . V_21 + 8 * V_4 -> V_18 . V_22 ) / ( 16 * V_4 -> V_18 . V_22 ) ,
V_4 -> V_18 . V_23 ? L_7 : L_8 ) ;
sprintf ( V_15 , L_9 , V_4 -> V_24 -> V_25 -> V_26 ) ;
F_8 ( V_27 L_10 , V_28 , V_17 , V_15 , V_14 ) ;
return F_9 ( V_17 , V_16 , V_29 , V_30 ) ;
}
static inline void F_10 ( struct V_3 * V_4 ,
unsigned char * V_31 , unsigned long V_32 )
{
#ifdef F_11
#define F_12 ( T_1 , T_2 ) printk(KERN_INFO "baycomm_epp: channel params: " a "\n", b)
#else
#define F_12 ( T_1 , T_2 )
#endif
if ( V_32 < 2 )
return;
switch( V_31 [ 0 ] ) {
case V_33 :
V_4 -> V_34 . V_35 = V_31 [ 1 ] ;
F_12 ( L_11 , 10 * V_4 -> V_34 . V_35 ) ;
break;
case V_36 :
V_4 -> V_34 . V_37 = V_31 [ 1 ] ;
F_12 ( L_12 , V_4 -> V_34 . V_37 ) ;
break;
case V_38 :
V_4 -> V_34 . V_39 = V_31 [ 1 ] ;
F_12 ( L_13 , V_4 -> V_34 . V_39 ) ;
break;
case V_40 :
V_4 -> V_34 . V_41 = V_31 [ 1 ] ;
F_12 ( L_14 , V_4 -> V_34 . V_41 ) ;
break;
case V_42 :
V_4 -> V_34 . V_43 = ! ! V_31 [ 1 ] ;
F_12 ( L_15 , V_4 -> V_34 . V_43 ? L_16 : L_17 ) ;
break;
default:
break;
}
#undef F_12
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_44 * V_45 ;
unsigned char * V_46 , * V_47 ;
int V_48 ;
unsigned V_49 , V_50 , V_51 , V_52 , V_53 ;
unsigned char V_54 [ 2 ] ;
int V_55 ;
if ( V_4 -> V_56 . V_57 > 0 )
return;
V_45 = V_4 -> V_45 ;
if ( ! V_45 )
return;
V_4 -> V_45 = NULL ;
V_48 = V_45 -> V_32 - 1 ;
V_46 = V_4 -> V_56 . V_1 ;
V_47 = V_45 -> V_31 + 1 ;
V_53 = F_3 ( V_47 , V_48 ) ;
V_54 [ 0 ] = V_53 ;
V_54 [ 1 ] = V_53 >> 8 ;
* V_46 ++ = 0x7e ;
V_49 = V_51 = V_52 = 0 ;
while ( V_48 > - 2 ) {
V_49 >>= 8 ;
V_49 |= ( ( unsigned int ) * V_47 ) << 8 ;
V_51 |= ( ( unsigned int ) * V_47 ) << V_52 ;
V_50 = ~ V_49 ;
V_47 ++ ;
V_48 -- ;
if ( ! V_48 )
V_47 = V_54 ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ )
if ( F_14 ( ! ( V_50 & ( 0x1f0 << V_55 ) ) ) ) {
V_49 &= ~ ( 0x100 << V_55 ) ;
V_51 = ( V_51 & ( ( ( 2 << V_55 ) << V_52 ) - 1 ) ) |
( ( V_51 & ~ ( ( ( 2 << V_55 ) << V_52 ) - 1 ) ) << 1 ) ;
V_52 ++ ;
V_50 = ~ V_49 ;
}
V_52 += 8 ;
while ( V_52 >= 8 ) {
* V_46 ++ = V_51 ;
V_51 >>= 8 ;
V_52 -= 8 ;
}
}
V_51 |= 0x7e7e << V_52 ;
V_52 += 16 ;
while ( V_52 >= 8 ) {
* V_46 ++ = V_51 ;
V_51 >>= 8 ;
V_52 -= 8 ;
}
V_4 -> V_56 . V_58 = V_4 -> V_56 . V_1 ;
V_4 -> V_56 . V_57 = V_46 - V_4 -> V_56 . V_1 ;
F_15 ( V_45 ) ;
V_4 -> V_59 -> V_60 . V_61 ++ ;
}
static int F_16 ( struct V_3 * V_4 , int V_2 , unsigned char V_62 )
{
struct V_63 * V_64 = V_4 -> V_24 -> V_25 ;
unsigned char V_65 [ 128 ] ;
int V_66 , V_55 ;
if ( V_4 -> V_56 . V_67 == V_41 && ! ( V_62 & V_68 ) )
V_4 -> V_56 . V_67 = V_69 ;
if ( V_4 -> V_56 . V_67 == V_69 && V_4 -> V_56 . V_70 <= 0 ) {
if ( V_4 -> V_56 . V_57 <= 0 )
F_13 ( V_4 ) ;
if ( V_4 -> V_56 . V_57 <= 0 )
return 0 ;
if ( ! V_4 -> V_34 . V_43 ) {
if ( ! ( V_62 & V_71 ) ) {
V_4 -> V_56 . V_72 = V_4 -> V_34 . V_39 ;
return 0 ;
}
if ( ( -- V_4 -> V_56 . V_72 ) > 0 )
return 0 ;
V_4 -> V_56 . V_72 = V_4 -> V_34 . V_39 ;
if ( ( F_17 () % 256 ) > V_4 -> V_34 . V_37 )
return 0 ;
}
}
if ( V_4 -> V_56 . V_67 == V_69 && V_4 -> V_56 . V_57 > 0 ) {
V_4 -> V_56 . V_67 = V_73 ;
V_4 -> V_56 . V_74 = F_18 ( V_4 , V_4 -> V_34 . V_35 ) ;
V_4 -> V_75 ++ ;
}
while ( V_2 > 0 ) {
switch ( V_4 -> V_56 . V_67 ) {
case V_73 :
V_66 = F_19 ( int , V_2 , V_4 -> V_56 . V_74 ) ;
V_2 -= V_66 ;
V_4 -> V_56 . V_74 -= V_66 ;
if ( V_4 -> V_56 . V_74 <= 0 )
V_4 -> V_56 . V_67 = V_76 ;
memset ( V_65 , 0x7e , sizeof( V_65 ) ) ;
while ( V_66 > 0 ) {
V_55 = ( V_66 > sizeof( V_65 ) ) ? sizeof( V_65 ) : V_66 ;
if ( V_55 != V_64 -> V_77 -> V_78 ( V_64 , V_65 , V_55 , 0 ) )
return - 1 ;
V_66 -= V_55 ;
}
break;
case V_76 :
if ( V_4 -> V_56 . V_57 <= 0 ) {
F_13 ( V_4 ) ;
if ( V_4 -> V_56 . V_57 <= 0 ) {
V_4 -> V_56 . V_67 = V_41 ;
V_4 -> V_56 . V_74 = F_18 ( V_4 , V_4 -> V_34 . V_41 ) ;
break;
}
}
V_66 = F_19 ( int , V_2 , V_4 -> V_56 . V_57 ) ;
V_4 -> V_56 . V_57 -= V_66 ;
V_2 -= V_66 ;
if ( V_66 != V_64 -> V_77 -> V_78 ( V_64 , V_4 -> V_56 . V_58 , V_66 , 0 ) )
return - 1 ;
V_4 -> V_56 . V_58 += V_66 ;
break;
case V_41 :
F_13 ( V_4 ) ;
if ( V_4 -> V_56 . V_57 > 0 ) {
V_4 -> V_56 . V_67 = V_76 ;
break;
}
V_66 = F_19 ( int , V_2 , V_4 -> V_56 . V_74 ) ;
if ( V_66 ) {
V_2 -= V_66 ;
V_4 -> V_56 . V_74 -= V_66 ;
memset ( V_65 , 0x7e , sizeof( V_65 ) ) ;
while ( V_66 > 0 ) {
V_55 = ( V_66 > sizeof( V_65 ) ) ? sizeof( V_65 ) : V_66 ;
if ( V_55 != V_64 -> V_77 -> V_78 ( V_64 , V_65 , V_55 , 0 ) )
return - 1 ;
V_66 -= V_55 ;
}
break;
}
default:
if ( V_4 -> V_56 . V_70 <= 0 )
return 0 ;
V_66 = F_19 ( int , V_2 , V_4 -> V_56 . V_70 ) ;
V_2 -= V_66 ;
V_4 -> V_56 . V_70 -= V_66 ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
while ( V_66 > 0 ) {
V_55 = ( V_66 > sizeof( V_65 ) ) ? sizeof( V_65 ) : V_66 ;
if ( V_55 != V_64 -> V_77 -> V_78 ( V_64 , V_65 , V_55 , 0 ) )
return - 1 ;
V_66 -= V_55 ;
}
break;
}
}
return 0 ;
}
static void F_20 ( struct V_79 * V_59 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
struct V_44 * V_45 ;
unsigned char * V_80 ;
unsigned V_81 ;
if ( V_4 -> V_82 . V_57 < 4 )
return;
if ( ! F_1 ( V_4 -> V_82 . V_1 , V_4 -> V_82 . V_57 ) )
return;
V_81 = V_4 -> V_82 . V_57 - 2 + 1 ;
if ( ! ( V_45 = F_22 ( V_81 ) ) ) {
F_8 ( L_18 , V_59 -> V_83 ) ;
V_59 -> V_60 . V_84 ++ ;
return;
}
V_80 = F_23 ( V_45 , V_81 ) ;
* V_80 ++ = 0 ;
memcpy ( V_80 , V_4 -> V_82 . V_1 , V_81 - 1 ) ;
V_45 -> V_85 = F_24 ( V_45 , V_59 ) ;
F_25 ( V_45 ) ;
V_59 -> V_60 . V_86 ++ ;
}
static int F_26 ( struct V_79 * V_59 , int V_2 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
struct V_63 * V_64 = V_4 -> V_24 -> V_25 ;
unsigned int V_51 , V_50 , V_49 , V_87 , V_67 ;
unsigned char V_65 [ 128 ] ;
unsigned char * V_80 ;
int V_88 , V_89 = 0 ;
int V_55 ;
V_87 = V_4 -> V_82 . V_87 ;
V_67 = V_4 -> V_82 . V_67 ;
V_49 = V_4 -> V_82 . V_49 ;
V_51 = V_4 -> V_82 . V_51 ;
while ( V_2 > 0 ) {
V_88 = ( V_2 > sizeof( V_65 ) ) ? sizeof( V_65 ) : V_2 ;
V_2 -= V_88 ;
if ( V_88 != V_64 -> V_77 -> V_90 ( V_64 , V_65 , V_88 , 0 ) ) {
V_89 = - 1 ;
break;
}
V_80 = V_65 ;
for (; V_88 > 0 ; V_88 -- , V_80 ++ ) {
V_49 >>= 8 ;
V_49 |= ( * V_80 ) << 8 ;
V_51 >>= 8 ;
V_51 |= ( * V_80 ) << 8 ;
V_87 += 8 ;
V_50 = ~ V_49 ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
if ( F_14 ( ! ( V_50 & ( 0x0fc << V_55 ) ) ) ) {
if ( ! ( V_50 & ( 0x1fc << V_55 ) ) )
V_67 = 0 ;
else if ( ( V_49 & ( 0x1fe << V_55 ) ) == ( 0x0fc << V_55 ) ) {
if ( V_67 )
F_20 ( V_59 ) ;
V_4 -> V_82 . V_57 = 0 ;
V_4 -> V_82 . V_58 = V_4 -> V_82 . V_1 ;
V_67 = 1 ;
V_87 = 7 - V_55 ;
}
}
else if ( F_14 ( ( V_49 & ( 0x1f8 << V_55 ) ) == ( 0xf8 << V_55 ) ) ) {
V_87 -- ;
V_51 = ( V_51 & ( ( ~ 0xff ) << V_55 ) ) | ( ( V_51 & ~ ( ( ~ 0xff ) << V_55 ) ) << 1 ) ;
}
}
while ( V_67 && V_87 >= 8 ) {
if ( V_4 -> V_82 . V_57 >= V_91 ) {
V_67 = 0 ;
} else {
* ( V_4 -> V_82 . V_58 ) ++ = V_51 >> ( 16 - V_87 ) ;
V_4 -> V_82 . V_57 ++ ;
V_87 -= 8 ;
}
}
}
}
V_4 -> V_82 . V_87 = V_87 ;
V_4 -> V_82 . V_67 = V_67 ;
V_4 -> V_82 . V_49 = V_49 ;
V_4 -> V_82 . V_51 = V_51 ;
return V_89 ;
}
static void F_27 ( struct V_92 * V_93 )
{
struct V_79 * V_59 ;
struct V_3 * V_4 ;
struct V_63 * V_64 ;
unsigned char V_62 ;
unsigned char V_65 [ 2 ] ;
unsigned int V_94 = 0 , V_95 = 0 , V_96 = 0 ;
int V_2 , V_88 ;
V_4 = F_28 ( V_93 , struct V_3 , V_97 . V_93 ) ;
V_59 = V_4 -> V_59 ;
if ( ! V_4 -> V_98 )
return;
F_4 ( V_4 ) ;
V_64 = V_4 -> V_24 -> V_25 ;
if ( V_64 -> V_77 -> V_99 ( V_64 , & V_62 , 1 , 0 ) != 1 )
goto V_100;
V_4 -> V_62 = V_62 ;
V_4 -> V_7 . V_12 = V_62 ;
F_29 ( V_94 ) ;
if ( V_4 -> V_101 == V_102 ) {
V_65 [ 0 ] = V_103 | V_104 | V_105 | 1 ;
if ( V_64 -> V_77 -> V_106 ( V_64 , V_65 , 1 , 0 ) != 1 )
goto V_100;
if ( V_64 -> V_77 -> V_99 ( V_64 , V_65 , 2 , 0 ) != 2 )
goto V_100;
V_2 = V_65 [ 0 ] | ( V_65 [ 1 ] << 8 ) ;
V_2 &= 0x7fff ;
V_65 [ 0 ] = V_103 | V_104 | V_105 | 2 ;
if ( V_64 -> V_77 -> V_106 ( V_64 , V_65 , 1 , 0 ) != 1 )
goto V_100;
if ( V_64 -> V_77 -> V_99 ( V_64 , V_65 , 2 , 0 ) != 2 )
goto V_100;
V_88 = V_65 [ 0 ] | ( V_65 [ 1 ] << 8 ) ;
V_88 = 16384 - ( V_88 & 0x7fff ) ;
V_65 [ 0 ] = V_103 | V_104 | V_105 ;
if ( V_64 -> V_77 -> V_106 ( V_64 , V_65 , 1 , 0 ) != 1 )
goto V_100;
if ( F_16 ( V_4 , V_88 , V_62 ) )
goto V_100;
F_29 ( V_95 ) ;
if ( F_26 ( V_59 , V_2 ) )
goto V_100;
if ( V_64 -> V_77 -> V_99 ( V_64 , & V_62 , 1 , 0 ) != 1 )
goto V_100;
V_4 -> V_62 = V_62 ;
} else {
switch ( V_62 & ( V_107 | V_108 ) ) {
case V_108 :
V_2 = 2048 - 256 ;
break;
case V_107 :
V_2 = 2048 - 1793 ;
break;
case 0 :
V_2 = 0 ;
break;
default:
V_2 = 2048 - 1025 ;
break;
}
if ( F_16 ( V_4 , V_2 , V_62 ) )
goto V_100;
F_29 ( V_95 ) ;
while ( ( V_62 & ( V_109 | V_110 ) ) != V_110 ) {
switch ( V_62 & ( V_109 | V_110 ) ) {
case V_109 :
V_2 = 1025 ;
break;
case 0 :
V_2 = 1793 ;
break;
default:
V_2 = 256 ;
break;
}
if ( F_26 ( V_59 , V_2 ) )
goto V_100;
if ( V_64 -> V_77 -> V_99 ( V_64 , & V_62 , 1 , 0 ) != 1 )
goto V_100;
}
V_2 = 0 ;
if ( V_4 -> V_111 < 50000 )
V_2 = 256 ;
else if ( V_4 -> V_111 < 100000 )
V_2 = 128 ;
while ( V_2 > 0 && V_62 & V_112 ) {
if ( F_26 ( V_59 , 1 ) )
goto V_100;
V_2 -- ;
if ( V_64 -> V_77 -> V_99 ( V_64 , & V_62 , 1 , 0 ) != 1 )
goto V_100;
}
}
F_29 ( V_96 ) ;
#ifdef F_5
V_4 -> V_7 . V_113 = V_95 - V_94 ;
V_4 -> V_7 . V_114 = V_96 - V_95 ;
#endif
F_30 ( & V_4 -> V_97 , 1 ) ;
if ( ! V_4 -> V_45 )
F_31 ( V_59 ) ;
return;
V_100:
F_8 ( V_115 L_19 , V_28 ) ;
}
static int F_32 ( struct V_44 * V_45 , struct V_79 * V_59 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
if ( V_45 -> V_85 == F_33 ( V_116 ) )
return F_34 ( V_45 ) ;
if ( V_45 -> V_31 [ 0 ] != 0 ) {
F_10 ( V_4 , V_45 -> V_31 , V_45 -> V_32 ) ;
F_15 ( V_45 ) ;
return V_117 ;
}
if ( V_4 -> V_45 )
return V_118 ;
if ( V_45 -> V_32 >= V_119 + 1 || V_45 -> V_32 < 3 ) {
F_15 ( V_45 ) ;
return V_117 ;
}
F_35 ( V_59 ) ;
V_4 -> V_45 = V_45 ;
return V_117 ;
}
static int F_36 ( struct V_79 * V_59 , void * V_120 )
{
struct V_121 * V_122 = (struct V_121 * ) V_120 ;
memcpy ( V_59 -> V_123 , V_122 -> V_124 , V_59 -> V_125 ) ;
return 0 ;
}
static void F_37 ( void * V_126 )
{
struct V_79 * V_59 = (struct V_79 * ) V_126 ;
struct V_3 * V_4 = F_21 ( V_59 ) ;
F_8 ( V_27 L_20 , V_59 -> V_83 ) ;
if ( ! F_38 ( V_4 -> V_24 ) )
F_8 ( V_27 L_21 , V_59 -> V_83 ) ;
}
static int F_39 ( struct V_79 * V_59 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
struct V_63 * V_64 = F_40 ( V_59 -> V_127 ) ;
unsigned int V_66 , V_55 ;
unsigned char V_65 [ 128 ] ;
unsigned char V_62 ;
unsigned long V_128 ;
if ( ! V_64 ) {
F_8 ( V_115 L_22 , V_28 , V_59 -> V_127 ) ;
return - V_129 ;
}
#if 0
if (pp->irq < 0) {
printk(KERN_ERR "%s: parport at 0x%lx has no irq\n", bc_drvname, pp->base);
parport_put_port(pp);
return -ENXIO;
}
#endif
if ( ( ~ V_64 -> V_130 ) & ( V_131 | V_132 | V_133 ) ) {
F_8 ( V_115 L_23 ,
V_28 , V_64 -> V_26 ) ;
F_41 ( V_64 ) ;
return - V_134 ;
}
memset ( & V_4 -> V_101 , 0 , sizeof( V_4 -> V_101 ) ) ;
V_4 -> V_24 = F_42 ( V_64 , V_59 -> V_83 , NULL , F_37 ,
NULL , V_135 , V_59 ) ;
F_41 ( V_64 ) ;
if ( ! V_4 -> V_24 ) {
F_8 ( V_115 L_24 , V_28 , V_64 -> V_26 ) ;
return - V_129 ;
}
if ( F_38 ( V_4 -> V_24 ) ) {
F_8 ( V_115 L_25 , V_28 , V_64 -> V_26 ) ;
F_43 ( V_4 -> V_24 ) ;
return - V_136 ;
}
V_59 -> V_137 = 0 ;
F_44 ( & V_4 -> V_97 , F_27 ) ;
V_4 -> V_98 = 1 ;
V_4 -> V_101 = V_138 ;
if ( F_7 ( V_4 ) )
F_8 ( V_139 L_26 , V_28 ) ;
else
V_4 -> V_101 = V_102 ;
F_45 ( V_64 , V_140 ) ;
V_65 [ 0 ] = 0 ;
V_65 [ 1 ] = V_103 | V_104 | V_105 ;
if ( V_64 -> V_77 -> V_106 ( V_64 , V_65 , 2 , 0 ) != 2 )
goto V_100;
V_128 = V_6 ;
V_66 = 0 ;
while ( F_46 ( V_6 , V_128 + V_10 / 3 ) ) {
if ( V_64 -> V_77 -> V_99 ( V_64 , & V_62 , 1 , 0 ) != 1 )
goto V_100;
if ( ( V_62 & ( V_109 | V_110 ) ) == V_110 ) {
F_47 () ;
continue;
}
if ( V_64 -> V_77 -> V_90 ( V_64 , V_65 , 128 , 0 ) != 128 )
goto V_100;
if ( V_64 -> V_77 -> V_90 ( V_64 , V_65 , 128 , 0 ) != 128 )
goto V_100;
V_66 += 256 ;
}
for ( V_55 = 0 ; V_55 < 256 ; V_55 ++ ) {
if ( V_64 -> V_77 -> V_99 ( V_64 , & V_62 , 1 , 0 ) != 1 )
goto V_100;
if ( ! ( V_62 & V_112 ) )
break;
if ( V_64 -> V_77 -> V_90 ( V_64 , V_65 , 1 , 0 ) != 1 )
goto V_100;
V_66 ++ ;
}
V_128 = V_6 - V_128 ;
V_4 -> V_111 = V_66 * ( 8 * V_10 ) / V_128 ;
V_55 = 1 ;
V_66 = V_4 -> V_111 >> 3 ;
while ( V_55 < 7 && V_66 > 150 ) {
V_55 ++ ;
V_66 >>= 1 ;
}
F_8 ( V_139 L_27 ,
V_28 , V_4 -> V_111 , V_55 , V_4 -> V_111 >> ( V_55 + 2 ) ) ;
V_65 [ 0 ] = V_103 | V_104 | V_105 ;
if ( V_64 -> V_77 -> V_106 ( V_64 , V_65 , 1 , 0 ) != 1 )
goto V_100;
V_4 -> V_82 . V_67 = 0 ;
V_4 -> V_82 . V_87 = 0 ;
V_4 -> V_56 . V_67 = V_69 ;
V_4 -> V_56 . V_57 = 0 ;
V_4 -> V_56 . V_72 = V_4 -> V_34 . V_39 ;
V_4 -> V_56 . V_70 = 0 ;
F_30 ( & V_4 -> V_97 , 1 ) ;
F_48 ( V_59 ) ;
return 0 ;
V_100:
F_8 ( V_115 L_28 , V_28 ) ;
F_45 ( V_64 , 0 ) ;
F_49 ( V_4 -> V_24 ) ;
F_43 ( V_4 -> V_24 ) ;
return - V_134 ;
}
static int F_50 ( struct V_79 * V_59 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
struct V_63 * V_64 = V_4 -> V_24 -> V_25 ;
unsigned char V_65 [ 1 ] ;
V_4 -> V_98 = 0 ;
F_51 ( & V_4 -> V_97 ) ;
V_4 -> V_62 = V_71 ;
V_65 [ 0 ] = 0 ;
V_64 -> V_77 -> V_106 ( V_64 , V_65 , 1 , 0 ) ;
F_45 ( V_64 , 0 ) ;
F_49 ( V_4 -> V_24 ) ;
F_43 ( V_4 -> V_24 ) ;
if ( V_4 -> V_45 )
F_15 ( V_4 -> V_45 ) ;
V_4 -> V_45 = NULL ;
F_8 ( V_139 L_29 ,
V_28 , V_59 -> V_127 , V_59 -> V_137 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 , const char * V_141 )
{
const char * V_80 ;
if ( strstr ( V_141 , L_30 ) )
V_4 -> V_18 . V_19 = 1 ;
if ( strstr ( V_141 , L_31 ) )
V_4 -> V_18 . V_19 = 0 ;
if ( strstr ( V_141 , L_32 ) )
V_4 -> V_18 . V_20 = 0 ;
if ( strstr ( V_141 , L_33 ) )
V_4 -> V_18 . V_20 = 1 ;
if ( strstr ( V_141 , L_34 ) )
V_4 -> V_18 . V_23 = 0 ;
if ( strstr ( V_141 , L_35 ) )
V_4 -> V_18 . V_23 = 1 ;
if ( ( V_80 = strstr ( V_141 , L_36 ) ) ) {
V_4 -> V_18 . V_21 = F_53 ( V_80 + 5 , NULL , 0 ) ;
if ( V_4 -> V_18 . V_21 < 1000000 )
V_4 -> V_18 . V_21 = 1000000 ;
if ( V_4 -> V_18 . V_21 > 25000000 )
V_4 -> V_18 . V_21 = 25000000 ;
}
if ( ( V_80 = strstr ( V_141 , L_37 ) ) ) {
V_4 -> V_18 . V_22 = F_53 ( V_80 + 4 , NULL , 0 ) ;
if ( V_4 -> V_18 . V_22 < 1000 )
V_4 -> V_18 . V_22 = 1000 ;
if ( V_4 -> V_18 . V_22 > 1500000 )
V_4 -> V_18 . V_22 = 1500000 ;
}
return 0 ;
}
static int F_54 ( struct V_79 * V_59 , struct V_142 * V_143 , int V_144 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
struct V_145 V_146 ;
if ( V_144 != V_147 )
return - V_148 ;
if ( F_55 ( & V_146 , V_143 -> V_149 , sizeof( V_146 ) ) )
return - V_150 ;
switch ( V_146 . V_144 ) {
default:
return - V_148 ;
case V_151 :
V_146 . V_31 . V_80 . V_35 = V_4 -> V_34 . V_35 ;
V_146 . V_31 . V_80 . V_41 = V_4 -> V_34 . V_41 ;
V_146 . V_31 . V_80 . V_39 = V_4 -> V_34 . V_39 ;
V_146 . V_31 . V_80 . V_37 = V_4 -> V_34 . V_37 ;
V_146 . V_31 . V_80 . V_43 = V_4 -> V_34 . V_43 ;
break;
case V_152 :
if ( ! F_56 ( V_153 ) )
return - V_154 ;
V_4 -> V_34 . V_35 = V_146 . V_31 . V_80 . V_35 ;
V_4 -> V_34 . V_41 = V_146 . V_31 . V_80 . V_41 ;
V_4 -> V_34 . V_39 = V_146 . V_31 . V_80 . V_39 ;
V_4 -> V_34 . V_37 = V_146 . V_31 . V_80 . V_37 ;
V_4 -> V_34 . V_43 = V_146 . V_31 . V_80 . V_43 ;
V_4 -> V_56 . V_72 = 1 ;
return 0 ;
case V_155 :
V_146 . V_31 . V_156 . V_157 = V_59 -> V_127 ;
V_146 . V_31 . V_156 . V_137 = V_59 -> V_137 ;
V_146 . V_31 . V_156 . V_158 = V_59 -> V_158 ;
V_146 . V_31 . V_156 . V_159 = 0 ;
V_146 . V_31 . V_156 . V_160 = 0 ;
V_146 . V_31 . V_156 . V_161 = 0 ;
V_146 . V_31 . V_156 . V_162 = 0 ;
break;
case V_163 :
if ( ( ! F_56 ( V_164 ) ) || F_57 ( V_59 ) )
return - V_154 ;
V_59 -> V_127 = V_146 . V_31 . V_156 . V_157 ;
V_59 -> V_137 = 0 ;
V_59 -> V_158 = 0 ;
return 0 ;
case V_165 :
V_146 . V_31 . V_166 . V_167 = ! ! ( V_4 -> V_62 & V_68 ) ;
V_146 . V_31 . V_166 . V_168 = ! ( V_4 -> V_62 & V_71 ) ;
V_146 . V_31 . V_166 . V_75 = V_4 -> V_75 ;
V_146 . V_31 . V_166 . V_61 = V_59 -> V_60 . V_61 ;
V_146 . V_31 . V_166 . V_169 = V_59 -> V_60 . V_169 ;
V_146 . V_31 . V_166 . V_86 = V_59 -> V_60 . V_86 ;
V_146 . V_31 . V_166 . V_170 = V_59 -> V_60 . V_170 ;
break;
case V_171 :
V_146 . V_31 . V_172 . V_167 = ! ! ( V_4 -> V_62 & V_68 ) ;
V_146 . V_31 . V_172 . V_168 = ! ( V_4 -> V_62 & V_71 ) ;
V_146 . V_31 . V_172 . V_75 = V_4 -> V_75 ;
break;
case V_173 :
if ( ! F_56 ( V_164 ) )
return - V_154 ;
V_4 -> V_56 . V_70 = V_146 . V_31 . V_70 * V_4 -> V_111 / 8 ;
return 0 ;
case V_174 :
strncpy ( V_146 . V_31 . V_175 , L_38 , sizeof( V_146 . V_31 . V_175 ) ) ;
break;
case V_176 :
sprintf ( V_146 . V_31 . V_177 , L_39 ,
V_4 -> V_18 . V_19 ? L_5 : L_6 ,
V_4 -> V_18 . V_20 ? L_6 : L_5 , V_4 -> V_18 . V_21 , V_4 -> V_18 . V_22 ,
V_4 -> V_18 . V_23 ? L_7 : L_8 ) ;
break;
case V_178 :
if ( ! F_56 ( V_153 ) || F_57 ( V_59 ) )
return - V_154 ;
V_146 . V_31 . V_177 [ sizeof( V_146 . V_31 . V_177 ) - 1 ] = '\0' ;
return F_52 ( V_4 , V_146 . V_31 . V_177 ) ;
case V_179 :
strncpy ( V_146 . V_31 . V_177 , L_40 ,
sizeof( V_146 . V_31 . V_177 ) ) ;
break;
case V_180 :
return V_181 ;
}
if ( F_58 ( V_143 -> V_149 , & V_146 , sizeof( V_146 ) ) )
return - V_150 ;
return 0 ;
}
static void F_59 ( struct V_79 * V_59 )
{
const struct V_182 V_183 = {
20 , 2 , 10 , 40 , 0
} ;
struct V_3 * V_4 ;
V_4 = F_21 ( V_59 ) ;
V_4 -> V_34 = V_183 ;
V_4 -> V_75 = 0 ;
V_4 -> V_45 = NULL ;
V_59 -> V_184 = & V_185 ;
V_59 -> V_186 = & V_187 ;
V_59 -> type = V_188 ;
V_59 -> V_189 = V_190 + V_191 ;
V_59 -> V_192 = V_193 ;
V_59 -> V_125 = V_194 ;
memcpy ( V_59 -> V_195 , & V_196 , V_194 ) ;
memcpy ( V_59 -> V_123 , & V_197 , V_194 ) ;
V_59 -> V_198 = 16 ;
V_59 -> V_74 = 0 ;
}
static void T_3 F_60 ( struct V_79 * V_59 )
{
struct V_3 * V_4 = F_21 ( V_59 ) ;
V_4 -> V_59 = V_59 ;
V_4 -> V_199 = V_200 ;
V_4 -> V_18 . V_21 = 19666600 ;
V_4 -> V_18 . V_22 = 9600 ;
F_59 ( V_59 ) ;
}
static int T_3 F_61 ( void )
{
int V_66 , V_201 = 0 ;
char V_202 = 1 ;
F_8 ( V_203 ) ;
for ( V_66 = 0 ; V_66 < V_204 ; V_66 ++ ) {
struct V_79 * V_59 ;
V_59 = F_62 ( sizeof( struct V_3 ) , L_41 ,
V_205 , F_60 ) ;
if ( ! V_59 ) {
F_8 ( V_206 L_42 , V_66 ) ;
return V_201 ? 0 : - V_207 ;
}
sprintf ( V_59 -> V_83 , L_41 , V_66 ) ;
V_59 -> V_127 = V_157 [ V_66 ] ;
if ( ! V_208 [ V_66 ] )
V_202 = 0 ;
if ( ! V_202 )
V_157 [ V_66 ] = 0 ;
if ( F_63 ( V_59 ) ) {
F_8 ( V_206 L_43 , V_28 , V_59 -> V_83 ) ;
F_64 ( V_59 ) ;
break;
}
if ( V_202 && F_52 ( F_21 ( V_59 ) , V_208 [ V_66 ] ) )
V_202 = 0 ;
V_209 [ V_66 ] = V_59 ;
V_201 ++ ;
}
return V_201 ? 0 : - V_129 ;
}
static void T_4 F_65 ( void )
{
int V_66 ;
for( V_66 = 0 ; V_66 < V_204 ; V_66 ++ ) {
struct V_79 * V_59 = V_209 [ V_66 ] ;
if ( V_59 ) {
struct V_3 * V_4 = F_21 ( V_59 ) ;
if ( V_4 -> V_199 == V_200 ) {
F_66 ( V_59 ) ;
F_64 ( V_59 ) ;
} else
F_8 ( V_210 , L_44 ) ;
}
}
}
static int T_3 F_67 ( char * V_211 )
{
static unsigned T_5 V_212 = 0 ;
int V_213 [ 2 ] ;
if ( V_212 >= V_204 )
return 0 ;
V_211 = F_68 ( V_211 , 2 , V_213 ) ;
if ( V_213 [ 0 ] < 1 )
return 0 ;
V_208 [ V_212 ] = V_211 ;
V_157 [ V_212 ] = V_213 [ 1 ] ;
V_212 ++ ;
return 1 ;
}
