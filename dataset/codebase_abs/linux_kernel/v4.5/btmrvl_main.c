void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = V_5 ;
V_2 -> V_3 -> V_6 = 0 ;
V_2 -> V_3 -> V_7 ++ ;
if ( V_2 -> V_3 -> V_8 == V_9 ) {
F_2 ( L_1 ) ;
V_2 -> V_3 -> V_8 = V_10 ;
}
F_3 ( & V_2 -> V_11 . V_12 ) ;
}
bool F_4 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = ( void * ) V_14 -> V_17 ;
if ( V_16 -> V_18 == V_19 ) {
struct V_20 * V_21 ;
T_1 V_22 ;
V_21 = ( void * ) ( V_14 -> V_17 + V_23 ) ;
V_22 = F_5 ( V_21 -> V_22 ) ;
if ( V_2 -> V_24 . V_25 ) {
V_2 -> V_24 . V_25 = false ;
V_2 -> V_3 -> V_26 = true ;
F_3 ( & V_2 -> V_3 -> V_27 ) ;
if ( F_6 ( V_22 ) == 0x3F ) {
F_2 ( L_2 ,
V_22 ) ;
F_7 ( V_14 ) ;
return false ;
}
}
}
return true ;
}
int F_8 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_28 * V_3 = V_2 -> V_3 ;
struct V_29 * V_30 ;
int V_31 = 0 ;
V_30 = (struct V_29 * ) V_14 -> V_17 ;
if ( V_30 -> V_21 != 0xff ) {
F_2 ( L_3 , V_30 -> V_21 ) ;
V_31 = - V_32 ;
goto exit;
}
switch ( V_30 -> V_17 [ 0 ] ) {
case V_33 :
if ( ! V_30 -> V_17 [ 2 ] ) {
if ( V_30 -> V_17 [ 1 ] == V_34 )
V_3 -> V_35 = 1 ;
else
V_3 -> V_35 = 0 ;
F_2 ( L_4 ,
( V_3 -> V_35 ) ? L_5 : L_6 ) ;
} else {
F_2 ( L_7 ) ;
}
break;
case V_36 :
if ( ! V_30 -> V_17 [ 3 ] )
F_2 ( L_8 , V_30 -> V_17 [ 1 ] ,
V_30 -> V_17 [ 2 ] ) ;
else
F_2 ( L_9 ) ;
break;
case V_37 :
if ( ! V_30 -> V_17 [ 1 ] ) {
V_3 -> V_8 = V_9 ;
if ( V_3 -> V_35 )
V_3 -> V_4 = V_38 ;
F_3 ( & V_3 -> V_39 ) ;
F_2 ( L_10 ) ;
} else {
F_2 ( L_11 ) ;
}
break;
case V_40 :
if ( V_2 -> V_24 . V_25 &&
V_30 -> V_17 [ 1 ] == V_41 ) {
F_2 ( L_12 ,
( ( V_30 -> V_17 [ 2 ] == V_42 ) ||
( V_30 -> V_17 [ 2 ] == V_43 ) ) ?
L_13 : L_14 ) ;
if ( V_30 -> V_44 > 3 && V_30 -> V_17 [ 3 ] )
V_2 -> V_24 . V_45 = V_46 ;
else
V_2 -> V_24 . V_45 = V_47 ;
F_2 ( L_15 , V_2 -> V_24 . V_45 ) ;
} else if ( V_2 -> V_24 . V_25 &&
V_30 -> V_17 [ 1 ] == V_48 ) {
F_2 ( L_12 , ( V_30 -> V_17 [ 2 ] ) ?
L_16 : L_17 ) ;
} else {
F_2 ( L_18 ) ;
V_31 = - V_32 ;
}
break;
case V_49 :
if ( V_30 -> V_17 [ 1 ] == V_50 )
V_3 -> V_4 = V_38 ;
F_2 ( L_12 ,
( V_3 -> V_4 ) ? L_19 : L_20 ) ;
break;
default:
F_2 ( L_21 , V_30 -> V_17 [ 0 ] ) ;
V_31 = - V_32 ;
break;
}
exit:
if ( ! V_31 )
F_7 ( V_14 ) ;
return V_31 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_22 ,
const void * V_51 , T_2 V_52 )
{
struct V_13 * V_14 ;
struct V_53 * V_16 ;
if ( V_2 -> V_54 ) {
F_10 ( L_22 ) ;
return - V_55 ;
}
V_14 = F_11 ( V_56 + V_52 , V_57 ) ;
if ( ! V_14 ) {
F_10 ( L_23 ) ;
return - V_58 ;
}
V_16 = (struct V_53 * ) F_12 ( V_14 , V_56 ) ;
V_16 -> V_22 = F_13 ( V_22 ) ;
V_16 -> V_59 = V_52 ;
if ( V_52 )
memcpy ( F_12 ( V_14 , V_52 ) , V_51 , V_52 ) ;
F_14 ( V_14 ) = V_60 ;
F_15 ( & V_2 -> V_3 -> V_61 , V_14 ) ;
V_2 -> V_24 . V_25 = true ;
V_2 -> V_3 -> V_26 = false ;
F_3 ( & V_2 -> V_11 . V_12 ) ;
if ( ! F_16 ( V_2 -> V_3 -> V_27 ,
V_2 -> V_3 -> V_26 ||
V_2 -> V_54 ,
V_62 ) )
return - V_63 ;
if ( V_2 -> V_54 )
return - V_55 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_2 V_64 )
{
int V_31 ;
V_31 = F_9 ( V_2 , V_65 , & V_64 , 1 ) ;
if ( V_31 )
F_10 ( L_24 , V_64 ) ;
return V_31 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_64 = 0 ;
V_31 = F_9 ( V_2 , V_66 , & V_64 , 1 ) ;
if ( V_31 )
F_10 ( L_25 , V_31 ) ;
return V_31 ;
}
int F_19 ( struct V_1 * V_2 , T_2 V_64 )
{
struct V_67 * V_68 = V_2 -> V_24 . V_68 ;
int V_31 ;
if ( ! V_68 -> V_69 )
return 0 ;
V_31 = F_9 ( V_2 , V_70 ,
& V_64 , 1 ) ;
if ( V_31 )
F_10 ( L_26 , V_31 ) ;
return V_31 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_51 [ 2 ] ;
V_51 [ 0 ] = ( V_2 -> V_24 . V_71 & 0xff00 ) >> 8 ;
V_51 [ 1 ] = ( T_2 ) ( V_2 -> V_24 . V_71 & 0x00ff ) ;
F_2 ( L_27 ,
V_51 [ 0 ] , V_51 [ 1 ] ) ;
V_31 = F_9 ( V_2 , V_72 , V_51 , 2 ) ;
if ( V_31 )
F_10 ( L_9 ) ;
return V_31 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_51 ;
if ( V_2 -> V_24 . V_35 )
V_51 = V_34 ;
else
V_51 = V_73 ;
V_31 = F_9 ( V_2 , V_74 , & V_51 , 1 ) ;
if ( V_31 )
F_10 ( L_28 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_28 * V_3 = V_2 -> V_3 ;
int V_31 ;
V_31 = F_9 ( V_2 , V_75 , NULL , 0 ) ;
if ( V_31 ) {
F_10 ( L_29 ) ;
return V_31 ;
}
V_31 = F_16 ( V_3 -> V_39 ,
V_3 -> V_8 ||
V_2 -> V_54 ,
V_76 ) ;
if ( V_31 < 0 || V_2 -> V_54 ) {
F_10 ( L_30 ,
V_31 , V_3 -> V_8 , V_3 -> V_4 ,
V_3 -> V_6 ) ;
} else if ( ! V_31 ) {
F_10 ( L_31 , V_3 -> V_8 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_31 = - V_63 ;
} else {
F_2 ( L_32 , V_3 -> V_8 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_31 = 0 ;
}
return V_31 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
if ( V_2 -> V_24 . V_77 ) {
V_2 -> V_24 . V_77 = 0 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_78 ) {
V_2 -> V_24 . V_78 = 0 ;
F_21 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_79 ) {
V_2 -> V_24 . V_79 = 0 ;
if ( V_2 -> V_24 . V_80 ) {
V_31 = F_22 ( V_2 ) ;
} else {
V_31 = V_2 -> V_81 ( V_2 ) ;
V_2 -> V_3 -> V_8 = V_10 ;
F_2 ( L_33 ) ;
}
}
return V_31 ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 )
V_2 -> V_82 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_31 = 0 ;
if ( ! V_14 || ! V_14 -> V_17 )
return - V_32 ;
if ( ! V_14 -> V_52 || ( ( V_14 -> V_52 + V_83 ) > V_84 ) ) {
F_10 ( L_34 ,
V_14 -> V_52 , V_84 ) ;
return - V_32 ;
}
F_26 ( V_14 , V_83 ) ;
V_14 -> V_17 [ 0 ] = ( V_14 -> V_52 & 0x0000ff ) ;
V_14 -> V_17 [ 1 ] = ( V_14 -> V_52 & 0x00ff00 ) >> 8 ;
V_14 -> V_17 [ 2 ] = ( V_14 -> V_52 & 0xff0000 ) >> 16 ;
V_14 -> V_17 [ 3 ] = F_14 ( V_14 ) ;
if ( V_2 -> V_85 )
V_31 = V_2 -> V_85 ( V_2 , V_14 -> V_17 , V_14 -> V_52 ) ;
return V_31 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_86 ;
F_28 ( & V_2 -> V_3 -> V_61 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
V_86 = F_29 ( V_87 , V_88 ) ;
V_2 -> V_3 -> V_89 = F_30 ( V_86 , V_90 ) ;
if ( ! V_2 -> V_3 -> V_89 ) {
V_2 -> V_3 -> V_91 = NULL ;
F_10 ( L_35 ) ;
} else {
V_2 -> V_3 -> V_91 =
( T_2 * ) F_31 ( V_2 -> V_3 -> V_89 ,
V_88 ) ;
F_2 ( L_36 ,
V_2 -> V_3 -> V_89 , V_2 -> V_3 -> V_91 ) ;
}
F_32 ( & V_2 -> V_3 -> V_27 ) ;
F_32 ( & V_2 -> V_3 -> V_39 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_3 -> V_61 ) ;
F_35 ( V_2 -> V_3 -> V_89 ) ;
F_35 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_36 ( struct V_92 * V_93 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_37 ( V_93 ) ;
F_2 ( L_37 , F_14 ( V_14 ) , V_14 -> V_52 ) ;
if ( V_2 -> V_3 -> V_94 || V_2 -> V_3 -> V_95 ) {
F_10 ( L_38 , V_96 ) ;
return - V_97 ;
}
switch ( F_14 ( V_14 ) ) {
case V_98 :
V_93 -> V_99 . V_100 ++ ;
break;
case V_101 :
V_93 -> V_99 . V_102 ++ ;
break;
case V_103 :
V_93 -> V_99 . V_104 ++ ;
break;
}
F_38 ( & V_2 -> V_3 -> V_61 , V_14 ) ;
if ( ! V_2 -> V_3 -> V_95 )
F_3 ( & V_2 -> V_11 . V_12 ) ;
return 0 ;
}
static int F_39 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_37 ( V_93 ) ;
F_34 ( & V_2 -> V_3 -> V_61 ) ;
return 0 ;
}
static int F_40 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_37 ( V_93 ) ;
F_34 ( & V_2 -> V_3 -> V_61 ) ;
return 0 ;
}
static int F_41 ( struct V_92 * V_93 )
{
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
T_2 * V_17 , int V_52 )
{
int V_31 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 1 ] = 0x00 ;
V_17 [ 2 ] = 0x00 ;
V_17 [ 3 ] = V_52 ;
F_43 ( L_39 ,
V_105 , V_17 , V_106 + V_52 ) ;
V_31 = F_9 ( V_2 , V_107 , V_17 ,
V_106 + V_52 ) ;
if ( V_31 )
F_10 ( L_40 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_110 [ V_106 + V_111 ] ;
int V_31 ;
T_3 V_112 ;
F_45 (dt_node, NULL, L_41 ) {
V_31 = F_46 ( V_109 , L_42 , & V_112 ) ;
if ( ! V_31 )
V_2 -> V_24 . V_71 = V_112 ;
V_31 = F_47 ( V_109 , L_43 ,
V_110 + V_106 ,
V_111 ) ;
if ( V_31 ) {
F_48 ( V_109 ) ;
return V_31 ;
}
F_2 ( L_44 ) ;
V_31 = F_42 ( V_2 , V_110 ,
V_111 ) ;
if ( V_31 ) {
F_10 ( L_45 ) ;
F_48 ( V_109 ) ;
return V_31 ;
}
}
return 0 ;
}
static int F_49 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_37 ( V_93 ) ;
int V_31 ;
V_31 = F_17 ( V_2 , V_41 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_24 . V_71 = 0xfffe ;
F_44 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , 0x01 ) ;
V_2 -> V_24 . V_35 = 1 ;
F_21 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_92 * V_93 , const T_4 * V_113 )
{
struct V_13 * V_14 ;
long V_31 ;
T_2 V_114 [ 8 ] ;
V_114 [ 0 ] = V_60 ;
V_114 [ 1 ] = sizeof( T_4 ) ;
memcpy ( V_114 + 2 , V_113 , sizeof( T_4 ) ) ;
V_14 = F_51 ( V_93 , V_115 , sizeof( V_114 ) , V_114 ,
V_116 ) ;
if ( F_52 ( V_14 ) ) {
V_31 = F_53 ( V_14 ) ;
F_10 ( L_46 ,
V_93 -> V_117 , V_31 ) ;
return V_31 ;
}
F_7 ( V_14 ) ;
return 0 ;
}
static int F_54 ( void * V_17 )
{
struct V_118 * V_119 = V_17 ;
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_28 * V_3 = V_2 -> V_3 ;
T_5 V_120 ;
struct V_13 * V_14 ;
T_6 V_121 ;
F_55 ( & V_120 , V_122 ) ;
for (; ; ) {
F_56 ( & V_119 -> V_12 , & V_120 ) ;
F_57 ( V_123 ) ;
if ( F_58 () || V_2 -> V_54 ) {
F_2 ( L_47 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_24 . V_124 ||
F_59 ( & V_3 -> V_61 ) ) ) ) {
F_2 ( L_48 ) ;
F_60 () ;
}
F_57 ( V_125 ) ;
F_61 ( & V_119 -> V_12 , & V_120 ) ;
F_2 ( L_49 ) ;
if ( F_58 () || V_2 -> V_54 ) {
F_2 ( L_47 ) ;
break;
}
F_62 ( & V_2 -> V_126 , V_121 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_63 ( & V_2 -> V_126 , V_121 ) ;
V_2 -> V_127 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_38 &&
! F_59 ( & V_3 -> V_61 ) ) {
F_63 ( & V_2 -> V_126 , V_121 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_81 ( V_2 ) ;
continue;
} else {
F_63 ( & V_2 -> V_126 , V_121 ) ;
}
if ( V_3 -> V_4 == V_38 )
continue;
if ( ! V_2 -> V_24 . V_124 ||
V_2 -> V_3 -> V_95 )
continue;
V_14 = F_64 ( & V_3 -> V_61 ) ;
if ( V_14 ) {
if ( F_25 ( V_2 , V_14 ) )
V_2 -> V_24 . V_128 -> V_99 . V_129 ++ ;
else
V_2 -> V_24 . V_128 -> V_99 . V_130 += V_14 -> V_52 ;
F_7 ( V_14 ) ;
}
}
return 0 ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = NULL ;
int V_31 ;
V_93 = F_66 () ;
if ( ! V_93 ) {
F_10 ( L_50 ) ;
goto V_131;
}
V_2 -> V_24 . V_128 = V_93 ;
F_67 ( V_93 , V_2 ) ;
V_93 -> V_132 = V_133 ;
V_93 -> V_134 = F_41 ;
V_93 -> V_135 = F_40 ;
V_93 -> V_136 = F_39 ;
V_93 -> V_137 = F_36 ;
V_93 -> V_138 = F_49 ;
V_93 -> V_139 = F_50 ;
V_93 -> V_45 = V_2 -> V_24 . V_45 ;
V_31 = F_68 ( V_93 ) ;
if ( V_31 < 0 ) {
F_10 ( L_51 ) ;
goto V_140;
}
#ifdef F_69
F_70 ( V_93 ) ;
#endif
return 0 ;
V_140:
F_71 ( V_93 ) ;
V_131:
F_72 ( V_2 -> V_11 . V_141 ) ;
F_33 ( V_2 ) ;
F_35 ( V_2 ) ;
return - V_58 ;
}
struct V_1 * F_73 ( void * V_68 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_90 ) ;
if ( ! V_2 ) {
F_10 ( L_52 ) ;
goto V_142;
}
V_2 -> V_3 = F_30 ( sizeof( * V_2 -> V_3 ) , V_90 ) ;
if ( ! V_2 -> V_3 ) {
F_10 ( L_53 ) ;
goto V_143;
}
F_27 ( V_2 ) ;
F_2 ( L_54 ) ;
V_2 -> V_11 . V_2 = V_2 ;
F_74 ( & V_2 -> V_126 ) ;
F_32 ( & V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_141 = F_75 ( F_54 ,
& V_2 -> V_11 , L_55 ) ;
if ( F_52 ( V_2 -> V_11 . V_141 ) )
goto V_144;
V_2 -> V_24 . V_68 = V_68 ;
V_2 -> V_24 . V_124 = true ;
return V_2 ;
V_144:
F_33 ( V_2 ) ;
V_143:
F_35 ( V_2 ) ;
V_142:
return NULL ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
V_93 = V_2 -> V_24 . V_128 ;
F_3 ( & V_2 -> V_3 -> V_27 ) ;
F_3 ( & V_2 -> V_3 -> V_39 ) ;
F_72 ( V_2 -> V_11 . V_141 ) ;
#ifdef F_69
F_77 ( V_93 ) ;
#endif
F_78 ( V_93 ) ;
F_71 ( V_93 ) ;
V_2 -> V_24 . V_128 = NULL ;
F_33 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
