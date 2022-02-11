static int F_1 ( struct V_1 * V_2 )
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
static int F_3 ( struct V_1 * V_2 )
{
struct V_1 * V_14 = NULL ;
struct V_15 * V_16 ;
int V_6 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
V_6 = F_4 ( V_2 -> V_21 -> V_22 , V_2 -> V_21 -> V_23 ,
V_2 -> V_21 -> V_24 , & V_14 ) ;
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
F_5 ( V_14 ) ;
V_18 = F_6 ( V_14 -> V_21 ) ;
F_7 ( L_1 ,
& V_18 -> V_29 , F_8 ( V_18 -> V_30 ) ,
& V_18 -> V_31 , F_8 ( V_18 -> V_32 ) ) ;
V_16 = F_9 ( V_18 -> V_29 , V_18 -> V_31 ,
& V_33 , V_34 ) ;
if ( F_10 ( V_16 ) ) {
V_6 = F_11 ( V_16 ) ;
goto V_25;
}
V_20 = (struct V_19 * ) V_16 -> V_35 ;
F_12 ( ! V_20 || V_20 -> V_36 ) ;
if ( ! F_13 ( V_16 , V_37 , V_38 ) ) {
if ( F_14 ( V_16 ) == V_39 )
F_15 ( V_40 ) ;
else
F_15 ( V_41 ) ;
F_16 ( V_16 ) ;
V_6 = 0 ;
goto V_25;
}
F_17 ( V_14 , V_16 ) ;
F_18 ( V_16 ) ;
V_14 = NULL ;
V_6 = 0 ;
V_25:
if ( V_14 )
F_19 ( V_14 ) ;
return V_6 ;
}
static void F_20 ( struct V_42 * V_43 )
{
while ( F_3 ( V_44 ) == 0 )
F_21 () ;
}
void F_22 ( struct V_2 * V_21 )
{
void (* F_23)( struct V_2 * V_21 );
F_7 ( L_2 , V_21 ) ;
F_24 ( & V_21 -> V_45 ) ;
F_23 = V_21 -> V_46 ;
if ( ! F_23 ) {
F_23 = V_21 -> V_47 ;
goto V_25;
}
if ( V_21 -> V_48 == V_49 )
F_25 ( V_50 , & V_51 ) ;
V_25:
F_26 ( & V_21 -> V_45 ) ;
F_23 ( V_21 ) ;
}
int F_27 ( void )
{
struct V_52 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_28 ( V_53 , V_54 , V_10 , & V_2 ) ;
if ( V_6 < 0 )
goto V_25;
V_2 -> V_21 -> V_55 = V_56 ;
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_21 -> V_45 ) ;
V_2 -> V_21 -> V_46 = V_2 -> V_21 -> V_47 ;
V_2 -> V_21 -> V_47 = F_22 ;
F_31 ( & V_2 -> V_21 -> V_45 ) ;
sin . V_57 = V_53 ;
sin . V_58 . V_59 = ( V_60 V_61 ) F_32 ( V_62 ) ;
sin . V_63 = ( V_60 V_64 ) F_33 ( V_65 ) ;
V_6 = V_2 -> V_26 -> V_66 ( V_2 , (struct V_67 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_25;
V_6 = V_2 -> V_26 -> V_68 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_25;
V_44 = V_2 ;
V_2 = NULL ;
V_25:
if ( V_2 )
F_19 ( V_2 ) ;
return V_6 ;
}
void F_34 ( void )
{
struct V_1 * V_2 = V_44 ;
struct V_2 * V_21 ;
if ( ! V_2 )
return;
V_21 = V_2 -> V_21 ;
F_35 ( V_21 ) ;
F_30 ( & V_21 -> V_45 ) ;
if ( V_21 -> V_46 ) {
V_21 -> V_47 = V_21 -> V_46 ;
V_21 -> V_46 = NULL ;
}
F_31 ( & V_21 -> V_45 ) ;
F_36 ( V_21 ) ;
F_37 ( V_50 ) ;
F_19 ( V_2 ) ;
V_44 = NULL ;
}
