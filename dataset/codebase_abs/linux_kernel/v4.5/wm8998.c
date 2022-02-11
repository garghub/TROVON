static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
unsigned int V_9 ;
switch ( V_5 ) {
case V_10 :
V_9 = F_3 ( V_7 , V_11 ) ;
V_9 &= V_12 ;
V_9 >>= V_13 ;
switch ( V_9 ) {
case 0 :
case 1 :
case 2 :
V_9 = F_3 ( V_7 ,
V_14 + V_9 ) ;
if ( V_9 >= 0x11 ) {
F_4 ( V_7 -> V_15 ,
L_1 ,
F_5 ( V_9 ) ) ;
return - V_16 ;
}
break;
default:
F_6 ( V_7 -> V_15 ,
L_2 ,
V_9 ) ;
return - V_16 ;
}
V_9 = F_3 ( V_7 , V_17 ) ;
V_9 &= V_18 ;
V_9 >>= V_19 ;
switch ( V_9 ) {
case 8 :
case 9 :
V_9 -= 0x8 ;
V_9 = F_3 ( V_7 ,
V_20 + V_9 ) ;
if ( V_9 >= 0x11 ) {
F_4 ( V_7 -> V_15 ,
L_3 ,
F_5 ( V_9 ) ) ;
return - V_16 ;
}
break;
default:
F_6 ( V_7 -> V_15 ,
L_4 ,
V_9 ) ;
return - V_16 ;
}
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_6 * V_7 = F_8 ( V_4 ) ;
struct V_23 * V_8 = F_9 ( V_7 ) ;
struct V_24 * V_25 = F_10 ( V_7 ) ;
struct V_26 * V_26 = V_25 -> V_27 . V_26 ;
struct V_28 * V_29 = (struct V_28 * ) V_4 -> V_30 ;
unsigned int V_31 , V_32 ;
unsigned int V_33 , V_34 ;
V_31 = V_22 -> V_35 . V_36 . V_37 [ 0 ] ;
if ( V_31 > 1 )
return - V_16 ;
V_32 = V_26 -> V_38 . V_32 [ 2 * V_31 ] ;
V_34 = V_31 << V_39 ;
if ( V_32 & V_40 )
V_34 |= 1 << V_41 ;
switch ( V_26 -> V_38 . V_32 [ 0 ] ) {
case V_42 :
if ( V_31 )
V_33 = 0 ;
else
V_33 = 1 << V_43 ;
F_11 ( V_7 , V_44 ,
V_45 , V_33 ) ;
F_11 ( V_7 ,
V_46 ,
V_47 |
V_48 , V_34 ) ;
F_11 ( V_7 ,
V_49 ,
V_50 |
V_51 , V_34 ) ;
break;
default:
F_11 ( V_7 ,
V_29 -> V_52 ,
V_47 |
V_48 ,
V_34 ) ;
break;
}
return F_12 ( V_8 , V_4 ,
V_22 -> V_35 . V_36 . V_37 [ 0 ] ,
V_29 , NULL ) ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_6 * V_7 = F_8 ( V_4 ) ;
struct V_23 * V_8 = F_9 ( V_7 ) ;
struct V_24 * V_25 = F_10 ( V_7 ) ;
struct V_26 * V_26 = V_25 -> V_27 . V_26 ;
struct V_28 * V_29 = (struct V_28 * ) V_4 -> V_30 ;
unsigned int V_31 , V_32 , V_34 , V_33 ;
V_31 = V_22 -> V_35 . V_36 . V_37 [ 0 ] ;
if ( V_31 > 1 )
return - V_16 ;
V_32 = V_26 -> V_38 . V_32 [ 1 + ( 2 * V_31 ) ] ;
if ( V_32 & V_42 )
V_33 = 1 << V_53 ;
else
V_33 = 0 ;
V_34 = V_31 << V_54 ;
if ( V_32 & V_40 )
V_34 |= 1 << V_55 ;
F_11 ( V_7 , V_56 ,
V_57 , V_33 ) ;
F_11 ( V_7 , V_58 ,
V_59 | V_60 ,
V_34 ) ;
return F_12 ( V_8 , V_4 ,
V_22 -> V_35 . V_36 . V_37 [ 0 ] ,
V_29 , NULL ) ;
}
static int F_14 ( struct V_6 * V_7 , int V_61 , int V_62 ,
unsigned int V_63 , unsigned int V_64 )
{
struct V_24 * V_25 = F_10 ( V_7 ) ;
switch ( V_61 ) {
case V_65 :
return F_15 ( & V_25 -> V_66 [ 0 ] , V_62 , V_63 , V_64 ) ;
case V_67 :
return F_15 ( & V_25 -> V_66 [ 1 ] , V_62 , V_63 , V_64 ) ;
case V_68 :
return F_16 ( & V_25 -> V_66 [ 0 ] , V_62 , V_63 ,
V_64 ) ;
case V_69 :
return F_16 ( & V_25 -> V_66 [ 1 ] , V_62 , V_63 ,
V_64 ) ;
default:
return - V_16 ;
}
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_24 * V_70 = F_10 ( V_7 ) ;
struct V_23 * V_8 = F_9 ( V_7 ) ;
V_70 -> V_27 . V_26 -> V_8 = V_8 ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
F_20 ( V_8 , L_5 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_24 * V_70 = F_10 ( V_7 ) ;
V_70 -> V_27 . V_26 -> V_8 = NULL ;
return 0 ;
}
static struct V_71 * F_22 ( struct V_72 * V_15 )
{
struct V_24 * V_70 = F_23 ( V_15 ) ;
return V_70 -> V_27 . V_26 -> V_71 ;
}
static int F_24 ( struct V_73 * V_74 )
{
struct V_26 * V_26 = F_23 ( V_74 -> V_15 . V_75 ) ;
struct V_24 * V_25 ;
int V_76 ;
V_25 = F_25 ( & V_74 -> V_15 , sizeof( struct V_24 ) ,
V_77 ) ;
if ( ! V_25 )
return - V_78 ;
F_26 ( V_74 , V_25 ) ;
V_25 -> V_27 . V_26 = V_26 ;
V_25 -> V_27 . V_79 = 3 ;
for ( V_76 = 0 ; V_76 < F_27 ( V_25 -> V_66 ) ; V_76 ++ )
V_25 -> V_66 [ V_76 ] . V_80 = 1 ;
F_28 ( V_26 , 1 , V_81 - 1 ,
V_82 , V_83 ,
& V_25 -> V_66 [ 0 ] ) ;
F_28 ( V_26 , 2 , V_84 - 1 ,
V_85 , V_86 ,
& V_25 -> V_66 [ 1 ] ) ;
for ( V_76 = 0 ; V_76 < F_27 ( V_87 ) ; V_76 ++ )
F_29 ( & V_25 -> V_27 , V_76 ) ;
for ( V_76 = 0 ; V_76 < F_27 ( V_88 ) ; V_76 ++ )
F_30 ( V_26 -> V_71 , V_88 [ V_76 ] ,
V_89 , V_89 ) ;
F_31 ( & V_74 -> V_15 ) ;
F_32 ( & V_74 -> V_15 ) ;
return F_33 ( & V_74 -> V_15 , & V_90 ,
V_87 , F_27 ( V_87 ) ) ;
}
static int F_34 ( struct V_73 * V_74 )
{
F_35 ( & V_74 -> V_15 ) ;
F_36 ( & V_74 -> V_15 ) ;
return 0 ;
}
