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
int F_18 ( struct V_1 * V_2 , T_2 V_65 )
{
struct V_67 * V_68 = V_2 -> V_24 . V_68 ;
int V_31 ;
if ( ! V_68 -> V_69 )
return 0 ;
V_31 = F_9 ( V_2 , V_70 ,
& V_65 , 1 ) ;
if ( V_31 )
F_10 ( L_25 , V_31 ) ;
return V_31 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_51 [ 2 ] ;
V_51 [ 0 ] = ( V_2 -> V_24 . V_71 & 0xff00 ) >> 8 ;
V_51 [ 1 ] = ( T_2 ) ( V_2 -> V_24 . V_71 & 0x00ff ) ;
F_2 ( L_26 ,
V_51 [ 0 ] , V_51 [ 1 ] ) ;
V_31 = F_9 ( V_2 , V_72 , V_51 , 2 ) ;
if ( V_31 )
F_10 ( L_9 ) ;
return V_31 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_51 ;
if ( V_2 -> V_24 . V_35 )
V_51 = V_34 ;
else
V_51 = V_73 ;
V_31 = F_9 ( V_2 , V_74 , & V_51 , 1 ) ;
if ( V_31 )
F_10 ( L_27 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_28 * V_3 = V_2 -> V_3 ;
int V_31 ;
V_31 = F_9 ( V_2 , V_75 , NULL , 0 ) ;
if ( V_31 ) {
F_10 ( L_28 ) ;
return V_31 ;
}
V_31 = F_16 ( V_3 -> V_39 ,
V_3 -> V_8 ||
V_2 -> V_54 ,
V_76 ) ;
if ( V_31 < 0 || V_2 -> V_54 ) {
F_10 ( L_29 ,
V_31 , V_3 -> V_8 , V_3 -> V_4 ,
V_3 -> V_6 ) ;
} else if ( ! V_31 ) {
F_10 ( L_30 , V_3 -> V_8 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_31 = - V_64 ;
} else {
F_2 ( L_31 , V_3 -> V_8 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_31 = 0 ;
}
return V_31 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
if ( V_2 -> V_24 . V_77 ) {
V_2 -> V_24 . V_77 = 0 ;
F_19 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_78 ) {
V_2 -> V_24 . V_78 = 0 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_24 . V_79 ) {
V_2 -> V_24 . V_79 = 0 ;
if ( V_2 -> V_24 . V_80 ) {
V_31 = F_21 ( V_2 ) ;
} else {
V_31 = V_2 -> V_81 ( V_2 ) ;
V_2 -> V_3 -> V_8 = V_10 ;
F_2 ( L_32 ) ;
}
}
return V_31 ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 )
V_2 -> V_82 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
int V_31 = 0 ;
if ( ! V_14 || ! V_14 -> V_17 )
return - V_32 ;
if ( ! V_14 -> V_52 || ( ( V_14 -> V_52 + V_83 ) > V_84 ) ) {
F_10 ( L_33 ,
V_14 -> V_52 , V_84 ) ;
return - V_32 ;
}
if ( F_25 ( V_14 ) < V_83 ) {
struct V_13 * V_85 = V_14 ;
V_14 = F_26 ( V_14 , V_83 ) ;
if ( ! V_14 ) {
F_10 ( L_34 ,
V_83 ) ;
V_14 = V_85 ;
return - V_32 ;
}
F_7 ( V_85 ) ;
}
F_27 ( V_14 , V_83 ) ;
V_14 -> V_17 [ 0 ] = ( V_14 -> V_52 & 0x0000ff ) ;
V_14 -> V_17 [ 1 ] = ( V_14 -> V_52 & 0x00ff00 ) >> 8 ;
V_14 -> V_17 [ 2 ] = ( V_14 -> V_52 & 0xff0000 ) >> 16 ;
V_14 -> V_17 [ 3 ] = F_14 ( V_14 ) -> V_60 ;
if ( V_2 -> V_86 )
V_31 = V_2 -> V_86 ( V_2 , V_14 -> V_17 , V_14 -> V_52 ) ;
return V_31 ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_87 ;
F_29 ( & V_2 -> V_3 -> V_62 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
V_87 = F_30 ( V_88 , V_89 ) ;
V_2 -> V_3 -> V_90 = F_31 ( V_87 , V_91 ) ;
if ( ! V_2 -> V_3 -> V_90 ) {
V_2 -> V_3 -> V_92 = NULL ;
F_10 ( L_35 ) ;
} else {
V_2 -> V_3 -> V_92 =
( T_2 * ) F_32 ( V_2 -> V_3 -> V_90 ,
V_89 ) ;
F_2 ( L_36 ,
V_2 -> V_3 -> V_90 , V_2 -> V_3 -> V_92 ) ;
}
F_33 ( & V_2 -> V_3 -> V_27 ) ;
F_33 ( & V_2 -> V_3 -> V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_3 -> V_62 ) ;
F_36 ( V_2 -> V_3 -> V_90 ) ;
F_36 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_37 ( struct V_93 * V_94 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_38 ( V_94 ) ;
F_2 ( L_37 , V_14 -> V_60 , V_14 -> V_52 ) ;
if ( ! F_39 ( V_95 , & V_94 -> V_96 ) ) {
F_10 ( L_38 , V_94 -> V_96 ) ;
F_40 ( L_39 , V_97 ,
V_14 -> V_17 , V_14 -> V_52 ) ;
return - V_98 ;
}
switch ( F_14 ( V_14 ) -> V_60 ) {
case V_99 :
V_94 -> V_100 . V_101 ++ ;
break;
case V_102 :
V_94 -> V_100 . V_103 ++ ;
break;
case V_104 :
V_94 -> V_100 . V_105 ++ ;
break;
}
F_41 ( & V_2 -> V_3 -> V_62 , V_14 ) ;
F_3 ( & V_2 -> V_11 . V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_38 ( V_94 ) ;
F_35 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_43 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_38 ( V_94 ) ;
if ( ! F_44 ( V_95 , & V_94 -> V_96 ) )
return 0 ;
F_35 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_45 ( struct V_93 * V_94 )
{
F_46 ( V_95 , & V_94 -> V_96 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
T_2 * V_17 , int V_52 )
{
int V_31 ;
V_17 [ 0 ] = 0x00 ;
V_17 [ 1 ] = 0x00 ;
V_17 [ 2 ] = 0x00 ;
V_17 [ 3 ] = V_52 ;
F_40 ( L_40 ,
V_97 , V_17 , V_106 + V_52 ) ;
V_31 = F_9 ( V_2 , V_107 , V_17 ,
V_106 + V_52 ) ;
if ( V_31 )
F_10 ( L_41 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
T_2 V_110 [ V_106 + V_111 ] ;
int V_31 ;
T_3 V_112 ;
F_49 (dt_node, NULL, L_42 ) {
V_31 = F_50 ( V_109 , L_43 , & V_112 ) ;
if ( ! V_31 )
V_2 -> V_24 . V_71 = V_112 ;
V_31 = F_51 ( V_109 , L_44 ,
V_110 + V_106 ,
V_111 ) ;
if ( V_31 )
return V_31 ;
F_2 ( L_45 ) ;
V_31 = F_47 ( V_2 , V_110 ,
V_111 ) ;
if ( V_31 ) {
F_10 ( L_46 ) ;
return V_31 ;
}
}
return 0 ;
}
static int F_52 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_38 ( V_94 ) ;
int V_31 ;
V_31 = F_17 ( V_2 , V_41 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_24 . V_71 = 0xffff ;
F_48 ( V_2 ) ;
F_18 ( V_2 , 0x01 ) ;
V_2 -> V_24 . V_35 = 1 ;
F_20 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_93 * V_94 , const T_4 * V_113 )
{
struct V_13 * V_14 ;
long V_31 ;
T_2 V_114 [ 8 ] ;
V_114 [ 0 ] = V_61 ;
V_114 [ 1 ] = sizeof( T_4 ) ;
memcpy ( V_114 + 2 , V_113 , sizeof( T_4 ) ) ;
V_14 = F_54 ( V_94 , V_115 , sizeof( V_114 ) , V_114 ,
V_116 ) ;
if ( F_55 ( V_14 ) ) {
V_31 = F_56 ( V_14 ) ;
F_10 ( L_47 ,
V_94 -> V_117 , V_31 ) ;
return V_31 ;
}
F_7 ( V_14 ) ;
return 0 ;
}
static int F_57 ( void * V_17 )
{
struct V_118 * V_119 = V_17 ;
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_28 * V_3 = V_2 -> V_3 ;
T_5 V_120 ;
struct V_13 * V_14 ;
T_6 V_96 ;
F_58 ( & V_120 , V_121 ) ;
for (; ; ) {
F_59 ( & V_119 -> V_12 , & V_120 ) ;
F_60 ( V_122 ) ;
if ( F_61 () || V_2 -> V_54 ) {
F_2 ( L_48 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_24 . V_123 ||
F_62 ( & V_3 -> V_62 ) ) ) ) {
F_2 ( L_49 ) ;
F_63 () ;
}
F_60 ( V_124 ) ;
F_64 ( & V_119 -> V_12 , & V_120 ) ;
F_2 ( L_50 ) ;
if ( F_61 () || V_2 -> V_54 ) {
F_2 ( L_48 ) ;
break;
}
F_65 ( & V_2 -> V_125 , V_96 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_66 ( & V_2 -> V_125 , V_96 ) ;
V_2 -> V_126 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_38 &&
! F_62 ( & V_3 -> V_62 ) ) {
F_66 ( & V_2 -> V_125 , V_96 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_81 ( V_2 ) ;
continue;
} else {
F_66 ( & V_2 -> V_125 , V_96 ) ;
}
if ( V_3 -> V_4 == V_38 )
continue;
if ( ! V_2 -> V_24 . V_123 )
continue;
V_14 = F_67 ( & V_3 -> V_62 ) ;
if ( V_14 ) {
if ( F_24 ( V_2 , V_14 ) )
V_2 -> V_24 . V_127 -> V_100 . V_128 ++ ;
else
V_2 -> V_24 . V_127 -> V_100 . V_129 += V_14 -> V_52 ;
F_7 ( V_14 ) ;
}
}
return 0 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = NULL ;
int V_31 ;
V_94 = F_69 () ;
if ( ! V_94 ) {
F_10 ( L_51 ) ;
goto V_130;
}
V_2 -> V_24 . V_127 = V_94 ;
F_70 ( V_94 , V_2 ) ;
V_94 -> V_131 = V_132 ;
V_94 -> V_133 = F_45 ;
V_94 -> V_134 = F_43 ;
V_94 -> V_135 = F_42 ;
V_94 -> V_136 = F_37 ;
V_94 -> V_137 = F_52 ;
V_94 -> V_138 = F_53 ;
V_94 -> V_45 = V_2 -> V_24 . V_45 ;
V_31 = F_71 ( V_94 ) ;
if ( V_31 < 0 ) {
F_10 ( L_52 ) ;
goto V_139;
}
#ifdef F_72
F_73 ( V_94 ) ;
#endif
return 0 ;
V_139:
F_74 ( V_94 ) ;
V_130:
F_75 ( V_2 -> V_11 . V_140 ) ;
F_34 ( V_2 ) ;
F_36 ( V_2 ) ;
return - V_58 ;
}
struct V_1 * F_76 ( void * V_68 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 ) {
F_10 ( L_53 ) ;
goto V_141;
}
V_2 -> V_3 = F_31 ( sizeof( * V_2 -> V_3 ) , V_91 ) ;
if ( ! V_2 -> V_3 ) {
F_10 ( L_54 ) ;
goto V_142;
}
F_28 ( V_2 ) ;
F_2 ( L_55 ) ;
V_2 -> V_11 . V_2 = V_2 ;
F_77 ( & V_2 -> V_125 ) ;
F_33 ( & V_2 -> V_11 . V_12 ) ;
V_2 -> V_11 . V_140 = F_78 ( F_57 ,
& V_2 -> V_11 , L_56 ) ;
if ( F_55 ( V_2 -> V_11 . V_140 ) )
goto V_143;
V_2 -> V_24 . V_68 = V_68 ;
V_2 -> V_24 . V_123 = true ;
return V_2 ;
V_143:
F_34 ( V_2 ) ;
V_142:
F_36 ( V_2 ) ;
V_141:
return NULL ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
V_94 = V_2 -> V_24 . V_127 ;
F_3 ( & V_2 -> V_3 -> V_27 ) ;
F_3 ( & V_2 -> V_3 -> V_39 ) ;
F_75 ( V_2 -> V_11 . V_140 ) ;
#ifdef F_72
F_80 ( V_94 ) ;
#endif
F_81 ( V_94 ) ;
F_74 ( V_94 ) ;
V_2 -> V_24 . V_127 = NULL ;
F_34 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
