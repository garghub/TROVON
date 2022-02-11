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
if ( V_30 -> V_30 . V_69 & V_70 ) {
F_36 ( L_5 ) ;
if ( ! F_45 ( V_8 ,
F_32 ( V_19 -> V_20 , V_30 -> V_30 . V_71 ) ,
F_32 ( V_19 -> V_20 , V_30 -> V_30 . V_72 ) ) )
goto V_73;
} else if ( V_30 -> V_30 . V_69 & V_74 ) {
V_8 -> V_75 = V_76 ;
}
V_8 -> V_77 = F_46 ( V_8 , V_22 ) ;
F_36 ( L_6 ,
F_47 ( V_8 -> V_77 ) , V_8 -> V_29 , V_8 -> V_78 ) ;
if ( V_30 -> V_30 . V_79 != V_80 ) {
F_36 ( L_7 ) ;
switch ( V_30 -> V_30 . V_79 & ~ V_81 ) {
case V_82 :
F_27 ( V_8 ) -> V_79 = V_83 ;
break;
case V_84 :
F_27 ( V_8 ) -> V_79 = V_85 ;
break;
case V_86 :
F_27 ( V_8 ) -> V_79 = V_87 ;
break;
default:
F_48 ( L_8 ,
V_22 -> V_40 , V_30 -> V_30 . V_79 ) ;
goto V_73;
}
if ( V_30 -> V_30 . V_79 & V_81 )
F_27 ( V_8 ) -> V_79 |= V_88 ;
F_27 ( V_8 ) -> V_89 = F_32 ( V_19 -> V_20 ,
V_30 -> V_30 . V_89 ) ;
if ( F_27 ( V_8 ) -> V_89 == 0 ) {
F_48 ( L_9 , V_22 -> V_40 ) ;
goto V_73;
}
F_27 ( V_8 ) -> V_79 |= V_90 ;
F_27 ( V_8 ) -> V_91 = 0 ;
}
F_49 ( & V_11 -> V_34 , V_8 ) ;
return;
V_73:
V_22 -> V_45 . V_92 ++ ;
F_24 ( V_8 ) ;
}
static int F_50 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_93 )
{
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_44 ;
V_8 = F_51 ( V_19 -> V_22 , V_94 , V_93 ) ;
if ( F_18 ( ! V_8 ) )
return - V_95 ;
F_20 ( V_8 , V_94 ) ;
V_30 = F_5 ( V_8 ) ;
F_52 ( V_11 -> V_96 , 2 ) ;
F_53 ( V_11 -> V_96 , V_30 , V_19 -> V_32 ) ;
F_54 ( V_8 , V_11 -> V_96 + 1 , 0 , V_8 -> V_29 ) ;
V_44 = F_55 ( V_11 -> V_2 , V_11 -> V_96 , 2 , V_8 , V_93 ) ;
if ( V_44 < 0 )
F_24 ( V_8 ) ;
return V_44 ;
}
static int F_56 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_93 )
{
struct V_12 * V_97 , * V_98 = NULL ;
char * V_17 ;
int V_99 , V_44 , V_28 ;
F_52 ( V_11 -> V_96 , V_38 + 2 ) ;
for ( V_99 = V_38 + 1 ; V_99 > 1 ; -- V_99 ) {
V_97 = F_7 ( V_11 , V_93 ) ;
if ( ! V_97 ) {
if ( V_98 )
F_6 ( V_11 , V_98 ) ;
return - V_95 ;
}
F_53 ( & V_11 -> V_96 [ V_99 ] , F_16 ( V_97 ) , V_39 ) ;
V_97 -> V_14 = ( unsigned long ) V_98 ;
V_98 = V_97 ;
}
V_97 = F_7 ( V_11 , V_93 ) ;
if ( ! V_97 ) {
F_6 ( V_11 , V_98 ) ;
return - V_95 ;
}
V_17 = F_16 ( V_97 ) ;
F_53 ( & V_11 -> V_96 [ 0 ] , V_17 , V_19 -> V_32 ) ;
V_28 = sizeof( struct V_37 ) ;
F_53 ( & V_11 -> V_96 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_97 -> V_14 = ( unsigned long ) V_98 ;
V_44 = F_55 ( V_11 -> V_2 , V_11 -> V_96 , V_38 + 2 ,
V_97 , V_93 ) ;
if ( V_44 < 0 )
F_6 ( V_11 , V_97 ) ;
return V_44 ;
}
static unsigned int F_57 ( struct V_100 * V_101 )
{
const T_3 V_32 = sizeof( struct V_6 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_58 (unsigned int, ewma_pkt_len_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_59 ( V_29 , V_25 ) ;
}
static int F_60 ( struct V_10 * V_11 , T_1 V_93 )
{
struct V_102 * V_103 = & V_11 -> V_103 ;
char * V_26 ;
unsigned long V_47 ;
int V_44 ;
unsigned int V_29 , V_104 ;
V_29 = F_57 ( & V_11 -> V_61 ) ;
if ( F_18 ( ! F_61 ( V_29 , V_103 , V_93 ) ) )
return - V_95 ;
V_26 = ( char * ) F_16 ( V_103 -> V_12 ) + V_103 -> V_28 ;
V_47 = F_14 ( V_26 , V_29 ) ;
F_62 ( V_103 -> V_12 ) ;
V_103 -> V_28 += V_29 ;
V_104 = V_103 -> V_27 - V_103 -> V_28 ;
if ( V_104 < V_29 ) {
V_29 += V_104 ;
V_103 -> V_28 += V_104 ;
}
F_63 ( V_11 -> V_96 , V_26 , V_29 ) ;
V_44 = F_55 ( V_11 -> V_2 , V_11 -> V_96 , 1 , ( void * ) V_47 , V_93 ) ;
if ( V_44 < 0 )
F_22 ( F_33 ( V_26 ) ) ;
return V_44 ;
}
static bool F_64 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_93 )
{
int V_44 ;
bool V_105 ;
V_93 |= V_106 ;
do {
if ( V_19 -> V_36 )
V_44 = F_60 ( V_11 , V_93 ) ;
else if ( V_19 -> V_65 )
V_44 = F_56 ( V_19 , V_11 , V_93 ) ;
else
V_44 = F_50 ( V_19 , V_11 , V_93 ) ;
V_105 = V_44 == - V_95 ;
if ( V_44 )
break;
} while ( V_11 -> V_2 -> V_107 );
F_65 ( V_11 -> V_2 ) ;
return ! V_105 ;
}
static void F_66 ( struct V_1 * V_108 )
{
struct V_18 * V_19 = V_108 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_108 ) ] ;
if ( F_67 ( & V_11 -> V_34 ) ) {
F_10 ( V_108 ) ;
F_68 ( & V_11 -> V_34 ) ;
}
}
static void F_69 ( struct V_10 * V_11 )
{
F_70 ( & V_11 -> V_34 ) ;
if ( F_67 ( & V_11 -> V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_71 () ;
F_68 ( & V_11 -> V_34 ) ;
F_72 () ;
}
}
static void F_73 ( struct V_109 * V_110 )
{
struct V_18 * V_19 =
F_74 ( V_110 , struct V_18 , V_111 . V_110 ) ;
bool V_112 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_99 ] ;
F_75 ( & V_11 -> V_34 ) ;
V_112 = ! F_64 ( V_19 , V_11 , V_114 ) ;
F_69 ( V_11 ) ;
if ( V_112 )
F_76 ( & V_19 -> V_111 , V_115 / 2 ) ;
}
}
static int F_77 ( struct V_10 * V_11 , int V_116 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_117 = 0 ;
void * V_26 ;
while ( V_117 < V_116 &&
( V_26 = F_35 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_41 ( V_19 , V_11 , V_26 , V_29 ) ;
V_117 ++ ;
}
if ( V_11 -> V_2 -> V_107 > F_78 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_64 ( V_19 , V_11 , V_57 ) )
F_76 ( & V_19 -> V_111 , 0 ) ;
}
return V_117 ;
}
static int F_79 ( struct V_118 * V_34 , int V_116 )
{
struct V_10 * V_11 =
F_74 ( V_34 , struct V_10 , V_34 ) ;
unsigned int V_119 , V_117 ;
V_117 = F_77 ( V_11 , V_116 ) ;
if ( V_117 < V_116 ) {
V_119 = F_80 ( V_11 -> V_2 ) ;
F_81 ( V_34 , V_117 ) ;
if ( F_18 ( F_82 ( V_11 -> V_2 , V_119 ) ) &&
F_67 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_68 ( V_34 ) ;
}
}
return V_117 ;
}
static int F_83 ( struct V_118 * V_34 )
{
struct V_10 * V_11 =
F_74 ( V_34 , struct V_10 , V_34 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_119 , V_117 = 0 , V_116 = 4 ;
if ( ! ( V_19 -> V_120 & V_121 ) )
return V_122 ;
if ( ! F_67 ( V_34 ) )
return V_123 ;
F_10 ( V_11 -> V_2 ) ;
V_124:
V_117 += F_77 ( V_11 , V_116 ) ;
V_119 = F_80 ( V_11 -> V_2 ) ;
F_84 ( V_125 , & V_34 -> V_126 ) ;
if ( F_18 ( F_82 ( V_11 -> V_2 , V_119 ) ) &&
F_67 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
if ( V_117 < V_116 ) {
V_116 -= V_117 ;
goto V_124;
} else {
F_68 ( V_34 ) ;
}
}
return V_117 ;
}
static int F_85 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
if ( V_99 < V_19 -> V_113 )
if ( ! F_64 ( V_19 , & V_19 -> V_11 [ V_99 ] , V_114 ) )
F_76 ( & V_19 -> V_111 , 0 ) ;
F_69 ( & V_19 -> V_11 [ V_99 ] ) ;
}
return 0 ;
}
static void F_87 ( struct V_128 * V_129 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_129 -> V_2 -> V_20 -> V_21 ;
struct V_62 * V_45 = F_42 ( V_19 -> V_45 ) ;
while ( ( V_8 = F_35 ( V_129 -> V_2 , & V_29 ) ) != NULL ) {
F_36 ( L_10 , V_8 ) ;
F_43 ( & V_45 -> V_130 ) ;
V_45 -> V_131 += V_8 -> V_29 ;
V_45 -> V_132 ++ ;
F_44 ( & V_45 -> V_130 ) ;
F_88 ( V_8 ) ;
}
}
static int F_89 ( struct V_128 * V_129 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_133 = ( (struct V_134 * ) V_8 -> V_135 ) -> V_136 ;
struct V_18 * V_19 = V_129 -> V_2 -> V_20 -> V_21 ;
unsigned V_137 ;
unsigned V_32 = V_19 -> V_32 ;
bool V_138 ;
F_36 ( L_11 , V_19 -> V_22 -> V_40 , V_8 , V_133 ) ;
V_138 = V_19 -> V_139 &&
! ( ( unsigned long ) V_8 -> V_135 & ( F_90 ( * V_30 ) - 1 ) ) &&
! F_91 ( V_8 ) && F_92 ( V_8 ) >= V_32 ;
if ( V_138 )
V_30 = (struct V_6 * ) ( V_8 -> V_135 - V_32 ) ;
else
V_30 = F_5 ( V_8 ) ;
if ( V_8 -> V_75 == V_140 ) {
V_30 -> V_30 . V_69 = V_70 ;
V_30 -> V_30 . V_71 = F_93 ( V_19 -> V_20 ,
F_94 ( V_8 ) ) ;
V_30 -> V_30 . V_72 = F_93 ( V_19 -> V_20 ,
V_8 -> V_72 ) ;
} else {
V_30 -> V_30 . V_69 = 0 ;
V_30 -> V_30 . V_72 = V_30 -> V_30 . V_71 = 0 ;
}
if ( F_95 ( V_8 ) ) {
V_30 -> V_30 . V_32 = F_93 ( V_19 -> V_20 , F_96 ( V_8 ) ) ;
V_30 -> V_30 . V_89 = F_93 ( V_19 -> V_20 ,
F_27 ( V_8 ) -> V_89 ) ;
if ( F_27 ( V_8 ) -> V_79 & V_83 )
V_30 -> V_30 . V_79 = V_82 ;
else if ( F_27 ( V_8 ) -> V_79 & V_87 )
V_30 -> V_30 . V_79 = V_86 ;
else if ( F_27 ( V_8 ) -> V_79 & V_85 )
V_30 -> V_30 . V_79 = V_84 ;
else
F_97 () ;
if ( F_27 ( V_8 ) -> V_79 & V_88 )
V_30 -> V_30 . V_79 |= V_81 ;
} else {
V_30 -> V_30 . V_79 = V_80 ;
V_30 -> V_30 . V_89 = V_30 -> V_30 . V_32 = 0 ;
}
if ( V_19 -> V_36 )
V_30 -> V_49 = 0 ;
F_52 ( V_129 -> V_96 , F_27 ( V_8 ) -> V_42 + ( V_138 ? 1 : 2 ) ) ;
if ( V_138 ) {
F_98 ( V_8 , V_32 ) ;
V_137 = F_54 ( V_8 , V_129 -> V_96 , 0 , V_8 -> V_29 ) ;
F_99 ( V_8 , V_32 ) ;
} else {
F_53 ( V_129 -> V_96 , V_30 , V_32 ) ;
V_137 = F_54 ( V_8 , V_129 -> V_96 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_100 ( V_129 -> V_2 , V_129 -> V_96 , V_137 , V_8 , V_57 ) ;
}
static T_4 F_101 ( struct V_7 * V_8 , struct V_43 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_141 = F_102 ( V_8 ) ;
struct V_128 * V_129 = & V_19 -> V_129 [ V_141 ] ;
int V_44 ;
struct V_142 * V_4 = F_103 ( V_22 , V_141 ) ;
bool V_143 = ! V_8 -> V_144 ;
F_87 ( V_129 ) ;
F_104 ( V_8 ) ;
V_44 = F_89 ( V_129 , V_8 ) ;
if ( F_18 ( V_44 ) ) {
V_22 -> V_45 . V_145 ++ ;
if ( F_105 () )
F_106 ( & V_22 -> V_22 ,
L_12 , V_141 , V_44 ) ;
V_22 -> V_45 . V_146 ++ ;
F_88 ( V_8 ) ;
return V_147 ;
}
F_107 ( V_8 ) ;
F_108 ( V_8 ) ;
if ( V_129 -> V_2 -> V_107 < 2 + V_38 ) {
F_109 ( V_22 , V_141 ) ;
if ( F_18 ( ! F_110 ( V_129 -> V_2 ) ) ) {
F_87 ( V_129 ) ;
if ( V_129 -> V_2 -> V_107 >= 2 + V_38 ) {
F_111 ( V_22 , V_141 ) ;
F_10 ( V_129 -> V_2 ) ;
}
}
}
if ( V_143 || F_112 ( V_4 ) )
F_65 ( V_129 -> V_2 ) ;
return V_147 ;
}
static bool F_113 ( struct V_18 * V_19 , T_5 V_148 , T_5 V_149 ,
struct V_150 * V_151 )
{
struct V_150 * V_152 [ 4 ] , V_30 , V_153 ;
unsigned V_154 = 0 , V_155 ;
F_25 ( ! F_114 ( V_19 -> V_20 , V_156 ) ) ;
V_19 -> V_157 = ~ 0 ;
V_19 -> V_158 . V_148 = V_148 ;
V_19 -> V_158 . V_149 = V_149 ;
F_63 ( & V_30 , & V_19 -> V_158 , sizeof( V_19 -> V_158 ) ) ;
V_152 [ V_154 ++ ] = & V_30 ;
if ( V_151 )
V_152 [ V_154 ++ ] = V_151 ;
F_63 ( & V_153 , & V_19 -> V_157 , sizeof( V_19 -> V_157 ) ) ;
V_152 [ V_154 ] = & V_153 ;
F_25 ( V_154 + 1 > F_115 ( V_152 ) ) ;
F_116 ( V_19 -> V_159 , V_152 , V_154 , 1 , V_19 , V_57 ) ;
if ( F_18 ( ! F_65 ( V_19 -> V_159 ) ) )
return V_19 -> V_157 == V_160 ;
while ( ! F_35 ( V_19 -> V_159 , & V_155 ) &&
! F_117 ( V_19 -> V_159 ) )
F_118 () ;
return V_19 -> V_157 == V_160 ;
}
static int F_119 ( struct V_43 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_161 * V_20 = V_19 -> V_20 ;
int V_162 ;
struct V_163 * V_164 = V_17 ;
struct V_150 V_96 ;
V_162 = F_120 ( V_22 , V_17 ) ;
if ( V_162 )
return V_162 ;
if ( F_114 ( V_20 , V_165 ) ) {
F_63 ( & V_96 , V_164 -> V_166 , V_22 -> V_167 ) ;
if ( ! F_113 ( V_19 , V_168 ,
V_169 , & V_96 ) ) {
F_106 ( & V_20 -> V_22 ,
L_13 ) ;
return - V_170 ;
}
} else if ( F_114 ( V_20 , V_171 ) &&
! F_114 ( V_20 , V_172 ) ) {
unsigned int V_99 ;
for ( V_99 = 0 ; V_99 < V_22 -> V_167 ; V_99 ++ )
F_121 ( V_20 ,
F_122 ( struct V_173 , V_174 ) +
V_99 , V_164 -> V_166 [ V_99 ] ) ;
}
F_123 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_175 * V_62 ( struct V_43 * V_22 ,
struct V_175 * V_176 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_177 ;
unsigned int V_178 ;
F_124 (cpu) {
struct V_62 * V_45 = F_125 ( V_19 -> V_45 , V_177 ) ;
T_6 V_179 , V_180 , V_181 , V_182 ;
do {
V_178 = F_126 ( & V_45 -> V_130 ) ;
V_179 = V_45 -> V_132 ;
V_180 = V_45 -> V_131 ;
} while ( F_127 ( & V_45 -> V_130 , V_178 ) );
do {
V_178 = F_126 ( & V_45 -> V_66 ) ;
V_181 = V_45 -> V_68 ;
V_182 = V_45 -> V_67 ;
} while ( F_127 ( & V_45 -> V_66 , V_178 ) );
V_176 -> V_68 += V_181 ;
V_176 -> V_132 += V_179 ;
V_176 -> V_67 += V_182 ;
V_176 -> V_131 += V_180 ;
}
V_176 -> V_146 = V_22 -> V_45 . V_146 ;
V_176 -> V_145 = V_22 -> V_45 . V_145 ;
V_176 -> V_46 = V_22 -> V_45 . V_46 ;
V_176 -> V_54 = V_22 -> V_45 . V_54 ;
V_176 -> V_92 = V_22 -> V_45 . V_92 ;
return V_176 ;
}
static void F_128 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ )
F_129 ( & V_19 -> V_11 [ V_99 ] . V_34 ) ;
}
static void F_130 ( struct V_18 * V_19 )
{
F_131 () ;
if ( ! F_113 ( V_19 , V_183 ,
V_184 , NULL ) )
F_106 ( & V_19 -> V_22 -> V_22 , L_14 ) ;
F_132 () ;
}
static int F_133 ( struct V_18 * V_19 , T_2 V_185 )
{
struct V_150 V_96 ;
struct V_186 V_187 ;
struct V_43 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_188 || ! F_114 ( V_19 -> V_20 , V_189 ) )
return 0 ;
V_187 . V_190 = F_93 ( V_19 -> V_20 , V_185 ) ;
F_63 ( & V_96 , & V_187 , sizeof( V_187 ) ) ;
if ( ! F_113 ( V_19 , V_191 ,
V_192 , & V_96 ) ) {
F_106 ( & V_22 -> V_22 , L_15 ,
V_185 ) ;
return - V_170 ;
} else {
V_19 -> V_113 = V_185 ;
if ( V_22 -> V_69 & V_193 )
F_76 ( & V_19 -> V_111 , 0 ) ;
}
return 0 ;
}
static int F_134 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
int V_99 ;
F_135 ( & V_19 -> V_111 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
F_75 ( & V_19 -> V_11 [ V_99 ] . V_34 ) ;
return 0 ;
}
static void F_136 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_150 V_96 [ 2 ] ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
int V_198 ;
int V_199 ;
void * V_26 ;
int V_99 ;
if ( ! F_114 ( V_19 -> V_20 , V_200 ) )
return;
V_19 -> V_201 = ( ( V_22 -> V_69 & V_202 ) != 0 ) ;
V_19 -> V_203 = ( ( V_22 -> V_69 & V_204 ) != 0 ) ;
F_63 ( V_96 , & V_19 -> V_201 , sizeof( V_19 -> V_201 ) ) ;
if ( ! F_113 ( V_19 , V_205 ,
V_206 , V_96 ) )
F_106 ( & V_22 -> V_22 , L_16 ,
V_19 -> V_201 ? L_17 : L_18 ) ;
F_63 ( V_96 , & V_19 -> V_203 , sizeof( V_19 -> V_203 ) ) ;
if ( ! F_113 ( V_19 , V_205 ,
V_207 , V_96 ) )
F_106 ( & V_22 -> V_22 , L_19 ,
V_19 -> V_203 ? L_17 : L_18 ) ;
V_198 = F_137 ( V_22 ) ;
V_199 = F_138 ( V_22 ) ;
V_26 = F_139 ( ( ( V_198 + V_199 ) * V_208 ) +
( 2 * sizeof( V_195 -> V_209 ) ) , V_57 ) ;
V_195 = V_26 ;
if ( ! V_26 )
return;
F_52 ( V_96 , 2 ) ;
V_195 -> V_209 = F_140 ( V_19 -> V_20 , V_198 ) ;
V_99 = 0 ;
F_141 (ha, dev)
memcpy ( & V_195 -> V_210 [ V_99 ++ ] [ 0 ] , V_197 -> V_164 , V_208 ) ;
F_53 ( & V_96 [ 0 ] , V_195 ,
sizeof( V_195 -> V_209 ) + ( V_198 * V_208 ) ) ;
V_195 = ( void * ) & V_195 -> V_210 [ V_198 ] [ 0 ] ;
V_195 -> V_209 = F_140 ( V_19 -> V_20 , V_199 ) ;
V_99 = 0 ;
F_142 (ha, dev)
memcpy ( & V_195 -> V_210 [ V_99 ++ ] [ 0 ] , V_197 -> V_164 , V_208 ) ;
F_53 ( & V_96 [ 1 ] , V_195 ,
sizeof( V_195 -> V_209 ) + ( V_199 * V_208 ) ) ;
if ( ! F_113 ( V_19 , V_168 ,
V_211 , V_96 ) )
F_106 ( & V_22 -> V_22 , L_20 ) ;
F_143 ( V_26 ) ;
}
static int F_144 ( struct V_43 * V_22 ,
T_7 V_212 , T_2 V_213 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_150 V_96 ;
F_63 ( & V_96 , & V_213 , sizeof( V_213 ) ) ;
if ( ! F_113 ( V_19 , V_214 ,
V_215 , & V_96 ) )
F_106 ( & V_22 -> V_22 , L_21 , V_213 ) ;
return 0 ;
}
static int F_145 ( struct V_43 * V_22 ,
T_7 V_212 , T_2 V_213 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_150 V_96 ;
F_63 ( & V_96 , & V_213 , sizeof( V_213 ) ) ;
if ( ! F_113 ( V_19 , V_214 ,
V_216 , & V_96 ) )
F_106 ( & V_22 -> V_22 , L_22 , V_213 ) ;
return 0 ;
}
static void F_146 ( struct V_18 * V_19 , long V_217 )
{
int V_99 ;
if ( V_19 -> V_218 ) {
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
F_147 ( V_19 -> V_11 [ V_99 ] . V_2 , - 1 ) ;
F_147 ( V_19 -> V_129 [ V_99 ] . V_2 , - 1 ) ;
}
V_19 -> V_218 = false ;
}
}
static void F_148 ( struct V_18 * V_19 )
{
int V_99 ;
int V_177 ;
if ( V_19 -> V_113 == 1 ||
V_19 -> V_127 != F_149 () ) {
F_146 ( V_19 , - 1 ) ;
return;
}
V_99 = 0 ;
F_150 (cpu) {
F_147 ( V_19 -> V_11 [ V_99 ] . V_2 , V_177 ) ;
F_147 ( V_19 -> V_129 [ V_99 ] . V_2 , V_177 ) ;
F_151 ( V_19 -> V_22 , F_152 ( V_177 ) , V_99 ) ;
V_99 ++ ;
}
V_19 -> V_218 = true ;
}
static int F_153 ( struct V_219 * V_220 ,
unsigned long V_221 , void * V_217 )
{
struct V_18 * V_19 = F_74 ( V_220 , struct V_18 , V_222 ) ;
switch( V_221 & ~ V_223 ) {
case V_224 :
case V_225 :
case V_226 :
F_148 ( V_19 ) ;
break;
case V_227 :
F_146 ( V_19 , ( long ) V_217 ) ;
break;
default:
break;
}
return V_228 ;
}
static void F_154 ( struct V_43 * V_22 ,
struct V_229 * V_230 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
V_230 -> V_231 = F_78 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_230 -> V_232 = F_78 ( V_19 -> V_129 [ 0 ] . V_2 ) ;
V_230 -> V_233 = V_230 -> V_231 ;
V_230 -> V_234 = V_230 -> V_232 ;
}
static void F_155 ( struct V_43 * V_22 ,
struct V_235 * V_236 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
struct V_161 * V_20 = V_19 -> V_20 ;
F_156 ( V_236 -> V_237 , V_238 , sizeof( V_236 -> V_237 ) ) ;
F_156 ( V_236 -> V_239 , V_240 , sizeof( V_236 -> V_239 ) ) ;
F_156 ( V_236 -> V_241 , F_157 ( V_20 ) , sizeof( V_236 -> V_241 ) ) ;
}
static int F_158 ( struct V_43 * V_22 ,
struct V_242 * V_243 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
T_2 V_185 = V_243 -> V_244 ;
int V_44 ;
if ( V_243 -> V_245 || V_243 -> V_246 || V_243 -> V_247 )
return - V_170 ;
if ( V_185 > V_19 -> V_127 || V_185 == 0 )
return - V_170 ;
F_159 () ;
V_44 = F_133 ( V_19 , V_185 ) ;
if ( ! V_44 ) {
F_160 ( V_22 , V_185 ) ;
F_161 ( V_22 , V_185 ) ;
F_148 ( V_19 ) ;
}
F_162 () ;
return V_44 ;
}
static void F_163 ( struct V_43 * V_22 ,
struct V_242 * V_243 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
V_243 -> V_244 = V_19 -> V_113 ;
V_243 -> V_248 = V_19 -> V_127 ;
V_243 -> V_249 = 0 ;
V_243 -> V_245 = 0 ;
V_243 -> V_246 = 0 ;
V_243 -> V_247 = 0 ;
}
static bool F_164 ( const struct V_250 * V_149 )
{
struct V_250 V_251 = * V_149 ;
struct V_250 V_252 = {} ;
F_165 ( & V_251 , 0 ) ;
V_252 . V_253 = V_254 ;
V_251 . V_255 = 0 ;
V_251 . V_256 = 0 ;
V_251 . V_149 = 0 ;
return ! memcmp ( & V_251 , & V_252 , sizeof( V_251 ) ) ;
}
static int F_166 ( struct V_43 * V_22 , struct V_250 * V_149 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
T_8 V_257 ;
V_257 = F_167 ( V_149 ) ;
if ( ! F_168 ( V_257 ) ||
! F_169 ( V_149 -> V_256 ) ||
! F_164 ( V_149 ) )
return - V_170 ;
V_19 -> V_257 = V_257 ;
V_19 -> V_256 = V_149 -> V_256 ;
return 0 ;
}
static int F_170 ( struct V_43 * V_22 , struct V_250 * V_149 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
F_165 ( V_149 , V_19 -> V_257 ) ;
V_149 -> V_256 = V_19 -> V_256 ;
V_149 -> V_253 = V_254 ;
return 0 ;
}
static void F_171 ( struct V_43 * V_22 )
{
struct V_18 * V_19 = F_86 ( V_22 ) ;
V_19 -> V_257 = V_258 ;
V_19 -> V_256 = V_259 ;
}
static int F_172 ( struct V_43 * V_22 , int V_260 )
{
if ( V_260 < V_261 || V_260 > V_262 )
return - V_170 ;
V_22 -> V_263 = V_260 ;
return 0 ;
}
static void F_173 ( struct V_109 * V_110 )
{
struct V_18 * V_19 =
F_74 ( V_110 , struct V_18 , V_264 ) ;
T_2 V_265 ;
if ( F_174 ( V_19 -> V_20 , V_266 ,
struct V_173 , V_120 , & V_265 ) < 0 )
return;
if ( V_265 & V_267 ) {
F_175 ( V_19 -> V_22 ) ;
F_130 ( V_19 ) ;
}
V_265 &= V_121 ;
if ( V_19 -> V_120 == V_265 )
return;
V_19 -> V_120 = V_265 ;
if ( V_19 -> V_120 & V_121 ) {
F_176 ( V_19 -> V_22 ) ;
F_177 ( V_19 -> V_22 ) ;
} else {
F_178 ( V_19 -> V_22 ) ;
F_179 ( V_19 -> V_22 ) ;
}
}
static void F_180 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_181 ( & V_19 -> V_264 ) ;
}
static void F_182 ( struct V_18 * V_19 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
F_183 ( & V_19 -> V_11 [ V_99 ] . V_34 ) ;
F_184 ( & V_19 -> V_11 [ V_99 ] . V_34 ) ;
}
F_143 ( V_19 -> V_11 ) ;
F_143 ( V_19 -> V_129 ) ;
}
static void F_185 ( struct V_18 * V_19 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
while ( V_19 -> V_11 [ V_99 ] . V_15 )
F_186 ( F_7 ( & V_19 -> V_11 [ V_99 ] , V_114 ) , 0 ) ;
}
}
static void F_187 ( struct V_18 * V_19 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
if ( V_19 -> V_11 [ V_99 ] . V_103 . V_12 )
F_22 ( V_19 -> V_11 [ V_99 ] . V_103 . V_12 ) ;
}
static void F_188 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
struct V_1 * V_2 = V_19 -> V_129 [ V_99 ] . V_2 ;
while ( ( V_26 = F_189 ( V_2 ) ) != NULL )
F_24 ( V_26 ) ;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_99 ] . V_2 ;
while ( ( V_26 = F_189 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_36 ) {
unsigned long V_47 = ( unsigned long ) V_26 ;
void * V_64 = F_13 ( V_47 ) ;
F_22 ( F_33 ( V_64 ) ) ;
} else if ( V_19 -> V_65 ) {
F_6 ( & V_19 -> V_11 [ V_99 ] , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
}
}
}
static void F_190 ( struct V_18 * V_19 )
{
struct V_161 * V_20 = V_19 -> V_20 ;
F_146 ( V_19 , - 1 ) ;
V_20 -> V_268 -> V_269 ( V_20 ) ;
F_182 ( V_19 ) ;
}
static int F_191 ( struct V_18 * V_19 )
{
T_9 * * V_270 ;
struct V_1 * * V_271 ;
int V_162 = - V_95 ;
int V_99 , V_272 ;
const char * * V_273 ;
V_272 = V_19 -> V_127 * 2 +
F_114 ( V_19 -> V_20 , V_156 ) ;
V_271 = F_139 ( V_272 * sizeof( * V_271 ) , V_114 ) ;
if ( ! V_271 )
goto V_274;
V_270 = F_192 ( V_272 * sizeof( * V_270 ) , V_114 ) ;
if ( ! V_270 )
goto V_275;
V_273 = F_192 ( V_272 * sizeof( * V_273 ) , V_114 ) ;
if ( ! V_273 )
goto V_276;
if ( V_19 -> V_188 ) {
V_270 [ V_272 - 1 ] = NULL ;
V_273 [ V_272 - 1 ] = L_23 ;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
V_270 [ F_4 ( V_99 ) ] = F_66 ;
V_270 [ F_2 ( V_99 ) ] = F_9 ;
sprintf ( V_19 -> V_11 [ V_99 ] . V_40 , L_24 , V_99 ) ;
sprintf ( V_19 -> V_129 [ V_99 ] . V_40 , L_25 , V_99 ) ;
V_273 [ F_4 ( V_99 ) ] = V_19 -> V_11 [ V_99 ] . V_40 ;
V_273 [ F_2 ( V_99 ) ] = V_19 -> V_129 [ V_99 ] . V_40 ;
}
V_162 = V_19 -> V_20 -> V_268 -> V_277 ( V_19 -> V_20 , V_272 , V_271 , V_270 ,
V_273 ) ;
if ( V_162 )
goto V_278;
if ( V_19 -> V_188 ) {
V_19 -> V_159 = V_271 [ V_272 - 1 ] ;
if ( F_114 ( V_19 -> V_20 , V_279 ) )
V_19 -> V_22 -> V_280 |= V_281 ;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
V_19 -> V_11 [ V_99 ] . V_2 = V_271 [ F_4 ( V_99 ) ] ;
V_19 -> V_129 [ V_99 ] . V_2 = V_271 [ F_2 ( V_99 ) ] ;
}
F_143 ( V_273 ) ;
F_143 ( V_270 ) ;
F_143 ( V_271 ) ;
return 0 ;
V_278:
F_143 ( V_273 ) ;
V_276:
F_143 ( V_270 ) ;
V_275:
F_143 ( V_271 ) ;
V_274:
return V_162 ;
}
static int F_193 ( struct V_18 * V_19 )
{
int V_99 ;
V_19 -> V_129 = F_139 ( sizeof( * V_19 -> V_129 ) * V_19 -> V_127 , V_114 ) ;
if ( ! V_19 -> V_129 )
goto V_282;
V_19 -> V_11 = F_139 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_127 , V_114 ) ;
if ( ! V_19 -> V_11 )
goto V_283;
F_194 ( & V_19 -> V_111 , F_73 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
V_19 -> V_11 [ V_99 ] . V_15 = NULL ;
F_195 ( V_19 -> V_22 , & V_19 -> V_11 [ V_99 ] . V_34 , F_79 ,
V_284 ) ;
F_52 ( V_19 -> V_11 [ V_99 ] . V_96 , F_115 ( V_19 -> V_11 [ V_99 ] . V_96 ) ) ;
F_196 ( & V_19 -> V_11 [ V_99 ] . V_61 ) ;
F_52 ( V_19 -> V_129 [ V_99 ] . V_96 , F_115 ( V_19 -> V_129 [ V_99 ] . V_96 ) ) ;
}
return 0 ;
V_283:
F_143 ( V_19 -> V_129 ) ;
V_282:
return - V_95 ;
}
static int F_197 ( struct V_18 * V_19 )
{
int V_162 ;
V_162 = F_193 ( V_19 ) ;
if ( V_162 )
goto V_44;
V_162 = F_191 ( V_19 ) ;
if ( V_162 )
goto V_285;
F_159 () ;
F_148 ( V_19 ) ;
F_162 () ;
return 0 ;
V_285:
F_182 ( V_19 ) ;
V_44:
return V_162 ;
}
static T_10 F_198 ( struct V_286 * V_287 ,
struct V_288 * V_289 , char * V_26 )
{
struct V_18 * V_19 = F_86 ( V_287 -> V_22 ) ;
unsigned int V_290 = F_199 ( V_287 ) ;
struct V_100 * V_291 ;
F_25 ( V_290 >= V_19 -> V_127 ) ;
V_291 = & V_19 -> V_11 [ V_290 ] . V_61 ;
return sprintf ( V_26 , L_26 , F_57 ( V_291 ) ) ;
}
static bool F_200 ( struct V_161 * V_20 ,
unsigned int V_292 ,
const char * V_293 , const char * V_294 )
{
if ( ! F_114 ( V_20 , V_292 ) )
return false ;
F_201 ( & V_20 -> V_22 , L_27 ,
V_293 , V_294 ) ;
return true ;
}
static bool F_202 ( struct V_161 * V_20 )
{
if ( ! F_114 ( V_20 , V_156 ) &&
( F_203 ( V_20 , V_200 ,
L_28 ) ||
F_203 ( V_20 , V_279 ,
L_28 ) ||
F_203 ( V_20 , V_295 ,
L_28 ) ||
F_203 ( V_20 , V_189 , L_28 ) ||
F_203 ( V_20 , V_165 ,
L_28 ) ) ) {
return false ;
}
return true ;
}
static int F_204 ( struct V_161 * V_20 )
{
int V_99 , V_44 ;
struct V_43 * V_22 ;
struct V_18 * V_19 ;
T_2 V_127 ;
if ( ! V_20 -> V_268 -> V_296 ) {
F_201 ( & V_20 -> V_22 , L_29 ,
V_297 ) ;
return - V_170 ;
}
if ( ! F_202 ( V_20 ) )
return - V_170 ;
V_44 = F_174 ( V_20 , V_189 ,
struct V_173 ,
V_298 , & V_127 ) ;
if ( V_44 || V_127 < V_299 ||
V_127 > V_300 ||
! F_114 ( V_20 , V_156 ) )
V_127 = 1 ;
V_22 = F_205 ( sizeof( struct V_18 ) , V_127 ) ;
if ( ! V_22 )
return - V_95 ;
V_22 -> V_301 |= V_302 | V_303 ;
V_22 -> V_304 = & V_305 ;
V_22 -> V_280 = V_306 ;
V_22 -> V_307 = & V_308 ;
F_206 ( V_22 , & V_20 -> V_22 ) ;
if ( F_114 ( V_20 , V_309 ) ) {
V_22 -> V_310 |= V_311 | V_312 ;
if ( V_313 )
V_22 -> V_280 |= V_311 | V_312 ;
if ( F_114 ( V_20 , V_314 ) ) {
V_22 -> V_310 |= V_315 | V_316
| V_317 | V_318 ;
}
if ( F_114 ( V_20 , V_319 ) )
V_22 -> V_310 |= V_315 ;
if ( F_114 ( V_20 , V_320 ) )
V_22 -> V_310 |= V_318 ;
if ( F_114 ( V_20 , V_321 ) )
V_22 -> V_310 |= V_317 ;
if ( F_114 ( V_20 , V_322 ) )
V_22 -> V_310 |= V_316 ;
V_22 -> V_280 |= V_323 ;
if ( V_324 )
V_22 -> V_280 |= V_22 -> V_310 & ( V_325 | V_316 ) ;
}
if ( F_114 ( V_20 , V_326 ) )
V_22 -> V_280 |= V_327 ;
V_22 -> V_328 = V_22 -> V_280 ;
if ( F_114 ( V_20 , V_171 ) )
F_207 ( V_20 ,
F_122 ( struct V_173 , V_174 ) ,
V_22 -> V_329 , V_22 -> V_167 ) ;
else
F_208 ( V_22 ) ;
V_19 = F_86 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_45 = F_209 ( struct V_62 ) ;
V_44 = - V_95 ;
if ( V_19 -> V_45 == NULL )
goto free;
F_124 (i) {
struct V_62 * V_62 ;
V_62 = F_125 ( V_19 -> V_45 , V_99 ) ;
F_210 ( & V_62 -> V_130 ) ;
F_210 ( & V_62 -> V_66 ) ;
}
F_211 ( & V_19 -> V_264 , F_173 ) ;
if ( F_114 ( V_20 , V_330 ) ||
F_114 ( V_20 , V_331 ) ||
F_114 ( V_20 , V_332 ) ||
F_114 ( V_20 , V_333 ) )
V_19 -> V_65 = true ;
if ( F_114 ( V_20 , V_334 ) )
V_19 -> V_36 = true ;
if ( F_114 ( V_20 , V_334 ) ||
F_114 ( V_20 , V_172 ) )
V_19 -> V_32 = sizeof( struct V_6 ) ;
else
V_19 -> V_32 = sizeof( struct V_335 ) ;
if ( F_114 ( V_20 , V_336 ) ||
F_114 ( V_20 , V_172 ) )
V_19 -> V_139 = true ;
if ( F_114 ( V_20 , V_156 ) )
V_19 -> V_188 = true ;
if ( V_19 -> V_139 )
V_22 -> V_337 = V_19 -> V_32 ;
V_19 -> V_113 = 1 ;
V_19 -> V_127 = V_127 ;
V_44 = F_197 ( V_19 ) ;
if ( V_44 )
goto V_338;
#ifdef F_212
if ( V_19 -> V_36 )
V_22 -> V_339 = & V_340 ;
#endif
F_160 ( V_22 , V_19 -> V_113 ) ;
F_161 ( V_22 , V_19 -> V_113 ) ;
F_171 ( V_22 ) ;
V_44 = F_213 ( V_22 ) ;
if ( V_44 ) {
F_36 ( L_30 ) ;
goto V_341;
}
F_214 ( V_20 ) ;
V_19 -> V_222 . V_342 = & F_153 ;
V_44 = F_215 ( & V_19 -> V_222 ) ;
if ( V_44 ) {
F_36 ( L_31 ) ;
goto V_343;
}
if ( F_114 ( V_19 -> V_20 , V_266 ) ) {
F_178 ( V_22 ) ;
F_181 ( & V_19 -> V_264 ) ;
} else {
V_19 -> V_120 = V_121 ;
F_176 ( V_22 ) ;
}
F_36 ( L_32 ,
V_22 -> V_40 , V_127 ) ;
return 0 ;
V_343:
V_19 -> V_20 -> V_268 -> V_344 ( V_20 ) ;
F_216 ( V_22 ) ;
V_341:
F_135 ( & V_19 -> V_111 ) ;
F_187 ( V_19 ) ;
F_190 ( V_19 ) ;
V_338:
F_217 ( V_19 -> V_45 ) ;
free:
F_218 ( V_22 ) ;
return V_44 ;
}
static void F_219 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_268 -> V_344 ( V_19 -> V_20 ) ;
F_188 ( V_19 ) ;
F_185 ( V_19 ) ;
F_187 ( V_19 ) ;
F_190 ( V_19 ) ;
}
static void F_220 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_221 ( & V_19 -> V_222 ) ;
F_222 ( & V_19 -> V_264 ) ;
F_216 ( V_19 -> V_22 ) ;
F_219 ( V_19 ) ;
F_217 ( V_19 -> V_45 ) ;
F_218 ( V_19 -> V_22 ) ;
}
static int F_223 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_99 ;
F_221 ( & V_19 -> V_222 ) ;
F_222 ( & V_19 -> V_264 ) ;
F_224 ( V_19 -> V_22 ) ;
F_135 ( & V_19 -> V_111 ) ;
if ( F_225 ( V_19 -> V_22 ) ) {
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
F_75 ( & V_19 -> V_11 [ V_99 ] . V_34 ) ;
}
F_219 ( V_19 ) ;
return 0 ;
}
static int F_226 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_44 , V_99 ;
V_44 = F_197 ( V_19 ) ;
if ( V_44 )
return V_44 ;
F_214 ( V_20 ) ;
if ( F_225 ( V_19 -> V_22 ) ) {
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ )
if ( ! F_64 ( V_19 , & V_19 -> V_11 [ V_99 ] , V_114 ) )
F_76 ( & V_19 -> V_111 , 0 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
F_69 ( & V_19 -> V_11 [ V_99 ] ) ;
}
F_227 ( V_19 -> V_22 ) ;
F_131 () ;
F_133 ( V_19 , V_19 -> V_113 ) ;
F_132 () ;
V_44 = F_215 ( & V_19 -> V_222 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
}
