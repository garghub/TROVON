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
V_47 . V_50 . V_68 -> V_70 [ V_63 ] = V_69 ;
}
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_59 = V_47 . V_50 . V_71 = F_47 ( V_34 ) ;
V_38 = - V_72 ;
if ( ! V_59 )
goto V_40;
V_38 = - V_39 ;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = F_48 ( V_34 , V_4 , V_59 , & V_47 . V_49 ,
NULL , V_21 ) ;
if ( V_38 )
goto V_40;
V_4 = F_20 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 > 0 ) {
V_47 . V_50 . V_73 = F_49 ( V_34 , V_21 ) ;
if ( ! V_47 . V_50 . V_73 ) {
V_38 = - V_22 ;
goto V_40;
}
}
}
V_47 . V_14 . V_42 = V_37 ;
V_57 = F_50 ( V_29 , & V_47 , V_57 ) ;
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
static struct V_46 * F_50 ( struct V_28 * V_29 , struct V_46 * V_25 , struct V_46 * V_45 )
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
F_51 ( struct V_28 * V_29 , struct V_1 * V_48 )
{
struct V_46 V_47 ;
struct V_46 * V_74 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( F_9 ( & V_47 . V_48 , V_48 -> V_5 , V_48 -> V_4 ) )
return NULL ;
V_74 = F_40 ( V_29 , & V_47 ) ;
F_28 ( & V_47 ) ;
if ( ! V_74 )
return NULL ;
if ( F_52 ( V_29 , & V_74 -> V_14 , NULL ) )
return NULL ;
return V_74 ;
}
static int
F_53 ( struct V_46 * V_47 , int V_75 )
{
struct V_76 * V_77 = & V_47 -> V_53 ;
F_54 ( & V_77 -> V_54 ) ;
if ( V_75 > V_77 -> V_78 ) {
if ( V_75 >= V_77 -> V_78 + V_79 ) {
memset ( V_77 -> V_80 , 0 , sizeof( V_77 -> V_80 ) ) ;
V_77 -> V_78 = V_75 ;
} else while ( V_77 -> V_78 < V_75 ) {
V_77 -> V_78 ++ ;
F_55 ( V_77 -> V_78 % V_79 , V_77 -> V_80 ) ;
}
F_56 ( V_75 % V_79 , V_77 -> V_80 ) ;
goto V_81;
} else if ( V_75 <= V_77 -> V_78 - V_79 ) {
goto V_82;
}
if ( F_57 ( V_75 % V_79 , V_77 -> V_80 ) )
goto V_82;
V_81:
F_58 ( & V_77 -> V_54 ) ;
return 1 ;
V_82:
F_58 ( & V_77 -> V_54 ) ;
return 0 ;
}
static inline T_3 F_59 ( T_3 V_63 )
{
return ( V_63 + 3 ) & ~ 3 ;
}
static inline int
F_60 ( struct V_83 * V_84 , struct V_1 * V_85 )
{
int V_86 ;
if ( V_84 -> V_87 < 4 )
return - 1 ;
V_85 -> V_4 = F_61 ( V_84 ) ;
V_86 = F_59 ( V_85 -> V_4 ) ;
if ( V_84 -> V_87 < V_86 )
return - 1 ;
V_85 -> V_5 = V_84 -> V_88 ;
V_84 -> V_88 += V_86 ;
V_84 -> V_87 -= V_86 ;
return 0 ;
}
static inline int
F_62 ( struct V_83 * V_89 , struct V_1 * V_85 )
{
T_4 * V_90 ;
if ( V_89 -> V_87 + 4 > V_91 )
return - 1 ;
F_63 ( V_89 , V_85 -> V_4 ) ;
V_90 = V_89 -> V_88 + V_89 -> V_87 ;
V_89 -> V_87 += F_59 ( V_85 -> V_4 ) ;
if ( V_89 -> V_87 > V_91 )
return - 1 ;
memcpy ( V_90 , V_85 -> V_5 , V_85 -> V_4 ) ;
memset ( V_90 + V_85 -> V_4 , 0 , F_59 ( V_85 -> V_4 ) - V_85 -> V_4 ) ;
return 0 ;
}
static int
F_64 ( struct V_92 * V_93 , struct V_46 * V_47 ,
T_5 * V_94 , struct V_95 * V_96 , T_5 * V_97 )
{
struct V_98 * V_99 = V_47 -> V_49 ;
struct V_100 V_101 ;
struct V_1 V_102 ;
T_3 V_103 = 0 ;
struct V_83 * V_84 = & V_93 -> V_104 . V_105 [ 0 ] ;
struct V_83 V_106 ;
V_106 . V_88 = V_94 ;
V_106 . V_87 = ( T_4 * ) V_84 -> V_88 - ( T_4 * ) V_94 ;
F_65 ( & V_106 , & V_101 ) ;
* V_97 = V_107 ;
if ( V_84 -> V_87 < 4 )
return V_108 ;
V_103 = F_61 ( V_84 ) ;
if ( V_103 != V_109 )
return V_108 ;
if ( F_60 ( V_84 , & V_102 ) )
return V_108 ;
if ( V_93 -> V_110 )
return V_111 ;
if ( F_66 ( V_99 , & V_101 , & V_102 ) != V_112 ) {
* V_97 = V_113 ;
return V_108 ;
}
if ( V_96 -> V_114 > V_115 ) {
F_67 ( L_1
L_2 , V_96 -> V_114 ) ;
* V_97 = V_116 ;
return V_108 ;
}
if ( ! F_53 ( V_47 , V_96 -> V_114 ) ) {
F_67 ( L_1
L_3 , V_96 -> V_114 ) ;
return V_117 ;
}
return V_111 ;
}
static int
F_68 ( struct V_92 * V_93 )
{
T_5 * V_90 ;
F_63 ( V_93 -> V_118 . V_105 , V_119 ) ;
V_90 = V_93 -> V_118 . V_105 -> V_88 + V_93 -> V_118 . V_105 -> V_87 ;
* V_90 ++ = 0 ;
if ( ! F_69 ( V_93 , V_90 ) )
return - 1 ;
return 0 ;
}
static int
F_70 ( struct V_92 * V_93 , struct V_98 * V_99 , T_3 V_120 )
{
T_5 * V_121 ;
T_3 V_122 ;
struct V_100 V_123 ;
struct V_1 V_124 ;
T_5 * V_90 ;
struct V_83 V_106 ;
int V_125 = - 1 ;
F_63 ( V_93 -> V_118 . V_105 , V_109 ) ;
V_121 = F_16 ( 4 , V_21 ) ;
if ( ! V_121 )
return - 1 ;
* V_121 = F_71 ( V_120 ) ;
V_106 . V_88 = V_121 ;
V_106 . V_87 = 4 ;
F_65 ( & V_106 , & V_123 ) ;
V_90 = V_93 -> V_118 . V_105 -> V_88 + V_93 -> V_118 . V_105 -> V_87 ;
V_124 . V_5 = ( T_4 * ) ( V_90 + 1 ) ;
V_122 = F_72 ( V_99 , & V_123 , & V_124 ) ;
if ( V_122 != V_112 )
goto V_40;
* V_90 ++ = F_71 ( V_124 . V_4 ) ;
memset ( ( T_4 * ) V_90 + V_124 . V_4 , 0 , F_59 ( V_124 . V_4 ) - V_124 . V_4 ) ;
V_90 += F_73 ( V_124 . V_4 ) ;
if ( ! F_69 ( V_93 , V_90 ) )
goto V_40;
V_125 = 0 ;
V_40:
F_3 ( V_121 ) ;
return V_125 ;
}
static struct V_126 *
F_74 ( struct V_98 * V_127 , T_3 V_128 )
{
char * V_129 ;
V_129 = F_75 ( V_127 -> V_130 , V_128 ) ;
if ( ! V_129 )
return NULL ;
return F_76 ( V_129 ) ;
}
T_3 F_77 ( struct V_126 * V_131 )
{
struct V_132 * V_133 = F_5 ( V_131 , struct V_132 , V_14 ) ;
return V_133 -> V_134 ;
}
int
F_78 ( T_3 V_134 , char * V_129 )
{
struct V_132 * V_25 ;
struct V_126 * V_135 ;
int V_136 = - V_22 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
goto V_40;
F_79 ( & V_25 -> V_14 . V_13 ) ;
V_25 -> V_14 . V_129 = F_49 ( V_129 , V_21 ) ;
if ( ! V_25 -> V_14 . V_129 )
goto V_137;
V_25 -> V_14 . V_138 = & V_139 ;
V_25 -> V_134 = V_134 ;
V_136 = 0 ;
V_135 = F_80 ( V_129 , & V_25 -> V_14 ) ;
if ( V_135 != & V_25 -> V_14 ) {
F_81 ( V_135 ) ;
F_3 ( V_25 -> V_14 . V_129 ) ;
goto V_137;
}
return 0 ;
V_137:
F_3 ( V_25 ) ;
V_40:
return V_136 ;
}
static inline int
F_82 ( struct V_100 * V_34 , int V_140 , T_3 * V_141 )
{
T_5 V_142 ;
int V_38 ;
V_38 = F_83 ( V_34 , V_140 , & V_142 , sizeof( * V_141 ) ) ;
if ( V_38 )
return V_38 ;
* V_141 = F_84 ( V_142 ) ;
return 0 ;
}
static int
F_85 ( struct V_92 * V_93 , struct V_100 * V_34 , T_3 V_120 , struct V_98 * V_127 )
{
int V_136 = - V_39 ;
T_3 V_143 , V_122 ;
struct V_1 V_124 ;
struct V_100 V_144 ;
if ( V_93 -> V_110 )
return 0 ;
V_143 = F_61 ( & V_34 -> V_105 [ 0 ] ) ;
if ( V_143 & 3 )
return V_136 ;
if ( V_143 > V_34 -> V_4 )
return V_136 ;
if ( F_86 ( V_34 , & V_144 , 0 , V_143 ) )
F_87 () ;
if ( F_82 ( V_34 , V_143 , & V_124 . V_4 ) )
F_87 () ;
if ( V_124 . V_4 > V_145 )
return V_136 ;
V_124 . V_5 = F_16 ( V_124 . V_4 , V_21 ) ;
if ( ! V_124 . V_5 )
return V_136 ;
if ( F_83 ( V_34 , V_143 + 4 , V_124 . V_5 , V_124 . V_4 ) )
goto V_40;
V_122 = F_66 ( V_127 , & V_144 , & V_124 ) ;
if ( V_122 != V_112 )
goto V_40;
if ( F_61 ( & V_34 -> V_105 [ 0 ] ) != V_120 )
goto V_40;
F_88 ( V_34 , F_59 ( V_124 . V_4 ) + 4 ) ;
V_136 = 0 ;
V_40:
F_3 ( V_124 . V_5 ) ;
return V_136 ;
}
static inline int
F_89 ( struct V_100 * V_34 )
{
return V_34 -> V_105 [ 0 ] . V_87 + V_34 -> V_146 + V_34 -> V_147 [ 0 ] . V_87 ;
}
static void
F_90 ( struct V_100 * V_34 , int V_148 )
{
if ( V_34 -> V_146 == 0 ) {
V_34 -> V_105 [ 0 ] . V_87 -= V_148 ;
}
}
static int
F_91 ( struct V_92 * V_93 , struct V_100 * V_34 , T_3 V_120 , struct V_98 * V_127 )
{
T_3 V_149 , V_122 ;
int V_148 , V_150 , V_151 , V_152 ;
F_92 ( V_153 , & V_93 -> V_154 ) ;
V_149 = F_61 ( & V_34 -> V_105 [ 0 ] ) ;
if ( V_93 -> V_110 ) {
goto V_155;
}
V_151 = F_89 ( V_34 ) ;
if ( V_149 > V_151 )
return - V_39 ;
V_148 = V_151 - V_149 ;
V_34 -> V_4 -= V_148 ;
F_90 ( V_34 , V_148 ) ;
V_150 = V_34 -> V_4 ;
V_34 -> V_4 = V_149 ;
V_122 = F_93 ( V_127 , 0 , V_34 ) ;
V_148 = V_149 - V_34 -> V_4 ;
V_34 -> V_4 = V_150 ;
V_34 -> V_4 -= V_148 ;
V_152 = V_34 -> V_105 [ 0 ] . V_87 % 4 ;
if ( V_152 ) {
V_34 -> V_156 = V_157 ;
F_94 ( V_34 , V_152 ) ;
F_90 ( V_34 , V_148 ) ;
}
if ( V_122 != V_112 )
return - V_39 ;
V_155:
if ( F_61 ( & V_34 -> V_105 [ 0 ] ) != V_120 )
return - V_39 ;
return 0 ;
}
static int
F_95 ( struct V_92 * V_93 )
{
struct V_158 * V_159 = V_93 -> V_160 ;
struct V_46 * V_47 = V_159 -> V_47 ;
struct V_95 * V_96 = & V_159 -> V_161 ;
int V_136 ;
V_93 -> V_162 = F_74 ( V_47 -> V_49 , V_96 -> V_163 ) ;
if ( V_93 -> V_162 == NULL )
return V_108 ;
V_136 = F_96 ( V_93 ) ;
if ( V_136 == V_117 || V_136 == V_164 )
return V_136 ;
return V_111 ;
}
static inline int
F_97 ( struct V_28 * V_29 , struct V_92 * V_93 ,
struct V_1 * V_10 , int * V_26 )
{
struct V_46 * V_47 ;
int V_165 ;
if ( * V_26 != V_112 )
return F_68 ( V_93 ) ;
V_47 = F_51 ( V_29 , V_10 ) ;
if ( V_47 == NULL ) {
* V_26 = V_166 ;
return F_68 ( V_93 ) ;
}
V_165 = F_70 ( V_93 , V_47 -> V_49 , V_79 ) ;
F_25 ( & V_47 -> V_14 , V_29 ) ;
return V_165 ;
}
static inline int
F_98 ( struct V_95 * V_96 ,
struct V_83 * V_84 , T_5 * V_97 ,
struct V_1 * V_8 )
{
* V_97 = V_107 ;
if ( V_84 -> V_87 < 2 * 4 )
return V_108 ;
if ( F_61 ( V_84 ) != V_119 )
return V_108 ;
if ( F_61 ( V_84 ) != 0 )
return V_108 ;
* V_97 = V_167 ;
if ( V_96 -> V_168 == V_169 && V_96 -> V_170 . V_4 != 0 )
return V_108 ;
if ( F_11 ( V_8 , & V_96 -> V_170 ) )
return V_164 ;
* V_97 = V_107 ;
return 0 ;
}
static inline int
F_99 ( struct V_95 * V_96 ,
struct V_83 * V_84 , T_5 * V_97 ,
struct V_1 * V_8 ,
struct V_1 * V_9 )
{
struct V_1 V_171 ;
int V_172 ;
V_172 = F_98 ( V_96 , V_84 , V_97 , V_8 ) ;
if ( V_172 )
return V_172 ;
if ( F_60 ( V_84 , & V_171 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_108 ;
}
if ( F_11 ( V_9 , & V_171 ) ) {
F_3 ( V_8 -> V_5 ) ;
return V_164 ;
}
return 0 ;
}
static inline int
F_100 ( struct V_92 * V_93 ,
struct V_95 * V_96 , T_5 * V_97 ,
struct V_1 * V_8 ,
struct V_173 * V_9 )
{
struct V_83 * V_84 = & V_93 -> V_104 . V_105 [ 0 ] ;
T_3 V_174 ;
int V_172 ;
V_172 = F_98 ( V_96 , V_84 , V_97 , V_8 ) ;
if ( V_172 )
return V_172 ;
V_174 = F_61 ( V_84 ) ;
if ( V_174 > ( V_84 -> V_87 + V_93 -> V_104 . V_146 ) )
return V_108 ;
V_9 -> V_175 = V_93 -> V_176 ;
V_9 -> V_177 = ( V_178 ) V_84 -> V_88 & ~ V_179 ;
V_9 -> V_146 = V_174 ;
return 0 ;
}
static inline int
F_101 ( struct V_83 * V_89 , T_6 V_180 ,
struct V_1 * V_10 , struct V_1 * V_11 ,
int V_26 , int V_27 )
{
if ( V_89 -> V_87 + 4 > V_180 )
return - 1 ;
F_63 ( V_89 , V_181 ) ;
if ( F_62 ( V_89 , V_10 ) )
return - 1 ;
if ( V_89 -> V_87 + 3 * 4 > V_180 )
return - 1 ;
F_63 ( V_89 , V_26 ) ;
F_63 ( V_89 , V_27 ) ;
F_63 ( V_89 , V_79 ) ;
if ( F_62 ( V_89 , V_11 ) )
return - 1 ;
return 0 ;
}
static int F_102 ( struct V_92 * V_93 ,
struct V_95 * V_96 , T_5 * V_97 )
{
struct V_83 * V_84 = & V_93 -> V_104 . V_105 [ 0 ] ;
struct V_83 * V_89 = & V_93 -> V_118 . V_105 [ 0 ] ;
struct V_6 * V_36 , V_182 ;
int V_183 ;
struct V_184 * V_185 = F_103 ( V_93 -> V_186 -> V_187 , V_188 ) ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_183 = F_99 ( V_96 , V_84 , V_97 ,
& V_182 . V_8 , & V_182 . V_9 ) ;
if ( V_183 )
return V_183 ;
V_36 = F_21 ( V_185 -> V_189 , & V_182 ) ;
F_2 ( & V_182 ) ;
if ( ! V_36 )
return V_164 ;
if ( F_52 ( V_185 -> V_189 , & V_36 -> V_14 , & V_93 -> V_190 ) < 0 )
return V_164 ;
V_183 = V_164 ;
if ( F_97 ( V_185 -> V_191 , V_93 ,
& V_36 -> V_10 , & V_36 -> V_26 ) )
goto V_40;
if ( F_101 ( V_89 , V_91 ,
& V_36 -> V_10 , & V_36 -> V_11 ,
V_36 -> V_26 , V_36 -> V_27 ) )
goto V_40;
V_183 = V_192 ;
V_40:
F_25 ( & V_36 -> V_14 , V_185 -> V_189 ) ;
return V_183 ;
}
static int F_104 ( struct V_28 * V_29 ,
struct V_193 * V_194 ,
T_7 * V_48 )
{
struct V_46 V_47 , * V_57 = NULL ;
static T_8 V_195 ;
long long V_196 ;
struct V_58 * V_59 = NULL ;
T_1 V_37 ;
int V_38 = - V_39 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_38 = - V_22 ;
V_196 = F_105 ( & V_195 ) ;
* V_48 = V_196 ;
if ( F_9 ( & V_47 . V_48 , ( char * ) V_48 , sizeof( T_7 ) ) )
goto V_40;
V_57 = F_40 ( V_29 , & V_47 ) ;
if ( ! V_57 )
goto V_40;
if ( ! V_194 -> V_197 ) {
F_67 ( L_4 ) ;
goto V_40;
} else {
V_47 . V_50 = V_194 -> V_198 ;
memset ( & V_194 -> V_198 , 0 , sizeof( struct V_199 ) ) ;
V_38 = - V_72 ;
V_59 = F_106 ( & V_194 -> V_200 ) ;
if ( ! V_59 )
goto V_40;
V_47 . V_50 . V_71 = V_59 ;
V_38 = - V_39 ;
V_38 = F_48 ( V_194 -> V_10 . V_5 ,
V_194 -> V_10 . V_4 ,
V_59 , & V_47 . V_49 ,
& V_37 , V_21 ) ;
if ( V_38 )
goto V_40;
}
V_47 . V_14 . V_42 = V_37 ;
V_57 = F_50 ( V_29 , & V_47 , V_57 ) ;
V_38 = 0 ;
V_40:
F_28 ( & V_47 ) ;
if ( V_57 )
F_25 ( & V_57 -> V_14 , V_29 ) ;
else
V_38 = - V_22 ;
return V_38 ;
}
static int F_107 ( struct V_92 * V_93 ,
struct V_95 * V_96 , T_5 * V_97 )
{
struct V_83 * V_89 = & V_93 -> V_118 . V_105 [ 0 ] ;
struct V_1 V_201 ;
struct V_193 V_194 ;
T_7 V_48 ;
int V_38 ;
int V_183 ;
struct V_202 * V_202 = V_93 -> V_186 -> V_187 ;
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_183 = F_100 ( V_93 , V_96 , V_97 ,
& V_194 . V_8 , & V_194 . V_9 ) ;
if ( V_183 )
return V_183 ;
V_183 = V_164 ;
V_38 = F_108 ( V_202 , & V_194 ) ;
if ( V_38 )
goto V_40;
F_67 ( L_5
L_6 ,
V_194 . V_26 , V_194 . V_27 ) ;
switch ( V_194 . V_26 ) {
case V_203 :
V_201 = V_194 . V_10 ;
break;
case V_112 :
V_38 = F_104 ( V_185 -> V_191 , & V_194 , & V_48 ) ;
if ( V_38 )
goto V_40;
V_201 . V_5 = ( T_4 * ) & V_48 ;
V_201 . V_4 = sizeof( V_48 ) ;
break;
default:
V_183 = V_164 ;
goto V_40;
}
if ( F_97 ( V_185 -> V_191 , V_93 ,
& V_201 , & V_194 . V_26 ) )
goto V_40;
if ( F_101 ( V_89 , V_91 ,
& V_201 , & V_194 . V_11 ,
V_194 . V_26 , V_194 . V_27 ) )
goto V_40;
V_183 = V_192 ;
V_40:
F_109 ( & V_194 ) ;
return V_183 ;
}
static int F_110 ( struct V_202 * V_202 , int type )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
int V_183 ;
F_111 ( type != 0 && type != 1 ) ;
V_183 = F_112 ( & V_185 -> V_204 , - 1 , type ) ;
if ( V_183 != - 1 && V_183 != type )
return - V_205 ;
return 0 ;
}
static bool V_204 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
if ( V_185 -> V_204 == - 1 )
F_110 ( V_202 , 0 ) ;
return V_185 -> V_204 ;
}
static T_9 F_113 ( struct V_206 * V_206 , const char T_10 * V_34 ,
T_6 V_207 , T_11 * V_208 )
{
struct V_202 * V_202 = F_114 ( F_115 ( V_206 ) ) ;
char V_209 [ 20 ] ;
unsigned long V_63 ;
int V_172 ;
if ( * V_208 || V_207 > sizeof( V_209 ) - 1 )
return - V_39 ;
if ( F_116 ( V_209 , V_34 , V_207 ) )
return - V_210 ;
V_209 [ V_207 ] = 0 ;
V_172 = F_117 ( V_209 , 0 , & V_63 ) ;
if ( V_172 )
return V_172 ;
if ( V_63 != 1 )
return - V_39 ;
V_172 = F_118 ( V_202 ) ;
if ( V_172 )
return V_172 ;
V_172 = F_110 ( V_202 , 1 ) ;
if ( V_172 )
return V_172 ;
return V_207 ;
}
static T_9 F_119 ( struct V_206 * V_206 , char T_10 * V_34 ,
T_6 V_207 , T_11 * V_208 )
{
struct V_202 * V_202 = F_114 ( F_115 ( V_206 ) ) ;
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
unsigned long V_90 = * V_208 ;
char V_209 [ 10 ] ;
T_6 V_4 ;
snprintf ( V_209 , sizeof( V_209 ) , L_7 , V_185 -> V_204 ) ;
V_4 = strlen ( V_209 ) ;
if ( V_90 >= V_4 )
return 0 ;
V_4 -= V_90 ;
if ( V_4 > V_207 )
V_4 = V_207 ;
if ( F_120 ( V_34 , ( void * ) ( V_209 + V_90 ) , V_4 ) )
return - V_210 ;
* V_208 += V_4 ;
return V_4 ;
}
static int F_121 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
struct V_211 * * V_90 = & V_185 -> V_212 ;
V_185 -> V_204 = - 1 ;
* V_90 = F_122 ( L_8 , V_213 | V_214 | V_215 ,
V_185 -> V_216 ,
& V_217 , V_202 ) ;
if ( ! * V_90 )
return - V_22 ;
F_123 ( V_185 ) ;
return 0 ;
}
static void F_124 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
if ( V_185 -> V_212 ) {
F_125 ( L_8 , V_185 -> V_216 ) ;
F_126 ( V_185 ) ;
}
}
static int F_121 ( struct V_202 * V_202 )
{
return 0 ;
}
static void F_124 ( struct V_202 * V_202 ) {}
static int
F_127 ( struct V_92 * V_93 , T_5 * V_97 )
{
struct V_83 * V_84 = & V_93 -> V_104 . V_105 [ 0 ] ;
struct V_83 * V_89 = & V_93 -> V_118 . V_105 [ 0 ] ;
T_3 V_218 ;
struct V_158 * V_159 = V_93 -> V_160 ;
struct V_95 * V_96 ;
struct V_46 * V_47 = NULL ;
T_5 * V_94 ;
T_5 * V_219 = V_89 -> V_88 + V_89 -> V_87 ;
int V_183 ;
struct V_184 * V_185 = F_103 ( V_93 -> V_186 -> V_187 , V_188 ) ;
F_67 ( L_9 ,
V_84 -> V_87 ) ;
* V_97 = V_167 ;
if ( ! V_159 )
V_159 = F_16 ( sizeof( * V_159 ) , V_21 ) ;
if ( ! V_159 )
goto V_220;
V_93 -> V_160 = V_159 ;
V_159 -> V_221 = NULL ;
V_159 -> V_47 = NULL ;
V_96 = & V_159 -> V_161 ;
V_94 = V_84 -> V_88 ;
V_94 -= 7 ;
if ( V_84 -> V_87 < 5 * 4 )
goto V_220;
V_218 = F_61 ( V_84 ) ;
if ( F_61 ( V_84 ) != V_222 )
goto V_220;
V_96 -> V_168 = F_61 ( V_84 ) ;
V_96 -> V_114 = F_61 ( V_84 ) ;
V_96 -> V_163 = F_61 ( V_84 ) ;
if ( F_60 ( V_84 , & V_96 -> V_170 ) )
goto V_220;
if ( V_218 != F_59 ( V_96 -> V_170 . V_4 ) + 5 * 4 )
goto V_220;
if ( ( V_96 -> V_168 != V_223 ) && ( V_93 -> V_224 != 0 ) )
goto V_220;
* V_97 = V_107 ;
switch ( V_96 -> V_168 ) {
case V_169 :
case V_225 :
if ( V_204 ( F_128 ( V_93 ) ) )
return F_107 ( V_93 , V_96 , V_97 ) ;
else
return F_102 ( V_93 , V_96 , V_97 ) ;
case V_223 :
case V_226 :
* V_97 = V_113 ;
V_47 = F_51 ( V_185 -> V_191 , & V_96 -> V_170 ) ;
if ( ! V_47 )
goto V_220;
switch ( F_64 ( V_93 , V_47 , V_94 , V_96 , V_97 ) ) {
case V_111 :
break;
case V_108 :
goto V_220;
case V_117 :
goto V_82;
}
break;
default:
* V_97 = V_227 ;
goto V_220;
}
switch ( V_96 -> V_168 ) {
case V_226 :
if ( F_70 ( V_93 , V_47 -> V_49 , V_96 -> V_114 ) )
goto V_220;
F_129 ( V_185 -> V_191 , & V_47 -> V_14 ) ;
if ( V_89 -> V_87 + 4 > V_91 )
goto V_82;
F_63 ( V_89 , V_181 ) ;
goto V_228;
case V_223 :
* V_97 = V_116 ;
V_159 -> V_221 = V_89 -> V_88 + V_89 -> V_87 ;
if ( F_70 ( V_93 , V_47 -> V_49 , V_96 -> V_114 ) )
goto V_220;
V_93 -> V_229 = V_47 -> V_50 ;
F_130 ( V_47 -> V_50 . V_68 ) ;
* V_97 = V_167 ;
switch ( V_96 -> V_163 ) {
case V_230 :
break;
case V_231 :
F_63 ( V_89 , 0 ) ;
F_63 ( V_89 , 0 ) ;
if ( F_85 ( V_93 , & V_93 -> V_104 ,
V_96 -> V_114 , V_47 -> V_49 ) )
goto V_232;
V_93 -> V_233 = V_145 ;
break;
case V_234 :
F_63 ( V_89 , 0 ) ;
F_63 ( V_89 , 0 ) ;
if ( F_91 ( V_93 , & V_93 -> V_104 ,
V_96 -> V_114 , V_47 -> V_49 ) )
goto V_232;
V_93 -> V_233 = V_145 * 2 ;
break;
default:
goto V_220;
}
V_159 -> V_47 = V_47 ;
F_131 ( & V_47 -> V_14 ) ;
V_93 -> V_229 . V_235 = F_132 (
V_47 -> V_49 -> V_130 ,
V_236 ,
V_96 -> V_163 ) ;
V_183 = V_111 ;
goto V_40;
}
V_232:
V_183 = V_237 ;
goto V_40;
V_220:
F_69 ( V_93 , V_219 ) ;
V_183 = V_108 ;
goto V_40;
V_228:
V_183 = V_192 ;
goto V_40;
V_82:
V_183 = V_164 ;
V_40:
if ( V_47 )
F_25 ( & V_47 -> V_14 , V_185 -> V_191 ) ;
return V_183 ;
}
static T_5 *
F_133 ( struct V_100 * V_238 , struct V_158 * V_239 )
{
T_5 * V_90 ;
T_3 V_240 ;
V_90 = V_239 -> V_221 ;
V_239 -> V_221 = NULL ;
if ( * ( V_90 - 1 ) != V_241 )
return NULL ;
V_90 += 1 ;
V_240 = F_84 ( * V_90 ++ ) ;
V_90 += F_73 ( V_240 ) ;
memcpy ( V_90 , V_90 + 2 , 4 ) ;
if ( * V_90 != V_241 ) {
V_238 -> V_105 [ 0 ] . V_87 -= 2 * 4 ;
return NULL ;
}
V_90 ++ ;
return V_90 ;
}
static inline int
F_134 ( struct V_92 * V_93 )
{
struct V_158 * V_239 = (struct V_158 * ) V_93 -> V_160 ;
struct V_95 * V_96 = & V_239 -> V_161 ;
struct V_100 * V_238 = & V_93 -> V_118 ;
struct V_100 V_144 ;
struct V_1 V_124 ;
struct V_83 * V_89 ;
T_5 * V_90 ;
int V_242 , V_143 ;
int V_136 = - V_39 ;
V_90 = F_133 ( V_238 , V_239 ) ;
if ( V_90 == NULL )
goto V_40;
V_242 = ( T_4 * ) ( V_90 + 1 ) - ( T_4 * ) V_238 -> V_105 [ 0 ] . V_88 ;
V_143 = V_238 -> V_4 - V_242 ;
F_14 ( V_143 % 4 ) ;
* V_90 ++ = F_71 ( V_143 ) ;
* V_90 ++ = F_71 ( V_96 -> V_114 ) ;
if ( F_86 ( V_238 , & V_144 , V_242 , V_143 ) )
F_87 () ;
if ( V_238 -> V_147 [ 0 ] . V_88 == NULL ) {
if ( V_238 -> V_105 [ 0 ] . V_87 + V_145 > V_91 )
goto V_243;
V_238 -> V_147 [ 0 ] . V_88 = V_238 -> V_105 [ 0 ] . V_88
+ V_238 -> V_105 [ 0 ] . V_87 ;
V_238 -> V_147 [ 0 ] . V_87 = 0 ;
}
V_89 = & V_238 -> V_147 [ 0 ] ;
V_124 . V_5 = ( T_4 * ) V_89 -> V_88 + V_89 -> V_87 + 4 ;
if ( F_72 ( V_239 -> V_47 -> V_49 , & V_144 , & V_124 ) )
goto V_243;
F_63 ( V_89 , V_124 . V_4 ) ;
memset ( V_124 . V_5 + V_124 . V_4 , 0 ,
F_59 ( V_124 . V_4 ) - V_124 . V_4 ) ;
V_89 -> V_87 += F_73 ( V_124 . V_4 ) << 2 ;
V_238 -> V_4 += F_73 ( V_124 . V_4 ) << 2 ;
F_14 ( V_89 -> V_87 > V_91 ) ;
V_40:
V_136 = 0 ;
V_243:
return V_136 ;
}
static inline int
F_135 ( struct V_92 * V_93 )
{
struct V_158 * V_239 = (struct V_158 * ) V_93 -> V_160 ;
struct V_95 * V_96 = & V_239 -> V_161 ;
struct V_100 * V_238 = & V_93 -> V_118 ;
struct V_244 * * V_245 = NULL ;
T_5 * V_90 , * V_4 ;
int V_152 ;
int V_148 ;
V_90 = F_133 ( V_238 , V_239 ) ;
if ( V_90 == NULL )
return 0 ;
V_4 = V_90 ++ ;
V_152 = ( T_4 * ) V_90 - ( T_4 * ) V_238 -> V_105 [ 0 ] . V_88 ;
* V_90 ++ = F_71 ( V_96 -> V_114 ) ;
V_245 = V_238 -> V_175 ;
if ( V_238 -> V_147 [ 0 ] . V_88 ) {
F_14 ( V_238 -> V_147 [ 0 ] . V_88 >= V_238 -> V_105 [ 0 ] . V_88
+ V_91 ) ;
F_14 ( V_238 -> V_147 [ 0 ] . V_88 < V_238 -> V_105 [ 0 ] . V_88 ) ;
if ( V_238 -> V_147 [ 0 ] . V_87 + V_238 -> V_105 [ 0 ] . V_87
+ 2 * V_145 > V_91 )
return - V_22 ;
memmove ( V_238 -> V_147 [ 0 ] . V_88 + V_145 ,
V_238 -> V_147 [ 0 ] . V_88 ,
V_238 -> V_147 [ 0 ] . V_87 ) ;
V_238 -> V_147 [ 0 ] . V_88 += V_145 ;
}
if ( V_238 -> V_147 [ 0 ] . V_88 == NULL ) {
if ( V_238 -> V_105 [ 0 ] . V_87 + 2 * V_145 > V_91 )
return - V_22 ;
V_238 -> V_147 [ 0 ] . V_88 = V_238 -> V_105 [ 0 ] . V_88
+ V_238 -> V_105 [ 0 ] . V_87 + V_145 ;
V_238 -> V_147 [ 0 ] . V_87 = 0 ;
}
if ( F_136 ( V_239 -> V_47 -> V_49 , V_152 , V_238 , V_245 ) )
return - V_22 ;
* V_4 = F_71 ( V_238 -> V_4 - V_152 ) ;
V_148 = 3 - ( ( V_238 -> V_4 - V_152 - 1 ) & 3 ) ;
V_90 = ( T_5 * ) ( V_238 -> V_147 [ 0 ] . V_88 + V_238 -> V_147 [ 0 ] . V_87 ) ;
memset ( V_90 , 0 , V_148 ) ;
V_238 -> V_147 [ 0 ] . V_87 += V_148 ;
V_238 -> V_4 += V_148 ;
return 0 ;
}
static int
F_137 ( struct V_92 * V_93 )
{
struct V_158 * V_239 = (struct V_158 * ) V_93 -> V_160 ;
struct V_95 * V_96 = & V_239 -> V_161 ;
struct V_100 * V_238 = & V_93 -> V_118 ;
int V_136 = - V_39 ;
struct V_184 * V_185 = F_103 ( V_93 -> V_186 -> V_187 , V_188 ) ;
if ( V_96 -> V_168 != V_223 )
goto V_40;
if ( V_239 -> V_221 == NULL )
goto V_40;
V_238 -> V_4 = F_89 ( V_238 ) ;
switch ( V_96 -> V_163 ) {
case V_230 :
break;
case V_231 :
V_136 = F_134 ( V_93 ) ;
if ( V_136 )
goto V_243;
break;
case V_234 :
V_136 = F_135 ( V_93 ) ;
if ( V_136 )
goto V_243;
break;
}
V_40:
V_136 = 0 ;
V_243:
if ( V_93 -> V_246 )
F_81 ( V_93 -> V_246 ) ;
V_93 -> V_246 = NULL ;
if ( V_93 -> V_162 )
F_81 ( V_93 -> V_162 ) ;
V_93 -> V_162 = NULL ;
if ( V_93 -> V_229 . V_68 )
F_138 ( V_93 -> V_229 . V_68 ) ;
V_93 -> V_229 . V_68 = NULL ;
if ( V_239 -> V_47 )
F_25 ( & V_239 -> V_47 -> V_14 , V_185 -> V_191 ) ;
V_239 -> V_47 = NULL ;
return V_136 ;
}
static void
F_139 ( struct V_126 * V_131 )
{
struct V_132 * V_133 = F_5 ( V_131 , struct V_132 , V_14 ) ;
F_3 ( V_131 -> V_129 ) ;
F_3 ( V_133 ) ;
}
static int F_140 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
struct V_28 * V_29 ;
int V_125 ;
V_29 = F_141 ( & V_247 , V_202 ) ;
if ( F_142 ( V_29 ) )
return F_143 ( V_29 ) ;
V_125 = F_144 ( V_29 , V_202 ) ;
if ( V_125 ) {
F_145 ( V_29 , V_202 ) ;
return V_125 ;
}
V_185 -> V_189 = V_29 ;
return 0 ;
}
static void F_146 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
struct V_28 * V_29 = V_185 -> V_189 ;
V_185 -> V_189 = NULL ;
F_147 ( V_29 ) ;
F_148 ( V_29 , V_202 ) ;
F_145 ( V_29 , V_202 ) ;
}
static int F_149 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
struct V_28 * V_29 ;
int V_125 ;
V_29 = F_141 ( & V_248 , V_202 ) ;
if ( F_142 ( V_29 ) )
return F_143 ( V_29 ) ;
V_125 = F_144 ( V_29 , V_202 ) ;
if ( V_125 ) {
F_145 ( V_29 , V_202 ) ;
return V_125 ;
}
V_185 -> V_191 = V_29 ;
return 0 ;
}
static void F_150 ( struct V_202 * V_202 )
{
struct V_184 * V_185 = F_103 ( V_202 , V_188 ) ;
struct V_28 * V_29 = V_185 -> V_191 ;
V_185 -> V_191 = NULL ;
F_147 ( V_29 ) ;
F_148 ( V_29 , V_202 ) ;
F_145 ( V_29 , V_202 ) ;
}
int
F_151 ( struct V_202 * V_202 )
{
int V_56 ;
V_56 = F_149 ( V_202 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_140 ( V_202 ) ;
if ( V_56 )
goto V_249;
V_56 = F_121 ( V_202 ) ;
if ( V_56 )
goto V_250;
return 0 ;
V_250:
F_124 ( V_202 ) ;
V_249:
F_150 ( V_202 ) ;
return V_56 ;
}
void
F_152 ( struct V_202 * V_202 )
{
F_124 ( V_202 ) ;
F_146 ( V_202 ) ;
F_150 ( V_202 ) ;
}
int
F_153 ( void )
{
return F_154 ( V_109 , & V_139 ) ;
}
void
F_155 ( void )
{
F_156 ( V_109 ) ;
}
