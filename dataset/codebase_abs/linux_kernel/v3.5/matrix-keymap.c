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
static int F_8 ( const char * V_15 ,
unsigned int V_2 , unsigned int V_3 ,
struct V_1 * V_1 )
{
struct V_16 * V_11 = V_1 -> V_11 . V_12 ;
struct V_17 * V_18 = V_11 -> V_19 ;
unsigned int V_4 = F_9 ( V_3 ) ;
unsigned int V_20 = V_2 << V_4 ;
unsigned int V_21 , V_22 , V_23 ;
const T_1 * V_24 ;
if ( ! V_18 )
return - V_25 ;
if ( ! V_15 )
V_15 = L_2 ;
V_24 = F_10 ( V_18 , V_15 , & V_21 ) ;
if ( ! V_24 ) {
F_5 ( V_11 , L_3 ,
V_15 , V_18 -> V_26 ) ;
return - V_25 ;
}
if ( V_21 % sizeof( V_27 ) ) {
F_5 ( V_11 , L_4 ,
V_15 , V_18 -> V_26 ) ;
return - V_28 ;
}
V_23 = V_21 / sizeof( V_27 ) ;
if ( V_23 > V_20 ) {
F_5 ( V_11 , L_5 , V_15 ) ;
return - V_28 ;
}
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
unsigned int V_5 = F_11 ( V_24 + V_22 ) ;
if ( ! F_1 ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) )
return - V_28 ;
}
return 0 ;
}
static int F_8 ( const char * V_15 ,
unsigned int V_2 , unsigned int V_3 ,
struct V_1 * V_1 )
{
return - V_29 ;
}
int F_12 ( const struct V_30 * V_31 ,
const char * V_32 ,
unsigned int V_2 , unsigned int V_3 ,
unsigned short * V_6 ,
struct V_1 * V_1 )
{
unsigned int V_4 = F_9 ( V_3 ) ;
int V_22 ;
int error ;
V_1 -> V_7 = V_6 ;
V_1 -> V_33 = sizeof( * V_6 ) ;
V_1 -> V_34 = V_2 << V_4 ;
F_7 ( V_35 , V_1 -> V_36 ) ;
if ( V_31 ) {
for ( V_22 = 0 ; V_22 < V_31 -> V_37 ; V_22 ++ ) {
unsigned int V_5 = V_31 -> V_6 [ V_22 ] ;
if ( ! F_1 ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) )
return - V_28 ;
}
} else {
error = F_8 ( V_32 , V_2 , V_3 ,
V_1 ) ;
if ( error )
return error ;
}
F_13 ( V_38 , V_1 -> V_14 ) ;
return 0 ;
}
