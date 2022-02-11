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
if ( V_47 -> V_50 . V_51 )
F_32 ( V_47 -> V_50 . V_51 ) ;
F_3 ( V_47 -> V_52 ) ;
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
return F_7 ( V_47 -> V_48 . V_5 , V_47 -> V_48 . V_4 , V_53 ) ;
}
static int
F_35 ( struct V_17 * V_2 , struct V_17 * V_3 )
{
struct V_46 * V_25 = F_5 ( V_2 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_3 , struct V_46 , V_14 ) ;
return F_1 ( & V_25 -> V_48 , & V_18 -> V_48 ) ;
}
static void
F_36 ( struct V_17 * V_23 , struct V_17 * V_54 )
{
struct V_46 * V_25 = F_5 ( V_23 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_54 , struct V_46 , V_14 ) ;
V_25 -> V_48 . V_4 = V_18 -> V_48 . V_4 ;
V_18 -> V_48 . V_4 = 0 ;
V_25 -> V_48 . V_5 = V_18 -> V_48 . V_5 ;
V_18 -> V_48 . V_5 = NULL ;
V_25 -> V_49 = NULL ;
V_25 -> V_50 . V_51 = NULL ;
V_25 -> V_52 = NULL ;
}
static void
F_37 ( struct V_17 * V_23 , struct V_17 * V_54 )
{
struct V_46 * V_25 = F_5 ( V_23 , struct V_46 , V_14 ) ;
struct V_46 * V_18 = F_5 ( V_54 , struct V_46 , V_14 ) ;
V_25 -> V_49 = V_18 -> V_49 ;
V_18 -> V_49 = NULL ;
memset ( & V_25 -> V_55 , 0 , sizeof( V_25 -> V_55 ) ) ;
F_38 ( & V_25 -> V_55 . V_56 ) ;
V_25 -> V_50 = V_18 -> V_50 ;
V_18 -> V_50 . V_51 = NULL ;
V_25 -> V_52 = V_18 -> V_52 ;
V_18 -> V_52 = NULL ;
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
V_47 . V_50 . V_51 = F_44 ( V_64 ) ;
if ( V_47 . V_50 . V_51 == NULL )
goto V_40;
V_38 = - V_39 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
T_2 V_67 ;
if ( F_42 ( & V_32 , & V_67 ) )
goto V_40;
F_45 ( V_47 . V_50 . V_51 , V_65 ) = V_67 ;
}
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_60 = F_46 ( V_34 ) ;
V_38 = - V_68 ;
if ( ! V_60 )
goto V_40;
V_38 = - V_39 ;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 < 0 )
goto V_40;
V_38 = F_47 ( V_34 , V_4 , V_60 , & V_47 . V_49 , V_21 ) ;
if ( V_38 )
goto V_40;
V_4 = F_22 ( & V_32 , V_34 , V_33 ) ;
if ( V_4 > 0 ) {
V_47 . V_52 = F_48 ( V_34 , V_21 ) ;
if ( ! V_47 . V_52 )
goto V_40;
}
}
V_47 . V_14 . V_42 = V_37 ;
V_58 = F_49 ( V_29 , & V_47 , V_58 ) ;
V_38 = 0 ;
V_40:
F_50 ( V_60 ) ;
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
static struct V_46 * F_49 ( struct V_28 * V_29 , struct V_46 * V_25 , struct V_46 * V_45 )
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
F_51 ( struct V_28 * V_29 , struct V_1 * V_48 )
{
struct V_46 V_47 ;
struct V_46 * V_69 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( F_9 ( & V_47 . V_48 , V_48 -> V_5 , V_48 -> V_4 ) )
return NULL ;
V_69 = F_41 ( V_29 , & V_47 ) ;
F_30 ( & V_47 ) ;
if ( ! V_69 )
return NULL ;
if ( F_52 ( V_29 , & V_69 -> V_14 , NULL ) )
return NULL ;
return V_69 ;
}
static int
F_53 ( struct V_46 * V_47 , int V_70 )
{
struct V_71 * V_72 = & V_47 -> V_55 ;
F_54 ( & V_72 -> V_56 ) ;
if ( V_70 > V_72 -> V_73 ) {
if ( V_70 >= V_72 -> V_73 + V_74 ) {
memset ( V_72 -> V_75 , 0 , sizeof( V_72 -> V_75 ) ) ;
V_72 -> V_73 = V_70 ;
} else while ( V_72 -> V_73 < V_70 ) {
V_72 -> V_73 ++ ;
F_55 ( V_72 -> V_73 % V_74 , V_72 -> V_75 ) ;
}
F_56 ( V_70 % V_74 , V_72 -> V_75 ) ;
goto V_76;
} else if ( V_70 <= V_72 -> V_73 - V_74 ) {
goto V_77;
}
if ( F_57 ( V_70 % V_74 , V_72 -> V_75 ) )
goto V_77;
V_76:
F_58 ( & V_72 -> V_56 ) ;
return 1 ;
V_77:
F_58 ( & V_72 -> V_56 ) ;
return 0 ;
}
static inline T_3 F_59 ( T_3 V_65 )
{
return ( V_65 + 3 ) & ~ 3 ;
}
static inline int
F_60 ( struct V_78 * V_79 , struct V_1 * V_80 )
{
int V_81 ;
if ( V_79 -> V_82 < 4 )
return - 1 ;
V_80 -> V_4 = F_61 ( V_79 ) ;
V_81 = F_59 ( V_80 -> V_4 ) ;
if ( V_79 -> V_82 < V_81 )
return - 1 ;
V_80 -> V_5 = V_79 -> V_83 ;
V_79 -> V_83 += V_81 ;
V_79 -> V_82 -= V_81 ;
return 0 ;
}
static inline int
F_62 ( struct V_78 * V_84 , struct V_1 * V_80 )
{
T_4 * V_85 ;
if ( V_84 -> V_82 + 4 > V_86 )
return - 1 ;
F_63 ( V_84 , V_80 -> V_4 ) ;
V_85 = V_84 -> V_83 + V_84 -> V_82 ;
V_84 -> V_82 += F_59 ( V_80 -> V_4 ) ;
if ( V_84 -> V_82 > V_86 )
return - 1 ;
memcpy ( V_85 , V_80 -> V_5 , V_80 -> V_4 ) ;
memset ( V_85 + V_80 -> V_4 , 0 , F_59 ( V_80 -> V_4 ) - V_80 -> V_4 ) ;
return 0 ;
}
static int
F_64 ( struct V_87 * V_88 , struct V_46 * V_47 ,
T_5 * V_89 , struct V_90 * V_91 , T_5 * V_92 )
{
struct V_93 * V_94 = V_47 -> V_49 ;
struct V_95 V_96 ;
struct V_1 V_97 ;
T_3 V_98 = 0 ;
struct V_78 * V_79 = & V_88 -> V_99 . V_100 [ 0 ] ;
struct V_78 V_101 ;
V_101 . V_83 = V_89 ;
V_101 . V_82 = ( T_4 * ) V_79 -> V_83 - ( T_4 * ) V_89 ;
F_65 ( & V_101 , & V_96 ) ;
* V_92 = V_102 ;
if ( V_79 -> V_82 < 4 )
return V_103 ;
V_98 = F_61 ( V_79 ) ;
if ( V_98 != V_104 )
return V_103 ;
if ( F_60 ( V_79 , & V_97 ) )
return V_103 ;
if ( V_88 -> V_105 )
return V_106 ;
if ( F_66 ( V_94 , & V_96 , & V_97 ) != V_107 ) {
* V_92 = V_108 ;
return V_103 ;
}
if ( V_91 -> V_109 > V_110 ) {
F_67 ( L_1
L_2 , V_91 -> V_109 ) ;
* V_92 = V_111 ;
return V_103 ;
}
if ( ! F_53 ( V_47 , V_91 -> V_109 ) ) {
F_67 ( L_1
L_3 , V_91 -> V_109 ) ;
return V_112 ;
}
return V_106 ;
}
static int
F_68 ( struct V_87 * V_88 )
{
T_5 * V_85 ;
F_63 ( V_88 -> V_113 . V_100 , V_114 ) ;
V_85 = V_88 -> V_113 . V_100 -> V_83 + V_88 -> V_113 . V_100 -> V_82 ;
* V_85 ++ = 0 ;
if ( ! F_69 ( V_88 , V_85 ) )
return - 1 ;
return 0 ;
}
static int
F_70 ( struct V_87 * V_88 , struct V_93 * V_94 , T_3 V_115 )
{
T_5 V_116 ;
T_3 V_117 ;
struct V_95 V_118 ;
struct V_1 V_119 ;
T_5 * V_85 ;
struct V_78 V_101 ;
F_63 ( V_88 -> V_113 . V_100 , V_104 ) ;
V_116 = F_71 ( V_115 ) ;
V_101 . V_83 = & V_116 ;
V_101 . V_82 = sizeof( V_116 ) ;
F_65 ( & V_101 , & V_118 ) ;
V_85 = V_88 -> V_113 . V_100 -> V_83 + V_88 -> V_113 . V_100 -> V_82 ;
V_119 . V_5 = ( T_4 * ) ( V_85 + 1 ) ;
V_117 = F_72 ( V_94 , & V_118 , & V_119 ) ;
if ( V_117 != V_107 )
return - 1 ;
* V_85 ++ = F_71 ( V_119 . V_4 ) ;
memset ( ( T_4 * ) V_85 + V_119 . V_4 , 0 , F_59 ( V_119 . V_4 ) - V_119 . V_4 ) ;
V_85 += F_73 ( V_119 . V_4 ) ;
if ( ! F_69 ( V_88 , V_85 ) )
return - 1 ;
return 0 ;
}
static struct V_120 *
F_74 ( struct V_93 * V_121 , T_3 V_122 )
{
char * V_123 ;
V_123 = F_75 ( V_121 -> V_124 , V_122 ) ;
if ( ! V_123 )
return NULL ;
return F_76 ( V_123 ) ;
}
T_3 F_77 ( struct V_120 * V_125 )
{
struct V_126 * V_127 = F_5 ( V_125 , struct V_126 , V_14 ) ;
return V_127 -> V_128 ;
}
int
F_78 ( T_3 V_128 , char * V_123 )
{
struct V_126 * V_25 ;
struct V_120 * V_129 ;
int V_130 = - V_22 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_21 ) ;
if ( ! V_25 )
goto V_40;
F_79 ( & V_25 -> V_14 . V_13 ) ;
V_25 -> V_14 . V_123 = F_48 ( V_123 , V_21 ) ;
if ( ! V_25 -> V_14 . V_123 )
goto V_131;
V_25 -> V_14 . V_132 = & V_133 ;
V_25 -> V_128 = V_128 ;
V_130 = 0 ;
V_129 = F_80 ( V_123 , & V_25 -> V_14 ) ;
if ( V_129 != & V_25 -> V_14 ) {
F_81 ( V_129 ) ;
F_3 ( V_25 -> V_14 . V_123 ) ;
goto V_131;
}
return 0 ;
V_131:
F_3 ( V_25 ) ;
V_40:
return V_130 ;
}
static inline int
F_82 ( struct V_95 * V_34 , int V_134 , T_3 * V_135 )
{
T_5 V_136 ;
int V_38 ;
V_38 = F_83 ( V_34 , V_134 , & V_136 , sizeof( * V_135 ) ) ;
if ( V_38 )
return V_38 ;
* V_135 = F_84 ( V_136 ) ;
return 0 ;
}
static int
F_85 ( struct V_95 * V_34 , T_3 V_115 , struct V_93 * V_121 )
{
int V_130 = - V_39 ;
T_3 V_137 , V_117 ;
struct V_1 V_119 ;
struct V_95 V_138 ;
V_137 = F_61 ( & V_34 -> V_100 [ 0 ] ) ;
if ( V_137 & 3 )
return V_130 ;
if ( V_137 > V_34 -> V_4 )
return V_130 ;
if ( F_86 ( V_34 , & V_138 , 0 , V_137 ) )
F_87 () ;
if ( F_82 ( V_34 , V_137 , & V_119 . V_4 ) )
F_87 () ;
if ( V_119 . V_4 > V_139 )
return V_130 ;
V_119 . V_5 = F_16 ( V_119 . V_4 , V_21 ) ;
if ( ! V_119 . V_5 )
return V_130 ;
if ( F_83 ( V_34 , V_137 + 4 , V_119 . V_5 , V_119 . V_4 ) )
goto V_40;
V_117 = F_66 ( V_121 , & V_138 , & V_119 ) ;
if ( V_117 != V_107 )
goto V_40;
if ( F_61 ( & V_34 -> V_100 [ 0 ] ) != V_115 )
goto V_40;
V_130 = 0 ;
V_40:
F_3 ( V_119 . V_5 ) ;
return V_130 ;
}
static inline int
F_88 ( struct V_95 * V_34 )
{
return V_34 -> V_100 [ 0 ] . V_82 + V_34 -> V_140 + V_34 -> V_141 [ 0 ] . V_82 ;
}
static void
F_89 ( struct V_95 * V_34 , int V_142 )
{
if ( V_34 -> V_140 == 0 ) {
V_34 -> V_100 [ 0 ] . V_82 -= V_142 ;
}
}
static int
F_90 ( struct V_87 * V_88 , struct V_95 * V_34 , T_3 V_115 , struct V_93 * V_121 )
{
T_3 V_143 , V_117 ;
int V_142 , V_144 , V_145 , V_146 ;
V_88 -> V_147 = 0 ;
V_143 = F_61 ( & V_34 -> V_100 [ 0 ] ) ;
if ( V_88 -> V_105 ) {
goto V_148;
}
V_145 = F_88 ( V_34 ) ;
if ( V_143 > V_145 )
return - V_39 ;
V_142 = V_145 - V_143 ;
V_34 -> V_4 -= V_142 ;
F_89 ( V_34 , V_142 ) ;
V_144 = V_34 -> V_4 ;
V_34 -> V_4 = V_143 ;
V_117 = F_91 ( V_121 , 0 , V_34 ) ;
V_142 = V_143 - V_34 -> V_4 ;
V_34 -> V_4 = V_144 ;
V_34 -> V_4 -= V_142 ;
V_146 = V_34 -> V_100 [ 0 ] . V_82 % 4 ;
if ( V_146 ) {
V_34 -> V_149 = V_150 ;
F_92 ( V_34 , V_146 ) ;
F_89 ( V_34 , V_142 ) ;
}
if ( V_117 != V_107 )
return - V_39 ;
V_148:
if ( F_61 ( & V_34 -> V_100 [ 0 ] ) != V_115 )
return - V_39 ;
return 0 ;
}
char * F_93 ( struct V_87 * V_88 )
{
struct V_151 * V_127 = (struct V_151 * ) V_88 -> V_152 ;
if ( V_127 && V_127 -> V_47 )
return V_127 -> V_47 -> V_52 ;
return NULL ;
}
static int
F_94 ( struct V_87 * V_88 )
{
struct V_151 * V_153 = V_88 -> V_152 ;
struct V_46 * V_47 = V_153 -> V_47 ;
struct V_90 * V_91 = & V_153 -> V_154 ;
int V_130 ;
V_88 -> V_155 = F_74 ( V_47 -> V_49 , V_91 -> V_156 ) ;
if ( V_88 -> V_155 == NULL )
return V_103 ;
V_130 = F_95 ( V_88 ) ;
if ( V_130 == V_112 || V_130 == V_157 )
return V_130 ;
return V_106 ;
}
static inline int
F_96 ( struct V_28 * V_29 , struct V_87 * V_88 , struct V_6 * V_36 )
{
struct V_46 * V_47 ;
int V_158 ;
if ( V_36 -> V_26 != V_107 )
return F_68 ( V_88 ) ;
V_47 = F_51 ( V_29 , & V_36 -> V_10 ) ;
if ( V_47 == NULL ) {
V_36 -> V_26 = V_159 ;
return F_68 ( V_88 ) ;
}
V_158 = F_70 ( V_88 , V_47 -> V_49 , V_74 ) ;
F_27 ( & V_47 -> V_14 , V_29 ) ;
return V_158 ;
}
static int F_97 ( struct V_87 * V_88 ,
struct V_90 * V_91 , T_5 * V_92 )
{
struct V_78 * V_79 = & V_88 -> V_99 . V_100 [ 0 ] ;
struct V_78 * V_84 = & V_88 -> V_113 . V_100 [ 0 ] ;
struct V_1 V_160 ;
struct V_6 * V_36 , V_161 ;
int V_162 ;
struct V_163 * V_164 = F_98 ( V_88 -> V_165 -> V_166 , V_167 ) ;
* V_92 = V_102 ;
if ( V_79 -> V_82 < 2 * 4 )
return V_103 ;
if ( F_61 ( V_79 ) != V_114 )
return V_103 ;
if ( F_61 ( V_79 ) != 0 )
return V_103 ;
* V_92 = V_168 ;
if ( V_91 -> V_169 == V_170 && V_91 -> V_171 . V_4 != 0 )
return V_103 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
if ( F_11 ( & V_161 . V_8 , & V_91 -> V_171 ) )
return V_157 ;
* V_92 = V_102 ;
if ( F_60 ( V_79 , & V_160 ) ) {
F_3 ( V_161 . V_8 . V_5 ) ;
return V_103 ;
}
if ( F_11 ( & V_161 . V_9 , & V_160 ) ) {
F_3 ( V_161 . V_8 . V_5 ) ;
return V_157 ;
}
V_36 = F_23 ( V_164 -> V_172 , & V_161 ) ;
F_2 ( & V_161 ) ;
if ( ! V_36 )
return V_157 ;
if ( F_52 ( V_164 -> V_172 , & V_36 -> V_14 , & V_88 -> V_173 ) < 0 )
return V_157 ;
V_162 = V_157 ;
if ( F_96 ( V_164 -> V_174 , V_88 , V_36 ) )
goto V_40;
if ( V_84 -> V_82 + 4 > V_86 )
goto V_40;
F_63 ( V_84 , V_175 ) ;
if ( F_62 ( V_84 , & V_36 -> V_10 ) )
goto V_40;
if ( V_84 -> V_82 + 3 * 4 > V_86 )
goto V_40;
F_63 ( V_84 , V_36 -> V_26 ) ;
F_63 ( V_84 , V_36 -> V_27 ) ;
F_63 ( V_84 , V_74 ) ;
if ( F_62 ( V_84 , & V_36 -> V_11 ) )
goto V_40;
V_162 = V_176 ;
V_40:
F_27 ( & V_36 -> V_14 , V_164 -> V_172 ) ;
return V_162 ;
}
static int
F_99 ( struct V_87 * V_88 , T_5 * V_92 )
{
struct V_78 * V_79 = & V_88 -> V_99 . V_100 [ 0 ] ;
struct V_78 * V_84 = & V_88 -> V_113 . V_100 [ 0 ] ;
T_3 V_177 ;
struct V_151 * V_153 = V_88 -> V_152 ;
struct V_90 * V_91 ;
struct V_46 * V_47 = NULL ;
T_5 * V_89 ;
T_5 * V_178 = V_84 -> V_83 + V_84 -> V_82 ;
int V_162 ;
struct V_163 * V_164 = F_98 ( V_88 -> V_165 -> V_166 , V_167 ) ;
F_67 ( L_4 ,
V_79 -> V_82 ) ;
* V_92 = V_168 ;
if ( ! V_153 )
V_153 = F_16 ( sizeof( * V_153 ) , V_21 ) ;
if ( ! V_153 )
goto V_179;
V_88 -> V_152 = V_153 ;
V_153 -> V_180 = NULL ;
V_153 -> V_47 = NULL ;
V_91 = & V_153 -> V_154 ;
V_89 = V_79 -> V_83 ;
V_89 -= 7 ;
if ( V_79 -> V_82 < 5 * 4 )
goto V_179;
V_177 = F_61 ( V_79 ) ;
if ( F_61 ( V_79 ) != V_181 )
goto V_179;
V_91 -> V_169 = F_61 ( V_79 ) ;
V_91 -> V_109 = F_61 ( V_79 ) ;
V_91 -> V_156 = F_61 ( V_79 ) ;
if ( F_60 ( V_79 , & V_91 -> V_171 ) )
goto V_179;
if ( V_177 != F_59 ( V_91 -> V_171 . V_4 ) + 5 * 4 )
goto V_179;
if ( ( V_91 -> V_169 != V_182 ) && ( V_88 -> V_183 != 0 ) )
goto V_179;
* V_92 = V_102 ;
switch ( V_91 -> V_169 ) {
case V_170 :
case V_184 :
return F_97 ( V_88 , V_91 , V_92 ) ;
case V_182 :
case V_185 :
* V_92 = V_108 ;
V_47 = F_51 ( V_164 -> V_174 , & V_91 -> V_171 ) ;
if ( ! V_47 )
goto V_179;
switch ( F_64 ( V_88 , V_47 , V_89 , V_91 , V_92 ) ) {
case V_106 :
break;
case V_103 :
goto V_179;
case V_112 :
goto V_77;
}
break;
default:
* V_92 = V_186 ;
goto V_179;
}
switch ( V_91 -> V_169 ) {
case V_185 :
if ( F_70 ( V_88 , V_47 -> V_49 , V_91 -> V_109 ) )
goto V_179;
V_47 -> V_14 . V_42 = F_100 () ;
F_43 ( V_63 , & V_47 -> V_14 . V_41 ) ;
if ( V_84 -> V_82 + 4 > V_86 )
goto V_77;
F_63 ( V_84 , V_175 ) ;
goto V_187;
case V_182 :
* V_92 = V_111 ;
V_153 -> V_180 = V_84 -> V_83 + V_84 -> V_82 ;
if ( F_70 ( V_88 , V_47 -> V_49 , V_91 -> V_109 ) )
goto V_179;
V_88 -> V_188 = V_47 -> V_50 ;
F_101 ( V_47 -> V_50 . V_51 ) ;
* V_92 = V_168 ;
switch ( V_91 -> V_156 ) {
case V_189 :
break;
case V_190 :
F_63 ( V_84 , 0 ) ;
F_63 ( V_84 , 0 ) ;
if ( F_85 ( & V_88 -> V_99 ,
V_91 -> V_109 , V_47 -> V_49 ) )
goto V_191;
break;
case V_192 :
F_63 ( V_84 , 0 ) ;
F_63 ( V_84 , 0 ) ;
if ( F_90 ( V_88 , & V_88 -> V_99 ,
V_91 -> V_109 , V_47 -> V_49 ) )
goto V_191;
break;
default:
goto V_179;
}
V_153 -> V_47 = V_47 ;
F_102 ( & V_47 -> V_14 ) ;
V_88 -> V_193 = F_103 (
V_47 -> V_49 -> V_124 , V_91 -> V_156 ) ;
V_162 = V_106 ;
goto V_40;
}
V_191:
V_162 = V_194 ;
goto V_40;
V_179:
F_69 ( V_88 , V_178 ) ;
V_162 = V_103 ;
goto V_40;
V_187:
V_162 = V_176 ;
goto V_40;
V_77:
V_162 = V_112 ;
V_40:
if ( V_47 )
F_27 ( & V_47 -> V_14 , V_164 -> V_174 ) ;
return V_162 ;
}
static T_5 *
F_104 ( struct V_95 * V_195 , struct V_151 * V_196 )
{
T_5 * V_85 ;
T_3 V_197 ;
V_85 = V_196 -> V_180 ;
V_196 -> V_180 = NULL ;
if ( * ( V_85 - 1 ) != V_198 )
return NULL ;
V_85 += 1 ;
V_197 = F_84 ( * V_85 ++ ) ;
V_85 += F_73 ( V_197 ) ;
memcpy ( V_85 , V_85 + 2 , 4 ) ;
if ( * V_85 != V_198 ) {
V_195 -> V_100 [ 0 ] . V_82 -= 2 * 4 ;
return NULL ;
}
V_85 ++ ;
return V_85 ;
}
static inline int
F_105 ( struct V_87 * V_88 )
{
struct V_151 * V_196 = (struct V_151 * ) V_88 -> V_152 ;
struct V_90 * V_91 = & V_196 -> V_154 ;
struct V_95 * V_195 = & V_88 -> V_113 ;
struct V_95 V_138 ;
struct V_1 V_119 ;
struct V_78 * V_84 ;
T_5 * V_85 ;
int V_199 , V_137 ;
int V_130 = - V_39 ;
V_85 = F_104 ( V_195 , V_196 ) ;
if ( V_85 == NULL )
goto V_40;
V_199 = ( T_4 * ) ( V_85 + 1 ) - ( T_4 * ) V_195 -> V_100 [ 0 ] . V_83 ;
V_137 = V_195 -> V_4 - V_199 ;
F_14 ( V_137 % 4 ) ;
* V_85 ++ = F_71 ( V_137 ) ;
* V_85 ++ = F_71 ( V_91 -> V_109 ) ;
if ( F_86 ( V_195 , & V_138 , V_199 ,
V_137 ) )
F_87 () ;
if ( V_195 -> V_141 [ 0 ] . V_83 == NULL ) {
if ( V_195 -> V_100 [ 0 ] . V_82 + V_139 > V_86 )
goto V_200;
V_195 -> V_141 [ 0 ] . V_83 = V_195 -> V_100 [ 0 ] . V_83
+ V_195 -> V_100 [ 0 ] . V_82 ;
V_195 -> V_141 [ 0 ] . V_82 = 0 ;
V_84 = & V_195 -> V_141 [ 0 ] ;
} else {
V_84 = & V_195 -> V_141 [ 0 ] ;
}
V_119 . V_5 = ( T_4 * ) V_84 -> V_83 + V_84 -> V_82 + 4 ;
if ( F_72 ( V_196 -> V_47 -> V_49 , & V_138 , & V_119 ) )
goto V_200;
F_63 ( V_84 , V_119 . V_4 ) ;
memset ( V_119 . V_5 + V_119 . V_4 , 0 ,
F_59 ( V_119 . V_4 ) - V_119 . V_4 ) ;
V_84 -> V_82 += F_73 ( V_119 . V_4 ) << 2 ;
V_195 -> V_4 += F_73 ( V_119 . V_4 ) << 2 ;
F_14 ( V_84 -> V_82 > V_86 ) ;
V_40:
V_130 = 0 ;
V_200:
return V_130 ;
}
static inline int
F_106 ( struct V_87 * V_88 )
{
struct V_151 * V_196 = (struct V_151 * ) V_88 -> V_152 ;
struct V_90 * V_91 = & V_196 -> V_154 ;
struct V_95 * V_195 = & V_88 -> V_113 ;
struct V_201 * * V_202 = NULL ;
T_5 * V_85 , * V_4 ;
int V_146 ;
int V_142 ;
V_85 = F_104 ( V_195 , V_196 ) ;
if ( V_85 == NULL )
return 0 ;
V_4 = V_85 ++ ;
V_146 = ( T_4 * ) V_85 - ( T_4 * ) V_195 -> V_100 [ 0 ] . V_83 ;
* V_85 ++ = F_71 ( V_91 -> V_109 ) ;
V_202 = V_195 -> V_203 ;
if ( V_195 -> V_141 [ 0 ] . V_83 ) {
F_14 ( V_195 -> V_141 [ 0 ] . V_83 >= V_195 -> V_100 [ 0 ] . V_83
+ V_86 ) ;
F_14 ( V_195 -> V_141 [ 0 ] . V_83 < V_195 -> V_100 [ 0 ] . V_83 ) ;
if ( V_195 -> V_141 [ 0 ] . V_82 + V_195 -> V_100 [ 0 ] . V_82
+ 2 * V_139 > V_86 )
return - V_22 ;
memmove ( V_195 -> V_141 [ 0 ] . V_83 + V_139 ,
V_195 -> V_141 [ 0 ] . V_83 ,
V_195 -> V_141 [ 0 ] . V_82 ) ;
V_195 -> V_141 [ 0 ] . V_83 += V_139 ;
}
if ( V_195 -> V_141 [ 0 ] . V_83 == NULL ) {
if ( V_195 -> V_100 [ 0 ] . V_82 + 2 * V_139 > V_86 )
return - V_22 ;
V_195 -> V_141 [ 0 ] . V_83 = V_195 -> V_100 [ 0 ] . V_83
+ V_195 -> V_100 [ 0 ] . V_82 + V_139 ;
V_195 -> V_141 [ 0 ] . V_82 = 0 ;
}
if ( F_107 ( V_196 -> V_47 -> V_49 , V_146 , V_195 , V_202 ) )
return - V_22 ;
* V_4 = F_71 ( V_195 -> V_4 - V_146 ) ;
V_142 = 3 - ( ( V_195 -> V_4 - V_146 - 1 ) & 3 ) ;
V_85 = ( T_5 * ) ( V_195 -> V_141 [ 0 ] . V_83 + V_195 -> V_141 [ 0 ] . V_82 ) ;
memset ( V_85 , 0 , V_142 ) ;
V_195 -> V_141 [ 0 ] . V_82 += V_142 ;
V_195 -> V_4 += V_142 ;
return 0 ;
}
static int
F_108 ( struct V_87 * V_88 )
{
struct V_151 * V_196 = (struct V_151 * ) V_88 -> V_152 ;
struct V_90 * V_91 = & V_196 -> V_154 ;
struct V_95 * V_195 = & V_88 -> V_113 ;
int V_130 = - V_39 ;
struct V_163 * V_164 = F_98 ( V_88 -> V_165 -> V_166 , V_167 ) ;
if ( V_91 -> V_169 != V_182 )
goto V_40;
if ( V_196 -> V_180 == NULL )
goto V_40;
V_195 -> V_4 = F_88 ( V_195 ) ;
switch ( V_91 -> V_156 ) {
case V_189 :
break;
case V_190 :
V_130 = F_105 ( V_88 ) ;
if ( V_130 )
goto V_200;
break;
case V_192 :
V_130 = F_106 ( V_88 ) ;
if ( V_130 )
goto V_200;
break;
}
V_40:
V_130 = 0 ;
V_200:
if ( V_88 -> V_204 )
F_81 ( V_88 -> V_204 ) ;
V_88 -> V_204 = NULL ;
if ( V_88 -> V_155 )
F_81 ( V_88 -> V_155 ) ;
V_88 -> V_155 = NULL ;
if ( V_88 -> V_188 . V_51 )
F_32 ( V_88 -> V_188 . V_51 ) ;
V_88 -> V_188 . V_51 = NULL ;
if ( V_196 -> V_47 )
F_27 ( & V_196 -> V_47 -> V_14 , V_164 -> V_174 ) ;
V_196 -> V_47 = NULL ;
return V_130 ;
}
static void
F_109 ( struct V_120 * V_125 )
{
struct V_126 * V_127 = F_5 ( V_125 , struct V_126 , V_14 ) ;
F_3 ( V_125 -> V_123 ) ;
F_3 ( V_127 ) ;
}
static int F_110 ( struct V_205 * V_205 )
{
struct V_163 * V_164 = F_98 ( V_205 , V_167 ) ;
struct V_28 * V_29 ;
int V_206 ;
V_29 = F_111 ( & V_207 , V_205 ) ;
if ( F_112 ( V_29 ) )
return F_113 ( V_29 ) ;
V_206 = F_114 ( V_29 , V_205 ) ;
if ( V_206 ) {
F_115 ( V_29 , V_205 ) ;
return V_206 ;
}
V_164 -> V_172 = V_29 ;
return 0 ;
}
static void F_116 ( struct V_205 * V_205 )
{
struct V_163 * V_164 = F_98 ( V_205 , V_167 ) ;
struct V_28 * V_29 = V_164 -> V_172 ;
V_164 -> V_172 = NULL ;
F_117 ( V_29 ) ;
F_118 ( V_29 , V_205 ) ;
F_115 ( V_29 , V_205 ) ;
}
static int F_119 ( struct V_205 * V_205 )
{
struct V_163 * V_164 = F_98 ( V_205 , V_167 ) ;
struct V_28 * V_29 ;
int V_206 ;
V_29 = F_111 ( & V_208 , V_205 ) ;
if ( F_112 ( V_29 ) )
return F_113 ( V_29 ) ;
V_206 = F_114 ( V_29 , V_205 ) ;
if ( V_206 ) {
F_115 ( V_29 , V_205 ) ;
return V_206 ;
}
V_164 -> V_174 = V_29 ;
return 0 ;
}
static void F_120 ( struct V_205 * V_205 )
{
struct V_163 * V_164 = F_98 ( V_205 , V_167 ) ;
struct V_28 * V_29 = V_164 -> V_174 ;
V_164 -> V_174 = NULL ;
F_117 ( V_29 ) ;
F_118 ( V_29 , V_205 ) ;
F_115 ( V_29 , V_205 ) ;
}
int
F_121 ( struct V_205 * V_205 )
{
int V_57 ;
V_57 = F_119 ( V_205 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_110 ( V_205 ) ;
if ( V_57 )
goto V_209;
return 0 ;
V_209:
F_120 ( V_205 ) ;
return V_57 ;
}
void
F_122 ( struct V_205 * V_205 )
{
F_116 ( V_205 ) ;
F_120 ( V_205 ) ;
}
int
F_123 ( void )
{
return F_124 ( V_104 , & V_133 ) ;
}
void
F_125 ( void )
{
F_126 ( V_104 ) ;
}
