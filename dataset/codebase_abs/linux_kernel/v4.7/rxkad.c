static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_9 ) ) ;
V_6 = V_2 -> V_9 -> V_10 . V_11 [ 0 ] ;
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
F_12 ( V_28 , V_2 -> V_27 ) ;
struct V_29 V_30 [ 2 ] ;
struct V_31 V_32 ;
struct {
T_1 V_33 [ 4 ] ;
} V_34 V_35 ( ( F_13 ( 16 ) ) ) ;
F_2 ( L_5 ) ;
if ( ! V_2 -> V_9 )
return;
V_6 = V_2 -> V_9 -> V_10 . V_11 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_15 -> V_16 , sizeof( V_32 ) ) ;
V_34 . V_33 [ 0 ] = F_14 ( V_2 -> V_36 ) ;
V_34 . V_33 [ 1 ] = F_14 ( V_2 -> V_37 ) ;
V_34 . V_33 [ 2 ] = 0 ;
V_34 . V_33 [ 3 ] = F_14 ( V_2 -> V_12 ) ;
F_15 ( & V_30 [ 0 ] , & V_34 , sizeof( V_34 ) ) ;
F_15 ( & V_30 [ 1 ] , & V_34 , sizeof( V_34 ) ) ;
F_16 ( V_28 , V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 [ 1 ] , & V_30 [ 0 ] , sizeof( V_34 ) , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
memcpy ( & V_2 -> V_38 , & V_34 . V_33 [ 2 ] , sizeof( V_2 -> V_38 ) ) ;
F_21 ( ( V_39 V_40 ) V_2 -> V_38 . V_41 [ 0 ] , == , ( V_39 V_40 ) V_34 . V_33 [ 2 ] ) ;
F_10 ( L_5 ) ;
}
static int F_22 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
V_39 V_46 ,
void * V_47 )
{
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 2 ] ;
struct {
struct V_22 V_50 ;
T_1 V_51 ;
} V_34 V_35 ( ( F_13 ( 8 ) ) ) ;
T_2 V_52 ;
V_49 = F_23 ( V_45 ) ;
F_2 ( L_5 ) ;
V_52 = V_49 -> V_50 . V_53 ^ V_49 -> V_50 . V_54 ;
V_46 |= ( V_39 ) V_52 << 16 ;
V_34 . V_50 . V_46 = F_14 ( V_46 ) ;
memcpy ( & V_34 . V_51 , V_47 + 4 , sizeof( V_34 . V_51 ) ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_15 ( & V_30 [ 0 ] , & V_34 , sizeof( V_34 ) ) ;
F_15 ( & V_30 [ 1 ] , & V_34 , sizeof( V_34 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 [ 1 ] , & V_30 [ 0 ] , sizeof( V_34 ) , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
memcpy ( V_47 , & V_34 , sizeof( V_34 ) ) ;
F_10 ( L_6 ) ;
return 0 ;
}
static int F_24 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
V_39 V_46 ,
void * V_47 )
{
const struct V_5 * V_6 ;
struct V_25 T_3
V_35 ( ( F_13 ( 8 ) ) ) ;
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 16 ] ;
struct V_44 * V_55 ;
unsigned int V_56 ;
T_2 V_52 ;
int V_57 ;
int V_58 ;
V_49 = F_23 ( V_45 ) ;
F_2 ( L_5 ) ;
V_52 = V_49 -> V_50 . V_53 ^ V_49 -> V_50 . V_54 ;
T_3 . V_46 = F_14 ( V_46 | ( V_39 ) V_52 << 16 ) ;
T_3 . V_59 = 0 ;
V_6 = V_43 -> V_2 -> V_9 -> V_10 . V_11 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_15 -> V_16 , sizeof( V_32 ) ) ;
F_15 ( & V_30 [ 0 ] , V_47 , sizeof( T_3 ) ) ;
F_15 ( & V_30 [ 1 ] , & T_3 , sizeof( T_3 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 [ 1 ] , & V_30 [ 0 ] , sizeof( T_3 ) , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
V_58 = - V_60 ;
if ( V_57 < 0 || V_57 > 16 )
goto V_61;
V_56 = V_46 + V_43 -> V_2 -> V_20 - 1 ;
V_56 &= ~ ( V_43 -> V_2 -> V_20 - 1 ) ;
F_26 ( V_30 , V_57 ) ;
F_27 ( V_45 , V_30 , 0 , V_56 ) ;
F_18 ( V_28 , V_30 , V_30 , V_56 , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
F_10 ( L_6 ) ;
V_58 = 0 ;
V_61:
F_20 ( V_28 ) ;
return V_58 ;
}
static int F_28 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
T_4 V_46 ,
void * V_47 )
{
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 2 ] ;
struct {
T_1 V_33 [ 2 ] ;
} V_34 V_35 ( ( F_13 ( 8 ) ) ) ;
V_39 V_33 , V_62 ;
int V_7 ;
V_49 = F_23 ( V_45 ) ;
F_2 ( L_7 ,
V_43 -> V_8 , F_3 ( V_43 -> V_2 -> V_9 ) , V_49 -> V_50 . V_53 ,
V_46 ) ;
if ( ! V_43 -> V_2 -> V_27 )
return 0 ;
V_7 = F_29 ( V_43 -> V_2 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
memcpy ( & V_32 , V_43 -> V_2 -> V_38 . V_33 , sizeof( V_32 ) ) ;
V_33 = V_43 -> V_63 << ( 32 - V_64 ) ;
V_33 |= V_49 -> V_50 . V_53 & 0x3fffffff ;
V_34 . V_33 [ 0 ] = F_14 ( V_49 -> V_50 . V_54 ) ;
V_34 . V_33 [ 1 ] = F_14 ( V_33 ) ;
F_15 ( & V_30 [ 0 ] , & V_34 , sizeof( V_34 ) ) ;
F_15 ( & V_30 [ 1 ] , & V_34 , sizeof( V_34 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 [ 1 ] , & V_30 [ 0 ] , sizeof( V_34 ) , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
V_62 = F_30 ( V_34 . V_33 [ 1 ] ) ;
V_62 = ( V_62 >> 16 ) & 0xffff ;
if ( V_62 == 0 )
V_62 = 1 ;
V_49 -> V_50 . V_65 = V_62 ;
switch ( V_43 -> V_2 -> V_17 ) {
case V_18 :
V_7 = 0 ;
break;
case V_19 :
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
F_10 ( L_8 , V_7 , V_62 ) ;
return V_7 ;
}
static int F_31 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
V_39 * V_67 )
{
struct V_22 V_47 ;
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 16 ] ;
struct V_44 * V_55 ;
V_39 V_46 , V_68 ;
T_2 V_52 ;
int V_57 ;
F_2 ( L_5 ) ;
V_49 = F_23 ( V_45 ) ;
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
if ( V_57 < 0 || V_57 > 16 )
goto V_69;
F_26 ( V_30 , V_57 ) ;
F_27 ( V_45 , V_30 , 0 , 8 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , 8 , V_32 . V_33 ) ;
F_32 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( F_33 ( V_45 , 0 , & V_47 , sizeof( V_47 ) ) < 0 )
goto V_70;
if ( ! F_34 ( V_45 , sizeof( V_47 ) ) )
F_9 () ;
V_68 = F_30 ( V_47 . V_46 ) ;
V_46 = V_68 & 0xffff ;
V_52 = V_68 >> 16 ;
V_52 ^= V_49 -> V_50 . V_53 ^ V_49 -> V_50 . V_54 ;
V_52 &= 0xffff ;
if ( V_52 != 0 ) {
* V_67 = V_71 ;
goto V_72;
}
if ( V_46 > V_45 -> V_56 )
goto V_70;
else if ( V_46 < V_45 -> V_56 )
V_45 -> V_56 = V_46 ;
F_10 ( L_9 , V_46 ) ;
return 0 ;
V_70:
* V_67 = V_73 ;
V_72:
F_10 ( L_10 ) ;
return - V_74 ;
V_69:
F_10 ( L_11 ) ;
return - V_60 ;
}
static int F_35 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
V_39 * V_67 )
{
const struct V_5 * V_6 ;
struct V_25 V_47 ;
struct V_48 * V_49 ;
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_75 [ 4 ] , * V_30 ;
struct V_44 * V_55 ;
V_39 V_46 , V_68 ;
T_2 V_52 ;
int V_57 ;
F_2 ( L_12 , V_45 -> V_56 ) ;
V_49 = F_23 ( V_45 ) ;
V_57 = F_25 ( V_45 , 0 , & V_55 ) ;
if ( V_57 < 0 )
goto V_69;
V_30 = V_75 ;
if ( F_36 ( V_57 > 4 ) ) {
V_30 = F_37 ( sizeof( * V_30 ) * V_57 , V_76 ) ;
if ( ! V_30 )
goto V_69;
}
F_26 ( V_30 , V_57 ) ;
F_27 ( V_45 , V_30 , 0 , V_45 -> V_56 ) ;
V_6 = V_43 -> V_2 -> V_9 -> V_10 . V_11 [ 0 ] ;
memcpy ( & V_32 , V_6 -> V_15 -> V_16 , sizeof( V_32 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , V_45 -> V_56 , V_32 . V_33 ) ;
F_32 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( V_30 != V_75 )
F_38 ( V_30 ) ;
if ( F_33 ( V_45 , 0 , & V_47 , sizeof( V_47 ) ) < 0 )
goto V_70;
if ( ! F_34 ( V_45 , sizeof( V_47 ) ) )
F_9 () ;
V_68 = F_30 ( V_47 . V_46 ) ;
V_46 = V_68 & 0xffff ;
V_52 = V_68 >> 16 ;
V_52 ^= V_49 -> V_50 . V_53 ^ V_49 -> V_50 . V_54 ;
V_52 &= 0xffff ;
if ( V_52 != 0 ) {
* V_67 = V_71 ;
goto V_72;
}
if ( V_46 > V_45 -> V_56 )
goto V_70;
else if ( V_46 < V_45 -> V_56 )
V_45 -> V_56 = V_46 ;
F_10 ( L_9 , V_46 ) ;
return 0 ;
V_70:
* V_67 = V_73 ;
V_72:
F_10 ( L_10 ) ;
return - V_74 ;
V_69:
F_10 ( L_11 ) ;
return - V_60 ;
}
static int F_39 ( const struct V_42 * V_43 ,
struct V_44 * V_45 ,
V_39 * V_67 )
{
F_12 ( V_28 , V_43 -> V_2 -> V_27 ) ;
struct V_48 * V_49 ;
struct V_31 V_32 ;
struct V_29 V_30 [ 2 ] ;
struct {
T_1 V_33 [ 2 ] ;
} V_34 V_35 ( ( F_13 ( 8 ) ) ) ;
T_2 V_65 ;
V_39 V_33 , V_62 ;
int V_7 ;
V_49 = F_23 ( V_45 ) ;
F_2 ( L_13 ,
V_43 -> V_8 , F_3 ( V_43 -> V_2 -> V_9 ) , V_49 -> V_50 . V_53 ) ;
if ( ! V_43 -> V_2 -> V_27 )
return 0 ;
if ( V_49 -> V_50 . V_77 != V_78 ) {
* V_67 = V_79 ;
F_10 ( L_14 ) ;
return - V_74 ;
}
memcpy ( & V_32 , V_43 -> V_2 -> V_38 . V_33 , sizeof( V_32 ) ) ;
V_33 = V_43 -> V_63 << ( 32 - V_64 ) ;
V_33 |= V_49 -> V_50 . V_53 & 0x3fffffff ;
V_34 . V_33 [ 0 ] = F_14 ( V_43 -> V_80 ) ;
V_34 . V_33 [ 1 ] = F_14 ( V_33 ) ;
F_15 ( & V_30 [ 0 ] , & V_34 , sizeof( V_34 ) ) ;
F_15 ( & V_30 [ 1 ] , & V_34 , sizeof( V_34 ) ) ;
F_16 ( V_28 , V_43 -> V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , & V_30 [ 1 ] , & V_30 [ 0 ] , sizeof( V_34 ) , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
V_62 = F_30 ( V_34 . V_33 [ 1 ] ) ;
V_65 = ( V_62 >> 16 ) & 0xffff ;
if ( V_65 == 0 )
V_65 = 1 ;
if ( V_49 -> V_50 . V_65 != V_65 ) {
* V_67 = V_71 ;
F_10 ( L_15 ) ;
return - V_74 ;
}
switch ( V_43 -> V_2 -> V_17 ) {
case V_18 :
V_7 = 0 ;
break;
case V_19 :
V_7 = F_31 ( V_43 , V_45 , V_67 ) ;
break;
case V_24 :
V_7 = F_35 ( V_43 , V_45 , V_67 ) ;
break;
default:
V_7 = - V_81 ;
break;
}
F_10 ( L_4 , V_7 ) ;
return V_7 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_82 V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
struct V_88 V_89 [ 2 ] ;
T_4 V_56 ;
V_39 V_90 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_9 ) ) ;
V_7 = F_29 ( V_2 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
F_41 ( & V_2 -> V_91 , sizeof( V_2 -> V_91 ) ) ;
V_83 . V_92 = F_14 ( 2 ) ;
V_83 . V_93 = F_14 ( V_2 -> V_91 ) ;
V_83 . V_94 = F_14 ( 0 ) ;
V_83 . V_95 = 0 ;
V_87 . V_96 = & V_2 -> V_97 -> V_98 -> V_99 . V_100 . sin ;
V_87 . V_101 = sizeof( V_2 -> V_97 -> V_98 -> V_99 . V_100 . sin ) ;
V_87 . V_102 = NULL ;
V_87 . V_103 = 0 ;
V_87 . V_104 = 0 ;
V_85 . V_36 = F_14 ( V_2 -> V_36 ) ;
V_85 . V_37 = F_14 ( V_2 -> V_37 ) ;
V_85 . V_54 = 0 ;
V_85 . V_53 = 0 ;
V_85 . type = V_105 ;
V_85 . V_106 = V_2 -> V_107 ;
V_85 . V_108 = 0 ;
V_85 . V_77 = V_2 -> V_12 ;
V_85 . V_109 = 0 ;
V_85 . V_110 = F_42 ( V_2 -> V_111 ) ;
V_89 [ 0 ] . V_112 = & V_85 ;
V_89 [ 0 ] . V_113 = sizeof( V_85 ) ;
V_89 [ 1 ] . V_112 = & V_83 ;
V_89 [ 1 ] . V_113 = sizeof( V_83 ) ;
V_56 = V_89 [ 0 ] . V_113 + V_89 [ 1 ] . V_113 ;
V_90 = F_43 ( & V_2 -> V_90 ) ;
V_85 . V_90 = F_14 ( V_90 ) ;
F_44 ( L_17 , V_90 ) ;
V_7 = F_45 ( V_2 -> V_97 -> V_114 -> V_115 , & V_87 , V_89 , 2 , V_56 ) ;
if ( V_7 < 0 ) {
F_6 ( L_18 , V_7 ) ;
return - V_116 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_117 * V_50 ,
struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
struct V_84 V_85 ;
struct V_86 V_87 ;
struct V_88 V_89 [ 3 ] ;
T_4 V_56 ;
V_39 V_90 ;
int V_7 ;
F_2 ( L_5 ) ;
V_87 . V_96 = & V_2 -> V_97 -> V_98 -> V_99 . V_100 . sin ;
V_87 . V_101 = sizeof( V_2 -> V_97 -> V_98 -> V_99 . V_100 . sin ) ;
V_87 . V_102 = NULL ;
V_87 . V_103 = 0 ;
V_87 . V_104 = 0 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_36 = F_14 ( V_50 -> V_36 ) ;
V_85 . V_37 = F_14 ( V_50 -> V_37 ) ;
V_85 . type = V_122 ;
V_85 . V_106 = V_2 -> V_107 ;
V_85 . V_77 = V_50 -> V_77 ;
V_85 . V_110 = F_42 ( V_50 -> V_110 ) ;
V_89 [ 0 ] . V_112 = & V_85 ;
V_89 [ 0 ] . V_113 = sizeof( V_85 ) ;
V_89 [ 1 ] . V_112 = V_119 ;
V_89 [ 1 ] . V_113 = sizeof( * V_119 ) ;
V_89 [ 2 ] . V_112 = ( void * ) V_121 -> V_123 ;
V_89 [ 2 ] . V_113 = V_121 -> V_124 ;
V_56 = V_89 [ 0 ] . V_113 + V_89 [ 1 ] . V_113 + V_89 [ 2 ] . V_113 ;
V_90 = F_43 ( & V_2 -> V_90 ) ;
V_85 . V_90 = F_14 ( V_90 ) ;
F_44 ( L_19 , V_90 ) ;
V_7 = F_45 ( V_2 -> V_97 -> V_114 -> V_115 , & V_87 , V_89 , 3 , V_56 ) ;
if ( V_7 < 0 ) {
F_6 ( L_18 , V_7 ) ;
return - V_116 ;
}
F_10 ( L_6 ) ;
return 0 ;
}
static void F_47 ( struct V_118 * V_125 )
{
V_39 V_126 = 1000003 ;
int V_127 ;
T_5 * V_128 = ( T_5 * ) V_125 ;
for ( V_127 = sizeof( * V_125 ) ; V_127 > 0 ; V_127 -- )
V_126 = V_126 * 0x10204081 + * V_128 ++ ;
V_125 -> V_129 . V_59 = F_14 ( V_126 ) ;
}
static void F_48 ( struct V_29 V_30 [ 2 ] ,
void * V_68 , T_4 V_130 )
{
int V_57 = 1 ;
F_26 ( V_30 , 2 ) ;
F_49 ( & V_30 [ 0 ] , V_68 , V_130 ) ;
if ( V_30 [ 0 ] . V_131 + V_130 > V_132 ) {
V_30 [ 0 ] . V_133 = V_132 - V_30 [ 0 ] . V_131 ;
F_49 ( & V_30 [ 1 ] , V_68 + V_30 [ 0 ] . V_133 , V_130 - V_30 [ 0 ] . V_133 ) ;
V_57 ++ ;
}
F_50 ( & V_30 [ V_57 - 1 ] ) ;
F_21 ( V_30 [ 0 ] . V_133 + V_30 [ 1 ] . V_133 , == , V_130 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
const struct V_120 * V_121 )
{
F_12 ( V_28 , V_2 -> V_27 ) ;
struct V_31 V_32 ;
struct V_29 V_30 [ 2 ] ;
memcpy ( & V_32 , V_121 -> V_16 , sizeof( V_32 ) ) ;
F_48 ( V_30 , & V_119 -> V_129 , sizeof( V_119 -> V_129 ) ) ;
F_16 ( V_28 , V_2 -> V_27 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , sizeof( V_119 -> V_129 ) , V_32 . V_33 ) ;
F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
V_39 * V_67 )
{
const struct V_5 * V_6 ;
struct V_82 V_83 ;
struct V_118 V_119
V_35 ( ( F_13 ( 8 ) ) ) ;
struct V_48 * V_49 ;
V_39 V_92 , V_93 , V_94 , V_134 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_9 ) ) ;
if ( ! V_2 -> V_9 ) {
F_10 ( L_20 ) ;
return - V_74 ;
}
V_7 = F_29 ( V_2 -> V_9 ) ;
if ( V_7 < 0 ) {
* V_67 = V_135 ;
return V_7 ;
}
V_134 = V_136 ;
V_49 = F_23 ( V_45 ) ;
if ( F_33 ( V_45 , 0 , & V_83 , sizeof( V_83 ) ) < 0 )
goto V_72;
V_92 = F_30 ( V_83 . V_92 ) ;
V_93 = F_30 ( V_83 . V_93 ) ;
V_94 = F_30 ( V_83 . V_94 ) ;
F_44 ( L_21 ,
V_49 -> V_50 . V_90 , V_92 , V_93 , V_94 ) ;
V_134 = V_79 ;
if ( V_92 != V_137 )
goto V_72;
V_134 = V_138 ;
if ( V_2 -> V_17 < V_94 )
goto V_72;
V_6 = V_2 -> V_9 -> V_10 . V_11 [ 0 ] ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_92 = F_14 ( V_137 ) ;
V_119 . V_129 . V_36 = F_14 ( V_2 -> V_36 ) ;
V_119 . V_129 . V_37 = F_14 ( V_2 -> V_37 ) ;
V_119 . V_129 . V_77 = F_14 ( V_2 -> V_12 ) ;
V_119 . V_129 . V_139 = F_14 ( V_93 + 1 ) ;
V_119 . V_129 . V_140 = F_14 ( V_2 -> V_17 ) ;
V_119 . V_141 = F_14 ( V_6 -> V_15 -> V_141 ) ;
V_119 . V_124 = F_14 ( V_6 -> V_15 -> V_124 ) ;
V_119 . V_129 . V_80 [ 0 ] =
F_14 ( V_2 -> V_142 [ 0 ] ? V_2 -> V_142 [ 0 ] -> V_80 : 0 ) ;
V_119 . V_129 . V_80 [ 1 ] =
F_14 ( V_2 -> V_142 [ 1 ] ? V_2 -> V_142 [ 1 ] -> V_80 : 0 ) ;
V_119 . V_129 . V_80 [ 2 ] =
F_14 ( V_2 -> V_142 [ 2 ] ? V_2 -> V_142 [ 2 ] -> V_80 : 0 ) ;
V_119 . V_129 . V_80 [ 3 ] =
F_14 ( V_2 -> V_142 [ 3 ] ? V_2 -> V_142 [ 3 ] -> V_80 : 0 ) ;
F_47 ( & V_119 ) ;
F_51 ( V_2 , & V_119 , V_6 -> V_15 ) ;
return F_46 ( V_2 , & V_49 -> V_50 , & V_119 , V_6 -> V_15 ) ;
V_72:
* V_67 = V_134 ;
F_10 ( L_22 , V_134 ) ;
return - V_74 ;
}
static int F_53 ( struct V_1 * V_2 ,
void * V_123 , T_4 V_124 ,
struct V_31 * V_143 ,
T_6 * V_144 ,
V_39 * V_67 )
{
struct V_145 * V_28 ;
struct V_31 V_32 , V_9 ;
struct V_29 V_30 [ 1 ] ;
struct V_146 V_147 ;
unsigned int V_148 ;
T_6 V_149 , V_150 ;
bool V_151 ;
int V_7 ;
T_5 * V_128 , * V_152 , * V_153 , * V_154 ;
F_2 ( L_1 , V_2 -> V_8 , F_3 ( V_2 -> V_155 ) ) ;
* V_144 = 0 ;
V_7 = F_29 ( V_2 -> V_155 ) ;
if ( V_7 < 0 ) {
switch ( V_7 ) {
case - V_156 :
* V_67 = V_135 ;
goto error;
default:
* V_67 = V_157 ;
goto error;
}
}
ASSERT ( V_2 -> V_155 -> V_10 . V_11 [ 0 ] != NULL ) ;
F_21 ( ( unsigned long ) V_123 & 7UL , == , 0 ) ;
memcpy ( & V_32 , & V_2 -> V_155 -> V_10 . V_11 [ 2 ] , sizeof( V_32 ) ) ;
V_28 = F_54 ( V_2 -> V_155 -> V_10 . V_11 [ 0 ] ,
V_158 ) ;
if ( ! V_28 ) {
* V_67 = V_157 ;
V_7 = - V_60 ;
goto error;
}
F_15 ( & V_30 [ 0 ] , V_123 , V_124 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , V_124 , V_32 . V_33 ) ;
F_32 ( V_28 ) ;
F_55 ( V_28 ) ;
V_128 = V_123 ;
V_154 = V_128 + V_124 ;
#define F_56 ( T_7 ) \
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
V_151 = * V_128 & 1 ;
V_128 ++ ;
V_153 = F_56 ( V_159 ) ;
F_6 ( L_24 , V_153 ) ;
V_153 = F_56 ( V_160 ) ;
F_6 ( L_25 , V_153 ) ;
V_153 = F_56 ( V_161 ) ;
F_6 ( L_26 , V_153 ) ;
if ( V_154 - V_128 < 4 + 8 + 4 + 2 )
goto V_162;
memcpy ( & V_147 , V_128 , sizeof( V_147 ) ) ;
V_128 += 4 ;
F_6 ( L_27 , & V_147 ) ;
memcpy ( & V_9 , V_128 , sizeof( V_9 ) ) ;
V_128 += 8 ;
F_6 ( L_28 , F_30 ( V_9 . V_41 [ 0 ] ) , F_30 ( V_9 . V_41 [ 1 ] ) ) ;
memcpy ( V_143 , & V_9 , sizeof( V_9 ) ) ;
V_148 = * V_128 ++ * 5 * 60 ;
F_6 ( L_29 , V_148 ) ;
if ( V_151 ) {
T_8 V_163 ;
memcpy ( & V_163 , V_128 , 4 ) ;
V_149 = F_57 ( V_163 ) ;
} else {
T_1 V_163 ;
memcpy ( & V_163 , V_128 , 4 ) ;
V_149 = F_58 ( V_163 ) ;
}
V_128 += 4 ;
V_150 = F_59 () ;
F_6 ( L_30 , V_149 , V_150 ) ;
if ( V_149 > V_150 ) {
* V_67 = V_157 ;
V_7 = - V_26 ;
goto error;
}
if ( V_149 < V_150 - V_148 ) {
* V_67 = V_135 ;
V_7 = - V_156 ;
goto error;
}
* V_144 = V_149 + V_148 ;
V_153 = F_56 ( V_164 ) ;
F_6 ( L_31 , V_153 ) ;
V_153 = F_56 ( V_160 ) ;
F_6 ( L_32 , V_153 ) ;
V_7 = 0 ;
error:
F_10 ( L_4 , V_7 ) ;
return V_7 ;
V_162:
* V_67 = V_165 ;
V_7 = - V_166 ;
goto error;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
const struct V_31 * V_16 )
{
F_12 ( V_28 , V_167 ) ;
struct V_29 V_30 [ 2 ] ;
struct V_31 V_32 ;
F_2 ( L_33 ,
F_30 ( V_16 -> V_41 [ 0 ] ) , F_30 ( V_16 -> V_41 [ 1 ] ) ) ;
ASSERT ( V_167 != NULL ) ;
F_61 ( & V_168 ) ;
if ( F_8 ( V_167 , V_16 -> V_33 ,
sizeof( * V_16 ) ) < 0 )
F_9 () ;
memcpy ( & V_32 , V_16 , sizeof( V_32 ) ) ;
F_48 ( V_30 , & V_119 -> V_129 , sizeof( V_119 -> V_129 ) ) ;
F_16 ( V_28 , V_167 ) ;
F_17 ( V_28 , 0 , NULL , NULL ) ;
F_18 ( V_28 , V_30 , V_30 , sizeof( V_119 -> V_129 ) , V_32 . V_33 ) ;
F_32 ( V_28 ) ;
F_20 ( V_28 ) ;
F_62 ( & V_168 ) ;
F_10 ( L_5 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
V_39 * V_67 )
{
struct V_118 V_125
V_35 ( ( F_13 ( 8 ) ) ) ;
struct V_48 * V_49 ;
struct V_31 V_16 ;
T_6 V_169 ;
void * V_123 ;
V_39 V_134 , V_92 , V_141 , V_124 , V_140 ;
T_1 V_126 ;
int V_7 ;
F_2 ( L_16 , V_2 -> V_8 , F_3 ( V_2 -> V_155 ) ) ;
V_134 = V_136 ;
if ( F_33 ( V_45 , 0 , & V_125 , sizeof( V_125 ) ) < 0 )
goto V_72;
if ( ! F_64 ( V_45 , sizeof( V_125 ) ) )
F_9 () ;
V_92 = F_30 ( V_125 . V_92 ) ;
V_124 = F_30 ( V_125 . V_124 ) ;
V_141 = F_30 ( V_125 . V_141 ) ;
V_49 = F_23 ( V_45 ) ;
F_44 ( L_34 ,
V_49 -> V_50 . V_90 , V_92 , V_141 , V_124 ) ;
V_134 = V_79 ;
if ( V_92 != V_137 )
goto V_72;
V_134 = V_170 ;
if ( V_124 < 4 || V_124 > V_171 )
goto V_72;
V_134 = V_172 ;
if ( V_141 >= V_173 )
goto V_72;
V_123 = F_37 ( V_124 , V_158 ) ;
if ( ! V_123 )
return - V_60 ;
V_134 = V_136 ;
if ( F_33 ( V_45 , 0 , V_123 , V_124 ) < 0 )
goto V_174;
V_7 = F_53 ( V_2 , V_123 , V_124 , & V_16 ,
& V_169 , & V_134 ) ;
if ( V_7 < 0 ) {
* V_67 = V_134 ;
F_38 ( V_123 ) ;
return V_7 ;
}
F_60 ( V_2 , & V_125 , & V_16 ) ;
V_134 = V_71 ;
if ( F_30 ( V_125 . V_129 . V_36 ) != V_2 -> V_36 )
goto V_174;
if ( F_30 ( V_125 . V_129 . V_37 ) != V_2 -> V_37 )
goto V_174;
if ( F_30 ( V_125 . V_129 . V_77 ) != V_2 -> V_12 )
goto V_174;
V_126 = V_125 . V_129 . V_59 ;
V_125 . V_129 . V_59 = 0 ;
F_47 ( & V_125 ) ;
if ( V_125 . V_129 . V_59 != V_126 )
goto V_174;
if ( F_30 ( V_125 . V_129 . V_80 [ 0 ] ) > V_175 ||
F_30 ( V_125 . V_129 . V_80 [ 1 ] ) > V_175 ||
F_30 ( V_125 . V_129 . V_80 [ 2 ] ) > V_175 ||
F_30 ( V_125 . V_129 . V_80 [ 3 ] ) > V_175 )
goto V_174;
V_134 = V_176 ;
if ( F_30 ( V_125 . V_129 . V_139 ) != V_2 -> V_91 + 1 )
goto V_174;
V_134 = V_138 ;
V_140 = F_30 ( V_125 . V_129 . V_140 ) ;
if ( V_140 > V_24 )
goto V_174;
V_2 -> V_17 = V_140 ;
V_7 = F_65 ( V_2 , & V_16 , V_169 , V_141 ) ;
if ( V_7 < 0 ) {
F_38 ( V_123 ) ;
return V_7 ;
}
F_38 ( V_123 ) ;
F_10 ( L_6 ) ;
return 0 ;
V_174:
F_38 ( V_123 ) ;
V_72:
* V_67 = V_134 ;
F_10 ( L_22 , V_134 ) ;
return - V_74 ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_2 ( L_5 ) ;
if ( V_2 -> V_27 )
F_67 ( V_2 -> V_27 ) ;
}
static int F_68 ( void )
{
V_167 = F_4 ( L_2 , 0 , V_14 ) ;
return F_69 ( V_167 ) ;
}
static void F_70 ( void )
{
if ( V_167 )
F_67 ( V_167 ) ;
}
