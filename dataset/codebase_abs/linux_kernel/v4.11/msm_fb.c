static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_4 ,
V_7 -> V_8 [ 0 ] , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = V_2 -> V_11 -> V_12 ;
F_5 ( L_1 , V_2 -> V_13 . V_14 , V_2 ) ;
F_6 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_15 * V_16 = V_7 -> V_8 [ V_9 ] ;
F_7 ( V_16 ) ;
}
F_8 ( V_7 ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = V_2 -> V_11 -> V_12 ;
F_10 ( V_18 , L_2 ,
V_2 -> V_19 , V_2 -> V_20 , ( char * ) & V_2 -> V_11 -> V_11 ,
F_11 ( V_2 ) , V_2 -> V_13 . V_14 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
F_10 ( V_18 , L_3 ,
V_9 , V_2 -> V_21 [ V_9 ] , V_2 -> V_22 [ V_9 ] ) ;
F_12 ( V_7 -> V_8 [ V_9 ] , V_18 ) ;
}
}
int F_13 ( struct V_1 * V_2 , int V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_23 , V_9 , V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_24 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_23 = F_14 ( V_7 -> V_8 [ V_9 ] , V_14 , & V_24 ) ;
F_5 ( L_4 , V_2 -> V_13 . V_14 , V_9 , V_24 , V_23 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 , int V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = V_2 -> V_11 -> V_12 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_16 ( V_7 -> V_8 [ V_9 ] , V_14 ) ;
}
T_2 F_17 ( struct V_1 * V_2 , int V_14 , int V_25 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_8 [ V_25 ] )
return 0 ;
return F_18 ( V_7 -> V_8 [ V_25 ] , V_14 ) + V_2 -> V_21 [ V_25 ] ;
}
struct V_15 * F_19 ( struct V_1 * V_2 , int V_25 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_8 [ V_25 ] ;
}
const struct V_26 * F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_11 ;
}
struct V_1 * F_21 ( struct V_27 * V_28 ,
struct V_3 * V_29 , const struct V_30 * V_31 )
{
struct V_15 * V_32 [ 4 ] = { 0 } ;
struct V_1 * V_2 ;
int V_23 , V_9 , V_10 = F_22 ( V_31 -> V_33 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_32 [ V_9 ] = F_23 ( V_29 , V_31 -> V_34 [ V_9 ] ) ;
if ( ! V_32 [ V_9 ] ) {
V_23 = - V_35 ;
goto V_36;
}
}
V_2 = F_24 ( V_28 , V_31 , V_32 ) ;
if ( F_25 ( V_2 ) ) {
V_23 = F_26 ( V_2 ) ;
goto V_36;
}
return V_2 ;
V_36:
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_7 ( V_32 [ V_9 ] ) ;
return F_27 ( V_23 ) ;
}
struct V_1 * F_24 ( struct V_27 * V_28 ,
const struct V_30 * V_31 , struct V_15 * * V_32 )
{
struct V_37 * V_38 = V_28 -> V_39 ;
struct V_40 * V_41 = V_38 -> V_41 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 ;
const struct V_26 * V_11 ;
int V_23 , V_9 , V_10 ;
unsigned int V_42 , V_43 ;
F_5 ( L_5 ,
V_28 , V_31 , V_31 -> V_19 , V_31 -> V_20 ,
( char * ) & V_31 -> V_33 ) ;
V_10 = F_22 ( V_31 -> V_33 ) ;
V_42 = F_28 ( V_31 -> V_33 ) ;
V_43 = F_29 ( V_31 -> V_33 ) ;
V_11 = V_41 -> V_44 -> V_45 ( V_41 , V_31 -> V_33 ) ;
if ( ! V_11 ) {
F_30 ( V_28 -> V_28 , L_6 ,
( char * ) & V_31 -> V_33 ) ;
V_23 = - V_46 ;
goto V_47;
}
V_7 = F_31 ( sizeof( * V_7 ) , V_48 ) ;
if ( ! V_7 ) {
V_23 = - V_49 ;
goto V_47;
}
V_2 = & V_7 -> V_13 ;
V_7 -> V_11 = V_11 ;
if ( V_10 > F_32 ( V_7 -> V_8 ) ) {
V_23 = - V_46 ;
goto V_47;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned int V_19 = V_31 -> V_19 / ( V_9 ? V_42 : 1 ) ;
unsigned int V_20 = V_31 -> V_20 / ( V_9 ? V_43 : 1 ) ;
unsigned int V_50 ;
V_50 = ( V_20 - 1 ) * V_31 -> V_22 [ V_9 ]
+ V_19 * F_33 ( V_31 -> V_33 , V_9 )
+ V_31 -> V_21 [ V_9 ] ;
if ( V_32 [ V_9 ] -> V_51 < V_50 ) {
V_23 = - V_46 ;
goto V_47;
}
V_7 -> V_8 [ V_9 ] = V_32 [ V_9 ] ;
}
F_34 ( V_28 , V_2 , V_31 ) ;
V_23 = F_35 ( V_28 , V_2 , & V_52 ) ;
if ( V_23 ) {
F_30 ( V_28 -> V_28 , L_7 , V_23 ) ;
goto V_47;
}
F_5 ( L_8 , V_2 -> V_13 . V_14 , V_2 ) ;
return V_2 ;
V_47:
F_8 ( V_7 ) ;
return F_27 ( V_23 ) ;
}
