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
#define F_17 ( T_3 , T_4 ) \
(*(u32 *)((u8*)pm8001_ha->memoryMap.region[IOP].virt_ptr + (r) * 32 \
+ (c)))
int V_36 ;
char * V_37 = V_5 ;
int V_38 = 2 ;
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ ) {
V_37 += sprintf ( V_37 , L_14
L_15 ,
F_17 ( V_36 , 0 ) ,
F_17 ( V_36 , 4 ) ,
F_17 ( V_36 , 8 ) ,
F_17 ( V_36 , 12 ) ,
F_17 ( V_36 , 16 ) ,
F_17 ( V_36 , 20 ) ,
F_17 ( V_36 , 24 ) ,
F_17 ( V_36 , 28 ) ) ;
}
return V_37 - V_5 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_39 * V_40 ;
F_19 ( V_41 ) ;
V_20 * V_42 = NULL ;
T_5 V_43 = 0 ;
T_5 V_44 = 0 ;
V_43 = 1024 * 5 + sizeof( * V_40 ) - 1 ;
V_42 = F_20 ( V_43 , V_45 ) ;
if ( ! V_42 )
return - V_46 ;
if ( ( V_11 -> V_47 -> V_48 <= 0 ) ||
( V_11 -> V_47 -> V_48 > 4096 ) ) {
V_44 = V_49 ;
goto V_50;
}
V_40 = (struct V_39 * ) V_42 ;
memcpy ( ( V_20 * ) & V_40 -> V_51 , ( V_20 * ) V_11 -> V_47 -> V_52 ,
V_11 -> V_47 -> V_48 ) ;
V_40 -> V_43 = V_11 -> V_47 -> V_48 ;
V_40 -> V_53 = 0 ;
V_40 -> V_54 = 0x1 ;
V_11 -> V_55 = & V_41 ;
V_44 = V_56 -> V_57 ( V_11 , V_40 ) ;
F_21 ( & V_41 ) ;
V_50:
F_22 ( V_42 ) ;
return V_44 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_39 * V_40 ;
F_19 ( V_41 ) ;
V_20 * V_42 = NULL ;
T_5 V_43 = 0 ;
struct V_58 * V_59 ;
T_5 V_60 , V_61 = 0 ;
T_5 V_62 = 0 ;
T_5 V_63 , V_64 ;
T_5 V_44 = 0 ;
T_5 V_65 = 0 ;
struct V_66 * V_67 ;
V_43 = 1024 * 16 + sizeof( * V_40 ) - 1 ;
V_42 = F_20 ( V_43 , V_45 ) ;
V_67 = (struct V_66 * ) V_11 -> V_47 -> V_52 ;
if ( ! V_42 )
return - V_46 ;
if ( V_11 -> V_47 -> V_48 < 28 ) {
V_44 = V_49 ;
goto V_50;
}
while ( V_62 < V_11 -> V_47 -> V_48 ) {
V_64 =
* ( T_5 * ) ( ( V_20 * ) & V_67 -> V_68 + V_62 ) ;
V_63 = F_24 ( V_64 ) ;
V_61 = ( V_63 + V_69 ) / V_70 ;
if ( V_61 % V_70 )
V_61 ++ ;
if ( V_61 == 0 )
V_61 ++ ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
V_40 = (struct V_39 * ) V_42 ;
V_40 -> V_43 = 1024 * 16 ;
V_40 -> V_53 = 0 ;
V_59 =
(struct V_58 * ) & V_40 -> V_51 ;
V_59 -> V_26 = V_70 ;
V_59 -> V_48 = V_63 + V_69 ;
V_59 -> V_71 = 0 ;
V_59 -> V_72 = V_60 * V_70 ;
if ( ( ( V_61 - V_60 ) == 1 ) &&
( ( V_63 + V_69 ) % V_70 ) ) {
V_59 -> V_26 =
( V_63 + V_69 ) % V_70 ;
memcpy ( ( V_20 * ) V_59 -> V_73 ,
( V_20 * ) V_11 -> V_47 -> V_52 + V_62 ,
( V_63 + V_69 ) % V_70 ) ;
V_62 +=
( V_63 + V_69 ) % V_70 ;
} else {
memcpy ( ( V_20 * ) V_59 -> V_73 ,
( V_20 * ) V_11 -> V_47 -> V_52 + V_62 ,
V_70 ) ;
V_62 += V_70 ;
}
V_11 -> V_55 = & V_41 ;
V_44 = V_56 -> V_74 ( V_11 , V_40 ) ;
F_21 ( & V_41 ) ;
if ( V_44 || ( V_59 -> V_71 > V_75 ) ) {
V_44 = V_59 -> V_71 ;
F_22 ( V_42 ) ;
V_42 = NULL ;
break;
}
}
if ( V_44 )
break;
V_65 ++ ;
}
V_50:
F_22 ( V_42 ) ;
return V_44 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_33 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
char * V_76 , * V_77 ;
int V_78 , V_36 ;
int V_79 = V_80 ;
int V_81 = 0 ;
if ( ! F_26 ( V_82 ) )
return - V_83 ;
V_76 = F_20 ( V_33 * 2 , V_45 ) ;
if ( ! V_76 ) {
V_81 = V_84 ;
goto V_50;
}
V_77 = V_76 + V_33 ;
V_78 = sscanf ( V_5 , L_16 , V_76 , V_77 ) ;
if ( V_78 != 2 ) {
V_81 = V_85 ;
goto V_86;
}
for ( V_36 = 0 ; V_87 [ V_36 ] . V_88 != V_80 ; V_36 ++ ) {
if ( ! memcmp ( V_87 [ V_36 ] . V_89 ,
V_76 , strlen ( V_76 ) ) ) {
V_79 = V_87 [ V_36 ] . V_88 ;
break;
}
}
if ( V_79 == V_80 ) {
V_81 = V_85 ;
goto V_86;
}
if ( V_11 -> V_90 == V_91 ) {
V_81 = V_91 ;
goto V_86;
}
V_81 = F_27 ( & V_11 -> V_47 ,
V_77 ,
V_11 -> V_92 ) ;
if ( V_81 ) {
F_28 ( V_11 ,
F_29 ( L_17
L_18 , V_77 , V_81 ) ) ;
V_81 = V_93 ;
goto V_86;
}
switch ( V_79 ) {
case V_94 :
V_11 -> V_90 = V_91 ;
V_81 = F_23 ( V_11 ) ;
break;
case V_95 :
V_11 -> V_90 = V_91 ;
V_81 = F_18 ( V_11 ) ;
break;
default:
V_11 -> V_90 = V_85 ;
V_81 = V_85 ;
break;
}
F_30 ( V_11 -> V_47 ) ;
V_86:
F_22 ( V_76 ) ;
V_50:
V_11 -> V_90 = V_81 ;
if ( ! V_81 )
return V_33 ;
else
return - V_81 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_36 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
for ( V_36 = 0 ; V_96 [ V_36 ] . V_97 != 0 ; V_36 ++ ) {
if ( V_96 [ V_36 ] . V_97 == V_11 -> V_90 )
break;
}
if ( V_11 -> V_90 != V_91 )
V_11 -> V_90 = V_98 ;
return snprintf ( V_5 , V_15 , L_19 ,
V_96 [ V_36 ] . V_97 ,
V_96 [ V_36 ] . V_99 ) ;
}
