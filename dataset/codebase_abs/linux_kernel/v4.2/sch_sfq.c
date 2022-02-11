static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
if ( V_4 < V_5 )
return & V_3 -> V_6 [ V_4 ] . V_7 ;
return & V_3 -> V_7 [ V_4 - V_5 ] ;
}
static unsigned int F_2 ( const struct V_2 * V_3 ,
const struct V_8 * V_9 )
{
return F_3 ( V_9 , V_3 -> V_10 ) & ( V_3 -> V_11 - 1 ) ;
}
static unsigned int F_4 ( struct V_8 * V_9 , struct V_12 * V_13 ,
int * V_14 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_15 V_16 ;
struct V_17 * V_18 ;
int V_19 ;
if ( F_6 ( V_9 -> V_20 ) == V_13 -> V_21 &&
F_7 ( V_9 -> V_20 ) > 0 &&
F_7 ( V_9 -> V_20 ) <= V_3 -> V_11 )
return F_7 ( V_9 -> V_20 ) ;
V_18 = F_8 ( V_3 -> V_22 ) ;
if ( ! V_18 )
return F_2 ( V_3 , V_9 ) + 1 ;
* V_14 = V_23 | V_24 ;
V_19 = F_9 ( V_9 , V_18 , & V_16 ) ;
if ( V_19 >= 0 ) {
#ifdef F_10
switch ( V_19 ) {
case V_25 :
case V_26 :
* V_14 = V_23 | V_27 ;
case V_28 :
return 0 ;
}
#endif
if ( F_7 ( V_16 . V_29 ) <= V_3 -> V_11 )
return F_7 ( V_16 . V_29 ) ;
}
return 0 ;
}
static inline void F_11 ( struct V_2 * V_3 , T_1 V_30 )
{
T_1 V_31 , V_32 ;
struct V_33 * V_34 = & V_3 -> V_6 [ V_30 ] ;
int V_35 = V_34 -> V_35 ;
V_31 = V_35 + V_5 ;
V_32 = V_3 -> V_7 [ V_35 ] . V_36 ;
V_34 -> V_7 . V_36 = V_32 ;
V_34 -> V_7 . V_37 = V_31 ;
V_3 -> V_7 [ V_35 ] . V_36 = V_30 ;
F_1 ( V_3 , V_32 ) -> V_37 = V_30 ;
}
static inline void F_12 ( struct V_2 * V_3 , T_1 V_30 )
{
T_1 V_31 , V_32 ;
int V_38 ;
F_13 ( V_3 , V_30 , V_32 , V_31 ) ;
V_38 = V_3 -> V_6 [ V_30 ] . V_35 -- ;
if ( V_32 == V_31 && V_3 -> V_39 == V_38 )
V_3 -> V_39 -- ;
F_11 ( V_3 , V_30 ) ;
}
static inline void F_14 ( struct V_2 * V_3 , T_1 V_30 )
{
T_1 V_31 , V_32 ;
int V_38 ;
F_13 ( V_3 , V_30 , V_32 , V_31 ) ;
V_38 = ++ V_3 -> V_6 [ V_30 ] . V_35 ;
if ( V_3 -> V_39 < V_38 )
V_3 -> V_39 = V_38 ;
F_11 ( V_3 , V_30 ) ;
}
static inline struct V_8 * F_15 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = V_34 -> V_40 ;
V_34 -> V_40 = V_9 -> V_37 ;
V_9 -> V_37 -> V_36 = (struct V_8 * ) V_34 ;
V_9 -> V_36 = V_9 -> V_37 = NULL ;
return V_9 ;
}
static inline struct V_8 * F_16 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = V_34 -> V_41 ;
V_34 -> V_41 = V_9 -> V_36 ;
V_9 -> V_36 -> V_37 = (struct V_8 * ) V_34 ;
V_9 -> V_36 = V_9 -> V_37 = NULL ;
return V_9 ;
}
static inline void F_17 ( struct V_33 * V_34 )
{
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_40 = V_34 -> V_41 = (struct V_8 * ) V_34 ;
}
static inline void F_18 ( struct V_33 * V_34 , struct V_8 * V_9 )
{
V_9 -> V_37 = V_34 -> V_40 ;
V_9 -> V_36 = (struct V_8 * ) V_34 ;
V_34 -> V_40 -> V_36 = V_9 ;
V_34 -> V_40 = V_9 ;
}
static unsigned int F_19 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
T_1 V_30 , V_38 = V_3 -> V_39 ;
struct V_8 * V_9 ;
unsigned int V_42 ;
struct V_33 * V_34 ;
if ( V_38 > 1 ) {
V_30 = V_3 -> V_7 [ V_38 ] . V_36 ;
V_34 = & V_3 -> V_6 [ V_30 ] ;
V_43:
V_9 = V_3 -> V_44 ? F_16 ( V_34 ) : F_15 ( V_34 ) ;
V_42 = F_20 ( V_9 ) ;
V_34 -> V_45 -= V_42 ;
F_12 ( V_3 , V_30 ) ;
V_13 -> V_3 . V_35 -- ;
F_21 ( V_13 ) ;
F_22 ( V_13 , V_9 ) ;
F_23 ( V_9 ) ;
return V_42 ;
}
if ( V_38 == 1 ) {
V_30 = V_3 -> V_46 -> V_36 ;
V_34 = & V_3 -> V_6 [ V_30 ] ;
V_3 -> V_46 -> V_36 = V_34 -> V_36 ;
V_3 -> V_47 [ V_34 -> V_48 ] = V_49 ;
goto V_43;
}
return 0 ;
}
static int F_24 ( const struct V_2 * V_3 )
{
return V_3 -> V_50 & V_51 ;
}
static int F_25 ( const struct V_2 * V_3 )
{
return ( V_3 -> V_50 & ( V_51 | V_52 ) ) == V_51 ;
}
static int F_26 ( const struct V_2 * V_3 )
{
return V_3 -> V_44 ;
}
static int
F_27 ( struct V_8 * V_9 , struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
unsigned int V_48 ;
T_1 V_30 , V_35 ;
struct V_33 * V_34 ;
int V_53 ( V_54 ) ;
struct V_8 * V_55 ;
int V_56 ;
V_48 = F_4 ( V_9 , V_13 , & V_54 ) ;
if ( V_48 == 0 ) {
if ( V_54 & V_24 )
F_21 ( V_13 ) ;
F_23 ( V_9 ) ;
return V_54 ;
}
V_48 -- ;
V_30 = V_3 -> V_47 [ V_48 ] ;
V_34 = & V_3 -> V_6 [ V_30 ] ;
if ( V_30 == V_49 ) {
V_30 = V_3 -> V_7 [ 0 ] . V_36 ;
if ( V_30 >= V_5 )
return F_28 ( V_9 , V_13 ) ;
V_3 -> V_47 [ V_48 ] = V_30 ;
V_34 = & V_3 -> V_6 [ V_30 ] ;
V_34 -> V_48 = V_48 ;
V_34 -> V_45 = 0 ;
F_29 ( & V_34 -> V_57 ) ;
goto V_58;
}
if ( V_3 -> V_59 ) {
V_34 -> V_57 . V_60 = F_30 ( V_3 -> V_59 ,
& V_34 -> V_57 ,
V_34 -> V_45 ) ;
switch ( F_31 ( V_3 -> V_59 ,
& V_34 -> V_57 ,
V_34 -> V_57 . V_60 ) ) {
case V_61 :
break;
case V_62 :
F_32 ( V_13 ) ;
if ( F_24 ( V_3 ) ) {
if ( F_26 ( V_3 ) &&
F_33 ( V_34 -> V_41 ) ) {
V_3 -> V_63 . V_64 ++ ;
break;
}
if ( F_33 ( V_9 ) ) {
V_3 -> V_63 . V_65 ++ ;
break;
}
}
V_3 -> V_63 . V_66 ++ ;
goto V_67;
case V_68 :
F_32 ( V_13 ) ;
if ( F_25 ( V_3 ) ) {
if ( F_26 ( V_3 ) &&
F_33 ( V_34 -> V_41 ) ) {
V_3 -> V_63 . V_69 ++ ;
break;
}
if ( F_33 ( V_9 ) ) {
V_3 -> V_63 . V_70 ++ ;
break;
}
}
V_3 -> V_63 . V_71 ++ ;
goto V_67;
}
}
if ( V_34 -> V_35 >= V_3 -> V_72 ) {
V_67:
if ( ! F_26 ( V_3 ) )
return F_28 ( V_9 , V_13 ) ;
V_55 = F_16 ( V_34 ) ;
V_56 = F_20 ( V_55 ) - F_20 ( V_9 ) ;
V_13 -> V_73 . V_45 -= V_56 ;
V_34 -> V_45 -= V_56 ;
F_28 ( V_55 , V_13 ) ;
F_18 ( V_34 , V_9 ) ;
return V_74 ;
}
V_58:
F_34 ( V_13 , V_9 ) ;
V_34 -> V_45 += F_20 ( V_9 ) ;
F_18 ( V_34 , V_9 ) ;
F_14 ( V_3 , V_30 ) ;
if ( V_34 -> V_35 == 1 ) {
if ( V_3 -> V_46 == NULL ) {
V_34 -> V_36 = V_30 ;
} else {
V_34 -> V_36 = V_3 -> V_46 -> V_36 ;
V_3 -> V_46 -> V_36 = V_30 ;
}
V_3 -> V_46 = V_34 ;
V_34 -> V_75 = V_3 -> V_76 ;
}
if ( ++ V_13 -> V_3 . V_35 <= V_3 -> V_77 )
return V_23 ;
V_35 = V_34 -> V_35 ;
F_19 ( V_13 ) ;
if ( V_35 != V_34 -> V_35 )
return V_74 ;
F_35 ( V_13 , 1 ) ;
return V_23 ;
}
static struct V_8 *
F_36 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_8 * V_9 ;
T_1 V_78 , V_79 ;
struct V_33 * V_34 ;
if ( V_3 -> V_46 == NULL )
return NULL ;
V_80:
V_78 = V_3 -> V_46 -> V_36 ;
V_34 = & V_3 -> V_6 [ V_78 ] ;
if ( V_34 -> V_75 <= 0 ) {
V_3 -> V_46 = V_34 ;
V_34 -> V_75 += V_3 -> V_76 ;
goto V_80;
}
V_9 = F_16 ( V_34 ) ;
F_12 ( V_3 , V_78 ) ;
F_37 ( V_13 , V_9 ) ;
V_13 -> V_3 . V_35 -- ;
F_22 ( V_13 , V_9 ) ;
V_34 -> V_45 -= F_20 ( V_9 ) ;
if ( V_34 -> V_35 == 0 ) {
V_3 -> V_47 [ V_34 -> V_48 ] = V_49 ;
V_79 = V_34 -> V_36 ;
if ( V_78 == V_79 ) {
V_3 -> V_46 = NULL ;
return V_9 ;
}
V_3 -> V_46 -> V_36 = V_79 ;
} else {
V_34 -> V_75 -= F_38 ( F_20 ( V_9 ) ) ;
}
return V_9 ;
}
static void
F_39 ( struct V_12 * V_13 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_36 ( V_13 ) ) != NULL )
F_23 ( V_9 ) ;
}
static void F_40 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_8 * V_9 ;
int V_81 ;
struct V_33 * V_34 ;
struct V_82 V_83 ;
int V_84 = 0 ;
F_41 ( & V_83 ) ;
for ( V_81 = 0 ; V_81 < V_3 -> V_85 ; V_81 ++ ) {
V_34 = & V_3 -> V_6 [ V_81 ] ;
if ( ! V_34 -> V_35 )
continue;
while ( V_34 -> V_35 ) {
V_9 = F_16 ( V_34 ) ;
F_12 ( V_3 , V_81 ) ;
F_42 ( & V_83 , V_9 ) ;
}
V_34 -> V_45 = 0 ;
F_29 ( & V_34 -> V_57 ) ;
V_3 -> V_47 [ V_34 -> V_48 ] = V_49 ;
}
V_3 -> V_46 = NULL ;
while ( ( V_9 = F_43 ( & V_83 ) ) != NULL ) {
unsigned int V_48 = F_2 ( V_3 , V_9 ) ;
T_1 V_30 = V_3 -> V_47 [ V_48 ] ;
V_34 = & V_3 -> V_6 [ V_30 ] ;
if ( V_30 == V_49 ) {
V_30 = V_3 -> V_7 [ 0 ] . V_36 ;
if ( V_30 >= V_5 ) {
V_43:
F_22 ( V_13 , V_9 ) ;
F_23 ( V_9 ) ;
V_84 ++ ;
continue;
}
V_3 -> V_47 [ V_48 ] = V_30 ;
V_34 = & V_3 -> V_6 [ V_30 ] ;
V_34 -> V_48 = V_48 ;
}
if ( V_34 -> V_35 >= V_3 -> V_72 )
goto V_43;
F_18 ( V_34 , V_9 ) ;
if ( V_3 -> V_59 )
V_34 -> V_57 . V_60 = F_44 ( V_3 -> V_59 ,
& V_34 -> V_57 ,
V_34 -> V_45 ) ;
V_34 -> V_45 += F_20 ( V_9 ) ;
F_14 ( V_3 , V_30 ) ;
if ( V_34 -> V_35 == 1 ) {
if ( V_3 -> V_46 == NULL ) {
V_34 -> V_36 = V_30 ;
} else {
V_34 -> V_36 = V_3 -> V_46 -> V_36 ;
V_3 -> V_46 -> V_36 = V_30 ;
}
V_3 -> V_46 = V_34 ;
V_34 -> V_75 = V_3 -> V_76 ;
}
}
V_13 -> V_3 . V_35 -= V_84 ;
F_35 ( V_13 , V_84 ) ;
}
static void F_45 ( unsigned long V_86 )
{
struct V_12 * V_13 = (struct V_12 * ) V_86 ;
struct V_2 * V_3 = F_5 ( V_13 ) ;
T_2 * V_87 = F_46 ( F_47 ( V_13 ) ) ;
F_48 ( V_87 ) ;
V_3 -> V_10 = F_49 () ;
if ( ! V_3 -> V_22 && V_3 -> V_46 )
F_40 ( V_13 ) ;
F_50 ( V_87 ) ;
if ( V_3 -> V_88 )
F_51 ( & V_3 -> V_89 , V_90 + V_3 -> V_88 ) ;
}
static int F_52 ( struct V_12 * V_13 , struct V_91 * V_92 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_93 * V_94 = F_53 ( V_92 ) ;
struct V_95 * V_96 = NULL ;
unsigned int V_35 ;
struct V_59 * V_31 = NULL ;
if ( V_92 -> V_97 < F_54 ( sizeof( * V_94 ) ) )
return - V_98 ;
if ( V_92 -> V_97 >= F_54 ( sizeof( * V_96 ) ) )
V_96 = F_53 ( V_92 ) ;
if ( V_94 -> V_11 &&
( ! F_55 ( V_94 -> V_11 ) || V_94 -> V_11 > 65536 ) )
return - V_98 ;
if ( V_96 && V_96 -> V_99 ) {
V_31 = F_56 ( sizeof( * V_31 ) , V_100 ) ;
if ( ! V_31 )
return - V_101 ;
}
F_57 ( V_13 ) ;
if ( V_94 -> V_102 ) {
V_3 -> V_102 = V_94 -> V_102 ;
V_3 -> V_76 = F_38 ( V_3 -> V_102 ) ;
}
V_3 -> V_88 = V_94 -> V_88 * V_103 ;
if ( V_94 -> V_104 )
V_3 -> V_85 = F_58 ( V_105 , V_94 -> V_104 , V_5 ) ;
if ( V_94 -> V_11 ) {
V_3 -> V_11 = V_94 -> V_11 ;
V_3 -> V_85 = F_58 ( V_105 , V_3 -> V_85 , V_3 -> V_11 ) ;
}
if ( V_96 ) {
if ( V_96 -> V_106 )
V_3 -> V_72 = F_58 ( V_105 , V_96 -> V_106 , V_107 ) ;
if ( V_31 ) {
F_59 ( V_3 -> V_59 , V_31 ) ;
F_60 ( V_3 -> V_59 ,
V_96 -> V_99 , V_96 -> V_108 ,
V_96 -> V_109 ,
V_96 -> V_110 , V_96 -> V_111 ,
NULL ,
V_96 -> V_112 ) ;
}
V_3 -> V_50 = V_96 -> V_50 ;
V_3 -> V_44 = V_96 -> V_44 ;
}
if ( V_94 -> V_77 ) {
V_3 -> V_77 = F_58 ( V_105 , V_94 -> V_77 , V_3 -> V_72 * V_3 -> V_85 ) ;
V_3 -> V_85 = F_58 ( V_105 , V_3 -> V_85 , V_3 -> V_77 ) ;
}
V_35 = V_13 -> V_3 . V_35 ;
while ( V_13 -> V_3 . V_35 > V_3 -> V_77 )
F_19 ( V_13 ) ;
F_35 ( V_13 , V_35 - V_13 -> V_3 . V_35 ) ;
F_61 ( & V_3 -> V_89 ) ;
if ( V_3 -> V_88 ) {
F_51 ( & V_3 -> V_89 , V_90 + V_3 -> V_88 ) ;
V_3 -> V_10 = F_49 () ;
}
F_62 ( V_13 ) ;
F_63 ( V_31 ) ;
return 0 ;
}
static void * F_64 ( T_3 V_113 )
{
void * V_114 = F_56 ( V_113 , V_100 | V_115 ) ;
if ( ! V_114 )
V_114 = F_65 ( V_113 ) ;
return V_114 ;
}
static void F_66 ( void * V_116 )
{
F_67 ( V_116 ) ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
F_69 ( & V_3 -> V_22 ) ;
V_3 -> V_88 = 0 ;
F_70 ( & V_3 -> V_89 ) ;
F_66 ( V_3 -> V_47 ) ;
F_66 ( V_3 -> V_6 ) ;
F_63 ( V_3 -> V_59 ) ;
}
static int F_71 ( struct V_12 * V_13 , struct V_91 * V_92 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
int V_81 ;
V_3 -> V_89 . V_117 = F_45 ;
V_3 -> V_89 . V_118 = ( unsigned long ) V_13 ;
F_72 ( & V_3 -> V_89 ) ;
for ( V_81 = 0 ; V_81 < V_107 + 1 ; V_81 ++ ) {
V_3 -> V_7 [ V_81 ] . V_36 = V_81 + V_5 ;
V_3 -> V_7 [ V_81 ] . V_37 = V_81 + V_5 ;
}
V_3 -> V_77 = V_107 ;
V_3 -> V_72 = V_107 ;
V_3 -> V_39 = 0 ;
V_3 -> V_46 = NULL ;
V_3 -> V_11 = V_119 ;
V_3 -> V_85 = V_120 ;
V_3 -> V_102 = F_73 ( F_74 ( V_13 ) ) ;
V_3 -> V_76 = F_38 ( V_3 -> V_102 ) ;
V_3 -> V_88 = 0 ;
V_3 -> V_10 = F_49 () ;
if ( V_92 ) {
int V_121 = F_52 ( V_13 , V_92 ) ;
if ( V_121 )
return V_121 ;
}
V_3 -> V_47 = F_64 ( sizeof( V_3 -> V_47 [ 0 ] ) * V_3 -> V_11 ) ;
V_3 -> V_6 = F_64 ( sizeof( V_3 -> V_6 [ 0 ] ) * V_3 -> V_85 ) ;
if ( ! V_3 -> V_47 || ! V_3 -> V_6 ) {
F_68 ( V_13 ) ;
return - V_101 ;
}
for ( V_81 = 0 ; V_81 < V_3 -> V_11 ; V_81 ++ )
V_3 -> V_47 [ V_81 ] = V_49 ;
for ( V_81 = 0 ; V_81 < V_3 -> V_85 ; V_81 ++ ) {
F_17 ( & V_3 -> V_6 [ V_81 ] ) ;
F_11 ( V_3 , V_81 ) ;
}
if ( V_3 -> V_77 >= 1 )
V_13 -> V_50 |= V_122 ;
else
V_13 -> V_50 &= ~ V_122 ;
return 0 ;
}
static int F_75 ( struct V_12 * V_13 , struct V_8 * V_9 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
unsigned char * V_123 = F_76 ( V_9 ) ;
struct V_95 V_92 ;
struct V_59 * V_31 = V_3 -> V_59 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_124 . V_102 = V_3 -> V_102 ;
V_92 . V_124 . V_88 = V_3 -> V_88 / V_103 ;
V_92 . V_124 . V_77 = V_3 -> V_77 ;
V_92 . V_124 . V_11 = V_3 -> V_11 ;
V_92 . V_124 . V_104 = V_3 -> V_85 ;
V_92 . V_106 = V_3 -> V_72 ;
V_92 . V_44 = V_3 -> V_44 ;
if ( V_31 ) {
V_92 . V_99 = V_31 -> V_99 >> V_31 -> V_109 ;
V_92 . V_108 = V_31 -> V_108 >> V_31 -> V_109 ;
V_92 . V_109 = V_31 -> V_109 ;
V_92 . V_110 = V_31 -> V_110 ;
V_92 . V_111 = V_31 -> V_111 ;
V_92 . V_112 = V_31 -> V_112 ;
}
memcpy ( & V_92 . V_63 , & V_3 -> V_63 , sizeof( V_92 . V_63 ) ) ;
V_92 . V_50 = V_3 -> V_50 ;
if ( F_77 ( V_9 , V_125 , sizeof( V_92 ) , & V_92 ) )
goto V_126;
return V_9 -> V_42 ;
V_126:
F_78 ( V_9 , V_123 ) ;
return - 1 ;
}
static struct V_12 * F_79 ( struct V_12 * V_13 , unsigned long V_86 )
{
return NULL ;
}
static unsigned long F_80 ( struct V_12 * V_13 , V_105 V_29 )
{
return 0 ;
}
static unsigned long F_81 ( struct V_12 * V_13 , unsigned long V_127 ,
V_105 V_29 )
{
V_13 -> V_50 &= ~ V_122 ;
return 0 ;
}
static void F_82 ( struct V_12 * V_3 , unsigned long V_128 )
{
}
static struct V_17 T_4 * * F_83 ( struct V_12 * V_13 ,
unsigned long V_128 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
if ( V_128 )
return NULL ;
return & V_3 -> V_22 ;
}
static int F_84 ( struct V_12 * V_13 , unsigned long V_128 ,
struct V_8 * V_9 , struct V_129 * V_130 )
{
V_130 -> V_131 |= F_7 ( V_128 ) ;
return 0 ;
}
static int F_85 ( struct V_12 * V_13 , unsigned long V_128 ,
struct V_132 * V_38 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
T_1 V_133 = V_3 -> V_47 [ V_128 - 1 ] ;
struct V_134 V_135 = { 0 } ;
struct V_136 V_137 = { 0 } ;
if ( V_133 != V_49 ) {
const struct V_33 * V_34 = & V_3 -> V_6 [ V_133 ] ;
V_137 . V_75 = V_34 -> V_75 << V_138 ;
V_135 . V_35 = V_34 -> V_35 ;
V_135 . V_45 = V_34 -> V_45 ;
}
if ( F_86 ( V_38 , NULL , & V_135 , V_135 . V_35 ) < 0 )
return - 1 ;
return F_87 ( V_38 , & V_137 , sizeof( V_137 ) ) ;
}
static void F_88 ( struct V_12 * V_13 , struct V_139 * V_86 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
unsigned int V_81 ;
if ( V_86 -> V_140 )
return;
for ( V_81 = 0 ; V_81 < V_3 -> V_11 ; V_81 ++ ) {
if ( V_3 -> V_47 [ V_81 ] == V_49 ||
V_86 -> V_141 < V_86 -> V_142 ) {
V_86 -> V_141 ++ ;
continue;
}
if ( V_86 -> V_143 ( V_13 , V_81 + 1 , V_86 ) < 0 ) {
V_86 -> V_140 = 1 ;
break;
}
V_86 -> V_141 ++ ;
}
}
static int T_5 F_89 ( void )
{
return F_90 ( & V_144 ) ;
}
static void T_6 F_91 ( void )
{
F_92 ( & V_144 ) ;
}
