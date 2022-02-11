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
V_56 -> V_57 ( V_11 , & V_50 ) ;
F_23 ( & V_48 ) ;
V_46 = V_11 -> V_58 . V_59 [ V_60 ] . V_61 ;
for ( V_47 = V_62 ; V_47 < V_63 ;
V_47 ++ )
V_37 += sprintf ( V_37 , L_17 ,
* ( ( V_20 * ) ( ( V_20 * ) V_46 + V_47 ) ) ) ;
return V_37 - V_5 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
#define F_25 ( T_3 , T_4 ) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[IOP].virt_ptr + (r) * 32 \
+ (c)))
int V_36 ;
char * V_37 = V_5 ;
int V_38 = 2 ;
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
V_37 += sprintf ( V_37 , L_14
L_15 ,
F_25 ( V_36 , 0 ) ,
F_25 ( V_36 , 4 ) ,
F_25 ( V_36 , 8 ) ,
F_25 ( V_36 , 12 ) ,
F_25 ( V_36 , 16 ) ,
F_25 ( V_36 , 20 ) ,
F_25 ( V_36 , 24 ) ,
F_25 ( V_36 , 28 ) ) ;
}
return V_37 - V_5 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_33 ;
V_33 = F_27 ( V_2 , V_4 , V_5 ) ;
return V_33 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_33 ;
V_33 = F_29 ( V_2 , V_43 , V_5 ) ;
return V_33 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_49 * V_50 ;
F_21 ( V_48 ) ;
V_20 * V_64 = NULL ;
T_5 V_53 = 0 ;
T_5 V_65 = 0 ;
V_53 = 1024 * 5 + sizeof( * V_50 ) - 1 ;
V_64 = F_22 ( V_53 , V_55 ) ;
if ( ! V_64 )
return - V_66 ;
if ( ( V_11 -> V_67 -> V_68 <= 0 ) ||
( V_11 -> V_67 -> V_68 > 4096 ) ) {
V_65 = V_69 ;
goto V_70;
}
V_50 = (struct V_49 * ) V_64 ;
memcpy ( ( V_20 * ) & V_50 -> V_54 , ( V_20 * ) V_11 -> V_67 -> V_71 ,
V_11 -> V_67 -> V_68 ) ;
V_50 -> V_53 = V_11 -> V_67 -> V_68 ;
V_50 -> V_72 = 0 ;
V_50 -> V_52 = 0x1 ;
V_11 -> V_51 = & V_48 ;
V_65 = V_56 -> V_73 ( V_11 , V_50 ) ;
F_23 ( & V_48 ) ;
V_70:
F_31 ( V_64 ) ;
return V_65 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_49 * V_50 ;
F_21 ( V_48 ) ;
V_20 * V_64 = NULL ;
T_5 V_53 = 0 ;
struct V_74 * V_75 ;
T_5 V_76 , V_77 = 0 ;
T_5 V_78 = 0 ;
T_5 V_79 , V_80 ;
T_5 V_65 = 0 ;
T_5 V_81 = 0 ;
struct V_82 * V_83 ;
V_53 = 1024 * 16 + sizeof( * V_50 ) - 1 ;
V_64 = F_22 ( V_53 , V_55 ) ;
V_83 = (struct V_82 * ) V_11 -> V_67 -> V_71 ;
if ( ! V_64 )
return - V_66 ;
if ( V_11 -> V_67 -> V_68 < 28 ) {
V_65 = V_69 ;
goto V_70;
}
while ( V_78 < V_11 -> V_67 -> V_68 ) {
V_80 =
* ( T_5 * ) ( ( V_20 * ) & V_83 -> V_84 + V_78 ) ;
V_79 = F_33 ( V_80 ) ;
V_77 = ( V_79 + V_85 ) / V_86 ;
if ( V_77 % V_86 )
V_77 ++ ;
if ( V_77 == 0 )
V_77 ++ ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
V_50 = (struct V_49 * ) V_64 ;
V_50 -> V_53 = 1024 * 16 ;
V_50 -> V_72 = 0 ;
V_75 =
(struct V_74 * ) & V_50 -> V_54 ;
V_75 -> V_26 = V_86 ;
V_75 -> V_68 = V_79 + V_85 ;
V_75 -> V_87 = 0 ;
V_75 -> V_39 = V_76 * V_86 ;
if ( ( ( V_77 - V_76 ) == 1 ) &&
( ( V_79 + V_85 ) % V_86 ) ) {
V_75 -> V_26 =
( V_79 + V_85 ) % V_86 ;
memcpy ( ( V_20 * ) V_75 -> V_88 ,
( V_20 * ) V_11 -> V_67 -> V_71 + V_78 ,
( V_79 + V_85 ) % V_86 ) ;
V_78 +=
( V_79 + V_85 ) % V_86 ;
} else {
memcpy ( ( V_20 * ) V_75 -> V_88 ,
( V_20 * ) V_11 -> V_67 -> V_71 + V_78 ,
V_86 ) ;
V_78 += V_86 ;
}
V_11 -> V_51 = & V_48 ;
V_65 = V_56 -> V_89 ( V_11 , V_50 ) ;
F_23 ( & V_48 ) ;
if ( V_65 || ( V_75 -> V_87 > V_90 ) ) {
V_65 = V_75 -> V_87 ;
F_31 ( V_64 ) ;
V_64 = NULL ;
break;
}
}
if ( V_65 )
break;
V_81 ++ ;
}
V_70:
F_31 ( V_64 ) ;
return V_65 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
char * V_91 , * V_92 ;
int V_93 , V_36 ;
int V_94 = V_95 ;
int V_96 = 0 ;
if ( ! F_35 ( V_97 ) )
return - V_98 ;
V_91 = F_22 ( V_33 * 2 , V_55 ) ;
if ( ! V_91 ) {
V_96 = V_99 ;
goto V_70;
}
V_92 = V_91 + V_33 ;
V_93 = sscanf ( V_5 , L_18 , V_91 , V_92 ) ;
if ( V_93 != 2 ) {
V_96 = V_100 ;
goto V_101;
}
for ( V_36 = 0 ; V_102 [ V_36 ] . V_103 != V_95 ; V_36 ++ ) {
if ( ! memcmp ( V_102 [ V_36 ] . V_104 ,
V_91 , strlen ( V_91 ) ) ) {
V_94 = V_102 [ V_36 ] . V_103 ;
break;
}
}
if ( V_94 == V_95 ) {
V_96 = V_100 ;
goto V_101;
}
if ( V_11 -> V_105 == V_106 ) {
V_96 = V_106 ;
goto V_101;
}
V_96 = F_36 ( & V_11 -> V_67 ,
V_92 ,
V_11 -> V_107 ) ;
if ( V_96 ) {
F_37 ( V_11 ,
F_38 ( L_19
L_20 , V_92 , V_96 ) ) ;
V_96 = V_108 ;
goto V_101;
}
switch ( V_94 ) {
case V_109 :
V_11 -> V_105 = V_106 ;
V_96 = F_32 ( V_11 ) ;
break;
case V_110 :
V_11 -> V_105 = V_106 ;
V_96 = F_30 ( V_11 ) ;
break;
default:
V_11 -> V_105 = V_100 ;
V_96 = V_100 ;
break;
}
F_39 ( V_11 -> V_67 ) ;
V_101:
F_31 ( V_91 ) ;
V_70:
V_11 -> V_105 = V_96 ;
if ( ! V_96 )
return V_33 ;
else
return - V_96 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_36 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
for ( V_36 = 0 ; V_111 [ V_36 ] . V_112 != 0 ; V_36 ++ ) {
if ( V_111 [ V_36 ] . V_112 == V_11 -> V_105 )
break;
}
if ( V_11 -> V_105 != V_106 )
V_11 -> V_105 = V_113 ;
return snprintf ( V_5 , V_15 , L_21 ,
V_111 [ V_36 ] . V_112 ,
V_111 [ V_36 ] . V_114 ) ;
}
