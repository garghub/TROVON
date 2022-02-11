static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
do {
if ( F_2 ( V_4 ) ) {
break;
}
if ( V_2 -> V_5 . V_6 != NULL ) {
F_3 ( V_7 , ( L_1 ,
V_2 -> V_8 , F_4 ( V_4 ) ) ) ;
V_2 -> V_5 . V_6 ( V_2 -> V_5 . V_9 ,
V_4 ) ;
F_5 ( V_4 ) ;
} else {
struct V_10 * V_11 ;
do {
V_11 = F_6 ( V_4 ) ;
F_3 ( V_7 , ( L_2 , \
V_2 -> V_8 , ( unsigned long ) ( V_11 ) ) ) ;
V_2 -> V_5 . V_12 ( V_2 -> V_5 . V_9 , V_11 ) ;
} while ( ! F_2 ( V_4 ) );
}
} while ( false );
}
static INLINE void F_7 ( struct V_13 * V_14 , struct V_1 * V_2 , struct V_10 * V_11 )
{
V_11 -> V_15 = NULL ;
if ( V_11 -> V_16 ) {
F_3 ( V_17 ,
( L_3 ,
V_11 -> V_16 , V_11 -> V_18 , V_11 -> V_19 , V_11 -> V_20 . V_21 . V_22 ) ) ;
F_8 ( V_14 ) ;
V_2 -> V_23 . V_24 += V_11 -> V_20 . V_21 . V_22 ;
V_2 -> V_23 . V_25 = F_4 ( & V_2 -> V_26 ) ;
F_9 ( V_14 ,
V_27 ,
L_4 ,
V_14 -> V_28 -> V_29 ) ;
F_10 ( V_14 ) ;
}
V_11 -> V_30 += V_31 ;
}
static void F_11 ( void * V_32 , struct V_10 * V_11 )
{
struct V_13 * V_14 = (struct V_13 * ) V_32 ;
struct V_1 * V_2 = & V_14 -> V_33 [ V_11 -> V_18 ] ;
struct V_3 V_34 ;
F_7 ( V_14 , V_2 , V_11 ) ;
F_12 ( & V_34 , V_11 ) ;
F_13 ( V_2 , & V_34 ) ;
}
int F_14 ( struct V_13 * V_14 , struct V_10 * V_11 )
{
int V_35 ;
bool V_36 = false ;
if ( V_11 -> V_15 == NULL ) {
V_36 = true ;
}
F_3 ( V_7 ,
( L_5 ,
V_11 -> V_19 + ( V_37 ) V_31 ,
V_36 ? L_6 : L_7 ) ) ;
V_35 = F_15 ( & V_14 -> V_38 ,
V_11 ,
V_11 -> V_19 + V_31 ) ;
if ( V_36 ) {
V_11 -> V_30 += V_31 ;
}
return V_35 ;
}
static INLINE void F_16 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_3 * V_39 )
{
int V_40 ;
int V_41 ;
T_1 V_42 ;
struct V_10 * V_11 ;
unsigned int V_43 ;
F_3 ( V_7 , ( L_8 ) ) ;
while ( true ) {
V_42 = 0 ;
V_11 = F_17 ( & V_2 -> V_26 ) ;
if ( V_11 == NULL ) {
break;
}
F_3 ( V_7 , ( L_9 ,
( unsigned long ) V_11 , F_4 ( & V_2 -> V_26 ) ) ) ;
V_43 = F_18 ( & V_14 -> V_38 , V_11 -> V_19 + V_31 ) ;
if ( V_43 <= V_14 -> V_44 ) {
V_40 = 1 ;
} else {
V_40 = V_43 / V_14 -> V_44 ;
V_41 = V_43 % V_14 -> V_44 ;
if ( V_41 ) {
V_40 ++ ;
}
}
F_3 ( V_7 , ( L_10 ,
V_40 , V_2 -> V_23 . V_45 ) ) ;
if ( V_2 -> V_23 . V_45 < V_40 ) {
if ( V_11 -> V_18 == V_46 ) {
break;
}
V_2 -> V_23 . V_47 =
V_40 - V_2 -> V_23 . V_45 ;
F_9 ( V_14 ,
V_48 ,
L_11 ,
& V_2 -> V_23 ) ;
V_2 -> V_23 . V_47 = 0 ;
if ( V_2 -> V_23 . V_45 < V_40 ) {
F_3 ( V_7 ,
( L_12 ,
V_11 -> V_18 ) ) ;
break;
}
}
V_2 -> V_23 . V_45 -= V_40 ;
F_19 ( V_2 , V_49 , V_40 ) ;
if ( V_2 -> V_23 . V_45 < V_2 -> V_23 . V_50 ) {
V_2 -> V_23 . V_47 =
V_2 -> V_23 . V_50 - V_2 -> V_23 . V_45 ;
F_9 ( V_14 ,
V_48 ,
L_11 ,
& V_2 -> V_23 ) ;
V_2 -> V_23 . V_47 = 0 ;
if ( V_2 -> V_23 . V_45 < V_2 -> V_23 . V_50 ) {
V_42 |= V_51 ;
F_19 ( V_2 , V_52 , 1 ) ;
F_3 ( V_7 , ( L_13 ) ) ;
}
}
V_11 = F_6 ( & V_2 -> V_26 ) ;
V_11 -> V_20 . V_21 . V_22 = V_40 ;
V_11 -> V_15 = F_11 ;
V_11 -> V_9 = V_14 ;
F_19 ( V_2 , V_53 , 1 ) ;
V_11 -> V_20 . V_21 . V_54 = V_42 ;
V_11 -> V_20 . V_21 . V_55 = V_2 -> V_55 ;
V_2 -> V_55 ++ ;
F_20 ( V_39 , V_11 ) ;
}
F_3 ( V_7 , ( L_14 ) ) ;
}
static void F_21 ( struct V_56 * V_57 )
{
int V_58 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = (struct V_1 * ) V_57 -> V_32 ;
struct V_13 * V_14 = (struct V_13 * ) V_2 -> V_14 ;
int V_35 = 0 ;
struct V_3 V_59 ;
F_5 ( & V_59 ) ;
F_3 ( V_7 , ( L_15 ,
V_57 -> V_60 , V_57 -> V_61 ) ) ;
F_22 ( V_57 ) ;
if ( V_57 -> V_62 ) {
F_3 ( V_17 , ( L_16 , V_57 -> V_62 ) ) ;
V_35 = V_63 ;
}
for ( V_58 = 0 ; V_58 < V_57 -> V_61 ; V_58 ++ ) {
V_11 = (struct V_10 * ) ( V_57 -> V_64 [ V_58 ] . V_65 [ 0 ] ) ;
F_23 ( V_11 != NULL ) ;
V_11 -> V_16 = V_35 ;
F_7 ( V_14 , V_2 , V_11 ) ;
F_20 ( & V_59 , V_11 ) ;
}
F_24 ( & V_14 -> V_38 , V_57 ) ;
F_13 ( V_2 , & V_59 ) ;
F_3 ( V_7 , ( L_17 ) ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_39 ,
int * V_66 ,
int * V_67 )
{
int V_68 ;
unsigned int V_69 ;
struct V_56 * V_57 = NULL ;
int V_58 , V_70 ;
unsigned int V_43 ;
struct V_10 * V_11 ;
bool V_71 = false ;
int V_72 = 0 ;
int V_73 = 0 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_74 = 0 ;
int V_75 ;
F_3 ( V_7 , ( L_18 ) ) ;
while ( ! V_71 ) {
V_68 = F_4 ( V_39 ) ;
V_68 = F_26 ( V_68 , V_14 -> V_76 ) ;
if ( V_68 < V_77 ) {
break;
}
V_57 = F_27 ( & V_14 -> V_38 ) ;
if ( V_57 == NULL ) {
F_3 ( V_7 , ( L_19 ) ) ;
break;
}
F_3 ( V_7 , ( L_20 , V_68 ) ) ;
V_57 -> V_60 = 0 ;
V_57 -> V_61 = 0 ;
V_70 = 0 ;
V_69 = F_28 ( & V_14 -> V_38 ) ;
for ( V_58 = 0 ; V_58 < V_68 ; V_58 ++ ) {
V_57 -> V_64 [ V_58 ] . V_65 [ 0 ] = NULL ;
V_11 = F_17 ( V_39 ) ;
if ( V_11 == NULL ) {
F_23 ( false ) ;
break;
}
V_75 = 0 ;
V_43 = F_18 ( & V_14 -> V_38 ,
V_11 -> V_19 + V_31 ) ;
V_74 = V_43 % V_14 -> V_44 ;
if ( V_74 != 0 ) {
if ( V_2 -> V_78 & V_79 ) {
if ( V_43 < V_14 -> V_44 ) {
V_75 = V_14 -> V_44 - V_43 ;
} else {
V_75 = V_74 ;
}
if ( ( V_75 > 0 ) && ( V_75 <= 255 ) ) {
V_43 += V_75 ;
} else {
V_11 = NULL ;
}
} else {
V_11 = NULL ;
}
}
if ( NULL == V_11 ) {
V_71 = true ;
break;
}
if ( V_69 < V_43 ) {
break;
}
V_69 -= V_43 ;
V_11 = F_6 ( V_39 ) ;
V_57 -> V_64 [ V_58 ] . V_65 [ 0 ] = V_11 ;
F_29 ( V_11 ,
V_11 -> V_20 . V_21 . V_54 | V_80 ,
V_75 ,
V_11 -> V_20 . V_21 . V_55 ) ;
V_57 -> V_64 [ V_58 ] . V_30 = V_11 -> V_30 ;
V_57 -> V_64 [ V_58 ] . V_81 = V_43 ;
F_23 ( V_43 ) ;
V_57 -> V_60 += V_43 ;
V_57 -> V_61 ++ ;
V_70 ++ ;
F_3 ( V_7 , ( L_21 ,
V_58 , ( unsigned long ) V_11 , V_43 , V_69 ) ) ;
}
if ( V_70 >= V_77 ) {
V_57 -> V_82 = F_21 ;
V_57 -> V_32 = V_2 ;
V_72 ++ ;
V_73 += V_70 ;
V_70 = 0 ;
F_3 ( V_7 , ( L_22 ,
V_57 -> V_60 , V_57 -> V_61 ) ) ;
F_30 ( & V_14 -> V_38 , V_57 , V_83 , V_84 ) ;
V_57 = NULL ;
continue;
}
if ( V_57 != NULL ) {
if ( V_70 > 0 ) {
for ( V_58 = ( V_70 - 1 ) ; V_58 >= 0 ; V_58 -- ) {
V_11 = (struct V_10 * ) ( V_57 -> V_64 [ V_58 ] . V_65 [ 0 ] ) ;
if ( V_11 != NULL ) {
F_31 ( V_11 ) ;
F_32 ( V_39 , V_11 ) ;
}
}
}
F_24 ( & V_14 -> V_38 , V_57 ) ;
}
break;
}
* V_66 = V_72 ;
* V_67 = V_73 ;
F_3 ( V_7 , ( L_23 , V_72 ) ) ;
return;
}
static T_2 F_33 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_3 * V_85 )
{
struct V_3 V_86 ;
struct V_10 * V_11 ;
int V_72 ;
int V_87 ;
int V_88 ;
T_2 V_89 = V_90 ;
F_3 ( V_7 , ( L_24 ,
( unsigned long ) V_85 ,
( V_85 == NULL ) ? 0 : F_4 ( V_85 ) ) ) ;
F_5 ( & V_86 ) ;
do {
if ( NULL == V_85 ) {
break;
}
if ( F_2 ( V_85 ) ) {
V_89 = V_91 ;
break;
}
if ( F_4 ( & V_2 -> V_26 ) >= V_2 -> V_92 ) {
V_88 = F_4 ( V_85 ) ;
} else {
V_88 = F_4 ( & V_2 -> V_26 ) ;
V_88 += F_4 ( V_85 ) ;
V_88 -= V_2 -> V_92 ;
}
if ( V_88 > 0 ) {
F_3 ( V_7 ,
( L_25 ,
V_2 -> V_8 , V_88 , F_4 ( & V_2 -> V_26 ) , V_2 -> V_92 ) ) ;
}
if ( ( V_88 <= 0 ) || ( V_2 -> V_5 . V_93 == NULL ) ) {
F_34 ( & V_86 , V_85 ) ;
} else {
int V_58 ;
int V_94 = F_4 ( V_85 ) - V_88 ;
F_23 ( V_94 >= 0 ) ;
for ( V_58 = 0 ; V_58 < V_94 ; V_58 ++ ) {
V_11 = F_6 ( V_85 ) ;
F_23 ( V_11 != NULL ) ;
F_20 ( & V_86 , V_11 ) ;
}
F_35 (&pCallersSendQueue->QueueHead, pPacket, struct htc_packet, ListLink) {
F_3 ( V_7 , ( L_26 ,
( unsigned long ) V_11 ) ) ;
if ( V_2 -> V_5 . V_93 ( V_2 -> V_5 . V_9 ,
V_11 ) == V_95 ) {
F_19 ( V_2 , V_96 , 1 ) ;
} else {
F_36 ( V_85 , V_11 ) ;
F_20 ( & V_86 , V_11 ) ;
}
} V_97 ;
if ( F_2 ( & V_86 ) ) {
V_89 = V_91 ;
break;
}
}
} while ( false );
if ( V_89 != V_90 ) {
F_3 ( V_7 , ( L_27 ) ) ;
return V_89 ;
}
F_8 ( V_14 ) ;
if ( ! F_2 ( & V_86 ) ) {
F_34 ( & V_2 -> V_26 , & V_86 ) ;
F_23 ( F_2 ( & V_86 ) ) ;
F_5 ( & V_86 ) ;
}
V_2 -> V_98 ++ ;
if ( V_2 -> V_98 > 1 ) {
V_2 -> V_98 -- ;
F_10 ( V_14 ) ;
F_3 ( V_7 , ( L_28 ) ) ;
return V_90 ;
}
while ( true ) {
if ( F_4 ( & V_2 -> V_26 ) == 0 ) {
break;
}
F_16 ( V_14 , V_2 , & V_86 ) ;
if ( F_4 ( & V_86 ) == 0 ) {
break;
}
F_10 ( V_14 ) ;
V_72 = 0 ;
V_87 = 0 ;
while ( true ) {
if ( ( V_14 -> V_99 ) &&
( F_4 ( & V_86 ) >= V_77 ) ) {
int V_100 , V_101 ;
F_25 ( V_2 , & V_86 , & V_100 , & V_101 ) ;
V_72 += V_100 ;
V_87 += V_101 ;
}
V_11 = F_6 ( & V_86 ) ;
if ( NULL == V_11 ) {
break;
}
F_29 ( V_11 ,
V_11 -> V_20 . V_21 . V_54 ,
0 ,
V_11 -> V_20 . V_21 . V_55 ) ;
F_14 ( V_14 , V_11 ) ;
}
F_8 ( V_14 ) ;
F_19 ( V_2 , V_102 , V_72 ) ;
F_19 ( V_2 , V_103 , V_87 ) ;
}
V_2 -> V_98 = 0 ;
F_10 ( V_14 ) ;
F_3 ( V_7 , ( L_27 ) ) ;
return V_90 ;
}
int F_37 ( T_3 V_104 , struct V_3 * V_105 )
{
struct V_13 * V_14 = F_38 ( V_104 ) ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
F_3 ( V_7 , ( L_29 ,
( unsigned long ) V_105 , F_4 ( V_105 ) ) ) ;
V_11 = F_17 ( V_105 ) ;
if ( NULL == V_11 ) {
F_3 ( V_7 , ( L_30 ) ) ;
return V_106 ;
}
F_39 ( V_11 -> V_18 < V_107 ) ;
V_2 = & V_14 -> V_33 [ V_11 -> V_18 ] ;
F_33 ( V_14 , V_2 , V_105 ) ;
if ( ! F_2 ( V_105 ) ) {
F_40 (pPktQueue,pPacket) {
if ( F_41 ( V_14 ) ) {
V_11 -> V_16 = V_108 ;
} else {
V_11 -> V_16 = V_109 ;
}
} V_110 ;
F_13 ( V_2 , V_105 ) ;
}
F_3 ( V_7 , ( L_30 ) ) ;
return 0 ;
}
int F_42 ( T_3 V_104 , struct V_10 * V_11 )
{
struct V_3 V_111 ;
F_3 ( V_7 ,
( L_31 ,
V_11 -> V_18 , ( unsigned long ) V_11 -> V_30 , V_11 -> V_19 ) ) ;
F_12 ( & V_111 , V_11 ) ;
return F_37 ( V_104 , & V_111 ) ;
}
static INLINE void F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_112 * V_113 ;
F_3 ( V_7 , ( L_32 ) ) ;
V_113 = V_14 -> V_28 ;
while ( V_113 != NULL ) {
V_2 = (struct V_1 * ) V_113 -> V_114 ;
if ( F_4 ( & V_2 -> V_26 ) > 0 ) {
F_3 ( V_7 , ( L_33 ,
V_113 -> V_18 , V_2 -> V_23 . V_45 , F_4 ( & V_2 -> V_26 ) ) ) ;
F_33 ( V_14 , V_2 , NULL ) ;
}
V_113 = V_113 -> V_29 ;
}
F_3 ( V_7 , ( L_34 ) ) ;
}
void F_44 ( struct V_13 * V_14 , T_4 * V_115 , int V_116 , T_5 V_117 )
{
int V_58 ;
struct V_1 * V_2 ;
int V_118 = 0 ;
bool V_119 = false ;
F_3 ( V_7 , ( L_35 , V_116 ) ) ;
F_8 ( V_14 ) ;
for ( V_58 = 0 ; V_58 < V_116 ; V_58 ++ , V_115 ++ ) {
if ( V_115 -> V_120 >= V_107 ) {
F_39 ( false ) ;
break;
}
V_2 = & V_14 -> V_33 [ V_115 -> V_120 ] ;
F_3 ( V_7 , ( L_36 ,
V_115 -> V_120 , V_115 -> V_121 ) ) ;
F_19 ( V_2 , V_122 , 1 ) ;
F_19 ( V_2 , V_123 , V_115 -> V_121 ) ;
if ( V_117 == V_115 -> V_120 ) {
F_19 ( V_2 , V_124 , V_115 -> V_121 ) ;
F_19 ( V_2 , V_125 , 1 ) ;
} else if ( V_117 == V_46 ) {
F_19 ( V_2 , V_126 , V_115 -> V_121 ) ;
F_19 ( V_2 , V_127 , 1 ) ;
} else {
F_19 ( V_2 , V_128 , V_115 -> V_121 ) ;
F_19 ( V_2 , V_129 , 1 ) ;
}
if ( V_46 == V_115 -> V_120 ) {
V_2 -> V_23 . V_45 += V_115 -> V_121 ;
} else {
V_2 -> V_23 . V_24 += V_115 -> V_121 ;
V_119 = true ;
}
V_2 -> V_23 . V_25 = F_4 ( & V_2 -> V_26 ) ;
V_118 += V_115 -> V_121 ;
}
F_3 ( V_7 , ( L_37 , V_118 ) ) ;
if ( V_119 ) {
F_9 ( V_14 ,
V_27 ,
L_4 ,
V_14 -> V_28 -> V_29 ) ;
}
F_10 ( V_14 ) ;
if ( V_118 ) {
F_43 ( V_14 ) ;
}
F_3 ( V_7 , ( L_38 ) ) ;
}
static void F_45 ( struct V_13 * V_14 , struct V_1 * V_2 , T_6 V_130 )
{
struct V_10 * V_11 ;
struct V_3 V_131 ;
struct V_3 V_34 ;
F_5 ( & V_131 ) ;
F_8 ( V_14 ) ;
F_35 (&pEndpoint->TxQueue.QueueHead, pPacket, struct htc_packet, ListLink) {
if ( ( V_132 == V_130 ) || ( V_130 == V_11 -> V_20 . V_21 . V_130 ) ) {
F_36 ( & V_2 -> V_26 , V_11 ) ;
F_20 ( & V_131 , V_11 ) ;
}
} V_97 ;
F_10 ( V_14 ) ;
while ( 1 ) {
V_11 = F_6 ( & V_131 ) ;
if ( NULL == V_11 ) {
break;
}
V_11 -> V_16 = V_108 ;
F_3 ( V_133 , ( L_39 ,
( unsigned long ) V_11 , V_11 -> V_19 , V_11 -> V_18 , V_11 -> V_20 . V_21 . V_130 ) ) ;
F_12 ( & V_34 , V_11 ) ;
F_13 ( V_2 , & V_34 ) ;
}
}
void F_46 ( struct V_112 * V_134 )
{
F_3 ( V_135 , ( L_40 ,
V_134 -> V_18 , V_134 -> V_136 ) ) ;
F_3 ( V_135 , ( L_41 ,
( unsigned long ) V_134 , ( unsigned long ) V_134 -> V_29 , ( unsigned long ) V_134 -> V_137 ) ) ;
F_3 ( V_135 , ( L_42 , V_134 -> V_138 ) ) ;
F_3 ( V_135 , ( L_43 , V_134 -> V_139 ) ) ;
F_3 ( V_135 , ( L_44 , V_134 -> V_140 ) ) ;
F_3 ( V_135 , ( L_45 , V_134 -> V_45 ) ) ;
F_3 ( V_135 , ( L_46 , V_134 -> V_141 ) ) ;
F_3 ( V_135 , ( L_47 , V_134 -> V_47 ) ) ;
F_3 ( V_135 , ( L_48 , V_134 -> V_142 ) ) ;
F_3 ( V_135 , ( L_49 , V_134 -> V_50 ) ) ;
F_3 ( V_135 , ( L_50 , V_134 -> V_24 ) ) ;
F_3 ( V_135 , ( L_51 ,
F_4 ( & ( (struct V_1 * ) V_134 -> V_114 ) -> V_26 ) ) ) ;
F_3 ( V_135 , ( L_52 ) ) ;
}
void F_47 ( struct V_13 * V_14 )
{
struct V_112 * V_143 = V_14 -> V_28 ;
while ( V_143 != NULL ) {
F_46 ( V_143 ) ;
V_143 = V_143 -> V_29 ;
}
if ( V_14 -> V_144 != NULL ) {
F_9 ( V_14 ,
V_145 ,
L_53 ,
NULL ) ;
}
}
void F_48 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_58 ;
if ( F_49 ( V_133 ) ) {
F_47 ( V_14 ) ;
}
for ( V_58 = V_46 ; V_58 < V_107 ; V_58 ++ ) {
V_2 = & V_14 -> V_33 [ V_58 ] ;
if ( V_2 -> V_136 == 0 ) {
continue;
}
F_45 ( V_14 , V_2 , V_132 ) ;
}
}
void F_50 ( T_3 V_104 , T_5 V_18 , T_6 V_130 )
{
struct V_13 * V_14 = F_38 ( V_104 ) ;
struct V_1 * V_2 = & V_14 -> V_33 [ V_18 ] ;
if ( V_2 -> V_136 == 0 ) {
F_39 ( false ) ;
return;
}
F_45 ( V_14 , V_2 , V_130 ) ;
}
void F_51 ( T_3 V_104 ,
T_5 V_18 ,
bool V_146 )
{
struct V_13 * V_14 = F_38 ( V_104 ) ;
struct V_1 * V_2 = & V_14 -> V_33 [ V_18 ] ;
bool V_119 = false ;
if ( V_2 -> V_136 == 0 ) {
F_39 ( false ) ;
return;
}
F_8 ( V_14 ) ;
if ( V_146 ) {
if ( ! ( V_2 -> V_23 . V_138 & V_147 ) ) {
V_2 -> V_23 . V_138 |= V_147 ;
V_119 = true ;
}
} else {
if ( V_2 -> V_23 . V_138 & V_147 ) {
V_2 -> V_23 . V_138 &= ~ V_147 ;
V_119 = true ;
}
}
if ( V_119 ) {
V_2 -> V_23 . V_25 = F_4 ( & V_2 -> V_26 ) ;
F_9 ( V_14 ,
V_148 ,
L_54 ,
V_14 -> V_28 -> V_29 ) ;
}
F_10 ( V_14 ) ;
if ( V_119 && ! V_146 ) {
F_43 ( V_14 ) ;
}
}
bool F_52 ( T_3 V_104 ,
T_5 V_18 )
{
struct V_13 * V_14 = F_38 ( V_104 ) ;
struct V_1 * V_2 = & V_14 -> V_33 [ V_18 ] ;
if ( V_2 -> V_136 == 0 ) {
return false ;
}
if ( V_2 -> V_23 . V_138 & V_147 ) {
return true ;
}
return false ;
}
