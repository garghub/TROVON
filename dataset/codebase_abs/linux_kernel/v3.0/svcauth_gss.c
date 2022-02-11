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
static int F_19 ( struct V_28 * V_29 , struct V_17 * V_14 )
{
return F_20 ( V_29 , V_14 , F_17 ) ;
}
static int F_21 ( struct V_28 * V_29 ,
char * V_32 , int V_33 )
{
char * V_34 = V_32 ;
char * V_35 ;
int V_4 ;
struct V_6 V_7 , * V_36 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_8 , V_34 , V_4 ) )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
V_38 = - V_39 ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_9 , V_34 , V_4 ) )
goto V_40;
V_36 = F_23 ( & V_7 ) ;
if ( ! V_36 )
goto V_40;
V_7 . V_14 . V_41 = 0 ;
V_37 = F_24 ( & V_32 ) ;
V_38 = - V_39 ;
if ( V_37 == 0 )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 <= 0 )
goto V_40;
V_7 . V_26 = F_25 ( V_34 , & V_35 , 10 ) ;
if ( * V_35 )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 <= 0 )
goto V_40;
V_7 . V_27 = F_25 ( V_34 , & V_35 , 10 ) ;
if ( * V_35 )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_10 , V_34 , V_4 ) )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
V_38 = - V_39 ;
if ( V_4 < 0 )
goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_7 . V_11 , V_34 , V_4 ) )
goto V_40;
V_7 . V_14 . V_42 = V_37 ;
V_36 = F_26 ( & V_7 , V_36 ) ;
V_38 = 0 ;
V_40:
F_2 ( & V_7 ) ;
if ( V_36 )
F_27 ( & V_36 -> V_14 , & V_43 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static struct V_6 * F_23 ( struct V_6 * V_15 )
{
struct V_17 * V_44 ;
int V_45 = F_6 ( V_15 ) ;
V_44 = F_28 ( & V_43 , & V_15 -> V_14 , V_45 ) ;
if ( V_44 )
return F_5 ( V_44 , struct V_6 , V_14 ) ;
else
return NULL ;
}
static struct V_6 * F_26 ( struct V_6 * V_25 , struct V_6 * V_46 )
{
struct V_17 * V_44 ;
int V_45 = F_6 ( V_25 ) ;
V_44 = F_29 ( & V_43 , & V_25 -> V_14 ,
& V_46 -> V_14 , V_45 ) ;
if ( V_44 )
return F_5 ( V_44 , struct V_6 , V_14 ) ;
else
return NULL ;
}
static void F_30 ( struct V_47 * V_48 )
{
F_3 ( V_48 -> V_49 . V_5 ) ;
if ( V_48 -> V_50 )
F_31 ( & V_48 -> V_50 ) ;
if ( V_48 -> V_51 . V_52 )
F_32 ( V_48 -> V_51 . V_52 ) ;
F_3 ( V_48 -> V_53 ) ;
}
static void F_33 ( struct V_12 * V_13 )
{
struct V_47 * V_48 = F_5 ( V_13 , struct V_47 , V_14 . V_13 ) ;
F_30 ( V_48 ) ;
F_3 ( V_48 ) ;
}
static inline int
F_34 ( struct V_47 * V_48 )
{
return F_7 ( V_48 -> V_49 . V_5 , V_48 -> V_49 . V_4 , V_54 ) ;
}
static int
F_35 ( struct V_17 * V_2 , struct V_17 * V_3 )
{
struct V_47 * V_25 = F_5 ( V_2 , struct V_47 , V_14 ) ;
struct V_47 * V_18 = F_5 ( V_3 , struct V_47 , V_14 ) ;
return F_1 ( & V_25 -> V_49 , & V_18 -> V_49 ) ;
}
static void
F_36 ( struct V_17 * V_23 , struct V_17 * V_55 )
{
struct V_47 * V_25 = F_5 ( V_23 , struct V_47 , V_14 ) ;
struct V_47 * V_18 = F_5 ( V_55 , struct V_47 , V_14 ) ;
V_25 -> V_49 . V_4 = V_18 -> V_49 . V_4 ;
V_18 -> V_49 . V_4 = 0 ;
V_25 -> V_49 . V_5 = V_18 -> V_49 . V_5 ;
V_18 -> V_49 . V_5 = NULL ;
V_25 -> V_50 = NULL ;
V_25 -> V_51 . V_52 = NULL ;
V_25 -> V_53 = NULL ;
}
static void
F_37 ( struct V_17 * V_23 , struct V_17 * V_55 )
{
struct V_47 * V_25 = F_5 ( V_23 , struct V_47 , V_14 ) ;
struct V_47 * V_18 = F_5 ( V_55 , struct V_47 , V_14 ) ;
V_25 -> V_50 = V_18 -> V_50 ;
V_18 -> V_50 = NULL ;
memset ( & V_25 -> V_56 , 0 , sizeof( V_25 -> V_56 ) ) ;
F_38 ( & V_25 -> V_56 . V_57 ) ;
V_25 -> V_51 = V_18 -> V_51 ;
V_18 -> V_51 . V_52 = NULL ;
V_25 -> V_53 = V_18 -> V_53 ;
V_18 -> V_53 = NULL ;
}
static struct V_17 *
F_39 ( void )
{
struct V_47 * V_48 = F_16 ( sizeof( * V_48 ) , V_21 ) ;
if ( V_48 )
return & V_48 -> V_14 ;
else
return NULL ;
}
static int F_40 ( struct V_28 * V_29 ,
char * V_32 , int V_33 )
{
char * V_34 = V_32 ;
int V_4 , V_58 ;
struct V_47 V_48 , * V_59 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
struct V_60 * V_61 = NULL ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 ) goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_48 . V_49 , V_34 , V_4 ) )
goto V_40;
V_48 . V_14 . V_41 = 0 ;
V_37 = F_24 ( & V_32 ) ;
V_38 = - V_39 ;
if ( V_37 == 0 )
goto V_40;
V_59 = F_41 ( & V_48 ) ;
if ( ! V_59 )
goto V_40;
V_58 = F_42 ( & V_32 , & V_48 . V_51 . V_62 ) ;
if ( V_58 == - V_39 )
goto V_40;
if ( V_58 == - V_63 )
F_43 ( V_64 , & V_48 . V_14 . V_41 ) ;
else {
int V_65 , V_66 ;
if ( F_42 ( & V_32 , & V_48 . V_51 . V_67 ) )
goto V_40;
if ( F_42 ( & V_32 , & V_65 ) )
goto V_40;
V_38 = - V_22 ;
V_48 . V_51 . V_52 = F_44 ( V_65 ) ;
if ( V_48 . V_51 . V_52 == NULL )
goto V_40;
V_38 = - V_39 ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
T_2 V_68 ;
if ( F_42 ( & V_32 , & V_68 ) )
goto V_40;
F_45 ( V_48 . V_51 . V_52 , V_66 ) = V_68 ;
}
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_61 = F_46 ( V_34 ) ;
V_38 = - V_69 ;
if ( ! V_61 )
goto V_40;
V_38 = - V_39 ;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = F_47 ( V_34 , V_4 , V_61 , & V_48 . V_50 , V_21 ) ;
if ( V_38 )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 > 0 ) {
V_48 . V_53 = F_48 ( V_34 , V_21 ) ;
if ( ! V_48 . V_53 )
goto V_40;
}
}
V_48 . V_14 . V_42 = V_37 ;
V_59 = F_49 ( & V_48 , V_59 ) ;
V_38 = 0 ;
V_40:
F_50 ( V_61 ) ;
F_30 ( & V_48 ) ;
if ( V_59 )
F_27 ( & V_59 -> V_14 , & V_70 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static struct V_47 * F_41 ( struct V_47 * V_15 )
{
struct V_17 * V_44 ;
int V_45 = F_34 ( V_15 ) ;
V_44 = F_28 ( & V_70 , & V_15 -> V_14 , V_45 ) ;
if ( V_44 )
return F_5 ( V_44 , struct V_47 , V_14 ) ;
else
return NULL ;
}
static struct V_47 * F_49 ( struct V_47 * V_25 , struct V_47 * V_46 )
{
struct V_17 * V_44 ;
int V_45 = F_34 ( V_25 ) ;
V_44 = F_29 ( & V_70 , & V_25 -> V_14 ,
& V_46 -> V_14 , V_45 ) ;
if ( V_44 )
return F_5 ( V_44 , struct V_47 , V_14 ) ;
else
return NULL ;
}
static struct V_47 *
F_51 ( struct V_1 * V_49 )
{
struct V_47 V_48 ;
struct V_47 * V_71 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
if ( F_9 ( & V_48 . V_49 , V_49 -> V_5 , V_49 -> V_4 ) )
return NULL ;
V_71 = F_41 ( & V_48 ) ;
F_30 ( & V_48 ) ;
if ( ! V_71 )
return NULL ;
if ( F_52 ( & V_70 , & V_71 -> V_14 , NULL ) )
return NULL ;
return V_71 ;
}
static int
F_53 ( struct V_47 * V_48 , int V_72 )
{
struct V_73 * V_74 = & V_48 -> V_56 ;
F_54 ( & V_74 -> V_57 ) ;
if ( V_72 > V_74 -> V_75 ) {
if ( V_72 >= V_74 -> V_75 + V_76 ) {
memset ( V_74 -> V_77 , 0 , sizeof( V_74 -> V_77 ) ) ;
V_74 -> V_75 = V_72 ;
} else while ( V_74 -> V_75 < V_72 ) {
V_74 -> V_75 ++ ;
F_55 ( V_74 -> V_75 % V_76 , V_74 -> V_77 ) ;
}
F_56 ( V_72 % V_76 , V_74 -> V_77 ) ;
goto V_78;
} else if ( V_72 <= V_74 -> V_75 - V_76 ) {
goto V_79;
}
if ( F_57 ( V_72 % V_76 , V_74 -> V_77 ) )
goto V_79;
V_78:
F_58 ( & V_74 -> V_57 ) ;
return 1 ;
V_79:
F_58 ( & V_74 -> V_57 ) ;
return 0 ;
}
static inline T_3 F_59 ( T_3 V_66 )
{
return ( V_66 + 3 ) & ~ 3 ;
}
static inline int
F_60 ( struct V_80 * V_81 , struct V_1 * V_82 )
{
int V_83 ;
if ( V_81 -> V_84 < 4 )
return - 1 ;
V_82 -> V_4 = F_61 ( V_81 ) ;
V_83 = F_59 ( V_82 -> V_4 ) ;
if ( V_81 -> V_84 < V_83 )
return - 1 ;
V_82 -> V_5 = V_81 -> V_85 ;
V_81 -> V_85 += V_83 ;
V_81 -> V_84 -= V_83 ;
return 0 ;
}
static inline int
F_62 ( struct V_80 * V_86 , struct V_1 * V_82 )
{
T_4 * V_87 ;
if ( V_86 -> V_84 + 4 > V_88 )
return - 1 ;
F_63 ( V_86 , V_82 -> V_4 ) ;
V_87 = V_86 -> V_85 + V_86 -> V_84 ;
V_86 -> V_84 += F_59 ( V_82 -> V_4 ) ;
if ( V_86 -> V_84 > V_88 )
return - 1 ;
memcpy ( V_87 , V_82 -> V_5 , V_82 -> V_4 ) ;
memset ( V_87 + V_82 -> V_4 , 0 , F_59 ( V_82 -> V_4 ) - V_82 -> V_4 ) ;
return 0 ;
}
static int
F_64 ( struct V_89 * V_90 , struct V_47 * V_48 ,
T_5 * V_91 , struct V_92 * V_93 , T_5 * V_94 )
{
struct V_95 * V_96 = V_48 -> V_50 ;
struct V_97 V_98 ;
struct V_1 V_99 ;
T_3 V_100 = 0 ;
struct V_80 * V_81 = & V_90 -> V_101 . V_102 [ 0 ] ;
struct V_80 V_103 ;
V_103 . V_85 = V_91 ;
V_103 . V_84 = ( T_4 * ) V_81 -> V_85 - ( T_4 * ) V_91 ;
F_65 ( & V_103 , & V_98 ) ;
* V_94 = V_104 ;
if ( V_81 -> V_84 < 4 )
return V_105 ;
V_100 = F_61 ( V_81 ) ;
if ( V_100 != V_106 )
return V_105 ;
if ( F_60 ( V_81 , & V_99 ) )
return V_105 ;
if ( V_90 -> V_107 )
return V_108 ;
if ( F_66 ( V_96 , & V_98 , & V_99 ) != V_109 ) {
* V_94 = V_110 ;
return V_105 ;
}
if ( V_93 -> V_111 > V_112 ) {
F_67 ( L_1
L_2 , V_93 -> V_111 ) ;
* V_94 = V_113 ;
return V_105 ;
}
if ( ! F_53 ( V_48 , V_93 -> V_111 ) ) {
F_67 ( L_1
L_3 , V_93 -> V_111 ) ;
return V_114 ;
}
return V_108 ;
}
static int
F_68 ( struct V_89 * V_90 )
{
T_5 * V_87 ;
F_63 ( V_90 -> V_115 . V_102 , V_116 ) ;
V_87 = V_90 -> V_115 . V_102 -> V_85 + V_90 -> V_115 . V_102 -> V_84 ;
* V_87 ++ = 0 ;
if ( ! F_69 ( V_90 , V_87 ) )
return - 1 ;
return 0 ;
}
static int
F_70 ( struct V_89 * V_90 , struct V_95 * V_96 , T_3 V_117 )
{
T_5 V_118 ;
T_3 V_119 ;
struct V_97 V_120 ;
struct V_1 V_121 ;
T_5 * V_87 ;
struct V_80 V_103 ;
F_63 ( V_90 -> V_115 . V_102 , V_106 ) ;
V_118 = F_71 ( V_117 ) ;
V_103 . V_85 = & V_118 ;
V_103 . V_84 = sizeof( V_118 ) ;
F_65 ( & V_103 , & V_120 ) ;
V_87 = V_90 -> V_115 . V_102 -> V_85 + V_90 -> V_115 . V_102 -> V_84 ;
V_121 . V_5 = ( T_4 * ) ( V_87 + 1 ) ;
V_119 = F_72 ( V_96 , & V_120 , & V_121 ) ;
if ( V_119 != V_109 )
return - 1 ;
* V_87 ++ = F_71 ( V_121 . V_4 ) ;
memset ( ( T_4 * ) V_87 + V_121 . V_4 , 0 , F_59 ( V_121 . V_4 ) - V_121 . V_4 ) ;
V_87 += F_73 ( V_121 . V_4 ) ;
if ( ! F_69 ( V_90 , V_87 ) )
return - 1 ;
return 0 ;
}
static struct V_122 *
F_74 ( struct V_95 * V_123 , T_3 V_124 )
{
char * V_125 ;
V_125 = F_75 ( V_123 -> V_126 , V_124 ) ;
if ( ! V_125 )
return NULL ;
return F_76 ( V_125 ) ;
}
T_3 F_77 ( struct V_122 * V_127 )
{
struct V_128 * V_129 = F_5 ( V_127 , struct V_128 , V_14 ) ;
return V_129 -> V_130 ;
}
int
F_78 ( T_3 V_130 , char * V_125 )
{
struct V_128 * V_25 ;
struct V_122 * V_131 ;
int V_132 = - V_22 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
goto V_40;
F_79 ( & V_25 -> V_14 . V_13 ) ;
V_25 -> V_14 . V_125 = F_48 ( V_125 , V_21 ) ;
if ( ! V_25 -> V_14 . V_125 )
goto V_133;
V_25 -> V_14 . V_134 = & V_135 ;
V_25 -> V_130 = V_130 ;
V_132 = 0 ;
V_131 = F_80 ( V_125 , & V_25 -> V_14 ) ;
if ( V_131 != & V_25 -> V_14 ) {
F_81 ( V_131 ) ;
F_3 ( V_25 -> V_14 . V_125 ) ;
goto V_133;
}
return 0 ;
V_133:
F_3 ( V_25 ) ;
V_40:
return V_132 ;
}
static inline int
F_82 ( struct V_97 * V_34 , int V_136 , T_3 * V_137 )
{
T_5 V_138 ;
int V_38 ;
V_38 = F_83 ( V_34 , V_136 , & V_138 , sizeof( * V_137 ) ) ;
if ( V_38 )
return V_38 ;
* V_137 = F_84 ( V_138 ) ;
return 0 ;
}
static int
F_85 ( struct V_97 * V_34 , T_3 V_117 , struct V_95 * V_123 )
{
int V_132 = - V_39 ;
T_3 V_139 , V_119 ;
struct V_1 V_121 ;
struct V_97 V_140 ;
V_139 = F_61 ( & V_34 -> V_102 [ 0 ] ) ;
if ( V_139 & 3 )
return V_132 ;
if ( V_139 > V_34 -> V_4 )
return V_132 ;
if ( F_86 ( V_34 , & V_140 , 0 , V_139 ) )
F_87 () ;
if ( F_82 ( V_34 , V_139 , & V_121 . V_4 ) )
F_87 () ;
if ( V_121 . V_4 > V_141 )
return V_132 ;
V_121 . V_5 = F_16 ( V_121 . V_4 , V_21 ) ;
if ( ! V_121 . V_5 )
return V_132 ;
if ( F_83 ( V_34 , V_139 + 4 , V_121 . V_5 , V_121 . V_4 ) )
goto V_40;
V_119 = F_66 ( V_123 , & V_140 , & V_121 ) ;
if ( V_119 != V_109 )
goto V_40;
if ( F_61 ( & V_34 -> V_102 [ 0 ] ) != V_117 )
goto V_40;
V_132 = 0 ;
V_40:
F_3 ( V_121 . V_5 ) ;
return V_132 ;
}
static inline int
F_88 ( struct V_97 * V_34 )
{
return V_34 -> V_102 [ 0 ] . V_84 + V_34 -> V_142 + V_34 -> V_143 [ 0 ] . V_84 ;
}
static void
F_89 ( struct V_97 * V_34 , int V_144 )
{
if ( V_34 -> V_142 == 0 ) {
V_34 -> V_102 [ 0 ] . V_84 -= V_144 ;
}
}
static int
F_90 ( struct V_89 * V_90 , struct V_97 * V_34 , T_3 V_117 , struct V_95 * V_123 )
{
T_3 V_145 , V_119 ;
int V_144 , V_146 , V_147 , V_148 ;
V_90 -> V_149 = 0 ;
V_145 = F_61 ( & V_34 -> V_102 [ 0 ] ) ;
if ( V_90 -> V_107 ) {
goto V_150;
}
V_147 = F_88 ( V_34 ) ;
if ( V_145 > V_147 )
return - V_39 ;
V_144 = V_147 - V_145 ;
V_34 -> V_4 -= V_144 ;
F_89 ( V_34 , V_144 ) ;
V_146 = V_34 -> V_4 ;
V_34 -> V_4 = V_145 ;
V_119 = F_91 ( V_123 , 0 , V_34 ) ;
V_144 = V_145 - V_34 -> V_4 ;
V_34 -> V_4 = V_146 ;
V_34 -> V_4 -= V_144 ;
V_148 = V_34 -> V_102 [ 0 ] . V_84 % 4 ;
if ( V_148 ) {
V_34 -> V_151 = V_152 ;
F_92 ( V_34 , V_148 ) ;
F_89 ( V_34 , V_144 ) ;
}
if ( V_119 != V_109 )
return - V_39 ;
V_150:
if ( F_61 ( & V_34 -> V_102 [ 0 ] ) != V_117 )
return - V_39 ;
return 0 ;
}
char * F_93 ( struct V_89 * V_90 )
{
struct V_153 * V_129 = (struct V_153 * ) V_90 -> V_154 ;
if ( V_129 && V_129 -> V_48 )
return V_129 -> V_48 -> V_53 ;
return NULL ;
}
static int
F_94 ( struct V_89 * V_90 )
{
struct V_153 * V_155 = V_90 -> V_154 ;
struct V_47 * V_48 = V_155 -> V_48 ;
struct V_92 * V_93 = & V_155 -> V_156 ;
int V_132 ;
V_90 -> V_157 = F_74 ( V_48 -> V_50 , V_93 -> V_158 ) ;
if ( V_90 -> V_157 == NULL )
return V_105 ;
V_132 = F_95 ( V_90 ) ;
if ( V_132 == V_114 || V_132 == V_159 )
return V_132 ;
return V_108 ;
}
static inline int
F_96 ( struct V_89 * V_90 , struct V_6 * V_36 )
{
struct V_47 * V_48 ;
int V_160 ;
if ( V_36 -> V_26 != V_109 )
return F_68 ( V_90 ) ;
V_48 = F_51 ( & V_36 -> V_10 ) ;
if ( V_48 == NULL ) {
V_36 -> V_26 = V_161 ;
return F_68 ( V_90 ) ;
}
V_160 = F_70 ( V_90 , V_48 -> V_50 , V_76 ) ;
F_27 ( & V_48 -> V_14 , & V_70 ) ;
return V_160 ;
}
static int F_97 ( struct V_89 * V_90 ,
struct V_92 * V_93 , T_5 * V_94 )
{
struct V_80 * V_81 = & V_90 -> V_101 . V_102 [ 0 ] ;
struct V_80 * V_86 = & V_90 -> V_115 . V_102 [ 0 ] ;
struct V_1 V_162 ;
struct V_6 * V_36 , V_163 ;
int V_164 ;
* V_94 = V_104 ;
if ( V_81 -> V_84 < 2 * 4 )
return V_105 ;
if ( F_61 ( V_81 ) != V_116 )
return V_105 ;
if ( F_61 ( V_81 ) != 0 )
return V_105 ;
* V_94 = V_165 ;
if ( V_93 -> V_166 == V_167 && V_93 -> V_168 . V_4 != 0 )
return V_105 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
if ( F_11 ( & V_163 . V_8 , & V_93 -> V_168 ) )
return V_159 ;
* V_94 = V_104 ;
if ( F_60 ( V_81 , & V_162 ) ) {
F_3 ( V_163 . V_8 . V_5 ) ;
return V_105 ;
}
if ( F_11 ( & V_163 . V_9 , & V_162 ) ) {
F_3 ( V_163 . V_8 . V_5 ) ;
return V_159 ;
}
V_36 = F_23 ( & V_163 ) ;
F_2 ( & V_163 ) ;
if ( ! V_36 )
return V_159 ;
if ( F_52 ( & V_43 , & V_36 -> V_14 , & V_90 -> V_169 ) < 0 )
return V_159 ;
V_164 = V_159 ;
if ( F_96 ( V_90 , V_36 ) )
goto V_40;
if ( V_86 -> V_84 + 4 > V_88 )
goto V_40;
F_63 ( V_86 , V_170 ) ;
if ( F_62 ( V_86 , & V_36 -> V_10 ) )
goto V_40;
if ( V_86 -> V_84 + 3 * 4 > V_88 )
goto V_40;
F_63 ( V_86 , V_36 -> V_26 ) ;
F_63 ( V_86 , V_36 -> V_27 ) ;
F_63 ( V_86 , V_76 ) ;
if ( F_62 ( V_86 , & V_36 -> V_11 ) )
goto V_40;
V_164 = V_171 ;
V_40:
F_27 ( & V_36 -> V_14 , & V_43 ) ;
return V_164 ;
}
static int
F_98 ( struct V_89 * V_90 , T_5 * V_94 )
{
struct V_80 * V_81 = & V_90 -> V_101 . V_102 [ 0 ] ;
struct V_80 * V_86 = & V_90 -> V_115 . V_102 [ 0 ] ;
T_3 V_172 ;
struct V_153 * V_155 = V_90 -> V_154 ;
struct V_92 * V_93 ;
struct V_47 * V_48 = NULL ;
T_5 * V_91 ;
T_5 * V_173 = V_86 -> V_85 + V_86 -> V_84 ;
int V_164 ;
F_67 ( L_4 ,
V_81 -> V_84 ) ;
* V_94 = V_165 ;
if ( ! V_155 )
V_155 = F_16 ( sizeof( * V_155 ) , V_21 ) ;
if ( ! V_155 )
goto V_174;
V_90 -> V_154 = V_155 ;
V_155 -> V_175 = NULL ;
V_155 -> V_48 = NULL ;
V_93 = & V_155 -> V_156 ;
V_91 = V_81 -> V_85 ;
V_91 -= 7 ;
if ( V_81 -> V_84 < 5 * 4 )
goto V_174;
V_172 = F_61 ( V_81 ) ;
if ( F_61 ( V_81 ) != V_176 )
goto V_174;
V_93 -> V_166 = F_61 ( V_81 ) ;
V_93 -> V_111 = F_61 ( V_81 ) ;
V_93 -> V_158 = F_61 ( V_81 ) ;
if ( F_60 ( V_81 , & V_93 -> V_168 ) )
goto V_174;
if ( V_172 != F_59 ( V_93 -> V_168 . V_4 ) + 5 * 4 )
goto V_174;
if ( ( V_93 -> V_166 != V_177 ) && ( V_90 -> V_178 != 0 ) )
goto V_174;
* V_94 = V_104 ;
switch ( V_93 -> V_166 ) {
case V_167 :
case V_179 :
return F_97 ( V_90 , V_93 , V_94 ) ;
case V_177 :
case V_180 :
* V_94 = V_110 ;
V_48 = F_51 ( & V_93 -> V_168 ) ;
if ( ! V_48 )
goto V_174;
switch ( F_64 ( V_90 , V_48 , V_91 , V_93 , V_94 ) ) {
case V_108 :
break;
case V_105 :
goto V_174;
case V_114 :
goto V_79;
}
break;
default:
* V_94 = V_181 ;
goto V_174;
}
switch ( V_93 -> V_166 ) {
case V_180 :
if ( F_70 ( V_90 , V_48 -> V_50 , V_93 -> V_111 ) )
goto V_174;
V_48 -> V_14 . V_42 = F_99 () ;
F_43 ( V_64 , & V_48 -> V_14 . V_41 ) ;
if ( V_86 -> V_84 + 4 > V_88 )
goto V_79;
F_63 ( V_86 , V_170 ) ;
goto V_182;
case V_177 :
* V_94 = V_113 ;
V_155 -> V_175 = V_86 -> V_85 + V_86 -> V_84 ;
if ( F_70 ( V_90 , V_48 -> V_50 , V_93 -> V_111 ) )
goto V_174;
V_90 -> V_183 = V_48 -> V_51 ;
F_100 ( V_48 -> V_51 . V_52 ) ;
* V_94 = V_165 ;
switch ( V_93 -> V_158 ) {
case V_184 :
break;
case V_185 :
F_63 ( V_86 , 0 ) ;
F_63 ( V_86 , 0 ) ;
if ( F_85 ( & V_90 -> V_101 ,
V_93 -> V_111 , V_48 -> V_50 ) )
goto V_186;
break;
case V_187 :
F_63 ( V_86 , 0 ) ;
F_63 ( V_86 , 0 ) ;
if ( F_90 ( V_90 , & V_90 -> V_101 ,
V_93 -> V_111 , V_48 -> V_50 ) )
goto V_186;
break;
default:
goto V_174;
}
V_155 -> V_48 = V_48 ;
F_101 ( & V_48 -> V_14 ) ;
V_90 -> V_188 = F_102 (
V_48 -> V_50 -> V_126 , V_93 -> V_158 ) ;
V_164 = V_108 ;
goto V_40;
}
V_186:
V_164 = V_189 ;
goto V_40;
V_174:
F_69 ( V_90 , V_173 ) ;
V_164 = V_105 ;
goto V_40;
V_182:
V_164 = V_171 ;
goto V_40;
V_79:
V_164 = V_114 ;
V_40:
if ( V_48 )
F_27 ( & V_48 -> V_14 , & V_70 ) ;
return V_164 ;
}
static T_5 *
F_103 ( struct V_97 * V_190 , struct V_153 * V_191 )
{
T_5 * V_87 ;
T_3 V_192 ;
V_87 = V_191 -> V_175 ;
V_191 -> V_175 = NULL ;
if ( * ( V_87 - 1 ) != V_193 )
return NULL ;
V_87 += 1 ;
V_192 = F_84 ( * V_87 ++ ) ;
V_87 += F_73 ( V_192 ) ;
memcpy ( V_87 , V_87 + 2 , 4 ) ;
if ( * V_87 != V_193 ) {
V_190 -> V_102 [ 0 ] . V_84 -= 2 * 4 ;
return NULL ;
}
V_87 ++ ;
return V_87 ;
}
static inline int
F_104 ( struct V_89 * V_90 )
{
struct V_153 * V_191 = (struct V_153 * ) V_90 -> V_154 ;
struct V_92 * V_93 = & V_191 -> V_156 ;
struct V_97 * V_190 = & V_90 -> V_115 ;
struct V_97 V_140 ;
struct V_1 V_121 ;
struct V_80 * V_86 ;
T_5 * V_87 ;
int V_194 , V_139 ;
int V_132 = - V_39 ;
V_87 = F_103 ( V_190 , V_191 ) ;
if ( V_87 == NULL )
goto V_40;
V_194 = ( T_4 * ) ( V_87 + 1 ) - ( T_4 * ) V_190 -> V_102 [ 0 ] . V_85 ;
V_139 = V_190 -> V_4 - V_194 ;
F_14 ( V_139 % 4 ) ;
* V_87 ++ = F_71 ( V_139 ) ;
* V_87 ++ = F_71 ( V_93 -> V_111 ) ;
if ( F_86 ( V_190 , & V_140 , V_194 ,
V_139 ) )
F_87 () ;
if ( V_190 -> V_143 [ 0 ] . V_85 == NULL ) {
if ( V_190 -> V_102 [ 0 ] . V_84 + V_141 > V_88 )
goto V_195;
V_190 -> V_143 [ 0 ] . V_85 = V_190 -> V_102 [ 0 ] . V_85
+ V_190 -> V_102 [ 0 ] . V_84 ;
V_190 -> V_143 [ 0 ] . V_84 = 0 ;
V_86 = & V_190 -> V_143 [ 0 ] ;
} else {
V_86 = & V_190 -> V_143 [ 0 ] ;
}
V_121 . V_5 = ( T_4 * ) V_86 -> V_85 + V_86 -> V_84 + 4 ;
if ( F_72 ( V_191 -> V_48 -> V_50 , & V_140 , & V_121 ) )
goto V_195;
F_63 ( V_86 , V_121 . V_4 ) ;
memset ( V_121 . V_5 + V_121 . V_4 , 0 ,
F_59 ( V_121 . V_4 ) - V_121 . V_4 ) ;
V_86 -> V_84 += F_73 ( V_121 . V_4 ) << 2 ;
V_190 -> V_4 += F_73 ( V_121 . V_4 ) << 2 ;
F_14 ( V_86 -> V_84 > V_88 ) ;
V_40:
V_132 = 0 ;
V_195:
return V_132 ;
}
static inline int
F_105 ( struct V_89 * V_90 )
{
struct V_153 * V_191 = (struct V_153 * ) V_90 -> V_154 ;
struct V_92 * V_93 = & V_191 -> V_156 ;
struct V_97 * V_190 = & V_90 -> V_115 ;
struct V_196 * * V_197 = NULL ;
T_5 * V_87 , * V_4 ;
int V_148 ;
int V_144 ;
V_87 = F_103 ( V_190 , V_191 ) ;
if ( V_87 == NULL )
return 0 ;
V_4 = V_87 ++ ;
V_148 = ( T_4 * ) V_87 - ( T_4 * ) V_190 -> V_102 [ 0 ] . V_85 ;
* V_87 ++ = F_71 ( V_93 -> V_111 ) ;
V_197 = V_190 -> V_198 ;
if ( V_190 -> V_143 [ 0 ] . V_85 ) {
F_14 ( V_190 -> V_143 [ 0 ] . V_85 >= V_190 -> V_102 [ 0 ] . V_85
+ V_88 ) ;
F_14 ( V_190 -> V_143 [ 0 ] . V_85 < V_190 -> V_102 [ 0 ] . V_85 ) ;
if ( V_190 -> V_143 [ 0 ] . V_84 + V_190 -> V_102 [ 0 ] . V_84
+ 2 * V_141 > V_88 )
return - V_22 ;
memmove ( V_190 -> V_143 [ 0 ] . V_85 + V_141 ,
V_190 -> V_143 [ 0 ] . V_85 ,
V_190 -> V_143 [ 0 ] . V_84 ) ;
V_190 -> V_143 [ 0 ] . V_85 += V_141 ;
}
if ( V_190 -> V_143 [ 0 ] . V_85 == NULL ) {
if ( V_190 -> V_102 [ 0 ] . V_84 + 2 * V_141 > V_88 )
return - V_22 ;
V_190 -> V_143 [ 0 ] . V_85 = V_190 -> V_102 [ 0 ] . V_85
+ V_190 -> V_102 [ 0 ] . V_84 + V_141 ;
V_190 -> V_143 [ 0 ] . V_84 = 0 ;
}
if ( F_106 ( V_191 -> V_48 -> V_50 , V_148 , V_190 , V_197 ) )
return - V_22 ;
* V_4 = F_71 ( V_190 -> V_4 - V_148 ) ;
V_144 = 3 - ( ( V_190 -> V_4 - V_148 - 1 ) & 3 ) ;
V_87 = ( T_5 * ) ( V_190 -> V_143 [ 0 ] . V_85 + V_190 -> V_143 [ 0 ] . V_84 ) ;
memset ( V_87 , 0 , V_144 ) ;
V_190 -> V_143 [ 0 ] . V_84 += V_144 ;
V_190 -> V_4 += V_144 ;
return 0 ;
}
static int
F_107 ( struct V_89 * V_90 )
{
struct V_153 * V_191 = (struct V_153 * ) V_90 -> V_154 ;
struct V_92 * V_93 = & V_191 -> V_156 ;
struct V_97 * V_190 = & V_90 -> V_115 ;
int V_132 = - V_39 ;
if ( V_93 -> V_166 != V_177 )
goto V_40;
if ( V_191 -> V_175 == NULL )
goto V_40;
V_190 -> V_4 = F_88 ( V_190 ) ;
switch ( V_93 -> V_158 ) {
case V_184 :
break;
case V_185 :
V_132 = F_104 ( V_90 ) ;
if ( V_132 )
goto V_195;
break;
case V_187 :
V_132 = F_105 ( V_90 ) ;
if ( V_132 )
goto V_195;
break;
}
V_40:
V_132 = 0 ;
V_195:
if ( V_90 -> V_199 )
F_81 ( V_90 -> V_199 ) ;
V_90 -> V_199 = NULL ;
if ( V_90 -> V_157 )
F_81 ( V_90 -> V_157 ) ;
V_90 -> V_157 = NULL ;
if ( V_90 -> V_183 . V_52 )
F_32 ( V_90 -> V_183 . V_52 ) ;
V_90 -> V_183 . V_52 = NULL ;
if ( V_191 -> V_48 )
F_27 ( & V_191 -> V_48 -> V_14 , & V_70 ) ;
V_191 -> V_48 = NULL ;
return V_132 ;
}
static void
F_108 ( struct V_122 * V_127 )
{
struct V_128 * V_129 = F_5 ( V_127 , struct V_128 , V_14 ) ;
F_3 ( V_127 -> V_125 ) ;
F_3 ( V_129 ) ;
}
int
F_109 ( void )
{
int V_58 = F_110 ( V_106 , & V_135 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_111 ( & V_70 ) ;
if ( V_58 )
goto V_200;
V_58 = F_111 ( & V_43 ) ;
if ( V_58 )
goto V_201;
return 0 ;
V_201:
F_112 ( & V_70 ) ;
V_200:
F_113 ( V_106 ) ;
return V_58 ;
}
void
F_114 ( void )
{
F_112 ( & V_70 ) ;
F_112 ( & V_43 ) ;
F_113 ( V_106 ) ;
}
