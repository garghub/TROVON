static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , int V_5 , struct V_6 * V_7 )
{
void * V_8 ;
int V_9 , V_10 = 0 ;
T_2 * V_11 = F_2 ( 32 * sizeof( T_2 ) , V_12 ) ;
F_3 ( L_1 , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
V_8 = F_4 ( V_2 , 0 , V_4 , & V_15 , V_5 ,
V_16 ) ;
if ( ! V_8 )
goto V_17;
F_5 ( & V_7 -> V_18 ) ;
if ( F_6 ( V_2 , V_19 , F_7 ( V_7 ) ) ||
F_8 ( V_2 , V_20 , V_7 -> V_21 ) ||
F_8 ( V_2 , V_22 , V_7 -> V_23 ) )
goto V_24;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_7 -> V_25 [ V_9 ] )
V_11 [ V_10 ++ ] = V_7 -> V_25 [ V_9 ] | ( V_9 << 27 ) ;
}
if ( V_10 &&
F_9 ( V_2 , V_26 ,
V_10 * sizeof( T_2 ) , V_11 ) )
goto V_24;
F_10 ( & V_7 -> V_18 ) ;
F_11 ( V_11 ) ;
return F_12 ( V_2 , V_8 ) ;
V_24:
F_10 ( & V_7 -> V_18 ) ;
F_13 ( V_2 , V_8 ) ;
V_17:
F_11 ( V_11 ) ;
return - V_14 ;
}
static int F_14 ( struct V_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
const char * V_30 ;
int V_31 = - V_32 ;
F_3 ( L_1 , V_13 ) ;
if ( ! V_29 -> V_33 [ V_19 ] )
return - V_34 ;
V_30 = F_15 ( V_29 -> V_33 [ V_19 ] ) ;
if ( V_30 [ F_16 ( V_29 -> V_33 [ V_19 ] ) - 1 ] != '\0' )
return - V_34 ;
V_7 = F_17 ( V_30 ) ;
if ( ! V_7 )
return - V_35 ;
V_2 = F_18 ( V_36 , V_12 ) ;
if ( ! V_2 )
goto V_37;
V_31 = F_1 ( V_2 , V_29 -> V_38 , V_29 -> V_39 ,
0 , V_7 ) ;
if ( V_31 < 0 )
goto V_40;
F_19 ( V_7 ) ;
return F_20 ( V_2 , V_29 ) ;
V_40:
F_21 ( V_2 ) ;
V_37:
F_19 ( V_7 ) ;
return V_31 ;
}
static int F_22 ( struct V_6 * V_7 , void * V_41 )
{
int V_31 ;
struct V_42 * V_43 = V_41 ;
F_3 ( L_1 , V_13 ) ;
if ( V_43 -> V_44 ++ < V_43 -> V_45 )
return 0 ;
V_31 = F_1 ( V_43 -> V_27 ,
F_23 ( V_43 -> V_46 -> V_27 ) . V_3 ,
V_43 -> V_46 -> V_47 -> V_48 ,
V_49 ,
V_7 ) ;
if ( V_31 < 0 ) {
V_43 -> V_44 -- ;
return V_31 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_27 ,
struct V_50 * V_46 )
{
struct V_42 V_43 = {
. V_46 = V_46 ,
. V_27 = V_27 ,
. V_45 = V_46 -> args [ 0 ] ,
. V_44 = 0 ,
} ;
F_3 ( L_1 , V_13 ) ;
F_25 ( F_22 , & V_43 ) ;
V_46 -> args [ 0 ] = V_43 . V_44 ;
return V_27 -> V_51 ;
}
static int F_26 ( struct V_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
const char * V_30 ;
const char * V_52 ;
int V_31 = - V_32 ;
struct V_53 * V_54 ;
int type = V_55 ;
F_3 ( L_1 , V_13 ) ;
if ( ! V_29 -> V_33 [ V_19 ] )
return - V_34 ;
V_30 = F_15 ( V_29 -> V_33 [ V_19 ] ) ;
if ( V_30 [ F_16 ( V_29 -> V_33 [ V_19 ] ) - 1 ] != '\0' )
return - V_34 ;
if ( V_29 -> V_33 [ V_56 ] ) {
V_52 = F_15 ( V_29 -> V_33 [ V_56 ] ) ;
if ( V_52 [ F_16 ( V_29 -> V_33 [ V_56 ] ) - 1 ]
!= '\0' )
return - V_34 ;
} else {
V_52 = L_2 ;
}
if ( strlen ( V_52 ) >= V_57 )
return - V_58 ;
V_7 = F_17 ( V_30 ) ;
if ( ! V_7 )
return - V_35 ;
V_2 = F_27 ( V_29 , 0 , V_59 ) ;
if ( ! V_2 )
goto V_37;
if ( ! V_7 -> V_60 ) {
V_31 = - V_34 ;
goto V_24;
}
if ( V_29 -> V_33 [ V_61 ] &&
F_16 ( V_29 -> V_33 [ V_61 ] ) !=
V_62 ) {
V_31 = - V_34 ;
goto V_24;
}
if ( V_29 -> V_33 [ V_63 ] ) {
type = F_28 ( V_29 -> V_33 [ V_63 ] ) ;
if ( type >= V_64 )
return - V_34 ;
}
V_54 = V_7 -> V_60 ( V_7 , V_52 , type ) ;
if ( F_29 ( V_54 ) ) {
V_31 = F_30 ( V_54 ) ;
goto V_24;
}
if ( V_29 -> V_33 [ V_61 ] ) {
struct V_65 V_66 ;
V_66 . V_67 = V_68 ;
F_31 ( & V_66 . V_69 , V_29 -> V_33 [ V_61 ] ,
V_62 ) ;
F_32 () ;
V_31 = F_33 ( V_54 , & V_66 ) ;
F_34 () ;
if ( V_31 )
goto V_70;
}
if ( F_6 ( V_2 , V_19 , F_7 ( V_7 ) ) ||
F_6 ( V_2 , V_56 , V_54 -> V_30 ) )
goto V_24;
F_35 ( V_54 ) ;
F_19 ( V_7 ) ;
return F_36 ( V_2 , V_29 ) ;
V_70:
F_32 () ;
V_7 -> V_71 ( V_7 , V_54 ) ;
F_35 ( V_54 ) ;
F_34 () ;
V_24:
F_21 ( V_2 ) ;
V_37:
F_19 ( V_7 ) ;
return V_31 ;
}
static int F_37 ( struct V_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
const char * V_30 ;
int V_31 ;
struct V_53 * V_54 ;
F_3 ( L_1 , V_13 ) ;
if ( ! V_29 -> V_33 [ V_56 ] )
return - V_34 ;
V_30 = F_15 ( V_29 -> V_33 [ V_56 ] ) ;
if ( V_30 [ F_16 ( V_29 -> V_33 [ V_56 ] ) - 1 ] != '\0' )
return - V_34 ;
V_54 = F_38 ( F_39 ( V_29 ) , V_30 ) ;
if ( ! V_54 )
return - V_35 ;
V_7 = F_40 ( V_54 ) -> F_41 ( V_54 ) ;
F_42 ( ! V_7 ) ;
V_31 = - V_34 ;
if ( V_29 -> V_33 [ V_19 ] ) {
struct V_6 * V_72 ;
const char * V_73 =
F_15 ( V_29 -> V_33 [ V_19 ] ) ;
if ( V_73 [ F_16 ( V_29 -> V_33 [ V_19 ] ) - 1 ]
!= '\0' )
goto V_37;
V_72 = F_17 ( V_73 ) ;
if ( ! V_72 )
goto V_37;
if ( V_7 != V_72 ) {
F_19 ( V_72 ) ;
goto V_37;
}
}
V_31 = - V_32 ;
V_2 = F_27 ( V_29 , 0 , V_74 ) ;
if ( ! V_2 )
goto V_37;
if ( ! V_7 -> V_71 ) {
V_31 = - V_34 ;
goto V_24;
}
F_32 () ;
V_7 -> V_71 ( V_7 , V_54 ) ;
F_35 ( V_54 ) ;
V_54 = NULL ;
F_34 () ;
if ( F_6 ( V_2 , V_19 , F_7 ( V_7 ) ) ||
F_6 ( V_2 , V_56 , V_30 ) )
goto V_24;
F_19 ( V_7 ) ;
return F_36 ( V_2 , V_29 ) ;
V_24:
F_21 ( V_2 ) ;
V_37:
F_19 ( V_7 ) ;
if ( V_54 )
F_35 ( V_54 ) ;
return V_31 ;
}
int F_43 ( void )
{
int V_9 ;
int V_31 ;
for ( V_9 = 0 ; V_9 < F_44 ( V_75 ) ; V_9 ++ ) {
V_31 = F_45 ( & V_15 ,
& V_75 [ V_9 ] ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
