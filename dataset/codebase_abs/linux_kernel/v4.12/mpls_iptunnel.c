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
struct V_22 * V_22 ;
int V_23 = 0 ;
bool V_24 ;
int V_25 ;
unsigned int V_26 ;
V_10 = V_15 -> V_27 ;
V_22 = F_4 ( V_10 ) ;
F_5 ( V_6 ) ;
if ( ! F_6 ( V_10 ) ||
! V_15 -> V_28 || F_7 ( V_6 ) )
goto V_29;
F_8 ( V_6 ) ;
V_7 = F_9 ( V_15 -> V_28 ) ;
if ( V_15 -> V_30 -> V_31 == V_32 ) {
if ( V_7 -> V_33 == V_34 )
V_26 = V_7 -> V_35 ;
else if ( V_7 -> V_33 == V_36 &&
! V_22 -> V_37 . V_38 )
V_26 = V_22 -> V_37 . V_35 ;
else
V_26 = F_10 ( V_6 ) -> V_26 ;
V_17 = (struct V_16 * ) V_15 ;
} else if ( V_15 -> V_30 -> V_31 == V_39 ) {
if ( V_7 -> V_33 == V_34 )
V_26 = V_7 -> V_35 ;
else if ( V_7 -> V_33 == V_36 &&
! V_22 -> V_37 . V_38 )
V_26 = V_22 -> V_37 . V_35 ;
else
V_26 = F_11 ( V_6 ) -> V_40 ;
V_19 = (struct V_18 * ) V_15 ;
} else {
goto V_29;
}
V_12 = F_1 ( V_7 ) ;
V_13 = F_12 ( V_10 ) ;
if ( F_13 ( V_6 , V_13 - V_12 ) )
goto V_29;
V_11 = F_14 ( V_10 ) ;
if ( ! V_10 -> V_41 )
V_11 = 0 ;
if ( F_15 ( V_6 , V_11 + V_12 ) )
goto V_29;
F_16 ( V_6 , V_6 -> V_42 ) ;
F_17 ( V_6 ) ;
F_18 ( V_6 , V_12 ) ;
F_19 ( V_6 ) ;
V_6 -> V_27 = V_10 ;
V_6 -> V_42 = F_20 ( V_43 ) ;
V_8 = F_21 ( V_6 ) ;
V_24 = true ;
for ( V_25 = V_7 -> V_3 - 1 ; V_25 >= 0 ; V_25 -- ) {
V_8 [ V_25 ] = F_22 ( V_7 -> V_44 [ V_25 ] ,
V_26 , 0 , V_24 ) ;
V_24 = false ;
}
F_23 ( V_10 , V_6 ) ;
if ( V_17 )
V_23 = F_24 ( V_45 , V_10 , & V_17 -> V_46 ,
V_6 ) ;
else if ( V_19 )
V_23 = F_24 ( V_47 , V_10 , & V_19 -> V_48 ,
V_6 ) ;
if ( V_23 )
F_25 ( L_1 ,
V_49 , V_23 ) ;
return V_50 ;
V_29:
V_21 = V_10 ? F_26 ( V_10 ) : NULL ;
if ( V_21 )
F_27 ( V_21 , V_51 ) ;
F_28 ( V_6 ) ;
return - V_52 ;
}
static int F_29 ( struct V_53 * V_54 ,
unsigned int V_31 , const void * V_55 ,
struct V_56 * * V_57 )
{
struct V_1 * V_7 ;
struct V_53 * V_58 [ V_59 + 1 ] ;
struct V_56 * V_60 ;
T_1 V_61 ;
int V_62 ;
V_62 = F_30 ( V_58 , V_59 , V_54 ,
V_63 , NULL ) ;
if ( V_62 < 0 )
return V_62 ;
if ( ! V_58 [ V_64 ] )
return - V_52 ;
if ( F_31 ( V_58 [ V_64 ] ,
V_65 , & V_61 , NULL ) )
return - V_52 ;
V_60 = F_32 ( sizeof( * V_7 ) +
V_61 * sizeof( V_66 ) ) ;
if ( ! V_60 )
return - V_67 ;
V_7 = F_9 ( V_60 ) ;
V_62 = F_31 ( V_58 [ V_64 ] , V_61 ,
& V_7 -> V_3 , V_7 -> V_44 ) ;
if ( V_62 )
goto V_68;
V_7 -> V_33 = V_36 ;
if ( V_58 [ V_69 ] ) {
V_7 -> V_35 = F_33 ( V_58 [ V_69 ] ) ;
V_7 -> V_33 = V_7 -> V_35 ?
V_34 :
V_70 ;
}
V_60 -> type = V_71 ;
V_60 -> V_72 |= V_73 ;
V_60 -> V_74 = F_1 ( V_7 ) ;
* V_57 = V_60 ;
return 0 ;
V_68:
F_34 ( V_60 ) ;
* V_57 = NULL ;
return V_62 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_56 * V_28 )
{
struct V_1 * V_7 ;
V_7 = F_9 ( V_28 ) ;
if ( F_36 ( V_6 , V_64 , V_7 -> V_3 ,
V_7 -> V_44 ) )
goto V_75;
if ( V_7 -> V_33 != V_36 &&
F_37 ( V_6 , V_69 , V_7 -> V_35 ) )
goto V_75;
return 0 ;
V_75:
return - V_76 ;
}
static int F_38 ( struct V_56 * V_28 )
{
struct V_1 * V_7 ;
int V_77 ;
V_7 = F_9 ( V_28 ) ;
V_77 = F_39 ( V_7 -> V_3 * 4 ) ;
if ( V_7 -> V_33 != V_36 )
V_77 += F_39 ( 1 ) ;
return V_77 ;
}
static int F_40 ( struct V_56 * V_78 , struct V_56 * V_79 )
{
struct V_1 * V_80 = F_9 ( V_78 ) ;
struct V_1 * V_81 = F_9 ( V_79 ) ;
int V_82 ;
if ( V_80 -> V_3 != V_81 -> V_3 ||
V_80 -> V_33 != V_81 -> V_33 ||
V_80 -> V_35 != V_81 -> V_35 )
return 1 ;
for ( V_82 = 0 ; V_82 < V_80 -> V_3 ; V_82 ++ )
if ( V_80 -> V_44 [ V_82 ] != V_81 -> V_44 [ V_82 ] )
return 1 ;
return 0 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_83 , V_71 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_83 , V_71 ) ;
}
