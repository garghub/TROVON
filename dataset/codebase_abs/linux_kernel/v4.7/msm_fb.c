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
if ( V_15 )
F_8 ( V_15 ) ;
}
F_9 ( V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_16 , unsigned V_17 ,
struct V_18 * V_19 , unsigned V_20 )
{
return 0 ;
}
void F_11 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
F_12 ( V_22 , L_2 ,
V_2 -> V_23 , V_2 -> V_24 , ( char * ) & V_2 -> V_11 ,
F_13 ( V_2 ) , V_2 -> V_12 . V_13 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
F_12 ( V_22 , L_3 ,
V_9 , V_2 -> V_25 [ V_9 ] , V_2 -> V_26 [ V_9 ] ) ;
F_14 ( V_7 -> V_8 [ V_9 ] , V_22 ) ;
}
}
int F_15 ( struct V_1 * V_2 , int V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_27 , V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
T_1 V_28 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_27 = F_16 ( V_7 -> V_8 [ V_9 ] , V_13 , & V_28 ) ;
F_6 ( L_4 , V_2 -> V_12 . V_13 , V_9 , V_28 , V_27 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
void F_17 ( struct V_1 * V_2 , int V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_18 ( V_7 -> V_8 [ V_9 ] , V_13 ) ;
}
T_1 F_19 ( struct V_1 * V_2 , int V_13 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_8 [ V_29 ] )
return 0 ;
return F_20 ( V_7 -> V_8 [ V_29 ] , V_13 ) + V_2 -> V_25 [ V_29 ] ;
}
struct V_14 * F_21 ( struct V_1 * V_2 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_8 [ V_29 ] ;
}
const struct V_30 * F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_31 ;
}
struct V_1 * F_23 ( struct V_32 * V_33 ,
struct V_3 * V_34 , const struct V_35 * V_36 )
{
struct V_14 * V_37 [ 4 ] = { 0 } ;
struct V_1 * V_2 ;
int V_27 , V_9 , V_10 = F_5 ( V_36 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_37 [ V_9 ] = F_24 ( V_34 , V_36 -> V_38 [ V_9 ] ) ;
if ( ! V_37 [ V_9 ] ) {
V_27 = - V_39 ;
goto V_40;
}
}
V_2 = F_25 ( V_33 , V_36 , V_37 ) ;
if ( F_26 ( V_2 ) ) {
V_27 = F_27 ( V_2 ) ;
goto V_40;
}
return V_2 ;
V_40:
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_8 ( V_37 [ V_9 ] ) ;
return F_28 ( V_27 ) ;
}
struct V_1 * F_25 ( struct V_32 * V_33 ,
const struct V_35 * V_36 , struct V_14 * * V_37 )
{
struct V_41 * V_42 = V_33 -> V_43 ;
struct V_44 * V_45 = V_42 -> V_45 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 ;
const struct V_30 * V_31 ;
int V_27 , V_9 , V_10 ;
unsigned int V_46 , V_47 ;
F_6 ( L_5 ,
V_33 , V_36 , V_36 -> V_23 , V_36 -> V_24 ,
( char * ) & V_36 -> V_11 ) ;
V_10 = F_5 ( V_36 -> V_11 ) ;
V_46 = F_29 ( V_36 -> V_11 ) ;
V_47 = F_30 ( V_36 -> V_11 ) ;
V_31 = V_45 -> V_48 -> V_49 ( V_45 , V_36 -> V_11 ) ;
if ( ! V_31 ) {
F_31 ( V_33 -> V_33 , L_6 ,
( char * ) & V_36 -> V_11 ) ;
V_27 = - V_50 ;
goto V_51;
}
V_7 = F_32 ( sizeof( * V_7 ) , V_52 ) ;
if ( ! V_7 ) {
V_27 = - V_53 ;
goto V_51;
}
V_2 = & V_7 -> V_12 ;
V_7 -> V_31 = V_31 ;
if ( V_10 > F_33 ( V_7 -> V_8 ) ) {
V_27 = - V_50 ;
goto V_51;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned int V_23 = V_36 -> V_23 / ( V_9 ? V_46 : 1 ) ;
unsigned int V_24 = V_36 -> V_24 / ( V_9 ? V_47 : 1 ) ;
unsigned int V_54 ;
V_54 = ( V_24 - 1 ) * V_36 -> V_26 [ V_9 ]
+ V_23 * F_34 ( V_36 -> V_11 , V_9 )
+ V_36 -> V_25 [ V_9 ] ;
if ( V_37 [ V_9 ] -> V_55 < V_54 ) {
V_27 = - V_50 ;
goto V_51;
}
V_7 -> V_8 [ V_9 ] = V_37 [ V_9 ] ;
}
F_35 ( V_2 , V_36 ) ;
V_27 = F_36 ( V_33 , V_2 , & V_56 ) ;
if ( V_27 ) {
F_31 ( V_33 -> V_33 , L_7 , V_27 ) ;
goto V_51;
}
F_6 ( L_8 , V_2 -> V_12 . V_13 , V_2 ) ;
return V_2 ;
V_51:
F_9 ( V_7 ) ;
return F_28 ( V_27 ) ;
}
