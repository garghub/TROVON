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
}
if ( V_14 )
V_25 = F_15 ( & V_9 -> V_20 , V_5 -> V_16 ) ;
if ( V_28 ) {
int V_45 = V_27 - ( V_31 & ( V_27 - 1 ) ) ;
V_9 -> V_37 += V_45 ;
memset ( V_9 -> V_46 , 0 , sizeof( V_9 -> V_46 ) ) ;
V_9 -> V_46 [ 0 ] = 0x80 ;
F_12 ( & V_9 -> V_47 , V_9 -> V_46 , V_45 ) ;
V_25 = F_15 ( & V_9 -> V_20 , & V_9 -> V_47 ) ;
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
static int F_24 ( struct V_6 * V_7 , const T_3 * V_58 ,
unsigned int V_34 )
{
struct V_22 * V_23 = F_25 ( F_11 ( V_7 ) ) ;
struct V_68 * V_69 =
V_68 ( F_11 ( V_7 ) ) ;
T_2 V_70 , V_71 , V_72 , V_73 , V_74 , V_75 ;
T_2 V_76 = 0x00 , V_77 = 0x87 ;
T_4 * V_78 ;
int V_3 ;
switch ( V_34 ) {
case V_79 :
V_23 -> V_32 . V_33 . type = V_80 ;
break;
case V_81 :
V_23 -> V_32 . V_33 . type = V_82 ;
break;
case V_83 :
V_23 -> V_32 . V_33 . type = V_84 ;
break;
default:
F_26 ( V_7 , V_85 ) ;
return - V_35 ;
}
V_23 -> V_32 . V_33 . V_55 = V_69 -> V_55 ;
V_23 -> V_32 . V_33 . V_34 = 0 ;
V_3 = F_27 ( V_23 -> V_32 . V_33 . V_86 , V_58 , V_34 ) ;
if ( V_3 )
return V_3 ;
memset ( V_23 -> V_32 . V_33 . V_58 , 0 , sizeof( V_23 -> V_32 . V_33 . V_58 ) ) ;
F_28 ( V_23 -> V_32 . V_33 . V_86 , V_23 -> V_32 . V_33 . V_58 ,
V_23 -> V_32 . V_33 . V_58 ) ;
V_70 = F_29 ( * ( ( T_4 * ) V_23 -> V_32 . V_33 . V_58 ) ) ;
V_71 = F_29 ( * ( ( T_4 * ) V_23 -> V_32 . V_33 . V_58 + 1 ) ) ;
V_72 = ( V_70 << 1 ) | ( V_71 >> 63 ) ;
V_73 = V_71 << 1 ;
if ( V_23 -> V_32 . V_33 . V_58 [ 0 ] & 0x80 ) {
V_72 ^= V_76 ;
V_73 ^= V_77 ;
}
V_78 = ( T_4 * ) V_23 -> V_32 . V_33 . V_87 ;
* V_78 = F_30 ( V_72 ) ;
V_78 ++ ;
* V_78 = F_30 ( V_73 ) ;
V_74 = ( V_72 << 1 ) | ( V_73 >> 63 ) ;
V_75 = V_73 << 1 ;
if ( V_23 -> V_32 . V_33 . V_87 [ 0 ] & 0x80 ) {
V_74 ^= V_76 ;
V_75 ^= V_77 ;
}
V_78 = ( T_4 * ) V_23 -> V_32 . V_33 . V_88 ;
* V_78 = F_30 ( V_74 ) ;
V_78 ++ ;
* V_78 = F_30 ( V_75 ) ;
V_23 -> V_32 . V_33 . V_66 = sizeof( V_23 -> V_32 . V_33 . V_87 ) ;
F_12 ( & V_23 -> V_32 . V_33 . V_50 , V_23 -> V_32 . V_33 . V_87 , sizeof( V_23 -> V_32 . V_33 . V_87 ) ) ;
F_12 ( & V_23 -> V_32 . V_33 . V_49 , V_23 -> V_32 . V_33 . V_88 , sizeof( V_23 -> V_32 . V_33 . V_88 ) ) ;
memset ( V_23 -> V_32 . V_33 . V_58 , 0 , sizeof( V_23 -> V_32 . V_33 . V_58 ) ) ;
memcpy ( V_23 -> V_32 . V_33 . V_58 , V_58 , V_34 ) ;
V_23 -> V_32 . V_33 . V_34 = V_34 ;
F_12 ( & V_23 -> V_32 . V_33 . V_59 , V_23 -> V_32 . V_33 . V_58 , V_34 ) ;
return V_3 ;
}
static int F_31 ( struct V_89 * V_7 )
{
struct V_22 * V_23 = F_25 ( V_7 ) ;
struct V_6 * V_90 = F_32 ( V_7 ) ;
struct V_91 * V_92 ;
V_23 -> V_93 = F_1 ;
V_23 -> V_32 . V_33 . V_34 = 0 ;
F_33 ( V_90 , sizeof( struct V_8 ) ) ;
V_92 = F_34 ( L_1 , 0 ,
V_94 |
V_95 ) ;
if ( F_35 ( V_92 ) ) {
F_36 ( L_2 ) ;
return F_37 ( V_92 ) ;
}
V_23 -> V_32 . V_33 . V_86 = V_92 ;
return 0 ;
}
static void F_38 ( struct V_89 * V_7 )
{
struct V_22 * V_23 = F_25 ( V_7 ) ;
if ( V_23 -> V_32 . V_33 . V_86 )
F_39 ( V_23 -> V_32 . V_33 . V_86 ) ;
V_23 -> V_32 . V_33 . V_86 = NULL ;
}
int F_40 ( struct V_96 * V_97 )
{
struct V_68 * V_98 ;
struct V_99 * V_69 ;
struct V_100 * V_101 ;
struct V_102 * V_39 ;
int V_3 ;
V_98 = F_41 ( sizeof( * V_98 ) , V_42 ) ;
if ( ! V_98 )
return - V_103 ;
F_17 ( & V_98 -> V_52 ) ;
V_98 -> V_55 = V_104 ;
V_69 = & V_98 -> V_69 ;
V_69 -> V_105 = F_19 ;
V_69 -> V_106 = F_20 ;
V_69 -> V_21 = F_21 ;
V_69 -> V_107 = F_22 ;
V_69 -> V_108 = F_23 ;
V_69 -> V_109 = F_24 ;
V_101 = & V_69 -> V_101 ;
V_101 -> V_110 = V_61 ;
V_39 = & V_101 -> V_39 ;
snprintf ( V_39 -> V_111 , V_112 , L_3 ) ;
snprintf ( V_39 -> V_113 , V_112 , L_4 ) ;
V_39 -> V_114 = V_115 | V_94 |
V_116 |
V_95 ;
V_39 -> V_117 = V_61 ;
V_39 -> V_118 = sizeof( struct V_22 ) ;
V_39 -> V_119 = V_120 ;
V_39 -> V_121 = & V_122 ;
V_39 -> V_123 = F_31 ;
V_39 -> V_124 = F_38 ;
V_39 -> V_125 = V_126 ;
V_3 = F_42 ( V_69 ) ;
if ( V_3 ) {
F_43 ( L_5 ,
V_39 -> V_111 , V_3 ) ;
F_44 ( V_98 ) ;
return V_3 ;
}
F_45 ( & V_98 -> V_52 , V_97 ) ;
return 0 ;
}
