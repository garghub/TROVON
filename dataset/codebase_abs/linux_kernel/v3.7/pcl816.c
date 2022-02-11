static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_9 ;
F_2 ( L_1 ) ;
F_3 ( 0 , V_2 -> V_10 + V_11 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
F_3 ( F_4 ( V_6 -> V_13 ) & 0xf , V_2 -> V_10 + V_14 ) ;
F_3 ( F_5 ( V_6 -> V_13 ) , V_2 -> V_10 + V_15 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_3 ( 0 , V_2 -> V_10 + V_16 ) ;
V_9 = 100 ;
while ( V_9 -- ) {
if ( ! ( F_6 ( V_2 -> V_10 + V_17 ) &
V_18 ) ) {
V_7 [ V_8 ] =
( ( F_6 ( V_2 -> V_10 +
V_19 ) << 8 ) |
( F_6 ( V_2 -> V_10 + V_16 ) ) ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
break;
}
F_7 ( 1 ) ;
}
if ( ! V_9 ) {
F_8 ( V_2 , L_2 ) ;
V_7 [ 0 ] = 0 ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
return - V_20 ;
}
}
return V_8 ;
}
static T_1 F_9 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_3 * V_4 = & V_2 -> V_23 [ 0 ] ;
int V_24 , V_25 ;
int V_9 = 50 ;
while ( V_9 -- ) {
if ( ! ( F_6 ( V_2 -> V_10 + V_17 ) &
V_18 ) )
break;
F_7 ( 1 ) ;
}
if ( ! V_9 ) {
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
F_8 ( V_2 , L_3 ) ;
F_10 ( V_2 , V_4 ) ;
V_4 -> V_26 -> V_27 |= V_28 | V_29 ;
F_11 ( V_2 , V_4 ) ;
return V_30 ;
}
V_24 = F_6 ( V_2 -> V_10 + V_16 ) ;
V_25 = F_6 ( V_2 -> V_10 + V_19 ) ;
F_12 ( V_4 -> V_26 , ( V_25 << 8 ) | V_24 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
if ( ++ V_31 -> V_32 >= V_31 -> V_33 )
V_31 -> V_32 = 0 ;
V_4 -> V_26 -> V_34 ++ ;
if ( V_4 -> V_26 -> V_34 >= V_31 -> V_35 ) {
V_4 -> V_26 -> V_34 = 0 ;
V_31 -> V_36 ++ ;
}
if ( ! V_31 -> V_37 )
if ( V_31 -> V_36 >= V_31 -> V_38 ) {
F_10 ( V_2 , V_4 ) ;
V_4 -> V_26 -> V_27 |= V_28 ;
}
F_11 ( V_2 , V_4 ) ;
return V_30 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , short * V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
int V_42 ;
V_4 -> V_26 -> V_27 = 0 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
F_12 ( V_4 -> V_26 , V_39 [ V_40 ++ ] ) ;
if ( ++ V_31 -> V_32 >=
V_31 -> V_33 ) {
V_31 -> V_32 = 0 ;
}
V_4 -> V_26 -> V_34 ++ ;
if ( V_4 -> V_26 -> V_34 >= V_31 -> V_35 ) {
V_4 -> V_26 -> V_34 = 0 ;
V_31 -> V_36 ++ ;
}
if ( ! V_31 -> V_37 )
if ( V_31 -> V_36 >= V_31 -> V_38 ) {
F_10 ( V_2 , V_4 ) ;
V_4 -> V_26 -> V_27 |= V_28 ;
V_4 -> V_26 -> V_27 |= V_43 ;
break;
}
}
F_11 ( V_2 , V_4 ) ;
}
static T_1 F_14 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_3 * V_4 = & V_2 -> V_23 [ 0 ] ;
int V_41 , V_40 , V_44 ;
unsigned long V_45 ;
short * V_39 ;
F_15 ( V_31 -> V_46 ) ;
V_44 = V_31 -> V_47 ;
if ( ( V_31 -> V_48 > - 1 ) || V_31 -> V_37 ) {
V_31 -> V_47 = 1 - V_31 -> V_47 ;
F_16 ( V_31 -> V_46 , V_49 ) ;
V_45 = F_17 () ;
F_18 ( V_31 -> V_46 ,
V_31 -> V_50 [ V_31 -> V_47 ] ) ;
if ( V_31 -> V_48 ) {
F_19 ( V_31 -> V_46 ,
V_31 -> V_51 [ V_31 ->
V_47 ] ) ;
} else {
F_19 ( V_31 -> V_46 , V_31 -> V_52 ) ;
}
F_20 ( V_45 ) ;
F_21 ( V_31 -> V_46 ) ;
}
V_31 -> V_48 -- ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
V_39 = ( short * ) V_31 -> V_53 [ V_44 ] ;
V_41 = ( V_31 -> V_51 [ 0 ] >> 1 ) - V_31 -> V_54 ;
V_40 = V_31 -> V_54 ;
V_31 -> V_54 = 0 ;
F_13 ( V_2 , V_4 , V_39 , V_40 , V_41 ) ;
return V_30 ;
}
static T_1 F_22 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
F_2 ( L_4 ) ;
if ( ! V_2 -> V_55 ) {
F_8 ( V_2 , L_5 ) ;
return V_30 ;
}
switch ( V_31 -> V_56 ) {
case V_57 :
case V_58 :
return F_14 ( V_21 , V_22 ) ;
case V_59 :
case V_60 :
return F_9 ( V_21 , V_22 ) ;
}
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
if ( ! V_2 -> V_21 || ! V_31 -> V_61 || ! V_31 -> V_62 ||
! V_31 -> V_56 ) {
if ( V_31 -> V_63 ) {
V_31 -> V_63 = 0 ;
return V_30 ;
}
F_8 ( V_2 , L_6 ) ;
return V_64 ;
}
F_8 ( V_2 , L_7 ) ;
return V_64 ;
}
static void F_23 ( int V_65 , struct V_66 * V_67 )
{
F_24 ( V_68 L_8 , V_65 ,
V_67 -> V_69 , V_67 -> V_70 , V_67 -> V_71 ) ;
F_24 ( V_68 L_9 , V_65 ,
V_67 -> V_72 , V_67 -> V_73 , V_67 -> V_74 ) ;
F_24 ( V_68 L_10 , V_65 ,
V_67 -> V_75 , V_67 -> V_76 ) ;
F_24 ( V_68 L_11 ,
V_65 , V_67 -> V_77 , V_67 -> V_78 , V_67 -> V_79 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_66 * V_67 )
{
const struct V_80 * V_81 = F_26 ( V_2 ) ;
int V_82 = 0 ;
int V_83 , V_84 = 0 , V_85 = 0 ;
F_27 (printk(KERN_INFO L_12);
pcl816_cmdtest_out(-1, cmd);
) ;
V_82 |= F_28 ( & V_67 -> V_69 , V_86 ) ;
V_82 |= F_28 ( & V_67 -> V_70 , V_87 ) ;
V_82 |= F_28 ( & V_67 -> V_71 , V_88 | V_89 ) ;
V_82 |= F_28 ( & V_67 -> V_76 , V_90 ) ;
V_82 |= F_28 ( & V_67 -> V_75 , V_90 | V_91 ) ;
if ( V_82 )
return 1 ;
V_82 |= F_29 ( V_67 -> V_71 ) ;
V_82 |= F_29 ( V_67 -> V_75 ) ;
if ( V_82 )
return 2 ;
if ( V_67 -> V_72 != 0 ) {
V_67 -> V_72 = 0 ;
V_82 ++ ;
}
if ( V_67 -> V_73 != 0 ) {
V_67 -> V_73 = 0 ;
V_82 ++ ;
}
if ( V_67 -> V_71 == V_89 ) {
if ( V_67 -> V_74 < V_81 -> V_92 ) {
V_67 -> V_74 = V_81 -> V_92 ;
V_82 ++ ;
}
} else {
if ( V_67 -> V_74 != 0 ) {
V_67 -> V_74 = 0 ;
V_82 ++ ;
}
}
if ( V_67 -> V_78 != V_67 -> V_79 ) {
V_67 -> V_78 = V_67 -> V_79 ;
V_82 ++ ;
}
if ( V_67 -> V_75 == V_90 ) {
if ( ! V_67 -> V_77 ) {
V_67 -> V_77 = 1 ;
V_82 ++ ;
}
} else {
if ( V_67 -> V_77 != 0 ) {
V_67 -> V_77 = 0 ;
V_82 ++ ;
}
}
if ( V_82 )
return 3 ;
if ( V_67 -> V_71 == V_89 ) {
V_83 = V_67 -> V_74 ;
F_30 ( V_81 -> V_93 ,
& V_84 , & V_85 ,
& V_67 -> V_74 ,
V_67 -> V_94 & V_95 ) ;
if ( V_67 -> V_74 < V_81 -> V_92 )
V_67 -> V_74 = V_81 -> V_92 ;
if ( V_83 != V_67 -> V_74 )
V_82 ++ ;
}
if ( V_82 )
return 4 ;
if ( V_67 -> V_96 ) {
if ( ! F_31 ( V_2 , V_4 , V_67 -> V_96 ,
V_67 -> V_79 ) )
return 5 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_80 * V_81 = F_26 ( V_2 ) ;
unsigned int V_84 = 0 , V_85 = 0 , V_45 , V_97 , V_98 ;
struct V_66 * V_67 = & V_4 -> V_26 -> V_67 ;
unsigned int V_99 ;
if ( V_67 -> V_69 != V_86 )
return - V_100 ;
if ( V_67 -> V_70 != V_87 )
return - V_100 ;
if ( V_67 -> V_76 != V_90 )
return - V_100 ;
if ( V_67 -> V_78 != V_67 -> V_79 )
return - V_100 ;
if ( V_31 -> V_62 )
return - V_101 ;
if ( V_67 -> V_71 == V_89 ) {
if ( V_67 -> V_74 < V_81 -> V_92 )
V_67 -> V_74 = V_81 -> V_92 ;
F_30 ( V_81 -> V_93 , & V_84 ,
& V_85 , & V_67 -> V_74 ,
V_67 -> V_94 & V_95 ) ;
if ( V_84 == 1 ) {
V_84 = 2 ;
V_85 /= 2 ;
}
if ( V_85 == 1 ) {
V_85 = 2 ;
V_84 /= 2 ;
}
}
F_33 ( V_2 , - 1 , 0 , 0 ) ;
V_99 = F_31 ( V_2 , V_4 , V_67 -> V_96 , V_67 -> V_79 ) ;
if ( V_99 < 1 )
return - V_100 ;
F_34 ( V_2 , V_4 , V_67 -> V_96 , V_99 ) ;
F_7 ( 1 ) ;
V_31 -> V_35 = V_67 -> V_79 ;
V_31 -> V_36 = 0 ;
V_4 -> V_26 -> V_34 = 0 ;
V_31 -> V_62 = 1 ;
V_31 -> V_54 = 0 ;
V_31 -> V_63 = 0 ;
if ( V_67 -> V_75 == V_90 ) {
V_31 -> V_38 = V_67 -> V_77 ;
V_31 -> V_37 = 0 ;
} else {
V_31 -> V_38 = 0 ;
V_31 -> V_37 = 1 ;
}
if ( ( V_67 -> V_94 & V_102 ) ) {
F_24 ( V_68
L_13 ) ;
}
if ( V_31 -> V_46 ) {
V_97 = V_31 -> V_51 [ 0 ] ;
if ( ! V_31 -> V_37 ) {
V_97 = V_4 -> V_26 -> V_67 . V_79 *
V_4 -> V_26 -> V_67 . V_79 *
sizeof( short ) ;
V_31 -> V_48 = V_97 /
V_31 -> V_51 [ 0 ] ;
V_31 -> V_52 = V_97 % V_31 -> V_51 [ 0 ] ;
V_31 -> V_48 -- ;
if ( V_31 -> V_48 >= 0 )
V_97 = V_31 -> V_51 [ 0 ] ;
} else
V_31 -> V_48 = - 1 ;
V_31 -> V_47 = 0 ;
F_16 ( V_31 -> V_46 , V_49 ) ;
V_45 = F_17 () ;
F_35 ( V_31 -> V_46 ) ;
F_18 ( V_31 -> V_46 , V_31 -> V_50 [ 0 ] ) ;
F_19 ( V_31 -> V_46 , V_97 ) ;
F_20 ( V_45 ) ;
F_21 ( V_31 -> V_46 ) ;
}
F_33 ( V_2 , 1 , V_84 , V_85 ) ;
V_98 = ( ( V_31 -> V_46 & 0x3 ) << 4 ) | ( V_2 -> V_21 & 0x7 ) ;
switch ( V_67 -> V_71 ) {
case V_89 :
V_31 -> V_56 = V_57 ;
F_3 ( 0x32 , V_2 -> V_10 + V_11 ) ;
F_3 ( V_98 , V_2 -> V_10 + V_17 ) ;
break;
default:
V_31 -> V_56 = V_58 ;
F_3 ( 0x34 , V_2 -> V_10 + V_11 ) ;
F_3 ( V_98 , V_2 -> V_10 + V_17 ) ;
break;
}
F_2 ( L_14 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_94 ;
unsigned int V_103 , V_104 , V_42 ;
if ( ! V_31 -> V_46 )
return 0 ;
F_37 ( & V_2 -> V_105 , V_94 ) ;
for ( V_42 = 0 ; V_42 < 20 ; V_42 ++ ) {
V_103 = F_38 ( V_31 -> V_46 ) ;
V_104 = F_38 ( V_31 -> V_46 ) ;
if ( V_103 == V_104 )
break;
}
if ( V_103 != V_104 ) {
F_39 ( & V_2 -> V_105 , V_94 ) ;
return 0 ;
}
V_103 = V_31 -> V_51 [ 0 ] - V_103 ;
V_103 >>= 1 ;
V_104 = V_103 - V_31 -> V_54 ;
if ( V_104 < 1 ) {
F_39 ( & V_2 -> V_105 , V_94 ) ;
return 0 ;
}
F_13 ( V_2 , V_4 ,
( short * ) V_31 -> V_53 [ V_31 -> V_47 ] ,
V_31 -> V_54 , V_104 ) ;
V_31 -> V_54 = V_103 ;
F_39 ( & V_2 -> V_105 , V_94 ) ;
return V_4 -> V_26 -> V_106 - V_4 -> V_26 -> V_107 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_31 -> V_62 > 0 ) {
switch ( V_31 -> V_56 ) {
#ifdef F_40
case V_108 :
case V_109 :
F_41 ( 0 ) ;
F_42 ( & V_31 -> V_110 ) ;
#endif
case V_57 :
case V_58 :
F_15 ( V_31 -> V_46 ) ;
case V_59 :
case V_60 :
F_3 ( F_6 ( V_2 -> V_10 + V_11 ) & 0x73 ,
V_2 -> V_10 + V_11 ) ;
F_7 ( 1 ) ;
F_3 ( 0 , V_2 -> V_10 + V_11 ) ;
F_3 ( 0xb0 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0x70 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0 , V_2 -> V_10 + V_16 ) ;
F_6 ( V_2 -> V_10 + V_16 ) ;
F_6 ( V_2 -> V_10 + V_19 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
F_3 ( 0 , V_2 -> V_10 + V_11 ) ;
V_31 -> V_62 = 0 ;
V_31 -> V_63 = V_31 -> V_56 ;
V_31 -> V_56 = 0 ;
V_31 -> V_112 = V_4 ;
break;
}
}
F_27 (printk(L_15);)
return 0 ;
}
static int F_43 ( unsigned long V_10 )
{
F_3 ( 0x00 , V_10 + V_14 ) ;
F_7 ( 1 ) ;
if ( F_6 ( V_10 + V_14 ) != 0x00 )
return 1 ;
F_3 ( 0x55 , V_10 + V_14 ) ;
F_7 ( 1 ) ;
if ( F_6 ( V_10 + V_14 ) != 0x55 )
return 1 ;
F_3 ( 0x00 , V_10 + V_14 ) ;
F_7 ( 1 ) ;
F_3 ( 0x18 , V_10 + V_11 ) ;
F_7 ( 1 ) ;
if ( F_6 ( V_10 + V_11 ) != 0x18 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_10 + V_11 ) ;
F_3 ( 0 , V_2 -> V_10 + V_14 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
F_3 ( 0xb0 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0x70 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0x30 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0 , V_2 -> V_10 + V_15 ) ;
}
static void
F_33 ( struct V_1 * V_2 , int V_113 , unsigned int V_84 ,
unsigned int V_85 )
{
F_3 ( 0x32 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0xff , V_2 -> V_10 + V_114 ) ;
F_3 ( 0x00 , V_2 -> V_10 + V_114 ) ;
F_7 ( 1 ) ;
F_3 ( 0xb4 , V_2 -> V_10 + V_111 ) ;
F_3 ( 0x74 , V_2 -> V_10 + V_111 ) ;
F_7 ( 1 ) ;
if ( V_113 == 1 ) {
F_2 ( L_16 , V_113 , V_84 ,
V_85 ) ;
F_3 ( V_85 & 0xff , V_2 -> V_10 + V_115 ) ;
F_3 ( ( V_85 >> 8 ) & 0xff , V_2 -> V_10 + V_115 ) ;
F_3 ( V_84 & 0xff , V_2 -> V_10 + V_116 ) ;
F_3 ( ( V_84 >> 8 ) & 0xff , V_2 -> V_10 + V_116 ) ;
}
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_96 ,
unsigned int V_117 )
{
unsigned int V_118 [ 16 ] ;
unsigned int V_42 , V_119 , V_99 , V_120 ;
if ( V_117 < 1 ) {
F_8 ( V_2 , L_17 ) ;
return 0 ;
}
if ( V_117 > 1 ) {
V_118 [ 0 ] = V_96 [ 0 ] ;
for ( V_42 = 1 , V_99 = 1 ; V_42 < V_117 ; V_42 ++ , V_99 ++ ) {
F_27 (printk(KERN_INFO L_18, i,
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_96 [ 0 ] == V_96 [ V_42 ] )
break;
V_119 =
( F_4 ( V_118 [ V_42 - 1 ] ) + 1 ) % V_117 ;
if ( V_119 != F_4 ( V_96 [ V_42 ] ) ) {
F_24 ( V_121
L_19
L_20
L_21 , V_2 -> V_122 ,
V_42 , F_4 ( V_96 [ V_42 ] ) , V_119 ,
F_4 ( V_96 [ 0 ] ) ) ;
return 0 ;
}
V_118 [ V_42 ] = V_96 [ V_42 ] ;
}
for ( V_42 = 0 , V_120 = 0 ; V_42 < V_117 ; V_42 ++ ) {
F_27 (printk(L_22,
CR_CHAN(chansegment[i % seglen]),
CR_RANGE(chansegment[i % seglen]),
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_96 [ V_42 ] != V_118 [ V_42 % V_99 ] ) {
F_24 ( V_121
L_23
L_24
L_25 , V_2 -> V_122 , V_42 ,
F_4 ( V_118 [ V_42 ] ) ,
F_5 ( V_118 [ V_42 ] ) ,
F_45 ( V_118 [ V_42 ] ) ,
F_4 ( V_96 [ V_42 % V_99 ] ) ,
F_5 ( V_96 [ V_42 % V_99 ] ) ,
F_45 ( V_118 [ V_42 % V_99 ] ) ) ;
return 0 ;
}
}
} else {
V_99 = 1 ;
}
return V_99 ;
}
static void
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_96 ,
unsigned int V_99 )
{
unsigned int V_42 ;
V_31 -> V_33 = V_99 ;
V_31 -> V_32 = 0 ;
for ( V_42 = 0 ; V_42 < V_99 ; V_42 ++ ) {
V_31 -> V_123 [ V_42 ] = F_4 ( V_96 [ V_42 ] ) ;
F_3 ( F_4 ( V_96 [ 0 ] ) & 0xf , V_2 -> V_10 + V_14 ) ;
F_3 ( F_5 ( V_96 [ 0 ] ) , V_2 -> V_10 + V_15 ) ;
}
F_7 ( 1 ) ;
F_3 ( V_31 -> V_123 [ 0 ] |
( V_31 -> V_123 [ V_99 - 1 ] << 4 ) ,
V_2 -> V_10 + V_14 ) ;
}
static int F_41 ( unsigned char V_124 )
{
unsigned char V_125 ;
unsigned long V_94 ;
if ( V_124 == 1 ) {
V_126 ++ ;
if ( V_126 > 1 )
return 0 ;
} else {
V_126 -- ;
if ( V_126 < 0 )
V_126 = 0 ;
if ( V_126 > 0 )
return 0 ;
}
F_46 ( V_94 ) ;
F_47 () ;
V_125 = F_48 ( V_127 ) ;
if ( V_124 )
V_125 |= V_128 ;
else
V_125 &= ~ V_128 ;
F_49 ( V_125 , V_127 ) ;
F_48 ( V_129 ) ;
F_50 ( V_94 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
const struct V_80 * V_81 = F_26 ( V_2 ) ;
int V_132 ;
unsigned long V_10 ;
unsigned int V_21 , V_46 ;
unsigned long V_133 ;
struct V_3 * V_4 ;
V_10 = V_131 -> V_134 [ 0 ] ;
F_24 ( L_26 , V_2 -> V_122 ,
V_81 -> V_135 , V_10 ) ;
if ( ! F_52 ( V_10 , V_81 -> V_136 , L_27 ) ) {
F_24 ( L_28 ) ;
return - V_20 ;
}
V_2 -> V_10 = V_10 ;
if ( F_43 ( V_10 ) ) {
F_24 ( V_137 L_29 ) ;
return - V_20 ;
}
V_132 = F_53 ( V_2 , sizeof( struct V_138 ) ) ;
if ( V_132 < 0 )
return V_132 ;
V_2 -> V_139 = V_81 -> V_135 ;
V_21 = 0 ;
if ( V_81 -> V_140 != 0 ) {
V_21 = V_131 -> V_134 [ 1 ] ;
if ( V_21 ) {
if ( ( ( 1 << V_21 ) & V_81 -> V_140 ) == 0 ) {
F_24
( L_30
L_31 , V_21 ) ;
V_21 = 0 ;
} else {
if ( F_54
( V_21 , F_22 , 0 , L_27 , V_2 ) ) {
F_24
( L_32
L_31 , V_21 ) ;
V_21 = 0 ;
} else {
F_24 ( V_68 L_33 , V_21 ) ;
}
}
}
}
V_2 -> V_21 = V_21 ;
if ( V_21 )
V_31 -> V_61 = 1 ;
else
V_31 -> V_61 = 0 ;
V_31 -> V_62 = 0 ;
V_31 -> V_56 = 0 ;
#ifdef F_40
V_31 -> V_141 = 0 ;
if ( V_131 -> V_134 [ 2 ] > 0 ) {
if ( V_142 == 0 ) {
if ( ! F_52 ( F_55 ( 0 ) , V_143 ,
L_34 ) )
goto V_144;
}
V_31 -> V_145 = F_55 ( 0 ) ;
V_31 -> V_146 = V_143 ;
V_142 ++ ;
#ifdef F_56
if ( ! F_54 ( V_147 , V_148 , 0 ,
L_35 , V_2 ) ) {
V_31 -> V_141 = 1 ;
V_31 -> V_149 = V_147 ;
F_24 ( L_36 , V_31 -> V_149 ) ;
} else {
V_142 -- ;
if ( V_142 == 0 ) {
if ( V_31 -> V_145 )
F_57 ( V_31 -> V_145 ,
V_31 -> V_146 ) ;
}
V_31 -> V_145 = 0 ;
V_31 -> V_146 = 0 ;
}
#else
F_24 ( L_37 ) ;
#endif
}
V_144:
#endif
V_46 = 0 ;
V_31 -> V_46 = V_46 ;
if ( ( V_31 -> V_61 == 0 ) && ( V_31 -> V_141 == 0 ) )
goto V_150;
if ( V_81 -> V_151 != 0 ) {
V_46 = V_131 -> V_134 [ 2 ] ;
if ( V_46 < 1 )
goto V_150;
if ( ( ( 1 << V_46 ) & V_81 -> V_151 ) == 0 ) {
F_24 ( L_38 ) ;
return - V_100 ;
}
V_132 = F_58 ( V_46 , L_27 ) ;
if ( V_132 ) {
F_24 ( V_137
L_39 , V_46 ) ;
return - V_101 ;
}
V_31 -> V_46 = V_46 ;
F_24 ( V_68 L_40 , V_46 ) ;
V_133 = 2 ;
V_31 -> V_53 [ 0 ] = F_59 ( V_152 , V_133 ) ;
if ( ! V_31 -> V_53 [ 0 ] ) {
F_24 ( L_41 ) ;
return - V_101 ;
}
V_31 -> V_153 [ 0 ] = V_133 ;
V_31 -> V_50 [ 0 ] = F_60 ( ( void * ) V_31 -> V_53 [ 0 ] ) ;
V_31 -> V_51 [ 0 ] = ( 1 << V_133 ) * V_154 ;
if ( V_31 -> V_141 == 0 ) {
V_31 -> V_53 [ 1 ] = F_59 ( V_152 , V_133 ) ;
if ( ! V_31 -> V_53 [ 1 ] ) {
F_24 ( V_137
L_42
L_43 ) ;
return - V_101 ;
}
V_31 -> V_153 [ 1 ] = V_133 ;
V_31 -> V_50 [ 1 ] =
F_60 ( ( void * ) V_31 -> V_53 [ 1 ] ) ;
V_31 -> V_51 [ 1 ] = ( 1 << V_133 ) * V_154 ;
}
}
V_150:
V_132 = F_61 ( V_2 , 1 ) ;
if ( V_132 )
return V_132 ;
V_4 = & V_2 -> V_23 [ 0 ] ;
if ( V_81 -> V_155 > 0 ) {
V_4 -> type = V_156 ;
V_31 -> V_157 = V_4 ;
V_2 -> V_158 = V_4 ;
V_4 -> V_159 = V_160 | V_161 ;
V_4 -> V_162 = V_81 -> V_155 ;
V_4 -> V_159 |= V_163 ;
V_4 -> V_164 = V_81 -> V_165 ;
V_4 -> V_166 = V_81 -> V_167 ;
V_4 -> V_168 = V_81 -> V_169 ;
V_4 -> V_170 = F_10 ;
V_4 -> V_171 = F_25 ;
V_4 -> V_172 = F_32 ;
V_4 -> V_173 = F_36 ;
V_4 -> V_174 = F_1 ;
} else {
V_4 -> type = V_175 ;
}
#if 0
case COMEDI_SUBD_AO:
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = board->ao_maxdata;
s->len_chanlist = board->ao_chanlist;
s->range_table = board->ao_range_type;
break;
case COMEDI_SUBD_DI:
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_dichan;
s->maxdata = 1;
s->len_chanlist = board->n_dichan;
s->range_table = &range_digital;
break;
case COMEDI_SUBD_DO:
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_dochan;
s->maxdata = 1;
s->len_chanlist = board->n_dochan;
s->range_table = &range_digital;
break;
#endif
F_44 ( V_2 ) ;
F_24 ( L_44 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
const struct V_80 * V_81 = F_26 ( V_2 ) ;
if ( V_2 -> V_176 ) {
F_10 ( V_2 , V_31 -> V_157 ) ;
F_44 ( V_2 ) ;
if ( V_31 -> V_46 )
F_63 ( V_31 -> V_46 ) ;
if ( V_31 -> V_53 [ 0 ] )
F_64 ( V_31 -> V_53 [ 0 ] , V_31 -> V_153 [ 0 ] ) ;
if ( V_31 -> V_53 [ 1 ] )
F_64 ( V_31 -> V_53 [ 1 ] , V_31 -> V_153 [ 1 ] ) ;
#ifdef F_40
if ( V_31 -> V_149 )
F_65 ( V_31 -> V_149 , V_2 ) ;
if ( ( V_31 -> V_141 ) && ( V_142 == 1 ) ) {
if ( V_31 -> V_145 )
F_57 ( V_31 -> V_145 ,
V_31 -> V_146 ) ;
}
#endif
}
if ( V_2 -> V_21 )
F_65 ( V_2 -> V_21 , V_2 ) ;
if ( V_2 -> V_10 )
F_57 ( V_2 -> V_10 , V_81 -> V_136 ) ;
#ifdef F_40
if ( V_31 -> V_141 )
V_142 -- ;
#endif
}
