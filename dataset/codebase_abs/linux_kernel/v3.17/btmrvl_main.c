void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 = V_5 ;
V_2 -> V_3 -> V_6 = 0 ;
V_2 -> V_3 -> V_7 ++ ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
}
bool F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_14 ;
if ( V_13 -> V_15 == V_16 ) {
struct V_17 * V_18 ;
T_1 V_19 ;
V_18 = ( void * ) ( V_11 -> V_14 + V_20 ) ;
V_19 = F_4 ( V_18 -> V_19 ) ;
if ( V_2 -> V_21 . V_22 ) {
V_2 -> V_21 . V_22 = false ;
V_2 -> V_3 -> V_23 = true ;
F_2 ( & V_2 -> V_3 -> V_24 ) ;
if ( F_5 ( V_19 ) == 0x3F ) {
F_6 ( L_1 ,
V_19 ) ;
F_7 ( V_11 ) ;
return false ;
}
}
}
return true ;
}
int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_25 * V_3 = V_2 -> V_3 ;
struct V_26 * V_27 ;
int V_28 = 0 ;
V_27 = (struct V_26 * ) V_11 -> V_14 ;
if ( V_27 -> V_18 != 0xff ) {
F_6 ( L_2 , V_27 -> V_18 ) ;
V_28 = - V_29 ;
goto exit;
}
switch ( V_27 -> V_14 [ 0 ] ) {
case V_30 :
if ( ! V_27 -> V_14 [ 2 ] ) {
if ( V_27 -> V_14 [ 1 ] == V_31 )
V_3 -> V_32 = 1 ;
else
V_3 -> V_32 = 0 ;
F_6 ( L_3 ,
( V_3 -> V_32 ) ? L_4 : L_5 ) ;
} else {
F_6 ( L_6 ) ;
}
break;
case V_33 :
if ( ! V_27 -> V_14 [ 3 ] )
F_6 ( L_7 , V_27 -> V_14 [ 1 ] ,
V_27 -> V_14 [ 2 ] ) ;
else
F_6 ( L_8 ) ;
break;
case V_34 :
if ( ! V_27 -> V_14 [ 1 ] ) {
V_3 -> V_35 = V_36 ;
if ( V_3 -> V_32 )
V_3 -> V_4 = V_37 ;
F_2 ( & V_3 -> V_38 ) ;
F_6 ( L_9 ) ;
} else {
F_6 ( L_10 ) ;
}
break;
case V_39 :
if ( V_2 -> V_21 . V_22 &&
V_27 -> V_14 [ 1 ] == V_40 ) {
F_6 ( L_11 ,
( ( V_27 -> V_14 [ 2 ] == V_41 ) ||
( V_27 -> V_14 [ 2 ] == V_42 ) ) ?
L_12 : L_13 ) ;
if ( V_27 -> V_43 > 3 && V_27 -> V_14 [ 3 ] )
V_2 -> V_21 . V_44 = V_45 ;
else
V_2 -> V_21 . V_44 = V_46 ;
F_6 ( L_14 , V_2 -> V_21 . V_44 ) ;
} else if ( V_2 -> V_21 . V_22 &&
V_27 -> V_14 [ 1 ] == V_47 ) {
F_6 ( L_11 , ( V_27 -> V_14 [ 2 ] ) ?
L_15 : L_16 ) ;
} else {
F_6 ( L_17 ) ;
V_28 = - V_29 ;
}
break;
case V_48 :
if ( V_27 -> V_14 [ 1 ] == V_49 )
V_3 -> V_4 = V_37 ;
F_6 ( L_11 ,
( V_3 -> V_4 ) ? L_18 : L_19 ) ;
break;
default:
F_6 ( L_20 , V_27 -> V_14 [ 0 ] ) ;
V_28 = - V_29 ;
break;
}
exit:
if ( ! V_28 )
F_7 ( V_11 ) ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_19 ,
const void * V_50 , T_2 V_51 )
{
struct V_10 * V_11 ;
struct V_52 * V_13 ;
V_11 = F_10 ( V_53 + V_51 , V_54 ) ;
if ( V_11 == NULL ) {
F_11 ( L_21 ) ;
return - V_55 ;
}
V_13 = (struct V_52 * ) F_12 ( V_11 , V_53 ) ;
V_13 -> V_19 = F_13 ( V_19 ) ;
V_13 -> V_56 = V_51 ;
if ( V_51 )
memcpy ( F_12 ( V_11 , V_51 ) , V_50 , V_51 ) ;
F_14 ( V_11 ) -> V_57 = V_58 ;
F_15 ( & V_2 -> V_3 -> V_59 , V_11 ) ;
V_2 -> V_21 . V_22 = true ;
V_2 -> V_3 -> V_23 = false ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_16 ( V_2 -> V_3 -> V_24 ,
V_2 -> V_3 -> V_23 ,
F_17 ( V_60 ) ) )
return - V_61 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_62 )
{
int V_28 ;
V_28 = F_9 ( V_2 , V_63 , & V_62 , 1 ) ;
if ( V_28 )
F_11 ( L_22 , V_62 ) ;
return V_28 ;
}
int F_19 ( struct V_1 * V_2 , T_2 V_62 )
{
struct V_64 * V_65 = V_2 -> V_21 . V_65 ;
int V_28 ;
if ( ! V_65 -> V_66 )
return 0 ;
V_28 = F_9 ( V_2 , V_67 ,
& V_62 , 1 ) ;
if ( V_28 )
F_11 ( L_23 , V_28 ) ;
return V_28 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_28 ;
T_2 V_50 [ 2 ] ;
V_50 [ 0 ] = ( V_2 -> V_21 . V_68 & 0xff00 ) >> 8 ;
V_50 [ 1 ] = ( T_2 ) ( V_2 -> V_21 . V_68 & 0x00ff ) ;
F_6 ( L_24 ,
V_50 [ 0 ] , V_50 [ 1 ] ) ;
V_28 = F_9 ( V_2 , V_69 , V_50 , 2 ) ;
if ( V_28 )
F_11 ( L_25 ) ;
return V_28 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_28 ;
T_2 V_50 ;
if ( V_2 -> V_21 . V_32 )
V_50 = V_31 ;
else
V_50 = V_70 ;
V_28 = F_9 ( V_2 , V_71 , & V_50 , 1 ) ;
if ( V_28 )
F_11 ( L_26 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_25 * V_3 = V_2 -> V_3 ;
int V_28 ;
V_28 = F_9 ( V_2 , V_72 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( L_27 ) ;
return V_28 ;
}
V_28 = F_16 ( V_3 -> V_38 ,
V_3 -> V_35 ,
F_17 ( V_73 ) ) ;
if ( V_28 < 0 ) {
F_11 ( L_28 ,
V_28 , V_3 -> V_35 , V_3 -> V_4 ,
V_3 -> V_6 ) ;
} else if ( ! V_28 ) {
F_11 ( L_29 , V_3 -> V_35 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_28 = - V_61 ;
} else {
F_6 ( L_30 , V_3 -> V_35 ,
V_3 -> V_4 , V_3 -> V_6 ) ;
V_28 = 0 ;
}
return V_28 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
if ( V_2 -> V_21 . V_74 ) {
V_2 -> V_21 . V_74 = 0 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_21 . V_75 ) {
V_2 -> V_21 . V_75 = 0 ;
F_21 ( V_2 ) ;
}
if ( V_2 -> V_21 . V_76 ) {
V_2 -> V_21 . V_76 = 0 ;
if ( V_2 -> V_21 . V_77 ) {
V_28 = F_22 ( V_2 ) ;
} else {
V_28 = V_2 -> V_78 ( V_2 ) ;
V_2 -> V_3 -> V_35 = V_79 ;
}
}
return V_28 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_28 = 0 ;
if ( ! V_11 || ! V_11 -> V_14 )
return - V_29 ;
if ( ! V_11 -> V_51 || ( ( V_11 -> V_51 + V_80 ) > V_81 ) ) {
F_11 ( L_31 ,
V_11 -> V_51 , V_81 ) ;
return - V_29 ;
}
if ( F_25 ( V_11 ) < V_80 ) {
struct V_10 * V_82 = V_11 ;
V_11 = F_26 ( V_11 , V_80 ) ;
if ( ! V_11 ) {
F_11 ( L_32 ,
V_80 ) ;
V_11 = V_82 ;
return - V_29 ;
}
F_7 ( V_82 ) ;
}
F_27 ( V_11 , V_80 ) ;
V_11 -> V_14 [ 0 ] = ( V_11 -> V_51 & 0x0000ff ) ;
V_11 -> V_14 [ 1 ] = ( V_11 -> V_51 & 0x00ff00 ) >> 8 ;
V_11 -> V_14 [ 2 ] = ( V_11 -> V_51 & 0xff0000 ) >> 16 ;
V_11 -> V_14 [ 3 ] = F_14 ( V_11 ) -> V_57 ;
if ( V_2 -> V_83 )
V_28 = V_2 -> V_83 ( V_2 , V_11 -> V_14 , V_11 -> V_51 ) ;
return V_28 ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_84 ;
F_29 ( & V_2 -> V_3 -> V_59 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
V_84 = F_30 ( V_85 , V_86 ) ;
V_2 -> V_3 -> V_87 = F_31 ( V_84 , V_88 ) ;
if ( ! V_2 -> V_3 -> V_87 ) {
V_2 -> V_3 -> V_89 = NULL ;
F_11 ( L_33 ) ;
} else {
V_2 -> V_3 -> V_89 =
( T_2 * ) F_32 ( V_2 -> V_3 -> V_87 ,
V_86 ) ;
F_6 ( L_34 ,
V_2 -> V_3 -> V_87 , V_2 -> V_3 -> V_89 ) ;
}
F_33 ( & V_2 -> V_3 -> V_24 ) ;
F_33 ( & V_2 -> V_3 -> V_38 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_3 -> V_59 ) ;
F_36 ( V_2 -> V_3 -> V_87 ) ;
F_36 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_37 ( struct V_90 * V_91 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_38 ( V_91 ) ;
F_6 ( L_35 , V_11 -> V_57 , V_11 -> V_51 ) ;
if ( ! F_39 ( V_92 , & V_91 -> V_93 ) ) {
F_11 ( L_36 , V_91 -> V_93 ) ;
F_40 ( L_37 , V_94 ,
V_11 -> V_14 , V_11 -> V_51 ) ;
return - V_95 ;
}
switch ( F_14 ( V_11 ) -> V_57 ) {
case V_96 :
V_91 -> V_97 . V_98 ++ ;
break;
case V_99 :
V_91 -> V_97 . V_100 ++ ;
break;
case V_101 :
V_91 -> V_97 . V_102 ++ ;
break;
}
F_41 ( & V_2 -> V_3 -> V_59 , V_11 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
return 0 ;
}
static int F_42 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_38 ( V_91 ) ;
F_35 ( & V_2 -> V_3 -> V_59 ) ;
return 0 ;
}
static int F_43 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_38 ( V_91 ) ;
if ( ! F_44 ( V_92 , & V_91 -> V_93 ) )
return 0 ;
F_35 ( & V_2 -> V_3 -> V_59 ) ;
return 0 ;
}
static int F_45 ( struct V_90 * V_91 )
{
F_46 ( V_92 , & V_91 -> V_93 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
T_2 * V_14 , int V_51 )
{
int V_28 ;
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0x00 ;
V_14 [ 2 ] = 0x00 ;
V_14 [ 3 ] = V_51 ;
F_40 ( L_38 ,
V_94 , V_14 , V_103 + V_51 ) ;
V_28 = F_9 ( V_2 , V_104 , V_14 ,
V_103 + V_51 ) ;
if ( V_28 )
F_11 ( L_39 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
T_2 V_107 [ V_103 + V_108 ] ;
const char V_109 [] = L_40 ;
const char V_110 [] = L_41 ;
int V_28 ;
V_106 = F_49 ( NULL , V_109 ) ;
if ( ! V_106 )
return - V_111 ;
V_28 = F_50 ( V_106 , V_110 ,
V_107 + V_103 ,
V_108 ) ;
if ( V_28 )
return V_28 ;
F_6 ( L_42 ) ;
V_28 = F_47 ( V_2 , V_107 , V_108 ) ;
if ( V_28 ) {
F_11 ( L_43 ) ;
return V_28 ;
}
return 0 ;
}
static int F_51 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_38 ( V_91 ) ;
F_18 ( V_2 , V_40 ) ;
F_48 ( V_2 ) ;
F_19 ( V_2 , 0x01 ) ;
V_2 -> V_21 . V_32 = 1 ;
F_21 ( V_2 ) ;
V_2 -> V_21 . V_68 = 0xffff ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_90 * V_91 , const T_3 * V_112 )
{
struct V_10 * V_11 ;
long V_28 ;
T_2 V_113 [ 8 ] ;
V_113 [ 0 ] = V_58 ;
V_113 [ 1 ] = sizeof( T_3 ) ;
memcpy ( V_113 + 2 , V_112 , sizeof( T_3 ) ) ;
V_11 = F_53 ( V_91 , V_114 , sizeof( V_113 ) , V_113 ,
V_115 ) ;
if ( F_54 ( V_11 ) ) {
V_28 = F_55 ( V_11 ) ;
F_11 ( L_44 ,
V_91 -> V_109 , V_28 ) ;
return V_28 ;
}
F_7 ( V_11 ) ;
return 0 ;
}
static int F_56 ( void * V_14 )
{
struct V_116 * V_117 = V_14 ;
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_25 * V_3 = V_2 -> V_3 ;
T_4 V_118 ;
struct V_10 * V_11 ;
T_5 V_93 ;
F_57 ( & V_118 , V_119 ) ;
for (; ; ) {
F_58 ( & V_117 -> V_9 , & V_118 ) ;
F_59 ( V_120 ) ;
if ( F_60 () ) {
F_6 ( L_45 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_21 . V_121 ||
F_61 ( & V_3 -> V_59 ) ) ) ) {
F_6 ( L_46 ) ;
F_62 () ;
}
F_59 ( V_122 ) ;
F_63 ( & V_117 -> V_9 , & V_118 ) ;
F_6 ( L_47 ) ;
F_64 ( & V_2 -> V_123 , V_93 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_65 ( & V_2 -> V_123 , V_93 ) ;
V_2 -> V_124 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_37 &&
! F_61 ( & V_3 -> V_59 ) ) {
F_65 ( & V_2 -> V_123 , V_93 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_78 ( V_2 ) ;
continue;
} else {
F_65 ( & V_2 -> V_123 , V_93 ) ;
}
if ( V_3 -> V_4 == V_37 )
continue;
if ( ! V_2 -> V_21 . V_121 )
continue;
V_11 = F_66 ( & V_3 -> V_59 ) ;
if ( V_11 ) {
if ( F_24 ( V_2 , V_11 ) )
V_2 -> V_21 . V_125 -> V_97 . V_126 ++ ;
else
V_2 -> V_21 . V_125 -> V_97 . V_127 += V_11 -> V_51 ;
F_7 ( V_11 ) ;
}
}
return 0 ;
}
int F_67 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = NULL ;
int V_28 ;
V_91 = F_68 () ;
if ( ! V_91 ) {
F_11 ( L_48 ) ;
goto V_128;
}
V_2 -> V_21 . V_125 = V_91 ;
F_69 ( V_91 , V_2 ) ;
V_91 -> V_129 = V_130 ;
V_91 -> V_131 = F_45 ;
V_91 -> V_132 = F_43 ;
V_91 -> V_133 = F_42 ;
V_91 -> V_134 = F_37 ;
V_91 -> V_135 = F_51 ;
V_91 -> V_136 = F_52 ;
V_91 -> V_44 = V_2 -> V_21 . V_44 ;
V_28 = F_70 ( V_91 ) ;
if ( V_28 < 0 ) {
F_11 ( L_49 ) ;
goto V_137;
}
#ifdef F_71
F_72 ( V_91 ) ;
#endif
return 0 ;
V_137:
F_73 ( V_91 ) ;
V_128:
F_74 ( V_2 -> V_8 . V_138 ) ;
F_34 ( V_2 ) ;
F_36 ( V_2 ) ;
return - V_55 ;
}
struct V_1 * F_75 ( void * V_65 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 ) {
F_11 ( L_50 ) ;
goto V_139;
}
V_2 -> V_3 = F_31 ( sizeof( * V_2 -> V_3 ) , V_88 ) ;
if ( ! V_2 -> V_3 ) {
F_11 ( L_51 ) ;
goto V_140;
}
F_28 ( V_2 ) ;
F_6 ( L_52 ) ;
V_2 -> V_8 . V_2 = V_2 ;
F_76 ( & V_2 -> V_123 ) ;
F_33 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_138 = F_77 ( F_56 ,
& V_2 -> V_8 , L_53 ) ;
if ( F_54 ( V_2 -> V_8 . V_138 ) )
goto V_141;
V_2 -> V_21 . V_65 = V_65 ;
V_2 -> V_21 . V_121 = true ;
return V_2 ;
V_141:
F_34 ( V_2 ) ;
V_140:
F_36 ( V_2 ) ;
V_139:
return NULL ;
}
int F_78 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
V_91 = V_2 -> V_21 . V_125 ;
F_2 ( & V_2 -> V_3 -> V_24 ) ;
F_2 ( & V_2 -> V_3 -> V_38 ) ;
F_74 ( V_2 -> V_8 . V_138 ) ;
#ifdef F_71
F_79 ( V_91 ) ;
#endif
F_80 ( V_91 ) ;
F_73 ( V_91 ) ;
V_2 -> V_21 . V_125 = NULL ;
F_34 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
