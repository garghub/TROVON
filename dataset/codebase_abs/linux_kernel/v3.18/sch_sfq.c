static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
if ( V_4 < V_5 )
return & V_3 -> V_6 [ V_4 ] . V_7 ;
return & V_3 -> V_7 [ V_4 - V_5 ] ;
}
static inline struct V_8 * V_8 ( const struct V_9 * V_10 )
{
F_2 ( V_10 , sizeof( struct V_8 ) ) ;
return (struct V_8 * ) F_3 ( V_10 ) -> V_11 ;
}
static unsigned int F_4 ( const struct V_2 * V_3 ,
const struct V_9 * V_10 )
{
const struct V_12 * V_13 = & V_8 ( V_10 ) -> V_13 ;
unsigned int V_14 ;
V_14 = F_5 ( ( V_15 V_16 ) V_13 -> V_17 ,
( V_15 V_16 ) V_13 -> V_18 ^ V_13 -> V_19 ,
( V_15 V_16 ) V_13 -> V_20 , V_3 -> V_21 ) ;
return V_14 & ( V_3 -> V_22 - 1 ) ;
}
static unsigned int F_6 ( struct V_9 * V_10 , struct V_23 * V_24 ,
int * V_25 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_26 V_27 ;
struct V_28 * V_29 ;
int V_30 ;
if ( F_8 ( V_10 -> V_31 ) == V_24 -> V_32 &&
F_9 ( V_10 -> V_31 ) > 0 &&
F_9 ( V_10 -> V_31 ) <= V_3 -> V_22 )
return F_9 ( V_10 -> V_31 ) ;
V_29 = F_10 ( V_3 -> V_33 ) ;
if ( ! V_29 ) {
F_11 ( V_10 , & V_8 ( V_10 ) -> V_13 ) ;
return F_4 ( V_3 , V_10 ) + 1 ;
}
* V_25 = V_34 | V_35 ;
V_30 = F_12 ( V_10 , V_29 , & V_27 ) ;
if ( V_30 >= 0 ) {
#ifdef F_13
switch ( V_30 ) {
case V_36 :
case V_37 :
* V_25 = V_34 | V_38 ;
case V_39 :
return 0 ;
}
#endif
if ( F_9 ( V_27 . V_40 ) <= V_3 -> V_22 )
return F_9 ( V_27 . V_40 ) ;
}
return 0 ;
}
static inline void F_14 ( struct V_2 * V_3 , T_1 V_41 )
{
T_1 V_42 , V_43 ;
struct V_44 * V_45 = & V_3 -> V_6 [ V_41 ] ;
int V_46 = V_45 -> V_46 ;
V_42 = V_46 + V_5 ;
V_43 = V_3 -> V_7 [ V_46 ] . V_47 ;
V_45 -> V_7 . V_47 = V_43 ;
V_45 -> V_7 . V_48 = V_42 ;
V_3 -> V_7 [ V_46 ] . V_47 = V_41 ;
F_1 ( V_3 , V_43 ) -> V_48 = V_41 ;
}
static inline void F_15 ( struct V_2 * V_3 , T_1 V_41 )
{
T_1 V_42 , V_43 ;
int V_49 ;
F_16 ( V_3 , V_41 , V_43 , V_42 ) ;
V_49 = V_3 -> V_6 [ V_41 ] . V_46 -- ;
if ( V_43 == V_42 && V_3 -> V_50 == V_49 )
V_3 -> V_50 -- ;
F_14 ( V_3 , V_41 ) ;
}
static inline void F_17 ( struct V_2 * V_3 , T_1 V_41 )
{
T_1 V_42 , V_43 ;
int V_49 ;
F_16 ( V_3 , V_41 , V_43 , V_42 ) ;
V_49 = ++ V_3 -> V_6 [ V_41 ] . V_46 ;
if ( V_3 -> V_50 < V_49 )
V_3 -> V_50 = V_49 ;
F_14 ( V_3 , V_41 ) ;
}
static inline struct V_9 * F_18 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = V_45 -> V_51 ;
V_45 -> V_51 = V_10 -> V_48 ;
V_10 -> V_48 -> V_47 = (struct V_9 * ) V_45 ;
V_10 -> V_47 = V_10 -> V_48 = NULL ;
return V_10 ;
}
static inline struct V_9 * F_19 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = V_45 -> V_52 ;
V_45 -> V_52 = V_10 -> V_47 ;
V_10 -> V_47 -> V_48 = (struct V_9 * ) V_45 ;
V_10 -> V_47 = V_10 -> V_48 = NULL ;
return V_10 ;
}
static inline void F_20 ( struct V_44 * V_45 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_51 = V_45 -> V_52 = (struct V_9 * ) V_45 ;
}
static inline void F_21 ( struct V_44 * V_45 , struct V_9 * V_10 )
{
V_10 -> V_48 = V_45 -> V_51 ;
V_10 -> V_47 = (struct V_9 * ) V_45 ;
V_45 -> V_51 -> V_47 = V_10 ;
V_45 -> V_51 = V_10 ;
}
static unsigned int F_22 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
T_1 V_41 , V_49 = V_3 -> V_50 ;
struct V_9 * V_10 ;
unsigned int V_53 ;
struct V_44 * V_45 ;
if ( V_49 > 1 ) {
V_41 = V_3 -> V_7 [ V_49 ] . V_47 ;
V_45 = & V_3 -> V_6 [ V_41 ] ;
V_54:
V_10 = V_3 -> V_55 ? F_19 ( V_45 ) : F_18 ( V_45 ) ;
V_53 = F_23 ( V_10 ) ;
V_45 -> V_56 -= V_53 ;
F_15 ( V_3 , V_41 ) ;
F_24 ( V_10 ) ;
V_24 -> V_3 . V_46 -- ;
F_25 ( V_24 ) ;
F_26 ( V_24 , V_10 ) ;
return V_53 ;
}
if ( V_49 == 1 ) {
V_41 = V_3 -> V_57 -> V_47 ;
V_45 = & V_3 -> V_6 [ V_41 ] ;
V_3 -> V_57 -> V_47 = V_45 -> V_47 ;
V_3 -> V_58 [ V_45 -> V_14 ] = V_59 ;
goto V_54;
}
return 0 ;
}
static int F_27 ( const struct V_2 * V_3 )
{
return V_3 -> V_60 & V_61 ;
}
static int F_28 ( const struct V_2 * V_3 )
{
return ( V_3 -> V_60 & ( V_61 | V_62 ) ) == V_61 ;
}
static int F_29 ( const struct V_2 * V_3 )
{
return V_3 -> V_55 ;
}
static int
F_30 ( struct V_9 * V_10 , struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
unsigned int V_14 ;
T_1 V_41 , V_46 ;
struct V_44 * V_45 ;
int V_63 ( V_64 ) ;
struct V_9 * V_65 ;
int V_66 ;
V_14 = F_6 ( V_10 , V_24 , & V_64 ) ;
if ( V_14 == 0 ) {
if ( V_64 & V_35 )
F_25 ( V_24 ) ;
F_24 ( V_10 ) ;
return V_64 ;
}
V_14 -- ;
V_41 = V_3 -> V_58 [ V_14 ] ;
V_45 = & V_3 -> V_6 [ V_41 ] ;
if ( V_41 == V_59 ) {
V_41 = V_3 -> V_7 [ 0 ] . V_47 ;
if ( V_41 >= V_5 )
return F_31 ( V_10 , V_24 ) ;
V_3 -> V_58 [ V_14 ] = V_41 ;
V_45 = & V_3 -> V_6 [ V_41 ] ;
V_45 -> V_14 = V_14 ;
V_45 -> V_56 = 0 ;
F_32 ( & V_45 -> V_67 ) ;
goto V_68;
}
if ( V_3 -> V_69 ) {
V_45 -> V_67 . V_70 = F_33 ( V_3 -> V_69 ,
& V_45 -> V_67 ,
V_45 -> V_56 ) ;
switch ( F_34 ( V_3 -> V_69 ,
& V_45 -> V_67 ,
V_45 -> V_67 . V_70 ) ) {
case V_71 :
break;
case V_72 :
F_35 ( V_24 ) ;
if ( F_27 ( V_3 ) ) {
if ( F_29 ( V_3 ) &&
F_36 ( V_45 -> V_52 ) ) {
V_3 -> V_73 . V_74 ++ ;
break;
}
if ( F_36 ( V_10 ) ) {
V_3 -> V_73 . V_75 ++ ;
break;
}
}
V_3 -> V_73 . V_76 ++ ;
goto V_77;
case V_78 :
F_35 ( V_24 ) ;
if ( F_28 ( V_3 ) ) {
if ( F_29 ( V_3 ) &&
F_36 ( V_45 -> V_52 ) ) {
V_3 -> V_73 . V_79 ++ ;
break;
}
if ( F_36 ( V_10 ) ) {
V_3 -> V_73 . V_80 ++ ;
break;
}
}
V_3 -> V_73 . V_81 ++ ;
goto V_77;
}
}
if ( V_45 -> V_46 >= V_3 -> V_82 ) {
V_77:
if ( ! F_29 ( V_3 ) )
return F_31 ( V_10 , V_24 ) ;
V_65 = F_19 ( V_45 ) ;
V_66 = F_23 ( V_65 ) - F_23 ( V_10 ) ;
V_24 -> V_83 . V_56 -= V_66 ;
V_45 -> V_56 -= V_66 ;
F_31 ( V_65 , V_24 ) ;
F_21 ( V_45 , V_10 ) ;
return V_84 ;
}
V_68:
F_37 ( V_24 , V_10 ) ;
V_45 -> V_56 += F_23 ( V_10 ) ;
F_21 ( V_45 , V_10 ) ;
F_17 ( V_3 , V_41 ) ;
if ( V_45 -> V_46 == 1 ) {
if ( V_3 -> V_57 == NULL ) {
V_45 -> V_47 = V_41 ;
} else {
V_45 -> V_47 = V_3 -> V_57 -> V_47 ;
V_3 -> V_57 -> V_47 = V_41 ;
}
V_3 -> V_57 = V_45 ;
V_45 -> V_85 = V_3 -> V_86 ;
}
if ( ++ V_24 -> V_3 . V_46 <= V_3 -> V_87 )
return V_34 ;
V_46 = V_45 -> V_46 ;
F_22 ( V_24 ) ;
if ( V_46 != V_45 -> V_46 )
return V_84 ;
F_38 ( V_24 , 1 ) ;
return V_34 ;
}
static struct V_9 *
F_39 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_9 * V_10 ;
T_1 V_88 , V_89 ;
struct V_44 * V_45 ;
if ( V_3 -> V_57 == NULL )
return NULL ;
V_90:
V_88 = V_3 -> V_57 -> V_47 ;
V_45 = & V_3 -> V_6 [ V_88 ] ;
if ( V_45 -> V_85 <= 0 ) {
V_3 -> V_57 = V_45 ;
V_45 -> V_85 += V_3 -> V_86 ;
goto V_90;
}
V_10 = F_19 ( V_45 ) ;
F_15 ( V_3 , V_88 ) ;
F_40 ( V_24 , V_10 ) ;
V_24 -> V_3 . V_46 -- ;
F_26 ( V_24 , V_10 ) ;
V_45 -> V_56 -= F_23 ( V_10 ) ;
if ( V_45 -> V_46 == 0 ) {
V_3 -> V_58 [ V_45 -> V_14 ] = V_59 ;
V_89 = V_45 -> V_47 ;
if ( V_88 == V_89 ) {
V_3 -> V_57 = NULL ;
return V_10 ;
}
V_3 -> V_57 -> V_47 = V_89 ;
} else {
V_45 -> V_85 -= F_41 ( F_23 ( V_10 ) ) ;
}
return V_10 ;
}
static void
F_42 ( struct V_23 * V_24 )
{
struct V_9 * V_10 ;
while ( ( V_10 = F_39 ( V_24 ) ) != NULL )
F_24 ( V_10 ) ;
}
static void F_43 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_9 * V_10 ;
int V_91 ;
struct V_44 * V_45 ;
struct V_92 V_93 ;
int V_94 = 0 ;
F_44 ( & V_93 ) ;
for ( V_91 = 0 ; V_91 < V_3 -> V_95 ; V_91 ++ ) {
V_45 = & V_3 -> V_6 [ V_91 ] ;
if ( ! V_45 -> V_46 )
continue;
while ( V_45 -> V_46 ) {
V_10 = F_19 ( V_45 ) ;
F_15 ( V_3 , V_91 ) ;
F_45 ( & V_93 , V_10 ) ;
}
V_45 -> V_56 = 0 ;
F_32 ( & V_45 -> V_67 ) ;
V_3 -> V_58 [ V_45 -> V_14 ] = V_59 ;
}
V_3 -> V_57 = NULL ;
while ( ( V_10 = F_46 ( & V_93 ) ) != NULL ) {
unsigned int V_14 = F_4 ( V_3 , V_10 ) ;
T_1 V_41 = V_3 -> V_58 [ V_14 ] ;
V_45 = & V_3 -> V_6 [ V_41 ] ;
if ( V_41 == V_59 ) {
V_41 = V_3 -> V_7 [ 0 ] . V_47 ;
if ( V_41 >= V_5 ) {
V_54:
F_26 ( V_24 , V_10 ) ;
F_24 ( V_10 ) ;
V_94 ++ ;
continue;
}
V_3 -> V_58 [ V_14 ] = V_41 ;
V_45 = & V_3 -> V_6 [ V_41 ] ;
V_45 -> V_14 = V_14 ;
}
if ( V_45 -> V_46 >= V_3 -> V_82 )
goto V_54;
F_21 ( V_45 , V_10 ) ;
if ( V_3 -> V_69 )
V_45 -> V_67 . V_70 = F_47 ( V_3 -> V_69 ,
& V_45 -> V_67 ,
V_45 -> V_56 ) ;
V_45 -> V_56 += F_23 ( V_10 ) ;
F_17 ( V_3 , V_41 ) ;
if ( V_45 -> V_46 == 1 ) {
if ( V_3 -> V_57 == NULL ) {
V_45 -> V_47 = V_41 ;
} else {
V_45 -> V_47 = V_3 -> V_57 -> V_47 ;
V_3 -> V_57 -> V_47 = V_41 ;
}
V_3 -> V_57 = V_45 ;
V_45 -> V_85 = V_3 -> V_86 ;
}
}
V_24 -> V_3 . V_46 -= V_94 ;
F_38 ( V_24 , V_94 ) ;
}
static void F_48 ( unsigned long V_96 )
{
struct V_23 * V_24 = (struct V_23 * ) V_96 ;
struct V_2 * V_3 = F_7 ( V_24 ) ;
T_2 * V_97 = F_49 ( F_50 ( V_24 ) ) ;
F_51 ( V_97 ) ;
V_3 -> V_21 = F_52 () ;
if ( ! V_3 -> V_33 && V_3 -> V_57 )
F_43 ( V_24 ) ;
F_53 ( V_97 ) ;
if ( V_3 -> V_98 )
F_54 ( & V_3 -> V_99 , V_100 + V_3 -> V_98 ) ;
}
static int F_55 ( struct V_23 * V_24 , struct V_101 * V_102 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_103 * V_104 = F_56 ( V_102 ) ;
struct V_105 * V_106 = NULL ;
unsigned int V_46 ;
struct V_69 * V_42 = NULL ;
if ( V_102 -> V_107 < F_57 ( sizeof( * V_104 ) ) )
return - V_108 ;
if ( V_102 -> V_107 >= F_57 ( sizeof( * V_106 ) ) )
V_106 = F_56 ( V_102 ) ;
if ( V_104 -> V_22 &&
( ! F_58 ( V_104 -> V_22 ) || V_104 -> V_22 > 65536 ) )
return - V_108 ;
if ( V_106 && V_106 -> V_109 ) {
V_42 = F_59 ( sizeof( * V_42 ) , V_110 ) ;
if ( ! V_42 )
return - V_111 ;
}
F_60 ( V_24 ) ;
if ( V_104 -> V_112 ) {
V_3 -> V_112 = V_104 -> V_112 ;
V_3 -> V_86 = F_41 ( V_3 -> V_112 ) ;
}
V_3 -> V_98 = V_104 -> V_98 * V_113 ;
if ( V_104 -> V_114 )
V_3 -> V_95 = F_61 ( V_16 , V_104 -> V_114 , V_5 ) ;
if ( V_104 -> V_22 ) {
V_3 -> V_22 = V_104 -> V_22 ;
V_3 -> V_95 = F_61 ( V_16 , V_3 -> V_95 , V_3 -> V_22 ) ;
}
if ( V_106 ) {
if ( V_106 -> V_115 )
V_3 -> V_82 = F_61 ( V_16 , V_106 -> V_115 , V_116 ) ;
if ( V_42 ) {
F_62 ( V_3 -> V_69 , V_42 ) ;
F_63 ( V_3 -> V_69 ,
V_106 -> V_109 , V_106 -> V_117 ,
V_106 -> V_118 ,
V_106 -> V_119 , V_106 -> V_120 ,
NULL ,
V_106 -> V_121 ) ;
}
V_3 -> V_60 = V_106 -> V_60 ;
V_3 -> V_55 = V_106 -> V_55 ;
}
if ( V_104 -> V_87 ) {
V_3 -> V_87 = F_61 ( V_16 , V_104 -> V_87 , V_3 -> V_82 * V_3 -> V_95 ) ;
V_3 -> V_95 = F_61 ( V_16 , V_3 -> V_95 , V_3 -> V_87 ) ;
}
V_46 = V_24 -> V_3 . V_46 ;
while ( V_24 -> V_3 . V_46 > V_3 -> V_87 )
F_22 ( V_24 ) ;
F_38 ( V_24 , V_46 - V_24 -> V_3 . V_46 ) ;
F_64 ( & V_3 -> V_99 ) ;
if ( V_3 -> V_98 ) {
F_54 ( & V_3 -> V_99 , V_100 + V_3 -> V_98 ) ;
V_3 -> V_21 = F_52 () ;
}
F_65 ( V_24 ) ;
F_66 ( V_42 ) ;
return 0 ;
}
static void * F_67 ( T_3 V_122 )
{
void * V_123 = F_59 ( V_122 , V_110 | V_124 ) ;
if ( ! V_123 )
V_123 = F_68 ( V_122 ) ;
return V_123 ;
}
static void F_69 ( void * V_125 )
{
F_70 ( V_125 ) ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
F_72 ( & V_3 -> V_33 ) ;
V_3 -> V_98 = 0 ;
F_73 ( & V_3 -> V_99 ) ;
F_69 ( V_3 -> V_58 ) ;
F_69 ( V_3 -> V_6 ) ;
F_66 ( V_3 -> V_69 ) ;
}
static int F_74 ( struct V_23 * V_24 , struct V_101 * V_102 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
int V_91 ;
V_3 -> V_99 . V_126 = F_48 ;
V_3 -> V_99 . V_11 = ( unsigned long ) V_24 ;
F_75 ( & V_3 -> V_99 ) ;
for ( V_91 = 0 ; V_91 < V_116 + 1 ; V_91 ++ ) {
V_3 -> V_7 [ V_91 ] . V_47 = V_91 + V_5 ;
V_3 -> V_7 [ V_91 ] . V_48 = V_91 + V_5 ;
}
V_3 -> V_87 = V_116 ;
V_3 -> V_82 = V_116 ;
V_3 -> V_50 = 0 ;
V_3 -> V_57 = NULL ;
V_3 -> V_22 = V_127 ;
V_3 -> V_95 = V_128 ;
V_3 -> V_112 = F_76 ( F_77 ( V_24 ) ) ;
V_3 -> V_86 = F_41 ( V_3 -> V_112 ) ;
V_3 -> V_98 = 0 ;
V_3 -> V_21 = F_52 () ;
if ( V_102 ) {
int V_129 = F_55 ( V_24 , V_102 ) ;
if ( V_129 )
return V_129 ;
}
V_3 -> V_58 = F_67 ( sizeof( V_3 -> V_58 [ 0 ] ) * V_3 -> V_22 ) ;
V_3 -> V_6 = F_67 ( sizeof( V_3 -> V_6 [ 0 ] ) * V_3 -> V_95 ) ;
if ( ! V_3 -> V_58 || ! V_3 -> V_6 ) {
F_71 ( V_24 ) ;
return - V_111 ;
}
for ( V_91 = 0 ; V_91 < V_3 -> V_22 ; V_91 ++ )
V_3 -> V_58 [ V_91 ] = V_59 ;
for ( V_91 = 0 ; V_91 < V_3 -> V_95 ; V_91 ++ ) {
F_20 ( & V_3 -> V_6 [ V_91 ] ) ;
F_14 ( V_3 , V_91 ) ;
}
if ( V_3 -> V_87 >= 1 )
V_24 -> V_60 |= V_130 ;
else
V_24 -> V_60 &= ~ V_130 ;
return 0 ;
}
static int F_78 ( struct V_23 * V_24 , struct V_9 * V_10 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
unsigned char * V_131 = F_79 ( V_10 ) ;
struct V_105 V_102 ;
struct V_69 * V_42 = V_3 -> V_69 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_132 . V_112 = V_3 -> V_112 ;
V_102 . V_132 . V_98 = V_3 -> V_98 / V_113 ;
V_102 . V_132 . V_87 = V_3 -> V_87 ;
V_102 . V_132 . V_22 = V_3 -> V_22 ;
V_102 . V_132 . V_114 = V_3 -> V_95 ;
V_102 . V_115 = V_3 -> V_82 ;
V_102 . V_55 = V_3 -> V_55 ;
if ( V_42 ) {
V_102 . V_109 = V_42 -> V_109 >> V_42 -> V_118 ;
V_102 . V_117 = V_42 -> V_117 >> V_42 -> V_118 ;
V_102 . V_118 = V_42 -> V_118 ;
V_102 . V_119 = V_42 -> V_119 ;
V_102 . V_120 = V_42 -> V_120 ;
V_102 . V_121 = V_42 -> V_121 ;
}
memcpy ( & V_102 . V_73 , & V_3 -> V_73 , sizeof( V_102 . V_73 ) ) ;
V_102 . V_60 = V_3 -> V_60 ;
if ( F_80 ( V_10 , V_133 , sizeof( V_102 ) , & V_102 ) )
goto V_134;
return V_10 -> V_53 ;
V_134:
F_81 ( V_10 , V_131 ) ;
return - 1 ;
}
static struct V_23 * F_82 ( struct V_23 * V_24 , unsigned long V_96 )
{
return NULL ;
}
static unsigned long F_83 ( struct V_23 * V_24 , V_16 V_40 )
{
return 0 ;
}
static unsigned long F_84 ( struct V_23 * V_24 , unsigned long V_135 ,
V_16 V_40 )
{
V_24 -> V_60 &= ~ V_130 ;
return 0 ;
}
static void F_85 ( struct V_23 * V_3 , unsigned long V_136 )
{
}
static struct V_28 T_4 * * F_86 ( struct V_23 * V_24 ,
unsigned long V_136 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
if ( V_136 )
return NULL ;
return & V_3 -> V_33 ;
}
static int F_87 ( struct V_23 * V_24 , unsigned long V_136 ,
struct V_9 * V_10 , struct V_137 * V_138 )
{
V_138 -> V_139 |= F_9 ( V_136 ) ;
return 0 ;
}
static int F_88 ( struct V_23 * V_24 , unsigned long V_136 ,
struct V_140 * V_49 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
T_1 V_141 = V_3 -> V_58 [ V_136 - 1 ] ;
struct V_142 V_143 = { 0 } ;
struct V_144 V_145 = { 0 } ;
if ( V_141 != V_59 ) {
const struct V_44 * V_45 = & V_3 -> V_6 [ V_141 ] ;
V_145 . V_85 = V_45 -> V_85 << V_146 ;
V_143 . V_46 = V_45 -> V_46 ;
V_143 . V_56 = V_45 -> V_56 ;
}
if ( F_89 ( V_49 , NULL , & V_143 , V_143 . V_46 ) < 0 )
return - 1 ;
return F_90 ( V_49 , & V_145 , sizeof( V_145 ) ) ;
}
static void F_91 ( struct V_23 * V_24 , struct V_147 * V_96 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
unsigned int V_91 ;
if ( V_96 -> V_148 )
return;
for ( V_91 = 0 ; V_91 < V_3 -> V_22 ; V_91 ++ ) {
if ( V_3 -> V_58 [ V_91 ] == V_59 ||
V_96 -> V_149 < V_96 -> V_150 ) {
V_96 -> V_149 ++ ;
continue;
}
if ( V_96 -> V_151 ( V_24 , V_91 + 1 , V_96 ) < 0 ) {
V_96 -> V_148 = 1 ;
break;
}
V_96 -> V_149 ++ ;
}
}
static int T_5 F_92 ( void )
{
return F_93 ( & V_152 ) ;
}
static void T_6 F_94 ( void )
{
F_95 ( & V_152 ) ;
}
