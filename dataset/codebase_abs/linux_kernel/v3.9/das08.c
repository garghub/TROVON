static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 , V_14 ;
int V_15 ;
int V_16 ;
int V_17 , V_18 ;
V_15 = F_3 ( V_6 -> V_19 ) ;
V_16 = F_4 ( V_6 -> V_19 ) ;
F_5 ( V_2 -> V_20 + V_21 ) ;
F_5 ( V_2 -> V_20 + V_22 ) ;
F_6 ( & V_2 -> V_23 ) ;
V_11 -> V_24 &= ~ V_25 ;
V_11 -> V_24 |= F_7 ( V_15 ) ;
F_8 ( V_11 -> V_24 , V_2 -> V_20 + V_26 ) ;
F_9 ( & V_2 -> V_23 ) ;
if ( V_4 -> V_27 -> V_28 > 1 ) {
V_16 = F_4 ( V_6 -> V_19 ) ;
F_8 ( V_11 -> V_29 [ V_16 ] ,
V_2 -> V_20 + V_30 ) ;
}
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ ) {
if ( V_9 -> V_31 == 16 )
if ( F_5 ( V_2 -> V_20 + V_22 ) & 0x80 )
F_10 ( V_2 -> V_32 , L_1 ) ;
F_11 ( 0 , V_2 -> V_20 + V_33 ) ;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ ) {
if ( ! ( F_5 ( V_2 -> V_20 + V_35 ) & V_36 ) )
break;
}
if ( V_13 == V_34 ) {
F_12 ( V_2 -> V_32 , L_2 ) ;
return - V_37 ;
}
V_18 = F_5 ( V_2 -> V_20 + V_22 ) ;
V_17 = F_5 ( V_2 -> V_20 + V_21 ) ;
if ( V_9 -> V_38 == V_39 ) {
V_7 [ V_14 ] = ( V_17 >> 4 ) | ( V_18 << 4 ) ;
} else if ( V_9 -> V_38 == V_40 ) {
V_7 [ V_14 ] = ( V_18 << 8 ) + V_17 ;
} else if ( V_9 -> V_38 == V_41 ) {
if ( V_18 & 0x80 )
V_7 [ V_14 ] = ( 1 << 15 ) | V_17 | ( ( V_18 & 0x7f ) << 8 ) ;
else
V_7 [ V_14 ] = ( 1 << 15 ) - ( V_17 | ( V_18 & 0x7f ) << 8 ) ;
} else {
F_13 ( V_2 , L_3 ) ;
return - 1 ;
}
}
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_15 ( F_5 ( V_2 -> V_20 + V_35 ) ) ;
return V_6 -> V_14 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_42 ;
V_42 = ( V_11 -> V_24 >> 4 ) & 0xf ;
V_42 &= ~ V_7 [ 0 ] ;
V_42 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_6 ( & V_2 -> V_23 ) ;
V_11 -> V_24 &= ~ V_43 ;
V_11 -> V_24 |= F_17 ( V_42 ) ;
F_8 ( V_11 -> V_24 , V_2 -> V_20 + V_26 ) ;
F_9 ( & V_2 -> V_23 ) ;
V_7 [ 1 ] = V_42 ;
return V_6 -> V_14 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = 0 ;
V_7 [ 1 ] = F_5 ( V_2 -> V_20 + V_44 ) ;
return V_6 -> V_14 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_45 &= ~ V_7 [ 0 ] ;
V_11 -> V_45 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_8 ( V_11 -> V_45 , V_2 -> V_20 + V_44 ) ;
V_7 [ 1 ] = V_11 -> V_45 ;
return V_6 -> V_14 ;
}
static void F_20 ( struct V_1 * V_2 ,
unsigned int V_15 , unsigned int V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned char V_17 ;
unsigned char V_18 ;
V_17 = V_7 & 0xff ;
V_18 = ( V_7 >> 8 ) & 0xff ;
if ( V_9 -> V_46 ) {
F_8 ( V_17 , V_2 -> V_20 + F_21 ( V_15 ) ) ;
F_8 ( V_18 , V_2 -> V_20 + F_22 ( V_15 ) ) ;
F_5 ( V_2 -> V_20 + V_44 ) ;
} else {
F_8 ( V_17 , V_2 -> V_20 + F_23 ( V_15 ) ) ;
F_8 ( V_18 , V_2 -> V_20 + F_24 ( V_15 ) ) ;
F_5 ( V_2 -> V_20 + V_47 ) ;
}
V_11 -> V_48 [ V_15 ] = V_7 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_14 ;
unsigned int V_7 ;
V_7 = V_4 -> V_49 / 2 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_50 ; V_14 ++ )
F_20 ( V_2 , V_14 , V_7 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_14 ;
unsigned int V_15 ;
V_15 = F_3 ( V_6 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ )
F_20 ( V_2 , V_15 , * V_7 ) ;
return V_14 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_14 ;
unsigned int V_15 ;
V_15 = F_3 ( V_6 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_14 ; V_14 ++ )
V_7 [ V_14 ] = V_11 -> V_48 [ V_15 ] ;
return V_14 ;
}
static void F_28 ( struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_20 + V_9 -> V_52 ;
unsigned int V_53 = V_54 | V_55 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 3 ; ++ V_13 )
F_29 ( V_51 , 0 , V_13 , V_53 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_20 + V_9 -> V_52 ;
int V_15 = V_6 -> V_19 ;
V_7 [ 0 ] = F_31 ( V_51 , 0 , V_15 ) ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_20 + V_9 -> V_52 ;
int V_15 = V_6 -> V_19 ;
F_33 ( V_51 , 0 , V_15 , V_7 [ 0 ] ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_20 + V_9 -> V_52 ;
int V_15 = V_6 -> V_19 ;
switch ( V_7 [ 0 ] ) {
case V_56 :
F_29 ( V_51 , 0 , V_15 , V_7 [ 1 ] ) ;
break;
case V_57 :
V_7 [ 1 ] = F_35 ( V_51 , 0 , V_15 ) ;
break;
default:
return - V_58 ;
break;
}
return 2 ;
}
int F_36 ( struct V_1 * V_2 , unsigned long V_20 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_3 * V_4 ;
int V_59 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_60 = V_9 -> V_61 ;
V_59 = F_37 ( V_2 , 6 ) ;
if ( V_59 )
return V_59 ;
V_4 = & V_2 -> V_62 [ 0 ] ;
if ( V_9 -> V_31 ) {
V_4 -> type = V_63 ;
V_4 -> V_64 = V_65 | V_66 ;
V_4 -> V_50 = 8 ;
V_4 -> V_49 = ( 1 << V_9 -> V_31 ) - 1 ;
V_4 -> V_27 = V_67 [ V_9 -> V_68 ] ;
V_4 -> V_69 = F_1 ;
V_11 -> V_29 = V_70 [ V_9 -> V_68 ] ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 1 ] ;
if ( V_9 -> V_72 ) {
V_4 -> type = V_73 ;
V_4 -> V_64 = V_74 ;
V_4 -> V_50 = 2 ;
V_4 -> V_49 = ( 1 << V_9 -> V_72 ) - 1 ;
V_4 -> V_27 = & V_75 ;
V_4 -> V_76 = F_26 ;
V_4 -> V_69 = F_27 ;
F_25 ( V_2 , V_4 ) ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 2 ] ;
if ( V_9 -> V_77 ) {
V_4 -> type = V_78 ;
V_4 -> V_64 = V_65 ;
V_4 -> V_50 = V_9 -> V_77 ;
V_4 -> V_49 = 1 ;
V_4 -> V_27 = & V_79 ;
V_4 -> V_80 =
V_9 -> V_46 ? F_18 : F_14 ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 3 ] ;
if ( V_9 -> V_81 ) {
V_4 -> type = V_82 ;
V_4 -> V_64 = V_74 | V_65 ;
V_4 -> V_50 = V_9 -> V_81 ;
V_4 -> V_49 = 1 ;
V_4 -> V_27 = & V_79 ;
V_4 -> V_80 =
V_9 -> V_46 ? F_19 : F_16 ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 4 ] ;
if ( V_9 -> V_83 != 0 ) {
F_38 ( V_2 , V_4 , NULL , ( unsigned long ) ( V_2 -> V_20 +
V_9 ->
V_83 ) ) ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 5 ] ;
if ( V_9 -> V_52 != 0 ) {
V_4 -> type = V_84 ;
V_4 -> V_64 = V_74 | V_65 ;
V_4 -> V_50 = 3 ;
V_4 -> V_49 = 0xFFFF ;
V_4 -> V_69 = F_30 ;
V_4 -> V_76 = F_32 ;
V_4 -> V_85 = F_34 ;
F_28 ( V_2 ) ;
} else {
V_4 -> type = V_71 ;
}
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_62 )
F_40 ( V_2 , & V_2 -> V_62 [ 4 ] ) ;
}
static int T_1 F_41 ( void )
{
return 0 ;
}
static void T_2 F_42 ( void )
{
}
