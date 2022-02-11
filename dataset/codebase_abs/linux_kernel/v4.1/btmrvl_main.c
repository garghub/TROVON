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
if ( V_14 == NULL ) {
F_10 ( L_23 ) ;
return - V_58 ;
}
V_16 = (struct V_53 * ) F_12 ( V_14 , V_56 ) ;
V_16 -> V_22 = F_13 ( V_22 ) ;
V_16 -> V_59 = V_52 ;
if ( V_52 )
memcpy ( F_12 ( V_14 , V_52 ) , V_51 , V_52 ) ;
F_14 ( V_14 ) -> V_60 = V_61 ;
F_15 ( & V_2 -> V_3 -> V_62 , V_14 ) ;
V_2 -> V_24 . V_25 = true ;
V_2 -> V_3 -> V_26 = false ;
F_3 ( & V_2 -> V_11 . V_12 ) ;
if ( ! F_16 ( V_2 -> V_3 -> V_27 ,
V_2 -> V_3 -> V_26 ||
V_2 -> V_54 ,
V_63 ) )
return - V_64 ;
if ( V_2 -> V_54 )
return - V_55 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_2 V_65 )
{
int V_31 ;
V_31 = F_9 ( V_2 , V_66 , & V_65 , 1 ) ;
if ( V_31 )
F_10 ( L_24 , V_65 ) ;
return V_31 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_65 = 0 ;
V_31 = F_9 ( V_2 , V_67 , & V_65 , 1 ) ;
if ( V_31 )
F_10 ( L_25 , V_31 ) ;
return V_31 ;
}
int F_19 ( struct V_1 * V_2 , T_2 V_65 )
{
struct V_68 * V_69 = V_2 -> V_24 . V_69 ;
int V_31 ;
if ( ! V_69 -> V_70 )
return 0 ;
V_31 = F_9 ( V_2 , V_71 ,
& V_65 , 1 ) ;
if ( V_31 )
F_10 ( L_26 , V_31 ) ;
return V_31 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_51 [ 2 ] ;
V_51 [ 0 ] = ( V_2 -> V_24 . V_72 & 0xff00 ) >> 8 ;
V_51 [ 1 ] = ( T_2 ) ( V_2 -> V_24 . V_72 & 0x00ff ) ;
F_2 ( L_27 ,
V_51 [ 0 ] , V_51 [ 1 ] ) ;
V_31 = F_9 ( V_2 , V_73 , V_51 , 2 ) ;
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
V_51 = V_74 ;
V_31 = F_9 ( V_2 , V_75 , & V_51 , 1 ) ;
if ( V_31 )
F_10 ( L_28 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_28 * V_3 = V_2 -> V_3 ;
int V_31 ;
V_31 = F_9 ( V_2 , V_76 , NULL , 0 ) ;
if ( V_31 ) {
F_10 ( L_29 ) ;
return V_31 ;
}
V_31 = F_16 ( V_3 -> V_39 ,
V_3 -> V_8 ||
V_2 -> V_54 ,
V_77 ) ;
if ( V_31 < 0 || V_2 -> V_54 ) {
F_10 ( L_30 ,
V_31 , V_3 -> V_8 , V_3 -> V_4 ,
V_3 -> V_6 ) ;
} else if ( ! V_31 ) {
F_10 ( L_31 , V_3 -> V_8 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_31 = - V_64 ;
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
if ( V_2 -> V_24 . V_78 ) {
V_2 -> V_24 . V_78 = 0 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_79 ) {
V_2 -> V_24 . V_79 = 0 ;
F_21 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_80 ) {
V_2 -> V_24 . V_80 = 0 ;
if ( V_2 -> V_24 . V_81 ) {
V_31 = F_22 ( V_2 ) ;
} else {
V_31 = V_2 -> V_82 ( V_2 ) ;
V_2 -> V_3 -> V_8 = V_10 ;
F_2 ( L_33 ) ;
}
}
return V_31 ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 )
V_2 -> V_83 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_31 = 0 ;
if ( ! V_14 || ! V_14 -> V_17 )
return - V_32 ;
if ( ! V_14 -> V_52 || ( ( V_14 -> V_52 + V_84 ) > V_85 ) ) {
F_10 ( L_34 ,
V_14 -> V_52 , V_85 ) ;
return - V_32 ;
}
if ( F_26 ( V_14 ) < V_84 ) {
struct V_13 * V_86 = V_14 ;
V_14 = F_27 ( V_14 , V_84 ) ;
if ( ! V_14 ) {
F_10 ( L_35 ,
V_84 ) ;
V_14 = V_86 ;
return - V_32 ;
}
F_7 ( V_86 ) ;
}
F_28 ( V_14 , V_84 ) ;
V_14 -> V_17 [ 0 ] = ( V_14 -> V_52 & 0x0000ff ) ;
V_14 -> V_17 [ 1 ] = ( V_14 -> V_52 & 0x00ff00 ) >> 8 ;
V_14 -> V_17 [ 2 ] = ( V_14 -> V_52 & 0xff0000 ) >> 16 ;
V_14 -> V_17 [ 3 ] = F_14 ( V_14 ) -> V_60 ;
if ( V_2 -> V_87 )
V_31 = V_2 -> V_87 ( V_2 , V_14 -> V_17 , V_14 -> V_52 ) ;
return V_31 ;
}
static void F_29 ( struct V_1 * V_2 )
{
int V_88 ;
F_30 ( & V_2 -> V_3 -> V_62 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
V_88 = F_31 ( V_89 , V_90 ) ;
V_2 -> V_3 -> V_91 = F_32 ( V_88 , V_92 ) ;
if ( ! V_2 -> V_3 -> V_91 ) {
V_2 -> V_3 -> V_93 = NULL ;
F_10 ( L_36 ) ;
} else {
V_2 -> V_3 -> V_93 =
( T_2 * ) F_33 ( V_2 -> V_3 -> V_91 ,
V_90 ) ;
F_2 ( L_37 ,
V_2 -> V_3 -> V_91 , V_2 -> V_3 -> V_93 ) ;
}
F_34 ( & V_2 -> V_3 -> V_27 ) ;
F_34 ( & V_2 -> V_3 -> V_39 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_3 -> V_62 ) ;
F_37 ( V_2 -> V_3 -> V_91 ) ;
F_37 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_38 ( struct V_94 * V_95 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_39 ( V_95 ) ;
F_2 ( L_38 , V_14 -> V_60 , V_14 -> V_52 ) ;
if ( ! F_40 ( V_96 , & V_95 -> V_97 ) ) {
F_10 ( L_39 , V_95 -> V_97 ) ;
F_41 ( L_40 , V_98 ,
V_14 -> V_17 , V_14 -> V_52 ) ;
return - V_99 ;
}
switch ( F_14 ( V_14 ) -> V_60 ) {
case V_100 :
V_95 -> V_101 . V_102 ++ ;
break;
case V_103 :
V_95 -> V_101 . V_104 ++ ;
break;
case V_105 :
V_95 -> V_101 . V_106 ++ ;
break;
}
F_42 ( & V_2 -> V_3 -> V_62 , V_14 ) ;
F_3 ( & V_2 -> V_11 . V_12 ) ;
return 0 ;
}
static int F_43 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_39 ( V_95 ) ;
F_36 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_44 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_39 ( V_95 ) ;
if ( ! F_45 ( V_96 , & V_95 -> V_97 ) )
return 0 ;
F_36 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_46 ( struct V_94 * V_95 )
{
F_47 ( V_96 , & V_95 -> V_97 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_2 * V_17 , int V_52 )
{
int V_31 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 1 ] = 0x00 ;
V_17 [ 2 ] = 0x00 ;
V_17 [ 3 ] = V_52 ;
F_41 ( L_41 ,
V_98 , V_17 , V_107 + V_52 ) ;
V_31 = F_9 ( V_2 , V_108 , V_17 ,
V_107 + V_52 ) ;
if ( V_31 )
F_10 ( L_42 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_109 * V_110 ;
T_2 V_111 [ V_107 + V_112 ] ;
int V_31 ;
T_3 V_113 ;
F_50 (dt_node, NULL, L_43 ) {
V_31 = F_51 ( V_110 , L_44 , & V_113 ) ;
if ( ! V_31 )
V_2 -> V_24 . V_72 = V_113 ;
V_31 = F_52 ( V_110 , L_45 ,
V_111 + V_107 ,
V_112 ) ;
if ( V_31 )
return V_31 ;
F_2 ( L_46 ) ;
V_31 = F_48 ( V_2 , V_111 ,
V_112 ) ;
if ( V_31 ) {
F_10 ( L_47 ) ;
return V_31 ;
}
}
return 0 ;
}
static int F_53 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_39 ( V_95 ) ;
int V_31 ;
V_31 = F_17 ( V_2 , V_41 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_24 . V_72 = 0xffff ;
F_49 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , 0x01 ) ;
V_2 -> V_24 . V_35 = 1 ;
F_21 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_94 * V_95 , const T_4 * V_114 )
{
struct V_13 * V_14 ;
long V_31 ;
T_2 V_115 [ 8 ] ;
V_115 [ 0 ] = V_61 ;
V_115 [ 1 ] = sizeof( T_4 ) ;
memcpy ( V_115 + 2 , V_114 , sizeof( T_4 ) ) ;
V_14 = F_55 ( V_95 , V_116 , sizeof( V_115 ) , V_115 ,
V_117 ) ;
if ( F_56 ( V_14 ) ) {
V_31 = F_57 ( V_14 ) ;
F_10 ( L_48 ,
V_95 -> V_118 , V_31 ) ;
return V_31 ;
}
F_7 ( V_14 ) ;
return 0 ;
}
static int F_58 ( void * V_17 )
{
struct V_119 * V_120 = V_17 ;
struct V_1 * V_2 = V_120 -> V_2 ;
struct V_28 * V_3 = V_2 -> V_3 ;
T_5 V_121 ;
struct V_13 * V_14 ;
T_6 V_97 ;
F_59 ( & V_121 , V_122 ) ;
for (; ; ) {
F_60 ( & V_120 -> V_12 , & V_121 ) ;
F_61 ( V_123 ) ;
if ( F_62 () || V_2 -> V_54 ) {
F_2 ( L_49 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_24 . V_124 ||
F_63 ( & V_3 -> V_62 ) ) ) ) {
F_2 ( L_50 ) ;
F_64 () ;
}
F_61 ( V_125 ) ;
F_65 ( & V_120 -> V_12 , & V_121 ) ;
F_2 ( L_51 ) ;
if ( F_62 () || V_2 -> V_54 ) {
F_2 ( L_49 ) ;
break;
}
F_66 ( & V_2 -> V_126 , V_97 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_67 ( & V_2 -> V_126 , V_97 ) ;
V_2 -> V_127 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_38 &&
! F_63 ( & V_3 -> V_62 ) ) {
F_67 ( & V_2 -> V_126 , V_97 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_82 ( V_2 ) ;
continue;
} else {
F_67 ( & V_2 -> V_126 , V_97 ) ;
}
if ( V_3 -> V_4 == V_38 )
continue;
if ( ! V_2 -> V_24 . V_124 )
continue;
V_14 = F_68 ( & V_3 -> V_62 ) ;
if ( V_14 ) {
if ( F_25 ( V_2 , V_14 ) )
V_2 -> V_24 . V_128 -> V_101 . V_129 ++ ;
else
V_2 -> V_24 . V_128 -> V_101 . V_130 += V_14 -> V_52 ;
F_7 ( V_14 ) ;
}
}
return 0 ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = NULL ;
int V_31 ;
V_95 = F_70 () ;
if ( ! V_95 ) {
F_10 ( L_52 ) ;
goto V_131;
}
V_2 -> V_24 . V_128 = V_95 ;
F_71 ( V_95 , V_2 ) ;
V_95 -> V_132 = V_133 ;
V_95 -> V_134 = F_46 ;
V_95 -> V_135 = F_44 ;
V_95 -> V_136 = F_43 ;
V_95 -> V_137 = F_38 ;
V_95 -> V_138 = F_53 ;
V_95 -> V_139 = F_54 ;
V_95 -> V_45 = V_2 -> V_24 . V_45 ;
V_31 = F_72 ( V_95 ) ;
if ( V_31 < 0 ) {
F_10 ( L_53 ) ;
goto V_140;
}
#ifdef F_73
F_74 ( V_95 ) ;
#endif
return 0 ;
V_140:
F_75 ( V_95 ) ;
V_131:
F_76 ( V_2 -> V_11 . V_141 ) ;
F_35 ( V_2 ) ;
F_37 ( V_2 ) ;
return - V_58 ;
}
struct V_1 * F_77 ( void * V_69 )
{
struct V_1 * V_2 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 ) {
F_10 ( L_54 ) ;
goto V_142;
}
V_2 -> V_3 = F_32 ( sizeof( * V_2 -> V_3 ) , V_92 ) ;
if ( ! V_2 -> V_3 ) {
F_10 ( L_55 ) ;
goto V_143;
}
F_29 ( V_2 ) ;
F_2 ( L_56 ) ;
V_2 -> V_11 . V_2 = V_2 ;
F_78 ( & V_2 -> V_126 ) ;
F_34 ( & V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_141 = F_79 ( F_58 ,
& V_2 -> V_11 , L_57 ) ;
if ( F_56 ( V_2 -> V_11 . V_141 ) )
goto V_144;
V_2 -> V_24 . V_69 = V_69 ;
V_2 -> V_24 . V_124 = true ;
return V_2 ;
V_144:
F_35 ( V_2 ) ;
V_143:
F_37 ( V_2 ) ;
V_142:
return NULL ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_94 * V_95 ;
V_95 = V_2 -> V_24 . V_128 ;
F_3 ( & V_2 -> V_3 -> V_27 ) ;
F_3 ( & V_2 -> V_3 -> V_39 ) ;
F_76 ( V_2 -> V_11 . V_141 ) ;
#ifdef F_73
F_81 ( V_95 ) ;
#endif
F_82 ( V_95 ) ;
F_75 ( V_95 ) ;
V_2 -> V_24 . V_128 = NULL ;
F_35 ( V_2 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
