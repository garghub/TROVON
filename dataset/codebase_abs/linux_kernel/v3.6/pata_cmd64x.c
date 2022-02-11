static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_7 ;
F_3 ( V_4 , V_8 , & V_7 ) ;
if ( V_7 & ( 1 << V_2 -> V_9 ) )
return V_10 ;
return V_11 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_12 * V_13 , T_1 V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
struct V_15 V_16 ;
const unsigned long V_17 = 1000000 / 33 ;
const T_1 V_18 [] = { 0x40 , 0x40 , 0x40 , 0x80 , 0x00 } ;
T_1 V_19 ;
const T_1 V_20 [ 2 ] [ 2 ] = {
{ V_21 , V_22 } ,
{ V_23 , V_23 }
} ;
const T_1 V_24 [ 2 ] [ 2 ] = {
{ V_25 , V_26 } ,
{ V_27 , V_28 }
} ;
int V_29 = V_20 [ V_2 -> V_9 ] [ V_13 -> V_30 ] ;
int V_31 = V_24 [ V_2 -> V_9 ] [ V_13 -> V_30 ] ;
if ( F_5 ( V_13 , V_14 , & V_16 , V_17 , 0 ) < 0 ) {
F_6 (KERN_ERR DRV_NAME L_1 ) ;
return;
}
if ( V_2 -> V_9 ) {
struct V_12 * V_32 = F_7 ( V_13 ) ;
if ( V_32 ) {
struct V_15 V_33 ;
F_5 ( V_32 , V_32 -> V_34 , & V_33 , V_17 , 0 ) ;
F_8 ( & V_16 , & V_33 , & V_16 , V_35 ) ;
}
}
F_6 (KERN_DEBUG DRV_NAME L_2 ,
t.active, t.recover, t.setup) ;
if ( V_16 . V_36 > 16 ) {
V_16 . V_37 += V_16 . V_36 - 16 ;
V_16 . V_36 = 16 ;
}
if ( V_16 . V_37 > 16 )
V_16 . V_37 = 16 ;
if ( V_16 . V_36 == 16 )
V_16 . V_36 = 0 ;
else if ( V_16 . V_36 > 1 )
V_16 . V_36 -- ;
else
V_16 . V_36 = 15 ;
if ( V_16 . V_38 > 4 )
V_16 . V_38 = 0xC0 ;
else
V_16 . V_38 = V_18 [ V_16 . V_38 ] ;
V_16 . V_37 &= 0x0F ;
F_3 ( V_4 , V_29 , & V_19 ) ;
V_19 &= 0x3F ;
V_19 |= V_16 . V_38 ;
F_9 ( V_4 , V_29 , V_19 ) ;
F_9 ( V_4 , V_31 , ( V_16 . V_37 << 4 ) | V_16 . V_36 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_4 ( V_2 , V_13 , V_13 -> V_34 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
static const T_1 V_39 [] = {
0x30 , 0x20 , 0x10 , 0x20 , 0x10 , 0x00
} ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_40 , V_41 ;
int V_42 = V_43 + 8 * V_2 -> V_9 ;
int V_44 = V_45 + 8 * V_2 -> V_9 ;
int V_46 = 2 * V_13 -> V_30 ;
F_3 ( V_4 , V_44 , & V_41 ) ;
F_3 ( V_4 , V_42 , & V_40 ) ;
V_41 &= ~ ( 0x20 << V_13 -> V_30 ) ;
V_40 &= ~ ( 0x30 << V_46 ) ;
V_40 &= ~ ( 0x05 << V_13 -> V_30 ) ;
if ( V_13 -> V_47 >= V_48 ) {
V_40 |= V_39 [ V_13 -> V_47 - V_48 ] << V_46 ;
V_40 |= 1 << V_13 -> V_30 ;
if ( V_13 -> V_47 > V_49 )
V_40 |= 4 << V_13 -> V_30 ;
} else {
V_40 &= ~ ( 1 << V_13 -> V_30 ) ;
F_4 ( V_2 , V_13 , V_13 -> V_47 ) ;
}
V_41 |= 0x20 << V_13 -> V_30 ;
F_9 ( V_4 , V_42 , V_40 ) ;
F_9 ( V_4 , V_44 , V_41 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_50 = V_2 -> V_9 ? V_51 : V_52 ;
int V_53 = V_2 -> V_9 ? V_23 : V_54 ;
T_1 V_55 ;
F_3 ( V_4 , V_53 , & V_55 ) ;
return V_55 & V_50 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_53 = V_2 -> V_9 ? V_23 : V_54 ;
T_1 V_55 ;
F_14 ( V_2 ) ;
F_3 ( V_4 , V_53 , & V_55 ) ;
}
static bool F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
unsigned long V_56 = F_16 ( V_4 , 4 ) ;
int V_50 = V_2 -> V_9 ? V_57 : V_58 ;
T_1 V_59 = F_17 ( V_56 + 1 ) ;
return V_59 & V_50 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
unsigned long V_56 = F_16 ( V_4 , 4 ) ;
int V_50 = V_2 -> V_9 ? V_57 : V_58 ;
T_1 V_59 ;
F_14 ( V_2 ) ;
V_59 = F_17 ( V_56 + 1 ) ;
V_59 &= ~ ( V_58 | V_57 ) ;
F_19 ( V_59 | V_50 , V_56 + 1 ) ;
}
static void F_20 ( struct V_60 * V_61 )
{
F_21 ( V_61 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
T_1 V_59 ;
F_9 ( V_4 , V_62 , 64 ) ;
F_3 ( V_4 , V_63 , & V_59 ) ;
V_59 &= ~ 0x30 ;
V_59 |= 0x02 ;
F_9 ( V_4 , V_63 , V_59 ) ;
#ifdef F_23
F_9 ( V_4 , V_43 , 0xF0 ) ;
#endif
}
static int F_24 ( struct V_3 * V_4 , const struct V_64 * V_65 )
{
static const struct V_66 V_67 [ 7 ] = {
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = & V_75
} ,
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = & V_75
} ,
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = & V_76
} ,
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_77 = V_78 ,
. V_74 = & V_76
} ,
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_74 = & V_79
} ,
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_77 = V_80 ,
. V_74 = & V_81
} ,
{
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_73 ,
. V_77 = V_82 ,
. V_74 = & V_81
}
} ;
const struct V_66 * V_83 [] = {
& V_67 [ V_65 -> V_84 ] ,
& V_67 [ V_65 -> V_84 ] ,
NULL
} ;
T_1 V_19 ;
int V_85 ;
struct V_3 * V_86 = V_4 -> V_87 -> V_88 ;
int V_89 = ! ( V_86 && V_86 -> V_90 ==
V_91 ) ;
int V_92 = ( V_65 -> V_84 != 0 ) ;
V_85 = F_25 ( V_4 ) ;
if ( V_85 )
return V_85 ;
if ( V_65 -> V_84 == 0 )
F_26 ( V_4 ) ;
if ( V_4 -> V_93 == V_94 )
switch ( V_4 -> V_95 ) {
default:
V_83 [ 0 ] = & V_67 [ 3 ] ;
V_83 [ 1 ] = & V_67 [ 3 ] ;
break;
case 3 :
case 4 :
V_83 [ 0 ] = & V_67 [ 2 ] ;
V_83 [ 1 ] = & V_67 [ 2 ] ;
break;
case 1 :
V_83 [ 0 ] = & V_67 [ 4 ] ;
V_83 [ 1 ] = & V_67 [ 4 ] ;
case 2 :
case 0 :
V_92 = 0 ;
break;
}
F_22 ( V_4 ) ;
F_3 ( V_4 , V_96 , & V_19 ) ;
if ( ! V_89 )
F_27 ( V_97 , & V_4 -> V_6 , L_3 ) ;
if ( V_89 && V_92 && ! ( V_19 & V_98 ) ) {
F_27 ( V_97 , & V_4 -> V_6 , L_4 ) ;
V_83 [ 0 ] = & V_99 ;
}
if ( V_89 && ! ( V_19 & V_100 ) ) {
F_27 ( V_97 , & V_4 -> V_6 , L_5 ) ;
V_83 [ 1 ] = & V_99 ;
}
return F_28 ( V_4 , V_83 , & V_101 , NULL , 0 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_102 * V_5 = F_30 ( & V_4 -> V_6 ) ;
int V_85 ;
V_85 = F_31 ( V_4 ) ;
if ( V_85 )
return V_85 ;
F_22 ( V_4 ) ;
F_32 ( V_5 ) ;
return 0 ;
}
