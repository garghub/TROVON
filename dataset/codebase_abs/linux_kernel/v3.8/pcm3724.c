static int F_1 ( int V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
unsigned long V_5 = V_4 ;
unsigned char V_6 ;
if ( V_1 ) {
F_2 ( V_3 , V_5 + V_2 ) ;
return 0 ;
} else {
V_6 = F_3 ( V_5 + V_2 ) ;
return V_6 ;
}
}
static int F_4 ( int V_7 , int V_8 , struct V_9 * V_10 )
{
if ( V_10 -> V_11 & 0x0000ff ) {
if ( V_8 == 0 )
V_7 |= V_12 ;
else
V_7 |= V_13 ;
}
if ( V_10 -> V_11 & 0x00ff00 ) {
if ( V_8 == 0 )
V_7 |= V_14 ;
else
V_7 |= V_15 ;
}
if ( V_10 -> V_11 & 0xff0000 ) {
if ( V_8 == 0 )
V_7 |= V_16 ;
else
V_7 |= V_17 ;
}
return V_7 ;
}
static void F_5 ( struct V_18 * V_19 ,
struct V_9 * V_10 , int V_20 )
{
struct V_9 * V_21 = & V_19 -> V_22 [ 0 ] ;
struct V_9 * V_23 = & V_19 -> V_22 [ 1 ] ;
int V_7 ;
int V_24 ;
unsigned long V_25 ;
V_7 = V_26 ;
V_24 = 0 ;
if ( ! ( V_10 -> V_11 & 0x0000ff ) )
V_7 |= V_27 ;
if ( ! ( V_10 -> V_11 & 0x00ff00 ) )
V_7 |= V_28 ;
if ( ! ( V_10 -> V_11 & 0xff0000 ) )
V_7 |= V_29 ;
V_24 = F_4 ( 0 , 0 , V_21 ) ;
V_24 = F_4 ( V_24 , 1 , V_23 ) ;
if ( V_10 == V_21 )
V_25 = V_19 -> V_5 + V_30 ;
else
V_25 = V_19 -> V_5 + V_31 + V_30 ;
F_2 ( V_24 , V_19 -> V_5 + 8 ) ;
F_2 ( V_7 , V_25 ) ;
}
static void F_6 ( struct V_18 * V_19 , struct V_9 * V_10 ,
int V_20 )
{
struct V_32 * V_33 = V_19 -> V_34 ;
struct V_9 * V_21 = & V_19 -> V_22 [ 0 ] ;
unsigned int V_35 ;
int V_36 ;
V_36 = 0 ;
V_35 = 1 << F_7 ( V_20 ) ;
if ( V_10 == V_21 )
V_33 -> V_37 |= V_35 ;
else
V_33 -> V_38 |= V_35 ;
if ( V_33 -> V_37 & 0xff0000 )
V_36 |= V_39 ;
if ( V_33 -> V_37 & 0xff00 )
V_36 |= V_40 ;
if ( V_33 -> V_37 & 0xff )
V_36 |= V_41 ;
if ( V_33 -> V_38 & 0xff0000 )
V_36 |= V_42 ;
if ( V_33 -> V_38 & 0xff00 )
V_36 |= V_43 ;
if ( V_33 -> V_38 & 0xff )
V_36 |= V_44 ;
F_2 ( V_36 , V_19 -> V_5 + 9 ) ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
struct V_45 * V_46 , unsigned int * V_3 )
{
unsigned int V_35 ;
unsigned int V_47 ;
V_35 = 1 << F_7 ( V_46 -> V_20 ) ;
if ( V_35 & 0x0000ff )
V_47 = 0x0000ff ;
else if ( V_35 & 0x00ff00 )
V_47 = 0x00ff00 ;
else if ( V_35 & 0x0f0000 )
V_47 = 0x0f0000 ;
else
V_47 = 0xf00000 ;
switch ( V_3 [ 0 ] ) {
case V_48 :
V_10 -> V_11 &= ~ V_47 ;
break;
case V_49 :
V_10 -> V_11 |= V_47 ;
break;
case V_50 :
V_3 [ 1 ] = ( V_10 -> V_11 & V_47 ) ? V_51 : V_52 ;
return V_46 -> V_53 ;
break;
default:
return - V_54 ;
}
F_5 ( V_19 , V_10 , V_46 -> V_20 ) ;
F_6 ( V_19 , V_10 , V_46 -> V_20 ) ;
return 1 ;
}
static int F_9 ( struct V_18 * V_19 ,
struct V_55 * V_56 )
{
struct V_32 * V_33 ;
struct V_9 * V_10 ;
unsigned long V_5 ;
unsigned int V_57 ;
int V_58 , V_59 ;
V_19 -> V_60 = V_19 -> V_61 -> V_62 ;
V_5 = V_56 -> V_63 [ 0 ] ;
V_57 = V_64 ;
V_33 = F_10 ( sizeof( * V_33 ) , V_65 ) ;
if ( ! V_33 )
return - V_66 ;
V_19 -> V_34 = V_33 ;
F_11 ( V_67 L_1 , V_19 -> V_68 ,
V_19 -> V_60 , V_5 ) ;
if ( ! V_5 || ! F_12 ( V_5 , V_57 , L_2 ) ) {
F_11 ( L_3 ) ;
return - V_69 ;
}
V_19 -> V_5 = V_5 ;
F_11 ( V_67 L_4 ) ;
V_58 = F_13 ( V_19 , 2 ) ;
if ( V_58 )
return V_58 ;
for ( V_59 = 0 ; V_59 < V_19 -> V_70 ; V_59 ++ ) {
V_10 = & V_19 -> V_22 [ V_59 ] ;
F_14 ( V_19 , V_10 , F_1 ,
( unsigned long ) ( V_19 -> V_5 + V_31 * V_59 ) ) ;
V_10 -> V_71 = F_8 ;
}
return 0 ;
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_9 * V_10 ;
int V_59 ;
if ( V_19 -> V_22 ) {
for ( V_59 = 0 ; V_59 < V_19 -> V_70 ; V_59 ++ ) {
V_10 = & V_19 -> V_22 [ V_59 ] ;
F_16 ( V_19 , V_10 ) ;
}
}
if ( V_19 -> V_5 )
F_17 ( V_19 -> V_5 , V_64 ) ;
}
