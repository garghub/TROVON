static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_5 V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
union V_10 * V_10 ;
int V_11 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
V_9 = F_4 ( V_7 ) ;
V_10 = & V_9 -> V_10 ;
V_11 = F_5 ( V_7 -> V_14 , & V_5 ) ;
F_6 ( V_15 L_1
L_2 , F_7 () ) ;
F_6 ( V_15 L_3 ) ;
F_8 ( V_15 , L_4 , V_16 , 16 , 1 ,
V_10 , sizeof( * V_10 ) , 0 ) ;
F_6 ( V_15 L_5 ,
F_9 ( & V_4 -> V_12 ) ) ;
F_6 ( V_15 L_6 ,
F_9 ( & V_7 -> V_12 ) ) ;
F_6 ( V_15 L_7
L_8 , V_7 -> V_17 , V_7 -> V_18 , V_7 -> V_19 ) ;
if ( V_10 -> V_20 . V_21 ) {
F_6 ( V_15 L_9 ) ;
F_6 ( V_15 L_10 ) ;
F_8 ( V_15 , L_4 , V_16 , 16 , 1 ,
( void * ) ( V_22 ) V_10 -> V_20 . V_23 ,
sizeof( struct V_23 ) , 0 ) ;
} else {
F_6 ( V_15 L_11 ) ;
if ( ( void * ) ( V_22 ) V_10 -> V_24 . V_25 == & V_9 -> V_26 ||
( void * ) ( V_22 ) V_10 -> V_24 . V_25 == V_4 -> V_9 -> V_27 )
F_6 ( V_15 L_12
L_13 ) ;
else
F_6 ( V_15 L_14 ) ;
F_8 ( V_15 , L_4 , V_16 , 16 , 1 ,
( void * ) ( V_22 ) V_10 -> V_24 . V_25 ,
sizeof( struct V_28 ) , 0 ) ;
}
F_6 ( V_15 L_15 ,
V_4 -> V_9 -> V_29 ) ;
F_6 ( V_15 L_16 , V_11 ) ;
F_6 ( V_15 L_17 ) ;
F_8 ( V_15 , L_4 , V_16 , 16 , 1 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
F_6 ( V_15 L_18 ) ;
F_8 ( V_15 , L_4 , V_16 , 16 , 1 ,
& V_4 -> V_9 -> V_30 , sizeof( V_4 -> V_9 -> V_30 ) , 0 ) ;
}
static void
F_10 ( unsigned long V_31 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) V_31 ;
F_11 ( V_4 -> V_32 ) ;
if ( V_2 )
F_2 ( V_4 ) ;
F_12 ( V_4 , V_33 ) ;
F_13 ( V_4 -> V_32 ) ;
}
void
F_14 ( struct V_3 * V_4 , int V_34 )
{
if ( V_34 == 0 ) {
F_15 ( & V_4 -> V_9 -> V_35 ) ;
return;
}
if ( F_16 ( & V_4 -> V_9 -> V_35 ) ) {
if ( F_17 ( & V_4 -> V_9 -> V_35 , V_36 + V_34 ) )
return;
}
V_4 -> V_9 -> V_35 . V_37 = F_10 ;
V_4 -> V_9 -> V_35 . V_31 = ( unsigned long ) V_4 ;
V_4 -> V_9 -> V_35 . V_34 = V_36 + V_34 ;
F_18 ( & V_4 -> V_9 -> V_35 ) ;
}
int
F_19 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_38 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_20 ( V_7 ) )
return - V_39 ;
if ( ! V_7 -> V_5 . V_40 . V_41 )
return 0 ;
if ( ! ( F_21 ( & V_7 -> V_5 . V_42 ) & V_43 ) &&
! ( F_21 ( & V_7 -> V_5 . V_42 ) & V_44 ) ) {
if ( ! F_22 ( & V_7 -> V_5 . V_42 ) ) {
V_38 = F_23 ( V_7 ) ;
if ( V_38 != - V_45 )
return V_38 ;
}
V_4 -> V_9 -> V_46 = 3 ;
}
if ( ! ( F_21 ( & V_7 -> V_5 . V_42 ) & V_44 ) ) {
if ( V_4 -> V_9 -> V_46 ) {
V_4 -> V_9 -> V_46 -- ;
V_38 = F_24 ( V_7 ) ;
if ( V_38 != - V_47 )
return ( V_38 == 0 ) ? - V_47 : V_38 ;
}
V_4 -> V_9 -> V_46 = 255 ;
}
if ( V_4 -> V_9 -> V_46 ) {
V_4 -> V_9 -> V_46 -- ;
V_38 = F_25 ( V_7 ) ;
return ( V_38 == 0 ) ? - V_47 : V_38 ;
}
F_26 ( 0 , L_19 ,
V_4 -> V_9 -> V_48 . V_49 , V_4 -> V_9 -> V_48 . V_50 ) ;
return - V_51 ;
}
void F_27 ( struct V_3 * V_4 )
{
memset ( & V_4 -> V_52 , 0 , sizeof( V_4 -> V_52 ) ) ;
V_4 -> V_52 . V_53 = V_4 -> V_9 -> V_54 . V_53 ;
V_4 -> V_52 . V_55 = V_4 -> V_9 -> V_54 . V_55 ;
V_4 -> V_52 . V_56 = V_4 -> V_9 -> V_54 . V_56 ;
V_4 -> V_52 . V_57 = V_4 -> V_9 -> V_54 . V_57 ;
}
int F_28 ( struct V_3 * V_4 )
{
return V_4 -> V_52 . V_53 == V_4 -> V_9 -> V_54 . V_53 &&
V_4 -> V_52 . V_55 == V_4 -> V_9 -> V_54 . V_55 &&
V_4 -> V_52 . V_56 == V_4 -> V_9 -> V_54 . V_56 &&
V_4 -> V_52 . V_57 == V_4 -> V_9 -> V_54 . V_57 ;
}
static void
F_29 ( struct V_6 * V_7 , int V_58 )
{
int V_59 , V_60 ;
struct V_61 V_62 ;
F_30 ( & V_62 ) ;
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ ) {
V_59 = 0x80 >> V_60 ;
if ( ! ( V_7 -> V_17 & V_59 ) )
continue;
if ( V_58 & V_59 )
continue;
V_62 . V_52 = V_7 -> V_5 . V_40 . V_62 [ V_60 ] ;
if ( ! F_31 ( V_62 ) )
F_32 () ;
}
}
static void
F_33 ( struct V_3 * V_4 , int V_29 )
{
struct V_6 * V_7 ;
int V_58 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_34 ( V_7 ) )
V_29 = V_63 ;
V_58 = V_7 -> V_17 ;
if ( F_20 ( V_7 ) )
V_29 = V_63 ;
else
V_7 -> V_17 = V_7 -> V_5 . V_40 . V_64 & V_7 -> V_18 ;
if ( V_4 -> V_9 -> V_29 == V_65 )
V_58 = 0 ;
if ( V_7 -> V_17 != V_58 )
F_29 ( V_7 , V_58 ) ;
if ( V_4 -> V_9 -> V_29 == V_65 &&
( V_29 == V_63 || V_29 == V_66 ) ) {
V_4 -> V_9 -> V_30 . V_67 = 1 ;
V_4 -> V_9 -> V_29 = V_68 ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
return;
}
if ( V_4 -> V_9 -> V_30 . V_70 ) {
V_4 -> V_9 -> V_29 = V_29 ;
V_4 -> V_9 -> V_30 . V_67 = 1 ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
return;
}
switch ( V_29 ) {
case V_63 :
break;
case V_71 :
if ( ! V_4 -> V_72 ) {
F_27 ( V_4 ) ;
break;
}
V_4 -> V_9 -> V_29 = V_71 ;
V_4 -> V_9 -> V_30 . V_67 = 1 ;
if ( F_28 ( V_4 ) ) {
V_4 -> V_9 -> V_30 . V_73 = 1 ;
F_36 ( V_4 ) ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
} else {
F_27 ( V_4 ) ;
F_37 ( V_4 , V_74 ) ;
}
return;
case V_66 :
if ( V_4 -> V_52 . V_53 != 0 ) {
V_4 -> V_9 -> V_30 . V_67 = 1 ;
V_4 -> V_9 -> V_29 = V_66 ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
return;
}
break;
}
V_4 -> V_9 -> V_29 = V_29 ;
F_38 ( V_4 ) ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
}
void
F_39 ( struct V_3 * V_4 , int V_75 )
{
switch ( V_75 ) {
case 0 :
F_33 ( V_4 , V_71 ) ;
break;
case - V_76 :
F_33 ( V_4 , V_66 ) ;
break;
default:
F_33 ( V_4 , V_63 ) ;
break;
}
}
int F_40 ( struct V_3 * V_4 , int V_77 )
{
int V_38 = - V_45 ;
if ( ! V_4 -> V_78 )
goto V_79;
if ( ! V_4 -> V_72 )
goto V_79;
F_26 ( 2 , L_20 ,
V_4 -> V_9 -> V_48 . V_49 , V_4 -> V_9 -> V_48 . V_50 ,
V_77 ) ;
if ( ! V_4 -> V_78 -> V_80 ) {
V_38 = - V_81 ;
goto V_79;
}
if ( V_4 -> V_78 -> V_80 ( V_4 , V_77 ) )
V_38 = V_82 ;
else
V_38 = V_83 ;
V_79:
return V_38 ;
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_40 ( V_4 , V_84 ) == V_82 ) {
F_37 ( V_4 , V_85 ) ;
V_4 -> V_9 -> V_86 = V_7 -> V_19 ;
return;
}
F_42 ( V_4 ) ;
F_37 ( V_4 , V_74 ) ;
}
static void
F_43 ( struct V_3 * V_4 , int V_29 )
{
struct V_6 * V_7 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
F_14 ( V_4 , 0 ) ;
if ( V_29 != V_87 )
F_34 ( V_7 ) ;
memset ( & V_4 -> V_9 -> V_88 , 0 , sizeof( struct V_88 ) ) ;
V_4 -> V_9 -> V_29 = V_29 ;
switch ( V_29 ) {
case V_66 :
F_26 ( 0 , L_21 ,
V_4 -> V_9 -> V_48 . V_50 , V_7 -> V_14 . V_89 ) ;
if ( V_4 -> V_72 &&
F_40 ( V_4 , V_90 ) != V_82 )
F_37 ( V_4 , V_91 ) ;
V_4 -> V_9 -> V_30 . V_73 = 0 ;
break;
case V_63 :
F_26 ( 0 , L_22 ,
V_4 -> V_9 -> V_48 . V_50 , V_7 -> V_14 . V_89 ) ;
if ( F_40 ( V_4 , V_92 ) != V_82 )
F_37 ( V_4 , V_91 ) ;
else
F_44 ( V_4 ) ;
V_4 -> V_9 -> V_30 . V_73 = 0 ;
break;
case V_68 :
F_26 ( 0 , L_23
L_24 , V_4 -> V_9 -> V_48 . V_50 ,
V_7 -> V_14 . V_89 ) ;
if ( F_40 ( V_4 , V_93 ) != V_82 ) {
V_4 -> V_9 -> V_29 = V_63 ;
F_37 ( V_4 , V_91 ) ;
} else
F_44 ( V_4 ) ;
V_4 -> V_9 -> V_30 . V_73 = 0 ;
break;
default:
break;
}
if ( V_4 -> V_9 -> V_30 . V_73 ) {
V_4 -> V_9 -> V_30 . V_73 = 0 ;
F_41 ( V_4 ) ;
}
F_35 ( & V_4 -> V_9 -> V_69 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
V_4 -> V_9 -> V_30 . V_67 = 0 ;
V_4 -> V_9 -> V_29 = V_94 ;
if ( F_46 ( V_7 , ( V_95 ) ( V_22 ) V_7 ) ) {
F_33 ( V_4 , V_63 ) ;
return;
}
F_47 ( V_4 ) ;
}
static void F_48 ( struct V_3 * V_4 , enum V_96 V_97 )
{
switch ( V_97 ) {
case V_98 :
F_49 ( V_4 ) ;
break;
case V_99 :
F_50 ( V_4 ) ;
break;
case V_33 :
F_51 ( V_4 ) ;
break;
default:
break;
}
}
static void F_52 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
int V_100 [ 8 ] ;
int V_101 , V_59 ;
for ( V_101 = 0 , V_59 = 0x80 ; V_101 < 8 ; V_101 ++ , V_59 >>= 1 ) {
V_100 [ V_101 ] = V_102 ;
if ( V_59 & V_4 -> V_9 -> V_103 & ~ ( V_7 -> V_19 ) )
V_100 [ V_101 ] |= V_104 ;
if ( V_59 & V_4 -> V_9 -> V_86 & V_7 -> V_19 )
V_100 [ V_101 ] |= V_105 ;
if ( V_59 & V_4 -> V_9 -> V_106 & V_7 -> V_19 )
V_100 [ V_101 ] |= V_107 ;
}
if ( V_4 -> V_72 && V_4 -> V_78 -> V_100 )
V_4 -> V_78 -> V_100 ( V_4 , V_100 ) ;
}
static void F_53 ( struct V_3 * V_4 )
{
V_4 -> V_9 -> V_103 = 0 ;
V_4 -> V_9 -> V_86 = 0 ;
V_4 -> V_9 -> V_106 = 0 ;
}
static void F_54 ( struct V_88 * V_88 , int type )
{
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
if ( type == V_108 ) {
struct V_109 * V_42 = & V_88 -> V_42 . V_24 ;
V_42 -> V_11 = 1 ;
V_42 -> V_110 = V_111 ;
V_42 -> V_112 = V_113 ;
V_42 -> V_114 = V_115 ;
} else if ( type == V_116 ) {
struct V_117 * V_42 = & V_88 -> V_42 . V_20 ;
V_42 -> V_118 = 1 ;
V_42 -> V_11 = 1 ;
V_42 -> V_110 = V_111 ;
V_42 -> V_112 = V_113 ;
V_42 -> V_114 = V_115 ;
}
}
void F_55 ( struct V_3 * V_4 , int V_75 )
{
struct V_6 * V_7 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_20 ( V_7 ) ) {
V_75 = - V_39 ;
goto V_119;
}
V_7 -> V_17 = V_7 -> V_19 ;
if ( V_4 -> V_9 -> V_30 . V_120 ) {
F_56 ( V_4 ) ;
return;
}
V_119:
switch ( V_75 ) {
case 0 :
F_43 ( V_4 , V_87 ) ;
if ( V_4 -> V_9 -> V_30 . V_121 ) {
F_54 ( & V_4 -> V_9 -> V_88 ,
V_4 -> V_9 -> V_30 . V_121 ) ;
V_4 -> V_9 -> V_30 . V_121 = 0 ;
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , V_4 -> V_9 -> V_123 ,
& V_4 -> V_9 -> V_88 ) ;
memset ( & V_4 -> V_9 -> V_88 , 0 , sizeof( struct V_88 ) ) ;
}
F_52 ( V_4 ) ;
break;
case - V_76 :
case - V_124 :
V_4 -> V_9 -> V_30 . V_73 = 0 ;
F_43 ( V_4 , V_66 ) ;
break;
case - V_125 :
V_4 -> V_9 -> V_30 . V_73 = 0 ;
F_43 ( V_4 , V_68 ) ;
break;
default:
V_4 -> V_9 -> V_30 . V_73 = 0 ;
F_43 ( V_4 , V_63 ) ;
break;
}
F_53 ( V_4 ) ;
}
int
F_36 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_38 ;
if ( ( V_4 -> V_9 -> V_29 != V_71 ) &&
( V_4 -> V_9 -> V_29 != V_66 ) )
return - V_45 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
V_38 = F_46 ( V_7 , ( V_95 ) ( V_22 ) V_7 ) ;
if ( V_38 != 0 ) {
if ( V_38 == - V_39 )
F_12 ( V_4 , V_98 ) ;
return V_38 ;
}
V_4 -> V_9 -> V_29 = V_126 ;
F_56 ( V_4 ) ;
return 0 ;
}
void
F_57 ( struct V_3 * V_4 , int V_75 )
{
switch ( V_75 ) {
case 0 :
F_43 ( V_4 , V_71 ) ;
break;
case - V_76 :
F_43 ( V_4 , V_66 ) ;
break;
default:
V_4 -> V_9 -> V_30 . V_73 = 0 ;
F_43 ( V_4 , V_63 ) ;
break;
}
}
int
F_58 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
if ( V_4 -> V_9 -> V_29 == V_68 ||
V_4 -> V_9 -> V_29 == V_63 ) {
V_4 -> V_9 -> V_30 . V_73 = 0 ;
F_43 ( V_4 , V_63 ) ;
return 0 ;
}
if ( V_4 -> V_9 -> V_29 == V_66 ) {
F_43 ( V_4 , V_66 ) ;
return 0 ;
}
if ( F_59 ( V_4 ) ) {
F_43 ( V_4 , V_71 ) ;
return 0 ;
}
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_20 ( V_7 ) )
return - V_39 ;
if ( F_21 ( & V_7 -> V_5 . V_42 ) != 0 )
return - V_47 ;
if ( V_4 -> V_9 -> V_29 != V_87 )
return - V_45 ;
if ( ! V_4 -> V_9 -> V_30 . V_127 ) {
F_43 ( V_4 , V_71 ) ;
return 0 ;
}
V_4 -> V_9 -> V_29 = V_128 ;
F_60 ( V_4 ) ;
return 0 ;
}
static void F_61 ( struct V_3 * V_4 ,
enum V_96 V_96 )
{
if ( F_40 ( V_4 , V_92 ) != V_82 )
F_37 ( V_4 , V_91 ) ;
else
F_44 ( V_4 ) ;
}
static void F_62 ( struct V_3 * V_4 ,
enum V_96 V_96 )
{
struct V_6 * V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
F_63 ( V_7 -> V_14 ) ;
}
static void
F_64 ( struct V_3 * V_4 , enum V_96 V_96 )
{
struct V_6 * V_7 ;
if ( V_4 -> V_9 -> V_29 == V_129 ) {
V_4 -> V_9 -> V_30 . V_120 = 1 ;
return;
}
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_20 ( V_7 ) ) {
F_55 ( V_4 , - V_39 ) ;
return;
}
if ( F_21 ( & V_7 -> V_5 . V_42 ) != 0 ||
( F_65 ( & V_7 -> V_5 . V_42 ) & V_115 ) ||
( F_65 ( & V_4 -> V_9 -> V_88 . V_42 ) & V_115 ) ) {
V_4 -> V_9 -> V_30 . V_120 = 1 ;
return;
}
V_4 -> V_9 -> V_29 = V_126 ;
F_56 ( V_4 ) ;
}
static void F_66 ( struct V_3 * V_4 ,
enum V_96 V_96 )
{
struct V_6 * V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( V_4 -> V_72 ) {
if ( F_46 ( V_7 , ( V_95 ) ( V_22 ) V_7 ) )
F_43 ( V_4 , V_63 ) ;
else
F_64 ( V_4 , V_96 ) ;
} else
F_63 ( V_7 -> V_14 ) ;
}
static void
F_67 ( struct V_3 * V_4 , enum V_96 V_96 )
{
struct V_88 * V_88 ;
int V_130 ;
V_88 = F_68 ( & V_131 ) ;
V_130 = ! F_22 ( & V_88 -> V_42 ) ;
if ( ! F_69 ( & V_88 -> V_42 ) ) {
if ( V_130 && ( V_88 -> V_42 . V_24 . V_132 & V_133 ) &&
! V_88 -> V_134 . V_135 . V_136 . V_137 ) {
if ( F_70 ( V_4 , V_88 ) != 0 )
goto V_138;
memcpy ( & V_4 -> V_9 -> V_88 , V_88 , sizeof( struct V_88 ) ) ;
V_4 -> V_9 -> V_29 = V_129 ;
V_4 -> V_9 -> V_123 = 0 ;
return;
}
V_138:
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , 0 , V_88 ) ;
if ( V_4 -> V_9 -> V_30 . V_120 )
F_64 ( V_4 , 0 ) ;
return;
}
F_71 ( V_4 , V_88 ) ;
if ( V_130 && V_4 -> V_9 -> V_30 . V_139 ) {
if ( F_70 ( V_4 , V_88 ) == 0 ) {
V_4 -> V_9 -> V_29 = V_129 ;
}
return;
}
if ( F_72 ( V_4 ) && V_4 -> V_9 -> V_30 . V_120 )
F_64 ( V_4 , 0 ) ;
}
static void
F_73 ( struct V_3 * V_4 , enum V_96 V_96 )
{
int V_38 ;
F_14 ( V_4 , 0 ) ;
V_4 -> V_9 -> V_46 = 255 ;
V_38 = F_19 ( V_4 ) ;
if ( V_38 == - V_47 ) {
F_14 ( V_4 , 3 * V_140 ) ;
V_4 -> V_9 -> V_29 = V_141 ;
return;
}
if ( V_38 )
F_12 ( V_4 , V_98 ) ;
else if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , V_4 -> V_9 -> V_123 ,
F_74 ( - V_142 ) ) ;
}
static void
F_75 ( struct V_3 * V_4 , enum V_96 V_96 )
{
struct V_88 * V_88 ;
V_88 = F_68 ( & V_131 ) ;
if ( F_65 ( & V_88 -> V_42 ) ==
( V_115 | V_143 ) ) {
if ( F_76 ( & V_88 -> V_42 ) == 1 )
F_70 ( V_4 , V_88 ) ;
else {
F_26 ( 0 , L_25
L_26 ,
V_4 -> V_9 -> V_48 . V_49 ,
V_4 -> V_9 -> V_48 . V_50 ) ;
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , 0 , V_88 ) ;
}
return;
}
if ( F_77 ( & V_88 -> V_42 ) &
( V_144 | V_145 ) ) {
V_4 -> V_9 -> V_30 . V_139 = 0 ;
memset ( & V_4 -> V_9 -> V_88 , 0 , sizeof( struct V_88 ) ) ;
F_71 ( V_4 , V_88 ) ;
goto V_146;
}
F_78 ( V_4 , V_88 ) ;
if ( V_4 -> V_9 -> V_30 . V_139 ) {
F_70 ( V_4 , V_88 ) ;
return;
}
V_146:
V_4 -> V_9 -> V_29 = V_87 ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
if ( F_72 ( V_4 ) && V_4 -> V_9 -> V_30 . V_120 )
F_64 ( V_4 , 0 ) ;
}
static void
F_79 ( struct V_3 * V_4 , enum V_96 V_96 )
{
F_14 ( V_4 , 0 ) ;
F_64 ( V_4 , 0 ) ;
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , V_4 -> V_9 -> V_123 ,
F_74 ( - V_51 ) ) ;
}
static void
F_80 ( struct V_3 * V_4 , enum V_96 V_96 )
{
int V_38 ;
V_38 = F_19 ( V_4 ) ;
if ( V_38 == - V_47 ) {
F_14 ( V_4 , 3 * V_140 ) ;
return;
}
F_64 ( V_4 , 0 ) ;
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , V_4 -> V_9 -> V_123 ,
F_74 ( - V_51 ) ) ;
}
void F_81 ( struct V_3 * V_4 )
{
int V_38 ;
V_4 -> V_9 -> V_46 = 255 ;
V_38 = F_19 ( V_4 ) ;
if ( V_38 == - V_47 ) {
F_14 ( V_4 , 3 * V_140 ) ;
V_4 -> V_9 -> V_29 = V_141 ;
return;
}
F_64 ( V_4 , 0 ) ;
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_4 , V_4 -> V_9 -> V_123 ,
F_74 ( - V_51 ) ) ;
}
static void
F_82 ( struct V_3 * V_4 , enum V_96 V_96 )
{
V_4 -> V_9 -> V_30 . V_120 = 1 ;
}
static void
F_83 ( struct V_3 * V_4 , enum V_96 V_96 )
{
struct V_6 * V_7 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_46 ( V_7 , ( V_95 ) ( V_22 ) V_7 ) != 0 )
return;
V_4 -> V_9 -> V_29 = V_65 ;
F_47 ( V_4 ) ;
}
void F_84 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
if ( V_4 -> V_9 -> V_29 != V_68 )
return;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
if ( F_20 ( V_7 ) )
return;
V_7 -> V_17 = V_7 -> V_5 . V_40 . V_64 & V_7 -> V_18 ;
F_85 ( V_7 ) ;
if ( F_86 ( V_7 ) )
return;
if ( V_7 -> V_5 . V_40 . V_12 != V_4 -> V_9 -> V_48 . V_50 )
F_63 ( V_7 -> V_14 ) ;
else
F_83 ( V_4 , 0 ) ;
}
static void F_87 ( struct V_3 * V_4 ,
enum V_96 V_96 )
{
struct V_6 * V_7 ;
V_7 = F_3 ( V_4 -> V_12 . V_13 ) ;
F_34 ( V_7 ) ;
}
static void
F_88 ( struct V_3 * V_4 , enum V_96 V_96 )
{
F_89 ( V_4 ) ;
V_4 -> V_9 -> V_29 = V_87 ;
F_12 ( V_4 , V_96 ) ;
}
static void F_90 ( struct V_3 * V_4 ,
enum V_96 V_96 )
{
F_91 ( V_4 ) ;
V_4 -> V_9 -> V_29 = V_87 ;
F_12 ( V_4 , V_96 ) ;
}
static void
F_92 ( struct V_3 * V_4 , enum V_96 V_96 )
{
F_14 ( V_4 , 0 ) ;
V_4 -> V_9 -> V_29 = V_63 ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
}
static void
F_93 ( struct V_3 * V_4 , enum V_96 V_96 )
{
int V_38 ;
V_38 = F_19 ( V_4 ) ;
if ( V_38 == - V_47 ) {
F_14 ( V_4 , V_140 / 10 ) ;
} else {
V_4 -> V_9 -> V_29 = V_63 ;
F_35 ( & V_4 -> V_9 -> V_69 ) ;
}
}
static void
F_94 ( struct V_3 * V_4 , enum V_96 V_96 )
{
}
