static bool F_1 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
unsigned short * V_6 = V_1 -> V_7 ;
unsigned int V_8 = F_2 ( V_5 ) ;
unsigned int V_9 = F_3 ( V_5 ) ;
unsigned short V_10 = F_4 ( V_5 ) ;
if ( V_8 >= V_2 || V_9 >= V_3 ) {
F_5 ( V_1 -> V_11 . V_12 ,
L_1 ,
V_13 , V_5 , V_8 , V_9 , V_2 , V_3 ) ;
return false ;
}
V_6 [ F_6 ( V_8 , V_9 , V_4 ) ] = V_10 ;
F_7 ( V_10 , V_1 -> V_14 ) ;
return true ;
}
int F_8 ( struct V_15 * V_11 ,
unsigned int * V_2 , unsigned int * V_3 )
{
* V_2 = * V_3 = 0 ;
F_9 ( V_11 , L_2 , V_2 ) ;
F_9 ( V_11 , L_3 , V_3 ) ;
if ( ! * V_2 || ! * V_3 ) {
F_5 ( V_11 , L_4 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_10 ( const char * V_17 ,
unsigned int V_2 , unsigned int V_3 ,
struct V_1 * V_1 )
{
struct V_15 * V_11 = V_1 -> V_11 . V_12 ;
unsigned int V_4 = F_11 ( V_3 ) ;
unsigned int V_18 = V_2 << V_4 ;
T_1 * V_19 ;
int V_20 ;
int V_21 ;
int V_22 ;
if ( ! V_17 )
V_17 = L_5 ;
V_21 = F_12 ( V_11 , V_17 , NULL , 0 ) ;
if ( V_21 <= 0 ) {
F_5 ( V_11 , L_6 ,
V_17 , V_21 ) ;
return V_21 < 0 ? V_21 : - V_16 ;
}
if ( V_21 > V_18 ) {
F_5 ( V_11 , L_7 ,
V_17 , V_21 , V_18 ) ;
return - V_16 ;
}
V_19 = F_13 ( V_21 , sizeof( T_1 ) , V_23 ) ;
if ( ! V_19 )
return - V_24 ;
V_22 = F_12 ( V_11 , V_17 , V_19 , V_21 ) ;
if ( V_22 ) {
F_5 ( V_11 , L_8 ,
V_17 , V_22 ) ;
goto V_25;
}
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( ! F_1 ( V_1 , V_2 , V_3 ,
V_4 , V_19 [ V_20 ] ) ) {
V_22 = - V_16 ;
goto V_25;
}
}
V_22 = 0 ;
V_25:
F_14 ( V_19 ) ;
return V_22 ;
}
int F_15 ( const struct V_26 * V_27 ,
const char * V_28 ,
unsigned int V_2 , unsigned int V_3 ,
unsigned short * V_6 ,
struct V_1 * V_1 )
{
unsigned int V_4 = F_11 ( V_3 ) ;
T_2 V_18 = V_2 << V_4 ;
int V_20 ;
int error ;
if ( F_16 ( ! V_1 -> V_11 . V_12 ) )
return - V_16 ;
if ( ! V_6 ) {
V_6 = F_17 ( V_1 -> V_11 . V_12 ,
V_18 * sizeof( * V_6 ) ,
V_23 ) ;
if ( ! V_6 ) {
F_5 ( V_1 -> V_11 . V_12 ,
L_9 ) ;
return - V_24 ;
}
}
V_1 -> V_7 = V_6 ;
V_1 -> V_29 = sizeof( * V_6 ) ;
V_1 -> V_30 = V_18 ;
F_7 ( V_31 , V_1 -> V_32 ) ;
if ( V_27 ) {
for ( V_20 = 0 ; V_20 < V_27 -> V_33 ; V_20 ++ ) {
unsigned int V_5 = V_27 -> V_6 [ V_20 ] ;
if ( ! F_1 ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) )
return - V_16 ;
}
} else {
error = F_10 ( V_28 , V_2 , V_3 ,
V_1 ) ;
if ( error )
return error ;
}
F_18 ( V_34 , V_1 -> V_14 ) ;
return 0 ;
}
