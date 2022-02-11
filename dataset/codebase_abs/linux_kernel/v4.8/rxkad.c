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
V_2 -> V_24 += sizeof( struct V_23 ) ;
break;
case V_25 :
V_2 -> V_21 = 8 ;
V_2 -> V_22 = sizeof( struct V_26 ) ;
V_2 -> V_24 += sizeof( struct V_26 ) ;
break;
default:
V_7 = - V_27 ;
goto error;
}
V_2 -> V_28 = V_4 ;
V_7 = 0 ;
error:
F_10 ( L_4 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_12 ( V_29 , V_2 -> V_28 ) ;
struct V_30 V_31 ;
struct V_32 V_33 ;
T_1 * V_34 ;
T_2 V_35 = 4 * sizeof( T_1 ) ;
F_2 ( L_5 ) ;
if ( ! V_2 -> V_9 . V_10 )
return 0 ;
V_34 = F_13 ( V_35 , V_36 ) ;
if ( ! V_34 )
return - V_37 ;
V_6 = V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_33 , V_6 -> V_16 -> V_17 , sizeof( V_33 ) ) ;
V_34 [ 0 ] = F_14 ( V_2 -> V_38 . V_39 ) ;
V_34 [ 1 ] = F_14 ( V_2 -> V_38 . V_40 ) ;
V_34 [ 2 ] = 0 ;
V_34 [ 3 ] = F_14 ( V_2 -> V_13 ) ;
F_15 ( & V_31 , V_34 , V_35 ) ;
F_16 ( V_29 , V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , & V_31 , & V_31 , V_35 , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
memcpy ( & V_2 -> V_42 , V_34 + 2 , sizeof( V_2 -> V_42 ) ) ;
F_21 ( V_34 ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_22 ( const struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
struct V_49 * V_50 ;
F_12 ( V_29 , V_44 -> V_2 -> V_28 ) ;
struct V_23 V_51 ;
struct V_32 V_33 ;
struct V_30 V_31 ;
T_4 V_52 ;
V_50 = F_23 ( V_46 ) ;
F_2 ( L_5 ) ;
V_52 = V_50 -> V_51 . V_53 ^ V_50 -> V_51 . V_54 ;
V_47 |= ( T_3 ) V_52 << 16 ;
V_51 . V_47 = F_14 ( V_47 ) ;
memcpy ( V_48 , & V_51 , sizeof( V_51 ) ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_15 ( & V_31 , V_48 , 8 ) ;
F_16 ( V_29 , V_44 -> V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , & V_31 , & V_31 , 8 , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_24 ( const struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
const struct V_5 * V_6 ;
struct V_26 V_55 ;
struct V_49 * V_50 ;
F_12 ( V_29 , V_44 -> V_2 -> V_28 ) ;
struct V_32 V_33 ;
struct V_30 V_31 [ 16 ] ;
struct V_45 * V_56 ;
unsigned int V_57 ;
T_4 V_52 ;
int V_58 ;
int V_59 ;
V_50 = F_23 ( V_46 ) ;
F_2 ( L_5 ) ;
V_52 = V_50 -> V_51 . V_53 ^ V_50 -> V_51 . V_54 ;
V_55 . V_47 = F_14 ( V_47 | ( T_3 ) V_52 << 16 ) ;
V_55 . V_60 = 0 ;
memcpy ( V_48 , & V_55 , sizeof( V_55 ) ) ;
V_6 = V_44 -> V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_33 , V_6 -> V_16 -> V_17 , sizeof( V_33 ) ) ;
F_15 ( & V_31 [ 0 ] , V_48 , sizeof( V_55 ) ) ;
F_16 ( V_29 , V_44 -> V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , & V_31 [ 0 ] , & V_31 [ 0 ] , sizeof( V_55 ) , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
V_58 = F_25 ( V_46 , 0 , & V_56 ) ;
V_59 = - V_37 ;
if ( V_58 < 0 || V_58 > 16 )
goto V_61;
V_57 = V_47 + V_44 -> V_2 -> V_21 - 1 ;
V_57 &= ~ ( V_44 -> V_2 -> V_21 - 1 ) ;
F_26 ( V_31 , V_58 ) ;
F_27 ( V_46 , V_31 , 0 , V_57 ) ;
F_18 ( V_29 , V_31 , V_31 , V_57 , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
F_10 ( L_6 ) ;
V_59 = 0 ;
V_61:
F_20 ( V_29 ) ;
return V_59 ;
}
static int F_28 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_2 V_47 ,
void * V_48 )
{
struct V_49 * V_50 ;
F_12 ( V_29 , V_44 -> V_2 -> V_28 ) ;
struct V_32 V_33 ;
struct V_30 V_31 ;
T_3 V_41 , V_62 ;
int V_7 ;
V_50 = F_23 ( V_46 ) ;
F_2 ( L_7 ,
V_44 -> V_8 , F_3 ( V_44 -> V_2 -> V_9 . V_10 ) ,
V_50 -> V_51 . V_53 , V_47 ) ;
if ( ! V_44 -> V_2 -> V_28 )
return 0 ;
V_7 = F_29 ( V_44 -> V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
memcpy ( & V_33 , V_44 -> V_2 -> V_42 . V_41 , sizeof( V_33 ) ) ;
V_41 = V_44 -> V_63 << ( 32 - V_64 ) ;
V_41 |= V_50 -> V_51 . V_53 & 0x3fffffff ;
V_44 -> V_65 [ 0 ] = F_14 ( V_50 -> V_51 . V_54 ) ;
V_44 -> V_65 [ 1 ] = F_14 ( V_41 ) ;
F_15 ( & V_31 , V_44 -> V_65 , 8 ) ;
F_16 ( V_29 , V_44 -> V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , & V_31 , & V_31 , 8 , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
V_62 = F_30 ( V_44 -> V_65 [ 1 ] ) ;
V_62 = ( V_62 >> 16 ) & 0xffff ;
if ( V_62 == 0 )
V_62 = 1 ;
V_50 -> V_51 . V_66 = V_62 ;
switch ( V_44 -> V_2 -> V_9 . V_18 ) {
case V_19 :
V_7 = 0 ;
break;
case V_20 :
V_7 = F_22 ( V_44 , V_46 , V_47 , V_48 ) ;
break;
case V_25 :
V_7 = F_24 ( V_44 , V_46 , V_47 ,
V_48 ) ;
break;
default:
V_7 = - V_67 ;
break;
}
F_10 ( L_8 , V_7 , V_62 ) ;
return V_7 ;
}
static int F_31 ( const struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_3 * V_68 )
{
struct V_23 V_48 ;
struct V_49 * V_50 ;
F_12 ( V_29 , V_44 -> V_2 -> V_28 ) ;
struct V_32 V_33 ;
struct V_30 V_31 [ 16 ] ;
struct V_45 * V_56 ;
T_3 V_47 , V_69 ;
T_4 V_52 ;
int V_58 ;
F_2 ( L_5 ) ;
V_50 = F_23 ( V_46 ) ;
V_58 = F_25 ( V_46 , 0 , & V_56 ) ;
if ( V_58 < 0 || V_58 > 16 )
goto V_70;
F_26 ( V_31 , V_58 ) ;
F_27 ( V_46 , V_31 , 0 , 8 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_16 ( V_29 , V_44 -> V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , V_31 , V_31 , 8 , V_33 . V_41 ) ;
F_32 ( V_29 ) ;
F_20 ( V_29 ) ;
if ( F_33 ( V_46 , 0 , & V_48 , sizeof( V_48 ) ) < 0 )
goto V_71;
if ( ! F_34 ( V_46 , sizeof( V_48 ) ) )
F_9 () ;
V_69 = F_30 ( V_48 . V_47 ) ;
V_47 = V_69 & 0xffff ;
V_52 = V_69 >> 16 ;
V_52 ^= V_50 -> V_51 . V_53 ^ V_50 -> V_51 . V_54 ;
V_52 &= 0xffff ;
if ( V_52 != 0 ) {
* V_68 = V_72 ;
goto V_73;
}
if ( V_47 > V_46 -> V_57 )
goto V_71;
else if ( V_47 < V_46 -> V_57 )
V_46 -> V_57 = V_47 ;
F_10 ( L_9 , V_47 ) ;
return 0 ;
V_71:
* V_68 = V_74 ;
V_73:
F_10 ( L_10 ) ;
return - V_75 ;
V_70:
F_10 ( L_11 ) ;
return - V_37 ;
}
static int F_35 ( const struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_3 * V_68 )
{
const struct V_5 * V_6 ;
struct V_26 V_48 ;
struct V_49 * V_50 ;
F_12 ( V_29 , V_44 -> V_2 -> V_28 ) ;
struct V_32 V_33 ;
struct V_30 V_76 [ 4 ] , * V_31 ;
struct V_45 * V_56 ;
T_3 V_47 , V_69 ;
T_4 V_52 ;
int V_58 ;
F_2 ( L_12 , V_46 -> V_57 ) ;
V_50 = F_23 ( V_46 ) ;
V_58 = F_25 ( V_46 , 0 , & V_56 ) ;
if ( V_58 < 0 )
goto V_70;
V_31 = V_76 ;
if ( F_36 ( V_58 > 4 ) ) {
V_31 = F_13 ( sizeof( * V_31 ) * V_58 , V_77 ) ;
if ( ! V_31 )
goto V_70;
}
F_26 ( V_31 , V_58 ) ;
F_27 ( V_46 , V_31 , 0 , V_46 -> V_57 ) ;
V_6 = V_44 -> V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memcpy ( & V_33 , V_6 -> V_16 -> V_17 , sizeof( V_33 ) ) ;
F_16 ( V_29 , V_44 -> V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , V_31 , V_31 , V_46 -> V_57 , V_33 . V_41 ) ;
F_32 ( V_29 ) ;
F_20 ( V_29 ) ;
if ( V_31 != V_76 )
F_21 ( V_31 ) ;
if ( F_33 ( V_46 , 0 , & V_48 , sizeof( V_48 ) ) < 0 )
goto V_71;
if ( ! F_34 ( V_46 , sizeof( V_48 ) ) )
F_9 () ;
V_69 = F_30 ( V_48 . V_47 ) ;
V_47 = V_69 & 0xffff ;
V_52 = V_69 >> 16 ;
V_52 ^= V_50 -> V_51 . V_53 ^ V_50 -> V_51 . V_54 ;
V_52 &= 0xffff ;
if ( V_52 != 0 ) {
* V_68 = V_72 ;
goto V_73;
}
if ( V_47 > V_46 -> V_57 )
goto V_71;
else if ( V_47 < V_46 -> V_57 )
V_46 -> V_57 = V_47 ;
F_10 ( L_9 , V_47 ) ;
return 0 ;
V_71:
* V_68 = V_74 ;
V_73:
F_10 ( L_10 ) ;
return - V_75 ;
V_70:
F_10 ( L_11 ) ;
return - V_37 ;
}
static int F_37 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_3 * V_68 )
{
F_12 ( V_29 , V_44 -> V_2 -> V_28 ) ;
struct V_49 * V_50 ;
struct V_32 V_33 ;
struct V_30 V_31 ;
T_4 V_66 ;
T_3 V_41 , V_62 ;
int V_7 ;
V_50 = F_23 ( V_46 ) ;
F_2 ( L_13 ,
V_44 -> V_8 , F_3 ( V_44 -> V_2 -> V_9 . V_10 ) , V_50 -> V_51 . V_53 ) ;
if ( ! V_44 -> V_2 -> V_28 )
return 0 ;
if ( V_50 -> V_51 . V_78 != V_79 ) {
* V_68 = V_80 ;
F_10 ( L_14 ) ;
return - V_75 ;
}
memcpy ( & V_33 , V_44 -> V_2 -> V_42 . V_41 , sizeof( V_33 ) ) ;
V_41 = V_44 -> V_63 << ( 32 - V_64 ) ;
V_41 |= V_50 -> V_51 . V_53 & 0x3fffffff ;
V_44 -> V_65 [ 0 ] = F_14 ( V_44 -> V_81 ) ;
V_44 -> V_65 [ 1 ] = F_14 ( V_41 ) ;
F_15 ( & V_31 , V_44 -> V_65 , 8 ) ;
F_16 ( V_29 , V_44 -> V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , & V_31 , & V_31 , 8 , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
V_62 = F_30 ( V_44 -> V_65 [ 1 ] ) ;
V_66 = ( V_62 >> 16 ) & 0xffff ;
if ( V_66 == 0 )
V_66 = 1 ;
if ( V_50 -> V_51 . V_66 != V_66 ) {
* V_68 = V_72 ;
F_10 ( L_15 ) ;
return - V_75 ;
}
switch ( V_44 -> V_2 -> V_9 . V_18 ) {
case V_19 :
V_7 = 0 ;
break;
case V_20 :
V_7 = F_31 ( V_44 , V_46 , V_68 ) ;
break;
case V_25 :
V_7 = F_35 ( V_44 , V_46 , V_68 ) ;
break;
default:
V_7 = - V_82 ;
break;
}
F_10 ( L_4 , V_7 ) ;
return V_7 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_83 V_84 ;
struct V_85 V_86 ;
struct V_87 V_88 ;
struct V_89 V_90 [ 2 ] ;
T_2 V_57 ;
T_3 V_91 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
V_7 = F_29 ( V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
F_39 ( & V_2 -> V_92 , sizeof( V_2 -> V_92 ) ) ;
V_84 . V_93 = F_14 ( 2 ) ;
V_84 . V_94 = F_14 ( V_2 -> V_92 ) ;
V_84 . V_95 = F_14 ( 0 ) ;
V_84 . V_96 = 0 ;
V_88 . V_97 = & V_2 -> V_9 . V_98 -> V_99 . V_100 . sin ;
V_88 . V_101 = sizeof( V_2 -> V_9 . V_98 -> V_99 . V_100 . sin ) ;
V_88 . V_102 = NULL ;
V_88 . V_103 = 0 ;
V_88 . V_104 = 0 ;
V_86 . V_39 = F_14 ( V_2 -> V_38 . V_39 ) ;
V_86 . V_40 = F_14 ( V_2 -> V_38 . V_40 ) ;
V_86 . V_54 = 0 ;
V_86 . V_53 = 0 ;
V_86 . type = V_105 ;
V_86 . V_106 = V_2 -> V_107 ;
V_86 . V_108 = 0 ;
V_86 . V_78 = V_2 -> V_13 ;
V_86 . V_109 = 0 ;
V_86 . V_110 = F_40 ( V_2 -> V_9 . V_111 ) ;
V_90 [ 0 ] . V_112 = & V_86 ;
V_90 [ 0 ] . V_113 = sizeof( V_86 ) ;
V_90 [ 1 ] . V_112 = & V_84 ;
V_90 [ 1 ] . V_113 = sizeof( V_84 ) ;
V_57 = V_90 [ 0 ] . V_113 + V_90 [ 1 ] . V_113 ;
V_91 = F_41 ( & V_2 -> V_91 ) ;
V_86 . V_91 = F_14 ( V_91 ) ;
F_42 ( L_17 , V_91 ) ;
V_7 = F_43 ( V_2 -> V_9 . V_114 -> V_115 , & V_88 , V_90 , 2 , V_57 ) ;
if ( V_7 < 0 ) {
F_6 ( L_18 , V_7 ) ;
return - V_116 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_117 * V_51 ,
struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
struct V_85 V_86 ;
struct V_87 V_88 ;
struct V_89 V_90 [ 3 ] ;
T_2 V_57 ;
T_3 V_91 ;
int V_7 ;
F_2 ( L_5 ) ;
V_88 . V_97 = & V_2 -> V_9 . V_98 -> V_99 . V_100 . sin ;
V_88 . V_101 = sizeof( V_2 -> V_9 . V_98 -> V_99 . V_100 . sin ) ;
V_88 . V_102 = NULL ;
V_88 . V_103 = 0 ;
V_88 . V_104 = 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_39 = F_14 ( V_51 -> V_39 ) ;
V_86 . V_40 = F_14 ( V_51 -> V_40 ) ;
V_86 . type = V_122 ;
V_86 . V_106 = V_2 -> V_107 ;
V_86 . V_78 = V_51 -> V_78 ;
V_86 . V_110 = F_40 ( V_51 -> V_110 ) ;
V_90 [ 0 ] . V_112 = & V_86 ;
V_90 [ 0 ] . V_113 = sizeof( V_86 ) ;
V_90 [ 1 ] . V_112 = V_119 ;
V_90 [ 1 ] . V_113 = sizeof( * V_119 ) ;
V_90 [ 2 ] . V_112 = ( void * ) V_121 -> V_123 ;
V_90 [ 2 ] . V_113 = V_121 -> V_124 ;
V_57 = V_90 [ 0 ] . V_113 + V_90 [ 1 ] . V_113 + V_90 [ 2 ] . V_113 ;
V_91 = F_41 ( & V_2 -> V_91 ) ;
V_86 . V_91 = F_14 ( V_91 ) ;
F_42 ( L_19 , V_91 ) ;
V_7 = F_43 ( V_2 -> V_9 . V_114 -> V_115 , & V_88 , V_90 , 3 , V_57 ) ;
if ( V_7 < 0 ) {
F_6 ( L_18 , V_7 ) ;
return - V_116 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static void F_45 ( struct V_118 * V_125 )
{
T_3 V_126 = 1000003 ;
int V_127 ;
T_5 * V_128 = ( T_5 * ) V_125 ;
for ( V_127 = sizeof( * V_125 ) ; V_127 > 0 ; V_127 -- )
V_126 = V_126 * 0x10204081 + * V_128 ++ ;
V_125 -> V_129 . V_60 = F_14 ( V_126 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
F_12 ( V_29 , V_2 -> V_28 ) ;
struct V_32 V_33 ;
struct V_30 V_31 [ 1 ] ;
memcpy ( & V_33 , V_121 -> V_17 , sizeof( V_33 ) ) ;
F_26 ( V_31 , 1 ) ;
F_47 ( V_31 , & V_119 -> V_129 , sizeof( V_119 -> V_129 ) ) ;
F_16 ( V_29 , V_2 -> V_28 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , V_31 , V_31 , sizeof( V_119 -> V_129 ) , V_33 . V_41 ) ;
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_3 * V_68 )
{
const struct V_5 * V_6 ;
struct V_83 V_84 ;
struct V_118 V_119
V_130 ( ( F_49 ( 8 ) ) ) ;
struct V_49 * V_50 ;
T_3 V_93 , V_94 , V_95 , V_131 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_9 . V_10 ) ) ;
if ( ! V_2 -> V_9 . V_10 ) {
F_10 ( L_20 ) ;
return - V_75 ;
}
V_7 = F_29 ( V_2 -> V_9 . V_10 ) ;
if ( V_7 < 0 ) {
* V_68 = V_132 ;
return V_7 ;
}
V_131 = V_133 ;
V_50 = F_23 ( V_46 ) ;
if ( F_33 ( V_46 , 0 , & V_84 , sizeof( V_84 ) ) < 0 )
goto V_73;
V_93 = F_30 ( V_84 . V_93 ) ;
V_94 = F_30 ( V_84 . V_94 ) ;
V_95 = F_30 ( V_84 . V_95 ) ;
F_42 ( L_21 ,
V_50 -> V_51 . V_91 , V_93 , V_94 , V_95 ) ;
V_131 = V_80 ;
if ( V_93 != V_134 )
goto V_73;
V_131 = V_135 ;
if ( V_2 -> V_9 . V_18 < V_95 )
goto V_73;
V_6 = V_2 -> V_9 . V_10 -> V_11 . V_12 [ 0 ] ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_93 = F_14 ( V_134 ) ;
V_119 . V_129 . V_39 = F_14 ( V_2 -> V_38 . V_39 ) ;
V_119 . V_129 . V_40 = F_14 ( V_2 -> V_38 . V_40 ) ;
V_119 . V_129 . V_78 = F_14 ( V_2 -> V_13 ) ;
V_119 . V_129 . V_136 = F_14 ( V_94 + 1 ) ;
V_119 . V_129 . V_137 = F_14 ( V_2 -> V_9 . V_18 ) ;
V_119 . V_138 = F_14 ( V_6 -> V_16 -> V_138 ) ;
V_119 . V_124 = F_14 ( V_6 -> V_16 -> V_124 ) ;
V_119 . V_129 . V_81 [ 0 ] = F_14 ( V_2 -> V_139 [ 0 ] . V_140 ) ;
V_119 . V_129 . V_81 [ 1 ] = F_14 ( V_2 -> V_139 [ 1 ] . V_140 ) ;
V_119 . V_129 . V_81 [ 2 ] = F_14 ( V_2 -> V_139 [ 2 ] . V_140 ) ;
V_119 . V_129 . V_81 [ 3 ] = F_14 ( V_2 -> V_139 [ 3 ] . V_140 ) ;
F_45 ( & V_119 ) ;
F_46 ( V_2 , & V_119 , V_6 -> V_16 ) ;
return F_44 ( V_2 , & V_50 -> V_51 , & V_119 , V_6 -> V_16 ) ;
V_73:
* V_68 = V_131 ;
F_10 ( L_22 , V_131 ) ;
return - V_75 ;
}
static int F_50 ( struct V_1 * V_2 ,
void * V_123 , T_2 V_124 ,
struct V_32 * V_141 ,
T_6 * V_142 ,
T_3 * V_68 )
{
struct V_143 * V_29 ;
struct V_32 V_33 , V_10 ;
struct V_30 V_31 [ 1 ] ;
struct V_144 V_145 ;
unsigned int V_146 ;
T_6 V_147 , V_148 ;
bool V_149 ;
int V_7 ;
T_5 * V_128 , * V_150 , * V_151 , * V_152 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_153 ) ) ;
* V_142 = 0 ;
V_7 = F_29 ( V_2 -> V_153 ) ;
if ( V_7 < 0 ) {
switch ( V_7 ) {
case - V_154 :
* V_68 = V_132 ;
goto error;
default:
* V_68 = V_155 ;
goto error;
}
}
ASSERT ( V_2 -> V_153 -> V_11 . V_12 [ 0 ] != NULL ) ;
F_51 ( ( unsigned long ) V_123 & 7UL , == , 0 ) ;
memcpy ( & V_33 , & V_2 -> V_153 -> V_11 . V_12 [ 2 ] , sizeof( V_33 ) ) ;
V_29 = F_52 ( V_2 -> V_153 -> V_11 . V_12 [ 0 ] ,
V_156 ) ;
if ( ! V_29 ) {
* V_68 = V_155 ;
V_7 = - V_37 ;
goto error;
}
F_15 ( & V_31 [ 0 ] , V_123 , V_124 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , V_31 , V_31 , V_124 , V_33 . V_41 ) ;
F_32 ( V_29 ) ;
F_53 ( V_29 ) ;
V_128 = V_123 ;
V_152 = V_128 + V_124 ;
#define F_54 ( T_7 ) \
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
F_6 ( L_23 , * V_128 ) ;
V_149 = * V_128 & 1 ;
V_128 ++ ;
V_151 = F_54 ( V_157 ) ;
F_6 ( L_24 , V_151 ) ;
V_151 = F_54 ( V_158 ) ;
F_6 ( L_25 , V_151 ) ;
V_151 = F_54 ( V_159 ) ;
F_6 ( L_26 , V_151 ) ;
if ( V_152 - V_128 < 4 + 8 + 4 + 2 )
goto V_160;
memcpy ( & V_145 , V_128 , sizeof( V_145 ) ) ;
V_128 += 4 ;
F_6 ( L_27 , & V_145 ) ;
memcpy ( & V_10 , V_128 , sizeof( V_10 ) ) ;
V_128 += 8 ;
F_6 ( L_28 , F_30 ( V_10 . V_161 [ 0 ] ) , F_30 ( V_10 . V_161 [ 1 ] ) ) ;
memcpy ( V_141 , & V_10 , sizeof( V_10 ) ) ;
V_146 = * V_128 ++ * 5 * 60 ;
F_6 ( L_29 , V_146 ) ;
if ( V_149 ) {
T_8 V_162 ;
memcpy ( & V_162 , V_128 , 4 ) ;
V_147 = F_55 ( V_162 ) ;
} else {
T_1 V_162 ;
memcpy ( & V_162 , V_128 , 4 ) ;
V_147 = F_56 ( V_162 ) ;
}
V_128 += 4 ;
V_148 = F_57 () ;
F_6 ( L_30 , V_147 , V_148 ) ;
if ( V_147 > V_148 ) {
* V_68 = V_155 ;
V_7 = - V_27 ;
goto error;
}
if ( V_147 < V_148 - V_146 ) {
* V_68 = V_132 ;
V_7 = - V_154 ;
goto error;
}
* V_142 = V_147 + V_146 ;
V_151 = F_54 ( V_163 ) ;
F_6 ( L_31 , V_151 ) ;
V_151 = F_54 ( V_158 ) ;
F_6 ( L_32 , V_151 ) ;
V_7 = 0 ;
error:
F_10 ( L_4 , V_7 ) ;
return V_7 ;
V_160:
* V_68 = V_164 ;
V_7 = - V_165 ;
goto error;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
const struct V_32 * V_17 )
{
F_12 ( V_29 , V_166 ) ;
struct V_30 V_31 [ 1 ] ;
struct V_32 V_33 ;
F_2 ( L_33 ,
F_30 ( V_17 -> V_161 [ 0 ] ) , F_30 ( V_17 -> V_161 [ 1 ] ) ) ;
ASSERT ( V_166 != NULL ) ;
F_59 ( & V_167 ) ;
if ( F_8 ( V_166 , V_17 -> V_41 ,
sizeof( * V_17 ) ) < 0 )
F_9 () ;
memcpy ( & V_33 , V_17 , sizeof( V_33 ) ) ;
F_26 ( V_31 , 1 ) ;
F_47 ( V_31 , & V_119 -> V_129 , sizeof( V_119 -> V_129 ) ) ;
F_16 ( V_29 , V_166 ) ;
F_17 ( V_29 , 0 , NULL , NULL ) ;
F_18 ( V_29 , V_31 , V_31 , sizeof( V_119 -> V_129 ) , V_33 . V_41 ) ;
F_32 ( V_29 ) ;
F_20 ( V_29 ) ;
F_60 ( & V_167 ) ;
F_10 ( L_5 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_3 * V_68 )
{
struct V_118 V_125
V_130 ( ( F_49 ( 8 ) ) ) ;
struct V_49 * V_50 ;
struct V_32 V_17 ;
T_6 V_168 ;
void * V_123 ;
T_3 V_131 , V_93 , V_138 , V_124 , V_137 ;
T_1 V_126 ;
int V_7 , V_169 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_153 ) ) ;
V_131 = V_133 ;
if ( F_33 ( V_46 , 0 , & V_125 , sizeof( V_125 ) ) < 0 )
goto V_73;
if ( ! F_62 ( V_46 , sizeof( V_125 ) ) )
F_9 () ;
V_93 = F_30 ( V_125 . V_93 ) ;
V_124 = F_30 ( V_125 . V_124 ) ;
V_138 = F_30 ( V_125 . V_138 ) ;
V_50 = F_23 ( V_46 ) ;
F_42 ( L_34 ,
V_50 -> V_51 . V_91 , V_93 , V_138 , V_124 ) ;
V_131 = V_80 ;
if ( V_93 != V_134 )
goto V_73;
V_131 = V_170 ;
if ( V_124 < 4 || V_124 > V_171 )
goto V_73;
V_131 = V_172 ;
if ( V_138 >= V_173 )
goto V_73;
V_123 = F_13 ( V_124 , V_156 ) ;
if ( ! V_123 )
return - V_37 ;
V_131 = V_133 ;
if ( F_33 ( V_46 , 0 , V_123 , V_124 ) < 0 )
goto V_174;
V_7 = F_50 ( V_2 , V_123 , V_124 , & V_17 ,
& V_168 , & V_131 ) ;
if ( V_7 < 0 ) {
* V_68 = V_131 ;
F_21 ( V_123 ) ;
return V_7 ;
}
F_58 ( V_2 , & V_125 , & V_17 ) ;
V_131 = V_72 ;
if ( F_30 ( V_125 . V_129 . V_39 ) != V_2 -> V_38 . V_39 )
goto V_174;
if ( F_30 ( V_125 . V_129 . V_40 ) != V_2 -> V_38 . V_40 )
goto V_174;
if ( F_30 ( V_125 . V_129 . V_78 ) != V_2 -> V_13 )
goto V_174;
V_126 = V_125 . V_129 . V_60 ;
V_125 . V_129 . V_60 = 0 ;
F_45 ( & V_125 ) ;
if ( V_125 . V_129 . V_60 != V_126 )
goto V_174;
F_63 ( & V_2 -> V_175 ) ;
for ( V_169 = 0 ; V_169 < V_176 ; V_169 ++ ) {
struct V_43 * V_44 ;
T_3 V_81 = F_30 ( V_125 . V_129 . V_81 [ V_169 ] ) ;
if ( V_81 > V_177 )
goto V_178;
if ( V_81 < V_2 -> V_139 [ V_169 ] . V_140 )
goto V_178;
if ( V_81 > V_2 -> V_139 [ V_169 ] . V_140 ) {
V_44 = F_64 (
V_2 -> V_139 [ V_169 ] . V_44 ,
F_65 ( & V_2 -> V_175 ) ) ;
if ( V_44 && V_44 -> V_179 < V_180 )
goto V_178;
V_2 -> V_139 [ V_169 ] . V_140 = V_81 ;
}
}
F_66 ( & V_2 -> V_175 ) ;
V_131 = V_181 ;
if ( F_30 ( V_125 . V_129 . V_136 ) != V_2 -> V_92 + 1 )
goto V_174;
V_131 = V_135 ;
V_137 = F_30 ( V_125 . V_129 . V_137 ) ;
if ( V_137 > V_25 )
goto V_174;
V_2 -> V_9 . V_18 = V_137 ;
V_7 = F_67 ( V_2 , & V_17 , V_168 , V_138 ) ;
if ( V_7 < 0 ) {
F_21 ( V_123 ) ;
return V_7 ;
}
F_21 ( V_123 ) ;
F_10 ( L_6 ) ;
return 0 ;
V_178:
F_66 ( & V_2 -> V_175 ) ;
V_174:
F_21 ( V_123 ) ;
V_73:
* V_68 = V_131 ;
F_10 ( L_22 , V_131 ) ;
return - V_75 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( V_2 -> V_28 )
F_69 ( V_2 -> V_28 ) ;
}
static int F_70 ( void )
{
V_166 = F_4 ( L_2 , 0 , V_15 ) ;
return F_71 ( V_166 ) ;
}
static void F_72 ( void )
{
if ( V_166 )
F_69 ( V_166 ) ;
}
