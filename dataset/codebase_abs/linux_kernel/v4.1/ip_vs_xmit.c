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
V_28 . V_26 = ( V_25 & V_31 ) ? * V_26 : 0 ;
V_28 . V_32 = ( V_25 & V_33 ) ?
V_34 : 0 ;
V_35:
V_29 = F_16 ( V_23 , & V_28 ) ;
if ( F_17 ( V_29 ) ) {
if ( F_18 ( V_29 ) == - V_36 && * V_26 &&
V_25 & V_31 && ! V_30 ) {
* V_26 = 0 ;
F_19 ( & V_28 , 0 , 0 , V_24 , 0 ) ;
goto V_35;
}
F_20 ( L_1 , & V_24 ) ;
return NULL ;
} else if ( ! * V_26 && V_25 & V_31 && V_28 . V_26 ) {
F_21 ( V_29 ) ;
* V_26 = V_28 . V_26 ;
F_19 ( & V_28 , 0 , 0 , V_24 , V_28 . V_26 ) ;
V_30 ++ ;
goto V_35;
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
static inline bool F_34 ( int V_41 , int V_25 ,
struct V_59 * V_60 ,
struct V_17 * V_18 , int V_19 )
{
#ifdef F_24
if ( V_41 == V_50 ) {
struct V_23 * V_23 = F_35 ( F_27 ( V_18 ) -> V_38 ) ;
if ( F_31 ( F_12 ( V_18 , V_19 ) ) ) {
if ( ! V_18 -> V_38 )
V_18 -> V_38 = V_23 -> V_61 ;
if ( ! V_60 -> V_62 )
F_36 ( V_18 , V_63 , 0 , V_19 ) ;
F_37 ( 1 , L_2 ,
& F_26 ( V_18 ) -> V_26 ) ;
return false ;
}
} else
#endif
{
struct V_64 * V_65 = F_38 ( F_39 ( V_18 ) ) ;
if ( ( V_25 & V_66 ) && ! F_40 ( V_65 ) )
return true ;
if ( F_31 ( F_29 ( V_18 ) -> V_67 & F_41 ( V_68 ) &&
V_18 -> V_21 > V_19 && ! F_14 ( V_18 ) ) ) {
F_42 ( V_18 , V_69 , V_70 ,
F_43 ( V_19 ) ) ;
F_37 ( 1 , L_3 ,
& F_29 ( V_18 ) -> V_26 ) ;
return false ;
}
}
return true ;
}
static int
F_44 ( int V_41 , struct V_17 * V_18 , struct V_4 * V_5 ,
T_2 V_24 , int V_25 , T_2 * V_71 ,
struct V_59 * V_60 )
{
struct V_23 * V_23 = F_35 ( F_27 ( V_18 ) -> V_38 ) ;
struct V_1 * V_3 ;
struct V_22 * V_29 ;
int V_19 ;
int V_72 , V_73 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_45 ( V_3 ) )
V_29 = (struct V_22 * ) V_3 -> V_11 ;
else {
V_3 = F_1 () ;
F_46 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_47 ( & V_5 -> V_10 ) ;
goto V_74;
}
V_29 = F_15 ( V_23 , V_5 -> V_75 . V_76 , V_25 ,
& V_3 -> V_77 . V_76 ) ;
if ( ! V_29 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_47 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_74;
}
F_5 ( V_5 , V_3 , & V_29 -> V_7 , 0 ) ;
F_47 ( & V_5 -> V_10 ) ;
F_37 ( 10 , L_4 ,
& V_5 -> V_75 . V_76 , & V_3 -> V_77 . V_76 ,
F_48 ( & V_29 -> V_7 . V_78 ) ) ;
}
if ( V_71 )
* V_71 = V_3 -> V_77 . V_76 ;
} else {
T_2 V_26 = F_43 ( V_79 ) ;
V_73 = 0 ;
V_25 &= ~ V_31 ;
V_29 = F_15 ( V_23 , V_24 , V_25 , & V_26 ) ;
if ( ! V_29 )
goto V_74;
if ( V_71 )
* V_71 = V_26 ;
}
V_72 = ( V_29 -> V_53 & V_54 ) ? 1 : 0 ;
if ( F_31 ( F_23 ( V_41 , V_18 , V_25 ,
V_72 ) ) ) {
F_20 ( L_5
L_6 , & V_24 ) ;
goto V_80;
}
if ( F_31 ( V_72 ) ) {
if ( ! V_73 )
F_21 ( V_29 ) ;
return V_72 ;
}
if ( F_45 ( ! ( V_25 & V_66 ) ) ) {
V_19 = F_49 ( & V_29 -> V_7 ) ;
} else {
V_19 = F_49 ( & V_29 -> V_7 ) - sizeof( struct V_81 ) ;
if ( V_19 < 68 ) {
F_20 ( L_7 , V_82 ) ;
goto V_80;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_34 ( V_41 , V_25 , V_60 , V_18 , V_19 ) )
goto V_80;
F_50 ( V_18 ) ;
if ( V_73 ) {
if ( ! V_72 )
F_51 ( V_18 , & V_29 -> V_7 ) ;
else
F_52 ( V_18 , F_53 ( & V_29 -> V_7 ) ) ;
} else
F_52 ( V_18 , & V_29 -> V_7 ) ;
return V_72 ;
V_80:
if ( ! V_73 )
F_21 ( V_29 ) ;
return - 1 ;
V_74:
F_54 ( V_18 ) ;
return - 1 ;
}
static struct V_6 *
F_55 ( struct V_23 * V_23 , struct V_83 * V_24 ,
struct V_83 * V_71 , int V_84 )
{
struct V_6 * V_7 ;
struct V_85 V_86 = {
. V_24 = * V_24 ,
} ;
V_7 = F_56 ( V_23 , NULL , & V_86 ) ;
if ( V_7 -> error )
goto V_87;
if ( ! V_71 )
return V_7 ;
if ( F_57 ( & V_86 . V_26 ) &&
F_58 ( V_23 , F_59 ( V_7 ) -> V_38 ,
& V_86 . V_24 , 0 , & V_86 . V_26 ) < 0 )
goto V_87;
if ( V_84 ) {
V_7 = F_60 ( V_23 , V_7 , F_61 ( & V_86 ) , NULL , 0 ) ;
if ( F_17 ( V_7 ) ) {
V_7 = NULL ;
goto V_87;
}
}
* V_71 = V_86 . V_26 ;
return V_7 ;
V_87:
F_62 ( V_7 ) ;
F_20 ( L_8 , V_24 ) ;
return NULL ;
}
static int
F_63 ( int V_41 , struct V_17 * V_18 , struct V_4 * V_5 ,
struct V_83 * V_24 , struct V_83 * V_71 ,
struct V_59 * V_60 , int V_84 , int V_25 )
{
struct V_23 * V_23 = F_35 ( F_27 ( V_18 ) -> V_38 ) ;
struct V_1 * V_3 ;
struct V_37 * V_29 ;
struct V_6 * V_7 ;
int V_19 ;
int V_72 , V_73 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_45 ( V_3 ) )
V_29 = (struct V_37 * ) V_3 -> V_11 ;
else {
T_1 V_88 ;
V_3 = F_1 () ;
F_46 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_47 ( & V_5 -> V_10 ) ;
goto V_74;
}
V_7 = F_55 ( V_23 , & V_5 -> V_75 . V_89 ,
& V_3 -> V_77 . V_89 ,
V_84 ) ;
if ( ! V_7 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_47 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_74;
}
V_29 = (struct V_37 * ) V_7 ;
V_88 = V_29 -> V_90 ? V_29 -> V_90 -> V_91 : 0 ;
F_5 ( V_5 , V_3 , & V_29 -> V_7 , V_88 ) ;
F_47 ( & V_5 -> V_10 ) ;
F_37 ( 10 , L_9 ,
& V_5 -> V_75 . V_89 , & V_3 -> V_77 . V_89 ,
F_48 ( & V_29 -> V_7 . V_78 ) ) ;
}
if ( V_71 )
* V_71 = V_3 -> V_77 . V_89 ;
} else {
V_73 = 0 ;
V_7 = F_55 ( V_23 , V_24 , V_71 , V_84 ) ;
if ( ! V_7 )
goto V_74;
V_29 = (struct V_37 * ) V_7 ;
}
V_72 = F_22 ( V_29 ) ;
if ( F_31 ( F_23 ( V_41 , V_18 , V_25 ,
V_72 ) ) ) {
F_20 ( L_5
L_10 , V_24 ) ;
goto V_80;
}
if ( F_31 ( V_72 ) ) {
if ( ! V_73 )
F_62 ( & V_29 -> V_7 ) ;
return V_72 ;
}
if ( F_45 ( ! ( V_25 & V_66 ) ) )
V_19 = F_49 ( & V_29 -> V_7 ) ;
else {
V_19 = F_49 ( & V_29 -> V_7 ) - sizeof( struct V_92 ) ;
if ( V_19 < V_93 ) {
F_20 ( L_11 , V_82 ,
V_93 ) ;
goto V_80;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_34 ( V_41 , V_25 , V_60 , V_18 , V_19 ) )
goto V_80;
F_50 ( V_18 ) ;
if ( V_73 ) {
if ( ! V_72 )
F_51 ( V_18 , & V_29 -> V_7 ) ;
else
F_52 ( V_18 , F_53 ( & V_29 -> V_7 ) ) ;
} else
F_52 ( V_18 , & V_29 -> V_7 ) ;
return V_72 ;
V_80:
if ( ! V_73 )
F_62 ( & V_29 -> V_7 ) ;
return - 1 ;
V_74:
F_54 ( V_18 ) ;
return - 1 ;
}
static inline int F_64 ( struct V_17 * V_18 ,
struct V_94 * V_95 )
{
int V_96 = V_97 ;
V_18 -> V_98 = 1 ;
if ( F_31 ( V_95 -> V_39 & V_99 ) )
V_96 = F_65 ( V_18 ) ;
if ( V_96 == V_97 ) {
F_66 ( V_18 ) ;
F_67 ( V_18 ) ;
}
return V_96 ;
}
static inline int F_68 ( int V_100 , struct V_17 * V_18 ,
struct V_94 * V_95 , int V_72 )
{
int V_96 = V_101 ;
V_18 -> V_98 = 1 ;
if ( F_45 ( ! ( V_95 -> V_39 & V_99 ) ) )
F_69 ( V_18 ) ;
else
F_70 ( V_18 , V_95 , 1 ) ;
if ( ! V_72 ) {
F_67 ( V_18 ) ;
F_71 ( V_100 , V_102 , NULL , V_18 ,
NULL , F_27 ( V_18 ) -> V_38 , V_103 ) ;
} else
V_96 = V_97 ;
return V_96 ;
}
static inline int F_72 ( int V_100 , struct V_17 * V_18 ,
struct V_94 * V_95 , int V_72 )
{
int V_96 = V_101 ;
V_18 -> V_98 = 1 ;
if ( F_45 ( ! ( V_95 -> V_39 & V_99 ) ) )
F_69 ( V_18 ) ;
if ( ! V_72 ) {
F_67 ( V_18 ) ;
F_71 ( V_100 , V_102 , NULL , V_18 ,
NULL , F_27 ( V_18 ) -> V_38 , V_103 ) ;
} else
V_96 = V_97 ;
return V_96 ;
}
int
F_73 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
return F_72 ( V_106 , V_18 , V_95 , 1 ) ;
}
int
F_74 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
struct V_81 * V_107 = F_29 ( V_18 ) ;
F_75 ( 10 ) ;
F_76 () ;
if ( F_44 ( V_95 -> V_108 , V_18 , NULL , V_107 -> V_24 ,
V_109 , NULL , V_60 ) < 0 )
goto V_110;
F_77 ( V_107 ) ;
V_18 -> V_111 = 1 ;
F_72 ( V_106 , V_18 , V_95 , 0 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_81 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
F_75 ( 10 ) ;
F_76 () ;
if ( F_63 ( V_95 -> V_108 , V_18 , NULL , & V_60 -> V_24 . V_89 , NULL ,
V_60 , 0 , V_109 ) < 0 )
goto V_110;
V_18 -> V_111 = 1 ;
F_72 ( V_112 , V_18 , V_95 , 0 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_82 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
struct V_22 * V_29 ;
int V_72 , V_113 , V_114 ;
F_75 ( 10 ) ;
F_76 () ;
if ( F_31 ( V_95 -> V_39 & V_115 ) ) {
T_3 V_116 , * V_117 ;
V_117 = F_83 ( V_18 , V_60 -> V_21 , sizeof( V_116 ) , & V_116 ) ;
if ( V_117 == NULL )
goto V_110;
F_84 ( V_95 , * V_117 ) ;
F_37 ( 10 , L_12 , F_85 ( * V_117 ) ) ;
}
V_114 = F_86 ( F_30 ( V_18 ) ) ;
V_72 = F_44 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , V_95 -> V_24 . V_76 ,
V_44 |
V_109 |
V_47 , NULL , V_60 ) ;
if ( V_72 < 0 )
goto V_110;
V_29 = F_30 ( V_18 ) ;
#if F_87 ( V_118 )
if ( V_95 -> V_39 & V_119 && V_72 ) {
enum V_120 V_121 ;
struct V_122 * V_123 = F_88 ( V_18 , & V_121 ) ;
if ( V_123 && ! F_89 ( V_123 ) ) {
F_90 ( 10 , V_124 , V_105 , V_18 , 0 ,
L_13
L_14 ) ;
goto V_110;
}
}
#endif
if ( V_72 && F_28 ( V_95 -> V_24 . V_76 ) && V_114 ) {
F_90 ( 1 , V_124 , V_105 , V_18 , 0 , L_13
L_15 ) ;
goto V_110;
}
if ( ! F_91 ( V_18 , sizeof( struct V_81 ) ) )
goto V_110;
if ( F_92 ( V_18 , V_29 -> V_7 . V_38 -> V_125 ) )
goto V_110;
if ( V_105 -> V_126 && ! V_105 -> V_126 ( V_18 , V_105 , V_95 , V_60 ) )
goto V_110;
F_29 ( V_18 ) -> V_24 = V_95 -> V_24 . V_76 ;
F_77 ( F_29 ( V_18 ) ) ;
F_93 ( 10 , V_124 , V_105 , V_18 , 0 , L_16 ) ;
V_18 -> V_111 = 1 ;
V_113 = F_68 ( V_106 , V_18 , V_95 , V_72 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_113 ;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_94 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
struct V_37 * V_29 ;
int V_72 , V_113 ;
F_75 ( 10 ) ;
F_76 () ;
if ( F_31 ( V_95 -> V_39 & V_115 && ! V_60 -> V_62 ) ) {
T_3 V_116 , * V_117 ;
V_117 = F_83 ( V_18 , V_60 -> V_21 , sizeof( V_116 ) , & V_116 ) ;
if ( V_117 == NULL )
goto V_110;
F_84 ( V_95 , * V_117 ) ;
F_37 ( 10 , L_12 , F_85 ( * V_117 ) ) ;
}
V_72 = F_63 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , & V_95 -> V_24 . V_89 ,
NULL , V_60 , 0 ,
V_44 |
V_109 |
V_47 ) ;
if ( V_72 < 0 )
goto V_110;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_87 ( V_118 )
if ( V_95 -> V_39 & V_119 && V_72 ) {
enum V_120 V_121 ;
struct V_122 * V_123 = F_88 ( V_18 , & V_121 ) ;
if ( V_123 && ! F_89 ( V_123 ) ) {
F_90 ( 10 , V_50 , V_105 , V_18 , 0 ,
L_17
L_14 ) ;
goto V_110;
}
}
#endif
if ( V_72 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_29 -> V_127 . V_75 ) & V_52 ) {
F_90 ( 1 , V_50 , V_105 , V_18 , 0 ,
L_17
L_15 ) ;
goto V_110;
}
if ( ! F_91 ( V_18 , sizeof( struct V_92 ) ) )
goto V_110;
if ( F_92 ( V_18 , V_29 -> V_7 . V_38 -> V_125 ) )
goto V_110;
if ( V_105 -> V_126 && ! V_105 -> V_126 ( V_18 , V_105 , V_95 , V_60 ) )
goto V_110;
F_26 ( V_18 ) -> V_24 = V_95 -> V_24 . V_89 ;
F_93 ( 10 , V_50 , V_105 , V_18 , 0 , L_16 ) ;
V_18 -> V_111 = 1 ;
V_113 = F_68 ( V_112 , V_18 , V_95 , V_72 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_113 ;
V_110:
F_79 ( 10 ) ;
F_80 ( V_18 ) ;
F_78 () ;
return V_101 ;
}
static struct V_17 *
F_95 ( struct V_17 * V_18 , int V_41 ,
unsigned int V_128 , T_4 * V_129 ,
T_5 * V_130 , T_4 * V_131 , T_4 * V_132 ,
T_3 * V_133 )
{
struct V_17 * V_134 = NULL ;
struct V_81 * V_135 = NULL ;
#ifdef F_24
struct V_92 * V_136 = NULL ;
#endif
if ( F_96 ( V_18 ) < V_128 || F_97 ( V_18 ) ) {
V_134 = F_98 ( V_18 , V_128 ) ;
if ( ! V_134 )
goto error;
if ( V_18 -> V_56 )
F_99 ( V_134 , V_18 -> V_56 ) ;
F_100 ( V_18 ) ;
V_18 = V_134 ;
}
#ifdef F_24
if ( V_41 == V_50 ) {
V_136 = F_26 ( V_18 ) ;
* V_129 = V_137 ;
if ( V_130 )
* V_130 =
F_85 ( V_136 -> V_130 ) +
sizeof( * V_136 ) ;
* V_131 = F_101 ( V_136 ) ;
* V_132 = V_136 -> V_138 ;
if ( V_133 )
* V_133 = 0 ;
} else
#endif
{
V_135 = F_29 ( V_18 ) ;
if ( V_133 )
* V_133 = ( V_135 -> V_67 & F_41 ( V_68 ) ) ;
* V_129 = V_139 ;
F_77 ( V_135 ) ;
* V_131 = F_102 ( V_135 ) ;
* V_132 = V_135 -> V_132 ;
if ( V_130 )
* V_130 = F_85 ( V_135 -> V_140 ) ;
}
return V_18 ;
error:
F_80 ( V_18 ) ;
return F_103 ( - V_141 ) ;
}
static inline int F_104 ( int V_142 , int V_143 )
{
if ( V_142 == V_124 ) {
if ( V_143 == V_124 )
return V_144 ;
return V_145 ;
}
return 0 ;
}
int
F_105 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
struct V_23 * V_23 = F_39 ( V_18 ) ;
struct V_64 * V_65 = F_38 ( V_23 ) ;
struct V_22 * V_29 ;
T_2 V_26 ;
struct V_146 * V_147 ;
T_4 V_129 = 0 ;
T_4 V_131 = 0 ;
T_4 V_132 = 0 ;
T_3 V_133 = 0 ;
T_3 * V_148 = NULL ;
struct V_81 * V_107 ;
unsigned int V_128 ;
int V_96 , V_72 ;
F_75 ( 10 ) ;
F_76 () ;
V_72 = F_44 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , V_95 -> V_24 . V_76 ,
V_44 |
V_109 |
V_31 |
V_66 , & V_26 , V_60 ) ;
if ( V_72 < 0 )
goto V_110;
if ( V_72 ) {
F_78 () ;
return F_72 ( V_106 , V_18 , V_95 , 1 ) ;
}
V_29 = F_30 ( V_18 ) ;
V_147 = V_29 -> V_7 . V_38 ;
V_128 = F_106 ( V_147 ) + sizeof( struct V_81 ) ;
V_148 = F_40 ( V_65 ) ? & V_133 : NULL ;
V_18 = F_95 ( V_18 , V_95 -> V_108 , V_128 ,
& V_129 , NULL , & V_131 ,
& V_132 , V_148 ) ;
if ( F_17 ( V_18 ) )
goto V_110;
V_18 = F_107 (
V_18 , false , F_104 ( V_124 , V_95 -> V_108 ) ) ;
if ( F_17 ( V_18 ) )
goto V_110;
V_18 -> V_149 = V_18 -> V_150 ;
F_108 ( V_18 , sizeof( struct V_81 ) ) ;
F_109 ( V_18 ) ;
memset ( & ( F_110 ( V_18 ) -> V_151 ) , 0 , sizeof( F_110 ( V_18 ) -> V_151 ) ) ;
V_107 = F_29 ( V_18 ) ;
V_107 -> V_152 = 4 ;
V_107 -> V_153 = sizeof( struct V_81 ) >> 2 ;
V_107 -> V_67 = V_133 ;
V_107 -> V_154 = V_129 ;
V_107 -> V_155 = V_131 ;
V_107 -> V_24 = V_95 -> V_24 . V_76 ;
V_107 -> V_26 = V_26 ;
V_107 -> V_132 = V_132 ;
F_111 ( V_23 , V_18 , NULL ) ;
V_18 -> V_111 = 1 ;
V_96 = F_64 ( V_18 , V_95 ) ;
if ( V_96 == V_97 )
F_112 ( V_18 ) ;
else if ( V_96 == V_156 )
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
V_110:
if ( ! F_17 ( V_18 ) )
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_113 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
struct V_37 * V_29 ;
struct V_83 V_26 ;
struct V_146 * V_147 ;
T_4 V_129 = 0 ;
T_5 V_130 = 0 ;
T_4 V_131 = 0 ;
T_4 V_132 = 0 ;
struct V_92 * V_107 ;
unsigned int V_128 ;
int V_96 , V_72 ;
F_75 ( 10 ) ;
F_76 () ;
V_72 = F_63 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , & V_95 -> V_24 . V_89 ,
& V_26 , V_60 , 1 ,
V_44 |
V_109 |
V_66 ) ;
if ( V_72 < 0 )
goto V_110;
if ( V_72 ) {
F_78 () ;
return F_72 ( V_112 , V_18 , V_95 , 1 ) ;
}
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
V_147 = V_29 -> V_7 . V_38 ;
V_128 = F_106 ( V_147 ) + sizeof( struct V_92 ) ;
V_18 = F_95 ( V_18 , V_95 -> V_108 , V_128 ,
& V_129 , & V_130 ,
& V_131 , & V_132 , NULL ) ;
if ( F_17 ( V_18 ) )
goto V_110;
V_18 = F_107 (
V_18 , false , F_104 ( V_50 , V_95 -> V_108 ) ) ;
if ( F_17 ( V_18 ) )
goto V_110;
V_18 -> V_149 = V_18 -> V_150 ;
F_108 ( V_18 , sizeof( struct V_92 ) ) ;
F_109 ( V_18 ) ;
memset ( & ( F_110 ( V_18 ) -> V_151 ) , 0 , sizeof( F_110 ( V_18 ) -> V_151 ) ) ;
V_107 = F_26 ( V_18 ) ;
V_107 -> V_152 = 6 ;
V_107 -> V_157 = V_129 ;
V_107 -> V_130 = F_41 ( V_130 ) ;
memset ( & V_107 -> V_158 , 0 , sizeof( V_107 -> V_158 ) ) ;
F_114 ( V_107 , 0 , V_131 ) ;
V_107 -> V_24 = V_95 -> V_24 . V_89 ;
V_107 -> V_26 = V_26 ;
V_107 -> V_138 = V_132 ;
V_18 -> V_111 = 1 ;
V_96 = F_64 ( V_18 , V_95 ) ;
if ( V_96 == V_97 )
F_115 ( V_18 ) ;
else if ( V_96 == V_156 )
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
V_110:
if ( ! F_17 ( V_18 ) )
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_116 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
int V_72 ;
F_75 ( 10 ) ;
F_76 () ;
V_72 = F_44 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , V_95 -> V_24 . V_76 ,
V_44 |
V_109 |
V_33 , NULL , V_60 ) ;
if ( V_72 < 0 )
goto V_110;
if ( V_72 ) {
F_78 () ;
return F_72 ( V_106 , V_18 , V_95 , 1 ) ;
}
F_77 ( F_29 ( V_18 ) ) ;
V_18 -> V_111 = 1 ;
F_72 ( V_106 , V_18 , V_95 , 0 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_117 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , struct V_59 * V_60 )
{
int V_72 ;
F_75 ( 10 ) ;
F_76 () ;
V_72 = F_63 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , & V_95 -> V_24 . V_89 ,
NULL , V_60 , 0 ,
V_44 |
V_109 ) ;
if ( V_72 < 0 )
goto V_110;
if ( V_72 ) {
F_78 () ;
return F_72 ( V_112 , V_18 , V_95 , 1 ) ;
}
V_18 -> V_111 = 1 ;
F_72 ( V_112 , V_18 , V_95 , 0 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
F_79 ( 10 ) ;
return V_101 ;
}
int
F_118 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , int V_159 , unsigned int V_160 ,
struct V_59 * V_107 )
{
struct V_22 * V_29 ;
int V_113 ;
int V_72 ;
int V_25 , V_114 ;
F_75 ( 10 ) ;
if ( F_119 ( V_95 ) != V_161 ) {
if ( V_95 -> V_162 )
V_113 = V_95 -> V_162 ( V_18 , V_95 , V_105 , V_107 ) ;
else
V_113 = V_97 ;
F_120 ( & V_95 -> V_163 ) ;
goto V_164;
}
V_114 = F_86 ( F_30 ( V_18 ) ) ;
V_25 = ( V_160 != V_165 ) ?
V_44 | V_109 |
V_47 : V_109 ;
F_76 () ;
V_72 = F_44 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , V_95 -> V_24 . V_76 , V_25 ,
NULL , V_107 ) ;
if ( V_72 < 0 )
goto V_110;
V_29 = F_30 ( V_18 ) ;
#if F_87 ( V_118 )
if ( V_95 -> V_39 & V_119 && V_72 ) {
enum V_120 V_121 ;
struct V_122 * V_123 = F_88 ( V_18 , & V_121 ) ;
if ( V_123 && ! F_89 ( V_123 ) ) {
F_37 ( 10 , L_18
L_19 ,
V_82 , & V_95 -> V_24 . V_76 ) ;
goto V_110;
}
}
#endif
if ( V_72 && F_28 ( V_95 -> V_24 . V_76 ) && V_114 ) {
F_37 ( 1 , L_18
L_20 ,
V_82 , & V_95 -> V_24 . V_76 ) ;
goto V_110;
}
if ( ! F_91 ( V_18 , V_159 ) )
goto V_110;
if ( F_92 ( V_18 , V_29 -> V_7 . V_38 -> V_125 ) )
goto V_110;
F_121 ( V_18 , V_105 , V_95 , 0 ) ;
V_18 -> V_111 = 1 ;
V_113 = F_68 ( V_106 , V_18 , V_95 , V_72 ) ;
F_78 () ;
goto V_164;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
V_113 = V_101 ;
V_164:
F_79 ( 10 ) ;
return V_113 ;
}
int
F_122 ( struct V_17 * V_18 , struct V_94 * V_95 ,
struct V_104 * V_105 , int V_159 , unsigned int V_160 ,
struct V_59 * V_60 )
{
struct V_37 * V_29 ;
int V_113 ;
int V_72 ;
int V_25 ;
F_75 ( 10 ) ;
if ( F_119 ( V_95 ) != V_161 ) {
if ( V_95 -> V_162 )
V_113 = V_95 -> V_162 ( V_18 , V_95 , V_105 , V_60 ) ;
else
V_113 = V_97 ;
F_120 ( & V_95 -> V_163 ) ;
goto V_164;
}
V_25 = ( V_160 != V_165 ) ?
V_44 | V_109 |
V_47 : V_109 ;
F_76 () ;
V_72 = F_63 ( V_95 -> V_108 , V_18 , V_95 -> V_5 , & V_95 -> V_24 . V_89 ,
NULL , V_60 , 0 , V_25 ) ;
if ( V_72 < 0 )
goto V_110;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_87 ( V_118 )
if ( V_95 -> V_39 & V_119 && V_72 ) {
enum V_120 V_121 ;
struct V_122 * V_123 = F_88 ( V_18 , & V_121 ) ;
if ( V_123 && ! F_89 ( V_123 ) ) {
F_37 ( 10 , L_18
L_21 ,
V_82 , & V_95 -> V_24 . V_89 ) ;
goto V_110;
}
}
#endif
if ( V_72 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_29 -> V_127 . V_75 ) & V_52 ) {
F_37 ( 1 , L_18
L_22 ,
V_82 , & V_95 -> V_24 . V_89 ) ;
goto V_110;
}
if ( ! F_91 ( V_18 , V_159 ) )
goto V_110;
if ( F_92 ( V_18 , V_29 -> V_7 . V_38 -> V_125 ) )
goto V_110;
F_123 ( V_18 , V_105 , V_95 , 0 ) ;
V_18 -> V_111 = 1 ;
V_113 = F_68 ( V_112 , V_18 , V_95 , V_72 ) ;
F_78 () ;
goto V_164;
V_110:
F_80 ( V_18 ) ;
F_78 () ;
V_113 = V_101 ;
V_164:
F_79 ( 10 ) ;
return V_113 ;
}
