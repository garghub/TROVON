static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = NULL ;
struct V_4 * V_5 ;
int V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 -> V_9 -> V_10 , V_2 -> V_9 -> V_11 ,
V_2 -> V_9 -> V_12 , & V_3 ) ;
if ( V_6 )
goto V_13;
V_3 -> type = V_2 -> type ;
V_3 -> V_14 = V_2 -> V_14 ;
V_6 = V_2 -> V_14 -> V_15 ( V_2 , V_3 , V_16 ) ;
if ( V_6 < 0 )
goto V_13;
F_3 ( V_3 ) ;
V_8 = F_4 ( V_3 -> V_9 ) ;
F_5 ( L_1 ,
& V_8 -> V_17 , F_6 ( V_8 -> V_18 ) ,
& V_8 -> V_19 , F_6 ( V_8 -> V_20 ) ) ;
V_5 = F_7 ( V_8 -> V_17 , V_8 -> V_19 ,
& V_21 , V_22 ) ;
if ( F_8 ( V_5 ) ) {
V_6 = F_9 ( V_5 ) ;
goto V_13;
}
if ( ! F_10 ( V_5 , V_23 , V_24 ) ) {
if ( F_11 ( V_5 ) == V_25 )
F_12 ( V_26 ) ;
else
F_12 ( V_27 ) ;
F_13 ( V_5 ) ;
V_6 = 0 ;
goto V_13;
}
F_14 ( V_3 , V_5 ) ;
F_15 ( V_5 ) ;
V_3 = NULL ;
V_6 = 0 ;
V_13:
if ( V_3 )
F_16 ( V_3 ) ;
return V_6 ;
}
static void F_17 ( struct V_28 * V_29 )
{
while ( F_1 ( V_30 ) == 0 )
F_18 () ;
}
void F_19 ( struct V_2 * V_9 , int V_31 )
{
void (* F_20)( struct V_2 * V_9 , int V_31 );
F_5 ( L_2 , V_9 ) ;
F_21 ( & V_9 -> V_32 ) ;
F_20 = V_9 -> V_33 ;
if ( ! F_20 ) {
F_20 = V_9 -> V_34 ;
goto V_13;
}
if ( V_9 -> V_35 == V_36 )
F_22 ( V_37 , & V_38 ) ;
V_13:
F_23 ( & V_9 -> V_32 ) ;
F_20 ( V_9 , V_31 ) ;
}
int F_24 ( void )
{
struct V_39 sin ;
struct V_1 * V_2 = NULL ;
int V_6 ;
V_6 = F_25 ( V_40 , V_41 , V_42 , & V_2 ) ;
if ( V_6 < 0 )
goto V_13;
V_2 -> V_9 -> V_43 = 1 ;
F_26 ( V_2 ) ;
F_27 ( & V_2 -> V_9 -> V_32 ) ;
V_2 -> V_9 -> V_33 = V_2 -> V_9 -> V_34 ;
V_2 -> V_9 -> V_34 = F_19 ;
F_28 ( & V_2 -> V_9 -> V_32 ) ;
sin . V_44 = V_40 ,
sin . V_45 . V_46 = ( V_47 V_48 ) F_29 ( V_49 ) ;
sin . V_50 = ( V_47 V_51 ) F_30 ( V_52 ) ;
V_6 = V_2 -> V_14 -> V_53 ( V_2 , (struct V_54 * ) & sin , sizeof( sin ) ) ;
if ( V_6 < 0 )
goto V_13;
V_6 = V_2 -> V_14 -> V_55 ( V_2 , 64 ) ;
if ( V_6 < 0 )
goto V_13;
V_30 = V_2 ;
V_2 = NULL ;
V_13:
if ( V_2 )
F_16 ( V_2 ) ;
return V_6 ;
}
void F_31 ( void )
{
struct V_1 * V_2 = V_30 ;
struct V_2 * V_9 ;
if ( ! V_2 )
return;
V_9 = V_2 -> V_9 ;
F_32 ( V_9 ) ;
F_27 ( & V_9 -> V_32 ) ;
if ( V_9 -> V_33 ) {
V_9 -> V_34 = V_9 -> V_33 ;
V_9 -> V_33 = NULL ;
}
F_28 ( & V_9 -> V_32 ) ;
F_33 ( V_9 ) ;
F_34 ( V_37 ) ;
F_16 ( V_2 ) ;
V_30 = NULL ;
}
