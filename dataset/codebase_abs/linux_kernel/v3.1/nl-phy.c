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
F_6 ( V_2 , V_19 , F_7 ( V_7 ) ) ;
F_8 ( V_2 , V_20 , V_7 -> V_21 ) ;
F_8 ( V_2 , V_22 , V_7 -> V_23 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
if ( V_7 -> V_24 [ V_9 ] )
V_11 [ V_10 ++ ] = V_7 -> V_24 [ V_9 ] | ( V_9 << 27 ) ;
}
if ( V_10 )
F_9 ( V_2 , V_25 ,
V_10 * sizeof( T_2 ) , V_11 ) ;
F_10 ( & V_7 -> V_18 ) ;
F_11 ( V_11 ) ;
return F_12 ( V_2 , V_8 ) ;
V_26:
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
F_3 ( L_1 , V_13 ) ;
if ( ! V_29 -> V_33 [ V_19 ] )
return - V_34 ;
V_30 = F_15 ( V_29 -> V_33 [ V_19 ] ) ;
if ( V_30 [ F_16 ( V_29 -> V_33 [ V_19 ] ) - 1 ] != '\0' )
return - V_34 ;
if ( V_29 -> V_33 [ V_55 ] ) {
V_52 = F_15 ( V_29 -> V_33 [ V_55 ] ) ;
if ( V_52 [ F_16 ( V_29 -> V_33 [ V_55 ] ) - 1 ]
!= '\0' )
return - V_34 ;
} else {
V_52 = L_2 ;
}
if ( strlen ( V_52 ) >= V_56 )
return - V_57 ;
V_7 = F_17 ( V_30 ) ;
if ( ! V_7 )
return - V_35 ;
V_2 = F_27 ( V_29 , 0 , V_58 ) ;
if ( ! V_2 )
goto V_37;
if ( ! V_7 -> V_59 ) {
V_31 = - V_34 ;
goto V_26;
}
if ( V_29 -> V_33 [ V_60 ] &&
F_16 ( V_29 -> V_33 [ V_60 ] ) !=
V_61 ) {
V_31 = - V_34 ;
goto V_26;
}
V_54 = V_7 -> V_59 ( V_7 , V_52 ) ;
if ( F_28 ( V_54 ) ) {
V_31 = F_29 ( V_54 ) ;
goto V_26;
}
if ( V_29 -> V_33 [ V_60 ] ) {
struct V_62 V_63 ;
V_63 . V_64 = V_65 ;
F_30 ( & V_63 . V_66 , V_29 -> V_33 [ V_60 ] ,
V_61 ) ;
F_31 () ;
V_31 = F_32 ( V_54 , & V_63 ) ;
F_33 () ;
if ( V_31 )
goto V_67;
}
F_6 ( V_2 , V_19 , F_7 ( V_7 ) ) ;
F_6 ( V_2 , V_55 , V_54 -> V_30 ) ;
F_34 ( V_54 ) ;
F_19 ( V_7 ) ;
return F_35 ( V_2 , V_29 ) ;
V_67:
F_31 () ;
V_7 -> V_68 ( V_7 , V_54 ) ;
F_34 ( V_54 ) ;
F_33 () ;
V_26:
F_21 ( V_2 ) ;
V_37:
F_19 ( V_7 ) ;
return V_31 ;
}
static int F_36 ( struct V_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
const char * V_30 ;
int V_31 ;
struct V_53 * V_54 ;
F_3 ( L_1 , V_13 ) ;
if ( ! V_29 -> V_33 [ V_55 ] )
return - V_34 ;
V_30 = F_15 ( V_29 -> V_33 [ V_55 ] ) ;
if ( V_30 [ F_16 ( V_29 -> V_33 [ V_55 ] ) - 1 ] != '\0' )
return - V_34 ;
V_54 = F_37 ( F_38 ( V_29 ) , V_30 ) ;
if ( ! V_54 )
return - V_35 ;
V_7 = F_39 ( V_54 ) -> F_40 ( V_54 ) ;
F_41 ( ! V_7 ) ;
V_31 = - V_34 ;
if ( V_29 -> V_33 [ V_19 ] ) {
struct V_6 * V_69 ;
const char * V_70 =
F_15 ( V_29 -> V_33 [ V_19 ] ) ;
if ( V_70 [ F_16 ( V_29 -> V_33 [ V_19 ] ) - 1 ]
!= '\0' )
goto V_37;
V_69 = F_17 ( V_70 ) ;
if ( ! V_69 )
goto V_37;
if ( V_7 != V_69 ) {
F_19 ( V_69 ) ;
goto V_37;
}
}
V_31 = - V_32 ;
V_2 = F_27 ( V_29 , 0 , V_71 ) ;
if ( ! V_2 )
goto V_37;
if ( ! V_7 -> V_68 ) {
V_31 = - V_34 ;
goto V_26;
}
F_31 () ;
V_7 -> V_68 ( V_7 , V_54 ) ;
F_34 ( V_54 ) ;
V_54 = NULL ;
F_33 () ;
F_6 ( V_2 , V_19 , F_7 ( V_7 ) ) ;
F_6 ( V_2 , V_55 , V_30 ) ;
F_19 ( V_7 ) ;
return F_35 ( V_2 , V_29 ) ;
V_26:
F_21 ( V_2 ) ;
V_37:
F_19 ( V_7 ) ;
if ( V_54 )
F_34 ( V_54 ) ;
return V_31 ;
}
int F_42 ( void )
{
int V_9 ;
int V_31 ;
for ( V_9 = 0 ; V_9 < F_43 ( V_72 ) ; V_9 ++ ) {
V_31 = F_44 ( & V_15 ,
& V_72 [ V_9 ] ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
