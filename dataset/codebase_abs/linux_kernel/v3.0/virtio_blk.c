static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
while ( ( V_8 = F_3 ( V_4 -> V_2 , & V_9 ) ) != NULL ) {
int error ;
switch ( V_8 -> V_12 ) {
case V_13 :
error = 0 ;
break;
case V_14 :
error = - V_15 ;
break;
default:
error = - V_16 ;
break;
}
switch ( V_8 -> V_17 -> V_18 ) {
case V_19 :
V_8 -> V_17 -> V_20 = V_8 -> V_21 . V_22 ;
V_8 -> V_17 -> V_23 = V_8 -> V_21 . V_23 ;
V_8 -> V_17 -> V_24 = V_8 -> V_21 . V_24 ;
break;
case V_25 :
V_8 -> V_17 -> V_24 = ( error != 0 ) ;
break;
default:
break;
}
F_4 ( V_8 -> V_17 , error ) ;
F_5 ( & V_8 -> V_26 ) ;
F_6 ( V_8 , V_4 -> V_27 ) ;
}
F_7 ( V_4 -> V_28 -> V_29 ) ;
F_8 ( & V_4 -> V_11 , V_10 ) ;
}
static bool F_9 ( struct V_30 * V_31 , struct V_3 * V_4 ,
struct V_32 * V_17 )
{
unsigned long V_33 , V_34 = 0 , V_35 = 0 ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_4 -> V_27 , V_36 ) ;
if ( ! V_8 )
return false ;
V_8 -> V_17 = V_17 ;
if ( V_17 -> V_37 & V_38 ) {
V_8 -> V_39 . type = V_40 ;
V_8 -> V_39 . V_41 = 0 ;
V_8 -> V_39 . V_42 = F_11 ( V_8 -> V_17 ) ;
} else {
switch ( V_17 -> V_18 ) {
case V_43 :
V_8 -> V_39 . type = 0 ;
V_8 -> V_39 . V_41 = F_12 ( V_8 -> V_17 ) ;
V_8 -> V_39 . V_42 = F_11 ( V_8 -> V_17 ) ;
break;
case V_19 :
V_8 -> V_39 . type = V_44 ;
V_8 -> V_39 . V_41 = 0 ;
V_8 -> V_39 . V_42 = F_11 ( V_8 -> V_17 ) ;
break;
case V_25 :
V_8 -> V_39 . type = V_45 ;
V_8 -> V_39 . V_41 = 0 ;
V_8 -> V_39 . V_42 = F_11 ( V_8 -> V_17 ) ;
break;
default:
F_13 () ;
}
}
F_14 ( & V_4 -> V_46 [ V_34 ++ ] , & V_8 -> V_39 , sizeof( V_8 -> V_39 ) ) ;
if ( V_8 -> V_17 -> V_18 == V_19 )
F_14 ( & V_4 -> V_46 [ V_34 ++ ] , V_8 -> V_17 -> V_47 , V_8 -> V_17 -> V_48 ) ;
V_33 = F_15 ( V_31 , V_8 -> V_17 , V_4 -> V_46 + V_34 ) ;
if ( V_8 -> V_17 -> V_18 == V_19 ) {
F_14 ( & V_4 -> V_46 [ V_33 + V_34 + V_35 ++ ] , V_8 -> V_17 -> V_49 , V_50 ) ;
F_14 ( & V_4 -> V_46 [ V_33 + V_34 + V_35 ++ ] , & V_8 -> V_21 ,
sizeof( V_8 -> V_21 ) ) ;
}
F_14 ( & V_4 -> V_46 [ V_33 + V_34 + V_35 ++ ] , & V_8 -> V_12 ,
sizeof( V_8 -> V_12 ) ) ;
if ( V_33 ) {
if ( F_16 ( V_8 -> V_17 ) == V_51 ) {
V_8 -> V_39 . type |= V_52 ;
V_34 += V_33 ;
} else {
V_8 -> V_39 . type |= V_53 ;
V_35 += V_33 ;
}
}
if ( F_17 ( V_4 -> V_2 , V_4 -> V_46 , V_34 , V_35 , V_8 ) < 0 ) {
F_6 ( V_8 , V_4 -> V_27 ) ;
return false ;
}
F_18 ( & V_8 -> V_26 , & V_4 -> V_54 ) ;
return true ;
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_55 ;
struct V_32 * V_17 ;
unsigned int V_56 = 0 ;
while ( ( V_17 = F_20 ( V_31 ) ) != NULL ) {
F_21 ( V_17 -> V_57 + 2 > V_4 -> V_58 ) ;
if ( ! F_9 ( V_31 , V_4 , V_17 ) ) {
F_22 ( V_31 ) ;
break;
}
F_23 ( V_17 ) ;
V_56 ++ ;
}
if ( V_56 )
F_24 ( V_4 -> V_2 ) ;
}
static int F_25 ( struct V_59 * V_28 , char * V_60 )
{
struct V_3 * V_4 = V_28 -> V_61 ;
struct V_32 * V_17 ;
struct V_62 * V_62 ;
int V_63 ;
V_62 = F_26 ( V_4 -> V_28 -> V_29 , V_60 , V_64 ,
V_65 ) ;
if ( F_27 ( V_62 ) )
return F_28 ( V_62 ) ;
V_17 = F_29 ( V_4 -> V_28 -> V_29 , V_62 , V_65 ) ;
if ( F_27 ( V_17 ) ) {
F_30 ( V_62 ) ;
return F_28 ( V_17 ) ;
}
V_17 -> V_18 = V_25 ;
V_63 = F_31 ( V_4 -> V_28 -> V_29 , V_4 -> V_28 , V_17 , false ) ;
F_32 ( V_17 ) ;
return V_63 ;
}
static int F_33 ( struct V_66 * V_67 , T_1 V_68 ,
unsigned int V_47 , unsigned long V_69 )
{
struct V_59 * V_28 = V_67 -> V_70 ;
struct V_3 * V_4 = V_28 -> V_61 ;
if ( ! F_34 ( V_4 -> V_5 , V_71 ) )
return - V_15 ;
return F_35 ( V_28 -> V_29 , V_28 , V_68 , V_47 ,
( void V_72 * ) V_69 ) ;
}
static int F_36 ( struct V_66 * V_73 , struct V_74 * V_75 )
{
struct V_3 * V_4 = V_73 -> V_70 -> V_61 ;
struct V_76 V_77 ;
int V_63 ;
V_63 = F_37 ( V_4 -> V_5 , V_78 ,
F_38 ( struct V_79 , V_80 ) ,
& V_77 ) ;
if ( ! V_63 ) {
V_75 -> V_81 = V_77 . V_81 ;
V_75 -> V_82 = V_77 . V_82 ;
V_75 -> V_83 = V_77 . V_83 ;
} else {
V_75 -> V_81 = 1 << 6 ;
V_75 -> V_82 = 1 << 5 ;
V_75 -> V_83 = F_39 ( V_73 -> V_70 ) >> 11 ;
}
return 0 ;
}
static int F_40 ( int V_84 )
{
return V_84 << V_85 ;
}
static T_2 F_41 ( struct V_86 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_59 * V_28 = F_42 ( V_87 ) ;
int V_63 ;
F_43 ( V_91 < V_64 ) ;
V_90 [ V_64 ] = '\0' ;
V_63 = F_25 ( V_28 , V_90 ) ;
if ( ! V_63 )
return strlen ( V_90 ) ;
if ( V_63 == - V_16 )
return 0 ;
return V_63 ;
}
static void F_44 ( struct V_92 * V_93 )
{
struct V_3 * V_4 =
F_45 ( V_93 , struct V_3 , V_94 ) ;
struct V_95 * V_5 = V_4 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_28 -> V_29 ;
char V_96 [ 10 ] , V_97 [ 10 ] ;
T_3 V_98 , V_99 ;
V_5 -> V_100 -> V_101 ( V_5 , F_38 ( struct V_79 , V_98 ) ,
& V_98 , sizeof( V_98 ) ) ;
if ( ( V_102 ) V_98 != V_98 ) {
F_46 ( & V_5 -> V_87 , L_1 ,
( unsigned long long ) V_98 ) ;
V_98 = ( V_102 ) - 1 ;
}
V_99 = V_98 * F_47 ( V_31 ) ;
F_48 ( V_99 , V_103 , V_96 , sizeof( V_96 ) ) ;
F_48 ( V_99 , V_104 , V_97 , sizeof( V_97 ) ) ;
F_49 ( & V_5 -> V_87 ,
L_2 ,
( unsigned long long ) V_98 ,
F_47 ( V_31 ) ,
V_97 , V_96 ) ;
F_50 ( V_4 -> V_28 , V_98 ) ;
}
static void F_51 ( struct V_95 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_52 ( V_105 , & V_4 -> V_94 ) ;
}
static int T_4 F_53 ( struct V_95 * V_5 )
{
struct V_3 * V_4 ;
struct V_30 * V_31 ;
int V_63 ;
T_3 V_106 ;
T_5 V_107 , V_108 , V_58 , V_109 ;
T_6 V_110 ;
T_7 V_111 , V_112 ;
if ( F_40 ( V_84 ) >= 1 << V_113 )
return - V_114 ;
V_63 = F_37 ( V_5 , V_115 ,
F_38 ( struct V_79 , V_116 ) ,
& V_58 ) ;
if ( V_63 || ! V_58 )
V_58 = 1 ;
V_58 += 2 ;
V_5 -> V_6 = V_4 = F_54 ( sizeof( * V_4 ) +
sizeof( V_4 -> V_46 [ 0 ] ) * V_58 , V_65 ) ;
if ( ! V_4 ) {
V_63 = - V_117 ;
goto V_34;
}
F_55 ( & V_4 -> V_54 ) ;
F_56 ( & V_4 -> V_11 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_58 = V_58 ;
F_57 ( V_4 -> V_46 , V_4 -> V_58 ) ;
F_58 ( & V_4 -> V_94 , F_44 ) ;
V_4 -> V_2 = F_59 ( V_5 , F_1 , L_3 ) ;
if ( F_27 ( V_4 -> V_2 ) ) {
V_63 = F_28 ( V_4 -> V_2 ) ;
goto V_118;
}
V_4 -> V_27 = F_60 ( 1 , sizeof( struct V_7 ) ) ;
if ( ! V_4 -> V_27 ) {
V_63 = - V_117 ;
goto V_119;
}
V_4 -> V_28 = F_61 ( 1 << V_85 ) ;
if ( ! V_4 -> V_28 ) {
V_63 = - V_117 ;
goto V_120;
}
V_31 = V_4 -> V_28 -> V_29 = F_62 ( F_19 , & V_4 -> V_11 ) ;
if ( ! V_31 ) {
V_63 = - V_117 ;
goto V_121;
}
V_31 -> V_55 = V_4 ;
if ( V_84 < 26 ) {
sprintf ( V_4 -> V_28 -> V_122 , L_4 , 'a' + V_84 % 26 ) ;
} else if ( V_84 < ( 26 + 1 ) * 26 ) {
sprintf ( V_4 -> V_28 -> V_122 , L_5 ,
'a' + V_84 / 26 - 1 , 'a' + V_84 % 26 ) ;
} else {
const unsigned int V_123 = ( V_84 / 26 - 1 ) / 26 - 1 ;
const unsigned int V_124 = ( V_84 / 26 - 1 ) % 26 ;
const unsigned int V_125 = V_84 % 26 ;
sprintf ( V_4 -> V_28 -> V_122 , L_6 ,
'a' + V_123 , 'a' + V_124 , 'a' + V_125 ) ;
}
V_4 -> V_28 -> V_126 = V_126 ;
V_4 -> V_28 -> V_127 = F_40 ( V_84 ) ;
V_4 -> V_28 -> V_61 = V_4 ;
V_4 -> V_28 -> V_128 = & V_129 ;
V_4 -> V_28 -> V_130 = & V_5 -> V_87 ;
V_84 ++ ;
if ( F_34 ( V_5 , V_131 ) )
F_63 ( V_31 , V_38 ) ;
if ( F_34 ( V_5 , V_132 ) )
F_64 ( V_4 -> V_28 , 1 ) ;
V_5 -> V_100 -> V_101 ( V_5 , F_38 ( struct V_79 , V_98 ) ,
& V_106 , sizeof( V_106 ) ) ;
if ( ( V_102 ) V_106 != V_106 ) {
F_46 ( & V_5 -> V_87 , L_1 ,
( unsigned long long ) V_106 ) ;
V_106 = ( V_102 ) - 1 ;
}
F_50 ( V_4 -> V_28 , V_106 ) ;
F_65 ( V_31 , V_4 -> V_58 - 2 ) ;
F_66 ( V_31 , V_133 ) ;
F_67 ( V_31 , - 1U ) ;
V_63 = F_37 ( V_5 , V_134 ,
F_38 ( struct V_79 , V_135 ) ,
& V_107 ) ;
if ( ! V_63 )
F_68 ( V_31 , V_107 ) ;
else
F_68 ( V_31 , - 1U ) ;
V_63 = F_37 ( V_5 , V_136 ,
F_38 ( struct V_79 , V_108 ) ,
& V_108 ) ;
if ( ! V_63 )
F_69 ( V_31 , V_108 ) ;
else
V_108 = F_47 ( V_31 ) ;
V_63 = F_37 ( V_5 , V_137 ,
F_38 ( struct V_79 , V_111 ) ,
& V_111 ) ;
if ( ! V_63 && V_111 )
F_70 ( V_31 ,
V_108 * ( 1 << V_111 ) ) ;
V_63 = F_37 ( V_5 , V_137 ,
F_38 ( struct V_79 , V_112 ) ,
& V_112 ) ;
if ( ! V_63 && V_112 )
F_71 ( V_31 , V_108 * V_112 ) ;
V_63 = F_37 ( V_5 , V_137 ,
F_38 ( struct V_79 , V_110 ) ,
& V_110 ) ;
if ( ! V_63 && V_110 )
F_72 ( V_31 , V_108 * V_110 ) ;
V_63 = F_37 ( V_5 , V_137 ,
F_38 ( struct V_79 , V_109 ) ,
& V_109 ) ;
if ( ! V_63 && V_109 )
F_73 ( V_31 , V_108 * V_109 ) ;
F_74 ( V_4 -> V_28 ) ;
V_63 = F_75 ( F_76 ( V_4 -> V_28 ) , & V_138 ) ;
if ( V_63 )
goto V_139;
return 0 ;
V_139:
F_77 ( V_4 -> V_28 ) ;
F_78 ( V_4 -> V_28 -> V_29 ) ;
V_121:
F_79 ( V_4 -> V_28 ) ;
V_120:
F_80 ( V_4 -> V_27 ) ;
V_119:
V_5 -> V_100 -> V_140 ( V_5 ) ;
V_118:
F_81 ( V_4 ) ;
V_34:
return V_63 ;
}
static void T_8 F_82 ( struct V_95 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_83 ( & V_4 -> V_94 ) ;
F_21 ( ! F_84 ( & V_4 -> V_54 ) ) ;
V_5 -> V_100 -> V_141 ( V_5 ) ;
F_77 ( V_4 -> V_28 ) ;
F_78 ( V_4 -> V_28 -> V_29 ) ;
F_79 ( V_4 -> V_28 ) ;
F_80 ( V_4 -> V_27 ) ;
V_5 -> V_100 -> V_140 ( V_5 ) ;
F_81 ( V_4 ) ;
}
static int T_9 F_85 ( void )
{
int error ;
V_105 = F_86 ( L_7 , 0 , 0 ) ;
if ( ! V_105 )
return - V_117 ;
V_126 = F_87 ( 0 , L_8 ) ;
if ( V_126 < 0 ) {
error = V_126 ;
goto V_142;
}
error = F_88 ( & V_3 ) ;
if ( error )
goto V_143;
return 0 ;
V_143:
F_89 ( V_126 , L_8 ) ;
V_142:
F_90 ( V_105 ) ;
return error ;
}
static void T_10 F_91 ( void )
{
F_89 ( V_126 , L_8 ) ;
F_92 ( & V_3 ) ;
F_90 ( V_105 ) ;
}
