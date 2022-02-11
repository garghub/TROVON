static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_19 ;
int V_20 ;
int V_21 ;
int V_22 , V_23 ;
int V_24 ;
V_20 = F_5 ( V_6 -> V_25 ) ;
V_21 = F_6 ( V_6 -> V_25 ) ;
F_2 ( V_2 -> V_9 + V_26 ) ;
F_2 ( V_2 -> V_9 + V_27 ) ;
F_7 ( & V_2 -> V_28 ) ;
V_17 -> V_29 &= ~ V_30 ;
V_17 -> V_29 |= F_8 ( V_20 ) ;
F_9 ( V_17 -> V_29 , V_2 -> V_9 + V_31 ) ;
F_10 ( & V_2 -> V_28 ) ;
if ( V_4 -> V_32 -> V_33 > 1 ) {
V_21 = F_6 ( V_6 -> V_25 ) ;
F_9 ( V_17 -> V_34 [ V_21 ] ,
V_2 -> V_9 + V_35 ) ;
}
for ( V_19 = 0 ; V_19 < V_6 -> V_19 ; V_19 ++ ) {
if ( V_15 -> V_36 == 16 )
if ( F_2 ( V_2 -> V_9 + V_27 ) & 0x80 )
F_11 ( V_2 -> V_37 , L_1 ) ;
F_12 ( 0 , V_2 -> V_9 + V_38 ) ;
V_24 = F_13 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_24 )
return V_24 ;
V_23 = F_2 ( V_2 -> V_9 + V_27 ) ;
V_22 = F_2 ( V_2 -> V_9 + V_26 ) ;
if ( V_15 -> V_39 == V_40 ) {
V_13 [ V_19 ] = ( V_22 >> 4 ) | ( V_23 << 4 ) ;
} else if ( V_15 -> V_39 == V_41 ) {
V_13 [ V_19 ] = ( V_23 << 8 ) + V_22 ;
} else if ( V_15 -> V_39 == V_42 ) {
if ( V_23 & 0x80 )
V_13 [ V_19 ] = ( 1 << 15 ) | V_22 | ( ( V_23 & 0x7f ) << 8 ) ;
else
V_13 [ V_19 ] = ( 1 << 15 ) - ( V_22 | ( V_23 & 0x7f ) << 8 ) ;
} else {
F_14 ( V_2 , L_2 ) ;
return - 1 ;
}
}
return V_19 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 0 ] = 0 ;
V_13 [ 1 ] = F_16 ( F_2 ( V_2 -> V_9 + V_10 ) ) ;
return V_6 -> V_19 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
if ( F_18 ( V_4 , V_13 ) ) {
F_7 ( & V_2 -> V_28 ) ;
V_17 -> V_29 &= ~ V_43 ;
V_17 -> V_29 |= F_19 ( V_4 -> V_44 ) ;
F_9 ( V_17 -> V_29 , V_2 -> V_9 + V_31 ) ;
F_10 ( & V_2 -> V_28 ) ;
}
V_13 [ 1 ] = V_4 -> V_44 ;
return V_6 -> V_19 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 0 ] = 0 ;
V_13 [ 1 ] = F_2 ( V_2 -> V_9 + V_45 ) ;
return V_6 -> V_19 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
if ( F_18 ( V_4 , V_13 ) )
F_9 ( V_4 -> V_44 , V_2 -> V_9 + V_45 ) ;
V_13 [ 1 ] = V_4 -> V_44 ;
return V_6 -> V_19 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int V_20 , unsigned int V_13 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned char V_22 ;
unsigned char V_23 ;
V_22 = V_13 & 0xff ;
V_23 = ( V_13 >> 8 ) & 0xff ;
if ( V_15 -> V_46 ) {
F_9 ( V_22 , V_2 -> V_9 + F_23 ( V_20 ) ) ;
F_9 ( V_23 , V_2 -> V_9 + F_24 ( V_20 ) ) ;
F_2 ( V_2 -> V_9 + V_45 ) ;
} else {
F_9 ( V_22 , V_2 -> V_9 + F_25 ( V_20 ) ) ;
F_9 ( V_23 , V_2 -> V_9 + F_26 ( V_20 ) ) ;
F_2 ( V_2 -> V_9 + V_47 ) ;
}
V_17 -> V_48 [ V_20 ] = V_13 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_19 ;
unsigned int V_13 ;
V_13 = V_4 -> V_49 / 2 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_50 ; V_19 ++ )
F_22 ( V_2 , V_19 , V_13 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
unsigned int V_19 ;
unsigned int V_20 ;
V_20 = F_5 ( V_6 -> V_25 ) ;
for ( V_19 = 0 ; V_19 < V_6 -> V_19 ; V_19 ++ )
F_22 ( V_2 , V_20 , * V_13 ) ;
return V_19 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_19 ;
unsigned int V_20 ;
V_20 = F_5 ( V_6 -> V_25 ) ;
for ( V_19 = 0 ; V_19 < V_6 -> V_19 ; V_19 ++ )
V_13 [ V_19 ] = V_17 -> V_48 [ V_20 ] ;
return V_19 ;
}
static void F_30 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_9 + V_15 -> V_52 ;
unsigned int V_53 = V_54 | V_55 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < 3 ; ++ V_56 )
F_31 ( V_51 , 0 , V_56 , V_53 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_9 + V_15 -> V_52 ;
int V_20 = V_6 -> V_25 ;
V_13 [ 0 ] = F_33 ( V_51 , 0 , V_20 ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_9 + V_15 -> V_52 ;
int V_20 = V_6 -> V_25 ;
F_35 ( V_51 , 0 , V_20 , V_13 [ 0 ] ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
unsigned long V_51 = V_2 -> V_9 + V_15 -> V_52 ;
int V_20 = V_6 -> V_25 ;
switch ( V_13 [ 0 ] ) {
case V_57 :
F_31 ( V_51 , 0 , V_20 , V_13 [ 1 ] ) ;
break;
case V_58 :
V_13 [ 1 ] = F_37 ( V_51 , 0 , V_20 ) ;
break;
default:
return - V_59 ;
break;
}
return 2 ;
}
int F_38 ( struct V_1 * V_2 , unsigned long V_9 )
{
const struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_3 * V_4 ;
int V_24 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_60 = V_15 -> V_61 ;
V_24 = F_39 ( V_2 , 6 ) ;
if ( V_24 )
return V_24 ;
V_4 = & V_2 -> V_62 [ 0 ] ;
if ( V_15 -> V_36 ) {
V_4 -> type = V_63 ;
V_4 -> V_64 = V_65 | V_66 ;
V_4 -> V_50 = 8 ;
V_4 -> V_49 = ( 1 << V_15 -> V_36 ) - 1 ;
V_4 -> V_32 = V_67 [ V_15 -> V_68 ] ;
V_4 -> V_69 = F_3 ;
V_17 -> V_34 = V_70 [ V_15 -> V_68 ] ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 1 ] ;
if ( V_15 -> V_72 ) {
V_4 -> type = V_73 ;
V_4 -> V_64 = V_74 ;
V_4 -> V_50 = 2 ;
V_4 -> V_49 = ( 1 << V_15 -> V_72 ) - 1 ;
V_4 -> V_32 = & V_75 ;
V_4 -> V_76 = F_28 ;
V_4 -> V_69 = F_29 ;
F_27 ( V_2 , V_4 ) ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 2 ] ;
if ( V_15 -> V_77 ) {
V_4 -> type = V_78 ;
V_4 -> V_64 = V_65 ;
V_4 -> V_50 = V_15 -> V_77 ;
V_4 -> V_49 = 1 ;
V_4 -> V_32 = & V_79 ;
V_4 -> V_80 =
V_15 -> V_46 ? F_20 : F_15 ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 3 ] ;
if ( V_15 -> V_81 ) {
V_4 -> type = V_82 ;
V_4 -> V_64 = V_74 | V_65 ;
V_4 -> V_50 = V_15 -> V_81 ;
V_4 -> V_49 = 1 ;
V_4 -> V_32 = & V_79 ;
V_4 -> V_80 =
V_15 -> V_46 ? F_21 : F_17 ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 4 ] ;
if ( V_15 -> V_83 != 0 ) {
V_24 = F_40 ( V_2 , V_4 , NULL ,
V_2 -> V_9 + V_15 -> V_83 ) ;
if ( V_24 )
return V_24 ;
} else {
V_4 -> type = V_71 ;
}
V_4 = & V_2 -> V_62 [ 5 ] ;
if ( V_15 -> V_52 != 0 ) {
V_4 -> type = V_84 ;
V_4 -> V_64 = V_74 | V_65 ;
V_4 -> V_50 = 3 ;
V_4 -> V_49 = 0xFFFF ;
V_4 -> V_69 = F_32 ;
V_4 -> V_76 = F_34 ;
V_4 -> V_85 = F_36 ;
F_30 ( V_2 ) ;
} else {
V_4 -> type = V_71 ;
}
return 0 ;
}
static int T_1 F_41 ( void )
{
return 0 ;
}
static void T_2 F_42 ( void )
{
}
