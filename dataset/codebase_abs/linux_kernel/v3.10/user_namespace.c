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
if ( F_5 () )
return - V_21 ;
if ( ! F_6 ( V_15 , V_16 ) ||
! F_7 ( V_15 , V_18 ) )
return - V_21 ;
V_14 = F_8 ( V_22 , V_23 ) ;
if ( ! V_14 )
return - V_24 ;
V_20 = F_9 ( & V_14 -> V_25 ) ;
if ( V_20 ) {
F_10 ( V_22 , V_14 ) ;
return V_20 ;
}
F_11 ( & V_14 -> V_26 , 1 ) ;
V_14 -> V_27 = V_15 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_18 = V_18 ;
F_1 ( V_13 , V_14 ) ;
F_12 ( V_14 ) ;
return 0 ;
}
int F_13 ( unsigned long V_28 , struct V_1 * * V_29 )
{
struct V_1 * V_1 ;
if ( ! ( V_28 & V_30 ) )
return 0 ;
V_1 = F_14 () ;
if ( ! V_1 )
return - V_24 ;
* V_29 = V_1 ;
return F_4 ( V_1 ) ;
}
void F_15 ( struct V_2 * V_14 )
{
struct V_2 * V_27 ;
do {
V_27 = V_14 -> V_27 ;
F_16 ( V_14 -> V_25 ) ;
F_10 ( V_22 , V_14 ) ;
V_14 = V_27 ;
} while ( F_17 ( & V_27 -> V_26 ) );
}
static T_3 F_18 ( struct V_31 * V_32 , T_3 V_33 , T_3 V_26 )
{
unsigned V_34 , V_35 ;
T_3 V_36 , V_37 , V_38 ;
V_38 = V_33 + V_26 - 1 ;
V_35 = V_32 -> V_39 ;
F_19 () ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_36 = V_32 -> V_40 [ V_34 ] . V_36 ;
V_37 = V_36 + V_32 -> V_40 [ V_34 ] . V_26 - 1 ;
if ( V_33 >= V_36 && V_33 <= V_37 &&
( V_38 >= V_36 && V_38 <= V_37 ) )
break;
}
if ( V_34 < V_35 )
V_33 = ( V_33 - V_36 ) + V_32 -> V_40 [ V_34 ] . V_41 ;
else
V_33 = ( T_3 ) - 1 ;
return V_33 ;
}
static T_3 F_20 ( struct V_31 * V_32 , T_3 V_33 )
{
unsigned V_34 , V_35 ;
T_3 V_36 , V_37 ;
V_35 = V_32 -> V_39 ;
F_19 () ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_36 = V_32 -> V_40 [ V_34 ] . V_36 ;
V_37 = V_36 + V_32 -> V_40 [ V_34 ] . V_26 - 1 ;
if ( V_33 >= V_36 && V_33 <= V_37 )
break;
}
if ( V_34 < V_35 )
V_33 = ( V_33 - V_36 ) + V_32 -> V_40 [ V_34 ] . V_41 ;
else
V_33 = ( T_3 ) - 1 ;
return V_33 ;
}
static T_3 F_21 ( struct V_31 * V_32 , T_3 V_33 )
{
unsigned V_34 , V_35 ;
T_3 V_36 , V_37 ;
V_35 = V_32 -> V_39 ;
F_19 () ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_36 = V_32 -> V_40 [ V_34 ] . V_41 ;
V_37 = V_36 + V_32 -> V_40 [ V_34 ] . V_26 - 1 ;
if ( V_33 >= V_36 && V_33 <= V_37 )
break;
}
if ( V_34 < V_35 )
V_33 = ( V_33 - V_36 ) + V_32 -> V_40 [ V_34 ] . V_36 ;
else
V_33 = ( T_3 ) - 1 ;
return V_33 ;
}
T_1 F_22 ( struct V_2 * V_14 , T_4 V_42 )
{
return F_23 ( F_20 ( & V_14 -> V_43 , V_42 ) ) ;
}
T_4 F_24 ( struct V_2 * V_44 , T_1 V_45 )
{
return F_21 ( & V_44 -> V_43 , F_25 ( V_45 ) ) ;
}
T_4 F_26 ( struct V_2 * V_44 , T_1 V_45 )
{
T_4 V_42 ;
V_42 = F_24 ( V_44 , V_45 ) ;
if ( V_42 == ( T_4 ) - 1 )
V_42 = V_46 ;
return V_42 ;
}
T_2 F_27 ( struct V_2 * V_14 , T_5 V_47 )
{
return F_28 ( F_20 ( & V_14 -> V_48 , V_47 ) ) ;
}
T_5 F_29 ( struct V_2 * V_44 , T_2 V_49 )
{
return F_21 ( & V_44 -> V_48 , F_30 ( V_49 ) ) ;
}
T_5 F_31 ( struct V_2 * V_44 , T_2 V_49 )
{
T_5 V_47 ;
V_47 = F_29 ( V_44 , V_49 ) ;
if ( V_47 == ( T_5 ) - 1 )
V_47 = V_50 ;
return V_47 ;
}
T_6 F_32 ( struct V_2 * V_14 , T_7 V_51 )
{
return F_33 ( F_20 ( & V_14 -> V_52 , V_51 ) ) ;
}
T_7 F_34 ( struct V_2 * V_44 , T_6 V_53 )
{
return F_21 ( & V_44 -> V_52 , F_35 ( V_53 ) ) ;
}
T_7 F_36 ( struct V_2 * V_44 , T_6 V_53 )
{
T_7 V_51 ;
V_51 = F_34 ( V_44 , V_53 ) ;
if ( V_51 == ( T_7 ) - 1 )
V_51 = V_54 ;
return V_51 ;
}
static int F_37 ( struct V_55 * V_56 , void * V_57 )
{
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_59 * V_40 = V_57 ;
struct V_2 * V_60 ;
T_4 V_61 ;
V_60 = F_38 ( V_56 ) ;
if ( ( V_60 == V_14 ) && V_60 -> V_27 )
V_60 = V_60 -> V_27 ;
V_61 = F_24 ( V_60 , F_23 ( V_40 -> V_41 ) ) ;
F_39 ( V_56 , L_1 ,
V_40 -> V_36 ,
V_61 ,
V_40 -> V_26 ) ;
return 0 ;
}
static int F_40 ( struct V_55 * V_56 , void * V_57 )
{
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_59 * V_40 = V_57 ;
struct V_2 * V_60 ;
T_5 V_61 ;
V_60 = F_38 ( V_56 ) ;
if ( ( V_60 == V_14 ) && V_60 -> V_27 )
V_60 = V_60 -> V_27 ;
V_61 = F_29 ( V_60 , F_28 ( V_40 -> V_41 ) ) ;
F_39 ( V_56 , L_1 ,
V_40 -> V_36 ,
V_61 ,
V_40 -> V_26 ) ;
return 0 ;
}
static int F_41 ( struct V_55 * V_56 , void * V_57 )
{
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_59 * V_40 = V_57 ;
struct V_2 * V_60 ;
T_7 V_61 ;
V_60 = F_38 ( V_56 ) ;
if ( ( V_60 == V_14 ) && V_60 -> V_27 )
V_60 = V_60 -> V_27 ;
V_61 = F_34 ( V_60 , F_33 ( V_40 -> V_41 ) ) ;
F_39 ( V_56 , L_1 ,
V_40 -> V_36 ,
V_61 ,
V_40 -> V_26 ) ;
return 0 ;
}
static void * F_42 ( struct V_55 * V_56 , T_8 * V_62 , struct V_31 * V_32 )
{
struct V_59 * V_40 = NULL ;
T_8 V_63 = * V_62 ;
if ( V_63 < V_32 -> V_39 )
V_40 = & V_32 -> V_40 [ V_63 ] ;
return V_40 ;
}
static void * F_43 ( struct V_55 * V_56 , T_8 * V_62 )
{
struct V_2 * V_14 = V_56 -> V_58 ;
return F_42 ( V_56 , V_62 , & V_14 -> V_43 ) ;
}
static void * F_44 ( struct V_55 * V_56 , T_8 * V_62 )
{
struct V_2 * V_14 = V_56 -> V_58 ;
return F_42 ( V_56 , V_62 , & V_14 -> V_48 ) ;
}
static void * F_45 ( struct V_55 * V_56 , T_8 * V_62 )
{
struct V_2 * V_14 = V_56 -> V_58 ;
return F_42 ( V_56 , V_62 , & V_14 -> V_52 ) ;
}
static void * F_46 ( struct V_55 * V_56 , void * V_57 , T_8 * V_63 )
{
( * V_63 ) ++ ;
return V_56 -> V_64 -> V_65 ( V_56 , V_63 ) ;
}
static void F_47 ( struct V_55 * V_56 , void * V_57 )
{
return;
}
static bool F_48 ( struct V_31 * V_66 , struct V_59 * V_40 )
{
T_3 V_67 , V_41 , V_68 , V_69 ;
unsigned V_34 ;
V_67 = V_40 -> V_36 ;
V_41 = V_40 -> V_41 ;
V_68 = V_67 + V_40 -> V_26 - 1 ;
V_69 = V_41 + V_40 -> V_26 - 1 ;
for ( V_34 = 0 ; V_34 < V_66 -> V_39 ; V_34 ++ ) {
T_3 V_70 , V_71 ;
T_3 V_72 , V_73 ;
struct V_59 * V_74 ;
V_74 = & V_66 -> V_40 [ V_34 ] ;
V_70 = V_74 -> V_36 ;
V_71 = V_74 -> V_41 ;
V_72 = V_70 + V_74 -> V_26 - 1 ;
V_73 = V_71 + V_74 -> V_26 - 1 ;
if ( ( V_70 <= V_68 ) &&
( V_72 >= V_67 ) )
return true ;
if ( ( V_71 <= V_69 ) &&
( V_73 >= V_41 ) )
return true ;
}
return false ;
}
static T_9 F_49 ( struct V_75 * V_75 , const char T_10 * V_76 ,
T_11 V_26 , T_8 * V_62 ,
int V_77 ,
struct V_31 * V_32 ,
struct V_31 * V_78 )
{
struct V_55 * V_56 = V_75 -> V_79 ;
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_31 V_66 ;
unsigned V_34 ;
struct V_59 * V_40 = NULL ;
unsigned long V_80 = 0 ;
char * V_81 , * V_63 , * V_82 ;
T_9 V_20 = - V_83 ;
F_50 ( & V_84 ) ;
V_20 = - V_21 ;
if ( V_32 -> V_39 != 0 )
goto V_85;
if ( F_51 ( V_77 ) && ! F_52 ( V_75 , V_14 , V_86 ) )
goto V_85;
V_20 = - V_24 ;
V_80 = F_53 ( V_87 ) ;
V_81 = ( char * ) V_80 ;
if ( ! V_80 )
goto V_85;
V_20 = - V_83 ;
if ( ( * V_62 != 0 ) || ( V_26 >= V_88 ) )
goto V_85;
V_20 = - V_89 ;
if ( F_54 ( V_81 , V_76 , V_26 ) )
goto V_85;
V_81 [ V_26 ] = '\0' ;
V_20 = - V_83 ;
V_63 = V_81 ;
V_66 . V_39 = 0 ;
for (; V_63 ; V_63 = V_82 ) {
V_40 = & V_66 . V_40 [ V_66 . V_39 ] ;
V_82 = strchr ( V_63 , '\n' ) ;
if ( V_82 ) {
* V_82 = '\0' ;
V_82 ++ ;
if ( * V_82 == '\0' )
V_82 = NULL ;
}
V_63 = F_55 ( V_63 ) ;
V_40 -> V_36 = F_56 ( V_63 , & V_63 , 10 ) ;
if ( ! isspace ( * V_63 ) )
goto V_85;
V_63 = F_55 ( V_63 ) ;
V_40 -> V_41 = F_56 ( V_63 , & V_63 , 10 ) ;
if ( ! isspace ( * V_63 ) )
goto V_85;
V_63 = F_55 ( V_63 ) ;
V_40 -> V_26 = F_56 ( V_63 , & V_63 , 10 ) ;
if ( * V_63 && ! isspace ( * V_63 ) )
goto V_85;
V_63 = F_55 ( V_63 ) ;
if ( * V_63 != '\0' )
goto V_85;
if ( ( V_40 -> V_36 == ( T_3 ) - 1 ) ||
( V_40 -> V_41 == ( T_3 ) - 1 ) )
goto V_85;
if ( ( V_40 -> V_36 + V_40 -> V_26 ) <= V_40 -> V_36 )
goto V_85;
if ( ( V_40 -> V_41 + V_40 -> V_26 ) <= V_40 -> V_41 )
goto V_85;
if ( F_48 ( & V_66 , V_40 ) )
goto V_85;
V_66 . V_39 ++ ;
if ( ( V_66 . V_39 == V_90 ) &&
( V_82 != NULL ) )
goto V_85;
}
if ( V_66 . V_39 == 0 )
goto V_85;
V_20 = - V_21 ;
if ( ! F_57 ( V_75 , V_14 , V_77 , & V_66 ) )
goto V_85;
for ( V_34 = 0 ; V_34 < V_66 . V_39 ; V_34 ++ ) {
T_3 V_41 ;
V_40 = & V_66 . V_40 [ V_34 ] ;
V_41 = F_18 ( V_78 ,
V_40 -> V_41 ,
V_40 -> V_26 ) ;
if ( V_41 == ( T_3 ) - 1 )
goto V_85;
V_40 -> V_41 = V_41 ;
}
memcpy ( V_32 -> V_40 , V_66 . V_40 ,
V_66 . V_39 * sizeof( V_66 . V_40 [ 0 ] ) ) ;
F_58 () ;
V_32 -> V_39 = V_66 . V_39 ;
* V_62 = V_26 ;
V_20 = V_26 ;
V_85:
F_59 ( & V_84 ) ;
if ( V_80 )
F_60 ( V_80 ) ;
return V_20 ;
}
T_9 F_61 ( struct V_75 * V_75 , const char T_10 * V_76 , T_11 V_91 , T_8 * V_62 )
{
struct V_55 * V_56 = V_75 -> V_79 ;
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_2 * V_92 = F_38 ( V_56 ) ;
if ( ! V_14 -> V_27 )
return - V_21 ;
if ( ( V_92 != V_14 ) && ( V_92 != V_14 -> V_27 ) )
return - V_21 ;
return F_49 ( V_75 , V_76 , V_91 , V_62 , V_93 ,
& V_14 -> V_43 , & V_14 -> V_27 -> V_43 ) ;
}
T_9 F_62 ( struct V_75 * V_75 , const char T_10 * V_76 , T_11 V_91 , T_8 * V_62 )
{
struct V_55 * V_56 = V_75 -> V_79 ;
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_2 * V_92 = F_38 ( V_56 ) ;
if ( ! V_14 -> V_27 )
return - V_21 ;
if ( ( V_92 != V_14 ) && ( V_92 != V_14 -> V_27 ) )
return - V_21 ;
return F_49 ( V_75 , V_76 , V_91 , V_62 , V_94 ,
& V_14 -> V_48 , & V_14 -> V_27 -> V_48 ) ;
}
T_9 F_63 ( struct V_75 * V_75 , const char T_10 * V_76 , T_11 V_91 , T_8 * V_62 )
{
struct V_55 * V_56 = V_75 -> V_79 ;
struct V_2 * V_14 = V_56 -> V_58 ;
struct V_2 * V_92 = F_38 ( V_56 ) ;
if ( ! V_14 -> V_27 )
return - V_21 ;
if ( ( V_92 != V_14 ) && ( V_92 != V_14 -> V_27 ) )
return - V_21 ;
return F_49 ( V_75 , V_76 , V_91 , V_62 , - 1 ,
& V_14 -> V_52 , & V_14 -> V_27 -> V_52 ) ;
}
static bool F_57 ( const struct V_75 * V_75 ,
struct V_2 * V_14 , int V_77 ,
struct V_31 * V_66 )
{
if ( ( V_66 -> V_39 == 1 ) && ( V_66 -> V_40 [ 0 ] . V_26 == 1 ) ) {
T_3 V_33 = V_66 -> V_40 [ 0 ] . V_41 ;
if ( V_77 == V_93 ) {
T_1 V_42 = F_22 ( V_14 -> V_27 , V_33 ) ;
if ( F_64 ( V_42 , V_75 -> V_95 -> V_96 ) )
return true ;
}
else if ( V_77 == V_94 ) {
T_2 V_47 = F_27 ( V_14 -> V_27 , V_33 ) ;
if ( F_65 ( V_47 , V_75 -> V_95 -> V_97 ) )
return true ;
}
}
if ( ! F_51 ( V_77 ) )
return true ;
if ( F_66 ( V_14 -> V_27 , V_77 ) &&
F_52 ( V_75 , V_14 -> V_27 , V_77 ) )
return true ;
return false ;
}
static void * F_67 ( struct V_98 * V_99 )
{
struct V_2 * V_3 ;
F_68 () ;
V_3 = F_69 ( F_70 ( V_99 ) -> V_3 ) ;
F_71 () ;
return V_3 ;
}
static void F_72 ( void * V_14 )
{
F_73 ( V_14 ) ;
}
static int F_74 ( struct V_100 * V_100 , void * V_14 )
{
struct V_2 * V_3 = V_14 ;
struct V_1 * V_1 ;
if ( V_3 == F_75 () )
return - V_83 ;
if ( F_76 ( & V_101 -> V_102 -> V_103 ) > 1 )
return - V_83 ;
if ( V_101 -> V_104 -> V_105 != 1 )
return - V_83 ;
if ( ! F_66 ( V_3 , V_86 ) )
return - V_21 ;
V_1 = F_14 () ;
if ( ! V_1 )
return - V_24 ;
F_73 ( V_1 -> V_3 ) ;
F_1 ( V_1 , F_69 ( V_3 ) ) ;
return F_77 ( V_1 ) ;
}
static unsigned int F_78 ( void * V_14 )
{
struct V_2 * V_3 = V_14 ;
return V_3 -> V_25 ;
}
static T_12 int F_79 ( void )
{
V_22 = F_80 ( V_2 , V_106 ) ;
return 0 ;
}
