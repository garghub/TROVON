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
int V_20 = 0 ;
bool V_21 ;
int V_22 ;
unsigned int V_23 ;
if ( V_15 -> V_24 -> V_25 == V_26 ) {
V_23 = F_4 ( V_6 ) -> V_23 ;
V_17 = (struct V_16 * ) V_15 ;
} else if ( V_15 -> V_24 -> V_25 == V_27 ) {
V_23 = F_5 ( V_6 ) -> V_28 ;
V_19 = (struct V_18 * ) V_15 ;
} else {
goto V_29;
}
F_6 ( V_6 ) ;
V_10 = V_15 -> V_30 ;
if ( ! F_7 ( V_10 ) ||
! V_15 -> V_31 || F_8 ( V_6 ) )
goto V_29;
F_9 ( V_6 ) ;
V_7 = F_10 ( V_15 -> V_31 ) ;
V_12 = F_1 ( V_7 ) ;
V_13 = F_11 ( V_10 ) ;
if ( F_12 ( V_6 , V_13 - V_12 ) )
goto V_29;
V_11 = F_13 ( V_10 ) ;
if ( ! V_10 -> V_32 )
V_11 = 0 ;
if ( F_14 ( V_6 , V_11 + V_12 ) )
goto V_29;
F_15 ( V_6 , V_6 -> V_33 ) ;
F_16 ( V_6 ) ;
F_17 ( V_6 , V_12 ) ;
F_18 ( V_6 ) ;
V_6 -> V_30 = V_10 ;
V_6 -> V_33 = F_19 ( V_34 ) ;
V_8 = F_20 ( V_6 ) ;
V_21 = true ;
for ( V_22 = V_7 -> V_3 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_8 [ V_22 ] = F_21 ( V_7 -> V_35 [ V_22 ] ,
V_23 , 0 , V_21 ) ;
V_21 = false ;
}
if ( V_17 )
V_20 = F_22 ( V_36 , V_10 , & V_17 -> V_37 ,
V_6 ) ;
else if ( V_19 )
V_20 = F_22 ( V_38 , V_10 , & V_19 -> V_39 ,
V_6 ) ;
if ( V_20 )
F_23 ( L_1 ,
V_40 , V_20 ) ;
return V_41 ;
V_29:
F_24 ( V_6 ) ;
return - V_42 ;
}
static int F_25 ( struct V_9 * V_30 , struct V_43 * V_44 ,
unsigned int V_25 , const void * V_45 ,
struct V_46 * * V_47 )
{
struct V_1 * V_7 ;
struct V_43 * V_48 [ V_49 + 1 ] ;
struct V_46 * V_50 ;
int V_51 ;
V_51 = F_26 ( V_48 , V_49 , V_44 ,
V_52 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ! V_48 [ V_53 ] )
return - V_42 ;
V_50 = F_27 ( sizeof( * V_7 ) ) ;
if ( ! V_50 )
return - V_54 ;
V_7 = F_10 ( V_50 ) ;
V_51 = F_28 ( V_48 [ V_53 ] , V_55 ,
& V_7 -> V_3 , V_7 -> V_35 ) ;
if ( V_51 )
goto V_56;
V_50 -> type = V_57 ;
V_50 -> V_58 |= V_59 ;
V_50 -> V_60 = F_1 ( V_7 ) ;
* V_47 = V_50 ;
return 0 ;
V_56:
F_29 ( V_50 ) ;
* V_47 = NULL ;
return V_51 ;
}
static int F_30 ( struct V_5 * V_6 ,
struct V_46 * V_31 )
{
struct V_1 * V_7 ;
V_7 = F_10 ( V_31 ) ;
if ( F_31 ( V_6 , V_53 , V_7 -> V_3 ,
V_7 -> V_35 ) )
goto V_61;
return 0 ;
V_61:
return - V_62 ;
}
static int F_32 ( struct V_46 * V_31 )
{
struct V_1 * V_7 ;
V_7 = F_10 ( V_31 ) ;
return F_33 ( V_7 -> V_3 * 4 ) ;
}
static int F_34 ( struct V_46 * V_63 , struct V_46 * V_64 )
{
struct V_1 * V_65 = F_10 ( V_63 ) ;
struct V_1 * V_66 = F_10 ( V_64 ) ;
int V_67 ;
if ( V_65 -> V_3 != V_66 -> V_3 )
return 1 ;
for ( V_67 = 0 ; V_67 < V_55 ; V_67 ++ )
if ( V_65 -> V_35 [ V_67 ] != V_66 -> V_35 [ V_67 ] )
return 1 ;
return 0 ;
}
static int T_1 F_35 ( void )
{
return F_36 ( & V_68 , V_57 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_68 , V_57 ) ;
}
