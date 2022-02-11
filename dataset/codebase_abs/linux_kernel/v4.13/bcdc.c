struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return V_5 -> V_8 ;
}
static int
F_2 ( struct V_2 * V_3 , int V_9 , T_1 V_10 , void * V_11 ,
T_1 V_12 , bool V_13 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_14 * V_15 = & V_5 -> V_15 ;
T_2 V_16 ;
F_3 ( V_17 , L_1 ) ;
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 -> V_10 = F_4 ( V_10 ) ;
V_15 -> V_12 = F_4 ( V_12 ) ;
V_16 = ( ++ V_5 -> V_18 << V_19 ) ;
if ( V_13 )
V_16 |= V_20 ;
V_16 = ( V_16 & ~ V_21 ) |
( V_9 << V_22 ) ;
V_15 -> V_16 = F_4 ( V_16 ) ;
if ( V_11 )
memcpy ( V_5 -> V_11 , V_11 , V_12 ) ;
V_12 += sizeof( * V_15 ) ;
if ( V_12 > V_23 )
V_12 = V_23 ;
return F_5 ( V_3 -> V_24 , ( unsigned char * ) & V_5 -> V_15 , V_12 ) ;
}
static int F_6 ( struct V_2 * V_3 , T_2 V_25 , T_2 V_12 )
{
int V_26 ;
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
F_3 ( V_17 , L_1 ) ;
V_12 += sizeof( struct V_14 ) ;
do {
V_26 = F_7 ( V_3 -> V_24 , ( unsigned char * ) & V_5 -> V_15 ,
V_12 ) ;
if ( V_26 < 0 )
break;
} while ( F_8 ( F_9 ( V_5 -> V_15 . V_16 ) ) != V_25 );
return V_26 ;
}
static int
F_10 ( struct V_2 * V_3 , int V_9 , T_1 V_10 ,
void * V_11 , T_1 V_12 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_14 * V_15 = & V_5 -> V_15 ;
void * V_27 ;
int V_26 = 0 , V_28 = 0 ;
T_2 V_25 , V_16 ;
F_3 ( V_17 , L_2 , V_10 , V_12 ) ;
V_26 = F_2 ( V_3 , V_9 , V_10 , V_11 , V_12 , false ) ;
if ( V_26 < 0 ) {
F_11 ( L_3 ,
V_26 ) ;
goto V_29;
}
V_30:
V_26 = F_6 ( V_3 , V_5 -> V_18 , V_12 ) ;
if ( V_26 < 0 )
goto V_29;
V_16 = F_9 ( V_15 -> V_16 ) ;
V_25 = ( V_16 & V_31 ) >> V_19 ;
if ( ( V_25 < V_5 -> V_18 ) && ( ++ V_28 < V_32 ) )
goto V_30;
if ( V_25 != V_5 -> V_18 ) {
F_11 ( L_4 ,
F_12 ( F_13 ( V_3 , V_9 ) ) , V_25 ,
V_5 -> V_18 ) ;
V_26 = - V_33 ;
goto V_29;
}
V_27 = ( void * ) & V_5 -> V_11 [ 0 ] ;
if ( V_11 ) {
if ( V_26 < ( int ) V_12 )
V_12 = V_26 ;
memcpy ( V_11 , V_27 , V_12 ) ;
}
if ( V_16 & V_34 )
V_26 = F_9 ( V_15 -> V_35 ) ;
V_29:
return V_26 ;
}
static int
F_14 ( struct V_2 * V_3 , int V_9 , T_1 V_10 ,
void * V_11 , T_1 V_12 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 -> V_7 ;
struct V_14 * V_15 = & V_5 -> V_15 ;
int V_26 = 0 ;
T_2 V_16 , V_25 ;
F_3 ( V_17 , L_2 , V_10 , V_12 ) ;
V_26 = F_2 ( V_3 , V_9 , V_10 , V_11 , V_12 , true ) ;
if ( V_26 < 0 )
goto V_29;
V_26 = F_6 ( V_3 , V_5 -> V_18 , V_12 ) ;
if ( V_26 < 0 )
goto V_29;
V_16 = F_9 ( V_15 -> V_16 ) ;
V_25 = ( V_16 & V_31 ) >> V_19 ;
if ( V_25 != V_5 -> V_18 ) {
F_11 ( L_4 ,
F_12 ( F_13 ( V_3 , V_9 ) ) , V_25 ,
V_5 -> V_18 ) ;
V_26 = - V_33 ;
goto V_29;
}
if ( V_16 & V_34 )
V_26 = F_9 ( V_15 -> V_35 ) ;
V_29:
return V_26 ;
}
static void
F_15 ( struct V_2 * V_3 , int V_9 , T_3 V_36 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 ;
F_3 ( V_17 , L_1 ) ;
F_16 ( V_38 , V_41 ) ;
V_40 = (struct V_39 * ) ( V_38 -> V_42 ) ;
V_40 -> V_16 = ( V_43 << V_44 ) ;
if ( V_38 -> V_45 == V_46 )
V_40 -> V_16 |= V_47 ;
V_40 -> V_48 = ( V_38 -> V_48 & V_49 ) ;
V_40 -> V_50 = 0 ;
V_40 -> V_51 = V_36 ;
F_17 ( V_40 , V_9 ) ;
F_18 ( V_38 -> V_42 ) ;
}
static int
F_19 ( struct V_2 * V_3 , bool V_52 ,
struct V_37 * V_38 , struct V_53 * * V_54 )
{
struct V_39 * V_40 ;
struct V_53 * V_55 ;
F_3 ( V_17 , L_1 ) ;
if ( V_38 -> V_12 <= V_41 ) {
F_3 ( V_56 , L_5 ,
V_38 -> V_12 , V_41 ) ;
return - V_57 ;
}
F_18 ( V_38 -> V_42 ) ;
V_40 = (struct V_39 * ) ( V_38 -> V_42 ) ;
V_55 = F_13 ( V_3 , F_20 ( V_40 ) ) ;
if ( ! V_55 ) {
F_3 ( V_56 , L_6 ) ;
return - V_57 ;
}
if ( ( ( V_40 -> V_16 & V_58 ) >> V_44 ) !=
V_43 ) {
F_11 ( L_7 ,
F_12 ( V_55 ) , V_40 -> V_16 ) ;
return - V_57 ;
}
if ( V_40 -> V_16 & V_59 ) {
F_3 ( V_17 , L_8 ,
F_12 ( V_55 ) , V_40 -> V_16 ) ;
V_38 -> V_45 = V_60 ;
}
V_38 -> V_48 = V_40 -> V_48 & V_49 ;
F_21 ( V_38 , V_41 ) ;
if ( V_52 )
F_22 ( V_55 , V_40 -> V_51 << 2 , V_38 ) ;
else
F_21 ( V_38 , V_40 -> V_51 << 2 ) ;
if ( V_38 -> V_12 == 0 )
return - V_61 ;
if ( V_54 != NULL )
* V_54 = V_55 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_9 ,
struct V_37 * V_62 )
{
struct V_53 * V_54 = F_13 ( V_3 , V_9 ) ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
if ( ! F_24 ( V_5 -> V_8 ) )
return F_25 ( V_3 , V_9 , 0 , V_62 ) ;
return F_26 ( V_54 , V_62 ) ;
}
static int
F_27 ( struct V_2 * V_3 , int V_9 , T_3 V_36 ,
struct V_37 * V_38 )
{
F_15 ( V_3 , V_9 , V_36 , V_38 ) ;
return F_28 ( V_3 -> V_24 , V_38 ) ;
}
void F_29 ( struct V_63 * V_64 , bool V_65 )
{
struct V_66 * V_24 = F_30 ( V_64 ) ;
struct V_2 * V_3 = V_24 -> V_3 ;
F_3 ( V_67 , L_1 ) ;
F_31 ( V_3 , V_65 ) ;
}
void
F_32 ( struct V_63 * V_64 , struct V_37 * V_68 ,
bool V_69 )
{
struct V_66 * V_24 = F_30 ( V_64 ) ;
struct V_4 * V_5 = V_24 -> V_3 -> V_6 -> V_7 ;
struct V_53 * V_54 ;
if ( F_33 ( V_5 -> V_8 ) ) {
if ( ! V_69 )
F_34 ( V_5 -> V_8 , V_68 ) ;
} else {
if ( F_19 ( V_24 -> V_3 , false , V_68 , & V_54 ) )
F_35 ( V_68 ) ;
else
F_36 ( V_54 , V_68 , V_69 ) ;
}
}
static void
F_37 ( struct V_2 * V_3 , int V_9 ,
enum V_70 V_71 )
{
}
static void
F_38 ( struct V_2 * V_3 , int V_9 ,
T_3 V_72 [ V_73 ] )
{
}
static void
F_39 ( struct V_2 * V_3 , int V_9 ,
T_3 V_72 [ V_73 ] )
{
}
static void F_40 ( struct V_53 * V_54 ,
struct V_37 * V_62 )
{
F_41 ( V_54 , V_62 ) ;
}
static void
F_42 ( struct V_53 * V_54 )
{
F_43 ( V_54 ) ;
}
static void
F_44 ( struct V_53 * V_54 )
{
F_45 ( V_54 ) ;
}
static void
F_46 ( struct V_53 * V_54 )
{
F_47 ( V_54 ) ;
}
static int
F_48 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 * V_8 ;
V_8 = F_49 ( V_3 ) ;
if ( F_50 ( V_8 ) )
return F_51 ( V_8 ) ;
V_5 -> V_8 = V_8 ;
return 0 ;
}
int F_52 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_53 ( sizeof( * V_5 ) , V_74 ) ;
if ( ! V_5 )
goto V_75;
if ( ( unsigned long ) ( & V_5 -> V_15 + 1 ) != ( unsigned long ) V_5 -> V_11 ) {
F_11 ( L_9 ) ;
goto V_75;
}
V_3 -> V_6 -> V_76 = F_19 ;
V_3 -> V_6 -> V_77 = F_10 ;
V_3 -> V_6 -> V_78 = F_14 ;
V_3 -> V_6 -> V_79 = F_23 ;
V_3 -> V_6 -> V_80 = F_27 ;
V_3 -> V_6 -> V_81 = F_37 ;
V_3 -> V_6 -> V_82 = F_38 ;
V_3 -> V_6 -> V_83 = F_39 ;
V_3 -> V_6 -> V_84 = F_40 ;
V_3 -> V_6 -> V_85 = F_42 ;
V_3 -> V_6 -> V_86 = F_44 ;
V_3 -> V_6 -> V_87 = F_46 ;
V_3 -> V_6 -> V_88 = F_48 ;
V_3 -> V_6 -> V_7 = V_5 ;
V_3 -> V_89 += V_41 + V_90 ;
V_3 -> V_24 -> V_91 = V_92 +
sizeof( struct V_14 ) ;
return 0 ;
V_75:
F_54 ( V_5 ) ;
return - V_93 ;
}
void F_55 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
V_3 -> V_6 -> V_7 = NULL ;
F_56 ( V_5 -> V_8 ) ;
F_54 ( V_5 ) ;
}
