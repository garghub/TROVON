static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_1 -> V_4 = V_5 ;
V_1 -> V_6 = V_7 ;
V_1 -> V_8 = V_9 ;
V_1 -> V_10 = V_9 ;
V_1 -> V_11 = V_9 ;
#ifdef F_2
F_3 ( V_1 -> V_12 ) ;
V_1 -> V_12 = NULL ;
#endif
V_1 -> V_3 = V_3 ;
}
int F_4 ( struct V_1 * V_13 )
{
struct V_2 * V_14 , * V_15 = V_13 -> V_3 ;
T_1 V_16 = V_13 -> V_17 ;
T_2 V_18 = V_13 -> V_19 ;
int V_20 ;
if ( ! F_5 ( V_15 , V_16 ) ||
! F_6 ( V_15 , V_18 ) )
return - V_21 ;
V_14 = F_7 ( V_22 , V_23 ) ;
if ( ! V_14 )
return - V_24 ;
V_20 = F_8 ( & V_14 -> V_25 ) ;
if ( V_20 ) {
F_9 ( V_22 , V_14 ) ;
return V_20 ;
}
F_10 ( & V_14 -> V_26 ) ;
V_14 -> V_27 = V_15 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_18 = V_18 ;
F_1 ( V_13 , V_14 ) ;
return 0 ;
}
int F_11 ( unsigned long V_28 , struct V_1 * * V_29 )
{
struct V_1 * V_1 ;
if ( ! ( V_28 & V_30 ) )
return 0 ;
V_1 = F_12 () ;
if ( ! V_1 )
return - V_24 ;
* V_29 = V_1 ;
return F_4 ( V_1 ) ;
}
void F_13 ( struct V_26 * V_26 )
{
struct V_2 * V_27 , * V_14 =
F_14 ( V_26 , struct V_2 , V_26 ) ;
V_27 = V_14 -> V_27 ;
F_15 ( V_14 -> V_25 ) ;
F_9 ( V_22 , V_14 ) ;
F_16 ( V_27 ) ;
}
static T_3 F_17 ( struct V_31 * V_32 , T_3 V_33 , T_3 V_34 )
{
unsigned V_35 , V_36 ;
T_3 V_37 , V_38 , V_39 ;
V_39 = V_33 + V_34 - 1 ;
V_36 = V_32 -> V_40 ;
F_18 () ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_37 = V_32 -> V_41 [ V_35 ] . V_37 ;
V_38 = V_37 + V_32 -> V_41 [ V_35 ] . V_34 - 1 ;
if ( V_33 >= V_37 && V_33 <= V_38 &&
( V_39 >= V_37 && V_39 <= V_38 ) )
break;
}
if ( V_35 < V_36 )
V_33 = ( V_33 - V_37 ) + V_32 -> V_41 [ V_35 ] . V_42 ;
else
V_33 = ( T_3 ) - 1 ;
return V_33 ;
}
static T_3 F_19 ( struct V_31 * V_32 , T_3 V_33 )
{
unsigned V_35 , V_36 ;
T_3 V_37 , V_38 ;
V_36 = V_32 -> V_40 ;
F_18 () ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_37 = V_32 -> V_41 [ V_35 ] . V_37 ;
V_38 = V_37 + V_32 -> V_41 [ V_35 ] . V_34 - 1 ;
if ( V_33 >= V_37 && V_33 <= V_38 )
break;
}
if ( V_35 < V_36 )
V_33 = ( V_33 - V_37 ) + V_32 -> V_41 [ V_35 ] . V_42 ;
else
V_33 = ( T_3 ) - 1 ;
return V_33 ;
}
static T_3 F_20 ( struct V_31 * V_32 , T_3 V_33 )
{
unsigned V_35 , V_36 ;
T_3 V_37 , V_38 ;
V_36 = V_32 -> V_40 ;
F_18 () ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_37 = V_32 -> V_41 [ V_35 ] . V_42 ;
V_38 = V_37 + V_32 -> V_41 [ V_35 ] . V_34 - 1 ;
if ( V_33 >= V_37 && V_33 <= V_38 )
break;
}
if ( V_35 < V_36 )
V_33 = ( V_33 - V_37 ) + V_32 -> V_41 [ V_35 ] . V_37 ;
else
V_33 = ( T_3 ) - 1 ;
return V_33 ;
}
T_1 F_21 ( struct V_2 * V_14 , T_4 V_43 )
{
return F_22 ( F_19 ( & V_14 -> V_44 , V_43 ) ) ;
}
T_4 F_23 ( struct V_2 * V_45 , T_1 V_46 )
{
return F_20 ( & V_45 -> V_44 , F_24 ( V_46 ) ) ;
}
T_4 F_25 ( struct V_2 * V_45 , T_1 V_46 )
{
T_4 V_43 ;
V_43 = F_23 ( V_45 , V_46 ) ;
if ( V_43 == ( T_4 ) - 1 )
V_43 = V_47 ;
return V_43 ;
}
T_2 F_26 ( struct V_2 * V_14 , T_5 V_48 )
{
return F_27 ( F_19 ( & V_14 -> V_49 , V_48 ) ) ;
}
T_5 F_28 ( struct V_2 * V_45 , T_2 V_50 )
{
return F_20 ( & V_45 -> V_49 , F_29 ( V_50 ) ) ;
}
T_5 F_30 ( struct V_2 * V_45 , T_2 V_50 )
{
T_5 V_48 ;
V_48 = F_28 ( V_45 , V_50 ) ;
if ( V_48 == ( T_5 ) - 1 )
V_48 = V_51 ;
return V_48 ;
}
T_6 F_31 ( struct V_2 * V_14 , T_7 V_52 )
{
return F_32 ( F_19 ( & V_14 -> V_53 , V_52 ) ) ;
}
T_7 F_33 ( struct V_2 * V_45 , T_6 V_54 )
{
return F_20 ( & V_45 -> V_53 , F_34 ( V_54 ) ) ;
}
T_7 F_35 ( struct V_2 * V_45 , T_6 V_54 )
{
T_7 V_52 ;
V_52 = F_33 ( V_45 , V_54 ) ;
if ( V_52 == ( T_7 ) - 1 )
V_52 = V_55 ;
return V_52 ;
}
static int F_36 ( struct V_56 * V_57 , void * V_58 )
{
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_60 * V_41 = V_58 ;
struct V_2 * V_61 ;
T_4 V_62 ;
V_61 = F_37 ( V_57 ) ;
if ( ( V_61 == V_14 ) && V_61 -> V_27 )
V_61 = V_61 -> V_27 ;
V_62 = F_23 ( V_61 , F_22 ( V_41 -> V_42 ) ) ;
F_38 ( V_57 , L_1 ,
V_41 -> V_37 ,
V_62 ,
V_41 -> V_34 ) ;
return 0 ;
}
static int F_39 ( struct V_56 * V_57 , void * V_58 )
{
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_60 * V_41 = V_58 ;
struct V_2 * V_61 ;
T_5 V_62 ;
V_61 = F_37 ( V_57 ) ;
if ( ( V_61 == V_14 ) && V_61 -> V_27 )
V_61 = V_61 -> V_27 ;
V_62 = F_28 ( V_61 , F_27 ( V_41 -> V_42 ) ) ;
F_38 ( V_57 , L_1 ,
V_41 -> V_37 ,
V_62 ,
V_41 -> V_34 ) ;
return 0 ;
}
static int F_40 ( struct V_56 * V_57 , void * V_58 )
{
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_60 * V_41 = V_58 ;
struct V_2 * V_61 ;
T_7 V_62 ;
V_61 = F_37 ( V_57 ) ;
if ( ( V_61 == V_14 ) && V_61 -> V_27 )
V_61 = V_61 -> V_27 ;
V_62 = F_33 ( V_61 , F_32 ( V_41 -> V_42 ) ) ;
F_38 ( V_57 , L_1 ,
V_41 -> V_37 ,
V_62 ,
V_41 -> V_34 ) ;
return 0 ;
}
static void * F_41 ( struct V_56 * V_57 , T_8 * V_63 , struct V_31 * V_32 )
{
struct V_60 * V_41 = NULL ;
T_8 V_64 = * V_63 ;
if ( V_64 < V_32 -> V_40 )
V_41 = & V_32 -> V_41 [ V_64 ] ;
return V_41 ;
}
static void * F_42 ( struct V_56 * V_57 , T_8 * V_63 )
{
struct V_2 * V_14 = V_57 -> V_59 ;
return F_41 ( V_57 , V_63 , & V_14 -> V_44 ) ;
}
static void * F_43 ( struct V_56 * V_57 , T_8 * V_63 )
{
struct V_2 * V_14 = V_57 -> V_59 ;
return F_41 ( V_57 , V_63 , & V_14 -> V_49 ) ;
}
static void * F_44 ( struct V_56 * V_57 , T_8 * V_63 )
{
struct V_2 * V_14 = V_57 -> V_59 ;
return F_41 ( V_57 , V_63 , & V_14 -> V_53 ) ;
}
static void * F_45 ( struct V_56 * V_57 , void * V_58 , T_8 * V_64 )
{
( * V_64 ) ++ ;
return V_57 -> V_65 -> V_66 ( V_57 , V_64 ) ;
}
static void F_46 ( struct V_56 * V_57 , void * V_58 )
{
return;
}
static T_9 F_47 ( struct V_67 * V_67 , const char T_10 * V_68 ,
T_11 V_34 , T_8 * V_63 ,
int V_69 ,
struct V_31 * V_32 ,
struct V_31 * V_70 )
{
struct V_56 * V_57 = V_67 -> V_71 ;
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_31 V_72 ;
unsigned V_35 ;
struct V_60 * V_41 , * V_38 = NULL ;
unsigned long V_73 = 0 ;
char * V_74 , * V_64 , * V_75 ;
T_9 V_20 = - V_76 ;
F_48 ( & V_77 ) ;
V_20 = - V_21 ;
if ( V_32 -> V_40 != 0 )
goto V_78;
if ( F_49 ( V_69 ) && ! F_50 ( V_14 , V_69 ) )
goto V_78;
V_20 = - V_24 ;
V_73 = F_51 ( V_79 ) ;
V_74 = ( char * ) V_73 ;
if ( ! V_73 )
goto V_78;
V_20 = - V_76 ;
if ( ( * V_63 != 0 ) || ( V_34 >= V_80 ) )
goto V_78;
V_20 = - V_81 ;
if ( F_52 ( V_74 , V_68 , V_34 ) )
goto V_78;
V_74 [ V_34 ] = '\0' ;
V_20 = - V_76 ;
V_64 = V_74 ;
V_72 . V_40 = 0 ;
for (; V_64 ; V_64 = V_75 ) {
V_41 = & V_72 . V_41 [ V_72 . V_40 ] ;
V_75 = strchr ( V_64 , '\n' ) ;
if ( V_75 ) {
* V_75 = '\0' ;
V_75 ++ ;
if ( * V_75 == '\0' )
V_75 = NULL ;
}
V_64 = F_53 ( V_64 ) ;
V_41 -> V_37 = F_54 ( V_64 , & V_64 , 10 ) ;
if ( ! isspace ( * V_64 ) )
goto V_78;
V_64 = F_53 ( V_64 ) ;
V_41 -> V_42 = F_54 ( V_64 , & V_64 , 10 ) ;
if ( ! isspace ( * V_64 ) )
goto V_78;
V_64 = F_53 ( V_64 ) ;
V_41 -> V_34 = F_54 ( V_64 , & V_64 , 10 ) ;
if ( * V_64 && ! isspace ( * V_64 ) )
goto V_78;
V_64 = F_53 ( V_64 ) ;
if ( * V_64 != '\0' )
goto V_78;
if ( ( V_41 -> V_37 == ( T_3 ) - 1 ) ||
( V_41 -> V_42 == ( T_3 ) - 1 ) )
goto V_78;
if ( ( V_41 -> V_37 + V_41 -> V_34 ) <= V_41 -> V_37 )
goto V_78;
if ( ( V_41 -> V_42 + V_41 -> V_34 ) <= V_41 -> V_42 )
goto V_78;
if ( V_38 &&
( ( ( V_38 -> V_37 + V_38 -> V_34 ) > V_41 -> V_37 ) ||
( ( V_38 -> V_42 + V_38 -> V_34 ) > V_41 -> V_42 ) ) )
goto V_78;
V_72 . V_40 ++ ;
V_38 = V_41 ;
if ( ( V_72 . V_40 == V_82 ) &&
( V_75 != NULL ) )
goto V_78;
}
if ( V_72 . V_40 == 0 )
goto V_78;
V_20 = - V_21 ;
if ( ! F_55 ( V_14 , V_69 , & V_72 ) )
goto V_78;
for ( V_35 = 0 ; V_35 < V_72 . V_40 ; V_35 ++ ) {
T_3 V_42 ;
V_41 = & V_72 . V_41 [ V_35 ] ;
V_42 = F_17 ( V_70 ,
V_41 -> V_42 ,
V_41 -> V_34 ) ;
if ( V_42 == ( T_3 ) - 1 )
goto V_78;
V_41 -> V_42 = V_42 ;
}
memcpy ( V_32 -> V_41 , V_72 . V_41 ,
V_72 . V_40 * sizeof( V_72 . V_41 [ 0 ] ) ) ;
F_56 () ;
V_32 -> V_40 = V_72 . V_40 ;
* V_63 = V_34 ;
V_20 = V_34 ;
V_78:
F_57 ( & V_77 ) ;
if ( V_73 )
F_58 ( V_73 ) ;
return V_20 ;
}
T_9 F_59 ( struct V_67 * V_67 , const char T_10 * V_68 , T_11 V_83 , T_8 * V_63 )
{
struct V_56 * V_57 = V_67 -> V_71 ;
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_2 * V_84 = F_37 ( V_57 ) ;
if ( ! V_14 -> V_27 )
return - V_21 ;
if ( ( V_84 != V_14 ) && ( V_84 != V_14 -> V_27 ) )
return - V_21 ;
return F_47 ( V_67 , V_68 , V_83 , V_63 , V_85 ,
& V_14 -> V_44 , & V_14 -> V_27 -> V_44 ) ;
}
T_9 F_60 ( struct V_67 * V_67 , const char T_10 * V_68 , T_11 V_83 , T_8 * V_63 )
{
struct V_56 * V_57 = V_67 -> V_71 ;
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_2 * V_84 = F_37 ( V_57 ) ;
if ( ! V_14 -> V_27 )
return - V_21 ;
if ( ( V_84 != V_14 ) && ( V_84 != V_14 -> V_27 ) )
return - V_21 ;
return F_47 ( V_67 , V_68 , V_83 , V_63 , V_86 ,
& V_14 -> V_49 , & V_14 -> V_27 -> V_49 ) ;
}
T_9 F_61 ( struct V_67 * V_67 , const char T_10 * V_68 , T_11 V_83 , T_8 * V_63 )
{
struct V_56 * V_57 = V_67 -> V_71 ;
struct V_2 * V_14 = V_57 -> V_59 ;
struct V_2 * V_84 = F_37 ( V_57 ) ;
if ( ! V_14 -> V_27 )
return - V_21 ;
if ( ( V_84 != V_14 ) && ( V_84 != V_14 -> V_27 ) )
return - V_21 ;
return F_47 ( V_67 , V_68 , V_83 , V_63 , - 1 ,
& V_14 -> V_53 , & V_14 -> V_27 -> V_53 ) ;
}
static bool F_55 ( struct V_2 * V_14 , int V_69 ,
struct V_31 * V_72 )
{
if ( ( V_72 -> V_40 == 1 ) && ( V_72 -> V_41 [ 0 ] . V_34 == 1 ) ) {
T_3 V_33 = V_72 -> V_41 [ 0 ] . V_42 ;
if ( V_69 == V_85 ) {
T_1 V_43 = F_21 ( V_14 -> V_27 , V_33 ) ;
if ( F_62 ( V_43 , F_63 () ) )
return true ;
}
else if ( V_69 == V_86 ) {
T_2 V_48 = F_26 ( V_14 -> V_27 , V_33 ) ;
if ( F_64 ( V_48 , F_65 () ) )
return true ;
}
}
if ( ! F_49 ( V_69 ) )
return true ;
if ( F_50 ( V_14 -> V_27 , V_69 ) )
return true ;
return false ;
}
static void * F_66 ( struct V_87 * V_88 )
{
struct V_2 * V_3 ;
F_67 () ;
V_3 = F_68 ( F_69 ( V_88 ) -> V_3 ) ;
F_70 () ;
return V_3 ;
}
static void F_71 ( void * V_14 )
{
F_16 ( V_14 ) ;
}
static int F_72 ( struct V_89 * V_89 , void * V_14 )
{
struct V_2 * V_3 = V_14 ;
struct V_1 * V_1 ;
if ( V_3 == F_73 () )
return - V_76 ;
if ( F_74 ( & V_90 -> V_91 -> V_92 ) > 1 )
return - V_76 ;
if ( ! F_50 ( V_3 , V_93 ) )
return - V_21 ;
V_1 = F_12 () ;
if ( ! V_1 )
return - V_24 ;
F_16 ( V_1 -> V_3 ) ;
F_1 ( V_1 , F_68 ( V_3 ) ) ;
return F_75 ( V_1 ) ;
}
static unsigned int F_76 ( void * V_14 )
{
struct V_2 * V_3 = V_14 ;
return V_3 -> V_25 ;
}
static T_12 int F_77 ( void )
{
V_22 = F_78 ( V_2 , V_94 ) ;
return 0 ;
}
