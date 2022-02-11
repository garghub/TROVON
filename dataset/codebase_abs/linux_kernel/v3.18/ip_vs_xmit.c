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
if ( ! V_18 -> V_38 && V_56 && V_56 -> V_58 != V_59 )
V_57 -> V_7 . V_15 -> V_60 ( & V_57 -> V_7 , V_56 , NULL , V_19 ) ;
}
static inline bool F_33 ( int V_41 , int V_25 ,
struct V_61 * V_62 ,
struct V_17 * V_18 , int V_19 )
{
#ifdef F_24
if ( V_41 == V_50 ) {
struct V_23 * V_23 = F_34 ( F_27 ( V_18 ) -> V_38 ) ;
if ( F_31 ( F_12 ( V_18 , V_19 ) ) ) {
if ( ! V_18 -> V_38 )
V_18 -> V_38 = V_23 -> V_63 ;
if ( ! V_62 -> V_64 )
F_35 ( V_18 , V_65 , 0 , V_19 ) ;
F_36 ( 1 , L_2 ,
& F_26 ( V_18 ) -> V_26 ) ;
return false ;
}
} else
#endif
{
struct V_66 * V_67 = F_37 ( F_38 ( V_18 ) ) ;
if ( ( V_25 & V_68 ) && ! F_39 ( V_67 ) )
return true ;
if ( F_31 ( F_29 ( V_18 ) -> V_69 & F_40 ( V_70 ) &&
V_18 -> V_21 > V_19 && ! F_14 ( V_18 ) ) ) {
F_41 ( V_18 , V_71 , V_72 ,
F_42 ( V_19 ) ) ;
F_36 ( 1 , L_3 ,
& F_29 ( V_18 ) -> V_26 ) ;
return false ;
}
}
return true ;
}
static int
F_43 ( int V_41 , struct V_17 * V_18 , struct V_4 * V_5 ,
T_2 V_24 , int V_25 , T_2 * V_73 ,
struct V_61 * V_62 )
{
struct V_23 * V_23 = F_34 ( F_27 ( V_18 ) -> V_38 ) ;
struct V_1 * V_3 ;
struct V_22 * V_29 ;
int V_19 ;
int V_74 , V_75 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_44 ( V_3 ) )
V_29 = (struct V_22 * ) V_3 -> V_11 ;
else {
V_3 = F_1 () ;
F_45 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_46 ( & V_5 -> V_10 ) ;
goto V_76;
}
V_29 = F_15 ( V_23 , V_5 -> V_77 . V_78 , V_25 ,
& V_3 -> V_79 . V_78 ) ;
if ( ! V_29 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_46 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_76;
}
F_5 ( V_5 , V_3 , & V_29 -> V_7 , 0 ) ;
F_46 ( & V_5 -> V_10 ) ;
F_36 ( 10 , L_4 ,
& V_5 -> V_77 . V_78 , & V_3 -> V_79 . V_78 ,
F_47 ( & V_29 -> V_7 . V_80 ) ) ;
}
V_24 = V_5 -> V_77 . V_78 ;
if ( V_73 )
* V_73 = V_3 -> V_79 . V_78 ;
} else {
T_2 V_26 = F_42 ( V_81 ) ;
V_75 = 0 ;
V_25 &= ~ V_31 ;
V_29 = F_15 ( V_23 , V_24 , V_25 , & V_26 ) ;
if ( ! V_29 )
goto V_76;
if ( V_73 )
* V_73 = V_26 ;
}
V_74 = ( V_29 -> V_53 & V_54 ) ? 1 : 0 ;
if ( F_31 ( F_23 ( V_41 , V_18 , V_25 ,
V_74 ) ) ) {
F_20 ( L_5
L_6 , & V_24 ) ;
goto V_82;
}
if ( F_31 ( V_74 ) ) {
if ( ! V_75 )
F_21 ( V_29 ) ;
return V_74 ;
}
if ( F_44 ( ! ( V_25 & V_68 ) ) ) {
V_19 = F_48 ( & V_29 -> V_7 ) ;
} else {
V_19 = F_48 ( & V_29 -> V_7 ) - sizeof( struct V_83 ) ;
if ( V_19 < 68 ) {
F_20 ( L_7 , V_84 ) ;
goto V_82;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_33 ( V_41 , V_25 , V_62 , V_18 , V_19 ) )
goto V_82;
F_49 ( V_18 ) ;
if ( V_75 ) {
if ( ! V_74 )
F_50 ( V_18 , & V_29 -> V_7 ) ;
else
F_51 ( V_18 , F_52 ( & V_29 -> V_7 ) ) ;
} else
F_51 ( V_18 , & V_29 -> V_7 ) ;
return V_74 ;
V_82:
if ( ! V_75 )
F_21 ( V_29 ) ;
return - 1 ;
V_76:
F_53 ( V_18 ) ;
return - 1 ;
}
static struct V_6 *
F_54 ( struct V_23 * V_23 , struct V_85 * V_24 ,
struct V_85 * V_73 , int V_86 )
{
struct V_6 * V_7 ;
struct V_87 V_88 = {
. V_24 = * V_24 ,
} ;
V_7 = F_55 ( V_23 , NULL , & V_88 ) ;
if ( V_7 -> error )
goto V_89;
if ( ! V_73 )
return V_7 ;
if ( F_56 ( & V_88 . V_26 ) &&
F_57 ( V_23 , F_58 ( V_7 ) -> V_38 ,
& V_88 . V_24 , 0 , & V_88 . V_26 ) < 0 )
goto V_89;
if ( V_86 ) {
V_7 = F_59 ( V_23 , V_7 , F_60 ( & V_88 ) , NULL , 0 ) ;
if ( F_17 ( V_7 ) ) {
V_7 = NULL ;
goto V_89;
}
}
* V_73 = V_88 . V_26 ;
return V_7 ;
V_89:
F_61 ( V_7 ) ;
F_20 ( L_8 , V_24 ) ;
return NULL ;
}
static int
F_62 ( int V_41 , struct V_17 * V_18 , struct V_4 * V_5 ,
struct V_85 * V_24 , struct V_85 * V_73 ,
struct V_61 * V_62 , int V_86 , int V_25 )
{
struct V_23 * V_23 = F_34 ( F_27 ( V_18 ) -> V_38 ) ;
struct V_1 * V_3 ;
struct V_37 * V_29 ;
struct V_6 * V_7 ;
int V_19 ;
int V_74 , V_75 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_44 ( V_3 ) )
V_29 = (struct V_37 * ) V_3 -> V_11 ;
else {
T_1 V_90 ;
V_3 = F_1 () ;
F_45 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_46 ( & V_5 -> V_10 ) ;
goto V_76;
}
V_7 = F_54 ( V_23 , & V_5 -> V_77 . V_91 ,
& V_3 -> V_79 . V_91 ,
V_86 ) ;
if ( ! V_7 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_46 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_76;
}
V_29 = (struct V_37 * ) V_7 ;
V_90 = V_29 -> V_92 ? V_29 -> V_92 -> V_93 : 0 ;
F_5 ( V_5 , V_3 , & V_29 -> V_7 , V_90 ) ;
F_46 ( & V_5 -> V_10 ) ;
F_36 ( 10 , L_9 ,
& V_5 -> V_77 . V_91 , & V_3 -> V_79 . V_91 ,
F_47 ( & V_29 -> V_7 . V_80 ) ) ;
}
if ( V_73 )
* V_73 = V_3 -> V_79 . V_91 ;
} else {
V_75 = 0 ;
V_7 = F_54 ( V_23 , V_24 , V_73 , V_86 ) ;
if ( ! V_7 )
goto V_76;
V_29 = (struct V_37 * ) V_7 ;
}
V_74 = F_22 ( V_29 ) ;
if ( F_31 ( F_23 ( V_41 , V_18 , V_25 ,
V_74 ) ) ) {
F_20 ( L_5
L_10 , V_24 ) ;
goto V_82;
}
if ( F_31 ( V_74 ) ) {
if ( ! V_75 )
F_61 ( & V_29 -> V_7 ) ;
return V_74 ;
}
if ( F_44 ( ! ( V_25 & V_68 ) ) )
V_19 = F_48 ( & V_29 -> V_7 ) ;
else {
V_19 = F_48 ( & V_29 -> V_7 ) - sizeof( struct V_94 ) ;
if ( V_19 < V_95 ) {
F_20 ( L_11 , V_84 ,
V_95 ) ;
goto V_82;
}
F_32 ( V_41 , V_18 , V_19 ) ;
}
if ( ! F_33 ( V_41 , V_25 , V_62 , V_18 , V_19 ) )
goto V_82;
F_49 ( V_18 ) ;
if ( V_75 ) {
if ( ! V_74 )
F_50 ( V_18 , & V_29 -> V_7 ) ;
else
F_51 ( V_18 , F_52 ( & V_29 -> V_7 ) ) ;
} else
F_51 ( V_18 , & V_29 -> V_7 ) ;
return V_74 ;
V_82:
if ( ! V_75 )
F_61 ( & V_29 -> V_7 ) ;
return - 1 ;
V_76:
F_53 ( V_18 ) ;
return - 1 ;
}
static inline int F_63 ( struct V_17 * V_18 ,
struct V_96 * V_97 )
{
int V_98 = V_99 ;
V_18 -> V_100 = 1 ;
if ( F_31 ( V_97 -> V_39 & V_101 ) )
V_98 = F_64 ( V_18 ) ;
if ( V_98 == V_99 ) {
F_65 ( V_18 ) ;
F_66 ( V_18 ) ;
}
return V_98 ;
}
static inline int F_67 ( int V_102 , struct V_17 * V_18 ,
struct V_96 * V_97 , int V_74 )
{
int V_98 = V_103 ;
V_18 -> V_100 = 1 ;
if ( F_44 ( ! ( V_97 -> V_39 & V_101 ) ) )
F_68 ( V_18 ) ;
else
F_69 ( V_18 , V_97 , 1 ) ;
if ( ! V_74 ) {
F_66 ( V_18 ) ;
F_70 ( V_102 , V_104 , V_18 , NULL , F_27 ( V_18 ) -> V_38 ,
V_105 ) ;
} else
V_98 = V_99 ;
return V_98 ;
}
static inline int F_71 ( int V_102 , struct V_17 * V_18 ,
struct V_96 * V_97 , int V_74 )
{
int V_98 = V_103 ;
V_18 -> V_100 = 1 ;
if ( F_44 ( ! ( V_97 -> V_39 & V_101 ) ) )
F_68 ( V_18 ) ;
if ( ! V_74 ) {
F_66 ( V_18 ) ;
F_70 ( V_102 , V_104 , V_18 , NULL , F_27 ( V_18 ) -> V_38 ,
V_105 ) ;
} else
V_98 = V_99 ;
return V_98 ;
}
int
F_72 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
return F_71 ( V_108 , V_18 , V_97 , 1 ) ;
}
int
F_73 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
struct V_83 * V_109 = F_29 ( V_18 ) ;
F_74 ( 10 ) ;
F_75 () ;
if ( F_43 ( V_97 -> V_110 , V_18 , NULL , V_109 -> V_24 ,
V_111 , NULL , V_62 ) < 0 )
goto V_112;
F_76 ( V_109 ) ;
V_18 -> V_113 = 1 ;
F_71 ( V_108 , V_18 , V_97 , 0 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_80 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
F_74 ( 10 ) ;
F_75 () ;
if ( F_62 ( V_97 -> V_110 , V_18 , NULL , & V_62 -> V_24 . V_91 , NULL ,
V_62 , 0 , V_111 ) < 0 )
goto V_112;
V_18 -> V_113 = 1 ;
F_71 ( V_114 , V_18 , V_97 , 0 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_81 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
struct V_22 * V_29 ;
int V_74 , V_115 , V_116 ;
F_74 ( 10 ) ;
F_75 () ;
if ( F_31 ( V_97 -> V_39 & V_117 ) ) {
T_3 V_118 , * V_119 ;
V_119 = F_82 ( V_18 , V_62 -> V_21 , sizeof( V_118 ) , & V_118 ) ;
if ( V_119 == NULL )
goto V_112;
F_83 ( V_97 , * V_119 ) ;
F_36 ( 10 , L_12 , F_84 ( * V_119 ) ) ;
}
V_116 = F_85 ( F_30 ( V_18 ) ) ;
V_74 = F_43 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , V_97 -> V_24 . V_78 ,
V_44 |
V_111 |
V_47 , NULL , V_62 ) ;
if ( V_74 < 0 )
goto V_112;
V_29 = F_30 ( V_18 ) ;
#if F_86 ( V_120 )
if ( V_97 -> V_39 & V_121 && V_74 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_87 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_88 ( V_125 ) ) {
F_89 ( 10 , V_126 , V_107 , V_18 , 0 ,
L_13
L_14 ) ;
goto V_112;
}
}
#endif
if ( V_74 && F_28 ( V_97 -> V_24 . V_78 ) && V_116 ) {
F_89 ( 1 , V_126 , V_107 , V_18 , 0 , L_13
L_15 ) ;
goto V_112;
}
if ( ! F_90 ( V_18 , sizeof( struct V_83 ) ) )
goto V_112;
if ( F_91 ( V_18 , V_29 -> V_7 . V_38 -> V_127 ) )
goto V_112;
if ( V_107 -> V_128 && ! V_107 -> V_128 ( V_18 , V_107 , V_97 , V_62 ) )
goto V_112;
F_29 ( V_18 ) -> V_24 = V_97 -> V_24 . V_78 ;
F_76 ( F_29 ( V_18 ) ) ;
F_92 ( 10 , V_126 , V_107 , V_18 , 0 , L_16 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_67 ( V_108 , V_18 , V_97 , V_74 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_115 ;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_93 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
struct V_37 * V_29 ;
int V_74 , V_115 ;
F_74 ( 10 ) ;
F_75 () ;
if ( F_31 ( V_97 -> V_39 & V_117 && ! V_62 -> V_64 ) ) {
T_3 V_118 , * V_119 ;
V_119 = F_82 ( V_18 , V_62 -> V_21 , sizeof( V_118 ) , & V_118 ) ;
if ( V_119 == NULL )
goto V_112;
F_83 ( V_97 , * V_119 ) ;
F_36 ( 10 , L_12 , F_84 ( * V_119 ) ) ;
}
V_74 = F_62 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , & V_97 -> V_24 . V_91 ,
NULL , V_62 , 0 ,
V_44 |
V_111 |
V_47 ) ;
if ( V_74 < 0 )
goto V_112;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_86 ( V_120 )
if ( V_97 -> V_39 & V_121 && V_74 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_87 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_88 ( V_125 ) ) {
F_89 ( 10 , V_50 , V_107 , V_18 , 0 ,
L_17
L_14 ) ;
goto V_112;
}
}
#endif
if ( V_74 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_29 -> V_129 . V_77 ) & V_52 ) {
F_89 ( 1 , V_50 , V_107 , V_18 , 0 ,
L_17
L_15 ) ;
goto V_112;
}
if ( ! F_90 ( V_18 , sizeof( struct V_94 ) ) )
goto V_112;
if ( F_91 ( V_18 , V_29 -> V_7 . V_38 -> V_127 ) )
goto V_112;
if ( V_107 -> V_128 && ! V_107 -> V_128 ( V_18 , V_107 , V_97 , V_62 ) )
goto V_112;
F_26 ( V_18 ) -> V_24 = V_97 -> V_24 . V_91 ;
F_92 ( 10 , V_50 , V_107 , V_18 , 0 , L_16 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_67 ( V_114 , V_18 , V_97 , V_74 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_115 ;
V_112:
F_78 ( 10 ) ;
F_79 ( V_18 ) ;
F_77 () ;
return V_103 ;
}
static struct V_17 *
F_94 ( struct V_17 * V_18 , int V_41 ,
unsigned int V_130 , T_4 * V_131 ,
T_5 * V_132 , T_4 * V_133 , T_4 * V_134 ,
T_3 * V_135 )
{
struct V_17 * V_136 = NULL ;
struct V_83 * V_137 = NULL ;
#ifdef F_24
struct V_94 * V_138 = NULL ;
#endif
if ( F_95 ( V_18 ) < V_130 || F_96 ( V_18 ) ) {
V_136 = F_97 ( V_18 , V_130 ) ;
if ( ! V_136 )
goto error;
if ( V_18 -> V_56 )
F_98 ( V_136 , V_18 -> V_56 ) ;
F_99 ( V_18 ) ;
V_18 = V_136 ;
}
#ifdef F_24
if ( V_41 == V_50 ) {
V_138 = F_26 ( V_18 ) ;
* V_131 = V_139 ;
if ( V_132 )
* V_132 =
F_84 ( V_138 -> V_132 ) +
sizeof( * V_138 ) ;
* V_133 = F_100 ( V_138 ) ;
* V_134 = V_138 -> V_140 ;
if ( V_135 )
* V_135 = 0 ;
} else
#endif
{
V_137 = F_29 ( V_18 ) ;
if ( V_135 )
* V_135 = ( V_137 -> V_69 & F_40 ( V_70 ) ) ;
* V_131 = V_141 ;
F_76 ( V_137 ) ;
* V_133 = F_101 ( V_137 ) ;
* V_134 = V_137 -> V_134 ;
if ( V_132 )
* V_132 = F_84 ( V_137 -> V_142 ) ;
}
return V_18 ;
error:
F_79 ( V_18 ) ;
return F_102 ( - V_143 ) ;
}
static inline int F_103 ( int V_144 , int V_145 )
{
if ( V_144 == V_126 ) {
if ( V_145 == V_126 )
return V_146 ;
return V_147 ;
}
return 0 ;
}
int
F_104 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
struct V_66 * V_67 = F_37 ( F_38 ( V_18 ) ) ;
struct V_22 * V_29 ;
T_2 V_26 ;
struct V_148 * V_149 ;
T_4 V_131 = 0 ;
T_4 V_133 = 0 ;
T_4 V_134 = 0 ;
T_3 V_135 = 0 ;
T_3 * V_150 = NULL ;
struct V_83 * V_109 ;
unsigned int V_130 ;
int V_98 , V_74 ;
F_74 ( 10 ) ;
F_75 () ;
V_74 = F_43 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , V_97 -> V_24 . V_78 ,
V_44 |
V_111 |
V_31 |
V_68 , & V_26 , V_62 ) ;
if ( V_74 < 0 )
goto V_112;
if ( V_74 ) {
F_77 () ;
return F_71 ( V_108 , V_18 , V_97 , 1 ) ;
}
V_29 = F_30 ( V_18 ) ;
V_149 = V_29 -> V_7 . V_38 ;
V_130 = F_105 ( V_149 ) + sizeof( struct V_83 ) ;
V_150 = F_39 ( V_67 ) ? & V_135 : NULL ;
V_18 = F_94 ( V_18 , V_97 -> V_110 , V_130 ,
& V_131 , NULL , & V_133 ,
& V_134 , V_150 ) ;
if ( F_17 ( V_18 ) )
goto V_112;
V_18 = F_106 (
V_18 , false , F_103 ( V_126 , V_97 -> V_110 ) ) ;
if ( F_17 ( V_18 ) )
goto V_112;
V_18 -> V_151 = V_18 -> V_152 ;
F_107 ( V_18 , sizeof( struct V_83 ) ) ;
F_108 ( V_18 ) ;
memset ( & ( F_109 ( V_18 ) -> V_153 ) , 0 , sizeof( F_109 ( V_18 ) -> V_153 ) ) ;
V_109 = F_29 ( V_18 ) ;
V_109 -> V_154 = 4 ;
V_109 -> V_155 = sizeof( struct V_83 ) >> 2 ;
V_109 -> V_69 = V_135 ;
V_109 -> V_156 = V_131 ;
V_109 -> V_157 = V_133 ;
V_109 -> V_24 = V_97 -> V_24 . V_78 ;
V_109 -> V_26 = V_26 ;
V_109 -> V_134 = V_134 ;
F_110 ( V_18 , NULL ) ;
V_18 -> V_113 = 1 ;
V_98 = F_63 ( V_18 , V_97 ) ;
if ( V_98 == V_99 )
F_111 ( V_18 ) ;
else if ( V_98 == V_158 )
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
V_112:
if ( ! F_17 ( V_18 ) )
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_112 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
struct V_37 * V_29 ;
struct V_85 V_26 ;
struct V_148 * V_149 ;
T_4 V_131 = 0 ;
T_5 V_132 = 0 ;
T_4 V_133 = 0 ;
T_4 V_134 = 0 ;
struct V_94 * V_109 ;
unsigned int V_130 ;
int V_98 , V_74 ;
F_74 ( 10 ) ;
F_75 () ;
V_74 = F_62 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , & V_97 -> V_24 . V_91 ,
& V_26 , V_62 , 1 ,
V_44 |
V_111 |
V_68 ) ;
if ( V_74 < 0 )
goto V_112;
if ( V_74 ) {
F_77 () ;
return F_71 ( V_114 , V_18 , V_97 , 1 ) ;
}
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
V_149 = V_29 -> V_7 . V_38 ;
V_130 = F_105 ( V_149 ) + sizeof( struct V_94 ) ;
V_18 = F_94 ( V_18 , V_97 -> V_110 , V_130 ,
& V_131 , & V_132 ,
& V_133 , & V_134 , NULL ) ;
if ( F_17 ( V_18 ) )
goto V_112;
V_18 = F_106 (
V_18 , false , F_103 ( V_50 , V_97 -> V_110 ) ) ;
if ( F_17 ( V_18 ) )
goto V_112;
V_18 -> V_151 = V_18 -> V_152 ;
F_107 ( V_18 , sizeof( struct V_94 ) ) ;
F_108 ( V_18 ) ;
memset ( & ( F_109 ( V_18 ) -> V_153 ) , 0 , sizeof( F_109 ( V_18 ) -> V_153 ) ) ;
V_109 = F_26 ( V_18 ) ;
V_109 -> V_154 = 6 ;
V_109 -> V_159 = V_131 ;
V_109 -> V_132 = F_40 ( V_132 ) ;
memset ( & V_109 -> V_160 , 0 , sizeof( V_109 -> V_160 ) ) ;
F_113 ( V_109 , 0 , V_133 ) ;
V_109 -> V_24 = V_97 -> V_24 . V_91 ;
V_109 -> V_26 = V_26 ;
V_109 -> V_140 = V_134 ;
V_18 -> V_113 = 1 ;
V_98 = F_63 ( V_18 , V_97 ) ;
if ( V_98 == V_99 )
F_114 ( V_18 ) ;
else if ( V_98 == V_158 )
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
V_112:
if ( ! F_17 ( V_18 ) )
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_115 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
int V_74 ;
F_74 ( 10 ) ;
F_75 () ;
V_74 = F_43 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , V_97 -> V_24 . V_78 ,
V_44 |
V_111 |
V_33 , NULL , V_62 ) ;
if ( V_74 < 0 )
goto V_112;
if ( V_74 ) {
F_77 () ;
return F_71 ( V_108 , V_18 , V_97 , 1 ) ;
}
F_76 ( F_29 ( V_18 ) ) ;
V_18 -> V_113 = 1 ;
F_71 ( V_108 , V_18 , V_97 , 0 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_116 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , struct V_61 * V_62 )
{
int V_74 ;
F_74 ( 10 ) ;
F_75 () ;
V_74 = F_62 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , & V_97 -> V_24 . V_91 ,
NULL , V_62 , 0 ,
V_44 |
V_111 ) ;
if ( V_74 < 0 )
goto V_112;
if ( V_74 ) {
F_77 () ;
return F_71 ( V_114 , V_18 , V_97 , 1 ) ;
}
V_18 -> V_113 = 1 ;
F_71 ( V_114 , V_18 , V_97 , 0 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
F_78 ( 10 ) ;
return V_103 ;
}
int
F_117 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , int V_161 , unsigned int V_162 ,
struct V_61 * V_109 )
{
struct V_22 * V_29 ;
int V_115 ;
int V_74 ;
int V_25 , V_116 ;
F_74 ( 10 ) ;
if ( F_118 ( V_97 ) != V_163 ) {
if ( V_97 -> V_164 )
V_115 = V_97 -> V_164 ( V_18 , V_97 , V_107 , V_109 ) ;
else
V_115 = V_99 ;
F_119 ( & V_97 -> V_165 ) ;
goto V_166;
}
V_116 = F_85 ( F_30 ( V_18 ) ) ;
V_25 = ( V_162 != V_167 ) ?
V_44 | V_111 |
V_47 : V_111 ;
F_75 () ;
V_74 = F_43 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , V_97 -> V_24 . V_78 , V_25 ,
NULL , V_109 ) ;
if ( V_74 < 0 )
goto V_112;
V_29 = F_30 ( V_18 ) ;
#if F_86 ( V_120 )
if ( V_97 -> V_39 & V_121 && V_74 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_87 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_88 ( V_125 ) ) {
F_36 ( 10 , L_18
L_19 ,
V_84 , & V_97 -> V_24 . V_78 ) ;
goto V_112;
}
}
#endif
if ( V_74 && F_28 ( V_97 -> V_24 . V_78 ) && V_116 ) {
F_36 ( 1 , L_18
L_20 ,
V_84 , & V_97 -> V_24 . V_78 ) ;
goto V_112;
}
if ( ! F_90 ( V_18 , V_161 ) )
goto V_112;
if ( F_91 ( V_18 , V_29 -> V_7 . V_38 -> V_127 ) )
goto V_112;
F_120 ( V_18 , V_107 , V_97 , 0 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_67 ( V_108 , V_18 , V_97 , V_74 ) ;
F_77 () ;
goto V_166;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
V_115 = V_103 ;
V_166:
F_78 ( 10 ) ;
return V_115 ;
}
int
F_121 ( struct V_17 * V_18 , struct V_96 * V_97 ,
struct V_106 * V_107 , int V_161 , unsigned int V_162 ,
struct V_61 * V_62 )
{
struct V_37 * V_29 ;
int V_115 ;
int V_74 ;
int V_25 ;
F_74 ( 10 ) ;
if ( F_118 ( V_97 ) != V_163 ) {
if ( V_97 -> V_164 )
V_115 = V_97 -> V_164 ( V_18 , V_97 , V_107 , V_62 ) ;
else
V_115 = V_99 ;
F_119 ( & V_97 -> V_165 ) ;
goto V_166;
}
V_25 = ( V_162 != V_167 ) ?
V_44 | V_111 |
V_47 : V_111 ;
F_75 () ;
V_74 = F_62 ( V_97 -> V_110 , V_18 , V_97 -> V_5 , & V_97 -> V_24 . V_91 ,
NULL , V_62 , 0 , V_25 ) ;
if ( V_74 < 0 )
goto V_112;
V_29 = (struct V_37 * ) F_27 ( V_18 ) ;
#if F_86 ( V_120 )
if ( V_97 -> V_39 & V_121 && V_74 ) {
enum V_122 V_123 ;
struct V_124 * V_125 = F_87 ( V_18 , & V_123 ) ;
if ( V_125 && ! F_88 ( V_125 ) ) {
F_36 ( 10 , L_18
L_21 ,
V_84 , & V_97 -> V_24 . V_91 ) ;
goto V_112;
}
}
#endif
if ( V_74 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_39 & V_40 ) &&
F_25 ( & V_29 -> V_129 . V_77 ) & V_52 ) {
F_36 ( 1 , L_18
L_22 ,
V_84 , & V_97 -> V_24 . V_91 ) ;
goto V_112;
}
if ( ! F_90 ( V_18 , V_161 ) )
goto V_112;
if ( F_91 ( V_18 , V_29 -> V_7 . V_38 -> V_127 ) )
goto V_112;
F_122 ( V_18 , V_107 , V_97 , 0 ) ;
V_18 -> V_113 = 1 ;
V_115 = F_67 ( V_114 , V_18 , V_97 , V_74 ) ;
F_77 () ;
goto V_166;
V_112:
F_79 ( V_18 ) ;
F_77 () ;
V_115 = V_103 ;
V_166:
F_78 ( 10 ) ;
return V_115 ;
}
