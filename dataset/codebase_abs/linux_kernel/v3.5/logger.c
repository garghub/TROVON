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
static T_2 F_3 ( struct V_1 * log , T_1 V_10 )
{
T_3 V_11 ;
( ( V_12 * ) & V_11 ) [ 0 ] = log -> V_13 [ V_10 ] ;
if ( F_4 ( V_10 + 1 < log -> V_3 ) )
( ( V_12 * ) & V_11 ) [ 1 ] = log -> V_13 [ V_10 + 1 ] ;
else
( ( V_12 * ) & V_11 ) [ 1 ] = log -> V_13 [ 0 ] ;
return sizeof( struct V_14 ) + V_11 ;
}
static T_4 F_5 ( struct V_1 * log ,
struct V_7 * V_8 ,
char T_5 * V_15 ,
T_1 V_16 )
{
T_1 V_17 ;
V_17 = F_6 ( V_16 , log -> V_3 - V_8 -> V_18 ) ;
if ( F_7 ( V_15 , log -> V_13 + V_8 -> V_18 , V_17 ) )
return - V_19 ;
if ( V_16 != V_17 )
if ( F_7 ( V_15 + V_17 , log -> V_13 , V_16 - V_17 ) )
return - V_19 ;
V_8 -> V_18 = F_1 ( log , V_8 -> V_18 + V_16 ) ;
return V_16 ;
}
static T_4 F_8 ( struct V_4 * V_4 , char T_5 * V_15 ,
T_1 V_16 , T_6 * V_20 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_1 * log = V_8 -> log ;
T_4 V_21 ;
F_9 ( V_22 ) ;
V_23:
while ( 1 ) {
F_10 ( & log -> V_24 ) ;
F_11 ( & log -> V_25 , & V_22 , V_26 ) ;
V_21 = ( log -> V_27 == V_8 -> V_18 ) ;
F_12 ( & log -> V_24 ) ;
if ( ! V_21 )
break;
if ( V_4 -> V_28 & V_29 ) {
V_21 = - V_30 ;
break;
}
if ( F_13 ( V_31 ) ) {
V_21 = - V_32 ;
break;
}
F_14 () ;
}
F_15 ( & log -> V_25 , & V_22 ) ;
if ( V_21 )
return V_21 ;
F_10 ( & log -> V_24 ) ;
if ( F_16 ( log -> V_27 == V_8 -> V_18 ) ) {
F_12 ( & log -> V_24 ) ;
goto V_23;
}
V_21 = F_3 ( log , V_8 -> V_18 ) ;
if ( V_16 < V_21 ) {
V_21 = - V_33 ;
goto V_34;
}
V_21 = F_5 ( log , V_8 , V_15 , V_21 ) ;
V_34:
F_12 ( & log -> V_24 ) ;
return V_21 ;
}
static T_1 F_17 ( struct V_1 * log , T_1 V_10 , T_1 V_17 )
{
T_1 V_16 = 0 ;
do {
T_1 V_35 = F_3 ( log , V_10 ) ;
V_10 = F_1 ( log , V_10 + V_35 ) ;
V_16 += V_35 ;
} while ( V_16 < V_17 );
return V_10 ;
}
static inline int F_18 ( T_1 V_36 , T_1 V_37 , T_1 V_38 )
{
if ( V_36 < V_37 ) {
if ( V_36 < V_38 && V_38 <= V_37 )
return 1 ;
} else {
if ( V_38 <= V_37 || V_36 < V_38 )
return 1 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * log , T_1 V_17 )
{
T_1 V_39 = log -> V_27 ;
T_1 V_40 = F_1 ( log , V_39 + V_17 ) ;
struct V_7 * V_8 ;
if ( F_18 ( V_39 , V_40 , log -> V_41 ) )
log -> V_41 = F_17 ( log , log -> V_41 , V_17 ) ;
F_20 (reader, &log->readers, list)
if ( F_18 ( V_39 , V_40 , V_8 -> V_18 ) )
V_8 -> V_18 = F_17 ( log , V_8 -> V_18 , V_17 ) ;
}
static void F_21 ( struct V_1 * log , const void * V_15 , T_1 V_16 )
{
T_1 V_17 ;
V_17 = F_6 ( V_16 , log -> V_3 - log -> V_27 ) ;
memcpy ( log -> V_13 + log -> V_27 , V_15 , V_17 ) ;
if ( V_16 != V_17 )
memcpy ( log -> V_13 , V_15 + V_17 , V_16 - V_17 ) ;
log -> V_27 = F_1 ( log , log -> V_27 + V_16 ) ;
}
static T_4 F_22 ( struct V_1 * log ,
const void T_5 * V_15 , T_1 V_16 )
{
T_1 V_17 ;
V_17 = F_6 ( V_16 , log -> V_3 - log -> V_27 ) ;
if ( V_17 && F_23 ( log -> V_13 + log -> V_27 , V_15 , V_17 ) )
return - V_19 ;
if ( V_16 != V_17 )
if ( F_23 ( log -> V_13 , V_15 + V_17 , V_16 - V_17 ) )
return - V_19 ;
log -> V_27 = F_1 ( log , log -> V_27 + V_16 ) ;
return V_16 ;
}
static T_4 F_24 ( struct V_42 * V_43 , const struct V_44 * V_45 ,
unsigned long V_46 , T_6 V_47 )
{
struct V_1 * log = F_2 ( V_43 -> V_48 ) ;
T_1 V_49 = log -> V_27 ;
struct V_14 V_50 ;
struct V_51 V_52 ;
T_4 V_21 = 0 ;
V_52 = F_25 () ;
V_50 . V_53 = V_31 -> V_54 ;
V_50 . V_55 = V_31 -> V_53 ;
V_50 . V_56 = V_52 . V_57 ;
V_50 . V_58 = V_52 . V_59 ;
V_50 . V_17 = F_26 ( T_1 , V_43 -> V_60 , V_61 ) ;
if ( F_16 ( ! V_50 . V_17 ) )
return 0 ;
F_10 ( & log -> V_24 ) ;
F_19 ( log , sizeof( struct V_14 ) + V_50 . V_17 ) ;
F_21 ( log , & V_50 , sizeof( struct V_14 ) ) ;
while ( V_46 -- > 0 ) {
T_1 V_17 ;
T_4 V_35 ;
V_17 = F_26 ( T_1 , V_45 -> V_62 , V_50 . V_17 - V_21 ) ;
V_35 = F_22 ( log , V_45 -> V_63 , V_17 ) ;
if ( F_16 ( V_35 < 0 ) ) {
log -> V_27 = V_49 ;
F_12 ( & log -> V_24 ) ;
return V_35 ;
}
V_45 ++ ;
V_21 += V_35 ;
}
F_12 ( & log -> V_24 ) ;
F_27 ( & log -> V_25 ) ;
return V_21 ;
}
static struct V_1 * F_28 ( int V_64 )
{
struct V_1 * log ;
F_20 (log, &log_list, logs)
if ( log -> V_65 . V_64 == V_64 )
return log ;
return NULL ;
}
static int F_29 ( struct V_66 * V_66 , struct V_4 * V_4 )
{
struct V_1 * log ;
int V_21 ;
V_21 = F_30 ( V_66 , V_4 ) ;
if ( V_21 )
return V_21 ;
log = F_28 ( F_31 ( V_66 -> V_67 ) ) ;
if ( ! log )
return - V_68 ;
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 ;
V_8 = F_32 ( sizeof( struct V_7 ) , V_69 ) ;
if ( ! V_8 )
return - V_70 ;
V_8 -> log = log ;
F_33 ( & V_8 -> V_71 ) ;
F_10 ( & log -> V_24 ) ;
V_8 -> V_18 = log -> V_41 ;
F_34 ( & V_8 -> V_71 , & log -> V_72 ) ;
F_12 ( & log -> V_24 ) ;
V_4 -> V_9 = V_8 ;
} else
V_4 -> V_9 = log ;
return 0 ;
}
static int F_35 ( struct V_66 * V_73 , struct V_4 * V_4 )
{
if ( V_4 -> V_5 & V_6 ) {
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_1 * log = V_8 -> log ;
F_10 ( & log -> V_24 ) ;
F_36 ( & V_8 -> V_71 ) ;
F_12 ( & log -> V_24 ) ;
F_37 ( V_8 ) ;
}
return 0 ;
}
static unsigned int F_38 ( struct V_4 * V_4 , T_7 * V_22 )
{
struct V_7 * V_8 ;
struct V_1 * log ;
unsigned int V_21 = V_74 | V_75 ;
if ( ! ( V_4 -> V_5 & V_6 ) )
return V_21 ;
V_8 = V_4 -> V_9 ;
log = V_8 -> log ;
F_39 ( V_4 , & log -> V_25 , V_22 ) ;
F_10 ( & log -> V_24 ) ;
if ( log -> V_27 != V_8 -> V_18 )
V_21 |= V_76 | V_77 ;
F_12 ( & log -> V_24 ) ;
return V_21 ;
}
static long F_40 ( struct V_4 * V_4 , unsigned int V_78 , unsigned long V_79 )
{
struct V_1 * log = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
long V_21 = - V_80 ;
F_10 ( & log -> V_24 ) ;
switch ( V_78 ) {
case V_81 :
V_21 = log -> V_3 ;
break;
case V_82 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_21 = - V_83 ;
break;
}
V_8 = V_4 -> V_9 ;
if ( log -> V_27 >= V_8 -> V_18 )
V_21 = log -> V_27 - V_8 -> V_18 ;
else
V_21 = ( log -> V_3 - V_8 -> V_18 ) + log -> V_27 ;
break;
case V_84 :
if ( ! ( V_4 -> V_5 & V_6 ) ) {
V_21 = - V_83 ;
break;
}
V_8 = V_4 -> V_9 ;
if ( log -> V_27 != V_8 -> V_18 )
V_21 = F_3 ( log , V_8 -> V_18 ) ;
else
V_21 = 0 ;
break;
case V_85 :
if ( ! ( V_4 -> V_5 & V_86 ) ) {
V_21 = - V_83 ;
break;
}
F_20 (reader, &log->readers, list)
V_8 -> V_18 = log -> V_27 ;
log -> V_41 = log -> V_27 ;
V_21 = 0 ;
break;
}
F_12 ( & log -> V_24 ) ;
return V_21 ;
}
static int T_8 F_41 ( char * V_87 , int V_3 )
{
int V_21 = 0 ;
struct V_1 * log ;
unsigned char * V_13 ;
V_13 = F_42 ( V_3 ) ;
if ( V_13 == NULL )
return - V_70 ;
log = F_43 ( sizeof( struct V_1 ) , V_69 ) ;
if ( log == NULL ) {
V_21 = - V_70 ;
goto V_88;
}
log -> V_13 = V_13 ;
log -> V_65 . V_64 = V_89 ;
log -> V_65 . V_90 = F_44 ( V_87 , V_69 ) ;
if ( log -> V_65 . V_90 == NULL ) {
V_21 = - V_70 ;
goto V_91;
}
log -> V_65 . V_92 = & V_93 ;
log -> V_65 . V_94 = NULL ;
F_45 ( & log -> V_25 ) ;
F_33 ( & log -> V_72 ) ;
F_46 ( & log -> V_24 ) ;
log -> V_27 = 0 ;
log -> V_41 = 0 ;
log -> V_3 = V_3 ;
F_33 ( & log -> V_95 ) ;
F_34 ( & log -> V_95 , & V_96 ) ;
V_21 = F_47 ( & log -> V_65 ) ;
if ( F_16 ( V_21 ) ) {
F_48 ( V_97 L_1
L_2 , log -> V_65 . V_90 ) ;
goto V_91;
}
F_48 ( V_98 L_3 ,
( unsigned long ) log -> V_3 >> 10 , log -> V_65 . V_90 ) ;
return 0 ;
V_91:
F_37 ( log ) ;
V_88:
F_49 ( V_13 ) ;
return V_21 ;
}
static int T_8 F_50 ( void )
{
int V_21 ;
V_21 = F_41 ( V_99 , 256 * 1024 ) ;
if ( F_16 ( V_21 ) )
goto V_34;
V_21 = F_41 ( V_100 , 256 * 1024 ) ;
if ( F_16 ( V_21 ) )
goto V_34;
V_21 = F_41 ( V_101 , 256 * 1024 ) ;
if ( F_16 ( V_21 ) )
goto V_34;
V_21 = F_41 ( V_102 , 256 * 1024 ) ;
if ( F_16 ( V_21 ) )
goto V_34;
V_34:
return V_21 ;
}
