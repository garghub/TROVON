struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 , int V_5 , int V_6 )
{
struct V_1 * V_7 =
F_2 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_7 )
goto V_9;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
F_3 ( & V_7 -> V_12 ) ;
F_4 ( & V_7 -> V_13 ) ;
snprintf ( V_7 -> V_14 , sizeof( V_7 -> V_14 ) ,
L_1 , V_4 , V_5 , V_6 ) ;
V_7 -> V_15 = F_5 ( V_7 -> V_14 ,
sizeof( struct V_16 ) ,
0 , 0 , NULL ) ;
if ( ! V_7 -> V_15 )
goto V_17;
snprintf ( V_7 -> V_18 , sizeof( V_7 -> V_18 ) ,
L_2 , V_4 , V_5 , V_6 ) ;
V_7 -> V_19 = F_6 ( V_7 -> V_18 ,
V_3 ,
V_20 ,
4 , 0 ) ;
if ( ! V_7 -> V_19 )
goto V_21;
V_7 -> V_22 = V_23 ;
goto V_9;
V_21:
F_7 ( V_7 -> V_15 ) ;
V_17:
F_8 ( V_7 ) ;
V_7 = NULL ;
V_9:
return V_7 ;
}
static void F_9 ( struct V_16 * V_24 ,
int V_25 , T_1 V_26 , T_1 V_27 ,
int V_28 , int V_29 ,
struct V_30 * V_30 ,
void * V_31 , T_2 V_32 )
{
V_24 -> V_33 [ V_25 ] . V_26 = V_26 ;
V_24 -> V_33 [ V_25 ] . V_34 = V_27 ;
V_24 -> V_33 [ V_25 ] . V_28 = V_28 ;
V_24 -> V_33 [ V_25 ] . V_29 = V_29 ;
V_24 -> V_33 [ V_25 ] . V_30 = V_30 ;
V_24 -> V_33 [ V_25 ] . V_31 = V_31 ;
V_24 -> V_33 [ V_25 ] . V_33 = V_32 ;
}
static void F_10 ( struct V_16 * V_24 ,
T_3 V_10 , T_1 V_26 ,
T_1 V_27 , int V_29 ,
struct V_30 * V_30 ,
void * V_31 , T_2 V_32 )
{
V_24 -> V_35 = 1 ;
V_24 -> V_10 = V_10 ;
F_9 ( V_24 , 0 , V_26 , V_27 , 0 , V_29 , V_30 ,
V_31 , V_32 ) ;
}
static int F_11 ( const struct V_36 * V_37 ,
struct V_16 * V_24 ,
const struct V_38 * V_39 ,
unsigned long V_40 )
{
int V_41 = 0 ;
struct V_30 * V_30 = F_12 ( V_8 ) ;
void * V_42 ;
char * V_43 ;
int V_25 ;
int V_27 = 0 ;
T_2 V_32 ;
if ( ! V_30 ) {
V_41 = - V_44 ;
goto V_9;
}
V_43 = F_13 ( V_30 ) ;
V_42 = V_43 ;
for ( V_25 = 0 ; V_25 < V_40 ; V_25 ++ ) {
int V_45 ;
V_45 = F_14 ( V_43 ,
V_39 [ V_25 ] . V_46 , V_39 [ V_25 ] . V_47 ) ;
if ( V_45 ) {
V_41 = - V_48 ;
goto V_49;
}
V_43 += V_39 [ V_25 ] . V_47 ;
V_27 += V_39 [ V_25 ] . V_47 ;
}
V_32 = F_15 ( & V_37 -> V_50 -> V_3 , V_30 , 0 , V_27 ,
V_51 ) ;
if ( F_16 ( & V_37 -> V_50 -> V_3 , V_32 ) ) {
V_41 = - V_44 ;
goto V_49;
}
F_9 ( V_24 , 1 , 0 , V_27 , 0 , 1 , V_30 , V_42 ,
V_32 ) ;
V_24 -> V_35 = 2 ;
goto V_9;
V_49:
F_17 ( V_30 ) ;
F_18 ( V_30 ) ;
V_9:
return V_41 ;
}
static int F_19 ( const struct V_38 * V_39 )
{
const unsigned long V_33 = ( unsigned long ) V_39 -> V_46 ;
const unsigned long V_27 = V_39 -> V_47 ;
const unsigned long V_52 = V_33 & V_53 ;
const unsigned long V_54 = ( V_33 + V_27 - 1 ) & V_53 ;
return 1 + ( ( V_54 - V_52 ) >> V_55 ) ;
}
static int F_20 ( unsigned long V_33 , unsigned long V_27 )
{
const unsigned long V_26 = V_33 & ~ V_53 ;
return ( ( V_26 + V_27 ) > V_56 ) ? ( V_56 - V_26 ) : V_27 ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_16 * V_24 ,
int V_57 )
{
const int V_25 = V_57 ;
if ( V_24 -> V_33 [ V_25 ] . V_30 ) {
if ( V_24 -> V_33 [ V_25 ] . V_29 )
F_22 ( V_3 ,
V_24 -> V_33 [ V_25 ] . V_33 ,
V_24 -> V_33 [ V_25 ] . V_34 ,
V_51 ) ;
if ( V_24 -> V_33 [ V_25 ] . V_31 )
F_17 ( V_24 -> V_33 [ V_25 ] . V_30 ) ;
if ( V_24 -> V_33 [ V_25 ] . V_28 )
V_28 ( V_24 -> V_33 [ V_25 ] . V_30 ) ;
else
F_18 ( V_24 -> V_33 [ V_25 ] . V_30 ) ;
} else if ( V_24 -> V_33 [ V_25 ] . V_31 )
F_23 ( V_7 -> V_19 ,
V_24 -> V_33 [ V_25 ] . V_31 , V_24 -> V_33 [ V_25 ] . V_33 ) ;
}
static int F_24 ( const struct V_36 * V_37 ,
struct V_16 * V_24 ,
unsigned long V_33 , int V_58 , int V_59 )
{
struct V_30 * V_60 [ 2 ] ;
int V_61 ;
int V_41 ;
V_41 = F_25 ( V_62 , V_62 -> V_63 , V_33 ,
V_59 , 0 , 1 , V_60 , NULL ) ;
if ( V_41 != V_59 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ )
V_28 ( V_60 [ V_25 ] ) ;
V_41 = - V_44 ;
goto V_9;
}
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
const int V_64 = F_20 ( V_33 , V_58 ) ;
T_2 V_32 =
F_15 ( & V_37 -> V_50 -> V_3 ,
V_60 [ V_61 ] , 0 , V_64 , V_51 ) ;
unsigned long V_65 = V_33 & ~ V_53 ;
if ( F_16 ( & V_37 -> V_50 -> V_3 , V_32 ) ) {
V_41 = - V_44 ;
goto V_9;
}
F_9 ( V_24 , V_24 -> V_35 , V_65 , V_64 , 1 , 1 ,
V_60 [ V_61 ] , F_13 ( V_60 [ V_61 ] ) , V_32 ) ;
V_24 -> V_35 ++ ;
V_33 += V_64 ;
V_58 -= V_64 ;
}
V_9:
return V_41 ;
}
static int F_26 ( const struct V_36 * V_37 ,
struct V_1 * V_7 ,
struct V_16 * V_24 ,
const struct V_38 * V_39 ,
unsigned long V_40 )
{
int V_41 = 0 ;
unsigned long V_66 ;
for ( V_66 = 0 ; V_66 < V_40 ; V_66 ++ ) {
const int V_59 = F_19 ( V_39 + V_66 ) ;
const unsigned long V_33 = ( unsigned long ) V_39 [ V_66 ] . V_46 ;
V_41 = F_24 ( V_37 , V_24 , V_33 ,
V_39 [ V_66 ] . V_47 , V_59 ) ;
if ( V_41 < 0 )
goto V_67;
}
goto V_9;
V_67:
for ( V_66 = 0 ; V_66 < V_24 -> V_35 ; V_66 ++ )
F_21 ( & V_37 -> V_50 -> V_3 , V_7 , V_24 , V_66 ) ;
V_9:
return V_41 ;
}
static int F_27 ( const struct V_36 * V_37 ,
struct V_1 * V_7 ,
struct V_16 * V_24 ,
const struct V_38 * V_39 ,
unsigned long V_40 , int V_59 )
{
int V_41 = 0 ;
if ( V_59 >= F_28 ( V_24 -> V_33 ) )
V_41 = F_11 ( V_37 , V_24 , V_39 , V_40 ) ;
else
V_41 = F_26 ( V_37 , V_7 , V_24 , V_39 , V_40 ) ;
return V_41 ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_68 * V_69 )
{
struct V_16 * V_24 , * V_70 ;
F_30 (pkt, pkt_next, list, list) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_24 -> V_35 ; V_25 ++ )
F_21 ( V_3 , V_7 , V_24 , V_25 ) ;
F_31 ( V_7 -> V_15 , V_24 ) ;
}
F_3 ( V_69 ) ;
}
static int F_32 ( const struct V_36 * V_37 ,
struct V_1 * V_7 ,
struct V_68 * V_69 ,
const struct V_38 * V_39 ,
unsigned long V_40 ,
int V_71 )
{
unsigned long V_66 = 0 ;
int V_41 = 0 ;
int V_72 = 0 ;
struct V_30 * V_30 = NULL ;
T_4 * V_73 ;
T_2 V_32 ;
struct V_16 * V_24 = NULL ;
T_1 V_27 ;
T_1 V_74 ;
T_3 V_10 = V_7 -> V_10 ;
int V_29 = 0 ;
while ( V_66 < V_40 && V_72 < V_71 ) {
const unsigned long V_33 = ( unsigned long ) V_39 [ V_66 ] . V_46 ;
const unsigned long V_75 = V_66 ;
unsigned V_76 ;
unsigned V_77 ;
int V_78 = 0 ;
int V_59 = 0 ;
int V_45 ;
V_29 = 0 ;
V_27 = V_39 [ V_66 ] . V_47 ;
V_74 = V_27 >> 2 ;
V_30 = NULL ;
V_24 = F_33 ( V_7 -> V_15 , V_8 ) ;
if ( ! V_24 ) {
V_41 = - V_44 ;
goto V_79;
}
if ( V_27 < V_80 ||
V_27 > V_56 || V_27 & 3 || V_33 & 3 ) {
V_41 = - V_81 ;
goto V_67;
}
if ( V_27 == V_20 )
V_73 = F_34 ( V_7 -> V_19 , V_8 ,
& V_32 ) ;
else
V_73 = NULL ;
if ( ! V_73 ) {
V_30 = F_12 ( V_8 ) ;
if ( ! V_30 ) {
V_41 = - V_44 ;
goto V_67;
}
V_73 = F_13 ( V_30 ) ;
}
V_45 = F_14 ( V_73 , V_39 [ V_66 ] . V_46 , V_27 ) ;
if ( V_45 ) {
V_41 = - V_48 ;
goto V_82;
}
V_77 = V_74 - 1 ;
V_76 = F_35 ( * V_73 ) & V_83 ;
if ( V_76 < V_77 || V_76 > V_77 + ( V_56 >> 2 ) ) {
V_41 = - V_81 ;
goto V_82;
}
V_66 ++ ;
while ( V_77 < V_76 && V_66 < V_40 ) {
const T_1 V_84 = V_39 [ V_66 ] . V_47 ;
const unsigned long V_85 =
( unsigned long ) V_39 [ V_66 ] . V_46 ;
if ( V_84 & 3 || V_85 & 3 || ! V_84 ||
V_84 > V_56 ) {
V_41 = - V_81 ;
goto V_82;
}
V_59 ++ ;
if ( ( V_85 & V_53 ) !=
( ( V_85 + V_84 - 1 ) & V_53 ) )
V_59 ++ ;
V_77 += V_84 >> 2 ;
V_66 ++ ;
V_78 ++ ;
}
if ( V_77 != V_76 ) {
V_41 = - V_81 ;
goto V_82;
}
if ( V_30 ) {
V_32 = F_15 ( & V_37 -> V_50 -> V_3 ,
V_30 , 0 , V_27 , V_51 ) ;
if ( F_16 ( & V_37 -> V_50 -> V_3 , V_32 ) ) {
V_41 = - V_44 ;
goto V_82;
}
V_29 = 1 ;
}
F_10 ( V_24 , V_10 , 0 , V_27 , V_29 ,
V_30 , V_73 , V_32 ) ;
if ( V_78 ) {
V_41 = F_27 ( V_37 , V_7 , V_24 ,
V_39 + V_75 + 1 ,
V_78 , V_59 ) ;
if ( V_41 < 0 )
goto V_86;
}
V_10 ++ ;
V_72 ++ ;
F_36 ( & V_24 -> V_69 , V_69 ) ;
}
V_41 = V_66 ;
goto V_9;
V_86:
if ( V_29 )
F_22 ( & V_37 -> V_50 -> V_3 , V_32 , V_27 , V_51 ) ;
V_82:
if ( V_30 ) {
F_17 ( V_30 ) ;
F_18 ( V_30 ) ;
} else
F_23 ( V_7 -> V_19 , V_73 , V_32 ) ;
V_67:
F_31 ( V_7 -> V_15 , V_24 ) ;
V_79:
F_29 ( & V_37 -> V_50 -> V_3 , V_7 , V_69 ) ;
V_9:
return V_41 ;
}
static void F_37 ( struct V_1 * V_7 ,
T_3 V_87 )
{
V_7 -> V_11 = V_87 ;
}
static int F_38 ( struct V_88 * V_89 ,
struct V_1 * V_7 )
{
struct V_36 * V_37 = V_89 -> V_37 ;
struct V_68 V_79 ;
struct V_16 * V_24 ;
struct V_16 * V_90 ;
int V_41 = 0 ;
F_3 ( & V_79 ) ;
F_30 (pkt, pkt_prev, &pq->sent, list) {
T_5 V_91 = V_89 -> V_92 - V_24 -> V_93 ;
if ( V_91 < 0 )
break;
F_39 ( & V_24 -> V_69 , & V_79 ) ;
V_41 ++ ;
}
if ( ! F_40 ( & V_79 ) ) {
T_3 V_10 ;
V_24 = F_41 ( V_79 . V_94 ,
struct V_16 , V_69 ) ;
V_10 = V_24 -> V_10 ;
F_29 ( & V_37 -> V_50 -> V_3 , V_7 , & V_79 ) ;
F_37 ( V_7 , V_10 ) ;
}
return V_41 ;
}
void F_42 ( struct V_1 * V_7 )
{
if ( ! V_7 )
return;
F_7 ( V_7 -> V_15 ) ;
F_43 ( V_7 -> V_19 ) ;
F_8 ( V_7 ) ;
}
static int F_44 ( struct V_88 * V_89 )
{
int V_41 ;
unsigned long V_95 ;
F_45 ( & V_89 -> V_96 , V_95 ) ;
V_41 = F_46 ( V_89 ) ;
F_47 ( & V_89 -> V_96 , V_95 ) ;
return V_41 ;
}
void F_48 ( struct V_88 * V_89 ,
struct V_1 * V_7 )
{
struct V_36 * V_37 = V_89 -> V_37 ;
int V_25 ;
if ( ! V_7 )
return;
for ( V_25 = 0 ; V_25 < V_97 ; V_25 ++ ) {
F_49 ( & V_7 -> V_13 ) ;
if ( F_40 ( & V_7 -> V_12 ) ) {
F_50 ( & V_7 -> V_13 ) ;
break;
}
F_44 ( V_89 ) ;
F_38 ( V_89 , V_7 ) ;
F_50 ( & V_7 -> V_13 ) ;
F_51 ( 10 ) ;
}
if ( ! F_40 ( & V_7 -> V_12 ) ) {
struct V_68 V_79 ;
F_52 ( V_37 , L_3 ) ;
F_3 ( & V_79 ) ;
F_49 ( & V_7 -> V_13 ) ;
F_53 ( & V_7 -> V_12 , & V_79 ) ;
F_29 ( & V_37 -> V_50 -> V_3 , V_7 , & V_79 ) ;
F_50 ( & V_7 -> V_13 ) ;
}
}
static inline T_6 F_54 ( struct V_88 * V_89 ,
T_7 V_33 , T_7 V_98 , T_7 V_99 )
{
T_8 V_100 ;
V_100 = V_89 -> V_101 ;
return F_55 (
( ( V_33 & 0xfffffffcULL ) << 32 ) |
( ( V_100 & 3ULL ) << 30 ) |
( ( V_98 & 0x7ffULL ) << 16 ) |
( V_99 & 0x7ffULL ) ) ;
}
static inline T_6 F_56 ( T_6 V_102 )
{
return V_102 | F_55 ( 1ULL << 12 ) ;
}
static inline T_6 F_57 ( T_6 V_102 )
{
return V_102 | F_55 ( 1ULL << 11 | 1ULL << 13 ) ;
}
static inline T_6 F_58 ( T_7 V_33 )
{
return F_55 ( V_33 >> 32 ) ;
}
static void F_59 ( struct V_88 * V_89 ,
struct V_16 * V_24 , int V_66 ,
unsigned V_103 , T_9 V_104 )
{
const T_7 V_33 = ( T_7 ) V_24 -> V_33 [ V_66 ] . V_33 +
( T_7 ) V_24 -> V_33 [ V_66 ] . V_26 ;
const T_7 V_98 = ( T_7 ) V_24 -> V_33 [ V_66 ] . V_34 / 4 ;
T_6 * V_105 ;
T_6 V_106 ;
V_105 = & V_89 -> V_107 [ V_104 ] . V_108 [ 0 ] ;
V_106 = F_54 ( V_89 , V_33 , V_98 , V_103 ) ;
if ( V_66 == 0 )
V_106 = F_56 ( V_106 ) ;
if ( V_66 == V_24 -> V_35 - 1 )
V_106 = F_57 ( V_106 ) ;
V_105 [ 0 ] = V_106 ;
V_105 [ 1 ] = F_58 ( V_33 ) ;
}
static int F_60 ( struct V_88 * V_89 ,
struct V_1 * V_7 ,
struct V_68 * V_109 )
{
struct V_36 * V_37 = V_89 -> V_37 ;
int V_41 = 0 ;
unsigned long V_95 ;
T_9 V_104 ;
T_8 V_110 ;
T_7 V_111 ;
if ( F_40 ( V_109 ) )
return 0 ;
if ( F_61 ( ! ( V_89 -> V_112 & V_113 ) ) )
return - V_114 ;
F_45 ( & V_89 -> V_96 , V_95 ) ;
V_110 = V_89 -> V_101 ;
V_111 = V_89 -> V_115 ;
if ( F_61 ( ! F_62 ( V_89 ) ) ) {
V_41 = - V_114 ;
goto V_116;
}
V_104 = V_89 -> V_117 ;
while ( ! F_40 ( V_109 ) ) {
struct V_16 * V_24 =
F_41 ( V_109 -> V_118 , struct V_16 ,
V_69 ) ;
int V_25 ;
unsigned V_103 = 0 ;
T_9 V_119 = V_104 ;
if ( V_24 -> V_35 > F_63 ( V_89 ) )
goto V_120;
for ( V_25 = 0 ; V_25 < V_24 -> V_35 ; V_25 ++ ) {
F_59 ( V_89 , V_24 , V_25 , V_103 , V_104 ) ;
V_103 += V_24 -> V_33 [ V_25 ] . V_34 >> 2 ;
if ( ++ V_104 == V_89 -> V_121 ) {
V_104 = 0 ;
++ V_89 -> V_101 ;
}
}
if ( ( V_103 << 2 ) > V_89 -> V_122 ) {
V_41 = - V_123 ;
goto V_116;
}
if ( V_103 > V_37 -> V_124 ) {
for ( V_25 = 0 ; V_25 < V_24 -> V_35 ; V_25 ++ ) {
V_89 -> V_107 [ V_119 ] . V_108 [ 0 ] |=
F_55 ( 1ULL << 14 ) ;
if ( ++ V_119 == V_89 -> V_121 )
V_119 = 0 ;
}
}
V_89 -> V_115 += V_24 -> V_35 ;
V_24 -> V_93 = V_89 -> V_115 ;
F_39 ( & V_24 -> V_69 , & V_7 -> V_12 ) ;
V_41 ++ ;
}
V_120:
if ( V_89 -> V_117 != V_104 )
V_37 -> V_125 ( V_89 , V_104 ) ;
V_116:
if ( F_61 ( V_41 < 0 ) ) {
V_89 -> V_101 = V_110 ;
V_89 -> V_115 = V_111 ;
}
F_47 ( & V_89 -> V_96 , V_95 ) ;
return V_41 ;
}
int F_64 ( struct V_126 * V_127 ,
struct V_1 * V_7 ,
const struct V_38 * V_39 ,
unsigned long V_128 )
{
struct V_36 * V_37 = V_127 -> V_37 ;
struct V_88 * V_89 = V_127 -> V_89 ;
int V_41 = 0 ;
struct V_68 V_69 ;
int V_72 = 0 ;
F_3 ( & V_69 ) ;
F_49 ( & V_7 -> V_13 ) ;
if ( ! F_65 ( V_89 ) )
goto V_129;
if ( V_89 -> V_115 != V_89 -> V_92 ) {
F_44 ( V_89 ) ;
F_38 ( V_89 , V_7 ) ;
}
while ( V_128 ) {
const int V_130 = 8 ;
F_66 ( & V_62 -> V_63 -> V_131 ) ;
V_41 = F_32 ( V_37 , V_7 , & V_69 , V_39 , V_128 , V_130 ) ;
F_67 ( & V_62 -> V_63 -> V_131 ) ;
if ( V_41 <= 0 )
goto V_129;
else {
V_128 -= V_41 ;
V_39 += V_41 ;
}
if ( ! F_40 ( & V_69 ) ) {
if ( F_63 ( V_89 ) < V_41 * 4 ) {
F_44 ( V_89 ) ;
F_38 ( V_89 , V_7 ) ;
}
V_41 = F_60 ( V_89 , V_7 , & V_69 ) ;
if ( V_41 < 0 )
goto V_129;
else {
V_72 += V_41 ;
V_7 -> V_10 += V_41 ;
if ( ! F_40 ( & V_69 ) )
goto V_129;
}
}
}
V_129:
if ( ! F_40 ( & V_69 ) )
F_29 ( & V_37 -> V_50 -> V_3 , V_7 , & V_69 ) ;
F_50 ( & V_7 -> V_13 ) ;
return ( V_41 < 0 ) ? V_41 : V_72 ;
}
int F_68 ( struct V_88 * V_89 ,
struct V_1 * V_7 )
{
int V_41 = 0 ;
F_49 ( & V_7 -> V_13 ) ;
F_44 ( V_89 ) ;
V_41 = F_38 ( V_89 , V_7 ) ;
F_50 ( & V_7 -> V_13 ) ;
return V_41 ;
}
T_3 F_69 ( const struct V_1 * V_7 )
{
return V_7 ? V_7 -> V_11 : 0 ;
}
T_3 F_70 ( struct V_1 * V_7 )
{
return V_7 ? V_7 -> V_10 : 0 ;
}
