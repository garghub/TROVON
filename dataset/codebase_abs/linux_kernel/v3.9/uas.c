static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_4 -> V_7 |= V_8 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
if ( V_4 -> V_9 )
F_4 ( V_4 -> V_9 ) ;
if ( V_4 -> V_10 )
F_4 ( V_4 -> V_10 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_4 -> V_7 &= ~ V_8 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static void F_5 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_3 * V_13 ;
struct V_14 V_15 ;
unsigned long V_5 ;
int V_16 ;
F_6 ( & V_17 ) ;
F_7 ( & V_18 , & V_15 ) ;
F_8 ( & V_17 ) ;
F_9 (cmdinfo, temp, &list, list) {
struct V_19 * V_20 = ( void * ) V_4 ;
struct V_21 * V_22 = F_10 ( V_20 ,
struct V_21 , V_23 ) ;
struct V_1 * V_2 = ( void * ) V_22 -> V_24 -> V_25 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_16 = F_11 ( V_22 , V_22 -> V_24 -> V_25 , V_26 ) ;
if ( ! V_16 )
V_4 -> V_7 &= ~ V_27 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
if ( V_16 ) {
F_12 ( & V_4 -> V_15 ) ;
F_6 ( & V_17 ) ;
F_13 ( & V_4 -> V_15 , & V_18 ) ;
F_8 ( & V_17 ) ;
F_14 ( & V_28 ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_13 ;
struct V_14 V_15 ;
unsigned long V_5 ;
F_6 ( & V_17 ) ;
F_7 ( & V_18 , & V_15 ) ;
F_8 ( & V_17 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_9 (cmdinfo, temp, &list, list) {
struct V_19 * V_20 = ( void * ) V_4 ;
struct V_21 * V_22 = F_10 ( V_20 ,
struct V_21 , V_23 ) ;
struct V_1 * V_29 = ( void * ) V_22 -> V_24 -> V_25 ;
if ( V_29 == V_2 ) {
V_4 -> V_7 |= V_30 ;
V_4 -> V_7 &= ~ V_27 ;
if ( V_2 -> V_31 ) {
V_4 -> V_7 &= ~ V_32 ;
}
F_16 ( V_22 , V_33 ) ;
} else {
F_12 ( & V_4 -> V_15 ) ;
F_6 ( & V_17 ) ;
F_13 ( & V_4 -> V_15 , & V_18 ) ;
F_8 ( & V_17 ) ;
}
}
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static void F_17 ( struct V_34 * V_34 , struct V_21 * V_22 )
{
struct V_35 * V_35 = V_34 -> V_36 ;
struct V_37 * V_38 = V_22 -> V_24 ;
if ( V_34 -> V_39 > 16 ) {
unsigned V_40 = F_18 ( & V_35 -> V_40 ) ;
if ( V_40 + 16 != V_34 -> V_39 ) {
int V_41 = F_19 ( V_40 + 16 , V_34 -> V_39 ) - 16 ;
if ( V_41 < 0 )
V_41 = 0 ;
F_20 ( V_42 , V_38 , L_1
L_2
L_3 , V_33 ,
V_34 -> V_39 , V_40 , V_41 ) ;
V_40 = V_41 ;
}
memcpy ( V_22 -> V_43 , V_35 -> V_44 , V_40 ) ;
}
V_22 -> V_45 = V_35 -> V_46 ;
}
static void F_21 ( struct V_34 * V_34 , struct V_21 * V_22 )
{
struct V_47 * V_35 = V_34 -> V_36 ;
struct V_37 * V_38 = V_22 -> V_24 ;
if ( V_34 -> V_39 > 8 ) {
unsigned V_40 = F_18 ( & V_35 -> V_40 ) - 2 ;
if ( V_40 + 8 != V_34 -> V_39 ) {
int V_41 = F_19 ( V_40 + 8 , V_34 -> V_39 ) - 8 ;
if ( V_41 < 0 )
V_41 = 0 ;
F_20 ( V_42 , V_38 , L_1
L_2
L_3 , V_33 ,
V_34 -> V_39 , V_40 , V_41 ) ;
V_40 = V_41 ;
}
memcpy ( V_22 -> V_43 , V_35 -> V_44 , V_40 ) ;
}
V_22 -> V_45 = V_35 -> V_46 ;
}
static void F_22 ( struct V_21 * V_22 , const char * V_48 )
{
struct V_3 * V_49 = ( void * ) & V_22 -> V_23 ;
F_23 ( V_42 , V_22 , L_4
L_5 ,
V_48 , V_22 , V_22 -> V_50 -> V_51 ,
( V_49 -> V_7 & V_52 ) ? L_6 : L_7 ,
( V_49 -> V_7 & V_53 ) ? L_8 : L_7 ,
( V_49 -> V_7 & V_54 ) ? L_9 : L_7 ,
( V_49 -> V_7 & V_55 ) ? L_10 : L_7 ,
( V_49 -> V_7 & V_56 ) ? L_11 : L_7 ,
( V_49 -> V_7 & V_57 ) ? L_12 : L_7 ,
( V_49 -> V_7 & V_58 ) ? L_13 : L_7 ,
( V_49 -> V_7 & V_32 ) ? L_14 : L_7 ,
( V_49 -> V_7 & V_59 ) ? L_15 : L_7 ,
( V_49 -> V_7 & V_60 ) ? L_16 : L_7 ,
( V_49 -> V_7 & V_61 ) ? L_17 : L_7 ,
( V_49 -> V_7 & V_30 ) ? L_18 : L_7 ,
( V_49 -> V_7 & V_8 ) ? L_19 : L_7 ,
( V_49 -> V_7 & V_27 ) ? L_20 : L_7 ) ;
}
static int F_16 ( struct V_21 * V_22 , const char * V_48 )
{
struct V_3 * V_4 = ( void * ) & V_22 -> V_23 ;
struct V_1 * V_2 = ( void * ) V_22 -> V_24 -> V_25 ;
F_24 ( ! F_25 ( & V_2 -> V_6 ) ) ;
if ( V_4 -> V_7 & ( V_32 |
V_59 |
V_60 |
V_8 ) )
return - V_62 ;
F_26 ( V_4 -> V_7 & V_61 ) ;
V_4 -> V_7 |= V_61 ;
F_27 ( V_4 -> V_9 ) ;
F_27 ( V_4 -> V_10 ) ;
if ( V_4 -> V_7 & V_30 ) {
F_23 ( V_42 , V_22 , L_21 ) ;
V_22 -> V_45 = V_63 << 16 ;
}
V_22 -> V_64 ( V_22 ) ;
return 0 ;
}
static void F_28 ( struct V_34 * V_34 , struct V_21 * V_22 ,
unsigned V_65 )
{
struct V_3 * V_4 = ( void * ) & V_22 -> V_23 ;
int V_16 ;
V_4 -> V_7 |= V_65 | V_52 ;
V_16 = F_11 ( V_22 , V_22 -> V_24 -> V_25 , V_26 ) ;
if ( V_16 ) {
F_29 ( & V_17 ) ;
F_13 ( & V_4 -> V_15 , & V_18 ) ;
V_4 -> V_7 |= V_27 ;
F_30 ( & V_17 ) ;
F_14 ( & V_28 ) ;
}
}
static void F_31 ( struct V_34 * V_34 )
{
struct V_66 * V_66 = V_34 -> V_36 ;
struct V_67 * V_68 = V_34 -> V_69 ;
struct V_1 * V_2 = ( void * ) V_68 -> V_25 [ 0 ] ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
unsigned long V_5 ;
T_1 V_51 ;
if ( V_34 -> V_46 ) {
F_32 ( & V_34 -> V_70 -> V_70 , L_22 , V_34 -> V_46 ) ;
F_27 ( V_34 ) ;
return;
}
if ( V_2 -> V_31 ) {
F_27 ( V_34 ) ;
return;
}
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_51 = F_18 ( & V_66 -> V_51 ) - 1 ;
if ( V_51 == 0 )
V_22 = V_2 -> V_22 ;
else
V_22 = F_33 ( V_68 , V_51 - 1 ) ;
if ( ! V_22 ) {
if ( V_66 -> V_71 == V_72 ) {
memcpy ( & V_2 -> V_73 , V_66 , sizeof( V_2 -> V_73 ) ) ;
}
F_27 ( V_34 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
return;
}
V_4 = ( void * ) & V_22 -> V_23 ;
switch ( V_66 -> V_71 ) {
case V_74 :
if ( V_2 -> V_22 == V_22 )
V_2 -> V_22 = NULL ;
if ( V_34 -> V_39 < 16 )
V_2 -> F_21 = 1 ;
if ( V_2 -> F_21 )
F_21 ( V_34 , V_22 ) ;
else
F_17 ( V_34 , V_22 ) ;
if ( V_22 -> V_45 != 0 ) {
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
}
V_4 -> V_7 &= ~ V_32 ;
F_16 ( V_22 , V_33 ) ;
break;
case V_75 :
F_28 ( V_34 , V_22 , V_54 ) ;
break;
case V_76 :
F_28 ( V_34 , V_22 , V_56 ) ;
break;
default:
F_23 ( V_77 , V_22 ,
L_23 , V_66 -> V_71 ) ;
}
F_27 ( V_34 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static void F_34 ( struct V_34 * V_34 )
{
struct V_21 * V_22 = V_34 -> V_69 ;
struct V_3 * V_4 = ( void * ) & V_22 -> V_23 ;
struct V_1 * V_2 = ( void * ) V_22 -> V_24 -> V_25 ;
struct V_78 * V_79 = NULL ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( V_4 -> V_9 == V_34 ) {
V_79 = F_35 ( V_22 ) ;
V_4 -> V_7 &= ~ V_59 ;
} else if ( V_4 -> V_10 == V_34 ) {
V_79 = F_36 ( V_22 ) ;
V_4 -> V_7 &= ~ V_60 ;
}
F_26 ( V_79 == NULL ) ;
if ( V_34 -> V_46 ) {
V_79 -> V_80 = V_79 -> V_81 ;
} else {
V_79 -> V_80 = V_79 -> V_81 - V_34 -> V_39 ;
}
F_16 ( V_22 , V_33 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
static struct V_34 * F_37 ( struct V_1 * V_2 , T_2 V_82 ,
unsigned int V_83 , T_1 V_84 ,
struct V_21 * V_22 ,
enum V_85 V_86 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_34 * V_34 = F_38 ( 0 , V_82 ) ;
struct V_78 * V_79 = ( V_86 == V_89 )
? F_35 ( V_22 ) : F_36 ( V_22 ) ;
if ( ! V_34 )
goto V_90;
F_39 ( V_34 , V_88 , V_83 , NULL , V_79 -> V_81 ,
F_34 , V_22 ) ;
if ( V_2 -> V_91 )
V_34 -> V_84 = V_84 ;
V_34 -> V_92 = V_88 -> V_93 -> V_94 ? V_79 -> V_95 . V_96 : 0 ;
V_34 -> V_97 = V_79 -> V_95 . V_98 ;
V_90:
return V_34 ;
}
static struct V_34 * F_40 ( struct V_1 * V_2 , T_2 V_82 ,
struct V_67 * V_68 , T_1 V_84 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_34 * V_34 = F_38 ( 0 , V_82 ) ;
struct V_35 * V_66 ;
if ( ! V_34 )
goto V_90;
V_66 = F_41 ( sizeof( * V_66 ) , V_82 ) ;
if ( ! V_66 )
goto free;
F_39 ( V_34 , V_88 , V_2 -> V_99 , V_66 , sizeof( * V_66 ) ,
F_31 , V_68 ) ;
V_34 -> V_84 = V_84 ;
V_34 -> V_100 |= V_101 ;
V_90:
return V_34 ;
free:
F_27 ( V_34 ) ;
return NULL ;
}
static struct V_34 * F_42 ( struct V_1 * V_2 , T_2 V_82 ,
struct V_21 * V_22 , T_1 V_84 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_37 * V_38 = V_22 -> V_24 ;
struct V_34 * V_34 = F_38 ( 0 , V_82 ) ;
struct V_102 * V_66 ;
int V_40 ;
if ( ! V_34 )
goto V_90;
V_40 = V_22 -> V_103 - 16 ;
if ( V_40 < 0 )
V_40 = 0 ;
V_40 = F_43 ( V_40 , 4 ) ;
V_66 = F_41 ( sizeof( * V_66 ) + V_40 , V_82 ) ;
if ( ! V_66 )
goto free;
V_66 -> V_71 = V_104 ;
if ( F_44 ( V_22 -> V_50 ) )
V_66 -> V_51 = F_45 ( V_22 -> V_50 -> V_51 + 2 ) ;
else
V_66 -> V_51 = F_45 ( 1 ) ;
V_66 -> V_105 = V_106 ;
V_66 -> V_40 = V_40 ;
F_46 ( V_38 -> V_107 , & V_66 -> V_107 ) ;
memcpy ( V_66 -> V_108 , V_22 -> V_22 , V_22 -> V_103 ) ;
F_39 ( V_34 , V_88 , V_2 -> V_109 , V_66 , sizeof( * V_66 ) + V_40 ,
F_27 , NULL ) ;
V_34 -> V_100 |= V_101 ;
V_90:
return V_34 ;
free:
F_27 ( V_34 ) ;
return NULL ;
}
static int F_47 ( struct V_21 * V_22 , T_2 V_82 ,
T_3 V_110 , T_1 V_84 )
{
struct V_1 * V_2 = ( void * ) V_22 -> V_24 -> V_25 ;
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_34 * V_34 = F_38 ( 0 , V_82 ) ;
struct V_111 * V_66 ;
int V_16 = - V_112 ;
if ( ! V_34 )
goto V_16;
V_66 = F_41 ( sizeof( * V_66 ) , V_82 ) ;
if ( ! V_66 )
goto V_16;
V_66 -> V_71 = V_113 ;
V_66 -> V_51 = F_45 ( V_84 ) ;
F_46 ( V_22 -> V_24 -> V_107 , & V_66 -> V_107 ) ;
V_66 -> V_110 = V_110 ;
switch ( V_110 ) {
case V_114 :
if ( F_44 ( V_22 -> V_50 ) )
V_66 -> V_115 = F_45 ( V_22 -> V_50 -> V_51 + 2 ) ;
else
V_66 -> V_115 = F_45 ( 1 ) ;
break;
}
F_39 ( V_34 , V_88 , V_2 -> V_109 , V_66 , sizeof( * V_66 ) ,
F_27 , NULL ) ;
V_34 -> V_100 |= V_101 ;
V_16 = F_48 ( V_34 , V_82 ) ;
if ( V_16 )
goto V_16;
F_49 ( V_34 , & V_2 -> V_116 ) ;
return 0 ;
V_16:
F_27 ( V_34 ) ;
return V_16 ;
}
static int F_50 ( struct V_67 * V_68 ,
T_2 V_82 , unsigned int V_117 )
{
struct V_1 * V_2 = ( void * ) V_68 -> V_25 [ 0 ] ;
struct V_34 * V_34 ;
V_34 = F_40 ( V_2 , V_82 , V_68 , V_117 ) ;
if ( ! V_34 )
return V_118 ;
if ( F_48 ( V_34 , V_82 ) ) {
F_51 ( V_42 , V_68 ,
L_24 ) ;
F_27 ( V_34 ) ;
return V_118 ;
}
F_49 ( V_34 , & V_2 -> V_119 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 ,
struct V_1 * V_2 , T_2 V_82 )
{
struct V_3 * V_4 = ( void * ) & V_22 -> V_23 ;
int V_16 ;
F_24 ( ! F_25 ( & V_2 -> V_6 ) ) ;
if ( V_4 -> V_7 & V_52 ) {
V_16 = F_50 ( V_22 -> V_24 -> V_120 , V_82 ,
V_4 -> V_117 ) ;
if ( V_16 ) {
return V_16 ;
}
V_4 -> V_7 &= ~ V_52 ;
}
if ( V_4 -> V_7 & V_53 ) {
V_4 -> V_9 = F_37 ( V_2 , V_82 ,
V_2 -> V_121 , V_4 -> V_117 ,
V_22 , V_89 ) ;
if ( ! V_4 -> V_9 )
return V_118 ;
V_4 -> V_7 &= ~ V_53 ;
}
if ( V_4 -> V_7 & V_54 ) {
if ( F_48 ( V_4 -> V_9 , V_82 ) ) {
F_23 ( V_42 , V_22 ,
L_25 ) ;
return V_118 ;
}
V_4 -> V_7 &= ~ V_54 ;
V_4 -> V_7 |= V_59 ;
F_49 ( V_4 -> V_9 , & V_2 -> V_122 ) ;
}
if ( V_4 -> V_7 & V_55 ) {
V_4 -> V_10 = F_37 ( V_2 , V_82 ,
V_2 -> V_123 , V_4 -> V_117 ,
V_22 , V_124 ) ;
if ( ! V_4 -> V_10 )
return V_118 ;
V_4 -> V_7 &= ~ V_55 ;
}
if ( V_4 -> V_7 & V_56 ) {
if ( F_48 ( V_4 -> V_10 , V_82 ) ) {
F_23 ( V_42 , V_22 ,
L_26 ) ;
return V_118 ;
}
V_4 -> V_7 &= ~ V_56 ;
V_4 -> V_7 |= V_60 ;
F_49 ( V_4 -> V_10 , & V_2 -> V_122 ) ;
}
if ( V_4 -> V_7 & V_57 ) {
V_4 -> V_125 = F_42 ( V_2 , V_82 , V_22 ,
V_4 -> V_117 ) ;
if ( ! V_4 -> V_125 )
return V_118 ;
V_4 -> V_7 &= ~ V_57 ;
}
if ( V_4 -> V_7 & V_58 ) {
F_52 ( V_4 -> V_125 ) ;
if ( F_48 ( V_4 -> V_125 , V_82 ) ) {
F_23 ( V_42 , V_22 ,
L_27 ) ;
return V_118 ;
}
F_49 ( V_4 -> V_125 , & V_2 -> V_116 ) ;
F_53 ( V_4 -> V_125 ) ;
V_4 -> V_125 = NULL ;
V_4 -> V_7 &= ~ V_58 ;
V_4 -> V_7 |= V_32 ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_22 ,
void (* F_55)( struct V_21 * ) )
{
struct V_37 * V_38 = V_22 -> V_24 ;
struct V_1 * V_2 = V_38 -> V_25 ;
struct V_3 * V_4 = ( void * ) & V_22 -> V_23 ;
unsigned long V_5 ;
int V_16 ;
F_56 ( sizeof( struct V_3 ) > sizeof( struct V_19 ) ) ;
if ( V_2 -> V_31 ) {
V_22 -> V_45 = V_126 << 16 ;
V_22 -> V_64 ( V_22 ) ;
return 0 ;
}
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( V_2 -> V_22 ) {
F_3 ( & V_2 -> V_6 , V_5 ) ;
return V_118 ;
}
if ( F_44 ( V_22 -> V_50 ) ) {
V_4 -> V_117 = V_22 -> V_50 -> V_51 + 2 ;
} else {
V_2 -> V_22 = V_22 ;
V_4 -> V_117 = 1 ;
}
V_22 -> V_64 = F_55 ;
V_4 -> V_7 = V_52 |
V_57 | V_58 ;
switch ( V_22 -> V_127 ) {
case V_89 :
V_4 -> V_7 |= V_53 | V_54 ;
break;
case V_128 :
V_4 -> V_7 |= V_53 | V_54 ;
case V_124 :
V_4 -> V_7 |= V_55 | V_56 ;
case V_129 :
break;
}
if ( ! V_2 -> V_91 ) {
V_4 -> V_7 &= ~ ( V_54 | V_56 ) ;
V_4 -> V_117 = 0 ;
}
V_16 = F_11 ( V_22 , V_2 , V_26 ) ;
if ( V_16 ) {
if ( V_4 -> V_7 & V_52 ) {
F_3 ( & V_2 -> V_6 , V_5 ) ;
return V_118 ;
}
F_29 ( & V_17 ) ;
F_13 ( & V_4 -> V_15 , & V_18 ) ;
V_4 -> V_7 |= V_27 ;
F_30 ( & V_17 ) ;
F_14 ( & V_28 ) ;
}
F_3 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
int F_57 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = ( void * ) & V_22 -> V_23 ;
struct V_1 * V_2 = ( void * ) V_22 -> V_24 -> V_25 ;
unsigned long V_5 ;
int V_130 ;
F_22 ( V_22 , V_33 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_4 -> V_7 |= V_30 ;
if ( V_4 -> V_7 & V_27 ) {
F_29 ( & V_17 ) ;
F_12 ( & V_4 -> V_15 ) ;
V_4 -> V_7 &= ~ V_27 ;
F_30 ( & V_17 ) ;
}
if ( V_4 -> V_7 & V_32 ) {
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_130 = F_58 ( V_22 , L_28 , V_114 ) ;
} else {
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_16 ( V_22 , V_33 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_130 = V_131 ;
}
return V_130 ;
}
static int F_59 ( struct V_21 * V_22 )
{
F_20 ( V_42 , V_22 -> V_24 , L_29 , V_33 ) ;
return F_58 ( V_22 , L_30 ,
V_132 ) ;
}
static int F_60 ( struct V_21 * V_22 )
{
struct V_37 * V_38 = V_22 -> V_24 ;
struct V_1 * V_2 = V_38 -> V_25 ;
struct V_87 * V_88 = V_2 -> V_88 ;
int V_16 ;
V_2 -> V_31 = 1 ;
F_15 ( V_2 ) ;
F_61 ( & V_2 -> V_116 ) ;
F_61 ( & V_2 -> V_119 ) ;
F_61 ( & V_2 -> V_122 ) ;
V_16 = F_62 ( V_88 ) ;
V_2 -> V_31 = 0 ;
if ( V_16 ) {
F_51 ( V_42 , V_38 -> V_120 , L_31 , V_33 ) ;
return V_133 ;
}
F_51 ( V_42 , V_38 -> V_120 , L_32 , V_33 ) ;
return V_131 ;
}
static int F_63 ( struct V_37 * V_38 )
{
V_38 -> V_25 = ( void * ) V_38 -> V_120 -> V_25 [ 0 ] ;
return 0 ;
}
static int F_64 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_25 ;
F_65 ( V_38 , V_134 ) ;
F_66 ( V_38 , V_2 -> V_135 - 3 ) ;
return 0 ;
}
static int F_67 ( struct V_136 * V_137 )
{
return ( V_137 -> V_138 . V_139 == V_140 &&
V_137 -> V_138 . V_141 == V_142 &&
V_137 -> V_138 . V_143 == V_144 ) ;
}
static int F_68 ( struct V_87 * V_88 )
{
struct V_145 * V_146 = F_69 ( V_88 -> V_93 ) ;
F_70 ( & V_88 -> V_70 , L_33
L_34 ,
V_146 -> V_147 -> V_148 ) ;
F_70 ( & V_88 -> V_70 , L_35
L_36 ) ;
return - V_149 ;
}
static int F_71 ( struct V_87 * V_88 ,
struct V_150 * V_137 )
{
int V_151 ;
int V_152 = V_88 -> V_93 -> V_94 != 0 ;
for ( V_151 = 0 ; V_151 < V_137 -> V_153 ; V_151 ++ ) {
struct V_136 * V_154 = & V_137 -> V_155 [ V_151 ] ;
if ( F_67 ( V_154 ) ) {
if ( ! V_152 )
return F_68 ( V_88 ) ;
return F_72 ( V_88 ,
V_154 -> V_138 . V_156 ,
V_154 -> V_138 . V_157 ) ;
}
}
return - V_149 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_158 * V_159 [ 4 ] = { } ;
struct V_150 * V_137 = V_2 -> V_137 ;
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_158 * V_160 = V_137 -> V_161 -> V_160 ;
unsigned V_151 , V_162 = V_137 -> V_161 -> V_138 . V_163 ;
V_2 -> F_21 = 0 ;
V_2 -> V_22 = NULL ;
for ( V_151 = 0 ; V_151 < V_162 ; V_151 ++ ) {
unsigned char * V_164 = V_160 [ V_151 ] . V_164 ;
int V_40 = V_160 [ V_151 ] . V_165 ;
while ( V_40 > 1 ) {
if ( V_164 [ 1 ] == V_166 ) {
unsigned V_167 = V_164 [ 2 ] ;
if ( V_167 > 0 && V_167 < 5 )
V_159 [ V_167 - 1 ] = & V_160 [ V_151 ] ;
break;
}
V_40 -= V_164 [ 0 ] ;
V_164 += V_164 [ 0 ] ;
}
}
if ( ! V_159 [ 0 ] ) {
V_2 -> V_109 = F_74 ( V_88 , 1 ) ;
V_2 -> V_99 = F_75 ( V_88 , 1 ) ;
V_2 -> V_121 = F_75 ( V_88 , 2 ) ;
V_2 -> V_123 = F_74 ( V_88 , 2 ) ;
V_159 [ 1 ] = F_76 ( V_88 , V_2 -> V_99 ) ;
V_159 [ 2 ] = F_76 ( V_88 , V_2 -> V_121 ) ;
V_159 [ 3 ] = F_76 ( V_88 , V_2 -> V_123 ) ;
} else {
V_2 -> V_109 = F_74 ( V_88 ,
V_159 [ 0 ] -> V_138 . V_168 ) ;
V_2 -> V_99 = F_75 ( V_88 ,
V_159 [ 1 ] -> V_138 . V_168 ) ;
V_2 -> V_121 = F_75 ( V_88 ,
V_159 [ 2 ] -> V_138 . V_168 ) ;
V_2 -> V_123 = F_74 ( V_88 ,
V_159 [ 3 ] -> V_138 . V_168 ) ;
}
V_2 -> V_135 = F_77 ( V_2 -> V_137 , V_159 + 1 , 3 , 256 ,
V_169 ) ;
if ( V_2 -> V_135 < 0 ) {
V_2 -> V_135 = 256 ;
V_2 -> V_91 = 0 ;
} else {
V_2 -> V_91 = 1 ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_158 * V_159 [ 3 ] ;
V_159 [ 0 ] = F_76 ( V_88 , V_2 -> V_99 ) ;
V_159 [ 1 ] = F_76 ( V_88 , V_2 -> V_121 ) ;
V_159 [ 2 ] = F_76 ( V_88 , V_2 -> V_123 ) ;
F_79 ( V_2 -> V_137 , V_159 , 3 , V_169 ) ;
}
static int F_80 ( struct V_150 * V_137 , const struct V_170 * V_171 )
{
int V_45 ;
struct V_67 * V_68 ;
struct V_1 * V_2 ;
struct V_87 * V_88 = F_81 ( V_137 ) ;
if ( F_71 ( V_88 , V_137 ) )
return - V_149 ;
V_2 = F_82 ( sizeof( struct V_1 ) , V_169 ) ;
if ( ! V_2 )
return - V_112 ;
V_45 = - V_112 ;
V_68 = F_83 ( & V_172 , sizeof( void * ) ) ;
if ( ! V_68 )
goto free;
V_68 -> V_173 = 16 + 252 ;
V_68 -> V_174 = 1 ;
V_68 -> V_175 = 256 ;
V_68 -> V_176 = 0 ;
V_68 -> V_94 = V_88 -> V_93 -> V_94 ;
V_2 -> V_137 = V_137 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_31 = 0 ;
F_84 ( & V_2 -> V_116 ) ;
F_84 ( & V_2 -> V_119 ) ;
F_84 ( & V_2 -> V_122 ) ;
F_85 ( & V_2 -> V_6 ) ;
F_73 ( V_2 ) ;
V_45 = F_86 ( V_68 , V_2 -> V_135 - 3 ) ;
if ( V_45 )
goto free;
V_45 = F_87 ( V_68 , & V_137 -> V_70 ) ;
if ( V_45 )
goto V_177;
V_68 -> V_25 [ 0 ] = ( unsigned long ) V_2 ;
F_88 ( V_68 ) ;
F_89 ( V_137 , V_68 ) ;
return V_45 ;
V_177:
F_78 ( V_2 ) ;
free:
F_90 ( V_2 ) ;
if ( V_68 )
F_91 ( V_68 ) ;
return V_45 ;
}
static int F_92 ( struct V_150 * V_137 )
{
return 0 ;
}
static int F_93 ( struct V_150 * V_137 )
{
return 0 ;
}
static void F_94 ( struct V_150 * V_137 )
{
struct V_67 * V_68 = F_95 ( V_137 ) ;
struct V_1 * V_2 = ( void * ) V_68 -> V_25 [ 0 ] ;
V_2 -> V_31 = 1 ;
F_15 ( V_2 ) ;
F_61 ( & V_2 -> V_116 ) ;
F_61 ( & V_2 -> V_119 ) ;
F_61 ( & V_2 -> V_122 ) ;
F_96 ( V_68 ) ;
F_78 ( V_2 ) ;
F_90 ( V_2 ) ;
}
