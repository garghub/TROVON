static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = 1 << ( 16 - 1 ) ;
unsigned long V_14 = 0 ;
unsigned short V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
V_14 = V_7 [ V_16 ] ^ V_13 ;
do {
V_15 = F_3 ( V_2 -> V_18 + V_19 ) ;
} while ( V_15 & V_20 );
F_4 ( V_14 , V_2 -> V_18 + F_5 ( V_11 ) ) ;
}
V_9 -> V_21 [ V_11 ] = V_14 ;
return V_6 -> V_17 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ )
V_7 [ V_16 ] = V_9 -> V_21 [ V_11 ] ;
return V_6 -> V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_22 = V_7 [ 0 ] & V_23 ;
unsigned int V_24 = V_7 [ 1 ] ;
if ( V_22 ) {
V_4 -> V_25 &= ~ V_22 ;
V_4 -> V_25 |= V_24 & V_22 ;
F_4 ( V_4 -> V_25 , V_2 -> V_18 + V_26 ) ;
}
V_4 -> V_25 = F_3 ( V_2 -> V_18 + V_26 ) ;
V_7 [ 1 ] = V_4 -> V_25 ;
return V_6 -> V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_22 = 1 << V_11 ;
switch ( V_7 [ 0 ] ) {
case V_27 :
V_7 [ 1 ] = ( V_4 -> V_28 & V_22 ) ? V_29 : V_30 ;
break;
default:
return - V_31 ;
}
return V_6 -> V_17 ;
}
static struct V_32 * F_9 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
const struct V_35 * V_36 ;
struct V_32 * V_32 = NULL ;
int V_37 = V_34 -> V_38 [ 0 ] ;
int V_39 = V_34 -> V_38 [ 1 ] ;
int V_16 ;
F_10 (pci_dev) {
if ( V_32 -> V_40 != V_41 )
continue;
for ( V_16 = 0 ; V_16 < F_11 ( V_42 ) ; V_16 ++ ) {
V_36 = & V_42 [ V_16 ] ;
if ( V_36 -> V_43 != V_32 -> V_44 )
continue;
if ( V_37 || V_39 ) {
if ( V_32 -> V_37 -> V_45 != V_37 ||
F_12 ( V_32 -> V_46 ) != V_39 )
continue;
}
F_13 ( V_2 -> V_47 ,
L_1 ,
V_36 -> V_48 ,
V_32 -> V_37 -> V_45 ,
F_12 ( V_32 -> V_46 ) ,
V_32 -> V_49 ) ;
V_2 -> V_50 = V_36 ;
return V_32 ;
}
}
F_14 ( V_2 -> V_47 ,
L_2 ,
V_37 , V_39 ) ;
return NULL ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
const struct V_35 * V_36 ;
struct V_8 * V_9 ;
struct V_32 * V_51 ;
struct V_3 * V_4 ;
int V_52 ;
V_52 = F_16 ( V_2 , sizeof( * V_9 ) ) ;
if ( V_52 < 0 )
return V_52 ;
V_9 = V_2 -> V_10 ;
V_51 = F_9 ( V_2 , V_34 ) ;
if ( ! V_51 )
return - V_53 ;
F_17 ( V_2 , & V_51 -> V_2 ) ;
V_36 = F_18 ( V_2 ) ;
V_2 -> V_54 = V_36 -> V_48 ;
V_52 = F_19 ( V_51 , V_2 -> V_55 -> V_56 ) ;
if ( V_52 ) {
F_14 ( V_2 -> V_47 ,
L_3 ) ;
return V_52 ;
}
V_2 -> V_18 = F_20 ( V_51 , 2 ) ;
V_52 = F_21 ( V_2 , 2 ) ;
if ( V_52 )
return V_52 ;
V_4 = V_2 -> V_57 + 0 ;
V_4 -> type = V_58 ;
V_4 -> V_59 = V_60 ;
V_4 -> V_61 = V_36 -> V_62 ;
V_4 -> V_63 = 0xffff ;
V_4 -> V_64 = & V_65 ;
V_4 -> V_66 = F_1 ;
V_4 -> V_67 = F_6 ;
V_4 = V_2 -> V_57 + 1 ;
V_4 -> type = V_68 ;
V_4 -> V_59 = V_69 | V_60 ;
V_4 -> V_61 = 8 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_70 ;
V_4 -> V_71 = F_7 ;
V_4 -> V_72 = F_8 ;
V_4 -> V_28 = 0x0f ;
V_4 -> V_25 = F_3 ( V_2 -> V_18 + V_26 ) ;
F_22 ( V_2 -> V_47 , L_4 ,
V_2 -> V_55 -> V_56 , V_2 -> V_54 , V_2 -> V_18 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_51 = F_24 ( V_2 ) ;
if ( V_51 ) {
if ( V_2 -> V_18 )
F_25 ( V_51 ) ;
F_26 ( V_51 ) ;
}
}
static int T_1 F_27 ( struct V_32 * V_2 ,
const struct V_73 * V_74 )
{
return F_28 ( V_2 , & V_75 ) ;
}
static void T_2 F_29 ( struct V_32 * V_2 )
{
F_30 ( V_2 ) ;
}
