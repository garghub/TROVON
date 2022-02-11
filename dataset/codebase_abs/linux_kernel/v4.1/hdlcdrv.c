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
if ( V_17 -> V_23 == F_33 ( V_65 ) )
return F_34 ( V_17 ) ;
if ( V_17 -> V_41 [ 0 ] != 0 ) {
F_18 ( V_64 , V_17 -> V_41 , V_17 -> V_2 ) ;
F_35 ( V_17 ) ;
return V_66 ;
}
if ( V_64 -> V_17 )
return V_67 ;
F_36 ( V_15 ) ;
V_64 -> V_17 = V_17 ;
return V_66 ;
}
static int F_37 ( struct V_14 * V_15 , void * V_68 )
{
struct V_69 * V_70 = (struct V_69 * ) V_68 ;
memcpy ( V_15 -> V_71 , V_70 -> V_72 , V_15 -> V_73 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
int V_25 ;
if ( ! V_7 -> V_74 || ! V_7 -> V_74 -> V_75 )
return - V_76 ;
V_7 -> V_77 = 1 ;
V_7 -> V_11 . V_36 . V_78 = V_7 -> V_11 . V_36 . V_79 = 0 ;
V_7 -> V_11 . V_35 = 0 ;
V_7 -> V_11 . V_12 = 0 ;
V_7 -> V_53 . V_36 . V_78 = V_7 -> V_53 . V_36 . V_79 = 0 ;
V_7 -> V_53 . V_54 = 0 ;
V_7 -> V_53 . V_55 = 1 ;
V_7 -> V_53 . V_56 = 0 ;
V_7 -> V_53 . V_38 = V_7 -> V_53 . V_39 = V_7 -> V_53 . V_40 = 0 ;
V_7 -> V_53 . V_60 = 0 ;
V_7 -> V_53 . V_63 = V_7 -> V_43 . V_48 ;
V_7 -> V_53 . V_80 = 0 ;
V_25 = V_7 -> V_74 -> V_75 ( V_15 ) ;
if ( V_25 )
return V_25 ;
F_39 ( V_15 ) ;
return 0 ;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
int V_25 = 0 ;
F_36 ( V_15 ) ;
if ( V_7 -> V_74 && V_7 -> V_74 -> V_81 )
V_25 = V_7 -> V_74 -> V_81 ( V_15 ) ;
if ( V_7 -> V_17 )
F_35 ( V_7 -> V_17 ) ;
V_7 -> V_17 = NULL ;
V_7 -> V_77 = 0 ;
return V_25 ;
}
static int F_41 ( struct V_14 * V_15 , struct V_82 * V_83 , int V_84 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
struct F_41 V_85 ;
if ( V_84 != V_86 ) {
if ( V_7 -> V_74 && V_7 -> V_74 -> V_87 )
return V_7 -> V_74 -> V_87 ( V_15 , V_83 , & V_85 , V_84 ) ;
return - V_88 ;
}
if ( F_42 ( & V_85 , V_83 -> V_89 , sizeof( V_85 ) ) )
return - V_90 ;
switch ( V_85 . V_84 ) {
default:
if ( V_7 -> V_74 && V_7 -> V_74 -> V_87 )
return V_7 -> V_74 -> V_87 ( V_15 , V_83 , & V_85 , V_84 ) ;
return - V_88 ;
case V_91 :
V_85 . V_41 . V_19 . V_44 = V_7 -> V_43 . V_44 ;
V_85 . V_41 . V_19 . V_50 = V_7 -> V_43 . V_50 ;
V_85 . V_41 . V_19 . V_48 = V_7 -> V_43 . V_48 ;
V_85 . V_41 . V_19 . V_46 = V_7 -> V_43 . V_46 ;
V_85 . V_41 . V_19 . V_52 = V_7 -> V_43 . V_52 ;
break;
case V_92 :
if ( ! F_43 ( V_93 ) )
return - V_94 ;
V_7 -> V_43 . V_44 = V_85 . V_41 . V_19 . V_44 ;
V_7 -> V_43 . V_50 = V_85 . V_41 . V_19 . V_50 ;
V_7 -> V_43 . V_48 = V_85 . V_41 . V_19 . V_48 ;
V_7 -> V_43 . V_46 = V_85 . V_41 . V_19 . V_46 ;
V_7 -> V_43 . V_52 = V_85 . V_41 . V_19 . V_52 ;
V_7 -> V_53 . V_63 = 1 ;
return 0 ;
case V_95 :
V_85 . V_41 . V_96 . V_97 = V_15 -> V_98 ;
V_85 . V_41 . V_96 . V_99 = V_15 -> V_99 ;
V_85 . V_41 . V_96 . V_100 = V_15 -> V_100 ;
V_85 . V_41 . V_96 . V_101 = V_7 -> V_102 . V_101 ;
V_85 . V_41 . V_96 . V_103 = V_7 -> V_102 . V_103 ;
V_85 . V_41 . V_96 . V_104 = V_7 -> V_102 . V_104 ;
V_85 . V_41 . V_96 . V_105 = V_7 -> V_102 . V_105 ;
break;
case V_106 :
if ( ( ! F_43 ( V_107 ) ) || F_44 ( V_15 ) )
return - V_94 ;
V_15 -> V_98 = V_85 . V_41 . V_96 . V_97 ;
V_15 -> V_99 = V_85 . V_41 . V_96 . V_99 ;
V_15 -> V_100 = V_85 . V_41 . V_96 . V_100 ;
V_7 -> V_102 . V_101 = V_85 . V_41 . V_96 . V_101 ;
V_7 -> V_102 . V_103 = V_85 . V_41 . V_96 . V_103 ;
V_7 -> V_102 . V_104 = V_85 . V_41 . V_96 . V_104 ;
V_7 -> V_102 . V_105 = V_85 . V_41 . V_96 . V_105 ;
return 0 ;
case V_108 :
V_85 . V_41 . V_109 . V_60 = F_45 ( V_7 ) ;
V_85 . V_41 . V_109 . V_62 = V_7 -> V_11 . V_62 ;
V_85 . V_41 . V_109 . V_61 = V_7 -> V_61 ;
V_85 . V_41 . V_109 . V_59 = V_15 -> V_21 . V_59 ;
V_85 . V_41 . V_109 . V_110 = V_15 -> V_21 . V_110 ;
V_85 . V_41 . V_109 . V_24 = V_15 -> V_21 . V_24 ;
V_85 . V_41 . V_109 . V_111 = V_15 -> V_21 . V_111 ;
break;
case V_112 :
V_85 . V_41 . V_113 . V_60 = F_45 ( V_7 ) ;
V_85 . V_41 . V_113 . V_62 = V_7 -> V_11 . V_62 ;
V_85 . V_41 . V_113 . V_61 = V_7 -> V_61 ;
break;
case V_114 :
if( ! F_43 ( V_107 ) )
return - V_115 ;
if ( V_85 . V_41 . V_80 > V_116 / V_7 -> V_117 . V_118 )
return - V_119 ;
V_7 -> V_53 . V_80 = V_85 . V_41 . V_80 * V_7 -> V_117 . V_118 / 16 ;
return 0 ;
case V_120 :
#ifndef F_15
return - V_115 ;
#else
if ( V_7 -> V_121 . V_78 == V_7 -> V_121 . V_79 )
return - V_122 ;
V_85 . V_41 . V_8 =
V_7 -> V_121 . V_1 [ V_7 -> V_121 . V_78 ] ;
V_7 -> V_121 . V_78 = ( V_7 -> V_121 . V_78 + 1 ) %
sizeof( V_7 -> V_121 . V_1 ) ;
break;
#endif
case V_123 :
#ifndef F_15
return - V_115 ;
#else
if ( V_7 -> V_37 . V_78 == V_7 -> V_37 . V_79 )
return - V_122 ;
V_85 . V_41 . V_8 =
V_7 -> V_37 . V_1 [ V_7 -> V_37 . V_78 ] ;
V_7 -> V_37 . V_78 = ( V_7 -> V_37 . V_78 + 1 ) %
sizeof( V_7 -> V_37 . V_1 ) ;
break;
#endif
case V_124 :
if ( V_7 -> V_74 && V_7 -> V_74 -> V_125 ) {
strncpy ( V_85 . V_41 . V_126 , V_7 -> V_74 -> V_125 ,
sizeof( V_85 . V_41 . V_126 ) ) ;
break;
}
V_85 . V_41 . V_126 [ 0 ] = '\0' ;
break;
}
if ( F_46 ( V_83 -> V_89 , & V_85 , sizeof( V_85 ) ) )
return - V_90 ;
return 0 ;
}
static void F_47 ( struct V_14 * V_15 )
{
static const struct V_127 V_128 = {
20 , 2 , 10 , 40 , 0
} ;
struct V_6 * V_7 = F_32 ( V_15 ) ;
V_7 -> V_43 = V_128 ;
V_7 -> V_61 = 0 ;
F_48 ( & V_7 -> V_11 . V_36 . V_129 ) ;
V_7 -> V_11 . V_36 . V_78 = V_7 -> V_11 . V_36 . V_79 = 0 ;
V_7 -> V_11 . V_35 = 0 ;
V_7 -> V_11 . V_12 = 0 ;
F_48 ( & V_7 -> V_53 . V_36 . V_129 ) ;
V_7 -> V_53 . V_36 . V_78 = V_7 -> V_53 . V_36 . V_79 = 0 ;
V_7 -> V_53 . V_54 = 0 ;
V_7 -> V_53 . V_55 = 1 ;
V_7 -> V_53 . V_56 = 0 ;
V_7 -> V_53 . V_38 = V_7 -> V_53 . V_39 = V_7 -> V_53 . V_40 = 0 ;
V_7 -> V_53 . V_60 = 0 ;
V_7 -> V_53 . V_63 = V_7 -> V_43 . V_48 ;
V_7 -> V_53 . V_80 = 0 ;
#ifdef F_15
V_7 -> V_121 . V_78 = V_7 -> V_121 . V_79 = 0 ;
V_7 -> V_121 . V_130 = 0x80 ;
V_7 -> V_37 . V_78 = V_7 -> V_37 . V_79 = 0 ;
V_7 -> V_37 . V_130 = 0x80 ;
#endif
V_7 -> V_17 = NULL ;
V_15 -> V_131 = & V_132 ;
V_15 -> V_133 = & V_134 ;
V_15 -> type = V_135 ;
V_15 -> V_136 = V_137 + V_138 ;
V_15 -> V_139 = V_140 ;
V_15 -> V_73 = V_141 ;
memcpy ( V_15 -> V_142 , & V_143 , V_141 ) ;
memcpy ( V_15 -> V_71 , & V_144 , V_141 ) ;
V_15 -> V_145 = 16 ;
}
struct V_14 * F_49 ( const struct V_146 * V_74 ,
unsigned int V_147 , const char * V_148 ,
unsigned int V_149 , unsigned int V_99 ,
unsigned int V_100 )
{
struct V_14 * V_15 ;
struct V_6 * V_7 ;
int V_150 ;
F_50 ( V_74 == NULL ) ;
if ( V_147 < sizeof( struct V_6 ) )
V_147 = sizeof( struct V_6 ) ;
V_15 = F_51 ( V_147 , V_148 , V_151 , F_47 ) ;
if ( ! V_15 )
return F_52 ( - V_152 ) ;
V_7 = F_32 ( V_15 ) ;
V_7 -> V_33 = V_34 ;
V_7 -> V_74 = V_74 ;
V_15 -> V_98 = V_149 ;
V_15 -> V_99 = V_99 ;
V_15 -> V_100 = V_100 ;
V_150 = F_53 ( V_15 ) ;
if ( V_150 < 0 ) {
F_7 ( V_153 L_9
L_10 , V_15 -> V_20 ) ;
F_54 ( V_15 ) ;
V_15 = F_52 ( V_150 ) ;
}
return V_15 ;
}
void F_55 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_32 ( V_15 ) ;
F_50 ( V_7 -> V_33 != V_34 ) ;
if ( V_7 -> V_77 && V_7 -> V_74 -> V_81 )
V_7 -> V_74 -> V_81 ( V_15 ) ;
F_56 ( V_15 ) ;
F_54 ( V_15 ) ;
}
static int T_4 F_57 ( void )
{
F_7 ( V_154 L_11 ) ;
F_7 ( V_154 L_12 ) ;
return 0 ;
}
static void T_5 F_58 ( void )
{
F_7 ( V_154 L_13 ) ;
}
