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
int V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
F_6 ( L_1 , V_2 -> V_12 . V_13 , V_2 ) ;
F_7 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_14 * V_15 = V_7 -> V_8 [ V_9 ] ;
F_8 ( V_15 ) ;
}
F_9 ( V_7 ) ;
}
void F_10 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
F_11 ( V_17 , L_2 ,
V_2 -> V_18 , V_2 -> V_19 , ( char * ) & V_2 -> V_11 ,
F_12 ( V_2 ) , V_2 -> V_12 . V_13 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
F_11 ( V_17 , L_3 ,
V_9 , V_2 -> V_20 [ V_9 ] , V_2 -> V_21 [ V_9 ] ) ;
F_13 ( V_7 -> V_8 [ V_9 ] , V_17 ) ;
}
}
int F_14 ( struct V_1 * V_2 , int V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_22 , V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
T_1 V_23 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_22 = F_15 ( V_7 -> V_8 [ V_9 ] , V_13 , & V_23 ) ;
F_6 ( L_4 , V_2 -> V_12 . V_13 , V_9 , V_23 , V_22 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
void F_16 ( struct V_1 * V_2 , int V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_17 ( V_7 -> V_8 [ V_9 ] , V_13 ) ;
}
T_1 F_18 ( struct V_1 * V_2 , int V_13 , int V_24 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_8 [ V_24 ] )
return 0 ;
return F_19 ( V_7 -> V_8 [ V_24 ] , V_13 ) + V_2 -> V_20 [ V_24 ] ;
}
struct V_14 * F_20 ( struct V_1 * V_2 , int V_24 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_8 [ V_24 ] ;
}
const struct V_25 * F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_26 ;
}
struct V_1 * F_22 ( struct V_27 * V_28 ,
struct V_3 * V_29 , const struct V_30 * V_31 )
{
struct V_14 * V_32 [ 4 ] = { 0 } ;
struct V_1 * V_2 ;
int V_22 , V_9 , V_10 = F_5 ( V_31 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_32 [ V_9 ] = F_23 ( V_29 , V_31 -> V_33 [ V_9 ] ) ;
if ( ! V_32 [ V_9 ] ) {
V_22 = - V_34 ;
goto V_35;
}
}
V_2 = F_24 ( V_28 , V_31 , V_32 ) ;
if ( F_25 ( V_2 ) ) {
V_22 = F_26 ( V_2 ) ;
goto V_35;
}
return V_2 ;
V_35:
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_8 ( V_32 [ V_9 ] ) ;
return F_27 ( V_22 ) ;
}
struct V_1 * F_24 ( struct V_27 * V_28 ,
const struct V_30 * V_31 , struct V_14 * * V_32 )
{
struct V_36 * V_37 = V_28 -> V_38 ;
struct V_39 * V_40 = V_37 -> V_40 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 ;
const struct V_25 * V_26 ;
int V_22 , V_9 , V_10 ;
unsigned int V_41 , V_42 ;
F_6 ( L_5 ,
V_28 , V_31 , V_31 -> V_18 , V_31 -> V_19 ,
( char * ) & V_31 -> V_11 ) ;
V_10 = F_5 ( V_31 -> V_11 ) ;
V_41 = F_28 ( V_31 -> V_11 ) ;
V_42 = F_29 ( V_31 -> V_11 ) ;
V_26 = V_40 -> V_43 -> V_44 ( V_40 , V_31 -> V_11 ) ;
if ( ! V_26 ) {
F_30 ( V_28 -> V_28 , L_6 ,
( char * ) & V_31 -> V_11 ) ;
V_22 = - V_45 ;
goto V_46;
}
V_7 = F_31 ( sizeof( * V_7 ) , V_47 ) ;
if ( ! V_7 ) {
V_22 = - V_48 ;
goto V_46;
}
V_2 = & V_7 -> V_12 ;
V_7 -> V_26 = V_26 ;
if ( V_10 > F_32 ( V_7 -> V_8 ) ) {
V_22 = - V_45 ;
goto V_46;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned int V_18 = V_31 -> V_18 / ( V_9 ? V_41 : 1 ) ;
unsigned int V_19 = V_31 -> V_19 / ( V_9 ? V_42 : 1 ) ;
unsigned int V_49 ;
V_49 = ( V_19 - 1 ) * V_31 -> V_21 [ V_9 ]
+ V_18 * F_33 ( V_31 -> V_11 , V_9 )
+ V_31 -> V_20 [ V_9 ] ;
if ( V_32 [ V_9 ] -> V_50 < V_49 ) {
V_22 = - V_45 ;
goto V_46;
}
V_7 -> V_8 [ V_9 ] = V_32 [ V_9 ] ;
}
F_34 ( V_2 , V_31 ) ;
V_22 = F_35 ( V_28 , V_2 , & V_51 ) ;
if ( V_22 ) {
F_30 ( V_28 -> V_28 , L_7 , V_22 ) ;
goto V_46;
}
F_6 ( L_8 , V_2 -> V_12 . V_13 , V_2 ) ;
return V_2 ;
V_46:
F_9 ( V_7 ) ;
return F_27 ( V_22 ) ;
}
