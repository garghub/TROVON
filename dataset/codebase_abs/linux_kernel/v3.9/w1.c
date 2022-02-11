static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return - V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_2 , L_1 , V_8 , V_7 -> V_9 ) ;
memset ( V_7 , 0 , sizeof( struct V_6 ) + sizeof( struct V_10 ) ) ;
F_6 ( V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
F_5 ( V_2 , L_1 , V_8 , V_12 -> V_9 ) ;
while ( F_9 ( & V_12 -> V_13 ) ) {
F_5 ( V_2 , L_2 ,
V_12 -> V_9 , F_9 ( & V_12 -> V_13 ) ) ;
if ( F_10 ( 1000 ) )
F_11 ( V_14 ) ;
}
F_12 ( V_12 -> V_15 ) ;
V_12 -> V_16 -> V_17 -- ;
F_13 ( & V_12 -> V_18 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
return sprintf ( V_21 , L_3 , V_12 -> V_9 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
T_1 V_22 = sizeof( V_12 -> V_23 ) ;
memcpy ( V_21 , ( V_24 * ) & V_12 -> V_23 , V_22 ) ;
return V_22 ;
}
static T_1 F_16 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_21 , T_2 V_31 , T_3 V_22 )
{
struct V_11 * V_12 = F_17 ( V_28 ) ;
F_18 ( & V_12 -> V_16 -> V_32 ) ;
if ( F_19 ( V_12 ) ) {
V_22 = 0 ;
goto V_33;
}
F_20 ( V_12 -> V_16 , V_21 , V_22 ) ;
V_33:
F_21 ( & V_12 -> V_16 -> V_32 ) ;
return V_22 ;
}
static T_1 F_22 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_21 , T_2 V_31 , T_3 V_22 )
{
struct V_11 * V_12 = F_17 ( V_28 ) ;
F_18 ( & V_12 -> V_16 -> V_32 ) ;
F_23 ( V_12 -> V_16 , V_21 , V_22 ) ;
F_21 ( & V_12 -> V_16 -> V_32 ) ;
return V_22 ;
}
static int F_24 ( struct V_11 * V_12 )
{
return F_25 ( & V_12 -> V_2 . V_28 , & V_34 ) ;
}
static void F_26 ( struct V_11 * V_12 )
{
F_27 ( & V_12 -> V_2 . V_28 , & V_34 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_3 , V_7 -> V_9 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
long V_35 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_30 ( V_21 , 0 , & V_35 ) == - V_36 )
return - V_36 ;
F_18 ( & V_7 -> V_32 ) ;
V_7 -> V_37 = V_35 ;
F_21 ( & V_7 -> V_32 ) ;
F_31 ( V_7 -> V_38 ) ;
return V_22 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_37 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
long V_35 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_30 ( V_21 , 0 , & V_35 ) == - V_36 )
return - V_36 ;
F_18 ( & V_7 -> V_32 ) ;
V_7 -> V_39 = V_35 ;
F_21 ( & V_7 -> V_32 ) ;
F_31 ( V_7 -> V_38 ) ;
return V_22 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_39 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_5 , V_7 -> V_40 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_36 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
T_1 V_22 ;
V_22 = sprintf ( V_21 , L_4 , V_41 ) ;
return V_22 ;
}
static T_1 F_37 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_42 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_38 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_6 , V_7 -> V_43 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_39 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_17 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_44 = V_45 ;
F_18 ( & V_7 -> V_32 ) ;
if ( V_7 -> V_17 == 0 )
V_44 -= snprintf ( V_21 + V_45 - V_44 , V_44 , L_7 ) ;
else {
struct V_46 * V_47 , * V_48 ;
struct V_11 * V_12 ;
F_41 (ent, n, &md->slist) {
V_12 = F_42 ( V_47 , struct V_11 , V_49 ) ;
V_44 -= snprintf ( V_21 + V_45 - V_44 , V_44 , L_3 , V_12 -> V_9 ) ;
}
}
F_21 ( & V_7 -> V_32 ) ;
return V_45 - V_44 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
int V_44 = V_45 ;
V_44 -= snprintf ( V_21 + V_45 - V_44 , V_44 ,
L_8 ) ;
return V_45 - V_44 ;
}
static int F_44 ( struct V_1 * V_2 , const char * V_21 , T_3 V_22 ,
struct V_50 * V_51 )
{
unsigned int V_15 ;
unsigned long long V_52 ;
int V_53 ;
T_4 V_54 ;
const char * V_55 = L_9
L_10 ;
if ( V_21 [ 2 ] != '-' ) {
F_45 ( V_2 , L_11 , V_55 ) ;
return - V_36 ;
}
V_53 = sscanf ( V_21 , L_12 , & V_15 , & V_52 ) ;
if ( V_53 != 2 ) {
F_45 ( V_2 , L_11 , V_55 ) ;
return - V_36 ;
}
V_51 -> V_15 = V_15 ;
V_51 -> V_52 = V_52 ;
V_54 = F_46 ( * ( T_4 * ) V_51 ) ;
V_51 -> V_56 = F_47 ( ( V_24 * ) & V_54 , 7 ) ;
#if 0
dev_info(dev, "With CRC device is %02x.%012llx.%02x.\n",
rn->family, (unsigned long long)rn->id, rn->crc);
#endif
return 0 ;
}
static struct V_11 * F_48 ( struct V_6 * V_2 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 ;
F_49 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_23 . V_15 == V_51 -> V_15 &&
V_12 -> V_23 . V_52 == V_51 -> V_52 &&
V_12 -> V_23 . V_56 == V_51 -> V_56 ) {
return V_12 ;
}
}
return NULL ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_50 V_51 ;
struct V_11 * V_12 ;
T_1 V_57 = V_22 ;
if ( F_44 ( V_2 , V_21 , V_22 , & V_51 ) )
return - V_36 ;
F_18 ( & V_7 -> V_32 ) ;
V_12 = F_48 ( V_7 , & V_51 ) ;
if ( V_12 ) {
F_51 ( V_2 , L_13 , V_12 -> V_9 ) ;
V_57 = - V_36 ;
} else {
F_52 ( V_7 , & V_51 ) ;
}
F_21 ( & V_7 -> V_32 ) ;
return V_57 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
int V_44 = V_45 ;
V_44 -= snprintf ( V_21 + V_45 - V_44 , V_44 ,
L_14 ) ;
return V_45 - V_44 ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_50 V_51 ;
struct V_11 * V_12 ;
T_1 V_57 = V_22 ;
if ( F_44 ( V_2 , V_21 , V_22 , & V_51 ) )
return - V_36 ;
F_18 ( & V_7 -> V_32 ) ;
V_12 = F_48 ( V_7 , & V_51 ) ;
if ( V_12 ) {
F_55 ( V_12 ) ;
} else {
F_51 ( V_2 , L_15 , V_51 . V_15 ,
( unsigned long long ) V_51 . V_52 ) ;
V_57 = - V_36 ;
}
F_21 ( & V_7 -> V_32 ) ;
return V_57 ;
}
int F_56 ( struct V_6 * V_16 )
{
return F_57 ( & V_16 -> V_2 . V_28 , & V_58 ) ;
}
void F_58 ( struct V_6 * V_16 )
{
F_59 ( & V_16 -> V_2 . V_28 , & V_58 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_6 * V_7 = NULL ;
struct V_11 * V_12 = NULL ;
char * V_61 , * V_9 ;
int V_62 = 0 ;
if ( V_2 -> V_63 == & V_64 ) {
V_7 = F_61 ( V_2 , struct V_6 , V_2 ) ;
V_61 = L_16 ;
V_9 = V_7 -> V_9 ;
} else if ( V_2 -> V_63 == & V_65 ) {
V_12 = F_61 ( V_2 , struct V_11 , V_2 ) ;
V_61 = L_17 ;
V_9 = V_12 -> V_9 ;
} else {
F_5 ( V_2 , L_18 ) ;
return - V_36 ;
}
F_5 ( V_2 , L_19 ,
V_61 , V_9 , F_62 ( V_2 ) ) ;
if ( V_2 -> V_63 != & V_65 || ! V_12 )
goto V_66;
V_62 = F_63 ( V_60 , L_20 , V_12 -> V_23 . V_15 ) ;
if ( V_62 )
goto V_66;
V_62 = F_63 ( V_60 , L_21 ,
( unsigned long long ) V_12 -> V_23 . V_52 ) ;
V_66:
return V_62 ;
}
static int F_64 ( struct V_11 * V_12 )
{
int V_62 ;
V_12 -> V_2 . V_67 = & V_12 -> V_16 -> V_2 ;
V_12 -> V_2 . V_63 = & V_65 ;
V_12 -> V_2 . V_68 = & V_69 ;
V_12 -> V_2 . V_70 = & F_7 ;
F_65 ( & V_12 -> V_2 , L_12 ,
( unsigned int ) V_12 -> V_23 . V_15 ,
( unsigned long long ) V_12 -> V_23 . V_52 ) ;
snprintf ( & V_12 -> V_9 [ 0 ] , sizeof( V_12 -> V_9 ) ,
L_12 ,
( unsigned int ) V_12 -> V_23 . V_15 ,
( unsigned long long ) V_12 -> V_23 . V_52 ) ;
F_5 ( & V_12 -> V_2 , L_22 , V_8 ,
F_62 ( & V_12 -> V_2 ) , V_12 ) ;
V_62 = F_66 ( & V_12 -> V_2 ) ;
if ( V_62 < 0 ) {
F_45 ( & V_12 -> V_2 ,
L_23 ,
F_62 ( & V_12 -> V_2 ) , V_62 ) ;
return V_62 ;
}
V_62 = F_67 ( & V_12 -> V_2 , & V_71 ) ;
if ( V_62 < 0 ) {
F_45 ( & V_12 -> V_2 ,
L_24 ,
F_62 ( & V_12 -> V_2 ) , V_62 ) ;
goto V_72;
}
V_62 = F_67 ( & V_12 -> V_2 , & V_73 ) ;
if ( V_62 < 0 ) {
F_45 ( & V_12 -> V_2 ,
L_24 ,
F_62 ( & V_12 -> V_2 ) , V_62 ) ;
goto V_74;
}
if ( V_12 -> V_15 -> V_75 && V_12 -> V_15 -> V_75 -> V_76 &&
( ( V_62 = V_12 -> V_15 -> V_75 -> V_76 ( V_12 ) ) < 0 ) ) {
F_45 ( & V_12 -> V_2 ,
L_24 ,
F_62 ( & V_12 -> V_2 ) , V_62 ) ;
goto V_77;
}
F_68 ( & V_12 -> V_49 , & V_12 -> V_16 -> V_78 ) ;
return 0 ;
V_77:
F_69 ( & V_12 -> V_2 , & V_73 ) ;
V_74:
F_69 ( & V_12 -> V_2 , & V_71 ) ;
V_72:
F_70 ( & V_12 -> V_2 ) ;
return V_62 ;
}
static int F_52 ( struct V_6 * V_2 , struct V_50 * V_51 )
{
struct V_11 * V_12 ;
struct V_79 * V_80 ;
int V_62 ;
struct V_81 V_82 ;
V_12 = F_71 ( sizeof( struct V_11 ) , V_83 ) ;
if ( ! V_12 ) {
F_45 ( & V_2 -> V_2 ,
L_25 ,
V_8 ) ;
return - V_84 ;
}
V_12 -> V_85 = V_86 ;
V_12 -> V_16 = V_2 ;
F_72 ( V_87 , ( long * ) & V_12 -> V_88 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
memcpy ( & V_12 -> V_23 , V_51 , sizeof( V_12 -> V_23 ) ) ;
F_73 ( & V_12 -> V_13 , 0 ) ;
F_74 ( & V_12 -> V_18 ) ;
F_75 ( & V_89 ) ;
V_80 = F_76 ( V_51 -> V_15 ) ;
if ( ! V_80 ) {
V_80 = & V_90 ;
F_51 ( & V_2 -> V_2 , L_26 ,
V_51 -> V_15 , V_51 -> V_15 ,
( unsigned long long ) V_51 -> V_52 , V_51 -> V_56 ) ;
}
F_77 ( V_80 ) ;
F_78 ( & V_89 ) ;
V_12 -> V_15 = V_80 ;
V_62 = F_64 ( V_12 ) ;
if ( V_62 < 0 ) {
F_45 ( & V_2 -> V_2 , L_27 , V_8 ,
V_12 -> V_9 ) ;
F_12 ( V_12 -> V_15 ) ;
F_6 ( V_12 ) ;
return V_62 ;
}
V_12 -> V_91 = V_2 -> V_92 ;
V_2 -> V_17 ++ ;
memcpy ( V_82 . V_52 . V_52 , V_51 , sizeof( V_82 . V_52 ) ) ;
V_82 . type = V_93 ;
F_79 ( V_2 , & V_82 ) ;
return 0 ;
}
void F_55 ( struct V_11 * V_12 )
{
struct V_81 V_82 ;
F_5 ( & V_12 -> V_2 , L_28 , V_8 , V_12 -> V_9 , V_12 ) ;
F_80 ( & V_12 -> V_49 ) ;
if ( V_12 -> V_15 -> V_75 && V_12 -> V_15 -> V_75 -> V_94 )
V_12 -> V_15 -> V_75 -> V_94 ( V_12 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
memcpy ( V_82 . V_52 . V_52 , & V_12 -> V_23 , sizeof( V_82 . V_52 ) ) ;
V_82 . type = V_95 ;
F_79 ( V_12 -> V_16 , & V_82 ) ;
F_69 ( & V_12 -> V_2 , & V_73 ) ;
F_69 ( & V_12 -> V_2 , & V_71 ) ;
F_70 ( & V_12 -> V_2 ) ;
F_81 ( & V_12 -> V_18 ) ;
F_6 ( V_12 ) ;
}
struct V_6 * F_82 ( T_5 V_52 )
{
struct V_6 * V_2 ;
int V_96 = 0 ;
F_18 ( & V_97 ) ;
F_49 (dev, &w1_masters, w1_master_entry) {
if ( V_2 -> V_52 == V_52 ) {
V_96 = 1 ;
F_83 ( & V_2 -> V_13 ) ;
break;
}
}
F_21 ( & V_97 ) ;
return ( V_96 ) ? V_2 : NULL ;
}
struct V_11 * F_84 ( struct V_50 * V_52 )
{
struct V_6 * V_2 ;
struct V_11 * V_12 = NULL ;
int V_96 = 0 ;
F_18 ( & V_97 ) ;
F_49 (dev, &w1_masters, w1_master_entry) {
F_18 ( & V_2 -> V_32 ) ;
F_49 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_23 . V_15 == V_52 -> V_15 &&
V_12 -> V_23 . V_52 == V_52 -> V_52 &&
V_12 -> V_23 . V_56 == V_52 -> V_56 ) {
V_96 = 1 ;
F_83 ( & V_2 -> V_13 ) ;
F_83 ( & V_12 -> V_13 ) ;
break;
}
}
F_21 ( & V_2 -> V_32 ) ;
if ( V_96 )
break;
}
F_21 ( & V_97 ) ;
return ( V_96 ) ? V_12 : NULL ;
}
void F_85 ( struct V_79 * V_80 , int V_98 )
{
struct V_11 * V_12 , * V_99 ;
struct V_6 * V_2 ;
F_18 ( & V_97 ) ;
F_49 (dev, &w1_masters, w1_master_entry) {
F_5 ( & V_2 -> V_2 , L_29
L_30 , V_2 -> V_9 , V_80 -> V_100 ) ;
F_18 ( & V_2 -> V_32 ) ;
F_86 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ( V_98 && V_12 -> V_15 -> V_100 == V_101
&& V_12 -> V_23 . V_15 == V_80 -> V_100 ) ||
( ! V_98 && V_12 -> V_15 -> V_100 == V_80 -> V_100 ) ) {
struct V_50 V_51 ;
memcpy ( & V_51 , & V_12 -> V_23 , sizeof( V_51 ) ) ;
F_55 ( V_12 ) ;
F_52 ( V_2 , & V_51 ) ;
}
}
F_5 ( & V_2 -> V_2 , L_29
L_31 , V_2 -> V_9 ) ;
F_21 ( & V_2 -> V_32 ) ;
}
F_21 ( & V_97 ) ;
}
void F_87 ( struct V_6 * V_2 , T_4 V_51 )
{
struct V_11 * V_12 ;
struct V_50 * V_35 ;
T_4 V_102 = F_46 ( V_51 ) ;
F_83 ( & V_2 -> V_13 ) ;
V_35 = (struct V_50 * ) & V_51 ;
V_12 = F_48 ( V_2 , V_35 ) ;
if ( V_12 ) {
F_72 ( V_87 , ( long * ) & V_12 -> V_88 ) ;
} else {
if ( V_51 && V_35 -> V_56 == F_47 ( ( V_24 * ) & V_102 , 7 ) )
F_52 ( V_2 , V_35 ) ;
}
F_88 ( & V_2 -> V_13 ) ;
}
void F_89 ( struct V_6 * V_2 , V_24 V_103 , T_6 V_104 )
{
T_4 V_105 , V_51 , V_106 ;
int V_53 , V_17 = 0 ;
int V_107 , V_108 ;
int V_109 , V_110 ;
V_24 V_111 = 0 ;
V_109 = 0 ;
V_51 = V_105 = 0 ;
V_108 = 0 ;
V_107 = - 1 ;
V_110 = 64 ;
while ( ! V_108 && ( V_17 ++ < V_2 -> V_42 ) ) {
V_105 = V_51 ;
V_51 = 0 ;
F_18 ( & V_2 -> V_112 ) ;
if ( F_90 ( V_2 ) ) {
F_21 ( & V_2 -> V_112 ) ;
F_5 ( & V_2 -> V_2 , L_32 ) ;
break;
}
if ( V_2 -> V_42 == 1 ) {
int V_113 ;
F_91 ( V_2 , V_114 ) ;
V_113 = F_23 ( V_2 , ( V_24 * ) & V_51 , 8 ) ;
F_21 ( & V_2 -> V_112 ) ;
if ( V_113 == 8 && V_51 )
V_104 ( V_2 , V_51 ) ;
break;
}
F_91 ( V_2 , V_103 ) ;
for ( V_53 = 0 ; V_53 < 64 ; ++ V_53 ) {
if ( V_53 == V_110 )
V_109 = 1 ;
else if ( V_53 > V_110 )
V_109 = 0 ;
else
V_109 = ( ( V_105 >> V_53 ) & 0x1 ) ;
V_111 = F_92 ( V_2 , V_109 ) ;
if ( ( V_111 & 0x03 ) == 0x03 )
break;
if ( V_111 == 0 )
V_107 = V_53 ;
V_106 = ( V_111 >> 2 ) ;
V_51 |= ( V_106 << V_53 ) ;
if ( ! V_2 -> V_115 && F_93 () ) {
F_21 ( & V_2 -> V_112 ) ;
F_5 ( & V_2 -> V_2 , L_33 ) ;
return;
}
}
F_21 ( & V_2 -> V_112 ) ;
if ( ( V_111 & 0x03 ) != 0x03 ) {
if ( ( V_110 == V_107 ) || ( V_107 < 0 ) )
V_108 = 1 ;
V_110 = V_107 ;
V_104 ( V_2 , V_51 ) ;
}
}
}
void F_94 ( struct V_6 * V_2 , V_24 V_103 ,
T_6 V_104 )
{
struct V_11 * V_12 , * V_99 ;
F_49 (sl, &dev->slist, w1_slave_entry)
F_95 ( V_87 , ( long * ) & V_12 -> V_88 ) ;
F_96 ( V_2 , V_103 , V_104 ) ;
F_86 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ! F_97 ( V_87 , ( unsigned long * ) & V_12 -> V_88 ) && ! -- V_12 -> V_91 )
F_55 ( V_12 ) ;
else if ( F_97 ( V_87 , ( unsigned long * ) & V_12 -> V_88 ) )
V_12 -> V_91 = V_2 -> V_92 ;
}
if ( V_2 -> V_37 > 0 )
V_2 -> V_37 -- ;
}
static void F_98 ( struct V_6 * V_2 , V_24 V_103 )
{
F_94 ( V_2 , V_103 , F_87 ) ;
}
int F_99 ( void * V_116 )
{
struct V_6 * V_2 = (struct V_6 * ) V_116 ;
const unsigned long V_117 = F_100 ( V_41 * 1000 ) ;
while ( ! F_93 () ) {
if ( V_2 -> V_37 ) {
F_18 ( & V_2 -> V_32 ) ;
F_98 ( V_2 , V_118 ) ;
F_21 ( & V_2 -> V_32 ) ;
}
F_101 () ;
F_102 ( V_119 ) ;
if ( F_93 () )
break;
if ( V_2 -> V_37 )
F_103 ( V_117 ) ;
else
F_104 () ;
}
F_88 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int T_7 F_105 ( void )
{
int V_120 ;
F_106 ( V_121 L_34 ) ;
F_107 () ;
V_120 = F_108 ( & V_69 ) ;
if ( V_120 ) {
F_106 ( V_122 L_35 , V_120 ) ;
goto V_123;
}
V_120 = F_109 ( & V_64 ) ;
if ( V_120 ) {
F_106 ( V_122
L_36 ,
V_120 ) ;
goto V_124;
}
V_120 = F_109 ( & V_65 ) ;
if ( V_120 ) {
F_106 ( V_122
L_37 ,
V_120 ) ;
goto V_125;
}
return 0 ;
#if 0
err_out_slave_unregister:
driver_unregister(&w1_slave_driver);
#endif
V_125:
F_110 ( & V_64 ) ;
V_124:
F_111 ( & V_69 ) ;
V_123:
return V_120 ;
}
static void T_8 F_112 ( void )
{
struct V_6 * V_2 ;
F_49 (dev, &w1_masters, w1_master_entry)
F_113 ( V_2 ) ;
F_114 () ;
F_110 ( & V_65 ) ;
F_110 ( & V_64 ) ;
F_111 ( & V_69 ) ;
}
