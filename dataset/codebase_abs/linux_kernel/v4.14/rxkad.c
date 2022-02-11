static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
V_6 = V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
V_2 -> V_13 = V_6 -> V_14 ;
V_4 = F_4 ( L_2 , 0 , V_15 ) ;
if ( F_5 ( V_4 ) ) {
F_6 ( L_3 ) ;
V_7 = F_7 ( V_4 ) ;
goto error;
}
if ( F_8 ( V_4 , V_6 -> V_16 -> V_17 ,
sizeof( V_6 -> V_16 -> V_17 ) ) < 0 )
F_9 () ;
switch ( V_2 -> V_9 . V_18 ) {
case V_19 :
break;
case V_20 :
V_2 -> V_21 = 8 ;
V_2 -> V_22 = sizeof( struct V_23 ) ;
break;
case V_24 :
V_2 -> V_21 = 8 ;
V_2 -> V_22 = sizeof( struct V_25 ) ;
break;
default:
V_7 = - V_26 ;
goto error;
}
V_2 -> V_27 = V_4 ;
V_7 = 0 ;
error:
F_10 ( L_4 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_12 ( V_28 , V_2 -> V_27 ) ;
struct V_29 V_30 ;
struct V_31 V_32 ;
T_1 * V_33 ;
T_2 V_34 = 4 * sizeof( T_1 ) ;
F_2 ( L_5 ) ;
if ( ! V_2 -> V_9 . V_10 )
return 0 ;
V_33 = F_13 ( V_34 , V_35 ) ;
if ( ! V_33 )
return - V_36 ;
V_6 = V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_16 -> V_17 , sizeof( V_32 ) ) ;
V_33 [ 0 ] = F_14 ( V_2 -> V_37 . V_38 ) ;
V_33 [ 1 ] = F_14 ( V_2 -> V_37 . V_39 ) ;
V_33 [ 2 ] = 0 ;
V_33 [ 3 ] = F_14 ( V_2 -> V_13 ) ;
F_15 ( & V_30 , V_33 , V_34 ) ;
F_16 ( V_28 , V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 , & V_30 , V_34 , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
memcpy ( & V_2 -> V_41 , V_33 + 2 , sizeof( V_2 -> V_41 ) ) ;
F_21 ( V_33 ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_22 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
T_3 V_46 ,
void * V_47 )
{
struct V_48 * V_49 = F_23 ( V_45 ) ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_23 V_50 ;
struct V_31 V_32 ;
struct V_29 V_30 ;
T_4 V_51 ;
F_2 ( L_5 ) ;
V_51 = V_49 -> V_50 . V_52 ^ V_43 -> V_53 ;
V_46 |= ( T_3 ) V_51 << 16 ;
V_50 . V_46 = F_14 ( V_46 ) ;
memcpy ( V_47 , & V_50 , sizeof( V_50 ) ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_15 ( & V_30 , V_47 , 8 ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 , & V_30 , 8 , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_24 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
T_3 V_46 ,
void * V_47 )
{
const struct V_5 * V_6 ;
struct V_25 V_54 ;
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 16 ] ;
struct V_44 * V_55 ;
unsigned int V_56 ;
T_4 V_51 ;
int V_57 ;
int V_58 ;
V_49 = F_23 ( V_45 ) ;
F_2 ( L_5 ) ;
V_51 = V_49 -> V_50 . V_52 ^ V_43 -> V_53 ;
V_54 . V_46 = F_14 ( V_46 | ( T_3 ) V_51 << 16 ) ;
V_54 . V_59 = 0 ;
memcpy ( V_47 , & V_54 , sizeof( V_54 ) ) ;
V_6 = V_43 -> V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_16 -> V_17 , sizeof( V_32 ) ) ;
F_15 ( & V_30 [ 0 ] , V_47 , sizeof( V_54 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 [ 0 ] , & V_30 [ 0 ] , sizeof( V_54 ) , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
V_58 = - V_36 ;
if ( V_57 < 0 || V_57 > 16 )
goto V_60;
V_56 = V_46 + V_43 -> V_2 -> V_21 - 1 ;
V_56 &= ~ ( V_43 -> V_2 -> V_21 - 1 ) ;
F_26 ( V_30 , V_57 ) ;
V_58 = F_27 ( V_45 , V_30 , 0 , V_56 ) ;
if ( F_28 ( V_58 < 0 ) )
goto V_60;
F_18 ( V_28 , V_30 , V_30 , V_56 , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_10 ( L_6 ) ;
V_58 = 0 ;
V_60:
F_20 ( V_28 ) ;
return V_58 ;
}
static int F_29 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
T_2 V_46 ,
void * V_47 )
{
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 ;
T_3 V_40 , V_61 ;
int V_7 ;
V_49 = F_23 ( V_45 ) ;
F_2 ( L_7 ,
V_43 -> V_8 , F_3 ( V_43 -> V_2 -> V_9 . V_10 ) ,
V_49 -> V_50 . V_52 , V_46 ) ;
if ( ! V_43 -> V_2 -> V_27 )
return 0 ;
V_7 = F_30 ( V_43 -> V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
memcpy ( & V_32 , V_43 -> V_2 -> V_41 . V_40 , sizeof( V_32 ) ) ;
V_40 = ( V_43 -> V_39 & V_62 ) << ( 32 - V_63 ) ;
V_40 |= V_49 -> V_50 . V_52 & 0x3fffffff ;
V_43 -> V_64 [ 0 ] = F_14 ( V_43 -> V_53 ) ;
V_43 -> V_64 [ 1 ] = F_14 ( V_40 ) ;
F_15 ( & V_30 , V_43 -> V_64 , 8 ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 , & V_30 , 8 , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
V_61 = F_31 ( V_43 -> V_64 [ 1 ] ) ;
V_61 = ( V_61 >> 16 ) & 0xffff ;
if ( V_61 == 0 )
V_61 = 1 ;
V_49 -> V_50 . V_65 = V_61 ;
switch ( V_43 -> V_2 -> V_9 . V_18 ) {
case V_19 :
V_7 = 0 ;
break;
case V_20 :
V_7 = F_22 ( V_43 , V_45 , V_46 , V_47 ) ;
break;
case V_24 :
V_7 = F_24 ( V_43 , V_45 , V_46 ,
V_47 ) ;
break;
default:
V_7 = - V_66 ;
break;
}
F_10 ( L_8 , V_7 , V_61 ) ;
return V_7 ;
}
static int F_32 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int V_67 , unsigned int V_56 ,
T_5 V_52 )
{
struct V_23 V_47 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 16 ] ;
struct V_44 * V_55 ;
bool V_68 ;
T_3 V_46 , V_69 ;
T_4 V_51 ;
int V_57 , V_7 ;
F_2 ( L_5 ) ;
if ( V_56 < 8 ) {
V_68 = F_33 ( V_43 , V_45 , L_9 , L_10 ,
V_70 ) ;
goto V_71;
}
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
if ( V_57 < 0 || V_57 > 16 )
goto V_72;
F_26 ( V_30 , V_57 ) ;
V_7 = F_27 ( V_45 , V_30 , V_67 , 8 ) ;
if ( F_28 ( V_7 < 0 ) )
return V_7 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , 8 , V_32 . V_40 ) ;
F_34 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( F_35 ( V_45 , V_67 , & V_47 , sizeof( V_47 ) ) < 0 ) {
V_68 = F_33 ( V_43 , V_45 , L_11 , L_12 ,
V_73 ) ;
goto V_71;
}
V_67 += sizeof( V_47 ) ;
V_56 -= sizeof( V_47 ) ;
V_69 = F_31 ( V_47 . V_46 ) ;
V_46 = V_69 & 0xffff ;
V_51 = V_69 >> 16 ;
V_51 ^= V_52 ^ V_43 -> V_53 ;
V_51 &= 0xffff ;
if ( V_51 != 0 ) {
V_68 = F_33 ( V_43 , V_45 , L_13 , L_14 ,
V_70 ) ;
goto V_71;
}
if ( V_46 > V_56 ) {
V_68 = F_33 ( V_43 , V_45 , L_15 , L_16 ,
V_73 ) ;
goto V_71;
}
F_10 ( L_17 , V_46 ) ;
return 0 ;
V_71:
if ( V_68 )
F_36 ( V_43 ) ;
return - V_74 ;
V_72:
F_10 ( L_18 ) ;
return - V_36 ;
}
static int F_37 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int V_67 , unsigned int V_56 ,
T_5 V_52 )
{
const struct V_5 * V_6 ;
struct V_25 V_47 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_75 [ 4 ] , * V_30 ;
struct V_44 * V_55 ;
bool V_68 ;
T_3 V_46 , V_69 ;
T_4 V_51 ;
int V_57 , V_7 ;
F_2 ( L_19 , V_45 -> V_56 ) ;
if ( V_56 < 8 ) {
V_68 = F_33 ( V_43 , V_45 , L_20 , L_21 ,
V_70 ) ;
goto V_71;
}
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
if ( V_57 < 0 )
goto V_72;
V_30 = V_75 ;
if ( F_28 ( V_57 > 4 ) ) {
V_30 = F_13 ( sizeof( * V_30 ) * V_57 , V_76 ) ;
if ( ! V_30 )
goto V_72;
}
F_26 ( V_30 , V_57 ) ;
V_7 = F_27 ( V_45 , V_30 , V_67 , V_56 ) ;
if ( F_28 ( V_7 < 0 ) ) {
if ( V_30 != V_75 )
F_21 ( V_30 ) ;
return V_7 ;
}
V_6 = V_43 -> V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_16 -> V_17 , sizeof( V_32 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , V_56 , V_32 . V_40 ) ;
F_34 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( V_30 != V_75 )
F_21 ( V_30 ) ;
if ( F_35 ( V_45 , V_67 , & V_47 , sizeof( V_47 ) ) < 0 ) {
V_68 = F_33 ( V_43 , V_45 , L_22 , L_23 ,
V_73 ) ;
goto V_71;
}
V_67 += sizeof( V_47 ) ;
V_56 -= sizeof( V_47 ) ;
V_69 = F_31 ( V_47 . V_46 ) ;
V_46 = V_69 & 0xffff ;
V_51 = V_69 >> 16 ;
V_51 ^= V_52 ^ V_43 -> V_53 ;
V_51 &= 0xffff ;
if ( V_51 != 0 ) {
V_68 = F_33 ( V_43 , V_45 , L_24 , L_25 ,
V_70 ) ;
goto V_71;
}
if ( V_46 > V_56 ) {
V_68 = F_33 ( V_43 , V_45 , L_26 , L_27 ,
V_73 ) ;
goto V_71;
}
F_10 ( L_17 , V_46 ) ;
return 0 ;
V_71:
if ( V_68 )
F_36 ( V_43 ) ;
return - V_74 ;
V_72:
F_10 ( L_18 ) ;
return - V_36 ;
}
static int F_38 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int V_67 , unsigned int V_56 ,
T_5 V_52 , T_4 V_77 )
{
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 ;
bool V_68 ;
T_4 V_65 ;
T_3 V_40 , V_61 ;
F_2 ( L_28 ,
V_43 -> V_8 , F_3 ( V_43 -> V_2 -> V_9 . V_10 ) , V_52 ) ;
if ( ! V_43 -> V_2 -> V_27 )
return 0 ;
memcpy ( & V_32 , V_43 -> V_2 -> V_41 . V_40 , sizeof( V_32 ) ) ;
V_40 = ( V_43 -> V_39 & V_62 ) << ( 32 - V_63 ) ;
V_40 |= V_52 & 0x3fffffff ;
V_43 -> V_64 [ 0 ] = F_14 ( V_43 -> V_53 ) ;
V_43 -> V_64 [ 1 ] = F_14 ( V_40 ) ;
F_15 ( & V_30 , V_43 -> V_64 , 8 ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 , & V_30 , 8 , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
V_61 = F_31 ( V_43 -> V_64 [ 1 ] ) ;
V_65 = ( V_61 >> 16 ) & 0xffff ;
if ( V_65 == 0 )
V_65 = 1 ;
if ( V_65 != V_77 ) {
V_68 = F_33 ( V_43 , V_45 , L_29 , L_30 ,
V_70 ) ;
goto V_71;
}
switch ( V_43 -> V_2 -> V_9 . V_18 ) {
case V_19 :
return 0 ;
case V_20 :
return F_32 ( V_43 , V_45 , V_67 , V_56 , V_52 ) ;
case V_24 :
return F_37 ( V_43 , V_45 , V_67 , V_56 , V_52 ) ;
default:
return - V_78 ;
}
V_71:
if ( V_68 )
F_36 ( V_43 ) ;
return - V_74 ;
}
static void F_39 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int * V_79 , unsigned int * V_80 )
{
struct V_23 V_47 ;
if ( F_35 ( V_45 , * V_79 , & V_47 , sizeof( V_47 ) ) < 0 )
F_9 () ;
* V_79 += sizeof( V_47 ) ;
* V_80 = F_31 ( V_47 . V_46 ) & 0xffff ;
}
static void F_40 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int * V_79 , unsigned int * V_80 )
{
struct V_25 V_47 ;
if ( F_35 ( V_45 , * V_79 , & V_47 , sizeof( V_47 ) ) < 0 )
F_9 () ;
* V_79 += sizeof( V_47 ) ;
* V_80 = F_31 ( V_47 . V_46 ) & 0xffff ;
}
static void F_41 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int * V_79 , unsigned int * V_80 )
{
switch ( V_43 -> V_2 -> V_9 . V_18 ) {
case V_20 :
F_39 ( V_43 , V_45 , V_79 , V_80 ) ;
return;
case V_24 :
F_40 ( V_43 , V_45 , V_79 , V_80 ) ;
return;
default:
return;
}
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
struct V_83 V_84 ;
struct V_85 V_86 ;
struct V_87 V_88 [ 2 ] ;
T_2 V_56 ;
T_3 V_89 ;
int V_7 ;
F_2 ( L_31 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
V_7 = F_30 ( V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
F_43 ( & V_2 -> V_90 , sizeof( V_2 -> V_90 ) ) ;
V_82 . V_91 = F_14 ( 2 ) ;
V_82 . V_92 = F_14 ( V_2 -> V_90 ) ;
V_82 . V_93 = F_14 ( 0 ) ;
V_82 . V_94 = 0 ;
V_86 . V_95 = & V_2 -> V_9 . V_96 -> V_97 . V_98 ;
V_86 . V_99 = V_2 -> V_9 . V_96 -> V_97 . V_100 ;
V_86 . V_101 = NULL ;
V_86 . V_102 = 0 ;
V_86 . V_103 = 0 ;
V_84 . V_38 = F_14 ( V_2 -> V_37 . V_38 ) ;
V_84 . V_39 = F_14 ( V_2 -> V_37 . V_39 ) ;
V_84 . V_104 = 0 ;
V_84 . V_52 = 0 ;
V_84 . type = V_105 ;
V_84 . V_106 = V_2 -> V_107 ;
V_84 . V_108 = 0 ;
V_84 . V_109 = V_2 -> V_13 ;
V_84 . V_110 = 0 ;
V_84 . V_111 = F_44 ( V_2 -> V_112 ) ;
V_88 [ 0 ] . V_113 = & V_84 ;
V_88 [ 0 ] . V_114 = sizeof( V_84 ) ;
V_88 [ 1 ] . V_113 = & V_82 ;
V_88 [ 1 ] . V_114 = sizeof( V_82 ) ;
V_56 = V_88 [ 0 ] . V_114 + V_88 [ 1 ] . V_114 ;
V_89 = F_45 ( & V_2 -> V_89 ) ;
V_84 . V_89 = F_14 ( V_89 ) ;
F_46 ( L_32 , V_89 ) ;
V_7 = F_47 ( V_2 -> V_9 . V_115 -> V_116 , & V_86 , V_88 , 2 , V_56 ) ;
if ( V_7 < 0 ) {
F_6 ( L_33 , V_7 ) ;
return - V_117 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_118 * V_50 ,
struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
struct V_83 V_84 ;
struct V_85 V_86 ;
struct V_87 V_88 [ 3 ] ;
T_2 V_56 ;
T_3 V_89 ;
int V_7 ;
F_2 ( L_5 ) ;
V_86 . V_95 = & V_2 -> V_9 . V_96 -> V_97 . V_98 ;
V_86 . V_99 = V_2 -> V_9 . V_96 -> V_97 . V_100 ;
V_86 . V_101 = NULL ;
V_86 . V_102 = 0 ;
V_86 . V_103 = 0 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_38 = F_14 ( V_50 -> V_38 ) ;
V_84 . V_39 = F_14 ( V_50 -> V_39 ) ;
V_84 . type = V_123 ;
V_84 . V_106 = V_2 -> V_107 ;
V_84 . V_109 = V_50 -> V_109 ;
V_84 . V_111 = F_44 ( V_50 -> V_111 ) ;
V_88 [ 0 ] . V_113 = & V_84 ;
V_88 [ 0 ] . V_114 = sizeof( V_84 ) ;
V_88 [ 1 ] . V_113 = V_120 ;
V_88 [ 1 ] . V_114 = sizeof( * V_120 ) ;
V_88 [ 2 ] . V_113 = ( void * ) V_122 -> V_124 ;
V_88 [ 2 ] . V_114 = V_122 -> V_125 ;
V_56 = V_88 [ 0 ] . V_114 + V_88 [ 1 ] . V_114 + V_88 [ 2 ] . V_114 ;
V_89 = F_45 ( & V_2 -> V_89 ) ;
V_84 . V_89 = F_14 ( V_89 ) ;
F_46 ( L_34 , V_89 ) ;
V_7 = F_47 ( V_2 -> V_9 . V_115 -> V_116 , & V_86 , V_88 , 3 , V_56 ) ;
if ( V_7 < 0 ) {
F_6 ( L_33 , V_7 ) ;
return - V_117 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static void F_49 ( struct V_119 * V_126 )
{
T_3 V_127 = 1000003 ;
int V_128 ;
T_6 * V_129 = ( T_6 * ) V_126 ;
for ( V_128 = sizeof( * V_126 ) ; V_128 > 0 ; V_128 -- )
V_127 = V_127 * 0x10204081 + * V_129 ++ ;
V_126 -> V_130 . V_59 = F_14 ( V_127 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_119 * V_120 ,
const struct V_121 * V_122 )
{
F_12 ( V_28 , V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 1 ] ;
memcpy ( & V_32 , V_122 -> V_17 , sizeof( V_32 ) ) ;
F_26 ( V_30 , 1 ) ;
F_51 ( V_30 , & V_120 -> V_130 , sizeof( V_120 -> V_130 ) ) ;
F_16 ( V_28 , V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , sizeof( V_120 -> V_130 ) , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_3 * V_131 )
{
const struct V_5 * V_6 ;
struct V_81 V_82 ;
struct V_119 V_120
V_132 ( ( F_53 ( 8 ) ) ) ;
struct V_48 * V_49 = F_23 ( V_45 ) ;
const char * V_133 ;
T_3 V_91 , V_92 , V_93 , V_134 ;
int V_7 ;
F_2 ( L_31 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
V_133 = F_54 ( L_35 ) ;
V_134 = V_135 ;
if ( ! V_2 -> V_9 . V_10 )
goto V_71;
V_134 = V_136 ;
V_7 = F_30 ( V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 )
goto V_137;
V_133 = F_54 ( L_36 ) ;
V_134 = V_138 ;
if ( F_35 ( V_45 , sizeof( struct V_83 ) ,
& V_82 , sizeof( V_82 ) ) < 0 )
goto V_71;
V_91 = F_31 ( V_82 . V_91 ) ;
V_92 = F_31 ( V_82 . V_92 ) ;
V_93 = F_31 ( V_82 . V_93 ) ;
F_46 ( L_37 ,
V_49 -> V_50 . V_89 , V_91 , V_92 , V_93 ) ;
V_133 = F_54 ( L_38 ) ;
V_134 = V_139 ;
if ( V_91 != V_140 )
goto V_71;
V_134 = V_141 ;
V_7 = - V_142 ;
if ( V_2 -> V_9 . V_18 < V_93 )
goto V_137;
V_6 = V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_91 = F_14 ( V_140 ) ;
V_120 . V_130 . V_38 = F_14 ( V_2 -> V_37 . V_38 ) ;
V_120 . V_130 . V_39 = F_14 ( V_2 -> V_37 . V_39 ) ;
V_120 . V_130 . V_109 = F_14 ( V_2 -> V_13 ) ;
V_120 . V_130 . V_143 = F_14 ( V_92 + 1 ) ;
V_120 . V_130 . V_144 = F_14 ( V_2 -> V_9 . V_18 ) ;
V_120 . V_145 = F_14 ( V_6 -> V_16 -> V_145 ) ;
V_120 . V_125 = F_14 ( V_6 -> V_16 -> V_125 ) ;
V_120 . V_130 . V_53 [ 0 ] = F_14 ( V_2 -> V_146 [ 0 ] . V_147 ) ;
V_120 . V_130 . V_53 [ 1 ] = F_14 ( V_2 -> V_146 [ 1 ] . V_147 ) ;
V_120 . V_130 . V_53 [ 2 ] = F_14 ( V_2 -> V_146 [ 2 ] . V_147 ) ;
V_120 . V_130 . V_53 [ 3 ] = F_14 ( V_2 -> V_146 [ 3 ] . V_147 ) ;
F_49 ( & V_120 ) ;
F_50 ( V_2 , & V_120 , V_6 -> V_16 ) ;
return F_48 ( V_2 , & V_49 -> V_50 , & V_120 , V_6 -> V_16 ) ;
V_71:
F_55 ( NULL , V_49 -> V_50 . V_89 , V_133 ) ;
V_7 = - V_74 ;
V_137:
* V_131 = V_134 ;
return V_7 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
void * V_124 , T_2 V_125 ,
struct V_31 * V_148 ,
T_7 * V_149 ,
T_3 * V_131 )
{
struct V_150 * V_28 ;
struct V_48 * V_49 = F_23 ( V_45 ) ;
struct V_31 V_32 , V_10 ;
struct V_29 V_30 [ 1 ] ;
struct V_151 V_152 ;
unsigned int V_153 ;
const char * V_133 ;
T_7 V_154 , V_155 ;
bool V_156 ;
int V_7 ;
T_3 V_134 ;
T_6 * V_129 , * V_157 , * V_158 , * V_159 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_160 ) ) ;
* V_149 = 0 ;
V_7 = F_30 ( V_2 -> V_160 ) ;
if ( V_7 < 0 ) {
switch ( V_7 ) {
case - V_161 :
V_134 = V_136 ;
goto V_137;
default:
V_134 = V_162 ;
goto V_137;
}
}
ASSERT ( V_2 -> V_160 -> V_11 . V_12 [ 0 ] != NULL ) ;
F_57 ( ( unsigned long ) V_124 & 7UL , == , 0 ) ;
memcpy ( & V_32 , & V_2 -> V_160 -> V_11 . V_12 [ 2 ] , sizeof( V_32 ) ) ;
V_7 = - V_36 ;
V_28 = F_58 ( V_2 -> V_160 -> V_11 . V_12 [ 0 ] ,
V_163 ) ;
if ( ! V_28 )
goto V_164;
F_15 ( & V_30 [ 0 ] , V_124 , V_125 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , V_125 , V_32 . V_40 ) ;
F_34 ( V_28 ) ;
F_59 ( V_28 ) ;
V_129 = V_124 ;
V_159 = V_129 + V_125 ;
#define F_60 ( T_8 ) \
({ \
u8 *__str = p; \
eproto = tracepoint_string("rxkad_bad_"#field); \
q = memchr(p, 0, end - p); \
if (!q || q - p > (field##_SZ)) \
goto bad_ticket; \
for (; p < q; p++) \
if (!isprint(*p)) \
goto bad_ticket; \
p++; \
__str; \
})
F_6 ( L_39 , * V_129 ) ;
V_156 = * V_129 & 1 ;
V_129 ++ ;
V_158 = F_60 ( V_165 ) ;
F_6 ( L_40 , V_158 ) ;
V_158 = F_60 ( V_166 ) ;
F_6 ( L_41 , V_158 ) ;
V_158 = F_60 ( V_167 ) ;
F_6 ( L_42 , V_158 ) ;
V_133 = F_54 ( L_43 ) ;
if ( V_159 - V_129 < 4 + 8 + 4 + 2 )
goto V_168;
memcpy ( & V_152 , V_129 , sizeof( V_152 ) ) ;
V_129 += 4 ;
F_6 ( L_44 , & V_152 ) ;
memcpy ( & V_10 , V_129 , sizeof( V_10 ) ) ;
V_129 += 8 ;
F_6 ( L_45 , F_31 ( V_10 . V_169 [ 0 ] ) , F_31 ( V_10 . V_169 [ 1 ] ) ) ;
memcpy ( V_148 , & V_10 , sizeof( V_10 ) ) ;
V_153 = * V_129 ++ * 5 * 60 ;
F_6 ( L_46 , V_153 ) ;
if ( V_156 ) {
T_9 V_170 ;
memcpy ( & V_170 , V_129 , 4 ) ;
V_154 = F_61 ( F_62 ( V_170 ) ) ;
} else {
T_1 V_170 ;
memcpy ( & V_170 , V_129 , 4 ) ;
V_154 = F_61 ( F_63 ( V_170 ) ) ;
}
V_129 += 4 ;
V_155 = F_64 () ;
F_6 ( L_47 , V_154 , V_155 ) ;
if ( V_154 > V_155 ) {
V_134 = V_162 ;
V_7 = - V_26 ;
goto V_137;
}
if ( V_154 < V_155 - V_153 ) {
V_134 = V_136 ;
V_7 = - V_161 ;
goto V_137;
}
* V_149 = V_154 + V_153 ;
V_158 = F_60 ( V_171 ) ;
F_6 ( L_48 , V_158 ) ;
V_158 = F_60 ( V_166 ) ;
F_6 ( L_49 , V_158 ) ;
return 0 ;
V_168:
F_55 ( NULL , V_49 -> V_50 . V_89 , V_133 ) ;
V_134 = V_172 ;
V_7 = - V_74 ;
V_137:
* V_131 = V_134 ;
return V_7 ;
V_164:
return V_7 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_119 * V_120 ,
const struct V_31 * V_17 )
{
F_12 ( V_28 , V_173 ) ;
struct V_29 V_30 [ 1 ] ;
struct V_31 V_32 ;
F_2 ( L_50 ,
F_31 ( V_17 -> V_169 [ 0 ] ) , F_31 ( V_17 -> V_169 [ 1 ] ) ) ;
ASSERT ( V_173 != NULL ) ;
F_66 ( & V_174 ) ;
if ( F_8 ( V_173 , V_17 -> V_40 ,
sizeof( * V_17 ) ) < 0 )
F_9 () ;
memcpy ( & V_32 , V_17 , sizeof( V_32 ) ) ;
F_26 ( V_30 , 1 ) ;
F_51 ( V_30 , & V_120 -> V_130 , sizeof( V_120 -> V_130 ) ) ;
F_16 ( V_28 , V_173 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , sizeof( V_120 -> V_130 ) , V_32 . V_40 ) ;
F_34 ( V_28 ) ;
F_20 ( V_28 ) ;
F_67 ( & V_174 ) ;
F_10 ( L_5 ) ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_3 * V_131 )
{
struct V_119 V_126
V_132 ( ( F_53 ( 8 ) ) ) ;
struct V_48 * V_49 = F_23 ( V_45 ) ;
struct V_31 V_17 ;
const char * V_133 ;
T_7 V_175 ;
void * V_124 ;
T_3 V_134 , V_91 , V_145 , V_125 , V_144 ;
T_1 V_127 ;
int V_7 , V_176 ;
F_2 ( L_31 , V_2 -> V_8 , F_3 ( V_2 -> V_160 ) ) ;
V_133 = F_54 ( L_51 ) ;
V_134 = V_138 ;
if ( F_35 ( V_45 , sizeof( struct V_83 ) ,
& V_126 , sizeof( V_126 ) ) < 0 )
goto V_71;
if ( ! F_69 ( V_45 , sizeof( V_126 ) ) )
F_9 () ;
V_91 = F_31 ( V_126 . V_91 ) ;
V_125 = F_31 ( V_126 . V_125 ) ;
V_145 = F_31 ( V_126 . V_145 ) ;
F_46 ( L_52 ,
V_49 -> V_50 . V_89 , V_91 , V_145 , V_125 ) ;
V_133 = F_54 ( L_53 ) ;
V_134 = V_139 ;
if ( V_91 != V_140 )
goto V_71;
V_133 = F_54 ( L_54 ) ;
V_134 = V_177 ;
if ( V_125 < 4 || V_125 > V_178 )
goto V_71;
V_133 = F_54 ( L_55 ) ;
V_134 = V_179 ;
if ( V_145 >= V_180 )
goto V_71;
V_7 = - V_36 ;
V_124 = F_13 ( V_125 , V_163 ) ;
if ( ! V_124 )
goto V_164;
V_133 = F_54 ( L_56 ) ;
V_134 = V_138 ;
if ( F_35 ( V_45 , sizeof( struct V_83 ) ,
V_124 , V_125 ) < 0 )
goto V_181;
V_7 = F_56 ( V_2 , V_45 , V_124 , V_125 , & V_17 ,
& V_175 , V_131 ) ;
if ( V_7 < 0 )
goto V_182;
F_65 ( V_2 , & V_126 , & V_17 ) ;
V_133 = F_54 ( L_57 ) ;
V_134 = V_70 ;
if ( F_31 ( V_126 . V_130 . V_38 ) != V_2 -> V_37 . V_38 )
goto V_181;
if ( F_31 ( V_126 . V_130 . V_39 ) != V_2 -> V_37 . V_39 )
goto V_181;
if ( F_31 ( V_126 . V_130 . V_109 ) != V_2 -> V_13 )
goto V_181;
V_127 = V_126 . V_130 . V_59 ;
V_126 . V_130 . V_59 = 0 ;
F_49 ( & V_126 ) ;
V_133 = F_54 ( L_58 ) ;
if ( V_126 . V_130 . V_59 != V_127 )
goto V_181;
F_70 ( & V_2 -> V_183 ) ;
for ( V_176 = 0 ; V_176 < V_184 ; V_176 ++ ) {
struct V_42 * V_43 ;
T_3 V_53 = F_31 ( V_126 . V_130 . V_53 [ V_176 ] ) ;
V_133 = F_54 ( L_59 ) ;
if ( V_53 > V_185 )
goto V_186;
V_133 = F_54 ( L_60 ) ;
if ( V_53 < V_2 -> V_146 [ V_176 ] . V_147 )
goto V_186;
V_133 = F_54 ( L_61 ) ;
if ( V_53 > V_2 -> V_146 [ V_176 ] . V_147 ) {
V_43 = F_71 (
V_2 -> V_146 [ V_176 ] . V_43 ,
F_72 ( & V_2 -> V_183 ) ) ;
if ( V_43 && V_43 -> V_187 < V_188 )
goto V_186;
V_2 -> V_146 [ V_176 ] . V_147 = V_53 ;
}
}
F_73 ( & V_2 -> V_183 ) ;
V_133 = F_54 ( L_62 ) ;
V_134 = V_189 ;
if ( F_31 ( V_126 . V_130 . V_143 ) != V_2 -> V_90 + 1 )
goto V_181;
V_133 = F_54 ( L_63 ) ;
V_134 = V_141 ;
V_144 = F_31 ( V_126 . V_130 . V_144 ) ;
if ( V_144 > V_24 )
goto V_181;
V_2 -> V_9 . V_18 = V_144 ;
V_7 = F_74 ( V_2 , & V_17 , V_175 , V_145 ) ;
if ( V_7 < 0 )
goto V_182;
F_21 ( V_124 ) ;
F_10 ( L_6 ) ;
return 0 ;
V_186:
F_73 ( & V_2 -> V_183 ) ;
V_181:
F_21 ( V_124 ) ;
V_71:
F_55 ( NULL , V_49 -> V_50 . V_89 , V_133 ) ;
* V_131 = V_134 ;
return - V_74 ;
V_182:
F_21 ( V_124 ) ;
V_164:
return V_7 ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( V_2 -> V_27 )
F_76 ( V_2 -> V_27 ) ;
}
static int F_77 ( void )
{
V_173 = F_4 ( L_2 , 0 , V_15 ) ;
return F_78 ( V_173 ) ;
}
static void F_79 ( void )
{
if ( V_173 )
F_76 ( V_173 ) ;
}
