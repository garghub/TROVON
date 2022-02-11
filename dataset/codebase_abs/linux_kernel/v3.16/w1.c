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
struct V_16 * V_17 , const char * V_18 , T_3 V_19 )
{
int V_31 ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
if ( F_30 ( V_18 , 0 , & V_31 ) == - V_38 || V_31 < 1 )
return - V_38 ;
F_14 ( & V_7 -> V_29 ) ;
V_7 -> V_39 = V_31 ;
F_31 ( V_40 , & V_7 -> V_41 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_4 , V_7 -> V_39 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_6 , V_7 -> V_42 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_34 ( struct V_1 * V_2 , struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_1 V_19 ;
F_14 ( & V_7 -> V_29 ) ;
V_19 = sprintf ( V_18 , L_4 , V_7 -> V_15 ) ;
F_17 ( & V_7 -> V_29 ) ;
return V_19 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_43 = V_44 ;
struct V_45 * V_46 , * V_47 ;
struct V_11 * V_12 = NULL ;
F_14 ( & V_7 -> V_48 ) ;
F_36 (ent, n, &md->slist) {
V_12 = F_37 ( V_46 , struct V_11 , V_49 ) ;
V_43 -= snprintf ( V_18 + V_44 - V_43 , V_43 , L_3 , V_12 -> V_9 ) ;
}
if ( ! V_12 )
V_43 -= snprintf ( V_18 + V_44 - V_43 , V_43 , L_7 ) ;
F_17 ( & V_7 -> V_48 ) ;
return V_44 - V_43 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
int V_43 = V_44 ;
V_43 -= snprintf ( V_18 + V_44 - V_43 , V_43 ,
L_8 ) ;
return V_44 - V_43 ;
}
static int F_39 ( struct V_1 * V_2 , const char * V_18 , T_3 V_19 ,
struct V_50 * V_51 )
{
unsigned int V_13 ;
unsigned long long V_52 ;
int V_53 ;
T_4 V_54 ;
const char * V_55 = L_9
L_10 ;
if ( V_18 [ 2 ] != '-' ) {
F_40 ( V_2 , L_11 , V_55 ) ;
return - V_38 ;
}
V_53 = sscanf ( V_18 , L_12 , & V_13 , & V_52 ) ;
if ( V_53 != 2 ) {
F_40 ( V_2 , L_11 , V_55 ) ;
return - V_38 ;
}
V_51 -> V_13 = V_13 ;
V_51 -> V_52 = V_52 ;
V_54 = F_41 ( * ( T_4 * ) V_51 ) ;
V_51 -> V_56 = F_42 ( ( V_21 * ) & V_54 , 7 ) ;
#if 0
dev_info(dev, "With CRC device is %02x.%012llx.%02x.\n",
rn->family, (unsigned long long)rn->id, rn->crc);
#endif
return 0 ;
}
struct V_11 * F_43 ( struct V_6 * V_2 ,
struct V_50 * V_51 )
{
struct V_11 * V_12 ;
F_14 ( & V_2 -> V_48 ) ;
F_44 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_20 . V_13 == V_51 -> V_13 &&
V_12 -> V_20 . V_52 == V_51 -> V_52 &&
V_12 -> V_20 . V_56 == V_51 -> V_56 ) {
F_17 ( & V_2 -> V_48 ) ;
return V_12 ;
}
}
F_17 ( & V_2 -> V_48 ) ;
return NULL ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_50 V_51 ;
struct V_11 * V_12 ;
T_1 V_57 = V_19 ;
if ( F_39 ( V_2 , V_18 , V_19 , & V_51 ) )
return - V_38 ;
F_14 ( & V_7 -> V_29 ) ;
V_12 = F_43 ( V_7 , & V_51 ) ;
if ( V_12 ) {
F_46 ( V_2 , L_13 , V_12 -> V_9 ) ;
V_57 = - V_38 ;
} else {
F_47 ( V_7 , & V_51 ) ;
}
F_17 ( & V_7 -> V_29 ) ;
return V_57 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_16 * V_17 , char * V_18 )
{
int V_43 = V_44 ;
V_43 -= snprintf ( V_18 + V_44 - V_43 , V_43 ,
L_14 ) ;
return V_44 - V_43 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_50 V_51 ;
struct V_11 * V_12 ;
T_1 V_57 = V_19 ;
if ( F_39 ( V_2 , V_18 , V_19 , & V_51 ) )
return - V_38 ;
F_14 ( & V_7 -> V_29 ) ;
V_12 = F_43 ( V_7 , & V_51 ) ;
if ( V_12 ) {
V_57 = F_50 ( V_12 ) ;
if ( V_57 == 0 )
V_57 = V_19 ;
} else {
F_46 ( V_2 , L_15 , V_51 . V_13 ,
( unsigned long long ) V_51 . V_52 ) ;
V_57 = - V_38 ;
}
F_17 ( & V_7 -> V_29 ) ;
return V_57 ;
}
int F_51 ( struct V_6 * V_14 )
{
return F_52 ( & V_14 -> V_2 . V_25 , & V_58 ) ;
}
void F_53 ( struct V_6 * V_14 )
{
F_54 ( & V_14 -> V_2 . V_25 , & V_58 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_6 * V_7 = NULL ;
struct V_11 * V_12 = NULL ;
char * V_61 , * V_9 ;
int V_62 = 0 ;
if ( V_2 -> V_63 == & V_64 ) {
V_7 = F_56 ( V_2 , struct V_6 , V_2 ) ;
V_61 = L_16 ;
V_9 = V_7 -> V_9 ;
} else if ( V_2 -> V_63 == & V_65 ) {
V_12 = F_56 ( V_2 , struct V_11 , V_2 ) ;
V_61 = L_17 ;
V_9 = V_12 -> V_9 ;
} else {
F_5 ( V_2 , L_18 ) ;
return - V_38 ;
}
F_5 ( V_2 , L_19 ,
V_61 , V_9 , F_57 ( V_2 ) ) ;
if ( V_2 -> V_63 != & V_65 || ! V_12 )
goto V_66;
V_62 = F_58 ( V_60 , L_20 , V_12 -> V_20 . V_13 ) ;
if ( V_62 )
goto V_66;
V_62 = F_58 ( V_60 , L_21 ,
( unsigned long long ) V_12 -> V_20 . V_52 ) ;
V_66:
return V_62 ;
}
static int F_59 ( unsigned long V_67 , struct V_11 * V_12 )
{
struct V_68 * V_69 ;
int V_62 ;
V_69 = V_12 -> V_13 -> V_69 ;
if ( ! V_69 )
return 0 ;
switch ( V_67 ) {
case V_70 :
if ( V_69 -> V_71 ) {
V_62 = V_69 -> V_71 ( V_12 ) ;
if ( V_62 < 0 ) {
F_40 ( & V_12 -> V_2 ,
L_22 ,
V_62 ) ;
return V_62 ;
}
}
if ( V_69 -> V_72 ) {
V_62 = F_60 ( & V_12 -> V_2 . V_25 , V_69 -> V_72 ) ;
if ( V_62 ) {
F_40 ( & V_12 -> V_2 ,
L_23 ,
V_62 ) ;
return V_62 ;
}
}
break;
case V_73 :
if ( V_69 -> V_74 )
V_12 -> V_13 -> V_69 -> V_74 ( V_12 ) ;
if ( V_69 -> V_72 )
F_61 ( & V_12 -> V_2 . V_25 , V_69 -> V_72 ) ;
break;
}
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
int V_62 ;
V_12 -> V_2 . V_75 = & V_12 -> V_14 -> V_2 ;
V_12 -> V_2 . V_63 = & V_65 ;
V_12 -> V_2 . V_76 = & V_77 ;
V_12 -> V_2 . V_78 = & F_7 ;
V_12 -> V_2 . V_72 = V_79 ;
F_63 ( & V_12 -> V_2 , L_12 ,
( unsigned int ) V_12 -> V_20 . V_13 ,
( unsigned long long ) V_12 -> V_20 . V_52 ) ;
snprintf ( & V_12 -> V_9 [ 0 ] , sizeof( V_12 -> V_9 ) ,
L_12 ,
( unsigned int ) V_12 -> V_20 . V_13 ,
( unsigned long long ) V_12 -> V_20 . V_52 ) ;
F_5 ( & V_12 -> V_2 , L_24 , V_8 ,
F_57 ( & V_12 -> V_2 ) , V_12 ) ;
F_64 ( & V_12 -> V_2 , true ) ;
V_62 = F_65 ( & V_12 -> V_2 ) ;
if ( V_62 < 0 ) {
F_40 ( & V_12 -> V_2 ,
L_25 ,
F_57 ( & V_12 -> V_2 ) , V_62 ) ;
return V_62 ;
}
F_59 ( V_70 , V_12 ) ;
F_64 ( & V_12 -> V_2 , false ) ;
F_66 ( & V_12 -> V_2 . V_25 , V_80 ) ;
F_14 ( & V_12 -> V_14 -> V_48 ) ;
F_67 ( & V_12 -> V_49 , & V_12 -> V_14 -> V_81 ) ;
F_17 ( & V_12 -> V_14 -> V_48 ) ;
return 0 ;
}
int F_47 ( struct V_6 * V_2 , struct V_50 * V_51 )
{
struct V_11 * V_12 ;
struct V_82 * V_83 ;
int V_62 ;
struct V_84 V_85 ;
V_12 = F_68 ( sizeof( struct V_11 ) , V_86 ) ;
if ( ! V_12 ) {
F_40 ( & V_2 -> V_2 ,
L_26 ,
V_8 ) ;
return - V_87 ;
}
V_12 -> V_88 = V_89 ;
V_12 -> V_14 = V_2 ;
F_69 ( V_90 , & V_12 -> V_41 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
memcpy ( & V_12 -> V_20 , V_51 , sizeof( V_12 -> V_20 ) ) ;
F_70 ( & V_12 -> V_91 , 1 ) ;
F_71 ( & V_12 -> V_14 -> V_91 ) ;
F_17 ( & V_2 -> V_29 ) ;
F_72 ( L_27 , V_51 -> V_13 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_73 ( & V_92 ) ;
V_83 = F_74 ( V_51 -> V_13 ) ;
if ( ! V_83 ) {
V_83 = & V_93 ;
F_46 ( & V_2 -> V_2 , L_28 ,
V_51 -> V_13 , V_51 -> V_13 ,
( unsigned long long ) V_51 -> V_52 , V_51 -> V_56 ) ;
}
F_75 ( V_83 ) ;
F_76 ( & V_92 ) ;
V_12 -> V_13 = V_83 ;
V_62 = F_62 ( V_12 ) ;
if ( V_62 < 0 ) {
F_40 ( & V_2 -> V_2 , L_29 , V_8 ,
V_12 -> V_9 ) ;
F_9 ( V_12 -> V_13 ) ;
F_6 ( V_12 ) ;
return V_62 ;
}
V_12 -> V_94 = V_2 -> V_95 ;
V_2 -> V_15 ++ ;
memcpy ( V_85 . V_52 . V_52 , V_51 , sizeof( V_85 . V_52 ) ) ;
V_85 . type = V_96 ;
F_77 ( V_2 , & V_85 ) ;
return 0 ;
}
int F_78 ( struct V_11 * V_12 )
{
struct V_6 * V_2 = V_12 -> V_14 ;
int V_91 ;
F_14 ( & V_2 -> V_48 ) ;
V_91 = F_79 ( 1 , & V_12 -> V_91 ) ;
if ( V_91 == 0 ) {
struct V_84 V_85 ;
F_5 ( & V_12 -> V_2 , L_30 , V_8 ,
V_12 -> V_9 , V_12 ) ;
F_80 ( & V_12 -> V_49 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
memcpy ( V_85 . V_52 . V_52 , & V_12 -> V_20 , sizeof( V_85 . V_52 ) ) ;
V_85 . type = V_97 ;
F_77 ( V_12 -> V_14 , & V_85 ) ;
F_59 ( V_73 , V_12 ) ;
F_81 ( & V_12 -> V_2 ) ;
#ifdef F_82
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
#endif
F_6 ( V_12 ) ;
}
F_83 ( & V_2 -> V_91 ) ;
F_17 ( & V_2 -> V_48 ) ;
return V_91 ;
}
int F_50 ( struct V_11 * V_12 )
{
int V_98 ;
F_14 ( & V_12 -> V_14 -> V_48 ) ;
V_98 = ! F_84 ( V_99 , & V_12 -> V_41 ) ;
F_69 ( V_99 , & V_12 -> V_41 ) ;
F_17 ( & V_12 -> V_14 -> V_48 ) ;
if ( V_98 )
V_98 = ! F_78 ( V_12 ) ;
return V_98 ? 0 : - V_100 ;
}
struct V_6 * F_85 ( T_5 V_52 )
{
struct V_6 * V_2 ;
int V_101 = 0 ;
F_14 ( & V_102 ) ;
F_44 (dev, &w1_masters, w1_master_entry) {
if ( V_2 -> V_52 == V_52 ) {
V_101 = 1 ;
F_71 ( & V_2 -> V_91 ) ;
break;
}
}
F_17 ( & V_102 ) ;
return ( V_101 ) ? V_2 : NULL ;
}
struct V_11 * F_86 ( struct V_50 * V_52 )
{
struct V_6 * V_2 ;
struct V_11 * V_12 = NULL ;
int V_101 = 0 ;
F_14 ( & V_102 ) ;
F_44 (dev, &w1_masters, w1_master_entry) {
F_14 ( & V_2 -> V_48 ) ;
F_44 (sl, &dev->slist, w1_slave_entry) {
if ( V_12 -> V_20 . V_13 == V_52 -> V_13 &&
V_12 -> V_20 . V_52 == V_52 -> V_52 &&
V_12 -> V_20 . V_56 == V_52 -> V_56 ) {
V_101 = 1 ;
F_71 ( & V_2 -> V_91 ) ;
F_71 ( & V_12 -> V_91 ) ;
break;
}
}
F_17 ( & V_2 -> V_48 ) ;
if ( V_101 )
break;
}
F_17 ( & V_102 ) ;
return ( V_101 ) ? V_12 : NULL ;
}
void F_87 ( struct V_82 * V_83 , int V_103 )
{
struct V_11 * V_12 , * V_104 ;
struct V_6 * V_2 ;
F_14 ( & V_102 ) ;
F_44 (dev, &w1_masters, w1_master_entry) {
F_5 ( & V_2 -> V_2 , L_31
L_32 , V_2 -> V_9 , V_83 -> V_105 ) ;
F_14 ( & V_2 -> V_29 ) ;
F_14 ( & V_2 -> V_48 ) ;
F_88 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ( V_103 && V_12 -> V_13 -> V_105 == V_106
&& V_12 -> V_20 . V_13 == V_83 -> V_105 ) ||
( ! V_103 && V_12 -> V_13 -> V_105 == V_83 -> V_105 ) ) {
struct V_50 V_51 ;
F_17 ( & V_2 -> V_48 ) ;
memcpy ( & V_51 , & V_12 -> V_20 , sizeof( V_51 ) ) ;
if ( ! F_50 ( V_12 ) )
F_47 ( V_2 , & V_51 ) ;
F_14 ( & V_2 -> V_48 ) ;
}
}
F_5 ( & V_2 -> V_2 , L_31
L_33 , V_2 -> V_9 ) ;
F_17 ( & V_2 -> V_48 ) ;
F_17 ( & V_2 -> V_29 ) ;
}
F_17 ( & V_102 ) ;
}
void F_89 ( struct V_6 * V_2 , T_4 V_51 )
{
struct V_11 * V_12 ;
struct V_50 * V_31 ;
T_4 V_107 = F_41 ( V_51 ) ;
F_71 ( & V_2 -> V_91 ) ;
V_31 = (struct V_50 * ) & V_51 ;
V_12 = F_43 ( V_2 , V_31 ) ;
if ( V_12 ) {
F_69 ( V_90 , & V_12 -> V_41 ) ;
} else {
if ( V_51 && V_31 -> V_56 == F_42 ( ( V_21 * ) & V_107 , 7 ) )
F_47 ( V_2 , V_31 ) ;
}
F_83 ( & V_2 -> V_91 ) ;
}
void F_90 ( struct V_6 * V_2 , V_21 V_108 , T_6 V_109 )
{
T_4 V_110 , V_51 , V_111 ;
int V_53 , V_15 = 0 ;
int V_112 , V_113 ;
int V_114 , V_115 ;
V_21 V_116 = 0 ;
V_114 = 0 ;
V_51 = V_2 -> V_117 ;
V_110 = 0 ;
V_113 = 0 ;
V_112 = - 1 ;
V_115 = 64 ;
while ( ! V_113 && ( V_15 ++ < V_2 -> V_39 ) ) {
V_110 = V_51 ;
V_51 = 0 ;
F_14 ( & V_2 -> V_118 ) ;
if ( F_91 ( V_2 ) ) {
F_17 ( & V_2 -> V_118 ) ;
F_5 ( & V_2 -> V_2 , L_34 ) ;
break;
}
if ( V_2 -> V_39 == 1 ) {
int V_119 ;
F_92 ( V_2 , V_120 ) ;
V_119 = F_19 ( V_2 , ( V_21 * ) & V_51 , 8 ) ;
F_17 ( & V_2 -> V_118 ) ;
if ( V_119 == 8 && V_51 )
V_109 ( V_2 , V_51 ) ;
break;
}
F_92 ( V_2 , V_108 ) ;
for ( V_53 = 0 ; V_53 < 64 ; ++ V_53 ) {
if ( V_53 == V_115 )
V_114 = 1 ;
else if ( V_53 > V_115 )
V_114 = 0 ;
else
V_114 = ( ( V_110 >> V_53 ) & 0x1 ) ;
V_116 = F_93 ( V_2 , V_114 ) ;
if ( ( V_116 & 0x03 ) == 0x03 )
break;
if ( V_116 == 0 )
V_112 = V_53 ;
V_111 = ( V_116 >> 2 ) ;
V_51 |= ( V_111 << V_53 ) ;
if ( F_84 ( V_121 , & V_2 -> V_41 ) ) {
F_17 ( & V_2 -> V_118 ) ;
F_5 ( & V_2 -> V_2 , L_35 ) ;
return;
}
}
F_17 ( & V_2 -> V_118 ) ;
if ( ( V_116 & 0x03 ) != 0x03 ) {
if ( ( V_115 == V_112 ) || ( V_112 < 0 ) ) {
V_113 = 1 ;
V_2 -> V_117 = 0 ;
} else {
V_2 -> V_117 = V_51 ;
}
V_115 = V_112 ;
V_109 ( V_2 , V_51 ) ;
}
if ( ! V_113 && V_15 == V_2 -> V_39 &&
! F_84 ( V_40 , & V_2 -> V_41 ) ) {
F_46 ( & V_2 -> V_2 , L_36
L_37 , V_8 ,
V_2 -> V_39 ) ;
F_69 ( V_40 , & V_2 -> V_41 ) ;
}
}
}
void F_94 ( struct V_6 * V_2 , V_21 V_108 ,
T_6 V_109 )
{
struct V_11 * V_12 , * V_104 ;
F_14 ( & V_2 -> V_48 ) ;
F_44 (sl, &dev->slist, w1_slave_entry)
F_31 ( V_90 , & V_12 -> V_41 ) ;
F_17 ( & V_2 -> V_48 ) ;
F_95 ( V_2 , V_108 , V_109 ) ;
F_14 ( & V_2 -> V_48 ) ;
F_88 (sl, sln, &dev->slist, w1_slave_entry) {
if ( ! F_84 ( V_90 , & V_12 -> V_41 ) && ! -- V_12 -> V_94 ) {
F_17 ( & V_2 -> V_48 ) ;
F_50 ( V_12 ) ;
F_14 ( & V_2 -> V_48 ) ;
}
else if ( F_84 ( V_90 , & V_12 -> V_41 ) )
V_12 -> V_94 = V_2 -> V_95 ;
}
F_17 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_33 > 0 )
V_2 -> V_33 -- ;
}
static void F_96 ( struct V_6 * V_2 , V_21 V_108 )
{
F_94 ( V_2 , V_108 , F_89 ) ;
}
int F_97 ( struct V_6 * V_2 )
{
int V_32 = 0 ;
struct V_122 * V_123 , * V_124 ;
while ( ! F_98 ( & V_2 -> V_125 ) ) {
F_88 (async_cmd, async_n, &dev->async_list,
async_entry) {
F_17 ( & V_2 -> V_48 ) ;
V_123 -> V_109 ( V_2 , V_123 ) ;
V_32 = 1 ;
F_14 ( & V_2 -> V_48 ) ;
}
}
return V_32 ;
}
int F_99 ( void * V_126 )
{
struct V_6 * V_2 = (struct V_6 * ) V_126 ;
const unsigned long V_127 = F_100 ( V_37 * 1000 ) ;
unsigned long V_128 = 0 ;
for (; ; ) {
if ( ! V_128 && V_2 -> V_33 ) {
F_14 ( & V_2 -> V_29 ) ;
F_96 ( V_2 , V_129 ) ;
F_17 ( & V_2 -> V_29 ) ;
}
F_14 ( & V_2 -> V_48 ) ;
if ( ! F_97 ( V_2 ) && V_128 ) {
V_128 = 1 ;
}
F_101 () ;
F_102 ( V_130 ) ;
F_17 ( & V_2 -> V_48 ) ;
if ( F_103 () )
break;
if ( V_2 -> V_33 ) {
if ( ! V_128 )
V_128 = V_127 ;
V_128 = F_104 ( V_128 ) ;
}
else
F_105 () ;
}
F_83 ( & V_2 -> V_91 ) ;
return 0 ;
}
static int T_7 F_106 ( void )
{
int V_131 ;
F_107 ( V_132 L_38 ) ;
F_108 () ;
V_131 = F_109 ( & V_77 ) ;
if ( V_131 ) {
F_107 ( V_133 L_39 , V_131 ) ;
goto V_134;
}
V_131 = F_110 ( & V_64 ) ;
if ( V_131 ) {
F_107 ( V_133
L_40 ,
V_131 ) ;
goto V_135;
}
V_131 = F_110 ( & V_65 ) ;
if ( V_131 ) {
F_107 ( V_133
L_41 ,
V_131 ) ;
goto V_136;
}
return 0 ;
#if 0
err_out_slave_unregister:
driver_unregister(&w1_slave_driver);
#endif
V_136:
F_111 ( & V_64 ) ;
V_135:
F_112 ( & V_77 ) ;
V_134:
return V_131 ;
}
static void T_8 F_113 ( void )
{
struct V_6 * V_2 ;
F_44 (dev, &w1_masters, w1_master_entry)
F_114 ( V_2 ) ;
F_115 () ;
F_111 ( & V_65 ) ;
F_111 ( & V_64 ) ;
F_112 ( & V_77 ) ;
}
