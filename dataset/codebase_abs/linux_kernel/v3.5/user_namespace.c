int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = V_2 -> V_6 ;
T_1 V_7 = V_2 -> V_8 ;
T_2 V_9 = V_2 -> V_10 ;
if ( ! F_2 ( V_5 , V_7 ) ||
! F_3 ( V_5 , V_9 ) )
return - V_11 ;
V_4 = F_4 ( V_12 , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
F_5 ( & V_4 -> V_15 ) ;
V_4 -> V_16 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_9 = V_9 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = V_22 ;
V_2 -> V_24 = V_22 ;
#ifdef F_6
F_7 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
#endif
V_2 -> V_6 = V_4 ;
return 0 ;
}
void F_8 ( struct V_15 * V_15 )
{
struct V_3 * V_16 , * V_4 =
F_9 ( V_15 , struct V_3 , V_15 ) ;
V_16 = V_4 -> V_16 ;
F_10 ( V_12 , V_4 ) ;
F_11 ( V_16 ) ;
}
static T_3 F_12 ( struct V_26 * V_27 , T_3 V_28 , T_3 V_29 )
{
unsigned V_30 , V_31 ;
T_3 V_32 , V_33 , V_34 ;
V_34 = V_28 + V_29 - 1 ;
V_31 = V_27 -> V_35 ;
F_13 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_32 = V_27 -> V_36 [ V_30 ] . V_32 ;
V_33 = V_32 + V_27 -> V_36 [ V_30 ] . V_29 - 1 ;
if ( V_28 >= V_32 && V_28 <= V_33 &&
( V_34 >= V_32 && V_34 <= V_33 ) )
break;
}
if ( V_30 < V_31 )
V_28 = ( V_28 - V_32 ) + V_27 -> V_36 [ V_30 ] . V_37 ;
else
V_28 = ( T_3 ) - 1 ;
return V_28 ;
}
static T_3 F_14 ( struct V_26 * V_27 , T_3 V_28 )
{
unsigned V_30 , V_31 ;
T_3 V_32 , V_33 ;
V_31 = V_27 -> V_35 ;
F_13 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_32 = V_27 -> V_36 [ V_30 ] . V_32 ;
V_33 = V_32 + V_27 -> V_36 [ V_30 ] . V_29 - 1 ;
if ( V_28 >= V_32 && V_28 <= V_33 )
break;
}
if ( V_30 < V_31 )
V_28 = ( V_28 - V_32 ) + V_27 -> V_36 [ V_30 ] . V_37 ;
else
V_28 = ( T_3 ) - 1 ;
return V_28 ;
}
static T_3 F_15 ( struct V_26 * V_27 , T_3 V_28 )
{
unsigned V_30 , V_31 ;
T_3 V_32 , V_33 ;
V_31 = V_27 -> V_35 ;
F_13 () ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_32 = V_27 -> V_36 [ V_30 ] . V_37 ;
V_33 = V_32 + V_27 -> V_36 [ V_30 ] . V_29 - 1 ;
if ( V_28 >= V_32 && V_28 <= V_33 )
break;
}
if ( V_30 < V_31 )
V_28 = ( V_28 - V_32 ) + V_27 -> V_36 [ V_30 ] . V_32 ;
else
V_28 = ( T_3 ) - 1 ;
return V_28 ;
}
T_1 F_16 ( struct V_3 * V_4 , T_4 V_38 )
{
return F_17 ( F_14 ( & V_4 -> V_39 , V_38 ) ) ;
}
T_4 F_18 ( struct V_3 * V_40 , T_1 V_41 )
{
return F_15 ( & V_40 -> V_39 , F_19 ( V_41 ) ) ;
}
T_4 F_20 ( struct V_3 * V_40 , T_1 V_41 )
{
T_4 V_38 ;
V_38 = F_18 ( V_40 , V_41 ) ;
if ( V_38 == ( T_4 ) - 1 )
V_38 = V_42 ;
return V_38 ;
}
T_2 F_21 ( struct V_3 * V_4 , T_5 V_43 )
{
return F_22 ( F_14 ( & V_4 -> V_44 , V_43 ) ) ;
}
T_5 F_23 ( struct V_3 * V_40 , T_2 V_45 )
{
return F_15 ( & V_40 -> V_44 , F_24 ( V_45 ) ) ;
}
T_5 F_25 ( struct V_3 * V_40 , T_2 V_45 )
{
T_5 V_43 ;
V_43 = F_23 ( V_40 , V_45 ) ;
if ( V_43 == ( T_5 ) - 1 )
V_43 = V_46 ;
return V_43 ;
}
static int F_26 ( struct V_47 * V_48 , void * V_49 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_51 * V_36 = V_49 ;
struct V_3 * V_52 ;
T_4 V_53 ;
V_52 = F_27 () ;
if ( ( V_52 == V_4 ) && V_52 -> V_16 )
V_52 = V_52 -> V_16 ;
V_53 = F_18 ( V_52 , F_17 ( V_36 -> V_37 ) ) ;
F_28 ( V_48 , L_1 ,
V_36 -> V_32 ,
V_53 ,
V_36 -> V_29 ) ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 , void * V_49 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_51 * V_36 = V_49 ;
struct V_3 * V_52 ;
T_5 V_53 ;
V_52 = F_27 () ;
if ( ( V_52 == V_4 ) && V_52 -> V_16 )
V_52 = V_52 -> V_16 ;
V_53 = F_23 ( V_52 , F_22 ( V_36 -> V_37 ) ) ;
F_28 ( V_48 , L_1 ,
V_36 -> V_32 ,
V_53 ,
V_36 -> V_29 ) ;
return 0 ;
}
static void * F_30 ( struct V_47 * V_48 , T_6 * V_54 , struct V_26 * V_27 )
{
struct V_51 * V_36 = NULL ;
T_6 V_55 = * V_54 ;
if ( V_55 < V_27 -> V_35 )
V_36 = & V_27 -> V_36 [ V_55 ] ;
return V_36 ;
}
static void * F_31 ( struct V_47 * V_48 , T_6 * V_54 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
return F_30 ( V_48 , V_54 , & V_4 -> V_39 ) ;
}
static void * F_32 ( struct V_47 * V_48 , T_6 * V_54 )
{
struct V_3 * V_4 = V_48 -> V_50 ;
return F_30 ( V_48 , V_54 , & V_4 -> V_44 ) ;
}
static void * F_33 ( struct V_47 * V_48 , void * V_49 , T_6 * V_55 )
{
( * V_55 ) ++ ;
return V_48 -> V_56 -> V_57 ( V_48 , V_55 ) ;
}
static void F_34 ( struct V_47 * V_48 , void * V_49 )
{
return;
}
static T_7 F_35 ( struct V_58 * V_58 , const char T_8 * V_59 ,
T_9 V_29 , T_6 * V_54 ,
int V_60 ,
struct V_26 * V_27 ,
struct V_26 * V_61 )
{
struct V_47 * V_48 = V_58 -> V_62 ;
struct V_3 * V_4 = V_48 -> V_50 ;
struct V_26 V_63 ;
unsigned V_30 ;
struct V_51 * V_36 , * V_33 = NULL ;
unsigned long V_64 = 0 ;
char * V_65 , * V_55 , * V_66 ;
T_7 V_67 = - V_68 ;
F_36 ( & V_69 ) ;
V_67 = - V_11 ;
if ( V_27 -> V_35 != 0 )
goto V_70;
if ( ! F_37 ( V_4 , V_60 ) )
goto V_70;
V_67 = - V_14 ;
V_64 = F_38 ( V_71 ) ;
V_65 = ( char * ) V_64 ;
if ( ! V_64 )
goto V_70;
V_67 = - V_68 ;
if ( ( * V_54 != 0 ) || ( V_29 >= V_72 ) )
goto V_70;
V_67 = - V_73 ;
if ( F_39 ( V_65 , V_59 , V_29 ) )
goto V_70;
V_65 [ V_29 ] = '\0' ;
V_67 = - V_68 ;
V_55 = V_65 ;
V_63 . V_35 = 0 ;
for (; V_55 ; V_55 = V_66 ) {
V_36 = & V_63 . V_36 [ V_63 . V_35 ] ;
V_66 = strchr ( V_55 , '\n' ) ;
if ( V_66 ) {
* V_66 = '\0' ;
V_66 ++ ;
if ( * V_66 == '\0' )
V_66 = NULL ;
}
V_55 = F_40 ( V_55 ) ;
V_36 -> V_32 = F_41 ( V_55 , & V_55 , 10 ) ;
if ( ! isspace ( * V_55 ) )
goto V_70;
V_55 = F_40 ( V_55 ) ;
V_36 -> V_37 = F_41 ( V_55 , & V_55 , 10 ) ;
if ( ! isspace ( * V_55 ) )
goto V_70;
V_55 = F_40 ( V_55 ) ;
V_36 -> V_29 = F_41 ( V_55 , & V_55 , 10 ) ;
if ( * V_55 && ! isspace ( * V_55 ) )
goto V_70;
V_55 = F_40 ( V_55 ) ;
if ( * V_55 != '\0' )
goto V_70;
if ( ( V_36 -> V_32 == ( T_3 ) - 1 ) ||
( V_36 -> V_37 == ( T_3 ) - 1 ) )
goto V_70;
if ( ( V_36 -> V_32 + V_36 -> V_29 ) <= V_36 -> V_32 )
goto V_70;
if ( ( V_36 -> V_37 + V_36 -> V_29 ) <= V_36 -> V_37 )
goto V_70;
if ( V_33 &&
( ( ( V_33 -> V_32 + V_33 -> V_29 ) > V_36 -> V_32 ) ||
( ( V_33 -> V_37 + V_33 -> V_29 ) > V_36 -> V_37 ) ) )
goto V_70;
V_63 . V_35 ++ ;
V_33 = V_36 ;
if ( ( V_63 . V_35 == V_74 ) &&
( V_66 != NULL ) )
goto V_70;
}
if ( V_63 . V_35 == 0 )
goto V_70;
V_67 = - V_11 ;
if ( ! F_42 ( V_4 , V_60 , & V_63 ) )
goto V_70;
for ( V_30 = 0 ; V_30 < V_63 . V_35 ; V_30 ++ ) {
T_3 V_37 ;
V_36 = & V_63 . V_36 [ V_30 ] ;
V_37 = F_12 ( V_61 ,
V_36 -> V_37 ,
V_36 -> V_29 ) ;
if ( V_37 == ( T_3 ) - 1 )
goto V_70;
V_36 -> V_37 = V_37 ;
}
memcpy ( V_27 -> V_36 , V_63 . V_36 ,
V_63 . V_35 * sizeof( V_63 . V_36 [ 0 ] ) ) ;
F_43 () ;
V_27 -> V_35 = V_63 . V_35 ;
* V_54 = V_29 ;
V_67 = V_29 ;
V_70:
F_44 ( & V_69 ) ;
if ( V_64 )
F_45 ( V_64 ) ;
return V_67 ;
}
T_7 F_46 ( struct V_58 * V_58 , const char T_8 * V_59 , T_9 V_75 , T_6 * V_54 )
{
struct V_47 * V_48 = V_58 -> V_62 ;
struct V_3 * V_4 = V_48 -> V_50 ;
if ( ! V_4 -> V_16 )
return - V_11 ;
return F_35 ( V_58 , V_59 , V_75 , V_54 , V_76 ,
& V_4 -> V_39 , & V_4 -> V_16 -> V_39 ) ;
}
T_7 F_47 ( struct V_58 * V_58 , const char T_8 * V_59 , T_9 V_75 , T_6 * V_54 )
{
struct V_47 * V_48 = V_58 -> V_62 ;
struct V_3 * V_4 = V_48 -> V_50 ;
if ( ! V_4 -> V_16 )
return - V_11 ;
return F_35 ( V_58 , V_59 , V_75 , V_54 , V_77 ,
& V_4 -> V_44 , & V_4 -> V_16 -> V_44 ) ;
}
static bool F_42 ( struct V_3 * V_4 , int V_60 ,
struct V_26 * V_63 )
{
if ( F_37 ( V_4 -> V_16 , V_60 ) )
return true ;
return false ;
}
static T_10 int F_48 ( void )
{
V_12 = F_49 ( V_3 , V_78 ) ;
return 0 ;
}
