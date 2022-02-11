static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 , V_11 , V_12 ;
unsigned int V_13 ;
V_8 -> V_14 = V_6 ;
V_8 -> V_15 = 0 ;
for ( V_10 = 0 ; V_10 < V_6 ; V_10 ++ ) {
V_12 = F_2 ( V_5 [ V_10 ] ) ;
if ( F_3 ( V_5 [ V_10 ] ) == V_16 ) {
V_13 = 1 ;
V_12 &= 0x0007 ;
} else {
V_13 = 0 ;
V_12 &= 0x000f ;
}
V_8 -> V_17 &= 0xf00f ;
if ( V_13 ) {
V_8 -> V_17 |= ( V_12 << 9 ) ;
V_8 -> V_17 |= V_18 ;
} else
V_8 -> V_17 |= ( V_12 << 8 ) ;
V_11 = V_19 [ F_4 ( V_5 [ V_10 ] ) ] ;
V_8 -> V_17 |= V_11 ;
F_5 ( V_8 -> V_17 , V_2 -> V_20 + V_21 ) ;
}
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned int V_25 ;
V_25 = F_7 ( V_2 -> V_20 + V_21 ) ;
if ( ( V_25 & V_26 ) == 0 )
return 0 ;
return - V_27 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_29 = 0 ;
int V_30 ;
V_8 -> V_31 &= ~ V_32 ;
F_5 ( V_8 -> V_31 , V_2 -> V_20 + V_33 ) ;
V_8 -> V_34 |= V_32 ;
F_5 ( V_8 -> V_34 , V_2 -> V_20 + V_35 ) ;
F_1 ( V_2 , V_4 , & V_23 -> V_36 , 1 ) ;
for ( V_30 = 0 ; V_30 < V_23 -> V_30 ; V_30 ++ ) {
V_8 -> V_17 |= V_37 ;
F_5 ( V_8 -> V_17 , V_2 -> V_20 + V_21 ) ;
V_8 -> V_17 &= ~ V_37 ;
F_9 ( 1 ) ;
V_29 = F_10 ( V_2 , V_4 , V_23 , F_6 , 0 ) ;
if ( V_29 )
break;
V_28 [ V_30 ] = ( F_7 ( V_2 -> V_20 + V_38 ) >> 4 ) & 0x0fff ;
}
V_8 -> V_31 &= ~ V_32 ;
F_5 ( V_8 -> V_31 , V_2 -> V_20 + V_33 ) ;
V_8 -> V_34 |= V_32 ;
F_5 ( V_8 -> V_34 , V_2 -> V_20 + V_35 ) ;
return V_29 ? V_29 : V_30 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned int V_25 ;
V_25 = F_7 ( V_2 -> V_20 + V_39 ) ;
if ( ( V_25 & V_40 ) == 0 )
return 0 ;
return - V_27 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_41 = F_2 ( V_23 -> V_36 ) ;
unsigned int V_11 = F_4 ( V_23 -> V_36 ) ;
int V_10 ;
V_8 -> V_31 &= ~ V_42 ;
F_5 ( V_8 -> V_31 , V_2 -> V_20 + V_33 ) ;
V_8 -> V_34 |= V_42 ;
F_5 ( V_8 -> V_34 , V_2 -> V_20 + V_35 ) ;
V_8 -> V_43 &= 0xfccf ;
V_8 -> V_43 |= V_19 [ V_11 ] ;
V_8 -> V_43 |= ( V_41 << 8 ) ;
F_5 ( V_8 -> V_43 , V_2 -> V_20 + V_39 ) ;
for ( V_10 = 0 ; V_10 < V_23 -> V_30 ; V_10 ++ ) {
unsigned int V_44 = V_28 [ V_10 ] ;
int V_29 ;
V_29 = F_10 ( V_2 , V_4 , V_23 , F_11 , 0 ) ;
if ( V_29 ) {
V_8 -> V_31 &= ~ V_42 ;
F_5 ( V_8 -> V_31 ,
V_2 -> V_20 + V_33 ) ;
V_8 -> V_34 |= V_42 ;
F_5 ( V_8 -> V_34 ,
V_2 -> V_20 + V_35 ) ;
return V_29 ;
}
F_5 ( V_44 , V_2 -> V_20 + V_45 ) ;
V_8 -> V_43 |= V_46 ;
F_5 ( V_8 -> V_43 , V_2 -> V_20 + V_39 ) ;
V_8 -> V_43 &= ~ V_46 ;
V_4 -> V_47 [ V_41 ] = V_44 ;
}
return V_23 -> V_30 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
V_28 [ 1 ] = F_7 ( V_2 -> V_20 + V_48 ) ;
return V_23 -> V_30 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
if ( F_15 ( V_4 , V_28 ) )
F_5 ( V_4 -> V_49 , V_2 -> V_20 + V_50 ) ;
V_28 [ 1 ] = V_4 -> V_49 ;
return V_23 -> V_30 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_28 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
return 0 ;
}
static T_1 F_18 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
int V_53 ;
V_53 = F_7 ( V_2 -> V_20 + V_35 ) & V_54 ;
if ( ! V_53 )
return V_55 ;
switch ( V_53 ) {
case V_32 :
break;
case V_42 :
break;
case V_56 :
break;
case V_57 :
break;
case V_58 :
break;
case V_59 :
break;
case V_60 :
break;
case V_61 :
break;
default:
break;
}
return V_62 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
F_5 ( 0 , V_2 -> V_20 + V_33 ) ;
F_5 ( 0x00ff , V_2 -> V_20 + V_35 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_8 -> V_43 &= 0xfcce ;
V_8 -> V_43 |= ( V_10 << 8 ) ;
F_5 ( 0 , V_2 -> V_20 + V_45 ) ;
V_8 -> V_43 |= V_46 ;
F_5 ( V_8 -> V_43 , V_2 -> V_20 + V_39 ) ;
F_9 ( 1 ) ;
}
F_5 ( 0 , V_2 -> V_20 + V_50 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned long V_63 )
{
struct V_64 * V_65 = F_21 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_29 ;
V_8 = F_22 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_66 ;
V_29 = F_23 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_2 -> V_20 = F_24 ( V_65 , 2 ) ;
if ( ! V_2 -> V_20 )
return - V_66 ;
V_29 = F_25 ( V_2 , 5 ) ;
if ( V_29 )
return V_29 ;
F_19 ( V_2 ) ;
if ( V_65 -> V_51 ) {
V_29 = F_26 ( V_65 -> V_51 , F_18 ,
V_67 , V_2 -> V_68 , V_2 ) ;
if ( V_29 == 0 )
V_2 -> V_51 = V_65 -> V_51 ;
}
V_4 = & V_2 -> V_69 [ 0 ] ;
V_2 -> V_70 = V_4 ;
V_4 -> type = V_71 ;
V_4 -> V_72 = V_73 | V_74 | V_75 | V_76 ;
V_4 -> V_6 = 16 ;
V_4 -> V_77 = 0x0fff ;
V_4 -> V_78 = 16 ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_81 = F_8 ;
V_4 = & V_2 -> V_69 [ 1 ] ;
V_4 -> type = V_82 ;
V_4 -> V_72 = V_83 | V_75 | V_74 ;
V_4 -> V_6 = 4 ;
V_4 -> V_77 = 0x0fff ;
V_4 -> V_78 = 4 ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_84 = F_12 ;
V_29 = F_27 ( V_4 ) ;
if ( V_29 )
return V_29 ;
V_4 = & V_2 -> V_69 [ 2 ] ;
V_4 -> type = V_85 ;
V_4 -> V_72 = V_73 ;
V_4 -> V_6 = 16 ;
V_4 -> V_77 = 1 ;
V_4 -> V_78 = 16 ;
V_4 -> V_79 = & V_86 ;
V_4 -> V_87 = F_13 ;
V_4 = & V_2 -> V_69 [ 3 ] ;
V_4 -> type = V_88 ;
V_4 -> V_72 = V_83 ;
V_4 -> V_6 = 8 ;
V_4 -> V_77 = 1 ;
V_4 -> V_78 = 8 ;
V_4 -> V_79 = & V_86 ;
V_4 -> V_87 = F_14 ;
V_4 = & V_2 -> V_69 [ 4 ] ;
V_4 -> type = V_89 ;
V_4 -> V_72 = V_83 ;
V_4 -> V_6 = 4 ;
V_4 -> V_77 = 0xffff ;
V_4 -> V_78 = 4 ;
V_4 -> V_49 = 0 ;
V_4 -> V_81 = F_16 ;
V_4 -> V_84 = F_17 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 )
F_19 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static int F_30 ( struct V_64 * V_2 ,
const struct V_90 * V_91 )
{
return F_31 ( V_2 , & V_92 , V_91 -> V_93 ) ;
}
