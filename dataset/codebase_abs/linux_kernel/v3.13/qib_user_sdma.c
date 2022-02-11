struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 , int V_5 , int V_6 )
{
struct V_1 * V_7 =
F_2 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_7 )
goto V_9;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = 0 ;
F_3 ( & V_7 -> V_15 ) ;
F_4 ( & V_7 -> V_16 ) ;
F_5 ( & V_7 -> V_17 ) ;
snprintf ( V_7 -> V_18 , sizeof( V_7 -> V_18 ) ,
L_1 , V_4 , V_5 , V_6 ) ;
V_7 -> V_19 = F_6 ( V_7 -> V_18 ,
sizeof( struct V_20 ) ,
0 , 0 , NULL ) ;
if ( ! V_7 -> V_19 )
goto V_21;
snprintf ( V_7 -> V_22 , sizeof( V_7 -> V_22 ) ,
L_2 , V_4 , V_5 , V_6 ) ;
V_7 -> V_23 = F_7 ( V_7 -> V_22 ,
V_3 ,
V_24 ,
4 , 0 ) ;
if ( ! V_7 -> V_23 )
goto V_25;
V_7 -> V_26 = V_27 ;
goto V_9;
V_25:
F_8 ( V_7 -> V_19 ) ;
V_21:
F_9 ( V_7 ) ;
V_7 = NULL ;
V_9:
return V_7 ;
}
static void F_10 ( struct V_20 * V_28 ,
int V_29 , T_1 V_30 , T_1 V_31 ,
T_1 V_32 , T_1 V_33 ,
T_1 V_34 , T_1 V_35 ,
struct V_36 * V_36 , void * V_37 ,
T_2 V_38 , T_1 V_39 )
{
V_28 -> V_40 [ V_29 ] . V_30 = V_30 ;
V_28 -> V_40 [ V_29 ] . V_41 = V_31 ;
V_28 -> V_40 [ V_29 ] . V_32 = V_32 ;
V_28 -> V_40 [ V_29 ] . V_33 = V_33 ;
V_28 -> V_40 [ V_29 ] . V_34 = V_34 ;
V_28 -> V_40 [ V_29 ] . V_35 = V_35 ;
V_28 -> V_40 [ V_29 ] . V_36 = V_36 ;
V_28 -> V_40 [ V_29 ] . V_37 = V_37 ;
V_28 -> V_40 [ V_29 ] . V_40 = V_38 ;
V_28 -> V_40 [ V_29 ] . V_39 = V_39 ;
}
static void * F_11 ( struct V_1 * V_7 ,
T_3 V_31 , T_2 * V_38 )
{
void * V_42 ;
if ( V_31 == V_24 )
V_42 = F_12 ( V_7 -> V_23 , V_8 ,
V_38 ) ;
else
V_42 = NULL ;
if ( ! V_42 ) {
V_42 = F_2 ( V_31 , V_8 ) ;
if ( ! V_42 )
return NULL ;
* V_38 = 0 ;
}
return V_42 ;
}
static int F_13 ( const struct V_43 * V_44 ,
struct V_1 * V_7 ,
struct V_20 * V_28 ,
struct V_36 * V_36 , T_1 V_45 ,
T_1 V_30 , T_1 V_31 , void * V_37 )
{
T_4 * V_46 ;
void * V_47 ;
struct V_48 * V_42 ;
T_1 V_49 , V_50 , V_51 , V_35 ;
T_5 V_52 ;
union V_53 V_54 ;
T_2 V_55 ;
T_2 V_38 =
F_14 ( & V_44 -> V_56 -> V_3 ,
V_36 , V_30 , V_31 , V_57 ) ;
int V_58 = 0 ;
if ( F_15 ( & V_44 -> V_56 -> V_3 , V_38 ) ) {
if ( V_45 ) {
V_34 ( V_36 ) ;
} else {
F_16 ( V_36 ) ;
F_17 ( V_36 ) ;
}
V_58 = - V_59 ;
goto V_9;
}
V_30 = 0 ;
V_35 = 1 ;
V_60:
if ( V_28 -> V_61 && V_31 > V_28 -> V_62 [ V_28 -> V_63 ] . V_41 )
V_49 = V_28 -> V_62 [ V_28 -> V_63 ] . V_41 ;
else
V_49 = V_31 ;
V_51 = 0 ;
if ( ( V_28 -> V_64 + V_49 ) >= V_28 -> V_65 ) {
V_49 = V_28 -> V_65 - V_28 -> V_64 ;
V_51 = 1 ;
} else if ( V_28 -> V_61 ) {
if ( V_49 == V_28 -> V_62 [ V_28 -> V_63 ] . V_41 )
V_51 = 1 ;
} else {
if ( V_49 == V_28 -> V_66 )
V_51 = 1 ;
}
F_10 ( V_28 , V_28 -> V_67 ,
V_30 , V_49 ,
0 , V_51 ,
V_45 , V_35 ,
V_36 , V_37 ,
V_38 , V_31 ) ;
V_28 -> V_66 -= V_49 ;
V_28 -> V_64 += V_49 ;
V_28 -> V_67 ++ ;
if ( V_28 -> V_67 == V_28 -> V_68 ) {
V_58 = - V_69 ;
goto V_9;
}
if ( V_28 -> V_66 == 0 ) {
if ( ! V_28 -> V_40 [ V_28 -> V_70 ] . V_40 ) {
V_28 -> V_40 [ V_28 -> V_70 ] . V_40 =
F_18 ( & V_44 -> V_56 -> V_3 ,
V_28 -> V_40 [ V_28 -> V_70 ] . V_37 ,
V_28 -> V_40 [ V_28 -> V_70 ] . V_39 ,
V_57 ) ;
if ( F_15 ( & V_44 -> V_56 -> V_3 ,
V_28 -> V_40 [ V_28 -> V_70 ] . V_40 ) ) {
V_58 = - V_59 ;
goto V_9;
}
V_28 -> V_40 [ V_28 -> V_70 ] . V_35 = 1 ;
}
goto V_9;
}
if ( V_28 -> V_61 ) {
V_28 -> V_62 [ V_28 -> V_63 ] . V_41 -= V_49 ;
if ( V_28 -> V_62 [ V_28 -> V_63 ] . V_41 ) {
V_28 -> V_62 [ V_28 -> V_63 ] . V_30 += V_49 ;
} else {
V_28 -> V_63 ++ ;
if ( V_28 -> V_63 == V_28 -> V_71 ) {
V_58 = - V_69 ;
goto V_9;
}
}
}
if ( V_51 == 0 )
goto V_9;
V_50 = V_28 -> V_40 [ V_28 -> V_70 ] . V_41 ;
V_47 = F_11 ( V_7 , V_50 , & V_55 ) ;
if ( ! V_47 ) {
V_58 = - V_59 ;
goto V_9;
}
V_46 = ( T_4 * ) V_28 -> V_40 [ V_28 -> V_70 ] . V_37 ;
memcpy ( V_47 , V_46 , V_50 ) ;
V_42 = (struct V_48 * ) & V_46 [ 4 ] ;
V_46 [ 0 ] = F_19 ( F_20 ( V_46 [ 0 ] ) - ( V_28 -> V_66 >> 2 ) ) ;
V_42 -> V_72 [ 2 ] = F_21 ( F_20 ( V_46 [ 0 ] ) ) ;
if ( V_28 -> V_61 ) {
V_42 -> V_73 . V_74 =
F_19 ( F_20 ( V_42 -> V_73 . V_74 ) | 0x2 ) ;
V_42 -> V_75 &= ~ ( 0x04 | 0x20 ) ;
} else {
V_42 -> V_76 [ 0 ] = F_22 ( F_23 ( V_42 -> V_76 [ 0 ] ) & 0xFFCFFFFF ) ;
V_42 -> V_75 &= ~ ( 0x04 ) ;
}
V_52 = F_24 ( V_42 -> V_73 . V_77 ) ;
V_42 -> V_73 . V_78 = F_19 ( V_79 +
F_25 ( V_42 -> V_72 [ 2 ] ) -
( ( V_52 >> 16 ) & 0xFFFF ) - ( V_52 & 0xFFFF ) -
F_20 ( V_42 -> V_73 . V_74 ) ) ;
if ( ! V_28 -> V_40 [ V_28 -> V_70 ] . V_40 ) {
V_28 -> V_40 [ V_28 -> V_70 ] . V_40 =
F_18 ( & V_44 -> V_56 -> V_3 ,
V_28 -> V_40 [ V_28 -> V_70 ] . V_37 ,
V_28 -> V_40 [ V_28 -> V_70 ] . V_39 ,
V_57 ) ;
if ( F_15 ( & V_44 -> V_56 -> V_3 ,
V_28 -> V_40 [ V_28 -> V_70 ] . V_40 ) ) {
V_58 = - V_59 ;
goto V_9;
}
V_28 -> V_40 [ V_28 -> V_70 ] . V_35 = 1 ;
}
V_46 = ( T_4 * ) V_47 ;
V_42 = (struct V_48 * ) & V_46 [ 4 ] ;
V_46 [ 0 ] = F_19 ( F_20 ( V_46 [ 0 ] ) - ( V_28 -> V_64 >> 2 ) ) ;
V_42 -> V_72 [ 2 ] = F_21 ( F_20 ( V_46 [ 0 ] ) ) ;
if ( V_28 -> V_61 ) {
V_42 -> V_73 . V_77 = F_26 (
( F_24 ( V_42 -> V_73 . V_77 ) & 0xFF000000 ) +
( V_28 -> V_62 [ V_28 -> V_63 ] . V_80 << V_81 ) +
( V_28 -> V_62 [ V_28 -> V_63 ] . V_30 >> 2 ) ) ;
} else {
V_42 -> V_82 [ 2 ] += V_28 -> V_64 ;
}
V_52 = F_24 ( V_42 -> V_73 . V_77 ) ;
V_42 -> V_73 . V_78 = F_19 ( V_79 +
F_25 ( V_42 -> V_72 [ 2 ] ) -
( ( V_52 >> 16 ) & 0xFFFF ) - ( V_52 & 0xFFFF ) -
F_20 ( V_42 -> V_73 . V_74 ) ) ;
V_54 . V_83 = F_23 ( V_42 -> V_76 [ 2 ] ) ;
if ( V_28 -> V_61 )
V_54 . V_84 ++ ;
else
V_54 . V_28 ++ ;
V_42 -> V_76 [ 2 ] = F_22 ( V_54 . V_83 ) ;
F_10 ( V_28 , V_28 -> V_67 ,
0 , V_50 ,
1 , 0 ,
0 , 0 ,
NULL , V_47 ,
V_55 , V_50 ) ;
V_28 -> V_70 = V_28 -> V_67 ;
V_28 -> V_64 = 0 ;
V_28 -> V_67 ++ ;
if ( V_28 -> V_67 == V_28 -> V_68 ) {
V_58 = - V_69 ;
goto V_9;
}
if ( V_49 != V_31 ) {
if ( V_35 ) {
V_45 = 0 ;
V_35 = 0 ;
V_36 = NULL ;
V_37 = NULL ;
}
V_31 -= V_49 ;
V_30 += V_49 ;
goto V_60;
}
V_9:
return V_58 ;
}
static int F_27 ( const struct V_43 * V_44 ,
struct V_1 * V_7 ,
struct V_20 * V_28 ,
const struct V_85 * V_86 ,
unsigned long V_87 )
{
int V_58 = 0 ;
struct V_36 * V_36 = F_28 ( V_8 ) ;
void * V_88 ;
char * V_89 ;
int V_29 ;
int V_31 = 0 ;
if ( ! V_36 ) {
V_58 = - V_59 ;
goto V_9;
}
V_89 = F_29 ( V_36 ) ;
V_88 = V_89 ;
for ( V_29 = 0 ; V_29 < V_87 ; V_29 ++ ) {
int V_90 ;
V_90 = F_30 ( V_89 ,
V_86 [ V_29 ] . V_91 , V_86 [ V_29 ] . V_92 ) ;
if ( V_90 ) {
V_58 = - V_69 ;
goto V_93;
}
V_89 += V_86 [ V_29 ] . V_92 ;
V_31 += V_86 [ V_29 ] . V_92 ;
}
V_58 = F_13 ( V_44 , V_7 , V_28 ,
V_36 , 0 , 0 , V_31 , V_88 ) ;
goto V_9;
V_93:
F_16 ( V_36 ) ;
F_17 ( V_36 ) ;
V_9:
return V_58 ;
}
static int F_31 ( const struct V_85 * V_86 )
{
const unsigned long V_40 = ( unsigned long ) V_86 -> V_91 ;
const unsigned long V_31 = V_86 -> V_92 ;
const unsigned long V_94 = V_40 & V_95 ;
const unsigned long V_96 = ( V_40 + V_31 - 1 ) & V_95 ;
return 1 + ( ( V_96 - V_94 ) >> V_97 ) ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_20 * V_28 ,
int V_98 )
{
const int V_29 = V_98 ;
if ( V_28 -> V_40 [ V_29 ] . V_36 ) {
if ( V_28 -> V_40 [ V_29 ] . V_35 )
F_33 ( V_3 ,
V_28 -> V_40 [ V_29 ] . V_40 ,
V_28 -> V_40 [ V_29 ] . V_39 ,
V_57 ) ;
if ( V_28 -> V_40 [ V_29 ] . V_37 )
F_16 ( V_28 -> V_40 [ V_29 ] . V_36 ) ;
if ( V_28 -> V_40 [ V_29 ] . V_34 )
V_34 ( V_28 -> V_40 [ V_29 ] . V_36 ) ;
else
F_17 ( V_28 -> V_40 [ V_29 ] . V_36 ) ;
} else if ( V_28 -> V_40 [ V_29 ] . V_37 ) {
if ( V_28 -> V_40 [ V_29 ] . V_35 ) {
F_34 ( V_3 ,
V_28 -> V_40 [ V_29 ] . V_40 ,
V_28 -> V_40 [ V_29 ] . V_39 ,
V_57 ) ;
F_9 ( V_28 -> V_40 [ V_29 ] . V_37 ) ;
} else if ( V_28 -> V_40 [ V_29 ] . V_40 ) {
F_35 ( V_7 -> V_23 ,
V_28 -> V_40 [ V_29 ] . V_37 , V_28 -> V_40 [ V_29 ] . V_40 ) ;
} else {
F_9 ( V_28 -> V_40 [ V_29 ] . V_37 ) ;
}
}
}
static int F_36 ( const struct V_43 * V_44 ,
struct V_1 * V_7 ,
struct V_20 * V_28 ,
unsigned long V_40 , int V_99 , int V_100 )
{
struct V_36 * V_101 [ 8 ] ;
int V_29 , V_102 ;
int V_58 = 0 ;
while ( V_100 ) {
if ( V_100 > 8 )
V_102 = 8 ;
else
V_102 = V_100 ;
V_58 = F_37 ( V_40 , V_102 , 0 , V_101 ) ;
if ( V_58 != V_102 ) {
V_29 = 0 ;
V_102 = V_58 ;
V_58 = - V_59 ;
goto V_103;
}
for ( V_29 = 0 ; V_29 < V_102 ; V_29 ++ ) {
unsigned long V_104 = V_40 & ~ V_95 ;
int V_105 = ( ( V_104 + V_99 ) > V_106 ) ?
( V_106 - V_104 ) : V_99 ;
V_58 = F_13 ( V_44 , V_7 , V_28 ,
V_101 [ V_29 ] , 1 , V_104 , V_105 , NULL ) ;
if ( V_58 < 0 ) {
V_29 ++ ;
goto V_103;
}
V_40 += V_105 ;
V_99 -= V_105 ;
}
V_100 -= V_102 ;
}
goto V_9;
V_103:
while ( V_29 < V_102 )
V_34 ( V_101 [ V_29 ++ ] ) ;
V_9:
return V_58 ;
}
static int F_38 ( const struct V_43 * V_44 ,
struct V_1 * V_7 ,
struct V_20 * V_28 ,
const struct V_85 * V_86 ,
unsigned long V_87 )
{
int V_58 = 0 ;
unsigned long V_107 ;
for ( V_107 = 0 ; V_107 < V_87 ; V_107 ++ ) {
const int V_100 = F_31 ( V_86 + V_107 ) ;
const unsigned long V_40 = ( unsigned long ) V_86 [ V_107 ] . V_91 ;
V_58 = F_36 ( V_44 , V_7 , V_28 , V_40 ,
V_86 [ V_107 ] . V_92 , V_100 ) ;
if ( V_58 < 0 )
goto V_108;
}
goto V_9;
V_108:
for ( V_107 = 1 ; V_107 < V_28 -> V_67 ; V_107 ++ )
F_32 ( & V_44 -> V_56 -> V_3 , V_7 , V_28 , V_107 ) ;
if ( V_28 -> V_40 [ 0 ] . V_35 ) {
F_34 ( & V_44 -> V_56 -> V_3 ,
V_28 -> V_40 [ 0 ] . V_40 ,
V_28 -> V_40 [ 0 ] . V_39 ,
V_57 ) ;
V_28 -> V_40 [ 0 ] . V_40 = 0 ;
V_28 -> V_40 [ 0 ] . V_35 = 0 ;
}
V_9:
return V_58 ;
}
static int F_39 ( const struct V_43 * V_44 ,
struct V_1 * V_7 ,
struct V_20 * V_28 ,
const struct V_85 * V_86 ,
unsigned long V_87 , int V_100 )
{
int V_58 = 0 ;
if ( V_28 -> V_65 == V_28 -> V_66 &&
V_100 >= F_40 ( V_28 -> V_40 ) )
V_58 = F_27 ( V_44 , V_7 , V_28 , V_86 , V_87 ) ;
else
V_58 = F_38 ( V_44 , V_7 , V_28 , V_86 , V_87 ) ;
return V_58 ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_109 * V_110 )
{
struct V_20 * V_28 , * V_111 ;
F_42 (pkt, pkt_next, list, list) {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_67 ; V_29 ++ )
F_32 ( V_3 , V_7 , V_28 , V_29 ) ;
if ( V_28 -> V_112 )
F_9 ( V_28 ) ;
else
F_43 ( V_7 -> V_19 , V_28 ) ;
}
F_3 ( V_110 ) ;
}
static int F_44 ( const struct V_43 * V_44 ,
struct V_113 * V_114 ,
struct V_1 * V_7 ,
const struct V_85 * V_86 ,
unsigned long V_87 ,
struct V_109 * V_110 ,
int * V_115 , int * V_116 )
{
unsigned long V_107 = 0 ;
int V_58 = 0 ;
int V_117 = 0 ;
T_6 * V_118 ;
T_2 V_38 ;
struct V_20 * V_28 = NULL ;
T_3 V_31 ;
T_3 V_119 ;
T_5 V_10 = V_7 -> V_10 ;
T_1 V_65 ;
while ( V_107 < V_87 && V_117 < * V_115 ) {
const unsigned long V_40 = ( unsigned long ) V_86 [ V_107 ] . V_91 ;
const unsigned long V_120 = V_107 ;
unsigned V_121 ;
unsigned V_122 ;
int V_123 = 0 ;
int V_100 = 0 ;
int V_66 = 0 ;
int V_61 = 0 ;
int V_90 ;
V_31 = V_86 [ V_107 ] . V_92 ;
V_119 = V_31 >> 2 ;
if ( V_31 < V_124 ||
V_31 > V_106 || V_31 & 3 || V_40 & 3 ) {
V_58 = - V_125 ;
goto V_126;
}
V_118 = F_11 ( V_7 , V_31 , & V_38 ) ;
if ( ! V_118 ) {
V_58 = - V_59 ;
goto V_126;
}
V_90 = F_30 ( V_118 , V_86 [ V_107 ] . V_91 , V_31 ) ;
if ( V_90 ) {
V_58 = - V_69 ;
goto V_127;
}
V_122 = V_119 - 1 ;
V_121 = F_24 ( * V_118 ) & 0xFFFF ;
if ( V_121 < V_122 ) {
V_58 = - V_125 ;
goto V_127;
}
V_107 ++ ;
while ( V_122 < V_121 && V_107 < V_87 ) {
const T_3 V_128 = V_86 [ V_107 ] . V_92 ;
const unsigned long V_129 =
( unsigned long ) V_86 [ V_107 ] . V_91 ;
if ( V_128 & 3 || V_129 & 3 || ! V_128 ) {
V_58 = - V_125 ;
goto V_127;
}
V_100 += F_31 ( & V_86 [ V_107 ] ) ;
V_66 += V_128 ;
V_122 += V_128 >> 2 ;
V_107 ++ ;
V_123 ++ ;
}
if ( V_122 != V_121 ) {
V_58 = - V_125 ;
goto V_127;
}
V_65 = ( ( F_24 ( * V_118 ) ) >> 16 ) & 0xFFFF ;
if ( ( ( V_65 ? V_65 : V_66 ) + V_31 ) >
V_114 -> V_130 ) {
V_58 = - V_125 ;
goto V_127;
}
if ( V_65 ) {
int V_131 , V_132 , V_133 ;
V_133 = V_100 * ( ( 2 * V_106 / V_65 ) + 1 ) ;
V_131 = sizeof( * V_28 ) + sizeof( V_28 -> V_40 [ 0 ] ) * V_133 ;
V_61 = ( ( ( F_24 ( V_118 [ 7 ] ) >>
V_81 ) &
V_134 ) !=
V_134 ) ;
if ( V_61 )
V_132 = V_86 [ V_107 ] . V_92 ;
else
V_132 = 0 ;
V_28 = F_2 ( V_131 + V_132 , V_8 ) ;
if ( ! V_28 ) {
V_58 = - V_59 ;
goto V_127;
}
V_28 -> V_112 = 1 ;
V_28 -> V_65 = V_65 ;
V_28 -> V_68 = V_133 + F_40 ( V_28 -> V_40 ) ;
if ( V_61 ) {
char * V_62 = ( char * ) V_28 + V_131 ;
V_90 = F_30 ( V_62 ,
V_86 [ V_107 ] . V_91 , V_132 ) ;
if ( V_90 ) {
V_58 = - V_69 ;
goto V_108;
}
V_28 -> V_62 =
(struct V_135 * ) V_62 ;
V_28 -> V_71 = V_132 /
sizeof( struct V_135 ) ;
V_28 -> V_63 = 0 ;
V_107 ++ ;
}
* V_118 = F_26 ( F_24 ( * V_118 ) & 0x0000FFFF ) ;
} else {
V_28 = F_45 ( V_7 -> V_19 , V_8 ) ;
if ( ! V_28 ) {
V_58 = - V_59 ;
goto V_127;
}
V_28 -> V_112 = 0 ;
V_28 -> V_65 = V_66 ;
V_28 -> V_68 = F_40 ( V_28 -> V_40 ) ;
}
V_28 -> V_66 = V_66 ;
V_28 -> V_64 = 0 ;
V_28 -> V_10 = V_10 ;
V_28 -> V_61 = V_61 ;
F_10 ( V_28 , 0 ,
0 , V_31 ,
1 , 0 ,
0 , 0 ,
NULL , V_118 ,
V_38 , V_31 ) ;
V_28 -> V_70 = 0 ;
V_28 -> V_67 = 1 ;
if ( V_123 ) {
V_58 = F_39 ( V_44 , V_7 , V_28 ,
V_86 + V_120 + 1 ,
V_123 , V_100 ) ;
if ( V_58 < 0 )
goto V_108;
} else {
V_28 -> V_40 [ 0 ] . V_33 = 1 ;
if ( V_38 == 0 ) {
V_38 = F_18 ( & V_44 -> V_56 -> V_3 ,
V_118 , V_31 , V_57 ) ;
if ( F_15 ( & V_44 -> V_56 -> V_3 ,
V_38 ) ) {
V_58 = - V_59 ;
goto V_108;
}
V_28 -> V_40 [ 0 ] . V_40 = V_38 ;
V_28 -> V_40 [ 0 ] . V_35 = 1 ;
}
}
V_10 ++ ;
V_117 ++ ;
V_28 -> V_7 = V_7 ;
V_28 -> V_70 = 0 ;
* V_116 += V_28 -> V_67 ;
F_46 ( & V_28 -> V_110 , V_110 ) ;
}
* V_115 = V_117 ;
V_58 = V_107 ;
goto V_9;
V_108:
if ( V_28 -> V_112 )
F_9 ( V_28 ) ;
else
F_43 ( V_7 -> V_19 , V_28 ) ;
V_127:
if ( V_38 )
F_35 ( V_7 -> V_23 , V_118 , V_38 ) ;
else
F_9 ( V_118 ) ;
V_126:
F_41 ( & V_44 -> V_56 -> V_3 , V_7 , V_110 ) ;
V_9:
return V_58 ;
}
static void F_47 ( struct V_1 * V_7 ,
T_5 V_136 )
{
V_7 -> V_11 = V_136 ;
}
static int F_48 ( struct V_113 * V_114 ,
struct V_1 * V_7 )
{
struct V_43 * V_44 = V_114 -> V_44 ;
struct V_109 V_126 ;
struct V_20 * V_28 ;
struct V_20 * V_137 ;
unsigned long V_75 ;
int V_58 = 0 ;
if ( ! V_7 -> V_13 )
return 0 ;
F_3 ( & V_126 ) ;
F_49 ( & V_7 -> V_16 , V_75 ) ;
F_42 (pkt, pkt_prev, &pq->sent, list) {
T_7 V_138 = V_114 -> V_139 - V_28 -> V_14 ;
if ( V_138 < 0 )
break;
F_50 ( & V_28 -> V_110 , & V_126 ) ;
V_58 ++ ;
V_7 -> V_13 -- ;
}
F_51 ( & V_7 -> V_16 , V_75 ) ;
if ( ! F_52 ( & V_126 ) ) {
T_5 V_10 ;
V_28 = F_53 ( V_126 . V_140 ,
struct V_20 , V_110 ) ;
V_10 = V_28 -> V_10 ;
F_41 ( & V_44 -> V_56 -> V_3 , V_7 , & V_126 ) ;
F_47 ( V_7 , V_10 ) ;
}
return V_58 ;
}
void F_54 ( struct V_1 * V_7 )
{
if ( ! V_7 )
return;
F_8 ( V_7 -> V_19 ) ;
F_55 ( V_7 -> V_23 ) ;
F_9 ( V_7 ) ;
}
static int F_56 ( struct V_113 * V_114 )
{
int V_58 ;
unsigned long V_75 ;
F_49 ( & V_114 -> V_141 , V_75 ) ;
V_58 = F_57 ( V_114 ) ;
F_51 ( & V_114 -> V_141 , V_75 ) ;
return V_58 ;
}
void F_58 ( struct V_113 * V_114 ,
struct V_1 * V_7 )
{
struct V_43 * V_44 = V_114 -> V_44 ;
unsigned long V_75 ;
int V_29 ;
if ( ! V_7 )
return;
for ( V_29 = 0 ; V_29 < V_142 ; V_29 ++ ) {
F_59 ( & V_7 -> V_17 ) ;
if ( ! V_7 -> V_12 && ! V_7 -> V_13 ) {
F_60 ( & V_7 -> V_17 ) ;
break;
}
F_56 ( V_114 ) ;
F_48 ( V_114 , V_7 ) ;
F_60 ( & V_7 -> V_17 ) ;
F_61 ( 10 ) ;
}
if ( V_7 -> V_12 || V_7 -> V_13 ) {
struct V_20 * V_28 ;
struct V_20 * V_137 ;
struct V_109 V_126 ;
F_59 ( & V_7 -> V_17 ) ;
F_49 ( & V_114 -> V_141 , V_75 ) ;
if ( V_7 -> V_12 ) {
F_42 (pkt, pkt_prev,
&ppd->sdma_userpending, list) {
if ( V_28 -> V_7 == V_7 ) {
F_50 ( & V_28 -> V_110 , & V_7 -> V_15 ) ;
V_7 -> V_12 -- ;
V_7 -> V_13 ++ ;
}
}
}
F_51 ( & V_114 -> V_141 , V_75 ) ;
F_62 ( V_44 , L_3 ) ;
F_3 ( & V_126 ) ;
F_63 ( & V_7 -> V_15 , & V_126 ) ;
V_7 -> V_13 = 0 ;
F_41 ( & V_44 -> V_56 -> V_3 , V_7 , & V_126 ) ;
F_60 ( & V_7 -> V_17 ) ;
}
}
static inline T_8 F_64 ( T_9 V_143 ,
T_10 V_40 , T_10 V_144 , T_10 V_145 )
{
return F_65 (
( ( V_40 & 0xfffffffcULL ) << 32 ) |
( ( V_143 & 3ULL ) << 30 ) |
( ( V_144 & 0x7ffULL ) << 16 ) |
( V_145 & 0x7ffULL ) ) ;
}
static inline T_8 F_66 ( T_8 V_146 )
{
return V_146 | F_65 ( 1ULL << 12 ) ;
}
static inline T_8 F_67 ( T_8 V_146 )
{
return V_146 | F_65 ( 1ULL << 11 | 1ULL << 13 ) ;
}
static inline T_8 F_68 ( T_10 V_40 )
{
return F_65 ( V_40 >> 32 ) ;
}
static void F_69 ( struct V_113 * V_114 ,
struct V_20 * V_28 , int V_107 ,
unsigned V_147 , T_1 V_148 , T_9 V_143 )
{
const T_10 V_40 = ( T_10 ) V_28 -> V_40 [ V_107 ] . V_40 +
( T_10 ) V_28 -> V_40 [ V_107 ] . V_30 ;
const T_10 V_144 = ( T_10 ) V_28 -> V_40 [ V_107 ] . V_41 / 4 ;
T_8 * V_149 ;
T_8 V_150 ;
V_149 = & V_114 -> V_151 [ V_148 ] . V_152 [ 0 ] ;
V_150 = F_64 ( V_143 , V_40 , V_144 , V_147 ) ;
if ( V_28 -> V_40 [ V_107 ] . V_32 )
V_150 = F_66 ( V_150 ) ;
if ( V_28 -> V_40 [ V_107 ] . V_33 ) {
V_150 = F_67 ( V_150 ) ;
if ( V_114 -> V_153 ) {
V_150 |= F_65 ( 1ULL << 15 ) ;
V_114 -> V_153 = 0 ;
}
}
V_149 [ 0 ] = V_150 ;
V_149 [ 1 ] = F_68 ( V_40 ) ;
}
void F_70 ( struct V_113 * V_114 ,
struct V_109 * V_154 )
{
struct V_43 * V_44 = V_114 -> V_44 ;
T_1 V_155 , V_156 ;
T_1 V_148 , V_157 ;
T_9 V_143 , V_158 ;
V_155 = F_71 ( V_114 ) ;
if ( ! V_155 )
return;
V_159:
V_156 = 0 ;
V_157 = V_148 = V_114 -> V_160 ;
V_158 = V_143 = V_114 -> V_161 ;
while ( ! F_52 ( V_154 ) ) {
struct V_20 * V_28 =
F_53 ( V_154 -> V_162 , struct V_20 ,
V_110 ) ;
int V_29 , V_102 , V_136 = 0 ;
unsigned V_147 = 0 ;
T_1 V_163 = V_148 ;
for ( V_29 = V_28 -> V_70 ; V_29 < V_28 -> V_67 && V_155 ; V_29 ++ ) {
F_69 ( V_114 , V_28 , V_29 , V_147 , V_148 , V_143 ) ;
V_147 += V_28 -> V_40 [ V_29 ] . V_41 >> 2 ;
if ( ++ V_148 == V_114 -> V_164 ) {
V_148 = 0 ;
++ V_143 ;
V_114 -> V_153 = 1 ;
} else if ( V_148 == ( V_114 -> V_164 >> 1 ) ) {
V_114 -> V_153 = 1 ;
}
V_155 -- ;
if ( V_28 -> V_40 [ V_29 ] . V_33 == 0 )
continue;
if ( V_147 > V_44 -> V_165 ) {
for ( V_102 = V_28 -> V_70 ; V_102 <= V_29 ; V_102 ++ ) {
V_114 -> V_151 [ V_163 ] . V_152 [ 0 ] |=
F_65 ( 1ULL << 14 ) ;
if ( ++ V_163 == V_114 -> V_164 )
V_163 = 0 ;
}
}
V_136 += V_29 + 1 - V_28 -> V_70 ;
V_28 -> V_70 = V_29 + 1 ;
V_157 = V_163 = V_148 ;
V_158 = V_143 ;
V_147 = 0 ;
}
V_114 -> V_166 += V_136 ;
V_156 += V_136 ;
if ( V_28 -> V_70 == V_28 -> V_67 ) {
V_28 -> V_14 = V_114 -> V_166 ;
V_28 -> V_7 -> V_14 = V_28 -> V_14 ;
V_28 -> V_7 -> V_12 -- ;
F_72 ( & V_28 -> V_7 -> V_16 ) ;
V_28 -> V_7 -> V_13 ++ ;
F_50 ( & V_28 -> V_110 , & V_28 -> V_7 -> V_15 ) ;
F_73 ( & V_28 -> V_7 -> V_16 ) ;
}
if ( ! V_155 || ( V_156 << 2 ) > V_114 -> V_164 )
break;
}
if ( V_114 -> V_160 != V_157 ) {
V_114 -> V_161 = V_158 ;
V_44 -> V_167 ( V_114 , V_157 ) ;
}
if ( V_155 && ! F_52 ( V_154 ) )
goto V_159;
return;
}
static int F_74 ( struct V_113 * V_114 ,
struct V_1 * V_7 ,
struct V_109 * V_154 , int V_168 )
{
int V_58 = 0 ;
unsigned long V_75 ;
if ( F_75 ( ! ( V_114 -> V_169 & V_170 ) ) )
return - V_171 ;
F_49 ( & V_114 -> V_141 , V_75 ) ;
if ( F_75 ( ! F_76 ( V_114 ) ) ) {
V_58 = - V_171 ;
goto V_172;
}
V_7 -> V_12 += V_168 ;
F_77 ( V_154 , & V_114 -> V_173 ) ;
F_70 ( V_114 , & V_114 -> V_173 ) ;
V_172:
F_51 ( & V_114 -> V_141 , V_75 ) ;
return V_58 ;
}
int F_78 ( struct V_174 * V_175 ,
struct V_1 * V_7 ,
const struct V_85 * V_86 ,
unsigned long V_176 )
{
struct V_43 * V_44 = V_175 -> V_44 ;
struct V_113 * V_114 = V_175 -> V_114 ;
int V_58 = 0 ;
struct V_109 V_110 ;
int V_117 = 0 ;
F_3 ( & V_110 ) ;
F_59 ( & V_7 -> V_17 ) ;
if ( ! F_79 ( V_114 ) )
goto V_177;
if ( V_7 -> V_14 > V_114 -> V_139 )
F_56 ( V_114 ) ;
if ( V_7 -> V_13 )
F_48 ( V_114 , V_7 ) ;
while ( V_176 ) {
int V_178 = 8 ;
int V_116 = 0 ;
V_58 = F_44 ( V_44 , V_114 , V_7 ,
V_86 , V_176 , & V_110 , & V_178 , & V_116 ) ;
if ( V_58 < 0 )
goto V_177;
else {
V_176 -= V_58 ;
V_86 += V_58 ;
}
if ( ! F_52 ( & V_110 ) ) {
if ( F_71 ( V_114 ) < V_116 ) {
F_56 ( V_114 ) ;
if ( V_7 -> V_13 )
F_48 ( V_114 , V_7 ) ;
}
V_58 = F_74 ( V_114 , V_7 , & V_110 , V_178 ) ;
if ( V_58 < 0 )
goto V_177;
else {
V_117 += V_178 ;
V_7 -> V_10 += V_178 ;
}
}
}
V_177:
if ( ! F_52 ( & V_110 ) )
F_41 ( & V_44 -> V_56 -> V_3 , V_7 , & V_110 ) ;
F_60 ( & V_7 -> V_17 ) ;
return ( V_58 < 0 ) ? V_58 : V_117 ;
}
int F_80 ( struct V_113 * V_114 ,
struct V_1 * V_7 )
{
int V_58 = 0 ;
F_59 ( & V_7 -> V_17 ) ;
F_56 ( V_114 ) ;
V_58 = F_48 ( V_114 , V_7 ) ;
F_60 ( & V_7 -> V_17 ) ;
return V_58 ;
}
T_5 F_81 ( const struct V_1 * V_7 )
{
return V_7 ? V_7 -> V_11 : 0 ;
}
T_5 F_82 ( struct V_1 * V_7 )
{
return V_7 ? V_7 -> V_10 : 0 ;
}
