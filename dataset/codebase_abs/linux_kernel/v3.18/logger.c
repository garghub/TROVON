static T_1 F_1 ( struct V_1 * log , T_1 V_2 )
{
return V_2 & ( log -> V_3 - 1 ) ;
}
static inline struct V_1 * F_2 ( struct V_4 * V_4 )
{
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 = V_4 -> V_9 ;
return V_8 -> log ;
}
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
static T_3 F_26 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
struct V_1 * log = F_2 ( V_58 -> V_61 ) ;
struct V_10 V_62 ;
struct V_63 V_64 ;
T_1 V_13 , V_27 , V_33 ;
V_27 = F_27 ( T_1 , V_58 -> V_65 , V_66 ) ;
V_64 = F_28 () ;
V_62 . V_23 = V_45 -> V_67 ;
V_62 . V_24 = V_45 -> V_23 ;
V_62 . V_25 = V_64 . V_68 ;
V_62 . V_26 = V_64 . V_69 ;
V_62 . V_32 = F_20 () ;
V_62 . V_13 = V_27 ;
V_62 . V_70 = sizeof( struct V_10 ) ;
if ( F_21 ( ! V_62 . V_13 ) )
return 0 ;
F_14 ( & log -> V_39 ) ;
F_24 ( log , sizeof( struct V_10 ) + V_62 . V_13 ) ;
V_13 = F_4 ( sizeof( V_62 ) , log -> V_3 - log -> V_33 ) ;
memcpy ( log -> V_14 + log -> V_33 , & V_62 , V_13 ) ;
memcpy ( log -> V_14 , ( char * ) & V_62 + V_13 , sizeof( V_62 ) - V_13 ) ;
V_33 = F_1 ( log , log -> V_33 + sizeof( struct V_10 ) ) ;
V_13 = F_4 ( V_27 , log -> V_3 - V_33 ) ;
if ( F_29 ( log -> V_14 + V_33 , V_13 , V_60 ) != V_13 ) {
F_16 ( & log -> V_39 ) ;
return - V_31 ;
}
if ( F_29 ( log -> V_14 , V_27 - V_13 , V_60 ) != V_27 - V_13 ) {
F_16 ( & log -> V_39 ) ;
return - V_31 ;
}
log -> V_33 = F_1 ( log , V_33 + V_27 ) ;
F_16 ( & log -> V_39 ) ;
F_30 ( & log -> V_40 ) ;
return V_13 ;
}
static struct V_1 * F_31 ( int V_71 )
{
struct V_1 * log ;
F_25 (log, &log_list, logs)
if ( log -> V_72 . V_71 == V_71 )
return log ;
return NULL ;
}
static int F_32 ( struct V_73 * V_73 , struct V_4 * V_4 )
{
struct V_1 * log ;
int V_36 ;
V_36 = F_33 ( V_73 , V_4 ) ;
if ( V_36 )
return V_36 ;
log = F_31 ( F_34 ( V_73 -> V_74 ) ) ;
if ( ! log )
return - V_75 ;
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 ;
V_8 = F_35 ( sizeof( struct V_7 ) , V_76 ) ;
if ( ! V_8 )
return - V_77 ;
V_8 -> log = log ;
V_8 -> V_30 = 1 ;
V_8 -> V_47 = F_36 ( V_73 -> V_78 ) ||
F_37 ( V_79 ) ;
F_38 ( & V_8 -> V_80 ) ;
F_14 ( & log -> V_39 ) ;
V_8 -> V_29 = log -> V_56 ;
F_39 ( & V_8 -> V_80 , & log -> V_81 ) ;
F_16 ( & log -> V_39 ) ;
V_4 -> V_9 = V_8 ;
} else
V_4 -> V_9 = log ;
return 0 ;
}
static int F_40 ( struct V_73 * V_82 , struct V_4 * V_4 )
{
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_1 * log = V_8 -> log ;
F_14 ( & log -> V_39 ) ;
F_41 ( & V_8 -> V_80 ) ;
F_16 ( & log -> V_39 ) ;
F_42 ( V_8 ) ;
}
return 0 ;
}
static unsigned int F_43 ( struct V_4 * V_4 , T_7 * V_37 )
{
struct V_7 * V_8 ;
struct V_1 * log ;
unsigned int V_36 = V_83 | V_84 ;
if ( ! ( V_4 -> V_5 & V_6 ) )
return V_36 ;
V_8 = V_4 -> V_9 ;
log = V_8 -> log ;
F_44 ( V_4 , & log -> V_40 , V_37 ) ;
F_14 ( & log -> V_39 ) ;
if ( ! V_8 -> V_47 )
V_8 -> V_29 = F_10 ( log ,
V_8 -> V_29 , F_20 () ) ;
if ( log -> V_33 != V_8 -> V_29 )
V_36 |= V_85 | V_86 ;
F_16 ( & log -> V_39 ) ;
return V_36 ;
}
static long F_45 ( struct V_7 * V_8 , void T_4 * V_87 )
{
int V_88 ;
if ( F_46 ( & V_88 , V_87 , sizeof( int ) ) )
return - V_31 ;
if ( ( V_88 < 1 ) || ( V_88 > 2 ) )
return - V_48 ;
V_8 -> V_30 = V_88 ;
return 0 ;
}
static long F_47 ( struct V_4 * V_4 , unsigned int V_89 , unsigned long V_87 )
{
struct V_1 * log = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
long V_36 = - V_48 ;
void T_4 * V_90 = ( void T_4 * ) V_87 ;
F_14 ( & log -> V_39 ) ;
switch ( V_89 ) {
case V_91 :
V_36 = log -> V_3 ;
break;
case V_92 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_93 ;
break;
}
V_8 = V_4 -> V_9 ;
if ( log -> V_33 >= V_8 -> V_29 )
V_36 = log -> V_33 - V_8 -> V_29 ;
else
V_36 = ( log -> V_3 - V_8 -> V_29 ) + log -> V_33 ;
break;
case V_94 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_93 ;
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
case V_95 :
if ( ! ( V_4 -> V_5 & V_96 ) ) {
V_36 = - V_93 ;
break;
}
if ( ! ( F_36 ( F_48 ( V_4 ) -> V_78 ) ||
F_37 ( V_79 ) ) ) {
V_36 = - V_97 ;
break;
}
F_25 (reader, &log->readers, list)
V_8 -> V_29 = log -> V_33 ;
log -> V_56 = log -> V_33 ;
V_36 = 0 ;
break;
case V_98 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_93 ;
break;
}
V_8 = V_4 -> V_9 ;
V_36 = V_8 -> V_30 ;
break;
case V_99 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_36 = - V_93 ;
break;
}
V_8 = V_4 -> V_9 ;
V_36 = F_45 ( V_8 , V_90 ) ;
break;
}
F_16 ( & log -> V_39 ) ;
return V_36 ;
}
static int T_8 F_49 ( char * V_100 , int V_3 )
{
int V_36 = 0 ;
struct V_1 * log ;
unsigned char * V_14 ;
V_14 = F_50 ( V_3 ) ;
if ( V_14 == NULL )
return - V_77 ;
log = F_51 ( sizeof( struct V_1 ) , V_76 ) ;
if ( log == NULL ) {
V_36 = - V_77 ;
goto V_101;
}
log -> V_14 = V_14 ;
log -> V_72 . V_71 = V_102 ;
log -> V_72 . V_103 = F_52 ( V_100 , V_76 ) ;
if ( log -> V_72 . V_103 == NULL ) {
V_36 = - V_77 ;
goto V_104;
}
log -> V_72 . V_105 = & V_106 ;
log -> V_72 . V_107 = NULL ;
F_53 ( & log -> V_40 ) ;
F_38 ( & log -> V_81 ) ;
F_54 ( & log -> V_39 ) ;
log -> V_33 = 0 ;
log -> V_56 = 0 ;
log -> V_3 = V_3 ;
F_38 ( & log -> V_108 ) ;
F_39 ( & log -> V_108 , & V_109 ) ;
V_36 = F_55 ( & log -> V_72 ) ;
if ( F_21 ( V_36 ) ) {
F_56 ( L_1 ,
log -> V_72 . V_103 ) ;
goto V_110;
}
F_57 ( L_2 ,
( unsigned long ) log -> V_3 >> 10 , log -> V_72 . V_103 ) ;
return 0 ;
V_110:
F_42 ( log -> V_72 . V_103 ) ;
V_104:
F_42 ( log ) ;
V_101:
F_58 ( V_14 ) ;
return V_36 ;
}
static int T_8 F_59 ( void )
{
int V_36 ;
V_36 = F_49 ( V_111 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_36 = F_49 ( V_112 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_36 = F_49 ( V_113 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_36 = F_49 ( V_114 , 256 * 1024 ) ;
if ( F_21 ( V_36 ) )
goto V_49;
V_49:
return V_36 ;
}
static void T_9 F_60 ( void )
{
struct V_1 * V_115 , * V_116 ;
F_61 (current_log, next_log, &log_list, logs) {
F_62 ( & V_115 -> V_72 ) ;
F_58 ( V_115 -> V_14 ) ;
F_42 ( V_115 -> V_72 . V_103 ) ;
F_41 ( & V_115 -> V_108 ) ;
F_42 ( V_115 ) ;
}
}
