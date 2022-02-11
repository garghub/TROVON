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
int V_28 ;
if ( F_8 ( V_10 -> V_29 ) == V_24 -> V_30 &&
F_9 ( V_10 -> V_29 ) > 0 &&
F_9 ( V_10 -> V_29 ) <= V_3 -> V_22 )
return F_9 ( V_10 -> V_29 ) ;
if ( ! V_3 -> V_31 ) {
F_10 ( V_10 , & V_8 ( V_10 ) -> V_13 ) ;
return F_4 ( V_3 , V_10 ) + 1 ;
}
* V_25 = V_32 | V_33 ;
V_28 = F_11 ( V_10 , V_3 -> V_31 , & V_27 ) ;
if ( V_28 >= 0 ) {
#ifdef F_12
switch ( V_28 ) {
case V_34 :
case V_35 :
* V_25 = V_32 | V_36 ;
case V_37 :
return 0 ;
}
#endif
if ( F_9 ( V_27 . V_38 ) <= V_3 -> V_22 )
return F_9 ( V_27 . V_38 ) ;
}
return 0 ;
}
static inline void F_13 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_40 , V_41 ;
struct V_42 * V_43 = & V_3 -> V_6 [ V_39 ] ;
int V_44 = V_43 -> V_44 ;
V_40 = V_44 + V_5 ;
V_41 = V_3 -> V_7 [ V_44 ] . V_45 ;
V_43 -> V_7 . V_45 = V_41 ;
V_43 -> V_7 . V_46 = V_40 ;
V_3 -> V_7 [ V_44 ] . V_45 = V_39 ;
F_1 ( V_3 , V_41 ) -> V_46 = V_39 ;
}
static inline void F_14 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_40 , V_41 ;
int V_47 ;
F_15 ( V_3 , V_39 , V_41 , V_40 ) ;
V_47 = V_3 -> V_6 [ V_39 ] . V_44 -- ;
if ( V_41 == V_40 && V_3 -> V_48 == V_47 )
V_3 -> V_48 -- ;
F_13 ( V_3 , V_39 ) ;
}
static inline void F_16 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_40 , V_41 ;
int V_47 ;
F_15 ( V_3 , V_39 , V_41 , V_40 ) ;
V_47 = ++ V_3 -> V_6 [ V_39 ] . V_44 ;
if ( V_3 -> V_48 < V_47 )
V_3 -> V_48 = V_47 ;
F_13 ( V_3 , V_39 ) ;
}
static inline struct V_9 * F_17 ( struct V_42 * V_43 )
{
struct V_9 * V_10 = V_43 -> V_49 ;
V_43 -> V_49 = V_10 -> V_46 ;
V_10 -> V_46 -> V_45 = (struct V_9 * ) V_43 ;
V_10 -> V_45 = V_10 -> V_46 = NULL ;
return V_10 ;
}
static inline struct V_9 * F_18 ( struct V_42 * V_43 )
{
struct V_9 * V_10 = V_43 -> V_50 ;
V_43 -> V_50 = V_10 -> V_45 ;
V_10 -> V_45 -> V_46 = (struct V_9 * ) V_43 ;
V_10 -> V_45 = V_10 -> V_46 = NULL ;
return V_10 ;
}
static inline void F_19 ( struct V_42 * V_43 )
{
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_49 = V_43 -> V_50 = (struct V_9 * ) V_43 ;
}
static inline void F_20 ( struct V_42 * V_43 , struct V_9 * V_10 )
{
V_10 -> V_46 = V_43 -> V_49 ;
V_10 -> V_45 = (struct V_9 * ) V_43 ;
V_43 -> V_49 -> V_45 = V_10 ;
V_43 -> V_49 = V_10 ;
}
static unsigned int F_21 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
T_1 V_39 , V_47 = V_3 -> V_48 ;
struct V_9 * V_10 ;
unsigned int V_51 ;
struct V_42 * V_43 ;
if ( V_47 > 1 ) {
V_39 = V_3 -> V_7 [ V_47 ] . V_45 ;
V_43 = & V_3 -> V_6 [ V_39 ] ;
V_52:
V_10 = V_3 -> V_53 ? F_18 ( V_43 ) : F_17 ( V_43 ) ;
V_51 = F_22 ( V_10 ) ;
V_43 -> V_54 -= V_51 ;
F_14 ( V_3 , V_39 ) ;
F_23 ( V_10 ) ;
V_24 -> V_3 . V_44 -- ;
V_24 -> V_55 . V_56 ++ ;
V_24 -> V_55 . V_54 -= V_51 ;
return V_51 ;
}
if ( V_47 == 1 ) {
V_39 = V_3 -> V_57 -> V_45 ;
V_43 = & V_3 -> V_6 [ V_39 ] ;
V_3 -> V_57 -> V_45 = V_43 -> V_45 ;
V_3 -> V_58 [ V_43 -> V_14 ] = V_59 ;
goto V_52;
}
return 0 ;
}
static int F_24 ( const struct V_2 * V_3 )
{
return V_3 -> V_60 & V_61 ;
}
static int F_25 ( const struct V_2 * V_3 )
{
return ( V_3 -> V_60 & ( V_61 | V_62 ) ) == V_61 ;
}
static int F_26 ( const struct V_2 * V_3 )
{
return V_3 -> V_53 ;
}
static int
F_27 ( struct V_9 * V_10 , struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
unsigned int V_14 ;
T_1 V_39 , V_44 ;
struct V_42 * V_43 ;
int V_63 ( V_64 ) ;
struct V_9 * V_65 ;
int V_66 ;
V_14 = F_6 ( V_10 , V_24 , & V_64 ) ;
if ( V_14 == 0 ) {
if ( V_64 & V_33 )
V_24 -> V_55 . V_56 ++ ;
F_23 ( V_10 ) ;
return V_64 ;
}
V_14 -- ;
V_39 = V_3 -> V_58 [ V_14 ] ;
V_43 = & V_3 -> V_6 [ V_39 ] ;
if ( V_39 == V_59 ) {
V_39 = V_3 -> V_7 [ 0 ] . V_45 ;
if ( V_39 >= V_5 )
return F_28 ( V_10 , V_24 ) ;
V_3 -> V_58 [ V_14 ] = V_39 ;
V_43 = & V_3 -> V_6 [ V_39 ] ;
V_43 -> V_14 = V_14 ;
V_43 -> V_54 = 0 ;
F_29 ( & V_43 -> V_67 ) ;
goto V_68;
}
if ( V_3 -> V_69 ) {
V_43 -> V_67 . V_70 = F_30 ( V_3 -> V_69 ,
& V_43 -> V_67 ,
V_43 -> V_54 ) ;
switch ( F_31 ( V_3 -> V_69 ,
& V_43 -> V_67 ,
V_43 -> V_67 . V_70 ) ) {
case V_71 :
break;
case V_72 :
V_24 -> V_55 . V_73 ++ ;
if ( F_24 ( V_3 ) ) {
if ( F_26 ( V_3 ) &&
F_32 ( V_43 -> V_50 ) ) {
V_3 -> V_74 . V_75 ++ ;
break;
}
if ( F_32 ( V_10 ) ) {
V_3 -> V_74 . V_76 ++ ;
break;
}
}
V_3 -> V_74 . V_77 ++ ;
goto V_78;
case V_79 :
V_24 -> V_55 . V_73 ++ ;
if ( F_25 ( V_3 ) ) {
if ( F_26 ( V_3 ) &&
F_32 ( V_43 -> V_50 ) ) {
V_3 -> V_74 . V_80 ++ ;
break;
}
if ( F_32 ( V_10 ) ) {
V_3 -> V_74 . V_81 ++ ;
break;
}
}
V_3 -> V_74 . V_82 ++ ;
goto V_78;
}
}
if ( V_43 -> V_44 >= V_3 -> V_83 ) {
V_78:
if ( ! F_26 ( V_3 ) )
return F_28 ( V_10 , V_24 ) ;
V_65 = F_18 ( V_43 ) ;
V_66 = F_22 ( V_65 ) - F_22 ( V_10 ) ;
V_24 -> V_55 . V_54 -= V_66 ;
V_43 -> V_54 -= V_66 ;
F_28 ( V_65 , V_24 ) ;
F_20 ( V_43 , V_10 ) ;
return V_84 ;
}
V_68:
V_24 -> V_55 . V_54 += F_22 ( V_10 ) ;
V_43 -> V_54 += F_22 ( V_10 ) ;
F_20 ( V_43 , V_10 ) ;
F_16 ( V_3 , V_39 ) ;
if ( V_43 -> V_44 == 1 ) {
if ( V_3 -> V_57 == NULL ) {
V_43 -> V_45 = V_39 ;
} else {
V_43 -> V_45 = V_3 -> V_57 -> V_45 ;
V_3 -> V_57 -> V_45 = V_39 ;
}
V_3 -> V_57 = V_43 ;
V_43 -> V_85 = V_3 -> V_86 ;
}
if ( ++ V_24 -> V_3 . V_44 <= V_3 -> V_87 )
return V_32 ;
V_44 = V_43 -> V_44 ;
F_21 ( V_24 ) ;
if ( V_44 != V_43 -> V_44 )
return V_84 ;
F_33 ( V_24 , 1 ) ;
return V_32 ;
}
static struct V_9 *
F_34 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_9 * V_10 ;
T_1 V_88 , V_89 ;
struct V_42 * V_43 ;
if ( V_3 -> V_57 == NULL )
return NULL ;
V_90:
V_88 = V_3 -> V_57 -> V_45 ;
V_43 = & V_3 -> V_6 [ V_88 ] ;
if ( V_43 -> V_85 <= 0 ) {
V_3 -> V_57 = V_43 ;
V_43 -> V_85 += V_3 -> V_86 ;
goto V_90;
}
V_10 = F_18 ( V_43 ) ;
F_14 ( V_3 , V_88 ) ;
F_35 ( V_24 , V_10 ) ;
V_24 -> V_3 . V_44 -- ;
V_24 -> V_55 . V_54 -= F_22 ( V_10 ) ;
V_43 -> V_54 -= F_22 ( V_10 ) ;
if ( V_43 -> V_44 == 0 ) {
V_3 -> V_58 [ V_43 -> V_14 ] = V_59 ;
V_89 = V_43 -> V_45 ;
if ( V_88 == V_89 ) {
V_3 -> V_57 = NULL ;
return V_10 ;
}
V_3 -> V_57 -> V_45 = V_89 ;
} else {
V_43 -> V_85 -= F_36 ( F_22 ( V_10 ) ) ;
}
return V_10 ;
}
static void
F_37 ( struct V_23 * V_24 )
{
struct V_9 * V_10 ;
while ( ( V_10 = F_34 ( V_24 ) ) != NULL )
F_23 ( V_10 ) ;
}
static void F_38 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_9 * V_10 ;
int V_91 ;
struct V_42 * V_43 ;
struct V_92 V_93 ;
int V_94 = 0 ;
F_39 ( & V_93 ) ;
for ( V_91 = 0 ; V_91 < V_3 -> V_95 ; V_91 ++ ) {
V_43 = & V_3 -> V_6 [ V_91 ] ;
if ( ! V_43 -> V_44 )
continue;
while ( V_43 -> V_44 ) {
V_10 = F_18 ( V_43 ) ;
F_14 ( V_3 , V_91 ) ;
F_40 ( & V_93 , V_10 ) ;
}
V_43 -> V_54 = 0 ;
F_29 ( & V_43 -> V_67 ) ;
V_3 -> V_58 [ V_43 -> V_14 ] = V_59 ;
}
V_3 -> V_57 = NULL ;
while ( ( V_10 = F_41 ( & V_93 ) ) != NULL ) {
unsigned int V_14 = F_4 ( V_3 , V_10 ) ;
T_1 V_39 = V_3 -> V_58 [ V_14 ] ;
V_43 = & V_3 -> V_6 [ V_39 ] ;
if ( V_39 == V_59 ) {
V_39 = V_3 -> V_7 [ 0 ] . V_45 ;
if ( V_39 >= V_5 ) {
V_52: V_24 -> V_55 . V_54 -= F_22 ( V_10 ) ;
F_23 ( V_10 ) ;
V_94 ++ ;
continue;
}
V_3 -> V_58 [ V_14 ] = V_39 ;
V_43 = & V_3 -> V_6 [ V_39 ] ;
V_43 -> V_14 = V_14 ;
}
if ( V_43 -> V_44 >= V_3 -> V_83 )
goto V_52;
F_20 ( V_43 , V_10 ) ;
if ( V_3 -> V_69 )
V_43 -> V_67 . V_70 = F_42 ( V_3 -> V_69 ,
& V_43 -> V_67 ,
V_43 -> V_54 ) ;
V_43 -> V_54 += F_22 ( V_10 ) ;
F_16 ( V_3 , V_39 ) ;
if ( V_43 -> V_44 == 1 ) {
if ( V_3 -> V_57 == NULL ) {
V_43 -> V_45 = V_39 ;
} else {
V_43 -> V_45 = V_3 -> V_57 -> V_45 ;
V_3 -> V_57 -> V_45 = V_39 ;
}
V_3 -> V_57 = V_43 ;
V_43 -> V_85 = V_3 -> V_86 ;
}
}
V_24 -> V_3 . V_44 -= V_94 ;
F_33 ( V_24 , V_94 ) ;
}
static void F_43 ( unsigned long V_96 )
{
struct V_23 * V_24 = (struct V_23 * ) V_96 ;
struct V_2 * V_3 = F_7 ( V_24 ) ;
T_2 * V_97 = F_44 ( F_45 ( V_24 ) ) ;
F_46 ( V_97 ) ;
V_3 -> V_21 = F_47 () ;
if ( ! V_3 -> V_31 && V_3 -> V_57 )
F_38 ( V_24 ) ;
F_48 ( V_97 ) ;
if ( V_3 -> V_98 )
F_49 ( & V_3 -> V_99 , V_100 + V_3 -> V_98 ) ;
}
static int F_50 ( struct V_23 * V_24 , struct V_101 * V_102 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
struct V_105 * V_106 = NULL ;
unsigned int V_44 ;
struct V_69 * V_40 = NULL ;
if ( V_102 -> V_107 < F_52 ( sizeof( * V_104 ) ) )
return - V_108 ;
if ( V_102 -> V_107 >= F_52 ( sizeof( * V_106 ) ) )
V_106 = F_51 ( V_102 ) ;
if ( V_104 -> V_22 &&
( ! F_53 ( V_104 -> V_22 ) || V_104 -> V_22 > 65536 ) )
return - V_108 ;
if ( V_106 && V_106 -> V_109 ) {
V_40 = F_54 ( sizeof( * V_40 ) , V_110 ) ;
if ( ! V_40 )
return - V_111 ;
}
F_55 ( V_24 ) ;
if ( V_104 -> V_112 ) {
V_3 -> V_112 = V_104 -> V_112 ;
V_3 -> V_86 = F_36 ( V_3 -> V_112 ) ;
}
V_3 -> V_98 = V_104 -> V_98 * V_113 ;
if ( V_104 -> V_114 )
V_3 -> V_95 = F_56 ( V_16 , V_104 -> V_114 , V_5 ) ;
if ( V_104 -> V_22 ) {
V_3 -> V_22 = V_104 -> V_22 ;
V_3 -> V_95 = F_56 ( V_16 , V_3 -> V_95 , V_3 -> V_22 ) ;
}
if ( V_106 ) {
if ( V_106 -> V_115 )
V_3 -> V_83 = F_56 ( V_16 , V_106 -> V_115 , V_116 ) ;
if ( V_40 ) {
F_57 ( V_3 -> V_69 , V_40 ) ;
F_58 ( V_3 -> V_69 ,
V_106 -> V_109 , V_106 -> V_117 ,
V_106 -> V_118 ,
V_106 -> V_119 , V_106 -> V_120 ,
NULL ,
V_106 -> V_121 ) ;
}
V_3 -> V_60 = V_106 -> V_60 ;
V_3 -> V_53 = V_106 -> V_53 ;
}
if ( V_104 -> V_87 ) {
V_3 -> V_87 = F_56 ( V_16 , V_104 -> V_87 , V_3 -> V_83 * V_3 -> V_95 ) ;
V_3 -> V_95 = F_56 ( V_16 , V_3 -> V_95 , V_3 -> V_87 ) ;
}
V_44 = V_24 -> V_3 . V_44 ;
while ( V_24 -> V_3 . V_44 > V_3 -> V_87 )
F_21 ( V_24 ) ;
F_33 ( V_24 , V_44 - V_24 -> V_3 . V_44 ) ;
F_59 ( & V_3 -> V_99 ) ;
if ( V_3 -> V_98 ) {
F_49 ( & V_3 -> V_99 , V_100 + V_3 -> V_98 ) ;
V_3 -> V_21 = F_47 () ;
}
F_60 ( V_24 ) ;
F_61 ( V_40 ) ;
return 0 ;
}
static void * F_62 ( T_3 V_122 )
{
void * V_123 = F_54 ( V_122 , V_110 | V_124 ) ;
if ( ! V_123 )
V_123 = F_63 ( V_122 ) ;
return V_123 ;
}
static void F_64 ( void * V_125 )
{
F_65 ( V_125 ) ;
}
static void F_66 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
F_67 ( & V_3 -> V_31 ) ;
V_3 -> V_98 = 0 ;
F_68 ( & V_3 -> V_99 ) ;
F_64 ( V_3 -> V_58 ) ;
F_64 ( V_3 -> V_6 ) ;
F_61 ( V_3 -> V_69 ) ;
}
static int F_69 ( struct V_23 * V_24 , struct V_101 * V_102 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
int V_91 ;
V_3 -> V_99 . V_126 = F_43 ;
V_3 -> V_99 . V_11 = ( unsigned long ) V_24 ;
F_70 ( & V_3 -> V_99 ) ;
for ( V_91 = 0 ; V_91 < V_116 + 1 ; V_91 ++ ) {
V_3 -> V_7 [ V_91 ] . V_45 = V_91 + V_5 ;
V_3 -> V_7 [ V_91 ] . V_46 = V_91 + V_5 ;
}
V_3 -> V_87 = V_116 ;
V_3 -> V_83 = V_116 ;
V_3 -> V_48 = 0 ;
V_3 -> V_57 = NULL ;
V_3 -> V_22 = V_127 ;
V_3 -> V_95 = V_128 ;
V_3 -> V_112 = F_71 ( F_72 ( V_24 ) ) ;
V_3 -> V_86 = F_36 ( V_3 -> V_112 ) ;
V_3 -> V_98 = 0 ;
V_3 -> V_21 = F_47 () ;
if ( V_102 ) {
int V_129 = F_50 ( V_24 , V_102 ) ;
if ( V_129 )
return V_129 ;
}
V_3 -> V_58 = F_62 ( sizeof( V_3 -> V_58 [ 0 ] ) * V_3 -> V_22 ) ;
V_3 -> V_6 = F_62 ( sizeof( V_3 -> V_6 [ 0 ] ) * V_3 -> V_95 ) ;
if ( ! V_3 -> V_58 || ! V_3 -> V_6 ) {
F_66 ( V_24 ) ;
return - V_111 ;
}
for ( V_91 = 0 ; V_91 < V_3 -> V_22 ; V_91 ++ )
V_3 -> V_58 [ V_91 ] = V_59 ;
for ( V_91 = 0 ; V_91 < V_3 -> V_95 ; V_91 ++ ) {
F_19 ( & V_3 -> V_6 [ V_91 ] ) ;
F_13 ( V_3 , V_91 ) ;
}
if ( V_3 -> V_87 >= 1 )
V_24 -> V_60 |= V_130 ;
else
V_24 -> V_60 &= ~ V_130 ;
return 0 ;
}
static int F_73 ( struct V_23 * V_24 , struct V_9 * V_10 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
unsigned char * V_131 = F_74 ( V_10 ) ;
struct V_105 V_102 ;
struct V_69 * V_40 = V_3 -> V_69 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_132 . V_112 = V_3 -> V_112 ;
V_102 . V_132 . V_98 = V_3 -> V_98 / V_113 ;
V_102 . V_132 . V_87 = V_3 -> V_87 ;
V_102 . V_132 . V_22 = V_3 -> V_22 ;
V_102 . V_132 . V_114 = V_3 -> V_95 ;
V_102 . V_115 = V_3 -> V_83 ;
V_102 . V_53 = V_3 -> V_53 ;
if ( V_40 ) {
V_102 . V_109 = V_40 -> V_109 >> V_40 -> V_118 ;
V_102 . V_117 = V_40 -> V_117 >> V_40 -> V_118 ;
V_102 . V_118 = V_40 -> V_118 ;
V_102 . V_119 = V_40 -> V_119 ;
V_102 . V_120 = V_40 -> V_120 ;
V_102 . V_121 = V_40 -> V_121 ;
}
memcpy ( & V_102 . V_74 , & V_3 -> V_74 , sizeof( V_102 . V_74 ) ) ;
V_102 . V_60 = V_3 -> V_60 ;
if ( F_75 ( V_10 , V_133 , sizeof( V_102 ) , & V_102 ) )
goto V_134;
return V_10 -> V_51 ;
V_134:
F_76 ( V_10 , V_131 ) ;
return - 1 ;
}
static struct V_23 * F_77 ( struct V_23 * V_24 , unsigned long V_96 )
{
return NULL ;
}
static unsigned long F_78 ( struct V_23 * V_24 , V_16 V_38 )
{
return 0 ;
}
static unsigned long F_79 ( struct V_23 * V_24 , unsigned long V_135 ,
V_16 V_38 )
{
V_24 -> V_60 &= ~ V_130 ;
return 0 ;
}
static void F_80 ( struct V_23 * V_3 , unsigned long V_136 )
{
}
static struct V_137 * * F_81 ( struct V_23 * V_24 , unsigned long V_136 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
if ( V_136 )
return NULL ;
return & V_3 -> V_31 ;
}
static int F_82 ( struct V_23 * V_24 , unsigned long V_136 ,
struct V_9 * V_10 , struct V_138 * V_139 )
{
V_139 -> V_140 |= F_9 ( V_136 ) ;
return 0 ;
}
static int F_83 ( struct V_23 * V_24 , unsigned long V_136 ,
struct V_141 * V_47 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
T_1 V_142 = V_3 -> V_58 [ V_136 - 1 ] ;
struct V_143 V_144 = { 0 } ;
struct V_145 V_146 = { 0 } ;
if ( V_142 != V_59 ) {
const struct V_42 * V_43 = & V_3 -> V_6 [ V_142 ] ;
V_146 . V_85 = V_43 -> V_85 << V_147 ;
V_144 . V_44 = V_43 -> V_44 ;
V_144 . V_54 = V_43 -> V_54 ;
}
if ( F_84 ( V_47 , & V_144 ) < 0 )
return - 1 ;
return F_85 ( V_47 , & V_146 , sizeof( V_146 ) ) ;
}
static void F_86 ( struct V_23 * V_24 , struct V_148 * V_96 )
{
struct V_2 * V_3 = F_7 ( V_24 ) ;
unsigned int V_91 ;
if ( V_96 -> V_149 )
return;
for ( V_91 = 0 ; V_91 < V_3 -> V_22 ; V_91 ++ ) {
if ( V_3 -> V_58 [ V_91 ] == V_59 ||
V_96 -> V_150 < V_96 -> V_151 ) {
V_96 -> V_150 ++ ;
continue;
}
if ( V_96 -> V_152 ( V_24 , V_91 + 1 , V_96 ) < 0 ) {
V_96 -> V_149 = 1 ;
break;
}
V_96 -> V_150 ++ ;
}
}
static int T_4 F_87 ( void )
{
return F_88 ( & V_153 ) ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_153 ) ;
}
