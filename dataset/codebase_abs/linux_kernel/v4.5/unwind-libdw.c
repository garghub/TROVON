static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 * V_6 ;
struct V_7 * V_7 = NULL ;
F_2 ( V_5 -> V_8 ,
V_9 ,
V_10 , V_3 , V_2 ) ;
if ( V_2 -> V_11 )
V_7 = V_2 -> V_11 -> V_7 ;
if ( ! V_7 )
return 0 ;
V_6 = F_3 ( V_5 -> V_12 , V_3 ) ;
if ( ! V_6 )
V_6 = F_4 ( V_5 -> V_12 , V_7 -> V_13 ,
V_7 -> V_14 , - 1 , V_2 -> V_11 -> V_15 ,
false ) ;
return V_6 && F_3 ( V_5 -> V_12 , V_3 ) == V_6 ? 0 : - 1 ;
}
static int F_5 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_1 V_2 ;
return F_1 ( & V_2 , V_3 , V_5 ) ;
}
static int F_6 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_16 * V_17 = & V_5 -> V_18 [ V_5 -> V_19 ++ ] ;
struct V_1 V_2 ;
if ( F_1 ( & V_2 , V_3 , V_5 ) )
return - 1 ;
V_17 -> V_3 = V_3 ;
V_17 -> V_11 = V_2 . V_11 ;
V_17 -> V_20 = V_2 . V_20 ;
F_7 ( L_1 V_21 L_2 V_21 L_3 ,
V_2 . V_20 ? V_2 . V_20 -> V_22 : L_4 ,
V_3 ,
V_2 . V_11 ? V_2 . V_11 -> V_23 ( V_2 . V_11 , V_3 ) : ( T_1 ) 0 ) ;
return 0 ;
}
static T_3 F_8 ( T_4 * V_12 , void * V_24 , void * * V_25 )
{
if ( * V_25 != NULL )
return 0 ;
* V_25 = V_24 ;
return F_9 ( V_12 ) ;
}
static int F_10 ( struct V_4 * V_5 , T_5 V_26 ,
T_6 * V_27 )
{
struct V_1 V_2 ;
T_7 V_28 ;
F_11 ( V_5 -> V_8 , V_9 ,
V_10 , V_26 , & V_2 ) ;
if ( ! V_2 . V_11 ) {
F_11 ( V_5 -> V_8 , V_9 ,
V_29 , V_26 , & V_2 ) ;
}
if ( ! V_2 . V_11 ) {
F_7 ( L_5 , ( unsigned long ) V_26 ) ;
return - 1 ;
}
if ( ! V_2 . V_11 -> V_7 )
return - 1 ;
V_28 = F_12 ( V_2 . V_11 -> V_7 , V_2 . V_11 , V_5 -> V_30 ,
V_26 , ( V_31 * ) V_27 , sizeof( * V_27 ) ) ;
return ! ( V_28 == sizeof( * V_27 ) ) ;
}
static bool F_13 ( T_4 * V_12 V_32 , T_5 V_26 , T_6 * V_33 ,
void * V_24 )
{
struct V_4 * V_5 = V_24 ;
struct V_34 * V_35 = & V_5 -> V_36 -> V_37 ;
T_1 V_15 , V_38 ;
int V_39 ;
int V_40 ;
V_40 = F_14 ( & V_15 , & V_5 -> V_36 -> V_41 , V_42 ) ;
if ( V_40 )
return false ;
V_38 = V_15 + V_35 -> V_28 ;
if ( V_26 + sizeof( T_6 ) < V_26 )
return false ;
if ( V_26 < V_15 || V_26 + sizeof( T_6 ) > V_38 ) {
V_40 = F_10 ( V_5 , V_26 , V_33 ) ;
if ( V_40 ) {
F_7 ( L_6 V_21 L_7
L_8 V_21 L_9 V_21 L_10 ,
V_26 , V_15 , V_38 ) ;
return false ;
}
return true ;
}
V_39 = V_26 - V_15 ;
* V_33 = * ( T_6 * ) & V_35 -> V_27 [ V_39 ] ;
F_7 ( L_11 V_21 L_12 ,
V_26 , ( unsigned long ) * V_33 , V_39 ) ;
return true ;
}
static int
F_15 ( T_8 * V_43 , void * V_24 )
{
struct V_4 * V_5 = V_24 ;
T_5 V_44 ;
if ( ! F_16 ( V_43 , & V_44 , NULL ) ) {
F_17 ( L_13 , F_18 ( - 1 ) ) ;
return V_45 ;
}
return F_6 ( V_44 , V_5 ) || ! ( -- V_5 -> V_46 ) ?
V_45 : V_47 ;
}
int F_19 ( T_9 V_48 , void * V_24 ,
struct V_8 * V_8 ,
struct V_49 * V_27 ,
int V_46 )
{
struct V_4 * V_5 , V_50 = {
. V_36 = V_27 ,
. V_8 = V_8 ,
. V_30 = V_8 -> V_51 -> V_30 ,
. V_48 = V_48 ,
. V_24 = V_24 ,
. V_46 = V_46 ,
} ;
T_6 V_3 ;
int V_52 = - V_53 , V_54 ;
if ( ! V_27 -> V_41 . V_55 )
return - V_53 ;
V_5 = F_20 ( sizeof( V_50 ) + sizeof( V_50 . V_18 [ 0 ] ) * V_46 ) ;
if ( ! V_5 )
return - V_56 ;
* V_5 = V_50 ;
V_5 -> V_12 = F_21 ( & V_57 ) ;
if ( ! V_5 -> V_12 )
goto V_58;
V_52 = F_14 ( & V_3 , & V_27 -> V_41 , V_59 ) ;
if ( V_52 )
goto V_58;
V_52 = F_5 ( V_3 , V_5 ) ;
if ( V_52 )
goto V_58;
if ( ! F_22 ( V_5 -> V_12 , V_60 , V_8 -> V_61 , & V_62 , V_5 ) )
goto V_58;
V_52 = F_23 ( V_5 -> V_12 , V_8 -> V_61 , F_15 , V_5 ) ;
if ( V_52 && ! V_5 -> V_46 )
V_52 = 0 ;
for ( V_54 = 0 ; V_54 < V_5 -> V_19 && ! V_52 ; V_54 ++ ) {
int V_63 = V_54 ;
if ( V_64 . V_65 == V_66 )
V_63 = V_5 -> V_19 - V_54 - 1 ;
V_52 = V_5 -> V_18 [ V_63 ] . V_3 ? V_5 -> V_48 ( & V_5 -> V_18 [ V_63 ] , V_5 -> V_24 ) : 0 ;
}
V_58:
if ( V_52 )
F_7 ( L_14 , F_18 ( - 1 ) ) ;
F_24 ( V_5 -> V_12 ) ;
free ( V_5 ) ;
return 0 ;
}
