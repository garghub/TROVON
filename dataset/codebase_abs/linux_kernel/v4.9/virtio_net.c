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
static inline struct V_6 * F_5 ( struct V_7 * V_8 )
{
return (struct V_6 * ) V_8 -> V_9 ;
}
static void F_6 ( struct V_10 * V_11 , struct V_12 * V_12 )
{
struct V_12 * V_13 ;
for ( V_13 = V_12 ; V_13 -> V_14 ; V_13 = (struct V_12 * ) V_13 -> V_14 ) ;
V_13 -> V_14 = ( unsigned long ) V_11 -> V_15 ;
V_11 -> V_15 = V_12 ;
}
static struct V_12 * F_7 ( struct V_10 * V_11 , T_1 V_16 )
{
struct V_12 * V_17 = V_11 -> V_15 ;
if ( V_17 ) {
V_11 -> V_15 = (struct V_12 * ) V_17 -> V_14 ;
V_17 -> V_14 = 0 ;
} else
V_17 = F_8 ( V_16 ) ;
return V_17 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
F_10 ( V_2 ) ;
F_11 ( V_19 -> V_22 , F_1 ( V_2 ) ) ;
}
static unsigned int F_12 ( unsigned long V_23 )
{
unsigned int V_24 = V_23 & ( V_25 - 1 ) ;
return ( V_24 + 1 ) * V_25 ;
}
static void * F_13 ( unsigned long V_23 )
{
return ( void * ) ( V_23 & - V_25 ) ;
}
static unsigned long F_14 ( void * V_26 , unsigned int V_24 )
{
unsigned int V_27 = V_24 / V_25 ;
return ( unsigned long ) V_26 | ( V_27 - 1 ) ;
}
static struct V_7 * F_15 ( struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_12 * V_12 , unsigned int V_28 ,
unsigned int V_29 , unsigned int V_24 )
{
struct V_7 * V_8 ;
struct V_6 * V_30 ;
unsigned int V_31 , V_32 , V_33 ;
char * V_17 ;
V_17 = F_16 ( V_12 ) + V_28 ;
V_8 = F_17 ( & V_11 -> V_34 , V_35 ) ;
if ( F_18 ( ! V_8 ) )
return NULL ;
V_30 = F_5 ( V_8 ) ;
V_32 = V_19 -> V_32 ;
if ( V_19 -> V_36 )
V_33 = sizeof *V_30 ;
else
V_33 = sizeof( struct V_37 ) ;
memcpy ( V_30 , V_17 , V_32 ) ;
V_29 -= V_32 ;
V_28 += V_33 ;
V_17 += V_33 ;
V_31 = V_29 ;
if ( V_31 > F_19 ( V_8 ) )
V_31 = F_19 ( V_8 ) ;
memcpy ( F_20 ( V_8 , V_31 ) , V_17 , V_31 ) ;
V_29 -= V_31 ;
V_28 += V_31 ;
if ( V_19 -> V_36 ) {
if ( V_29 )
F_21 ( V_8 , 0 , V_12 , V_28 , V_29 , V_24 ) ;
else
F_22 ( V_12 ) ;
return V_8 ;
}
if ( F_18 ( V_29 > V_38 * V_39 ) ) {
F_23 ( L_1 , V_8 -> V_22 -> V_40 ) ;
F_24 ( V_8 ) ;
return NULL ;
}
F_25 ( V_28 >= V_39 ) ;
while ( V_29 ) {
unsigned int V_41 = F_26 ( ( unsigned ) V_39 - V_28 , V_29 ) ;
F_21 ( V_8 , F_27 ( V_8 ) -> V_42 , V_12 , V_28 ,
V_41 , V_24 ) ;
V_29 -= V_41 ;
V_12 = (struct V_12 * ) V_12 -> V_14 ;
V_28 = 0 ;
}
if ( V_12 )
F_6 ( V_11 , V_12 ) ;
return V_8 ;
}
static struct V_7 * F_28 ( struct V_18 * V_19 , void * V_26 , unsigned int V_29 )
{
struct V_7 * V_8 = V_26 ;
V_29 -= V_19 -> V_32 ;
F_29 ( V_8 , V_29 ) ;
return V_8 ;
}
static struct V_7 * F_30 ( struct V_43 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
void * V_26 ,
unsigned int V_29 )
{
struct V_12 * V_12 = V_26 ;
struct V_7 * V_8 = F_15 ( V_19 , V_11 , V_12 , 0 , V_29 , V_39 ) ;
if ( F_18 ( ! V_8 ) )
goto V_44;
return V_8 ;
V_44:
V_22 -> V_45 . V_46 ++ ;
F_6 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_7 * F_31 ( struct V_43 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
unsigned long V_47 ,
unsigned int V_29 )
{
void * V_26 = F_13 ( V_47 ) ;
struct V_6 * V_30 = V_26 ;
T_2 V_48 = F_32 ( V_19 -> V_20 , V_30 -> V_49 ) ;
struct V_12 * V_12 = F_33 ( V_26 ) ;
int V_28 = V_26 - F_16 ( V_12 ) ;
unsigned int V_24 = F_34 ( V_29 , F_12 ( V_47 ) ) ;
struct V_7 * V_50 = F_15 ( V_19 , V_11 , V_12 , V_28 , V_29 ,
V_24 ) ;
struct V_7 * V_51 = V_50 ;
if ( F_18 ( ! V_51 ) )
goto V_52;
while ( -- V_48 ) {
int V_53 ;
V_47 = ( unsigned long ) F_35 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_47 ) ) {
F_36 ( L_2 ,
V_22 -> V_40 , V_48 ,
F_32 ( V_19 -> V_20 ,
V_30 -> V_49 ) ) ;
V_22 -> V_45 . V_54 ++ ;
goto V_55;
}
V_26 = F_13 ( V_47 ) ;
V_12 = F_33 ( V_26 ) ;
V_53 = F_27 ( V_51 ) -> V_42 ;
if ( F_18 ( V_53 == V_38 ) ) {
struct V_7 * V_56 = F_37 ( 0 , V_57 ) ;
if ( F_18 ( ! V_56 ) )
goto V_52;
if ( V_51 == V_50 )
F_27 ( V_51 ) -> V_58 = V_56 ;
else
V_51 -> V_59 = V_56 ;
V_51 = V_56 ;
V_50 -> V_24 += V_56 -> V_24 ;
V_53 = 0 ;
}
V_24 = F_34 ( V_29 , F_12 ( V_47 ) ) ;
if ( V_51 != V_50 ) {
V_50 -> V_60 += V_29 ;
V_50 -> V_29 += V_29 ;
V_50 -> V_24 += V_24 ;
}
V_28 = V_26 - F_16 ( V_12 ) ;
if ( F_38 ( V_51 , V_53 , V_12 , V_28 ) ) {
F_22 ( V_12 ) ;
F_39 ( V_51 , V_53 - 1 ,
V_29 , V_24 ) ;
} else {
F_21 ( V_51 , V_53 , V_12 ,
V_28 , V_29 , V_24 ) ;
}
}
F_40 ( & V_11 -> V_61 , V_50 -> V_29 ) ;
return V_50 ;
V_52:
F_22 ( V_12 ) ;
while ( -- V_48 ) {
V_47 = ( unsigned long ) F_35 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_47 ) ) {
F_36 ( L_3 ,
V_22 -> V_40 , V_48 ) ;
V_22 -> V_45 . V_54 ++ ;
break;
}
V_12 = F_33 ( F_13 ( V_47 ) ) ;
F_22 ( V_12 ) ;
}
V_55:
V_22 -> V_45 . V_46 ++ ;
F_24 ( V_50 ) ;
return NULL ;
}
static void F_41 ( struct V_18 * V_19 , struct V_10 * V_11 ,
void * V_26 , unsigned int V_29 )
{
struct V_43 * V_22 = V_19 -> V_22 ;
struct V_62 * V_45 = F_42 ( V_19 -> V_45 ) ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
if ( F_18 ( V_29 < V_19 -> V_32 + V_63 ) ) {
F_36 ( L_4 , V_22 -> V_40 , V_29 ) ;
V_22 -> V_45 . V_54 ++ ;
if ( V_19 -> V_36 ) {
unsigned long V_47 = ( unsigned long ) V_26 ;
void * V_64 = F_13 ( V_47 ) ;
F_22 ( F_33 ( V_64 ) ) ;
} else if ( V_19 -> V_65 ) {
F_6 ( V_11 , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
return;
}
if ( V_19 -> V_36 )
V_8 = F_31 ( V_22 , V_19 , V_11 , ( unsigned long ) V_26 , V_29 ) ;
else if ( V_19 -> V_65 )
V_8 = F_30 ( V_22 , V_19 , V_11 , V_26 , V_29 ) ;
else
V_8 = F_28 ( V_19 , V_26 , V_29 ) ;
if ( F_18 ( ! V_8 ) )
return;
V_30 = F_5 ( V_8 ) ;
F_43 ( & V_45 -> V_66 ) ;
V_45 -> V_67 += V_8 -> V_29 ;
V_45 -> V_68 ++ ;
F_44 ( & V_45 -> V_66 ) ;
if ( V_30 -> V_30 . V_69 & V_70 )
V_8 -> V_71 = V_72 ;
if ( F_45 ( V_8 , & V_30 -> V_30 ,
F_46 ( V_19 -> V_20 ) ) ) {
F_47 ( L_5 ,
V_22 -> V_40 , V_30 -> V_30 . V_73 ,
V_30 -> V_30 . V_74 ) ;
goto V_75;
}
V_8 -> V_76 = F_48 ( V_8 , V_22 ) ;
F_36 ( L_6 ,
F_49 ( V_8 -> V_76 ) , V_8 -> V_29 , V_8 -> V_77 ) ;
F_50 ( & V_11 -> V_34 , V_8 ) ;
return;
V_75:
V_22 -> V_45 . V_78 ++ ;
F_24 ( V_8 ) ;
}
static int F_51 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_79 )
{
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_44 ;
V_8 = F_52 ( V_19 -> V_22 , V_80 , V_79 ) ;
if ( F_18 ( ! V_8 ) )
return - V_81 ;
F_20 ( V_8 , V_80 ) ;
V_30 = F_5 ( V_8 ) ;
F_53 ( V_11 -> V_82 , 2 ) ;
F_54 ( V_11 -> V_82 , V_30 , V_19 -> V_32 ) ;
F_55 ( V_8 , V_11 -> V_82 + 1 , 0 , V_8 -> V_29 ) ;
V_44 = F_56 ( V_11 -> V_2 , V_11 -> V_82 , 2 , V_8 , V_79 ) ;
if ( V_44 < 0 )
F_24 ( V_8 ) ;
return V_44 ;
}
static int F_57 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_79 )
{
struct V_12 * V_83 , * V_84 = NULL ;
char * V_17 ;
int V_85 , V_44 , V_28 ;
F_53 ( V_11 -> V_82 , V_38 + 2 ) ;
for ( V_85 = V_38 + 1 ; V_85 > 1 ; -- V_85 ) {
V_83 = F_7 ( V_11 , V_79 ) ;
if ( ! V_83 ) {
if ( V_84 )
F_6 ( V_11 , V_84 ) ;
return - V_81 ;
}
F_54 ( & V_11 -> V_82 [ V_85 ] , F_16 ( V_83 ) , V_39 ) ;
V_83 -> V_14 = ( unsigned long ) V_84 ;
V_84 = V_83 ;
}
V_83 = F_7 ( V_11 , V_79 ) ;
if ( ! V_83 ) {
F_6 ( V_11 , V_84 ) ;
return - V_81 ;
}
V_17 = F_16 ( V_83 ) ;
F_54 ( & V_11 -> V_82 [ 0 ] , V_17 , V_19 -> V_32 ) ;
V_28 = sizeof( struct V_37 ) ;
F_54 ( & V_11 -> V_82 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_83 -> V_14 = ( unsigned long ) V_84 ;
V_44 = F_56 ( V_11 -> V_2 , V_11 -> V_82 , V_38 + 2 ,
V_83 , V_79 ) ;
if ( V_44 < 0 )
F_6 ( V_11 , V_83 ) ;
return V_44 ;
}
static unsigned int F_58 ( struct V_86 * V_87 )
{
const T_3 V_32 = sizeof( struct V_6 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_59 (unsigned int, ewma_pkt_len_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_60 ( V_29 , V_25 ) ;
}
static int F_61 ( struct V_10 * V_11 , T_1 V_79 )
{
struct V_88 * V_89 = & V_11 -> V_89 ;
char * V_26 ;
unsigned long V_47 ;
int V_44 ;
unsigned int V_29 , V_90 ;
V_29 = F_58 ( & V_11 -> V_61 ) ;
if ( F_18 ( ! F_62 ( V_29 , V_89 , V_79 ) ) )
return - V_81 ;
V_26 = ( char * ) F_16 ( V_89 -> V_12 ) + V_89 -> V_28 ;
V_47 = F_14 ( V_26 , V_29 ) ;
F_63 ( V_89 -> V_12 ) ;
V_89 -> V_28 += V_29 ;
V_90 = V_89 -> V_27 - V_89 -> V_28 ;
if ( V_90 < V_29 ) {
V_29 += V_90 ;
V_89 -> V_28 += V_90 ;
}
F_64 ( V_11 -> V_82 , V_26 , V_29 ) ;
V_44 = F_56 ( V_11 -> V_2 , V_11 -> V_82 , 1 , ( void * ) V_47 , V_79 ) ;
if ( V_44 < 0 )
F_22 ( F_33 ( V_26 ) ) ;
return V_44 ;
}
static bool F_65 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_79 )
{
int V_44 ;
bool V_91 ;
V_79 |= V_92 ;
do {
if ( V_19 -> V_36 )
V_44 = F_61 ( V_11 , V_79 ) ;
else if ( V_19 -> V_65 )
V_44 = F_57 ( V_19 , V_11 , V_79 ) ;
else
V_44 = F_51 ( V_19 , V_11 , V_79 ) ;
V_91 = V_44 == - V_81 ;
if ( V_44 )
break;
} while ( V_11 -> V_2 -> V_93 );
F_66 ( V_11 -> V_2 ) ;
return ! V_91 ;
}
static void F_67 ( struct V_1 * V_94 )
{
struct V_18 * V_19 = V_94 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_94 ) ] ;
if ( F_68 ( & V_11 -> V_34 ) ) {
F_10 ( V_94 ) ;
F_69 ( & V_11 -> V_34 ) ;
}
}
static void F_70 ( struct V_10 * V_11 )
{
F_71 ( & V_11 -> V_34 ) ;
if ( F_68 ( & V_11 -> V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_72 () ;
F_69 ( & V_11 -> V_34 ) ;
F_73 () ;
}
}
static void F_74 ( struct V_95 * V_96 )
{
struct V_18 * V_19 =
F_75 ( V_96 , struct V_18 , V_97 . V_96 ) ;
bool V_98 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_99 ; V_85 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_85 ] ;
F_76 ( & V_11 -> V_34 ) ;
V_98 = ! F_65 ( V_19 , V_11 , V_100 ) ;
F_70 ( V_11 ) ;
if ( V_98 )
F_77 ( & V_19 -> V_97 , V_101 / 2 ) ;
}
}
static int F_78 ( struct V_10 * V_11 , int V_102 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_103 = 0 ;
void * V_26 ;
while ( V_103 < V_102 &&
( V_26 = F_35 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_41 ( V_19 , V_11 , V_26 , V_29 ) ;
V_103 ++ ;
}
if ( V_11 -> V_2 -> V_93 > F_79 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_65 ( V_19 , V_11 , V_57 ) )
F_77 ( & V_19 -> V_97 , 0 ) ;
}
return V_103 ;
}
static int F_80 ( struct V_104 * V_34 , int V_102 )
{
struct V_10 * V_11 =
F_75 ( V_34 , struct V_10 , V_34 ) ;
unsigned int V_105 , V_103 ;
V_103 = F_78 ( V_11 , V_102 ) ;
if ( V_103 < V_102 ) {
V_105 = F_81 ( V_11 -> V_2 ) ;
F_82 ( V_34 , V_103 ) ;
if ( F_18 ( F_83 ( V_11 -> V_2 , V_105 ) ) &&
F_68 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_69 ( V_34 ) ;
}
}
return V_103 ;
}
static int F_84 ( struct V_104 * V_34 )
{
struct V_10 * V_11 =
F_75 ( V_34 , struct V_10 , V_34 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_105 , V_103 = 0 , V_102 = 4 ;
if ( ! ( V_19 -> V_106 & V_107 ) )
return V_108 ;
if ( ! F_68 ( V_34 ) )
return V_109 ;
F_10 ( V_11 -> V_2 ) ;
V_110:
V_103 += F_78 ( V_11 , V_102 ) ;
V_105 = F_81 ( V_11 -> V_2 ) ;
F_85 ( V_111 , & V_34 -> V_112 ) ;
if ( F_18 ( F_83 ( V_11 -> V_2 , V_105 ) ) &&
F_68 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
if ( V_103 < V_102 ) {
V_102 -= V_103 ;
goto V_110;
} else {
F_69 ( V_34 ) ;
}
}
return V_103 ;
}
static int F_86 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
if ( V_85 < V_19 -> V_99 )
if ( ! F_65 ( V_19 , & V_19 -> V_11 [ V_85 ] , V_100 ) )
F_77 ( & V_19 -> V_97 , 0 ) ;
F_70 ( & V_19 -> V_11 [ V_85 ] ) ;
}
return 0 ;
}
static void F_88 ( struct V_114 * V_115 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_115 -> V_2 -> V_20 -> V_21 ;
struct V_62 * V_45 = F_42 ( V_19 -> V_45 ) ;
while ( ( V_8 = F_35 ( V_115 -> V_2 , & V_29 ) ) != NULL ) {
F_36 ( L_7 , V_8 ) ;
F_43 ( & V_45 -> V_116 ) ;
V_45 -> V_117 += V_8 -> V_29 ;
V_45 -> V_118 ++ ;
F_44 ( & V_45 -> V_116 ) ;
F_89 ( V_8 ) ;
}
}
static int F_90 ( struct V_114 * V_115 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_119 = ( (struct V_120 * ) V_8 -> V_121 ) -> V_122 ;
struct V_18 * V_19 = V_115 -> V_2 -> V_20 -> V_21 ;
unsigned V_123 ;
unsigned V_32 = V_19 -> V_32 ;
bool V_124 ;
F_36 ( L_8 , V_19 -> V_22 -> V_40 , V_8 , V_119 ) ;
V_124 = V_19 -> V_125 &&
! ( ( unsigned long ) V_8 -> V_121 & ( F_91 ( * V_30 ) - 1 ) ) &&
! F_92 ( V_8 ) && F_93 ( V_8 ) >= V_32 ;
if ( V_124 )
V_30 = (struct V_6 * ) ( V_8 -> V_121 - V_32 ) ;
else
V_30 = F_5 ( V_8 ) ;
if ( F_94 ( V_8 , & V_30 -> V_30 ,
F_46 ( V_19 -> V_20 ) ) )
F_95 () ;
if ( V_19 -> V_36 )
V_30 -> V_49 = 0 ;
F_53 ( V_115 -> V_82 , F_27 ( V_8 ) -> V_42 + ( V_124 ? 1 : 2 ) ) ;
if ( V_124 ) {
F_96 ( V_8 , V_32 ) ;
V_123 = F_55 ( V_8 , V_115 -> V_82 , 0 , V_8 -> V_29 ) ;
F_97 ( V_8 , V_32 ) ;
} else {
F_54 ( V_115 -> V_82 , V_30 , V_32 ) ;
V_123 = F_55 ( V_8 , V_115 -> V_82 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_98 ( V_115 -> V_2 , V_115 -> V_82 , V_123 , V_8 , V_57 ) ;
}
static T_4 F_99 ( struct V_7 * V_8 , struct V_43 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_126 = F_100 ( V_8 ) ;
struct V_114 * V_115 = & V_19 -> V_115 [ V_126 ] ;
int V_44 ;
struct V_127 * V_4 = F_101 ( V_22 , V_126 ) ;
bool V_128 = ! V_8 -> V_129 ;
F_88 ( V_115 ) ;
F_102 ( V_8 ) ;
V_44 = F_90 ( V_115 , V_8 ) ;
if ( F_18 ( V_44 ) ) {
V_22 -> V_45 . V_130 ++ ;
if ( F_103 () )
F_104 ( & V_22 -> V_22 ,
L_9 , V_126 , V_44 ) ;
V_22 -> V_45 . V_131 ++ ;
F_89 ( V_8 ) ;
return V_132 ;
}
F_105 ( V_8 ) ;
F_106 ( V_8 ) ;
if ( V_115 -> V_2 -> V_93 < 2 + V_38 ) {
F_107 ( V_22 , V_126 ) ;
if ( F_18 ( ! F_108 ( V_115 -> V_2 ) ) ) {
F_88 ( V_115 ) ;
if ( V_115 -> V_2 -> V_93 >= 2 + V_38 ) {
F_109 ( V_22 , V_126 ) ;
F_10 ( V_115 -> V_2 ) ;
}
}
}
if ( V_128 || F_110 ( V_4 ) )
F_66 ( V_115 -> V_2 ) ;
return V_132 ;
}
static bool F_111 ( struct V_18 * V_19 , T_5 V_133 , T_5 V_134 ,
struct V_135 * V_136 )
{
struct V_135 * V_137 [ 4 ] , V_30 , V_138 ;
unsigned V_139 = 0 , V_140 ;
F_25 ( ! F_112 ( V_19 -> V_20 , V_141 ) ) ;
V_19 -> V_142 = ~ 0 ;
V_19 -> V_143 . V_133 = V_133 ;
V_19 -> V_143 . V_134 = V_134 ;
F_64 ( & V_30 , & V_19 -> V_143 , sizeof( V_19 -> V_143 ) ) ;
V_137 [ V_139 ++ ] = & V_30 ;
if ( V_136 )
V_137 [ V_139 ++ ] = V_136 ;
F_64 ( & V_138 , & V_19 -> V_142 , sizeof( V_19 -> V_142 ) ) ;
V_137 [ V_139 ] = & V_138 ;
F_25 ( V_139 + 1 > F_113 ( V_137 ) ) ;
F_114 ( V_19 -> V_144 , V_137 , V_139 , 1 , V_19 , V_57 ) ;
if ( F_18 ( ! F_66 ( V_19 -> V_144 ) ) )
return V_19 -> V_142 == V_145 ;
while ( ! F_35 ( V_19 -> V_144 , & V_140 ) &&
! F_115 ( V_19 -> V_144 ) )
F_116 () ;
return V_19 -> V_142 == V_145 ;
}
static int F_117 ( struct V_43 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_146 * V_20 = V_19 -> V_20 ;
int V_147 ;
struct V_148 * V_149 ;
struct V_135 V_82 ;
V_149 = F_118 ( sizeof( * V_149 ) , V_100 ) ;
if ( ! V_149 )
return - V_81 ;
memcpy ( V_149 , V_17 , sizeof( * V_149 ) ) ;
V_147 = F_119 ( V_22 , V_149 ) ;
if ( V_147 )
goto V_136;
if ( F_112 ( V_20 , V_150 ) ) {
F_64 ( & V_82 , V_149 -> V_151 , V_22 -> V_152 ) ;
if ( ! F_111 ( V_19 , V_153 ,
V_154 , & V_82 ) ) {
F_104 ( & V_20 -> V_22 ,
L_10 ) ;
V_147 = - V_155 ;
goto V_136;
}
} else if ( F_112 ( V_20 , V_156 ) &&
! F_112 ( V_20 , V_157 ) ) {
unsigned int V_85 ;
for ( V_85 = 0 ; V_85 < V_22 -> V_152 ; V_85 ++ )
F_120 ( V_20 ,
F_121 ( struct V_158 , V_159 ) +
V_85 , V_149 -> V_151 [ V_85 ] ) ;
}
F_122 ( V_22 , V_17 ) ;
V_147 = 0 ;
V_136:
F_123 ( V_149 ) ;
return V_147 ;
}
static struct V_160 * V_62 ( struct V_43 * V_22 ,
struct V_160 * V_161 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_162 ;
unsigned int V_163 ;
F_124 (cpu) {
struct V_62 * V_45 = F_125 ( V_19 -> V_45 , V_162 ) ;
T_6 V_164 , V_165 , V_166 , V_167 ;
do {
V_163 = F_126 ( & V_45 -> V_116 ) ;
V_164 = V_45 -> V_118 ;
V_165 = V_45 -> V_117 ;
} while ( F_127 ( & V_45 -> V_116 , V_163 ) );
do {
V_163 = F_126 ( & V_45 -> V_66 ) ;
V_166 = V_45 -> V_68 ;
V_167 = V_45 -> V_67 ;
} while ( F_127 ( & V_45 -> V_66 , V_163 ) );
V_161 -> V_68 += V_166 ;
V_161 -> V_118 += V_164 ;
V_161 -> V_67 += V_167 ;
V_161 -> V_117 += V_165 ;
}
V_161 -> V_131 = V_22 -> V_45 . V_131 ;
V_161 -> V_130 = V_22 -> V_45 . V_130 ;
V_161 -> V_46 = V_22 -> V_45 . V_46 ;
V_161 -> V_54 = V_22 -> V_45 . V_54 ;
V_161 -> V_78 = V_22 -> V_45 . V_78 ;
return V_161 ;
}
static void F_128 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_99 ; V_85 ++ )
F_129 ( & V_19 -> V_11 [ V_85 ] . V_34 ) ;
}
static void F_130 ( struct V_18 * V_19 )
{
F_131 () ;
if ( ! F_111 ( V_19 , V_168 ,
V_169 , NULL ) )
F_104 ( & V_19 -> V_22 -> V_22 , L_11 ) ;
F_132 () ;
}
static int F_133 ( struct V_18 * V_19 , T_2 V_170 )
{
struct V_135 V_82 ;
struct V_43 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_171 || ! F_112 ( V_19 -> V_20 , V_172 ) )
return 0 ;
V_19 -> V_173 . V_174 = F_134 ( V_19 -> V_20 , V_170 ) ;
F_64 ( & V_82 , & V_19 -> V_173 , sizeof( V_19 -> V_173 ) ) ;
if ( ! F_111 ( V_19 , V_175 ,
V_176 , & V_82 ) ) {
F_104 ( & V_22 -> V_22 , L_12 ,
V_170 ) ;
return - V_155 ;
} else {
V_19 -> V_99 = V_170 ;
if ( V_22 -> V_69 & V_177 )
F_77 ( & V_19 -> V_97 , 0 ) ;
}
return 0 ;
}
static int F_135 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_85 ;
F_136 ( & V_19 -> V_97 ) ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ )
F_76 ( & V_19 -> V_11 [ V_85 ] . V_34 ) ;
return 0 ;
}
static void F_137 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_135 V_82 [ 2 ] ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
int V_182 ;
int V_183 ;
void * V_26 ;
int V_85 ;
if ( ! F_112 ( V_19 -> V_20 , V_184 ) )
return;
V_19 -> V_185 = ( ( V_22 -> V_69 & V_186 ) != 0 ) ;
V_19 -> V_187 = ( ( V_22 -> V_69 & V_188 ) != 0 ) ;
F_64 ( V_82 , & V_19 -> V_185 , sizeof( V_19 -> V_185 ) ) ;
if ( ! F_111 ( V_19 , V_189 ,
V_190 , V_82 ) )
F_104 ( & V_22 -> V_22 , L_13 ,
V_19 -> V_185 ? L_14 : L_15 ) ;
F_64 ( V_82 , & V_19 -> V_187 , sizeof( V_19 -> V_187 ) ) ;
if ( ! F_111 ( V_19 , V_189 ,
V_191 , V_82 ) )
F_104 ( & V_22 -> V_22 , L_16 ,
V_19 -> V_187 ? L_14 : L_15 ) ;
V_182 = F_138 ( V_22 ) ;
V_183 = F_139 ( V_22 ) ;
V_26 = F_140 ( ( ( V_182 + V_183 ) * V_192 ) +
( 2 * sizeof( V_179 -> V_193 ) ) , V_57 ) ;
V_179 = V_26 ;
if ( ! V_26 )
return;
F_53 ( V_82 , 2 ) ;
V_179 -> V_193 = F_141 ( V_19 -> V_20 , V_182 ) ;
V_85 = 0 ;
F_142 (ha, dev)
memcpy ( & V_179 -> V_194 [ V_85 ++ ] [ 0 ] , V_181 -> V_149 , V_192 ) ;
F_54 ( & V_82 [ 0 ] , V_179 ,
sizeof( V_179 -> V_193 ) + ( V_182 * V_192 ) ) ;
V_179 = ( void * ) & V_179 -> V_194 [ V_182 ] [ 0 ] ;
V_179 -> V_193 = F_141 ( V_19 -> V_20 , V_183 ) ;
V_85 = 0 ;
F_143 (ha, dev)
memcpy ( & V_179 -> V_194 [ V_85 ++ ] [ 0 ] , V_181 -> V_149 , V_192 ) ;
F_54 ( & V_82 [ 1 ] , V_179 ,
sizeof( V_179 -> V_193 ) + ( V_183 * V_192 ) ) ;
if ( ! F_111 ( V_19 , V_153 ,
V_195 , V_82 ) )
F_104 ( & V_22 -> V_22 , L_17 ) ;
F_123 ( V_26 ) ;
}
static int F_144 ( struct V_43 * V_22 ,
T_7 V_196 , T_2 V_197 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_135 V_82 ;
V_19 -> V_198 = V_197 ;
F_64 ( & V_82 , & V_19 -> V_198 , sizeof( V_19 -> V_198 ) ) ;
if ( ! F_111 ( V_19 , V_199 ,
V_200 , & V_82 ) )
F_104 ( & V_22 -> V_22 , L_18 , V_197 ) ;
return 0 ;
}
static int F_145 ( struct V_43 * V_22 ,
T_7 V_196 , T_2 V_197 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_135 V_82 ;
V_19 -> V_198 = V_197 ;
F_64 ( & V_82 , & V_19 -> V_198 , sizeof( V_19 -> V_198 ) ) ;
if ( ! F_111 ( V_19 , V_199 ,
V_201 , & V_82 ) )
F_104 ( & V_22 -> V_22 , L_19 , V_197 ) ;
return 0 ;
}
static void F_146 ( struct V_18 * V_19 , long V_202 )
{
int V_85 ;
if ( V_19 -> V_203 ) {
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
F_147 ( V_19 -> V_11 [ V_85 ] . V_2 , - 1 ) ;
F_147 ( V_19 -> V_115 [ V_85 ] . V_2 , - 1 ) ;
}
V_19 -> V_203 = false ;
}
}
static void F_148 ( struct V_18 * V_19 )
{
int V_85 ;
int V_162 ;
if ( V_19 -> V_99 == 1 ||
V_19 -> V_113 != F_149 () ) {
F_146 ( V_19 , - 1 ) ;
return;
}
V_85 = 0 ;
F_150 (cpu) {
F_147 ( V_19 -> V_11 [ V_85 ] . V_2 , V_162 ) ;
F_147 ( V_19 -> V_115 [ V_85 ] . V_2 , V_162 ) ;
F_151 ( V_19 -> V_22 , F_152 ( V_162 ) , V_85 ) ;
V_85 ++ ;
}
V_19 -> V_203 = true ;
}
static int F_153 ( unsigned int V_162 , struct V_204 * V_205 )
{
struct V_18 * V_19 = F_154 ( V_205 , struct V_18 ,
V_205 ) ;
F_148 ( V_19 ) ;
return 0 ;
}
static int F_155 ( unsigned int V_162 , struct V_204 * V_205 )
{
struct V_18 * V_19 = F_154 ( V_205 , struct V_18 ,
V_206 ) ;
F_148 ( V_19 ) ;
return 0 ;
}
static int F_156 ( unsigned int V_162 , struct V_204 * V_205 )
{
struct V_18 * V_19 = F_154 ( V_205 , struct V_18 ,
V_205 ) ;
F_146 ( V_19 , V_162 ) ;
return 0 ;
}
static int F_157 ( struct V_18 * V_19 )
{
int V_147 ;
V_147 = F_158 ( V_207 , & V_19 -> V_205 ) ;
if ( V_147 )
return V_147 ;
V_147 = F_158 ( V_208 ,
& V_19 -> V_206 ) ;
if ( ! V_147 )
return V_147 ;
F_159 ( V_207 , & V_19 -> V_205 ) ;
return V_147 ;
}
static void F_160 ( struct V_18 * V_19 )
{
F_159 ( V_207 , & V_19 -> V_205 ) ;
F_159 ( V_208 ,
& V_19 -> V_206 ) ;
}
static void F_161 ( struct V_43 * V_22 ,
struct V_209 * V_210 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
V_210 -> V_211 = F_79 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_210 -> V_212 = F_79 ( V_19 -> V_115 [ 0 ] . V_2 ) ;
V_210 -> V_213 = V_210 -> V_211 ;
V_210 -> V_214 = V_210 -> V_212 ;
}
static void F_162 ( struct V_43 * V_22 ,
struct V_215 * V_216 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_146 * V_20 = V_19 -> V_20 ;
F_163 ( V_216 -> V_217 , V_218 , sizeof( V_216 -> V_217 ) ) ;
F_163 ( V_216 -> V_219 , V_220 , sizeof( V_216 -> V_219 ) ) ;
F_163 ( V_216 -> V_221 , F_164 ( V_20 ) , sizeof( V_216 -> V_221 ) ) ;
}
static int F_165 ( struct V_43 * V_22 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
T_2 V_170 = V_223 -> V_224 ;
int V_44 ;
if ( V_223 -> V_225 || V_223 -> V_226 || V_223 -> V_227 )
return - V_155 ;
if ( V_170 > V_19 -> V_113 || V_170 == 0 )
return - V_155 ;
F_166 () ;
V_44 = F_133 ( V_19 , V_170 ) ;
if ( ! V_44 ) {
F_167 ( V_22 , V_170 ) ;
F_168 ( V_22 , V_170 ) ;
F_148 ( V_19 ) ;
}
F_169 () ;
return V_44 ;
}
static void F_170 ( struct V_43 * V_22 ,
struct V_222 * V_223 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
V_223 -> V_224 = V_19 -> V_99 ;
V_223 -> V_228 = V_19 -> V_113 ;
V_223 -> V_229 = 0 ;
V_223 -> V_225 = 0 ;
V_223 -> V_226 = 0 ;
V_223 -> V_227 = 0 ;
}
static bool F_171 ( const struct V_230 * V_134 )
{
struct V_230 V_231 = * V_134 ;
struct V_230 V_232 = {} ;
F_172 ( & V_231 , 0 ) ;
V_232 . V_233 = V_234 ;
V_231 . V_235 = 0 ;
V_231 . V_236 = 0 ;
V_231 . V_134 = 0 ;
return ! memcmp ( & V_231 , & V_232 , sizeof( V_231 ) ) ;
}
static int F_173 ( struct V_43 * V_22 , struct V_230 * V_134 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
T_8 V_237 ;
V_237 = F_174 ( V_134 ) ;
if ( ! F_175 ( V_237 ) ||
! F_176 ( V_134 -> V_236 ) ||
! F_171 ( V_134 ) )
return - V_155 ;
V_19 -> V_237 = V_237 ;
V_19 -> V_236 = V_134 -> V_236 ;
return 0 ;
}
static int F_177 ( struct V_43 * V_22 , struct V_230 * V_134 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
F_172 ( V_134 , V_19 -> V_237 ) ;
V_134 -> V_236 = V_19 -> V_236 ;
V_134 -> V_233 = V_234 ;
return 0 ;
}
static void F_178 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
V_19 -> V_237 = V_238 ;
V_19 -> V_236 = V_239 ;
}
static int F_179 ( struct V_43 * V_22 , int V_240 )
{
if ( V_240 < V_241 || V_240 > V_242 )
return - V_155 ;
V_22 -> V_243 = V_240 ;
return 0 ;
}
static void F_180 ( struct V_95 * V_96 )
{
struct V_18 * V_19 =
F_75 ( V_96 , struct V_18 , V_244 ) ;
T_2 V_245 ;
if ( F_181 ( V_19 -> V_20 , V_246 ,
struct V_158 , V_106 , & V_245 ) < 0 )
return;
if ( V_245 & V_247 ) {
F_182 ( V_19 -> V_22 ) ;
F_130 ( V_19 ) ;
}
V_245 &= V_107 ;
if ( V_19 -> V_106 == V_245 )
return;
V_19 -> V_106 = V_245 ;
if ( V_19 -> V_106 & V_107 ) {
F_183 ( V_19 -> V_22 ) ;
F_184 ( V_19 -> V_22 ) ;
} else {
F_185 ( V_19 -> V_22 ) ;
F_186 ( V_19 -> V_22 ) ;
}
}
static void F_187 ( struct V_146 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_188 ( & V_19 -> V_244 ) ;
}
static void F_189 ( struct V_18 * V_19 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
F_190 ( & V_19 -> V_11 [ V_85 ] . V_34 ) ;
F_191 ( & V_19 -> V_11 [ V_85 ] . V_34 ) ;
}
F_192 () ;
F_123 ( V_19 -> V_11 ) ;
F_123 ( V_19 -> V_115 ) ;
}
static void F_193 ( struct V_18 * V_19 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
while ( V_19 -> V_11 [ V_85 ] . V_15 )
F_194 ( F_7 ( & V_19 -> V_11 [ V_85 ] , V_100 ) , 0 ) ;
}
}
static void F_195 ( struct V_18 * V_19 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ )
if ( V_19 -> V_11 [ V_85 ] . V_89 . V_12 )
F_22 ( V_19 -> V_11 [ V_85 ] . V_89 . V_12 ) ;
}
static void F_196 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
struct V_1 * V_2 = V_19 -> V_115 [ V_85 ] . V_2 ;
while ( ( V_26 = F_197 ( V_2 ) ) != NULL )
F_24 ( V_26 ) ;
}
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_85 ] . V_2 ;
while ( ( V_26 = F_197 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_36 ) {
unsigned long V_47 = ( unsigned long ) V_26 ;
void * V_64 = F_13 ( V_47 ) ;
F_22 ( F_33 ( V_64 ) ) ;
} else if ( V_19 -> V_65 ) {
F_6 ( & V_19 -> V_11 [ V_85 ] , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
}
}
}
static void F_198 ( struct V_18 * V_19 )
{
struct V_146 * V_20 = V_19 -> V_20 ;
F_146 ( V_19 , - 1 ) ;
V_20 -> V_248 -> V_249 ( V_20 ) ;
F_189 ( V_19 ) ;
}
static int F_199 ( struct V_18 * V_19 )
{
T_9 * * V_250 ;
struct V_1 * * V_251 ;
int V_147 = - V_81 ;
int V_85 , V_252 ;
const char * * V_253 ;
V_252 = V_19 -> V_113 * 2 +
F_112 ( V_19 -> V_20 , V_141 ) ;
V_251 = F_140 ( V_252 * sizeof( * V_251 ) , V_100 ) ;
if ( ! V_251 )
goto V_254;
V_250 = F_118 ( V_252 * sizeof( * V_250 ) , V_100 ) ;
if ( ! V_250 )
goto V_255;
V_253 = F_118 ( V_252 * sizeof( * V_253 ) , V_100 ) ;
if ( ! V_253 )
goto V_256;
if ( V_19 -> V_171 ) {
V_250 [ V_252 - 1 ] = NULL ;
V_253 [ V_252 - 1 ] = L_20 ;
}
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
V_250 [ F_4 ( V_85 ) ] = F_67 ;
V_250 [ F_2 ( V_85 ) ] = F_9 ;
sprintf ( V_19 -> V_11 [ V_85 ] . V_40 , L_21 , V_85 ) ;
sprintf ( V_19 -> V_115 [ V_85 ] . V_40 , L_22 , V_85 ) ;
V_253 [ F_4 ( V_85 ) ] = V_19 -> V_11 [ V_85 ] . V_40 ;
V_253 [ F_2 ( V_85 ) ] = V_19 -> V_115 [ V_85 ] . V_40 ;
}
V_147 = V_19 -> V_20 -> V_248 -> V_257 ( V_19 -> V_20 , V_252 , V_251 , V_250 ,
V_253 ) ;
if ( V_147 )
goto V_258;
if ( V_19 -> V_171 ) {
V_19 -> V_144 = V_251 [ V_252 - 1 ] ;
if ( F_112 ( V_19 -> V_20 , V_259 ) )
V_19 -> V_22 -> V_260 |= V_261 ;
}
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
V_19 -> V_11 [ V_85 ] . V_2 = V_251 [ F_4 ( V_85 ) ] ;
V_19 -> V_115 [ V_85 ] . V_2 = V_251 [ F_2 ( V_85 ) ] ;
}
F_123 ( V_253 ) ;
F_123 ( V_250 ) ;
F_123 ( V_251 ) ;
return 0 ;
V_258:
F_123 ( V_253 ) ;
V_256:
F_123 ( V_250 ) ;
V_255:
F_123 ( V_251 ) ;
V_254:
return V_147 ;
}
static int F_200 ( struct V_18 * V_19 )
{
int V_85 ;
V_19 -> V_115 = F_140 ( sizeof( * V_19 -> V_115 ) * V_19 -> V_113 , V_100 ) ;
if ( ! V_19 -> V_115 )
goto V_262;
V_19 -> V_11 = F_140 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_113 , V_100 ) ;
if ( ! V_19 -> V_11 )
goto V_263;
F_201 ( & V_19 -> V_97 , F_74 ) ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ ) {
V_19 -> V_11 [ V_85 ] . V_15 = NULL ;
F_202 ( V_19 -> V_22 , & V_19 -> V_11 [ V_85 ] . V_34 , F_80 ,
V_264 ) ;
F_53 ( V_19 -> V_11 [ V_85 ] . V_82 , F_113 ( V_19 -> V_11 [ V_85 ] . V_82 ) ) ;
F_203 ( & V_19 -> V_11 [ V_85 ] . V_61 ) ;
F_53 ( V_19 -> V_115 [ V_85 ] . V_82 , F_113 ( V_19 -> V_115 [ V_85 ] . V_82 ) ) ;
}
return 0 ;
V_263:
F_123 ( V_19 -> V_115 ) ;
V_262:
return - V_81 ;
}
static int F_204 ( struct V_18 * V_19 )
{
int V_147 ;
V_147 = F_200 ( V_19 ) ;
if ( V_147 )
goto V_44;
V_147 = F_199 ( V_19 ) ;
if ( V_147 )
goto V_265;
F_166 () ;
F_148 ( V_19 ) ;
F_169 () ;
return 0 ;
V_265:
F_189 ( V_19 ) ;
V_44:
return V_147 ;
}
static T_10 F_205 ( struct V_266 * V_267 ,
struct V_268 * V_269 , char * V_26 )
{
struct V_18 * V_19 = F_87 ( V_267 -> V_22 ) ;
unsigned int V_270 = F_206 ( V_267 ) ;
struct V_86 * V_271 ;
F_25 ( V_270 >= V_19 -> V_113 ) ;
V_271 = & V_19 -> V_11 [ V_270 ] . V_61 ;
return sprintf ( V_26 , L_23 , F_58 ( V_271 ) ) ;
}
static bool F_207 ( struct V_146 * V_20 ,
unsigned int V_272 ,
const char * V_273 , const char * V_274 )
{
if ( ! F_112 ( V_20 , V_272 ) )
return false ;
F_208 ( & V_20 -> V_22 , L_24 ,
V_273 , V_274 ) ;
return true ;
}
static bool F_209 ( struct V_146 * V_20 )
{
if ( ! F_112 ( V_20 , V_141 ) &&
( F_210 ( V_20 , V_184 ,
L_25 ) ||
F_210 ( V_20 , V_259 ,
L_25 ) ||
F_210 ( V_20 , V_275 ,
L_25 ) ||
F_210 ( V_20 , V_172 , L_25 ) ||
F_210 ( V_20 , V_150 ,
L_25 ) ) ) {
return false ;
}
return true ;
}
static int F_211 ( struct V_146 * V_20 )
{
int V_85 , V_44 ;
struct V_43 * V_22 ;
struct V_18 * V_19 ;
T_2 V_113 ;
int V_243 ;
if ( ! V_20 -> V_248 -> V_276 ) {
F_208 ( & V_20 -> V_22 , L_26 ,
V_277 ) ;
return - V_155 ;
}
if ( ! F_209 ( V_20 ) )
return - V_155 ;
V_44 = F_181 ( V_20 , V_172 ,
struct V_158 ,
V_278 , & V_113 ) ;
if ( V_44 || V_113 < V_279 ||
V_113 > V_280 ||
! F_112 ( V_20 , V_141 ) )
V_113 = 1 ;
V_22 = F_212 ( sizeof( struct V_18 ) , V_113 ) ;
if ( ! V_22 )
return - V_81 ;
V_22 -> V_281 |= V_282 | V_283 ;
V_22 -> V_284 = & V_285 ;
V_22 -> V_260 = V_286 ;
V_22 -> V_287 = & V_288 ;
F_213 ( V_22 , & V_20 -> V_22 ) ;
if ( F_112 ( V_20 , V_289 ) ) {
V_22 -> V_290 |= V_291 | V_292 ;
if ( V_293 )
V_22 -> V_260 |= V_291 | V_292 ;
if ( F_112 ( V_20 , V_294 ) ) {
V_22 -> V_290 |= V_295 | V_296
| V_297 | V_298 ;
}
if ( F_112 ( V_20 , V_299 ) )
V_22 -> V_290 |= V_295 ;
if ( F_112 ( V_20 , V_300 ) )
V_22 -> V_290 |= V_298 ;
if ( F_112 ( V_20 , V_301 ) )
V_22 -> V_290 |= V_297 ;
if ( F_112 ( V_20 , V_302 ) )
V_22 -> V_290 |= V_296 ;
V_22 -> V_260 |= V_303 ;
if ( V_304 )
V_22 -> V_260 |= V_22 -> V_290 & ( V_305 | V_296 ) ;
}
if ( F_112 ( V_20 , V_306 ) )
V_22 -> V_260 |= V_307 ;
V_22 -> V_308 = V_22 -> V_260 ;
if ( F_112 ( V_20 , V_156 ) )
F_214 ( V_20 ,
F_121 ( struct V_158 , V_159 ) ,
V_22 -> V_309 , V_22 -> V_152 ) ;
else
F_215 ( V_22 ) ;
V_19 = F_87 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_45 = F_216 ( struct V_62 ) ;
V_44 = - V_81 ;
if ( V_19 -> V_45 == NULL )
goto free;
F_124 (i) {
struct V_62 * V_62 ;
V_62 = F_125 ( V_19 -> V_45 , V_85 ) ;
F_217 ( & V_62 -> V_116 ) ;
F_217 ( & V_62 -> V_66 ) ;
}
F_218 ( & V_19 -> V_244 , F_180 ) ;
if ( F_112 ( V_20 , V_310 ) ||
F_112 ( V_20 , V_311 ) ||
F_112 ( V_20 , V_312 ) ||
F_112 ( V_20 , V_313 ) )
V_19 -> V_65 = true ;
if ( F_112 ( V_20 , V_314 ) )
V_19 -> V_36 = true ;
if ( F_112 ( V_20 , V_314 ) ||
F_112 ( V_20 , V_157 ) )
V_19 -> V_32 = sizeof( struct V_6 ) ;
else
V_19 -> V_32 = sizeof( struct V_315 ) ;
if ( F_112 ( V_20 , V_316 ) ||
F_112 ( V_20 , V_157 ) )
V_19 -> V_125 = true ;
if ( F_112 ( V_20 , V_141 ) )
V_19 -> V_171 = true ;
if ( F_112 ( V_20 , V_317 ) ) {
V_243 = F_219 ( V_20 ,
F_121 ( struct V_158 ,
V_243 ) ) ;
if ( F_179 ( V_22 , V_243 ) )
F_220 ( V_20 , V_317 ) ;
}
if ( V_19 -> V_125 )
V_22 -> V_318 = V_19 -> V_32 ;
V_19 -> V_99 = 1 ;
V_19 -> V_113 = V_113 ;
V_44 = F_204 ( V_19 ) ;
if ( V_44 )
goto V_319;
#ifdef F_221
if ( V_19 -> V_36 )
V_22 -> V_320 = & V_321 ;
#endif
F_167 ( V_22 , V_19 -> V_99 ) ;
F_168 ( V_22 , V_19 -> V_99 ) ;
F_178 ( V_22 ) ;
V_44 = F_222 ( V_22 ) ;
if ( V_44 ) {
F_36 ( L_27 ) ;
goto V_322;
}
F_223 ( V_20 ) ;
V_44 = F_157 ( V_19 ) ;
if ( V_44 ) {
F_36 ( L_28 ) ;
goto V_323;
}
if ( F_112 ( V_19 -> V_20 , V_246 ) ) {
F_185 ( V_22 ) ;
F_188 ( & V_19 -> V_244 ) ;
} else {
V_19 -> V_106 = V_107 ;
F_183 ( V_22 ) ;
}
F_36 ( L_29 ,
V_22 -> V_40 , V_113 ) ;
return 0 ;
V_323:
V_19 -> V_20 -> V_248 -> V_324 ( V_20 ) ;
F_224 ( V_22 ) ;
V_322:
F_136 ( & V_19 -> V_97 ) ;
F_195 ( V_19 ) ;
F_198 ( V_19 ) ;
V_319:
F_225 ( V_19 -> V_45 ) ;
free:
F_226 ( V_22 ) ;
return V_44 ;
}
static void F_227 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_248 -> V_324 ( V_19 -> V_20 ) ;
F_196 ( V_19 ) ;
F_193 ( V_19 ) ;
F_195 ( V_19 ) ;
F_198 ( V_19 ) ;
}
static void F_228 ( struct V_146 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_160 ( V_19 ) ;
F_229 ( & V_19 -> V_244 ) ;
F_224 ( V_19 -> V_22 ) ;
F_227 ( V_19 ) ;
F_225 ( V_19 -> V_45 ) ;
F_226 ( V_19 -> V_22 ) ;
}
static int F_230 ( struct V_146 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_85 ;
F_160 ( V_19 ) ;
F_229 ( & V_19 -> V_244 ) ;
F_231 ( V_19 -> V_22 ) ;
F_136 ( & V_19 -> V_97 ) ;
if ( F_232 ( V_19 -> V_22 ) ) {
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ )
F_76 ( & V_19 -> V_11 [ V_85 ] . V_34 ) ;
}
F_227 ( V_19 ) ;
return 0 ;
}
static int F_233 ( struct V_146 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_44 , V_85 ;
V_44 = F_204 ( V_19 ) ;
if ( V_44 )
return V_44 ;
F_223 ( V_20 ) ;
if ( F_232 ( V_19 -> V_22 ) ) {
for ( V_85 = 0 ; V_85 < V_19 -> V_99 ; V_85 ++ )
if ( ! F_65 ( V_19 , & V_19 -> V_11 [ V_85 ] , V_100 ) )
F_77 ( & V_19 -> V_97 , 0 ) ;
for ( V_85 = 0 ; V_85 < V_19 -> V_113 ; V_85 ++ )
F_70 ( & V_19 -> V_11 [ V_85 ] ) ;
}
F_234 ( V_19 -> V_22 ) ;
F_131 () ;
F_133 ( V_19 , V_19 -> V_99 ) ;
F_132 () ;
V_44 = F_157 ( V_19 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
}
static T_11 int F_235 ( void )
{
int V_147 ;
V_147 = F_236 ( V_325 , L_30 ,
F_153 ,
F_156 ) ;
if ( V_147 < 0 )
goto V_136;
V_207 = V_147 ;
V_147 = F_236 ( V_208 , L_31 ,
NULL , F_155 ) ;
if ( V_147 )
goto V_326;
V_147 = F_237 ( & V_327 ) ;
if ( V_147 )
goto V_328;
return 0 ;
V_328:
F_238 ( V_208 ) ;
V_326:
F_238 ( V_207 ) ;
V_136:
return V_147 ;
}
static T_12 void F_239 ( void )
{
F_238 ( V_208 ) ;
F_238 ( V_207 ) ;
F_240 ( & V_327 ) ;
}
