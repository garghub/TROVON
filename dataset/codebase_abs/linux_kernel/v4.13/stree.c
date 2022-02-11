inline int F_1 ( const struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) > V_3 ,
L_1 , V_2 , V_2 ) ;
return ( F_3 ( V_2 ) != V_4 ) ;
}
inline void F_4 ( struct V_5 * V_6 ,
const struct V_5 * V_7 )
{
memcpy ( V_6 , V_7 , V_8 ) ;
}
inline int F_5 ( const struct V_9 * V_10 ,
const struct V_11 * V_11 )
{
T_1 V_12 ;
V_12 = F_6 ( V_10 -> V_13 ) ;
if ( V_12 < V_11 -> V_14 . V_13 )
return - 1 ;
if ( V_12 > V_11 -> V_14 . V_13 )
return 1 ;
V_12 = F_6 ( V_10 -> V_15 ) ;
if ( V_12 < V_11 -> V_14 . V_15 )
return - 1 ;
if ( V_12 > V_11 -> V_14 . V_15 )
return 1 ;
return 0 ;
}
static inline int F_7 ( const struct V_9 * V_10 ,
const struct V_11 * V_11 )
{
int V_16 ;
V_16 = F_5 ( V_10 , V_11 ) ;
if ( V_16 )
return V_16 ;
if ( F_8 ( F_9 ( V_10 ) , V_10 ) <
F_10 ( V_11 ) )
return - 1 ;
if ( F_8 ( F_9 ( V_10 ) , V_10 ) >
F_10 ( V_11 ) )
return 1 ;
if ( V_11 -> V_17 == 3 )
return 0 ;
if ( F_11 ( F_9 ( V_10 ) , V_10 ) <
F_12 ( V_11 ) )
return - 1 ;
if ( F_11 ( F_9 ( V_10 ) , V_10 ) >
F_12 ( V_11 ) )
return 1 ;
return 0 ;
}
inline int F_13 ( const struct V_9 * V_18 ,
const struct V_9 * V_19 )
{
T_1 * V_20 , * V_21 ;
int V_17 = V_22 ;
V_20 = ( T_1 * ) V_18 ;
V_21 = ( T_1 * ) V_19 ;
for (; V_17 -- ; ++ V_20 , ++ V_21 ) {
if ( F_6 ( * V_20 ) < F_6 ( * V_21 ) )
return - 1 ;
if ( F_6 ( * V_20 ) > F_6 ( * V_21 ) )
return 1 ;
}
return 0 ;
}
inline void F_14 ( struct V_11 * V_6 , const struct V_9 * V_7 )
{
int V_23 ;
V_6 -> V_14 . V_13 = F_6 ( V_7 -> V_13 ) ;
V_6 -> V_14 . V_15 = F_6 ( V_7 -> V_15 ) ;
V_23 = F_9 ( V_7 ) ;
V_6 -> V_23 = V_23 ;
V_6 -> V_14 . V_24 = F_8 ( V_23 , V_7 ) ;
V_6 -> V_14 . V_25 = F_11 ( V_23 , V_7 ) ;
}
inline int F_15 ( const struct V_9 * V_26 ,
const struct V_9 * V_27 )
{
return memcmp ( V_26 , V_27 , sizeof( struct V_9 ) ) ;
}
static inline int F_16 ( const void * V_28 ,
const void * V_29 ,
int V_30 ,
int V_31 ,
int * V_32
)
{
int V_33 , V_34 , V_35 ;
for ( V_35 = ( ( V_33 = V_30 - 1 ) + ( V_34 = 0 ) ) / 2 ;
V_34 <= V_33 ; V_35 = ( V_33 + V_34 ) / 2 )
switch ( F_7
( (struct V_9 * ) ( ( char * ) V_29 + V_35 * V_31 ) ,
(struct V_11 * ) V_28 ) ) {
case - 1 :
V_34 = V_35 + 1 ;
continue;
case 1 :
V_33 = V_35 - 1 ;
continue;
case 0 :
* V_32 = V_35 ;
return V_36 ;
}
* V_32 = V_34 ;
return V_37 ;
}
static inline const struct V_9 * F_17 ( const struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
int V_42 , V_43 = V_39 -> V_44 ;
struct V_1 * V_45 ;
F_2 ( V_43 < V_46 ,
L_2 ) ;
while ( V_43 -- > V_46 ) {
F_2 ( ! F_18
( F_19 ( V_39 , V_43 ) ) ,
L_3 ) ;
if ( ! F_1
( V_45 =
F_19 ( V_39 , V_43 ) ) )
return & V_47 ;
if ( ( V_42 =
F_20 ( V_39 ,
V_43 ) ) >
F_21 ( V_45 ) )
return & V_47 ;
if ( F_22 ( V_45 , V_42 ) !=
F_19 ( V_39 ,
V_43 + 1 ) -> V_48 )
return & V_47 ;
if ( V_42 )
return F_23 ( V_45 , V_42 - 1 ) ;
}
if ( F_19 ( V_39 , V_46 ) ->
V_48 == F_24 ( V_41 ) )
return & V_49 ;
return & V_47 ;
}
inline const struct V_9 * F_25 ( const struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
int V_42 , V_43 = V_39 -> V_44 ;
struct V_1 * V_45 ;
F_2 ( V_43 < V_46 ,
L_4 ) ;
while ( V_43 -- > V_46 ) {
F_2 ( ! F_18
( F_19 ( V_39 , V_43 ) ) ,
L_5 ) ;
if ( ! F_1
( V_45 =
F_19 ( V_39 , V_43 ) ) )
return & V_49 ;
if ( ( V_42 =
F_20 ( V_39 ,
V_43 ) ) >
F_21 ( V_45 ) )
return & V_49 ;
if ( F_22 ( V_45 , V_42 ) !=
F_19 ( V_39 ,
V_43 + 1 ) -> V_48 )
return & V_49 ;
if ( V_42 != F_21 ( V_45 ) )
return F_23 ( V_45 , V_42 ) ;
}
if ( F_19 ( V_39 , V_46 ) ->
V_48 == F_24 ( V_41 ) )
return & V_47 ;
return & V_49 ;
}
static inline int F_26 (
struct V_38 * V_39 ,
const struct V_11 * V_28 ,
struct V_40 * V_41
)
{
F_2 ( ! V_28 || V_39 -> V_44 < V_46
|| V_39 -> V_44 > V_3 ,
L_6 ,
V_28 , V_39 -> V_44 ) ;
F_2 ( ! F_27 ( V_39 ) -> V_50 ,
L_7 ) ;
if ( F_7 ( F_17 ( V_39 , V_41 ) , V_28 ) == 1 )
return 0 ;
if ( F_7 ( F_25 ( V_39 , V_41 ) , V_28 ) != 1 )
return 0 ;
return 1 ;
}
int F_28 ( struct V_38 * V_51 )
{
F_2 ( V_51 -> V_44 != V_52 ,
L_8 ) ;
return 0 ;
}
void F_29 ( struct V_40 * V_41 ,
struct V_38 * V_53 )
{
int V_43 = V_53 -> V_44 ;
F_2 ( V_43 < V_52 ,
L_9 ) ;
while ( V_43 > V_52 ) {
struct V_1 * V_2 ;
V_2 = F_19 ( V_53 , V_43 -- ) ;
F_30 ( V_41 , V_2 ) ;
F_31 ( V_2 ) ;
}
V_53 -> V_44 = V_52 ;
}
void F_32 ( struct V_38 * V_53 )
{
int V_43 = V_53 -> V_44 ;
F_2 ( V_43 < V_52 ,
L_10 ) ;
while ( V_43 > V_52 )
F_31 ( F_19 ( V_53 , V_43 -- ) ) ;
V_53 -> V_44 = V_52 ;
}
static int F_33 ( char * V_54 , int V_55 , struct V_1 * V_2 )
{
struct V_56 * V_57 ;
struct V_5 * V_58 ;
int V_59 ;
int V_60 ;
int V_61 ;
int V_62 ;
V_57 = (struct V_56 * ) V_54 ;
if ( F_34 ( V_57 ) != V_63 ) {
F_35 ( NULL , L_11 ,
L_12 ) ;
return 0 ;
}
V_62 = F_36 ( V_57 ) ;
if ( V_62 < 1 || V_62 > ( ( V_55 - V_64 ) / ( V_8 + V_65 ) ) ) {
F_35 ( NULL , L_13 ,
L_14 , V_2 ) ;
return 0 ;
}
V_58 = (struct V_5 * ) ( V_54 + V_64 ) + V_62 - 1 ;
V_59 = V_64 + V_8 * V_62 + ( V_55 - F_37 ( V_58 ) ) ;
if ( V_59 != V_55 - F_38 ( V_57 ) ) {
F_35 ( NULL , L_15 ,
L_16 , V_2 ) ;
return 0 ;
}
V_58 = (struct V_5 * ) ( V_54 + V_64 ) ;
V_60 = V_55 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ , V_58 ++ ) {
if ( F_39 ( V_58 ) == V_66 ) {
F_35 ( NULL , L_17 ,
L_18 ,
V_58 ) ;
return 0 ;
}
if ( F_37 ( V_58 ) >= V_55
|| F_37 ( V_58 ) < V_8 * V_62 ) {
F_35 ( NULL , L_19 ,
L_20 ,
V_58 ) ;
return 0 ;
}
if ( F_40 ( V_58 ) < 1
|| F_40 ( V_58 ) > F_41 ( V_55 ) ) {
F_35 ( NULL , L_21 ,
L_22 ,
V_58 ) ;
return 0 ;
}
if ( V_60 - F_37 ( V_58 ) != F_40 ( V_58 ) ) {
F_35 ( NULL , L_23 ,
L_24
L_25 , V_58 ) ;
return 0 ;
}
V_60 = F_37 ( V_58 ) ;
}
return 1 ;
}
static int F_42 ( char * V_54 , int V_55 , struct V_1 * V_2 )
{
struct V_56 * V_57 ;
int V_62 ;
int V_59 ;
V_57 = (struct V_56 * ) V_54 ;
V_62 = F_34 ( V_57 ) ;
if ( V_62 <= V_63 || V_62 > V_3 ) {
F_35 ( NULL , L_26 ,
L_12 ) ;
return 0 ;
}
V_62 = F_36 ( V_57 ) ;
if ( V_62 > ( V_55 - V_64 - V_67 ) / ( V_68 + V_67 ) ) {
F_35 ( NULL , L_27 ,
L_28 , V_2 ) ;
return 0 ;
}
V_59 = V_64 + V_68 * V_62 + V_67 * ( V_62 + 1 ) ;
if ( V_59 != V_55 - F_38 ( V_57 ) ) {
F_35 ( NULL , L_29 ,
L_16 , V_2 ) ;
return 0 ;
}
return 1 ;
}
static int F_43 ( struct V_1 * V_2 , int V_69 )
{
if ( F_3 ( V_2 ) != V_69 ) {
F_35 ( NULL , L_30 , L_31
L_32 ,
F_3 ( V_2 ) , V_69 ) ;
return 0 ;
}
if ( V_69 == V_63 )
return F_33 ( V_2 -> V_70 , V_2 -> V_71 , V_2 ) ;
return F_42 ( V_2 -> V_70 , V_2 -> V_71 , V_2 ) ;
}
static int F_44 ( struct V_40 * V_72 ,
struct V_1 * * V_2 ,
T_2 * V_73 , int V_30 )
{
int V_61 , V_35 ;
int V_74 = - 1 ;
for ( V_61 = 0 ; V_61 < V_30 ; V_61 ++ ) {
V_2 [ V_61 ] = F_45 ( V_72 , V_73 [ V_61 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_61 ; V_35 ++ ) {
if ( ! F_18 ( V_2 [ V_35 ] ) ) {
if ( V_74 == - 1 )
V_74 = F_46 ( V_72 ) ;
F_47 ( V_75 , V_76 , 1 , V_2 + V_35 ) ;
}
F_31 ( V_2 [ V_35 ] ) ;
}
return V_74 ;
}
int F_48 ( struct V_40 * V_41 , const struct V_11 * V_28 ,
struct V_38 * V_53 , int V_77 )
{
T_2 V_78 ;
int V_79 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
int V_82 , V_16 ;
int V_83 ;
int V_84 ;
struct V_1 * V_85 [ V_86 ] ;
T_2 V_87 [ V_86 ] ;
int V_88 = 0 ;
#ifdef F_49
int V_89 = 0 ;
#endif
F_50 ( V_41 , F_48 ) ;
F_32 ( V_53 ) ;
V_83 = 0 ;
V_78 = F_24 ( V_41 ) ;
V_79 = - 1 ;
while ( 1 ) {
#ifdef F_49
if ( ! ( ++ V_89 % 50000 ) )
F_35 ( V_41 , L_33 ,
L_34
L_35 ,
V_90 -> V_91 , V_89 ,
V_28 ) ;
#endif
V_81 =
F_51 ( V_53 ,
++ V_53 -> V_44 ) ;
V_84 = F_52 ( V_41 ) ;
if ( ( V_2 = V_81 -> V_92 =
F_45 ( V_41 , V_78 ) ) ) {
int V_74 = - 1 ;
if ( ! F_18 ( V_2 ) && V_88 > 1 )
V_74 = F_44 ( V_41 , V_85 ,
V_87 , V_88 ) ;
if ( ! F_18 ( V_2 ) && V_74 == - 1 )
V_74 = F_46 ( V_41 ) ;
F_47 ( V_75 , 0 , 1 , & V_2 ) ;
F_53 ( V_2 ) ;
if ( V_74 != - 1 )
F_54 ( V_41 , V_74 ) ;
if ( ! F_18 ( V_2 ) )
goto V_93;
} else {
V_93:
V_53 -> V_44 -- ;
F_32 ( V_53 ) ;
return V_94 ;
}
V_88 = 0 ;
if ( V_79 == - 1 )
V_79 = F_55 ( V_41 ) ;
V_79 -- ;
if ( F_56 ( V_84 , V_41 ) &&
( ! F_1 ( V_2 ) ||
F_3 ( V_2 ) != V_79 ||
! F_26 ( V_53 , V_28 , V_41 ) ) ) {
F_50 ( V_41 , V_95 ) ;
F_50 ( V_41 , V_96 ) ;
F_50 ( V_41 ,
V_97 [ V_79 - 1 ] ) ;
F_32 ( V_53 ) ;
V_78 = F_24 ( V_41 ) ;
V_79 = - 1 ;
V_83 = 0 ;
continue;
}
F_2 ( F_7 ( & V_47 , V_28 ) &&
! F_26 ( V_53 , V_28 , V_41 ) ,
L_36 ) ;
#ifdef F_49
if ( F_57 ( V_41 ) -> V_98 ) {
F_58 ( L_37 ) ;
F_59 ( V_41 , L_38 ,
L_39 ) ;
}
#endif
if ( ! F_43 ( V_2 , V_79 ) ) {
F_60 ( V_41 , L_40 ,
L_41
L_42 , V_2 -> V_48 ) ;
F_32 ( V_53 ) ;
return V_94 ;
}
V_82 = F_3 ( V_2 ) ;
F_61 ( V_41 , V_2 , V_82 - 1 ) ;
F_2 ( V_82 < V_77 ,
L_43 ,
V_82 , V_77 ) ;
V_16 = F_16 ( V_28 , V_5 ( V_2 , 0 ) ,
F_21 ( V_2 ) ,
( V_82 ==
V_63 ) ? V_8 :
V_68 ,
& V_81 -> V_99 ) ;
if ( V_82 == V_77 ) {
return V_16 ;
}
if ( V_16 == V_36 )
V_81 -> V_99 ++ ;
V_78 =
F_22 ( V_2 , V_81 -> V_99 ) ;
if ( ( V_53 -> V_100 & V_101 ) &&
V_82 == V_63 + 1 ) {
int V_32 = V_81 -> V_99 ;
int V_102 = F_21 ( V_2 ) ;
struct V_9 * V_10 ;
if ( V_53 -> V_100 & V_103 )
V_102 = 0 ;
while ( V_88 < V_86 ) {
if ( V_32 == V_102 )
break;
V_87 [ V_88 ++ ] =
F_22 ( V_2 , V_32 ) ;
if ( V_53 -> V_100 & V_103 )
V_32 -- ;
else
V_32 ++ ;
V_10 = F_23 ( V_2 , V_32 ) ;
if ( F_6 ( V_10 -> V_15 ) !=
V_28 -> V_14 . V_15 ) {
break;
}
}
}
}
}
int F_62 ( struct V_40 * V_41 ,
const struct V_11 * V_104 ,
struct V_38 * V_53 )
{
struct V_5 * V_105 ;
int V_106 ;
T_3 V_107 , V_108 ;
struct V_109 V_110 ;
int V_16 ;
if ( F_63 ( V_104 ) )
return F_64 ( V_41 , V_104 , V_53 ,
& V_110 ) ;
V_16 = F_65 ( V_41 , V_104 , V_53 ) ;
if ( V_16 == V_94 )
return V_16 ;
if ( V_16 == V_36 ) {
F_2 ( ! F_40
( V_5
( F_27 ( V_53 ) ,
F_66 ( V_53 ) ) ) ,
L_44 ) ;
F_67 ( V_53 ) = 0 ;
return V_111 ;
}
F_2 ( ! F_66 ( V_53 ) ,
L_45 ) ;
V_105 =
V_5 ( F_27 ( V_53 ) ,
-- F_66 ( V_53 ) ) ;
V_106 = V_41 -> V_112 ;
if ( F_5 ( & V_105 -> V_113 , V_104 ) )
return V_114 ;
V_107 = F_68 ( V_105 ) ;
V_108 = F_10 ( V_104 ) ;
if ( V_107 <= V_108 &&
V_107 + F_69 ( V_105 , V_106 ) > V_108 ) {
F_67 ( V_53 ) = V_108 - V_107 ;
if ( F_70 ( V_105 ) ) {
F_67 ( V_53 ) /= V_106 ;
}
return V_111 ;
}
if ( F_70 ( V_105 ) )
F_67 ( V_53 ) =
F_40 ( V_105 ) / V_115 ;
else
F_67 ( V_53 ) = F_40 ( V_105 ) ;
return V_116 ;
}
int F_71 ( const struct V_5 * V_117 , const struct V_38 * V_118 )
{
struct V_1 * V_2 = F_27 ( V_118 ) ;
struct V_5 * V_58 ;
if ( ! F_1 ( V_2 ) )
return 1 ;
if ( F_66 ( V_118 ) >= F_21 ( V_2 ) )
return 1 ;
V_58 = F_72 ( V_118 ) ;
return memcmp ( V_117 , V_58 , V_8 ) ;
}
static inline int F_73 ( struct V_38 * V_118 ,
struct V_5 * V_119 ,
struct V_120 * V_120 ,
T_3 V_121 , int * V_122 )
{
T_3 V_123 ;
if ( V_121 == F_74 ( V_120 ) ) {
* V_122 = - ( V_8 + F_40 ( V_119 ) ) ;
return V_124 ;
}
if ( F_75 ( V_120 ) == V_125 ) {
V_123 = F_76 ( V_121 ) ;
if ( V_123 < F_68 ( V_119 ) ) {
* V_122 = - ( V_8 + F_40 ( V_119 ) ) ;
return V_124 ;
}
F_67 ( V_118 ) = V_123 - ( F_68 ( V_119 ) - 1 ) ;
* V_122 = - ( F_40 ( V_119 ) - F_67 ( V_118 ) ) ;
return V_126 ;
}
if ( V_121 < F_68 ( V_119 ) ) {
* V_122 = - ( V_8 + F_40 ( V_119 ) ) ;
return V_124 ;
}
* V_122 = - ( F_40 ( V_119 ) -
( F_67 ( V_118 ) =
V_121 + 1 - F_68 ( V_119 ) ) ) ;
return V_126 ;
}
static inline int F_77 ( struct V_38 * V_118 ,
struct V_5 * V_119 ,
struct V_120 * V_120 ,
T_3 V_121 ,
int * V_122 )
{
if ( F_68 ( V_119 ) == V_127 &&
V_121 == F_74 ( V_120 ) ) {
F_2 ( F_78 ( V_119 ) != 2 ,
L_46 , V_119 ) ;
* V_122 = - ( V_8 + F_40 ( V_119 ) ) ;
return V_124 ;
}
if ( F_78 ( V_119 ) == 1 ) {
* V_122 = - ( V_8 + F_40 ( V_119 ) ) ;
return V_124 ;
}
* V_122 =
- ( V_128 +
F_79 ( F_80 ( V_118 ) , V_119 , F_67 ( V_118 ) ) ) ;
return V_126 ;
}
static char F_81 ( struct V_129 * V_130 ,
struct V_120 * V_120 ,
struct V_38 * V_118 ,
const struct V_11 * V_131 ,
int * V_132 ,
int * V_122 ,
unsigned long long V_121
)
{
struct V_40 * V_41 = V_120 -> V_133 ;
struct V_5 * V_105 = F_72 ( V_118 ) ;
struct V_1 * V_2 = F_27 ( V_118 ) ;
F_82 ( ! V_130 -> V_134 ) ;
if ( F_83 ( V_105 ) ) {
F_2 ( V_121 != F_74 ( V_120 ) ,
L_47 ) ;
* V_122 = - ( V_8 + F_40 ( V_105 ) ) ;
return V_124 ;
}
if ( F_84 ( V_105 ) )
return F_77 ( V_118 , V_105 , V_120 ,
V_121 ,
V_122 ) ;
if ( F_85 ( V_105 ) )
return F_73 ( V_118 , V_105 , V_120 ,
V_121 , V_122 ) ;
{
int V_106 = V_41 -> V_112 ;
struct V_5 V_135 ;
int V_136 ;
int V_137 = 0 ;
int V_138 = V_126 ;
int V_32 = 0 ;
if ( V_121 == F_74 ( V_120 ) ) {
V_121 = 0 ;
V_137 = 1 ;
}
do {
V_136 = 0 ;
* V_122 = 0 ;
V_2 = F_27 ( V_118 ) ;
F_4 ( & V_135 , F_72 ( V_118 ) ) ;
V_32 = F_86 ( & V_135 ) ;
while ( F_68 ( & V_135 ) + ( V_32 - 1 ) * V_106 > V_121 ) {
T_4 * V_139 ;
T_1 V_140 ;
if ( ! V_137 && ( * V_122 ) != 0 &&
F_87 ( V_130 ) < V_141 )
break;
V_139 = ( T_4 * ) F_88 ( V_2 , & V_135 ) + V_32 - 1 ;
V_140 = F_89 ( V_139 , 0 ) ;
if ( V_140 != 0 ) {
F_90 ( V_41 , V_2 , 1 ) ;
F_91 ( V_139 , 0 , 0 ) ;
F_92 ( V_130 , V_2 ) ;
F_93 ( V_130 , V_120 , V_140 , 1 ) ;
}
F_94 ( V_41 ) ;
if ( F_95 ( & V_135 , V_118 ) ) {
V_136 = 1 ;
break;
}
V_32 -- ;
( * V_132 ) ++ ;
( * V_122 ) -= V_115 ;
if ( V_32 == 0 ) {
( * V_122 ) -= V_8 ;
V_138 = V_124 ;
break;
}
}
F_30 ( V_41 , V_2 ) ;
} while ( V_136 &&
F_62 ( V_41 , V_131 , V_118 ) == V_111 );
F_67 ( V_118 ) = V_32 * V_115 ;
if ( * V_122 == 0 ) {
V_138 = V_142 ;
}
return V_138 ;
}
}
static int F_96 ( struct V_143 * V_144 , char V_145 )
{
int V_146 ;
struct V_5 * V_105 = F_72 ( V_144 -> V_147 ) ;
if ( F_83 ( V_105 ) )
return 0 ;
V_146 =
( V_145 ==
V_124 ) ? F_40 ( V_105 ) : - V_144 -> V_148 [ 0 ] ;
if ( F_84 ( V_105 ) ) {
return V_146 ;
}
if ( F_70 ( V_105 ) )
V_146 = ( V_146 / V_115 ) *
( F_27 ( V_144 -> V_147 ) -> V_71 ) ;
return V_146 ;
}
static void F_97 ( struct V_129 * V_130 ,
struct V_143 * V_144 ,
struct V_40 * V_41 ,
struct V_38 * V_118 , int V_149 )
{
F_82 ( ! V_130 -> V_134 ) ;
memset ( V_144 , '\0' , sizeof( struct V_143 ) ) ;
V_144 -> V_150 = V_130 ;
V_144 -> V_151 = V_41 ;
V_144 -> V_147 = V_118 ;
F_19 ( V_118 , V_52 ) = NULL ;
F_20 ( V_118 , V_52 ) = 0 ;
V_144 -> V_148 [ 0 ] = V_149 ;
}
void F_98 ( char * V_152 , int V_153 , int V_154 )
{
int V_61 ;
for ( V_61 = V_153 ; V_61 > V_154 ; )
V_152 [ -- V_61 ] = 0 ;
}
char F_99 ( struct V_9 * V_58 )
{
if ( F_100 ( 2 , V_58 ) )
return 'd' ;
if ( F_101 ( 2 , V_58 ) )
return 'D' ;
if ( F_102 ( 2 , V_58 ) )
return 'i' ;
if ( F_103 ( 2 , V_58 ) )
return 's' ;
return 'u' ;
}
char F_104 ( struct V_5 * V_58 )
{
if ( F_84 ( V_58 ) )
return 'd' ;
if ( F_85 ( V_58 ) )
return 'D' ;
if ( F_70 ( V_58 ) )
return 'i' ;
if ( F_83 ( V_58 ) )
return 's' ;
return 'u' ;
}
int F_105 ( struct V_129 * V_130 ,
struct V_38 * V_118 , const struct V_11 * V_131 ,
struct V_120 * V_120 , struct V_1 * V_155 )
{
struct V_40 * V_41 = V_120 -> V_133 ;
struct V_143 V_156 ;
struct V_5 V_135 ;
struct V_5 * V_157 ;
int V_158 ;
int V_159 , V_146 , V_132 ;
int V_74 ;
#ifdef F_49
char V_145 ;
int V_160 = 0 ;
#endif
F_82 ( ! V_130 -> V_134 ) ;
F_97 ( V_130 , & V_156 , V_41 , V_118 ,
0 ) ;
while ( 1 ) {
V_132 = 0 ;
#ifdef F_49
V_160 ++ ;
V_145 =
#endif
F_81 ( V_130 , V_120 , V_118 ,
V_131 , & V_132 ,
& V_146 ,
F_74 ( V_120 ) ) ;
F_2 ( V_145 != V_124 , L_48 ) ;
F_4 ( & V_135 , F_72 ( V_118 ) ) ;
V_156 . V_148 [ 0 ] = V_146 ;
V_159 = F_106 ( V_124 , & V_156 , NULL , NULL ) ;
if ( V_159 != V_161 )
break;
F_50 ( V_41 , V_162 ) ;
V_159 =
F_62 ( V_41 , V_131 , V_118 ) ;
if ( V_159 == V_94 )
break;
if ( V_159 == V_114 ) {
F_35 ( V_41 , L_49 ,
L_50 ,
V_131 ) ;
break;
}
}
if ( V_159 != V_163 ) {
F_107 ( & V_156 ) ;
return 0 ;
}
V_159 = F_96 ( & V_156 , V_124 ) ;
V_157 = F_72 ( V_118 ) ;
V_158 = F_40 ( V_157 ) ;
if ( ! F_108 ( V_120 -> V_164 ) && F_85 ( V_157 ) ) {
if ( ( F_68 ( V_157 ) & ( V_41 -> V_112 - 1 ) ) == 1 ) {
V_158 = V_41 -> V_112 + V_115 ;
} else {
V_158 = 0 ;
}
}
if ( V_155 ) {
int V_165 ;
char * V_166 ;
V_166 = F_109 ( V_155 -> V_167 ) ;
V_165 = ( ( F_68 ( & V_135 ) - 1 ) & ( V_168 - 1 ) ) ;
memcpy ( V_166 + V_165 ,
F_88 ( F_27 ( V_118 ) , & V_135 ) ,
V_159 ) ;
F_110 ( V_166 ) ;
}
F_111 ( & V_156 , NULL , NULL , V_124 ) ;
#ifdef F_112
F_113 ( V_41 , V_169 ,
L_51 ,
V_158 , V_120 -> V_170 , F_104 ( & V_135 ) ) ;
#endif
V_74 = F_46 ( V_120 -> V_133 ) ;
F_114 ( V_120 , V_158 ) ;
F_54 ( V_120 -> V_133 , V_74 ) ;
return V_159 ;
}
void F_115 ( struct V_129 * V_130 ,
struct V_120 * V_120 , struct V_9 * V_28 )
{
struct V_40 * V_41 = V_130 -> V_171 ;
struct V_143 V_144 ;
F_116 ( V_118 ) ;
int V_172 = 0 ;
int V_173 = 0 ;
struct V_11 V_11 ;
int V_16 ;
int V_158 = 0 ;
F_82 ( ! V_130 -> V_134 ) ;
F_14 ( & V_11 , V_28 ) ;
while ( 1 ) {
V_16 = F_65 ( V_130 -> V_171 , & V_11 , & V_118 ) ;
if ( V_16 == V_94 ) {
F_60 ( V_130 -> V_171 , L_52 ,
L_53
L_54 , & V_11 ) ;
break;
}
if ( V_16 != V_36 ) {
F_32 ( & V_118 ) ;
if ( !
( ( unsigned long long )
F_117 ( F_8
( F_9 ( V_28 ) , V_28 ) ) == 0
&& ( unsigned long long )
F_118 ( F_8
( F_9 ( V_28 ) ,
V_28 ) ) == 1 ) )
F_35 ( V_130 -> V_171 , L_55 ,
L_56 , V_28 ) ;
break;
}
if ( ! V_173 ) {
V_173 = 1 ;
V_172 = F_40 ( F_72 ( & V_118 ) ) ;
F_97 ( V_130 , & V_144 , V_130 -> V_171 , & V_118 ,
- ( V_8 + V_172 ) ) ;
}
V_158 = F_40 ( F_72 ( & V_118 ) ) ;
V_16 = F_106 ( V_124 , & V_144 , NULL , NULL ) ;
if ( V_16 == V_161 ) {
F_50 ( V_130 -> V_171 , V_174 ) ;
continue;
}
if ( V_16 == V_163 ) {
F_111 ( & V_144 , NULL , NULL , V_124 ) ;
if ( V_120 ) {
int V_74 ;
#ifdef F_112
F_113 ( V_130 -> V_171 , V_169 ,
L_57 ,
V_158 , V_120 -> V_170 ,
F_99 ( V_28 ) ) ;
#endif
V_74 = F_46 ( V_41 ) ;
F_114 ( V_120 ,
V_158 ) ;
F_54 ( V_41 , V_74 ) ;
}
break;
}
F_35 ( V_130 -> V_171 , L_58 ,
L_59 ,
& V_11 ) ;
F_107 ( & V_144 ) ;
break;
}
F_28 ( & V_118 ) ;
}
int F_119 ( struct V_129 * V_130 ,
struct V_120 * V_120 )
{
int V_175 ;
V_120 -> V_176 = 0 ;
F_82 ( ! V_130 -> V_134 ) ;
V_175 =
F_120 ( V_130 , V_120 , NULL , 0 ) ;
if ( V_175 )
return V_175 ;
#if F_121 ( V_177 )
if ( ! F_122 ( V_130 -> V_171 ) ) {
T_4 * V_178 ;
V_178 =
& F_57 ( V_130 -> V_171 ) -> V_179 -> V_180 ;
F_123 ( V_178 , 1 ) ;
}
#endif
F_115 ( V_130 , V_120 , F_124 ( V_120 ) ) ;
return V_175 ;
}
static void F_125 ( struct V_181 * V_181 , T_3 V_32 )
{
struct V_1 * V_2 ;
struct V_1 * V_182 ;
struct V_1 * V_183 ;
unsigned long V_184 ;
unsigned long V_185 ;
if ( V_181 ) {
if ( F_126 ( V_181 ) ) {
V_184 = V_32 & ( V_168 - 1 ) ;
V_185 = 0 ;
V_182 = F_127 ( V_181 ) ;
V_2 = V_182 ;
do {
V_183 = V_2 -> V_186 ;
V_185 += V_2 -> V_71 ;
if ( V_185 > V_184 ) {
F_128 ( V_2 ) ;
}
V_2 = V_183 ;
} while ( V_2 != V_182 );
}
}
}
static int F_129 ( struct V_129 * V_130 ,
struct V_120 * V_120 ,
struct V_181 * V_181 ,
struct V_38 * V_118 ,
const struct V_11 * V_131 ,
T_3 V_187 , char * V_145 )
{
struct V_40 * V_41 = V_120 -> V_133 ;
int V_188 = V_41 -> V_112 ;
int V_189 ;
F_82 ( ! V_130 -> V_134 ) ;
F_82 ( V_187 != V_120 -> V_176 ) ;
if ( F_130 ( & V_120 -> V_190 ) > 1 ||
! F_131 ( V_120 ) ||
! V_181 || ( F_132 ( V_120 ) -> V_191 & V_192 ) ) {
* V_145 = V_193 ;
V_189 =
V_188 - ( V_187 & ( V_188 - 1 ) ) ;
F_32 ( V_118 ) ;
return V_189 ;
}
return F_133 ( V_130 , V_120 , V_181 , V_118 , V_131 ,
V_187 , V_145 ) ;
}
static void F_134 ( struct V_129 * V_130 ,
struct V_120 * V_120 , struct V_38 * V_118 )
{
struct V_11 V_194 ;
int V_195 ;
int V_132 ;
F_82 ( ! V_130 -> V_134 ) ;
F_135 ( & V_194 , V_120 , V_120 -> V_176 + 1 , V_196 , 4 ) ;
V_194 . V_17 = 4 ;
V_195 =
( F_10 ( & V_194 ) & ( V_120 -> V_133 -> V_112 - 1 ) ) - 1 ;
while ( V_195 ) {
if ( F_62 ( V_120 -> V_133 , & V_194 , V_118 ) ==
V_116 )
F_59 ( V_120 -> V_133 , L_60 ,
L_61 ) ;
F_2 ( V_118 -> F_67 !=
F_40 ( F_72 ( V_118 ) ) - 1 ,
L_62 ) ;
F_66 ( V_118 ) -- ;
V_132 =
F_105 ( V_130 , V_118 , & V_194 , V_120 ,
NULL ) ;
F_2 ( V_132 <= 0
|| V_132 > V_195 ,
L_63 ,
V_195 , V_132 ) ;
V_195 -= V_132 ;
F_136 ( & V_194 ,
F_10 ( & V_194 ) - V_132 ) ;
}
F_35 ( V_120 -> V_133 , L_64 , L_65
L_66
L_67 ) ;
F_137 ( V_120 ) ;
}
int F_138 ( struct V_129 * V_130 ,
struct V_38 * V_118 ,
struct V_11 * V_131 ,
struct V_120 * V_120 ,
struct V_181 * V_181 , T_3 V_187 )
{
struct V_40 * V_41 = V_120 -> V_133 ;
struct V_143 V_197 ;
struct V_5 * V_105 ;
int V_122 = 0 ;
int V_159 = V_163 ;
int V_132 = 0 ;
int V_198 = 0 ;
char V_145 ;
int V_199 = - 1 ;
int V_158 ;
T_3 V_200 = 0 ;
int V_74 ;
F_82 ( ! V_130 -> V_134 ) ;
F_97 ( V_130 , & V_197 , V_120 -> V_133 , V_118 ,
V_122 ) ;
while ( 1 ) {
V_145 =
F_81 ( V_130 , V_120 , V_118 ,
V_131 , & V_132 ,
& V_122 , V_187 ) ;
if ( V_145 == V_142 ) {
F_2 ( V_159 != V_163 ,
L_68 ) ;
V_159 =
F_129 ( V_130 , V_120 , V_181 ,
V_118 , V_131 ,
V_187 , & V_145 ) ;
if ( V_145 == V_193 )
return V_159 ;
V_198 = 1 ;
V_199 = V_159 ;
F_139 ( V_131 , V_201 ) ;
V_131 -> V_17 = 4 ;
V_187 -=
( V_187 & ( V_41 -> V_112 - 1 ) ) ;
V_200 = V_187 ;
F_136 ( V_131 , V_187 + 1 ) ;
if ( F_62
( V_41 , V_131 ,
V_118 ) == V_116 ) {
F_140 ( F_27 ( V_118 ) , 3 ,
F_66 ( V_118 ) - 1 ,
F_66 ( V_118 ) + 1 ) ;
F_59 ( V_41 , L_69 , L_70
L_71 ,
V_131 ) ;
}
continue;
}
if ( V_122 == 0 ) {
F_32 ( V_118 ) ;
return 0 ;
}
V_197 . V_148 [ 0 ] = V_122 ;
V_159 = F_106 ( V_145 , & V_197 , NULL , NULL ) ;
if ( V_159 != V_161 )
break;
F_50 ( V_41 , V_202 ) ;
V_159 =
F_62 ( V_41 , V_131 , V_118 ) ;
if ( V_159 == V_111 )
continue;
F_35 ( V_41 , L_72 , L_73 ,
V_131 ) ;
F_107 ( & V_197 ) ;
return ( V_159 == V_94 ) ? - V_203 : - V_204 ;
}
if ( V_159 != V_163 ) {
if ( V_198 ) {
F_134 ( V_130 , V_120 , V_118 ) ;
}
if ( V_159 == V_205 )
F_35 ( V_41 , L_74 ,
L_75 ) ;
F_107 ( & V_197 ) ;
return - V_203 ;
}
F_2 ( V_145 == V_206 || V_145 == V_207 , L_76 ) ;
V_158 =
( V_145 ==
V_124 ) ? F_40 ( F_72 ( V_118 ) ) : - V_197 .
V_148 [ 0 ] ;
if ( V_199 == - 1 )
V_159 = F_96 ( & V_197 , V_145 ) ;
else
V_159 = V_199 ;
V_105 = F_72 ( V_197 . V_147 ) ;
if ( ! F_108 ( V_120 -> V_164 ) && F_85 ( V_105 ) ) {
if ( V_145 == V_124 &&
( F_68 ( V_105 ) & ( V_41 -> V_112 - 1 ) ) ==
1 ) {
F_132 ( V_120 ) -> V_208 = V_209 ;
V_158 = V_41 -> V_112 + V_115 ;
} else {
V_158 = 0 ;
}
}
#ifdef F_49
if ( V_198 ) {
struct V_5 * V_119 =
F_72 ( V_197 . V_147 ) ;
if ( ! F_70 ( V_119 ) )
F_59 ( V_41 , L_77 ,
L_78 , V_119 ) ;
if ( V_145 == V_124 && F_40 ( V_119 ) != V_115 )
F_59 ( V_41 , L_79 , L_80
L_81
L_82
L_83 , V_119 ) ;
if ( V_145 == V_126
&& V_197 . V_148 [ 0 ] != - V_115 ) {
F_59 ( V_41 , L_84 , L_85
L_86
L_87 ,
V_119 , V_197 . V_148 [ 0 ] ) ;
}
}
#endif
F_111 ( & V_197 , NULL , NULL , V_145 ) ;
if ( V_198 ) {
F_125 ( V_181 , V_200 ) ;
F_132 ( V_120 ) -> V_191 &= ~ V_210 ;
}
#ifdef F_112
F_113 ( V_120 -> V_133 , V_169 ,
L_88 ,
V_158 , V_120 -> V_170 , '?' ) ;
#endif
V_74 = F_46 ( V_41 ) ;
F_114 ( V_120 , V_158 ) ;
F_54 ( V_41 , V_74 ) ;
return V_159 ;
}
static void F_141 ( struct V_129 * V_130 ,
struct V_120 * V_120 )
{
F_82 ( ! V_130 -> V_134 ) ;
if ( V_120 -> V_211 )
F_60 ( V_120 -> V_133 , L_89 , L_90 ) ;
F_142 ( V_212 , F_124 ( V_120 ) , V_127 ) ;
F_143 ( V_212 , F_124 ( V_120 ) , V_213 ) ;
F_115 ( V_130 , V_120 , F_124 ( V_120 ) ) ;
F_144 ( V_130 , V_120 ) ;
F_142 ( V_212 , F_124 ( V_120 ) , V_214 ) ;
F_143 ( V_212 , F_124 ( V_120 ) , V_215 ) ;
}
int F_120 ( struct V_129 * V_130 ,
struct V_120 * V_120 ,
struct V_181 * V_181 ,
int V_216
)
{
F_116 ( V_217 ) ;
struct V_5 * V_105 ;
struct V_11 V_218 ;
T_3 V_219 ,
V_187 ;
int V_220 ;
int V_16 ;
int V_175 = 0 ;
F_82 ( ! V_130 -> V_134 ) ;
if ( !
( F_145 ( V_120 -> V_164 ) || F_146 ( V_120 -> V_164 )
|| F_108 ( V_120 -> V_164 ) ) )
return 0 ;
if ( F_146 ( V_120 -> V_164 ) ) {
F_141 ( V_130 , V_120 ) ;
return 0 ;
}
V_187 = V_120 -> V_176 ;
F_135 ( & V_218 , V_120 , F_74 ( V_120 ) ,
V_196 , 3 ) ;
V_16 =
F_62 ( V_120 -> V_133 , & V_218 ,
& V_217 ) ;
if ( V_16 == V_94 ) {
F_60 ( V_120 -> V_133 , L_91 ,
L_92 ,
& V_218 ) ;
V_175 = - V_203 ;
goto V_221;
}
if ( V_16 == V_111 || V_16 == V_114 ) {
F_60 ( V_120 -> V_133 , L_93 ,
L_94 , V_16 ,
& V_218 ) ;
V_175 = - V_203 ;
goto V_221;
}
V_217 . F_67 -- ;
V_105 = F_72 ( & V_217 ) ;
if ( F_83 ( V_105 ) )
V_219 = 0 ;
else {
T_3 V_108 = F_68 ( V_105 ) ;
int V_222 =
F_69 ( V_105 , V_120 -> V_133 -> V_112 ) ;
V_219 = V_108 + V_222 - 1 ;
}
if ( V_187 == 0 )
V_217 . V_100 = V_101 | V_103 ;
if ( V_219 == 0 || V_219 < V_187 ) {
goto V_223;
}
F_136 ( & V_218 , V_219 ) ;
do {
V_220 =
F_138 ( V_130 , & V_217 , & V_218 ,
V_120 , V_181 , V_187 ) ;
if ( V_220 < 0 ) {
F_35 ( V_120 -> V_133 , L_95 ,
L_96 ) ;
F_28 ( & V_217 ) ;
return 0 ;
}
F_2 ( V_220 > V_219 ,
L_97 ,
V_220 , V_219 , & V_218 ) ;
V_219 -= V_220 ;
F_136 ( & V_218 , V_219 ) ;
if ( F_147 ( V_130 , 0 ) ||
F_87 ( V_130 ) <= V_141 ) {
F_32 ( & V_217 ) ;
if ( V_216 ) {
V_120 -> V_224 = F_148 ( V_120 ) ;
V_120 -> V_225 = F_148 ( V_120 ) ;
}
F_144 ( V_130 , V_120 ) ;
V_175 = F_149 ( V_130 ) ;
if ( V_175 )
goto V_221;
V_175 = F_150 ( V_130 , V_120 -> V_133 ,
V_141 + V_226 * 4 ) ;
if ( V_175 )
goto V_221;
F_151 ( V_120 ) ;
}
} while ( V_219 > F_76 ( V_187 ) &&
F_62 ( V_120 -> V_133 , & V_218 ,
& V_217 ) == V_111 );
F_2 ( V_219 > F_76 ( V_187 ) ,
L_98 ,
V_187 , V_219 , V_218 . V_14 . V_15 ) ;
V_223:
if ( V_216 ) {
V_120 -> V_224 = F_148 ( V_120 ) ;
V_120 -> V_225 = F_148 ( V_120 ) ;
}
F_144 ( V_130 , V_120 ) ;
V_221:
F_32 ( & V_217 ) ;
return V_175 ;
}
static void F_152 ( struct V_38 * V_118 ,
const struct V_11 * V_28 )
{
struct V_5 * V_227 = F_72 ( V_118 ) ;
if ( F_85 ( V_227 ) ) {
if ( F_68 ( V_227 ) +
F_69 ( V_227 ,
F_80 ( V_118 ) -> V_71 ) !=
F_10 ( V_28 )
|| F_69 ( V_227 ,
F_80 ( V_118 ) -> V_71 ) !=
F_67 ( V_118 ) )
F_59 ( NULL , L_99 , L_100
L_101
L_102 , V_227 ,
F_67 ( V_118 ) , V_28 ) ;
}
if ( F_70 ( V_227 ) ) {
if ( F_68 ( V_227 ) +
F_69 ( V_227 ,
F_80 ( V_118 ) -> V_71 ) !=
F_10 ( V_28 )
|| F_86 ( V_227 ) != F_67 ( V_118 )
|| F_153 ( V_227 ) != 0 )
F_59 ( NULL , L_103 , L_104
L_105
L_106 ,
V_227 , F_67 ( V_118 ) , V_28 ) ;
}
}
int F_154 ( struct V_129 * V_130 ,
struct V_38 * V_53 ,
const struct V_11 * V_28 ,
struct V_120 * V_120 ,
const char * V_228 ,
int V_229 )
{
struct V_40 * V_41 = V_120 -> V_133 ;
struct V_143 V_230 ;
int V_16 ;
int V_84 ;
int V_74 ;
F_82 ( ! V_130 -> V_134 ) ;
V_84 = F_52 ( V_120 -> V_133 ) ;
#ifdef F_112
F_113 ( V_120 -> V_133 , V_169 ,
L_107 ,
V_229 , V_120 -> V_170 ,
F_99 ( & V_28 -> V_14 ) ) ;
#endif
V_74 = F_46 ( V_41 ) ;
V_16 = F_155 ( V_120 , V_229 ) ;
F_54 ( V_41 , V_74 ) ;
if ( V_16 ) {
F_32 ( V_53 ) ;
return V_16 ;
}
F_97 ( V_130 , & V_230 , V_130 -> V_171 , V_53 ,
V_229 ) ;
#ifdef F_156
V_230 . V_28 = V_28 -> V_14 ;
#endif
if ( F_56 ( V_84 , V_120 -> V_133 ) ) {
goto V_231;
}
while ( ( V_16 =
F_106 ( V_206 , & V_230 , NULL ,
V_228 ) ) == V_161 ) {
V_231:
F_50 ( V_130 -> V_171 , V_232 ) ;
V_16 =
F_62 ( V_130 -> V_171 , V_28 ,
V_53 ) ;
if ( V_16 == V_94 ) {
V_16 = - V_203 ;
goto V_233;
}
if ( V_16 == V_111 ) {
F_35 ( V_120 -> V_133 , L_108 ,
L_109 ,
V_28 ) ;
V_16 = - V_234 ;
goto V_233;
}
#ifdef F_49
F_152 ( V_53 , V_28 ) ;
#endif
}
if ( V_16 == V_163 ) {
F_111 ( & V_230 , NULL , V_228 , V_206 ) ;
return 0 ;
}
V_16 = ( V_16 == V_205 ) ? - V_235 : - V_203 ;
V_233:
F_107 ( & V_230 ) ;
#ifdef F_112
F_113 ( V_120 -> V_133 , V_169 ,
L_110 ,
V_229 , V_120 -> V_170 ,
F_99 ( & V_28 -> V_14 ) ) ;
#endif
V_74 = F_46 ( V_41 ) ;
F_114 ( V_120 , V_229 ) ;
F_54 ( V_41 , V_74 ) ;
return V_16 ;
}
int F_157 ( struct V_129 * V_130 ,
struct V_38 * V_118 , const struct V_11 * V_28 ,
struct V_5 * V_58 , struct V_120 * V_120 ,
const char * V_228 )
{
struct V_143 V_236 ;
int V_16 ;
int V_84 = 0 ;
int V_237 = 0 ;
F_82 ( ! V_130 -> V_134 ) ;
if ( V_120 ) {
int V_74 ;
V_84 = F_52 ( V_120 -> V_133 ) ;
V_237 = F_40 ( V_58 ) ;
if ( ! F_108 ( V_120 -> V_164 ) && F_85 ( V_58 ) )
V_237 = V_120 -> V_133 -> V_112 + V_115 ;
#ifdef F_112
F_113 ( V_120 -> V_133 , V_169 ,
L_111 ,
V_237 , V_120 -> V_170 , F_104 ( V_58 ) ) ;
#endif
V_74 = F_46 ( V_120 -> V_133 ) ;
V_16 = F_155 ( V_120 , V_237 ) ;
F_54 ( V_120 -> V_133 , V_74 ) ;
if ( V_16 ) {
F_32 ( V_118 ) ;
return V_16 ;
}
}
F_97 ( V_130 , & V_236 , V_130 -> V_171 , V_118 ,
V_8 + F_40 ( V_58 ) ) ;
#ifdef F_156
V_236 . V_28 = V_28 -> V_14 ;
#endif
if ( V_120 && F_56 ( V_84 , V_120 -> V_133 ) ) {
goto V_231;
}
while ( ( V_16 =
F_106 ( V_207 , & V_236 , V_58 ,
V_228 ) ) == V_161 ) {
V_231:
F_50 ( V_130 -> V_171 , V_238 ) ;
V_16 = F_65 ( V_130 -> V_171 , V_28 , V_118 ) ;
if ( V_16 == V_94 ) {
V_16 = - V_203 ;
goto V_233;
}
if ( V_16 == V_36 ) {
F_35 ( V_130 -> V_171 , L_112 ,
L_113 ,
V_28 ) ;
V_16 = - V_234 ;
goto V_233;
}
}
if ( V_16 == V_163 ) {
F_111 ( & V_236 , V_58 , V_228 , V_207 ) ;
return 0 ;
}
V_16 = ( V_16 == V_205 ) ? - V_235 : - V_203 ;
V_233:
F_107 ( & V_236 ) ;
#ifdef F_112
F_113 ( V_130 -> V_171 , V_169 ,
L_114 ,
V_237 , V_120 -> V_170 , F_104 ( V_58 ) ) ;
#endif
if ( V_120 ) {
int V_74 = F_46 ( V_120 -> V_133 ) ;
F_114 ( V_120 , V_237 ) ;
F_54 ( V_120 -> V_133 , V_74 ) ;
}
return V_16 ;
}
