static inline struct V_1 * F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) , V_2 ) ;
}
static inline void F_3 ( struct V_1 * V_3 )
{
F_4 ( V_3 ) ;
}
static inline void
F_5 ( struct V_4 * V_5 , struct V_1 * V_3 ,
struct V_6 * V_7 , T_1 V_8 )
{
struct V_1 * V_9 ;
V_9 = F_6 ( V_5 -> V_3 ,
F_7 ( & V_5 -> V_10 ) ) ;
if ( V_3 ) {
V_3 -> V_11 = V_7 ;
V_3 -> V_8 = V_8 ;
}
F_8 ( V_5 -> V_3 , V_3 ) ;
if ( V_9 )
F_9 ( & V_9 -> V_12 , V_13 ) ;
}
static inline struct V_1 *
F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_3 = F_11 ( V_5 -> V_3 ) ;
struct V_6 * V_7 ;
if ( ! V_3 )
return NULL ;
V_7 = V_3 -> V_11 ;
if ( V_7 -> V_14 &&
V_7 -> V_15 -> V_16 ( V_7 , V_3 -> V_8 ) == NULL )
return NULL ;
return V_3 ;
}
static inline bool
F_12 ( const struct V_17 * V_18 , T_1 V_19 )
{
if ( F_13 ( V_18 ) -> V_20 ) {
if ( F_13 ( V_18 ) -> V_20 > V_19 )
return true ;
}
else if ( V_18 -> V_21 > V_19 && ! F_14 ( V_18 ) ) {
return true ;
}
return false ;
}
static struct V_22 * F_15 ( struct V_23 * V_23 , T_2 V_24 ,
int V_25 , T_2 * V_26 )
{
struct V_27 V_28 ;
struct V_22 * V_29 ;
int V_30 = 0 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_24 = V_24 ;
V_28 . V_31 = ( V_25 & V_32 ) ?
V_33 : 0 ;
V_34:
V_29 = F_16 ( V_23 , & V_28 ) ;
if ( F_17 ( V_29 ) ) {
if ( F_18 ( V_29 ) == - V_35 && * V_26 &&
V_25 & V_36 && ! V_30 ) {
* V_26 = 0 ;
F_19 ( & V_28 , 0 , 0 , V_24 , 0 ) ;
goto V_34;
}
F_20 ( L_1 , & V_24 ) ;
return NULL ;
} else if ( ! * V_26 && V_25 & V_36 && V_28 . V_26 ) {
F_21 ( V_29 ) ;
* V_26 = V_28 . V_26 ;
F_19 ( & V_28 , 0 , 0 , V_24 , V_28 . V_26 ) ;
V_30 ++ ;
goto V_34;
}
* V_26 = V_28 . V_26 ;
return V_29 ;
}
static inline int F_22 ( struct V_37 * V_29 )
{
return V_29 -> V_7 . V_38 && V_29 -> V_7 . V_38 -> V_39 & V_40 ;
}
static inline bool F_23 ( int V_41 , struct V_17 * V_18 ,
int V_25 ,
bool V_42 )
{
bool V_43 = ! ! ( V_25 & V_44 ) ;
bool V_45 = ! ! ( V_25 & V_44 ) ;
bool V_46 = ! ! ( V_25 & V_47 ) ;
bool V_48 ;
bool V_49 ;
#ifdef F_24
if ( V_41 == V_50 ) {
int V_51 = F_25 ( & F_26 ( V_18 ) -> V_26 ) ;
V_48 =
( ! V_18 -> V_38 || V_18 -> V_38 -> V_39 & V_40 ) &&
( V_51 & V_52 ) ;
V_49 = F_22 (
(struct V_37 * ) F_27 ( V_18 ) ) ;
} else
#endif
{
V_48 = F_28 ( F_29 ( V_18 ) -> V_26 ) ;
V_49 = F_30 ( V_18 ) -> V_53 & V_54 ;
}
if ( F_31 ( V_42 ) ) {
if ( ! V_43 )
return true ;
if ( ! V_46 && ! V_49 )
return true ;
} else {
if ( ! V_45 )
return true ;
if ( V_48 )
return true ;
}
return false ;
}
static inline void F_32 ( int V_41 , struct V_17 * V_18 , int V_19 )
{
struct V_55 * V_56 = V_18 -> V_56 ;
struct V_22 * V_57 = F_30 ( V_18 ) ;
if ( ! V_18 -> V_38 && V_56 && F_33 ( V_56 ) )
V_57 -> V_7 . V_15 -> V_58 ( & V_57 -> V_7 , V_56 , NULL , V_19 ) ;
}
static inline bool F_34 ( struct V_59 * V_60 , int V_41 ,
int V_25 ,
struct V_61 * V_62 ,
struct V_17 * V_18 , int V_19 )
{
#ifdef F_24
if ( V_41 == V_50 ) {
struct V_23 * V_23 = V_60 -> V_23 ;
if ( F_31 ( F_12 ( V_18 , V_19 ) ) ) {
if ( ! V_18 -> V_38 )
V_18 -> V_38 = V_23 -> V_63 ;
if ( ! V_62 -> V_64 && ! F_35 ( V_62 ) )
F_36 ( V_18 , V_65 , 0 , V_19 ) ;
F_37 ( 1 , L_2 ,
& F_26 ( V_18 ) -> V_26 ) ;
return false ;
}
} else
#endif
{
if ( ( V_25 & V_66 ) && ! F_38 ( V_60 ) )
return true ;
if ( F_31 ( F_29 ( V_18 ) -> V_67 & F_39 ( V_68 ) &&
V_18 -> V_21 > V_19 && ! F_14 ( V_18 ) &&
! F_35 ( V_62 ) ) ) {
F_40 ( V_18 , V_69 , V_70 ,
F_41 ( V_19 ) ) ;
F_37 ( 1 , L_3 ,
& F_29 ( V_18 ) -> V_26 ) ;
return false ;
}
}
return true ;
}
static inline bool F_42 ( struct V_59 * V_60 ,
int V_41 ,
struct V_17 * V_18 )
{
struct V_23 * V_23 = V_60 -> V_23 ;
#ifdef F_24
if ( V_41 == V_50 ) {
struct V_6 * V_7 = F_27 ( V_18 ) ;
if ( F_26 ( V_18 ) -> V_71 <= 1 ) {
V_18 -> V_38 = V_7 -> V_38 ;
F_36 ( V_18 , V_72 ,
V_73 , 0 ) ;
F_43 ( V_23 , F_44 ( V_7 ) ,
V_74 ) ;
return false ;
}
if ( ! F_45 ( V_18 , sizeof( struct V_75 ) ) )
return false ;
F_26 ( V_18 ) -> V_71 -- ;
} else
#endif
{
if ( F_29 ( V_18 ) -> V_76 <= 1 ) {
F_46 ( V_23 , V_74 ) ;
F_40 ( V_18 , V_77 , V_78 , 0 ) ;
return false ;
}
if ( ! F_45 ( V_18 , sizeof( struct V_79 ) ) )
return false ;
F_47 ( F_29 ( V_18 ) ) ;
}
return true ;
}
static int
F_48 ( struct V_59 * V_60 , int V_41 , struct V_17 * V_18 ,
struct V_4 * V_5 ,
T_2 V_24 , int V_25 , T_2 * V_80 ,
struct V_61 * V_62 )
{
struct V_23 * V_23 = V_60 -> V_23 ;
struct V_1 * V_3 ;
struct V_22 * V_29 ;
int V_19 ;
int V_81 , V_82 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_49 ( V_3 ) )
V_29 = (struct V_22 * ) V_3 -> V_11 ;
else {
V_3 = F_1 () ;
F_50 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_51 ( & V_5 -> V_10 ) ;
goto V_83;
}
V_29 = F_15 ( V_23 , V_5 -> V_84 . V_85 , V_25 ,
& V_3 -> V_86 . V_85 ) ;
if ( ! V_29 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_51 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_83;
}
F_5 ( V_5 , V_3 , & V_29 -> V_7 , 0 ) ;
F_51 ( & V_5 -> V_10 ) ;
F_37 ( 10 , L_4 ,
& V_5 -> V_84 . V_85 , & V_3 -> V_86 . V_85 ,
F_52 ( & V_29 -> V_7 . V_87 ) ) ;
}
if ( V_80 )
* V_80 = V_3 -> V_86 . V_85 ;
} else {
T_2 V_26 = F_41 ( V_88 ) ;
V_82 = 0 ;
V_25 &= ~ V_36 ;
V_29 = F_15 ( V_23 , V_24 , V_25 , & V_26 ) ;
if ( ! V_29 )
goto V_83;
if ( V_80 )
* V_80 = V_26 ;
}
V_81 = ( V_29 -> V_53 & V_54 ) ? 1 : 0 ;
if ( F_31 ( F_23 ( V_41 , V_18 , V_25 ,
V_81 ) ) ) {
F_20 ( L_5
L_6 , & V_24 ) ;
goto V_89;
}
if ( F_31 ( V_81 ) ) {
if ( ! V_82 )
F_21 ( V_29 ) ;
return V_81 ;
}
if ( ! F_42 ( V_60 , V_41 , V_18 ) )
goto V_89;
if ( F_49 ( ! ( V_25 & V_66 ) ) ) {
V_19 = F_53 ( & V_29 -> V_7 ) ;
} else {
V_19 = F_53 ( & V_29 -> V_7 ) - sizeof( struct V_79 ) ;
if ( V_19 < 68 ) {
F_20 ( L_7 , V_90 ) ;
goto V_89;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_34 ( V_60 , V_41 , V_25 , V_62 , V_18 , V_19 ) )
goto V_89;
F_54 ( V_18 ) ;
if ( V_82 ) {
if ( ! V_81 )
F_55 ( V_18 , & V_29 -> V_7 ) ;
else
F_56 ( V_18 , F_57 ( & V_29 -> V_7 ) ) ;
} else
F_56 ( V_18 , & V_29 -> V_7 ) ;
return V_81 ;
V_89:
if ( ! V_82 )
F_21 ( V_29 ) ;
return - 1 ;
V_83:
F_58 ( V_18 ) ;
return - 1 ;
}
static struct V_6 *
F_59 ( struct V_23 * V_23 , struct V_91 * V_24 ,
struct V_91 * V_80 , int V_92 , int V_25 )
{
struct V_6 * V_7 ;
struct V_93 V_94 = {
. V_24 = * V_24 ,
} ;
if ( V_25 & V_32 )
V_94 . V_95 = V_33 ;
V_7 = F_60 ( V_23 , NULL , & V_94 ) ;
if ( V_7 -> error )
goto V_96;
if ( ! V_80 )
return V_7 ;
if ( F_61 ( & V_94 . V_26 ) &&
F_62 ( V_23 , F_44 ( V_7 ) -> V_38 ,
& V_94 . V_24 , 0 , & V_94 . V_26 ) < 0 )
goto V_96;
if ( V_92 ) {
V_7 = F_63 ( V_23 , V_7 , F_64 ( & V_94 ) , NULL , 0 ) ;
if ( F_17 ( V_7 ) ) {
V_7 = NULL ;
goto V_96;
}
}
* V_80 = V_94 . V_26 ;
return V_7 ;
V_96:
F_65 ( V_7 ) ;
F_20 ( L_8 , V_24 ) ;
return NULL ;
}
static int
F_66 ( struct V_59 * V_60 , int V_41 , struct V_17 * V_18 ,
struct V_4 * V_5 ,
struct V_91 * V_24 , struct V_91 * V_80 ,
struct V_61 * V_62 , int V_92 , int V_25 )
{
struct V_23 * V_23 = V_60 -> V_23 ;
struct V_1 * V_3 ;
struct V_37 * V_29 ;
struct V_6 * V_7 ;
int V_19 ;
int V_81 , V_82 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_49 ( V_3 ) )
V_29 = (struct V_37 * ) V_3 -> V_11 ;
else {
T_1 V_97 ;
V_3 = F_1 () ;
F_50 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_51 ( & V_5 -> V_10 ) ;
goto V_83;
}
V_7 = F_59 ( V_23 , & V_5 -> V_84 . V_98 ,
& V_3 -> V_86 . V_98 ,
V_92 , V_25 ) ;
if ( ! V_7 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_51 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_83;
}
V_29 = (struct V_37 * ) V_7 ;
V_97 = F_67 ( V_29 ) ;
F_5 ( V_5 , V_3 , & V_29 -> V_7 , V_97 ) ;
F_51 ( & V_5 -> V_10 ) ;
F_37 ( 10 , L_9 ,
& V_5 -> V_84 . V_98 , & V_3 -> V_86 . V_98 ,
F_52 ( & V_29 -> V_7 . V_87 ) ) ;
}
if ( V_80 )
* V_80 = V_3 -> V_86 . V_98 ;
} else {
V_82 = 0 ;
V_7 = F_59 ( V_23 , V_24 , V_80 , V_92 ,
V_25 ) ;
if ( ! V_7 )
goto V_83;
V_29 = (struct V_37 * ) V_7 ;
}
V_81 = F_22 ( V_29 ) ;
if ( F_31 ( F_23 ( V_41 , V_18 , V_25 ,
V_81 ) ) ) {
F_20 ( L_5
L_10 , V_24 ) ;
goto V_89;
}
if ( F_31 ( V_81 ) ) {
if ( ! V_82 )
F_65 ( & V_29 -> V_7 ) ;
return V_81 ;
}
if ( ! F_42 ( V_60 , V_41 , V_18 ) )
goto V_89;
if ( F_49 ( ! ( V_25 & V_66 ) ) )
V_19 = F_53 ( & V_29 -> V_7 ) ;
else {
V_19 = F_53 ( & V_29 -> V_7 ) - sizeof( struct V_75 ) ;
if ( V_19 < V_99 ) {
F_20 ( L_11 , V_90 ,
V_99 ) ;
goto V_89;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_34 ( V_60 , V_41 , V_25 , V_62 , V_18 , V_19 ) )
goto V_89;
F_54 ( V_18 ) ;
if ( V_82 ) {
if ( ! V_81 )
F_55 ( V_18 , & V_29 -> V_7 ) ;
else
F_56 ( V_18 , F_57 ( & V_29 -> V_7 ) ) ;
} else
F_56 ( V_18 , & V_29 -> V_7 ) ;
return V_81 ;
V_89:
if ( ! V_82 )
F_65 ( & V_29 -> V_7 ) ;
return - 1 ;
V_83:
if ( ! V_18 -> V_38 )
V_18 -> V_38 = F_27 ( V_18 ) -> V_38 ;
F_58 ( V_18 ) ;
return - 1 ;
}
static inline int F_68 ( struct V_17 * V_18 ,
struct V_100 * V_101 )
{
int V_102 = V_103 ;
V_18 -> V_104 = 1 ;
if ( F_31 ( V_101 -> V_39 & V_105 ) )
V_102 = F_69 ( V_18 ) ;
if ( V_102 == V_103 ) {
F_70 ( V_18 ) ;
F_71 ( V_18 ) ;
}
return V_102 ;
}
static inline void F_72 ( struct V_17 * V_18 )
{
if ( V_18 -> V_38 )
F_73 ( V_18 ) ;
}
static inline int F_74 ( int V_106 , struct V_17 * V_18 ,
struct V_100 * V_101 , int V_81 )
{
int V_102 = V_107 ;
V_18 -> V_104 = 1 ;
if ( F_49 ( ! ( V_101 -> V_39 & V_105 ) ) )
F_75 ( V_18 ) ;
else
F_76 ( V_18 , V_101 , 1 ) ;
if ( ! V_81 || V_101 -> V_108 != V_101 -> V_109 ||
! F_77 ( V_101 -> V_110 , & V_101 -> V_111 , & V_101 -> V_24 ) )
F_72 ( V_18 ) ;
if ( ! V_81 ) {
F_71 ( V_18 ) ;
F_78 ( V_106 , V_112 , V_101 -> V_60 -> V_23 , NULL , V_18 ,
NULL , F_27 ( V_18 ) -> V_38 , V_113 ) ;
} else
V_102 = V_103 ;
return V_102 ;
}
static inline int F_79 ( int V_106 , struct V_17 * V_18 ,
struct V_100 * V_101 , int V_81 )
{
int V_102 = V_107 ;
V_18 -> V_104 = 1 ;
if ( F_49 ( ! ( V_101 -> V_39 & V_105 ) ) )
F_75 ( V_18 ) ;
if ( ! V_81 ) {
F_72 ( V_18 ) ;
F_71 ( V_18 ) ;
F_78 ( V_106 , V_112 , V_101 -> V_60 -> V_23 , NULL , V_18 ,
NULL , F_27 ( V_18 ) -> V_38 , V_113 ) ;
} else
V_102 = V_103 ;
return V_102 ;
}
int
F_80 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
return F_79 ( V_116 , V_18 , V_101 , 1 ) ;
}
int
F_81 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
struct V_79 * V_117 = F_29 ( V_18 ) ;
F_82 ( 10 ) ;
F_83 () ;
if ( F_48 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , NULL , V_117 -> V_24 ,
V_118 , NULL , V_62 ) < 0 )
goto V_119;
F_84 ( V_117 ) ;
V_18 -> V_120 = 1 ;
F_79 ( V_116 , V_18 , V_101 , 0 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_88 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
struct V_75 * V_117 = F_26 ( V_18 ) ;
F_82 ( 10 ) ;
F_83 () ;
if ( F_66 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , NULL ,
& V_117 -> V_24 , NULL ,
V_62 , 0 , V_118 ) < 0 )
goto V_119;
V_18 -> V_120 = 1 ;
F_79 ( V_121 , V_18 , V_101 , 0 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_89 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
struct V_22 * V_29 ;
int V_81 , V_122 , V_123 ;
F_82 ( 10 ) ;
F_83 () ;
if ( F_31 ( V_101 -> V_39 & V_124 ) ) {
T_3 V_125 , * V_126 ;
V_126 = F_90 ( V_18 , V_62 -> V_21 , sizeof( V_125 ) , & V_125 ) ;
if ( V_126 == NULL )
goto V_119;
F_91 ( V_101 , * V_126 ) ;
F_37 ( 10 , L_12 , F_92 ( * V_126 ) ) ;
}
V_123 = F_93 ( F_30 ( V_18 ) ) ;
V_81 = F_48 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 , V_101 -> V_24 . V_85 ,
V_44 |
V_118 |
V_47 , NULL , V_62 ) ;
if ( V_81 < 0 )
goto V_119;
V_29 = F_30 ( V_18 ) ;
#if F_94 ( V_127 )
if ( V_101 -> V_39 & V_128 && V_81 ) {
enum V_129 V_130 ;
struct V_131 * V_132 = F_95 ( V_18 , & V_130 ) ;
if ( V_132 ) {
F_96 ( 10 , V_133 , V_115 , V_18 , V_62 -> V_134 ,
L_13
L_14 ) ;
goto V_119;
}
}
#endif
if ( V_81 && F_28 ( V_101 -> V_24 . V_85 ) && V_123 ) {
F_96 ( 1 , V_133 , V_115 , V_18 , V_62 -> V_134 ,
L_15
L_16 ) ;
goto V_119;
}
if ( ! F_45 ( V_18 , sizeof( struct V_79 ) ) )
goto V_119;
if ( F_97 ( V_18 , V_29 -> V_7 . V_38 -> V_135 ) )
goto V_119;
if ( V_115 -> V_136 && ! V_115 -> V_136 ( V_18 , V_115 , V_101 , V_62 ) )
goto V_119;
F_29 ( V_18 ) -> V_24 = V_101 -> V_24 . V_85 ;
F_84 ( F_29 ( V_18 ) ) ;
F_98 ( 10 , V_133 , V_115 , V_18 , V_62 -> V_134 , L_17 ) ;
V_18 -> V_120 = 1 ;
V_122 = F_74 ( V_116 , V_18 , V_101 , V_81 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_122 ;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_99 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
struct V_37 * V_29 ;
int V_81 , V_122 ;
F_82 ( 10 ) ;
F_83 () ;
if ( F_31 ( V_101 -> V_39 & V_124 && ! V_62 -> V_64 ) ) {
T_3 V_125 , * V_126 ;
V_126 = F_90 ( V_18 , V_62 -> V_21 , sizeof( V_125 ) , & V_125 ) ;
if ( V_126 == NULL )
goto V_119;
F_91 ( V_101 , * V_126 ) ;
F_37 ( 10 , L_12 , F_92 ( * V_126 ) ) ;
}
V_81 = F_66 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 ,
& V_101 -> V_24 . V_98 ,
NULL , V_62 , 0 ,
V_44 |
V_118 |
V_47 ) ;
if ( V_81 < 0 )
goto V_119;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_94 ( V_127 )
if ( V_101 -> V_39 & V_128 && V_81 ) {
enum V_129 V_130 ;
struct V_131 * V_132 = F_95 ( V_18 , & V_130 ) ;
if ( V_132 ) {
F_96 ( 10 , V_50 , V_115 , V_18 , V_62 -> V_134 ,
L_18
L_14 ) ;
goto V_119;
}
}
#endif
if ( V_81 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_101 -> V_24 . V_98 ) & V_52 ) {
F_96 ( 1 , V_50 , V_115 , V_18 , V_62 -> V_134 ,
L_18
L_19 ) ;
goto V_119;
}
if ( ! F_45 ( V_18 , sizeof( struct V_75 ) ) )
goto V_119;
if ( F_97 ( V_18 , V_29 -> V_7 . V_38 -> V_135 ) )
goto V_119;
if ( V_115 -> V_136 && ! V_115 -> V_136 ( V_18 , V_115 , V_101 , V_62 ) )
goto V_119;
F_26 ( V_18 ) -> V_24 = V_101 -> V_24 . V_98 ;
F_98 ( 10 , V_50 , V_115 , V_18 , V_62 -> V_134 , L_17 ) ;
V_18 -> V_120 = 1 ;
V_122 = F_74 ( V_121 , V_18 , V_101 , V_81 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_122 ;
V_119:
F_86 ( 10 ) ;
F_87 ( V_18 ) ;
F_85 () ;
return V_107 ;
}
static struct V_17 *
F_100 ( struct V_17 * V_18 , int V_41 ,
unsigned int V_137 , T_4 * V_138 ,
T_5 * V_139 , T_4 * V_140 , T_4 * V_76 ,
T_3 * V_141 )
{
struct V_17 * V_142 = NULL ;
struct V_79 * V_143 = NULL ;
#ifdef F_24
struct V_75 * V_144 = NULL ;
#endif
F_72 ( V_18 ) ;
if ( F_101 ( V_18 ) < V_137 || F_102 ( V_18 ) ) {
V_142 = F_103 ( V_18 , V_137 ) ;
if ( ! V_142 )
goto error;
if ( V_18 -> V_56 )
F_104 ( V_142 , V_18 -> V_56 ) ;
F_105 ( V_18 ) ;
V_18 = V_142 ;
}
#ifdef F_24
if ( V_41 == V_50 ) {
V_144 = F_26 ( V_18 ) ;
* V_138 = V_145 ;
if ( V_139 )
* V_139 =
F_92 ( V_144 -> V_139 ) +
sizeof( * V_144 ) ;
* V_140 = F_106 ( V_144 ) ;
* V_76 = V_144 -> V_71 ;
if ( V_141 )
* V_141 = 0 ;
} else
#endif
{
V_143 = F_29 ( V_18 ) ;
if ( V_141 )
* V_141 = ( V_143 -> V_67 & F_39 ( V_68 ) ) ;
* V_138 = V_146 ;
F_84 ( V_143 ) ;
* V_140 = F_107 ( V_143 ) ;
* V_76 = V_143 -> V_76 ;
if ( V_139 )
* V_139 = F_92 ( V_143 -> V_147 ) ;
}
return V_18 ;
error:
F_87 ( V_18 ) ;
return F_108 ( - V_148 ) ;
}
static inline int F_109 ( int V_149 , int V_150 )
{
switch ( V_149 ) {
case V_133 :
return V_151 ;
case V_50 :
return V_152 ;
default:
return 0 ;
}
}
int
F_110 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
struct V_59 * V_60 = V_101 -> V_60 ;
struct V_23 * V_23 = V_60 -> V_23 ;
struct V_22 * V_29 ;
T_2 V_26 ;
struct V_153 * V_154 ;
T_4 V_138 = 0 ;
T_4 V_140 = 0 ;
T_4 V_76 = 0 ;
T_3 V_141 = 0 ;
T_3 * V_155 = NULL ;
struct V_79 * V_117 ;
unsigned int V_137 ;
int V_102 , V_81 ;
F_82 ( 10 ) ;
F_83 () ;
V_81 = F_48 ( V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 , V_101 -> V_24 . V_85 ,
V_44 |
V_118 |
V_36 |
V_66 , & V_26 , V_62 ) ;
if ( V_81 < 0 )
goto V_119;
if ( V_81 ) {
F_85 () ;
return F_79 ( V_116 , V_18 , V_101 , 1 ) ;
}
V_29 = F_30 ( V_18 ) ;
V_154 = V_29 -> V_7 . V_38 ;
V_137 = F_111 ( V_154 ) + sizeof( struct V_79 ) ;
V_155 = F_38 ( V_60 ) ? & V_141 : NULL ;
V_18 = F_100 ( V_18 , V_101 -> V_110 , V_137 ,
& V_138 , NULL , & V_140 ,
& V_76 , V_155 ) ;
if ( F_17 ( V_18 ) )
goto V_119;
if ( F_112 ( V_18 , F_109 ( V_133 , V_101 -> V_110 ) ) )
goto V_119;
V_18 -> V_156 = V_18 -> V_157 ;
F_113 ( V_18 , sizeof( struct V_79 ) ) ;
F_114 ( V_18 ) ;
memset ( & ( F_115 ( V_18 ) -> V_158 ) , 0 , sizeof( F_115 ( V_18 ) -> V_158 ) ) ;
V_117 = F_29 ( V_18 ) ;
V_117 -> V_159 = 4 ;
V_117 -> V_160 = sizeof( struct V_79 ) >> 2 ;
V_117 -> V_67 = V_141 ;
V_117 -> V_161 = V_138 ;
V_117 -> V_162 = V_140 ;
V_117 -> V_24 = V_101 -> V_24 . V_85 ;
V_117 -> V_26 = V_26 ;
V_117 -> V_76 = V_76 ;
F_116 ( V_23 , V_18 , NULL ) ;
V_18 -> V_120 = 1 ;
V_102 = F_68 ( V_18 , V_101 ) ;
if ( V_102 == V_103 )
F_117 ( V_23 , V_18 -> V_56 , V_18 ) ;
else if ( V_102 == V_163 )
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
V_119:
if ( ! F_17 ( V_18 ) )
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_118 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
struct V_37 * V_29 ;
struct V_91 V_26 ;
struct V_153 * V_154 ;
T_4 V_138 = 0 ;
T_5 V_139 = 0 ;
T_4 V_140 = 0 ;
T_4 V_76 = 0 ;
struct V_75 * V_117 ;
unsigned int V_137 ;
int V_102 , V_81 ;
F_82 ( 10 ) ;
F_83 () ;
V_81 = F_66 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 ,
& V_101 -> V_24 . V_98 ,
& V_26 , V_62 , 1 ,
V_44 |
V_118 |
V_66 ) ;
if ( V_81 < 0 )
goto V_119;
if ( V_81 ) {
F_85 () ;
return F_79 ( V_121 , V_18 , V_101 , 1 ) ;
}
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
V_154 = V_29 -> V_7 . V_38 ;
V_137 = F_111 ( V_154 ) + sizeof( struct V_75 ) ;
V_18 = F_100 ( V_18 , V_101 -> V_110 , V_137 ,
& V_138 , & V_139 ,
& V_140 , & V_76 , NULL ) ;
if ( F_17 ( V_18 ) )
goto V_119;
if ( F_112 ( V_18 , F_109 ( V_50 , V_101 -> V_110 ) ) )
goto V_119;
V_18 -> V_156 = V_18 -> V_157 ;
F_113 ( V_18 , sizeof( struct V_75 ) ) ;
F_114 ( V_18 ) ;
memset ( & ( F_115 ( V_18 ) -> V_158 ) , 0 , sizeof( F_115 ( V_18 ) -> V_158 ) ) ;
V_117 = F_26 ( V_18 ) ;
V_117 -> V_159 = 6 ;
V_117 -> V_164 = V_138 ;
V_117 -> V_139 = F_39 ( V_139 ) ;
memset ( & V_117 -> V_165 , 0 , sizeof( V_117 -> V_165 ) ) ;
F_119 ( V_117 , 0 , V_140 ) ;
V_117 -> V_24 = V_101 -> V_24 . V_98 ;
V_117 -> V_26 = V_26 ;
V_117 -> V_71 = V_76 ;
V_18 -> V_120 = 1 ;
V_102 = F_68 ( V_18 , V_101 ) ;
if ( V_102 == V_103 )
F_120 ( V_101 -> V_60 -> V_23 , V_18 -> V_56 , V_18 ) ;
else if ( V_102 == V_163 )
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
V_119:
if ( ! F_17 ( V_18 ) )
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_121 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
int V_81 ;
F_82 ( 10 ) ;
F_83 () ;
V_81 = F_48 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 , V_101 -> V_24 . V_85 ,
V_44 |
V_118 |
V_32 , NULL , V_62 ) ;
if ( V_81 < 0 )
goto V_119;
if ( V_81 ) {
F_85 () ;
return F_79 ( V_116 , V_18 , V_101 , 1 ) ;
}
F_84 ( F_29 ( V_18 ) ) ;
V_18 -> V_120 = 1 ;
F_79 ( V_116 , V_18 , V_101 , 0 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_122 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , struct V_61 * V_62 )
{
int V_81 ;
F_82 ( 10 ) ;
F_83 () ;
V_81 = F_66 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 ,
& V_101 -> V_24 . V_98 ,
NULL , V_62 , 0 ,
V_44 |
V_118 |
V_32 ) ;
if ( V_81 < 0 )
goto V_119;
if ( V_81 ) {
F_85 () ;
return F_79 ( V_121 , V_18 , V_101 , 1 ) ;
}
V_18 -> V_120 = 1 ;
F_79 ( V_121 , V_18 , V_101 , 0 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
F_86 ( 10 ) ;
return V_107 ;
}
int
F_123 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , int V_166 , unsigned int V_167 ,
struct V_61 * V_117 )
{
struct V_22 * V_29 ;
int V_122 ;
int V_81 ;
int V_25 , V_123 ;
F_82 ( 10 ) ;
if ( F_124 ( V_101 ) != V_168 ) {
if ( V_101 -> V_169 )
V_122 = V_101 -> V_169 ( V_18 , V_101 , V_115 , V_117 ) ;
else
V_122 = V_103 ;
F_125 ( & V_101 -> V_170 ) ;
goto V_171;
}
V_123 = F_93 ( F_30 ( V_18 ) ) ;
V_25 = ( V_167 != V_172 ) ?
V_44 | V_118 |
V_47 : V_118 ;
F_83 () ;
V_81 = F_48 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 , V_101 -> V_24 . V_85 , V_25 ,
NULL , V_117 ) ;
if ( V_81 < 0 )
goto V_119;
V_29 = F_30 ( V_18 ) ;
#if F_94 ( V_127 )
if ( V_101 -> V_39 & V_128 && V_81 ) {
enum V_129 V_130 ;
struct V_131 * V_132 = F_95 ( V_18 , & V_130 ) ;
if ( V_132 ) {
F_37 ( 10 , L_20
L_21 ,
V_90 , & V_101 -> V_24 . V_85 ) ;
goto V_119;
}
}
#endif
if ( V_81 && F_28 ( V_101 -> V_24 . V_85 ) && V_123 ) {
F_37 ( 1 , L_20
L_22 ,
V_90 , & V_101 -> V_24 . V_85 ) ;
goto V_119;
}
if ( ! F_45 ( V_18 , V_166 ) )
goto V_119;
if ( F_97 ( V_18 , V_29 -> V_7 . V_38 -> V_135 ) )
goto V_119;
F_126 ( V_18 , V_115 , V_101 , 0 ) ;
V_18 -> V_120 = 1 ;
V_122 = F_74 ( V_116 , V_18 , V_101 , V_81 ) ;
F_85 () ;
goto V_171;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
V_122 = V_107 ;
V_171:
F_86 ( 10 ) ;
return V_122 ;
}
int
F_127 ( struct V_17 * V_18 , struct V_100 * V_101 ,
struct V_114 * V_115 , int V_166 , unsigned int V_167 ,
struct V_61 * V_62 )
{
struct V_37 * V_29 ;
int V_122 ;
int V_81 ;
int V_25 ;
F_82 ( 10 ) ;
if ( F_124 ( V_101 ) != V_168 ) {
if ( V_101 -> V_169 )
V_122 = V_101 -> V_169 ( V_18 , V_101 , V_115 , V_62 ) ;
else
V_122 = V_103 ;
F_125 ( & V_101 -> V_170 ) ;
goto V_171;
}
V_25 = ( V_167 != V_172 ) ?
V_44 | V_118 |
V_47 : V_118 ;
F_83 () ;
V_81 = F_66 ( V_101 -> V_60 , V_101 -> V_110 , V_18 , V_101 -> V_5 ,
& V_101 -> V_24 . V_98 , NULL , V_62 , 0 , V_25 ) ;
if ( V_81 < 0 )
goto V_119;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_94 ( V_127 )
if ( V_101 -> V_39 & V_128 && V_81 ) {
enum V_129 V_130 ;
struct V_131 * V_132 = F_95 ( V_18 , & V_130 ) ;
if ( V_132 ) {
F_37 ( 10 , L_20
L_23 ,
V_90 , & V_101 -> V_24 . V_98 ) ;
goto V_119;
}
}
#endif
if ( V_81 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_101 -> V_24 . V_98 ) & V_52 ) {
F_37 ( 1 , L_20
L_24 ,
V_90 , & V_101 -> V_24 . V_98 ) ;
goto V_119;
}
if ( ! F_45 ( V_18 , V_166 ) )
goto V_119;
if ( F_97 ( V_18 , V_29 -> V_7 . V_38 -> V_135 ) )
goto V_119;
F_128 ( V_18 , V_115 , V_101 , 0 ) ;
V_18 -> V_120 = 1 ;
V_122 = F_74 ( V_121 , V_18 , V_101 , V_81 ) ;
F_85 () ;
goto V_171;
V_119:
F_87 ( V_18 ) ;
F_85 () ;
V_122 = V_107 ;
V_171:
F_86 ( 10 ) ;
return V_122 ;
}
