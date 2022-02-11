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
static const struct V_33 *
F_8 ( struct V_34 * V_35 )
{
unsigned int V_36 = V_35 -> V_37 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_9 ( V_38 ) ; V_14 ++ ) {
const struct V_33 * V_39 = & V_38 [ V_14 ] ;
if ( V_39 -> V_36 == V_36 )
return V_39 ;
}
return NULL ;
}
static int T_2 F_10 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
const struct V_33 * V_40 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_41 ;
int V_11 ;
V_41 = F_11 ( V_2 , sizeof( * V_9 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_9 = V_2 -> V_10 ;
V_2 -> V_42 = F_8 ( V_35 ) ;
if ( ! V_2 -> V_42 )
return - V_43 ;
V_9 -> V_15 = F_12 ( V_35 ) ;
if ( ! V_9 -> V_15 )
return - V_44 ;
V_40 = F_13 ( V_2 ) ;
V_41 = F_14 ( V_9 -> V_15 ) ;
if ( V_41 < 0 ) {
F_15 ( V_2 -> V_45 , L_1 ) ;
return V_41 ;
}
V_2 -> V_46 = V_40 -> V_47 ;
V_41 = F_16 ( V_2 , 2 ) ;
if ( V_41 )
return V_41 ;
V_4 = & V_2 -> V_48 [ 0 ] ;
V_4 -> type = V_49 ;
V_4 -> V_50 = V_51 ;
V_4 -> V_52 = V_40 -> V_53 ;
V_4 -> V_54 = 0xffff ;
if ( V_4 -> V_52 == 32 ) {
const struct V_55 * * V_56 ;
V_56 = F_17 ( sizeof( struct V_55 * ) * 32 ,
V_57 ) ;
if ( ! V_56 )
return - V_44 ;
V_4 -> V_56 = V_56 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_56 [ V_11 ] = & V_58 ;
V_56 [ 16 + V_11 ] = & V_59 ;
}
} else {
V_4 -> V_60 = & V_58 ;
}
V_4 -> V_61 = & F_1 ;
V_4 -> V_62 = & F_4 ;
V_4 = & V_2 -> V_48 [ 1 ] ;
V_4 -> type = V_63 ;
V_4 -> V_50 = V_64 | V_51 ;
V_4 -> V_52 = 8 ;
V_4 -> V_54 = 1 ;
V_4 -> V_60 = & V_65 ;
V_4 -> V_66 = F_5 ;
V_4 -> V_67 = F_7 ;
F_3 ( 0x10 , V_9 -> V_15 -> V_16 + V_68 ) ;
F_3 ( 0x00 , V_9 -> V_15 -> V_16 + V_69 ) ;
F_18 ( V_2 -> V_45 , L_2 ,
V_2 -> V_70 -> V_71 , V_2 -> V_46 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 ;
if ( V_2 -> V_72 ) {
V_4 = & V_2 -> V_48 [ 0 ] ;
if ( V_4 )
F_20 ( V_4 -> V_56 ) ;
}
if ( V_9 && V_9 -> V_15 ) {
F_21 ( V_9 -> V_15 ) ;
F_22 ( V_9 -> V_15 ) ;
}
}
static int T_2 F_23 ( struct V_34 * V_2 ,
const struct V_73 * V_74 )
{
return F_24 ( V_2 , & V_75 ) ;
}
static void T_3 F_25 ( struct V_34 * V_2 )
{
F_26 ( V_2 ) ;
}
