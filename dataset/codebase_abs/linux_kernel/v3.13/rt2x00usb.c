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
F_10 ( ! F_11 ( & V_2 -> V_21 ) ) ;
if ( F_12 ( ! V_2 -> V_22 . V_23 || V_8 > V_24 ) ) {
F_8 ( V_2 , L_2 ) ;
return - V_25 ;
}
if ( V_4 == V_26 )
memcpy ( V_2 -> V_22 . V_23 , V_7 , V_8 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 ,
V_5 , 0 , V_2 -> V_22 . V_23 ,
V_8 , V_9 ) ;
if ( ! V_13 && V_4 == V_16 )
memcpy ( V_7 , V_2 -> V_22 . V_23 , V_8 ) ;
return V_13 ;
}
int F_13 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 , const int V_9 )
{
int V_13 = 0 ;
unsigned char * V_27 ;
T_2 V_28 , V_29 , V_30 ;
F_14 ( & V_2 -> V_21 ) ;
V_27 = ( char * ) V_7 ;
V_28 = V_5 ;
V_29 = V_8 ;
while ( V_29 && ! V_13 ) {
V_30 = F_15 ( T_2 , V_24 , V_29 ) ;
V_13 = F_9 ( V_2 , V_3 ,
V_4 , V_28 , V_27 ,
V_30 , V_9 ) ;
V_27 += V_30 ;
V_29 -= V_30 ;
V_28 += V_30 ;
}
F_16 ( & V_2 -> V_21 ) ;
return V_13 ;
}
int F_17 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
const struct V_31 V_32 ,
T_3 * V_33 )
{
unsigned int V_14 ;
if ( ! F_5 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
F_18 ( V_2 , V_5 , V_33 ) ;
if ( ! F_19 ( * V_33 , V_32 ) )
return 1 ;
F_20 ( V_34 ) ;
}
F_8 ( V_2 , L_3 ,
V_5 , * V_33 ) ;
* V_33 = ~ 0 ;
return 0 ;
}
static void F_21 ( struct V_35 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
if ( V_37 -> V_39 ( V_37 -> V_2 , V_35 -> V_13 , F_22 ( V_37 -> V_33 ) ) ) {
if ( F_23 ( V_35 , V_40 ) < 0 )
F_24 ( V_37 ) ;
} else
F_24 ( V_37 ) ;
}
void F_25 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
bool (* V_39)( struct V_1 * , int , T_3 ) )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
V_37 = F_26 ( sizeof( * V_37 ) , V_40 ) ;
if ( ! V_37 )
return;
V_35 = F_27 ( 0 , V_40 ) ;
if ( ! V_35 ) {
F_24 ( V_37 ) ;
return;
}
V_37 -> V_2 = V_2 ;
V_37 -> V_39 = V_39 ;
V_37 -> V_41 . V_42 = V_16 ;
V_37 -> V_41 . V_43 = V_44 ;
V_37 -> V_41 . V_45 = 0 ;
V_37 -> V_41 . V_46 = F_28 ( V_5 ) ;
V_37 -> V_41 . V_47 = F_28 ( sizeof( T_3 ) ) ;
F_29 ( V_35 , V_11 , F_3 ( V_11 , 0 ) ,
( unsigned char * ) ( & V_37 -> V_41 ) , & V_37 -> V_33 , sizeof( V_37 -> V_33 ) ,
F_21 , V_37 ) ;
if ( F_23 ( V_35 , V_40 ) < 0 )
F_24 ( V_37 ) ;
F_30 ( V_35 ) ;
}
static void F_31 ( struct V_48 * V_49 )
{
if ( F_5 ( V_50 , & V_49 -> V_18 ) )
F_32 ( V_49 , V_51 ) ;
else
F_32 ( V_49 , V_52 ) ;
}
static void F_33 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_34 ( V_54 , struct V_1 , V_55 ) ;
struct V_56 * V_57 ;
struct V_48 * V_49 ;
F_35 (rt2x00dev, queue) {
while ( ! F_36 ( V_57 ) ) {
V_49 = F_37 ( V_57 , V_58 ) ;
if ( F_5 ( V_59 , & V_49 -> V_18 ) ||
! F_5 ( V_60 , & V_49 -> V_18 ) )
break;
F_31 ( V_49 ) ;
}
}
}
static void F_38 ( struct V_35 * V_35 )
{
struct V_48 * V_49 = (struct V_48 * ) V_35 -> V_38 ;
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
if ( ! F_5 ( V_59 , & V_49 -> V_18 ) )
return;
if ( V_35 -> V_13 )
F_39 ( V_50 , & V_49 -> V_18 ) ;
F_40 ( V_49 ) ;
if ( V_2 -> V_61 -> V_62 -> V_63 )
V_2 -> V_61 -> V_62 -> V_63 ( V_49 ) ;
if ( ! F_5 ( V_64 , & V_2 -> V_65 ) ||
! F_41 ( & V_2 -> V_66 ) )
F_42 ( V_2 -> V_67 , & V_2 -> V_55 ) ;
}
static bool F_43 ( struct V_48 * V_49 , void * V_68 )
{
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_69 * V_70 = V_49 -> V_71 ;
T_3 V_72 ;
int V_13 ;
if ( ! F_44 ( V_73 , & V_49 -> V_18 ) ||
F_5 ( V_60 , & V_49 -> V_18 ) )
return false ;
V_72 = V_2 -> V_61 -> V_62 -> V_74 ( V_49 ) ;
V_13 = F_45 ( V_49 -> V_75 , V_72 ) ;
if ( F_12 ( V_13 ) ) {
F_46 ( V_2 , L_4 ) ;
F_39 ( V_50 , & V_49 -> V_18 ) ;
F_40 ( V_49 ) ;
return false ;
}
F_47 ( V_70 -> V_35 , V_11 ,
F_48 ( V_11 , V_49 -> V_57 -> V_76 ) ,
V_49 -> V_75 -> V_68 , V_72 ,
F_38 , V_49 ) ;
V_13 = F_23 ( V_70 -> V_35 , V_40 ) ;
if ( V_13 ) {
if ( V_13 == - V_19 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_39 ( V_50 , & V_49 -> V_18 ) ;
F_40 ( V_49 ) ;
}
return false ;
}
static void F_49 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_34 ( V_54 , struct V_1 , V_77 ) ;
struct V_48 * V_49 ;
struct V_78 * V_79 ;
T_1 V_80 [ 32 ] ;
while ( ! F_36 ( V_2 -> V_81 ) ) {
V_49 = F_37 ( V_2 -> V_81 , V_58 ) ;
if ( F_5 ( V_59 , & V_49 -> V_18 ) ||
! F_5 ( V_60 , & V_49 -> V_18 ) )
break;
V_79 = F_50 ( V_49 -> V_75 ) ;
V_79 -> V_82 = V_80 ;
V_79 -> V_83 = V_49 -> V_57 -> V_84 ;
F_51 ( V_49 , V_85 ) ;
}
}
static void F_52 ( struct V_35 * V_35 )
{
struct V_48 * V_49 = (struct V_48 * ) V_35 -> V_38 ;
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
if ( ! F_44 ( V_59 , & V_49 -> V_18 ) )
return;
F_40 ( V_49 ) ;
if ( V_35 -> V_86 < V_49 -> V_57 -> V_84 || V_35 -> V_13 )
F_39 ( V_50 , & V_49 -> V_18 ) ;
F_42 ( V_2 -> V_67 , & V_2 -> V_77 ) ;
}
static bool F_53 ( struct V_48 * V_49 , void * V_68 )
{
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_69 * V_70 = V_49 -> V_71 ;
int V_13 ;
if ( F_54 ( V_59 , & V_49 -> V_18 ) ||
F_5 ( V_60 , & V_49 -> V_18 ) )
return false ;
F_55 ( V_49 ) ;
F_47 ( V_70 -> V_35 , V_11 ,
F_56 ( V_11 , V_49 -> V_57 -> V_76 ) ,
V_49 -> V_75 -> V_68 , V_49 -> V_75 -> V_29 ,
F_52 , V_49 ) ;
V_13 = F_23 ( V_70 -> V_35 , V_40 ) ;
if ( V_13 ) {
if ( V_13 == - V_19 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_39 ( V_50 , & V_49 -> V_18 ) ;
F_40 ( V_49 ) ;
}
return false ;
}
void F_57 ( struct V_56 * V_57 )
{
switch ( V_57 -> V_87 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
if ( ! F_36 ( V_57 ) )
F_58 ( V_57 ,
V_58 ,
V_92 ,
NULL ,
F_43 ) ;
break;
case V_93 :
if ( ! F_59 ( V_57 ) )
F_58 ( V_57 ,
V_92 ,
V_58 ,
NULL ,
F_53 ) ;
break;
default:
break;
}
}
static bool F_60 ( struct V_48 * V_49 , void * V_68 )
{
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
struct V_69 * V_70 = V_49 -> V_71 ;
struct V_94 * V_95 = V_49 -> V_71 ;
if ( ! F_5 ( V_59 , & V_49 -> V_18 ) )
return false ;
F_61 ( V_70 -> V_35 ) ;
if ( ( V_49 -> V_57 -> V_87 == V_96 ) &&
( F_5 ( V_97 , & V_2 -> V_65 ) ) )
F_61 ( V_95 -> V_98 ) ;
return false ;
}
void F_62 ( struct V_56 * V_57 , bool V_99 )
{
struct V_53 * V_100 ;
unsigned int V_14 ;
if ( V_99 )
F_58 ( V_57 , V_58 , V_92 , NULL ,
F_60 ) ;
switch ( V_57 -> V_87 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
V_100 = & V_57 -> V_2 -> V_55 ;
break;
case V_93 :
V_100 = & V_57 -> V_2 -> V_77 ;
break;
default:
return;
}
for ( V_14 = 0 ; V_14 < 10 ; V_14 ++ ) {
if ( F_36 ( V_57 ) )
break;
F_42 ( V_57 -> V_2 -> V_67 , V_100 ) ;
F_63 ( 10 ) ;
}
}
static void F_64 ( struct V_56 * V_57 )
{
F_46 ( V_57 -> V_2 , L_5 ,
V_57 -> V_87 ) ;
F_65 ( V_57 ) ;
F_66 ( V_57 , true ) ;
F_67 ( V_57 ) ;
}
static int F_68 ( struct V_56 * V_57 )
{
struct V_48 * V_49 ;
V_49 = F_37 ( V_57 , V_101 ) ;
return F_69 ( V_49 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
F_35 (rt2x00dev, queue) {
if ( ! F_36 ( V_57 ) ) {
if ( F_68 ( V_57 ) )
F_64 ( V_57 ) ;
}
}
}
void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 , V_102 , 0 , 0 ,
V_103 ) ;
}
void F_73 ( struct V_48 * V_49 )
{
V_49 -> V_18 = 0 ;
if ( V_49 -> V_57 -> V_87 == V_93 )
F_53 ( V_49 , NULL ) ;
}
static void F_74 ( struct V_56 * V_57 ,
struct V_104 * V_105 )
{
struct V_10 * V_11 = F_2 ( V_57 -> V_2 -> V_12 ) ;
int V_15 ;
V_57 -> V_76 = F_75 ( V_105 ) ;
if ( V_57 -> V_87 == V_93 ) {
V_15 = F_56 ( V_11 , V_57 -> V_76 ) ;
V_57 -> V_106 = V_106 ( V_11 , V_15 , 0 ) ;
} else {
V_15 = F_48 ( V_11 , V_57 -> V_76 ) ;
V_57 -> V_106 = V_106 ( V_11 , V_15 , 1 ) ;
}
if ( ! V_57 -> V_106 )
V_57 -> V_106 = 1 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_107 * V_108 = F_77 ( V_2 -> V_12 ) ;
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_104 * V_105 ;
struct V_56 * V_57 = V_2 -> V_112 ;
struct V_104 * V_113 = NULL ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_110 -> V_82 . V_114 ; V_14 ++ ) {
V_105 = & V_110 -> V_115 [ V_14 ] . V_82 ;
if ( F_78 ( V_105 ) ) {
F_74 ( V_2 -> V_81 , V_105 ) ;
} else if ( F_79 ( V_105 ) &&
( V_57 != F_80 ( V_2 ) ) ) {
F_74 ( V_57 , V_105 ) ;
V_57 = F_81 ( V_57 ) ;
V_113 = V_105 ;
}
}
if ( ! V_2 -> V_81 -> V_76 || ! V_2 -> V_112 -> V_76 ) {
F_8 ( V_2 , L_6 ) ;
return - V_116 ;
}
F_82 (rt2x00dev, queue) {
if ( ! V_57 -> V_76 )
F_74 ( V_57 , V_113 ) ;
}
return 0 ;
}
static int F_83 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_69 * V_70 ;
struct V_94 * V_95 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_70 = V_57 -> V_118 [ V_14 ] . V_71 ;
V_70 -> V_35 = F_27 ( 0 , V_85 ) ;
if ( ! V_70 -> V_35 )
return - V_25 ;
}
if ( V_57 -> V_87 != V_96 ||
! F_5 ( V_97 , & V_2 -> V_65 ) )
return 0 ;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_95 = V_57 -> V_118 [ V_14 ] . V_71 ;
V_95 -> V_98 = F_27 ( 0 , V_85 ) ;
if ( ! V_95 -> V_98 )
return - V_25 ;
}
return 0 ;
}
static void F_84 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_69 * V_70 ;
struct V_94 * V_95 ;
unsigned int V_14 ;
if ( ! V_57 -> V_118 )
return;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_70 = V_57 -> V_118 [ V_14 ] . V_71 ;
F_61 ( V_70 -> V_35 ) ;
F_30 ( V_70 -> V_35 ) ;
}
if ( V_57 -> V_87 != V_96 ||
! F_5 ( V_97 , & V_2 -> V_65 ) )
return;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_95 = V_57 -> V_118 [ V_14 ] . V_71 ;
F_61 ( V_95 -> V_98 ) ;
F_30 ( V_95 -> V_98 ) ;
}
}
int F_85 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
int V_13 ;
V_13 = F_76 ( V_2 ) ;
if ( V_13 )
goto exit;
F_86 (rt2x00dev, queue) {
V_13 = F_83 ( V_57 ) ;
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
struct V_56 * V_57 ;
F_86 (rt2x00dev, queue)
F_84 ( V_57 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_119 ) ;
V_2 -> V_119 = NULL ;
F_24 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
F_24 ( V_2 -> V_22 . V_23 ) ;
V_2 -> V_22 . V_23 = NULL ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_23 = F_90 ( V_24 , V_85 ) ;
if ( ! V_2 -> V_22 . V_23 )
goto exit;
V_2 -> V_120 = F_90 ( V_2 -> V_61 -> V_121 , V_85 ) ;
if ( ! V_2 -> V_120 )
goto exit;
V_2 -> V_119 = F_90 ( V_2 -> V_61 -> V_122 , V_85 ) ;
if ( ! V_2 -> V_119 )
goto exit;
return 0 ;
exit:
F_91 ( L_7 ) ;
F_88 ( V_2 ) ;
return - V_25 ;
}
int F_92 ( struct V_107 * V_123 ,
const struct V_124 * V_61 )
{
struct V_10 * V_11 = F_93 ( V_123 ) ;
struct V_125 * V_126 ;
struct V_1 * V_2 ;
int V_127 ;
V_11 = F_94 ( V_11 ) ;
F_95 ( V_11 ) ;
V_126 = F_96 ( sizeof( struct V_1 ) , V_61 -> V_126 ) ;
if ( ! V_126 ) {
F_91 ( L_8 ) ;
V_127 = - V_25 ;
goto V_128;
}
F_97 ( V_123 , V_126 ) ;
V_2 = V_126 -> V_129 ;
V_2 -> V_12 = & V_123 -> V_12 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_126 = V_126 ;
F_98 ( V_2 , V_130 ) ;
F_99 ( & V_2 -> V_77 , F_49 ) ;
F_99 ( & V_2 -> V_55 , F_33 ) ;
F_100 ( & V_2 -> V_131 , V_132 ,
V_133 ) ;
V_127 = F_89 ( V_2 ) ;
if ( V_127 )
goto V_134;
V_127 = F_101 ( V_2 ) ;
if ( V_127 )
goto V_135;
return 0 ;
V_135:
F_88 ( V_2 ) ;
V_134:
F_102 ( V_126 ) ;
V_128:
F_103 ( V_11 ) ;
F_97 ( V_123 , NULL ) ;
return V_127 ;
}
void F_104 ( struct V_107 * V_123 )
{
struct V_125 * V_126 = F_105 ( V_123 ) ;
struct V_1 * V_2 = V_126 -> V_129 ;
F_106 ( V_2 ) ;
F_88 ( V_2 ) ;
F_102 ( V_126 ) ;
F_97 ( V_123 , NULL ) ;
F_103 ( F_93 ( V_123 ) ) ;
}
int F_107 ( struct V_107 * V_123 , T_4 V_136 )
{
struct V_125 * V_126 = F_105 ( V_123 ) ;
struct V_1 * V_2 = V_126 -> V_129 ;
return F_108 ( V_2 , V_136 ) ;
}
int F_109 ( struct V_107 * V_123 )
{
struct V_125 * V_126 = F_105 ( V_123 ) ;
struct V_1 * V_2 = V_126 -> V_129 ;
return F_110 ( V_2 ) ;
}
