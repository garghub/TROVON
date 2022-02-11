static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_2 * V_6 ;
struct V_7 * V_7 = NULL ;
F_2 ( V_5 -> V_8 , V_5 -> V_9 ,
V_10 ,
V_11 , V_3 , V_2 ) ;
if ( V_2 -> V_12 )
V_7 = V_2 -> V_12 -> V_7 ;
if ( ! V_7 )
return 0 ;
V_6 = F_3 ( V_5 -> V_13 , V_3 ) ;
if ( ! V_6 )
V_6 = F_4 ( V_5 -> V_13 , V_7 -> V_14 ,
V_7 -> V_15 , - 1 , V_2 -> V_12 -> V_16 ,
false ) ;
return V_6 && F_3 ( V_5 -> V_13 , V_3 ) == V_6 ? 0 : - 1 ;
}
static int F_5 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_1 V_2 ;
return F_1 ( & V_2 , V_3 , V_5 ) ;
}
static int F_6 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_17 V_18 ;
struct V_1 V_2 ;
if ( F_1 ( & V_2 , V_3 , V_5 ) )
return - 1 ;
V_18 . V_3 = V_3 ;
V_18 . V_12 = V_2 . V_12 ;
V_18 . V_19 = V_2 . V_19 ;
F_7 ( L_1 V_20 L_2 V_20 L_3 ,
V_2 . V_19 ? V_2 . V_19 -> V_21 : L_4 ,
V_3 ,
V_2 . V_12 ? V_2 . V_12 -> V_22 ( V_2 . V_12 , V_3 ) : ( T_1 ) 0 ) ;
return V_5 -> V_23 ( & V_18 , V_5 -> V_24 ) ;
}
static T_3 F_8 ( T_4 * V_13 , void * V_24 , void * * V_25 )
{
if ( * V_25 != NULL )
return 0 ;
* V_25 = V_24 ;
return F_9 ( V_13 ) ;
}
static int F_10 ( struct V_4 * V_5 , T_5 V_26 ,
T_6 * V_27 )
{
struct V_1 V_2 ;
T_7 V_28 ;
F_11 ( V_5 -> V_8 , V_5 -> V_9 , V_10 ,
V_11 , V_26 , & V_2 ) ;
if ( ! V_2 . V_12 ) {
F_7 ( L_5 , ( unsigned long ) V_26 ) ;
return - 1 ;
}
if ( ! V_2 . V_12 -> V_7 )
return - 1 ;
V_28 = F_12 ( V_2 . V_12 -> V_7 , V_2 . V_12 , V_5 -> V_9 ,
V_26 , ( V_29 * ) V_27 , sizeof( * V_27 ) ) ;
return ! ( V_28 == sizeof( * V_27 ) ) ;
}
static bool F_13 ( T_4 * V_13 V_30 , T_5 V_26 , T_6 * V_31 ,
void * V_24 )
{
struct V_4 * V_5 = V_24 ;
struct V_32 * V_33 = & V_5 -> V_34 -> V_35 ;
T_1 V_16 , V_36 ;
int V_37 ;
int V_38 ;
V_38 = F_14 ( & V_16 , & V_5 -> V_34 -> V_39 , V_40 ) ;
if ( V_38 )
return false ;
V_36 = V_16 + V_33 -> V_28 ;
if ( V_26 + sizeof( T_6 ) < V_26 )
return false ;
if ( V_26 < V_16 || V_26 + sizeof( T_6 ) > V_36 ) {
V_38 = F_10 ( V_5 , V_26 , V_31 ) ;
if ( V_38 ) {
F_7 ( L_6 V_20 L_7
L_8 V_20 L_9 V_20 L_10 ,
V_26 , V_16 , V_36 ) ;
return false ;
}
return true ;
}
V_37 = V_26 - V_16 ;
* V_31 = * ( T_6 * ) & V_33 -> V_27 [ V_37 ] ;
F_7 ( L_11 V_20 L_12 ,
V_26 , ( unsigned long ) * V_31 , V_37 ) ;
return true ;
}
static int
F_15 ( T_8 * V_41 , void * V_24 )
{
struct V_4 * V_5 = V_24 ;
T_5 V_42 ;
if ( ! F_16 ( V_41 , & V_42 , NULL ) ) {
F_17 ( L_13 , F_18 ( - 1 ) ) ;
return V_43 ;
}
return F_6 ( V_42 , V_5 ) || ! ( -- V_5 -> V_44 ) ?
V_43 : V_45 ;
}
int F_19 ( T_9 V_23 , void * V_24 ,
struct V_9 * V_9 , struct V_8 * V_8 ,
struct V_46 * V_27 ,
int V_44 )
{
struct V_4 V_5 = {
. V_34 = V_27 ,
. V_8 = V_8 ,
. V_9 = V_9 ,
. V_23 = V_23 ,
. V_24 = V_24 ,
. V_44 = V_44 ,
} ;
T_6 V_3 ;
int V_47 = - V_48 ;
if ( ! V_27 -> V_39 . V_49 )
return - V_48 ;
V_5 . V_13 = F_20 ( & V_50 ) ;
if ( ! V_5 . V_13 )
goto V_51;
V_47 = F_14 ( & V_3 , & V_27 -> V_39 , V_52 ) ;
if ( V_47 )
goto V_51;
V_47 = F_5 ( V_3 , & V_5 ) ;
if ( V_47 )
goto V_51;
if ( ! F_21 ( V_5 . V_13 , V_53 , V_8 -> V_54 , & V_55 , & V_5 ) )
goto V_51;
V_47 = F_22 ( V_5 . V_13 , V_8 -> V_54 , F_15 , & V_5 ) ;
if ( V_47 && ! V_5 . V_44 )
V_47 = 0 ;
V_51:
if ( V_47 )
F_7 ( L_14 , F_18 ( - 1 ) ) ;
F_23 ( V_5 . V_13 ) ;
return 0 ;
}
