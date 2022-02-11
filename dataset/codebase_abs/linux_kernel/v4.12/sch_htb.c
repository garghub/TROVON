static inline struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
V_8 = F_3 ( & V_6 -> V_9 , V_2 ) ;
if ( V_8 == NULL )
return NULL ;
return F_4 ( V_8 , struct V_1 , V_10 ) ;
}
static struct V_1 * F_5 ( struct V_11 * V_12 , struct V_3 * V_4 ,
int * V_13 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
struct V_15 V_16 ;
struct V_17 * V_18 ;
int V_19 ;
if ( V_12 -> V_20 == V_4 -> V_2 )
return V_21 ;
V_14 = F_1 ( V_12 -> V_20 , V_4 ) ;
if ( V_14 ) {
if ( V_14 -> V_22 == 0 )
return V_14 ;
V_18 = F_6 ( V_14 -> V_23 ) ;
} else {
V_18 = F_6 ( V_6 -> V_23 ) ;
}
* V_13 = V_24 | V_25 ;
while ( V_18 && ( V_19 = F_7 ( V_12 , V_18 , & V_16 , false ) ) >= 0 ) {
#ifdef F_8
switch ( V_19 ) {
case V_26 :
case V_27 :
* V_13 = V_24 | V_28 ;
case V_29 :
return NULL ;
}
#endif
V_14 = ( void * ) V_16 . V_30 ;
if ( ! V_14 ) {
if ( V_16 . V_31 == V_4 -> V_2 )
return V_21 ;
V_14 = F_1 ( V_16 . V_31 , V_4 ) ;
if ( ! V_14 )
break;
}
if ( ! V_14 -> V_22 )
return V_14 ;
V_18 = F_6 ( V_14 -> V_23 ) ;
}
V_14 = F_1 ( F_9 ( F_10 ( V_4 -> V_2 ) , V_6 -> V_32 ) , V_4 ) ;
if ( ! V_14 || V_14 -> V_22 )
return V_21 ;
return V_14 ;
}
static void F_11 ( struct V_33 * V_34 ,
struct V_1 * V_14 , int V_35 )
{
struct V_36 * * V_37 = & V_34 -> V_36 , * V_38 = NULL ;
while ( * V_37 ) {
struct V_1 * V_39 ;
V_38 = * V_37 ;
V_39 = F_12 ( V_38 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_14 -> V_10 . V_31 > V_39 -> V_10 . V_31 )
V_37 = & V_38 -> V_41 ;
else
V_37 = & V_38 -> V_42 ;
}
F_13 ( & V_14 -> V_40 [ V_35 ] , V_38 , V_37 ) ;
F_14 ( & V_14 -> V_40 [ V_35 ] , V_34 ) ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_1 * V_14 , T_2 V_43 )
{
struct V_36 * * V_37 = & V_6 -> V_44 [ V_14 -> V_22 ] . V_45 . V_36 , * V_38 = NULL ;
V_14 -> V_46 = V_6 -> V_47 + V_43 ;
if ( V_14 -> V_46 == V_6 -> V_47 )
V_14 -> V_46 ++ ;
if ( V_6 -> V_48 [ V_14 -> V_22 ] > V_14 -> V_46 )
V_6 -> V_48 [ V_14 -> V_22 ] = V_14 -> V_46 ;
while ( * V_37 ) {
struct V_1 * V_39 ;
V_38 = * V_37 ;
V_39 = F_12 ( V_38 , struct V_1 , V_49 ) ;
if ( V_14 -> V_46 >= V_39 -> V_46 )
V_37 = & V_38 -> V_41 ;
else
V_37 = & V_38 -> V_42 ;
}
F_13 ( & V_14 -> V_49 , V_38 , V_37 ) ;
F_14 ( & V_14 -> V_49 , & V_6 -> V_44 [ V_14 -> V_22 ] . V_45 ) ;
}
static inline void F_16 ( struct V_36 * * V_50 )
{
* V_50 = F_17 ( * V_50 ) ;
}
static inline void F_18 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_51 )
{
V_6 -> V_52 [ V_14 -> V_22 ] |= V_51 ;
while ( V_51 ) {
int V_35 = F_19 ( ~ V_51 ) ;
V_51 &= ~ ( 1 << V_35 ) ;
F_11 ( & V_6 -> V_44 [ V_14 -> V_22 ] . V_53 [ V_35 ] . V_54 , V_14 , V_35 ) ;
}
}
static void F_20 ( struct V_36 * V_55 , struct V_33 * V_34 )
{
if ( F_21 ( V_55 ) ) {
F_22 ( 1 ) ;
} else {
F_23 ( V_55 , V_34 ) ;
F_24 ( V_55 ) ;
}
}
static inline void F_25 ( struct V_5 * V_6 ,
struct V_1 * V_14 , int V_51 )
{
int V_56 = 0 ;
struct V_57 * V_44 = & V_6 -> V_44 [ V_14 -> V_22 ] ;
while ( V_51 ) {
int V_35 = F_19 ( ~ V_51 ) ;
struct V_58 * V_53 = & V_44 -> V_53 [ V_35 ] ;
V_51 &= ~ ( 1 << V_35 ) ;
if ( V_53 -> V_59 == V_14 -> V_40 + V_35 )
F_16 ( & V_53 -> V_59 ) ;
F_20 ( V_14 -> V_40 + V_35 , & V_53 -> V_54 ) ;
if ( ! V_53 -> V_54 . V_36 )
V_56 |= 1 << V_35 ;
}
V_6 -> V_52 [ V_14 -> V_22 ] &= ~ V_56 ;
}
static void F_26 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_37 = V_14 -> V_38 ;
long V_56 , V_51 = V_14 -> V_60 ;
while ( V_14 -> V_61 == V_62 && V_37 && V_51 ) {
V_56 = V_51 ;
while ( V_56 ) {
int V_35 = F_19 ( ~ V_56 ) ;
V_56 &= ~ ( 1 << V_35 ) ;
if ( V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 . V_36 )
V_51 &= ~ ( 1 << V_35 ) ;
F_11 ( & V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 , V_14 , V_35 ) ;
}
V_37 -> V_60 |= V_51 ;
V_14 = V_37 ;
V_37 = V_14 -> V_38 ;
}
if ( V_14 -> V_61 == V_67 && V_51 )
F_18 ( V_6 , V_14 , V_51 ) ;
}
static void F_27 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
struct V_1 * V_37 = V_14 -> V_38 ;
long V_56 , V_51 = V_14 -> V_60 ;
while ( V_14 -> V_61 == V_62 && V_37 && V_51 ) {
V_56 = V_51 ;
V_51 = 0 ;
while ( V_56 ) {
int V_35 = F_19 ( ~ V_56 ) ;
V_56 &= ~ ( 1 << V_35 ) ;
if ( V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 == V_14 -> V_40 + V_35 ) {
V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_68 = V_14 -> V_10 . V_31 ;
V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 = NULL ;
}
F_20 ( V_14 -> V_40 + V_35 ,
& V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 ) ;
if ( ! V_37 -> V_63 . V_64 . V_65 [ V_35 ] . V_66 . V_36 )
V_51 |= 1 << V_35 ;
}
V_37 -> V_60 &= ~ V_51 ;
V_14 = V_37 ;
V_37 = V_14 -> V_38 ;
}
if ( V_14 -> V_61 == V_67 && V_51 )
F_25 ( V_6 , V_14 , V_51 ) ;
}
static inline T_2 F_28 ( const struct V_1 * V_14 )
{
if ( V_69 )
return V_14 -> V_61 != V_70 ? - V_14 -> V_71 : 0 ;
else
return 0 ;
}
static inline T_2 F_29 ( const struct V_1 * V_14 )
{
if ( V_69 )
return V_14 -> V_61 == V_67 ? - V_14 -> V_72 : 0 ;
else
return 0 ;
}
static inline enum V_73
F_30 ( struct V_1 * V_14 , T_2 * V_74 )
{
T_2 V_75 ;
if ( ( V_75 = ( V_14 -> V_76 + * V_74 ) ) < F_28 ( V_14 ) ) {
* V_74 = - V_75 ;
return V_70 ;
}
if ( ( V_75 = ( V_14 -> V_77 + * V_74 ) ) >= F_29 ( V_14 ) )
return V_67 ;
* V_74 = - V_75 ;
return V_62 ;
}
static void
F_31 ( struct V_5 * V_6 , struct V_1 * V_14 , T_2 * V_74 )
{
enum V_73 V_78 = F_30 ( V_14 , V_74 ) ;
if ( V_78 == V_14 -> V_61 )
return;
if ( V_14 -> V_60 ) {
if ( V_14 -> V_61 != V_70 )
F_27 ( V_6 , V_14 ) ;
V_14 -> V_61 = V_78 ;
if ( V_78 != V_70 )
F_26 ( V_6 , V_14 ) ;
} else
V_14 -> V_61 = V_78 ;
}
static inline void F_32 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_22 ( V_14 -> V_22 || ! V_14 -> V_63 . V_79 . V_6 || ! V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 ) ;
if ( ! V_14 -> V_60 ) {
V_14 -> V_60 = 1 << V_14 -> V_35 ;
F_26 ( V_6 , V_14 ) ;
F_33 ( & V_14 -> V_63 . V_79 . V_81 ,
V_6 -> V_82 + V_14 -> V_35 ) ;
}
}
static inline void F_34 ( struct V_5 * V_6 , struct V_1 * V_14 )
{
F_22 ( ! V_14 -> V_60 ) ;
F_27 ( V_6 , V_14 ) ;
V_14 -> V_60 = 0 ;
F_35 ( & V_14 -> V_63 . V_79 . V_81 ) ;
}
static void F_36 ( struct V_11 * V_12 , struct V_3 * V_4 ,
struct V_83 * V_84 )
{
struct V_11 * V_85 = V_84 -> V_86 ;
if ( V_85 ) {
V_12 -> V_87 = NULL ;
V_85 -> V_87 = V_12 ;
V_84 -> V_86 = V_12 ;
} else {
V_84 -> V_86 = V_12 ;
V_84 -> V_88 = V_12 ;
}
V_84 -> V_80 ++ ;
}
static int F_37 ( struct V_11 * V_12 , struct V_3 * V_4 ,
struct V_11 * * V_89 )
{
int V_90 ( V_91 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = F_5 ( V_12 , V_4 , & V_91 ) ;
if ( V_14 == V_21 ) {
if ( V_6 -> V_92 . V_80 < V_6 -> V_93 ) {
F_36 ( V_12 , V_4 , & V_6 -> V_92 ) ;
V_6 -> V_94 ++ ;
} else {
return F_38 ( V_12 , V_4 , V_89 ) ;
}
#ifdef F_8
} else if ( ! V_14 ) {
if ( V_91 & V_25 )
F_39 ( V_4 ) ;
F_40 ( V_12 , V_89 ) ;
return V_91 ;
#endif
} else if ( ( V_91 = F_41 ( V_12 , V_14 -> V_63 . V_79 . V_6 ,
V_89 ) ) != V_24 ) {
if ( F_42 ( V_91 ) ) {
F_39 ( V_4 ) ;
V_14 -> V_82 ++ ;
}
return V_91 ;
} else {
F_32 ( V_6 , V_14 ) ;
}
F_43 ( V_4 , V_12 ) ;
V_4 -> V_6 . V_80 ++ ;
return V_24 ;
}
static inline void F_44 ( struct V_1 * V_14 , int V_95 , T_2 V_74 )
{
T_2 V_75 = V_74 + V_14 -> V_77 ;
if ( V_75 > V_14 -> V_72 )
V_75 = V_14 -> V_72 ;
V_75 -= ( T_2 ) F_45 ( & V_14 -> V_96 , V_95 ) ;
if ( V_75 <= - V_14 -> V_97 )
V_75 = 1 - V_14 -> V_97 ;
V_14 -> V_77 = V_75 ;
}
static inline void F_46 ( struct V_1 * V_14 , int V_95 , T_2 V_74 )
{
T_2 V_75 = V_74 + V_14 -> V_76 ;
if ( V_75 > V_14 -> V_71 )
V_75 = V_14 -> V_71 ;
V_75 -= ( T_2 ) F_45 ( & V_14 -> ceil , V_95 ) ;
if ( V_75 <= - V_14 -> V_97 )
V_75 = 1 - V_14 -> V_97 ;
V_14 -> V_76 = V_75 ;
}
static void F_47 ( struct V_5 * V_6 , struct V_1 * V_14 ,
int V_22 , struct V_11 * V_12 )
{
int V_95 = F_48 ( V_12 ) ;
enum V_73 V_98 ;
T_2 V_74 ;
while ( V_14 ) {
V_74 = F_49 ( T_2 , V_6 -> V_47 - V_14 -> V_99 , V_14 -> V_97 ) ;
if ( V_14 -> V_22 >= V_22 ) {
if ( V_14 -> V_22 == V_22 )
V_14 -> V_100 . V_101 ++ ;
F_44 ( V_14 , V_95 , V_74 ) ;
} else {
V_14 -> V_100 . V_102 ++ ;
V_14 -> V_77 += V_74 ;
}
F_46 ( V_14 , V_95 , V_74 ) ;
V_14 -> V_99 = V_6 -> V_47 ;
V_98 = V_14 -> V_61 ;
V_74 = 0 ;
F_31 ( V_6 , V_14 , & V_74 ) ;
if ( V_98 != V_14 -> V_61 ) {
if ( V_98 != V_67 )
F_20 ( & V_14 -> V_49 , & V_6 -> V_44 [ V_14 -> V_22 ] . V_45 ) ;
if ( V_14 -> V_61 != V_67 )
F_15 ( V_6 , V_14 , V_74 ) ;
}
if ( V_14 -> V_22 )
F_50 ( & V_14 -> V_103 , V_12 ) ;
V_14 = V_14 -> V_38 ;
}
}
static T_2 F_51 ( struct V_5 * V_6 , const int V_22 ,
unsigned long V_104 )
{
unsigned long V_105 = V_104 + 2 ;
struct V_33 * V_45 = & V_6 -> V_44 [ V_22 ] . V_45 ;
while ( F_52 ( V_106 , V_105 ) ) {
struct V_1 * V_14 ;
T_2 V_74 ;
struct V_36 * V_37 = F_53 ( V_45 ) ;
if ( ! V_37 )
return 0 ;
V_14 = F_12 ( V_37 , struct V_1 , V_49 ) ;
if ( V_14 -> V_46 > V_6 -> V_47 )
return V_14 -> V_46 ;
F_20 ( V_37 , V_45 ) ;
V_74 = F_49 ( T_2 , V_6 -> V_47 - V_14 -> V_99 , V_14 -> V_97 ) ;
F_31 ( V_6 , V_14 , & V_74 ) ;
if ( V_14 -> V_61 != V_67 )
F_15 ( V_6 , V_14 , V_74 ) ;
}
if ( ! ( V_6 -> V_107 & V_108 ) ) {
F_54 ( L_1 ) ;
V_6 -> V_107 |= V_108 ;
}
return V_6 -> V_47 ;
}
static struct V_36 * F_55 ( int V_35 , struct V_36 * V_50 ,
T_1 V_109 )
{
struct V_36 * V_110 = NULL ;
while ( V_50 ) {
struct V_1 * V_14 =
F_12 ( V_50 , struct V_1 , V_40 [ V_35 ] ) ;
if ( V_109 > V_14 -> V_10 . V_31 ) {
V_50 = V_50 -> V_41 ;
} else if ( V_109 < V_14 -> V_10 . V_31 ) {
V_110 = V_50 ;
V_50 = V_50 -> V_42 ;
} else {
return V_50 ;
}
}
return V_110 ;
}
static struct V_1 * F_56 ( struct V_58 * V_53 , const int V_35 )
{
int V_111 ;
struct {
struct V_36 * V_34 ;
struct V_36 * * V_112 ;
T_1 * V_113 ;
} V_114 [ V_115 ] , * V_116 = V_114 ;
F_57 ( ! V_53 -> V_54 . V_36 ) ;
V_116 -> V_34 = V_53 -> V_54 . V_36 ;
V_116 -> V_112 = & V_53 -> V_59 ;
V_116 -> V_113 = & V_53 -> V_68 ;
for ( V_111 = 0 ; V_111 < 65535 ; V_111 ++ ) {
if ( ! * V_116 -> V_112 && * V_116 -> V_113 ) {
* V_116 -> V_112 =
F_55 ( V_35 , V_116 -> V_34 , * V_116 -> V_113 ) ;
}
* V_116 -> V_113 = 0 ;
if ( ! * V_116 -> V_112 ) {
* V_116 -> V_112 = V_116 -> V_34 ;
while ( ( * V_116 -> V_112 ) -> V_42 )
* V_116 -> V_112 = ( * V_116 -> V_112 ) -> V_42 ;
if ( V_116 > V_114 ) {
V_116 -- ;
if ( ! * V_116 -> V_112 ) {
F_22 ( 1 ) ;
return NULL ;
}
F_16 ( V_116 -> V_112 ) ;
}
} else {
struct V_1 * V_14 ;
struct V_58 * V_117 ;
V_14 = F_12 ( * V_116 -> V_112 , struct V_1 , V_40 [ V_35 ] ) ;
if ( ! V_14 -> V_22 )
return V_14 ;
V_117 = & V_14 -> V_63 . V_64 . V_65 [ V_35 ] ;
( ++ V_116 ) -> V_34 = V_117 -> V_66 . V_36 ;
V_116 -> V_112 = & V_117 -> V_59 ;
V_116 -> V_113 = & V_117 -> V_68 ;
}
}
F_22 ( 1 ) ;
return NULL ;
}
static struct V_11 * F_58 ( struct V_5 * V_6 , const int V_35 ,
const int V_22 )
{
struct V_11 * V_12 = NULL ;
struct V_1 * V_14 , * V_104 ;
struct V_57 * V_44 = & V_6 -> V_44 [ V_22 ] ;
struct V_58 * V_53 = & V_44 -> V_53 [ V_35 ] ;
V_104 = V_14 = F_56 ( V_53 , V_35 ) ;
do {
V_87:
if ( F_59 ( ! V_14 ) )
return NULL ;
if ( F_59 ( V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 == 0 ) ) {
struct V_1 * V_87 ;
F_34 ( V_6 , V_14 ) ;
if ( ( V_6 -> V_52 [ V_22 ] & ( 1 << V_35 ) ) == 0 )
return NULL ;
V_87 = F_56 ( V_53 , V_35 ) ;
if ( V_14 == V_104 )
V_104 = V_87 ;
V_14 = V_87 ;
goto V_87;
}
V_12 = V_14 -> V_63 . V_79 . V_6 -> V_118 ( V_14 -> V_63 . V_79 . V_6 ) ;
if ( F_60 ( V_12 != NULL ) )
break;
F_61 ( L_2 , V_14 -> V_63 . V_79 . V_6 ) ;
F_16 ( V_22 ? & V_14 -> V_38 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 :
& V_6 -> V_44 [ 0 ] . V_53 [ V_35 ] . V_59 ) ;
V_14 = F_56 ( V_53 , V_35 ) ;
} while ( V_14 != V_104 );
if ( F_60 ( V_12 != NULL ) ) {
F_50 ( & V_14 -> V_103 , V_12 ) ;
V_14 -> V_63 . V_79 . V_119 [ V_22 ] -= F_48 ( V_12 ) ;
if ( V_14 -> V_63 . V_79 . V_119 [ V_22 ] < 0 ) {
V_14 -> V_63 . V_79 . V_119 [ V_22 ] += V_14 -> V_120 ;
F_16 ( V_22 ? & V_14 -> V_38 -> V_63 . V_64 . V_65 [ V_35 ] . V_59 :
& V_6 -> V_44 [ 0 ] . V_53 [ V_35 ] . V_59 ) ;
}
if ( ! V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 )
F_34 ( V_6 , V_14 ) ;
F_47 ( V_6 , V_14 , V_22 , V_12 ) ;
}
return V_12 ;
}
static struct V_11 * F_62 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_22 ;
T_2 V_121 ;
unsigned long V_122 ;
V_12 = F_63 ( & V_6 -> V_92 ) ;
if ( V_12 != NULL ) {
V_123:
F_64 ( V_4 , V_12 ) ;
F_65 ( V_4 , V_12 ) ;
V_4 -> V_6 . V_80 -- ;
return V_12 ;
}
if ( ! V_4 -> V_6 . V_80 )
goto V_124;
V_6 -> V_47 = F_66 () ;
V_122 = V_106 ;
V_121 = V_6 -> V_47 + 5LLU * V_125 ;
for ( V_22 = 0 ; V_22 < V_115 ; V_22 ++ ) {
int V_56 ;
T_2 V_126 = V_6 -> V_48 [ V_22 ] ;
if ( V_6 -> V_47 >= V_126 ) {
V_126 = F_51 ( V_6 , V_22 , V_122 ) ;
if ( ! V_126 )
V_126 = V_6 -> V_47 + V_125 ;
V_6 -> V_48 [ V_22 ] = V_126 ;
}
if ( V_121 > V_126 )
V_121 = V_126 ;
V_56 = ~ V_6 -> V_52 [ V_22 ] ;
while ( V_56 != ( int ) ( - 1 ) ) {
int V_35 = F_19 ( V_56 ) ;
V_56 |= 1 << V_35 ;
V_12 = F_58 ( V_6 , V_35 , V_22 ) ;
if ( F_60 ( V_12 != NULL ) )
goto V_123;
}
}
F_67 ( V_4 ) ;
if ( F_60 ( V_121 > V_6 -> V_47 ) )
F_68 ( & V_6 -> V_127 , V_121 ) ;
else
F_69 ( & V_6 -> V_128 ) ;
V_124:
return V_12 ;
}
static void F_70 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_6 -> V_9 . V_129 ; V_111 ++ ) {
F_71 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_14 -> V_22 )
memset ( & V_14 -> V_63 . V_64 , 0 , sizeof( V_14 -> V_63 . V_64 ) ) ;
else {
if ( V_14 -> V_63 . V_79 . V_6 )
F_72 ( V_14 -> V_63 . V_79 . V_6 ) ;
F_73 ( & V_14 -> V_63 . V_79 . V_81 ) ;
}
V_14 -> V_60 = 0 ;
V_14 -> V_61 = V_67 ;
}
}
F_74 ( & V_6 -> V_127 ) ;
F_75 ( & V_6 -> V_92 ) ;
V_4 -> V_6 . V_80 = 0 ;
V_4 -> V_130 . V_131 = 0 ;
memset ( V_6 -> V_44 , 0 , sizeof( V_6 -> V_44 ) ) ;
memset ( V_6 -> V_52 , 0 , sizeof( V_6 -> V_52 ) ) ;
for ( V_111 = 0 ; V_111 < V_132 ; V_111 ++ )
F_73 ( V_6 -> V_82 + V_111 ) ;
}
static void F_76 ( struct V_133 * V_128 )
{
struct V_5 * V_6 = F_4 ( V_128 , struct V_5 , V_128 ) ;
struct V_3 * V_4 = V_6 -> V_127 . V_134 ;
F_77 () ;
F_78 ( F_79 ( V_4 ) ) ;
F_80 () ;
}
static int F_81 ( struct V_3 * V_4 , struct V_135 * V_136 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_135 * V_137 [ V_138 + 1 ] ;
struct V_139 * V_140 ;
int V_141 ;
int V_111 ;
if ( ! V_136 )
return - V_142 ;
V_141 = F_82 ( V_137 , V_138 , V_136 , V_143 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! V_137 [ V_144 ] )
return - V_142 ;
V_140 = F_83 ( V_137 [ V_144 ] ) ;
if ( V_140 -> V_145 != V_146 >> 16 )
return - V_142 ;
V_141 = F_84 ( & V_6 -> V_9 ) ;
if ( V_141 < 0 )
return V_141 ;
for ( V_111 = 0 ; V_111 < V_132 ; V_111 ++ )
F_73 ( V_6 -> V_82 + V_111 ) ;
F_85 ( & V_6 -> V_127 , V_4 ) ;
F_86 ( & V_6 -> V_128 , F_76 ) ;
F_87 ( & V_6 -> V_92 ) ;
if ( V_137 [ V_147 ] )
V_6 -> V_93 = F_88 ( V_137 [ V_147 ] ) ;
else
V_6 -> V_93 = F_89 ( V_4 ) -> V_148 ;
if ( ( V_6 -> V_149 = V_140 -> V_149 ) < 1 )
V_6 -> V_149 = 1 ;
V_6 -> V_32 = V_140 -> V_32 ;
return 0 ;
}
static int F_90 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_135 * V_150 ;
struct V_139 V_140 ;
V_140 . V_94 = V_6 -> V_94 ;
V_140 . V_145 = V_146 ;
V_140 . V_149 = V_6 -> V_149 ;
V_140 . V_32 = V_6 -> V_32 ;
V_140 . V_151 = 0 ;
V_150 = F_91 ( V_12 , V_152 ) ;
if ( V_150 == NULL )
goto V_153;
if ( F_92 ( V_12 , V_144 , sizeof( V_140 ) , & V_140 ) ||
F_93 ( V_12 , V_147 , V_6 -> V_93 ) )
goto V_153;
return F_94 ( V_12 , V_150 ) ;
V_153:
F_95 ( V_12 , V_150 ) ;
return - 1 ;
}
static int F_96 ( struct V_3 * V_4 , unsigned long V_154 ,
struct V_11 * V_12 , struct V_155 * V_156 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
struct V_135 * V_150 ;
struct V_157 V_136 ;
V_156 -> V_158 = V_14 -> V_38 ? V_14 -> V_38 -> V_10 . V_31 : V_159 ;
V_156 -> V_160 = V_14 -> V_10 . V_31 ;
if ( ! V_14 -> V_22 && V_14 -> V_63 . V_79 . V_6 )
V_156 -> V_161 = V_14 -> V_63 . V_79 . V_6 -> V_2 ;
V_150 = F_91 ( V_12 , V_152 ) ;
if ( V_150 == NULL )
goto V_153;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
F_97 ( & V_136 . V_96 , & V_14 -> V_96 ) ;
V_136 . V_72 = F_98 ( V_14 -> V_72 ) ;
F_97 ( & V_136 . ceil , & V_14 -> ceil ) ;
V_136 . V_71 = F_98 ( V_14 -> V_71 ) ;
V_136 . V_120 = V_14 -> V_120 ;
V_136 . V_35 = V_14 -> V_35 ;
V_136 . V_22 = V_14 -> V_22 ;
if ( F_92 ( V_12 , V_162 , sizeof( V_136 ) , & V_136 ) )
goto V_153;
if ( ( V_14 -> V_96 . V_163 >= ( 1ULL << 32 ) ) &&
F_99 ( V_12 , V_164 , V_14 -> V_96 . V_163 ,
V_165 ) )
goto V_153;
if ( ( V_14 -> ceil . V_163 >= ( 1ULL << 32 ) ) &&
F_99 ( V_12 , V_166 , V_14 -> ceil . V_163 ,
V_165 ) )
goto V_153;
return F_94 ( V_12 , V_150 ) ;
V_153:
F_95 ( V_12 , V_150 ) ;
return - 1 ;
}
static int
F_100 ( struct V_3 * V_4 , unsigned long V_154 , struct V_167 * V_168 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
struct V_169 V_170 = {
. V_82 = V_14 -> V_82 ,
} ;
T_3 V_80 = 0 ;
if ( ! V_14 -> V_22 && V_14 -> V_63 . V_79 . V_6 ) {
V_80 = V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 ;
V_170 . V_131 = V_14 -> V_63 . V_79 . V_6 -> V_130 . V_131 ;
}
V_14 -> V_100 . V_77 = F_101 ( T_2 , F_98 ( V_14 -> V_77 ) ,
V_171 , V_172 ) ;
V_14 -> V_100 . V_76 = F_101 ( T_2 , F_98 ( V_14 -> V_76 ) ,
V_171 , V_172 ) ;
if ( F_102 ( F_103 ( V_4 ) ,
V_168 , NULL , & V_14 -> V_103 ) < 0 ||
F_104 ( V_168 , & V_14 -> V_173 ) < 0 ||
F_105 ( V_168 , NULL , & V_170 , V_80 ) < 0 )
return - 1 ;
return F_106 ( V_168 , & V_14 -> V_100 , sizeof( V_14 -> V_100 ) ) ;
}
static int F_107 ( struct V_3 * V_4 , unsigned long V_154 , struct V_3 * V_174 ,
struct V_3 * * V_175 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
if ( V_14 -> V_22 )
return - V_142 ;
if ( V_174 == NULL &&
( V_174 = F_108 ( V_4 -> V_176 , & V_177 ,
V_14 -> V_10 . V_31 ) ) == NULL )
return - V_178 ;
* V_175 = F_109 ( V_4 , V_174 , & V_14 -> V_63 . V_79 . V_6 ) ;
return 0 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 , unsigned long V_154 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
return ! V_14 -> V_22 ? V_14 -> V_63 . V_79 . V_6 : NULL ;
}
static void F_111 ( struct V_3 * V_4 , unsigned long V_154 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
if ( V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 == 0 )
F_34 ( F_2 ( V_4 ) , V_14 ) ;
}
static unsigned long F_112 ( struct V_3 * V_4 , T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_179 ++ ;
return ( unsigned long ) V_14 ;
}
static inline int F_113 ( struct V_1 * V_14 )
{
if ( ! V_14 -> V_38 )
return 0 ;
if ( V_14 -> V_38 -> V_180 > 1 )
return 0 ;
return 1 ;
}
static void F_114 ( struct V_5 * V_6 , struct V_1 * V_14 ,
struct V_3 * V_181 )
{
struct V_1 * V_38 = V_14 -> V_38 ;
F_22 ( V_14 -> V_22 || ! V_14 -> V_63 . V_79 . V_6 || V_14 -> V_60 ) ;
if ( V_38 -> V_61 != V_67 )
F_20 ( & V_38 -> V_49 ,
& V_6 -> V_44 [ V_38 -> V_22 ] . V_45 ) ;
V_38 -> V_22 = 0 ;
memset ( & V_38 -> V_63 . V_64 , 0 , sizeof( V_38 -> V_63 . V_64 ) ) ;
F_73 ( & V_38 -> V_63 . V_79 . V_81 ) ;
V_38 -> V_63 . V_79 . V_6 = V_181 ? V_181 : & V_182 ;
V_38 -> V_77 = V_38 -> V_72 ;
V_38 -> V_76 = V_38 -> V_71 ;
V_38 -> V_99 = F_66 () ;
V_38 -> V_61 = V_67 ;
}
static void F_115 ( struct V_3 * V_4 , struct V_1 * V_14 )
{
if ( ! V_14 -> V_22 ) {
F_22 ( ! V_14 -> V_63 . V_79 . V_6 ) ;
F_116 ( V_14 -> V_63 . V_79 . V_6 ) ;
}
F_117 ( & V_14 -> V_173 ) ;
F_118 ( & V_14 -> V_23 ) ;
F_119 ( V_14 ) ;
}
static void F_120 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_183 * V_87 ;
struct V_1 * V_14 ;
unsigned int V_111 ;
F_121 ( & V_6 -> V_128 ) ;
F_74 ( & V_6 -> V_127 ) ;
F_118 ( & V_6 -> V_23 ) ;
for ( V_111 = 0 ; V_111 < V_6 -> V_9 . V_129 ; V_111 ++ ) {
F_71 (cl, &q->clhash.hash[i], common.hnode)
F_118 ( & V_14 -> V_23 ) ;
}
for ( V_111 = 0 ; V_111 < V_6 -> V_9 . V_129 ; V_111 ++ ) {
F_122 (cl, next, &q->clhash.hash[i],
common.hnode)
F_115 ( V_4 , V_14 ) ;
}
F_123 ( & V_6 -> V_9 ) ;
F_75 ( & V_6 -> V_92 ) ;
}
static int F_124 ( struct V_3 * V_4 , unsigned long V_154 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
struct V_3 * V_181 = NULL ;
int V_184 = 0 ;
if ( V_14 -> V_180 || V_14 -> V_185 )
return - V_186 ;
if ( ! V_14 -> V_22 && F_113 ( V_14 ) ) {
V_181 = F_108 ( V_4 -> V_176 , & V_177 ,
V_14 -> V_38 -> V_10 . V_31 ) ;
V_184 = 1 ;
}
F_125 ( V_4 ) ;
if ( ! V_14 -> V_22 ) {
unsigned int V_80 = V_14 -> V_63 . V_79 . V_6 -> V_6 . V_80 ;
unsigned int V_131 = V_14 -> V_63 . V_79 . V_6 -> V_130 . V_131 ;
F_72 ( V_14 -> V_63 . V_79 . V_6 ) ;
F_126 ( V_14 -> V_63 . V_79 . V_6 , V_80 , V_131 ) ;
}
F_127 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_14 -> V_38 )
V_14 -> V_38 -> V_180 -- ;
if ( V_14 -> V_60 )
F_34 ( V_6 , V_14 ) ;
if ( V_14 -> V_61 != V_67 )
F_20 ( & V_14 -> V_49 ,
& V_6 -> V_44 [ V_14 -> V_22 ] . V_45 ) ;
if ( V_184 )
F_114 ( V_6 , V_14 , V_181 ) ;
F_57 ( -- V_14 -> V_179 == 0 ) ;
F_128 ( V_4 ) ;
return 0 ;
}
static void F_129 ( struct V_3 * V_4 , unsigned long V_154 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
if ( -- V_14 -> V_179 == 0 )
F_115 ( V_4 , V_14 ) ;
}
static int F_130 ( struct V_3 * V_4 , T_1 V_31 ,
T_1 V_187 , struct V_135 * * V_188 ,
unsigned long * V_154 )
{
int V_141 = - V_142 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) * V_154 , * V_38 ;
struct V_135 * V_136 = V_188 [ V_152 ] ;
struct V_135 * V_137 [ V_138 + 1 ] ;
struct V_157 * V_189 ;
T_4 V_190 , V_191 ;
if ( ! V_136 )
goto V_192;
V_141 = F_82 ( V_137 , V_138 , V_136 , V_143 , NULL ) ;
if ( V_141 < 0 )
goto V_192;
V_141 = - V_142 ;
if ( V_137 [ V_162 ] == NULL )
goto V_192;
V_38 = V_187 == V_159 ? NULL : F_1 ( V_187 , V_4 ) ;
V_189 = F_83 ( V_137 [ V_162 ] ) ;
if ( ! V_189 -> V_96 . V_96 || ! V_189 -> ceil . V_96 )
goto V_192;
if ( V_189 -> V_96 . V_193 == V_194 )
F_131 ( F_132 ( & V_189 -> V_96 , V_137 [ V_195 ] ) ) ;
if ( V_189 -> ceil . V_193 == V_194 )
F_131 ( F_132 ( & V_189 -> ceil , V_137 [ V_196 ] ) ) ;
if ( ! V_14 ) {
struct V_3 * V_181 ;
int V_35 ;
struct {
struct V_135 V_197 ;
struct V_198 V_136 ;
} V_199 = {
. V_197 = {
. V_200 = F_133 ( sizeof( V_199 . V_136 ) ) ,
. V_201 = V_202 ,
} ,
. V_136 = {
. V_203 = 2 ,
. V_204 = 2 ,
} ,
} ;
if ( ! V_31 || F_10 ( V_31 ^ V_4 -> V_2 ) ||
F_1 ( V_31 , V_4 ) )
goto V_192;
if ( V_38 && V_38 -> V_38 && V_38 -> V_38 -> V_22 < 2 ) {
F_134 ( L_3 ) ;
goto V_192;
}
V_141 = - V_178 ;
V_14 = F_135 ( sizeof( * V_14 ) , V_205 ) ;
if ( ! V_14 )
goto V_192;
if ( V_206 || V_188 [ V_202 ] ) {
V_141 = F_136 ( & V_14 -> V_103 , NULL ,
& V_14 -> V_173 ,
NULL ,
F_103 ( V_4 ) ,
V_188 [ V_202 ] ? : & V_199 . V_197 ) ;
if ( V_141 ) {
F_119 ( V_14 ) ;
goto V_192;
}
}
V_14 -> V_179 = 1 ;
V_14 -> V_180 = 0 ;
F_73 ( & V_14 -> V_63 . V_79 . V_81 ) ;
F_24 ( & V_14 -> V_49 ) ;
for ( V_35 = 0 ; V_35 < V_132 ; V_35 ++ )
F_24 ( & V_14 -> V_40 [ V_35 ] ) ;
V_181 = F_108 ( V_4 -> V_176 ,
& V_177 , V_31 ) ;
F_125 ( V_4 ) ;
if ( V_38 && ! V_38 -> V_22 ) {
unsigned int V_80 = V_38 -> V_63 . V_79 . V_6 -> V_6 . V_80 ;
unsigned int V_131 = V_38 -> V_63 . V_79 . V_6 -> V_130 . V_131 ;
F_72 ( V_38 -> V_63 . V_79 . V_6 ) ;
F_126 ( V_38 -> V_63 . V_79 . V_6 , V_80 , V_131 ) ;
F_116 ( V_38 -> V_63 . V_79 . V_6 ) ;
if ( V_38 -> V_60 )
F_34 ( V_6 , V_38 ) ;
if ( V_38 -> V_61 != V_67 ) {
F_20 ( & V_38 -> V_49 , & V_6 -> V_44 [ 0 ] . V_45 ) ;
V_38 -> V_61 = V_67 ;
}
V_38 -> V_22 = ( V_38 -> V_38 ? V_38 -> V_38 -> V_22
: V_115 ) - 1 ;
memset ( & V_38 -> V_63 . V_64 , 0 , sizeof( V_38 -> V_63 . V_64 ) ) ;
}
V_14 -> V_63 . V_79 . V_6 = V_181 ? V_181 : & V_182 ;
V_14 -> V_10 . V_31 = V_31 ;
V_14 -> V_38 = V_38 ;
V_14 -> V_77 = F_137 ( V_189 -> V_72 ) ;
V_14 -> V_76 = F_137 ( V_189 -> V_71 ) ;
V_14 -> V_97 = 60ULL * V_125 ;
V_14 -> V_99 = F_66 () ;
V_14 -> V_61 = V_67 ;
F_138 ( & V_6 -> V_9 , & V_14 -> V_10 ) ;
if ( V_38 )
V_38 -> V_180 ++ ;
if ( V_14 -> V_63 . V_79 . V_6 != & V_182 )
F_139 ( V_14 -> V_63 . V_79 . V_6 , true ) ;
} else {
if ( V_188 [ V_202 ] ) {
V_141 = F_140 ( & V_14 -> V_103 , NULL ,
& V_14 -> V_173 ,
NULL ,
F_103 ( V_4 ) ,
V_188 [ V_202 ] ) ;
if ( V_141 )
return V_141 ;
}
F_125 ( V_4 ) ;
}
V_190 = V_137 [ V_164 ] ? F_141 ( V_137 [ V_164 ] ) : 0 ;
V_191 = V_137 [ V_166 ] ? F_141 ( V_137 [ V_166 ] ) : 0 ;
F_142 ( & V_14 -> V_96 , & V_189 -> V_96 , V_190 ) ;
F_142 ( & V_14 -> ceil , & V_189 -> ceil , V_191 ) ;
if ( ! V_14 -> V_22 ) {
T_4 V_120 = V_14 -> V_96 . V_163 ;
F_143 ( V_120 , V_6 -> V_149 ) ;
V_14 -> V_120 = F_49 ( T_4 , V_120 , V_172 ) ;
if ( ! V_189 -> V_120 && V_14 -> V_120 < 1000 ) {
F_54 ( L_4 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_120 = 1000 ;
}
if ( ! V_189 -> V_120 && V_14 -> V_120 > 200000 ) {
F_54 ( L_5 ,
V_14 -> V_10 . V_31 ) ;
V_14 -> V_120 = 200000 ;
}
if ( V_189 -> V_120 )
V_14 -> V_120 = V_189 -> V_120 ;
if ( ( V_14 -> V_35 = V_189 -> V_35 ) >= V_132 )
V_14 -> V_35 = V_132 - 1 ;
}
V_14 -> V_72 = F_137 ( V_189 -> V_72 ) ;
V_14 -> V_71 = F_137 ( V_189 -> V_71 ) ;
F_128 ( V_4 ) ;
F_144 ( V_4 , & V_6 -> V_9 ) ;
* V_154 = ( unsigned long ) V_14 ;
return 0 ;
V_192:
return V_141 ;
}
static struct V_17 T_5 * * F_145 ( struct V_3 * V_4 ,
unsigned long V_154 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
struct V_17 T_5 * * V_207 = V_14 ? & V_14 -> V_23 : & V_6 -> V_23 ;
return V_207 ;
}
static unsigned long F_146 ( struct V_3 * V_4 , unsigned long V_38 ,
T_1 V_31 )
{
struct V_1 * V_14 = F_1 ( V_31 , V_4 ) ;
if ( V_14 )
V_14 -> V_185 ++ ;
return ( unsigned long ) V_14 ;
}
static void F_147 ( struct V_3 * V_4 , unsigned long V_154 )
{
struct V_1 * V_14 = (struct V_1 * ) V_154 ;
if ( V_14 )
V_14 -> V_185 -- ;
}
static void F_148 ( struct V_3 * V_4 , struct V_208 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_14 ;
unsigned int V_111 ;
if ( V_154 -> V_209 )
return;
for ( V_111 = 0 ; V_111 < V_6 -> V_9 . V_129 ; V_111 ++ ) {
F_71 (cl, &q->clhash.hash[i], common.hnode) {
if ( V_154 -> V_210 < V_154 -> V_211 ) {
V_154 -> V_210 ++ ;
continue;
}
if ( V_154 -> V_212 ( V_4 , ( unsigned long ) V_14 , V_154 ) < 0 ) {
V_154 -> V_209 = 1 ;
return;
}
V_154 -> V_210 ++ ;
}
}
}
static int T_6 F_149 ( void )
{
return F_150 ( & V_213 ) ;
}
static void T_7 F_151 ( void )
{
F_152 ( & V_213 ) ;
}
