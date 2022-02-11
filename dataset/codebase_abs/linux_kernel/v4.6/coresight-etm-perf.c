static void F_1 ( struct V_1 * V_2 ) {}
static int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . type != V_4 . type )
return - V_5 ;
return 0 ;
}
static void F_3 ( struct V_6 * V_7 )
{
int V_8 ;
T_1 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_4 ( V_7 , struct V_10 , V_7 ) ;
V_9 = & V_11 -> V_9 ;
if ( V_11 -> V_14 ) {
V_8 = F_5 ( V_9 ) ;
V_13 = F_6 ( V_11 -> V_15 [ V_8 ] ) ;
if ( F_7 ( V_13 ) -> V_16 )
F_7 ( V_13 ) -> V_16 ( V_11 -> V_14 ) ;
}
F_8 (cpu, mask) {
if ( V_11 -> V_15 [ V_8 ] )
F_9 ( V_11 -> V_15 [ V_8 ] ) ;
}
F_10 ( V_11 -> V_15 ) ;
F_10 ( V_11 ) ;
}
static void * F_11 ( int V_8 )
{
int V_17 ;
T_1 * V_9 ;
struct V_10 * V_11 ;
V_11 = F_12 ( sizeof( struct V_10 ) , V_18 ) ;
if ( ! V_11 )
return NULL ;
F_13 () ;
V_17 = F_14 () ;
V_9 = & V_11 -> V_9 ;
if ( V_8 != - 1 )
F_15 ( V_8 , V_9 ) ;
else
F_16 ( V_9 , V_19 ) ;
F_17 () ;
V_11 -> V_15 = F_18 ( V_17 ,
sizeof( struct V_20 * ) , V_18 ) ;
if ( ! V_11 -> V_15 ) {
F_10 ( V_11 ) ;
return NULL ;
}
return V_11 ;
}
static void F_19 ( void * V_21 )
{
struct V_10 * V_11 = V_21 ;
F_20 ( & V_11 -> V_7 ) ;
}
static void * F_21 ( int V_22 , void * * V_23 ,
int V_24 , bool V_25 )
{
int V_8 ;
T_1 * V_9 ;
struct V_12 * V_13 ;
struct V_10 * V_11 = NULL ;
V_11 = F_11 ( V_22 ) ;
if ( ! V_11 )
return NULL ;
F_22 ( & V_11 -> V_7 , F_3 ) ;
V_9 = & V_11 -> V_9 ;
F_8 (cpu, mask) {
struct V_12 * V_26 ;
V_26 = F_23 ( V_27 , V_8 ) ;
if ( ! V_26 )
goto V_28;
V_11 -> V_15 [ V_8 ] = F_24 ( V_26 ) ;
if ( ! V_11 -> V_15 [ V_8 ] )
goto V_28;
}
V_8 = F_5 ( V_9 ) ;
V_13 = F_6 ( V_11 -> V_15 [ V_8 ] ) ;
if ( ! V_13 )
goto V_28;
if ( ! F_7 ( V_13 ) -> V_29 )
goto V_28;
V_11 -> V_14 =
F_7 ( V_13 ) -> V_29 ( V_13 , V_8 , V_23 ,
V_24 , V_25 ) ;
if ( ! V_11 -> V_14 )
goto V_28;
V_30:
return V_11 ;
V_28:
F_19 ( V_11 ) ;
V_11 = NULL ;
goto V_30;
}
static void F_25 ( struct V_1 * V_2 , int V_31 )
{
int V_8 = F_26 () ;
struct V_10 * V_11 ;
struct V_32 * V_33 = F_27 ( & V_34 ) ;
struct V_12 * V_13 , * V_26 = F_23 ( V_27 , V_8 ) ;
if ( ! V_26 )
goto V_35;
V_11 = F_28 ( V_33 , V_2 ) ;
if ( ! V_11 )
goto V_35;
V_13 = F_6 ( V_11 -> V_15 [ V_8 ] ) ;
if ( F_29 ( ! V_13 || ! F_7 ( V_13 ) -> V_36 ) )
goto V_37;
if ( F_7 ( V_13 ) -> V_36 ( V_13 , V_33 ,
V_11 -> V_14 ) )
goto V_37;
if ( F_30 ( V_11 -> V_15 [ V_8 ] , V_38 ) )
goto V_37;
V_2 -> V_39 . V_40 = 0 ;
if ( F_31 ( V_26 ) -> F_32 ( V_26 , & V_2 -> V_3 , V_38 ) )
goto V_37;
V_30:
return;
V_37:
F_33 ( V_33 , 0 , true ) ;
V_35:
V_2 -> V_39 . V_40 = V_41 ;
goto V_30;
}
static void F_34 ( struct V_1 * V_2 , int V_42 )
{
bool V_43 ;
int V_8 = F_26 () ;
unsigned long V_17 ;
struct V_12 * V_13 , * V_26 = F_23 ( V_27 , V_8 ) ;
struct V_32 * V_33 = F_27 ( & V_34 ) ;
struct V_10 * V_11 = F_35 ( V_33 ) ;
if ( V_2 -> V_39 . V_40 == V_41 )
return;
if ( ! V_26 )
return;
V_13 = F_6 ( V_11 -> V_15 [ V_8 ] ) ;
if ( ! V_13 )
return;
F_31 ( V_26 ) -> F_36 ( V_26 ) ;
V_2 -> V_39 . V_40 = V_41 ;
if ( V_42 & V_44 ) {
if ( F_29 ( V_33 -> V_2 != V_2 ) )
return;
if ( ! F_7 ( V_13 ) -> V_45 )
return;
F_7 ( V_13 ) -> V_45 ( V_13 , V_33 ,
V_11 -> V_14 ) ;
if ( ! F_7 ( V_13 ) -> V_46 )
return;
V_17 = F_7 ( V_13 ) -> V_46 ( V_13 , V_33 ,
V_11 -> V_14 ,
& V_43 ) ;
F_33 ( V_33 , V_17 , V_43 ) ;
}
F_37 ( V_11 -> V_15 [ V_8 ] ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_42 )
{
int V_47 = 0 ;
struct V_48 * V_49 = & V_2 -> V_39 ;
if ( V_42 & V_50 ) {
F_25 ( V_2 , 0 ) ;
if ( V_49 -> V_40 & V_41 )
V_47 = - V_51 ;
} else {
V_49 -> V_40 = V_41 ;
}
return V_47 ;
}
static void F_39 ( struct V_1 * V_2 , int V_42 )
{
F_34 ( V_2 , V_44 ) ;
}
int F_40 ( struct V_12 * V_26 , bool V_52 )
{
char V_53 [ sizeof( L_1 ) ] ;
int V_47 = 0 , V_8 = F_31 ( V_26 ) -> F_41 ( V_26 ) ;
struct V_54 * V_55 = V_4 . V_56 ;
struct V_54 * V_57 = & V_26 -> V_56 ;
sprintf ( V_53 , L_2 , V_8 ) ;
if ( ! V_58 )
return - V_59 ;
if ( V_52 ) {
V_47 = F_42 ( & V_55 -> V_60 , & V_57 -> V_60 , V_53 ) ;
if ( V_47 )
return V_47 ;
F_23 ( V_27 , V_8 ) = V_26 ;
} else {
F_43 ( & V_55 -> V_60 , V_53 ) ;
F_23 ( V_27 , V_8 ) = NULL ;
}
return 0 ;
}
static int T_2 F_44 ( void )
{
int V_47 ;
V_4 . V_61 = V_62 ;
V_4 . V_63 = V_64 ;
V_4 . V_65 = V_66 ;
V_4 . V_67 = F_1 ;
V_4 . V_68 = F_2 ;
V_4 . V_69 = F_21 ;
V_4 . V_70 = F_19 ;
V_4 . V_71 = F_25 ;
V_4 . V_72 = F_34 ;
V_4 . V_73 = F_38 ;
V_4 . V_74 = F_39 ;
V_47 = F_45 ( & V_4 , V_75 , - 1 ) ;
if ( V_47 == 0 )
V_58 = true ;
return V_47 ;
}
