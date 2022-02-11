int F_1 ( struct V_1 * V_2 , char * * string )
{
char * V_3 ;
int V_4 = 0 , V_5 = 0 , V_6 = 0 , V_7 ;
const char * V_8 = V_9 [ V_2 -> V_10 ] ;
const char * V_11 = NULL ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_12 * V_14 = F_2 () -> V_13 ;
char * V_15 ;
if ( ! F_3 ( V_14 , V_13 , true ) )
return - V_16 ;
V_11 = F_4 ( V_14 , V_13 , true ) ;
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
static char * F_7 ( const char * V_21 , char * args , T_1 * V_22 )
{
char * V_23 ;
* V_22 = F_8 ( args , & V_23 , 16 ) ;
if ( ( V_23 == args ) || * V_23 != '^' ) {
F_9 ( L_4 , V_21 , args ) ;
return F_10 ( - V_24 ) ;
}
V_23 ++ ;
if ( ! * V_23 )
V_23 = NULL ;
return V_23 ;
}
int F_11 ( char * args , T_2 V_25 , int V_26 )
{
char * V_27 ;
T_1 V_22 ;
const char * V_28 [ 16 ] ;
int V_29 = 0 ;
V_27 = F_7 ( V_30 , args , & V_22 ) ;
if ( F_12 ( V_27 ) )
return F_13 ( V_27 ) ;
if ( ! V_27 && ! V_22 ) {
F_9 ( L_5 ) ;
return - V_24 ;
}
if ( V_27 ) {
char * V_31 = args + V_25 ;
for ( V_29 = 0 ; ( V_27 < V_31 ) && V_29 < 16 ; ++ V_29 ) {
char * V_32 = V_27 + strlen ( V_27 ) + 1 ;
V_28 [ V_29 ] = V_27 ;
F_14 ( L_6
, V_33 , V_34 -> V_35 , V_22 , V_29 , V_27 ) ;
V_27 = V_32 ;
}
} else
F_14 ( L_7 ,
V_33 , V_34 -> V_35 , V_22 , V_29 , L_8 ) ;
return F_15 ( V_28 , V_29 , V_22 , V_26 ) ;
}
