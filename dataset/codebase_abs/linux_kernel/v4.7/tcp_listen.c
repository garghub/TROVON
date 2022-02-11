int F_1 ( struct V_1 * V_2 )
{
int V_3 = 5 ;
int V_4 = 5 ;
int V_5 = 1 ;
int V_6 = 0 ;
V_6 = F_2 ( V_2 , V_7 , V_8 ,
( char * ) & V_5 , sizeof( V_5 ) ) ;
if ( V_6 < 0 )
goto V_9;
V_6 = F_2 ( V_2 , V_10 , V_11 ,
( char * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
goto V_9;
V_6 = F_2 ( V_2 , V_10 , V_12 ,
( char * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_6 < 0 )
goto V_9;
V_6 = F_2 ( V_2 , V_10 , V_13 ,
( char * ) & V_3 , sizeof( V_3 ) ) ;
V_9:
return V_6 ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = NULL ;
struct V_15 * V_16 ;
int V_6 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = NULL ;
int V_21 ;
if ( ! V_2 )
return - V_22 ;
V_6 = F_4 ( F_5 ( V_2 -> V_23 ) , V_2 -> V_23 -> V_24 ,
V_2 -> V_23 -> V_25 , V_2 -> V_23 -> V_26 ,
& V_14 ) ;
if ( V_6 )
goto V_27;
V_14 -> type = V_2 -> type ;
V_14 -> V_28 = V_2 -> V_28 ;
V_6 = V_2 -> V_28 -> V_29 ( V_2 , V_14 , V_30 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_1 ( V_14 ) ;
if ( V_6 < 0 )
goto V_27;
F_6 ( V_14 ) ;
V_18 = F_7 ( V_14 -> V_23 ) ;
F_8 ( L_1 ,
& V_18 -> V_31 , F_9 ( V_18 -> V_32 ) ,
& V_18 -> V_33 , F_9 ( V_18 -> V_34 ) ) ;
V_16 = F_10 ( F_5 ( V_2 -> V_23 ) ,
V_18 -> V_31 , V_18 -> V_33 ,
& V_35 , V_36 ) ;
if ( F_11 ( V_16 ) ) {
V_6 = F_12 ( V_16 ) ;
goto V_27;
}
V_20 = (struct V_19 * ) V_16 -> V_37 ;
F_13 ( V_16 , V_38 , V_39 ) ;
F_14 ( & V_20 -> V_40 ) ;
V_21 = F_15 ( V_16 ) ;
if ( V_21 != V_39 && V_21 != V_41 )
goto V_42;
if ( V_20 -> V_43 ) {
if ( F_16 ( V_18 -> V_31 ) < F_16 ( V_18 -> V_33 ) ||
! V_16 -> V_44 ) {
goto V_42;
} else {
F_17 ( V_14 , V_16 ) ;
V_16 -> V_44 = 0 ;
F_18 ( V_16 , V_45 ) ;
}
} else {
F_19 ( V_14 , V_16 ) ;
F_18 ( V_16 , V_39 ) ;
}
V_14 = NULL ;
V_6 = 0 ;
goto V_27;
V_42:
F_20 ( V_14 , V_46 ) ;
V_6 = 0 ;
V_27:
if ( V_20 )
F_21 ( & V_20 -> V_40 ) ;
if ( V_14 )
F_22 ( V_14 ) ;
return V_6 ;
}
void F_23 ( struct V_2 * V_23 )
{
void (* F_24)( struct V_2 * V_23 );
F_8 ( L_2 , V_23 ) ;
F_25 ( & V_23 -> V_47 ) ;
F_24 = V_23 -> V_48 ;
if ( ! F_24 ) {
F_24 = V_23 -> V_49 ;
goto V_27;
}
if ( V_23 -> V_50 == V_51 )
F_26 ( V_23 ) ;
V_27:
F_27 ( & V_23 -> V_47 ) ;
F_24 ( V_23 ) ;
}
struct V_1 * F_28 ( struct V_52 * V_52 )
{
struct V_53 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_4 ( V_52 , V_54 , V_55 , V_10 , & V_2 ) ;
if ( V_6 < 0 )
goto V_27;
V_2 -> V_23 -> V_56 = V_57 ;
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_23 -> V_47 ) ;
V_2 -> V_23 -> V_48 = V_2 -> V_23 -> V_49 ;
V_2 -> V_23 -> V_49 = F_23 ;
F_31 ( & V_2 -> V_23 -> V_47 ) ;
sin . V_58 = V_54 ;
sin . V_59 . V_60 = ( V_61 V_62 ) F_32 ( V_63 ) ;
sin . V_64 = ( V_61 V_65 ) F_33 ( V_66 ) ;
V_6 = V_2 -> V_28 -> V_67 ( V_2 , (struct V_68 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = V_2 -> V_28 -> V_69 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_27;
return V_2 ;
V_27:
if ( V_2 )
F_22 ( V_2 ) ;
return NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_2 * V_23 ;
if ( ! V_2 )
return;
V_23 = V_2 -> V_23 ;
F_35 ( V_23 ) ;
F_30 ( & V_23 -> V_47 ) ;
if ( V_23 -> V_48 ) {
V_23 -> V_49 = V_23 -> V_48 ;
V_23 -> V_48 = NULL ;
}
F_31 ( & V_23 -> V_47 ) ;
F_36 ( V_23 ) ;
F_37 ( V_70 ) ;
F_22 ( V_2 ) ;
}
