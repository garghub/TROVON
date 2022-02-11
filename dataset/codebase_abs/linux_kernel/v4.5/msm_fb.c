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
V_2 -> V_25 . V_25 . V_26 , V_2 -> V_12 . V_13 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
F_12 ( V_22 , L_3 ,
V_9 , V_2 -> V_27 [ V_9 ] , V_2 -> V_28 [ V_9 ] ) ;
F_13 ( V_7 -> V_8 [ V_9 ] , V_22 ) ;
}
}
int F_14 ( struct V_1 * V_2 , int V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_29 , V_9 , V_10 = F_5 ( V_2 -> V_11 ) ;
T_1 V_30 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_29 = F_15 ( V_7 -> V_8 [ V_9 ] , V_13 , & V_30 ) ;
F_6 ( L_4 , V_2 -> V_12 . V_13 , V_9 , V_30 , V_29 ) ;
if ( V_29 )
return V_29 ;
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
T_1 F_18 ( struct V_1 * V_2 , int V_13 , int V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_8 [ V_31 ] )
return 0 ;
return F_19 ( V_7 -> V_8 [ V_31 ] , V_13 ) + V_2 -> V_27 [ V_31 ] ;
}
struct V_14 * F_20 ( struct V_1 * V_2 , int V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_8 [ V_31 ] ;
}
const struct V_32 * F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_33 ;
}
struct V_1 * F_22 ( struct V_34 * V_35 ,
struct V_3 * V_36 , const struct V_37 * V_38 )
{
struct V_14 * V_39 [ 4 ] = { 0 } ;
struct V_1 * V_2 ;
int V_29 , V_9 , V_10 = F_5 ( V_38 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_39 [ V_9 ] = F_23 ( V_35 , V_36 ,
V_38 -> V_40 [ V_9 ] ) ;
if ( ! V_39 [ V_9 ] ) {
V_29 = - V_41 ;
goto V_42;
}
}
V_2 = F_24 ( V_35 , V_38 , V_39 ) ;
if ( F_25 ( V_2 ) ) {
V_29 = F_26 ( V_2 ) ;
goto V_42;
}
return V_2 ;
V_42:
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_8 ( V_39 [ V_9 ] ) ;
return F_27 ( V_29 ) ;
}
struct V_1 * F_24 ( struct V_34 * V_35 ,
const struct V_37 * V_38 , struct V_14 * * V_39 )
{
struct V_43 * V_44 = V_35 -> V_45 ;
struct V_46 * V_47 = V_44 -> V_47 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 ;
const struct V_32 * V_33 ;
int V_29 , V_9 , V_10 ;
unsigned int V_48 , V_49 ;
F_6 ( L_5 ,
V_35 , V_38 , V_38 -> V_23 , V_38 -> V_24 ,
( char * ) & V_38 -> V_11 ) ;
V_10 = F_5 ( V_38 -> V_11 ) ;
V_48 = F_28 ( V_38 -> V_11 ) ;
V_49 = F_29 ( V_38 -> V_11 ) ;
V_33 = V_47 -> V_50 -> V_51 ( V_47 , V_38 -> V_11 ) ;
if ( ! V_33 ) {
F_30 ( V_35 -> V_35 , L_6 ,
( char * ) & V_38 -> V_11 ) ;
V_29 = - V_52 ;
goto V_53;
}
V_7 = F_31 ( sizeof( * V_7 ) , V_54 ) ;
if ( ! V_7 ) {
V_29 = - V_55 ;
goto V_53;
}
V_2 = & V_7 -> V_12 ;
V_7 -> V_33 = V_33 ;
if ( V_10 > F_32 ( V_7 -> V_8 ) ) {
V_29 = - V_52 ;
goto V_53;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned int V_23 = V_38 -> V_23 / ( V_9 ? V_48 : 1 ) ;
unsigned int V_24 = V_38 -> V_24 / ( V_9 ? V_49 : 1 ) ;
unsigned int V_56 ;
V_56 = ( V_24 - 1 ) * V_38 -> V_28 [ V_9 ]
+ V_23 * F_33 ( V_38 -> V_11 , V_9 )
+ V_38 -> V_27 [ V_9 ] ;
if ( V_39 [ V_9 ] -> V_57 < V_56 ) {
V_29 = - V_52 ;
goto V_53;
}
V_7 -> V_8 [ V_9 ] = V_39 [ V_9 ] ;
}
F_34 ( V_2 , V_38 ) ;
V_29 = F_35 ( V_35 , V_2 , & V_58 ) ;
if ( V_29 ) {
F_30 ( V_35 -> V_35 , L_7 , V_29 ) ;
goto V_53;
}
F_6 ( L_8 , V_2 -> V_12 . V_13 , V_2 ) ;
return V_2 ;
V_53:
F_9 ( V_7 ) ;
return F_27 ( V_29 ) ;
}
