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
static void F_12 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
T_1 V_52 ;
int V_53 = V_2 -> V_9 ? V_54 : V_55 ;
int V_56 = V_2 -> V_9 ? V_23 : V_57 ;
F_13 ( V_51 ) ;
F_3 ( V_4 , V_56 , & V_52 ) ;
F_9 ( V_4 , V_56 , V_52 | V_53 ) ;
}
static void F_14 ( struct V_50 * V_51 )
{
F_13 ( V_51 ) ;
}
static int F_15 ( struct V_3 * V_4 , const struct V_58 * V_59 )
{
static const struct V_60 V_61 [ 6 ] = {
{
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_67 ,
. V_68 = & V_69
} ,
{
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_67 ,
. V_68 = & V_69
} ,
{
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_67 ,
. V_70 = V_71 ,
. V_68 = & V_69
} ,
{
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_67 ,
. V_68 = & V_72
} ,
{
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_67 ,
. V_70 = V_73 ,
. V_68 = & V_74
} ,
{
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_67 ,
. V_70 = V_75 ,
. V_68 = & V_74
}
} ;
const struct V_60 * V_76 [] = {
& V_61 [ V_59 -> V_77 ] ,
& V_61 [ V_59 -> V_77 ] ,
NULL
} ;
T_1 V_78 , V_19 ;
int V_79 ;
struct V_3 * V_80 = V_4 -> V_81 -> V_82 ;
int V_83 = ! ( V_80 && V_80 -> V_84 ==
V_85 ) ;
int V_86 = ( V_59 -> V_77 != 0 ) ;
V_79 = F_16 ( V_4 ) ;
if ( V_79 )
return V_79 ;
if ( V_59 -> V_77 == 0 )
F_17 ( V_4 ) ;
if ( V_4 -> V_87 == V_88 ) {
if ( V_4 -> V_89 > 4 ) {
V_76 [ 0 ] = & V_61 [ 2 ] ;
V_76 [ 1 ] = & V_61 [ 2 ] ;
}
else if ( V_4 -> V_89 == 1 ) {
V_76 [ 0 ] = & V_61 [ 3 ] ;
V_76 [ 1 ] = & V_61 [ 3 ] ;
}
if ( V_4 -> V_89 < 3 )
V_86 = 0 ;
}
F_9 ( V_4 , V_90 , 64 ) ;
F_3 ( V_4 , V_91 , & V_78 ) ;
V_78 &= ~ 0x30 ;
V_78 |= 0x02 ;
F_9 ( V_4 , V_91 , V_78 ) ;
F_3 ( V_4 , V_92 , & V_19 ) ;
if ( ! V_83 )
F_18 ( V_93 , & V_4 -> V_6 , L_3 ) ;
if ( V_83 && V_86 && ! ( V_19 & V_94 ) ) {
F_18 ( V_93 , & V_4 -> V_6 , L_4 ) ;
V_76 [ 0 ] = & V_95 ;
}
if ( V_83 && ! ( V_19 & V_96 ) ) {
F_18 ( V_93 , & V_4 -> V_6 , L_5 ) ;
V_76 [ 1 ] = & V_95 ;
}
#ifdef F_19
F_9 ( V_4 , V_43 , 0xF0 ) ;
#endif
return F_20 ( V_4 , V_76 , & V_97 , NULL , 0 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_98 * V_5 = F_22 ( & V_4 -> V_6 ) ;
T_1 V_78 ;
int V_79 ;
V_79 = F_23 ( V_4 ) ;
if ( V_79 )
return V_79 ;
F_9 ( V_4 , V_90 , 64 ) ;
F_3 ( V_4 , V_91 , & V_78 ) ;
V_78 &= ~ 0x30 ;
V_78 |= 0x02 ;
F_9 ( V_4 , V_91 , V_78 ) ;
#ifdef F_19
F_9 ( V_4 , V_43 , 0xF0 ) ;
#endif
F_24 ( V_5 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_99 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_99 ) ;
}
