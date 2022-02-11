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
static void F_9 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
if ( F_10 ( V_19 ) ) {
F_11 ( V_2 ) ;
F_12 ( V_19 ) ;
}
}
static void F_13 ( struct V_18 * V_19 ,
struct V_1 * V_2 , int V_20 )
{
int V_21 ;
V_21 = F_14 ( V_2 ) ;
if ( F_15 ( V_19 , V_20 ) &&
F_16 ( F_17 ( V_2 , V_21 ) ) )
F_9 ( V_19 , V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_24 -> V_25 ;
struct V_18 * V_19 = & V_23 -> V_26 [ F_1 ( V_2 ) ] . V_19 ;
F_11 ( V_2 ) ;
if ( V_19 -> V_27 )
F_9 ( V_19 , V_2 ) ;
else
F_19 ( V_23 -> V_28 , F_1 ( V_2 ) ) ;
}
static struct V_7 * F_20 ( struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_12 * V_12 , unsigned int V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_7 * V_8 ;
struct V_6 * V_32 ;
unsigned int V_33 , V_34 , V_35 ;
char * V_17 ;
V_17 = F_21 ( V_12 ) + V_29 ;
V_8 = F_22 ( & V_11 -> V_19 , V_36 ) ;
if ( F_16 ( ! V_8 ) )
return NULL ;
V_32 = F_5 ( V_8 ) ;
V_34 = V_23 -> V_34 ;
if ( V_23 -> V_37 )
V_35 = sizeof *V_32 ;
else
V_35 = sizeof( struct V_38 ) ;
memcpy ( V_32 , V_17 , V_34 ) ;
V_30 -= V_34 ;
V_29 += V_35 ;
V_17 += V_35 ;
V_33 = V_30 ;
if ( V_33 > F_23 ( V_8 ) )
V_33 = F_23 ( V_8 ) ;
memcpy ( F_24 ( V_8 , V_33 ) , V_17 , V_33 ) ;
V_30 -= V_33 ;
V_29 += V_33 ;
if ( V_23 -> V_37 ) {
if ( V_30 )
F_25 ( V_8 , 0 , V_12 , V_29 , V_30 , V_31 ) ;
else
F_26 ( V_12 ) ;
return V_8 ;
}
if ( F_16 ( V_30 > V_39 * V_40 ) ) {
F_27 ( L_1 , V_8 -> V_28 -> V_41 ) ;
F_28 ( V_8 ) ;
return NULL ;
}
F_29 ( V_29 >= V_40 ) ;
while ( V_30 ) {
unsigned int V_42 = F_30 ( ( unsigned ) V_40 - V_29 , V_30 ) ;
F_25 ( V_8 , F_31 ( V_8 ) -> V_43 , V_12 , V_29 ,
V_42 , V_31 ) ;
V_30 -= V_42 ;
V_12 = (struct V_12 * ) V_12 -> V_14 ;
V_29 = 0 ;
}
if ( V_12 )
F_6 ( V_11 , V_12 ) ;
return V_8 ;
}
static bool F_32 ( struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_44 * V_45 )
{
struct V_6 * V_32 ;
unsigned int V_30 ;
struct V_46 * V_26 ;
unsigned int V_47 ;
void * V_48 ;
int V_49 ;
V_47 = V_23 -> V_50 - V_23 -> V_51 + F_33 () ;
V_26 = & V_23 -> V_26 [ V_47 ] ;
while ( ( V_48 = F_34 ( V_26 -> V_2 , & V_30 ) ) != NULL ) {
struct V_12 * V_52 = F_35 ( V_48 ) ;
F_26 ( V_52 ) ;
}
V_45 -> V_53 -= V_23 -> V_34 ;
V_32 = V_45 -> V_53 ;
memset ( V_32 , 0 , V_23 -> V_34 ) ;
F_36 ( V_26 -> V_54 , V_45 -> V_53 , V_45 -> V_55 - V_45 -> V_53 ) ;
V_49 = F_37 ( V_26 -> V_2 , V_26 -> V_54 , 1 , V_45 -> V_53 , V_56 ) ;
if ( F_16 ( V_49 ) ) {
struct V_12 * V_12 = F_35 ( V_45 -> V_53 ) ;
F_26 ( V_12 ) ;
return false ;
}
F_38 ( V_26 -> V_2 ) ;
return true ;
}
static unsigned int F_39 ( struct V_22 * V_23 )
{
return V_23 -> V_51 ? V_57 : 0 ;
}
static struct V_7 * F_40 ( struct V_58 * V_28 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
void * V_59 , unsigned int V_30 )
{
struct V_7 * V_8 ;
struct V_60 * V_61 ;
unsigned int V_62 = F_39 ( V_23 ) ;
unsigned int V_63 = V_64 + V_62 ;
unsigned int V_65 = V_23 -> V_34 + V_63 ;
unsigned int V_66 = F_41 ( V_67 + V_65 ) +
F_41 ( sizeof( struct V_68 ) ) ;
unsigned int V_69 = 0 ;
V_30 -= V_23 -> V_34 ;
F_42 () ;
V_61 = F_43 ( V_11 -> V_61 ) ;
if ( V_61 ) {
struct V_6 * V_32 = V_59 + V_63 ;
struct V_44 V_45 ;
void * V_70 ;
T_2 V_71 ;
if ( F_16 ( V_32 -> V_32 . V_72 || V_32 -> V_32 . V_73 ) )
goto V_74;
V_45 . V_75 = V_59 + V_64 + V_23 -> V_34 ;
V_45 . V_53 = V_45 . V_75 + V_62 ;
V_45 . V_55 = V_45 . V_53 + V_30 ;
V_70 = V_45 . V_53 ;
V_71 = F_44 ( V_61 , & V_45 ) ;
switch ( V_71 ) {
case V_76 :
V_69 = V_70 - V_45 . V_53 ;
break;
case V_77 :
if ( F_16 ( ! F_32 ( V_23 , V_11 , & V_45 ) ) )
F_45 ( V_23 -> V_28 , V_61 , V_71 ) ;
F_46 () ;
goto V_78;
default:
F_47 ( V_71 ) ;
case V_79 :
F_45 ( V_23 -> V_28 , V_61 , V_71 ) ;
case V_80 :
goto V_74;
}
}
F_46 () ;
V_8 = F_48 ( V_59 , V_66 ) ;
if ( ! V_8 ) {
F_26 ( F_35 ( V_59 ) ) ;
goto V_49;
}
F_49 ( V_8 , V_65 - V_69 ) ;
F_24 ( V_8 , V_30 + V_69 ) ;
if ( ! V_69 ) {
V_59 += V_63 ;
memcpy ( F_5 ( V_8 ) , V_59 , V_23 -> V_34 ) ;
}
V_49:
return V_8 ;
V_74:
F_46 () ;
V_28 -> V_81 . V_82 ++ ;
F_26 ( F_35 ( V_59 ) ) ;
V_78:
return NULL ;
}
static struct V_7 * F_50 ( struct V_58 * V_28 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
void * V_59 ,
unsigned int V_30 )
{
struct V_12 * V_12 = V_59 ;
struct V_7 * V_8 = F_20 ( V_23 , V_11 , V_12 , 0 , V_30 , V_40 ) ;
if ( F_16 ( ! V_8 ) )
goto V_49;
return V_8 ;
V_49:
V_28 -> V_81 . V_82 ++ ;
F_6 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_12 * F_51 ( struct V_10 * V_11 ,
T_3 * V_83 ,
struct V_12 * V_17 ,
int V_29 ,
unsigned int * V_30 )
{
struct V_12 * V_12 = F_8 ( V_56 ) ;
unsigned int V_84 = V_57 ;
if ( ! V_12 )
return NULL ;
memcpy ( F_21 ( V_12 ) + V_84 , F_21 ( V_17 ) + V_29 , * V_30 ) ;
V_84 += * V_30 ;
while ( -- * V_83 ) {
unsigned int V_66 ;
void * V_59 ;
int V_85 ;
V_59 = F_34 ( V_11 -> V_2 , & V_66 ) ;
if ( F_16 ( ! V_59 ) )
goto V_86;
V_17 = F_35 ( V_59 ) ;
V_85 = V_59 - F_21 ( V_17 ) ;
if ( ( V_84 + V_66 ) > V_40 ) {
F_26 ( V_17 ) ;
goto V_86;
}
memcpy ( F_21 ( V_12 ) + V_84 ,
F_21 ( V_17 ) + V_85 , V_66 ) ;
V_84 += V_66 ;
F_26 ( V_17 ) ;
}
* V_30 = V_84 - V_57 ;
return V_12 ;
V_86:
F_52 ( V_12 , 0 ) ;
return NULL ;
}
static struct V_7 * F_53 ( struct V_58 * V_28 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
void * V_59 ,
void * V_87 ,
unsigned int V_30 )
{
struct V_6 * V_32 = V_59 ;
T_3 V_83 = F_54 ( V_23 -> V_24 , V_32 -> V_88 ) ;
struct V_12 * V_12 = F_35 ( V_59 ) ;
int V_29 = V_59 - F_21 ( V_12 ) ;
struct V_7 * V_89 , * V_90 ;
struct V_60 * V_61 ;
unsigned int V_31 ;
V_89 = NULL ;
F_42 () ;
V_61 = F_43 ( V_11 -> V_61 ) ;
if ( V_61 ) {
struct V_12 * V_91 ;
struct V_44 V_45 ;
void * V_53 ;
T_2 V_71 ;
if ( F_16 ( V_83 > 1 ) ) {
V_91 = F_51 ( V_11 , & V_83 ,
V_12 , V_29 , & V_30 ) ;
if ( ! V_91 )
goto V_74;
V_29 = V_57 ;
} else {
V_91 = V_12 ;
}
if ( F_16 ( V_32 -> V_32 . V_72 ) )
goto V_74;
V_53 = F_21 ( V_91 ) + V_29 ;
V_45 . V_75 = V_53 - V_57 + V_23 -> V_34 ;
V_45 . V_53 = V_53 + V_23 -> V_34 ;
V_45 . V_55 = V_45 . V_53 + ( V_30 - V_23 -> V_34 ) ;
V_71 = F_44 ( V_61 , & V_45 ) ;
switch ( V_71 ) {
case V_76 :
V_29 = V_45 . V_53 -
F_21 ( V_91 ) - V_23 -> V_34 ;
if ( F_16 ( V_91 != V_12 ) ) {
F_46 () ;
F_26 ( V_12 ) ;
V_89 = F_20 ( V_23 , V_11 , V_91 ,
V_29 , V_30 , V_40 ) ;
F_55 ( & V_11 -> V_92 , V_30 ) ;
return V_89 ;
}
break;
case V_77 :
if ( F_16 ( ! F_32 ( V_23 , V_11 , & V_45 ) ) )
F_45 ( V_23 -> V_28 , V_61 , V_71 ) ;
F_55 ( & V_11 -> V_92 , V_30 ) ;
if ( F_16 ( V_91 != V_12 ) )
goto V_74;
F_46 () ;
goto V_78;
default:
F_47 ( V_71 ) ;
case V_79 :
F_45 ( V_23 -> V_28 , V_61 , V_71 ) ;
case V_80 :
if ( F_16 ( V_91 != V_12 ) )
F_52 ( V_91 , 0 ) ;
F_55 ( & V_11 -> V_92 , V_30 ) ;
goto V_74;
}
}
F_46 () ;
if ( F_16 ( V_30 > ( unsigned long ) V_87 ) ) {
F_56 ( L_2 ,
V_28 -> V_41 , V_30 , ( unsigned long ) V_87 ) ;
V_28 -> V_81 . V_93 ++ ;
goto V_94;
}
V_31 = ( unsigned long ) V_87 ;
V_89 = F_20 ( V_23 , V_11 , V_12 , V_29 , V_30 , V_31 ) ;
V_90 = V_89 ;
if ( F_16 ( ! V_90 ) )
goto V_94;
while ( -- V_83 ) {
int V_95 ;
V_59 = F_57 ( V_11 -> V_2 , & V_30 , & V_87 ) ;
if ( F_16 ( ! V_87 ) ) {
F_56 ( L_3 ,
V_28 -> V_41 , V_83 ,
F_54 ( V_23 -> V_24 ,
V_32 -> V_88 ) ) ;
V_28 -> V_81 . V_93 ++ ;
goto V_86;
}
V_12 = F_35 ( V_59 ) ;
if ( F_16 ( V_30 > ( unsigned long ) V_87 ) ) {
F_56 ( L_2 ,
V_28 -> V_41 , V_30 , ( unsigned long ) V_87 ) ;
V_28 -> V_81 . V_93 ++ ;
goto V_94;
}
V_31 = ( unsigned long ) V_87 ;
V_95 = F_31 ( V_90 ) -> V_43 ;
if ( F_16 ( V_95 == V_39 ) ) {
struct V_7 * V_96 = F_58 ( 0 , V_56 ) ;
if ( F_16 ( ! V_96 ) )
goto V_94;
if ( V_90 == V_89 )
F_31 ( V_90 ) -> V_97 = V_96 ;
else
V_90 -> V_98 = V_96 ;
V_90 = V_96 ;
V_89 -> V_31 += V_96 -> V_31 ;
V_95 = 0 ;
}
if ( V_90 != V_89 ) {
V_89 -> V_99 += V_30 ;
V_89 -> V_30 += V_30 ;
V_89 -> V_31 += V_31 ;
}
V_29 = V_59 - F_21 ( V_12 ) ;
if ( F_59 ( V_90 , V_95 , V_12 , V_29 ) ) {
F_26 ( V_12 ) ;
F_60 ( V_90 , V_95 - 1 ,
V_30 , V_31 ) ;
} else {
F_25 ( V_90 , V_95 , V_12 ,
V_29 , V_30 , V_31 ) ;
}
}
F_55 ( & V_11 -> V_92 , V_89 -> V_30 ) ;
return V_89 ;
V_74:
F_46 () ;
V_94:
F_26 ( V_12 ) ;
while ( -- V_83 ) {
V_59 = F_34 ( V_11 -> V_2 , & V_30 ) ;
if ( F_16 ( ! V_59 ) ) {
F_56 ( L_4 ,
V_28 -> V_41 , V_83 ) ;
V_28 -> V_81 . V_93 ++ ;
break;
}
V_12 = F_35 ( V_59 ) ;
F_26 ( V_12 ) ;
}
V_86:
V_28 -> V_81 . V_82 ++ ;
F_28 ( V_89 ) ;
V_78:
return NULL ;
}
static int F_61 ( struct V_22 * V_23 , struct V_10 * V_11 ,
void * V_59 , unsigned int V_30 , void * * V_87 )
{
struct V_58 * V_28 = V_23 -> V_28 ;
struct V_7 * V_8 ;
struct V_6 * V_32 ;
int V_100 ;
if ( F_16 ( V_30 < V_23 -> V_34 + V_101 ) ) {
F_56 ( L_5 , V_28 -> V_41 , V_30 ) ;
V_28 -> V_81 . V_93 ++ ;
if ( V_23 -> V_37 ) {
F_26 ( F_35 ( V_59 ) ) ;
} else if ( V_23 -> V_102 ) {
F_6 ( V_11 , V_59 ) ;
} else {
F_26 ( F_35 ( V_59 ) ) ;
}
return 0 ;
}
if ( V_23 -> V_37 )
V_8 = F_53 ( V_28 , V_23 , V_11 , V_59 , V_87 , V_30 ) ;
else if ( V_23 -> V_102 )
V_8 = F_50 ( V_28 , V_23 , V_11 , V_59 , V_30 ) ;
else
V_8 = F_40 ( V_28 , V_23 , V_11 , V_59 , V_30 ) ;
if ( F_16 ( ! V_8 ) )
return 0 ;
V_32 = F_5 ( V_8 ) ;
V_100 = V_8 -> V_30 ;
if ( V_32 -> V_32 . V_73 & V_103 )
V_8 -> V_104 = V_105 ;
if ( F_62 ( V_8 , & V_32 -> V_32 ,
F_63 ( V_23 -> V_24 ) ) ) {
F_64 ( L_6 ,
V_28 -> V_41 , V_32 -> V_32 . V_72 ,
V_32 -> V_32 . V_106 ) ;
goto V_107;
}
V_8 -> V_108 = F_65 ( V_8 , V_28 ) ;
F_56 ( L_7 ,
F_66 ( V_8 -> V_108 ) , V_8 -> V_30 , V_8 -> V_109 ) ;
F_67 ( & V_11 -> V_19 , V_8 ) ;
return V_100 ;
V_107:
V_28 -> V_81 . V_110 ++ ;
F_28 ( V_8 ) ;
return 0 ;
}
static int F_68 ( struct V_22 * V_23 , struct V_10 * V_11 ,
T_1 V_111 )
{
struct V_112 * V_113 = & V_11 -> V_113 ;
char * V_59 ;
unsigned int V_62 = F_39 ( V_23 ) ;
int V_30 = V_23 -> V_34 + V_64 + V_67 + V_62 ;
int V_49 ;
V_30 = F_41 ( V_30 ) +
F_41 ( sizeof( struct V_68 ) ) ;
if ( F_16 ( ! F_69 ( V_30 , V_113 , V_111 ) ) )
return - V_114 ;
V_59 = ( char * ) F_21 ( V_113 -> V_12 ) + V_113 -> V_29 ;
F_70 ( V_113 -> V_12 ) ;
V_113 -> V_29 += V_30 ;
F_36 ( V_11 -> V_54 , V_59 + V_64 + V_62 ,
V_23 -> V_34 + V_67 ) ;
V_49 = F_71 ( V_11 -> V_2 , V_11 -> V_54 , 1 , V_59 , V_111 ) ;
if ( V_49 < 0 )
F_26 ( F_35 ( V_59 ) ) ;
return V_49 ;
}
static int F_72 ( struct V_22 * V_23 , struct V_10 * V_11 ,
T_1 V_111 )
{
struct V_12 * V_115 , * V_116 = NULL ;
char * V_17 ;
int V_117 , V_49 , V_29 ;
F_73 ( V_11 -> V_54 , V_39 + 2 ) ;
for ( V_117 = V_39 + 1 ; V_117 > 1 ; -- V_117 ) {
V_115 = F_7 ( V_11 , V_111 ) ;
if ( ! V_115 ) {
if ( V_116 )
F_6 ( V_11 , V_116 ) ;
return - V_114 ;
}
F_74 ( & V_11 -> V_54 [ V_117 ] , F_21 ( V_115 ) , V_40 ) ;
V_115 -> V_14 = ( unsigned long ) V_116 ;
V_116 = V_115 ;
}
V_115 = F_7 ( V_11 , V_111 ) ;
if ( ! V_115 ) {
F_6 ( V_11 , V_116 ) ;
return - V_114 ;
}
V_17 = F_21 ( V_115 ) ;
F_74 ( & V_11 -> V_54 [ 0 ] , V_17 , V_23 -> V_34 ) ;
V_29 = sizeof( struct V_38 ) ;
F_74 ( & V_11 -> V_54 [ 1 ] , V_17 + V_29 , V_40 - V_29 ) ;
V_115 -> V_14 = ( unsigned long ) V_116 ;
V_49 = F_71 ( V_11 -> V_2 , V_11 -> V_54 , V_39 + 2 ,
V_115 , V_111 ) ;
if ( V_49 < 0 )
F_6 ( V_11 , V_115 ) ;
return V_49 ;
}
static unsigned int F_75 ( struct V_10 * V_11 ,
struct V_118 * V_119 )
{
const T_4 V_34 = sizeof( struct V_6 ) ;
unsigned int V_30 ;
V_30 = V_34 + F_76 (unsigned int, ewma_pkt_len_read(avg_pkt_len),
rq->min_buf_len, PAGE_SIZE - hdr_len) ;
return F_77 ( V_30 , V_120 ) ;
}
static int F_78 ( struct V_22 * V_23 ,
struct V_10 * V_11 , T_1 V_111 )
{
struct V_112 * V_113 = & V_11 -> V_113 ;
unsigned int V_65 = F_39 ( V_23 ) ;
char * V_59 ;
void * V_87 ;
int V_49 ;
unsigned int V_30 , V_121 ;
V_30 = F_75 ( V_11 , & V_11 -> V_92 ) ;
if ( F_16 ( ! F_69 ( V_30 + V_65 , V_113 , V_111 ) ) )
return - V_114 ;
V_59 = ( char * ) F_21 ( V_113 -> V_12 ) + V_113 -> V_29 ;
V_59 += V_65 ;
V_87 = ( void * ) ( unsigned long ) V_30 ;
F_70 ( V_113 -> V_12 ) ;
V_113 -> V_29 += V_30 + V_65 ;
V_121 = V_113 -> V_122 - V_113 -> V_29 ;
if ( V_121 < V_30 + V_65 ) {
V_30 += V_121 ;
V_113 -> V_29 += V_121 ;
}
F_36 ( V_11 -> V_54 , V_59 , V_30 ) ;
V_49 = F_79 ( V_11 -> V_2 , V_11 -> V_54 , 1 , V_59 , V_87 , V_111 ) ;
if ( V_49 < 0 )
F_26 ( F_35 ( V_59 ) ) ;
return V_49 ;
}
static bool F_80 ( struct V_22 * V_23 , struct V_10 * V_11 ,
T_1 V_111 )
{
int V_49 ;
bool V_123 ;
V_111 |= V_124 ;
do {
if ( V_23 -> V_37 )
V_49 = F_78 ( V_23 , V_11 , V_111 ) ;
else if ( V_23 -> V_102 )
V_49 = F_72 ( V_23 , V_11 , V_111 ) ;
else
V_49 = F_68 ( V_23 , V_11 , V_111 ) ;
V_123 = V_49 == - V_114 ;
if ( V_49 )
break;
} while ( V_11 -> V_2 -> V_125 );
F_38 ( V_11 -> V_2 ) ;
return ! V_123 ;
}
static void F_81 ( struct V_1 * V_126 )
{
struct V_22 * V_23 = V_126 -> V_24 -> V_25 ;
struct V_10 * V_11 = & V_23 -> V_11 [ F_3 ( V_126 ) ] ;
F_9 ( & V_11 -> V_19 , V_126 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
F_83 ( V_19 ) ;
F_84 () ;
F_9 ( V_19 , V_2 ) ;
F_85 () ;
}
static void F_86 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_18 * V_19 )
{
if ( ! V_19 -> V_27 )
return;
if ( ! V_23 -> V_127 ) {
V_19 -> V_27 = 0 ;
return;
}
return F_82 ( V_2 , V_19 ) ;
}
static void F_87 ( struct V_18 * V_19 )
{
if ( V_19 -> V_27 )
F_88 ( V_19 ) ;
}
static void F_89 ( struct V_128 * V_129 )
{
struct V_22 * V_23 =
F_90 ( V_129 , struct V_22 , V_130 . V_129 ) ;
bool V_131 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_50 ; V_117 ++ ) {
struct V_10 * V_11 = & V_23 -> V_11 [ V_117 ] ;
F_88 ( & V_11 -> V_19 ) ;
V_131 = ! F_80 ( V_23 , V_11 , V_132 ) ;
F_82 ( V_11 -> V_2 , & V_11 -> V_19 ) ;
if ( V_131 )
F_91 ( & V_23 -> V_130 , V_133 / 2 ) ;
}
}
static int F_92 ( struct V_10 * V_11 , int V_134 )
{
struct V_22 * V_23 = V_11 -> V_2 -> V_24 -> V_25 ;
unsigned int V_30 , V_135 = 0 , V_136 = 0 ;
void * V_59 ;
struct V_137 * V_81 = F_93 ( V_23 -> V_81 ) ;
if ( V_23 -> V_37 ) {
void * V_87 ;
while ( V_135 < V_134 &&
( V_59 = F_57 ( V_11 -> V_2 , & V_30 , & V_87 ) ) ) {
V_136 += F_61 ( V_23 , V_11 , V_59 , V_30 , V_87 ) ;
V_135 ++ ;
}
} else {
while ( V_135 < V_134 &&
( V_59 = F_34 ( V_11 -> V_2 , & V_30 ) ) != NULL ) {
V_136 += F_61 ( V_23 , V_11 , V_59 , V_30 , NULL ) ;
V_135 ++ ;
}
}
if ( V_11 -> V_2 -> V_125 > F_94 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_80 ( V_23 , V_11 , V_56 ) )
F_91 ( & V_23 -> V_130 , 0 ) ;
}
F_95 ( & V_81 -> V_138 ) ;
V_81 -> V_139 += V_136 ;
V_81 -> V_140 += V_135 ;
F_96 ( & V_81 -> V_138 ) ;
return V_135 ;
}
static void F_97 ( struct V_46 * V_26 )
{
struct V_7 * V_8 ;
unsigned int V_30 ;
struct V_22 * V_23 = V_26 -> V_2 -> V_24 -> V_25 ;
struct V_137 * V_81 = F_93 ( V_23 -> V_81 ) ;
unsigned int V_141 = 0 ;
unsigned int V_136 = 0 ;
while ( ( V_8 = F_34 ( V_26 -> V_2 , & V_30 ) ) != NULL ) {
F_56 ( L_8 , V_8 ) ;
V_136 += V_8 -> V_30 ;
V_141 ++ ;
F_98 ( V_8 ) ;
}
if ( ! V_141 )
return;
F_95 ( & V_81 -> V_142 ) ;
V_81 -> V_143 += V_136 ;
V_81 -> V_144 += V_141 ;
F_96 ( & V_81 -> V_142 ) ;
}
static void F_99 ( struct V_10 * V_11 )
{
struct V_22 * V_23 = V_11 -> V_2 -> V_24 -> V_25 ;
unsigned int V_3 = F_3 ( V_11 -> V_2 ) ;
struct V_46 * V_26 = & V_23 -> V_26 [ V_3 ] ;
struct V_145 * V_4 = F_100 ( V_23 -> V_28 , V_3 ) ;
if ( ! V_26 -> V_19 . V_27 )
return;
if ( F_101 ( V_4 ) ) {
F_97 ( V_26 ) ;
F_102 ( V_4 ) ;
}
if ( V_26 -> V_2 -> V_125 >= 2 + V_39 )
F_103 ( V_4 ) ;
}
static int F_104 ( struct V_18 * V_19 , int V_134 )
{
struct V_10 * V_11 =
F_90 ( V_19 , struct V_10 , V_19 ) ;
unsigned int V_135 ;
F_99 ( V_11 ) ;
V_135 = F_92 ( V_11 , V_134 ) ;
if ( V_135 < V_134 )
F_13 ( V_19 , V_11 -> V_2 , V_135 ) ;
return V_135 ;
}
static int F_105 ( struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
if ( V_117 < V_23 -> V_50 )
if ( ! F_80 ( V_23 , & V_23 -> V_11 [ V_117 ] , V_132 ) )
F_91 ( & V_23 -> V_130 , 0 ) ;
F_82 ( V_23 -> V_11 [ V_117 ] . V_2 , & V_23 -> V_11 [ V_117 ] . V_19 ) ;
F_86 ( V_23 , V_23 -> V_26 [ V_117 ] . V_2 , & V_23 -> V_26 [ V_117 ] . V_19 ) ;
}
return 0 ;
}
static int F_107 ( struct V_18 * V_19 , int V_134 )
{
struct V_46 * V_26 = F_90 ( V_19 , struct V_46 , V_19 ) ;
struct V_22 * V_23 = V_26 -> V_2 -> V_24 -> V_25 ;
struct V_145 * V_4 = F_100 ( V_23 -> V_28 , F_1 ( V_26 -> V_2 ) ) ;
F_108 ( V_4 , F_109 () ) ;
F_97 ( V_26 ) ;
F_102 ( V_4 ) ;
F_13 ( V_19 , V_26 -> V_2 , 0 ) ;
if ( V_26 -> V_2 -> V_125 >= 2 + V_39 )
F_103 ( V_4 ) ;
return 0 ;
}
static int F_110 ( struct V_46 * V_26 , struct V_7 * V_8 )
{
struct V_6 * V_32 ;
const unsigned char * V_147 = ( (struct V_148 * ) V_8 -> V_53 ) -> V_149 ;
struct V_22 * V_23 = V_26 -> V_2 -> V_24 -> V_25 ;
unsigned V_150 ;
unsigned V_34 = V_23 -> V_34 ;
bool V_151 ;
F_56 ( L_9 , V_23 -> V_28 -> V_41 , V_8 , V_147 ) ;
V_151 = V_23 -> V_152 &&
! ( ( unsigned long ) V_8 -> V_53 & ( F_111 ( * V_32 ) - 1 ) ) &&
! F_112 ( V_8 ) && F_113 ( V_8 ) >= V_34 ;
if ( V_151 )
V_32 = (struct V_6 * ) ( V_8 -> V_53 - V_34 ) ;
else
V_32 = F_5 ( V_8 ) ;
if ( F_114 ( V_8 , & V_32 -> V_32 ,
F_63 ( V_23 -> V_24 ) , false ) )
F_115 () ;
if ( V_23 -> V_37 )
V_32 -> V_88 = 0 ;
F_73 ( V_26 -> V_54 , F_31 ( V_8 ) -> V_43 + ( V_151 ? 1 : 2 ) ) ;
if ( V_151 ) {
F_116 ( V_8 , V_34 ) ;
V_150 = F_117 ( V_8 , V_26 -> V_54 , 0 , V_8 -> V_30 ) ;
F_118 ( V_8 , V_34 ) ;
} else {
F_74 ( V_26 -> V_54 , V_32 , V_34 ) ;
V_150 = F_117 ( V_8 , V_26 -> V_54 + 1 , 0 , V_8 -> V_30 ) + 1 ;
}
return F_37 ( V_26 -> V_2 , V_26 -> V_54 , V_150 , V_8 , V_56 ) ;
}
static T_5 F_119 ( struct V_7 * V_8 , struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
int V_153 = F_120 ( V_8 ) ;
struct V_46 * V_26 = & V_23 -> V_26 [ V_153 ] ;
int V_49 ;
struct V_145 * V_4 = F_100 ( V_28 , V_153 ) ;
bool V_154 = ! V_8 -> V_155 ;
bool V_156 = V_26 -> V_19 . V_27 ;
F_97 ( V_26 ) ;
if ( V_156 && V_154 )
F_121 ( V_26 -> V_2 ) ;
F_122 ( V_8 ) ;
V_49 = F_110 ( V_26 , V_8 ) ;
if ( F_16 ( V_49 ) ) {
V_28 -> V_81 . V_157 ++ ;
if ( F_123 () )
F_124 ( & V_28 -> V_28 ,
L_10 , V_153 , V_49 ) ;
V_28 -> V_81 . V_158 ++ ;
F_98 ( V_8 ) ;
return V_159 ;
}
if ( ! V_156 ) {
F_125 ( V_8 ) ;
F_126 ( V_8 ) ;
}
if ( V_26 -> V_2 -> V_125 < 2 + V_39 ) {
F_127 ( V_28 , V_153 ) ;
if ( ! V_156 &&
F_16 ( ! F_121 ( V_26 -> V_2 ) ) ) {
F_97 ( V_26 ) ;
if ( V_26 -> V_2 -> V_125 >= 2 + V_39 ) {
F_128 ( V_28 , V_153 ) ;
F_11 ( V_26 -> V_2 ) ;
}
}
}
if ( V_154 || F_129 ( V_4 ) )
F_38 ( V_26 -> V_2 ) ;
return V_159 ;
}
static bool F_130 ( struct V_22 * V_23 , T_6 V_160 , T_6 V_161 ,
struct V_162 * V_163 )
{
struct V_162 * V_164 [ 4 ] , V_32 , V_165 ;
unsigned V_166 = 0 , V_167 ;
F_29 ( ! F_131 ( V_23 -> V_24 , V_168 ) ) ;
V_23 -> V_169 = ~ 0 ;
V_23 -> V_170 . V_160 = V_160 ;
V_23 -> V_170 . V_161 = V_161 ;
F_36 ( & V_32 , & V_23 -> V_170 , sizeof( V_23 -> V_170 ) ) ;
V_164 [ V_166 ++ ] = & V_32 ;
if ( V_163 )
V_164 [ V_166 ++ ] = V_163 ;
F_36 ( & V_165 , & V_23 -> V_169 , sizeof( V_23 -> V_169 ) ) ;
V_164 [ V_166 ] = & V_165 ;
F_29 ( V_166 + 1 > F_132 ( V_164 ) ) ;
F_133 ( V_23 -> V_171 , V_164 , V_166 , 1 , V_23 , V_56 ) ;
if ( F_16 ( ! F_38 ( V_23 -> V_171 ) ) )
return V_23 -> V_169 == V_172 ;
while ( ! F_34 ( V_23 -> V_171 , & V_167 ) &&
! F_134 ( V_23 -> V_171 ) )
F_135 () ;
return V_23 -> V_169 == V_172 ;
}
static int F_136 ( struct V_58 * V_28 , void * V_17 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
struct V_173 * V_24 = V_23 -> V_24 ;
int V_100 ;
struct V_174 * V_175 ;
struct V_162 V_54 ;
V_175 = F_137 ( V_17 , sizeof( * V_175 ) , V_132 ) ;
if ( ! V_175 )
return - V_114 ;
V_100 = F_138 ( V_28 , V_175 ) ;
if ( V_100 )
goto V_163;
if ( F_131 ( V_24 , V_176 ) ) {
F_36 ( & V_54 , V_175 -> V_177 , V_28 -> V_178 ) ;
if ( ! F_130 ( V_23 , V_179 ,
V_180 , & V_54 ) ) {
F_124 ( & V_24 -> V_28 ,
L_11 ) ;
V_100 = - V_181 ;
goto V_163;
}
} else if ( F_131 ( V_24 , V_182 ) &&
! F_131 ( V_24 , V_183 ) ) {
unsigned int V_117 ;
for ( V_117 = 0 ; V_117 < V_28 -> V_178 ; V_117 ++ )
F_139 ( V_24 ,
F_140 ( struct V_184 , V_185 ) +
V_117 , V_175 -> V_177 [ V_117 ] ) ;
}
F_141 ( V_28 , V_17 ) ;
V_100 = 0 ;
V_163:
F_142 ( V_175 ) ;
return V_100 ;
}
static void V_137 ( struct V_58 * V_28 ,
struct V_186 * V_187 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
int V_188 ;
unsigned int V_189 ;
F_143 (cpu) {
struct V_137 * V_81 = F_144 ( V_23 -> V_81 , V_188 ) ;
T_7 V_190 , V_191 , V_192 , V_193 ;
do {
V_189 = F_145 ( & V_81 -> V_142 ) ;
V_190 = V_81 -> V_144 ;
V_191 = V_81 -> V_143 ;
} while ( F_146 ( & V_81 -> V_142 , V_189 ) );
do {
V_189 = F_145 ( & V_81 -> V_138 ) ;
V_192 = V_81 -> V_140 ;
V_193 = V_81 -> V_139 ;
} while ( F_146 ( & V_81 -> V_138 , V_189 ) );
V_187 -> V_140 += V_192 ;
V_187 -> V_144 += V_190 ;
V_187 -> V_139 += V_193 ;
V_187 -> V_143 += V_191 ;
}
V_187 -> V_158 = V_28 -> V_81 . V_158 ;
V_187 -> V_157 = V_28 -> V_81 . V_157 ;
V_187 -> V_82 = V_28 -> V_81 . V_82 ;
V_187 -> V_93 = V_28 -> V_81 . V_93 ;
V_187 -> V_110 = V_28 -> V_81 . V_110 ;
}
static void F_147 ( struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_50 ; V_117 ++ )
F_148 ( & V_23 -> V_11 [ V_117 ] . V_19 ) ;
}
static void F_149 ( struct V_22 * V_23 )
{
F_150 () ;
if ( ! F_130 ( V_23 , V_194 ,
V_195 , NULL ) )
F_124 ( & V_23 -> V_28 -> V_28 , L_12 ) ;
F_151 () ;
}
static int F_152 ( struct V_22 * V_23 , T_3 V_196 )
{
struct V_162 V_54 ;
struct V_58 * V_28 = V_23 -> V_28 ;
if ( ! V_23 -> V_197 || ! F_131 ( V_23 -> V_24 , V_198 ) )
return 0 ;
V_23 -> V_199 . V_200 = F_153 ( V_23 -> V_24 , V_196 ) ;
F_36 ( & V_54 , & V_23 -> V_199 , sizeof( V_23 -> V_199 ) ) ;
if ( ! F_130 ( V_23 , V_201 ,
V_202 , & V_54 ) ) {
F_124 ( & V_28 -> V_28 , L_13 ,
V_196 ) ;
return - V_181 ;
} else {
V_23 -> V_50 = V_196 ;
if ( V_28 -> V_73 & V_203 )
F_91 ( & V_23 -> V_130 , 0 ) ;
}
return 0 ;
}
static int F_154 ( struct V_22 * V_23 , T_3 V_196 )
{
int V_49 ;
F_150 () ;
V_49 = F_152 ( V_23 , V_196 ) ;
F_151 () ;
return V_49 ;
}
static int F_155 ( struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
int V_117 ;
F_156 ( & V_23 -> V_130 ) ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
F_88 ( & V_23 -> V_11 [ V_117 ] . V_19 ) ;
F_87 ( & V_23 -> V_26 [ V_117 ] . V_19 ) ;
}
return 0 ;
}
static void F_157 ( struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
struct V_162 V_54 [ 2 ] ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
int V_208 ;
int V_209 ;
void * V_59 ;
int V_117 ;
if ( ! F_131 ( V_23 -> V_24 , V_210 ) )
return;
V_23 -> V_211 = ( ( V_28 -> V_73 & V_212 ) != 0 ) ;
V_23 -> V_213 = ( ( V_28 -> V_73 & V_214 ) != 0 ) ;
F_36 ( V_54 , & V_23 -> V_211 , sizeof( V_23 -> V_211 ) ) ;
if ( ! F_130 ( V_23 , V_215 ,
V_216 , V_54 ) )
F_124 ( & V_28 -> V_28 , L_14 ,
V_23 -> V_211 ? L_15 : L_16 ) ;
F_36 ( V_54 , & V_23 -> V_213 , sizeof( V_23 -> V_213 ) ) ;
if ( ! F_130 ( V_23 , V_215 ,
V_217 , V_54 ) )
F_124 ( & V_28 -> V_28 , L_17 ,
V_23 -> V_213 ? L_15 : L_16 ) ;
V_208 = F_158 ( V_28 ) ;
V_209 = F_159 ( V_28 ) ;
V_59 = F_160 ( ( ( V_208 + V_209 ) * V_218 ) +
( 2 * sizeof( V_205 -> V_219 ) ) , V_56 ) ;
V_205 = V_59 ;
if ( ! V_59 )
return;
F_73 ( V_54 , 2 ) ;
V_205 -> V_219 = F_161 ( V_23 -> V_24 , V_208 ) ;
V_117 = 0 ;
F_162 (ha, dev)
memcpy ( & V_205 -> V_220 [ V_117 ++ ] [ 0 ] , V_207 -> V_175 , V_218 ) ;
F_74 ( & V_54 [ 0 ] , V_205 ,
sizeof( V_205 -> V_219 ) + ( V_208 * V_218 ) ) ;
V_205 = ( void * ) & V_205 -> V_220 [ V_208 ] [ 0 ] ;
V_205 -> V_219 = F_161 ( V_23 -> V_24 , V_209 ) ;
V_117 = 0 ;
F_163 (ha, dev)
memcpy ( & V_205 -> V_220 [ V_117 ++ ] [ 0 ] , V_207 -> V_175 , V_218 ) ;
F_74 ( & V_54 [ 1 ] , V_205 ,
sizeof( V_205 -> V_219 ) + ( V_209 * V_218 ) ) ;
if ( ! F_130 ( V_23 , V_179 ,
V_221 , V_54 ) )
F_124 ( & V_28 -> V_28 , L_18 ) ;
F_142 ( V_59 ) ;
}
static int F_164 ( struct V_58 * V_28 ,
T_8 V_222 , T_3 V_223 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
struct V_162 V_54 ;
V_23 -> V_224 = V_223 ;
F_36 ( & V_54 , & V_23 -> V_224 , sizeof( V_23 -> V_224 ) ) ;
if ( ! F_130 ( V_23 , V_225 ,
V_226 , & V_54 ) )
F_124 ( & V_28 -> V_28 , L_19 , V_223 ) ;
return 0 ;
}
static int F_165 ( struct V_58 * V_28 ,
T_8 V_222 , T_3 V_223 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
struct V_162 V_54 ;
V_23 -> V_224 = V_223 ;
F_36 ( & V_54 , & V_23 -> V_224 , sizeof( V_23 -> V_224 ) ) ;
if ( ! F_130 ( V_23 , V_225 ,
V_227 , & V_54 ) )
F_124 ( & V_28 -> V_28 , L_20 , V_223 ) ;
return 0 ;
}
static void F_166 ( struct V_22 * V_23 , long V_228 )
{
int V_117 ;
if ( V_23 -> V_127 ) {
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
F_167 ( V_23 -> V_11 [ V_117 ] . V_2 , - 1 ) ;
F_167 ( V_23 -> V_26 [ V_117 ] . V_2 , - 1 ) ;
}
V_23 -> V_127 = false ;
}
}
static void F_168 ( struct V_22 * V_23 )
{
int V_117 ;
int V_188 ;
if ( V_23 -> V_50 == 1 ||
V_23 -> V_146 != F_169 () ) {
F_166 ( V_23 , - 1 ) ;
return;
}
V_117 = 0 ;
F_170 (cpu) {
F_167 ( V_23 -> V_11 [ V_117 ] . V_2 , V_188 ) ;
F_167 ( V_23 -> V_26 [ V_117 ] . V_2 , V_188 ) ;
F_171 ( V_23 -> V_28 , F_172 ( V_188 ) , V_117 ) ;
V_117 ++ ;
}
V_23 -> V_127 = true ;
}
static int F_173 ( unsigned int V_188 , struct V_229 * V_230 )
{
struct V_22 * V_23 = F_174 ( V_230 , struct V_22 ,
V_230 ) ;
F_168 ( V_23 ) ;
return 0 ;
}
static int F_175 ( unsigned int V_188 , struct V_229 * V_230 )
{
struct V_22 * V_23 = F_174 ( V_230 , struct V_22 ,
V_231 ) ;
F_168 ( V_23 ) ;
return 0 ;
}
static int F_176 ( unsigned int V_188 , struct V_229 * V_230 )
{
struct V_22 * V_23 = F_174 ( V_230 , struct V_22 ,
V_230 ) ;
F_166 ( V_23 , V_188 ) ;
return 0 ;
}
static int F_177 ( struct V_22 * V_23 )
{
int V_100 ;
V_100 = F_178 ( V_232 , & V_23 -> V_230 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_178 ( V_233 ,
& V_23 -> V_231 ) ;
if ( ! V_100 )
return V_100 ;
F_179 ( V_232 , & V_23 -> V_230 ) ;
return V_100 ;
}
static void F_180 ( struct V_22 * V_23 )
{
F_179 ( V_232 , & V_23 -> V_230 ) ;
F_179 ( V_233 ,
& V_23 -> V_231 ) ;
}
static void F_181 ( struct V_58 * V_28 ,
struct V_234 * V_235 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
V_235 -> V_236 = F_94 ( V_23 -> V_11 [ 0 ] . V_2 ) ;
V_235 -> V_237 = F_94 ( V_23 -> V_26 [ 0 ] . V_2 ) ;
V_235 -> V_238 = V_235 -> V_236 ;
V_235 -> V_239 = V_235 -> V_237 ;
}
static void F_182 ( struct V_58 * V_28 ,
struct V_240 * V_241 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
struct V_173 * V_24 = V_23 -> V_24 ;
F_183 ( V_241 -> V_242 , V_243 , sizeof( V_241 -> V_242 ) ) ;
F_183 ( V_241 -> V_244 , V_245 , sizeof( V_241 -> V_244 ) ) ;
F_183 ( V_241 -> V_246 , F_184 ( V_24 ) , sizeof( V_241 -> V_246 ) ) ;
}
static int F_185 ( struct V_58 * V_28 ,
struct V_247 * V_248 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
T_3 V_196 = V_248 -> V_249 ;
int V_49 ;
if ( V_248 -> V_250 || V_248 -> V_251 || V_248 -> V_252 )
return - V_181 ;
if ( V_196 > V_23 -> V_146 || V_196 == 0 )
return - V_181 ;
if ( V_23 -> V_11 [ 0 ] . V_61 )
return - V_181 ;
F_186 () ;
V_49 = F_152 ( V_23 , V_196 ) ;
if ( ! V_49 ) {
F_187 ( V_28 , V_196 ) ;
F_188 ( V_28 , V_196 ) ;
F_168 ( V_23 ) ;
}
F_189 () ;
return V_49 ;
}
static void F_190 ( struct V_58 * V_28 ,
struct V_247 * V_248 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
V_248 -> V_249 = V_23 -> V_50 ;
V_248 -> V_253 = V_23 -> V_146 ;
V_248 -> V_254 = 0 ;
V_248 -> V_250 = 0 ;
V_248 -> V_251 = 0 ;
V_248 -> V_252 = 0 ;
}
static bool
F_191 ( const struct V_255 * V_161 )
{
struct V_255 V_256 = * V_161 ;
struct V_255 V_257 = {} ;
V_256 . V_258 . V_259 = 0 ;
V_257 . V_258 . V_260 = V_261 ;
F_192 ( & V_256 , V_262 ) ;
V_256 . V_258 . V_263 = 0 ;
V_256 . V_258 . V_161 = 0 ;
V_256 . V_258 . V_264 = 0 ;
return ! memcmp ( & V_256 . V_258 , & V_257 . V_258 , sizeof( V_256 . V_258 ) ) &&
F_193 ( V_256 . V_265 . V_266 ,
V_267 ) &&
F_193 ( V_256 . V_265 . V_262 ,
V_267 ) &&
F_193 ( V_256 . V_265 . V_268 ,
V_267 ) ;
}
static int F_194 ( struct V_58 * V_28 ,
const struct V_255 * V_161 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
T_2 V_259 ;
V_259 = V_161 -> V_258 . V_259 ;
if ( ! F_195 ( V_259 ) ||
! F_196 ( V_161 -> V_258 . V_263 ) ||
! F_191 ( V_161 ) )
return - V_181 ;
V_23 -> V_259 = V_259 ;
V_23 -> V_263 = V_161 -> V_258 . V_263 ;
return 0 ;
}
static int F_197 ( struct V_58 * V_28 ,
struct V_255 * V_161 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
V_161 -> V_258 . V_259 = V_23 -> V_259 ;
V_161 -> V_258 . V_263 = V_23 -> V_263 ;
V_161 -> V_258 . V_260 = V_261 ;
return 0 ;
}
static void F_198 ( struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
V_23 -> V_259 = V_269 ;
V_23 -> V_263 = V_270 ;
}
static void F_199 ( struct V_173 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
int V_117 ;
F_200 ( & V_23 -> V_271 ) ;
F_201 ( V_23 -> V_28 ) ;
F_202 ( V_23 -> V_28 ) ;
F_156 ( & V_23 -> V_130 ) ;
if ( F_203 ( V_23 -> V_28 ) ) {
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
F_88 ( & V_23 -> V_11 [ V_117 ] . V_19 ) ;
F_87 ( & V_23 -> V_26 [ V_117 ] . V_19 ) ;
}
}
}
static int F_204 ( struct V_173 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
int V_49 , V_117 ;
V_49 = F_205 ( V_23 ) ;
if ( V_49 )
return V_49 ;
F_206 ( V_24 ) ;
if ( F_203 ( V_23 -> V_28 ) ) {
for ( V_117 = 0 ; V_117 < V_23 -> V_50 ; V_117 ++ )
if ( ! F_80 ( V_23 , & V_23 -> V_11 [ V_117 ] , V_132 ) )
F_91 ( & V_23 -> V_130 , 0 ) ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
F_82 ( V_23 -> V_11 [ V_117 ] . V_2 , & V_23 -> V_11 [ V_117 ] . V_19 ) ;
F_86 ( V_23 , V_23 -> V_26 [ V_117 ] . V_2 ,
& V_23 -> V_26 [ V_117 ] . V_19 ) ;
}
}
F_207 ( V_23 -> V_28 ) ;
return V_49 ;
}
static int F_208 ( struct V_22 * V_23 , int V_272 , int V_273 )
{
struct V_173 * V_28 = V_23 -> V_24 ;
int V_100 ;
F_209 ( V_28 ) ;
V_28 -> V_274 = V_28 -> V_275 -> V_276 ( V_28 ) & V_277 ;
F_199 ( V_28 ) ;
F_210 ( V_23 ) ;
F_211 ( V_28 , V_278 ) ;
F_211 ( V_28 , V_279 ) ;
V_100 = F_212 ( V_28 ) ;
if ( V_100 )
goto V_49;
V_23 -> V_51 = V_273 ;
V_100 = F_204 ( V_28 ) ;
if ( V_100 )
goto V_49;
V_100 = F_152 ( V_23 , V_272 ) ;
if ( V_100 )
goto V_49;
F_211 ( V_28 , V_280 ) ;
F_213 ( V_28 ) ;
return 0 ;
V_49:
F_211 ( V_28 , V_277 ) ;
return V_100 ;
}
static int F_214 ( struct V_58 * V_28 , struct V_60 * V_281 ,
struct V_282 * V_283 )
{
unsigned long int V_284 = V_40 - sizeof( struct V_38 ) ;
struct V_22 * V_23 = F_106 ( V_28 ) ;
struct V_60 * V_285 ;
T_3 V_273 = 0 , V_272 ;
int V_117 , V_49 ;
if ( F_131 ( V_23 -> V_24 , V_286 ) ||
F_131 ( V_23 -> V_24 , V_287 ) ||
F_131 ( V_23 -> V_24 , V_288 ) ||
F_131 ( V_23 -> V_24 , V_289 ) ) {
F_215 ( V_283 , L_21 ) ;
return - V_290 ;
}
if ( V_23 -> V_37 && ! V_23 -> V_152 ) {
F_215 ( V_283 , L_22 ) ;
return - V_181 ;
}
if ( V_28 -> V_291 > V_284 ) {
F_215 ( V_283 , L_23 ) ;
F_216 ( V_28 , L_24 , V_284 ) ;
return - V_181 ;
}
V_272 = V_23 -> V_50 - V_23 -> V_51 ;
if ( V_281 )
V_273 = V_292 ;
if ( V_272 + V_273 > V_23 -> V_146 ) {
F_215 ( V_283 , L_25 ) ;
F_216 ( V_28 , L_26 ,
V_272 + V_273 , V_23 -> V_146 ) ;
return - V_114 ;
}
if ( V_281 ) {
V_281 = F_217 ( V_281 , V_23 -> V_146 - 1 ) ;
if ( F_218 ( V_281 ) )
return F_219 ( V_281 ) ;
}
if ( V_23 -> V_51 != V_273 ) {
V_49 = F_208 ( V_23 , V_272 + V_273 , V_273 ) ;
if ( V_49 ) {
F_124 ( & V_28 -> V_28 , L_27 ) ;
goto V_293;
}
}
F_188 ( V_28 , V_272 + V_273 ) ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
V_285 = F_220 ( V_23 -> V_11 [ V_117 ] . V_61 ) ;
F_221 ( V_23 -> V_11 [ V_117 ] . V_61 , V_281 ) ;
if ( V_285 )
F_222 ( V_285 ) ;
}
return 0 ;
V_293:
if ( V_281 )
F_223 ( V_281 , V_23 -> V_146 - 1 ) ;
return V_49 ;
}
static bool F_224 ( struct V_58 * V_28 )
{
struct V_22 * V_23 = F_106 ( V_28 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
if ( V_23 -> V_11 [ V_117 ] . V_61 )
return true ;
}
return false ;
}
static int F_225 ( struct V_58 * V_28 , struct V_294 * V_45 )
{
switch ( V_45 -> V_295 ) {
case V_296 :
return F_214 ( V_28 , V_45 -> V_281 , V_45 -> V_283 ) ;
case V_297 :
V_45 -> V_298 = F_224 ( V_28 ) ;
return 0 ;
default:
return - V_181 ;
}
}
static void F_226 ( struct V_128 * V_129 )
{
struct V_22 * V_23 =
F_90 ( V_129 , struct V_22 , V_271 ) ;
T_3 V_299 ;
if ( F_227 ( V_23 -> V_24 , V_300 ,
struct V_184 , V_301 , & V_299 ) < 0 )
return;
if ( V_299 & V_302 ) {
F_228 ( V_23 -> V_28 ) ;
F_149 ( V_23 ) ;
}
V_299 &= V_303 ;
if ( V_23 -> V_301 == V_299 )
return;
V_23 -> V_301 = V_299 ;
if ( V_23 -> V_301 & V_303 ) {
F_229 ( V_23 -> V_28 ) ;
F_230 ( V_23 -> V_28 ) ;
} else {
F_231 ( V_23 -> V_28 ) ;
F_232 ( V_23 -> V_28 ) ;
}
}
static void F_233 ( struct V_173 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
F_234 ( & V_23 -> V_271 ) ;
}
static void F_235 ( struct V_22 * V_23 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
F_236 ( & V_23 -> V_11 [ V_117 ] . V_19 ) ;
F_237 ( & V_23 -> V_11 [ V_117 ] . V_19 ) ;
F_237 ( & V_23 -> V_26 [ V_117 ] . V_19 ) ;
}
F_238 () ;
F_142 ( V_23 -> V_11 ) ;
F_142 ( V_23 -> V_26 ) ;
}
static void F_239 ( struct V_22 * V_23 )
{
struct V_60 * V_285 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
while ( V_23 -> V_11 [ V_117 ] . V_15 )
F_52 ( F_7 ( & V_23 -> V_11 [ V_117 ] , V_132 ) , 0 ) ;
V_285 = F_220 ( V_23 -> V_11 [ V_117 ] . V_61 ) ;
F_240 ( V_23 -> V_11 [ V_117 ] . V_61 , NULL ) ;
if ( V_285 )
F_222 ( V_285 ) ;
}
}
static void F_241 ( struct V_22 * V_23 )
{
F_150 () ;
F_239 ( V_23 ) ;
F_151 () ;
}
static void F_242 ( struct V_22 * V_23 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ )
if ( V_23 -> V_11 [ V_117 ] . V_113 . V_12 )
F_26 ( V_23 -> V_11 [ V_117 ] . V_113 . V_12 ) ;
}
static bool F_243 ( struct V_22 * V_23 , int V_304 )
{
if ( V_304 < ( V_23 -> V_50 - V_23 -> V_51 ) )
return false ;
else if ( V_304 < V_23 -> V_50 )
return true ;
else
return false ;
}
static void F_244 ( struct V_22 * V_23 )
{
void * V_59 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
struct V_1 * V_2 = V_23 -> V_26 [ V_117 ] . V_2 ;
while ( ( V_59 = F_245 ( V_2 ) ) != NULL ) {
if ( ! F_243 ( V_23 , V_117 ) )
F_28 ( V_59 ) ;
else
F_26 ( F_35 ( V_59 ) ) ;
}
}
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
struct V_1 * V_2 = V_23 -> V_11 [ V_117 ] . V_2 ;
while ( ( V_59 = F_245 ( V_2 ) ) != NULL ) {
if ( V_23 -> V_37 ) {
F_26 ( F_35 ( V_59 ) ) ;
} else if ( V_23 -> V_102 ) {
F_6 ( & V_23 -> V_11 [ V_117 ] , V_59 ) ;
} else {
F_26 ( F_35 ( V_59 ) ) ;
}
}
}
}
static void F_246 ( struct V_22 * V_23 )
{
struct V_173 * V_24 = V_23 -> V_24 ;
F_166 ( V_23 , - 1 ) ;
V_24 -> V_275 -> V_305 ( V_24 ) ;
F_235 ( V_23 ) ;
}
static unsigned int F_247 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
const unsigned int V_34 = sizeof( struct V_6 ) ;
unsigned int V_306 = F_94 ( V_2 ) ;
unsigned int V_307 = V_23 -> V_102 ? V_308 : V_23 -> V_28 -> V_309 ;
unsigned int V_310 = V_34 + V_101 + V_311 + V_307 ;
unsigned int V_312 = F_248 ( V_310 , V_306 ) ;
return F_249 ( F_249 ( V_312 , V_34 ) - V_34 ,
( unsigned int ) V_67 ) ;
}
static int F_250 ( struct V_22 * V_23 )
{
T_9 * * V_313 ;
struct V_1 * * V_314 ;
int V_100 = - V_114 ;
int V_117 , V_315 ;
const char * * V_316 ;
bool * V_87 ;
V_315 = V_23 -> V_146 * 2 +
F_131 ( V_23 -> V_24 , V_168 ) ;
V_314 = F_160 ( V_315 * sizeof( * V_314 ) , V_132 ) ;
if ( ! V_314 )
goto V_317;
V_313 = F_251 ( V_315 * sizeof( * V_313 ) , V_132 ) ;
if ( ! V_313 )
goto V_318;
V_316 = F_251 ( V_315 * sizeof( * V_316 ) , V_132 ) ;
if ( ! V_316 )
goto V_319;
if ( V_23 -> V_37 ) {
V_87 = F_160 ( V_315 * sizeof( * V_87 ) , V_132 ) ;
if ( ! V_87 )
goto V_320;
} else {
V_87 = NULL ;
}
if ( V_23 -> V_197 ) {
V_313 [ V_315 - 1 ] = NULL ;
V_316 [ V_315 - 1 ] = L_28 ;
}
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
V_313 [ F_4 ( V_117 ) ] = F_81 ;
V_313 [ F_2 ( V_117 ) ] = F_18 ;
sprintf ( V_23 -> V_11 [ V_117 ] . V_41 , L_29 , V_117 ) ;
sprintf ( V_23 -> V_26 [ V_117 ] . V_41 , L_30 , V_117 ) ;
V_316 [ F_4 ( V_117 ) ] = V_23 -> V_11 [ V_117 ] . V_41 ;
V_316 [ F_2 ( V_117 ) ] = V_23 -> V_26 [ V_117 ] . V_41 ;
if ( V_87 )
V_87 [ F_4 ( V_117 ) ] = true ;
}
V_100 = V_23 -> V_24 -> V_275 -> V_321 ( V_23 -> V_24 , V_315 , V_314 , V_313 ,
V_316 , V_87 , NULL ) ;
if ( V_100 )
goto V_322;
if ( V_23 -> V_197 ) {
V_23 -> V_171 = V_314 [ V_315 - 1 ] ;
if ( F_131 ( V_23 -> V_24 , V_323 ) )
V_23 -> V_28 -> V_324 |= V_325 ;
}
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
V_23 -> V_11 [ V_117 ] . V_2 = V_314 [ F_4 ( V_117 ) ] ;
V_23 -> V_11 [ V_117 ] . V_312 = F_247 ( V_23 , V_23 -> V_11 [ V_117 ] . V_2 ) ;
V_23 -> V_26 [ V_117 ] . V_2 = V_314 [ F_2 ( V_117 ) ] ;
}
F_142 ( V_316 ) ;
F_142 ( V_313 ) ;
F_142 ( V_314 ) ;
return 0 ;
V_322:
F_142 ( V_87 ) ;
V_320:
F_142 ( V_316 ) ;
V_319:
F_142 ( V_313 ) ;
V_318:
F_142 ( V_314 ) ;
V_317:
return V_100 ;
}
static int F_252 ( struct V_22 * V_23 )
{
int V_117 ;
V_23 -> V_26 = F_160 ( sizeof( * V_23 -> V_26 ) * V_23 -> V_146 , V_132 ) ;
if ( ! V_23 -> V_26 )
goto V_326;
V_23 -> V_11 = F_160 ( sizeof( * V_23 -> V_11 ) * V_23 -> V_146 , V_132 ) ;
if ( ! V_23 -> V_11 )
goto V_327;
F_253 ( & V_23 -> V_130 , F_89 ) ;
for ( V_117 = 0 ; V_117 < V_23 -> V_146 ; V_117 ++ ) {
V_23 -> V_11 [ V_117 ] . V_15 = NULL ;
F_254 ( V_23 -> V_28 , & V_23 -> V_11 [ V_117 ] . V_19 , F_104 ,
V_328 ) ;
F_255 ( V_23 -> V_28 , & V_23 -> V_26 [ V_117 ] . V_19 , F_107 ,
V_329 ? V_328 : 0 ) ;
F_73 ( V_23 -> V_11 [ V_117 ] . V_54 , F_132 ( V_23 -> V_11 [ V_117 ] . V_54 ) ) ;
F_256 ( & V_23 -> V_11 [ V_117 ] . V_92 ) ;
F_73 ( V_23 -> V_26 [ V_117 ] . V_54 , F_132 ( V_23 -> V_26 [ V_117 ] . V_54 ) ) ;
}
return 0 ;
V_327:
F_142 ( V_23 -> V_26 ) ;
V_326:
return - V_114 ;
}
static int F_205 ( struct V_22 * V_23 )
{
int V_100 ;
V_100 = F_252 ( V_23 ) ;
if ( V_100 )
goto V_49;
V_100 = F_250 ( V_23 ) ;
if ( V_100 )
goto V_330;
F_186 () ;
F_168 ( V_23 ) ;
F_189 () ;
return 0 ;
V_330:
F_235 ( V_23 ) ;
V_49:
return V_100 ;
}
static T_10 F_257 ( struct V_331 * V_332 ,
struct V_333 * V_334 , char * V_59 )
{
struct V_22 * V_23 = F_106 ( V_332 -> V_28 ) ;
unsigned int V_335 = F_258 ( V_332 ) ;
struct V_118 * V_336 ;
F_29 ( V_335 >= V_23 -> V_146 ) ;
V_336 = & V_23 -> V_11 [ V_335 ] . V_92 ;
return sprintf ( V_59 , L_31 ,
F_75 ( & V_23 -> V_11 [ V_335 ] , V_336 ) ) ;
}
static bool F_259 ( struct V_173 * V_24 ,
unsigned int V_337 ,
const char * V_338 , const char * V_339 )
{
if ( ! F_131 ( V_24 , V_337 ) )
return false ;
F_260 ( & V_24 -> V_28 , L_32 ,
V_338 , V_339 ) ;
return true ;
}
static bool F_261 ( struct V_173 * V_24 )
{
if ( ! F_131 ( V_24 , V_168 ) &&
( F_262 ( V_24 , V_210 ,
L_33 ) ||
F_262 ( V_24 , V_323 ,
L_33 ) ||
F_262 ( V_24 , V_340 ,
L_33 ) ||
F_262 ( V_24 , V_198 , L_33 ) ||
F_262 ( V_24 , V_176 ,
L_33 ) ) ) {
return false ;
}
return true ;
}
static int F_263 ( struct V_173 * V_24 )
{
if ( ! V_24 -> V_275 -> V_341 ) {
F_260 ( & V_24 -> V_28 , L_34 ,
V_342 ) ;
return - V_181 ;
}
if ( ! F_261 ( V_24 ) )
return - V_181 ;
if ( F_131 ( V_24 , V_343 ) ) {
int V_291 = F_264 ( V_24 ,
F_140 ( struct V_184 ,
V_291 ) ) ;
if ( V_291 < V_344 )
F_265 ( V_24 , V_343 ) ;
}
return 0 ;
}
static int F_266 ( struct V_173 * V_24 )
{
int V_117 , V_49 ;
struct V_58 * V_28 ;
struct V_22 * V_23 ;
T_3 V_146 ;
int V_291 ;
V_49 = F_227 ( V_24 , V_198 ,
struct V_184 ,
V_345 , & V_146 ) ;
if ( V_49 || V_146 < V_346 ||
V_146 > V_347 ||
! F_131 ( V_24 , V_168 ) )
V_146 = 1 ;
V_28 = F_267 ( sizeof( struct V_22 ) , V_146 ) ;
if ( ! V_28 )
return - V_114 ;
V_28 -> V_348 |= V_349 | V_350 ;
V_28 -> V_351 = & V_352 ;
V_28 -> V_324 = V_353 ;
V_28 -> V_354 = & V_355 ;
F_268 ( V_28 , & V_24 -> V_28 ) ;
if ( F_131 ( V_24 , V_356 ) ) {
V_28 -> V_357 |= V_358 | V_359 ;
if ( V_360 )
V_28 -> V_324 |= V_358 | V_359 ;
if ( F_131 ( V_24 , V_361 ) ) {
V_28 -> V_357 |= V_362 | V_363
| V_364 | V_365 ;
}
if ( F_131 ( V_24 , V_366 ) )
V_28 -> V_357 |= V_362 ;
if ( F_131 ( V_24 , V_367 ) )
V_28 -> V_357 |= V_365 ;
if ( F_131 ( V_24 , V_368 ) )
V_28 -> V_357 |= V_364 ;
if ( F_131 ( V_24 , V_369 ) )
V_28 -> V_357 |= V_363 ;
V_28 -> V_324 |= V_370 ;
if ( V_371 )
V_28 -> V_324 |= V_28 -> V_357 & ( V_372 | V_363 ) ;
}
if ( F_131 ( V_24 , V_373 ) )
V_28 -> V_324 |= V_374 ;
V_28 -> V_375 = V_28 -> V_324 ;
V_28 -> V_376 = V_344 ;
V_28 -> V_309 = V_377 ;
if ( F_131 ( V_24 , V_182 ) )
F_269 ( V_24 ,
F_140 ( struct V_184 , V_185 ) ,
V_28 -> V_378 , V_28 -> V_178 ) ;
else
F_270 ( V_28 ) ;
V_23 = F_106 ( V_28 ) ;
V_23 -> V_28 = V_28 ;
V_23 -> V_24 = V_24 ;
V_24 -> V_25 = V_23 ;
V_23 -> V_81 = F_271 ( struct V_137 ) ;
V_49 = - V_114 ;
if ( V_23 -> V_81 == NULL )
goto free;
F_143 (i) {
struct V_137 * V_137 ;
V_137 = F_144 ( V_23 -> V_81 , V_117 ) ;
F_272 ( & V_137 -> V_142 ) ;
F_272 ( & V_137 -> V_138 ) ;
}
F_273 ( & V_23 -> V_271 , F_226 ) ;
if ( F_131 ( V_24 , V_286 ) ||
F_131 ( V_24 , V_287 ) ||
F_131 ( V_24 , V_288 ) ||
F_131 ( V_24 , V_289 ) )
V_23 -> V_102 = true ;
if ( F_131 ( V_24 , V_379 ) )
V_23 -> V_37 = true ;
if ( F_131 ( V_24 , V_379 ) ||
F_131 ( V_24 , V_183 ) )
V_23 -> V_34 = sizeof( struct V_6 ) ;
else
V_23 -> V_34 = sizeof( struct V_380 ) ;
if ( F_131 ( V_24 , V_381 ) ||
F_131 ( V_24 , V_183 ) )
V_23 -> V_152 = true ;
if ( F_131 ( V_24 , V_168 ) )
V_23 -> V_197 = true ;
if ( F_131 ( V_24 , V_343 ) ) {
V_291 = F_264 ( V_24 ,
F_140 ( struct V_184 ,
V_291 ) ) ;
if ( V_291 < V_28 -> V_376 ) {
F_260 ( & V_24 -> V_28 , L_35
L_36 , V_291 , V_28 -> V_376 ) ;
goto V_382;
}
V_28 -> V_291 = V_291 ;
V_28 -> V_309 = V_291 ;
if ( V_28 -> V_291 > V_383 )
V_23 -> V_102 = true ;
}
if ( V_23 -> V_152 )
V_28 -> V_384 = V_23 -> V_34 ;
if ( F_169 () >= V_146 )
V_23 -> V_50 = V_146 ;
else
V_23 -> V_50 = F_169 () ;
V_23 -> V_146 = V_146 ;
V_49 = F_205 ( V_23 ) ;
if ( V_49 )
goto V_382;
#ifdef F_274
if ( V_23 -> V_37 )
V_28 -> V_385 = & V_386 ;
#endif
F_187 ( V_28 , V_23 -> V_50 ) ;
F_188 ( V_28 , V_23 -> V_50 ) ;
F_198 ( V_28 ) ;
V_49 = F_275 ( V_28 ) ;
if ( V_49 ) {
F_56 ( L_37 ) ;
goto V_387;
}
F_206 ( V_24 ) ;
V_49 = F_177 ( V_23 ) ;
if ( V_49 ) {
F_56 ( L_38 ) ;
goto V_388;
}
F_154 ( V_23 , V_23 -> V_50 ) ;
if ( F_131 ( V_23 -> V_24 , V_300 ) ) {
F_231 ( V_28 ) ;
F_234 ( & V_23 -> V_271 ) ;
} else {
V_23 -> V_301 = V_303 ;
F_229 ( V_28 ) ;
}
F_56 ( L_39 ,
V_28 -> V_41 , V_146 ) ;
return 0 ;
V_388:
V_23 -> V_24 -> V_275 -> V_389 ( V_24 ) ;
F_276 ( V_28 ) ;
V_387:
F_156 ( & V_23 -> V_130 ) ;
F_242 ( V_23 ) ;
F_246 ( V_23 ) ;
V_382:
F_277 ( V_23 -> V_81 ) ;
free:
F_278 ( V_28 ) ;
return V_49 ;
}
static void F_210 ( struct V_22 * V_23 )
{
V_23 -> V_24 -> V_275 -> V_389 ( V_23 -> V_24 ) ;
F_244 ( V_23 ) ;
F_239 ( V_23 ) ;
F_242 ( V_23 ) ;
F_246 ( V_23 ) ;
}
static void F_279 ( struct V_22 * V_23 )
{
V_23 -> V_24 -> V_275 -> V_389 ( V_23 -> V_24 ) ;
F_244 ( V_23 ) ;
F_241 ( V_23 ) ;
F_242 ( V_23 ) ;
F_246 ( V_23 ) ;
}
static void F_280 ( struct V_173 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
F_180 ( V_23 ) ;
F_200 ( & V_23 -> V_271 ) ;
F_276 ( V_23 -> V_28 ) ;
F_279 ( V_23 ) ;
F_277 ( V_23 -> V_81 ) ;
F_278 ( V_23 -> V_28 ) ;
}
static int F_281 ( struct V_173 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
F_180 ( V_23 ) ;
F_199 ( V_24 ) ;
F_279 ( V_23 ) ;
return 0 ;
}
static int F_282 ( struct V_173 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
int V_49 ;
V_49 = F_204 ( V_24 ) ;
if ( V_49 )
return V_49 ;
F_154 ( V_23 , V_23 -> V_50 ) ;
V_49 = F_177 ( V_23 ) ;
if ( V_49 )
return V_49 ;
return 0 ;
}
static T_11 int F_283 ( void )
{
int V_100 ;
V_100 = F_284 ( V_390 , L_40 ,
F_173 ,
F_176 ) ;
if ( V_100 < 0 )
goto V_163;
V_232 = V_100 ;
V_100 = F_284 ( V_233 , L_41 ,
NULL , F_175 ) ;
if ( V_100 )
goto V_391;
V_100 = F_285 ( & V_392 ) ;
if ( V_100 )
goto V_393;
return 0 ;
V_393:
F_286 ( V_233 ) ;
V_391:
F_286 ( V_232 ) ;
V_163:
return V_100 ;
}
static T_12 void F_287 ( void )
{
F_286 ( V_233 ) ;
F_286 ( V_232 ) ;
F_288 ( & V_392 ) ;
}
