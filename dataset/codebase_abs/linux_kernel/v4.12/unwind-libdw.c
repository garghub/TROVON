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
if ( V_6 ) {
T_3 V_13 ;
F_4 ( V_6 , NULL , & V_13 , NULL , NULL , NULL , NULL , NULL ) ;
if ( V_13 != V_2 -> V_11 -> V_14 )
V_6 = 0 ;
}
if ( ! V_6 )
V_6 = F_5 ( V_5 -> V_12 , V_7 -> V_15 ,
V_7 -> V_16 , - 1 , V_2 -> V_11 -> V_14 ,
false ) ;
return V_6 && F_3 ( V_5 -> V_12 , V_3 ) == V_6 ? 0 : - 1 ;
}
static int F_6 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_1 V_2 ;
return F_1 ( & V_2 , V_3 , V_5 ) ;
}
static int F_7 ( T_1 V_3 , struct V_4 * V_5 )
{
struct V_17 * V_18 = & V_5 -> V_19 [ V_5 -> V_20 ++ ] ;
struct V_1 V_2 ;
if ( F_1 ( & V_2 , V_3 , V_5 ) )
return - 1 ;
V_18 -> V_3 = V_2 . V_21 ;
V_18 -> V_11 = V_2 . V_11 ;
V_18 -> V_22 = V_2 . V_22 ;
F_8 ( L_1 V_23 L_2 V_23 L_3 ,
V_2 . V_22 ? V_2 . V_22 -> V_24 : L_4 ,
V_3 ,
V_2 . V_11 ? V_2 . V_11 -> V_25 ( V_2 . V_11 , V_3 ) : ( T_1 ) 0 ) ;
return 0 ;
}
static T_4 F_9 ( T_5 * V_12 , void * V_26 , void * * V_27 )
{
if ( * V_27 != NULL )
return 0 ;
* V_27 = V_26 ;
return F_10 ( V_12 ) ;
}
static int F_11 ( struct V_4 * V_5 , T_3 V_21 ,
T_6 * V_28 )
{
struct V_1 V_2 ;
T_7 V_29 ;
F_12 ( V_5 -> V_8 , V_9 ,
V_10 , V_21 , & V_2 ) ;
if ( ! V_2 . V_11 ) {
F_12 ( V_5 -> V_8 , V_9 ,
V_30 , V_21 , & V_2 ) ;
}
if ( ! V_2 . V_11 ) {
F_8 ( L_5 , ( unsigned long ) V_21 ) ;
return - 1 ;
}
if ( ! V_2 . V_11 -> V_7 )
return - 1 ;
V_29 = F_13 ( V_2 . V_11 -> V_7 , V_2 . V_11 , V_5 -> V_31 ,
V_21 , ( V_32 * ) V_28 , sizeof( * V_28 ) ) ;
return ! ( V_29 == sizeof( * V_28 ) ) ;
}
static bool F_14 ( T_5 * V_12 V_33 , T_3 V_21 , T_6 * V_34 ,
void * V_26 )
{
struct V_4 * V_5 = V_26 ;
struct V_35 * V_36 = & V_5 -> V_37 -> V_38 ;
T_1 V_14 , V_39 ;
int V_40 ;
int V_41 ;
V_41 = F_15 ( & V_14 , & V_5 -> V_37 -> V_42 , V_43 ) ;
if ( V_41 )
return false ;
V_39 = V_14 + V_36 -> V_29 ;
if ( V_21 + sizeof( T_6 ) < V_21 )
return false ;
if ( V_21 < V_14 || V_21 + sizeof( T_6 ) > V_39 ) {
V_41 = F_11 ( V_5 , V_21 , V_34 ) ;
if ( V_41 ) {
F_8 ( L_6 V_23 L_7
L_8 V_23 L_9 V_23 L_10 ,
V_21 , V_14 , V_39 ) ;
return false ;
}
return true ;
}
V_40 = V_21 - V_14 ;
* V_34 = * ( T_6 * ) & V_36 -> V_28 [ V_40 ] ;
F_8 ( L_11 V_23 L_12 ,
V_21 , ( unsigned long ) * V_34 , V_40 ) ;
return true ;
}
static int
F_16 ( T_8 * V_44 , void * V_26 )
{
struct V_4 * V_5 = V_26 ;
T_3 V_45 ;
bool V_46 ;
if ( ! F_17 ( V_44 , & V_45 , NULL ) ) {
F_18 ( L_13 , F_19 ( - 1 ) ) ;
return V_47 ;
}
F_6 ( V_45 , V_5 ) ;
if ( ! F_17 ( V_44 , & V_45 , & V_46 ) ) {
F_18 ( L_13 , F_19 ( - 1 ) ) ;
return V_47 ;
}
if ( ! V_46 )
-- V_45 ;
return F_7 ( V_45 , V_5 ) || ! ( -- V_5 -> V_48 ) ?
V_47 : V_49 ;
}
int F_20 ( T_9 V_50 , void * V_26 ,
struct V_8 * V_8 ,
struct V_51 * V_28 ,
int V_48 )
{
struct V_4 * V_5 , V_52 = {
. V_37 = V_28 ,
. V_8 = V_8 ,
. V_31 = V_8 -> V_53 -> V_31 ,
. V_50 = V_50 ,
. V_26 = V_26 ,
. V_48 = V_48 ,
} ;
T_6 V_3 ;
int V_54 = - V_55 , V_56 ;
if ( ! V_28 -> V_42 . V_57 )
return - V_55 ;
V_5 = F_21 ( sizeof( V_52 ) + sizeof( V_52 . V_19 [ 0 ] ) * V_48 ) ;
if ( ! V_5 )
return - V_58 ;
* V_5 = V_52 ;
V_5 -> V_12 = F_22 ( & V_59 ) ;
if ( ! V_5 -> V_12 )
goto V_60;
V_54 = F_15 ( & V_3 , & V_28 -> V_42 , V_61 ) ;
if ( V_54 )
goto V_60;
V_54 = F_6 ( V_3 , V_5 ) ;
if ( V_54 )
goto V_60;
if ( ! F_23 ( V_5 -> V_12 , V_62 , V_8 -> V_63 , & V_64 , V_5 ) )
goto V_60;
V_54 = F_24 ( V_5 -> V_12 , V_8 -> V_63 , F_16 , V_5 ) ;
if ( V_54 && V_5 -> V_48 != V_48 )
V_54 = 0 ;
for ( V_56 = 0 ; V_56 < V_5 -> V_20 && ! V_54 ; V_56 ++ ) {
int V_65 = V_56 ;
if ( V_66 . V_67 == V_68 )
V_65 = V_5 -> V_20 - V_56 - 1 ;
V_54 = V_5 -> V_19 [ V_65 ] . V_3 ? V_5 -> V_50 ( & V_5 -> V_19 [ V_65 ] , V_5 -> V_26 ) : 0 ;
}
V_60:
if ( V_54 )
F_8 ( L_14 , F_19 ( - 1 ) ) ;
F_25 ( V_5 -> V_12 ) ;
free ( V_5 ) ;
return 0 ;
}
