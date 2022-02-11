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
struct V_3 * V_4 = V_2 -> V_23 + 0 ;
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
struct V_3 * V_4 = V_2 -> V_23 + 0 ;
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
if ( ( ! V_2 -> V_21 ) | ( ! V_31 -> V_61 ) | ( ! V_31 -> V_62 ) |
( ! V_31 -> V_56 ) ) {
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
int V_80 = 0 ;
int V_81 , V_82 = 0 , V_83 = 0 ;
F_26 (printk(KERN_INFO L_12);
pcl816_cmdtest_out(-1, cmd);
) ;
V_81 = V_67 -> V_69 ;
V_67 -> V_69 &= V_84 ;
if ( ! V_67 -> V_69 || V_81 != V_67 -> V_69 )
V_80 ++ ;
V_81 = V_67 -> V_70 ;
V_67 -> V_70 &= V_85 ;
if ( ! V_67 -> V_70 || V_81 != V_67 -> V_70 )
V_80 ++ ;
V_81 = V_67 -> V_71 ;
V_67 -> V_71 &= V_86 | V_87 ;
if ( ! V_67 -> V_71 || V_81 != V_67 -> V_71 )
V_80 ++ ;
V_81 = V_67 -> V_76 ;
V_67 -> V_76 &= V_88 ;
if ( ! V_67 -> V_76 || V_81 != V_67 -> V_76 )
V_80 ++ ;
V_81 = V_67 -> V_75 ;
V_67 -> V_75 &= V_88 | V_89 ;
if ( ! V_67 -> V_75 || V_81 != V_67 -> V_75 )
V_80 ++ ;
if ( V_80 )
return 1 ;
if ( V_67 -> V_69 != V_84 ) {
V_67 -> V_69 = V_84 ;
V_80 ++ ;
}
if ( V_67 -> V_70 != V_85 ) {
V_67 -> V_70 = V_85 ;
V_80 ++ ;
}
if ( V_67 -> V_71 != V_86 && V_67 -> V_71 != V_87 ) {
V_67 -> V_71 = V_87 ;
V_80 ++ ;
}
if ( V_67 -> V_76 != V_88 ) {
V_67 -> V_76 = V_88 ;
V_80 ++ ;
}
if ( V_67 -> V_75 != V_89 && V_67 -> V_75 != V_88 )
V_80 ++ ;
if ( V_80 )
return 2 ;
if ( V_67 -> V_72 != 0 ) {
V_67 -> V_72 = 0 ;
V_80 ++ ;
}
if ( V_67 -> V_73 != 0 ) {
V_67 -> V_73 = 0 ;
V_80 ++ ;
}
if ( V_67 -> V_71 == V_87 ) {
if ( V_67 -> V_74 < V_90 -> V_91 ) {
V_67 -> V_74 = V_90 -> V_91 ;
V_80 ++ ;
}
} else {
if ( V_67 -> V_74 != 0 ) {
V_67 -> V_74 = 0 ;
V_80 ++ ;
}
}
if ( V_67 -> V_78 != V_67 -> V_79 ) {
V_67 -> V_78 = V_67 -> V_79 ;
V_80 ++ ;
}
if ( V_67 -> V_75 == V_88 ) {
if ( ! V_67 -> V_77 ) {
V_67 -> V_77 = 1 ;
V_80 ++ ;
}
} else {
if ( V_67 -> V_77 != 0 ) {
V_67 -> V_77 = 0 ;
V_80 ++ ;
}
}
if ( V_80 )
return 3 ;
if ( V_67 -> V_71 == V_87 ) {
V_81 = V_67 -> V_74 ;
F_27 ( V_90 -> V_92 ,
& V_82 , & V_83 ,
& V_67 -> V_74 ,
V_67 -> V_93 & V_94 ) ;
if ( V_67 -> V_74 < V_90 -> V_91 )
V_67 -> V_74 = V_90 -> V_91 ;
if ( V_81 != V_67 -> V_74 )
V_80 ++ ;
}
if ( V_80 )
return 4 ;
if ( V_67 -> V_95 ) {
if ( ! F_28 ( V_2 , V_4 , V_67 -> V_95 ,
V_67 -> V_79 ) )
return 5 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_82 = 0 , V_83 = 0 , V_45 , V_96 , V_97 ;
struct V_66 * V_67 = & V_4 -> V_26 -> V_67 ;
unsigned int V_98 ;
if ( V_67 -> V_69 != V_84 )
return - V_99 ;
if ( V_67 -> V_70 != V_85 )
return - V_99 ;
if ( V_67 -> V_76 != V_88 )
return - V_99 ;
if ( V_67 -> V_78 != V_67 -> V_79 )
return - V_99 ;
if ( V_31 -> V_62 )
return - V_100 ;
if ( V_67 -> V_71 == V_87 ) {
if ( V_67 -> V_74 < V_90 -> V_91 )
V_67 -> V_74 = V_90 -> V_91 ;
F_27 ( V_90 -> V_92 , & V_82 ,
& V_83 , & V_67 -> V_74 ,
V_67 -> V_93 & V_94 ) ;
if ( V_82 == 1 ) {
V_82 = 2 ;
V_83 /= 2 ;
}
if ( V_83 == 1 ) {
V_83 = 2 ;
V_82 /= 2 ;
}
}
F_30 ( V_2 , - 1 , 0 , 0 ) ;
V_98 = F_28 ( V_2 , V_4 , V_67 -> V_95 , V_67 -> V_79 ) ;
if ( V_98 < 1 )
return - V_99 ;
F_31 ( V_2 , V_4 , V_67 -> V_95 , V_98 ) ;
F_7 ( 1 ) ;
V_31 -> V_35 = V_67 -> V_79 ;
V_31 -> V_36 = 0 ;
V_4 -> V_26 -> V_34 = 0 ;
V_31 -> V_62 = 1 ;
V_31 -> V_54 = 0 ;
V_31 -> V_63 = 0 ;
if ( V_67 -> V_75 == V_88 ) {
V_31 -> V_38 = V_67 -> V_77 ;
V_31 -> V_37 = 0 ;
} else {
V_31 -> V_38 = 0 ;
V_31 -> V_37 = 1 ;
}
if ( ( V_67 -> V_93 & V_101 ) ) {
F_24 ( V_68
L_13 ) ;
}
if ( V_31 -> V_46 ) {
V_96 = V_31 -> V_51 [ 0 ] ;
if ( ! V_31 -> V_37 ) {
V_96 = V_4 -> V_26 -> V_67 . V_79 *
V_4 -> V_26 -> V_67 . V_79 *
sizeof( short ) ;
V_31 -> V_48 = V_96 /
V_31 -> V_51 [ 0 ] ;
V_31 -> V_52 = V_96 % V_31 -> V_51 [ 0 ] ;
V_31 -> V_48 -- ;
if ( V_31 -> V_48 >= 0 )
V_96 = V_31 -> V_51 [ 0 ] ;
} else
V_31 -> V_48 = - 1 ;
V_31 -> V_47 = 0 ;
F_16 ( V_31 -> V_46 , V_49 ) ;
V_45 = F_17 () ;
F_32 ( V_31 -> V_46 ) ;
F_18 ( V_31 -> V_46 , V_31 -> V_50 [ 0 ] ) ;
F_19 ( V_31 -> V_46 , V_96 ) ;
F_20 ( V_45 ) ;
F_21 ( V_31 -> V_46 ) ;
}
F_30 ( V_2 , 1 , V_82 , V_83 ) ;
V_97 = ( ( V_31 -> V_46 & 0x3 ) << 4 ) | ( V_2 -> V_21 & 0x7 ) ;
switch ( V_67 -> V_71 ) {
case V_87 :
V_31 -> V_56 = V_57 ;
F_3 ( 0x32 , V_2 -> V_10 + V_11 ) ;
F_3 ( V_97 , V_2 -> V_10 + V_17 ) ;
break;
default:
V_31 -> V_56 = V_58 ;
F_3 ( 0x34 , V_2 -> V_10 + V_11 ) ;
F_3 ( V_97 , V_2 -> V_10 + V_17 ) ;
break;
}
F_2 ( L_14 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_93 ;
unsigned int V_102 , V_103 , V_42 ;
if ( ! V_31 -> V_46 )
return 0 ;
F_34 ( & V_2 -> V_104 , V_93 ) ;
for ( V_42 = 0 ; V_42 < 20 ; V_42 ++ ) {
V_102 = F_35 ( V_31 -> V_46 ) ;
V_103 = F_35 ( V_31 -> V_46 ) ;
if ( V_102 == V_103 )
break;
}
if ( V_102 != V_103 ) {
F_36 ( & V_2 -> V_104 , V_93 ) ;
return 0 ;
}
V_102 = V_31 -> V_51 [ 0 ] - V_102 ;
V_102 >>= 1 ;
V_103 = V_102 - V_31 -> V_54 ;
if ( V_103 < 1 ) {
F_36 ( & V_2 -> V_104 , V_93 ) ;
return 0 ;
}
F_13 ( V_2 , V_4 ,
( short * ) V_31 -> V_53 [ V_31 -> V_47 ] ,
V_31 -> V_54 , V_103 ) ;
V_31 -> V_54 = V_102 ;
F_36 ( & V_2 -> V_104 , V_93 ) ;
return V_4 -> V_26 -> V_105 - V_4 -> V_26 -> V_106 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_31 -> V_62 > 0 ) {
switch ( V_31 -> V_56 ) {
#ifdef F_37
case V_107 :
case V_108 :
F_38 ( 0 ) ;
F_39 ( & V_31 -> V_109 ) ;
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
F_3 ( 0xb0 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0x70 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0 , V_2 -> V_10 + V_16 ) ;
F_6 ( V_2 -> V_10 + V_16 ) ;
F_6 ( V_2 -> V_10 + V_19 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
F_3 ( 0 , V_2 -> V_10 + V_11 ) ;
V_31 -> V_62 = 0 ;
V_31 -> V_63 = V_31 -> V_56 ;
V_31 -> V_56 = 0 ;
V_31 -> V_111 = V_4 ;
break;
}
}
F_26 (printk(L_15);)
return 0 ;
}
static int F_40 ( unsigned long V_10 )
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
static void F_41 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_10 + V_11 ) ;
F_3 ( 0 , V_2 -> V_10 + V_14 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
F_3 ( 0xb0 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0x70 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0x30 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0 , V_2 -> V_10 + V_15 ) ;
}
static void
F_30 ( struct V_1 * V_2 , int V_112 , unsigned int V_82 ,
unsigned int V_83 )
{
F_3 ( 0x32 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0xff , V_2 -> V_10 + V_113 ) ;
F_3 ( 0x00 , V_2 -> V_10 + V_113 ) ;
F_7 ( 1 ) ;
F_3 ( 0xb4 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0x74 , V_2 -> V_10 + V_110 ) ;
F_7 ( 1 ) ;
if ( V_112 == 1 ) {
F_2 ( L_16 , V_112 , V_82 ,
V_83 ) ;
F_3 ( V_83 & 0xff , V_2 -> V_10 + V_114 ) ;
F_3 ( ( V_83 >> 8 ) & 0xff , V_2 -> V_10 + V_114 ) ;
F_3 ( V_82 & 0xff , V_2 -> V_10 + V_115 ) ;
F_3 ( ( V_82 >> 8 ) & 0xff , V_2 -> V_10 + V_115 ) ;
}
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_95 ,
unsigned int V_116 )
{
unsigned int V_117 [ 16 ] ;
unsigned int V_42 , V_118 , V_98 , V_119 ;
if ( V_116 < 1 ) {
F_8 ( V_2 , L_17 ) ;
return 0 ;
}
if ( V_116 > 1 ) {
V_117 [ 0 ] = V_95 [ 0 ] ;
for ( V_42 = 1 , V_98 = 1 ; V_42 < V_116 ; V_42 ++ , V_98 ++ ) {
F_26 (printk(KERN_INFO L_18, i,
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_95 [ 0 ] == V_95 [ V_42 ] )
break;
V_118 =
( F_4 ( V_117 [ V_42 - 1 ] ) + 1 ) % V_116 ;
if ( V_118 != F_4 ( V_95 [ V_42 ] ) ) {
F_24 ( V_120
L_19
L_20
L_21 , V_2 -> V_121 ,
V_42 , F_4 ( V_95 [ V_42 ] ) , V_118 ,
F_4 ( V_95 [ 0 ] ) ) ;
return 0 ;
}
V_117 [ V_42 ] = V_95 [ V_42 ] ;
}
for ( V_42 = 0 , V_119 = 0 ; V_42 < V_116 ; V_42 ++ ) {
F_26 (printk(L_22,
CR_CHAN(chansegment[i % seglen]),
CR_RANGE(chansegment[i % seglen]),
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_95 [ V_42 ] != V_117 [ V_42 % V_98 ] ) {
F_24 ( V_120
L_23
L_24
L_25 , V_2 -> V_121 , V_42 ,
F_4 ( V_117 [ V_42 ] ) ,
F_5 ( V_117 [ V_42 ] ) ,
F_42 ( V_117 [ V_42 ] ) ,
F_4 ( V_95 [ V_42 % V_98 ] ) ,
F_5 ( V_95 [ V_42 % V_98 ] ) ,
F_42 ( V_117 [ V_42 % V_98 ] ) ) ;
return 0 ;
}
}
} else {
V_98 = 1 ;
}
return V_98 ;
}
static void
F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_95 ,
unsigned int V_98 )
{
unsigned int V_42 ;
V_31 -> V_33 = V_98 ;
V_31 -> V_32 = 0 ;
for ( V_42 = 0 ; V_42 < V_98 ; V_42 ++ ) {
V_31 -> V_122 [ V_42 ] = F_4 ( V_95 [ V_42 ] ) ;
F_3 ( F_4 ( V_95 [ 0 ] ) & 0xf , V_2 -> V_10 + V_14 ) ;
F_3 ( F_5 ( V_95 [ 0 ] ) , V_2 -> V_10 + V_15 ) ;
}
F_7 ( 1 ) ;
F_3 ( V_31 -> V_122 [ 0 ] |
( V_31 -> V_122 [ V_98 - 1 ] << 4 ) ,
V_2 -> V_10 + V_14 ) ;
}
static int F_38 ( unsigned char V_123 )
{
unsigned char V_124 ;
unsigned long V_93 ;
if ( V_123 == 1 ) {
V_125 ++ ;
if ( V_125 > 1 )
return 0 ;
} else {
V_125 -- ;
if ( V_125 < 0 )
V_125 = 0 ;
if ( V_125 > 0 )
return 0 ;
}
F_43 ( V_93 ) ;
F_44 () ;
V_124 = F_45 ( V_126 ) ;
if ( V_123 )
V_124 |= V_127 ;
else
V_124 &= ~ V_127 ;
F_46 ( V_124 , V_126 ) ;
F_45 ( V_128 ) ;
F_47 ( V_93 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
int V_131 ;
unsigned long V_10 ;
unsigned int V_21 , V_46 ;
unsigned long V_132 ;
struct V_3 * V_4 ;
V_10 = V_130 -> V_133 [ 0 ] ;
F_24 ( L_26 , V_2 -> V_121 ,
V_90 -> V_134 , V_10 ) ;
if ( ! F_49 ( V_10 , V_90 -> V_135 , L_27 ) ) {
F_24 ( L_28 ) ;
return - V_20 ;
}
V_2 -> V_10 = V_10 ;
if ( F_40 ( V_10 ) ) {
F_24 ( V_136 L_29 ) ;
return - V_20 ;
}
V_131 = F_50 ( V_2 , sizeof( struct V_137 ) ) ;
if ( V_131 < 0 )
return V_131 ;
V_2 -> V_138 = V_90 -> V_134 ;
V_21 = 0 ;
if ( V_90 -> V_139 != 0 ) {
V_21 = V_130 -> V_133 [ 1 ] ;
if ( V_21 ) {
if ( ( ( 1 << V_21 ) & V_90 -> V_139 ) == 0 ) {
F_24
( L_30
L_31 , V_21 ) ;
V_21 = 0 ;
} else {
if ( F_51
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
#ifdef F_37
V_31 -> V_140 = 0 ;
if ( V_130 -> V_133 [ 2 ] > 0 ) {
if ( V_141 == 0 ) {
if ( ! F_49 ( F_52 ( 0 ) , V_142 ,
L_34 ) )
goto V_143;
}
V_31 -> V_144 = F_52 ( 0 ) ;
V_31 -> V_145 = V_142 ;
V_141 ++ ;
#ifdef F_53
if ( ! F_51 ( V_146 , V_147 , 0 ,
L_35 , V_2 ) ) {
V_31 -> V_140 = 1 ;
V_31 -> V_148 = V_146 ;
F_24 ( L_36 , V_31 -> V_148 ) ;
} else {
V_141 -- ;
if ( V_141 == 0 ) {
if ( V_31 -> V_144 )
F_54 ( V_31 -> V_144 ,
V_31 -> V_145 ) ;
}
V_31 -> V_144 = 0 ;
V_31 -> V_145 = 0 ;
}
#else
F_24 ( L_37 ) ;
#endif
}
V_143:
#endif
V_46 = 0 ;
V_31 -> V_46 = V_46 ;
if ( ( V_31 -> V_61 == 0 ) && ( V_31 -> V_140 == 0 ) )
goto V_149;
if ( V_90 -> V_150 != 0 ) {
V_46 = V_130 -> V_133 [ 2 ] ;
if ( V_46 < 1 )
goto V_149;
if ( ( ( 1 << V_46 ) & V_90 -> V_150 ) == 0 ) {
F_24 ( L_38 ) ;
return - V_99 ;
}
V_131 = F_55 ( V_46 , L_27 ) ;
if ( V_131 ) {
F_24 ( V_136
L_39 , V_46 ) ;
return - V_100 ;
}
V_31 -> V_46 = V_46 ;
F_24 ( V_68 L_40 , V_46 ) ;
V_132 = 2 ;
V_31 -> V_53 [ 0 ] = F_56 ( V_151 , V_132 ) ;
if ( ! V_31 -> V_53 [ 0 ] ) {
F_24 ( L_41 ) ;
return - V_100 ;
}
V_31 -> V_152 [ 0 ] = V_132 ;
V_31 -> V_50 [ 0 ] = F_57 ( ( void * ) V_31 -> V_53 [ 0 ] ) ;
V_31 -> V_51 [ 0 ] = ( 1 << V_132 ) * V_153 ;
if ( V_31 -> V_140 == 0 ) {
V_31 -> V_53 [ 1 ] = F_56 ( V_151 , V_132 ) ;
if ( ! V_31 -> V_53 [ 1 ] ) {
F_24 ( V_136
L_42
L_43 ) ;
return - V_100 ;
}
V_31 -> V_152 [ 1 ] = V_132 ;
V_31 -> V_50 [ 1 ] =
F_57 ( ( void * ) V_31 -> V_53 [ 1 ] ) ;
V_31 -> V_51 [ 1 ] = ( 1 << V_132 ) * V_153 ;
}
}
V_149:
V_131 = F_58 ( V_2 , 1 ) ;
if ( V_131 < 0 )
return V_131 ;
V_4 = V_2 -> V_23 + 0 ;
if ( V_90 -> V_154 > 0 ) {
V_4 -> type = V_155 ;
V_31 -> V_156 = V_4 ;
V_2 -> V_157 = V_4 ;
V_4 -> V_158 = V_159 | V_160 ;
V_4 -> V_161 = V_90 -> V_154 ;
V_4 -> V_158 |= V_162 ;
V_4 -> V_163 = V_90 -> V_164 ;
V_4 -> V_165 = V_90 -> V_166 ;
V_4 -> V_167 = V_90 -> V_168 ;
V_4 -> V_169 = F_10 ;
V_4 -> V_170 = F_25 ;
V_4 -> V_171 = F_29 ;
V_4 -> V_172 = F_33 ;
V_4 -> V_173 = F_1 ;
} else {
V_4 -> type = V_174 ;
}
#if 0
case COMEDI_SUBD_AO:
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = this_board->n_aochan;
s->maxdata = this_board->ao_maxdata;
s->len_chanlist = this_board->ao_chanlist;
s->range_table = this_board->ao_range_type;
break;
case COMEDI_SUBD_DI:
s->subdev_flags = SDF_READABLE;
s->n_chan = this_board->n_dichan;
s->maxdata = 1;
s->len_chanlist = this_board->n_dichan;
s->range_table = &range_digital;
break;
case COMEDI_SUBD_DO:
s->subdev_flags = SDF_WRITABLE;
s->n_chan = this_board->n_dochan;
s->maxdata = 1;
s->len_chanlist = this_board->n_dochan;
s->range_table = &range_digital;
break;
#endif
F_41 ( V_2 ) ;
F_24 ( L_44 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_175 ) {
F_10 ( V_2 , V_31 -> V_156 ) ;
F_41 ( V_2 ) ;
if ( V_31 -> V_46 )
F_60 ( V_31 -> V_46 ) ;
if ( V_31 -> V_53 [ 0 ] )
F_61 ( V_31 -> V_53 [ 0 ] , V_31 -> V_152 [ 0 ] ) ;
if ( V_31 -> V_53 [ 1 ] )
F_61 ( V_31 -> V_53 [ 1 ] , V_31 -> V_152 [ 1 ] ) ;
#ifdef F_37
if ( V_31 -> V_148 )
F_62 ( V_31 -> V_148 , V_2 ) ;
if ( ( V_31 -> V_140 ) && ( V_141 == 1 ) ) {
if ( V_31 -> V_144 )
F_54 ( V_31 -> V_144 ,
V_31 -> V_145 ) ;
}
#endif
}
if ( V_2 -> V_21 )
F_62 ( V_2 -> V_21 , V_2 ) ;
if ( V_2 -> V_10 )
F_54 ( V_2 -> V_10 , V_90 -> V_135 ) ;
#ifdef F_37
if ( V_31 -> V_140 )
V_141 -- ;
#endif
}
