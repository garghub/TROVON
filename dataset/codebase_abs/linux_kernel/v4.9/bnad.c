static void
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = & ( (struct V_4 * ) V_3 -> V_8 ) [ V_6 ] ;
V_5 -> V_9 = 0 ;
}
}
static T_1
F_2 ( struct V_1 * V_1 ,
struct V_10 * V_11 ,
T_1 V_7 , T_1 V_12 )
{
struct V_10 * V_13 ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_13 = & V_11 [ V_12 ] ;
V_17 = V_13 -> V_17 ;
V_15 = V_13 -> V_15 ;
V_13 -> V_15 = NULL ;
V_13 -> V_17 = 0 ;
F_3 ( & V_1 -> V_18 -> V_19 ,
F_4 ( & V_13 -> V_20 [ 0 ] , V_21 ) ,
F_5 ( V_15 ) , V_22 ) ;
F_6 ( & V_13 -> V_20 [ 0 ] , V_21 , 0 ) ;
V_17 -- ;
V_16 = 0 ;
while ( V_17 ) {
V_16 ++ ;
if ( V_16 == V_23 ) {
V_16 = 0 ;
F_7 ( V_12 , V_7 ) ;
V_13 = & V_11 [ V_12 ] ;
}
F_8 ( & V_1 -> V_18 -> V_19 ,
F_4 ( & V_13 -> V_20 [ V_16 ] , V_21 ) ,
F_9 ( & V_13 -> V_20 [ V_16 ] , V_24 ) ,
V_22 ) ;
F_6 ( & V_13 -> V_20 [ V_16 ] , V_21 , 0 ) ;
V_17 -- ;
}
F_7 ( V_12 , V_7 ) ;
return V_12 ;
}
static void
F_10 ( struct V_1 * V_1 , struct V_25 * V_26 )
{
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_14 * V_15 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_26 -> V_7 ; V_6 ++ ) {
V_15 = V_11 [ V_6 ] . V_15 ;
if ( ! V_15 )
continue;
F_2 ( V_1 , V_11 , V_26 -> V_7 , V_6 ) ;
F_11 ( V_15 ) ;
}
}
static T_1
F_12 ( struct V_1 * V_1 , struct V_25 * V_26 )
{
T_1 V_27 = 0 , V_28 = 0 ;
T_1 V_29 , V_30 , V_31 , V_32 , V_7 ;
struct V_10 * V_11 = V_26 -> V_11 ;
struct V_10 * V_13 ;
struct V_14 * V_15 ;
if ( ! F_13 ( V_33 , & V_26 -> V_34 ) )
return 0 ;
V_31 = * ( V_26 -> V_35 ) ;
F_14 () ;
V_32 = V_26 -> V_36 ;
V_7 = V_26 -> V_7 ;
V_29 = F_15 ( V_32 , V_31 , V_7 ) ;
F_16 ( ! ( V_29 <= F_17 ( V_26 , V_26 -> V_7 ) ) ) ;
while ( V_29 ) {
V_13 = & V_11 [ V_32 ] ;
V_15 = V_13 -> V_15 ;
V_27 ++ ;
V_28 += V_15 -> V_37 ;
V_30 = F_18 ( V_13 -> V_17 ) ;
V_29 -= V_30 ;
V_32 = F_2 ( V_1 , V_11 , V_7 , V_32 ) ;
F_11 ( V_15 ) ;
}
V_26 -> V_36 = V_31 ;
V_26 -> V_38 -> V_39 += V_27 ;
V_26 -> V_38 -> V_40 += V_28 ;
return V_27 ;
}
static T_1
F_19 ( struct V_1 * V_1 , struct V_25 * V_26 )
{
struct V_41 * V_42 = V_1 -> V_42 ;
T_1 V_43 = 0 ;
if ( F_20 ( V_44 , & V_26 -> V_34 ) )
return 0 ;
V_43 = F_12 ( V_1 , V_26 ) ;
if ( V_43 ) {
if ( F_21 ( V_42 ) &&
F_22 ( V_42 ) &&
F_23 ( V_26 , V_26 -> V_7 ) >=
V_45 ) {
if ( F_13 ( V_33 , & V_26 -> V_34 ) ) {
F_24 ( V_42 ) ;
F_25 ( V_1 , V_46 ) ;
}
}
}
if ( F_26 ( F_13 ( V_33 , & V_26 -> V_34 ) ) )
F_27 ( V_26 -> V_47 , V_43 ) ;
F_28 () ;
F_29 ( V_44 , & V_26 -> V_34 ) ;
return V_43 ;
}
static T_2
F_30 ( int V_48 , void * V_49 )
{
struct V_25 * V_26 = (struct V_25 * ) V_49 ;
struct V_1 * V_1 = V_26 -> V_1 ;
F_19 ( V_1 , V_26 ) ;
return V_50 ;
}
static inline void
F_31 ( struct V_1 * V_1 , struct V_51 * V_52 )
{
struct V_53 * V_11 = V_52 -> V_11 ;
V_11 -> V_54 = - 1 ;
V_11 -> V_55 = - 1 ;
V_11 -> V_56 = 0 ;
V_11 -> type = V_57 ;
}
static int
F_32 ( struct V_1 * V_1 , struct V_51 * V_52 )
{
struct V_53 * V_11 = V_52 -> V_11 ;
int V_58 ;
F_31 ( V_1 , V_52 ) ;
V_58 = F_33 ( V_52 -> V_59 -> V_60 ) ;
V_11 -> type = V_61 ;
if ( F_34 ( V_52 -> V_62 ) ) {
V_11 -> V_55 = 0 ;
V_11 -> V_56 = V_52 -> V_59 -> V_60 ;
} else {
if ( V_52 -> V_59 -> V_63 ) {
V_11 -> V_55 = 0 ;
V_11 -> V_56 = V_52 -> V_59 -> V_60 ;
V_11 -> type = V_64 ;
} else {
V_11 -> V_55 = V_58 ;
V_11 -> V_56 =
( V_52 -> V_59 -> V_60 > 2048 ) ?
V_65 << V_58 : 2048 ;
}
}
F_16 ( ( V_65 << V_58 ) % V_11 -> V_56 ) ;
return 0 ;
}
static inline void
F_35 ( struct V_1 * V_1 , struct V_66 * V_13 )
{
if ( ! V_13 -> V_67 )
return;
F_8 ( & V_1 -> V_18 -> V_19 ,
F_4 ( & V_13 -> V_16 , V_21 ) ,
V_13 -> V_16 . V_37 , V_68 ) ;
F_36 ( V_13 -> V_67 ) ;
V_13 -> V_67 = NULL ;
F_6 ( & V_13 -> V_16 , V_21 , 0 ) ;
V_13 -> V_16 . V_37 = 0 ;
}
static inline void
F_37 ( struct V_1 * V_1 , struct V_66 * V_13 )
{
if ( ! V_13 -> V_15 )
return;
F_3 ( & V_1 -> V_18 -> V_19 ,
F_4 ( & V_13 -> V_16 , V_21 ) ,
V_13 -> V_16 . V_37 , V_68 ) ;
F_11 ( V_13 -> V_15 ) ;
V_13 -> V_15 = NULL ;
F_6 ( & V_13 -> V_16 , V_21 , 0 ) ;
V_13 -> V_16 . V_37 = 0 ;
}
static void
F_38 ( struct V_1 * V_1 , struct V_51 * V_52 )
{
struct V_53 * V_11 = V_52 -> V_11 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_52 -> V_7 ; V_6 ++ ) {
struct V_66 * V_13 = & V_11 -> V_13 [ V_6 ] ;
if ( F_39 ( V_11 -> type ) )
F_37 ( V_1 , V_13 ) ;
else
F_35 ( V_1 , V_13 ) ;
}
F_31 ( V_1 , V_52 ) ;
}
static T_1
F_40 ( struct V_1 * V_1 , struct V_51 * V_52 , T_1 V_69 )
{
T_1 V_70 , V_71 , V_7 ;
struct V_53 * V_11 = V_52 -> V_11 ;
struct V_66 * V_13 , * V_72 ;
struct V_73 * V_74 ;
struct V_67 * V_67 ;
T_1 V_75 , V_76 ;
T_3 V_21 ;
V_71 = V_52 -> V_77 ;
V_7 = V_52 -> V_7 ;
V_76 = V_65 << V_11 -> V_55 ;
V_70 = 0 ;
while ( V_69 -- ) {
V_13 = & V_11 -> V_13 [ V_71 ] ;
if ( V_11 -> V_54 < 0 ) {
V_67 = F_41 ( V_78 | V_79 ,
V_11 -> V_55 ) ;
V_75 = 0 ;
} else {
V_72 = & V_11 -> V_13 [ V_11 -> V_54 ] ;
V_67 = V_72 -> V_67 ;
V_75 = V_72 -> V_75 + V_11 -> V_56 ;
F_42 ( V_67 ) ;
}
if ( F_43 ( ! V_67 ) ) {
F_25 ( V_1 , V_80 ) ;
V_52 -> V_59 -> V_80 ++ ;
goto V_81;
}
V_21 = F_44 ( & V_1 -> V_18 -> V_19 , V_67 , V_75 ,
V_11 -> V_56 , V_68 ) ;
if ( F_45 ( & V_1 -> V_18 -> V_19 , V_21 ) ) {
F_36 ( V_67 ) ;
F_25 ( V_1 , V_82 ) ;
V_52 -> V_59 -> V_82 ++ ;
goto V_81;
}
V_13 -> V_67 = V_67 ;
V_13 -> V_75 = V_75 ;
F_6 ( & V_13 -> V_16 , V_21 , V_21 ) ;
V_13 -> V_16 . V_37 = V_11 -> V_56 ;
V_75 += V_11 -> V_56 ;
if ( V_75 < V_76 )
V_11 -> V_54 = V_71 ;
else
V_11 -> V_54 = - 1 ;
V_74 = & ( (struct V_73 * ) V_52 -> V_8 ) [ V_71 ] ;
F_46 ( V_21 , & V_74 -> V_83 ) ;
F_7 ( V_71 , V_7 ) ;
V_70 ++ ;
}
V_81:
if ( F_26 ( V_70 ) ) {
V_52 -> V_77 = V_71 ;
F_47 () ;
if ( F_26 ( F_13 ( V_84 , & V_52 -> V_34 ) ) )
F_48 ( V_52 ) ;
}
return V_70 ;
}
static T_1
F_49 ( struct V_1 * V_1 , struct V_51 * V_52 , T_1 V_69 )
{
T_1 V_70 , V_71 , V_7 , V_85 ;
struct V_53 * V_11 = V_52 -> V_11 ;
struct V_66 * V_13 ;
struct V_73 * V_74 ;
struct V_14 * V_15 ;
T_3 V_21 ;
V_85 = V_52 -> V_59 -> V_60 ;
V_71 = V_52 -> V_77 ;
V_7 = V_52 -> V_7 ;
V_70 = 0 ;
while ( V_69 -- ) {
V_13 = & V_11 -> V_13 [ V_71 ] ;
V_15 = F_50 ( V_1 -> V_42 , V_85 ) ;
if ( F_43 ( ! V_15 ) ) {
F_25 ( V_1 , V_80 ) ;
V_52 -> V_59 -> V_80 ++ ;
goto V_81;
}
V_21 = F_51 ( & V_1 -> V_18 -> V_19 , V_15 -> V_49 ,
V_85 , V_68 ) ;
if ( F_45 ( & V_1 -> V_18 -> V_19 , V_21 ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_82 ) ;
V_52 -> V_59 -> V_82 ++ ;
goto V_81;
}
V_13 -> V_15 = V_15 ;
F_6 ( & V_13 -> V_16 , V_21 , V_21 ) ;
V_13 -> V_16 . V_37 = V_85 ;
V_74 = & ( (struct V_73 * ) V_52 -> V_8 ) [ V_71 ] ;
F_46 ( V_21 , & V_74 -> V_83 ) ;
F_7 ( V_71 , V_7 ) ;
V_70 ++ ;
}
V_81:
if ( F_26 ( V_70 ) ) {
V_52 -> V_77 = V_71 ;
F_47 () ;
if ( F_26 ( F_13 ( V_84 , & V_52 -> V_34 ) ) )
F_48 ( V_52 ) ;
}
return V_70 ;
}
static inline void
F_52 ( struct V_1 * V_1 , struct V_51 * V_52 )
{
struct V_53 * V_11 = V_52 -> V_11 ;
T_1 V_86 ;
V_86 = F_23 ( V_52 , V_52 -> V_7 ) ;
if ( ! ( V_86 >> V_87 ) )
return;
if ( F_39 ( V_11 -> type ) )
F_49 ( V_1 , V_52 , V_86 ) ;
else
F_40 ( V_1 , V_52 , V_86 ) ;
}
static void
F_53 ( struct V_1 * V_1 , struct V_51 * V_52 ,
T_1 V_88 , T_1 V_17 )
{
struct V_53 * V_11 ;
struct V_66 * V_13 ;
T_1 V_89 , V_90 ;
V_11 = V_52 -> V_11 ;
for ( V_90 = 0 , V_89 = V_88 ; V_90 < V_17 ; V_90 ++ ) {
V_13 = & V_11 -> V_13 [ V_89 ] ;
F_7 ( V_89 , V_52 -> V_7 ) ;
if ( F_39 ( V_11 -> type ) )
F_37 ( V_1 , V_13 ) ;
else
F_35 ( V_1 , V_13 ) ;
}
}
static void
F_54 ( struct V_2 * V_3 , struct V_14 * V_15 , T_1 V_17 )
{
struct V_51 * V_52 ;
struct V_1 * V_1 ;
struct V_53 * V_11 ;
struct V_4 * V_91 , * V_5 ;
T_1 V_89 , V_92 , V_93 = 0 ;
V_91 = V_3 -> V_8 ;
V_92 = V_3 -> V_77 ;
V_5 = & V_91 [ V_92 ] ;
V_52 = F_34 ( V_5 -> V_94 ) ? V_3 -> V_52 [ 1 ] : V_3 -> V_52 [ 0 ] ;
V_11 = V_52 -> V_11 ;
V_1 = V_52 -> V_1 ;
V_89 = V_52 -> V_36 ;
F_55 ( F_56 ( V_11 -> V_13 [ V_89 ] . V_67 ) +
V_11 -> V_13 [ V_89 ] . V_75 ) ;
while ( V_17 -- ) {
struct V_66 * V_13 ;
T_1 V_37 ;
V_13 = & V_11 -> V_13 [ V_89 ] ;
F_7 ( V_89 , V_52 -> V_7 ) ;
F_8 ( & V_1 -> V_18 -> V_19 ,
F_4 ( & V_13 -> V_16 , V_21 ) ,
V_13 -> V_16 . V_37 , V_68 ) ;
V_37 = F_57 ( V_5 -> V_95 ) ;
V_15 -> V_96 += V_13 -> V_16 . V_37 ;
V_93 += V_37 ;
F_58 ( V_15 , F_59 ( V_15 ) -> V_97 ,
V_13 -> V_67 , V_13 -> V_75 , V_37 ) ;
V_13 -> V_67 = NULL ;
V_13 -> V_16 . V_37 = 0 ;
F_7 ( V_92 , V_3 -> V_7 ) ;
V_5 = & V_91 [ V_92 ] ;
}
V_15 -> V_37 += V_93 ;
V_15 -> V_98 += V_93 ;
}
static inline void
F_60 ( struct V_1 * V_1 , struct V_14 * V_15 ,
struct V_66 * V_13 , T_1 V_37 )
{
F_55 ( V_15 -> V_49 ) ;
F_3 ( & V_1 -> V_18 -> V_19 ,
F_4 ( & V_13 -> V_16 , V_21 ) ,
V_13 -> V_16 . V_37 , V_68 ) ;
F_61 ( V_15 , V_37 ) ;
V_15 -> V_99 = F_62 ( V_15 , V_1 -> V_42 ) ;
V_13 -> V_15 = NULL ;
V_13 -> V_16 . V_37 = 0 ;
}
static T_1
F_63 ( struct V_1 * V_1 , struct V_2 * V_3 , int V_100 )
{
struct V_4 * V_91 , * V_5 , * V_101 ;
struct V_51 * V_52 = NULL ;
struct V_53 * V_11 ;
struct V_66 * V_13 = NULL ;
struct V_14 * V_15 = NULL ;
struct V_102 * V_103 = & V_3 -> V_104 ;
struct V_105 * V_106 = V_3 -> V_107 ;
T_1 V_108 = 0 , V_37 = 0 , V_93 = 0 ;
T_1 V_92 , V_90 , V_88 = 0 , V_17 = 0 ;
T_1 V_34 , V_109 ;
F_55 ( V_1 -> V_42 ) ;
V_91 = V_3 -> V_8 ;
while ( V_108 < V_100 ) {
V_5 = & V_91 [ V_3 -> V_77 ] ;
if ( ! V_5 -> V_9 )
break;
F_14 () ;
F_64 ( V_103 , F_57 ( V_5 -> V_95 ) ) ;
if ( F_34 ( V_5 -> V_94 ) )
V_52 = V_3 -> V_52 [ 1 ] ;
else
V_52 = V_3 -> V_52 [ 0 ] ;
V_11 = V_52 -> V_11 ;
V_88 = V_52 -> V_36 ;
if ( F_39 ( V_11 -> type ) ) {
V_13 = & V_11 -> V_13 [ V_88 ] ;
V_15 = V_13 -> V_15 ;
} else {
V_15 = F_65 ( & V_106 -> V_110 ) ;
if ( F_43 ( ! V_15 ) )
break;
}
F_55 ( V_15 ) ;
V_34 = F_66 ( V_5 -> V_34 ) ;
V_37 = F_57 ( V_5 -> V_95 ) ;
V_93 = V_37 ;
V_17 = 1 ;
if ( F_67 ( V_11 -> type ) &&
( V_34 & V_111 ) == 0 ) {
V_92 = V_3 -> V_77 ;
do {
F_7 ( V_92 , V_3 -> V_7 ) ;
V_101 = & V_91 [ V_92 ] ;
if ( ! V_101 -> V_9 )
break;
F_14 () ;
V_37 = F_57 ( V_101 -> V_95 ) ;
V_34 = F_66 ( V_101 -> V_34 ) ;
V_17 ++ ;
V_93 += V_37 ;
} while ( ( V_34 & V_111 ) == 0 );
if ( ! V_101 -> V_9 )
break;
}
V_108 ++ ;
if ( F_43 ( V_34 & ( V_112 |
V_113 |
V_114 ) ) ) {
F_53 ( V_1 , V_52 , V_88 , V_17 ) ;
V_52 -> V_59 -> V_115 ++ ;
goto V_116;
}
if ( F_39 ( V_11 -> type ) )
F_60 ( V_1 , V_15 , V_13 , V_37 ) ;
else
F_54 ( V_3 , V_15 , V_17 ) ;
V_52 -> V_59 -> V_117 ++ ;
V_52 -> V_59 -> V_118 += V_93 ;
V_3 -> V_119 += V_93 ;
V_109 = V_34 & V_120 ;
if ( F_26
( ( V_1 -> V_42 -> V_121 & V_122 ) &&
( ( V_109 == V_123 ) ||
( V_109 == V_124 ) ||
( V_109 == V_125 ) ||
( V_109 == V_126 ) ) ) )
V_15 -> V_127 = V_128 ;
else
F_68 ( V_15 ) ;
if ( ( V_34 & V_129 ) &&
( V_1 -> V_42 -> V_121 & V_130 ) )
F_69 ( V_15 , F_70 ( V_131 ) , F_57 ( V_5 -> V_132 ) ) ;
if ( F_39 ( V_11 -> type ) )
F_71 ( V_15 ) ;
else
F_72 ( & V_106 -> V_110 ) ;
V_116:
F_73 ( V_52 -> V_36 , V_17 , V_52 -> V_7 ) ;
for ( V_90 = 0 ; V_90 < V_17 ; V_90 ++ ) {
V_5 = & V_91 [ V_3 -> V_77 ] ;
V_5 -> V_9 = 0 ;
F_7 ( V_3 -> V_77 , V_3 -> V_7 ) ;
}
}
F_74 ( & V_106 -> V_110 , false ) ;
if ( F_26 ( F_13 ( V_133 , & V_3 -> V_52 [ 0 ] -> V_34 ) ) )
F_75 ( V_3 -> V_47 , V_108 ) ;
F_52 ( V_1 , V_3 -> V_52 [ 0 ] ) ;
if ( V_3 -> V_52 [ 1 ] )
F_52 ( V_1 , V_3 -> V_52 [ 1 ] ) ;
return V_108 ;
}
static void
F_76 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_105 * V_106 = (struct V_105 * ) ( V_3 -> V_107 ) ;
struct V_134 * V_110 = & V_106 -> V_110 ;
if ( F_26 ( F_77 ( V_110 ) ) ) {
F_78 ( V_110 ) ;
V_106 -> V_135 ++ ;
}
}
static T_2
F_79 ( int V_48 , void * V_49 )
{
struct V_2 * V_3 = (struct V_2 * ) V_49 ;
if ( V_3 ) {
( (struct V_105 * ) V_3 -> V_107 ) -> V_136 ++ ;
F_76 ( V_3 -> V_1 , V_3 ) ;
}
return V_50 ;
}
static T_2
F_80 ( int V_48 , void * V_49 )
{
T_1 V_137 ;
unsigned long V_34 ;
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( F_43 ( F_13 ( V_139 , & V_1 -> V_140 ) ) ) {
F_82 ( & V_1 -> V_138 , V_34 ) ;
return V_50 ;
}
F_83 ( & V_1 -> V_141 , V_137 ) ;
if ( F_84 ( & V_1 -> V_141 , V_137 ) )
F_85 ( & V_1 -> V_141 , V_137 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
return V_50 ;
}
static T_2
F_86 ( int V_48 , void * V_49 )
{
int V_6 , V_142 ;
T_1 V_137 ;
unsigned long V_34 ;
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
struct V_143 * V_144 ;
struct V_105 * V_106 ;
struct V_25 * V_26 = NULL ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( F_43 ( F_13 ( V_139 , & V_1 -> V_140 ) ) ) {
F_82 ( & V_1 -> V_138 , V_34 ) ;
return V_145 ;
}
F_83 ( & V_1 -> V_141 , V_137 ) ;
if ( F_43 ( ! V_137 ) ) {
F_82 ( & V_1 -> V_138 , V_34 ) ;
return V_145 ;
}
if ( F_84 ( & V_1 -> V_141 , V_137 ) )
F_85 ( & V_1 -> V_141 , V_137 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( ! F_87 ( V_137 ) )
return V_50 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_146 ; V_6 ++ ) {
for ( V_142 = 0 ; V_142 < V_1 -> V_147 ; V_142 ++ ) {
V_26 = V_1 -> V_148 [ V_6 ] . V_26 [ V_142 ] ;
if ( V_26 && F_13 ( V_33 , & V_26 -> V_34 ) )
F_19 ( V_1 , V_1 -> V_148 [ V_6 ] . V_26 [ V_142 ] ) ;
}
}
for ( V_6 = 0 ; V_6 < V_1 -> V_149 ; V_6 ++ ) {
V_144 = & V_1 -> V_144 [ V_6 ] ;
if ( ! V_144 -> V_150 )
continue;
for ( V_142 = 0 ; V_142 < V_1 -> V_151 ; V_142 ++ ) {
V_106 = & V_144 -> V_106 [ V_142 ] ;
if ( V_106 -> V_3 )
F_76 ( V_1 ,
V_106 -> V_3 ) ;
}
}
return V_50 ;
}
static void
F_88 ( struct V_1 * V_1 )
{
F_29 ( V_139 , & V_1 -> V_140 ) ;
F_25 ( V_1 , V_152 ) ;
}
static void
F_89 ( struct V_1 * V_1 )
{
F_90 ( V_139 , & V_1 -> V_140 ) ;
F_25 ( V_1 , V_153 ) ;
}
static void
F_91 ( struct V_1 * V_1 )
{
struct V_41 * V_42 = V_1 -> V_42 ;
F_92 ( V_42 -> V_154 , V_1 -> V_154 ) ;
if ( F_93 ( V_42 -> V_155 ) )
F_92 ( V_42 -> V_155 , V_1 -> V_154 ) ;
}
void
F_94 ( struct V_1 * V_1 )
{
F_88 ( V_1 ) ;
}
void
F_95 ( struct V_1 * V_1 )
{
F_89 ( V_1 ) ;
}
void
F_96 ( struct V_1 * V_1 )
{
V_1 -> V_156 . V_157 = V_158 ;
F_97 ( & V_1 -> V_156 . V_159 ) ;
}
void
F_98 ( struct V_1 * V_1 )
{
V_1 -> V_156 . V_157 = V_160 ;
F_97 ( & V_1 -> V_156 . V_159 ) ;
}
void
F_99 ( struct V_1 * V_1 )
{
V_1 -> V_156 . V_157 = V_158 ;
F_97 ( & V_1 -> V_156 . V_159 ) ;
}
static void
F_100 ( void * V_161 )
{
struct V_1 * V_1 = (struct V_1 * ) V_161 ;
F_101 ( V_1 -> V_42 ) ;
F_97 ( & V_1 -> V_156 . V_162 ) ;
}
void
F_102 ( struct V_1 * V_1 ,
enum V_163 V_164 )
{
bool V_165 = false ;
V_165 = ( V_164 == V_166 ) || ( V_164 == V_167 ) ;
if ( V_164 == V_167 ) {
if ( ! F_13 ( V_168 , & V_1 -> V_140 ) )
F_25 ( V_1 , V_169 ) ;
F_90 ( V_168 , & V_1 -> V_140 ) ;
} else {
if ( F_13 ( V_168 , & V_1 -> V_140 ) )
F_25 ( V_1 , V_169 ) ;
F_29 ( V_168 , & V_1 -> V_140 ) ;
}
if ( V_165 ) {
if ( ! F_22 ( V_1 -> V_42 ) ) {
T_4 V_170 , V_171 ;
F_103 ( V_1 -> V_42 , L_1 ) ;
F_104 ( V_1 -> V_42 ) ;
F_25 ( V_1 , V_172 ) ;
for ( V_170 = 0 ; V_170 < V_1 -> V_146 ; V_170 ++ ) {
for ( V_171 = 0 ; V_171 < V_1 -> V_147 ;
V_171 ++ ) {
struct V_25 * V_26 =
V_1 -> V_148 [ V_170 ] . V_26 [ V_171 ] ;
T_1 V_173 ;
if ( ! V_26 )
continue;
V_173 = V_26 -> V_62 ;
if ( F_13 ( V_33 ,
& V_26 -> V_34 ) ) {
F_105 (
V_1 -> V_42 ,
V_173 ) ;
F_25 ( V_1 ,
V_46 ) ;
} else {
F_106 (
V_1 -> V_42 ,
V_173 ) ;
F_25 ( V_1 ,
V_174 ) ;
}
}
}
}
} else {
if ( F_22 ( V_1 -> V_42 ) ) {
F_103 ( V_1 -> V_42 , L_2 ) ;
F_101 ( V_1 -> V_42 ) ;
F_25 ( V_1 , V_172 ) ;
}
}
}
static void
F_107 ( void * V_161 , struct V_175 * V_176 )
{
struct V_1 * V_1 = (struct V_1 * ) V_161 ;
F_97 ( & V_1 -> V_156 . V_177 ) ;
}
static void
F_108 ( struct V_1 * V_1 , struct V_25 * V_26 )
{
struct V_178 * V_148 =
(struct V_178 * ) V_26 -> V_38 -> V_176 -> V_179 ;
V_26 -> V_179 = V_26 ;
V_148 -> V_26 [ V_26 -> V_62 ] = V_26 ;
}
static void
F_109 ( struct V_1 * V_1 , struct V_25 * V_26 )
{
struct V_178 * V_148 =
(struct V_178 * ) V_26 -> V_38 -> V_176 -> V_179 ;
V_148 -> V_26 [ V_26 -> V_62 ] = NULL ;
V_26 -> V_179 = NULL ;
}
static void
F_110 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_143 * V_144 =
(struct V_143 * ) V_3 -> V_91 -> V_150 -> V_179 ;
V_144 -> V_106 [ V_3 -> V_62 ] . V_3 = V_3 ;
V_3 -> V_107 = & V_144 -> V_106 [ V_3 -> V_62 ] ;
}
static void
F_111 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_143 * V_144 =
(struct V_143 * ) V_3 -> V_91 -> V_150 -> V_179 ;
V_144 -> V_106 [ V_3 -> V_62 ] . V_3 = NULL ;
}
static void
F_112 ( struct V_1 * V_1 , struct V_175 * V_176 )
{
struct V_178 * V_148 =
(struct V_178 * ) V_176 -> V_179 ;
struct V_25 * V_26 ;
T_1 V_173 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_180 ; V_6 ++ ) {
V_26 = V_148 -> V_26 [ V_6 ] ;
if ( ! V_26 )
continue;
V_173 = V_26 -> V_62 ;
F_29 ( V_33 , & V_26 -> V_34 ) ;
F_106 ( V_1 -> V_42 , V_173 ) ;
}
}
static void
F_113 ( struct V_1 * V_1 , struct V_175 * V_176 )
{
struct V_178 * V_148 = (struct V_178 * ) V_176 -> V_179 ;
struct V_25 * V_26 ;
T_1 V_173 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_180 ; V_6 ++ ) {
V_26 = V_148 -> V_26 [ V_6 ] ;
if ( ! V_26 )
continue;
V_173 = V_26 -> V_62 ;
F_16 ( F_13 ( V_33 , & V_26 -> V_34 ) ) ;
F_90 ( V_33 , & V_26 -> V_34 ) ;
F_16 ( * ( V_26 -> V_35 ) != 0 ) ;
if ( F_22 ( V_1 -> V_42 ) ) {
F_105 ( V_1 -> V_42 , V_173 ) ;
F_25 ( V_1 , V_46 ) ;
}
}
if ( F_93 ( V_1 -> V_154 ) ) {
F_114 ( & V_1 -> V_141 . V_181 , V_1 -> V_154 ) ;
F_91 ( V_1 ) ;
}
}
static void
F_115 ( struct V_182 * V_183 )
{
struct V_178 * V_148 =
F_116 ( V_183 , struct V_178 , V_184 ) ;
struct V_1 * V_1 = NULL ;
struct V_25 * V_26 ;
unsigned long V_34 ;
T_1 V_6 , V_185 = 0 ;
for ( V_6 = 0 ; V_6 < V_180 ; V_6 ++ ) {
V_26 = V_148 -> V_26 [ V_6 ] ;
if ( ! V_26 )
continue;
V_1 = V_26 -> V_1 ;
if ( F_20 ( V_44 , & V_26 -> V_34 ) ) {
V_185 ++ ;
continue;
}
F_10 ( V_1 , V_26 ) ;
F_28 () ;
F_29 ( V_44 , & V_26 -> V_34 ) ;
}
if ( V_185 ) {
F_117 ( V_1 -> V_186 , & V_148 -> V_184 ,
F_118 ( 1 ) ) ;
return;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_119 ( V_148 -> V_176 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_120 ( struct V_1 * V_1 , struct V_175 * V_176 )
{
struct V_178 * V_148 = (struct V_178 * ) V_176 -> V_179 ;
struct V_25 * V_26 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_180 ; V_6 ++ ) {
V_26 = V_148 -> V_26 [ V_6 ] ;
if ( ! V_26 )
continue;
}
F_117 ( V_1 -> V_186 , & V_148 -> V_184 , 0 ) ;
}
static void
F_121 ( struct V_1 * V_1 , struct V_187 * V_150 )
{
struct V_143 * V_144 = (struct V_143 * ) V_150 -> V_179 ;
struct V_2 * V_3 ;
struct V_105 * V_106 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_188 ; V_6 ++ ) {
V_106 = & V_144 -> V_106 [ V_6 ] ;
V_3 = V_106 -> V_3 ;
if ( ! V_3 )
continue;
F_29 ( V_84 , & V_3 -> V_52 [ 0 ] -> V_34 ) ;
if ( V_3 -> V_52 [ 1 ] )
F_29 ( V_84 , & V_3 -> V_52 [ 1 ] -> V_34 ) ;
}
}
static void
F_122 ( void * V_183 )
{
struct V_143 * V_144 =
F_116 ( V_183 , struct V_143 , V_189 ) ;
struct V_105 * V_106 ;
struct V_1 * V_1 = NULL ;
unsigned long V_34 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_188 ; V_6 ++ ) {
V_106 = & V_144 -> V_106 [ V_6 ] ;
if ( ! V_106 -> V_3 )
continue;
V_1 = V_106 -> V_3 -> V_1 ;
F_123 ( & V_106 -> V_110 ) ;
F_1 ( V_1 , V_106 -> V_3 ) ;
F_38 ( V_1 , V_106 -> V_3 -> V_52 [ 0 ] ) ;
if ( V_106 -> V_3 -> V_52 [ 1 ] )
F_38 ( V_1 , V_106 -> V_3 -> V_52 [ 1 ] ) ;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_124 ( V_144 -> V_150 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_125 ( struct V_1 * V_1 , struct V_187 * V_150 )
{
struct V_143 * V_144 = (struct V_143 * ) V_150 -> V_179 ;
struct V_2 * V_3 ;
struct V_105 * V_106 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_188 ; V_6 ++ ) {
V_106 = & V_144 -> V_106 [ V_6 ] ;
V_3 = V_106 -> V_3 ;
if ( ! V_3 )
continue;
F_29 ( V_133 , & V_3 -> V_52 [ 0 ] -> V_34 ) ;
if ( V_3 -> V_52 [ 1 ] )
F_29 ( V_133 , & V_3 -> V_52 [ 1 ] -> V_34 ) ;
}
F_126 ( V_1 -> V_186 , & V_144 -> V_189 ) ;
}
static void
F_127 ( struct V_1 * V_1 , struct V_187 * V_150 )
{
struct V_143 * V_144 = (struct V_143 * ) V_150 -> V_179 ;
struct V_2 * V_3 ;
struct V_51 * V_52 ;
struct V_105 * V_106 ;
int V_6 , V_142 ;
for ( V_6 = 0 ; V_6 < V_188 ; V_6 ++ ) {
V_106 = & V_144 -> V_106 [ V_6 ] ;
V_3 = V_106 -> V_3 ;
if ( ! V_3 )
continue;
F_128 ( & V_106 -> V_110 ) ;
for ( V_142 = 0 ; V_142 < V_190 ; V_142 ++ ) {
V_52 = V_3 -> V_52 [ V_142 ] ;
if ( ! V_52 )
continue;
F_32 ( V_1 , V_52 ) ;
F_90 ( V_133 , & V_52 -> V_34 ) ;
F_90 ( V_84 , & V_52 -> V_34 ) ;
F_52 ( V_1 , V_52 ) ;
}
}
}
static void
F_129 ( void * V_161 , struct V_187 * V_150 )
{
struct V_1 * V_1 = (struct V_1 * ) V_161 ;
F_97 ( & V_1 -> V_156 . V_191 ) ;
}
static void
F_130 ( struct V_1 * V_1 , struct V_187 * V_150 )
{
V_1 -> V_156 . V_192 = V_158 ;
F_97 ( & V_1 -> V_156 . V_193 ) ;
}
void
F_131 ( struct V_1 * V_1 , enum V_194 V_195 ,
struct V_196 * V_197 )
{
if ( V_195 == V_158 )
F_25 ( V_1 , V_198 ) ;
if ( ! F_132 ( V_1 -> V_42 ) ||
! F_13 ( V_199 , & V_1 -> V_140 ) )
return;
F_133 ( & V_1 -> V_200 ,
V_201 + F_118 ( V_202 ) ) ;
}
static void
F_134 ( struct V_1 * V_1 )
{
V_1 -> V_156 . V_203 = V_158 ;
F_97 ( & V_1 -> V_156 . V_204 ) ;
}
void
F_135 ( void * V_161 , enum V_205 V_195 )
{
struct V_206 * V_207 =
(struct V_206 * ) V_161 ;
V_207 -> V_208 = ( T_1 ) V_195 ;
F_97 ( & V_207 -> V_209 ) ;
}
static void
F_136 ( struct V_1 * V_1 ,
struct V_210 * V_211 )
{
int V_6 ;
T_3 V_212 ;
if ( V_211 -> V_213 == NULL )
return;
for ( V_6 = 0 ; V_6 < V_211 -> V_214 ; V_6 ++ ) {
if ( V_211 -> V_213 [ V_6 ] . V_215 != NULL ) {
if ( V_211 -> V_216 == V_217 ) {
F_137 ( & ( V_211 -> V_213 [ V_6 ] . V_218 ) ,
V_212 ) ;
F_138 ( & V_1 -> V_18 -> V_19 ,
V_211 -> V_213 [ V_6 ] . V_37 ,
V_211 -> V_213 [ V_6 ] . V_215 , V_212 ) ;
} else
F_139 ( V_211 -> V_213 [ V_6 ] . V_215 ) ;
}
}
F_139 ( V_211 -> V_213 ) ;
V_211 -> V_213 = NULL ;
}
static int
F_140 ( struct V_1 * V_1 ,
struct V_210 * V_211 )
{
int V_6 ;
T_3 V_212 ;
if ( ( V_211 -> V_214 == 0 ) || ( V_211 -> V_37 == 0 ) ) {
V_211 -> V_213 = NULL ;
return 0 ;
}
V_211 -> V_213 = F_141 ( V_211 -> V_214 , sizeof( struct V_219 ) ,
V_220 ) ;
if ( V_211 -> V_213 == NULL )
return - V_221 ;
if ( V_211 -> V_216 == V_217 ) {
for ( V_6 = 0 ; V_6 < V_211 -> V_214 ; V_6 ++ ) {
V_211 -> V_213 [ V_6 ] . V_37 = V_211 -> V_37 ;
V_211 -> V_213 [ V_6 ] . V_215 =
F_142 ( & V_1 -> V_18 -> V_19 ,
V_211 -> V_37 , & V_212 ,
V_220 ) ;
if ( V_211 -> V_213 [ V_6 ] . V_215 == NULL )
goto V_222;
F_46 ( V_212 ,
& ( V_211 -> V_213 [ V_6 ] . V_218 ) ) ;
}
} else {
for ( V_6 = 0 ; V_6 < V_211 -> V_214 ; V_6 ++ ) {
V_211 -> V_213 [ V_6 ] . V_37 = V_211 -> V_37 ;
V_211 -> V_213 [ V_6 ] . V_215 = F_143 ( V_211 -> V_37 ,
V_220 ) ;
if ( V_211 -> V_213 [ V_6 ] . V_215 == NULL )
goto V_222;
}
}
return 0 ;
V_222:
F_136 ( V_1 , V_211 ) ;
return - V_221 ;
}
static void
F_144 ( struct V_1 * V_1 )
{
int V_48 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_89 ( V_1 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_48 = F_145 ( V_1 ) ;
F_146 ( V_48 , V_1 ) ;
}
static int
F_147 ( struct V_1 * V_1 )
{
int V_223 = 0 ;
unsigned long V_224 , V_34 ;
T_1 V_48 ;
T_5 V_225 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( V_1 -> V_226 & V_227 ) {
V_225 = ( T_5 ) F_80 ;
V_48 = V_1 -> V_228 [ V_229 ] . V_16 ;
V_224 = 0 ;
} else {
V_225 = ( T_5 ) F_86 ;
V_48 = V_1 -> V_18 -> V_48 ;
V_224 = V_230 ;
}
F_82 ( & V_1 -> V_138 , V_34 ) ;
sprintf ( V_1 -> V_231 , L_3 , V_232 ) ;
F_90 ( V_139 , & V_1 -> V_140 ) ;
F_25 ( V_1 , V_153 ) ;
V_223 = F_148 ( V_48 , V_225 , V_224 ,
V_1 -> V_231 , V_1 ) ;
return V_223 ;
}
static void
F_149 ( struct V_1 * V_1 , struct V_233 * V_234 )
{
F_139 ( V_234 -> V_235 ) ;
V_234 -> V_235 = NULL ;
}
static int
F_150 ( struct V_1 * V_1 , enum V_236 V_237 ,
T_1 V_238 , struct V_233 * V_234 )
{
int V_6 , V_239 = 0 ;
T_1 V_226 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_226 = V_1 -> V_226 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_226 & V_227 ) {
V_234 -> V_240 = V_241 ;
V_234 -> V_235 = F_141 ( V_234 -> V_214 ,
sizeof( struct V_242 ) ,
V_220 ) ;
if ( ! V_234 -> V_235 )
return - V_221 ;
switch ( V_237 ) {
case V_243 :
V_239 = V_244 + V_238 ;
break;
case V_245 :
V_239 = V_244 +
( V_1 -> V_146 * V_1 -> V_147 ) +
V_238 ;
break;
default:
F_151 () ;
}
for ( V_6 = 0 ; V_6 < V_234 -> V_214 ; V_6 ++ )
V_234 -> V_235 [ V_6 ] . V_16 = V_239 + V_6 ;
} else {
V_234 -> V_240 = V_246 ;
V_234 -> V_214 = 1 ;
V_234 -> V_235 = F_141 ( V_234 -> V_214 ,
sizeof( struct V_242 ) ,
V_220 ) ;
if ( ! V_234 -> V_235 )
return - V_221 ;
switch ( V_237 ) {
case V_243 :
V_234 -> V_235 [ 0 ] . V_16 = V_247 ;
break;
case V_245 :
V_234 -> V_235 [ 0 ] . V_16 = V_248 ;
break;
}
}
return 0 ;
}
static void
F_152 ( struct V_1 * V_1 , struct V_178 * V_148 ,
int V_249 )
{
int V_6 ;
int V_250 ;
for ( V_6 = 0 ; V_6 < V_249 ; V_6 ++ ) {
if ( V_148 -> V_26 [ V_6 ] == NULL )
continue;
V_250 = V_148 -> V_26 [ V_6 ] -> V_251 ;
F_146 ( V_1 -> V_228 [ V_250 ] . V_16 , V_148 -> V_26 [ V_6 ] ) ;
}
}
static int
F_153 ( struct V_1 * V_1 , struct V_178 * V_148 ,
T_1 V_170 , int V_249 )
{
int V_6 ;
int V_223 ;
int V_250 ;
for ( V_6 = 0 ; V_6 < V_249 ; V_6 ++ ) {
V_250 = V_148 -> V_26 [ V_6 ] -> V_251 ;
sprintf ( V_148 -> V_26 [ V_6 ] -> V_252 , L_4 , V_1 -> V_42 -> V_252 ,
V_170 + V_148 -> V_26 [ V_6 ] -> V_62 ) ;
V_223 = F_148 ( V_1 -> V_228 [ V_250 ] . V_16 ,
( T_5 ) F_30 , 0 ,
V_148 -> V_26 [ V_6 ] -> V_252 ,
V_148 -> V_26 [ V_6 ] ) ;
if ( V_223 )
goto V_222;
}
return 0 ;
V_222:
if ( V_6 > 0 )
F_152 ( V_1 , V_148 , ( V_6 - 1 ) ) ;
return - 1 ;
}
static void
F_154 ( struct V_1 * V_1 , struct V_143 * V_144 ,
int V_253 )
{
int V_6 ;
int V_250 ;
for ( V_6 = 0 ; V_6 < V_253 ; V_6 ++ ) {
if ( V_144 -> V_106 [ V_6 ] . V_3 == NULL )
continue;
V_250 = V_144 -> V_106 [ V_6 ] . V_3 -> V_251 ;
F_146 ( V_1 -> V_228 [ V_250 ] . V_16 ,
V_144 -> V_106 [ V_6 ] . V_3 ) ;
}
}
static int
F_155 ( struct V_1 * V_1 , struct V_143 * V_144 ,
T_1 V_254 , int V_253 )
{
int V_6 ;
int V_223 ;
int V_250 ;
for ( V_6 = 0 ; V_6 < V_253 ; V_6 ++ ) {
V_250 = V_144 -> V_106 [ V_6 ] . V_3 -> V_251 ;
sprintf ( V_144 -> V_106 [ V_6 ] . V_3 -> V_252 , L_5 ,
V_1 -> V_42 -> V_252 ,
V_254 + V_144 -> V_106 [ V_6 ] . V_3 -> V_62 ) ;
V_223 = F_148 ( V_1 -> V_228 [ V_250 ] . V_16 ,
( T_5 ) F_79 , 0 ,
V_144 -> V_106 [ V_6 ] . V_3 -> V_252 ,
V_144 -> V_106 [ V_6 ] . V_3 ) ;
if ( V_223 )
goto V_222;
}
return 0 ;
V_222:
if ( V_6 > 0 )
F_154 ( V_1 , V_144 , ( V_6 - 1 ) ) ;
return - 1 ;
}
static void
F_156 ( struct V_1 * V_1 , struct V_255 * V_256 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_257 ; V_6 ++ ) {
if ( V_256 [ V_6 ] . V_258 == V_259 )
F_136 ( V_1 , & V_256 [ V_6 ] . V_260 . V_211 ) ;
else if ( V_256 [ V_6 ] . V_258 == V_261 )
F_149 ( V_1 , & V_256 [ V_6 ] . V_260 . V_234 ) ;
}
}
static int
F_157 ( struct V_1 * V_1 , struct V_255 * V_256 ,
T_1 V_170 )
{
int V_6 , V_223 = 0 ;
for ( V_6 = 0 ; V_6 < V_257 ; V_6 ++ ) {
if ( V_256 [ V_6 ] . V_258 == V_259 )
V_223 = F_140 ( V_1 ,
& V_256 [ V_6 ] . V_260 . V_211 ) ;
else if ( V_256 [ V_6 ] . V_258 == V_261 )
V_223 = F_150 ( V_1 , V_243 , V_170 ,
& V_256 [ V_6 ] . V_260 . V_234 ) ;
if ( V_223 )
goto V_222;
}
return 0 ;
V_222:
F_156 ( V_1 , V_256 ) ;
return V_223 ;
}
static void
F_158 ( struct V_1 * V_1 , struct V_255 * V_256 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_262 ; V_6 ++ ) {
if ( V_256 [ V_6 ] . V_258 == V_259 )
F_136 ( V_1 , & V_256 [ V_6 ] . V_260 . V_211 ) ;
else if ( V_256 [ V_6 ] . V_258 == V_261 )
F_149 ( V_1 , & V_256 [ V_6 ] . V_260 . V_234 ) ;
}
}
static int
F_159 ( struct V_1 * V_1 , struct V_255 * V_256 ,
T_4 V_254 )
{
int V_6 , V_223 = 0 ;
for ( V_6 = 0 ; V_6 < V_262 ; V_6 ++ ) {
if ( V_256 [ V_6 ] . V_258 == V_259 )
V_223 = F_140 ( V_1 ,
& V_256 [ V_6 ] . V_260 . V_211 ) ;
else if ( V_256 [ V_6 ] . V_258 == V_261 )
V_223 = F_150 ( V_1 , V_245 , V_254 ,
& V_256 [ V_6 ] . V_260 . V_234 ) ;
if ( V_223 )
goto V_222;
}
return 0 ;
V_222:
F_158 ( V_1 , V_256 ) ;
return V_223 ;
}
static void
F_160 ( unsigned long V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_161 ( & V_1 -> V_141 . V_263 . V_264 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_162 ( unsigned long V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_163 ( & V_1 -> V_141 . V_263 . V_264 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_164 ( unsigned long V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_165 ( & V_1 -> V_141 . V_263 . V_264 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_166 ( unsigned long V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_167 ( & V_1 -> V_141 . V_263 . V_264 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_168 ( unsigned long V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
struct V_143 * V_144 ;
struct V_105 * V_106 ;
int V_6 , V_142 ;
unsigned long V_34 ;
if ( ! F_22 ( V_1 -> V_42 ) )
return;
F_81 ( & V_1 -> V_138 , V_34 ) ;
for ( V_6 = 0 ; V_6 < V_1 -> V_149 ; V_6 ++ ) {
V_144 = & V_1 -> V_144 [ V_6 ] ;
if ( ! V_144 -> V_150 )
continue;
for ( V_142 = 0 ; V_142 < V_1 -> V_151 ; V_142 ++ ) {
V_106 = & V_144 -> V_106 [ V_142 ] ;
if ( ! V_106 -> V_3 )
continue;
F_169 ( V_106 -> V_3 ) ;
}
}
if ( F_13 ( V_265 , & V_1 -> V_140 ) )
F_133 ( & V_1 -> V_266 ,
V_201 + F_118 ( V_267 ) ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_170 ( unsigned long V_49 )
{
struct V_1 * V_1 = (struct V_1 * ) V_49 ;
unsigned long V_34 ;
if ( ! F_132 ( V_1 -> V_42 ) ||
! F_13 ( V_199 , & V_1 -> V_140 ) )
return;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_171 ( & V_1 -> V_141 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
void
F_172 ( struct V_1 * V_1 )
{
if ( V_1 -> V_226 & V_268 &&
! F_13 ( V_265 , & V_1 -> V_140 ) ) {
F_173 ( & V_1 -> V_266 , F_168 ,
( unsigned long ) V_1 ) ;
F_90 ( V_265 , & V_1 -> V_140 ) ;
F_133 ( & V_1 -> V_266 ,
V_201 + F_118 ( V_267 ) ) ;
}
}
static void
F_174 ( struct V_1 * V_1 )
{
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( ! F_20 ( V_199 , & V_1 -> V_140 ) ) {
F_173 ( & V_1 -> V_200 , F_170 ,
( unsigned long ) V_1 ) ;
F_133 ( & V_1 -> V_200 ,
V_201 + F_118 ( V_202 ) ) ;
}
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_175 ( struct V_1 * V_1 )
{
int V_269 = 0 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( F_176 ( V_199 , & V_1 -> V_140 ) )
V_269 = 1 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_269 )
F_177 ( & V_1 -> V_200 ) ;
}
static void
F_178 ( struct V_41 * V_42 , T_6 * V_270 )
{
int V_6 = 1 ;
struct V_271 * V_272 ;
F_179 (mc_addr, netdev) {
F_92 ( & V_270 [ V_6 * V_273 ] , & V_272 -> V_274 [ 0 ] ) ;
V_6 ++ ;
}
}
static int
F_180 ( struct V_134 * V_110 , int V_100 )
{
struct V_105 * V_106 =
F_116 ( V_110 , struct V_105 , V_110 ) ;
struct V_1 * V_1 = V_106 -> V_1 ;
int V_275 = 0 ;
V_106 -> V_276 ++ ;
if ( ! F_22 ( V_1 -> V_42 ) )
goto V_277;
V_275 = F_63 ( V_1 , V_106 -> V_3 , V_100 ) ;
if ( V_275 >= V_100 )
return V_275 ;
V_277:
F_181 ( V_110 ) ;
V_106 -> V_278 ++ ;
if ( V_106 -> V_3 )
F_182 ( V_106 -> V_3 ) ;
return V_275 ;
}
static void
F_183 ( struct V_1 * V_1 , T_1 V_254 )
{
struct V_105 * V_106 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_151 ; V_6 ++ ) {
V_106 = & V_1 -> V_144 [ V_254 ] . V_106 [ V_6 ] ;
F_184 ( V_1 -> V_42 , & V_106 -> V_110 ,
F_180 , V_279 ) ;
}
}
static void
F_185 ( struct V_1 * V_1 , T_1 V_254 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_151 ; V_6 ++ )
F_186 ( & V_1 -> V_144 [ V_254 ] . V_106 [ V_6 ] . V_110 ) ;
}
void
F_187 ( struct V_1 * V_1 , T_1 V_170 )
{
struct V_178 * V_148 = & V_1 -> V_148 [ V_170 ] ;
struct V_255 * V_256 = & V_1 -> V_280 [ V_170 ] . V_256 [ 0 ] ;
unsigned long V_34 ;
if ( ! V_148 -> V_176 )
return;
F_188 ( & V_1 -> V_156 . V_177 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_189 ( V_148 -> V_176 , V_281 , F_107 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_190 ( & V_1 -> V_156 . V_177 ) ;
if ( V_148 -> V_26 [ 0 ] -> V_240 == V_241 )
F_152 ( V_1 , V_148 ,
V_1 -> V_147 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_191 ( V_148 -> V_176 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_148 -> V_176 = NULL ;
V_148 -> V_170 = 0 ;
F_156 ( V_1 , V_256 ) ;
}
int
F_192 ( struct V_1 * V_1 , T_1 V_170 )
{
int V_223 ;
struct V_178 * V_148 = & V_1 -> V_148 [ V_170 ] ;
struct V_255 * V_256 = & V_1 -> V_280 [ V_170 ] . V_256 [ 0 ] ;
struct V_233 * V_234 =
& V_256 [ V_282 ] . V_260 . V_234 ;
struct V_283 * V_284 = & V_1 -> V_284 [ V_170 ] ;
static const struct V_285 V_286 = {
. V_287 = F_108 ,
. V_288 = F_109 ,
. V_289 = F_112 ,
. V_290 = F_113 ,
. V_291 = F_120 ,
} ;
struct V_175 * V_176 ;
unsigned long V_34 ;
V_148 -> V_170 = V_170 ;
V_284 -> V_292 = V_1 -> V_147 ;
V_284 -> V_293 = V_1 -> V_293 ;
V_284 -> V_294 = V_295 ;
V_284 -> V_296 = V_1 -> V_297 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_193 ( V_1 -> V_147 ,
V_1 -> V_293 , V_256 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_194 ( & V_256 [ V_298 ] ,
V_1 -> V_147 , ( sizeof( struct V_10 ) *
V_1 -> V_293 ) ) ;
V_223 = F_157 ( V_1 , V_256 , V_170 ) ;
if ( V_223 )
return V_223 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_176 = F_195 ( & V_1 -> V_141 , V_1 , V_284 , & V_286 , V_256 ,
V_148 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( ! V_176 ) {
V_223 = - V_221 ;
goto V_222;
}
V_148 -> V_176 = V_176 ;
F_196 ( & V_148 -> V_184 ,
( V_299 ) F_115 ) ;
if ( V_234 -> V_240 == V_241 ) {
V_223 = F_153 ( V_1 , V_148 ,
V_170 , V_1 -> V_147 ) ;
if ( V_223 )
goto V_300;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_197 ( V_176 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
return 0 ;
V_300:
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_191 ( V_148 -> V_176 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_148 -> V_176 = NULL ;
V_148 -> V_170 = 0 ;
V_222:
F_156 ( V_1 , V_256 ) ;
return V_223 ;
}
static void
F_198 ( struct V_1 * V_1 , struct V_301 * V_302 )
{
memset ( V_302 , 0 , sizeof( * V_302 ) ) ;
V_302 -> V_303 = V_304 ;
V_302 -> V_305 = V_1 -> V_151 ;
V_302 -> V_296 = V_1 -> V_306 ;
if ( V_1 -> V_151 > 1 ) {
V_302 -> V_307 = V_308 ;
V_302 -> V_309 . V_310 =
( V_311 |
V_312 |
V_313 |
V_314 ) ;
V_302 -> V_309 . V_315 =
V_1 -> V_151 - 1 ;
F_199 ( V_302 -> V_309 . V_316 ,
sizeof( V_302 -> V_309 . V_316 ) ) ;
} else {
V_302 -> V_307 = V_317 ;
memset ( & V_302 -> V_309 , 0 ,
sizeof( V_302 -> V_309 ) ) ;
}
V_302 -> V_318 = F_200 ( V_1 -> V_42 -> V_319 ) ;
V_302 -> V_320 = V_317 ;
V_302 -> V_321 = V_322 ;
if ( F_201 ( V_1 ) &&
V_302 -> V_318 > 4096 ) {
V_302 -> V_323 = 2048 ;
V_302 -> V_324 = 4 ;
V_302 -> V_325 = V_1 -> V_326 * V_302 -> V_324 ;
V_302 -> V_320 = V_308 ;
} else {
V_302 -> V_323 = V_302 -> V_318 ;
V_302 -> V_324 = 1 ;
V_302 -> V_325 = V_1 -> V_326 ;
}
if ( V_302 -> V_321 == V_322 ) {
V_302 -> V_327 = V_1 -> V_326 ;
V_302 -> V_328 = V_329 ;
}
V_302 -> V_330 =
( V_1 -> V_42 -> V_121 & V_130 ) ?
V_308 : V_317 ;
}
static void
F_202 ( struct V_1 * V_1 , T_1 V_254 )
{
struct V_143 * V_144 = & V_1 -> V_144 [ V_254 ] ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_151 ; V_6 ++ )
V_144 -> V_106 [ V_6 ] . V_1 = V_1 ;
}
static T_1
F_203 ( struct V_1 * V_1 )
{
struct V_41 * V_42 = V_1 -> V_42 ;
T_1 V_223 = 0 , V_331 = 0 ;
T_1 V_254 = 0 , V_332 = 0 ;
unsigned long V_34 ;
for ( V_254 = 0 ; V_254 < V_1 -> V_149 ; V_254 ++ ) {
if ( ! V_1 -> V_144 [ V_254 ] . V_150 )
continue;
F_204 ( V_1 , V_254 ) ;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_205 ( & V_1 -> V_141 . V_181 ,
F_200 ( V_1 -> V_42 -> V_319 ) , NULL ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
for ( V_254 = 0 ; V_254 < V_1 -> V_149 ; V_254 ++ ) {
V_332 ++ ;
V_331 = F_206 ( V_1 , V_254 ) ;
if ( V_331 && ! V_223 ) {
V_223 = V_331 ;
F_207 ( V_42 , L_6 , V_254 ) ;
}
}
if ( V_1 -> V_144 [ 0 ] . V_150 && ! V_223 ) {
F_208 ( V_1 , 0 ) ;
F_209 ( V_1 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_210 ( V_1 , V_42 -> V_155 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_211 ( V_42 ) ;
}
return V_332 ;
}
void
F_204 ( struct V_1 * V_1 , T_1 V_254 )
{
struct V_143 * V_144 = & V_1 -> V_144 [ V_254 ] ;
struct V_301 * V_302 = & V_1 -> V_302 [ V_254 ] ;
struct V_255 * V_256 = & V_1 -> V_333 [ V_254 ] . V_256 [ 0 ] ;
unsigned long V_34 ;
int V_269 = 0 ;
if ( ! V_144 -> V_150 )
return;
if ( 0 == V_254 ) {
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( V_1 -> V_226 & V_268 &&
F_13 ( V_265 , & V_1 -> V_140 ) ) {
F_29 ( V_265 , & V_1 -> V_140 ) ;
V_269 = 1 ;
}
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_269 )
F_177 ( & V_1 -> V_266 ) ;
}
F_188 ( & V_1 -> V_156 . V_191 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_212 ( V_144 -> V_150 , V_281 , F_129 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_190 ( & V_1 -> V_156 . V_191 ) ;
if ( V_144 -> V_106 [ 0 ] . V_3 -> V_240 == V_241 )
F_154 ( V_1 , V_144 , V_302 -> V_305 ) ;
F_185 ( V_1 , V_254 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_213 ( V_144 -> V_150 ) ;
V_144 -> V_150 = NULL ;
V_144 -> V_254 = 0 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_158 ( V_1 , V_256 ) ;
}
int
F_206 ( struct V_1 * V_1 , T_1 V_254 )
{
int V_223 ;
struct V_143 * V_144 = & V_1 -> V_144 [ V_254 ] ;
struct V_255 * V_256 = & V_1 -> V_333 [ V_254 ] . V_256 [ 0 ] ;
struct V_233 * V_234 =
& V_256 [ V_334 ] . V_260 . V_234 ;
struct V_301 * V_302 = & V_1 -> V_302 [ V_254 ] ;
static const struct V_335 V_336 = {
. V_337 = NULL ,
. V_338 = NULL ,
. V_339 = F_110 ,
. V_340 = F_111 ,
. V_341 = F_121 ,
. V_342 = F_125 ,
. V_343 = F_127 ,
} ;
struct V_187 * V_150 ;
unsigned long V_34 ;
V_144 -> V_254 = V_254 ;
F_198 ( V_1 , V_302 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_214 ( V_302 , V_256 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_194 ( & V_256 [ V_344 ] ,
V_302 -> V_305 ,
( V_302 -> V_325 *
sizeof( struct V_66 ) ) +
sizeof( struct V_53 ) ) ;
if ( V_302 -> V_321 != V_345 ) {
F_194 ( & V_256 [ V_346 ] ,
V_302 -> V_305 ,
( V_302 -> V_327 *
sizeof( struct V_66 ) +
sizeof( struct V_53 ) ) ) ;
}
V_223 = F_159 ( V_1 , V_256 , V_254 ) ;
if ( V_223 )
return V_223 ;
F_202 ( V_1 , V_254 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_150 = F_215 ( & V_1 -> V_141 , V_1 , V_302 , & V_336 , V_256 ,
V_144 ) ;
if ( ! V_150 ) {
V_223 = - V_221 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
goto V_222;
}
V_144 -> V_150 = V_150 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_216 ( & V_144 -> V_189 ,
( V_299 ) ( F_122 ) ) ;
F_183 ( V_1 , V_254 ) ;
if ( V_234 -> V_240 == V_241 ) {
V_223 = F_155 ( V_1 , V_144 , V_254 ,
V_302 -> V_305 ) ;
if ( V_223 )
goto V_222;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( 0 == V_254 ) {
if ( V_1 -> V_226 & V_268 )
F_217 ( & V_1 -> V_141 , V_347 ) ;
F_218 ( V_150 ) ;
F_172 ( V_1 ) ;
}
F_219 ( V_150 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
return 0 ;
V_222:
F_204 ( V_1 , V_254 ) ;
return V_223 ;
}
void
F_220 ( struct V_1 * V_1 )
{
struct V_178 * V_148 ;
V_148 = & V_1 -> V_148 [ 0 ] ;
if ( ! V_148 -> V_176 )
return;
F_221 ( V_148 -> V_176 , V_1 -> V_297 ) ;
}
void
F_222 ( struct V_1 * V_1 )
{
struct V_143 * V_144 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_149 ; V_6 ++ ) {
V_144 = & V_1 -> V_144 [ V_6 ] ;
if ( ! V_144 -> V_150 )
continue;
F_223 ( V_144 -> V_150 ,
V_1 -> V_306 ) ;
}
}
int
F_210 ( struct V_1 * V_1 , const T_6 * V_348 )
{
int V_349 ;
if ( ! F_224 ( V_348 ) )
return - V_350 ;
if ( ! V_1 -> V_144 [ 0 ] . V_150 )
return 0 ;
V_349 = F_225 ( V_1 -> V_144 [ 0 ] . V_150 , V_348 ) ;
if ( V_349 != V_158 )
return - V_350 ;
return 0 ;
}
int
F_209 ( struct V_1 * V_1 )
{
struct V_143 * V_144 = & V_1 -> V_144 [ 0 ] ;
int V_349 ;
unsigned long V_34 ;
F_188 ( & V_1 -> V_156 . V_193 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_349 = F_226 ( V_144 -> V_150 , V_351 ,
F_130 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_349 == V_158 )
F_190 ( & V_1 -> V_156 . V_193 ) ;
else
return - V_352 ;
if ( V_1 -> V_156 . V_192 != V_158 )
return - V_352 ;
return 0 ;
}
void
F_208 ( struct V_1 * V_1 , T_1 V_254 )
{
T_7 V_353 ;
unsigned long V_34 ;
F_227 (vid, bnad->active_vlans, VLAN_N_VID) {
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_228 ( V_1 -> V_144 [ V_254 ] . V_150 , V_353 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
}
void
F_229 ( struct V_1 * V_1 , struct V_354 * V_197 )
{
int V_6 , V_142 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_149 ; V_6 ++ ) {
for ( V_142 = 0 ; V_142 < V_1 -> V_151 ; V_142 ++ ) {
if ( V_1 -> V_144 [ V_6 ] . V_106 [ V_142 ] . V_3 ) {
V_197 -> V_117 += V_1 -> V_144 [ V_6 ] .
V_106 [ V_142 ] . V_3 -> V_52 [ 0 ] -> V_59 -> V_117 ;
V_197 -> V_118 += V_1 -> V_144 [ V_6 ] .
V_106 [ V_142 ] . V_3 -> V_52 [ 0 ] -> V_59 -> V_118 ;
if ( V_1 -> V_144 [ V_6 ] . V_106 [ V_142 ] . V_3 -> V_52 [ 1 ] &&
V_1 -> V_144 [ V_6 ] . V_106 [ V_142 ] . V_3 ->
V_52 [ 1 ] -> V_59 ) {
V_197 -> V_117 +=
V_1 -> V_144 [ V_6 ] . V_106 [ V_142 ] .
V_3 -> V_52 [ 1 ] -> V_59 -> V_117 ;
V_197 -> V_118 +=
V_1 -> V_144 [ V_6 ] . V_106 [ V_142 ] .
V_3 -> V_52 [ 1 ] -> V_59 -> V_118 ;
}
}
}
}
for ( V_6 = 0 ; V_6 < V_1 -> V_146 ; V_6 ++ ) {
for ( V_142 = 0 ; V_142 < V_1 -> V_147 ; V_142 ++ ) {
if ( V_1 -> V_148 [ V_6 ] . V_26 [ V_142 ] ) {
V_197 -> V_39 +=
V_1 -> V_148 [ V_6 ] . V_26 [ V_142 ] -> V_38 -> V_39 ;
V_197 -> V_40 +=
V_1 -> V_148 [ V_6 ] . V_26 [ V_142 ] -> V_38 -> V_40 ;
}
}
}
}
void
F_230 ( struct V_1 * V_1 , struct V_354 * V_197 )
{
struct V_355 * V_356 ;
T_1 V_357 ;
int V_6 ;
V_356 = & V_1 -> V_197 . V_196 -> V_358 . V_356 ;
V_197 -> V_359 =
V_356 -> V_360 + V_356 -> V_361 +
V_356 -> V_362 + V_356 -> V_363 +
V_356 -> V_364 ;
V_197 -> V_365 = V_356 -> V_366 +
V_356 -> V_367 ;
V_197 -> V_368 = V_356 -> V_369 ;
V_197 -> V_370 = V_356 -> V_371 ;
V_197 -> V_372 = V_356 -> V_373 ;
V_197 -> V_374 = V_356 -> V_375 ;
V_197 -> V_376 = V_356 -> V_362 ;
V_197 -> V_377 = V_356 -> V_360 ;
V_197 -> V_378 = V_356 -> V_361 ;
V_357 = F_231 ( & V_1 -> V_141 ) ;
for ( V_6 = 0 ; V_357 ; V_6 ++ ) {
if ( V_357 & 1 ) {
V_197 -> V_379 +=
V_1 -> V_197 . V_196 ->
V_358 . V_380 [ V_6 ] . V_381 ;
break;
}
V_357 >>= 1 ;
}
}
static void
F_232 ( struct V_1 * V_1 )
{
T_1 V_48 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( V_1 -> V_226 & V_227 )
V_48 = V_1 -> V_228 [ V_229 ] . V_16 ;
else
V_48 = V_1 -> V_18 -> V_48 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_233 ( V_48 ) ;
}
static int
F_234 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
int V_223 ;
V_223 = F_235 ( V_15 , 0 ) ;
if ( V_223 < 0 ) {
F_25 ( V_1 , V_382 ) ;
return V_223 ;
}
if ( F_236 ( V_15 ) == F_70 ( V_383 ) ) {
struct V_384 * V_385 = F_237 ( V_15 ) ;
V_385 -> V_386 = 0 ;
V_385 -> V_387 = 0 ;
F_238 ( V_15 ) -> V_387 =
~ F_239 ( V_385 -> V_388 , V_385 -> V_389 , 0 ,
V_390 , 0 ) ;
F_25 ( V_1 , V_391 ) ;
} else {
struct V_392 * V_393 = F_240 ( V_15 ) ;
V_393 -> V_394 = 0 ;
F_238 ( V_15 ) -> V_387 =
~ F_241 ( & V_393 -> V_388 , & V_393 -> V_389 , 0 ,
V_390 , 0 ) ;
F_25 ( V_1 , V_395 ) ;
}
return 0 ;
}
static void
F_242 ( struct V_1 * V_1 )
{
int V_396 ;
V_396 = F_243 ( ( T_4 ) F_244 () ,
( T_4 ) ( V_397 * V_188 ) ) ;
if ( ! ( V_1 -> V_226 & V_227 ) )
V_396 = 1 ;
V_1 -> V_149 = 1 ;
V_1 -> V_146 = 1 ;
V_1 -> V_151 = V_396 ;
V_1 -> V_147 = V_398 ;
}
static void
F_245 ( struct V_1 * V_1 , int V_399 , int V_400 )
{
V_1 -> V_147 = 1 ;
if ( ( V_399 >= ( V_1 -> V_146 * V_1 -> V_147 ) +
V_401 + V_244 ) &&
( V_1 -> V_226 & V_227 ) ) {
V_1 -> V_151 = V_399 -
( V_1 -> V_146 * V_1 -> V_147 ) -
V_244 ;
} else
V_1 -> V_151 = 1 ;
}
static int
F_246 ( struct V_1 * V_1 )
{
unsigned long V_34 ;
int V_223 = 0 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_188 ( & V_1 -> V_156 . V_159 ) ;
F_247 ( & V_1 -> V_141 . V_263 , V_281 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_248 ( & V_1 -> V_156 . V_159 ,
F_118 ( V_402 ) ) ;
V_223 = V_1 -> V_156 . V_157 ;
return V_223 ;
}
static int
F_249 ( struct V_1 * V_1 )
{
int V_223 = 0 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_188 ( & V_1 -> V_156 . V_159 ) ;
V_1 -> V_156 . V_157 = V_403 ;
F_250 ( & V_1 -> V_141 . V_263 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_248 ( & V_1 -> V_156 . V_159 ,
F_118 ( V_402 ) ) ;
V_223 = V_1 -> V_156 . V_157 ;
return V_223 ;
}
static void
F_251 ( struct V_1 * V_1 , struct V_255 * V_256 ,
T_1 V_404 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_404 ; V_6 ++ )
F_136 ( V_1 , & V_256 [ V_6 ] . V_260 . V_211 ) ;
}
static int
F_252 ( struct V_1 * V_1 , struct V_255 * V_256 ,
T_1 V_404 )
{
int V_6 , V_223 ;
for ( V_6 = 0 ; V_6 < V_404 ; V_6 ++ ) {
V_223 = F_140 ( V_1 , & V_256 [ V_6 ] . V_260 . V_211 ) ;
if ( V_223 )
goto V_222;
}
return 0 ;
V_222:
F_251 ( V_1 , V_256 , V_404 ) ;
return V_223 ;
}
static void
F_253 ( struct V_1 * V_1 )
{
int V_6 , V_349 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( ! ( V_1 -> V_226 & V_227 ) ) {
F_82 ( & V_1 -> V_138 , V_34 ) ;
return;
}
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_1 -> V_228 )
return;
V_1 -> V_228 =
F_141 ( V_1 -> V_405 , sizeof( struct V_406 ) , V_220 ) ;
if ( ! V_1 -> V_228 )
goto V_407;
for ( V_6 = 0 ; V_6 < V_1 -> V_405 ; V_6 ++ )
V_1 -> V_228 [ V_6 ] . V_408 = V_6 ;
V_349 = F_254 ( V_1 -> V_18 , V_1 -> V_228 ,
1 , V_1 -> V_405 ) ;
if ( V_349 < 0 ) {
goto V_407;
} else if ( V_349 < V_1 -> V_405 ) {
F_255 ( & V_1 -> V_18 -> V_19 ,
L_7 ,
V_349 , V_1 -> V_405 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_245 ( V_1 , ( V_349 - V_244 ) / 2 ,
( V_349 - V_244 ) / 2 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_1 -> V_405 = V_409 + V_410 +
V_244 ;
if ( V_1 -> V_405 > V_349 ) {
F_256 ( V_1 -> V_18 ) ;
goto V_407;
}
}
F_257 ( V_1 -> V_18 , 0 ) ;
return;
V_407:
F_255 ( & V_1 -> V_18 -> V_19 ,
L_8 ) ;
F_139 ( V_1 -> V_228 ) ;
V_1 -> V_228 = NULL ;
V_1 -> V_405 = 0 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_1 -> V_226 &= ~ V_227 ;
F_242 ( V_1 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static void
F_258 ( struct V_1 * V_1 )
{
T_1 V_226 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_226 = V_1 -> V_226 ;
if ( V_1 -> V_226 & V_227 )
V_1 -> V_226 &= ~ V_227 ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_226 & V_227 ) {
F_256 ( V_1 -> V_18 ) ;
F_139 ( V_1 -> V_228 ) ;
V_1 -> V_228 = NULL ;
}
}
static int
F_259 ( struct V_41 * V_42 )
{
int V_223 ;
struct V_1 * V_1 = F_260 ( V_42 ) ;
struct V_411 V_412 ;
unsigned long V_34 ;
F_261 ( & V_1 -> V_413 ) ;
V_223 = F_192 ( V_1 , 0 ) ;
if ( V_223 )
goto V_222;
V_223 = F_206 ( V_1 , 0 ) ;
if ( V_223 )
goto V_300;
V_412 . V_414 = 0 ;
V_412 . V_415 = 0 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_205 ( & V_1 -> V_141 . V_181 ,
F_200 ( V_1 -> V_42 -> V_319 ) , NULL ) ;
F_262 ( & V_1 -> V_141 . V_181 , & V_412 ) ;
F_263 ( & V_1 -> V_141 . V_181 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_209 ( V_1 ) ;
F_208 ( V_1 , 0 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_210 ( V_1 , V_42 -> V_155 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_174 ( V_1 ) ;
F_264 ( & V_1 -> V_413 ) ;
return 0 ;
V_300:
F_187 ( V_1 , 0 ) ;
V_222:
F_264 ( & V_1 -> V_413 ) ;
return V_223 ;
}
static int
F_265 ( struct V_41 * V_42 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
unsigned long V_34 ;
F_261 ( & V_1 -> V_413 ) ;
F_175 ( V_1 ) ;
F_188 ( & V_1 -> V_156 . V_162 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_266 ( & V_1 -> V_141 . V_181 , V_281 ,
F_100 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_190 ( & V_1 -> V_156 . V_162 ) ;
F_187 ( V_1 , 0 ) ;
F_204 ( V_1 , 0 ) ;
F_232 ( V_1 ) ;
F_264 ( & V_1 -> V_413 ) ;
return 0 ;
}
static int
F_267 ( struct V_1 * V_1 , struct V_25 * V_26 ,
struct V_14 * V_15 , struct V_416 * V_417 )
{
T_7 V_34 = 0 ;
T_1 V_418 ;
T_7 V_132 = 0 ;
if ( F_268 ( V_15 ) ) {
V_132 = ( T_7 ) F_269 ( V_15 ) ;
V_34 |= ( V_419 | V_420 ) ;
}
if ( F_13 ( V_168 , & V_1 -> V_140 ) ) {
V_132 = ( ( V_26 -> V_421 & 0x7 ) << V_422 )
| ( V_132 & 0x1fff ) ;
V_34 |= ( V_419 | V_420 ) ;
}
V_417 -> V_423 . V_424 . V_132 = F_70 ( V_132 ) ;
if ( F_270 ( V_15 ) ) {
V_418 = F_59 ( V_15 ) -> V_418 ;
if ( F_43 ( V_418 > V_1 -> V_42 -> V_319 ) ) {
F_25 ( V_1 , V_425 ) ;
return - V_426 ;
}
if ( F_43 ( ( V_418 + F_271 ( V_15 ) +
F_272 ( V_15 ) ) >= V_15 -> V_37 ) ) {
V_417 -> V_423 . V_424 . V_427 = F_70 ( V_428 ) ;
V_417 -> V_423 . V_424 . V_429 = 0 ;
F_25 ( V_1 , V_430 ) ;
} else {
V_417 -> V_423 . V_424 . V_427 = F_70 ( V_431 ) ;
V_417 -> V_423 . V_424 . V_429 = F_70 ( V_418 ) ;
}
if ( F_234 ( V_1 , V_15 ) ) {
F_25 ( V_1 , V_432 ) ;
return - V_426 ;
}
V_34 |= ( V_433 | V_434 ) ;
V_417 -> V_423 . V_424 . V_435 =
F_70 ( F_273 (
F_272 ( V_15 ) >> 2 , F_271 ( V_15 ) ) ) ;
} else {
V_417 -> V_423 . V_424 . V_427 = F_70 ( V_428 ) ;
V_417 -> V_423 . V_424 . V_429 = 0 ;
if ( F_43 ( V_15 -> V_37 > ( V_1 -> V_42 -> V_319 + V_436 ) ) ) {
F_25 ( V_1 , V_437 ) ;
return - V_426 ;
}
if ( V_15 -> V_127 == V_438 ) {
T_8 V_439 = F_236 ( V_15 ) ;
T_6 V_440 = 0 ;
if ( V_439 == F_70 ( V_383 ) )
V_440 = F_237 ( V_15 ) -> V_99 ;
#ifdef F_274
else if ( V_439 == F_70 ( V_441 ) ) {
V_440 = F_240 ( V_15 ) -> V_442 ;
}
#endif
if ( V_440 == V_390 ) {
V_34 |= V_434 ;
V_417 -> V_423 . V_424 . V_435 =
F_70 ( F_273
( 0 , F_271 ( V_15 ) ) ) ;
F_25 ( V_1 , V_443 ) ;
if ( F_43 ( F_5 ( V_15 ) <
F_271 ( V_15 ) +
F_272 ( V_15 ) ) ) {
F_25 ( V_1 , V_444 ) ;
return - V_426 ;
}
} else if ( V_440 == V_445 ) {
V_34 |= V_446 ;
V_417 -> V_423 . V_424 . V_435 =
F_70 ( F_273
( 0 , F_271 ( V_15 ) ) ) ;
F_25 ( V_1 , V_447 ) ;
if ( F_43 ( F_5 ( V_15 ) <
F_271 ( V_15 ) +
sizeof( struct V_448 ) ) ) {
F_25 ( V_1 , V_449 ) ;
return - V_426 ;
}
} else {
F_25 ( V_1 , V_450 ) ;
return - V_426 ;
}
} else
V_417 -> V_423 . V_424 . V_435 = 0 ;
}
V_417 -> V_423 . V_424 . V_34 = F_70 ( V_34 ) ;
V_417 -> V_423 . V_424 . V_451 = F_275 ( V_15 -> V_37 ) ;
return 0 ;
}
static T_9
F_276 ( struct V_14 * V_15 , struct V_41 * V_42 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
T_1 V_173 = 0 ;
struct V_25 * V_26 = NULL ;
struct V_10 * V_11 , * V_13 , * V_452 ;
T_1 V_71 , V_7 , V_453 ;
T_1 V_29 , V_20 , V_37 ;
int V_6 ;
T_3 V_21 ;
struct V_416 * V_417 ;
V_37 = F_5 ( V_15 ) ;
if ( F_43 ( V_15 -> V_37 <= V_454 ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_455 ) ;
return V_456 ;
}
if ( F_43 ( V_37 > V_457 ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_458 ) ;
return V_456 ;
}
if ( F_43 ( V_37 == 0 ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_458 ) ;
return V_456 ;
}
V_26 = V_1 -> V_148 [ 0 ] . V_26 [ V_173 ] ;
if ( F_43 ( ! V_26 || ! F_13 ( V_33 , & V_26 -> V_34 ) ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_459 ) ;
return V_456 ;
}
V_7 = V_26 -> V_7 ;
V_71 = V_26 -> V_77 ;
V_11 = V_26 -> V_11 ;
V_20 = 1 + F_59 ( V_15 ) -> V_97 ;
V_29 = F_18 ( V_20 ) ;
if ( F_43 ( V_20 > V_460 ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_461 ) ;
return V_456 ;
}
if ( F_43 ( V_29 > F_23 ( V_26 , V_7 ) ) ) {
if ( ( * V_26 -> V_35 != V_26 -> V_36 ) &&
! F_20 ( V_44 , & V_26 -> V_34 ) ) {
T_1 V_43 ;
V_43 = F_12 ( V_1 , V_26 ) ;
if ( F_26 ( F_13 ( V_33 , & V_26 -> V_34 ) ) )
F_27 ( V_26 -> V_47 , V_43 ) ;
F_28 () ;
F_29 ( V_44 , & V_26 -> V_34 ) ;
} else {
F_277 ( V_42 ) ;
F_25 ( V_1 , V_174 ) ;
}
F_47 () ;
if ( F_26 ( V_29 > F_23 ( V_26 , V_7 ) ) ) {
F_25 ( V_1 , V_174 ) ;
return V_462 ;
} else {
F_24 ( V_42 ) ;
F_25 ( V_1 , V_46 ) ;
}
}
V_417 = & ( (struct V_416 * ) V_26 -> V_8 ) [ V_71 ] ;
V_452 = & V_11 [ V_71 ] ;
if ( F_267 ( V_1 , V_26 , V_15 , V_417 ) ) {
F_11 ( V_15 ) ;
return V_456 ;
}
V_417 -> V_423 . V_424 . V_463 = 0 ;
V_417 -> V_423 . V_424 . V_464 = V_20 ;
V_452 -> V_15 = V_15 ;
V_452 -> V_17 = 0 ;
V_13 = V_452 ;
V_21 = F_51 ( & V_1 -> V_18 -> V_19 , V_15 -> V_49 ,
V_37 , V_22 ) ;
if ( F_45 ( & V_1 -> V_18 -> V_19 , V_21 ) ) {
F_11 ( V_15 ) ;
F_25 ( V_1 , V_465 ) ;
return V_456 ;
}
F_46 ( V_21 , & V_417 -> V_16 [ 0 ] . V_83 ) ;
V_417 -> V_16 [ 0 ] . V_95 = F_70 ( V_37 ) ;
F_6 ( & V_13 -> V_20 [ 0 ] , V_21 , V_21 ) ;
V_452 -> V_17 ++ ;
for ( V_6 = 0 , V_453 = 0 ; V_6 < V_20 - 1 ; V_6 ++ ) {
const struct V_466 * V_467 = & F_59 ( V_15 ) -> V_468 [ V_6 ] ;
T_1 V_469 = F_278 ( V_467 ) ;
if ( F_43 ( V_469 == 0 ) ) {
F_2 ( V_1 , V_11 , V_7 ,
V_26 -> V_77 ) ;
F_11 ( V_15 ) ;
F_25 ( V_1 , V_470 ) ;
return V_456 ;
}
V_37 += V_469 ;
V_453 ++ ;
if ( V_453 == V_23 ) {
V_453 = 0 ;
F_7 ( V_71 , V_7 ) ;
V_417 = & ( (struct V_416 * ) V_26 -> V_8 ) [ V_71 ] ;
V_417 -> V_423 . V_471 . V_427 = F_70 ( V_472 ) ;
V_13 = & V_11 [ V_71 ] ;
}
V_21 = F_279 ( & V_1 -> V_18 -> V_19 , V_467 ,
0 , V_469 , V_22 ) ;
if ( F_45 ( & V_1 -> V_18 -> V_19 , V_21 ) ) {
F_2 ( V_1 , V_11 , V_7 ,
V_26 -> V_77 ) ;
F_11 ( V_15 ) ;
F_25 ( V_1 , V_465 ) ;
return V_456 ;
}
F_280 ( & V_13 -> V_20 [ V_453 ] , V_24 , V_469 ) ;
F_46 ( V_21 , & V_417 -> V_16 [ V_453 ] . V_83 ) ;
V_417 -> V_16 [ V_453 ] . V_95 = F_70 ( V_469 ) ;
F_6 ( & V_13 -> V_20 [ V_453 ] , V_21 ,
V_21 ) ;
V_452 -> V_17 ++ ;
}
if ( F_43 ( V_37 != V_15 -> V_37 ) ) {
F_2 ( V_1 , V_11 , V_7 , V_26 -> V_77 ) ;
F_11 ( V_15 ) ;
F_25 ( V_1 , V_473 ) ;
return V_456 ;
}
F_7 ( V_71 , V_7 ) ;
V_26 -> V_77 = V_71 ;
F_281 () ;
if ( F_43 ( ! F_13 ( V_33 , & V_26 -> V_34 ) ) )
return V_456 ;
F_282 ( V_15 ) ;
F_283 ( V_26 ) ;
return V_456 ;
}
static struct V_354 *
F_284 ( struct V_41 * V_42 , struct V_354 * V_197 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_229 ( V_1 , V_197 ) ;
F_230 ( V_1 , V_197 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
return V_197 ;
}
static void
F_285 ( struct V_1 * V_1 )
{
struct V_41 * V_42 = V_1 -> V_42 ;
int V_474 = F_286 ( V_42 ) ;
enum V_194 V_349 ;
T_6 * V_475 ;
struct V_271 * V_476 ;
int V_408 ;
if ( F_287 ( V_1 -> V_42 ) ) {
F_288 ( V_1 -> V_144 [ 0 ] . V_150 , 0 , NULL ) ;
return;
}
if ( V_474 > F_289 ( & V_1 -> V_141 ) -> V_477 )
goto V_478;
V_475 = F_143 ( V_474 * V_273 , V_78 ) ;
if ( V_475 == NULL )
goto V_478;
V_408 = 0 ;
F_290 (ha, netdev) {
F_92 ( & V_475 [ V_408 * V_273 ] , & V_476 -> V_274 [ 0 ] ) ;
V_408 ++ ;
}
V_349 = F_288 ( V_1 -> V_144 [ 0 ] . V_150 , V_408 , V_475 ) ;
F_139 ( V_475 ) ;
if ( V_349 != V_158 )
goto V_478;
return;
V_478:
V_1 -> V_226 |= V_479 ;
F_288 ( V_1 -> V_144 [ 0 ] . V_150 , 0 , NULL ) ;
}
static void
F_291 ( struct V_1 * V_1 )
{
struct V_41 * V_42 = V_1 -> V_42 ;
int V_480 = F_292 ( V_42 ) ;
enum V_194 V_349 ;
T_6 * V_475 ;
if ( V_42 -> V_34 & V_481 )
goto V_482;
if ( F_293 ( V_42 ) )
return;
if ( V_480 > F_289 ( & V_1 -> V_141 ) -> V_483 )
goto V_482;
V_475 = F_143 ( ( V_480 + 1 ) * V_273 , V_78 ) ;
if ( V_475 == NULL )
goto V_482;
F_92 ( & V_475 [ 0 ] , & V_351 [ 0 ] ) ;
F_178 ( V_42 , V_475 ) ;
V_349 = F_294 ( V_1 -> V_144 [ 0 ] . V_150 , V_480 + 1 , V_475 ) ;
F_139 ( V_475 ) ;
if ( V_349 != V_158 )
goto V_482;
return;
V_482:
V_1 -> V_226 |= V_484 ;
F_295 ( V_1 -> V_144 [ 0 ] . V_150 ) ;
}
void
F_211 ( struct V_41 * V_42 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
enum V_485 V_486 , V_487 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( V_1 -> V_144 [ 0 ] . V_150 == NULL ) {
F_82 ( & V_1 -> V_138 , V_34 ) ;
return;
}
V_1 -> V_226 &= ~ ( V_488 | V_479 |
V_484 ) ;
V_486 = 0 ;
if ( V_42 -> V_34 & V_489 ) {
V_486 |= V_490 ;
V_1 -> V_226 |= V_488 ;
} else {
F_291 ( V_1 ) ;
if ( V_1 -> V_226 & V_484 )
V_486 |= V_491 ;
F_285 ( V_1 ) ;
if ( V_1 -> V_226 & V_479 )
V_486 |= V_492 ;
}
V_487 = V_493 | V_492 |
V_491 ;
F_296 ( V_1 -> V_144 [ 0 ] . V_150 , V_486 , V_487 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
static int
F_297 ( struct V_41 * V_42 , void * V_274 )
{
int V_223 ;
struct V_1 * V_1 = F_260 ( V_42 ) ;
struct V_494 * V_495 = (struct V_494 * ) V_274 ;
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
V_223 = F_210 ( V_1 , V_495 -> V_496 ) ;
if ( ! V_223 )
F_92 ( V_42 -> V_155 , V_495 -> V_496 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
return V_223 ;
}
static int
F_298 ( struct V_1 * V_1 , int V_318 )
{
unsigned long V_34 ;
F_188 ( & V_1 -> V_156 . V_204 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_205 ( & V_1 -> V_141 . V_181 , V_318 , F_134 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_190 ( & V_1 -> V_156 . V_204 ) ;
return V_1 -> V_156 . V_203 ;
}
static int
F_299 ( struct V_41 * V_42 , int V_497 )
{
int V_223 , V_319 ;
struct V_1 * V_1 = F_260 ( V_42 ) ;
T_1 V_498 = 0 , V_499 , V_500 ;
if ( V_497 + V_454 < V_501 || V_497 > V_502 )
return - V_426 ;
F_261 ( & V_1 -> V_413 ) ;
V_319 = V_42 -> V_319 ;
V_42 -> V_319 = V_497 ;
V_499 = F_200 ( V_319 ) ;
V_500 = F_200 ( V_497 ) ;
if ( F_201 ( V_1 ) &&
F_132 ( V_1 -> V_42 ) ) {
if ( ( V_499 <= 4096 && V_500 > 4096 ) ||
( V_499 > 4096 && V_500 <= 4096 ) )
V_498 = F_203 ( V_1 ) ;
}
V_223 = F_298 ( V_1 , V_500 ) ;
if ( V_223 )
V_223 = - V_503 ;
F_264 ( & V_1 -> V_413 ) ;
return V_223 ;
}
static int
F_300 ( struct V_41 * V_42 , T_8 V_440 , T_7 V_353 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
unsigned long V_34 ;
if ( ! V_1 -> V_144 [ 0 ] . V_150 )
return 0 ;
F_261 ( & V_1 -> V_413 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_228 ( V_1 -> V_144 [ 0 ] . V_150 , V_353 ) ;
F_90 ( V_353 , V_1 -> V_504 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_264 ( & V_1 -> V_413 ) ;
return 0 ;
}
static int
F_301 ( struct V_41 * V_42 , T_8 V_440 , T_7 V_353 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
unsigned long V_34 ;
if ( ! V_1 -> V_144 [ 0 ] . V_150 )
return 0 ;
F_261 ( & V_1 -> V_413 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_29 ( V_353 , V_1 -> V_504 ) ;
F_302 ( V_1 -> V_144 [ 0 ] . V_150 , V_353 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_264 ( & V_1 -> V_413 ) ;
return 0 ;
}
static int F_303 ( struct V_41 * V_19 , T_10 V_121 )
{
struct V_1 * V_1 = F_260 ( V_19 ) ;
T_10 V_505 = V_121 ^ V_19 -> V_121 ;
if ( ( V_505 & V_130 ) && F_132 ( V_19 ) ) {
unsigned long V_34 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( V_121 & V_130 )
F_304 ( V_1 -> V_144 [ 0 ] . V_150 ) ;
else
F_305 ( V_1 -> V_144 [ 0 ] . V_150 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
}
return 0 ;
}
static void
F_306 ( struct V_41 * V_42 )
{
struct V_1 * V_1 = F_260 ( V_42 ) ;
struct V_143 * V_144 ;
struct V_105 * V_106 ;
T_1 V_506 ;
int V_6 , V_142 ;
if ( ! ( V_1 -> V_226 & V_227 ) ) {
F_307 ( & V_1 -> V_141 , V_506 ) ;
F_86 ( V_1 -> V_18 -> V_48 , V_42 ) ;
F_308 ( & V_1 -> V_141 , V_506 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_1 -> V_149 ; V_6 ++ ) {
V_144 = & V_1 -> V_144 [ V_6 ] ;
if ( ! V_144 -> V_150 )
continue;
for ( V_142 = 0 ; V_142 < V_1 -> V_151 ; V_142 ++ ) {
V_106 = & V_144 -> V_106 [ V_142 ] ;
if ( V_106 -> V_3 )
F_76 ( V_1 ,
V_106 -> V_3 ) ;
}
}
}
}
static void
F_309 ( struct V_1 * V_1 , bool V_507 )
{
struct V_41 * V_42 = V_1 -> V_42 ;
V_42 -> V_508 = V_509 | V_122 |
V_510 | F_274 |
V_511 | V_512 | V_513 |
V_130 ;
V_42 -> V_514 = V_509 | V_515 |
V_510 | F_274 |
V_511 | V_512 ;
V_42 -> V_121 |= V_42 -> V_508 | V_516 ;
if ( V_507 )
V_42 -> V_121 |= V_515 ;
V_42 -> V_517 = V_1 -> V_518 ;
V_42 -> V_519 = V_1 -> V_518 + V_1 -> V_520 - 1 ;
V_42 -> V_521 = & V_522 ;
F_310 ( V_42 ) ;
}
static int
F_311 ( struct V_1 * V_1 ,
struct V_523 * V_524 , struct V_41 * V_42 )
{
unsigned long V_34 ;
F_312 ( V_42 , & V_524 -> V_19 ) ;
F_313 ( V_524 , V_42 ) ;
V_1 -> V_42 = V_42 ;
V_1 -> V_18 = V_524 ;
V_1 -> V_518 = F_314 ( V_524 , 0 ) ;
V_1 -> V_520 = F_315 ( V_524 , 0 ) ;
V_1 -> V_525 = F_316 ( V_1 -> V_518 , V_1 -> V_520 ) ;
if ( ! V_1 -> V_525 ) {
F_317 ( & V_524 -> V_19 , L_9 ) ;
return - V_221 ;
}
F_318 ( & V_524 -> V_19 , L_10 , V_1 -> V_525 ,
( unsigned long long ) V_1 -> V_520 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( ! V_526 )
V_1 -> V_226 = V_227 ;
V_1 -> V_226 |= V_268 ;
F_242 ( V_1 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_1 -> V_405 = ( V_1 -> V_146 * V_1 -> V_147 ) +
( V_1 -> V_149 * V_1 -> V_151 ) +
V_244 ;
V_1 -> V_293 = V_527 ;
V_1 -> V_326 = V_528 ;
V_1 -> V_297 = V_529 ;
V_1 -> V_306 = V_530 ;
sprintf ( V_1 -> V_531 , L_11 , V_232 , V_1 -> V_62 ) ;
V_1 -> V_186 = F_319 ( V_1 -> V_531 ) ;
if ( ! V_1 -> V_186 ) {
F_320 ( V_1 -> V_525 ) ;
return - V_221 ;
}
return 0 ;
}
static void
F_321 ( struct V_1 * V_1 )
{
if ( V_1 -> V_186 ) {
F_322 ( V_1 -> V_186 ) ;
F_323 ( V_1 -> V_186 ) ;
V_1 -> V_186 = NULL ;
}
if ( V_1 -> V_525 )
F_320 ( V_1 -> V_525 ) ;
}
static void
F_324 ( struct V_1 * V_1 )
{
F_325 ( & V_1 -> V_138 ) ;
F_326 ( & V_1 -> V_413 ) ;
}
static void
F_327 ( struct V_1 * V_1 )
{
F_328 ( & V_1 -> V_413 ) ;
}
static int
F_329 ( struct V_1 * V_1 ,
struct V_523 * V_524 , bool * V_507 )
{
int V_223 ;
V_223 = F_330 ( V_524 ) ;
if ( V_223 )
return V_223 ;
V_223 = F_331 ( V_524 , V_232 ) ;
if ( V_223 )
goto V_532;
if ( ! F_332 ( & V_524 -> V_19 , F_333 ( 64 ) ) ) {
* V_507 = true ;
} else {
V_223 = F_332 ( & V_524 -> V_19 , F_333 ( 32 ) ) ;
if ( V_223 )
goto V_533;
* V_507 = false ;
}
F_334 ( V_524 ) ;
return 0 ;
V_533:
F_335 ( V_524 ) ;
V_532:
F_336 ( V_524 ) ;
return V_223 ;
}
static void
F_337 ( struct V_523 * V_524 )
{
F_335 ( V_524 ) ;
F_336 ( V_524 ) ;
}
static int
F_338 ( struct V_523 * V_524 ,
const struct V_534 * V_535 )
{
bool V_507 ;
int V_223 ;
struct V_1 * V_1 ;
struct V_141 * V_141 ;
struct V_41 * V_42 ;
struct V_536 V_537 ;
unsigned long V_34 ;
F_261 ( & V_538 ) ;
if ( ! F_339 ( V_524 ) ) {
F_264 ( & V_538 ) ;
F_317 ( & V_524 -> V_19 , L_12 ) ;
return - V_352 ;
}
F_264 ( & V_538 ) ;
V_42 = F_340 ( sizeof( struct V_1 ) ) ;
if ( ! V_42 ) {
V_223 = - V_221 ;
return V_223 ;
}
V_1 = F_260 ( V_42 ) ;
F_324 ( V_1 ) ;
V_1 -> V_62 = F_341 ( & V_539 ) - 1 ;
F_261 ( & V_1 -> V_413 ) ;
V_507 = false ;
V_223 = F_329 ( V_1 , V_524 , & V_507 ) ;
if ( V_223 )
goto V_540;
V_223 = F_311 ( V_1 , V_524 , V_42 ) ;
if ( V_223 )
goto V_541;
F_309 ( V_1 , V_507 ) ;
F_101 ( V_42 ) ;
if ( V_542 )
F_342 ( V_1 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_343 ( & V_1 -> V_256 [ 0 ] ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_223 = F_252 ( V_1 , & V_1 -> V_256 [ 0 ] , V_543 ) ;
if ( V_223 )
goto V_544;
V_141 = & V_1 -> V_141 ;
V_537 . V_545 = F_344 ( V_1 -> V_18 -> V_546 ) ;
V_537 . V_547 = F_345 ( V_1 -> V_18 -> V_546 ) ;
V_537 . V_548 = V_1 -> V_18 -> V_549 ;
V_537 . V_550 = V_1 -> V_525 ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_346 ( V_141 , V_1 , & V_537 , & V_1 -> V_256 [ 0 ] ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_1 -> V_197 . V_196 = & V_141 -> V_197 ;
F_253 ( V_1 ) ;
V_223 = F_147 ( V_1 ) ;
if ( V_223 )
goto V_551;
F_173 ( & V_1 -> V_141 . V_263 . V_264 . V_552 , F_160 ,
( unsigned long ) V_1 ) ;
F_173 ( & V_1 -> V_141 . V_263 . V_264 . V_553 , F_162 ,
( unsigned long ) V_1 ) ;
F_173 ( & V_1 -> V_141 . V_263 . V_264 . V_554 , F_164 ,
( unsigned long ) V_1 ) ;
F_173 ( & V_1 -> V_141 . V_263 . V_264 . V_555 , F_166 ,
( unsigned long ) V_1 ) ;
V_223 = F_249 ( V_1 ) ;
if ( V_223 ) {
F_317 ( & V_524 -> V_19 , L_13 , V_223 ) ;
goto V_556;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
if ( F_347 ( V_141 , V_409 + 1 ) ||
F_348 ( V_141 , V_410 + 1 ) ) {
F_245 ( V_1 , F_289 ( V_141 ) -> V_292 - 1 ,
F_289 ( V_141 ) -> V_557 - 1 ) ;
if ( F_347 ( V_141 , V_409 + 1 ) ||
F_348 ( V_141 , V_410 + 1 ) )
V_223 = - V_558 ;
}
F_82 ( & V_1 -> V_138 , V_34 ) ;
if ( V_223 )
goto V_559;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_349 ( & V_1 -> V_141 , & V_1 -> V_560 [ 0 ] ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
V_223 = F_252 ( V_1 , & V_1 -> V_560 [ 0 ] , V_561 ) ;
if ( V_223 ) {
V_223 = - V_558 ;
goto V_559;
}
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_350 ( & V_1 -> V_141 , & V_1 -> V_560 [ 0 ] ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_114 ( & V_141 -> V_181 , V_1 -> V_154 ) ;
F_91 ( V_1 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_264 ( & V_1 -> V_413 ) ;
V_223 = F_351 ( V_42 ) ;
if ( V_223 ) {
F_317 ( & V_524 -> V_19 , L_14 ) ;
goto V_562;
}
F_90 ( V_563 , & V_1 -> V_140 ) ;
return 0 ;
V_556:
F_264 ( & V_1 -> V_413 ) ;
return 0 ;
V_562:
F_261 ( & V_1 -> V_413 ) ;
F_251 ( V_1 , & V_1 -> V_560 [ 0 ] , V_561 ) ;
V_559:
F_246 ( V_1 ) ;
F_177 ( & V_1 -> V_141 . V_263 . V_264 . V_552 ) ;
F_177 ( & V_1 -> V_141 . V_263 . V_264 . V_555 ) ;
F_177 ( & V_1 -> V_141 . V_263 . V_264 . V_553 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_352 ( V_141 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_144 ( V_1 ) ;
F_258 ( V_1 ) ;
V_551:
F_251 ( V_1 , & V_1 -> V_256 [ 0 ] , V_543 ) ;
V_544:
F_139 ( V_1 -> V_564 ) ;
F_353 ( V_1 ) ;
F_321 ( V_1 ) ;
V_541:
F_337 ( V_524 ) ;
V_540:
F_264 ( & V_1 -> V_413 ) ;
F_327 ( V_1 ) ;
F_354 ( V_42 ) ;
return V_223 ;
}
static void
F_355 ( struct V_523 * V_524 )
{
struct V_41 * V_42 = F_356 ( V_524 ) ;
struct V_1 * V_1 ;
struct V_141 * V_141 ;
unsigned long V_34 ;
if ( ! V_42 )
return;
V_1 = F_260 ( V_42 ) ;
V_141 = & V_1 -> V_141 ;
if ( F_176 ( V_563 , & V_1 -> V_140 ) )
F_357 ( V_42 ) ;
F_261 ( & V_1 -> V_413 ) ;
F_246 ( V_1 ) ;
F_177 ( & V_1 -> V_141 . V_263 . V_264 . V_552 ) ;
F_177 ( & V_1 -> V_141 . V_263 . V_264 . V_555 ) ;
F_177 ( & V_1 -> V_141 . V_263 . V_264 . V_553 ) ;
F_81 ( & V_1 -> V_138 , V_34 ) ;
F_352 ( V_141 ) ;
F_82 ( & V_1 -> V_138 , V_34 ) ;
F_251 ( V_1 , & V_1 -> V_560 [ 0 ] , V_561 ) ;
F_251 ( V_1 , & V_1 -> V_256 [ 0 ] , V_543 ) ;
F_144 ( V_1 ) ;
F_258 ( V_1 ) ;
F_337 ( V_524 ) ;
F_264 ( & V_1 -> V_413 ) ;
F_327 ( V_1 ) ;
F_139 ( V_1 -> V_564 ) ;
F_353 ( V_1 ) ;
F_321 ( V_1 ) ;
F_354 ( V_42 ) ;
}
static int T_11
F_358 ( void )
{
int V_223 ;
F_359 ( L_15 ,
V_565 ) ;
F_360 ( V_566 ) ;
V_223 = F_361 ( & V_567 ) ;
if ( V_223 < 0 ) {
F_362 ( L_16 , V_223 ) ;
return V_223 ;
}
return 0 ;
}
static void T_12
F_363 ( void )
{
F_364 ( & V_567 ) ;
F_365 ( V_568 ) ;
}
