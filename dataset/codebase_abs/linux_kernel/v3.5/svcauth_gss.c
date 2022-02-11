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
V_36 = F_23 ( V_29 , & V_7 ) ;
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
V_36 = F_26 ( V_29 , & V_7 , V_36 ) ;
V_38 = 0 ;
V_40:
F_2 ( & V_7 ) ;
if ( V_36 )
F_27 ( & V_36 -> V_14 , V_29 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static struct V_6 * F_23 ( struct V_28 * V_29 , struct V_6 * V_15 )
{
struct V_17 * V_43 ;
int V_44 = F_6 ( V_15 ) ;
V_43 = F_28 ( V_29 , & V_15 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_6 , V_14 ) ;
else
return NULL ;
}
static struct V_6 * F_26 ( struct V_28 * V_29 , struct V_6 * V_25 , struct V_6 * V_45 )
{
struct V_17 * V_43 ;
int V_44 = F_6 ( V_25 ) ;
V_43 = F_29 ( V_29 , & V_25 -> V_14 ,
& V_45 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_6 , V_14 ) ;
else
return NULL ;
}
static void F_30 ( struct V_46 * V_47 )
{
F_3 ( V_47 -> V_48 . V_5 ) ;
if ( V_47 -> V_49 )
F_31 ( & V_47 -> V_49 ) ;
F_32 ( & V_47 -> V_50 ) ;
}
static void F_33 ( struct V_12 * V_13 )
{
struct V_46 * V_47 = F_5 ( V_13 , struct V_46 , V_14 . V_13 ) ;
F_30 ( V_47 ) ;
F_3 ( V_47 ) ;
}
static inline int
F_34 ( struct V_46 * V_47 )
{
return F_7 ( V_47 -> V_48 . V_5 , V_47 -> V_48 . V_4 , V_51 ) ;
}
static int
F_35 ( struct V_17 * V_2 , struct V_17 * V_3 )
{
struct V_46 * V_25 = F_5 ( V_2 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_3 , struct V_46 , V_14 ) ;
return F_1 ( & V_25 -> V_48 , & V_18 -> V_48 ) ;
}
static void
F_36 ( struct V_17 * V_23 , struct V_17 * V_52 )
{
struct V_46 * V_25 = F_5 ( V_23 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_52 , struct V_46 , V_14 ) ;
V_25 -> V_48 . V_4 = V_18 -> V_48 . V_4 ;
V_18 -> V_48 . V_4 = 0 ;
V_25 -> V_48 . V_5 = V_18 -> V_48 . V_5 ;
V_18 -> V_48 . V_5 = NULL ;
V_25 -> V_49 = NULL ;
V_25 -> V_50 . V_53 = NULL ;
V_25 -> V_50 . V_54 = NULL ;
}
static void
F_37 ( struct V_17 * V_23 , struct V_17 * V_52 )
{
struct V_46 * V_25 = F_5 ( V_23 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_52 , struct V_46 , V_14 ) ;
V_25 -> V_49 = V_18 -> V_49 ;
V_18 -> V_49 = NULL ;
memset ( & V_25 -> V_55 , 0 , sizeof( V_25 -> V_55 ) ) ;
F_38 ( & V_25 -> V_55 . V_56 ) ;
V_25 -> V_50 = V_18 -> V_50 ;
V_18 -> V_50 . V_53 = NULL ;
V_25 -> V_50 . V_54 = V_18 -> V_50 . V_54 ;
V_18 -> V_50 . V_54 = NULL ;
}
static struct V_17 *
F_39 ( void )
{
struct V_46 * V_47 = F_16 ( sizeof( * V_47 ) , V_21 ) ;
if ( V_47 )
return & V_47 -> V_14 ;
else
return NULL ;
}
static int F_40 ( struct V_28 * V_29 ,
char * V_32 , int V_33 )
{
char * V_34 = V_32 ;
int V_4 , V_57 ;
struct V_46 V_47 , * V_58 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
struct V_59 * V_60 = NULL ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 ) goto V_40;
V_38 = - V_22 ;
if ( F_9 ( & V_47 . V_48 , V_34 , V_4 ) )
goto V_40;
V_47 . V_14 . V_41 = 0 ;
V_37 = F_24 ( & V_32 ) ;
V_38 = - V_39 ;
if ( V_37 == 0 )
goto V_40;
V_58 = F_41 ( V_29 , & V_47 ) ;
if ( ! V_58 )
goto V_40;
V_57 = F_42 ( & V_32 , & V_47 . V_50 . V_61 ) ;
if ( V_57 == - V_39 )
goto V_40;
if ( V_57 == - V_62 )
F_43 ( V_63 , & V_47 . V_14 . V_41 ) ;
else {
int V_64 , V_65 ;
if ( F_42 ( & V_32 , & V_47 . V_50 . V_66 ) )
goto V_40;
if ( F_42 ( & V_32 , & V_64 ) )
goto V_40;
V_38 = - V_22 ;
V_47 . V_50 . V_53 = F_44 ( V_64 ) ;
if ( V_47 . V_50 . V_53 == NULL )
goto V_40;
V_38 = - V_39 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
T_2 V_67 ;
T_3 V_68 ;
if ( F_42 ( & V_32 , & V_67 ) )
goto V_40;
V_68 = F_45 ( & V_69 , V_67 ) ;
if ( ! F_46 ( V_68 ) )
goto V_40;
F_47 ( V_47 . V_50 . V_53 , V_65 ) = V_68 ;
}
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_60 = F_48 ( V_34 ) ;
V_38 = - V_70 ;
if ( ! V_60 )
goto V_40;
V_38 = - V_39 ;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = F_49 ( V_34 , V_4 , V_60 , & V_47 . V_49 , V_21 ) ;
if ( V_38 )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 > 0 ) {
V_47 . V_50 . V_54 = F_50 ( V_34 , V_21 ) ;
if ( ! V_47 . V_50 . V_54 )
goto V_40;
}
}
V_47 . V_14 . V_42 = V_37 ;
V_58 = F_51 ( V_29 , & V_47 , V_58 ) ;
V_38 = 0 ;
V_40:
F_52 ( V_60 ) ;
F_30 ( & V_47 ) ;
if ( V_58 )
F_27 ( & V_58 -> V_14 , V_29 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static struct V_46 * F_41 ( struct V_28 * V_29 , struct V_46 * V_15 )
{
struct V_17 * V_43 ;
int V_44 = F_34 ( V_15 ) ;
V_43 = F_28 ( V_29 , & V_15 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_46 , V_14 ) ;
else
return NULL ;
}
static struct V_46 * F_51 ( struct V_28 * V_29 , struct V_46 * V_25 , struct V_46 * V_45 )
{
struct V_17 * V_43 ;
int V_44 = F_34 ( V_25 ) ;
V_43 = F_29 ( V_29 , & V_25 -> V_14 ,
& V_45 -> V_14 , V_44 ) ;
if ( V_43 )
return F_5 ( V_43 , struct V_46 , V_14 ) ;
else
return NULL ;
}
static struct V_46 *
F_53 ( struct V_28 * V_29 , struct V_1 * V_48 )
{
struct V_46 V_47 ;
struct V_46 * V_71 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( F_9 ( & V_47 . V_48 , V_48 -> V_5 , V_48 -> V_4 ) )
return NULL ;
V_71 = F_41 ( V_29 , & V_47 ) ;
F_30 ( & V_47 ) ;
if ( ! V_71 )
return NULL ;
if ( F_54 ( V_29 , & V_71 -> V_14 , NULL ) )
return NULL ;
return V_71 ;
}
static int
F_55 ( struct V_46 * V_47 , int V_72 )
{
struct V_73 * V_74 = & V_47 -> V_55 ;
F_56 ( & V_74 -> V_56 ) ;
if ( V_72 > V_74 -> V_75 ) {
if ( V_72 >= V_74 -> V_75 + V_76 ) {
memset ( V_74 -> V_77 , 0 , sizeof( V_74 -> V_77 ) ) ;
V_74 -> V_75 = V_72 ;
} else while ( V_74 -> V_75 < V_72 ) {
V_74 -> V_75 ++ ;
F_57 ( V_74 -> V_75 % V_76 , V_74 -> V_77 ) ;
}
F_58 ( V_72 % V_76 , V_74 -> V_77 ) ;
goto V_78;
} else if ( V_72 <= V_74 -> V_75 - V_76 ) {
goto V_79;
}
if ( F_59 ( V_72 % V_76 , V_74 -> V_77 ) )
goto V_79;
V_78:
F_60 ( & V_74 -> V_56 ) ;
return 1 ;
V_79:
F_60 ( & V_74 -> V_56 ) ;
return 0 ;
}
static inline T_4 F_61 ( T_4 V_65 )
{
return ( V_65 + 3 ) & ~ 3 ;
}
static inline int
F_62 ( struct V_80 * V_81 , struct V_1 * V_82 )
{
int V_83 ;
if ( V_81 -> V_84 < 4 )
return - 1 ;
V_82 -> V_4 = F_63 ( V_81 ) ;
V_83 = F_61 ( V_82 -> V_4 ) ;
if ( V_81 -> V_84 < V_83 )
return - 1 ;
V_82 -> V_5 = V_81 -> V_85 ;
V_81 -> V_85 += V_83 ;
V_81 -> V_84 -= V_83 ;
return 0 ;
}
static inline int
F_64 ( struct V_80 * V_86 , struct V_1 * V_82 )
{
T_5 * V_87 ;
if ( V_86 -> V_84 + 4 > V_88 )
return - 1 ;
F_65 ( V_86 , V_82 -> V_4 ) ;
V_87 = V_86 -> V_85 + V_86 -> V_84 ;
V_86 -> V_84 += F_61 ( V_82 -> V_4 ) ;
if ( V_86 -> V_84 > V_88 )
return - 1 ;
memcpy ( V_87 , V_82 -> V_5 , V_82 -> V_4 ) ;
memset ( V_87 + V_82 -> V_4 , 0 , F_61 ( V_82 -> V_4 ) - V_82 -> V_4 ) ;
return 0 ;
}
static int
F_66 ( struct V_89 * V_90 , struct V_46 * V_47 ,
T_6 * V_91 , struct V_92 * V_93 , T_6 * V_94 )
{
struct V_95 * V_96 = V_47 -> V_49 ;
struct V_97 V_98 ;
struct V_1 V_99 ;
T_4 V_100 = 0 ;
struct V_80 * V_81 = & V_90 -> V_101 . V_102 [ 0 ] ;
struct V_80 V_103 ;
V_103 . V_85 = V_91 ;
V_103 . V_84 = ( T_5 * ) V_81 -> V_85 - ( T_5 * ) V_91 ;
F_67 ( & V_103 , & V_98 ) ;
* V_94 = V_104 ;
if ( V_81 -> V_84 < 4 )
return V_105 ;
V_100 = F_63 ( V_81 ) ;
if ( V_100 != V_106 )
return V_105 ;
if ( F_62 ( V_81 , & V_99 ) )
return V_105 ;
if ( V_90 -> V_107 )
return V_108 ;
if ( F_68 ( V_96 , & V_98 , & V_99 ) != V_109 ) {
* V_94 = V_110 ;
return V_105 ;
}
if ( V_93 -> V_111 > V_112 ) {
F_69 ( L_1
L_2 , V_93 -> V_111 ) ;
* V_94 = V_113 ;
return V_105 ;
}
if ( ! F_55 ( V_47 , V_93 -> V_111 ) ) {
F_69 ( L_1
L_3 , V_93 -> V_111 ) ;
return V_114 ;
}
return V_108 ;
}
static int
F_70 ( struct V_89 * V_90 )
{
T_6 * V_87 ;
F_65 ( V_90 -> V_115 . V_102 , V_116 ) ;
V_87 = V_90 -> V_115 . V_102 -> V_85 + V_90 -> V_115 . V_102 -> V_84 ;
* V_87 ++ = 0 ;
if ( ! F_71 ( V_90 , V_87 ) )
return - 1 ;
return 0 ;
}
static int
F_72 ( struct V_89 * V_90 , struct V_95 * V_96 , T_4 V_117 )
{
T_6 V_118 ;
T_4 V_119 ;
struct V_97 V_120 ;
struct V_1 V_121 ;
T_6 * V_87 ;
struct V_80 V_103 ;
F_65 ( V_90 -> V_115 . V_102 , V_106 ) ;
V_118 = F_73 ( V_117 ) ;
V_103 . V_85 = & V_118 ;
V_103 . V_84 = sizeof( V_118 ) ;
F_67 ( & V_103 , & V_120 ) ;
V_87 = V_90 -> V_115 . V_102 -> V_85 + V_90 -> V_115 . V_102 -> V_84 ;
V_121 . V_5 = ( T_5 * ) ( V_87 + 1 ) ;
V_119 = F_74 ( V_96 , & V_120 , & V_121 ) ;
if ( V_119 != V_109 )
return - 1 ;
* V_87 ++ = F_73 ( V_121 . V_4 ) ;
memset ( ( T_5 * ) V_87 + V_121 . V_4 , 0 , F_61 ( V_121 . V_4 ) - V_121 . V_4 ) ;
V_87 += F_75 ( V_121 . V_4 ) ;
if ( ! F_71 ( V_90 , V_87 ) )
return - 1 ;
return 0 ;
}
static struct V_122 *
F_76 ( struct V_95 * V_123 , T_4 V_124 )
{
char * V_125 ;
V_125 = F_77 ( V_123 -> V_126 , V_124 ) ;
if ( ! V_125 )
return NULL ;
return F_78 ( V_125 ) ;
}
T_4 F_79 ( struct V_122 * V_127 )
{
struct V_128 * V_129 = F_5 ( V_127 , struct V_128 , V_14 ) ;
return V_129 -> V_130 ;
}
int
F_80 ( T_4 V_130 , char * V_125 )
{
struct V_128 * V_25 ;
struct V_122 * V_131 ;
int V_132 = - V_22 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
goto V_40;
F_81 ( & V_25 -> V_14 . V_13 ) ;
V_25 -> V_14 . V_125 = F_50 ( V_125 , V_21 ) ;
if ( ! V_25 -> V_14 . V_125 )
goto V_133;
V_25 -> V_14 . V_134 = & V_135 ;
V_25 -> V_130 = V_130 ;
V_132 = 0 ;
V_131 = F_82 ( V_125 , & V_25 -> V_14 ) ;
if ( V_131 != & V_25 -> V_14 ) {
F_83 ( V_131 ) ;
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
F_84 ( struct V_97 * V_34 , int V_136 , T_4 * V_137 )
{
T_6 V_138 ;
int V_38 ;
V_38 = F_85 ( V_34 , V_136 , & V_138 , sizeof( * V_137 ) ) ;
if ( V_38 )
return V_38 ;
* V_137 = F_86 ( V_138 ) ;
return 0 ;
}
static int
F_87 ( struct V_97 * V_34 , T_4 V_117 , struct V_95 * V_123 )
{
int V_132 = - V_39 ;
T_4 V_139 , V_119 ;
struct V_1 V_121 ;
struct V_97 V_140 ;
V_139 = F_63 ( & V_34 -> V_102 [ 0 ] ) ;
if ( V_139 & 3 )
return V_132 ;
if ( V_139 > V_34 -> V_4 )
return V_132 ;
if ( F_88 ( V_34 , & V_140 , 0 , V_139 ) )
F_89 () ;
if ( F_84 ( V_34 , V_139 , & V_121 . V_4 ) )
F_89 () ;
if ( V_121 . V_4 > V_141 )
return V_132 ;
V_121 . V_5 = F_16 ( V_121 . V_4 , V_21 ) ;
if ( ! V_121 . V_5 )
return V_132 ;
if ( F_85 ( V_34 , V_139 + 4 , V_121 . V_5 , V_121 . V_4 ) )
goto V_40;
V_119 = F_68 ( V_123 , & V_140 , & V_121 ) ;
if ( V_119 != V_109 )
goto V_40;
if ( F_63 ( & V_34 -> V_102 [ 0 ] ) != V_117 )
goto V_40;
V_132 = 0 ;
V_40:
F_3 ( V_121 . V_5 ) ;
return V_132 ;
}
static inline int
F_90 ( struct V_97 * V_34 )
{
return V_34 -> V_102 [ 0 ] . V_84 + V_34 -> V_142 + V_34 -> V_143 [ 0 ] . V_84 ;
}
static void
F_91 ( struct V_97 * V_34 , int V_144 )
{
if ( V_34 -> V_142 == 0 ) {
V_34 -> V_102 [ 0 ] . V_84 -= V_144 ;
}
}
static int
F_92 ( struct V_89 * V_90 , struct V_97 * V_34 , T_4 V_117 , struct V_95 * V_123 )
{
T_4 V_145 , V_119 ;
int V_144 , V_146 , V_147 , V_148 ;
V_90 -> V_149 = 0 ;
V_145 = F_63 ( & V_34 -> V_102 [ 0 ] ) ;
if ( V_90 -> V_107 ) {
goto V_150;
}
V_147 = F_90 ( V_34 ) ;
if ( V_145 > V_147 )
return - V_39 ;
V_144 = V_147 - V_145 ;
V_34 -> V_4 -= V_144 ;
F_91 ( V_34 , V_144 ) ;
V_146 = V_34 -> V_4 ;
V_34 -> V_4 = V_145 ;
V_119 = F_93 ( V_123 , 0 , V_34 ) ;
V_144 = V_145 - V_34 -> V_4 ;
V_34 -> V_4 = V_146 ;
V_34 -> V_4 -= V_144 ;
V_148 = V_34 -> V_102 [ 0 ] . V_84 % 4 ;
if ( V_148 ) {
V_34 -> V_151 = V_152 ;
F_94 ( V_34 , V_148 ) ;
F_91 ( V_34 , V_144 ) ;
}
if ( V_119 != V_109 )
return - V_39 ;
V_150:
if ( F_63 ( & V_34 -> V_102 [ 0 ] ) != V_117 )
return - V_39 ;
return 0 ;
}
static int
F_95 ( struct V_89 * V_90 )
{
struct V_153 * V_154 = V_90 -> V_155 ;
struct V_46 * V_47 = V_154 -> V_47 ;
struct V_92 * V_93 = & V_154 -> V_156 ;
int V_132 ;
V_90 -> V_157 = F_76 ( V_47 -> V_49 , V_93 -> V_158 ) ;
if ( V_90 -> V_157 == NULL )
return V_105 ;
V_132 = F_96 ( V_90 ) ;
if ( V_132 == V_114 || V_132 == V_159 )
return V_132 ;
return V_108 ;
}
static inline int
F_97 ( struct V_28 * V_29 , struct V_89 * V_90 ,
struct V_1 * V_10 , int * V_26 )
{
struct V_46 * V_47 ;
int V_160 ;
if ( * V_26 != V_109 )
return F_70 ( V_90 ) ;
V_47 = F_53 ( V_29 , V_10 ) ;
if ( V_47 == NULL ) {
* V_26 = V_161 ;
return F_70 ( V_90 ) ;
}
V_160 = F_72 ( V_90 , V_47 -> V_49 , V_76 ) ;
F_27 ( & V_47 -> V_14 , V_29 ) ;
return V_160 ;
}
static inline int
F_98 ( struct V_92 * V_93 ,
struct V_80 * V_81 , T_6 * V_94 ,
struct V_1 * V_8 ,
struct V_1 * V_9 )
{
struct V_1 V_162 ;
* V_94 = V_104 ;
if ( V_81 -> V_84 < 2 * 4 )
return V_105 ;
if ( F_63 ( V_81 ) != V_116 )
return V_105 ;
if ( F_63 ( V_81 ) != 0 )
return V_105 ;
* V_94 = V_163 ;
if ( V_93 -> V_164 == V_165 && V_93 -> V_166 . V_4 != 0 )
return V_105 ;
if ( F_11 ( V_8 , & V_93 -> V_166 ) )
return V_159 ;
* V_94 = V_104 ;
if ( F_62 ( V_81 , & V_162 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_105 ;
}
if ( F_11 ( V_9 , & V_162 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_159 ;
}
return 0 ;
}
static inline int
F_99 ( struct V_80 * V_86 , T_7 V_167 ,
struct V_1 * V_10 , struct V_1 * V_11 ,
int V_26 , int V_27 )
{
if ( V_86 -> V_84 + 4 > V_167 )
return - 1 ;
F_65 ( V_86 , V_168 ) ;
if ( F_64 ( V_86 , V_10 ) )
return - 1 ;
if ( V_86 -> V_84 + 3 * 4 > V_167 )
return - 1 ;
F_65 ( V_86 , V_26 ) ;
F_65 ( V_86 , V_27 ) ;
F_65 ( V_86 , V_76 ) ;
if ( F_64 ( V_86 , V_11 ) )
return - 1 ;
return 0 ;
}
static int F_100 ( struct V_89 * V_90 ,
struct V_92 * V_93 , T_6 * V_94 )
{
struct V_80 * V_81 = & V_90 -> V_101 . V_102 [ 0 ] ;
struct V_80 * V_86 = & V_90 -> V_115 . V_102 [ 0 ] ;
struct V_6 * V_36 , V_169 ;
int V_170 ;
struct V_171 * V_172 = F_101 ( V_90 -> V_173 -> V_174 , V_175 ) ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_170 = F_98 ( V_93 , V_81 , V_94 ,
& V_169 . V_8 , & V_169 . V_9 ) ;
if ( V_170 )
return V_170 ;
V_36 = F_23 ( V_172 -> V_176 , & V_169 ) ;
F_2 ( & V_169 ) ;
if ( ! V_36 )
return V_159 ;
if ( F_54 ( V_172 -> V_176 , & V_36 -> V_14 , & V_90 -> V_177 ) < 0 )
return V_159 ;
V_170 = V_159 ;
if ( F_97 ( V_172 -> V_178 , V_90 ,
& V_36 -> V_10 , & V_36 -> V_26 ) )
goto V_40;
if ( F_99 ( V_86 , V_88 ,
& V_36 -> V_10 , & V_36 -> V_11 ,
V_36 -> V_26 , V_36 -> V_27 ) )
goto V_40;
V_170 = V_179 ;
V_40:
F_27 ( & V_36 -> V_14 , V_172 -> V_176 ) ;
return V_170 ;
}
static int
F_102 ( struct V_89 * V_90 , T_6 * V_94 )
{
struct V_80 * V_81 = & V_90 -> V_101 . V_102 [ 0 ] ;
struct V_80 * V_86 = & V_90 -> V_115 . V_102 [ 0 ] ;
T_4 V_180 ;
struct V_153 * V_154 = V_90 -> V_155 ;
struct V_92 * V_93 ;
struct V_46 * V_47 = NULL ;
T_6 * V_91 ;
T_6 * V_181 = V_86 -> V_85 + V_86 -> V_84 ;
int V_170 ;
struct V_171 * V_172 = F_101 ( V_90 -> V_173 -> V_174 , V_175 ) ;
F_69 ( L_4 ,
V_81 -> V_84 ) ;
* V_94 = V_163 ;
if ( ! V_154 )
V_154 = F_16 ( sizeof( * V_154 ) , V_21 ) ;
if ( ! V_154 )
goto V_182;
V_90 -> V_155 = V_154 ;
V_154 -> V_183 = NULL ;
V_154 -> V_47 = NULL ;
V_93 = & V_154 -> V_156 ;
V_91 = V_81 -> V_85 ;
V_91 -= 7 ;
if ( V_81 -> V_84 < 5 * 4 )
goto V_182;
V_180 = F_63 ( V_81 ) ;
if ( F_63 ( V_81 ) != V_184 )
goto V_182;
V_93 -> V_164 = F_63 ( V_81 ) ;
V_93 -> V_111 = F_63 ( V_81 ) ;
V_93 -> V_158 = F_63 ( V_81 ) ;
if ( F_62 ( V_81 , & V_93 -> V_166 ) )
goto V_182;
if ( V_180 != F_61 ( V_93 -> V_166 . V_4 ) + 5 * 4 )
goto V_182;
if ( ( V_93 -> V_164 != V_185 ) && ( V_90 -> V_186 != 0 ) )
goto V_182;
* V_94 = V_104 ;
switch ( V_93 -> V_164 ) {
case V_165 :
case V_187 :
return F_100 ( V_90 , V_93 , V_94 ) ;
case V_185 :
case V_188 :
* V_94 = V_110 ;
V_47 = F_53 ( V_172 -> V_178 , & V_93 -> V_166 ) ;
if ( ! V_47 )
goto V_182;
switch ( F_66 ( V_90 , V_47 , V_91 , V_93 , V_94 ) ) {
case V_108 :
break;
case V_105 :
goto V_182;
case V_114 :
goto V_79;
}
break;
default:
* V_94 = V_189 ;
goto V_182;
}
switch ( V_93 -> V_164 ) {
case V_188 :
if ( F_72 ( V_90 , V_47 -> V_49 , V_93 -> V_111 ) )
goto V_182;
V_47 -> V_14 . V_42 = F_103 () ;
F_43 ( V_63 , & V_47 -> V_14 . V_41 ) ;
if ( V_86 -> V_84 + 4 > V_88 )
goto V_79;
F_65 ( V_86 , V_168 ) ;
goto V_190;
case V_185 :
* V_94 = V_113 ;
V_154 -> V_183 = V_86 -> V_85 + V_86 -> V_84 ;
if ( F_72 ( V_90 , V_47 -> V_49 , V_93 -> V_111 ) )
goto V_182;
V_90 -> V_191 = V_47 -> V_50 ;
F_104 ( V_47 -> V_50 . V_53 ) ;
* V_94 = V_163 ;
switch ( V_93 -> V_158 ) {
case V_192 :
break;
case V_193 :
F_65 ( V_86 , 0 ) ;
F_65 ( V_86 , 0 ) ;
if ( F_87 ( & V_90 -> V_101 ,
V_93 -> V_111 , V_47 -> V_49 ) )
goto V_194;
break;
case V_195 :
F_65 ( V_86 , 0 ) ;
F_65 ( V_86 , 0 ) ;
if ( F_92 ( V_90 , & V_90 -> V_101 ,
V_93 -> V_111 , V_47 -> V_49 ) )
goto V_194;
break;
default:
goto V_182;
}
V_154 -> V_47 = V_47 ;
F_105 ( & V_47 -> V_14 ) ;
V_90 -> V_191 . V_196 = F_106 (
V_47 -> V_49 -> V_126 , V_93 -> V_158 ) ;
V_170 = V_108 ;
goto V_40;
}
V_194:
V_170 = V_197 ;
goto V_40;
V_182:
F_71 ( V_90 , V_181 ) ;
V_170 = V_105 ;
goto V_40;
V_190:
V_170 = V_179 ;
goto V_40;
V_79:
V_170 = V_114 ;
V_40:
if ( V_47 )
F_27 ( & V_47 -> V_14 , V_172 -> V_178 ) ;
return V_170 ;
}
static T_6 *
F_107 ( struct V_97 * V_198 , struct V_153 * V_199 )
{
T_6 * V_87 ;
T_4 V_200 ;
V_87 = V_199 -> V_183 ;
V_199 -> V_183 = NULL ;
if ( * ( V_87 - 1 ) != V_201 )
return NULL ;
V_87 += 1 ;
V_200 = F_86 ( * V_87 ++ ) ;
V_87 += F_75 ( V_200 ) ;
memcpy ( V_87 , V_87 + 2 , 4 ) ;
if ( * V_87 != V_201 ) {
V_198 -> V_102 [ 0 ] . V_84 -= 2 * 4 ;
return NULL ;
}
V_87 ++ ;
return V_87 ;
}
static inline int
F_108 ( struct V_89 * V_90 )
{
struct V_153 * V_199 = (struct V_153 * ) V_90 -> V_155 ;
struct V_92 * V_93 = & V_199 -> V_156 ;
struct V_97 * V_198 = & V_90 -> V_115 ;
struct V_97 V_140 ;
struct V_1 V_121 ;
struct V_80 * V_86 ;
T_6 * V_87 ;
int V_202 , V_139 ;
int V_132 = - V_39 ;
V_87 = F_107 ( V_198 , V_199 ) ;
if ( V_87 == NULL )
goto V_40;
V_202 = ( T_5 * ) ( V_87 + 1 ) - ( T_5 * ) V_198 -> V_102 [ 0 ] . V_85 ;
V_139 = V_198 -> V_4 - V_202 ;
F_14 ( V_139 % 4 ) ;
* V_87 ++ = F_73 ( V_139 ) ;
* V_87 ++ = F_73 ( V_93 -> V_111 ) ;
if ( F_88 ( V_198 , & V_140 , V_202 ,
V_139 ) )
F_89 () ;
if ( V_198 -> V_143 [ 0 ] . V_85 == NULL ) {
if ( V_198 -> V_102 [ 0 ] . V_84 + V_141 > V_88 )
goto V_203;
V_198 -> V_143 [ 0 ] . V_85 = V_198 -> V_102 [ 0 ] . V_85
+ V_198 -> V_102 [ 0 ] . V_84 ;
V_198 -> V_143 [ 0 ] . V_84 = 0 ;
V_86 = & V_198 -> V_143 [ 0 ] ;
} else {
V_86 = & V_198 -> V_143 [ 0 ] ;
}
V_121 . V_5 = ( T_5 * ) V_86 -> V_85 + V_86 -> V_84 + 4 ;
if ( F_74 ( V_199 -> V_47 -> V_49 , & V_140 , & V_121 ) )
goto V_203;
F_65 ( V_86 , V_121 . V_4 ) ;
memset ( V_121 . V_5 + V_121 . V_4 , 0 ,
F_61 ( V_121 . V_4 ) - V_121 . V_4 ) ;
V_86 -> V_84 += F_75 ( V_121 . V_4 ) << 2 ;
V_198 -> V_4 += F_75 ( V_121 . V_4 ) << 2 ;
F_14 ( V_86 -> V_84 > V_88 ) ;
V_40:
V_132 = 0 ;
V_203:
return V_132 ;
}
static inline int
F_109 ( struct V_89 * V_90 )
{
struct V_153 * V_199 = (struct V_153 * ) V_90 -> V_155 ;
struct V_92 * V_93 = & V_199 -> V_156 ;
struct V_97 * V_198 = & V_90 -> V_115 ;
struct V_204 * * V_205 = NULL ;
T_6 * V_87 , * V_4 ;
int V_148 ;
int V_144 ;
V_87 = F_107 ( V_198 , V_199 ) ;
if ( V_87 == NULL )
return 0 ;
V_4 = V_87 ++ ;
V_148 = ( T_5 * ) V_87 - ( T_5 * ) V_198 -> V_102 [ 0 ] . V_85 ;
* V_87 ++ = F_73 ( V_93 -> V_111 ) ;
V_205 = V_198 -> V_206 ;
if ( V_198 -> V_143 [ 0 ] . V_85 ) {
F_14 ( V_198 -> V_143 [ 0 ] . V_85 >= V_198 -> V_102 [ 0 ] . V_85
+ V_88 ) ;
F_14 ( V_198 -> V_143 [ 0 ] . V_85 < V_198 -> V_102 [ 0 ] . V_85 ) ;
if ( V_198 -> V_143 [ 0 ] . V_84 + V_198 -> V_102 [ 0 ] . V_84
+ 2 * V_141 > V_88 )
return - V_22 ;
memmove ( V_198 -> V_143 [ 0 ] . V_85 + V_141 ,
V_198 -> V_143 [ 0 ] . V_85 ,
V_198 -> V_143 [ 0 ] . V_84 ) ;
V_198 -> V_143 [ 0 ] . V_85 += V_141 ;
}
if ( V_198 -> V_143 [ 0 ] . V_85 == NULL ) {
if ( V_198 -> V_102 [ 0 ] . V_84 + 2 * V_141 > V_88 )
return - V_22 ;
V_198 -> V_143 [ 0 ] . V_85 = V_198 -> V_102 [ 0 ] . V_85
+ V_198 -> V_102 [ 0 ] . V_84 + V_141 ;
V_198 -> V_143 [ 0 ] . V_84 = 0 ;
}
if ( F_110 ( V_199 -> V_47 -> V_49 , V_148 , V_198 , V_205 ) )
return - V_22 ;
* V_4 = F_73 ( V_198 -> V_4 - V_148 ) ;
V_144 = 3 - ( ( V_198 -> V_4 - V_148 - 1 ) & 3 ) ;
V_87 = ( T_6 * ) ( V_198 -> V_143 [ 0 ] . V_85 + V_198 -> V_143 [ 0 ] . V_84 ) ;
memset ( V_87 , 0 , V_144 ) ;
V_198 -> V_143 [ 0 ] . V_84 += V_144 ;
V_198 -> V_4 += V_144 ;
return 0 ;
}
static int
F_111 ( struct V_89 * V_90 )
{
struct V_153 * V_199 = (struct V_153 * ) V_90 -> V_155 ;
struct V_92 * V_93 = & V_199 -> V_156 ;
struct V_97 * V_198 = & V_90 -> V_115 ;
int V_132 = - V_39 ;
struct V_171 * V_172 = F_101 ( V_90 -> V_173 -> V_174 , V_175 ) ;
if ( V_93 -> V_164 != V_185 )
goto V_40;
if ( V_199 -> V_183 == NULL )
goto V_40;
V_198 -> V_4 = F_90 ( V_198 ) ;
switch ( V_93 -> V_158 ) {
case V_192 :
break;
case V_193 :
V_132 = F_108 ( V_90 ) ;
if ( V_132 )
goto V_203;
break;
case V_195 :
V_132 = F_109 ( V_90 ) ;
if ( V_132 )
goto V_203;
break;
}
V_40:
V_132 = 0 ;
V_203:
if ( V_90 -> V_207 )
F_83 ( V_90 -> V_207 ) ;
V_90 -> V_207 = NULL ;
if ( V_90 -> V_157 )
F_83 ( V_90 -> V_157 ) ;
V_90 -> V_157 = NULL ;
if ( V_90 -> V_191 . V_53 )
F_112 ( V_90 -> V_191 . V_53 ) ;
V_90 -> V_191 . V_53 = NULL ;
if ( V_199 -> V_47 )
F_27 ( & V_199 -> V_47 -> V_14 , V_172 -> V_178 ) ;
V_199 -> V_47 = NULL ;
return V_132 ;
}
static void
F_113 ( struct V_122 * V_127 )
{
struct V_128 * V_129 = F_5 ( V_127 , struct V_128 , V_14 ) ;
F_3 ( V_127 -> V_125 ) ;
F_3 ( V_129 ) ;
}
static int F_114 ( struct V_208 * V_208 )
{
struct V_171 * V_172 = F_101 ( V_208 , V_175 ) ;
struct V_28 * V_29 ;
int V_209 ;
V_29 = F_115 ( & V_210 , V_208 ) ;
if ( F_116 ( V_29 ) )
return F_117 ( V_29 ) ;
V_209 = F_118 ( V_29 , V_208 ) ;
if ( V_209 ) {
F_119 ( V_29 , V_208 ) ;
return V_209 ;
}
V_172 -> V_176 = V_29 ;
return 0 ;
}
static void F_120 ( struct V_208 * V_208 )
{
struct V_171 * V_172 = F_101 ( V_208 , V_175 ) ;
struct V_28 * V_29 = V_172 -> V_176 ;
V_172 -> V_176 = NULL ;
F_121 ( V_29 ) ;
F_122 ( V_29 , V_208 ) ;
F_119 ( V_29 , V_208 ) ;
}
static int F_123 ( struct V_208 * V_208 )
{
struct V_171 * V_172 = F_101 ( V_208 , V_175 ) ;
struct V_28 * V_29 ;
int V_209 ;
V_29 = F_115 ( & V_211 , V_208 ) ;
if ( F_116 ( V_29 ) )
return F_117 ( V_29 ) ;
V_209 = F_118 ( V_29 , V_208 ) ;
if ( V_209 ) {
F_119 ( V_29 , V_208 ) ;
return V_209 ;
}
V_172 -> V_178 = V_29 ;
return 0 ;
}
static void F_124 ( struct V_208 * V_208 )
{
struct V_171 * V_172 = F_101 ( V_208 , V_175 ) ;
struct V_28 * V_29 = V_172 -> V_178 ;
V_172 -> V_178 = NULL ;
F_121 ( V_29 ) ;
F_122 ( V_29 , V_208 ) ;
F_119 ( V_29 , V_208 ) ;
}
int
F_125 ( struct V_208 * V_208 )
{
int V_57 ;
V_57 = F_123 ( V_208 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_114 ( V_208 ) ;
if ( V_57 )
goto V_212;
return 0 ;
V_212:
F_124 ( V_208 ) ;
return V_57 ;
}
void
F_126 ( struct V_208 * V_208 )
{
F_120 ( V_208 ) ;
F_124 ( V_208 ) ;
}
int
F_127 ( void )
{
return F_128 ( V_106 , & V_135 ) ;
}
void
F_129 ( void )
{
F_130 ( V_106 ) ;
}
