static unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 * sizeof( struct V_4 ) ;
}
static int F_2 ( struct V_5 * V_6 )
{
struct V_1 * V_7 ;
struct V_4 * V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 = F_3 ( V_6 ) ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 ;
int V_22 = 0 ;
bool V_23 ;
int V_24 ;
unsigned int V_25 ;
V_10 = V_15 -> V_26 ;
if ( V_15 -> V_27 -> V_28 == V_29 ) {
V_25 = F_4 ( V_6 ) -> V_25 ;
V_17 = (struct V_16 * ) V_15 ;
} else if ( V_15 -> V_27 -> V_28 == V_30 ) {
V_25 = F_5 ( V_6 ) -> V_31 ;
V_19 = (struct V_18 * ) V_15 ;
} else {
goto V_32;
}
F_6 ( V_6 ) ;
if ( ! F_7 ( V_10 ) ||
! V_15 -> V_33 || F_8 ( V_6 ) )
goto V_32;
F_9 ( V_6 ) ;
V_7 = F_10 ( V_15 -> V_33 ) ;
V_12 = F_1 ( V_7 ) ;
V_13 = F_11 ( V_10 ) ;
if ( F_12 ( V_6 , V_13 - V_12 ) )
goto V_32;
V_11 = F_13 ( V_10 ) ;
if ( ! V_10 -> V_34 )
V_11 = 0 ;
if ( F_14 ( V_6 , V_11 + V_12 ) )
goto V_32;
F_15 ( V_6 , V_6 -> V_35 ) ;
F_16 ( V_6 ) ;
F_17 ( V_6 , V_12 ) ;
F_18 ( V_6 ) ;
V_6 -> V_26 = V_10 ;
V_6 -> V_35 = F_19 ( V_36 ) ;
V_8 = F_20 ( V_6 ) ;
V_23 = true ;
for ( V_24 = V_7 -> V_3 - 1 ; V_24 >= 0 ; V_24 -- ) {
V_8 [ V_24 ] = F_21 ( V_7 -> V_37 [ V_24 ] ,
V_25 , 0 , V_23 ) ;
V_23 = false ;
}
F_22 ( V_10 , V_6 ) ;
if ( V_17 )
V_22 = F_23 ( V_38 , V_10 , & V_17 -> V_39 ,
V_6 ) ;
else if ( V_19 )
V_22 = F_23 ( V_40 , V_10 , & V_19 -> V_41 ,
V_6 ) ;
if ( V_22 )
F_24 ( L_1 ,
V_42 , V_22 ) ;
return V_43 ;
V_32:
V_21 = V_10 ? F_25 ( V_10 ) : NULL ;
if ( V_21 )
F_26 ( V_21 , V_44 ) ;
F_27 ( V_6 ) ;
return - V_45 ;
}
static int F_28 ( struct V_46 * V_47 ,
unsigned int V_28 , const void * V_48 ,
struct V_49 * * V_50 )
{
struct V_1 * V_7 ;
struct V_46 * V_51 [ V_52 + 1 ] ;
struct V_49 * V_53 ;
int V_54 ;
V_54 = F_29 ( V_51 , V_52 , V_47 ,
V_55 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! V_51 [ V_56 ] )
return - V_45 ;
V_53 = F_30 ( sizeof( * V_7 ) ) ;
if ( ! V_53 )
return - V_57 ;
V_7 = F_10 ( V_53 ) ;
V_54 = F_31 ( V_51 [ V_56 ] , V_58 ,
& V_7 -> V_3 , V_7 -> V_37 ) ;
if ( V_54 )
goto V_59;
V_53 -> type = V_60 ;
V_53 -> V_61 |= V_62 ;
V_53 -> V_63 = F_1 ( V_7 ) ;
* V_50 = V_53 ;
return 0 ;
V_59:
F_32 ( V_53 ) ;
* V_50 = NULL ;
return V_54 ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_49 * V_33 )
{
struct V_1 * V_7 ;
V_7 = F_10 ( V_33 ) ;
if ( F_34 ( V_6 , V_56 , V_7 -> V_3 ,
V_7 -> V_37 ) )
goto V_64;
return 0 ;
V_64:
return - V_65 ;
}
static int F_35 ( struct V_49 * V_33 )
{
struct V_1 * V_7 ;
V_7 = F_10 ( V_33 ) ;
return F_36 ( V_7 -> V_3 * 4 ) ;
}
static int F_37 ( struct V_49 * V_66 , struct V_49 * V_67 )
{
struct V_1 * V_68 = F_10 ( V_66 ) ;
struct V_1 * V_69 = F_10 ( V_67 ) ;
int V_70 ;
if ( V_68 -> V_3 != V_69 -> V_3 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_58 ; V_70 ++ )
if ( V_68 -> V_37 [ V_70 ] != V_69 -> V_37 [ V_70 ] )
return 1 ;
return 0 ;
}
static int T_1 F_38 ( void )
{
return F_39 ( & V_71 , V_60 ) ;
}
static void T_2 F_40 ( void )
{
F_41 ( & V_71 , V_60 ) ;
}
