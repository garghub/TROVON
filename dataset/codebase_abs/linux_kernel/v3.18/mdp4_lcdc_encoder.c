static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
struct V_10 * V_6 = V_9 -> V_11 . V_6 ;
struct V_12 * V_13 = F_5 ( L_1 ) ;
if ( ! V_13 ) {
F_6 ( V_6 -> V_6 , L_2 ) ;
return;
}
if ( V_13 -> V_14 ) {
V_9 -> V_15 = F_7 (
V_13 -> V_14 ) ;
F_8 ( L_3 , V_9 -> V_15 ) ;
}
}
static void F_9 ( struct V_9 * V_9 )
{
if ( V_9 -> V_15 ) {
F_10 ( V_9 -> V_15 ) ;
V_9 -> V_15 = 0 ;
}
}
static void F_11 ( struct V_9 * V_9 , int V_16 )
{
if ( V_9 -> V_15 ) {
F_8 ( L_4 , V_16 ) ;
F_12 ( V_9 -> V_15 , V_16 ) ;
}
}
static void F_4 ( struct V_9 * V_9 ) {}
static void F_9 ( struct V_9 * V_9 ) {}
static void F_11 ( struct V_9 * V_9 , int V_16 ) {}
static void F_13 ( struct V_2 * V_3 )
{
struct V_9 * V_9 =
F_14 ( V_3 ) ;
F_9 ( V_9 ) ;
F_15 ( V_3 ) ;
F_16 ( V_9 ) ;
}
struct V_17 * F_17 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_17 * V_18 ;
F_18 (connector, &dev->mode_config.connector_list, head)
if ( V_18 -> V_3 == V_3 )
return V_18 ;
return NULL ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_17 * V_18 = F_17 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_19 = 0 , V_20 = 0 ;
int V_21 , V_22 , V_23 ;
if ( ! V_18 )
return;
V_21 = 3 * V_18 -> V_24 . V_25 ;
if ( ! V_21 )
V_21 = 18 ;
V_22 = 1 ;
V_23 = 0 ;
switch ( V_21 ) {
case 24 :
F_20 ( V_1 , F_21 ( 0 ) ,
F_22 ( 0x08 ) |
F_23 ( 0x05 ) |
F_24 ( 0x04 ) |
F_25 ( 0x03 ) ) ;
F_20 ( V_1 , F_26 ( 0 ) ,
F_27 ( 0x02 ) |
F_28 ( 0x01 ) |
F_29 ( 0x00 ) ) ;
F_20 ( V_1 , F_21 ( 1 ) ,
F_22 ( 0x11 ) |
F_23 ( 0x10 ) |
F_24 ( 0x0d ) |
F_25 ( 0x0c ) ) ;
F_20 ( V_1 , F_26 ( 1 ) ,
F_27 ( 0x0b ) |
F_28 ( 0x0a ) |
F_29 ( 0x09 ) ) ;
F_20 ( V_1 , F_21 ( 2 ) ,
F_22 ( 0x1a ) |
F_23 ( 0x19 ) |
F_24 ( 0x18 ) |
F_25 ( 0x15 ) ) ;
F_20 ( V_1 , F_26 ( 2 ) ,
F_27 ( 0x14 ) |
F_28 ( 0x13 ) |
F_29 ( 0x12 ) ) ;
F_20 ( V_1 , F_21 ( 3 ) ,
F_22 ( 0x1b ) |
F_23 ( 0x17 ) |
F_24 ( 0x16 ) |
F_25 ( 0x0f ) ) ;
F_20 ( V_1 , F_26 ( 3 ) ,
F_27 ( 0x0e ) |
F_28 ( 0x07 ) |
F_29 ( 0x06 ) ) ;
if ( V_22 == 2 ) {
V_19 |= V_26 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 ;
} else {
V_19 |= V_30 |
V_31 |
V_32 |
V_33 ;
}
break;
case 18 :
F_20 ( V_1 , F_21 ( 0 ) ,
F_22 ( 0x0a ) |
F_23 ( 0x07 ) |
F_24 ( 0x06 ) |
F_25 ( 0x05 ) ) ;
F_20 ( V_1 , F_26 ( 0 ) ,
F_27 ( 0x04 ) |
F_28 ( 0x03 ) |
F_29 ( 0x02 ) ) ;
F_20 ( V_1 , F_21 ( 1 ) ,
F_22 ( 0x13 ) |
F_23 ( 0x12 ) |
F_24 ( 0x0f ) |
F_25 ( 0x0e ) ) ;
F_20 ( V_1 , F_26 ( 1 ) ,
F_27 ( 0x0d ) |
F_28 ( 0x0c ) |
F_29 ( 0x0b ) ) ;
F_20 ( V_1 , F_21 ( 2 ) ,
F_22 ( 0x1a ) |
F_23 ( 0x19 ) |
F_24 ( 0x18 ) |
F_25 ( 0x17 ) ) ;
F_20 ( V_1 , F_26 ( 2 ) ,
F_27 ( 0x16 ) |
F_28 ( 0x15 ) |
F_29 ( 0x14 ) ) ;
if ( V_22 == 2 ) {
V_19 |= V_27 |
V_28 |
V_29 |
V_31 |
V_32 |
V_33 ;
} else {
V_19 |= V_31 |
V_32 |
V_33 ;
}
V_19 |= V_34 ;
break;
default:
F_6 ( V_6 -> V_6 , L_5 , V_21 ) ;
return;
}
switch ( V_22 ) {
case 1 :
V_20 = V_35 ;
V_19 |= V_36 |
V_37 ;
break;
case 2 :
V_20 = V_35 |
V_38 ;
V_19 |= V_39 |
V_36 ;
break;
default:
F_6 ( V_6 -> V_6 , L_6 , V_22 ) ;
return;
}
if ( V_23 )
V_19 |= V_40 ;
V_19 |= V_41 ;
F_20 ( V_1 , V_42 , V_20 ) ;
F_20 ( V_1 , V_43 , V_19 ) ;
F_20 ( V_1 , V_44 , 0x30 ) ;
F_30 () ;
F_31 ( 1 ) ;
V_20 |= V_45 ;
F_20 ( V_1 , V_42 , V_20 ) ;
}
static void F_32 ( struct V_2 * V_3 , int V_46 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 =
F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_47 * V_48 = V_9 -> V_48 ;
bool V_49 = ( V_46 == V_50 ) ;
int V_51 , V_52 ;
F_8 ( L_7 , V_46 ) ;
if ( V_49 == V_9 -> V_49 )
return;
if ( V_49 ) {
unsigned long V_53 = V_9 -> V_54 ;
int V_52 ;
F_11 ( V_9 , 1 ) ;
for ( V_51 = 0 ; V_51 < F_33 ( V_9 -> V_55 ) ; V_51 ++ ) {
V_52 = F_34 ( V_9 -> V_55 [ V_51 ] ) ;
if ( V_52 )
F_6 ( V_6 -> V_6 , L_8 , V_52 ) ;
}
F_8 ( L_9 , V_53 ) ;
V_52 = F_35 ( V_9 -> V_56 , V_53 ) ;
if ( V_52 )
F_6 ( V_6 -> V_6 , L_10 , V_52 ) ;
V_52 = F_36 ( V_9 -> V_56 ) ;
if ( V_52 )
F_6 ( V_6 -> V_6 , L_11 , V_52 ) ;
if ( V_48 )
F_37 ( V_48 ) ;
F_19 ( V_3 ) ;
F_20 ( V_1 , V_57 , 1 ) ;
} else {
F_20 ( V_1 , V_57 , 0 ) ;
if ( V_48 )
F_38 ( V_48 ) ;
F_39 ( & V_1 -> V_11 , V_58 ) ;
F_40 ( V_9 -> V_56 ) ;
for ( V_51 = 0 ; V_51 < F_33 ( V_9 -> V_55 ) ; V_51 ++ ) {
V_52 = F_41 ( V_9 -> V_55 [ V_51 ] ) ;
if ( V_52 )
F_6 ( V_6 -> V_6 , L_12 , V_52 ) ;
}
F_11 ( V_9 , 0 ) ;
}
V_9 -> V_49 = V_49 ;
}
static bool F_42 ( struct V_2 * V_3 ,
const struct V_59 * V_46 ,
struct V_59 * V_60 )
{
return true ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_59 * V_46 ,
struct V_59 * V_60 )
{
struct V_9 * V_9 =
F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_61 , V_62 , V_63 , V_64 ;
T_1 V_65 , V_66 ;
T_1 V_67 , V_68 ;
V_46 = V_60 ;
F_8 ( L_13 ,
V_46 -> V_11 . V_69 , V_46 -> V_70 ,
V_46 -> V_71 , V_46 -> clock ,
V_46 -> V_72 , V_46 -> V_73 ,
V_46 -> V_74 , V_46 -> V_75 ,
V_46 -> V_76 , V_46 -> V_77 ,
V_46 -> V_78 , V_46 -> V_79 ,
V_46 -> type , V_46 -> V_80 ) ;
V_9 -> V_54 = V_46 -> clock * 1000 ;
F_8 ( L_14 , V_9 -> V_54 ) ;
V_64 = 0 ;
if ( V_46 -> V_80 & V_81 )
V_64 |= V_82 ;
if ( V_46 -> V_80 & V_83 )
V_64 |= V_84 ;
V_61 = 0 ;
V_67 = ( V_46 -> V_75 - V_46 -> V_73 ) ;
V_68 = V_46 -> V_75 - ( V_46 -> V_73 - V_46 -> V_72 ) - 1 ;
V_62 = V_46 -> V_79 * V_46 -> V_75 ;
V_63 = ( V_46 -> V_78 - V_46 -> V_77 ) * V_46 -> V_75 ;
V_65 = ( V_46 -> V_79 - V_46 -> V_77 ) * V_46 -> V_75 + V_61 ;
V_66 = V_62 - ( ( V_46 -> V_77 - V_46 -> V_76 ) * V_46 -> V_75 ) + V_61 - 1 ;
F_20 ( V_1 , V_85 ,
F_44 ( V_46 -> V_74 - V_46 -> V_73 ) |
F_45 ( V_46 -> V_75 ) ) ;
F_20 ( V_1 , V_86 , V_62 ) ;
F_20 ( V_1 , V_87 , V_63 ) ;
F_20 ( V_1 , V_88 ,
F_46 ( V_67 ) |
F_47 ( V_68 ) ) ;
F_20 ( V_1 , V_89 , V_65 ) ;
F_20 ( V_1 , V_90 , V_66 ) ;
F_20 ( V_1 , V_91 , 0 ) ;
F_20 ( V_1 , V_92 ,
V_93 |
F_48 ( 0xff ) ) ;
F_20 ( V_1 , V_94 , V_61 ) ;
F_20 ( V_1 , V_95 , V_64 ) ;
F_20 ( V_1 , V_96 ,
F_49 ( 0 ) |
F_50 ( 0 ) ) ;
F_20 ( V_1 , V_97 , 0 ) ;
F_20 ( V_1 , V_98 , 0 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_32 ( V_3 , V_99 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
F_53 ( V_3 -> V_100 ,
F_54 ( V_101 ) |
F_55 ( V_101 ) |
F_56 ( V_101 ) |
V_102 |
F_57 ( 0x21 ) |
V_103 |
V_104 ) ;
F_58 ( V_3 -> V_100 , V_105 , 0 ) ;
F_32 ( V_3 , V_50 ) ;
}
long F_59 ( struct V_2 * V_3 , unsigned long V_106 )
{
struct V_9 * V_9 =
F_14 ( V_3 ) ;
return F_60 ( V_9 -> V_56 , V_106 ) ;
}
struct V_2 * F_61 ( struct V_10 * V_6 ,
struct V_47 * V_48 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
struct V_107 * V_108 ;
int V_52 ;
V_9 = F_62 ( sizeof( * V_9 ) , V_109 ) ;
if ( ! V_9 ) {
V_52 = - V_110 ;
goto V_111;
}
V_9 -> V_48 = V_48 ;
V_3 = & V_9 -> V_11 ;
F_63 ( V_6 , V_3 , & V_112 ,
V_113 ) ;
F_64 ( V_3 , & V_114 ) ;
V_9 -> V_56 = F_65 ( V_6 ) ;
if ( F_66 ( V_9 -> V_56 ) ) {
F_6 ( V_6 -> V_6 , L_15 ) ;
V_52 = F_67 ( V_9 -> V_56 ) ;
goto V_111;
}
V_108 = F_68 ( V_6 -> V_6 , L_16 ) ;
if ( F_66 ( V_108 ) ) {
V_52 = F_67 ( V_108 ) ;
F_6 ( V_6 -> V_6 , L_17 , V_52 ) ;
goto V_111;
}
V_9 -> V_55 [ 0 ] = V_108 ;
V_108 = F_68 ( V_6 -> V_6 , L_18 ) ;
if ( F_66 ( V_108 ) ) {
V_52 = F_67 ( V_108 ) ;
F_6 ( V_6 -> V_6 , L_19 , V_52 ) ;
goto V_111;
}
V_9 -> V_55 [ 1 ] = V_108 ;
V_108 = F_68 ( V_6 -> V_6 , L_20 ) ;
if ( F_66 ( V_108 ) ) {
V_52 = F_67 ( V_108 ) ;
F_6 ( V_6 -> V_6 , L_21 , V_52 ) ;
goto V_111;
}
V_9 -> V_55 [ 2 ] = V_108 ;
F_4 ( V_9 ) ;
return V_3 ;
V_111:
if ( V_3 )
F_13 ( V_3 ) ;
return F_69 ( V_52 ) ;
}
