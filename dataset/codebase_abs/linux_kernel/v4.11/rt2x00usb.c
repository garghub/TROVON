int F_1 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , const T_2 V_6 ,
void * V_7 , const T_2 V_8 ,
const int V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
int V_13 ;
unsigned int V_14 =
( V_4 == V_15 ) ?
F_3 ( V_11 , 0 ) : F_4 ( V_11 , 0 ) ;
unsigned long V_16 = V_17 + F_5 ( V_9 ) ;
if ( ! F_6 ( V_18 , & V_2 -> V_19 ) )
return - V_20 ;
do {
V_13 = F_7 ( V_11 , V_14 , V_3 , V_4 ,
V_6 , V_5 , V_7 , V_8 ,
V_9 / 2 ) ;
if ( V_13 >= 0 )
return 0 ;
if ( V_13 == - V_20 ) {
F_8 ( V_18 , & V_2 -> V_19 ) ;
break;
}
} while ( F_9 ( V_17 , V_16 ) );
F_10 ( V_2 ,
L_1 ,
V_3 , V_5 , V_13 ) ;
return V_13 ;
}
int F_11 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 , const int V_9 )
{
int V_13 ;
F_12 ( ! F_13 ( & V_2 -> V_21 ) ) ;
if ( F_14 ( ! V_2 -> V_22 . V_23 || V_8 > V_24 ) ) {
F_10 ( V_2 , L_2 ) ;
return - V_25 ;
}
if ( V_4 == V_26 )
memcpy ( V_2 -> V_22 . V_23 , V_7 , V_8 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 ,
V_5 , 0 , V_2 -> V_22 . V_23 ,
V_8 , V_9 ) ;
if ( ! V_13 && V_4 == V_15 )
memcpy ( V_7 , V_2 -> V_22 . V_23 , V_8 ) ;
return V_13 ;
}
int F_15 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 )
{
int V_13 = 0 ;
unsigned char * V_27 ;
T_2 V_28 , V_29 , V_30 ;
F_16 ( & V_2 -> V_21 ) ;
V_27 = ( char * ) V_7 ;
V_28 = V_5 ;
V_29 = V_8 ;
while ( V_29 && ! V_13 ) {
V_30 = F_17 ( T_2 , V_24 , V_29 ) ;
V_13 = F_11 ( V_2 , V_3 ,
V_4 , V_28 , V_27 ,
V_30 , V_31 ) ;
V_27 += V_30 ;
V_29 -= V_30 ;
V_28 += V_30 ;
}
F_18 ( & V_2 -> V_21 ) ;
return V_13 ;
}
int F_19 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
const struct V_32 V_33 ,
T_3 * V_34 )
{
unsigned int V_35 ;
if ( ! F_6 ( V_18 , & V_2 -> V_19 ) )
return - V_20 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
F_20 ( V_2 , V_5 , V_34 ) ;
if ( ! F_21 ( * V_34 , V_33 ) )
return 1 ;
F_22 ( V_37 ) ;
}
F_10 ( V_2 , L_3 ,
V_5 , * V_34 ) ;
* V_34 = ~ 0 ;
return 0 ;
}
static void F_23 ( struct V_38 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
if ( V_40 -> V_42 ( V_40 -> V_2 , V_38 -> V_13 , F_24 ( V_40 -> V_34 ) ) ) {
F_25 ( V_38 , V_40 -> V_2 -> V_43 ) ;
if ( F_26 ( V_38 , V_44 ) < 0 ) {
F_27 ( V_38 ) ;
F_28 ( V_40 ) ;
}
} else
F_28 ( V_40 ) ;
}
void F_29 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
bool (* V_42)( struct V_1 * , int , T_3 ) )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_38 * V_38 ;
struct V_39 * V_40 ;
V_40 = F_30 ( sizeof( * V_40 ) , V_44 ) ;
if ( ! V_40 )
return;
V_38 = F_31 ( 0 , V_44 ) ;
if ( ! V_38 ) {
F_28 ( V_40 ) ;
return;
}
V_40 -> V_2 = V_2 ;
V_40 -> V_42 = V_42 ;
V_40 -> V_45 . V_46 = V_15 ;
V_40 -> V_45 . V_47 = V_48 ;
V_40 -> V_45 . V_49 = 0 ;
V_40 -> V_45 . V_50 = F_32 ( V_5 ) ;
V_40 -> V_45 . V_51 = F_32 ( sizeof( T_3 ) ) ;
F_33 ( V_38 , V_11 , F_3 ( V_11 , 0 ) ,
( unsigned char * ) ( & V_40 -> V_45 ) , & V_40 -> V_34 , sizeof( V_40 -> V_34 ) ,
F_23 , V_40 ) ;
F_25 ( V_38 , V_2 -> V_43 ) ;
if ( F_26 ( V_38 , V_44 ) < 0 ) {
F_27 ( V_38 ) ;
F_28 ( V_40 ) ;
}
F_34 ( V_38 ) ;
}
static void F_35 ( struct V_52 * V_53 )
{
if ( F_6 ( V_54 , & V_53 -> V_19 ) )
F_36 ( V_53 , V_55 ) ;
else
F_36 ( V_53 , V_56 ) ;
}
static void F_37 ( struct V_57 * V_58 )
{
struct V_1 * V_2 =
F_38 ( V_58 , struct V_1 , V_59 ) ;
struct V_60 * V_61 ;
struct V_52 * V_53 ;
F_39 (rt2x00dev, queue) {
while ( ! F_40 ( V_61 ) ) {
V_53 = F_41 ( V_61 , V_62 ) ;
if ( F_6 ( V_63 , & V_53 -> V_19 ) ||
! F_6 ( V_64 , & V_53 -> V_19 ) )
break;
F_35 ( V_53 ) ;
}
}
}
static void F_42 ( struct V_38 * V_38 )
{
struct V_52 * V_53 = (struct V_52 * ) V_38 -> V_41 ;
struct V_1 * V_2 = V_53 -> V_61 -> V_2 ;
if ( ! F_6 ( V_63 , & V_53 -> V_19 ) )
return;
if ( V_38 -> V_13 )
F_43 ( V_54 , & V_53 -> V_19 ) ;
F_44 ( V_53 ) ;
if ( V_2 -> V_65 -> V_66 -> V_67 )
V_2 -> V_65 -> V_66 -> V_67 ( V_53 ) ;
if ( ! F_45 ( V_2 , V_68 ) ||
! F_46 ( & V_2 -> V_69 ) )
F_47 ( V_2 -> V_70 , & V_2 -> V_59 ) ;
}
static bool F_48 ( struct V_52 * V_53 , void * V_71 )
{
struct V_1 * V_2 = V_53 -> V_61 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_72 * V_73 = V_53 -> V_74 ;
T_3 V_75 ;
int V_13 ;
if ( ! F_49 ( V_76 , & V_53 -> V_19 ) ||
F_6 ( V_64 , & V_53 -> V_19 ) )
return false ;
V_75 = V_2 -> V_65 -> V_66 -> V_77 ( V_53 ) ;
V_13 = F_50 ( V_53 -> V_78 , V_75 ) ;
if ( F_14 ( V_13 ) ) {
F_51 ( V_2 , L_4 ) ;
F_43 ( V_54 , & V_53 -> V_19 ) ;
F_44 ( V_53 ) ;
return false ;
}
F_52 ( V_73 -> V_38 , V_11 ,
F_53 ( V_11 , V_53 -> V_61 -> V_79 ) ,
V_53 -> V_78 -> V_71 , V_75 ,
F_42 , V_53 ) ;
V_13 = F_26 ( V_73 -> V_38 , V_44 ) ;
if ( V_13 ) {
if ( V_13 == - V_20 )
F_8 ( V_18 , & V_2 -> V_19 ) ;
F_43 ( V_54 , & V_53 -> V_19 ) ;
F_44 ( V_53 ) ;
}
return false ;
}
static void F_54 ( struct V_57 * V_58 )
{
struct V_1 * V_2 =
F_38 ( V_58 , struct V_1 , V_80 ) ;
struct V_52 * V_53 ;
struct V_81 * V_82 ;
T_1 V_83 [ 32 ] ;
while ( ! F_40 ( V_2 -> V_84 ) ) {
V_53 = F_41 ( V_2 -> V_84 , V_62 ) ;
if ( F_6 ( V_63 , & V_53 -> V_19 ) ||
! F_6 ( V_64 , & V_53 -> V_19 ) )
break;
V_82 = F_55 ( V_53 -> V_78 ) ;
V_82 -> V_85 = V_83 ;
V_82 -> V_86 = V_53 -> V_61 -> V_87 ;
F_56 ( V_53 , V_88 ) ;
}
}
static void F_57 ( struct V_38 * V_38 )
{
struct V_52 * V_53 = (struct V_52 * ) V_38 -> V_41 ;
struct V_1 * V_2 = V_53 -> V_61 -> V_2 ;
if ( ! F_49 ( V_63 , & V_53 -> V_19 ) )
return;
F_44 ( V_53 ) ;
if ( V_38 -> V_89 < V_53 -> V_61 -> V_87 || V_38 -> V_13 )
F_43 ( V_54 , & V_53 -> V_19 ) ;
F_47 ( V_2 -> V_70 , & V_2 -> V_80 ) ;
}
static bool F_58 ( struct V_52 * V_53 , void * V_71 )
{
struct V_1 * V_2 = V_53 -> V_61 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_72 * V_73 = V_53 -> V_74 ;
int V_13 ;
if ( F_59 ( V_63 , & V_53 -> V_19 ) ||
F_6 ( V_64 , & V_53 -> V_19 ) )
return false ;
F_60 ( V_53 ) ;
F_52 ( V_73 -> V_38 , V_11 ,
F_61 ( V_11 , V_53 -> V_61 -> V_79 ) ,
V_53 -> V_78 -> V_71 , V_53 -> V_78 -> V_29 ,
F_57 , V_53 ) ;
V_13 = F_26 ( V_73 -> V_38 , V_44 ) ;
if ( V_13 ) {
if ( V_13 == - V_20 )
F_8 ( V_18 , & V_2 -> V_19 ) ;
F_43 ( V_54 , & V_53 -> V_19 ) ;
F_44 ( V_53 ) ;
}
return false ;
}
void F_62 ( struct V_60 * V_61 )
{
switch ( V_61 -> V_90 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
if ( ! F_40 ( V_61 ) )
F_63 ( V_61 ,
V_62 ,
V_95 ,
NULL ,
F_48 ) ;
break;
case V_96 :
if ( ! F_64 ( V_61 ) )
F_63 ( V_61 ,
V_95 ,
V_62 ,
NULL ,
F_58 ) ;
break;
default:
break;
}
}
static bool F_65 ( struct V_52 * V_53 , void * V_71 )
{
struct V_1 * V_2 = V_53 -> V_61 -> V_2 ;
struct V_72 * V_73 = V_53 -> V_74 ;
struct V_97 * V_98 = V_53 -> V_74 ;
if ( ! F_6 ( V_63 , & V_53 -> V_19 ) )
return false ;
F_66 ( V_73 -> V_38 ) ;
if ( ( V_53 -> V_61 -> V_90 == V_99 ) &&
( F_45 ( V_2 , V_100 ) ) )
F_66 ( V_98 -> V_101 ) ;
return false ;
}
void F_67 ( struct V_60 * V_61 , bool V_102 )
{
struct V_57 * V_103 ;
unsigned int V_35 ;
if ( V_102 )
F_63 ( V_61 , V_62 , V_95 , NULL ,
F_65 ) ;
switch ( V_61 -> V_90 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
V_103 = & V_61 -> V_2 -> V_59 ;
break;
case V_96 :
V_103 = & V_61 -> V_2 -> V_80 ;
break;
default:
return;
}
for ( V_35 = 0 ; V_35 < 10 ; V_35 ++ ) {
if ( F_40 ( V_61 ) )
break;
F_47 ( V_61 -> V_2 -> V_70 , V_103 ) ;
F_68 ( 50 ) ;
}
}
static void F_69 ( struct V_60 * V_61 )
{
F_51 ( V_61 -> V_2 , L_5 ,
V_61 -> V_90 ) ;
F_70 ( V_61 ) ;
F_71 ( V_61 , true ) ;
F_72 ( V_61 ) ;
}
static int F_73 ( struct V_60 * V_61 )
{
struct V_52 * V_53 ;
V_53 = F_41 ( V_61 , V_104 ) ;
return F_74 ( V_53 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
F_39 (rt2x00dev, queue) {
if ( ! F_40 ( V_61 ) ) {
if ( F_73 ( V_61 ) )
F_69 ( V_61 ) ;
}
}
}
void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 , V_105 , 0 , 0 ,
V_31 ) ;
}
void F_78 ( struct V_52 * V_53 )
{
V_53 -> V_19 = 0 ;
if ( V_53 -> V_61 -> V_90 == V_96 )
F_58 ( V_53 , NULL ) ;
}
static void F_79 ( struct V_60 * V_61 ,
struct V_106 * V_107 )
{
struct V_10 * V_11 = F_2 ( V_61 -> V_2 -> V_12 ) ;
int V_14 ;
V_61 -> V_79 = F_80 ( V_107 ) ;
if ( V_61 -> V_90 == V_96 ) {
V_14 = F_61 ( V_11 , V_61 -> V_79 ) ;
V_61 -> V_108 = V_108 ( V_11 , V_14 , 0 ) ;
} else {
V_14 = F_53 ( V_11 , V_61 -> V_79 ) ;
V_61 -> V_108 = V_108 ( V_11 , V_14 , 1 ) ;
}
if ( ! V_61 -> V_108 )
V_61 -> V_108 = 1 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_82 ( V_2 -> V_12 ) ;
struct V_111 * V_112 = V_110 -> V_113 ;
struct V_106 * V_107 ;
struct V_60 * V_61 = V_2 -> V_114 ;
struct V_106 * V_115 = NULL ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_112 -> V_85 . V_116 ; V_35 ++ ) {
V_107 = & V_112 -> V_117 [ V_35 ] . V_85 ;
if ( F_83 ( V_107 ) ) {
F_79 ( V_2 -> V_84 , V_107 ) ;
} else if ( F_84 ( V_107 ) &&
( V_61 != F_85 ( V_2 ) ) ) {
F_79 ( V_61 , V_107 ) ;
V_61 = F_86 ( V_61 ) ;
V_115 = V_107 ;
}
}
if ( ! V_2 -> V_84 -> V_79 || ! V_2 -> V_114 -> V_79 ) {
F_10 ( V_2 , L_6 ) ;
return - V_118 ;
}
F_87 (rt2x00dev, queue) {
if ( ! V_61 -> V_79 )
F_79 ( V_61 , V_115 ) ;
}
return 0 ;
}
static int F_88 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_72 * V_73 ;
struct V_97 * V_98 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_61 -> V_119 ; V_35 ++ ) {
V_73 = V_61 -> V_120 [ V_35 ] . V_74 ;
V_73 -> V_38 = F_31 ( 0 , V_88 ) ;
if ( ! V_73 -> V_38 )
return - V_25 ;
}
if ( V_61 -> V_90 != V_99 ||
! F_45 ( V_2 , V_100 ) )
return 0 ;
for ( V_35 = 0 ; V_35 < V_61 -> V_119 ; V_35 ++ ) {
V_98 = V_61 -> V_120 [ V_35 ] . V_74 ;
V_98 -> V_101 = F_31 ( 0 , V_88 ) ;
if ( ! V_98 -> V_101 )
return - V_25 ;
}
return 0 ;
}
static void F_89 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_72 * V_73 ;
struct V_97 * V_98 ;
unsigned int V_35 ;
if ( ! V_61 -> V_120 )
return;
for ( V_35 = 0 ; V_35 < V_61 -> V_119 ; V_35 ++ ) {
V_73 = V_61 -> V_120 [ V_35 ] . V_74 ;
F_66 ( V_73 -> V_38 ) ;
F_34 ( V_73 -> V_38 ) ;
}
if ( V_61 -> V_90 != V_99 ||
! F_45 ( V_2 , V_100 ) )
return;
for ( V_35 = 0 ; V_35 < V_61 -> V_119 ; V_35 ++ ) {
V_98 = V_61 -> V_120 [ V_35 ] . V_74 ;
F_66 ( V_98 -> V_101 ) ;
F_34 ( V_98 -> V_101 ) ;
}
}
int F_90 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
int V_13 ;
V_13 = F_81 ( V_2 ) ;
if ( V_13 )
goto exit;
F_91 (rt2x00dev, queue) {
V_13 = F_88 ( V_61 ) ;
if ( V_13 )
goto exit;
}
return 0 ;
exit:
F_92 ( V_2 ) ;
return V_13 ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
F_93 ( V_2 -> V_43 ) ;
F_94 ( & V_2 -> V_121 ) ;
F_95 ( & V_2 -> V_80 ) ;
F_95 ( & V_2 -> V_59 ) ;
F_91 (rt2x00dev, queue)
F_89 ( V_61 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_122 ) ;
V_2 -> V_122 = NULL ;
F_28 ( V_2 -> V_123 ) ;
V_2 -> V_123 = NULL ;
F_28 ( V_2 -> V_22 . V_23 ) ;
V_2 -> V_22 . V_23 = NULL ;
}
static int F_97 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_23 = F_98 ( V_24 , V_88 ) ;
if ( ! V_2 -> V_22 . V_23 )
goto exit;
V_2 -> V_123 = F_98 ( V_2 -> V_65 -> V_124 , V_88 ) ;
if ( ! V_2 -> V_123 )
goto exit;
V_2 -> V_122 = F_98 ( V_2 -> V_65 -> V_125 , V_88 ) ;
if ( ! V_2 -> V_122 )
goto exit;
return 0 ;
exit:
F_99 ( L_7 ) ;
F_96 ( V_2 ) ;
return - V_25 ;
}
int F_100 ( struct V_109 * V_126 ,
const struct V_127 * V_65 )
{
struct V_10 * V_11 = F_101 ( V_126 ) ;
struct V_128 * V_129 ;
struct V_1 * V_2 ;
int V_130 ;
V_11 = F_102 ( V_11 ) ;
F_103 ( V_11 ) ;
V_129 = F_104 ( sizeof( struct V_1 ) , V_65 -> V_129 ) ;
if ( ! V_129 ) {
F_99 ( L_8 ) ;
V_130 = - V_25 ;
goto V_131;
}
F_105 ( V_126 , V_129 ) ;
V_2 = V_129 -> V_132 ;
V_2 -> V_12 = & V_126 -> V_12 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_129 = V_129 ;
F_106 ( V_2 , V_133 ) ;
F_107 ( & V_2 -> V_80 , F_54 ) ;
F_107 ( & V_2 -> V_59 , F_37 ) ;
F_108 ( & V_2 -> V_121 , V_134 ,
V_135 ) ;
V_130 = F_97 ( V_2 ) ;
if ( V_130 )
goto V_136;
V_2 -> V_43 = F_109 ( & V_11 -> V_12 ,
sizeof( struct V_137 ) ,
V_88 ) ;
if ( ! V_2 -> V_43 ) {
V_130 = - V_25 ;
goto V_138;
}
F_110 ( V_2 -> V_43 ) ;
V_130 = F_111 ( V_2 ) ;
if ( V_130 )
goto V_139;
return 0 ;
V_139:
F_93 ( V_2 -> V_43 ) ;
V_138:
F_96 ( V_2 ) ;
V_136:
F_112 ( V_129 ) ;
V_131:
F_113 ( V_11 ) ;
F_105 ( V_126 , NULL ) ;
return V_130 ;
}
void F_114 ( struct V_109 * V_126 )
{
struct V_128 * V_129 = F_115 ( V_126 ) ;
struct V_1 * V_2 = V_129 -> V_132 ;
F_116 ( V_2 ) ;
F_96 ( V_2 ) ;
F_112 ( V_129 ) ;
F_105 ( V_126 , NULL ) ;
F_113 ( F_101 ( V_126 ) ) ;
}
int F_117 ( struct V_109 * V_126 , T_4 V_140 )
{
struct V_128 * V_129 = F_115 ( V_126 ) ;
struct V_1 * V_2 = V_129 -> V_132 ;
return F_118 ( V_2 , V_140 ) ;
}
int F_119 ( struct V_109 * V_126 )
{
struct V_128 * V_129 = F_115 ( V_126 ) ;
struct V_1 * V_2 = V_129 -> V_132 ;
return F_120 ( V_2 ) ;
}
