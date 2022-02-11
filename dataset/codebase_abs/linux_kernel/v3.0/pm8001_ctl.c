static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 . V_15 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_2 ,
( V_16 ) ( V_11 -> V_14 . V_17 >> 24 ) ,
( V_16 ) ( V_11 -> V_14 . V_17 >> 16 ) ,
( V_16 ) ( V_11 -> V_14 . V_17 >> 8 ) ,
( V_16 ) ( V_11 -> V_14 . V_17 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 . V_18 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_3 ,
( V_19 ) ( V_11 -> V_14 . V_20 >> 16 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_3 ,
V_11 -> V_14 . V_20 & 0x0000FFFF ) ;
}
static T_1
F_8 ( unsigned int V_21 , char * V_5 )
{
T_1 V_22 = 0 ;
if ( V_21 & V_23 )
V_22 = sprintf ( V_5 , L_4 , L_5 ) ;
if ( V_21 & V_24 )
V_22 += sprintf ( V_5 + V_22 , L_6 , V_22 ? L_7 : L_8 , L_9 ) ;
V_22 += sprintf ( V_5 + V_22 , L_10 ) ;
return V_22 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned int V_21 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_21 = ( V_11 -> V_14 . V_25 & 0xfe000000 ) >> 25 ;
return F_8 ( V_21 , V_5 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_11 ,
F_11 ( * ( V_26 * ) V_11 -> V_27 ) ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
return snprintf ( V_5 , V_13 , L_12 , V_11 -> V_28 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_30 = 0 ;
if ( sscanf ( V_5 , L_13 , & V_30 ) != 1 )
return - V_31 ;
V_11 -> V_28 = V_30 ;
return strlen ( V_5 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_32 ;
#define F_15 ( T_3 , T_4 ) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[AAP1].virt_ptr + (r) * 32 \
+ (c)))
char * V_33 = V_5 ;
int V_34 = 2 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_33 += sprintf ( V_33 , L_14
L_15 ,
F_15 ( V_32 , 0 ) ,
F_15 ( V_32 , 4 ) ,
F_15 ( V_32 , 8 ) ,
F_15 ( V_32 , 12 ) ,
F_15 ( V_32 , 16 ) ,
F_15 ( V_32 , 20 ) ,
F_15 ( V_32 , 24 ) ,
F_15 ( V_32 , 28 ) ) ;
}
return V_33 - V_5 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
#define F_17 ( T_3 , T_4 ) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[IOP].virt_ptr + (r) * 32 \
+ (c)))
int V_32 ;
char * V_33 = V_5 ;
int V_34 = 2 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
V_33 += sprintf ( V_33 , L_14
L_15 ,
F_17 ( V_32 , 0 ) ,
F_17 ( V_32 , 4 ) ,
F_17 ( V_32 , 8 ) ,
F_17 ( V_32 , 12 ) ,
F_17 ( V_32 , 16 ) ,
F_17 ( V_32 , 20 ) ,
F_17 ( V_32 , 24 ) ,
F_17 ( V_32 , 28 ) ) ;
}
return V_33 - V_5 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_35 * V_36 ;
F_19 ( V_37 ) ;
V_16 * V_38 = NULL ;
T_5 V_39 = 0 ;
T_5 V_40 = 0 ;
V_39 = 1024 * 5 + sizeof( * V_36 ) - 1 ;
V_38 = F_20 ( V_39 , V_41 ) ;
if ( ! V_38 )
return - V_42 ;
if ( ( V_11 -> V_43 -> V_44 <= 0 ) ||
( V_11 -> V_43 -> V_44 > 4096 ) ) {
V_40 = V_45 ;
goto V_46;
}
V_36 = (struct V_35 * ) V_38 ;
memcpy ( ( V_16 * ) V_36 -> V_47 , ( V_16 * ) V_11 -> V_43 -> V_48 ,
V_11 -> V_43 -> V_44 ) ;
V_36 -> V_39 = V_11 -> V_43 -> V_44 ;
V_36 -> V_49 = 0 ;
V_11 -> V_50 = & V_37 ;
V_40 = V_51 -> V_52 ( V_11 , V_36 ) ;
F_21 ( & V_37 ) ;
V_46:
F_22 ( V_38 ) ;
return V_40 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_35 * V_36 ;
F_19 ( V_37 ) ;
V_16 * V_38 = NULL ;
T_5 V_39 = 0 ;
struct V_53 * V_54 ;
T_5 V_55 , V_56 = 0 ;
T_5 V_57 = 0 ;
T_5 V_58 , V_59 ;
T_5 V_40 = 0 ;
T_5 V_60 = 0 ;
struct V_61 * V_62 ;
V_39 = 1024 * 16 + sizeof( * V_36 ) - 1 ;
V_38 = F_20 ( V_39 , V_41 ) ;
V_62 = (struct V_61 * ) V_11 -> V_43 -> V_48 ;
if ( ! V_38 )
return - V_42 ;
if ( V_11 -> V_43 -> V_44 < 28 ) {
V_40 = V_45 ;
goto V_46;
}
while ( V_57 < V_11 -> V_43 -> V_44 ) {
V_59 =
* ( T_5 * ) ( ( V_16 * ) & V_62 -> V_63 + V_57 ) ;
V_58 = F_24 ( V_59 ) ;
V_56 = ( V_58 + V_64 ) / V_65 ;
if ( V_56 % V_65 )
V_56 ++ ;
if ( V_56 == 0 )
V_56 ++ ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
V_36 = (struct V_35 * ) V_38 ;
V_36 -> V_39 = 1024 * 16 ;
V_36 -> V_49 = 0 ;
V_54 =
(struct V_53 * ) V_36 -> V_47 ;
V_54 -> V_22 = V_65 ;
V_54 -> V_44 = V_58 + V_64 ;
V_54 -> V_66 = 0 ;
V_54 -> V_67 = V_55 * V_65 ;
if ( ( ( V_56 - V_55 ) == 1 ) &&
( ( V_58 + V_64 ) % V_65 ) ) {
V_54 -> V_22 =
( V_58 + V_64 ) % V_65 ;
memcpy ( ( V_16 * ) V_54 -> V_68 ,
( V_16 * ) V_11 -> V_43 -> V_48 + V_57 ,
( V_58 + V_64 ) % V_65 ) ;
V_57 +=
( V_58 + V_64 ) % V_65 ;
} else {
memcpy ( ( V_16 * ) V_54 -> V_68 ,
( V_16 * ) V_11 -> V_43 -> V_48 + V_57 ,
V_65 ) ;
V_57 += V_65 ;
}
V_11 -> V_50 = & V_37 ;
V_40 = V_51 -> V_69 ( V_11 , V_36 ) ;
F_21 ( & V_37 ) ;
if ( V_40 || ( V_54 -> V_66 > V_70 ) ) {
V_40 = V_54 -> V_66 ;
F_22 ( V_38 ) ;
V_38 = NULL ;
break;
}
}
if ( V_40 )
break;
V_60 ++ ;
}
V_46:
F_22 ( V_38 ) ;
return V_40 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
char * V_71 , * V_72 ;
int V_73 , V_32 ;
int V_74 = V_75 ;
int V_76 = 0 ;
if ( ! F_26 ( V_77 ) )
return - V_78 ;
V_71 = F_20 ( V_29 * 2 , V_41 ) ;
if ( ! V_71 ) {
V_76 = V_79 ;
goto V_46;
}
V_72 = V_71 + V_29 ;
V_73 = sscanf ( V_5 , L_16 , V_71 , V_72 ) ;
if ( V_73 != 2 ) {
V_76 = V_80 ;
goto V_81;
}
for ( V_32 = 0 ; V_82 [ V_32 ] . V_83 != V_75 ; V_32 ++ ) {
if ( ! memcmp ( V_82 [ V_32 ] . V_84 ,
V_71 , strlen ( V_71 ) ) ) {
V_74 = V_82 [ V_32 ] . V_83 ;
break;
}
}
if ( V_74 == V_75 ) {
V_76 = V_80 ;
goto V_81;
}
if ( V_11 -> V_85 == V_86 ) {
V_76 = V_86 ;
goto V_81;
}
V_76 = F_27 ( & V_11 -> V_43 ,
V_72 ,
V_11 -> V_87 ) ;
if ( V_76 ) {
F_28 ( V_11 ,
F_29 ( L_17
L_18 , V_72 , V_76 ) ) ;
V_76 = V_88 ;
goto V_81;
}
switch ( V_74 ) {
case V_89 :
V_11 -> V_85 = V_86 ;
V_76 = F_23 ( V_11 ) ;
break;
case V_90 :
V_11 -> V_85 = V_86 ;
V_76 = F_18 ( V_11 ) ;
break;
default:
V_11 -> V_85 = V_80 ;
V_76 = V_80 ;
break;
}
F_30 ( V_11 -> V_43 ) ;
V_81:
F_22 ( V_71 ) ;
V_46:
V_11 -> V_85 = V_76 ;
if ( ! V_76 )
return V_29 ;
else
return - V_76 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_32 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
for ( V_32 = 0 ; V_91 [ V_32 ] . V_92 != 0 ; V_32 ++ ) {
if ( V_91 [ V_32 ] . V_92 == V_11 -> V_85 )
break;
}
if ( V_11 -> V_85 != V_86 )
V_11 -> V_85 = V_93 ;
return snprintf ( V_5 , V_13 , L_19 ,
V_91 [ V_32 ] . V_92 ,
V_91 [ V_32 ] . V_94 ) ;
}
