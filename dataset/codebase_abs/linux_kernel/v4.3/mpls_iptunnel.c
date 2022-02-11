static unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 * sizeof( struct V_4 ) ;
}
int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_1 * V_9 ;
struct V_4 * V_10 ;
struct V_11 * V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
struct V_16 * V_17 = F_3 ( V_8 ) ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
int V_22 = 0 ;
bool V_23 ;
int V_24 ;
unsigned int V_25 ;
if ( V_8 -> V_26 == F_4 ( V_27 ) ) {
V_25 = F_5 ( V_8 ) -> V_25 ;
V_19 = (struct V_18 * ) V_17 ;
} else if ( V_8 -> V_26 == F_4 ( V_28 ) ) {
V_25 = F_6 ( V_8 ) -> V_29 ;
V_21 = (struct V_20 * ) V_17 ;
} else {
goto V_30;
}
F_7 ( V_8 ) ;
V_12 = V_17 -> V_31 ;
if ( ! F_8 ( V_12 ) ||
! V_17 -> V_32 || F_9 ( V_8 ) )
goto V_30;
F_10 ( V_8 ) ;
V_9 = F_11 ( V_17 -> V_32 ) ;
V_14 = F_1 ( V_9 ) ;
V_15 = F_12 ( V_12 ) ;
if ( F_13 ( V_8 , V_15 - V_14 ) )
goto V_30;
V_13 = F_14 ( V_12 ) ;
if ( ! V_12 -> V_33 )
V_13 = 0 ;
if ( F_15 ( V_8 , V_13 + V_14 ) )
goto V_30;
F_16 ( V_8 , V_14 ) ;
F_17 ( V_8 ) ;
V_8 -> V_31 = V_12 ;
V_8 -> V_26 = F_4 ( V_34 ) ;
V_10 = F_18 ( V_8 ) ;
V_23 = true ;
for ( V_24 = V_9 -> V_3 - 1 ; V_24 >= 0 ; V_24 -- ) {
V_10 [ V_24 ] = F_19 ( V_9 -> V_35 [ V_24 ] ,
V_25 , 0 , V_23 ) ;
V_23 = false ;
}
if ( V_19 )
V_22 = F_20 ( V_36 , V_12 , & V_19 -> V_37 ,
V_8 ) ;
else if ( V_21 )
V_22 = F_20 ( V_38 , V_12 , & V_21 -> V_39 ,
V_8 ) ;
if ( V_22 )
F_21 ( L_1 ,
V_40 , V_22 ) ;
return 0 ;
V_30:
F_22 ( V_8 ) ;
return - V_41 ;
}
static int F_23 ( struct V_11 * V_31 , struct V_42 * V_43 ,
unsigned int V_44 , const void * V_45 ,
struct V_46 * * V_47 )
{
struct V_1 * V_9 ;
struct V_42 * V_48 [ V_49 + 1 ] ;
struct V_46 * V_50 ;
int V_51 ;
int V_52 ;
V_52 = F_24 ( V_48 , V_49 , V_43 ,
V_53 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( ! V_48 [ V_54 ] )
return - V_41 ;
V_51 = sizeof( * V_9 ) ;
V_50 = F_25 ( V_51 ) ;
if ( ! V_50 )
return - V_55 ;
V_50 -> V_56 = V_51 ;
V_9 = F_11 ( V_50 ) ;
V_52 = F_26 ( V_48 [ V_54 ] , V_57 ,
& V_9 -> V_3 , V_9 -> V_35 ) ;
if ( V_52 )
goto V_58;
V_50 -> type = V_59 ;
V_50 -> V_60 |= V_61 ;
* V_47 = V_50 ;
return 0 ;
V_58:
F_27 ( V_50 ) ;
* V_47 = NULL ;
return V_52 ;
}
static int F_28 ( struct V_7 * V_8 ,
struct V_46 * V_32 )
{
struct V_1 * V_9 ;
V_9 = F_11 ( V_32 ) ;
if ( F_29 ( V_8 , V_54 , V_9 -> V_3 ,
V_9 -> V_35 ) )
goto V_62;
return 0 ;
V_62:
return - V_63 ;
}
static int F_30 ( struct V_46 * V_32 )
{
struct V_1 * V_9 ;
V_9 = F_11 ( V_32 ) ;
return F_31 ( V_9 -> V_3 * 4 ) ;
}
static int F_32 ( struct V_46 * V_64 , struct V_46 * V_65 )
{
struct V_1 * V_66 = F_11 ( V_64 ) ;
struct V_1 * V_67 = F_11 ( V_65 ) ;
int V_68 ;
if ( V_66 -> V_3 != V_67 -> V_3 )
return 1 ;
for ( V_68 = 0 ; V_68 < V_57 ; V_68 ++ )
if ( V_66 -> V_35 [ V_68 ] != V_67 -> V_35 [ V_68 ] )
return 1 ;
return 0 ;
}
static int T_1 F_33 ( void )
{
return F_34 ( & V_69 , V_59 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_69 , V_59 ) ;
}
