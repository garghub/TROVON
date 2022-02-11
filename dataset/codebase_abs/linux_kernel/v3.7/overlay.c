static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ?
( V_3 -> V_4 -> V_5 ? V_3 -> V_4 -> V_5 -> V_6 : NULL ) :
NULL ;
}
int F_2 ( void )
{
return V_7 ;
}
struct V_2 * F_3 ( int V_8 )
{
if ( V_8 >= V_7 )
return NULL ;
return & V_9 [ V_8 ] ;
}
void F_4 ( struct V_10 * V_11 )
{
int V_12 , V_13 ;
V_7 = F_5 () ;
V_9 = F_6 ( sizeof( struct V_2 ) * V_7 ,
V_14 ) ;
F_7 ( V_9 == NULL ) ;
for ( V_12 = 0 ; V_12 < V_7 ; ++ V_12 ) {
struct V_2 * V_3 = & V_9 [ V_12 ] ;
switch ( V_12 ) {
case 0 :
V_3 -> V_15 = L_1 ;
V_3 -> V_16 = V_17 ;
break;
case 1 :
V_3 -> V_15 = L_2 ;
V_3 -> V_16 = V_18 ;
break;
case 2 :
V_3 -> V_15 = L_3 ;
V_3 -> V_16 = V_19 ;
break;
case 3 :
V_3 -> V_15 = L_4 ;
V_3 -> V_16 = V_20 ;
break;
}
V_3 -> V_21 = & V_22 ;
V_3 -> V_23 = & V_24 ;
V_3 -> V_25 = & V_26 ;
V_3 -> V_27 = & V_28 ;
V_3 -> V_29 = & V_30 ;
V_3 -> V_31 = & V_32 ;
V_3 -> V_33 = & V_34 ;
V_3 -> V_35 = & V_36 ;
V_3 -> V_37 = & F_1 ;
V_3 -> V_38 = F_8 ( V_3 -> V_16 ) ;
V_3 -> V_39 =
F_9 ( V_3 -> V_16 ) ;
V_13 = F_10 ( V_3 , V_11 ) ;
if ( V_13 )
F_11 ( L_5 ) ;
}
}
void F_12 ( struct V_10 * V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 ; ++ V_12 ) {
struct V_2 * V_3 = & V_9 [ V_12 ] ;
F_13 ( V_3 ) ;
}
F_14 ( V_9 ) ;
V_9 = NULL ;
V_7 = 0 ;
}
int F_15 ( struct V_2 * V_3 ,
const struct V_40 * V_41 )
{
if ( V_41 -> V_42 == 0 ) {
F_11 ( L_6 ) ;
return - V_43 ;
}
if ( ( V_3 -> V_38 & V_44 ) == 0 ) {
if ( V_41 -> V_45 != 0 && V_41 -> V_46 != V_41 -> V_45 ) {
F_11 ( L_7
L_8 , V_3 -> V_16 ) ;
return - V_43 ;
}
if ( V_41 -> V_47 != 0 && V_41 -> V_48 != V_41 -> V_47 ) {
F_11 ( L_7
L_8 , V_3 -> V_16 ) ;
return - V_43 ;
}
}
if ( ( V_3 -> V_39 & V_41 -> V_49 ) == 0 ) {
F_11 ( L_9 ,
V_3 -> V_16 , V_41 -> V_49 ) ;
return - V_43 ;
}
if ( V_41 -> V_50 >= F_2 () ) {
F_11 ( L_10 , V_41 -> V_50 ) ;
return - V_43 ;
}
if ( F_16 ( V_41 -> V_51 ) == 0 ) {
F_11 ( L_11 ,
V_41 -> V_51 ) ;
return - V_43 ;
}
return 0 ;
}
int F_17 ( struct V_2 * V_3 , struct V_40 * V_41 ,
const struct V_52 * V_53 )
{
T_1 V_54 , V_55 ;
T_1 V_56 , V_57 ;
V_56 = V_53 -> V_58 ;
V_57 = V_53 -> V_59 ;
if ( ( V_3 -> V_38 & V_44 ) == 0 ) {
V_54 = V_41 -> V_46 ;
V_55 = V_41 -> V_48 ;
} else {
if ( V_41 -> V_45 == 0 )
V_54 = V_41 -> V_46 ;
else
V_54 = V_41 -> V_45 ;
if ( V_41 -> V_47 == 0 )
V_55 = V_41 -> V_48 ;
else
V_55 = V_41 -> V_47 ;
}
if ( V_56 < V_41 -> V_60 + V_54 ) {
F_11 ( L_12
L_13 ,
V_3 -> V_16 , V_41 -> V_60 , V_54 , V_56 ) ;
return - V_43 ;
}
if ( V_57 < V_41 -> V_61 + V_55 ) {
F_11 ( L_14
L_13 ,
V_3 -> V_16 , V_41 -> V_61 , V_55 , V_57 ) ;
return - V_43 ;
}
return 0 ;
}
bool F_18 ( struct V_62 V_63 ,
enum V_64 V_65 )
{
if ( V_65 != V_66 && V_65 != V_67 )
return false ;
return V_63 . V_68 > 16 ;
}
