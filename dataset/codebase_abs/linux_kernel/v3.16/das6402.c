static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_2 ( V_4 | V_3 , V_2 -> V_5 + V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
F_2 ( V_8 , V_2 -> V_5 + V_9 ) ;
F_2 ( V_8 | V_7 , V_2 -> V_5 + V_9 ) ;
F_2 ( V_7 , V_2 -> V_5 + V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_10 |
V_11 |
V_12 , V_2 -> V_5 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_10 , V_2 -> V_5 + V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , bool V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned long V_17 = V_2 -> V_5 + V_18 ;
if ( V_13 ) {
F_7 ( V_17 , 0 , 0 , V_19 | V_20 ) ;
F_7 ( V_17 , 0 , 1 , V_21 | V_20 ) ;
F_7 ( V_17 , 0 , 2 , V_21 | V_20 ) ;
F_8 ( V_17 , 0 , 0 , V_15 -> V_22 ) ;
F_8 ( V_17 , 0 , 1 , V_15 -> V_23 ) ;
F_8 ( V_17 , 0 , 2 , V_15 -> V_24 ) ;
} else {
F_7 ( V_17 , 0 , 0 , V_19 | V_20 ) ;
F_7 ( V_17 , 0 , 1 , V_19 | V_20 ) ;
F_7 ( V_17 , 0 , 2 , V_19 | V_20 ) ;
}
}
static T_1 F_9 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
F_4 ( V_2 ) ;
return V_27 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
return - V_30 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_31 * V_32 )
{
return - V_30 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
F_2 ( V_33 , V_2 -> V_5 + V_34 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( 0 , V_2 -> V_5 + V_35 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_36 * V_37 ,
unsigned long V_38 )
{
unsigned int V_39 ;
V_39 = F_16 ( V_2 -> V_5 + V_9 ) ;
if ( V_39 & V_40 )
return 0 ;
return - V_41 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_36 * V_37 ,
unsigned int * V_42 )
{
unsigned int V_43 = F_18 ( V_37 -> V_44 ) ;
unsigned int V_45 = F_19 ( V_37 -> V_44 ) ;
unsigned int V_46 = F_20 ( V_37 -> V_44 ) ;
unsigned int V_7 ;
int V_47 ;
int V_48 ;
V_7 = F_21 ( V_45 ) | V_49 ;
if ( V_46 == V_50 ) {
if ( V_43 > V_29 -> V_51 / 2 )
return - V_30 ;
} else {
V_7 |= V_52 ;
}
if ( F_22 ( V_29 , V_45 ) )
V_7 |= V_53 ;
F_2 ( V_33 , V_2 -> V_5 + V_34 ) ;
F_1 ( V_2 , V_7 ) ;
F_14 ( F_23 ( V_43 ) | F_24 ( V_43 ) ,
V_2 -> V_5 + V_54 ) ;
for ( V_48 = 0 ; V_48 < V_37 -> V_55 ; V_48 ++ ) {
F_5 ( V_2 ) ;
F_13 ( V_2 ) ;
V_47 = F_25 ( V_2 , V_29 , V_37 , F_15 , 0 ) ;
if ( V_47 )
break;
V_7 = F_26 ( V_2 -> V_5 + V_35 ) ;
if ( V_29 -> V_56 == 0x0fff )
V_7 >>= 4 ;
V_42 [ V_48 ] = V_7 ;
}
F_5 ( V_2 ) ;
return V_37 -> V_55 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_36 * V_37 ,
unsigned int * V_42 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_43 = F_18 ( V_37 -> V_44 ) ;
unsigned int V_45 = F_19 ( V_37 -> V_44 ) ;
unsigned int V_7 ;
int V_48 ;
V_7 = V_15 -> V_57 ;
V_7 &= ~ F_28 ( V_43 ) ;
V_7 |= F_29 ( V_43 , V_45 ) ;
if ( V_7 != V_15 -> V_57 ) {
V_15 -> V_57 = V_7 ;
F_2 ( V_7 , V_2 -> V_5 + V_58 ) ;
}
for ( V_48 = 0 ; V_48 < V_37 -> V_55 ; V_48 ++ ) {
V_7 = V_42 [ V_48 ] ;
V_15 -> V_59 [ V_43 ] = V_7 ;
if ( V_29 -> V_56 == 0x0fff ) {
V_7 <<= 4 ;
F_14 ( V_7 , V_2 -> V_5 + F_30 ( V_43 ) ) ;
} else {
F_2 ( V_7 & 0xff ,
V_2 -> V_5 + F_31 ( V_43 ) ) ;
F_2 ( ( V_7 >> 8 ) & 0xff ,
V_2 -> V_5 + F_31 ( V_43 ) ) ;
}
}
return V_37 -> V_55 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_36 * V_37 ,
unsigned int * V_42 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_43 = F_18 ( V_37 -> V_44 ) ;
int V_48 ;
F_26 ( V_2 -> V_5 + F_31 ( V_43 ) ) ;
for ( V_48 = 0 ; V_48 < V_37 -> V_55 ; V_48 ++ )
V_42 [ V_48 ] = V_15 -> V_59 [ V_43 ] ;
return V_37 -> V_55 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_36 * V_37 ,
unsigned int * V_42 )
{
V_42 [ 1 ] = F_16 ( V_2 -> V_5 + V_60 ) ;
return V_37 -> V_55 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_36 * V_37 ,
unsigned int * V_42 )
{
if ( F_35 ( V_29 , V_42 ) )
F_2 ( V_29 -> V_61 , V_2 -> V_5 + V_60 ) ;
V_42 [ 1 ] = V_29 -> V_61 ;
return V_37 -> V_55 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
F_2 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_2 , V_62 ) ;
F_2 ( V_33 , V_2 -> V_5 + V_34 ) ;
F_1 ( V_2 , F_21 ( 0 ) |
V_49 |
V_52 |
V_53 ) ;
F_14 ( F_23 ( 0 ) | F_24 ( 0 ) ,
V_2 -> V_5 + V_54 ) ;
V_15 -> V_57 = F_29 ( 0 , 2 ) | F_29 ( 1 , 2 ) ;
F_2 ( V_15 -> V_57 , V_2 -> V_5 + V_58 ) ;
F_14 ( 0 , V_2 -> V_5 + F_30 ( 0 ) ) ;
F_14 ( 0 , V_2 -> V_5 + F_30 ( 0 ) ) ;
F_26 ( V_2 -> V_5 + F_31 ( 0 ) ) ;
F_6 ( V_2 , false ) ;
F_2 ( 0 , V_2 -> V_5 + V_60 ) ;
F_4 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
const struct V_65 * V_66 = F_38 ( V_2 ) ;
struct V_14 * V_15 ;
struct V_28 * V_29 ;
int V_47 ;
V_15 = F_39 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_67 ;
V_47 = F_40 ( V_2 , V_64 -> V_68 [ 0 ] , 0x10 ) ;
if ( V_47 )
return V_47 ;
F_36 ( V_2 ) ;
if ( ( 1 << V_64 -> V_68 [ 1 ] ) & 0x8cec ) {
V_47 = F_41 ( V_64 -> V_68 [ 1 ] , F_9 , 0 ,
V_2 -> V_69 , V_2 ) ;
if ( V_47 == 0 ) {
V_2 -> V_25 = V_64 -> V_68 [ 1 ] ;
switch ( V_2 -> V_25 ) {
case 10 :
V_15 -> V_25 = 4 ;
break;
case 11 :
V_15 -> V_25 = 1 ;
break;
case 15 :
V_15 -> V_25 = 6 ;
break;
default:
V_15 -> V_25 = V_2 -> V_25 ;
break;
}
}
}
V_47 = F_42 ( V_2 , 4 ) ;
if ( V_47 )
return V_47 ;
V_29 = & V_2 -> V_70 [ 0 ] ;
V_29 -> type = V_71 ;
V_29 -> V_72 = V_73 | V_74 | V_75 ;
V_29 -> V_51 = 64 ;
V_29 -> V_56 = V_66 -> V_56 ;
V_29 -> V_76 = & V_77 ;
V_29 -> V_78 = F_17 ;
if ( V_2 -> V_25 ) {
V_2 -> V_79 = V_29 ;
V_29 -> V_72 |= V_80 ;
V_29 -> V_81 = V_29 -> V_51 ;
V_29 -> V_82 = F_11 ;
V_29 -> V_83 = F_10 ;
V_29 -> V_84 = F_12 ;
}
V_29 = & V_2 -> V_70 [ 1 ] ;
V_29 -> type = V_85 ;
V_29 -> V_72 = V_86 ;
V_29 -> V_51 = 2 ;
V_29 -> V_56 = V_66 -> V_56 ;
V_29 -> V_76 = & V_87 ;
V_29 -> V_88 = F_27 ;
V_29 -> V_78 = F_32 ;
V_29 = & V_2 -> V_70 [ 2 ] ;
V_29 -> type = V_89 ;
V_29 -> V_72 = V_73 ;
V_29 -> V_51 = 8 ;
V_29 -> V_56 = 1 ;
V_29 -> V_76 = & V_90 ;
V_29 -> V_91 = F_33 ;
V_29 = & V_2 -> V_70 [ 3 ] ;
V_29 -> type = V_92 ;
V_29 -> V_72 = V_86 ;
V_29 -> V_51 = 8 ;
V_29 -> V_56 = 1 ;
V_29 -> V_76 = & V_90 ;
V_29 -> V_91 = F_34 ;
return 0 ;
}
