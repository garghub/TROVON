static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
F_3 ( 0x01 , V_2 -> V_4 + V_5 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_6 -> V_7 [ V_3 ] = 0x8000 ;
F_3 ( V_6 -> V_7 [ V_3 ] , V_2 -> V_4 + F_4 ( V_3 ) ) ;
V_6 -> V_8 [ V_3 ] = 0 ;
F_3 ( ( ( V_6 -> V_8 [ V_3 ] << 4 ) | V_3 ) ,
V_9 ) ;
}
F_3 ( 0 , V_2 -> V_4 + V_10 ) ;
F_3 ( 0 , V_2 -> V_4 + V_11 ) ;
F_3 ( 0 , V_2 -> V_4 + V_5 ) ;
F_2 ( L_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
int V_17 , V_18 ;
V_18 = F_6 ( V_15 -> V_19 ) ;
F_2 ( L_3 ) ;
for ( V_17 = 0 ; V_17 < V_15 -> V_17 ; V_17 ++ )
V_16 [ V_17 ] = V_6 -> V_7 [ V_18 ] ;
return V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
int V_17 , V_18 ;
V_18 = F_6 ( V_15 -> V_19 ) ;
F_2 ( L_4 ) ;
for ( V_17 = 0 ; V_17 < V_15 -> V_17 ; V_17 ++ ) {
V_6 -> V_7 [ V_18 ] = V_16 [ V_17 ] ;
F_3 ( V_16 [ V_17 ] , V_2 -> V_4 + F_4 ( V_18 ) ) ;
}
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
unsigned int V_20 ;
unsigned int V_21 ;
unsigned short V_22 ;
V_20 = 1 << F_6 ( V_15 -> V_19 ) ;
if ( V_20 & 0x00FF )
V_21 = 0x00FF ;
else
V_21 = 0xFF00 ;
switch ( V_16 [ 0 ] ) {
case V_23 :
V_13 -> V_24 &= ~ V_21 ;
break;
case V_25 :
V_13 -> V_24 |= V_21 ;
break;
case V_26 :
V_16 [ 1 ] = ( V_13 -> V_24 & V_21 ) ? V_27 : V_28 ;
return V_15 -> V_17 ;
default:
return - V_29 ;
}
V_22 = 0x0000 ;
if ( ( V_13 -> V_24 & 0x00FF ) == 0 )
V_22 |= 0x0001 ;
if ( ( V_13 -> V_24 & 0xFF00 ) == 0 )
V_22 |= 0x0002 ;
F_3 ( V_22 , V_2 -> V_4 + V_30 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_16 )
{
if ( V_16 [ 0 ] ) {
V_13 -> V_31 &= ~ V_16 [ 0 ] ;
V_13 -> V_31 |= ( V_16 [ 0 ] & V_16 [ 1 ] ) ;
F_3 ( V_13 -> V_31 , V_2 -> V_4 + V_32 ) ;
}
V_16 [ 1 ] = F_10 ( V_2 -> V_4 + V_33 ) ;
return V_15 -> V_17 ;
}
static struct V_34 * F_11 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_34 * V_37 = NULL ;
int V_38 = V_36 -> V_39 [ 0 ] ;
int V_40 = V_36 -> V_39 [ 1 ] ;
F_12 (pcidev) {
if ( V_38 || V_40 ) {
if ( V_38 != V_37 -> V_38 -> V_41 ||
V_40 != F_13 ( V_37 -> V_42 ) )
continue;
}
if ( V_37 -> V_43 != V_44 )
continue;
return V_37 ;
}
F_14 ( V_2 -> V_45 ,
L_5 ,
V_38 , V_40 ) ;
return NULL ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_34 * V_37 ;
struct V_12 * V_13 ;
int V_46 , V_47 , V_48 ;
F_16 ( V_49 L_6 ,
V_2 -> V_50 , V_51 -> V_52 ) ;
V_46 = F_17 ( V_2 , sizeof( struct V_53 ) ) ;
if ( V_46 < 0 ) {
F_16 ( L_7 ) ;
return - V_54 ;
}
V_37 = F_11 ( V_2 , V_36 ) ;
if ( ! V_37 )
return - V_55 ;
F_18 ( V_2 , & V_37 -> V_2 ) ;
V_46 = F_19 ( V_37 , L_8 ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_4 = F_20 ( V_37 , 2 ) ;
V_2 -> V_56 = V_51 -> V_52 ;
V_48 = 0 ;
if ( V_51 -> V_57 )
V_48 ++ ;
if ( V_51 -> V_58 )
V_48 ++ ;
V_46 = F_21 ( V_2 , V_48 ) ;
if ( V_46 )
return V_46 ;
F_1 ( V_2 ) ;
V_47 = 0 ;
if ( V_51 -> V_57 ) {
V_13 = V_2 -> V_59 + V_47 ;
V_2 -> V_60 = V_13 ;
V_13 -> type = V_61 ;
V_13 -> V_62 = V_63 | V_64 | V_65 ;
V_13 -> V_66 = V_51 -> V_57 ;
V_13 -> V_67 = V_51 -> V_68 ;
V_13 -> V_69 = V_51 -> V_57 ;
V_13 -> V_70 = V_51 -> V_71 ;
V_13 -> V_72 = F_7 ;
V_13 -> V_73 = F_5 ;
switch ( F_10 ( V_2 -> V_4 + V_74 )
& 0x03 ) {
case 0x00 :
V_13 -> V_24 = 0xFFFF ;
break;
case 0x01 :
V_13 -> V_24 = 0xFF00 ;
break;
case 0x02 :
V_13 -> V_24 = 0x00FF ;
break;
case 0x03 :
V_13 -> V_24 = 0x0000 ;
break;
}
V_13 -> V_31 = F_10 ( V_2 -> V_4 + V_33 ) ;
V_47 ++ ;
}
if ( V_51 -> V_58 ) {
V_13 = V_2 -> V_59 + V_47 ;
V_13 -> type = V_75 ;
V_13 -> V_62 =
V_76 | V_77 | V_64 | V_65 ;
V_13 -> V_66 = V_51 -> V_58 ;
V_13 -> V_67 = 1 ;
V_13 -> V_69 = V_51 -> V_58 ;
V_13 -> V_70 = & V_78 ;
V_13 -> V_79 = F_8 ;
V_13 -> V_80 = F_9 ;
V_47 ++ ;
}
V_6 -> V_81 = 1 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_34 * V_37 = F_23 ( V_2 ) ;
if ( V_2 -> V_82 ) {
if ( V_6 -> V_81 )
F_1 ( V_2 ) ;
}
if ( V_37 ) {
if ( V_2 -> V_4 )
F_24 ( V_37 ) ;
F_25 ( V_37 ) ;
}
}
static int T_1 F_26 ( struct V_34 * V_2 ,
const struct V_83 * V_84 )
{
return F_27 ( V_2 , & V_85 ) ;
}
static void T_2 F_28 ( struct V_34 * V_2 )
{
F_29 ( V_2 ) ;
}
