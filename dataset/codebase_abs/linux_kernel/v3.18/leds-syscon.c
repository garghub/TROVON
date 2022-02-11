static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
T_1 V_8 ;
int V_9 ;
if ( V_4 == V_10 ) {
V_8 = 0 ;
V_6 -> V_11 = false ;
} else {
V_8 = V_6 -> V_12 ;
V_6 -> V_11 = true ;
}
V_9 = F_3 ( V_6 -> V_13 , V_6 -> V_14 , V_6 -> V_12 , V_8 ) ;
if ( V_9 < 0 )
F_4 ( V_6 -> V_7 . V_15 , L_1 ) ;
}
static int T_2 F_5 ( void )
{
const struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
struct V_21 * V_13 ;
struct V_22 * V_23 ;
struct V_24 * V_15 ;
int V_9 ;
V_19 = F_6 ( NULL , V_25 ,
& V_17 ) ;
if ( ! V_19 )
return - V_26 ;
V_13 = F_7 ( V_19 ) ;
if ( F_8 ( V_13 ) )
return F_9 ( V_13 ) ;
V_23 = F_10 ( V_19 ) ;
if ( ! V_23 )
return - V_26 ;
V_15 = & V_23 -> V_15 ;
F_11 (np, child) {
struct V_5 * V_6 ;
const char * V_11 ;
if ( F_12 ( V_20 , L_2 ,
L_3 ) < 0 )
continue;
V_6 = F_13 ( V_15 , sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 )
return - V_28 ;
V_6 -> V_13 = V_13 ;
if ( F_14 ( V_20 , L_4 , & V_6 -> V_14 ) )
return - V_29 ;
if ( F_14 ( V_20 , L_5 , & V_6 -> V_12 ) )
return - V_29 ;
V_6 -> V_7 . V_30 =
F_15 ( V_20 , L_6 , NULL ) ? : V_20 -> V_30 ;
V_6 -> V_7 . V_31 =
F_15 ( V_20 , L_7 , NULL ) ;
V_11 = F_15 ( V_20 , L_8 , NULL ) ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_9 ) ) {
T_1 V_8 ;
V_9 = F_16 ( V_13 , V_6 -> V_14 , & V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 -> V_11 = ! ! ( V_8 & V_6 -> V_12 ) ;
} else if ( ! strcmp ( V_11 , L_10 ) ) {
V_6 -> V_11 = true ;
V_9 = F_3 ( V_13 , V_6 -> V_14 ,
V_6 -> V_12 ,
V_6 -> V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
} else {
V_6 -> V_11 = false ;
V_9 = F_3 ( V_13 , V_6 -> V_14 ,
V_6 -> V_12 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
}
}
V_6 -> V_7 . V_32 = F_1 ;
V_9 = F_17 ( V_15 , & V_6 -> V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
F_18 ( V_15 , L_11 , V_6 -> V_7 . V_30 ) ;
}
return 0 ;
}
