static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( V_2 -> V_3 & V_4 ) {
struct V_5 * V_6 = V_2 -> V_7 ;
return V_6 -> log ;
} else
return V_2 -> V_7 ;
}
static T_1 F_2 ( struct V_1 * log , T_2 V_8 )
{
T_3 V_9 ;
switch ( log -> V_10 - V_8 ) {
case 1 :
memcpy ( & V_9 , log -> V_11 + V_8 , 1 ) ;
memcpy ( ( ( char * ) & V_9 ) + 1 , log -> V_11 , 1 ) ;
break;
default:
memcpy ( & V_9 , log -> V_11 + V_8 , 2 ) ;
}
return sizeof( struct V_12 ) + V_9 ;
}
static T_4 F_3 ( struct V_1 * log ,
struct V_5 * V_6 ,
char T_5 * V_13 ,
T_2 V_14 )
{
T_2 V_15 ;
V_15 = F_4 ( V_14 , log -> V_10 - V_6 -> V_16 ) ;
if ( F_5 ( V_13 , log -> V_11 + V_6 -> V_16 , V_15 ) )
return - V_17 ;
if ( V_14 != V_15 )
if ( F_5 ( V_13 + V_15 , log -> V_11 , V_14 - V_15 ) )
return - V_17 ;
V_6 -> V_16 = F_6 ( V_6 -> V_16 + V_14 ) ;
return V_14 ;
}
static T_4 F_7 ( struct V_2 * V_2 , char T_5 * V_13 ,
T_2 V_14 , T_6 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_1 * log = V_6 -> log ;
T_4 V_19 ;
F_8 ( V_20 ) ;
V_21:
while ( 1 ) {
F_9 ( & log -> V_22 , & V_20 , V_23 ) ;
F_10 ( & log -> V_24 ) ;
V_19 = ( log -> V_25 == V_6 -> V_16 ) ;
F_11 ( & log -> V_24 ) ;
if ( ! V_19 )
break;
if ( V_2 -> V_26 & V_27 ) {
V_19 = - V_28 ;
break;
}
if ( F_12 ( V_29 ) ) {
V_19 = - V_30 ;
break;
}
F_13 () ;
}
F_14 ( & log -> V_22 , & V_20 ) ;
if ( V_19 )
return V_19 ;
F_10 ( & log -> V_24 ) ;
if ( F_15 ( log -> V_25 == V_6 -> V_16 ) ) {
F_11 ( & log -> V_24 ) ;
goto V_21;
}
V_19 = F_2 ( log , V_6 -> V_16 ) ;
if ( V_14 < V_19 ) {
V_19 = - V_31 ;
goto V_32;
}
V_19 = F_3 ( log , V_6 , V_13 , V_19 ) ;
V_32:
F_11 ( & log -> V_24 ) ;
return V_19 ;
}
static T_2 F_16 ( struct V_1 * log , T_2 V_8 , T_2 V_15 )
{
T_2 V_14 = 0 ;
do {
T_2 V_33 = F_2 ( log , V_8 ) ;
V_8 = F_6 ( V_8 + V_33 ) ;
V_14 += V_33 ;
} while ( V_14 < V_15 );
return V_8 ;
}
static inline int F_17 ( T_2 V_34 , T_2 V_35 , T_2 V_36 )
{
if ( V_35 < V_34 ) {
if ( V_34 < V_36 || V_35 >= V_36 )
return 1 ;
} else {
if ( V_34 < V_36 && V_35 >= V_36 )
return 1 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * log , T_2 V_15 )
{
T_2 V_37 = log -> V_25 ;
T_2 V_38 = F_6 ( V_37 + V_15 ) ;
struct V_5 * V_6 ;
if ( F_17 ( V_37 , V_38 , log -> V_39 ) )
log -> V_39 = F_16 ( log , log -> V_39 , V_15 ) ;
F_19 (reader, &log->readers, list)
if ( F_17 ( V_37 , V_38 , V_6 -> V_16 ) )
V_6 -> V_16 = F_16 ( log , V_6 -> V_16 , V_15 ) ;
}
static void F_20 ( struct V_1 * log , const void * V_13 , T_2 V_14 )
{
T_2 V_15 ;
V_15 = F_4 ( V_14 , log -> V_10 - log -> V_25 ) ;
memcpy ( log -> V_11 + log -> V_25 , V_13 , V_15 ) ;
if ( V_14 != V_15 )
memcpy ( log -> V_11 , V_13 + V_15 , V_14 - V_15 ) ;
log -> V_25 = F_6 ( log -> V_25 + V_14 ) ;
}
static T_4 F_21 ( struct V_1 * log ,
const void T_5 * V_13 , T_2 V_14 )
{
T_2 V_15 ;
V_15 = F_4 ( V_14 , log -> V_10 - log -> V_25 ) ;
if ( V_15 && F_22 ( log -> V_11 + log -> V_25 , V_13 , V_15 ) )
return - V_17 ;
if ( V_14 != V_15 )
if ( F_22 ( log -> V_11 , V_13 + V_15 , V_14 - V_15 ) )
return - V_17 ;
log -> V_25 = F_6 ( log -> V_25 + V_14 ) ;
return V_14 ;
}
T_4 F_23 ( struct V_40 * V_41 , const struct V_42 * V_43 ,
unsigned long V_44 , T_6 V_45 )
{
struct V_1 * log = F_1 ( V_41 -> V_46 ) ;
T_2 V_47 = log -> V_25 ;
struct V_12 V_48 ;
struct V_49 V_50 ;
T_4 V_19 = 0 ;
V_50 = F_24 () ;
V_48 . V_51 = V_29 -> V_52 ;
V_48 . V_53 = V_29 -> V_51 ;
V_48 . V_54 = V_50 . V_55 ;
V_48 . V_56 = V_50 . V_57 ;
V_48 . V_15 = F_25 ( T_2 , V_41 -> V_58 , V_59 ) ;
if ( F_15 ( ! V_48 . V_15 ) )
return 0 ;
F_10 ( & log -> V_24 ) ;
F_18 ( log , sizeof( struct V_12 ) + V_48 . V_15 ) ;
F_20 ( log , & V_48 , sizeof( struct V_12 ) ) ;
while ( V_44 -- > 0 ) {
T_2 V_15 ;
T_4 V_33 ;
V_15 = F_25 ( T_2 , V_43 -> V_60 , V_48 . V_15 - V_19 ) ;
V_33 = F_21 ( log , V_43 -> V_61 , V_15 ) ;
if ( F_15 ( V_33 < 0 ) ) {
log -> V_25 = V_47 ;
F_11 ( & log -> V_24 ) ;
return V_33 ;
}
V_43 ++ ;
V_19 += V_33 ;
}
F_11 ( & log -> V_24 ) ;
F_26 ( & log -> V_22 ) ;
return V_19 ;
}
static int F_27 ( struct V_62 * V_62 , struct V_2 * V_2 )
{
struct V_1 * log ;
int V_19 ;
V_19 = F_28 ( V_62 , V_2 ) ;
if ( V_19 )
return V_19 ;
log = F_29 ( F_30 ( V_62 -> V_63 ) ) ;
if ( ! log )
return - V_64 ;
if ( V_2 -> V_3 & V_4 ) {
struct V_5 * V_6 ;
V_6 = F_31 ( sizeof( struct V_5 ) , V_65 ) ;
if ( ! V_6 )
return - V_66 ;
V_6 -> log = log ;
F_32 ( & V_6 -> V_67 ) ;
F_10 ( & log -> V_24 ) ;
V_6 -> V_16 = log -> V_39 ;
F_33 ( & V_6 -> V_67 , & log -> V_68 ) ;
F_11 ( & log -> V_24 ) ;
V_2 -> V_7 = V_6 ;
} else
V_2 -> V_7 = log ;
return 0 ;
}
static int F_34 ( struct V_62 * V_69 , struct V_2 * V_2 )
{
if ( V_2 -> V_3 & V_4 ) {
struct V_5 * V_6 = V_2 -> V_7 ;
F_35 ( & V_6 -> V_67 ) ;
F_36 ( V_6 ) ;
}
return 0 ;
}
static unsigned int F_37 ( struct V_2 * V_2 , T_7 * V_20 )
{
struct V_5 * V_6 ;
struct V_1 * log ;
unsigned int V_19 = V_70 | V_71 ;
if ( ! ( V_2 -> V_3 & V_4 ) )
return V_19 ;
V_6 = V_2 -> V_7 ;
log = V_6 -> log ;
F_38 ( V_2 , & log -> V_22 , V_20 ) ;
F_10 ( & log -> V_24 ) ;
if ( log -> V_25 != V_6 -> V_16 )
V_19 |= V_72 | V_73 ;
F_11 ( & log -> V_24 ) ;
return V_19 ;
}
static long F_39 ( struct V_2 * V_2 , unsigned int V_74 , unsigned long V_75 )
{
struct V_1 * log = F_1 ( V_2 ) ;
struct V_5 * V_6 ;
long V_19 = - V_76 ;
F_10 ( & log -> V_24 ) ;
switch ( V_74 ) {
case V_77 :
V_19 = log -> V_10 ;
break;
case V_78 :
if ( ! ( V_2 -> V_3 & V_4 ) ) {
V_19 = - V_79 ;
break;
}
V_6 = V_2 -> V_7 ;
if ( log -> V_25 >= V_6 -> V_16 )
V_19 = log -> V_25 - V_6 -> V_16 ;
else
V_19 = ( log -> V_10 - V_6 -> V_16 ) + log -> V_25 ;
break;
case V_80 :
if ( ! ( V_2 -> V_3 & V_4 ) ) {
V_19 = - V_79 ;
break;
}
V_6 = V_2 -> V_7 ;
if ( log -> V_25 != V_6 -> V_16 )
V_19 = F_2 ( log , V_6 -> V_16 ) ;
else
V_19 = 0 ;
break;
case V_81 :
if ( ! ( V_2 -> V_3 & V_82 ) ) {
V_19 = - V_79 ;
break;
}
F_19 (reader, &log->readers, list)
V_6 -> V_16 = log -> V_25 ;
log -> V_39 = log -> V_25 ;
V_19 = 0 ;
break;
}
F_11 ( & log -> V_24 ) ;
return V_19 ;
}
static struct V_1 * F_29 ( int V_83 )
{
if ( V_84 . V_85 . V_83 == V_83 )
return & V_84 ;
if ( V_86 . V_85 . V_83 == V_83 )
return & V_86 ;
if ( V_87 . V_85 . V_83 == V_83 )
return & V_87 ;
if ( V_88 . V_85 . V_83 == V_83 )
return & V_88 ;
return NULL ;
}
static int T_8 F_40 ( struct V_1 * log )
{
int V_19 ;
V_19 = F_41 ( & log -> V_85 ) ;
if ( F_15 ( V_19 ) ) {
F_42 ( V_89 L_1
L_2 , log -> V_85 . V_90 ) ;
return V_19 ;
}
F_42 ( V_91 L_3 ,
( unsigned long ) log -> V_10 >> 10 , log -> V_85 . V_90 ) ;
return 0 ;
}
static int T_8 F_43 ( void )
{
int V_19 ;
V_19 = F_40 ( & V_84 ) ;
if ( F_15 ( V_19 ) )
goto V_32;
V_19 = F_40 ( & V_86 ) ;
if ( F_15 ( V_19 ) )
goto V_32;
V_19 = F_40 ( & V_87 ) ;
if ( F_15 ( V_19 ) )
goto V_32;
V_19 = F_40 ( & V_88 ) ;
if ( F_15 ( V_19 ) )
goto V_32;
V_32:
return V_19 ;
}
