int F_1 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , const T_2 V_6 ,
void * V_7 , const T_2 V_8 ,
const int V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
int V_13 ;
unsigned int V_14 ;
unsigned int V_15 =
( V_4 == V_16 ) ?
F_3 ( V_11 , 0 ) : F_4 ( V_11 , 0 ) ;
if ( ! F_5 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
V_13 = F_6 ( V_11 , V_15 , V_3 , V_4 ,
V_6 , V_5 , V_7 , V_8 ,
V_9 ) ;
if ( V_13 >= 0 )
return 0 ;
else if ( V_13 == - V_19 ) {
F_7 ( V_17 , & V_2 -> V_18 ) ;
break;
}
}
if ( V_13 == - V_21 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_8 ( V_2 ,
L_1 ,
V_3 , V_5 , V_13 ) ;
return V_13 ;
}
int F_9 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 , const int V_9 )
{
int V_13 ;
F_10 ( ! F_11 ( & V_2 -> V_22 ) ) ;
if ( F_12 ( ! V_2 -> V_23 . V_24 || V_8 > V_25 ) ) {
F_8 ( V_2 , L_2 ) ;
return - V_26 ;
}
if ( V_4 == V_27 )
memcpy ( V_2 -> V_23 . V_24 , V_7 , V_8 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 ,
V_5 , 0 , V_2 -> V_23 . V_24 ,
V_8 , V_9 ) ;
if ( ! V_13 && V_4 == V_16 )
memcpy ( V_7 , V_2 -> V_23 . V_24 , V_8 ) ;
return V_13 ;
}
int F_13 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 , const int V_9 )
{
int V_13 = 0 ;
unsigned char * V_28 ;
T_2 V_29 , V_30 , V_31 ;
F_14 ( & V_2 -> V_22 ) ;
V_28 = ( char * ) V_7 ;
V_29 = V_5 ;
V_30 = V_8 ;
while ( V_30 && ! V_13 ) {
V_31 = F_15 ( T_2 , V_25 , V_30 ) ;
V_13 = F_9 ( V_2 , V_3 ,
V_4 , V_29 , V_28 ,
V_31 , V_9 ) ;
V_28 += V_31 ;
V_30 -= V_31 ;
V_29 += V_31 ;
}
F_16 ( & V_2 -> V_22 ) ;
return V_13 ;
}
int F_17 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
const struct V_32 V_33 ,
T_3 * V_34 )
{
unsigned int V_14 ;
if ( ! F_5 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
F_18 ( V_2 , V_5 , V_34 ) ;
if ( ! F_19 ( * V_34 , V_33 ) )
return 1 ;
F_20 ( V_35 ) ;
}
F_8 ( V_2 , L_3 ,
V_5 , * V_34 ) ;
* V_34 = ~ 0 ;
return 0 ;
}
static void F_21 ( struct V_36 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_39 ;
if ( V_38 -> V_40 ( V_38 -> V_2 , V_36 -> V_13 , F_22 ( V_38 -> V_34 ) ) ) {
if ( F_23 ( V_36 , V_41 ) < 0 )
F_24 ( V_38 ) ;
} else
F_24 ( V_38 ) ;
}
void F_25 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
bool (* V_40)( struct V_1 * , int , T_3 ) )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_36 * V_36 ;
struct V_37 * V_38 ;
V_38 = F_26 ( sizeof( * V_38 ) , V_41 ) ;
if ( ! V_38 )
return;
V_36 = F_27 ( 0 , V_41 ) ;
if ( ! V_36 ) {
F_24 ( V_38 ) ;
return;
}
V_38 -> V_2 = V_2 ;
V_38 -> V_40 = V_40 ;
V_38 -> V_42 . V_43 = V_16 ;
V_38 -> V_42 . V_44 = V_45 ;
V_38 -> V_42 . V_46 = 0 ;
V_38 -> V_42 . V_47 = F_28 ( V_5 ) ;
V_38 -> V_42 . V_48 = F_28 ( sizeof( T_3 ) ) ;
F_29 ( V_36 , V_11 , F_3 ( V_11 , 0 ) ,
( unsigned char * ) ( & V_38 -> V_42 ) , & V_38 -> V_34 , sizeof( V_38 -> V_34 ) ,
F_21 , V_38 ) ;
if ( F_23 ( V_36 , V_41 ) < 0 )
F_24 ( V_38 ) ;
F_30 ( V_36 ) ;
}
static void F_31 ( struct V_49 * V_50 )
{
if ( F_5 ( V_51 , & V_50 -> V_18 ) )
F_32 ( V_50 , V_52 ) ;
else
F_32 ( V_50 , V_53 ) ;
}
static void F_33 ( struct V_54 * V_55 )
{
struct V_1 * V_2 =
F_34 ( V_55 , struct V_1 , V_56 ) ;
struct V_57 * V_58 ;
struct V_49 * V_50 ;
F_35 (rt2x00dev, queue) {
while ( ! F_36 ( V_58 ) ) {
V_50 = F_37 ( V_58 , V_59 ) ;
if ( F_5 ( V_60 , & V_50 -> V_18 ) ||
! F_5 ( V_61 , & V_50 -> V_18 ) )
break;
F_31 ( V_50 ) ;
}
}
}
static void F_38 ( struct V_36 * V_36 )
{
struct V_49 * V_50 = (struct V_49 * ) V_36 -> V_39 ;
struct V_1 * V_2 = V_50 -> V_58 -> V_2 ;
if ( ! F_5 ( V_60 , & V_50 -> V_18 ) )
return;
if ( V_36 -> V_13 )
F_39 ( V_51 , & V_50 -> V_18 ) ;
F_40 ( V_50 ) ;
if ( V_2 -> V_62 -> V_63 -> V_64 )
V_2 -> V_62 -> V_63 -> V_64 ( V_50 ) ;
if ( ! F_5 ( V_65 , & V_2 -> V_66 ) ||
! F_41 ( & V_2 -> V_67 ) )
F_42 ( V_2 -> V_68 , & V_2 -> V_56 ) ;
}
static bool F_43 ( struct V_49 * V_50 , void * V_69 )
{
struct V_1 * V_2 = V_50 -> V_58 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_70 * V_71 = V_50 -> V_72 ;
T_3 V_73 ;
int V_13 ;
if ( ! F_44 ( V_74 , & V_50 -> V_18 ) ||
F_5 ( V_61 , & V_50 -> V_18 ) )
return false ;
V_73 = V_2 -> V_62 -> V_63 -> V_75 ( V_50 ) ;
V_13 = F_45 ( V_50 -> V_76 , V_73 ) ;
if ( F_12 ( V_13 ) ) {
F_46 ( V_2 , L_4 ) ;
F_39 ( V_51 , & V_50 -> V_18 ) ;
F_40 ( V_50 ) ;
return false ;
}
F_47 ( V_71 -> V_36 , V_11 ,
F_48 ( V_11 , V_50 -> V_58 -> V_77 ) ,
V_50 -> V_76 -> V_69 , V_73 ,
F_38 , V_50 ) ;
V_13 = F_23 ( V_71 -> V_36 , V_41 ) ;
if ( V_13 ) {
if ( V_13 == - V_19 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_39 ( V_51 , & V_50 -> V_18 ) ;
F_40 ( V_50 ) ;
}
return false ;
}
static void F_49 ( struct V_54 * V_55 )
{
struct V_1 * V_2 =
F_34 ( V_55 , struct V_1 , V_78 ) ;
struct V_49 * V_50 ;
struct V_79 * V_80 ;
T_1 V_81 [ 32 ] ;
while ( ! F_36 ( V_2 -> V_82 ) ) {
V_50 = F_37 ( V_2 -> V_82 , V_59 ) ;
if ( F_5 ( V_60 , & V_50 -> V_18 ) ||
! F_5 ( V_61 , & V_50 -> V_18 ) )
break;
V_80 = F_50 ( V_50 -> V_76 ) ;
V_80 -> V_83 = V_81 ;
V_80 -> V_84 = V_50 -> V_58 -> V_85 ;
F_51 ( V_50 , V_86 ) ;
}
}
static void F_52 ( struct V_36 * V_36 )
{
struct V_49 * V_50 = (struct V_49 * ) V_36 -> V_39 ;
struct V_1 * V_2 = V_50 -> V_58 -> V_2 ;
if ( ! F_44 ( V_60 , & V_50 -> V_18 ) )
return;
F_40 ( V_50 ) ;
if ( V_36 -> V_87 < V_50 -> V_58 -> V_85 || V_36 -> V_13 )
F_39 ( V_51 , & V_50 -> V_18 ) ;
F_42 ( V_2 -> V_68 , & V_2 -> V_78 ) ;
}
static bool F_53 ( struct V_49 * V_50 , void * V_69 )
{
struct V_1 * V_2 = V_50 -> V_58 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_70 * V_71 = V_50 -> V_72 ;
int V_13 ;
if ( F_54 ( V_60 , & V_50 -> V_18 ) ||
F_5 ( V_61 , & V_50 -> V_18 ) )
return false ;
F_55 ( V_50 ) ;
F_47 ( V_71 -> V_36 , V_11 ,
F_56 ( V_11 , V_50 -> V_58 -> V_77 ) ,
V_50 -> V_76 -> V_69 , V_50 -> V_76 -> V_30 ,
F_52 , V_50 ) ;
V_13 = F_23 ( V_71 -> V_36 , V_41 ) ;
if ( V_13 ) {
if ( V_13 == - V_19 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_39 ( V_51 , & V_50 -> V_18 ) ;
F_40 ( V_50 ) ;
}
return false ;
}
void F_57 ( struct V_57 * V_58 )
{
switch ( V_58 -> V_88 ) {
case V_89 :
case V_90 :
case V_91 :
case V_92 :
if ( ! F_36 ( V_58 ) )
F_58 ( V_58 ,
V_59 ,
V_93 ,
NULL ,
F_43 ) ;
break;
case V_94 :
if ( ! F_59 ( V_58 ) )
F_58 ( V_58 ,
V_93 ,
V_59 ,
NULL ,
F_53 ) ;
break;
default:
break;
}
}
static bool F_60 ( struct V_49 * V_50 , void * V_69 )
{
struct V_1 * V_2 = V_50 -> V_58 -> V_2 ;
struct V_70 * V_71 = V_50 -> V_72 ;
struct V_95 * V_96 = V_50 -> V_72 ;
if ( ! F_5 ( V_60 , & V_50 -> V_18 ) )
return false ;
F_61 ( V_71 -> V_36 ) ;
if ( ( V_50 -> V_58 -> V_88 == V_97 ) &&
( F_5 ( V_98 , & V_2 -> V_66 ) ) )
F_61 ( V_96 -> V_99 ) ;
return false ;
}
void F_62 ( struct V_57 * V_58 , bool V_100 )
{
struct V_54 * V_101 ;
unsigned int V_14 ;
if ( V_100 )
F_58 ( V_58 , V_59 , V_93 , NULL ,
F_60 ) ;
switch ( V_58 -> V_88 ) {
case V_89 :
case V_90 :
case V_91 :
case V_92 :
V_101 = & V_58 -> V_2 -> V_56 ;
break;
case V_94 :
V_101 = & V_58 -> V_2 -> V_78 ;
break;
default:
return;
}
for ( V_14 = 0 ; V_14 < 10 ; V_14 ++ ) {
if ( F_36 ( V_58 ) )
break;
F_42 ( V_58 -> V_2 -> V_68 , V_101 ) ;
F_63 ( 10 ) ;
}
}
static void F_64 ( struct V_57 * V_58 )
{
F_46 ( V_58 -> V_2 , L_5 ,
V_58 -> V_88 ) ;
F_65 ( V_58 ) ;
F_66 ( V_58 , true ) ;
F_67 ( V_58 ) ;
}
static int F_68 ( struct V_57 * V_58 )
{
struct V_49 * V_50 ;
V_50 = F_37 ( V_58 , V_102 ) ;
return F_69 ( V_50 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
F_35 (rt2x00dev, queue) {
if ( ! F_36 ( V_58 ) ) {
if ( F_68 ( V_58 ) )
F_64 ( V_58 ) ;
}
}
}
void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 , V_103 , 0 , 0 ,
V_104 ) ;
}
void F_73 ( struct V_49 * V_50 )
{
V_50 -> V_18 = 0 ;
if ( V_50 -> V_58 -> V_88 == V_94 )
F_53 ( V_50 , NULL ) ;
}
static void F_74 ( struct V_57 * V_58 ,
struct V_105 * V_106 )
{
struct V_10 * V_11 = F_2 ( V_58 -> V_2 -> V_12 ) ;
int V_15 ;
V_58 -> V_77 = F_75 ( V_106 ) ;
if ( V_58 -> V_88 == V_94 ) {
V_15 = F_56 ( V_11 , V_58 -> V_77 ) ;
V_58 -> V_107 = V_107 ( V_11 , V_15 , 0 ) ;
} else {
V_15 = F_48 ( V_11 , V_58 -> V_77 ) ;
V_58 -> V_107 = V_107 ( V_11 , V_15 , 1 ) ;
}
if ( ! V_58 -> V_107 )
V_58 -> V_107 = 1 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = F_77 ( V_2 -> V_12 ) ;
struct V_110 * V_111 = V_109 -> V_112 ;
struct V_105 * V_106 ;
struct V_57 * V_58 = V_2 -> V_113 ;
struct V_105 * V_114 = NULL ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_111 -> V_83 . V_115 ; V_14 ++ ) {
V_106 = & V_111 -> V_116 [ V_14 ] . V_83 ;
if ( F_78 ( V_106 ) ) {
F_74 ( V_2 -> V_82 , V_106 ) ;
} else if ( F_79 ( V_106 ) &&
( V_58 != F_80 ( V_2 ) ) ) {
F_74 ( V_58 , V_106 ) ;
V_58 = F_81 ( V_58 ) ;
V_114 = V_106 ;
}
}
if ( ! V_2 -> V_82 -> V_77 || ! V_2 -> V_113 -> V_77 ) {
F_8 ( V_2 , L_6 ) ;
return - V_117 ;
}
F_82 (rt2x00dev, queue) {
if ( ! V_58 -> V_77 )
F_74 ( V_58 , V_114 ) ;
}
return 0 ;
}
static int F_83 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_70 * V_71 ;
struct V_95 * V_96 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_58 -> V_118 ; V_14 ++ ) {
V_71 = V_58 -> V_119 [ V_14 ] . V_72 ;
V_71 -> V_36 = F_27 ( 0 , V_86 ) ;
if ( ! V_71 -> V_36 )
return - V_26 ;
}
if ( V_58 -> V_88 != V_97 ||
! F_5 ( V_98 , & V_2 -> V_66 ) )
return 0 ;
for ( V_14 = 0 ; V_14 < V_58 -> V_118 ; V_14 ++ ) {
V_96 = V_58 -> V_119 [ V_14 ] . V_72 ;
V_96 -> V_99 = F_27 ( 0 , V_86 ) ;
if ( ! V_96 -> V_99 )
return - V_26 ;
}
return 0 ;
}
static void F_84 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_70 * V_71 ;
struct V_95 * V_96 ;
unsigned int V_14 ;
if ( ! V_58 -> V_119 )
return;
for ( V_14 = 0 ; V_14 < V_58 -> V_118 ; V_14 ++ ) {
V_71 = V_58 -> V_119 [ V_14 ] . V_72 ;
F_61 ( V_71 -> V_36 ) ;
F_30 ( V_71 -> V_36 ) ;
}
if ( V_58 -> V_88 != V_97 ||
! F_5 ( V_98 , & V_2 -> V_66 ) )
return;
for ( V_14 = 0 ; V_14 < V_58 -> V_118 ; V_14 ++ ) {
V_96 = V_58 -> V_119 [ V_14 ] . V_72 ;
F_61 ( V_96 -> V_99 ) ;
F_30 ( V_96 -> V_99 ) ;
}
}
int F_85 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
int V_13 ;
V_13 = F_76 ( V_2 ) ;
if ( V_13 )
goto exit;
F_86 (rt2x00dev, queue) {
V_13 = F_83 ( V_58 ) ;
if ( V_13 )
goto exit;
}
return 0 ;
exit:
F_87 ( V_2 ) ;
return V_13 ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
F_86 (rt2x00dev, queue)
F_84 ( V_58 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
F_24 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
F_24 ( V_2 -> V_23 . V_24 ) ;
V_2 -> V_23 . V_24 = NULL ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_23 . V_24 = F_90 ( V_25 , V_86 ) ;
if ( ! V_2 -> V_23 . V_24 )
goto exit;
V_2 -> V_121 = F_90 ( V_2 -> V_62 -> V_122 , V_86 ) ;
if ( ! V_2 -> V_121 )
goto exit;
V_2 -> V_120 = F_90 ( V_2 -> V_62 -> V_123 , V_86 ) ;
if ( ! V_2 -> V_120 )
goto exit;
return 0 ;
exit:
F_91 ( L_7 ) ;
F_88 ( V_2 ) ;
return - V_26 ;
}
int F_92 ( struct V_108 * V_124 ,
const struct V_125 * V_62 )
{
struct V_10 * V_11 = F_93 ( V_124 ) ;
struct V_126 * V_127 ;
struct V_1 * V_2 ;
int V_128 ;
V_11 = F_94 ( V_11 ) ;
F_95 ( V_11 ) ;
V_127 = F_96 ( sizeof( struct V_1 ) , V_62 -> V_127 ) ;
if ( ! V_127 ) {
F_91 ( L_8 ) ;
V_128 = - V_26 ;
goto V_129;
}
F_97 ( V_124 , V_127 ) ;
V_2 = V_127 -> V_130 ;
V_2 -> V_12 = & V_124 -> V_12 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_127 = V_127 ;
F_98 ( V_2 , V_131 ) ;
F_99 ( & V_2 -> V_78 , F_49 ) ;
F_99 ( & V_2 -> V_56 , F_33 ) ;
F_100 ( & V_2 -> V_132 , V_133 ,
V_134 ) ;
V_128 = F_89 ( V_2 ) ;
if ( V_128 )
goto V_135;
V_128 = F_101 ( V_2 ) ;
if ( V_128 )
goto V_136;
return 0 ;
V_136:
F_88 ( V_2 ) ;
V_135:
F_102 ( V_127 ) ;
V_129:
F_103 ( V_11 ) ;
F_97 ( V_124 , NULL ) ;
return V_128 ;
}
void F_104 ( struct V_108 * V_124 )
{
struct V_126 * V_127 = F_105 ( V_124 ) ;
struct V_1 * V_2 = V_127 -> V_130 ;
F_106 ( V_2 ) ;
F_88 ( V_2 ) ;
F_102 ( V_127 ) ;
F_97 ( V_124 , NULL ) ;
F_103 ( F_93 ( V_124 ) ) ;
}
int F_107 ( struct V_108 * V_124 , T_4 V_137 )
{
struct V_126 * V_127 = F_105 ( V_124 ) ;
struct V_1 * V_2 = V_127 -> V_130 ;
return F_108 ( V_2 , V_137 ) ;
}
int F_109 ( struct V_108 * V_124 )
{
struct V_126 * V_127 = F_105 ( V_124 ) ;
struct V_1 * V_2 = V_127 -> V_130 ;
return F_110 ( V_2 ) ;
}
