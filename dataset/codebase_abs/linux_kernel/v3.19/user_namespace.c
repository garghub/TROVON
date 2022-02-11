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
V_20 = F_9 ( & V_14 -> V_14 ) ;
if ( V_20 ) {
F_10 ( V_24 , V_14 ) ;
return V_20 ;
}
V_14 -> V_14 . V_27 = & V_28 ;
F_11 ( & V_14 -> V_29 , 1 ) ;
V_14 -> V_30 = V_15 ;
V_14 -> V_21 = V_15 -> V_21 + 1 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_18 = V_18 ;
F_12 ( & V_31 ) ;
V_14 -> V_32 = V_15 -> V_32 ;
F_13 ( & V_31 ) ;
F_1 ( V_13 , V_14 ) ;
#ifdef F_14
F_15 ( & V_14 -> V_33 ) ;
#endif
return 0 ;
}
int F_16 ( unsigned long V_34 , struct V_1 * * V_35 )
{
struct V_1 * V_1 ;
int V_36 = - V_26 ;
if ( ! ( V_34 & V_37 ) )
return 0 ;
V_1 = F_17 () ;
if ( V_1 ) {
V_36 = F_4 ( V_1 ) ;
if ( V_36 )
F_18 ( V_1 ) ;
else
* V_35 = V_1 ;
}
return V_36 ;
}
void F_19 ( struct V_2 * V_14 )
{
struct V_2 * V_30 ;
do {
V_30 = V_14 -> V_30 ;
#ifdef F_14
F_3 ( V_14 -> V_38 ) ;
#endif
F_20 ( & V_14 -> V_14 ) ;
F_10 ( V_24 , V_14 ) ;
V_14 = V_30 ;
} while ( F_21 ( & V_30 -> V_29 ) );
}
static T_3 F_22 ( struct V_39 * V_40 , T_3 V_41 , T_3 V_29 )
{
unsigned V_42 , V_43 ;
T_3 V_44 , V_45 , V_46 ;
V_46 = V_41 + V_29 - 1 ;
V_43 = V_40 -> V_47 ;
F_23 () ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_44 = V_40 -> V_48 [ V_42 ] . V_44 ;
V_45 = V_44 + V_40 -> V_48 [ V_42 ] . V_29 - 1 ;
if ( V_41 >= V_44 && V_41 <= V_45 &&
( V_46 >= V_44 && V_46 <= V_45 ) )
break;
}
if ( V_42 < V_43 )
V_41 = ( V_41 - V_44 ) + V_40 -> V_48 [ V_42 ] . V_49 ;
else
V_41 = ( T_3 ) - 1 ;
return V_41 ;
}
static T_3 F_24 ( struct V_39 * V_40 , T_3 V_41 )
{
unsigned V_42 , V_43 ;
T_3 V_44 , V_45 ;
V_43 = V_40 -> V_47 ;
F_23 () ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_44 = V_40 -> V_48 [ V_42 ] . V_44 ;
V_45 = V_44 + V_40 -> V_48 [ V_42 ] . V_29 - 1 ;
if ( V_41 >= V_44 && V_41 <= V_45 )
break;
}
if ( V_42 < V_43 )
V_41 = ( V_41 - V_44 ) + V_40 -> V_48 [ V_42 ] . V_49 ;
else
V_41 = ( T_3 ) - 1 ;
return V_41 ;
}
static T_3 F_25 ( struct V_39 * V_40 , T_3 V_41 )
{
unsigned V_42 , V_43 ;
T_3 V_44 , V_45 ;
V_43 = V_40 -> V_47 ;
F_23 () ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_44 = V_40 -> V_48 [ V_42 ] . V_49 ;
V_45 = V_44 + V_40 -> V_48 [ V_42 ] . V_29 - 1 ;
if ( V_41 >= V_44 && V_41 <= V_45 )
break;
}
if ( V_42 < V_43 )
V_41 = ( V_41 - V_44 ) + V_40 -> V_48 [ V_42 ] . V_44 ;
else
V_41 = ( T_3 ) - 1 ;
return V_41 ;
}
T_1 F_26 ( struct V_2 * V_14 , T_4 V_50 )
{
return F_27 ( F_24 ( & V_14 -> V_51 , V_50 ) ) ;
}
T_4 F_28 ( struct V_2 * V_52 , T_1 V_53 )
{
return F_25 ( & V_52 -> V_51 , F_29 ( V_53 ) ) ;
}
T_4 F_30 ( struct V_2 * V_52 , T_1 V_53 )
{
T_4 V_50 ;
V_50 = F_28 ( V_52 , V_53 ) ;
if ( V_50 == ( T_4 ) - 1 )
V_50 = V_54 ;
return V_50 ;
}
T_2 F_31 ( struct V_2 * V_14 , T_5 V_55 )
{
return F_32 ( F_24 ( & V_14 -> V_56 , V_55 ) ) ;
}
T_5 F_33 ( struct V_2 * V_52 , T_2 V_57 )
{
return F_25 ( & V_52 -> V_56 , F_34 ( V_57 ) ) ;
}
T_5 F_35 ( struct V_2 * V_52 , T_2 V_57 )
{
T_5 V_55 ;
V_55 = F_33 ( V_52 , V_57 ) ;
if ( V_55 == ( T_5 ) - 1 )
V_55 = V_58 ;
return V_55 ;
}
T_6 F_36 ( struct V_2 * V_14 , T_7 V_59 )
{
return F_37 ( F_24 ( & V_14 -> V_60 , V_59 ) ) ;
}
T_7 F_38 ( struct V_2 * V_52 , T_6 V_61 )
{
return F_25 ( & V_52 -> V_60 , F_39 ( V_61 ) ) ;
}
T_7 F_40 ( struct V_2 * V_52 , T_6 V_61 )
{
T_7 V_59 ;
V_59 = F_38 ( V_52 , V_61 ) ;
if ( V_59 == ( T_7 ) - 1 )
V_59 = V_62 ;
return V_59 ;
}
static int F_41 ( struct V_63 * V_64 , void * V_65 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_67 * V_48 = V_65 ;
struct V_2 * V_68 ;
T_4 V_69 ;
V_68 = F_42 ( V_64 ) ;
if ( ( V_68 == V_14 ) && V_68 -> V_30 )
V_68 = V_68 -> V_30 ;
V_69 = F_28 ( V_68 , F_27 ( V_48 -> V_49 ) ) ;
F_43 ( V_64 , L_1 ,
V_48 -> V_44 ,
V_69 ,
V_48 -> V_29 ) ;
return 0 ;
}
static int F_44 ( struct V_63 * V_64 , void * V_65 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_67 * V_48 = V_65 ;
struct V_2 * V_68 ;
T_5 V_69 ;
V_68 = F_42 ( V_64 ) ;
if ( ( V_68 == V_14 ) && V_68 -> V_30 )
V_68 = V_68 -> V_30 ;
V_69 = F_33 ( V_68 , F_32 ( V_48 -> V_49 ) ) ;
F_43 ( V_64 , L_1 ,
V_48 -> V_44 ,
V_69 ,
V_48 -> V_29 ) ;
return 0 ;
}
static int F_45 ( struct V_63 * V_64 , void * V_65 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_67 * V_48 = V_65 ;
struct V_2 * V_68 ;
T_7 V_69 ;
V_68 = F_42 ( V_64 ) ;
if ( ( V_68 == V_14 ) && V_68 -> V_30 )
V_68 = V_68 -> V_30 ;
V_69 = F_38 ( V_68 , F_37 ( V_48 -> V_49 ) ) ;
F_43 ( V_64 , L_1 ,
V_48 -> V_44 ,
V_69 ,
V_48 -> V_29 ) ;
return 0 ;
}
static void * F_46 ( struct V_63 * V_64 , T_8 * V_70 ,
struct V_39 * V_40 )
{
struct V_67 * V_48 = NULL ;
T_8 V_71 = * V_70 ;
if ( V_71 < V_40 -> V_47 )
V_48 = & V_40 -> V_48 [ V_71 ] ;
return V_48 ;
}
static void * F_47 ( struct V_63 * V_64 , T_8 * V_70 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
return F_46 ( V_64 , V_70 , & V_14 -> V_51 ) ;
}
static void * F_48 ( struct V_63 * V_64 , T_8 * V_70 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
return F_46 ( V_64 , V_70 , & V_14 -> V_56 ) ;
}
static void * F_49 ( struct V_63 * V_64 , T_8 * V_70 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
return F_46 ( V_64 , V_70 , & V_14 -> V_60 ) ;
}
static void * F_50 ( struct V_63 * V_64 , void * V_65 , T_8 * V_71 )
{
( * V_71 ) ++ ;
return V_64 -> V_72 -> V_73 ( V_64 , V_71 ) ;
}
static void F_51 ( struct V_63 * V_64 , void * V_65 )
{
return;
}
static bool F_52 ( struct V_39 * V_74 ,
struct V_67 * V_48 )
{
T_3 V_75 , V_49 , V_76 , V_77 ;
unsigned V_42 ;
V_75 = V_48 -> V_44 ;
V_49 = V_48 -> V_49 ;
V_76 = V_75 + V_48 -> V_29 - 1 ;
V_77 = V_49 + V_48 -> V_29 - 1 ;
for ( V_42 = 0 ; V_42 < V_74 -> V_47 ; V_42 ++ ) {
T_3 V_78 , V_79 ;
T_3 V_80 , V_81 ;
struct V_67 * V_82 ;
V_82 = & V_74 -> V_48 [ V_42 ] ;
V_78 = V_82 -> V_44 ;
V_79 = V_82 -> V_49 ;
V_80 = V_78 + V_82 -> V_29 - 1 ;
V_81 = V_79 + V_82 -> V_29 - 1 ;
if ( ( V_78 <= V_76 ) &&
( V_80 >= V_75 ) )
return true ;
if ( ( V_79 <= V_77 ) &&
( V_81 >= V_49 ) )
return true ;
}
return false ;
}
static T_9 F_53 ( struct V_83 * V_83 , const char T_10 * V_84 ,
T_11 V_29 , T_8 * V_70 ,
int V_85 ,
struct V_39 * V_40 ,
struct V_39 * V_86 )
{
struct V_63 * V_64 = V_83 -> V_87 ;
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_39 V_74 ;
unsigned V_42 ;
struct V_67 * V_48 = NULL ;
unsigned long V_88 = 0 ;
char * V_89 , * V_71 , * V_90 ;
T_9 V_20 = - V_91 ;
F_12 ( & V_31 ) ;
V_20 = - V_23 ;
if ( V_40 -> V_47 != 0 )
goto V_92;
if ( F_54 ( V_85 ) && ! F_55 ( V_83 , V_14 , V_93 ) )
goto V_92;
V_20 = - V_26 ;
V_88 = F_56 ( V_94 ) ;
V_89 = ( char * ) V_88 ;
if ( ! V_88 )
goto V_92;
V_20 = - V_91 ;
if ( ( * V_70 != 0 ) || ( V_29 >= V_95 ) )
goto V_92;
V_20 = - V_96 ;
if ( F_57 ( V_89 , V_84 , V_29 ) )
goto V_92;
V_89 [ V_29 ] = '\0' ;
V_20 = - V_91 ;
V_71 = V_89 ;
V_74 . V_47 = 0 ;
for (; V_71 ; V_71 = V_90 ) {
V_48 = & V_74 . V_48 [ V_74 . V_47 ] ;
V_90 = strchr ( V_71 , '\n' ) ;
if ( V_90 ) {
* V_90 = '\0' ;
V_90 ++ ;
if ( * V_90 == '\0' )
V_90 = NULL ;
}
V_71 = F_58 ( V_71 ) ;
V_48 -> V_44 = F_59 ( V_71 , & V_71 , 10 ) ;
if ( ! isspace ( * V_71 ) )
goto V_92;
V_71 = F_58 ( V_71 ) ;
V_48 -> V_49 = F_59 ( V_71 , & V_71 , 10 ) ;
if ( ! isspace ( * V_71 ) )
goto V_92;
V_71 = F_58 ( V_71 ) ;
V_48 -> V_29 = F_59 ( V_71 , & V_71 , 10 ) ;
if ( * V_71 && ! isspace ( * V_71 ) )
goto V_92;
V_71 = F_58 ( V_71 ) ;
if ( * V_71 != '\0' )
goto V_92;
if ( ( V_48 -> V_44 == ( T_3 ) - 1 ) ||
( V_48 -> V_49 == ( T_3 ) - 1 ) )
goto V_92;
if ( ( V_48 -> V_44 + V_48 -> V_29 ) <= V_48 -> V_44 )
goto V_92;
if ( ( V_48 -> V_49 + V_48 -> V_29 ) <=
V_48 -> V_49 )
goto V_92;
if ( F_52 ( & V_74 , V_48 ) )
goto V_92;
V_74 . V_47 ++ ;
if ( ( V_74 . V_47 == V_97 ) &&
( V_90 != NULL ) )
goto V_92;
}
if ( V_74 . V_47 == 0 )
goto V_92;
V_20 = - V_23 ;
if ( ! F_60 ( V_83 , V_14 , V_85 , & V_74 ) )
goto V_92;
for ( V_42 = 0 ; V_42 < V_74 . V_47 ; V_42 ++ ) {
T_3 V_49 ;
V_48 = & V_74 . V_48 [ V_42 ] ;
V_49 = F_22 ( V_86 ,
V_48 -> V_49 ,
V_48 -> V_29 ) ;
if ( V_49 == ( T_3 ) - 1 )
goto V_92;
V_48 -> V_49 = V_49 ;
}
memcpy ( V_40 -> V_48 , V_74 . V_48 ,
V_74 . V_47 * sizeof( V_74 . V_48 [ 0 ] ) ) ;
F_61 () ;
V_40 -> V_47 = V_74 . V_47 ;
* V_70 = V_29 ;
V_20 = V_29 ;
V_92:
F_13 ( & V_31 ) ;
if ( V_88 )
F_62 ( V_88 ) ;
return V_20 ;
}
T_9 F_63 ( struct V_83 * V_83 , const char T_10 * V_84 ,
T_11 V_98 , T_8 * V_70 )
{
struct V_63 * V_64 = V_83 -> V_87 ;
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_2 * V_99 = F_42 ( V_64 ) ;
if ( ! V_14 -> V_30 )
return - V_23 ;
if ( ( V_99 != V_14 ) && ( V_99 != V_14 -> V_30 ) )
return - V_23 ;
return F_53 ( V_83 , V_84 , V_98 , V_70 , V_100 ,
& V_14 -> V_51 , & V_14 -> V_30 -> V_51 ) ;
}
T_9 F_64 ( struct V_83 * V_83 , const char T_10 * V_84 ,
T_11 V_98 , T_8 * V_70 )
{
struct V_63 * V_64 = V_83 -> V_87 ;
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_2 * V_99 = F_42 ( V_64 ) ;
if ( ! V_14 -> V_30 )
return - V_23 ;
if ( ( V_99 != V_14 ) && ( V_99 != V_14 -> V_30 ) )
return - V_23 ;
return F_53 ( V_83 , V_84 , V_98 , V_70 , V_101 ,
& V_14 -> V_56 , & V_14 -> V_30 -> V_56 ) ;
}
T_9 F_65 ( struct V_83 * V_83 , const char T_10 * V_84 ,
T_11 V_98 , T_8 * V_70 )
{
struct V_63 * V_64 = V_83 -> V_87 ;
struct V_2 * V_14 = V_64 -> V_66 ;
struct V_2 * V_99 = F_42 ( V_64 ) ;
if ( ! V_14 -> V_30 )
return - V_23 ;
if ( ( V_99 != V_14 ) && ( V_99 != V_14 -> V_30 ) )
return - V_23 ;
return F_53 ( V_83 , V_84 , V_98 , V_70 , - 1 ,
& V_14 -> V_60 , & V_14 -> V_30 -> V_60 ) ;
}
static bool F_60 ( const struct V_83 * V_83 ,
struct V_2 * V_14 , int V_85 ,
struct V_39 * V_74 )
{
const struct V_1 * V_1 = V_83 -> V_102 ;
if ( ( V_74 -> V_47 == 1 ) && ( V_74 -> V_48 [ 0 ] . V_29 == 1 ) &&
F_66 ( V_14 -> V_16 , V_1 -> V_17 ) ) {
T_3 V_41 = V_74 -> V_48 [ 0 ] . V_49 ;
if ( V_85 == V_100 ) {
T_1 V_50 = F_26 ( V_14 -> V_30 , V_41 ) ;
if ( F_66 ( V_50 , V_1 -> V_17 ) )
return true ;
} else if ( V_85 == V_101 ) {
T_2 V_55 = F_31 ( V_14 -> V_30 , V_41 ) ;
if ( ! ( V_14 -> V_32 & V_103 ) &&
F_67 ( V_55 , V_1 -> V_19 ) )
return true ;
}
}
if ( ! F_54 ( V_85 ) )
return true ;
if ( F_68 ( V_14 -> V_30 , V_85 ) &&
F_55 ( V_83 , V_14 -> V_30 , V_85 ) )
return true ;
return false ;
}
int F_69 ( struct V_63 * V_64 , void * V_65 )
{
struct V_2 * V_14 = V_64 -> V_66 ;
unsigned long V_104 = F_70 ( V_14 -> V_32 ) ;
F_43 ( V_64 , L_2 ,
( V_104 & V_103 ) ?
L_3 : L_4 ) ;
return 0 ;
}
T_9 F_71 ( struct V_83 * V_83 , const char T_10 * V_84 ,
T_11 V_29 , T_8 * V_70 )
{
struct V_63 * V_64 = V_83 -> V_87 ;
struct V_2 * V_14 = V_64 -> V_66 ;
char V_89 [ 8 ] , * V_71 ;
bool V_105 ;
T_9 V_20 ;
V_20 = - V_91 ;
if ( ( * V_70 != 0 ) || ( V_29 >= sizeof( V_89 ) ) )
goto V_92;
V_20 = - V_96 ;
if ( F_57 ( V_89 , V_84 , V_29 ) )
goto V_92;
V_89 [ V_29 ] = '\0' ;
V_71 = V_89 ;
V_20 = - V_91 ;
if ( strncmp ( V_71 , L_3 , 5 ) == 0 ) {
V_71 += 5 ;
V_105 = true ;
}
else if ( strncmp ( V_71 , L_4 , 4 ) == 0 ) {
V_71 += 4 ;
V_105 = false ;
}
else
goto V_92;
V_71 = F_58 ( V_71 ) ;
if ( * V_71 != '\0' )
goto V_92;
V_20 = - V_23 ;
F_12 ( & V_31 ) ;
if ( V_105 ) {
if ( ! ( V_14 -> V_32 & V_103 ) )
goto V_106;
} else {
if ( V_14 -> V_56 . V_47 != 0 )
goto V_106;
V_14 -> V_32 &= ~ V_103 ;
}
F_13 ( & V_31 ) ;
* V_70 = V_29 ;
V_20 = V_29 ;
V_92:
return V_20 ;
V_106:
F_13 ( & V_31 ) ;
goto V_92;
}
bool F_72 ( const struct V_2 * V_14 )
{
bool V_107 ;
F_12 ( & V_31 ) ;
V_107 = V_14 -> V_56 . V_47 != 0 ;
V_107 = V_107 && ( V_14 -> V_32 & V_103 ) ;
F_13 ( & V_31 ) ;
return V_107 ;
}
static inline struct V_2 * F_73 ( struct V_108 * V_14 )
{
return F_74 ( V_14 , struct V_2 , V_14 ) ;
}
static struct V_108 * F_75 ( struct V_109 * V_110 )
{
struct V_2 * V_3 ;
F_76 () ;
V_3 = F_77 ( F_78 ( V_110 ) -> V_3 ) ;
F_79 () ;
return V_3 ? & V_3 -> V_14 : NULL ;
}
static void F_80 ( struct V_108 * V_14 )
{
F_81 ( F_73 ( V_14 ) ) ;
}
static int F_82 ( struct V_111 * V_111 , struct V_108 * V_14 )
{
struct V_2 * V_3 = F_73 ( V_14 ) ;
struct V_1 * V_1 ;
if ( V_3 == F_83 () )
return - V_91 ;
if ( F_84 ( & V_112 -> V_113 -> V_114 ) > 1 )
return - V_91 ;
if ( V_112 -> V_115 -> V_116 != 1 )
return - V_91 ;
if ( ! F_68 ( V_3 , V_93 ) )
return - V_23 ;
V_1 = F_17 () ;
if ( ! V_1 )
return - V_26 ;
F_81 ( V_1 -> V_3 ) ;
F_1 ( V_1 , F_77 ( V_3 ) ) ;
return F_85 ( V_1 ) ;
}
static T_12 int F_86 ( void )
{
V_24 = F_87 ( V_2 , V_117 ) ;
return 0 ;
}
