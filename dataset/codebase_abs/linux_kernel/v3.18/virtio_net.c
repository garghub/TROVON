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
{
static bool V_86 ;
if ( ! V_86 ) {
V_86 = true ;
F_46 ( V_22 ,
L_8 ) ;
}
F_26 ( V_8 ) -> V_80 = V_87 ;
break;
}
case V_88 :
F_26 ( V_8 ) -> V_80 = V_89 ;
break;
default:
F_47 ( L_9 ,
V_22 -> V_40 , V_30 -> V_30 . V_80 ) ;
goto V_74;
}
if ( V_30 -> V_30 . V_80 & V_82 )
F_26 ( V_8 ) -> V_80 |= V_90 ;
F_26 ( V_8 ) -> V_91 = V_30 -> V_30 . V_91 ;
if ( F_26 ( V_8 ) -> V_91 == 0 ) {
F_47 ( L_10 , V_22 -> V_40 ) ;
goto V_74;
}
F_26 ( V_8 ) -> V_80 |= V_92 ;
F_26 ( V_8 ) -> V_93 = 0 ;
}
F_48 ( V_8 , & V_11 -> V_94 ) ;
F_49 ( V_8 ) ;
return;
V_74:
V_22 -> V_46 . V_95 ++ ;
F_23 ( V_8 ) ;
}
static int F_50 ( struct V_10 * V_11 , T_1 V_96 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_45 ;
V_8 = F_51 ( V_19 -> V_22 , V_97 , V_96 ) ;
if ( F_17 ( ! V_8 ) )
return - V_98 ;
F_19 ( V_8 , V_97 ) ;
V_30 = V_6 ( V_8 ) ;
F_52 ( V_11 -> V_99 , V_38 + 2 ) ;
F_53 ( V_11 -> V_99 , & V_30 -> V_30 , sizeof V_30 -> V_30 ) ;
F_54 ( V_8 , V_11 -> V_99 + 1 , 0 , V_8 -> V_29 ) ;
V_45 = F_55 ( V_11 -> V_2 , V_11 -> V_99 , 2 , V_8 , V_96 ) ;
if ( V_45 < 0 )
F_23 ( V_8 ) ;
return V_45 ;
}
static int F_56 ( struct V_10 * V_11 , T_1 V_96 )
{
struct V_12 * V_100 , * V_101 = NULL ;
char * V_17 ;
int V_102 , V_45 , V_28 ;
F_52 ( V_11 -> V_99 , V_38 + 2 ) ;
for ( V_102 = V_38 + 1 ; V_102 > 1 ; -- V_102 ) {
V_100 = F_6 ( V_11 , V_96 ) ;
if ( ! V_100 ) {
if ( V_101 )
F_5 ( V_11 , V_101 ) ;
return - V_98 ;
}
F_53 ( & V_11 -> V_99 [ V_102 ] , F_15 ( V_100 ) , V_39 ) ;
V_100 -> V_14 = ( unsigned long ) V_101 ;
V_101 = V_100 ;
}
V_100 = F_6 ( V_11 , V_96 ) ;
if ( ! V_100 ) {
F_5 ( V_11 , V_101 ) ;
return - V_98 ;
}
V_17 = F_15 ( V_100 ) ;
F_53 ( & V_11 -> V_99 [ 0 ] , V_17 , sizeof( struct V_43 ) ) ;
V_28 = sizeof( struct V_37 ) ;
F_53 ( & V_11 -> V_99 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_100 -> V_14 = ( unsigned long ) V_101 ;
V_45 = F_55 ( V_11 -> V_2 , V_11 -> V_99 , V_38 + 2 ,
V_100 , V_96 ) ;
if ( V_45 < 0 )
F_5 ( V_11 , V_100 ) ;
return V_45 ;
}
static unsigned int F_57 ( struct V_103 * V_104 )
{
const T_2 V_32 = sizeof( struct V_105 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_58 (unsigned int, ewma_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_59 ( V_29 , V_25 ) ;
}
static int F_60 ( struct V_10 * V_11 , T_1 V_96 )
{
struct V_106 * V_107 = & V_11 -> V_107 ;
char * V_26 ;
unsigned long V_48 ;
int V_45 ;
unsigned int V_29 , V_108 ;
V_29 = F_57 ( & V_11 -> V_62 ) ;
if ( F_17 ( ! F_61 ( V_29 , V_107 , V_96 ) ) )
return - V_98 ;
V_26 = ( char * ) F_15 ( V_107 -> V_12 ) + V_107 -> V_28 ;
V_48 = F_13 ( V_26 , V_29 ) ;
F_62 ( V_107 -> V_12 ) ;
V_107 -> V_28 += V_29 ;
V_108 = V_107 -> V_27 - V_107 -> V_28 ;
if ( V_108 < V_29 ) {
V_29 += V_108 ;
V_107 -> V_28 += V_108 ;
}
F_63 ( V_11 -> V_99 , V_26 , V_29 ) ;
V_45 = F_55 ( V_11 -> V_2 , V_11 -> V_99 , 1 , ( void * ) V_48 , V_96 ) ;
if ( V_45 < 0 )
F_21 ( F_31 ( V_26 ) ) ;
return V_45 ;
}
static bool F_64 ( struct V_10 * V_11 , T_1 V_96 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_45 ;
bool V_109 ;
V_96 |= V_110 ;
do {
if ( V_19 -> V_35 )
V_45 = F_60 ( V_11 , V_96 ) ;
else if ( V_19 -> V_66 )
V_45 = F_56 ( V_11 , V_96 ) ;
else
V_45 = F_50 ( V_11 , V_96 ) ;
V_109 = V_45 == - V_98 ;
if ( V_45 )
break;
} while ( V_11 -> V_2 -> V_111 );
F_65 ( V_11 -> V_2 ) ;
return ! V_109 ;
}
static void F_66 ( struct V_1 * V_112 )
{
struct V_18 * V_19 = V_112 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_112 ) ] ;
if ( F_67 ( & V_11 -> V_94 ) ) {
F_9 ( V_112 ) ;
F_68 ( & V_11 -> V_94 ) ;
}
}
static void F_69 ( struct V_10 * V_11 )
{
F_70 ( & V_11 -> V_94 ) ;
if ( F_67 ( & V_11 -> V_94 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_71 () ;
F_68 ( & V_11 -> V_94 ) ;
F_72 () ;
}
}
static void F_73 ( struct V_113 * V_114 )
{
struct V_18 * V_19 =
F_74 ( V_114 , struct V_18 , V_115 . V_114 ) ;
bool V_116 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_117 ; V_102 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_102 ] ;
F_75 ( & V_11 -> V_94 ) ;
V_116 = ! F_64 ( V_11 , V_118 ) ;
F_69 ( V_11 ) ;
if ( V_116 )
F_76 ( & V_19 -> V_115 , V_119 / 2 ) ;
}
}
static int F_77 ( struct V_10 * V_11 , int V_120 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_121 = 0 ;
void * V_26 ;
while ( V_121 < V_120 &&
( V_26 = F_33 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_39 ( V_11 , V_26 , V_29 ) ;
V_121 ++ ;
}
if ( V_11 -> V_2 -> V_111 > F_78 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_64 ( V_11 , V_58 ) )
F_76 ( & V_19 -> V_115 , 0 ) ;
}
return V_121 ;
}
static int F_79 ( struct V_122 * V_94 , int V_120 )
{
struct V_10 * V_11 =
F_74 ( V_94 , struct V_10 , V_94 ) ;
unsigned int V_123 , V_121 = 0 ;
V_124:
V_121 += F_77 ( V_11 , V_120 - V_121 ) ;
if ( V_121 < V_120 ) {
V_123 = F_80 ( V_11 -> V_2 ) ;
F_81 ( V_94 ) ;
if ( F_17 ( F_82 ( V_11 -> V_2 , V_123 ) ) &&
F_67 ( V_94 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_68 ( V_94 ) ;
goto V_124;
}
}
return V_121 ;
}
static int F_83 ( struct V_122 * V_94 )
{
struct V_10 * V_11 =
F_74 ( V_94 , struct V_10 , V_94 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_123 , V_121 = 0 , V_120 = 4 ;
if ( ! ( V_19 -> V_125 & V_126 ) )
return V_127 ;
if ( ! F_67 ( V_94 ) )
return V_128 ;
F_9 ( V_11 -> V_2 ) ;
V_124:
V_121 += F_77 ( V_11 , V_120 ) ;
V_123 = F_80 ( V_11 -> V_2 ) ;
F_84 ( V_129 , & V_94 -> V_130 ) ;
if ( F_17 ( F_82 ( V_11 -> V_2 , V_123 ) ) &&
F_67 ( V_94 ) ) {
F_9 ( V_11 -> V_2 ) ;
if ( V_121 < V_120 ) {
V_120 -= V_121 ;
goto V_124;
} else {
F_68 ( V_94 ) ;
}
}
return V_121 ;
}
static int F_85 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
if ( V_102 < V_19 -> V_117 )
if ( ! F_64 ( & V_19 -> V_11 [ V_102 ] , V_118 ) )
F_76 ( & V_19 -> V_115 , 0 ) ;
F_69 ( & V_19 -> V_11 [ V_102 ] ) ;
}
return 0 ;
}
static void F_87 ( struct V_132 * V_133 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_133 -> V_2 -> V_20 -> V_21 ;
struct V_63 * V_46 = F_40 ( V_19 -> V_46 ) ;
while ( ( V_8 = F_33 ( V_133 -> V_2 , & V_29 ) ) != NULL ) {
F_34 ( L_11 , V_8 ) ;
F_41 ( & V_46 -> V_134 ) ;
V_46 -> V_135 += V_8 -> V_29 ;
V_46 -> V_136 ++ ;
F_42 ( & V_46 -> V_134 ) ;
F_88 ( V_8 ) ;
}
}
static int F_89 ( struct V_132 * V_133 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_137 = ( (struct V_138 * ) V_8 -> V_139 ) -> V_140 ;
struct V_18 * V_19 = V_133 -> V_2 -> V_20 -> V_21 ;
unsigned V_141 ;
unsigned V_32 ;
bool V_142 ;
F_34 ( L_12 , V_19 -> V_22 -> V_40 , V_8 , V_137 ) ;
if ( V_19 -> V_35 )
V_32 = sizeof V_30 -> V_36 ;
else
V_32 = sizeof V_30 -> V_30 ;
V_142 = V_19 -> V_143 &&
! ( ( unsigned long ) V_8 -> V_139 & ( F_90 ( * V_30 ) - 1 ) ) &&
! F_91 ( V_8 ) && F_92 ( V_8 ) >= V_32 ;
if ( V_142 )
V_30 = (struct V_6 * ) ( V_8 -> V_139 - V_32 ) ;
else
V_30 = V_6 ( V_8 ) ;
if ( V_8 -> V_76 == V_144 ) {
V_30 -> V_30 . V_70 = V_71 ;
V_30 -> V_30 . V_72 = F_93 ( V_8 ) ;
V_30 -> V_30 . V_73 = V_8 -> V_73 ;
} else {
V_30 -> V_30 . V_70 = 0 ;
V_30 -> V_30 . V_73 = V_30 -> V_30 . V_72 = 0 ;
}
if ( F_94 ( V_8 ) ) {
V_30 -> V_30 . V_32 = F_95 ( V_8 ) ;
V_30 -> V_30 . V_91 = F_26 ( V_8 ) -> V_91 ;
if ( F_26 ( V_8 ) -> V_80 & V_84 )
V_30 -> V_30 . V_80 = V_83 ;
else if ( F_26 ( V_8 ) -> V_80 & V_89 )
V_30 -> V_30 . V_80 = V_88 ;
else
F_96 () ;
if ( F_26 ( V_8 ) -> V_80 & V_90 )
V_30 -> V_30 . V_80 |= V_82 ;
} else {
V_30 -> V_30 . V_80 = V_81 ;
V_30 -> V_30 . V_91 = V_30 -> V_30 . V_32 = 0 ;
}
if ( V_19 -> V_35 )
V_30 -> V_36 . V_50 = 0 ;
F_52 ( V_133 -> V_99 , V_38 + 2 ) ;
if ( V_142 ) {
F_97 ( V_8 , V_32 ) ;
V_141 = F_54 ( V_8 , V_133 -> V_99 , 0 , V_8 -> V_29 ) ;
F_98 ( V_8 , V_32 ) ;
} else {
F_53 ( V_133 -> V_99 , V_30 , V_32 ) ;
V_141 = F_54 ( V_8 , V_133 -> V_99 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_99 ( V_133 -> V_2 , V_133 -> V_99 , V_141 , V_8 , V_58 ) ;
}
static T_3 F_100 ( struct V_7 * V_8 , struct V_44 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_145 = F_101 ( V_8 ) ;
struct V_132 * V_133 = & V_19 -> V_133 [ V_145 ] ;
int V_45 ;
struct V_146 * V_4 = F_102 ( V_22 , V_145 ) ;
bool V_147 = ! V_8 -> V_148 ;
F_87 ( V_133 ) ;
V_45 = F_89 ( V_133 , V_8 ) ;
if ( F_17 ( V_45 ) ) {
V_22 -> V_46 . V_149 ++ ;
if ( F_103 () )
F_104 ( & V_22 -> V_22 ,
L_13 , V_145 , V_45 ) ;
V_22 -> V_46 . V_150 ++ ;
F_88 ( V_8 ) ;
return V_151 ;
}
F_105 ( V_8 ) ;
F_106 ( V_8 ) ;
if ( V_133 -> V_2 -> V_111 < 2 + V_38 ) {
F_107 ( V_22 , V_145 ) ;
if ( F_17 ( ! F_108 ( V_133 -> V_2 ) ) ) {
F_87 ( V_133 ) ;
if ( V_133 -> V_2 -> V_111 >= 2 + V_38 ) {
F_109 ( V_22 , V_145 ) ;
F_9 ( V_133 -> V_2 ) ;
}
}
}
if ( V_147 || F_110 ( V_4 ) )
F_65 ( V_133 -> V_2 ) ;
return V_151 ;
}
static bool F_111 ( struct V_18 * V_19 , T_4 V_152 , T_4 V_153 ,
struct V_154 * V_155 )
{
struct V_154 * V_156 [ 4 ] , V_30 , V_157 ;
struct V_158 V_159 ;
T_5 V_125 = ~ 0 ;
unsigned V_160 = 0 , V_161 ;
F_24 ( ! F_112 ( V_19 -> V_20 , V_162 ) ) ;
V_159 . V_152 = V_152 ;
V_159 . V_153 = V_153 ;
F_63 ( & V_30 , & V_159 , sizeof( V_159 ) ) ;
V_156 [ V_160 ++ ] = & V_30 ;
if ( V_155 )
V_156 [ V_160 ++ ] = V_155 ;
F_63 ( & V_157 , & V_125 , sizeof( V_125 ) ) ;
V_156 [ V_160 ] = & V_157 ;
F_24 ( V_160 + 1 > F_113 ( V_156 ) ) ;
F_114 ( V_19 -> V_163 , V_156 , V_160 , 1 , V_19 , V_58 ) ;
if ( F_17 ( ! F_65 ( V_19 -> V_163 ) ) )
return V_125 == V_164 ;
while ( ! F_33 ( V_19 -> V_163 , & V_161 ) &&
! F_115 ( V_19 -> V_163 ) )
F_116 () ;
return V_125 == V_164 ;
}
static int F_117 ( struct V_44 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_165 * V_20 = V_19 -> V_20 ;
int V_166 ;
struct V_167 * V_168 = V_17 ;
struct V_154 V_99 ;
V_166 = F_118 ( V_22 , V_17 ) ;
if ( V_166 )
return V_166 ;
if ( F_112 ( V_20 , V_169 ) ) {
F_63 ( & V_99 , V_168 -> V_170 , V_22 -> V_171 ) ;
if ( ! F_111 ( V_19 , V_172 ,
V_173 , & V_99 ) ) {
F_104 ( & V_20 -> V_22 ,
L_14 ) ;
return - V_174 ;
}
} else if ( F_112 ( V_20 , V_175 ) ) {
unsigned int V_102 ;
for ( V_102 = 0 ; V_102 < V_22 -> V_171 ; V_102 ++ )
F_119 ( V_20 ,
F_120 ( struct V_176 , V_177 ) +
V_102 , V_168 -> V_170 [ V_102 ] ) ;
}
F_121 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_178 * V_63 ( struct V_44 * V_22 ,
struct V_178 * V_179 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_180 ;
unsigned int V_181 ;
F_122 (cpu) {
struct V_63 * V_46 = F_123 ( V_19 -> V_46 , V_180 ) ;
T_6 V_182 , V_183 , V_184 , V_185 ;
do {
V_181 = F_124 ( & V_46 -> V_134 ) ;
V_182 = V_46 -> V_136 ;
V_183 = V_46 -> V_135 ;
} while ( F_125 ( & V_46 -> V_134 , V_181 ) );
do {
V_181 = F_124 ( & V_46 -> V_67 ) ;
V_184 = V_46 -> V_69 ;
V_185 = V_46 -> V_68 ;
} while ( F_125 ( & V_46 -> V_67 , V_181 ) );
V_179 -> V_69 += V_184 ;
V_179 -> V_136 += V_182 ;
V_179 -> V_68 += V_185 ;
V_179 -> V_135 += V_183 ;
}
V_179 -> V_150 = V_22 -> V_46 . V_150 ;
V_179 -> V_149 = V_22 -> V_46 . V_149 ;
V_179 -> V_47 = V_22 -> V_46 . V_47 ;
V_179 -> V_55 = V_22 -> V_46 . V_55 ;
V_179 -> V_95 = V_22 -> V_46 . V_95 ;
return V_179 ;
}
static void F_126 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_117 ; V_102 ++ )
F_127 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
}
static void F_128 ( struct V_18 * V_19 )
{
F_129 () ;
if ( ! F_111 ( V_19 , V_186 ,
V_187 , NULL ) )
F_104 ( & V_19 -> V_22 -> V_22 , L_15 ) ;
F_130 () ;
}
static int F_131 ( struct V_18 * V_19 , T_7 V_188 )
{
struct V_154 V_99 ;
struct V_189 V_190 ;
struct V_44 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_191 || ! F_112 ( V_19 -> V_20 , V_192 ) )
return 0 ;
V_190 . V_193 = V_188 ;
F_63 ( & V_99 , & V_190 , sizeof( V_190 ) ) ;
if ( ! F_111 ( V_19 , V_194 ,
V_195 , & V_99 ) ) {
F_104 ( & V_22 -> V_22 , L_16 ,
V_188 ) ;
return - V_174 ;
} else {
V_19 -> V_117 = V_188 ;
if ( V_22 -> V_70 & V_196 )
F_76 ( & V_19 -> V_115 , 0 ) ;
}
return 0 ;
}
static int F_132 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_102 ;
F_133 ( & V_19 -> V_115 ) ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ )
F_75 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
return 0 ;
}
static void F_134 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_154 V_99 [ 2 ] ;
T_4 V_197 , V_198 ;
struct V_199 * V_200 ;
struct V_201 * V_202 ;
int V_203 ;
int V_204 ;
void * V_26 ;
int V_102 ;
if ( ! F_112 ( V_19 -> V_20 , V_205 ) )
return;
V_197 = ( ( V_22 -> V_70 & V_206 ) != 0 ) ;
V_198 = ( ( V_22 -> V_70 & V_207 ) != 0 ) ;
F_63 ( V_99 , & V_197 , sizeof( V_197 ) ) ;
if ( ! F_111 ( V_19 , V_208 ,
V_209 , V_99 ) )
F_104 ( & V_22 -> V_22 , L_17 ,
V_197 ? L_18 : L_19 ) ;
F_63 ( V_99 , & V_198 , sizeof( V_198 ) ) ;
if ( ! F_111 ( V_19 , V_208 ,
V_210 , V_99 ) )
F_104 ( & V_22 -> V_22 , L_20 ,
V_198 ? L_18 : L_19 ) ;
V_203 = F_135 ( V_22 ) ;
V_204 = F_136 ( V_22 ) ;
V_26 = F_137 ( ( ( V_203 + V_204 ) * V_211 ) +
( 2 * sizeof( V_200 -> V_212 ) ) , V_58 ) ;
V_200 = V_26 ;
if ( ! V_26 )
return;
F_52 ( V_99 , 2 ) ;
V_200 -> V_212 = V_203 ;
V_102 = 0 ;
F_138 (ha, dev)
memcpy ( & V_200 -> V_213 [ V_102 ++ ] [ 0 ] , V_202 -> V_168 , V_211 ) ;
F_53 ( & V_99 [ 0 ] , V_200 ,
sizeof( V_200 -> V_212 ) + ( V_203 * V_211 ) ) ;
V_200 = ( void * ) & V_200 -> V_213 [ V_203 ] [ 0 ] ;
V_200 -> V_212 = V_204 ;
V_102 = 0 ;
F_139 (ha, dev)
memcpy ( & V_200 -> V_213 [ V_102 ++ ] [ 0 ] , V_202 -> V_168 , V_211 ) ;
F_53 ( & V_99 [ 1 ] , V_200 ,
sizeof( V_200 -> V_212 ) + ( V_204 * V_211 ) ) ;
if ( ! F_111 ( V_19 , V_172 ,
V_214 , V_99 ) )
F_104 ( & V_22 -> V_22 , L_21 ) ;
F_140 ( V_26 ) ;
}
static int F_141 ( struct V_44 * V_22 ,
T_8 V_215 , T_7 V_216 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_154 V_99 ;
F_63 ( & V_99 , & V_216 , sizeof( V_216 ) ) ;
if ( ! F_111 ( V_19 , V_217 ,
V_218 , & V_99 ) )
F_104 ( & V_22 -> V_22 , L_22 , V_216 ) ;
return 0 ;
}
static int F_142 ( struct V_44 * V_22 ,
T_8 V_215 , T_7 V_216 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_154 V_99 ;
F_63 ( & V_99 , & V_216 , sizeof( V_216 ) ) ;
if ( ! F_111 ( V_19 , V_217 ,
V_219 , & V_99 ) )
F_104 ( & V_22 -> V_22 , L_23 , V_216 ) ;
return 0 ;
}
static void F_143 ( struct V_18 * V_19 , long V_220 )
{
int V_102 ;
if ( V_19 -> V_221 ) {
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
F_144 ( V_19 -> V_11 [ V_102 ] . V_2 , - 1 ) ;
F_144 ( V_19 -> V_133 [ V_102 ] . V_2 , - 1 ) ;
}
V_19 -> V_221 = false ;
}
}
static void F_145 ( struct V_18 * V_19 )
{
int V_102 ;
int V_180 ;
if ( V_19 -> V_117 == 1 ||
V_19 -> V_131 != F_146 () ) {
F_143 ( V_19 , - 1 ) ;
return;
}
V_102 = 0 ;
F_147 (cpu) {
F_144 ( V_19 -> V_11 [ V_102 ] . V_2 , V_180 ) ;
F_144 ( V_19 -> V_133 [ V_102 ] . V_2 , V_180 ) ;
F_148 ( V_19 -> V_22 , F_149 ( V_180 ) , V_102 ) ;
V_102 ++ ;
}
V_19 -> V_221 = true ;
}
static int F_150 ( struct V_222 * V_223 ,
unsigned long V_224 , void * V_220 )
{
struct V_18 * V_19 = F_74 ( V_223 , struct V_18 , V_225 ) ;
switch( V_224 & ~ V_226 ) {
case V_227 :
case V_228 :
case V_229 :
F_145 ( V_19 ) ;
break;
case V_230 :
F_143 ( V_19 , ( long ) V_220 ) ;
break;
default:
break;
}
return V_231 ;
}
static void F_151 ( struct V_44 * V_22 ,
struct V_232 * V_233 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
V_233 -> V_234 = F_78 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_233 -> V_235 = F_78 ( V_19 -> V_133 [ 0 ] . V_2 ) ;
V_233 -> V_236 = V_233 -> V_234 ;
V_233 -> V_237 = V_233 -> V_235 ;
}
static void F_152 ( struct V_44 * V_22 ,
struct V_238 * V_239 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_165 * V_20 = V_19 -> V_20 ;
F_153 ( V_239 -> V_240 , V_241 , sizeof( V_239 -> V_240 ) ) ;
F_153 ( V_239 -> V_242 , V_243 , sizeof( V_239 -> V_242 ) ) ;
F_153 ( V_239 -> V_244 , F_154 ( V_20 ) , sizeof( V_239 -> V_244 ) ) ;
}
static int F_155 ( struct V_44 * V_22 ,
struct V_245 * V_246 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
T_7 V_188 = V_246 -> V_247 ;
int V_45 ;
if ( V_246 -> V_248 || V_246 -> V_249 || V_246 -> V_250 )
return - V_174 ;
if ( V_188 > V_19 -> V_131 || V_188 == 0 )
return - V_174 ;
F_156 () ;
V_45 = F_131 ( V_19 , V_188 ) ;
if ( ! V_45 ) {
F_157 ( V_22 , V_188 ) ;
F_158 ( V_22 , V_188 ) ;
F_145 ( V_19 ) ;
}
F_159 () ;
return V_45 ;
}
static void F_160 ( struct V_44 * V_22 ,
struct V_245 * V_246 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
V_246 -> V_247 = V_19 -> V_117 ;
V_246 -> V_251 = V_19 -> V_131 ;
V_246 -> V_252 = 0 ;
V_246 -> V_248 = 0 ;
V_246 -> V_249 = 0 ;
V_246 -> V_250 = 0 ;
}
static int F_161 ( struct V_44 * V_22 , int V_253 )
{
if ( V_253 < V_254 || V_253 > V_255 )
return - V_174 ;
V_22 -> V_256 = V_253 ;
return 0 ;
}
static void F_162 ( struct V_113 * V_114 )
{
struct V_18 * V_19 =
F_74 ( V_114 , struct V_18 , V_257 ) ;
T_7 V_258 ;
if ( F_163 ( V_19 -> V_20 , V_259 ,
struct V_176 , V_125 , & V_258 ) < 0 )
return;
if ( V_258 & V_260 ) {
F_164 ( V_19 -> V_22 ) ;
F_128 ( V_19 ) ;
}
V_258 &= V_126 ;
if ( V_19 -> V_125 == V_258 )
return;
V_19 -> V_125 = V_258 ;
if ( V_19 -> V_125 & V_126 ) {
F_165 ( V_19 -> V_22 ) ;
F_166 ( V_19 -> V_22 ) ;
} else {
F_167 ( V_19 -> V_22 ) ;
F_168 ( V_19 -> V_22 ) ;
}
}
static void F_169 ( struct V_165 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_170 ( & V_19 -> V_257 ) ;
}
static void F_171 ( struct V_18 * V_19 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ )
F_172 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
F_140 ( V_19 -> V_11 ) ;
F_140 ( V_19 -> V_133 ) ;
}
static void F_173 ( struct V_18 * V_19 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
while ( V_19 -> V_11 [ V_102 ] . V_15 )
F_174 ( F_6 ( & V_19 -> V_11 [ V_102 ] , V_118 ) , 0 ) ;
}
}
static void F_175 ( struct V_18 * V_19 )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ )
if ( V_19 -> V_11 [ V_102 ] . V_107 . V_12 )
F_21 ( V_19 -> V_11 [ V_102 ] . V_107 . V_12 ) ;
}
static void F_176 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
struct V_1 * V_2 = V_19 -> V_133 [ V_102 ] . V_2 ;
while ( ( V_26 = F_177 ( V_2 ) ) != NULL )
F_23 ( V_26 ) ;
}
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_102 ] . V_2 ;
while ( ( V_26 = F_177 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_35 ) {
unsigned long V_48 = ( unsigned long ) V_26 ;
void * V_65 = F_12 ( V_48 ) ;
F_21 ( F_31 ( V_65 ) ) ;
} else if ( V_19 -> V_66 ) {
F_5 ( & V_19 -> V_11 [ V_102 ] , V_26 ) ;
} else {
F_23 ( V_26 ) ;
}
}
}
}
static void F_178 ( struct V_18 * V_19 )
{
struct V_165 * V_20 = V_19 -> V_20 ;
F_143 ( V_19 , - 1 ) ;
V_20 -> V_261 -> V_262 ( V_20 ) ;
F_171 ( V_19 ) ;
}
static int F_179 ( struct V_18 * V_19 )
{
T_9 * * V_263 ;
struct V_1 * * V_264 ;
int V_166 = - V_98 ;
int V_102 , V_265 ;
const char * * V_266 ;
V_265 = V_19 -> V_131 * 2 +
F_112 ( V_19 -> V_20 , V_162 ) ;
V_264 = F_137 ( V_265 * sizeof( * V_264 ) , V_118 ) ;
if ( ! V_264 )
goto V_267;
V_263 = F_180 ( V_265 * sizeof( * V_263 ) , V_118 ) ;
if ( ! V_263 )
goto V_268;
V_266 = F_180 ( V_265 * sizeof( * V_266 ) , V_118 ) ;
if ( ! V_266 )
goto V_269;
if ( V_19 -> V_191 ) {
V_263 [ V_265 - 1 ] = NULL ;
V_266 [ V_265 - 1 ] = L_24 ;
}
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
V_263 [ F_4 ( V_102 ) ] = F_66 ;
V_263 [ F_2 ( V_102 ) ] = F_8 ;
sprintf ( V_19 -> V_11 [ V_102 ] . V_40 , L_25 , V_102 ) ;
sprintf ( V_19 -> V_133 [ V_102 ] . V_40 , L_26 , V_102 ) ;
V_266 [ F_4 ( V_102 ) ] = V_19 -> V_11 [ V_102 ] . V_40 ;
V_266 [ F_2 ( V_102 ) ] = V_19 -> V_133 [ V_102 ] . V_40 ;
}
V_166 = V_19 -> V_20 -> V_261 -> V_270 ( V_19 -> V_20 , V_265 , V_264 , V_263 ,
V_266 ) ;
if ( V_166 )
goto V_271;
if ( V_19 -> V_191 ) {
V_19 -> V_163 = V_264 [ V_265 - 1 ] ;
if ( F_112 ( V_19 -> V_20 , V_272 ) )
V_19 -> V_22 -> V_273 |= V_274 ;
}
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
V_19 -> V_11 [ V_102 ] . V_2 = V_264 [ F_4 ( V_102 ) ] ;
V_19 -> V_133 [ V_102 ] . V_2 = V_264 [ F_2 ( V_102 ) ] ;
}
F_140 ( V_266 ) ;
F_140 ( V_263 ) ;
F_140 ( V_264 ) ;
return 0 ;
V_271:
F_140 ( V_266 ) ;
V_269:
F_140 ( V_263 ) ;
V_268:
F_140 ( V_264 ) ;
V_267:
return V_166 ;
}
static int F_181 ( struct V_18 * V_19 )
{
int V_102 ;
V_19 -> V_133 = F_137 ( sizeof( * V_19 -> V_133 ) * V_19 -> V_131 , V_118 ) ;
if ( ! V_19 -> V_133 )
goto V_275;
V_19 -> V_11 = F_137 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_131 , V_118 ) ;
if ( ! V_19 -> V_11 )
goto V_276;
F_182 ( & V_19 -> V_115 , F_73 ) ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
V_19 -> V_11 [ V_102 ] . V_15 = NULL ;
F_183 ( V_19 -> V_22 , & V_19 -> V_11 [ V_102 ] . V_94 , F_79 ,
V_277 ) ;
F_184 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
F_52 ( V_19 -> V_11 [ V_102 ] . V_99 , F_113 ( V_19 -> V_11 [ V_102 ] . V_99 ) ) ;
F_185 ( & V_19 -> V_11 [ V_102 ] . V_62 , 1 , V_278 ) ;
F_52 ( V_19 -> V_133 [ V_102 ] . V_99 , F_113 ( V_19 -> V_133 [ V_102 ] . V_99 ) ) ;
}
return 0 ;
V_276:
F_140 ( V_19 -> V_133 ) ;
V_275:
return - V_98 ;
}
static int F_186 ( struct V_18 * V_19 )
{
int V_166 ;
V_166 = F_181 ( V_19 ) ;
if ( V_166 )
goto V_45;
V_166 = F_179 ( V_19 ) ;
if ( V_166 )
goto V_279;
F_156 () ;
F_145 ( V_19 ) ;
F_159 () ;
return 0 ;
V_279:
F_171 ( V_19 ) ;
V_45:
return V_166 ;
}
static T_10 F_187 ( struct V_280 * V_281 ,
struct V_282 * V_283 , char * V_26 )
{
struct V_18 * V_19 = F_86 ( V_281 -> V_22 ) ;
unsigned int V_284 = F_188 ( V_281 ) ;
struct V_103 * V_285 ;
F_24 ( V_284 >= V_19 -> V_131 ) ;
V_285 = & V_19 -> V_11 [ V_284 ] . V_62 ;
return sprintf ( V_26 , L_27 , F_57 ( V_285 ) ) ;
}
static bool F_189 ( struct V_165 * V_20 ,
unsigned int V_286 ,
const char * V_287 , const char * V_288 )
{
if ( ! F_112 ( V_20 , V_286 ) )
return false ;
F_190 ( & V_20 -> V_22 , L_28 ,
V_287 , V_288 ) ;
return true ;
}
static bool F_191 ( struct V_165 * V_20 )
{
if ( ! F_112 ( V_20 , V_162 ) &&
( F_192 ( V_20 , V_205 ,
L_29 ) ||
F_192 ( V_20 , V_272 ,
L_29 ) ||
F_192 ( V_20 , V_289 ,
L_29 ) ||
F_192 ( V_20 , V_192 , L_29 ) ||
F_192 ( V_20 , V_169 ,
L_29 ) ) ) {
return false ;
}
return true ;
}
static int F_193 ( struct V_165 * V_20 )
{
int V_102 , V_45 ;
struct V_44 * V_22 ;
struct V_18 * V_19 ;
T_7 V_131 ;
if ( ! F_191 ( V_20 ) )
return - V_174 ;
V_45 = F_163 ( V_20 , V_192 ,
struct V_176 ,
V_290 , & V_131 ) ;
if ( V_45 || V_131 < V_291 ||
V_131 > V_292 ||
! F_112 ( V_20 , V_162 ) )
V_131 = 1 ;
V_22 = F_194 ( sizeof( struct V_18 ) , V_131 ) ;
if ( ! V_22 )
return - V_98 ;
V_22 -> V_293 |= V_294 | V_295 ;
V_22 -> V_296 = & V_297 ;
V_22 -> V_273 = V_298 ;
V_22 -> V_299 = & V_300 ;
F_195 ( V_22 , & V_20 -> V_22 ) ;
if ( F_112 ( V_20 , V_301 ) ) {
V_22 -> V_302 |= V_303 | V_304 | V_305 ;
if ( V_306 )
V_22 -> V_273 |= V_303 | V_304 | V_305 ;
if ( F_112 ( V_20 , V_307 ) ) {
V_22 -> V_302 |= V_308
| V_309 | V_310 ;
}
if ( F_112 ( V_20 , V_311 ) )
V_22 -> V_302 |= V_308 ;
if ( F_112 ( V_20 , V_312 ) )
V_22 -> V_302 |= V_310 ;
if ( F_112 ( V_20 , V_313 ) )
V_22 -> V_302 |= V_309 ;
if ( V_314 )
V_22 -> V_273 |= V_22 -> V_302 & V_315 ;
}
if ( F_112 ( V_20 , V_316 ) )
V_22 -> V_273 |= V_317 ;
V_22 -> V_318 = V_22 -> V_273 ;
if ( F_112 ( V_20 , V_175 ) )
F_196 ( V_20 ,
F_120 ( struct V_176 , V_177 ) ,
V_22 -> V_319 , V_22 -> V_171 ) ;
else
F_197 ( V_22 ) ;
V_19 = F_86 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_46 = F_198 ( struct V_63 ) ;
V_45 = - V_98 ;
if ( V_19 -> V_46 == NULL )
goto free;
F_122 (i) {
struct V_63 * V_63 ;
V_63 = F_123 ( V_19 -> V_46 , V_102 ) ;
F_199 ( & V_63 -> V_134 ) ;
F_199 ( & V_63 -> V_67 ) ;
}
F_200 ( & V_19 -> V_257 , F_162 ) ;
if ( F_112 ( V_20 , V_320 ) ||
F_112 ( V_20 , V_321 ) ||
F_112 ( V_20 , V_322 ) )
V_19 -> V_66 = true ;
if ( F_112 ( V_20 , V_323 ) )
V_19 -> V_35 = true ;
if ( F_112 ( V_20 , V_324 ) )
V_19 -> V_143 = true ;
if ( F_112 ( V_20 , V_162 ) )
V_19 -> V_191 = true ;
if ( V_19 -> V_143 ) {
if ( V_19 -> V_35 )
V_22 -> V_325 = sizeof( struct V_105 ) ;
else
V_22 -> V_325 = sizeof( struct V_43 ) ;
}
V_19 -> V_117 = 1 ;
V_19 -> V_131 = V_131 ;
V_45 = F_186 ( V_19 ) ;
if ( V_45 )
goto V_326;
#ifdef F_201
if ( V_19 -> V_35 )
V_22 -> V_327 = & V_328 ;
#endif
F_157 ( V_22 , V_19 -> V_117 ) ;
F_158 ( V_22 , V_19 -> V_117 ) ;
V_45 = F_202 ( V_22 ) ;
if ( V_45 ) {
F_34 ( L_30 ) ;
goto V_329;
}
F_203 ( V_20 ) ;
for ( V_102 = 0 ; V_102 < V_19 -> V_117 ; V_102 ++ ) {
F_64 ( & V_19 -> V_11 [ V_102 ] , V_118 ) ;
if ( V_19 -> V_11 [ V_102 ] . V_2 -> V_111 ==
F_78 ( V_19 -> V_11 [ V_102 ] . V_2 ) ) {
F_176 ( V_19 ) ;
V_45 = - V_98 ;
goto V_330;
}
}
V_19 -> V_225 . V_331 = & F_150 ;
V_45 = F_204 ( & V_19 -> V_225 ) ;
if ( V_45 ) {
F_34 ( L_31 ) ;
goto V_330;
}
if ( F_112 ( V_19 -> V_20 , V_259 ) ) {
F_167 ( V_22 ) ;
F_170 ( & V_19 -> V_257 ) ;
} else {
V_19 -> V_125 = V_126 ;
F_165 ( V_22 ) ;
}
F_34 ( L_32 ,
V_22 -> V_40 , V_131 ) ;
return 0 ;
V_330:
V_19 -> V_20 -> V_261 -> V_332 ( V_20 ) ;
F_173 ( V_19 ) ;
F_205 ( V_22 ) ;
V_329:
F_133 ( & V_19 -> V_115 ) ;
F_175 ( V_19 ) ;
F_178 ( V_19 ) ;
V_326:
F_206 ( V_19 -> V_46 ) ;
free:
F_207 ( V_22 ) ;
return V_45 ;
}
static void F_208 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_261 -> V_332 ( V_19 -> V_20 ) ;
F_176 ( V_19 ) ;
F_173 ( V_19 ) ;
F_175 ( V_19 ) ;
F_178 ( V_19 ) ;
}
static void F_209 ( struct V_165 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_210 ( & V_19 -> V_225 ) ;
F_211 ( & V_19 -> V_257 ) ;
F_205 ( V_19 -> V_22 ) ;
F_208 ( V_19 ) ;
F_206 ( V_19 -> V_46 ) ;
F_207 ( V_19 -> V_22 ) ;
}
static int F_212 ( struct V_165 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_102 ;
F_210 ( & V_19 -> V_225 ) ;
F_211 ( & V_19 -> V_257 ) ;
F_213 ( V_19 -> V_22 ) ;
F_133 ( & V_19 -> V_115 ) ;
if ( F_214 ( V_19 -> V_22 ) ) {
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ ) {
F_75 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
F_215 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
F_172 ( & V_19 -> V_11 [ V_102 ] . V_94 ) ;
}
}
F_208 ( V_19 ) ;
return 0 ;
}
static int F_216 ( struct V_165 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_45 , V_102 ;
V_45 = F_186 ( V_19 ) ;
if ( V_45 )
return V_45 ;
F_203 ( V_20 ) ;
if ( F_214 ( V_19 -> V_22 ) ) {
for ( V_102 = 0 ; V_102 < V_19 -> V_117 ; V_102 ++ )
if ( ! F_64 ( & V_19 -> V_11 [ V_102 ] , V_118 ) )
F_76 ( & V_19 -> V_115 , 0 ) ;
for ( V_102 = 0 ; V_102 < V_19 -> V_131 ; V_102 ++ )
F_69 ( & V_19 -> V_11 [ V_102 ] ) ;
}
F_217 ( V_19 -> V_22 ) ;
F_129 () ;
F_131 ( V_19 , V_19 -> V_117 ) ;
F_130 () ;
V_45 = F_204 ( & V_19 -> V_225 ) ;
if ( V_45 )
return V_45 ;
return 0 ;
}
