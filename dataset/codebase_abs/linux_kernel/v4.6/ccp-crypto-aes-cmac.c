static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned int V_10 = F_5 ( V_7 ) ;
if ( V_3 )
goto V_11;
if ( V_9 -> V_12 ) {
unsigned int V_13 = V_9 -> V_14 - V_9 -> V_12 ;
F_6 ( V_9 -> V_15 , V_9 -> V_16 ,
V_13 , V_9 -> V_12 , 0 ) ;
V_9 -> V_17 = V_9 -> V_12 ;
} else {
V_9 -> V_17 = 0 ;
}
if ( V_5 -> V_18 )
memcpy ( V_5 -> V_18 , V_9 -> V_19 , V_10 ) ;
V_11:
F_7 ( & V_9 -> V_20 ) ;
return V_3 ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int V_14 ,
unsigned int V_21 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_22 * V_23 = F_9 ( V_7 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_24 * V_25 , * V_26 = NULL ;
unsigned int V_27 =
F_10 ( F_11 ( V_7 ) ) ;
unsigned int V_28 , V_29 ;
T_1 V_30 ;
T_2 V_31 ;
int V_3 ;
if ( ! V_23 -> V_32 . V_33 . V_34 )
return - V_35 ;
if ( V_14 )
V_9 -> V_36 = 0 ;
V_31 = ( T_2 ) V_9 -> V_17 + ( T_2 ) V_14 ;
if ( ! V_21 && ( V_31 <= V_27 ) ) {
F_6 ( V_9 -> V_15 + V_9 -> V_17 , V_5 -> V_16 ,
0 , V_14 , 0 ) ;
V_9 -> V_17 += V_14 ;
return 0 ;
}
V_9 -> V_16 = V_5 -> V_16 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_21 = V_21 ;
V_9 -> V_12 = V_21 ? 0 : V_31 & ( V_27 - 1 ) ;
V_9 -> V_37 = V_31 - V_9 -> V_12 ;
if ( ! V_21 && ! V_9 -> V_12 ) {
V_9 -> V_37 -= V_27 ;
V_9 -> V_12 = V_27 ;
}
if ( V_21 && ( V_9 -> V_36 || ( V_31 & ( V_27 - 1 ) ) ) )
V_28 = 1 ;
else
V_28 = 0 ;
F_12 ( & V_9 -> V_38 , V_9 -> V_19 , sizeof( V_9 -> V_19 ) ) ;
V_29 = ( V_14 ) ? F_13 ( V_5 -> V_16 ) + 2 : 2 ;
V_30 = V_5 -> V_39 . V_40 & V_41 ?
V_42 : V_43 ;
V_3 = F_14 ( & V_9 -> V_20 , V_29 , V_30 ) ;
if ( V_3 )
return V_3 ;
V_25 = NULL ;
if ( V_9 -> V_17 ) {
F_12 ( & V_9 -> V_44 , V_9 -> V_15 , V_9 -> V_17 ) ;
V_25 = F_15 ( & V_9 -> V_20 , & V_9 -> V_44 ) ;
if ( ! V_25 ) {
V_3 = - V_35 ;
goto V_11;
}
}
if ( V_14 ) {
V_25 = F_15 ( & V_9 -> V_20 , V_5 -> V_16 ) ;
if ( ! V_25 ) {
V_3 = - V_35 ;
goto V_11;
}
}
if ( V_28 ) {
int V_45 = V_27 - ( V_31 & ( V_27 - 1 ) ) ;
V_9 -> V_37 += V_45 ;
memset ( V_9 -> V_46 , 0 , sizeof( V_9 -> V_46 ) ) ;
V_9 -> V_46 [ 0 ] = 0x80 ;
F_12 ( & V_9 -> V_47 , V_9 -> V_46 , V_45 ) ;
V_25 = F_15 ( & V_9 -> V_20 , & V_9 -> V_47 ) ;
if ( ! V_25 ) {
V_3 = - V_35 ;
goto V_11;
}
}
if ( V_25 ) {
F_16 ( V_25 ) ;
V_25 = V_9 -> V_20 . V_48 ;
}
if ( V_21 )
V_26 = ( V_28 ) ? & V_23 -> V_32 . V_33 . V_49
: & V_23 -> V_32 . V_33 . V_50 ;
memset ( & V_9 -> V_51 , 0 , sizeof( V_9 -> V_51 ) ) ;
F_17 ( & V_9 -> V_51 . V_52 ) ;
V_9 -> V_51 . V_53 = V_54 ;
V_9 -> V_51 . V_32 . V_33 . type = V_23 -> V_32 . V_33 . type ;
V_9 -> V_51 . V_32 . V_33 . V_55 = V_23 -> V_32 . V_33 . V_55 ;
V_9 -> V_51 . V_32 . V_33 . V_56 = V_57 ;
V_9 -> V_51 . V_32 . V_33 . V_58 = & V_23 -> V_32 . V_33 . V_59 ;
V_9 -> V_51 . V_32 . V_33 . V_34 = V_23 -> V_32 . V_33 . V_34 ;
V_9 -> V_51 . V_32 . V_33 . V_19 = & V_9 -> V_38 ;
V_9 -> V_51 . V_32 . V_33 . V_60 = V_61 ;
V_9 -> V_51 . V_32 . V_33 . V_16 = V_25 ;
V_9 -> V_51 . V_32 . V_33 . V_62 = V_9 -> V_37 ;
V_9 -> V_51 . V_32 . V_33 . V_63 = NULL ;
V_9 -> V_51 . V_32 . V_33 . V_64 = V_26 ;
V_9 -> V_51 . V_32 . V_33 . V_65 = V_23 -> V_32 . V_33 . V_66 ;
V_9 -> V_51 . V_32 . V_33 . V_67 = V_21 ;
V_3 = F_18 ( & V_5 -> V_39 , & V_9 -> V_51 ) ;
return V_3 ;
V_11:
F_7 ( & V_9 -> V_20 ) ;
return V_3 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_36 = 1 ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
return F_8 ( V_5 , V_5 -> V_14 , 0 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
return F_8 ( V_5 , 0 , 1 ) ;
}
static int F_22 ( struct V_4 * V_5 )
{
return F_8 ( V_5 , V_5 -> V_14 , 1 ) ;
}
static int F_23 ( struct V_4 * V_5 )
{
int V_3 ;
V_3 = F_19 ( V_5 ) ;
if ( V_3 )
return V_3 ;
return F_22 ( V_5 ) ;
}
static int F_24 ( struct V_4 * V_5 , void * V_68 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_69 V_70 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_36 = V_9 -> V_36 ;
memcpy ( V_70 . V_19 , V_9 -> V_19 , sizeof( V_70 . V_19 ) ) ;
V_70 . V_17 = V_9 -> V_17 ;
memcpy ( V_70 . V_15 , V_9 -> V_15 , sizeof( V_70 . V_15 ) ) ;
memcpy ( V_68 , & V_70 , sizeof( V_70 ) ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 , const void * V_71 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_69 V_70 ;
memcpy ( & V_70 , V_71 , sizeof( V_70 ) ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_36 = V_70 . V_36 ;
memcpy ( V_9 -> V_19 , V_70 . V_19 , sizeof( V_9 -> V_19 ) ) ;
V_9 -> V_17 = V_70 . V_17 ;
memcpy ( V_9 -> V_15 , V_70 . V_15 , sizeof( V_9 -> V_15 ) ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , const T_3 * V_58 ,
unsigned int V_34 )
{
struct V_22 * V_23 = F_27 ( F_11 ( V_7 ) ) ;
struct V_72 * V_73 =
V_72 ( F_11 ( V_7 ) ) ;
T_2 V_74 , V_75 , V_76 , V_77 , V_78 , V_79 ;
T_2 V_80 = 0x00 , V_81 = 0x87 ;
T_4 * V_82 ;
int V_3 ;
switch ( V_34 ) {
case V_83 :
V_23 -> V_32 . V_33 . type = V_84 ;
break;
case V_85 :
V_23 -> V_32 . V_33 . type = V_86 ;
break;
case V_87 :
V_23 -> V_32 . V_33 . type = V_88 ;
break;
default:
F_28 ( V_7 , V_89 ) ;
return - V_35 ;
}
V_23 -> V_32 . V_33 . V_55 = V_73 -> V_55 ;
V_23 -> V_32 . V_33 . V_34 = 0 ;
V_3 = F_29 ( V_23 -> V_32 . V_33 . V_90 , V_58 , V_34 ) ;
if ( V_3 )
return V_3 ;
memset ( V_23 -> V_32 . V_33 . V_58 , 0 , sizeof( V_23 -> V_32 . V_33 . V_58 ) ) ;
F_30 ( V_23 -> V_32 . V_33 . V_90 , V_23 -> V_32 . V_33 . V_58 ,
V_23 -> V_32 . V_33 . V_58 ) ;
V_74 = F_31 ( * ( ( T_4 * ) V_23 -> V_32 . V_33 . V_58 ) ) ;
V_75 = F_31 ( * ( ( T_4 * ) V_23 -> V_32 . V_33 . V_58 + 1 ) ) ;
V_76 = ( V_74 << 1 ) | ( V_75 >> 63 ) ;
V_77 = V_75 << 1 ;
if ( V_23 -> V_32 . V_33 . V_58 [ 0 ] & 0x80 ) {
V_76 ^= V_80 ;
V_77 ^= V_81 ;
}
V_82 = ( T_4 * ) V_23 -> V_32 . V_33 . V_91 ;
* V_82 = F_32 ( V_76 ) ;
V_82 ++ ;
* V_82 = F_32 ( V_77 ) ;
V_78 = ( V_76 << 1 ) | ( V_77 >> 63 ) ;
V_79 = V_77 << 1 ;
if ( V_23 -> V_32 . V_33 . V_91 [ 0 ] & 0x80 ) {
V_78 ^= V_80 ;
V_79 ^= V_81 ;
}
V_82 = ( T_4 * ) V_23 -> V_32 . V_33 . V_92 ;
* V_82 = F_32 ( V_78 ) ;
V_82 ++ ;
* V_82 = F_32 ( V_79 ) ;
V_23 -> V_32 . V_33 . V_66 = sizeof( V_23 -> V_32 . V_33 . V_91 ) ;
F_12 ( & V_23 -> V_32 . V_33 . V_50 , V_23 -> V_32 . V_33 . V_91 , sizeof( V_23 -> V_32 . V_33 . V_91 ) ) ;
F_12 ( & V_23 -> V_32 . V_33 . V_49 , V_23 -> V_32 . V_33 . V_92 , sizeof( V_23 -> V_32 . V_33 . V_92 ) ) ;
memset ( V_23 -> V_32 . V_33 . V_58 , 0 , sizeof( V_23 -> V_32 . V_33 . V_58 ) ) ;
memcpy ( V_23 -> V_32 . V_33 . V_58 , V_58 , V_34 ) ;
V_23 -> V_32 . V_33 . V_34 = V_34 ;
F_12 ( & V_23 -> V_32 . V_33 . V_59 , V_23 -> V_32 . V_33 . V_58 , V_34 ) ;
return V_3 ;
}
static int F_33 ( struct V_93 * V_7 )
{
struct V_22 * V_23 = F_27 ( V_7 ) ;
struct V_6 * V_94 = F_34 ( V_7 ) ;
struct V_95 * V_96 ;
V_23 -> V_97 = F_1 ;
V_23 -> V_32 . V_33 . V_34 = 0 ;
F_35 ( V_94 , sizeof( struct V_8 ) ) ;
V_96 = F_36 ( L_1 , 0 ,
V_98 |
V_99 ) ;
if ( F_37 ( V_96 ) ) {
F_38 ( L_2 ) ;
return F_39 ( V_96 ) ;
}
V_23 -> V_32 . V_33 . V_90 = V_96 ;
return 0 ;
}
static void F_40 ( struct V_93 * V_7 )
{
struct V_22 * V_23 = F_27 ( V_7 ) ;
if ( V_23 -> V_32 . V_33 . V_90 )
F_41 ( V_23 -> V_32 . V_33 . V_90 ) ;
V_23 -> V_32 . V_33 . V_90 = NULL ;
}
int F_42 ( struct V_100 * V_101 )
{
struct V_72 * V_102 ;
struct V_103 * V_73 ;
struct V_104 * V_105 ;
struct V_106 * V_39 ;
int V_3 ;
V_102 = F_43 ( sizeof( * V_102 ) , V_42 ) ;
if ( ! V_102 )
return - V_107 ;
F_17 ( & V_102 -> V_52 ) ;
V_102 -> V_55 = V_108 ;
V_73 = & V_102 -> V_73 ;
V_73 -> V_109 = F_19 ;
V_73 -> V_110 = F_20 ;
V_73 -> V_21 = F_21 ;
V_73 -> V_111 = F_22 ;
V_73 -> V_112 = F_23 ;
V_73 -> V_113 = F_24 ;
V_73 -> V_114 = F_25 ;
V_73 -> V_115 = F_26 ;
V_105 = & V_73 -> V_105 ;
V_105 -> V_116 = V_61 ;
V_105 -> V_117 = sizeof( struct V_69 ) ;
V_39 = & V_105 -> V_39 ;
snprintf ( V_39 -> V_118 , V_119 , L_3 ) ;
snprintf ( V_39 -> V_120 , V_119 , L_4 ) ;
V_39 -> V_121 = V_122 | V_98 |
V_123 |
V_99 ;
V_39 -> V_124 = V_61 ;
V_39 -> V_125 = sizeof( struct V_22 ) ;
V_39 -> V_126 = V_127 ;
V_39 -> V_128 = & V_129 ;
V_39 -> V_130 = F_33 ;
V_39 -> V_131 = F_40 ;
V_39 -> V_132 = V_133 ;
V_3 = F_44 ( V_73 ) ;
if ( V_3 ) {
F_45 ( L_5 ,
V_39 -> V_118 , V_3 ) ;
F_46 ( V_102 ) ;
return V_3 ;
}
F_47 ( & V_102 -> V_52 , V_101 ) ;
return 0 ;
}
