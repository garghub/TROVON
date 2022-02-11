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
V_38 = - V_22 ;
V_47 . V_50 . V_67 = F_45 ( V_62 ) ;
if ( V_47 . V_50 . V_67 == NULL )
goto V_40;
V_38 = - V_39 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
T_2 V_68 ;
if ( F_41 ( & V_32 , & V_55 ) )
goto V_40;
V_68 = F_44 ( & V_65 , V_55 ) ;
if ( ! F_46 ( V_68 ) )
goto V_40;
F_47 ( V_47 . V_50 . V_67 , V_63 ) = V_68 ;
}
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_59 = V_47 . V_50 . V_69 = F_48 ( V_34 ) ;
V_38 = - V_70 ;
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
V_47 . V_50 . V_71 = F_50 ( V_34 , V_21 ) ;
if ( ! V_47 . V_50 . V_71 ) {
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
struct V_46 * V_72 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( F_9 ( & V_47 . V_48 , V_48 -> V_5 , V_48 -> V_4 ) )
return NULL ;
V_72 = F_40 ( V_29 , & V_47 ) ;
F_28 ( & V_47 ) ;
if ( ! V_72 )
return NULL ;
if ( F_53 ( V_29 , & V_72 -> V_14 , NULL ) )
return NULL ;
return V_72 ;
}
static int
F_54 ( struct V_46 * V_47 , int V_73 )
{
struct V_74 * V_75 = & V_47 -> V_53 ;
F_55 ( & V_75 -> V_54 ) ;
if ( V_73 > V_75 -> V_76 ) {
if ( V_73 >= V_75 -> V_76 + V_77 ) {
memset ( V_75 -> V_78 , 0 , sizeof( V_75 -> V_78 ) ) ;
V_75 -> V_76 = V_73 ;
} else while ( V_75 -> V_76 < V_73 ) {
V_75 -> V_76 ++ ;
F_56 ( V_75 -> V_76 % V_77 , V_75 -> V_78 ) ;
}
F_57 ( V_73 % V_77 , V_75 -> V_78 ) ;
goto V_79;
} else if ( V_73 <= V_75 -> V_76 - V_77 ) {
goto V_80;
}
if ( F_58 ( V_73 % V_77 , V_75 -> V_78 ) )
goto V_80;
V_79:
F_59 ( & V_75 -> V_54 ) ;
return 1 ;
V_80:
F_59 ( & V_75 -> V_54 ) ;
return 0 ;
}
static inline T_3 F_60 ( T_3 V_63 )
{
return ( V_63 + 3 ) & ~ 3 ;
}
static inline int
F_61 ( struct V_81 * V_82 , struct V_1 * V_83 )
{
int V_84 ;
if ( V_82 -> V_85 < 4 )
return - 1 ;
V_83 -> V_4 = F_62 ( V_82 ) ;
V_84 = F_60 ( V_83 -> V_4 ) ;
if ( V_82 -> V_85 < V_84 )
return - 1 ;
V_83 -> V_5 = V_82 -> V_86 ;
V_82 -> V_86 += V_84 ;
V_82 -> V_85 -= V_84 ;
return 0 ;
}
static inline int
F_63 ( struct V_81 * V_87 , struct V_1 * V_83 )
{
T_4 * V_88 ;
if ( V_87 -> V_85 + 4 > V_89 )
return - 1 ;
F_64 ( V_87 , V_83 -> V_4 ) ;
V_88 = V_87 -> V_86 + V_87 -> V_85 ;
V_87 -> V_85 += F_60 ( V_83 -> V_4 ) ;
if ( V_87 -> V_85 > V_89 )
return - 1 ;
memcpy ( V_88 , V_83 -> V_5 , V_83 -> V_4 ) ;
memset ( V_88 + V_83 -> V_4 , 0 , F_60 ( V_83 -> V_4 ) - V_83 -> V_4 ) ;
return 0 ;
}
static int
F_65 ( struct V_90 * V_91 , struct V_46 * V_47 ,
T_5 * V_92 , struct V_93 * V_94 , T_5 * V_95 )
{
struct V_96 * V_97 = V_47 -> V_49 ;
struct V_98 V_99 ;
struct V_1 V_100 ;
T_3 V_101 = 0 ;
struct V_81 * V_82 = & V_91 -> V_102 . V_103 [ 0 ] ;
struct V_81 V_104 ;
V_104 . V_86 = V_92 ;
V_104 . V_85 = ( T_4 * ) V_82 -> V_86 - ( T_4 * ) V_92 ;
F_66 ( & V_104 , & V_99 ) ;
* V_95 = V_105 ;
if ( V_82 -> V_85 < 4 )
return V_106 ;
V_101 = F_62 ( V_82 ) ;
if ( V_101 != V_107 )
return V_106 ;
if ( F_61 ( V_82 , & V_100 ) )
return V_106 ;
if ( V_91 -> V_108 )
return V_109 ;
if ( F_67 ( V_97 , & V_99 , & V_100 ) != V_110 ) {
* V_95 = V_111 ;
return V_106 ;
}
if ( V_94 -> V_112 > V_113 ) {
F_68 ( L_1
L_2 , V_94 -> V_112 ) ;
* V_95 = V_114 ;
return V_106 ;
}
if ( ! F_54 ( V_47 , V_94 -> V_112 ) ) {
F_68 ( L_1
L_3 , V_94 -> V_112 ) ;
return V_115 ;
}
return V_109 ;
}
static int
F_69 ( struct V_90 * V_91 )
{
T_5 * V_88 ;
F_64 ( V_91 -> V_116 . V_103 , V_117 ) ;
V_88 = V_91 -> V_116 . V_103 -> V_86 + V_91 -> V_116 . V_103 -> V_85 ;
* V_88 ++ = 0 ;
if ( ! F_70 ( V_91 , V_88 ) )
return - 1 ;
return 0 ;
}
static int
F_71 ( struct V_90 * V_91 , struct V_96 * V_97 , T_3 V_118 )
{
T_5 V_119 ;
T_3 V_120 ;
struct V_98 V_121 ;
struct V_1 V_122 ;
T_5 * V_88 ;
struct V_81 V_104 ;
F_64 ( V_91 -> V_116 . V_103 , V_107 ) ;
V_119 = F_72 ( V_118 ) ;
V_104 . V_86 = & V_119 ;
V_104 . V_85 = sizeof( V_119 ) ;
F_66 ( & V_104 , & V_121 ) ;
V_88 = V_91 -> V_116 . V_103 -> V_86 + V_91 -> V_116 . V_103 -> V_85 ;
V_122 . V_5 = ( T_4 * ) ( V_88 + 1 ) ;
V_120 = F_73 ( V_97 , & V_121 , & V_122 ) ;
if ( V_120 != V_110 )
return - 1 ;
* V_88 ++ = F_72 ( V_122 . V_4 ) ;
memset ( ( T_4 * ) V_88 + V_122 . V_4 , 0 , F_60 ( V_122 . V_4 ) - V_122 . V_4 ) ;
V_88 += F_74 ( V_122 . V_4 ) ;
if ( ! F_70 ( V_91 , V_88 ) )
return - 1 ;
return 0 ;
}
static struct V_123 *
F_75 ( struct V_96 * V_124 , T_3 V_125 )
{
char * V_126 ;
V_126 = F_76 ( V_124 -> V_127 , V_125 ) ;
if ( ! V_126 )
return NULL ;
return F_77 ( V_126 ) ;
}
T_3 F_78 ( struct V_123 * V_128 )
{
struct V_129 * V_130 = F_5 ( V_128 , struct V_129 , V_14 ) ;
return V_130 -> V_131 ;
}
int
F_79 ( T_3 V_131 , char * V_126 )
{
struct V_129 * V_25 ;
struct V_123 * V_132 ;
int V_133 = - V_22 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
goto V_40;
F_80 ( & V_25 -> V_14 . V_13 ) ;
V_25 -> V_14 . V_126 = F_50 ( V_126 , V_21 ) ;
if ( ! V_25 -> V_14 . V_126 )
goto V_134;
V_25 -> V_14 . V_135 = & V_136 ;
V_25 -> V_131 = V_131 ;
V_133 = 0 ;
V_132 = F_81 ( V_126 , & V_25 -> V_14 ) ;
if ( V_132 != & V_25 -> V_14 ) {
F_82 ( V_132 ) ;
F_3 ( V_25 -> V_14 . V_126 ) ;
goto V_134;
}
return 0 ;
V_134:
F_3 ( V_25 ) ;
V_40:
return V_133 ;
}
static inline int
F_83 ( struct V_98 * V_34 , int V_137 , T_3 * V_138 )
{
T_5 V_139 ;
int V_38 ;
V_38 = F_84 ( V_34 , V_137 , & V_139 , sizeof( * V_138 ) ) ;
if ( V_38 )
return V_38 ;
* V_138 = F_85 ( V_139 ) ;
return 0 ;
}
static int
F_86 ( struct V_90 * V_91 , struct V_98 * V_34 , T_3 V_118 , struct V_96 * V_124 )
{
int V_133 = - V_39 ;
T_3 V_140 , V_120 ;
struct V_1 V_122 ;
struct V_98 V_141 ;
if ( V_91 -> V_108 )
return 0 ;
V_140 = F_62 ( & V_34 -> V_103 [ 0 ] ) ;
if ( V_140 & 3 )
return V_133 ;
if ( V_140 > V_34 -> V_4 )
return V_133 ;
if ( F_87 ( V_34 , & V_141 , 0 , V_140 ) )
F_88 () ;
if ( F_83 ( V_34 , V_140 , & V_122 . V_4 ) )
F_88 () ;
if ( V_122 . V_4 > V_142 )
return V_133 ;
V_122 . V_5 = F_16 ( V_122 . V_4 , V_21 ) ;
if ( ! V_122 . V_5 )
return V_133 ;
if ( F_84 ( V_34 , V_140 + 4 , V_122 . V_5 , V_122 . V_4 ) )
goto V_40;
V_120 = F_67 ( V_124 , & V_141 , & V_122 ) ;
if ( V_120 != V_110 )
goto V_40;
if ( F_62 ( & V_34 -> V_103 [ 0 ] ) != V_118 )
goto V_40;
F_89 ( V_34 , V_122 . V_4 + 4 ) ;
V_133 = 0 ;
V_40:
F_3 ( V_122 . V_5 ) ;
return V_133 ;
}
static inline int
F_90 ( struct V_98 * V_34 )
{
return V_34 -> V_103 [ 0 ] . V_85 + V_34 -> V_143 + V_34 -> V_144 [ 0 ] . V_85 ;
}
static void
F_91 ( struct V_98 * V_34 , int V_145 )
{
if ( V_34 -> V_143 == 0 ) {
V_34 -> V_103 [ 0 ] . V_85 -= V_145 ;
}
}
static int
F_92 ( struct V_90 * V_91 , struct V_98 * V_34 , T_3 V_118 , struct V_96 * V_124 )
{
T_3 V_146 , V_120 ;
int V_145 , V_147 , V_148 , V_149 ;
V_91 -> V_150 = false ;
V_146 = F_62 ( & V_34 -> V_103 [ 0 ] ) ;
if ( V_91 -> V_108 ) {
goto V_151;
}
V_148 = F_90 ( V_34 ) ;
if ( V_146 > V_148 )
return - V_39 ;
V_145 = V_148 - V_146 ;
V_34 -> V_4 -= V_145 ;
F_91 ( V_34 , V_145 ) ;
V_147 = V_34 -> V_4 ;
V_34 -> V_4 = V_146 ;
V_120 = F_93 ( V_124 , 0 , V_34 ) ;
V_145 = V_146 - V_34 -> V_4 ;
V_34 -> V_4 = V_147 ;
V_34 -> V_4 -= V_145 ;
V_149 = V_34 -> V_103 [ 0 ] . V_85 % 4 ;
if ( V_149 ) {
V_34 -> V_152 = V_153 ;
F_94 ( V_34 , V_149 ) ;
F_91 ( V_34 , V_145 ) ;
}
if ( V_120 != V_110 )
return - V_39 ;
V_151:
if ( F_62 ( & V_34 -> V_103 [ 0 ] ) != V_118 )
return - V_39 ;
return 0 ;
}
static int
F_95 ( struct V_90 * V_91 )
{
struct V_154 * V_155 = V_91 -> V_156 ;
struct V_46 * V_47 = V_155 -> V_47 ;
struct V_93 * V_94 = & V_155 -> V_157 ;
int V_133 ;
V_91 -> V_158 = F_75 ( V_47 -> V_49 , V_94 -> V_159 ) ;
if ( V_91 -> V_158 == NULL )
return V_106 ;
V_133 = F_96 ( V_91 ) ;
if ( V_133 == V_115 || V_133 == V_160 )
return V_133 ;
return V_109 ;
}
static inline int
F_97 ( struct V_28 * V_29 , struct V_90 * V_91 ,
struct V_1 * V_10 , int * V_26 )
{
struct V_46 * V_47 ;
int V_161 ;
if ( * V_26 != V_110 )
return F_69 ( V_91 ) ;
V_47 = F_52 ( V_29 , V_10 ) ;
if ( V_47 == NULL ) {
* V_26 = V_162 ;
return F_69 ( V_91 ) ;
}
V_161 = F_71 ( V_91 , V_47 -> V_49 , V_77 ) ;
F_25 ( & V_47 -> V_14 , V_29 ) ;
return V_161 ;
}
static inline int
F_98 ( struct V_93 * V_94 ,
struct V_81 * V_82 , T_5 * V_95 ,
struct V_1 * V_8 )
{
* V_95 = V_105 ;
if ( V_82 -> V_85 < 2 * 4 )
return V_106 ;
if ( F_62 ( V_82 ) != V_117 )
return V_106 ;
if ( F_62 ( V_82 ) != 0 )
return V_106 ;
* V_95 = V_163 ;
if ( V_94 -> V_164 == V_165 && V_94 -> V_166 . V_4 != 0 )
return V_106 ;
if ( F_11 ( V_8 , & V_94 -> V_166 ) )
return V_160 ;
* V_95 = V_105 ;
return 0 ;
}
static inline int
F_99 ( struct V_93 * V_94 ,
struct V_81 * V_82 , T_5 * V_95 ,
struct V_1 * V_8 ,
struct V_1 * V_9 )
{
struct V_1 V_167 ;
int V_168 ;
V_168 = F_98 ( V_94 , V_82 , V_95 , V_8 ) ;
if ( V_168 )
return V_168 ;
if ( F_61 ( V_82 , & V_167 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_106 ;
}
if ( F_11 ( V_9 , & V_167 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_160 ;
}
return 0 ;
}
static inline int
F_100 ( struct V_90 * V_91 ,
struct V_93 * V_94 , T_5 * V_95 ,
struct V_1 * V_8 ,
struct V_169 * V_9 )
{
struct V_81 * V_82 = & V_91 -> V_102 . V_103 [ 0 ] ;
T_3 V_170 ;
int V_168 ;
V_168 = F_98 ( V_94 , V_82 , V_95 , V_8 ) ;
if ( V_168 )
return V_168 ;
V_170 = F_62 ( V_82 ) ;
if ( V_170 > ( V_82 -> V_85 + V_91 -> V_102 . V_143 ) )
return V_106 ;
V_9 -> V_171 = V_91 -> V_172 ;
V_9 -> V_173 = ( V_174 ) V_82 -> V_86 & ~ V_175 ;
V_9 -> V_143 = V_170 ;
return 0 ;
}
static inline int
F_101 ( struct V_81 * V_87 , T_6 V_176 ,
struct V_1 * V_10 , struct V_1 * V_11 ,
int V_26 , int V_27 )
{
if ( V_87 -> V_85 + 4 > V_176 )
return - 1 ;
F_64 ( V_87 , V_177 ) ;
if ( F_63 ( V_87 , V_10 ) )
return - 1 ;
if ( V_87 -> V_85 + 3 * 4 > V_176 )
return - 1 ;
F_64 ( V_87 , V_26 ) ;
F_64 ( V_87 , V_27 ) ;
F_64 ( V_87 , V_77 ) ;
if ( F_63 ( V_87 , V_11 ) )
return - 1 ;
return 0 ;
}
static int F_102 ( struct V_90 * V_91 ,
struct V_93 * V_94 , T_5 * V_95 )
{
struct V_81 * V_82 = & V_91 -> V_102 . V_103 [ 0 ] ;
struct V_81 * V_87 = & V_91 -> V_116 . V_103 [ 0 ] ;
struct V_6 * V_36 , V_178 ;
int V_179 ;
struct V_180 * V_181 = F_103 ( V_91 -> V_182 -> V_183 , V_184 ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_179 = F_99 ( V_94 , V_82 , V_95 ,
& V_178 . V_8 , & V_178 . V_9 ) ;
if ( V_179 )
return V_179 ;
V_36 = F_21 ( V_181 -> V_185 , & V_178 ) ;
F_2 ( & V_178 ) ;
if ( ! V_36 )
return V_160 ;
if ( F_53 ( V_181 -> V_185 , & V_36 -> V_14 , & V_91 -> V_186 ) < 0 )
return V_160 ;
V_179 = V_160 ;
if ( F_97 ( V_181 -> V_187 , V_91 ,
& V_36 -> V_10 , & V_36 -> V_26 ) )
goto V_40;
if ( F_101 ( V_87 , V_89 ,
& V_36 -> V_10 , & V_36 -> V_11 ,
V_36 -> V_26 , V_36 -> V_27 ) )
goto V_40;
V_179 = V_188 ;
V_40:
F_25 ( & V_36 -> V_14 , V_181 -> V_185 ) ;
return V_179 ;
}
static int F_104 ( struct V_28 * V_29 ,
struct V_189 * V_190 ,
T_7 * V_48 )
{
struct V_46 V_47 , * V_57 = NULL ;
static T_8 V_191 ;
long long V_192 ;
struct V_58 * V_59 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_38 = - V_22 ;
V_192 = F_105 ( & V_191 ) ;
* V_48 = V_192 ;
if ( F_9 ( & V_47 . V_48 , ( char * ) V_48 , sizeof( T_7 ) ) )
goto V_40;
V_57 = F_40 ( V_29 , & V_47 ) ;
if ( ! V_57 )
goto V_40;
if ( ! V_190 -> V_193 ) {
F_68 ( L_4 ) ;
goto V_40;
} else {
V_47 . V_50 = V_190 -> V_194 ;
memset ( & V_190 -> V_194 , 0 , sizeof( struct V_195 ) ) ;
V_38 = - V_70 ;
V_59 = F_106 ( & V_190 -> V_196 ) ;
if ( ! V_59 )
goto V_40;
V_47 . V_50 . V_69 = V_59 ;
V_38 = - V_39 ;
V_38 = F_49 ( V_190 -> V_10 . V_5 ,
V_190 -> V_10 . V_4 ,
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
static int F_107 ( struct V_90 * V_91 ,
struct V_93 * V_94 , T_5 * V_95 )
{
struct V_81 * V_87 = & V_91 -> V_116 . V_103 [ 0 ] ;
struct V_1 V_197 ;
struct V_189 V_190 ;
T_7 V_48 ;
int V_38 ;
int V_179 ;
struct V_198 * V_198 = V_91 -> V_182 -> V_183 ;
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_179 = F_100 ( V_91 , V_94 , V_95 ,
& V_190 . V_8 , & V_190 . V_9 ) ;
if ( V_179 )
return V_179 ;
V_179 = V_160 ;
V_38 = F_108 ( V_198 , & V_190 ) ;
if ( V_38 )
goto V_40;
F_68 ( L_5 ,
V_190 . V_26 ) ;
switch ( V_190 . V_26 ) {
case V_199 :
V_197 = V_190 . V_10 ;
break;
case V_110 :
V_38 = F_104 ( V_181 -> V_187 , & V_190 , & V_48 ) ;
if ( V_38 )
goto V_40;
V_197 . V_5 = ( T_4 * ) & V_48 ;
V_197 . V_4 = sizeof( V_48 ) ;
break;
default:
V_179 = V_160 ;
goto V_40;
}
if ( F_97 ( V_181 -> V_187 , V_91 ,
& V_197 , & V_190 . V_26 ) )
goto V_40;
if ( F_101 ( V_87 , V_89 ,
& V_197 , & V_190 . V_11 ,
V_190 . V_26 , V_190 . V_27 ) )
goto V_40;
V_179 = V_188 ;
V_40:
F_109 ( & V_190 ) ;
return V_179 ;
}
static int F_110 ( struct V_198 * V_198 , int type )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
int V_179 ;
F_111 ( type != 0 && type != 1 ) ;
V_179 = F_112 ( & V_181 -> V_200 , - 1 , type ) ;
if ( V_179 != - 1 && V_179 != type )
return - V_201 ;
return 0 ;
}
static bool V_200 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
if ( V_181 -> V_200 == - 1 )
F_110 ( V_198 , 0 ) ;
return V_181 -> V_200 ;
}
static T_9 F_113 ( struct V_202 * V_202 , const char T_10 * V_34 ,
T_6 V_203 , T_11 * V_204 )
{
struct V_198 * V_198 = F_114 ( F_115 ( V_202 ) ) ;
char V_205 [ 20 ] ;
unsigned long V_63 ;
int V_168 ;
if ( * V_204 || V_203 > sizeof( V_205 ) - 1 )
return - V_39 ;
if ( F_116 ( V_205 , V_34 , V_203 ) )
return - V_206 ;
V_205 [ V_203 ] = 0 ;
V_168 = F_117 ( V_205 , 0 , & V_63 ) ;
if ( V_168 )
return V_168 ;
if ( V_63 != 1 )
return - V_39 ;
V_168 = F_118 ( V_198 ) ;
if ( V_168 )
return V_168 ;
V_168 = F_110 ( V_198 , 1 ) ;
if ( V_168 )
return V_168 ;
return V_203 ;
}
static T_9 F_119 ( struct V_202 * V_202 , char T_10 * V_34 ,
T_6 V_203 , T_11 * V_204 )
{
struct V_198 * V_198 = F_114 ( F_115 ( V_202 ) ) ;
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
unsigned long V_88 = * V_204 ;
char V_205 [ 10 ] ;
T_6 V_4 ;
snprintf ( V_205 , sizeof( V_205 ) , L_6 , V_181 -> V_200 ) ;
V_4 = strlen ( V_205 ) ;
if ( V_88 >= V_4 )
return 0 ;
V_4 -= V_88 ;
if ( V_4 > V_203 )
V_4 = V_203 ;
if ( F_120 ( V_34 , ( void * ) ( V_205 + V_88 ) , V_4 ) )
return - V_206 ;
* V_204 += V_4 ;
return V_4 ;
}
static int F_121 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
struct V_207 * * V_88 = & V_181 -> V_208 ;
V_181 -> V_200 = - 1 ;
* V_88 = F_122 ( L_7 , V_209 | V_210 | V_211 ,
V_181 -> V_212 ,
& V_213 , V_198 ) ;
if ( ! * V_88 )
return - V_22 ;
F_123 ( V_181 ) ;
return 0 ;
}
static void F_124 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
if ( V_181 -> V_208 ) {
F_125 ( L_7 , V_181 -> V_212 ) ;
F_126 ( V_181 ) ;
}
}
static int F_121 ( struct V_198 * V_198 )
{
return 0 ;
}
static void F_124 ( struct V_198 * V_198 ) {}
static int
F_127 ( struct V_90 * V_91 , T_5 * V_95 )
{
struct V_81 * V_82 = & V_91 -> V_102 . V_103 [ 0 ] ;
struct V_81 * V_87 = & V_91 -> V_116 . V_103 [ 0 ] ;
T_3 V_214 ;
struct V_154 * V_155 = V_91 -> V_156 ;
struct V_93 * V_94 ;
struct V_46 * V_47 = NULL ;
T_5 * V_92 ;
T_5 * V_215 = V_87 -> V_86 + V_87 -> V_85 ;
int V_179 ;
struct V_180 * V_181 = F_103 ( V_91 -> V_182 -> V_183 , V_184 ) ;
F_68 ( L_8 ,
V_82 -> V_85 ) ;
* V_95 = V_163 ;
if ( ! V_155 )
V_155 = F_16 ( sizeof( * V_155 ) , V_21 ) ;
if ( ! V_155 )
goto V_216;
V_91 -> V_156 = V_155 ;
V_155 -> V_217 = NULL ;
V_155 -> V_47 = NULL ;
V_94 = & V_155 -> V_157 ;
V_92 = V_82 -> V_86 ;
V_92 -= 7 ;
if ( V_82 -> V_85 < 5 * 4 )
goto V_216;
V_214 = F_62 ( V_82 ) ;
if ( F_62 ( V_82 ) != V_218 )
goto V_216;
V_94 -> V_164 = F_62 ( V_82 ) ;
V_94 -> V_112 = F_62 ( V_82 ) ;
V_94 -> V_159 = F_62 ( V_82 ) ;
if ( F_61 ( V_82 , & V_94 -> V_166 ) )
goto V_216;
if ( V_214 != F_60 ( V_94 -> V_166 . V_4 ) + 5 * 4 )
goto V_216;
if ( ( V_94 -> V_164 != V_219 ) && ( V_91 -> V_220 != 0 ) )
goto V_216;
* V_95 = V_105 ;
switch ( V_94 -> V_164 ) {
case V_165 :
case V_221 :
if ( V_200 ( F_128 ( V_91 ) ) )
return F_107 ( V_91 , V_94 , V_95 ) ;
else
return F_102 ( V_91 , V_94 , V_95 ) ;
case V_219 :
case V_222 :
* V_95 = V_111 ;
V_47 = F_52 ( V_181 -> V_187 , & V_94 -> V_166 ) ;
if ( ! V_47 )
goto V_216;
switch ( F_65 ( V_91 , V_47 , V_92 , V_94 , V_95 ) ) {
case V_109 :
break;
case V_106 :
goto V_216;
case V_115 :
goto V_80;
}
break;
default:
* V_95 = V_223 ;
goto V_216;
}
switch ( V_94 -> V_164 ) {
case V_222 :
if ( F_71 ( V_91 , V_47 -> V_49 , V_94 -> V_112 ) )
goto V_216;
V_47 -> V_14 . V_42 = F_129 () ;
F_42 ( V_61 , & V_47 -> V_14 . V_41 ) ;
if ( V_87 -> V_85 + 4 > V_89 )
goto V_80;
F_64 ( V_87 , V_177 ) ;
goto V_224;
case V_219 :
* V_95 = V_114 ;
V_155 -> V_217 = V_87 -> V_86 + V_87 -> V_85 ;
if ( F_71 ( V_91 , V_47 -> V_49 , V_94 -> V_112 ) )
goto V_216;
V_91 -> V_225 = V_47 -> V_50 ;
F_130 ( V_47 -> V_50 . V_67 ) ;
* V_95 = V_163 ;
switch ( V_94 -> V_159 ) {
case V_226 :
break;
case V_227 :
F_64 ( V_87 , 0 ) ;
F_64 ( V_87 , 0 ) ;
if ( F_86 ( V_91 , & V_91 -> V_102 ,
V_94 -> V_112 , V_47 -> V_49 ) )
goto V_228;
V_91 -> V_229 = V_142 ;
break;
case V_230 :
F_64 ( V_87 , 0 ) ;
F_64 ( V_87 , 0 ) ;
if ( F_92 ( V_91 , & V_91 -> V_102 ,
V_94 -> V_112 , V_47 -> V_49 ) )
goto V_228;
V_91 -> V_229 = V_142 * 2 ;
break;
default:
goto V_216;
}
V_155 -> V_47 = V_47 ;
F_131 ( & V_47 -> V_14 ) ;
V_91 -> V_225 . V_231 = F_132 (
V_47 -> V_49 -> V_127 ,
V_232 ,
V_94 -> V_159 ) ;
V_179 = V_109 ;
goto V_40;
}
V_228:
V_179 = V_233 ;
goto V_40;
V_216:
F_70 ( V_91 , V_215 ) ;
V_179 = V_106 ;
goto V_40;
V_224:
V_179 = V_188 ;
goto V_40;
V_80:
V_179 = V_115 ;
V_40:
if ( V_47 )
F_25 ( & V_47 -> V_14 , V_181 -> V_187 ) ;
return V_179 ;
}
static T_5 *
F_133 ( struct V_98 * V_234 , struct V_154 * V_235 )
{
T_5 * V_88 ;
T_3 V_236 ;
V_88 = V_235 -> V_217 ;
V_235 -> V_217 = NULL ;
if ( * ( V_88 - 1 ) != V_237 )
return NULL ;
V_88 += 1 ;
V_236 = F_85 ( * V_88 ++ ) ;
V_88 += F_74 ( V_236 ) ;
memcpy ( V_88 , V_88 + 2 , 4 ) ;
if ( * V_88 != V_237 ) {
V_234 -> V_103 [ 0 ] . V_85 -= 2 * 4 ;
return NULL ;
}
V_88 ++ ;
return V_88 ;
}
static inline int
F_134 ( struct V_90 * V_91 )
{
struct V_154 * V_235 = (struct V_154 * ) V_91 -> V_156 ;
struct V_93 * V_94 = & V_235 -> V_157 ;
struct V_98 * V_234 = & V_91 -> V_116 ;
struct V_98 V_141 ;
struct V_1 V_122 ;
struct V_81 * V_87 ;
T_5 * V_88 ;
int V_238 , V_140 ;
int V_133 = - V_39 ;
V_88 = F_133 ( V_234 , V_235 ) ;
if ( V_88 == NULL )
goto V_40;
V_238 = ( T_4 * ) ( V_88 + 1 ) - ( T_4 * ) V_234 -> V_103 [ 0 ] . V_86 ;
V_140 = V_234 -> V_4 - V_238 ;
F_14 ( V_140 % 4 ) ;
* V_88 ++ = F_72 ( V_140 ) ;
* V_88 ++ = F_72 ( V_94 -> V_112 ) ;
if ( F_87 ( V_234 , & V_141 , V_238 , V_140 ) )
F_88 () ;
if ( V_234 -> V_144 [ 0 ] . V_86 == NULL ) {
if ( V_234 -> V_103 [ 0 ] . V_85 + V_142 > V_89 )
goto V_239;
V_234 -> V_144 [ 0 ] . V_86 = V_234 -> V_103 [ 0 ] . V_86
+ V_234 -> V_103 [ 0 ] . V_85 ;
V_234 -> V_144 [ 0 ] . V_85 = 0 ;
}
V_87 = & V_234 -> V_144 [ 0 ] ;
V_122 . V_5 = ( T_4 * ) V_87 -> V_86 + V_87 -> V_85 + 4 ;
if ( F_73 ( V_235 -> V_47 -> V_49 , & V_141 , & V_122 ) )
goto V_239;
F_64 ( V_87 , V_122 . V_4 ) ;
memset ( V_122 . V_5 + V_122 . V_4 , 0 ,
F_60 ( V_122 . V_4 ) - V_122 . V_4 ) ;
V_87 -> V_85 += F_74 ( V_122 . V_4 ) << 2 ;
V_234 -> V_4 += F_74 ( V_122 . V_4 ) << 2 ;
F_14 ( V_87 -> V_85 > V_89 ) ;
V_40:
V_133 = 0 ;
V_239:
return V_133 ;
}
static inline int
F_135 ( struct V_90 * V_91 )
{
struct V_154 * V_235 = (struct V_154 * ) V_91 -> V_156 ;
struct V_93 * V_94 = & V_235 -> V_157 ;
struct V_98 * V_234 = & V_91 -> V_116 ;
struct V_240 * * V_241 = NULL ;
T_5 * V_88 , * V_4 ;
int V_149 ;
int V_145 ;
V_88 = F_133 ( V_234 , V_235 ) ;
if ( V_88 == NULL )
return 0 ;
V_4 = V_88 ++ ;
V_149 = ( T_4 * ) V_88 - ( T_4 * ) V_234 -> V_103 [ 0 ] . V_86 ;
* V_88 ++ = F_72 ( V_94 -> V_112 ) ;
V_241 = V_234 -> V_171 ;
if ( V_234 -> V_144 [ 0 ] . V_86 ) {
F_14 ( V_234 -> V_144 [ 0 ] . V_86 >= V_234 -> V_103 [ 0 ] . V_86
+ V_89 ) ;
F_14 ( V_234 -> V_144 [ 0 ] . V_86 < V_234 -> V_103 [ 0 ] . V_86 ) ;
if ( V_234 -> V_144 [ 0 ] . V_85 + V_234 -> V_103 [ 0 ] . V_85
+ 2 * V_142 > V_89 )
return - V_22 ;
memmove ( V_234 -> V_144 [ 0 ] . V_86 + V_142 ,
V_234 -> V_144 [ 0 ] . V_86 ,
V_234 -> V_144 [ 0 ] . V_85 ) ;
V_234 -> V_144 [ 0 ] . V_86 += V_142 ;
}
if ( V_234 -> V_144 [ 0 ] . V_86 == NULL ) {
if ( V_234 -> V_103 [ 0 ] . V_85 + 2 * V_142 > V_89 )
return - V_22 ;
V_234 -> V_144 [ 0 ] . V_86 = V_234 -> V_103 [ 0 ] . V_86
+ V_234 -> V_103 [ 0 ] . V_85 + V_142 ;
V_234 -> V_144 [ 0 ] . V_85 = 0 ;
}
if ( F_136 ( V_235 -> V_47 -> V_49 , V_149 , V_234 , V_241 ) )
return - V_22 ;
* V_4 = F_72 ( V_234 -> V_4 - V_149 ) ;
V_145 = 3 - ( ( V_234 -> V_4 - V_149 - 1 ) & 3 ) ;
V_88 = ( T_5 * ) ( V_234 -> V_144 [ 0 ] . V_86 + V_234 -> V_144 [ 0 ] . V_85 ) ;
memset ( V_88 , 0 , V_145 ) ;
V_234 -> V_144 [ 0 ] . V_85 += V_145 ;
V_234 -> V_4 += V_145 ;
return 0 ;
}
static int
F_137 ( struct V_90 * V_91 )
{
struct V_154 * V_235 = (struct V_154 * ) V_91 -> V_156 ;
struct V_93 * V_94 = & V_235 -> V_157 ;
struct V_98 * V_234 = & V_91 -> V_116 ;
int V_133 = - V_39 ;
struct V_180 * V_181 = F_103 ( V_91 -> V_182 -> V_183 , V_184 ) ;
if ( V_94 -> V_164 != V_219 )
goto V_40;
if ( V_235 -> V_217 == NULL )
goto V_40;
V_234 -> V_4 = F_90 ( V_234 ) ;
switch ( V_94 -> V_159 ) {
case V_226 :
break;
case V_227 :
V_133 = F_134 ( V_91 ) ;
if ( V_133 )
goto V_239;
break;
case V_230 :
V_133 = F_135 ( V_91 ) ;
if ( V_133 )
goto V_239;
break;
}
V_40:
V_133 = 0 ;
V_239:
if ( V_91 -> V_242 )
F_82 ( V_91 -> V_242 ) ;
V_91 -> V_242 = NULL ;
if ( V_91 -> V_158 )
F_82 ( V_91 -> V_158 ) ;
V_91 -> V_158 = NULL ;
if ( V_91 -> V_225 . V_67 )
F_138 ( V_91 -> V_225 . V_67 ) ;
V_91 -> V_225 . V_67 = NULL ;
if ( V_235 -> V_47 )
F_25 ( & V_235 -> V_47 -> V_14 , V_181 -> V_187 ) ;
V_235 -> V_47 = NULL ;
return V_133 ;
}
static void
F_139 ( struct V_123 * V_128 )
{
struct V_129 * V_130 = F_5 ( V_128 , struct V_129 , V_14 ) ;
F_3 ( V_128 -> V_126 ) ;
F_3 ( V_130 ) ;
}
static int F_140 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
struct V_28 * V_29 ;
int V_243 ;
V_29 = F_141 ( & V_244 , V_198 ) ;
if ( F_142 ( V_29 ) )
return F_143 ( V_29 ) ;
V_243 = F_144 ( V_29 , V_198 ) ;
if ( V_243 ) {
F_145 ( V_29 , V_198 ) ;
return V_243 ;
}
V_181 -> V_185 = V_29 ;
return 0 ;
}
static void F_146 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
struct V_28 * V_29 = V_181 -> V_185 ;
V_181 -> V_185 = NULL ;
F_147 ( V_29 ) ;
F_148 ( V_29 , V_198 ) ;
F_145 ( V_29 , V_198 ) ;
}
static int F_149 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
struct V_28 * V_29 ;
int V_243 ;
V_29 = F_141 ( & V_245 , V_198 ) ;
if ( F_142 ( V_29 ) )
return F_143 ( V_29 ) ;
V_243 = F_144 ( V_29 , V_198 ) ;
if ( V_243 ) {
F_145 ( V_29 , V_198 ) ;
return V_243 ;
}
V_181 -> V_187 = V_29 ;
return 0 ;
}
static void F_150 ( struct V_198 * V_198 )
{
struct V_180 * V_181 = F_103 ( V_198 , V_184 ) ;
struct V_28 * V_29 = V_181 -> V_187 ;
V_181 -> V_187 = NULL ;
F_147 ( V_29 ) ;
F_148 ( V_29 , V_198 ) ;
F_145 ( V_29 , V_198 ) ;
}
int
F_151 ( struct V_198 * V_198 )
{
int V_56 ;
V_56 = F_149 ( V_198 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_140 ( V_198 ) ;
if ( V_56 )
goto V_246;
V_56 = F_121 ( V_198 ) ;
if ( V_56 )
goto V_247;
return 0 ;
V_247:
F_124 ( V_198 ) ;
V_246:
F_150 ( V_198 ) ;
return V_56 ;
}
void
F_152 ( struct V_198 * V_198 )
{
F_124 ( V_198 ) ;
F_146 ( V_198 ) ;
F_150 ( V_198 ) ;
}
int
F_153 ( void )
{
return F_154 ( V_107 , & V_136 ) ;
}
void
F_155 ( void )
{
F_156 ( V_107 ) ;
}
