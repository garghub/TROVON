static int F_1 ( const char * V_1 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
F_2 ( L_1 , V_4 . V_6 , V_1 ) ;
if ( ++ V_4 . V_6 == V_8 ) {
F_3 ( L_2 , V_8 ) ;
return - 1 ;
}
V_3 -> V_9 = V_4 . V_9 ;
V_7 = F_4 ( V_1 , V_3 ) ;
F_2 ( L_3 , V_3 -> V_10 ) ;
return V_7 ;
}
static int F_5 ( const char * V_11 )
{
int V_12 = 0 ;
const char * V_13 ;
if ( ! V_4 . V_14 && V_11 && * V_11 == '/' ) {
V_4 . V_14 = V_11 ;
V_12 = 1 ;
V_13 = V_11 + ( strlen ( V_11 ) - 3 ) ;
if ( strcmp ( V_13 , L_4 ) )
V_4 . V_9 = true ;
}
return V_12 ;
}
static int F_6 ( int V_15 , const char * * V_16 )
{
int V_17 , V_18 , V_7 , V_19 ;
char * V_13 ;
V_19 = F_5 ( V_16 [ 0 ] ) ;
if ( V_19 && V_15 == 1 )
return 0 ;
V_18 = 0 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_17 == 0 && V_19 )
continue;
V_18 += strlen ( V_16 [ V_17 ] ) + 1 ;
}
V_13 = F_7 ( V_18 + 1 ) ;
if ( V_13 == NULL )
return - V_20 ;
V_18 = 0 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_17 == 0 && V_19 )
continue;
V_18 += sprintf ( & V_13 [ V_18 ] , L_5 , V_16 [ V_17 ] ) ;
}
V_4 . V_21 = true ;
V_7 = F_1 ( V_13 ) ;
free ( V_13 ) ;
return V_7 ;
}
static int F_8 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
if ( V_1 ) {
V_4 . V_21 = true ;
return F_1 ( V_1 ) ;
} else
return 0 ;
}
static int F_9 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
if ( V_1 ) {
V_4 . V_21 = true ;
if ( ! V_4 . V_24 )
V_4 . V_24 = F_10 ( true , NULL ) ;
F_11 ( V_4 . V_24 , V_1 ) ;
}
return 0 ;
}
static int F_12 ( const struct V_22 * T_1 , const char * V_1 ,
int T_2 V_23 )
{
int V_7 = - V_25 ;
if ( V_1 && ! V_4 . V_14 ) {
if ( ! strcmp ( T_1 -> V_26 , L_6 ) )
V_4 . V_9 = true ;
#ifdef F_13
else if ( ! strcmp ( T_1 -> V_26 , L_7 ) )
V_4 . V_9 = false ;
#endif
else
return V_7 ;
V_4 . V_14 = V_1 ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_14 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_27 ) {
F_15 ( L_8
L_9 ) ;
return 0 ;
}
V_4 . V_27 = true ;
V_7 = F_16 ( V_1 , & V_4 . V_28 ) ;
F_17 ( & V_4 . V_28 . V_29 ) ;
return V_7 ;
}
static int F_18 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_10 != 0 ) {
F_3 ( L_10 ) ;
return - V_30 ;
}
V_4 . V_31 = true ;
return V_7 ;
}
static int F_19 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
const char * V_32 ;
if ( V_1 ) {
F_20 ( L_11 , V_1 ) ;
if ( V_4 . V_33 )
F_21 ( V_4 . V_33 ) ;
V_4 . V_33 = F_22 ( V_1 , & V_32 ) ;
if ( ! V_4 . V_33 ) {
F_3 ( L_12 , V_32 - V_1 + 1 ) ;
F_3 ( L_13 , V_1 ) ;
F_3 ( L_14 , ( int ) ( V_32 - V_1 + 1 ) , '^' ) ;
return - V_30 ;
}
}
return 0 ;
}
int F_23 ( int V_15 , const char * * V_16 , const char * T_3 V_23 )
{
int V_7 ;
V_15 = F_24 ( V_15 , V_16 , V_34 , V_35 ,
V_36 ) ;
if ( V_15 > 0 ) {
if ( strcmp ( V_16 [ 0 ] , L_15 ) == 0 ) {
F_15 ( L_16 ) ;
F_25 ( V_35 , V_34 ) ;
}
V_7 = F_6 ( V_15 , V_16 ) ;
if ( V_7 < 0 ) {
F_3 ( L_17 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_37 == 0 )
V_4 . V_37 = V_8 ;
if ( ( ! V_4 . V_6 && ! V_4 . V_24 && ! V_4 . V_38 &&
! V_4 . V_27 && ! V_4 . V_39 ) )
F_25 ( V_35 , V_34 ) ;
V_40 . V_41 = ( V_40 . V_42 == NULL ) ;
if ( V_4 . V_38 ) {
if ( V_4 . V_21 ) {
F_3 ( L_18 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_27 ) {
F_3 ( L_19 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_20 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_39 ) {
F_3 ( L_21 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_9 ) {
F_15 ( L_22 ) ;
F_25 ( V_35 , V_34 ) ;
}
V_7 = F_26 () ;
if ( V_7 < 0 )
F_3 ( L_23 ,
V_7 ) ;
return V_7 ;
}
if ( V_4 . V_39 ) {
if ( V_4 . V_6 != 0 || V_4 . V_24 ) {
F_3 ( L_24
L_25 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_27 ) {
F_3 ( L_26 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_27 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( ! V_4 . V_33 )
V_4 . V_33 = F_22 ( V_43 ,
NULL ) ;
V_7 = F_27 ( V_4 . V_14 , V_4 . V_33 ,
V_4 . V_9 ) ;
F_21 ( V_4 . V_33 ) ;
if ( V_7 < 0 )
F_3 ( L_28
L_29 , V_7 ) ;
return V_7 ;
}
#ifdef F_13
if ( V_4 . V_27 && ! V_4 . V_9 ) {
if ( V_4 . V_21 ) {
F_3 ( L_30
L_25 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_31 ) ;
F_25 ( V_35 , V_34 ) ;
}
V_7 = F_28 ( & V_4 . V_28 , V_4 . V_14 ) ;
if ( V_7 < 0 )
F_3 ( L_32 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_31 ) {
if ( V_4 . V_21 ) {
F_3 ( L_33
L_25 ) ;
F_25 ( V_35 , V_34 ) ;
}
if ( ! V_4 . V_33 )
V_4 . V_33 = F_22 ( V_44 ,
NULL ) ;
V_7 = F_29 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_37 ,
V_4 . V_14 ,
V_4 . V_33 ,
V_4 . V_45 ) ;
F_21 ( V_4 . V_33 ) ;
if ( V_7 < 0 )
F_3 ( L_34 , V_7 ) ;
return V_7 ;
}
#endif
if ( V_4 . V_24 ) {
V_7 = F_30 ( V_4 . V_24 ) ;
F_31 ( V_4 . V_24 ) ;
if ( V_7 < 0 ) {
F_3 ( L_35 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_6 ) {
V_7 = F_32 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_37 ,
V_4 . V_14 ,
V_4 . V_46 ) ;
if ( V_7 < 0 ) {
F_3 ( L_36 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
