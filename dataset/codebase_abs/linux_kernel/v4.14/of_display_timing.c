static int F_1 ( const struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 , V_9 , V_10 ;
V_7 = F_2 ( V_2 , V_3 , & V_8 ) ;
if ( ! V_7 ) {
F_3 ( L_1 , V_2 , V_3 ) ;
return - V_11 ;
}
V_9 = V_8 / sizeof( V_12 ) ;
if ( V_9 == 1 ) {
V_10 = F_4 ( V_2 , V_3 , & V_5 -> V_13 ) ;
V_5 -> V_14 = V_5 -> V_13 ;
V_5 -> V_15 = V_5 -> V_13 ;
} else if ( V_9 == 3 ) {
V_10 = F_5 ( V_2 , V_3 , & V_5 -> V_14 , V_9 ) ;
} else {
F_3 ( L_2 , V_2 , V_3 ) ;
return - V_11 ;
}
return V_10 ;
}
static int F_6 ( const struct V_1 * V_2 ,
struct V_16 * V_17 )
{
V_12 V_18 = 0 ;
int V_10 = 0 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_10 |= F_1 ( V_2 , L_3 , & V_17 -> V_19 ) ;
V_10 |= F_1 ( V_2 , L_4 , & V_17 -> V_20 ) ;
V_10 |= F_1 ( V_2 , L_5 , & V_17 -> V_21 ) ;
V_10 |= F_1 ( V_2 , L_6 , & V_17 -> V_22 ) ;
V_10 |= F_1 ( V_2 , L_7 , & V_17 -> V_23 ) ;
V_10 |= F_1 ( V_2 , L_8 , & V_17 -> V_24 ) ;
V_10 |= F_1 ( V_2 , L_9 , & V_17 -> V_25 ) ;
V_10 |= F_1 ( V_2 , L_10 , & V_17 -> V_26 ) ;
V_10 |= F_1 ( V_2 , L_11 , & V_17 -> V_27 ) ;
V_17 -> V_28 = 0 ;
if ( ! F_4 ( V_2 , L_12 , & V_18 ) )
V_17 -> V_28 |= V_18 ? V_29 :
V_30 ;
if ( ! F_4 ( V_2 , L_13 , & V_18 ) )
V_17 -> V_28 |= V_18 ? V_31 :
V_32 ;
if ( ! F_4 ( V_2 , L_14 , & V_18 ) )
V_17 -> V_28 |= V_18 ? V_33 :
V_34 ;
if ( ! F_4 ( V_2 , L_15 , & V_18 ) )
V_17 -> V_28 |= V_18 ? V_35 :
V_36 ;
if ( ! F_4 ( V_2 , L_16 , & V_18 ) )
V_17 -> V_28 |= V_18 ? V_37 :
V_38 ;
else if ( V_17 -> V_28 & ( V_35 |
V_36 ) )
V_17 -> V_28 |= V_17 -> V_28 & V_35 ?
V_37 :
V_38 ;
if ( F_7 ( V_2 , L_17 ) )
V_17 -> V_28 |= V_39 ;
if ( F_7 ( V_2 , L_18 ) )
V_17 -> V_28 |= V_40 ;
if ( F_7 ( V_2 , L_19 ) )
V_17 -> V_28 |= V_41 ;
if ( V_10 ) {
F_3 ( L_20 , V_2 ) ;
return - V_11 ;
}
return 0 ;
}
int F_8 ( const struct V_1 * V_2 , const char * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_42 ;
if ( ! V_2 )
return - V_11 ;
V_42 = F_9 ( V_2 , V_3 ) ;
if ( ! V_42 ) {
F_3 ( L_21 , V_2 , V_3 ) ;
return - V_43 ;
}
return F_6 ( V_42 , V_17 ) ;
}
struct V_44 * F_10 ( const struct V_1 * V_2 )
{
struct V_1 * V_45 ;
struct V_1 * V_46 ;
struct V_1 * V_47 ;
struct V_44 * V_48 ;
if ( ! V_2 )
return NULL ;
V_45 = F_9 ( V_2 , L_22 ) ;
if ( ! V_45 ) {
F_3 ( L_23 , V_2 ) ;
return NULL ;
}
V_48 = F_11 ( sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 ) {
F_3 ( L_24 , V_2 ) ;
goto V_50;
}
V_46 = F_12 ( V_45 , L_25 , 0 ) ;
if ( ! V_46 )
V_46 = F_13 ( V_45 , NULL ) ;
if ( ! V_46 ) {
F_3 ( L_26 , V_2 ) ;
goto V_51;
}
F_14 ( L_27 , V_2 , V_46 -> V_3 ) ;
V_47 = V_46 ;
V_48 -> V_52 = F_15 ( V_45 ) ;
if ( V_48 -> V_52 == 0 ) {
F_3 ( L_28 , V_2 ) ;
goto V_51;
}
V_48 -> V_53 = F_11 ( sizeof( struct V_16 * ) *
V_48 -> V_52 , V_49 ) ;
if ( ! V_48 -> V_53 ) {
F_3 ( L_29 , V_2 ) ;
goto V_51;
}
V_48 -> V_52 = 0 ;
V_48 -> V_47 = 0 ;
F_16 (timings_np, entry) {
struct V_16 * V_17 ;
int V_54 ;
V_17 = F_11 ( sizeof( * V_17 ) , V_49 ) ;
if ( ! V_17 ) {
F_3 ( L_30 ,
V_2 ) ;
goto V_55;
}
V_54 = F_6 ( V_46 , V_17 ) ;
if ( V_54 ) {
F_3 ( L_31 ,
V_2 , V_48 -> V_52 + 1 ) ;
F_17 ( V_17 ) ;
goto V_55;
}
if ( V_47 == V_46 )
V_48 -> V_47 = V_48 -> V_52 ;
V_48 -> V_53 [ V_48 -> V_52 ] = V_17 ;
V_48 -> V_52 ++ ;
}
F_18 ( V_45 ) ;
F_18 ( V_47 ) ;
F_14 ( L_32 ,
V_2 , V_48 -> V_52 ,
V_48 -> V_47 + 1 ) ;
return V_48 ;
V_55:
F_18 ( V_47 ) ;
F_19 ( V_48 ) ;
V_48 = NULL ;
V_51:
F_17 ( V_48 ) ;
V_50:
F_18 ( V_45 ) ;
return NULL ;
}
int F_20 ( const struct V_1 * V_2 )
{
struct V_1 * V_45 ;
if ( ! V_2 )
return - V_11 ;
V_45 = F_12 ( V_2 , L_22 , 0 ) ;
if ( ! V_45 )
return - V_11 ;
F_18 ( V_45 ) ;
return 1 ;
}
