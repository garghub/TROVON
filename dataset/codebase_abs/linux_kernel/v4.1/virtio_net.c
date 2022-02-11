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
V_8 = F_17 ( V_19 -> V_22 , V_34 ) ;
if ( F_18 ( ! V_8 ) )
return NULL ;
V_30 = F_5 ( V_8 ) ;
V_32 = V_19 -> V_32 ;
if ( V_19 -> V_35 )
V_33 = sizeof *V_30 ;
else
V_33 = sizeof( struct V_36 ) ;
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
if ( V_19 -> V_35 ) {
if ( V_29 )
F_21 ( V_8 , 0 , V_12 , V_28 , V_29 , V_24 ) ;
else
F_22 ( V_12 ) ;
return V_8 ;
}
if ( F_18 ( V_29 > V_37 * V_38 ) ) {
F_23 ( L_1 , V_8 -> V_22 -> V_39 ) ;
F_24 ( V_8 ) ;
return NULL ;
}
F_25 ( V_28 >= V_38 ) ;
while ( V_29 ) {
unsigned int V_40 = F_26 ( ( unsigned ) V_38 - V_28 , V_29 ) ;
F_21 ( V_8 , F_27 ( V_8 ) -> V_41 , V_12 , V_28 ,
V_40 , V_24 ) ;
V_29 -= V_40 ;
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
static struct V_7 * F_30 ( struct V_42 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
void * V_26 ,
unsigned int V_29 )
{
struct V_12 * V_12 = V_26 ;
struct V_7 * V_8 = F_15 ( V_19 , V_11 , V_12 , 0 , V_29 , V_38 ) ;
if ( F_18 ( ! V_8 ) )
goto V_43;
return V_8 ;
V_43:
V_22 -> V_44 . V_45 ++ ;
F_6 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_7 * F_31 ( struct V_42 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
unsigned long V_46 ,
unsigned int V_29 )
{
void * V_26 = F_13 ( V_46 ) ;
struct V_6 * V_30 = V_26 ;
T_2 V_47 = F_32 ( V_19 -> V_20 , V_30 -> V_48 ) ;
struct V_12 * V_12 = F_33 ( V_26 ) ;
int V_28 = V_26 - F_16 ( V_12 ) ;
unsigned int V_24 = F_34 ( V_29 , F_12 ( V_46 ) ) ;
struct V_7 * V_49 = F_15 ( V_19 , V_11 , V_12 , V_28 , V_29 ,
V_24 ) ;
struct V_7 * V_50 = V_49 ;
if ( F_18 ( ! V_50 ) )
goto V_51;
while ( -- V_47 ) {
int V_52 ;
V_46 = ( unsigned long ) F_35 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_46 ) ) {
F_36 ( L_2 ,
V_22 -> V_39 , V_47 ,
F_32 ( V_19 -> V_20 ,
V_30 -> V_48 ) ) ;
V_22 -> V_44 . V_53 ++ ;
goto V_54;
}
V_26 = F_13 ( V_46 ) ;
V_12 = F_33 ( V_26 ) ;
V_52 = F_27 ( V_50 ) -> V_41 ;
if ( F_18 ( V_52 == V_37 ) ) {
struct V_7 * V_55 = F_37 ( 0 , V_56 ) ;
if ( F_18 ( ! V_55 ) )
goto V_51;
if ( V_50 == V_49 )
F_27 ( V_50 ) -> V_57 = V_55 ;
else
V_50 -> V_58 = V_55 ;
V_50 = V_55 ;
V_49 -> V_24 += V_55 -> V_24 ;
V_52 = 0 ;
}
V_24 = F_34 ( V_29 , F_12 ( V_46 ) ) ;
if ( V_50 != V_49 ) {
V_49 -> V_59 += V_29 ;
V_49 -> V_29 += V_29 ;
V_49 -> V_24 += V_24 ;
}
V_28 = V_26 - F_16 ( V_12 ) ;
if ( F_38 ( V_50 , V_52 , V_12 , V_28 ) ) {
F_22 ( V_12 ) ;
F_39 ( V_50 , V_52 - 1 ,
V_29 , V_24 ) ;
} else {
F_21 ( V_50 , V_52 , V_12 ,
V_28 , V_29 , V_24 ) ;
}
}
F_40 ( & V_11 -> V_60 , V_49 -> V_29 ) ;
return V_49 ;
V_51:
F_22 ( V_12 ) ;
while ( -- V_47 ) {
V_46 = ( unsigned long ) F_35 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_46 ) ) {
F_36 ( L_3 ,
V_22 -> V_39 , V_47 ) ;
V_22 -> V_44 . V_53 ++ ;
break;
}
V_12 = F_33 ( F_13 ( V_46 ) ) ;
F_22 ( V_12 ) ;
}
V_54:
V_22 -> V_44 . V_45 ++ ;
F_24 ( V_49 ) ;
return NULL ;
}
static void F_41 ( struct V_18 * V_19 , struct V_10 * V_11 ,
void * V_26 , unsigned int V_29 )
{
struct V_42 * V_22 = V_19 -> V_22 ;
struct V_61 * V_44 = F_42 ( V_19 -> V_44 ) ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
if ( F_18 ( V_29 < V_19 -> V_32 + V_62 ) ) {
F_36 ( L_4 , V_22 -> V_39 , V_29 ) ;
V_22 -> V_44 . V_53 ++ ;
if ( V_19 -> V_35 ) {
unsigned long V_46 = ( unsigned long ) V_26 ;
void * V_63 = F_13 ( V_46 ) ;
F_22 ( F_33 ( V_63 ) ) ;
} else if ( V_19 -> V_64 ) {
F_6 ( V_11 , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
return;
}
if ( V_19 -> V_35 )
V_8 = F_31 ( V_22 , V_19 , V_11 , ( unsigned long ) V_26 , V_29 ) ;
else if ( V_19 -> V_64 )
V_8 = F_30 ( V_22 , V_19 , V_11 , V_26 , V_29 ) ;
else
V_8 = F_28 ( V_19 , V_26 , V_29 ) ;
if ( F_18 ( ! V_8 ) )
return;
V_30 = F_5 ( V_8 ) ;
F_43 ( & V_44 -> V_65 ) ;
V_44 -> V_66 += V_8 -> V_29 ;
V_44 -> V_67 ++ ;
F_44 ( & V_44 -> V_65 ) ;
if ( V_30 -> V_30 . V_68 & V_69 ) {
F_36 ( L_5 ) ;
if ( ! F_45 ( V_8 ,
F_32 ( V_19 -> V_20 , V_30 -> V_30 . V_70 ) ,
F_32 ( V_19 -> V_20 , V_30 -> V_30 . V_71 ) ) )
goto V_72;
} else if ( V_30 -> V_30 . V_68 & V_73 ) {
V_8 -> V_74 = V_75 ;
}
V_8 -> V_76 = F_46 ( V_8 , V_22 ) ;
F_36 ( L_6 ,
F_47 ( V_8 -> V_76 ) , V_8 -> V_29 , V_8 -> V_77 ) ;
if ( V_30 -> V_30 . V_78 != V_79 ) {
F_36 ( L_7 ) ;
switch ( V_30 -> V_30 . V_78 & ~ V_80 ) {
case V_81 :
F_27 ( V_8 ) -> V_78 = V_82 ;
break;
case V_83 :
F_27 ( V_8 ) -> V_78 = V_84 ;
break;
case V_85 :
F_27 ( V_8 ) -> V_78 = V_86 ;
break;
default:
F_48 ( L_8 ,
V_22 -> V_39 , V_30 -> V_30 . V_78 ) ;
goto V_72;
}
if ( V_30 -> V_30 . V_78 & V_80 )
F_27 ( V_8 ) -> V_78 |= V_87 ;
F_27 ( V_8 ) -> V_88 = F_32 ( V_19 -> V_20 ,
V_30 -> V_30 . V_88 ) ;
if ( F_27 ( V_8 ) -> V_88 == 0 ) {
F_48 ( L_9 , V_22 -> V_39 ) ;
goto V_72;
}
F_27 ( V_8 ) -> V_78 |= V_89 ;
F_27 ( V_8 ) -> V_90 = 0 ;
}
F_49 ( V_8 , & V_11 -> V_91 ) ;
F_50 ( V_8 ) ;
return;
V_72:
V_22 -> V_44 . V_92 ++ ;
F_24 ( V_8 ) ;
}
static int F_51 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_93 )
{
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_43 ;
V_8 = F_52 ( V_19 -> V_22 , V_94 , V_93 ) ;
if ( F_18 ( ! V_8 ) )
return - V_95 ;
F_20 ( V_8 , V_94 ) ;
V_30 = F_5 ( V_8 ) ;
F_53 ( V_11 -> V_96 , V_37 + 2 ) ;
F_54 ( V_11 -> V_96 , V_30 , V_19 -> V_32 ) ;
F_55 ( V_8 , V_11 -> V_96 + 1 , 0 , V_8 -> V_29 ) ;
V_43 = F_56 ( V_11 -> V_2 , V_11 -> V_96 , 2 , V_8 , V_93 ) ;
if ( V_43 < 0 )
F_24 ( V_8 ) ;
return V_43 ;
}
static int F_57 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_93 )
{
struct V_12 * V_97 , * V_98 = NULL ;
char * V_17 ;
int V_99 , V_43 , V_28 ;
F_53 ( V_11 -> V_96 , V_37 + 2 ) ;
for ( V_99 = V_37 + 1 ; V_99 > 1 ; -- V_99 ) {
V_97 = F_7 ( V_11 , V_93 ) ;
if ( ! V_97 ) {
if ( V_98 )
F_6 ( V_11 , V_98 ) ;
return - V_95 ;
}
F_54 ( & V_11 -> V_96 [ V_99 ] , F_16 ( V_97 ) , V_38 ) ;
V_97 -> V_14 = ( unsigned long ) V_98 ;
V_98 = V_97 ;
}
V_97 = F_7 ( V_11 , V_93 ) ;
if ( ! V_97 ) {
F_6 ( V_11 , V_98 ) ;
return - V_95 ;
}
V_17 = F_16 ( V_97 ) ;
F_54 ( & V_11 -> V_96 [ 0 ] , V_17 , V_19 -> V_32 ) ;
V_28 = sizeof( struct V_36 ) ;
F_54 ( & V_11 -> V_96 [ 1 ] , V_17 + V_28 , V_38 - V_28 ) ;
V_97 -> V_14 = ( unsigned long ) V_98 ;
V_43 = F_56 ( V_11 -> V_2 , V_11 -> V_96 , V_37 + 2 ,
V_97 , V_93 ) ;
if ( V_43 < 0 )
F_6 ( V_11 , V_97 ) ;
return V_43 ;
}
static unsigned int F_58 ( struct V_100 * V_101 )
{
const T_3 V_32 = sizeof( struct V_6 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_59 (unsigned int, ewma_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_60 ( V_29 , V_25 ) ;
}
static int F_61 ( struct V_10 * V_11 , T_1 V_93 )
{
struct V_102 * V_103 = & V_11 -> V_103 ;
char * V_26 ;
unsigned long V_46 ;
int V_43 ;
unsigned int V_29 , V_104 ;
V_29 = F_58 ( & V_11 -> V_60 ) ;
if ( F_18 ( ! F_62 ( V_29 , V_103 , V_93 ) ) )
return - V_95 ;
V_26 = ( char * ) F_16 ( V_103 -> V_12 ) + V_103 -> V_28 ;
V_46 = F_14 ( V_26 , V_29 ) ;
F_63 ( V_103 -> V_12 ) ;
V_103 -> V_28 += V_29 ;
V_104 = V_103 -> V_27 - V_103 -> V_28 ;
if ( V_104 < V_29 ) {
V_29 += V_104 ;
V_103 -> V_28 += V_104 ;
}
F_64 ( V_11 -> V_96 , V_26 , V_29 ) ;
V_43 = F_56 ( V_11 -> V_2 , V_11 -> V_96 , 1 , ( void * ) V_46 , V_93 ) ;
if ( V_43 < 0 )
F_22 ( F_33 ( V_26 ) ) ;
return V_43 ;
}
static bool F_65 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_93 )
{
int V_43 ;
bool V_105 ;
V_93 |= V_106 ;
do {
if ( V_19 -> V_35 )
V_43 = F_61 ( V_11 , V_93 ) ;
else if ( V_19 -> V_64 )
V_43 = F_57 ( V_19 , V_11 , V_93 ) ;
else
V_43 = F_51 ( V_19 , V_11 , V_93 ) ;
V_105 = V_43 == - V_95 ;
if ( V_43 )
break;
} while ( V_11 -> V_2 -> V_107 );
F_66 ( V_11 -> V_2 ) ;
return ! V_105 ;
}
static void F_67 ( struct V_1 * V_108 )
{
struct V_18 * V_19 = V_108 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_108 ) ] ;
if ( F_68 ( & V_11 -> V_91 ) ) {
F_10 ( V_108 ) ;
F_69 ( & V_11 -> V_91 ) ;
}
}
static void F_70 ( struct V_10 * V_11 )
{
F_71 ( & V_11 -> V_91 ) ;
if ( F_68 ( & V_11 -> V_91 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_72 () ;
F_69 ( & V_11 -> V_91 ) ;
F_73 () ;
}
}
static void F_74 ( struct V_109 * V_110 )
{
struct V_18 * V_19 =
F_75 ( V_110 , struct V_18 , V_111 . V_110 ) ;
bool V_112 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_99 ] ;
F_76 ( & V_11 -> V_91 ) ;
V_112 = ! F_65 ( V_19 , V_11 , V_114 ) ;
F_70 ( V_11 ) ;
if ( V_112 )
F_77 ( & V_19 -> V_111 , V_115 / 2 ) ;
}
}
static int F_78 ( struct V_10 * V_11 , int V_116 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_117 = 0 ;
void * V_26 ;
while ( V_117 < V_116 &&
( V_26 = F_35 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_41 ( V_19 , V_11 , V_26 , V_29 ) ;
V_117 ++ ;
}
if ( V_11 -> V_2 -> V_107 > F_79 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_65 ( V_19 , V_11 , V_56 ) )
F_77 ( & V_19 -> V_111 , 0 ) ;
}
return V_117 ;
}
static int F_80 ( struct V_118 * V_91 , int V_116 )
{
struct V_10 * V_11 =
F_75 ( V_91 , struct V_10 , V_91 ) ;
unsigned int V_119 , V_117 ;
V_117 = F_78 ( V_11 , V_116 ) ;
if ( V_117 < V_116 ) {
V_119 = F_81 ( V_11 -> V_2 ) ;
F_82 ( V_91 ) ;
if ( F_18 ( F_83 ( V_11 -> V_2 , V_119 ) ) &&
F_68 ( V_91 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_69 ( V_91 ) ;
}
}
return V_117 ;
}
static int F_84 ( struct V_118 * V_91 )
{
struct V_10 * V_11 =
F_75 ( V_91 , struct V_10 , V_91 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_119 , V_117 = 0 , V_116 = 4 ;
if ( ! ( V_19 -> V_120 & V_121 ) )
return V_122 ;
if ( ! F_68 ( V_91 ) )
return V_123 ;
F_10 ( V_11 -> V_2 ) ;
V_124:
V_117 += F_78 ( V_11 , V_116 ) ;
V_119 = F_81 ( V_11 -> V_2 ) ;
F_85 ( V_125 , & V_91 -> V_126 ) ;
if ( F_18 ( F_83 ( V_11 -> V_2 , V_119 ) ) &&
F_68 ( V_91 ) ) {
F_10 ( V_11 -> V_2 ) ;
if ( V_117 < V_116 ) {
V_116 -= V_117 ;
goto V_124;
} else {
F_69 ( V_91 ) ;
}
}
return V_117 ;
}
static int F_86 ( struct V_42 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
if ( V_99 < V_19 -> V_113 )
if ( ! F_65 ( V_19 , & V_19 -> V_11 [ V_99 ] , V_114 ) )
F_77 ( & V_19 -> V_111 , 0 ) ;
F_70 ( & V_19 -> V_11 [ V_99 ] ) ;
}
return 0 ;
}
static void F_88 ( struct V_128 * V_129 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_129 -> V_2 -> V_20 -> V_21 ;
struct V_61 * V_44 = F_42 ( V_19 -> V_44 ) ;
while ( ( V_8 = F_35 ( V_129 -> V_2 , & V_29 ) ) != NULL ) {
F_36 ( L_10 , V_8 ) ;
F_43 ( & V_44 -> V_130 ) ;
V_44 -> V_131 += V_8 -> V_29 ;
V_44 -> V_132 ++ ;
F_44 ( & V_44 -> V_130 ) ;
F_89 ( V_8 ) ;
}
}
static int F_90 ( struct V_128 * V_129 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_133 = ( (struct V_134 * ) V_8 -> V_135 ) -> V_136 ;
struct V_18 * V_19 = V_129 -> V_2 -> V_20 -> V_21 ;
unsigned V_137 ;
unsigned V_32 = V_19 -> V_32 ;
bool V_138 ;
F_36 ( L_11 , V_19 -> V_22 -> V_39 , V_8 , V_133 ) ;
V_138 = V_19 -> V_139 &&
! ( ( unsigned long ) V_8 -> V_135 & ( F_91 ( * V_30 ) - 1 ) ) &&
! F_92 ( V_8 ) && F_93 ( V_8 ) >= V_32 ;
if ( V_138 )
V_30 = (struct V_6 * ) ( V_8 -> V_135 - V_32 ) ;
else
V_30 = F_5 ( V_8 ) ;
if ( V_8 -> V_74 == V_140 ) {
V_30 -> V_30 . V_68 = V_69 ;
V_30 -> V_30 . V_70 = F_94 ( V_19 -> V_20 ,
F_95 ( V_8 ) ) ;
V_30 -> V_30 . V_71 = F_94 ( V_19 -> V_20 ,
V_8 -> V_71 ) ;
} else {
V_30 -> V_30 . V_68 = 0 ;
V_30 -> V_30 . V_71 = V_30 -> V_30 . V_70 = 0 ;
}
if ( F_96 ( V_8 ) ) {
V_30 -> V_30 . V_32 = F_94 ( V_19 -> V_20 , F_97 ( V_8 ) ) ;
V_30 -> V_30 . V_88 = F_94 ( V_19 -> V_20 ,
F_27 ( V_8 ) -> V_88 ) ;
if ( F_27 ( V_8 ) -> V_78 & V_82 )
V_30 -> V_30 . V_78 = V_81 ;
else if ( F_27 ( V_8 ) -> V_78 & V_86 )
V_30 -> V_30 . V_78 = V_85 ;
else if ( F_27 ( V_8 ) -> V_78 & V_84 )
V_30 -> V_30 . V_78 = V_83 ;
else
F_98 () ;
if ( F_27 ( V_8 ) -> V_78 & V_87 )
V_30 -> V_30 . V_78 |= V_80 ;
} else {
V_30 -> V_30 . V_78 = V_79 ;
V_30 -> V_30 . V_88 = V_30 -> V_30 . V_32 = 0 ;
}
if ( V_19 -> V_35 )
V_30 -> V_48 = 0 ;
F_53 ( V_129 -> V_96 , V_37 + 2 ) ;
if ( V_138 ) {
F_99 ( V_8 , V_32 ) ;
V_137 = F_55 ( V_8 , V_129 -> V_96 , 0 , V_8 -> V_29 ) ;
F_100 ( V_8 , V_32 ) ;
} else {
F_54 ( V_129 -> V_96 , V_30 , V_32 ) ;
V_137 = F_55 ( V_8 , V_129 -> V_96 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_101 ( V_129 -> V_2 , V_129 -> V_96 , V_137 , V_8 , V_56 ) ;
}
static T_4 F_102 ( struct V_7 * V_8 , struct V_42 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_141 = F_103 ( V_8 ) ;
struct V_128 * V_129 = & V_19 -> V_129 [ V_141 ] ;
int V_43 ;
struct V_142 * V_4 = F_104 ( V_22 , V_141 ) ;
bool V_143 = ! V_8 -> V_144 ;
F_88 ( V_129 ) ;
F_105 ( V_8 ) ;
V_43 = F_90 ( V_129 , V_8 ) ;
if ( F_18 ( V_43 ) ) {
V_22 -> V_44 . V_145 ++ ;
if ( F_106 () )
F_107 ( & V_22 -> V_22 ,
L_12 , V_141 , V_43 ) ;
V_22 -> V_44 . V_146 ++ ;
F_89 ( V_8 ) ;
return V_147 ;
}
F_108 ( V_8 ) ;
F_109 ( V_8 ) ;
if ( V_129 -> V_2 -> V_107 < 2 + V_37 ) {
F_110 ( V_22 , V_141 ) ;
if ( F_18 ( ! F_111 ( V_129 -> V_2 ) ) ) {
F_88 ( V_129 ) ;
if ( V_129 -> V_2 -> V_107 >= 2 + V_37 ) {
F_112 ( V_22 , V_141 ) ;
F_10 ( V_129 -> V_2 ) ;
}
}
}
if ( V_143 || F_113 ( V_4 ) )
F_66 ( V_129 -> V_2 ) ;
return V_147 ;
}
static bool F_114 ( struct V_18 * V_19 , T_5 V_148 , T_5 V_149 ,
struct V_150 * V_151 )
{
struct V_150 * V_152 [ 4 ] , V_30 , V_153 ;
struct V_154 V_155 ;
T_6 V_120 = ~ 0 ;
unsigned V_156 = 0 , V_157 ;
F_25 ( ! F_115 ( V_19 -> V_20 , V_158 ) ) ;
V_155 . V_148 = V_148 ;
V_155 . V_149 = V_149 ;
F_64 ( & V_30 , & V_155 , sizeof( V_155 ) ) ;
V_152 [ V_156 ++ ] = & V_30 ;
if ( V_151 )
V_152 [ V_156 ++ ] = V_151 ;
F_64 ( & V_153 , & V_120 , sizeof( V_120 ) ) ;
V_152 [ V_156 ] = & V_153 ;
F_25 ( V_156 + 1 > F_116 ( V_152 ) ) ;
F_117 ( V_19 -> V_159 , V_152 , V_156 , 1 , V_19 , V_56 ) ;
if ( F_18 ( ! F_66 ( V_19 -> V_159 ) ) )
return V_120 == V_160 ;
while ( ! F_35 ( V_19 -> V_159 , & V_157 ) &&
! F_118 ( V_19 -> V_159 ) )
F_119 () ;
return V_120 == V_160 ;
}
static int F_120 ( struct V_42 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_161 * V_20 = V_19 -> V_20 ;
int V_162 ;
struct V_163 * V_164 = V_17 ;
struct V_150 V_96 ;
V_162 = F_121 ( V_22 , V_17 ) ;
if ( V_162 )
return V_162 ;
if ( F_115 ( V_20 , V_165 ) ) {
F_64 ( & V_96 , V_164 -> V_166 , V_22 -> V_167 ) ;
if ( ! F_114 ( V_19 , V_168 ,
V_169 , & V_96 ) ) {
F_107 ( & V_20 -> V_22 ,
L_13 ) ;
return - V_170 ;
}
} else if ( F_115 ( V_20 , V_171 ) &&
! F_115 ( V_20 , V_172 ) ) {
unsigned int V_99 ;
for ( V_99 = 0 ; V_99 < V_22 -> V_167 ; V_99 ++ )
F_122 ( V_20 ,
F_123 ( struct V_173 , V_174 ) +
V_99 , V_164 -> V_166 [ V_99 ] ) ;
}
F_124 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_175 * V_61 ( struct V_42 * V_22 ,
struct V_175 * V_176 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_177 ;
unsigned int V_178 ;
F_125 (cpu) {
struct V_61 * V_44 = F_126 ( V_19 -> V_44 , V_177 ) ;
T_7 V_179 , V_180 , V_181 , V_182 ;
do {
V_178 = F_127 ( & V_44 -> V_130 ) ;
V_179 = V_44 -> V_132 ;
V_180 = V_44 -> V_131 ;
} while ( F_128 ( & V_44 -> V_130 , V_178 ) );
do {
V_178 = F_127 ( & V_44 -> V_65 ) ;
V_181 = V_44 -> V_67 ;
V_182 = V_44 -> V_66 ;
} while ( F_128 ( & V_44 -> V_65 , V_178 ) );
V_176 -> V_67 += V_181 ;
V_176 -> V_132 += V_179 ;
V_176 -> V_66 += V_182 ;
V_176 -> V_131 += V_180 ;
}
V_176 -> V_146 = V_22 -> V_44 . V_146 ;
V_176 -> V_145 = V_22 -> V_44 . V_145 ;
V_176 -> V_45 = V_22 -> V_44 . V_45 ;
V_176 -> V_53 = V_22 -> V_44 . V_53 ;
V_176 -> V_92 = V_22 -> V_44 . V_92 ;
return V_176 ;
}
static void F_129 ( struct V_42 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ )
F_130 ( & V_19 -> V_11 [ V_99 ] . V_91 ) ;
}
static void F_131 ( struct V_18 * V_19 )
{
F_132 () ;
if ( ! F_114 ( V_19 , V_183 ,
V_184 , NULL ) )
F_107 ( & V_19 -> V_22 -> V_22 , L_14 ) ;
F_133 () ;
}
static int F_134 ( struct V_18 * V_19 , T_2 V_185 )
{
struct V_150 V_96 ;
struct V_186 V_187 ;
struct V_42 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_188 || ! F_115 ( V_19 -> V_20 , V_189 ) )
return 0 ;
V_187 . V_190 = F_94 ( V_19 -> V_20 , V_185 ) ;
F_64 ( & V_96 , & V_187 , sizeof( V_187 ) ) ;
if ( ! F_114 ( V_19 , V_191 ,
V_192 , & V_96 ) ) {
F_107 ( & V_22 -> V_22 , L_15 ,
V_185 ) ;
return - V_170 ;
} else {
V_19 -> V_113 = V_185 ;
if ( V_22 -> V_68 & V_193 )
F_77 ( & V_19 -> V_111 , 0 ) ;
}
return 0 ;
}
static int F_135 ( struct V_42 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
int V_99 ;
F_136 ( & V_19 -> V_111 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
F_76 ( & V_19 -> V_11 [ V_99 ] . V_91 ) ;
return 0 ;
}
static void F_137 ( struct V_42 * V_22 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_150 V_96 [ 2 ] ;
T_5 V_194 , V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
int V_200 ;
int V_201 ;
void * V_26 ;
int V_99 ;
if ( ! F_115 ( V_19 -> V_20 , V_202 ) )
return;
V_194 = ( ( V_22 -> V_68 & V_203 ) != 0 ) ;
V_195 = ( ( V_22 -> V_68 & V_204 ) != 0 ) ;
F_64 ( V_96 , & V_194 , sizeof( V_194 ) ) ;
if ( ! F_114 ( V_19 , V_205 ,
V_206 , V_96 ) )
F_107 ( & V_22 -> V_22 , L_16 ,
V_194 ? L_17 : L_18 ) ;
F_64 ( V_96 , & V_195 , sizeof( V_195 ) ) ;
if ( ! F_114 ( V_19 , V_205 ,
V_207 , V_96 ) )
F_107 ( & V_22 -> V_22 , L_19 ,
V_195 ? L_17 : L_18 ) ;
V_200 = F_138 ( V_22 ) ;
V_201 = F_139 ( V_22 ) ;
V_26 = F_140 ( ( ( V_200 + V_201 ) * V_208 ) +
( 2 * sizeof( V_197 -> V_209 ) ) , V_56 ) ;
V_197 = V_26 ;
if ( ! V_26 )
return;
F_53 ( V_96 , 2 ) ;
V_197 -> V_209 = F_141 ( V_19 -> V_20 , V_200 ) ;
V_99 = 0 ;
F_142 (ha, dev)
memcpy ( & V_197 -> V_210 [ V_99 ++ ] [ 0 ] , V_199 -> V_164 , V_208 ) ;
F_54 ( & V_96 [ 0 ] , V_197 ,
sizeof( V_197 -> V_209 ) + ( V_200 * V_208 ) ) ;
V_197 = ( void * ) & V_197 -> V_210 [ V_200 ] [ 0 ] ;
V_197 -> V_209 = F_141 ( V_19 -> V_20 , V_201 ) ;
V_99 = 0 ;
F_143 (ha, dev)
memcpy ( & V_197 -> V_210 [ V_99 ++ ] [ 0 ] , V_199 -> V_164 , V_208 ) ;
F_54 ( & V_96 [ 1 ] , V_197 ,
sizeof( V_197 -> V_209 ) + ( V_201 * V_208 ) ) ;
if ( ! F_114 ( V_19 , V_168 ,
V_211 , V_96 ) )
F_107 ( & V_22 -> V_22 , L_20 ) ;
F_144 ( V_26 ) ;
}
static int F_145 ( struct V_42 * V_22 ,
T_8 V_212 , T_2 V_213 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_150 V_96 ;
F_64 ( & V_96 , & V_213 , sizeof( V_213 ) ) ;
if ( ! F_114 ( V_19 , V_214 ,
V_215 , & V_96 ) )
F_107 ( & V_22 -> V_22 , L_21 , V_213 ) ;
return 0 ;
}
static int F_146 ( struct V_42 * V_22 ,
T_8 V_212 , T_2 V_213 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_150 V_96 ;
F_64 ( & V_96 , & V_213 , sizeof( V_213 ) ) ;
if ( ! F_114 ( V_19 , V_214 ,
V_216 , & V_96 ) )
F_107 ( & V_22 -> V_22 , L_22 , V_213 ) ;
return 0 ;
}
static void F_147 ( struct V_18 * V_19 , long V_217 )
{
int V_99 ;
if ( V_19 -> V_218 ) {
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
F_148 ( V_19 -> V_11 [ V_99 ] . V_2 , - 1 ) ;
F_148 ( V_19 -> V_129 [ V_99 ] . V_2 , - 1 ) ;
}
V_19 -> V_218 = false ;
}
}
static void F_149 ( struct V_18 * V_19 )
{
int V_99 ;
int V_177 ;
if ( V_19 -> V_113 == 1 ||
V_19 -> V_127 != F_150 () ) {
F_147 ( V_19 , - 1 ) ;
return;
}
V_99 = 0 ;
F_151 (cpu) {
F_148 ( V_19 -> V_11 [ V_99 ] . V_2 , V_177 ) ;
F_148 ( V_19 -> V_129 [ V_99 ] . V_2 , V_177 ) ;
F_152 ( V_19 -> V_22 , F_153 ( V_177 ) , V_99 ) ;
V_99 ++ ;
}
V_19 -> V_218 = true ;
}
static int F_154 ( struct V_219 * V_220 ,
unsigned long V_221 , void * V_217 )
{
struct V_18 * V_19 = F_75 ( V_220 , struct V_18 , V_222 ) ;
switch( V_221 & ~ V_223 ) {
case V_224 :
case V_225 :
case V_226 :
F_149 ( V_19 ) ;
break;
case V_227 :
F_147 ( V_19 , ( long ) V_217 ) ;
break;
default:
break;
}
return V_228 ;
}
static void F_155 ( struct V_42 * V_22 ,
struct V_229 * V_230 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
V_230 -> V_231 = F_79 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_230 -> V_232 = F_79 ( V_19 -> V_129 [ 0 ] . V_2 ) ;
V_230 -> V_233 = V_230 -> V_231 ;
V_230 -> V_234 = V_230 -> V_232 ;
}
static void F_156 ( struct V_42 * V_22 ,
struct V_235 * V_236 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
struct V_161 * V_20 = V_19 -> V_20 ;
F_157 ( V_236 -> V_237 , V_238 , sizeof( V_236 -> V_237 ) ) ;
F_157 ( V_236 -> V_239 , V_240 , sizeof( V_236 -> V_239 ) ) ;
F_157 ( V_236 -> V_241 , F_158 ( V_20 ) , sizeof( V_236 -> V_241 ) ) ;
}
static int F_159 ( struct V_42 * V_22 ,
struct V_242 * V_243 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
T_2 V_185 = V_243 -> V_244 ;
int V_43 ;
if ( V_243 -> V_245 || V_243 -> V_246 || V_243 -> V_247 )
return - V_170 ;
if ( V_185 > V_19 -> V_127 || V_185 == 0 )
return - V_170 ;
F_160 () ;
V_43 = F_134 ( V_19 , V_185 ) ;
if ( ! V_43 ) {
F_161 ( V_22 , V_185 ) ;
F_162 ( V_22 , V_185 ) ;
F_149 ( V_19 ) ;
}
F_163 () ;
return V_43 ;
}
static void F_164 ( struct V_42 * V_22 ,
struct V_242 * V_243 )
{
struct V_18 * V_19 = F_87 ( V_22 ) ;
V_243 -> V_244 = V_19 -> V_113 ;
V_243 -> V_248 = V_19 -> V_127 ;
V_243 -> V_249 = 0 ;
V_243 -> V_245 = 0 ;
V_243 -> V_246 = 0 ;
V_243 -> V_247 = 0 ;
}
static int F_165 ( struct V_42 * V_22 , int V_250 )
{
if ( V_250 < V_251 || V_250 > V_252 )
return - V_170 ;
V_22 -> V_253 = V_250 ;
return 0 ;
}
static void F_166 ( struct V_109 * V_110 )
{
struct V_18 * V_19 =
F_75 ( V_110 , struct V_18 , V_254 ) ;
T_2 V_255 ;
if ( F_167 ( V_19 -> V_20 , V_256 ,
struct V_173 , V_120 , & V_255 ) < 0 )
return;
if ( V_255 & V_257 ) {
F_168 ( V_19 -> V_22 ) ;
F_131 ( V_19 ) ;
}
V_255 &= V_121 ;
if ( V_19 -> V_120 == V_255 )
return;
V_19 -> V_120 = V_255 ;
if ( V_19 -> V_120 & V_121 ) {
F_169 ( V_19 -> V_22 ) ;
F_170 ( V_19 -> V_22 ) ;
} else {
F_171 ( V_19 -> V_22 ) ;
F_172 ( V_19 -> V_22 ) ;
}
}
static void F_173 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_174 ( & V_19 -> V_254 ) ;
}
static void F_175 ( struct V_18 * V_19 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
F_176 ( & V_19 -> V_11 [ V_99 ] . V_91 ) ;
F_177 ( & V_19 -> V_11 [ V_99 ] . V_91 ) ;
}
F_144 ( V_19 -> V_11 ) ;
F_144 ( V_19 -> V_129 ) ;
}
static void F_178 ( struct V_18 * V_19 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
while ( V_19 -> V_11 [ V_99 ] . V_15 )
F_179 ( F_7 ( & V_19 -> V_11 [ V_99 ] , V_114 ) , 0 ) ;
}
}
static void F_180 ( struct V_18 * V_19 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
if ( V_19 -> V_11 [ V_99 ] . V_103 . V_12 )
F_22 ( V_19 -> V_11 [ V_99 ] . V_103 . V_12 ) ;
}
static void F_181 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
struct V_1 * V_2 = V_19 -> V_129 [ V_99 ] . V_2 ;
while ( ( V_26 = F_182 ( V_2 ) ) != NULL )
F_24 ( V_26 ) ;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_99 ] . V_2 ;
while ( ( V_26 = F_182 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_35 ) {
unsigned long V_46 = ( unsigned long ) V_26 ;
void * V_63 = F_13 ( V_46 ) ;
F_22 ( F_33 ( V_63 ) ) ;
} else if ( V_19 -> V_64 ) {
F_6 ( & V_19 -> V_11 [ V_99 ] , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
}
}
}
static void F_183 ( struct V_18 * V_19 )
{
struct V_161 * V_20 = V_19 -> V_20 ;
F_147 ( V_19 , - 1 ) ;
V_20 -> V_258 -> V_259 ( V_20 ) ;
F_175 ( V_19 ) ;
}
static int F_184 ( struct V_18 * V_19 )
{
T_9 * * V_260 ;
struct V_1 * * V_261 ;
int V_162 = - V_95 ;
int V_99 , V_262 ;
const char * * V_263 ;
V_262 = V_19 -> V_127 * 2 +
F_115 ( V_19 -> V_20 , V_158 ) ;
V_261 = F_140 ( V_262 * sizeof( * V_261 ) , V_114 ) ;
if ( ! V_261 )
goto V_264;
V_260 = F_185 ( V_262 * sizeof( * V_260 ) , V_114 ) ;
if ( ! V_260 )
goto V_265;
V_263 = F_185 ( V_262 * sizeof( * V_263 ) , V_114 ) ;
if ( ! V_263 )
goto V_266;
if ( V_19 -> V_188 ) {
V_260 [ V_262 - 1 ] = NULL ;
V_263 [ V_262 - 1 ] = L_23 ;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
V_260 [ F_4 ( V_99 ) ] = F_67 ;
V_260 [ F_2 ( V_99 ) ] = F_9 ;
sprintf ( V_19 -> V_11 [ V_99 ] . V_39 , L_24 , V_99 ) ;
sprintf ( V_19 -> V_129 [ V_99 ] . V_39 , L_25 , V_99 ) ;
V_263 [ F_4 ( V_99 ) ] = V_19 -> V_11 [ V_99 ] . V_39 ;
V_263 [ F_2 ( V_99 ) ] = V_19 -> V_129 [ V_99 ] . V_39 ;
}
V_162 = V_19 -> V_20 -> V_258 -> V_267 ( V_19 -> V_20 , V_262 , V_261 , V_260 ,
V_263 ) ;
if ( V_162 )
goto V_268;
if ( V_19 -> V_188 ) {
V_19 -> V_159 = V_261 [ V_262 - 1 ] ;
if ( F_115 ( V_19 -> V_20 , V_269 ) )
V_19 -> V_22 -> V_270 |= V_271 ;
}
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
V_19 -> V_11 [ V_99 ] . V_2 = V_261 [ F_4 ( V_99 ) ] ;
V_19 -> V_129 [ V_99 ] . V_2 = V_261 [ F_2 ( V_99 ) ] ;
}
F_144 ( V_263 ) ;
F_144 ( V_260 ) ;
F_144 ( V_261 ) ;
return 0 ;
V_268:
F_144 ( V_263 ) ;
V_266:
F_144 ( V_260 ) ;
V_265:
F_144 ( V_261 ) ;
V_264:
return V_162 ;
}
static int F_186 ( struct V_18 * V_19 )
{
int V_99 ;
V_19 -> V_129 = F_140 ( sizeof( * V_19 -> V_129 ) * V_19 -> V_127 , V_114 ) ;
if ( ! V_19 -> V_129 )
goto V_272;
V_19 -> V_11 = F_140 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_127 , V_114 ) ;
if ( ! V_19 -> V_11 )
goto V_273;
F_187 ( & V_19 -> V_111 , F_74 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ ) {
V_19 -> V_11 [ V_99 ] . V_15 = NULL ;
F_188 ( V_19 -> V_22 , & V_19 -> V_11 [ V_99 ] . V_91 , F_80 ,
V_274 ) ;
F_189 ( & V_19 -> V_11 [ V_99 ] . V_91 ) ;
F_53 ( V_19 -> V_11 [ V_99 ] . V_96 , F_116 ( V_19 -> V_11 [ V_99 ] . V_96 ) ) ;
F_190 ( & V_19 -> V_11 [ V_99 ] . V_60 , 1 , V_275 ) ;
F_53 ( V_19 -> V_129 [ V_99 ] . V_96 , F_116 ( V_19 -> V_129 [ V_99 ] . V_96 ) ) ;
}
return 0 ;
V_273:
F_144 ( V_19 -> V_129 ) ;
V_272:
return - V_95 ;
}
static int F_191 ( struct V_18 * V_19 )
{
int V_162 ;
V_162 = F_186 ( V_19 ) ;
if ( V_162 )
goto V_43;
V_162 = F_184 ( V_19 ) ;
if ( V_162 )
goto V_276;
F_160 () ;
F_149 ( V_19 ) ;
F_163 () ;
return 0 ;
V_276:
F_175 ( V_19 ) ;
V_43:
return V_162 ;
}
static T_10 F_192 ( struct V_277 * V_278 ,
struct V_279 * V_280 , char * V_26 )
{
struct V_18 * V_19 = F_87 ( V_278 -> V_22 ) ;
unsigned int V_281 = F_193 ( V_278 ) ;
struct V_100 * V_282 ;
F_25 ( V_281 >= V_19 -> V_127 ) ;
V_282 = & V_19 -> V_11 [ V_281 ] . V_60 ;
return sprintf ( V_26 , L_26 , F_58 ( V_282 ) ) ;
}
static bool F_194 ( struct V_161 * V_20 ,
unsigned int V_283 ,
const char * V_284 , const char * V_285 )
{
if ( ! F_115 ( V_20 , V_283 ) )
return false ;
F_195 ( & V_20 -> V_22 , L_27 ,
V_284 , V_285 ) ;
return true ;
}
static bool F_196 ( struct V_161 * V_20 )
{
if ( ! F_115 ( V_20 , V_158 ) &&
( F_197 ( V_20 , V_202 ,
L_28 ) ||
F_197 ( V_20 , V_269 ,
L_28 ) ||
F_197 ( V_20 , V_286 ,
L_28 ) ||
F_197 ( V_20 , V_189 , L_28 ) ||
F_197 ( V_20 , V_165 ,
L_28 ) ) ) {
return false ;
}
return true ;
}
static int F_198 ( struct V_161 * V_20 )
{
int V_99 , V_43 ;
struct V_42 * V_22 ;
struct V_18 * V_19 ;
T_2 V_127 ;
if ( ! V_20 -> V_258 -> V_287 ) {
F_195 ( & V_20 -> V_22 , L_29 ,
V_288 ) ;
return - V_170 ;
}
if ( ! F_196 ( V_20 ) )
return - V_170 ;
V_43 = F_167 ( V_20 , V_189 ,
struct V_173 ,
V_289 , & V_127 ) ;
if ( V_43 || V_127 < V_290 ||
V_127 > V_291 ||
! F_115 ( V_20 , V_158 ) )
V_127 = 1 ;
V_22 = F_199 ( sizeof( struct V_18 ) , V_127 ) ;
if ( ! V_22 )
return - V_95 ;
V_22 -> V_292 |= V_293 | V_294 ;
V_22 -> V_295 = & V_296 ;
V_22 -> V_270 = V_297 ;
V_22 -> V_298 = & V_299 ;
F_200 ( V_22 , & V_20 -> V_22 ) ;
if ( F_115 ( V_20 , V_300 ) ) {
V_22 -> V_301 |= V_302 | V_303 | V_304 ;
if ( V_305 )
V_22 -> V_270 |= V_302 | V_303 | V_304 ;
if ( F_115 ( V_20 , V_306 ) ) {
V_22 -> V_301 |= V_307 | V_308
| V_309 | V_310 ;
}
if ( F_115 ( V_20 , V_311 ) )
V_22 -> V_301 |= V_307 ;
if ( F_115 ( V_20 , V_312 ) )
V_22 -> V_301 |= V_310 ;
if ( F_115 ( V_20 , V_313 ) )
V_22 -> V_301 |= V_309 ;
if ( F_115 ( V_20 , V_314 ) )
V_22 -> V_301 |= V_308 ;
V_22 -> V_270 |= V_315 ;
if ( V_316 )
V_22 -> V_270 |= V_22 -> V_301 & ( V_317 | V_308 ) ;
}
if ( F_115 ( V_20 , V_318 ) )
V_22 -> V_270 |= V_319 ;
V_22 -> V_320 = V_22 -> V_270 ;
if ( F_115 ( V_20 , V_171 ) )
F_201 ( V_20 ,
F_123 ( struct V_173 , V_174 ) ,
V_22 -> V_321 , V_22 -> V_167 ) ;
else
F_202 ( V_22 ) ;
V_19 = F_87 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_44 = F_203 ( struct V_61 ) ;
V_43 = - V_95 ;
if ( V_19 -> V_44 == NULL )
goto free;
F_125 (i) {
struct V_61 * V_61 ;
V_61 = F_126 ( V_19 -> V_44 , V_99 ) ;
F_204 ( & V_61 -> V_130 ) ;
F_204 ( & V_61 -> V_65 ) ;
}
F_205 ( & V_19 -> V_254 , F_166 ) ;
if ( F_115 ( V_20 , V_322 ) ||
F_115 ( V_20 , V_323 ) ||
F_115 ( V_20 , V_324 ) ||
F_115 ( V_20 , V_325 ) )
V_19 -> V_64 = true ;
if ( F_115 ( V_20 , V_326 ) )
V_19 -> V_35 = true ;
if ( F_115 ( V_20 , V_326 ) ||
F_115 ( V_20 , V_172 ) )
V_19 -> V_32 = sizeof( struct V_6 ) ;
else
V_19 -> V_32 = sizeof( struct V_327 ) ;
if ( F_115 ( V_20 , V_328 ) )
V_19 -> V_139 = true ;
if ( F_115 ( V_20 , V_158 ) )
V_19 -> V_188 = true ;
if ( V_19 -> V_139 )
V_22 -> V_329 = V_19 -> V_32 ;
V_19 -> V_113 = 1 ;
V_19 -> V_127 = V_127 ;
V_43 = F_191 ( V_19 ) ;
if ( V_43 )
goto V_330;
#ifdef F_206
if ( V_19 -> V_35 )
V_22 -> V_331 = & V_332 ;
#endif
F_161 ( V_22 , V_19 -> V_113 ) ;
F_162 ( V_22 , V_19 -> V_113 ) ;
V_43 = F_207 ( V_22 ) ;
if ( V_43 ) {
F_36 ( L_30 ) ;
goto V_333;
}
F_208 ( V_20 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ ) {
F_65 ( V_19 , & V_19 -> V_11 [ V_99 ] , V_114 ) ;
if ( V_19 -> V_11 [ V_99 ] . V_2 -> V_107 ==
F_79 ( V_19 -> V_11 [ V_99 ] . V_2 ) ) {
F_181 ( V_19 ) ;
V_43 = - V_95 ;
goto V_334;
}
}
V_19 -> V_222 . V_335 = & F_154 ;
V_43 = F_209 ( & V_19 -> V_222 ) ;
if ( V_43 ) {
F_36 ( L_31 ) ;
goto V_334;
}
if ( F_115 ( V_19 -> V_20 , V_256 ) ) {
F_171 ( V_22 ) ;
F_174 ( & V_19 -> V_254 ) ;
} else {
V_19 -> V_120 = V_121 ;
F_169 ( V_22 ) ;
}
F_36 ( L_32 ,
V_22 -> V_39 , V_127 ) ;
return 0 ;
V_334:
V_19 -> V_20 -> V_258 -> V_336 ( V_20 ) ;
F_178 ( V_19 ) ;
F_210 ( V_22 ) ;
V_333:
F_136 ( & V_19 -> V_111 ) ;
F_180 ( V_19 ) ;
F_183 ( V_19 ) ;
V_330:
F_211 ( V_19 -> V_44 ) ;
free:
F_212 ( V_22 ) ;
return V_43 ;
}
static void F_213 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_258 -> V_336 ( V_19 -> V_20 ) ;
F_181 ( V_19 ) ;
F_178 ( V_19 ) ;
F_180 ( V_19 ) ;
F_183 ( V_19 ) ;
}
static void F_214 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_215 ( & V_19 -> V_222 ) ;
F_216 ( & V_19 -> V_254 ) ;
F_210 ( V_19 -> V_22 ) ;
F_213 ( V_19 ) ;
F_211 ( V_19 -> V_44 ) ;
F_212 ( V_19 -> V_22 ) ;
}
static int F_217 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_99 ;
F_215 ( & V_19 -> V_222 ) ;
F_216 ( & V_19 -> V_254 ) ;
F_218 ( V_19 -> V_22 ) ;
F_136 ( & V_19 -> V_111 ) ;
if ( F_219 ( V_19 -> V_22 ) ) {
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
F_76 ( & V_19 -> V_11 [ V_99 ] . V_91 ) ;
}
F_213 ( V_19 ) ;
return 0 ;
}
static int F_220 ( struct V_161 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_43 , V_99 ;
V_43 = F_191 ( V_19 ) ;
if ( V_43 )
return V_43 ;
F_208 ( V_20 ) ;
if ( F_219 ( V_19 -> V_22 ) ) {
for ( V_99 = 0 ; V_99 < V_19 -> V_113 ; V_99 ++ )
if ( ! F_65 ( V_19 , & V_19 -> V_11 [ V_99 ] , V_114 ) )
F_77 ( & V_19 -> V_111 , 0 ) ;
for ( V_99 = 0 ; V_99 < V_19 -> V_127 ; V_99 ++ )
F_70 ( & V_19 -> V_11 [ V_99 ] ) ;
}
F_221 ( V_19 -> V_22 ) ;
F_132 () ;
F_134 ( V_19 , V_19 -> V_113 ) ;
F_133 () ;
V_43 = F_209 ( & V_19 -> V_222 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
