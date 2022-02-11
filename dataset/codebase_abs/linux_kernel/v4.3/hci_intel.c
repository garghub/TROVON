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
F_5 ( L_1 , V_3 -> V_11 -> V_12 ) ;
return - V_13 ;
}
if ( V_7 ) {
F_5 ( L_2 , V_3 -> V_11 -> V_12 ) ;
return - V_14 ;
}
return V_7 ;
}
static int F_6 ( struct V_2 * V_3 , bool V_15 )
{
struct V_16 * V_17 ;
int V_7 = - V_18 ;
F_7 ( & V_19 ) ;
F_8 (p, &intel_device_list) {
struct V_20 * V_21 = F_9 ( V_17 , struct V_20 ,
V_22 ) ;
if ( V_3 -> V_23 -> V_24 -> V_25 != V_21 -> V_26 -> V_24 . V_25 )
continue;
if ( ! V_21 -> V_27 ) {
V_7 = - V_28 ;
break;
}
F_10 ( L_3 ,
V_3 , F_11 ( & V_21 -> V_26 -> V_24 ) , V_15 ) ;
F_12 ( V_21 -> V_27 , V_15 ) ;
}
F_13 ( & V_19 ) ;
return V_7 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_15 ( L_4 , V_3 ) ;
V_5 = F_16 ( sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
F_17 ( & V_5 -> V_31 ) ;
V_3 -> V_6 = V_5 ;
if ( ! F_6 ( V_3 , true ) )
F_18 ( V_9 , & V_5 -> V_8 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_15 ( L_4 , V_3 ) ;
F_6 ( V_3 , false ) ;
F_20 ( & V_5 -> V_31 ) ;
F_21 ( V_5 -> V_32 ) ;
F_22 ( V_5 ) ;
V_3 -> V_6 = NULL ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_15 ( L_4 , V_3 ) ;
F_20 ( & V_5 -> V_31 ) ;
return 0 ;
}
static int F_24 ( struct V_33 * V_11 , T_2 V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_36 = F_25 ( sizeof( * V_38 ) + sizeof( * V_40 ) + 1 , V_41 ) ;
if ( ! V_36 )
return - V_30 ;
V_38 = (struct V_37 * ) F_26 ( V_36 , sizeof( * V_38 ) ) ;
V_38 -> V_40 = V_42 ;
V_38 -> V_43 = sizeof( * V_40 ) + 1 ;
V_40 = (struct V_39 * ) F_26 ( V_36 , sizeof( * V_40 ) ) ;
V_40 -> V_44 = 0x01 ;
V_40 -> V_34 = F_27 ( V_34 ) ;
* F_26 ( V_36 , 1 ) = 0x00 ;
F_28 ( V_36 ) -> V_45 = V_46 ;
return F_29 ( V_11 , V_36 ) ;
}
static int F_30 ( struct V_2 * V_3 , unsigned int V_1 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_33 * V_11 = V_3 -> V_11 ;
T_1 V_47 [] = { 0x06 , 0xfc , 0x01 , 0x00 } ;
struct V_35 * V_36 ;
int V_7 ;
V_7 = F_2 ( V_3 ) ;
F_31 ( V_9 , & V_5 -> V_8 ) ;
if ( V_7 && V_7 != V_14 )
return V_7 ;
F_10 ( L_5 , V_11 -> V_12 , V_1 ) ;
V_47 [ 3 ] = F_1 ( V_1 ) ;
if ( V_47 [ 3 ] == 0xff ) {
F_5 ( L_6 , V_11 -> V_12 ) ;
return - V_48 ;
}
V_36 = F_32 ( V_11 , 0xfc05 , 0 , NULL , V_49 ) ;
if ( F_33 ( V_36 ) ) {
F_5 ( L_7 ,
V_11 -> V_12 , F_34 ( V_36 ) ) ;
return F_34 ( V_36 ) ;
}
F_21 ( V_36 ) ;
V_36 = F_25 ( sizeof( V_47 ) , V_29 ) ;
if ( ! V_36 ) {
F_5 ( L_8 ,
V_11 -> V_12 ) ;
return - V_30 ;
}
memcpy ( F_26 ( V_36 , sizeof( V_47 ) ) , V_47 , sizeof( V_47 ) ) ;
F_28 ( V_36 ) -> V_45 = V_50 ;
F_35 ( V_3 , true ) ;
F_36 ( & V_5 -> V_31 , V_36 ) ;
F_37 ( V_3 ) ;
F_38 ( 100 ) ;
F_39 ( V_3 , V_1 ) ;
F_35 ( V_3 , false ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
static const T_1 V_51 [] = { 0x00 , 0x01 , 0x00 , 0x01 ,
0x00 , 0x08 , 0x04 , 0x00 } ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_33 * V_11 = V_3 -> V_11 ;
struct V_35 * V_36 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
const struct V_56 * V_57 ;
const T_1 * V_58 ;
char V_59 [ 64 ] ;
T_3 V_60 ;
T_4 V_61 , V_62 , V_63 ;
unsigned long long V_64 ;
unsigned int V_65 , V_66 ;
int V_67 = 0 ;
int V_7 ;
F_15 ( L_9 , V_11 -> V_12 ) ;
V_3 -> V_11 -> V_68 = V_69 ;
V_61 = F_41 () ;
if ( V_3 -> V_65 )
V_65 = V_3 -> V_65 ;
else
V_65 = V_3 -> V_70 -> V_65 ;
if ( V_3 -> V_66 )
V_66 = V_3 -> V_66 ;
else
V_66 = V_3 -> V_70 -> V_66 ;
if ( V_66 && V_65 && V_66 != V_65 )
V_67 = 1 ;
V_7 = F_2 ( V_3 ) ;
F_31 ( V_9 , & V_5 -> V_8 ) ;
if ( V_7 && V_7 != V_14 )
return V_7 ;
F_18 ( V_71 , & V_5 -> V_8 ) ;
V_36 = F_32 ( V_11 , 0xfc05 , 0 , NULL , V_49 ) ;
if ( F_33 ( V_36 ) ) {
F_5 ( L_7 ,
V_11 -> V_12 , F_34 ( V_36 ) ) ;
return F_34 ( V_36 ) ;
}
if ( V_36 -> V_72 != sizeof( * V_53 ) ) {
F_5 ( L_10 , V_11 -> V_12 ) ;
F_21 ( V_36 ) ;
return - V_73 ;
}
V_53 = (struct V_52 * ) V_36 -> V_74 ;
if ( V_53 -> V_75 ) {
F_5 ( L_11 ,
V_11 -> V_12 , V_53 -> V_75 ) ;
V_7 = - F_42 ( V_53 -> V_75 ) ;
F_21 ( V_36 ) ;
return V_7 ;
}
if ( V_53 -> V_76 != 0x37 ) {
F_5 ( L_12 ,
V_11 -> V_12 , V_53 -> V_76 ) ;
F_21 ( V_36 ) ;
return - V_48 ;
}
if ( V_53 -> V_77 != 0x0b ) {
F_5 ( L_13 ,
V_11 -> V_12 , V_53 -> V_77 ) ;
F_21 ( V_36 ) ;
return - V_48 ;
}
F_43 ( V_11 , V_53 ) ;
if ( V_53 -> V_78 == 0x23 ) {
F_21 ( V_36 ) ;
F_31 ( V_71 , & V_5 -> V_8 ) ;
F_44 ( V_11 ) ;
return 0 ;
}
if ( V_53 -> V_78 != 0x06 ) {
F_5 ( L_14 ,
V_11 -> V_12 , V_53 -> V_78 ) ;
F_21 ( V_36 ) ;
return - V_18 ;
}
F_21 ( V_36 ) ;
V_36 = F_32 ( V_11 , 0xfc0d , 0 , NULL , V_49 ) ;
if ( F_33 ( V_36 ) ) {
F_5 ( L_15 ,
V_11 -> V_12 , F_34 ( V_36 ) ) ;
return F_34 ( V_36 ) ;
}
if ( V_36 -> V_72 != sizeof( * V_55 ) ) {
F_5 ( L_16 , V_11 -> V_12 ) ;
F_21 ( V_36 ) ;
return - V_73 ;
}
V_55 = (struct V_54 * ) V_36 -> V_74 ;
if ( V_55 -> V_75 ) {
F_5 ( L_17 ,
V_11 -> V_12 , V_55 -> V_75 ) ;
V_7 = - F_42 ( V_55 -> V_75 ) ;
F_21 ( V_36 ) ;
return V_7 ;
}
F_10 ( L_18 , V_11 -> V_12 ,
F_45 ( V_55 -> V_79 ) ) ;
F_10 ( L_19 , V_11 -> V_12 ,
V_55 -> V_80 ? L_20 : L_21 ) ;
F_10 ( L_22 , V_11 -> V_12 ,
V_55 -> V_81 , V_55 -> V_82 ,
2000 + V_55 -> V_83 ) ;
if ( V_55 -> V_84 != 0x00 ) {
F_5 ( L_23 ,
V_11 -> V_12 , V_55 -> V_84 ) ;
F_21 ( V_36 ) ;
return - V_48 ;
}
if ( ! F_46 ( & V_55 -> V_85 , V_86 ) ) {
F_10 ( L_24 , V_11 -> V_12 ) ;
F_18 ( V_87 , & V_11 -> V_88 ) ;
}
snprintf ( V_59 , sizeof( V_59 ) , L_25 ,
F_45 ( V_55 -> V_79 ) ) ;
V_7 = F_47 ( & V_57 , V_59 , & V_11 -> V_24 ) ;
if ( V_7 < 0 ) {
F_5 ( L_26 ,
V_11 -> V_12 , V_7 ) ;
F_21 ( V_36 ) ;
return V_7 ;
}
F_10 ( L_27 , V_11 -> V_12 , V_59 ) ;
F_21 ( V_36 ) ;
if ( V_57 -> V_89 < 644 ) {
F_5 ( L_28 ,
V_11 -> V_12 , V_57 -> V_89 ) ;
V_7 = - V_90 ;
goto V_91;
}
F_18 ( V_92 , & V_5 -> V_8 ) ;
V_7 = F_48 ( V_11 , 0x00 , 128 , V_57 -> V_74 ) ;
if ( V_7 < 0 ) {
F_5 ( L_29 ,
V_11 -> V_12 , V_7 ) ;
goto V_91;
}
V_7 = F_48 ( V_11 , 0x03 , 256 , V_57 -> V_74 + 128 ) ;
if ( V_7 < 0 ) {
F_5 ( L_30 ,
V_11 -> V_12 , V_7 ) ;
goto V_91;
}
V_7 = F_48 ( V_11 , 0x02 , 256 , V_57 -> V_74 + 388 ) ;
if ( V_7 < 0 ) {
F_5 ( L_31 ,
V_11 -> V_12 , V_7 ) ;
goto V_91;
}
V_58 = V_57 -> V_74 + 644 ;
V_60 = 0 ;
while ( V_58 - V_57 -> V_74 < V_57 -> V_89 ) {
struct V_93 * V_94 = ( void * ) ( V_58 + V_60 ) ;
V_60 += sizeof( * V_94 ) + V_94 -> V_43 ;
F_15 ( L_32 , V_11 -> V_12 ,
( V_58 - V_57 -> V_74 ) , V_57 -> V_89 ) ;
if ( V_60 % 4 )
continue;
V_7 = F_48 ( V_11 , 0x01 , V_60 , V_58 ) ;
if ( V_7 < 0 ) {
F_5 ( L_33 ,
V_11 -> V_12 , V_7 ) ;
goto V_91;
}
V_58 += V_60 ;
V_60 = 0 ;
}
F_18 ( V_95 , & V_5 -> V_8 ) ;
F_10 ( L_34 , V_11 -> V_12 ) ;
V_7 = F_3 ( & V_5 -> V_8 , V_92 ,
V_10 ,
F_4 ( 5000 ) ) ;
if ( V_7 == 1 ) {
F_5 ( L_35 , V_11 -> V_12 ) ;
V_7 = - V_13 ;
goto V_91;
}
if ( V_7 ) {
F_5 ( L_36 , V_11 -> V_12 ) ;
V_7 = - V_14 ;
goto V_91;
}
if ( F_49 ( V_96 , & V_5 -> V_8 ) ) {
F_5 ( L_37 , V_11 -> V_12 ) ;
V_7 = - V_97 ;
goto V_91;
}
V_63 = F_41 () ;
V_62 = F_50 ( V_63 , V_61 ) ;
V_64 = ( unsigned long long ) F_51 ( V_62 ) >> 10 ;
F_10 ( L_38 , V_11 -> V_12 , V_64 ) ;
V_91:
F_52 ( V_57 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_67 ) {
V_7 = F_30 ( V_3 , V_65 ) ;
if ( V_7 )
return V_7 ;
}
V_61 = F_41 () ;
F_18 ( V_9 , & V_5 -> V_8 ) ;
V_36 = F_32 ( V_11 , 0xfc01 , sizeof( V_51 ) , V_51 ,
V_49 ) ;
if ( F_33 ( V_36 ) )
return F_34 ( V_36 ) ;
F_21 ( V_36 ) ;
F_10 ( L_39 , V_11 -> V_12 ) ;
V_7 = F_2 ( V_3 ) ;
if ( V_7 )
return V_7 ;
F_31 ( V_9 , & V_5 -> V_8 ) ;
V_63 = F_41 () ;
V_62 = F_50 ( V_63 , V_61 ) ;
V_64 = ( unsigned long long ) F_51 ( V_62 ) >> 10 ;
F_10 ( L_40 , V_11 -> V_12 , V_64 ) ;
V_36 = F_32 ( V_11 , V_98 , 0 , NULL , V_99 ) ;
if ( F_33 ( V_36 ) )
return F_34 ( V_36 ) ;
F_21 ( V_36 ) ;
if ( V_67 ) {
V_7 = F_30 ( V_3 , V_66 ) ;
if ( V_7 )
return V_7 ;
}
F_10 ( L_41 , V_11 -> V_12 ) ;
F_31 ( V_71 , & V_5 -> V_8 ) ;
return 0 ;
}
static int F_53 ( struct V_33 * V_11 , struct V_35 * V_36 )
{
struct V_2 * V_3 = F_54 ( V_11 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_37 * V_38 ;
if ( ! F_49 ( V_71 , & V_5 -> V_8 ) &&
! F_49 ( V_9 , & V_5 -> V_8 ) )
goto V_100;
V_38 = ( void * ) V_36 -> V_74 ;
if ( V_36 -> V_72 == 7 && V_38 -> V_40 == 0xff && V_38 -> V_43 == 0x05 &&
V_36 -> V_74 [ 2 ] == 0x06 ) {
if ( V_36 -> V_74 [ 3 ] != 0x00 )
F_18 ( V_96 , & V_5 -> V_8 ) ;
if ( F_55 ( V_92 , & V_5 -> V_8 ) &&
F_49 ( V_95 , & V_5 -> V_8 ) ) {
F_56 () ;
F_57 ( & V_5 -> V_8 , V_92 ) ;
}
} else if ( V_36 -> V_72 == 9 && V_38 -> V_40 == 0xff && V_38 -> V_43 == 0x07 &&
V_36 -> V_74 [ 2 ] == 0x02 ) {
if ( F_55 ( V_9 , & V_5 -> V_8 ) ) {
F_56 () ;
F_57 ( & V_5 -> V_8 , V_9 ) ;
}
}
V_100:
return F_29 ( V_11 , V_36 ) ;
}
static int F_58 ( struct V_2 * V_3 , const void * V_74 , int V_101 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( ! F_49 ( V_102 , & V_3 -> V_8 ) )
return - V_103 ;
V_5 -> V_32 = F_59 ( V_3 -> V_11 , V_5 -> V_32 , V_74 , V_101 ,
V_104 ,
F_60 ( V_104 ) ) ;
if ( F_33 ( V_5 -> V_32 ) ) {
int V_7 = F_34 ( V_5 -> V_32 ) ;
F_5 ( L_42 , V_3 -> V_11 -> V_12 , V_7 ) ;
V_5 -> V_32 = NULL ;
return V_7 ;
}
return V_101 ;
}
static int F_61 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_15 ( L_43 , V_3 , V_36 ) ;
F_36 ( & V_5 -> V_31 , V_36 ) ;
return 0 ;
}
static struct V_35 * F_62 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_35 * V_36 ;
V_36 = F_63 ( & V_5 -> V_31 ) ;
if ( ! V_36 )
return V_36 ;
if ( F_49 ( V_71 , & V_5 -> V_8 ) &&
( F_28 ( V_36 ) -> V_45 == V_50 ) ) {
struct V_93 * V_94 = ( void * ) V_36 -> V_74 ;
T_2 V_34 = F_45 ( V_94 -> V_34 ) ;
if ( V_34 == 0xfc01 )
F_24 ( V_3 -> V_11 , V_34 ) ;
}
memcpy ( F_64 ( V_36 , 1 ) , & F_28 ( V_36 ) -> V_45 , 1 ) ;
return V_36 ;
}
static int F_65 ( struct V_20 * V_21 )
{
const struct V_105 * V_106 ;
V_106 = F_66 ( V_107 , & V_21 -> V_26 -> V_24 ) ;
if ( ! V_106 )
return - V_18 ;
return 0 ;
}
static int F_65 ( struct V_20 * V_21 )
{
return - V_18 ;
}
static int F_67 ( struct V_108 * V_26 )
{
struct V_20 * V_21 ;
V_21 = F_68 ( & V_26 -> V_24 , sizeof( * V_21 ) , V_29 ) ;
if ( ! V_21 )
return - V_30 ;
V_21 -> V_26 = V_26 ;
if ( F_69 ( & V_26 -> V_24 ) ) {
int V_7 = F_65 ( V_21 ) ;
if ( V_7 )
return V_7 ;
} else {
return - V_18 ;
}
V_21 -> V_27 = F_70 ( & V_26 -> V_24 , L_44 ,
V_109 ) ;
if ( F_33 ( V_21 -> V_27 ) ) {
F_71 ( & V_26 -> V_24 , L_45 ) ;
return F_34 ( V_21 -> V_27 ) ;
}
F_72 ( V_26 , V_21 ) ;
F_7 ( & V_19 ) ;
F_73 ( & V_21 -> V_22 , & V_110 ) ;
F_13 ( & V_19 ) ;
F_74 ( & V_26 -> V_24 , L_46 ) ;
return 0 ;
}
static int F_75 ( struct V_108 * V_26 )
{
struct V_20 * V_21 = F_76 ( V_26 ) ;
F_7 ( & V_19 ) ;
F_77 ( & V_21 -> V_22 ) ;
F_13 ( & V_19 ) ;
F_74 ( & V_26 -> V_24 , L_47 ) ;
return 0 ;
}
int T_5 F_78 ( void )
{
F_79 ( & V_111 ) ;
return F_80 ( & V_112 ) ;
}
int T_6 F_81 ( void )
{
F_82 ( & V_111 ) ;
return F_83 ( & V_112 ) ;
}
