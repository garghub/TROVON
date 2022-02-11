static int F_1 ( unsigned int * V_1 , int V_2 )
{
return * V_1 ;
}
static int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
const struct V_10 * V_11 = F_3 ( V_4 ) ;
int V_12 , V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_12 ; V_12 ++ ) {
#define F_4 100
for ( V_13 = 0 ; V_13 < F_4 ; V_13 ++ ) {
V_15 = 1 ;
if ( V_15 )
break;
}
if ( V_13 == F_4 ) {
F_5 ( V_4 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_14 = 0 ;
V_14 ^= 1 << ( V_11 -> V_18 - 1 ) ;
V_9 [ V_12 ] = V_14 ;
}
return V_12 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
int V_22 ;
V_21 |= F_7 ( & V_20 -> V_23 , V_24 ) ;
V_21 |= F_7 ( & V_20 -> V_25 ,
V_26 | V_27 ) ;
V_21 |= F_7 ( & V_20 -> V_28 , V_26 | V_27 ) ;
V_21 |= F_7 ( & V_20 -> V_29 , V_30 ) ;
V_21 |= F_7 ( & V_20 -> V_31 , V_30 | V_32 ) ;
if ( V_21 )
return 1 ;
V_21 |= F_8 ( V_20 -> V_25 ) ;
V_21 |= F_8 ( V_20 -> V_28 ) ;
V_21 |= F_8 ( V_20 -> V_31 ) ;
if ( V_21 )
return 2 ;
V_21 |= F_9 ( & V_20 -> V_33 , 0 ) ;
#define F_10 10000
#define F_11 1000000000
if ( V_20 -> V_25 == V_26 ) {
V_21 |= F_12 ( & V_20 -> V_34 ,
F_10 ) ;
V_21 |= F_13 ( & V_20 -> V_34 ,
F_11 ) ;
} else {
V_21 |= F_13 ( & V_20 -> V_34 , 9 ) ;
}
if ( V_20 -> V_28 == V_26 ) {
V_21 |= F_12 ( & V_20 -> V_35 , F_10 ) ;
V_21 |= F_13 ( & V_20 -> V_35 , F_11 ) ;
} else {
V_21 |= F_13 ( & V_20 -> V_34 , 9 ) ;
}
V_21 |= F_9 ( & V_20 -> V_36 , V_20 -> V_37 ) ;
if ( V_20 -> V_31 == V_30 )
V_21 |= F_13 ( & V_20 -> V_38 , 0x00ffffff ) ;
else
V_21 |= F_9 ( & V_20 -> V_38 , 0 ) ;
if ( V_21 )
return 3 ;
if ( V_20 -> V_25 == V_26 ) {
V_22 = V_20 -> V_34 ;
F_1 ( & V_20 -> V_34 ,
V_20 -> V_39 & V_40 ) ;
if ( V_22 != V_20 -> V_34 )
V_21 ++ ;
}
if ( V_20 -> V_28 == V_26 ) {
V_22 = V_20 -> V_35 ;
F_1 ( & V_20 -> V_35 ,
V_20 -> V_39 & V_40 ) ;
if ( V_22 != V_20 -> V_35 )
V_21 ++ ;
if ( V_20 -> V_25 == V_26 &&
V_20 -> V_34 <
V_20 -> V_35 * V_20 -> V_36 ) {
V_20 -> V_34 =
V_20 -> V_35 * V_20 -> V_36 ;
V_21 ++ ;
}
}
if ( V_21 )
return 4 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
int V_13 ;
int V_44 = F_15 ( V_8 -> V_45 ) ;
for ( V_13 = 0 ; V_13 < V_8 -> V_12 ; V_13 ++ ) {
V_42 -> V_46 [ V_44 ] = V_9 [ V_13 ] ;
}
return V_13 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_41 * V_42 = V_4 -> V_43 ;
int V_13 ;
int V_44 = F_15 ( V_8 -> V_45 ) ;
for ( V_13 = 0 ; V_13 < V_8 -> V_12 ; V_13 ++ )
V_9 [ V_13 ] = V_42 -> V_46 [ V_44 ] ;
return V_13 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
if ( V_9 [ 0 ] ) {
V_6 -> V_47 &= ~ V_9 [ 0 ] ;
V_6 -> V_47 |= V_9 [ 0 ] & V_9 [ 1 ] ;
}
return V_8 -> V_12 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
int V_44 = F_15 ( V_8 -> V_45 ) ;
switch ( V_9 [ 0 ] ) {
case V_48 :
V_6 -> V_49 |= 1 << V_44 ;
break;
case V_50 :
V_6 -> V_49 &= ~ ( 1 << V_44 ) ;
break;
case V_51 :
V_9 [ 1 ] =
( V_6 -> V_49 & ( 1 << V_44 ) ) ? V_52 : V_53 ;
return V_8 -> V_12 ;
break;
default:
return - V_54 ;
break;
}
return V_8 -> V_12 ;
}
static int F_19 ( struct V_3 * V_4 )
{
const struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_5 * V_6 ;
int V_55 ;
V_55 = F_20 ( V_4 , 3 ) ;
if ( V_55 )
return V_55 ;
V_6 = & V_4 -> V_56 [ 0 ] ;
V_6 -> type = V_57 ;
V_6 -> V_58 = V_59 | V_60 | V_61 ;
V_6 -> V_62 = V_11 -> V_63 ;
V_6 -> V_64 = ( 1 << V_11 -> V_18 ) - 1 ;
V_6 -> V_65 = & V_66 ;
V_6 -> V_67 = 16 ;
V_6 -> V_68 = F_2 ;
V_6 -> V_69 = F_6 ;
V_6 = & V_4 -> V_56 [ 1 ] ;
V_6 -> type = V_70 ;
V_6 -> V_58 = V_71 ;
V_6 -> V_62 = 1 ;
V_6 -> V_64 = 0xffff ;
V_6 -> V_65 = & V_72 ;
V_6 -> V_73 = F_14 ;
V_6 -> V_68 = F_16 ;
V_6 = & V_4 -> V_56 [ 2 ] ;
if ( V_11 -> V_74 ) {
V_6 -> type = V_75 ;
V_6 -> V_58 = V_59 | V_71 ;
V_6 -> V_62 = 16 ;
V_6 -> V_64 = 1 ;
V_6 -> V_65 = & V_76 ;
V_6 -> V_77 = F_17 ;
V_6 -> V_78 = F_18 ;
} else {
V_6 -> type = V_79 ;
}
F_21 ( V_4 -> V_16 , L_2 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , struct V_80 * V_81 )
{
const struct V_10 * V_11 ;
struct V_41 * V_42 ;
V_11 = F_3 ( V_4 ) ;
V_42 = F_23 ( sizeof( * V_42 ) , V_82 ) ;
if ( ! V_42 )
return - V_83 ;
V_4 -> V_43 = V_42 ;
return F_19 ( V_4 ) ;
}
static int F_24 ( struct V_3 * V_4 ,
unsigned long V_84 )
{
struct V_85 * V_86 = F_25 ( V_4 ) ;
const struct V_10 * V_11 = NULL ;
struct V_41 * V_42 ;
int V_55 ;
if ( ! F_26 ( V_87 ) )
return - V_54 ;
if ( V_84 < F_27 ( V_88 ) )
V_11 = & V_88 [ V_84 ] ;
if ( ! V_11 )
return - V_89 ;
V_4 -> V_90 = V_11 ;
V_4 -> V_91 = V_11 -> V_92 ;
V_42 = F_23 ( sizeof( * V_42 ) , V_82 ) ;
if ( ! V_42 )
return - V_83 ;
V_4 -> V_43 = V_42 ;
V_55 = F_28 ( V_4 ) ;
if ( V_55 )
return V_55 ;
V_4 -> V_93 = F_29 ( V_86 , 0 ) ;
return F_19 ( V_4 ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
const struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_41 * V_42 = V_4 -> V_43 ;
if ( ! V_11 || ! V_42 )
return;
if ( F_26 ( V_87 ) ) {
F_31 ( V_4 ) ;
} else {
F_32 ( V_4 ) ;
}
}
static int F_33 ( struct V_85 * V_4 ,
const struct V_94 * V_95 )
{
return F_34 ( V_4 , & V_96 , V_95 -> V_97 ) ;
}
