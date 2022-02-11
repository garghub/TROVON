static int F_1 ( const char * V_1 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
F_2 ( L_1 , V_4 . V_6 , V_1 ) ;
if ( ++ V_4 . V_6 == V_8 ) {
F_3 ( L_2 , V_8 ) ;
return - 1 ;
}
V_7 = F_4 ( V_1 , V_3 ) ;
F_2 ( L_3 , V_3 -> V_9 ) ;
return V_7 ;
}
static int F_5 ( int V_10 , const char * * V_11 )
{
int V_12 , V_13 , V_7 ;
char * V_14 ;
V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
V_13 += strlen ( V_11 [ V_12 ] ) + 1 ;
V_14 = F_6 ( V_13 + 1 ) ;
if ( V_14 == NULL )
return - V_15 ;
V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
V_13 += sprintf ( & V_14 [ V_13 ] , L_4 , V_11 [ V_12 ] ) ;
V_4 . V_16 = true ;
V_7 = F_1 ( V_14 ) ;
free ( V_14 ) ;
return V_7 ;
}
static int F_7 ( const struct V_17 * T_1 V_18 ,
const char * V_1 , int T_2 V_18 )
{
if ( V_1 ) {
V_4 . V_16 = true ;
return F_1 ( V_1 ) ;
} else
return 0 ;
}
static int F_8 ( const struct V_17 * T_1 V_18 ,
const char * V_1 , int T_2 V_18 )
{
if ( V_1 ) {
V_4 . V_16 = true ;
if ( ! V_4 . V_19 )
V_4 . V_19 = F_9 ( true , NULL ) ;
F_10 ( V_4 . V_19 , V_1 ) ;
}
return 0 ;
}
static int F_11 ( const struct V_17 * T_1 V_18 ,
const char * V_1 , int T_2 V_18 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_20 ) {
F_12 ( L_5
L_6 ) ;
return 0 ;
}
V_4 . V_20 = true ;
V_7 = F_13 ( V_1 , & V_4 . V_21 ) ;
F_14 ( & V_4 . V_21 . V_22 ) ;
return V_7 ;
}
static int F_15 ( const struct V_17 * T_1 V_18 ,
const char * V_1 , int T_2 V_18 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_9 != 0 ) {
F_3 ( L_7 ) ;
return - V_23 ;
}
V_4 . V_24 = true ;
return V_7 ;
}
static int F_16 ( const struct V_17 * T_1 V_18 ,
const char * V_1 , int T_2 V_18 )
{
const char * V_25 ;
if ( V_1 ) {
F_17 ( L_8 , V_1 ) ;
if ( V_4 . V_26 )
F_18 ( V_4 . V_26 ) ;
V_4 . V_26 = F_19 ( V_1 , & V_25 ) ;
if ( ! V_4 . V_26 ) {
F_3 ( L_9 , V_25 - V_1 + 1 ) ;
F_3 ( L_10 , V_1 ) ;
F_3 ( L_11 , ( int ) ( V_25 - V_1 + 1 ) , '^' ) ;
return - V_23 ;
}
}
return 0 ;
}
int F_20 ( int V_10 , const char * * V_11 , const char * T_3 V_18 )
{
int V_7 ;
V_10 = F_21 ( V_10 , V_11 , V_27 , V_28 ,
V_29 ) ;
if ( V_10 > 0 ) {
if ( strcmp ( V_11 [ 0 ] , L_12 ) == 0 ) {
F_12 ( L_13 ) ;
F_22 ( V_28 , V_27 ) ;
}
V_7 = F_5 ( V_10 , V_11 ) ;
if ( V_7 < 0 ) {
F_3 ( L_14 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_30 == 0 )
V_4 . V_30 = V_8 ;
if ( ( ! V_4 . V_6 && ! V_4 . V_19 && ! V_4 . V_31 &&
! V_4 . V_20 && ! V_4 . V_32 ) )
F_22 ( V_28 , V_27 ) ;
V_33 . V_34 = ( V_33 . V_35 == NULL ) ;
if ( V_4 . V_31 ) {
if ( V_4 . V_16 ) {
F_3 ( L_15 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( V_4 . V_20 ) {
F_3 ( L_16 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( V_4 . V_24 ) {
F_3 ( L_17 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( V_4 . V_32 ) {
F_3 ( L_18 ) ;
F_22 ( V_28 , V_27 ) ;
}
V_7 = F_23 () ;
if ( V_7 < 0 )
F_3 ( L_19 ,
V_7 ) ;
return V_7 ;
}
if ( V_4 . V_32 ) {
if ( V_4 . V_6 != 0 || V_4 . V_19 ) {
F_3 ( L_20
L_21 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( V_4 . V_20 ) {
F_3 ( L_22 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( V_4 . V_24 ) {
F_3 ( L_23 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( ! V_4 . V_26 )
V_4 . V_26 = F_19 ( V_36 ,
NULL ) ;
V_7 = F_24 ( V_4 . V_37 ,
V_4 . V_26 ) ;
F_18 ( V_4 . V_26 ) ;
if ( V_7 < 0 )
F_3 ( L_24
L_25 , V_7 ) ;
return V_7 ;
}
#ifdef F_25
if ( V_4 . V_20 ) {
if ( V_4 . V_16 ) {
F_3 ( L_26
L_21 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( V_4 . V_24 ) {
F_3 ( L_27 ) ;
F_22 ( V_28 , V_27 ) ;
}
V_7 = F_26 ( & V_4 . V_21 , V_4 . V_37 ) ;
if ( V_7 < 0 )
F_3 ( L_28 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_24 ) {
if ( V_4 . V_16 ) {
F_3 ( L_29
L_21 ) ;
F_22 ( V_28 , V_27 ) ;
}
if ( ! V_4 . V_26 )
V_4 . V_26 = F_19 ( V_38 ,
NULL ) ;
V_7 = F_27 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_30 ,
V_4 . V_37 ,
V_4 . V_26 ,
V_4 . V_39 ) ;
F_18 ( V_4 . V_26 ) ;
if ( V_7 < 0 )
F_3 ( L_30 , V_7 ) ;
return V_7 ;
}
#endif
if ( V_4 . V_19 ) {
V_7 = F_28 ( V_4 . V_19 ) ;
F_29 ( V_4 . V_19 ) ;
if ( V_7 < 0 ) {
F_3 ( L_31 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_6 ) {
V_7 = F_30 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_30 ,
V_4 . V_37 ,
V_4 . V_40 ) ;
if ( V_7 < 0 ) {
F_3 ( L_32 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
