int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , enum V_7 V_8 )
{
if ( V_4 && V_4 -> error ) {
F_2 ( L_1 ) ;
goto V_9;
}
if ( V_8 & V_10 ) {
if ( V_6 -> V_11 > V_2 -> V_6 . V_12 ) {
F_2 ( L_2 ,
V_6 -> V_11 , V_2 -> V_6 . V_12 ) ;
goto V_9;
}
if ( V_6 -> V_11 <= 0 ) {
F_2 ( L_3 , V_6 -> V_11 ) ;
goto V_9;
}
if ( V_4 && V_4 -> V_13 && ( V_6 -> V_11 < V_4 -> V_13 ) ) {
F_2 ( L_4 ,
V_6 -> V_11 , V_4 -> V_13 ) ;
goto V_9;
}
if ( V_6 -> V_11 < V_14 )
V_6 -> V_11 = V_14 ;
}
if ( V_8 & V_15 ) {
if ( V_6 -> V_16 > V_2 -> V_6 . V_12 ) {
F_2 ( L_5 ,
V_6 -> V_16 , V_2 -> V_6 . V_12 ) ;
goto V_9;
}
if ( V_4 && ( V_6 -> V_16 > V_4 -> V_17 . V_18 -> V_19 -> V_20 ) ) {
F_2 ( L_6 ,
V_6 -> V_16 ,
V_4 -> V_17 . V_18 -> V_19 -> V_20 ) ;
goto V_9;
}
}
if ( V_8 == V_21 ) {
if ( V_6 -> V_22 > V_2 -> V_6 . V_23 ) {
F_2 ( L_7 ,
V_6 -> V_22 , V_2 -> V_6 . V_23 ) ;
goto V_9;
}
if ( V_6 -> V_22 < V_24 )
V_6 -> V_22 = V_24 ;
}
return 0 ;
V_9:
return - V_25 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_26 * V_27 ,
struct V_28 * V_29 , struct V_30 * V_31 )
{
int V_32 ;
int V_33 ;
struct V_34 * V_35 ;
V_4 -> V_36 . V_37 = V_27 -> V_37 ;
V_4 -> V_36 . V_38 = V_27 -> V_38 ;
V_4 -> V_13 = V_27 -> V_6 . V_16 ;
V_4 -> V_39 = V_4 -> V_40 . V_41 ;
V_4 -> V_17 . V_11 = V_27 -> V_6 . V_11 ;
V_4 -> V_17 . V_22 = V_27 -> V_6 . V_22 ;
V_33 = F_4 ( V_4 -> V_17 . V_22 ) ;
F_5 ( & V_4 -> V_17 . V_42 ) ;
F_5 ( & V_4 -> V_17 . V_43 ) ;
V_35 = F_6 ( V_2 , & V_4 -> V_17 . V_11 ,
V_33 ) ;
if ( ! V_35 ) {
F_2 ( L_8 ) ;
return - V_44 ;
}
V_4 -> V_17 . V_18 = V_35 ;
V_32 = F_7 ( V_2 , V_31 , false , V_29 , V_35 -> V_19 ,
V_35 -> V_45 , & V_35 -> V_46 ) ;
if ( V_32 )
return V_32 ;
if ( V_31 && V_31 -> V_47 >= sizeof( struct V_48 ) + sizeof( V_49 ) ) {
if ( F_8 ( V_31 -> V_50 + sizeof( struct V_48 ) ,
& V_4 -> V_39 , sizeof( V_49 ) ) )
return - V_51 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , enum V_7 V_8 ,
struct V_30 * V_31 )
{
int V_32 ;
struct V_34 * V_35 = V_4 -> V_17 . V_18 ;
struct V_48 V_52 = { . V_53 = 1 , . V_54 = 0 } ;
if ( V_8 & V_10 ) {
if ( V_31 && V_31 -> V_55 >= sizeof( V_56 ) ) {
V_56 V_57 ;
V_32 = F_10 ( & V_57 , V_31 ,
sizeof( V_57 ) ) ;
if ( V_32 )
goto V_9;
V_31 -> V_50 = ( void V_58 * ) ( unsigned long ) V_57 ;
V_31 -> V_47 = sizeof( V_52 ) ;
if ( ! F_11 ( V_59 ,
( void V_58 * ) V_31 -> V_50 ,
V_31 -> V_47 ) ) {
V_32 = - V_51 ;
goto V_9;
}
}
V_32 = F_12 ( V_35 , ( unsigned int * ) & V_6 -> V_11 ,
F_4 ( V_4 -> V_17 . V_22 ) ,
V_4 -> V_17 . V_18 -> V_46 ?
V_4 -> V_17 . V_18 -> V_46 -> V_29 :
NULL ,
V_31 , & V_4 -> V_17 . V_42 ,
& V_4 -> V_17 . V_43 ) ;
if ( V_32 )
goto V_60;
}
if ( V_8 & V_15 )
V_4 -> V_13 = V_6 -> V_16 ;
return 0 ;
V_60:
F_13 ( V_35 ) ;
V_4 -> V_17 . V_18 = NULL ;
V_9:
return V_32 ;
}
