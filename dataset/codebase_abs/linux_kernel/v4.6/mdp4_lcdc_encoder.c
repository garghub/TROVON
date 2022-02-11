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
static void F_32 ( struct V_2 * V_3 ,
struct V_46 * V_47 ,
struct V_46 * V_48 )
{
struct V_9 * V_9 =
F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_49 , V_50 , V_51 , V_52 ;
T_1 V_53 , V_54 ;
T_1 V_55 , V_56 ;
V_47 = V_48 ;
F_8 ( L_7 ,
V_47 -> V_11 . V_57 , V_47 -> V_58 ,
V_47 -> V_59 , V_47 -> clock ,
V_47 -> V_60 , V_47 -> V_61 ,
V_47 -> V_62 , V_47 -> V_63 ,
V_47 -> V_64 , V_47 -> V_65 ,
V_47 -> V_66 , V_47 -> V_67 ,
V_47 -> type , V_47 -> V_68 ) ;
V_9 -> V_69 = V_47 -> clock * 1000 ;
F_8 ( L_8 , V_9 -> V_69 ) ;
V_52 = 0 ;
if ( V_47 -> V_68 & V_70 )
V_52 |= V_71 ;
if ( V_47 -> V_68 & V_72 )
V_52 |= V_73 ;
V_49 = 0 ;
V_55 = ( V_47 -> V_63 - V_47 -> V_61 ) ;
V_56 = V_47 -> V_63 - ( V_47 -> V_61 - V_47 -> V_60 ) - 1 ;
V_50 = V_47 -> V_67 * V_47 -> V_63 ;
V_51 = ( V_47 -> V_66 - V_47 -> V_65 ) * V_47 -> V_63 ;
V_53 = ( V_47 -> V_67 - V_47 -> V_65 ) * V_47 -> V_63 + V_49 ;
V_54 = V_50 - ( ( V_47 -> V_65 - V_47 -> V_64 ) * V_47 -> V_63 ) + V_49 - 1 ;
F_20 ( V_1 , V_74 ,
F_33 ( V_47 -> V_62 - V_47 -> V_61 ) |
F_34 ( V_47 -> V_63 ) ) ;
F_20 ( V_1 , V_75 , V_50 ) ;
F_20 ( V_1 , V_76 , V_51 ) ;
F_20 ( V_1 , V_77 ,
F_35 ( V_55 ) |
F_36 ( V_56 ) ) ;
F_20 ( V_1 , V_78 , V_53 ) ;
F_20 ( V_1 , V_79 , V_54 ) ;
F_20 ( V_1 , V_80 , 0 ) ;
F_20 ( V_1 , V_81 ,
V_82 |
F_37 ( 0xff ) ) ;
F_20 ( V_1 , V_83 , V_49 ) ;
F_20 ( V_1 , V_84 , V_52 ) ;
F_20 ( V_1 , V_85 ,
F_38 ( 0 ) |
F_39 ( 0 ) ) ;
F_20 ( V_1 , V_86 , 0 ) ;
F_20 ( V_1 , V_87 , 0 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 =
F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_88 * V_89 ;
int V_90 , V_91 ;
if ( F_41 ( ! V_9 -> V_92 ) )
return;
F_20 ( V_1 , V_93 , 0 ) ;
V_89 = F_42 ( V_9 -> V_94 ) ;
if ( V_89 ) {
F_43 ( V_89 ) ;
F_44 ( V_89 ) ;
}
F_45 ( & V_1 -> V_11 , V_95 ) ;
F_46 ( V_9 -> V_96 ) ;
for ( V_90 = 0 ; V_90 < F_47 ( V_9 -> V_97 ) ; V_90 ++ ) {
V_91 = F_48 ( V_9 -> V_97 [ V_90 ] ) ;
if ( V_91 )
F_6 ( V_6 -> V_6 , L_9 , V_91 ) ;
}
F_11 ( V_9 , 0 ) ;
V_9 -> V_92 = false ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 =
F_14 ( V_3 ) ;
unsigned long V_98 = V_9 -> V_69 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_88 * V_89 ;
int V_90 , V_91 ;
if ( F_41 ( V_9 -> V_92 ) )
return;
F_50 ( V_3 -> V_99 ,
F_51 ( V_100 ) |
F_52 ( V_100 ) |
F_53 ( V_100 ) |
V_101 |
F_54 ( 0x21 ) |
V_102 |
V_103 ) ;
F_55 ( V_3 -> V_99 , V_104 , 0 ) ;
F_11 ( V_9 , 1 ) ;
for ( V_90 = 0 ; V_90 < F_47 ( V_9 -> V_97 ) ; V_90 ++ ) {
V_91 = F_56 ( V_9 -> V_97 [ V_90 ] ) ;
if ( V_91 )
F_6 ( V_6 -> V_6 , L_10 , V_91 ) ;
}
F_8 ( L_11 , V_98 ) ;
V_91 = F_57 ( V_9 -> V_96 , V_98 ) ;
if ( V_91 )
F_6 ( V_6 -> V_6 , L_12 , V_91 ) ;
V_91 = F_58 ( V_9 -> V_96 ) ;
if ( V_91 )
F_6 ( V_6 -> V_6 , L_13 , V_91 ) ;
V_89 = F_42 ( V_9 -> V_94 ) ;
if ( V_89 ) {
F_59 ( V_89 ) ;
F_60 ( V_89 ) ;
}
F_19 ( V_3 ) ;
F_20 ( V_1 , V_93 , 1 ) ;
V_9 -> V_92 = true ;
}
long F_61 ( struct V_2 * V_3 , unsigned long V_105 )
{
struct V_9 * V_9 =
F_14 ( V_3 ) ;
return F_62 ( V_9 -> V_96 , V_105 ) ;
}
struct V_2 * F_63 ( struct V_10 * V_6 ,
struct V_106 * V_94 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
struct V_107 * V_108 ;
int V_91 ;
V_9 = F_64 ( sizeof( * V_9 ) , V_109 ) ;
if ( ! V_9 ) {
V_91 = - V_110 ;
goto V_111;
}
V_9 -> V_94 = V_94 ;
V_3 = & V_9 -> V_11 ;
F_65 ( V_6 , V_3 , & V_112 ,
V_113 , NULL ) ;
F_66 ( V_3 , & V_114 ) ;
V_9 -> V_96 = F_67 ( V_6 ) ;
if ( F_68 ( V_9 -> V_96 ) ) {
F_6 ( V_6 -> V_6 , L_14 ) ;
V_91 = F_69 ( V_9 -> V_96 ) ;
goto V_111;
}
V_108 = F_70 ( V_6 -> V_6 , L_15 ) ;
if ( F_68 ( V_108 ) ) {
V_91 = F_69 ( V_108 ) ;
F_6 ( V_6 -> V_6 , L_16 , V_91 ) ;
goto V_111;
}
V_9 -> V_97 [ 0 ] = V_108 ;
V_108 = F_70 ( V_6 -> V_6 , L_17 ) ;
if ( F_68 ( V_108 ) ) {
V_91 = F_69 ( V_108 ) ;
F_6 ( V_6 -> V_6 , L_18 , V_91 ) ;
goto V_111;
}
V_9 -> V_97 [ 1 ] = V_108 ;
V_108 = F_70 ( V_6 -> V_6 , L_19 ) ;
if ( F_68 ( V_108 ) ) {
V_91 = F_69 ( V_108 ) ;
F_6 ( V_6 -> V_6 , L_20 , V_91 ) ;
goto V_111;
}
V_9 -> V_97 [ 2 ] = V_108 ;
F_4 ( V_9 ) ;
return V_3 ;
V_111:
if ( V_3 )
F_13 ( V_3 ) ;
return F_71 ( V_91 ) ;
}
