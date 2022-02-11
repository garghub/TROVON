static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , int V_6 )
{
unsigned long V_7 = V_2 -> V_7 + ( V_4 * V_8 ) ;
if ( V_5 == 0 ) {
F_2 ( V_3 & 0xff , V_7 + F_3 ( V_6 + 0 ) ) ;
F_2 ( ( V_3 >> 8 ) & 0xff , V_7 + F_3 ( V_6 + 1 ) ) ;
F_2 ( ( V_3 >> 16 ) & 0xff , V_7 + F_3 ( V_6 + 2 ) ) ;
} else {
F_2 ( F_4 ( V_5 ) , V_7 + V_9 ) ;
F_2 ( V_3 & 0xff , V_7 + F_5 ( 0 ) ) ;
F_2 ( ( V_3 >> 8 ) & 0xff , V_7 + F_5 ( 1 ) ) ;
F_2 ( ( V_3 >> 16 ) & 0xff , V_7 + F_5 ( 2 ) ) ;
}
}
static unsigned int F_6 ( struct V_1 * V_2 ,
int V_4 , int V_5 , int V_6 )
{
unsigned long V_7 = V_2 -> V_7 + ( V_4 * V_8 ) ;
unsigned int V_3 ;
if ( V_5 == 0 ) {
V_3 = F_7 ( V_7 + F_3 ( V_6 + 0 ) ) ;
V_3 |= ( F_7 ( V_7 + F_3 ( V_6 + 1 ) ) << 8 ) ;
V_3 |= ( F_7 ( V_7 + F_3 ( V_6 + 2 ) ) << 16 ) ;
} else {
F_2 ( F_4 ( V_5 ) , V_7 + V_9 ) ;
V_3 = F_7 ( V_7 + F_5 ( 0 ) ) ;
V_3 |= ( F_7 ( V_7 + F_5 ( 1 ) ) << 8 ) ;
V_3 |= ( F_7 ( V_7 + F_5 ( 2 ) ) << 16 ) ;
}
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
unsigned int V_15 = V_14 [ 0 ] & V_11 -> V_16 ;
unsigned int V_17 = V_14 [ 1 ] ;
int V_4 = V_11 -> V_18 / 2 ;
int V_6 = ( V_11 -> V_18 % 2 ) ? 3 : 0 ;
unsigned int V_3 ;
V_3 = F_6 ( V_2 , V_4 , 0 , V_6 ) ;
V_11 -> V_19 = V_3 ^ ( ( 0x1 << V_11 -> V_20 ) - 1 ) ;
if ( V_15 ) {
V_11 -> V_19 &= ~ V_15 ;
V_11 -> V_19 |= ( V_15 & V_17 ) ;
V_3 = V_11 -> V_19 ^ ( ( 0x1 << V_11 -> V_20 ) - 1 ) ;
F_1 ( V_2 , V_3 , V_4 , 0 , V_6 ) ;
}
V_14 [ 1 ] = V_11 -> V_19 ;
return V_13 -> V_21 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned int * V_14 )
{
unsigned int V_22 = 1 << F_10 ( V_13 -> V_23 ) ;
int V_4 = V_11 -> V_18 / 2 ;
int V_6 = ( V_11 -> V_18 % 2 ) ? 3 : 0 ;
switch ( V_14 [ 0 ] ) {
case V_24 :
V_11 -> V_16 |= V_22 ;
break;
case V_25 :
V_11 -> V_16 &= ~ V_22 ;
F_1 ( V_2 , V_11 -> V_16 , V_4 , 0 , V_6 ) ;
break;
case V_26 :
V_14 [ 1 ] = ( V_11 -> V_16 & V_22 ) ? V_27 : V_28 ;
break;
default:
return - V_29 ;
break;
}
return V_13 -> V_21 ;
}
static void F_11 ( struct V_1 * V_2 )
{
const struct V_30 * V_31 = F_12 ( V_2 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_31 -> V_32 ; ++ V_4 ) {
F_1 ( V_2 , 0 , V_4 , 0 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , 0 , 3 ) ;
F_1 ( V_2 , 0 , V_4 , V_33 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , V_34 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , V_35 , 0 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_36 * V_37 = V_11 -> V_38 ;
int V_4 ;
V_4 = V_37 -> V_39 . V_4 ;
if ( V_4 < 0 )
return;
V_37 -> V_39 . V_40 = 0 ;
V_37 -> V_39 . V_41 = 0 ;
V_11 -> V_42 -> V_43 = NULL ;
F_1 ( V_2 , 0 , V_4 , V_34 , 0 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned V_44 )
{
struct V_36 * V_37 = V_11 -> V_38 ;
unsigned int V_45 = V_11 -> V_42 -> V_46 . V_47 ;
unsigned V_48 = V_11 -> V_42 -> V_49 ;
unsigned int V_3 = 0 ;
unsigned long V_50 ;
unsigned V_51 ;
unsigned int V_52 ;
F_15 ( & V_37 -> V_39 . V_53 , V_50 ) ;
if ( ! V_37 -> V_39 . V_41 )
goto V_54;
V_51 = V_44 ;
V_51 &= ( ( 0x1 << V_11 -> V_20 ) - 1 ) ;
if ( ! ( V_51 & V_37 -> V_39 . V_40 ) )
goto V_54;
for ( V_52 = 0 ; V_52 < V_45 ; V_52 ++ ) {
unsigned int V_55 = F_10 ( V_11 -> V_42 -> V_46 . V_56 [ V_52 ] ) ;
if ( V_51 & ( 1U << V_55 ) )
V_3 |= ( 1U << V_52 ) ;
}
if ( F_16 ( V_11 -> V_42 , ( ( short * ) & V_3 ) [ 0 ] ) &&
F_16 ( V_11 -> V_42 , ( ( short * ) & V_3 ) [ 1 ] ) ) {
V_11 -> V_42 -> V_49 |= ( V_57 | V_58 ) ;
} else {
F_13 ( V_2 , V_11 ) ;
}
if ( ! V_37 -> V_39 . V_59 ) {
if ( V_37 -> V_39 . V_60 > 0 ) {
V_37 -> V_39 . V_60 -- ;
if ( V_37 -> V_39 . V_60 == 0 ) {
V_11 -> V_42 -> V_49 |= V_61 ;
F_13 ( V_2 , V_11 ) ;
}
}
}
V_54:
F_17 ( & V_37 -> V_39 . V_53 , V_50 ) ;
if ( V_48 != V_11 -> V_42 -> V_49 )
F_18 ( V_2 , V_11 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_4 )
{
struct V_62 * V_63 = V_2 -> V_38 ;
struct V_36 * V_37 ;
unsigned long V_7 = V_2 -> V_7 + ( V_4 * V_8 ) ;
unsigned int V_44 = 0 ;
int V_64 = 0 ;
unsigned long V_50 ;
unsigned char V_65 ;
int V_52 ;
F_15 ( & V_63 -> V_66 [ V_4 ] . V_53 , V_50 ) ;
V_65 = F_7 ( V_7 + V_67 ) & 0x07 ;
if ( V_65 ) {
V_44 = F_6 ( V_2 , V_4 , V_35 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , V_35 , 0 ) ;
++ V_64 ;
}
F_17 ( & V_63 -> V_66 [ V_4 ] . V_53 , V_50 ) ;
if ( V_44 ) {
struct V_10 * V_11 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_68 ; V_52 ++ ) {
V_11 = & V_2 -> V_69 [ V_52 ] ;
V_37 = V_11 -> V_38 ;
if ( V_37 -> V_39 . V_4 == V_4 ) {
F_14 ( V_2 , V_11 ,
V_44 ) ;
}
}
}
return V_64 ;
}
static T_1 F_20 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_62 * V_63 = V_2 -> V_38 ;
int V_64 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_72 ; ++ V_4 ) {
if ( V_70 == V_63 -> V_66 [ V_4 ] . V_70 ) {
if ( F_19 ( V_2 , V_4 ) )
V_64 ++ ;
}
}
if ( ! V_64 )
return V_73 ;
return V_74 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_36 * V_37 = V_11 -> V_38 ;
if ( ! V_37 -> V_39 . V_59 && V_37 -> V_39 . V_60 == 0 ) {
V_11 -> V_42 -> V_49 |= V_61 ;
V_37 -> V_39 . V_41 = 0 ;
return 1 ;
} else {
unsigned V_17 = 0 , V_75 = 0 , V_21 ;
int V_4 ;
struct V_76 * V_46 = & V_11 -> V_42 -> V_46 ;
V_4 = V_37 -> V_39 . V_4 ;
if ( V_4 < 0 )
return 1 ;
V_37 -> V_39 . V_40 = 0 ;
V_37 -> V_39 . V_41 = 1 ;
if ( V_46 -> V_56 ) {
for ( V_21 = 0 ; V_21 < V_46 -> V_47 ; V_21 ++ ) {
V_17 |= ( 1U << F_10 ( V_46 -> V_56 [ V_21 ] ) ) ;
V_75 |= ( F_22 ( V_46 -> V_56 [ V_21 ] )
|| F_23 ( V_46 ->
V_56 [ V_21 ] ) ? 1U : 0U )
<< F_10 ( V_46 -> V_56 [ V_21 ] ) ;
}
}
V_17 &= ( ( 0x1 << V_11 -> V_20 ) - 1 ) ;
V_37 -> V_39 . V_40 = V_17 ;
F_1 ( V_2 , V_75 , V_4 , V_33 , 0 ) ;
F_1 ( V_2 , V_17 , V_4 , V_34 , 0 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_36 * V_37 = V_11 -> V_38 ;
unsigned long V_50 ;
F_15 ( & V_37 -> V_39 . V_53 , V_50 ) ;
if ( V_37 -> V_39 . V_41 )
F_13 ( V_2 , V_11 ) ;
F_17 ( & V_37 -> V_39 . V_53 , V_50 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_77 )
{
struct V_36 * V_37 = V_11 -> V_38 ;
unsigned long V_50 ;
int V_78 = 0 ;
if ( V_77 != 0 )
return - V_29 ;
F_15 ( & V_37 -> V_39 . V_53 , V_50 ) ;
V_11 -> V_42 -> V_43 = NULL ;
if ( V_37 -> V_39 . V_41 )
V_78 = F_21 ( V_2 , V_11 ) ;
F_17 ( & V_37 -> V_39 . V_53 , V_50 ) ;
if ( V_78 )
F_18 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_36 * V_37 = V_11 -> V_38 ;
struct V_76 * V_46 = & V_11 -> V_42 -> V_46 ;
unsigned long V_50 ;
int V_78 = 0 ;
F_15 ( & V_37 -> V_39 . V_53 , V_50 ) ;
V_37 -> V_39 . V_41 = 1 ;
switch ( V_46 -> V_79 ) {
case V_80 :
V_37 -> V_39 . V_59 = 0 ;
V_37 -> V_39 . V_60 = V_46 -> V_81 ;
break;
default:
V_37 -> V_39 . V_59 = 1 ;
V_37 -> V_39 . V_60 = 0 ;
break;
}
switch ( V_46 -> V_82 ) {
case V_83 :
V_11 -> V_42 -> V_43 = F_25 ;
break;
default:
V_78 = F_21 ( V_2 , V_11 ) ;
break;
}
F_17 ( & V_37 -> V_39 . V_53 , V_50 ) ;
if ( V_78 )
F_18 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_76 * V_46 )
{
int V_84 = 0 ;
V_84 |= F_28 ( & V_46 -> V_82 , V_85 | V_83 ) ;
V_84 |= F_28 ( & V_46 -> V_86 , V_87 ) ;
V_84 |= F_28 ( & V_46 -> V_88 , V_85 ) ;
V_84 |= F_28 ( & V_46 -> V_89 , V_80 ) ;
V_84 |= F_28 ( & V_46 -> V_79 , V_80 | V_90 ) ;
if ( V_84 )
return 1 ;
V_84 |= F_29 ( V_46 -> V_82 ) ;
V_84 |= F_29 ( V_46 -> V_79 ) ;
if ( V_84 )
return 2 ;
V_84 |= F_30 ( & V_46 -> V_91 , 0 ) ;
V_84 |= F_30 ( & V_46 -> V_92 , 0 ) ;
V_84 |= F_30 ( & V_46 -> V_93 , 0 ) ;
V_84 |= F_30 ( & V_46 -> V_94 , V_46 -> V_47 ) ;
switch ( V_46 -> V_79 ) {
case V_80 :
break;
case V_90 :
V_84 |= F_30 ( & V_46 -> V_81 , 0 ) ;
break;
default:
break;
}
if ( V_84 )
return 3 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
const struct V_30 * V_31 = F_12 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_62 * V_63 ;
struct V_36 * V_37 ;
int V_97 , V_98 , V_4 ;
unsigned int V_70 [ V_72 ] ;
int V_99 ;
V_70 [ 0 ] = V_96 -> V_100 [ 1 ] ;
V_70 [ 1 ] = V_96 -> V_100 [ 2 ] ;
V_99 = F_32 ( V_2 , V_96 -> V_100 [ 0 ] ,
V_31 -> V_32 * V_8 ) ;
if ( V_99 )
return V_99 ;
V_63 = F_33 ( sizeof( * V_63 ) , V_101 ) ;
if ( ! V_63 )
return - V_102 ;
V_2 -> V_38 = V_63 ;
for ( V_4 = 0 ; V_4 < V_72 ; ++ V_4 )
F_34 ( & V_63 -> V_66 [ V_4 ] . V_53 ) ;
V_98 = V_31 -> V_32 * 2 ;
V_63 -> V_103 = F_35 ( V_98 , sizeof( * V_37 ) , V_101 ) ;
if ( ! V_63 -> V_103 )
return - V_102 ;
V_99 = F_36 ( V_2 , V_98 ) ;
if ( V_99 )
return V_99 ;
for ( V_97 = 0 ; V_97 < ( int ) V_2 -> V_68 ; ++ V_97 ) {
V_11 = & V_2 -> V_69 [ V_97 ] ;
V_37 = & V_63 -> V_103 [ V_97 ] ;
V_11 -> V_38 = V_37 ;
V_11 -> V_104 = 1 ;
V_11 -> V_105 = & V_106 ;
V_11 -> V_107 = V_108 | V_109 ;
V_11 -> type = V_110 ;
V_11 -> V_111 = F_8 ;
V_11 -> V_112 = F_9 ;
V_11 -> V_20 = 24 ;
if ( ( V_97 % 2 ) == 0 ) {
V_37 -> V_39 . V_4 = V_97 / 2 ;
V_2 -> V_113 = V_11 ;
V_11 -> V_107 |= V_114 ;
V_11 -> V_115 = F_24 ;
V_11 -> V_116 = F_26 ;
V_11 -> V_117 = F_27 ;
V_11 -> V_118 = V_11 -> V_20 ;
} else {
V_37 -> V_39 . V_4 = - 1 ;
V_11 -> V_118 = 1 ;
}
F_34 ( & V_37 -> V_39 . V_53 ) ;
}
F_11 ( V_2 ) ;
for ( V_4 = 0 ; V_70 [ 0 ] && V_4 < V_72 ; ++ V_4 ) {
if ( V_70 [ V_4 ]
&& F_37 ( V_70 [ V_4 ] , F_20 ,
V_119 , V_31 -> V_120 , V_2 ) ) {
int V_52 ;
for ( V_52 = V_4 - 1 ; V_52 >= 0 ; -- V_52 ) {
F_38 ( V_70 [ V_52 ] , V_2 ) ;
V_63 -> V_66 [ V_52 ] . V_70 = V_70 [ V_52 ] = 0 ;
}
V_70 [ V_4 ] = 0 ;
}
V_63 -> V_66 [ V_4 ] . V_70 = V_70 [ V_4 ] ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_38 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_72 ; ++ V_52 ) {
if ( V_63 -> V_66 [ V_52 ] . V_70 )
F_38 ( V_63 -> V_66 [ V_52 ] . V_70 , V_2 ) ;
}
if ( V_63 && V_63 -> V_103 )
F_40 ( V_63 -> V_103 ) ;
F_41 ( V_2 ) ;
}
