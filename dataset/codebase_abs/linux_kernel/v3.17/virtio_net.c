static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 - 1 ) / 2 ;
}
static int F_2 ( int V_4 )
{
return V_4 * 2 + 1 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 / 2 ;
}
static int F_4 ( int V_5 )
{
return V_5 * 2 ;
}
static inline struct V_6 * V_6 ( struct V_7 * V_8 )
{
return (struct V_6 * ) V_8 -> V_9 ;
}
static void F_5 ( struct V_10 * V_11 , struct V_12 * V_12 )
{
struct V_12 * V_13 ;
for ( V_13 = V_12 ; V_13 -> V_14 ; V_13 = (struct V_12 * ) V_13 -> V_14 ) ;
V_13 -> V_14 = ( unsigned long ) V_11 -> V_15 ;
V_11 -> V_15 = V_12 ;
}
static struct V_12 * F_6 ( struct V_10 * V_11 , T_1 V_16 )
{
struct V_12 * V_17 = V_11 -> V_15 ;
if ( V_17 ) {
V_11 -> V_15 = (struct V_12 * ) V_17 -> V_14 ;
V_17 -> V_14 = 0 ;
} else
V_17 = F_7 ( V_16 ) ;
return V_17 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
F_9 ( V_2 ) ;
F_10 ( V_19 -> V_22 , F_1 ( V_2 ) ) ;
}
static unsigned int F_11 ( unsigned long V_23 )
{
unsigned int V_24 = V_23 & ( V_25 - 1 ) ;
return ( V_24 + 1 ) * V_25 ;
}
static void * F_12 ( unsigned long V_23 )
{
return ( void * ) ( V_23 & - V_25 ) ;
}
static unsigned long F_13 ( void * V_26 , unsigned int V_24 )
{
unsigned int V_27 = V_24 / V_25 ;
return ( unsigned long ) V_26 | ( V_27 - 1 ) ;
}
static struct V_7 * F_14 ( struct V_10 * V_11 ,
struct V_12 * V_12 , unsigned int V_28 ,
unsigned int V_29 , unsigned int V_24 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
unsigned int V_31 , V_32 , V_33 ;
char * V_17 ;
V_17 = F_15 ( V_12 ) + V_28 ;
V_8 = F_16 ( V_19 -> V_22 , V_34 ) ;
if ( F_17 ( ! V_8 ) )
return NULL ;
V_30 = V_6 ( V_8 ) ;
if ( V_19 -> V_35 ) {
V_32 = sizeof V_30 -> V_36 ;
V_33 = sizeof V_30 -> V_36 ;
} else {
V_32 = sizeof V_30 -> V_30 ;
V_33 = sizeof( struct V_37 ) ;
}
memcpy ( V_30 , V_17 , V_32 ) ;
V_29 -= V_32 ;
V_28 += V_33 ;
V_17 += V_33 ;
V_31 = V_29 ;
if ( V_31 > F_18 ( V_8 ) )
V_31 = F_18 ( V_8 ) ;
memcpy ( F_19 ( V_8 , V_31 ) , V_17 , V_31 ) ;
V_29 -= V_31 ;
V_28 += V_31 ;
if ( V_19 -> V_35 ) {
if ( V_29 )
F_20 ( V_8 , 0 , V_12 , V_28 , V_29 , V_24 ) ;
else
F_21 ( V_12 ) ;
return V_8 ;
}
if ( F_17 ( V_29 > V_38 * V_39 ) ) {
F_22 ( L_1 , V_8 -> V_22 -> V_40 ) ;
F_23 ( V_8 ) ;
return NULL ;
}
F_24 ( V_28 >= V_39 ) ;
while ( V_29 ) {
unsigned int V_41 = F_25 ( ( unsigned ) V_39 - V_28 , V_29 ) ;
F_20 ( V_8 , F_26 ( V_8 ) -> V_42 , V_12 , V_28 ,
V_41 , V_24 ) ;
V_29 -= V_41 ;
V_12 = (struct V_12 * ) V_12 -> V_14 ;
V_28 = 0 ;
}
if ( V_12 )
F_5 ( V_11 , V_12 ) ;
return V_8 ;
}
static struct V_7 * F_27 ( void * V_26 , unsigned int V_29 )
{
struct V_7 * V_8 = V_26 ;
V_29 -= sizeof( struct V_43 ) ;
F_28 ( V_8 , V_29 ) ;
return V_8 ;
}
static struct V_7 * F_29 ( struct V_44 * V_22 ,
struct V_10 * V_11 ,
void * V_26 ,
unsigned int V_29 )
{
struct V_12 * V_12 = V_26 ;
struct V_7 * V_8 = F_14 ( V_11 , V_12 , 0 , V_29 , V_39 ) ;
if ( F_17 ( ! V_8 ) )
goto V_45;
return V_8 ;
V_45:
V_22 -> V_46 . V_47 ++ ;
F_5 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_7 * F_30 ( struct V_44 * V_22 ,
struct V_10 * V_11 ,
unsigned long V_48 ,
unsigned int V_29 )
{
void * V_26 = F_12 ( V_48 ) ;
struct V_6 * V_30 = V_26 ;
int V_49 = V_30 -> V_36 . V_50 ;
struct V_12 * V_12 = F_31 ( V_26 ) ;
int V_28 = V_26 - F_15 ( V_12 ) ;
unsigned int V_24 = F_32 ( V_29 , F_11 ( V_48 ) ) ;
struct V_7 * V_51 = F_14 ( V_11 , V_12 , V_28 , V_29 , V_24 ) ;
struct V_7 * V_52 = V_51 ;
if ( F_17 ( ! V_52 ) )
goto V_53;
while ( -- V_49 ) {
int V_54 ;
V_48 = ( unsigned long ) F_33 ( V_11 -> V_2 , & V_29 ) ;
if ( F_17 ( ! V_48 ) ) {
F_34 ( L_2 ,
V_22 -> V_40 , V_49 , V_30 -> V_36 . V_50 ) ;
V_22 -> V_46 . V_55 ++ ;
goto V_56;
}
V_26 = F_12 ( V_48 ) ;
V_12 = F_31 ( V_26 ) ;
V_54 = F_26 ( V_52 ) -> V_42 ;
if ( F_17 ( V_54 == V_38 ) ) {
struct V_7 * V_57 = F_35 ( 0 , V_58 ) ;
if ( F_17 ( ! V_57 ) )
goto V_53;
if ( V_52 == V_51 )
F_26 ( V_52 ) -> V_59 = V_57 ;
else
V_52 -> V_60 = V_57 ;
V_52 = V_57 ;
V_51 -> V_24 += V_57 -> V_24 ;
V_54 = 0 ;
}
V_24 = F_32 ( V_29 , F_11 ( V_48 ) ) ;
if ( V_52 != V_51 ) {
V_51 -> V_61 += V_29 ;
V_51 -> V_29 += V_29 ;
V_51 -> V_24 += V_24 ;
}
V_28 = V_26 - F_15 ( V_12 ) ;
if ( F_36 ( V_52 , V_54 , V_12 , V_28 ) ) {
F_21 ( V_12 ) ;
F_37 ( V_52 , V_54 - 1 ,
V_29 , V_24 ) ;
} else {
F_20 ( V_52 , V_54 , V_12 ,
V_28 , V_29 , V_24 ) ;
}
}
F_38 ( & V_11 -> V_62 , V_51 -> V_29 ) ;
return V_51 ;
V_53:
F_21 ( V_12 ) ;
while ( -- V_49 ) {
V_48 = ( unsigned long ) F_33 ( V_11 -> V_2 , & V_29 ) ;
if ( F_17 ( ! V_48 ) ) {
F_34 ( L_3 ,
V_22 -> V_40 , V_49 ) ;
V_22 -> V_46 . V_55 ++ ;
break;
}
V_12 = F_31 ( F_12 ( V_48 ) ) ;
F_21 ( V_12 ) ;
}
V_56:
V_22 -> V_46 . V_47 ++ ;
F_23 ( V_51 ) ;
return NULL ;
}
static void F_39 ( struct V_10 * V_11 , void * V_26 , unsigned int V_29 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_44 * V_22 = V_19 -> V_22 ;
struct V_63 * V_46 = F_40 ( V_19 -> V_46 ) ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
if ( F_17 ( V_29 < sizeof( struct V_43 ) + V_64 ) ) {
F_34 ( L_4 , V_22 -> V_40 , V_29 ) ;
V_22 -> V_46 . V_55 ++ ;
if ( V_19 -> V_35 ) {
unsigned long V_48 = ( unsigned long ) V_26 ;
void * V_65 = F_12 ( V_48 ) ;
F_21 ( F_31 ( V_65 ) ) ;
} else if ( V_19 -> V_66 ) {
F_5 ( V_11 , V_26 ) ;
} else {
F_23 ( V_26 ) ;
}
return;
}
if ( V_19 -> V_35 )
V_8 = F_30 ( V_22 , V_11 , ( unsigned long ) V_26 , V_29 ) ;
else if ( V_19 -> V_66 )
V_8 = F_29 ( V_22 , V_11 , V_26 , V_29 ) ;
else
V_8 = F_27 ( V_26 , V_29 ) ;
if ( F_17 ( ! V_8 ) )
return;
V_30 = V_6 ( V_8 ) ;
F_41 ( & V_46 -> V_67 ) ;
V_46 -> V_68 += V_8 -> V_29 ;
V_46 -> V_69 ++ ;
F_42 ( & V_46 -> V_67 ) ;
if ( V_30 -> V_30 . V_70 & V_71 ) {
F_34 ( L_5 ) ;
if ( ! F_43 ( V_8 ,
V_30 -> V_30 . V_72 ,
V_30 -> V_30 . V_73 ) )
goto V_74;
} else if ( V_30 -> V_30 . V_70 & V_75 ) {
V_8 -> V_76 = V_77 ;
}
V_8 -> V_78 = F_44 ( V_8 , V_22 ) ;
F_34 ( L_6 ,
F_45 ( V_8 -> V_78 ) , V_8 -> V_29 , V_8 -> V_79 ) ;
if ( V_30 -> V_30 . V_80 != V_81 ) {
F_34 ( L_7 ) ;
switch ( V_30 -> V_30 . V_80 & ~ V_82 ) {
case V_83 :
F_26 ( V_8 ) -> V_80 = V_84 ;
break;
case V_85 :
F_26 ( V_8 ) -> V_80 = V_86 ;
break;
case V_87 :
F_26 ( V_8 ) -> V_80 = V_88 ;
break;
default:
F_46 ( L_8 ,
V_22 -> V_40 , V_30 -> V_30 . V_80 ) ;
goto V_74;
}
if ( V_30 -> V_30 . V_80 & V_82 )
F_26 ( V_8 ) -> V_80 |= V_89 ;
F_26 ( V_8 ) -> V_90 = V_30 -> V_30 . V_90 ;
if ( F_26 ( V_8 ) -> V_90 == 0 ) {
F_46 ( L_9 , V_22 -> V_40 ) ;
goto V_74;
}
F_26 ( V_8 ) -> V_80 |= V_91 ;
F_26 ( V_8 ) -> V_92 = 0 ;
}
F_47 ( V_8 , & V_11 -> V_93 ) ;
F_48 ( V_8 ) ;
return;
V_74:
V_22 -> V_46 . V_94 ++ ;
F_23 ( V_8 ) ;
}
static int F_49 ( struct V_10 * V_11 , T_1 V_95 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_45 ;
V_8 = F_50 ( V_19 -> V_22 , V_96 , V_95 ) ;
if ( F_17 ( ! V_8 ) )
return - V_97 ;
F_19 ( V_8 , V_96 ) ;
V_30 = V_6 ( V_8 ) ;
F_51 ( V_11 -> V_98 , & V_30 -> V_30 , sizeof V_30 -> V_30 ) ;
F_52 ( V_8 , V_11 -> V_98 + 1 , 0 , V_8 -> V_29 ) ;
V_45 = F_53 ( V_11 -> V_2 , V_11 -> V_98 , 2 , V_8 , V_95 ) ;
if ( V_45 < 0 )
F_23 ( V_8 ) ;
return V_45 ;
}
static int F_54 ( struct V_10 * V_11 , T_1 V_95 )
{
struct V_12 * V_99 , * V_100 = NULL ;
char * V_17 ;
int V_101 , V_45 , V_28 ;
for ( V_101 = V_38 + 1 ; V_101 > 1 ; -- V_101 ) {
V_99 = F_6 ( V_11 , V_95 ) ;
if ( ! V_99 ) {
if ( V_100 )
F_5 ( V_11 , V_100 ) ;
return - V_97 ;
}
F_51 ( & V_11 -> V_98 [ V_101 ] , F_15 ( V_99 ) , V_39 ) ;
V_99 -> V_14 = ( unsigned long ) V_100 ;
V_100 = V_99 ;
}
V_99 = F_6 ( V_11 , V_95 ) ;
if ( ! V_99 ) {
F_5 ( V_11 , V_100 ) ;
return - V_97 ;
}
V_17 = F_15 ( V_99 ) ;
F_51 ( & V_11 -> V_98 [ 0 ] , V_17 , sizeof( struct V_43 ) ) ;
V_28 = sizeof( struct V_37 ) ;
F_51 ( & V_11 -> V_98 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_99 -> V_14 = ( unsigned long ) V_100 ;
V_45 = F_53 ( V_11 -> V_2 , V_11 -> V_98 , V_38 + 2 ,
V_99 , V_95 ) ;
if ( V_45 < 0 )
F_5 ( V_11 , V_99 ) ;
return V_45 ;
}
static unsigned int F_55 ( struct V_102 * V_103 )
{
const T_2 V_32 = sizeof( struct V_104 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_56 (unsigned int, ewma_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_57 ( V_29 , V_25 ) ;
}
static int F_58 ( struct V_10 * V_11 , T_1 V_95 )
{
struct V_105 * V_106 = & V_11 -> V_106 ;
char * V_26 ;
unsigned long V_48 ;
int V_45 ;
unsigned int V_29 , V_107 ;
V_29 = F_55 ( & V_11 -> V_62 ) ;
if ( F_17 ( ! F_59 ( V_29 , V_106 , V_95 ) ) )
return - V_97 ;
V_26 = ( char * ) F_15 ( V_106 -> V_12 ) + V_106 -> V_28 ;
V_48 = F_13 ( V_26 , V_29 ) ;
F_60 ( V_106 -> V_12 ) ;
V_106 -> V_28 += V_29 ;
V_107 = V_106 -> V_27 - V_106 -> V_28 ;
if ( V_107 < V_29 ) {
V_29 += V_107 ;
V_106 -> V_28 += V_107 ;
}
F_61 ( V_11 -> V_98 , V_26 , V_29 ) ;
V_45 = F_53 ( V_11 -> V_2 , V_11 -> V_98 , 1 , ( void * ) V_48 , V_95 ) ;
if ( V_45 < 0 )
F_21 ( F_31 ( V_26 ) ) ;
return V_45 ;
}
static bool F_62 ( struct V_10 * V_11 , T_1 V_95 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_45 ;
bool V_108 ;
V_95 |= V_109 ;
do {
if ( V_19 -> V_35 )
V_45 = F_58 ( V_11 , V_95 ) ;
else if ( V_19 -> V_66 )
V_45 = F_54 ( V_11 , V_95 ) ;
else
V_45 = F_49 ( V_11 , V_95 ) ;
V_108 = V_45 == - V_97 ;
if ( V_45 )
break;
} while ( V_11 -> V_2 -> V_110 );
F_63 ( V_11 -> V_2 ) ;
return ! V_108 ;
}
static void F_64 ( struct V_1 * V_111 )
{
struct V_18 * V_19 = V_111 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_111 ) ] ;
if ( F_65 ( & V_11 -> V_93 ) ) {
F_9 ( V_111 ) ;
F_66 ( & V_11 -> V_93 ) ;
}
}
static void F_67 ( struct V_10 * V_11 )
{
F_68 ( & V_11 -> V_93 ) ;
if ( F_65 ( & V_11 -> V_93 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_69 () ;
F_66 ( & V_11 -> V_93 ) ;
F_70 () ;
}
}
static void F_71 ( struct V_112 * V_113 )
{
struct V_18 * V_19 =
F_72 ( V_113 , struct V_18 , V_114 . V_113 ) ;
bool V_115 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_116 ; V_101 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_101 ] ;
F_73 ( & V_11 -> V_93 ) ;
V_115 = ! F_62 ( V_11 , V_117 ) ;
F_67 ( V_11 ) ;
if ( V_115 )
F_74 ( & V_19 -> V_114 , V_118 / 2 ) ;
}
}
static int F_75 ( struct V_10 * V_11 , int V_119 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_120 = 0 ;
void * V_26 ;
while ( V_120 < V_119 &&
( V_26 = F_33 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_39 ( V_11 , V_26 , V_29 ) ;
V_120 ++ ;
}
if ( V_11 -> V_2 -> V_110 > F_76 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_62 ( V_11 , V_58 ) )
F_74 ( & V_19 -> V_114 , 0 ) ;
}
return V_120 ;
}
static int F_77 ( struct V_121 * V_93 , int V_119 )
{
struct V_10 * V_11 =
F_72 ( V_93 , struct V_10 , V_93 ) ;
unsigned int V_122 , V_120 = 0 ;
V_123:
V_120 += F_75 ( V_11 , V_119 - V_120 ) ;
if ( V_120 < V_119 ) {
V_122 = F_78 ( V_11 -> V_2 ) ;
F_79 ( V_93 ) ;
if ( F_17 ( F_80 ( V_11 -> V_2 , V_122 ) ) &&
F_65 ( V_93 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_66 ( V_93 ) ;
goto V_123;
}
}
return V_120 ;
}
static int F_81 ( struct V_121 * V_93 )
{
struct V_10 * V_11 =
F_72 ( V_93 , struct V_10 , V_93 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_122 , V_120 = 0 , V_119 = 4 ;
if ( ! ( V_19 -> V_124 & V_125 ) )
return V_126 ;
if ( ! F_65 ( V_93 ) )
return V_127 ;
F_9 ( V_11 -> V_2 ) ;
V_123:
V_120 += F_75 ( V_11 , V_119 ) ;
V_122 = F_78 ( V_11 -> V_2 ) ;
F_82 ( V_128 , & V_93 -> V_129 ) ;
if ( F_17 ( F_80 ( V_11 -> V_2 , V_122 ) ) &&
F_65 ( V_93 ) ) {
F_9 ( V_11 -> V_2 ) ;
if ( V_120 < V_119 ) {
V_119 -= V_120 ;
goto V_123;
} else {
F_66 ( V_93 ) ;
}
}
return V_120 ;
}
static int F_83 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
if ( V_101 < V_19 -> V_116 )
if ( ! F_62 ( & V_19 -> V_11 [ V_101 ] , V_117 ) )
F_74 ( & V_19 -> V_114 , 0 ) ;
F_67 ( & V_19 -> V_11 [ V_101 ] ) ;
}
return 0 ;
}
static void F_85 ( struct V_131 * V_132 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_132 -> V_2 -> V_20 -> V_21 ;
struct V_63 * V_46 = F_40 ( V_19 -> V_46 ) ;
while ( ( V_8 = F_33 ( V_132 -> V_2 , & V_29 ) ) != NULL ) {
F_34 ( L_10 , V_8 ) ;
F_41 ( & V_46 -> V_133 ) ;
V_46 -> V_134 += V_8 -> V_29 ;
V_46 -> V_135 ++ ;
F_42 ( & V_46 -> V_133 ) ;
F_86 ( V_8 ) ;
}
}
static int F_87 ( struct V_131 * V_132 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_136 = ( (struct V_137 * ) V_8 -> V_138 ) -> V_139 ;
struct V_18 * V_19 = V_132 -> V_2 -> V_20 -> V_21 ;
unsigned V_140 ;
unsigned V_32 ;
bool V_141 ;
F_34 ( L_11 , V_19 -> V_22 -> V_40 , V_8 , V_136 ) ;
if ( V_19 -> V_35 )
V_32 = sizeof V_30 -> V_36 ;
else
V_32 = sizeof V_30 -> V_30 ;
V_141 = V_19 -> V_142 &&
! ( ( unsigned long ) V_8 -> V_138 & ( F_88 ( * V_30 ) - 1 ) ) &&
! F_89 ( V_8 ) && F_90 ( V_8 ) >= V_32 ;
if ( V_141 )
V_30 = (struct V_6 * ) ( V_8 -> V_138 - V_32 ) ;
else
V_30 = V_6 ( V_8 ) ;
if ( V_8 -> V_76 == V_143 ) {
V_30 -> V_30 . V_70 = V_71 ;
V_30 -> V_30 . V_72 = F_91 ( V_8 ) ;
V_30 -> V_30 . V_73 = V_8 -> V_73 ;
} else {
V_30 -> V_30 . V_70 = 0 ;
V_30 -> V_30 . V_73 = V_30 -> V_30 . V_72 = 0 ;
}
if ( F_92 ( V_8 ) ) {
V_30 -> V_30 . V_32 = F_93 ( V_8 ) ;
V_30 -> V_30 . V_90 = F_26 ( V_8 ) -> V_90 ;
if ( F_26 ( V_8 ) -> V_80 & V_84 )
V_30 -> V_30 . V_80 = V_83 ;
else if ( F_26 ( V_8 ) -> V_80 & V_88 )
V_30 -> V_30 . V_80 = V_87 ;
else if ( F_26 ( V_8 ) -> V_80 & V_86 )
V_30 -> V_30 . V_80 = V_85 ;
else
F_94 () ;
if ( F_26 ( V_8 ) -> V_80 & V_89 )
V_30 -> V_30 . V_80 |= V_82 ;
} else {
V_30 -> V_30 . V_80 = V_81 ;
V_30 -> V_30 . V_90 = V_30 -> V_30 . V_32 = 0 ;
}
if ( V_19 -> V_35 )
V_30 -> V_36 . V_50 = 0 ;
if ( V_141 ) {
F_95 ( V_8 , V_32 ) ;
V_140 = F_52 ( V_8 , V_132 -> V_98 , 0 , V_8 -> V_29 ) ;
F_96 ( V_8 , V_32 ) ;
} else {
F_51 ( V_132 -> V_98 , V_30 , V_32 ) ;
V_140 = F_52 ( V_8 , V_132 -> V_98 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_97 ( V_132 -> V_2 , V_132 -> V_98 , V_140 , V_8 , V_58 ) ;
}
static T_3 F_98 ( struct V_7 * V_8 , struct V_44 * V_22 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
int V_144 = F_99 ( V_8 ) ;
struct V_131 * V_132 = & V_19 -> V_132 [ V_144 ] ;
int V_45 ;
F_85 ( V_132 ) ;
V_45 = F_87 ( V_132 , V_8 ) ;
if ( F_17 ( V_45 ) ) {
V_22 -> V_46 . V_145 ++ ;
if ( F_100 () )
F_101 ( & V_22 -> V_22 ,
L_12 , V_144 , V_45 ) ;
V_22 -> V_46 . V_146 ++ ;
F_86 ( V_8 ) ;
return V_147 ;
}
F_63 ( V_132 -> V_2 ) ;
F_102 ( V_8 ) ;
F_103 ( V_8 ) ;
if ( V_132 -> V_2 -> V_110 < 2 + V_38 ) {
F_104 ( V_22 , V_144 ) ;
if ( F_17 ( ! F_105 ( V_132 -> V_2 ) ) ) {
F_85 ( V_132 ) ;
if ( V_132 -> V_2 -> V_110 >= 2 + V_38 ) {
F_106 ( V_22 , V_144 ) ;
F_9 ( V_132 -> V_2 ) ;
}
}
}
return V_147 ;
}
static bool F_107 ( struct V_18 * V_19 , T_4 V_148 , T_4 V_149 ,
struct V_150 * V_151 )
{
struct V_150 * V_152 [ 4 ] , V_30 , V_153 ;
struct V_154 V_155 ;
T_5 V_124 = ~ 0 ;
unsigned V_156 = 0 , V_157 ;
F_24 ( ! F_108 ( V_19 -> V_20 , V_158 ) ) ;
V_155 . V_148 = V_148 ;
V_155 . V_149 = V_149 ;
F_61 ( & V_30 , & V_155 , sizeof( V_155 ) ) ;
V_152 [ V_156 ++ ] = & V_30 ;
if ( V_151 )
V_152 [ V_156 ++ ] = V_151 ;
F_61 ( & V_153 , & V_124 , sizeof( V_124 ) ) ;
V_152 [ V_156 ] = & V_153 ;
F_24 ( V_156 + 1 > F_109 ( V_152 ) ) ;
F_110 ( V_19 -> V_159 , V_152 , V_156 , 1 , V_19 , V_58 ) ;
if ( F_17 ( ! F_63 ( V_19 -> V_159 ) ) )
return V_124 == V_160 ;
while ( ! F_33 ( V_19 -> V_159 , & V_157 ) &&
! F_111 ( V_19 -> V_159 ) )
F_112 () ;
return V_124 == V_160 ;
}
static int F_113 ( struct V_44 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
struct V_161 * V_20 = V_19 -> V_20 ;
int V_162 ;
struct V_163 * V_164 = V_17 ;
struct V_150 V_98 ;
V_162 = F_114 ( V_22 , V_17 ) ;
if ( V_162 )
return V_162 ;
if ( F_108 ( V_20 , V_165 ) ) {
F_61 ( & V_98 , V_164 -> V_166 , V_22 -> V_167 ) ;
if ( ! F_107 ( V_19 , V_168 ,
V_169 , & V_98 ) ) {
F_101 ( & V_20 -> V_22 ,
L_13 ) ;
return - V_170 ;
}
} else if ( F_108 ( V_20 , V_171 ) ) {
unsigned int V_101 ;
for ( V_101 = 0 ; V_101 < V_22 -> V_167 ; V_101 ++ )
F_115 ( V_20 ,
F_116 ( struct V_172 , V_173 ) +
V_101 , V_164 -> V_166 [ V_101 ] ) ;
}
F_117 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_174 * V_63 ( struct V_44 * V_22 ,
struct V_174 * V_175 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
int V_176 ;
unsigned int V_177 ;
F_118 (cpu) {
struct V_63 * V_46 = F_119 ( V_19 -> V_46 , V_176 ) ;
T_6 V_178 , V_179 , V_180 , V_181 ;
do {
V_177 = F_120 ( & V_46 -> V_133 ) ;
V_178 = V_46 -> V_135 ;
V_179 = V_46 -> V_134 ;
} while ( F_121 ( & V_46 -> V_133 , V_177 ) );
do {
V_177 = F_120 ( & V_46 -> V_67 ) ;
V_180 = V_46 -> V_69 ;
V_181 = V_46 -> V_68 ;
} while ( F_121 ( & V_46 -> V_67 , V_177 ) );
V_175 -> V_69 += V_180 ;
V_175 -> V_135 += V_178 ;
V_175 -> V_68 += V_181 ;
V_175 -> V_134 += V_179 ;
}
V_175 -> V_146 = V_22 -> V_46 . V_146 ;
V_175 -> V_145 = V_22 -> V_46 . V_145 ;
V_175 -> V_47 = V_22 -> V_46 . V_47 ;
V_175 -> V_55 = V_22 -> V_46 . V_55 ;
V_175 -> V_94 = V_22 -> V_46 . V_94 ;
return V_175 ;
}
static void F_122 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_116 ; V_101 ++ )
F_123 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
}
static void F_124 ( struct V_18 * V_19 )
{
F_125 () ;
if ( ! F_107 ( V_19 , V_182 ,
V_183 , NULL ) )
F_101 ( & V_19 -> V_22 -> V_22 , L_14 ) ;
F_126 () ;
}
static int F_127 ( struct V_18 * V_19 , T_7 V_184 )
{
struct V_150 V_98 ;
struct V_185 V_186 ;
struct V_44 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_187 || ! F_108 ( V_19 -> V_20 , V_188 ) )
return 0 ;
V_186 . V_189 = V_184 ;
F_61 ( & V_98 , & V_186 , sizeof( V_186 ) ) ;
if ( ! F_107 ( V_19 , V_190 ,
V_191 , & V_98 ) ) {
F_101 ( & V_22 -> V_22 , L_15 ,
V_184 ) ;
return - V_170 ;
} else {
V_19 -> V_116 = V_184 ;
if ( V_22 -> V_70 & V_192 )
F_74 ( & V_19 -> V_114 , 0 ) ;
}
return 0 ;
}
static int F_128 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
int V_101 ;
F_129 ( & V_19 -> V_114 ) ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ )
F_73 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
return 0 ;
}
static void F_130 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
struct V_150 V_98 [ 2 ] ;
T_4 V_193 , V_194 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
int V_199 ;
int V_200 ;
void * V_26 ;
int V_101 ;
if ( ! F_108 ( V_19 -> V_20 , V_201 ) )
return;
V_193 = ( ( V_22 -> V_70 & V_202 ) != 0 ) ;
V_194 = ( ( V_22 -> V_70 & V_203 ) != 0 ) ;
F_61 ( V_98 , & V_193 , sizeof( V_193 ) ) ;
if ( ! F_107 ( V_19 , V_204 ,
V_205 , V_98 ) )
F_101 ( & V_22 -> V_22 , L_16 ,
V_193 ? L_17 : L_18 ) ;
F_61 ( V_98 , & V_194 , sizeof( V_194 ) ) ;
if ( ! F_107 ( V_19 , V_204 ,
V_206 , V_98 ) )
F_101 ( & V_22 -> V_22 , L_19 ,
V_194 ? L_17 : L_18 ) ;
V_199 = F_131 ( V_22 ) ;
V_200 = F_132 ( V_22 ) ;
V_26 = F_133 ( ( ( V_199 + V_200 ) * V_207 ) +
( 2 * sizeof( V_196 -> V_208 ) ) , V_58 ) ;
V_196 = V_26 ;
if ( ! V_26 )
return;
F_134 ( V_98 , 2 ) ;
V_196 -> V_208 = V_199 ;
V_101 = 0 ;
F_135 (ha, dev)
memcpy ( & V_196 -> V_209 [ V_101 ++ ] [ 0 ] , V_198 -> V_164 , V_207 ) ;
F_51 ( & V_98 [ 0 ] , V_196 ,
sizeof( V_196 -> V_208 ) + ( V_199 * V_207 ) ) ;
V_196 = ( void * ) & V_196 -> V_209 [ V_199 ] [ 0 ] ;
V_196 -> V_208 = V_200 ;
V_101 = 0 ;
F_136 (ha, dev)
memcpy ( & V_196 -> V_209 [ V_101 ++ ] [ 0 ] , V_198 -> V_164 , V_207 ) ;
F_51 ( & V_98 [ 1 ] , V_196 ,
sizeof( V_196 -> V_208 ) + ( V_200 * V_207 ) ) ;
if ( ! F_107 ( V_19 , V_168 ,
V_210 , V_98 ) )
F_101 ( & V_22 -> V_22 , L_20 ) ;
F_137 ( V_26 ) ;
}
static int F_138 ( struct V_44 * V_22 ,
T_8 V_211 , T_7 V_212 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
struct V_150 V_98 ;
F_61 ( & V_98 , & V_212 , sizeof( V_212 ) ) ;
if ( ! F_107 ( V_19 , V_213 ,
V_214 , & V_98 ) )
F_101 ( & V_22 -> V_22 , L_21 , V_212 ) ;
return 0 ;
}
static int F_139 ( struct V_44 * V_22 ,
T_8 V_211 , T_7 V_212 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
struct V_150 V_98 ;
F_61 ( & V_98 , & V_212 , sizeof( V_212 ) ) ;
if ( ! F_107 ( V_19 , V_213 ,
V_215 , & V_98 ) )
F_101 ( & V_22 -> V_22 , L_22 , V_212 ) ;
return 0 ;
}
static void F_140 ( struct V_18 * V_19 , long V_216 )
{
int V_101 ;
if ( V_19 -> V_217 ) {
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
F_141 ( V_19 -> V_11 [ V_101 ] . V_2 , - 1 ) ;
F_141 ( V_19 -> V_132 [ V_101 ] . V_2 , - 1 ) ;
}
V_19 -> V_217 = false ;
}
}
static void F_142 ( struct V_18 * V_19 )
{
int V_101 ;
int V_176 ;
if ( V_19 -> V_116 == 1 ||
V_19 -> V_130 != F_143 () ) {
F_140 ( V_19 , - 1 ) ;
return;
}
V_101 = 0 ;
F_144 (cpu) {
F_141 ( V_19 -> V_11 [ V_101 ] . V_2 , V_176 ) ;
F_141 ( V_19 -> V_132 [ V_101 ] . V_2 , V_176 ) ;
F_145 ( V_19 -> V_22 , F_146 ( V_176 ) , V_101 ) ;
V_101 ++ ;
}
V_19 -> V_217 = true ;
}
static int F_147 ( struct V_218 * V_219 ,
unsigned long V_220 , void * V_216 )
{
struct V_18 * V_19 = F_72 ( V_219 , struct V_18 , V_221 ) ;
switch( V_220 & ~ V_222 ) {
case V_223 :
case V_224 :
case V_225 :
F_142 ( V_19 ) ;
break;
case V_226 :
F_140 ( V_19 , ( long ) V_216 ) ;
break;
default:
break;
}
return V_227 ;
}
static void F_148 ( struct V_44 * V_22 ,
struct V_228 * V_229 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
V_229 -> V_230 = F_76 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_229 -> V_231 = F_76 ( V_19 -> V_132 [ 0 ] . V_2 ) ;
V_229 -> V_232 = V_229 -> V_230 ;
V_229 -> V_233 = V_229 -> V_231 ;
}
static void F_149 ( struct V_44 * V_22 ,
struct V_234 * V_235 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
struct V_161 * V_20 = V_19 -> V_20 ;
F_150 ( V_235 -> V_236 , V_237 , sizeof( V_235 -> V_236 ) ) ;
F_150 ( V_235 -> V_238 , V_239 , sizeof( V_235 -> V_238 ) ) ;
F_150 ( V_235 -> V_240 , F_151 ( V_20 ) , sizeof( V_235 -> V_240 ) ) ;
}
static int F_152 ( struct V_44 * V_22 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
T_7 V_184 = V_242 -> V_243 ;
int V_45 ;
if ( V_242 -> V_244 || V_242 -> V_245 || V_242 -> V_246 )
return - V_170 ;
if ( V_184 > V_19 -> V_130 || V_184 == 0 )
return - V_170 ;
F_153 () ;
V_45 = F_127 ( V_19 , V_184 ) ;
if ( ! V_45 ) {
F_154 ( V_22 , V_184 ) ;
F_155 ( V_22 , V_184 ) ;
F_142 ( V_19 ) ;
}
F_156 () ;
return V_45 ;
}
static void F_157 ( struct V_44 * V_22 ,
struct V_241 * V_242 )
{
struct V_18 * V_19 = F_84 ( V_22 ) ;
V_242 -> V_243 = V_19 -> V_116 ;
V_242 -> V_247 = V_19 -> V_130 ;
V_242 -> V_248 = 0 ;
V_242 -> V_244 = 0 ;
V_242 -> V_245 = 0 ;
V_242 -> V_246 = 0 ;
}
static int F_158 ( struct V_44 * V_22 , int V_249 )
{
if ( V_249 < V_250 || V_249 > V_251 )
return - V_170 ;
V_22 -> V_252 = V_249 ;
return 0 ;
}
static void F_159 ( struct V_112 * V_113 )
{
struct V_18 * V_19 =
F_72 ( V_113 , struct V_18 , V_253 ) ;
T_7 V_254 ;
F_160 ( & V_19 -> V_255 ) ;
if ( ! V_19 -> V_256 )
goto V_257;
if ( F_161 ( V_19 -> V_20 , V_258 ,
struct V_172 , V_124 , & V_254 ) < 0 )
goto V_257;
if ( V_254 & V_259 ) {
F_162 ( V_19 -> V_22 ) ;
F_124 ( V_19 ) ;
}
V_254 &= V_125 ;
if ( V_19 -> V_124 == V_254 )
goto V_257;
V_19 -> V_124 = V_254 ;
if ( V_19 -> V_124 & V_125 ) {
F_163 ( V_19 -> V_22 ) ;
F_164 ( V_19 -> V_22 ) ;
} else {
F_165 ( V_19 -> V_22 ) ;
F_166 ( V_19 -> V_22 ) ;
}
V_257:
F_167 ( & V_19 -> V_255 ) ;
}
static void F_168 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_169 ( & V_19 -> V_253 ) ;
}
static void F_170 ( struct V_18 * V_19 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ )
F_171 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
F_137 ( V_19 -> V_11 ) ;
F_137 ( V_19 -> V_132 ) ;
}
static void F_172 ( struct V_18 * V_19 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
while ( V_19 -> V_11 [ V_101 ] . V_15 )
F_173 ( F_6 ( & V_19 -> V_11 [ V_101 ] , V_117 ) , 0 ) ;
}
}
static void F_174 ( struct V_18 * V_19 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ )
if ( V_19 -> V_11 [ V_101 ] . V_106 . V_12 )
F_21 ( V_19 -> V_11 [ V_101 ] . V_106 . V_12 ) ;
}
static void F_175 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
struct V_1 * V_2 = V_19 -> V_132 [ V_101 ] . V_2 ;
while ( ( V_26 = F_176 ( V_2 ) ) != NULL )
F_23 ( V_26 ) ;
}
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_101 ] . V_2 ;
while ( ( V_26 = F_176 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_35 ) {
unsigned long V_48 = ( unsigned long ) V_26 ;
void * V_65 = F_12 ( V_48 ) ;
F_21 ( F_31 ( V_65 ) ) ;
} else if ( V_19 -> V_66 ) {
F_5 ( & V_19 -> V_11 [ V_101 ] , V_26 ) ;
} else {
F_23 ( V_26 ) ;
}
}
}
}
static void F_177 ( struct V_18 * V_19 )
{
struct V_161 * V_20 = V_19 -> V_20 ;
F_140 ( V_19 , - 1 ) ;
V_20 -> V_260 -> V_261 ( V_20 ) ;
F_170 ( V_19 ) ;
}
static int F_178 ( struct V_18 * V_19 )
{
T_9 * * V_262 ;
struct V_1 * * V_263 ;
int V_162 = - V_97 ;
int V_101 , V_264 ;
const char * * V_265 ;
V_264 = V_19 -> V_130 * 2 +
F_108 ( V_19 -> V_20 , V_158 ) ;
V_263 = F_133 ( V_264 * sizeof( * V_263 ) , V_117 ) ;
if ( ! V_263 )
goto V_266;
V_262 = F_179 ( V_264 * sizeof( * V_262 ) , V_117 ) ;
if ( ! V_262 )
goto V_267;
V_265 = F_179 ( V_264 * sizeof( * V_265 ) , V_117 ) ;
if ( ! V_265 )
goto V_268;
if ( V_19 -> V_187 ) {
V_262 [ V_264 - 1 ] = NULL ;
V_265 [ V_264 - 1 ] = L_23 ;
}
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
V_262 [ F_4 ( V_101 ) ] = F_64 ;
V_262 [ F_2 ( V_101 ) ] = F_8 ;
sprintf ( V_19 -> V_11 [ V_101 ] . V_40 , L_24 , V_101 ) ;
sprintf ( V_19 -> V_132 [ V_101 ] . V_40 , L_25 , V_101 ) ;
V_265 [ F_4 ( V_101 ) ] = V_19 -> V_11 [ V_101 ] . V_40 ;
V_265 [ F_2 ( V_101 ) ] = V_19 -> V_132 [ V_101 ] . V_40 ;
}
V_162 = V_19 -> V_20 -> V_260 -> V_269 ( V_19 -> V_20 , V_264 , V_263 , V_262 ,
V_265 ) ;
if ( V_162 )
goto V_270;
if ( V_19 -> V_187 ) {
V_19 -> V_159 = V_263 [ V_264 - 1 ] ;
if ( F_108 ( V_19 -> V_20 , V_271 ) )
V_19 -> V_22 -> V_272 |= V_273 ;
}
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
V_19 -> V_11 [ V_101 ] . V_2 = V_263 [ F_4 ( V_101 ) ] ;
V_19 -> V_132 [ V_101 ] . V_2 = V_263 [ F_2 ( V_101 ) ] ;
}
F_137 ( V_265 ) ;
F_137 ( V_262 ) ;
F_137 ( V_263 ) ;
return 0 ;
V_270:
F_137 ( V_265 ) ;
V_268:
F_137 ( V_262 ) ;
V_267:
F_137 ( V_263 ) ;
V_266:
return V_162 ;
}
static int F_180 ( struct V_18 * V_19 )
{
int V_101 ;
V_19 -> V_132 = F_133 ( sizeof( * V_19 -> V_132 ) * V_19 -> V_130 , V_117 ) ;
if ( ! V_19 -> V_132 )
goto V_274;
V_19 -> V_11 = F_133 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_130 , V_117 ) ;
if ( ! V_19 -> V_11 )
goto V_275;
F_181 ( & V_19 -> V_114 , F_71 ) ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
V_19 -> V_11 [ V_101 ] . V_15 = NULL ;
F_182 ( V_19 -> V_22 , & V_19 -> V_11 [ V_101 ] . V_93 , F_77 ,
V_276 ) ;
F_183 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
F_134 ( V_19 -> V_11 [ V_101 ] . V_98 , F_109 ( V_19 -> V_11 [ V_101 ] . V_98 ) ) ;
F_184 ( & V_19 -> V_11 [ V_101 ] . V_62 , 1 , V_277 ) ;
F_134 ( V_19 -> V_132 [ V_101 ] . V_98 , F_109 ( V_19 -> V_132 [ V_101 ] . V_98 ) ) ;
}
return 0 ;
V_275:
F_137 ( V_19 -> V_132 ) ;
V_274:
return - V_97 ;
}
static int F_185 ( struct V_18 * V_19 )
{
int V_162 ;
V_162 = F_180 ( V_19 ) ;
if ( V_162 )
goto V_45;
V_162 = F_178 ( V_19 ) ;
if ( V_162 )
goto V_278;
F_153 () ;
F_142 ( V_19 ) ;
F_156 () ;
return 0 ;
V_278:
F_170 ( V_19 ) ;
V_45:
return V_162 ;
}
static T_10 F_186 ( struct V_279 * V_280 ,
struct V_281 * V_282 , char * V_26 )
{
struct V_18 * V_19 = F_84 ( V_280 -> V_22 ) ;
unsigned int V_283 = F_187 ( V_280 ) ;
struct V_102 * V_284 ;
F_24 ( V_283 >= V_19 -> V_130 ) ;
V_284 = & V_19 -> V_11 [ V_283 ] . V_62 ;
return sprintf ( V_26 , L_26 , F_55 ( V_284 ) ) ;
}
static int F_188 ( struct V_161 * V_20 )
{
int V_101 , V_45 ;
struct V_44 * V_22 ;
struct V_18 * V_19 ;
T_7 V_130 ;
V_45 = F_161 ( V_20 , V_188 ,
struct V_172 ,
V_285 , & V_130 ) ;
if ( V_45 || V_130 < V_286 ||
V_130 > V_287 ||
! F_108 ( V_20 , V_158 ) )
V_130 = 1 ;
V_22 = F_189 ( sizeof( struct V_18 ) , V_130 ) ;
if ( ! V_22 )
return - V_97 ;
V_22 -> V_288 |= V_289 | V_290 ;
V_22 -> V_291 = & V_292 ;
V_22 -> V_272 = V_293 ;
V_22 -> V_294 = & V_295 ;
F_190 ( V_22 , & V_20 -> V_22 ) ;
if ( F_108 ( V_20 , V_296 ) ) {
V_22 -> V_297 |= V_298 | V_299 | V_300 ;
if ( V_301 )
V_22 -> V_272 |= V_298 | V_299 | V_300 ;
if ( F_108 ( V_20 , V_302 ) ) {
V_22 -> V_297 |= V_303 | V_304
| V_305 | V_306 ;
}
if ( F_108 ( V_20 , V_307 ) )
V_22 -> V_297 |= V_303 ;
if ( F_108 ( V_20 , V_308 ) )
V_22 -> V_297 |= V_306 ;
if ( F_108 ( V_20 , V_309 ) )
V_22 -> V_297 |= V_305 ;
if ( F_108 ( V_20 , V_310 ) )
V_22 -> V_297 |= V_304 ;
if ( V_311 )
V_22 -> V_272 |= V_22 -> V_297 & ( V_312 | V_304 ) ;
}
if ( F_108 ( V_20 , V_313 ) )
V_22 -> V_272 |= V_314 ;
V_22 -> V_315 = V_22 -> V_272 ;
if ( F_108 ( V_20 , V_171 ) )
F_191 ( V_20 ,
F_116 ( struct V_172 , V_173 ) ,
V_22 -> V_316 , V_22 -> V_167 ) ;
else
F_192 ( V_22 ) ;
V_19 = F_84 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_46 = F_193 ( struct V_63 ) ;
V_45 = - V_97 ;
if ( V_19 -> V_46 == NULL )
goto free;
F_118 (i) {
struct V_63 * V_63 ;
V_63 = F_119 ( V_19 -> V_46 , V_101 ) ;
F_194 ( & V_63 -> V_133 ) ;
F_194 ( & V_63 -> V_67 ) ;
}
F_195 ( & V_19 -> V_255 ) ;
V_19 -> V_256 = true ;
F_196 ( & V_19 -> V_253 , F_159 ) ;
if ( F_108 ( V_20 , V_317 ) ||
F_108 ( V_20 , V_318 ) ||
F_108 ( V_20 , V_319 ) ||
F_108 ( V_20 , V_320 ) )
V_19 -> V_66 = true ;
if ( F_108 ( V_20 , V_321 ) )
V_19 -> V_35 = true ;
if ( F_108 ( V_20 , V_322 ) )
V_19 -> V_142 = true ;
if ( F_108 ( V_20 , V_158 ) )
V_19 -> V_187 = true ;
if ( V_19 -> V_142 ) {
if ( V_19 -> V_35 )
V_22 -> V_323 = sizeof( struct V_104 ) ;
else
V_22 -> V_323 = sizeof( struct V_43 ) ;
}
V_19 -> V_116 = 1 ;
V_19 -> V_130 = V_130 ;
V_45 = F_185 ( V_19 ) ;
if ( V_45 )
goto V_324;
#ifdef F_197
if ( V_19 -> V_35 )
V_22 -> V_325 = & V_326 ;
#endif
F_154 ( V_22 , V_19 -> V_116 ) ;
F_155 ( V_22 , V_19 -> V_116 ) ;
V_45 = F_198 ( V_22 ) ;
if ( V_45 ) {
F_34 ( L_27 ) ;
goto V_327;
}
for ( V_101 = 0 ; V_101 < V_19 -> V_116 ; V_101 ++ ) {
F_62 ( & V_19 -> V_11 [ V_101 ] , V_117 ) ;
if ( V_19 -> V_11 [ V_101 ] . V_2 -> V_110 ==
F_76 ( V_19 -> V_11 [ V_101 ] . V_2 ) ) {
F_175 ( V_19 ) ;
V_45 = - V_97 ;
goto V_328;
}
}
V_19 -> V_221 . V_329 = & F_147 ;
V_45 = F_199 ( & V_19 -> V_221 ) ;
if ( V_45 ) {
F_34 ( L_28 ) ;
goto V_328;
}
if ( F_108 ( V_19 -> V_20 , V_258 ) ) {
F_165 ( V_22 ) ;
F_169 ( & V_19 -> V_253 ) ;
} else {
V_19 -> V_124 = V_125 ;
F_163 ( V_22 ) ;
}
F_34 ( L_29 ,
V_22 -> V_40 , V_130 ) ;
return 0 ;
V_328:
F_172 ( V_19 ) ;
F_200 ( V_22 ) ;
V_327:
F_129 ( & V_19 -> V_114 ) ;
F_174 ( V_19 ) ;
F_177 ( V_19 ) ;
V_324:
F_201 ( V_19 -> V_46 ) ;
free:
F_202 ( V_22 ) ;
return V_45 ;
}
static void F_203 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_260 -> V_330 ( V_19 -> V_20 ) ;
F_175 ( V_19 ) ;
F_172 ( V_19 ) ;
F_174 ( V_19 ) ;
F_177 ( V_19 ) ;
}
static void F_204 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_205 ( & V_19 -> V_221 ) ;
F_160 ( & V_19 -> V_255 ) ;
V_19 -> V_256 = false ;
F_167 ( & V_19 -> V_255 ) ;
F_200 ( V_19 -> V_22 ) ;
F_203 ( V_19 ) ;
F_206 ( & V_19 -> V_253 ) ;
F_201 ( V_19 -> V_46 ) ;
F_202 ( V_19 -> V_22 ) ;
}
static int F_207 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_101 ;
F_205 ( & V_19 -> V_221 ) ;
F_160 ( & V_19 -> V_255 ) ;
V_19 -> V_256 = false ;
F_167 ( & V_19 -> V_255 ) ;
F_208 ( V_19 -> V_22 ) ;
F_129 ( & V_19 -> V_114 ) ;
if ( F_209 ( V_19 -> V_22 ) ) {
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ ) {
F_73 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
F_210 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
F_171 ( & V_19 -> V_11 [ V_101 ] . V_93 ) ;
}
}
F_203 ( V_19 ) ;
F_206 ( & V_19 -> V_253 ) ;
return 0 ;
}
static int F_211 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_45 , V_101 ;
V_45 = F_185 ( V_19 ) ;
if ( V_45 )
return V_45 ;
if ( F_209 ( V_19 -> V_22 ) ) {
for ( V_101 = 0 ; V_101 < V_19 -> V_116 ; V_101 ++ )
if ( ! F_62 ( & V_19 -> V_11 [ V_101 ] , V_117 ) )
F_74 ( & V_19 -> V_114 , 0 ) ;
for ( V_101 = 0 ; V_101 < V_19 -> V_130 ; V_101 ++ )
F_67 ( & V_19 -> V_11 [ V_101 ] ) ;
}
F_212 ( V_19 -> V_22 ) ;
F_160 ( & V_19 -> V_255 ) ;
V_19 -> V_256 = true ;
F_167 ( & V_19 -> V_255 ) ;
F_125 () ;
F_127 ( V_19 , V_19 -> V_116 ) ;
F_126 () ;
V_45 = F_199 ( & V_19 -> V_221 ) ;
if ( V_45 )
return V_45 ;
return 0 ;
}
