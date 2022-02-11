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
static int T_2 F_5 ( struct V_16 * V_17 ,
struct V_18 * V_15 ,
struct V_19 * V_13 )
{
struct V_16 * V_20 ;
int V_9 ;
F_6 (np, child) {
struct V_5 * V_6 ;
const char * V_11 ;
if ( F_7 ( V_20 , L_2 ,
L_3 ) < 0 )
continue;
V_6 = F_8 ( V_15 , sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
V_6 -> V_13 = V_13 ;
if ( F_9 ( V_20 , L_4 , & V_6 -> V_14 ) )
return - V_23 ;
if ( F_9 ( V_20 , L_5 , & V_6 -> V_12 ) )
return - V_23 ;
V_6 -> V_7 . V_24 =
F_10 ( V_20 , L_6 , NULL ) ? : V_20 -> V_24 ;
V_6 -> V_7 . V_25 =
F_10 ( V_20 , L_7 , NULL ) ;
V_11 = F_10 ( V_20 , L_8 , NULL ) ;
if ( V_11 ) {
if ( ! strcmp ( V_11 , L_9 ) ) {
T_1 V_8 ;
V_9 = F_11 ( V_13 , V_6 -> V_14 , & V_8 ) ;
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
V_6 -> V_7 . V_26 = F_1 ;
V_9 = F_12 ( V_15 , & V_6 -> V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
F_13 ( V_15 , L_11 , V_6 -> V_7 . V_24 ) ;
}
return 0 ;
}
static int T_2 F_14 ( void )
{
struct V_16 * V_17 ;
F_15 (np) {
struct V_27 * V_28 ;
struct V_19 * V_13 ;
int V_9 ;
if ( ! F_16 ( V_17 , L_12 ) )
continue;
V_13 = F_17 ( V_17 ) ;
if ( F_18 ( V_13 ) ) {
F_19 ( L_13 ) ;
continue;
}
V_28 = F_20 ( V_17 ) ;
if ( ! V_28 )
return - V_29 ;
V_9 = F_5 ( V_17 , & V_28 -> V_15 , V_13 ) ;
if ( V_9 )
F_4 ( & V_28 -> V_15 , L_14 ) ;
}
return 0 ;
}
