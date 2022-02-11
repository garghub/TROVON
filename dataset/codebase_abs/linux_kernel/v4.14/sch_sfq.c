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
V_19 = F_9 ( V_9 , V_18 , & V_16 , false ) ;
if ( V_19 >= 0 ) {
#ifdef F_10
switch ( V_19 ) {
case V_25 :
case V_26 :
case V_27 :
* V_14 = V_23 | V_28 ;
case V_29 :
return 0 ;
}
#endif
if ( F_7 ( V_16 . V_30 ) <= V_3 -> V_11 )
return F_7 ( V_16 . V_30 ) ;
}
return 0 ;
}
static inline void F_11 ( struct V_2 * V_3 , T_1 V_31 )
{
T_1 V_32 , V_33 ;
struct V_34 * V_35 = & V_3 -> V_6 [ V_31 ] ;
int V_36 = V_35 -> V_36 ;
V_32 = V_36 + V_5 ;
V_33 = V_3 -> V_7 [ V_36 ] . V_37 ;
V_35 -> V_7 . V_37 = V_33 ;
V_35 -> V_7 . V_38 = V_32 ;
V_3 -> V_7 [ V_36 ] . V_37 = V_31 ;
F_1 ( V_3 , V_33 ) -> V_38 = V_31 ;
}
static inline void F_12 ( struct V_2 * V_3 , T_1 V_31 )
{
T_1 V_32 , V_33 ;
int V_39 ;
F_13 ( V_3 , V_31 , V_33 , V_32 ) ;
V_39 = V_3 -> V_6 [ V_31 ] . V_36 -- ;
if ( V_33 == V_32 && V_3 -> V_40 == V_39 )
V_3 -> V_40 -- ;
F_11 ( V_3 , V_31 ) ;
}
static inline void F_14 ( struct V_2 * V_3 , T_1 V_31 )
{
T_1 V_32 , V_33 ;
int V_39 ;
F_13 ( V_3 , V_31 , V_33 , V_32 ) ;
V_39 = ++ V_3 -> V_6 [ V_31 ] . V_36 ;
if ( V_3 -> V_40 < V_39 )
V_3 -> V_40 = V_39 ;
F_11 ( V_3 , V_31 ) ;
}
static inline struct V_8 * F_15 ( struct V_34 * V_35 )
{
struct V_8 * V_9 = V_35 -> V_41 ;
V_35 -> V_41 = V_9 -> V_38 ;
V_9 -> V_38 -> V_37 = (struct V_8 * ) V_35 ;
V_9 -> V_37 = V_9 -> V_38 = NULL ;
return V_9 ;
}
static inline struct V_8 * F_16 ( struct V_34 * V_35 )
{
struct V_8 * V_9 = V_35 -> V_42 ;
V_35 -> V_42 = V_9 -> V_37 ;
V_9 -> V_37 -> V_38 = (struct V_8 * ) V_35 ;
V_9 -> V_37 = V_9 -> V_38 = NULL ;
return V_9 ;
}
static inline void F_17 ( struct V_34 * V_35 )
{
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_41 = V_35 -> V_42 = (struct V_8 * ) V_35 ;
}
static inline void F_18 ( struct V_34 * V_35 , struct V_8 * V_9 )
{
V_9 -> V_38 = V_35 -> V_41 ;
V_9 -> V_37 = (struct V_8 * ) V_35 ;
V_35 -> V_41 -> V_37 = V_9 ;
V_35 -> V_41 = V_9 ;
}
static unsigned int F_19 ( struct V_12 * V_13 , struct V_8 * * V_43 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
T_1 V_31 , V_39 = V_3 -> V_40 ;
struct V_8 * V_9 ;
unsigned int V_44 ;
struct V_34 * V_35 ;
if ( V_39 > 1 ) {
V_31 = V_3 -> V_7 [ V_39 ] . V_37 ;
V_35 = & V_3 -> V_6 [ V_31 ] ;
V_45:
V_9 = V_3 -> V_46 ? F_16 ( V_35 ) : F_15 ( V_35 ) ;
V_44 = F_20 ( V_9 ) ;
V_35 -> V_47 -= V_44 ;
F_12 ( V_3 , V_31 ) ;
V_13 -> V_3 . V_36 -- ;
F_21 ( V_13 , V_9 ) ;
F_22 ( V_9 , V_13 , V_43 ) ;
return V_44 ;
}
if ( V_39 == 1 ) {
V_31 = V_3 -> V_48 -> V_37 ;
V_35 = & V_3 -> V_6 [ V_31 ] ;
V_3 -> V_48 -> V_37 = V_35 -> V_37 ;
V_3 -> V_49 [ V_35 -> V_50 ] = V_51 ;
goto V_45;
}
return 0 ;
}
static int F_23 ( const struct V_2 * V_3 )
{
return V_3 -> V_52 & V_53 ;
}
static int F_24 ( const struct V_2 * V_3 )
{
return ( V_3 -> V_52 & ( V_53 | V_54 ) ) == V_53 ;
}
static int F_25 ( const struct V_2 * V_3 )
{
return V_3 -> V_46 ;
}
static int
F_26 ( struct V_8 * V_9 , struct V_12 * V_13 , struct V_8 * * V_43 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
unsigned int V_50 , V_55 ;
T_1 V_31 , V_36 ;
struct V_34 * V_35 ;
int V_56 ( V_57 ) ;
struct V_8 * V_58 ;
int V_59 ;
V_50 = F_4 ( V_9 , V_13 , & V_57 ) ;
if ( V_50 == 0 ) {
if ( V_57 & V_24 )
F_27 ( V_13 ) ;
F_28 ( V_9 , V_43 ) ;
return V_57 ;
}
V_50 -- ;
V_31 = V_3 -> V_49 [ V_50 ] ;
V_35 = & V_3 -> V_6 [ V_31 ] ;
if ( V_31 == V_51 ) {
V_31 = V_3 -> V_7 [ 0 ] . V_37 ;
if ( V_31 >= V_5 )
return F_22 ( V_9 , V_13 , V_43 ) ;
V_3 -> V_49 [ V_50 ] = V_31 ;
V_35 = & V_3 -> V_6 [ V_31 ] ;
V_35 -> V_50 = V_50 ;
V_35 -> V_47 = 0 ;
F_29 ( & V_35 -> V_60 ) ;
goto V_61;
}
if ( V_3 -> V_62 ) {
V_35 -> V_60 . V_63 = F_30 ( V_3 -> V_62 ,
& V_35 -> V_60 ,
V_35 -> V_47 ) ;
switch ( F_31 ( V_3 -> V_62 ,
& V_35 -> V_60 ,
V_35 -> V_60 . V_63 ) ) {
case V_64 :
break;
case V_65 :
F_32 ( V_13 ) ;
if ( F_23 ( V_3 ) ) {
if ( F_25 ( V_3 ) &&
F_33 ( V_35 -> V_42 ) ) {
V_3 -> V_66 . V_67 ++ ;
break;
}
if ( F_33 ( V_9 ) ) {
V_3 -> V_66 . V_68 ++ ;
break;
}
}
V_3 -> V_66 . V_69 ++ ;
goto V_70;
case V_71 :
F_32 ( V_13 ) ;
if ( F_24 ( V_3 ) ) {
if ( F_25 ( V_3 ) &&
F_33 ( V_35 -> V_42 ) ) {
V_3 -> V_66 . V_72 ++ ;
break;
}
if ( F_33 ( V_9 ) ) {
V_3 -> V_66 . V_73 ++ ;
break;
}
}
V_3 -> V_66 . V_74 ++ ;
goto V_70;
}
}
if ( V_35 -> V_36 >= V_3 -> V_75 ) {
V_70:
if ( ! F_25 ( V_3 ) )
return F_22 ( V_9 , V_13 , V_43 ) ;
V_58 = F_16 ( V_35 ) ;
V_59 = F_20 ( V_58 ) - F_20 ( V_9 ) ;
V_13 -> V_76 . V_47 -= V_59 ;
V_35 -> V_47 -= V_59 ;
F_22 ( V_58 , V_13 , V_43 ) ;
F_18 ( V_35 , V_9 ) ;
F_34 ( V_13 , 0 , V_59 ) ;
return V_77 ;
}
V_61:
F_35 ( V_13 , V_9 ) ;
V_35 -> V_47 += F_20 ( V_9 ) ;
F_18 ( V_35 , V_9 ) ;
F_14 ( V_3 , V_31 ) ;
if ( V_35 -> V_36 == 1 ) {
if ( V_3 -> V_48 == NULL ) {
V_35 -> V_37 = V_31 ;
} else {
V_35 -> V_37 = V_3 -> V_48 -> V_37 ;
V_3 -> V_48 -> V_37 = V_31 ;
}
V_3 -> V_48 = V_35 ;
V_35 -> V_78 = V_3 -> V_79 ;
}
if ( ++ V_13 -> V_3 . V_36 <= V_3 -> V_80 )
return V_23 ;
V_36 = V_35 -> V_36 ;
V_55 = F_19 ( V_13 , V_43 ) ;
if ( V_36 != V_35 -> V_36 ) {
F_34 ( V_13 , 0 , V_55 - F_20 ( V_9 ) ) ;
return V_77 ;
}
F_34 ( V_13 , 1 , V_55 ) ;
return V_23 ;
}
static struct V_8 *
F_36 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_8 * V_9 ;
T_1 V_81 , V_82 ;
struct V_34 * V_35 ;
if ( V_3 -> V_48 == NULL )
return NULL ;
V_83:
V_81 = V_3 -> V_48 -> V_37 ;
V_35 = & V_3 -> V_6 [ V_81 ] ;
if ( V_35 -> V_78 <= 0 ) {
V_3 -> V_48 = V_35 ;
V_35 -> V_78 += V_3 -> V_79 ;
goto V_83;
}
V_9 = F_16 ( V_35 ) ;
F_12 ( V_3 , V_81 ) ;
F_37 ( V_13 , V_9 ) ;
V_13 -> V_3 . V_36 -- ;
F_21 ( V_13 , V_9 ) ;
V_35 -> V_47 -= F_20 ( V_9 ) ;
if ( V_35 -> V_36 == 0 ) {
V_3 -> V_49 [ V_35 -> V_50 ] = V_51 ;
V_82 = V_35 -> V_37 ;
if ( V_81 == V_82 ) {
V_3 -> V_48 = NULL ;
return V_9 ;
}
V_3 -> V_48 -> V_37 = V_82 ;
} else {
V_35 -> V_78 -= F_38 ( F_20 ( V_9 ) ) ;
}
return V_9 ;
}
static void
F_39 ( struct V_12 * V_13 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_36 ( V_13 ) ) != NULL )
F_40 ( V_9 , V_9 ) ;
}
static void F_41 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_8 * V_9 ;
int V_84 ;
struct V_34 * V_35 ;
struct V_85 V_86 ;
int V_55 = 0 ;
unsigned int V_87 = 0 ;
F_42 ( & V_86 ) ;
for ( V_84 = 0 ; V_84 < V_3 -> V_88 ; V_84 ++ ) {
V_35 = & V_3 -> V_6 [ V_84 ] ;
if ( ! V_35 -> V_36 )
continue;
while ( V_35 -> V_36 ) {
V_9 = F_16 ( V_35 ) ;
F_12 ( V_3 , V_84 ) ;
F_43 ( & V_86 , V_9 ) ;
}
V_35 -> V_47 = 0 ;
F_29 ( & V_35 -> V_60 ) ;
V_3 -> V_49 [ V_35 -> V_50 ] = V_51 ;
}
V_3 -> V_48 = NULL ;
while ( ( V_9 = F_44 ( & V_86 ) ) != NULL ) {
unsigned int V_50 = F_2 ( V_3 , V_9 ) ;
T_1 V_31 = V_3 -> V_49 [ V_50 ] ;
V_35 = & V_3 -> V_6 [ V_31 ] ;
if ( V_31 == V_51 ) {
V_31 = V_3 -> V_7 [ 0 ] . V_37 ;
if ( V_31 >= V_5 ) {
V_45:
F_21 ( V_13 , V_9 ) ;
V_87 += F_20 ( V_9 ) ;
F_45 ( V_9 ) ;
V_55 ++ ;
continue;
}
V_3 -> V_49 [ V_50 ] = V_31 ;
V_35 = & V_3 -> V_6 [ V_31 ] ;
V_35 -> V_50 = V_50 ;
}
if ( V_35 -> V_36 >= V_3 -> V_75 )
goto V_45;
F_18 ( V_35 , V_9 ) ;
if ( V_3 -> V_62 )
V_35 -> V_60 . V_63 = F_46 ( V_3 -> V_62 ,
& V_35 -> V_60 ,
V_35 -> V_47 ) ;
V_35 -> V_47 += F_20 ( V_9 ) ;
F_14 ( V_3 , V_31 ) ;
if ( V_35 -> V_36 == 1 ) {
if ( V_3 -> V_48 == NULL ) {
V_35 -> V_37 = V_31 ;
} else {
V_35 -> V_37 = V_3 -> V_48 -> V_37 ;
V_3 -> V_48 -> V_37 = V_31 ;
}
V_3 -> V_48 = V_35 ;
V_35 -> V_78 = V_3 -> V_79 ;
}
}
V_13 -> V_3 . V_36 -= V_55 ;
F_34 ( V_13 , V_55 , V_87 ) ;
}
static void F_47 ( unsigned long V_89 )
{
struct V_12 * V_13 = (struct V_12 * ) V_89 ;
struct V_2 * V_3 = F_5 ( V_13 ) ;
T_2 * V_90 = F_48 ( F_49 ( V_13 ) ) ;
F_50 ( V_90 ) ;
V_3 -> V_10 = F_51 () ;
if ( ! V_3 -> V_22 && V_3 -> V_48 )
F_41 ( V_13 ) ;
F_52 ( V_90 ) ;
if ( V_3 -> V_91 )
F_53 ( & V_3 -> V_92 , V_93 + V_3 -> V_91 ) ;
}
static int F_54 ( struct V_12 * V_13 , struct V_94 * V_95 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
struct V_96 * V_97 = F_55 ( V_95 ) ;
struct V_98 * V_99 = NULL ;
unsigned int V_36 , V_55 = 0 ;
struct V_62 * V_32 = NULL ;
struct V_8 * V_43 = NULL ;
struct V_8 * V_48 = NULL ;
if ( V_95 -> V_100 < F_56 ( sizeof( * V_97 ) ) )
return - V_101 ;
if ( V_95 -> V_100 >= F_56 ( sizeof( * V_99 ) ) )
V_99 = F_55 ( V_95 ) ;
if ( V_97 -> V_11 &&
( ! F_57 ( V_97 -> V_11 ) || V_97 -> V_11 > 65536 ) )
return - V_101 ;
if ( V_99 && V_99 -> V_102 ) {
V_32 = F_58 ( sizeof( * V_32 ) , V_103 ) ;
if ( ! V_32 )
return - V_104 ;
}
F_59 ( V_13 ) ;
if ( V_97 -> V_105 ) {
V_3 -> V_105 = V_97 -> V_105 ;
V_3 -> V_79 = F_38 ( V_3 -> V_105 ) ;
}
V_3 -> V_91 = V_97 -> V_91 * V_106 ;
if ( V_97 -> V_107 )
V_3 -> V_88 = F_60 ( V_108 , V_97 -> V_107 , V_5 ) ;
if ( V_97 -> V_11 ) {
V_3 -> V_11 = V_97 -> V_11 ;
V_3 -> V_88 = F_60 ( V_108 , V_3 -> V_88 , V_3 -> V_11 ) ;
}
if ( V_99 ) {
if ( V_99 -> V_109 )
V_3 -> V_75 = F_60 ( V_108 , V_99 -> V_109 , V_110 ) ;
if ( V_32 ) {
F_61 ( V_3 -> V_62 , V_32 ) ;
F_62 ( V_3 -> V_62 ,
V_99 -> V_102 , V_99 -> V_111 ,
V_99 -> V_112 ,
V_99 -> V_113 , V_99 -> V_114 ,
NULL ,
V_99 -> V_115 ) ;
}
V_3 -> V_52 = V_99 -> V_52 ;
V_3 -> V_46 = V_99 -> V_46 ;
}
if ( V_97 -> V_80 ) {
V_3 -> V_80 = F_60 ( V_108 , V_97 -> V_80 , V_3 -> V_75 * V_3 -> V_88 ) ;
V_3 -> V_88 = F_60 ( V_108 , V_3 -> V_88 , V_3 -> V_80 ) ;
}
V_36 = V_13 -> V_3 . V_36 ;
while ( V_13 -> V_3 . V_36 > V_3 -> V_80 ) {
V_55 += F_19 ( V_13 , & V_43 ) ;
if ( ! V_48 )
V_48 = V_43 ;
}
F_40 ( V_43 , V_48 ) ;
F_34 ( V_13 , V_36 - V_13 -> V_3 . V_36 , V_55 ) ;
F_63 ( & V_3 -> V_92 ) ;
if ( V_3 -> V_91 ) {
F_53 ( & V_3 -> V_92 , V_93 + V_3 -> V_91 ) ;
V_3 -> V_10 = F_51 () ;
}
F_64 ( V_13 ) ;
F_65 ( V_32 ) ;
return 0 ;
}
static void * F_66 ( T_3 V_116 )
{
return F_67 ( V_116 , V_103 ) ;
}
static void F_68 ( void * V_117 )
{
F_69 ( V_117 ) ;
}
static void F_70 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
F_71 ( V_3 -> V_118 ) ;
V_3 -> V_91 = 0 ;
F_72 ( & V_3 -> V_92 ) ;
F_68 ( V_3 -> V_49 ) ;
F_68 ( V_3 -> V_6 ) ;
F_65 ( V_3 -> V_62 ) ;
}
static int F_73 ( struct V_12 * V_13 , struct V_94 * V_95 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
int V_84 ;
int V_119 ;
F_74 ( & V_3 -> V_92 , F_47 ,
( unsigned long ) V_13 ) ;
V_119 = F_75 ( & V_3 -> V_118 , & V_3 -> V_22 ) ;
if ( V_119 )
return V_119 ;
for ( V_84 = 0 ; V_84 < V_110 + 1 ; V_84 ++ ) {
V_3 -> V_7 [ V_84 ] . V_37 = V_84 + V_5 ;
V_3 -> V_7 [ V_84 ] . V_38 = V_84 + V_5 ;
}
V_3 -> V_80 = V_110 ;
V_3 -> V_75 = V_110 ;
V_3 -> V_40 = 0 ;
V_3 -> V_48 = NULL ;
V_3 -> V_11 = V_120 ;
V_3 -> V_88 = V_121 ;
V_3 -> V_105 = F_76 ( F_77 ( V_13 ) ) ;
V_3 -> V_79 = F_38 ( V_3 -> V_105 ) ;
V_3 -> V_91 = 0 ;
V_3 -> V_10 = F_51 () ;
if ( V_95 ) {
int V_119 = F_54 ( V_13 , V_95 ) ;
if ( V_119 )
return V_119 ;
}
V_3 -> V_49 = F_66 ( sizeof( V_3 -> V_49 [ 0 ] ) * V_3 -> V_11 ) ;
V_3 -> V_6 = F_66 ( sizeof( V_3 -> V_6 [ 0 ] ) * V_3 -> V_88 ) ;
if ( ! V_3 -> V_49 || ! V_3 -> V_6 ) {
return - V_104 ;
}
for ( V_84 = 0 ; V_84 < V_3 -> V_11 ; V_84 ++ )
V_3 -> V_49 [ V_84 ] = V_51 ;
for ( V_84 = 0 ; V_84 < V_3 -> V_88 ; V_84 ++ ) {
F_17 ( & V_3 -> V_6 [ V_84 ] ) ;
F_11 ( V_3 , V_84 ) ;
}
if ( V_3 -> V_80 >= 1 )
V_13 -> V_52 |= V_122 ;
else
V_13 -> V_52 &= ~ V_122 ;
return 0 ;
}
static int F_78 ( struct V_12 * V_13 , struct V_8 * V_9 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
unsigned char * V_123 = F_79 ( V_9 ) ;
struct V_98 V_95 ;
struct V_62 * V_32 = V_3 -> V_62 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_124 . V_105 = V_3 -> V_105 ;
V_95 . V_124 . V_91 = V_3 -> V_91 / V_106 ;
V_95 . V_124 . V_80 = V_3 -> V_80 ;
V_95 . V_124 . V_11 = V_3 -> V_11 ;
V_95 . V_124 . V_107 = V_3 -> V_88 ;
V_95 . V_109 = V_3 -> V_75 ;
V_95 . V_46 = V_3 -> V_46 ;
if ( V_32 ) {
V_95 . V_102 = V_32 -> V_102 >> V_32 -> V_112 ;
V_95 . V_111 = V_32 -> V_111 >> V_32 -> V_112 ;
V_95 . V_112 = V_32 -> V_112 ;
V_95 . V_113 = V_32 -> V_113 ;
V_95 . V_114 = V_32 -> V_114 ;
V_95 . V_115 = V_32 -> V_115 ;
}
memcpy ( & V_95 . V_66 , & V_3 -> V_66 , sizeof( V_95 . V_66 ) ) ;
V_95 . V_52 = V_3 -> V_52 ;
if ( F_80 ( V_9 , V_125 , sizeof( V_95 ) , & V_95 ) )
goto V_126;
return V_9 -> V_44 ;
V_126:
F_81 ( V_9 , V_123 ) ;
return - 1 ;
}
static struct V_12 * F_82 ( struct V_12 * V_13 , unsigned long V_89 )
{
return NULL ;
}
static unsigned long F_83 ( struct V_12 * V_13 , V_108 V_30 )
{
return 0 ;
}
static unsigned long F_84 ( struct V_12 * V_13 , unsigned long V_127 ,
V_108 V_30 )
{
V_13 -> V_52 &= ~ V_122 ;
return 0 ;
}
static void F_85 ( struct V_12 * V_3 , unsigned long V_128 )
{
}
static struct V_129 * F_86 ( struct V_12 * V_13 , unsigned long V_128 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
if ( V_128 )
return NULL ;
return V_3 -> V_118 ;
}
static int F_87 ( struct V_12 * V_13 , unsigned long V_128 ,
struct V_8 * V_9 , struct V_130 * V_131 )
{
V_131 -> V_132 |= F_7 ( V_128 ) ;
return 0 ;
}
static int F_88 ( struct V_12 * V_13 , unsigned long V_128 ,
struct V_133 * V_39 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
T_1 V_134 = V_3 -> V_49 [ V_128 - 1 ] ;
struct V_135 V_136 = { 0 } ;
struct V_137 V_138 = { 0 } ;
if ( V_134 != V_51 ) {
const struct V_34 * V_35 = & V_3 -> V_6 [ V_134 ] ;
V_138 . V_78 = V_35 -> V_78 << V_139 ;
V_136 . V_36 = V_35 -> V_36 ;
V_136 . V_47 = V_35 -> V_47 ;
}
if ( F_89 ( V_39 , NULL , & V_136 , V_136 . V_36 ) < 0 )
return - 1 ;
return F_90 ( V_39 , & V_138 , sizeof( V_138 ) ) ;
}
static void F_91 ( struct V_12 * V_13 , struct V_140 * V_89 )
{
struct V_2 * V_3 = F_5 ( V_13 ) ;
unsigned int V_84 ;
if ( V_89 -> V_141 )
return;
for ( V_84 = 0 ; V_84 < V_3 -> V_11 ; V_84 ++ ) {
if ( V_3 -> V_49 [ V_84 ] == V_51 ||
V_89 -> V_142 < V_89 -> V_143 ) {
V_89 -> V_142 ++ ;
continue;
}
if ( V_89 -> V_144 ( V_13 , V_84 + 1 , V_89 ) < 0 ) {
V_89 -> V_141 = 1 ;
break;
}
V_89 -> V_142 ++ ;
}
}
static int T_4 F_92 ( void )
{
return F_93 ( & V_145 ) ;
}
static void T_5 F_94 ( void )
{
F_95 ( & V_145 ) ;
}
