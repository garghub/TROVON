static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 , V_9 , V_10 ;
V_7 = F_2 ( V_2 , V_3 , & V_8 ) ;
if ( ! V_7 ) {
F_3 ( L_1 ,
F_4 ( V_2 ) , V_3 ) ;
return - V_11 ;
}
V_9 = V_8 / sizeof( V_12 ) ;
if ( V_9 == 1 ) {
V_10 = F_5 ( V_2 , V_3 , & V_5 -> V_13 ) ;
V_5 -> V_14 = V_5 -> V_13 ;
V_5 -> V_15 = V_5 -> V_13 ;
} else if ( V_9 == 3 ) {
V_10 = F_6 ( V_2 , V_3 , & V_5 -> V_14 , V_9 ) ;
} else {
F_3 ( L_2 ,
F_4 ( V_2 ) , V_3 ) ;
return - V_11 ;
}
return V_10 ;
}
static struct V_16 * F_7 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_12 V_18 = 0 ;
int V_10 = 0 ;
V_17 = F_8 ( sizeof( * V_17 ) , V_19 ) ;
if ( ! V_17 ) {
F_3 ( L_3 ,
F_4 ( V_2 ) ) ;
return NULL ;
}
V_10 |= F_1 ( V_2 , L_4 , & V_17 -> V_20 ) ;
V_10 |= F_1 ( V_2 , L_5 , & V_17 -> V_21 ) ;
V_10 |= F_1 ( V_2 , L_6 , & V_17 -> V_22 ) ;
V_10 |= F_1 ( V_2 , L_7 , & V_17 -> V_23 ) ;
V_10 |= F_1 ( V_2 , L_8 , & V_17 -> V_24 ) ;
V_10 |= F_1 ( V_2 , L_9 , & V_17 -> V_25 ) ;
V_10 |= F_1 ( V_2 , L_10 , & V_17 -> V_26 ) ;
V_10 |= F_1 ( V_2 , L_11 , & V_17 -> V_27 ) ;
V_10 |= F_1 ( V_2 , L_12 , & V_17 -> V_28 ) ;
V_17 -> V_29 = 0 ;
V_17 -> V_30 = 0 ;
if ( ! F_5 ( V_2 , L_13 , & V_18 ) )
V_17 -> V_29 |= V_18 ? V_31 :
V_32 ;
if ( ! F_5 ( V_2 , L_14 , & V_18 ) )
V_17 -> V_29 |= V_18 ? V_33 :
V_34 ;
if ( ! F_5 ( V_2 , L_15 , & V_18 ) )
V_17 -> V_30 |= V_18 ? V_35 :
V_36 ;
if ( ! F_5 ( V_2 , L_16 , & V_18 ) )
V_17 -> V_30 |= V_18 ? V_37 :
V_38 ;
if ( F_9 ( V_2 , L_17 ) )
V_17 -> V_30 |= V_39 ;
if ( F_9 ( V_2 , L_18 ) )
V_17 -> V_30 |= V_40 ;
if ( V_10 ) {
F_3 ( L_19 ,
F_4 ( V_2 ) ) ;
F_10 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
struct V_41 * F_11 ( struct V_1 * V_2 )
{
struct V_1 * V_42 ;
struct V_1 * V_43 ;
struct V_1 * V_44 ;
struct V_41 * V_45 ;
if ( ! V_2 ) {
F_3 ( L_20 , F_4 ( V_2 ) ) ;
return NULL ;
}
V_42 = F_12 ( V_2 , L_21 ) ;
if ( ! V_42 ) {
F_3 ( L_22 ,
F_4 ( V_2 ) ) ;
return NULL ;
}
V_45 = F_8 ( sizeof( * V_45 ) , V_19 ) ;
if ( ! V_45 ) {
F_3 ( L_23 ,
F_4 ( V_2 ) ) ;
goto V_46;
}
V_43 = F_13 ( V_42 , L_24 , 0 ) ;
if ( ! V_43 )
V_43 = F_14 ( V_2 , NULL ) ;
if ( ! V_43 ) {
F_3 ( L_25 ,
F_4 ( V_2 ) ) ;
goto V_47;
}
F_15 ( L_26 ,
F_4 ( V_2 ) , V_43 -> V_3 ) ;
V_44 = V_43 ;
V_45 -> V_48 = F_16 ( V_42 ) ;
if ( V_45 -> V_48 == 0 ) {
F_3 ( L_27 , F_4 ( V_2 ) ) ;
goto V_47;
}
V_45 -> V_49 = F_8 ( sizeof( struct V_16 * ) *
V_45 -> V_48 , V_19 ) ;
if ( ! V_45 -> V_49 ) {
F_3 ( L_28 ,
F_4 ( V_2 ) ) ;
goto V_47;
}
V_45 -> V_48 = 0 ;
V_45 -> V_44 = 0 ;
F_17 (timings_np, entry) {
struct V_16 * V_17 ;
V_17 = F_7 ( V_43 ) ;
if ( ! V_17 ) {
F_3 ( L_29 ,
F_4 ( V_2 ) , V_45 -> V_48 + 1 ) ;
goto V_50;
}
if ( V_44 == V_43 )
V_45 -> V_44 = V_45 -> V_48 ;
V_45 -> V_49 [ V_45 -> V_48 ] = V_17 ;
V_45 -> V_48 ++ ;
}
F_18 ( V_42 ) ;
F_18 ( V_44 ) ;
F_15 ( L_30 ,
F_4 ( V_2 ) , V_45 -> V_48 ,
V_45 -> V_44 + 1 ) ;
return V_45 ;
V_50:
if ( V_44 )
F_18 ( V_44 ) ;
F_19 ( V_45 ) ;
V_47:
F_10 ( V_45 ) ;
V_46:
F_18 ( V_42 ) ;
return NULL ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_1 * V_42 ;
if ( ! V_2 )
return - V_11 ;
V_42 = F_13 ( V_2 , L_21 , 0 ) ;
if ( ! V_42 )
return - V_11 ;
F_18 ( V_42 ) ;
return 1 ;
}
