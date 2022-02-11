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
struct V_22 * V_23 ,
unsigned int * V_24 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( F_14 ( V_4 , V_24 ) )
F_5 ( V_4 -> V_48 , V_8 -> V_20 + V_49 ) ;
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
static T_1 F_17 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_52 ;
V_52 = F_8 ( V_8 -> V_20 + V_31 ) & V_53 ;
if ( ! V_52 )
return V_54 ;
switch ( V_52 ) {
case V_28 :
break;
case V_39 :
break;
case V_55 :
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
default:
break;
}
return V_61 ;
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
F_5 ( 0 , V_8 -> V_20 + V_49 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned long V_62 )
{
struct V_63 * V_64 = F_20 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_65 ;
V_8 = F_21 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_66 ;
V_65 = F_22 ( V_2 ) ;
if ( V_65 )
return V_65 ;
V_8 -> V_20 = F_23 ( V_64 , 2 ) ;
if ( ! V_8 -> V_20 )
return - V_66 ;
V_65 = F_24 ( V_2 , 5 ) ;
if ( V_65 )
return V_65 ;
F_18 ( V_2 ) ;
if ( V_64 -> V_50 ) {
V_65 = F_25 ( V_64 -> V_50 , F_17 ,
V_67 , V_2 -> V_68 , V_2 ) ;
if ( V_65 == 0 )
V_2 -> V_50 = V_64 -> V_50 ;
}
V_4 = & V_2 -> V_69 [ 0 ] ;
V_2 -> V_70 = V_4 ;
V_4 -> type = V_71 ;
V_4 -> V_72 = V_73 | V_74 | V_75 | V_76 ;
V_4 -> V_6 = 16 ;
V_4 -> V_77 = 0x0fff ;
V_4 -> V_78 = 16 ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_81 = F_6 ;
V_4 = & V_2 -> V_69 [ 1 ] ;
V_4 -> type = V_82 ;
V_4 -> V_72 = V_83 | V_75 | V_74 ;
V_4 -> V_6 = 4 ;
V_4 -> V_77 = 0x0fff ;
V_4 -> V_78 = 4 ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_84 = F_10 ;
V_4 -> V_81 = F_11 ;
V_4 = & V_2 -> V_69 [ 2 ] ;
V_4 -> type = V_85 ;
V_4 -> V_72 = V_73 ;
V_4 -> V_6 = 16 ;
V_4 -> V_77 = 1 ;
V_4 -> V_78 = 16 ;
V_4 -> V_79 = & V_86 ;
V_4 -> V_87 = F_12 ;
V_4 = & V_2 -> V_69 [ 3 ] ;
V_4 -> type = V_88 ;
V_4 -> V_72 = V_83 | V_73 ;
V_4 -> V_6 = 8 ;
V_4 -> V_77 = 1 ;
V_4 -> V_78 = 8 ;
V_4 -> V_79 = & V_86 ;
V_4 -> V_87 = F_13 ;
V_4 = & V_2 -> V_69 [ 4 ] ;
V_4 -> type = V_89 ;
V_4 -> V_72 = V_83 | V_75 | V_74 ;
V_4 -> V_6 = 4 ;
V_4 -> V_77 = 0xffff ;
V_4 -> V_78 = 4 ;
V_4 -> V_48 = 0 ;
V_4 -> V_81 = F_15 ;
V_4 -> V_84 = F_16 ;
V_8 -> V_90 = 1 ;
F_26 ( V_2 -> V_91 , L_3 ,
V_2 -> V_68 , V_2 -> V_50 ? L_4 : L_5 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 )
if ( V_8 -> V_90 )
F_18 ( V_2 ) ;
if ( V_2 -> V_50 )
F_28 ( V_2 -> V_50 , V_2 ) ;
if ( V_8 && V_8 -> V_20 )
F_29 ( V_8 -> V_20 ) ;
F_30 ( V_2 ) ;
}
static int F_31 ( struct V_63 * V_2 ,
const struct V_92 * V_93 )
{
return F_32 ( V_2 , & V_94 , V_93 -> V_95 ) ;
}
