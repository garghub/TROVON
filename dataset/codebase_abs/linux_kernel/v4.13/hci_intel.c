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
if ( V_7 == - V_11 ) {
F_5 ( V_3 -> V_12 , L_1 ) ;
return - V_11 ;
}
if ( V_7 ) {
F_5 ( V_3 -> V_12 , L_2 ) ;
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
if ( V_7 == - V_11 ) {
F_5 ( V_3 -> V_12 , L_3 ) ;
return - V_11 ;
}
if ( V_7 ) {
F_5 ( V_3 -> V_12 , L_4 ) ;
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
F_9 ( V_3 -> V_12 , L_5 ) ;
V_17 = F_10 ( sizeof( V_15 ) , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_3 -> V_12 , L_6 ) ;
return - V_23 ;
}
F_11 ( V_17 , V_15 , sizeof( V_15 ) ) ;
F_12 ( V_17 ) = V_24 ;
F_13 ( V_14 , & V_5 -> V_8 ) ;
F_14 ( & V_5 -> V_25 , V_17 ) ;
F_15 ( V_3 ) ;
F_6 ( V_3 ) ;
F_16 ( V_14 , & V_5 -> V_8 ) ;
if ( ! F_8 ( V_19 , & V_5 -> V_8 ) ) {
F_5 ( V_3 -> V_12 , L_7 ) ;
return - V_26 ;
}
F_9 ( V_3 -> V_12 , L_8 ) ;
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
F_9 ( V_3 -> V_12 , L_9 ) ;
F_17 ( V_3 , false ) ;
V_17 = F_10 ( 0 , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_3 -> V_12 , L_6 ) ;
return - V_23 ;
}
F_12 ( V_17 ) = V_27 ;
F_13 ( V_14 , & V_5 -> V_8 ) ;
F_14 ( & V_5 -> V_25 , V_17 ) ;
F_15 ( V_3 ) ;
F_6 ( V_3 ) ;
F_16 ( V_14 , & V_5 -> V_8 ) ;
if ( F_8 ( V_19 , & V_5 -> V_8 ) ) {
F_5 ( V_3 -> V_12 , L_10 ) ;
return - V_26 ;
}
F_9 ( V_3 -> V_12 , L_11 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
static const T_1 V_28 [] = { V_29 , 0x00 } ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_16 * V_17 ;
F_17 ( V_3 , false ) ;
F_16 ( V_19 , & V_5 -> V_8 ) ;
V_17 = F_10 ( sizeof( V_28 ) , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_3 -> V_12 , L_6 ) ;
return - V_23 ;
}
F_11 ( V_17 , V_28 , sizeof( V_28 ) ) ;
F_12 ( V_17 ) = V_24 ;
F_14 ( & V_5 -> V_25 , V_17 ) ;
F_15 ( V_3 ) ;
F_9 ( V_3 -> V_12 , L_12 ) ;
return 0 ;
}
static T_2 F_20 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
F_21 ( & V_33 -> V_34 -> V_35 , L_13 ) ;
F_22 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_3 )
F_19 ( V_33 -> V_3 ) ;
F_23 ( & V_33 -> V_36 ) ;
F_24 ( & V_33 -> V_34 -> V_35 ) ;
F_25 ( & V_33 -> V_34 -> V_35 ) ;
F_26 ( & V_33 -> V_34 -> V_35 ) ;
return V_37 ;
}
static int F_27 ( struct V_2 * V_3 , bool V_38 )
{
struct V_39 * V_40 ;
int V_7 = - V_41 ;
if ( ! V_3 -> V_42 -> V_35 )
return V_7 ;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_32 * V_33 = F_29 ( V_40 , struct V_32 ,
V_44 ) ;
if ( V_3 -> V_42 -> V_35 -> V_45 != V_33 -> V_34 -> V_35 . V_45 )
continue;
if ( ! V_33 -> V_46 ) {
V_7 = - V_47 ;
break;
}
F_30 ( L_14 ,
V_3 , F_31 ( & V_33 -> V_34 -> V_35 ) , V_38 ) ;
F_32 ( V_33 -> V_46 , V_38 ) ;
F_22 ( & V_33 -> V_36 ) ;
V_33 -> V_3 = V_38 ? V_3 : NULL ;
F_23 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_30 < 0 )
break;
if ( V_38 && F_33 ( & V_33 -> V_34 -> V_35 ) ) {
V_7 = F_34 ( & V_33 -> V_34 -> V_35 ,
V_33 -> V_30 , NULL ,
F_20 ,
V_48 ,
L_15 , V_33 ) ;
if ( V_7 ) {
F_35 ( L_16 ,
V_3 , V_33 -> V_30 ) ;
break;
}
F_36 ( & V_33 -> V_34 -> V_35 ) ;
F_37 ( & V_33 -> V_34 -> V_35 ) ;
F_38 ( & V_33 -> V_34 -> V_35 ) ;
F_39 ( & V_33 -> V_34 -> V_35 ,
V_49 ) ;
F_40 ( & V_33 -> V_34 -> V_35 ) ;
} else if ( ! V_38 && F_41 ( & V_33 -> V_34 -> V_35 ) ) {
F_42 ( & V_33 -> V_34 -> V_35 , V_33 -> V_30 , V_33 ) ;
F_43 ( & V_33 -> V_34 -> V_35 ) ;
F_44 ( & V_33 -> V_34 -> V_35 ) ;
}
}
F_23 ( & V_43 ) ;
return V_7 ;
}
static void F_45 ( struct V_50 * V_51 )
{
struct V_39 * V_40 ;
struct V_4 * V_5 = F_46 ( V_51 , struct V_4 ,
V_52 ) ;
if ( ! V_5 -> V_3 -> V_42 -> V_35 )
return;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_32 * V_33 = F_29 ( V_40 , struct V_32 ,
V_44 ) ;
if ( V_5 -> V_3 -> V_42 -> V_35 -> V_45 == V_33 -> V_34 -> V_35 . V_45 ) {
F_24 ( & V_33 -> V_34 -> V_35 ) ;
F_25 ( & V_33 -> V_34 -> V_35 ) ;
F_26 ( & V_33 -> V_34 -> V_35 ) ;
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
F_50 ( & V_5 -> V_25 ) ;
F_51 ( & V_5 -> V_52 , F_45 ) ;
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
F_53 ( & V_5 -> V_52 ) ;
F_27 ( V_3 , false ) ;
F_54 ( & V_5 -> V_25 ) ;
F_55 ( V_5 -> V_53 ) ;
F_56 ( V_5 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_48 ( L_17 , V_3 ) ;
F_54 ( & V_5 -> V_25 ) ;
return 0 ;
}
static int F_58 ( struct V_54 * V_12 , T_3 V_55 )
{
struct V_16 * V_17 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_17 = F_10 ( sizeof( * V_57 ) + sizeof( * V_59 ) + 1 , V_60 ) ;
if ( ! V_17 )
return - V_23 ;
V_57 = F_59 ( V_17 , sizeof( * V_57 ) ) ;
V_57 -> V_59 = V_61 ;
V_57 -> V_62 = sizeof( * V_59 ) + 1 ;
V_59 = F_59 ( V_17 , sizeof( * V_59 ) ) ;
V_59 -> V_63 = 0x01 ;
V_59 -> V_55 = F_60 ( V_55 ) ;
F_61 ( V_17 , 0x00 ) ;
F_12 ( V_17 ) = V_64 ;
return F_62 ( V_12 , V_17 ) ;
}
static int F_63 ( struct V_2 * V_3 , unsigned int V_1 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_54 * V_12 = V_3 -> V_12 ;
T_1 V_65 [] = { 0x06 , 0xfc , 0x01 , 0x00 } ;
struct V_16 * V_17 ;
int V_7 ;
V_7 = F_2 ( V_3 ) ;
F_16 ( V_9 , & V_5 -> V_8 ) ;
if ( V_7 && V_7 != - V_13 )
return V_7 ;
F_64 ( V_12 , L_18 , V_1 ) ;
V_65 [ 3 ] = F_1 ( V_1 ) ;
if ( V_65 [ 3 ] == 0xff ) {
F_5 ( V_12 , L_19 ) ;
return - V_26 ;
}
V_17 = F_65 ( V_12 , 0xfc05 , 0 , NULL , V_66 ) ;
if ( F_66 ( V_17 ) ) {
F_5 ( V_12 , L_20 ,
F_67 ( V_17 ) ) ;
return F_67 ( V_17 ) ;
}
F_55 ( V_17 ) ;
V_17 = F_10 ( sizeof( V_65 ) , V_22 ) ;
if ( ! V_17 ) {
F_5 ( V_12 , L_21 ) ;
return - V_23 ;
}
F_11 ( V_17 , V_65 , sizeof( V_65 ) ) ;
F_12 ( V_17 ) = V_67 ;
F_17 ( V_3 , true ) ;
F_68 ( & V_5 -> V_25 , V_17 ) ;
F_15 ( V_3 ) ;
F_69 ( 100 ) ;
F_70 ( V_3 , V_1 ) ;
F_17 ( V_3 , false ) ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 )
{
static const T_1 V_68 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_54 * V_12 = V_3 -> V_12 ;
struct V_16 * V_17 ;
struct V_69 V_70 ;
struct V_71 * V_72 ;
struct V_39 * V_40 ;
const struct V_73 * V_74 ;
const T_1 * V_75 ;
char V_76 [ 64 ] ;
T_4 V_77 ;
T_5 V_78 , V_79 , V_80 ;
unsigned long long V_81 ;
unsigned int V_82 , V_83 ;
int V_84 = 0 ;
int V_7 ;
F_9 ( V_12 , L_22 ) ;
V_3 -> V_12 -> V_85 = V_86 ;
V_3 -> V_12 -> V_87 = V_88 ;
V_78 = F_72 () ;
if ( V_3 -> V_82 )
V_82 = V_3 -> V_82 ;
else
V_82 = V_3 -> V_89 -> V_82 ;
if ( V_3 -> V_83 )
V_83 = V_3 -> V_83 ;
else
V_83 = V_3 -> V_89 -> V_83 ;
if ( V_83 && V_82 && V_83 != V_82 )
V_84 = 1 ;
V_7 = F_2 ( V_3 ) ;
F_16 ( V_9 , & V_5 -> V_8 ) ;
if ( V_7 && V_7 != - V_13 )
return V_7 ;
F_13 ( V_90 , & V_5 -> V_8 ) ;
V_7 = F_73 ( V_12 , & V_70 ) ;
if ( V_7 )
return V_7 ;
if ( V_70 . V_91 != 0x37 ) {
F_5 ( V_12 , L_23 ,
V_70 . V_91 ) ;
return - V_26 ;
}
switch ( V_70 . V_92 ) {
case 0x0b :
case 0x0c :
case 0x12 :
break;
default:
F_5 ( V_12 , L_24 ,
V_70 . V_92 ) ;
return - V_26 ;
}
F_74 ( V_12 , & V_70 ) ;
if ( V_70 . V_93 == 0x23 ) {
F_16 ( V_90 , & V_5 -> V_8 ) ;
F_75 ( V_12 ) ;
return 0 ;
}
if ( V_70 . V_93 != 0x06 ) {
F_5 ( V_12 , L_25 ,
V_70 . V_93 ) ;
return - V_41 ;
}
V_17 = F_65 ( V_12 , 0xfc0d , 0 , NULL , V_66 ) ;
if ( F_66 ( V_17 ) ) {
F_5 ( V_12 , L_26 ,
F_67 ( V_17 ) ) ;
return F_67 ( V_17 ) ;
}
if ( V_17 -> V_94 != sizeof( * V_72 ) ) {
F_5 ( V_12 , L_27 ) ;
F_55 ( V_17 ) ;
return - V_95 ;
}
V_72 = (struct V_71 * ) V_17 -> V_96 ;
if ( V_72 -> V_97 ) {
F_5 ( V_12 , L_28 ,
V_72 -> V_97 ) ;
V_7 = - F_76 ( V_72 -> V_97 ) ;
F_55 ( V_17 ) ;
return V_7 ;
}
F_64 ( V_12 , L_29 ,
F_77 ( V_72 -> V_98 ) ) ;
F_64 ( V_12 , L_30 ,
V_72 -> V_99 ? L_31 : L_32 ) ;
F_64 ( V_12 , L_33 ,
V_72 -> V_100 , V_72 -> V_101 ,
2000 + V_72 -> V_102 ) ;
if ( V_72 -> V_103 != 0x00 ) {
F_5 ( V_12 , L_34 ,
V_72 -> V_103 ) ;
F_55 ( V_17 ) ;
return - V_26 ;
}
if ( ! F_78 ( & V_72 -> V_104 , V_105 ) ) {
F_64 ( V_12 , L_35 ) ;
F_13 ( V_106 , & V_12 -> V_107 ) ;
}
snprintf ( V_76 , sizeof( V_76 ) , L_36 ,
F_77 ( V_70 . V_92 ) ,
F_77 ( V_72 -> V_98 ) ) ;
V_7 = F_79 ( & V_74 , V_76 , & V_12 -> V_35 ) ;
if ( V_7 < 0 ) {
F_5 ( V_12 , L_37 ,
V_7 ) ;
F_55 ( V_17 ) ;
return V_7 ;
}
F_64 ( V_12 , L_38 , V_76 ) ;
snprintf ( V_76 , sizeof( V_76 ) , L_39 ,
F_77 ( V_70 . V_92 ) ,
F_77 ( V_72 -> V_98 ) ) ;
F_55 ( V_17 ) ;
if ( V_74 -> V_108 < 644 ) {
F_5 ( V_12 , L_40 ,
V_74 -> V_108 ) ;
V_7 = - V_109 ;
goto V_110;
}
F_13 ( V_111 , & V_5 -> V_8 ) ;
V_7 = F_80 ( V_12 , 0x00 , 128 , V_74 -> V_96 ) ;
if ( V_7 < 0 ) {
F_5 ( V_12 , L_41 , V_7 ) ;
goto V_110;
}
V_7 = F_80 ( V_12 , 0x03 , 256 , V_74 -> V_96 + 128 ) ;
if ( V_7 < 0 ) {
F_5 ( V_12 , L_42 ,
V_7 ) ;
goto V_110;
}
V_7 = F_80 ( V_12 , 0x02 , 256 , V_74 -> V_96 + 388 ) ;
if ( V_7 < 0 ) {
F_5 ( V_12 , L_43 ,
V_7 ) ;
goto V_110;
}
V_75 = V_74 -> V_96 + 644 ;
V_77 = 0 ;
while ( V_75 - V_74 -> V_96 < V_74 -> V_108 ) {
struct V_112 * V_113 = ( void * ) ( V_75 + V_77 ) ;
V_77 += sizeof( * V_113 ) + V_113 -> V_62 ;
F_9 ( V_12 , L_44 , ( V_75 - V_74 -> V_96 ) ,
V_74 -> V_108 ) ;
if ( V_77 % 4 )
continue;
V_7 = F_80 ( V_12 , 0x01 , V_77 , V_75 ) ;
if ( V_7 < 0 ) {
F_5 ( V_12 , L_45 ,
V_7 ) ;
goto V_110;
}
V_75 += V_77 ;
V_77 = 0 ;
}
F_13 ( V_114 , & V_5 -> V_8 ) ;
F_64 ( V_12 , L_46 ) ;
V_7 = F_3 ( & V_5 -> V_8 , V_111 ,
V_10 ,
F_4 ( 5000 ) ) ;
if ( V_7 == - V_11 ) {
F_5 ( V_12 , L_47 ) ;
V_7 = - V_11 ;
goto V_110;
}
if ( V_7 ) {
F_5 ( V_12 , L_48 ) ;
V_7 = - V_13 ;
goto V_110;
}
if ( F_8 ( V_115 , & V_5 -> V_8 ) ) {
F_5 ( V_12 , L_49 ) ;
V_7 = - V_116 ;
goto V_110;
}
V_80 = F_72 () ;
V_79 = F_81 ( V_80 , V_78 ) ;
V_81 = ( unsigned long long ) F_82 ( V_79 ) >> 10 ;
F_64 ( V_12 , L_50 , V_81 ) ;
V_110:
F_83 ( V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_84 ) {
V_7 = F_63 ( V_3 , V_82 ) ;
if ( V_7 )
return V_7 ;
}
V_78 = F_72 () ;
F_13 ( V_9 , & V_5 -> V_8 ) ;
V_17 = F_65 ( V_12 , 0xfc01 , sizeof( V_68 ) , V_68 ,
V_66 ) ;
if ( F_66 ( V_17 ) )
return F_67 ( V_17 ) ;
F_55 ( V_17 ) ;
F_64 ( V_12 , L_51 ) ;
V_7 = F_2 ( V_3 ) ;
if ( V_7 )
return V_7 ;
F_16 ( V_9 , & V_5 -> V_8 ) ;
V_80 = F_72 () ;
V_79 = F_81 ( V_80 , V_78 ) ;
V_81 = ( unsigned long long ) F_82 ( V_79 ) >> 10 ;
F_64 ( V_12 , L_52 , V_81 ) ;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_32 * V_35 = F_29 ( V_40 , struct V_32 ,
V_44 ) ;
if ( ! V_3 -> V_42 -> V_35 )
break;
if ( V_3 -> V_42 -> V_35 -> V_45 == V_35 -> V_34 -> V_35 . V_45 ) {
if ( F_41 ( & V_35 -> V_34 -> V_35 ) ) {
F_13 ( V_18 , & V_5 -> V_8 ) ;
F_13 ( V_20 , & V_5 -> V_8 ) ;
}
break;
}
}
F_23 ( & V_43 ) ;
F_84 ( V_12 , V_76 ) ;
V_17 = F_65 ( V_12 , V_117 , 0 , NULL , V_66 ) ;
if ( F_66 ( V_17 ) )
return F_67 ( V_17 ) ;
F_55 ( V_17 ) ;
if ( V_84 ) {
V_7 = F_63 ( V_3 , V_83 ) ;
if ( V_7 )
return V_7 ;
}
F_64 ( V_12 , L_53 ) ;
F_16 ( V_90 , & V_5 -> V_8 ) ;
return 0 ;
}
static int F_85 ( struct V_54 * V_12 , struct V_16 * V_17 )
{
struct V_2 * V_3 = F_86 ( V_12 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_56 * V_57 ;
if ( ! F_8 ( V_90 , & V_5 -> V_8 ) &&
! F_8 ( V_9 , & V_5 -> V_8 ) )
goto V_118;
V_57 = ( void * ) V_17 -> V_96 ;
if ( V_17 -> V_94 == 7 && V_57 -> V_59 == 0xff && V_57 -> V_62 == 0x05 &&
V_17 -> V_96 [ 2 ] == 0x06 ) {
if ( V_17 -> V_96 [ 3 ] != 0x00 )
F_13 ( V_115 , & V_5 -> V_8 ) ;
if ( F_87 ( V_111 , & V_5 -> V_8 ) &&
F_8 ( V_114 , & V_5 -> V_8 ) ) {
F_88 () ;
F_89 ( & V_5 -> V_8 , V_111 ) ;
}
} else if ( V_17 -> V_94 == 9 && V_57 -> V_59 == 0xff && V_57 -> V_62 == 0x07 &&
V_17 -> V_96 [ 2 ] == 0x02 ) {
if ( F_87 ( V_9 , & V_5 -> V_8 ) ) {
F_88 () ;
F_89 ( & V_5 -> V_8 , V_9 ) ;
}
}
V_118:
return F_62 ( V_12 , V_17 ) ;
}
static void F_90 ( struct V_54 * V_12 , int V_119 )
{
struct V_2 * V_3 = F_86 ( V_12 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
F_9 ( V_12 , L_54 , V_119 ) ;
if ( V_119 ) {
F_13 ( V_20 , & V_5 -> V_8 ) ;
F_91 ( & V_5 -> V_52 ) ;
} else {
F_16 ( V_20 , & V_5 -> V_8 ) ;
}
}
static int F_92 ( struct V_54 * V_12 , struct V_16 * V_17 )
{
struct V_120 * V_121 = ( void * ) V_17 -> V_96 ;
struct V_2 * V_3 = F_86 ( V_12 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
switch ( V_121 -> V_55 ) {
case V_122 :
if ( V_121 -> V_123 < 1 ) {
F_5 ( V_3 -> V_12 , L_55 ) ;
break;
}
F_90 ( V_12 , V_121 -> V_96 [ 0 ] ) ;
break;
case V_124 :
F_13 ( V_19 , & V_5 -> V_8 ) ;
if ( F_87 ( V_14 , & V_5 -> V_8 ) ) {
F_88 () ;
F_89 ( & V_5 -> V_8 , V_14 ) ;
}
break;
case V_29 :
F_16 ( V_19 , & V_5 -> V_8 ) ;
if ( F_87 ( V_14 , & V_5 -> V_8 ) ) {
F_88 () ;
F_89 ( & V_5 -> V_8 , V_14 ) ;
}
break;
default:
F_5 ( V_12 , L_56 , V_121 -> V_55 ) ;
break;
}
F_55 ( V_17 ) ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 , const void * V_96 , int V_125 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( ! F_8 ( V_126 , & V_3 -> V_8 ) )
return - V_127 ;
V_5 -> V_53 = F_94 ( V_3 -> V_12 , V_5 -> V_53 , V_96 , V_125 ,
V_128 ,
F_95 ( V_128 ) ) ;
if ( F_66 ( V_5 -> V_53 ) ) {
int V_7 = F_67 ( V_5 -> V_53 ) ;
F_5 ( V_3 -> V_12 , L_57 , V_7 ) ;
V_5 -> V_53 = NULL ;
return V_7 ;
}
return V_125 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_39 * V_40 ;
F_48 ( L_58 , V_3 , V_17 ) ;
if ( ! V_3 -> V_42 -> V_35 )
goto V_129;
F_22 ( & V_43 ) ;
F_28 (p, &intel_device_list) {
struct V_32 * V_33 = F_29 ( V_40 , struct V_32 ,
V_44 ) ;
if ( V_3 -> V_42 -> V_35 -> V_45 == V_33 -> V_34 -> V_35 . V_45 ) {
F_97 ( & V_33 -> V_34 -> V_35 ) ;
F_25 ( & V_33 -> V_34 -> V_35 ) ;
F_26 ( & V_33 -> V_34 -> V_35 ) ;
break;
}
}
F_23 ( & V_43 ) ;
V_129:
F_68 ( & V_5 -> V_25 , V_17 ) ;
return 0 ;
}
static struct V_16 * F_98 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_16 * V_17 ;
V_17 = F_99 ( & V_5 -> V_25 ) ;
if ( ! V_17 )
return V_17 ;
if ( F_8 ( V_90 , & V_5 -> V_8 ) &&
( F_12 ( V_17 ) == V_67 ) ) {
struct V_112 * V_113 = ( void * ) V_17 -> V_96 ;
T_3 V_55 = F_77 ( V_113 -> V_55 ) ;
if ( V_55 == 0xfc01 )
F_58 ( V_3 -> V_12 , V_55 ) ;
}
memcpy ( F_100 ( V_17 , 1 ) , & F_12 ( V_17 ) , 1 ) ;
return V_17 ;
}
static int F_101 ( struct V_130 * V_35 )
{
struct V_32 * V_33 = F_102 ( V_35 ) ;
F_22 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_3 )
F_7 ( V_33 -> V_3 ) ;
F_23 ( & V_33 -> V_36 ) ;
return 0 ;
}
static int F_103 ( struct V_130 * V_35 )
{
struct V_32 * V_33 = F_102 ( V_35 ) ;
F_22 ( & V_33 -> V_36 ) ;
if ( V_33 -> V_3 )
F_18 ( V_33 -> V_3 ) ;
F_23 ( & V_33 -> V_36 ) ;
return 0 ;
}
static int F_104 ( struct V_130 * V_35 )
{
struct V_32 * V_33 = F_102 ( V_35 ) ;
if ( F_41 ( V_35 ) )
F_105 ( V_33 -> V_30 ) ;
return F_101 ( V_35 ) ;
}
static int F_106 ( struct V_130 * V_35 )
{
struct V_32 * V_33 = F_102 ( V_35 ) ;
if ( F_41 ( V_35 ) )
F_107 ( V_33 -> V_30 ) ;
return F_103 ( V_35 ) ;
}
static int F_108 ( struct V_131 * V_34 )
{
struct V_32 * V_33 ;
int V_132 ;
V_33 = F_109 ( & V_34 -> V_35 , sizeof( * V_33 ) , V_22 ) ;
if ( ! V_33 )
return - V_23 ;
F_110 ( & V_33 -> V_36 ) ;
V_33 -> V_34 = V_34 ;
V_132 = F_111 ( & V_34 -> V_35 , V_133 ) ;
if ( V_132 )
F_112 ( & V_34 -> V_35 , L_59 ) ;
V_33 -> V_46 = F_113 ( & V_34 -> V_35 , L_60 , V_134 ) ;
if ( F_66 ( V_33 -> V_46 ) ) {
F_114 ( & V_34 -> V_35 , L_61 ) ;
return F_67 ( V_33 -> V_46 ) ;
}
V_33 -> V_30 = F_115 ( V_34 , 0 ) ;
if ( V_33 -> V_30 < 0 ) {
struct V_135 * V_136 ;
F_114 ( & V_34 -> V_35 , L_62 ) ;
V_136 = F_113 ( & V_34 -> V_35 , L_63 , V_137 ) ;
if ( F_66 ( V_136 ) ) {
F_114 ( & V_34 -> V_35 , L_64 ) ;
goto V_138;
}
V_33 -> V_30 = F_116 ( V_136 ) ;
if ( V_33 -> V_30 < 0 ) {
F_114 ( & V_34 -> V_35 , L_65 ) ;
goto V_138;
}
}
F_117 ( & V_34 -> V_35 , true ) ;
F_43 ( & V_34 -> V_35 ) ;
V_138:
F_118 ( V_34 , V_33 ) ;
F_22 ( & V_43 ) ;
F_119 ( & V_33 -> V_44 , & V_139 ) ;
F_23 ( & V_43 ) ;
F_21 ( & V_34 -> V_35 , L_66 ,
F_120 ( V_33 -> V_46 ) , V_33 -> V_30 ) ;
return 0 ;
}
static int F_121 ( struct V_131 * V_34 )
{
struct V_32 * V_33 = F_122 ( V_34 ) ;
F_43 ( & V_34 -> V_35 ) ;
F_22 ( & V_43 ) ;
F_123 ( & V_33 -> V_44 ) ;
F_23 ( & V_43 ) ;
F_21 ( & V_34 -> V_35 , L_67 ) ;
return 0 ;
}
int T_6 F_124 ( void )
{
F_125 ( & V_140 ) ;
return F_126 ( & V_141 ) ;
}
int T_7 F_127 ( void )
{
F_128 ( & V_140 ) ;
return F_129 ( & V_141 ) ;
}
