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
static void F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_4 ;
unsigned int V_13 ;
T_2 V_14 ;
int V_15 , V_16 ;
V_12 = F_10 ( V_10 ) ;
V_4 = V_12 -> V_4 ;
V_16 = V_12 -> V_17 ;
while ( ( V_14 = F_6 ( & V_4 -> V_7 -> V_18 [ V_16 ] ) ) != 0 ) {
V_15 = F_11 ( V_14 ) ;
V_13 = F_12 ( V_4 -> V_19 , V_16 * 32 + V_15 ) ;
F_5 ( 1 << V_15 , & V_4 -> V_7 -> V_20 [ V_16 ] ) ;
F_13 ( V_13 ) ;
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
struct V_40 * V_41 = F_20 ( V_4 -> V_19 ) ;
const T_5 * V_42 ;
int V_26 , V_43 ;
T_2 V_34 ;
V_42 = F_21 ( V_41 , L_1 , & V_43 ) ;
if ( V_42 ) {
V_43 /= 4 ;
if ( V_43 > V_39 )
V_43 = V_39 ;
for ( V_26 = 0 ; V_26 < V_43 ; V_26 ++ ) {
V_34 = F_22 ( V_42 ) ;
if ( V_34 && V_34 >= 4 )
V_38 [ V_26 ] = V_34 ;
++ V_42 ;
}
}
}
static struct V_3 * T_4 F_23 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
int V_26 , V_13 ;
int V_38 [ V_27 ] ;
F_24 ( L_2 ) ;
V_4 = F_25 ( sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_4 ) {
F_26 ( L_3 , V_41 ) ;
return NULL ;
}
V_4 -> V_19 = F_27 ( V_41 , V_35 * 32 ,
& V_45 , V_4 ) ;
if ( ! V_4 -> V_19 ) {
F_26 ( L_4 , V_41 ) ;
goto V_46;
}
V_4 -> V_19 -> V_25 = V_4 ;
F_28 ( & V_4 -> V_8 ) ;
V_4 -> V_7 = F_29 ( V_41 , 0 ) ;
if ( ! V_4 -> V_7 ) {
F_26 ( L_5 , V_41 ) ;
goto V_46;
}
for ( V_26 = 0 ; V_26 < F_30 ( V_38 ) ; V_26 ++ )
V_38 [ V_26 ] = V_36 ;
F_19 ( V_4 , V_38 , F_30 ( V_38 ) ) ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ ) {
struct V_1 * V_1 ;
T_1 V_47 ;
V_13 = F_31 ( V_41 , V_26 ) ;
if ( V_13 == V_48 )
continue;
V_1 = F_32 ( V_13 ) ;
if ( ! V_1 ) {
F_26 ( L_6 ,
V_41 , V_26 , V_13 ) ;
continue;
}
V_47 = V_1 -> V_47 ;
if ( V_47 < 4 || V_47 >= V_49 ) {
F_26 ( L_7 ,
V_41 , V_26 , V_47 ) ;
continue;
}
V_38 [ V_47 - 4 ] = V_26 ;
F_33 ( L_8 ,
V_41 , V_26 , V_47 ) ;
V_50 [ V_26 ] . V_4 = V_4 ;
V_50 [ V_26 ] . V_17 = V_26 ;
F_5 ( ~ 0 , & V_4 -> V_7 -> V_6 [ V_26 ] ) ;
F_5 ( ~ 0 , & V_4 -> V_7 -> V_20 [ V_26 ] ) ;
F_34 ( V_13 , F_9 ,
& V_50 [ V_26 ] ) ;
}
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
if ( V_38 [ V_26 ] != V_36 ) {
F_33 ( L_9 ,
V_41 , V_38 [ V_26 ] , V_26 + 4 ) ;
F_18 ( V_4 , V_38 [ V_26 ] , V_26 ) ;
}
}
return V_4 ;
V_46:
F_35 ( V_4 ) ;
return NULL ;
}
static int F_36 ( void )
{
int V_26 , V_51 ;
T_2 V_52 ;
for ( V_26 = 0 ; V_26 < V_35 ; V_26 ++ ) {
V_52 = F_6 ( & V_53 -> V_7 -> V_54 [ V_26 ] ) ;
if ( V_52 ) {
V_51 = F_11 ( V_52 ) ;
F_5 ( 1 << V_51 , & V_53 -> V_7 -> V_20 [ V_26 ] ) ;
return ( V_26 * 32 ) + V_51 ;
}
}
return - 1 ;
}
static void F_37 ( unsigned int V_34 )
{
F_5 ( V_34 , & V_53 -> V_7 -> V_55 ) ;
}
void T_4 F_38 ( void )
{
struct V_40 * V_41 ;
V_41 = F_39 ( NULL , NULL , L_10 ) ;
if ( ! V_41 )
return;
V_53 = F_23 ( V_41 ) ;
F_40 ( V_41 ) ;
V_56 . F_36 = F_36 ;
V_56 . F_37 = F_37 ;
return;
}
