static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
default: return L_3 ;
}
}
static void * F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 -> V_8 ;
while ( V_9 ) {
struct V_10 * V_11 = F_3 ( V_9 , struct V_10 ,
V_9 ) ;
if ( V_7 < V_11 -> V_7 )
V_9 = V_9 -> V_12 ;
else if ( V_7 > V_11 -> V_7 )
V_9 = V_9 -> V_13 ;
else
return V_11 ;
}
return NULL ;
}
static int F_4 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_8 * * V_14 = & ( V_6 -> V_8 ) , * V_15 = NULL ;
while ( * V_14 ) {
struct V_10 * V_16 = F_3 ( * V_14 , struct V_10 ,
V_9 ) ;
V_15 = * V_14 ;
if ( V_11 -> V_7 < V_16 -> V_7 )
V_14 = & ( ( * V_14 ) -> V_12 ) ;
else if ( V_11 -> V_7 > V_16 -> V_7 )
V_14 = & ( ( * V_14 ) -> V_13 ) ;
else
return - V_17 ;
}
F_5 ( & V_11 -> V_9 , V_15 , V_14 ) ;
F_6 ( & V_11 -> V_9 , V_6 ) ;
return 0 ;
}
static const char * F_7 ( enum V_18 V_19 )
{
switch ( V_19 ) {
case V_20 : return L_4 ;
case V_21 : return L_5 ;
case V_22 : return L_6 ;
case V_23 : return L_7 ;
case V_24 : return L_8 ;
case V_25 : return L_9 ;
case V_26 : return L_10 ;
case V_27 : return L_11 ;
case V_28 : return L_12 ;
case V_29 : return L_13 ;
default: return L_14 ;
} ;
}
int F_8 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
int V_34 ;
int V_35 ;
V_33 -> V_36 . V_37 . V_38 . V_39 =
F_9 ( V_31 -> V_40 * sizeof( struct V_39 ) ,
V_41 ) ;
if ( ! V_33 -> V_36 . V_37 . V_38 . V_39 )
return - V_42 ;
for ( V_34 = 0 ; V_34 < V_31 -> V_40 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_43 ; ++ V_35 )
F_10 ( & V_33 -> V_36 . V_37 . V_38 .
V_39 [ V_34 ] . V_44 [ V_35 ] ) ;
F_11 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_34 ] . V_45 ) ;
}
F_12 ( V_31 , L_15 ,
V_31 -> V_40 ) ;
for ( V_34 = 0 ; V_34 < V_43 ; V_34 ++ )
V_33 -> V_36 . V_37 . V_38 . V_46 [ V_34 ] = V_47 ;
F_13 ( & V_33 -> V_36 . V_37 . V_38 . V_48 ) ;
return 0 ;
}
void F_14 ( struct V_30 * V_31 ,
enum V_49 type )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
int V_34 ;
if ( V_33 -> V_36 . V_37 . V_38 . V_39 ) {
if ( type != V_50 )
for ( V_34 = 0 ; V_34 < V_31 -> V_40 ; V_34 ++ )
if ( type == V_51 ||
V_31 -> V_52 . V_53 != V_34 )
F_15 ( V_31 , V_34 ) ;
if ( type != V_54 ) {
F_16 ( V_33 -> V_36 . V_37 . V_38 . V_39 ) ;
V_33 -> V_36 . V_37 . V_38 . V_39 = NULL ;
}
}
}
static void F_17 ( struct V_30 * V_31 , int V_55 ,
struct V_56 * V_57 )
{
T_2 V_58 = * ( T_2 * ) ( V_57 -> V_59 + 64 ) ;
T_2 V_60 = * ( T_2 * ) ( V_57 -> V_59 + 35 ) ;
T_2 V_61 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
int V_62 ;
V_62 = ( V_58 >> 6 & 1 ) + 1 ;
V_61 = V_33 -> V_63 [ V_55 ] [ V_62 - 1 ] [ V_60 ] ;
* ( T_2 * ) ( V_57 -> V_59 + 35 ) = V_61 ;
}
static void F_18 ( struct V_30 * V_31 , struct V_56 * V_57 ,
T_2 V_55 )
{
struct V_64 * V_65 = V_57 -> V_59 + 8 ;
enum V_66 V_67 = F_19 ( * ( V_68 * ) V_57 -> V_59 ) ;
T_3 V_69 = ( F_19 ( V_65 -> V_70 ) >> 16 ) & 0xff ;
if ( V_71 == V_69 )
V_65 -> V_72 . V_73 = 0x80 | V_55 ;
if ( V_74 == V_69 || V_75 == V_69 ) {
if ( V_67 & V_76 )
V_65 -> V_72 . V_73 = V_55 & 0x7F ;
if ( V_67 & V_77 )
V_65 -> V_78 . V_73 = V_55 & 0x7F ;
}
}
static int F_20 ( struct V_30 * V_31 )
{
return V_31 -> V_52 . V_79 - 1 ;
}
static void * F_21 ( struct V_30 * V_31 , T_1 V_7 ,
enum V_18 type )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
return F_2 ( & V_33 -> V_36 . V_37 . V_38 . V_46 [ type ] ,
V_7 ) ;
}
static int F_22 ( struct V_30 * V_31 , int V_55 , T_1 V_7 ,
enum V_18 type ,
void * V_11 )
{
struct V_10 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_21 ( V_31 , V_7 , type ) ;
if ( ! V_80 ) {
V_81 = - V_82 ;
goto exit;
}
if ( V_80 -> V_2 == V_83 ) {
V_81 = - V_84 ;
goto exit;
}
if ( V_80 -> V_85 != V_55 ) {
V_81 = - V_86 ;
goto exit;
}
V_80 -> V_87 = V_80 -> V_2 ;
V_80 -> V_2 = V_83 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_80 ;
exit:
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
int F_26 ( struct V_30 * V_31 ,
enum V_18 type ,
T_1 V_7 , int * V_55 )
{
struct V_10 * V_80 ;
int V_81 = - V_88 ;
int V_89 = V_7 ;
if ( type == V_20 )
V_89 &= 0x7fffff ;
F_27 ( F_24 ( V_31 ) ) ;
V_80 = F_21 ( V_31 , V_89 , type ) ;
if ( V_80 ) {
* V_55 = V_80 -> V_85 ;
V_81 = 0 ;
}
F_28 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static void F_29 ( struct V_30 * V_31 , int V_55 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_21 ( V_31 , V_7 , type ) ;
if ( V_80 )
V_80 -> V_2 = V_80 -> V_87 ;
F_25 ( F_24 ( V_31 ) ) ;
}
static struct V_10 * F_30 ( int V_89 )
{
struct V_90 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_93 ;
V_91 -> V_94 = V_89 ;
F_10 ( & V_91 -> V_95 ) ;
F_13 ( & V_91 -> V_96 ) ;
F_31 ( & V_91 -> V_97 , 0 ) ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_32 ( int V_89 , int V_98 )
{
struct V_99 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_98 = V_98 ;
V_91 -> V_92 . V_2 = V_4 ;
F_31 ( & V_91 -> V_97 , 0 ) ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_33 ( int V_89 , int V_100 )
{
struct V_101 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_102 ;
V_91 -> V_100 = V_100 ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_34 ( int V_89 )
{
struct V_103 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_104 ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_35 ( int V_89 )
{
struct V_105 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_106 ;
F_31 ( & V_91 -> V_97 , 0 ) ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_36 ( int V_89 )
{
struct V_107 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_108 ;
F_31 ( & V_91 -> V_97 , 0 ) ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_37 ( int V_89 )
{
struct V_109 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_110 ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_38 ( int V_89 )
{
struct V_111 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_112 ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_39 ( T_1 V_89 , int V_113 )
{
struct V_114 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_115 ;
V_91 -> V_113 = V_113 ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_40 ( T_1 V_89 , enum V_18 type , int V_55 ,
int V_116 )
{
struct V_10 * V_91 ;
switch ( type ) {
case V_20 :
V_91 = F_30 ( V_89 ) ;
break;
case V_23 :
V_91 = F_33 ( V_89 , V_116 ) ;
break;
case V_24 :
V_91 = F_32 ( V_89 , V_116 ) ;
break;
case V_26 :
V_91 = F_34 ( V_89 ) ;
break;
case V_21 :
V_91 = F_35 ( V_89 ) ;
break;
case V_22 :
V_91 = F_36 ( V_89 ) ;
break;
case V_25 :
F_41 ( V_117 L_16 ) ;
return NULL ;
case V_27 :
V_91 = F_37 ( V_89 ) ;
break;
case V_29 :
V_91 = F_38 ( V_89 ) ;
break;
case V_28 :
V_91 = F_39 ( V_89 , V_116 ) ;
break;
default:
return NULL ;
}
if ( V_91 )
V_91 -> V_85 = V_55 ;
return V_91 ;
}
static int F_42 ( struct V_30 * V_31 , int V_55 , T_1 V_118 , int V_119 ,
enum V_18 type , int V_116 )
{
int V_34 ;
int V_81 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_10 * * V_120 ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_5 * V_6 = & V_122 -> V_46 [ type ] ;
V_120 = F_9 ( V_119 * sizeof *V_120 , V_41 ) ;
if ( ! V_120 )
return - V_42 ;
for ( V_34 = 0 ; V_34 < V_119 ; ++ V_34 ) {
V_120 [ V_34 ] = F_40 ( V_118 + V_34 , type , V_55 , V_116 ) ;
if ( ! V_120 [ V_34 ] ) {
for ( -- V_34 ; V_34 >= 0 ; -- V_34 )
F_16 ( V_120 [ V_34 ] ) ;
F_16 ( V_120 ) ;
return - V_42 ;
}
}
F_23 ( F_24 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_119 ; ++ V_34 ) {
if ( F_21 ( V_31 , V_118 + V_34 , type ) ) {
V_81 = - V_17 ;
goto V_123;
}
V_81 = F_4 ( V_6 , V_120 [ V_34 ] ) ;
if ( V_81 )
goto V_123;
F_43 ( & V_120 [ V_34 ] -> V_124 ,
& V_122 -> V_39 [ V_55 ] . V_44 [ type ] ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_120 ) ;
return 0 ;
V_123:
for ( -- V_34 ; V_34 >= V_118 ; -- V_34 )
F_44 ( & V_120 [ V_34 ] -> V_9 , V_6 ) ;
F_25 ( F_24 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_119 ; ++ V_34 )
F_16 ( V_120 [ V_34 ] ) ;
F_16 ( V_120 ) ;
return V_81 ;
}
static int F_45 ( struct V_90 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_125 || F_46 ( & V_11 -> V_97 ) ||
! F_47 ( & V_11 -> V_95 ) ) {
F_48 ( L_17 ,
V_11 -> V_92 . V_2 , F_46 ( & V_11 -> V_97 ) ) ;
return - V_84 ;
} else if ( V_11 -> V_92 . V_2 != V_93 ) {
return - V_86 ;
}
return 0 ;
}
static int F_49 ( struct V_99 * V_11 , int V_98 )
{
if ( V_11 -> V_92 . V_2 == V_3 ||
F_46 ( & V_11 -> V_97 ) ) {
F_41 ( V_126 L_18 ,
V_127 , __LINE__ ,
F_1 ( V_11 -> V_92 . V_2 ) ,
F_46 ( & V_11 -> V_97 ) ) ;
return - V_84 ;
} else if ( V_11 -> V_92 . V_2 != V_4 )
return - V_86 ;
else if ( V_11 -> V_98 != V_98 )
return - V_128 ;
return 0 ;
}
static int F_50 ( struct V_101 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_129 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_102 )
return - V_86 ;
return 0 ;
}
static int F_51 ( struct V_103 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_129 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_102 )
return - V_86 ;
return 0 ;
}
static int F_52 ( struct V_109 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_130 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_110 )
return - V_86 ;
return 0 ;
}
static int F_53 ( struct V_111 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_131 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_112 )
return - V_86 ;
return 0 ;
}
static int F_54 ( struct V_114 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_132 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_115 )
return - V_86 ;
return 0 ;
}
static int F_55 ( struct V_105 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_133 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_106 )
return - V_86 ;
return 0 ;
}
static int F_56 ( struct V_107 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_134 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_108 )
return - V_86 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_11 , enum V_18 type , int V_116 )
{
switch ( type ) {
case V_20 :
return F_45 ( (struct V_90 * ) V_11 ) ;
case V_21 :
return F_55 ( (struct V_105 * ) V_11 ) ;
case V_22 :
return F_56 ( (struct V_107 * ) V_11 ) ;
case V_23 :
return F_50 ( (struct V_101 * ) V_11 ) ;
case V_24 :
return F_49 ( (struct V_99 * ) V_11 , V_116 ) ;
case V_25 :
return - V_135 ;
case V_26 :
return F_51 ( (struct V_103 * ) V_11 ) ;
case V_27 :
return F_52 ( (struct V_109 * ) V_11 ) ;
case V_29 :
return F_53 ( (struct V_111 * ) V_11 ) ;
case V_28 :
return F_54 ( (struct V_114 * ) V_11 ) ;
default:
return - V_128 ;
}
}
static int F_58 ( struct V_30 * V_31 , int V_55 , T_1 V_118 , int V_119 ,
enum V_18 type , int V_116 )
{
T_1 V_34 ;
int V_81 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
for ( V_34 = V_118 ; V_34 < V_118 + V_119 ; ++ V_34 ) {
V_80 = F_2 ( & V_122 -> V_46 [ type ] , V_34 ) ;
if ( ! V_80 ) {
V_81 = - V_88 ;
goto V_136;
}
if ( V_80 -> V_85 != V_55 ) {
V_81 = - V_86 ;
goto V_136;
}
V_81 = F_57 ( V_80 , type , V_116 ) ;
if ( V_81 )
goto V_136;
}
for ( V_34 = V_118 ; V_34 < V_118 + V_119 ; ++ V_34 ) {
V_80 = F_2 ( & V_122 -> V_46 [ type ] , V_34 ) ;
F_44 ( & V_80 -> V_9 , & V_122 -> V_46 [ type ] ) ;
F_59 ( & V_80 -> V_124 ) ;
F_16 ( V_80 ) ;
}
V_81 = 0 ;
V_136:
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_60 ( struct V_30 * V_31 , int V_55 , int V_113 ,
enum V_137 V_2 , struct V_90 * * V_138 ,
int V_139 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_90 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ V_20 ] , V_113 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_125 :
F_12 ( V_31 , L_19 ,
V_127 , V_80 -> V_92 . V_7 ) ;
V_81 = - V_84 ;
break;
case V_93 :
if ( V_80 -> V_92 . V_2 == V_140 && ! V_139 )
break;
F_12 ( V_31 , L_20 , V_80 -> V_92 . V_7 ) ;
V_81 = - V_128 ;
break;
case V_140 :
if ( ( V_80 -> V_92 . V_2 == V_93 && V_139 ) ||
V_80 -> V_92 . V_2 == V_141 )
break;
else {
F_12 ( V_31 , L_20 ,
V_80 -> V_92 . V_7 ) ;
V_81 = - V_128 ;
}
break;
case V_141 :
if ( V_80 -> V_92 . V_2 != V_140 )
V_81 = - V_128 ;
break;
default:
V_81 = - V_128 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_125 ;
if ( V_138 )
* V_138 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_61 ( struct V_30 * V_31 , int V_55 , int V_143 ,
enum V_144 V_2 , struct V_101 * * V_145 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_101 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ V_23 ] , V_143 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_129 :
V_81 = - V_128 ;
break;
case V_102 :
if ( V_80 -> V_92 . V_2 != V_146 )
V_81 = - V_128 ;
break;
case V_146 :
if ( V_80 -> V_92 . V_2 != V_102 &&
V_80 -> V_92 . V_2 != V_147 )
V_81 = - V_128 ;
break;
case V_147 :
if ( V_80 -> V_92 . V_2 != V_146 )
V_81 = - V_128 ;
break;
default:
V_81 = - V_128 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_129 ;
if ( V_145 )
* V_145 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_62 ( struct V_30 * V_31 , int V_55 , int V_143 ,
enum V_148 V_2 , struct V_103 * * V_149 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_103 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ V_26 ] , V_143 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_150 :
V_81 = - V_128 ;
break;
case V_104 :
if ( V_80 -> V_92 . V_2 != V_151 )
V_81 = - V_128 ;
break;
case V_151 :
if ( V_80 -> V_92 . V_2 != V_104 )
V_81 = - V_128 ;
break;
default:
V_81 = - V_128 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_150 ;
if ( V_149 )
* V_149 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_63 ( struct V_30 * V_31 , int V_55 , int V_152 ,
enum V_153 V_2 , struct V_105 * * V_154 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_105 * V_80 ;
int V_81 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ V_21 ] , V_152 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_133 :
V_81 = - V_84 ;
break;
case V_106 :
if ( V_80 -> V_92 . V_2 != V_155 )
V_81 = - V_128 ;
else if ( F_46 ( & V_80 -> V_97 ) )
V_81 = - V_84 ;
else
V_81 = 0 ;
break;
case V_155 :
if ( V_80 -> V_92 . V_2 != V_106 )
V_81 = - V_128 ;
else
V_81 = 0 ;
break;
default:
V_81 = - V_128 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_133 ;
if ( V_154 )
* V_154 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_64 ( struct V_30 * V_31 , int V_55 , int V_143 ,
enum V_153 V_2 , struct V_107 * * V_156 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_107 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ V_22 ] , V_143 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_134 :
V_81 = - V_128 ;
break;
case V_108 :
if ( V_80 -> V_92 . V_2 != V_157 )
V_81 = - V_128 ;
else if ( F_46 ( & V_80 -> V_97 ) )
V_81 = - V_84 ;
break;
case V_157 :
if ( V_80 -> V_92 . V_2 != V_108 )
V_81 = - V_128 ;
break;
default:
V_81 = - V_128 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_134 ;
if ( V_156 )
* V_156 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static void F_65 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_89 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ type ] , V_89 ) ;
if ( V_80 && ( V_80 -> V_85 == V_55 ) )
V_80 -> V_2 = V_80 -> V_87 ;
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_66 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_89 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_122 -> V_46 [ type ] , V_89 ) ;
if ( V_80 && ( V_80 -> V_85 == V_55 ) )
V_80 -> V_2 = V_80 -> V_142 ;
F_25 ( F_24 ( V_31 ) ) ;
}
static int F_67 ( struct V_30 * V_31 , int V_55 , int V_113 )
{
return F_68 ( V_31 , V_113 ) &&
( F_69 ( V_31 ) || F_70 ( V_31 , V_55 , V_113 ) ) ;
}
static int F_71 ( struct V_30 * V_31 , int V_113 )
{
return V_113 < V_31 -> V_52 . V_158 [ V_159 ] ;
}
static int F_72 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 ;
int V_119 ;
int V_164 ;
int V_118 ;
int V_113 ;
switch ( V_160 ) {
case V_165 :
V_119 = F_73 ( & V_162 ) ;
V_164 = F_74 ( & V_162 ) ;
V_81 = F_75 ( V_31 , V_119 , V_164 , & V_118 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_42 ( V_31 , V_55 , V_118 , V_119 , V_20 , 0 ) ;
if ( V_81 ) {
F_76 ( V_31 , V_118 , V_119 ) ;
return V_81 ;
}
F_77 ( V_163 , V_118 ) ;
break;
case V_166 :
V_113 = F_73 ( & V_162 ) & 0x7fffff ;
if ( F_67 ( V_31 , V_55 , V_113 ) ) {
V_81 = F_42 ( V_31 , V_55 , V_113 , 1 , V_20 , 0 ) ;
if ( V_81 )
return V_81 ;
}
V_81 = F_60 ( V_31 , V_55 , V_113 , V_140 ,
NULL , 1 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_71 ( V_31 , V_113 ) ) {
V_81 = F_78 ( V_31 , V_113 ) ;
if ( V_81 ) {
F_65 ( V_31 , V_55 , V_20 , V_113 ) ;
return V_81 ;
}
}
F_66 ( V_31 , V_55 , V_20 , V_113 ) ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_79 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_128 ;
int V_118 ;
int V_98 ;
if ( V_160 != V_167 )
return V_81 ;
V_98 = F_73 ( & V_162 ) ;
V_118 = F_80 ( V_31 , V_98 ) ;
if ( V_118 == - 1 )
return - V_42 ;
V_81 = F_42 ( V_31 , V_55 , V_118 , 1 , V_24 , V_98 ) ;
if ( V_81 )
F_81 ( V_31 , V_118 , V_98 ) ;
else
F_77 ( V_163 , V_118 ) ;
return V_81 ;
}
static int F_82 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_128 ;
int V_143 ;
int V_89 ;
struct V_101 * V_145 ;
switch ( V_160 ) {
case V_165 :
V_143 = F_83 ( V_31 ) ;
if ( V_143 == - 1 )
break;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_42 ( V_31 , V_55 , V_89 , 1 , V_23 , V_143 ) ;
if ( V_81 ) {
F_84 ( V_31 , V_143 ) ;
break;
}
F_77 ( V_163 , V_143 ) ;
break;
case V_166 :
V_143 = F_73 ( & V_162 ) ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_61 ( V_31 , V_55 , V_89 ,
V_146 , & V_145 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_85 ( V_31 , V_145 -> V_100 ) ;
if ( V_81 ) {
F_65 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
}
F_66 ( V_31 , V_55 , V_23 , V_89 ) ;
break;
}
return V_81 ;
}
static int F_86 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_152 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_81 = F_87 ( V_31 , & V_152 ) ;
if ( V_81 )
break;
V_81 = F_42 ( V_31 , V_55 , V_152 , 1 , V_21 , 0 ) ;
if ( V_81 ) {
F_88 ( V_31 , V_152 ) ;
break;
}
F_77 ( V_163 , V_152 ) ;
break;
default:
V_81 = - V_128 ;
}
return V_81 ;
}
static int F_89 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_168 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_81 = F_90 ( V_31 , & V_168 ) ;
if ( V_81 )
break;
V_81 = F_42 ( V_31 , V_55 , V_168 , 1 , V_22 , 0 ) ;
if ( V_81 ) {
F_91 ( V_31 , V_168 ) ;
break;
}
F_77 ( V_163 , V_168 ) ;
break;
default:
V_81 = - V_128 ;
}
return V_81 ;
}
static int F_92 ( struct V_30 * V_31 , int V_55 , T_1 V_169 , int V_62 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_170 * V_11 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
V_11 -> V_169 = V_169 ;
V_11 -> V_62 = ( T_2 ) V_62 ;
F_43 ( & V_11 -> V_124 ,
& V_122 -> V_39 [ V_55 ] . V_44 [ V_25 ] ) ;
return 0 ;
}
static void F_93 ( struct V_30 * V_31 , int V_55 , T_1 V_169 ,
int V_62 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_172 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
struct V_170 * V_11 , * V_173 ;
F_94 (res, tmp, mac_list, list) {
if ( V_11 -> V_169 == V_169 && V_11 -> V_62 == ( T_2 ) V_62 ) {
F_59 ( & V_11 -> V_124 ) ;
F_16 ( V_11 ) ;
break;
}
}
}
static void F_95 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_172 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
struct V_170 * V_11 , * V_173 ;
F_94 (res, tmp, mac_list, list) {
F_59 ( & V_11 -> V_124 ) ;
F_96 ( V_31 , V_11 -> V_62 , V_11 -> V_169 ) ;
F_16 ( V_11 ) ;
}
}
static int F_97 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_128 ;
int V_62 ;
T_1 V_169 ;
if ( V_160 != V_167 )
return V_81 ;
V_62 = F_73 ( V_163 ) ;
V_169 = V_162 ;
V_81 = F_98 ( V_31 , V_62 , V_169 ) ;
if ( V_81 >= 0 ) {
F_77 ( V_163 , V_81 ) ;
V_81 = 0 ;
}
if ( ! V_81 ) {
V_81 = F_92 ( V_31 , V_55 , V_169 , V_62 ) ;
if ( V_81 )
F_96 ( V_31 , V_62 , V_169 ) ;
}
return V_81 ;
}
static int F_99 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
return 0 ;
}
static int F_100 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
T_3 V_143 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_128 ;
V_81 = F_101 ( V_31 , & V_143 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_42 ( V_31 , V_55 , V_143 , 1 , V_27 , 0 ) ;
if ( V_81 )
F_102 ( V_31 , V_143 ) ;
else
F_77 ( V_163 , V_143 ) ;
return V_81 ;
}
static int F_103 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
T_3 V_174 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_128 ;
V_81 = F_104 ( V_31 , & V_174 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_42 ( V_31 , V_55 , V_174 , 1 , V_29 , 0 ) ;
if ( V_81 )
F_105 ( V_31 , V_174 ) ;
else
F_77 ( V_163 , V_174 ) ;
return V_81 ;
}
int F_106 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_179 = V_176 -> V_180 ;
switch ( V_176 -> V_181 ) {
case V_20 :
V_81 = F_72 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_24 :
V_81 = F_79 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_23 :
V_81 = F_82 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_21 :
V_81 = F_86 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_22 :
V_81 = F_89 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_25 :
V_81 = F_97 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_182 :
V_81 = F_99 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_27 :
V_81 = F_100 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_29 :
V_81 = F_103 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_107 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 )
{
int V_81 ;
int V_119 ;
int V_118 ;
int V_113 ;
switch ( V_160 ) {
case V_165 :
V_118 = F_73 ( & V_162 ) & 0x7fffff ;
V_119 = F_74 ( & V_162 ) ;
V_81 = F_58 ( V_31 , V_55 , V_118 , V_119 , V_20 , 0 ) ;
if ( V_81 )
break;
F_76 ( V_31 , V_118 , V_119 ) ;
break;
case V_166 :
V_113 = F_73 ( & V_162 ) & 0x7fffff ;
V_81 = F_60 ( V_31 , V_55 , V_113 , V_93 ,
NULL , 0 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_71 ( V_31 , V_113 ) )
F_108 ( V_31 , V_113 ) ;
F_66 ( V_31 , V_55 , V_20 , V_113 ) ;
if ( F_67 ( V_31 , V_55 , V_113 ) )
V_81 = F_58 ( V_31 , V_55 , V_113 , 1 , V_20 , 0 ) ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_109 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_128 ;
int V_118 ;
int V_98 ;
if ( V_160 != V_167 )
return V_81 ;
V_118 = F_73 ( & V_162 ) ;
V_98 = F_74 ( & V_162 ) ;
V_81 = F_58 ( V_31 , V_55 , V_118 , 1 , V_24 , V_98 ) ;
if ( ! V_81 )
F_81 ( V_31 , V_118 , V_98 ) ;
return V_81 ;
}
static int F_110 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 )
{
int V_81 = - V_128 ;
int V_143 ;
int V_89 ;
struct V_101 * V_145 ;
switch ( V_160 ) {
case V_165 :
V_143 = F_73 ( & V_162 ) ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_22 ( V_31 , V_55 , V_89 , V_23 , & V_145 ) ;
if ( V_81 )
break;
V_143 = V_145 -> V_100 ;
F_29 ( V_31 , V_55 , V_89 , V_23 ) ;
V_81 = F_58 ( V_31 , V_55 , V_89 , 1 , V_23 , 0 ) ;
if ( V_81 )
break;
F_84 ( V_31 , V_143 ) ;
break;
case V_166 :
V_143 = F_73 ( & V_162 ) ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_61 ( V_31 , V_55 , V_89 ,
V_102 , & V_145 ) ;
if ( V_81 )
return V_81 ;
F_111 ( V_31 , V_145 -> V_100 ) ;
F_66 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_112 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_152 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_152 = F_73 ( & V_162 ) ;
V_81 = F_58 ( V_31 , V_55 , V_152 , 1 , V_21 , 0 ) ;
if ( V_81 )
break;
F_88 ( V_31 , V_152 ) ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_113 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_168 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_168 = F_73 ( & V_162 ) ;
V_81 = F_58 ( V_31 , V_55 , V_168 , 1 , V_22 , 0 ) ;
if ( V_81 )
break;
F_91 ( V_31 , V_168 ) ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_114 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_62 ;
int V_81 = 0 ;
switch ( V_160 ) {
case V_167 :
V_62 = F_73 ( V_163 ) ;
F_93 ( V_31 , V_55 , V_162 , V_62 ) ;
F_96 ( V_31 , V_62 , V_162 ) ;
break;
default:
V_81 = - V_128 ;
break;
}
return V_81 ;
}
static int F_115 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
return 0 ;
}
static int F_116 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_143 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_128 ;
V_143 = F_73 ( & V_162 ) ;
V_81 = F_58 ( V_31 , V_55 , V_143 , 1 , V_27 , 0 ) ;
if ( V_81 )
return V_81 ;
F_102 ( V_31 , V_143 ) ;
return V_81 ;
}
static int F_117 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_174 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_128 ;
V_174 = F_73 ( & V_162 ) ;
V_81 = F_58 ( V_31 , V_55 , V_174 , 1 , V_29 , 0 ) ;
if ( V_81 )
return V_81 ;
F_105 ( V_31 , V_174 ) ;
return V_81 ;
}
int F_118 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 = - V_128 ;
int V_179 = V_176 -> V_180 ;
switch ( V_176 -> V_181 ) {
case V_20 :
V_81 = F_107 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 ) ;
break;
case V_24 :
V_81 = F_109 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_23 :
V_81 = F_110 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 ) ;
break;
case V_21 :
V_81 = F_112 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_22 :
V_81 = F_113 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_25 :
V_81 = F_114 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_182 :
V_81 = F_115 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_27 :
V_81 = F_116 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_29 :
V_81 = F_117 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
default:
break;
}
return V_81 ;
}
static int F_119 ( struct V_183 * V_145 )
{
return ( F_19 ( V_145 -> V_70 ) >> 9 ) & 1 ;
}
static int F_120 ( struct V_183 * V_145 )
{
return ( int ) F_121 ( V_145 -> V_184 ) & 0xfffffff8 ;
}
static int F_122 ( struct V_183 * V_145 )
{
return F_19 ( V_145 -> V_185 ) ;
}
static T_3 F_123 ( struct V_183 * V_145 )
{
return F_19 ( V_145 -> V_186 ) & 0x00ffffff ;
}
static int F_124 ( struct V_183 * V_145 )
{
return F_19 ( V_145 -> V_186 ) & V_187 ;
}
static int F_125 ( struct V_183 * V_145 )
{
return F_19 ( V_145 -> V_70 ) & V_188 ;
}
static int F_126 ( struct V_183 * V_145 )
{
return F_19 ( V_145 -> V_70 ) & V_189 ;
}
static int F_127 ( struct V_64 * V_190 )
{
return F_19 ( V_190 -> V_191 ) & 0xfffffff8 ;
}
static int F_128 ( struct V_192 * V_193 )
{
return F_19 ( V_193 -> V_191 ) & 0xfffffff8 ;
}
static int F_129 ( struct V_64 * V_190 )
{
int V_194 = ( V_190 -> V_195 & 0x3f ) + 12 ;
int V_196 = ( V_190 -> V_197 >> 3 ) & 0xf ;
int V_198 = V_190 -> V_197 & 7 ;
int V_199 = ( V_190 -> V_200 >> 3 ) & 0xf ;
int V_201 = V_190 -> V_200 & 7 ;
int V_156 = ( F_19 ( V_190 -> V_168 ) >> 24 ) & 1 ;
int V_202 = ( F_19 ( V_190 -> V_70 ) >> 13 ) & 1 ;
int V_203 = ( F_19 ( V_190 -> V_94 ) >> 23 ) & 1 ;
int V_204 ;
int V_205 ;
int V_206 ;
int V_207 ;
int V_208 = ( F_19 ( V_190 -> V_209 ) >> 6 ) & 0x3f ;
V_204 = 1 << ( V_196 + V_198 + 4 ) ;
V_205 = ( V_156 | V_202 | V_203 ) ? 0 : ( 1 << ( V_199 + V_201 + 4 ) ) ;
V_207 = V_204 + V_205 ;
V_206 =
F_130 ( ( V_207 + ( V_208 << 6 ) ) >>
V_194 ) ;
return V_206 ;
}
static int F_131 ( struct V_30 * V_31 , int V_55 , int V_210 ,
int V_211 , struct V_99 * V_212 )
{
int V_213 = V_212 -> V_92 . V_7 ;
int V_214 = ( 1 << V_212 -> V_98 ) ;
if ( V_210 < V_213 || V_210 + V_211 > V_213 + V_214 )
return - V_86 ;
return 0 ;
}
int F_132 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_143 = V_176 -> V_181 ;
struct V_99 * V_212 ;
struct V_101 * V_145 ;
int V_215 = F_120 ( V_57 -> V_59 ) / V_31 -> V_52 . V_216 ;
int V_217 ;
int V_89 ;
T_3 V_218 ;
int V_219 ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_61 ( V_31 , V_55 , V_89 , V_147 , & V_145 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_126 ( V_57 -> V_59 ) ) {
V_81 = - V_86 ;
goto V_220;
}
V_218 = F_123 ( V_57 -> V_59 ) ;
V_219 = ( V_218 >> 17 ) & 0x7f ;
if ( V_219 != 0 && V_219 != V_55 ) {
V_81 = - V_86 ;
goto V_220;
}
if ( F_124 ( V_57 -> V_59 ) ) {
if ( F_125 ( V_57 -> V_59 ) ) {
V_81 = - V_86 ;
goto V_220;
}
if ( ! F_126 ( V_57 -> V_59 ) ) {
V_81 = - V_86 ;
goto V_220;
}
}
V_217 = F_119 ( V_57 -> V_59 ) ;
if ( ! V_217 ) {
V_81 = F_22 ( V_31 , V_55 , V_215 , V_24 , & V_212 ) ;
if ( V_81 )
goto V_220;
V_81 = F_131 ( V_31 , V_55 , V_215 ,
F_122 ( V_57 -> V_59 ) , V_212 ) ;
if ( V_81 )
goto V_221;
V_145 -> V_212 = V_212 ;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_221;
if ( ! V_217 ) {
F_134 ( & V_212 -> V_97 ) ;
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
}
F_66 ( V_31 , V_55 , V_23 , V_89 ) ;
return 0 ;
V_221:
if ( ! V_217 )
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
V_220:
F_65 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
}
int F_135 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_143 = V_176 -> V_181 ;
struct V_101 * V_145 ;
int V_89 ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_61 ( V_31 , V_55 , V_89 , V_146 , & V_145 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_220;
if ( V_145 -> V_212 )
F_136 ( & V_145 -> V_212 -> V_97 ) ;
F_66 ( V_31 , V_55 , V_23 , V_89 ) ;
return 0 ;
V_220:
F_65 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
}
int F_137 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_143 = V_176 -> V_181 ;
struct V_101 * V_145 ;
int V_89 ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_22 ( V_31 , V_55 , V_89 , V_23 , & V_145 ) ;
if ( V_81 )
return V_81 ;
if ( V_145 -> V_92 . V_87 != V_147 ) {
V_81 = - V_84 ;
goto V_136;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_136:
F_29 ( V_31 , V_55 , V_89 , V_23 ) ;
return V_81 ;
}
static int F_138 ( struct V_64 * V_190 )
{
return F_19 ( V_190 -> V_222 ) & 0xffffff ;
}
static int F_139 ( struct V_64 * V_190 )
{
return F_19 ( V_190 -> V_223 ) & 0xffffff ;
}
static T_3 F_140 ( struct V_64 * V_190 )
{
return F_19 ( V_190 -> V_168 ) & 0x1ffffff ;
}
static void F_141 ( struct V_30 * V_31 , struct V_175 * V_176 ,
struct V_64 * V_224 )
{
T_3 V_113 = V_176 -> V_181 & 0xffffff ;
T_3 V_225 = 0 ;
if ( F_142 ( V_31 , V_113 , & V_225 ) )
return;
V_224 -> V_225 = F_143 ( V_225 ) ;
}
int F_144 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_113 = V_176 -> V_181 & 0x7fffff ;
struct V_99 * V_212 ;
struct V_90 * V_138 ;
struct V_64 * V_190 = V_57 -> V_59 + 8 ;
int V_215 = F_127 ( V_190 ) / V_31 -> V_52 . V_216 ;
int V_226 = F_129 ( V_190 ) ;
struct V_105 * V_227 ;
struct V_105 * V_228 ;
int V_229 = F_138 ( V_190 ) ;
int V_230 = F_139 ( V_190 ) ;
T_3 V_168 = F_140 ( V_190 ) & 0xffffff ;
int V_231 = ( F_140 ( V_190 ) >> 24 ) & 1 ;
struct V_107 * V_156 ;
int V_94 = F_19 ( V_190 -> V_94 ) & 0xffffff ;
V_81 = F_60 ( V_31 , V_55 , V_113 , V_141 , & V_138 , 0 ) ;
if ( V_81 )
return V_81 ;
V_138 -> V_94 = V_94 ;
V_81 = F_22 ( V_31 , V_55 , V_215 , V_24 , & V_212 ) ;
if ( V_81 )
goto V_220;
V_81 = F_131 ( V_31 , V_55 , V_215 , V_226 , V_212 ) ;
if ( V_81 )
goto V_232;
V_81 = F_22 ( V_31 , V_55 , V_229 , V_21 , & V_227 ) ;
if ( V_81 )
goto V_232;
if ( V_230 != V_229 ) {
V_81 = F_22 ( V_31 , V_55 , V_230 , V_21 , & V_228 ) ;
if ( V_81 )
goto V_233;
} else
V_228 = V_227 ;
if ( V_231 ) {
V_81 = F_22 ( V_31 , V_55 , V_168 , V_22 , & V_156 ) ;
if ( V_81 )
goto V_234;
}
F_141 ( V_31 , V_176 , V_190 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_235;
F_134 ( & V_212 -> V_97 ) ;
V_138 -> V_212 = V_212 ;
F_134 ( & V_227 -> V_97 ) ;
V_138 -> V_227 = V_227 ;
F_134 ( & V_228 -> V_97 ) ;
V_138 -> V_228 = V_228 ;
if ( V_230 != V_229 )
F_29 ( V_31 , V_55 , V_230 , V_21 ) ;
if ( V_231 ) {
F_134 ( & V_156 -> V_97 ) ;
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
V_138 -> V_156 = V_156 ;
}
F_29 ( V_31 , V_55 , V_229 , V_21 ) ;
F_29 ( V_31 , V_55 , V_215 , V_24 ) ;
F_66 ( V_31 , V_55 , V_20 , V_113 ) ;
return 0 ;
V_235:
if ( V_231 )
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
V_234:
if ( V_230 != V_229 )
F_29 ( V_31 , V_55 , V_230 , V_21 ) ;
V_233:
F_29 ( V_31 , V_55 , V_229 , V_21 ) ;
V_232:
F_29 ( V_31 , V_55 , V_215 , V_24 ) ;
V_220:
F_65 ( V_31 , V_55 , V_20 , V_113 ) ;
return V_81 ;
}
static int F_145 ( struct V_236 * V_237 )
{
return F_19 ( V_237 -> V_191 ) & 0xfffffff8 ;
}
static int F_146 ( struct V_236 * V_237 )
{
int V_238 = V_237 -> V_238 & 0x1f ;
int V_194 = ( V_237 -> V_195 & 0x3f ) + 12 ;
if ( V_238 + 5 < V_194 )
return 1 ;
return 1 << ( V_238 + 5 - V_194 ) ;
}
static int F_147 ( struct V_239 * V_240 )
{
return F_19 ( V_240 -> V_191 ) & 0xfffffff8 ;
}
static int F_148 ( struct V_239 * V_240 )
{
int V_241 = ( F_19 ( V_240 -> V_242 ) >> 24 ) & 0x1f ;
int V_194 = ( V_240 -> V_195 & 0x3f ) + 12 ;
if ( V_241 + 5 < V_194 )
return 1 ;
return 1 << ( V_241 + 5 - V_194 ) ;
}
int F_149 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_243 = V_176 -> V_181 ;
int V_7 = ( V_55 << 8 ) | V_243 ;
struct V_236 * V_237 = V_57 -> V_59 ;
int V_215 = F_145 ( V_237 ) / V_31 -> V_52 . V_216 ;
int V_226 = F_146 ( V_237 ) ;
struct V_103 * V_149 ;
struct V_99 * V_212 ;
V_81 = F_42 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_62 ( V_31 , V_55 , V_7 , V_151 , & V_149 ) ;
if ( V_81 )
goto V_244;
V_81 = F_22 ( V_31 , V_55 , V_215 , V_24 , & V_212 ) ;
if ( V_81 )
goto V_245;
V_81 = F_131 ( V_31 , V_55 , V_215 , V_226 , V_212 ) ;
if ( V_81 )
goto V_246;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_246;
F_134 ( & V_212 -> V_97 ) ;
V_149 -> V_212 = V_212 ;
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
F_66 ( V_31 , V_55 , V_26 , V_7 ) ;
return 0 ;
V_246:
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
V_245:
F_65 ( V_31 , V_55 , V_26 , V_7 ) ;
V_244:
F_58 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
return V_81 ;
}
static int F_150 ( struct V_30 * V_31 , int V_55 , int V_210 ,
int V_247 , struct V_99 * * V_11 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_99 * V_212 ;
int V_81 = - V_128 ;
F_23 ( F_24 ( V_31 ) ) ;
F_151 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_131 ( V_31 , V_55 , V_210 , V_247 , V_212 ) ) {
* V_11 = V_212 ;
V_212 -> V_92 . V_87 = V_212 -> V_92 . V_2 ;
V_212 -> V_92 . V_2 = V_3 ;
V_81 = 0 ;
break;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_152 ( struct V_30 * V_31 ,
struct V_56 * V_57 ,
enum V_248 V_249 , T_2 V_55 )
{
T_3 V_250 ;
struct V_64 * V_65 ;
enum V_66 V_67 ;
V_65 = V_57 -> V_59 + 8 ;
V_250 = ( F_19 ( V_65 -> V_70 ) >> 16 ) & 0xff ;
V_67 = F_19 ( * ( V_68 * ) V_57 -> V_59 ) ;
switch ( V_250 ) {
case V_74 :
case V_75 :
switch ( V_249 ) {
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
if ( V_55 != F_153 ( V_31 ) )
if ( V_67 & V_76 )
if ( V_65 -> V_72 . V_73 )
return - V_128 ;
if ( V_67 & V_77 )
if ( V_65 -> V_78 . V_73 )
return - V_128 ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
int F_154 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_256 V_212 ;
T_4 * V_257 = V_57 -> V_59 ;
T_1 * V_258 = ( T_1 * ) V_257 ;
int V_34 ;
struct V_99 * V_259 = NULL ;
int V_210 = F_121 ( V_257 [ 0 ] ) ;
int V_260 = V_176 -> V_181 ;
int V_81 ;
V_81 = F_150 ( V_31 , V_55 , V_210 , V_260 , & V_259 ) ;
if ( V_81 )
return V_81 ;
V_212 . V_261 = 0 ;
V_212 . V_98 = 0 ;
V_212 . V_194 = 0 ;
for ( V_34 = 0 ; V_34 < V_260 ; ++ V_34 )
V_258 [ V_34 + 2 ] = ( F_121 ( V_257 [ V_34 + 2 ] ) & ~ 1ULL ) ;
V_81 = F_155 ( V_31 , & V_212 , F_121 ( V_257 [ 0 ] ) , V_260 ,
( ( T_1 * ) V_257 + 2 ) ) ;
if ( V_259 )
F_29 ( V_31 , V_55 , V_259 -> V_92 . V_7 , V_24 ) ;
return V_81 ;
}
int F_156 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_243 = V_176 -> V_181 ;
int V_7 = V_243 | ( V_55 << 8 ) ;
struct V_103 * V_149 ;
int V_81 ;
V_81 = F_62 ( V_31 , V_55 , V_7 , V_104 , & V_149 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_149 -> V_212 -> V_92 . V_7 , V_24 , NULL ) ;
if ( V_81 )
goto V_220;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_221;
F_136 ( & V_149 -> V_212 -> V_97 ) ;
F_29 ( V_31 , V_55 , V_149 -> V_212 -> V_92 . V_7 , V_24 ) ;
F_66 ( V_31 , V_55 , V_26 , V_7 ) ;
F_58 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
return 0 ;
V_221:
F_29 ( V_31 , V_55 , V_149 -> V_212 -> V_92 . V_7 , V_24 ) ;
V_220:
F_65 ( V_31 , V_55 , V_26 , V_7 ) ;
return V_81 ;
}
int F_157 ( struct V_30 * V_31 , int V_55 , struct V_262 * V_263 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_264 * V_265 ;
struct V_56 * V_266 ;
T_3 V_181 = 0 ;
int V_81 ;
int V_7 ;
struct V_103 * V_267 ;
if ( ! V_33 -> V_36 . V_37 . V_268 )
return - V_128 ;
V_265 = & V_33 -> V_36 . V_37 . V_268 [ V_55 ] . V_265 [ V_263 -> type ] ;
if ( V_265 -> V_243 < 0 )
return 0 ;
F_158 ( & V_33 -> V_36 . V_37 . V_269 [ V_55 ] ) ;
V_7 = ( V_55 << 8 ) | V_265 -> V_243 ;
V_81 = F_22 ( V_31 , V_55 , V_7 , V_26 , & V_267 ) ;
if ( V_81 )
goto V_270;
if ( V_267 -> V_92 . V_87 != V_151 ) {
V_81 = - V_128 ;
goto V_271;
}
V_266 = F_159 ( V_31 ) ;
if ( F_160 ( V_266 ) ) {
V_81 = F_161 ( V_266 ) ;
goto V_271;
}
if ( V_263 -> type == V_272 ) {
++ V_265 -> V_273 ;
V_263 -> V_274 . V_161 . V_273 = F_162 ( V_265 -> V_273 ) ;
}
memcpy ( V_266 -> V_59 , ( T_2 * ) V_263 , 28 ) ;
V_181 = ( V_55 & 0xff ) | ( ( V_265 -> V_243 & 0xff ) << 16 ) ;
V_81 = F_163 ( V_31 , V_266 -> V_275 , V_181 , 0 ,
V_276 , V_277 ,
V_278 ) ;
F_29 ( V_31 , V_55 , V_7 , V_26 ) ;
F_164 ( & V_33 -> V_36 . V_37 . V_269 [ V_55 ] ) ;
F_165 ( V_31 , V_266 ) ;
return V_81 ;
V_271:
F_29 ( V_31 , V_55 , V_7 , V_26 ) ;
V_270:
F_164 ( & V_33 -> V_36 . V_37 . V_269 [ V_55 ] ) ;
return V_81 ;
}
int F_166 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_243 = V_176 -> V_181 ;
int V_7 = V_243 | ( V_55 << 8 ) ;
struct V_103 * V_149 ;
int V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_7 , V_26 , & V_149 ) ;
if ( V_81 )
return V_81 ;
if ( V_149 -> V_92 . V_87 != V_151 ) {
V_81 = - V_128 ;
goto V_221;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_221:
F_29 ( V_31 , V_55 , V_7 , V_26 ) ;
return V_81 ;
}
int F_167 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_152 = V_176 -> V_181 ;
struct V_239 * V_240 = V_57 -> V_59 ;
int V_215 = F_147 ( V_240 ) / V_31 -> V_52 . V_216 ;
struct V_105 * V_154 ;
struct V_99 * V_212 ;
V_81 = F_63 ( V_31 , V_55 , V_152 , V_155 , & V_154 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_215 , V_24 , & V_212 ) ;
if ( V_81 )
goto V_245;
V_81 = F_131 ( V_31 , V_55 , V_215 , F_148 ( V_240 ) , V_212 ) ;
if ( V_81 )
goto V_246;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_246;
F_134 ( & V_212 -> V_97 ) ;
V_154 -> V_212 = V_212 ;
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
F_66 ( V_31 , V_55 , V_21 , V_152 ) ;
return 0 ;
V_246:
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
V_245:
F_65 ( V_31 , V_55 , V_21 , V_152 ) ;
return V_81 ;
}
int F_168 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_152 = V_176 -> V_181 ;
struct V_105 * V_154 ;
V_81 = F_63 ( V_31 , V_55 , V_152 , V_106 , & V_154 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_245;
F_136 ( & V_154 -> V_212 -> V_97 ) ;
F_66 ( V_31 , V_55 , V_21 , V_152 ) ;
return 0 ;
V_245:
F_65 ( V_31 , V_55 , V_21 , V_152 ) ;
return V_81 ;
}
int F_169 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_152 = V_176 -> V_181 ;
struct V_105 * V_154 ;
int V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_152 , V_21 , & V_154 ) ;
if ( V_81 )
return V_81 ;
if ( V_154 -> V_92 . V_87 != V_155 )
goto V_221;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_221:
F_29 ( V_31 , V_55 , V_152 , V_21 ) ;
return V_81 ;
}
static int F_170 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 ,
struct V_105 * V_154 )
{
int V_81 ;
struct V_99 * V_279 ;
struct V_99 * V_212 ;
struct V_239 * V_240 = V_57 -> V_59 ;
int V_215 = F_147 ( V_240 ) / V_31 -> V_52 . V_216 ;
V_81 = F_22 ( V_31 , V_55 , V_154 -> V_212 -> V_92 . V_7 , V_24 , & V_279 ) ;
if ( V_81 )
return V_81 ;
if ( V_279 != V_154 -> V_212 ) {
V_81 = - V_128 ;
goto V_221;
}
V_81 = F_22 ( V_31 , V_55 , V_215 , V_24 , & V_212 ) ;
if ( V_81 )
goto V_221;
V_81 = F_131 ( V_31 , V_55 , V_215 , F_148 ( V_240 ) , V_212 ) ;
if ( V_81 )
goto V_280;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_280;
F_136 ( & V_279 -> V_97 ) ;
F_29 ( V_31 , V_55 , V_279 -> V_92 . V_7 , V_24 ) ;
F_134 ( & V_212 -> V_97 ) ;
V_154 -> V_212 = V_212 ;
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
return 0 ;
V_280:
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
V_221:
F_29 ( V_31 , V_55 , V_279 -> V_92 . V_7 , V_24 ) ;
return V_81 ;
}
int F_171 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_152 = V_176 -> V_181 ;
struct V_105 * V_154 ;
int V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_152 , V_21 , & V_154 ) ;
if ( V_81 )
return V_81 ;
if ( V_154 -> V_92 . V_87 != V_155 )
goto V_221;
if ( V_176 -> V_180 == 0 ) {
V_81 = F_170 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 , V_154 ) ;
goto V_221;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_221:
F_29 ( V_31 , V_55 , V_152 , V_21 ) ;
return V_81 ;
}
static int F_172 ( struct V_192 * V_193 )
{
int V_281 = ( F_19 ( V_193 -> V_282 ) >> 24 ) & 0xf ;
int V_201 = V_193 -> V_283 & 7 ;
int V_194 = ( V_193 -> V_195 & 0x3f ) + 12 ;
if ( V_281 + V_201 + 4 < V_194 )
return 1 ;
return 1 << ( V_281 + V_201 + 4 - V_194 ) ;
}
int F_173 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_168 = V_176 -> V_181 ;
struct V_99 * V_212 ;
struct V_107 * V_156 ;
struct V_192 * V_193 = V_57 -> V_59 ;
int V_215 = F_128 ( V_193 ) / V_31 -> V_52 . V_216 ;
if ( V_168 != ( F_19 ( V_193 -> V_282 ) & 0xffffff ) )
return - V_128 ;
V_81 = F_64 ( V_31 , V_55 , V_168 , V_157 , & V_156 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_215 , V_24 , & V_212 ) ;
if ( V_81 )
goto V_220;
V_81 = F_131 ( V_31 , V_55 , V_215 , F_172 ( V_193 ) ,
V_212 ) ;
if ( V_81 )
goto V_232;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_232;
F_134 ( & V_212 -> V_97 ) ;
V_156 -> V_212 = V_212 ;
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
F_66 ( V_31 , V_55 , V_22 , V_168 ) ;
return 0 ;
V_232:
F_29 ( V_31 , V_55 , V_212 -> V_92 . V_7 , V_24 ) ;
V_220:
F_65 ( V_31 , V_55 , V_22 , V_168 ) ;
return V_81 ;
}
int F_174 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_168 = V_176 -> V_181 ;
struct V_107 * V_156 ;
V_81 = F_64 ( V_31 , V_55 , V_168 , V_108 , & V_156 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_220;
F_136 ( & V_156 -> V_212 -> V_97 ) ;
if ( V_156 -> V_154 )
F_136 ( & V_156 -> V_154 -> V_97 ) ;
F_66 ( V_31 , V_55 , V_22 , V_168 ) ;
return 0 ;
V_220:
F_65 ( V_31 , V_55 , V_22 , V_168 ) ;
return V_81 ;
}
int F_175 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_168 = V_176 -> V_181 ;
struct V_107 * V_156 ;
V_81 = F_22 ( V_31 , V_55 , V_168 , V_22 , & V_156 ) ;
if ( V_81 )
return V_81 ;
if ( V_156 -> V_92 . V_87 != V_157 ) {
V_81 = - V_84 ;
goto V_136;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_136:
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
return V_81 ;
}
int F_176 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_168 = V_176 -> V_181 ;
struct V_107 * V_156 ;
V_81 = F_22 ( V_31 , V_55 , V_168 , V_22 , & V_156 ) ;
if ( V_81 )
return V_81 ;
if ( V_156 -> V_92 . V_87 != V_157 ) {
V_81 = - V_84 ;
goto V_136;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_136:
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
return V_81 ;
}
int F_177 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_113 = V_176 -> V_181 & 0x7fffff ;
struct V_90 * V_138 ;
V_81 = F_22 ( V_31 , V_55 , V_113 , V_20 , & V_138 ) ;
if ( V_81 )
return V_81 ;
if ( V_138 -> V_92 . V_87 != V_141 ) {
V_81 = - V_84 ;
goto V_136;
}
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_136:
F_29 ( V_31 , V_55 , V_113 , V_20 ) ;
return V_81 ;
}
int F_178 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_64 * V_224 = V_57 -> V_59 + 8 ;
F_141 ( V_31 , V_176 , V_224 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_179 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_190 = V_57 -> V_59 + 8 ;
V_81 = F_152 ( V_31 , V_57 , V_251 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_141 ( V_31 , V_176 , V_190 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_180 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_224 = V_57 -> V_59 + 8 ;
V_81 = F_152 ( V_31 , V_57 , V_252 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_141 ( V_31 , V_176 , V_224 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_181 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_224 = V_57 -> V_59 + 8 ;
V_81 = F_152 ( V_31 , V_57 , V_253 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_141 ( V_31 , V_176 , V_224 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_182 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_64 * V_224 = V_57 -> V_59 + 8 ;
F_141 ( V_31 , V_176 , V_224 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_183 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_224 = V_57 -> V_59 + 8 ;
V_81 = F_152 ( V_31 , V_57 , V_254 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_141 ( V_31 , V_176 , V_224 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_184 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_224 = V_57 -> V_59 + 8 ;
V_81 = F_152 ( V_31 , V_57 , V_255 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_141 ( V_31 , V_176 , V_224 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_177 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_185 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_113 = V_176 -> V_181 & 0x7fffff ;
struct V_90 * V_138 ;
V_81 = F_60 ( V_31 , V_55 , V_113 , V_140 , & V_138 , 0 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_220;
F_136 ( & V_138 -> V_212 -> V_97 ) ;
F_136 ( & V_138 -> V_227 -> V_97 ) ;
F_136 ( & V_138 -> V_228 -> V_97 ) ;
if ( V_138 -> V_156 )
F_136 ( & V_138 -> V_156 -> V_97 ) ;
F_66 ( V_31 , V_55 , V_20 , V_113 ) ;
return 0 ;
V_220:
F_65 ( V_31 , V_55 , V_20 , V_113 ) ;
return V_81 ;
}
static struct V_284 * F_186 ( struct V_30 * V_31 , int V_55 ,
struct V_90 * V_285 , T_2 * V_286 )
{
struct V_284 * V_11 ;
F_151 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_286 , V_286 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_187 ( struct V_30 * V_31 , int V_55 , struct V_90 * V_285 ,
T_2 * V_286 , enum V_287 V_288 ,
enum V_289 V_290 )
{
struct V_284 * V_11 ;
int V_81 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
F_23 ( & V_285 -> V_96 ) ;
if ( F_186 ( V_31 , V_55 , V_285 , V_286 ) ) {
F_16 ( V_11 ) ;
V_81 = - V_17 ;
} else {
memcpy ( V_11 -> V_286 , V_286 , 16 ) ;
V_11 -> V_288 = V_288 ;
V_11 -> V_290 = V_290 ;
F_43 ( & V_11 -> V_124 , & V_285 -> V_95 ) ;
V_81 = 0 ;
}
F_25 ( & V_285 -> V_96 ) ;
return V_81 ;
}
static int F_188 ( struct V_30 * V_31 , int V_55 , struct V_90 * V_285 ,
T_2 * V_286 , enum V_287 V_288 ,
enum V_289 V_290 )
{
struct V_284 * V_11 ;
int V_81 ;
F_23 ( & V_285 -> V_96 ) ;
V_11 = F_186 ( V_31 , V_55 , V_285 , V_286 ) ;
if ( ! V_11 || V_11 -> V_288 != V_288 || V_11 -> V_290 != V_290 )
V_81 = - V_128 ;
else {
F_59 ( & V_11 -> V_124 ) ;
F_16 ( V_11 ) ;
V_81 = 0 ;
}
F_25 ( & V_285 -> V_96 ) ;
return V_81 ;
}
int F_189 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_291 V_138 ;
T_2 * V_286 = V_57 -> V_59 ;
enum V_287 V_288 = ( V_176 -> V_181 >> 28 ) & 0x7 ;
int V_81 ;
int V_113 ;
struct V_90 * V_285 ;
int V_292 = V_176 -> V_180 ;
int V_293 = V_176 -> V_181 >> 31 ;
T_2 V_294 = 2 ;
enum V_289 type = ( V_286 [ 7 ] & V_294 ) >> 1 ;
if ( V_31 -> V_52 . V_295 != V_296 )
return - V_128 ;
V_113 = V_176 -> V_181 & 0xffffff ;
V_81 = F_22 ( V_31 , V_55 , V_113 , V_20 , & V_285 ) ;
if ( V_81 )
return V_81 ;
V_138 . V_113 = V_113 ;
if ( V_292 ) {
V_81 = F_187 ( V_31 , V_55 , V_285 , V_286 , V_288 , type ) ;
if ( V_81 )
goto V_221;
V_81 = F_190 ( V_31 , & V_138 , V_286 ,
V_293 , V_288 , type ) ;
if ( V_81 )
goto V_297;
} else {
V_81 = F_188 ( V_31 , V_55 , V_285 , V_286 , V_288 , type ) ;
if ( V_81 )
goto V_221;
V_81 = F_191 ( V_31 , & V_138 , V_286 , V_288 , type ) ;
}
F_29 ( V_31 , V_55 , V_113 , V_20 ) ;
return 0 ;
V_297:
( void ) F_188 ( V_31 , V_55 , V_285 , V_286 , V_288 , type ) ;
V_221:
F_29 ( V_31 , V_55 , V_113 , V_20 ) ;
return V_81 ;
}
static int F_192 ( int V_55 , struct V_298 * V_299 ,
struct V_171 * V_300 )
{
struct V_170 * V_11 , * V_173 ;
T_4 V_301 ;
if ( ! F_193 ( V_299 -> V_302 . V_303 ) &&
! F_194 ( V_299 -> V_302 . V_303 ) ) {
F_94 (res, tmp, rlist, list) {
V_301 = F_195 ( V_11 -> V_169 << 16 ) ;
if ( ! memcmp ( & V_301 , V_299 -> V_302 . V_303 , V_304 ) )
return 0 ;
}
F_48 ( L_21 ,
V_299 -> V_302 . V_303 , V_55 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_196 ( struct V_30 * V_31 , int V_55 ,
struct V_56 * V_57 ,
struct V_171 * V_300 , int V_305 )
{
struct V_170 * V_11 , * V_173 ;
T_2 V_62 ;
struct V_306 * V_307 ;
struct V_308 * V_299 ;
struct V_309 * V_310 ;
struct V_311 * V_312 ;
T_4 V_301 = 0 ;
T_4 V_313 = F_195 ( V_314 << 16 ) ;
V_307 = (struct V_306 * ) V_57 -> V_59 ;
V_62 = V_307 -> V_62 ;
V_299 = (struct V_308 * ) ( V_307 + 1 ) ;
switch ( V_305 ) {
case V_315 :
V_310 =
(struct V_309 * ) ( V_299 + 1 ) ;
memmove ( V_310 , V_299 ,
sizeof( * V_310 ) + sizeof( * V_312 ) ) ;
break;
case V_316 :
case V_317 :
V_312 = (struct V_311 * )
( V_299 + 1 ) ;
memmove ( V_312 , V_299 , sizeof( * V_312 ) ) ;
break;
default:
return - V_128 ;
}
F_94 (res, tmp, rlist, list) {
if ( V_62 == V_11 -> V_62 ) {
V_301 = F_195 ( V_11 -> V_169 << 16 ) ;
break;
}
}
if ( ! V_301 ) {
F_48 ( L_22 ,
V_62 ) ;
return - V_128 ;
}
memset ( V_299 , 0 , sizeof( * V_299 ) ) ;
V_299 -> V_211 = sizeof( * V_299 ) >> 2 ;
V_299 -> V_89 = F_162 ( V_318 [ V_319 ] ) ;
memcpy ( V_299 -> V_303 , & V_301 , V_304 ) ;
memcpy ( V_299 -> V_320 , & V_313 , V_304 ) ;
return 0 ;
}
int F_197 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_300 = & V_122 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
int V_81 ;
int V_113 ;
struct V_90 * V_285 ;
struct V_306 * V_307 ;
struct V_298 * V_321 ;
int V_305 ;
if ( V_31 -> V_52 . V_295 !=
V_322 )
return - V_323 ;
V_307 = (struct V_306 * ) V_57 -> V_59 ;
V_113 = F_19 ( V_307 -> V_113 ) & 0xffffff ;
V_81 = F_22 ( V_31 , V_55 , V_113 , V_20 , & V_285 ) ;
if ( V_81 ) {
F_48 ( L_23 , V_113 ) ;
return V_81 ;
}
V_321 = (struct V_298 * ) ( V_307 + 1 ) ;
V_305 = F_198 ( F_199 ( V_321 -> V_89 ) ) ;
switch ( V_305 ) {
case V_319 :
if ( F_192 ( V_55 , V_321 , V_300 ) ) {
V_81 = - V_128 ;
goto V_324;
}
break;
case V_325 :
break;
case V_315 :
case V_316 :
case V_317 :
F_200 ( L_24 ) ;
if ( F_196 ( V_31 , V_55 , V_57 , V_300 , V_305 ) ) {
V_81 = - V_128 ;
goto V_324;
}
V_176 -> V_181 +=
sizeof( struct V_308 ) >> 2 ;
break;
default:
F_48 ( L_25 ) ;
V_81 = - V_128 ;
goto V_324;
}
V_81 = F_201 ( V_31 , V_57 -> V_275 , & V_176 -> V_163 ,
V_176 -> V_181 , 0 ,
V_326 , V_327 ,
V_278 ) ;
if ( V_81 )
goto V_324;
V_81 = F_42 ( V_31 , V_55 , V_176 -> V_163 , 1 , V_28 , V_113 ) ;
if ( V_81 ) {
F_202 ( V_31 , L_26 ) ;
F_163 ( V_31 , V_176 -> V_163 , 0 , 0 ,
V_328 , V_327 ,
V_278 ) ;
goto V_324;
}
F_134 ( & V_285 -> V_97 ) ;
V_324:
F_29 ( V_31 , V_55 , V_113 , V_20 ) ;
return V_81 ;
}
int F_203 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_90 * V_285 ;
struct V_114 * V_329 ;
if ( V_31 -> V_52 . V_295 !=
V_322 )
return - V_323 ;
V_81 = F_22 ( V_31 , V_55 , V_176 -> V_162 , V_28 , & V_329 ) ;
if ( V_81 )
return V_81 ;
F_29 ( V_31 , V_55 , V_176 -> V_162 , V_28 ) ;
V_81 = F_22 ( V_31 , V_55 , V_329 -> V_113 , V_20 , & V_285 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_58 ( V_31 , V_55 , V_176 -> V_162 , 1 , V_28 , 0 ) ;
if ( V_81 ) {
F_202 ( V_31 , L_27 ) ;
goto V_136;
}
V_81 = F_163 ( V_31 , V_176 -> V_162 , 0 , 0 ,
V_328 , V_327 ,
V_278 ) ;
if ( ! V_81 )
F_136 ( & V_285 -> V_97 ) ;
V_136:
F_29 ( V_31 , V_55 , V_329 -> V_113 , V_20 ) ;
return V_81 ;
}
int F_204 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_143 = V_176 -> V_181 & 0xffff ;
V_81 = F_22 ( V_31 , V_55 , V_143 , V_27 , NULL ) ;
if ( V_81 )
return V_81 ;
V_81 = F_133 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
F_29 ( V_31 , V_55 , V_143 , V_27 ) ;
return V_81 ;
}
static void F_205 ( struct V_30 * V_31 , int V_55 , struct V_90 * V_285 )
{
struct V_284 * V_330 ;
struct V_284 * V_173 ;
struct V_291 V_138 ;
F_94 (rgid, tmp, &rqp->mcg_list, list) {
V_138 . V_113 = V_285 -> V_94 ;
( void ) F_191 ( V_31 , & V_138 , V_330 -> V_286 , V_330 -> V_288 ,
V_330 -> V_290 ) ;
F_59 ( & V_330 -> V_124 ) ;
F_16 ( V_330 ) ;
}
}
static int F_206 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_331 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_300 = & V_122 -> V_39 [ V_55 ] . V_44 [ type ] ;
struct V_10 * V_80 ;
struct V_10 * V_173 ;
int V_332 ;
V_332 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (r, tmp, rlist, list) {
if ( V_80 -> V_85 == V_55 ) {
if ( ! V_80 -> V_333 ) {
if ( V_80 -> V_2 == V_83 ) {
if ( V_331 )
F_12 ( V_31 ,
L_28 ,
F_7 ( type ) ,
V_80 -> V_7 ) ;
++ V_332 ;
} else {
V_80 -> V_87 = V_80 -> V_2 ;
V_80 -> V_2 = V_83 ;
V_80 -> V_333 = 1 ;
}
}
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_332 ;
}
static int F_207 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type )
{
unsigned long V_334 ;
int V_332 ;
V_334 = V_335 ;
do {
V_332 = F_206 ( V_31 , V_55 , type , 0 ) ;
if ( F_208 ( V_335 , V_334 + 5 * V_336 ) )
break;
if ( V_332 )
F_209 () ;
} while ( V_332 );
if ( V_332 )
V_332 = F_206 ( V_31 , V_55 , type , 1 ) ;
return V_332 ;
}
static void F_210 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_337 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_20 ] ;
struct V_90 * V_138 ;
struct V_90 * V_173 ;
int V_2 ;
T_1 V_162 ;
int V_113 ;
int V_81 ;
V_81 = F_207 ( V_31 , V_55 , V_20 ) ;
if ( V_81 )
F_211 ( V_31 , L_29
L_30 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (qp, tmp, qp_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_138 -> V_92 . V_85 == V_55 ) {
V_113 = V_138 -> V_92 . V_7 ;
F_205 ( V_31 , V_55 , V_138 ) ;
V_2 = V_138 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_93 :
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_138 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_20 ] ) ;
F_59 ( & V_138 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_138 ) ;
V_2 = 0 ;
break;
case V_140 :
if ( ! F_67 ( V_31 , V_55 , V_113 ) )
F_108 ( V_31 , V_113 ) ;
V_2 = V_93 ;
break;
case V_141 :
V_162 = V_55 ;
V_81 = F_163 ( V_31 , V_162 ,
V_138 -> V_94 , 2 ,
V_338 ,
V_327 ,
V_278 ) ;
if ( V_81 )
F_12 ( V_31 , L_31
L_32
L_33 , V_55 ,
V_138 -> V_94 ) ;
F_136 ( & V_138 -> V_227 -> V_97 ) ;
F_136 ( & V_138 -> V_228 -> V_97 ) ;
F_136 ( & V_138 -> V_212 -> V_97 ) ;
if ( V_138 -> V_156 )
F_136 ( & V_138 -> V_156 -> V_97 ) ;
V_2 = V_140 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_212 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_339 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_22 ] ;
struct V_107 * V_156 ;
struct V_107 * V_173 ;
int V_2 ;
T_1 V_162 ;
F_213 ( V_340 ) ;
int V_168 ;
int V_81 ;
V_81 = F_207 ( V_31 , V_55 , V_22 ) ;
if ( V_81 )
F_211 ( V_31 , L_34
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (srq, tmp, srq_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_156 -> V_92 . V_85 == V_55 ) {
V_168 = V_156 -> V_92 . V_7 ;
V_2 = V_156 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_108 :
F_91 ( V_31 , V_168 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_156 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_22 ] ) ;
F_59 ( & V_156 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_156 ) ;
V_2 = 0 ;
break;
case V_157 :
V_162 = V_55 ;
V_81 = F_163 ( V_31 , V_162 , V_168 , 1 ,
V_341 ,
V_327 ,
V_278 ) ;
if ( V_81 )
F_12 ( V_31 , L_36
L_37
L_38 ,
V_55 , V_168 ) ;
F_136 ( & V_156 -> V_212 -> V_97 ) ;
if ( V_156 -> V_154 )
F_136 ( & V_156 -> V_154 -> V_97 ) ;
V_2 = V_108 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_214 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_342 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_21 ] ;
struct V_105 * V_154 ;
struct V_105 * V_173 ;
int V_2 ;
T_1 V_162 ;
F_213 ( V_340 ) ;
int V_152 ;
int V_81 ;
V_81 = F_207 ( V_31 , V_55 , V_21 ) ;
if ( V_81 )
F_211 ( V_31 , L_39
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (cq, tmp, cq_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_154 -> V_92 . V_85 == V_55 && ! F_46 ( & V_154 -> V_97 ) ) {
V_152 = V_154 -> V_92 . V_7 ;
V_2 = V_154 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_106 :
F_88 ( V_31 , V_152 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_154 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_21 ] ) ;
F_59 ( & V_154 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_154 ) ;
V_2 = 0 ;
break;
case V_155 :
V_162 = V_55 ;
V_81 = F_163 ( V_31 , V_162 , V_152 , 1 ,
V_343 ,
V_327 ,
V_278 ) ;
if ( V_81 )
F_12 ( V_31 , L_40
L_41
L_38 ,
V_55 , V_152 ) ;
F_136 ( & V_154 -> V_212 -> V_97 ) ;
V_2 = V_106 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_215 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_344 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_23 ] ;
struct V_101 * V_145 ;
struct V_101 * V_173 ;
int V_2 ;
T_1 V_162 ;
F_213 ( V_340 ) ;
int V_345 ;
int V_81 ;
V_81 = F_207 ( V_31 , V_55 , V_23 ) ;
if ( V_81 )
F_211 ( V_31 , L_42
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (mpt, tmp, mpt_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_145 -> V_92 . V_85 == V_55 ) {
V_345 = V_145 -> V_92 . V_7 ;
V_2 = V_145 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_102 :
F_84 ( V_31 , V_145 -> V_100 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_145 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_23 ] ) ;
F_59 ( & V_145 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_145 ) ;
V_2 = 0 ;
break;
case V_146 :
F_111 ( V_31 , V_145 -> V_100 ) ;
V_2 = V_102 ;
break;
case V_147 :
V_162 = V_55 ;
V_81 = F_163 ( V_31 , V_162 , V_345 , 0 ,
V_346 ,
V_327 ,
V_278 ) ;
if ( V_81 )
F_12 ( V_31 , L_43
L_44
L_38 ,
V_55 , V_345 ) ;
if ( V_145 -> V_212 )
F_136 ( & V_145 -> V_212 -> V_97 ) ;
V_2 = V_146 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_216 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_347 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_24 ] ;
struct V_99 * V_212 ;
struct V_99 * V_173 ;
int V_2 ;
F_213 ( V_340 ) ;
int V_118 ;
int V_81 ;
V_81 = F_207 ( V_31 , V_55 , V_24 ) ;
if ( V_81 )
F_211 ( V_31 , L_45
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (mtt, tmp, mtt_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_212 -> V_92 . V_85 == V_55 ) {
V_118 = V_212 -> V_92 . V_7 ;
V_2 = V_212 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_81 ( V_31 , V_118 ,
V_212 -> V_98 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_212 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_24 ] ) ;
F_59 ( & V_212 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_212 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_217 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_348 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_28 ] ;
struct V_114 * V_349 ;
struct V_114 * V_173 ;
int V_2 ;
T_1 V_118 ;
int V_81 ;
V_81 = F_207 ( V_31 , V_55 , V_28 ) ;
if ( V_81 )
F_211 ( V_31 , L_46 ,
V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (fs_rule, tmp, fs_rule_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_349 -> V_92 . V_85 == V_55 ) {
V_118 = V_349 -> V_92 . V_7 ;
V_2 = V_349 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_115 :
V_81 = F_163 ( V_31 , V_118 , 0 , 0 ,
V_328 ,
V_327 ,
V_278 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_349 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_28 ] ) ;
F_59 ( & V_349 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_349 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_218 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_350 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_26 ] ;
struct V_103 * V_149 ;
struct V_103 * V_173 ;
int V_81 ;
int V_2 ;
F_213 ( V_340 ) ;
int V_243 ;
struct V_56 * V_266 ;
V_81 = F_207 ( V_31 , V_55 , V_26 ) ;
if ( V_81 )
F_211 ( V_31 , L_47
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (eq, tmp, eq_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_149 -> V_92 . V_85 == V_55 ) {
V_243 = V_149 -> V_92 . V_7 ;
V_2 = V_149 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_104 :
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_149 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_26 ] ) ;
F_59 ( & V_149 -> V_92 . V_124 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_149 ) ;
V_2 = 0 ;
break;
case V_151 :
V_266 = F_159 ( V_31 ) ;
if ( F_160 ( V_266 ) ) {
F_209 () ;
continue;
}
V_81 = F_219 ( V_31 , V_55 , 0 ,
V_243 & 0xff , 0 ,
V_351 ,
V_327 ,
V_278 ) ;
if ( V_81 )
F_12 ( V_31 , L_48
L_49
L_38 , V_55 , V_243 ) ;
F_165 ( V_31 , V_266 ) ;
F_136 ( & V_149 -> V_212 -> V_97 ) ;
V_2 = V_104 ;
break;
default:
V_2 = 0 ;
}
}
}
F_23 ( F_24 ( V_31 ) ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_220 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_352 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_27 ] ;
struct V_109 * V_353 ;
struct V_109 * V_173 ;
int V_81 ;
int V_143 ;
V_81 = F_207 ( V_31 , V_55 , V_27 ) ;
if ( V_81 )
F_211 ( V_31 , L_50
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (counter, tmp, counter_list, com.list) {
if ( V_353 -> V_92 . V_85 == V_55 ) {
V_143 = V_353 -> V_92 . V_7 ;
F_44 ( & V_353 -> V_92 . V_9 ,
& V_122 -> V_46 [ V_27 ] ) ;
F_59 ( & V_353 -> V_92 . V_124 ) ;
F_16 ( V_353 ) ;
F_102 ( V_31 , V_143 ) ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_221 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_121 * V_122 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_354 =
& V_122 -> V_39 [ V_55 ] . V_44 [ V_29 ] ;
struct V_111 * V_355 ;
struct V_111 * V_173 ;
int V_81 ;
int V_174 ;
V_81 = F_207 ( V_31 , V_55 , V_29 ) ;
if ( V_81 )
F_211 ( V_31 , L_51
L_35 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_94 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_355 -> V_92 . V_85 == V_55 ) {
V_174 = V_355 -> V_92 . V_7 ;
F_44 ( & V_355 -> V_92 . V_9 , & V_122 -> V_46 [ V_29 ] ) ;
F_59 ( & V_355 -> V_92 . V_124 ) ;
F_16 ( V_355 ) ;
F_105 ( V_31 , V_174 ) ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
}
void F_15 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
F_158 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_55 ] . V_45 ) ;
F_95 ( V_31 , V_55 ) ;
F_217 ( V_31 , V_55 ) ;
F_210 ( V_31 , V_55 ) ;
F_212 ( V_31 , V_55 ) ;
F_214 ( V_31 , V_55 ) ;
F_215 ( V_31 , V_55 ) ;
F_218 ( V_31 , V_55 ) ;
F_216 ( V_31 , V_55 ) ;
F_220 ( V_31 , V_55 ) ;
F_221 ( V_31 , V_55 ) ;
F_164 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_55 ] . V_45 ) ;
}
