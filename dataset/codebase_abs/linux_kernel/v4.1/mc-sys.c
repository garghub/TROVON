int T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_3 V_4 ,
struct V_5 * V_6 ,
T_3 V_7 , struct V_8 * * V_9 )
{
struct V_8 * V_10 ;
void T_4 * V_11 ;
struct V_6 * V_12 ;
V_10 = F_2 ( V_2 , sizeof( * V_10 ) , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_15 = V_3 ;
V_10 -> V_16 = V_4 ;
V_10 -> V_6 = V_6 ;
V_12 = F_3 ( V_2 ,
V_3 ,
V_4 ,
L_1 ) ;
if ( ! V_12 ) {
F_4 ( V_2 ,
L_2 ,
V_3 ) ;
return - V_17 ;
}
V_11 = F_5 ( V_2 ,
V_3 ,
V_4 ) ;
if ( ! V_11 ) {
F_4 ( V_2 ,
L_3 ,
V_3 ) ;
return - V_18 ;
}
V_10 -> V_19 = V_11 ;
* V_9 = V_10 ;
return 0 ;
}
void F_6 ( struct V_8 * V_10 )
{
F_7 ( V_10 -> V_2 , V_10 -> V_19 ) ;
F_8 ( V_10 -> V_2 ,
V_10 -> V_15 ,
V_10 -> V_16 ) ;
V_10 -> V_19 = NULL ;
F_9 ( V_10 -> V_2 , V_10 ) ;
}
static int F_10 ( enum V_20 V_21 )
{
static const int V_22 [] = {
[ V_23 ] = 0 ,
[ V_24 ] = - V_25 ,
[ V_26 ] = - V_27 ,
[ V_28 ] = - V_29 ,
[ V_30 ] = - V_18 ,
[ V_31 ] = - V_32 ,
[ V_33 ] = - V_34 ,
[ V_35 ] = - V_14 ,
[ V_36 ] = - V_17 ,
[ V_37 ] = - V_38 ,
[ V_39 ] = - V_40 ,
} ;
if ( F_11 ( ( V_41 ) V_21 >= F_12 ( V_22 ) ) )
return - V_42 ;
return V_22 [ V_21 ] ;
}
static const char * F_13 ( enum V_20 V_21 )
{
static const char * const V_43 [] = {
[ V_23 ] = L_4 ,
[ V_44 ] = L_5 ,
[ V_24 ] = L_6 ,
[ V_26 ] = L_7 ,
[ V_28 ] = L_8 ,
[ V_30 ] = L_9 ,
[ V_31 ] = L_10 ,
[ V_33 ] = L_11 ,
[ V_35 ] = L_12 ,
[ V_36 ] = L_13 ,
[ V_37 ] = L_14 ,
[ V_39 ] = L_15
} ;
if ( ( unsigned int ) V_21 >= F_12 ( V_43 ) )
return L_16 ;
return V_43 [ V_21 ] ;
}
static inline void F_14 ( struct V_45 T_4 * V_46 ,
struct V_45 * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
F_15 ( V_47 -> V_50 [ V_48 ] , & V_46 -> V_50 [ V_48 ] ) ;
F_15 ( V_47 -> V_51 , & V_46 -> V_51 ) ;
}
static inline enum V_20 F_16 ( struct V_45 T_4 *
V_46 ,
struct V_45 * V_52 )
{
int V_48 ;
enum V_20 V_21 ;
V_52 -> V_51 = F_17 ( & V_46 -> V_51 ) ;
V_21 = F_18 ( V_52 -> V_51 ) ;
if ( V_21 != V_23 )
return V_21 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
V_52 -> V_50 [ V_48 ] = F_17 ( & V_46 -> V_50 [ V_48 ] ) ;
return V_21 ;
}
int F_19 ( struct V_8 * V_10 , struct V_45 * V_47 )
{
enum V_20 V_21 ;
unsigned long V_53 =
V_54 + V_55 ;
F_14 ( V_10 -> V_19 , V_47 ) ;
for (; ; ) {
V_21 = F_16 ( V_10 -> V_19 , V_47 ) ;
if ( V_21 != V_44 )
break;
F_20 ( V_56 ,
V_57 ) ;
if ( F_21 ( V_54 , V_53 ) ) {
F_22 ( L_17 ,
V_10 -> V_15 ,
( unsigned int )
F_23 ( V_47 -> V_51 ) ,
( unsigned int )
F_24 ( V_47 -> V_51 ) ) ;
return - V_32 ;
}
}
if ( V_21 != V_23 ) {
F_22 ( L_18 ,
V_10 -> V_15 ,
( unsigned int ) F_23 ( V_47 -> V_51 ) ,
( unsigned int ) F_24 ( V_47 -> V_51 ) ,
F_13 ( V_21 ) ,
( unsigned int ) V_21 ) ;
return F_10 ( V_21 ) ;
}
return 0 ;
}
