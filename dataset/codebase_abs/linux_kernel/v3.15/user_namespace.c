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
if ( V_15 -> V_21 > 32 )
return - V_22 ;
if ( F_5 () )
return - V_23 ;
if ( ! F_6 ( V_15 , V_16 ) ||
! F_7 ( V_15 , V_18 ) )
return - V_23 ;
V_14 = F_8 ( V_24 , V_25 ) ;
if ( ! V_14 )
return - V_26 ;
V_20 = F_9 ( & V_14 -> V_27 ) ;
if ( V_20 ) {
F_10 ( V_24 , V_14 ) ;
return V_20 ;
}
F_11 ( & V_14 -> V_28 , 1 ) ;
V_14 -> V_29 = V_15 ;
V_14 -> V_21 = V_15 -> V_21 + 1 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_18 = V_18 ;
F_1 ( V_13 , V_14 ) ;
#ifdef F_12
F_13 ( & V_14 -> V_30 ) ;
#endif
return 0 ;
}
int F_14 ( unsigned long V_31 , struct V_1 * * V_32 )
{
struct V_1 * V_1 ;
int V_33 = - V_26 ;
if ( ! ( V_31 & V_34 ) )
return 0 ;
V_1 = F_15 () ;
if ( V_1 ) {
V_33 = F_4 ( V_1 ) ;
if ( V_33 )
F_16 ( V_1 ) ;
else
* V_32 = V_1 ;
}
return V_33 ;
}
void F_17 ( struct V_2 * V_14 )
{
struct V_2 * V_29 ;
do {
V_29 = V_14 -> V_29 ;
#ifdef F_12
F_3 ( V_14 -> V_35 ) ;
#endif
F_18 ( V_14 -> V_27 ) ;
F_10 ( V_24 , V_14 ) ;
V_14 = V_29 ;
} while ( F_19 ( & V_29 -> V_28 ) );
}
static T_3 F_20 ( struct V_36 * V_37 , T_3 V_38 , T_3 V_28 )
{
unsigned V_39 , V_40 ;
T_3 V_41 , V_42 , V_43 ;
V_43 = V_38 + V_28 - 1 ;
V_40 = V_37 -> V_44 ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_41 = V_37 -> V_45 [ V_39 ] . V_41 ;
V_42 = V_41 + V_37 -> V_45 [ V_39 ] . V_28 - 1 ;
if ( V_38 >= V_41 && V_38 <= V_42 &&
( V_43 >= V_41 && V_43 <= V_42 ) )
break;
}
if ( V_39 < V_40 )
V_38 = ( V_38 - V_41 ) + V_37 -> V_45 [ V_39 ] . V_46 ;
else
V_38 = ( T_3 ) - 1 ;
return V_38 ;
}
static T_3 F_22 ( struct V_36 * V_37 , T_3 V_38 )
{
unsigned V_39 , V_40 ;
T_3 V_41 , V_42 ;
V_40 = V_37 -> V_44 ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_41 = V_37 -> V_45 [ V_39 ] . V_41 ;
V_42 = V_41 + V_37 -> V_45 [ V_39 ] . V_28 - 1 ;
if ( V_38 >= V_41 && V_38 <= V_42 )
break;
}
if ( V_39 < V_40 )
V_38 = ( V_38 - V_41 ) + V_37 -> V_45 [ V_39 ] . V_46 ;
else
V_38 = ( T_3 ) - 1 ;
return V_38 ;
}
static T_3 F_23 ( struct V_36 * V_37 , T_3 V_38 )
{
unsigned V_39 , V_40 ;
T_3 V_41 , V_42 ;
V_40 = V_37 -> V_44 ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_41 = V_37 -> V_45 [ V_39 ] . V_46 ;
V_42 = V_41 + V_37 -> V_45 [ V_39 ] . V_28 - 1 ;
if ( V_38 >= V_41 && V_38 <= V_42 )
break;
}
if ( V_39 < V_40 )
V_38 = ( V_38 - V_41 ) + V_37 -> V_45 [ V_39 ] . V_41 ;
else
V_38 = ( T_3 ) - 1 ;
return V_38 ;
}
T_1 F_24 ( struct V_2 * V_14 , T_4 V_47 )
{
return F_25 ( F_22 ( & V_14 -> V_48 , V_47 ) ) ;
}
T_4 F_26 ( struct V_2 * V_49 , T_1 V_50 )
{
return F_23 ( & V_49 -> V_48 , F_27 ( V_50 ) ) ;
}
T_4 F_28 ( struct V_2 * V_49 , T_1 V_50 )
{
T_4 V_47 ;
V_47 = F_26 ( V_49 , V_50 ) ;
if ( V_47 == ( T_4 ) - 1 )
V_47 = V_51 ;
return V_47 ;
}
T_2 F_29 ( struct V_2 * V_14 , T_5 V_52 )
{
return F_30 ( F_22 ( & V_14 -> V_53 , V_52 ) ) ;
}
T_5 F_31 ( struct V_2 * V_49 , T_2 V_54 )
{
return F_23 ( & V_49 -> V_53 , F_32 ( V_54 ) ) ;
}
T_5 F_33 ( struct V_2 * V_49 , T_2 V_54 )
{
T_5 V_52 ;
V_52 = F_31 ( V_49 , V_54 ) ;
if ( V_52 == ( T_5 ) - 1 )
V_52 = V_55 ;
return V_52 ;
}
T_6 F_34 ( struct V_2 * V_14 , T_7 V_56 )
{
return F_35 ( F_22 ( & V_14 -> V_57 , V_56 ) ) ;
}
T_7 F_36 ( struct V_2 * V_49 , T_6 V_58 )
{
return F_23 ( & V_49 -> V_57 , F_37 ( V_58 ) ) ;
}
T_7 F_38 ( struct V_2 * V_49 , T_6 V_58 )
{
T_7 V_56 ;
V_56 = F_36 ( V_49 , V_58 ) ;
if ( V_56 == ( T_7 ) - 1 )
V_56 = V_59 ;
return V_56 ;
}
static int F_39 ( struct V_60 * V_61 , void * V_62 )
{
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_64 * V_45 = V_62 ;
struct V_2 * V_65 ;
T_4 V_66 ;
V_65 = F_40 ( V_61 ) ;
if ( ( V_65 == V_14 ) && V_65 -> V_29 )
V_65 = V_65 -> V_29 ;
V_66 = F_26 ( V_65 , F_25 ( V_45 -> V_46 ) ) ;
F_41 ( V_61 , L_1 ,
V_45 -> V_41 ,
V_66 ,
V_45 -> V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_60 * V_61 , void * V_62 )
{
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_64 * V_45 = V_62 ;
struct V_2 * V_65 ;
T_5 V_66 ;
V_65 = F_40 ( V_61 ) ;
if ( ( V_65 == V_14 ) && V_65 -> V_29 )
V_65 = V_65 -> V_29 ;
V_66 = F_31 ( V_65 , F_30 ( V_45 -> V_46 ) ) ;
F_41 ( V_61 , L_1 ,
V_45 -> V_41 ,
V_66 ,
V_45 -> V_28 ) ;
return 0 ;
}
static int F_43 ( struct V_60 * V_61 , void * V_62 )
{
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_64 * V_45 = V_62 ;
struct V_2 * V_65 ;
T_7 V_66 ;
V_65 = F_40 ( V_61 ) ;
if ( ( V_65 == V_14 ) && V_65 -> V_29 )
V_65 = V_65 -> V_29 ;
V_66 = F_36 ( V_65 , F_35 ( V_45 -> V_46 ) ) ;
F_41 ( V_61 , L_1 ,
V_45 -> V_41 ,
V_66 ,
V_45 -> V_28 ) ;
return 0 ;
}
static void * F_44 ( struct V_60 * V_61 , T_8 * V_67 , struct V_36 * V_37 )
{
struct V_64 * V_45 = NULL ;
T_8 V_68 = * V_67 ;
if ( V_68 < V_37 -> V_44 )
V_45 = & V_37 -> V_45 [ V_68 ] ;
return V_45 ;
}
static void * F_45 ( struct V_60 * V_61 , T_8 * V_67 )
{
struct V_2 * V_14 = V_61 -> V_63 ;
return F_44 ( V_61 , V_67 , & V_14 -> V_48 ) ;
}
static void * F_46 ( struct V_60 * V_61 , T_8 * V_67 )
{
struct V_2 * V_14 = V_61 -> V_63 ;
return F_44 ( V_61 , V_67 , & V_14 -> V_53 ) ;
}
static void * F_47 ( struct V_60 * V_61 , T_8 * V_67 )
{
struct V_2 * V_14 = V_61 -> V_63 ;
return F_44 ( V_61 , V_67 , & V_14 -> V_57 ) ;
}
static void * F_48 ( struct V_60 * V_61 , void * V_62 , T_8 * V_68 )
{
( * V_68 ) ++ ;
return V_61 -> V_69 -> V_70 ( V_61 , V_68 ) ;
}
static void F_49 ( struct V_60 * V_61 , void * V_62 )
{
return;
}
static bool F_50 ( struct V_36 * V_71 , struct V_64 * V_45 )
{
T_3 V_72 , V_46 , V_73 , V_74 ;
unsigned V_39 ;
V_72 = V_45 -> V_41 ;
V_46 = V_45 -> V_46 ;
V_73 = V_72 + V_45 -> V_28 - 1 ;
V_74 = V_46 + V_45 -> V_28 - 1 ;
for ( V_39 = 0 ; V_39 < V_71 -> V_44 ; V_39 ++ ) {
T_3 V_75 , V_76 ;
T_3 V_77 , V_78 ;
struct V_64 * V_79 ;
V_79 = & V_71 -> V_45 [ V_39 ] ;
V_75 = V_79 -> V_41 ;
V_76 = V_79 -> V_46 ;
V_77 = V_75 + V_79 -> V_28 - 1 ;
V_78 = V_76 + V_79 -> V_28 - 1 ;
if ( ( V_75 <= V_73 ) &&
( V_77 >= V_72 ) )
return true ;
if ( ( V_76 <= V_74 ) &&
( V_78 >= V_46 ) )
return true ;
}
return false ;
}
static T_9 F_51 ( struct V_80 * V_80 , const char T_10 * V_81 ,
T_11 V_28 , T_8 * V_67 ,
int V_82 ,
struct V_36 * V_37 ,
struct V_36 * V_83 )
{
struct V_60 * V_61 = V_80 -> V_84 ;
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_36 V_71 ;
unsigned V_39 ;
struct V_64 * V_45 = NULL ;
unsigned long V_85 = 0 ;
char * V_86 , * V_68 , * V_87 ;
T_9 V_20 = - V_88 ;
F_52 ( & V_89 ) ;
V_20 = - V_23 ;
if ( V_37 -> V_44 != 0 )
goto V_90;
if ( F_53 ( V_82 ) && ! F_54 ( V_80 , V_14 , V_91 ) )
goto V_90;
V_20 = - V_26 ;
V_85 = F_55 ( V_92 ) ;
V_86 = ( char * ) V_85 ;
if ( ! V_85 )
goto V_90;
V_20 = - V_88 ;
if ( ( * V_67 != 0 ) || ( V_28 >= V_93 ) )
goto V_90;
V_20 = - V_94 ;
if ( F_56 ( V_86 , V_81 , V_28 ) )
goto V_90;
V_86 [ V_28 ] = '\0' ;
V_20 = - V_88 ;
V_68 = V_86 ;
V_71 . V_44 = 0 ;
for (; V_68 ; V_68 = V_87 ) {
V_45 = & V_71 . V_45 [ V_71 . V_44 ] ;
V_87 = strchr ( V_68 , '\n' ) ;
if ( V_87 ) {
* V_87 = '\0' ;
V_87 ++ ;
if ( * V_87 == '\0' )
V_87 = NULL ;
}
V_68 = F_57 ( V_68 ) ;
V_45 -> V_41 = F_58 ( V_68 , & V_68 , 10 ) ;
if ( ! isspace ( * V_68 ) )
goto V_90;
V_68 = F_57 ( V_68 ) ;
V_45 -> V_46 = F_58 ( V_68 , & V_68 , 10 ) ;
if ( ! isspace ( * V_68 ) )
goto V_90;
V_68 = F_57 ( V_68 ) ;
V_45 -> V_28 = F_58 ( V_68 , & V_68 , 10 ) ;
if ( * V_68 && ! isspace ( * V_68 ) )
goto V_90;
V_68 = F_57 ( V_68 ) ;
if ( * V_68 != '\0' )
goto V_90;
if ( ( V_45 -> V_41 == ( T_3 ) - 1 ) ||
( V_45 -> V_46 == ( T_3 ) - 1 ) )
goto V_90;
if ( ( V_45 -> V_41 + V_45 -> V_28 ) <= V_45 -> V_41 )
goto V_90;
if ( ( V_45 -> V_46 + V_45 -> V_28 ) <= V_45 -> V_46 )
goto V_90;
if ( F_50 ( & V_71 , V_45 ) )
goto V_90;
V_71 . V_44 ++ ;
if ( ( V_71 . V_44 == V_95 ) &&
( V_87 != NULL ) )
goto V_90;
}
if ( V_71 . V_44 == 0 )
goto V_90;
V_20 = - V_23 ;
if ( ! F_59 ( V_80 , V_14 , V_82 , & V_71 ) )
goto V_90;
for ( V_39 = 0 ; V_39 < V_71 . V_44 ; V_39 ++ ) {
T_3 V_46 ;
V_45 = & V_71 . V_45 [ V_39 ] ;
V_46 = F_20 ( V_83 ,
V_45 -> V_46 ,
V_45 -> V_28 ) ;
if ( V_46 == ( T_3 ) - 1 )
goto V_90;
V_45 -> V_46 = V_46 ;
}
memcpy ( V_37 -> V_45 , V_71 . V_45 ,
V_71 . V_44 * sizeof( V_71 . V_45 [ 0 ] ) ) ;
F_60 () ;
V_37 -> V_44 = V_71 . V_44 ;
* V_67 = V_28 ;
V_20 = V_28 ;
V_90:
F_61 ( & V_89 ) ;
if ( V_85 )
F_62 ( V_85 ) ;
return V_20 ;
}
T_9 F_63 ( struct V_80 * V_80 , const char T_10 * V_81 , T_11 V_96 , T_8 * V_67 )
{
struct V_60 * V_61 = V_80 -> V_84 ;
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_2 * V_97 = F_40 ( V_61 ) ;
if ( ! V_14 -> V_29 )
return - V_23 ;
if ( ( V_97 != V_14 ) && ( V_97 != V_14 -> V_29 ) )
return - V_23 ;
return F_51 ( V_80 , V_81 , V_96 , V_67 , V_98 ,
& V_14 -> V_48 , & V_14 -> V_29 -> V_48 ) ;
}
T_9 F_64 ( struct V_80 * V_80 , const char T_10 * V_81 , T_11 V_96 , T_8 * V_67 )
{
struct V_60 * V_61 = V_80 -> V_84 ;
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_2 * V_97 = F_40 ( V_61 ) ;
if ( ! V_14 -> V_29 )
return - V_23 ;
if ( ( V_97 != V_14 ) && ( V_97 != V_14 -> V_29 ) )
return - V_23 ;
return F_51 ( V_80 , V_81 , V_96 , V_67 , V_99 ,
& V_14 -> V_53 , & V_14 -> V_29 -> V_53 ) ;
}
T_9 F_65 ( struct V_80 * V_80 , const char T_10 * V_81 , T_11 V_96 , T_8 * V_67 )
{
struct V_60 * V_61 = V_80 -> V_84 ;
struct V_2 * V_14 = V_61 -> V_63 ;
struct V_2 * V_97 = F_40 ( V_61 ) ;
if ( ! V_14 -> V_29 )
return - V_23 ;
if ( ( V_97 != V_14 ) && ( V_97 != V_14 -> V_29 ) )
return - V_23 ;
return F_51 ( V_80 , V_81 , V_96 , V_67 , - 1 ,
& V_14 -> V_57 , & V_14 -> V_29 -> V_57 ) ;
}
static bool F_59 ( const struct V_80 * V_80 ,
struct V_2 * V_14 , int V_82 ,
struct V_36 * V_71 )
{
if ( ( V_71 -> V_44 == 1 ) && ( V_71 -> V_45 [ 0 ] . V_28 == 1 ) ) {
T_3 V_38 = V_71 -> V_45 [ 0 ] . V_46 ;
if ( V_82 == V_98 ) {
T_1 V_47 = F_24 ( V_14 -> V_29 , V_38 ) ;
if ( F_66 ( V_47 , V_80 -> V_100 -> V_101 ) )
return true ;
}
else if ( V_82 == V_99 ) {
T_2 V_52 = F_29 ( V_14 -> V_29 , V_38 ) ;
if ( F_67 ( V_52 , V_80 -> V_100 -> V_102 ) )
return true ;
}
}
if ( ! F_53 ( V_82 ) )
return true ;
if ( F_68 ( V_14 -> V_29 , V_82 ) &&
F_54 ( V_80 , V_14 -> V_29 , V_82 ) )
return true ;
return false ;
}
static void * F_69 ( struct V_103 * V_104 )
{
struct V_2 * V_3 ;
F_70 () ;
V_3 = F_71 ( F_72 ( V_104 ) -> V_3 ) ;
F_73 () ;
return V_3 ;
}
static void F_74 ( void * V_14 )
{
F_75 ( V_14 ) ;
}
static int F_76 ( struct V_105 * V_105 , void * V_14 )
{
struct V_2 * V_3 = V_14 ;
struct V_1 * V_1 ;
if ( V_3 == F_77 () )
return - V_88 ;
if ( F_78 ( & V_106 -> V_107 -> V_108 ) > 1 )
return - V_88 ;
if ( V_106 -> V_109 -> V_110 != 1 )
return - V_88 ;
if ( ! F_68 ( V_3 , V_91 ) )
return - V_23 ;
V_1 = F_15 () ;
if ( ! V_1 )
return - V_26 ;
F_75 ( V_1 -> V_3 ) ;
F_1 ( V_1 , F_71 ( V_3 ) ) ;
return F_79 ( V_1 ) ;
}
static unsigned int F_80 ( void * V_14 )
{
struct V_2 * V_3 = V_14 ;
return V_3 -> V_27 ;
}
static T_12 int F_81 ( void )
{
V_24 = F_82 ( V_2 , V_111 ) ;
return 0 ;
}
