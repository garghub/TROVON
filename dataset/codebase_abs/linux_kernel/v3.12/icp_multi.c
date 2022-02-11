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
F_5 ( V_8 -> V_17 ,
V_8 -> V_20 + V_21 ) ;
}
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_25 , V_26 ;
V_8 -> V_27 &= ~ V_28 ;
F_5 ( V_8 -> V_27 , V_8 -> V_20 + V_29 ) ;
V_8 -> V_30 |= V_28 ;
F_5 ( V_8 -> V_30 , V_8 -> V_20 + V_31 ) ;
F_1 ( V_2 , V_4 , & V_23 -> V_32 , 1 ) ;
for ( V_25 = 0 ; V_25 < V_23 -> V_25 ; V_25 ++ ) {
V_8 -> V_17 |= V_33 ;
F_5 ( V_8 -> V_17 ,
V_8 -> V_20 + V_21 ) ;
V_8 -> V_17 &= ~ V_33 ;
F_7 ( 1 ) ;
V_26 = 100 ;
while ( V_26 -- ) {
if ( ! ( F_8 ( V_8 -> V_20 +
V_21 ) & V_34 ) )
goto V_35;
F_7 ( 1 ) ;
}
F_9 ( V_2 , L_1 ) ;
V_8 -> V_27 &= ~ V_28 ;
F_5 ( V_8 -> V_27 , V_8 -> V_20 + V_29 ) ;
V_8 -> V_30 |= V_28 ;
F_5 ( V_8 -> V_30 ,
V_8 -> V_20 + V_31 ) ;
V_24 [ V_25 ] = 0 ;
return - V_36 ;
V_35:
V_24 [ V_25 ] =
( F_8 ( V_8 -> V_20 + V_37 ) >> 4 ) & 0x0fff ;
}
V_8 -> V_27 &= ~ V_28 ;
F_5 ( V_8 -> V_27 , V_8 -> V_20 + V_29 ) ;
V_8 -> V_30 |= V_28 ;
F_5 ( V_8 -> V_30 , V_8 -> V_20 + V_31 ) ;
return V_25 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_25 , V_38 , V_11 , V_26 ;
V_8 -> V_27 &= ~ V_39 ;
F_5 ( V_8 -> V_27 , V_8 -> V_20 + V_29 ) ;
V_8 -> V_30 |= V_39 ;
F_5 ( V_8 -> V_30 , V_8 -> V_20 + V_31 ) ;
V_38 = F_2 ( V_23 -> V_32 ) ;
V_11 = F_4 ( V_23 -> V_32 ) ;
V_8 -> V_40 &= 0xfccf ;
V_8 -> V_40 |= V_19 [ V_11 ] ;
V_8 -> V_40 |= ( V_38 << 8 ) ;
F_5 ( V_8 -> V_40 , V_8 -> V_20 + V_41 ) ;
for ( V_25 = 0 ; V_25 < V_23 -> V_25 ; V_25 ++ ) {
V_26 = 100 ;
while ( V_26 -- ) {
if ( ! ( F_8 ( V_8 -> V_20 +
V_41 ) & V_42 ) )
goto V_43;
F_7 ( 1 ) ;
}
F_9 ( V_2 , L_2 ) ;
V_8 -> V_27 &= ~ V_39 ;
F_5 ( V_8 -> V_27 , V_8 -> V_20 + V_29 ) ;
V_8 -> V_30 |= V_39 ;
F_5 ( V_8 -> V_30 ,
V_8 -> V_20 + V_31 ) ;
V_8 -> V_44 [ V_38 ] = 0 ;
return - V_36 ;
V_43:
F_5 ( V_24 [ V_25 ] , V_8 -> V_20 + V_45 ) ;
V_8 -> V_40 |= V_46 ;
F_5 ( V_8 -> V_40 ,
V_8 -> V_20 + V_41 ) ;
V_8 -> V_40 &= ~ V_46 ;
V_8 -> V_44 [ V_38 ] = V_24 [ V_25 ] ;
}
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_25 , V_38 ;
V_38 = F_2 ( V_23 -> V_32 ) ;
for ( V_25 = 0 ; V_25 < V_23 -> V_25 ; V_25 ++ )
V_24 [ V_25 ] = V_8 -> V_44 [ V_38 ] ;
return V_25 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_24 [ 1 ] = F_8 ( V_8 -> V_20 + V_47 ) ;
return V_23 -> V_25 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_24 [ 0 ] ) {
V_4 -> V_48 &= ~ V_24 [ 0 ] ;
V_4 -> V_48 |= ( V_24 [ 0 ] & V_24 [ 1 ] ) ;
F_14 ( V_49 L_3 , V_4 -> V_48 ) ;
F_5 ( V_4 -> V_48 , V_8 -> V_20 + V_50 ) ;
}
V_24 [ 1 ] = F_8 ( V_8 -> V_20 + V_47 ) ;
return V_23 -> V_25 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned int * V_24 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_24 )
{
return 0 ;
}
static T_1 F_17 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_53 ;
V_53 = F_8 ( V_8 -> V_20 + V_31 ) & V_54 ;
if ( ! V_53 )
return V_55 ;
switch ( V_53 ) {
case V_28 :
break;
case V_39 :
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
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
F_5 ( 0 , V_8 -> V_20 + V_29 ) ;
F_5 ( 0x00ff , V_8 -> V_20 + V_31 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_8 -> V_40 &= 0xfcce ;
V_8 -> V_40 |= ( V_10 << 8 ) ;
F_5 ( 0 , V_8 -> V_20 + V_45 ) ;
V_8 -> V_40 |= V_46 ;
F_5 ( V_8 -> V_40 ,
V_8 -> V_20 + V_41 ) ;
F_7 ( 1 ) ;
}
F_5 ( 0 , V_8 -> V_20 + V_50 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned long V_63 )
{
struct V_64 * V_65 = F_20 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_66 ;
V_8 = F_21 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_67 ;
V_66 = F_22 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_8 -> V_20 = F_23 ( V_65 , 2 ) ;
if ( ! V_8 -> V_20 )
return - V_67 ;
V_66 = F_24 ( V_2 , 5 ) ;
if ( V_66 )
return V_66 ;
F_18 ( V_2 ) ;
if ( V_65 -> V_51 ) {
V_66 = F_25 ( V_65 -> V_51 , F_17 ,
V_68 , V_2 -> V_69 , V_2 ) ;
if ( V_66 == 0 )
V_2 -> V_51 = V_65 -> V_51 ;
}
V_4 = & V_2 -> V_70 [ 0 ] ;
V_2 -> V_71 = V_4 ;
V_4 -> type = V_72 ;
V_4 -> V_73 = V_74 | V_75 | V_76 | V_77 ;
V_4 -> V_6 = 16 ;
V_4 -> V_78 = 0x0fff ;
V_4 -> V_79 = 16 ;
V_4 -> V_80 = & V_81 ;
V_4 -> V_82 = F_6 ;
V_4 = & V_2 -> V_70 [ 1 ] ;
V_4 -> type = V_83 ;
V_4 -> V_73 = V_84 | V_76 | V_75 ;
V_4 -> V_6 = 4 ;
V_4 -> V_78 = 0x0fff ;
V_4 -> V_79 = 4 ;
V_4 -> V_80 = & V_81 ;
V_4 -> V_85 = F_10 ;
V_4 -> V_82 = F_11 ;
V_4 = & V_2 -> V_70 [ 2 ] ;
V_4 -> type = V_86 ;
V_4 -> V_73 = V_74 ;
V_4 -> V_6 = 16 ;
V_4 -> V_78 = 1 ;
V_4 -> V_79 = 16 ;
V_4 -> V_80 = & V_87 ;
V_4 -> V_88 = 0 ;
V_4 -> V_89 = F_12 ;
V_4 = & V_2 -> V_70 [ 3 ] ;
V_4 -> type = V_90 ;
V_4 -> V_73 = V_84 | V_74 ;
V_4 -> V_6 = 8 ;
V_4 -> V_78 = 1 ;
V_4 -> V_79 = 8 ;
V_4 -> V_80 = & V_87 ;
V_4 -> V_88 = 0xff ;
V_4 -> V_48 = 0 ;
V_4 -> V_89 = F_13 ;
V_4 = & V_2 -> V_70 [ 4 ] ;
V_4 -> type = V_91 ;
V_4 -> V_73 = V_84 | V_76 | V_75 ;
V_4 -> V_6 = 4 ;
V_4 -> V_78 = 0xffff ;
V_4 -> V_79 = 4 ;
V_4 -> V_48 = 0 ;
V_4 -> V_82 = F_15 ;
V_4 -> V_85 = F_16 ;
V_8 -> V_92 = 1 ;
F_26 ( V_2 -> V_93 , L_4 ,
V_2 -> V_69 , V_2 -> V_51 ? L_5 : L_6 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 )
if ( V_8 -> V_92 )
F_18 ( V_2 ) ;
if ( V_2 -> V_51 )
F_28 ( V_2 -> V_51 , V_2 ) ;
if ( V_8 && V_8 -> V_20 )
F_29 ( V_8 -> V_20 ) ;
F_30 ( V_2 ) ;
}
static int F_31 ( struct V_64 * V_2 ,
const struct V_94 * V_95 )
{
return F_32 ( V_2 , & V_96 , V_95 -> V_97 ) ;
}
