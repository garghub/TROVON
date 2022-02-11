static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( V_2 , V_6 -> V_7 , V_4 -> V_8 , V_9 ) ;
F_2 ( V_2 , V_6 -> V_10 , V_4 -> V_11 , V_12 ) ;
if ( V_4 -> V_13 )
F_3 ( V_2 , V_4 -> V_14 , V_4 -> V_13 ,
V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 = & V_4 -> V_22 . V_23 ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_26 , V_20 -> V_27 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_28 * V_22 = & V_4 -> V_22 . V_29 ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
F_3 ( V_2 , V_22 -> V_30 , V_20 -> V_31 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_32 , T_1 V_33 , void * V_34 )
{
struct V_5 * V_6 = V_34 ;
struct V_3 * V_4 ;
if ( V_33 )
F_9 ( V_2 , V_33 ) ;
V_4 = F_10 ( V_32 , struct V_3 , V_35 [ 0 ] ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_11 ( V_4 ) ;
F_12 ( V_6 , V_33 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 * V_32 , T_1 V_33 ,
void * V_34 )
{
struct V_5 * V_6 = V_34 ;
struct V_3 * V_4 ;
if ( V_33 )
F_9 ( V_2 , V_33 ) ;
V_4 = F_10 ( V_32 , struct V_3 , V_35 [ 0 ] ) ;
F_7 ( V_2 , V_4 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 ) ;
F_11 ( V_4 ) ;
F_12 ( V_6 , V_33 ) ;
}
static struct V_3 * F_14 ( struct V_5 * V_6 ,
T_2 V_36 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 ;
T_3 V_37 = ( V_6 -> V_38 . V_37 & ( V_39 |
V_40 ) ) ? V_41 : V_42 ;
int V_43 ;
int V_44 , V_45 = 0 , V_13 ;
int V_11 , V_8 ;
V_11 = F_15 ( V_6 -> V_10 , V_6 -> V_46 ) ;
V_8 = F_15 ( V_6 -> V_7 , V_6 -> V_47 ) ;
if ( V_11 > 1 )
V_45 = V_11 ;
if ( V_8 > 1 )
V_45 += V_8 ;
V_13 = V_45 * sizeof( struct V_48 ) ;
V_4 = F_16 ( sizeof( * V_4 ) + V_36 + V_13 ,
V_49 | V_37 ) ;
if ( ! V_4 )
return F_17 ( - V_50 ) ;
V_43 = F_18 ( V_2 , V_6 -> V_10 , V_11 , V_12 ) ;
if ( F_19 ( ! V_43 ) ) {
F_20 ( V_2 , L_1 ) ;
goto V_51;
}
V_43 = F_18 ( V_2 , V_6 -> V_7 , V_8 , V_9 ) ;
if ( F_19 ( ! V_43 ) ) {
F_20 ( V_2 , L_2 ) ;
goto V_52;
}
V_4 -> V_53 = ( void * ) V_4 + sizeof( * V_4 ) + V_36 ;
V_44 = 0 ;
if ( V_11 > 1 ) {
F_21 ( V_6 -> V_10 , V_11 , V_4 -> V_53 , 0 ) ;
V_44 += V_11 ;
}
if ( V_8 > 1 )
F_21 ( V_6 -> V_7 , V_8 ,
V_4 -> V_53 + V_44 , 0 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_8 = V_8 ;
if ( ! V_13 )
return V_4 ;
V_4 -> V_14 = F_22 ( V_2 , V_4 -> V_53 ,
V_13 , V_12 ) ;
if ( F_23 ( V_2 , V_4 -> V_14 ) ) {
F_20 ( V_2 , L_3 ) ;
goto V_54;
}
V_4 -> V_13 = V_13 ;
return V_4 ;
V_54:
F_2 ( V_2 , V_6 -> V_7 , V_8 , V_9 ) ;
V_52:
F_2 ( V_2 , V_6 -> V_10 , V_11 , V_12 ) ;
V_51:
F_11 ( V_4 ) ;
return F_17 ( - V_50 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_21 * V_22 = & V_4 -> V_22 . V_23 ;
int V_44 = 0 ;
V_22 -> V_24 = F_22 ( V_2 , V_20 -> V_55 , V_20 -> V_25 , V_12 ) ;
if ( F_23 ( V_2 , V_22 -> V_24 ) ) {
F_20 ( V_2 , L_4 ) ;
return - V_50 ;
}
V_22 -> V_26 = F_22 ( V_2 , V_20 -> V_56 , V_20 -> V_27 , V_12 ) ;
if ( F_23 ( V_2 , V_22 -> V_26 ) ) {
F_20 ( V_2 , L_5 ) ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
return - V_50 ;
}
if ( V_4 -> V_11 > 1 ) {
V_22 -> V_57 |= V_58 ;
V_22 -> V_59 = V_4 -> V_14 ;
V_44 += V_4 -> V_11 ;
} else {
V_22 -> V_59 = F_25 ( V_6 -> V_10 ) ;
}
if ( V_4 -> V_8 > 1 ) {
V_22 -> V_57 |= V_60 ;
V_22 -> V_61 = V_4 -> V_14 +
V_44 * sizeof( struct V_48 ) ;
} else {
V_22 -> V_61 = F_25 ( V_6 -> V_7 ) ;
}
V_22 -> V_57 |= ( V_20 -> V_27 << V_62 ) | V_20 -> V_25 ;
V_22 -> V_63 = V_6 -> V_46 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_28 * V_22 = & V_4 -> V_22 . V_29 ;
int V_44 = 0 ;
V_22 -> V_24 = F_22 ( V_2 , V_20 -> V_55 , V_20 -> V_25 , V_12 ) ;
if ( F_23 ( V_2 , V_22 -> V_24 ) ) {
F_20 ( V_2 , L_6 ) ;
return - V_50 ;
}
V_22 -> V_30 = F_22 ( V_2 , V_20 -> V_64 , V_20 -> V_31 , V_12 ) ;
if ( F_23 ( V_2 , V_22 -> V_30 ) ) {
F_20 ( V_2 , L_7 ) ;
F_3 ( V_2 , V_22 -> V_24 , V_20 -> V_25 , V_12 ) ;
return - V_50 ;
}
if ( V_4 -> V_11 > 1 ) {
V_22 -> V_57 |= V_65 ;
V_22 -> V_61 = V_4 -> V_14 ;
V_44 += V_4 -> V_11 ;
} else {
V_22 -> V_61 = F_25 ( V_6 -> V_10 ) ;
}
if ( V_4 -> V_8 > 1 ) {
V_22 -> V_57 |= V_66 ;
V_22 -> V_59 = V_4 -> V_14 +
V_44 * sizeof( struct V_48 ) ;
} else {
V_22 -> V_59 = F_25 ( V_6 -> V_7 ) ;
}
V_22 -> V_57 |= ( V_20 -> V_31 << V_67 ) | V_20 -> V_25 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_68 = V_18 -> V_2 ;
struct V_3 * V_4 ;
int V_69 ;
if ( F_19 ( ! V_20 -> V_55 || ! V_20 -> V_56 ) )
return - V_70 ;
if ( V_6 -> V_47 < V_20 -> V_25 ) {
V_6 -> V_47 = V_20 -> V_25 ;
F_20 ( V_68 , L_8 ) ;
return - V_71 ;
}
V_4 = F_14 ( V_6 , V_72 ) ;
if ( F_28 ( V_4 ) )
return F_29 ( V_4 ) ;
V_69 = F_24 ( V_6 , V_4 ) ;
if ( V_69 )
goto V_73;
F_30 ( V_4 -> V_35 , & V_4 -> V_22 . V_23 ) ;
V_69 = F_31 ( V_68 , V_4 -> V_35 , F_8 , V_6 ) ;
if ( ! V_69 )
return - V_74 ;
F_4 ( V_68 , V_4 , V_6 ) ;
V_73:
F_1 ( V_68 , V_4 , V_6 ) ;
F_11 ( V_4 ) ;
return V_69 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_5 ( V_6 ) ;
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_68 = V_18 -> V_2 ;
struct V_3 * V_4 ;
int V_69 ;
if ( F_19 ( ! V_20 -> V_55 || ! V_20 -> V_64 ) )
return - V_70 ;
if ( V_6 -> V_47 < V_20 -> V_25 ) {
V_6 -> V_47 = V_20 -> V_25 ;
F_20 ( V_68 , L_8 ) ;
return - V_71 ;
}
V_4 = F_14 ( V_6 , V_75 ) ;
if ( F_28 ( V_4 ) )
return F_29 ( V_4 ) ;
V_69 = F_26 ( V_6 , V_4 ) ;
if ( V_69 )
goto V_73;
F_33 ( V_4 -> V_35 , & V_4 -> V_22 . V_29 ) ;
V_69 = F_31 ( V_68 , V_4 -> V_35 , F_13 , V_6 ) ;
if ( ! V_69 )
return - V_74 ;
F_7 ( V_68 , V_4 , V_6 ) ;
V_73:
F_1 ( V_68 , V_4 , V_6 ) ;
F_11 ( V_4 ) ;
return V_69 ;
}
static void F_34 ( struct V_19 * V_20 )
{
F_35 ( V_20 -> V_64 ) ;
F_11 ( V_20 -> V_56 ) ;
F_11 ( V_20 -> V_55 ) ;
V_20 -> V_64 = NULL ;
V_20 -> V_56 = NULL ;
V_20 -> V_55 = NULL ;
V_20 -> V_31 = 0 ;
V_20 -> V_27 = 0 ;
V_20 -> V_25 = 0 ;
}
static inline T_4 * F_36 ( const T_4 * V_76 , T_2 * V_77 )
{
T_4 * V_78 ;
while ( ! * V_76 && * V_77 ) {
V_76 ++ ;
( * V_77 ) -- ;
}
V_78 = F_16 ( * V_77 , V_49 | V_41 ) ;
if ( ! V_78 )
return NULL ;
memcpy ( V_78 , V_76 , * V_77 ) ;
return V_78 ;
}
static int F_37 ( unsigned int V_79 )
{
if ( V_79 > 4096 )
return - V_70 ;
return 0 ;
}
static int F_38 ( struct V_15 * V_16 , const void * V_20 ,
unsigned int V_80 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_81 V_82 = { NULL } ;
struct V_19 * V_81 = & V_18 -> V_20 ;
int V_69 ;
F_34 ( V_81 ) ;
V_69 = F_39 ( & V_82 , V_20 , V_80 ) ;
if ( V_69 )
return V_69 ;
V_81 -> V_56 = F_16 ( V_82 . V_27 , V_49 | V_41 ) ;
if ( ! V_81 -> V_56 )
goto V_33;
V_81 -> V_55 = F_36 ( V_82 . V_55 , & V_82 . V_25 ) ;
if ( ! V_81 -> V_55 )
goto V_33;
if ( F_37 ( V_82 . V_25 << 3 ) ) {
F_34 ( V_81 ) ;
return - V_70 ;
}
V_81 -> V_27 = V_82 . V_27 ;
V_81 -> V_25 = V_82 . V_25 ;
memcpy ( V_81 -> V_56 , V_82 . V_56 , V_82 . V_27 ) ;
return 0 ;
V_33:
F_34 ( V_81 ) ;
return - V_50 ;
}
static int F_40 ( struct V_15 * V_16 , const void * V_20 ,
unsigned int V_80 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_81 V_82 = { NULL } ;
struct V_19 * V_81 = & V_18 -> V_20 ;
int V_69 ;
F_34 ( V_81 ) ;
V_69 = F_41 ( & V_82 , V_20 , V_80 ) ;
if ( V_69 )
return V_69 ;
V_81 -> V_64 = F_16 ( V_82 . V_31 , V_49 | V_41 ) ;
if ( ! V_81 -> V_64 )
goto V_33;
V_81 -> V_56 = F_16 ( V_82 . V_27 , V_49 | V_41 ) ;
if ( ! V_81 -> V_56 )
goto V_33;
V_81 -> V_55 = F_36 ( V_82 . V_55 , & V_82 . V_25 ) ;
if ( ! V_81 -> V_55 )
goto V_33;
if ( F_37 ( V_82 . V_25 << 3 ) ) {
F_34 ( V_81 ) ;
return - V_70 ;
}
V_81 -> V_31 = V_82 . V_31 ;
V_81 -> V_27 = V_82 . V_27 ;
V_81 -> V_25 = V_82 . V_25 ;
memcpy ( V_81 -> V_64 , V_82 . V_64 , V_82 . V_31 ) ;
memcpy ( V_81 -> V_56 , V_82 . V_56 , V_82 . V_27 ) ;
return 0 ;
V_33:
F_34 ( V_81 ) ;
return - V_50 ;
}
static int F_42 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
return ( V_20 -> V_55 ) ? V_20 -> V_25 : - V_70 ;
}
static int F_43 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
V_18 -> V_2 = F_44 () ;
if ( F_28 ( V_18 -> V_2 ) ) {
F_45 ( L_9 ) ;
return F_29 ( V_18 -> V_2 ) ;
}
return 0 ;
}
static void F_46 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
F_34 ( V_20 ) ;
F_47 ( V_18 -> V_2 ) ;
}
static int T_5 F_48 ( void )
{
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_1 * V_87 ;
struct V_88 * V_89 ;
T_1 V_90 , V_91 ;
int V_33 ;
V_84 = F_49 ( NULL , NULL , L_10 ) ;
if ( ! V_84 ) {
V_84 = F_49 ( NULL , NULL , L_11 ) ;
if ( ! V_84 )
return - V_92 ;
}
V_86 = F_50 ( V_84 ) ;
if ( ! V_86 ) {
F_51 ( V_84 ) ;
return - V_92 ;
}
V_87 = & V_86 -> V_2 ;
V_89 = F_52 ( V_87 ) ;
F_51 ( V_84 ) ;
if ( ! V_89 )
return - V_92 ;
V_90 = F_53 ( & V_89 -> V_93 -> V_94 . V_95 ) ;
V_91 = ( V_90 & V_96 ) >> V_97 ;
if ( ! V_91 )
return - V_92 ;
V_33 = F_54 ( & V_98 ) ;
if ( V_33 )
F_55 ( V_87 , L_12 ,
V_98 . V_38 . V_99 ) ;
else
F_56 ( V_87 , L_13 ) ;
return V_33 ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_98 ) ;
}
