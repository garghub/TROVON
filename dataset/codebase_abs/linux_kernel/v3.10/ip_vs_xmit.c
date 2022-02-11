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
static int
F_22 ( struct V_17 * V_18 , struct V_4 * V_5 ,
T_2 V_24 , int V_25 , T_2 * V_37 )
{
struct V_23 * V_23 = F_23 ( F_24 ( V_18 ) -> V_38 ) ;
struct V_39 * V_40 = F_25 ( V_23 ) ;
struct V_1 * V_3 ;
struct V_22 * V_29 ;
struct V_22 * V_41 ;
struct V_42 * V_43 ;
T_3 V_44 ;
int V_19 ;
int V_45 , V_46 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_26 ( V_3 ) )
V_29 = (struct V_22 * ) V_3 -> V_11 ;
else {
V_3 = F_1 () ;
F_27 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_28 ( & V_5 -> V_10 ) ;
goto V_47;
}
V_29 = F_15 ( V_23 , V_5 -> V_48 . V_49 , V_25 ,
& V_3 -> V_50 . V_49 ) ;
if ( ! V_29 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_28 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_47;
}
F_5 ( V_5 , V_3 , & V_29 -> V_7 , 0 ) ;
F_28 ( & V_5 -> V_10 ) ;
F_29 ( 10 , L_2 ,
& V_5 -> V_48 . V_49 , & V_3 -> V_50 . V_49 ,
F_30 ( & V_29 -> V_7 . V_51 ) ) ;
}
V_24 = V_5 -> V_48 . V_49 ;
if ( V_37 )
* V_37 = V_3 -> V_50 . V_49 ;
} else {
T_2 V_26 = F_31 ( V_52 ) ;
V_46 = 0 ;
V_25 &= ~ V_31 ;
V_29 = F_15 ( V_23 , V_24 , V_25 , & V_26 ) ;
if ( ! V_29 )
goto V_47;
if ( V_37 )
* V_37 = V_26 ;
}
V_45 = ( V_29 -> V_53 & V_54 ) ? 1 : 0 ;
if ( ! ( ( V_45 ? V_55 : V_56 ) &
V_25 ) ) {
F_20 ( L_3 ,
( V_29 -> V_53 & V_54 ) ?
L_4 : L_5 , & V_24 ) ;
goto V_57;
}
V_43 = F_32 ( V_18 ) ;
if ( F_26 ( ! V_45 ) ) {
if ( F_33 ( F_34 ( V_43 -> V_26 ) ) ) {
F_20 ( L_6
L_7 ,
& V_43 -> V_26 , & V_24 ) ;
goto V_57;
}
} else {
V_41 = F_35 ( V_18 ) ;
if ( ! ( V_25 & V_58 ) &&
! ( V_41 -> V_53 & V_54 ) ) {
F_20 ( L_8
L_9 ,
& V_43 -> V_24 , & V_24 ) ;
goto V_57;
}
if ( ! V_46 )
F_21 ( V_29 ) ;
return V_45 ;
}
if ( F_26 ( ! ( V_25 & V_59 ) ) ) {
V_19 = F_36 ( & V_29 -> V_7 ) ;
V_44 = V_43 -> V_60 & F_37 ( V_61 ) ;
} else {
struct V_62 * V_63 = V_18 -> V_63 ;
V_19 = F_36 ( & V_29 -> V_7 ) - sizeof( struct V_42 ) ;
if ( V_19 < 68 ) {
F_20 ( L_10 , V_64 ) ;
goto V_57;
}
V_41 = F_35 ( V_18 ) ;
if ( ! V_18 -> V_38 && V_63 && V_63 -> V_65 != V_66 )
V_41 -> V_7 . V_15 -> V_67 ( & V_41 -> V_7 , V_63 , NULL , V_19 ) ;
V_44 = F_38 ( V_40 ) ? V_43 -> V_60 & F_37 ( V_61 ) : 0 ;
}
if ( F_33 ( V_44 && V_18 -> V_21 > V_19 && ! F_14 ( V_18 ) ) ) {
F_39 ( V_18 , V_68 , V_69 , F_31 ( V_19 ) ) ;
F_29 ( 1 , L_11 , & V_43 -> V_26 ) ;
goto V_57;
}
F_40 ( V_18 ) ;
if ( V_46 ) {
if ( ! V_45 )
F_41 ( V_18 , & V_29 -> V_7 ) ;
else
F_42 ( V_18 , F_43 ( & V_29 -> V_7 ) ) ;
} else
F_42 ( V_18 , & V_29 -> V_7 ) ;
return V_45 ;
V_57:
if ( ! V_46 )
F_21 ( V_29 ) ;
return - 1 ;
V_47:
F_44 ( V_18 ) ;
return - 1 ;
}
static inline int F_45 ( struct V_70 * V_29 )
{
return V_29 -> V_7 . V_38 && V_29 -> V_7 . V_38 -> V_71 & V_72 ;
}
static struct V_6 *
F_46 ( struct V_23 * V_23 , struct V_73 * V_24 ,
struct V_73 * V_37 , int V_74 )
{
struct V_6 * V_7 ;
struct V_75 V_76 = {
. V_24 = * V_24 ,
} ;
V_7 = F_47 ( V_23 , NULL , & V_76 ) ;
if ( V_7 -> error )
goto V_77;
if ( ! V_37 )
return V_7 ;
if ( F_48 ( & V_76 . V_26 ) &&
F_49 ( V_23 , F_50 ( V_7 ) -> V_38 ,
& V_76 . V_24 , 0 , & V_76 . V_26 ) < 0 )
goto V_77;
if ( V_74 ) {
V_7 = F_51 ( V_23 , V_7 , F_52 ( & V_76 ) , NULL , 0 ) ;
if ( F_17 ( V_7 ) ) {
V_7 = NULL ;
goto V_77;
}
}
* V_37 = V_76 . V_26 ;
return V_7 ;
V_77:
F_53 ( V_7 ) ;
F_20 ( L_12 , V_24 ) ;
return NULL ;
}
static int
F_54 ( struct V_17 * V_18 , struct V_4 * V_5 ,
struct V_73 * V_24 , struct V_73 * V_37 ,
struct V_78 * V_79 , int V_74 , int V_25 )
{
struct V_23 * V_23 = F_23 ( F_24 ( V_18 ) -> V_38 ) ;
struct V_1 * V_3 ;
struct V_70 * V_29 ;
struct V_70 * V_41 ;
struct V_6 * V_7 ;
int V_19 ;
int V_45 , V_46 = 1 ;
if ( V_5 ) {
V_3 = F_10 ( V_5 ) ;
if ( F_26 ( V_3 ) )
V_29 = (struct V_70 * ) V_3 -> V_11 ;
else {
T_1 V_80 ;
V_3 = F_1 () ;
F_27 ( & V_5 -> V_10 ) ;
if ( ! V_3 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_28 ( & V_5 -> V_10 ) ;
goto V_47;
}
V_7 = F_46 ( V_23 , & V_5 -> V_48 . V_81 ,
& V_3 -> V_50 . V_81 ,
V_74 ) ;
if ( ! V_7 ) {
F_5 ( V_5 , NULL , NULL , 0 ) ;
F_28 ( & V_5 -> V_10 ) ;
F_3 ( V_3 ) ;
goto V_47;
}
V_29 = (struct V_70 * ) V_7 ;
V_80 = V_29 -> V_82 ? V_29 -> V_82 -> V_83 : 0 ;
F_5 ( V_5 , V_3 , & V_29 -> V_7 , V_80 ) ;
F_28 ( & V_5 -> V_10 ) ;
F_29 ( 10 , L_13 ,
& V_5 -> V_48 . V_81 , & V_3 -> V_50 . V_81 ,
F_30 ( & V_29 -> V_7 . V_51 ) ) ;
}
if ( V_37 )
* V_37 = V_3 -> V_50 . V_81 ;
} else {
V_46 = 0 ;
V_7 = F_46 ( V_23 , V_24 , V_37 , V_74 ) ;
if ( ! V_7 )
goto V_47;
V_29 = (struct V_70 * ) V_7 ;
}
V_45 = F_45 ( V_29 ) ;
if ( ! ( ( V_45 ? V_55 : V_56 ) &
V_25 ) ) {
F_20 ( L_14 ,
V_45 ? L_4 : L_5 , V_24 ) ;
goto V_57;
}
if ( F_26 ( ! V_45 ) ) {
if ( F_33 ( ( ! V_18 -> V_38 || V_18 -> V_38 -> V_71 & V_72 ) &&
F_55 ( & F_56 ( V_18 ) -> V_26 ) &
V_84 ) ) {
F_20 ( L_6
L_15
L_16 ,
& F_56 ( V_18 ) -> V_26 , V_24 ) ;
goto V_57;
}
} else {
V_41 = (struct V_70 * ) F_24 ( V_18 ) ;
if ( ! ( V_25 & V_58 ) &&
! F_45 ( V_41 ) ) {
F_20 ( L_17
L_18
L_16 ,
& F_56 ( V_18 ) -> V_24 , V_24 ) ;
goto V_57;
}
if ( ! V_46 )
F_53 ( & V_29 -> V_7 ) ;
return V_45 ;
}
if ( F_26 ( ! ( V_25 & V_59 ) ) )
V_19 = F_36 ( & V_29 -> V_7 ) ;
else {
struct V_62 * V_63 = V_18 -> V_63 ;
V_19 = F_36 ( & V_29 -> V_7 ) - sizeof( struct V_85 ) ;
if ( V_19 < V_86 ) {
F_20 ( L_19 , V_64 ,
V_86 ) ;
goto V_57;
}
V_41 = (struct V_70 * ) F_24 ( V_18 ) ;
if ( ! V_18 -> V_38 && V_63 && V_63 -> V_65 != V_66 )
V_41 -> V_7 . V_15 -> V_67 ( & V_41 -> V_7 , V_63 , NULL , V_19 ) ;
}
if ( F_33 ( F_12 ( V_18 , V_19 ) ) ) {
if ( ! V_18 -> V_38 )
V_18 -> V_38 = V_23 -> V_87 ;
if ( ! V_79 -> V_88 )
F_57 ( V_18 , V_89 , 0 , V_19 ) ;
F_29 ( 1 , L_20 , & F_56 ( V_18 ) -> V_26 ) ;
goto V_57;
}
F_40 ( V_18 ) ;
if ( V_46 ) {
if ( ! V_45 )
F_41 ( V_18 , & V_29 -> V_7 ) ;
else
F_42 ( V_18 , F_43 ( & V_29 -> V_7 ) ) ;
} else
F_42 ( V_18 , & V_29 -> V_7 ) ;
return V_45 ;
V_57:
if ( ! V_46 )
F_53 ( & V_29 -> V_7 ) ;
return - 1 ;
V_47:
F_44 ( V_18 ) ;
return - 1 ;
}
static inline int F_58 ( struct V_17 * V_18 ,
struct V_90 * V_91 )
{
int V_92 = V_93 ;
V_18 -> V_94 = 1 ;
if ( F_33 ( V_91 -> V_71 & V_95 ) )
V_92 = F_59 ( V_18 ) ;
if ( V_92 == V_93 ) {
F_60 ( V_18 ) ;
F_61 ( V_18 ) ;
}
return V_92 ;
}
static inline int F_62 ( int V_96 , struct V_17 * V_18 ,
struct V_90 * V_91 , int V_45 )
{
int V_92 = V_97 ;
V_18 -> V_94 = 1 ;
if ( F_26 ( ! ( V_91 -> V_71 & V_95 ) ) )
F_63 ( V_18 ) ;
else
F_64 ( V_18 , V_91 , 1 ) ;
if ( ! V_45 ) {
F_61 ( V_18 ) ;
F_65 ( V_96 , V_98 , V_18 , NULL , F_24 ( V_18 ) -> V_38 ,
V_99 ) ;
} else
V_92 = V_93 ;
return V_92 ;
}
static inline int F_66 ( int V_96 , struct V_17 * V_18 ,
struct V_90 * V_91 , int V_45 )
{
int V_92 = V_97 ;
V_18 -> V_94 = 1 ;
if ( F_26 ( ! ( V_91 -> V_71 & V_95 ) ) )
F_63 ( V_18 ) ;
if ( ! V_45 ) {
F_61 ( V_18 ) ;
F_65 ( V_96 , V_98 , V_18 , NULL , F_24 ( V_18 ) -> V_38 ,
V_99 ) ;
} else
V_92 = V_93 ;
return V_92 ;
}
int
F_67 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
return F_66 ( V_102 , V_18 , V_91 , 1 ) ;
}
int
F_68 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
struct V_42 * V_43 = F_32 ( V_18 ) ;
F_69 ( 10 ) ;
F_70 () ;
if ( F_22 ( V_18 , NULL , V_43 -> V_24 , V_56 ,
NULL ) < 0 )
goto V_103;
F_71 ( V_43 ) ;
V_18 -> V_104 = 1 ;
F_66 ( V_102 , V_18 , V_91 , 0 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_75 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
F_69 ( 10 ) ;
F_70 () ;
if ( F_54 ( V_18 , NULL , & V_79 -> V_24 . V_81 , NULL ,
V_79 , 0 , V_56 ) < 0 )
goto V_103;
V_18 -> V_104 = 1 ;
F_66 ( V_105 , V_18 , V_91 , 0 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_76 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
struct V_22 * V_29 ;
int V_45 , V_106 , V_107 ;
F_69 ( 10 ) ;
F_70 () ;
if ( F_33 ( V_91 -> V_71 & V_108 ) ) {
T_3 V_109 , * V_110 ;
V_110 = F_77 ( V_18 , V_79 -> V_21 , sizeof( V_109 ) , & V_109 ) ;
if ( V_110 == NULL )
goto V_103;
F_78 ( V_91 , * V_110 ) ;
F_29 ( 10 , L_21 , F_79 ( * V_110 ) ) ;
}
V_107 = F_80 ( F_35 ( V_18 ) ) ;
V_45 = F_22 ( V_18 , V_91 -> V_5 , V_91 -> V_24 . V_49 ,
V_55 |
V_56 |
V_58 , NULL ) ;
if ( V_45 < 0 )
goto V_103;
V_29 = F_35 ( V_18 ) ;
#if F_81 ( V_111 )
if ( V_91 -> V_71 & V_112 && V_45 ) {
enum V_113 V_114 ;
struct V_115 * V_116 = F_82 ( V_18 , & V_114 ) ;
if ( V_116 && ! F_83 ( V_116 ) ) {
F_84 ( 10 , V_117 , V_101 , V_18 , 0 ,
L_22
L_23 ) ;
goto V_103;
}
}
#endif
if ( V_45 && F_34 ( V_91 -> V_24 . V_49 ) && V_107 ) {
F_84 ( 1 , V_117 , V_101 , V_18 , 0 , L_22
L_24 ) ;
goto V_103;
}
if ( ! F_85 ( V_18 , sizeof( struct V_42 ) ) )
goto V_103;
if ( F_86 ( V_18 , V_29 -> V_7 . V_38 -> V_118 ) )
goto V_103;
if ( V_101 -> V_119 && ! V_101 -> V_119 ( V_18 , V_101 , V_91 , V_79 ) )
goto V_103;
F_32 ( V_18 ) -> V_24 = V_91 -> V_24 . V_49 ;
F_71 ( F_32 ( V_18 ) ) ;
F_87 ( 10 , V_117 , V_101 , V_18 , 0 , L_25 ) ;
V_18 -> V_104 = 1 ;
V_106 = F_62 ( V_102 , V_18 , V_91 , V_45 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_106 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_88 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
struct V_70 * V_29 ;
int V_45 , V_106 ;
F_69 ( 10 ) ;
F_70 () ;
if ( F_33 ( V_91 -> V_71 & V_108 && ! V_79 -> V_88 ) ) {
T_3 V_109 , * V_110 ;
V_110 = F_77 ( V_18 , V_79 -> V_21 , sizeof( V_109 ) , & V_109 ) ;
if ( V_110 == NULL )
goto V_103;
F_78 ( V_91 , * V_110 ) ;
F_29 ( 10 , L_21 , F_79 ( * V_110 ) ) ;
}
V_45 = F_54 ( V_18 , V_91 -> V_5 , & V_91 -> V_24 . V_81 , NULL ,
V_79 , 0 ,
V_55 |
V_56 |
V_58 ) ;
if ( V_45 < 0 )
goto V_103;
V_29 = (struct V_70 * ) F_24 ( V_18 ) ;
#if F_81 ( V_111 )
if ( V_91 -> V_71 & V_112 && V_45 ) {
enum V_113 V_114 ;
struct V_115 * V_116 = F_82 ( V_18 , & V_114 ) ;
if ( V_116 && ! F_83 ( V_116 ) ) {
F_84 ( 10 , V_120 , V_101 , V_18 , 0 ,
L_26
L_23 ) ;
goto V_103;
}
}
#endif
if ( V_45 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_71 & V_72 ) &&
F_55 ( & V_29 -> V_121 . V_48 ) & V_84 ) {
F_84 ( 1 , V_120 , V_101 , V_18 , 0 ,
L_26
L_24 ) ;
goto V_103;
}
if ( ! F_85 ( V_18 , sizeof( struct V_85 ) ) )
goto V_103;
if ( F_86 ( V_18 , V_29 -> V_7 . V_38 -> V_118 ) )
goto V_103;
if ( V_101 -> V_119 && ! V_101 -> V_119 ( V_18 , V_101 , V_91 , V_79 ) )
goto V_103;
F_56 ( V_18 ) -> V_24 = V_91 -> V_24 . V_81 ;
F_87 ( 10 , V_120 , V_101 , V_18 , 0 , L_25 ) ;
V_18 -> V_104 = 1 ;
V_106 = F_62 ( V_105 , V_18 , V_91 , V_45 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_106 ;
V_103:
F_73 ( 10 ) ;
F_74 ( V_18 ) ;
F_72 () ;
return V_97 ;
}
int
F_89 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
struct V_39 * V_40 = F_25 ( F_90 ( V_18 ) ) ;
struct V_22 * V_29 ;
T_2 V_26 ;
struct V_122 * V_123 ;
struct V_42 * V_124 = F_32 ( V_18 ) ;
T_4 V_125 = V_124 -> V_125 ;
T_3 V_44 ;
struct V_42 * V_43 ;
unsigned int V_126 ;
int V_92 , V_45 ;
F_69 ( 10 ) ;
F_70 () ;
V_45 = F_22 ( V_18 , V_91 -> V_5 , V_91 -> V_24 . V_49 ,
V_55 |
V_56 |
V_31 |
V_59 , & V_26 ) ;
if ( V_45 < 0 )
goto V_103;
if ( V_45 ) {
F_72 () ;
return F_66 ( V_102 , V_18 , V_91 , 1 ) ;
}
V_29 = F_35 ( V_18 ) ;
V_123 = V_29 -> V_7 . V_38 ;
V_44 = F_38 ( V_40 ) ? V_124 -> V_60 & F_37 ( V_61 ) : 0 ;
V_126 = F_91 ( V_123 ) + sizeof( struct V_42 ) ;
if ( F_92 ( V_18 ) < V_126 || F_93 ( V_18 ) ) {
struct V_17 * V_127 =
F_94 ( V_18 , V_126 ) ;
if ( ! V_127 )
goto V_103;
F_95 ( V_18 ) ;
V_18 = V_127 ;
V_124 = F_32 ( V_18 ) ;
}
V_18 -> V_128 = V_18 -> V_129 ;
F_71 ( V_124 ) ;
F_96 ( V_18 , sizeof( struct V_42 ) ) ;
F_97 ( V_18 ) ;
memset ( & ( F_98 ( V_18 ) -> V_130 ) , 0 , sizeof( F_98 ( V_18 ) -> V_130 ) ) ;
V_43 = F_32 ( V_18 ) ;
V_43 -> V_131 = 4 ;
V_43 -> V_132 = sizeof( struct V_42 ) >> 2 ;
V_43 -> V_60 = V_44 ;
V_43 -> V_133 = V_134 ;
V_43 -> V_125 = V_125 ;
V_43 -> V_24 = V_91 -> V_24 . V_49 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_135 = V_124 -> V_135 ;
F_99 ( V_43 , & V_29 -> V_7 , NULL ) ;
V_18 -> V_104 = 1 ;
V_92 = F_58 ( V_18 , V_91 ) ;
if ( V_92 == V_93 )
F_100 ( V_18 ) ;
else if ( V_92 == V_136 )
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_101 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
struct V_70 * V_29 ;
struct V_73 V_26 ;
struct V_122 * V_123 ;
struct V_85 * V_124 = F_56 ( V_18 ) ;
struct V_85 * V_43 ;
unsigned int V_126 ;
int V_92 , V_45 ;
F_69 ( 10 ) ;
F_70 () ;
V_45 = F_54 ( V_18 , V_91 -> V_5 , & V_91 -> V_24 . V_81 ,
& V_26 , V_79 , 1 ,
V_55 |
V_56 |
V_59 ) ;
if ( V_45 < 0 )
goto V_103;
if ( V_45 ) {
F_72 () ;
return F_66 ( V_105 , V_18 , V_91 , 1 ) ;
}
V_29 = (struct V_70 * ) F_24 ( V_18 ) ;
V_123 = V_29 -> V_7 . V_38 ;
V_126 = F_91 ( V_123 ) + sizeof( struct V_85 ) ;
if ( F_92 ( V_18 ) < V_126 || F_93 ( V_18 ) ) {
struct V_17 * V_127 =
F_94 ( V_18 , V_126 ) ;
if ( ! V_127 )
goto V_103;
F_95 ( V_18 ) ;
V_18 = V_127 ;
V_124 = F_56 ( V_18 ) ;
}
V_18 -> V_128 = V_18 -> V_129 ;
F_96 ( V_18 , sizeof( struct V_85 ) ) ;
F_97 ( V_18 ) ;
memset ( & ( F_98 ( V_18 ) -> V_130 ) , 0 , sizeof( F_98 ( V_18 ) -> V_130 ) ) ;
V_43 = F_56 ( V_18 ) ;
V_43 -> V_131 = 6 ;
V_43 -> V_137 = V_138 ;
V_43 -> V_139 = V_124 -> V_139 ;
F_102 ( & V_43 -> V_139 , sizeof( * V_124 ) ) ;
V_43 -> V_140 = V_124 -> V_140 ;
memset ( & V_43 -> V_141 , 0 , sizeof( V_43 -> V_141 ) ) ;
V_43 -> V_24 = V_91 -> V_24 . V_81 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_142 = V_124 -> V_142 ;
V_18 -> V_104 = 1 ;
V_92 = F_58 ( V_18 , V_91 ) ;
if ( V_92 == V_93 )
F_103 ( V_18 ) ;
else if ( V_92 == V_136 )
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_104 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
int V_45 ;
F_69 ( 10 ) ;
F_70 () ;
V_45 = F_22 ( V_18 , V_91 -> V_5 , V_91 -> V_24 . V_49 ,
V_55 |
V_56 |
V_33 , NULL ) ;
if ( V_45 < 0 )
goto V_103;
if ( V_45 ) {
F_72 () ;
return F_66 ( V_102 , V_18 , V_91 , 1 ) ;
}
F_71 ( F_32 ( V_18 ) ) ;
V_18 -> V_104 = 1 ;
F_66 ( V_102 , V_18 , V_91 , 0 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_105 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , struct V_78 * V_79 )
{
int V_45 ;
F_69 ( 10 ) ;
F_70 () ;
V_45 = F_54 ( V_18 , V_91 -> V_5 , & V_91 -> V_24 . V_81 , NULL ,
V_79 , 0 ,
V_55 |
V_56 ) ;
if ( V_45 < 0 )
goto V_103;
if ( V_45 ) {
F_72 () ;
return F_66 ( V_105 , V_18 , V_91 , 1 ) ;
}
V_18 -> V_104 = 1 ;
F_66 ( V_105 , V_18 , V_91 , 0 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
F_73 ( 10 ) ;
return V_97 ;
}
int
F_106 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , int V_143 , unsigned int V_144 ,
struct V_78 * V_43 )
{
struct V_22 * V_29 ;
int V_106 ;
int V_45 ;
int V_25 , V_107 ;
F_69 ( 10 ) ;
if ( F_107 ( V_91 ) != V_145 ) {
if ( V_91 -> V_146 )
V_106 = V_91 -> V_146 ( V_18 , V_91 , V_101 , V_43 ) ;
else
V_106 = V_93 ;
F_108 ( & V_91 -> V_147 ) ;
goto V_148;
}
V_107 = F_80 ( F_35 ( V_18 ) ) ;
V_25 = ( V_144 != V_149 ) ?
V_55 | V_56 |
V_58 : V_56 ;
F_70 () ;
V_45 = F_22 ( V_18 , V_91 -> V_5 , V_91 -> V_24 . V_49 , V_25 , NULL ) ;
if ( V_45 < 0 )
goto V_103;
V_29 = F_35 ( V_18 ) ;
#if F_81 ( V_111 )
if ( V_91 -> V_71 & V_112 && V_45 ) {
enum V_113 V_114 ;
struct V_115 * V_116 = F_82 ( V_18 , & V_114 ) ;
if ( V_116 && ! F_83 ( V_116 ) ) {
F_29 ( 10 , L_27
L_28 ,
V_64 , & V_91 -> V_24 . V_49 ) ;
goto V_103;
}
}
#endif
if ( V_45 && F_34 ( V_91 -> V_24 . V_49 ) && V_107 ) {
F_29 ( 1 , L_27
L_29 ,
V_64 , & V_91 -> V_24 . V_49 ) ;
goto V_103;
}
if ( ! F_85 ( V_18 , V_143 ) )
goto V_103;
if ( F_86 ( V_18 , V_29 -> V_7 . V_38 -> V_118 ) )
goto V_103;
F_109 ( V_18 , V_101 , V_91 , 0 ) ;
V_18 -> V_104 = 1 ;
V_106 = F_62 ( V_102 , V_18 , V_91 , V_45 ) ;
F_72 () ;
goto V_148;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
V_106 = V_97 ;
V_148:
F_73 ( 10 ) ;
return V_106 ;
}
int
F_110 ( struct V_17 * V_18 , struct V_90 * V_91 ,
struct V_100 * V_101 , int V_143 , unsigned int V_144 ,
struct V_78 * V_79 )
{
struct V_70 * V_29 ;
int V_106 ;
int V_45 ;
int V_25 ;
F_69 ( 10 ) ;
if ( F_107 ( V_91 ) != V_145 ) {
if ( V_91 -> V_146 )
V_106 = V_91 -> V_146 ( V_18 , V_91 , V_101 , V_79 ) ;
else
V_106 = V_93 ;
F_108 ( & V_91 -> V_147 ) ;
goto V_148;
}
V_25 = ( V_144 != V_149 ) ?
V_55 | V_56 |
V_58 : V_56 ;
F_70 () ;
V_45 = F_54 ( V_18 , V_91 -> V_5 , & V_91 -> V_24 . V_81 , NULL ,
V_79 , 0 , V_25 ) ;
if ( V_45 < 0 )
goto V_103;
V_29 = (struct V_70 * ) F_24 ( V_18 ) ;
#if F_81 ( V_111 )
if ( V_91 -> V_71 & V_112 && V_45 ) {
enum V_113 V_114 ;
struct V_115 * V_116 = F_82 ( V_18 , & V_114 ) ;
if ( V_116 && ! F_83 ( V_116 ) ) {
F_29 ( 10 , L_27
L_30 ,
V_64 , & V_91 -> V_24 . V_81 ) ;
goto V_103;
}
}
#endif
if ( V_45 && V_18 -> V_38 && ! ( V_18 -> V_38 -> V_71 & V_72 ) &&
F_55 ( & V_29 -> V_121 . V_48 ) & V_84 ) {
F_29 ( 1 , L_27
L_31 ,
V_64 , & V_91 -> V_24 . V_81 ) ;
goto V_103;
}
if ( ! F_85 ( V_18 , V_143 ) )
goto V_103;
if ( F_86 ( V_18 , V_29 -> V_7 . V_38 -> V_118 ) )
goto V_103;
F_111 ( V_18 , V_101 , V_91 , 0 ) ;
V_18 -> V_104 = 1 ;
V_106 = F_62 ( V_105 , V_18 , V_91 , V_45 ) ;
F_72 () ;
goto V_148;
V_103:
F_74 ( V_18 ) ;
F_72 () ;
V_106 = V_97 ;
V_148:
F_73 ( 10 ) ;
return V_106 ;
}
