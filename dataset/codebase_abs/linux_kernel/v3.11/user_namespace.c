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
F_12 ( V_14 ) ;
return 0 ;
}
int F_13 ( unsigned long V_30 , struct V_1 * * V_31 )
{
struct V_1 * V_1 ;
int V_32 = - V_26 ;
if ( ! ( V_30 & V_33 ) )
return 0 ;
V_1 = F_14 () ;
if ( V_1 ) {
V_32 = F_4 ( V_1 ) ;
if ( V_32 )
F_15 ( V_1 ) ;
else
* V_31 = V_1 ;
}
return V_32 ;
}
void F_16 ( struct V_2 * V_14 )
{
struct V_2 * V_29 ;
do {
V_29 = V_14 -> V_29 ;
F_17 ( V_14 -> V_27 ) ;
F_10 ( V_24 , V_14 ) ;
V_14 = V_29 ;
} while ( F_18 ( & V_29 -> V_28 ) );
}
static T_3 F_19 ( struct V_34 * V_35 , T_3 V_36 , T_3 V_28 )
{
unsigned V_37 , V_38 ;
T_3 V_39 , V_40 , V_41 ;
V_41 = V_36 + V_28 - 1 ;
V_38 = V_35 -> V_42 ;
F_20 () ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_39 = V_35 -> V_43 [ V_37 ] . V_39 ;
V_40 = V_39 + V_35 -> V_43 [ V_37 ] . V_28 - 1 ;
if ( V_36 >= V_39 && V_36 <= V_40 &&
( V_41 >= V_39 && V_41 <= V_40 ) )
break;
}
if ( V_37 < V_38 )
V_36 = ( V_36 - V_39 ) + V_35 -> V_43 [ V_37 ] . V_44 ;
else
V_36 = ( T_3 ) - 1 ;
return V_36 ;
}
static T_3 F_21 ( struct V_34 * V_35 , T_3 V_36 )
{
unsigned V_37 , V_38 ;
T_3 V_39 , V_40 ;
V_38 = V_35 -> V_42 ;
F_20 () ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_39 = V_35 -> V_43 [ V_37 ] . V_39 ;
V_40 = V_39 + V_35 -> V_43 [ V_37 ] . V_28 - 1 ;
if ( V_36 >= V_39 && V_36 <= V_40 )
break;
}
if ( V_37 < V_38 )
V_36 = ( V_36 - V_39 ) + V_35 -> V_43 [ V_37 ] . V_44 ;
else
V_36 = ( T_3 ) - 1 ;
return V_36 ;
}
static T_3 F_22 ( struct V_34 * V_35 , T_3 V_36 )
{
unsigned V_37 , V_38 ;
T_3 V_39 , V_40 ;
V_38 = V_35 -> V_42 ;
F_20 () ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_39 = V_35 -> V_43 [ V_37 ] . V_44 ;
V_40 = V_39 + V_35 -> V_43 [ V_37 ] . V_28 - 1 ;
if ( V_36 >= V_39 && V_36 <= V_40 )
break;
}
if ( V_37 < V_38 )
V_36 = ( V_36 - V_39 ) + V_35 -> V_43 [ V_37 ] . V_39 ;
else
V_36 = ( T_3 ) - 1 ;
return V_36 ;
}
T_1 F_23 ( struct V_2 * V_14 , T_4 V_45 )
{
return F_24 ( F_21 ( & V_14 -> V_46 , V_45 ) ) ;
}
T_4 F_25 ( struct V_2 * V_47 , T_1 V_48 )
{
return F_22 ( & V_47 -> V_46 , F_26 ( V_48 ) ) ;
}
T_4 F_27 ( struct V_2 * V_47 , T_1 V_48 )
{
T_4 V_45 ;
V_45 = F_25 ( V_47 , V_48 ) ;
if ( V_45 == ( T_4 ) - 1 )
V_45 = V_49 ;
return V_45 ;
}
T_2 F_28 ( struct V_2 * V_14 , T_5 V_50 )
{
return F_29 ( F_21 ( & V_14 -> V_51 , V_50 ) ) ;
}
T_5 F_30 ( struct V_2 * V_47 , T_2 V_52 )
{
return F_22 ( & V_47 -> V_51 , F_31 ( V_52 ) ) ;
}
T_5 F_32 ( struct V_2 * V_47 , T_2 V_52 )
{
T_5 V_50 ;
V_50 = F_30 ( V_47 , V_52 ) ;
if ( V_50 == ( T_5 ) - 1 )
V_50 = V_53 ;
return V_50 ;
}
T_6 F_33 ( struct V_2 * V_14 , T_7 V_54 )
{
return F_34 ( F_21 ( & V_14 -> V_55 , V_54 ) ) ;
}
T_7 F_35 ( struct V_2 * V_47 , T_6 V_56 )
{
return F_22 ( & V_47 -> V_55 , F_36 ( V_56 ) ) ;
}
T_7 F_37 ( struct V_2 * V_47 , T_6 V_56 )
{
T_7 V_54 ;
V_54 = F_35 ( V_47 , V_56 ) ;
if ( V_54 == ( T_7 ) - 1 )
V_54 = V_57 ;
return V_54 ;
}
static int F_38 ( struct V_58 * V_59 , void * V_60 )
{
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_62 * V_43 = V_60 ;
struct V_2 * V_63 ;
T_4 V_64 ;
V_63 = F_39 ( V_59 ) ;
if ( ( V_63 == V_14 ) && V_63 -> V_29 )
V_63 = V_63 -> V_29 ;
V_64 = F_25 ( V_63 , F_24 ( V_43 -> V_44 ) ) ;
F_40 ( V_59 , L_1 ,
V_43 -> V_39 ,
V_64 ,
V_43 -> V_28 ) ;
return 0 ;
}
static int F_41 ( struct V_58 * V_59 , void * V_60 )
{
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_62 * V_43 = V_60 ;
struct V_2 * V_63 ;
T_5 V_64 ;
V_63 = F_39 ( V_59 ) ;
if ( ( V_63 == V_14 ) && V_63 -> V_29 )
V_63 = V_63 -> V_29 ;
V_64 = F_30 ( V_63 , F_29 ( V_43 -> V_44 ) ) ;
F_40 ( V_59 , L_1 ,
V_43 -> V_39 ,
V_64 ,
V_43 -> V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_58 * V_59 , void * V_60 )
{
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_62 * V_43 = V_60 ;
struct V_2 * V_63 ;
T_7 V_64 ;
V_63 = F_39 ( V_59 ) ;
if ( ( V_63 == V_14 ) && V_63 -> V_29 )
V_63 = V_63 -> V_29 ;
V_64 = F_35 ( V_63 , F_34 ( V_43 -> V_44 ) ) ;
F_40 ( V_59 , L_1 ,
V_43 -> V_39 ,
V_64 ,
V_43 -> V_28 ) ;
return 0 ;
}
static void * F_43 ( struct V_58 * V_59 , T_8 * V_65 , struct V_34 * V_35 )
{
struct V_62 * V_43 = NULL ;
T_8 V_66 = * V_65 ;
if ( V_66 < V_35 -> V_42 )
V_43 = & V_35 -> V_43 [ V_66 ] ;
return V_43 ;
}
static void * F_44 ( struct V_58 * V_59 , T_8 * V_65 )
{
struct V_2 * V_14 = V_59 -> V_61 ;
return F_43 ( V_59 , V_65 , & V_14 -> V_46 ) ;
}
static void * F_45 ( struct V_58 * V_59 , T_8 * V_65 )
{
struct V_2 * V_14 = V_59 -> V_61 ;
return F_43 ( V_59 , V_65 , & V_14 -> V_51 ) ;
}
static void * F_46 ( struct V_58 * V_59 , T_8 * V_65 )
{
struct V_2 * V_14 = V_59 -> V_61 ;
return F_43 ( V_59 , V_65 , & V_14 -> V_55 ) ;
}
static void * F_47 ( struct V_58 * V_59 , void * V_60 , T_8 * V_66 )
{
( * V_66 ) ++ ;
return V_59 -> V_67 -> V_68 ( V_59 , V_66 ) ;
}
static void F_48 ( struct V_58 * V_59 , void * V_60 )
{
return;
}
static bool F_49 ( struct V_34 * V_69 , struct V_62 * V_43 )
{
T_3 V_70 , V_44 , V_71 , V_72 ;
unsigned V_37 ;
V_70 = V_43 -> V_39 ;
V_44 = V_43 -> V_44 ;
V_71 = V_70 + V_43 -> V_28 - 1 ;
V_72 = V_44 + V_43 -> V_28 - 1 ;
for ( V_37 = 0 ; V_37 < V_69 -> V_42 ; V_37 ++ ) {
T_3 V_73 , V_74 ;
T_3 V_75 , V_76 ;
struct V_62 * V_77 ;
V_77 = & V_69 -> V_43 [ V_37 ] ;
V_73 = V_77 -> V_39 ;
V_74 = V_77 -> V_44 ;
V_75 = V_73 + V_77 -> V_28 - 1 ;
V_76 = V_74 + V_77 -> V_28 - 1 ;
if ( ( V_73 <= V_71 ) &&
( V_75 >= V_70 ) )
return true ;
if ( ( V_74 <= V_72 ) &&
( V_76 >= V_44 ) )
return true ;
}
return false ;
}
static T_9 F_50 ( struct V_78 * V_78 , const char T_10 * V_79 ,
T_11 V_28 , T_8 * V_65 ,
int V_80 ,
struct V_34 * V_35 ,
struct V_34 * V_81 )
{
struct V_58 * V_59 = V_78 -> V_82 ;
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_34 V_69 ;
unsigned V_37 ;
struct V_62 * V_43 = NULL ;
unsigned long V_83 = 0 ;
char * V_84 , * V_66 , * V_85 ;
T_9 V_20 = - V_86 ;
F_51 ( & V_87 ) ;
V_20 = - V_23 ;
if ( V_35 -> V_42 != 0 )
goto V_88;
if ( F_52 ( V_80 ) && ! F_53 ( V_78 , V_14 , V_89 ) )
goto V_88;
V_20 = - V_26 ;
V_83 = F_54 ( V_90 ) ;
V_84 = ( char * ) V_83 ;
if ( ! V_83 )
goto V_88;
V_20 = - V_86 ;
if ( ( * V_65 != 0 ) || ( V_28 >= V_91 ) )
goto V_88;
V_20 = - V_92 ;
if ( F_55 ( V_84 , V_79 , V_28 ) )
goto V_88;
V_84 [ V_28 ] = '\0' ;
V_20 = - V_86 ;
V_66 = V_84 ;
V_69 . V_42 = 0 ;
for (; V_66 ; V_66 = V_85 ) {
V_43 = & V_69 . V_43 [ V_69 . V_42 ] ;
V_85 = strchr ( V_66 , '\n' ) ;
if ( V_85 ) {
* V_85 = '\0' ;
V_85 ++ ;
if ( * V_85 == '\0' )
V_85 = NULL ;
}
V_66 = F_56 ( V_66 ) ;
V_43 -> V_39 = F_57 ( V_66 , & V_66 , 10 ) ;
if ( ! isspace ( * V_66 ) )
goto V_88;
V_66 = F_56 ( V_66 ) ;
V_43 -> V_44 = F_57 ( V_66 , & V_66 , 10 ) ;
if ( ! isspace ( * V_66 ) )
goto V_88;
V_66 = F_56 ( V_66 ) ;
V_43 -> V_28 = F_57 ( V_66 , & V_66 , 10 ) ;
if ( * V_66 && ! isspace ( * V_66 ) )
goto V_88;
V_66 = F_56 ( V_66 ) ;
if ( * V_66 != '\0' )
goto V_88;
if ( ( V_43 -> V_39 == ( T_3 ) - 1 ) ||
( V_43 -> V_44 == ( T_3 ) - 1 ) )
goto V_88;
if ( ( V_43 -> V_39 + V_43 -> V_28 ) <= V_43 -> V_39 )
goto V_88;
if ( ( V_43 -> V_44 + V_43 -> V_28 ) <= V_43 -> V_44 )
goto V_88;
if ( F_49 ( & V_69 , V_43 ) )
goto V_88;
V_69 . V_42 ++ ;
if ( ( V_69 . V_42 == V_93 ) &&
( V_85 != NULL ) )
goto V_88;
}
if ( V_69 . V_42 == 0 )
goto V_88;
V_20 = - V_23 ;
if ( ! F_58 ( V_78 , V_14 , V_80 , & V_69 ) )
goto V_88;
for ( V_37 = 0 ; V_37 < V_69 . V_42 ; V_37 ++ ) {
T_3 V_44 ;
V_43 = & V_69 . V_43 [ V_37 ] ;
V_44 = F_19 ( V_81 ,
V_43 -> V_44 ,
V_43 -> V_28 ) ;
if ( V_44 == ( T_3 ) - 1 )
goto V_88;
V_43 -> V_44 = V_44 ;
}
memcpy ( V_35 -> V_43 , V_69 . V_43 ,
V_69 . V_42 * sizeof( V_69 . V_43 [ 0 ] ) ) ;
F_59 () ;
V_35 -> V_42 = V_69 . V_42 ;
* V_65 = V_28 ;
V_20 = V_28 ;
V_88:
F_60 ( & V_87 ) ;
if ( V_83 )
F_61 ( V_83 ) ;
return V_20 ;
}
T_9 F_62 ( struct V_78 * V_78 , const char T_10 * V_79 , T_11 V_94 , T_8 * V_65 )
{
struct V_58 * V_59 = V_78 -> V_82 ;
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_2 * V_95 = F_39 ( V_59 ) ;
if ( ! V_14 -> V_29 )
return - V_23 ;
if ( ( V_95 != V_14 ) && ( V_95 != V_14 -> V_29 ) )
return - V_23 ;
return F_50 ( V_78 , V_79 , V_94 , V_65 , V_96 ,
& V_14 -> V_46 , & V_14 -> V_29 -> V_46 ) ;
}
T_9 F_63 ( struct V_78 * V_78 , const char T_10 * V_79 , T_11 V_94 , T_8 * V_65 )
{
struct V_58 * V_59 = V_78 -> V_82 ;
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_2 * V_95 = F_39 ( V_59 ) ;
if ( ! V_14 -> V_29 )
return - V_23 ;
if ( ( V_95 != V_14 ) && ( V_95 != V_14 -> V_29 ) )
return - V_23 ;
return F_50 ( V_78 , V_79 , V_94 , V_65 , V_97 ,
& V_14 -> V_51 , & V_14 -> V_29 -> V_51 ) ;
}
T_9 F_64 ( struct V_78 * V_78 , const char T_10 * V_79 , T_11 V_94 , T_8 * V_65 )
{
struct V_58 * V_59 = V_78 -> V_82 ;
struct V_2 * V_14 = V_59 -> V_61 ;
struct V_2 * V_95 = F_39 ( V_59 ) ;
if ( ! V_14 -> V_29 )
return - V_23 ;
if ( ( V_95 != V_14 ) && ( V_95 != V_14 -> V_29 ) )
return - V_23 ;
return F_50 ( V_78 , V_79 , V_94 , V_65 , - 1 ,
& V_14 -> V_55 , & V_14 -> V_29 -> V_55 ) ;
}
static bool F_58 ( const struct V_78 * V_78 ,
struct V_2 * V_14 , int V_80 ,
struct V_34 * V_69 )
{
if ( ( V_69 -> V_42 == 1 ) && ( V_69 -> V_43 [ 0 ] . V_28 == 1 ) ) {
T_3 V_36 = V_69 -> V_43 [ 0 ] . V_44 ;
if ( V_80 == V_96 ) {
T_1 V_45 = F_23 ( V_14 -> V_29 , V_36 ) ;
if ( F_65 ( V_45 , V_78 -> V_98 -> V_99 ) )
return true ;
}
else if ( V_80 == V_97 ) {
T_2 V_50 = F_28 ( V_14 -> V_29 , V_36 ) ;
if ( F_66 ( V_50 , V_78 -> V_98 -> V_100 ) )
return true ;
}
}
if ( ! F_52 ( V_80 ) )
return true ;
if ( F_67 ( V_14 -> V_29 , V_80 ) &&
F_53 ( V_78 , V_14 -> V_29 , V_80 ) )
return true ;
return false ;
}
static void * F_68 ( struct V_101 * V_102 )
{
struct V_2 * V_3 ;
F_69 () ;
V_3 = F_70 ( F_71 ( V_102 ) -> V_3 ) ;
F_72 () ;
return V_3 ;
}
static void F_73 ( void * V_14 )
{
F_74 ( V_14 ) ;
}
static int F_75 ( struct V_103 * V_103 , void * V_14 )
{
struct V_2 * V_3 = V_14 ;
struct V_1 * V_1 ;
if ( V_3 == F_76 () )
return - V_86 ;
if ( F_77 ( & V_104 -> V_105 -> V_106 ) > 1 )
return - V_86 ;
if ( V_104 -> V_107 -> V_108 != 1 )
return - V_86 ;
if ( ! F_67 ( V_3 , V_89 ) )
return - V_23 ;
V_1 = F_14 () ;
if ( ! V_1 )
return - V_26 ;
F_74 ( V_1 -> V_3 ) ;
F_1 ( V_1 , F_70 ( V_3 ) ) ;
return F_78 ( V_1 ) ;
}
static unsigned int F_79 ( void * V_14 )
{
struct V_2 * V_3 = V_14 ;
return V_3 -> V_27 ;
}
static T_12 int F_80 ( void )
{
V_24 = F_81 ( V_2 , V_109 ) ;
return 0 ;
}
