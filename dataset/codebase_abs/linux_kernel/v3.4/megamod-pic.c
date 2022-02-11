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
static void T_4 F_18 ( struct V_3 * V_4 , int V_5 , int V_32 )
{
int V_17 , V_33 ;
T_2 V_34 ;
if ( V_5 < 0 || V_5 >= ( V_35 * 32 ) ) {
V_4 -> V_28 [ V_32 ] = V_36 ;
return;
}
V_17 = V_32 / 4 ;
V_33 = ( V_32 & 3 ) * 8 ;
V_34 = F_6 ( & V_4 -> V_7 -> V_37 [ V_17 ] ) ;
V_34 &= ~ ( 0xff << V_33 ) ;
V_34 |= V_5 << V_33 ;
F_5 ( V_34 , & V_4 -> V_7 -> V_37 [ V_17 ] ) ;
}
static void T_4 F_19 ( struct V_3 * V_4 ,
int * V_38 , int V_39 )
{
struct V_40 * V_41 = V_4 -> V_19 -> V_42 ;
const T_5 * V_43 ;
int V_26 , V_44 ;
T_2 V_34 ;
V_43 = F_20 ( V_41 , L_1 , & V_44 ) ;
if ( V_43 ) {
V_44 /= 4 ;
if ( V_44 > V_39 )
V_44 = V_39 ;
for ( V_26 = 0 ; V_26 < V_44 ; V_26 ++ ) {
V_34 = F_21 ( V_43 ) ;
if ( V_34 && V_34 >= 4 )
V_38 [ V_26 ] = V_34 ;
++ V_43 ;
}
}
}
static struct V_3 * T_4 F_22 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
int V_26 , V_9 ;
int V_38 [ V_27 ] ;
F_23 ( L_2 ) ;
V_4 = F_24 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_4 ) {
F_25 ( L_3 , V_41 -> V_46 ) ;
return NULL ;
}
V_4 -> V_19 = F_26 ( V_41 , V_35 * 32 ,
& V_47 , V_4 ) ;
if ( ! V_4 -> V_19 ) {
F_25 ( L_4 , V_41 -> V_46 ) ;
goto V_48;
}
V_4 -> V_19 -> V_25 = V_4 ;
F_27 ( & V_4 -> V_8 ) ;
V_4 -> V_7 = F_28 ( V_41 , 0 ) ;
if ( ! V_4 -> V_7 ) {
F_25 ( L_5 , V_41 -> V_46 ) ;
goto V_48;
}
for ( V_26 = 0 ; V_26 < F_29 ( V_38 ) ; V_26 ++ )
V_38 [ V_26 ] = V_36 ;
F_19 ( V_4 , V_38 , F_29 ( V_38 ) ) ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ ) {
V_9 = F_30 ( V_41 , V_26 ) ;
if ( V_9 == V_49 )
continue;
if ( V_9 < 4 || V_9 >= V_50 ) {
F_25 ( L_6 ,
V_41 -> V_46 , V_26 , V_9 ) ;
continue;
}
V_38 [ V_9 - 4 ] = V_26 ;
F_31 ( L_7 ,
V_41 -> V_46 , V_26 , V_9 ) ;
V_51 [ V_26 ] . V_4 = V_4 ;
V_51 [ V_26 ] . V_17 = V_26 ;
F_5 ( ~ 0 , & V_4 -> V_7 -> V_6 [ V_26 ] ) ;
F_5 ( ~ 0 , & V_4 -> V_7 -> V_20 [ V_26 ] ) ;
F_32 ( V_9 , & V_51 [ V_26 ] ) ;
F_33 ( V_9 , F_9 ) ;
}
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
if ( V_38 [ V_26 ] != V_36 ) {
F_31 ( L_8 ,
V_41 -> V_46 , V_38 [ V_26 ] , V_26 + 4 ) ;
F_18 ( V_4 , V_38 [ V_26 ] , V_26 ) ;
}
}
return V_4 ;
V_48:
F_34 ( V_4 ) ;
return NULL ;
}
static int F_35 ( void )
{
int V_26 , V_52 ;
T_2 V_53 ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ ) {
V_53 = F_6 ( & V_54 -> V_7 -> V_55 [ V_26 ] ) ;
if ( V_53 ) {
V_52 = F_11 ( V_53 ) ;
F_5 ( 1 << V_52 , & V_54 -> V_7 -> V_20 [ V_26 ] ) ;
return ( V_26 * 32 ) + V_52 ;
}
}
return - 1 ;
}
static void F_36 ( unsigned int V_34 )
{
F_5 ( V_34 , & V_54 -> V_7 -> V_56 ) ;
}
void T_4 F_37 ( void )
{
struct V_40 * V_41 ;
V_41 = F_38 ( NULL , NULL , L_9 ) ;
if ( ! V_41 )
return;
V_54 = F_22 ( V_41 ) ;
F_39 ( V_41 ) ;
V_57 . F_35 = F_35 ;
V_57 . F_36 = F_36 ;
return;
}
