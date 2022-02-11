static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
int V_12 = F_2 ( V_6 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ ) {
F_3 ( ( ( V_12 & 15 ) << 1 ) | ( ( V_12 & 16 ) >> 4 ) ,
V_9 -> V_15 -> V_16 + V_17 ) ;
F_3 ( V_7 [ V_11 ] , V_9 -> V_15 -> V_16 + V_18 ) ;
V_9 -> V_19 [ V_12 ] = V_7 [ V_11 ] ;
}
return V_11 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
int V_12 = F_2 ( V_6 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ )
V_7 [ V_11 ] = V_9 -> V_19 [ V_12 ] ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
void T_1 * V_20 = V_9 -> V_15 -> V_16 +
V_21 ;
unsigned int V_22 = V_7 [ 0 ] ;
unsigned int V_23 = V_7 [ 1 ] ;
if ( V_22 ) {
V_4 -> V_24 &= ~ V_22 ;
V_4 -> V_24 |= ( V_23 & V_22 ) ;
F_3 ( V_4 -> V_24 , V_20 ) ;
}
V_7 [ 1 ] = F_6 ( V_20 ) ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_12 = F_2 ( V_6 -> V_13 ) ;
switch ( V_7 [ 0 ] ) {
case V_25 :
V_4 -> V_26 |= 1 << V_12 ;
break;
case V_27 :
V_4 -> V_26 &= ~ ( 1 << V_12 ) ;
break;
case V_28 :
V_7 [ 1 ] =
( V_4 -> V_26 & ( 1 << V_12 ) ) ? V_29 : V_30 ;
return V_6 -> V_14 ;
break;
default:
return - V_31 ;
break;
}
F_3 ( V_4 -> V_26 , V_9 -> V_15 -> V_16 + V_32 ) ;
return V_6 -> V_14 ;
}
static int F_8 ( struct V_1 * V_2 , int V_33 , int V_34 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_35 * V_15 ;
int V_11 ;
for ( V_15 = V_36 ; V_15 ; V_15 = V_15 -> V_37 ) {
if ( V_15 -> V_38 )
continue;
if ( V_33 || V_34 ) {
if ( V_33 != V_15 -> V_39 -> V_33 -> V_40
|| V_34 != F_9 ( V_15 -> V_39 -> V_41 ) )
continue;
}
for ( V_11 = 0 ; V_11 < F_10 ( V_42 ) ; V_11 ++ ) {
if ( F_11 ( V_15 ) == V_42 [ V_11 ] . V_43 ) {
V_2 -> V_44 = V_42 + V_11 ;
V_9 -> V_15 = V_15 ;
return 0 ;
}
}
}
F_12 ( V_2 -> V_45 , L_1 ) ;
F_13 () ;
return - V_46 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
const struct V_49 * V_50 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_51 ;
int V_11 ;
V_51 = F_15 ( V_2 , sizeof( * V_9 ) ) ;
if ( V_51 < 0 )
return V_51 ;
V_9 = V_2 -> V_10 ;
V_51 = F_8 ( V_2 , V_48 -> V_52 [ 0 ] , V_48 -> V_52 [ 1 ] ) ;
if ( V_51 < 0 )
return V_51 ;
V_50 = F_16 ( V_2 ) ;
V_51 = F_17 ( V_9 -> V_15 ) ;
if ( V_51 < 0 ) {
F_12 ( V_2 -> V_45 , L_2 ) ;
return V_51 ;
}
V_2 -> V_53 = V_50 -> V_54 ;
V_2 -> V_55 = F_18 ( V_9 -> V_15 ) ;
V_51 = F_19 ( V_2 , 2 ) ;
if ( V_51 )
return V_51 ;
V_4 = V_2 -> V_56 + 0 ;
V_4 -> type = V_57 ;
V_4 -> V_58 = V_59 ;
V_4 -> V_60 = V_50 -> V_61 ;
V_4 -> V_62 = 0xffff ;
if ( V_4 -> V_60 == 32 ) {
const struct V_63 * * V_64 ;
V_64 = F_20 ( sizeof( struct V_63 * ) * 32 ,
V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_4 -> V_64 = V_64 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_64 [ V_11 ] = & V_67 ;
V_64 [ 16 + V_11 ] = & V_68 ;
}
} else {
V_4 -> V_69 = & V_67 ;
}
V_4 -> V_70 = & F_1 ;
V_4 -> V_71 = & F_4 ;
V_4 = V_2 -> V_56 + 1 ;
V_4 -> type = V_72 ;
V_4 -> V_58 = V_73 | V_59 ;
V_4 -> V_60 = 8 ;
V_4 -> V_62 = 1 ;
V_4 -> V_69 = & V_74 ;
V_4 -> V_75 = F_5 ;
V_4 -> V_76 = F_7 ;
F_3 ( 0x10 , V_9 -> V_15 -> V_16 + V_77 ) ;
F_3 ( 0x00 , V_9 -> V_15 -> V_16 + V_78 ) ;
F_21 ( V_2 -> V_45 , L_3 ,
V_2 -> V_79 -> V_80 , V_2 -> V_53 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 ;
if ( V_2 -> V_81 ) {
V_4 = V_2 -> V_56 + 0 ;
if ( V_4 )
F_23 ( V_4 -> V_64 ) ;
}
if ( V_9 && V_9 -> V_15 )
F_24 ( V_9 -> V_15 ) ;
if ( V_2 -> V_55 )
F_25 ( V_2 -> V_55 , V_2 ) ;
}
static int T_2 F_26 ( struct V_82 * V_2 ,
const struct V_83 * V_84 )
{
return F_27 ( V_2 , & V_85 ) ;
}
static void T_3 F_28 ( struct V_82 * V_2 )
{
F_29 ( V_2 ) ;
}
