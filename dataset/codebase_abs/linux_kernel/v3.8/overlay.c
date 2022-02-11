int F_1 ( void )
{
return V_1 ;
}
struct V_2 * F_2 ( int V_3 )
{
if ( V_3 >= V_1 )
return NULL ;
return & V_4 [ V_3 ] ;
}
void F_3 ( struct V_5 * V_6 )
{
int V_7 , V_8 ;
V_1 = F_4 () ;
V_4 = F_5 ( sizeof( struct V_2 ) * V_1 ,
V_9 ) ;
F_6 ( V_4 == NULL ) ;
for ( V_7 = 0 ; V_7 < V_1 ; ++ V_7 ) {
struct V_2 * V_10 = & V_4 [ V_7 ] ;
switch ( V_7 ) {
case 0 :
V_10 -> V_11 = L_1 ;
V_10 -> V_12 = V_13 ;
break;
case 1 :
V_10 -> V_11 = L_2 ;
V_10 -> V_12 = V_14 ;
break;
case 2 :
V_10 -> V_11 = L_3 ;
V_10 -> V_12 = V_15 ;
break;
case 3 :
V_10 -> V_11 = L_4 ;
V_10 -> V_12 = V_16 ;
break;
}
V_10 -> V_17 = F_7 ( V_10 -> V_12 ) ;
V_10 -> V_18 =
F_8 ( V_10 -> V_12 ) ;
V_8 = F_9 ( V_10 , V_6 ) ;
if ( V_8 )
F_10 ( L_5 ) ;
}
}
void F_11 ( struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_1 ; ++ V_7 ) {
struct V_2 * V_10 = & V_4 [ V_7 ] ;
F_12 ( V_10 ) ;
}
F_13 ( V_4 ) ;
V_4 = NULL ;
V_1 = 0 ;
}
int F_14 ( struct V_2 * V_10 ,
const struct V_19 * V_20 )
{
if ( V_20 -> V_21 == 0 ) {
F_10 ( L_6 ) ;
return - V_22 ;
}
if ( ( V_10 -> V_17 & V_23 ) == 0 ) {
if ( V_20 -> V_24 != 0 && V_20 -> V_25 != V_20 -> V_24 ) {
F_10 ( L_7
L_8 , V_10 -> V_12 ) ;
return - V_22 ;
}
if ( V_20 -> V_26 != 0 && V_20 -> V_27 != V_20 -> V_26 ) {
F_10 ( L_7
L_8 , V_10 -> V_12 ) ;
return - V_22 ;
}
}
if ( ( V_10 -> V_18 & V_20 -> V_28 ) == 0 ) {
F_10 ( L_9 ,
V_10 -> V_12 , V_20 -> V_28 ) ;
return - V_22 ;
}
if ( V_20 -> V_29 >= F_1 () ) {
F_10 ( L_10 , V_20 -> V_29 ) ;
return - V_22 ;
}
if ( F_15 ( V_20 -> V_30 ) == 0 ) {
F_10 ( L_11 ,
V_20 -> V_30 ) ;
return - V_22 ;
}
return 0 ;
}
int F_16 ( struct V_2 * V_10 , struct V_19 * V_20 ,
const struct V_31 * V_32 )
{
T_1 V_33 , V_34 ;
T_1 V_35 , V_36 ;
V_35 = V_32 -> V_37 ;
V_36 = V_32 -> V_38 ;
if ( ( V_10 -> V_17 & V_23 ) == 0 ) {
V_33 = V_20 -> V_25 ;
V_34 = V_20 -> V_27 ;
} else {
if ( V_20 -> V_24 == 0 )
V_33 = V_20 -> V_25 ;
else
V_33 = V_20 -> V_24 ;
if ( V_20 -> V_26 == 0 )
V_34 = V_20 -> V_27 ;
else
V_34 = V_20 -> V_26 ;
}
if ( V_35 < V_20 -> V_39 + V_33 ) {
F_10 ( L_12
L_13 ,
V_10 -> V_12 , V_20 -> V_39 , V_33 , V_35 ) ;
return - V_22 ;
}
if ( V_36 < V_20 -> V_40 + V_34 ) {
F_10 ( L_14
L_13 ,
V_10 -> V_12 , V_20 -> V_40 , V_34 , V_36 ) ;
return - V_22 ;
}
return 0 ;
}
bool F_17 ( struct V_41 V_42 ,
enum V_43 V_44 )
{
if ( V_44 != V_45 && V_44 != V_46 )
return false ;
return V_42 . V_47 > 16 ;
}
