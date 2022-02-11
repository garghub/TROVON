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
static void F_28 ( struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
void * V_47 )
{
struct V_6 * V_30 ;
unsigned int V_48 , V_29 ;
void * V_49 ;
int V_50 ;
while ( ( V_49 = F_29 ( V_44 -> V_2 , & V_29 ) ) != NULL ) {
if ( V_19 -> V_36 ) {
struct V_12 * V_51 = F_30 ( V_49 ) ;
F_22 ( V_51 ) ;
} else {
struct V_7 * V_8 = V_49 ;
F_31 ( V_8 ) ;
}
}
if ( V_19 -> V_36 ) {
V_30 = V_46 -> V_47 ;
memset ( V_30 , 0 , V_19 -> V_32 ) ;
V_48 = 1 ;
F_32 ( V_44 -> V_52 , V_46 -> V_47 , V_46 -> V_53 - V_46 -> V_47 ) ;
} else {
struct V_7 * V_8 = V_47 ;
V_30 = F_5 ( V_8 ) ;
memset ( V_30 , 0 , V_19 -> V_32 ) ;
V_48 = 2 ;
F_33 ( V_44 -> V_52 , 2 ) ;
F_34 ( V_44 -> V_52 , V_30 , V_19 -> V_32 ) ;
F_35 ( V_8 , V_44 -> V_52 + 1 , 0 , V_8 -> V_29 ) ;
}
V_50 = F_36 ( V_44 -> V_2 , V_44 -> V_52 , V_48 ,
V_47 , V_54 ) ;
if ( F_18 ( V_50 ) ) {
if ( V_19 -> V_36 ) {
struct V_12 * V_12 = F_30 ( V_46 -> V_47 ) ;
F_22 ( V_12 ) ;
} else
F_31 ( V_47 ) ;
return;
}
F_37 ( V_44 -> V_2 ) ;
}
static T_2 F_38 ( struct V_18 * V_19 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
void * V_47 , int V_29 )
{
int V_33 ;
struct V_45 V_46 ;
void * V_26 ;
unsigned int V_57 ;
T_2 V_58 ;
if ( V_19 -> V_36 ) {
V_33 = sizeof( struct V_6 ) ;
V_46 . V_47 = V_47 + V_33 ;
V_46 . V_53 = V_46 . V_47 + ( V_29 - V_19 -> V_32 ) ;
V_26 = V_47 ;
} else {
struct V_7 * V_8 = V_47 ;
V_46 . V_47 = V_8 -> V_47 ;
V_46 . V_53 = V_46 . V_47 + V_29 ;
V_26 = V_8 -> V_47 ;
}
V_58 = F_39 ( V_56 , & V_46 ) ;
switch ( V_58 ) {
case V_59 :
return V_59 ;
case V_60 :
V_57 = V_19 -> V_61 -
V_19 -> V_62 +
F_40 () ;
V_46 . V_47 = V_26 ;
F_28 ( V_19 , V_11 , & V_19 -> V_44 [ V_57 ] , & V_46 , V_47 ) ;
return V_60 ;
default:
F_41 ( V_58 ) ;
case V_63 :
case V_64 :
return V_64 ;
}
}
static struct V_7 * F_42 ( struct V_65 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
void * V_26 , unsigned int V_29 )
{
struct V_7 * V_8 = V_26 ;
struct V_55 * V_56 ;
V_29 -= V_19 -> V_32 ;
F_43 ( V_8 , V_29 ) ;
F_44 () ;
V_56 = F_45 ( V_11 -> V_56 ) ;
if ( V_56 ) {
struct V_6 * V_30 = V_26 ;
T_2 V_58 ;
if ( F_18 ( V_30 -> V_30 . V_66 || V_30 -> V_30 . V_67 ) )
goto V_68;
V_58 = F_38 ( V_19 , V_11 , V_56 , V_8 , V_29 ) ;
switch ( V_58 ) {
case V_59 :
break;
case V_60 :
F_46 () ;
goto V_69;
case V_64 :
default:
goto V_68;
}
}
F_46 () ;
return V_8 ;
V_68:
F_46 () ;
V_22 -> V_70 . V_71 ++ ;
F_31 ( V_8 ) ;
V_69:
return NULL ;
}
static struct V_7 * F_47 ( struct V_65 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
void * V_26 ,
unsigned int V_29 )
{
struct V_12 * V_12 = V_26 ;
struct V_7 * V_8 = F_15 ( V_19 , V_11 , V_12 , 0 , V_29 , V_39 ) ;
if ( F_18 ( ! V_8 ) )
goto V_50;
return V_8 ;
V_50:
V_22 -> V_70 . V_71 ++ ;
F_6 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_12 * F_48 ( struct V_10 * V_11 ,
T_3 * V_72 ,
struct V_12 * V_17 ,
int V_28 ,
unsigned int * V_29 )
{
struct V_12 * V_12 = F_8 ( V_54 ) ;
unsigned int V_73 = 0 ;
if ( ! V_12 )
return NULL ;
memcpy ( F_16 ( V_12 ) + V_73 , F_16 ( V_17 ) + V_28 , * V_29 ) ;
V_73 += * V_29 ;
while ( -- * V_72 ) {
unsigned int V_74 ;
unsigned long V_75 ;
void * V_26 ;
int V_76 ;
V_75 = ( unsigned long ) F_29 ( V_11 -> V_2 , & V_74 ) ;
if ( F_18 ( ! V_75 ) )
goto V_77;
V_26 = F_13 ( V_75 ) ;
V_17 = F_30 ( V_26 ) ;
V_76 = V_26 - F_16 ( V_17 ) ;
if ( ( V_73 + V_74 ) > V_39 ) {
F_22 ( V_17 ) ;
goto V_77;
}
memcpy ( F_16 ( V_12 ) + V_73 ,
F_16 ( V_17 ) + V_76 , V_74 ) ;
V_73 += V_74 ;
F_22 ( V_17 ) ;
}
* V_29 = V_73 ;
return V_12 ;
V_77:
F_49 ( V_12 , 0 ) ;
return NULL ;
}
static struct V_7 * F_50 ( struct V_65 * V_22 ,
struct V_18 * V_19 ,
struct V_10 * V_11 ,
unsigned long V_75 ,
unsigned int V_29 )
{
void * V_26 = F_13 ( V_75 ) ;
struct V_6 * V_30 = V_26 ;
T_3 V_72 = F_51 ( V_19 -> V_20 , V_30 -> V_78 ) ;
struct V_12 * V_12 = F_30 ( V_26 ) ;
int V_28 = V_26 - F_16 ( V_12 ) ;
struct V_7 * V_79 , * V_80 ;
struct V_55 * V_56 ;
unsigned int V_24 ;
V_79 = NULL ;
F_44 () ;
V_56 = F_45 ( V_11 -> V_56 ) ;
if ( V_56 ) {
struct V_12 * V_81 ;
T_2 V_58 ;
if ( F_18 ( V_72 > 1 ) ) {
V_81 = F_48 ( V_11 , & V_72 ,
V_12 , V_28 , & V_29 ) ;
if ( ! V_81 )
goto V_68;
V_28 = 0 ;
} else {
V_81 = V_12 ;
}
if ( F_18 ( V_30 -> V_30 . V_66 ) )
goto V_68;
V_58 = F_38 ( V_19 , V_11 , V_56 ,
F_16 ( V_81 ) + V_28 , V_29 ) ;
switch ( V_58 ) {
case V_59 :
if ( F_18 ( V_81 != V_12 ) ) {
F_46 () ;
F_22 ( V_12 ) ;
V_79 = F_15 ( V_19 , V_11 , V_81 ,
0 , V_29 , V_39 ) ;
F_52 ( & V_11 -> V_82 , V_29 ) ;
return V_79 ;
}
break;
case V_60 :
F_52 ( & V_11 -> V_82 , V_29 ) ;
if ( F_18 ( V_81 != V_12 ) )
goto V_68;
F_46 () ;
goto V_69;
case V_64 :
default:
if ( F_18 ( V_81 != V_12 ) )
F_49 ( V_81 , 0 ) ;
F_52 ( & V_11 -> V_82 , V_29 ) ;
goto V_68;
}
}
F_46 () ;
V_24 = F_53 ( V_29 , F_12 ( V_75 ) ) ;
V_79 = F_15 ( V_19 , V_11 , V_12 , V_28 , V_29 , V_24 ) ;
V_80 = V_79 ;
if ( F_18 ( ! V_80 ) )
goto V_83;
while ( -- V_72 ) {
int V_84 ;
V_75 = ( unsigned long ) F_29 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_75 ) ) {
F_54 ( L_2 ,
V_22 -> V_40 , V_72 ,
F_51 ( V_19 -> V_20 ,
V_30 -> V_78 ) ) ;
V_22 -> V_70 . V_85 ++ ;
goto V_77;
}
V_26 = F_13 ( V_75 ) ;
V_12 = F_30 ( V_26 ) ;
V_84 = F_27 ( V_80 ) -> V_42 ;
if ( F_18 ( V_84 == V_38 ) ) {
struct V_7 * V_86 = F_55 ( 0 , V_54 ) ;
if ( F_18 ( ! V_86 ) )
goto V_83;
if ( V_80 == V_79 )
F_27 ( V_80 ) -> V_87 = V_86 ;
else
V_80 -> V_88 = V_86 ;
V_80 = V_86 ;
V_79 -> V_24 += V_86 -> V_24 ;
V_84 = 0 ;
}
V_24 = F_53 ( V_29 , F_12 ( V_75 ) ) ;
if ( V_80 != V_79 ) {
V_79 -> V_89 += V_29 ;
V_79 -> V_29 += V_29 ;
V_79 -> V_24 += V_24 ;
}
V_28 = V_26 - F_16 ( V_12 ) ;
if ( F_56 ( V_80 , V_84 , V_12 , V_28 ) ) {
F_22 ( V_12 ) ;
F_57 ( V_80 , V_84 - 1 ,
V_29 , V_24 ) ;
} else {
F_21 ( V_80 , V_84 , V_12 ,
V_28 , V_29 , V_24 ) ;
}
}
F_52 ( & V_11 -> V_82 , V_79 -> V_29 ) ;
return V_79 ;
V_68:
F_46 () ;
V_83:
F_22 ( V_12 ) ;
while ( -- V_72 ) {
V_75 = ( unsigned long ) F_29 ( V_11 -> V_2 , & V_29 ) ;
if ( F_18 ( ! V_75 ) ) {
F_54 ( L_3 ,
V_22 -> V_40 , V_72 ) ;
V_22 -> V_70 . V_85 ++ ;
break;
}
V_12 = F_30 ( F_13 ( V_75 ) ) ;
F_22 ( V_12 ) ;
}
V_77:
V_22 -> V_70 . V_71 ++ ;
F_24 ( V_79 ) ;
V_69:
return NULL ;
}
static void F_58 ( struct V_18 * V_19 , struct V_10 * V_11 ,
void * V_26 , unsigned int V_29 )
{
struct V_65 * V_22 = V_19 -> V_22 ;
struct V_90 * V_70 = F_59 ( V_19 -> V_70 ) ;
struct V_7 * V_8 ;
struct V_6 * V_30 ;
if ( F_18 ( V_29 < V_19 -> V_32 + V_91 ) ) {
F_54 ( L_4 , V_22 -> V_40 , V_29 ) ;
V_22 -> V_70 . V_85 ++ ;
if ( V_19 -> V_36 ) {
unsigned long V_75 = ( unsigned long ) V_26 ;
void * V_92 = F_13 ( V_75 ) ;
F_22 ( F_30 ( V_92 ) ) ;
} else if ( V_19 -> V_93 ) {
F_6 ( V_11 , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
return;
}
if ( V_19 -> V_36 )
V_8 = F_50 ( V_22 , V_19 , V_11 , ( unsigned long ) V_26 , V_29 ) ;
else if ( V_19 -> V_93 )
V_8 = F_47 ( V_22 , V_19 , V_11 , V_26 , V_29 ) ;
else
V_8 = F_42 ( V_22 , V_19 , V_11 , V_26 , V_29 ) ;
if ( F_18 ( ! V_8 ) )
return;
V_30 = F_5 ( V_8 ) ;
F_60 ( & V_70 -> V_94 ) ;
V_70 -> V_95 += V_8 -> V_29 ;
V_70 -> V_96 ++ ;
F_61 ( & V_70 -> V_94 ) ;
if ( V_30 -> V_30 . V_67 & V_97 )
V_8 -> V_98 = V_99 ;
if ( F_62 ( V_8 , & V_30 -> V_30 ,
F_63 ( V_19 -> V_20 ) ) ) {
F_64 ( L_5 ,
V_22 -> V_40 , V_30 -> V_30 . V_66 ,
V_30 -> V_30 . V_100 ) ;
goto V_101;
}
V_8 -> V_102 = F_65 ( V_8 , V_22 ) ;
F_54 ( L_6 ,
F_66 ( V_8 -> V_102 ) , V_8 -> V_29 , V_8 -> V_103 ) ;
F_67 ( & V_11 -> V_34 , V_8 ) ;
return;
V_101:
V_22 -> V_70 . V_104 ++ ;
F_24 ( V_8 ) ;
}
static int F_68 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_105 )
{
struct V_7 * V_8 ;
struct V_6 * V_30 ;
int V_50 ;
V_8 = F_69 ( V_19 -> V_22 , V_106 , V_105 ) ;
if ( F_18 ( ! V_8 ) )
return - V_107 ;
F_20 ( V_8 , V_106 ) ;
V_30 = F_5 ( V_8 ) ;
F_33 ( V_11 -> V_52 , 2 ) ;
F_34 ( V_11 -> V_52 , V_30 , V_19 -> V_32 ) ;
F_35 ( V_8 , V_11 -> V_52 + 1 , 0 , V_8 -> V_29 ) ;
V_50 = F_70 ( V_11 -> V_2 , V_11 -> V_52 , 2 , V_8 , V_105 ) ;
if ( V_50 < 0 )
F_24 ( V_8 ) ;
return V_50 ;
}
static int F_71 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_105 )
{
struct V_12 * V_108 , * V_109 = NULL ;
char * V_17 ;
int V_110 , V_50 , V_28 ;
F_33 ( V_11 -> V_52 , V_38 + 2 ) ;
for ( V_110 = V_38 + 1 ; V_110 > 1 ; -- V_110 ) {
V_108 = F_7 ( V_11 , V_105 ) ;
if ( ! V_108 ) {
if ( V_109 )
F_6 ( V_11 , V_109 ) ;
return - V_107 ;
}
F_34 ( & V_11 -> V_52 [ V_110 ] , F_16 ( V_108 ) , V_39 ) ;
V_108 -> V_14 = ( unsigned long ) V_109 ;
V_109 = V_108 ;
}
V_108 = F_7 ( V_11 , V_105 ) ;
if ( ! V_108 ) {
F_6 ( V_11 , V_109 ) ;
return - V_107 ;
}
V_17 = F_16 ( V_108 ) ;
F_34 ( & V_11 -> V_52 [ 0 ] , V_17 , V_19 -> V_32 ) ;
V_28 = sizeof( struct V_37 ) ;
F_34 ( & V_11 -> V_52 [ 1 ] , V_17 + V_28 , V_39 - V_28 ) ;
V_108 -> V_14 = ( unsigned long ) V_109 ;
V_50 = F_70 ( V_11 -> V_2 , V_11 -> V_52 , V_38 + 2 ,
V_108 , V_105 ) ;
if ( V_50 < 0 )
F_6 ( V_11 , V_108 ) ;
return V_50 ;
}
static unsigned int F_72 ( struct V_111 * V_112 )
{
const T_4 V_32 = sizeof( struct V_6 ) ;
unsigned int V_29 ;
V_29 = V_32 + F_73 (unsigned int, ewma_pkt_len_read(avg_pkt_len),
GOOD_PACKET_LEN, PAGE_SIZE - hdr_len) ;
return F_74 ( V_29 , V_25 ) ;
}
static int F_75 ( struct V_10 * V_11 , T_1 V_105 )
{
struct V_113 * V_114 = & V_11 -> V_114 ;
char * V_26 ;
unsigned long V_75 ;
int V_50 ;
unsigned int V_29 , V_115 ;
V_29 = F_72 ( & V_11 -> V_82 ) ;
if ( F_18 ( ! F_76 ( V_29 , V_114 , V_105 ) ) )
return - V_107 ;
V_26 = ( char * ) F_16 ( V_114 -> V_12 ) + V_114 -> V_28 ;
V_75 = F_14 ( V_26 , V_29 ) ;
F_77 ( V_114 -> V_12 ) ;
V_114 -> V_28 += V_29 ;
V_115 = V_114 -> V_27 - V_114 -> V_28 ;
if ( V_115 < V_29 ) {
V_29 += V_115 ;
V_114 -> V_28 += V_115 ;
}
F_32 ( V_11 -> V_52 , V_26 , V_29 ) ;
V_50 = F_70 ( V_11 -> V_2 , V_11 -> V_52 , 1 , ( void * ) V_75 , V_105 ) ;
if ( V_50 < 0 )
F_22 ( F_30 ( V_26 ) ) ;
return V_50 ;
}
static bool F_78 ( struct V_18 * V_19 , struct V_10 * V_11 ,
T_1 V_105 )
{
int V_50 ;
bool V_116 ;
V_105 |= V_117 ;
do {
if ( V_19 -> V_36 )
V_50 = F_75 ( V_11 , V_105 ) ;
else if ( V_19 -> V_93 )
V_50 = F_71 ( V_19 , V_11 , V_105 ) ;
else
V_50 = F_68 ( V_19 , V_11 , V_105 ) ;
V_116 = V_50 == - V_107 ;
if ( V_50 )
break;
} while ( V_11 -> V_2 -> V_118 );
F_37 ( V_11 -> V_2 ) ;
return ! V_116 ;
}
static void F_79 ( struct V_1 * V_119 )
{
struct V_18 * V_19 = V_119 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_119 ) ] ;
if ( F_80 ( & V_11 -> V_34 ) ) {
F_10 ( V_119 ) ;
F_81 ( & V_11 -> V_34 ) ;
}
}
static void F_82 ( struct V_10 * V_11 )
{
F_83 ( & V_11 -> V_34 ) ;
if ( F_80 ( & V_11 -> V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_84 () ;
F_81 ( & V_11 -> V_34 ) ;
F_85 () ;
}
}
static void F_86 ( struct V_120 * V_121 )
{
struct V_18 * V_19 =
F_87 ( V_121 , struct V_18 , V_122 . V_121 ) ;
bool V_123 ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_61 ; V_110 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_110 ] ;
F_88 ( & V_11 -> V_34 ) ;
V_123 = ! F_78 ( V_19 , V_11 , V_124 ) ;
F_82 ( V_11 ) ;
if ( V_123 )
F_89 ( & V_19 -> V_122 , V_125 / 2 ) ;
}
}
static int F_90 ( struct V_10 * V_11 , int V_126 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
unsigned int V_29 , V_127 = 0 ;
void * V_26 ;
while ( V_127 < V_126 &&
( V_26 = F_29 ( V_11 -> V_2 , & V_29 ) ) != NULL ) {
F_58 ( V_19 , V_11 , V_26 , V_29 ) ;
V_127 ++ ;
}
if ( V_11 -> V_2 -> V_118 > F_91 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_78 ( V_19 , V_11 , V_54 ) )
F_89 ( & V_19 -> V_122 , 0 ) ;
}
return V_127 ;
}
static int F_92 ( struct V_128 * V_34 , int V_126 )
{
struct V_10 * V_11 =
F_87 ( V_34 , struct V_10 , V_34 ) ;
unsigned int V_129 , V_127 ;
V_127 = F_90 ( V_11 , V_126 ) ;
if ( V_127 < V_126 ) {
V_129 = F_93 ( V_11 -> V_2 ) ;
F_94 ( V_34 , V_127 ) ;
if ( F_18 ( F_95 ( V_11 -> V_2 , V_129 ) ) &&
F_80 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
F_81 ( V_34 ) ;
}
}
return V_127 ;
}
static int F_96 ( struct V_128 * V_34 )
{
struct V_10 * V_11 =
F_87 ( V_34 , struct V_10 , V_34 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_129 , V_127 = 0 , V_126 = 4 ;
if ( ! ( V_19 -> V_130 & V_131 ) )
return V_132 ;
if ( ! F_80 ( V_34 ) )
return V_133 ;
F_10 ( V_11 -> V_2 ) ;
V_134:
V_127 += F_90 ( V_11 , V_126 ) ;
V_129 = F_93 ( V_11 -> V_2 ) ;
F_97 ( V_135 , & V_34 -> V_136 ) ;
if ( F_18 ( F_95 ( V_11 -> V_2 , V_129 ) ) &&
F_80 ( V_34 ) ) {
F_10 ( V_11 -> V_2 ) ;
if ( V_127 < V_126 ) {
V_126 -= V_127 ;
goto V_134;
} else {
F_81 ( V_34 ) ;
}
}
return V_127 ;
}
static int F_98 ( struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
if ( V_110 < V_19 -> V_61 )
if ( ! F_78 ( V_19 , & V_19 -> V_11 [ V_110 ] , V_124 ) )
F_89 ( & V_19 -> V_122 , 0 ) ;
F_82 ( & V_19 -> V_11 [ V_110 ] ) ;
}
return 0 ;
}
static void F_100 ( struct V_43 * V_44 )
{
struct V_7 * V_8 ;
unsigned int V_29 ;
struct V_18 * V_19 = V_44 -> V_2 -> V_20 -> V_21 ;
struct V_90 * V_70 = F_59 ( V_19 -> V_70 ) ;
while ( ( V_8 = F_29 ( V_44 -> V_2 , & V_29 ) ) != NULL ) {
F_54 ( L_7 , V_8 ) ;
F_60 ( & V_70 -> V_138 ) ;
V_70 -> V_139 += V_8 -> V_29 ;
V_70 -> V_140 ++ ;
F_61 ( & V_70 -> V_138 ) ;
F_101 ( V_8 ) ;
}
}
static int F_102 ( struct V_43 * V_44 , struct V_7 * V_8 )
{
struct V_6 * V_30 ;
const unsigned char * V_141 = ( (struct V_142 * ) V_8 -> V_47 ) -> V_143 ;
struct V_18 * V_19 = V_44 -> V_2 -> V_20 -> V_21 ;
unsigned V_48 ;
unsigned V_32 = V_19 -> V_32 ;
bool V_144 ;
F_54 ( L_8 , V_19 -> V_22 -> V_40 , V_8 , V_141 ) ;
V_144 = V_19 -> V_145 &&
! ( ( unsigned long ) V_8 -> V_47 & ( F_103 ( * V_30 ) - 1 ) ) &&
! F_104 ( V_8 ) && F_105 ( V_8 ) >= V_32 ;
if ( V_144 )
V_30 = (struct V_6 * ) ( V_8 -> V_47 - V_32 ) ;
else
V_30 = F_5 ( V_8 ) ;
if ( F_106 ( V_8 , & V_30 -> V_30 ,
F_63 ( V_19 -> V_20 ) , false ) )
F_107 () ;
if ( V_19 -> V_36 )
V_30 -> V_78 = 0 ;
F_33 ( V_44 -> V_52 , F_27 ( V_8 ) -> V_42 + ( V_144 ? 1 : 2 ) ) ;
if ( V_144 ) {
F_108 ( V_8 , V_32 ) ;
V_48 = F_35 ( V_8 , V_44 -> V_52 , 0 , V_8 -> V_29 ) ;
F_109 ( V_8 , V_32 ) ;
} else {
F_34 ( V_44 -> V_52 , V_30 , V_32 ) ;
V_48 = F_35 ( V_8 , V_44 -> V_52 + 1 , 0 , V_8 -> V_29 ) + 1 ;
}
return F_36 ( V_44 -> V_2 , V_44 -> V_52 , V_48 , V_8 , V_54 ) ;
}
static T_5 F_110 ( struct V_7 * V_8 , struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
int V_146 = F_111 ( V_8 ) ;
struct V_43 * V_44 = & V_19 -> V_44 [ V_146 ] ;
int V_50 ;
struct V_147 * V_4 = F_112 ( V_22 , V_146 ) ;
bool V_148 = ! V_8 -> V_149 ;
F_100 ( V_44 ) ;
F_113 ( V_8 ) ;
V_50 = F_102 ( V_44 , V_8 ) ;
if ( F_18 ( V_50 ) ) {
V_22 -> V_70 . V_150 ++ ;
if ( F_114 () )
F_115 ( & V_22 -> V_22 ,
L_9 , V_146 , V_50 ) ;
V_22 -> V_70 . V_151 ++ ;
F_101 ( V_8 ) ;
return V_152 ;
}
F_116 ( V_8 ) ;
F_117 ( V_8 ) ;
if ( V_44 -> V_2 -> V_118 < 2 + V_38 ) {
F_118 ( V_22 , V_146 ) ;
if ( F_18 ( ! F_119 ( V_44 -> V_2 ) ) ) {
F_100 ( V_44 ) ;
if ( V_44 -> V_2 -> V_118 >= 2 + V_38 ) {
F_120 ( V_22 , V_146 ) ;
F_10 ( V_44 -> V_2 ) ;
}
}
}
if ( V_148 || F_121 ( V_4 ) )
F_37 ( V_44 -> V_2 ) ;
return V_152 ;
}
static bool F_122 ( struct V_18 * V_19 , T_6 V_153 , T_6 V_154 ,
struct V_155 * V_156 )
{
struct V_155 * V_157 [ 4 ] , V_30 , V_158 ;
unsigned V_159 = 0 , V_160 ;
F_25 ( ! F_123 ( V_19 -> V_20 , V_161 ) ) ;
V_19 -> V_162 = ~ 0 ;
V_19 -> V_163 . V_153 = V_153 ;
V_19 -> V_163 . V_154 = V_154 ;
F_32 ( & V_30 , & V_19 -> V_163 , sizeof( V_19 -> V_163 ) ) ;
V_157 [ V_159 ++ ] = & V_30 ;
if ( V_156 )
V_157 [ V_159 ++ ] = V_156 ;
F_32 ( & V_158 , & V_19 -> V_162 , sizeof( V_19 -> V_162 ) ) ;
V_157 [ V_159 ] = & V_158 ;
F_25 ( V_159 + 1 > F_124 ( V_157 ) ) ;
F_125 ( V_19 -> V_164 , V_157 , V_159 , 1 , V_19 , V_54 ) ;
if ( F_18 ( ! F_37 ( V_19 -> V_164 ) ) )
return V_19 -> V_162 == V_165 ;
while ( ! F_29 ( V_19 -> V_164 , & V_160 ) &&
! F_126 ( V_19 -> V_164 ) )
F_127 () ;
return V_19 -> V_162 == V_165 ;
}
static int F_128 ( struct V_65 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
struct V_166 * V_20 = V_19 -> V_20 ;
int V_167 ;
struct V_168 * V_169 ;
struct V_155 V_52 ;
V_169 = F_129 ( sizeof( * V_169 ) , V_124 ) ;
if ( ! V_169 )
return - V_107 ;
memcpy ( V_169 , V_17 , sizeof( * V_169 ) ) ;
V_167 = F_130 ( V_22 , V_169 ) ;
if ( V_167 )
goto V_156;
if ( F_123 ( V_20 , V_170 ) ) {
F_32 ( & V_52 , V_169 -> V_171 , V_22 -> V_172 ) ;
if ( ! F_122 ( V_19 , V_173 ,
V_174 , & V_52 ) ) {
F_115 ( & V_20 -> V_22 ,
L_10 ) ;
V_167 = - V_175 ;
goto V_156;
}
} else if ( F_123 ( V_20 , V_176 ) &&
! F_123 ( V_20 , V_177 ) ) {
unsigned int V_110 ;
for ( V_110 = 0 ; V_110 < V_22 -> V_172 ; V_110 ++ )
F_131 ( V_20 ,
F_132 ( struct V_178 , V_179 ) +
V_110 , V_169 -> V_171 [ V_110 ] ) ;
}
F_133 ( V_22 , V_17 ) ;
V_167 = 0 ;
V_156:
F_134 ( V_169 ) ;
return V_167 ;
}
static struct V_180 * V_90 ( struct V_65 * V_22 ,
struct V_180 * V_181 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
int V_182 ;
unsigned int V_183 ;
F_135 (cpu) {
struct V_90 * V_70 = F_136 ( V_19 -> V_70 , V_182 ) ;
T_7 V_184 , V_185 , V_186 , V_187 ;
do {
V_183 = F_137 ( & V_70 -> V_138 ) ;
V_184 = V_70 -> V_140 ;
V_185 = V_70 -> V_139 ;
} while ( F_138 ( & V_70 -> V_138 , V_183 ) );
do {
V_183 = F_137 ( & V_70 -> V_94 ) ;
V_186 = V_70 -> V_96 ;
V_187 = V_70 -> V_95 ;
} while ( F_138 ( & V_70 -> V_94 , V_183 ) );
V_181 -> V_96 += V_186 ;
V_181 -> V_140 += V_184 ;
V_181 -> V_95 += V_187 ;
V_181 -> V_139 += V_185 ;
}
V_181 -> V_151 = V_22 -> V_70 . V_151 ;
V_181 -> V_150 = V_22 -> V_70 . V_150 ;
V_181 -> V_71 = V_22 -> V_70 . V_71 ;
V_181 -> V_85 = V_22 -> V_70 . V_85 ;
V_181 -> V_104 = V_22 -> V_70 . V_104 ;
return V_181 ;
}
static void F_139 ( struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_61 ; V_110 ++ )
F_140 ( & V_19 -> V_11 [ V_110 ] . V_34 ) ;
}
static void F_141 ( struct V_18 * V_19 )
{
F_142 () ;
if ( ! F_122 ( V_19 , V_188 ,
V_189 , NULL ) )
F_115 ( & V_19 -> V_22 -> V_22 , L_11 ) ;
F_143 () ;
}
static int F_144 ( struct V_18 * V_19 , T_3 V_190 )
{
struct V_155 V_52 ;
struct V_65 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_191 || ! F_123 ( V_19 -> V_20 , V_192 ) )
return 0 ;
V_19 -> V_193 . V_194 = F_145 ( V_19 -> V_20 , V_190 ) ;
F_32 ( & V_52 , & V_19 -> V_193 , sizeof( V_19 -> V_193 ) ) ;
if ( ! F_122 ( V_19 , V_195 ,
V_196 , & V_52 ) ) {
F_115 ( & V_22 -> V_22 , L_12 ,
V_190 ) ;
return - V_175 ;
} else {
V_19 -> V_61 = V_190 ;
if ( V_22 -> V_67 & V_197 )
F_89 ( & V_19 -> V_122 , 0 ) ;
}
return 0 ;
}
static int F_146 ( struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
int V_110 ;
F_147 ( & V_19 -> V_122 ) ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ )
F_88 ( & V_19 -> V_11 [ V_110 ] . V_34 ) ;
return 0 ;
}
static void F_148 ( struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
struct V_155 V_52 [ 2 ] ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
int V_202 ;
int V_203 ;
void * V_26 ;
int V_110 ;
if ( ! F_123 ( V_19 -> V_20 , V_204 ) )
return;
V_19 -> V_205 = ( ( V_22 -> V_67 & V_206 ) != 0 ) ;
V_19 -> V_207 = ( ( V_22 -> V_67 & V_208 ) != 0 ) ;
F_32 ( V_52 , & V_19 -> V_205 , sizeof( V_19 -> V_205 ) ) ;
if ( ! F_122 ( V_19 , V_209 ,
V_210 , V_52 ) )
F_115 ( & V_22 -> V_22 , L_13 ,
V_19 -> V_205 ? L_14 : L_15 ) ;
F_32 ( V_52 , & V_19 -> V_207 , sizeof( V_19 -> V_207 ) ) ;
if ( ! F_122 ( V_19 , V_209 ,
V_211 , V_52 ) )
F_115 ( & V_22 -> V_22 , L_16 ,
V_19 -> V_207 ? L_14 : L_15 ) ;
V_202 = F_149 ( V_22 ) ;
V_203 = F_150 ( V_22 ) ;
V_26 = F_151 ( ( ( V_202 + V_203 ) * V_212 ) +
( 2 * sizeof( V_199 -> V_213 ) ) , V_54 ) ;
V_199 = V_26 ;
if ( ! V_26 )
return;
F_33 ( V_52 , 2 ) ;
V_199 -> V_213 = F_152 ( V_19 -> V_20 , V_202 ) ;
V_110 = 0 ;
F_153 (ha, dev)
memcpy ( & V_199 -> V_214 [ V_110 ++ ] [ 0 ] , V_201 -> V_169 , V_212 ) ;
F_34 ( & V_52 [ 0 ] , V_199 ,
sizeof( V_199 -> V_213 ) + ( V_202 * V_212 ) ) ;
V_199 = ( void * ) & V_199 -> V_214 [ V_202 ] [ 0 ] ;
V_199 -> V_213 = F_152 ( V_19 -> V_20 , V_203 ) ;
V_110 = 0 ;
F_154 (ha, dev)
memcpy ( & V_199 -> V_214 [ V_110 ++ ] [ 0 ] , V_201 -> V_169 , V_212 ) ;
F_34 ( & V_52 [ 1 ] , V_199 ,
sizeof( V_199 -> V_213 ) + ( V_203 * V_212 ) ) ;
if ( ! F_122 ( V_19 , V_173 ,
V_215 , V_52 ) )
F_115 ( & V_22 -> V_22 , L_17 ) ;
F_134 ( V_26 ) ;
}
static int F_155 ( struct V_65 * V_22 ,
T_8 V_216 , T_3 V_217 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
struct V_155 V_52 ;
V_19 -> V_218 = V_217 ;
F_32 ( & V_52 , & V_19 -> V_218 , sizeof( V_19 -> V_218 ) ) ;
if ( ! F_122 ( V_19 , V_219 ,
V_220 , & V_52 ) )
F_115 ( & V_22 -> V_22 , L_18 , V_217 ) ;
return 0 ;
}
static int F_156 ( struct V_65 * V_22 ,
T_8 V_216 , T_3 V_217 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
struct V_155 V_52 ;
V_19 -> V_218 = V_217 ;
F_32 ( & V_52 , & V_19 -> V_218 , sizeof( V_19 -> V_218 ) ) ;
if ( ! F_122 ( V_19 , V_219 ,
V_221 , & V_52 ) )
F_115 ( & V_22 -> V_22 , L_19 , V_217 ) ;
return 0 ;
}
static void F_157 ( struct V_18 * V_19 , long V_222 )
{
int V_110 ;
if ( V_19 -> V_223 ) {
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
F_158 ( V_19 -> V_11 [ V_110 ] . V_2 , - 1 ) ;
F_158 ( V_19 -> V_44 [ V_110 ] . V_2 , - 1 ) ;
}
V_19 -> V_223 = false ;
}
}
static void F_159 ( struct V_18 * V_19 )
{
int V_110 ;
int V_182 ;
if ( V_19 -> V_61 == 1 ||
V_19 -> V_137 != F_160 () ) {
F_157 ( V_19 , - 1 ) ;
return;
}
V_110 = 0 ;
F_161 (cpu) {
F_158 ( V_19 -> V_11 [ V_110 ] . V_2 , V_182 ) ;
F_158 ( V_19 -> V_44 [ V_110 ] . V_2 , V_182 ) ;
F_162 ( V_19 -> V_22 , F_163 ( V_182 ) , V_110 ) ;
V_110 ++ ;
}
V_19 -> V_223 = true ;
}
static int F_164 ( unsigned int V_182 , struct V_224 * V_225 )
{
struct V_18 * V_19 = F_165 ( V_225 , struct V_18 ,
V_225 ) ;
F_159 ( V_19 ) ;
return 0 ;
}
static int F_166 ( unsigned int V_182 , struct V_224 * V_225 )
{
struct V_18 * V_19 = F_165 ( V_225 , struct V_18 ,
V_226 ) ;
F_159 ( V_19 ) ;
return 0 ;
}
static int F_167 ( unsigned int V_182 , struct V_224 * V_225 )
{
struct V_18 * V_19 = F_165 ( V_225 , struct V_18 ,
V_225 ) ;
F_157 ( V_19 , V_182 ) ;
return 0 ;
}
static int F_168 ( struct V_18 * V_19 )
{
int V_167 ;
V_167 = F_169 ( V_227 , & V_19 -> V_225 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_169 ( V_228 ,
& V_19 -> V_226 ) ;
if ( ! V_167 )
return V_167 ;
F_170 ( V_227 , & V_19 -> V_225 ) ;
return V_167 ;
}
static void F_171 ( struct V_18 * V_19 )
{
F_170 ( V_227 , & V_19 -> V_225 ) ;
F_170 ( V_228 ,
& V_19 -> V_226 ) ;
}
static void F_172 ( struct V_65 * V_22 ,
struct V_229 * V_230 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
V_230 -> V_231 = F_91 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_230 -> V_232 = F_91 ( V_19 -> V_44 [ 0 ] . V_2 ) ;
V_230 -> V_233 = V_230 -> V_231 ;
V_230 -> V_234 = V_230 -> V_232 ;
}
static void F_173 ( struct V_65 * V_22 ,
struct V_235 * V_236 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
struct V_166 * V_20 = V_19 -> V_20 ;
F_174 ( V_236 -> V_237 , V_238 , sizeof( V_236 -> V_237 ) ) ;
F_174 ( V_236 -> V_239 , V_240 , sizeof( V_236 -> V_239 ) ) ;
F_174 ( V_236 -> V_241 , F_175 ( V_20 ) , sizeof( V_236 -> V_241 ) ) ;
}
static int F_176 ( struct V_65 * V_22 ,
struct V_242 * V_243 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
T_3 V_190 = V_243 -> V_244 ;
int V_50 ;
if ( V_243 -> V_245 || V_243 -> V_246 || V_243 -> V_247 )
return - V_175 ;
if ( V_190 > V_19 -> V_137 || V_190 == 0 )
return - V_175 ;
if ( V_19 -> V_11 [ 0 ] . V_56 )
return - V_175 ;
F_177 () ;
V_50 = F_144 ( V_19 , V_190 ) ;
if ( ! V_50 ) {
F_178 ( V_22 , V_190 ) ;
F_179 ( V_22 , V_190 ) ;
F_159 ( V_19 ) ;
}
F_180 () ;
return V_50 ;
}
static void F_181 ( struct V_65 * V_22 ,
struct V_242 * V_243 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
V_243 -> V_244 = V_19 -> V_61 ;
V_243 -> V_248 = V_19 -> V_137 ;
V_243 -> V_249 = 0 ;
V_243 -> V_245 = 0 ;
V_243 -> V_246 = 0 ;
V_243 -> V_247 = 0 ;
}
static bool F_182 ( const struct V_250 * V_154 )
{
struct V_250 V_251 = * V_154 ;
struct V_250 V_252 = {} ;
F_183 ( & V_251 , 0 ) ;
V_252 . V_253 = V_254 ;
V_251 . V_255 = 0 ;
V_251 . V_256 = 0 ;
V_251 . V_154 = 0 ;
return ! memcmp ( & V_251 , & V_252 , sizeof( V_251 ) ) ;
}
static int F_184 ( struct V_65 * V_22 , struct V_250 * V_154 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
T_2 V_257 ;
V_257 = F_185 ( V_154 ) ;
if ( ! F_186 ( V_257 ) ||
! F_187 ( V_154 -> V_256 ) ||
! F_182 ( V_154 ) )
return - V_175 ;
V_19 -> V_257 = V_257 ;
V_19 -> V_256 = V_154 -> V_256 ;
return 0 ;
}
static int F_188 ( struct V_65 * V_22 , struct V_250 * V_154 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
F_183 ( V_154 , V_19 -> V_257 ) ;
V_154 -> V_256 = V_19 -> V_256 ;
V_154 -> V_253 = V_254 ;
return 0 ;
}
static void F_189 ( struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
V_19 -> V_257 = V_258 ;
V_19 -> V_256 = V_259 ;
}
static int F_190 ( struct V_65 * V_22 , struct V_55 * V_260 )
{
unsigned long int V_261 = V_39 - sizeof( struct V_37 ) ;
struct V_18 * V_19 = F_99 ( V_22 ) ;
struct V_55 * V_262 ;
T_3 V_263 = 0 , V_264 ;
int V_110 , V_50 ;
if ( V_260 && V_260 -> V_265 ) {
F_191 ( V_22 , L_20 ) ;
return - V_266 ;
}
if ( F_123 ( V_19 -> V_20 , V_267 ) ||
F_123 ( V_19 -> V_20 , V_268 ) ||
F_123 ( V_19 -> V_20 , V_269 ) ||
F_123 ( V_19 -> V_20 , V_270 ) ) {
F_191 ( V_22 , L_21 ) ;
return - V_266 ;
}
if ( V_19 -> V_36 && ! V_19 -> V_145 ) {
F_191 ( V_22 , L_22 ) ;
return - V_175 ;
}
if ( V_22 -> V_271 > V_261 ) {
F_191 ( V_22 , L_23 , V_261 ) ;
return - V_175 ;
}
V_264 = V_19 -> V_61 - V_19 -> V_62 ;
if ( V_260 )
V_263 = V_272 ;
if ( V_264 + V_263 > V_19 -> V_137 ) {
F_191 ( V_22 , L_24 ,
V_264 + V_263 , V_19 -> V_137 ) ;
return - V_107 ;
}
V_50 = F_144 ( V_19 , V_264 + V_263 ) ;
if ( V_50 ) {
F_115 ( & V_22 -> V_22 , L_25 ) ;
return V_50 ;
}
if ( V_260 ) {
V_260 = F_192 ( V_260 , V_19 -> V_137 - 1 ) ;
if ( F_193 ( V_260 ) ) {
F_144 ( V_19 , V_264 ) ;
return F_194 ( V_260 ) ;
}
}
V_19 -> V_62 = V_263 ;
F_179 ( V_22 , V_264 + V_263 ) ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
V_262 = F_195 ( V_19 -> V_11 [ V_110 ] . V_56 ) ;
F_196 ( V_19 -> V_11 [ V_110 ] . V_56 , V_260 ) ;
if ( V_262 )
F_197 ( V_262 ) ;
}
return 0 ;
}
static bool F_198 ( struct V_65 * V_22 )
{
struct V_18 * V_19 = F_99 ( V_22 ) ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
if ( V_19 -> V_11 [ V_110 ] . V_56 )
return true ;
}
return false ;
}
static int F_199 ( struct V_65 * V_22 , struct V_273 * V_46 )
{
switch ( V_46 -> V_274 ) {
case V_275 :
return F_190 ( V_22 , V_46 -> V_260 ) ;
case V_276 :
V_46 -> V_277 = F_198 ( V_22 ) ;
return 0 ;
default:
return - V_175 ;
}
}
static void F_200 ( struct V_120 * V_121 )
{
struct V_18 * V_19 =
F_87 ( V_121 , struct V_18 , V_278 ) ;
T_3 V_279 ;
if ( F_201 ( V_19 -> V_20 , V_280 ,
struct V_178 , V_130 , & V_279 ) < 0 )
return;
if ( V_279 & V_281 ) {
F_202 ( V_19 -> V_22 ) ;
F_141 ( V_19 ) ;
}
V_279 &= V_131 ;
if ( V_19 -> V_130 == V_279 )
return;
V_19 -> V_130 = V_279 ;
if ( V_19 -> V_130 & V_131 ) {
F_203 ( V_19 -> V_22 ) ;
F_204 ( V_19 -> V_22 ) ;
} else {
F_205 ( V_19 -> V_22 ) ;
F_206 ( V_19 -> V_22 ) ;
}
}
static void F_207 ( struct V_166 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_208 ( & V_19 -> V_278 ) ;
}
static void F_209 ( struct V_18 * V_19 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
F_210 ( & V_19 -> V_11 [ V_110 ] . V_34 ) ;
F_211 ( & V_19 -> V_11 [ V_110 ] . V_34 ) ;
}
F_212 () ;
F_134 ( V_19 -> V_11 ) ;
F_134 ( V_19 -> V_44 ) ;
}
static void F_213 ( struct V_18 * V_19 )
{
struct V_55 * V_262 ;
int V_110 ;
F_142 () ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
while ( V_19 -> V_11 [ V_110 ] . V_15 )
F_49 ( F_7 ( & V_19 -> V_11 [ V_110 ] , V_124 ) , 0 ) ;
V_262 = F_195 ( V_19 -> V_11 [ V_110 ] . V_56 ) ;
F_214 ( V_19 -> V_11 [ V_110 ] . V_56 , NULL ) ;
if ( V_262 )
F_197 ( V_262 ) ;
}
F_143 () ;
}
static void F_215 ( struct V_18 * V_19 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ )
if ( V_19 -> V_11 [ V_110 ] . V_114 . V_12 )
F_22 ( V_19 -> V_11 [ V_110 ] . V_114 . V_12 ) ;
}
static bool F_216 ( struct V_18 * V_19 , int V_282 )
{
if ( ! V_19 -> V_36 )
return false ;
if ( V_282 < ( V_19 -> V_61 - V_19 -> V_62 ) )
return false ;
else if ( V_282 < V_19 -> V_61 )
return true ;
else
return false ;
}
static void F_217 ( struct V_18 * V_19 )
{
void * V_26 ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
struct V_1 * V_2 = V_19 -> V_44 [ V_110 ] . V_2 ;
while ( ( V_26 = F_218 ( V_2 ) ) != NULL ) {
if ( ! F_216 ( V_19 , V_110 ) )
F_24 ( V_26 ) ;
else
F_22 ( F_30 ( V_26 ) ) ;
}
}
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_110 ] . V_2 ;
while ( ( V_26 = F_218 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_36 ) {
unsigned long V_75 = ( unsigned long ) V_26 ;
void * V_92 = F_13 ( V_75 ) ;
F_22 ( F_30 ( V_92 ) ) ;
} else if ( V_19 -> V_93 ) {
F_6 ( & V_19 -> V_11 [ V_110 ] , V_26 ) ;
} else {
F_24 ( V_26 ) ;
}
}
}
}
static void F_219 ( struct V_18 * V_19 )
{
struct V_166 * V_20 = V_19 -> V_20 ;
F_157 ( V_19 , - 1 ) ;
V_20 -> V_283 -> V_284 ( V_20 ) ;
F_209 ( V_19 ) ;
}
static int F_220 ( struct V_18 * V_19 )
{
T_9 * * V_285 ;
struct V_1 * * V_286 ;
int V_167 = - V_107 ;
int V_110 , V_287 ;
const char * * V_288 ;
V_287 = V_19 -> V_137 * 2 +
F_123 ( V_19 -> V_20 , V_161 ) ;
V_286 = F_151 ( V_287 * sizeof( * V_286 ) , V_124 ) ;
if ( ! V_286 )
goto V_289;
V_285 = F_129 ( V_287 * sizeof( * V_285 ) , V_124 ) ;
if ( ! V_285 )
goto V_290;
V_288 = F_129 ( V_287 * sizeof( * V_288 ) , V_124 ) ;
if ( ! V_288 )
goto V_291;
if ( V_19 -> V_191 ) {
V_285 [ V_287 - 1 ] = NULL ;
V_288 [ V_287 - 1 ] = L_26 ;
}
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
V_285 [ F_4 ( V_110 ) ] = F_79 ;
V_285 [ F_2 ( V_110 ) ] = F_9 ;
sprintf ( V_19 -> V_11 [ V_110 ] . V_40 , L_27 , V_110 ) ;
sprintf ( V_19 -> V_44 [ V_110 ] . V_40 , L_28 , V_110 ) ;
V_288 [ F_4 ( V_110 ) ] = V_19 -> V_11 [ V_110 ] . V_40 ;
V_288 [ F_2 ( V_110 ) ] = V_19 -> V_44 [ V_110 ] . V_40 ;
}
V_167 = V_19 -> V_20 -> V_283 -> V_292 ( V_19 -> V_20 , V_287 , V_286 , V_285 ,
V_288 ) ;
if ( V_167 )
goto V_293;
if ( V_19 -> V_191 ) {
V_19 -> V_164 = V_286 [ V_287 - 1 ] ;
if ( F_123 ( V_19 -> V_20 , V_294 ) )
V_19 -> V_22 -> V_295 |= V_296 ;
}
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
V_19 -> V_11 [ V_110 ] . V_2 = V_286 [ F_4 ( V_110 ) ] ;
V_19 -> V_44 [ V_110 ] . V_2 = V_286 [ F_2 ( V_110 ) ] ;
}
F_134 ( V_288 ) ;
F_134 ( V_285 ) ;
F_134 ( V_286 ) ;
return 0 ;
V_293:
F_134 ( V_288 ) ;
V_291:
F_134 ( V_285 ) ;
V_290:
F_134 ( V_286 ) ;
V_289:
return V_167 ;
}
static int F_221 ( struct V_18 * V_19 )
{
int V_110 ;
V_19 -> V_44 = F_151 ( sizeof( * V_19 -> V_44 ) * V_19 -> V_137 , V_124 ) ;
if ( ! V_19 -> V_44 )
goto V_297;
V_19 -> V_11 = F_151 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_137 , V_124 ) ;
if ( ! V_19 -> V_11 )
goto V_298;
F_222 ( & V_19 -> V_122 , F_86 ) ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ ) {
V_19 -> V_11 [ V_110 ] . V_15 = NULL ;
F_223 ( V_19 -> V_22 , & V_19 -> V_11 [ V_110 ] . V_34 , F_92 ,
V_299 ) ;
F_33 ( V_19 -> V_11 [ V_110 ] . V_52 , F_124 ( V_19 -> V_11 [ V_110 ] . V_52 ) ) ;
F_224 ( & V_19 -> V_11 [ V_110 ] . V_82 ) ;
F_33 ( V_19 -> V_44 [ V_110 ] . V_52 , F_124 ( V_19 -> V_44 [ V_110 ] . V_52 ) ) ;
}
return 0 ;
V_298:
F_134 ( V_19 -> V_44 ) ;
V_297:
return - V_107 ;
}
static int F_225 ( struct V_18 * V_19 )
{
int V_167 ;
V_167 = F_221 ( V_19 ) ;
if ( V_167 )
goto V_50;
V_167 = F_220 ( V_19 ) ;
if ( V_167 )
goto V_300;
F_177 () ;
F_159 ( V_19 ) ;
F_180 () ;
return 0 ;
V_300:
F_209 ( V_19 ) ;
V_50:
return V_167 ;
}
static T_10 F_226 ( struct V_301 * V_302 ,
struct V_303 * V_304 , char * V_26 )
{
struct V_18 * V_19 = F_99 ( V_302 -> V_22 ) ;
unsigned int V_305 = F_227 ( V_302 ) ;
struct V_111 * V_306 ;
F_25 ( V_305 >= V_19 -> V_137 ) ;
V_306 = & V_19 -> V_11 [ V_305 ] . V_82 ;
return sprintf ( V_26 , L_29 , F_72 ( V_306 ) ) ;
}
static bool F_228 ( struct V_166 * V_20 ,
unsigned int V_307 ,
const char * V_308 , const char * V_309 )
{
if ( ! F_123 ( V_20 , V_307 ) )
return false ;
F_229 ( & V_20 -> V_22 , L_30 ,
V_308 , V_309 ) ;
return true ;
}
static bool F_230 ( struct V_166 * V_20 )
{
if ( ! F_123 ( V_20 , V_161 ) &&
( F_231 ( V_20 , V_204 ,
L_31 ) ||
F_231 ( V_20 , V_294 ,
L_31 ) ||
F_231 ( V_20 , V_310 ,
L_31 ) ||
F_231 ( V_20 , V_192 , L_31 ) ||
F_231 ( V_20 , V_170 ,
L_31 ) ) ) {
return false ;
}
return true ;
}
static int F_232 ( struct V_166 * V_20 )
{
int V_110 , V_50 ;
struct V_65 * V_22 ;
struct V_18 * V_19 ;
T_3 V_137 ;
int V_271 ;
if ( ! V_20 -> V_283 -> V_311 ) {
F_229 ( & V_20 -> V_22 , L_32 ,
V_312 ) ;
return - V_175 ;
}
if ( ! F_230 ( V_20 ) )
return - V_175 ;
V_50 = F_201 ( V_20 , V_192 ,
struct V_178 ,
V_313 , & V_137 ) ;
if ( V_50 || V_137 < V_314 ||
V_137 > V_315 ||
! F_123 ( V_20 , V_161 ) )
V_137 = 1 ;
V_22 = F_233 ( sizeof( struct V_18 ) , V_137 ) ;
if ( ! V_22 )
return - V_107 ;
V_22 -> V_316 |= V_317 | V_318 ;
V_22 -> V_319 = & V_320 ;
V_22 -> V_295 = V_321 ;
V_22 -> V_322 = & V_323 ;
F_234 ( V_22 , & V_20 -> V_22 ) ;
if ( F_123 ( V_20 , V_324 ) ) {
V_22 -> V_325 |= V_326 | V_327 ;
if ( V_328 )
V_22 -> V_295 |= V_326 | V_327 ;
if ( F_123 ( V_20 , V_329 ) ) {
V_22 -> V_325 |= V_330 | V_331
| V_332 | V_333 ;
}
if ( F_123 ( V_20 , V_334 ) )
V_22 -> V_325 |= V_330 ;
if ( F_123 ( V_20 , V_335 ) )
V_22 -> V_325 |= V_333 ;
if ( F_123 ( V_20 , V_336 ) )
V_22 -> V_325 |= V_332 ;
if ( F_123 ( V_20 , V_337 ) )
V_22 -> V_325 |= V_331 ;
V_22 -> V_295 |= V_338 ;
if ( V_339 )
V_22 -> V_295 |= V_22 -> V_325 & ( V_340 | V_331 ) ;
}
if ( F_123 ( V_20 , V_341 ) )
V_22 -> V_295 |= V_342 ;
V_22 -> V_343 = V_22 -> V_295 ;
V_22 -> V_344 = V_345 ;
V_22 -> V_346 = V_347 ;
if ( F_123 ( V_20 , V_176 ) )
F_235 ( V_20 ,
F_132 ( struct V_178 , V_179 ) ,
V_22 -> V_348 , V_22 -> V_172 ) ;
else
F_236 ( V_22 ) ;
V_19 = F_99 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_70 = F_237 ( struct V_90 ) ;
V_50 = - V_107 ;
if ( V_19 -> V_70 == NULL )
goto free;
F_135 (i) {
struct V_90 * V_90 ;
V_90 = F_136 ( V_19 -> V_70 , V_110 ) ;
F_238 ( & V_90 -> V_138 ) ;
F_238 ( & V_90 -> V_94 ) ;
}
F_239 ( & V_19 -> V_278 , F_200 ) ;
if ( F_123 ( V_20 , V_267 ) ||
F_123 ( V_20 , V_268 ) ||
F_123 ( V_20 , V_269 ) ||
F_123 ( V_20 , V_270 ) )
V_19 -> V_93 = true ;
if ( F_123 ( V_20 , V_349 ) )
V_19 -> V_36 = true ;
if ( F_123 ( V_20 , V_349 ) ||
F_123 ( V_20 , V_177 ) )
V_19 -> V_32 = sizeof( struct V_6 ) ;
else
V_19 -> V_32 = sizeof( struct V_350 ) ;
if ( F_123 ( V_20 , V_351 ) ||
F_123 ( V_20 , V_177 ) )
V_19 -> V_145 = true ;
if ( F_123 ( V_20 , V_161 ) )
V_19 -> V_191 = true ;
if ( F_123 ( V_20 , V_352 ) ) {
V_271 = F_240 ( V_20 ,
F_132 ( struct V_178 ,
V_271 ) ) ;
if ( V_271 < V_22 -> V_344 ) {
F_241 ( V_20 , V_352 ) ;
} else {
V_22 -> V_271 = V_271 ;
V_22 -> V_346 = V_271 ;
}
}
if ( V_19 -> V_145 )
V_22 -> V_353 = V_19 -> V_32 ;
if ( F_160 () >= V_137 )
V_19 -> V_61 = V_137 ;
else
V_19 -> V_61 = F_160 () ;
V_19 -> V_137 = V_137 ;
V_50 = F_225 ( V_19 ) ;
if ( V_50 )
goto V_354;
#ifdef F_242
if ( V_19 -> V_36 )
V_22 -> V_355 = & V_356 ;
#endif
F_178 ( V_22 , V_19 -> V_61 ) ;
F_179 ( V_22 , V_19 -> V_61 ) ;
F_189 ( V_22 ) ;
V_50 = F_243 ( V_22 ) ;
if ( V_50 ) {
F_54 ( L_33 ) ;
goto V_357;
}
F_244 ( V_20 ) ;
V_50 = F_168 ( V_19 ) ;
if ( V_50 ) {
F_54 ( L_34 ) ;
goto V_358;
}
F_142 () ;
F_144 ( V_19 , V_19 -> V_61 ) ;
F_143 () ;
if ( F_123 ( V_19 -> V_20 , V_280 ) ) {
F_205 ( V_22 ) ;
F_208 ( & V_19 -> V_278 ) ;
} else {
V_19 -> V_130 = V_131 ;
F_203 ( V_22 ) ;
}
F_54 ( L_35 ,
V_22 -> V_40 , V_137 ) ;
return 0 ;
V_358:
V_19 -> V_20 -> V_283 -> V_359 ( V_20 ) ;
F_245 ( V_22 ) ;
V_357:
F_147 ( & V_19 -> V_122 ) ;
F_215 ( V_19 ) ;
F_219 ( V_19 ) ;
V_354:
F_246 ( V_19 -> V_70 ) ;
free:
F_247 ( V_22 ) ;
return V_50 ;
}
static void F_248 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_283 -> V_359 ( V_19 -> V_20 ) ;
F_217 ( V_19 ) ;
F_213 ( V_19 ) ;
F_215 ( V_19 ) ;
F_219 ( V_19 ) ;
}
static void F_249 ( struct V_166 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_171 ( V_19 ) ;
F_250 ( & V_19 -> V_278 ) ;
F_245 ( V_19 -> V_22 ) ;
F_248 ( V_19 ) ;
F_246 ( V_19 -> V_70 ) ;
F_247 ( V_19 -> V_22 ) ;
}
static int F_251 ( struct V_166 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_110 ;
F_171 ( V_19 ) ;
F_250 ( & V_19 -> V_278 ) ;
F_252 ( V_19 -> V_22 ) ;
F_147 ( & V_19 -> V_122 ) ;
if ( F_253 ( V_19 -> V_22 ) ) {
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ )
F_88 ( & V_19 -> V_11 [ V_110 ] . V_34 ) ;
}
F_248 ( V_19 ) ;
return 0 ;
}
static int F_254 ( struct V_166 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_50 , V_110 ;
V_50 = F_225 ( V_19 ) ;
if ( V_50 )
return V_50 ;
F_244 ( V_20 ) ;
if ( F_253 ( V_19 -> V_22 ) ) {
for ( V_110 = 0 ; V_110 < V_19 -> V_61 ; V_110 ++ )
if ( ! F_78 ( V_19 , & V_19 -> V_11 [ V_110 ] , V_124 ) )
F_89 ( & V_19 -> V_122 , 0 ) ;
for ( V_110 = 0 ; V_110 < V_19 -> V_137 ; V_110 ++ )
F_82 ( & V_19 -> V_11 [ V_110 ] ) ;
}
F_255 ( V_19 -> V_22 ) ;
F_142 () ;
F_144 ( V_19 , V_19 -> V_61 ) ;
F_143 () ;
V_50 = F_168 ( V_19 ) ;
if ( V_50 )
return V_50 ;
return 0 ;
}
static T_11 int F_256 ( void )
{
int V_167 ;
V_167 = F_257 ( V_360 , L_36 ,
F_164 ,
F_167 ) ;
if ( V_167 < 0 )
goto V_156;
V_227 = V_167 ;
V_167 = F_257 ( V_228 , L_37 ,
NULL , F_166 ) ;
if ( V_167 )
goto V_361;
V_167 = F_258 ( & V_362 ) ;
if ( V_167 )
goto V_363;
return 0 ;
V_363:
F_259 ( V_228 ) ;
V_361:
F_259 ( V_227 ) ;
V_156:
return V_167 ;
}
static T_12 void F_260 ( void )
{
F_259 ( V_228 ) ;
F_259 ( V_227 ) ;
F_261 ( & V_362 ) ;
}
