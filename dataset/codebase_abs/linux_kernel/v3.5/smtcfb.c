static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 , V_4 = 0 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 -> V_7 ,
L_1
L_2 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_10 . V_11 . V_12 , V_2 -> V_13 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
if ( V_15 [ V_4 ] . V_16 == V_2 -> V_8 &&
V_15 [ V_4 ] . V_17 == V_2 -> V_9 &&
V_15 [ V_4 ] . V_18 == V_2 -> V_10 . V_11 . V_12 &&
V_15 [ V_4 ] . V_13 == V_2 -> V_13 ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_3
L_4 ,
V_15 [ V_4 ] . V_16 , V_15 [ V_4 ] . V_17 ,
V_15 [ V_4 ] . V_18 , V_15 [ V_4 ] . V_13 ) ;
F_2 ( & V_2 -> V_6 -> V_7 , L_5 , V_4 ) ;
F_3 ( 0x0 , 0x3c6 ) ;
F_4 ( 0 , 0x1 ) ;
F_3 ( V_15 [ V_4 ] . V_19 , 0x3c2 ) ;
for ( V_3 = 0 ; V_3 < V_20 ; V_3 ++ )
F_4 ( V_3 , V_15 [ V_4 ] . V_21 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ )
F_4 ( V_3 + 0x10 ,
V_15 [ V_4 ] . V_23 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_24 ; V_3 ++ )
if ( ( ( V_3 + 0x30 ) != 0x62 ) \
&& ( ( V_3 + 0x30 ) != 0x6a ) \
&& ( ( V_3 + 0x30 ) != 0x6b ) )
F_4 ( V_3 + 0x30 ,
V_15 [ V_4 ] . V_25 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ )
F_4 ( V_3 + 0x80 ,
V_15 [ V_4 ] . V_27 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_28 ; V_3 ++ )
F_4 ( V_3 + 0xa0 ,
V_15 [ V_4 ] . V_29 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_30 ; V_3 ++ )
F_5 ( V_3 , V_15 [ V_4 ] . V_31 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ )
F_6 ( V_3 , V_15 [ V_4 ] . V_33 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_34 ; V_3 ++ )
F_7 ( V_3 , V_15 [ V_4 ] . V_35 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ )
F_7 ( V_3 + 0x30 ,
V_15 [ V_4 ] . V_37 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ )
F_7 ( V_3 + 0x90 ,
V_15 [ V_4 ] . V_39 [ V_3 ] ) ;
}
}
F_3 ( 0x67 , 0x3c2 ) ;
F_8 ( 0x0 , V_2 -> V_40 + 0x0C ) ;
F_8 ( 0x0 , V_2 -> V_40 + 0x40 ) ;
V_5 =
( V_2 -> V_8 * V_2 -> V_10 . V_11 . V_12 ) / 64 ;
switch ( V_2 -> V_10 . V_11 . V_12 ) {
case 8 :
F_8 ( 0x0 , V_2 -> V_40 + 0x0 ) ;
break;
case 16 :
F_8 ( 0x00020000 , V_2 -> V_40 + 0x0 ) ;
break;
case 24 :
F_8 ( 0x00040000 , V_2 -> V_40 + 0x0 ) ;
break;
case 32 :
F_8 ( 0x00030000 , V_2 -> V_40 + 0x0 ) ;
break;
}
F_8 ( ( T_1 ) ( ( ( V_5 + 2 ) << 16 ) | V_5 ) ,
V_2 -> V_40 + 0x10 ) ;
}
static void F_9 ( int V_41 , unsigned V_42 , unsigned V_43 ,
unsigned V_44 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_47 ;
if ( V_2 -> V_48 )
F_4 ( 0x66 , ( F_10 ( 0x66 ) & 0xC3 ) | 0x20 ) ;
else
F_4 ( 0x66 , ( F_10 ( 0x66 ) & 0xC3 ) | 0x10 ) ;
F_3 ( V_41 , V_49 ) ;
F_3 ( V_42 >> 10 , V_50 ) ;
F_3 ( V_43 >> 10 , V_50 ) ;
F_3 ( V_44 >> 10 , V_50 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_51 ) {
case 0x710 :
case 0x712 :
case 0x720 :
F_1 ( V_2 ) ;
break;
}
}
static inline unsigned int F_12 ( unsigned int V_52 ,
struct V_53 * V_54 )
{
V_52 &= 0xffff ;
V_52 >>= 16 - V_54 -> V_55 ;
return V_52 << V_54 -> V_56 ;
}
static int F_13 ( int V_57 , struct V_45 * V_46 )
{
switch ( V_57 ) {
case V_58 :
F_4 ( 0x01 , ( F_10 ( 0x01 ) & ( ~ 0x20 ) ) ) ;
F_4 ( 0x6a , 0x16 ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x21 , ( F_10 ( 0x21 ) & 0x77 ) ) ;
F_4 ( 0x22 , ( F_10 ( 0x22 ) & ( ~ 0x30 ) ) ) ;
F_4 ( 0x23 , ( F_10 ( 0x23 ) & ( ~ 0xc0 ) ) ) ;
F_4 ( 0x24 , ( F_10 ( 0x24 ) | 0x01 ) ) ;
F_4 ( 0x31 , ( F_10 ( 0x31 ) | 0x03 ) ) ;
break;
case V_59 :
F_4 ( 0x01 , ( F_10 ( 0x01 ) & ( ~ 0x20 ) ) ) ;
F_4 ( 0x6a , 0x16 ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x22 , ( F_10 ( 0x22 ) & ( ~ 0x30 ) ) ) ;
F_4 ( 0x23 , ( F_10 ( 0x23 ) & ( ~ 0xc0 ) ) ) ;
F_4 ( 0x24 , ( F_10 ( 0x24 ) | 0x01 ) ) ;
F_4 ( 0x31 , ( ( F_10 ( 0x31 ) & ( ~ 0x07 ) ) | 0x00 ) ) ;
break;
case V_60 :
F_4 ( 0x01 , ( F_10 ( 0x01 ) | 0x20 ) ) ;
F_4 ( 0x20 , ( F_10 ( 0x20 ) & ( ~ 0xB0 ) ) ) ;
F_4 ( 0x6a , 0x0c ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x21 , ( F_10 ( 0x21 ) | 0x88 ) ) ;
F_4 ( 0x22 , ( ( F_10 ( 0x22 ) & ( ~ 0x30 ) ) | 0x20 ) ) ;
F_4 ( 0x23 , ( ( F_10 ( 0x23 ) & ( ~ 0xc0 ) ) | 0x20 ) ) ;
F_4 ( 0x24 , ( F_10 ( 0x24 ) & ( ~ 0x01 ) ) ) ;
F_4 ( 0x31 , ( ( F_10 ( 0x31 ) & ( ~ 0x07 ) ) | 0x00 ) ) ;
F_4 ( 0x34 , ( F_10 ( 0x34 ) | 0x80 ) ) ;
break;
case V_61 :
F_4 ( 0x01 , ( F_10 ( 0x01 ) | 0x20 ) ) ;
F_4 ( 0x20 , ( F_10 ( 0x20 ) & ( ~ 0xB0 ) ) ) ;
F_4 ( 0x6a , 0x0c ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x21 , ( F_10 ( 0x21 ) | 0x88 ) ) ;
F_4 ( 0x22 , ( ( F_10 ( 0x22 ) & ( ~ 0x30 ) ) | 0x10 ) ) ;
F_4 ( 0x23 , ( ( F_10 ( 0x23 ) & ( ~ 0xc0 ) ) | 0xD8 ) ) ;
F_4 ( 0x24 , ( F_10 ( 0x24 ) & ( ~ 0x01 ) ) ) ;
F_4 ( 0x31 , ( ( F_10 ( 0x31 ) & ( ~ 0x07 ) ) | 0x00 ) ) ;
F_4 ( 0x34 , ( F_10 ( 0x34 ) | 0x80 ) ) ;
break;
case V_62 :
F_4 ( 0x01 , ( F_10 ( 0x01 ) | 0x20 ) ) ;
F_4 ( 0x20 , ( F_10 ( 0x20 ) & ( ~ 0xB0 ) ) ) ;
F_4 ( 0x6a , 0x0c ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x21 , ( F_10 ( 0x21 ) | 0x88 ) ) ;
F_4 ( 0x22 , ( ( F_10 ( 0x22 ) & ( ~ 0x30 ) ) | 0x30 ) ) ;
F_4 ( 0x23 , ( ( F_10 ( 0x23 ) & ( ~ 0xc0 ) ) | 0xD8 ) ) ;
F_4 ( 0x24 , ( F_10 ( 0x24 ) & ( ~ 0x01 ) ) ) ;
F_4 ( 0x31 , ( ( F_10 ( 0x31 ) & ( ~ 0x07 ) ) | 0x00 ) ) ;
F_4 ( 0x34 , ( F_10 ( 0x34 ) | 0x80 ) ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static int F_14 ( unsigned V_41 , unsigned V_42 , unsigned V_43 ,
unsigned V_44 , unsigned V_64 , struct V_45 * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_46 ;
T_1 V_65 ;
if ( V_41 > 255 )
return 1 ;
switch ( V_2 -> V_10 . V_66 . V_67 ) {
case V_68 :
case V_69 :
if ( V_41 < 16 ) {
if ( V_2 -> V_10 . V_11 . V_12 == 16 ) {
T_1 * V_70 = V_2 -> V_10 . V_71 ;
V_65 = F_12 ( V_42 , & V_2 -> V_10 . V_11 . V_42 ) ;
V_65 |= F_12 ( V_43 , \
& V_2 -> V_10 . V_11 . V_43 ) ;
V_65 |= F_12 ( V_44 , & V_2 -> V_10 . V_11 . V_44 ) ;
#ifdef F_15
V_70 [ V_41 ] =
( ( V_42 & 0xf800 ) >> 8 ) |
( ( V_43 & 0xe000 ) >> 13 ) |
( ( V_43 & 0x1c00 ) << 3 ) |
( ( V_44 & 0xf800 ) >> 3 ) ;
#else
V_70 [ V_41 ] = V_65 ;
#endif
} else {
T_1 * V_70 = V_2 -> V_10 . V_71 ;
V_65 = F_12 ( V_42 , & V_2 -> V_10 . V_11 . V_42 ) ;
V_65 |= F_12 ( V_43 , \
& V_2 -> V_10 . V_11 . V_43 ) ;
V_65 |= F_12 ( V_44 , & V_2 -> V_10 . V_11 . V_44 ) ;
#ifdef F_15
V_65 =
( V_65 & 0xff00ff00 >> 8 ) |
( V_65 & 0x00ff00ff << 8 ) ;
#endif
V_70 [ V_41 ] = V_65 ;
}
}
break;
case V_72 :
F_9 ( V_41 , V_42 , V_43 , V_44 , V_46 ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static T_2 F_16 ( struct V_45 * V_46 , char T_3 * V_73 , T_4
V_74 , T_5 * V_75 )
{
unsigned long V_76 = * V_75 ;
T_1 * V_77 , * V_78 ;
T_1 T_6 * V_79 ;
int V_80 , V_3 , V_81 = 0 , V_82 = 0 ;
unsigned long V_83 ;
if ( ! V_46 || ! V_46 -> V_84 )
return - V_85 ;
if ( V_46 -> V_86 != V_87 )
return - V_88 ;
V_83 = V_46 -> V_89 ;
if ( V_83 == 0 )
V_83 = V_46 -> V_66 . V_90 ;
if ( V_76 >= V_83 )
return 0 ;
if ( V_74 >= V_83 )
V_74 = V_83 ;
if ( V_74 + V_76 > V_83 )
V_74 = V_83 - V_76 ;
V_77 = F_17 ( ( V_74 > V_91 ) ? V_91 : V_74 , V_92 ) ;
if ( ! V_77 )
return - V_93 ;
V_79 = ( T_1 T_6 * ) ( V_46 -> V_84 + V_76 ) ;
if ( V_46 -> V_94 -> V_95 )
V_46 -> V_94 -> V_95 ( V_46 ) ;
while ( V_74 ) {
V_80 = ( V_74 > V_91 ) ? V_91 : V_74 ;
V_78 = V_77 ;
for ( V_3 = V_80 >> 2 ; V_3 -- ; ) {
* V_78 = F_18 ( V_79 ++ ) ;
* V_78 =
( * V_78 & 0xff00ff00 >> 8 ) |
( * V_78 & 0x00ff00ff << 8 ) ;
V_78 ++ ;
}
if ( V_80 & 3 ) {
T_7 * V_96 = ( T_7 * ) V_78 ;
T_7 T_6 * V_97 = ( T_7 T_6 * ) V_79 ;
for ( V_3 = V_80 & 3 ; V_3 -- ; ) {
if ( V_3 & 1 ) {
* V_96 ++ = F_19 ( ++ V_97 ) ;
} else {
* V_96 ++ = F_19 ( -- V_97 ) ;
V_97 += 2 ;
}
}
V_79 = ( T_1 T_6 * ) V_97 ;
}
if ( F_20 ( V_73 , V_77 , V_80 ) ) {
V_82 = - V_98 ;
break;
}
* V_75 += V_80 ;
V_73 += V_80 ;
V_81 += V_80 ;
V_74 -= V_80 ;
}
F_21 ( V_77 ) ;
return ( V_82 ) ? V_82 : V_81 ;
}
static T_2
F_22 ( struct V_45 * V_46 , const char T_3 * V_73 , T_4 V_74 ,
T_5 * V_75 )
{
unsigned long V_76 = * V_75 ;
T_1 * V_77 , * V_79 ;
T_1 T_6 * V_78 ;
int V_80 , V_3 , V_81 = 0 , V_82 = 0 ;
unsigned long V_83 ;
if ( ! V_46 || ! V_46 -> V_84 )
return - V_85 ;
if ( V_46 -> V_86 != V_87 )
return - V_88 ;
V_83 = V_46 -> V_89 ;
if ( V_83 == 0 )
V_83 = V_46 -> V_66 . V_90 ;
if ( V_76 > V_83 )
return - V_99 ;
if ( V_74 > V_83 ) {
V_82 = - V_99 ;
V_74 = V_83 ;
}
if ( V_74 + V_76 > V_83 ) {
if ( ! V_82 )
V_82 = - V_100 ;
V_74 = V_83 - V_76 ;
}
V_77 = F_17 ( ( V_74 > V_91 ) ? V_91 : V_74 , V_92 ) ;
if ( ! V_77 )
return - V_93 ;
V_78 = ( T_1 T_6 * ) ( V_46 -> V_84 + V_76 ) ;
if ( V_46 -> V_94 -> V_95 )
V_46 -> V_94 -> V_95 ( V_46 ) ;
while ( V_74 ) {
V_80 = ( V_74 > V_91 ) ? V_91 : V_74 ;
V_79 = V_77 ;
if ( F_23 ( V_79 , V_73 , V_80 ) ) {
V_82 = - V_98 ;
break;
}
for ( V_3 = V_80 >> 2 ; V_3 -- ; ) {
F_24 ( ( * V_79 & 0xff00ff00 >> 8 ) |
( * V_79 & 0x00ff00ff << 8 ) , V_78 ++ ) ;
V_79 ++ ;
}
if ( V_80 & 3 ) {
T_7 * V_97 = ( T_7 * ) V_79 ;
T_7 T_6 * V_96 = ( T_7 T_6 * ) V_78 ;
for ( V_3 = V_80 & 3 ; V_3 -- ; ) {
if ( V_3 & 1 ) {
F_25 ( * V_97 ++ , ++ V_96 ) ;
} else {
F_25 ( * V_97 ++ , -- V_96 ) ;
V_96 += 2 ;
}
}
V_78 = ( T_1 T_6 * ) V_96 ;
}
* V_75 += V_80 ;
V_73 += V_80 ;
V_81 += V_80 ;
V_74 -= V_80 ;
}
F_21 ( V_77 ) ;
return ( V_81 ) ? V_81 : V_82 ;
}
void F_26 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 . V_11 . V_12 ) {
case 32 :
V_2 -> V_10 . V_66 . V_67 = V_69 ;
V_2 -> V_10 . V_66 . V_101 = V_2 -> V_10 . V_11 . V_102 * 4 ;
V_2 -> V_10 . V_11 . V_42 . V_55 = 8 ;
V_2 -> V_10 . V_11 . V_43 . V_55 = 8 ;
V_2 -> V_10 . V_11 . V_44 . V_55 = 8 ;
V_2 -> V_10 . V_11 . V_42 . V_56 = 16 ;
V_2 -> V_10 . V_11 . V_43 . V_56 = 8 ;
V_2 -> V_10 . V_11 . V_44 . V_56 = 0 ;
break;
case 8 :
V_2 -> V_10 . V_66 . V_67 = V_72 ;
V_2 -> V_10 . V_66 . V_101 = V_2 -> V_10 . V_11 . V_102 ;
V_2 -> V_10 . V_11 . V_42 . V_56 = 5 ;
V_2 -> V_10 . V_11 . V_42 . V_55 = 3 ;
V_2 -> V_10 . V_11 . V_43 . V_56 = 2 ;
V_2 -> V_10 . V_11 . V_43 . V_55 = 3 ;
V_2 -> V_10 . V_11 . V_44 . V_56 = 0 ;
V_2 -> V_10 . V_11 . V_44 . V_55 = 2 ;
break;
case 24 :
V_2 -> V_10 . V_66 . V_67 = V_69 ;
V_2 -> V_10 . V_66 . V_101 = V_2 -> V_10 . V_11 . V_102 * 3 ;
V_2 -> V_10 . V_11 . V_42 . V_55 = 8 ;
V_2 -> V_10 . V_11 . V_43 . V_55 = 8 ;
V_2 -> V_10 . V_11 . V_44 . V_55 = 8 ;
V_2 -> V_10 . V_11 . V_42 . V_56 = 16 ;
V_2 -> V_10 . V_11 . V_43 . V_56 = 8 ;
V_2 -> V_10 . V_11 . V_44 . V_56 = 0 ;
break;
case 16 :
default:
V_2 -> V_10 . V_66 . V_67 = V_69 ;
V_2 -> V_10 . V_66 . V_101 = V_2 -> V_10 . V_11 . V_102 * 2 ;
V_2 -> V_10 . V_11 . V_42 . V_55 = 5 ;
V_2 -> V_10 . V_11 . V_43 . V_55 = 6 ;
V_2 -> V_10 . V_11 . V_44 . V_55 = 5 ;
V_2 -> V_10 . V_11 . V_42 . V_56 = 11 ;
V_2 -> V_10 . V_11 . V_43 . V_56 = 5 ;
V_2 -> V_10 . V_11 . V_44 . V_56 = 0 ;
break;
}
V_2 -> V_8 = V_2 -> V_10 . V_11 . V_102 ;
V_2 -> V_9 = V_2 -> V_10 . V_11 . V_103 ;
V_2 -> V_13 = 60 ;
F_11 ( V_2 ) ;
}
static int F_27 ( struct V_104 * V_11 , struct V_45 * V_46 )
{
if ( V_11 -> V_105 < V_11 -> V_102 )
V_11 -> V_105 = V_11 -> V_102 ;
if ( V_11 -> V_106 < V_11 -> V_103 )
V_11 -> V_106 = V_11 -> V_103 ;
if ( ( V_11 -> V_12 != 8 ) && ( V_11 -> V_12 != 16 ) &&
( V_11 -> V_12 != 24 ) && ( V_11 -> V_12 != 32 ) )
V_11 -> V_12 = 16 ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_46 ;
F_26 ( V_2 ) ;
return 0 ;
}
static struct V_1 * F_29 ( struct V_107 * V_6 , char * V_108 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = V_6 ;
V_2 -> V_10 . V_109 = V_110 ;
V_2 -> V_10 . V_94 = & V_111 ;
V_2 -> V_10 . V_11 = V_112 ;
V_2 -> V_10 . V_66 = V_113 ;
strcpy ( V_2 -> V_10 . V_66 . V_114 , V_108 ) ;
V_2 -> V_10 . V_66 . type = V_115 ;
V_2 -> V_10 . V_66 . V_116 = 0 ;
V_2 -> V_10 . V_66 . V_117 = 0 ;
V_2 -> V_10 . V_66 . V_118 = 0 ;
V_2 -> V_10 . V_66 . V_119 = 0 ;
V_2 -> V_10 . V_66 . V_120 = V_121 ;
V_2 -> V_10 . V_11 . V_122 = 0 ;
V_2 -> V_10 . V_11 . V_123 = V_124 ;
V_2 -> V_10 . V_11 . V_9 = - 1 ;
V_2 -> V_10 . V_11 . V_8 = - 1 ;
V_2 -> V_10 . V_11 . V_125 = V_126 ;
V_2 -> V_10 . V_11 . V_127 = V_128 ;
V_2 -> V_10 . V_47 = V_2 ;
V_2 -> V_10 . V_71 = V_129 ;
return V_2 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 && V_130 )
V_130 = NULL ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_107 * V_6 , T_8 V_90 )
{
if ( V_2 -> V_10 . V_11 . V_12 == 32 ) {
#ifdef F_15
V_2 -> V_10 . V_66 . V_131 = F_33 ( V_6 , 0 )
+ 0x800000 ;
#else
V_2 -> V_10 . V_66 . V_131 = F_33 ( V_6 , 0 ) ;
#endif
} else {
V_2 -> V_10 . V_66 . V_131 = F_33 ( V_6 , 0 ) ;
}
V_2 -> V_10 . V_66 . V_90 = V_90 ;
V_2 -> V_10 . V_84 = V_132 ;
if ( ! V_2 -> V_10 . V_84 ) {
F_34 ( & V_6 -> V_7 ,
L_6 , V_2 -> V_10 . V_66 . V_114 ) ;
return - V_93 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_10 . V_84 ) {
F_36 ( V_2 -> V_10 . V_84 ) ;
V_2 -> V_10 . V_84 = NULL ;
}
}
static inline void F_37 ( void )
{
F_38 ( 0x18 , 0x3c4 ) ;
F_38 ( 0x11 , 0x3c5 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_40 ( & V_2 -> V_10 . V_133 , 0 , 0 ) ;
F_21 ( V_2 ) ;
}
}
static int T_9 F_41 ( char * V_134 )
{
int V_135 ;
if ( ! V_134 || ! * V_134 )
return - V_63 ;
V_136 . V_137 = 0 ;
V_136 . V_138 = 0 ;
V_136 . V_139 = 0 ;
F_42 ( L_7 , V_134 ) ;
for ( V_135 = 0 ;
V_135 < F_43 ( V_140 ) ;
V_135 ++ ) {
if ( strstr ( V_134 , V_140 [ V_135 ] . V_141 ) ) {
V_136 . V_137 = V_140 [ V_135 ] . V_137 ;
V_136 . V_138 =
V_140 [ V_135 ] . V_138 ;
V_136 . V_139 = V_140 [ V_135 ] . V_139 ;
return 0 ;
}
}
return - 1 ;
}
static int T_10 F_44 ( struct V_107 * V_6 ,
const struct V_142 * V_143 )
{
struct V_1 * V_2 ;
T_8 V_144 = 0x00800000 ;
char V_108 [ 16 ] ;
int V_82 ;
unsigned long V_145 ;
F_45 ( & V_6 -> V_7 , L_8 ) ;
V_82 = F_46 ( V_6 ) ;
if ( V_82 )
return V_82 ;
V_2 = F_29 ( V_6 , V_108 ) ;
if ( ! V_2 )
goto V_146;
V_2 -> V_51 = V_143 -> V_147 ;
sprintf ( V_108 , L_9 , V_2 -> V_51 ) ;
F_47 ( V_6 , V_2 ) ;
F_37 () ;
if ( V_136 . V_137 != 0 ) {
V_2 -> V_10 . V_11 . V_102 = V_136 . V_137 ;
V_2 -> V_10 . V_11 . V_103 = V_136 . V_138 ;
V_2 -> V_10 . V_11 . V_12 = V_136 . V_139 ;
} else {
V_2 -> V_10 . V_11 . V_102 = V_148 ;
V_2 -> V_10 . V_11 . V_103 = V_149 ;
V_2 -> V_10 . V_11 . V_12 = V_150 ;
}
#ifdef F_15
if ( V_2 -> V_10 . V_11 . V_12 == 24 )
V_2 -> V_10 . V_11 . V_12 = ( V_136 . V_139 = 32 ) ;
#endif
V_145 = F_33 ( V_6 , 0 ) ;
F_48 ( V_6 , V_151 , & V_2 -> V_152 ) ;
switch ( V_2 -> V_51 ) {
case 0x710 :
case 0x712 :
V_2 -> V_10 . V_66 . V_153 = V_145 + 0x00400000 ;
V_2 -> V_10 . V_66 . V_154 = 0x00400000 ;
V_144 = V_155 ;
#ifdef F_15
V_2 -> V_156 = ( V_132 =
F_49 ( V_145 , 0x00c00000 ) ) ;
#else
V_2 -> V_156 = ( V_132 =
F_49 ( V_145 , 0x00800000 ) ) ;
#endif
V_2 -> V_157 = ( V_130 =
V_132 + 0x00700000 ) ;
V_2 -> V_158 = V_132 + 0x00408000 ;
V_2 -> V_40 = V_2 -> V_156 + 0x0040c000 ;
#ifdef F_15
if ( V_2 -> V_10 . V_11 . V_12 == 32 ) {
V_132 += 0x800000 ;
V_2 -> V_156 += 0x800000 ;
F_45 ( & V_6 -> V_7 ,
L_10 ,
V_132 , V_2 -> V_156 ) ;
}
#endif
if ( ! V_130 ) {
F_34 ( & V_6 -> V_7 ,
L_11 ,
V_2 -> V_10 . V_66 . V_114 ) ;
V_82 = - V_93 ;
goto V_159;
}
F_4 ( 0x6a , 0x16 ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x62 , 0x3e ) ;
F_4 ( 0x17 , 0x20 ) ;
#ifdef F_15
if ( V_2 -> V_10 . V_11 . V_12 == 32 )
F_4 ( 0x17 , 0x30 ) ;
#endif
break;
case 0x720 :
V_2 -> V_10 . V_66 . V_153 = V_145 ;
V_2 -> V_10 . V_66 . V_154 = 0x00200000 ;
V_144 = V_160 ;
V_2 -> V_158 = F_49 ( V_145 , 0x00a00000 ) ;
V_2 -> V_156 = ( V_132 =
V_2 -> V_158 + 0x00200000 ) ;
V_2 -> V_157 = ( V_130 =
V_2 -> V_158 + 0x000c0000 ) ;
V_2 -> V_40 = V_2 -> V_158 + 0x800 ;
F_4 ( 0x62 , 0xff ) ;
F_4 ( 0x6a , 0x0d ) ;
F_4 ( 0x6b , 0x02 ) ;
break;
default:
F_34 ( & V_6 -> V_7 ,
L_12 ) ;
goto V_159;
}
if ( 15 == V_2 -> V_10 . V_11 . V_12 )
V_2 -> V_10 . V_11 . V_12 = 16 ;
V_2 -> V_10 . V_11 . V_105 = V_2 -> V_10 . V_11 . V_102 ;
V_2 -> V_10 . V_11 . V_106 = V_2 -> V_10 . V_11 . V_103 ;
V_82 = F_32 ( V_2 , V_6 , V_144 ) ;
if ( V_82 )
goto V_161;
F_26 ( V_2 ) ;
V_2 -> V_48 = 0 ;
V_82 = F_50 ( & V_2 -> V_10 ) ;
if ( V_82 < 0 )
goto V_161;
F_45 ( & V_6 -> V_7 ,
L_13 ,
V_2 -> V_51 , V_2 -> V_152 , V_2 -> V_10 . V_11 . V_102 ,
V_2 -> V_10 . V_11 . V_103 , V_2 -> V_10 . V_11 . V_12 ) ;
return 0 ;
V_161:
F_34 ( & V_6 -> V_7 , L_14 ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
V_159:
F_39 ( V_2 ) ;
V_146:
F_51 ( V_6 ) ;
return V_82 ;
}
static void T_11 F_52 ( struct V_107 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_53 ( V_6 ) ;
F_47 ( V_6 , NULL ) ;
F_35 ( V_2 ) ;
F_31 ( V_2 ) ;
F_54 ( & V_2 -> V_10 ) ;
F_39 ( V_2 ) ;
}
static int F_55 ( struct V_147 * V_147 )
{
struct V_107 * V_6 = F_56 ( V_147 ) ;
struct V_1 * V_2 ;
V_2 = F_53 ( V_6 ) ;
F_4 ( 0x20 , ( F_10 ( 0x20 ) | 0xc0 ) ) ;
F_4 ( 0x69 , ( F_10 ( 0x69 ) & 0xf7 ) ) ;
F_57 () ;
F_58 ( & V_2 -> V_10 , 1 ) ;
F_59 () ;
F_4 ( 0x21 , 0xff ) ;
return 0 ;
}
static int F_60 ( struct V_147 * V_147 )
{
struct V_107 * V_6 = F_56 ( V_147 ) ;
struct V_1 * V_2 ;
V_2 = F_53 ( V_6 ) ;
F_37 () ;
switch ( V_2 -> V_51 ) {
case 0x710 :
case 0x712 :
F_4 ( 0x6a , 0x16 ) ;
F_4 ( 0x6b , 0x02 ) ;
F_4 ( 0x62 , 0x3e ) ;
F_4 ( 0x17 , 0x20 ) ;
#ifdef F_15
if ( V_2 -> V_10 . V_11 . V_12 == 32 )
F_4 ( 0x17 , 0x30 ) ;
#endif
break;
case 0x720 :
F_4 ( 0x62 , 0xff ) ;
F_4 ( 0x6a , 0x0d ) ;
F_4 ( 0x6b , 0x02 ) ;
break;
}
F_4 ( 0x34 , ( F_10 ( 0x34 ) | 0xc0 ) ) ;
F_4 ( 0x33 , ( ( F_10 ( 0x33 ) | 0x08 ) & 0xfb ) ) ;
F_26 ( V_2 ) ;
F_57 () ;
F_58 ( & V_2 -> V_10 , 0 ) ;
F_59 () ;
return 0 ;
}
static int T_9 F_61 ( void )
{
return F_62 ( & V_162 ) ;
}
static void T_12 F_63 ( void )
{
F_64 ( & V_162 ) ;
}
