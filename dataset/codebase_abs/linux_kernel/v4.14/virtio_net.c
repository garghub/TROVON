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
static void * F_20 ( unsigned int V_29 ,
unsigned int V_30 )
{
return ( void * ) ( unsigned long ) ( ( V_30 << V_31 ) | V_29 ) ;
}
static unsigned int F_21 ( void * V_32 )
{
return ( unsigned long ) V_32 >> V_31 ;
}
static unsigned int F_22 ( void * V_32 )
{
return ( unsigned long ) V_32 & ( ( 1 << V_31 ) - 1 ) ;
}
static struct V_7 * F_23 ( struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_12 * V_12 , unsigned int V_33 ,
unsigned int V_34 , unsigned int V_29 )
{
struct V_7 * V_8 ;
struct V_6 * V_35 ;
unsigned int V_36 , V_37 , V_38 ;
char * V_17 ;
V_17 = F_24 ( V_12 ) + V_33 ;
V_8 = F_25 ( & V_11 -> V_19 , V_39 ) ;
if ( F_16 ( ! V_8 ) )
return NULL ;
V_35 = F_5 ( V_8 ) ;
V_37 = V_23 -> V_37 ;
if ( V_23 -> V_40 )
V_38 = sizeof( * V_35 ) ;
else
V_38 = sizeof( struct V_41 ) ;
memcpy ( V_35 , V_17 , V_37 ) ;
V_34 -= V_37 ;
V_33 += V_38 ;
V_17 += V_38 ;
V_36 = V_34 ;
if ( V_36 > F_26 ( V_8 ) )
V_36 = F_26 ( V_8 ) ;
F_27 ( V_8 , V_17 , V_36 ) ;
V_34 -= V_36 ;
V_33 += V_36 ;
if ( V_23 -> V_40 ) {
if ( V_34 )
F_28 ( V_8 , 0 , V_12 , V_33 , V_34 , V_29 ) ;
else
F_29 ( V_12 ) ;
return V_8 ;
}
if ( F_16 ( V_34 > V_42 * V_43 ) ) {
F_30 ( L_1 , V_8 -> V_28 -> V_44 ) ;
F_31 ( V_8 ) ;
return NULL ;
}
F_32 ( V_33 >= V_43 ) ;
while ( V_34 ) {
unsigned int V_45 = F_33 ( ( unsigned ) V_43 - V_33 , V_34 ) ;
F_28 ( V_8 , F_34 ( V_8 ) -> V_46 , V_12 , V_33 ,
V_45 , V_29 ) ;
V_34 -= V_45 ;
V_12 = (struct V_12 * ) V_12 -> V_14 ;
V_33 = 0 ;
}
if ( V_12 )
F_6 ( V_11 , V_12 ) ;
return V_8 ;
}
static bool F_35 ( struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_6 * V_35 ;
unsigned int V_34 ;
struct V_49 * V_26 ;
unsigned int V_50 ;
void * V_51 ;
int V_52 ;
V_50 = V_23 -> V_53 - V_23 -> V_54 + F_36 () ;
V_26 = & V_23 -> V_26 [ V_50 ] ;
while ( ( V_51 = F_37 ( V_26 -> V_2 , & V_34 ) ) != NULL ) {
struct V_12 * V_55 = F_38 ( V_51 ) ;
F_29 ( V_55 ) ;
}
V_48 -> V_56 -= V_23 -> V_37 ;
V_35 = V_48 -> V_56 ;
memset ( V_35 , 0 , V_23 -> V_37 ) ;
F_39 ( V_26 -> V_57 , V_48 -> V_56 , V_48 -> V_58 - V_48 -> V_56 ) ;
V_52 = F_40 ( V_26 -> V_2 , V_26 -> V_57 , 1 , V_48 -> V_56 , V_59 ) ;
if ( F_16 ( V_52 ) ) {
struct V_12 * V_12 = F_38 ( V_48 -> V_56 ) ;
F_29 ( V_12 ) ;
return false ;
}
F_41 ( V_26 -> V_2 ) ;
return true ;
}
static unsigned int F_42 ( struct V_22 * V_23 )
{
return V_23 -> V_54 ? V_60 : 0 ;
}
static struct V_12 * F_43 ( struct V_10 * V_11 ,
T_2 * V_61 ,
struct V_12 * V_17 ,
int V_33 ,
int V_62 ,
unsigned int * V_34 )
{
struct V_12 * V_12 = F_8 ( V_59 ) ;
if ( ! V_12 )
return NULL ;
memcpy ( F_24 ( V_12 ) + V_62 , F_24 ( V_17 ) + V_33 , * V_34 ) ;
V_62 += * V_34 ;
while ( -- * V_61 ) {
unsigned int V_63 ;
void * V_64 ;
int V_65 ;
V_64 = F_37 ( V_11 -> V_2 , & V_63 ) ;
if ( F_16 ( ! V_64 ) )
goto V_66;
V_17 = F_38 ( V_64 ) ;
V_65 = V_64 - F_24 ( V_17 ) ;
if ( ( V_62 + V_63 ) > V_43 ) {
F_29 ( V_17 ) ;
goto V_66;
}
memcpy ( F_24 ( V_12 ) + V_62 ,
F_24 ( V_17 ) + V_65 , V_63 ) ;
V_62 += V_63 ;
F_29 ( V_17 ) ;
}
* V_34 = V_62 - V_60 ;
return V_12 ;
V_66:
F_44 ( V_12 , 0 ) ;
return NULL ;
}
static struct V_7 * F_45 ( struct V_67 * V_28 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
void * V_64 , void * V_68 ,
unsigned int V_34 )
{
struct V_7 * V_8 ;
struct V_69 * V_70 ;
unsigned int V_71 = ( unsigned long ) V_68 ;
unsigned int V_72 = V_73 + V_71 ;
unsigned int V_30 = V_23 -> V_37 + V_72 ;
unsigned int V_63 = F_46 ( V_74 + V_30 ) +
F_46 ( sizeof( struct V_75 ) ) ;
struct V_12 * V_12 = F_38 ( V_64 ) ;
unsigned int V_76 = 0 ;
struct V_12 * V_77 ;
V_34 -= V_23 -> V_37 ;
F_47 () ;
V_70 = F_48 ( V_11 -> V_70 ) ;
if ( V_70 ) {
struct V_6 * V_35 = V_64 + V_72 ;
struct V_47 V_48 ;
void * V_78 ;
T_3 V_79 ;
if ( F_16 ( V_35 -> V_35 . V_80 || V_35 -> V_35 . V_81 ) )
goto V_82;
if ( F_16 ( V_71 < F_42 ( V_23 ) ) ) {
int V_33 = V_64 - F_24 ( V_12 ) + V_72 ;
unsigned int V_83 = V_34 + V_23 -> V_37 ;
T_2 V_61 = 1 ;
V_71 = F_42 ( V_23 ) ;
V_72 = V_73 + V_71 ;
V_30 = V_23 -> V_37 + V_72 ;
V_63 = F_46 ( V_74 + V_30 ) +
F_46 ( sizeof( struct V_75 ) ) ;
V_77 = F_43 ( V_11 , & V_61 , V_12 ,
V_33 , V_72 ,
& V_83 ) ;
if ( ! V_77 )
goto V_82;
V_64 = F_24 ( V_77 ) ;
F_29 ( V_12 ) ;
V_12 = V_77 ;
}
V_48 . V_84 = V_64 + V_73 + V_23 -> V_37 ;
V_48 . V_56 = V_48 . V_84 + V_71 ;
V_48 . V_58 = V_48 . V_56 + V_34 ;
V_78 = V_48 . V_56 ;
V_79 = F_49 ( V_70 , & V_48 ) ;
switch ( V_79 ) {
case V_85 :
V_76 = V_78 - V_48 . V_56 ;
break;
case V_86 :
if ( F_16 ( ! F_35 ( V_23 , V_11 , & V_48 ) ) )
F_50 ( V_23 -> V_28 , V_70 , V_79 ) ;
F_51 () ;
goto V_87;
default:
F_52 ( V_79 ) ;
case V_88 :
F_50 ( V_23 -> V_28 , V_70 , V_79 ) ;
case V_89 :
goto V_82;
}
}
F_51 () ;
V_8 = F_53 ( V_64 , V_63 ) ;
if ( ! V_8 ) {
F_29 ( V_12 ) ;
goto V_52;
}
F_54 ( V_8 , V_30 - V_76 ) ;
F_55 ( V_8 , V_34 + V_76 ) ;
if ( ! V_76 ) {
V_64 += V_72 ;
memcpy ( F_5 ( V_8 ) , V_64 , V_23 -> V_37 ) ;
}
V_52:
return V_8 ;
V_82:
F_51 () ;
V_28 -> V_90 . V_91 ++ ;
F_29 ( V_12 ) ;
V_87:
return NULL ;
}
static struct V_7 * F_56 ( struct V_67 * V_28 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
void * V_64 ,
unsigned int V_34 )
{
struct V_12 * V_12 = V_64 ;
struct V_7 * V_8 = F_23 ( V_23 , V_11 , V_12 , 0 , V_34 , V_43 ) ;
if ( F_16 ( ! V_8 ) )
goto V_52;
return V_8 ;
V_52:
V_28 -> V_90 . V_91 ++ ;
F_6 ( V_11 , V_12 ) ;
return NULL ;
}
static struct V_7 * F_57 ( struct V_67 * V_28 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
void * V_64 ,
void * V_68 ,
unsigned int V_34 )
{
struct V_6 * V_35 = V_64 ;
T_2 V_61 = F_58 ( V_23 -> V_24 , V_35 -> V_92 ) ;
struct V_12 * V_12 = F_38 ( V_64 ) ;
int V_33 = V_64 - F_24 ( V_12 ) ;
struct V_7 * V_93 , * V_94 ;
struct V_69 * V_70 ;
unsigned int V_29 ;
unsigned int V_30 = F_21 ( V_68 ) ;
V_93 = NULL ;
F_47 () ;
V_70 = F_48 ( V_11 -> V_70 ) ;
if ( V_70 ) {
struct V_12 * V_77 ;
struct V_47 V_48 ;
void * V_56 ;
T_3 V_79 ;
if ( F_16 ( V_61 > 1 ||
V_30 < F_42 ( V_23 ) ) ) {
V_77 = F_43 ( V_11 , & V_61 ,
V_12 , V_33 ,
V_60 ,
& V_34 ) ;
if ( ! V_77 )
goto V_82;
V_33 = V_60 ;
} else {
V_77 = V_12 ;
}
if ( F_16 ( V_35 -> V_35 . V_80 ) )
goto V_82;
V_56 = F_24 ( V_77 ) + V_33 ;
V_48 . V_84 = V_56 - V_60 + V_23 -> V_37 ;
V_48 . V_56 = V_56 + V_23 -> V_37 ;
V_48 . V_58 = V_48 . V_56 + ( V_34 - V_23 -> V_37 ) ;
V_79 = F_49 ( V_70 , & V_48 ) ;
switch ( V_79 ) {
case V_85 :
V_33 = V_48 . V_56 -
F_24 ( V_77 ) - V_23 -> V_37 ;
if ( F_16 ( V_77 != V_12 ) ) {
F_51 () ;
F_29 ( V_12 ) ;
V_93 = F_23 ( V_23 , V_11 , V_77 ,
V_33 , V_34 , V_43 ) ;
F_59 ( & V_11 -> V_95 , V_34 ) ;
return V_93 ;
}
break;
case V_86 :
if ( F_16 ( ! F_35 ( V_23 , V_11 , & V_48 ) ) )
F_50 ( V_23 -> V_28 , V_70 , V_79 ) ;
F_59 ( & V_11 -> V_95 , V_34 ) ;
if ( F_16 ( V_77 != V_12 ) )
goto V_82;
F_51 () ;
goto V_87;
default:
F_52 ( V_79 ) ;
case V_88 :
F_50 ( V_23 -> V_28 , V_70 , V_79 ) ;
case V_89 :
if ( F_16 ( V_77 != V_12 ) )
F_44 ( V_77 , 0 ) ;
F_59 ( & V_11 -> V_95 , V_34 ) ;
goto V_82;
}
}
F_51 () ;
V_29 = F_22 ( V_68 ) ;
if ( F_16 ( V_34 > V_29 ) ) {
F_60 ( L_2 ,
V_28 -> V_44 , V_34 , ( unsigned long ) V_68 ) ;
V_28 -> V_90 . V_96 ++ ;
goto V_97;
}
V_93 = F_23 ( V_23 , V_11 , V_12 , V_33 , V_34 , V_29 ) ;
V_94 = V_93 ;
if ( F_16 ( ! V_94 ) )
goto V_97;
while ( -- V_61 ) {
int V_98 ;
V_64 = F_61 ( V_11 -> V_2 , & V_34 , & V_68 ) ;
if ( F_16 ( ! V_68 ) ) {
F_60 ( L_3 ,
V_28 -> V_44 , V_61 ,
F_58 ( V_23 -> V_24 ,
V_35 -> V_92 ) ) ;
V_28 -> V_90 . V_96 ++ ;
goto V_66;
}
V_12 = F_38 ( V_64 ) ;
V_29 = F_22 ( V_68 ) ;
if ( F_16 ( V_34 > V_29 ) ) {
F_60 ( L_2 ,
V_28 -> V_44 , V_34 , ( unsigned long ) V_68 ) ;
V_28 -> V_90 . V_96 ++ ;
goto V_97;
}
V_98 = F_34 ( V_94 ) -> V_46 ;
if ( F_16 ( V_98 == V_42 ) ) {
struct V_7 * V_99 = F_62 ( 0 , V_59 ) ;
if ( F_16 ( ! V_99 ) )
goto V_97;
if ( V_94 == V_93 )
F_34 ( V_94 ) -> V_100 = V_99 ;
else
V_94 -> V_101 = V_99 ;
V_94 = V_99 ;
V_93 -> V_29 += V_99 -> V_29 ;
V_98 = 0 ;
}
if ( V_94 != V_93 ) {
V_93 -> V_102 += V_34 ;
V_93 -> V_34 += V_34 ;
V_93 -> V_29 += V_29 ;
}
V_33 = V_64 - F_24 ( V_12 ) ;
if ( F_63 ( V_94 , V_98 , V_12 , V_33 ) ) {
F_29 ( V_12 ) ;
F_64 ( V_94 , V_98 - 1 ,
V_34 , V_29 ) ;
} else {
F_28 ( V_94 , V_98 , V_12 ,
V_33 , V_34 , V_29 ) ;
}
}
F_59 ( & V_11 -> V_95 , V_93 -> V_34 ) ;
return V_93 ;
V_82:
F_51 () ;
V_97:
F_29 ( V_12 ) ;
while ( -- V_61 ) {
V_64 = F_37 ( V_11 -> V_2 , & V_34 ) ;
if ( F_16 ( ! V_64 ) ) {
F_60 ( L_4 ,
V_28 -> V_44 , V_61 ) ;
V_28 -> V_90 . V_96 ++ ;
break;
}
V_12 = F_38 ( V_64 ) ;
F_29 ( V_12 ) ;
}
V_66:
V_28 -> V_90 . V_91 ++ ;
F_31 ( V_93 ) ;
V_87:
return NULL ;
}
static int F_65 ( struct V_22 * V_23 , struct V_10 * V_11 ,
void * V_64 , unsigned int V_34 , void * * V_68 )
{
struct V_67 * V_28 = V_23 -> V_28 ;
struct V_7 * V_8 ;
struct V_6 * V_35 ;
int V_103 ;
if ( F_16 ( V_34 < V_23 -> V_37 + V_104 ) ) {
F_60 ( L_5 , V_28 -> V_44 , V_34 ) ;
V_28 -> V_90 . V_96 ++ ;
if ( V_23 -> V_40 ) {
F_29 ( F_38 ( V_64 ) ) ;
} else if ( V_23 -> V_105 ) {
F_6 ( V_11 , V_64 ) ;
} else {
F_29 ( F_38 ( V_64 ) ) ;
}
return 0 ;
}
if ( V_23 -> V_40 )
V_8 = F_57 ( V_28 , V_23 , V_11 , V_64 , V_68 , V_34 ) ;
else if ( V_23 -> V_105 )
V_8 = F_56 ( V_28 , V_23 , V_11 , V_64 , V_34 ) ;
else
V_8 = F_45 ( V_28 , V_23 , V_11 , V_64 , V_68 , V_34 ) ;
if ( F_16 ( ! V_8 ) )
return 0 ;
V_35 = F_5 ( V_8 ) ;
V_103 = V_8 -> V_34 ;
if ( V_35 -> V_35 . V_81 & V_106 )
V_8 -> V_107 = V_108 ;
if ( F_66 ( V_8 , & V_35 -> V_35 ,
F_67 ( V_23 -> V_24 ) ) ) {
F_68 ( L_6 ,
V_28 -> V_44 , V_35 -> V_35 . V_80 ,
V_35 -> V_35 . V_109 ) ;
goto V_110;
}
V_8 -> V_111 = F_69 ( V_8 , V_28 ) ;
F_60 ( L_7 ,
F_70 ( V_8 -> V_111 ) , V_8 -> V_34 , V_8 -> V_112 ) ;
F_71 ( & V_11 -> V_19 , V_8 ) ;
return V_103 ;
V_110:
V_28 -> V_90 . V_113 ++ ;
F_31 ( V_8 ) ;
return 0 ;
}
static int F_72 ( struct V_22 * V_23 , struct V_10 * V_11 ,
T_1 V_114 )
{
struct V_115 * V_116 = & V_11 -> V_116 ;
char * V_64 ;
unsigned int V_71 = F_42 ( V_23 ) ;
void * V_68 = ( void * ) ( unsigned long ) V_71 ;
int V_34 = V_23 -> V_37 + V_73 + V_74 + V_71 ;
int V_52 ;
V_34 = F_46 ( V_34 ) +
F_46 ( sizeof( struct V_75 ) ) ;
if ( F_16 ( ! F_73 ( V_34 , V_116 , V_114 ) ) )
return - V_117 ;
V_64 = ( char * ) F_24 ( V_116 -> V_12 ) + V_116 -> V_33 ;
F_74 ( V_116 -> V_12 ) ;
V_116 -> V_33 += V_34 ;
F_39 ( V_11 -> V_57 , V_64 + V_73 + V_71 ,
V_23 -> V_37 + V_74 ) ;
V_52 = F_75 ( V_11 -> V_2 , V_11 -> V_57 , 1 , V_64 , V_68 , V_114 ) ;
if ( V_52 < 0 )
F_29 ( F_38 ( V_64 ) ) ;
return V_52 ;
}
static int F_76 ( struct V_22 * V_23 , struct V_10 * V_11 ,
T_1 V_114 )
{
struct V_12 * V_118 , * V_119 = NULL ;
char * V_17 ;
int V_120 , V_52 , V_33 ;
F_77 ( V_11 -> V_57 , V_42 + 2 ) ;
for ( V_120 = V_42 + 1 ; V_120 > 1 ; -- V_120 ) {
V_118 = F_7 ( V_11 , V_114 ) ;
if ( ! V_118 ) {
if ( V_119 )
F_6 ( V_11 , V_119 ) ;
return - V_117 ;
}
F_78 ( & V_11 -> V_57 [ V_120 ] , F_24 ( V_118 ) , V_43 ) ;
V_118 -> V_14 = ( unsigned long ) V_119 ;
V_119 = V_118 ;
}
V_118 = F_7 ( V_11 , V_114 ) ;
if ( ! V_118 ) {
F_6 ( V_11 , V_119 ) ;
return - V_117 ;
}
V_17 = F_24 ( V_118 ) ;
F_78 ( & V_11 -> V_57 [ 0 ] , V_17 , V_23 -> V_37 ) ;
V_33 = sizeof( struct V_41 ) ;
F_78 ( & V_11 -> V_57 [ 1 ] , V_17 + V_33 , V_43 - V_33 ) ;
V_118 -> V_14 = ( unsigned long ) V_119 ;
V_52 = F_79 ( V_11 -> V_2 , V_11 -> V_57 , V_42 + 2 ,
V_118 , V_114 ) ;
if ( V_52 < 0 )
F_6 ( V_11 , V_118 ) ;
return V_52 ;
}
static unsigned int F_80 ( struct V_10 * V_11 ,
struct V_121 * V_122 )
{
const T_4 V_37 = sizeof( struct V_6 ) ;
unsigned int V_34 ;
V_34 = V_37 + F_81 (unsigned int, ewma_pkt_len_read(avg_pkt_len),
rq->min_buf_len, PAGE_SIZE - hdr_len) ;
return F_82 ( V_34 , V_123 ) ;
}
static int F_83 ( struct V_22 * V_23 ,
struct V_10 * V_11 , T_1 V_114 )
{
struct V_115 * V_116 = & V_11 -> V_116 ;
unsigned int V_30 = F_42 ( V_23 ) ;
char * V_64 ;
void * V_68 ;
int V_52 ;
unsigned int V_34 , V_124 ;
V_34 = F_80 ( V_11 , & V_11 -> V_95 ) ;
if ( F_16 ( ! F_73 ( V_34 + V_30 , V_116 , V_114 ) ) )
return - V_117 ;
V_64 = ( char * ) F_24 ( V_116 -> V_12 ) + V_116 -> V_33 ;
V_64 += V_30 ;
F_74 ( V_116 -> V_12 ) ;
V_116 -> V_33 += V_34 + V_30 ;
V_124 = V_116 -> V_125 - V_116 -> V_33 ;
if ( V_124 < V_34 + V_30 ) {
V_34 += V_124 ;
V_116 -> V_33 += V_124 ;
}
F_39 ( V_11 -> V_57 , V_64 , V_34 ) ;
V_68 = F_20 ( V_34 , V_30 ) ;
V_52 = F_75 ( V_11 -> V_2 , V_11 -> V_57 , 1 , V_64 , V_68 , V_114 ) ;
if ( V_52 < 0 )
F_29 ( F_38 ( V_64 ) ) ;
return V_52 ;
}
static bool F_84 ( struct V_22 * V_23 , struct V_10 * V_11 ,
T_1 V_114 )
{
int V_52 ;
bool V_126 ;
V_114 |= V_127 ;
do {
if ( V_23 -> V_40 )
V_52 = F_83 ( V_23 , V_11 , V_114 ) ;
else if ( V_23 -> V_105 )
V_52 = F_76 ( V_23 , V_11 , V_114 ) ;
else
V_52 = F_72 ( V_23 , V_11 , V_114 ) ;
V_126 = V_52 == - V_117 ;
if ( V_52 )
break;
} while ( V_11 -> V_2 -> V_128 );
F_41 ( V_11 -> V_2 ) ;
return ! V_126 ;
}
static void F_85 ( struct V_1 * V_129 )
{
struct V_22 * V_23 = V_129 -> V_24 -> V_25 ;
struct V_10 * V_11 = & V_23 -> V_11 [ F_3 ( V_129 ) ] ;
F_9 ( & V_11 -> V_19 , V_129 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
F_87 ( V_19 ) ;
F_88 () ;
F_9 ( V_19 , V_2 ) ;
F_89 () ;
}
static void F_90 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_18 * V_19 )
{
if ( ! V_19 -> V_27 )
return;
if ( ! V_23 -> V_130 ) {
V_19 -> V_27 = 0 ;
return;
}
return F_86 ( V_2 , V_19 ) ;
}
static void F_91 ( struct V_18 * V_19 )
{
if ( V_19 -> V_27 )
F_92 ( V_19 ) ;
}
static void F_93 ( struct V_131 * V_132 )
{
struct V_22 * V_23 =
F_94 ( V_132 , struct V_22 , V_133 . V_132 ) ;
bool V_134 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_53 ; V_120 ++ ) {
struct V_10 * V_11 = & V_23 -> V_11 [ V_120 ] ;
F_92 ( & V_11 -> V_19 ) ;
V_134 = ! F_84 ( V_23 , V_11 , V_135 ) ;
F_86 ( V_11 -> V_2 , & V_11 -> V_19 ) ;
if ( V_134 )
F_95 ( & V_23 -> V_133 , V_136 / 2 ) ;
}
}
static int F_96 ( struct V_10 * V_11 , int V_137 )
{
struct V_22 * V_23 = V_11 -> V_2 -> V_24 -> V_25 ;
unsigned int V_34 , V_138 = 0 , V_139 = 0 ;
void * V_64 ;
struct V_140 * V_90 = F_97 ( V_23 -> V_90 ) ;
if ( ! V_23 -> V_105 || V_23 -> V_40 ) {
void * V_68 ;
while ( V_138 < V_137 &&
( V_64 = F_61 ( V_11 -> V_2 , & V_34 , & V_68 ) ) ) {
V_139 += F_65 ( V_23 , V_11 , V_64 , V_34 , V_68 ) ;
V_138 ++ ;
}
} else {
while ( V_138 < V_137 &&
( V_64 = F_37 ( V_11 -> V_2 , & V_34 ) ) != NULL ) {
V_139 += F_65 ( V_23 , V_11 , V_64 , V_34 , NULL ) ;
V_138 ++ ;
}
}
if ( V_11 -> V_2 -> V_128 > F_98 ( V_11 -> V_2 ) / 2 ) {
if ( ! F_84 ( V_23 , V_11 , V_59 ) )
F_95 ( & V_23 -> V_133 , 0 ) ;
}
F_99 ( & V_90 -> V_141 ) ;
V_90 -> V_142 += V_139 ;
V_90 -> V_143 += V_138 ;
F_100 ( & V_90 -> V_141 ) ;
return V_138 ;
}
static void F_101 ( struct V_49 * V_26 )
{
struct V_7 * V_8 ;
unsigned int V_34 ;
struct V_22 * V_23 = V_26 -> V_2 -> V_24 -> V_25 ;
struct V_140 * V_90 = F_97 ( V_23 -> V_90 ) ;
unsigned int V_144 = 0 ;
unsigned int V_139 = 0 ;
while ( ( V_8 = F_37 ( V_26 -> V_2 , & V_34 ) ) != NULL ) {
F_60 ( L_8 , V_8 ) ;
V_139 += V_8 -> V_34 ;
V_144 ++ ;
F_102 ( V_8 ) ;
}
if ( ! V_144 )
return;
F_99 ( & V_90 -> V_145 ) ;
V_90 -> V_146 += V_139 ;
V_90 -> V_147 += V_144 ;
F_100 ( & V_90 -> V_145 ) ;
}
static void F_103 ( struct V_10 * V_11 )
{
struct V_22 * V_23 = V_11 -> V_2 -> V_24 -> V_25 ;
unsigned int V_3 = F_3 ( V_11 -> V_2 ) ;
struct V_49 * V_26 = & V_23 -> V_26 [ V_3 ] ;
struct V_148 * V_4 = F_104 ( V_23 -> V_28 , V_3 ) ;
if ( ! V_26 -> V_19 . V_27 )
return;
if ( F_105 ( V_4 ) ) {
F_101 ( V_26 ) ;
F_106 ( V_4 ) ;
}
if ( V_26 -> V_2 -> V_128 >= 2 + V_42 )
F_107 ( V_4 ) ;
}
static int F_108 ( struct V_18 * V_19 , int V_137 )
{
struct V_10 * V_11 =
F_94 ( V_19 , struct V_10 , V_19 ) ;
unsigned int V_138 ;
F_103 ( V_11 ) ;
V_138 = F_96 ( V_11 , V_137 ) ;
if ( V_138 < V_137 )
F_13 ( V_19 , V_11 -> V_2 , V_138 ) ;
return V_138 ;
}
static int F_109 ( struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
if ( V_120 < V_23 -> V_53 )
if ( ! F_84 ( V_23 , & V_23 -> V_11 [ V_120 ] , V_135 ) )
F_95 ( & V_23 -> V_133 , 0 ) ;
F_86 ( V_23 -> V_11 [ V_120 ] . V_2 , & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_90 ( V_23 , V_23 -> V_26 [ V_120 ] . V_2 , & V_23 -> V_26 [ V_120 ] . V_19 ) ;
}
return 0 ;
}
static int F_111 ( struct V_18 * V_19 , int V_137 )
{
struct V_49 * V_26 = F_94 ( V_19 , struct V_49 , V_19 ) ;
struct V_22 * V_23 = V_26 -> V_2 -> V_24 -> V_25 ;
struct V_148 * V_4 = F_104 ( V_23 -> V_28 , F_1 ( V_26 -> V_2 ) ) ;
F_112 ( V_4 , F_113 () ) ;
F_101 ( V_26 ) ;
F_106 ( V_4 ) ;
F_13 ( V_19 , V_26 -> V_2 , 0 ) ;
if ( V_26 -> V_2 -> V_128 >= 2 + V_42 )
F_107 ( V_4 ) ;
return 0 ;
}
static int F_114 ( struct V_49 * V_26 , struct V_7 * V_8 )
{
struct V_6 * V_35 ;
const unsigned char * V_150 = ( (struct V_151 * ) V_8 -> V_56 ) -> V_152 ;
struct V_22 * V_23 = V_26 -> V_2 -> V_24 -> V_25 ;
int V_153 ;
unsigned V_37 = V_23 -> V_37 ;
bool V_154 ;
F_60 ( L_9 , V_23 -> V_28 -> V_44 , V_8 , V_150 ) ;
V_154 = V_23 -> V_155 &&
! ( ( unsigned long ) V_8 -> V_56 & ( F_115 ( * V_35 ) - 1 ) ) &&
! F_116 ( V_8 ) && F_117 ( V_8 ) >= V_37 ;
if ( V_154 )
V_35 = (struct V_6 * ) ( V_8 -> V_56 - V_37 ) ;
else
V_35 = F_5 ( V_8 ) ;
if ( F_118 ( V_8 , & V_35 -> V_35 ,
F_67 ( V_23 -> V_24 ) , false ) )
F_119 () ;
if ( V_23 -> V_40 )
V_35 -> V_92 = 0 ;
F_77 ( V_26 -> V_57 , F_34 ( V_8 ) -> V_46 + ( V_154 ? 1 : 2 ) ) ;
if ( V_154 ) {
F_120 ( V_8 , V_37 ) ;
V_153 = F_121 ( V_8 , V_26 -> V_57 , 0 , V_8 -> V_34 ) ;
if ( F_16 ( V_153 < 0 ) )
return V_153 ;
F_122 ( V_8 , V_37 ) ;
} else {
F_78 ( V_26 -> V_57 , V_35 , V_37 ) ;
V_153 = F_121 ( V_8 , V_26 -> V_57 + 1 , 0 , V_8 -> V_34 ) ;
if ( F_16 ( V_153 < 0 ) )
return V_153 ;
V_153 ++ ;
}
return F_40 ( V_26 -> V_2 , V_26 -> V_57 , V_153 , V_8 , V_59 ) ;
}
static T_5 F_123 ( struct V_7 * V_8 , struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
int V_156 = F_124 ( V_8 ) ;
struct V_49 * V_26 = & V_23 -> V_26 [ V_156 ] ;
int V_52 ;
struct V_148 * V_4 = F_104 ( V_28 , V_156 ) ;
bool V_157 = ! V_8 -> V_158 ;
bool V_159 = V_26 -> V_19 . V_27 ;
F_101 ( V_26 ) ;
if ( V_159 && V_157 )
F_125 ( V_26 -> V_2 ) ;
F_126 ( V_8 ) ;
V_52 = F_114 ( V_26 , V_8 ) ;
if ( F_16 ( V_52 ) ) {
V_28 -> V_90 . V_160 ++ ;
if ( F_127 () )
F_128 ( & V_28 -> V_28 ,
L_10 , V_156 , V_52 ) ;
V_28 -> V_90 . V_161 ++ ;
F_129 ( V_8 ) ;
return V_162 ;
}
if ( ! V_159 ) {
F_130 ( V_8 ) ;
F_131 ( V_8 ) ;
}
if ( V_26 -> V_2 -> V_128 < 2 + V_42 ) {
F_132 ( V_28 , V_156 ) ;
if ( ! V_159 &&
F_16 ( ! F_125 ( V_26 -> V_2 ) ) ) {
F_101 ( V_26 ) ;
if ( V_26 -> V_2 -> V_128 >= 2 + V_42 ) {
F_133 ( V_28 , V_156 ) ;
F_11 ( V_26 -> V_2 ) ;
}
}
}
if ( V_157 || F_134 ( V_4 ) )
F_41 ( V_26 -> V_2 ) ;
return V_162 ;
}
static bool F_135 ( struct V_22 * V_23 , T_6 V_163 , T_6 V_164 ,
struct V_165 * V_166 )
{
struct V_165 * V_167 [ 4 ] , V_35 , V_168 ;
unsigned V_169 = 0 , V_170 ;
F_32 ( ! F_136 ( V_23 -> V_24 , V_171 ) ) ;
V_23 -> V_172 = ~ 0 ;
V_23 -> V_173 . V_163 = V_163 ;
V_23 -> V_173 . V_164 = V_164 ;
F_39 ( & V_35 , & V_23 -> V_173 , sizeof( V_23 -> V_173 ) ) ;
V_167 [ V_169 ++ ] = & V_35 ;
if ( V_166 )
V_167 [ V_169 ++ ] = V_166 ;
F_39 ( & V_168 , & V_23 -> V_172 , sizeof( V_23 -> V_172 ) ) ;
V_167 [ V_169 ] = & V_168 ;
F_32 ( V_169 + 1 > F_137 ( V_167 ) ) ;
F_138 ( V_23 -> V_174 , V_167 , V_169 , 1 , V_23 , V_59 ) ;
if ( F_16 ( ! F_41 ( V_23 -> V_174 ) ) )
return V_23 -> V_172 == V_175 ;
while ( ! F_37 ( V_23 -> V_174 , & V_170 ) &&
! F_139 ( V_23 -> V_174 ) )
F_140 () ;
return V_23 -> V_172 == V_175 ;
}
static int F_141 ( struct V_67 * V_28 , void * V_17 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
struct V_176 * V_24 = V_23 -> V_24 ;
int V_103 ;
struct V_177 * V_178 ;
struct V_165 V_57 ;
V_178 = F_142 ( V_17 , sizeof( * V_178 ) , V_135 ) ;
if ( ! V_178 )
return - V_117 ;
V_103 = F_143 ( V_28 , V_178 ) ;
if ( V_103 )
goto V_166;
if ( F_136 ( V_24 , V_179 ) ) {
F_39 ( & V_57 , V_178 -> V_180 , V_28 -> V_181 ) ;
if ( ! F_135 ( V_23 , V_182 ,
V_183 , & V_57 ) ) {
F_128 ( & V_24 -> V_28 ,
L_11 ) ;
V_103 = - V_184 ;
goto V_166;
}
} else if ( F_136 ( V_24 , V_185 ) &&
! F_136 ( V_24 , V_186 ) ) {
unsigned int V_120 ;
for ( V_120 = 0 ; V_120 < V_28 -> V_181 ; V_120 ++ )
F_144 ( V_24 ,
F_145 ( struct V_187 , V_188 ) +
V_120 , V_178 -> V_180 [ V_120 ] ) ;
}
F_146 ( V_28 , V_17 ) ;
V_103 = 0 ;
V_166:
F_147 ( V_178 ) ;
return V_103 ;
}
static void V_140 ( struct V_67 * V_28 ,
struct V_189 * V_190 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
int V_191 ;
unsigned int V_192 ;
F_148 (cpu) {
struct V_140 * V_90 = F_149 ( V_23 -> V_90 , V_191 ) ;
T_7 V_193 , V_194 , V_195 , V_196 ;
do {
V_192 = F_150 ( & V_90 -> V_145 ) ;
V_193 = V_90 -> V_147 ;
V_194 = V_90 -> V_146 ;
} while ( F_151 ( & V_90 -> V_145 , V_192 ) );
do {
V_192 = F_150 ( & V_90 -> V_141 ) ;
V_195 = V_90 -> V_143 ;
V_196 = V_90 -> V_142 ;
} while ( F_151 ( & V_90 -> V_141 , V_192 ) );
V_190 -> V_143 += V_195 ;
V_190 -> V_147 += V_193 ;
V_190 -> V_142 += V_196 ;
V_190 -> V_146 += V_194 ;
}
V_190 -> V_161 = V_28 -> V_90 . V_161 ;
V_190 -> V_160 = V_28 -> V_90 . V_160 ;
V_190 -> V_91 = V_28 -> V_90 . V_91 ;
V_190 -> V_96 = V_28 -> V_90 . V_96 ;
V_190 -> V_113 = V_28 -> V_90 . V_113 ;
}
static void F_152 ( struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_53 ; V_120 ++ )
F_153 ( & V_23 -> V_11 [ V_120 ] . V_19 ) ;
}
static void F_154 ( struct V_22 * V_23 )
{
F_155 () ;
if ( ! F_135 ( V_23 , V_197 ,
V_198 , NULL ) )
F_128 ( & V_23 -> V_28 -> V_28 , L_12 ) ;
F_156 () ;
}
static int F_157 ( struct V_22 * V_23 , T_2 V_199 )
{
struct V_165 V_57 ;
struct V_67 * V_28 = V_23 -> V_28 ;
if ( ! V_23 -> V_200 || ! F_136 ( V_23 -> V_24 , V_201 ) )
return 0 ;
V_23 -> V_202 . V_203 = F_158 ( V_23 -> V_24 , V_199 ) ;
F_39 ( & V_57 , & V_23 -> V_202 , sizeof( V_23 -> V_202 ) ) ;
if ( ! F_135 ( V_23 , V_204 ,
V_205 , & V_57 ) ) {
F_128 ( & V_28 -> V_28 , L_13 ,
V_199 ) ;
return - V_184 ;
} else {
V_23 -> V_53 = V_199 ;
if ( V_28 -> V_81 & V_206 )
F_95 ( & V_23 -> V_133 , 0 ) ;
}
return 0 ;
}
static int F_159 ( struct V_22 * V_23 , T_2 V_199 )
{
int V_52 ;
F_155 () ;
V_52 = F_157 ( V_23 , V_199 ) ;
F_156 () ;
return V_52 ;
}
static int F_160 ( struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
int V_120 ;
F_161 ( & V_23 -> V_133 ) ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
F_92 ( & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_91 ( & V_23 -> V_26 [ V_120 ] . V_19 ) ;
}
return 0 ;
}
static void F_162 ( struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
struct V_165 V_57 [ 2 ] ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
int V_211 ;
int V_212 ;
void * V_64 ;
int V_120 ;
if ( ! F_136 ( V_23 -> V_24 , V_213 ) )
return;
V_23 -> V_214 = ( ( V_28 -> V_81 & V_215 ) != 0 ) ;
V_23 -> V_216 = ( ( V_28 -> V_81 & V_217 ) != 0 ) ;
F_39 ( V_57 , & V_23 -> V_214 , sizeof( V_23 -> V_214 ) ) ;
if ( ! F_135 ( V_23 , V_218 ,
V_219 , V_57 ) )
F_128 ( & V_28 -> V_28 , L_14 ,
V_23 -> V_214 ? L_15 : L_16 ) ;
F_39 ( V_57 , & V_23 -> V_216 , sizeof( V_23 -> V_216 ) ) ;
if ( ! F_135 ( V_23 , V_218 ,
V_220 , V_57 ) )
F_128 ( & V_28 -> V_28 , L_17 ,
V_23 -> V_216 ? L_15 : L_16 ) ;
V_211 = F_163 ( V_28 ) ;
V_212 = F_164 ( V_28 ) ;
V_64 = F_165 ( ( ( V_211 + V_212 ) * V_221 ) +
( 2 * sizeof( V_208 -> V_222 ) ) , V_59 ) ;
V_208 = V_64 ;
if ( ! V_64 )
return;
F_77 ( V_57 , 2 ) ;
V_208 -> V_222 = F_166 ( V_23 -> V_24 , V_211 ) ;
V_120 = 0 ;
F_167 (ha, dev)
memcpy ( & V_208 -> V_223 [ V_120 ++ ] [ 0 ] , V_210 -> V_178 , V_221 ) ;
F_78 ( & V_57 [ 0 ] , V_208 ,
sizeof( V_208 -> V_222 ) + ( V_211 * V_221 ) ) ;
V_208 = ( void * ) & V_208 -> V_223 [ V_211 ] [ 0 ] ;
V_208 -> V_222 = F_166 ( V_23 -> V_24 , V_212 ) ;
V_120 = 0 ;
F_168 (ha, dev)
memcpy ( & V_208 -> V_223 [ V_120 ++ ] [ 0 ] , V_210 -> V_178 , V_221 ) ;
F_78 ( & V_57 [ 1 ] , V_208 ,
sizeof( V_208 -> V_222 ) + ( V_212 * V_221 ) ) ;
if ( ! F_135 ( V_23 , V_182 ,
V_224 , V_57 ) )
F_128 ( & V_28 -> V_28 , L_18 ) ;
F_147 ( V_64 ) ;
}
static int F_169 ( struct V_67 * V_28 ,
T_8 V_225 , T_2 V_226 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
struct V_165 V_57 ;
V_23 -> V_227 = V_226 ;
F_39 ( & V_57 , & V_23 -> V_227 , sizeof( V_23 -> V_227 ) ) ;
if ( ! F_135 ( V_23 , V_228 ,
V_229 , & V_57 ) )
F_128 ( & V_28 -> V_28 , L_19 , V_226 ) ;
return 0 ;
}
static int F_170 ( struct V_67 * V_28 ,
T_8 V_225 , T_2 V_226 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
struct V_165 V_57 ;
V_23 -> V_227 = V_226 ;
F_39 ( & V_57 , & V_23 -> V_227 , sizeof( V_23 -> V_227 ) ) ;
if ( ! F_135 ( V_23 , V_228 ,
V_230 , & V_57 ) )
F_128 ( & V_28 -> V_28 , L_20 , V_226 ) ;
return 0 ;
}
static void F_171 ( struct V_22 * V_23 , long V_231 )
{
int V_120 ;
if ( V_23 -> V_130 ) {
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
F_172 ( V_23 -> V_11 [ V_120 ] . V_2 , - 1 ) ;
F_172 ( V_23 -> V_26 [ V_120 ] . V_2 , - 1 ) ;
}
V_23 -> V_130 = false ;
}
}
static void F_173 ( struct V_22 * V_23 )
{
int V_120 ;
int V_191 ;
if ( V_23 -> V_53 == 1 ||
V_23 -> V_149 != F_174 () ) {
F_171 ( V_23 , - 1 ) ;
return;
}
V_120 = 0 ;
F_175 (cpu) {
F_172 ( V_23 -> V_11 [ V_120 ] . V_2 , V_191 ) ;
F_172 ( V_23 -> V_26 [ V_120 ] . V_2 , V_191 ) ;
F_176 ( V_23 -> V_28 , F_177 ( V_191 ) , V_120 ) ;
V_120 ++ ;
}
V_23 -> V_130 = true ;
}
static int F_178 ( unsigned int V_191 , struct V_232 * V_233 )
{
struct V_22 * V_23 = F_179 ( V_233 , struct V_22 ,
V_233 ) ;
F_173 ( V_23 ) ;
return 0 ;
}
static int F_180 ( unsigned int V_191 , struct V_232 * V_233 )
{
struct V_22 * V_23 = F_179 ( V_233 , struct V_22 ,
V_234 ) ;
F_173 ( V_23 ) ;
return 0 ;
}
static int F_181 ( unsigned int V_191 , struct V_232 * V_233 )
{
struct V_22 * V_23 = F_179 ( V_233 , struct V_22 ,
V_233 ) ;
F_171 ( V_23 , V_191 ) ;
return 0 ;
}
static int F_182 ( struct V_22 * V_23 )
{
int V_103 ;
V_103 = F_183 ( V_235 , & V_23 -> V_233 ) ;
if ( V_103 )
return V_103 ;
V_103 = F_183 ( V_236 ,
& V_23 -> V_234 ) ;
if ( ! V_103 )
return V_103 ;
F_184 ( V_235 , & V_23 -> V_233 ) ;
return V_103 ;
}
static void F_185 ( struct V_22 * V_23 )
{
F_184 ( V_235 , & V_23 -> V_233 ) ;
F_184 ( V_236 ,
& V_23 -> V_234 ) ;
}
static void F_186 ( struct V_67 * V_28 ,
struct V_237 * V_238 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
V_238 -> V_239 = F_98 ( V_23 -> V_11 [ 0 ] . V_2 ) ;
V_238 -> V_240 = F_98 ( V_23 -> V_26 [ 0 ] . V_2 ) ;
V_238 -> V_241 = V_238 -> V_239 ;
V_238 -> V_242 = V_238 -> V_240 ;
}
static void F_187 ( struct V_67 * V_28 ,
struct V_243 * V_244 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
struct V_176 * V_24 = V_23 -> V_24 ;
F_188 ( V_244 -> V_245 , V_246 , sizeof( V_244 -> V_245 ) ) ;
F_188 ( V_244 -> V_247 , V_248 , sizeof( V_244 -> V_247 ) ) ;
F_188 ( V_244 -> V_249 , F_189 ( V_24 ) , sizeof( V_244 -> V_249 ) ) ;
}
static int F_190 ( struct V_67 * V_28 ,
struct V_250 * V_251 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
T_2 V_199 = V_251 -> V_252 ;
int V_52 ;
if ( V_251 -> V_253 || V_251 -> V_254 || V_251 -> V_255 )
return - V_184 ;
if ( V_199 > V_23 -> V_149 || V_199 == 0 )
return - V_184 ;
if ( V_23 -> V_11 [ 0 ] . V_70 )
return - V_184 ;
F_191 () ;
V_52 = F_157 ( V_23 , V_199 ) ;
if ( ! V_52 ) {
F_192 ( V_28 , V_199 ) ;
F_193 ( V_28 , V_199 ) ;
F_173 ( V_23 ) ;
}
F_194 () ;
return V_52 ;
}
static void F_195 ( struct V_67 * V_28 ,
struct V_250 * V_251 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
V_251 -> V_252 = V_23 -> V_53 ;
V_251 -> V_256 = V_23 -> V_149 ;
V_251 -> V_257 = 0 ;
V_251 -> V_253 = 0 ;
V_251 -> V_254 = 0 ;
V_251 -> V_255 = 0 ;
}
static bool
F_196 ( const struct V_258 * V_164 )
{
struct V_258 V_259 = * V_164 ;
struct V_258 V_260 = {} ;
V_259 . V_261 . V_262 = 0 ;
V_260 . V_261 . V_263 = V_264 ;
F_197 ( & V_259 , V_265 ) ;
V_259 . V_261 . V_266 = 0 ;
V_259 . V_261 . V_164 = 0 ;
V_259 . V_261 . V_267 = 0 ;
return ! memcmp ( & V_259 . V_261 , & V_260 . V_261 , sizeof( V_259 . V_261 ) ) &&
F_198 ( V_259 . V_268 . V_269 ,
V_270 ) &&
F_198 ( V_259 . V_268 . V_265 ,
V_270 ) &&
F_198 ( V_259 . V_268 . V_271 ,
V_270 ) ;
}
static int F_199 ( struct V_67 * V_28 ,
const struct V_258 * V_164 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
T_3 V_262 ;
V_262 = V_164 -> V_261 . V_262 ;
if ( ! F_200 ( V_262 ) ||
! F_201 ( V_164 -> V_261 . V_266 ) ||
! F_196 ( V_164 ) )
return - V_184 ;
V_23 -> V_262 = V_262 ;
V_23 -> V_266 = V_164 -> V_261 . V_266 ;
return 0 ;
}
static int F_202 ( struct V_67 * V_28 ,
struct V_258 * V_164 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
V_164 -> V_261 . V_262 = V_23 -> V_262 ;
V_164 -> V_261 . V_266 = V_23 -> V_266 ;
V_164 -> V_261 . V_263 = V_264 ;
return 0 ;
}
static void F_203 ( struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
V_23 -> V_262 = V_272 ;
V_23 -> V_266 = V_273 ;
}
static void F_204 ( struct V_176 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
int V_120 ;
F_205 ( & V_23 -> V_274 ) ;
F_206 ( V_23 -> V_28 ) ;
F_207 ( V_23 -> V_28 ) ;
F_161 ( & V_23 -> V_133 ) ;
if ( F_208 ( V_23 -> V_28 ) ) {
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
F_92 ( & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_91 ( & V_23 -> V_26 [ V_120 ] . V_19 ) ;
}
}
}
static int F_209 ( struct V_176 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
int V_52 , V_120 ;
V_52 = F_210 ( V_23 ) ;
if ( V_52 )
return V_52 ;
F_211 ( V_24 ) ;
if ( F_208 ( V_23 -> V_28 ) ) {
for ( V_120 = 0 ; V_120 < V_23 -> V_53 ; V_120 ++ )
if ( ! F_84 ( V_23 , & V_23 -> V_11 [ V_120 ] , V_135 ) )
F_95 ( & V_23 -> V_133 , 0 ) ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
F_86 ( V_23 -> V_11 [ V_120 ] . V_2 , & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_90 ( V_23 , V_23 -> V_26 [ V_120 ] . V_2 ,
& V_23 -> V_26 [ V_120 ] . V_19 ) ;
}
}
F_212 ( V_23 -> V_28 ) ;
return V_52 ;
}
static int F_213 ( struct V_22 * V_23 , T_7 V_275 )
{
struct V_165 V_57 ;
V_23 -> V_276 = F_214 ( V_23 -> V_24 , V_275 ) ;
F_39 ( & V_57 , & V_23 -> V_276 , sizeof( V_23 -> V_276 ) ) ;
if ( ! F_135 ( V_23 , V_277 ,
V_278 , & V_57 ) ) {
F_128 ( & V_23 -> V_28 -> V_28 , L_21 ) ;
return - V_184 ;
}
return 0 ;
}
static int F_215 ( struct V_22 * V_23 )
{
T_7 V_275 = 0 ;
if ( ! V_23 -> V_279 )
return 0 ;
if ( F_136 ( V_23 -> V_24 , V_280 ) )
V_275 = 1ULL << V_280 ;
return F_213 ( V_23 , V_275 ) ;
}
static int F_216 ( struct V_22 * V_23 )
{
T_7 V_275 = V_23 -> V_279 ;
if ( ! V_23 -> V_279 )
return 0 ;
if ( F_136 ( V_23 -> V_24 , V_280 ) )
V_275 |= 1ULL << V_280 ;
return F_213 ( V_23 , V_275 ) ;
}
static int F_217 ( struct V_67 * V_28 , struct V_69 * V_281 ,
struct V_282 * V_283 )
{
unsigned long int V_284 = V_43 - sizeof( struct V_41 ) ;
struct V_22 * V_23 = F_110 ( V_28 ) ;
struct V_69 * V_285 ;
T_2 V_286 = 0 , V_287 ;
int V_120 , V_52 ;
if ( ! F_136 ( V_23 -> V_24 , V_288 )
&& ( F_136 ( V_23 -> V_24 , V_289 ) ||
F_136 ( V_23 -> V_24 , V_290 ) ||
F_136 ( V_23 -> V_24 , V_291 ) ||
F_136 ( V_23 -> V_24 , V_292 ) ) ) {
F_218 ( V_283 , L_22 ) ;
return - V_293 ;
}
if ( V_23 -> V_40 && ! V_23 -> V_155 ) {
F_218 ( V_283 , L_23 ) ;
return - V_184 ;
}
if ( V_28 -> V_294 > V_284 ) {
F_218 ( V_283 , L_24 ) ;
F_219 ( V_28 , L_25 , V_284 ) ;
return - V_184 ;
}
V_287 = V_23 -> V_53 - V_23 -> V_54 ;
if ( V_281 )
V_286 = V_295 ;
if ( V_287 + V_286 > V_23 -> V_149 ) {
F_218 ( V_283 , L_26 ) ;
F_219 ( V_28 , L_27 ,
V_287 + V_286 , V_23 -> V_149 ) ;
return - V_117 ;
}
if ( V_281 ) {
V_281 = F_220 ( V_281 , V_23 -> V_149 - 1 ) ;
if ( F_221 ( V_281 ) )
return F_222 ( V_281 ) ;
}
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ )
F_92 ( & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_193 ( V_28 , V_287 + V_286 ) ;
V_52 = F_157 ( V_23 , V_287 + V_286 ) ;
if ( V_52 )
goto V_52;
V_23 -> V_54 = V_286 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
V_285 = F_223 ( V_23 -> V_11 [ V_120 ] . V_70 ) ;
F_224 ( V_23 -> V_11 [ V_120 ] . V_70 , V_281 ) ;
if ( V_120 == 0 ) {
if ( ! V_285 )
F_215 ( V_23 ) ;
if ( ! V_281 )
F_216 ( V_23 ) ;
}
if ( V_285 )
F_225 ( V_285 ) ;
F_86 ( V_23 -> V_11 [ V_120 ] . V_2 , & V_23 -> V_11 [ V_120 ] . V_19 ) ;
}
return 0 ;
V_52:
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ )
F_86 ( V_23 -> V_11 [ V_120 ] . V_2 , & V_23 -> V_11 [ V_120 ] . V_19 ) ;
if ( V_281 )
F_226 ( V_281 , V_23 -> V_149 - 1 ) ;
return V_52 ;
}
static T_3 F_227 ( struct V_67 * V_28 )
{
struct V_22 * V_23 = F_110 ( V_28 ) ;
const struct V_69 * V_70 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
V_70 = F_223 ( V_23 -> V_11 [ V_120 ] . V_70 ) ;
if ( V_70 )
return V_70 -> V_296 -> V_297 ;
}
return 0 ;
}
static int F_228 ( struct V_67 * V_28 , struct V_298 * V_48 )
{
switch ( V_48 -> V_299 ) {
case V_300 :
return F_217 ( V_28 , V_48 -> V_281 , V_48 -> V_283 ) ;
case V_301 :
V_48 -> V_302 = F_227 ( V_28 ) ;
V_48 -> V_303 = ! ! V_48 -> V_302 ;
return 0 ;
default:
return - V_184 ;
}
}
static void F_229 ( struct V_131 * V_132 )
{
struct V_22 * V_23 =
F_94 ( V_132 , struct V_22 , V_274 ) ;
T_2 V_304 ;
if ( F_230 ( V_23 -> V_24 , V_305 ,
struct V_187 , V_306 , & V_304 ) < 0 )
return;
if ( V_304 & V_307 ) {
F_231 ( V_23 -> V_28 ) ;
F_154 ( V_23 ) ;
}
V_304 &= V_308 ;
if ( V_23 -> V_306 == V_304 )
return;
V_23 -> V_306 = V_304 ;
if ( V_23 -> V_306 & V_308 ) {
F_232 ( V_23 -> V_28 ) ;
F_233 ( V_23 -> V_28 ) ;
} else {
F_234 ( V_23 -> V_28 ) ;
F_235 ( V_23 -> V_28 ) ;
}
}
static void F_236 ( struct V_176 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
F_237 ( & V_23 -> V_274 ) ;
}
static void F_238 ( struct V_22 * V_23 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
F_239 ( & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_240 ( & V_23 -> V_11 [ V_120 ] . V_19 ) ;
F_240 ( & V_23 -> V_26 [ V_120 ] . V_19 ) ;
}
F_241 () ;
F_147 ( V_23 -> V_11 ) ;
F_147 ( V_23 -> V_26 ) ;
}
static void F_242 ( struct V_22 * V_23 )
{
struct V_69 * V_285 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
while ( V_23 -> V_11 [ V_120 ] . V_15 )
F_44 ( F_7 ( & V_23 -> V_11 [ V_120 ] , V_135 ) , 0 ) ;
V_285 = F_223 ( V_23 -> V_11 [ V_120 ] . V_70 ) ;
F_243 ( V_23 -> V_11 [ V_120 ] . V_70 , NULL ) ;
if ( V_285 )
F_225 ( V_285 ) ;
}
}
static void F_244 ( struct V_22 * V_23 )
{
F_155 () ;
F_242 ( V_23 ) ;
F_156 () ;
}
static void F_245 ( struct V_22 * V_23 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ )
if ( V_23 -> V_11 [ V_120 ] . V_116 . V_12 )
F_29 ( V_23 -> V_11 [ V_120 ] . V_116 . V_12 ) ;
}
static bool F_246 ( struct V_22 * V_23 , int V_309 )
{
if ( V_309 < ( V_23 -> V_53 - V_23 -> V_54 ) )
return false ;
else if ( V_309 < V_23 -> V_53 )
return true ;
else
return false ;
}
static void F_247 ( struct V_22 * V_23 )
{
void * V_64 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
struct V_1 * V_2 = V_23 -> V_26 [ V_120 ] . V_2 ;
while ( ( V_64 = F_248 ( V_2 ) ) != NULL ) {
if ( ! F_246 ( V_23 , V_120 ) )
F_31 ( V_64 ) ;
else
F_29 ( F_38 ( V_64 ) ) ;
}
}
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
struct V_1 * V_2 = V_23 -> V_11 [ V_120 ] . V_2 ;
while ( ( V_64 = F_248 ( V_2 ) ) != NULL ) {
if ( V_23 -> V_40 ) {
F_29 ( F_38 ( V_64 ) ) ;
} else if ( V_23 -> V_105 ) {
F_6 ( & V_23 -> V_11 [ V_120 ] , V_64 ) ;
} else {
F_29 ( F_38 ( V_64 ) ) ;
}
}
}
}
static void F_249 ( struct V_22 * V_23 )
{
struct V_176 * V_24 = V_23 -> V_24 ;
F_171 ( V_23 , - 1 ) ;
V_24 -> V_310 -> V_311 ( V_24 ) ;
F_238 ( V_23 ) ;
}
static unsigned int F_250 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
const unsigned int V_37 = sizeof( struct V_6 ) ;
unsigned int V_312 = F_98 ( V_2 ) ;
unsigned int V_313 = V_23 -> V_105 ? V_314 : V_23 -> V_28 -> V_315 ;
unsigned int V_316 = V_37 + V_104 + V_317 + V_313 ;
unsigned int V_318 = F_251 ( V_316 , V_312 ) ;
return F_252 ( F_252 ( V_318 , V_37 ) - V_37 ,
( unsigned int ) V_74 ) ;
}
static int F_253 ( struct V_22 * V_23 )
{
T_9 * * V_319 ;
struct V_1 * * V_320 ;
int V_103 = - V_117 ;
int V_120 , V_321 ;
const char * * V_322 ;
bool * V_68 ;
V_321 = V_23 -> V_149 * 2 +
F_136 ( V_23 -> V_24 , V_171 ) ;
V_320 = F_165 ( V_321 * sizeof( * V_320 ) , V_135 ) ;
if ( ! V_320 )
goto V_323;
V_319 = F_254 ( V_321 * sizeof( * V_319 ) , V_135 ) ;
if ( ! V_319 )
goto V_324;
V_322 = F_254 ( V_321 * sizeof( * V_322 ) , V_135 ) ;
if ( ! V_322 )
goto V_325;
if ( ! V_23 -> V_105 || V_23 -> V_40 ) {
V_68 = F_165 ( V_321 * sizeof( * V_68 ) , V_135 ) ;
if ( ! V_68 )
goto V_326;
} else {
V_68 = NULL ;
}
if ( V_23 -> V_200 ) {
V_319 [ V_321 - 1 ] = NULL ;
V_322 [ V_321 - 1 ] = L_28 ;
}
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
V_319 [ F_4 ( V_120 ) ] = F_85 ;
V_319 [ F_2 ( V_120 ) ] = F_18 ;
sprintf ( V_23 -> V_11 [ V_120 ] . V_44 , L_29 , V_120 ) ;
sprintf ( V_23 -> V_26 [ V_120 ] . V_44 , L_30 , V_120 ) ;
V_322 [ F_4 ( V_120 ) ] = V_23 -> V_11 [ V_120 ] . V_44 ;
V_322 [ F_2 ( V_120 ) ] = V_23 -> V_26 [ V_120 ] . V_44 ;
if ( V_68 )
V_68 [ F_4 ( V_120 ) ] = true ;
}
V_103 = V_23 -> V_24 -> V_310 -> V_327 ( V_23 -> V_24 , V_321 , V_320 , V_319 ,
V_322 , V_68 , NULL ) ;
if ( V_103 )
goto V_328;
if ( V_23 -> V_200 ) {
V_23 -> V_174 = V_320 [ V_321 - 1 ] ;
if ( F_136 ( V_23 -> V_24 , V_329 ) )
V_23 -> V_28 -> V_330 |= V_331 ;
}
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
V_23 -> V_11 [ V_120 ] . V_2 = V_320 [ F_4 ( V_120 ) ] ;
V_23 -> V_11 [ V_120 ] . V_318 = F_250 ( V_23 , V_23 -> V_11 [ V_120 ] . V_2 ) ;
V_23 -> V_26 [ V_120 ] . V_2 = V_320 [ F_2 ( V_120 ) ] ;
}
F_147 ( V_322 ) ;
F_147 ( V_319 ) ;
F_147 ( V_320 ) ;
F_147 ( V_68 ) ;
return 0 ;
V_328:
F_147 ( V_68 ) ;
V_326:
F_147 ( V_322 ) ;
V_325:
F_147 ( V_319 ) ;
V_324:
F_147 ( V_320 ) ;
V_323:
return V_103 ;
}
static int F_255 ( struct V_22 * V_23 )
{
int V_120 ;
V_23 -> V_26 = F_165 ( sizeof( * V_23 -> V_26 ) * V_23 -> V_149 , V_135 ) ;
if ( ! V_23 -> V_26 )
goto V_332;
V_23 -> V_11 = F_165 ( sizeof( * V_23 -> V_11 ) * V_23 -> V_149 , V_135 ) ;
if ( ! V_23 -> V_11 )
goto V_333;
F_256 ( & V_23 -> V_133 , F_93 ) ;
for ( V_120 = 0 ; V_120 < V_23 -> V_149 ; V_120 ++ ) {
V_23 -> V_11 [ V_120 ] . V_15 = NULL ;
F_257 ( V_23 -> V_28 , & V_23 -> V_11 [ V_120 ] . V_19 , F_108 ,
V_334 ) ;
F_258 ( V_23 -> V_28 , & V_23 -> V_26 [ V_120 ] . V_19 , F_111 ,
V_335 ? V_334 : 0 ) ;
F_77 ( V_23 -> V_11 [ V_120 ] . V_57 , F_137 ( V_23 -> V_11 [ V_120 ] . V_57 ) ) ;
F_259 ( & V_23 -> V_11 [ V_120 ] . V_95 ) ;
F_77 ( V_23 -> V_26 [ V_120 ] . V_57 , F_137 ( V_23 -> V_26 [ V_120 ] . V_57 ) ) ;
}
return 0 ;
V_333:
F_147 ( V_23 -> V_26 ) ;
V_332:
return - V_117 ;
}
static int F_210 ( struct V_22 * V_23 )
{
int V_103 ;
V_103 = F_255 ( V_23 ) ;
if ( V_103 )
goto V_52;
V_103 = F_253 ( V_23 ) ;
if ( V_103 )
goto V_336;
F_191 () ;
F_173 ( V_23 ) ;
F_194 () ;
return 0 ;
V_336:
F_238 ( V_23 ) ;
V_52:
return V_103 ;
}
static T_10 F_260 ( struct V_337 * V_338 ,
char * V_64 )
{
struct V_22 * V_23 = F_110 ( V_338 -> V_28 ) ;
unsigned int V_339 = F_261 ( V_338 ) ;
struct V_121 * V_340 ;
F_32 ( V_339 >= V_23 -> V_149 ) ;
V_340 = & V_23 -> V_11 [ V_339 ] . V_95 ;
return sprintf ( V_64 , L_31 ,
F_80 ( & V_23 -> V_11 [ V_339 ] , V_340 ) ) ;
}
static bool F_262 ( struct V_176 * V_24 ,
unsigned int V_341 ,
const char * V_342 , const char * V_343 )
{
if ( ! F_136 ( V_24 , V_341 ) )
return false ;
F_263 ( & V_24 -> V_28 , L_32 ,
V_342 , V_343 ) ;
return true ;
}
static bool F_264 ( struct V_176 * V_24 )
{
if ( ! F_136 ( V_24 , V_171 ) &&
( F_265 ( V_24 , V_213 ,
L_33 ) ||
F_265 ( V_24 , V_329 ,
L_33 ) ||
F_265 ( V_24 , V_344 ,
L_33 ) ||
F_265 ( V_24 , V_201 , L_33 ) ||
F_265 ( V_24 , V_179 ,
L_33 ) ) ) {
return false ;
}
return true ;
}
static int F_266 ( struct V_176 * V_24 )
{
if ( ! V_24 -> V_310 -> V_345 ) {
F_263 ( & V_24 -> V_28 , L_34 ,
V_346 ) ;
return - V_184 ;
}
if ( ! F_264 ( V_24 ) )
return - V_184 ;
if ( F_136 ( V_24 , V_347 ) ) {
int V_294 = F_267 ( V_24 ,
F_145 ( struct V_187 ,
V_294 ) ) ;
if ( V_294 < V_348 )
F_268 ( V_24 , V_347 ) ;
}
return 0 ;
}
static int F_269 ( struct V_176 * V_24 )
{
int V_120 , V_52 ;
struct V_67 * V_28 ;
struct V_22 * V_23 ;
T_2 V_149 ;
int V_294 ;
V_52 = F_230 ( V_24 , V_201 ,
struct V_187 ,
V_349 , & V_149 ) ;
if ( V_52 || V_149 < V_350 ||
V_149 > V_351 ||
! F_136 ( V_24 , V_171 ) )
V_149 = 1 ;
V_28 = F_270 ( sizeof( struct V_22 ) , V_149 ) ;
if ( ! V_28 )
return - V_117 ;
V_28 -> V_352 |= V_353 | V_354 ;
V_28 -> V_355 = & V_356 ;
V_28 -> V_330 = V_357 ;
V_28 -> V_358 = & V_359 ;
F_271 ( V_28 , & V_24 -> V_28 ) ;
if ( F_136 ( V_24 , V_360 ) ) {
V_28 -> V_361 |= V_362 | V_363 ;
if ( V_364 )
V_28 -> V_330 |= V_362 | V_363 ;
if ( F_136 ( V_24 , V_365 ) ) {
V_28 -> V_361 |= V_366
| V_367 | V_368 ;
}
if ( F_136 ( V_24 , V_369 ) )
V_28 -> V_361 |= V_366 ;
if ( F_136 ( V_24 , V_370 ) )
V_28 -> V_361 |= V_368 ;
if ( F_136 ( V_24 , V_371 ) )
V_28 -> V_361 |= V_367 ;
V_28 -> V_330 |= V_372 ;
if ( V_373 )
V_28 -> V_330 |= V_28 -> V_361 & V_374 ;
}
if ( F_136 ( V_24 , V_280 ) )
V_28 -> V_330 |= V_375 ;
V_28 -> V_376 = V_28 -> V_330 ;
V_28 -> V_377 = V_348 ;
V_28 -> V_315 = V_378 ;
if ( F_136 ( V_24 , V_185 ) )
F_272 ( V_24 ,
F_145 ( struct V_187 , V_188 ) ,
V_28 -> V_379 , V_28 -> V_181 ) ;
else
F_273 ( V_28 ) ;
V_23 = F_110 ( V_28 ) ;
V_23 -> V_28 = V_28 ;
V_23 -> V_24 = V_24 ;
V_24 -> V_25 = V_23 ;
V_23 -> V_90 = F_274 ( struct V_140 ) ;
V_52 = - V_117 ;
if ( V_23 -> V_90 == NULL )
goto free;
F_148 (i) {
struct V_140 * V_140 ;
V_140 = F_149 ( V_23 -> V_90 , V_120 ) ;
F_275 ( & V_140 -> V_145 ) ;
F_275 ( & V_140 -> V_141 ) ;
}
F_276 ( & V_23 -> V_274 , F_229 ) ;
if ( F_136 ( V_24 , V_289 ) ||
F_136 ( V_24 , V_290 ) ||
F_136 ( V_24 , V_291 ) ||
F_136 ( V_24 , V_292 ) )
V_23 -> V_105 = true ;
if ( F_136 ( V_24 , V_380 ) )
V_23 -> V_40 = true ;
if ( F_136 ( V_24 , V_380 ) ||
F_136 ( V_24 , V_186 ) )
V_23 -> V_37 = sizeof( struct V_6 ) ;
else
V_23 -> V_37 = sizeof( struct V_381 ) ;
if ( F_136 ( V_24 , V_382 ) ||
F_136 ( V_24 , V_186 ) )
V_23 -> V_155 = true ;
if ( F_136 ( V_24 , V_171 ) )
V_23 -> V_200 = true ;
if ( F_136 ( V_24 , V_347 ) ) {
V_294 = F_267 ( V_24 ,
F_145 ( struct V_187 ,
V_294 ) ) ;
if ( V_294 < V_28 -> V_377 ) {
F_263 ( & V_24 -> V_28 , L_35
L_36 , V_294 , V_28 -> V_377 ) ;
goto V_383;
}
V_28 -> V_294 = V_294 ;
V_28 -> V_315 = V_294 ;
if ( V_28 -> V_294 > V_384 )
V_23 -> V_105 = true ;
}
if ( V_23 -> V_155 )
V_28 -> V_385 = V_23 -> V_37 ;
if ( F_174 () >= V_149 )
V_23 -> V_53 = V_149 ;
else
V_23 -> V_53 = F_174 () ;
V_23 -> V_149 = V_149 ;
V_52 = F_210 ( V_23 ) ;
if ( V_52 )
goto V_383;
#ifdef F_277
if ( V_23 -> V_40 )
V_28 -> V_386 = & V_387 ;
#endif
F_192 ( V_28 , V_23 -> V_53 ) ;
F_193 ( V_28 , V_23 -> V_53 ) ;
F_203 ( V_28 ) ;
V_52 = F_278 ( V_28 ) ;
if ( V_52 ) {
F_60 ( L_37 ) ;
goto V_388;
}
F_211 ( V_24 ) ;
V_52 = F_182 ( V_23 ) ;
if ( V_52 ) {
F_60 ( L_38 ) ;
goto V_389;
}
F_159 ( V_23 , V_23 -> V_53 ) ;
if ( F_136 ( V_23 -> V_24 , V_305 ) ) {
F_234 ( V_28 ) ;
F_237 ( & V_23 -> V_274 ) ;
} else {
V_23 -> V_306 = V_308 ;
F_232 ( V_28 ) ;
}
for ( V_120 = 0 ; V_120 < F_137 ( V_279 ) ; V_120 ++ )
if ( F_136 ( V_23 -> V_24 , V_279 [ V_120 ] ) )
F_279 ( V_279 [ V_120 ] , & V_23 -> V_279 ) ;
F_60 ( L_39 ,
V_28 -> V_44 , V_149 ) ;
return 0 ;
V_389:
V_23 -> V_24 -> V_310 -> V_390 ( V_24 ) ;
F_280 ( V_28 ) ;
V_388:
F_161 ( & V_23 -> V_133 ) ;
F_245 ( V_23 ) ;
F_249 ( V_23 ) ;
V_383:
F_281 ( V_23 -> V_90 ) ;
free:
F_282 ( V_28 ) ;
return V_52 ;
}
static void F_283 ( struct V_22 * V_23 )
{
V_23 -> V_24 -> V_310 -> V_390 ( V_23 -> V_24 ) ;
F_247 ( V_23 ) ;
F_244 ( V_23 ) ;
F_245 ( V_23 ) ;
F_249 ( V_23 ) ;
}
static void F_284 ( struct V_176 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
F_185 ( V_23 ) ;
F_205 ( & V_23 -> V_274 ) ;
F_280 ( V_23 -> V_28 ) ;
F_283 ( V_23 ) ;
F_281 ( V_23 -> V_90 ) ;
F_282 ( V_23 -> V_28 ) ;
}
static T_11 int F_285 ( struct V_176 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
F_185 ( V_23 ) ;
F_204 ( V_24 ) ;
F_283 ( V_23 ) ;
return 0 ;
}
static T_11 int F_286 ( struct V_176 * V_24 )
{
struct V_22 * V_23 = V_24 -> V_25 ;
int V_52 ;
V_52 = F_209 ( V_24 ) ;
if ( V_52 )
return V_52 ;
F_159 ( V_23 , V_23 -> V_53 ) ;
V_52 = F_182 ( V_23 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
static T_12 int F_287 ( void )
{
int V_103 ;
V_103 = F_288 ( V_391 , L_40 ,
F_178 ,
F_181 ) ;
if ( V_103 < 0 )
goto V_166;
V_235 = V_103 ;
V_103 = F_288 ( V_236 , L_41 ,
NULL , F_180 ) ;
if ( V_103 )
goto V_392;
V_103 = F_289 ( & V_393 ) ;
if ( V_103 )
goto V_394;
return 0 ;
V_394:
F_290 ( V_236 ) ;
V_392:
F_290 ( V_235 ) ;
V_166:
return V_103 ;
}
static T_13 void F_291 ( void )
{
F_292 ( & V_393 ) ;
F_290 ( V_236 ) ;
F_290 ( V_235 ) ;
}
