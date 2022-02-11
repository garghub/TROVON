static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_2 ) ;
T_2 T_3 * V_6 = & V_4 -> V_7 -> V_6 [ V_5 / 32 ] ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( F_6 ( V_6 ) | ( 1 << ( V_5 & 31 ) ) , V_6 ) ;
F_7 ( & V_4 -> V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_2 ) ;
T_2 T_3 * V_6 = & V_4 -> V_7 -> V_6 [ V_5 / 32 ] ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( F_6 ( V_6 ) & ~ ( 1 << ( V_5 & 31 ) ) , V_6 ) ;
F_7 ( & V_4 -> V_8 ) ;
}
static void F_9 ( unsigned int V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 ;
T_2 V_14 ;
int V_15 , V_16 ;
V_13 = F_10 ( V_11 ) ;
V_4 = V_13 -> V_4 ;
V_16 = V_13 -> V_17 ;
while ( ( V_14 = F_6 ( & V_4 -> V_7 -> V_18 [ V_16 ] ) ) != 0 ) {
V_15 = F_11 ( V_14 ) ;
V_9 = F_12 ( V_4 -> V_19 , V_16 * 32 + V_15 ) ;
F_5 ( 1 << V_15 , & V_4 -> V_7 -> V_20 [ V_16 ] ) ;
F_13 ( V_9 ) ;
}
}
static int F_14 ( struct V_21 * V_22 , unsigned int V_23 ,
T_1 V_24 )
{
struct V_3 * V_4 = V_22 -> V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_4 -> V_28 [ V_26 ] == V_24 )
return - 1 ;
F_15 ( V_23 , V_4 ) ;
F_16 ( V_23 , & V_29 , V_30 ) ;
F_17 ( V_23 , V_31 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 , struct V_32 * V_33 ,
const T_2 * V_34 , unsigned int V_35 ,
T_1 * V_36 , unsigned int * V_37 )
{
F_19 ( V_35 != 1 ) ;
* V_36 = V_34 [ 0 ] ;
* V_37 = V_31 ;
return 0 ;
}
static void T_4 F_20 ( struct V_3 * V_4 , int V_5 , int V_38 )
{
int V_17 , V_39 ;
T_2 V_40 ;
if ( V_5 < 0 || V_5 >= ( V_41 * 32 ) ) {
V_4 -> V_28 [ V_38 ] = V_42 ;
return;
}
V_17 = V_38 / 4 ;
V_39 = ( V_38 & 3 ) * 8 ;
V_40 = F_6 ( & V_4 -> V_7 -> V_43 [ V_17 ] ) ;
V_40 &= ~ ( 0xff << V_39 ) ;
V_40 |= V_5 << V_39 ;
F_5 ( V_40 , & V_4 -> V_7 -> V_43 [ V_17 ] ) ;
}
static void T_4 F_21 ( struct V_3 * V_4 ,
int * V_44 , int V_45 )
{
struct V_32 * V_46 = V_4 -> V_19 -> V_47 ;
const T_5 * V_48 ;
int V_26 , V_49 ;
T_2 V_40 ;
V_48 = F_22 ( V_46 , L_1 , & V_49 ) ;
if ( V_48 ) {
V_49 /= 4 ;
if ( V_49 > V_45 )
V_49 = V_45 ;
for ( V_26 = 0 ; V_26 < V_49 ; V_26 ++ ) {
V_40 = F_23 ( V_48 ) ;
if ( V_40 && V_40 >= 4 )
V_44 [ V_26 ] = V_40 ;
++ V_48 ;
}
}
}
static struct V_3 * T_4 F_24 ( struct V_32 * V_46 )
{
struct V_3 * V_4 ;
int V_26 , V_9 ;
int V_44 [ V_27 ] ;
F_25 ( L_2 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_50 ) ;
if ( ! V_4 ) {
F_27 ( L_3 , V_46 -> V_51 ) ;
return NULL ;
}
V_4 -> V_19 = F_28 ( V_46 , V_52 ,
V_41 * 32 , & V_53 ,
V_42 ) ;
if ( ! V_4 -> V_19 ) {
F_27 ( L_4 , V_46 -> V_51 ) ;
goto V_54;
}
V_4 -> V_19 -> V_25 = V_4 ;
F_29 ( & V_4 -> V_8 ) ;
V_4 -> V_7 = F_30 ( V_46 , 0 ) ;
if ( ! V_4 -> V_7 ) {
F_27 ( L_5 , V_46 -> V_51 ) ;
goto V_54;
}
for ( V_26 = 0 ; V_26 < F_31 ( V_44 ) ; V_26 ++ )
V_44 [ V_26 ] = V_42 ;
F_21 ( V_4 , V_44 , F_31 ( V_44 ) ) ;
for ( V_26 = 0 ; V_26 < V_41 ; V_26 ++ ) {
V_9 = F_32 ( V_46 , V_26 ) ;
if ( V_9 == V_55 )
continue;
if ( V_9 < 4 || V_9 >= V_56 ) {
F_27 ( L_6 ,
V_46 -> V_51 , V_26 , V_9 ) ;
continue;
}
V_44 [ V_9 - 4 ] = V_26 ;
F_33 ( L_7 ,
V_46 -> V_51 , V_26 , V_9 ) ;
V_57 [ V_26 ] . V_4 = V_4 ;
V_57 [ V_26 ] . V_17 = V_26 ;
F_5 ( ~ 0 , & V_4 -> V_7 -> V_6 [ V_26 ] ) ;
F_5 ( ~ 0 , & V_4 -> V_7 -> V_20 [ V_26 ] ) ;
F_34 ( V_9 , & V_57 [ V_26 ] ) ;
F_35 ( V_9 , F_9 ) ;
}
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
if ( V_44 [ V_26 ] != V_42 ) {
F_33 ( L_8 ,
V_46 -> V_51 , V_44 [ V_26 ] , V_26 + 4 ) ;
F_20 ( V_4 , V_44 [ V_26 ] , V_26 ) ;
}
}
return V_4 ;
V_54:
F_36 ( V_4 ) ;
return NULL ;
}
static int F_37 ( void )
{
int V_26 , V_58 ;
T_2 V_59 ;
for ( V_26 = 0 ; V_26 < V_41 ; V_26 ++ ) {
V_59 = F_6 ( & V_60 -> V_7 -> V_61 [ V_26 ] ) ;
if ( V_59 ) {
V_58 = F_11 ( V_59 ) ;
F_5 ( 1 << V_58 , & V_60 -> V_7 -> V_20 [ V_26 ] ) ;
return ( V_26 * 32 ) + V_58 ;
}
}
return - 1 ;
}
static void F_38 ( unsigned int V_40 )
{
F_5 ( V_40 , & V_60 -> V_7 -> V_62 ) ;
}
void T_4 F_39 ( void )
{
struct V_32 * V_46 ;
V_46 = F_40 ( NULL , NULL , L_9 ) ;
if ( ! V_46 )
return;
V_60 = F_24 ( V_46 ) ;
F_41 ( V_46 ) ;
V_63 . F_37 = F_37 ;
V_63 . F_38 = F_38 ;
return;
}
