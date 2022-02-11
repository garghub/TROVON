static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_3 ( V_2 , V_7 ) ;
V_6 |= V_8 ;
V_6 |= V_9 ;
F_1 ( V_2 , V_7 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_3 ( V_2 , V_7 ) ;
V_6 &= ~ V_8 ;
V_6 |= V_9 ;
F_1 ( V_2 , V_7 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_3 ( V_2 , V_10 ) ;
V_6 |= V_8 ;
V_6 |= V_9 ;
F_1 ( V_2 , V_10 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_6 = F_3 ( V_2 , V_10 ) ;
V_6 &= ~ V_8 ;
V_6 |= V_9 ;
F_1 ( V_2 , V_10 , V_6 ) ;
}
static int F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_10 ( V_14 ) ;
F_11 ( V_16 -> V_17 ) ;
F_11 ( V_16 -> V_2 -> V_18 ) ;
return 0 ;
}
static void F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_10 ( V_14 ) ;
F_13 ( V_16 -> V_2 -> V_18 ) ;
F_13 ( V_16 -> V_17 ) ;
return;
}
static int F_14 ( struct V_13 * V_19 ,
int V_20 , unsigned int V_21 , int V_22 )
{
struct V_15 * V_16 = F_10 ( V_19 ) ;
int V_23 = 0 ;
switch ( V_20 ) {
case V_24 :
V_23 = F_15 ( V_16 -> V_25 , V_21 ) ;
if ( V_23 )
return V_23 ;
break;
case V_26 :
case V_27 :
return - V_28 ;
default:
return - V_28 ;
}
return 0 ;
}
static int F_16 ( struct V_13 * V_19 , int V_29 ,
int V_30 , unsigned int V_31 ,
unsigned int V_32 )
{
struct V_15 * V_16 = F_10 ( V_19 ) ;
int V_23 = 0 ;
switch ( V_29 ) {
case V_33 :
V_23 = F_15 ( V_16 -> V_17 , V_32 ) ;
if ( V_23 )
return V_23 ;
break;
case V_34 :
V_23 = F_15 ( V_16 -> V_2 -> V_18 , V_32 ) ;
if ( V_23 )
return V_23 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_17 ( struct V_13 * V_19 ,
unsigned int V_36 )
{
struct V_15 * V_15 = F_10 ( V_19 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
T_1 V_6 , V_37 ;
if ( V_15 -> V_38 == V_36 )
return 0 ;
if ( ( F_3 ( V_2 , V_7 ) & V_8 ) ||
( F_3 ( V_2 , V_10 ) & V_8 ) ) {
F_18 ( & V_2 -> V_39 -> V_40 ,
L_1 ) ;
return - V_28 ;
}
V_6 = V_9 | V_41 | V_42 ;
V_37 = 0 ;
switch ( V_36 & V_43 ) {
case V_44 :
V_6 |= V_45 ;
break;
case V_46 :
break;
default:
return - V_28 ;
}
switch ( V_36 & V_47 ) {
case V_48 :
V_6 |= V_49 ;
break;
default:
return - V_28 ;
}
switch ( V_36 & V_50 ) {
case V_51 :
V_6 |= F_19 ( 63 ) ;
V_6 |= F_20 ( 31 ) ;
V_37 |= F_21 ( 1 ) ;
break;
default:
return - V_28 ;
}
F_1 ( V_2 , V_7 , V_6 ) ;
F_1 ( V_2 , V_10 , V_6 ) ;
V_6 &= ~ ( V_41 | V_42 ) ;
F_1 ( V_2 , V_7 , V_6 ) ;
F_1 ( V_2 , V_10 , V_6 ) ;
V_6 &= ~ V_45 ;
F_1 ( V_2 , V_7 , V_6 ) ;
F_1 ( V_2 , V_52 , V_37 ) ;
F_1 ( V_2 , V_53 , V_37 ) ;
V_15 -> V_38 = V_36 ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 ,
struct V_54 * V_55 ,
struct V_13 * V_14 )
{
struct V_56 * V_57 = V_12 -> V_58 ;
struct V_13 * V_19 = V_57 -> V_19 ;
struct V_15 * V_15 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_59 * V_60 ;
T_1 V_37 ;
if ( V_12 -> V_61 == V_62 )
V_37 = F_3 ( V_2 , V_52 ) ;
else
V_37 = F_3 ( V_2 , V_53 ) ;
V_37 &= ~ V_63 ;
V_37 |= F_23 ( F_24 ( V_55 ) - 1 ) ;
V_37 &= ~ V_64 ;
V_37 |= F_25 ( V_65 ) ;
V_37 &= ~ V_66 ;
switch ( F_26 ( V_55 ) ) {
case V_67 :
V_37 |= F_27 ( V_68 ) ;
break;
case V_69 :
V_37 |= F_27 ( V_70 ) ;
break;
case V_71 :
V_37 |= F_27 ( V_72 ) ;
break;
case V_73 :
V_37 |= F_27 ( V_74 ) ;
break;
case V_75 :
V_37 |= F_27 ( V_65 ) ;
break;
default:
return - V_28 ;
}
if ( V_12 -> V_61 == V_62 ) {
F_1 ( V_2 , V_52 , V_37 ) ;
F_1 ( V_2 , V_76 , 0x1 ) ;
} else {
F_1 ( V_2 , V_53 , V_37 ) ;
F_1 ( V_2 , V_77 , 0x0 ) ;
}
V_60 = & V_15 -> V_60 [ V_12 -> V_61 ] ;
V_60 -> V_78 = V_12 -> V_61 == V_62 ?
( V_2 -> V_79 + V_80 ) :
( V_2 -> V_79 + V_81 ) ;
F_28 ( V_19 , V_12 , V_60 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 , int V_82 ,
struct V_13 * V_14 )
{
struct V_15 * V_15 = F_10 ( V_14 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_23 = 0 ;
switch ( V_82 ) {
case V_83 :
case V_84 :
case V_85 :
if ( ! V_15 -> V_86 )
F_7 ( V_2 ) ;
if ( V_12 -> V_61 == V_62 )
F_5 ( V_2 ) ;
V_15 -> V_86 ++ ;
break;
case V_87 :
case V_88 :
case V_89 :
V_15 -> V_86 -- ;
if ( V_12 -> V_61 == V_62 )
F_6 ( V_2 ) ;
if ( ! V_15 -> V_86 )
F_8 ( V_2 ) ;
break;
default:
V_23 = - V_28 ;
}
return V_23 ;
}
static int F_30 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_31 ( V_14 -> V_40 ) ;
F_32 ( V_14 , V_16 ) ;
return 0 ;
}
static int F_33 ( struct V_90 * V_39 )
{
struct V_15 * V_16 ;
struct V_91 * V_92 ;
V_16 = F_34 ( & V_39 -> V_40 ,
sizeof( struct V_15 ) , V_93 ) ;
if ( ! V_16 )
return - V_94 ;
V_16 -> V_2 = F_34 ( & V_39 -> V_40 ,
sizeof( struct V_1 ) , V_93 ) ;
if ( V_16 -> V_2 == NULL )
return - V_94 ;
V_16 -> V_60 = F_34 ( & V_39 -> V_40 ,
2 * sizeof( struct V_59 ) , V_93 ) ;
if ( V_16 -> V_60 == NULL )
return - V_94 ;
V_92 = F_35 ( V_39 , V_95 , 0 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_16 -> V_2 -> V_5 = F_36 ( & V_39 -> V_40 , V_92 ) ;
if ( F_37 ( V_16 -> V_2 -> V_5 ) )
return F_38 ( V_16 -> V_2 -> V_5 ) ;
V_16 -> V_2 -> V_18 = F_39 ( & V_39 -> V_40 , NULL ) ;
if ( F_37 ( V_16 -> V_2 -> V_18 ) )
return F_38 ( V_16 -> V_2 -> V_18 ) ;
V_16 -> V_25 = F_40 ( NULL , L_2 ) ;
if ( F_37 ( V_16 -> V_25 ) )
return F_38 ( V_16 -> V_25 ) ;
V_16 -> V_17 = F_40 ( NULL , L_3 ) ;
if ( F_37 ( V_16 -> V_17 ) ) {
F_41 ( V_16 -> V_25 ) ;
return F_38 ( V_16 -> V_17 ) ;
}
F_11 ( V_16 -> V_25 ) ;
V_16 -> V_38 = ( unsigned int ) - 1 ;
F_42 ( V_39 , V_16 ) ;
return F_43 ( & V_39 -> V_40 , & V_96 ) ;
}
static int F_44 ( struct V_90 * V_39 )
{
struct V_15 * V_16 = F_45 ( V_39 ) ;
F_13 ( V_16 -> V_25 ) ;
F_41 ( V_16 -> V_25 ) ;
F_41 ( V_16 -> V_17 ) ;
F_46 ( & V_39 -> V_40 ) ;
return 0 ;
}
