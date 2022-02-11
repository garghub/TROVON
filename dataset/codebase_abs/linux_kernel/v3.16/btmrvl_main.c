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
F_6 ( L_9 ) ;
} else {
F_6 ( L_10 ) ;
}
break;
case V_38 :
if ( V_2 -> V_21 . V_22 &&
V_27 -> V_14 [ 1 ] == V_39 ) {
F_6 ( L_11 ,
( ( V_27 -> V_14 [ 2 ] == V_40 ) ||
( V_27 -> V_14 [ 2 ] == V_41 ) ) ?
L_12 : L_13 ) ;
if ( V_27 -> V_42 > 3 && V_27 -> V_14 [ 3 ] )
V_2 -> V_21 . V_43 = V_44 ;
else
V_2 -> V_21 . V_43 = V_45 ;
F_6 ( L_14 , V_2 -> V_21 . V_43 ) ;
} else if ( V_2 -> V_21 . V_22 &&
V_27 -> V_14 [ 1 ] == V_46 ) {
F_6 ( L_11 , ( V_27 -> V_14 [ 2 ] ) ?
L_15 : L_16 ) ;
} else {
F_6 ( L_17 ) ;
V_28 = - V_29 ;
}
break;
case V_47 :
if ( V_27 -> V_14 [ 1 ] == V_48 )
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
const void * V_49 , T_2 V_50 )
{
struct V_10 * V_11 ;
struct V_51 * V_13 ;
V_11 = F_10 ( V_52 + V_50 , V_53 ) ;
if ( V_11 == NULL ) {
F_11 ( L_21 ) ;
return - V_54 ;
}
V_13 = (struct V_51 * ) F_12 ( V_11 , V_52 ) ;
V_13 -> V_19 = F_13 ( V_19 ) ;
V_13 -> V_55 = V_50 ;
if ( V_50 )
memcpy ( F_12 ( V_11 , V_50 ) , V_49 , V_50 ) ;
F_14 ( V_11 ) -> V_56 = V_57 ;
F_15 ( & V_2 -> V_3 -> V_58 , V_11 ) ;
V_2 -> V_21 . V_22 = true ;
V_2 -> V_3 -> V_23 = false ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_16 ( V_2 -> V_3 -> V_24 ,
V_2 -> V_3 -> V_23 ,
F_17 ( V_59 ) ) )
return - V_60 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_61 )
{
int V_28 ;
V_28 = F_9 ( V_2 , V_62 , & V_61 , 1 ) ;
if ( V_28 )
F_11 ( L_22 , V_61 ) ;
return V_28 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_28 ;
T_2 V_49 [ 2 ] ;
V_49 [ 0 ] = ( V_2 -> V_21 . V_63 & 0xff00 ) >> 8 ;
V_49 [ 1 ] = ( T_2 ) ( V_2 -> V_21 . V_63 & 0x00ff ) ;
F_6 ( L_23 ,
V_49 [ 0 ] , V_49 [ 1 ] ) ;
V_28 = F_9 ( V_2 , V_64 , V_49 , 2 ) ;
if ( V_28 )
F_11 ( L_24 ) ;
return V_28 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_28 ;
T_2 V_49 ;
if ( V_2 -> V_21 . V_32 )
V_49 = V_31 ;
else
V_49 = V_65 ;
V_28 = F_9 ( V_2 , V_66 , & V_49 , 1 ) ;
if ( V_28 )
F_11 ( L_25 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_28 ;
V_28 = F_9 ( V_2 , V_67 , NULL , 0 ) ;
if ( V_28 )
F_11 ( L_26 ) ;
return V_28 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_28 = 0 ;
if ( V_2 -> V_21 . V_68 ) {
V_2 -> V_21 . V_68 = 0 ;
F_19 ( V_2 ) ;
}
if ( V_2 -> V_21 . V_69 ) {
V_2 -> V_21 . V_69 = 0 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_21 . V_70 ) {
V_2 -> V_21 . V_70 = 0 ;
if ( V_2 -> V_21 . V_71 ) {
V_28 = F_21 ( V_2 ) ;
} else {
V_28 = V_2 -> V_72 ( V_2 ) ;
V_2 -> V_3 -> V_35 = V_73 ;
}
}
return V_28 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_28 = 0 ;
if ( ! V_11 || ! V_11 -> V_14 )
return - V_29 ;
if ( ! V_11 -> V_50 || ( ( V_11 -> V_50 + V_74 ) > V_75 ) ) {
F_11 ( L_27 ,
V_11 -> V_50 , V_75 ) ;
return - V_29 ;
}
if ( F_24 ( V_11 ) < V_74 ) {
struct V_10 * V_76 = V_11 ;
V_11 = F_25 ( V_11 , V_74 ) ;
if ( ! V_11 ) {
F_11 ( L_28 ,
V_74 ) ;
V_11 = V_76 ;
return - V_29 ;
}
F_7 ( V_76 ) ;
}
F_26 ( V_11 , V_74 ) ;
V_11 -> V_14 [ 0 ] = ( V_11 -> V_50 & 0x0000ff ) ;
V_11 -> V_14 [ 1 ] = ( V_11 -> V_50 & 0x00ff00 ) >> 8 ;
V_11 -> V_14 [ 2 ] = ( V_11 -> V_50 & 0xff0000 ) >> 16 ;
V_11 -> V_14 [ 3 ] = F_14 ( V_11 ) -> V_56 ;
if ( V_2 -> V_77 )
V_28 = V_2 -> V_77 ( V_2 , V_11 -> V_14 , V_11 -> V_50 ) ;
return V_28 ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_78 ;
F_28 ( & V_2 -> V_3 -> V_58 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
V_78 = F_29 ( V_79 , V_80 ) ;
V_2 -> V_3 -> V_81 = F_30 ( V_78 , V_82 ) ;
if ( ! V_2 -> V_3 -> V_81 ) {
V_2 -> V_3 -> V_83 = NULL ;
F_11 ( L_29 ) ;
} else {
V_2 -> V_3 -> V_83 =
( T_2 * ) F_31 ( V_2 -> V_3 -> V_81 ,
V_80 ) ;
F_6 ( L_30 ,
V_2 -> V_3 -> V_81 , V_2 -> V_3 -> V_83 ) ;
}
F_32 ( & V_2 -> V_3 -> V_24 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_3 -> V_58 ) ;
F_35 ( V_2 -> V_3 -> V_81 ) ;
F_35 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_36 ( struct V_84 * V_85 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_37 ( V_85 ) ;
F_6 ( L_31 , V_11 -> V_56 , V_11 -> V_50 ) ;
if ( ! F_38 ( V_86 , & V_85 -> V_87 ) ) {
F_11 ( L_32 , V_85 -> V_87 ) ;
F_39 ( L_33 , V_88 ,
V_11 -> V_14 , V_11 -> V_50 ) ;
return - V_89 ;
}
switch ( F_14 ( V_11 ) -> V_56 ) {
case V_90 :
V_85 -> V_91 . V_92 ++ ;
break;
case V_93 :
V_85 -> V_91 . V_94 ++ ;
break;
case V_95 :
V_85 -> V_91 . V_96 ++ ;
break;
}
F_40 ( & V_2 -> V_3 -> V_58 , V_11 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
return 0 ;
}
static int F_41 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_37 ( V_85 ) ;
F_34 ( & V_2 -> V_3 -> V_58 ) ;
return 0 ;
}
static int F_42 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_37 ( V_85 ) ;
if ( ! F_43 ( V_86 , & V_85 -> V_87 ) )
return 0 ;
F_34 ( & V_2 -> V_3 -> V_58 ) ;
return 0 ;
}
static int F_44 ( struct V_84 * V_85 )
{
F_45 ( V_86 , & V_85 -> V_87 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
T_2 * V_14 , int V_50 )
{
int V_28 ;
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0x00 ;
V_14 [ 2 ] = 0x00 ;
V_14 [ 3 ] = V_50 ;
F_39 ( L_34 ,
V_88 , V_14 , V_97 + V_50 ) ;
V_28 = F_9 ( V_2 , V_98 , V_14 ,
V_97 + V_50 ) ;
if ( V_28 )
F_11 ( L_35 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_99 * V_100 ;
T_2 V_101 [ V_97 + V_102 ] ;
const char V_103 [] = L_36 ;
const char V_104 [] = L_37 ;
int V_28 ;
V_100 = F_48 ( NULL , V_103 ) ;
if ( ! V_100 )
return - V_105 ;
V_28 = F_49 ( V_100 , V_104 ,
V_101 + V_97 ,
V_102 ) ;
if ( V_28 )
return V_28 ;
F_6 ( L_38 ) ;
V_28 = F_46 ( V_2 , V_101 , V_102 ) ;
if ( V_28 ) {
F_11 ( L_39 ) ;
return V_28 ;
}
return 0 ;
}
static int F_50 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_37 ( V_85 ) ;
F_18 ( V_2 , V_39 ) ;
F_47 ( V_2 ) ;
V_2 -> V_21 . V_32 = 1 ;
F_20 ( V_2 ) ;
V_2 -> V_21 . V_63 = 0xffff ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_51 ( void * V_14 )
{
struct V_106 * V_107 = V_14 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_25 * V_3 = V_2 -> V_3 ;
T_3 V_108 ;
struct V_10 * V_11 ;
T_4 V_87 ;
F_52 ( & V_108 , V_109 ) ;
for (; ; ) {
F_53 ( & V_107 -> V_9 , & V_108 ) ;
F_54 ( V_110 ) ;
if ( F_55 () ) {
F_6 ( L_40 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_21 . V_111 ||
F_56 ( & V_3 -> V_58 ) ) ) ) {
F_6 ( L_41 ) ;
F_57 () ;
}
F_54 ( V_112 ) ;
F_58 ( & V_107 -> V_9 , & V_108 ) ;
F_6 ( L_42 ) ;
F_59 ( & V_2 -> V_113 , V_87 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_60 ( & V_2 -> V_113 , V_87 ) ;
V_2 -> V_114 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_37 &&
! F_56 ( & V_3 -> V_58 ) ) {
F_60 ( & V_2 -> V_113 , V_87 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_72 ( V_2 ) ;
continue;
} else {
F_60 ( & V_2 -> V_113 , V_87 ) ;
}
if ( V_3 -> V_4 == V_37 )
continue;
if ( ! V_2 -> V_21 . V_111 )
continue;
V_11 = F_61 ( & V_3 -> V_58 ) ;
if ( V_11 ) {
if ( F_23 ( V_2 , V_11 ) )
V_2 -> V_21 . V_115 -> V_91 . V_116 ++ ;
else
V_2 -> V_21 . V_115 -> V_91 . V_117 += V_11 -> V_50 ;
F_7 ( V_11 ) ;
}
}
return 0 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = NULL ;
int V_28 ;
V_85 = F_63 () ;
if ( ! V_85 ) {
F_11 ( L_43 ) ;
goto V_118;
}
V_2 -> V_21 . V_115 = V_85 ;
F_64 ( V_85 , V_2 ) ;
V_85 -> V_119 = V_120 ;
V_85 -> V_121 = F_44 ;
V_85 -> V_122 = F_42 ;
V_85 -> V_123 = F_41 ;
V_85 -> V_124 = F_36 ;
V_85 -> V_125 = F_50 ;
V_85 -> V_43 = V_2 -> V_21 . V_43 ;
V_28 = F_65 ( V_85 ) ;
if ( V_28 < 0 ) {
F_11 ( L_44 ) ;
goto V_126;
}
#ifdef F_66
F_67 ( V_85 ) ;
#endif
return 0 ;
V_126:
F_68 ( V_85 ) ;
V_118:
F_69 ( V_2 -> V_8 . V_127 ) ;
F_33 ( V_2 ) ;
F_35 ( V_2 ) ;
return - V_54 ;
}
struct V_1 * F_70 ( void * V_128 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 ) {
F_11 ( L_45 ) ;
goto V_129;
}
V_2 -> V_3 = F_30 ( sizeof( * V_2 -> V_3 ) , V_82 ) ;
if ( ! V_2 -> V_3 ) {
F_11 ( L_46 ) ;
goto V_130;
}
F_27 ( V_2 ) ;
F_6 ( L_47 ) ;
V_2 -> V_8 . V_2 = V_2 ;
F_71 ( & V_2 -> V_113 ) ;
F_32 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_127 = F_72 ( F_51 ,
& V_2 -> V_8 , L_48 ) ;
V_2 -> V_21 . V_128 = V_128 ;
V_2 -> V_21 . V_111 = true ;
return V_2 ;
V_130:
F_35 ( V_2 ) ;
V_129:
return NULL ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
V_85 = V_2 -> V_21 . V_115 ;
F_2 ( & V_2 -> V_3 -> V_24 ) ;
F_69 ( V_2 -> V_8 . V_127 ) ;
#ifdef F_66
F_74 ( V_85 ) ;
#endif
F_75 ( V_85 ) ;
F_68 ( V_85 ) ;
V_2 -> V_21 . V_115 = NULL ;
F_33 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
