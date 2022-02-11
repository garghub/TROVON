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
static bool F_28 ( struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_43 * V_44 )
{
struct V_6 * V_30 ;
unsigned int V_29 ;
struct V_45 * V_46 ;
unsigned int V_47 ;
void * V_48 ;
int V_49 ;
V_47 = V_19 -> V_50 - V_19 -> V_51 + F_29 () ;
V_46 = & V_19 -> V_46 [ V_47 ] ;
while ( ( V_48 = F_30 ( V_46 -> V_2 , & V_29 ) ) != NULL ) {
struct V_12 * V_52 = F_31 ( V_48 ) ;
F_22 ( V_52 ) ;
}
V_44 -> V_53 -= V_19 -> V_32 ;
V_30 = V_44 -> V_53 ;
memset ( V_30 , 0 , V_19 -> V_32 ) ;
F_32 ( V_46 -> V_54 , V_44 -> V_53 , V_44 -> V_55 - V_44 -> V_53 ) ;
V_49 = F_33 ( V_46 -> V_2 , V_46 -> V_54 , 1 , V_44 -> V_53 , V_56 ) ;
if ( F_18 ( V_49 ) ) {
struct V_12 * V_12 = F_31 ( V_44 -> V_53 ) ;
F_22 ( V_12 ) ;
return false ;
}
F_34 ( V_46 -> V_2 ) ;
return true ;
}
static unsigned int F_35 ( struct V_18 * V_19 )
{
return V_19 -> V_51 ? V_57 : 0 ;
}
static struct V_7 * F_36 ( struct V_58 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
void * V_26 , unsigned int V_29 )
{
struct V_7 * V_8 ;
struct V_59 * V_60 ;
unsigned int V_61 = F_35 ( V_19 ) ;
unsigned int V_62 = V_63 + V_61 ;
unsigned int V_64 = V_19 -> V_32 + V_62 ;
unsigned int V_65 = F_37 ( V_66 + V_64 ) +
F_37 ( sizeof( struct V_67 ) ) ;
unsigned int V_68 = 0 ;
V_29 -= V_19 -> V_32 ;
F_38 () ;
V_60 = F_39 ( V_11 -> V_60 ) ;
if ( V_60 ) {
struct V_6 * V_30 = V_26 + V_62 ;
struct V_43 V_44 ;
void * V_69 ;
T_2 V_70 ;
if ( F_18 ( V_30 -> V_30 . V_71 || V_30 -> V_30 . V_72 ) )
goto V_73;
V_44 . V_74 = V_26 + V_63 + V_19 -> V_32 ;
V_44 . V_53 = V_44 . V_74 + V_61 ;
V_44 . V_55 = V_44 . V_53 + V_29 ;
V_69 = V_44 . V_53 ;
V_70 = F_40 ( V_60 , & V_44 ) ;
switch ( V_70 ) {
case V_75 :
V_68 = V_69 - V_44 . V_53 ;
break;
case V_76 :
if ( F_18 ( ! F_28 ( V_19 , V_11 , & V_44 ) ) )
F_41 ( V_19 -> V_22 , V_60 , V_70 ) ;
F_42 () ;
goto V_77;
default:
F_43 ( V_70 ) ;
case V_78 :
F_41 ( V_19 -> V_22 , V_60 , V_70 ) ;
case V_79 :
goto V_73;
}
}
F_42 () ;
V_8 = F_44 ( V_26 , V_65 ) ;
if ( ! V_8 ) {
F_22 ( F_31 ( V_26 ) ) ;
goto V_49;
}
F_45 ( V_8 , V_64 - V_68 ) ;
F_20 ( V_8 , V_29 + V_68 ) ;
if ( ! V_68 ) {
V_26 += V_62 ;
memcpy ( F_5 ( V_8 ) , V_26 , V_19 -> V_32 ) ;
}
V_49:
return V_8 ;
V_73:
F_42 () ;
V_22 -> V_80 . V_81 ++ ;
F_22 ( F_31 ( V_26 ) ) ;
V_77:
return NULL ;
}
static struct V_7 * F_46 ( struct V_58 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
void * V_26 ,
unsigned int V_29 )
{
struct V_12 * V_12 = V_26 ;
struct V_7 * V_8 = F_15 ( V_19 , V_11 , V_12 , 0 , V_29 , V_39 ) ;
if ( F_18 ( ! V_8 ) )
goto V_49;
return V_8 ;
V_49:
V_22 -> V_80 . V_81 ++ ;
F_6 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_12 * F_47 ( struct V_10 * V_11 ,
T_3 * V_82 ,
struct V_12 * V_17 ,
int V_28 ,
unsigned int * V_29 )
{
struct V_12 * V_12 = F_8 ( V_56 ) ;
unsigned int V_83 = V_57 ;
if ( ! V_12 )
return NULL ;
memcpy ( F_16 ( V_12 ) + V_83 , F_16 ( V_17 ) + V_28 , * V_29 ) ;
V_83 += * V_29 ;
while ( -- * V_82 ) {
unsigned int V_65 ;
unsigned long V_84 ;
void * V_26 ;
int V_85 ;
V_84 = ( unsigned long ) F_30 ( V_11 -> V_2 , & V_65 ) ;
if ( F_18 ( ! V_84 ) )
goto V_86;
V_26 = F_13 ( V_84 ) ;
V_17 = F_31 ( V_26 ) ;
V_85 = V_26 - F_16 ( V_17 ) ;
if ( ( V_83 + V_65 ) > V_39 ) {
F_22 ( V_17 ) ;
goto V_86;
}
memcpy ( F_16 ( V_12 ) + V_83 ,
F_16 ( V_17 ) + V_85 , V_65 ) ;
V_83 += V_65 ;
F_22 ( V_17 ) ;
}
* V_29 = V_83 - V_57 ;
return V_12 ;
V_86:
F_48 ( V_12 , 0 ) ;
return NULL ;
}
static struct V_7 * F_49 ( struct V_58 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
unsigned long V_84 ,
unsigned int V_29 )
{
void * V_26 = F_13 ( V_84 ) ;
struct V_6 * V_30 = V_26 ;
T_3 V_82 = F_50 ( V_19 -> V_20 , V_30 -> V_87 ) ;
struct V_12 * V_12 = F_31 ( V_26 ) ;
int V_28 = V_26 - F_16 ( V_12 ) ;
struct V_7 * V_88 , * V_89 ;
struct V_59 * V_60 ;
unsigned int V_24 ;
V_88 = NULL ;
F_38 () ;
V_60 = F_39 ( V_11 -> V_60 ) ;
if ( V_60 ) {
struct V_12 * V_90 ;
struct V_43 V_44 ;
void * V_53 ;
T_2 V_70 ;
if ( F_18 ( V_82 > 1 ) ) {
V_90 = F_47 ( V_11 , & V_82 ,
V_12 , V_28 , & V_29 ) ;
if ( ! V_90 )
goto V_73;
V_28 = V_57 ;
} else {
V_90 = V_12 ;
}
if ( F_18 ( V_30 -> V_30 . V_71 ) )
goto V_73;
V_53 = F_16 ( V_90 ) + V_28 ;
V_44 . V_74 = V_53 - V_57 + V_19 -> V_32 ;
V_44 . V_53 = V_53 + V_19 -> V_32 ;
V_44 . V_55 = V_44 . V_53 + ( V_29 - V_19 -> V_32 ) ;
V_70 = F_40 ( V_60 , & V_44 ) ;
switch ( V_70 ) {
case V_75 :
V_28 = V_44 . V_53 -
F_16 ( V_90 ) - V_19 -> V_32 ;
if ( F_18 ( V_90 != V_12 ) ) {
F_42 () ;
F_22 ( V_12 ) ;
V_88 = F_15 ( V_19 , V_11 , V_90 ,
V_28 , V_29 , V_39 ) ;
F_51 ( & V_11 -> V_91 , V_29 ) ;
return V_88 ;
}
break;
case V_76 :
if ( F_18 ( ! F_28 ( V_19 , V_11 , & V_44 ) ) )
F_41 ( V_19 -> V_22 , V_60 , V_70 ) ;
F_51 ( & V_11 -> V_91 , V_29 ) ;
if ( F_18 ( V_90 != V_12 ) )
goto V_73;
F_42 () ;
goto V_77;
default:
F_43 ( V_70 ) ;
case V_78 :
F_41 ( V_19 -> V_22 , V_60 , V_70 ) ;
case V_79 :
if ( F_18 ( V_90 != V_12 ) )
F_48 ( V_90 , 0 ) ;
F_51 ( & V_11 -> V_91 , V_29 ) ;
goto V_73;
}
}
F_42 () ;
V_24 = F_52 ( V_29 , F_12 ( V_84 ) ) ;
V_88 = F_15 ( V_19 , V_11 , V_12 , V_28 , V_29 , V_24 ) ;
V_89 = V_88 ;
if ( F_18 ( ! V_89 ) )
goto V_92;
while ( -- V_82 ) {
int V_93 ;
V_84 = ( unsigned long ) F_30 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_84 ) ) {
F_53 ( L_2 ,
V_22 -> V_40 , V_82 ,
F_50 ( V_19 -> V_20 ,
V_30 -> V_87 ) ) ;
V_22 -> V_80 . V_94 ++ ;
goto V_86;
}
V_26 = F_13 ( V_84 ) ;
V_12 = F_31 ( V_26 ) ;
V_93 = F_27 ( V_89 ) -> V_42 ;
if ( F_18 ( V_93 == V_38 ) ) {
struct V_7 * V_95 = F_54 ( 0 , V_56 ) ;
if ( F_18 ( ! V_95 ) )
goto V_92;
if ( V_89 == V_88 )
F_27 ( V_89 ) -> V_96 = V_95 ;
else
V_89 -> V_97 = V_95 ;
V_89 = V_95 ;
V_88 -> V_24 += V_95 -> V_24 ;
V_93 = 0 ;
}
V_24 = F_52 ( V_29 , F_12 ( V_84 ) ) ;
if ( V_89 != V_88 ) {
V_88 -> V_98 += V_29 ;
V_88 -> V_29 += V_29 ;
V_88 -> V_24 += V_24 ;
}
V_28 = V_26 - F_16 ( V_12 ) ;
if ( F_55 ( V_89 , V_93 , V_12 , V_28 ) ) {
F_22 ( V_12 ) ;
F_56 ( V_89 , V_93 - 1 ,
V_29 , V_24 ) ;
} else {
F_21 ( V_89 , V_93 , V_12 ,
V_28 , V_29 , V_24 ) ;
}
}
F_51 ( & V_11 -> V_91 , V_88 -> V_29 ) ;
return V_88 ;
V_73:
F_42 () ;
V_92:
F_22 ( V_12 ) ;
while ( -- V_82 ) {
V_84 = ( unsigned long ) F_30 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_84 ) ) {
F_53 ( L_3 ,
V_22 -> V_40 , V_82 ) ;
V_22 -> V_80 . V_94 ++ ;
break;
}
V_12 = F_31 ( F_13 ( V_84 ) ) ;
F_22 ( V_12 ) ;
}
V_86:
V_22 -> V_80 . V_81 ++ ;
F_24 ( V_88 ) ;
V_77:
return NULL ;
}
static int F_57 ( struct V_18 * V_19 , struct V_10 * V_11 ,
void * V_26 , unsigned int V_29 )
{
struct V_58 * V_22 = V_19 -> V_22 ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_99 ;
if ( F_18 ( V_29 < V_19 -> V_32 + V_100 ) ) {
F_53 ( L_4 , V_22 -> V_40 , V_29 ) ;
V_22 -> V_80 . V_94 ++ ;
if ( V_19 -> V_36 ) {
unsigned long V_84 = ( unsigned long ) V_26 ;
void * V_101 = F_13 ( V_84 ) ;
F_22 ( F_31 ( V_101 ) ) ;
} else if ( V_19 -> V_102 ) {
F_6 ( V_11 , V_26 ) ;
} else {
F_22 ( F_31 ( V_26 ) ) ;
}
return 0 ;
}
if ( V_19 -> V_36 )
V_8 = F_49 ( V_22 , V_19 , V_11 , ( unsigned long ) V_26 , V_29 ) ;
else if ( V_19 -> V_102 )
V_8 = F_46 ( V_22 , V_19 , V_11 , V_26 , V_29 ) ;
else
V_8 = F_36 ( V_22 , V_19 , V_11 , V_26 , V_29 ) ;
if ( F_18 ( ! V_8 ) )
return 0 ;
V_30 = F_5 ( V_8 ) ;
V_99 = V_8 -> V_29 ;
if ( V_30 -> V_30 . V_72 & V_103 )
V_8 -> V_104 = V_105 ;
if ( F_58 ( V_8 , & V_30 -> V_30 ,
F_59 ( V_19 -> V_20 ) ) ) {
F_60 ( L_5 ,
V_22 -> V_40 , V_30 -> V_30 . V_71 ,
V_30 -> V_30 . V_106 ) ;
goto V_107;
}
V_8 -> V_108 = F_61 ( V_8 , V_22 ) ;
F_53 ( L_6 ,
F_62 ( V_8 -> V_108 ) , V_8 -> V_29 , V_8 -> V_109 ) ;
F_63 ( & V_11 -> V_34 , V_8 ) ;
return V_99 ;
V_107:
V_22 -> V_80 . V_110 ++ ;
F_24 ( V_8 ) ;
return 0 ;
}
static int F_64 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_111 )
{
struct V_112 * V_113 = & V_11 -> V_113 ;
char * V_26 ;
unsigned int V_61 = F_35 ( V_19 ) ;
int V_29 = V_19 -> V_32 + V_63 + V_66 + V_61 ;
int V_49 ;
V_29 = F_37 ( V_29 ) +
F_37 ( sizeof( struct V_67 ) ) ;
if ( F_18 ( ! F_65 ( V_29 , V_113 , V_111 ) ) )
return - V_114 ;
V_26 = ( char * ) F_16 ( V_113 -> V_12 ) + V_113 -> V_28 ;
F_66 ( V_113 -> V_12 ) ;
V_113 -> V_28 += V_29 ;
F_32 ( V_11 -> V_54 , V_26 + V_63 + V_61 ,
V_19 -> V_32 + V_66 ) ;
V_49 = F_67 ( V_11 -> V_2 , V_11 -> V_54 , 1 , V_26 , V_111 ) ;
if ( V_49 < 0 )
F_22 ( F_31 ( V_26 ) ) ;
return V_49 ;
}
static int F_68 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_111 )
{
struct V_12 * V_115 , * V_116 = NULL ;
char * V_17 ;
int V_117 , V_49 , V_28 ;
F_69 ( V_11 -> V_54 , V_38 + 2 ) ;
for ( V_117 = V_38 + 1 ; V_117 > 1 ; -- V_117 ) {
V_115 = F_7 ( V_11 , V_111 ) ;
if ( ! V_115 ) {
if ( V_116 )
F_6 ( V_11 , V_116 ) ;
return - V_114 ;
}
F_70 ( & V_11 -> V_54 [ V_117 ] , F_16 ( V_115 ) , V_39 ) ;
V_115 -> V_14 = ( unsigned long ) V_116 ;
V_116 = V_115 ;
}
V_115 = F_7 ( V_11 , V_111 ) ;
if ( ! V_115 ) {
F_6 ( V_11 , V_116 ) ;
return - V_114 ;
}
V_17 = F_16 ( V_115 ) ;
F_70 ( & V_11 -> V_54 [ 0 ] , V_17 , V_19 -> V_32 ) ;
V_28 = sizeof( struct V_37 ) ;
F_70 ( & V_11 -> V_54 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_115 -> V_14 = ( unsigned long ) V_116 ;
V_49 = F_67 ( V_11 -> V_2 , V_11 -> V_54 , V_38 + 2 ,
V_115 , V_111 ) ;
if ( V_49 < 0 )
F_6 ( V_11 , V_115 ) ;
return V_49 ;
}
static unsigned int F_71 ( struct V_118 * V_119 )
{
const T_4 V_32 = sizeof( struct V_6 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_72 (unsigned int, ewma_pkt_len_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_73 ( V_29 , V_25 ) ;
}
static int F_74 ( struct V_18 * V_19 ,
struct V_10 * V_11 , T_1 V_111 )
{
struct V_112 * V_113 = & V_11 -> V_113 ;
unsigned int V_64 = F_35 ( V_19 ) ;
char * V_26 ;
unsigned long V_84 ;
int V_49 ;
unsigned int V_29 , V_120 ;
V_29 = F_71 ( & V_11 -> V_91 ) ;
if ( F_18 ( ! F_65 ( V_29 + V_64 , V_113 , V_111 ) ) )
return - V_114 ;
V_26 = ( char * ) F_16 ( V_113 -> V_12 ) + V_113 -> V_28 ;
V_26 += V_64 ;
V_84 = F_14 ( V_26 , V_29 ) ;
F_66 ( V_113 -> V_12 ) ;
V_113 -> V_28 += V_29 + V_64 ;
V_120 = V_113 -> V_27 - V_113 -> V_28 ;
if ( V_120 < V_29 + V_64 ) {
V_29 += V_120 ;
V_113 -> V_28 += V_120 ;
}
F_32 ( V_11 -> V_54 , V_26 , V_29 ) ;
V_49 = F_67 ( V_11 -> V_2 , V_11 -> V_54 , 1 , ( void * ) V_84 , V_111 ) ;
if ( V_49 < 0 )
F_22 ( F_31 ( V_26 ) ) ;
return V_49 ;
}
static bool F_75 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_111 )
{
int V_49 ;
bool V_121 ;
V_111 |= V_122 ;
do {
if ( V_19 -> V_36 )
V_49 = F_74 ( V_19 , V_11 , V_111 ) ;
else if ( V_19 -> V_102 )
V_49 = F_68 ( V_19 , V_11 , V_111 ) ;
else
V_49 = F_64 ( V_19 , V_11 , V_111 ) ;
V_121 = V_49 == - V_114 ;
if ( V_49 )
break;
} while ( V_11 -> V_2 -> V_123 );
F_34 ( V_11 -> V_2 ) ;
return ! V_121 ;
}
static void F_76 ( struct V_1 * V_124 )
{
struct V_18 * V_19 = V_124 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_124 ) ] ;
if ( F_77 ( & V_11 -> V_34 ) ) {
F_10 ( V_124 ) ;
F_78 ( & V_11 -> V_34 ) ;
}
}
static void F_79 ( struct V_10 * V_11 )
{
F_80 ( & V_11 -> V_34 ) ;
if ( F_77 ( & V_11 -> V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_81 () ;
F_78 ( & V_11 -> V_34 ) ;
F_82 () ;
}
}
static void F_83 ( struct V_125 * V_126 )
{
struct V_18 * V_19 =
F_84 ( V_126 , struct V_18 , V_127 . V_126 ) ;
bool V_128 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_50 ; V_117 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_117 ] ;
F_85 ( & V_11 -> V_34 ) ;
V_128 = ! F_75 ( V_19 , V_11 , V_129 ) ;
F_79 ( V_11 ) ;
if ( V_128 )
F_86 ( & V_19 -> V_127 , V_130 / 2 ) ;
}
}
static int F_87 ( struct V_10 * V_11 , int V_131 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_132 = 0 , V_133 = 0 ;
void * V_26 ;
struct V_134 * V_80 = F_88 ( V_19 -> V_80 ) ;
while ( V_132 < V_131 &&
( V_26 = F_30 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
V_133 += F_57 ( V_19 , V_11 , V_26 , V_29 ) ;
V_132 ++ ;
}
if ( V_11 -> V_2 -> V_123 > F_89 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_75 ( V_19 , V_11 , V_56 ) )
F_86 ( & V_19 -> V_127 , 0 ) ;
}
F_90 ( & V_80 -> V_135 ) ;
V_80 -> V_136 += V_133 ;
V_80 -> V_137 += V_132 ;
F_91 ( & V_80 -> V_135 ) ;
return V_132 ;
}
static int F_92 ( struct V_138 * V_34 , int V_131 )
{
struct V_10 * V_11 =
F_84 ( V_34 , struct V_10 , V_34 ) ;
unsigned int V_139 , V_132 ;
V_132 = F_87 ( V_11 , V_131 ) ;
if ( V_132 < V_131 ) {
V_139 = F_93 ( V_11 -> V_2 ) ;
if ( F_94 ( V_34 , V_132 ) ) {
if ( F_18 ( F_95 ( V_11 -> V_2 , V_139 ) ) &&
F_77 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_78 ( V_34 ) ;
}
}
}
return V_132 ;
}
static int F_96 ( struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
if ( V_117 < V_19 -> V_50 )
if ( ! F_75 ( V_19 , & V_19 -> V_11 [ V_117 ] , V_129 ) )
F_86 ( & V_19 -> V_127 , 0 ) ;
F_79 ( & V_19 -> V_11 [ V_117 ] ) ;
}
return 0 ;
}
static void F_98 ( struct V_45 * V_46 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_46 -> V_2 -> V_20 -> V_21 ;
struct V_134 * V_80 = F_88 ( V_19 -> V_80 ) ;
unsigned int V_141 = 0 ;
unsigned int V_133 = 0 ;
while ( ( V_8 = F_30 ( V_46 -> V_2 , & V_29 ) ) != NULL ) {
F_53 ( L_7 , V_8 ) ;
V_133 += V_8 -> V_29 ;
V_141 ++ ;
F_99 ( V_8 ) ;
}
if ( ! V_141 )
return;
F_90 ( & V_80 -> V_142 ) ;
V_80 -> V_143 += V_133 ;
V_80 -> V_144 += V_141 ;
F_91 ( & V_80 -> V_142 ) ;
}
static int F_100 ( struct V_45 * V_46 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_145 = ( (struct V_146 * ) V_8 -> V_53 ) -> V_147 ;
struct V_18 * V_19 = V_46 -> V_2 -> V_20 -> V_21 ;
unsigned V_148 ;
unsigned V_32 = V_19 -> V_32 ;
bool V_149 ;
F_53 ( L_8 , V_19 -> V_22 -> V_40 , V_8 , V_145 ) ;
V_149 = V_19 -> V_150 &&
! ( ( unsigned long ) V_8 -> V_53 & ( F_101 ( * V_30 ) - 1 ) ) &&
! F_102 ( V_8 ) && F_103 ( V_8 ) >= V_32 ;
if ( V_149 )
V_30 = (struct V_6 * ) ( V_8 -> V_53 - V_32 ) ;
else
V_30 = F_5 ( V_8 ) ;
if ( F_104 ( V_8 , & V_30 -> V_30 ,
F_59 ( V_19 -> V_20 ) , false ) )
F_105 () ;
if ( V_19 -> V_36 )
V_30 -> V_87 = 0 ;
F_69 ( V_46 -> V_54 , F_27 ( V_8 ) -> V_42 + ( V_149 ? 1 : 2 ) ) ;
if ( V_149 ) {
F_106 ( V_8 , V_32 ) ;
V_148 = F_107 ( V_8 , V_46 -> V_54 , 0 , V_8 -> V_29 ) ;
F_108 ( V_8 , V_32 ) ;
} else {
F_70 ( V_46 -> V_54 , V_30 , V_32 ) ;
V_148 = F_107 ( V_8 , V_46 -> V_54 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_33 ( V_46 -> V_2 , V_46 -> V_54 , V_148 , V_8 , V_56 ) ;
}
static T_5 F_109 ( struct V_7 * V_8 , struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
int V_151 = F_110 ( V_8 ) ;
struct V_45 * V_46 = & V_19 -> V_46 [ V_151 ] ;
int V_49 ;
struct V_152 * V_4 = F_111 ( V_22 , V_151 ) ;
bool V_153 = ! V_8 -> V_154 ;
F_98 ( V_46 ) ;
F_112 ( V_8 ) ;
V_49 = F_100 ( V_46 , V_8 ) ;
if ( F_18 ( V_49 ) ) {
V_22 -> V_80 . V_155 ++ ;
if ( F_113 () )
F_114 ( & V_22 -> V_22 ,
L_9 , V_151 , V_49 ) ;
V_22 -> V_80 . V_156 ++ ;
F_99 ( V_8 ) ;
return V_157 ;
}
F_115 ( V_8 ) ;
F_116 ( V_8 ) ;
if ( V_46 -> V_2 -> V_123 < 2 + V_38 ) {
F_117 ( V_22 , V_151 ) ;
if ( F_18 ( ! F_118 ( V_46 -> V_2 ) ) ) {
F_98 ( V_46 ) ;
if ( V_46 -> V_2 -> V_123 >= 2 + V_38 ) {
F_119 ( V_22 , V_151 ) ;
F_10 ( V_46 -> V_2 ) ;
}
}
}
if ( V_153 || F_120 ( V_4 ) )
F_34 ( V_46 -> V_2 ) ;
return V_157 ;
}
static bool F_121 ( struct V_18 * V_19 , T_6 V_158 , T_6 V_159 ,
struct V_160 * V_161 )
{
struct V_160 * V_162 [ 4 ] , V_30 , V_163 ;
unsigned V_164 = 0 , V_165 ;
F_25 ( ! F_122 ( V_19 -> V_20 , V_166 ) ) ;
V_19 -> V_167 = ~ 0 ;
V_19 -> V_168 . V_158 = V_158 ;
V_19 -> V_168 . V_159 = V_159 ;
F_32 ( & V_30 , & V_19 -> V_168 , sizeof( V_19 -> V_168 ) ) ;
V_162 [ V_164 ++ ] = & V_30 ;
if ( V_161 )
V_162 [ V_164 ++ ] = V_161 ;
F_32 ( & V_163 , & V_19 -> V_167 , sizeof( V_19 -> V_167 ) ) ;
V_162 [ V_164 ] = & V_163 ;
F_25 ( V_164 + 1 > F_123 ( V_162 ) ) ;
F_124 ( V_19 -> V_169 , V_162 , V_164 , 1 , V_19 , V_56 ) ;
if ( F_18 ( ! F_34 ( V_19 -> V_169 ) ) )
return V_19 -> V_167 == V_170 ;
while ( ! F_30 ( V_19 -> V_169 , & V_165 ) &&
! F_125 ( V_19 -> V_169 ) )
F_126 () ;
return V_19 -> V_167 == V_170 ;
}
static int F_127 ( struct V_58 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
struct V_171 * V_20 = V_19 -> V_20 ;
int V_99 ;
struct V_172 * V_173 ;
struct V_160 V_54 ;
V_173 = F_128 ( V_17 , sizeof( * V_173 ) , V_129 ) ;
if ( ! V_173 )
return - V_114 ;
V_99 = F_129 ( V_22 , V_173 ) ;
if ( V_99 )
goto V_161;
if ( F_122 ( V_20 , V_174 ) ) {
F_32 ( & V_54 , V_173 -> V_175 , V_22 -> V_176 ) ;
if ( ! F_121 ( V_19 , V_177 ,
V_178 , & V_54 ) ) {
F_114 ( & V_20 -> V_22 ,
L_10 ) ;
V_99 = - V_179 ;
goto V_161;
}
} else if ( F_122 ( V_20 , V_180 ) &&
! F_122 ( V_20 , V_181 ) ) {
unsigned int V_117 ;
for ( V_117 = 0 ; V_117 < V_22 -> V_176 ; V_117 ++ )
F_130 ( V_20 ,
F_131 ( struct V_182 , V_183 ) +
V_117 , V_173 -> V_175 [ V_117 ] ) ;
}
F_132 ( V_22 , V_17 ) ;
V_99 = 0 ;
V_161:
F_133 ( V_173 ) ;
return V_99 ;
}
static void V_134 ( struct V_58 * V_22 ,
struct V_184 * V_185 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
int V_186 ;
unsigned int V_187 ;
F_134 (cpu) {
struct V_134 * V_80 = F_135 ( V_19 -> V_80 , V_186 ) ;
T_7 V_188 , V_189 , V_190 , V_191 ;
do {
V_187 = F_136 ( & V_80 -> V_142 ) ;
V_188 = V_80 -> V_144 ;
V_189 = V_80 -> V_143 ;
} while ( F_137 ( & V_80 -> V_142 , V_187 ) );
do {
V_187 = F_136 ( & V_80 -> V_135 ) ;
V_190 = V_80 -> V_137 ;
V_191 = V_80 -> V_136 ;
} while ( F_137 ( & V_80 -> V_135 , V_187 ) );
V_185 -> V_137 += V_190 ;
V_185 -> V_144 += V_188 ;
V_185 -> V_136 += V_191 ;
V_185 -> V_143 += V_189 ;
}
V_185 -> V_156 = V_22 -> V_80 . V_156 ;
V_185 -> V_155 = V_22 -> V_80 . V_155 ;
V_185 -> V_81 = V_22 -> V_80 . V_81 ;
V_185 -> V_94 = V_22 -> V_80 . V_94 ;
V_185 -> V_110 = V_22 -> V_80 . V_110 ;
}
static void F_138 ( struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_50 ; V_117 ++ )
F_139 ( & V_19 -> V_11 [ V_117 ] . V_34 ) ;
}
static void F_140 ( struct V_18 * V_19 )
{
F_141 () ;
if ( ! F_121 ( V_19 , V_192 ,
V_193 , NULL ) )
F_114 ( & V_19 -> V_22 -> V_22 , L_11 ) ;
F_142 () ;
}
static int F_143 ( struct V_18 * V_19 , T_3 V_194 )
{
struct V_160 V_54 ;
struct V_58 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_195 || ! F_122 ( V_19 -> V_20 , V_196 ) )
return 0 ;
V_19 -> V_197 . V_198 = F_144 ( V_19 -> V_20 , V_194 ) ;
F_32 ( & V_54 , & V_19 -> V_197 , sizeof( V_19 -> V_197 ) ) ;
if ( ! F_121 ( V_19 , V_199 ,
V_200 , & V_54 ) ) {
F_114 ( & V_22 -> V_22 , L_12 ,
V_194 ) ;
return - V_179 ;
} else {
V_19 -> V_50 = V_194 ;
if ( V_22 -> V_72 & V_201 )
F_86 ( & V_19 -> V_127 , 0 ) ;
}
return 0 ;
}
static int F_145 ( struct V_18 * V_19 , T_3 V_194 )
{
int V_49 ;
F_141 () ;
V_49 = F_143 ( V_19 , V_194 ) ;
F_142 () ;
return V_49 ;
}
static int F_146 ( struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
int V_117 ;
F_147 ( & V_19 -> V_127 ) ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ )
F_85 ( & V_19 -> V_11 [ V_117 ] . V_34 ) ;
return 0 ;
}
static void F_148 ( struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
struct V_160 V_54 [ 2 ] ;
struct V_202 * V_203 ;
struct V_204 * V_205 ;
int V_206 ;
int V_207 ;
void * V_26 ;
int V_117 ;
if ( ! F_122 ( V_19 -> V_20 , V_208 ) )
return;
V_19 -> V_209 = ( ( V_22 -> V_72 & V_210 ) != 0 ) ;
V_19 -> V_211 = ( ( V_22 -> V_72 & V_212 ) != 0 ) ;
F_32 ( V_54 , & V_19 -> V_209 , sizeof( V_19 -> V_209 ) ) ;
if ( ! F_121 ( V_19 , V_213 ,
V_214 , V_54 ) )
F_114 ( & V_22 -> V_22 , L_13 ,
V_19 -> V_209 ? L_14 : L_15 ) ;
F_32 ( V_54 , & V_19 -> V_211 , sizeof( V_19 -> V_211 ) ) ;
if ( ! F_121 ( V_19 , V_213 ,
V_215 , V_54 ) )
F_114 ( & V_22 -> V_22 , L_16 ,
V_19 -> V_211 ? L_14 : L_15 ) ;
V_206 = F_149 ( V_22 ) ;
V_207 = F_150 ( V_22 ) ;
V_26 = F_151 ( ( ( V_206 + V_207 ) * V_216 ) +
( 2 * sizeof( V_203 -> V_217 ) ) , V_56 ) ;
V_203 = V_26 ;
if ( ! V_26 )
return;
F_69 ( V_54 , 2 ) ;
V_203 -> V_217 = F_152 ( V_19 -> V_20 , V_206 ) ;
V_117 = 0 ;
F_153 (ha, dev)
memcpy ( & V_203 -> V_218 [ V_117 ++ ] [ 0 ] , V_205 -> V_173 , V_216 ) ;
F_70 ( & V_54 [ 0 ] , V_203 ,
sizeof( V_203 -> V_217 ) + ( V_206 * V_216 ) ) ;
V_203 = ( void * ) & V_203 -> V_218 [ V_206 ] [ 0 ] ;
V_203 -> V_217 = F_152 ( V_19 -> V_20 , V_207 ) ;
V_117 = 0 ;
F_154 (ha, dev)
memcpy ( & V_203 -> V_218 [ V_117 ++ ] [ 0 ] , V_205 -> V_173 , V_216 ) ;
F_70 ( & V_54 [ 1 ] , V_203 ,
sizeof( V_203 -> V_217 ) + ( V_207 * V_216 ) ) ;
if ( ! F_121 ( V_19 , V_177 ,
V_219 , V_54 ) )
F_114 ( & V_22 -> V_22 , L_17 ) ;
F_133 ( V_26 ) ;
}
static int F_155 ( struct V_58 * V_22 ,
T_8 V_220 , T_3 V_221 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
struct V_160 V_54 ;
V_19 -> V_222 = V_221 ;
F_32 ( & V_54 , & V_19 -> V_222 , sizeof( V_19 -> V_222 ) ) ;
if ( ! F_121 ( V_19 , V_223 ,
V_224 , & V_54 ) )
F_114 ( & V_22 -> V_22 , L_18 , V_221 ) ;
return 0 ;
}
static int F_156 ( struct V_58 * V_22 ,
T_8 V_220 , T_3 V_221 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
struct V_160 V_54 ;
V_19 -> V_222 = V_221 ;
F_32 ( & V_54 , & V_19 -> V_222 , sizeof( V_19 -> V_222 ) ) ;
if ( ! F_121 ( V_19 , V_223 ,
V_225 , & V_54 ) )
F_114 ( & V_22 -> V_22 , L_19 , V_221 ) ;
return 0 ;
}
static void F_157 ( struct V_18 * V_19 , long V_226 )
{
int V_117 ;
if ( V_19 -> V_227 ) {
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
F_158 ( V_19 -> V_11 [ V_117 ] . V_2 , - 1 ) ;
F_158 ( V_19 -> V_46 [ V_117 ] . V_2 , - 1 ) ;
}
V_19 -> V_227 = false ;
}
}
static void F_159 ( struct V_18 * V_19 )
{
int V_117 ;
int V_186 ;
if ( V_19 -> V_50 == 1 ||
V_19 -> V_140 != F_160 () ) {
F_157 ( V_19 , - 1 ) ;
return;
}
V_117 = 0 ;
F_161 (cpu) {
F_158 ( V_19 -> V_11 [ V_117 ] . V_2 , V_186 ) ;
F_158 ( V_19 -> V_46 [ V_117 ] . V_2 , V_186 ) ;
F_162 ( V_19 -> V_22 , F_163 ( V_186 ) , V_117 ) ;
V_117 ++ ;
}
V_19 -> V_227 = true ;
}
static int F_164 ( unsigned int V_186 , struct V_228 * V_229 )
{
struct V_18 * V_19 = F_165 ( V_229 , struct V_18 ,
V_229 ) ;
F_159 ( V_19 ) ;
return 0 ;
}
static int F_166 ( unsigned int V_186 , struct V_228 * V_229 )
{
struct V_18 * V_19 = F_165 ( V_229 , struct V_18 ,
V_230 ) ;
F_159 ( V_19 ) ;
return 0 ;
}
static int F_167 ( unsigned int V_186 , struct V_228 * V_229 )
{
struct V_18 * V_19 = F_165 ( V_229 , struct V_18 ,
V_229 ) ;
F_157 ( V_19 , V_186 ) ;
return 0 ;
}
static int F_168 ( struct V_18 * V_19 )
{
int V_99 ;
V_99 = F_169 ( V_231 , & V_19 -> V_229 ) ;
if ( V_99 )
return V_99 ;
V_99 = F_169 ( V_232 ,
& V_19 -> V_230 ) ;
if ( ! V_99 )
return V_99 ;
F_170 ( V_231 , & V_19 -> V_229 ) ;
return V_99 ;
}
static void F_171 ( struct V_18 * V_19 )
{
F_170 ( V_231 , & V_19 -> V_229 ) ;
F_170 ( V_232 ,
& V_19 -> V_230 ) ;
}
static void F_172 ( struct V_58 * V_22 ,
struct V_233 * V_234 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
V_234 -> V_235 = F_89 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_234 -> V_236 = F_89 ( V_19 -> V_46 [ 0 ] . V_2 ) ;
V_234 -> V_237 = V_234 -> V_235 ;
V_234 -> V_238 = V_234 -> V_236 ;
}
static void F_173 ( struct V_58 * V_22 ,
struct V_239 * V_240 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
struct V_171 * V_20 = V_19 -> V_20 ;
F_174 ( V_240 -> V_241 , V_242 , sizeof( V_240 -> V_241 ) ) ;
F_174 ( V_240 -> V_243 , V_244 , sizeof( V_240 -> V_243 ) ) ;
F_174 ( V_240 -> V_245 , F_175 ( V_20 ) , sizeof( V_240 -> V_245 ) ) ;
}
static int F_176 ( struct V_58 * V_22 ,
struct V_246 * V_247 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
T_3 V_194 = V_247 -> V_248 ;
int V_49 ;
if ( V_247 -> V_249 || V_247 -> V_250 || V_247 -> V_251 )
return - V_179 ;
if ( V_194 > V_19 -> V_140 || V_194 == 0 )
return - V_179 ;
if ( V_19 -> V_11 [ 0 ] . V_60 )
return - V_179 ;
F_177 () ;
V_49 = F_143 ( V_19 , V_194 ) ;
if ( ! V_49 ) {
F_178 ( V_22 , V_194 ) ;
F_179 ( V_22 , V_194 ) ;
F_159 ( V_19 ) ;
}
F_180 () ;
return V_49 ;
}
static void F_181 ( struct V_58 * V_22 ,
struct V_246 * V_247 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
V_247 -> V_248 = V_19 -> V_50 ;
V_247 -> V_252 = V_19 -> V_140 ;
V_247 -> V_253 = 0 ;
V_247 -> V_249 = 0 ;
V_247 -> V_250 = 0 ;
V_247 -> V_251 = 0 ;
}
static bool F_182 ( const struct V_254 * V_159 )
{
struct V_254 V_255 = * V_159 ;
struct V_254 V_256 = {} ;
F_183 ( & V_255 , 0 ) ;
V_256 . V_257 = V_258 ;
V_255 . V_259 = 0 ;
V_255 . V_260 = 0 ;
V_255 . V_159 = 0 ;
return ! memcmp ( & V_255 , & V_256 , sizeof( V_255 ) ) ;
}
static int F_184 ( struct V_58 * V_22 , struct V_254 * V_159 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
T_2 V_261 ;
V_261 = F_185 ( V_159 ) ;
if ( ! F_186 ( V_261 ) ||
! F_187 ( V_159 -> V_260 ) ||
! F_182 ( V_159 ) )
return - V_179 ;
V_19 -> V_261 = V_261 ;
V_19 -> V_260 = V_159 -> V_260 ;
return 0 ;
}
static int F_188 ( struct V_58 * V_22 , struct V_254 * V_159 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
F_183 ( V_159 , V_19 -> V_261 ) ;
V_159 -> V_260 = V_19 -> V_260 ;
V_159 -> V_257 = V_258 ;
return 0 ;
}
static void F_189 ( struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
V_19 -> V_261 = V_262 ;
V_19 -> V_260 = V_263 ;
}
static void F_190 ( struct V_171 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_117 ;
F_191 ( & V_19 -> V_264 ) ;
F_192 ( V_19 -> V_22 ) ;
F_147 ( & V_19 -> V_127 ) ;
if ( F_193 ( V_19 -> V_22 ) ) {
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ )
F_85 ( & V_19 -> V_11 [ V_117 ] . V_34 ) ;
}
}
static int F_194 ( struct V_171 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_49 , V_117 ;
V_49 = F_195 ( V_19 ) ;
if ( V_49 )
return V_49 ;
F_196 ( V_20 ) ;
if ( F_193 ( V_19 -> V_22 ) ) {
for ( V_117 = 0 ; V_117 < V_19 -> V_50 ; V_117 ++ )
if ( ! F_75 ( V_19 , & V_19 -> V_11 [ V_117 ] , V_129 ) )
F_86 ( & V_19 -> V_127 , 0 ) ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ )
F_79 ( & V_19 -> V_11 [ V_117 ] ) ;
}
F_197 ( V_19 -> V_22 ) ;
return V_49 ;
}
static int F_198 ( struct V_18 * V_19 , int V_265 , int V_266 )
{
struct V_171 * V_22 = V_19 -> V_20 ;
int V_99 ;
F_199 ( V_22 ) ;
V_22 -> V_267 = V_22 -> V_268 -> V_269 ( V_22 ) & V_270 ;
F_190 ( V_22 ) ;
F_200 ( V_19 ) ;
V_22 -> V_268 -> V_271 ( V_22 ) ;
F_201 ( V_22 , V_272 ) ;
F_201 ( V_22 , V_273 ) ;
V_99 = F_202 ( V_22 ) ;
if ( V_99 )
goto V_49;
V_19 -> V_51 = V_266 ;
V_99 = F_194 ( V_22 ) ;
if ( V_99 )
goto V_49;
V_99 = F_143 ( V_19 , V_265 ) ;
if ( V_99 )
goto V_49;
F_201 ( V_22 , V_274 ) ;
F_203 ( V_22 ) ;
return 0 ;
V_49:
F_201 ( V_22 , V_270 ) ;
return V_99 ;
}
static int F_204 ( struct V_58 * V_22 , struct V_59 * V_275 )
{
unsigned long int V_276 = V_39 - sizeof( struct V_37 ) ;
struct V_18 * V_19 = F_97 ( V_22 ) ;
struct V_59 * V_277 ;
T_3 V_266 = 0 , V_265 ;
int V_117 , V_49 ;
if ( F_122 ( V_19 -> V_20 , V_278 ) ||
F_122 ( V_19 -> V_20 , V_279 ) ||
F_122 ( V_19 -> V_20 , V_280 ) ||
F_122 ( V_19 -> V_20 , V_281 ) ) {
F_205 ( V_22 , L_20 ) ;
return - V_282 ;
}
if ( V_19 -> V_36 && ! V_19 -> V_150 ) {
F_205 ( V_22 , L_21 ) ;
return - V_179 ;
}
if ( V_22 -> V_283 > V_276 ) {
F_205 ( V_22 , L_22 , V_276 ) ;
return - V_179 ;
}
V_265 = V_19 -> V_50 - V_19 -> V_51 ;
if ( V_275 )
V_266 = V_284 ;
if ( V_265 + V_266 > V_19 -> V_140 ) {
F_205 ( V_22 , L_23 ,
V_265 + V_266 , V_19 -> V_140 ) ;
return - V_114 ;
}
if ( V_275 ) {
V_275 = F_206 ( V_275 , V_19 -> V_140 - 1 ) ;
if ( F_207 ( V_275 ) )
return F_208 ( V_275 ) ;
}
if ( V_19 -> V_51 != V_266 ) {
V_49 = F_198 ( V_19 , V_265 + V_266 , V_266 ) ;
if ( V_49 ) {
F_114 ( & V_22 -> V_22 , L_24 ) ;
goto V_285;
}
}
F_179 ( V_22 , V_265 + V_266 ) ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
V_277 = F_209 ( V_19 -> V_11 [ V_117 ] . V_60 ) ;
F_210 ( V_19 -> V_11 [ V_117 ] . V_60 , V_275 ) ;
if ( V_277 )
F_211 ( V_277 ) ;
}
return 0 ;
V_285:
if ( V_275 )
F_212 ( V_275 , V_19 -> V_140 - 1 ) ;
return V_49 ;
}
static bool F_213 ( struct V_58 * V_22 )
{
struct V_18 * V_19 = F_97 ( V_22 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
if ( V_19 -> V_11 [ V_117 ] . V_60 )
return true ;
}
return false ;
}
static int F_214 ( struct V_58 * V_22 , struct V_286 * V_44 )
{
switch ( V_44 -> V_287 ) {
case V_288 :
return F_204 ( V_22 , V_44 -> V_275 ) ;
case V_289 :
V_44 -> V_290 = F_213 ( V_22 ) ;
return 0 ;
default:
return - V_179 ;
}
}
static void F_215 ( struct V_125 * V_126 )
{
struct V_18 * V_19 =
F_84 ( V_126 , struct V_18 , V_264 ) ;
T_3 V_291 ;
if ( F_216 ( V_19 -> V_20 , V_292 ,
struct V_182 , V_293 , & V_291 ) < 0 )
return;
if ( V_291 & V_294 ) {
F_217 ( V_19 -> V_22 ) ;
F_140 ( V_19 ) ;
}
V_291 &= V_295 ;
if ( V_19 -> V_293 == V_291 )
return;
V_19 -> V_293 = V_291 ;
if ( V_19 -> V_293 & V_295 ) {
F_218 ( V_19 -> V_22 ) ;
F_219 ( V_19 -> V_22 ) ;
} else {
F_220 ( V_19 -> V_22 ) ;
F_221 ( V_19 -> V_22 ) ;
}
}
static void F_222 ( struct V_171 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_223 ( & V_19 -> V_264 ) ;
}
static void F_224 ( struct V_18 * V_19 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
F_225 ( & V_19 -> V_11 [ V_117 ] . V_34 ) ;
F_226 ( & V_19 -> V_11 [ V_117 ] . V_34 ) ;
}
F_227 () ;
F_133 ( V_19 -> V_11 ) ;
F_133 ( V_19 -> V_46 ) ;
}
static void F_228 ( struct V_18 * V_19 )
{
struct V_59 * V_277 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
while ( V_19 -> V_11 [ V_117 ] . V_15 )
F_48 ( F_7 ( & V_19 -> V_11 [ V_117 ] , V_129 ) , 0 ) ;
V_277 = F_209 ( V_19 -> V_11 [ V_117 ] . V_60 ) ;
F_229 ( V_19 -> V_11 [ V_117 ] . V_60 , NULL ) ;
if ( V_277 )
F_211 ( V_277 ) ;
}
}
static void F_230 ( struct V_18 * V_19 )
{
F_141 () ;
F_228 ( V_19 ) ;
F_142 () ;
}
static void F_231 ( struct V_18 * V_19 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ )
if ( V_19 -> V_11 [ V_117 ] . V_113 . V_12 )
F_22 ( V_19 -> V_11 [ V_117 ] . V_113 . V_12 ) ;
}
static bool F_232 ( struct V_18 * V_19 , int V_296 )
{
if ( V_296 < ( V_19 -> V_50 - V_19 -> V_51 ) )
return false ;
else if ( V_296 < V_19 -> V_50 )
return true ;
else
return false ;
}
static void F_233 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
struct V_1 * V_2 = V_19 -> V_46 [ V_117 ] . V_2 ;
while ( ( V_26 = F_234 ( V_2 ) ) != NULL ) {
if ( ! F_232 ( V_19 , V_117 ) )
F_24 ( V_26 ) ;
else
F_22 ( F_31 ( V_26 ) ) ;
}
}
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_117 ] . V_2 ;
while ( ( V_26 = F_234 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_36 ) {
unsigned long V_84 = ( unsigned long ) V_26 ;
void * V_101 = F_13 ( V_84 ) ;
F_22 ( F_31 ( V_101 ) ) ;
} else if ( V_19 -> V_102 ) {
F_6 ( & V_19 -> V_11 [ V_117 ] , V_26 ) ;
} else {
F_22 ( F_31 ( V_26 ) ) ;
}
}
}
}
static void F_235 ( struct V_18 * V_19 )
{
struct V_171 * V_20 = V_19 -> V_20 ;
F_157 ( V_19 , - 1 ) ;
V_20 -> V_268 -> V_297 ( V_20 ) ;
F_224 ( V_19 ) ;
}
static int F_236 ( struct V_18 * V_19 )
{
T_9 * * V_298 ;
struct V_1 * * V_299 ;
int V_99 = - V_114 ;
int V_117 , V_300 ;
const char * * V_301 ;
V_300 = V_19 -> V_140 * 2 +
F_122 ( V_19 -> V_20 , V_166 ) ;
V_299 = F_151 ( V_300 * sizeof( * V_299 ) , V_129 ) ;
if ( ! V_299 )
goto V_302;
V_298 = F_237 ( V_300 * sizeof( * V_298 ) , V_129 ) ;
if ( ! V_298 )
goto V_303;
V_301 = F_237 ( V_300 * sizeof( * V_301 ) , V_129 ) ;
if ( ! V_301 )
goto V_304;
if ( V_19 -> V_195 ) {
V_298 [ V_300 - 1 ] = NULL ;
V_301 [ V_300 - 1 ] = L_25 ;
}
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
V_298 [ F_4 ( V_117 ) ] = F_76 ;
V_298 [ F_2 ( V_117 ) ] = F_9 ;
sprintf ( V_19 -> V_11 [ V_117 ] . V_40 , L_26 , V_117 ) ;
sprintf ( V_19 -> V_46 [ V_117 ] . V_40 , L_27 , V_117 ) ;
V_301 [ F_4 ( V_117 ) ] = V_19 -> V_11 [ V_117 ] . V_40 ;
V_301 [ F_2 ( V_117 ) ] = V_19 -> V_46 [ V_117 ] . V_40 ;
}
V_99 = V_19 -> V_20 -> V_268 -> V_305 ( V_19 -> V_20 , V_300 , V_299 , V_298 ,
V_301 , NULL ) ;
if ( V_99 )
goto V_306;
if ( V_19 -> V_195 ) {
V_19 -> V_169 = V_299 [ V_300 - 1 ] ;
if ( F_122 ( V_19 -> V_20 , V_307 ) )
V_19 -> V_22 -> V_308 |= V_309 ;
}
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
V_19 -> V_11 [ V_117 ] . V_2 = V_299 [ F_4 ( V_117 ) ] ;
V_19 -> V_46 [ V_117 ] . V_2 = V_299 [ F_2 ( V_117 ) ] ;
}
F_133 ( V_301 ) ;
F_133 ( V_298 ) ;
F_133 ( V_299 ) ;
return 0 ;
V_306:
F_133 ( V_301 ) ;
V_304:
F_133 ( V_298 ) ;
V_303:
F_133 ( V_299 ) ;
V_302:
return V_99 ;
}
static int F_238 ( struct V_18 * V_19 )
{
int V_117 ;
V_19 -> V_46 = F_151 ( sizeof( * V_19 -> V_46 ) * V_19 -> V_140 , V_129 ) ;
if ( ! V_19 -> V_46 )
goto V_310;
V_19 -> V_11 = F_151 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_140 , V_129 ) ;
if ( ! V_19 -> V_11 )
goto V_311;
F_239 ( & V_19 -> V_127 , F_83 ) ;
for ( V_117 = 0 ; V_117 < V_19 -> V_140 ; V_117 ++ ) {
V_19 -> V_11 [ V_117 ] . V_15 = NULL ;
F_240 ( V_19 -> V_22 , & V_19 -> V_11 [ V_117 ] . V_34 , F_92 ,
V_312 ) ;
F_69 ( V_19 -> V_11 [ V_117 ] . V_54 , F_123 ( V_19 -> V_11 [ V_117 ] . V_54 ) ) ;
F_241 ( & V_19 -> V_11 [ V_117 ] . V_91 ) ;
F_69 ( V_19 -> V_46 [ V_117 ] . V_54 , F_123 ( V_19 -> V_46 [ V_117 ] . V_54 ) ) ;
}
return 0 ;
V_311:
F_133 ( V_19 -> V_46 ) ;
V_310:
return - V_114 ;
}
static int F_195 ( struct V_18 * V_19 )
{
int V_99 ;
V_99 = F_238 ( V_19 ) ;
if ( V_99 )
goto V_49;
V_99 = F_236 ( V_19 ) ;
if ( V_99 )
goto V_313;
F_177 () ;
F_159 ( V_19 ) ;
F_180 () ;
return 0 ;
V_313:
F_224 ( V_19 ) ;
V_49:
return V_99 ;
}
static T_10 F_242 ( struct V_314 * V_315 ,
struct V_316 * V_317 , char * V_26 )
{
struct V_18 * V_19 = F_97 ( V_315 -> V_22 ) ;
unsigned int V_318 = F_243 ( V_315 ) ;
struct V_118 * V_319 ;
F_25 ( V_318 >= V_19 -> V_140 ) ;
V_319 = & V_19 -> V_11 [ V_318 ] . V_91 ;
return sprintf ( V_26 , L_28 , F_71 ( V_319 ) ) ;
}
static bool F_244 ( struct V_171 * V_20 ,
unsigned int V_320 ,
const char * V_321 , const char * V_322 )
{
if ( ! F_122 ( V_20 , V_320 ) )
return false ;
F_245 ( & V_20 -> V_22 , L_29 ,
V_321 , V_322 ) ;
return true ;
}
static bool F_246 ( struct V_171 * V_20 )
{
if ( ! F_122 ( V_20 , V_166 ) &&
( F_247 ( V_20 , V_208 ,
L_30 ) ||
F_247 ( V_20 , V_307 ,
L_30 ) ||
F_247 ( V_20 , V_323 ,
L_30 ) ||
F_247 ( V_20 , V_196 , L_30 ) ||
F_247 ( V_20 , V_174 ,
L_30 ) ) ) {
return false ;
}
return true ;
}
static int F_248 ( struct V_171 * V_20 )
{
if ( ! V_20 -> V_268 -> V_324 ) {
F_245 ( & V_20 -> V_22 , L_31 ,
V_325 ) ;
return - V_179 ;
}
if ( ! F_246 ( V_20 ) )
return - V_179 ;
if ( F_122 ( V_20 , V_326 ) ) {
int V_283 = F_249 ( V_20 ,
F_131 ( struct V_182 ,
V_283 ) ) ;
if ( V_283 < V_327 )
F_250 ( V_20 , V_326 ) ;
}
return 0 ;
}
static int F_251 ( struct V_171 * V_20 )
{
int V_117 , V_49 ;
struct V_58 * V_22 ;
struct V_18 * V_19 ;
T_3 V_140 ;
int V_283 ;
V_49 = F_216 ( V_20 , V_196 ,
struct V_182 ,
V_328 , & V_140 ) ;
if ( V_49 || V_140 < V_329 ||
V_140 > V_330 ||
! F_122 ( V_20 , V_166 ) )
V_140 = 1 ;
V_22 = F_252 ( sizeof( struct V_18 ) , V_140 ) ;
if ( ! V_22 )
return - V_114 ;
V_22 -> V_331 |= V_332 | V_333 ;
V_22 -> V_334 = & V_335 ;
V_22 -> V_308 = V_336 ;
V_22 -> V_337 = & V_338 ;
F_253 ( V_22 , & V_20 -> V_22 ) ;
if ( F_122 ( V_20 , V_339 ) ) {
V_22 -> V_340 |= V_341 | V_342 ;
if ( V_343 )
V_22 -> V_308 |= V_341 | V_342 ;
if ( F_122 ( V_20 , V_344 ) ) {
V_22 -> V_340 |= V_345 | V_346
| V_347 | V_348 ;
}
if ( F_122 ( V_20 , V_349 ) )
V_22 -> V_340 |= V_345 ;
if ( F_122 ( V_20 , V_350 ) )
V_22 -> V_340 |= V_348 ;
if ( F_122 ( V_20 , V_351 ) )
V_22 -> V_340 |= V_347 ;
if ( F_122 ( V_20 , V_352 ) )
V_22 -> V_340 |= V_346 ;
V_22 -> V_308 |= V_353 ;
if ( V_354 )
V_22 -> V_308 |= V_22 -> V_340 & ( V_355 | V_346 ) ;
}
if ( F_122 ( V_20 , V_356 ) )
V_22 -> V_308 |= V_357 ;
V_22 -> V_358 = V_22 -> V_308 ;
V_22 -> V_359 = V_327 ;
V_22 -> V_360 = V_361 ;
if ( F_122 ( V_20 , V_180 ) )
F_254 ( V_20 ,
F_131 ( struct V_182 , V_183 ) ,
V_22 -> V_362 , V_22 -> V_176 ) ;
else
F_255 ( V_22 ) ;
V_19 = F_97 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_80 = F_256 ( struct V_134 ) ;
V_49 = - V_114 ;
if ( V_19 -> V_80 == NULL )
goto free;
F_134 (i) {
struct V_134 * V_134 ;
V_134 = F_135 ( V_19 -> V_80 , V_117 ) ;
F_257 ( & V_134 -> V_142 ) ;
F_257 ( & V_134 -> V_135 ) ;
}
F_258 ( & V_19 -> V_264 , F_215 ) ;
if ( F_122 ( V_20 , V_278 ) ||
F_122 ( V_20 , V_279 ) ||
F_122 ( V_20 , V_280 ) ||
F_122 ( V_20 , V_281 ) )
V_19 -> V_102 = true ;
if ( F_122 ( V_20 , V_363 ) )
V_19 -> V_36 = true ;
if ( F_122 ( V_20 , V_363 ) ||
F_122 ( V_20 , V_181 ) )
V_19 -> V_32 = sizeof( struct V_6 ) ;
else
V_19 -> V_32 = sizeof( struct V_364 ) ;
if ( F_122 ( V_20 , V_365 ) ||
F_122 ( V_20 , V_181 ) )
V_19 -> V_150 = true ;
if ( F_122 ( V_20 , V_166 ) )
V_19 -> V_195 = true ;
if ( F_122 ( V_20 , V_326 ) ) {
V_283 = F_249 ( V_20 ,
F_131 ( struct V_182 ,
V_283 ) ) ;
if ( V_283 < V_22 -> V_359 ) {
F_245 ( & V_20 -> V_22 , L_32
L_33 , V_283 , V_22 -> V_359 ) ;
goto V_366;
}
V_22 -> V_283 = V_283 ;
V_22 -> V_360 = V_283 ;
if ( V_22 -> V_283 > V_367 )
V_19 -> V_102 = true ;
}
if ( V_19 -> V_150 )
V_22 -> V_368 = V_19 -> V_32 ;
if ( F_160 () >= V_140 )
V_19 -> V_50 = V_140 ;
else
V_19 -> V_50 = F_160 () ;
V_19 -> V_140 = V_140 ;
V_49 = F_195 ( V_19 ) ;
if ( V_49 )
goto V_366;
#ifdef F_259
if ( V_19 -> V_36 )
V_22 -> V_369 = & V_370 ;
#endif
F_178 ( V_22 , V_19 -> V_50 ) ;
F_179 ( V_22 , V_19 -> V_50 ) ;
F_189 ( V_22 ) ;
V_49 = F_260 ( V_22 ) ;
if ( V_49 ) {
F_53 ( L_34 ) ;
goto V_371;
}
F_196 ( V_20 ) ;
V_49 = F_168 ( V_19 ) ;
if ( V_49 ) {
F_53 ( L_35 ) ;
goto V_372;
}
F_145 ( V_19 , V_19 -> V_50 ) ;
if ( F_122 ( V_19 -> V_20 , V_292 ) ) {
F_220 ( V_22 ) ;
F_223 ( & V_19 -> V_264 ) ;
} else {
V_19 -> V_293 = V_295 ;
F_218 ( V_22 ) ;
}
F_53 ( L_36 ,
V_22 -> V_40 , V_140 ) ;
return 0 ;
V_372:
V_19 -> V_20 -> V_268 -> V_271 ( V_20 ) ;
F_261 ( V_22 ) ;
V_371:
F_147 ( & V_19 -> V_127 ) ;
F_231 ( V_19 ) ;
F_235 ( V_19 ) ;
V_366:
F_262 ( V_19 -> V_80 ) ;
free:
F_263 ( V_22 ) ;
return V_49 ;
}
static void F_200 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_268 -> V_271 ( V_19 -> V_20 ) ;
F_233 ( V_19 ) ;
F_228 ( V_19 ) ;
F_231 ( V_19 ) ;
F_235 ( V_19 ) ;
}
static void F_264 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_268 -> V_271 ( V_19 -> V_20 ) ;
F_233 ( V_19 ) ;
F_230 ( V_19 ) ;
F_231 ( V_19 ) ;
F_235 ( V_19 ) ;
}
static void F_265 ( struct V_171 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_171 ( V_19 ) ;
F_191 ( & V_19 -> V_264 ) ;
F_261 ( V_19 -> V_22 ) ;
F_264 ( V_19 ) ;
F_262 ( V_19 -> V_80 ) ;
F_263 ( V_19 -> V_22 ) ;
}
static int F_266 ( struct V_171 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_171 ( V_19 ) ;
F_190 ( V_20 ) ;
F_264 ( V_19 ) ;
return 0 ;
}
static int F_267 ( struct V_171 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_49 ;
V_49 = F_194 ( V_20 ) ;
if ( V_49 )
return V_49 ;
F_145 ( V_19 , V_19 -> V_50 ) ;
V_49 = F_168 ( V_19 ) ;
if ( V_49 )
return V_49 ;
return 0 ;
}
static T_11 int F_268 ( void )
{
int V_99 ;
V_99 = F_269 ( V_373 , L_37 ,
F_164 ,
F_167 ) ;
if ( V_99 < 0 )
goto V_161;
V_231 = V_99 ;
V_99 = F_269 ( V_232 , L_38 ,
NULL , F_166 ) ;
if ( V_99 )
goto V_374;
V_99 = F_270 ( & V_375 ) ;
if ( V_99 )
goto V_376;
return 0 ;
V_376:
F_271 ( V_232 ) ;
V_374:
F_271 ( V_231 ) ;
V_161:
return V_99 ;
}
static T_12 void F_272 ( void )
{
F_271 ( V_232 ) ;
F_271 ( V_231 ) ;
F_273 ( & V_375 ) ;
}
