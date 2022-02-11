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
if ( F_25 ( V_38 , V_43 ) < 0 )
F_26 ( V_40 ) ;
} else
F_26 ( V_40 ) ;
}
void F_27 ( struct V_1 * V_2 ,
const unsigned int V_5 ,
bool (* V_42)( struct V_1 * , int , T_3 ) )
{
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_38 * V_38 ;
struct V_39 * V_40 ;
V_40 = F_28 ( sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 )
return;
V_38 = F_29 ( 0 , V_43 ) ;
if ( ! V_38 ) {
F_26 ( V_40 ) ;
return;
}
V_40 -> V_2 = V_2 ;
V_40 -> V_42 = V_42 ;
V_40 -> V_44 . V_45 = V_15 ;
V_40 -> V_44 . V_46 = V_47 ;
V_40 -> V_44 . V_48 = 0 ;
V_40 -> V_44 . V_49 = F_30 ( V_5 ) ;
V_40 -> V_44 . V_50 = F_30 ( sizeof( T_3 ) ) ;
F_31 ( V_38 , V_11 , F_3 ( V_11 , 0 ) ,
( unsigned char * ) ( & V_40 -> V_44 ) , & V_40 -> V_34 , sizeof( V_40 -> V_34 ) ,
F_23 , V_40 ) ;
if ( F_25 ( V_38 , V_43 ) < 0 )
F_26 ( V_40 ) ;
F_32 ( V_38 ) ;
}
static void F_33 ( struct V_51 * V_52 )
{
if ( F_6 ( V_53 , & V_52 -> V_19 ) )
F_34 ( V_52 , V_54 ) ;
else
F_34 ( V_52 , V_55 ) ;
}
static void F_35 ( struct V_56 * V_57 )
{
struct V_1 * V_2 =
F_36 ( V_57 , struct V_1 , V_58 ) ;
struct V_59 * V_60 ;
struct V_51 * V_52 ;
F_37 (rt2x00dev, queue) {
while ( ! F_38 ( V_60 ) ) {
V_52 = F_39 ( V_60 , V_61 ) ;
if ( F_6 ( V_62 , & V_52 -> V_19 ) ||
! F_6 ( V_63 , & V_52 -> V_19 ) )
break;
F_33 ( V_52 ) ;
}
}
}
static void F_40 ( struct V_38 * V_38 )
{
struct V_51 * V_52 = (struct V_51 * ) V_38 -> V_41 ;
struct V_1 * V_2 = V_52 -> V_60 -> V_2 ;
if ( ! F_6 ( V_62 , & V_52 -> V_19 ) )
return;
if ( V_38 -> V_13 )
F_41 ( V_53 , & V_52 -> V_19 ) ;
F_42 ( V_52 ) ;
if ( V_2 -> V_64 -> V_65 -> V_66 )
V_2 -> V_64 -> V_65 -> V_66 ( V_52 ) ;
if ( ! F_43 ( V_2 , V_67 ) ||
! F_44 ( & V_2 -> V_68 ) )
F_45 ( V_2 -> V_69 , & V_2 -> V_58 ) ;
}
static bool F_46 ( struct V_51 * V_52 , void * V_70 )
{
struct V_1 * V_2 = V_52 -> V_60 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_71 * V_72 = V_52 -> V_73 ;
T_3 V_74 ;
int V_13 ;
if ( ! F_47 ( V_75 , & V_52 -> V_19 ) ||
F_6 ( V_63 , & V_52 -> V_19 ) )
return false ;
V_74 = V_2 -> V_64 -> V_65 -> V_76 ( V_52 ) ;
V_13 = F_48 ( V_52 -> V_77 , V_74 ) ;
if ( F_14 ( V_13 ) ) {
F_49 ( V_2 , L_4 ) ;
F_41 ( V_53 , & V_52 -> V_19 ) ;
F_42 ( V_52 ) ;
return false ;
}
F_50 ( V_72 -> V_38 , V_11 ,
F_51 ( V_11 , V_52 -> V_60 -> V_78 ) ,
V_52 -> V_77 -> V_70 , V_74 ,
F_40 , V_52 ) ;
V_13 = F_25 ( V_72 -> V_38 , V_43 ) ;
if ( V_13 ) {
if ( V_13 == - V_20 )
F_8 ( V_18 , & V_2 -> V_19 ) ;
F_41 ( V_53 , & V_52 -> V_19 ) ;
F_42 ( V_52 ) ;
}
return false ;
}
static void F_52 ( struct V_56 * V_57 )
{
struct V_1 * V_2 =
F_36 ( V_57 , struct V_1 , V_79 ) ;
struct V_51 * V_52 ;
struct V_80 * V_81 ;
T_1 V_82 [ 32 ] ;
while ( ! F_38 ( V_2 -> V_83 ) ) {
V_52 = F_39 ( V_2 -> V_83 , V_61 ) ;
if ( F_6 ( V_62 , & V_52 -> V_19 ) ||
! F_6 ( V_63 , & V_52 -> V_19 ) )
break;
V_81 = F_53 ( V_52 -> V_77 ) ;
V_81 -> V_84 = V_82 ;
V_81 -> V_85 = V_52 -> V_60 -> V_86 ;
F_54 ( V_52 , V_87 ) ;
}
}
static void F_55 ( struct V_38 * V_38 )
{
struct V_51 * V_52 = (struct V_51 * ) V_38 -> V_41 ;
struct V_1 * V_2 = V_52 -> V_60 -> V_2 ;
if ( ! F_47 ( V_62 , & V_52 -> V_19 ) )
return;
F_42 ( V_52 ) ;
if ( V_38 -> V_88 < V_52 -> V_60 -> V_86 || V_38 -> V_13 )
F_41 ( V_53 , & V_52 -> V_19 ) ;
F_45 ( V_2 -> V_69 , & V_2 -> V_79 ) ;
}
static bool F_56 ( struct V_51 * V_52 , void * V_70 )
{
struct V_1 * V_2 = V_52 -> V_60 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 -> V_12 ) ;
struct V_71 * V_72 = V_52 -> V_73 ;
int V_13 ;
if ( F_57 ( V_62 , & V_52 -> V_19 ) ||
F_6 ( V_63 , & V_52 -> V_19 ) )
return false ;
F_58 ( V_52 ) ;
F_50 ( V_72 -> V_38 , V_11 ,
F_59 ( V_11 , V_52 -> V_60 -> V_78 ) ,
V_52 -> V_77 -> V_70 , V_52 -> V_77 -> V_29 ,
F_55 , V_52 ) ;
V_13 = F_25 ( V_72 -> V_38 , V_43 ) ;
if ( V_13 ) {
if ( V_13 == - V_20 )
F_8 ( V_18 , & V_2 -> V_19 ) ;
F_41 ( V_53 , & V_52 -> V_19 ) ;
F_42 ( V_52 ) ;
}
return false ;
}
void F_60 ( struct V_59 * V_60 )
{
switch ( V_60 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
if ( ! F_38 ( V_60 ) )
F_61 ( V_60 ,
V_61 ,
V_94 ,
NULL ,
F_46 ) ;
break;
case V_95 :
if ( ! F_62 ( V_60 ) )
F_61 ( V_60 ,
V_94 ,
V_61 ,
NULL ,
F_56 ) ;
break;
default:
break;
}
}
static bool F_63 ( struct V_51 * V_52 , void * V_70 )
{
struct V_1 * V_2 = V_52 -> V_60 -> V_2 ;
struct V_71 * V_72 = V_52 -> V_73 ;
struct V_96 * V_97 = V_52 -> V_73 ;
if ( ! F_6 ( V_62 , & V_52 -> V_19 ) )
return false ;
F_64 ( V_72 -> V_38 ) ;
if ( ( V_52 -> V_60 -> V_89 == V_98 ) &&
( F_43 ( V_2 , V_99 ) ) )
F_64 ( V_97 -> V_100 ) ;
return false ;
}
void F_65 ( struct V_59 * V_60 , bool V_101 )
{
struct V_56 * V_102 ;
unsigned int V_35 ;
if ( V_101 )
F_61 ( V_60 , V_61 , V_94 , NULL ,
F_63 ) ;
switch ( V_60 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
V_102 = & V_60 -> V_2 -> V_58 ;
break;
case V_95 :
V_102 = & V_60 -> V_2 -> V_79 ;
break;
default:
return;
}
for ( V_35 = 0 ; V_35 < 10 ; V_35 ++ ) {
if ( F_38 ( V_60 ) )
break;
F_45 ( V_60 -> V_2 -> V_69 , V_102 ) ;
F_66 ( 10 ) ;
}
}
static void F_67 ( struct V_59 * V_60 )
{
F_49 ( V_60 -> V_2 , L_5 ,
V_60 -> V_89 ) ;
F_68 ( V_60 ) ;
F_69 ( V_60 , true ) ;
F_70 ( V_60 ) ;
}
static int F_71 ( struct V_59 * V_60 )
{
struct V_51 * V_52 ;
V_52 = F_39 ( V_60 , V_103 ) ;
return F_72 ( V_52 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
F_37 (rt2x00dev, queue) {
if ( ! F_38 ( V_60 ) ) {
if ( F_71 ( V_60 ) )
F_67 ( V_60 ) ;
}
}
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 , V_104 , 0 , 0 ,
V_31 ) ;
}
void F_76 ( struct V_51 * V_52 )
{
V_52 -> V_19 = 0 ;
if ( V_52 -> V_60 -> V_89 == V_95 )
F_56 ( V_52 , NULL ) ;
}
static void F_77 ( struct V_59 * V_60 ,
struct V_105 * V_106 )
{
struct V_10 * V_11 = F_2 ( V_60 -> V_2 -> V_12 ) ;
int V_14 ;
V_60 -> V_78 = F_78 ( V_106 ) ;
if ( V_60 -> V_89 == V_95 ) {
V_14 = F_59 ( V_11 , V_60 -> V_78 ) ;
V_60 -> V_107 = V_107 ( V_11 , V_14 , 0 ) ;
} else {
V_14 = F_51 ( V_11 , V_60 -> V_78 ) ;
V_60 -> V_107 = V_107 ( V_11 , V_14 , 1 ) ;
}
if ( ! V_60 -> V_107 )
V_60 -> V_107 = 1 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = F_80 ( V_2 -> V_12 ) ;
struct V_110 * V_111 = V_109 -> V_112 ;
struct V_105 * V_106 ;
struct V_59 * V_60 = V_2 -> V_113 ;
struct V_105 * V_114 = NULL ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_111 -> V_84 . V_115 ; V_35 ++ ) {
V_106 = & V_111 -> V_116 [ V_35 ] . V_84 ;
if ( F_81 ( V_106 ) ) {
F_77 ( V_2 -> V_83 , V_106 ) ;
} else if ( F_82 ( V_106 ) &&
( V_60 != F_83 ( V_2 ) ) ) {
F_77 ( V_60 , V_106 ) ;
V_60 = F_84 ( V_60 ) ;
V_114 = V_106 ;
}
}
if ( ! V_2 -> V_83 -> V_78 || ! V_2 -> V_113 -> V_78 ) {
F_10 ( V_2 , L_6 ) ;
return - V_117 ;
}
F_85 (rt2x00dev, queue) {
if ( ! V_60 -> V_78 )
F_77 ( V_60 , V_114 ) ;
}
return 0 ;
}
static int F_86 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_71 * V_72 ;
struct V_96 * V_97 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_60 -> V_118 ; V_35 ++ ) {
V_72 = V_60 -> V_119 [ V_35 ] . V_73 ;
V_72 -> V_38 = F_29 ( 0 , V_87 ) ;
if ( ! V_72 -> V_38 )
return - V_25 ;
}
if ( V_60 -> V_89 != V_98 ||
! F_43 ( V_2 , V_99 ) )
return 0 ;
for ( V_35 = 0 ; V_35 < V_60 -> V_118 ; V_35 ++ ) {
V_97 = V_60 -> V_119 [ V_35 ] . V_73 ;
V_97 -> V_100 = F_29 ( 0 , V_87 ) ;
if ( ! V_97 -> V_100 )
return - V_25 ;
}
return 0 ;
}
static void F_87 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_71 * V_72 ;
struct V_96 * V_97 ;
unsigned int V_35 ;
if ( ! V_60 -> V_119 )
return;
for ( V_35 = 0 ; V_35 < V_60 -> V_118 ; V_35 ++ ) {
V_72 = V_60 -> V_119 [ V_35 ] . V_73 ;
F_64 ( V_72 -> V_38 ) ;
F_32 ( V_72 -> V_38 ) ;
}
if ( V_60 -> V_89 != V_98 ||
! F_43 ( V_2 , V_99 ) )
return;
for ( V_35 = 0 ; V_35 < V_60 -> V_118 ; V_35 ++ ) {
V_97 = V_60 -> V_119 [ V_35 ] . V_73 ;
F_64 ( V_97 -> V_100 ) ;
F_32 ( V_97 -> V_100 ) ;
}
}
int F_88 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
int V_13 ;
V_13 = F_79 ( V_2 ) ;
if ( V_13 )
goto exit;
F_89 (rt2x00dev, queue) {
V_13 = F_86 ( V_60 ) ;
if ( V_13 )
goto exit;
}
return 0 ;
exit:
F_90 ( V_2 ) ;
return V_13 ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
F_89 (rt2x00dev, queue)
F_87 ( V_60 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
F_26 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
F_26 ( V_2 -> V_22 . V_23 ) ;
V_2 -> V_22 . V_23 = NULL ;
}
static int F_92 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_23 = F_93 ( V_24 , V_87 ) ;
if ( ! V_2 -> V_22 . V_23 )
goto exit;
V_2 -> V_121 = F_93 ( V_2 -> V_64 -> V_122 , V_87 ) ;
if ( ! V_2 -> V_121 )
goto exit;
V_2 -> V_120 = F_93 ( V_2 -> V_64 -> V_123 , V_87 ) ;
if ( ! V_2 -> V_120 )
goto exit;
return 0 ;
exit:
F_94 ( L_7 ) ;
F_91 ( V_2 ) ;
return - V_25 ;
}
int F_95 ( struct V_108 * V_124 ,
const struct V_125 * V_64 )
{
struct V_10 * V_11 = F_96 ( V_124 ) ;
struct V_126 * V_127 ;
struct V_1 * V_2 ;
int V_128 ;
V_11 = F_97 ( V_11 ) ;
F_98 ( V_11 ) ;
V_127 = F_99 ( sizeof( struct V_1 ) , V_64 -> V_127 ) ;
if ( ! V_127 ) {
F_94 ( L_8 ) ;
V_128 = - V_25 ;
goto V_129;
}
F_100 ( V_124 , V_127 ) ;
V_2 = V_127 -> V_130 ;
V_2 -> V_12 = & V_124 -> V_12 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_127 = V_127 ;
F_101 ( V_2 , V_131 ) ;
F_102 ( & V_2 -> V_79 , F_52 ) ;
F_102 ( & V_2 -> V_58 , F_35 ) ;
F_103 ( & V_2 -> V_132 , V_133 ,
V_134 ) ;
V_128 = F_92 ( V_2 ) ;
if ( V_128 )
goto V_135;
V_128 = F_104 ( V_2 ) ;
if ( V_128 )
goto V_136;
return 0 ;
V_136:
F_91 ( V_2 ) ;
V_135:
F_105 ( V_127 ) ;
V_129:
F_106 ( V_11 ) ;
F_100 ( V_124 , NULL ) ;
return V_128 ;
}
void F_107 ( struct V_108 * V_124 )
{
struct V_126 * V_127 = F_108 ( V_124 ) ;
struct V_1 * V_2 = V_127 -> V_130 ;
F_109 ( V_2 ) ;
F_91 ( V_2 ) ;
F_105 ( V_127 ) ;
F_100 ( V_124 , NULL ) ;
F_106 ( F_96 ( V_124 ) ) ;
}
int F_110 ( struct V_108 * V_124 , T_4 V_137 )
{
struct V_126 * V_127 = F_108 ( V_124 ) ;
struct V_1 * V_2 = V_127 -> V_130 ;
return F_111 ( V_2 , V_137 ) ;
}
int F_112 ( struct V_108 * V_124 )
{
struct V_126 * V_127 = F_108 ( V_124 ) ;
struct V_1 * V_2 = V_127 -> V_130 ;
return F_113 ( V_2 ) ;
}
