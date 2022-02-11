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
struct V_16 * V_17 = V_11 -> V_18 ;
if ( ! V_17 ) {
F_5 ( V_11 , L_2 ) ;
return - V_19 ;
}
F_9 ( V_17 , L_3 , V_2 ) ;
F_9 ( V_17 , L_4 , V_3 ) ;
if ( ! * V_2 || ! * V_3 ) {
F_5 ( V_11 , L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_10 ( const char * V_20 ,
unsigned int V_2 , unsigned int V_3 ,
struct V_1 * V_1 )
{
struct V_15 * V_11 = V_1 -> V_11 . V_12 ;
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned int V_4 = F_11 ( V_3 ) ;
unsigned int V_21 = V_2 << V_4 ;
unsigned int V_22 , V_23 , V_24 ;
const T_1 * V_25 ;
if ( ! V_17 )
return - V_26 ;
if ( ! V_20 )
V_20 = L_6 ;
V_25 = F_12 ( V_17 , V_20 , & V_22 ) ;
if ( ! V_25 ) {
F_5 ( V_11 , L_7 ,
V_20 , V_17 -> V_27 ) ;
return - V_26 ;
}
if ( V_22 % sizeof( V_28 ) ) {
F_5 ( V_11 , L_8 ,
V_20 , V_17 -> V_27 ) ;
return - V_19 ;
}
V_24 = V_22 / sizeof( V_28 ) ;
if ( V_24 > V_21 ) {
F_5 ( V_11 , L_9 , V_20 ) ;
return - V_19 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
unsigned int V_5 = F_13 ( V_25 + V_23 ) ;
if ( ! F_1 ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) )
return - V_19 ;
}
return 0 ;
}
static int F_10 ( const char * V_20 ,
unsigned int V_2 , unsigned int V_3 ,
struct V_1 * V_1 )
{
return - V_29 ;
}
int F_14 ( const struct V_30 * V_31 ,
const char * V_32 ,
unsigned int V_2 , unsigned int V_3 ,
unsigned short * V_6 ,
struct V_1 * V_1 )
{
unsigned int V_4 = F_11 ( V_3 ) ;
T_2 V_21 = V_2 << V_4 ;
int V_23 ;
int error ;
if ( F_15 ( ! V_1 -> V_11 . V_12 ) )
return - V_19 ;
if ( ! V_6 ) {
V_6 = F_16 ( V_1 -> V_11 . V_12 ,
V_21 * sizeof( * V_6 ) ,
V_33 ) ;
if ( ! V_6 ) {
F_5 ( V_1 -> V_11 . V_12 ,
L_10 ) ;
return - V_34 ;
}
}
V_1 -> V_7 = V_6 ;
V_1 -> V_35 = sizeof( * V_6 ) ;
V_1 -> V_36 = V_21 ;
F_7 ( V_37 , V_1 -> V_38 ) ;
if ( V_31 ) {
for ( V_23 = 0 ; V_23 < V_31 -> V_39 ; V_23 ++ ) {
unsigned int V_5 = V_31 -> V_6 [ V_23 ] ;
if ( ! F_1 ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) )
return - V_19 ;
}
} else {
error = F_10 ( V_32 , V_2 , V_3 ,
V_1 ) ;
if ( error )
return error ;
}
F_17 ( V_40 , V_1 -> V_14 ) ;
return 0 ;
}
