static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_9 ) ) ;
V_6 = V_2 -> V_9 -> V_10 . V_11 ;
V_2 -> V_12 = V_6 -> V_13 ;
V_4 = F_4 ( L_2 , 0 , V_14 ) ;
if ( F_5 ( V_4 ) ) {
F_6 ( L_3 ) ;
V_7 = F_7 ( V_4 ) ;
goto error;
}
if ( F_8 ( V_4 , V_6 -> V_15 -> V_16 ,
sizeof( V_6 -> V_15 -> V_16 ) ) < 0 )
F_9 () ;
switch ( V_2 -> V_17 ) {
case V_18 :
break;
case V_19 :
V_2 -> V_20 = 8 ;
V_2 -> V_21 = sizeof( struct V_22 ) ;
V_2 -> V_23 += sizeof( struct V_22 ) ;
break;
case V_24 :
V_2 -> V_20 = 8 ;
V_2 -> V_21 = sizeof( struct V_25 ) ;
V_2 -> V_23 += sizeof( struct V_25 ) ;
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
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_28 V_29 ;
struct V_30 V_31 [ 2 ] ;
struct V_32 V_33 ;
struct {
T_1 V_34 [ 4 ] ;
} V_35 V_36 ( ( F_12 ( 16 ) ) ) ;
F_2 ( L_5 ) ;
if ( ! V_2 -> V_9 )
return;
V_6 = V_2 -> V_9 -> V_10 . V_11 ;
memcpy ( & V_33 , V_6 -> V_15 -> V_16 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
V_35 . V_34 [ 0 ] = V_2 -> V_40 ;
V_35 . V_34 [ 1 ] = V_2 -> V_41 ;
V_35 . V_34 [ 2 ] = 0 ;
V_35 . V_34 [ 3 ] = F_13 ( V_2 -> V_12 ) ;
F_14 ( & V_31 [ 0 ] , & V_35 , sizeof( V_35 ) ) ;
F_14 ( & V_31 [ 1 ] , & V_35 , sizeof( V_35 ) ) ;
F_15 ( & V_29 , & V_31 [ 0 ] , & V_31 [ 1 ] , sizeof( V_35 ) ) ;
memcpy ( & V_2 -> V_42 , & V_35 . V_34 [ 2 ] , sizeof( V_2 -> V_42 ) ) ;
F_16 ( V_2 -> V_42 . V_43 [ 0 ] , == , V_35 . V_34 [ 2 ] ) ;
F_10 ( L_5 ) ;
}
static int F_17 ( const struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_2 V_48 ,
void * V_49 )
{
struct V_50 * V_51 ;
struct V_28 V_29 ;
struct V_32 V_33 ;
struct V_30 V_31 [ 2 ] ;
struct {
struct V_22 V_52 ;
T_1 V_53 ;
} V_35 V_36 ( ( F_12 ( 8 ) ) ) ;
T_3 V_54 ;
V_51 = F_18 ( V_47 ) ;
F_2 ( L_5 ) ;
V_54 = F_19 ( V_51 -> V_52 . V_55 ^ V_51 -> V_52 . V_56 ) ;
V_48 |= ( T_2 ) V_54 << 16 ;
V_35 . V_52 . V_48 = F_13 ( V_48 ) ;
memcpy ( & V_35 . V_53 , V_49 + 4 , sizeof( V_35 . V_53 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_45 -> V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_14 ( & V_31 [ 0 ] , & V_35 , sizeof( V_35 ) ) ;
F_14 ( & V_31 [ 1 ] , & V_35 , sizeof( V_35 ) ) ;
F_15 ( & V_29 , & V_31 [ 0 ] , & V_31 [ 1 ] , sizeof( V_35 ) ) ;
memcpy ( V_49 , & V_35 , sizeof( V_35 ) ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_20 ( const struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_2 V_48 ,
void * V_49 )
{
const struct V_5 * V_6 ;
struct V_25 T_4
V_36 ( ( F_12 ( 8 ) ) ) ;
struct V_50 * V_51 ;
struct V_28 V_29 ;
struct V_32 V_33 ;
struct V_30 V_31 [ 16 ] ;
struct V_46 * V_57 ;
unsigned V_58 ;
T_3 V_54 ;
int V_59 ;
V_51 = F_18 ( V_47 ) ;
F_2 ( L_5 ) ;
V_54 = F_19 ( V_51 -> V_52 . V_55 ^ V_51 -> V_52 . V_56 ) ;
T_4 . V_48 = F_13 ( V_48 | ( T_2 ) V_54 << 16 ) ;
T_4 . V_60 = 0 ;
V_6 = V_45 -> V_2 -> V_9 -> V_10 . V_11 ;
memcpy ( & V_33 , V_6 -> V_15 -> V_16 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_45 -> V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_14 ( & V_31 [ 0 ] , V_49 , sizeof( T_4 ) ) ;
F_14 ( & V_31 [ 1 ] , & T_4 , sizeof( T_4 ) ) ;
F_15 ( & V_29 , & V_31 [ 0 ] , & V_31 [ 1 ] , sizeof( T_4 ) ) ;
V_59 = F_21 ( V_47 , 0 , & V_57 ) ;
if ( V_59 < 0 || V_59 > 16 )
return - V_61 ;
V_58 = V_48 + V_45 -> V_2 -> V_20 - 1 ;
V_58 &= ~ ( V_45 -> V_2 -> V_20 - 1 ) ;
F_22 ( V_31 , V_59 ) ;
F_23 ( V_47 , V_31 , 0 , V_58 ) ;
F_15 ( & V_29 , V_31 , V_31 , V_58 ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_24 ( const struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_5 V_48 ,
void * V_49 )
{
struct V_50 * V_51 ;
struct V_28 V_29 ;
struct V_32 V_33 ;
struct V_30 V_31 [ 2 ] ;
struct {
T_1 V_34 [ 2 ] ;
} V_35 V_36 ( ( F_12 ( 8 ) ) ) ;
T_1 V_34 ;
T_2 V_62 ;
int V_7 ;
V_51 = F_18 ( V_47 ) ;
F_2 ( L_7 ,
V_45 -> V_8 , F_3 ( V_45 -> V_2 -> V_9 ) , F_19 ( V_51 -> V_52 . V_55 ) ,
V_48 ) ;
if ( ! V_45 -> V_2 -> V_27 )
return 0 ;
V_7 = F_25 ( V_45 -> V_2 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
memcpy ( & V_33 , V_45 -> V_2 -> V_42 . V_34 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_45 -> V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
V_34 = F_13 ( V_45 -> V_63 << ( 32 - V_64 ) ) ;
V_34 |= V_51 -> V_52 . V_55 & F_26 ( 0x3fffffff ) ;
V_35 . V_34 [ 0 ] = V_51 -> V_52 . V_56 ;
V_35 . V_34 [ 1 ] = V_34 ;
F_14 ( & V_31 [ 0 ] , & V_35 , sizeof( V_35 ) ) ;
F_14 ( & V_31 [ 1 ] , & V_35 , sizeof( V_35 ) ) ;
F_15 ( & V_29 , & V_31 [ 0 ] , & V_31 [ 1 ] , sizeof( V_35 ) ) ;
V_62 = F_19 ( V_35 . V_34 [ 1 ] ) ;
V_62 = ( V_62 >> 16 ) & 0xffff ;
if ( V_62 == 0 )
V_62 = 1 ;
V_51 -> V_52 . V_65 = F_27 ( V_62 ) ;
switch ( V_45 -> V_2 -> V_17 ) {
case V_18 :
V_7 = 0 ;
break;
case V_19 :
V_7 = F_17 ( V_45 , V_47 , V_48 , V_49 ) ;
break;
case V_24 :
V_7 = F_20 ( V_45 , V_47 , V_48 ,
V_49 ) ;
break;
default:
V_7 = - V_66 ;
break;
}
F_10 ( L_8 , V_7 , V_62 ) ;
return V_7 ;
}
static int F_28 ( const struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_2 * V_67 )
{
struct V_22 V_49 ;
struct V_50 * V_51 ;
struct V_28 V_29 ;
struct V_32 V_33 ;
struct V_30 V_31 [ 16 ] ;
struct V_46 * V_57 ;
T_2 V_48 , V_68 ;
T_3 V_54 ;
int V_59 ;
F_2 ( L_5 ) ;
V_51 = F_18 ( V_47 ) ;
V_59 = F_21 ( V_47 , 0 , & V_57 ) ;
if ( V_59 < 0 || V_59 > 16 )
goto V_69;
F_22 ( V_31 , V_59 ) ;
F_23 ( V_47 , V_31 , 0 , 8 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_45 -> V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_29 ( & V_29 , V_31 , V_31 , 8 ) ;
if ( F_30 ( V_47 , 0 , & V_49 , sizeof( V_49 ) ) < 0 )
goto V_70;
if ( ! F_31 ( V_47 , sizeof( V_49 ) ) )
F_9 () ;
V_68 = F_19 ( V_49 . V_48 ) ;
V_48 = V_68 & 0xffff ;
V_54 = V_68 >> 16 ;
V_54 ^= F_19 ( V_51 -> V_52 . V_55 ^ V_51 -> V_52 . V_56 ) ;
V_54 &= 0xffff ;
if ( V_54 != 0 ) {
* V_67 = V_71 ;
goto V_72;
}
if ( V_48 > V_47 -> V_58 )
goto V_70;
else if ( V_48 < V_47 -> V_58 )
V_47 -> V_58 = V_48 ;
F_10 ( L_9 , V_48 ) ;
return 0 ;
V_70:
* V_67 = V_73 ;
V_72:
F_10 ( L_10 ) ;
return - V_74 ;
V_69:
F_10 ( L_11 ) ;
return - V_61 ;
}
static int F_32 ( const struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_2 * V_67 )
{
const struct V_5 * V_6 ;
struct V_25 V_49 ;
struct V_50 * V_51 ;
struct V_28 V_29 ;
struct V_32 V_33 ;
struct V_30 V_75 [ 4 ] , * V_31 ;
struct V_46 * V_57 ;
T_2 V_48 , V_68 ;
T_3 V_54 ;
int V_59 ;
F_2 ( L_12 , V_47 -> V_58 ) ;
V_51 = F_18 ( V_47 ) ;
V_59 = F_21 ( V_47 , 0 , & V_57 ) ;
if ( V_59 < 0 )
goto V_69;
V_31 = V_75 ;
if ( F_33 ( V_59 > 4 ) ) {
V_31 = F_34 ( sizeof( * V_31 ) * V_59 , V_76 ) ;
if ( ! V_31 )
goto V_69;
}
F_22 ( V_31 , V_59 ) ;
F_23 ( V_47 , V_31 , 0 , V_47 -> V_58 ) ;
V_6 = V_45 -> V_2 -> V_9 -> V_10 . V_11 ;
memcpy ( & V_33 , V_6 -> V_15 -> V_16 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_45 -> V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_29 ( & V_29 , V_31 , V_31 , V_47 -> V_58 ) ;
if ( V_31 != V_75 )
F_35 ( V_31 ) ;
if ( F_30 ( V_47 , 0 , & V_49 , sizeof( V_49 ) ) < 0 )
goto V_70;
if ( ! F_31 ( V_47 , sizeof( V_49 ) ) )
F_9 () ;
V_68 = F_19 ( V_49 . V_48 ) ;
V_48 = V_68 & 0xffff ;
V_54 = V_68 >> 16 ;
V_54 ^= F_19 ( V_51 -> V_52 . V_55 ^ V_51 -> V_52 . V_56 ) ;
V_54 &= 0xffff ;
if ( V_54 != 0 ) {
* V_67 = V_71 ;
goto V_72;
}
if ( V_48 > V_47 -> V_58 )
goto V_70;
else if ( V_48 < V_47 -> V_58 )
V_47 -> V_58 = V_48 ;
F_10 ( L_9 , V_48 ) ;
return 0 ;
V_70:
* V_67 = V_73 ;
V_72:
F_10 ( L_10 ) ;
return - V_74 ;
V_69:
F_10 ( L_11 ) ;
return - V_61 ;
}
static int F_36 ( const struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_2 * V_67 )
{
struct V_28 V_29 ;
struct V_50 * V_51 ;
struct V_32 V_33 ;
struct V_30 V_31 [ 2 ] ;
struct {
T_1 V_34 [ 2 ] ;
} V_35 V_36 ( ( F_12 ( 8 ) ) ) ;
T_1 V_34 ;
T_6 V_65 ;
T_2 V_62 ;
int V_7 ;
V_51 = F_18 ( V_47 ) ;
F_2 ( L_13 ,
V_45 -> V_8 , F_3 ( V_45 -> V_2 -> V_9 ) ,
F_19 ( V_51 -> V_52 . V_55 ) ) ;
if ( ! V_45 -> V_2 -> V_27 )
return 0 ;
if ( V_51 -> V_52 . V_77 != V_78 ) {
* V_67 = V_79 ;
F_10 ( L_14 ) ;
return - V_74 ;
}
memcpy ( & V_33 , V_45 -> V_2 -> V_42 . V_34 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_45 -> V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
V_34 = F_13 ( V_45 -> V_63 << ( 32 - V_64 ) ) ;
V_34 |= V_51 -> V_52 . V_55 & F_26 ( 0x3fffffff ) ;
V_35 . V_34 [ 0 ] = V_45 -> V_80 ;
V_35 . V_34 [ 1 ] = V_34 ;
F_14 ( & V_31 [ 0 ] , & V_35 , sizeof( V_35 ) ) ;
F_14 ( & V_31 [ 1 ] , & V_35 , sizeof( V_35 ) ) ;
F_15 ( & V_29 , & V_31 [ 0 ] , & V_31 [ 1 ] , sizeof( V_35 ) ) ;
V_62 = F_19 ( V_35 . V_34 [ 1 ] ) ;
V_62 = ( V_62 >> 16 ) & 0xffff ;
if ( V_62 == 0 )
V_62 = 1 ;
V_65 = F_27 ( V_62 ) ;
if ( V_51 -> V_52 . V_65 != V_65 ) {
* V_67 = V_71 ;
F_10 ( L_15 ) ;
return - V_74 ;
}
switch ( V_45 -> V_2 -> V_17 ) {
case V_18 :
V_7 = 0 ;
break;
case V_19 :
V_7 = F_28 ( V_45 , V_47 , V_67 ) ;
break;
case V_24 :
V_7 = F_32 ( V_45 , V_47 , V_67 ) ;
break;
default:
V_7 = - V_81 ;
break;
}
F_10 ( L_4 , V_7 ) ;
return V_7 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
struct V_84 V_52 ;
struct V_85 V_86 ;
struct V_87 V_88 [ 2 ] ;
T_5 V_58 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_9 ) ) ;
V_7 = F_25 ( V_2 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
F_38 ( & V_2 -> V_89 , sizeof( V_2 -> V_89 ) ) ;
V_83 . V_90 = F_13 ( 2 ) ;
V_83 . V_91 = F_13 ( V_2 -> V_89 ) ;
V_83 . V_92 = F_13 ( 0 ) ;
V_83 . V_93 = 0 ;
V_86 . V_94 = & V_2 -> V_95 -> V_96 -> V_97 . V_98 . sin ;
V_86 . V_99 = sizeof( V_2 -> V_95 -> V_96 -> V_97 . V_98 . sin ) ;
V_86 . V_100 = NULL ;
V_86 . V_101 = 0 ;
V_86 . V_102 = 0 ;
V_52 . V_40 = V_2 -> V_40 ;
V_52 . V_41 = V_2 -> V_41 ;
V_52 . V_56 = 0 ;
V_52 . V_55 = 0 ;
V_52 . type = V_103 ;
V_52 . V_39 = V_2 -> V_104 ;
V_52 . V_105 = 0 ;
V_52 . V_77 = V_2 -> V_12 ;
V_52 . V_106 = 0 ;
V_52 . V_107 = V_2 -> V_108 ;
V_88 [ 0 ] . V_109 = & V_52 ;
V_88 [ 0 ] . V_110 = sizeof( V_52 ) ;
V_88 [ 1 ] . V_109 = & V_83 ;
V_88 [ 1 ] . V_110 = sizeof( V_83 ) ;
V_58 = V_88 [ 0 ] . V_110 + V_88 [ 1 ] . V_110 ;
V_52 . V_111 = F_13 ( F_39 ( & V_2 -> V_111 ) ) ;
F_40 ( L_17 , F_19 ( V_52 . V_111 ) ) ;
V_7 = F_41 ( V_2 -> V_95 -> V_112 -> V_113 , & V_86 , V_88 , 2 , V_58 ) ;
if ( V_7 < 0 ) {
F_6 ( L_18 , V_7 ) ;
return - V_114 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_84 * V_52 ,
struct V_115 * V_116 ,
const struct V_117 * V_118 )
{
struct V_85 V_86 ;
struct V_87 V_88 [ 3 ] ;
T_5 V_58 ;
int V_7 ;
F_2 ( L_5 ) ;
V_86 . V_94 = & V_2 -> V_95 -> V_96 -> V_97 . V_98 . sin ;
V_86 . V_99 = sizeof( V_2 -> V_95 -> V_96 -> V_97 . V_98 . sin ) ;
V_86 . V_100 = NULL ;
V_86 . V_101 = 0 ;
V_86 . V_102 = 0 ;
V_52 -> V_40 = V_2 -> V_40 ;
V_52 -> V_55 = 0 ;
V_52 -> type = V_119 ;
V_52 -> V_39 = V_2 -> V_104 ;
V_52 -> V_105 = 0 ;
V_52 -> V_106 = 0 ;
V_88 [ 0 ] . V_109 = V_52 ;
V_88 [ 0 ] . V_110 = sizeof( * V_52 ) ;
V_88 [ 1 ] . V_109 = V_116 ;
V_88 [ 1 ] . V_110 = sizeof( * V_116 ) ;
V_88 [ 2 ] . V_109 = ( void * ) V_118 -> V_120 ;
V_88 [ 2 ] . V_110 = V_118 -> V_121 ;
V_58 = V_88 [ 0 ] . V_110 + V_88 [ 1 ] . V_110 + V_88 [ 2 ] . V_110 ;
V_52 -> V_111 = F_13 ( F_39 ( & V_2 -> V_111 ) ) ;
F_40 ( L_19 , F_19 ( V_52 -> V_111 ) ) ;
V_7 = F_41 ( V_2 -> V_95 -> V_112 -> V_113 , & V_86 , V_88 , 3 , V_58 ) ;
if ( V_7 < 0 ) {
F_6 ( L_18 , V_7 ) ;
return - V_114 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static void F_43 ( struct V_115 * V_122 )
{
T_2 V_123 = 1000003 ;
int V_124 ;
T_7 * V_125 = ( T_7 * ) V_122 ;
for ( V_124 = sizeof( * V_122 ) ; V_124 > 0 ; V_124 -- )
V_123 = V_123 * 0x10204081 + * V_125 ++ ;
V_122 -> V_126 . V_60 = F_13 ( V_123 ) ;
}
static void F_44 ( struct V_30 V_31 [ 2 ] ,
void * V_68 , T_5 V_127 )
{
int V_59 = 1 ;
F_22 ( V_31 , 2 ) ;
F_45 ( & V_31 [ 0 ] , V_68 , V_127 ) ;
if ( V_31 [ 0 ] . V_128 + V_127 > V_129 ) {
V_31 [ 0 ] . V_130 = V_129 - V_31 [ 0 ] . V_128 ;
F_45 ( & V_31 [ 1 ] , V_68 + V_31 [ 0 ] . V_130 , V_127 - V_31 [ 0 ] . V_130 ) ;
V_59 ++ ;
}
F_46 ( & V_31 [ V_59 - 1 ] ) ;
F_16 ( V_31 [ 0 ] . V_130 + V_31 [ 1 ] . V_130 , == , V_127 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
const struct V_117 * V_118 )
{
struct V_28 V_29 ;
struct V_32 V_33 ;
struct V_30 V_31 [ 2 ] ;
memcpy ( & V_33 , V_118 -> V_16 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_2 -> V_27 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_44 ( V_31 , & V_116 -> V_126 , sizeof( V_116 -> V_126 ) ) ;
F_15 ( & V_29 , V_31 , V_31 , sizeof( V_116 -> V_126 ) ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
T_2 * V_67 )
{
const struct V_5 * V_6 ;
struct V_82 V_83 ;
struct V_115 V_116
V_36 ( ( F_12 ( 8 ) ) ) ;
struct V_50 * V_51 ;
T_2 V_90 , V_91 , V_92 , V_131 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_9 ) ) ;
if ( ! V_2 -> V_9 ) {
F_10 ( L_20 ) ;
return - V_74 ;
}
V_7 = F_25 ( V_2 -> V_9 ) ;
if ( V_7 < 0 ) {
* V_67 = V_132 ;
return V_7 ;
}
V_131 = V_133 ;
V_51 = F_18 ( V_47 ) ;
if ( F_30 ( V_47 , 0 , & V_83 , sizeof( V_83 ) ) < 0 )
goto V_72;
V_90 = F_19 ( V_83 . V_90 ) ;
V_91 = F_19 ( V_83 . V_91 ) ;
V_92 = F_19 ( V_83 . V_92 ) ;
F_40 ( L_21 ,
F_19 ( V_51 -> V_52 . V_111 ) , V_90 , V_91 , V_92 ) ;
V_131 = V_79 ;
if ( V_90 != V_134 )
goto V_72;
V_131 = V_135 ;
if ( V_2 -> V_17 < V_92 )
goto V_72;
V_6 = V_2 -> V_9 -> V_10 . V_11 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_90 = V_134 ;
V_116 . V_126 . V_40 = V_2 -> V_40 ;
V_116 . V_126 . V_41 = V_2 -> V_41 ;
V_116 . V_126 . V_77 = F_13 ( V_2 -> V_12 ) ;
V_116 . V_126 . V_80 [ 0 ] =
( V_2 -> V_136 [ 0 ] ? V_2 -> V_136 [ 0 ] -> V_80 : 0 ) ;
V_116 . V_126 . V_80 [ 1 ] =
( V_2 -> V_136 [ 1 ] ? V_2 -> V_136 [ 1 ] -> V_80 : 0 ) ;
V_116 . V_126 . V_80 [ 2 ] =
( V_2 -> V_136 [ 2 ] ? V_2 -> V_136 [ 2 ] -> V_80 : 0 ) ;
V_116 . V_126 . V_80 [ 3 ] =
( V_2 -> V_136 [ 3 ] ? V_2 -> V_136 [ 3 ] -> V_80 : 0 ) ;
V_116 . V_126 . V_137 = F_13 ( V_91 + 1 ) ;
V_116 . V_126 . V_138 = F_13 ( V_2 -> V_17 ) ;
V_116 . V_139 = F_13 ( V_6 -> V_15 -> V_139 ) ;
V_116 . V_121 = F_13 ( V_6 -> V_15 -> V_121 ) ;
F_43 ( & V_116 ) ;
F_47 ( V_2 , & V_116 , V_6 -> V_15 ) ;
return F_42 ( V_2 , & V_51 -> V_52 , & V_116 , V_6 -> V_15 ) ;
V_72:
* V_67 = V_131 ;
F_10 ( L_22 , V_131 ) ;
return - V_74 ;
}
static int F_49 ( struct V_1 * V_2 ,
void * V_120 , T_5 V_121 ,
struct V_32 * V_140 ,
T_8 * V_141 ,
T_2 * V_67 )
{
struct V_28 V_29 ;
struct V_32 V_33 , V_9 ;
struct V_30 V_31 [ 1 ] ;
struct V_142 V_143 ;
unsigned V_144 ;
T_8 V_145 , V_146 ;
bool V_147 ;
int V_7 ;
T_7 * V_125 , * V_148 , * V_149 , * V_150 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_151 ) ) ;
* V_141 = 0 ;
V_7 = F_25 ( V_2 -> V_151 ) ;
if ( V_7 < 0 ) {
switch ( V_7 ) {
case - V_152 :
* V_67 = V_132 ;
goto error;
default:
* V_67 = V_153 ;
goto error;
}
}
ASSERT ( V_2 -> V_151 -> V_10 . V_11 != NULL ) ;
F_16 ( ( unsigned long ) V_120 & 7UL , == , 0 ) ;
memcpy ( & V_33 , & V_2 -> V_151 -> V_154 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_2 -> V_151 -> V_10 . V_11 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_14 ( & V_31 [ 0 ] , V_120 , V_121 ) ;
F_29 ( & V_29 , V_31 , V_31 , V_121 ) ;
V_125 = V_120 ;
V_150 = V_125 + V_121 ;
#define F_50 ( T_9 ) \
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
F_6 ( L_23 , * V_125 ) ;
V_147 = * V_125 & 1 ;
V_125 ++ ;
V_149 = F_50 ( V_155 ) ;
F_6 ( L_24 , V_149 ) ;
V_149 = F_50 ( V_156 ) ;
F_6 ( L_25 , V_149 ) ;
V_149 = F_50 ( V_157 ) ;
F_6 ( L_26 , V_149 ) ;
if ( V_150 - V_125 < 4 + 8 + 4 + 2 )
goto V_158;
memcpy ( & V_143 , V_125 , sizeof( V_143 ) ) ;
V_125 += 4 ;
F_6 ( L_27 , & V_143 ) ;
memcpy ( & V_9 , V_125 , sizeof( V_9 ) ) ;
V_125 += 8 ;
F_6 ( L_28 , F_19 ( V_9 . V_43 [ 0 ] ) , F_19 ( V_9 . V_43 [ 1 ] ) ) ;
memcpy ( V_140 , & V_9 , sizeof( V_9 ) ) ;
V_144 = * V_125 ++ * 5 * 60 ;
F_6 ( L_29 , V_144 ) ;
if ( V_147 ) {
T_10 V_159 ;
memcpy ( & V_159 , V_125 , 4 ) ;
V_145 = F_51 ( V_159 ) ;
} else {
T_1 V_159 ;
memcpy ( & V_159 , V_125 , 4 ) ;
V_145 = F_52 ( V_159 ) ;
}
V_125 += 4 ;
V_146 = F_53 () ;
F_6 ( L_30 , V_145 , V_146 ) ;
if ( V_145 > V_146 ) {
* V_67 = V_153 ;
V_7 = - V_26 ;
goto error;
}
if ( V_145 < V_146 - V_144 ) {
* V_67 = V_132 ;
V_7 = - V_152 ;
goto error;
}
* V_141 = V_145 + V_144 ;
V_149 = F_50 ( V_160 ) ;
F_6 ( L_31 , V_149 ) ;
V_149 = F_50 ( V_156 ) ;
F_6 ( L_32 , V_149 ) ;
V_7 = 0 ;
error:
F_10 ( L_4 , V_7 ) ;
return V_7 ;
V_158:
* V_67 = V_161 ;
V_7 = - V_162 ;
goto error;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
const struct V_32 * V_16 )
{
struct V_28 V_29 ;
struct V_30 V_31 [ 2 ] ;
struct V_32 V_33 ;
F_2 ( L_33 ,
F_19 ( V_16 -> V_43 [ 0 ] ) , F_19 ( V_16 -> V_43 [ 1 ] ) ) ;
ASSERT ( V_163 != NULL ) ;
F_55 ( & V_164 ) ;
if ( F_8 ( V_163 , V_16 -> V_34 ,
sizeof( * V_16 ) ) < 0 )
F_9 () ;
memcpy ( & V_33 , V_16 , sizeof( V_33 ) ) ;
V_29 . V_37 = V_163 ;
V_29 . V_38 = V_33 . V_34 ;
V_29 . V_39 = 0 ;
F_44 ( V_31 , & V_116 -> V_126 , sizeof( V_116 -> V_126 ) ) ;
F_29 ( & V_29 , V_31 , V_31 , sizeof( V_116 -> V_126 ) ) ;
F_56 ( & V_164 ) ;
F_10 ( L_5 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
T_2 * V_67 )
{
struct V_115 V_122
V_36 ( ( F_12 ( 8 ) ) ) ;
struct V_50 * V_51 ;
struct V_32 V_16 ;
T_8 V_165 ;
void * V_120 ;
T_2 V_131 , V_90 , V_139 , V_121 , V_138 ;
T_1 V_123 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_151 ) ) ;
V_131 = V_133 ;
if ( F_30 ( V_47 , 0 , & V_122 , sizeof( V_122 ) ) < 0 )
goto V_72;
if ( ! F_58 ( V_47 , sizeof( V_122 ) ) )
F_9 () ;
V_90 = F_19 ( V_122 . V_90 ) ;
V_121 = F_19 ( V_122 . V_121 ) ;
V_139 = F_19 ( V_122 . V_139 ) ;
V_51 = F_18 ( V_47 ) ;
F_40 ( L_34 ,
F_19 ( V_51 -> V_52 . V_111 ) , V_90 , V_139 , V_121 ) ;
V_131 = V_79 ;
if ( V_90 != V_134 )
goto V_72;
V_131 = V_166 ;
if ( V_121 < 4 || V_121 > V_167 )
goto V_72;
V_131 = V_168 ;
if ( V_139 >= V_169 )
goto V_72;
V_120 = F_34 ( V_121 , V_170 ) ;
if ( ! V_120 )
return - V_61 ;
V_131 = V_133 ;
if ( F_30 ( V_47 , 0 , V_120 , V_121 ) < 0 )
goto V_171;
V_7 = F_49 ( V_2 , V_120 , V_121 , & V_16 ,
& V_165 , & V_131 ) ;
if ( V_7 < 0 ) {
* V_67 = V_131 ;
F_35 ( V_120 ) ;
return V_7 ;
}
F_54 ( V_2 , & V_122 , & V_16 ) ;
V_131 = V_71 ;
if ( V_122 . V_126 . V_40 != V_2 -> V_40 )
goto V_171;
if ( V_122 . V_126 . V_41 != V_2 -> V_41 )
goto V_171;
if ( F_19 ( V_122 . V_126 . V_77 ) != V_2 -> V_12 )
goto V_171;
V_123 = V_122 . V_126 . V_60 ;
V_122 . V_126 . V_60 = 0 ;
F_43 ( & V_122 ) ;
if ( V_122 . V_126 . V_60 != V_123 )
goto V_171;
if ( F_19 ( V_122 . V_126 . V_80 [ 0 ] ) > V_172 ||
F_19 ( V_122 . V_126 . V_80 [ 1 ] ) > V_172 ||
F_19 ( V_122 . V_126 . V_80 [ 2 ] ) > V_172 ||
F_19 ( V_122 . V_126 . V_80 [ 3 ] ) > V_172 )
goto V_171;
V_131 = V_173 ;
if ( V_122 . V_126 . V_137 != F_13 ( V_2 -> V_89 + 1 ) )
goto V_171;
V_131 = V_135 ;
V_138 = F_19 ( V_122 . V_126 . V_138 ) ;
if ( V_138 > V_24 )
goto V_171;
V_2 -> V_17 = V_138 ;
V_7 = F_59 ( V_2 , & V_16 , V_165 , V_139 ) ;
if ( V_7 < 0 ) {
F_35 ( V_120 ) ;
return V_7 ;
}
F_35 ( V_120 ) ;
F_10 ( L_6 ) ;
return 0 ;
V_171:
F_35 ( V_120 ) ;
V_72:
* V_67 = V_131 ;
F_10 ( L_22 , V_131 ) ;
return - V_74 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( V_2 -> V_27 )
F_61 ( V_2 -> V_27 ) ;
}
static T_11 int F_62 ( void )
{
F_2 ( L_5 ) ;
V_163 = F_4 ( L_2 , 0 , V_14 ) ;
if ( F_5 ( V_163 ) )
return F_7 ( V_163 ) ;
return F_63 ( & V_174 ) ;
}
static T_12 void F_64 ( void )
{
F_2 ( L_5 ) ;
F_65 ( & V_174 ) ;
F_61 ( V_163 ) ;
}
