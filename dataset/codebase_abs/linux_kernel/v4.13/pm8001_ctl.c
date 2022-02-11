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
int V_46 ;
F_21 ( V_47 ) ;
struct V_48 V_49 ;
V_11 -> V_50 = & V_47 ;
V_49 . V_51 = 7 ;
V_49 . V_39 = 0 ;
V_49 . V_52 = 4096 ;
V_49 . V_53 = F_22 ( 4096 , V_54 ) ;
if ( ! V_49 . V_53 )
return - V_55 ;
if ( V_56 -> V_57 ( V_11 , & V_49 ) ) {
F_23 ( V_49 . V_53 ) ;
return - V_55 ;
}
F_24 ( & V_47 ) ;
for ( V_46 = V_58 ; V_46 < V_59 ;
V_46 ++ )
V_37 += sprintf ( V_37 , L_17 ,
* ( V_49 . V_53 + V_46 ) ) ;
F_23 ( V_49 . V_53 ) ;
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
struct V_48 * V_49 ;
F_21 ( V_47 ) ;
V_20 * V_60 ;
T_5 V_61 ;
T_5 V_52 = 1024 * 5 + sizeof( * V_49 ) - 1 ;
if ( V_11 -> V_62 -> V_63 > 4096 ) {
V_11 -> V_64 = V_65 ;
return - V_66 ;
}
V_60 = F_22 ( V_52 , V_54 ) ;
if ( ! V_60 ) {
V_11 -> V_64 = V_67 ;
return - V_55 ;
}
V_49 = (struct V_48 * ) V_60 ;
memcpy ( ( V_20 * ) & V_49 -> V_53 , ( V_20 * ) V_11 -> V_62 -> V_68 ,
V_11 -> V_62 -> V_63 ) ;
V_49 -> V_52 = V_11 -> V_62 -> V_63 ;
V_49 -> V_69 = 0 ;
V_49 -> V_51 = 0x1 ;
V_11 -> V_50 = & V_47 ;
V_61 = V_56 -> V_70 ( V_11 , V_49 ) ;
if ( V_61 ) {
V_11 -> V_64 = V_67 ;
goto V_71;
}
F_24 ( & V_47 ) ;
V_71:
F_23 ( V_60 ) ;
return V_61 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_48 * V_49 ;
F_21 ( V_47 ) ;
V_20 * V_60 ;
struct V_72 * V_73 ;
T_5 V_74 , V_75 ;
T_5 V_76 , V_77 ;
struct V_78 * V_79 ;
T_5 V_80 = 0 ;
T_5 V_61 = 0 ;
T_5 V_52 = 1024 * 16 + sizeof( * V_49 ) - 1 ;
if ( V_11 -> V_62 -> V_63 < 28 ) {
V_11 -> V_64 = V_65 ;
return - V_66 ;
}
V_60 = F_22 ( V_52 , V_54 ) ;
if ( ! V_60 ) {
V_11 -> V_64 = V_67 ;
return - V_55 ;
}
V_79 = (struct V_78 * ) V_11 -> V_62 -> V_68 ;
while ( V_80 < V_11 -> V_62 -> V_63 ) {
V_75 =
* ( T_5 * ) ( ( V_20 * ) & V_79 -> V_81 + V_80 ) ;
V_74 = F_33 ( V_75 ) ;
V_77 = F_34 ( V_74 + V_82 ,
V_83 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
V_49 = (struct V_48 * ) V_60 ;
V_49 -> V_52 = 1024 * 16 ;
V_49 -> V_69 = 0 ;
V_73 =
(struct V_72 * ) & V_49 -> V_53 ;
V_73 -> V_26 = V_83 ;
V_73 -> V_63 = V_74 + V_82 ;
V_73 -> V_84 = 0 ;
V_73 -> V_39 = V_76 * V_83 ;
if ( ( ( V_77 - V_76 ) == 1 ) &&
( ( V_74 + V_82 ) % V_83 ) ) {
V_73 -> V_26 =
( V_74 + V_82 ) % V_83 ;
memcpy ( ( V_20 * ) V_73 -> V_85 ,
( V_20 * ) V_11 -> V_62 -> V_68 + V_80 ,
( V_74 + V_82 ) % V_83 ) ;
V_80 +=
( V_74 + V_82 ) % V_83 ;
} else {
memcpy ( ( V_20 * ) V_73 -> V_85 ,
( V_20 * ) V_11 -> V_62 -> V_68 + V_80 ,
V_83 ) ;
V_80 += V_83 ;
}
V_11 -> V_50 = & V_47 ;
V_61 = V_56 -> V_86 ( V_11 , V_49 ) ;
if ( V_61 ) {
V_11 -> V_64 = V_67 ;
goto V_71;
}
F_24 ( & V_47 ) ;
if ( V_73 -> V_84 > V_87 ) {
V_11 -> V_64 = V_73 -> V_84 ;
V_61 = - V_66 ;
goto V_71;
}
}
}
V_71:
F_23 ( V_60 ) ;
return V_61 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
char * V_88 , * V_89 ;
int V_90 , V_36 ;
int V_91 = V_92 ;
int V_61 ;
if ( ! F_36 ( V_93 ) )
return - V_94 ;
if ( V_11 -> V_64 == V_95 )
return - V_96 ;
V_11 -> V_64 = V_95 ;
V_88 = F_22 ( V_33 * 2 , V_54 ) ;
if ( ! V_88 ) {
V_11 -> V_64 = V_67 ;
return - V_55 ;
}
V_89 = V_88 + V_33 ;
V_90 = sscanf ( V_5 , L_18 , V_88 , V_89 ) ;
if ( V_90 != 2 ) {
V_11 -> V_64 = V_97 ;
V_61 = - V_35 ;
goto V_71;
}
for ( V_36 = 0 ; V_98 [ V_36 ] . V_99 != V_92 ; V_36 ++ ) {
if ( ! memcmp ( V_98 [ V_36 ] . V_100 ,
V_88 , strlen ( V_88 ) ) ) {
V_91 = V_98 [ V_36 ] . V_99 ;
break;
}
}
if ( V_91 == V_92 ) {
V_11 -> V_64 = V_97 ;
V_61 = - V_35 ;
goto V_71;
}
V_61 = F_37 ( & V_11 -> V_62 ,
V_89 ,
V_11 -> V_101 ) ;
if ( V_61 ) {
F_38 ( V_11 ,
F_39 (
L_19 ,
V_89 , V_61 ) ) ;
V_11 -> V_64 = V_102 ;
goto V_71;
}
if ( V_103 == V_91 )
V_61 = F_32 ( V_11 ) ;
else
V_61 = F_31 ( V_11 ) ;
F_40 ( V_11 -> V_62 ) ;
V_71:
F_23 ( V_88 ) ;
if ( V_61 )
return V_61 ;
V_11 -> V_64 = V_104 ;
return V_33 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_36 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
for ( V_36 = 0 ; V_105 [ V_36 ] . V_106 != 0 ; V_36 ++ ) {
if ( V_105 [ V_36 ] . V_106 == V_11 -> V_64 )
break;
}
if ( V_11 -> V_64 != V_95 )
V_11 -> V_64 = V_104 ;
return snprintf ( V_5 , V_15 , L_20 ,
V_105 [ V_36 ] . V_106 ,
V_105 [ V_36 ] . V_107 ) ;
}
