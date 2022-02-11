static T_1 F_1 ( struct V_1 * log , T_1 V_2 )
{
return V_2 & ( log -> V_3 - 1 ) ;
}
static inline struct V_1 * F_2 ( struct V_4 * V_4 )
{
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 = V_4 -> V_9 ;
return V_8 -> log ;
} else
return V_4 -> V_9 ;
}
static struct V_10 * F_3 ( struct V_1 * log ,
T_1 V_11 , struct V_10 * V_12 )
{
T_1 V_13 = F_4 ( sizeof( struct V_10 ) , log -> V_3 - V_11 ) ;
if ( V_13 != sizeof( struct V_10 ) ) {
memcpy ( ( ( void * ) V_12 ) , log -> V_14 + V_11 , V_13 ) ;
memcpy ( ( ( void * ) V_12 ) + V_13 , log -> V_14 ,
sizeof( struct V_10 ) - V_13 ) ;
return V_12 ;
}
return (struct V_10 * ) ( log -> V_14 + V_11 ) ;
}
static T_2 F_5 ( struct V_1 * log , T_1 V_11 )
{
struct V_10 V_12 ;
struct V_10 * V_15 ;
V_15 = F_3 ( log , V_11 , & V_12 ) ;
return V_15 -> V_13 ;
}
static T_1 F_6 ( int V_16 )
{
if ( V_16 < 2 )
return sizeof( struct V_17 ) ;
else
return sizeof( struct V_10 ) ;
}
static T_3 F_7 ( int V_16 , struct V_10 * V_15 ,
char T_4 * V_18 )
{
void * V_19 ;
T_1 V_20 ;
struct V_17 V_21 ;
if ( V_16 < 2 ) {
V_21 . V_13 = V_15 -> V_13 ;
V_21 . V_22 = 0 ;
V_21 . V_23 = V_15 -> V_23 ;
V_21 . V_24 = V_15 -> V_24 ;
V_21 . V_25 = V_15 -> V_25 ;
V_21 . V_26 = V_15 -> V_26 ;
V_19 = & V_21 ;
V_20 = sizeof( struct V_17 ) ;
} else {
V_19 = V_15 ;
V_20 = sizeof( struct V_10 ) ;
}
return F_8 ( V_18 , V_19 , V_20 ) ;
}
static T_3 F_9 ( struct V_1 * log ,
struct V_7 * V_8 ,
char T_4 * V_18 ,
T_1 V_27 )
{
struct V_10 V_12 ;
struct V_10 * V_15 ;
T_1 V_13 ;
T_1 V_28 ;
V_15 = F_3 ( log , V_8 -> V_29 , & V_12 ) ;
if ( F_7 ( V_8 -> V_30 , V_15 , V_18 ) )
return - V_31 ;
V_27 -= F_6 ( V_8 -> V_30 ) ;
V_18 += F_6 ( V_8 -> V_30 ) ;
V_28 = F_1 ( log ,
V_8 -> V_29 + sizeof( struct V_10 ) ) ;
V_13 = F_4 ( V_27 , log -> V_3 - V_28 ) ;
if ( F_8 ( V_18 , log -> V_14 + V_28 , V_13 ) )
return - V_31 ;
if ( V_27 != V_13 )
if ( F_8 ( V_18 + V_13 , log -> V_14 , V_27 - V_13 ) )
return - V_31 ;
V_8 -> V_29 = F_1 ( log , V_8 -> V_29 +
sizeof( struct V_10 ) + V_27 ) ;
return V_27 + F_6 ( V_8 -> V_30 ) ;
}
static T_1 F_10 ( struct V_1 * log ,
T_1 V_11 , T_5 V_32 )
{
while ( V_11 != log -> V_33 ) {
struct V_10 * V_15 ;
struct V_10 V_12 ;
T_1 V_34 ;
V_15 = F_3 ( log , V_11 , & V_12 ) ;
if ( F_11 ( V_15 -> V_32 , V_32 ) )
return V_11 ;
V_34 = sizeof( struct V_10 ) + V_15 -> V_13 ;
V_11 = F_1 ( log , V_11 + V_34 ) ;
}
return V_11 ;
}
static T_3 F_12 ( struct V_4 * V_4 , char T_4 * V_18 ,
T_1 V_27 , T_6 * V_35 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_1 * log = V_8 -> log ;
T_3 V_36 ;
F_13 ( V_37 ) ;
V_38:
while ( 1 ) {
F_14 ( & log -> V_39 ) ;
F_15 ( & log -> V_40 , & V_37 , V_41 ) ;
V_36 = ( log -> V_33 == V_8 -> V_29 ) ;
F_16 ( & log -> V_39 ) ;
if ( ! V_36 )
break;
if ( V_4 -> V_42 & V_43 ) {
V_36 = - V_44 ;
break;
}
if ( F_17 ( V_45 ) ) {
V_36 = - V_46 ;
break;
}
F_18 () ;
}
F_19 ( & log -> V_40 , & V_37 ) ;
if ( V_36 )
return V_36 ;
F_14 ( & log -> V_39 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_29 = F_10 ( log ,
V_8 -> V_29 , F_20 () ) ;
if ( F_21 ( log -> V_33 == V_8 -> V_29 ) ) {
F_16 ( & log -> V_39 ) ;
goto V_38;
}
V_36 = F_6 ( V_8 -> V_30 ) +
F_5 ( log , V_8 -> V_29 ) ;
if ( V_27 < V_36 ) {
V_36 = - V_48 ;
goto V_49;
}
V_36 = F_9 ( log , V_8 , V_18 , V_36 ) ;
V_49:
F_16 ( & log -> V_39 ) ;
return V_36 ;
}
static T_1 F_22 ( struct V_1 * log , T_1 V_11 , T_1 V_13 )
{
T_1 V_27 = 0 ;
do {
T_1 V_50 = sizeof( struct V_10 ) +
F_5 ( log , V_11 ) ;
V_11 = F_1 ( log , V_11 + V_50 ) ;
V_27 += V_50 ;
} while ( V_27 < V_13 );
return V_11 ;
}
static inline int F_23 ( T_1 V_51 , T_1 V_52 , T_1 V_53 )
{
if ( V_51 < V_52 ) {
if ( V_51 < V_53 && V_53 <= V_52 )
return 1 ;
} else {
if ( V_53 <= V_52 || V_51 < V_53 )
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * log , T_1 V_13 )
{
T_1 V_54 = log -> V_33 ;
T_1 V_55 = F_1 ( log , V_54 + V_13 ) ;
struct V_7 * V_8 ;
if ( F_23 ( V_54 , V_55 , log -> V_56 ) )
log -> V_56 = F_22 ( log , log -> V_56 , V_13 ) ;
F_25 (reader, &log->readers, list)
if ( F_23 ( V_54 , V_55 , V_8 -> V_29 ) )
V_8 -> V_29 = F_22 ( log , V_8 -> V_29 , V_13 ) ;
}
static void F_26 ( struct V_1 * log , const void * V_18 , T_1 V_27 )
{
T_1 V_13 ;
V_13 = F_4 ( V_27 , log -> V_3 - log -> V_33 ) ;
memcpy ( log -> V_14 + log -> V_33 , V_18 , V_13 ) ;
if ( V_27 != V_13 )
memcpy ( log -> V_14 , V_18 + V_13 , V_27 - V_13 ) ;
log -> V_33 = F_1 ( log , log -> V_33 + V_27 ) ;
}
static T_3 F_27 ( struct V_1 * log ,
const void T_4 * V_18 , T_1 V_27 )
{
T_1 V_13 ;
V_13 = F_4 ( V_27 , log -> V_3 - log -> V_33 ) ;
if ( V_13 && F_28 ( log -> V_14 + log -> V_33 , V_18 , V_13 ) )
return - V_31 ;
if ( V_27 != V_13 )
if ( F_28 ( log -> V_14 , V_18 + V_13 , V_27 - V_13 ) )
return - V_31 ;
log -> V_33 = F_1 ( log , log -> V_33 + V_27 ) ;
return V_27 ;
}
static T_3 F_29 ( struct V_57 * V_58 , const struct V_59 * V_60 ,
unsigned long V_61 , T_6 V_62 )
{
struct V_1 * log = F_2 ( V_58 -> V_63 ) ;
T_1 V_64 = log -> V_33 ;
struct V_10 V_65 ;
struct V_66 V_67 ;
T_3 V_36 = 0 ;
V_67 = F_30 () ;
V_65 . V_23 = V_45 -> V_68 ;
V_65 . V_24 = V_45 -> V_23 ;
V_65 . V_25 = V_67 . V_69 ;
V_65 . V_26 = V_67 . V_70 ;
V_65 . V_32 = F_20 () ;
V_65 . V_13 = F_31 ( T_1 , V_58 -> V_71 , V_72 ) ;
V_65 . V_73 = sizeof( struct V_10 ) ;
if ( F_21 ( ! V_65 . V_13 ) )
return 0 ;
F_14 ( & log -> V_39 ) ;
F_24 ( log , sizeof( struct V_10 ) + V_65 . V_13 ) ;
F_26 ( log , & V_65 , sizeof( struct V_10 ) ) ;
while ( V_61 -- > 0 ) {
T_1 V_13 ;
T_3 V_50 ;
V_13 = F_31 ( T_1 , V_60 -> V_74 , V_65 . V_13 - V_36 ) ;
V_50 = F_27 ( log , V_60 -> V_75 , V_13 ) ;
if ( F_21 ( V_50 < 0 ) ) {
log -> V_33 = V_64 ;
F_16 ( & log -> V_39 ) ;
return V_50 ;
}
V_60 ++ ;
V_36 += V_50 ;
}
F_16 ( & log -> V_39 ) ;
F_32 ( & log -> V_40 ) ;
return V_36 ;
}
static struct V_1 * F_33 ( int V_76 )
{
struct V_1 * log ;
F_25 (log, &log_list, logs)
if ( log -> V_77 . V_76 == V_76 )
return log ;
return NULL ;
}
static int F_34 ( struct V_78 * V_78 , struct V_4 * V_4 )
{
struct V_1 * log ;
int V_36 ;
V_36 = F_35 ( V_78 , V_4 ) ;
if ( V_36 )
return V_36 ;
log = F_33 ( F_36 ( V_78 -> V_79 ) ) ;
if ( ! log )
return - V_80 ;
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 ;
V_8 = F_37 ( sizeof( struct V_7 ) , V_81 ) ;
if ( ! V_8 )
return - V_82 ;
V_8 -> log = log ;
V_8 -> V_30 = 1 ;
V_8 -> V_47 = F_38 ( V_78 -> V_83 ) ||
F_39 ( V_84 ) ;
F_40 ( & V_8 -> V_85 ) ;
F_14 ( & log -> V_39 ) ;
V_8 -> V_29 = log -> V_56 ;
F_41 ( & V_8 -> V_85 , & log -> V_86 ) ;
F_16 ( & log -> V_39 ) ;
V_4 -> V_9 = V_8 ;
} else
V_4 -> V_9 = log ;
return 0 ;
}
static int F_42 ( struct V_78 * V_87 , struct V_4 * V_4 )
{
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_1 * log = V_8 -> log ;
F_14 ( & log -> V_39 ) ;
F_43 ( & V_8 -> V_85 ) ;
F_16 ( & log -> V_39 ) ;
F_44 ( V_8 ) ;
}
return 0 ;
}
static unsigned int F_45 ( struct V_4 * V_4 , T_7 * V_37 )
{
struct V_7 * V_8 ;
struct V_1 * log ;
unsigned int V_36 = V_88 | V_89 ;
if ( ! ( V_4 -> V_5 & V_6 ) )
return V_36 ;
V_8 = V_4 -> V_9 ;
log = V_8 -> log ;
F_46 ( V_4 , & log -> V_40 , V_37 ) ;
F_14 ( & log -> V_39 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_29 = F_10 ( log ,
V_8 -> V_29 , F_20 () ) ;
if ( log -> V_33 != V_8 -> V_29 )
V_36 |= V_90 | V_91 ;
F_16 ( & log -> V_39 ) ;
return V_36 ;
}
static long F_47 ( struct V_7 * V_8 , void T_4 * V_92 )
{
int V_93 ;
if ( F_28 ( & V_93 , V_92 , sizeof( int ) ) )
return - V_31 ;
if ( ( V_93 < 1 ) || ( V_93 > 2 ) )
return - V_48 ;
V_8 -> V_30 = V_93 ;
return 0 ;
}
static long F_48 ( struct V_4 * V_4 , unsigned int V_94 , unsigned long V_92 )
{
struct V_1 * log = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
long V_36 = - V_48 ;
void T_4 * V_95 = ( void T_4 * ) V_92 ;
F_14 ( & log -> V_39 ) ;
switch ( V_94 ) {
case V_96 :
V_36 = log -> V_3 ;
break;
case V_97 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_98 ;
break;
}
V_8 = V_4 -> V_9 ;
if ( log -> V_33 >= V_8 -> V_29 )
V_36 = log -> V_33 - V_8 -> V_29 ;
else
V_36 = ( log -> V_3 - V_8 -> V_29 ) + log -> V_33 ;
break;
case V_99 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_98 ;
break;
}
V_8 = V_4 -> V_9 ;
if ( ! V_8 -> V_47 )
V_8 -> V_29 = F_10 ( log ,
V_8 -> V_29 , F_20 () ) ;
if ( log -> V_33 != V_8 -> V_29 )
V_36 = F_6 ( V_8 -> V_30 ) +
F_5 ( log , V_8 -> V_29 ) ;
else
V_36 = 0 ;
break;
case V_100 :
if ( ! ( V_4 -> V_5 & V_101 ) ) {
V_36 = - V_98 ;
break;
}
if ( ! ( F_38 ( V_4 -> V_102 -> V_103 -> V_83 ) ||
F_39 ( V_84 ) ) ) {
V_36 = - V_104 ;
break;
}
F_25 (reader, &log->readers, list)
V_8 -> V_29 = log -> V_33 ;
log -> V_56 = log -> V_33 ;
V_36 = 0 ;
break;
case V_105 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_98 ;
break;
}
V_8 = V_4 -> V_9 ;
V_36 = V_8 -> V_30 ;
break;
case V_106 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_98 ;
break;
}
V_8 = V_4 -> V_9 ;
V_36 = F_47 ( V_8 , V_95 ) ;
break;
}
F_16 ( & log -> V_39 ) ;
return V_36 ;
}
static int T_8 F_49 ( char * V_107 , int V_3 )
{
int V_36 = 0 ;
struct V_1 * log ;
unsigned char * V_14 ;
V_14 = F_50 ( V_3 ) ;
if ( V_14 == NULL )
return - V_82 ;
log = F_51 ( sizeof( struct V_1 ) , V_81 ) ;
if ( log == NULL ) {
V_36 = - V_82 ;
goto V_108;
}
log -> V_14 = V_14 ;
log -> V_77 . V_76 = V_109 ;
log -> V_77 . V_110 = F_52 ( V_107 , V_81 ) ;
if ( log -> V_77 . V_110 == NULL ) {
V_36 = - V_82 ;
goto V_111;
}
log -> V_77 . V_112 = & V_113 ;
log -> V_77 . V_114 = NULL ;
F_53 ( & log -> V_40 ) ;
F_40 ( & log -> V_86 ) ;
F_54 ( & log -> V_39 ) ;
log -> V_33 = 0 ;
log -> V_56 = 0 ;
log -> V_3 = V_3 ;
F_40 ( & log -> V_115 ) ;
F_41 ( & log -> V_115 , & V_116 ) ;
V_36 = F_55 ( & log -> V_77 ) ;
if ( F_21 ( V_36 ) ) {
F_56 ( L_1 ,
log -> V_77 . V_110 ) ;
goto V_111;
}
F_57 ( L_2 ,
( unsigned long ) log -> V_3 >> 10 , log -> V_77 . V_110 ) ;
return 0 ;
V_111:
F_44 ( log ) ;
V_108:
F_58 ( V_14 ) ;
return V_36 ;
}
static int T_8 F_59 ( void )
{
int V_36 ;
V_36 = F_49 ( V_117 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_36 = F_49 ( V_118 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_36 = F_49 ( V_119 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_36 = F_49 ( V_120 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_49:
return V_36 ;
}
static void T_9 F_60 ( void )
{
struct V_1 * V_121 , * V_122 ;
F_61 (current_log, next_log, &log_list, logs) {
F_62 ( & V_121 -> V_77 ) ;
F_58 ( V_121 -> V_14 ) ;
F_44 ( V_121 -> V_77 . V_110 ) ;
F_43 ( & V_121 -> V_115 ) ;
F_44 ( V_121 ) ;
}
}
