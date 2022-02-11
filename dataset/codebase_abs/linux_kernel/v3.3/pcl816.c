static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
int V_10 ;
F_6 ( L_1 ) ;
F_7 ( 0 , V_3 -> V_11 + V_12 ) ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
F_7 ( F_8 ( V_7 -> V_14 ) & 0xf , V_3 -> V_11 + V_15 ) ;
F_7 ( F_9 ( V_7 -> V_14 ) , V_3 -> V_11 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ ) {
F_7 ( 0 , V_3 -> V_11 + V_17 ) ;
V_10 = 100 ;
while ( V_10 -- ) {
if ( ! ( F_10 ( V_3 -> V_11 + V_18 ) &
V_19 ) ) {
V_8 [ V_9 ] =
( ( F_10 ( V_3 -> V_11 +
V_20 ) << 8 ) |
( F_10 ( V_3 -> V_11 + V_17 ) ) ) ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
break;
}
F_11 ( 1 ) ;
}
if ( ! V_10 ) {
F_12 ( V_3 , L_2 ) ;
V_8 [ 0 ] = 0 ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
return - V_21 ;
}
}
return V_9 ;
}
static T_3 F_13 ( int V_22 , void * V_23 )
{
struct V_2 * V_3 = V_23 ;
struct V_4 * V_5 = V_3 -> V_24 + 0 ;
int V_25 , V_26 ;
int V_10 = 50 ;
while ( V_10 -- ) {
if ( ! ( F_10 ( V_3 -> V_11 + V_18 ) &
V_19 ) )
break;
F_11 ( 1 ) ;
}
if ( ! V_10 ) {
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
F_12 ( V_3 , L_3 ) ;
F_14 ( V_3 , V_5 ) ;
V_5 -> V_27 -> V_28 |= V_29 | V_30 ;
F_15 ( V_3 , V_5 ) ;
return V_31 ;
}
V_25 = F_10 ( V_3 -> V_11 + V_17 ) ;
V_26 = F_10 ( V_3 -> V_11 + V_20 ) ;
F_16 ( V_5 -> V_27 , ( V_26 << 8 ) | V_25 ) ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
if ( ++ V_32 -> V_33 >= V_32 -> V_34 )
V_32 -> V_33 = 0 ;
V_5 -> V_27 -> V_35 ++ ;
if ( V_5 -> V_27 -> V_35 >= V_32 -> V_36 ) {
V_5 -> V_27 -> V_35 = 0 ;
V_32 -> V_37 ++ ;
}
if ( ! V_32 -> V_38 )
if ( V_32 -> V_37 >= V_32 -> V_39 ) {
F_14 ( V_3 , V_5 ) ;
V_5 -> V_27 -> V_28 |= V_29 ;
}
F_15 ( V_3 , V_5 ) ;
return V_31 ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 , short * V_40 ,
unsigned int V_41 , unsigned int V_42 )
{
int V_43 ;
V_5 -> V_27 -> V_28 = 0 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
F_16 ( V_5 -> V_27 , V_40 [ V_41 ++ ] ) ;
if ( ++ V_32 -> V_33 >=
V_32 -> V_34 ) {
V_32 -> V_33 = 0 ;
}
V_5 -> V_27 -> V_35 ++ ;
if ( V_5 -> V_27 -> V_35 >= V_32 -> V_36 ) {
V_5 -> V_27 -> V_35 = 0 ;
V_32 -> V_37 ++ ;
}
if ( ! V_32 -> V_38 )
if ( V_32 -> V_37 >= V_32 -> V_39 ) {
F_14 ( V_3 , V_5 ) ;
V_5 -> V_27 -> V_28 |= V_29 ;
V_5 -> V_27 -> V_28 |= V_44 ;
break;
}
}
F_15 ( V_3 , V_5 ) ;
}
static T_3 F_18 ( int V_22 , void * V_23 )
{
struct V_2 * V_3 = V_23 ;
struct V_4 * V_5 = V_3 -> V_24 + 0 ;
int V_42 , V_41 , V_45 ;
unsigned long V_46 ;
short * V_40 ;
F_19 ( V_32 -> V_47 ) ;
V_45 = V_32 -> V_48 ;
if ( ( V_32 -> V_49 > - 1 ) || V_32 -> V_38 ) {
V_32 -> V_48 = 1 - V_32 -> V_48 ;
F_20 ( V_32 -> V_47 , V_50 ) ;
V_46 = F_21 () ;
F_22 ( V_32 -> V_47 ,
V_32 -> V_51 [ V_32 -> V_48 ] ) ;
if ( V_32 -> V_49 ) {
F_23 ( V_32 -> V_47 ,
V_32 -> V_52 [ V_32 ->
V_48 ] ) ;
} else {
F_23 ( V_32 -> V_47 , V_32 -> V_53 ) ;
}
F_24 ( V_46 ) ;
F_25 ( V_32 -> V_47 ) ;
}
V_32 -> V_49 -- ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
V_40 = ( short * ) V_32 -> V_54 [ V_45 ] ;
V_42 = ( V_32 -> V_52 [ 0 ] >> 1 ) - V_32 -> V_55 ;
V_41 = V_32 -> V_55 ;
V_32 -> V_55 = 0 ;
F_17 ( V_3 , V_5 , V_40 , V_41 , V_42 ) ;
return V_31 ;
}
static T_3 F_26 ( int V_22 , void * V_23 )
{
struct V_2 * V_3 = V_23 ;
F_6 ( L_4 ) ;
if ( ! V_3 -> V_56 ) {
F_12 ( V_3 , L_5 ) ;
return V_31 ;
}
switch ( V_32 -> V_57 ) {
case V_58 :
case V_59 :
return F_18 ( V_22 , V_23 ) ;
case V_60 :
case V_61 :
return F_13 ( V_22 , V_23 ) ;
}
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
if ( ( ! V_3 -> V_22 ) | ( ! V_32 -> V_62 ) | ( ! V_32 -> V_63 ) |
( ! V_32 -> V_57 ) ) {
if ( V_32 -> V_64 ) {
V_32 -> V_64 = 0 ;
return V_31 ;
}
F_12 ( V_3 , L_6 ) ;
return V_65 ;
}
F_12 ( V_3 , L_7 ) ;
return V_65 ;
}
static void F_27 ( int V_66 , struct V_67 * V_68 )
{
F_28 ( V_69 L_8 , V_66 ,
V_68 -> V_70 , V_68 -> V_71 , V_68 -> V_72 ) ;
F_28 ( V_69 L_9 , V_66 ,
V_68 -> V_73 , V_68 -> V_74 , V_68 -> V_75 ) ;
F_28 ( V_69 L_10 , V_66 ,
V_68 -> V_76 , V_68 -> V_77 ) ;
F_28 ( V_69 L_11 ,
V_66 , V_68 -> V_78 , V_68 -> V_79 , V_68 -> V_80 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_67 * V_68 )
{
int V_81 = 0 ;
int V_82 , V_83 = 0 , V_84 = 0 ;
F_30 (printk(KERN_INFO L_12);
pcl816_cmdtest_out(-1, cmd);
) ;
V_82 = V_68 -> V_70 ;
V_68 -> V_70 &= V_85 ;
if ( ! V_68 -> V_70 || V_82 != V_68 -> V_70 )
V_81 ++ ;
V_82 = V_68 -> V_71 ;
V_68 -> V_71 &= V_86 ;
if ( ! V_68 -> V_71 || V_82 != V_68 -> V_71 )
V_81 ++ ;
V_82 = V_68 -> V_72 ;
V_68 -> V_72 &= V_87 | V_88 ;
if ( ! V_68 -> V_72 || V_82 != V_68 -> V_72 )
V_81 ++ ;
V_82 = V_68 -> V_77 ;
V_68 -> V_77 &= V_89 ;
if ( ! V_68 -> V_77 || V_82 != V_68 -> V_77 )
V_81 ++ ;
V_82 = V_68 -> V_76 ;
V_68 -> V_76 &= V_89 | V_90 ;
if ( ! V_68 -> V_76 || V_82 != V_68 -> V_76 )
V_81 ++ ;
if ( V_81 )
return 1 ;
if ( V_68 -> V_70 != V_85 ) {
V_68 -> V_70 = V_85 ;
V_81 ++ ;
}
if ( V_68 -> V_71 != V_86 ) {
V_68 -> V_71 = V_86 ;
V_81 ++ ;
}
if ( V_68 -> V_72 != V_87 && V_68 -> V_72 != V_88 ) {
V_68 -> V_72 = V_88 ;
V_81 ++ ;
}
if ( V_68 -> V_77 != V_89 ) {
V_68 -> V_77 = V_89 ;
V_81 ++ ;
}
if ( V_68 -> V_76 != V_90 && V_68 -> V_76 != V_89 )
V_81 ++ ;
if ( V_81 )
return 2 ;
if ( V_68 -> V_73 != 0 ) {
V_68 -> V_73 = 0 ;
V_81 ++ ;
}
if ( V_68 -> V_74 != 0 ) {
V_68 -> V_74 = 0 ;
V_81 ++ ;
}
if ( V_68 -> V_72 == V_88 ) {
if ( V_68 -> V_75 < V_91 -> V_92 ) {
V_68 -> V_75 = V_91 -> V_92 ;
V_81 ++ ;
}
} else {
if ( V_68 -> V_75 != 0 ) {
V_68 -> V_75 = 0 ;
V_81 ++ ;
}
}
if ( V_68 -> V_79 != V_68 -> V_80 ) {
V_68 -> V_79 = V_68 -> V_80 ;
V_81 ++ ;
}
if ( V_68 -> V_76 == V_89 ) {
if ( ! V_68 -> V_78 ) {
V_68 -> V_78 = 1 ;
V_81 ++ ;
}
} else {
if ( V_68 -> V_78 != 0 ) {
V_68 -> V_78 = 0 ;
V_81 ++ ;
}
}
if ( V_81 )
return 3 ;
if ( V_68 -> V_72 == V_88 ) {
V_82 = V_68 -> V_75 ;
F_31 ( V_91 -> V_93 ,
& V_83 , & V_84 ,
& V_68 -> V_75 ,
V_68 -> V_94 & V_95 ) ;
if ( V_68 -> V_75 < V_91 -> V_92 )
V_68 -> V_75 = V_91 -> V_92 ;
if ( V_82 != V_68 -> V_75 )
V_81 ++ ;
}
if ( V_81 )
return 4 ;
if ( V_68 -> V_96 ) {
if ( ! F_32 ( V_3 , V_5 , V_68 -> V_96 ,
V_68 -> V_80 ) )
return 5 ;
}
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned int V_83 = 0 , V_84 = 0 , V_46 , V_97 , V_98 ;
struct V_67 * V_68 = & V_5 -> V_27 -> V_68 ;
unsigned int V_99 ;
if ( V_68 -> V_70 != V_85 )
return - V_100 ;
if ( V_68 -> V_71 != V_86 )
return - V_100 ;
if ( V_68 -> V_77 != V_89 )
return - V_100 ;
if ( V_68 -> V_79 != V_68 -> V_80 )
return - V_100 ;
if ( V_32 -> V_63 )
return - V_101 ;
if ( V_68 -> V_72 == V_88 ) {
if ( V_68 -> V_75 < V_91 -> V_92 )
V_68 -> V_75 = V_91 -> V_92 ;
F_31 ( V_91 -> V_93 , & V_83 ,
& V_84 , & V_68 -> V_75 ,
V_68 -> V_94 & V_95 ) ;
if ( V_83 == 1 ) {
V_83 = 2 ;
V_84 /= 2 ;
}
if ( V_84 == 1 ) {
V_84 = 2 ;
V_83 /= 2 ;
}
}
F_34 ( V_3 , - 1 , 0 , 0 ) ;
V_99 = F_32 ( V_3 , V_5 , V_68 -> V_96 , V_68 -> V_80 ) ;
if ( V_99 < 1 )
return - V_100 ;
F_35 ( V_3 , V_5 , V_68 -> V_96 , V_99 ) ;
F_11 ( 1 ) ;
V_32 -> V_36 = V_68 -> V_80 ;
V_32 -> V_37 = 0 ;
V_5 -> V_27 -> V_35 = 0 ;
V_32 -> V_63 = 1 ;
V_32 -> V_55 = 0 ;
V_32 -> V_64 = 0 ;
if ( V_68 -> V_76 == V_89 ) {
V_32 -> V_39 = V_68 -> V_78 ;
V_32 -> V_38 = 0 ;
} else {
V_32 -> V_39 = 0 ;
V_32 -> V_38 = 1 ;
}
if ( ( V_68 -> V_94 & V_102 ) ) {
F_28 ( V_69
L_13 ) ;
}
if ( V_32 -> V_47 ) {
V_97 = V_32 -> V_52 [ 0 ] ;
if ( ! V_32 -> V_38 ) {
V_97 = V_5 -> V_27 -> V_68 . V_80 *
V_5 -> V_27 -> V_68 . V_80 *
sizeof( short ) ;
V_32 -> V_49 = V_97 /
V_32 -> V_52 [ 0 ] ;
V_32 -> V_53 = V_97 % V_32 -> V_52 [ 0 ] ;
V_32 -> V_49 -- ;
if ( V_32 -> V_49 >= 0 )
V_97 = V_32 -> V_52 [ 0 ] ;
} else
V_32 -> V_49 = - 1 ;
V_32 -> V_48 = 0 ;
F_20 ( V_32 -> V_47 , V_50 ) ;
V_46 = F_21 () ;
F_36 ( V_32 -> V_47 ) ;
F_22 ( V_32 -> V_47 , V_32 -> V_51 [ 0 ] ) ;
F_23 ( V_32 -> V_47 , V_97 ) ;
F_24 ( V_46 ) ;
F_25 ( V_32 -> V_47 ) ;
}
F_34 ( V_3 , 1 , V_83 , V_84 ) ;
V_98 = ( ( V_32 -> V_47 & 0x3 ) << 4 ) | ( V_3 -> V_22 & 0x7 ) ;
switch ( V_68 -> V_72 ) {
case V_88 :
V_32 -> V_57 = V_58 ;
F_7 ( 0x32 , V_3 -> V_11 + V_12 ) ;
F_7 ( V_98 , V_3 -> V_11 + V_18 ) ;
break;
default:
V_32 -> V_57 = V_59 ;
F_7 ( 0x34 , V_3 -> V_11 + V_12 ) ;
F_7 ( V_98 , V_3 -> V_11 + V_18 ) ;
break;
}
F_6 ( L_14 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_94 ;
unsigned int V_103 , V_104 , V_43 ;
if ( ! V_32 -> V_47 )
return 0 ;
F_38 ( & V_3 -> V_105 , V_94 ) ;
for ( V_43 = 0 ; V_43 < 20 ; V_43 ++ ) {
V_103 = F_39 ( V_32 -> V_47 ) ;
V_104 = F_39 ( V_32 -> V_47 ) ;
if ( V_103 == V_104 )
break;
}
if ( V_103 != V_104 ) {
F_40 ( & V_3 -> V_105 , V_94 ) ;
return 0 ;
}
V_103 = V_32 -> V_52 [ 0 ] - V_103 ;
V_103 >>= 1 ;
V_104 = V_103 - V_32 -> V_55 ;
if ( V_104 < 1 ) {
F_40 ( & V_3 -> V_105 , V_94 ) ;
return 0 ;
}
F_17 ( V_3 , V_5 ,
( short * ) V_32 -> V_54 [ V_32 -> V_48 ] ,
V_32 -> V_55 , V_104 ) ;
V_32 -> V_55 = V_103 ;
F_40 ( & V_3 -> V_105 , V_94 ) ;
return V_5 -> V_27 -> V_106 - V_5 -> V_27 -> V_107 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( V_32 -> V_63 > 0 ) {
switch ( V_32 -> V_57 ) {
#ifdef F_41
case V_108 :
case V_109 :
F_42 ( 0 ) ;
F_43 ( & V_32 -> V_110 ) ;
#endif
case V_58 :
case V_59 :
F_19 ( V_32 -> V_47 ) ;
case V_60 :
case V_61 :
F_7 ( F_10 ( V_3 -> V_11 + V_12 ) & 0x73 ,
V_3 -> V_11 + V_12 ) ;
F_11 ( 1 ) ;
F_7 ( 0 , V_3 -> V_11 + V_12 ) ;
F_7 ( 0xb0 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0x70 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0 , V_3 -> V_11 + V_17 ) ;
F_10 ( V_3 -> V_11 + V_17 ) ;
F_10 ( V_3 -> V_11 + V_20 ) ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
F_7 ( 0 , V_3 -> V_11 + V_12 ) ;
V_32 -> V_63 = 0 ;
V_32 -> V_64 = V_32 -> V_57 ;
V_32 -> V_57 = 0 ;
V_32 -> V_112 = V_5 ;
break;
}
}
F_30 (printk(L_15);)
return 0 ;
}
static int F_44 ( unsigned long V_11 )
{
F_7 ( 0x00 , V_11 + V_15 ) ;
F_11 ( 1 ) ;
if ( F_10 ( V_11 + V_15 ) != 0x00 )
return 1 ;
F_7 ( 0x55 , V_11 + V_15 ) ;
F_11 ( 1 ) ;
if ( F_10 ( V_11 + V_15 ) != 0x55 )
return 1 ;
F_7 ( 0x00 , V_11 + V_15 ) ;
F_11 ( 1 ) ;
F_7 ( 0x18 , V_11 + V_12 ) ;
F_11 ( 1 ) ;
if ( F_10 ( V_11 + V_12 ) != 0x18 )
return 1 ;
return 0 ;
}
static void F_45 ( struct V_2 * V_3 )
{
F_7 ( 0 , V_3 -> V_11 + V_12 ) ;
F_7 ( 0 , V_3 -> V_11 + V_15 ) ;
F_7 ( 0 , V_3 -> V_11 + V_13 ) ;
F_7 ( 0xb0 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0x70 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0x30 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0 , V_3 -> V_11 + V_16 ) ;
}
static void
F_34 ( struct V_2 * V_3 , int V_113 , unsigned int V_83 ,
unsigned int V_84 )
{
F_7 ( 0x32 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0xff , V_3 -> V_11 + V_114 ) ;
F_7 ( 0x00 , V_3 -> V_11 + V_114 ) ;
F_11 ( 1 ) ;
F_7 ( 0xb4 , V_3 -> V_11 + V_111 ) ;
F_7 ( 0x74 , V_3 -> V_11 + V_111 ) ;
F_11 ( 1 ) ;
if ( V_113 == 1 ) {
F_6 ( L_16 , V_113 , V_83 ,
V_84 ) ;
F_7 ( V_84 & 0xff , V_3 -> V_11 + V_115 ) ;
F_7 ( ( V_84 >> 8 ) & 0xff , V_3 -> V_11 + V_115 ) ;
F_7 ( V_83 & 0xff , V_3 -> V_11 + V_116 ) ;
F_7 ( ( V_83 >> 8 ) & 0xff , V_3 -> V_11 + V_116 ) ;
}
}
static int
F_32 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int * V_96 ,
unsigned int V_117 )
{
unsigned int V_118 [ 16 ] ;
unsigned int V_43 , V_119 , V_99 , V_120 ;
if ( V_117 < 1 ) {
F_12 ( V_3 , L_17 ) ;
return 0 ;
}
if ( V_117 > 1 ) {
V_118 [ 0 ] = V_96 [ 0 ] ;
for ( V_43 = 1 , V_99 = 1 ; V_43 < V_117 ; V_43 ++ , V_99 ++ ) {
F_30 (printk(KERN_INFO L_18, i,
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_96 [ 0 ] == V_96 [ V_43 ] )
break;
V_119 =
( F_8 ( V_118 [ V_43 - 1 ] ) + 1 ) % V_117 ;
if ( V_119 != F_8 ( V_96 [ V_43 ] ) ) {
F_28 ( V_121
L_19
L_20
L_21 , V_3 -> V_122 ,
V_43 , F_8 ( V_96 [ V_43 ] ) , V_119 ,
F_8 ( V_96 [ 0 ] ) ) ;
return 0 ;
}
V_118 [ V_43 ] = V_96 [ V_43 ] ;
}
for ( V_43 = 0 , V_120 = 0 ; V_43 < V_117 ; V_43 ++ ) {
F_30 (printk(L_22,
CR_CHAN(chansegment[i % seglen]),
CR_RANGE(chansegment[i % seglen]),
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_96 [ V_43 ] != V_118 [ V_43 % V_99 ] ) {
F_28 ( V_121
L_23
L_24
L_25 , V_3 -> V_122 , V_43 ,
F_8 ( V_118 [ V_43 ] ) ,
F_9 ( V_118 [ V_43 ] ) ,
F_46 ( V_118 [ V_43 ] ) ,
F_8 ( V_96 [ V_43 % V_99 ] ) ,
F_9 ( V_96 [ V_43 % V_99 ] ) ,
F_46 ( V_118 [ V_43 % V_99 ] ) ) ;
return 0 ;
}
}
} else {
V_99 = 1 ;
}
return V_99 ;
}
static void
F_35 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int * V_96 ,
unsigned int V_99 )
{
unsigned int V_43 ;
V_32 -> V_34 = V_99 ;
V_32 -> V_33 = 0 ;
for ( V_43 = 0 ; V_43 < V_99 ; V_43 ++ ) {
V_32 -> V_123 [ V_43 ] = F_8 ( V_96 [ V_43 ] ) ;
F_7 ( F_8 ( V_96 [ 0 ] ) & 0xf , V_3 -> V_11 + V_15 ) ;
F_7 ( F_9 ( V_96 [ 0 ] ) , V_3 -> V_11 + V_16 ) ;
}
F_11 ( 1 ) ;
F_7 ( V_32 -> V_123 [ 0 ] |
( V_32 -> V_123 [ V_99 - 1 ] << 4 ) ,
V_3 -> V_11 + V_15 ) ;
}
static int F_42 ( unsigned char V_124 )
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
F_47 ( V_94 ) ;
F_48 () ;
V_125 = F_49 ( V_127 ) ;
if ( V_124 )
V_125 |= V_128 ;
else
V_125 &= ~ V_128 ;
F_50 ( V_125 , V_127 ) ;
F_49 ( V_129 ) ;
F_51 ( V_94 ) ;
return 0 ;
}
static void F_52 ( struct V_2 * V_3 )
{
if ( V_3 -> V_130 ) {
F_14 ( V_3 , V_32 -> V_131 ) ;
F_45 ( V_3 ) ;
if ( V_32 -> V_47 )
F_53 ( V_32 -> V_47 ) ;
if ( V_32 -> V_54 [ 0 ] )
F_54 ( V_32 -> V_54 [ 0 ] , V_32 -> V_132 [ 0 ] ) ;
if ( V_32 -> V_54 [ 1 ] )
F_54 ( V_32 -> V_54 [ 1 ] , V_32 -> V_132 [ 1 ] ) ;
#ifdef F_41
if ( V_32 -> V_133 )
F_55 ( V_32 -> V_133 , V_3 ) ;
if ( ( V_32 -> V_134 ) && ( V_135 == 1 ) ) {
if ( V_32 -> V_136 )
F_56 ( V_32 -> V_136 ,
V_32 -> V_137 ) ;
}
#endif
}
if ( V_3 -> V_22 )
F_55 ( V_3 -> V_22 , V_3 ) ;
if ( V_3 -> V_11 )
F_56 ( V_3 -> V_11 , V_91 -> V_138 ) ;
}
static int F_57 ( struct V_2 * V_3 , struct V_139 * V_140 )
{
int V_141 ;
unsigned long V_11 ;
unsigned int V_22 , V_47 ;
unsigned long V_142 ;
struct V_4 * V_5 ;
V_11 = V_140 -> V_143 [ 0 ] ;
F_28 ( L_26 , V_3 -> V_122 ,
V_91 -> V_144 , V_11 ) ;
if ( ! F_58 ( V_11 , V_91 -> V_138 , L_27 ) ) {
F_28 ( L_28 ) ;
return - V_21 ;
}
V_3 -> V_11 = V_11 ;
if ( F_44 ( V_11 ) ) {
F_28 ( V_145 L_29 ) ;
return - V_21 ;
}
V_141 = F_59 ( V_3 , sizeof( struct V_146 ) ) ;
if ( V_141 < 0 )
return V_141 ;
V_3 -> V_147 = V_91 -> V_144 ;
V_22 = 0 ;
if ( V_91 -> V_148 != 0 ) {
V_22 = V_140 -> V_143 [ 1 ] ;
if ( V_22 ) {
if ( ( ( 1 << V_22 ) & V_91 -> V_148 ) == 0 ) {
F_28
( L_30
L_31 , V_22 ) ;
V_22 = 0 ;
} else {
if ( F_60
( V_22 , F_26 , 0 , L_27 , V_3 ) ) {
F_28
( L_32
L_31 , V_22 ) ;
V_22 = 0 ;
} else {
F_28 ( V_69 L_33 , V_22 ) ;
}
}
}
}
V_3 -> V_22 = V_22 ;
if ( V_22 )
V_32 -> V_62 = 1 ;
else
V_32 -> V_62 = 0 ;
V_32 -> V_63 = 0 ;
V_32 -> V_57 = 0 ;
#ifdef F_41
V_32 -> V_134 = 0 ;
if ( V_140 -> V_143 [ 2 ] > 0 ) {
if ( V_135 == 0 ) {
if ( ! F_58 ( F_61 ( 0 ) , V_149 ,
L_34 ) )
goto V_150;
}
V_32 -> V_136 = F_61 ( 0 ) ;
V_32 -> V_137 = V_149 ;
V_135 ++ ;
#ifdef F_62
if ( ! F_60 ( V_151 , V_152 , 0 ,
L_35 , V_3 ) ) {
V_32 -> V_134 = 1 ;
V_32 -> V_133 = V_151 ;
F_28 ( L_36 , V_32 -> V_133 ) ;
} else {
V_135 -- ;
if ( V_135 == 0 ) {
if ( V_32 -> V_136 )
F_56 ( V_32 -> V_136 ,
V_32 -> V_137 ) ;
}
V_32 -> V_136 = 0 ;
V_32 -> V_137 = 0 ;
}
#else
F_28 ( L_37 ) ;
#endif
}
V_150:
#endif
V_47 = 0 ;
V_32 -> V_47 = V_47 ;
if ( ( V_32 -> V_62 == 0 ) && ( V_32 -> V_134 == 0 ) )
goto V_153;
if ( V_91 -> V_154 != 0 ) {
V_47 = V_140 -> V_143 [ 2 ] ;
if ( V_47 < 1 )
goto V_153;
if ( ( ( 1 << V_47 ) & V_91 -> V_154 ) == 0 ) {
F_28 ( L_38 ) ;
return - V_100 ;
}
V_141 = F_63 ( V_47 , L_27 ) ;
if ( V_141 ) {
F_28 ( V_145
L_39 , V_47 ) ;
return - V_101 ;
}
V_32 -> V_47 = V_47 ;
F_28 ( V_69 L_40 , V_47 ) ;
V_142 = 2 ;
V_32 -> V_54 [ 0 ] = F_64 ( V_155 , V_142 ) ;
if ( ! V_32 -> V_54 [ 0 ] ) {
F_28 ( L_41 ) ;
return - V_101 ;
}
V_32 -> V_132 [ 0 ] = V_142 ;
V_32 -> V_51 [ 0 ] = F_65 ( ( void * ) V_32 -> V_54 [ 0 ] ) ;
V_32 -> V_52 [ 0 ] = ( 1 << V_142 ) * V_156 ;
if ( V_32 -> V_134 == 0 ) {
V_32 -> V_54 [ 1 ] = F_64 ( V_155 , V_142 ) ;
if ( ! V_32 -> V_54 [ 1 ] ) {
F_28 ( V_145
L_42
L_43 ) ;
return - V_101 ;
}
V_32 -> V_132 [ 1 ] = V_142 ;
V_32 -> V_51 [ 1 ] =
F_65 ( ( void * ) V_32 -> V_54 [ 1 ] ) ;
V_32 -> V_52 [ 1 ] = ( 1 << V_142 ) * V_156 ;
}
}
V_153:
V_141 = F_66 ( V_3 , 1 ) ;
if ( V_141 < 0 )
return V_141 ;
V_5 = V_3 -> V_24 + 0 ;
if ( V_91 -> V_157 > 0 ) {
V_5 -> type = V_158 ;
V_32 -> V_131 = V_5 ;
V_3 -> V_159 = V_5 ;
V_5 -> V_160 = V_161 | V_162 ;
V_5 -> V_163 = V_91 -> V_157 ;
V_5 -> V_160 |= V_164 ;
V_5 -> V_165 = V_91 -> V_166 ;
V_5 -> V_167 = V_91 -> V_168 ;
V_5 -> V_169 = V_91 -> V_170 ;
V_5 -> V_171 = F_14 ;
V_5 -> V_172 = F_29 ;
V_5 -> V_173 = F_33 ;
V_5 -> V_174 = F_37 ;
V_5 -> V_175 = F_5 ;
} else {
V_5 -> type = V_176 ;
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
F_45 ( V_3 ) ;
F_28 ( L_44 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
F_30 (printk(KERN_INFO L_45, dev->minor);)
F_52 ( V_3 ) ;
#ifdef F_41
if ( V_32 -> V_134 )
V_135 -- ;
#endif
return 0 ;
}
