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
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_23 V_50 ;
struct V_31 V_32 ;
struct V_29 V_30 ;
T_4 V_51 ;
V_49 = F_23 ( V_45 ) ;
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
F_27 ( V_45 , V_30 , 0 , V_56 ) ;
F_18 ( V_28 , V_30 , V_30 , V_56 , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_10 ( L_6 ) ;
V_58 = 0 ;
V_60:
F_20 ( V_28 ) ;
return V_58 ;
}
static int F_28 ( struct V_42 * V_43 ,
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
V_7 = F_29 ( V_43 -> V_2 -> V_9 . V_10 ) ;
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
V_61 = F_30 ( V_43 -> V_64 [ 1 ] ) ;
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
static int F_31 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int V_67 , unsigned int V_56 ,
T_5 V_52 )
{
struct V_23 V_47 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 16 ] ;
struct V_44 * V_55 ;
T_3 V_46 , V_68 ;
T_4 V_51 ;
int V_57 ;
F_2 ( L_5 ) ;
if ( V_56 < 8 ) {
F_32 ( L_9 , V_43 , V_52 , V_69 , V_70 ) ;
goto V_71;
}
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
if ( V_57 < 0 || V_57 > 16 )
goto V_72;
F_26 ( V_30 , V_57 ) ;
F_27 ( V_45 , V_30 , V_67 , 8 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , 8 , V_32 . V_40 ) ;
F_33 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( F_34 ( V_45 , V_67 , & V_47 , sizeof( V_47 ) ) < 0 ) {
F_32 ( L_10 , V_43 , V_52 , V_73 , V_70 ) ;
goto V_71;
}
V_67 += sizeof( V_47 ) ;
V_56 -= sizeof( V_47 ) ;
V_68 = F_30 ( V_47 . V_46 ) ;
V_46 = V_68 & 0xffff ;
V_51 = V_68 >> 16 ;
V_51 ^= V_52 ^ V_43 -> V_53 ;
V_51 &= 0xffff ;
if ( V_51 != 0 ) {
F_32 ( L_11 , V_43 , V_52 , V_69 , V_70 ) ;
goto V_71;
}
if ( V_46 > V_56 ) {
F_32 ( L_12 , V_43 , V_52 , V_73 , V_70 ) ;
goto V_71;
}
F_10 ( L_13 , V_46 ) ;
return 0 ;
V_71:
F_35 ( V_43 ) ;
F_10 ( L_14 ) ;
return - V_70 ;
V_72:
F_10 ( L_15 ) ;
return - V_36 ;
}
static int F_36 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int V_67 , unsigned int V_56 ,
T_5 V_52 )
{
const struct V_5 * V_6 ;
struct V_25 V_47 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_74 [ 4 ] , * V_30 ;
struct V_44 * V_55 ;
T_3 V_46 , V_68 ;
T_4 V_51 ;
int V_57 ;
F_2 ( L_16 , V_45 -> V_56 ) ;
if ( V_56 < 8 ) {
F_32 ( L_17 , V_43 , V_52 , V_69 , V_70 ) ;
goto V_71;
}
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
if ( V_57 < 0 )
goto V_72;
V_30 = V_74 ;
if ( F_37 ( V_57 > 4 ) ) {
V_30 = F_13 ( sizeof( * V_30 ) * V_57 , V_75 ) ;
if ( ! V_30 )
goto V_72;
}
F_26 ( V_30 , V_57 ) ;
F_27 ( V_45 , V_30 , V_67 , V_56 ) ;
V_6 = V_43 -> V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_16 -> V_17 , sizeof( V_32 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , V_56 , V_32 . V_40 ) ;
F_33 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( V_30 != V_74 )
F_21 ( V_30 ) ;
if ( F_34 ( V_45 , V_67 , & V_47 , sizeof( V_47 ) ) < 0 ) {
F_32 ( L_18 , V_43 , V_52 , V_73 , V_70 ) ;
goto V_71;
}
V_67 += sizeof( V_47 ) ;
V_56 -= sizeof( V_47 ) ;
V_68 = F_30 ( V_47 . V_46 ) ;
V_46 = V_68 & 0xffff ;
V_51 = V_68 >> 16 ;
V_51 ^= V_52 ^ V_43 -> V_53 ;
V_51 &= 0xffff ;
if ( V_51 != 0 ) {
F_32 ( L_19 , V_43 , V_52 , V_69 , V_70 ) ;
goto V_71;
}
if ( V_46 > V_56 ) {
F_32 ( L_20 , V_43 , V_52 , V_73 , V_70 ) ;
goto V_71;
}
F_10 ( L_13 , V_46 ) ;
return 0 ;
V_71:
F_35 ( V_43 ) ;
F_10 ( L_14 ) ;
return - V_70 ;
V_72:
F_10 ( L_15 ) ;
return - V_36 ;
}
static int F_38 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int V_67 , unsigned int V_56 ,
T_5 V_52 , T_4 V_76 )
{
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 ;
T_4 V_65 ;
T_3 V_40 , V_61 ;
F_2 ( L_21 ,
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
V_61 = F_30 ( V_43 -> V_64 [ 1 ] ) ;
V_65 = ( V_61 >> 16 ) & 0xffff ;
if ( V_65 == 0 )
V_65 = 1 ;
if ( V_65 != V_76 ) {
F_32 ( L_22 , V_43 , V_52 , V_69 , V_70 ) ;
F_35 ( V_43 ) ;
F_10 ( L_23 ) ;
return - V_70 ;
}
switch ( V_43 -> V_2 -> V_9 . V_18 ) {
case V_19 :
return 0 ;
case V_20 :
return F_31 ( V_43 , V_45 , V_67 , V_56 , V_52 ) ;
case V_24 :
return F_36 ( V_43 , V_45 , V_67 , V_56 , V_52 ) ;
default:
return - V_77 ;
}
}
static void F_39 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int * V_78 , unsigned int * V_79 )
{
struct V_23 V_47 ;
if ( F_34 ( V_45 , * V_78 , & V_47 , sizeof( V_47 ) ) < 0 )
F_9 () ;
* V_78 += sizeof( V_47 ) ;
* V_79 = F_30 ( V_47 . V_46 ) & 0xffff ;
}
static void F_40 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int * V_78 , unsigned int * V_79 )
{
struct V_25 V_47 ;
if ( F_34 ( V_45 , * V_78 , & V_47 , sizeof( V_47 ) ) < 0 )
F_9 () ;
* V_78 += sizeof( V_47 ) ;
* V_79 = F_30 ( V_47 . V_46 ) & 0xffff ;
}
static void F_41 ( struct V_42 * V_43 , struct V_44 * V_45 ,
unsigned int * V_78 , unsigned int * V_79 )
{
switch ( V_43 -> V_2 -> V_9 . V_18 ) {
case V_20 :
F_39 ( V_43 , V_45 , V_78 , V_79 ) ;
return;
case V_24 :
F_40 ( V_43 , V_45 , V_78 , V_79 ) ;
return;
default:
return;
}
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_80 V_81 ;
struct V_82 V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 [ 2 ] ;
T_2 V_56 ;
T_3 V_88 ;
int V_7 ;
F_2 ( L_24 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
V_7 = F_29 ( V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
F_43 ( & V_2 -> V_89 , sizeof( V_2 -> V_89 ) ) ;
V_81 . V_90 = F_14 ( 2 ) ;
V_81 . V_91 = F_14 ( V_2 -> V_89 ) ;
V_81 . V_92 = F_14 ( 0 ) ;
V_81 . V_93 = 0 ;
V_85 . V_94 = & V_2 -> V_9 . V_95 -> V_96 . V_97 . sin ;
V_85 . V_98 = sizeof( V_2 -> V_9 . V_95 -> V_96 . V_97 . sin ) ;
V_85 . V_99 = NULL ;
V_85 . V_100 = 0 ;
V_85 . V_101 = 0 ;
V_83 . V_38 = F_14 ( V_2 -> V_37 . V_38 ) ;
V_83 . V_39 = F_14 ( V_2 -> V_37 . V_39 ) ;
V_83 . V_102 = 0 ;
V_83 . V_52 = 0 ;
V_83 . type = V_103 ;
V_83 . V_104 = V_2 -> V_105 ;
V_83 . V_106 = 0 ;
V_83 . V_107 = V_2 -> V_13 ;
V_83 . V_108 = 0 ;
V_83 . V_109 = F_44 ( V_2 -> V_9 . V_110 ) ;
V_87 [ 0 ] . V_111 = & V_83 ;
V_87 [ 0 ] . V_112 = sizeof( V_83 ) ;
V_87 [ 1 ] . V_111 = & V_81 ;
V_87 [ 1 ] . V_112 = sizeof( V_81 ) ;
V_56 = V_87 [ 0 ] . V_112 + V_87 [ 1 ] . V_112 ;
V_88 = F_45 ( & V_2 -> V_88 ) ;
V_83 . V_88 = F_14 ( V_88 ) ;
F_46 ( L_25 , V_88 ) ;
V_7 = F_47 ( V_2 -> V_9 . V_113 -> V_114 , & V_85 , V_87 , 2 , V_56 ) ;
if ( V_7 < 0 ) {
F_6 ( L_26 , V_7 ) ;
return - V_115 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_116 * V_50 ,
struct V_117 * V_118 ,
const struct V_119 * V_120 )
{
struct V_82 V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 [ 3 ] ;
T_2 V_56 ;
T_3 V_88 ;
int V_7 ;
F_2 ( L_5 ) ;
V_85 . V_94 = & V_2 -> V_9 . V_95 -> V_96 . V_97 . sin ;
V_85 . V_98 = sizeof( V_2 -> V_9 . V_95 -> V_96 . V_97 . sin ) ;
V_85 . V_99 = NULL ;
V_85 . V_100 = 0 ;
V_85 . V_101 = 0 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_38 = F_14 ( V_50 -> V_38 ) ;
V_83 . V_39 = F_14 ( V_50 -> V_39 ) ;
V_83 . type = V_121 ;
V_83 . V_104 = V_2 -> V_105 ;
V_83 . V_107 = V_50 -> V_107 ;
V_83 . V_109 = F_44 ( V_50 -> V_109 ) ;
V_87 [ 0 ] . V_111 = & V_83 ;
V_87 [ 0 ] . V_112 = sizeof( V_83 ) ;
V_87 [ 1 ] . V_111 = V_118 ;
V_87 [ 1 ] . V_112 = sizeof( * V_118 ) ;
V_87 [ 2 ] . V_111 = ( void * ) V_120 -> V_122 ;
V_87 [ 2 ] . V_112 = V_120 -> V_123 ;
V_56 = V_87 [ 0 ] . V_112 + V_87 [ 1 ] . V_112 + V_87 [ 2 ] . V_112 ;
V_88 = F_45 ( & V_2 -> V_88 ) ;
V_83 . V_88 = F_14 ( V_88 ) ;
F_46 ( L_27 , V_88 ) ;
V_7 = F_47 ( V_2 -> V_9 . V_113 -> V_114 , & V_85 , V_87 , 3 , V_56 ) ;
if ( V_7 < 0 ) {
F_6 ( L_26 , V_7 ) ;
return - V_115 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static void F_49 ( struct V_117 * V_124 )
{
T_3 V_125 = 1000003 ;
int V_126 ;
T_6 * V_127 = ( T_6 * ) V_124 ;
for ( V_126 = sizeof( * V_124 ) ; V_126 > 0 ; V_126 -- )
V_125 = V_125 * 0x10204081 + * V_127 ++ ;
V_124 -> V_128 . V_59 = F_14 ( V_125 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_117 * V_118 ,
const struct V_119 * V_120 )
{
F_12 ( V_28 , V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 1 ] ;
memcpy ( & V_32 , V_120 -> V_17 , sizeof( V_32 ) ) ;
F_26 ( V_30 , 1 ) ;
F_51 ( V_30 , & V_118 -> V_128 , sizeof( V_118 -> V_128 ) ) ;
F_16 ( V_28 , V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , sizeof( V_118 -> V_128 ) , V_32 . V_40 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_3 * V_129 )
{
const struct V_5 * V_6 ;
struct V_80 V_81 ;
struct V_117 V_118
V_130 ( ( F_53 ( 8 ) ) ) ;
struct V_48 * V_49 = F_23 ( V_45 ) ;
T_3 V_90 , V_91 , V_92 , V_131 ;
int V_7 ;
F_2 ( L_24 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
if ( ! V_2 -> V_9 . V_10 ) {
F_10 ( L_28 ) ;
return - V_70 ;
}
V_7 = F_29 ( V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 ) {
* V_129 = V_132 ;
return V_7 ;
}
V_131 = V_133 ;
if ( F_34 ( V_45 , sizeof( struct V_82 ) ,
& V_81 , sizeof( V_81 ) ) < 0 )
goto V_71;
V_90 = F_30 ( V_81 . V_90 ) ;
V_91 = F_30 ( V_81 . V_91 ) ;
V_92 = F_30 ( V_81 . V_92 ) ;
F_46 ( L_29 ,
V_49 -> V_50 . V_88 , V_90 , V_91 , V_92 ) ;
V_131 = V_134 ;
if ( V_90 != V_135 )
goto V_71;
V_131 = V_136 ;
if ( V_2 -> V_9 . V_18 < V_92 )
goto V_71;
V_6 = V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_118 . V_90 = F_14 ( V_135 ) ;
V_118 . V_128 . V_38 = F_14 ( V_2 -> V_37 . V_38 ) ;
V_118 . V_128 . V_39 = F_14 ( V_2 -> V_37 . V_39 ) ;
V_118 . V_128 . V_107 = F_14 ( V_2 -> V_13 ) ;
V_118 . V_128 . V_137 = F_14 ( V_91 + 1 ) ;
V_118 . V_128 . V_138 = F_14 ( V_2 -> V_9 . V_18 ) ;
V_118 . V_139 = F_14 ( V_6 -> V_16 -> V_139 ) ;
V_118 . V_123 = F_14 ( V_6 -> V_16 -> V_123 ) ;
V_118 . V_128 . V_53 [ 0 ] = F_14 ( V_2 -> V_140 [ 0 ] . V_141 ) ;
V_118 . V_128 . V_53 [ 1 ] = F_14 ( V_2 -> V_140 [ 1 ] . V_141 ) ;
V_118 . V_128 . V_53 [ 2 ] = F_14 ( V_2 -> V_140 [ 2 ] . V_141 ) ;
V_118 . V_128 . V_53 [ 3 ] = F_14 ( V_2 -> V_140 [ 3 ] . V_141 ) ;
F_49 ( & V_118 ) ;
F_50 ( V_2 , & V_118 , V_6 -> V_16 ) ;
return F_48 ( V_2 , & V_49 -> V_50 , & V_118 , V_6 -> V_16 ) ;
V_71:
* V_129 = V_131 ;
F_10 ( L_30 , V_131 ) ;
return - V_70 ;
}
static int F_54 ( struct V_1 * V_2 ,
void * V_122 , T_2 V_123 ,
struct V_31 * V_142 ,
T_7 * V_143 ,
T_3 * V_129 )
{
struct V_144 * V_28 ;
struct V_31 V_32 , V_10 ;
struct V_29 V_30 [ 1 ] ;
struct V_145 V_146 ;
unsigned int V_147 ;
T_7 V_148 , V_149 ;
bool V_150 ;
int V_7 ;
T_6 * V_127 , * V_151 , * V_152 , * V_153 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_154 ) ) ;
* V_143 = 0 ;
V_7 = F_29 ( V_2 -> V_154 ) ;
if ( V_7 < 0 ) {
switch ( V_7 ) {
case - V_155 :
* V_129 = V_132 ;
goto error;
default:
* V_129 = V_156 ;
goto error;
}
}
ASSERT ( V_2 -> V_154 -> V_11 . V_12 [ 0 ] != NULL ) ;
F_55 ( ( unsigned long ) V_122 & 7UL , == , 0 ) ;
memcpy ( & V_32 , & V_2 -> V_154 -> V_11 . V_12 [ 2 ] , sizeof( V_32 ) ) ;
V_28 = F_56 ( V_2 -> V_154 -> V_11 . V_12 [ 0 ] ,
V_157 ) ;
if ( ! V_28 ) {
* V_129 = V_156 ;
V_7 = - V_36 ;
goto error;
}
F_15 ( & V_30 [ 0 ] , V_122 , V_123 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , V_123 , V_32 . V_40 ) ;
F_33 ( V_28 ) ;
F_57 ( V_28 ) ;
V_127 = V_122 ;
V_153 = V_127 + V_123 ;
#define F_58 ( T_8 ) \
({ \
u8 *__str = p; \
q = memchr(p, 0, end - p); \
if (!q || q - p > (size)) \
goto bad_ticket; \
for (; p < q; p++) \
if (!isprint(*p)) \
goto bad_ticket; \
p++; \
__str; \
})
F_6 ( L_31 , * V_127 ) ;
V_150 = * V_127 & 1 ;
V_127 ++ ;
V_152 = F_58 ( V_158 ) ;
F_6 ( L_32 , V_152 ) ;
V_152 = F_58 ( V_159 ) ;
F_6 ( L_33 , V_152 ) ;
V_152 = F_58 ( V_160 ) ;
F_6 ( L_34 , V_152 ) ;
if ( V_153 - V_127 < 4 + 8 + 4 + 2 )
goto V_161;
memcpy ( & V_146 , V_127 , sizeof( V_146 ) ) ;
V_127 += 4 ;
F_6 ( L_35 , & V_146 ) ;
memcpy ( & V_10 , V_127 , sizeof( V_10 ) ) ;
V_127 += 8 ;
F_6 ( L_36 , F_30 ( V_10 . V_162 [ 0 ] ) , F_30 ( V_10 . V_162 [ 1 ] ) ) ;
memcpy ( V_142 , & V_10 , sizeof( V_10 ) ) ;
V_147 = * V_127 ++ * 5 * 60 ;
F_6 ( L_37 , V_147 ) ;
if ( V_150 ) {
T_9 V_163 ;
memcpy ( & V_163 , V_127 , 4 ) ;
V_148 = F_59 ( V_163 ) ;
} else {
T_1 V_163 ;
memcpy ( & V_163 , V_127 , 4 ) ;
V_148 = F_60 ( V_163 ) ;
}
V_127 += 4 ;
V_149 = F_61 () ;
F_6 ( L_38 , V_148 , V_149 ) ;
if ( V_148 > V_149 ) {
* V_129 = V_156 ;
V_7 = - V_26 ;
goto error;
}
if ( V_148 < V_149 - V_147 ) {
* V_129 = V_132 ;
V_7 = - V_155 ;
goto error;
}
* V_143 = V_148 + V_147 ;
V_152 = F_58 ( V_164 ) ;
F_6 ( L_39 , V_152 ) ;
V_152 = F_58 ( V_159 ) ;
F_6 ( L_40 , V_152 ) ;
V_7 = 0 ;
error:
F_10 ( L_4 , V_7 ) ;
return V_7 ;
V_161:
* V_129 = V_165 ;
V_7 = - V_166 ;
goto error;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_117 * V_118 ,
const struct V_31 * V_17 )
{
F_12 ( V_28 , V_167 ) ;
struct V_29 V_30 [ 1 ] ;
struct V_31 V_32 ;
F_2 ( L_41 ,
F_30 ( V_17 -> V_162 [ 0 ] ) , F_30 ( V_17 -> V_162 [ 1 ] ) ) ;
ASSERT ( V_167 != NULL ) ;
F_63 ( & V_168 ) ;
if ( F_8 ( V_167 , V_17 -> V_40 ,
sizeof( * V_17 ) ) < 0 )
F_9 () ;
memcpy ( & V_32 , V_17 , sizeof( V_32 ) ) ;
F_26 ( V_30 , 1 ) ;
F_51 ( V_30 , & V_118 -> V_128 , sizeof( V_118 -> V_128 ) ) ;
F_16 ( V_28 , V_167 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , sizeof( V_118 -> V_128 ) , V_32 . V_40 ) ;
F_33 ( V_28 ) ;
F_20 ( V_28 ) ;
F_64 ( & V_168 ) ;
F_10 ( L_5 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_3 * V_129 )
{
struct V_117 V_124
V_130 ( ( F_53 ( 8 ) ) ) ;
struct V_48 * V_49 = F_23 ( V_45 ) ;
struct V_31 V_17 ;
T_7 V_169 ;
void * V_122 ;
T_3 V_131 , V_90 , V_139 , V_123 , V_138 ;
T_1 V_125 ;
int V_7 , V_170 ;
F_2 ( L_24 , V_2 -> V_8 , F_3 ( V_2 -> V_154 ) ) ;
V_131 = V_133 ;
if ( F_34 ( V_45 , sizeof( struct V_82 ) ,
& V_124 , sizeof( V_124 ) ) < 0 )
goto V_71;
if ( ! F_66 ( V_45 , sizeof( V_124 ) ) )
F_9 () ;
V_90 = F_30 ( V_124 . V_90 ) ;
V_123 = F_30 ( V_124 . V_123 ) ;
V_139 = F_30 ( V_124 . V_139 ) ;
F_46 ( L_42 ,
V_49 -> V_50 . V_88 , V_90 , V_139 , V_123 ) ;
V_131 = V_134 ;
if ( V_90 != V_135 )
goto V_71;
V_131 = V_171 ;
if ( V_123 < 4 || V_123 > V_172 )
goto V_71;
V_131 = V_173 ;
if ( V_139 >= V_174 )
goto V_71;
V_122 = F_13 ( V_123 , V_157 ) ;
if ( ! V_122 )
return - V_36 ;
V_131 = V_133 ;
if ( F_34 ( V_45 , sizeof( struct V_82 ) ,
V_122 , V_123 ) < 0 )
goto V_175;
V_7 = F_54 ( V_2 , V_122 , V_123 , & V_17 ,
& V_169 , & V_131 ) ;
if ( V_7 < 0 ) {
* V_129 = V_131 ;
F_21 ( V_122 ) ;
return V_7 ;
}
F_62 ( V_2 , & V_124 , & V_17 ) ;
V_131 = V_69 ;
if ( F_30 ( V_124 . V_128 . V_38 ) != V_2 -> V_37 . V_38 )
goto V_175;
if ( F_30 ( V_124 . V_128 . V_39 ) != V_2 -> V_37 . V_39 )
goto V_175;
if ( F_30 ( V_124 . V_128 . V_107 ) != V_2 -> V_13 )
goto V_175;
V_125 = V_124 . V_128 . V_59 ;
V_124 . V_128 . V_59 = 0 ;
F_49 ( & V_124 ) ;
if ( V_124 . V_128 . V_59 != V_125 )
goto V_175;
F_67 ( & V_2 -> V_176 ) ;
for ( V_170 = 0 ; V_170 < V_177 ; V_170 ++ ) {
struct V_42 * V_43 ;
T_3 V_53 = F_30 ( V_124 . V_128 . V_53 [ V_170 ] ) ;
if ( V_53 > V_178 )
goto V_179;
if ( V_53 < V_2 -> V_140 [ V_170 ] . V_141 )
goto V_179;
if ( V_53 > V_2 -> V_140 [ V_170 ] . V_141 ) {
V_43 = F_68 (
V_2 -> V_140 [ V_170 ] . V_43 ,
F_69 ( & V_2 -> V_176 ) ) ;
if ( V_43 && V_43 -> V_180 < V_181 )
goto V_179;
V_2 -> V_140 [ V_170 ] . V_141 = V_53 ;
}
}
F_70 ( & V_2 -> V_176 ) ;
V_131 = V_182 ;
if ( F_30 ( V_124 . V_128 . V_137 ) != V_2 -> V_89 + 1 )
goto V_175;
V_131 = V_136 ;
V_138 = F_30 ( V_124 . V_128 . V_138 ) ;
if ( V_138 > V_24 )
goto V_175;
V_2 -> V_9 . V_18 = V_138 ;
V_7 = F_71 ( V_2 , & V_17 , V_169 , V_139 ) ;
if ( V_7 < 0 ) {
F_21 ( V_122 ) ;
return V_7 ;
}
F_21 ( V_122 ) ;
F_10 ( L_6 ) ;
return 0 ;
V_179:
F_70 ( & V_2 -> V_176 ) ;
V_175:
F_21 ( V_122 ) ;
V_71:
* V_129 = V_131 ;
F_10 ( L_30 , V_131 ) ;
return - V_70 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( V_2 -> V_27 )
F_73 ( V_2 -> V_27 ) ;
}
static int F_74 ( void )
{
V_167 = F_4 ( L_2 , 0 , V_15 ) ;
return F_75 ( V_167 ) ;
}
static void F_76 ( void )
{
if ( V_167 )
F_73 ( V_167 ) ;
}
