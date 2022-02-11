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
struct V_12 * V_13 ,
unsigned int * V_14 )
{
int V_4 = V_11 -> V_18 / 2 ;
int V_6 = ( V_11 -> V_18 % 2 ) ? 3 : 0 ;
int V_22 ;
V_22 = F_10 ( V_2 , V_11 , V_13 , V_14 , 0 ) ;
if ( V_22 )
return V_22 ;
if ( V_14 [ 0 ] == V_23 )
F_1 ( V_2 , V_11 -> V_16 , V_4 , 0 , V_6 ) ;
return V_13 -> V_21 ;
}
static void F_11 ( struct V_1 * V_2 )
{
const struct V_24 * V_25 = F_12 ( V_2 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_25 -> V_26 ; ++ V_4 ) {
F_1 ( V_2 , 0 , V_4 , 0 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , 0 , 3 ) ;
F_1 ( V_2 , 0 , V_4 , V_27 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , V_28 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , V_29 , 0 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_30 * V_31 = V_11 -> V_32 ;
int V_4 ;
V_4 = V_31 -> V_33 . V_4 ;
if ( V_4 < 0 )
return;
V_31 -> V_33 . V_34 = 0 ;
V_31 -> V_33 . V_35 = 0 ;
V_11 -> V_36 -> V_37 = NULL ;
F_1 ( V_2 , 0 , V_4 , V_28 , 0 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned V_38 )
{
struct V_30 * V_31 = V_11 -> V_32 ;
unsigned int V_39 = V_11 -> V_36 -> V_40 . V_41 ;
unsigned V_42 = V_11 -> V_36 -> V_43 ;
unsigned int V_3 = 0 ;
unsigned long V_44 ;
unsigned V_45 ;
unsigned int V_46 ;
F_15 ( & V_31 -> V_33 . V_47 , V_44 ) ;
if ( ! V_31 -> V_33 . V_35 )
goto V_48;
V_45 = V_38 ;
V_45 &= ( ( 0x1 << V_11 -> V_20 ) - 1 ) ;
if ( ! ( V_45 & V_31 -> V_33 . V_34 ) )
goto V_48;
for ( V_46 = 0 ; V_46 < V_39 ; V_46 ++ ) {
unsigned int V_49 = F_16 ( V_11 -> V_36 -> V_40 . V_50 [ V_46 ] ) ;
if ( V_45 & ( 1U << V_49 ) )
V_3 |= ( 1U << V_46 ) ;
}
if ( F_17 ( V_11 -> V_36 , V_3 ) &&
F_17 ( V_11 -> V_36 , V_3 >> 16 ) ) {
V_11 -> V_36 -> V_43 |= ( V_51 | V_52 ) ;
} else {
F_13 ( V_2 , V_11 ) ;
}
if ( ! V_31 -> V_33 . V_53 ) {
if ( V_31 -> V_33 . V_54 > 0 ) {
V_31 -> V_33 . V_54 -- ;
if ( V_31 -> V_33 . V_54 == 0 ) {
V_11 -> V_36 -> V_43 |= V_55 ;
F_13 ( V_2 , V_11 ) ;
}
}
}
V_48:
F_18 ( & V_31 -> V_33 . V_47 , V_44 ) ;
if ( V_42 != V_11 -> V_36 -> V_43 )
F_19 ( V_2 , V_11 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_4 )
{
struct V_56 * V_57 = V_2 -> V_32 ;
struct V_30 * V_31 ;
unsigned long V_7 = V_2 -> V_7 + ( V_4 * V_8 ) ;
unsigned int V_38 = 0 ;
int V_58 = 0 ;
unsigned long V_44 ;
unsigned char V_59 ;
int V_46 ;
F_15 ( & V_57 -> V_60 [ V_4 ] . V_47 , V_44 ) ;
V_59 = F_7 ( V_7 + V_61 ) & 0x07 ;
if ( V_59 ) {
V_38 = F_6 ( V_2 , V_4 , V_29 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , V_29 , 0 ) ;
++ V_58 ;
}
F_18 ( & V_57 -> V_60 [ V_4 ] . V_47 , V_44 ) ;
if ( V_38 ) {
struct V_10 * V_11 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_62 ; V_46 ++ ) {
V_11 = & V_2 -> V_63 [ V_46 ] ;
V_31 = V_11 -> V_32 ;
if ( V_31 -> V_33 . V_4 == V_4 ) {
F_14 ( V_2 , V_11 ,
V_38 ) ;
}
}
}
return V_58 ;
}
static T_1 F_21 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
struct V_56 * V_57 = V_2 -> V_32 ;
int V_58 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_66 ; ++ V_4 ) {
if ( V_64 == V_57 -> V_60 [ V_4 ] . V_64 ) {
if ( F_20 ( V_2 , V_4 ) )
V_58 ++ ;
}
}
if ( ! V_58 )
return V_67 ;
return V_68 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_30 * V_31 = V_11 -> V_32 ;
if ( ! V_31 -> V_33 . V_53 && V_31 -> V_33 . V_54 == 0 ) {
V_11 -> V_36 -> V_43 |= V_55 ;
V_31 -> V_33 . V_35 = 0 ;
return 1 ;
} else {
unsigned V_17 = 0 , V_69 = 0 , V_21 ;
int V_4 ;
struct V_70 * V_40 = & V_11 -> V_36 -> V_40 ;
V_4 = V_31 -> V_33 . V_4 ;
if ( V_4 < 0 )
return 1 ;
V_31 -> V_33 . V_34 = 0 ;
V_31 -> V_33 . V_35 = 1 ;
if ( V_40 -> V_50 ) {
for ( V_21 = 0 ; V_21 < V_40 -> V_41 ; V_21 ++ ) {
V_17 |= ( 1U << F_16 ( V_40 -> V_50 [ V_21 ] ) ) ;
V_69 |= ( F_23 ( V_40 -> V_50 [ V_21 ] )
|| F_24 ( V_40 ->
V_50 [ V_21 ] ) ? 1U : 0U )
<< F_16 ( V_40 -> V_50 [ V_21 ] ) ;
}
}
V_17 &= ( ( 0x1 << V_11 -> V_20 ) - 1 ) ;
V_31 -> V_33 . V_34 = V_17 ;
F_1 ( V_2 , V_69 , V_4 , V_27 , 0 ) ;
F_1 ( V_2 , V_17 , V_4 , V_28 , 0 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_30 * V_31 = V_11 -> V_32 ;
unsigned long V_44 ;
F_15 ( & V_31 -> V_33 . V_47 , V_44 ) ;
if ( V_31 -> V_33 . V_35 )
F_13 ( V_2 , V_11 ) ;
F_18 ( & V_31 -> V_33 . V_47 , V_44 ) ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_71 )
{
struct V_30 * V_31 = V_11 -> V_32 ;
unsigned long V_44 ;
int V_72 = 0 ;
if ( V_71 != 0 )
return - V_73 ;
F_15 ( & V_31 -> V_33 . V_47 , V_44 ) ;
V_11 -> V_36 -> V_37 = NULL ;
if ( V_31 -> V_33 . V_35 )
V_72 = F_22 ( V_2 , V_11 ) ;
F_18 ( & V_31 -> V_33 . V_47 , V_44 ) ;
if ( V_72 )
F_19 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_30 * V_31 = V_11 -> V_32 ;
struct V_70 * V_40 = & V_11 -> V_36 -> V_40 ;
unsigned long V_44 ;
int V_72 = 0 ;
F_15 ( & V_31 -> V_33 . V_47 , V_44 ) ;
V_31 -> V_33 . V_35 = 1 ;
switch ( V_40 -> V_74 ) {
case V_75 :
V_31 -> V_33 . V_53 = 0 ;
V_31 -> V_33 . V_54 = V_40 -> V_76 ;
break;
default:
V_31 -> V_33 . V_53 = 1 ;
V_31 -> V_33 . V_54 = 0 ;
break;
}
switch ( V_40 -> V_77 ) {
case V_78 :
V_11 -> V_36 -> V_37 = F_26 ;
break;
default:
V_72 = F_22 ( V_2 , V_11 ) ;
break;
}
F_18 ( & V_31 -> V_33 . V_47 , V_44 ) ;
if ( V_72 )
F_19 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_70 * V_40 )
{
int V_79 = 0 ;
V_79 |= F_29 ( & V_40 -> V_77 , V_80 | V_78 ) ;
V_79 |= F_29 ( & V_40 -> V_81 , V_82 ) ;
V_79 |= F_29 ( & V_40 -> V_83 , V_80 ) ;
V_79 |= F_29 ( & V_40 -> V_84 , V_75 ) ;
V_79 |= F_29 ( & V_40 -> V_74 , V_75 | V_85 ) ;
if ( V_79 )
return 1 ;
V_79 |= F_30 ( V_40 -> V_77 ) ;
V_79 |= F_30 ( V_40 -> V_74 ) ;
if ( V_79 )
return 2 ;
V_79 |= F_31 ( & V_40 -> V_86 , 0 ) ;
V_79 |= F_31 ( & V_40 -> V_87 , 0 ) ;
V_79 |= F_31 ( & V_40 -> V_88 , 0 ) ;
V_79 |= F_31 ( & V_40 -> V_89 , V_40 -> V_41 ) ;
switch ( V_40 -> V_74 ) {
case V_75 :
break;
case V_85 :
V_79 |= F_31 ( & V_40 -> V_76 , 0 ) ;
break;
default:
break;
}
if ( V_79 )
return 3 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
const struct V_24 * V_25 = F_12 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_56 * V_57 ;
struct V_30 * V_31 ;
int V_92 , V_93 , V_4 ;
unsigned int V_64 [ V_66 ] ;
int V_22 ;
V_64 [ 0 ] = V_91 -> V_94 [ 1 ] ;
V_64 [ 1 ] = V_91 -> V_94 [ 2 ] ;
V_22 = F_33 ( V_2 , V_91 -> V_94 [ 0 ] ,
V_25 -> V_26 * V_8 ) ;
if ( V_22 )
return V_22 ;
V_57 = F_34 ( V_2 , sizeof( * V_57 ) ) ;
if ( ! V_57 )
return - V_95 ;
for ( V_4 = 0 ; V_4 < V_66 ; ++ V_4 )
F_35 ( & V_57 -> V_60 [ V_4 ] . V_47 ) ;
V_93 = V_25 -> V_26 * 2 ;
V_57 -> V_96 = F_36 ( V_93 , sizeof( * V_31 ) , V_97 ) ;
if ( ! V_57 -> V_96 )
return - V_95 ;
V_22 = F_37 ( V_2 , V_93 ) ;
if ( V_22 )
return V_22 ;
for ( V_92 = 0 ; V_92 < ( int ) V_2 -> V_62 ; ++ V_92 ) {
V_11 = & V_2 -> V_63 [ V_92 ] ;
V_31 = & V_57 -> V_96 [ V_92 ] ;
V_11 -> V_32 = V_31 ;
V_11 -> V_98 = 1 ;
V_11 -> V_99 = & V_100 ;
V_11 -> V_101 = V_102 | V_103 ;
V_11 -> type = V_104 ;
V_11 -> V_105 = F_8 ;
V_11 -> V_106 = F_9 ;
V_11 -> V_20 = 24 ;
if ( ( V_92 % 2 ) == 0 ) {
V_31 -> V_33 . V_4 = V_92 / 2 ;
V_2 -> V_107 = V_11 ;
V_11 -> V_101 |= V_108 ;
V_11 -> V_109 = F_25 ;
V_11 -> V_110 = F_27 ;
V_11 -> V_111 = F_28 ;
V_11 -> V_112 = V_11 -> V_20 ;
} else {
V_31 -> V_33 . V_4 = - 1 ;
V_11 -> V_112 = 1 ;
}
F_35 ( & V_31 -> V_33 . V_47 ) ;
}
F_11 ( V_2 ) ;
for ( V_4 = 0 ; V_64 [ 0 ] && V_4 < V_66 ; ++ V_4 ) {
if ( V_64 [ V_4 ]
&& F_38 ( V_64 [ V_4 ] , F_21 ,
V_113 , V_25 -> V_114 , V_2 ) ) {
int V_46 ;
for ( V_46 = V_4 - 1 ; V_46 >= 0 ; -- V_46 ) {
F_39 ( V_64 [ V_46 ] , V_2 ) ;
V_57 -> V_60 [ V_46 ] . V_64 = V_64 [ V_46 ] = 0 ;
}
V_64 [ V_4 ] = 0 ;
}
V_57 -> V_60 [ V_4 ] . V_64 = V_64 [ V_4 ] ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_32 ;
int V_46 ;
if ( V_57 ) {
for ( V_46 = 0 ; V_46 < V_66 ; ++ V_46 ) {
if ( V_57 -> V_60 [ V_46 ] . V_64 )
F_39 ( V_57 -> V_60 [ V_46 ] . V_64 , V_2 ) ;
}
F_41 ( V_57 -> V_96 ) ;
}
F_42 ( V_2 ) ;
}
