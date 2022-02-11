static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
unsigned int V_8 ;
if ( F_2 ( V_2 -> V_9 >= V_10 * V_11 ) )
return;
V_6 = & V_12 [ V_2 -> V_9 >> V_13 ] ;
V_8 = V_2 -> V_9 & V_14 ;
V_7 = V_6 -> V_15 . V_16 + V_17 ;
V_4 -> V_18 = F_3 ( V_7 ) ;
V_4 -> V_19 = F_4 ( V_7 ) ;
V_4 -> V_20 = V_8 << V_21 ;
}
static int F_5 ( struct V_22 * V_23 , unsigned int V_24 ,
unsigned int V_25 , void * args )
{
struct V_5 * V_6 = NULL ;
struct V_26 V_27 ;
struct V_1 * V_2 ;
unsigned int V_9 , V_8 ;
int V_28 ;
F_6 ( & V_29 ) ;
V_9 = F_7 ( V_30 , V_11 * V_10 ) ;
if ( V_9 >= V_11 * V_10 ) {
F_8 ( & V_29 ) ;
return - V_31 ;
}
F_9 ( V_9 , V_30 ) ;
F_8 ( & V_29 ) ;
V_6 = & V_12 [ V_9 >> V_13 ] ;
V_8 = V_9 & V_14 ;
V_27 . V_32 = V_23 -> V_33 -> V_32 ;
V_27 . V_34 = 3 ;
V_27 . V_35 [ 0 ] = V_36 ;
V_27 . V_35 [ 1 ] = V_6 -> V_37 - 32 + V_8 ;
V_27 . V_35 [ 2 ] = V_38 ;
V_28 = F_10 ( V_23 , V_24 , 1 , & V_27 ) ;
if ( V_28 ) {
F_11 ( L_1 ) ;
F_6 ( & V_29 ) ;
F_12 ( V_8 , V_30 ) ;
F_8 ( & V_29 ) ;
return V_28 ;
}
V_2 = F_13 ( V_23 -> V_33 , V_24 ) ;
V_2 -> V_39 -> V_40 ( V_2 , V_38 ) ;
F_14 ( V_23 , V_24 , V_9 ,
& V_41 , NULL ) ;
return 0 ;
}
static void F_15 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_13 ( V_23 , V_24 ) ;
if ( V_2 -> V_9 >= V_10 * V_11 ) {
F_11 ( L_2 , V_2 -> V_9 ) ;
return;
}
F_16 ( V_23 , V_24 , V_25 ) ;
F_6 ( & V_29 ) ;
F_12 ( V_2 -> V_9 , V_30 ) ;
F_8 ( & V_29 ) ;
}
static int T_2 F_17 ( struct V_42 * V_43 ,
struct V_42 * V_33 )
{
struct V_22 * V_44 , * V_45 ;
int V_28 , V_46 ;
if ( F_18 ( V_43 , L_3 , & V_10 ) )
return - V_47 ;
V_12 = F_19 ( V_10 , sizeof( struct V_5 ) , V_48 ) ;
if ( ! V_12 )
return - V_49 ;
V_30 = F_19 ( F_20 ( V_10 * V_11 ) ,
sizeof( long ) , V_48 ) ;
if ( ! V_30 ) {
V_28 = - V_49 ;
goto V_50;
}
for ( V_46 = 0 ; V_46 < V_10 ; V_46 ++ ) {
struct V_5 * V_6 = & V_12 [ V_46 ] ;
V_28 = F_21 ( V_43 , V_46 , & V_6 -> V_15 ) ;
if ( V_28 )
goto V_51;
V_6 -> V_52 = F_22 ( V_43 , V_46 , L_4 ) ;
if ( F_23 ( V_6 -> V_52 ) ) {
V_28 = F_24 ( V_6 -> V_52 ) ;
goto V_51;
}
if ( F_25 ( V_43 , L_5 ,
V_46 , & V_6 -> V_37 ) ) {
V_28 = - V_47 ;
goto V_51;
}
}
V_44 = F_26 ( F_27 ( V_43 ) ,
V_10 * V_11 ,
& V_53 , NULL ) ;
if ( ! V_44 ) {
V_28 = - V_49 ;
goto V_51;
}
V_44 -> V_33 = F_28 ( V_33 ) ;
V_45 = F_29 ( F_27 ( V_43 ) ,
& V_54 ,
V_44 ) ;
if ( ! V_45 ) {
V_28 = - V_49 ;
goto V_55;
}
return 0 ;
V_55:
F_30 ( V_44 ) ;
V_51:
for ( V_46 = 0 ; V_46 < V_10 ; V_46 ++ ) {
struct V_5 * V_6 = & V_12 [ V_46 ] ;
if ( V_6 -> V_52 && ! F_23 ( V_6 -> V_52 ) )
F_31 ( V_12 [ V_46 ] . V_52 ) ;
}
F_32 ( V_30 ) ;
V_50:
F_32 ( V_12 ) ;
return V_28 ;
}
