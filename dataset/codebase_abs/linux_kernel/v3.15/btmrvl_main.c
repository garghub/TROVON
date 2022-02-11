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
int F_18 ( struct V_1 * V_2 , int V_61 )
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
F_28 ( & V_2 -> V_3 -> V_58 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
F_29 ( & V_2 -> V_3 -> V_24 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_3 -> V_58 ) ;
F_32 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_33 ( struct V_78 * V_79 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_34 ( V_79 ) ;
F_6 ( L_29 , V_11 -> V_56 , V_11 -> V_50 ) ;
if ( ! F_35 ( V_80 , & V_79 -> V_81 ) ) {
F_11 ( L_30 , V_79 -> V_81 ) ;
F_36 ( L_31 , V_82 ,
V_11 -> V_14 , V_11 -> V_50 ) ;
return - V_83 ;
}
switch ( F_14 ( V_11 ) -> V_56 ) {
case V_84 :
V_79 -> V_85 . V_86 ++ ;
break;
case V_87 :
V_79 -> V_85 . V_88 ++ ;
break;
case V_89 :
V_79 -> V_85 . V_90 ++ ;
break;
}
F_37 ( & V_2 -> V_3 -> V_58 , V_11 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
return 0 ;
}
static int F_38 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_34 ( V_79 ) ;
F_31 ( & V_2 -> V_3 -> V_58 ) ;
return 0 ;
}
static int F_39 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_34 ( V_79 ) ;
if ( ! F_40 ( V_80 , & V_79 -> V_81 ) )
return 0 ;
F_31 ( & V_2 -> V_3 -> V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_78 * V_79 )
{
F_42 ( V_80 , & V_79 -> V_81 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
T_2 * V_14 , int V_50 )
{
int V_28 ;
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0x00 ;
V_14 [ 2 ] = 0x00 ;
V_14 [ 3 ] = V_50 ;
F_36 ( L_32 ,
V_82 , V_14 , V_91 + V_50 ) ;
V_28 = F_9 ( V_2 , V_92 , V_14 ,
V_91 + V_50 ) ;
if ( V_28 )
F_11 ( L_33 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
T_2 V_95 [ V_91 + V_96 ] ;
const char V_97 [] = L_34 ;
const char V_98 [] = L_35 ;
int V_28 ;
V_94 = F_45 ( NULL , V_97 ) ;
if ( ! V_94 )
return - V_99 ;
V_28 = F_46 ( V_94 , V_98 ,
V_95 + V_91 ,
V_96 ) ;
if ( V_28 )
return V_28 ;
F_6 ( L_36 ) ;
V_28 = F_43 ( V_2 , V_95 , V_96 ) ;
if ( V_28 ) {
F_11 ( L_37 ) ;
return V_28 ;
}
return 0 ;
}
static int F_47 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_34 ( V_79 ) ;
F_18 ( V_2 , V_39 ) ;
F_44 ( V_2 ) ;
V_2 -> V_21 . V_32 = 1 ;
F_20 ( V_2 ) ;
V_2 -> V_21 . V_63 = 0xffff ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_48 ( void * V_14 )
{
struct V_100 * V_101 = V_14 ;
struct V_1 * V_2 = V_101 -> V_2 ;
struct V_25 * V_3 = V_2 -> V_3 ;
T_3 V_102 ;
struct V_10 * V_11 ;
T_4 V_81 ;
F_49 ( & V_102 , V_103 ) ;
for (; ; ) {
F_50 ( & V_101 -> V_9 , & V_102 ) ;
F_51 ( V_104 ) ;
if ( F_52 () ) {
F_6 ( L_38 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_21 . V_105 ||
F_53 ( & V_3 -> V_58 ) ) ) ) {
F_6 ( L_39 ) ;
F_54 () ;
}
F_51 ( V_106 ) ;
F_55 ( & V_101 -> V_9 , & V_102 ) ;
F_6 ( L_40 ) ;
F_56 ( & V_2 -> V_107 , V_81 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_57 ( & V_2 -> V_107 , V_81 ) ;
V_2 -> V_108 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_37 &&
! F_53 ( & V_3 -> V_58 ) ) {
F_57 ( & V_2 -> V_107 , V_81 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_72 ( V_2 ) ;
continue;
} else {
F_57 ( & V_2 -> V_107 , V_81 ) ;
}
if ( V_3 -> V_4 == V_37 )
continue;
if ( ! V_2 -> V_21 . V_105 )
continue;
V_11 = F_58 ( & V_3 -> V_58 ) ;
if ( V_11 ) {
if ( F_23 ( V_2 , V_11 ) )
V_2 -> V_21 . V_109 -> V_85 . V_110 ++ ;
else
V_2 -> V_21 . V_109 -> V_85 . V_111 += V_11 -> V_50 ;
F_7 ( V_11 ) ;
}
}
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL ;
int V_28 ;
V_79 = F_60 () ;
if ( ! V_79 ) {
F_11 ( L_41 ) ;
goto V_112;
}
V_2 -> V_21 . V_109 = V_79 ;
F_61 ( V_79 , V_2 ) ;
V_79 -> V_113 = V_114 ;
V_79 -> V_115 = F_41 ;
V_79 -> V_116 = F_39 ;
V_79 -> V_117 = F_38 ;
V_79 -> V_118 = F_33 ;
V_79 -> V_119 = F_47 ;
V_79 -> V_43 = V_2 -> V_21 . V_43 ;
V_28 = F_62 ( V_79 ) ;
if ( V_28 < 0 ) {
F_11 ( L_42 ) ;
goto V_120;
}
#ifdef F_63
F_64 ( V_79 ) ;
#endif
return 0 ;
V_120:
F_65 ( V_79 ) ;
V_112:
F_66 ( V_2 -> V_8 . V_121 ) ;
F_30 ( V_2 ) ;
F_32 ( V_2 ) ;
return - V_54 ;
}
struct V_1 * F_67 ( void * V_122 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( sizeof( * V_2 ) , V_123 ) ;
if ( ! V_2 ) {
F_11 ( L_43 ) ;
goto V_124;
}
V_2 -> V_3 = F_68 ( sizeof( * V_2 -> V_3 ) , V_123 ) ;
if ( ! V_2 -> V_3 ) {
F_11 ( L_44 ) ;
goto V_125;
}
F_27 ( V_2 ) ;
F_6 ( L_45 ) ;
V_2 -> V_8 . V_2 = V_2 ;
F_69 ( & V_2 -> V_107 ) ;
F_29 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_121 = F_70 ( F_48 ,
& V_2 -> V_8 , L_46 ) ;
V_2 -> V_21 . V_122 = V_122 ;
V_2 -> V_21 . V_105 = true ;
return V_2 ;
V_125:
F_32 ( V_2 ) ;
V_124:
return NULL ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
V_79 = V_2 -> V_21 . V_109 ;
F_2 ( & V_2 -> V_3 -> V_24 ) ;
F_66 ( V_2 -> V_8 . V_121 ) ;
#ifdef F_63
F_72 ( V_79 ) ;
#endif
F_73 ( V_79 ) ;
F_65 ( V_79 ) ;
V_2 -> V_21 . V_109 = NULL ;
F_30 ( V_2 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
