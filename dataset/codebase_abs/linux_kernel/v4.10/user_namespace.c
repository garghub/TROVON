static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_2 ( V_3 , V_4 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
return F_4 ( V_1 , V_5 ) ;
}
static void F_5 ( struct V_6 * V_6 , struct V_2 * V_7 )
{
V_6 -> V_8 = V_9 ;
V_6 -> V_10 = V_11 ;
V_6 -> V_12 = V_13 ;
V_6 -> V_14 = V_13 ;
V_6 -> V_15 = V_11 ;
V_6 -> V_16 = V_13 ;
#ifdef F_6
F_7 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
#endif
V_6 -> V_7 = V_7 ;
}
int F_8 ( struct V_6 * V_18 )
{
struct V_2 * V_3 , * V_19 = V_18 -> V_7 ;
T_1 V_20 = V_18 -> V_21 ;
T_2 V_22 = V_18 -> V_23 ;
struct V_1 * V_1 ;
int V_24 , V_25 ;
V_24 = - V_26 ;
if ( V_19 -> V_27 > 32 )
goto V_28;
V_1 = F_1 ( V_19 , V_20 ) ;
if ( ! V_1 )
goto V_28;
V_24 = - V_29 ;
if ( F_9 () )
goto V_30;
V_24 = - V_29 ;
if ( ! F_10 ( V_19 , V_20 ) ||
! F_11 ( V_19 , V_22 ) )
goto V_30;
V_24 = - V_31 ;
V_3 = F_12 ( V_32 , V_33 ) ;
if ( ! V_3 )
goto V_30;
V_24 = F_13 ( & V_3 -> V_3 ) ;
if ( V_24 )
goto V_34;
V_3 -> V_3 . V_35 = & V_36 ;
F_14 ( & V_3 -> V_37 , 1 ) ;
V_3 -> V_38 = V_19 ;
V_3 -> V_27 = V_19 -> V_27 + 1 ;
V_3 -> V_20 = V_20 ;
V_3 -> V_22 = V_22 ;
F_15 ( & V_3 -> V_39 , V_40 ) ;
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
V_3 -> V_42 [ V_25 ] = V_43 ;
}
V_3 -> V_1 = V_1 ;
F_16 ( & V_44 ) ;
V_3 -> V_45 = V_19 -> V_45 ;
F_17 ( & V_44 ) ;
#ifdef F_18
F_19 ( & V_3 -> V_46 ) ;
#endif
V_24 = - V_31 ;
if ( ! F_20 ( V_3 ) )
goto V_47;
F_5 ( V_18 , V_3 ) ;
return 0 ;
V_47:
#ifdef F_18
F_7 ( V_3 -> V_48 ) ;
#endif
F_21 ( & V_3 -> V_3 ) ;
V_34:
F_22 ( V_32 , V_3 ) ;
V_30:
F_3 ( V_1 ) ;
V_28:
return V_24 ;
}
int F_23 ( unsigned long V_49 , struct V_6 * * V_50 )
{
struct V_6 * V_6 ;
int V_51 = - V_31 ;
if ( ! ( V_49 & V_52 ) )
return 0 ;
V_6 = F_24 () ;
if ( V_6 ) {
V_51 = F_8 ( V_6 ) ;
if ( V_51 )
F_25 ( V_6 ) ;
else
* V_50 = V_6 ;
}
return V_51 ;
}
static void V_40 ( struct V_53 * V_39 )
{
struct V_2 * V_38 , * V_3 =
F_26 ( V_39 , struct V_2 , V_39 ) ;
do {
struct V_1 * V_1 = V_3 -> V_1 ;
V_38 = V_3 -> V_38 ;
F_27 ( V_3 ) ;
#ifdef F_18
F_7 ( V_3 -> V_48 ) ;
#endif
F_21 ( & V_3 -> V_3 ) ;
F_22 ( V_32 , V_3 ) ;
F_3 ( V_1 ) ;
V_3 = V_38 ;
} while ( F_28 ( & V_38 -> V_37 ) );
}
void F_29 ( struct V_2 * V_3 )
{
F_30 ( & V_3 -> V_39 ) ;
}
static T_3 F_31 ( struct V_54 * V_55 , T_3 V_56 , T_3 V_37 )
{
unsigned V_57 , V_58 ;
T_3 V_59 , V_60 , V_61 ;
V_61 = V_56 + V_37 - 1 ;
V_58 = V_55 -> V_62 ;
F_32 () ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_59 = V_55 -> V_63 [ V_57 ] . V_59 ;
V_60 = V_59 + V_55 -> V_63 [ V_57 ] . V_37 - 1 ;
if ( V_56 >= V_59 && V_56 <= V_60 &&
( V_61 >= V_59 && V_61 <= V_60 ) )
break;
}
if ( V_57 < V_58 )
V_56 = ( V_56 - V_59 ) + V_55 -> V_63 [ V_57 ] . V_64 ;
else
V_56 = ( T_3 ) - 1 ;
return V_56 ;
}
static T_3 F_33 ( struct V_54 * V_55 , T_3 V_56 )
{
unsigned V_57 , V_58 ;
T_3 V_59 , V_60 ;
V_58 = V_55 -> V_62 ;
F_32 () ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_59 = V_55 -> V_63 [ V_57 ] . V_59 ;
V_60 = V_59 + V_55 -> V_63 [ V_57 ] . V_37 - 1 ;
if ( V_56 >= V_59 && V_56 <= V_60 )
break;
}
if ( V_57 < V_58 )
V_56 = ( V_56 - V_59 ) + V_55 -> V_63 [ V_57 ] . V_64 ;
else
V_56 = ( T_3 ) - 1 ;
return V_56 ;
}
static T_3 F_34 ( struct V_54 * V_55 , T_3 V_56 )
{
unsigned V_57 , V_58 ;
T_3 V_59 , V_60 ;
V_58 = V_55 -> V_62 ;
F_32 () ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_59 = V_55 -> V_63 [ V_57 ] . V_64 ;
V_60 = V_59 + V_55 -> V_63 [ V_57 ] . V_37 - 1 ;
if ( V_56 >= V_59 && V_56 <= V_60 )
break;
}
if ( V_57 < V_58 )
V_56 = ( V_56 - V_59 ) + V_55 -> V_63 [ V_57 ] . V_59 ;
else
V_56 = ( T_3 ) - 1 ;
return V_56 ;
}
T_1 F_35 ( struct V_2 * V_3 , T_4 V_4 )
{
return F_36 ( F_33 ( & V_3 -> V_65 , V_4 ) ) ;
}
T_4 F_37 ( struct V_2 * V_66 , T_1 V_67 )
{
return F_34 ( & V_66 -> V_65 , F_38 ( V_67 ) ) ;
}
T_4 F_39 ( struct V_2 * V_66 , T_1 V_67 )
{
T_4 V_4 ;
V_4 = F_37 ( V_66 , V_67 ) ;
if ( V_4 == ( T_4 ) - 1 )
V_4 = V_68 ;
return V_4 ;
}
T_2 F_40 ( struct V_2 * V_3 , T_5 V_69 )
{
return F_41 ( F_33 ( & V_3 -> V_70 , V_69 ) ) ;
}
T_5 F_42 ( struct V_2 * V_66 , T_2 V_71 )
{
return F_34 ( & V_66 -> V_70 , F_43 ( V_71 ) ) ;
}
T_5 F_44 ( struct V_2 * V_66 , T_2 V_71 )
{
T_5 V_69 ;
V_69 = F_42 ( V_66 , V_71 ) ;
if ( V_69 == ( T_5 ) - 1 )
V_69 = V_72 ;
return V_69 ;
}
T_6 F_45 ( struct V_2 * V_3 , T_7 V_73 )
{
return F_46 ( F_33 ( & V_3 -> V_74 , V_73 ) ) ;
}
T_7 F_47 ( struct V_2 * V_66 , T_6 V_75 )
{
return F_34 ( & V_66 -> V_74 , F_48 ( V_75 ) ) ;
}
T_7 F_49 ( struct V_2 * V_66 , T_6 V_75 )
{
T_7 V_73 ;
V_73 = F_47 ( V_66 , V_75 ) ;
if ( V_73 == ( T_7 ) - 1 )
V_73 = V_76 ;
return V_73 ;
}
static int F_50 ( struct V_77 * V_78 , void * V_79 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_81 * V_63 = V_79 ;
struct V_2 * V_82 ;
T_4 V_83 ;
V_82 = F_51 ( V_78 ) ;
if ( ( V_82 == V_3 ) && V_82 -> V_38 )
V_82 = V_82 -> V_38 ;
V_83 = F_37 ( V_82 , F_36 ( V_63 -> V_64 ) ) ;
F_52 ( V_78 , L_1 ,
V_63 -> V_59 ,
V_83 ,
V_63 -> V_37 ) ;
return 0 ;
}
static int F_53 ( struct V_77 * V_78 , void * V_79 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_81 * V_63 = V_79 ;
struct V_2 * V_82 ;
T_5 V_83 ;
V_82 = F_51 ( V_78 ) ;
if ( ( V_82 == V_3 ) && V_82 -> V_38 )
V_82 = V_82 -> V_38 ;
V_83 = F_42 ( V_82 , F_41 ( V_63 -> V_64 ) ) ;
F_52 ( V_78 , L_1 ,
V_63 -> V_59 ,
V_83 ,
V_63 -> V_37 ) ;
return 0 ;
}
static int F_54 ( struct V_77 * V_78 , void * V_79 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_81 * V_63 = V_79 ;
struct V_2 * V_82 ;
T_7 V_83 ;
V_82 = F_51 ( V_78 ) ;
if ( ( V_82 == V_3 ) && V_82 -> V_38 )
V_82 = V_82 -> V_38 ;
V_83 = F_47 ( V_82 , F_46 ( V_63 -> V_64 ) ) ;
F_52 ( V_78 , L_1 ,
V_63 -> V_59 ,
V_83 ,
V_63 -> V_37 ) ;
return 0 ;
}
static void * F_55 ( struct V_77 * V_78 , T_8 * V_84 ,
struct V_54 * V_55 )
{
struct V_81 * V_63 = NULL ;
T_8 V_85 = * V_84 ;
if ( V_85 < V_55 -> V_62 )
V_63 = & V_55 -> V_63 [ V_85 ] ;
return V_63 ;
}
static void * F_56 ( struct V_77 * V_78 , T_8 * V_84 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
return F_55 ( V_78 , V_84 , & V_3 -> V_65 ) ;
}
static void * F_57 ( struct V_77 * V_78 , T_8 * V_84 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
return F_55 ( V_78 , V_84 , & V_3 -> V_70 ) ;
}
static void * F_58 ( struct V_77 * V_78 , T_8 * V_84 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
return F_55 ( V_78 , V_84 , & V_3 -> V_74 ) ;
}
static void * F_59 ( struct V_77 * V_78 , void * V_79 , T_8 * V_85 )
{
( * V_85 ) ++ ;
return V_78 -> V_86 -> V_87 ( V_78 , V_85 ) ;
}
static void F_60 ( struct V_77 * V_78 , void * V_79 )
{
return;
}
static bool F_61 ( struct V_54 * V_88 ,
struct V_81 * V_63 )
{
T_3 V_89 , V_64 , V_90 , V_91 ;
unsigned V_57 ;
V_89 = V_63 -> V_59 ;
V_64 = V_63 -> V_64 ;
V_90 = V_89 + V_63 -> V_37 - 1 ;
V_91 = V_64 + V_63 -> V_37 - 1 ;
for ( V_57 = 0 ; V_57 < V_88 -> V_62 ; V_57 ++ ) {
T_3 V_92 , V_93 ;
T_3 V_94 , V_95 ;
struct V_81 * V_96 ;
V_96 = & V_88 -> V_63 [ V_57 ] ;
V_92 = V_96 -> V_59 ;
V_93 = V_96 -> V_64 ;
V_94 = V_92 + V_96 -> V_37 - 1 ;
V_95 = V_93 + V_96 -> V_37 - 1 ;
if ( ( V_92 <= V_90 ) &&
( V_94 >= V_89 ) )
return true ;
if ( ( V_93 <= V_91 ) &&
( V_95 >= V_64 ) )
return true ;
}
return false ;
}
static T_9 F_62 ( struct V_97 * V_97 , const char T_10 * V_98 ,
T_11 V_37 , T_8 * V_84 ,
int V_99 ,
struct V_54 * V_55 ,
struct V_54 * V_100 )
{
struct V_77 * V_78 = V_97 -> V_101 ;
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_54 V_88 ;
unsigned V_57 ;
struct V_81 * V_63 = NULL ;
char * V_102 = NULL , * V_85 , * V_103 ;
T_9 V_24 = - V_104 ;
F_16 ( & V_44 ) ;
V_24 = - V_29 ;
if ( V_55 -> V_62 != 0 )
goto V_105;
if ( F_63 ( V_99 ) && ! F_64 ( V_97 , V_3 , V_106 ) )
goto V_105;
V_24 = - V_104 ;
if ( ( * V_84 != 0 ) || ( V_37 >= V_107 ) )
goto V_105;
V_102 = F_65 ( V_98 , V_37 ) ;
if ( F_66 ( V_102 ) ) {
V_24 = F_67 ( V_102 ) ;
V_102 = NULL ;
goto V_105;
}
V_24 = - V_104 ;
V_85 = V_102 ;
V_88 . V_62 = 0 ;
for (; V_85 ; V_85 = V_103 ) {
V_63 = & V_88 . V_63 [ V_88 . V_62 ] ;
V_103 = strchr ( V_85 , '\n' ) ;
if ( V_103 ) {
* V_103 = '\0' ;
V_103 ++ ;
if ( * V_103 == '\0' )
V_103 = NULL ;
}
V_85 = F_68 ( V_85 ) ;
V_63 -> V_59 = F_69 ( V_85 , & V_85 , 10 ) ;
if ( ! isspace ( * V_85 ) )
goto V_105;
V_85 = F_68 ( V_85 ) ;
V_63 -> V_64 = F_69 ( V_85 , & V_85 , 10 ) ;
if ( ! isspace ( * V_85 ) )
goto V_105;
V_85 = F_68 ( V_85 ) ;
V_63 -> V_37 = F_69 ( V_85 , & V_85 , 10 ) ;
if ( * V_85 && ! isspace ( * V_85 ) )
goto V_105;
V_85 = F_68 ( V_85 ) ;
if ( * V_85 != '\0' )
goto V_105;
if ( ( V_63 -> V_59 == ( T_3 ) - 1 ) ||
( V_63 -> V_64 == ( T_3 ) - 1 ) )
goto V_105;
if ( ( V_63 -> V_59 + V_63 -> V_37 ) <= V_63 -> V_59 )
goto V_105;
if ( ( V_63 -> V_64 + V_63 -> V_37 ) <=
V_63 -> V_64 )
goto V_105;
if ( F_61 ( & V_88 , V_63 ) )
goto V_105;
V_88 . V_62 ++ ;
if ( ( V_88 . V_62 == V_108 ) &&
( V_103 != NULL ) )
goto V_105;
}
if ( V_88 . V_62 == 0 )
goto V_105;
V_24 = - V_29 ;
if ( ! F_70 ( V_97 , V_3 , V_99 , & V_88 ) )
goto V_105;
for ( V_57 = 0 ; V_57 < V_88 . V_62 ; V_57 ++ ) {
T_3 V_64 ;
V_63 = & V_88 . V_63 [ V_57 ] ;
V_64 = F_31 ( V_100 ,
V_63 -> V_64 ,
V_63 -> V_37 ) ;
if ( V_64 == ( T_3 ) - 1 )
goto V_105;
V_63 -> V_64 = V_64 ;
}
memcpy ( V_55 -> V_63 , V_88 . V_63 ,
V_88 . V_62 * sizeof( V_88 . V_63 [ 0 ] ) ) ;
F_71 () ;
V_55 -> V_62 = V_88 . V_62 ;
* V_84 = V_37 ;
V_24 = V_37 ;
V_105:
F_17 ( & V_44 ) ;
F_72 ( V_102 ) ;
return V_24 ;
}
T_9 F_73 ( struct V_97 * V_97 , const char T_10 * V_98 ,
T_11 V_109 , T_8 * V_84 )
{
struct V_77 * V_78 = V_97 -> V_101 ;
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_2 * V_110 = F_51 ( V_78 ) ;
if ( ! V_3 -> V_38 )
return - V_29 ;
if ( ( V_110 != V_3 ) && ( V_110 != V_3 -> V_38 ) )
return - V_29 ;
return F_62 ( V_97 , V_98 , V_109 , V_84 , V_111 ,
& V_3 -> V_65 , & V_3 -> V_38 -> V_65 ) ;
}
T_9 F_74 ( struct V_97 * V_97 , const char T_10 * V_98 ,
T_11 V_109 , T_8 * V_84 )
{
struct V_77 * V_78 = V_97 -> V_101 ;
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_2 * V_110 = F_51 ( V_78 ) ;
if ( ! V_3 -> V_38 )
return - V_29 ;
if ( ( V_110 != V_3 ) && ( V_110 != V_3 -> V_38 ) )
return - V_29 ;
return F_62 ( V_97 , V_98 , V_109 , V_84 , V_112 ,
& V_3 -> V_70 , & V_3 -> V_38 -> V_70 ) ;
}
T_9 F_75 ( struct V_97 * V_97 , const char T_10 * V_98 ,
T_11 V_109 , T_8 * V_84 )
{
struct V_77 * V_78 = V_97 -> V_101 ;
struct V_2 * V_3 = V_78 -> V_80 ;
struct V_2 * V_110 = F_51 ( V_78 ) ;
if ( ! V_3 -> V_38 )
return - V_29 ;
if ( ( V_110 != V_3 ) && ( V_110 != V_3 -> V_38 ) )
return - V_29 ;
return F_62 ( V_97 , V_98 , V_109 , V_84 , - 1 ,
& V_3 -> V_74 , & V_3 -> V_38 -> V_74 ) ;
}
static bool F_70 ( const struct V_97 * V_97 ,
struct V_2 * V_3 , int V_99 ,
struct V_54 * V_88 )
{
const struct V_6 * V_6 = V_97 -> V_113 ;
if ( ( V_88 -> V_62 == 1 ) && ( V_88 -> V_63 [ 0 ] . V_37 == 1 ) &&
F_76 ( V_3 -> V_20 , V_6 -> V_21 ) ) {
T_3 V_56 = V_88 -> V_63 [ 0 ] . V_64 ;
if ( V_99 == V_111 ) {
T_1 V_4 = F_35 ( V_3 -> V_38 , V_56 ) ;
if ( F_76 ( V_4 , V_6 -> V_21 ) )
return true ;
} else if ( V_99 == V_112 ) {
T_2 V_69 = F_40 ( V_3 -> V_38 , V_56 ) ;
if ( ! ( V_3 -> V_45 & V_114 ) &&
F_77 ( V_69 , V_6 -> V_23 ) )
return true ;
}
}
if ( ! F_63 ( V_99 ) )
return true ;
if ( F_78 ( V_3 -> V_38 , V_99 ) &&
F_64 ( V_97 , V_3 -> V_38 , V_99 ) )
return true ;
return false ;
}
int F_79 ( struct V_77 * V_78 , void * V_79 )
{
struct V_2 * V_3 = V_78 -> V_80 ;
unsigned long V_115 = F_80 ( V_3 -> V_45 ) ;
F_52 ( V_78 , L_2 ,
( V_115 & V_114 ) ?
L_3 : L_4 ) ;
return 0 ;
}
T_9 F_81 ( struct V_97 * V_97 , const char T_10 * V_98 ,
T_11 V_37 , T_8 * V_84 )
{
struct V_77 * V_78 = V_97 -> V_101 ;
struct V_2 * V_3 = V_78 -> V_80 ;
char V_102 [ 8 ] , * V_85 ;
bool V_116 ;
T_9 V_24 ;
V_24 = - V_104 ;
if ( ( * V_84 != 0 ) || ( V_37 >= sizeof( V_102 ) ) )
goto V_105;
V_24 = - V_117 ;
if ( F_82 ( V_102 , V_98 , V_37 ) )
goto V_105;
V_102 [ V_37 ] = '\0' ;
V_85 = V_102 ;
V_24 = - V_104 ;
if ( strncmp ( V_85 , L_3 , 5 ) == 0 ) {
V_85 += 5 ;
V_116 = true ;
}
else if ( strncmp ( V_85 , L_4 , 4 ) == 0 ) {
V_85 += 4 ;
V_116 = false ;
}
else
goto V_105;
V_85 = F_68 ( V_85 ) ;
if ( * V_85 != '\0' )
goto V_105;
V_24 = - V_29 ;
F_16 ( & V_44 ) ;
if ( V_116 ) {
if ( ! ( V_3 -> V_45 & V_114 ) )
goto V_118;
} else {
if ( V_3 -> V_70 . V_62 != 0 )
goto V_118;
V_3 -> V_45 &= ~ V_114 ;
}
F_17 ( & V_44 ) ;
* V_84 = V_37 ;
V_24 = V_37 ;
V_105:
return V_24 ;
V_118:
F_17 ( & V_44 ) ;
goto V_105;
}
bool F_83 ( const struct V_2 * V_3 )
{
bool V_119 ;
F_16 ( & V_44 ) ;
V_119 = V_3 -> V_70 . V_62 != 0 ;
V_119 = V_119 && ( V_3 -> V_45 & V_114 ) ;
F_17 ( & V_44 ) ;
return V_119 ;
}
bool F_84 ( const struct V_2 * V_120 )
{
struct V_2 * V_3 ;
for ( V_3 = F_85 () ; V_3 ; V_3 = V_3 -> V_38 ) {
if ( V_3 == V_120 )
return true ;
}
return false ;
}
static inline struct V_2 * F_86 ( struct V_121 * V_3 )
{
return F_26 ( V_3 , struct V_2 , V_3 ) ;
}
static struct V_121 * F_87 ( struct V_122 * V_123 )
{
struct V_2 * V_7 ;
F_88 () ;
V_7 = F_89 ( F_90 ( V_123 ) -> V_7 ) ;
F_91 () ;
return V_7 ? & V_7 -> V_3 : NULL ;
}
static void F_92 ( struct V_121 * V_3 )
{
F_93 ( F_86 ( V_3 ) ) ;
}
static int F_94 ( struct V_124 * V_124 , struct V_121 * V_3 )
{
struct V_2 * V_7 = F_86 ( V_3 ) ;
struct V_6 * V_6 ;
if ( V_7 == F_85 () )
return - V_104 ;
if ( ! F_95 ( V_125 ) )
return - V_104 ;
if ( V_125 -> V_126 -> V_127 != 1 )
return - V_104 ;
if ( ! F_78 ( V_7 , V_106 ) )
return - V_29 ;
V_6 = F_24 () ;
if ( ! V_6 )
return - V_31 ;
F_93 ( V_6 -> V_7 ) ;
F_5 ( V_6 , F_89 ( V_7 ) ) ;
return F_96 ( V_6 ) ;
}
struct V_121 * F_97 ( struct V_121 * V_3 )
{
struct V_2 * V_128 = F_85 () ;
struct V_2 * V_20 , * V_129 ;
V_20 = V_129 = V_3 -> V_35 -> V_20 ( V_3 ) ;
for (; ; ) {
if ( ! V_129 )
return F_98 ( - V_29 ) ;
if ( V_129 == V_128 )
break;
V_129 = V_129 -> V_38 ;
}
return & F_89 ( V_20 ) -> V_3 ;
}
static struct V_2 * F_99 ( struct V_121 * V_3 )
{
return F_86 ( V_3 ) -> V_38 ;
}
static T_12 int F_100 ( void )
{
V_32 = F_101 ( V_2 , V_130 ) ;
return 0 ;
}
