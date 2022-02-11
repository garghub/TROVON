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
int F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_25 , V_9 , V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_26 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_25 = F_14 ( V_7 -> V_8 [ V_9 ] , V_24 , & V_26 ) ;
F_5 ( L_4 , V_2 -> V_13 . V_14 , V_9 , V_26 , V_25 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_9 , V_10 = V_2 -> V_11 -> V_12 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_16 ( V_7 -> V_8 [ V_9 ] , V_24 ) ;
}
T_2 F_17 ( struct V_1 * V_2 ,
struct V_23 * V_24 , int V_27 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_8 [ V_27 ] )
return 0 ;
return F_18 ( V_7 -> V_8 [ V_27 ] , V_24 ) + V_2 -> V_21 [ V_27 ] ;
}
struct V_15 * F_19 ( struct V_1 * V_2 , int V_27 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_8 [ V_27 ] ;
}
const struct V_28 * F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_11 ;
}
struct V_1 * F_21 ( struct V_29 * V_30 ,
struct V_3 * V_31 , const struct V_32 * V_33 )
{
struct V_15 * V_34 [ 4 ] = { 0 } ;
struct V_1 * V_2 ;
int V_25 , V_9 , V_10 = F_22 ( V_33 -> V_35 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_34 [ V_9 ] = F_23 ( V_31 , V_33 -> V_36 [ V_9 ] ) ;
if ( ! V_34 [ V_9 ] ) {
V_25 = - V_37 ;
goto V_38;
}
}
V_2 = F_24 ( V_30 , V_33 , V_34 ) ;
if ( F_25 ( V_2 ) ) {
V_25 = F_26 ( V_2 ) ;
goto V_38;
}
return V_2 ;
V_38:
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_7 ( V_34 [ V_9 ] ) ;
return F_27 ( V_25 ) ;
}
static struct V_1 * F_24 ( struct V_29 * V_30 ,
const struct V_32 * V_33 , struct V_15 * * V_34 )
{
struct V_39 * V_40 = V_30 -> V_41 ;
struct V_42 * V_43 = V_40 -> V_43 ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 ;
const struct V_28 * V_11 ;
int V_25 , V_9 , V_10 ;
unsigned int V_44 , V_45 ;
F_5 ( L_5 ,
V_30 , V_33 , V_33 -> V_19 , V_33 -> V_20 ,
( char * ) & V_33 -> V_35 ) ;
V_10 = F_22 ( V_33 -> V_35 ) ;
V_44 = F_28 ( V_33 -> V_35 ) ;
V_45 = F_29 ( V_33 -> V_35 ) ;
V_11 = V_43 -> V_46 -> V_47 ( V_43 , V_33 -> V_35 ) ;
if ( ! V_11 ) {
F_30 ( V_30 -> V_30 , L_6 ,
( char * ) & V_33 -> V_35 ) ;
V_25 = - V_48 ;
goto V_49;
}
V_7 = F_31 ( sizeof( * V_7 ) , V_50 ) ;
if ( ! V_7 ) {
V_25 = - V_51 ;
goto V_49;
}
V_2 = & V_7 -> V_13 ;
V_7 -> V_11 = V_11 ;
if ( V_10 > F_32 ( V_7 -> V_8 ) ) {
V_25 = - V_48 ;
goto V_49;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
unsigned int V_19 = V_33 -> V_19 / ( V_9 ? V_44 : 1 ) ;
unsigned int V_20 = V_33 -> V_20 / ( V_9 ? V_45 : 1 ) ;
unsigned int V_52 ;
V_52 = ( V_20 - 1 ) * V_33 -> V_22 [ V_9 ]
+ V_19 * F_33 ( V_33 -> V_35 , V_9 )
+ V_33 -> V_21 [ V_9 ] ;
if ( V_34 [ V_9 ] -> V_53 < V_52 ) {
V_25 = - V_48 ;
goto V_49;
}
V_7 -> V_8 [ V_9 ] = V_34 [ V_9 ] ;
}
F_34 ( V_30 , V_2 , V_33 ) ;
V_25 = F_35 ( V_30 , V_2 , & V_54 ) ;
if ( V_25 ) {
F_30 ( V_30 -> V_30 , L_7 , V_25 ) ;
goto V_49;
}
F_5 ( L_8 , V_2 -> V_13 . V_14 , V_2 ) ;
return V_2 ;
V_49:
F_8 ( V_7 ) ;
return F_27 ( V_25 ) ;
}
struct V_1 *
F_36 ( struct V_29 * V_30 , int V_55 , int V_56 , int V_57 , T_2 V_11 )
{
struct V_32 V_33 = {
. V_35 = V_11 ,
. V_19 = V_55 ,
. V_20 = V_56 ,
. V_22 = { V_57 } ,
} ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_53 ;
V_53 = V_33 . V_22 [ 0 ] * V_33 . V_20 ;
F_5 ( L_9 , V_53 , V_30 -> V_58 -> V_59 ) ;
V_16 = F_37 ( V_30 , V_53 , V_60 | V_61 | V_62 ) ;
if ( F_25 ( V_16 ) ) {
F_38 ( V_30 -> V_30 , L_10 ) ;
V_16 = F_37 ( V_30 , V_53 , V_60 | V_61 ) ;
}
if ( F_25 ( V_16 ) ) {
F_30 ( V_30 -> V_30 , L_11 ) ;
return F_39 ( V_16 ) ;
}
V_2 = F_24 ( V_30 , & V_33 , & V_16 ) ;
if ( F_25 ( V_2 ) ) {
F_30 ( V_30 -> V_30 , L_12 ) ;
F_7 ( V_16 ) ;
return F_39 ( V_2 ) ;
}
return V_2 ;
}
