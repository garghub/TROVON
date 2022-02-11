static T_1 F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case 9600 :
return 0x00 ;
case 19200 :
return 0x01 ;
case 38400 :
return 0x02 ;
case 57600 :
return 0x03 ;
case 115200 :
return 0x04 ;
case 230400 :
return 0x05 ;
case 460800 :
return 0x06 ;
case 921600 :
return 0x07 ;
case 1843200 :
return 0x08 ;
case 3250000 :
return 0x09 ;
case 2000000 :
return 0x0a ;
case 3000000 :
return 0x0b ;
default:
return 0xff ;
}
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_7 ;
V_7 = F_3 ( & V_5 -> V_8 , V_9 ,
V_10 ,
F_4 ( 1000 ) ) ;
if ( V_7 == 1 ) {
F_5 ( V_3 -> V_11 , L_1 ) ;
return - V_12 ;
}
if ( V_7 ) {
F_5 ( V_3 -> V_11 , L_2 ) ;
return - V_13 ;
}
return V_7 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_7 ;
V_7 = F_3 ( & V_5 -> V_8 , V_14 ,
V_10 ,
F_4 ( 1000 ) ) ;
if ( V_7 == 1 ) {
F_5 ( V_3 -> V_11 , L_3 ) ;
return - V_12 ;
}
if ( V_7 ) {
F_5 ( V_3 -> V_11 , L_4 ) ;
return - V_13 ;
}
return V_7 ;
}
static int F_7 ( struct V_2 * V_3 )
{
static const T_1 V_15 [] = { 0x01 , 0x01 , 0x01 } ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_16 * V_17 ;
if ( ! F_8 ( V_18 , & V_5 -> V_8 ) ||
F_8 ( V_19 , & V_5 -> V_8 ) )
return 0 ;
if ( F_8 ( V_20 , & V_5 -> V_8 ) )
return - V_21 ;
F_9 ( V_3 -> V_11 , L_5 ) ;
V_17 = F_10 ( sizeof( V_15 ) , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_3 -> V_11 , L_6 ) ;
return - V_23 ;
}
memcpy ( F_11 ( V_17 , sizeof( V_15 ) ) , V_15 , sizeof( V_15 ) ) ;
F_12 ( V_17 ) -> V_24 = V_25 ;
F_13 ( V_14 , & V_5 -> V_8 ) ;
F_14 ( & V_5 -> V_26 , V_17 ) ;
F_15 ( V_3 ) ;
F_6 ( V_3 ) ;
F_16 ( V_14 , & V_5 -> V_8 ) ;
if ( ! F_8 ( V_19 , & V_5 -> V_8 ) ) {
F_5 ( V_3 -> V_11 , L_7 ) ;
return - V_27 ;
}
F_9 ( V_3 -> V_11 , L_8 ) ;
F_17 ( V_3 , true ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_16 * V_17 ;
if ( ! F_8 ( V_18 , & V_5 -> V_8 ) ||
! F_8 ( V_19 , & V_5 -> V_8 ) )
return 0 ;
F_9 ( V_3 -> V_11 , L_9 ) ;
F_17 ( V_3 , false ) ;
V_17 = F_10 ( 0 , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_3 -> V_11 , L_6 ) ;
return - V_23 ;
}
F_12 ( V_17 ) -> V_24 = V_28 ;
F_13 ( V_14 , & V_5 -> V_8 ) ;
F_14 ( & V_5 -> V_26 , V_17 ) ;
F_15 ( V_3 ) ;
F_6 ( V_3 ) ;
F_16 ( V_14 , & V_5 -> V_8 ) ;
if ( F_8 ( V_19 , & V_5 -> V_8 ) ) {
F_5 ( V_3 -> V_11 , L_10 ) ;
return - V_27 ;
}
F_9 ( V_3 -> V_11 , L_11 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
static const T_1 V_29 [] = { V_30 , 0x00 } ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_16 * V_17 ;
F_17 ( V_3 , false ) ;
F_16 ( V_19 , & V_5 -> V_8 ) ;
V_17 = F_10 ( sizeof( V_29 ) , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_3 -> V_11 , L_6 ) ;
return - V_23 ;
}
memcpy ( F_11 ( V_17 , sizeof( V_29 ) ) , V_29 ,
sizeof( V_29 ) ) ;
F_12 ( V_17 ) -> V_24 = V_25 ;
F_14 ( & V_5 -> V_26 , V_17 ) ;
F_15 ( V_3 ) ;
F_9 ( V_3 -> V_11 , L_12 ) ;
return 0 ;
}
static T_2 F_20 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
F_21 ( & V_34 -> V_35 -> V_36 , L_13 ) ;
F_22 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_3 )
F_19 ( V_34 -> V_3 ) ;
F_23 ( & V_34 -> V_37 ) ;
F_24 ( & V_34 -> V_35 -> V_36 ) ;
F_25 ( & V_34 -> V_35 -> V_36 ) ;
F_26 ( & V_34 -> V_35 -> V_36 ) ;
return V_38 ;
}
static int F_27 ( struct V_2 * V_3 , bool V_39 )
{
struct V_40 * V_41 ;
int V_7 = - V_42 ;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_33 * V_34 = F_29 ( V_41 , struct V_33 ,
V_44 ) ;
if ( V_3 -> V_45 -> V_36 -> V_46 != V_34 -> V_35 -> V_36 . V_46 )
continue;
if ( ! V_34 -> V_47 ) {
V_7 = - V_48 ;
break;
}
F_30 ( L_14 ,
V_3 , F_31 ( & V_34 -> V_35 -> V_36 ) , V_39 ) ;
F_32 ( V_34 -> V_47 , V_39 ) ;
F_22 ( & V_34 -> V_37 ) ;
V_34 -> V_3 = V_39 ? V_3 : NULL ;
F_23 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_31 < 0 )
break;
if ( V_39 && F_33 ( & V_34 -> V_35 -> V_36 ) ) {
V_7 = F_34 ( & V_34 -> V_35 -> V_36 ,
V_34 -> V_31 , NULL ,
F_20 ,
V_49 ,
L_15 , V_34 ) ;
if ( V_7 ) {
F_35 ( L_16 ,
V_3 , V_34 -> V_31 ) ;
break;
}
F_36 ( & V_34 -> V_35 -> V_36 ) ;
F_37 ( & V_34 -> V_35 -> V_36 ) ;
F_38 ( & V_34 -> V_35 -> V_36 ) ;
F_39 ( & V_34 -> V_35 -> V_36 ,
V_50 ) ;
F_40 ( & V_34 -> V_35 -> V_36 ) ;
} else if ( ! V_39 && F_41 ( & V_34 -> V_35 -> V_36 ) ) {
F_42 ( & V_34 -> V_35 -> V_36 , V_34 -> V_31 , V_34 ) ;
F_43 ( & V_34 -> V_35 -> V_36 ) ;
F_44 ( & V_34 -> V_35 -> V_36 ) ;
}
}
F_23 ( & V_43 ) ;
return V_7 ;
}
static void F_45 ( struct V_51 * V_52 )
{
struct V_40 * V_41 ;
struct V_4 * V_5 = F_46 ( V_52 , struct V_4 ,
V_53 ) ;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_33 * V_34 = F_29 ( V_41 , struct V_33 ,
V_44 ) ;
if ( V_5 -> V_3 -> V_45 -> V_36 -> V_46 == V_34 -> V_35 -> V_36 . V_46 ) {
F_24 ( & V_34 -> V_35 -> V_36 ) ;
F_25 ( & V_34 -> V_35 -> V_36 ) ;
F_26 ( & V_34 -> V_35 -> V_36 ) ;
break;
}
}
F_23 ( & V_43 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_48 ( L_17 , V_3 ) ;
V_5 = F_49 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return - V_23 ;
F_50 ( & V_5 -> V_26 ) ;
F_51 ( & V_5 -> V_53 , F_45 ) ;
V_5 -> V_3 = V_3 ;
V_3 -> V_6 = V_5 ;
if ( ! F_27 ( V_3 , true ) )
F_13 ( V_9 , & V_5 -> V_8 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_48 ( L_17 , V_3 ) ;
F_53 ( & V_5 -> V_53 ) ;
F_27 ( V_3 , false ) ;
F_54 ( & V_5 -> V_26 ) ;
F_55 ( V_5 -> V_54 ) ;
F_56 ( V_5 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_48 ( L_17 , V_3 ) ;
F_54 ( & V_5 -> V_26 ) ;
return 0 ;
}
static int F_58 ( struct V_55 * V_11 , T_3 V_56 )
{
struct V_16 * V_17 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
V_17 = F_10 ( sizeof( * V_58 ) + sizeof( * V_60 ) + 1 , V_61 ) ;
if ( ! V_17 )
return - V_23 ;
V_58 = (struct V_57 * ) F_11 ( V_17 , sizeof( * V_58 ) ) ;
V_58 -> V_60 = V_62 ;
V_58 -> V_63 = sizeof( * V_60 ) + 1 ;
V_60 = (struct V_59 * ) F_11 ( V_17 , sizeof( * V_60 ) ) ;
V_60 -> V_64 = 0x01 ;
V_60 -> V_56 = F_59 ( V_56 ) ;
* F_11 ( V_17 , 1 ) = 0x00 ;
F_12 ( V_17 ) -> V_24 = V_65 ;
return F_60 ( V_11 , V_17 ) ;
}
static int F_61 ( struct V_2 * V_3 , unsigned int V_1 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_55 * V_11 = V_3 -> V_11 ;
T_1 V_66 [] = { 0x06 , 0xfc , 0x01 , 0x00 } ;
struct V_16 * V_17 ;
int V_7 ;
V_7 = F_2 ( V_3 ) ;
F_16 ( V_9 , & V_5 -> V_8 ) ;
if ( V_7 && V_7 != V_13 )
return V_7 ;
F_62 ( V_11 , L_18 , V_1 ) ;
V_66 [ 3 ] = F_1 ( V_1 ) ;
if ( V_66 [ 3 ] == 0xff ) {
F_5 ( V_11 , L_19 ) ;
return - V_27 ;
}
V_17 = F_63 ( V_11 , 0xfc05 , 0 , NULL , V_67 ) ;
if ( F_64 ( V_17 ) ) {
F_5 ( V_11 , L_20 ,
F_65 ( V_17 ) ) ;
return F_65 ( V_17 ) ;
}
F_55 ( V_17 ) ;
V_17 = F_10 ( sizeof( V_66 ) , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_11 , L_21 ) ;
return - V_23 ;
}
memcpy ( F_11 ( V_17 , sizeof( V_66 ) ) , V_66 , sizeof( V_66 ) ) ;
F_12 ( V_17 ) -> V_24 = V_68 ;
F_17 ( V_3 , true ) ;
F_66 ( & V_5 -> V_26 , V_17 ) ;
F_15 ( V_3 ) ;
F_67 ( 100 ) ;
F_68 ( V_3 , V_1 ) ;
F_17 ( V_3 , false ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
static const T_1 V_69 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
static const T_1 V_70 [] = { 0x03 , 0x07 , 0x01 , 0x0b } ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_33 * V_34 = NULL ;
struct V_55 * V_11 = V_3 -> V_11 ;
struct V_16 * V_17 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_40 * V_41 ;
const struct V_75 * V_76 ;
const T_1 * V_77 ;
char V_78 [ 64 ] ;
T_4 V_79 ;
T_5 V_80 , V_81 , V_82 ;
unsigned long long V_83 ;
unsigned int V_84 , V_85 ;
int V_86 = 0 ;
int V_7 ;
F_9 ( V_11 , L_22 ) ;
V_3 -> V_11 -> V_87 = V_88 ;
V_3 -> V_11 -> V_89 = V_90 ;
V_80 = F_70 () ;
if ( V_3 -> V_84 )
V_84 = V_3 -> V_84 ;
else
V_84 = V_3 -> V_91 -> V_84 ;
if ( V_3 -> V_85 )
V_85 = V_3 -> V_85 ;
else
V_85 = V_3 -> V_91 -> V_85 ;
if ( V_85 && V_84 && V_85 != V_84 )
V_86 = 1 ;
V_7 = F_2 ( V_3 ) ;
F_16 ( V_9 , & V_5 -> V_8 ) ;
if ( V_7 && V_7 != V_13 )
return V_7 ;
F_13 ( V_92 , & V_5 -> V_8 ) ;
V_17 = F_63 ( V_11 , 0xfc05 , 0 , NULL , V_67 ) ;
if ( F_64 ( V_17 ) ) {
F_5 ( V_11 , L_20 ,
F_65 ( V_17 ) ) ;
return F_65 ( V_17 ) ;
}
if ( V_17 -> V_93 != sizeof( * V_72 ) ) {
F_5 ( V_11 , L_23 ) ;
F_55 ( V_17 ) ;
return - V_94 ;
}
V_72 = (struct V_71 * ) V_17 -> V_95 ;
if ( V_72 -> V_96 ) {
F_5 ( V_11 , L_24 ,
V_72 -> V_96 ) ;
V_7 = - F_71 ( V_72 -> V_96 ) ;
F_55 ( V_17 ) ;
return V_7 ;
}
if ( V_72 -> V_97 != 0x37 ) {
F_5 ( V_11 , L_25 ,
V_72 -> V_97 ) ;
F_55 ( V_17 ) ;
return - V_27 ;
}
if ( V_72 -> V_98 != 0x0b ) {
F_5 ( V_11 , L_26 ,
V_72 -> V_98 ) ;
F_55 ( V_17 ) ;
return - V_27 ;
}
F_72 ( V_11 , V_72 ) ;
if ( V_72 -> V_99 == 0x23 ) {
F_55 ( V_17 ) ;
F_16 ( V_92 , & V_5 -> V_8 ) ;
F_73 ( V_11 ) ;
return 0 ;
}
if ( V_72 -> V_99 != 0x06 ) {
F_5 ( V_11 , L_27 ,
V_72 -> V_99 ) ;
F_55 ( V_17 ) ;
return - V_42 ;
}
F_55 ( V_17 ) ;
V_17 = F_63 ( V_11 , 0xfc0d , 0 , NULL , V_67 ) ;
if ( F_64 ( V_17 ) ) {
F_5 ( V_11 , L_28 ,
F_65 ( V_17 ) ) ;
return F_65 ( V_17 ) ;
}
if ( V_17 -> V_93 != sizeof( * V_74 ) ) {
F_5 ( V_11 , L_29 ) ;
F_55 ( V_17 ) ;
return - V_94 ;
}
V_74 = (struct V_73 * ) V_17 -> V_95 ;
if ( V_74 -> V_96 ) {
F_5 ( V_11 , L_30 ,
V_74 -> V_96 ) ;
V_7 = - F_71 ( V_74 -> V_96 ) ;
F_55 ( V_17 ) ;
return V_7 ;
}
F_62 ( V_11 , L_31 ,
F_74 ( V_74 -> V_100 ) ) ;
F_62 ( V_11 , L_32 ,
V_74 -> V_101 ? L_33 : L_34 ) ;
F_62 ( V_11 , L_35 ,
V_74 -> V_102 , V_74 -> V_103 ,
2000 + V_74 -> V_104 ) ;
if ( V_74 -> V_105 != 0x00 ) {
F_5 ( V_11 , L_36 ,
V_74 -> V_105 ) ;
F_55 ( V_17 ) ;
return - V_27 ;
}
if ( ! F_75 ( & V_74 -> V_106 , V_107 ) ) {
F_62 ( V_11 , L_37 ) ;
F_13 ( V_108 , & V_11 -> V_109 ) ;
}
snprintf ( V_78 , sizeof( V_78 ) , L_38 ,
F_74 ( V_74 -> V_100 ) ) ;
V_7 = F_76 ( & V_76 , V_78 , & V_11 -> V_36 ) ;
if ( V_7 < 0 ) {
F_5 ( V_11 , L_39 ,
V_7 ) ;
F_55 ( V_17 ) ;
return V_7 ;
}
F_62 ( V_11 , L_40 , V_78 ) ;
snprintf ( V_78 , sizeof( V_78 ) , L_41 ,
F_74 ( V_74 -> V_100 ) ) ;
F_55 ( V_17 ) ;
if ( V_76 -> V_110 < 644 ) {
F_5 ( V_11 , L_42 ,
V_76 -> V_110 ) ;
V_7 = - V_111 ;
goto V_112;
}
F_13 ( V_113 , & V_5 -> V_8 ) ;
V_7 = F_77 ( V_11 , 0x00 , 128 , V_76 -> V_95 ) ;
if ( V_7 < 0 ) {
F_5 ( V_11 , L_43 , V_7 ) ;
goto V_112;
}
V_7 = F_77 ( V_11 , 0x03 , 256 , V_76 -> V_95 + 128 ) ;
if ( V_7 < 0 ) {
F_5 ( V_11 , L_44 ,
V_7 ) ;
goto V_112;
}
V_7 = F_77 ( V_11 , 0x02 , 256 , V_76 -> V_95 + 388 ) ;
if ( V_7 < 0 ) {
F_5 ( V_11 , L_45 ,
V_7 ) ;
goto V_112;
}
V_77 = V_76 -> V_95 + 644 ;
V_79 = 0 ;
while ( V_77 - V_76 -> V_95 < V_76 -> V_110 ) {
struct V_114 * V_115 = ( void * ) ( V_77 + V_79 ) ;
V_79 += sizeof( * V_115 ) + V_115 -> V_63 ;
F_9 ( V_11 , L_46 , ( V_77 - V_76 -> V_95 ) ,
V_76 -> V_110 ) ;
if ( V_79 % 4 )
continue;
V_7 = F_77 ( V_11 , 0x01 , V_79 , V_77 ) ;
if ( V_7 < 0 ) {
F_5 ( V_11 , L_47 ,
V_7 ) ;
goto V_112;
}
V_77 += V_79 ;
V_79 = 0 ;
}
F_13 ( V_116 , & V_5 -> V_8 ) ;
F_62 ( V_11 , L_48 ) ;
V_7 = F_3 ( & V_5 -> V_8 , V_113 ,
V_10 ,
F_4 ( 5000 ) ) ;
if ( V_7 == 1 ) {
F_5 ( V_11 , L_49 ) ;
V_7 = - V_12 ;
goto V_112;
}
if ( V_7 ) {
F_5 ( V_11 , L_50 ) ;
V_7 = - V_13 ;
goto V_112;
}
if ( F_8 ( V_117 , & V_5 -> V_8 ) ) {
F_5 ( V_11 , L_51 ) ;
V_7 = - V_118 ;
goto V_112;
}
V_82 = F_70 () ;
V_81 = F_78 ( V_82 , V_80 ) ;
V_83 = ( unsigned long long ) F_79 ( V_81 ) >> 10 ;
F_62 ( V_11 , L_52 , V_83 ) ;
V_112:
F_80 ( V_76 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_86 ) {
V_7 = F_61 ( V_3 , V_84 ) ;
if ( V_7 )
return V_7 ;
}
V_80 = F_70 () ;
F_13 ( V_9 , & V_5 -> V_8 ) ;
V_17 = F_63 ( V_11 , 0xfc01 , sizeof( V_69 ) , V_69 ,
V_67 ) ;
if ( F_64 ( V_17 ) )
return F_65 ( V_17 ) ;
F_55 ( V_17 ) ;
F_62 ( V_11 , L_53 ) ;
V_7 = F_2 ( V_3 ) ;
if ( V_7 )
return V_7 ;
F_16 ( V_9 , & V_5 -> V_8 ) ;
V_82 = F_70 () ;
V_81 = F_78 ( V_82 , V_80 ) ;
V_83 = ( unsigned long long ) F_79 ( V_81 ) >> 10 ;
F_62 ( V_11 , L_54 , V_83 ) ;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_33 * V_36 = F_29 ( V_41 , struct V_33 ,
V_44 ) ;
if ( V_3 -> V_45 -> V_36 -> V_46 == V_36 -> V_35 -> V_36 . V_46 ) {
if ( F_41 ( & V_36 -> V_35 -> V_36 ) )
V_34 = V_36 ;
break;
}
}
F_23 ( & V_43 ) ;
if ( ! V_34 )
goto V_119;
F_62 ( V_11 , L_55 ) ;
V_17 = F_63 ( V_11 , 0xfc8b , sizeof( V_70 ) , V_70 ,
V_120 ) ;
if ( F_64 ( V_17 ) ) {
F_5 ( V_11 , L_56 ) ;
goto V_119;
}
F_55 ( V_17 ) ;
F_13 ( V_18 , & V_5 -> V_8 ) ;
V_119:
F_81 ( V_11 , V_78 ) ;
V_17 = F_63 ( V_11 , V_121 , 0 , NULL , V_120 ) ;
if ( F_64 ( V_17 ) )
return F_65 ( V_17 ) ;
F_55 ( V_17 ) ;
if ( V_86 ) {
V_7 = F_61 ( V_3 , V_85 ) ;
if ( V_7 )
return V_7 ;
}
F_62 ( V_11 , L_57 ) ;
F_16 ( V_92 , & V_5 -> V_8 ) ;
return 0 ;
}
static int F_82 ( struct V_55 * V_11 , struct V_16 * V_17 )
{
struct V_2 * V_3 = F_83 ( V_11 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_57 * V_58 ;
if ( ! F_8 ( V_92 , & V_5 -> V_8 ) &&
! F_8 ( V_9 , & V_5 -> V_8 ) )
goto V_122;
V_58 = ( void * ) V_17 -> V_95 ;
if ( V_17 -> V_93 == 7 && V_58 -> V_60 == 0xff && V_58 -> V_63 == 0x05 &&
V_17 -> V_95 [ 2 ] == 0x06 ) {
if ( V_17 -> V_95 [ 3 ] != 0x00 )
F_13 ( V_117 , & V_5 -> V_8 ) ;
if ( F_84 ( V_113 , & V_5 -> V_8 ) &&
F_8 ( V_116 , & V_5 -> V_8 ) ) {
F_85 () ;
F_86 ( & V_5 -> V_8 , V_113 ) ;
}
} else if ( V_17 -> V_93 == 9 && V_58 -> V_60 == 0xff && V_58 -> V_63 == 0x07 &&
V_17 -> V_95 [ 2 ] == 0x02 ) {
if ( F_84 ( V_9 , & V_5 -> V_8 ) ) {
F_85 () ;
F_86 ( & V_5 -> V_8 , V_9 ) ;
}
}
V_122:
return F_60 ( V_11 , V_17 ) ;
}
static void F_87 ( struct V_55 * V_11 , int V_123 )
{
struct V_2 * V_3 = F_83 ( V_11 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_9 ( V_11 , L_58 , V_123 ) ;
if ( V_123 ) {
F_13 ( V_20 , & V_5 -> V_8 ) ;
F_88 ( & V_5 -> V_53 ) ;
} else {
F_16 ( V_20 , & V_5 -> V_8 ) ;
}
}
static int F_89 ( struct V_55 * V_11 , struct V_16 * V_17 )
{
struct V_124 * V_125 = ( void * ) V_17 -> V_95 ;
struct V_2 * V_3 = F_83 ( V_11 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
switch ( V_125 -> V_56 ) {
case V_126 :
if ( V_125 -> V_127 < 1 ) {
F_5 ( V_3 -> V_11 , L_59 ) ;
break;
}
F_87 ( V_11 , V_125 -> V_95 [ 0 ] ) ;
break;
case V_128 :
F_13 ( V_19 , & V_5 -> V_8 ) ;
if ( F_84 ( V_14 , & V_5 -> V_8 ) ) {
F_85 () ;
F_86 ( & V_5 -> V_8 , V_14 ) ;
}
break;
case V_30 :
F_16 ( V_19 , & V_5 -> V_8 ) ;
if ( F_84 ( V_14 , & V_5 -> V_8 ) ) {
F_85 () ;
F_86 ( & V_5 -> V_8 , V_14 ) ;
}
break;
default:
F_5 ( V_11 , L_60 , V_125 -> V_56 ) ;
break;
}
F_55 ( V_17 ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 , const void * V_95 , int V_129 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( ! F_8 ( V_130 , & V_3 -> V_8 ) )
return - V_131 ;
V_5 -> V_54 = F_91 ( V_3 -> V_11 , V_5 -> V_54 , V_95 , V_129 ,
V_132 ,
F_92 ( V_132 ) ) ;
if ( F_64 ( V_5 -> V_54 ) ) {
int V_7 = F_65 ( V_5 -> V_54 ) ;
F_5 ( V_3 -> V_11 , L_61 , V_7 ) ;
V_5 -> V_54 = NULL ;
return V_7 ;
}
return V_129 ;
}
static int F_93 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_40 * V_41 ;
F_48 ( L_62 , V_3 , V_17 ) ;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_33 * V_34 = F_29 ( V_41 , struct V_33 ,
V_44 ) ;
if ( V_3 -> V_45 -> V_36 -> V_46 == V_34 -> V_35 -> V_36 . V_46 ) {
F_94 ( & V_34 -> V_35 -> V_36 ) ;
F_25 ( & V_34 -> V_35 -> V_36 ) ;
F_26 ( & V_34 -> V_35 -> V_36 ) ;
break;
}
}
F_23 ( & V_43 ) ;
F_66 ( & V_5 -> V_26 , V_17 ) ;
return 0 ;
}
static struct V_16 * F_95 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_16 * V_17 ;
V_17 = F_96 ( & V_5 -> V_26 ) ;
if ( ! V_17 )
return V_17 ;
if ( F_8 ( V_92 , & V_5 -> V_8 ) &&
( F_12 ( V_17 ) -> V_24 == V_68 ) ) {
struct V_114 * V_115 = ( void * ) V_17 -> V_95 ;
T_3 V_56 = F_74 ( V_115 -> V_56 ) ;
if ( V_56 == 0xfc01 )
F_58 ( V_3 -> V_11 , V_56 ) ;
}
memcpy ( F_97 ( V_17 , 1 ) , & F_12 ( V_17 ) -> V_24 , 1 ) ;
return V_17 ;
}
static int F_98 ( struct V_133 * V_36 )
{
struct V_33 * V_34 = F_99 ( V_36 ) ;
F_22 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_3 )
F_7 ( V_34 -> V_3 ) ;
F_23 ( & V_34 -> V_37 ) ;
return 0 ;
}
static int F_100 ( struct V_133 * V_36 )
{
struct V_33 * V_34 = F_99 ( V_36 ) ;
F_22 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_3 )
F_18 ( V_34 -> V_3 ) ;
F_23 ( & V_34 -> V_37 ) ;
return 0 ;
}
static int F_101 ( struct V_133 * V_36 )
{
struct V_33 * V_34 = F_99 ( V_36 ) ;
if ( F_41 ( V_36 ) )
F_102 ( V_34 -> V_31 ) ;
return F_98 ( V_36 ) ;
}
static int F_103 ( struct V_133 * V_36 )
{
struct V_33 * V_34 = F_99 ( V_36 ) ;
if ( F_41 ( V_36 ) )
F_104 ( V_34 -> V_31 ) ;
return F_100 ( V_36 ) ;
}
static int F_105 ( struct V_134 * V_35 )
{
struct V_33 * V_34 ;
V_34 = F_106 ( & V_35 -> V_36 , sizeof( * V_34 ) , V_22 ) ;
if ( ! V_34 )
return - V_23 ;
F_107 ( & V_34 -> V_37 ) ;
V_34 -> V_35 = V_35 ;
V_34 -> V_47 = F_108 ( & V_35 -> V_36 , L_63 ,
V_135 ) ;
if ( F_64 ( V_34 -> V_47 ) ) {
F_109 ( & V_35 -> V_36 , L_64 ) ;
return F_65 ( V_34 -> V_47 ) ;
}
V_34 -> V_31 = F_110 ( V_35 , 0 ) ;
if ( V_34 -> V_31 < 0 ) {
struct V_136 * V_137 ;
F_109 ( & V_35 -> V_36 , L_65 ) ;
V_137 = F_108 ( & V_35 -> V_36 , L_66 ,
V_138 ) ;
if ( F_64 ( V_137 ) ) {
F_109 ( & V_35 -> V_36 , L_67 ) ;
goto V_139;
}
V_34 -> V_31 = F_111 ( V_137 ) ;
if ( V_34 -> V_31 < 0 ) {
F_109 ( & V_35 -> V_36 , L_68 ) ;
goto V_139;
}
}
F_112 ( & V_35 -> V_36 , true ) ;
F_43 ( & V_35 -> V_36 ) ;
V_139:
F_113 ( V_35 , V_34 ) ;
F_22 ( & V_43 ) ;
F_114 ( & V_34 -> V_44 , & V_140 ) ;
F_23 ( & V_43 ) ;
F_21 ( & V_35 -> V_36 , L_69 ,
F_115 ( V_34 -> V_47 ) , V_34 -> V_31 ) ;
return 0 ;
}
static int F_116 ( struct V_134 * V_35 )
{
struct V_33 * V_34 = F_117 ( V_35 ) ;
F_43 ( & V_35 -> V_36 ) ;
F_22 ( & V_43 ) ;
F_118 ( & V_34 -> V_44 ) ;
F_23 ( & V_43 ) ;
F_21 ( & V_35 -> V_36 , L_70 ) ;
return 0 ;
}
int T_6 F_119 ( void )
{
F_120 ( & V_141 ) ;
return F_121 ( & V_142 ) ;
}
int T_7 F_122 ( void )
{
F_123 ( & V_141 ) ;
return F_124 ( & V_142 ) ;
}
