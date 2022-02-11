static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 , V_9 ;
unsigned short V_10 = F_2 ( V_6 -> V_11 ) ;
unsigned long V_12 = 1 << ( 16 - 1 ) ;
unsigned long V_13 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_14 ; V_8 ++ ) {
V_13 = V_7 [ V_8 ] ^ V_12 ;
do {
V_9 = ( F_3 ( V_2 -> V_15 ) & 1 ) ;
} while ( V_9 );
F_4 ( V_13 , V_2 -> V_15 + ( 0x02 * V_10 ) ) ;
V_16 -> V_17 [ V_10 ] = V_13 ;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_10 = F_2 ( V_6 -> V_11 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_14 ; V_8 ++ )
V_7 [ V_8 ] = V_16 -> V_17 [ V_10 ] ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , int V_18 , int V_19 )
{
struct V_20 * V_20 = NULL ;
int V_8 ;
F_7 (pci_dev) {
if ( V_20 -> V_21 == V_22 ) {
for ( V_8 = 0 ; V_8 < F_8 ( V_23 ) ; V_8 ++ ) {
if ( V_23 [ V_8 ] . V_24 ==
V_20 -> V_25 ) {
if ( ( V_18 != 0 ) || ( V_19 != 0 ) ) {
if ( V_20 -> V_18 -> V_26
!= V_18 ||
F_9 ( V_20 -> V_27 )
!= V_19 ) {
continue;
}
}
V_2 -> V_28 = V_23 + V_8 ;
goto V_29;
}
}
}
}
F_10 ( V_30 L_1
L_2 ,
V_2 -> V_31 , V_18 , V_19 ) ;
return - V_32 ;
V_29:
F_10 ( L_3 ,
V_2 -> V_31 ,
V_23 [ V_8 ] . V_33 ,
V_20 -> V_18 -> V_26 ,
F_9 ( V_20 -> V_27 ) ,
F_11 ( V_20 -> V_27 ) , V_20 -> V_34 ) ;
V_16 -> V_20 = V_20 ;
return 0 ;
}
static int
F_12 ( struct V_20 * V_20 , unsigned long * V_35 ,
int V_36 )
{
unsigned long V_37 , V_38 , V_39 , V_40 ;
if ( F_13 ( V_20 , L_4 ) < 0 ) {
F_10 ( V_30 L_5
L_6 ,
V_36 ) ;
return - V_32 ;
}
V_39 = F_14 ( V_20 , 1 ) ;
V_40 = F_15 ( V_20 , 1 ) ;
F_10 ( V_41 L_7
L_8 ,
V_36 , V_39 , V_40 ) ;
V_37 = F_14 ( V_20 , 2 ) ;
V_38 = F_16 ( V_20 , 2 ) - V_37 + 1 ;
F_10 ( L_9 ,
V_36 , V_37 , V_38 ) ;
* V_35 = V_37 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 ;
int V_44 ;
unsigned long V_37 ;
F_10 ( V_41 L_10 , V_2 -> V_31 ) ;
V_44 = F_18 ( V_2 , sizeof( struct V_45 ) ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_6 ( V_2 , V_43 -> V_46 [ 0 ] , V_43 -> V_46 [ 1 ] ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_12 ( V_16 -> V_20 , & V_37 , V_2 -> V_31 ) ;
if ( V_44 < 0 )
return V_44 ;
V_2 -> V_15 = V_37 ;
V_2 -> V_47 = V_48 -> V_33 ;
if ( F_19 ( V_2 , 2 ) < 0 )
return - V_49 ;
V_4 = V_2 -> V_50 + 0 ;
V_4 -> type = V_51 ;
V_4 -> V_52 = V_53 ;
V_4 -> V_54 = V_48 -> V_55 ;
V_4 -> V_56 = 0xffff ;
V_4 -> V_57 = & V_58 ;
V_4 -> V_59 = F_1 ;
V_4 -> V_60 = F_5 ;
F_10 ( V_41 L_11 ) ;
return 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_16 && V_16 -> V_20 ) {
if ( V_2 -> V_15 )
F_21 ( V_16 -> V_20 ) ;
F_22 ( V_16 -> V_20 ) ;
}
}
static int T_1 F_23 ( struct V_20 * V_2 ,
const struct V_61 * V_62 )
{
return F_24 ( V_2 , & V_63 ) ;
}
static void T_2 F_25 ( struct V_20 * V_2 )
{
F_26 ( V_2 ) ;
}
