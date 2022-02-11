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
struct V_19 * V_20 ;
V_6 = F_4 ( F_5 ( V_2 -> V_21 ) , V_2 -> V_21 -> V_22 ,
V_2 -> V_21 -> V_23 , V_2 -> V_21 -> V_24 ,
& V_14 ) ;
if ( V_6 )
goto V_25;
V_14 -> type = V_2 -> type ;
V_14 -> V_26 = V_2 -> V_26 ;
V_6 = V_2 -> V_26 -> V_27 ( V_2 , V_14 , V_28 ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = F_1 ( V_14 ) ;
if ( V_6 < 0 )
goto V_25;
F_6 ( V_14 ) ;
V_18 = F_7 ( V_14 -> V_21 ) ;
F_8 ( L_1 ,
& V_18 -> V_29 , F_9 ( V_18 -> V_30 ) ,
& V_18 -> V_31 , F_9 ( V_18 -> V_32 ) ) ;
V_16 = F_10 ( F_5 ( V_2 -> V_21 ) ,
V_18 -> V_29 , V_18 -> V_31 ,
& V_33 , V_34 ) ;
if ( F_11 ( V_16 ) ) {
V_6 = F_12 ( V_16 ) ;
goto V_25;
}
V_20 = (struct V_19 * ) V_16 -> V_35 ;
if ( V_20 -> V_36 &&
F_13 ( V_18 -> V_29 ) < F_13 ( V_18 -> V_31 ) ) {
struct V_2 * V_37 = V_14 -> V_21 ;
V_37 -> V_38 = NULL ;
V_37 -> V_39 -> V_40 ( V_37 , 0 ) ;
F_14 ( V_37 ) ;
V_14 = NULL ;
V_6 = 0 ;
goto V_25;
} else if ( V_20 -> V_36 ) {
F_15 ( V_20 -> V_36 , V_20 ) ;
V_16 -> V_41 = 0 ;
}
F_16 ( V_16 , V_42 , V_43 ) ;
F_17 ( V_14 , V_16 ) ;
F_18 ( V_16 ) ;
V_14 = NULL ;
V_6 = 0 ;
V_25:
if ( V_14 )
F_19 ( V_14 ) ;
return V_6 ;
}
void F_20 ( struct V_2 * V_21 )
{
void (* F_21)( struct V_2 * V_21 );
F_8 ( L_2 , V_21 ) ;
F_22 ( & V_21 -> V_44 ) ;
F_21 = V_21 -> V_38 ;
if ( ! F_21 ) {
F_21 = V_21 -> V_45 ;
goto V_25;
}
if ( V_21 -> V_46 == V_47 )
F_23 ( V_21 ) ;
V_25:
F_24 ( & V_21 -> V_44 ) ;
F_21 ( V_21 ) ;
}
struct V_1 * F_25 ( struct V_48 * V_48 )
{
struct V_49 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_4 ( V_48 , V_50 , V_51 , V_10 , & V_2 ) ;
if ( V_6 < 0 )
goto V_25;
V_2 -> V_21 -> V_52 = V_53 ;
F_26 ( V_2 ) ;
F_27 ( & V_2 -> V_21 -> V_44 ) ;
V_2 -> V_21 -> V_38 = V_2 -> V_21 -> V_45 ;
V_2 -> V_21 -> V_45 = F_20 ;
F_28 ( & V_2 -> V_21 -> V_44 ) ;
sin . V_54 = V_50 ;
sin . V_55 . V_56 = ( V_57 V_58 ) F_29 ( V_59 ) ;
sin . V_60 = ( V_57 V_61 ) F_30 ( V_62 ) ;
V_6 = V_2 -> V_26 -> V_63 ( V_2 , (struct V_64 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = V_2 -> V_26 -> V_65 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_25;
return V_2 ;
V_25:
if ( V_2 )
F_19 ( V_2 ) ;
return NULL ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_2 * V_21 ;
if ( ! V_2 )
return;
V_21 = V_2 -> V_21 ;
F_32 ( V_21 ) ;
F_27 ( & V_21 -> V_44 ) ;
if ( V_21 -> V_38 ) {
V_21 -> V_45 = V_21 -> V_38 ;
V_21 -> V_38 = NULL ;
}
F_28 ( & V_21 -> V_44 ) ;
F_33 ( V_21 ) ;
F_34 ( V_66 ) ;
F_19 ( V_2 ) ;
}
