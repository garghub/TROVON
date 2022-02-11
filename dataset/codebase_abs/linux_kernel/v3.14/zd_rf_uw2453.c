static int F_1 ( struct V_1 * V_2 , int V_3 ,
bool V_4 )
{
int V_5 ;
int V_6 = V_3 - 1 ;
T_1 V_7 ;
if ( V_4 )
V_7 = F_2 ( 1 , V_8 [ V_6 ] ) ;
else
V_7 = F_2 ( 1 , V_9 [ V_6 ] ) ;
V_5 = F_3 ( V_2 , V_7 , V_10 ) ;
if ( V_5 )
return V_5 ;
return F_3 ( V_2 ,
F_2 ( 2 , V_11 [ V_6 ] ) , V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_12 )
{
T_1 V_7 = 0x40000 | V_12 ;
return F_3 ( V_2 , F_2 ( 3 , V_7 ) , V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
static const T_1 V_13 [] = {
F_2 ( 0 , 0x25f98 ) ,
F_2 ( 0 , 0x25f9a ) ,
F_2 ( 0 , 0x25f94 ) ,
F_2 ( 0 , 0x27fd4 ) ,
} ;
return F_6 ( V_2 , V_13 , F_7 ( V_13 ) , V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
T_3 V_14 = V_2 -> V_15 [ V_3 - 1 ] ;
if ( V_14 >= F_7 ( V_16 ) ) {
F_9 ( F_10 ( V_2 ) , L_1
L_2 , V_14 , V_3 ) ;
return 0 ;
}
return F_3 ( V_2 ,
F_2 ( 7 , V_16 [ V_14 ] ) , V_10 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
int V_19 , V_5 ;
int V_20 = - 1 ;
T_2 V_21 ;
struct V_1 * V_2 = F_12 ( V_18 ) ;
static const struct V_22 V_23 [] = {
{ V_24 , 0x89 } , { V_25 , 0x20 } ,
{ V_26 , 0x28 } ,
{ V_27 , 0x38 } , { V_28 , 0x20 } , { V_29 , 0x93 } ,
{ V_30 , 0x15 } , { V_31 , 0x3e } , { V_32 , 0x00 } ,
{ V_33 , 0x28 } , { V_34 , 0x30 } ,
{ V_35 , 0x43 } ,
{ V_36 , 0x24 } , { V_37 , 0x32 } ,
{ V_38 , 0x92 } ,
{ V_39 , 0x1e } ,
{ V_40 , 0x04 } ,
{ V_41 , 0xfa } , { V_42 , 0x58 } , { V_43 , 0x30 } ,
{ V_44 , 0x30 } , { V_45 , 0x0a } , { V_46 , 0x04 } ,
{ V_47 , 0x00 } , { V_48 , 0x0a } , { V_49 , 0x8d } ,
{ V_50 , 0x28 } , { V_51 , 0x02 } ,
{ V_52 , 0x09 } ,
{ V_53 , 0x27 } ,
{ V_54 , 0x1c } ,
{ V_55 , 0x1c } ,
{ V_56 , 0x13 } ,
{ V_57 , 0x1f } ,
{ V_58 , 0x13 } , { V_59 , 0x1f } , { V_60 , 0x27 } ,
{ V_61 , 0x23 } ,
{ V_62 , 0x24 } ,
{ V_63 , 0x24 } ,
{ V_64 , 0xfa } ,
{ V_65 , 0xf0 } ,
{ V_66 , 0x1a } ,
{ V_67 , 0x4f } ,
{ V_68 , 0x1f } ,
{ V_69 , 0xf0 } , { V_70 , 0x57 } , { V_71 , 0xad } ,
{ V_72 , 0x6c } , { V_73 , 0x03 } ,
{ V_74 , 0x14 } ,
{ V_75 , 0x12 } ,
{ V_76 , 0x10 } , { V_77 , 0x50 } , { V_78 , 0xa8 } ,
{ V_79 , 0xac } , { V_80 , 0x20 } , { V_81 , 0xff } ,
{ V_82 , 0xff } ,
} ;
static const T_1 V_13 [] = {
F_2 ( 4 , 0x2b ) ,
F_2 ( 5 , 0x19e4f ) ,
F_2 ( 6 , 0xf81ad ) ,
F_2 ( 7 , 0x3fffe ) ,
F_2 ( 0 , 0x25f9c ) ,
F_2 ( 1 , 0x47 ) ,
F_2 ( 2 , 0x999 ) ,
F_2 ( 3 , 0x7602 ) ,
F_2 ( 3 , 0x46063 ) ,
} ;
V_5 = F_13 ( V_2 , V_23 , F_7 ( V_23 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_2 , V_13 , F_7 ( V_13 ) , V_10 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 ) ;
if ( V_5 )
return V_5 ;
for ( V_19 = 0 ; V_19 < F_7 ( V_83 ) - 1 ; V_19 ++ ) {
V_5 = F_1 ( V_2 , 1 , false ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_83 [ V_19 ] [ 0 ] ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_2 , 0x0f , V_84 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_15 ( V_2 , & V_21 , V_84 ) ;
if ( V_5 )
return V_5 ;
if ( ! ( V_21 & 0xf ) ) {
F_9 ( F_10 ( V_2 ) ,
L_3 , V_19 ) ;
V_20 = V_19 ;
break;
}
}
if ( V_20 == - 1 ) {
F_9 ( F_10 ( V_2 ) ,
L_4 ) ;
V_5 = F_1 ( V_2 , 1 , true ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_85 ) ;
if ( V_5 )
return V_5 ;
}
F_16 ( V_18 ) -> V_86 = V_20 + 1 ;
return F_14 ( V_2 , 0x06 , V_87 ) ;
}
static int F_17 ( struct V_17 * V_18 , T_3 V_3 )
{
int V_5 ;
T_2 V_88 ;
int V_86 = F_16 ( V_18 ) -> V_86 ;
bool V_4 = ( V_86 == - 1 ) ;
struct V_1 * V_2 = F_12 ( V_18 ) ;
static const struct V_22 V_23 [] = {
{ V_43 , 0x30 } , { V_44 , 0x30 } , { V_42 , 0x58 } ,
{ V_89 , 0xf0 } , { V_90 , 0x1b } , { V_91 , 0x58 } ,
} ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 )
V_88 = V_85 ;
else
V_88 = V_83 [ V_86 ] [ F_18 ( V_3 ) ] ;
V_5 = F_4 ( V_2 , V_88 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_13 ( V_2 , V_23 , F_7 ( V_23 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_8 ( V_2 , V_3 ) ;
if ( V_5 )
return V_5 ;
return F_14 ( V_2 , 0x06 , V_87 ) ;
}
static int F_19 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_1 * V_2 = F_12 ( V_18 ) ;
struct V_22 V_23 [] = {
{ V_92 , 0x00 } , { V_93 , 0x3f } ,
} ;
V_5 = F_3 ( V_2 , F_2 ( 0 , 0x25f94 ) , V_10 ) ;
if ( V_5 )
return V_5 ;
if ( F_20 ( V_2 ) )
V_23 [ 1 ] . V_12 = 0x7f ;
return F_13 ( V_2 , V_23 , F_7 ( V_23 ) ) ;
}
static int F_21 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_1 * V_2 = F_12 ( V_18 ) ;
static const struct V_22 V_23 [] = {
{ V_92 , 0x04 } , { V_93 , 0x2f } ,
} ;
V_5 = F_3 ( V_2 , F_2 ( 0 , 0x25f90 ) , V_10 ) ;
if ( V_5 )
return V_5 ;
return F_13 ( V_2 , V_23 , F_7 ( V_23 ) ) ;
}
static void F_22 ( struct V_17 * V_18 )
{
F_23 ( V_18 -> V_94 ) ;
}
int F_24 ( struct V_17 * V_18 )
{
V_18 -> V_95 = F_11 ;
V_18 -> V_96 = F_17 ;
V_18 -> V_97 = F_19 ;
V_18 -> V_98 = F_21 ;
V_18 -> V_99 = V_100 ;
V_18 -> V_101 = F_22 ;
V_18 -> V_102 = 0 ;
V_18 -> V_94 = F_25 ( sizeof( struct V_103 ) , V_104 ) ;
if ( V_18 -> V_94 == NULL )
return - V_105 ;
return 0 ;
}
