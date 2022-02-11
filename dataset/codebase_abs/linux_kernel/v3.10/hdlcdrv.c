static inline void F_1 ( unsigned char * V_1 , int V_2 )
{
unsigned int V_3 = F_2 ( 0xffff , V_1 , V_2 ) ^ 0xffff ;
V_1 += V_2 ;
* V_1 ++ = V_3 ;
* V_1 ++ = V_3 >> 8 ;
}
static inline int F_3 ( const unsigned char * V_4 , int V_5 )
{
return ( F_2 ( 0xffff , V_4 , V_5 ) & 0xffff ) == 0xf0b8 ;
}
static int F_4 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_9 )
{
int V_10 = 0 ;
while ( V_7 -> V_11 . V_12 && V_9 >= 8 ) {
if ( V_7 -> V_11 . V_2 >= sizeof( V_7 -> V_11 . V_1 ) ) {
V_7 -> V_11 . V_12 = 0 ;
return 0 ;
}
* V_7 -> V_11 . V_13 ++ = V_8 >> ( 32 - V_9 ) ;
V_7 -> V_11 . V_2 ++ ;
V_9 -= 8 ;
V_10 += 8 ;
}
return V_10 ;
}
static void F_5 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
struct V_16 * V_17 ;
int V_18 ;
unsigned char * V_19 ;
if ( V_7 -> V_11 . V_2 < 4 )
return;
if ( ! F_3 ( V_7 -> V_11 . V_1 , V_7 -> V_11 . V_2 ) )
return;
V_18 = V_7 -> V_11 . V_2 - 2 + 1 ;
if ( ! ( V_17 = F_6 ( V_18 ) ) ) {
F_7 ( L_1 , V_15 -> V_20 ) ;
V_15 -> V_21 . V_22 ++ ;
return;
}
V_19 = F_8 ( V_17 , V_18 ) ;
* V_19 ++ = 0 ;
memcpy ( V_19 , V_7 -> V_11 . V_1 , V_18 - 1 ) ;
V_17 -> V_23 = F_9 ( V_17 , V_15 ) ;
F_10 ( V_17 ) ;
V_15 -> V_21 . V_24 ++ ;
}
void F_11 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
int V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ;
if ( ! V_7 || V_7 -> V_33 != V_34 )
return;
if ( F_12 ( 0 , & V_7 -> V_11 . V_35 ) )
return;
while ( ! F_13 ( & V_7 -> V_11 . V_36 ) ) {
V_32 = F_14 ( & V_7 -> V_11 . V_36 ) ;
#ifdef F_15
F_16 ( & V_7 -> V_37 , V_32 ) ;
#endif
V_7 -> V_11 . V_38 >>= 16 ;
V_7 -> V_11 . V_38 |= V_32 << 16 ;
V_7 -> V_11 . V_39 >>= 16 ;
V_7 -> V_11 . V_39 |= V_32 << 16 ;
V_7 -> V_11 . V_40 += 16 ;
for( V_25 = 15 , V_26 = 0x1fc00 , V_27 = 0x1fe00 , V_28 = 0x0fc00 ,
V_29 = 0x1f800 , V_30 = 0xf800 , V_31 = 0xffff ;
V_25 >= 0 ;
V_25 -- , V_26 <<= 1 , V_27 <<= 1 , V_28 <<= 1 , V_29 <<= 1 ,
V_30 <<= 1 , V_31 = ( V_31 << 1 ) | 1 ) {
if ( ( V_7 -> V_11 . V_38 & V_26 ) == V_26 )
V_7 -> V_11 . V_12 = 0 ;
else if ( ( V_7 -> V_11 . V_38 & V_27 ) == V_28 ) {
if ( V_7 -> V_11 . V_12 ) {
F_4 ( V_7 , V_7 -> V_11 . V_39
<< ( 8 + V_25 ) ,
V_7 -> V_11 . V_40
- 8 - V_25 ) ;
F_5 ( V_15 , V_7 ) ;
}
V_7 -> V_11 . V_2 = 0 ;
V_7 -> V_11 . V_13 = V_7 -> V_11 . V_1 ;
V_7 -> V_11 . V_12 = 1 ;
V_7 -> V_11 . V_40 = V_25 ;
} else if ( ( V_7 -> V_11 . V_38 & V_29 ) == V_30 ) {
V_7 -> V_11 . V_40 -- ;
V_7 -> V_11 . V_39 = ( V_7 -> V_11 . V_39 & ( ~ V_31 ) ) |
( ( V_7 -> V_11 . V_39 & V_31 ) << 1 ) ;
}
}
V_7 -> V_11 . V_40 -= F_4 ( V_7 , V_7 -> V_11 . V_39 ,
V_7 -> V_11 . V_40 ) ;
}
F_17 ( 0 , & V_7 -> V_11 . V_35 ) ;
}
static inline void F_18 ( struct V_6 * V_7 ,
unsigned char * V_41 , unsigned long V_2 )
{
#ifdef F_19
#define F_20 ( T_1 , T_2 ) printk(KERN_INFO "hdlcdrv.c: channel params: " a "\n", b)
#else
#define F_20 ( T_1 , T_2 )
#endif
if ( V_2 < 2 )
return;
switch( V_41 [ 0 ] ) {
case V_42 :
V_7 -> V_43 . V_44 = V_41 [ 1 ] ;
F_20 ( L_2 , 10 * V_7 -> V_43 . V_44 ) ;
break;
case V_45 :
V_7 -> V_43 . V_46 = V_41 [ 1 ] ;
F_20 ( L_3 , V_7 -> V_43 . V_46 ) ;
break;
case V_47 :
V_7 -> V_43 . V_48 = V_41 [ 1 ] ;
F_20 ( L_4 , V_7 -> V_43 . V_48 ) ;
break;
case V_49 :
V_7 -> V_43 . V_50 = V_41 [ 1 ] ;
F_20 ( L_5 , V_7 -> V_43 . V_50 ) ;
break;
case V_51 :
V_7 -> V_43 . V_52 = ! ! V_41 [ 1 ] ;
F_20 ( L_6 , V_7 -> V_43 . V_52 ? L_7 : L_8 ) ;
break;
default:
break;
}
#undef F_20
}
void F_21 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
unsigned int V_26 , V_27 , V_28 ;
int V_25 ;
struct V_16 * V_17 ;
int V_18 ;
if ( ! V_7 || V_7 -> V_33 != V_34 )
return;
if ( F_12 ( 0 , & V_7 -> V_53 . V_54 ) )
return;
for (; ; ) {
if ( V_7 -> V_53 . V_40 >= 16 ) {
if ( F_22 ( & V_7 -> V_53 . V_36 ) ) {
F_17 ( 0 , & V_7 -> V_53 . V_54 ) ;
return;
}
F_23 ( & V_7 -> V_53 . V_36 , V_7 -> V_53 . V_39 ) ;
V_7 -> V_53 . V_39 >>= 16 ;
V_7 -> V_53 . V_40 -= 16 ;
}
switch ( V_7 -> V_53 . V_55 ) {
default:
F_17 ( 0 , & V_7 -> V_53 . V_54 ) ;
return;
case 0 :
case 1 :
if ( V_7 -> V_53 . V_56 ) {
V_7 -> V_53 . V_56 -- ;
V_7 -> V_53 . V_39 |=
0x7e7e << V_7 -> V_53 . V_40 ;
V_7 -> V_53 . V_40 += 16 ;
break;
}
if ( V_7 -> V_53 . V_55 == 1 ) {
F_17 ( 0 , & V_7 -> V_53 . V_54 ) ;
return;
}
if ( ! ( V_17 = V_7 -> V_17 ) ) {
int V_57 = F_24 ( V_7 , V_7 -> V_43 . V_50 ) ;
if ( V_57 < 2 )
V_57 = 2 ;
V_7 -> V_53 . V_55 = 1 ;
V_7 -> V_53 . V_56 = V_57 ;
break;
}
V_7 -> V_17 = NULL ;
F_25 ( V_15 ) ;
V_18 = V_17 -> V_2 - 1 ;
if ( V_18 >= V_58 || V_18 < 2 ) {
V_7 -> V_53 . V_55 = 0 ;
V_7 -> V_53 . V_56 = 1 ;
F_26 ( V_17 ) ;
break;
}
F_27 ( V_17 , 1 ,
V_7 -> V_53 . V_1 ,
V_18 ) ;
F_26 ( V_17 ) ;
V_7 -> V_53 . V_13 = V_7 -> V_53 . V_1 ;
F_1 ( V_7 -> V_53 . V_1 , V_18 ) ;
V_7 -> V_53 . V_2 = V_18 + 2 ;
V_7 -> V_53 . V_55 = 2 ;
V_7 -> V_53 . V_38 = 0 ;
V_15 -> V_21 . V_59 ++ ;
break;
case 2 :
if ( ! V_7 -> V_53 . V_2 ) {
V_7 -> V_53 . V_55 = 0 ;
V_7 -> V_53 . V_56 = 1 ;
break;
}
V_7 -> V_53 . V_2 -- ;
V_7 -> V_53 . V_39 |= * V_7 -> V_53 . V_13 <<
V_7 -> V_53 . V_40 ;
V_7 -> V_53 . V_38 >>= 8 ;
V_7 -> V_53 . V_38 |= ( * V_7 -> V_53 . V_13 ++ ) << 16 ;
V_26 = 0x1f000 ;
V_27 = 0x10000 ;
V_28 = 0xffffffff >> ( 31 - V_7 -> V_53 . V_40 ) ;
V_7 -> V_53 . V_40 += 8 ;
for( V_25 = 0 ; V_25 < 8 ; V_25 ++ , V_26 <<= 1 , V_27 <<= 1 ,
V_28 = ( V_28 << 1 ) | 1 ) {
if ( ( V_7 -> V_53 . V_38 & V_26 ) != V_26 )
continue;
V_7 -> V_53 . V_38 &= ~ V_27 ;
V_7 -> V_53 . V_39 =
( V_7 -> V_53 . V_39 & V_28 ) |
( ( V_7 -> V_53 . V_39 &
( ~ V_28 ) ) << 1 ) ;
V_7 -> V_53 . V_40 ++ ;
V_28 = ( V_28 << 1 ) | 1 ;
}
break;
}
}
}
static void F_28 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
V_7 -> V_53 . V_55 = 0 ;
V_7 -> V_53 . V_56 = F_24 ( V_7 , V_7 -> V_43 . V_44 ) ;
V_7 -> V_53 . V_39 = V_7 -> V_53 . V_38 = V_7 -> V_53 . V_40 = 0 ;
F_21 ( V_15 , V_7 ) ;
V_7 -> V_53 . V_60 = 1 ;
V_7 -> V_61 ++ ;
}
void F_29 ( struct V_14 * V_15 , struct V_6 * V_7 )
{
if ( ! V_7 || V_7 -> V_33 != V_34 || V_7 -> V_53 . V_60 || ! V_7 -> V_17 )
return;
if ( V_7 -> V_43 . V_52 ) {
F_28 ( V_15 , V_7 ) ;
return;
}
if ( V_7 -> V_11 . V_62 ) {
V_7 -> V_53 . V_63 = V_7 -> V_43 . V_48 ;
return;
}
if ( ( -- V_7 -> V_53 . V_63 ) > 0 )
return;
V_7 -> V_53 . V_63 = V_7 -> V_43 . V_48 ;
if ( ( F_30 () % 256 ) > V_7 -> V_43 . V_46 )
return;
F_28 ( V_15 , V_7 ) ;
}
static T_3 F_31 ( struct V_16 * V_17 ,
struct V_14 * V_15 )
{
struct V_6 * V_64 = F_32 ( V_15 ) ;
if ( V_17 -> V_41 [ 0 ] != 0 ) {
F_18 ( V_64 , V_17 -> V_41 , V_17 -> V_2 ) ;
F_33 ( V_17 ) ;
return V_65 ;
}
if ( V_64 -> V_17 )
return V_66 ;
F_34 ( V_15 ) ;
V_64 -> V_17 = V_17 ;
return V_65 ;
}
static int F_35 ( struct V_14 * V_15 , void * V_67 )
{
struct V_68 * V_69 = (struct V_68 * ) V_67 ;
memcpy ( V_15 -> V_70 , V_69 -> V_71 , V_15 -> V_72 ) ;
return 0 ;
}
static int F_36 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
int V_25 ;
if ( ! V_7 -> V_73 || ! V_7 -> V_73 -> V_74 )
return - V_75 ;
V_7 -> V_76 = 1 ;
V_7 -> V_11 . V_36 . V_77 = V_7 -> V_11 . V_36 . V_78 = 0 ;
V_7 -> V_11 . V_35 = 0 ;
V_7 -> V_11 . V_12 = 0 ;
V_7 -> V_53 . V_36 . V_77 = V_7 -> V_53 . V_36 . V_78 = 0 ;
V_7 -> V_53 . V_54 = 0 ;
V_7 -> V_53 . V_55 = 1 ;
V_7 -> V_53 . V_56 = 0 ;
V_7 -> V_53 . V_38 = V_7 -> V_53 . V_39 = V_7 -> V_53 . V_40 = 0 ;
V_7 -> V_53 . V_60 = 0 ;
V_7 -> V_53 . V_63 = V_7 -> V_43 . V_48 ;
V_7 -> V_53 . V_79 = 0 ;
V_25 = V_7 -> V_73 -> V_74 ( V_15 ) ;
if ( V_25 )
return V_25 ;
F_37 ( V_15 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
int V_25 = 0 ;
F_34 ( V_15 ) ;
if ( V_7 -> V_73 && V_7 -> V_73 -> V_80 )
V_25 = V_7 -> V_73 -> V_80 ( V_15 ) ;
if ( V_7 -> V_17 )
F_33 ( V_7 -> V_17 ) ;
V_7 -> V_17 = NULL ;
V_7 -> V_76 = 0 ;
return V_25 ;
}
static int F_39 ( struct V_14 * V_15 , struct V_81 * V_82 , int V_83 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
struct F_39 V_84 ;
if ( V_83 != V_85 ) {
if ( V_7 -> V_73 && V_7 -> V_73 -> V_86 )
return V_7 -> V_73 -> V_86 ( V_15 , V_82 , & V_84 , V_83 ) ;
return - V_87 ;
}
if ( F_40 ( & V_84 , V_82 -> V_88 , sizeof( V_84 ) ) )
return - V_89 ;
switch ( V_84 . V_83 ) {
default:
if ( V_7 -> V_73 && V_7 -> V_73 -> V_86 )
return V_7 -> V_73 -> V_86 ( V_15 , V_82 , & V_84 , V_83 ) ;
return - V_87 ;
case V_90 :
V_84 . V_41 . V_19 . V_44 = V_7 -> V_43 . V_44 ;
V_84 . V_41 . V_19 . V_50 = V_7 -> V_43 . V_50 ;
V_84 . V_41 . V_19 . V_48 = V_7 -> V_43 . V_48 ;
V_84 . V_41 . V_19 . V_46 = V_7 -> V_43 . V_46 ;
V_84 . V_41 . V_19 . V_52 = V_7 -> V_43 . V_52 ;
break;
case V_91 :
if ( ! F_41 ( V_92 ) )
return - V_93 ;
V_7 -> V_43 . V_44 = V_84 . V_41 . V_19 . V_44 ;
V_7 -> V_43 . V_50 = V_84 . V_41 . V_19 . V_50 ;
V_7 -> V_43 . V_48 = V_84 . V_41 . V_19 . V_48 ;
V_7 -> V_43 . V_46 = V_84 . V_41 . V_19 . V_46 ;
V_7 -> V_43 . V_52 = V_84 . V_41 . V_19 . V_52 ;
V_7 -> V_53 . V_63 = 1 ;
return 0 ;
case V_94 :
V_84 . V_41 . V_95 . V_96 = V_15 -> V_97 ;
V_84 . V_41 . V_95 . V_98 = V_15 -> V_98 ;
V_84 . V_41 . V_95 . V_99 = V_15 -> V_99 ;
V_84 . V_41 . V_95 . V_100 = V_7 -> V_101 . V_100 ;
V_84 . V_41 . V_95 . V_102 = V_7 -> V_101 . V_102 ;
V_84 . V_41 . V_95 . V_103 = V_7 -> V_101 . V_103 ;
V_84 . V_41 . V_95 . V_104 = V_7 -> V_101 . V_104 ;
break;
case V_105 :
if ( ( ! F_41 ( V_106 ) ) || F_42 ( V_15 ) )
return - V_93 ;
V_15 -> V_97 = V_84 . V_41 . V_95 . V_96 ;
V_15 -> V_98 = V_84 . V_41 . V_95 . V_98 ;
V_15 -> V_99 = V_84 . V_41 . V_95 . V_99 ;
V_7 -> V_101 . V_100 = V_84 . V_41 . V_95 . V_100 ;
V_7 -> V_101 . V_102 = V_84 . V_41 . V_95 . V_102 ;
V_7 -> V_101 . V_103 = V_84 . V_41 . V_95 . V_103 ;
V_7 -> V_101 . V_104 = V_84 . V_41 . V_95 . V_104 ;
return 0 ;
case V_107 :
V_84 . V_41 . V_108 . V_60 = F_43 ( V_7 ) ;
V_84 . V_41 . V_108 . V_62 = V_7 -> V_11 . V_62 ;
V_84 . V_41 . V_108 . V_61 = V_7 -> V_61 ;
V_84 . V_41 . V_108 . V_59 = V_15 -> V_21 . V_59 ;
V_84 . V_41 . V_108 . V_109 = V_15 -> V_21 . V_109 ;
V_84 . V_41 . V_108 . V_24 = V_15 -> V_21 . V_24 ;
V_84 . V_41 . V_108 . V_110 = V_15 -> V_21 . V_110 ;
break;
case V_111 :
V_84 . V_41 . V_112 . V_60 = F_43 ( V_7 ) ;
V_84 . V_41 . V_112 . V_62 = V_7 -> V_11 . V_62 ;
V_84 . V_41 . V_112 . V_61 = V_7 -> V_61 ;
break;
case V_113 :
if( ! F_41 ( V_106 ) )
return - V_114 ;
V_7 -> V_53 . V_79 = V_84 . V_41 . V_79 * V_7 -> V_115 . V_116 / 16 ;
return 0 ;
case V_117 :
#ifndef F_15
return - V_114 ;
#else
if ( V_7 -> V_118 . V_77 == V_7 -> V_118 . V_78 )
return - V_119 ;
V_84 . V_41 . V_8 =
V_7 -> V_118 . V_1 [ V_7 -> V_118 . V_77 ] ;
V_7 -> V_118 . V_77 = ( V_7 -> V_118 . V_77 + 1 ) %
sizeof( V_7 -> V_118 . V_1 ) ;
break;
#endif
case V_120 :
#ifndef F_15
return - V_114 ;
#else
if ( V_7 -> V_37 . V_77 == V_7 -> V_37 . V_78 )
return - V_119 ;
V_84 . V_41 . V_8 =
V_7 -> V_37 . V_1 [ V_7 -> V_37 . V_77 ] ;
V_7 -> V_37 . V_77 = ( V_7 -> V_37 . V_77 + 1 ) %
sizeof( V_7 -> V_37 . V_1 ) ;
break;
#endif
case V_121 :
if ( V_7 -> V_73 && V_7 -> V_73 -> V_122 ) {
strncpy ( V_84 . V_41 . V_123 , V_7 -> V_73 -> V_122 ,
sizeof( V_84 . V_41 . V_123 ) ) ;
break;
}
V_84 . V_41 . V_123 [ 0 ] = '\0' ;
break;
}
if ( F_44 ( V_82 -> V_88 , & V_84 , sizeof( V_84 ) ) )
return - V_89 ;
return 0 ;
}
static void F_45 ( struct V_14 * V_15 )
{
static const struct V_124 V_125 = {
20 , 2 , 10 , 40 , 0
} ;
struct V_6 * V_7 = F_32 ( V_15 ) ;
V_7 -> V_43 = V_125 ;
V_7 -> V_61 = 0 ;
F_46 ( & V_7 -> V_11 . V_36 . V_126 ) ;
V_7 -> V_11 . V_36 . V_77 = V_7 -> V_11 . V_36 . V_78 = 0 ;
V_7 -> V_11 . V_35 = 0 ;
V_7 -> V_11 . V_12 = 0 ;
F_46 ( & V_7 -> V_53 . V_36 . V_126 ) ;
V_7 -> V_53 . V_36 . V_77 = V_7 -> V_53 . V_36 . V_78 = 0 ;
V_7 -> V_53 . V_54 = 0 ;
V_7 -> V_53 . V_55 = 1 ;
V_7 -> V_53 . V_56 = 0 ;
V_7 -> V_53 . V_38 = V_7 -> V_53 . V_39 = V_7 -> V_53 . V_40 = 0 ;
V_7 -> V_53 . V_60 = 0 ;
V_7 -> V_53 . V_63 = V_7 -> V_43 . V_48 ;
V_7 -> V_53 . V_79 = 0 ;
#ifdef F_15
V_7 -> V_118 . V_77 = V_7 -> V_118 . V_78 = 0 ;
V_7 -> V_118 . V_127 = 0x80 ;
V_7 -> V_37 . V_77 = V_7 -> V_37 . V_78 = 0 ;
V_7 -> V_37 . V_127 = 0x80 ;
#endif
V_7 -> V_17 = NULL ;
V_15 -> V_128 = & V_129 ;
V_15 -> V_130 = & V_131 ;
V_15 -> type = V_132 ;
V_15 -> V_133 = V_134 + V_135 ;
V_15 -> V_136 = V_137 ;
V_15 -> V_72 = V_138 ;
memcpy ( V_15 -> V_139 , & V_140 , V_138 ) ;
memcpy ( V_15 -> V_70 , & V_141 , V_138 ) ;
V_15 -> V_142 = 16 ;
}
struct V_14 * F_47 ( const struct V_143 * V_73 ,
unsigned int V_144 , const char * V_145 ,
unsigned int V_146 , unsigned int V_98 ,
unsigned int V_99 )
{
struct V_14 * V_15 ;
struct V_6 * V_7 ;
int V_147 ;
F_48 ( V_73 == NULL ) ;
if ( V_144 < sizeof( struct V_6 ) )
V_144 = sizeof( struct V_6 ) ;
V_15 = F_49 ( V_144 , V_145 , F_45 ) ;
if ( ! V_15 )
return F_50 ( - V_148 ) ;
V_7 = F_32 ( V_15 ) ;
V_7 -> V_33 = V_34 ;
V_7 -> V_73 = V_73 ;
V_15 -> V_97 = V_146 ;
V_15 -> V_98 = V_98 ;
V_15 -> V_99 = V_99 ;
V_147 = F_51 ( V_15 ) ;
if ( V_147 < 0 ) {
F_7 ( V_149 L_9
L_10 , V_15 -> V_20 ) ;
F_52 ( V_15 ) ;
V_15 = F_50 ( V_147 ) ;
}
return V_15 ;
}
void F_53 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
F_48 ( V_7 -> V_33 != V_34 ) ;
if ( V_7 -> V_76 && V_7 -> V_73 -> V_80 )
V_7 -> V_73 -> V_80 ( V_15 ) ;
F_54 ( V_15 ) ;
F_52 ( V_15 ) ;
}
static int T_4 F_55 ( void )
{
F_7 ( V_150 L_11 ) ;
F_7 ( V_150 L_12 ) ;
return 0 ;
}
static void T_5 F_56 ( void )
{
F_7 ( V_150 L_13 ) ;
}
