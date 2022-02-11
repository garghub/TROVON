static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_13 == V_14 ) {
return snprintf ( V_5 , V_15 , L_1 ,
V_11 -> V_16 . V_17 . V_18 ) ;
} else {
return snprintf ( V_5 , V_15 , L_1 ,
V_11 -> V_16 . V_19 . V_18 ) ;
}
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_13 == V_14 ) {
return snprintf ( V_5 , V_15 , L_2 ,
( V_20 ) ( V_11 -> V_16 . V_17 . V_21 >> 24 ) ,
( V_20 ) ( V_11 -> V_16 . V_17 . V_21 >> 16 ) ,
( V_20 ) ( V_11 -> V_16 . V_17 . V_21 >> 8 ) ,
( V_20 ) ( V_11 -> V_16 . V_17 . V_21 ) ) ;
} else {
return snprintf ( V_5 , V_15 , L_2 ,
( V_20 ) ( V_11 -> V_16 . V_19 . V_21 >> 24 ) ,
( V_20 ) ( V_11 -> V_16 . V_19 . V_21 >> 16 ) ,
( V_20 ) ( V_11 -> V_16 . V_19 . V_21 >> 8 ) ,
( V_20 ) ( V_11 -> V_16 . V_19 . V_21 ) ) ;
}
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_13 == V_14 ) {
return snprintf ( V_5 , V_15 , L_1 ,
V_11 -> V_16 . V_17 . V_22 ) ;
} else {
return snprintf ( V_5 , V_15 , L_1 ,
V_11 -> V_16 . V_19 . V_22 ) ;
}
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_13 == V_14 ) {
return snprintf ( V_5 , V_15 , L_3 ,
( V_23 ) ( V_11 -> V_16 . V_17 . V_24 >> 16 )
) ;
} else {
return snprintf ( V_5 , V_15 , L_3 ,
( V_23 ) ( V_11 -> V_16 . V_19 . V_24 >> 16 )
) ;
}
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_13 == V_14 ) {
return snprintf ( V_5 , V_15 , L_3 ,
V_11 -> V_16 . V_17 . V_24 & 0x0000FFFF
) ;
} else {
return snprintf ( V_5 , V_15 , L_3 ,
V_11 -> V_16 . V_19 . V_24 & 0x0000FFFF
) ;
}
}
static T_1
F_8 ( unsigned int V_25 , char * V_5 )
{
T_1 V_26 = 0 ;
if ( V_25 & V_27 )
V_26 = sprintf ( V_5 , L_4 , L_5 ) ;
if ( V_25 & V_28 )
V_26 += sprintf ( V_5 + V_26 , L_6 , V_26 ? L_7 : L_8 , L_9 ) ;
V_26 += sprintf ( V_5 + V_26 , L_10 ) ;
return V_26 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned int V_25 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_13 == V_14 )
V_25 = ( V_11 -> V_16 . V_17 . V_29 &
0xfe000000 ) >> 25 ;
else
V_25 = ( V_11 -> V_16 . V_19 . V_29 &
0xfe000000 ) >> 25 ;
return F_8 ( V_25 , V_5 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_15 , L_11 ,
F_11 ( * ( V_30 * ) V_11 -> V_31 ) ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_15 , L_12 , V_11 -> V_32 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_34 = 0 ;
if ( sscanf ( V_5 , L_13 , & V_34 ) != 1 )
return - V_35 ;
V_11 -> V_32 = V_34 ;
return strlen ( V_5 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_36 ;
#define F_15 ( T_3 , T_4 ) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[AAP1].virt_ptr + (r) * 32 \
+ (c)))
char * V_37 = V_5 ;
int V_38 = 2 ;
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
V_37 += sprintf ( V_37 , L_14
L_15 ,
F_15 ( V_36 , 0 ) ,
F_15 ( V_36 , 4 ) ,
F_15 ( V_36 , 8 ) ,
F_15 ( V_36 , 12 ) ,
F_15 ( V_36 , 16 ) ,
F_15 ( V_36 , 20 ) ,
F_15 ( V_36 , 24 ) ,
F_15 ( V_36 , 28 ) ) ;
}
return V_37 - V_5 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_39 ;
char * V_37 = V_5 ;
int V_40 = 0 ;
#define F_17 ( T_4 ) \
(*(u32 *)((u8 *)pm8001_ha-> \
memoryMap.region[IB].virt_ptr + \
pm8001_ha->evtlog_ib_offset + (c)))
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
V_37 += sprintf ( V_37 , L_16 , F_17 ( V_40 ) ) ;
V_40 = V_40 + 4 ;
}
V_11 -> V_42 += V_43 ;
if ( ( ( V_11 -> V_42 ) % ( V_44 ) ) == 0 )
V_11 -> V_42 = 0 ;
return V_37 - V_5 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_39 ;
char * V_37 = V_5 ;
int V_40 = 0 ;
#define F_19 ( T_4 ) \
(*(u32 *)((u8 *)pm8001_ha-> \
memoryMap.region[OB].virt_ptr + \
pm8001_ha->evtlog_ob_offset + (c)))
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
V_37 += sprintf ( V_37 , L_16 , F_19 ( V_40 ) ) ;
V_40 = V_40 + 4 ;
}
V_11 -> V_45 += V_43 ;
if ( ( ( V_11 -> V_45 ) % ( V_44 ) ) == 0 )
V_11 -> V_45 = 0 ;
return V_37 - V_5 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
char * V_37 = V_5 ;
void * V_46 ;
int V_47 ;
F_21 ( V_48 ) ;
struct V_49 V_50 ;
V_11 -> V_51 = & V_48 ;
V_50 . V_52 = 7 ;
V_50 . V_39 = 0 ;
V_50 . V_53 = 4096 ;
V_50 . V_54 = F_22 ( 4096 , V_55 ) ;
if ( ! V_50 . V_54 )
return - V_56 ;
if ( V_57 -> V_58 ( V_11 , & V_50 ) ) {
F_23 ( V_50 . V_54 ) ;
return - V_56 ;
}
F_24 ( & V_48 ) ;
V_46 = V_11 -> V_59 . V_60 [ V_61 ] . V_62 ;
for ( V_47 = V_63 ; V_47 < V_64 ;
V_47 ++ )
V_37 += sprintf ( V_37 , L_17 ,
* ( ( V_20 * ) ( ( V_20 * ) V_46 + V_47 ) ) ) ;
F_23 ( V_50 . V_54 ) ;
return V_37 - V_5 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
#define F_26 ( T_3 , T_4 ) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[IOP].virt_ptr + (r) * 32 \
+ (c)))
int V_36 ;
char * V_37 = V_5 ;
int V_38 = 2 ;
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
V_37 += sprintf ( V_37 , L_14
L_15 ,
F_26 ( V_36 , 0 ) ,
F_26 ( V_36 , 4 ) ,
F_26 ( V_36 , 8 ) ,
F_26 ( V_36 , 12 ) ,
F_26 ( V_36 , 16 ) ,
F_26 ( V_36 , 20 ) ,
F_26 ( V_36 , 24 ) ,
F_26 ( V_36 , 28 ) ) ;
}
return V_37 - V_5 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_33 ;
V_33 = F_28 ( V_2 , V_4 , V_5 ) ;
return V_33 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_33 ;
V_33 = F_30 ( V_2 , V_43 , V_5 ) ;
return V_33 ;
}
static int F_31 ( struct V_10 * V_11 )
{
struct V_49 * V_50 ;
F_21 ( V_48 ) ;
V_20 * V_65 ;
T_5 V_66 ;
T_5 V_53 = 1024 * 5 + sizeof( * V_50 ) - 1 ;
if ( V_11 -> V_67 -> V_68 > 4096 ) {
V_11 -> V_69 = V_70 ;
return - V_71 ;
}
V_65 = F_22 ( V_53 , V_55 ) ;
if ( ! V_65 ) {
V_11 -> V_69 = V_72 ;
return - V_56 ;
}
V_50 = (struct V_49 * ) V_65 ;
memcpy ( ( V_20 * ) & V_50 -> V_54 , ( V_20 * ) V_11 -> V_67 -> V_73 ,
V_11 -> V_67 -> V_68 ) ;
V_50 -> V_53 = V_11 -> V_67 -> V_68 ;
V_50 -> V_74 = 0 ;
V_50 -> V_52 = 0x1 ;
V_11 -> V_51 = & V_48 ;
V_66 = V_57 -> V_75 ( V_11 , V_50 ) ;
if ( V_66 ) {
V_11 -> V_69 = V_72 ;
goto V_76;
}
F_24 ( & V_48 ) ;
V_76:
F_23 ( V_65 ) ;
return V_66 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_49 * V_50 ;
F_21 ( V_48 ) ;
V_20 * V_65 ;
struct V_77 * V_78 ;
T_5 V_79 , V_80 ;
T_5 V_81 , V_82 ;
struct V_83 * V_84 ;
T_5 V_85 = 0 ;
T_5 V_66 = 0 ;
T_5 V_53 = 1024 * 16 + sizeof( * V_50 ) - 1 ;
if ( V_11 -> V_67 -> V_68 < 28 ) {
V_11 -> V_69 = V_70 ;
return - V_71 ;
}
V_65 = F_22 ( V_53 , V_55 ) ;
if ( ! V_65 ) {
V_11 -> V_69 = V_72 ;
return - V_56 ;
}
V_84 = (struct V_83 * ) V_11 -> V_67 -> V_73 ;
while ( V_85 < V_11 -> V_67 -> V_68 ) {
V_80 =
* ( T_5 * ) ( ( V_20 * ) & V_84 -> V_86 + V_85 ) ;
V_79 = F_33 ( V_80 ) ;
V_82 = F_34 ( V_79 + V_87 ,
V_88 ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_50 = (struct V_49 * ) V_65 ;
V_50 -> V_53 = 1024 * 16 ;
V_50 -> V_74 = 0 ;
V_78 =
(struct V_77 * ) & V_50 -> V_54 ;
V_78 -> V_26 = V_88 ;
V_78 -> V_68 = V_79 + V_87 ;
V_78 -> V_89 = 0 ;
V_78 -> V_39 = V_81 * V_88 ;
if ( ( ( V_82 - V_81 ) == 1 ) &&
( ( V_79 + V_87 ) % V_88 ) ) {
V_78 -> V_26 =
( V_79 + V_87 ) % V_88 ;
memcpy ( ( V_20 * ) V_78 -> V_90 ,
( V_20 * ) V_11 -> V_67 -> V_73 + V_85 ,
( V_79 + V_87 ) % V_88 ) ;
V_85 +=
( V_79 + V_87 ) % V_88 ;
} else {
memcpy ( ( V_20 * ) V_78 -> V_90 ,
( V_20 * ) V_11 -> V_67 -> V_73 + V_85 ,
V_88 ) ;
V_85 += V_88 ;
}
V_11 -> V_51 = & V_48 ;
V_66 = V_57 -> V_91 ( V_11 , V_50 ) ;
if ( V_66 ) {
V_11 -> V_69 = V_72 ;
goto V_76;
}
F_24 ( & V_48 ) ;
if ( V_78 -> V_89 > V_92 ) {
V_11 -> V_69 = V_78 -> V_89 ;
V_66 = - V_71 ;
goto V_76;
}
}
}
V_76:
F_23 ( V_65 ) ;
return V_66 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
char * V_93 , * V_94 ;
int V_95 , V_36 ;
int V_96 = V_97 ;
int V_66 ;
if ( ! F_36 ( V_98 ) )
return - V_99 ;
if ( V_11 -> V_69 == V_100 )
return - V_101 ;
V_11 -> V_69 = V_100 ;
V_93 = F_22 ( V_33 * 2 , V_55 ) ;
if ( ! V_93 ) {
V_11 -> V_69 = V_72 ;
return - V_56 ;
}
V_94 = V_93 + V_33 ;
V_95 = sscanf ( V_5 , L_18 , V_93 , V_94 ) ;
if ( V_95 != 2 ) {
V_11 -> V_69 = V_102 ;
V_66 = - V_35 ;
goto V_76;
}
for ( V_36 = 0 ; V_103 [ V_36 ] . V_104 != V_97 ; V_36 ++ ) {
if ( ! memcmp ( V_103 [ V_36 ] . V_105 ,
V_93 , strlen ( V_93 ) ) ) {
V_96 = V_103 [ V_36 ] . V_104 ;
break;
}
}
if ( V_96 == V_97 ) {
V_11 -> V_69 = V_102 ;
V_66 = - V_35 ;
goto V_76;
}
V_66 = F_37 ( & V_11 -> V_67 ,
V_94 ,
V_11 -> V_106 ) ;
if ( V_66 ) {
F_38 ( V_11 ,
F_39 (
L_19 ,
V_94 , V_66 ) ) ;
V_11 -> V_69 = V_107 ;
goto V_76;
}
if ( V_108 == V_96 )
V_66 = F_32 ( V_11 ) ;
else
V_66 = F_31 ( V_11 ) ;
F_40 ( V_11 -> V_67 ) ;
V_76:
F_23 ( V_93 ) ;
if ( V_66 )
return V_66 ;
V_11 -> V_69 = V_109 ;
return V_33 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_36 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
for ( V_36 = 0 ; V_110 [ V_36 ] . V_111 != 0 ; V_36 ++ ) {
if ( V_110 [ V_36 ] . V_111 == V_11 -> V_69 )
break;
}
if ( V_11 -> V_69 != V_100 )
V_11 -> V_69 = V_109 ;
return snprintf ( V_5 , V_15 , L_20 ,
V_110 [ V_36 ] . V_111 ,
V_110 [ V_36 ] . V_112 ) ;
}
