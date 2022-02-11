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
static int F_5 ( struct V_16 * V_17 )
{
struct V_18 * V_15 = & V_17 -> V_15 ;
struct V_19 * V_20 = V_15 -> V_21 ;
struct V_18 * V_22 ;
struct V_23 * V_13 ;
struct V_5 * V_6 ;
const char * V_11 ;
int V_9 ;
V_22 = V_15 -> V_22 ;
if ( ! V_22 ) {
F_4 ( V_15 , L_2 ) ;
return - V_24 ;
}
V_13 = F_6 ( V_22 -> V_21 ) ;
if ( ! V_13 ) {
F_4 ( V_15 , L_3 ) ;
return - V_24 ;
}
V_6 = F_7 ( V_15 , sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_13 = V_13 ;
if ( F_8 ( V_20 , L_4 , & V_6 -> V_14 ) )
return - V_27 ;
if ( F_8 ( V_20 , L_5 , & V_6 -> V_12 ) )
return - V_27 ;
V_6 -> V_7 . V_28 =
F_9 ( V_20 , L_6 , NULL ) ? : V_20 -> V_28 ;
V_6 -> V_7 . V_29 =
F_9 ( V_20 , L_7 , NULL ) ;
V_11 = F_9 ( V_20 , L_8 , NULL ) ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_9 ) ) {
T_1 V_8 ;
V_9 = F_10 ( V_13 , V_6 -> V_14 , & V_8 ) ;
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
V_6 -> V_7 . V_30 = F_1 ;
V_9 = F_11 ( V_15 , & V_6 -> V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
F_12 ( V_17 , V_6 ) ;
F_13 ( V_15 , L_11 , V_6 -> V_7 . V_28 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_15 ( V_17 ) ;
F_16 ( & V_6 -> V_7 ) ;
F_3 ( V_6 -> V_13 , V_6 -> V_14 , V_6 -> V_12 , 0 ) ;
return 0 ;
}
