static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( F_3 ( V_2 -> V_4 . V_5 + V_3 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_5 ( F_6 ( V_6 ) , V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
F_8 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
F_10 ( V_2 -> V_4 . V_7 + V_3 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( F_3 ( V_2 -> V_4 . V_7 + V_3 ) ) ;
}
static inline struct V_8 * F_12 ( void )
{
return & F_13 ( V_9 ) ;
}
static inline void F_14 ( void )
{
F_15 ( V_9 ) ;
}
static T_2 F_16 ( int V_10 , void * V_11 )
{
struct V_8 * V_2 = V_11 ;
struct V_1 * V_12 = & V_2 -> V_2 ;
T_1 V_13 = V_2 -> V_14 ;
T_1 V_15 = F_1 ( V_12 , V_16 ) & V_2 -> V_14 ;
if ( F_17 ( ! V_15 ) )
return V_17 ;
V_13 |= F_18 ( V_2 , V_15 ) ;
F_4 ( V_12 , V_16 , V_13 ) ;
return V_18 ;
}
static struct V_19 * F_19 ( struct V_19 * V_2 )
{
T_3 V_4 = ( T_3 ) V_2 ;
V_4 &= ~ V_20 ;
return (struct V_19 * ) V_4 ;
}
static int F_20 ( struct V_19 * V_21 )
{
return ( ( T_3 ) V_21 >> V_22 ) & ( V_23 - 1 ) ;
}
static inline void F_21 ( struct V_24 * V_25 )
{
struct V_19 * V_26 = V_25 -> V_27 + 1 ;
V_25 -> V_27 = F_19 ( V_26 ) ;
if ( V_26 != V_25 -> V_27 )
V_25 -> V_28 ^= V_29 ;
}
static int F_22 ( struct V_1 * V_12 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
return V_25 -> V_30 ;
}
static int F_23 ( struct V_1 * V_12 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
return V_23 - 1 - V_25 -> V_30 ;
}
static void F_24 ( struct V_1 * V_12 , T_4 V_31 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
V_25 -> V_31 = V_31 ;
F_4 ( V_12 , V_32 , V_31 ) ;
}
static void F_25 ( struct V_1 * V_12 )
{
T_5 struct V_24 * V_25 = & V_12 -> V_25 ;
F_26 ( V_25 -> V_33 == V_34 ) ;
F_9 ( V_12 , V_35 ) ;
}
static T_4 F_27 ( struct V_1 * V_12 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
T_4 V_36 , V_37 = V_25 -> V_5 ;
F_26 ( V_25 -> V_33 == V_34 ) ;
V_25 -> V_5 = F_11 ( V_12 , V_35 ) & ( V_23 - 1 ) ;
F_7 ( V_12 , V_35 ) ;
V_36 = F_28 ( V_23 , V_37 , V_25 -> V_5 ) ;
V_25 -> V_30 += V_36 ;
return V_36 ;
}
static inline struct V_19 * F_29 ( struct V_1 * V_12 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
F_26 ( ! V_25 -> V_38 ) ;
if ( ! V_25 -> V_30 )
return NULL ;
#ifdef F_30
V_25 -> V_38 = 1 ;
#endif
F_31 ( V_25 -> V_27 ) ;
return V_25 -> V_27 ;
}
static inline void F_32 ( struct V_1 * V_12 , T_4 V_39 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
struct V_19 * V_40 ;
F_26 ( V_25 -> V_38 ) ;
F_26 ( V_25 -> V_41 == V_42 ) ;
F_26 ( V_25 -> V_30 >= 1 ) ;
F_33 () ;
V_40 = V_25 -> V_27 ;
V_40 -> V_43 = V_39 | V_25 -> V_28 ;
F_34 ( V_40 ) ;
F_21 ( V_25 ) ;
V_25 -> V_30 -- ;
#ifdef F_30
V_25 -> V_38 = 0 ;
#endif
}
static int F_35 ( struct V_1 * V_12 , enum V_44 V_41 ,
enum V_45 V_33 )
{
struct V_24 * V_25 = & V_12 -> V_25 ;
T_1 V_46 ;
T_4 V_47 ;
V_25 -> V_48 = V_12 -> V_4 . V_7 + V_49 ;
V_25 -> V_5 = F_1 ( V_12 , V_50 ) & ( V_23 - 1 ) ;
V_47 = F_1 ( V_12 , V_51 ) & ( V_23 - 1 ) ;
V_25 -> V_27 = V_25 -> V_48 + V_47 ;
V_25 -> V_28 = ( F_1 ( V_12 , V_51 ) & V_23 ) ?
V_29 : 0 ;
V_25 -> V_30 = V_23 - 1
- F_28 ( V_23 , V_25 -> V_5 , V_47 ) ;
V_25 -> V_31 = F_1 ( V_12 , V_32 ) ;
#ifdef F_30
V_25 -> V_38 = 0 ;
V_25 -> V_41 = V_41 ;
V_25 -> V_33 = V_33 ;
#endif
V_46 = ( F_1 ( V_12 , V_52 ) & 0xffffffe0 )
| ( V_41 & 0x3 ) ;
F_4 ( V_12 , V_52 , V_46 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_12 )
{
#ifdef F_30
struct V_24 * V_25 = & V_12 -> V_25 ;
int V_53 ;
F_26 ( ! V_25 -> V_38 ) ;
V_53 = F_1 ( V_12 , V_51 ) & ( V_23 - 1 ) ;
if ( V_53 != F_20 ( V_25 -> V_27 ) )
F_37 ( L_1 ) ;
V_53 = F_1 ( V_12 , V_50 ) & ( V_23 - 1 ) ;
if ( V_53 != V_25 -> V_5 )
F_37 ( L_2 ) ;
if ( V_25 -> V_5 != F_20 ( V_25 -> V_27 ) )
F_37 ( L_3 ) ;
#endif
}
static int F_38 ( struct V_1 * V_12 )
{
struct V_54 * V_55 = & V_12 -> V_55 ;
V_55 -> V_56 = V_12 -> V_4 . V_7 + V_57 ;
V_55 -> V_58 = V_12 -> V_4 . V_7 + V_59 ;
V_55 -> V_60 = ( F_39 ( & V_55 -> V_56 -> V_43 ) & V_61 ) ?
0 : 1 ;
V_55 -> V_28 = V_55 -> V_60 ? V_61 : 0 ;
#ifdef F_30
V_55 -> V_62 = V_63 ;
#endif
return 0 ;
}
static void F_40 ( struct V_1 * V_12 )
{
#ifdef F_30
struct V_54 * V_55 = & V_12 -> V_55 ;
F_26 ( V_55 -> V_62 == V_63 ) ;
if ( V_55 -> V_62 != V_63 )
F_37 ( L_4 ) ;
#endif
}
static inline struct V_64 * F_41 ( struct V_1 * V_12 )
{
struct V_54 * V_55 = & V_12 -> V_55 ;
F_26 ( V_55 -> V_62 == V_63 ) ;
#ifdef F_30
V_55 -> V_62 = V_65 ;
#endif
F_31 ( V_55 -> V_56 ) ;
return V_55 -> V_56 ;
}
static inline void F_42 ( struct V_1 * V_12 , T_4 V_39 )
{
struct V_54 * V_55 = & V_12 -> V_55 ;
union V_66 * V_58 = V_55 -> V_58 + V_55 -> V_60 ;
F_26 ( V_55 -> V_62 == V_65 ) ;
F_33 () ;
V_55 -> V_56 -> V_43 = V_39 | V_55 -> V_28 ;
F_34 ( V_55 -> V_56 ) ;
F_43 ( V_58 ) ;
#ifdef F_30
V_55 -> V_62 = V_67 ;
#endif
}
static inline union V_66 * V_66 ( struct V_1 * V_12 )
{
struct V_54 * V_55 = & V_12 -> V_55 ;
union V_66 * V_58 = V_55 -> V_58 + V_55 -> V_60 ;
F_26 ( V_55 -> V_62 == V_67 ) ;
if ( ! F_39 ( & V_58 -> V_68 ) ) {
F_43 ( V_58 ) ;
return NULL ;
}
V_55 -> V_60 ^= 1 ;
V_55 -> V_28 ^= V_61 ;
#ifdef F_30
V_55 -> V_62 = V_63 ;
#endif
return V_58 ;
}
static inline int F_44 ( struct V_1 * V_12 ,
union V_66 * * V_69 )
{
int V_70 = V_71 ;
do {
* V_69 = V_66 ( V_12 ) ;
if ( * V_69 )
break;
F_45 ( 1 ) ;
} while ( -- V_70 );
return V_70 ;
}
static void F_46 ( struct V_1 * V_12 )
{
F_4 ( V_12 , F_47 ( 0 ) , 0 ) ;
F_4 ( V_12 , F_47 ( 1 ) , 0 ) ;
}
static int F_48 ( struct V_8 * V_12 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 ;
int V_74 ;
V_2 = & V_12 -> V_2 ;
V_2 -> V_4 . V_7 = V_73 -> V_75 [ V_76 ] ;
V_2 -> V_4 . V_5 = V_73 -> V_75 [ V_77 ] ;
if ( F_35 ( V_2 , V_42 , V_34 ) ) {
F_49 ( V_73 -> V_78 , L_5 ) ;
goto V_79;
}
if ( F_38 ( V_2 ) ) {
F_49 ( V_73 -> V_78 , L_6 ) ;
goto V_80;
}
F_46 ( V_2 ) ;
F_4 ( V_2 , V_81 , 0xffffffff ) ;
V_12 -> V_14 = 0 ;
F_4 ( V_2 , V_82 , 0 ) ;
F_4 ( V_2 , V_16 , 0xffffffff ) ;
snprintf ( V_12 -> V_83 , V_84 , V_85 , V_73 -> V_86 ) ;
if ( F_50 ( V_73 -> V_10 , F_16 , 0 , V_12 -> V_83 , V_12 ) ) {
F_49 ( V_73 -> V_78 , L_7 ) ;
goto V_87;
}
if ( V_73 -> V_86 != - 1 && F_51 ( V_73 -> V_10 ) &&
F_52 ( V_73 -> V_10 , F_53 ( V_73 -> V_86 ) ) ) {
F_49 ( V_73 -> V_78 , L_8 ) ;
goto V_88;
}
V_74 = F_23 ( V_2 ) ;
if ( V_74 ) {
F_49 ( V_73 -> V_78 , L_9 ) ;
goto V_89;
}
V_12 -> V_90 = V_73 ;
F_4 ( V_2 , V_81 , 0 ) ;
F_4 ( V_2 , V_91 , 0 ) ;
return 0 ;
V_89:
V_88:
F_54 ( V_73 -> V_10 , V_12 ) ;
V_87:
F_40 ( V_2 ) ;
V_80:
F_36 ( V_2 ) ;
V_79:
return - V_92 ;
}
struct V_8 * F_55 ( const struct V_72 * V_73 )
{
struct V_8 * V_12 ;
int V_93 ;
V_12 = & F_56 ( V_9 , V_73 -> V_86 ) ;
V_93 = F_48 ( V_12 , V_73 ) ;
if ( V_93 )
return NULL ;
F_57 ( & V_94 ) ;
F_58 ( V_73 -> V_86 , & V_95 ) ;
F_59 ( & V_94 ) ;
return V_12 ;
}
static T_1 F_18 ( struct V_8 * V_2 , T_1 V_15 )
{
T_1 V_74 = V_15 ;
if ( V_15 & V_96 ) {
F_27 ( & V_2 -> V_2 ) ;
F_24 ( & V_2 -> V_2 , 0 ) ;
F_4 ( & V_2 -> V_2 , V_16 , V_96 ) ;
V_15 &= ~ V_96 ;
}
F_26 ( ! V_15 ) ;
return V_74 ;
}
int F_60 ( struct V_8 * V_2 , T_1 V_97 )
{
unsigned long V_98 ;
F_61 ( V_98 ) ;
F_62 ( V_97 & V_99 , & V_2 -> V_14 ) ;
F_4 ( & V_2 -> V_2 , V_82 , V_2 -> V_14 ) ;
F_63 ( V_98 ) ;
return 0 ;
}
static int F_64 ( T_1 V_100 )
{
struct V_64 * V_101 ;
union V_66 * V_102 ;
while ( 1 ) {
struct V_8 * V_2 = F_12 () ;
V_101 = F_41 ( & V_2 -> V_2 ) ;
V_101 -> V_100 = V_100 ;
F_42 ( & V_2 -> V_2 , V_103 | 1 ) ;
if ( ! F_44 ( & V_2 -> V_2 , & V_102 ) ) {
F_14 () ;
F_37 ( L_10 ) ;
return - V_104 ;
}
if ( ! ( V_102 -> V_68 & V_105 ) ) {
F_14 () ;
return 0 ;
}
F_14 () ;
}
return 0 ;
}
static int F_65 ( T_1 * V_106 , T_1 V_107 )
{
unsigned long V_4 ;
V_4 = F_66 ( V_108 , V_107 ) ;
if ( ! V_4 )
return - V_109 ;
* V_106 = V_4 & ~ V_110 ;
return 0 ;
}
static int F_67 ( T_1 V_100 )
{
int V_74 ;
V_74 = F_64 ( V_100 ) ;
if ( V_74 ) {
F_68 ( L_11 , V_100 ) ;
return V_74 ;
}
F_69 ( V_108 , V_100 | V_110 , 1 ) ;
return 0 ;
}
struct V_111 * F_70 ( void )
{
struct V_111 * V_112 = NULL ;
T_1 V_100 ;
if ( F_65 ( & V_100 , 1 ) )
return NULL ;
V_112 = F_71 ( sizeof( * V_112 ) , V_113 ) ;
if ( ! V_112 )
goto V_93;
V_112 -> V_100 = V_100 ;
return V_112 ;
V_93:
F_67 ( V_100 ) ;
F_72 ( V_112 ) ;
return NULL ;
}
void F_73 ( struct V_111 * V_112 )
{
F_67 ( V_112 -> V_100 ) ;
F_72 ( V_112 ) ;
}
int F_74 ( const struct V_111 * V_112 )
{
return V_112 -> V_100 ;
}
static void F_75 ( struct V_8 * V_2 , int V_114 )
{
if ( V_114 )
F_25 ( & V_2 -> V_2 ) ;
else
F_27 ( & V_2 -> V_2 ) ;
}
int F_76 ( struct V_111 * V_112 , const struct V_115 * V_116 , T_4 V_117 )
{
struct V_8 * V_2 ;
struct V_19 * V_118 ;
unsigned long V_98 ;
int V_114 , V_70 = 1000 ;
int V_53 = V_117 - 1 ;
F_26 ( V_117 > 0 && V_117 <= 8 ) ;
do {
V_2 = F_12 () ;
F_61 ( V_98 ) ;
V_114 = F_22 ( & V_2 -> V_2 ) ;
if ( V_114 < 2 )
F_75 ( V_2 , V_114 ) ;
V_118 = F_29 ( & V_2 -> V_2 ) ;
F_63 ( V_98 ) ;
F_14 () ;
if ( F_77 ( V_118 ) )
break;
F_45 ( 1 ) ;
} while ( -- V_70 );
if ( F_17 ( ! V_70 ) )
return - V_104 ;
V_2 = F_12 () ;
F_61 ( V_98 ) ;
F_78 ( V_118 -> V_116 , F_79 ( V_116 ) ) ;
F_80 ( V_118 -> V_116 , V_112 -> V_100 ) ;
if ( V_53 )
memcpy ( & V_118 -> V_116 [ 1 ] , & V_116 [ 1 ] , V_53 * sizeof( V_116 [ 0 ] ) ) ;
F_32 ( & V_2 -> V_2 , V_119 |
( V_117 & V_120 ) ) ;
F_63 ( V_98 ) ;
F_14 () ;
return 0 ;
}
int F_81 ( struct V_111 * V_112 , struct V_115 * V_116 , T_4 V_117 )
{
struct V_8 * V_2 = F_12 () ;
struct V_64 * V_121 ;
union V_66 * V_69 ;
int V_74 ;
F_26 ( V_117 > 0 && V_117 <= 8 ) ;
V_121 = F_41 ( & V_2 -> V_2 ) ;
V_121 -> V_100 = V_112 -> V_100 ;
F_42 ( & V_2 -> V_2 , V_103 |
( V_117 & V_122 ) ) ;
if ( ! F_44 ( & V_2 -> V_2 , & V_69 ) ) {
F_14 () ;
F_37 ( L_12 ) ;
return - V_104 ;
}
V_74 = V_69 -> V_68 & V_105 ;
if ( V_116 )
memcpy ( & V_116 [ 0 ] , & V_69 -> V_116 [ 0 ] , V_117 * sizeof( V_116 [ 0 ] ) ) ;
F_14 () ;
if ( V_74 != V_117 )
V_74 = - V_109 ;
return V_74 ;
}
const struct V_72 *
F_82 ( const struct V_8 * V_12 )
{
return V_12 -> V_90 ;
}
