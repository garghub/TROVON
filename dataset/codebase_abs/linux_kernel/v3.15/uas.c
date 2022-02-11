static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_5 )
{
V_4 -> V_6 |= V_7 ;
F_2 ( & V_2 -> V_8 , * V_5 ) ;
if ( V_4 -> V_9 )
F_3 ( V_4 -> V_9 ) ;
if ( V_4 -> V_10 )
F_3 ( V_4 -> V_10 ) ;
F_4 ( & V_2 -> V_8 , * V_5 ) ;
V_4 -> V_6 &= ~ V_7 ;
}
static void F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_2 =
F_6 ( V_12 , struct V_1 , V_12 ) ;
struct V_3 * V_4 ;
unsigned long V_13 ;
int V_14 ;
F_4 ( & V_2 -> V_8 , V_13 ) ;
F_7 (cmdinfo, &devinfo->inflight_list, list) {
struct V_15 * V_16 = ( void * ) V_4 ;
struct V_17 * V_18 = F_6 ( V_16 , struct V_17 ,
V_19 ) ;
if ( ! ( V_4 -> V_6 & V_20 ) )
continue;
V_14 = F_8 ( V_18 , V_18 -> V_21 -> V_22 , V_23 ) ;
if ( ! V_14 )
V_4 -> V_6 &= ~ V_20 ;
else
F_9 ( & V_2 -> V_12 ) ;
}
F_2 ( & V_2 -> V_8 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_24 , const char * V_25 )
{
struct V_15 * V_16 = ( void * ) V_4 ;
struct V_17 * V_18 = F_6 ( V_16 , struct V_17 , V_19 ) ;
F_11 ( V_18 , V_25 ) ;
F_12 ( ! F_13 ( & V_2 -> V_8 ) ) ;
F_12 ( V_4 -> V_6 & V_26 ) ;
V_4 -> V_6 |= V_26 ;
V_4 -> V_6 &= ~ V_20 ;
V_18 -> V_24 = V_24 << 16 ;
F_14 ( & V_4 -> V_27 , & V_2 -> V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_24 ,
const char * V_25 )
{
struct V_3 * V_4 ;
struct V_3 * V_29 ;
unsigned long V_13 ;
F_4 ( & V_2 -> V_8 , V_13 ) ;
F_16 (cmdinfo, temp, &devinfo->inflight_list, list)
F_10 ( V_2 , V_4 , V_24 , V_25 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = ( void * ) V_4 ;
struct V_17 * V_18 = F_6 ( V_16 , struct V_17 , V_19 ) ;
struct V_1 * V_2 = V_18 -> V_21 -> V_22 ;
F_12 ( ! F_13 ( & V_2 -> V_8 ) ) ;
V_4 -> V_6 |= V_20 ;
F_9 ( & V_2 -> V_12 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_29 ;
unsigned long V_13 ;
F_4 ( & V_2 -> V_8 , V_13 ) ;
F_16 (cmdinfo, temp, &devinfo->dead_list, list) {
struct V_15 * V_16 = ( void * ) V_4 ;
struct V_17 * V_18 = F_6 ( V_16 , struct V_17 ,
V_19 ) ;
F_11 ( V_18 , V_30 ) ;
F_12 ( ! ( V_4 -> V_6 & V_26 ) ) ;
V_4 -> V_6 &= ~ ( V_31 |
V_32 |
V_33 ) ;
F_19 ( V_18 , V_30 ) ;
}
V_2 -> V_34 = 0 ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
}
static void F_20 ( struct V_35 * V_35 , struct V_17 * V_18 )
{
struct V_36 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_18 -> V_21 ;
if ( V_35 -> V_40 > 16 ) {
unsigned V_41 = F_21 ( & V_36 -> V_41 ) ;
if ( V_41 + 16 != V_35 -> V_40 ) {
int V_42 = F_22 ( V_41 + 16 , V_35 -> V_40 ) - 16 ;
if ( V_42 < 0 )
V_42 = 0 ;
F_23 ( V_43 , V_39 , L_1
L_2
L_3 , V_30 ,
V_35 -> V_40 , V_41 , V_42 ) ;
V_41 = V_42 ;
}
memcpy ( V_18 -> V_44 , V_36 -> V_45 , V_41 ) ;
}
V_18 -> V_24 = V_36 -> V_46 ;
}
static void F_24 ( struct V_35 * V_35 , struct V_17 * V_18 )
{
struct V_47 * V_36 = V_35 -> V_37 ;
struct V_38 * V_39 = V_18 -> V_21 ;
if ( V_35 -> V_40 > 8 ) {
unsigned V_41 = F_21 ( & V_36 -> V_41 ) - 2 ;
if ( V_41 + 8 != V_35 -> V_40 ) {
int V_42 = F_22 ( V_41 + 8 , V_35 -> V_40 ) - 8 ;
if ( V_42 < 0 )
V_42 = 0 ;
F_23 ( V_43 , V_39 , L_1
L_2
L_3 , V_30 ,
V_35 -> V_40 , V_41 , V_42 ) ;
V_41 = V_42 ;
}
memcpy ( V_18 -> V_44 , V_36 -> V_45 , V_41 ) ;
}
V_18 -> V_24 = V_36 -> V_46 ;
}
static void F_11 ( struct V_17 * V_18 , const char * V_25 )
{
struct V_3 * V_48 = ( void * ) & V_18 -> V_19 ;
F_25 ( V_43 , V_18 , L_4
L_5 ,
V_25 , V_18 , V_18 -> V_49 -> V_50 ,
( V_48 -> V_6 & V_51 ) ? L_6 : L_7 ,
( V_48 -> V_6 & V_52 ) ? L_8 : L_7 ,
( V_48 -> V_6 & V_53 ) ? L_9 : L_7 ,
( V_48 -> V_6 & V_54 ) ? L_10 : L_7 ,
( V_48 -> V_6 & V_55 ) ? L_11 : L_7 ,
( V_48 -> V_6 & V_56 ) ? L_12 : L_7 ,
( V_48 -> V_6 & V_57 ) ? L_13 : L_7 ,
( V_48 -> V_6 & V_31 ) ? L_14 : L_7 ,
( V_48 -> V_6 & V_32 ) ? L_15 : L_7 ,
( V_48 -> V_6 & V_33 ) ? L_16 : L_7 ,
( V_48 -> V_6 & V_58 ) ? L_17 : L_7 ,
( V_48 -> V_6 & V_26 ) ? L_18 : L_7 ,
( V_48 -> V_6 & V_7 ) ? L_19 : L_7 ,
( V_48 -> V_6 & V_20 ) ? L_20 : L_7 ) ;
}
static int F_19 ( struct V_17 * V_18 , const char * V_25 )
{
struct V_3 * V_4 = ( void * ) & V_18 -> V_19 ;
struct V_1 * V_2 = ( void * ) V_18 -> V_21 -> V_22 ;
F_12 ( ! F_13 ( & V_2 -> V_8 ) ) ;
if ( V_4 -> V_6 & ( V_31 |
V_32 |
V_33 |
V_7 ) )
return - V_59 ;
F_12 ( V_4 -> V_6 & V_58 ) ;
V_4 -> V_6 |= V_58 ;
F_26 ( V_4 -> V_9 ) ;
F_26 ( V_4 -> V_10 ) ;
if ( V_4 -> V_6 & V_26 )
F_25 ( V_43 , V_18 , L_21 ) ;
F_27 ( & V_4 -> V_27 ) ;
V_18 -> V_60 ( V_18 ) ;
return 0 ;
}
static void F_28 ( struct V_35 * V_35 , struct V_17 * V_18 ,
unsigned V_61 )
{
struct V_3 * V_4 = ( void * ) & V_18 -> V_19 ;
int V_14 ;
V_4 -> V_6 |= V_61 | V_51 ;
V_14 = F_8 ( V_18 , V_18 -> V_21 -> V_22 , V_23 ) ;
if ( V_14 ) {
F_17 ( V_4 ) ;
}
}
static void F_29 ( struct V_35 * V_35 )
{
struct V_62 * V_62 = V_35 -> V_37 ;
struct V_63 * V_64 = V_35 -> V_65 ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
T_1 V_50 ;
if ( V_35 -> V_46 ) {
if ( V_35 -> V_46 == - V_66 ) {
F_30 ( & V_35 -> V_67 -> V_67 , L_22 ,
V_35 -> V_68 ) ;
} else {
F_30 ( & V_35 -> V_67 -> V_67 , L_23 ,
V_35 -> V_46 ) ;
}
F_26 ( V_35 ) ;
return;
}
if ( V_2 -> V_69 ) {
F_26 ( V_35 ) ;
return;
}
F_4 ( & V_2 -> V_8 , V_13 ) ;
V_50 = F_21 ( & V_62 -> V_50 ) - 1 ;
if ( V_50 == 0 )
V_18 = V_2 -> V_18 ;
else
V_18 = F_31 ( V_64 , V_50 - 1 ) ;
if ( ! V_18 ) {
if ( V_62 -> V_70 == V_71 ) {
if ( ! V_2 -> V_34 )
F_32 ( & V_35 -> V_67 -> V_67 ,
L_24 ) ;
memcpy ( & V_2 -> V_72 , V_62 , sizeof( V_2 -> V_72 ) ) ;
}
F_26 ( V_35 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
return;
}
V_4 = ( void * ) & V_18 -> V_19 ;
switch ( V_62 -> V_70 ) {
case V_73 :
if ( V_2 -> V_18 == V_18 )
V_2 -> V_18 = NULL ;
if ( V_35 -> V_40 < 16 )
V_2 -> F_24 = 1 ;
if ( V_2 -> F_24 )
F_24 ( V_35 , V_18 ) ;
else
F_20 ( V_35 , V_18 ) ;
if ( V_18 -> V_24 != 0 ) {
F_1 ( V_2 , V_4 , & V_13 ) ;
}
V_4 -> V_6 &= ~ V_31 ;
F_19 ( V_18 , V_30 ) ;
break;
case V_74 :
if ( ! V_4 -> V_9 ||
( V_4 -> V_6 & V_32 ) ) {
F_25 ( V_75 , V_18 , L_25 ) ;
break;
}
F_28 ( V_35 , V_18 , V_53 ) ;
break;
case V_76 :
if ( ! V_4 -> V_10 ||
( V_4 -> V_6 & V_33 ) ) {
F_25 ( V_75 , V_18 , L_26 ) ;
break;
}
F_28 ( V_35 , V_18 , V_55 ) ;
break;
default:
F_25 ( V_75 , V_18 ,
L_27 , V_62 -> V_70 ) ;
}
F_26 ( V_35 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
}
static void F_33 ( struct V_35 * V_35 )
{
struct V_17 * V_18 = V_35 -> V_65 ;
struct V_3 * V_4 = ( void * ) & V_18 -> V_19 ;
struct V_1 * V_2 = ( void * ) V_18 -> V_21 -> V_22 ;
struct V_77 * V_78 = NULL ;
unsigned long V_13 ;
F_4 ( & V_2 -> V_8 , V_13 ) ;
if ( V_4 -> V_9 == V_35 ) {
V_78 = F_34 ( V_18 ) ;
V_4 -> V_6 &= ~ V_32 ;
} else if ( V_4 -> V_10 == V_35 ) {
V_78 = F_35 ( V_18 ) ;
V_4 -> V_6 &= ~ V_33 ;
}
if ( V_78 == NULL ) {
F_12 ( 1 ) ;
} else if ( V_35 -> V_46 ) {
if ( V_35 -> V_46 != - V_79 ) {
F_11 ( V_18 , V_30 ) ;
F_25 ( V_75 , V_18 ,
L_28 ,
V_35 -> V_46 , V_35 -> V_68 ) ;
}
V_78 -> V_80 = V_78 -> V_81 ;
} else {
V_78 -> V_80 = V_78 -> V_81 - V_35 -> V_40 ;
}
F_19 ( V_18 , V_30 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
}
static void F_36 ( struct V_35 * V_35 )
{
struct V_17 * V_18 = V_35 -> V_65 ;
if ( V_35 -> V_46 ) {
F_11 ( V_18 , V_30 ) ;
F_25 ( V_75 , V_18 , L_29 , V_35 -> V_46 ) ;
}
F_26 ( V_35 ) ;
}
static struct V_35 * F_37 ( struct V_1 * V_2 , T_2 V_82 ,
unsigned int V_83 , T_1 V_68 ,
struct V_17 * V_18 ,
enum V_84 V_85 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_35 * V_35 = F_38 ( 0 , V_82 ) ;
struct V_77 * V_78 = ( V_85 == V_88 )
? F_34 ( V_18 ) : F_35 ( V_18 ) ;
if ( ! V_35 )
goto V_89;
F_39 ( V_35 , V_87 , V_83 , NULL , V_78 -> V_81 ,
F_33 , V_18 ) ;
V_35 -> V_68 = V_68 ;
V_35 -> V_90 = V_87 -> V_91 -> V_92 ? V_78 -> V_93 . V_94 : 0 ;
V_35 -> V_95 = V_78 -> V_93 . V_96 ;
V_89:
return V_35 ;
}
static struct V_35 * F_40 ( struct V_1 * V_2 , T_2 V_82 ,
struct V_63 * V_64 , T_1 V_68 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_35 * V_35 = F_38 ( 0 , V_82 ) ;
struct V_36 * V_62 ;
if ( ! V_35 )
goto V_89;
V_62 = F_41 ( sizeof( * V_62 ) , V_82 ) ;
if ( ! V_62 )
goto free;
F_39 ( V_35 , V_87 , V_2 -> V_97 , V_62 , sizeof( * V_62 ) ,
F_29 , V_64 ) ;
V_35 -> V_68 = V_68 ;
V_35 -> V_98 |= V_99 ;
V_89:
return V_35 ;
free:
F_26 ( V_35 ) ;
return NULL ;
}
static struct V_35 * F_42 ( struct V_1 * V_2 , T_2 V_82 ,
struct V_17 * V_18 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_38 * V_39 = V_18 -> V_21 ;
struct V_35 * V_35 = F_38 ( 0 , V_82 ) ;
struct V_100 * V_62 ;
int V_41 ;
if ( ! V_35 )
goto V_89;
V_41 = V_18 -> V_101 - 16 ;
if ( V_41 < 0 )
V_41 = 0 ;
V_41 = F_43 ( V_41 , 4 ) ;
V_62 = F_41 ( sizeof( * V_62 ) + V_41 , V_82 ) ;
if ( ! V_62 )
goto free;
V_62 -> V_70 = V_102 ;
if ( F_44 ( V_18 -> V_49 ) )
V_62 -> V_50 = F_45 ( V_18 -> V_49 -> V_50 + 2 ) ;
else
V_62 -> V_50 = F_45 ( 1 ) ;
V_62 -> V_103 = V_104 ;
V_62 -> V_41 = V_41 ;
F_46 ( V_39 -> V_105 , & V_62 -> V_105 ) ;
memcpy ( V_62 -> V_106 , V_18 -> V_18 , V_18 -> V_101 ) ;
F_39 ( V_35 , V_87 , V_2 -> V_107 , V_62 , sizeof( * V_62 ) + V_41 ,
F_36 , V_18 ) ;
V_35 -> V_98 |= V_99 ;
V_89:
return V_35 ;
free:
F_26 ( V_35 ) ;
return NULL ;
}
static int F_47 ( struct V_17 * V_18 , T_2 V_82 ,
T_3 V_108 , T_1 V_68 )
{
struct V_1 * V_2 = ( void * ) V_18 -> V_21 -> V_22 ;
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_35 * V_35 = F_38 ( 0 , V_82 ) ;
struct V_109 * V_62 ;
int V_14 = - V_110 ;
if ( ! V_35 )
goto V_14;
V_62 = F_41 ( sizeof( * V_62 ) , V_82 ) ;
if ( ! V_62 )
goto V_14;
V_62 -> V_70 = V_111 ;
V_62 -> V_50 = F_45 ( V_68 ) ;
F_46 ( V_18 -> V_21 -> V_105 , & V_62 -> V_105 ) ;
V_62 -> V_108 = V_108 ;
switch ( V_108 ) {
case V_112 :
if ( F_44 ( V_18 -> V_49 ) )
V_62 -> V_113 = F_45 ( V_18 -> V_49 -> V_50 + 2 ) ;
else
V_62 -> V_113 = F_45 ( 1 ) ;
break;
}
F_39 ( V_35 , V_87 , V_2 -> V_107 , V_62 , sizeof( * V_62 ) ,
F_36 , V_18 ) ;
V_35 -> V_98 |= V_99 ;
F_48 ( V_35 , & V_2 -> V_114 ) ;
V_14 = F_49 ( V_35 , V_82 ) ;
if ( V_14 ) {
F_50 ( V_35 ) ;
F_11 ( V_18 , V_30 ) ;
F_25 ( V_75 , V_18 , L_30 , V_14 ) ;
goto V_14;
}
return 0 ;
V_14:
F_26 ( V_35 ) ;
return V_14 ;
}
static struct V_35 * F_51 ( struct V_17 * V_18 ,
T_2 V_82 , unsigned int V_115 )
{
struct V_63 * V_64 = V_18 -> V_21 -> V_116 ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
struct V_35 * V_35 ;
int V_14 ;
V_35 = F_40 ( V_2 , V_82 , V_64 , V_115 ) ;
if ( ! V_35 )
return NULL ;
F_48 ( V_35 , & V_2 -> V_117 ) ;
V_14 = F_49 ( V_35 , V_82 ) ;
if ( V_14 ) {
F_50 ( V_35 ) ;
F_11 ( V_18 , V_30 ) ;
F_52 ( V_43 , V_64 ,
L_31 ,
V_14 , V_115 ) ;
F_26 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
static int F_8 ( struct V_17 * V_18 ,
struct V_1 * V_2 , T_2 V_82 )
{
struct V_3 * V_4 = ( void * ) & V_18 -> V_19 ;
struct V_35 * V_35 ;
int V_14 ;
F_12 ( ! F_13 ( & V_2 -> V_8 ) ) ;
if ( V_4 -> V_6 & V_51 ) {
V_35 = F_51 ( V_18 , V_82 , V_4 -> V_115 ) ;
if ( ! V_35 )
return V_118 ;
V_4 -> V_6 &= ~ V_51 ;
}
if ( V_4 -> V_6 & V_52 ) {
V_4 -> V_9 = F_37 ( V_2 , V_82 ,
V_2 -> V_119 , V_4 -> V_115 ,
V_18 , V_88 ) ;
if ( ! V_4 -> V_9 )
return V_118 ;
V_4 -> V_6 &= ~ V_52 ;
}
if ( V_4 -> V_6 & V_53 ) {
F_48 ( V_4 -> V_9 , & V_2 -> V_120 ) ;
V_14 = F_49 ( V_4 -> V_9 , V_82 ) ;
if ( V_14 ) {
F_50 ( V_4 -> V_9 ) ;
F_11 ( V_18 , V_30 ) ;
F_25 ( V_43 , V_18 ,
L_32 ,
V_14 , V_4 -> V_9 -> V_68 ) ;
return V_118 ;
}
V_4 -> V_6 &= ~ V_53 ;
V_4 -> V_6 |= V_32 ;
}
if ( V_4 -> V_6 & V_54 ) {
V_4 -> V_10 = F_37 ( V_2 , V_82 ,
V_2 -> V_121 , V_4 -> V_115 ,
V_18 , V_122 ) ;
if ( ! V_4 -> V_10 )
return V_118 ;
V_4 -> V_6 &= ~ V_54 ;
}
if ( V_4 -> V_6 & V_55 ) {
F_48 ( V_4 -> V_10 , & V_2 -> V_120 ) ;
V_14 = F_49 ( V_4 -> V_10 , V_82 ) ;
if ( V_14 ) {
F_50 ( V_4 -> V_10 ) ;
F_11 ( V_18 , V_30 ) ;
F_25 ( V_43 , V_18 ,
L_33 ,
V_14 , V_4 -> V_10 -> V_68 ) ;
return V_118 ;
}
V_4 -> V_6 &= ~ V_55 ;
V_4 -> V_6 |= V_33 ;
}
if ( V_4 -> V_6 & V_56 ) {
V_4 -> V_123 = F_42 ( V_2 , V_82 , V_18 ) ;
if ( ! V_4 -> V_123 )
return V_118 ;
V_4 -> V_6 &= ~ V_56 ;
}
if ( V_4 -> V_6 & V_57 ) {
F_48 ( V_4 -> V_123 , & V_2 -> V_114 ) ;
V_14 = F_49 ( V_4 -> V_123 , V_82 ) ;
if ( V_14 ) {
F_50 ( V_4 -> V_123 ) ;
F_11 ( V_18 , V_30 ) ;
F_25 ( V_43 , V_18 ,
L_34 , V_14 ) ;
return V_118 ;
}
V_4 -> V_123 = NULL ;
V_4 -> V_6 &= ~ V_57 ;
V_4 -> V_6 |= V_31 ;
}
return 0 ;
}
static int F_53 ( struct V_17 * V_18 ,
void (* F_54)( struct V_17 * ) )
{
struct V_38 * V_39 = V_18 -> V_21 ;
struct V_1 * V_2 = V_39 -> V_22 ;
struct V_3 * V_4 = ( void * ) & V_18 -> V_19 ;
unsigned long V_13 ;
int V_14 ;
F_55 ( sizeof( struct V_3 ) > sizeof( struct V_15 ) ) ;
F_4 ( & V_2 -> V_8 , V_13 ) ;
if ( V_2 -> V_69 ) {
V_18 -> V_24 = V_124 << 16 ;
V_18 -> V_60 ( V_18 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
return 0 ;
}
if ( V_2 -> V_18 ) {
F_2 ( & V_2 -> V_8 , V_13 ) ;
return V_118 ;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( F_44 ( V_18 -> V_49 ) ) {
V_4 -> V_115 = V_18 -> V_49 -> V_50 + 2 ;
} else {
V_2 -> V_18 = V_18 ;
V_4 -> V_115 = 1 ;
}
V_18 -> V_60 = F_54 ;
V_4 -> V_6 = V_51 |
V_56 | V_57 ;
switch ( V_18 -> V_125 ) {
case V_88 :
V_4 -> V_6 |= V_52 | V_53 ;
break;
case V_126 :
V_4 -> V_6 |= V_52 | V_53 ;
case V_122 :
V_4 -> V_6 |= V_54 | V_55 ;
case V_127 :
break;
}
if ( ! V_2 -> V_128 ) {
V_4 -> V_6 &= ~ ( V_53 | V_55 ) ;
V_4 -> V_115 = 0 ;
}
V_14 = F_8 ( V_18 , V_2 , V_23 ) ;
if ( V_14 ) {
if ( V_4 -> V_6 & V_51 ) {
F_2 ( & V_2 -> V_8 , V_13 ) ;
return V_118 ;
}
F_17 ( V_4 ) ;
}
F_56 ( & V_4 -> V_27 , & V_2 -> V_129 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
return 0 ;
}
int F_57 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = ( void * ) & V_18 -> V_19 ;
struct V_1 * V_2 = ( void * ) V_18 -> V_21 -> V_22 ;
unsigned long V_13 ;
int V_130 ;
F_4 ( & V_2 -> V_8 , V_13 ) ;
if ( V_2 -> V_69 ) {
F_2 ( & V_2 -> V_8 , V_13 ) ;
return V_131 ;
}
F_10 ( V_2 , V_4 , V_132 , V_30 ) ;
if ( V_4 -> V_6 & V_31 ) {
F_2 ( & V_2 -> V_8 , V_13 ) ;
V_130 = F_58 ( V_18 , L_35 , V_112 ) ;
} else {
F_1 ( V_2 , V_4 , & V_13 ) ;
F_19 ( V_18 , V_30 ) ;
F_2 ( & V_2 -> V_8 , V_13 ) ;
V_130 = V_133 ;
}
return V_130 ;
}
static int F_59 ( struct V_17 * V_18 )
{
F_23 ( V_43 , V_18 -> V_21 , L_36 , V_30 ) ;
return F_58 ( V_18 , L_37 ,
V_134 ) ;
}
static int F_60 ( struct V_17 * V_18 )
{
struct V_38 * V_39 = V_18 -> V_21 ;
struct V_1 * V_2 = V_39 -> V_22 ;
struct V_86 * V_87 = V_2 -> V_87 ;
int V_14 ;
V_14 = F_61 ( V_87 , V_2 -> V_135 ) ;
if ( V_14 ) {
F_52 ( V_75 , V_39 -> V_116 ,
L_38 , V_30 , V_14 ) ;
return V_131 ;
}
F_52 ( V_43 , V_39 -> V_116 , L_39 , V_30 ) ;
V_2 -> V_69 = 1 ;
F_15 ( V_2 , V_136 , V_30 ) ;
F_62 ( & V_2 -> V_114 ) ;
F_62 ( & V_2 -> V_117 ) ;
F_62 ( & V_2 -> V_120 ) ;
F_18 ( V_2 ) ;
V_14 = F_63 ( V_87 ) ;
V_2 -> V_69 = 0 ;
F_64 ( V_87 ) ;
if ( V_14 ) {
F_52 ( V_43 , V_39 -> V_116 , L_40 , V_30 ) ;
return V_131 ;
}
F_52 ( V_43 , V_39 -> V_116 , L_41 , V_30 ) ;
return V_133 ;
}
static int F_65 ( struct V_38 * V_39 )
{
V_39 -> V_22 = ( void * ) V_39 -> V_116 -> V_22 ;
F_66 ( V_39 -> V_137 , ( 512 - 1 ) ) ;
return 0 ;
}
static int F_67 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_22 ;
F_68 ( V_39 , V_138 ) ;
F_69 ( V_39 , V_2 -> V_139 - 2 ) ;
return 0 ;
}
static int F_70 ( struct V_86 * V_87 ,
struct V_140 * V_135 )
{
int V_141 ;
V_141 = F_71 ( V_135 ) ;
if ( V_141 < 0 )
return V_141 ;
return F_72 ( V_87 ,
V_135 -> V_142 [ 0 ] . V_143 . V_144 , V_141 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_145 * V_146 [ 4 ] = { } ;
struct V_86 * V_87 = V_2 -> V_87 ;
int V_147 ;
V_2 -> F_24 = 0 ;
V_2 -> V_18 = NULL ;
V_147 = F_74 ( V_2 -> V_135 -> V_148 , V_146 ) ;
if ( V_147 )
return V_147 ;
V_2 -> V_107 = F_75 ( V_87 ,
F_76 ( & V_146 [ 0 ] -> V_143 ) ) ;
V_2 -> V_97 = F_77 ( V_87 ,
F_76 ( & V_146 [ 1 ] -> V_143 ) ) ;
V_2 -> V_119 = F_77 ( V_87 ,
F_76 ( & V_146 [ 2 ] -> V_143 ) ) ;
V_2 -> V_121 = F_75 ( V_87 ,
F_76 ( & V_146 [ 3 ] -> V_143 ) ) ;
if ( V_87 -> V_149 != V_150 ) {
V_2 -> V_139 = 256 ;
V_2 -> V_128 = 0 ;
} else {
V_2 -> V_139 = F_78 ( V_2 -> V_135 , V_146 + 1 ,
3 , 256 , V_151 ) ;
if ( V_2 -> V_139 < 0 )
return V_2 -> V_139 ;
V_2 -> V_128 = 1 ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = V_2 -> V_87 ;
struct V_145 * V_146 [ 3 ] ;
V_146 [ 0 ] = F_80 ( V_87 , V_2 -> V_97 ) ;
V_146 [ 1 ] = F_80 ( V_87 , V_2 -> V_119 ) ;
V_146 [ 2 ] = F_80 ( V_87 , V_2 -> V_121 ) ;
F_81 ( V_2 -> V_135 , V_146 , 3 , V_151 ) ;
}
static int F_82 ( struct V_140 * V_135 , const struct V_152 * V_153 )
{
int V_24 = - V_110 ;
struct V_63 * V_64 = NULL ;
struct V_1 * V_2 ;
struct V_86 * V_87 = F_83 ( V_135 ) ;
if ( ! F_84 ( V_135 , V_153 ) )
return - V_154 ;
if ( F_70 ( V_87 , V_135 ) )
return - V_154 ;
V_64 = F_85 ( & V_155 ,
sizeof( struct V_1 ) ) ;
if ( ! V_64 )
goto V_156;
V_64 -> V_157 = 16 + 252 ;
V_64 -> V_158 = 1 ;
V_64 -> V_159 = 256 ;
V_64 -> V_160 = 0 ;
V_64 -> V_92 = V_87 -> V_91 -> V_92 ;
V_2 = (struct V_1 * ) V_64 -> V_22 ;
V_2 -> V_135 = V_135 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_69 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_161 = 0 ;
F_86 ( & V_2 -> V_114 ) ;
F_86 ( & V_2 -> V_117 ) ;
F_86 ( & V_2 -> V_120 ) ;
F_87 ( & V_2 -> V_8 ) ;
F_88 ( & V_2 -> V_12 , F_5 ) ;
F_89 ( & V_2 -> V_129 ) ;
F_89 ( & V_2 -> V_28 ) ;
V_24 = F_73 ( V_2 ) ;
if ( V_24 )
goto V_156;
V_24 = F_90 ( V_64 , V_2 -> V_139 - 2 ) ;
if ( V_24 )
goto V_162;
F_91 ( V_135 , V_64 ) ;
V_24 = F_92 ( V_64 , & V_135 -> V_67 ) ;
if ( V_24 )
goto V_162;
F_93 ( V_64 ) ;
return V_24 ;
V_162:
F_79 ( V_2 ) ;
F_91 ( V_135 , NULL ) ;
V_156:
F_72 ( V_87 , V_135 -> V_142 [ 0 ] . V_143 . V_144 , 0 ) ;
if ( V_64 )
F_94 ( V_64 ) ;
return V_24 ;
}
static int F_95 ( struct V_140 * V_135 )
{
struct V_63 * V_64 = F_96 ( V_135 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
unsigned long V_13 ;
if ( V_2 -> V_161 )
return 0 ;
F_4 ( V_64 -> V_163 , V_13 ) ;
F_97 ( V_64 ) ;
F_2 ( V_64 -> V_163 , V_13 ) ;
F_98 ( & V_2 -> V_12 ) ;
if ( F_99 ( & V_2 -> V_117 , 5000 ) == 0 ) {
F_52 ( V_75 , V_64 , L_42 , V_30 ) ;
return 1 ;
}
F_79 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_140 * V_135 )
{
struct V_63 * V_64 = F_96 ( V_135 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
unsigned long V_13 ;
if ( V_2 -> V_161 )
return 0 ;
if ( F_73 ( V_2 ) != 0 ) {
F_52 ( V_75 , V_64 ,
L_43 , V_30 ) ;
return 1 ;
}
F_4 ( V_64 -> V_163 , V_13 ) ;
F_101 ( V_64 , 0 ) ;
F_2 ( V_64 -> V_163 , V_13 ) ;
F_102 ( V_64 ) ;
return 0 ;
}
static int F_103 ( struct V_140 * V_135 , T_4 V_164 )
{
struct V_63 * V_64 = F_96 ( V_135 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
F_98 ( & V_2 -> V_12 ) ;
if ( F_99 ( & V_2 -> V_117 , 5000 ) == 0 ) {
F_52 ( V_75 , V_64 , L_42 , V_30 ) ;
return - V_165 ;
}
return 0 ;
}
static int F_104 ( struct V_140 * V_135 )
{
return 0 ;
}
static int F_105 ( struct V_140 * V_135 )
{
struct V_63 * V_64 = F_96 ( V_135 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
unsigned long V_13 ;
if ( F_73 ( V_2 ) != 0 ) {
F_52 ( V_75 , V_64 ,
L_43 , V_30 ) ;
return - V_166 ;
}
F_4 ( V_64 -> V_163 , V_13 ) ;
F_101 ( V_64 , 0 ) ;
F_2 ( V_64 -> V_163 , V_13 ) ;
return 0 ;
}
static void F_106 ( struct V_140 * V_135 )
{
struct V_63 * V_64 = F_96 ( V_135 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
V_2 -> V_69 = 1 ;
F_107 ( & V_2 -> V_12 ) ;
F_15 ( V_2 , V_167 , V_30 ) ;
F_62 ( & V_2 -> V_114 ) ;
F_62 ( & V_2 -> V_117 ) ;
F_62 ( & V_2 -> V_120 ) ;
F_18 ( V_2 ) ;
F_108 ( V_64 ) ;
F_79 ( V_2 ) ;
F_94 ( V_64 ) ;
}
static void F_109 ( struct V_21 * V_67 )
{
struct V_140 * V_135 = F_110 ( V_67 ) ;
struct V_86 * V_87 = F_83 ( V_135 ) ;
struct V_63 * V_64 = F_96 ( V_135 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_22 ;
if ( V_168 != V_169 )
return;
V_2 -> V_161 = 1 ;
F_79 ( V_2 ) ;
F_72 ( V_87 , V_135 -> V_142 [ 0 ] . V_143 . V_144 , 0 ) ;
F_63 ( V_87 ) ;
}
