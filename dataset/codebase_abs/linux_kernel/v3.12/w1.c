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
struct V_29 * V_30 , char * V_21 , T_2 V_31 ,
T_3 V_22 )
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
struct V_29 * V_30 , char * V_21 , T_2 V_31 ,
T_3 V_22 )
{
struct V_11 * V_12 = F_17 ( V_28 ) ;
F_18 ( & V_12 -> V_16 -> V_32 ) ;
F_23 ( V_12 -> V_16 , V_21 , V_22 ) ;
F_21 ( & V_12 -> V_16 -> V_32 ) ;
return V_22 ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_3 , V_7 -> V_9 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
long V_34 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_35 ;
V_35 = F_26 ( V_21 , 0 , & V_34 ) ;
if ( V_35 )
return V_35 ;
F_18 ( & V_7 -> V_32 ) ;
V_7 -> V_36 = V_34 ;
F_21 ( & V_7 -> V_32 ) ;
F_27 ( V_7 -> V_37 ) ;
return V_22 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_36 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
long V_34 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_35 ;
V_35 = F_26 ( V_21 , 0 , & V_34 ) ;
if ( V_35 )
return V_35 ;
F_18 ( & V_7 -> V_32 ) ;
V_7 -> V_38 = V_34 ;
F_21 ( & V_7 -> V_32 ) ;
F_27 ( V_7 -> V_37 ) ;
return V_22 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_38 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_31 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_5 , V_7 -> V_39 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
T_1 V_22 ;
V_22 = sprintf ( V_21 , L_4 , V_40 ) ;
return V_22 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_41 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_34 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_6 , V_7 -> V_42 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_22 ;
F_18 ( & V_7 -> V_32 ) ;
V_22 = sprintf ( V_21 , L_4 , V_7 -> V_17 ) ;
F_21 ( & V_7 -> V_32 ) ;
return V_22 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_43 = V_44 ;
F_18 ( & V_7 -> V_32 ) ;
if ( V_7 -> V_17 == 0 )
V_43 -= snprintf ( V_21 + V_44 - V_43 , V_43 , L_7 ) ;
else {
struct V_45 * V_46 , * V_47 ;
struct V_11 * V_12 ;
F_37 (ent, n, &md->slist) {
V_12 = F_38 ( V_46 , struct V_11 , V_48 ) ;
V_43 -= snprintf ( V_21 + V_44 - V_43 , V_43 , L_3 , V_12 -> V_9 ) ;
}
}
F_21 ( & V_7 -> V_32 ) ;
return V_44 - V_43 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
int V_43 = V_44 ;
V_43 -= snprintf ( V_21 + V_44 - V_43 , V_43 ,
L_8 ) ;
return V_44 - V_43 ;
}
static int F_40 ( struct V_1 * V_2 , const char * V_21 , T_3 V_22 ,
struct V_49 * V_50 )
{
unsigned int V_15 ;
unsigned long long V_51 ;
int V_52 ;
T_4 V_53 ;
const char * V_54 = L_9
L_10 ;
if ( V_21 [ 2 ] != '-' ) {
F_41 ( V_2 , L_11 , V_54 ) ;
return - V_55 ;
}
V_52 = sscanf ( V_21 , L_12 , & V_15 , & V_51 ) ;
if ( V_52 != 2 ) {
F_41 ( V_2 , L_11 , V_54 ) ;
return - V_55 ;
}
V_50 -> V_15 = V_15 ;
V_50 -> V_51 = V_51 ;
V_53 = F_42 ( * ( T_4 * ) V_50 ) ;
V_50 -> V_56 = F_43 ( ( V_24 * ) & V_53 , 7 ) ;
#if 0
dev_info(dev, "With CRC device is %02x.%012llx.%02x.\n",
rn->family, (unsigned long long)rn->id, rn->crc);
#endif
return 0 ;
}
static struct V_11 * F_44 ( struct V_6 * V_2 ,
struct V_49 * V_50 )
{
struct V_11 * V_12 ;
F_45 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_23 . V_15 == V_50 -> V_15 &&
V_12 -> V_23 . V_51 == V_50 -> V_51 &&
V_12 -> V_23 . V_56 == V_50 -> V_56 ) {
return V_12 ;
}
}
return NULL ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_49 V_50 ;
struct V_11 * V_12 ;
T_1 V_57 = V_22 ;
if ( F_40 ( V_2 , V_21 , V_22 , & V_50 ) )
return - V_55 ;
F_18 ( & V_7 -> V_32 ) ;
V_12 = F_44 ( V_7 , & V_50 ) ;
if ( V_12 ) {
F_47 ( V_2 , L_13 , V_12 -> V_9 ) ;
V_57 = - V_55 ;
} else {
F_48 ( V_7 , & V_50 ) ;
}
F_21 ( & V_7 -> V_32 ) ;
return V_57 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
int V_43 = V_44 ;
V_43 -= snprintf ( V_21 + V_44 - V_43 , V_43 ,
L_14 ) ;
return V_44 - V_43 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_3 V_22 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_49 V_50 ;
struct V_11 * V_12 ;
T_1 V_57 = V_22 ;
if ( F_40 ( V_2 , V_21 , V_22 , & V_50 ) )
return - V_55 ;
F_18 ( & V_7 -> V_32 ) ;
V_12 = F_44 ( V_7 , & V_50 ) ;
if ( V_12 ) {
F_51 ( V_12 ) ;
} else {
F_47 ( V_2 , L_15 , V_50 . V_15 ,
( unsigned long long ) V_50 . V_51 ) ;
V_57 = - V_55 ;
}
F_21 ( & V_7 -> V_32 ) ;
return V_57 ;
}
int F_52 ( struct V_6 * V_16 )
{
return F_53 ( & V_16 -> V_2 . V_28 , & V_58 ) ;
}
void F_54 ( struct V_6 * V_16 )
{
F_55 ( & V_16 -> V_2 . V_28 , & V_58 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_6 * V_7 = NULL ;
struct V_11 * V_12 = NULL ;
char * V_61 , * V_9 ;
int V_62 = 0 ;
if ( V_2 -> V_63 == & V_64 ) {
V_7 = F_57 ( V_2 , struct V_6 , V_2 ) ;
V_61 = L_16 ;
V_9 = V_7 -> V_9 ;
} else if ( V_2 -> V_63 == & V_65 ) {
V_12 = F_57 ( V_2 , struct V_11 , V_2 ) ;
V_61 = L_17 ;
V_9 = V_12 -> V_9 ;
} else {
F_5 ( V_2 , L_18 ) ;
return - V_55 ;
}
F_5 ( V_2 , L_19 ,
V_61 , V_9 , F_58 ( V_2 ) ) ;
if ( V_2 -> V_63 != & V_65 || ! V_12 )
goto V_66;
V_62 = F_59 ( V_60 , L_20 , V_12 -> V_23 . V_15 ) ;
if ( V_62 )
goto V_66;
V_62 = F_59 ( V_60 , L_21 ,
( unsigned long long ) V_12 -> V_23 . V_51 ) ;
V_66:
return V_62 ;
}
static int F_60 ( struct V_67 * V_68 , unsigned long V_69 ,
void * V_70 )
{
struct V_1 * V_2 = V_70 ;
struct V_11 * V_12 ;
struct V_71 * V_72 ;
int V_62 ;
if ( V_2 -> V_73 != F_7 )
return 0 ;
V_12 = F_8 ( V_2 ) ;
V_72 = V_12 -> V_15 -> V_72 ;
if ( ! V_72 )
return 0 ;
switch ( V_69 ) {
case V_74 :
if ( V_72 -> V_75 ) {
V_62 = V_72 -> V_75 ( V_12 ) ;
if ( V_62 < 0 ) {
F_41 ( & V_12 -> V_2 ,
L_22 ,
V_62 ) ;
return V_62 ;
}
}
if ( V_72 -> V_76 ) {
V_62 = F_61 ( & V_12 -> V_2 . V_28 , V_72 -> V_76 ) ;
if ( V_62 ) {
F_41 ( & V_12 -> V_2 ,
L_23 ,
V_62 ) ;
return V_62 ;
}
}
break;
case V_77 :
if ( V_72 -> V_78 )
V_12 -> V_15 -> V_72 -> V_78 ( V_12 ) ;
if ( V_72 -> V_76 )
F_62 ( & V_12 -> V_2 . V_28 , V_72 -> V_76 ) ;
break;
}
return 0 ;
}
static int F_63 ( struct V_11 * V_12 )
{
int V_62 ;
V_12 -> V_2 . V_79 = & V_12 -> V_16 -> V_2 ;
V_12 -> V_2 . V_63 = & V_65 ;
V_12 -> V_2 . V_80 = & V_81 ;
V_12 -> V_2 . V_73 = & F_7 ;
V_12 -> V_2 . V_76 = V_82 ;
F_64 ( & V_12 -> V_2 , L_12 ,
( unsigned int ) V_12 -> V_23 . V_15 ,
( unsigned long long ) V_12 -> V_23 . V_51 ) ;
snprintf ( & V_12 -> V_9 [ 0 ] , sizeof( V_12 -> V_9 ) ,
L_12 ,
( unsigned int ) V_12 -> V_23 . V_15 ,
( unsigned long long ) V_12 -> V_23 . V_51 ) ;
F_5 ( & V_12 -> V_2 , L_24 , V_8 ,
F_58 ( & V_12 -> V_2 ) , V_12 ) ;
V_62 = F_65 ( & V_12 -> V_2 ) ;
if ( V_62 < 0 ) {
F_41 ( & V_12 -> V_2 ,
L_25 ,
F_58 ( & V_12 -> V_2 ) , V_62 ) ;
return V_62 ;
}
F_66 ( & V_12 -> V_2 , false ) ;
F_67 ( & V_12 -> V_2 . V_28 , V_83 ) ;
F_68 ( & V_12 -> V_48 , & V_12 -> V_16 -> V_84 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_2 , struct V_49 * V_50 )
{
struct V_11 * V_12 ;
struct V_85 * V_86 ;
int V_62 ;
struct V_87 V_88 ;
V_12 = F_69 ( sizeof( struct V_11 ) , V_89 ) ;
if ( ! V_12 ) {
F_41 ( & V_2 -> V_2 ,
L_26 ,
V_8 ) ;
return - V_90 ;
}
V_12 -> V_91 = V_92 ;
V_12 -> V_16 = V_2 ;
F_70 ( V_93 , ( long * ) & V_12 -> V_94 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
memcpy ( & V_12 -> V_23 , V_50 , sizeof( V_12 -> V_23 ) ) ;
F_71 ( & V_12 -> V_13 , 0 ) ;
F_72 ( & V_12 -> V_18 ) ;
F_21 ( & V_2 -> V_32 ) ;
F_73 ( L_27 , V_50 -> V_15 ) ;
F_18 ( & V_2 -> V_32 ) ;
F_74 ( & V_95 ) ;
V_86 = F_75 ( V_50 -> V_15 ) ;
if ( ! V_86 ) {
V_86 = & V_96 ;
F_47 ( & V_2 -> V_2 , L_28 ,
V_50 -> V_15 , V_50 -> V_15 ,
( unsigned long long ) V_50 -> V_51 , V_50 -> V_56 ) ;
}
F_76 ( V_86 ) ;
F_77 ( & V_95 ) ;
V_12 -> V_15 = V_86 ;
V_62 = F_63 ( V_12 ) ;
if ( V_62 < 0 ) {
F_41 ( & V_2 -> V_2 , L_29 , V_8 ,
V_12 -> V_9 ) ;
F_12 ( V_12 -> V_15 ) ;
F_6 ( V_12 ) ;
return V_62 ;
}
V_12 -> V_97 = V_2 -> V_98 ;
V_2 -> V_17 ++ ;
memcpy ( V_88 . V_51 . V_51 , V_50 , sizeof( V_88 . V_51 ) ) ;
V_88 . type = V_99 ;
F_78 ( V_2 , & V_88 ) ;
return 0 ;
}
void F_51 ( struct V_11 * V_12 )
{
struct V_87 V_88 ;
F_5 ( & V_12 -> V_2 , L_30 , V_8 , V_12 -> V_9 , V_12 ) ;
F_79 ( & V_12 -> V_48 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
memcpy ( V_88 . V_51 . V_51 , & V_12 -> V_23 , sizeof( V_88 . V_51 ) ) ;
V_88 . type = V_100 ;
F_78 ( V_12 -> V_16 , & V_88 ) ;
F_80 ( & V_12 -> V_2 ) ;
F_81 ( & V_12 -> V_18 ) ;
F_6 ( V_12 ) ;
}
struct V_6 * F_82 ( T_5 V_51 )
{
struct V_6 * V_2 ;
int V_101 = 0 ;
F_18 ( & V_102 ) ;
F_45 (dev, &w1_masters, w1_master_entry) {
if ( V_2 -> V_51 == V_51 ) {
V_101 = 1 ;
F_83 ( & V_2 -> V_13 ) ;
break;
}
}
F_21 ( & V_102 ) ;
return ( V_101 ) ? V_2 : NULL ;
}
struct V_11 * F_84 ( struct V_49 * V_51 )
{
struct V_6 * V_2 ;
struct V_11 * V_12 = NULL ;
int V_101 = 0 ;
F_18 ( & V_102 ) ;
F_45 (dev, &w1_masters, w1_master_entry) {
F_18 ( & V_2 -> V_32 ) ;
F_45 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_23 . V_15 == V_51 -> V_15 &&
V_12 -> V_23 . V_51 == V_51 -> V_51 &&
V_12 -> V_23 . V_56 == V_51 -> V_56 ) {
V_101 = 1 ;
F_83 ( & V_2 -> V_13 ) ;
F_83 ( & V_12 -> V_13 ) ;
break;
}
}
F_21 ( & V_2 -> V_32 ) ;
if ( V_101 )
break;
}
F_21 ( & V_102 ) ;
return ( V_101 ) ? V_12 : NULL ;
}
void F_85 ( struct V_85 * V_86 , int V_103 )
{
struct V_11 * V_12 , * V_104 ;
struct V_6 * V_2 ;
F_18 ( & V_102 ) ;
F_45 (dev, &w1_masters, w1_master_entry) {
F_5 ( & V_2 -> V_2 , L_31
L_32 , V_2 -> V_9 , V_86 -> V_105 ) ;
F_18 ( & V_2 -> V_32 ) ;
F_86 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ( V_103 && V_12 -> V_15 -> V_105 == V_106
&& V_12 -> V_23 . V_15 == V_86 -> V_105 ) ||
( ! V_103 && V_12 -> V_15 -> V_105 == V_86 -> V_105 ) ) {
struct V_49 V_50 ;
memcpy ( & V_50 , & V_12 -> V_23 , sizeof( V_50 ) ) ;
F_51 ( V_12 ) ;
F_48 ( V_2 , & V_50 ) ;
}
}
F_5 ( & V_2 -> V_2 , L_31
L_33 , V_2 -> V_9 ) ;
F_21 ( & V_2 -> V_32 ) ;
}
F_21 ( & V_102 ) ;
}
void F_87 ( struct V_6 * V_2 , T_4 V_50 )
{
struct V_11 * V_12 ;
struct V_49 * V_34 ;
T_4 V_107 = F_42 ( V_50 ) ;
F_83 ( & V_2 -> V_13 ) ;
V_34 = (struct V_49 * ) & V_50 ;
V_12 = F_44 ( V_2 , V_34 ) ;
if ( V_12 ) {
F_70 ( V_93 , ( long * ) & V_12 -> V_94 ) ;
} else {
if ( V_50 && V_34 -> V_56 == F_43 ( ( V_24 * ) & V_107 , 7 ) )
F_48 ( V_2 , V_34 ) ;
}
F_88 ( & V_2 -> V_13 ) ;
}
void F_89 ( struct V_6 * V_2 , V_24 V_108 , T_6 V_109 )
{
T_4 V_110 , V_50 , V_111 ;
int V_52 , V_17 = 0 ;
int V_112 , V_113 ;
int V_114 , V_115 ;
V_24 V_116 = 0 ;
V_114 = 0 ;
V_50 = V_110 = 0 ;
V_113 = 0 ;
V_112 = - 1 ;
V_115 = 64 ;
while ( ! V_113 && ( V_17 ++ < V_2 -> V_41 ) ) {
V_110 = V_50 ;
V_50 = 0 ;
F_18 ( & V_2 -> V_117 ) ;
if ( F_90 ( V_2 ) ) {
F_21 ( & V_2 -> V_117 ) ;
F_5 ( & V_2 -> V_2 , L_34 ) ;
break;
}
if ( V_2 -> V_41 == 1 ) {
int V_118 ;
F_91 ( V_2 , V_119 ) ;
V_118 = F_23 ( V_2 , ( V_24 * ) & V_50 , 8 ) ;
F_21 ( & V_2 -> V_117 ) ;
if ( V_118 == 8 && V_50 )
V_109 ( V_2 , V_50 ) ;
break;
}
F_91 ( V_2 , V_108 ) ;
for ( V_52 = 0 ; V_52 < 64 ; ++ V_52 ) {
if ( V_52 == V_115 )
V_114 = 1 ;
else if ( V_52 > V_115 )
V_114 = 0 ;
else
V_114 = ( ( V_110 >> V_52 ) & 0x1 ) ;
V_116 = F_92 ( V_2 , V_114 ) ;
if ( ( V_116 & 0x03 ) == 0x03 )
break;
if ( V_116 == 0 )
V_112 = V_52 ;
V_111 = ( V_116 >> 2 ) ;
V_50 |= ( V_111 << V_52 ) ;
if ( ! V_2 -> V_120 && F_93 () ) {
F_21 ( & V_2 -> V_117 ) ;
F_5 ( & V_2 -> V_2 , L_35 ) ;
return;
}
}
F_21 ( & V_2 -> V_117 ) ;
if ( ( V_116 & 0x03 ) != 0x03 ) {
if ( ( V_115 == V_112 ) || ( V_112 < 0 ) )
V_113 = 1 ;
V_115 = V_112 ;
V_109 ( V_2 , V_50 ) ;
}
}
}
void F_94 ( struct V_6 * V_2 , V_24 V_108 ,
T_6 V_109 )
{
struct V_11 * V_12 , * V_104 ;
F_45 (sl, &dev->slist, w1_slave_entry)
F_95 ( V_93 , ( long * ) & V_12 -> V_94 ) ;
F_96 ( V_2 , V_108 , V_109 ) ;
F_86 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ! F_97 ( V_93 , ( unsigned long * ) & V_12 -> V_94 ) && ! -- V_12 -> V_97 )
F_51 ( V_12 ) ;
else if ( F_97 ( V_93 , ( unsigned long * ) & V_12 -> V_94 ) )
V_12 -> V_97 = V_2 -> V_98 ;
}
if ( V_2 -> V_36 > 0 )
V_2 -> V_36 -- ;
}
static void F_98 ( struct V_6 * V_2 , V_24 V_108 )
{
F_94 ( V_2 , V_108 , F_87 ) ;
}
int F_99 ( void * V_70 )
{
struct V_6 * V_2 = (struct V_6 * ) V_70 ;
const unsigned long V_121 = F_100 ( V_40 * 1000 ) ;
while ( ! F_93 () ) {
if ( V_2 -> V_36 ) {
F_18 ( & V_2 -> V_32 ) ;
F_98 ( V_2 , V_122 ) ;
F_21 ( & V_2 -> V_32 ) ;
}
F_101 () ;
F_102 ( V_123 ) ;
if ( F_93 () )
break;
if ( V_2 -> V_36 )
F_103 ( V_121 ) ;
else
F_104 () ;
}
F_88 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int T_7 F_105 ( void )
{
int V_124 ;
F_106 ( V_125 L_36 ) ;
F_107 () ;
V_124 = F_108 ( & V_81 ) ;
if ( V_124 ) {
F_106 ( V_126 L_37 , V_124 ) ;
goto V_127;
}
V_124 = F_109 ( & V_81 , & V_128 ) ;
if ( V_124 )
goto V_129;
V_124 = F_110 ( & V_64 ) ;
if ( V_124 ) {
F_106 ( V_126
L_38 ,
V_124 ) ;
goto V_129;
}
V_124 = F_110 ( & V_65 ) ;
if ( V_124 ) {
F_106 ( V_126
L_39 ,
V_124 ) ;
goto V_130;
}
return 0 ;
#if 0
err_out_slave_unregister:
driver_unregister(&w1_slave_driver);
#endif
V_130:
F_111 ( & V_64 ) ;
V_129:
F_112 ( & V_81 ) ;
V_127:
return V_124 ;
}
static void T_8 F_113 ( void )
{
struct V_6 * V_2 ;
F_45 (dev, &w1_masters, w1_master_entry)
F_114 ( V_2 ) ;
F_115 () ;
F_111 ( & V_65 ) ;
F_111 ( & V_64 ) ;
F_112 ( & V_81 ) ;
}
