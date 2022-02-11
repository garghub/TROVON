int F_1 ( struct V_1 * V_2 , char * * string )
{
char * V_3 ;
int V_4 = 0 , V_5 = 0 , V_6 = 0 , V_7 ;
const char * V_8 = V_9 [ V_2 -> V_10 ] ;
const char * V_11 = NULL ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_12 * V_14 = F_2 () -> V_13 ;
char * V_15 ;
if ( ! F_3 ( V_14 , V_13 ) )
return - V_16 ;
V_11 = F_4 ( V_14 , V_13 ) ;
V_6 = strlen ( V_11 ) ;
if ( V_6 )
V_6 += 4 ;
if ( ! F_5 ( V_2 ) )
V_5 = strlen ( V_8 ) + 3 ;
V_7 = strlen ( V_2 -> V_17 . V_18 ) ;
V_4 = V_5 + V_6 + V_7 + 1 ;
V_15 = V_3 = F_6 ( V_4 + 1 , V_19 ) ;
if ( ! V_3 )
return - V_20 ;
if ( V_6 ) {
sprintf ( V_15 , L_1 , V_11 ) ;
V_15 += V_6 ;
}
if ( F_5 ( V_2 ) )
sprintf ( V_15 , L_2 , V_2 -> V_17 . V_18 ) ;
else
sprintf ( V_15 , L_3 , V_2 -> V_17 . V_18 , V_8 ) ;
* string = V_3 ;
return V_4 ;
}
static char * F_7 ( int V_21 , char * args , T_1 * V_22 )
{
char * V_23 ;
* V_22 = F_8 ( args , & V_23 , 16 ) ;
if ( ( V_23 == args ) || * V_23 != '^' ) {
F_9 ( L_4 , V_24 [ V_21 ] , args ) ;
return F_10 ( - V_25 ) ;
}
V_23 ++ ;
if ( ! * V_23 )
V_23 = NULL ;
return V_23 ;
}
int F_11 ( char * args , T_2 V_26 , int V_27 )
{
char * V_28 ;
T_1 V_22 ;
const char * V_29 [ 16 ] ;
int V_30 = 0 ;
V_28 = F_7 ( V_31 , args , & V_22 ) ;
if ( F_12 ( V_28 ) )
return F_13 ( V_28 ) ;
if ( ! V_28 && ! V_22 ) {
F_9 ( L_5 ) ;
return - V_25 ;
}
if ( V_28 ) {
char * V_32 = args + V_26 ;
for ( V_30 = 0 ; ( V_28 < V_32 ) && V_30 < 16 ; ++ V_30 ) {
char * V_33 = V_28 + strlen ( V_28 ) + 1 ;
V_29 [ V_30 ] = V_28 ;
V_28 = V_33 ;
}
}
F_14 ( L_6 ,
V_34 , V_22 , V_28 ? V_28 : NULL ) ;
return F_15 ( V_29 , V_30 , V_22 , V_27 ) ;
}
int F_16 ( char * V_35 , bool V_36 , int V_27 )
{
char * V_23 , * V_11 ;
V_23 = F_17 ( V_35 , & V_11 ) ;
return F_18 ( V_11 , V_23 , V_36 , V_27 ) ;
}
