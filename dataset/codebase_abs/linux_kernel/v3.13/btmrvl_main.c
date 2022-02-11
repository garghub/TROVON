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
T_1 V_19 , V_20 , V_21 ;
V_18 = ( void * ) ( V_11 -> V_14 + V_22 ) ;
V_19 = F_4 ( V_18 -> V_19 ) ;
V_20 = F_5 ( V_19 ) ;
V_21 = F_6 ( V_19 ) ;
if ( V_2 -> V_23 . V_24 ) {
V_2 -> V_23 . V_24 = false ;
V_2 -> V_3 -> V_25 = true ;
F_2 ( & V_2 -> V_3 -> V_26 ) ;
}
if ( V_21 == V_27 ) {
F_7 ( L_1 ,
V_21 , V_20 ) ;
F_8 ( V_11 ) ;
return false ;
}
}
return true ;
}
int F_9 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_28 * V_3 = V_2 -> V_3 ;
struct V_29 * V_30 ;
int V_31 = 0 ;
V_30 = (struct V_29 * ) V_11 -> V_14 ;
if ( V_30 -> V_18 != 0xff ) {
F_7 ( L_2 , V_30 -> V_18 ) ;
V_31 = - V_32 ;
goto exit;
}
switch ( V_30 -> V_14 [ 0 ] ) {
case V_33 :
if ( ! V_30 -> V_14 [ 2 ] ) {
if ( V_30 -> V_14 [ 1 ] == V_34 )
V_3 -> V_35 = 1 ;
else
V_3 -> V_35 = 0 ;
F_7 ( L_3 ,
( V_3 -> V_35 ) ? L_4 : L_5 ) ;
} else {
F_7 ( L_6 ) ;
}
break;
case V_36 :
if ( ! V_30 -> V_14 [ 3 ] )
F_7 ( L_7 , V_30 -> V_14 [ 1 ] ,
V_30 -> V_14 [ 2 ] ) ;
else
F_7 ( L_8 ) ;
break;
case V_37 :
if ( ! V_30 -> V_14 [ 1 ] ) {
V_3 -> V_38 = V_39 ;
if ( V_3 -> V_35 )
V_3 -> V_4 = V_40 ;
F_7 ( L_9 ) ;
} else {
F_7 ( L_10 ) ;
}
break;
case V_41 :
if ( V_2 -> V_23 . V_24 &&
V_30 -> V_14 [ 1 ] == V_42 ) {
F_7 ( L_11 ,
( ( V_30 -> V_14 [ 2 ] == V_43 ) ||
( V_30 -> V_14 [ 2 ] == V_44 ) ) ?
L_12 : L_13 ) ;
if ( V_30 -> V_45 > 3 && V_30 -> V_14 [ 3 ] )
V_2 -> V_23 . V_46 = V_47 ;
else
V_2 -> V_23 . V_46 = V_48 ;
F_7 ( L_14 , V_2 -> V_23 . V_46 ) ;
} else if ( V_2 -> V_23 . V_24 &&
V_30 -> V_14 [ 1 ] == V_49 ) {
F_7 ( L_11 , ( V_30 -> V_14 [ 2 ] ) ?
L_15 : L_16 ) ;
} else {
F_7 ( L_17 ) ;
V_31 = - V_32 ;
}
break;
case V_50 :
if ( V_30 -> V_14 [ 1 ] == V_51 )
V_3 -> V_4 = V_40 ;
F_7 ( L_11 ,
( V_3 -> V_4 ) ? L_18 : L_19 ) ;
break;
default:
F_7 ( L_20 , V_30 -> V_14 [ 0 ] ) ;
V_31 = - V_32 ;
break;
}
exit:
if ( ! V_31 )
F_8 ( V_11 ) ;
return V_31 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_52 ,
const void * V_53 , T_2 V_54 )
{
struct V_10 * V_11 ;
struct V_55 * V_13 ;
V_11 = F_11 ( V_56 + V_54 , V_57 ) ;
if ( V_11 == NULL ) {
F_12 ( L_21 ) ;
return - V_58 ;
}
V_13 = (struct V_55 * ) F_13 ( V_11 , V_56 ) ;
V_13 -> V_19 = F_14 ( F_15 ( V_27 , V_52 ) ) ;
V_13 -> V_59 = V_54 ;
if ( V_54 )
memcpy ( F_13 ( V_11 , V_54 ) , V_53 , V_54 ) ;
F_16 ( V_11 ) -> V_60 = V_61 ;
F_17 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
V_2 -> V_23 . V_24 = true ;
V_2 -> V_3 -> V_25 = false ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
if ( ! F_18 ( V_2 -> V_3 -> V_26 ,
V_2 -> V_3 -> V_25 ,
F_19 ( V_63 ) ) )
return - V_64 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_65 )
{
int V_31 ;
V_31 = F_10 ( V_2 , V_41 , & V_65 , 1 ) ;
if ( V_31 )
F_12 ( L_22 , V_65 ) ;
return V_31 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_53 [ 2 ] ;
V_53 [ 0 ] = ( V_2 -> V_23 . V_66 & 0xff00 ) >> 8 ;
V_53 [ 1 ] = ( T_2 ) ( V_2 -> V_23 . V_66 & 0x00ff ) ;
F_7 ( L_23 ,
V_53 [ 0 ] , V_53 [ 1 ] ) ;
V_31 = F_10 ( V_2 , V_36 , V_53 , 2 ) ;
if ( V_31 )
F_12 ( L_24 ) ;
return V_31 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_31 ;
T_2 V_53 ;
if ( V_2 -> V_23 . V_35 )
V_53 = V_34 ;
else
V_53 = V_67 ;
V_31 = F_10 ( V_2 , V_33 , & V_53 , 1 ) ;
if ( V_31 )
F_12 ( L_25 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_10 ( V_2 , V_37 , NULL , 0 ) ;
if ( V_31 )
F_12 ( L_26 ) ;
return V_31 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
if ( V_2 -> V_23 . V_68 ) {
V_2 -> V_23 . V_68 = 0 ;
F_21 ( V_2 ) ;
}
if ( V_2 -> V_23 . V_69 ) {
V_2 -> V_23 . V_69 = 0 ;
F_22 ( V_2 ) ;
}
if ( V_2 -> V_23 . V_70 ) {
V_2 -> V_23 . V_70 = 0 ;
if ( V_2 -> V_23 . V_71 ) {
V_31 = F_23 ( V_2 ) ;
} else {
V_31 = V_2 -> V_72 ( V_2 ) ;
V_2 -> V_3 -> V_38 = V_73 ;
}
}
return V_31 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_31 = 0 ;
if ( ! V_11 || ! V_11 -> V_14 )
return - V_32 ;
if ( ! V_11 -> V_54 || ( ( V_11 -> V_54 + V_74 ) > V_75 ) ) {
F_12 ( L_27 ,
V_11 -> V_54 , V_75 ) ;
return - V_32 ;
}
if ( F_26 ( V_11 ) < V_74 ) {
struct V_10 * V_76 = V_11 ;
V_11 = F_27 ( V_11 , V_74 ) ;
if ( ! V_11 ) {
F_12 ( L_28 ,
V_74 ) ;
V_11 = V_76 ;
return - V_32 ;
}
F_8 ( V_76 ) ;
}
F_28 ( V_11 , V_74 ) ;
V_11 -> V_14 [ 0 ] = ( V_11 -> V_54 & 0x0000ff ) ;
V_11 -> V_14 [ 1 ] = ( V_11 -> V_54 & 0x00ff00 ) >> 8 ;
V_11 -> V_14 [ 2 ] = ( V_11 -> V_54 & 0xff0000 ) >> 16 ;
V_11 -> V_14 [ 3 ] = F_16 ( V_11 ) -> V_60 ;
if ( V_2 -> V_77 )
V_31 = V_2 -> V_77 ( V_2 , V_11 -> V_14 , V_11 -> V_54 ) ;
return V_31 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_3 -> V_62 ) ;
V_2 -> V_3 -> V_4 = V_5 ;
F_31 ( & V_2 -> V_3 -> V_26 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_3 -> V_62 ) ;
F_34 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_35 ( struct V_78 * V_79 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_36 ( V_79 ) ;
F_7 ( L_29 , V_11 -> V_60 , V_11 -> V_54 ) ;
if ( ! F_37 ( V_80 , & V_79 -> V_81 ) ) {
F_12 ( L_30 , V_79 -> V_81 ) ;
F_38 ( L_31 , V_82 ,
V_11 -> V_14 , V_11 -> V_54 ) ;
return - V_83 ;
}
switch ( F_16 ( V_11 ) -> V_60 ) {
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
F_39 ( & V_2 -> V_3 -> V_62 , V_11 ) ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
return 0 ;
}
static int F_40 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_36 ( V_79 ) ;
F_33 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_41 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_36 ( V_79 ) ;
if ( ! F_42 ( V_80 , & V_79 -> V_81 ) )
return 0 ;
F_33 ( & V_2 -> V_3 -> V_62 ) ;
return 0 ;
}
static int F_43 ( struct V_78 * V_79 )
{
F_44 ( V_80 , & V_79 -> V_81 ) ;
return 0 ;
}
static int F_45 ( const T_2 * V_91 , T_3 V_54 , T_2 * V_92 , T_3 V_93 )
{
const T_2 * V_94 = V_91 ;
T_2 * V_95 = V_92 ;
int V_31 ;
T_2 V_76 [ 3 ] ;
V_76 [ 2 ] = '\0' ;
while ( ( V_94 - V_91 ) <= V_54 - 2 ) {
if ( isspace ( * V_94 ) ) {
V_94 ++ ;
continue;
}
if ( isxdigit ( * V_94 ) ) {
if ( ( V_95 - V_92 ) >= V_93 ) {
F_12 ( L_32 ) ;
return - V_32 ;
}
memcpy ( V_76 , V_94 , 2 ) ;
V_31 = F_46 ( V_76 , 16 , V_95 ++ ) ;
if ( V_31 < 0 )
return V_31 ;
V_94 += 2 ;
} else {
return - V_32 ;
}
}
if ( V_95 == V_92 )
return - V_32 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
T_2 * V_96 )
{
int V_97 , V_31 ;
T_2 V_14 [ V_98 ] ;
V_14 [ 0 ] = 0x00 ;
V_14 [ 1 ] = 0x00 ;
V_14 [ 2 ] = 0x00 ;
V_14 [ 3 ] = V_98 - 4 ;
for ( V_97 = 4 ; V_97 < V_98 ; V_97 ++ )
V_14 [ V_97 ] = V_96 [ ( V_97 / 4 ) * 8 - 1 - V_97 ] ;
F_38 ( L_33 ,
V_82 , V_14 , V_98 ) ;
V_31 = F_10 ( V_2 , V_99 , V_14 ,
V_98 ) ;
if ( V_31 )
F_12 ( L_34 ) ;
return 0 ;
}
static int
F_48 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_100 )
{
T_2 V_101 [ V_102 ] ;
int V_31 ;
V_31 = F_45 ( V_14 , V_100 , V_101 , sizeof( V_101 ) ) ;
if ( V_31 )
return V_31 ;
V_31 = F_47 ( V_2 , V_101 ) ;
if ( V_31 ) {
F_12 ( L_35 ) ;
return V_31 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
const struct V_103 * V_104 ;
int V_31 ;
const char * V_101 = V_2 -> V_23 . V_101 ;
if ( ! V_101 )
return 0 ;
V_31 = F_50 ( & V_104 , V_101 , V_2 -> V_23 . V_105 ) ;
if ( V_31 < 0 ) {
F_7 ( L_36 ,
V_101 ) ;
return 0 ;
}
V_31 = F_48 ( V_2 , ( T_2 * ) V_104 -> V_14 , V_104 -> V_100 ) ;
F_51 ( V_104 ) ;
return V_31 ;
}
static int F_52 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_36 ( V_79 ) ;
F_20 ( V_2 , V_42 ) ;
if ( F_49 ( V_2 ) )
F_12 ( L_37 ) ;
V_2 -> V_23 . V_35 = 1 ;
F_22 ( V_2 ) ;
V_2 -> V_23 . V_66 = 0xffff ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_53 ( void * V_14 )
{
struct V_106 * V_107 = V_14 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_28 * V_3 = V_2 -> V_3 ;
T_4 V_108 ;
struct V_10 * V_11 ;
T_5 V_81 ;
F_54 ( & V_108 , V_109 ) ;
for (; ; ) {
F_55 ( & V_107 -> V_9 , & V_108 ) ;
F_56 ( V_110 ) ;
if ( F_57 () ) {
F_7 ( L_38 ) ;
break;
}
if ( V_3 -> V_6 ||
( ( ! V_3 -> V_7 ) &&
( ! V_2 -> V_23 . V_111 ||
F_58 ( & V_3 -> V_62 ) ) ) ) {
F_7 ( L_39 ) ;
F_59 () ;
}
F_56 ( V_112 ) ;
F_60 ( & V_107 -> V_9 , & V_108 ) ;
F_7 ( L_40 ) ;
F_61 ( & V_2 -> V_113 , V_81 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
F_62 ( & V_2 -> V_113 , V_81 ) ;
V_2 -> V_114 ( V_2 ) ;
} else if ( V_3 -> V_4 == V_40 &&
! F_58 ( & V_3 -> V_62 ) ) {
F_62 ( & V_2 -> V_113 , V_81 ) ;
V_3 -> V_6 ++ ;
V_2 -> V_72 ( V_2 ) ;
continue;
} else {
F_62 ( & V_2 -> V_113 , V_81 ) ;
}
if ( V_3 -> V_4 == V_40 )
continue;
if ( ! V_2 -> V_23 . V_111 )
continue;
V_11 = F_63 ( & V_3 -> V_62 ) ;
if ( V_11 ) {
if ( F_25 ( V_2 , V_11 ) )
V_2 -> V_23 . V_115 -> V_85 . V_116 ++ ;
else
V_2 -> V_23 . V_115 -> V_85 . V_117 += V_11 -> V_54 ;
F_8 ( V_11 ) ;
}
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL ;
int V_31 ;
V_79 = F_65 () ;
if ( ! V_79 ) {
F_12 ( L_41 ) ;
goto V_118;
}
V_2 -> V_23 . V_115 = V_79 ;
F_66 ( V_79 , V_2 ) ;
V_79 -> V_119 = V_120 ;
V_79 -> V_121 = F_43 ;
V_79 -> V_122 = F_41 ;
V_79 -> V_123 = F_40 ;
V_79 -> V_124 = F_35 ;
V_79 -> V_125 = F_52 ;
V_79 -> V_46 = V_2 -> V_23 . V_46 ;
V_31 = F_67 ( V_79 ) ;
if ( V_31 < 0 ) {
F_12 ( L_42 ) ;
goto V_126;
}
#ifdef F_68
F_69 ( V_79 ) ;
#endif
return 0 ;
V_126:
F_70 ( V_79 ) ;
V_118:
F_71 ( V_2 -> V_8 . V_127 ) ;
F_32 ( V_2 ) ;
F_34 ( V_2 ) ;
return - V_58 ;
}
struct V_1 * F_72 ( void * V_128 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 ) {
F_12 ( L_43 ) ;
goto V_130;
}
V_2 -> V_3 = F_73 ( sizeof( * V_2 -> V_3 ) , V_129 ) ;
if ( ! V_2 -> V_3 ) {
F_12 ( L_44 ) ;
goto V_131;
}
F_29 ( V_2 ) ;
F_7 ( L_45 ) ;
V_2 -> V_8 . V_2 = V_2 ;
F_74 ( & V_2 -> V_113 ) ;
F_31 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_127 = F_75 ( F_53 ,
& V_2 -> V_8 , L_46 ) ;
V_2 -> V_23 . V_128 = V_128 ;
V_2 -> V_23 . V_111 = true ;
return V_2 ;
V_131:
F_34 ( V_2 ) ;
V_130:
return NULL ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
V_79 = V_2 -> V_23 . V_115 ;
F_2 ( & V_2 -> V_3 -> V_26 ) ;
F_71 ( V_2 -> V_8 . V_127 ) ;
#ifdef F_68
F_77 ( V_79 ) ;
#endif
F_78 ( V_79 ) ;
F_70 ( V_79 ) ;
V_2 -> V_23 . V_115 = NULL ;
F_32 ( V_2 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
