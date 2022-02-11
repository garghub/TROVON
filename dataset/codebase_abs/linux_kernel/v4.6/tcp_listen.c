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
struct V_2 * V_22 ;
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
F_16 ( V_16 -> V_44 ,
! F_17 ( V_45 , & V_16 -> V_46 ) ) ;
if ( F_18 ( V_18 -> V_31 ) < F_18 ( V_18 -> V_33 ) ) {
goto V_42;
} else if ( V_20 -> V_43 ) {
F_19 ( V_20 -> V_43 , V_20 ) ;
V_16 -> V_47 = 0 ;
}
}
F_20 ( V_14 , V_16 ) ;
F_21 ( V_16 ) ;
V_14 = NULL ;
V_6 = 0 ;
goto V_27;
V_42:
V_22 = V_14 -> V_23 ;
F_22 ( V_48 ) ;
V_22 -> V_49 = NULL ;
V_22 -> V_50 -> V_51 ( V_22 , 0 ) ;
F_23 ( V_22 ) ;
V_14 = NULL ;
V_6 = 0 ;
V_27:
if ( V_20 )
F_24 ( & V_20 -> V_40 ) ;
if ( V_14 )
F_25 ( V_14 ) ;
return V_6 ;
}
void F_26 ( struct V_2 * V_23 )
{
void (* F_27)( struct V_2 * V_23 );
F_8 ( L_2 , V_23 ) ;
F_28 ( & V_23 -> V_52 ) ;
F_27 = V_23 -> V_49 ;
if ( ! F_27 ) {
F_27 = V_23 -> V_53 ;
goto V_27;
}
if ( V_23 -> V_54 == V_55 )
F_29 ( V_23 ) ;
V_27:
F_30 ( & V_23 -> V_52 ) ;
F_27 ( V_23 ) ;
}
struct V_1 * F_31 ( struct V_56 * V_56 )
{
struct V_57 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_4 ( V_56 , V_58 , V_59 , V_10 , & V_2 ) ;
if ( V_6 < 0 )
goto V_27;
V_2 -> V_23 -> V_60 = V_61 ;
F_32 ( V_2 ) ;
F_33 ( & V_2 -> V_23 -> V_52 ) ;
V_2 -> V_23 -> V_49 = V_2 -> V_23 -> V_53 ;
V_2 -> V_23 -> V_53 = F_26 ;
F_34 ( & V_2 -> V_23 -> V_52 ) ;
sin . V_62 = V_58 ;
sin . V_63 . V_64 = ( V_65 V_66 ) F_35 ( V_67 ) ;
sin . V_68 = ( V_65 V_69 ) F_36 ( V_70 ) ;
V_6 = V_2 -> V_28 -> V_71 ( V_2 , (struct V_72 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = V_2 -> V_28 -> V_73 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_27;
return V_2 ;
V_27:
if ( V_2 )
F_25 ( V_2 ) ;
return NULL ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_2 * V_23 ;
if ( ! V_2 )
return;
V_23 = V_2 -> V_23 ;
F_38 ( V_23 ) ;
F_33 ( & V_23 -> V_52 ) ;
if ( V_23 -> V_49 ) {
V_23 -> V_53 = V_23 -> V_49 ;
V_23 -> V_49 = NULL ;
}
F_34 ( & V_23 -> V_52 ) ;
F_39 ( V_23 ) ;
F_40 ( V_74 ) ;
F_25 ( V_2 ) ;
}
