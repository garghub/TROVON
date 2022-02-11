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
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_3 * V_4 = & V_2 -> V_26 [ 0 ] ;
int V_27 , V_28 ;
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
V_4 -> V_29 -> V_30 |= V_31 | V_32 ;
F_11 ( V_2 , V_4 ) ;
return V_33 ;
}
V_27 = F_6 ( V_2 -> V_10 + V_16 ) ;
V_28 = F_6 ( V_2 -> V_10 + V_19 ) ;
F_12 ( V_4 -> V_29 , ( V_28 << 8 ) | V_27 ) ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
if ( ++ V_24 -> V_34 >= V_24 -> V_35 )
V_24 -> V_34 = 0 ;
V_4 -> V_29 -> V_36 ++ ;
if ( V_4 -> V_29 -> V_36 >= V_24 -> V_37 ) {
V_4 -> V_29 -> V_36 = 0 ;
V_24 -> V_38 ++ ;
}
if ( ! V_24 -> V_39 )
if ( V_24 -> V_38 >= V_24 -> V_40 ) {
F_10 ( V_2 , V_4 ) ;
V_4 -> V_29 -> V_30 |= V_31 ;
}
F_11 ( V_2 , V_4 ) ;
return V_33 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , short * V_41 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_44 ;
V_4 -> V_29 -> V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
F_12 ( V_4 -> V_29 , V_41 [ V_42 ++ ] ) ;
if ( ++ V_24 -> V_34 >=
V_24 -> V_35 ) {
V_24 -> V_34 = 0 ;
}
V_4 -> V_29 -> V_36 ++ ;
if ( V_4 -> V_29 -> V_36 >= V_24 -> V_37 ) {
V_4 -> V_29 -> V_36 = 0 ;
V_24 -> V_38 ++ ;
}
if ( ! V_24 -> V_39 )
if ( V_24 -> V_38 >= V_24 -> V_40 ) {
F_10 ( V_2 , V_4 ) ;
V_4 -> V_29 -> V_30 |= V_31 ;
V_4 -> V_29 -> V_30 |= V_45 ;
break;
}
}
F_11 ( V_2 , V_4 ) ;
}
static T_1 F_14 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_3 * V_4 = & V_2 -> V_26 [ 0 ] ;
int V_43 , V_42 , V_46 ;
unsigned long V_47 ;
short * V_41 ;
F_15 ( V_24 -> V_48 ) ;
V_46 = V_24 -> V_49 ;
if ( ( V_24 -> V_50 > - 1 ) || V_24 -> V_39 ) {
V_24 -> V_49 = 1 - V_24 -> V_49 ;
F_16 ( V_24 -> V_48 , V_51 ) ;
V_47 = F_17 () ;
F_18 ( V_24 -> V_48 ,
V_24 -> V_52 [ V_24 -> V_49 ] ) ;
if ( V_24 -> V_50 ) {
F_19 ( V_24 -> V_48 ,
V_24 -> V_53 [ V_24 ->
V_49 ] ) ;
} else {
F_19 ( V_24 -> V_48 , V_24 -> V_54 ) ;
}
F_20 ( V_47 ) ;
F_21 ( V_24 -> V_48 ) ;
}
V_24 -> V_50 -- ;
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
V_41 = ( short * ) V_24 -> V_55 [ V_46 ] ;
V_43 = ( V_24 -> V_53 [ 0 ] >> 1 ) - V_24 -> V_56 ;
V_42 = V_24 -> V_56 ;
V_24 -> V_56 = 0 ;
F_13 ( V_2 , V_4 , V_41 , V_42 , V_43 ) ;
return V_33 ;
}
static T_1 F_22 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_23 * V_24 = V_2 -> V_25 ;
F_2 ( L_4 ) ;
if ( ! V_2 -> V_57 ) {
F_8 ( V_2 , L_5 ) ;
return V_33 ;
}
switch ( V_24 -> V_58 ) {
case V_59 :
case V_60 :
return F_14 ( V_21 , V_22 ) ;
case V_61 :
case V_62 :
return F_9 ( V_21 , V_22 ) ;
}
F_3 ( 0 , V_2 -> V_10 + V_12 ) ;
if ( ! V_2 -> V_21 || ! V_24 -> V_63 || ! V_24 -> V_64 ||
! V_24 -> V_58 ) {
if ( V_24 -> V_65 ) {
V_24 -> V_65 = 0 ;
return V_33 ;
}
F_8 ( V_2 , L_6 ) ;
return V_66 ;
}
F_8 ( V_2 , L_7 ) ;
return V_66 ;
}
static void F_23 ( int V_67 , struct V_68 * V_69 )
{
F_24 ( V_70 L_8 , V_67 ,
V_69 -> V_71 , V_69 -> V_72 , V_69 -> V_73 ) ;
F_24 ( V_70 L_9 , V_67 ,
V_69 -> V_74 , V_69 -> V_75 , V_69 -> V_76 ) ;
F_24 ( V_70 L_10 , V_67 ,
V_69 -> V_77 , V_69 -> V_78 ) ;
F_24 ( V_70 L_11 ,
V_67 , V_69 -> V_79 , V_69 -> V_80 , V_69 -> V_81 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_68 * V_69 )
{
const struct V_82 * V_83 = F_26 ( V_2 ) ;
int V_84 = 0 ;
int V_85 , V_86 = 0 , V_87 = 0 ;
F_27 (printk(KERN_INFO L_12);
pcl816_cmdtest_out(-1, cmd);
) ;
V_84 |= F_28 ( & V_69 -> V_71 , V_88 ) ;
V_84 |= F_28 ( & V_69 -> V_72 , V_89 ) ;
V_84 |= F_28 ( & V_69 -> V_73 , V_90 | V_91 ) ;
V_84 |= F_28 ( & V_69 -> V_78 , V_92 ) ;
V_84 |= F_28 ( & V_69 -> V_77 , V_92 | V_93 ) ;
if ( V_84 )
return 1 ;
V_84 |= F_29 ( V_69 -> V_73 ) ;
V_84 |= F_29 ( V_69 -> V_77 ) ;
if ( V_84 )
return 2 ;
V_84 |= F_30 ( & V_69 -> V_74 , 0 ) ;
V_84 |= F_30 ( & V_69 -> V_75 , 0 ) ;
if ( V_69 -> V_73 == V_91 )
V_84 |= F_31 ( & V_69 -> V_76 ,
V_83 -> V_94 ) ;
else
V_84 |= F_30 ( & V_69 -> V_76 , 0 ) ;
V_84 |= F_30 ( & V_69 -> V_80 , V_69 -> V_81 ) ;
if ( V_69 -> V_77 == V_92 )
V_84 |= F_31 ( & V_69 -> V_79 , 1 ) ;
else
V_84 |= F_30 ( & V_69 -> V_79 , 0 ) ;
if ( V_84 )
return 3 ;
if ( V_69 -> V_73 == V_91 ) {
V_85 = V_69 -> V_76 ;
F_32 ( V_83 -> V_95 ,
& V_86 , & V_87 ,
& V_69 -> V_76 ,
V_69 -> V_96 & V_97 ) ;
if ( V_69 -> V_76 < V_83 -> V_94 )
V_69 -> V_76 = V_83 -> V_94 ;
if ( V_85 != V_69 -> V_76 )
V_84 ++ ;
}
if ( V_84 )
return 4 ;
if ( V_69 -> V_98 ) {
if ( ! F_33 ( V_2 , V_4 , V_69 -> V_98 ,
V_69 -> V_81 ) )
return 5 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_82 * V_83 = F_26 ( V_2 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned int V_86 = 0 , V_87 = 0 , V_47 , V_99 , V_100 ;
struct V_68 * V_69 = & V_4 -> V_29 -> V_69 ;
unsigned int V_101 ;
if ( V_69 -> V_71 != V_88 )
return - V_102 ;
if ( V_69 -> V_72 != V_89 )
return - V_102 ;
if ( V_69 -> V_78 != V_92 )
return - V_102 ;
if ( V_69 -> V_80 != V_69 -> V_81 )
return - V_102 ;
if ( V_24 -> V_64 )
return - V_103 ;
if ( V_69 -> V_73 == V_91 ) {
if ( V_69 -> V_76 < V_83 -> V_94 )
V_69 -> V_76 = V_83 -> V_94 ;
F_32 ( V_83 -> V_95 , & V_86 ,
& V_87 , & V_69 -> V_76 ,
V_69 -> V_96 & V_97 ) ;
if ( V_86 == 1 ) {
V_86 = 2 ;
V_87 /= 2 ;
}
if ( V_87 == 1 ) {
V_87 = 2 ;
V_86 /= 2 ;
}
}
F_35 ( V_2 , - 1 , 0 , 0 ) ;
V_101 = F_33 ( V_2 , V_4 , V_69 -> V_98 , V_69 -> V_81 ) ;
if ( V_101 < 1 )
return - V_102 ;
F_36 ( V_2 , V_4 , V_69 -> V_98 , V_101 ) ;
F_7 ( 1 ) ;
V_24 -> V_37 = V_69 -> V_81 ;
V_24 -> V_38 = 0 ;
V_4 -> V_29 -> V_36 = 0 ;
V_24 -> V_64 = 1 ;
V_24 -> V_56 = 0 ;
V_24 -> V_65 = 0 ;
if ( V_69 -> V_77 == V_92 ) {
V_24 -> V_40 = V_69 -> V_79 ;
V_24 -> V_39 = 0 ;
} else {
V_24 -> V_40 = 0 ;
V_24 -> V_39 = 1 ;
}
if ( ( V_69 -> V_96 & V_104 ) ) {
F_24 ( V_70
L_13 ) ;
}
if ( V_24 -> V_48 ) {
V_99 = V_24 -> V_53 [ 0 ] ;
if ( ! V_24 -> V_39 ) {
V_99 = V_4 -> V_29 -> V_69 . V_81 *
V_4 -> V_29 -> V_69 . V_81 *
sizeof( short ) ;
V_24 -> V_50 = V_99 /
V_24 -> V_53 [ 0 ] ;
V_24 -> V_54 = V_99 % V_24 -> V_53 [ 0 ] ;
V_24 -> V_50 -- ;
if ( V_24 -> V_50 >= 0 )
V_99 = V_24 -> V_53 [ 0 ] ;
} else
V_24 -> V_50 = - 1 ;
V_24 -> V_49 = 0 ;
F_16 ( V_24 -> V_48 , V_51 ) ;
V_47 = F_17 () ;
F_37 ( V_24 -> V_48 ) ;
F_18 ( V_24 -> V_48 , V_24 -> V_52 [ 0 ] ) ;
F_19 ( V_24 -> V_48 , V_99 ) ;
F_20 ( V_47 ) ;
F_21 ( V_24 -> V_48 ) ;
}
F_35 ( V_2 , 1 , V_86 , V_87 ) ;
V_100 = ( ( V_24 -> V_48 & 0x3 ) << 4 ) | ( V_2 -> V_21 & 0x7 ) ;
switch ( V_69 -> V_73 ) {
case V_91 :
V_24 -> V_58 = V_59 ;
F_3 ( 0x32 , V_2 -> V_10 + V_11 ) ;
F_3 ( V_100 , V_2 -> V_10 + V_17 ) ;
break;
default:
V_24 -> V_58 = V_60 ;
F_3 ( 0x34 , V_2 -> V_10 + V_11 ) ;
F_3 ( V_100 , V_2 -> V_10 + V_17 ) ;
break;
}
F_2 ( L_14 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned long V_96 ;
unsigned int V_105 , V_106 , V_44 ;
if ( ! V_24 -> V_48 )
return 0 ;
F_39 ( & V_2 -> V_107 , V_96 ) ;
for ( V_44 = 0 ; V_44 < 20 ; V_44 ++ ) {
V_105 = F_40 ( V_24 -> V_48 ) ;
V_106 = F_40 ( V_24 -> V_48 ) ;
if ( V_105 == V_106 )
break;
}
if ( V_105 != V_106 ) {
F_41 ( & V_2 -> V_107 , V_96 ) ;
return 0 ;
}
V_105 = V_24 -> V_53 [ 0 ] - V_105 ;
V_105 >>= 1 ;
V_106 = V_105 - V_24 -> V_56 ;
if ( V_106 < 1 ) {
F_41 ( & V_2 -> V_107 , V_96 ) ;
return 0 ;
}
F_13 ( V_2 , V_4 ,
( short * ) V_24 -> V_55 [ V_24 -> V_49 ] ,
V_24 -> V_56 , V_106 ) ;
V_24 -> V_56 = V_105 ;
F_41 ( & V_2 -> V_107 , V_96 ) ;
return V_4 -> V_29 -> V_108 - V_4 -> V_29 -> V_109 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
if ( V_24 -> V_64 > 0 ) {
switch ( V_24 -> V_58 ) {
case V_59 :
case V_60 :
F_15 ( V_24 -> V_48 ) ;
case V_61 :
case V_62 :
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
V_24 -> V_64 = 0 ;
V_24 -> V_65 = V_24 -> V_58 ;
V_24 -> V_58 = 0 ;
V_24 -> V_111 = V_4 ;
break;
}
}
F_27 (printk(L_15);)
return 0 ;
}
static int F_42 ( unsigned long V_10 )
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
static void F_43 ( struct V_1 * V_2 )
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
F_35 ( struct V_1 * V_2 , int V_112 , unsigned int V_86 ,
unsigned int V_87 )
{
F_3 ( 0x32 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0xff , V_2 -> V_10 + V_113 ) ;
F_3 ( 0x00 , V_2 -> V_10 + V_113 ) ;
F_7 ( 1 ) ;
F_3 ( 0xb4 , V_2 -> V_10 + V_110 ) ;
F_3 ( 0x74 , V_2 -> V_10 + V_110 ) ;
F_7 ( 1 ) ;
if ( V_112 == 1 ) {
F_2 ( L_16 , V_112 , V_86 ,
V_87 ) ;
F_3 ( V_87 & 0xff , V_2 -> V_10 + V_114 ) ;
F_3 ( ( V_87 >> 8 ) & 0xff , V_2 -> V_10 + V_114 ) ;
F_3 ( V_86 & 0xff , V_2 -> V_10 + V_115 ) ;
F_3 ( ( V_86 >> 8 ) & 0xff , V_2 -> V_10 + V_115 ) ;
}
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_98 ,
unsigned int V_116 )
{
unsigned int V_117 [ 16 ] ;
unsigned int V_44 , V_118 , V_101 , V_119 ;
if ( V_116 < 1 ) {
F_8 ( V_2 , L_17 ) ;
return 0 ;
}
if ( V_116 > 1 ) {
V_117 [ 0 ] = V_98 [ 0 ] ;
for ( V_44 = 1 , V_101 = 1 ; V_44 < V_116 ; V_44 ++ , V_101 ++ ) {
F_27 (printk(KERN_INFO L_18, i,
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_98 [ 0 ] == V_98 [ V_44 ] )
break;
V_118 =
( F_4 ( V_117 [ V_44 - 1 ] ) + 1 ) % V_116 ;
if ( V_118 != F_4 ( V_98 [ V_44 ] ) ) {
F_24 ( V_120
L_19
L_20
L_21 , V_2 -> V_121 ,
V_44 , F_4 ( V_98 [ V_44 ] ) , V_118 ,
F_4 ( V_98 [ 0 ] ) ) ;
return 0 ;
}
V_117 [ V_44 ] = V_98 [ V_44 ] ;
}
for ( V_44 = 0 , V_119 = 0 ; V_44 < V_116 ; V_44 ++ ) {
F_27 (printk(L_22,
CR_CHAN(chansegment[i % seglen]),
CR_RANGE(chansegment[i % seglen]),
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if ( V_98 [ V_44 ] != V_117 [ V_44 % V_101 ] ) {
F_24 ( V_120
L_23
L_24
L_25 , V_2 -> V_121 , V_44 ,
F_4 ( V_117 [ V_44 ] ) ,
F_5 ( V_117 [ V_44 ] ) ,
F_44 ( V_117 [ V_44 ] ) ,
F_4 ( V_98 [ V_44 % V_101 ] ) ,
F_5 ( V_98 [ V_44 % V_101 ] ) ,
F_44 ( V_117 [ V_44 % V_101 ] ) ) ;
return 0 ;
}
}
} else {
V_101 = 1 ;
}
return V_101 ;
}
static void
F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_98 ,
unsigned int V_101 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned int V_44 ;
V_24 -> V_35 = V_101 ;
V_24 -> V_34 = 0 ;
for ( V_44 = 0 ; V_44 < V_101 ; V_44 ++ ) {
V_24 -> V_122 [ V_44 ] = F_4 ( V_98 [ V_44 ] ) ;
F_3 ( F_4 ( V_98 [ 0 ] ) & 0xf , V_2 -> V_10 + V_14 ) ;
F_3 ( F_5 ( V_98 [ 0 ] ) , V_2 -> V_10 + V_15 ) ;
}
F_7 ( 1 ) ;
F_3 ( V_24 -> V_122 [ 0 ] |
( V_24 -> V_122 [ V_101 - 1 ] << 4 ) ,
V_2 -> V_10 + V_14 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
const struct V_82 * V_83 = F_26 ( V_2 ) ;
struct V_23 * V_24 ;
int V_125 ;
unsigned int V_21 , V_48 ;
unsigned long V_126 ;
struct V_3 * V_4 ;
V_125 = F_46 ( V_2 , V_124 -> V_127 [ 0 ] , V_83 -> V_128 ) ;
if ( V_125 )
return V_125 ;
if ( F_42 ( V_2 -> V_10 ) ) {
F_24 ( V_129 L_26 ) ;
return - V_20 ;
}
V_24 = F_47 ( sizeof( * V_24 ) , V_130 ) ;
if ( ! V_24 )
return - V_131 ;
V_2 -> V_25 = V_24 ;
V_21 = 0 ;
if ( V_83 -> V_132 != 0 ) {
V_21 = V_124 -> V_127 [ 1 ] ;
if ( V_21 ) {
if ( ( ( 1 << V_21 ) & V_83 -> V_132 ) == 0 ) {
F_24
( L_27
L_28 , V_21 ) ;
V_21 = 0 ;
} else {
if ( F_48 ( V_21 , F_22 , 0 ,
V_2 -> V_133 , V_2 ) ) {
F_24
( L_29
L_28 , V_21 ) ;
V_21 = 0 ;
} else {
F_24 ( V_70 L_30 , V_21 ) ;
}
}
}
}
V_2 -> V_21 = V_21 ;
if ( V_21 )
V_24 -> V_63 = 1 ;
else
V_24 -> V_63 = 0 ;
V_24 -> V_64 = 0 ;
V_24 -> V_58 = 0 ;
V_48 = 0 ;
V_24 -> V_48 = V_48 ;
if ( ! V_24 -> V_63 )
goto V_134;
if ( V_83 -> V_135 != 0 ) {
V_48 = V_124 -> V_127 [ 2 ] ;
if ( V_48 < 1 )
goto V_134;
if ( ( ( 1 << V_48 ) & V_83 -> V_135 ) == 0 ) {
F_24 ( L_31 ) ;
return - V_102 ;
}
V_125 = F_49 ( V_48 , V_2 -> V_133 ) ;
if ( V_125 ) {
F_24 ( V_129
L_32 , V_48 ) ;
return - V_103 ;
}
V_24 -> V_48 = V_48 ;
F_24 ( V_70 L_33 , V_48 ) ;
V_126 = 2 ;
V_24 -> V_55 [ 0 ] = F_50 ( V_130 , V_126 ) ;
if ( ! V_24 -> V_55 [ 0 ] ) {
F_24 ( L_34 ) ;
return - V_103 ;
}
V_24 -> V_136 [ 0 ] = V_126 ;
V_24 -> V_52 [ 0 ] = F_51 ( ( void * ) V_24 -> V_55 [ 0 ] ) ;
V_24 -> V_53 [ 0 ] = ( 1 << V_126 ) * V_137 ;
V_24 -> V_55 [ 1 ] = F_50 ( V_130 , V_126 ) ;
if ( ! V_24 -> V_55 [ 1 ] ) {
F_24 ( V_129
L_35
L_36 ) ;
return - V_103 ;
}
V_24 -> V_136 [ 1 ] = V_126 ;
V_24 -> V_52 [ 1 ] = F_51 ( ( void * ) V_24 -> V_55 [ 1 ] ) ;
V_24 -> V_53 [ 1 ] = ( 1 << V_126 ) * V_137 ;
}
V_134:
V_125 = F_52 ( V_2 , 1 ) ;
if ( V_125 )
return V_125 ;
V_4 = & V_2 -> V_26 [ 0 ] ;
if ( V_83 -> V_138 > 0 ) {
V_4 -> type = V_139 ;
V_24 -> V_140 = V_4 ;
V_2 -> V_141 = V_4 ;
V_4 -> V_142 = V_143 | V_144 ;
V_4 -> V_145 = V_83 -> V_138 ;
V_4 -> V_142 |= V_146 ;
V_4 -> V_147 = V_83 -> V_148 ;
V_4 -> V_149 = V_83 -> V_150 ;
V_4 -> V_151 = V_83 -> V_152 ;
V_4 -> V_153 = F_10 ;
V_4 -> V_154 = F_25 ;
V_4 -> V_155 = F_34 ;
V_4 -> V_156 = F_38 ;
V_4 -> V_157 = F_1 ;
} else {
V_4 -> type = V_158 ;
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
F_43 ( V_2 ) ;
F_24 ( L_37 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
if ( V_2 -> V_25 ) {
F_10 ( V_2 , V_24 -> V_140 ) ;
F_43 ( V_2 ) ;
if ( V_24 -> V_48 )
F_54 ( V_24 -> V_48 ) ;
if ( V_24 -> V_55 [ 0 ] )
F_55 ( V_24 -> V_55 [ 0 ] , V_24 -> V_136 [ 0 ] ) ;
if ( V_24 -> V_55 [ 1 ] )
F_55 ( V_24 -> V_55 [ 1 ] , V_24 -> V_136 [ 1 ] ) ;
}
F_56 ( V_2 ) ;
}
