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
T_6 F_26 ( struct V_3 * V_4 , T_7 V_47 )
{
return F_27 ( F_14 ( & V_4 -> V_48 , V_47 ) ) ;
}
T_7 F_28 ( struct V_3 * V_40 , T_6 V_49 )
{
return F_15 ( & V_40 -> V_48 , F_29 ( V_49 ) ) ;
}
T_7 F_30 ( struct V_3 * V_40 , T_6 V_49 )
{
T_7 V_47 ;
V_47 = F_28 ( V_40 , V_49 ) ;
if ( V_47 == ( T_7 ) - 1 )
V_47 = V_50 ;
return V_47 ;
}
static int F_31 ( struct V_51 * V_52 , void * V_53 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_55 * V_36 = V_53 ;
struct V_3 * V_56 ;
T_4 V_57 ;
V_56 = F_32 () ;
if ( ( V_56 == V_4 ) && V_56 -> V_16 )
V_56 = V_56 -> V_16 ;
V_57 = F_18 ( V_56 , F_17 ( V_36 -> V_37 ) ) ;
F_33 ( V_52 , L_1 ,
V_36 -> V_32 ,
V_57 ,
V_36 -> V_29 ) ;
return 0 ;
}
static int F_34 ( struct V_51 * V_52 , void * V_53 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_55 * V_36 = V_53 ;
struct V_3 * V_56 ;
T_5 V_57 ;
V_56 = F_32 () ;
if ( ( V_56 == V_4 ) && V_56 -> V_16 )
V_56 = V_56 -> V_16 ;
V_57 = F_23 ( V_56 , F_22 ( V_36 -> V_37 ) ) ;
F_33 ( V_52 , L_1 ,
V_36 -> V_32 ,
V_57 ,
V_36 -> V_29 ) ;
return 0 ;
}
static int F_35 ( struct V_51 * V_52 , void * V_53 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_55 * V_36 = V_53 ;
struct V_3 * V_56 ;
T_7 V_57 ;
V_56 = F_36 ( V_52 ) ;
if ( ( V_56 == V_4 ) && V_56 -> V_16 )
V_56 = V_56 -> V_16 ;
V_57 = F_28 ( V_56 , F_27 ( V_36 -> V_37 ) ) ;
F_33 ( V_52 , L_1 ,
V_36 -> V_32 ,
V_57 ,
V_36 -> V_29 ) ;
return 0 ;
}
static void * F_37 ( struct V_51 * V_52 , T_8 * V_58 , struct V_26 * V_27 )
{
struct V_55 * V_36 = NULL ;
T_8 V_59 = * V_58 ;
if ( V_59 < V_27 -> V_35 )
V_36 = & V_27 -> V_36 [ V_59 ] ;
return V_36 ;
}
static void * F_38 ( struct V_51 * V_52 , T_8 * V_58 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
return F_37 ( V_52 , V_58 , & V_4 -> V_39 ) ;
}
static void * F_39 ( struct V_51 * V_52 , T_8 * V_58 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
return F_37 ( V_52 , V_58 , & V_4 -> V_44 ) ;
}
static void * F_40 ( struct V_51 * V_52 , T_8 * V_58 )
{
struct V_3 * V_4 = V_52 -> V_54 ;
return F_37 ( V_52 , V_58 , & V_4 -> V_48 ) ;
}
static void * F_41 ( struct V_51 * V_52 , void * V_53 , T_8 * V_59 )
{
( * V_59 ) ++ ;
return V_52 -> V_60 -> V_61 ( V_52 , V_59 ) ;
}
static void F_42 ( struct V_51 * V_52 , void * V_53 )
{
return;
}
static T_9 F_43 ( struct V_62 * V_62 , const char T_10 * V_63 ,
T_11 V_29 , T_8 * V_58 ,
int V_64 ,
struct V_26 * V_27 ,
struct V_26 * V_65 )
{
struct V_51 * V_52 = V_62 -> V_66 ;
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_26 V_67 ;
unsigned V_30 ;
struct V_55 * V_36 , * V_33 = NULL ;
unsigned long V_68 = 0 ;
char * V_69 , * V_59 , * V_70 ;
T_9 V_71 = - V_72 ;
F_44 ( & V_73 ) ;
V_71 = - V_11 ;
if ( V_27 -> V_35 != 0 )
goto V_74;
if ( F_45 ( V_64 ) && ! F_46 ( V_4 , V_64 ) )
goto V_74;
V_71 = - V_14 ;
V_68 = F_47 ( V_75 ) ;
V_69 = ( char * ) V_68 ;
if ( ! V_68 )
goto V_74;
V_71 = - V_72 ;
if ( ( * V_58 != 0 ) || ( V_29 >= V_76 ) )
goto V_74;
V_71 = - V_77 ;
if ( F_48 ( V_69 , V_63 , V_29 ) )
goto V_74;
V_69 [ V_29 ] = '\0' ;
V_71 = - V_72 ;
V_59 = V_69 ;
V_67 . V_35 = 0 ;
for (; V_59 ; V_59 = V_70 ) {
V_36 = & V_67 . V_36 [ V_67 . V_35 ] ;
V_70 = strchr ( V_59 , '\n' ) ;
if ( V_70 ) {
* V_70 = '\0' ;
V_70 ++ ;
if ( * V_70 == '\0' )
V_70 = NULL ;
}
V_59 = F_49 ( V_59 ) ;
V_36 -> V_32 = F_50 ( V_59 , & V_59 , 10 ) ;
if ( ! isspace ( * V_59 ) )
goto V_74;
V_59 = F_49 ( V_59 ) ;
V_36 -> V_37 = F_50 ( V_59 , & V_59 , 10 ) ;
if ( ! isspace ( * V_59 ) )
goto V_74;
V_59 = F_49 ( V_59 ) ;
V_36 -> V_29 = F_50 ( V_59 , & V_59 , 10 ) ;
if ( * V_59 && ! isspace ( * V_59 ) )
goto V_74;
V_59 = F_49 ( V_59 ) ;
if ( * V_59 != '\0' )
goto V_74;
if ( ( V_36 -> V_32 == ( T_3 ) - 1 ) ||
( V_36 -> V_37 == ( T_3 ) - 1 ) )
goto V_74;
if ( ( V_36 -> V_32 + V_36 -> V_29 ) <= V_36 -> V_32 )
goto V_74;
if ( ( V_36 -> V_37 + V_36 -> V_29 ) <= V_36 -> V_37 )
goto V_74;
if ( V_33 &&
( ( ( V_33 -> V_32 + V_33 -> V_29 ) > V_36 -> V_32 ) ||
( ( V_33 -> V_37 + V_33 -> V_29 ) > V_36 -> V_37 ) ) )
goto V_74;
V_67 . V_35 ++ ;
V_33 = V_36 ;
if ( ( V_67 . V_35 == V_78 ) &&
( V_70 != NULL ) )
goto V_74;
}
if ( V_67 . V_35 == 0 )
goto V_74;
V_71 = - V_11 ;
if ( ! F_51 ( V_4 , V_64 , & V_67 ) )
goto V_74;
for ( V_30 = 0 ; V_30 < V_67 . V_35 ; V_30 ++ ) {
T_3 V_37 ;
V_36 = & V_67 . V_36 [ V_30 ] ;
V_37 = F_12 ( V_65 ,
V_36 -> V_37 ,
V_36 -> V_29 ) ;
if ( V_37 == ( T_3 ) - 1 )
goto V_74;
V_36 -> V_37 = V_37 ;
}
memcpy ( V_27 -> V_36 , V_67 . V_36 ,
V_67 . V_35 * sizeof( V_67 . V_36 [ 0 ] ) ) ;
F_52 () ;
V_27 -> V_35 = V_67 . V_35 ;
* V_58 = V_29 ;
V_71 = V_29 ;
V_74:
F_53 ( & V_73 ) ;
if ( V_68 )
F_54 ( V_68 ) ;
return V_71 ;
}
T_9 F_55 ( struct V_62 * V_62 , const char T_10 * V_63 , T_11 V_79 , T_8 * V_58 )
{
struct V_51 * V_52 = V_62 -> V_66 ;
struct V_3 * V_4 = V_52 -> V_54 ;
if ( ! V_4 -> V_16 )
return - V_11 ;
return F_43 ( V_62 , V_63 , V_79 , V_58 , V_80 ,
& V_4 -> V_39 , & V_4 -> V_16 -> V_39 ) ;
}
T_9 F_56 ( struct V_62 * V_62 , const char T_10 * V_63 , T_11 V_79 , T_8 * V_58 )
{
struct V_51 * V_52 = V_62 -> V_66 ;
struct V_3 * V_4 = V_52 -> V_54 ;
if ( ! V_4 -> V_16 )
return - V_11 ;
return F_43 ( V_62 , V_63 , V_79 , V_58 , V_81 ,
& V_4 -> V_44 , & V_4 -> V_16 -> V_44 ) ;
}
T_9 F_57 ( struct V_62 * V_62 , const char T_10 * V_63 , T_11 V_79 , T_8 * V_58 )
{
struct V_51 * V_52 = V_62 -> V_66 ;
struct V_3 * V_4 = V_52 -> V_54 ;
struct V_3 * V_82 = F_36 ( V_52 ) ;
if ( ! V_4 -> V_16 )
return - V_11 ;
if ( ( V_82 != V_4 ) && ( V_82 != V_4 -> V_16 ) )
return - V_11 ;
return F_43 ( V_62 , V_63 , V_79 , V_58 , - 1 ,
& V_4 -> V_48 , & V_4 -> V_16 -> V_48 ) ;
}
static bool F_51 ( struct V_3 * V_4 , int V_64 ,
struct V_26 * V_67 )
{
if ( ! F_45 ( V_64 ) )
return true ;
if ( F_46 ( V_4 -> V_16 , V_64 ) )
return true ;
return false ;
}
static T_12 int F_58 ( void )
{
V_12 = F_59 ( V_3 , V_83 ) ;
return 0 ;
}
