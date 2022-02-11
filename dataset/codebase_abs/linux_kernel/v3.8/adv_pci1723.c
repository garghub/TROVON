static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( 0x01 , V_2 -> V_7 + V_8 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
V_4 -> V_9 [ V_6 ] = 0x8000 ;
F_2 ( V_4 -> V_9 [ V_6 ] , V_2 -> V_7 + F_3 ( V_6 ) ) ;
V_4 -> V_10 [ V_6 ] = 0 ;
F_2 ( ( ( V_4 -> V_10 [ V_6 ] << 4 ) | V_6 ) ,
V_11 ) ;
}
F_2 ( 0 , V_2 -> V_7 + V_12 ) ;
F_2 ( 0 , V_2 -> V_7 + V_13 ) ;
F_2 ( 0 , V_2 -> V_7 + V_8 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_19 , V_20 ;
V_20 = F_5 ( V_17 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_19 ; V_19 ++ )
V_18 [ V_19 ] = V_4 -> V_9 [ V_20 ] ;
return V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_19 , V_20 ;
V_20 = F_5 ( V_17 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_19 ; V_19 ++ ) {
V_4 -> V_9 [ V_20 ] = V_18 [ V_19 ] ;
F_2 ( V_18 [ V_19 ] , V_2 -> V_7 + F_3 ( V_20 ) ) ;
}
return V_19 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
unsigned int V_22 ;
unsigned int V_23 ;
unsigned short V_24 ;
V_22 = 1 << F_5 ( V_17 -> V_21 ) ;
if ( V_22 & 0x00FF )
V_23 = 0x00FF ;
else
V_23 = 0xFF00 ;
switch ( V_18 [ 0 ] ) {
case V_25 :
V_15 -> V_26 &= ~ V_23 ;
break;
case V_27 :
V_15 -> V_26 |= V_23 ;
break;
case V_28 :
V_18 [ 1 ] = ( V_15 -> V_26 & V_23 ) ? V_29 : V_30 ;
return V_17 -> V_19 ;
default:
return - V_31 ;
}
V_24 = 0x0000 ;
if ( ( V_15 -> V_26 & 0x00FF ) == 0 )
V_24 |= 0x0001 ;
if ( ( V_15 -> V_26 & 0xFF00 ) == 0 )
V_24 |= 0x0002 ;
F_2 ( V_24 , V_2 -> V_7 + V_32 ) ;
return 1 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 , unsigned int * V_18 )
{
if ( V_18 [ 0 ] ) {
V_15 -> V_33 &= ~ V_18 [ 0 ] ;
V_15 -> V_33 |= ( V_18 [ 0 ] & V_18 [ 1 ] ) ;
F_2 ( V_15 -> V_33 , V_2 -> V_7 + V_34 ) ;
}
V_18 [ 1 ] = F_9 ( V_2 -> V_7 + V_35 ) ;
return V_17 -> V_19 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_36 )
{
struct V_37 * V_38 = F_11 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
int V_39 ;
V_2 -> V_40 = V_2 -> V_41 -> V_42 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_44 ;
V_2 -> V_5 = V_4 ;
V_39 = F_13 ( V_38 , V_2 -> V_40 ) ;
if ( V_39 )
return V_39 ;
V_2 -> V_7 = F_14 ( V_38 , 2 ) ;
V_39 = F_15 ( V_2 , 2 ) ;
if ( V_39 )
return V_39 ;
V_15 = & V_2 -> V_45 [ 0 ] ;
V_2 -> V_46 = V_15 ;
V_15 -> type = V_47 ;
V_15 -> V_48 = V_49 | V_50 | V_51 ;
V_15 -> V_52 = 8 ;
V_15 -> V_53 = 0xffff ;
V_15 -> V_54 = 8 ;
V_15 -> V_55 = & V_56 ;
V_15 -> V_57 = F_6 ;
V_15 -> V_58 = F_4 ;
V_15 = & V_2 -> V_45 [ 1 ] ;
V_15 -> type = V_59 ;
V_15 -> V_48 = V_60 | V_61 ;
V_15 -> V_52 = 16 ;
V_15 -> V_53 = 1 ;
V_15 -> V_54 = 16 ;
V_15 -> V_55 = & V_62 ;
V_15 -> V_63 = F_7 ;
V_15 -> V_64 = F_8 ;
switch ( F_9 ( V_2 -> V_7 + V_65 ) & 0x03 ) {
case 0x00 :
V_15 -> V_26 = 0xFFFF ;
break;
case 0x01 :
V_15 -> V_26 = 0xFF00 ;
break;
case 0x02 :
V_15 -> V_26 = 0x00FF ;
break;
case 0x03 :
V_15 -> V_26 = 0x0000 ;
break;
}
V_15 -> V_33 = F_9 ( V_2 -> V_7 + V_35 ) ;
F_1 ( V_2 ) ;
F_16 ( V_2 -> V_66 , L_1 , V_2 -> V_40 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_11 ( V_2 ) ;
if ( V_38 ) {
if ( V_2 -> V_7 ) {
F_1 ( V_2 ) ;
F_18 ( V_38 ) ;
}
}
}
static int F_19 ( struct V_37 * V_2 ,
const struct V_67 * V_68 )
{
return F_20 ( V_2 , & V_69 ) ;
}
static void F_21 ( struct V_37 * V_2 )
{
F_22 ( V_2 ) ;
}
