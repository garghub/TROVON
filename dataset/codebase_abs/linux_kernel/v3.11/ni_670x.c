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
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_33 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
const struct V_36 * V_37 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_38 ;
int V_11 ;
if ( V_33 < F_10 ( V_39 ) )
V_37 = & V_39 [ V_33 ] ;
if ( ! V_37 )
return - V_40 ;
V_2 -> V_41 = V_37 ;
V_2 -> V_42 = V_37 -> V_43 ;
V_38 = F_11 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 )
return - V_45 ;
V_2 -> V_10 = V_9 ;
V_9 -> V_15 = F_13 ( V_35 ) ;
if ( ! V_9 -> V_15 )
return - V_45 ;
V_38 = F_14 ( V_9 -> V_15 ) ;
if ( V_38 < 0 ) {
F_15 ( V_2 -> V_46 , L_1 ) ;
return V_38 ;
}
V_38 = F_16 ( V_2 , 2 ) ;
if ( V_38 )
return V_38 ;
V_4 = & V_2 -> V_47 [ 0 ] ;
V_4 -> type = V_48 ;
V_4 -> V_49 = V_50 ;
V_4 -> V_51 = V_37 -> V_52 ;
V_4 -> V_53 = 0xffff ;
if ( V_4 -> V_51 == 32 ) {
const struct V_54 * * V_55 ;
V_55 = F_17 ( sizeof( struct V_54 * ) * 32 ,
V_44 ) ;
if ( ! V_55 )
return - V_45 ;
V_4 -> V_55 = V_55 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_55 [ V_11 ] = & V_56 ;
V_55 [ 16 + V_11 ] = & V_57 ;
}
} else {
V_4 -> V_58 = & V_56 ;
}
V_4 -> V_59 = & F_1 ;
V_4 -> V_60 = & F_4 ;
V_4 = & V_2 -> V_47 [ 1 ] ;
V_4 -> type = V_61 ;
V_4 -> V_49 = V_62 | V_50 ;
V_4 -> V_51 = 8 ;
V_4 -> V_53 = 1 ;
V_4 -> V_58 = & V_63 ;
V_4 -> V_64 = F_5 ;
V_4 -> V_65 = F_7 ;
F_3 ( 0x10 , V_9 -> V_15 -> V_16 + V_66 ) ;
F_3 ( 0x00 , V_9 -> V_15 -> V_16 + V_67 ) ;
F_18 ( V_2 -> V_46 , L_2 ,
V_2 -> V_68 -> V_69 , V_2 -> V_42 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 ;
if ( V_2 -> V_70 ) {
V_4 = & V_2 -> V_47 [ 0 ] ;
if ( V_4 )
F_20 ( V_4 -> V_55 ) ;
}
if ( V_9 && V_9 -> V_15 ) {
F_21 ( V_9 -> V_15 ) ;
F_22 ( V_9 -> V_15 ) ;
}
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_34 * V_2 ,
const struct V_71 * V_72 )
{
return F_25 ( V_2 , & V_73 , V_72 -> V_74 ) ;
}
