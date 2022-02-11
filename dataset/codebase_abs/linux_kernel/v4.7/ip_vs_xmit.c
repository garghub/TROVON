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
static int
F_42 ( struct V_59 * V_60 , int V_41 , struct V_17 * V_18 ,
struct V_4 * V_5 ,
T_2 V_24 , int V_25 , T_2 * V_71 ,
struct V_61 * V_62 )
{
struct V_23 * V_23 = V_60 -> V_23 ;
struct V_1 * V_3 ;
struct V_22 * V_29 ;
int V_19 ;
int V_72 , V_73 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_43 ( V_3 ) )
V_29 = (struct V_22 * ) V_3 -> V_11 ;
else {
V_3 = F_1 () ;
F_44 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_45 ( & V_5 -> V_10 ) ;
goto V_74;
}
V_29 = F_15 ( V_23 , V_5 -> V_75 . V_76 , V_25 ,
& V_3 -> V_77 . V_76 ) ;
if ( ! V_29 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_45 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_74;
}
F_5 ( V_5 , V_3 , & V_29 -> V_7 , 0 ) ;
F_45 ( & V_5 -> V_10 ) ;
F_37 ( 10 , L_4 ,
& V_5 -> V_75 . V_76 , & V_3 -> V_77 . V_76 ,
F_46 ( & V_29 -> V_7 . V_78 ) ) ;
}
if ( V_71 )
* V_71 = V_3 -> V_77 . V_76 ;
} else {
T_2 V_26 = F_41 ( V_79 ) ;
V_73 = 0 ;
V_25 &= ~ V_36 ;
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
if ( F_43 ( ! ( V_25 & V_66 ) ) ) {
V_19 = F_47 ( & V_29 -> V_7 ) ;
} else {
V_19 = F_47 ( & V_29 -> V_7 ) - sizeof( struct V_81 ) ;
if ( V_19 < 68 ) {
F_20 ( L_7 , V_82 ) ;
goto V_80;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_34 ( V_60 , V_41 , V_25 , V_62 , V_18 , V_19 ) )
goto V_80;
F_48 ( V_18 ) ;
if ( V_73 ) {
if ( ! V_72 )
F_49 ( V_18 , & V_29 -> V_7 ) ;
else
F_50 ( V_18 , F_51 ( & V_29 -> V_7 ) ) ;
} else
F_50 ( V_18 , & V_29 -> V_7 ) ;
return V_72 ;
V_80:
if ( ! V_73 )
F_21 ( V_29 ) ;
return - 1 ;
V_74:
F_52 ( V_18 ) ;
return - 1 ;
}
static struct V_6 *
F_53 ( struct V_23 * V_23 , struct V_83 * V_24 ,
struct V_83 * V_71 , int V_84 , int V_25 )
{
struct V_6 * V_7 ;
struct V_85 V_86 = {
. V_24 = * V_24 ,
} ;
if ( V_25 & V_32 )
V_86 . V_87 = V_33 ;
V_7 = F_54 ( V_23 , NULL , & V_86 ) ;
if ( V_7 -> error )
goto V_88;
if ( ! V_71 )
return V_7 ;
if ( F_55 ( & V_86 . V_26 ) &&
F_56 ( V_23 , F_57 ( V_7 ) -> V_38 ,
& V_86 . V_24 , 0 , & V_86 . V_26 ) < 0 )
goto V_88;
if ( V_84 ) {
V_7 = F_58 ( V_23 , V_7 , F_59 ( & V_86 ) , NULL , 0 ) ;
if ( F_17 ( V_7 ) ) {
V_7 = NULL ;
goto V_88;
}
}
* V_71 = V_86 . V_26 ;
return V_7 ;
V_88:
F_60 ( V_7 ) ;
F_20 ( L_8 , V_24 ) ;
return NULL ;
}
static int
F_61 ( struct V_59 * V_60 , int V_41 , struct V_17 * V_18 ,
struct V_4 * V_5 ,
struct V_83 * V_24 , struct V_83 * V_71 ,
struct V_61 * V_62 , int V_84 , int V_25 )
{
struct V_23 * V_23 = V_60 -> V_23 ;
struct V_1 * V_3 ;
struct V_37 * V_29 ;
struct V_6 * V_7 ;
int V_19 ;
int V_72 , V_73 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_43 ( V_3 ) )
V_29 = (struct V_37 * ) V_3 -> V_11 ;
else {
T_1 V_89 ;
V_3 = F_1 () ;
F_44 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_45 ( & V_5 -> V_10 ) ;
goto V_74;
}
V_7 = F_53 ( V_23 , & V_5 -> V_75 . V_90 ,
& V_3 -> V_77 . V_90 ,
V_84 , V_25 ) ;
if ( ! V_7 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_45 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_74;
}
V_29 = (struct V_37 * ) V_7 ;
V_89 = F_62 ( V_29 ) ;
F_5 ( V_5 , V_3 , & V_29 -> V_7 , V_89 ) ;
F_45 ( & V_5 -> V_10 ) ;
F_37 ( 10 , L_9 ,
& V_5 -> V_75 . V_90 , & V_3 -> V_77 . V_90 ,
F_46 ( & V_29 -> V_7 . V_78 ) ) ;
}
if ( V_71 )
* V_71 = V_3 -> V_77 . V_90 ;
} else {
V_73 = 0 ;
V_7 = F_53 ( V_23 , V_24 , V_71 , V_84 ,
V_25 ) ;
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
F_60 ( & V_29 -> V_7 ) ;
return V_72 ;
}
if ( F_43 ( ! ( V_25 & V_66 ) ) )
V_19 = F_47 ( & V_29 -> V_7 ) ;
else {
V_19 = F_47 ( & V_29 -> V_7 ) - sizeof( struct V_91 ) ;
if ( V_19 < V_92 ) {
F_20 ( L_11 , V_82 ,
V_92 ) ;
goto V_80;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_34 ( V_60 , V_41 , V_25 , V_62 , V_18 , V_19 ) )
goto V_80;
F_48 ( V_18 ) ;
if ( V_73 ) {
if ( ! V_72 )
F_49 ( V_18 , & V_29 -> V_7 ) ;
else
F_50 ( V_18 , F_51 ( & V_29 -> V_7 ) ) ;
} else
F_50 ( V_18 , & V_29 -> V_7 ) ;
return V_72 ;
V_80:
if ( ! V_73 )
F_60 ( & V_29 -> V_7 ) ;
return - 1 ;
V_74:
if ( ! V_18 -> V_38 )
V_18 -> V_38 = F_27 ( V_18 ) -> V_38 ;
F_52 ( V_18 ) ;
return - 1 ;
}
static inline int F_63 ( struct V_17 * V_18 ,
struct V_93 * V_94 )
{
int V_95 = V_96 ;
V_18 -> V_97 = 1 ;
if ( F_31 ( V_94 -> V_39 & V_98 ) )
V_95 = F_64 ( V_18 ) ;
if ( V_95 == V_96 ) {
F_65 ( V_18 ) ;
F_66 ( V_18 ) ;
}
return V_95 ;
}
static inline void F_67 ( struct V_17 * V_18 )
{
if ( V_18 -> V_38 )
F_68 ( V_18 ) ;
}
static inline int F_69 ( int V_99 , struct V_17 * V_18 ,
struct V_93 * V_94 , int V_72 )
{
int V_95 = V_100 ;
V_18 -> V_97 = 1 ;
if ( F_43 ( ! ( V_94 -> V_39 & V_98 ) ) )
F_70 ( V_18 ) ;
else
F_71 ( V_18 , V_94 , 1 ) ;
if ( ! V_72 || V_94 -> V_101 != V_94 -> V_102 ||
! F_72 ( V_94 -> V_103 , & V_94 -> V_104 , & V_94 -> V_24 ) )
F_67 ( V_18 ) ;
if ( ! V_72 ) {
F_66 ( V_18 ) ;
F_73 ( V_99 , V_105 , V_94 -> V_60 -> V_23 , NULL , V_18 ,
NULL , F_27 ( V_18 ) -> V_38 , V_106 ) ;
} else
V_95 = V_96 ;
return V_95 ;
}
static inline int F_74 ( int V_99 , struct V_17 * V_18 ,
struct V_93 * V_94 , int V_72 )
{
int V_95 = V_100 ;
V_18 -> V_97 = 1 ;
if ( F_43 ( ! ( V_94 -> V_39 & V_98 ) ) )
F_70 ( V_18 ) ;
if ( ! V_72 ) {
F_67 ( V_18 ) ;
F_66 ( V_18 ) ;
F_73 ( V_99 , V_105 , V_94 -> V_60 -> V_23 , NULL , V_18 ,
NULL , F_27 ( V_18 ) -> V_38 , V_106 ) ;
} else
V_95 = V_96 ;
return V_95 ;
}
int
F_75 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
return F_74 ( V_109 , V_18 , V_94 , 1 ) ;
}
int
F_76 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
struct V_81 * V_110 = F_29 ( V_18 ) ;
F_77 ( 10 ) ;
F_78 () ;
if ( F_42 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , NULL , V_110 -> V_24 ,
V_111 , NULL , V_62 ) < 0 )
goto V_112;
F_79 ( V_110 ) ;
V_18 -> V_113 = 1 ;
F_74 ( V_109 , V_18 , V_94 , 0 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_83 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
struct V_91 * V_110 = F_26 ( V_18 ) ;
F_77 ( 10 ) ;
F_78 () ;
if ( F_61 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , NULL ,
& V_110 -> V_24 , NULL ,
V_62 , 0 , V_111 ) < 0 )
goto V_112;
V_18 -> V_113 = 1 ;
F_74 ( V_114 , V_18 , V_94 , 0 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_84 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
struct V_22 * V_29 ;
int V_72 , V_115 , V_116 ;
F_77 ( 10 ) ;
F_78 () ;
if ( F_31 ( V_94 -> V_39 & V_117 ) ) {
T_3 V_118 , * V_119 ;
V_119 = F_85 ( V_18 , V_62 -> V_21 , sizeof( V_118 ) , & V_118 ) ;
if ( V_119 == NULL )
goto V_112;
F_86 ( V_94 , * V_119 ) ;
F_37 ( 10 , L_12 , F_87 ( * V_119 ) ) ;
}
V_116 = F_88 ( F_30 ( V_18 ) ) ;
V_72 = F_42 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 , V_94 -> V_24 . V_76 ,
V_44 |
V_111 |
V_47 , NULL , V_62 ) ;
if ( V_72 < 0 )
goto V_112;
V_29 = F_30 ( V_18 ) ;
#if F_89 ( V_120 )
if ( V_94 -> V_39 & V_121 && V_72 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_90 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_91 ( V_125 ) ) {
F_92 ( 10 , V_126 , V_108 , V_18 , V_62 -> V_127 ,
L_13
L_14 ) ;
goto V_112;
}
}
#endif
if ( V_72 && F_28 ( V_94 -> V_24 . V_76 ) && V_116 ) {
F_92 ( 1 , V_126 , V_108 , V_18 , V_62 -> V_127 ,
L_15
L_16 ) ;
goto V_112;
}
if ( ! F_93 ( V_18 , sizeof( struct V_81 ) ) )
goto V_112;
if ( F_94 ( V_18 , V_29 -> V_7 . V_38 -> V_128 ) )
goto V_112;
if ( V_108 -> V_129 && ! V_108 -> V_129 ( V_18 , V_108 , V_94 , V_62 ) )
goto V_112;
F_29 ( V_18 ) -> V_24 = V_94 -> V_24 . V_76 ;
F_79 ( F_29 ( V_18 ) ) ;
F_95 ( 10 , V_126 , V_108 , V_18 , V_62 -> V_127 , L_17 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_69 ( V_109 , V_18 , V_94 , V_72 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_115 ;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_96 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
struct V_37 * V_29 ;
int V_72 , V_115 ;
F_77 ( 10 ) ;
F_78 () ;
if ( F_31 ( V_94 -> V_39 & V_117 && ! V_62 -> V_64 ) ) {
T_3 V_118 , * V_119 ;
V_119 = F_85 ( V_18 , V_62 -> V_21 , sizeof( V_118 ) , & V_118 ) ;
if ( V_119 == NULL )
goto V_112;
F_86 ( V_94 , * V_119 ) ;
F_37 ( 10 , L_12 , F_87 ( * V_119 ) ) ;
}
V_72 = F_61 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 ,
& V_94 -> V_24 . V_90 ,
NULL , V_62 , 0 ,
V_44 |
V_111 |
V_47 ) ;
if ( V_72 < 0 )
goto V_112;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_89 ( V_120 )
if ( V_94 -> V_39 & V_121 && V_72 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_90 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_91 ( V_125 ) ) {
F_92 ( 10 , V_50 , V_108 , V_18 , V_62 -> V_127 ,
L_18
L_14 ) ;
goto V_112;
}
}
#endif
if ( V_72 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_94 -> V_24 . V_90 ) & V_52 ) {
F_92 ( 1 , V_50 , V_108 , V_18 , V_62 -> V_127 ,
L_18
L_19 ) ;
goto V_112;
}
if ( ! F_93 ( V_18 , sizeof( struct V_91 ) ) )
goto V_112;
if ( F_94 ( V_18 , V_29 -> V_7 . V_38 -> V_128 ) )
goto V_112;
if ( V_108 -> V_129 && ! V_108 -> V_129 ( V_18 , V_108 , V_94 , V_62 ) )
goto V_112;
F_26 ( V_18 ) -> V_24 = V_94 -> V_24 . V_90 ;
F_95 ( 10 , V_50 , V_108 , V_18 , V_62 -> V_127 , L_17 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_69 ( V_114 , V_18 , V_94 , V_72 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_115 ;
V_112:
F_81 ( 10 ) ;
F_82 ( V_18 ) ;
F_80 () ;
return V_100 ;
}
static struct V_17 *
F_97 ( struct V_17 * V_18 , int V_41 ,
unsigned int V_130 , T_4 * V_131 ,
T_5 * V_132 , T_4 * V_133 , T_4 * V_134 ,
T_3 * V_135 )
{
struct V_17 * V_136 = NULL ;
struct V_81 * V_137 = NULL ;
#ifdef F_24
struct V_91 * V_138 = NULL ;
#endif
F_67 ( V_18 ) ;
if ( F_98 ( V_18 ) < V_130 || F_99 ( V_18 ) ) {
V_136 = F_100 ( V_18 , V_130 ) ;
if ( ! V_136 )
goto error;
if ( V_18 -> V_56 )
F_101 ( V_136 , V_18 -> V_56 ) ;
F_102 ( V_18 ) ;
V_18 = V_136 ;
}
#ifdef F_24
if ( V_41 == V_50 ) {
V_138 = F_26 ( V_18 ) ;
* V_131 = V_139 ;
if ( V_132 )
* V_132 =
F_87 ( V_138 -> V_132 ) +
sizeof( * V_138 ) ;
* V_133 = F_103 ( V_138 ) ;
* V_134 = V_138 -> V_140 ;
if ( V_135 )
* V_135 = 0 ;
} else
#endif
{
V_137 = F_29 ( V_18 ) ;
if ( V_135 )
* V_135 = ( V_137 -> V_67 & F_39 ( V_68 ) ) ;
* V_131 = V_141 ;
F_79 ( V_137 ) ;
* V_133 = F_104 ( V_137 ) ;
* V_134 = V_137 -> V_134 ;
if ( V_132 )
* V_132 = F_87 ( V_137 -> V_142 ) ;
}
return V_18 ;
error:
F_82 ( V_18 ) ;
return F_105 ( - V_143 ) ;
}
static inline int F_106 ( int V_144 , int V_145 )
{
switch ( V_144 ) {
case V_126 :
return V_146 ;
case V_50 :
return V_147 ;
default:
return 0 ;
}
}
int
F_107 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
struct V_59 * V_60 = V_94 -> V_60 ;
struct V_23 * V_23 = V_60 -> V_23 ;
struct V_22 * V_29 ;
T_2 V_26 ;
struct V_148 * V_149 ;
T_4 V_131 = 0 ;
T_4 V_133 = 0 ;
T_4 V_134 = 0 ;
T_3 V_135 = 0 ;
T_3 * V_150 = NULL ;
struct V_81 * V_110 ;
unsigned int V_130 ;
int V_95 , V_72 ;
F_77 ( 10 ) ;
F_78 () ;
V_72 = F_42 ( V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 , V_94 -> V_24 . V_76 ,
V_44 |
V_111 |
V_36 |
V_66 , & V_26 , V_62 ) ;
if ( V_72 < 0 )
goto V_112;
if ( V_72 ) {
F_80 () ;
return F_74 ( V_109 , V_18 , V_94 , 1 ) ;
}
V_29 = F_30 ( V_18 ) ;
V_149 = V_29 -> V_7 . V_38 ;
V_130 = F_108 ( V_149 ) + sizeof( struct V_81 ) ;
V_150 = F_38 ( V_60 ) ? & V_135 : NULL ;
V_18 = F_97 ( V_18 , V_94 -> V_103 , V_130 ,
& V_131 , NULL , & V_133 ,
& V_134 , V_150 ) ;
if ( F_17 ( V_18 ) )
goto V_112;
if ( F_109 ( V_18 , F_106 ( V_126 , V_94 -> V_103 ) ) )
goto V_112;
V_18 -> V_151 = V_18 -> V_152 ;
F_110 ( V_18 , sizeof( struct V_81 ) ) ;
F_111 ( V_18 ) ;
memset ( & ( F_112 ( V_18 ) -> V_153 ) , 0 , sizeof( F_112 ( V_18 ) -> V_153 ) ) ;
V_110 = F_29 ( V_18 ) ;
V_110 -> V_154 = 4 ;
V_110 -> V_155 = sizeof( struct V_81 ) >> 2 ;
V_110 -> V_67 = V_135 ;
V_110 -> V_156 = V_131 ;
V_110 -> V_157 = V_133 ;
V_110 -> V_24 = V_94 -> V_24 . V_76 ;
V_110 -> V_26 = V_26 ;
V_110 -> V_134 = V_134 ;
F_113 ( V_23 , V_18 , NULL ) ;
V_18 -> V_113 = 1 ;
V_95 = F_63 ( V_18 , V_94 ) ;
if ( V_95 == V_96 )
F_114 ( V_23 , V_18 -> V_56 , V_18 ) ;
else if ( V_95 == V_158 )
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
V_112:
if ( ! F_17 ( V_18 ) )
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_115 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
struct V_37 * V_29 ;
struct V_83 V_26 ;
struct V_148 * V_149 ;
T_4 V_131 = 0 ;
T_5 V_132 = 0 ;
T_4 V_133 = 0 ;
T_4 V_134 = 0 ;
struct V_91 * V_110 ;
unsigned int V_130 ;
int V_95 , V_72 ;
F_77 ( 10 ) ;
F_78 () ;
V_72 = F_61 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 ,
& V_94 -> V_24 . V_90 ,
& V_26 , V_62 , 1 ,
V_44 |
V_111 |
V_66 ) ;
if ( V_72 < 0 )
goto V_112;
if ( V_72 ) {
F_80 () ;
return F_74 ( V_114 , V_18 , V_94 , 1 ) ;
}
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
V_149 = V_29 -> V_7 . V_38 ;
V_130 = F_108 ( V_149 ) + sizeof( struct V_91 ) ;
V_18 = F_97 ( V_18 , V_94 -> V_103 , V_130 ,
& V_131 , & V_132 ,
& V_133 , & V_134 , NULL ) ;
if ( F_17 ( V_18 ) )
goto V_112;
if ( F_109 ( V_18 , F_106 ( V_50 , V_94 -> V_103 ) ) )
goto V_112;
V_18 -> V_151 = V_18 -> V_152 ;
F_110 ( V_18 , sizeof( struct V_91 ) ) ;
F_111 ( V_18 ) ;
memset ( & ( F_112 ( V_18 ) -> V_153 ) , 0 , sizeof( F_112 ( V_18 ) -> V_153 ) ) ;
V_110 = F_26 ( V_18 ) ;
V_110 -> V_154 = 6 ;
V_110 -> V_159 = V_131 ;
V_110 -> V_132 = F_39 ( V_132 ) ;
memset ( & V_110 -> V_160 , 0 , sizeof( V_110 -> V_160 ) ) ;
F_116 ( V_110 , 0 , V_133 ) ;
V_110 -> V_24 = V_94 -> V_24 . V_90 ;
V_110 -> V_26 = V_26 ;
V_110 -> V_140 = V_134 ;
V_18 -> V_113 = 1 ;
V_95 = F_63 ( V_18 , V_94 ) ;
if ( V_95 == V_96 )
F_117 ( V_94 -> V_60 -> V_23 , V_18 -> V_56 , V_18 ) ;
else if ( V_95 == V_158 )
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
V_112:
if ( ! F_17 ( V_18 ) )
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_118 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
int V_72 ;
F_77 ( 10 ) ;
F_78 () ;
V_72 = F_42 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 , V_94 -> V_24 . V_76 ,
V_44 |
V_111 |
V_32 , NULL , V_62 ) ;
if ( V_72 < 0 )
goto V_112;
if ( V_72 ) {
F_80 () ;
return F_74 ( V_109 , V_18 , V_94 , 1 ) ;
}
F_79 ( F_29 ( V_18 ) ) ;
V_18 -> V_113 = 1 ;
F_74 ( V_109 , V_18 , V_94 , 0 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_119 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , struct V_61 * V_62 )
{
int V_72 ;
F_77 ( 10 ) ;
F_78 () ;
V_72 = F_61 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 ,
& V_94 -> V_24 . V_90 ,
NULL , V_62 , 0 ,
V_44 |
V_111 |
V_32 ) ;
if ( V_72 < 0 )
goto V_112;
if ( V_72 ) {
F_80 () ;
return F_74 ( V_114 , V_18 , V_94 , 1 ) ;
}
V_18 -> V_113 = 1 ;
F_74 ( V_114 , V_18 , V_94 , 0 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
F_81 ( 10 ) ;
return V_100 ;
}
int
F_120 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , int V_161 , unsigned int V_162 ,
struct V_61 * V_110 )
{
struct V_22 * V_29 ;
int V_115 ;
int V_72 ;
int V_25 , V_116 ;
F_77 ( 10 ) ;
if ( F_121 ( V_94 ) != V_163 ) {
if ( V_94 -> V_164 )
V_115 = V_94 -> V_164 ( V_18 , V_94 , V_108 , V_110 ) ;
else
V_115 = V_96 ;
F_122 ( & V_94 -> V_165 ) ;
goto V_166;
}
V_116 = F_88 ( F_30 ( V_18 ) ) ;
V_25 = ( V_162 != V_167 ) ?
V_44 | V_111 |
V_47 : V_111 ;
F_78 () ;
V_72 = F_42 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 , V_94 -> V_24 . V_76 , V_25 ,
NULL , V_110 ) ;
if ( V_72 < 0 )
goto V_112;
V_29 = F_30 ( V_18 ) ;
#if F_89 ( V_120 )
if ( V_94 -> V_39 & V_121 && V_72 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_90 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_91 ( V_125 ) ) {
F_37 ( 10 , L_20
L_21 ,
V_82 , & V_94 -> V_24 . V_76 ) ;
goto V_112;
}
}
#endif
if ( V_72 && F_28 ( V_94 -> V_24 . V_76 ) && V_116 ) {
F_37 ( 1 , L_20
L_22 ,
V_82 , & V_94 -> V_24 . V_76 ) ;
goto V_112;
}
if ( ! F_93 ( V_18 , V_161 ) )
goto V_112;
if ( F_94 ( V_18 , V_29 -> V_7 . V_38 -> V_128 ) )
goto V_112;
F_123 ( V_18 , V_108 , V_94 , 0 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_69 ( V_109 , V_18 , V_94 , V_72 ) ;
F_80 () ;
goto V_166;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
V_115 = V_100 ;
V_166:
F_81 ( 10 ) ;
return V_115 ;
}
int
F_124 ( struct V_17 * V_18 , struct V_93 * V_94 ,
struct V_107 * V_108 , int V_161 , unsigned int V_162 ,
struct V_61 * V_62 )
{
struct V_37 * V_29 ;
int V_115 ;
int V_72 ;
int V_25 ;
F_77 ( 10 ) ;
if ( F_121 ( V_94 ) != V_163 ) {
if ( V_94 -> V_164 )
V_115 = V_94 -> V_164 ( V_18 , V_94 , V_108 , V_62 ) ;
else
V_115 = V_96 ;
F_122 ( & V_94 -> V_165 ) ;
goto V_166;
}
V_25 = ( V_162 != V_167 ) ?
V_44 | V_111 |
V_47 : V_111 ;
F_78 () ;
V_72 = F_61 ( V_94 -> V_60 , V_94 -> V_103 , V_18 , V_94 -> V_5 ,
& V_94 -> V_24 . V_90 , NULL , V_62 , 0 , V_25 ) ;
if ( V_72 < 0 )
goto V_112;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_89 ( V_120 )
if ( V_94 -> V_39 & V_121 && V_72 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_90 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_91 ( V_125 ) ) {
F_37 ( 10 , L_20
L_23 ,
V_82 , & V_94 -> V_24 . V_90 ) ;
goto V_112;
}
}
#endif
if ( V_72 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_94 -> V_24 . V_90 ) & V_52 ) {
F_37 ( 1 , L_20
L_24 ,
V_82 , & V_94 -> V_24 . V_90 ) ;
goto V_112;
}
if ( ! F_93 ( V_18 , V_161 ) )
goto V_112;
if ( F_94 ( V_18 , V_29 -> V_7 . V_38 -> V_128 ) )
goto V_112;
F_125 ( V_18 , V_108 , V_94 , 0 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_69 ( V_114 , V_18 , V_94 , V_72 ) ;
F_80 () ;
goto V_166;
V_112:
F_82 ( V_18 ) ;
F_80 () ;
V_115 = V_100 ;
V_166:
F_81 ( 10 ) ;
return V_115 ;
}
