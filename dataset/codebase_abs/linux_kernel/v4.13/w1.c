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
F_5 ( V_2 , L_2 , V_8 , V_12 -> V_9 , V_12 ) ;
F_9 ( V_12 -> V_13 ) ;
V_12 -> V_14 -> V_15 -- ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
return sprintf ( V_18 , L_3 , V_12 -> V_9 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
T_1 V_19 = sizeof( V_12 -> V_20 ) ;
memcpy ( V_18 , ( V_21 * ) & V_12 -> V_20 , V_19 ) ;
return V_19 ;
}
static T_1 F_12 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_18 , T_2 V_28 ,
T_3 V_19 )
{
struct V_11 * V_12 = F_13 ( V_25 ) ;
F_14 ( & V_12 -> V_14 -> V_29 ) ;
if ( F_15 ( V_12 ) ) {
V_19 = 0 ;
goto V_30;
}
F_16 ( V_12 -> V_14 , V_18 , V_19 ) ;
V_30:
F_17 ( & V_12 -> V_14 -> V_29 ) ;
return V_19 ;
}
static T_1 F_18 ( struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_18 , T_2 V_28 ,
T_3 V_19 )
{
struct V_11 * V_12 = F_13 ( V_25 ) ;
F_14 ( & V_12 -> V_14 -> V_29 ) ;
F_19 ( V_12 -> V_14 , V_18 , V_19 ) ;
F_17 ( & V_12 -> V_14 -> V_29 ) ;
return V_19 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_3 , V_7 -> V_9 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
long V_31 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_32 ;
V_32 = F_22 ( V_18 , 0 , & V_31 ) ;
if ( V_32 )
return V_32 ;
F_14 ( & V_7 -> V_29 ) ;
V_7 -> V_33 = V_31 ;
F_17 ( & V_7 -> V_29 ) ;
if ( V_31 )
F_23 ( V_7 -> V_34 ) ;
return V_19 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_4 , V_7 -> V_33 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
long V_31 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_32 ;
V_32 = F_22 ( V_18 , 0 , & V_31 ) ;
if ( V_32 )
return V_32 ;
F_14 ( & V_7 -> V_29 ) ;
V_7 -> V_35 = V_31 ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_4 , V_7 -> V_35 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_5 , V_7 -> V_36 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_28 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
T_1 V_19 ;
V_19 = sprintf ( V_18 , L_4 , V_37 ) ;
return V_19 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
T_1 V_19 ;
V_19 = sprintf ( V_18 , L_4 , V_38 ) ;
return V_19 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_16 * V_17 , const char * V_18 , T_3 V_19 )
{
int V_31 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_31 ( V_18 , 0 , & V_31 ) || V_31 < 1 )
return - V_39 ;
F_14 ( & V_7 -> V_29 ) ;
V_7 -> V_40 = V_31 ;
F_32 ( V_41 , & V_7 -> V_42 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_4 , V_7 -> V_40 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_34 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_6 , V_7 -> V_43 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_4 , V_7 -> V_15 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_44 = V_45 ;
struct V_46 * V_47 , * V_48 ;
struct V_11 * V_12 = NULL ;
F_14 ( & V_7 -> V_49 ) ;
F_37 (ent, n, &md->slist) {
V_12 = F_38 ( V_47 , struct V_11 , V_50 ) ;
V_44 -= snprintf ( V_18 + V_45 - V_44 , V_44 , L_3 , V_12 -> V_9 ) ;
}
if ( ! V_12 )
V_44 -= snprintf ( V_18 + V_45 - V_44 , V_44 , L_7 ) ;
F_17 ( & V_7 -> V_49 ) ;
return V_45 - V_44 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
int V_44 = V_45 ;
V_44 -= snprintf ( V_18 + V_45 - V_44 , V_44 ,
L_8 ) ;
return V_45 - V_44 ;
}
static int F_40 ( struct V_1 * V_2 , const char * V_18 , T_3 V_19 ,
struct V_51 * V_52 )
{
unsigned int V_13 ;
unsigned long long V_53 ;
int V_54 ;
T_4 V_55 ;
const char * V_56 = L_9
L_10 ;
if ( V_18 [ 2 ] != '-' ) {
F_41 ( V_2 , L_11 , V_56 ) ;
return - V_39 ;
}
V_54 = sscanf ( V_18 , L_12 , & V_13 , & V_53 ) ;
if ( V_54 != 2 ) {
F_41 ( V_2 , L_11 , V_56 ) ;
return - V_39 ;
}
V_52 -> V_13 = V_13 ;
V_52 -> V_53 = V_53 ;
V_55 = F_42 ( * ( T_4 * ) V_52 ) ;
V_52 -> V_57 = F_43 ( ( V_21 * ) & V_55 , 7 ) ;
#if 0
dev_info(dev, "With CRC device is %02x.%012llx.%02x.\n",
rn->family, (unsigned long long)rn->id, rn->crc);
#endif
return 0 ;
}
struct V_11 * F_44 ( struct V_6 * V_2 ,
struct V_51 * V_52 )
{
struct V_11 * V_12 ;
F_14 ( & V_2 -> V_49 ) ;
F_45 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_20 . V_13 == V_52 -> V_13 &&
V_12 -> V_20 . V_53 == V_52 -> V_53 &&
V_12 -> V_20 . V_57 == V_52 -> V_57 ) {
F_17 ( & V_2 -> V_49 ) ;
return V_12 ;
}
}
F_17 ( & V_2 -> V_49 ) ;
return NULL ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_51 V_52 ;
struct V_11 * V_12 ;
T_1 V_58 = V_19 ;
if ( F_40 ( V_2 , V_18 , V_19 , & V_52 ) )
return - V_39 ;
F_14 ( & V_7 -> V_29 ) ;
V_12 = F_44 ( V_7 , & V_52 ) ;
if ( V_12 ) {
F_47 ( V_2 , L_13 , V_12 -> V_9 ) ;
V_58 = - V_39 ;
} else {
F_48 ( V_7 , & V_52 ) ;
}
F_17 ( & V_7 -> V_29 ) ;
return V_58 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
int V_44 = V_45 ;
V_44 -= snprintf ( V_18 + V_45 - V_44 , V_44 ,
L_14 ) ;
return V_45 - V_44 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_51 V_52 ;
struct V_11 * V_12 ;
T_1 V_58 = V_19 ;
if ( F_40 ( V_2 , V_18 , V_19 , & V_52 ) )
return - V_39 ;
F_14 ( & V_7 -> V_29 ) ;
V_12 = F_44 ( V_7 , & V_52 ) ;
if ( V_12 ) {
V_58 = F_51 ( V_12 ) ;
if ( V_58 == 0 )
V_58 = V_19 ;
} else {
F_47 ( V_2 , L_15 , V_52 . V_13 ,
( unsigned long long ) V_52 . V_53 ) ;
V_58 = - V_39 ;
}
F_17 ( & V_7 -> V_29 ) ;
return V_58 ;
}
int F_52 ( struct V_6 * V_14 )
{
return F_53 ( & V_14 -> V_2 . V_25 , & V_59 ) ;
}
void F_54 ( struct V_6 * V_14 )
{
F_55 ( & V_14 -> V_2 . V_25 , & V_59 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_6 * V_7 = NULL ;
struct V_11 * V_12 = NULL ;
char * V_62 , * V_9 ;
int V_63 = 0 ;
if ( V_2 -> V_64 == & V_65 ) {
V_7 = F_57 ( V_2 , struct V_6 , V_2 ) ;
V_62 = L_16 ;
V_9 = V_7 -> V_9 ;
} else if ( V_2 -> V_64 == & V_66 ) {
V_12 = F_57 ( V_2 , struct V_11 , V_2 ) ;
V_62 = L_17 ;
V_9 = V_12 -> V_9 ;
} else {
F_5 ( V_2 , L_18 ) ;
return - V_39 ;
}
F_5 ( V_2 , L_19 ,
V_62 , V_9 , F_58 ( V_2 ) ) ;
if ( V_2 -> V_64 != & V_66 || ! V_12 )
goto V_67;
V_63 = F_59 ( V_61 , L_20 , V_12 -> V_20 . V_13 ) ;
if ( V_63 )
goto V_67;
V_63 = F_59 ( V_61 , L_21 ,
( unsigned long long ) V_12 -> V_20 . V_53 ) ;
V_67:
return V_63 ;
}
static int F_60 ( unsigned long V_68 , struct V_11 * V_12 )
{
struct V_69 * V_70 ;
int V_63 ;
V_70 = V_12 -> V_13 -> V_70 ;
if ( ! V_70 )
return 0 ;
switch ( V_68 ) {
case V_71 :
if ( V_70 -> V_72 ) {
V_63 = V_70 -> V_72 ( V_12 ) ;
if ( V_63 < 0 ) {
F_41 ( & V_12 -> V_2 ,
L_22 ,
V_63 ) ;
return V_63 ;
}
}
if ( V_70 -> V_73 ) {
V_63 = F_61 ( & V_12 -> V_2 . V_25 , V_70 -> V_73 ) ;
if ( V_63 ) {
F_41 ( & V_12 -> V_2 ,
L_23 ,
V_63 ) ;
return V_63 ;
}
}
break;
case V_74 :
if ( V_70 -> V_75 )
V_12 -> V_13 -> V_70 -> V_75 ( V_12 ) ;
if ( V_70 -> V_73 )
F_62 ( & V_12 -> V_2 . V_25 , V_70 -> V_73 ) ;
break;
}
return 0 ;
}
static int F_63 ( struct V_11 * V_12 )
{
int V_63 ;
V_12 -> V_2 . V_76 = & V_12 -> V_14 -> V_2 ;
V_12 -> V_2 . V_64 = & V_66 ;
V_12 -> V_2 . V_77 = & V_78 ;
V_12 -> V_2 . V_79 = & F_7 ;
V_12 -> V_2 . V_73 = V_80 ;
F_64 ( & V_12 -> V_2 , L_12 ,
( unsigned int ) V_12 -> V_20 . V_13 ,
( unsigned long long ) V_12 -> V_20 . V_53 ) ;
snprintf ( & V_12 -> V_9 [ 0 ] , sizeof( V_12 -> V_9 ) ,
L_12 ,
( unsigned int ) V_12 -> V_20 . V_13 ,
( unsigned long long ) V_12 -> V_20 . V_53 ) ;
F_5 ( & V_12 -> V_2 , L_24 , V_8 ,
F_58 ( & V_12 -> V_2 ) , V_12 ) ;
F_65 ( & V_12 -> V_2 , true ) ;
V_63 = F_66 ( & V_12 -> V_2 ) ;
if ( V_63 < 0 ) {
F_41 ( & V_12 -> V_2 ,
L_25 ,
F_58 ( & V_12 -> V_2 ) , V_63 ) ;
return V_63 ;
}
F_60 ( V_71 , V_12 ) ;
F_65 ( & V_12 -> V_2 , false ) ;
F_67 ( & V_12 -> V_2 . V_25 , V_81 ) ;
F_14 ( & V_12 -> V_14 -> V_49 ) ;
F_68 ( & V_12 -> V_50 , & V_12 -> V_14 -> V_82 ) ;
F_17 ( & V_12 -> V_14 -> V_49 ) ;
return 0 ;
}
int F_48 ( struct V_6 * V_2 , struct V_51 * V_52 )
{
struct V_11 * V_12 ;
struct V_83 * V_84 ;
int V_63 ;
struct V_85 V_86 ;
V_12 = F_69 ( sizeof( struct V_11 ) , V_87 ) ;
if ( ! V_12 ) {
F_41 ( & V_2 -> V_2 ,
L_26 ,
V_8 ) ;
return - V_88 ;
}
V_12 -> V_89 = V_90 ;
V_12 -> V_14 = V_2 ;
F_70 ( V_91 , & V_12 -> V_42 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memcpy ( & V_12 -> V_20 , V_52 , sizeof( V_12 -> V_20 ) ) ;
F_71 ( & V_12 -> V_92 , 1 ) ;
F_72 ( & V_12 -> V_14 -> V_92 ) ;
V_2 -> V_15 ++ ;
F_17 ( & V_2 -> V_29 ) ;
F_73 ( L_27 , V_52 -> V_13 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_74 ( & V_93 ) ;
V_84 = F_75 ( V_52 -> V_13 ) ;
if ( ! V_84 ) {
V_84 = & V_94 ;
F_47 ( & V_2 -> V_2 , L_28 ,
V_52 -> V_13 , V_52 -> V_13 ,
( unsigned long long ) V_52 -> V_53 , V_52 -> V_57 ) ;
}
F_76 ( V_84 ) ;
F_77 ( & V_93 ) ;
V_12 -> V_13 = V_84 ;
V_63 = F_63 ( V_12 ) ;
if ( V_63 < 0 ) {
F_41 ( & V_2 -> V_2 , L_29 , V_8 ,
V_12 -> V_9 ) ;
V_2 -> V_15 -- ;
F_9 ( V_12 -> V_13 ) ;
F_78 ( & V_12 -> V_14 -> V_92 ) ;
F_6 ( V_12 ) ;
return V_63 ;
}
V_12 -> V_95 = V_2 -> V_96 ;
memcpy ( V_86 . V_53 . V_53 , V_52 , sizeof( V_86 . V_53 ) ) ;
V_86 . type = V_97 ;
F_79 ( V_2 , & V_86 ) ;
return 0 ;
}
int F_80 ( struct V_11 * V_12 )
{
struct V_6 * V_2 = V_12 -> V_14 ;
int V_92 ;
F_14 ( & V_2 -> V_49 ) ;
V_92 = F_81 ( 1 , & V_12 -> V_92 ) ;
if ( V_92 == 0 ) {
struct V_85 V_86 ;
F_5 ( & V_12 -> V_2 , L_30 , V_8 ,
V_12 -> V_9 , V_12 ) ;
F_82 ( & V_12 -> V_50 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memcpy ( V_86 . V_53 . V_53 , & V_12 -> V_20 , sizeof( V_86 . V_53 ) ) ;
V_86 . type = V_98 ;
F_79 ( V_12 -> V_14 , & V_86 ) ;
F_60 ( V_74 , V_12 ) ;
F_83 ( & V_12 -> V_2 ) ;
#ifdef F_84
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
#endif
F_6 ( V_12 ) ;
}
F_78 ( & V_2 -> V_92 ) ;
F_17 ( & V_2 -> V_49 ) ;
return V_92 ;
}
int F_51 ( struct V_11 * V_12 )
{
int V_99 ;
F_14 ( & V_12 -> V_14 -> V_49 ) ;
V_99 = ! F_85 ( V_100 , & V_12 -> V_42 ) ;
F_70 ( V_100 , & V_12 -> V_42 ) ;
F_17 ( & V_12 -> V_14 -> V_49 ) ;
if ( V_99 )
V_99 = ! F_80 ( V_12 ) ;
return V_99 ? 0 : - V_101 ;
}
struct V_6 * F_86 ( T_5 V_53 )
{
struct V_6 * V_2 ;
int V_102 = 0 ;
F_14 ( & V_103 ) ;
F_45 (dev, &w1_masters, w1_master_entry) {
if ( V_2 -> V_53 == V_53 ) {
V_102 = 1 ;
F_72 ( & V_2 -> V_92 ) ;
break;
}
}
F_17 ( & V_103 ) ;
return ( V_102 ) ? V_2 : NULL ;
}
struct V_11 * F_87 ( struct V_51 * V_53 )
{
struct V_6 * V_2 ;
struct V_11 * V_12 = NULL ;
int V_102 = 0 ;
F_14 ( & V_103 ) ;
F_45 (dev, &w1_masters, w1_master_entry) {
F_14 ( & V_2 -> V_49 ) ;
F_45 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_20 . V_13 == V_53 -> V_13 &&
V_12 -> V_20 . V_53 == V_53 -> V_53 &&
V_12 -> V_20 . V_57 == V_53 -> V_57 ) {
V_102 = 1 ;
F_72 ( & V_2 -> V_92 ) ;
F_72 ( & V_12 -> V_92 ) ;
break;
}
}
F_17 ( & V_2 -> V_49 ) ;
if ( V_102 )
break;
}
F_17 ( & V_103 ) ;
return ( V_102 ) ? V_12 : NULL ;
}
void F_88 ( struct V_83 * V_84 , int V_104 )
{
struct V_11 * V_12 , * V_105 ;
struct V_6 * V_2 ;
F_14 ( & V_103 ) ;
F_45 (dev, &w1_masters, w1_master_entry) {
F_5 ( & V_2 -> V_2 , L_31
L_32 , V_2 -> V_9 , V_84 -> V_106 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_14 ( & V_2 -> V_49 ) ;
F_89 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ( V_104 && V_12 -> V_13 -> V_106 == V_107
&& V_12 -> V_20 . V_13 == V_84 -> V_106 ) ||
( ! V_104 && V_12 -> V_13 -> V_106 == V_84 -> V_106 ) ) {
struct V_51 V_52 ;
F_17 ( & V_2 -> V_49 ) ;
memcpy ( & V_52 , & V_12 -> V_20 , sizeof( V_52 ) ) ;
if ( ! F_51 ( V_12 ) )
F_48 ( V_2 , & V_52 ) ;
F_14 ( & V_2 -> V_49 ) ;
}
}
F_5 ( & V_2 -> V_2 , L_31
L_33 , V_2 -> V_9 ) ;
F_17 ( & V_2 -> V_49 ) ;
F_17 ( & V_2 -> V_29 ) ;
}
F_17 ( & V_103 ) ;
}
void F_90 ( struct V_6 * V_2 , T_4 V_52 )
{
struct V_11 * V_12 ;
struct V_51 * V_31 ;
T_4 V_108 = F_42 ( V_52 ) ;
F_72 ( & V_2 -> V_92 ) ;
V_31 = (struct V_51 * ) & V_52 ;
V_12 = F_44 ( V_2 , V_31 ) ;
if ( V_12 ) {
F_70 ( V_91 , & V_12 -> V_42 ) ;
} else {
if ( V_52 && V_31 -> V_57 == F_43 ( ( V_21 * ) & V_108 , 7 ) )
F_48 ( V_2 , V_31 ) ;
}
F_78 ( & V_2 -> V_92 ) ;
}
void F_91 ( struct V_6 * V_2 , V_21 V_109 , T_6 V_110 )
{
T_4 V_111 , V_52 , V_112 ;
int V_54 , V_15 = 0 ;
int V_113 , V_114 ;
int V_115 , V_116 ;
V_21 V_117 = 0 ;
V_115 = 0 ;
V_52 = V_2 -> V_118 ;
V_111 = 0 ;
V_114 = 0 ;
V_113 = - 1 ;
V_116 = 64 ;
while ( ! V_114 && ( V_15 ++ < V_2 -> V_40 ) ) {
V_111 = V_52 ;
V_52 = 0 ;
F_14 ( & V_2 -> V_119 ) ;
if ( F_92 ( V_2 ) ) {
F_17 ( & V_2 -> V_119 ) ;
F_5 ( & V_2 -> V_2 , L_34 ) ;
break;
}
if ( V_2 -> V_40 == 1 ) {
int V_120 ;
F_93 ( V_2 , V_121 ) ;
V_120 = F_19 ( V_2 , ( V_21 * ) & V_52 , 8 ) ;
F_17 ( & V_2 -> V_119 ) ;
if ( V_120 == 8 && V_52 )
V_110 ( V_2 , V_52 ) ;
break;
}
F_93 ( V_2 , V_109 ) ;
for ( V_54 = 0 ; V_54 < 64 ; ++ V_54 ) {
if ( V_54 == V_116 )
V_115 = 1 ;
else if ( V_54 > V_116 )
V_115 = 0 ;
else
V_115 = ( ( V_111 >> V_54 ) & 0x1 ) ;
V_117 = F_94 ( V_2 , V_115 ) ;
if ( ( V_117 & 0x03 ) == 0x03 )
break;
if ( V_117 == 0 )
V_113 = V_54 ;
V_112 = ( V_117 >> 2 ) ;
V_52 |= ( V_112 << V_54 ) ;
if ( F_85 ( V_122 , & V_2 -> V_42 ) ) {
F_17 ( & V_2 -> V_119 ) ;
F_5 ( & V_2 -> V_2 , L_35 ) ;
return;
}
}
F_17 ( & V_2 -> V_119 ) ;
if ( ( V_117 & 0x03 ) != 0x03 ) {
if ( ( V_116 == V_113 ) || ( V_113 < 0 ) ) {
V_114 = 1 ;
V_2 -> V_118 = 0 ;
} else {
V_2 -> V_118 = V_52 ;
}
V_116 = V_113 ;
V_110 ( V_2 , V_52 ) ;
}
if ( ! V_114 && V_15 == V_2 -> V_40 &&
! F_85 ( V_41 , & V_2 -> V_42 ) ) {
F_47 ( & V_2 -> V_2 , L_36
L_37 , V_8 ,
V_2 -> V_40 ) ;
F_70 ( V_41 , & V_2 -> V_42 ) ;
}
}
}
void F_95 ( struct V_6 * V_2 , V_21 V_109 ,
T_6 V_110 )
{
struct V_11 * V_12 , * V_105 ;
F_14 ( & V_2 -> V_49 ) ;
F_45 (sl, &dev->slist, w1_slave_entry)
F_32 ( V_91 , & V_12 -> V_42 ) ;
F_17 ( & V_2 -> V_49 ) ;
F_96 ( V_2 , V_109 , V_110 ) ;
F_14 ( & V_2 -> V_49 ) ;
F_89 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ! F_85 ( V_91 , & V_12 -> V_42 ) && ! -- V_12 -> V_95 ) {
F_17 ( & V_2 -> V_49 ) ;
F_51 ( V_12 ) ;
F_14 ( & V_2 -> V_49 ) ;
}
else if ( F_85 ( V_91 , & V_12 -> V_42 ) )
V_12 -> V_95 = V_2 -> V_96 ;
}
F_17 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_33 > 0 )
V_2 -> V_33 -- ;
}
static void F_97 ( struct V_6 * V_2 , V_21 V_109 )
{
F_95 ( V_2 , V_109 , F_90 ) ;
}
int F_98 ( struct V_6 * V_2 )
{
int V_32 = 0 ;
struct V_123 * V_124 , * V_125 ;
while ( ! F_99 ( & V_2 -> V_126 ) ) {
F_89 (async_cmd, async_n, &dev->async_list,
async_entry) {
F_17 ( & V_2 -> V_49 ) ;
V_124 -> V_110 ( V_2 , V_124 ) ;
V_32 = 1 ;
F_14 ( & V_2 -> V_49 ) ;
}
}
return V_32 ;
}
int F_100 ( void * V_127 )
{
struct V_6 * V_2 = (struct V_6 * ) V_127 ;
const unsigned long V_128 =
F_101 ( V_37 * 1000000 + V_38 ) ;
unsigned long V_129 = 0 ;
for (; ; ) {
if ( ! V_129 && V_2 -> V_33 ) {
F_14 ( & V_2 -> V_29 ) ;
F_97 ( V_2 , V_130 ) ;
F_17 ( & V_2 -> V_29 ) ;
}
F_14 ( & V_2 -> V_49 ) ;
if ( ! F_98 ( V_2 ) && V_129 ) {
V_129 = 1 ;
}
F_102 ( V_131 ) ;
F_17 ( & V_2 -> V_49 ) ;
if ( F_103 () )
break;
if ( V_2 -> V_33 ) {
if ( ! V_129 )
V_129 = V_128 ;
V_129 = F_104 ( V_129 ) ;
}
else
F_105 () ;
}
F_78 ( & V_2 -> V_92 ) ;
return 0 ;
}
static int T_7 F_106 ( void )
{
int V_132 ;
F_107 ( L_38 ) ;
F_108 () ;
V_132 = F_109 ( & V_78 ) ;
if ( V_132 ) {
F_110 ( L_39 , V_132 ) ;
goto V_133;
}
V_132 = F_111 ( & V_65 ) ;
if ( V_132 ) {
F_110 ( L_40 ,
V_132 ) ;
goto V_134;
}
V_132 = F_111 ( & V_66 ) ;
if ( V_132 ) {
F_110 ( L_41 ,
V_132 ) ;
goto V_135;
}
return 0 ;
#if 0
err_out_slave_unregister:
driver_unregister(&w1_slave_driver);
#endif
V_135:
F_112 ( & V_65 ) ;
V_134:
F_113 ( & V_78 ) ;
V_133:
return V_132 ;
}
static void T_8 F_114 ( void )
{
struct V_6 * V_2 ;
F_45 (dev, &w1_masters, w1_master_entry)
F_115 ( V_2 ) ;
F_116 () ;
F_112 ( & V_66 ) ;
F_112 ( & V_65 ) ;
F_113 ( & V_78 ) ;
}
