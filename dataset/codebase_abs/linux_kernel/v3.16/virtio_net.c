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
F_47 ( V_8 ) ;
return;
V_74:
V_22 -> V_46 . V_93 ++ ;
F_23 ( V_8 ) ;
}
static int F_48 ( struct V_10 * V_11 , T_1 V_94 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_45 ;
V_8 = F_49 ( V_19 -> V_22 , V_95 , V_94 ) ;
if ( F_17 ( ! V_8 ) )
return - V_96 ;
F_19 ( V_8 , V_95 ) ;
V_30 = V_6 ( V_8 ) ;
F_50 ( V_11 -> V_97 , & V_30 -> V_30 , sizeof V_30 -> V_30 ) ;
F_51 ( V_8 , V_11 -> V_97 + 1 , 0 , V_8 -> V_29 ) ;
V_45 = F_52 ( V_11 -> V_2 , V_11 -> V_97 , 2 , V_8 , V_94 ) ;
if ( V_45 < 0 )
F_23 ( V_8 ) ;
return V_45 ;
}
static int F_53 ( struct V_10 * V_11 , T_1 V_94 )
{
struct V_12 * V_98 , * V_99 = NULL ;
char * V_17 ;
int V_100 , V_45 , V_28 ;
for ( V_100 = V_38 + 1 ; V_100 > 1 ; -- V_100 ) {
V_98 = F_6 ( V_11 , V_94 ) ;
if ( ! V_98 ) {
if ( V_99 )
F_5 ( V_11 , V_99 ) ;
return - V_96 ;
}
F_50 ( & V_11 -> V_97 [ V_100 ] , F_15 ( V_98 ) , V_39 ) ;
V_98 -> V_14 = ( unsigned long ) V_99 ;
V_99 = V_98 ;
}
V_98 = F_6 ( V_11 , V_94 ) ;
if ( ! V_98 ) {
F_5 ( V_11 , V_99 ) ;
return - V_96 ;
}
V_17 = F_15 ( V_98 ) ;
F_50 ( & V_11 -> V_97 [ 0 ] , V_17 , sizeof( struct V_43 ) ) ;
V_28 = sizeof( struct V_37 ) ;
F_50 ( & V_11 -> V_97 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_98 -> V_14 = ( unsigned long ) V_99 ;
V_45 = F_52 ( V_11 -> V_2 , V_11 -> V_97 , V_38 + 2 ,
V_98 , V_94 ) ;
if ( V_45 < 0 )
F_5 ( V_11 , V_98 ) ;
return V_45 ;
}
static unsigned int F_54 ( struct V_101 * V_102 )
{
const T_2 V_32 = sizeof( struct V_103 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_55 (unsigned int, ewma_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_56 ( V_29 , V_25 ) ;
}
static int F_57 ( struct V_10 * V_11 , T_1 V_94 )
{
struct V_104 * V_105 = & V_11 -> V_105 ;
char * V_26 ;
unsigned long V_48 ;
int V_45 ;
unsigned int V_29 , V_106 ;
V_29 = F_54 ( & V_11 -> V_62 ) ;
if ( F_17 ( ! F_58 ( V_29 , V_105 , V_94 ) ) )
return - V_96 ;
V_26 = ( char * ) F_15 ( V_105 -> V_12 ) + V_105 -> V_28 ;
V_48 = F_13 ( V_26 , V_29 ) ;
F_59 ( V_105 -> V_12 ) ;
V_105 -> V_28 += V_29 ;
V_106 = V_105 -> V_27 - V_105 -> V_28 ;
if ( V_106 < V_29 ) {
V_29 += V_106 ;
V_105 -> V_28 += V_106 ;
}
F_60 ( V_11 -> V_97 , V_26 , V_29 ) ;
V_45 = F_52 ( V_11 -> V_2 , V_11 -> V_97 , 1 , ( void * ) V_48 , V_94 ) ;
if ( V_45 < 0 )
F_21 ( F_31 ( V_26 ) ) ;
return V_45 ;
}
static bool F_61 ( struct V_10 * V_11 , T_1 V_94 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_45 ;
bool V_107 ;
V_94 |= V_108 ;
do {
if ( V_19 -> V_35 )
V_45 = F_57 ( V_11 , V_94 ) ;
else if ( V_19 -> V_66 )
V_45 = F_53 ( V_11 , V_94 ) ;
else
V_45 = F_48 ( V_11 , V_94 ) ;
V_107 = V_45 == - V_96 ;
if ( V_45 )
break;
} while ( V_11 -> V_2 -> V_109 );
F_62 ( V_11 -> V_2 ) ;
return ! V_107 ;
}
static void F_63 ( struct V_1 * V_110 )
{
struct V_18 * V_19 = V_110 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_110 ) ] ;
if ( F_64 ( & V_11 -> V_111 ) ) {
F_9 ( V_110 ) ;
F_65 ( & V_11 -> V_111 ) ;
}
}
static void F_66 ( struct V_10 * V_11 )
{
F_67 ( & V_11 -> V_111 ) ;
if ( F_64 ( & V_11 -> V_111 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_68 () ;
F_65 ( & V_11 -> V_111 ) ;
F_69 () ;
}
}
static void F_70 ( struct V_112 * V_113 )
{
struct V_18 * V_19 =
F_71 ( V_113 , struct V_18 , V_114 . V_113 ) ;
bool V_115 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_116 ; V_100 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_100 ] ;
F_72 ( & V_11 -> V_111 ) ;
V_115 = ! F_61 ( V_11 , V_117 ) ;
F_66 ( V_11 ) ;
if ( V_115 )
F_73 ( & V_19 -> V_114 , V_118 / 2 ) ;
}
}
static int F_74 ( struct V_119 * V_111 , int V_120 )
{
struct V_10 * V_11 =
F_71 ( V_111 , struct V_10 , V_111 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
void * V_26 ;
unsigned int V_121 , V_29 , V_122 = 0 ;
V_123:
while ( V_122 < V_120 &&
( V_26 = F_33 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_39 ( V_11 , V_26 , V_29 ) ;
V_122 ++ ;
}
if ( V_11 -> V_2 -> V_109 > F_75 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_61 ( V_11 , V_58 ) )
F_73 ( & V_19 -> V_114 , 0 ) ;
}
if ( V_122 < V_120 ) {
V_121 = F_76 ( V_11 -> V_2 ) ;
F_77 ( V_111 ) ;
if ( F_17 ( F_78 ( V_11 -> V_2 , V_121 ) ) &&
F_64 ( V_111 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_65 ( V_111 ) ;
goto V_123;
}
}
return V_122 ;
}
static int F_79 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
if ( V_100 < V_19 -> V_116 )
if ( ! F_61 ( & V_19 -> V_11 [ V_100 ] , V_117 ) )
F_73 ( & V_19 -> V_114 , 0 ) ;
F_66 ( & V_19 -> V_11 [ V_100 ] ) ;
}
return 0 ;
}
static void F_81 ( struct V_125 * V_126 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_126 -> V_2 -> V_20 -> V_21 ;
struct V_63 * V_46 = F_40 ( V_19 -> V_46 ) ;
while ( ( V_8 = F_33 ( V_126 -> V_2 , & V_29 ) ) != NULL ) {
F_34 ( L_10 , V_8 ) ;
F_41 ( & V_46 -> V_127 ) ;
V_46 -> V_128 += V_8 -> V_29 ;
V_46 -> V_129 ++ ;
F_42 ( & V_46 -> V_127 ) ;
F_82 ( V_8 ) ;
}
}
static int F_83 ( struct V_125 * V_126 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_130 = ( (struct V_131 * ) V_8 -> V_132 ) -> V_133 ;
struct V_18 * V_19 = V_126 -> V_2 -> V_20 -> V_21 ;
unsigned V_134 ;
unsigned V_32 ;
bool V_135 ;
F_34 ( L_11 , V_19 -> V_22 -> V_40 , V_8 , V_130 ) ;
if ( V_19 -> V_35 )
V_32 = sizeof V_30 -> V_36 ;
else
V_32 = sizeof V_30 -> V_30 ;
V_135 = V_19 -> V_136 &&
! ( ( unsigned long ) V_8 -> V_132 & ( F_84 ( * V_30 ) - 1 ) ) &&
! F_85 ( V_8 ) && F_86 ( V_8 ) >= V_32 ;
if ( V_135 )
V_30 = (struct V_6 * ) ( V_8 -> V_132 - V_32 ) ;
else
V_30 = V_6 ( V_8 ) ;
if ( V_8 -> V_76 == V_137 ) {
V_30 -> V_30 . V_70 = V_71 ;
V_30 -> V_30 . V_72 = F_87 ( V_8 ) ;
V_30 -> V_30 . V_73 = V_8 -> V_73 ;
} else {
V_30 -> V_30 . V_70 = 0 ;
V_30 -> V_30 . V_73 = V_30 -> V_30 . V_72 = 0 ;
}
if ( F_88 ( V_8 ) ) {
V_30 -> V_30 . V_32 = F_89 ( V_8 ) ;
V_30 -> V_30 . V_90 = F_26 ( V_8 ) -> V_90 ;
if ( F_26 ( V_8 ) -> V_80 & V_84 )
V_30 -> V_30 . V_80 = V_83 ;
else if ( F_26 ( V_8 ) -> V_80 & V_88 )
V_30 -> V_30 . V_80 = V_87 ;
else if ( F_26 ( V_8 ) -> V_80 & V_86 )
V_30 -> V_30 . V_80 = V_85 ;
else
F_90 () ;
if ( F_26 ( V_8 ) -> V_80 & V_89 )
V_30 -> V_30 . V_80 |= V_82 ;
} else {
V_30 -> V_30 . V_80 = V_81 ;
V_30 -> V_30 . V_90 = V_30 -> V_30 . V_32 = 0 ;
}
if ( V_19 -> V_35 )
V_30 -> V_36 . V_50 = 0 ;
if ( V_135 ) {
F_91 ( V_8 , V_32 ) ;
V_134 = F_51 ( V_8 , V_126 -> V_97 , 0 , V_8 -> V_29 ) ;
F_92 ( V_8 , V_32 ) ;
} else {
F_50 ( V_126 -> V_97 , V_30 , V_32 ) ;
V_134 = F_51 ( V_8 , V_126 -> V_97 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_93 ( V_126 -> V_2 , V_126 -> V_97 , V_134 , V_8 , V_58 ) ;
}
static T_3 F_94 ( struct V_7 * V_8 , struct V_44 * V_22 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
int V_138 = F_95 ( V_8 ) ;
struct V_125 * V_126 = & V_19 -> V_126 [ V_138 ] ;
int V_45 ;
F_81 ( V_126 ) ;
V_45 = F_83 ( V_126 , V_8 ) ;
if ( F_17 ( V_45 ) ) {
V_22 -> V_46 . V_139 ++ ;
if ( F_96 () )
F_97 ( & V_22 -> V_22 ,
L_12 , V_138 , V_45 ) ;
V_22 -> V_46 . V_140 ++ ;
F_82 ( V_8 ) ;
return V_141 ;
}
F_62 ( V_126 -> V_2 ) ;
F_98 ( V_8 ) ;
F_99 ( V_8 ) ;
if ( V_126 -> V_2 -> V_109 < 2 + V_38 ) {
F_100 ( V_22 , V_138 ) ;
if ( F_17 ( ! F_101 ( V_126 -> V_2 ) ) ) {
F_81 ( V_126 ) ;
if ( V_126 -> V_2 -> V_109 >= 2 + V_38 ) {
F_102 ( V_22 , V_138 ) ;
F_9 ( V_126 -> V_2 ) ;
}
}
}
return V_141 ;
}
static bool F_103 ( struct V_18 * V_19 , T_4 V_142 , T_4 V_143 ,
struct V_144 * V_145 )
{
struct V_144 * V_146 [ 4 ] , V_30 , V_147 ;
struct V_148 V_149 ;
T_5 V_150 = ~ 0 ;
unsigned V_151 = 0 , V_152 ;
F_24 ( ! F_104 ( V_19 -> V_20 , V_153 ) ) ;
V_149 . V_142 = V_142 ;
V_149 . V_143 = V_143 ;
F_60 ( & V_30 , & V_149 , sizeof( V_149 ) ) ;
V_146 [ V_151 ++ ] = & V_30 ;
if ( V_145 )
V_146 [ V_151 ++ ] = V_145 ;
F_60 ( & V_147 , & V_150 , sizeof( V_150 ) ) ;
V_146 [ V_151 ] = & V_147 ;
F_24 ( V_151 + 1 > F_105 ( V_146 ) ) ;
F_106 ( V_19 -> V_154 , V_146 , V_151 , 1 , V_19 , V_58 ) ;
if ( F_17 ( ! F_62 ( V_19 -> V_154 ) ) )
return V_150 == V_155 ;
while ( ! F_33 ( V_19 -> V_154 , & V_152 ) &&
! F_107 ( V_19 -> V_154 ) )
F_108 () ;
return V_150 == V_155 ;
}
static int F_109 ( struct V_44 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
struct V_156 * V_20 = V_19 -> V_20 ;
int V_157 ;
struct V_158 * V_159 = V_17 ;
struct V_144 V_97 ;
V_157 = F_110 ( V_22 , V_17 ) ;
if ( V_157 )
return V_157 ;
if ( F_104 ( V_20 , V_160 ) ) {
F_60 ( & V_97 , V_159 -> V_161 , V_22 -> V_162 ) ;
if ( ! F_103 ( V_19 , V_163 ,
V_164 , & V_97 ) ) {
F_97 ( & V_20 -> V_22 ,
L_13 ) ;
return - V_165 ;
}
} else if ( F_104 ( V_20 , V_166 ) ) {
unsigned int V_100 ;
for ( V_100 = 0 ; V_100 < V_22 -> V_162 ; V_100 ++ )
F_111 ( V_20 ,
F_112 ( struct V_167 , V_168 ) +
V_100 , V_159 -> V_161 [ V_100 ] ) ;
}
F_113 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_169 * V_63 ( struct V_44 * V_22 ,
struct V_169 * V_170 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
int V_171 ;
unsigned int V_172 ;
F_114 (cpu) {
struct V_63 * V_46 = F_115 ( V_19 -> V_46 , V_171 ) ;
T_6 V_173 , V_174 , V_175 , V_176 ;
do {
V_172 = F_116 ( & V_46 -> V_127 ) ;
V_173 = V_46 -> V_129 ;
V_174 = V_46 -> V_128 ;
} while ( F_117 ( & V_46 -> V_127 , V_172 ) );
do {
V_172 = F_116 ( & V_46 -> V_67 ) ;
V_175 = V_46 -> V_69 ;
V_176 = V_46 -> V_68 ;
} while ( F_117 ( & V_46 -> V_67 , V_172 ) );
V_170 -> V_69 += V_175 ;
V_170 -> V_129 += V_173 ;
V_170 -> V_68 += V_176 ;
V_170 -> V_128 += V_174 ;
}
V_170 -> V_140 = V_22 -> V_46 . V_140 ;
V_170 -> V_139 = V_22 -> V_46 . V_139 ;
V_170 -> V_47 = V_22 -> V_46 . V_47 ;
V_170 -> V_55 = V_22 -> V_46 . V_55 ;
V_170 -> V_93 = V_22 -> V_46 . V_93 ;
return V_170 ;
}
static void F_118 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_116 ; V_100 ++ )
F_119 ( & V_19 -> V_11 [ V_100 ] . V_111 ) ;
}
static void F_120 ( struct V_18 * V_19 )
{
F_121 () ;
if ( ! F_103 ( V_19 , V_177 ,
V_178 , NULL ) )
F_97 ( & V_19 -> V_22 -> V_22 , L_14 ) ;
F_122 () ;
}
static int F_123 ( struct V_18 * V_19 , T_7 V_179 )
{
struct V_144 V_97 ;
struct V_180 V_181 ;
struct V_44 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_182 || ! F_104 ( V_19 -> V_20 , V_183 ) )
return 0 ;
V_181 . V_184 = V_179 ;
F_60 ( & V_97 , & V_181 , sizeof( V_181 ) ) ;
if ( ! F_103 ( V_19 , V_185 ,
V_186 , & V_97 ) ) {
F_97 ( & V_22 -> V_22 , L_15 ,
V_179 ) ;
return - V_165 ;
} else {
V_19 -> V_116 = V_179 ;
if ( V_22 -> V_70 & V_187 )
F_73 ( & V_19 -> V_114 , 0 ) ;
}
return 0 ;
}
static int F_124 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
int V_100 ;
F_125 ( & V_19 -> V_114 ) ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ )
F_72 ( & V_19 -> V_11 [ V_100 ] . V_111 ) ;
return 0 ;
}
static void F_126 ( struct V_44 * V_22 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
struct V_144 V_97 [ 2 ] ;
T_4 V_188 , V_189 ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
int V_194 ;
int V_195 ;
void * V_26 ;
int V_100 ;
if ( ! F_104 ( V_19 -> V_20 , V_196 ) )
return;
V_188 = ( ( V_22 -> V_70 & V_197 ) != 0 ) ;
V_189 = ( ( V_22 -> V_70 & V_198 ) != 0 ) ;
F_60 ( V_97 , & V_188 , sizeof( V_188 ) ) ;
if ( ! F_103 ( V_19 , V_199 ,
V_200 , V_97 ) )
F_97 ( & V_22 -> V_22 , L_16 ,
V_188 ? L_17 : L_18 ) ;
F_60 ( V_97 , & V_189 , sizeof( V_189 ) ) ;
if ( ! F_103 ( V_19 , V_199 ,
V_201 , V_97 ) )
F_97 ( & V_22 -> V_22 , L_19 ,
V_189 ? L_17 : L_18 ) ;
V_194 = F_127 ( V_22 ) ;
V_195 = F_128 ( V_22 ) ;
V_26 = F_129 ( ( ( V_194 + V_195 ) * V_202 ) +
( 2 * sizeof( V_191 -> V_203 ) ) , V_58 ) ;
V_191 = V_26 ;
if ( ! V_26 )
return;
F_130 ( V_97 , 2 ) ;
V_191 -> V_203 = V_194 ;
V_100 = 0 ;
F_131 (ha, dev)
memcpy ( & V_191 -> V_204 [ V_100 ++ ] [ 0 ] , V_193 -> V_159 , V_202 ) ;
F_50 ( & V_97 [ 0 ] , V_191 ,
sizeof( V_191 -> V_203 ) + ( V_194 * V_202 ) ) ;
V_191 = ( void * ) & V_191 -> V_204 [ V_194 ] [ 0 ] ;
V_191 -> V_203 = V_195 ;
V_100 = 0 ;
F_132 (ha, dev)
memcpy ( & V_191 -> V_204 [ V_100 ++ ] [ 0 ] , V_193 -> V_159 , V_202 ) ;
F_50 ( & V_97 [ 1 ] , V_191 ,
sizeof( V_191 -> V_203 ) + ( V_195 * V_202 ) ) ;
if ( ! F_103 ( V_19 , V_163 ,
V_205 , V_97 ) )
F_97 ( & V_22 -> V_22 , L_20 ) ;
F_133 ( V_26 ) ;
}
static int F_134 ( struct V_44 * V_22 ,
T_8 V_206 , T_7 V_207 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
struct V_144 V_97 ;
F_60 ( & V_97 , & V_207 , sizeof( V_207 ) ) ;
if ( ! F_103 ( V_19 , V_208 ,
V_209 , & V_97 ) )
F_97 ( & V_22 -> V_22 , L_21 , V_207 ) ;
return 0 ;
}
static int F_135 ( struct V_44 * V_22 ,
T_8 V_206 , T_7 V_207 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
struct V_144 V_97 ;
F_60 ( & V_97 , & V_207 , sizeof( V_207 ) ) ;
if ( ! F_103 ( V_19 , V_208 ,
V_210 , & V_97 ) )
F_97 ( & V_22 -> V_22 , L_22 , V_207 ) ;
return 0 ;
}
static void F_136 ( struct V_18 * V_19 , long V_211 )
{
int V_100 ;
if ( V_19 -> V_212 ) {
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
F_137 ( V_19 -> V_11 [ V_100 ] . V_2 , - 1 ) ;
F_137 ( V_19 -> V_126 [ V_100 ] . V_2 , - 1 ) ;
}
V_19 -> V_212 = false ;
}
}
static void F_138 ( struct V_18 * V_19 )
{
int V_100 ;
int V_171 ;
if ( V_19 -> V_116 == 1 ||
V_19 -> V_124 != F_139 () ) {
F_136 ( V_19 , - 1 ) ;
return;
}
V_100 = 0 ;
F_140 (cpu) {
F_137 ( V_19 -> V_11 [ V_100 ] . V_2 , V_171 ) ;
F_137 ( V_19 -> V_126 [ V_100 ] . V_2 , V_171 ) ;
F_141 ( V_19 -> V_22 , F_142 ( V_171 ) , V_100 ) ;
V_100 ++ ;
}
V_19 -> V_212 = true ;
}
static int F_143 ( struct V_213 * V_214 ,
unsigned long V_215 , void * V_211 )
{
struct V_18 * V_19 = F_71 ( V_214 , struct V_18 , V_216 ) ;
switch( V_215 & ~ V_217 ) {
case V_218 :
case V_219 :
case V_220 :
F_138 ( V_19 ) ;
break;
case V_221 :
F_136 ( V_19 , ( long ) V_211 ) ;
break;
default:
break;
}
return V_222 ;
}
static void F_144 ( struct V_44 * V_22 ,
struct V_223 * V_224 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
V_224 -> V_225 = F_75 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_224 -> V_226 = F_75 ( V_19 -> V_126 [ 0 ] . V_2 ) ;
V_224 -> V_227 = V_224 -> V_225 ;
V_224 -> V_228 = V_224 -> V_226 ;
}
static void F_145 ( struct V_44 * V_22 ,
struct V_229 * V_230 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
struct V_156 * V_20 = V_19 -> V_20 ;
F_146 ( V_230 -> V_231 , V_232 , sizeof( V_230 -> V_231 ) ) ;
F_146 ( V_230 -> V_233 , V_234 , sizeof( V_230 -> V_233 ) ) ;
F_146 ( V_230 -> V_235 , F_147 ( V_20 ) , sizeof( V_230 -> V_235 ) ) ;
}
static int F_148 ( struct V_44 * V_22 ,
struct V_236 * V_237 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
T_7 V_179 = V_237 -> V_238 ;
int V_45 ;
if ( V_237 -> V_239 || V_237 -> V_240 || V_237 -> V_241 )
return - V_165 ;
if ( V_179 > V_19 -> V_124 || V_179 == 0 )
return - V_165 ;
F_149 () ;
V_45 = F_123 ( V_19 , V_179 ) ;
if ( ! V_45 ) {
F_150 ( V_22 , V_179 ) ;
F_151 ( V_22 , V_179 ) ;
F_138 ( V_19 ) ;
}
F_152 () ;
return V_45 ;
}
static void F_153 ( struct V_44 * V_22 ,
struct V_236 * V_237 )
{
struct V_18 * V_19 = F_80 ( V_22 ) ;
V_237 -> V_238 = V_19 -> V_116 ;
V_237 -> V_242 = V_19 -> V_124 ;
V_237 -> V_243 = 0 ;
V_237 -> V_239 = 0 ;
V_237 -> V_240 = 0 ;
V_237 -> V_241 = 0 ;
}
static int F_154 ( struct V_44 * V_22 , int V_244 )
{
if ( V_244 < V_245 || V_244 > V_246 )
return - V_165 ;
V_22 -> V_247 = V_244 ;
return 0 ;
}
static void F_155 ( struct V_112 * V_113 )
{
struct V_18 * V_19 =
F_71 ( V_113 , struct V_18 , V_248 ) ;
T_7 V_249 ;
F_156 ( & V_19 -> V_250 ) ;
if ( ! V_19 -> V_251 )
goto V_252;
if ( F_157 ( V_19 -> V_20 , V_253 ,
struct V_167 , V_150 , & V_249 ) < 0 )
goto V_252;
if ( V_249 & V_254 ) {
F_158 ( V_19 -> V_22 ) ;
F_120 ( V_19 ) ;
}
V_249 &= V_255 ;
if ( V_19 -> V_150 == V_249 )
goto V_252;
V_19 -> V_150 = V_249 ;
if ( V_19 -> V_150 & V_255 ) {
F_159 ( V_19 -> V_22 ) ;
F_160 ( V_19 -> V_22 ) ;
} else {
F_161 ( V_19 -> V_22 ) ;
F_162 ( V_19 -> V_22 ) ;
}
V_252:
F_163 ( & V_19 -> V_250 ) ;
}
static void F_164 ( struct V_156 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_165 ( & V_19 -> V_248 ) ;
}
static void F_166 ( struct V_18 * V_19 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ )
F_167 ( & V_19 -> V_11 [ V_100 ] . V_111 ) ;
F_133 ( V_19 -> V_11 ) ;
F_133 ( V_19 -> V_126 ) ;
}
static void F_168 ( struct V_18 * V_19 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
while ( V_19 -> V_11 [ V_100 ] . V_15 )
F_169 ( F_6 ( & V_19 -> V_11 [ V_100 ] , V_117 ) , 0 ) ;
}
}
static void F_170 ( struct V_18 * V_19 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ )
if ( V_19 -> V_11 [ V_100 ] . V_105 . V_12 )
F_21 ( V_19 -> V_11 [ V_100 ] . V_105 . V_12 ) ;
}
static void F_171 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
struct V_1 * V_2 = V_19 -> V_126 [ V_100 ] . V_2 ;
while ( ( V_26 = F_172 ( V_2 ) ) != NULL )
F_23 ( V_26 ) ;
}
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_100 ] . V_2 ;
while ( ( V_26 = F_172 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_35 ) {
unsigned long V_48 = ( unsigned long ) V_26 ;
void * V_65 = F_12 ( V_48 ) ;
F_21 ( F_31 ( V_65 ) ) ;
} else if ( V_19 -> V_66 ) {
F_5 ( & V_19 -> V_11 [ V_100 ] , V_26 ) ;
} else {
F_23 ( V_26 ) ;
}
}
}
}
static void F_173 ( struct V_18 * V_19 )
{
struct V_156 * V_20 = V_19 -> V_20 ;
F_136 ( V_19 , - 1 ) ;
V_20 -> V_256 -> V_257 ( V_20 ) ;
F_166 ( V_19 ) ;
}
static int F_174 ( struct V_18 * V_19 )
{
T_9 * * V_258 ;
struct V_1 * * V_259 ;
int V_157 = - V_96 ;
int V_100 , V_260 ;
const char * * V_261 ;
V_260 = V_19 -> V_124 * 2 +
F_104 ( V_19 -> V_20 , V_153 ) ;
V_259 = F_129 ( V_260 * sizeof( * V_259 ) , V_117 ) ;
if ( ! V_259 )
goto V_262;
V_258 = F_175 ( V_260 * sizeof( * V_258 ) , V_117 ) ;
if ( ! V_258 )
goto V_263;
V_261 = F_175 ( V_260 * sizeof( * V_261 ) , V_117 ) ;
if ( ! V_261 )
goto V_264;
if ( V_19 -> V_182 ) {
V_258 [ V_260 - 1 ] = NULL ;
V_261 [ V_260 - 1 ] = L_23 ;
}
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
V_258 [ F_4 ( V_100 ) ] = F_63 ;
V_258 [ F_2 ( V_100 ) ] = F_8 ;
sprintf ( V_19 -> V_11 [ V_100 ] . V_40 , L_24 , V_100 ) ;
sprintf ( V_19 -> V_126 [ V_100 ] . V_40 , L_25 , V_100 ) ;
V_261 [ F_4 ( V_100 ) ] = V_19 -> V_11 [ V_100 ] . V_40 ;
V_261 [ F_2 ( V_100 ) ] = V_19 -> V_126 [ V_100 ] . V_40 ;
}
V_157 = V_19 -> V_20 -> V_256 -> V_265 ( V_19 -> V_20 , V_260 , V_259 , V_258 ,
V_261 ) ;
if ( V_157 )
goto V_266;
if ( V_19 -> V_182 ) {
V_19 -> V_154 = V_259 [ V_260 - 1 ] ;
if ( F_104 ( V_19 -> V_20 , V_267 ) )
V_19 -> V_22 -> V_268 |= V_269 ;
}
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
V_19 -> V_11 [ V_100 ] . V_2 = V_259 [ F_4 ( V_100 ) ] ;
V_19 -> V_126 [ V_100 ] . V_2 = V_259 [ F_2 ( V_100 ) ] ;
}
F_133 ( V_261 ) ;
F_133 ( V_258 ) ;
F_133 ( V_259 ) ;
return 0 ;
V_266:
F_133 ( V_261 ) ;
V_264:
F_133 ( V_258 ) ;
V_263:
F_133 ( V_259 ) ;
V_262:
return V_157 ;
}
static int F_176 ( struct V_18 * V_19 )
{
int V_100 ;
V_19 -> V_126 = F_129 ( sizeof( * V_19 -> V_126 ) * V_19 -> V_124 , V_117 ) ;
if ( ! V_19 -> V_126 )
goto V_270;
V_19 -> V_11 = F_129 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_124 , V_117 ) ;
if ( ! V_19 -> V_11 )
goto V_271;
F_177 ( & V_19 -> V_114 , F_70 ) ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
V_19 -> V_11 [ V_100 ] . V_15 = NULL ;
F_178 ( V_19 -> V_22 , & V_19 -> V_11 [ V_100 ] . V_111 , F_74 ,
V_272 ) ;
F_130 ( V_19 -> V_11 [ V_100 ] . V_97 , F_105 ( V_19 -> V_11 [ V_100 ] . V_97 ) ) ;
F_179 ( & V_19 -> V_11 [ V_100 ] . V_62 , 1 , V_273 ) ;
F_130 ( V_19 -> V_126 [ V_100 ] . V_97 , F_105 ( V_19 -> V_126 [ V_100 ] . V_97 ) ) ;
}
return 0 ;
V_271:
F_133 ( V_19 -> V_126 ) ;
V_270:
return - V_96 ;
}
static int F_180 ( struct V_18 * V_19 )
{
int V_157 ;
V_157 = F_176 ( V_19 ) ;
if ( V_157 )
goto V_45;
V_157 = F_174 ( V_19 ) ;
if ( V_157 )
goto V_274;
F_149 () ;
F_138 ( V_19 ) ;
F_152 () ;
return 0 ;
V_274:
F_166 ( V_19 ) ;
V_45:
return V_157 ;
}
static T_10 F_181 ( struct V_275 * V_276 ,
struct V_277 * V_278 , char * V_26 )
{
struct V_18 * V_19 = F_80 ( V_276 -> V_22 ) ;
unsigned int V_279 = F_182 ( V_276 ) ;
struct V_101 * V_280 ;
F_24 ( V_279 >= V_19 -> V_124 ) ;
V_280 = & V_19 -> V_11 [ V_279 ] . V_62 ;
return sprintf ( V_26 , L_26 , F_54 ( V_280 ) ) ;
}
static int F_183 ( struct V_156 * V_20 )
{
int V_100 , V_45 ;
struct V_44 * V_22 ;
struct V_18 * V_19 ;
T_7 V_124 ;
V_45 = F_157 ( V_20 , V_183 ,
struct V_167 ,
V_281 , & V_124 ) ;
if ( V_45 || V_124 < V_282 ||
V_124 > V_283 ||
! F_104 ( V_20 , V_153 ) )
V_124 = 1 ;
V_22 = F_184 ( sizeof( struct V_18 ) , V_124 ) ;
if ( ! V_22 )
return - V_96 ;
V_22 -> V_284 |= V_285 | V_286 ;
V_22 -> V_287 = & V_288 ;
V_22 -> V_268 = V_289 ;
V_22 -> V_290 = & V_291 ;
F_185 ( V_22 , & V_20 -> V_22 ) ;
if ( F_104 ( V_20 , V_292 ) ) {
V_22 -> V_293 |= V_294 | V_295 | V_296 ;
if ( V_297 )
V_22 -> V_268 |= V_294 | V_295 | V_296 ;
if ( F_104 ( V_20 , V_298 ) ) {
V_22 -> V_293 |= V_299 | V_300
| V_301 | V_302 ;
}
if ( F_104 ( V_20 , V_303 ) )
V_22 -> V_293 |= V_299 ;
if ( F_104 ( V_20 , V_304 ) )
V_22 -> V_293 |= V_302 ;
if ( F_104 ( V_20 , V_305 ) )
V_22 -> V_293 |= V_301 ;
if ( F_104 ( V_20 , V_306 ) )
V_22 -> V_293 |= V_300 ;
if ( V_307 )
V_22 -> V_268 |= V_22 -> V_293 & ( V_308 | V_300 ) ;
}
if ( F_104 ( V_20 , V_309 ) )
V_22 -> V_268 |= V_310 ;
V_22 -> V_311 = V_22 -> V_268 ;
if ( F_104 ( V_20 , V_166 ) )
F_186 ( V_20 ,
F_112 ( struct V_167 , V_168 ) ,
V_22 -> V_312 , V_22 -> V_162 ) ;
else
F_187 ( V_22 ) ;
V_19 = F_80 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_46 = F_188 ( struct V_63 ) ;
V_45 = - V_96 ;
if ( V_19 -> V_46 == NULL )
goto free;
F_114 (i) {
struct V_63 * V_63 ;
V_63 = F_115 ( V_19 -> V_46 , V_100 ) ;
F_189 ( & V_63 -> V_127 ) ;
F_189 ( & V_63 -> V_67 ) ;
}
F_190 ( & V_19 -> V_250 ) ;
V_19 -> V_251 = true ;
F_191 ( & V_19 -> V_248 , F_155 ) ;
if ( F_104 ( V_20 , V_313 ) ||
F_104 ( V_20 , V_314 ) ||
F_104 ( V_20 , V_315 ) ||
F_104 ( V_20 , V_316 ) )
V_19 -> V_66 = true ;
if ( F_104 ( V_20 , V_317 ) )
V_19 -> V_35 = true ;
if ( F_104 ( V_20 , V_318 ) )
V_19 -> V_136 = true ;
if ( F_104 ( V_20 , V_153 ) )
V_19 -> V_182 = true ;
if ( V_19 -> V_136 ) {
if ( V_19 -> V_35 )
V_22 -> V_319 = sizeof( struct V_103 ) ;
else
V_22 -> V_319 = sizeof( struct V_43 ) ;
}
V_19 -> V_116 = 1 ;
V_19 -> V_124 = V_124 ;
V_45 = F_180 ( V_19 ) ;
if ( V_45 )
goto V_320;
#ifdef F_192
if ( V_19 -> V_35 )
V_22 -> V_321 = & V_322 ;
#endif
F_150 ( V_22 , V_19 -> V_116 ) ;
F_151 ( V_22 , V_19 -> V_116 ) ;
V_45 = F_193 ( V_22 ) ;
if ( V_45 ) {
F_34 ( L_27 ) ;
goto V_323;
}
for ( V_100 = 0 ; V_100 < V_19 -> V_116 ; V_100 ++ ) {
F_61 ( & V_19 -> V_11 [ V_100 ] , V_117 ) ;
if ( V_19 -> V_11 [ V_100 ] . V_2 -> V_109 ==
F_75 ( V_19 -> V_11 [ V_100 ] . V_2 ) ) {
F_171 ( V_19 ) ;
V_45 = - V_96 ;
goto V_324;
}
}
V_19 -> V_216 . V_325 = & F_143 ;
V_45 = F_194 ( & V_19 -> V_216 ) ;
if ( V_45 ) {
F_34 ( L_28 ) ;
goto V_324;
}
if ( F_104 ( V_19 -> V_20 , V_253 ) ) {
F_161 ( V_22 ) ;
F_165 ( & V_19 -> V_248 ) ;
} else {
V_19 -> V_150 = V_255 ;
F_159 ( V_22 ) ;
}
F_34 ( L_29 ,
V_22 -> V_40 , V_124 ) ;
return 0 ;
V_324:
F_168 ( V_19 ) ;
F_195 ( V_22 ) ;
V_323:
F_125 ( & V_19 -> V_114 ) ;
F_170 ( V_19 ) ;
F_173 ( V_19 ) ;
V_320:
F_196 ( V_19 -> V_46 ) ;
free:
F_197 ( V_22 ) ;
return V_45 ;
}
static void F_198 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_256 -> V_326 ( V_19 -> V_20 ) ;
F_171 ( V_19 ) ;
F_168 ( V_19 ) ;
F_170 ( V_19 ) ;
F_173 ( V_19 ) ;
}
static void F_199 ( struct V_156 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_200 ( & V_19 -> V_216 ) ;
F_156 ( & V_19 -> V_250 ) ;
V_19 -> V_251 = false ;
F_163 ( & V_19 -> V_250 ) ;
F_195 ( V_19 -> V_22 ) ;
F_198 ( V_19 ) ;
F_201 ( & V_19 -> V_248 ) ;
F_196 ( V_19 -> V_46 ) ;
F_197 ( V_19 -> V_22 ) ;
}
static int F_202 ( struct V_156 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_100 ;
F_200 ( & V_19 -> V_216 ) ;
F_156 ( & V_19 -> V_250 ) ;
V_19 -> V_251 = false ;
F_163 ( & V_19 -> V_250 ) ;
F_203 ( V_19 -> V_22 ) ;
F_125 ( & V_19 -> V_114 ) ;
if ( F_204 ( V_19 -> V_22 ) )
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ ) {
F_72 ( & V_19 -> V_11 [ V_100 ] . V_111 ) ;
F_167 ( & V_19 -> V_11 [ V_100 ] . V_111 ) ;
}
F_198 ( V_19 ) ;
F_201 ( & V_19 -> V_248 ) ;
return 0 ;
}
static int F_205 ( struct V_156 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_45 , V_100 ;
V_45 = F_180 ( V_19 ) ;
if ( V_45 )
return V_45 ;
if ( F_204 ( V_19 -> V_22 ) ) {
for ( V_100 = 0 ; V_100 < V_19 -> V_116 ; V_100 ++ )
if ( ! F_61 ( & V_19 -> V_11 [ V_100 ] , V_117 ) )
F_73 ( & V_19 -> V_114 , 0 ) ;
for ( V_100 = 0 ; V_100 < V_19 -> V_124 ; V_100 ++ )
F_66 ( & V_19 -> V_11 [ V_100 ] ) ;
}
F_206 ( V_19 -> V_22 ) ;
F_156 ( & V_19 -> V_250 ) ;
V_19 -> V_251 = true ;
F_163 ( & V_19 -> V_250 ) ;
F_121 () ;
F_123 ( V_19 , V_19 -> V_116 ) ;
F_122 () ;
V_45 = F_194 ( & V_19 -> V_216 ) ;
if ( V_45 )
return V_45 ;
return 0 ;
}
