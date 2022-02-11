static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_1 -> V_4 = V_5 ;
V_1 -> V_6 = V_7 ;
V_1 -> V_8 = V_9 ;
V_1 -> V_10 = V_9 ;
V_1 -> V_11 = V_7 ;
V_1 -> V_12 = V_9 ;
#ifdef F_2
F_3 ( V_1 -> V_13 ) ;
V_1 -> V_13 = NULL ;
#endif
V_1 -> V_3 = V_3 ;
}
int F_4 ( struct V_1 * V_14 )
{
struct V_2 * V_15 , * V_16 = V_14 -> V_3 ;
T_1 V_17 = V_14 -> V_18 ;
T_2 V_19 = V_14 -> V_20 ;
int V_21 ;
if ( V_16 -> V_22 > 32 )
return - V_23 ;
if ( F_5 () )
return - V_24 ;
if ( ! F_6 ( V_16 , V_17 ) ||
! F_7 ( V_16 , V_19 ) )
return - V_24 ;
V_15 = F_8 ( V_25 , V_26 ) ;
if ( ! V_15 )
return - V_27 ;
V_21 = F_9 ( & V_15 -> V_15 ) ;
if ( V_21 ) {
F_10 ( V_25 , V_15 ) ;
return V_21 ;
}
V_15 -> V_15 . V_28 = & V_29 ;
F_11 ( & V_15 -> V_30 , 1 ) ;
V_15 -> V_31 = V_16 ;
V_15 -> V_22 = V_16 -> V_22 + 1 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_19 = V_19 ;
F_12 ( & V_32 ) ;
V_15 -> V_33 = V_16 -> V_33 ;
F_13 ( & V_32 ) ;
F_1 ( V_14 , V_15 ) ;
#ifdef F_14
F_15 ( & V_15 -> V_34 ) ;
#endif
return 0 ;
}
int F_16 ( unsigned long V_35 , struct V_1 * * V_36 )
{
struct V_1 * V_1 ;
int V_37 = - V_27 ;
if ( ! ( V_35 & V_38 ) )
return 0 ;
V_1 = F_17 () ;
if ( V_1 ) {
V_37 = F_4 ( V_1 ) ;
if ( V_37 )
F_18 ( V_1 ) ;
else
* V_36 = V_1 ;
}
return V_37 ;
}
void F_19 ( struct V_2 * V_15 )
{
struct V_2 * V_31 ;
do {
V_31 = V_15 -> V_31 ;
#ifdef F_14
F_3 ( V_15 -> V_39 ) ;
#endif
F_20 ( & V_15 -> V_15 ) ;
F_10 ( V_25 , V_15 ) ;
V_15 = V_31 ;
} while ( F_21 ( & V_31 -> V_30 ) );
}
static T_3 F_22 ( struct V_40 * V_41 , T_3 V_42 , T_3 V_30 )
{
unsigned V_43 , V_44 ;
T_3 V_45 , V_46 , V_47 ;
V_47 = V_42 + V_30 - 1 ;
V_44 = V_41 -> V_48 ;
F_23 () ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_45 = V_41 -> V_49 [ V_43 ] . V_45 ;
V_46 = V_45 + V_41 -> V_49 [ V_43 ] . V_30 - 1 ;
if ( V_42 >= V_45 && V_42 <= V_46 &&
( V_47 >= V_45 && V_47 <= V_46 ) )
break;
}
if ( V_43 < V_44 )
V_42 = ( V_42 - V_45 ) + V_41 -> V_49 [ V_43 ] . V_50 ;
else
V_42 = ( T_3 ) - 1 ;
return V_42 ;
}
static T_3 F_24 ( struct V_40 * V_41 , T_3 V_42 )
{
unsigned V_43 , V_44 ;
T_3 V_45 , V_46 ;
V_44 = V_41 -> V_48 ;
F_23 () ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_45 = V_41 -> V_49 [ V_43 ] . V_45 ;
V_46 = V_45 + V_41 -> V_49 [ V_43 ] . V_30 - 1 ;
if ( V_42 >= V_45 && V_42 <= V_46 )
break;
}
if ( V_43 < V_44 )
V_42 = ( V_42 - V_45 ) + V_41 -> V_49 [ V_43 ] . V_50 ;
else
V_42 = ( T_3 ) - 1 ;
return V_42 ;
}
static T_3 F_25 ( struct V_40 * V_41 , T_3 V_42 )
{
unsigned V_43 , V_44 ;
T_3 V_45 , V_46 ;
V_44 = V_41 -> V_48 ;
F_23 () ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_45 = V_41 -> V_49 [ V_43 ] . V_50 ;
V_46 = V_45 + V_41 -> V_49 [ V_43 ] . V_30 - 1 ;
if ( V_42 >= V_45 && V_42 <= V_46 )
break;
}
if ( V_43 < V_44 )
V_42 = ( V_42 - V_45 ) + V_41 -> V_49 [ V_43 ] . V_45 ;
else
V_42 = ( T_3 ) - 1 ;
return V_42 ;
}
T_1 F_26 ( struct V_2 * V_15 , T_4 V_51 )
{
return F_27 ( F_24 ( & V_15 -> V_52 , V_51 ) ) ;
}
T_4 F_28 ( struct V_2 * V_53 , T_1 V_54 )
{
return F_25 ( & V_53 -> V_52 , F_29 ( V_54 ) ) ;
}
T_4 F_30 ( struct V_2 * V_53 , T_1 V_54 )
{
T_4 V_51 ;
V_51 = F_28 ( V_53 , V_54 ) ;
if ( V_51 == ( T_4 ) - 1 )
V_51 = V_55 ;
return V_51 ;
}
T_2 F_31 ( struct V_2 * V_15 , T_5 V_56 )
{
return F_32 ( F_24 ( & V_15 -> V_57 , V_56 ) ) ;
}
T_5 F_33 ( struct V_2 * V_53 , T_2 V_58 )
{
return F_25 ( & V_53 -> V_57 , F_34 ( V_58 ) ) ;
}
T_5 F_35 ( struct V_2 * V_53 , T_2 V_58 )
{
T_5 V_56 ;
V_56 = F_33 ( V_53 , V_58 ) ;
if ( V_56 == ( T_5 ) - 1 )
V_56 = V_59 ;
return V_56 ;
}
T_6 F_36 ( struct V_2 * V_15 , T_7 V_60 )
{
return F_37 ( F_24 ( & V_15 -> V_61 , V_60 ) ) ;
}
T_7 F_38 ( struct V_2 * V_53 , T_6 V_62 )
{
return F_25 ( & V_53 -> V_61 , F_39 ( V_62 ) ) ;
}
T_7 F_40 ( struct V_2 * V_53 , T_6 V_62 )
{
T_7 V_60 ;
V_60 = F_38 ( V_53 , V_62 ) ;
if ( V_60 == ( T_7 ) - 1 )
V_60 = V_63 ;
return V_60 ;
}
static int F_41 ( struct V_64 * V_65 , void * V_66 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_68 * V_49 = V_66 ;
struct V_2 * V_69 ;
T_4 V_70 ;
V_69 = F_42 ( V_65 ) ;
if ( ( V_69 == V_15 ) && V_69 -> V_31 )
V_69 = V_69 -> V_31 ;
V_70 = F_28 ( V_69 , F_27 ( V_49 -> V_50 ) ) ;
F_43 ( V_65 , L_1 ,
V_49 -> V_45 ,
V_70 ,
V_49 -> V_30 ) ;
return 0 ;
}
static int F_44 ( struct V_64 * V_65 , void * V_66 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_68 * V_49 = V_66 ;
struct V_2 * V_69 ;
T_5 V_70 ;
V_69 = F_42 ( V_65 ) ;
if ( ( V_69 == V_15 ) && V_69 -> V_31 )
V_69 = V_69 -> V_31 ;
V_70 = F_33 ( V_69 , F_32 ( V_49 -> V_50 ) ) ;
F_43 ( V_65 , L_1 ,
V_49 -> V_45 ,
V_70 ,
V_49 -> V_30 ) ;
return 0 ;
}
static int F_45 ( struct V_64 * V_65 , void * V_66 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_68 * V_49 = V_66 ;
struct V_2 * V_69 ;
T_7 V_70 ;
V_69 = F_42 ( V_65 ) ;
if ( ( V_69 == V_15 ) && V_69 -> V_31 )
V_69 = V_69 -> V_31 ;
V_70 = F_38 ( V_69 , F_37 ( V_49 -> V_50 ) ) ;
F_43 ( V_65 , L_1 ,
V_49 -> V_45 ,
V_70 ,
V_49 -> V_30 ) ;
return 0 ;
}
static void * F_46 ( struct V_64 * V_65 , T_8 * V_71 ,
struct V_40 * V_41 )
{
struct V_68 * V_49 = NULL ;
T_8 V_72 = * V_71 ;
if ( V_72 < V_41 -> V_48 )
V_49 = & V_41 -> V_49 [ V_72 ] ;
return V_49 ;
}
static void * F_47 ( struct V_64 * V_65 , T_8 * V_71 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
return F_46 ( V_65 , V_71 , & V_15 -> V_52 ) ;
}
static void * F_48 ( struct V_64 * V_65 , T_8 * V_71 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
return F_46 ( V_65 , V_71 , & V_15 -> V_57 ) ;
}
static void * F_49 ( struct V_64 * V_65 , T_8 * V_71 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
return F_46 ( V_65 , V_71 , & V_15 -> V_61 ) ;
}
static void * F_50 ( struct V_64 * V_65 , void * V_66 , T_8 * V_72 )
{
( * V_72 ) ++ ;
return V_65 -> V_73 -> V_74 ( V_65 , V_72 ) ;
}
static void F_51 ( struct V_64 * V_65 , void * V_66 )
{
return;
}
static bool F_52 ( struct V_40 * V_75 ,
struct V_68 * V_49 )
{
T_3 V_76 , V_50 , V_77 , V_78 ;
unsigned V_43 ;
V_76 = V_49 -> V_45 ;
V_50 = V_49 -> V_50 ;
V_77 = V_76 + V_49 -> V_30 - 1 ;
V_78 = V_50 + V_49 -> V_30 - 1 ;
for ( V_43 = 0 ; V_43 < V_75 -> V_48 ; V_43 ++ ) {
T_3 V_79 , V_80 ;
T_3 V_81 , V_82 ;
struct V_68 * V_83 ;
V_83 = & V_75 -> V_49 [ V_43 ] ;
V_79 = V_83 -> V_45 ;
V_80 = V_83 -> V_50 ;
V_81 = V_79 + V_83 -> V_30 - 1 ;
V_82 = V_80 + V_83 -> V_30 - 1 ;
if ( ( V_79 <= V_77 ) &&
( V_81 >= V_76 ) )
return true ;
if ( ( V_80 <= V_78 ) &&
( V_82 >= V_50 ) )
return true ;
}
return false ;
}
static T_9 F_53 ( struct V_84 * V_84 , const char T_10 * V_85 ,
T_11 V_30 , T_8 * V_71 ,
int V_86 ,
struct V_40 * V_41 ,
struct V_40 * V_87 )
{
struct V_64 * V_65 = V_84 -> V_88 ;
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_40 V_75 ;
unsigned V_43 ;
struct V_68 * V_49 = NULL ;
char * V_89 = NULL , * V_72 , * V_90 ;
T_9 V_21 = - V_91 ;
F_12 ( & V_32 ) ;
V_21 = - V_24 ;
if ( V_41 -> V_48 != 0 )
goto V_92;
if ( F_54 ( V_86 ) && ! F_55 ( V_84 , V_15 , V_93 ) )
goto V_92;
V_21 = - V_91 ;
if ( ( * V_71 != 0 ) || ( V_30 >= V_94 ) )
goto V_92;
V_89 = F_56 ( V_85 , V_30 ) ;
if ( F_57 ( V_89 ) ) {
V_21 = F_58 ( V_89 ) ;
V_89 = NULL ;
goto V_92;
}
V_21 = - V_91 ;
V_72 = V_89 ;
V_75 . V_48 = 0 ;
for (; V_72 ; V_72 = V_90 ) {
V_49 = & V_75 . V_49 [ V_75 . V_48 ] ;
V_90 = strchr ( V_72 , '\n' ) ;
if ( V_90 ) {
* V_90 = '\0' ;
V_90 ++ ;
if ( * V_90 == '\0' )
V_90 = NULL ;
}
V_72 = F_59 ( V_72 ) ;
V_49 -> V_45 = F_60 ( V_72 , & V_72 , 10 ) ;
if ( ! isspace ( * V_72 ) )
goto V_92;
V_72 = F_59 ( V_72 ) ;
V_49 -> V_50 = F_60 ( V_72 , & V_72 , 10 ) ;
if ( ! isspace ( * V_72 ) )
goto V_92;
V_72 = F_59 ( V_72 ) ;
V_49 -> V_30 = F_60 ( V_72 , & V_72 , 10 ) ;
if ( * V_72 && ! isspace ( * V_72 ) )
goto V_92;
V_72 = F_59 ( V_72 ) ;
if ( * V_72 != '\0' )
goto V_92;
if ( ( V_49 -> V_45 == ( T_3 ) - 1 ) ||
( V_49 -> V_50 == ( T_3 ) - 1 ) )
goto V_92;
if ( ( V_49 -> V_45 + V_49 -> V_30 ) <= V_49 -> V_45 )
goto V_92;
if ( ( V_49 -> V_50 + V_49 -> V_30 ) <=
V_49 -> V_50 )
goto V_92;
if ( F_52 ( & V_75 , V_49 ) )
goto V_92;
V_75 . V_48 ++ ;
if ( ( V_75 . V_48 == V_95 ) &&
( V_90 != NULL ) )
goto V_92;
}
if ( V_75 . V_48 == 0 )
goto V_92;
V_21 = - V_24 ;
if ( ! F_61 ( V_84 , V_15 , V_86 , & V_75 ) )
goto V_92;
for ( V_43 = 0 ; V_43 < V_75 . V_48 ; V_43 ++ ) {
T_3 V_50 ;
V_49 = & V_75 . V_49 [ V_43 ] ;
V_50 = F_22 ( V_87 ,
V_49 -> V_50 ,
V_49 -> V_30 ) ;
if ( V_50 == ( T_3 ) - 1 )
goto V_92;
V_49 -> V_50 = V_50 ;
}
memcpy ( V_41 -> V_49 , V_75 . V_49 ,
V_75 . V_48 * sizeof( V_75 . V_49 [ 0 ] ) ) ;
F_62 () ;
V_41 -> V_48 = V_75 . V_48 ;
* V_71 = V_30 ;
V_21 = V_30 ;
V_92:
F_13 ( & V_32 ) ;
F_63 ( V_89 ) ;
return V_21 ;
}
T_9 F_64 ( struct V_84 * V_84 , const char T_10 * V_85 ,
T_11 V_96 , T_8 * V_71 )
{
struct V_64 * V_65 = V_84 -> V_88 ;
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_2 * V_97 = F_42 ( V_65 ) ;
if ( ! V_15 -> V_31 )
return - V_24 ;
if ( ( V_97 != V_15 ) && ( V_97 != V_15 -> V_31 ) )
return - V_24 ;
return F_53 ( V_84 , V_85 , V_96 , V_71 , V_98 ,
& V_15 -> V_52 , & V_15 -> V_31 -> V_52 ) ;
}
T_9 F_65 ( struct V_84 * V_84 , const char T_10 * V_85 ,
T_11 V_96 , T_8 * V_71 )
{
struct V_64 * V_65 = V_84 -> V_88 ;
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_2 * V_97 = F_42 ( V_65 ) ;
if ( ! V_15 -> V_31 )
return - V_24 ;
if ( ( V_97 != V_15 ) && ( V_97 != V_15 -> V_31 ) )
return - V_24 ;
return F_53 ( V_84 , V_85 , V_96 , V_71 , V_99 ,
& V_15 -> V_57 , & V_15 -> V_31 -> V_57 ) ;
}
T_9 F_66 ( struct V_84 * V_84 , const char T_10 * V_85 ,
T_11 V_96 , T_8 * V_71 )
{
struct V_64 * V_65 = V_84 -> V_88 ;
struct V_2 * V_15 = V_65 -> V_67 ;
struct V_2 * V_97 = F_42 ( V_65 ) ;
if ( ! V_15 -> V_31 )
return - V_24 ;
if ( ( V_97 != V_15 ) && ( V_97 != V_15 -> V_31 ) )
return - V_24 ;
return F_53 ( V_84 , V_85 , V_96 , V_71 , - 1 ,
& V_15 -> V_61 , & V_15 -> V_31 -> V_61 ) ;
}
static bool F_61 ( const struct V_84 * V_84 ,
struct V_2 * V_15 , int V_86 ,
struct V_40 * V_75 )
{
const struct V_1 * V_1 = V_84 -> V_100 ;
if ( ( V_75 -> V_48 == 1 ) && ( V_75 -> V_49 [ 0 ] . V_30 == 1 ) &&
F_67 ( V_15 -> V_17 , V_1 -> V_18 ) ) {
T_3 V_42 = V_75 -> V_49 [ 0 ] . V_50 ;
if ( V_86 == V_98 ) {
T_1 V_51 = F_26 ( V_15 -> V_31 , V_42 ) ;
if ( F_67 ( V_51 , V_1 -> V_18 ) )
return true ;
} else if ( V_86 == V_99 ) {
T_2 V_56 = F_31 ( V_15 -> V_31 , V_42 ) ;
if ( ! ( V_15 -> V_33 & V_101 ) &&
F_68 ( V_56 , V_1 -> V_20 ) )
return true ;
}
}
if ( ! F_54 ( V_86 ) )
return true ;
if ( F_69 ( V_15 -> V_31 , V_86 ) &&
F_55 ( V_84 , V_15 -> V_31 , V_86 ) )
return true ;
return false ;
}
int F_70 ( struct V_64 * V_65 , void * V_66 )
{
struct V_2 * V_15 = V_65 -> V_67 ;
unsigned long V_102 = F_71 ( V_15 -> V_33 ) ;
F_43 ( V_65 , L_2 ,
( V_102 & V_101 ) ?
L_3 : L_4 ) ;
return 0 ;
}
T_9 F_72 ( struct V_84 * V_84 , const char T_10 * V_85 ,
T_11 V_30 , T_8 * V_71 )
{
struct V_64 * V_65 = V_84 -> V_88 ;
struct V_2 * V_15 = V_65 -> V_67 ;
char V_89 [ 8 ] , * V_72 ;
bool V_103 ;
T_9 V_21 ;
V_21 = - V_91 ;
if ( ( * V_71 != 0 ) || ( V_30 >= sizeof( V_89 ) ) )
goto V_92;
V_21 = - V_104 ;
if ( F_73 ( V_89 , V_85 , V_30 ) )
goto V_92;
V_89 [ V_30 ] = '\0' ;
V_72 = V_89 ;
V_21 = - V_91 ;
if ( strncmp ( V_72 , L_3 , 5 ) == 0 ) {
V_72 += 5 ;
V_103 = true ;
}
else if ( strncmp ( V_72 , L_4 , 4 ) == 0 ) {
V_72 += 4 ;
V_103 = false ;
}
else
goto V_92;
V_72 = F_59 ( V_72 ) ;
if ( * V_72 != '\0' )
goto V_92;
V_21 = - V_24 ;
F_12 ( & V_32 ) ;
if ( V_103 ) {
if ( ! ( V_15 -> V_33 & V_101 ) )
goto V_105;
} else {
if ( V_15 -> V_57 . V_48 != 0 )
goto V_105;
V_15 -> V_33 &= ~ V_101 ;
}
F_13 ( & V_32 ) ;
* V_71 = V_30 ;
V_21 = V_30 ;
V_92:
return V_21 ;
V_105:
F_13 ( & V_32 ) ;
goto V_92;
}
bool F_74 ( const struct V_2 * V_15 )
{
bool V_106 ;
F_12 ( & V_32 ) ;
V_106 = V_15 -> V_57 . V_48 != 0 ;
V_106 = V_106 && ( V_15 -> V_33 & V_101 ) ;
F_13 ( & V_32 ) ;
return V_106 ;
}
static inline struct V_2 * F_75 ( struct V_107 * V_15 )
{
return F_76 ( V_15 , struct V_2 , V_15 ) ;
}
static struct V_107 * F_77 ( struct V_108 * V_109 )
{
struct V_2 * V_3 ;
F_78 () ;
V_3 = F_79 ( F_80 ( V_109 ) -> V_3 ) ;
F_81 () ;
return V_3 ? & V_3 -> V_15 : NULL ;
}
static void F_82 ( struct V_107 * V_15 )
{
F_83 ( F_75 ( V_15 ) ) ;
}
static int F_84 ( struct V_110 * V_110 , struct V_107 * V_15 )
{
struct V_2 * V_3 = F_75 ( V_15 ) ;
struct V_1 * V_1 ;
if ( V_3 == F_85 () )
return - V_91 ;
if ( ! F_86 ( V_111 ) )
return - V_91 ;
if ( V_111 -> V_112 -> V_113 != 1 )
return - V_91 ;
if ( ! F_69 ( V_3 , V_93 ) )
return - V_24 ;
V_1 = F_17 () ;
if ( ! V_1 )
return - V_27 ;
F_83 ( V_1 -> V_3 ) ;
F_1 ( V_1 , F_79 ( V_3 ) ) ;
return F_87 ( V_1 ) ;
}
static T_12 int F_88 ( void )
{
V_25 = F_89 ( V_2 , V_114 ) ;
return 0 ;
}
