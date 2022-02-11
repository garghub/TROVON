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
ERROR ( V_2 ,
L_1 ,
V_3 , V_5 , V_13 ) ;
return V_13 ;
}
int F_8 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 , const int V_9 )
{
int V_13 ;
F_9 ( ! F_10 ( & V_2 -> V_21 ) ) ;
if ( F_11 ( ! V_2 -> V_22 . V_23 || V_8 > V_24 ) ) {
ERROR ( V_2 , L_2 ) ;
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
int F_12 ( struct V_1 * V_2 ,
const T_1 V_3 , const T_1 V_4 ,
const T_2 V_5 , void * V_7 ,
const T_2 V_8 , const int V_9 )
{
int V_13 = 0 ;
unsigned char * V_27 ;
T_2 V_28 , V_29 , V_30 ;
F_13 ( & V_2 -> V_21 ) ;
V_27 = ( char * ) V_7 ;
V_28 = V_5 ;
V_29 = V_8 ;
while ( V_29 && ! V_13 ) {
V_30 = F_14 ( T_2 , V_24 , V_29 ) ;
V_13 = F_8 ( V_2 , V_3 ,
V_4 , V_28 , V_27 ,
V_30 , V_9 ) ;
V_27 += V_30 ;
V_29 -= V_30 ;
V_28 += V_30 ;
}
F_15 ( & V_2 -> V_21 ) ;
return V_13 ;
}
int F_16 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
const struct V_31 V_32 ,
T_3 * V_33 )
{
unsigned int V_14 ;
if ( ! F_5 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
for ( V_14 = 0 ; V_14 < V_20 ; V_14 ++ ) {
F_17 ( V_2 , V_5 , V_33 ) ;
if ( ! F_18 ( * V_33 , V_32 ) )
return 1 ;
F_19 ( V_34 ) ;
}
ERROR ( V_2 , L_3
L_4 , V_5 , * V_33 ) ;
* V_33 = ~ 0 ;
return 0 ;
}
static void F_20 ( struct V_35 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_38 ;
if ( V_37 -> V_39 ( V_37 -> V_2 , V_35 -> V_13 , F_21 ( V_37 -> V_33 ) ) ) {
if ( F_22 ( V_35 , V_40 ) < 0 )
F_23 ( V_37 ) ;
} else
F_23 ( V_37 ) ;
}
void F_24 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
bool (* V_39)( struct V_1 * , int , T_3 ) )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
V_37 = F_25 ( sizeof( * V_37 ) , V_40 ) ;
if ( ! V_37 )
return;
V_35 = F_26 ( 0 , V_40 ) ;
if ( ! V_35 ) {
F_23 ( V_37 ) ;
return;
}
V_37 -> V_2 = V_2 ;
V_37 -> V_39 = V_39 ;
V_37 -> V_41 . V_42 = V_16 ;
V_37 -> V_41 . V_43 = V_44 ;
V_37 -> V_41 . V_45 = 0 ;
V_37 -> V_41 . V_46 = F_27 ( V_5 ) ;
V_37 -> V_41 . V_47 = F_27 ( sizeof( T_3 ) ) ;
F_28 ( V_35 , V_11 , F_3 ( V_11 , 0 ) ,
( unsigned char * ) ( & V_37 -> V_41 ) , & V_37 -> V_33 , sizeof( V_37 -> V_33 ) ,
F_20 , V_37 ) ;
if ( F_22 ( V_35 , V_40 ) < 0 )
F_23 ( V_37 ) ;
F_29 ( V_35 ) ;
}
static void F_30 ( struct V_48 * V_49 )
{
if ( F_5 ( V_50 , & V_49 -> V_18 ) )
F_31 ( V_49 , V_51 ) ;
else
F_31 ( V_49 , V_52 ) ;
}
static void F_32 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_33 ( V_54 , struct V_1 , V_55 ) ;
struct V_56 * V_57 ;
struct V_48 * V_49 ;
F_34 (rt2x00dev, queue) {
while ( ! F_35 ( V_57 ) ) {
V_49 = F_36 ( V_57 , V_58 ) ;
if ( F_5 ( V_59 , & V_49 -> V_18 ) ||
! F_5 ( V_60 , & V_49 -> V_18 ) )
break;
F_30 ( V_49 ) ;
}
}
}
static void F_37 ( struct V_35 * V_35 )
{
struct V_48 * V_49 = (struct V_48 * ) V_35 -> V_38 ;
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
if ( ! F_5 ( V_59 , & V_49 -> V_18 ) )
return;
if ( V_35 -> V_13 )
F_38 ( V_50 , & V_49 -> V_18 ) ;
F_39 ( V_49 ) ;
if ( V_2 -> V_61 -> V_62 -> V_63 )
V_2 -> V_61 -> V_62 -> V_63 ( V_49 ) ;
if ( ! F_5 ( V_64 , & V_2 -> V_65 ) ||
! F_40 ( & V_2 -> V_66 ) )
F_41 ( V_2 -> V_67 , & V_2 -> V_55 ) ;
}
static bool F_42 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_68 * V_69 = V_49 -> V_70 ;
T_3 V_71 ;
int V_13 ;
if ( ! F_43 ( V_72 , & V_49 -> V_18 ) ||
F_5 ( V_60 , & V_49 -> V_18 ) )
return false ;
V_71 = V_2 -> V_61 -> V_62 -> V_73 ( V_49 ) ;
V_13 = F_44 ( V_49 -> V_74 , V_71 ) ;
if ( F_11 ( V_13 ) ) {
F_45 ( V_2 , L_5 ) ;
F_38 ( V_50 , & V_49 -> V_18 ) ;
F_39 ( V_49 ) ;
return false ;
}
F_46 ( V_69 -> V_35 , V_11 ,
F_47 ( V_11 , V_49 -> V_57 -> V_75 ) ,
V_49 -> V_74 -> V_76 , V_71 ,
F_37 , V_49 ) ;
V_13 = F_22 ( V_69 -> V_35 , V_40 ) ;
if ( V_13 ) {
if ( V_13 == - V_19 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_38 ( V_50 , & V_49 -> V_18 ) ;
F_39 ( V_49 ) ;
}
return false ;
}
static void F_48 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_33 ( V_54 , struct V_1 , V_77 ) ;
struct V_48 * V_49 ;
struct V_78 * V_79 ;
T_1 V_80 [ 32 ] ;
while ( ! F_35 ( V_2 -> V_81 ) ) {
V_49 = F_36 ( V_2 -> V_81 , V_58 ) ;
if ( F_5 ( V_59 , & V_49 -> V_18 ) ||
! F_5 ( V_60 , & V_49 -> V_18 ) )
break;
V_79 = F_49 ( V_49 -> V_74 ) ;
V_79 -> V_82 = V_80 ;
V_79 -> V_83 = V_49 -> V_57 -> V_84 ;
F_50 ( V_49 , V_85 ) ;
}
}
static void F_51 ( struct V_35 * V_35 )
{
struct V_48 * V_49 = (struct V_48 * ) V_35 -> V_38 ;
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
if ( ! F_43 ( V_59 , & V_49 -> V_18 ) )
return;
F_39 ( V_49 ) ;
if ( V_35 -> V_86 < V_49 -> V_57 -> V_84 || V_35 -> V_13 )
F_38 ( V_50 , & V_49 -> V_18 ) ;
F_41 ( V_2 -> V_67 , & V_2 -> V_77 ) ;
}
static bool F_52 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_68 * V_69 = V_49 -> V_70 ;
int V_13 ;
if ( F_53 ( V_59 , & V_49 -> V_18 ) ||
F_5 ( V_60 , & V_49 -> V_18 ) )
return false ;
F_54 ( V_49 ) ;
F_46 ( V_69 -> V_35 , V_11 ,
F_55 ( V_11 , V_49 -> V_57 -> V_75 ) ,
V_49 -> V_74 -> V_76 , V_49 -> V_74 -> V_29 ,
F_51 , V_49 ) ;
V_13 = F_22 ( V_69 -> V_35 , V_40 ) ;
if ( V_13 ) {
if ( V_13 == - V_19 )
F_7 ( V_17 , & V_2 -> V_18 ) ;
F_38 ( V_50 , & V_49 -> V_18 ) ;
F_39 ( V_49 ) ;
}
return false ;
}
void F_56 ( struct V_56 * V_57 )
{
switch ( V_57 -> V_87 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
if ( ! F_35 ( V_57 ) )
F_57 ( V_57 , V_58 , V_92 ,
F_42 ) ;
break;
case V_93 :
if ( ! F_58 ( V_57 ) )
F_57 ( V_57 , V_92 , V_58 ,
F_52 ) ;
break;
default:
break;
}
}
static bool F_59 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_57 -> V_2 ;
struct V_68 * V_69 = V_49 -> V_70 ;
struct V_94 * V_95 = V_49 -> V_70 ;
if ( ! F_5 ( V_59 , & V_49 -> V_18 ) )
return false ;
F_60 ( V_69 -> V_35 ) ;
if ( ( V_49 -> V_57 -> V_87 == V_96 ) &&
( F_5 ( V_97 , & V_2 -> V_65 ) ) )
F_60 ( V_95 -> V_98 ) ;
return false ;
}
void F_61 ( struct V_56 * V_57 , bool V_99 )
{
struct V_53 * V_100 ;
unsigned int V_14 ;
if ( V_99 )
F_57 ( V_57 , V_58 , V_92 ,
F_59 ) ;
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
if ( F_35 ( V_57 ) )
break;
F_41 ( V_57 -> V_2 -> V_67 , V_100 ) ;
F_62 ( 10 ) ;
}
}
static void F_63 ( struct V_56 * V_57 )
{
F_45 ( V_57 -> V_2 , L_6
L_7 , V_57 -> V_87 ) ;
F_64 ( V_57 , true ) ;
}
static int F_65 ( struct V_56 * V_57 )
{
struct V_48 * V_49 ;
V_49 = F_36 ( V_57 , V_101 ) ;
return F_66 ( V_49 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
F_34 (rt2x00dev, queue) {
if ( ! F_35 ( V_57 ) ) {
if ( F_65 ( V_57 ) )
F_63 ( V_57 ) ;
}
}
}
void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_102 , 0 , 0 ,
V_103 ) ;
}
void F_70 ( struct V_48 * V_49 )
{
V_49 -> V_18 = 0 ;
if ( V_49 -> V_57 -> V_87 == V_93 )
F_52 ( V_49 ) ;
}
static void F_71 ( struct V_56 * V_57 ,
struct V_104 * V_105 )
{
struct V_10 * V_11 = F_2 ( V_57 -> V_2 -> V_12 ) ;
int V_15 ;
V_57 -> V_75 = F_72 ( V_105 ) ;
if ( V_57 -> V_87 == V_93 ) {
V_15 = F_55 ( V_11 , V_57 -> V_75 ) ;
V_57 -> V_106 = V_106 ( V_11 , V_15 , 0 ) ;
} else {
V_15 = F_47 ( V_11 , V_57 -> V_75 ) ;
V_57 -> V_106 = V_106 ( V_11 , V_15 , 1 ) ;
}
if ( ! V_57 -> V_106 )
V_57 -> V_106 = 1 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_107 * V_108 = F_74 ( V_2 -> V_12 ) ;
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_104 * V_105 ;
struct V_56 * V_57 = V_2 -> V_112 ;
struct V_104 * V_113 = NULL ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_110 -> V_82 . V_114 ; V_14 ++ ) {
V_105 = & V_110 -> V_115 [ V_14 ] . V_82 ;
if ( F_75 ( V_105 ) ) {
F_71 ( V_2 -> V_81 , V_105 ) ;
} else if ( F_76 ( V_105 ) &&
( V_57 != F_77 ( V_2 ) ) ) {
F_71 ( V_57 , V_105 ) ;
V_57 = F_78 ( V_57 ) ;
V_113 = V_105 ;
}
}
if ( ! V_2 -> V_81 -> V_75 || ! V_2 -> V_112 -> V_75 ) {
ERROR ( V_2 , L_8 ) ;
return - V_116 ;
}
F_79 (rt2x00dev, queue) {
if ( ! V_57 -> V_75 )
F_71 ( V_57 , V_113 ) ;
}
return 0 ;
}
static int F_80 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_68 * V_69 ;
struct V_94 * V_95 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_69 = V_57 -> V_118 [ V_14 ] . V_70 ;
V_69 -> V_35 = F_26 ( 0 , V_85 ) ;
if ( ! V_69 -> V_35 )
return - V_25 ;
}
if ( V_57 -> V_87 != V_96 ||
! F_5 ( V_97 , & V_2 -> V_65 ) )
return 0 ;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_95 = V_57 -> V_118 [ V_14 ] . V_70 ;
V_95 -> V_98 = F_26 ( 0 , V_85 ) ;
if ( ! V_95 -> V_98 )
return - V_25 ;
}
return 0 ;
}
static void F_81 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_68 * V_69 ;
struct V_94 * V_95 ;
unsigned int V_14 ;
if ( ! V_57 -> V_118 )
return;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_69 = V_57 -> V_118 [ V_14 ] . V_70 ;
F_60 ( V_69 -> V_35 ) ;
F_29 ( V_69 -> V_35 ) ;
}
if ( V_57 -> V_87 != V_96 ||
! F_5 ( V_97 , & V_2 -> V_65 ) )
return;
for ( V_14 = 0 ; V_14 < V_57 -> V_117 ; V_14 ++ ) {
V_95 = V_57 -> V_118 [ V_14 ] . V_70 ;
F_60 ( V_95 -> V_98 ) ;
F_29 ( V_95 -> V_98 ) ;
}
}
int F_82 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
int V_13 ;
V_13 = F_73 ( V_2 ) ;
if ( V_13 )
goto exit;
F_83 (rt2x00dev, queue) {
V_13 = F_80 ( V_57 ) ;
if ( V_13 )
goto exit;
}
return 0 ;
exit:
F_84 ( V_2 ) ;
return V_13 ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
F_83 (rt2x00dev, queue)
F_81 ( V_57 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_119 ) ;
V_2 -> V_119 = NULL ;
F_23 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
F_23 ( V_2 -> V_22 . V_23 ) ;
V_2 -> V_22 . V_23 = NULL ;
}
static int F_86 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_23 = F_87 ( V_24 , V_85 ) ;
if ( ! V_2 -> V_22 . V_23 )
goto exit;
V_2 -> V_120 = F_87 ( V_2 -> V_61 -> V_121 , V_85 ) ;
if ( ! V_2 -> V_120 )
goto exit;
V_2 -> V_119 = F_87 ( V_2 -> V_61 -> V_122 , V_85 ) ;
if ( ! V_2 -> V_119 )
goto exit;
return 0 ;
exit:
F_88 ( L_9 ) ;
F_85 ( V_2 ) ;
return - V_25 ;
}
int F_89 ( struct V_107 * V_123 ,
const struct V_124 * V_61 )
{
struct V_10 * V_11 = F_90 ( V_123 ) ;
struct V_125 * V_126 ;
struct V_1 * V_2 ;
int V_127 ;
V_11 = F_91 ( V_11 ) ;
F_92 ( V_11 ) ;
V_126 = F_93 ( sizeof( struct V_1 ) , V_61 -> V_126 ) ;
if ( ! V_126 ) {
F_88 ( L_10 ) ;
V_127 = - V_25 ;
goto V_128;
}
F_94 ( V_123 , V_126 ) ;
V_2 = V_126 -> V_129 ;
V_2 -> V_12 = & V_123 -> V_12 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_126 = V_126 ;
F_95 ( V_2 , V_130 ) ;
F_96 ( & V_2 -> V_77 , F_48 ) ;
F_96 ( & V_2 -> V_55 , F_32 ) ;
F_97 ( & V_2 -> V_131 , V_132 ,
V_133 ) ;
V_127 = F_86 ( V_2 ) ;
if ( V_127 )
goto V_134;
V_127 = F_98 ( V_2 ) ;
if ( V_127 )
goto V_135;
return 0 ;
V_135:
F_85 ( V_2 ) ;
V_134:
F_99 ( V_126 ) ;
V_128:
F_100 ( V_11 ) ;
F_94 ( V_123 , NULL ) ;
return V_127 ;
}
void F_101 ( struct V_107 * V_123 )
{
struct V_125 * V_126 = F_102 ( V_123 ) ;
struct V_1 * V_2 = V_126 -> V_129 ;
F_103 ( V_2 ) ;
F_85 ( V_2 ) ;
F_99 ( V_126 ) ;
F_94 ( V_123 , NULL ) ;
F_100 ( F_90 ( V_123 ) ) ;
}
int F_104 ( struct V_107 * V_123 , T_4 V_136 )
{
struct V_125 * V_126 = F_102 ( V_123 ) ;
struct V_1 * V_2 = V_126 -> V_129 ;
return F_105 ( V_2 , V_136 ) ;
}
int F_106 ( struct V_107 * V_123 )
{
struct V_125 * V_126 = F_102 ( V_123 ) ;
struct V_1 * V_2 = V_126 -> V_129 ;
return F_107 ( V_2 ) ;
}
