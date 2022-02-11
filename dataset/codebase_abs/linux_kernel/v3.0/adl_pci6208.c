static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 = ( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static int F_11 ( struct V_10 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int V_7 ;
unsigned long V_15 ;
F_12 ( V_16 L_1 , V_2 -> V_17 ) ;
V_7 = F_13 ( V_2 , sizeof( struct V_18 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( V_2 , V_12 -> V_19 [ 0 ] , V_12 -> V_19 [ 1 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( V_20 -> V_1 , & V_15 , V_2 -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_21 = V_15 ;
V_2 -> V_22 = V_23 -> V_9 ;
if ( F_16 ( V_2 , 2 ) < 0 )
return - V_24 ;
V_14 = V_2 -> V_25 + 0 ;
V_14 -> type = V_26 ;
V_14 -> V_27 = V_28 ;
V_14 -> V_29 = V_23 -> V_30 ;
V_14 -> V_31 = 0xffff ;
V_14 -> V_32 = & V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_36 = V_37 ;
F_12 ( V_16 L_2 ) ;
return 1 ;
}
static int F_17 ( struct V_10 * V_2 )
{
F_12 ( V_16 L_3 , V_2 -> V_17 ) ;
if ( V_20 && V_20 -> V_1 ) {
if ( V_2 -> V_21 )
F_18 ( V_20 -> V_1 ) ;
F_19 ( V_20 -> V_1 ) ;
}
return 0 ;
}
static int V_35 ( struct V_10 * V_2 ,
struct V_13 * V_14 ,
struct V_38 * V_39 , unsigned int * V_40 )
{
int V_41 = 0 , V_42 ;
unsigned short V_43 = F_20 ( V_39 -> V_44 ) ;
unsigned long V_45 = 1 << ( 16 - 1 ) ;
unsigned long V_46 ;
for ( V_41 = 0 ; V_41 < V_39 -> V_47 ; V_41 ++ ) {
V_46 = V_40 [ V_41 ] ^ V_45 ;
do {
V_42 = ( F_21 ( V_2 -> V_21 ) & 1 ) ;
} while ( V_42 );
F_22 ( V_46 , V_2 -> V_21 + ( 0x02 * V_43 ) ) ;
V_20 -> V_48 [ V_43 ] = V_46 ;
}
return V_41 ;
}
static int V_37 ( struct V_10 * V_2 ,
struct V_13 * V_14 ,
struct V_38 * V_39 , unsigned int * V_40 )
{
int V_41 ;
int V_43 = F_20 ( V_39 -> V_44 ) ;
for ( V_41 = 0 ; V_41 < V_39 -> V_47 ; V_41 ++ )
V_40 [ V_41 ] = V_20 -> V_48 [ V_43 ] ;
return V_41 ;
}
static int F_14 ( struct V_10 * V_2 , int V_49 , int V_50 )
{
struct V_1 * V_1 = NULL ;
int V_41 ;
F_23 (pci_dev) {
if ( V_1 -> V_51 == V_52 ) {
for ( V_41 = 0 ; V_41 < F_24 ( V_53 ) ; V_41 ++ ) {
if ( V_53 [ V_41 ] . V_54 ==
V_1 -> V_55 ) {
if ( ( V_49 != 0 ) || ( V_50 != 0 ) ) {
if ( V_1 -> V_49 -> V_56
!= V_49 ||
F_25 ( V_1 -> V_57 )
!= V_50 ) {
continue;
}
}
V_2 -> V_58 = V_53 + V_41 ;
goto V_59;
}
}
}
}
F_12 ( V_60 L_4
L_5 ,
V_2 -> V_17 , V_49 , V_50 ) ;
return - V_61 ;
V_59:
F_12 ( L_6 ,
V_2 -> V_17 ,
V_53 [ V_41 ] . V_9 ,
V_1 -> V_49 -> V_56 ,
F_25 ( V_1 -> V_57 ) ,
F_26 ( V_1 -> V_57 ) , V_1 -> V_62 ) ;
V_20 -> V_1 = V_1 ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_1 , unsigned long * V_63 ,
int V_64 )
{
unsigned long V_15 , V_65 , V_66 , V_67 ;
if ( F_27 ( V_1 , V_68 ) < 0 ) {
F_12 ( V_60 L_7
L_8 ,
V_64 ) ;
return - V_61 ;
}
V_66 = F_28 ( V_1 , 1 ) ;
V_67 = F_29 ( V_1 , 1 ) ;
F_12 ( V_16 L_9
L_10 ,
V_64 , V_66 , V_67 ) ;
V_15 = F_28 ( V_1 , 2 ) ;
V_65 = F_30 ( V_1 , 2 ) - V_15 + 1 ;
F_12 ( L_11 ,
V_64 , V_15 , V_65 ) ;
* V_63 = V_15 ;
return 0 ;
}
