static void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
V_3 -> V_4 = F_2 ( & V_2 -> V_4 ) ;
V_3 -> V_5 = F_2 ( & V_2 -> V_5 ) ;
V_3 -> V_6 = F_2 ( & V_2 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_3 , struct V_1 * V_2 )
{
F_4 ( V_3 -> V_4 , & V_2 -> V_4 ) ;
F_4 ( V_3 -> V_5 , & V_2 -> V_5 ) ;
F_4 ( V_3 -> V_6 , & V_2 -> V_6 ) ;
}
static inline struct V_7 * F_5 ( struct V_8 * V_9 )
{
struct V_7 * V_10 ;
F_6 ( & V_9 -> V_11 ) ;
if ( F_7 ( & V_9 -> V_12 ) ) {
V_10 = NULL ;
} else {
V_10 = F_8 ( V_9 -> V_12 . V_13 ,
struct V_7 ,
V_14 ) ;
F_9 ( & V_10 -> V_14 ) ;
}
F_10 ( & V_9 -> V_11 ) ;
return V_10 ;
}
static inline struct V_7 *
F_11 ( struct V_8 * V_9 )
{
struct V_7 * V_10 ;
if ( ! ( V_10 = F_12 ( sizeof( struct V_7 ) , V_15 ) ) )
return NULL ;
V_10 -> V_16 = F_12 ( V_9 -> V_17 , V_15 ) ;
if ( ! V_10 -> V_16 ) {
F_13 ( V_10 ) ;
return NULL ;
}
V_10 -> V_16 -> V_18 = 0 ;
V_10 -> V_16 -> V_19 = V_20 ;
V_10 -> V_16 -> V_21 = V_9 -> V_22 ;
V_10 -> V_16 -> V_23 = sizeof( struct V_24 ) ;
V_10 -> V_16 -> V_25 = 0 ;
V_10 -> V_16 -> V_26 = 0 ;
V_10 -> V_27 = ( unsigned char * ) V_10 -> V_16 + sizeof( struct V_24 ) ;
V_10 -> V_28 = ( unsigned char * ) V_10 -> V_16 + V_9 -> V_17 ;
V_10 -> V_29 = V_30 ;
return V_10 ;
}
static inline void F_14 ( struct V_7 * V_10 )
{
F_13 ( V_10 -> V_16 ) ;
F_13 ( V_10 ) ;
}
static inline void F_15 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = V_9 -> V_31 ;
F_16 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_32 & V_33 )
F_17 ( & V_10 -> V_14 , & V_9 -> V_12 ) ;
else
F_14 ( V_10 ) ;
F_18 ( & V_9 -> V_11 ) ;
}
static inline struct V_7 *
F_19 ( struct V_8 * V_9 , unsigned long time )
{
struct V_7 * V_10 ;
F_6 ( & V_9 -> V_34 ) ;
if ( V_9 -> V_31 &&
F_20 ( V_30 - V_9 -> V_31 -> V_29 , time ) ) {
V_10 = V_9 -> V_31 ;
V_9 -> V_31 = NULL ;
} else
V_10 = NULL ;
F_10 ( & V_9 -> V_34 ) ;
return V_10 ;
}
void F_21 ( struct V_35 * V_35 , int V_36 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
if ( ! ( V_9 -> V_32 & V_33 ) )
return;
if ( V_36 == F_23 ( V_9 ) || ! V_9 -> V_31 )
return;
F_6 ( & V_9 -> V_34 ) ;
if ( V_9 -> V_31 -> V_16 -> V_23 <= sizeof( struct V_24 ) ) {
F_13 ( V_9 -> V_31 ) ;
V_9 -> V_31 = NULL ;
} else {
F_6 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_32 & V_33 )
F_17 ( & V_9 -> V_31 -> V_14 ,
& V_9 -> V_12 ) ;
else
F_14 ( V_9 -> V_31 ) ;
F_10 ( & V_9 -> V_11 ) ;
}
F_10 ( & V_9 -> V_34 ) ;
}
static inline struct V_7 *
F_24 ( struct V_8 * V_9 )
{
struct V_7 * V_10 ;
struct V_37 * V_16 ;
if ( ! ( V_10 = F_12 ( sizeof( struct V_7 ) , V_15 ) ) )
return NULL ;
V_10 -> V_16 = F_12 ( V_9 -> V_17 , V_15 ) ;
if ( ! V_10 -> V_16 ) {
F_13 ( V_10 ) ;
return NULL ;
}
V_16 = (struct V_37 * ) V_10 -> V_16 ;
V_16 -> V_25 = 0 ;
V_16 -> V_21 = V_9 -> V_22 ;
V_16 -> V_23 = sizeof( struct V_37 ) ;
V_10 -> V_27 = ( unsigned char * ) V_16 + sizeof( struct V_37 ) ;
V_10 -> V_28 = ( unsigned char * ) V_16 + V_9 -> V_17 ;
V_10 -> V_29 = V_30 ;
return V_10 ;
}
void F_25 ( struct V_35 * V_35 , struct V_38 * V_39 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
struct V_37 * V_40 ;
struct F_25 * V_41 ;
int V_42 ;
if ( F_26 ( V_39 -> V_43 != V_44 ) )
return;
if ( V_39 -> V_45 & V_46 )
return;
F_16 ( & V_9 -> V_34 ) ;
if ( ! V_9 -> V_31 ) {
V_9 -> V_31 =
F_24 ( V_9 ) ;
if ( ! V_9 -> V_31 ) {
F_18 ( & V_9 -> V_34 ) ;
F_27 ( L_1 ) ;
return;
}
}
V_42 = ( V_39 -> V_45 & V_47 ) ? V_48 :
V_49 ;
V_40 = (struct V_37 * ) V_9 -> V_31 -> V_16 ;
V_41 = (struct F_25 * ) V_9 -> V_31 -> V_27 ;
V_41 -> V_18 = 0 ;
V_41 -> V_50 = V_39 -> V_50 ;
V_41 -> V_51 = V_39 -> V_51 ;
V_41 -> V_52 = V_39 -> V_52 ;
V_41 -> V_53 = V_39 -> V_53 ;
V_41 -> V_54 = V_39 -> V_54 . V_55 ;
V_41 -> V_56 = V_39 -> V_56 . V_55 ;
V_41 -> V_57 = V_39 -> V_57 . V_55 ;
V_41 -> V_45 = F_28 ( V_39 -> V_45 & ~ V_58 ) ;
V_41 -> V_59 = F_28 ( V_39 -> V_59 ) ;
if ( V_39 -> V_45 & V_47 ) {
struct V_60 * V_61 =
(struct V_60 * ) & V_41 [ 1 ] ;
memcpy ( V_61 , & V_39 -> V_62 , sizeof( * V_61 ) ) ;
}
V_40 -> V_25 ++ ;
V_40 -> V_23 += V_42 ;
V_9 -> V_31 -> V_27 += V_42 ;
if ( V_9 -> V_31 -> V_27 + V_48 > V_9 -> V_31 -> V_28 ) {
F_15 ( V_9 ) ;
V_9 -> V_31 = NULL ;
}
F_18 ( & V_9 -> V_34 ) ;
if ( V_39 -> V_63 )
F_29 ( V_35 , V_39 -> V_63 ) ;
}
void F_29 ( struct V_35 * V_35 , struct V_38 * V_39 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
struct V_24 * V_40 ;
union F_29 * V_41 ;
T_1 * V_64 ;
unsigned int V_42 , V_65 , V_66 ;
if ( F_23 ( V_9 ) == 0 ) {
F_25 ( V_35 , V_39 ) ;
return;
}
if ( V_39 -> V_45 & V_46 )
goto V_63;
V_67:
V_65 = 0 ;
if ( V_39 -> V_68 ) {
if ( ! V_39 -> V_69 || ! V_39 -> V_70 ) {
F_30 ( L_2 ) ;
return;
}
V_65 = F_31 ( V_39 -> V_71 -> V_72 , V_73 ) ;
}
F_16 ( & V_9 -> V_34 ) ;
#ifdef F_32
if ( V_39 -> V_43 == V_74 )
V_42 = sizeof( struct V_75 ) ;
else
#endif
V_42 = sizeof( struct V_76 ) ;
if ( V_39 -> V_45 & V_47 )
V_42 += sizeof( struct V_60 ) + 2 ;
if ( V_39 -> V_68 )
V_42 += V_39 -> V_68 + 2 ;
if ( V_65 )
V_42 += V_65 + 2 ;
V_66 = 0 ;
if ( V_9 -> V_31 ) {
V_66 = ( 4 - ( V_77 ) V_9 -> V_31 -> V_27 ) & 3 ;
if ( V_9 -> V_31 -> V_27 + V_42 + V_66 > V_9 -> V_31 -> V_28 ) {
F_15 ( V_9 ) ;
V_9 -> V_31 = NULL ;
V_66 = 0 ;
}
}
if ( ! V_9 -> V_31 ) {
V_9 -> V_31 = F_11 ( V_9 ) ;
if ( ! V_9 -> V_31 ) {
F_18 ( & V_9 -> V_34 ) ;
F_27 ( L_1 ) ;
return;
}
}
V_40 = V_9 -> V_31 -> V_16 ;
V_64 = V_9 -> V_31 -> V_27 ;
V_9 -> V_31 -> V_27 += V_66 + V_42 ;
V_40 -> V_23 += V_66 + V_42 ;
while ( V_66 -- )
* ( V_64 ++ ) = 0 ;
V_41 = (union F_29 * ) V_64 ;
V_41 -> V_78 . type = ( V_39 -> V_43 == V_74 ? V_79 : 0 ) ;
V_41 -> V_78 . V_80 = F_28 ( V_42 & V_81 ) ;
V_41 -> V_78 . V_45 = F_33 ( V_39 -> V_45 & ~ V_58 ) ;
V_41 -> V_78 . V_59 = F_28 ( V_39 -> V_59 ) ;
V_41 -> V_78 . V_50 = V_39 -> V_50 ;
V_41 -> V_78 . V_51 = V_39 -> V_51 ;
V_41 -> V_78 . V_52 = V_39 -> V_52 ;
V_41 -> V_78 . V_53 = V_39 -> V_53 ;
V_41 -> V_78 . V_82 = F_33 ( V_39 -> V_82 ) ;
V_41 -> V_78 . V_83 = F_33 ( V_39 -> V_83 / V_84 ) ;
V_40 -> V_25 ++ ;
#ifdef F_32
if ( V_39 -> V_43 == V_74 ) {
V_64 += sizeof( struct V_75 ) ;
V_41 -> V_85 . V_54 = V_39 -> V_54 . V_86 ;
V_41 -> V_85 . V_56 = V_39 -> V_56 . V_86 ;
V_41 -> V_85 . V_57 = V_39 -> V_57 . V_86 ;
} else
#endif
{
V_64 += sizeof( struct V_76 ) ;
V_41 -> V_78 . V_54 = V_39 -> V_54 . V_55 ;
V_41 -> V_78 . V_56 = V_39 -> V_56 . V_55 ;
V_41 -> V_78 . V_57 = V_39 -> V_57 . V_55 ;
}
if ( V_39 -> V_45 & V_47 ) {
* ( V_64 ++ ) = V_87 ;
* ( V_64 ++ ) = sizeof( struct V_60 ) ;
F_3 ( (struct V_1 * ) V_64 , & V_39 -> V_62 ) ;
V_64 += sizeof( struct V_1 ) ;
F_3 ( (struct V_1 * ) V_64 , & V_39 -> V_88 ) ;
V_64 += sizeof( struct V_1 ) ;
}
if ( V_39 -> V_68 && V_39 -> V_69 ) {
* ( V_64 ++ ) = V_89 ;
* ( V_64 ++ ) = V_39 -> V_68 ;
memcpy ( V_64 , V_39 -> V_69 , V_39 -> V_68 ) ;
V_64 += V_39 -> V_68 ;
if ( V_65 ) {
* ( V_64 ++ ) = V_90 ;
* ( V_64 ++ ) = V_65 ;
memcpy ( V_64 , V_39 -> V_71 -> V_72 , V_65 ) ;
V_64 += V_65 ;
}
}
F_18 ( & V_9 -> V_34 ) ;
V_63:
V_39 = V_39 -> V_63 ;
if ( ! V_39 )
return;
if ( V_39 -> V_45 & V_91 ) {
int V_92 = F_34 ( 1 , & V_39 -> V_93 ) ;
if ( V_92 % F_35 ( V_9 ) != 1 )
return;
}
goto V_67;
}
static inline int
F_36 ( struct V_35 * V_35 , int V_43 , union F_29 * V_94 ,
struct V_95 * V_64 ,
T_1 * V_69 , unsigned int V_68 ,
T_1 * V_96 , unsigned int V_65 )
{
#ifdef F_32
if ( V_43 == V_74 )
F_37 ( V_35 , V_43 , V_94 -> V_85 . V_50 ,
( const union V_97 * ) & V_94 -> V_85 . V_54 ,
V_94 -> V_85 . V_51 ,
( const union V_97 * ) & V_94 -> V_85 . V_56 ,
V_94 -> V_85 . V_52 , V_64 ) ;
else
#endif
F_37 ( V_35 , V_43 , V_94 -> V_78 . V_50 ,
( const union V_97 * ) & V_94 -> V_78 . V_54 ,
V_94 -> V_78 . V_51 ,
( const union V_97 * ) & V_94 -> V_78 . V_56 ,
V_94 -> V_78 . V_52 , V_64 ) ;
if ( V_68 ) {
if ( V_65 ) {
char V_98 [ V_73 + 1 ] ;
memcpy ( V_98 , V_96 , V_65 ) ;
V_98 [ V_65 ] = 0 ;
V_64 -> V_71 = F_38 ( V_98 ) ;
if ( ! V_64 -> V_71 ) {
F_39 ( 3 , L_3 ,
V_98 ) ;
return 1 ;
}
} else {
F_30 ( L_4 ) ;
return 1 ;
}
V_64 -> V_69 = F_40 ( V_69 , V_68 , V_15 ) ;
if ( ! V_64 -> V_69 ) {
if ( V_64 -> V_71 -> V_99 )
F_41 ( V_64 -> V_71 -> V_99 ) ;
return - V_100 ;
}
V_64 -> V_68 = V_68 ;
}
return 0 ;
}
static void F_42 ( struct V_35 * V_35 , struct V_95 * V_101 ,
unsigned int V_45 , unsigned int V_59 ,
unsigned int V_50 , unsigned int type ,
const union V_97 * V_57 , T_2 V_53 ,
unsigned long V_83 , T_3 V_82 ,
struct V_60 * V_61 )
{
struct V_102 * V_70 ;
struct V_38 * V_39 ;
struct V_8 * V_9 = F_22 ( V_35 ) ;
if ( ! ( V_45 & V_91 ) )
V_39 = F_43 ( V_101 ) ;
else
V_39 = F_44 ( V_101 ) ;
if ( V_39 && V_101 -> V_69 )
F_13 ( V_101 -> V_69 ) ;
if ( ! V_39 ) {
V_70 = F_45 ( V_35 , type , V_57 , V_53 , V_101 -> V_56 ,
V_101 -> V_52 , V_50 , V_82 , V_45 ) ;
if ( V_50 == V_103 ) {
if ( V_59 != V_104 )
V_45 |= V_105 ;
else
V_45 &= ~ V_105 ;
} else if ( V_50 == V_106 ) {
if ( V_59 != V_107 )
V_45 |= V_105 ;
else
V_45 &= ~ V_105 ;
}
V_39 = F_46 ( V_101 , V_57 , V_53 , V_45 , V_70 , V_82 ) ;
if ( V_70 )
F_47 ( & V_70 -> V_108 ) ;
if ( ! V_39 ) {
if ( V_101 -> V_69 )
F_13 ( V_101 -> V_69 ) ;
F_39 ( 2 , L_5 ) ;
return;
}
} else if ( ! V_39 -> V_70 ) {
V_70 = F_48 ( V_39 ) ;
if ( V_70 )
F_47 ( & V_70 -> V_108 ) ;
} else if ( ( V_39 -> V_70 ) && ( V_39 -> V_50 == V_103 ) &&
( V_39 -> V_59 != V_59 ) ) {
V_70 = V_39 -> V_70 ;
if ( ! ( V_39 -> V_45 & V_105 ) &&
( V_59 != V_104 ) ) {
F_47 ( & V_70 -> V_109 ) ;
F_49 ( & V_70 -> V_110 ) ;
V_39 -> V_45 |= V_105 ;
} else if ( ( V_39 -> V_45 & V_105 ) &&
( V_59 == V_104 ) ) {
F_49 ( & V_70 -> V_109 ) ;
F_47 ( & V_70 -> V_110 ) ;
V_39 -> V_45 &= ~ V_105 ;
}
} else if ( ( V_39 -> V_70 ) && ( V_39 -> V_50 == V_106 ) &&
( V_39 -> V_59 != V_59 ) ) {
V_70 = V_39 -> V_70 ;
if ( ! ( V_39 -> V_45 & V_105 ) &&
( V_59 != V_107 ) ) {
F_47 ( & V_70 -> V_109 ) ;
F_49 ( & V_70 -> V_110 ) ;
V_39 -> V_45 &= ~ V_105 ;
}
}
if ( V_61 )
memcpy ( & V_39 -> V_62 , V_61 , sizeof( * V_61 ) ) ;
F_50 ( & V_39 -> V_93 , F_51 ( V_9 ) ) ;
V_39 -> V_59 = V_59 ;
V_39 -> V_111 = V_39 -> V_59 ;
if ( V_83 ) {
if ( V_83 > V_112 / V_84 )
V_83 = V_112 / V_84 ;
V_39 -> V_83 = V_83 * V_84 ;
} else {
struct V_113 * V_114 ;
V_114 = F_52 ( V_35 , V_50 ) ;
if ( ! ( V_45 & V_91 ) && V_114 && V_114 -> V_115 )
V_39 -> V_83 = V_114 -> V_115 [ V_59 ] ;
else
V_39 -> V_83 = ( 3 * 60 * V_84 ) ;
}
F_53 ( V_39 ) ;
}
static void F_54 ( struct V_35 * V_35 , const char * V_116 ,
const V_77 V_117 )
{
struct V_37 * V_40 = (struct V_37 * ) V_116 ;
struct F_25 * V_41 ;
struct V_60 * V_61 ;
struct V_118 * V_119 ;
struct V_95 V_101 ;
char * V_64 ;
int V_120 ;
V_64 = ( char * ) V_116 + sizeof( struct V_37 ) ;
for ( V_120 = 0 ; V_120 < V_40 -> V_25 ; V_120 ++ ) {
unsigned V_45 , V_59 ;
if ( V_64 + V_49 > V_116 + V_117 ) {
F_30 ( L_6 ) ;
return;
}
V_41 = (struct F_25 * ) V_64 ;
V_45 = F_55 ( V_41 -> V_45 ) | V_121 ;
V_45 &= ~ V_58 ;
if ( V_45 & V_47 ) {
V_61 = (struct V_60 * ) & V_41 [ 1 ] ;
V_64 += V_48 ;
if ( V_64 > V_116 + V_117 ) {
F_30 ( L_7 ) ;
return;
}
} else {
V_61 = NULL ;
V_64 += V_49 ;
}
V_59 = F_55 ( V_41 -> V_59 ) ;
if ( ! ( V_45 & V_91 ) ) {
V_119 = F_56 ( V_41 -> V_50 ) ;
if ( ! V_119 ) {
F_39 ( 2 , L_8 ,
V_41 -> V_50 ) ;
continue;
}
if ( V_59 >= V_119 -> V_122 ) {
F_39 ( 2 , L_9 ,
V_119 -> V_72 , V_59 ) ;
continue;
}
} else {
if ( V_59 > 0 ) {
F_39 ( 2 , L_10 ,
V_59 ) ;
V_59 = 0 ;
}
}
F_37 ( V_35 , V_44 , V_41 -> V_50 ,
( const union V_97 * ) & V_41 -> V_54 ,
V_41 -> V_51 ,
( const union V_97 * ) & V_41 -> V_56 ,
V_41 -> V_52 , & V_101 ) ;
F_42 ( V_35 , & V_101 , V_45 , V_59 , V_41 -> V_50 , V_44 ,
(union V_97 * ) & V_41 -> V_57 , V_41 -> V_53 ,
0 , 0 , V_61 ) ;
}
}
static inline int F_57 ( T_1 * V_64 , unsigned int V_123 ,
T_3 * V_124 ,
struct V_60 * V_61 )
{
struct V_60 * V_125 ;
V_125 = (struct V_60 * ) V_64 ;
if ( V_123 != sizeof( struct V_60 ) ) {
F_39 ( 2 , L_11 ) ;
return - V_126 ;
}
if ( * V_124 & V_127 ) {
F_39 ( 2 , L_12 ) ;
return - V_126 ;
}
F_1 ( & V_125 -> V_62 , & V_61 -> V_62 ) ;
F_1 ( & V_125 -> V_88 , & V_61 -> V_88 ) ;
* V_124 |= V_127 ;
return 0 ;
}
static int F_58 ( T_1 * V_64 , unsigned int V_123 , unsigned int * V_128 ,
T_1 * * V_129 , unsigned int V_130 ,
T_3 * V_124 , T_3 V_131 )
{
if ( V_123 > V_130 ) {
F_39 ( 2 , L_13 , V_130 ) ;
return - V_126 ;
}
if ( * V_124 & V_131 ) {
F_39 ( 2 , L_14 , V_131 ) ;
return - V_126 ;
}
* V_128 = V_123 ;
* V_129 = V_64 ;
* V_124 |= V_131 ;
return 0 ;
}
static inline int F_59 ( struct V_35 * V_35 , T_1 * V_64 , T_1 * V_132 )
{
struct V_60 V_61 ;
union F_29 * V_41 ;
struct V_118 * V_119 ;
struct V_95 V_101 ;
T_3 V_45 ;
unsigned int V_43 , V_59 , V_68 = 0 , V_65 = 0 ;
T_1 * V_69 = NULL , * V_96 = NULL ;
T_3 V_124 = 0 ;
int V_133 = 0 ;
V_41 = (union F_29 * ) V_64 ;
if ( V_41 -> V_85 . type & V_79 ) {
#ifdef F_32
V_43 = V_74 ;
V_64 += sizeof( struct V_75 ) ;
#else
F_39 ( 3 , L_15 ) ;
V_133 = 10 ;
goto V_134;
#endif
} else if ( ! V_41 -> V_78 . type ) {
V_43 = V_44 ;
V_64 += sizeof( struct V_76 ) ;
} else {
return - 10 ;
}
if ( V_64 > V_132 )
return - 20 ;
while ( V_64 < V_132 ) {
int V_135 ;
int V_123 ;
if ( V_64 + 2 > V_132 )
return - 30 ;
V_135 = * ( V_64 ++ ) ;
V_123 = * ( V_64 ++ ) ;
if ( ! V_123 || ( ( V_64 + V_123 ) > V_132 ) )
return - 40 ;
switch ( V_135 & ~ V_136 ) {
case V_87 :
if ( F_57 ( V_64 , V_123 , & V_124 , & V_61 ) )
return - 50 ;
break;
case V_89 :
if ( F_58 ( V_64 , V_123 , & V_68 , & V_69 ,
V_137 , & V_124 ,
V_138 ) )
return - 60 ;
break;
case V_90 :
if ( F_58 ( V_64 , V_123 , & V_65 , & V_96 ,
V_73 , & V_124 ,
V_139 ) )
return - 70 ;
break;
default:
if ( ! ( V_135 & V_136 ) ) {
F_39 ( 3 , L_16 ,
V_135 & ~ V_136 ) ;
V_133 = 20 ;
goto V_134;
}
}
V_64 += V_123 ;
}
V_45 = F_60 ( V_41 -> V_78 . V_45 ) & V_140 ;
V_45 |= V_121 ;
V_59 = F_55 ( V_41 -> V_78 . V_59 ) ;
if ( ! ( V_45 & V_91 ) ) {
V_119 = F_56 ( V_41 -> V_78 . V_50 ) ;
if ( ! V_119 ) {
F_39 ( 3 , L_17 ,
V_41 -> V_78 . V_50 ) ;
V_133 = 30 ;
goto V_134;
}
if ( V_59 >= V_119 -> V_122 ) {
F_39 ( 3 , L_18 ,
V_119 -> V_72 , V_59 ) ;
V_133 = 40 ;
goto V_134;
}
} else {
if ( V_59 > 0 ) {
F_39 ( 3 , L_19 ,
V_59 ) ;
V_59 = 0 ;
}
}
if ( F_36 ( V_35 , V_43 , V_41 , & V_101 , V_69 ,
V_68 , V_96 , V_65 ) ) {
V_133 = 50 ;
goto V_134;
}
if ( V_43 == V_44 )
F_42 ( V_35 , & V_101 , V_45 , V_59 , V_41 -> V_78 . V_50 , V_43 ,
(union V_97 * ) & V_41 -> V_78 . V_57 , V_41 -> V_78 . V_53 ,
F_60 ( V_41 -> V_78 . V_83 ) , F_60 ( V_41 -> V_78 . V_82 ) ,
( V_124 & V_127 ? & V_61 : NULL )
) ;
#ifdef F_32
else
F_42 ( V_35 , & V_101 , V_45 , V_59 , V_41 -> V_85 . V_50 , V_43 ,
(union V_97 * ) & V_41 -> V_85 . V_57 , V_41 -> V_85 . V_53 ,
F_60 ( V_41 -> V_85 . V_83 ) , F_60 ( V_41 -> V_85 . V_82 ) ,
( V_124 & V_127 ? & V_61 : NULL )
) ;
#endif
return 0 ;
V_134:
F_39 ( 2 , L_20 , V_133 ) ;
return V_133 ;
}
static void F_61 ( struct V_35 * V_35 , T_1 * V_116 ,
const V_77 V_117 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
struct V_24 * V_141 = (struct V_24 * ) V_116 ;
T_1 * V_64 , * V_132 ;
int V_120 , V_25 ;
if ( V_117 < sizeof( struct V_37 ) ) {
F_39 ( 2 , L_21 ) ;
return;
}
V_141 -> V_23 = F_55 ( V_141 -> V_23 ) ;
if ( V_117 != V_141 -> V_23 ) {
F_39 ( 2 , L_22 ) ;
return;
}
if ( V_9 -> V_142 != 0 && V_141 -> V_21 != V_9 -> V_142 ) {
F_39 ( 7 , L_23 , V_141 -> V_21 ) ;
return;
}
if ( ( V_141 -> V_19 == V_20 ) && ( V_141 -> V_18 == 0 )
&& ( V_141 -> V_26 == 0 ) ) {
V_132 = V_116 + sizeof( struct V_24 ) ;
V_25 = V_141 -> V_25 ;
for ( V_120 = 0 ; V_120 < V_25 ; V_120 ++ ) {
union F_29 * V_41 ;
unsigned V_23 ;
int V_133 ;
V_64 = V_132 ;
if ( V_64 + sizeof( V_41 -> V_78 ) > V_116 + V_117 ) {
F_30 ( L_24 ) ;
return;
}
V_41 = (union F_29 * ) V_64 ;
V_23 = F_55 ( V_41 -> V_78 . V_80 ) & V_81 ;
V_132 = V_64 + V_23 ;
if ( V_132 > V_116 + V_117 ) {
F_30 ( L_25 ) ;
return;
}
if ( F_55 ( V_41 -> V_78 . V_80 ) >> V_143 ) {
F_30 ( L_26 ,
F_55 ( V_41 -> V_78 . V_80 ) >> V_143 ) ;
return;
}
V_133 = F_59 ( V_35 , V_64 , V_132 ) ;
if ( V_133 < 0 ) {
F_30 ( L_27 ,
V_133 ) ;
return;
}
V_132 = V_64 + ( ( V_23 + 3 ) & ~ 3 ) ;
}
} else {
F_54 ( V_35 , V_116 , V_117 ) ;
return;
}
}
static void F_62 ( struct V_144 * V_145 , T_4 V_146 )
{
struct V_147 * V_148 = F_63 ( V_145 ) ;
F_64 ( V_145 ) ;
V_148 -> V_149 = V_146 ? 1 : 0 ;
F_65 ( V_145 ) ;
}
static void F_66 ( struct V_144 * V_145 , T_4 V_150 )
{
struct V_147 * V_148 = F_63 ( V_145 ) ;
F_64 ( V_145 ) ;
V_148 -> V_151 = V_150 ;
F_65 ( V_145 ) ;
}
static int F_67 ( struct V_144 * V_145 , char * V_152 )
{
struct V_153 * V_154 ;
struct V_147 * V_148 = F_63 ( V_145 ) ;
struct V_35 * V_35 = F_68 ( V_145 ) ;
V_154 = F_69 ( V_35 , V_152 ) ;
if ( ! V_154 )
return - V_155 ;
if ( V_145 -> V_156 && V_154 -> V_157 != V_145 -> V_156 )
return - V_126 ;
F_64 ( V_145 ) ;
V_148 -> V_158 = V_154 -> V_157 ;
F_65 ( V_145 ) ;
return 0 ;
}
static int F_70 ( struct V_35 * V_35 , int V_32 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
struct V_153 * V_154 ;
int V_159 ;
if ( V_32 == V_33 ) {
V_154 = F_69 ( V_35 , V_9 -> V_160 ) ;
if ( ! V_154 )
return - V_155 ;
V_159 = ( V_154 -> V_161 - sizeof( struct V_162 ) -
sizeof( struct V_163 ) -
V_164 - 20 ) / V_49 ;
V_9 -> V_17 = V_164 +
V_49 * F_71 ( V_159 , V_165 ) ;
F_39 ( 7 , L_28
L_29 , V_9 -> V_17 ) ;
} else if ( V_32 == V_166 ) {
V_154 = F_69 ( V_35 , V_9 -> V_167 ) ;
if ( ! V_154 )
return - V_155 ;
V_9 -> V_168 = V_154 -> V_161 -
sizeof( struct V_162 ) - sizeof( struct V_163 ) ;
F_39 ( 7 , L_30
L_29 , V_9 -> V_168 ) ;
}
return 0 ;
}
static int
F_72 ( struct V_144 * V_145 , struct V_169 * V_170 , char * V_152 )
{
struct V_35 * V_35 = F_68 ( V_145 ) ;
struct V_171 V_172 ;
struct V_153 * V_154 ;
int V_173 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
memcpy ( & V_172 . V_174 , V_170 , sizeof( struct V_169 ) ) ;
V_154 = F_69 ( V_35 , V_152 ) ;
if ( ! V_154 )
return - V_155 ;
if ( V_145 -> V_156 && V_154 -> V_157 != V_145 -> V_156 )
return - V_126 ;
V_172 . V_175 = V_154 -> V_157 ;
F_64 ( V_145 ) ;
V_173 = F_73 ( V_145 , & V_172 ) ;
F_65 ( V_145 ) ;
return V_173 ;
}
static int F_74 ( struct V_176 * V_144 , char * V_152 )
{
struct V_35 * V_35 = F_68 ( V_144 -> V_145 ) ;
struct V_153 * V_154 ;
T_5 V_170 ;
struct V_177 sin ;
V_154 = F_69 ( V_35 , V_152 ) ;
if ( ! V_154 )
return - V_155 ;
V_170 = F_75 ( V_154 , 0 , V_178 ) ;
if ( ! V_170 )
F_27 ( L_31
L_32 ) ;
F_39 ( 7 , L_33 ,
V_152 , & V_170 ) ;
sin . V_179 = V_44 ;
sin . V_180 . V_181 = V_170 ;
sin . V_182 = 0 ;
return V_144 -> V_183 -> V_184 ( V_144 , (struct V_185 * ) & sin , sizeof( sin ) ) ;
}
static struct V_176 * F_76 ( struct V_35 * V_35 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
struct V_176 * V_144 ;
int V_186 ;
V_186 = F_77 ( V_187 , V_188 , V_189 , & V_144 ) ;
if ( V_186 < 0 ) {
F_27 ( L_34 ) ;
return F_78 ( V_186 ) ;
}
F_79 ( V_144 -> V_145 , V_35 ) ;
V_186 = F_67 ( V_144 -> V_145 , V_9 -> V_160 ) ;
if ( V_186 < 0 ) {
F_27 ( L_35 ) ;
goto error;
}
F_62 ( V_144 -> V_145 , 0 ) ;
F_66 ( V_144 -> V_145 , 1 ) ;
V_186 = F_74 ( V_144 , V_9 -> V_160 ) ;
if ( V_186 < 0 ) {
F_27 ( L_36 ) ;
goto error;
}
V_186 = V_144 -> V_183 -> V_190 ( V_144 , (struct V_185 * ) & V_191 ,
sizeof( struct V_185 ) , 0 ) ;
if ( V_186 < 0 ) {
F_27 ( L_37 ) ;
goto error;
}
return V_144 ;
error:
F_80 ( V_144 -> V_145 ) ;
return F_78 ( V_186 ) ;
}
static struct V_176 * F_81 ( struct V_35 * V_35 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
struct V_176 * V_144 ;
int V_186 ;
V_186 = F_77 ( V_187 , V_188 , V_189 , & V_144 ) ;
if ( V_186 < 0 ) {
F_27 ( L_34 ) ;
return F_78 ( V_186 ) ;
}
F_79 ( V_144 -> V_145 , V_35 ) ;
V_144 -> V_145 -> V_192 = 1 ;
V_186 = V_144 -> V_183 -> V_184 ( V_144 , (struct V_185 * ) & V_191 ,
sizeof( struct V_185 ) ) ;
if ( V_186 < 0 ) {
F_27 ( L_38 ) ;
goto error;
}
V_186 = F_72 ( V_144 -> V_145 ,
(struct V_169 * ) & V_191 . V_180 ,
V_9 -> V_167 ) ;
if ( V_186 < 0 ) {
F_27 ( L_39 ) ;
goto error;
}
return V_144 ;
error:
F_80 ( V_144 -> V_145 ) ;
return F_78 ( V_186 ) ;
}
static int
F_82 ( struct V_176 * V_144 , const char * V_116 , const V_77 V_193 )
{
struct V_194 V_195 = { . V_196 = V_197 | V_198 } ;
struct V_199 V_200 ;
int V_42 ;
F_83 ( 7 ) ;
V_200 . V_201 = ( void * ) V_116 ;
V_200 . V_202 = V_193 ;
V_42 = F_84 ( V_144 , & V_195 , & V_200 , 1 , ( V_77 ) ( V_193 ) ) ;
F_85 ( 7 ) ;
return V_42 ;
}
static void
F_86 ( struct V_176 * V_144 , struct V_24 * V_195 )
{
int V_203 ;
V_203 = V_195 -> V_23 ;
V_195 -> V_23 = F_28 ( V_195 -> V_23 ) ;
if ( F_82 ( V_144 , ( char * ) V_195 , V_203 ) != V_203 )
F_27 ( L_40 ) ;
}
static int
F_87 ( struct V_176 * V_144 , char * V_116 , const V_77 V_117 )
{
struct V_194 V_195 = { NULL ,} ;
struct V_199 V_200 ;
int V_42 ;
F_83 ( 7 ) ;
V_200 . V_201 = V_116 ;
V_200 . V_202 = ( V_77 ) V_117 ;
V_42 = F_88 ( V_144 , & V_195 , & V_200 , 1 , V_117 , 0 ) ;
if ( V_42 < 0 )
return - 1 ;
F_85 ( 7 ) ;
return V_42 ;
}
static int F_89 ( void * V_129 )
{
struct V_204 * V_205 = V_129 ;
struct V_8 * V_9 = F_22 ( V_205 -> V_35 ) ;
struct V_7 * V_10 ;
F_90 ( L_41
L_42 ,
V_9 -> V_160 , V_9 -> V_22 ) ;
while ( ! F_91 () ) {
while ( ( V_10 = F_5 ( V_9 ) ) ) {
F_86 ( V_205 -> V_144 , V_10 -> V_16 ) ;
F_14 ( V_10 ) ;
}
V_10 = F_19 ( V_9 , 2 * V_84 ) ;
if ( V_10 ) {
F_86 ( V_205 -> V_144 , V_10 -> V_16 ) ;
F_14 ( V_10 ) ;
}
F_92 ( V_84 ) ;
}
while ( ( V_10 = F_5 ( V_9 ) ) )
F_14 ( V_10 ) ;
V_10 = F_19 ( V_9 , 0 ) ;
if ( V_10 )
F_14 ( V_10 ) ;
F_80 ( V_205 -> V_144 -> V_145 ) ;
F_13 ( V_205 ) ;
return 0 ;
}
static int F_93 ( void * V_129 )
{
struct V_204 * V_205 = V_129 ;
struct V_8 * V_9 = F_22 ( V_205 -> V_35 ) ;
int V_42 ;
F_90 ( L_43
L_42 ,
V_9 -> V_167 , V_9 -> V_142 ) ;
while ( ! F_91 () ) {
F_94 ( * F_95 ( V_205 -> V_144 -> V_145 ) ,
! F_96 ( & V_205 -> V_144 -> V_145 -> V_206 )
|| F_91 () ) ;
while ( ! F_96 ( & ( V_205 -> V_144 -> V_145 -> V_206 ) ) ) {
V_42 = F_87 ( V_205 -> V_144 , V_205 -> V_207 ,
V_9 -> V_168 ) ;
if ( V_42 <= 0 ) {
F_27 ( L_44 ) ;
break;
}
F_97 () ;
F_61 ( V_205 -> V_35 , V_205 -> V_207 , V_42 ) ;
F_98 () ;
}
}
F_80 ( V_205 -> V_144 -> V_145 ) ;
F_13 ( V_205 -> V_207 ) ;
F_13 ( V_205 ) ;
return 0 ;
}
int F_99 ( struct V_35 * V_35 , int V_59 , char * V_208 , T_1 V_21 )
{
struct V_204 * V_205 ;
struct V_209 * * V_210 , * V_211 ;
struct V_176 * V_144 ;
struct V_8 * V_9 = F_22 ( V_35 ) ;
char * V_72 , * V_207 = NULL ;
int (* F_100)( void * V_129 );
int V_186 = - V_100 ;
F_39 ( 7 , L_45 , V_212 , F_101 ( V_213 ) ) ;
F_39 ( 7 , L_46 ,
sizeof( struct F_25 ) ) ;
if ( V_59 == V_33 ) {
if ( V_9 -> V_214 )
return - V_215 ;
F_102 ( V_9 -> V_160 , V_208 ,
sizeof( V_9 -> V_160 ) ) ;
V_9 -> V_22 = V_21 ;
V_210 = & V_9 -> V_214 ;
V_72 = L_47 ;
F_100 = F_89 ;
V_144 = F_76 ( V_35 ) ;
} else if ( V_59 == V_166 ) {
if ( V_9 -> V_216 )
return - V_215 ;
F_102 ( V_9 -> V_167 , V_208 ,
sizeof( V_9 -> V_167 ) ) ;
V_9 -> V_142 = V_21 ;
V_210 = & V_9 -> V_216 ;
V_72 = L_48 ;
F_100 = F_93 ;
V_144 = F_81 ( V_35 ) ;
} else {
return - V_126 ;
}
if ( F_103 ( V_144 ) ) {
V_186 = F_104 ( V_144 ) ;
goto V_134;
}
F_70 ( V_35 , V_59 ) ;
if ( V_59 == V_166 ) {
V_207 = F_12 ( V_9 -> V_168 , V_217 ) ;
if ( ! V_207 )
goto V_218;
}
V_205 = F_12 ( sizeof( * V_205 ) , V_217 ) ;
if ( ! V_205 )
goto V_219;
V_205 -> V_35 = V_35 ;
V_205 -> V_144 = V_144 ;
V_205 -> V_207 = V_207 ;
V_211 = F_105 ( F_100 , V_205 , V_72 , V_9 -> V_220 ) ;
if ( F_103 ( V_211 ) ) {
V_186 = F_104 ( V_211 ) ;
goto V_221;
}
* V_210 = V_211 ;
V_9 -> V_32 |= V_59 ;
F_106 () ;
return 0 ;
V_221:
F_13 ( V_205 ) ;
V_219:
F_13 ( V_207 ) ;
V_218:
F_80 ( V_144 -> V_145 ) ;
V_134:
return V_186 ;
}
int F_107 ( struct V_35 * V_35 , int V_59 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
int V_133 = - V_126 ;
F_39 ( 7 , L_45 , V_212 , F_101 ( V_213 ) ) ;
if ( V_59 == V_33 ) {
if ( ! V_9 -> V_214 )
return - V_222 ;
F_90 ( L_49 ,
F_101 ( V_9 -> V_214 ) ) ;
F_6 ( & V_9 -> V_11 ) ;
V_9 -> V_32 &= ~ V_33 ;
F_10 ( & V_9 -> V_11 ) ;
V_133 = F_108 ( V_9 -> V_214 ) ;
V_9 -> V_214 = NULL ;
} else if ( V_59 == V_166 ) {
if ( ! V_9 -> V_216 )
return - V_222 ;
F_90 ( L_50 ,
F_101 ( V_9 -> V_216 ) ) ;
V_9 -> V_32 &= ~ V_166 ;
V_133 = F_108 ( V_9 -> V_216 ) ;
V_9 -> V_216 = NULL ;
}
F_109 () ;
return V_133 ;
}
int T_6 F_110 ( struct V_35 * V_35 )
{
struct V_8 * V_9 = F_22 ( V_35 ) ;
F_111 ( & V_9 -> V_223 , L_51 , & V_224 ) ;
F_112 ( & V_9 -> V_12 ) ;
F_113 ( & V_9 -> V_11 ) ;
F_113 ( & V_9 -> V_34 ) ;
V_9 -> V_225 . V_179 = V_44 ;
V_9 -> V_225 . V_182 = F_114 ( V_226 ) ;
V_9 -> V_225 . V_180 . V_181 = F_115 ( V_227 ) ;
return 0 ;
}
void F_116 ( struct V_35 * V_35 )
{
int V_133 ;
struct V_8 * V_9 = F_22 ( V_35 ) ;
F_117 ( & V_9 -> V_223 ) ;
V_133 = F_107 ( V_35 , V_33 ) ;
if ( V_133 && V_133 != - V_222 )
F_27 ( L_52 ) ;
V_133 = F_107 ( V_35 , V_166 ) ;
if ( V_133 && V_133 != - V_222 )
F_27 ( L_53 ) ;
F_118 ( & V_9 -> V_223 ) ;
}
