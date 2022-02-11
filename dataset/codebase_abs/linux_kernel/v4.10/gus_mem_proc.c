static T_1 F_1 ( struct V_1 * V_2 ,
void * V_3 ,
struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_13 ;
V_13 = F_2 ( V_12 , V_5 , V_7 , V_6 , V_9 -> V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_4 ( V_9 ) ;
}
int F_5 ( struct V_11 * V_12 )
{
int V_15 ;
char V_16 [ 16 ] ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( V_12 -> V_17 . V_18 . V_19 [ V_15 ] . V_20 > 0 ) {
V_9 = F_6 ( sizeof( * V_9 ) , V_21 ) ;
if ( V_9 == NULL )
return - V_22 ;
V_9 -> V_12 = V_12 ;
sprintf ( V_16 , L_1 , V_15 ) ;
if ( ! F_7 ( V_12 -> V_23 , V_16 , & V_2 ) ) {
V_2 -> V_24 = V_25 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_26 = F_3 ;
V_2 -> V_27 . V_28 = & V_29 ;
V_9 -> V_30 = V_12 -> V_17 . V_18 . V_19 [ V_15 ] . V_30 ;
V_9 -> V_20 = V_2 -> V_20 = V_12 -> V_17 . V_18 . V_19 [ V_15 ] . V_20 ;
}
}
}
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( V_12 -> V_17 . V_31 & ( 1 << V_15 ) ) {
V_9 = F_6 ( sizeof( * V_9 ) , V_21 ) ;
if ( V_9 == NULL )
return - V_22 ;
V_9 -> V_14 = 1 ;
V_9 -> V_12 = V_12 ;
sprintf ( V_16 , L_2 , V_15 ) ;
if ( ! F_7 ( V_12 -> V_23 , V_16 , & V_2 ) ) {
V_2 -> V_24 = V_25 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_26 = F_3 ;
V_2 -> V_27 . V_28 = & V_29 ;
V_9 -> V_30 = V_15 * 4096 * 1024 ;
V_9 -> V_20 = V_2 -> V_20 = V_12 -> V_17 . V_32 ;
}
}
}
return 0 ;
}
