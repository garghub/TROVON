static unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 * sizeof( struct V_4 ) ;
}
int F_2 ( struct V_5 * V_5 , struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_10 ;
struct V_4 * V_11 ;
struct V_12 * V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
struct V_17 * V_18 = F_3 ( V_9 ) ;
struct V_19 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
int V_23 = 0 ;
bool V_24 ;
int V_25 ;
unsigned int V_26 ;
if ( V_18 -> V_27 -> V_28 == V_29 ) {
V_26 = F_4 ( V_9 ) -> V_26 ;
V_20 = (struct V_19 * ) V_18 ;
} else if ( V_18 -> V_27 -> V_28 == V_30 ) {
V_26 = F_5 ( V_9 ) -> V_31 ;
V_22 = (struct V_21 * ) V_18 ;
} else {
goto V_32;
}
F_6 ( V_9 ) ;
V_13 = V_18 -> V_33 ;
if ( ! F_7 ( V_13 ) ||
! V_18 -> V_34 || F_8 ( V_9 ) )
goto V_32;
F_9 ( V_9 ) ;
V_10 = F_10 ( V_18 -> V_34 ) ;
V_15 = F_1 ( V_10 ) ;
V_16 = F_11 ( V_13 ) ;
if ( F_12 ( V_9 , V_16 - V_15 ) )
goto V_32;
V_14 = F_13 ( V_13 ) ;
if ( ! V_13 -> V_35 )
V_14 = 0 ;
if ( F_14 ( V_9 , V_14 + V_15 ) )
goto V_32;
F_15 ( V_9 , V_15 ) ;
F_16 ( V_9 ) ;
V_9 -> V_33 = V_13 ;
V_9 -> V_36 = F_17 ( V_37 ) ;
V_11 = F_18 ( V_9 ) ;
V_24 = true ;
for ( V_25 = V_10 -> V_3 - 1 ; V_25 >= 0 ; V_25 -- ) {
V_11 [ V_25 ] = F_19 ( V_10 -> V_38 [ V_25 ] ,
V_26 , 0 , V_24 ) ;
V_24 = false ;
}
if ( V_20 )
V_23 = F_20 ( V_39 , V_13 , & V_20 -> V_40 ,
V_9 ) ;
else if ( V_22 )
V_23 = F_20 ( V_41 , V_13 , & V_22 -> V_42 ,
V_9 ) ;
if ( V_23 )
F_21 ( L_1 ,
V_43 , V_23 ) ;
return 0 ;
V_32:
F_22 ( V_9 ) ;
return - V_44 ;
}
static int F_23 ( struct V_12 * V_33 , struct V_45 * V_46 ,
unsigned int V_28 , const void * V_47 ,
struct V_48 * * V_49 )
{
struct V_1 * V_10 ;
struct V_45 * V_50 [ V_51 + 1 ] ;
struct V_48 * V_52 ;
int V_53 ;
int V_54 ;
V_54 = F_24 ( V_50 , V_51 , V_46 ,
V_55 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! V_50 [ V_56 ] )
return - V_44 ;
V_53 = sizeof( * V_10 ) ;
V_52 = F_25 ( V_53 ) ;
if ( ! V_52 )
return - V_57 ;
V_52 -> V_58 = V_53 ;
V_10 = F_10 ( V_52 ) ;
V_54 = F_26 ( V_50 [ V_56 ] , V_59 ,
& V_10 -> V_3 , V_10 -> V_38 ) ;
if ( V_54 )
goto V_60;
V_52 -> type = V_61 ;
V_52 -> V_62 |= V_63 ;
* V_49 = V_52 ;
return 0 ;
V_60:
F_27 ( V_52 ) ;
* V_49 = NULL ;
return V_54 ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_48 * V_34 )
{
struct V_1 * V_10 ;
V_10 = F_10 ( V_34 ) ;
if ( F_29 ( V_9 , V_56 , V_10 -> V_3 ,
V_10 -> V_38 ) )
goto V_64;
return 0 ;
V_64:
return - V_65 ;
}
static int F_30 ( struct V_48 * V_34 )
{
struct V_1 * V_10 ;
V_10 = F_10 ( V_34 ) ;
return F_31 ( V_10 -> V_3 * 4 ) ;
}
static int F_32 ( struct V_48 * V_66 , struct V_48 * V_67 )
{
struct V_1 * V_68 = F_10 ( V_66 ) ;
struct V_1 * V_69 = F_10 ( V_67 ) ;
int V_70 ;
if ( V_68 -> V_3 != V_69 -> V_3 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_59 ; V_70 ++ )
if ( V_68 -> V_38 [ V_70 ] != V_69 -> V_38 [ V_70 ] )
return 1 ;
return 0 ;
}
static int T_1 F_33 ( void )
{
return F_34 ( & V_71 , V_61 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_71 , V_61 ) ;
}
