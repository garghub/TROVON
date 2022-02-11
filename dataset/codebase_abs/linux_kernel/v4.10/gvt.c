int F_1 ( void )
{
int V_1 ;
if ( V_2 . V_3 )
return 0 ;
if ( F_2 () && ! F_3 () )
return - V_4 ;
if ( F_3 () ) {
V_2 . V_5 = F_4 (
F_5 ( V_6 ) , L_1 ) ;
V_2 . V_7 = V_8 ;
} else {
#if F_6 ( V_9 )
V_2 . V_5 = F_4 (
F_5 ( V_10 ) , L_2 ) ;
V_2 . V_7 = V_11 ;
#endif
}
if ( ! V_2 . V_5 )
return - V_12 ;
V_1 = F_7 () ;
if ( V_1 )
return - V_4 ;
F_8 ( L_3 ,
V_13 [ V_2 . V_7 ] ) ;
V_2 . V_3 = true ;
return 0 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_18 ;
struct V_19 * V_20 = V_15 -> V_21 -> V_22 . V_20 ;
if ( F_10 ( V_15 -> V_21 ) || F_11 ( V_15 -> V_21 ) ) {
V_17 -> V_23 = 8 ;
V_17 -> V_24 = 256 ;
V_17 -> V_25 = 2 * 1024 * 1024 ;
V_17 -> V_26 = 0 ;
V_17 -> V_27 = 8 * 1024 * 1024 ;
V_17 -> V_28 = 8 ;
V_17 -> V_29 = 3 ;
V_17 -> V_30 = 8 ;
V_17 -> V_31 = 36 * 1024 * 1024 ;
}
V_17 -> V_32 = V_20 -> V_33 ;
}
static int F_12 ( void * V_34 )
{
struct V_14 * V_15 = (struct V_14 * ) V_34 ;
int V_1 ;
F_8 ( L_4 ) ;
while ( ! F_13 () ) {
V_1 = F_14 ( V_15 -> V_35 ,
F_13 () || V_15 -> V_36 ) ;
if ( F_13 () )
break;
if ( F_15 ( V_1 , L_5 ) )
continue;
if ( F_16 ( V_37 ,
( void * ) & V_15 -> V_36 ) ) {
F_17 ( & V_15 -> V_38 ) ;
F_18 ( V_15 ) ;
F_19 ( & V_15 -> V_38 ) ;
}
}
return 0 ;
}
static void F_20 ( struct V_14 * V_15 )
{
F_21 ( V_15 -> V_39 ) ;
}
static int F_22 ( struct V_14 * V_15 )
{
F_23 ( & V_15 -> V_35 ) ;
V_15 -> V_39 = F_24 ( F_12 ,
V_15 , L_6 ) ;
if ( F_25 ( V_15 -> V_39 ) ) {
F_26 ( L_7 ) ;
return F_27 ( V_15 -> V_39 ) ;
}
return 0 ;
}
void F_28 ( struct V_40 * V_21 )
{
struct V_14 * V_15 = F_29 ( V_21 ) ;
if ( F_30 ( ! V_15 ) )
return;
F_20 ( V_15 ) ;
F_31 ( V_15 ) ;
F_32 ( V_15 ) ;
F_33 ( V_15 ) ;
F_34 ( V_15 ) ;
F_35 ( V_15 ) ;
F_36 ( V_15 ) ;
F_37 ( V_15 ) ;
F_38 ( V_15 ) ;
F_39 ( & V_21 -> V_22 . V_20 -> V_41 , V_15 ) ;
F_40 ( V_15 ) ;
F_41 ( & V_15 -> V_42 ) ;
F_42 ( V_21 -> V_15 ) ;
V_21 -> V_15 = NULL ;
}
int F_43 ( struct V_40 * V_21 )
{
struct V_14 * V_15 ;
int V_1 ;
if ( F_30 ( ! V_2 . V_3 ) )
return - V_12 ;
if ( F_30 ( V_21 -> V_15 ) )
return - V_43 ;
V_15 = F_44 ( sizeof( struct V_14 ) , V_44 ) ;
if ( ! V_15 )
return - V_45 ;
F_8 ( L_8 ) ;
F_45 ( & V_15 -> V_42 ) ;
F_46 ( & V_15 -> V_38 ) ;
V_15 -> V_21 = V_21 ;
F_9 ( V_15 ) ;
V_1 = F_47 ( V_15 ) ;
if ( V_1 )
goto V_46;
V_1 = F_48 ( V_15 ) ;
if ( V_1 )
goto V_47;
V_1 = F_49 ( V_15 ) ;
if ( V_1 )
goto V_48;
V_1 = F_50 ( V_15 ) ;
if ( V_1 )
goto V_49;
V_1 = F_51 ( V_15 ) ;
if ( V_1 )
goto V_50;
V_1 = F_52 ( V_15 ) ;
if ( V_1 )
goto V_51;
V_1 = F_53 ( V_15 ) ;
if ( V_1 )
goto V_52;
V_1 = F_54 ( V_15 ) ;
if ( V_1 )
goto V_53;
V_1 = F_22 ( V_15 ) ;
if ( V_1 )
goto V_54;
V_1 = F_55 ( V_15 ) ;
if ( V_1 )
goto V_55;
V_1 = F_56 ( & V_21 -> V_22 . V_20 -> V_41 , V_15 ,
& V_56 ) ;
if ( V_1 ) {
F_26 ( L_9 , V_1 ) ;
goto V_57;
}
F_8 ( L_10 ) ;
V_21 -> V_15 = V_15 ;
return 0 ;
V_57:
F_40 ( V_15 ) ;
V_55:
F_20 ( V_15 ) ;
V_54:
F_31 ( V_15 ) ;
V_53:
F_32 ( V_15 ) ;
V_52:
F_33 ( V_15 ) ;
V_51:
F_34 ( V_15 ) ;
V_50:
F_35 ( V_15 ) ;
V_49:
F_36 ( V_15 ) ;
V_48:
F_38 ( V_15 ) ;
V_47:
F_37 ( V_15 ) ;
V_46:
F_41 ( & V_15 -> V_42 ) ;
F_42 ( V_15 ) ;
return V_1 ;
}
