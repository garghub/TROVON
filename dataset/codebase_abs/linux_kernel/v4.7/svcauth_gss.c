static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return V_2 -> V_4 == V_3 -> V_4 && 0 == memcmp ( V_2 -> V_5 , V_3 -> V_5 , V_2 -> V_4 ) ;
}
static void F_2 ( struct V_6 * V_7 )
{
F_3 ( V_7 -> V_8 . V_5 ) ;
F_3 ( V_7 -> V_9 . V_5 ) ;
F_3 ( V_7 -> V_10 . V_5 ) ;
F_3 ( V_7 -> V_11 . V_5 ) ;
}
static void F_4 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_5 ( V_13 , struct V_6 , V_14 . V_13 ) ;
F_2 ( V_7 ) ;
F_3 ( V_7 ) ;
}
static inline int F_6 ( struct V_6 * V_15 )
{
return F_7 ( V_15 -> V_8 . V_5 , V_15 -> V_8 . V_4 , V_16 )
^ F_7 ( V_15 -> V_9 . V_5 , V_15 -> V_9 . V_4 , V_16 ) ;
}
static int F_8 ( struct V_17 * V_2 , struct V_17 * V_3 )
{
struct V_6 * V_15 = F_5 ( V_2 , struct V_6 , V_14 ) ;
struct V_6 * V_18 = F_5 ( V_3 , struct V_6 , V_14 ) ;
return F_1 ( & V_15 -> V_8 , & V_18 -> V_8 ) &&
F_1 ( & V_15 -> V_9 , & V_18 -> V_9 ) ;
}
static int F_9 ( struct V_1 * V_19 , char * V_20 , int V_4 )
{
V_19 -> V_4 = V_4 ;
V_19 -> V_5 = ( V_4 ? F_10 ( V_20 , V_4 , V_21 ) : NULL ) ;
if ( V_4 && ! V_19 -> V_5 )
return - V_22 ;
return 0 ;
}
static inline int F_11 ( struct V_1 * V_19 , struct V_1 * V_20 )
{
return F_9 ( V_19 , V_20 -> V_5 , V_20 -> V_4 ) ;
}
static void F_12 ( struct V_17 * V_23 , struct V_17 * V_24 )
{
struct V_6 * V_25 = F_5 ( V_23 , struct V_6 , V_14 ) ;
struct V_6 * V_15 = F_5 ( V_24 , struct V_6 , V_14 ) ;
V_25 -> V_10 . V_5 = NULL ;
V_25 -> V_10 . V_4 = 0 ;
V_25 -> V_11 . V_5 = NULL ;
V_25 -> V_11 . V_4 = 0 ;
V_25 -> V_8 . V_4 = V_15 -> V_8 . V_4 ;
V_15 -> V_8 . V_4 = 0 ;
V_25 -> V_9 . V_4 = V_15 -> V_9 . V_4 ;
V_15 -> V_9 . V_4 = 0 ;
V_25 -> V_8 . V_5 = V_15 -> V_8 . V_5 ;
V_15 -> V_8 . V_5 = NULL ;
V_25 -> V_9 . V_5 = V_15 -> V_9 . V_5 ;
V_15 -> V_9 . V_5 = NULL ;
}
static void F_13 ( struct V_17 * V_23 , struct V_17 * V_24 )
{
struct V_6 * V_25 = F_5 ( V_23 , struct V_6 , V_14 ) ;
struct V_6 * V_15 = F_5 ( V_24 , struct V_6 , V_14 ) ;
F_14 ( V_25 -> V_10 . V_5 || V_25 -> V_11 . V_5 ) ;
V_25 -> V_10 . V_4 = V_15 -> V_10 . V_4 ;
V_15 -> V_10 . V_4 = 0 ;
V_25 -> V_11 . V_4 = V_15 -> V_11 . V_4 ;
V_15 -> V_11 . V_4 = 0 ;
V_25 -> V_10 . V_5 = V_15 -> V_10 . V_5 ;
V_15 -> V_10 . V_5 = NULL ;
V_25 -> V_11 . V_5 = V_15 -> V_11 . V_5 ;
V_15 -> V_11 . V_5 = NULL ;
V_25 -> V_26 = V_15 -> V_26 ;
V_25 -> V_27 = V_15 -> V_27 ;
}
static struct V_17 * F_15 ( void )
{
struct V_6 * V_7 = F_16 ( sizeof( * V_7 ) , V_21 ) ;
if ( V_7 )
return & V_7 -> V_14 ;
else
return NULL ;
}
static void F_17 ( struct V_28 * V_29 ,
struct V_17 * V_14 ,
char * * V_30 , int * V_31 )
{
struct V_6 * V_7 = F_5 ( V_14 , struct V_6 , V_14 ) ;
F_18 ( V_30 , V_31 , V_7 -> V_8 . V_5 , V_7 -> V_8 . V_4 ) ;
F_18 ( V_30 , V_31 , V_7 -> V_9 . V_5 , V_7 -> V_9 . V_4 ) ;
( * V_30 ) [ - 1 ] = '\n' ;
}
static int F_19 ( struct V_28 * V_29 ,
char * V_32 , int V_33 )
{
char * V_34 = V_32 ;
char * V_35 ;
int V_4 ;
struct V_6 V_7 , * V_36 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_8 , V_34 , V_4 ) )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
V_38 = - V_39 ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_9 , V_34 , V_4 ) )
goto V_40;
V_36 = F_21 ( V_29 , & V_7 ) ;
if ( ! V_36 )
goto V_40;
V_7 . V_14 . V_41 = 0 ;
V_37 = F_22 ( & V_32 ) ;
V_38 = - V_39 ;
if ( V_37 == 0 )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 <= 0 )
goto V_40;
V_7 . V_26 = F_23 ( V_34 , & V_35 , 10 ) ;
if ( * V_35 )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 <= 0 )
goto V_40;
V_7 . V_27 = F_23 ( V_34 , & V_35 , 10 ) ;
if ( * V_35 )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_10 , V_34 , V_4 ) )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
V_38 = - V_39 ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_11 , V_34 , V_4 ) )
goto V_40;
V_7 . V_14 . V_42 = V_37 ;
V_36 = F_24 ( V_29 , & V_7 , V_36 ) ;
V_38 = 0 ;
V_40:
F_2 ( & V_7 ) ;
if ( V_36 )
F_25 ( & V_36 -> V_14 , V_29 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static struct V_6 * F_21 ( struct V_28 * V_29 , struct V_6 * V_15 )
{
struct V_17 * V_43 ;
int V_44 = F_6 ( V_15 ) ;
V_43 = F_26 ( V_29 , & V_15 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_6 , V_14 ) ;
else
return NULL ;
}
static struct V_6 * F_24 ( struct V_28 * V_29 , struct V_6 * V_25 , struct V_6 * V_45 )
{
struct V_17 * V_43 ;
int V_44 = F_6 ( V_25 ) ;
V_43 = F_27 ( V_29 , & V_25 -> V_14 ,
& V_45 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_6 , V_14 ) ;
else
return NULL ;
}
static void F_28 ( struct V_46 * V_47 )
{
F_3 ( V_47 -> V_48 . V_5 ) ;
if ( V_47 -> V_49 )
F_29 ( & V_47 -> V_49 ) ;
F_30 ( & V_47 -> V_50 ) ;
}
static void F_31 ( struct V_12 * V_13 )
{
struct V_46 * V_47 = F_5 ( V_13 , struct V_46 , V_14 . V_13 ) ;
F_28 ( V_47 ) ;
F_3 ( V_47 ) ;
}
static inline int
F_32 ( struct V_46 * V_47 )
{
return F_7 ( V_47 -> V_48 . V_5 , V_47 -> V_48 . V_4 , V_51 ) ;
}
static int
F_33 ( struct V_17 * V_2 , struct V_17 * V_3 )
{
struct V_46 * V_25 = F_5 ( V_2 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_3 , struct V_46 , V_14 ) ;
return F_1 ( & V_25 -> V_48 , & V_18 -> V_48 ) ;
}
static void
F_34 ( struct V_17 * V_23 , struct V_17 * V_52 )
{
struct V_46 * V_25 = F_5 ( V_23 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_52 , struct V_46 , V_14 ) ;
V_25 -> V_48 . V_4 = V_18 -> V_48 . V_4 ;
V_18 -> V_48 . V_4 = 0 ;
V_25 -> V_48 . V_5 = V_18 -> V_48 . V_5 ;
V_18 -> V_48 . V_5 = NULL ;
V_25 -> V_49 = NULL ;
F_35 ( & V_25 -> V_50 ) ;
}
static void
F_36 ( struct V_17 * V_23 , struct V_17 * V_52 )
{
struct V_46 * V_25 = F_5 ( V_23 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_52 , struct V_46 , V_14 ) ;
V_25 -> V_49 = V_18 -> V_49 ;
V_18 -> V_49 = NULL ;
memset ( & V_25 -> V_53 , 0 , sizeof( V_25 -> V_53 ) ) ;
F_37 ( & V_25 -> V_53 . V_54 ) ;
V_25 -> V_50 = V_18 -> V_50 ;
F_35 ( & V_18 -> V_50 ) ;
}
static struct V_17 *
F_38 ( void )
{
struct V_46 * V_47 = F_16 ( sizeof( * V_47 ) , V_21 ) ;
if ( V_47 )
return & V_47 -> V_14 ;
else
return NULL ;
}
static int F_39 ( struct V_28 * V_29 ,
char * V_32 , int V_33 )
{
char * V_34 = V_32 ;
int V_55 ;
int V_4 , V_56 ;
struct V_46 V_47 , * V_57 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
struct V_58 * V_59 = NULL ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 ) goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_47 . V_48 , V_34 , V_4 ) )
goto V_40;
V_47 . V_14 . V_41 = 0 ;
V_37 = F_22 ( & V_32 ) ;
V_38 = - V_39 ;
if ( V_37 == 0 )
goto V_40;
V_57 = F_40 ( V_29 , & V_47 ) ;
if ( ! V_57 )
goto V_40;
V_56 = F_41 ( & V_32 , & V_55 ) ;
if ( V_56 == - V_39 )
goto V_40;
if ( V_56 == - V_60 )
F_42 ( V_61 , & V_47 . V_14 . V_41 ) ;
else {
int V_62 , V_63 ;
V_47 . V_50 . V_64 = F_43 ( & V_65 , V_55 ) ;
if ( F_41 ( & V_32 , & V_55 ) )
goto V_40;
V_47 . V_50 . V_66 = F_44 ( & V_65 , V_55 ) ;
if ( F_41 ( & V_32 , & V_62 ) )
goto V_40;
if ( V_62 < 0 || V_62 > V_67 )
goto V_40;
V_38 = - V_22 ;
V_47 . V_50 . V_68 = F_45 ( V_62 ) ;
if ( V_47 . V_50 . V_68 == NULL )
goto V_40;
V_38 = - V_39 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
T_2 V_69 ;
if ( F_41 ( & V_32 , & V_55 ) )
goto V_40;
V_69 = F_44 ( & V_65 , V_55 ) ;
if ( ! F_46 ( V_69 ) )
goto V_40;
F_47 ( V_47 . V_50 . V_68 , V_63 ) = V_69 ;
}
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_59 = V_47 . V_50 . V_70 = F_48 ( V_34 ) ;
V_38 = - V_71 ;
if ( ! V_59 )
goto V_40;
V_38 = - V_39 ;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = F_49 ( V_34 , V_4 , V_59 , & V_47 . V_49 ,
NULL , V_21 ) ;
if ( V_38 )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 > 0 ) {
V_47 . V_50 . V_72 = F_50 ( V_34 , V_21 ) ;
if ( ! V_47 . V_50 . V_72 ) {
V_38 = - V_22 ;
goto V_40;
}
}
}
V_47 . V_14 . V_42 = V_37 ;
V_57 = F_51 ( V_29 , & V_47 , V_57 ) ;
V_38 = 0 ;
V_40:
F_28 ( & V_47 ) ;
if ( V_57 )
F_25 ( & V_57 -> V_14 , V_29 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static struct V_46 * F_40 ( struct V_28 * V_29 , struct V_46 * V_15 )
{
struct V_17 * V_43 ;
int V_44 = F_32 ( V_15 ) ;
V_43 = F_26 ( V_29 , & V_15 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_46 , V_14 ) ;
else
return NULL ;
}
static struct V_46 * F_51 ( struct V_28 * V_29 , struct V_46 * V_25 , struct V_46 * V_45 )
{
struct V_17 * V_43 ;
int V_44 = F_32 ( V_25 ) ;
V_43 = F_27 ( V_29 , & V_25 -> V_14 ,
& V_45 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_46 , V_14 ) ;
else
return NULL ;
}
static struct V_46 *
F_52 ( struct V_28 * V_29 , struct V_1 * V_48 )
{
struct V_46 V_47 ;
struct V_46 * V_73 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_48 . V_5 = V_48 -> V_5 ;
V_47 . V_48 . V_4 = V_48 -> V_4 ;
V_73 = F_40 ( V_29 , & V_47 ) ;
if ( ! V_73 )
return NULL ;
if ( F_53 ( V_29 , & V_73 -> V_14 , NULL ) )
return NULL ;
return V_73 ;
}
static int
F_54 ( struct V_46 * V_47 , int V_74 )
{
struct V_75 * V_76 = & V_47 -> V_53 ;
F_55 ( & V_76 -> V_54 ) ;
if ( V_74 > V_76 -> V_77 ) {
if ( V_74 >= V_76 -> V_77 + V_78 ) {
memset ( V_76 -> V_79 , 0 , sizeof( V_76 -> V_79 ) ) ;
V_76 -> V_77 = V_74 ;
} else while ( V_76 -> V_77 < V_74 ) {
V_76 -> V_77 ++ ;
F_56 ( V_76 -> V_77 % V_78 , V_76 -> V_79 ) ;
}
F_57 ( V_74 % V_78 , V_76 -> V_79 ) ;
goto V_80;
} else if ( V_74 <= V_76 -> V_77 - V_78 ) {
goto V_81;
}
if ( F_58 ( V_74 % V_78 , V_76 -> V_79 ) )
goto V_81;
V_80:
F_59 ( & V_76 -> V_54 ) ;
return 1 ;
V_81:
F_59 ( & V_76 -> V_54 ) ;
return 0 ;
}
static inline T_3 F_60 ( T_3 V_63 )
{
return ( V_63 + 3 ) & ~ 3 ;
}
static inline int
F_61 ( struct V_82 * V_83 , struct V_1 * V_84 )
{
int V_85 ;
if ( V_83 -> V_86 < 4 )
return - 1 ;
V_84 -> V_4 = F_62 ( V_83 ) ;
V_85 = F_60 ( V_84 -> V_4 ) ;
if ( V_83 -> V_86 < V_85 )
return - 1 ;
V_84 -> V_5 = V_83 -> V_87 ;
V_83 -> V_87 += V_85 ;
V_83 -> V_86 -= V_85 ;
return 0 ;
}
static inline int
F_63 ( struct V_82 * V_88 , struct V_1 * V_84 )
{
T_4 * V_89 ;
if ( V_88 -> V_86 + 4 > V_90 )
return - 1 ;
F_64 ( V_88 , V_84 -> V_4 ) ;
V_89 = V_88 -> V_87 + V_88 -> V_86 ;
V_88 -> V_86 += F_60 ( V_84 -> V_4 ) ;
if ( V_88 -> V_86 > V_90 )
return - 1 ;
memcpy ( V_89 , V_84 -> V_5 , V_84 -> V_4 ) ;
memset ( V_89 + V_84 -> V_4 , 0 , F_60 ( V_84 -> V_4 ) - V_84 -> V_4 ) ;
return 0 ;
}
static int
F_65 ( struct V_91 * V_92 , struct V_46 * V_47 ,
T_5 * V_93 , struct V_94 * V_95 , T_5 * V_96 )
{
struct V_97 * V_98 = V_47 -> V_49 ;
struct V_99 V_100 ;
struct V_1 V_101 ;
T_3 V_102 = 0 ;
struct V_82 * V_83 = & V_92 -> V_103 . V_104 [ 0 ] ;
struct V_82 V_105 ;
V_105 . V_87 = V_93 ;
V_105 . V_86 = ( T_4 * ) V_83 -> V_87 - ( T_4 * ) V_93 ;
F_66 ( & V_105 , & V_100 ) ;
* V_96 = V_106 ;
if ( V_83 -> V_86 < 4 )
return V_107 ;
V_102 = F_62 ( V_83 ) ;
if ( V_102 != V_108 )
return V_107 ;
if ( F_61 ( V_83 , & V_101 ) )
return V_107 ;
if ( V_92 -> V_109 )
return V_110 ;
if ( F_67 ( V_98 , & V_100 , & V_101 ) != V_111 ) {
* V_96 = V_112 ;
return V_107 ;
}
if ( V_95 -> V_113 > V_114 ) {
F_68 ( L_1
L_2 , V_95 -> V_113 ) ;
* V_96 = V_115 ;
return V_107 ;
}
if ( ! F_54 ( V_47 , V_95 -> V_113 ) ) {
F_68 ( L_1
L_3 , V_95 -> V_113 ) ;
return V_116 ;
}
return V_110 ;
}
static int
F_69 ( struct V_91 * V_92 )
{
T_5 * V_89 ;
F_64 ( V_92 -> V_117 . V_104 , V_118 ) ;
V_89 = V_92 -> V_117 . V_104 -> V_87 + V_92 -> V_117 . V_104 -> V_86 ;
* V_89 ++ = 0 ;
if ( ! F_70 ( V_92 , V_89 ) )
return - 1 ;
return 0 ;
}
static int
F_71 ( struct V_91 * V_92 , struct V_97 * V_98 , T_3 V_119 )
{
T_5 V_120 ;
T_3 V_121 ;
struct V_99 V_122 ;
struct V_1 V_123 ;
T_5 * V_89 ;
struct V_82 V_105 ;
F_64 ( V_92 -> V_117 . V_104 , V_108 ) ;
V_120 = F_72 ( V_119 ) ;
V_105 . V_87 = & V_120 ;
V_105 . V_86 = sizeof( V_120 ) ;
F_66 ( & V_105 , & V_122 ) ;
V_89 = V_92 -> V_117 . V_104 -> V_87 + V_92 -> V_117 . V_104 -> V_86 ;
V_123 . V_5 = ( T_4 * ) ( V_89 + 1 ) ;
V_121 = F_73 ( V_98 , & V_122 , & V_123 ) ;
if ( V_121 != V_111 )
return - 1 ;
* V_89 ++ = F_72 ( V_123 . V_4 ) ;
memset ( ( T_4 * ) V_89 + V_123 . V_4 , 0 , F_60 ( V_123 . V_4 ) - V_123 . V_4 ) ;
V_89 += F_74 ( V_123 . V_4 ) ;
if ( ! F_70 ( V_92 , V_89 ) )
return - 1 ;
return 0 ;
}
static struct V_124 *
F_75 ( struct V_97 * V_125 , T_3 V_126 )
{
char * V_127 ;
V_127 = F_76 ( V_125 -> V_128 , V_126 ) ;
if ( ! V_127 )
return NULL ;
return F_77 ( V_127 ) ;
}
T_3 F_78 ( struct V_124 * V_129 )
{
struct V_130 * V_131 = F_5 ( V_129 , struct V_130 , V_14 ) ;
return V_131 -> V_132 ;
}
int
F_79 ( T_3 V_132 , char * V_127 )
{
struct V_130 * V_25 ;
struct V_124 * V_133 ;
int V_134 = - V_22 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
goto V_40;
F_80 ( & V_25 -> V_14 . V_13 ) ;
V_25 -> V_14 . V_127 = F_50 ( V_127 , V_21 ) ;
if ( ! V_25 -> V_14 . V_127 )
goto V_135;
V_25 -> V_14 . V_136 = & V_137 ;
V_25 -> V_132 = V_132 ;
V_134 = 0 ;
V_133 = F_81 ( V_127 , & V_25 -> V_14 ) ;
if ( V_133 != & V_25 -> V_14 ) {
F_82 ( V_133 ) ;
F_3 ( V_25 -> V_14 . V_127 ) ;
goto V_135;
}
return 0 ;
V_135:
F_3 ( V_25 ) ;
V_40:
return V_134 ;
}
static inline int
F_83 ( struct V_99 * V_34 , int V_138 , T_3 * V_139 )
{
T_5 V_140 ;
int V_38 ;
V_38 = F_84 ( V_34 , V_138 , & V_140 , sizeof( * V_139 ) ) ;
if ( V_38 )
return V_38 ;
* V_139 = F_85 ( V_140 ) ;
return 0 ;
}
static int
F_86 ( struct V_91 * V_92 , struct V_99 * V_34 , T_3 V_119 , struct V_97 * V_125 )
{
int V_134 = - V_39 ;
T_3 V_141 , V_121 ;
struct V_1 V_123 ;
struct V_99 V_142 ;
if ( V_92 -> V_109 )
return 0 ;
V_141 = F_62 ( & V_34 -> V_104 [ 0 ] ) ;
if ( V_141 & 3 )
return V_134 ;
if ( V_141 > V_34 -> V_4 )
return V_134 ;
if ( F_87 ( V_34 , & V_142 , 0 , V_141 ) )
F_88 () ;
if ( F_83 ( V_34 , V_141 , & V_123 . V_4 ) )
F_88 () ;
if ( V_123 . V_4 > V_143 )
return V_134 ;
V_123 . V_5 = F_16 ( V_123 . V_4 , V_21 ) ;
if ( ! V_123 . V_5 )
return V_134 ;
if ( F_84 ( V_34 , V_141 + 4 , V_123 . V_5 , V_123 . V_4 ) )
goto V_40;
V_121 = F_67 ( V_125 , & V_142 , & V_123 ) ;
if ( V_121 != V_111 )
goto V_40;
if ( F_62 ( & V_34 -> V_104 [ 0 ] ) != V_119 )
goto V_40;
F_89 ( V_34 , F_60 ( V_123 . V_4 ) + 4 ) ;
V_134 = 0 ;
V_40:
F_3 ( V_123 . V_5 ) ;
return V_134 ;
}
static inline int
F_90 ( struct V_99 * V_34 )
{
return V_34 -> V_104 [ 0 ] . V_86 + V_34 -> V_144 + V_34 -> V_145 [ 0 ] . V_86 ;
}
static void
F_91 ( struct V_99 * V_34 , int V_146 )
{
if ( V_34 -> V_144 == 0 ) {
V_34 -> V_104 [ 0 ] . V_86 -= V_146 ;
}
}
static int
F_92 ( struct V_91 * V_92 , struct V_99 * V_34 , T_3 V_119 , struct V_97 * V_125 )
{
T_3 V_147 , V_121 ;
int V_146 , V_148 , V_149 , V_150 ;
F_93 ( V_151 , & V_92 -> V_152 ) ;
V_147 = F_62 ( & V_34 -> V_104 [ 0 ] ) ;
if ( V_92 -> V_109 ) {
goto V_153;
}
V_149 = F_90 ( V_34 ) ;
if ( V_147 > V_149 )
return - V_39 ;
V_146 = V_149 - V_147 ;
V_34 -> V_4 -= V_146 ;
F_91 ( V_34 , V_146 ) ;
V_148 = V_34 -> V_4 ;
V_34 -> V_4 = V_147 ;
V_121 = F_94 ( V_125 , 0 , V_34 ) ;
V_146 = V_147 - V_34 -> V_4 ;
V_34 -> V_4 = V_148 ;
V_34 -> V_4 -= V_146 ;
V_150 = V_34 -> V_104 [ 0 ] . V_86 % 4 ;
if ( V_150 ) {
V_34 -> V_154 = V_155 ;
F_95 ( V_34 , V_150 ) ;
F_91 ( V_34 , V_146 ) ;
}
if ( V_121 != V_111 )
return - V_39 ;
V_153:
if ( F_62 ( & V_34 -> V_104 [ 0 ] ) != V_119 )
return - V_39 ;
return 0 ;
}
static int
F_96 ( struct V_91 * V_92 )
{
struct V_156 * V_157 = V_92 -> V_158 ;
struct V_46 * V_47 = V_157 -> V_47 ;
struct V_94 * V_95 = & V_157 -> V_159 ;
int V_134 ;
V_92 -> V_160 = F_75 ( V_47 -> V_49 , V_95 -> V_161 ) ;
if ( V_92 -> V_160 == NULL )
return V_107 ;
V_134 = F_97 ( V_92 ) ;
if ( V_134 == V_116 || V_134 == V_162 )
return V_134 ;
return V_110 ;
}
static inline int
F_98 ( struct V_28 * V_29 , struct V_91 * V_92 ,
struct V_1 * V_10 , int * V_26 )
{
struct V_46 * V_47 ;
int V_163 ;
if ( * V_26 != V_111 )
return F_69 ( V_92 ) ;
V_47 = F_52 ( V_29 , V_10 ) ;
if ( V_47 == NULL ) {
* V_26 = V_164 ;
return F_69 ( V_92 ) ;
}
V_163 = F_71 ( V_92 , V_47 -> V_49 , V_78 ) ;
F_25 ( & V_47 -> V_14 , V_29 ) ;
return V_163 ;
}
static inline int
F_99 ( struct V_94 * V_95 ,
struct V_82 * V_83 , T_5 * V_96 ,
struct V_1 * V_8 )
{
* V_96 = V_106 ;
if ( V_83 -> V_86 < 2 * 4 )
return V_107 ;
if ( F_62 ( V_83 ) != V_118 )
return V_107 ;
if ( F_62 ( V_83 ) != 0 )
return V_107 ;
* V_96 = V_165 ;
if ( V_95 -> V_166 == V_167 && V_95 -> V_168 . V_4 != 0 )
return V_107 ;
if ( F_11 ( V_8 , & V_95 -> V_168 ) )
return V_162 ;
* V_96 = V_106 ;
return 0 ;
}
static inline int
F_100 ( struct V_94 * V_95 ,
struct V_82 * V_83 , T_5 * V_96 ,
struct V_1 * V_8 ,
struct V_1 * V_9 )
{
struct V_1 V_169 ;
int V_170 ;
V_170 = F_99 ( V_95 , V_83 , V_96 , V_8 ) ;
if ( V_170 )
return V_170 ;
if ( F_61 ( V_83 , & V_169 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_107 ;
}
if ( F_11 ( V_9 , & V_169 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_162 ;
}
return 0 ;
}
static inline int
F_101 ( struct V_91 * V_92 ,
struct V_94 * V_95 , T_5 * V_96 ,
struct V_1 * V_8 ,
struct V_171 * V_9 )
{
struct V_82 * V_83 = & V_92 -> V_103 . V_104 [ 0 ] ;
T_3 V_172 ;
int V_170 ;
V_170 = F_99 ( V_95 , V_83 , V_96 , V_8 ) ;
if ( V_170 )
return V_170 ;
V_172 = F_62 ( V_83 ) ;
if ( V_172 > ( V_83 -> V_86 + V_92 -> V_103 . V_144 ) )
return V_107 ;
V_9 -> V_173 = V_92 -> V_174 ;
V_9 -> V_175 = ( V_176 ) V_83 -> V_87 & ~ V_177 ;
V_9 -> V_144 = V_172 ;
return 0 ;
}
static inline int
F_102 ( struct V_82 * V_88 , T_6 V_178 ,
struct V_1 * V_10 , struct V_1 * V_11 ,
int V_26 , int V_27 )
{
if ( V_88 -> V_86 + 4 > V_178 )
return - 1 ;
F_64 ( V_88 , V_179 ) ;
if ( F_63 ( V_88 , V_10 ) )
return - 1 ;
if ( V_88 -> V_86 + 3 * 4 > V_178 )
return - 1 ;
F_64 ( V_88 , V_26 ) ;
F_64 ( V_88 , V_27 ) ;
F_64 ( V_88 , V_78 ) ;
if ( F_63 ( V_88 , V_11 ) )
return - 1 ;
return 0 ;
}
static int F_103 ( struct V_91 * V_92 ,
struct V_94 * V_95 , T_5 * V_96 )
{
struct V_82 * V_83 = & V_92 -> V_103 . V_104 [ 0 ] ;
struct V_82 * V_88 = & V_92 -> V_117 . V_104 [ 0 ] ;
struct V_6 * V_36 , V_180 ;
int V_181 ;
struct V_182 * V_183 = F_104 ( V_92 -> V_184 -> V_185 , V_186 ) ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_181 = F_100 ( V_95 , V_83 , V_96 ,
& V_180 . V_8 , & V_180 . V_9 ) ;
if ( V_181 )
return V_181 ;
V_36 = F_21 ( V_183 -> V_187 , & V_180 ) ;
F_2 ( & V_180 ) ;
if ( ! V_36 )
return V_162 ;
if ( F_53 ( V_183 -> V_187 , & V_36 -> V_14 , & V_92 -> V_188 ) < 0 )
return V_162 ;
V_181 = V_162 ;
if ( F_98 ( V_183 -> V_189 , V_92 ,
& V_36 -> V_10 , & V_36 -> V_26 ) )
goto V_40;
if ( F_102 ( V_88 , V_90 ,
& V_36 -> V_10 , & V_36 -> V_11 ,
V_36 -> V_26 , V_36 -> V_27 ) )
goto V_40;
V_181 = V_190 ;
V_40:
F_25 ( & V_36 -> V_14 , V_183 -> V_187 ) ;
return V_181 ;
}
static int F_105 ( struct V_28 * V_29 ,
struct V_191 * V_192 ,
T_7 * V_48 )
{
struct V_46 V_47 , * V_57 = NULL ;
static T_8 V_193 ;
long long V_194 ;
struct V_58 * V_59 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_38 = - V_22 ;
V_194 = F_106 ( & V_193 ) ;
* V_48 = V_194 ;
if ( F_9 ( & V_47 . V_48 , ( char * ) V_48 , sizeof( T_7 ) ) )
goto V_40;
V_57 = F_40 ( V_29 , & V_47 ) ;
if ( ! V_57 )
goto V_40;
if ( ! V_192 -> V_195 ) {
F_68 ( L_4 ) ;
goto V_40;
} else {
V_47 . V_50 = V_192 -> V_196 ;
memset ( & V_192 -> V_196 , 0 , sizeof( struct V_197 ) ) ;
V_38 = - V_71 ;
V_59 = F_107 ( & V_192 -> V_198 ) ;
if ( ! V_59 )
goto V_40;
V_47 . V_50 . V_70 = V_59 ;
V_38 = - V_39 ;
V_38 = F_49 ( V_192 -> V_10 . V_5 ,
V_192 -> V_10 . V_4 ,
V_59 , & V_47 . V_49 ,
& V_37 , V_21 ) ;
if ( V_38 )
goto V_40;
}
V_47 . V_14 . V_42 = V_37 ;
V_57 = F_51 ( V_29 , & V_47 , V_57 ) ;
V_38 = 0 ;
V_40:
F_28 ( & V_47 ) ;
if ( V_57 )
F_25 ( & V_57 -> V_14 , V_29 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static int F_108 ( struct V_91 * V_92 ,
struct V_94 * V_95 , T_5 * V_96 )
{
struct V_82 * V_88 = & V_92 -> V_117 . V_104 [ 0 ] ;
struct V_1 V_199 ;
struct V_191 V_192 ;
T_7 V_48 ;
int V_38 ;
int V_181 ;
struct V_200 * V_200 = V_92 -> V_184 -> V_185 ;
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
memset ( & V_192 , 0 , sizeof( V_192 ) ) ;
V_181 = F_101 ( V_92 , V_95 , V_96 ,
& V_192 . V_8 , & V_192 . V_9 ) ;
if ( V_181 )
return V_181 ;
V_181 = V_162 ;
V_38 = F_109 ( V_200 , & V_192 ) ;
if ( V_38 )
goto V_40;
F_68 ( L_5 ,
V_192 . V_26 ) ;
switch ( V_192 . V_26 ) {
case V_201 :
V_199 = V_192 . V_10 ;
break;
case V_111 :
V_38 = F_105 ( V_183 -> V_189 , & V_192 , & V_48 ) ;
if ( V_38 )
goto V_40;
V_199 . V_5 = ( T_4 * ) & V_48 ;
V_199 . V_4 = sizeof( V_48 ) ;
break;
default:
V_181 = V_162 ;
goto V_40;
}
if ( F_98 ( V_183 -> V_189 , V_92 ,
& V_199 , & V_192 . V_26 ) )
goto V_40;
if ( F_102 ( V_88 , V_90 ,
& V_199 , & V_192 . V_11 ,
V_192 . V_26 , V_192 . V_27 ) )
goto V_40;
V_181 = V_190 ;
V_40:
F_110 ( & V_192 ) ;
return V_181 ;
}
static int F_111 ( struct V_200 * V_200 , int type )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
int V_181 ;
F_112 ( type != 0 && type != 1 ) ;
V_181 = F_113 ( & V_183 -> V_202 , - 1 , type ) ;
if ( V_181 != - 1 && V_181 != type )
return - V_203 ;
return 0 ;
}
static bool V_202 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
if ( V_183 -> V_202 == - 1 )
F_111 ( V_200 , 0 ) ;
return V_183 -> V_202 ;
}
static T_9 F_114 ( struct V_204 * V_204 , const char T_10 * V_34 ,
T_6 V_205 , T_11 * V_206 )
{
struct V_200 * V_200 = F_115 ( F_116 ( V_204 ) ) ;
char V_207 [ 20 ] ;
unsigned long V_63 ;
int V_170 ;
if ( * V_206 || V_205 > sizeof( V_207 ) - 1 )
return - V_39 ;
if ( F_117 ( V_207 , V_34 , V_205 ) )
return - V_208 ;
V_207 [ V_205 ] = 0 ;
V_170 = F_118 ( V_207 , 0 , & V_63 ) ;
if ( V_170 )
return V_170 ;
if ( V_63 != 1 )
return - V_39 ;
V_170 = F_119 ( V_200 ) ;
if ( V_170 )
return V_170 ;
V_170 = F_111 ( V_200 , 1 ) ;
if ( V_170 )
return V_170 ;
return V_205 ;
}
static T_9 F_120 ( struct V_204 * V_204 , char T_10 * V_34 ,
T_6 V_205 , T_11 * V_206 )
{
struct V_200 * V_200 = F_115 ( F_116 ( V_204 ) ) ;
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
unsigned long V_89 = * V_206 ;
char V_207 [ 10 ] ;
T_6 V_4 ;
snprintf ( V_207 , sizeof( V_207 ) , L_6 , V_183 -> V_202 ) ;
V_4 = strlen ( V_207 ) ;
if ( V_89 >= V_4 )
return 0 ;
V_4 -= V_89 ;
if ( V_4 > V_205 )
V_4 = V_205 ;
if ( F_121 ( V_34 , ( void * ) ( V_207 + V_89 ) , V_4 ) )
return - V_208 ;
* V_206 += V_4 ;
return V_4 ;
}
static int F_122 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
struct V_209 * * V_89 = & V_183 -> V_210 ;
V_183 -> V_202 = - 1 ;
* V_89 = F_123 ( L_7 , V_211 | V_212 | V_213 ,
V_183 -> V_214 ,
& V_215 , V_200 ) ;
if ( ! * V_89 )
return - V_22 ;
F_124 ( V_183 ) ;
return 0 ;
}
static void F_125 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
if ( V_183 -> V_210 ) {
F_126 ( L_7 , V_183 -> V_214 ) ;
F_127 ( V_183 ) ;
}
}
static int F_122 ( struct V_200 * V_200 )
{
return 0 ;
}
static void F_125 ( struct V_200 * V_200 ) {}
static int
F_128 ( struct V_91 * V_92 , T_5 * V_96 )
{
struct V_82 * V_83 = & V_92 -> V_103 . V_104 [ 0 ] ;
struct V_82 * V_88 = & V_92 -> V_117 . V_104 [ 0 ] ;
T_3 V_216 ;
struct V_156 * V_157 = V_92 -> V_158 ;
struct V_94 * V_95 ;
struct V_46 * V_47 = NULL ;
T_5 * V_93 ;
T_5 * V_217 = V_88 -> V_87 + V_88 -> V_86 ;
int V_181 ;
struct V_182 * V_183 = F_104 ( V_92 -> V_184 -> V_185 , V_186 ) ;
F_68 ( L_8 ,
V_83 -> V_86 ) ;
* V_96 = V_165 ;
if ( ! V_157 )
V_157 = F_16 ( sizeof( * V_157 ) , V_21 ) ;
if ( ! V_157 )
goto V_218;
V_92 -> V_158 = V_157 ;
V_157 -> V_219 = NULL ;
V_157 -> V_47 = NULL ;
V_95 = & V_157 -> V_159 ;
V_93 = V_83 -> V_87 ;
V_93 -= 7 ;
if ( V_83 -> V_86 < 5 * 4 )
goto V_218;
V_216 = F_62 ( V_83 ) ;
if ( F_62 ( V_83 ) != V_220 )
goto V_218;
V_95 -> V_166 = F_62 ( V_83 ) ;
V_95 -> V_113 = F_62 ( V_83 ) ;
V_95 -> V_161 = F_62 ( V_83 ) ;
if ( F_61 ( V_83 , & V_95 -> V_168 ) )
goto V_218;
if ( V_216 != F_60 ( V_95 -> V_168 . V_4 ) + 5 * 4 )
goto V_218;
if ( ( V_95 -> V_166 != V_221 ) && ( V_92 -> V_222 != 0 ) )
goto V_218;
* V_96 = V_106 ;
switch ( V_95 -> V_166 ) {
case V_167 :
case V_223 :
if ( V_202 ( F_129 ( V_92 ) ) )
return F_108 ( V_92 , V_95 , V_96 ) ;
else
return F_103 ( V_92 , V_95 , V_96 ) ;
case V_221 :
case V_224 :
* V_96 = V_112 ;
V_47 = F_52 ( V_183 -> V_189 , & V_95 -> V_168 ) ;
if ( ! V_47 )
goto V_218;
switch ( F_65 ( V_92 , V_47 , V_93 , V_95 , V_96 ) ) {
case V_110 :
break;
case V_107 :
goto V_218;
case V_116 :
goto V_81;
}
break;
default:
* V_96 = V_225 ;
goto V_218;
}
switch ( V_95 -> V_166 ) {
case V_224 :
if ( F_71 ( V_92 , V_47 -> V_49 , V_95 -> V_113 ) )
goto V_218;
V_47 -> V_14 . V_42 = F_130 () ;
F_42 ( V_61 , & V_47 -> V_14 . V_41 ) ;
if ( V_88 -> V_86 + 4 > V_90 )
goto V_81;
F_64 ( V_88 , V_179 ) ;
goto V_226;
case V_221 :
* V_96 = V_115 ;
V_157 -> V_219 = V_88 -> V_87 + V_88 -> V_86 ;
if ( F_71 ( V_92 , V_47 -> V_49 , V_95 -> V_113 ) )
goto V_218;
V_92 -> V_227 = V_47 -> V_50 ;
F_131 ( V_47 -> V_50 . V_68 ) ;
* V_96 = V_165 ;
switch ( V_95 -> V_161 ) {
case V_228 :
break;
case V_229 :
F_64 ( V_88 , 0 ) ;
F_64 ( V_88 , 0 ) ;
if ( F_86 ( V_92 , & V_92 -> V_103 ,
V_95 -> V_113 , V_47 -> V_49 ) )
goto V_230;
V_92 -> V_231 = V_143 ;
break;
case V_232 :
F_64 ( V_88 , 0 ) ;
F_64 ( V_88 , 0 ) ;
if ( F_92 ( V_92 , & V_92 -> V_103 ,
V_95 -> V_113 , V_47 -> V_49 ) )
goto V_230;
V_92 -> V_231 = V_143 * 2 ;
break;
default:
goto V_218;
}
V_157 -> V_47 = V_47 ;
F_132 ( & V_47 -> V_14 ) ;
V_92 -> V_227 . V_233 = F_133 (
V_47 -> V_49 -> V_128 ,
V_234 ,
V_95 -> V_161 ) ;
V_181 = V_110 ;
goto V_40;
}
V_230:
V_181 = V_235 ;
goto V_40;
V_218:
F_70 ( V_92 , V_217 ) ;
V_181 = V_107 ;
goto V_40;
V_226:
V_181 = V_190 ;
goto V_40;
V_81:
V_181 = V_116 ;
V_40:
if ( V_47 )
F_25 ( & V_47 -> V_14 , V_183 -> V_189 ) ;
return V_181 ;
}
static T_5 *
F_134 ( struct V_99 * V_236 , struct V_156 * V_237 )
{
T_5 * V_89 ;
T_3 V_238 ;
V_89 = V_237 -> V_219 ;
V_237 -> V_219 = NULL ;
if ( * ( V_89 - 1 ) != V_239 )
return NULL ;
V_89 += 1 ;
V_238 = F_85 ( * V_89 ++ ) ;
V_89 += F_74 ( V_238 ) ;
memcpy ( V_89 , V_89 + 2 , 4 ) ;
if ( * V_89 != V_239 ) {
V_236 -> V_104 [ 0 ] . V_86 -= 2 * 4 ;
return NULL ;
}
V_89 ++ ;
return V_89 ;
}
static inline int
F_135 ( struct V_91 * V_92 )
{
struct V_156 * V_237 = (struct V_156 * ) V_92 -> V_158 ;
struct V_94 * V_95 = & V_237 -> V_159 ;
struct V_99 * V_236 = & V_92 -> V_117 ;
struct V_99 V_142 ;
struct V_1 V_123 ;
struct V_82 * V_88 ;
T_5 * V_89 ;
int V_240 , V_141 ;
int V_134 = - V_39 ;
V_89 = F_134 ( V_236 , V_237 ) ;
if ( V_89 == NULL )
goto V_40;
V_240 = ( T_4 * ) ( V_89 + 1 ) - ( T_4 * ) V_236 -> V_104 [ 0 ] . V_87 ;
V_141 = V_236 -> V_4 - V_240 ;
F_14 ( V_141 % 4 ) ;
* V_89 ++ = F_72 ( V_141 ) ;
* V_89 ++ = F_72 ( V_95 -> V_113 ) ;
if ( F_87 ( V_236 , & V_142 , V_240 , V_141 ) )
F_88 () ;
if ( V_236 -> V_145 [ 0 ] . V_87 == NULL ) {
if ( V_236 -> V_104 [ 0 ] . V_86 + V_143 > V_90 )
goto V_241;
V_236 -> V_145 [ 0 ] . V_87 = V_236 -> V_104 [ 0 ] . V_87
+ V_236 -> V_104 [ 0 ] . V_86 ;
V_236 -> V_145 [ 0 ] . V_86 = 0 ;
}
V_88 = & V_236 -> V_145 [ 0 ] ;
V_123 . V_5 = ( T_4 * ) V_88 -> V_87 + V_88 -> V_86 + 4 ;
if ( F_73 ( V_237 -> V_47 -> V_49 , & V_142 , & V_123 ) )
goto V_241;
F_64 ( V_88 , V_123 . V_4 ) ;
memset ( V_123 . V_5 + V_123 . V_4 , 0 ,
F_60 ( V_123 . V_4 ) - V_123 . V_4 ) ;
V_88 -> V_86 += F_74 ( V_123 . V_4 ) << 2 ;
V_236 -> V_4 += F_74 ( V_123 . V_4 ) << 2 ;
F_14 ( V_88 -> V_86 > V_90 ) ;
V_40:
V_134 = 0 ;
V_241:
return V_134 ;
}
static inline int
F_136 ( struct V_91 * V_92 )
{
struct V_156 * V_237 = (struct V_156 * ) V_92 -> V_158 ;
struct V_94 * V_95 = & V_237 -> V_159 ;
struct V_99 * V_236 = & V_92 -> V_117 ;
struct V_242 * * V_243 = NULL ;
T_5 * V_89 , * V_4 ;
int V_150 ;
int V_146 ;
V_89 = F_134 ( V_236 , V_237 ) ;
if ( V_89 == NULL )
return 0 ;
V_4 = V_89 ++ ;
V_150 = ( T_4 * ) V_89 - ( T_4 * ) V_236 -> V_104 [ 0 ] . V_87 ;
* V_89 ++ = F_72 ( V_95 -> V_113 ) ;
V_243 = V_236 -> V_173 ;
if ( V_236 -> V_145 [ 0 ] . V_87 ) {
F_14 ( V_236 -> V_145 [ 0 ] . V_87 >= V_236 -> V_104 [ 0 ] . V_87
+ V_90 ) ;
F_14 ( V_236 -> V_145 [ 0 ] . V_87 < V_236 -> V_104 [ 0 ] . V_87 ) ;
if ( V_236 -> V_145 [ 0 ] . V_86 + V_236 -> V_104 [ 0 ] . V_86
+ 2 * V_143 > V_90 )
return - V_22 ;
memmove ( V_236 -> V_145 [ 0 ] . V_87 + V_143 ,
V_236 -> V_145 [ 0 ] . V_87 ,
V_236 -> V_145 [ 0 ] . V_86 ) ;
V_236 -> V_145 [ 0 ] . V_87 += V_143 ;
}
if ( V_236 -> V_145 [ 0 ] . V_87 == NULL ) {
if ( V_236 -> V_104 [ 0 ] . V_86 + 2 * V_143 > V_90 )
return - V_22 ;
V_236 -> V_145 [ 0 ] . V_87 = V_236 -> V_104 [ 0 ] . V_87
+ V_236 -> V_104 [ 0 ] . V_86 + V_143 ;
V_236 -> V_145 [ 0 ] . V_86 = 0 ;
}
if ( F_137 ( V_237 -> V_47 -> V_49 , V_150 , V_236 , V_243 ) )
return - V_22 ;
* V_4 = F_72 ( V_236 -> V_4 - V_150 ) ;
V_146 = 3 - ( ( V_236 -> V_4 - V_150 - 1 ) & 3 ) ;
V_89 = ( T_5 * ) ( V_236 -> V_145 [ 0 ] . V_87 + V_236 -> V_145 [ 0 ] . V_86 ) ;
memset ( V_89 , 0 , V_146 ) ;
V_236 -> V_145 [ 0 ] . V_86 += V_146 ;
V_236 -> V_4 += V_146 ;
return 0 ;
}
static int
F_138 ( struct V_91 * V_92 )
{
struct V_156 * V_237 = (struct V_156 * ) V_92 -> V_158 ;
struct V_94 * V_95 = & V_237 -> V_159 ;
struct V_99 * V_236 = & V_92 -> V_117 ;
int V_134 = - V_39 ;
struct V_182 * V_183 = F_104 ( V_92 -> V_184 -> V_185 , V_186 ) ;
if ( V_95 -> V_166 != V_221 )
goto V_40;
if ( V_237 -> V_219 == NULL )
goto V_40;
V_236 -> V_4 = F_90 ( V_236 ) ;
switch ( V_95 -> V_161 ) {
case V_228 :
break;
case V_229 :
V_134 = F_135 ( V_92 ) ;
if ( V_134 )
goto V_241;
break;
case V_232 :
V_134 = F_136 ( V_92 ) ;
if ( V_134 )
goto V_241;
break;
}
V_40:
V_134 = 0 ;
V_241:
if ( V_92 -> V_244 )
F_82 ( V_92 -> V_244 ) ;
V_92 -> V_244 = NULL ;
if ( V_92 -> V_160 )
F_82 ( V_92 -> V_160 ) ;
V_92 -> V_160 = NULL ;
if ( V_92 -> V_227 . V_68 )
F_139 ( V_92 -> V_227 . V_68 ) ;
V_92 -> V_227 . V_68 = NULL ;
if ( V_237 -> V_47 )
F_25 ( & V_237 -> V_47 -> V_14 , V_183 -> V_189 ) ;
V_237 -> V_47 = NULL ;
return V_134 ;
}
static void
F_140 ( struct V_124 * V_129 )
{
struct V_130 * V_131 = F_5 ( V_129 , struct V_130 , V_14 ) ;
F_3 ( V_129 -> V_127 ) ;
F_3 ( V_131 ) ;
}
static int F_141 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
struct V_28 * V_29 ;
int V_245 ;
V_29 = F_142 ( & V_246 , V_200 ) ;
if ( F_143 ( V_29 ) )
return F_144 ( V_29 ) ;
V_245 = F_145 ( V_29 , V_200 ) ;
if ( V_245 ) {
F_146 ( V_29 , V_200 ) ;
return V_245 ;
}
V_183 -> V_187 = V_29 ;
return 0 ;
}
static void F_147 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
struct V_28 * V_29 = V_183 -> V_187 ;
V_183 -> V_187 = NULL ;
F_148 ( V_29 ) ;
F_149 ( V_29 , V_200 ) ;
F_146 ( V_29 , V_200 ) ;
}
static int F_150 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
struct V_28 * V_29 ;
int V_245 ;
V_29 = F_142 ( & V_247 , V_200 ) ;
if ( F_143 ( V_29 ) )
return F_144 ( V_29 ) ;
V_245 = F_145 ( V_29 , V_200 ) ;
if ( V_245 ) {
F_146 ( V_29 , V_200 ) ;
return V_245 ;
}
V_183 -> V_189 = V_29 ;
return 0 ;
}
static void F_151 ( struct V_200 * V_200 )
{
struct V_182 * V_183 = F_104 ( V_200 , V_186 ) ;
struct V_28 * V_29 = V_183 -> V_189 ;
V_183 -> V_189 = NULL ;
F_148 ( V_29 ) ;
F_149 ( V_29 , V_200 ) ;
F_146 ( V_29 , V_200 ) ;
}
int
F_152 ( struct V_200 * V_200 )
{
int V_56 ;
V_56 = F_150 ( V_200 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_141 ( V_200 ) ;
if ( V_56 )
goto V_248;
V_56 = F_122 ( V_200 ) ;
if ( V_56 )
goto V_249;
return 0 ;
V_249:
F_125 ( V_200 ) ;
V_248:
F_151 ( V_200 ) ;
return V_56 ;
}
void
F_153 ( struct V_200 * V_200 )
{
F_125 ( V_200 ) ;
F_147 ( V_200 ) ;
F_151 ( V_200 ) ;
}
int
F_154 ( void )
{
return F_155 ( V_108 , & V_137 ) ;
}
void
F_156 ( void )
{
F_157 ( V_108 ) ;
}
