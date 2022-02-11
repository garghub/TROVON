static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 , T_1 V_7 ,
unsigned long V_8 )
{
F_4 ( V_7 , V_6 -> V_9 + V_8 ) ;
}
static inline T_1 F_5 ( struct V_5 * V_6 , unsigned long V_8 )
{
return F_6 ( V_6 -> V_9 + V_8 ) ;
}
static unsigned int F_7 ( unsigned long V_10 )
{
return ( V_10 >> V_11 ) & ( V_12 - 1 ) ;
}
static unsigned int F_8 ( unsigned long V_10 )
{
return ( V_10 >> V_13 ) & ( V_14 - 1 ) ;
}
static bool F_9 ( struct V_5 * V_6 , T_2 V_15 )
{
V_15 >>= 12 ;
return ( V_15 & V_6 -> V_16 ) == V_15 ;
}
static T_2 F_10 ( T_1 V_17 )
{
return V_17 << 12 ;
}
static void F_11 ( struct V_5 * V_6 )
{
F_3 ( V_6 , V_18 , V_19 ) ;
}
static inline void F_12 ( struct V_5 * V_6 , T_2 V_20 ,
unsigned long V_8 )
{
T_1 V_7 ;
V_8 &= ~ ( V_6 -> V_21 -> V_22 -> V_23 - 1 ) ;
if ( V_6 -> V_21 -> V_22 -> V_24 > 32 ) {
#ifdef F_13
V_7 = ( V_20 >> 32 ) & V_25 ;
#else
V_7 = 0 ;
#endif
F_3 ( V_6 , V_7 , V_26 ) ;
}
V_7 = ( V_20 + V_8 ) | V_27 ;
F_3 ( V_6 , V_7 , V_19 ) ;
}
static inline void F_14 ( struct V_5 * V_6 )
{
F_3 ( V_6 , V_28 , V_29 ) ;
}
static inline void F_15 ( struct V_5 * V_6 ,
unsigned long V_30 )
{
T_1 V_7 ;
V_7 = V_31 | F_16 ( V_30 ) |
V_28 ;
F_3 ( V_6 , V_7 , V_29 ) ;
}
static inline void F_17 ( struct V_5 * V_6 ,
unsigned long V_30 ,
unsigned long V_10 )
{
T_1 V_7 ;
V_7 = V_31 | F_16 ( V_30 ) |
F_18 ( V_10 ) ;
F_3 ( V_6 , V_7 , V_29 ) ;
}
static inline void F_19 ( struct V_5 * V_6 ,
unsigned long V_30 ,
unsigned long V_10 )
{
T_1 V_7 ;
V_7 = V_31 | F_16 ( V_30 ) |
F_20 ( V_10 ) ;
F_3 ( V_6 , V_7 , V_29 ) ;
}
static inline void F_21 ( struct V_5 * V_6 )
{
F_5 ( V_6 , V_32 ) ;
}
static int F_22 ( struct V_5 * V_6 , unsigned int * V_33 )
{
unsigned long V_34 ;
F_23 ( & V_6 -> V_35 ) ;
V_34 = F_24 ( V_6 -> V_36 , V_6 -> V_22 -> V_37 ) ;
if ( V_34 >= V_6 -> V_22 -> V_37 ) {
F_25 ( & V_6 -> V_35 ) ;
return - V_38 ;
}
F_26 ( V_34 , V_6 -> V_36 ) ;
* V_33 = V_34 ;
F_25 ( & V_6 -> V_35 ) ;
return 0 ;
}
static void F_27 ( struct V_5 * V_6 , unsigned int V_34 )
{
F_23 ( & V_6 -> V_35 ) ;
F_28 ( V_34 , V_6 -> V_36 ) ;
F_25 ( & V_6 -> V_35 ) ;
}
static bool F_29 ( enum V_39 V_40 )
{
return false ;
}
static struct V_2 * F_30 ( unsigned type )
{
struct V_1 * V_41 ;
if ( type != V_42 )
return NULL ;
V_41 = F_31 ( sizeof( * V_41 ) , V_43 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_44 = V_45 | V_46 | V_47 ;
V_41 -> V_48 = F_32 ( V_43 | V_49 | V_50 ) ;
if ( ! V_41 -> V_48 ) {
F_33 ( V_41 ) ;
return NULL ;
}
V_41 -> V_51 = F_34 ( V_12 , sizeof( T_1 ) , V_43 ) ;
if ( ! V_41 -> V_51 ) {
F_35 ( V_41 -> V_48 ) ;
F_33 ( V_41 ) ;
return NULL ;
}
V_41 -> V_52 = F_34 ( V_12 , sizeof( * V_41 -> V_52 ) , V_43 ) ;
if ( ! V_41 -> V_52 ) {
F_33 ( V_41 -> V_51 ) ;
F_35 ( V_41 -> V_48 ) ;
F_33 ( V_41 ) ;
return NULL ;
}
V_41 -> V_4 . V_53 . V_54 = 0 ;
V_41 -> V_4 . V_53 . V_55 = 0xffffffff ;
V_41 -> V_4 . V_53 . V_56 = true ;
return & V_41 -> V_4 ;
}
static void F_36 ( struct V_2 * V_4 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
F_33 ( V_41 ) ;
}
static const struct V_57 *
F_37 ( struct V_5 * V_6 , unsigned int V_58 )
{
const struct V_57 * V_59 = NULL ;
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_22 -> V_61 ; V_60 ++ ) {
if ( V_6 -> V_22 -> V_62 [ V_60 ] . V_58 == V_58 ) {
V_59 = & V_6 -> V_22 -> V_62 [ V_60 ] ;
break;
}
}
return V_59 ;
}
static void F_38 ( struct V_5 * V_6 , unsigned int V_58 ,
unsigned int V_30 )
{
const struct V_57 * V_59 ;
unsigned int V_60 ;
T_1 V_7 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_22 -> V_63 ; V_60 ++ ) {
const struct V_64 * V_65 = & V_6 -> V_22 -> V_66 [ V_60 ] ;
if ( V_65 -> V_58 != V_58 )
continue;
V_7 = F_5 ( V_6 , V_65 -> V_6 . V_67 ) ;
V_7 |= F_39 ( V_65 -> V_6 . V_68 ) ;
F_3 ( V_6 , V_7 , V_65 -> V_6 . V_67 ) ;
}
V_59 = F_37 ( V_6 , V_58 ) ;
if ( V_59 ) {
V_7 = F_5 ( V_6 , V_59 -> V_67 ) ;
V_7 &= ~ V_69 ;
V_7 |= F_40 ( V_30 ) ;
V_7 |= V_70 ;
F_3 ( V_6 , V_7 , V_59 -> V_67 ) ;
}
}
static void F_41 ( struct V_5 * V_6 , unsigned int V_58 ,
unsigned int V_30 )
{
const struct V_57 * V_59 ;
unsigned int V_60 ;
T_1 V_7 ;
V_59 = F_37 ( V_6 , V_58 ) ;
if ( V_59 ) {
V_7 = F_5 ( V_6 , V_59 -> V_67 ) ;
V_7 &= ~ V_69 ;
V_7 |= F_40 ( V_30 ) ;
V_7 &= ~ V_70 ;
F_3 ( V_6 , V_7 , V_59 -> V_67 ) ;
}
for ( V_60 = 0 ; V_60 < V_6 -> V_22 -> V_63 ; V_60 ++ ) {
const struct V_64 * V_65 = & V_6 -> V_22 -> V_66 [ V_60 ] ;
if ( V_65 -> V_58 != V_58 )
continue;
V_7 = F_5 ( V_6 , V_65 -> V_6 . V_67 ) ;
V_7 &= ~ F_39 ( V_65 -> V_6 . V_68 ) ;
F_3 ( V_6 , V_7 , V_65 -> V_6 . V_67 ) ;
}
}
static int F_42 ( struct V_5 * V_6 ,
struct V_1 * V_41 )
{
T_1 V_7 ;
int V_71 ;
if ( V_41 -> V_72 > 0 ) {
V_41 -> V_72 ++ ;
return 0 ;
}
V_41 -> V_73 = F_43 ( V_6 -> V_74 , V_41 -> V_48 , 0 , V_75 ,
V_76 ) ;
if ( F_44 ( V_6 -> V_74 , V_41 -> V_73 ) )
return - V_77 ;
if ( ! F_9 ( V_6 , V_41 -> V_73 ) ) {
V_71 = - V_77 ;
goto V_78;
}
V_71 = F_22 ( V_6 , & V_41 -> V_34 ) ;
if ( V_71 < 0 )
goto V_78;
F_12 ( V_6 , V_41 -> V_73 , 0 ) ;
F_15 ( V_6 , V_41 -> V_34 ) ;
F_3 ( V_6 , V_41 -> V_34 & 0x7f , V_79 ) ;
V_7 = F_45 ( V_41 -> V_73 , V_41 -> V_44 ) ;
F_3 ( V_6 , V_7 , V_80 ) ;
F_21 ( V_6 ) ;
V_41 -> V_6 = V_6 ;
V_41 -> V_72 ++ ;
return 0 ;
V_78:
F_46 ( V_6 -> V_74 , V_41 -> V_73 , V_75 , V_76 ) ;
return V_71 ;
}
static void F_47 ( struct V_5 * V_6 ,
struct V_1 * V_41 )
{
if ( -- V_41 -> V_72 > 0 )
return;
F_27 ( V_6 , V_41 -> V_34 ) ;
F_46 ( V_6 -> V_74 , V_41 -> V_73 , V_75 , V_76 ) ;
V_41 -> V_6 = NULL ;
}
static int F_48 ( struct V_2 * V_4 ,
struct V_81 * V_74 )
{
struct V_5 * V_6 = V_74 -> V_82 . V_83 ;
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_84 * V_85 = V_74 -> V_86 ;
struct V_87 args ;
unsigned int V_88 = 0 ;
int V_71 = 0 ;
while ( ! F_49 ( V_85 , L_1 , L_2 , V_88 ,
& args ) ) {
unsigned int V_58 = args . args [ 0 ] ;
if ( args . V_85 != V_6 -> V_74 -> V_86 ) {
F_50 ( args . V_85 ) ;
continue;
}
F_50 ( args . V_85 ) ;
V_71 = F_42 ( V_6 , V_41 ) ;
if ( V_71 < 0 )
return V_71 ;
F_38 ( V_6 , V_58 , V_41 -> V_34 ) ;
V_88 ++ ;
}
if ( V_88 == 0 )
return - V_89 ;
return 0 ;
}
static void F_51 ( struct V_2 * V_4 , struct V_81 * V_74 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
struct V_84 * V_85 = V_74 -> V_86 ;
struct V_5 * V_6 = V_41 -> V_6 ;
struct V_87 args ;
unsigned int V_88 = 0 ;
while ( ! F_49 ( V_85 , L_1 , L_2 , V_88 ,
& args ) ) {
unsigned int V_58 = args . args [ 0 ] ;
if ( args . V_85 != V_6 -> V_74 -> V_86 ) {
F_50 ( args . V_85 ) ;
continue;
}
F_50 ( args . V_85 ) ;
F_41 ( V_6 , V_58 , V_41 -> V_34 ) ;
F_47 ( V_6 , V_41 ) ;
V_88 ++ ;
}
}
static void F_52 ( struct V_1 * V_41 , unsigned long V_10 ,
T_1 V_7 )
{
unsigned int V_90 = F_7 ( V_10 ) ;
struct V_5 * V_6 = V_41 -> V_6 ;
T_1 * V_48 = F_53 ( V_41 -> V_48 ) ;
unsigned long V_8 = V_90 * sizeof( * V_48 ) ;
V_48 [ V_90 ] = V_7 ;
F_54 ( V_6 -> V_74 , V_41 -> V_73 , V_8 ,
sizeof( * V_48 ) , V_76 ) ;
F_12 ( V_6 , V_41 -> V_73 , V_8 ) ;
F_17 ( V_6 , V_41 -> V_34 , V_10 ) ;
F_21 ( V_6 ) ;
}
static T_1 * F_55 ( struct V_91 * V_92 , unsigned long V_10 )
{
T_1 * V_93 = F_53 ( V_92 ) ;
return V_93 + F_8 ( V_10 ) ;
}
static T_1 * F_56 ( struct V_1 * V_41 , unsigned long V_10 ,
T_2 * V_94 )
{
unsigned int V_90 = F_7 ( V_10 ) ;
struct V_91 * V_92 ;
T_1 * V_48 ;
V_92 = V_41 -> V_52 [ V_90 ] ;
if ( ! V_92 )
return NULL ;
V_48 = F_53 ( V_41 -> V_48 ) ;
* V_94 = F_10 ( V_48 [ V_90 ] ) ;
return F_55 ( V_92 , V_10 ) ;
}
static T_1 * F_57 ( struct V_1 * V_41 , T_2 V_10 ,
T_2 * V_94 )
{
unsigned int V_17 = F_7 ( V_10 ) ;
struct V_5 * V_6 = V_41 -> V_6 ;
if ( ! V_41 -> V_52 [ V_17 ] ) {
struct V_91 * V_91 ;
T_2 V_20 ;
V_91 = F_32 ( V_43 | V_49 | V_50 ) ;
if ( ! V_91 )
return NULL ;
V_20 = F_43 ( V_6 -> V_74 , V_91 , 0 , V_95 ,
V_76 ) ;
if ( F_44 ( V_6 -> V_74 , V_20 ) ) {
F_35 ( V_91 ) ;
return NULL ;
}
if ( ! F_9 ( V_6 , V_20 ) ) {
F_46 ( V_6 -> V_74 , V_20 , V_95 ,
V_76 ) ;
F_35 ( V_91 ) ;
return NULL ;
}
V_41 -> V_52 [ V_17 ] = V_91 ;
F_52 ( V_41 , V_10 , F_58 ( V_20 , V_96 |
V_97 ) ) ;
* V_94 = V_20 ;
} else {
T_1 * V_48 = F_53 ( V_41 -> V_48 ) ;
* V_94 = F_10 ( V_48 [ V_17 ] ) ;
}
return F_55 ( V_41 -> V_52 [ V_17 ] , V_10 ) ;
}
static void F_59 ( struct V_1 * V_41 , unsigned long V_10 )
{
unsigned int V_90 = F_7 ( V_10 ) ;
V_41 -> V_51 [ V_90 ] ++ ;
}
static void F_60 ( struct V_1 * V_41 , unsigned long V_10 )
{
unsigned int V_17 = F_7 ( V_10 ) ;
struct V_91 * V_91 = V_41 -> V_52 [ V_17 ] ;
if ( -- V_41 -> V_51 [ V_17 ] == 0 ) {
struct V_5 * V_6 = V_41 -> V_6 ;
T_1 * V_48 = F_53 ( V_41 -> V_48 ) ;
T_2 V_98 = F_10 ( V_48 [ V_17 ] ) ;
F_52 ( V_41 , V_10 , 0 ) ;
F_46 ( V_6 -> V_74 , V_98 , V_95 , V_76 ) ;
F_35 ( V_91 ) ;
V_41 -> V_52 [ V_17 ] = NULL ;
}
}
static void F_61 ( struct V_1 * V_41 , unsigned long V_10 ,
T_1 * V_99 , T_2 V_98 , T_1 V_100 )
{
struct V_5 * V_6 = V_41 -> V_6 ;
unsigned long V_8 = F_62 ( V_99 ) ;
* V_99 = V_100 ;
F_54 ( V_6 -> V_74 , V_98 , V_8 ,
4 , V_76 ) ;
F_12 ( V_6 , V_98 , V_8 ) ;
F_19 ( V_6 , V_41 -> V_34 , V_10 ) ;
F_21 ( V_6 ) ;
}
static int F_63 ( struct V_2 * V_4 , unsigned long V_10 ,
T_3 V_101 , T_4 V_102 , int V_103 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
T_2 V_98 ;
T_1 * V_99 ;
V_99 = F_57 ( V_41 , V_10 , & V_98 ) ;
if ( ! V_99 )
return - V_77 ;
if ( * V_99 == 0 )
F_59 ( V_41 , V_10 ) ;
F_61 ( V_41 , V_10 , V_99 , V_98 ,
F_64 ( V_101 ) | V_104 ) ;
return 0 ;
}
static T_4 F_65 ( struct V_2 * V_4 , unsigned long V_10 ,
T_4 V_102 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
T_2 V_98 ;
T_1 * V_99 ;
V_99 = F_56 ( V_41 , V_10 , & V_98 ) ;
if ( ! V_99 || ! * V_99 )
return 0 ;
F_61 ( V_41 , V_10 , V_99 , V_98 , 0 ) ;
F_60 ( V_41 , V_10 ) ;
return V_102 ;
}
static T_3 F_66 ( struct V_2 * V_4 ,
T_2 V_10 )
{
struct V_1 * V_41 = F_1 ( V_4 ) ;
unsigned long V_105 ;
T_2 V_98 ;
T_1 * V_99 ;
V_99 = F_56 ( V_41 , V_10 , & V_98 ) ;
if ( ! V_99 || ! * V_99 )
return 0 ;
V_105 = * V_99 & V_41 -> V_6 -> V_16 ;
return F_67 ( V_105 ) ;
}
static struct V_5 * F_68 ( struct V_84 * V_85 )
{
struct V_106 * V_107 ;
struct V_108 * V_21 ;
V_107 = F_69 ( V_85 ) ;
if ( ! V_107 )
return NULL ;
V_21 = F_70 ( V_107 ) ;
if ( ! V_21 )
return NULL ;
return V_21 -> V_6 ;
}
static int F_71 ( struct V_81 * V_74 )
{
struct V_84 * V_85 = V_74 -> V_86 ;
struct V_87 args ;
unsigned int V_88 = 0 ;
while ( F_49 ( V_85 , L_1 , L_2 , V_88 ,
& args ) == 0 ) {
struct V_5 * V_6 ;
V_6 = F_68 ( args . V_85 ) ;
if ( V_6 ) {
V_74 -> V_82 . V_83 = V_6 ;
break;
}
V_88 ++ ;
}
return 0 ;
}
static void F_72 ( struct V_81 * V_74 )
{
V_74 -> V_82 . V_83 = NULL ;
}
static void F_73 ( void )
{
static const struct V_109 V_110 [] = {
{ . V_111 = L_3 , } ,
{ }
} ;
struct V_84 * V_112 ;
V_112 = F_74 ( NULL , V_110 ) ;
if ( V_112 ) {
F_75 ( V_112 ) ;
F_50 ( V_112 ) ;
}
}
static int F_76 ( struct V_113 * V_114 , void * V_115 )
{
struct V_5 * V_6 = V_114 -> V_116 ;
unsigned int V_60 ;
T_1 V_7 ;
F_77 ( V_114 , L_4 ) ;
F_77 ( V_114 , L_5 ) ;
for ( V_60 = 0 ; V_60 < V_6 -> V_22 -> V_61 ; V_60 ++ ) {
const struct V_57 * V_59 = & V_6 -> V_22 -> V_62 [ V_60 ] ;
const char * V_117 ;
unsigned int V_30 ;
V_7 = F_5 ( V_6 , V_59 -> V_67 ) ;
if ( V_7 & V_70 )
V_117 = L_6 ;
else
V_117 = L_7 ;
V_30 = V_7 & V_69 ;
F_77 ( V_114 , L_8 , V_59 -> V_118 , V_117 ,
V_30 ) ;
}
return 0 ;
}
static int F_78 ( struct V_119 * V_119 , struct V_120 * V_120 )
{
return F_79 ( V_120 , F_76 , V_119 -> V_121 ) ;
}
static int F_80 ( struct V_113 * V_114 , void * V_115 )
{
struct V_5 * V_6 = V_114 -> V_116 ;
unsigned int V_60 ;
T_1 V_7 ;
F_77 ( V_114 , L_9 ) ;
F_77 ( V_114 , L_10 ) ;
for ( V_60 = 0 ; V_60 < V_6 -> V_22 -> V_63 ; V_60 ++ ) {
const struct V_64 * V_65 = & V_6 -> V_22 -> V_66 [ V_60 ] ;
const char * V_117 ;
V_7 = F_5 ( V_6 , V_65 -> V_6 . V_67 ) ;
if ( V_7 & F_39 ( V_65 -> V_6 . V_68 ) )
V_117 = L_6 ;
else
V_117 = L_7 ;
F_77 ( V_114 , L_11 , V_65 -> V_118 , V_117 ) ;
}
return 0 ;
}
static int F_81 ( struct V_119 * V_119 , struct V_120 * V_120 )
{
return F_79 ( V_120 , F_80 , V_119 -> V_121 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
V_6 -> V_122 = F_83 ( L_12 , NULL ) ;
if ( ! V_6 -> V_122 )
return;
F_84 ( L_13 , V_123 , V_6 -> V_122 , V_6 ,
& V_124 ) ;
F_84 ( L_14 , V_123 , V_6 -> V_122 , V_6 ,
& V_125 ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
F_86 ( V_6 -> V_122 ) ;
}
struct V_5 * F_87 ( struct V_81 * V_74 ,
const struct V_126 * V_22 ,
struct V_108 * V_21 )
{
struct V_5 * V_6 ;
T_4 V_102 ;
T_1 V_7 ;
int V_71 ;
if ( ! V_22 )
return NULL ;
V_6 = F_88 ( V_74 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return F_89 ( - V_77 ) ;
V_21 -> V_6 = V_6 ;
V_102 = F_90 ( V_22 -> V_37 ) * sizeof( long ) ;
V_6 -> V_36 = F_88 ( V_74 , V_102 , V_43 ) ;
if ( ! V_6 -> V_36 )
return F_89 ( - V_77 ) ;
F_91 ( & V_6 -> V_35 ) ;
V_6 -> V_9 = V_21 -> V_9 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_74 = V_74 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_16 = F_92 ( V_21 -> V_22 -> V_24 - V_127 ) - 1 ;
F_93 ( V_74 , L_15 ,
V_21 -> V_22 -> V_24 , V_6 -> V_16 ) ;
V_6 -> V_128 = ( V_6 -> V_22 -> V_129 << 1 ) - 1 ;
F_93 ( V_74 , L_16 , V_6 -> V_22 -> V_129 ,
V_6 -> V_128 ) ;
V_7 = V_130 | F_94 ( 0x3f ) ;
if ( V_22 -> V_131 )
V_7 |= F_95 ( 8 ) ;
F_3 ( V_6 , V_7 , V_132 ) ;
V_7 = V_133 |
F_96 ( V_6 ) ;
if ( V_22 -> V_134 )
V_7 |= V_135 ;
F_3 ( V_6 , V_7 , V_136 ) ;
F_11 ( V_6 ) ;
F_14 ( V_6 ) ;
F_3 ( V_6 , V_137 , V_32 ) ;
F_21 ( V_6 ) ;
F_73 () ;
V_71 = F_97 ( & V_138 , & V_139 ) ;
if ( V_71 < 0 )
return F_89 ( V_71 ) ;
if ( F_98 ( V_140 ) )
F_82 ( V_6 ) ;
return V_6 ;
}
void F_99 ( struct V_5 * V_6 )
{
if ( F_98 ( V_140 ) )
F_85 ( V_6 ) ;
}
