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
static void * F_21 ( struct V_30 * V_31 , int V_7 ,
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
return & V_91 -> V_92 ;
}
static struct V_10 * F_31 ( int V_89 , int V_97 )
{
struct V_98 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_97 = V_97 ;
V_91 -> V_92 . V_2 = V_4 ;
F_32 ( & V_91 -> V_99 , 0 ) ;
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
F_32 ( & V_91 -> V_99 , 0 ) ;
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
F_32 ( & V_91 -> V_99 , 0 ) ;
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
static struct V_10 * F_39 ( T_1 V_89 )
{
struct V_113 * V_91 ;
V_91 = F_9 ( sizeof *V_91 , V_41 ) ;
if ( ! V_91 )
return NULL ;
V_91 -> V_92 . V_7 = V_89 ;
V_91 -> V_92 . V_2 = V_114 ;
return & V_91 -> V_92 ;
}
static struct V_10 * F_40 ( T_1 V_89 , enum V_18 type , int V_55 ,
int V_115 )
{
struct V_10 * V_91 ;
switch ( type ) {
case V_20 :
V_91 = F_30 ( V_89 ) ;
break;
case V_23 :
V_91 = F_33 ( V_89 , V_115 ) ;
break;
case V_24 :
V_91 = F_31 ( V_89 , V_115 ) ;
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
F_41 ( V_116 L_16 ) ;
return NULL ;
case V_27 :
V_91 = F_37 ( V_89 ) ;
break;
case V_29 :
V_91 = F_38 ( V_89 ) ;
break;
case V_28 :
V_91 = F_39 ( V_89 ) ;
break;
default:
return NULL ;
}
if ( V_91 )
V_91 -> V_85 = V_55 ;
return V_91 ;
}
static int F_42 ( struct V_30 * V_31 , int V_55 , T_1 V_117 , int V_118 ,
enum V_18 type , int V_115 )
{
int V_34 ;
int V_81 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_10 * * V_119 ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_5 * V_6 = & V_121 -> V_46 [ type ] ;
V_119 = F_9 ( V_118 * sizeof *V_119 , V_41 ) ;
if ( ! V_119 )
return - V_42 ;
for ( V_34 = 0 ; V_34 < V_118 ; ++ V_34 ) {
V_119 [ V_34 ] = F_40 ( V_117 + V_34 , type , V_55 , V_115 ) ;
if ( ! V_119 [ V_34 ] ) {
for ( -- V_34 ; V_34 >= 0 ; -- V_34 )
F_16 ( V_119 [ V_34 ] ) ;
F_16 ( V_119 ) ;
return - V_42 ;
}
}
F_23 ( F_24 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_118 ; ++ V_34 ) {
if ( F_21 ( V_31 , V_117 + V_34 , type ) ) {
V_81 = - V_17 ;
goto V_122;
}
V_81 = F_4 ( V_6 , V_119 [ V_34 ] ) ;
if ( V_81 )
goto V_122;
F_43 ( & V_119 [ V_34 ] -> V_123 ,
& V_121 -> V_39 [ V_55 ] . V_44 [ type ] ) ;
}
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_119 ) ;
return 0 ;
V_122:
for ( -- V_34 ; V_34 >= V_117 ; -- V_34 )
F_44 ( & V_119 [ V_34 ] -> V_9 , V_6 ) ;
F_25 ( F_24 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_118 ; ++ V_34 )
F_16 ( V_119 [ V_34 ] ) ;
F_16 ( V_119 ) ;
return V_81 ;
}
static int F_45 ( struct V_90 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_124 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_93 )
return - V_86 ;
return 0 ;
}
static int F_46 ( struct V_98 * V_11 , int V_97 )
{
if ( V_11 -> V_92 . V_2 == V_3 ||
F_47 ( & V_11 -> V_99 ) ) {
F_41 ( V_125 L_17 ,
V_126 , __LINE__ ,
F_1 ( V_11 -> V_92 . V_2 ) ,
F_47 ( & V_11 -> V_99 ) ) ;
return - V_84 ;
} else if ( V_11 -> V_92 . V_2 != V_4 )
return - V_86 ;
else if ( V_11 -> V_97 != V_97 )
return - V_127 ;
return 0 ;
}
static int F_48 ( struct V_101 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_128 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_102 )
return - V_86 ;
return 0 ;
}
static int F_49 ( struct V_103 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_128 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_102 )
return - V_86 ;
return 0 ;
}
static int F_50 ( struct V_109 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_129 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_110 )
return - V_86 ;
return 0 ;
}
static int F_51 ( struct V_111 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_130 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_112 )
return - V_86 ;
return 0 ;
}
static int F_52 ( struct V_113 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_131 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_114 )
return - V_86 ;
return 0 ;
}
static int F_53 ( struct V_105 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_132 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_106 )
return - V_86 ;
return 0 ;
}
static int F_54 ( struct V_107 * V_11 )
{
if ( V_11 -> V_92 . V_2 == V_133 )
return - V_84 ;
else if ( V_11 -> V_92 . V_2 != V_108 )
return - V_86 ;
return 0 ;
}
static int F_55 ( struct V_10 * V_11 , enum V_18 type , int V_115 )
{
switch ( type ) {
case V_20 :
return F_45 ( (struct V_90 * ) V_11 ) ;
case V_21 :
return F_53 ( (struct V_105 * ) V_11 ) ;
case V_22 :
return F_54 ( (struct V_107 * ) V_11 ) ;
case V_23 :
return F_48 ( (struct V_101 * ) V_11 ) ;
case V_24 :
return F_46 ( (struct V_98 * ) V_11 , V_115 ) ;
case V_25 :
return - V_134 ;
case V_26 :
return F_49 ( (struct V_103 * ) V_11 ) ;
case V_27 :
return F_50 ( (struct V_109 * ) V_11 ) ;
case V_29 :
return F_51 ( (struct V_111 * ) V_11 ) ;
case V_28 :
return F_52 ( (struct V_113 * ) V_11 ) ;
default:
return - V_127 ;
}
}
static int F_56 ( struct V_30 * V_31 , int V_55 , T_1 V_117 , int V_118 ,
enum V_18 type , int V_115 )
{
T_1 V_34 ;
int V_81 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
for ( V_34 = V_117 ; V_34 < V_117 + V_118 ; ++ V_34 ) {
V_80 = F_2 ( & V_121 -> V_46 [ type ] , V_34 ) ;
if ( ! V_80 ) {
V_81 = - V_88 ;
goto V_135;
}
if ( V_80 -> V_85 != V_55 ) {
V_81 = - V_86 ;
goto V_135;
}
V_81 = F_55 ( V_80 , type , V_115 ) ;
if ( V_81 )
goto V_135;
}
for ( V_34 = V_117 ; V_34 < V_117 + V_118 ; ++ V_34 ) {
V_80 = F_2 ( & V_121 -> V_46 [ type ] , V_34 ) ;
F_44 ( & V_80 -> V_9 , & V_121 -> V_46 [ type ] ) ;
F_57 ( & V_80 -> V_123 ) ;
F_16 ( V_80 ) ;
}
V_81 = 0 ;
V_135:
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_58 ( struct V_30 * V_31 , int V_55 , int V_136 ,
enum V_137 V_2 , struct V_90 * * V_138 ,
int V_139 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_90 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ V_20 ] , V_136 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_124 :
F_12 ( V_31 , L_18 ,
V_126 , V_80 -> V_92 . V_7 ) ;
V_81 = - V_84 ;
break;
case V_93 :
if ( V_80 -> V_92 . V_2 == V_140 && ! V_139 )
break;
F_12 ( V_31 , L_19 , V_80 -> V_92 . V_7 ) ;
V_81 = - V_127 ;
break;
case V_140 :
if ( ( V_80 -> V_92 . V_2 == V_93 && V_139 ) ||
V_80 -> V_92 . V_2 == V_141 )
break;
else {
F_12 ( V_31 , L_19 ,
V_80 -> V_92 . V_7 ) ;
V_81 = - V_127 ;
}
break;
case V_141 :
if ( V_80 -> V_92 . V_2 != V_140 )
V_81 = - V_127 ;
break;
default:
V_81 = - V_127 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_124 ;
if ( V_138 )
* V_138 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_59 ( struct V_30 * V_31 , int V_55 , int V_143 ,
enum V_144 V_2 , struct V_101 * * V_145 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_101 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ V_23 ] , V_143 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_128 :
V_81 = - V_127 ;
break;
case V_102 :
if ( V_80 -> V_92 . V_2 != V_146 )
V_81 = - V_127 ;
break;
case V_146 :
if ( V_80 -> V_92 . V_2 != V_102 &&
V_80 -> V_92 . V_2 != V_147 )
V_81 = - V_127 ;
break;
case V_147 :
if ( V_80 -> V_92 . V_2 != V_146 )
V_81 = - V_127 ;
break;
default:
V_81 = - V_127 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_128 ;
if ( V_145 )
* V_145 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_60 ( struct V_30 * V_31 , int V_55 , int V_143 ,
enum V_148 V_2 , struct V_103 * * V_149 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_103 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ V_26 ] , V_143 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_150 :
V_81 = - V_127 ;
break;
case V_104 :
if ( V_80 -> V_92 . V_2 != V_151 )
V_81 = - V_127 ;
break;
case V_151 :
if ( V_80 -> V_92 . V_2 != V_104 )
V_81 = - V_127 ;
break;
default:
V_81 = - V_127 ;
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
static int F_61 ( struct V_30 * V_31 , int V_55 , int V_152 ,
enum V_153 V_2 , struct V_105 * * V_154 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_105 * V_80 ;
int V_81 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ V_21 ] , V_152 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_132 :
V_81 = - V_84 ;
break;
case V_106 :
if ( V_80 -> V_92 . V_2 != V_155 )
V_81 = - V_127 ;
else if ( F_47 ( & V_80 -> V_99 ) )
V_81 = - V_84 ;
else
V_81 = 0 ;
break;
case V_155 :
if ( V_80 -> V_92 . V_2 != V_106 )
V_81 = - V_127 ;
else
V_81 = 0 ;
break;
default:
V_81 = - V_127 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_132 ;
if ( V_154 )
* V_154 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_62 ( struct V_30 * V_31 , int V_55 , int V_143 ,
enum V_153 V_2 , struct V_107 * * V_156 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_107 * V_80 ;
int V_81 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ V_22 ] , V_143 ) ;
if ( ! V_80 )
V_81 = - V_88 ;
else if ( V_80 -> V_92 . V_85 != V_55 )
V_81 = - V_86 ;
else {
switch ( V_2 ) {
case V_133 :
V_81 = - V_127 ;
break;
case V_108 :
if ( V_80 -> V_92 . V_2 != V_157 )
V_81 = - V_127 ;
else if ( F_47 ( & V_80 -> V_99 ) )
V_81 = - V_84 ;
break;
case V_157 :
if ( V_80 -> V_92 . V_2 != V_108 )
V_81 = - V_127 ;
break;
default:
V_81 = - V_127 ;
}
if ( ! V_81 ) {
V_80 -> V_92 . V_87 = V_80 -> V_92 . V_2 ;
V_80 -> V_92 . V_142 = V_2 ;
V_80 -> V_92 . V_2 = V_133 ;
if ( V_156 )
* V_156 = V_80 ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static void F_63 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_89 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ type ] , V_89 ) ;
if ( V_80 && ( V_80 -> V_85 == V_55 ) )
V_80 -> V_2 = V_80 -> V_87 ;
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_64 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_89 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_80 ;
F_23 ( F_24 ( V_31 ) ) ;
V_80 = F_2 ( & V_121 -> V_46 [ type ] , V_89 ) ;
if ( V_80 && ( V_80 -> V_85 == V_55 ) )
V_80 -> V_2 = V_80 -> V_142 ;
F_25 ( F_24 ( V_31 ) ) ;
}
static int F_65 ( struct V_30 * V_31 , int V_55 , int V_136 )
{
return F_66 ( V_31 , V_136 ) &&
( F_67 ( V_31 ) || F_68 ( V_31 , V_55 , V_136 ) ) ;
}
static int F_69 ( struct V_30 * V_31 , int V_136 )
{
return V_136 < V_31 -> V_52 . V_158 [ V_159 ] ;
}
static int F_70 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 ;
int V_118 ;
int V_164 ;
int V_117 ;
int V_136 ;
switch ( V_160 ) {
case V_165 :
V_118 = F_71 ( & V_162 ) ;
V_164 = F_72 ( & V_162 ) ;
V_81 = F_73 ( V_31 , V_118 , V_164 , & V_117 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_42 ( V_31 , V_55 , V_117 , V_118 , V_20 , 0 ) ;
if ( V_81 ) {
F_74 ( V_31 , V_117 , V_118 ) ;
return V_81 ;
}
F_75 ( V_163 , V_117 ) ;
break;
case V_166 :
V_136 = F_71 ( & V_162 ) & 0x7fffff ;
if ( F_65 ( V_31 , V_55 , V_136 ) ) {
V_81 = F_42 ( V_31 , V_55 , V_136 , 1 , V_20 , 0 ) ;
if ( V_81 )
return V_81 ;
}
V_81 = F_58 ( V_31 , V_55 , V_136 , V_140 ,
NULL , 1 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_69 ( V_31 , V_136 ) ) {
V_81 = F_76 ( V_31 , V_136 ) ;
if ( V_81 ) {
F_63 ( V_31 , V_55 , V_20 , V_136 ) ;
return V_81 ;
}
}
F_64 ( V_31 , V_55 , V_20 , V_136 ) ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_77 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_127 ;
int V_117 ;
int V_97 ;
if ( V_160 != V_167 )
return V_81 ;
V_97 = F_71 ( & V_162 ) ;
V_117 = F_78 ( V_31 , V_97 ) ;
if ( V_117 == - 1 )
return - V_42 ;
V_81 = F_42 ( V_31 , V_55 , V_117 , 1 , V_24 , V_97 ) ;
if ( V_81 )
F_79 ( V_31 , V_117 , V_97 ) ;
else
F_75 ( V_163 , V_117 ) ;
return V_81 ;
}
static int F_80 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_127 ;
int V_143 ;
int V_89 ;
struct V_101 * V_145 ;
switch ( V_160 ) {
case V_165 :
V_143 = F_81 ( V_31 ) ;
if ( V_143 == - 1 )
break;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_42 ( V_31 , V_55 , V_89 , 1 , V_23 , V_143 ) ;
if ( V_81 ) {
F_82 ( V_31 , V_143 ) ;
break;
}
F_75 ( V_163 , V_143 ) ;
break;
case V_166 :
V_143 = F_71 ( & V_162 ) ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_59 ( V_31 , V_55 , V_89 ,
V_146 , & V_145 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_83 ( V_31 , V_145 -> V_100 ) ;
if ( V_81 ) {
F_63 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
}
F_64 ( V_31 , V_55 , V_23 , V_89 ) ;
break;
}
return V_81 ;
}
static int F_84 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_152 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_81 = F_85 ( V_31 , & V_152 ) ;
if ( V_81 )
break;
V_81 = F_42 ( V_31 , V_55 , V_152 , 1 , V_21 , 0 ) ;
if ( V_81 ) {
F_86 ( V_31 , V_152 ) ;
break;
}
F_75 ( V_163 , V_152 ) ;
break;
default:
V_81 = - V_127 ;
}
return V_81 ;
}
static int F_87 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_168 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_81 = F_88 ( V_31 , & V_168 ) ;
if ( V_81 )
break;
V_81 = F_42 ( V_31 , V_55 , V_168 , 1 , V_22 , 0 ) ;
if ( V_81 ) {
F_89 ( V_31 , V_168 ) ;
break;
}
F_75 ( V_163 , V_168 ) ;
break;
default:
V_81 = - V_127 ;
}
return V_81 ;
}
static int F_90 ( struct V_30 * V_31 , int V_55 , T_1 V_169 , int V_62 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_170 * V_11 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
V_11 -> V_169 = V_169 ;
V_11 -> V_62 = ( T_2 ) V_62 ;
F_43 ( & V_11 -> V_123 ,
& V_121 -> V_39 [ V_55 ] . V_44 [ V_25 ] ) ;
return 0 ;
}
static void F_91 ( struct V_30 * V_31 , int V_55 , T_1 V_169 ,
int V_62 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_172 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
struct V_170 * V_11 , * V_173 ;
F_92 (res, tmp, mac_list, list) {
if ( V_11 -> V_169 == V_169 && V_11 -> V_62 == ( T_2 ) V_62 ) {
F_57 ( & V_11 -> V_123 ) ;
F_16 ( V_11 ) ;
break;
}
}
}
static void F_93 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_172 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
struct V_170 * V_11 , * V_173 ;
F_92 (res, tmp, mac_list, list) {
F_57 ( & V_11 -> V_123 ) ;
F_94 ( V_31 , V_11 -> V_62 , V_11 -> V_169 ) ;
F_16 ( V_11 ) ;
}
}
static int F_95 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_127 ;
int V_62 ;
T_1 V_169 ;
if ( V_160 != V_167 )
return V_81 ;
V_62 = F_71 ( V_163 ) ;
V_169 = V_162 ;
V_81 = F_96 ( V_31 , V_62 , V_169 ) ;
if ( V_81 >= 0 ) {
F_75 ( V_163 , V_81 ) ;
V_81 = 0 ;
}
if ( ! V_81 ) {
V_81 = F_90 ( V_31 , V_55 , V_169 , V_62 ) ;
if ( V_81 )
F_94 ( V_31 , V_62 , V_169 ) ;
}
return V_81 ;
}
static int F_97 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
return 0 ;
}
static int F_98 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
T_3 V_143 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_127 ;
V_81 = F_99 ( V_31 , & V_143 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_42 ( V_31 , V_55 , V_143 , 1 , V_27 , 0 ) ;
if ( V_81 )
F_100 ( V_31 , V_143 ) ;
else
F_75 ( V_163 , V_143 ) ;
return V_81 ;
}
static int F_101 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
T_3 V_174 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_127 ;
V_81 = F_102 ( V_31 , & V_174 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_42 ( V_31 , V_55 , V_174 , 1 , V_29 , 0 ) ;
if ( V_81 )
F_103 ( V_31 , V_174 ) ;
else
F_75 ( V_163 , V_174 ) ;
return V_81 ;
}
int F_104 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_179 = V_176 -> V_180 ;
switch ( V_176 -> V_181 ) {
case V_20 :
V_81 = F_70 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_24 :
V_81 = F_77 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_23 :
V_81 = F_80 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_21 :
V_81 = F_84 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_22 :
V_81 = F_87 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_25 :
V_81 = F_95 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_182 :
V_81 = F_97 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_27 :
V_81 = F_98 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_29 :
V_81 = F_101 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_105 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 )
{
int V_81 ;
int V_118 ;
int V_117 ;
int V_136 ;
switch ( V_160 ) {
case V_165 :
V_117 = F_71 ( & V_162 ) & 0x7fffff ;
V_118 = F_72 ( & V_162 ) ;
V_81 = F_56 ( V_31 , V_55 , V_117 , V_118 , V_20 , 0 ) ;
if ( V_81 )
break;
F_74 ( V_31 , V_117 , V_118 ) ;
break;
case V_166 :
V_136 = F_71 ( & V_162 ) & 0x7fffff ;
V_81 = F_58 ( V_31 , V_55 , V_136 , V_93 ,
NULL , 0 ) ;
if ( V_81 )
return V_81 ;
if ( ! F_69 ( V_31 , V_136 ) )
F_106 ( V_31 , V_136 ) ;
F_64 ( V_31 , V_55 , V_20 , V_136 ) ;
if ( F_65 ( V_31 , V_55 , V_136 ) )
V_81 = F_56 ( V_31 , V_55 , V_136 , 1 , V_20 , 0 ) ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_107 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_81 = - V_127 ;
int V_117 ;
int V_97 ;
if ( V_160 != V_167 )
return V_81 ;
V_117 = F_71 ( & V_162 ) ;
V_97 = F_72 ( & V_162 ) ;
V_81 = F_56 ( V_31 , V_55 , V_117 , 1 , V_24 , V_97 ) ;
if ( ! V_81 )
F_79 ( V_31 , V_117 , V_97 ) ;
return V_81 ;
}
static int F_108 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 )
{
int V_81 = - V_127 ;
int V_143 ;
int V_89 ;
struct V_101 * V_145 ;
switch ( V_160 ) {
case V_165 :
V_143 = F_71 ( & V_162 ) ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_22 ( V_31 , V_55 , V_89 , V_23 , & V_145 ) ;
if ( V_81 )
break;
V_143 = V_145 -> V_100 ;
F_29 ( V_31 , V_55 , V_89 , V_23 ) ;
V_81 = F_56 ( V_31 , V_55 , V_89 , 1 , V_23 , 0 ) ;
if ( V_81 )
break;
F_82 ( V_31 , V_143 ) ;
break;
case V_166 :
V_143 = F_71 ( & V_162 ) ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_59 ( V_31 , V_55 , V_89 ,
V_102 , & V_145 ) ;
if ( V_81 )
return V_81 ;
F_109 ( V_31 , V_145 -> V_100 ) ;
F_64 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_110 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_152 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_152 = F_71 ( & V_162 ) ;
V_81 = F_56 ( V_31 , V_55 , V_152 , 1 , V_21 , 0 ) ;
if ( V_81 )
break;
F_86 ( V_31 , V_152 ) ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_111 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_168 ;
int V_81 ;
switch ( V_160 ) {
case V_167 :
V_168 = F_71 ( & V_162 ) ;
V_81 = F_56 ( V_31 , V_55 , V_168 , 1 , V_22 , 0 ) ;
if ( V_81 )
break;
F_89 ( V_31 , V_168 ) ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_112 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_62 ;
int V_81 = 0 ;
switch ( V_160 ) {
case V_167 :
V_62 = F_71 ( V_163 ) ;
F_91 ( V_31 , V_55 , V_162 , V_62 ) ;
F_94 ( V_31 , V_62 , V_162 ) ;
break;
default:
V_81 = - V_127 ;
break;
}
return V_81 ;
}
static int F_113 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
return 0 ;
}
static int F_114 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_143 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_127 ;
V_143 = F_71 ( & V_162 ) ;
V_81 = F_56 ( V_31 , V_55 , V_143 , 1 , V_27 , 0 ) ;
if ( V_81 )
return V_81 ;
F_100 ( V_31 , V_143 ) ;
return V_81 ;
}
static int F_115 ( struct V_30 * V_31 , int V_55 , int V_160 , int V_161 ,
T_1 V_162 , T_1 * V_163 )
{
int V_174 ;
int V_81 ;
if ( V_160 != V_165 )
return - V_127 ;
V_174 = F_71 ( & V_162 ) ;
V_81 = F_56 ( V_31 , V_55 , V_174 , 1 , V_29 , 0 ) ;
if ( V_81 )
return V_81 ;
F_103 ( V_31 , V_174 ) ;
return V_81 ;
}
int F_116 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 = - V_127 ;
int V_179 = V_176 -> V_180 ;
switch ( V_176 -> V_181 ) {
case V_20 :
V_81 = F_105 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 ) ;
break;
case V_24 :
V_81 = F_107 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_23 :
V_81 = F_108 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 ) ;
break;
case V_21 :
V_81 = F_110 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_22 :
V_81 = F_111 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_25 :
V_81 = F_112 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_182 :
V_81 = F_113 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_27 :
V_81 = F_114 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
break;
case V_29 :
V_81 = F_115 ( V_31 , V_55 , V_176 -> V_180 , V_179 ,
V_176 -> V_162 , & V_176 -> V_163 ) ;
default:
break;
}
return V_81 ;
}
static int F_117 ( struct V_183 * V_145 )
{
return ( F_19 ( V_145 -> V_70 ) >> 9 ) & 1 ;
}
static int F_118 ( struct V_183 * V_145 )
{
return ( int ) F_119 ( V_145 -> V_184 ) & 0xfffffff8 ;
}
static int F_120 ( struct V_183 * V_145 )
{
return F_19 ( V_145 -> V_185 ) ;
}
static int F_121 ( struct V_64 * V_186 )
{
return F_19 ( V_186 -> V_187 ) & 0xfffffff8 ;
}
static int F_122 ( struct V_188 * V_189 )
{
return F_19 ( V_189 -> V_187 ) & 0xfffffff8 ;
}
static int F_123 ( struct V_64 * V_186 )
{
int V_190 = ( V_186 -> V_191 & 0x3f ) + 12 ;
int V_192 = ( V_186 -> V_193 >> 3 ) & 0xf ;
int V_194 = V_186 -> V_193 & 7 ;
int V_195 = ( V_186 -> V_196 >> 3 ) & 0xf ;
int V_197 = V_186 -> V_196 & 7 ;
int V_156 = ( F_19 ( V_186 -> V_168 ) >> 24 ) & 1 ;
int V_198 = ( F_19 ( V_186 -> V_70 ) >> 13 ) & 1 ;
int V_199 = ( F_19 ( V_186 -> V_94 ) >> 23 ) & 1 ;
int V_200 ;
int V_201 ;
int V_202 ;
int V_203 ;
int V_204 = ( F_19 ( V_186 -> V_205 ) >> 6 ) & 0x3f ;
V_200 = 1 << ( V_192 + V_194 + 4 ) ;
V_201 = ( V_156 | V_198 | V_199 ) ? 0 : ( 1 << ( V_195 + V_197 + 4 ) ) ;
V_203 = V_200 + V_201 ;
V_202 =
F_124 ( ( V_203 + ( V_204 << 6 ) ) >>
V_190 ) ;
return V_202 ;
}
static int F_125 ( struct V_30 * V_31 , int V_55 , int V_206 ,
int V_207 , struct V_98 * V_208 )
{
int V_209 = V_208 -> V_92 . V_7 ;
int V_210 = ( 1 << V_208 -> V_97 ) ;
if ( V_206 < V_209 || V_206 + V_207 > V_209 + V_210 )
return - V_86 ;
return 0 ;
}
int F_126 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_143 = V_176 -> V_181 ;
struct V_98 * V_208 ;
struct V_101 * V_145 ;
int V_211 = F_118 ( V_57 -> V_59 ) / V_31 -> V_52 . V_212 ;
int V_213 ;
int V_89 ;
V_89 = V_143 & F_20 ( V_31 ) ;
V_81 = F_59 ( V_31 , V_55 , V_89 , V_147 , & V_145 ) ;
if ( V_81 )
return V_81 ;
V_213 = F_117 ( V_57 -> V_59 ) ;
if ( ! V_213 ) {
V_81 = F_22 ( V_31 , V_55 , V_211 , V_24 , & V_208 ) ;
if ( V_81 )
goto V_214;
V_81 = F_125 ( V_31 , V_55 , V_211 ,
F_120 ( V_57 -> V_59 ) , V_208 ) ;
if ( V_81 )
goto V_215;
V_145 -> V_208 = V_208 ;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_215;
if ( ! V_213 ) {
F_128 ( & V_208 -> V_99 ) ;
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
}
F_64 ( V_31 , V_55 , V_23 , V_89 ) ;
return 0 ;
V_215:
if ( ! V_213 )
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
V_214:
F_63 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
}
int F_129 ( struct V_30 * V_31 , int V_55 ,
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
V_81 = F_59 ( V_31 , V_55 , V_89 , V_146 , & V_145 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_214;
if ( V_145 -> V_208 )
F_130 ( & V_145 -> V_208 -> V_99 ) ;
F_64 ( V_31 , V_55 , V_23 , V_89 ) ;
return 0 ;
V_214:
F_63 ( V_31 , V_55 , V_23 , V_89 ) ;
return V_81 ;
}
int F_131 ( struct V_30 * V_31 , int V_55 ,
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
goto V_135;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_135:
F_29 ( V_31 , V_55 , V_89 , V_23 ) ;
return V_81 ;
}
static int F_132 ( struct V_64 * V_186 )
{
return F_19 ( V_186 -> V_216 ) & 0xffffff ;
}
static int F_133 ( struct V_64 * V_186 )
{
return F_19 ( V_186 -> V_217 ) & 0xffffff ;
}
static T_3 F_134 ( struct V_64 * V_186 )
{
return F_19 ( V_186 -> V_168 ) & 0x1ffffff ;
}
static void F_135 ( struct V_30 * V_31 , struct V_175 * V_176 ,
struct V_64 * V_218 )
{
T_3 V_136 = V_176 -> V_181 & 0xffffff ;
T_3 V_219 = 0 ;
if ( F_136 ( V_31 , V_136 , & V_219 ) )
return;
V_218 -> V_219 = F_137 ( V_219 ) ;
}
int F_138 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_136 = V_176 -> V_181 & 0x7fffff ;
struct V_98 * V_208 ;
struct V_90 * V_138 ;
struct V_64 * V_186 = V_57 -> V_59 + 8 ;
int V_211 = F_121 ( V_186 ) / V_31 -> V_52 . V_212 ;
int V_220 = F_123 ( V_186 ) ;
struct V_105 * V_221 ;
struct V_105 * V_222 ;
int V_223 = F_132 ( V_186 ) ;
int V_224 = F_133 ( V_186 ) ;
T_3 V_168 = F_134 ( V_186 ) & 0xffffff ;
int V_225 = ( F_134 ( V_186 ) >> 24 ) & 1 ;
struct V_107 * V_156 ;
int V_94 = F_19 ( V_186 -> V_94 ) & 0xffffff ;
V_81 = F_58 ( V_31 , V_55 , V_136 , V_141 , & V_138 , 0 ) ;
if ( V_81 )
return V_81 ;
V_138 -> V_94 = V_94 ;
V_81 = F_22 ( V_31 , V_55 , V_211 , V_24 , & V_208 ) ;
if ( V_81 )
goto V_214;
V_81 = F_125 ( V_31 , V_55 , V_211 , V_220 , V_208 ) ;
if ( V_81 )
goto V_226;
V_81 = F_22 ( V_31 , V_55 , V_223 , V_21 , & V_221 ) ;
if ( V_81 )
goto V_226;
if ( V_224 != V_223 ) {
V_81 = F_22 ( V_31 , V_55 , V_224 , V_21 , & V_222 ) ;
if ( V_81 )
goto V_227;
} else
V_222 = V_221 ;
if ( V_225 ) {
V_81 = F_22 ( V_31 , V_55 , V_168 , V_22 , & V_156 ) ;
if ( V_81 )
goto V_228;
}
F_135 ( V_31 , V_176 , V_186 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_229;
F_128 ( & V_208 -> V_99 ) ;
V_138 -> V_208 = V_208 ;
F_128 ( & V_221 -> V_99 ) ;
V_138 -> V_221 = V_221 ;
F_128 ( & V_222 -> V_99 ) ;
V_138 -> V_222 = V_222 ;
if ( V_224 != V_223 )
F_29 ( V_31 , V_55 , V_224 , V_21 ) ;
if ( V_225 ) {
F_128 ( & V_156 -> V_99 ) ;
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
V_138 -> V_156 = V_156 ;
}
F_29 ( V_31 , V_55 , V_223 , V_21 ) ;
F_29 ( V_31 , V_55 , V_211 , V_24 ) ;
F_64 ( V_31 , V_55 , V_20 , V_136 ) ;
return 0 ;
V_229:
if ( V_225 )
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
V_228:
if ( V_224 != V_223 )
F_29 ( V_31 , V_55 , V_224 , V_21 ) ;
V_227:
F_29 ( V_31 , V_55 , V_223 , V_21 ) ;
V_226:
F_29 ( V_31 , V_55 , V_211 , V_24 ) ;
V_214:
F_63 ( V_31 , V_55 , V_20 , V_136 ) ;
return V_81 ;
}
static int F_139 ( struct V_230 * V_231 )
{
return F_19 ( V_231 -> V_187 ) & 0xfffffff8 ;
}
static int F_140 ( struct V_230 * V_231 )
{
int V_232 = V_231 -> V_232 & 0x1f ;
int V_190 = ( V_231 -> V_191 & 0x3f ) + 12 ;
if ( V_232 + 5 < V_190 )
return 1 ;
return 1 << ( V_232 + 5 - V_190 ) ;
}
static int F_141 ( struct V_233 * V_234 )
{
return F_19 ( V_234 -> V_187 ) & 0xfffffff8 ;
}
static int F_142 ( struct V_233 * V_234 )
{
int V_235 = ( F_19 ( V_234 -> V_236 ) >> 24 ) & 0x1f ;
int V_190 = ( V_234 -> V_191 & 0x3f ) + 12 ;
if ( V_235 + 5 < V_190 )
return 1 ;
return 1 << ( V_235 + 5 - V_190 ) ;
}
int F_143 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_237 = V_176 -> V_181 ;
int V_7 = ( V_55 << 8 ) | V_237 ;
struct V_230 * V_231 = V_57 -> V_59 ;
int V_211 = F_139 ( V_231 ) / V_31 -> V_52 . V_212 ;
int V_220 = F_140 ( V_231 ) ;
struct V_103 * V_149 ;
struct V_98 * V_208 ;
V_81 = F_42 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_60 ( V_31 , V_55 , V_7 , V_151 , & V_149 ) ;
if ( V_81 )
goto V_238;
V_81 = F_22 ( V_31 , V_55 , V_211 , V_24 , & V_208 ) ;
if ( V_81 )
goto V_239;
V_81 = F_125 ( V_31 , V_55 , V_211 , V_220 , V_208 ) ;
if ( V_81 )
goto V_240;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_240;
F_128 ( & V_208 -> V_99 ) ;
V_149 -> V_208 = V_208 ;
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
F_64 ( V_31 , V_55 , V_26 , V_7 ) ;
return 0 ;
V_240:
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
V_239:
F_63 ( V_31 , V_55 , V_26 , V_7 ) ;
V_238:
F_56 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
return V_81 ;
}
static int F_144 ( struct V_30 * V_31 , int V_55 , int V_206 ,
int V_241 , struct V_98 * * V_11 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_98 * V_208 ;
int V_81 = - V_127 ;
F_23 ( F_24 ( V_31 ) ) ;
F_145 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_125 ( V_31 , V_55 , V_206 , V_241 , V_208 ) ) {
* V_11 = V_208 ;
V_208 -> V_92 . V_87 = V_208 -> V_92 . V_2 ;
V_208 -> V_92 . V_2 = V_3 ;
V_81 = 0 ;
break;
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_81 ;
}
static int F_146 ( struct V_30 * V_31 ,
struct V_56 * V_57 ,
enum V_242 V_243 , T_2 V_55 )
{
T_3 V_244 ;
struct V_64 * V_65 ;
enum V_66 V_67 ;
V_65 = V_57 -> V_59 + 8 ;
V_244 = ( F_19 ( V_65 -> V_70 ) >> 16 ) & 0xff ;
V_67 = F_19 ( * ( V_68 * ) V_57 -> V_59 ) ;
switch ( V_244 ) {
case V_74 :
case V_75 :
switch ( V_243 ) {
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
if ( V_55 != F_147 ( V_31 ) )
if ( V_67 & V_76 )
if ( V_65 -> V_72 . V_73 )
return - V_127 ;
if ( V_67 & V_77 )
if ( V_65 -> V_78 . V_73 )
return - V_127 ;
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
int F_148 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_250 V_208 ;
T_4 * V_251 = V_57 -> V_59 ;
T_1 * V_252 = ( T_1 * ) V_251 ;
int V_34 ;
struct V_98 * V_253 = NULL ;
int V_206 = F_119 ( V_251 [ 0 ] ) ;
int V_254 = V_176 -> V_181 ;
int V_81 ;
V_81 = F_144 ( V_31 , V_55 , V_206 , V_254 , & V_253 ) ;
if ( V_81 )
return V_81 ;
V_208 . V_255 = 0 ;
V_208 . V_97 = 0 ;
V_208 . V_190 = 0 ;
for ( V_34 = 0 ; V_34 < V_254 ; ++ V_34 )
V_252 [ V_34 + 2 ] = ( F_119 ( V_251 [ V_34 + 2 ] ) & ~ 1ULL ) ;
V_81 = F_149 ( V_31 , & V_208 , F_119 ( V_251 [ 0 ] ) , V_254 ,
( ( T_1 * ) V_251 + 2 ) ) ;
if ( V_253 )
F_29 ( V_31 , V_55 , V_253 -> V_92 . V_7 , V_24 ) ;
return V_81 ;
}
int F_150 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_237 = V_176 -> V_181 ;
int V_7 = V_237 | ( V_55 << 8 ) ;
struct V_103 * V_149 ;
int V_81 ;
V_81 = F_60 ( V_31 , V_55 , V_7 , V_104 , & V_149 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_149 -> V_208 -> V_92 . V_7 , V_24 , NULL ) ;
if ( V_81 )
goto V_214;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_215;
F_130 ( & V_149 -> V_208 -> V_99 ) ;
F_29 ( V_31 , V_55 , V_149 -> V_208 -> V_92 . V_7 , V_24 ) ;
F_64 ( V_31 , V_55 , V_26 , V_7 ) ;
F_56 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
return 0 ;
V_215:
F_29 ( V_31 , V_55 , V_149 -> V_208 -> V_92 . V_7 , V_24 ) ;
V_214:
F_63 ( V_31 , V_55 , V_26 , V_7 ) ;
return V_81 ;
}
int F_151 ( struct V_30 * V_31 , int V_55 , struct V_256 * V_257 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_258 * V_259 ;
struct V_56 * V_260 ;
T_3 V_181 = 0 ;
int V_81 ;
int V_7 ;
struct V_103 * V_261 ;
if ( ! V_33 -> V_36 . V_37 . V_262 )
return - V_127 ;
V_259 = & V_33 -> V_36 . V_37 . V_262 [ V_55 ] . V_259 [ V_257 -> type ] ;
if ( V_259 -> V_237 < 0 )
return 0 ;
F_152 ( & V_33 -> V_36 . V_37 . V_263 [ V_55 ] ) ;
V_7 = ( V_55 << 8 ) | V_259 -> V_237 ;
V_81 = F_22 ( V_31 , V_55 , V_7 , V_26 , & V_261 ) ;
if ( V_81 )
goto V_264;
if ( V_261 -> V_92 . V_87 != V_151 ) {
V_81 = - V_127 ;
goto V_265;
}
V_260 = F_153 ( V_31 ) ;
if ( F_154 ( V_260 ) ) {
V_81 = F_155 ( V_260 ) ;
goto V_265;
}
if ( V_257 -> type == V_266 ) {
++ V_259 -> V_267 ;
V_257 -> V_268 . V_161 . V_267 = F_156 ( V_259 -> V_267 ) ;
}
memcpy ( V_260 -> V_59 , ( T_2 * ) V_257 , 28 ) ;
V_181 = ( V_55 & 0xff ) | ( ( V_259 -> V_237 & 0xff ) << 16 ) ;
V_81 = F_157 ( V_31 , V_260 -> V_269 , V_181 , 0 ,
V_270 , V_271 ,
V_272 ) ;
F_29 ( V_31 , V_55 , V_7 , V_26 ) ;
F_158 ( & V_33 -> V_36 . V_37 . V_263 [ V_55 ] ) ;
F_159 ( V_31 , V_260 ) ;
return V_81 ;
V_265:
F_29 ( V_31 , V_55 , V_7 , V_26 ) ;
V_264:
F_158 ( & V_33 -> V_36 . V_37 . V_263 [ V_55 ] ) ;
return V_81 ;
}
int F_160 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_237 = V_176 -> V_181 ;
int V_7 = V_237 | ( V_55 << 8 ) ;
struct V_103 * V_149 ;
int V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_7 , V_26 , & V_149 ) ;
if ( V_81 )
return V_81 ;
if ( V_149 -> V_92 . V_87 != V_151 ) {
V_81 = - V_127 ;
goto V_215;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_215:
F_29 ( V_31 , V_55 , V_7 , V_26 ) ;
return V_81 ;
}
int F_161 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_152 = V_176 -> V_181 ;
struct V_233 * V_234 = V_57 -> V_59 ;
int V_211 = F_141 ( V_234 ) / V_31 -> V_52 . V_212 ;
struct V_105 * V_154 ;
struct V_98 * V_208 ;
V_81 = F_61 ( V_31 , V_55 , V_152 , V_155 , & V_154 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_211 , V_24 , & V_208 ) ;
if ( V_81 )
goto V_239;
V_81 = F_125 ( V_31 , V_55 , V_211 , F_142 ( V_234 ) , V_208 ) ;
if ( V_81 )
goto V_240;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_240;
F_128 ( & V_208 -> V_99 ) ;
V_154 -> V_208 = V_208 ;
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
F_64 ( V_31 , V_55 , V_21 , V_152 ) ;
return 0 ;
V_240:
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
V_239:
F_63 ( V_31 , V_55 , V_21 , V_152 ) ;
return V_81 ;
}
int F_162 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_152 = V_176 -> V_181 ;
struct V_105 * V_154 ;
V_81 = F_61 ( V_31 , V_55 , V_152 , V_106 , & V_154 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_239;
F_130 ( & V_154 -> V_208 -> V_99 ) ;
F_64 ( V_31 , V_55 , V_21 , V_152 ) ;
return 0 ;
V_239:
F_63 ( V_31 , V_55 , V_21 , V_152 ) ;
return V_81 ;
}
int F_163 ( struct V_30 * V_31 , int V_55 ,
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
goto V_215;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_215:
F_29 ( V_31 , V_55 , V_152 , V_21 ) ;
return V_81 ;
}
static int F_164 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 ,
struct V_105 * V_154 )
{
int V_81 ;
struct V_98 * V_273 ;
struct V_98 * V_208 ;
struct V_233 * V_234 = V_57 -> V_59 ;
int V_211 = F_141 ( V_234 ) / V_31 -> V_52 . V_212 ;
V_81 = F_22 ( V_31 , V_55 , V_154 -> V_208 -> V_92 . V_7 , V_24 , & V_273 ) ;
if ( V_81 )
return V_81 ;
if ( V_273 != V_154 -> V_208 ) {
V_81 = - V_127 ;
goto V_215;
}
V_81 = F_22 ( V_31 , V_55 , V_211 , V_24 , & V_208 ) ;
if ( V_81 )
goto V_215;
V_81 = F_125 ( V_31 , V_55 , V_211 , F_142 ( V_234 ) , V_208 ) ;
if ( V_81 )
goto V_274;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_274;
F_130 ( & V_273 -> V_99 ) ;
F_29 ( V_31 , V_55 , V_273 -> V_92 . V_7 , V_24 ) ;
F_128 ( & V_208 -> V_99 ) ;
V_154 -> V_208 = V_208 ;
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
return 0 ;
V_274:
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
V_215:
F_29 ( V_31 , V_55 , V_273 -> V_92 . V_7 , V_24 ) ;
return V_81 ;
}
int F_165 ( struct V_30 * V_31 , int V_55 ,
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
goto V_215;
if ( V_176 -> V_180 == 0 ) {
V_81 = F_164 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 , V_154 ) ;
goto V_215;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_215:
F_29 ( V_31 , V_55 , V_152 , V_21 ) ;
return V_81 ;
}
static int F_166 ( struct V_188 * V_189 )
{
int V_275 = ( F_19 ( V_189 -> V_276 ) >> 24 ) & 0xf ;
int V_197 = V_189 -> V_277 & 7 ;
int V_190 = ( V_189 -> V_191 & 0x3f ) + 12 ;
if ( V_275 + V_197 + 4 < V_190 )
return 1 ;
return 1 << ( V_275 + V_197 + 4 - V_190 ) ;
}
int F_167 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_168 = V_176 -> V_181 ;
struct V_98 * V_208 ;
struct V_107 * V_156 ;
struct V_188 * V_189 = V_57 -> V_59 ;
int V_211 = F_122 ( V_189 ) / V_31 -> V_52 . V_212 ;
if ( V_168 != ( F_19 ( V_189 -> V_276 ) & 0xffffff ) )
return - V_127 ;
V_81 = F_62 ( V_31 , V_55 , V_168 , V_157 , & V_156 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_31 , V_55 , V_211 , V_24 , & V_208 ) ;
if ( V_81 )
goto V_214;
V_81 = F_125 ( V_31 , V_55 , V_211 , F_166 ( V_189 ) ,
V_208 ) ;
if ( V_81 )
goto V_226;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_226;
F_128 ( & V_208 -> V_99 ) ;
V_156 -> V_208 = V_208 ;
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
F_64 ( V_31 , V_55 , V_22 , V_168 ) ;
return 0 ;
V_226:
F_29 ( V_31 , V_55 , V_208 -> V_92 . V_7 , V_24 ) ;
V_214:
F_63 ( V_31 , V_55 , V_22 , V_168 ) ;
return V_81 ;
}
int F_168 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_168 = V_176 -> V_181 ;
struct V_107 * V_156 ;
V_81 = F_62 ( V_31 , V_55 , V_168 , V_108 , & V_156 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_214;
F_130 ( & V_156 -> V_208 -> V_99 ) ;
if ( V_156 -> V_154 )
F_130 ( & V_156 -> V_154 -> V_99 ) ;
F_64 ( V_31 , V_55 , V_22 , V_168 ) ;
return 0 ;
V_214:
F_63 ( V_31 , V_55 , V_22 , V_168 ) ;
return V_81 ;
}
int F_169 ( struct V_30 * V_31 , int V_55 ,
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
goto V_135;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_135:
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
return V_81 ;
}
int F_170 ( struct V_30 * V_31 , int V_55 ,
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
goto V_135;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_135:
F_29 ( V_31 , V_55 , V_168 , V_22 ) ;
return V_81 ;
}
int F_171 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_136 = V_176 -> V_181 & 0x7fffff ;
struct V_90 * V_138 ;
V_81 = F_22 ( V_31 , V_55 , V_136 , V_20 , & V_138 ) ;
if ( V_81 )
return V_81 ;
if ( V_138 -> V_92 . V_87 != V_141 ) {
V_81 = - V_84 ;
goto V_135;
}
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
V_135:
F_29 ( V_31 , V_55 , V_136 , V_20 ) ;
return V_81 ;
}
int F_172 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_64 * V_218 = V_57 -> V_59 + 8 ;
F_135 ( V_31 , V_176 , V_218 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_173 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_186 = V_57 -> V_59 + 8 ;
V_81 = F_146 ( V_31 , V_57 , V_245 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_135 ( V_31 , V_176 , V_186 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_174 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_218 = V_57 -> V_59 + 8 ;
V_81 = F_146 ( V_31 , V_57 , V_246 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_135 ( V_31 , V_176 , V_218 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_175 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_218 = V_57 -> V_59 + 8 ;
V_81 = F_146 ( V_31 , V_57 , V_247 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_135 ( V_31 , V_176 , V_218 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_176 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_64 * V_218 = V_57 -> V_59 + 8 ;
F_135 ( V_31 , V_176 , V_218 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_177 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_218 = V_57 -> V_59 + 8 ;
V_81 = F_146 ( V_31 , V_57 , V_248 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_135 ( V_31 , V_176 , V_218 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_178 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
struct V_64 * V_218 = V_57 -> V_59 + 8 ;
V_81 = F_146 ( V_31 , V_57 , V_249 , V_55 ) ;
if ( V_81 )
return V_81 ;
F_135 ( V_31 , V_176 , V_218 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_171 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
}
int F_179 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
int V_136 = V_176 -> V_181 & 0x7fffff ;
struct V_90 * V_138 ;
V_81 = F_58 ( V_31 , V_55 , V_136 , V_140 , & V_138 , 0 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
if ( V_81 )
goto V_214;
F_130 ( & V_138 -> V_208 -> V_99 ) ;
F_130 ( & V_138 -> V_221 -> V_99 ) ;
F_130 ( & V_138 -> V_222 -> V_99 ) ;
if ( V_138 -> V_156 )
F_130 ( & V_138 -> V_156 -> V_99 ) ;
F_64 ( V_31 , V_55 , V_20 , V_136 ) ;
return 0 ;
V_214:
F_63 ( V_31 , V_55 , V_20 , V_136 ) ;
return V_81 ;
}
static struct V_278 * F_180 ( struct V_30 * V_31 , int V_55 ,
struct V_90 * V_279 , T_2 * V_280 )
{
struct V_278 * V_11 ;
F_145 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_280 , V_280 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_181 ( struct V_30 * V_31 , int V_55 , struct V_90 * V_279 ,
T_2 * V_280 , enum V_281 V_282 ,
enum V_283 V_284 )
{
struct V_278 * V_11 ;
int V_81 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
F_23 ( & V_279 -> V_96 ) ;
if ( F_180 ( V_31 , V_55 , V_279 , V_280 ) ) {
F_16 ( V_11 ) ;
V_81 = - V_17 ;
} else {
memcpy ( V_11 -> V_280 , V_280 , 16 ) ;
V_11 -> V_282 = V_282 ;
V_11 -> V_284 = V_284 ;
F_43 ( & V_11 -> V_123 , & V_279 -> V_95 ) ;
V_81 = 0 ;
}
F_25 ( & V_279 -> V_96 ) ;
return V_81 ;
}
static int F_182 ( struct V_30 * V_31 , int V_55 , struct V_90 * V_279 ,
T_2 * V_280 , enum V_281 V_282 ,
enum V_283 V_284 )
{
struct V_278 * V_11 ;
int V_81 ;
F_23 ( & V_279 -> V_96 ) ;
V_11 = F_180 ( V_31 , V_55 , V_279 , V_280 ) ;
if ( ! V_11 || V_11 -> V_282 != V_282 || V_11 -> V_284 != V_284 )
V_81 = - V_127 ;
else {
F_57 ( & V_11 -> V_123 ) ;
F_16 ( V_11 ) ;
V_81 = 0 ;
}
F_25 ( & V_279 -> V_96 ) ;
return V_81 ;
}
int F_183 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_285 V_138 ;
T_2 * V_280 = V_57 -> V_59 ;
enum V_281 V_282 = ( V_176 -> V_181 >> 28 ) & 0x7 ;
int V_81 ;
int V_136 ;
struct V_90 * V_279 ;
int V_286 = V_176 -> V_180 ;
int V_287 = V_176 -> V_181 >> 31 ;
T_2 V_288 = 2 ;
enum V_283 type = ( V_280 [ 7 ] & V_288 ) >> 1 ;
V_136 = V_176 -> V_181 & 0xffffff ;
V_81 = F_22 ( V_31 , V_55 , V_136 , V_20 , & V_279 ) ;
if ( V_81 )
return V_81 ;
V_138 . V_136 = V_136 ;
if ( V_286 ) {
V_81 = F_181 ( V_31 , V_55 , V_279 , V_280 , V_282 , type ) ;
if ( V_81 )
goto V_215;
V_81 = F_184 ( V_31 , & V_138 , V_280 ,
V_287 , V_282 , type ) ;
if ( V_81 )
goto V_289;
} else {
V_81 = F_182 ( V_31 , V_55 , V_279 , V_280 , V_282 , type ) ;
if ( V_81 )
goto V_215;
V_81 = F_185 ( V_31 , & V_138 , V_280 , V_282 , type ) ;
}
F_29 ( V_31 , V_55 , V_136 , V_20 ) ;
return 0 ;
V_289:
( void ) F_182 ( V_31 , V_55 , V_279 , V_280 , V_282 , type ) ;
V_215:
F_29 ( V_31 , V_55 , V_136 , V_20 ) ;
return V_81 ;
}
static int F_186 ( int V_55 , struct V_290 * V_291 ,
struct V_171 * V_292 )
{
struct V_170 * V_11 , * V_173 ;
T_4 V_293 ;
if ( ! F_187 ( V_291 -> V_294 . V_295 ) &&
! F_188 ( V_291 -> V_294 . V_295 ) ) {
F_92 (res, tmp, rlist, list) {
V_293 = F_189 ( V_11 -> V_169 << 16 ) ;
if ( ! memcmp ( & V_293 , V_291 -> V_294 . V_295 , V_296 ) )
return 0 ;
}
F_190 ( L_20 ,
V_291 -> V_294 . V_295 , V_55 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_191 ( struct V_30 * V_31 , int V_55 ,
struct V_56 * V_57 ,
struct V_171 * V_292 , int V_297 )
{
struct V_170 * V_11 , * V_173 ;
T_2 V_62 ;
struct V_298 * V_299 ;
struct V_300 * V_291 ;
struct V_301 * V_302 ;
struct V_303 * V_304 ;
T_4 V_293 = 0 ;
T_4 V_305 = F_189 ( V_306 << 16 ) ;
V_299 = (struct V_298 * ) V_57 -> V_59 ;
V_62 = F_19 ( V_299 -> V_307 ) & 0xff ;
V_291 = (struct V_300 * ) ( V_299 + 1 ) ;
switch ( V_297 ) {
case V_308 :
V_302 =
(struct V_301 * ) ( V_291 + 1 ) ;
memmove ( V_302 , V_291 ,
sizeof( * V_302 ) + sizeof( * V_304 ) ) ;
break;
case V_309 :
case V_310 :
V_304 = (struct V_303 * )
( V_291 + 1 ) ;
memmove ( V_304 , V_291 , sizeof( * V_304 ) ) ;
break;
default:
return - V_127 ;
}
F_92 (res, tmp, rlist, list) {
if ( V_62 == V_11 -> V_62 ) {
V_293 = F_189 ( V_11 -> V_169 << 16 ) ;
break;
}
}
if ( ! V_293 ) {
F_190 ( L_21 ,
V_62 ) ;
return - V_127 ;
}
memset ( V_291 , 0 , sizeof( * V_291 ) ) ;
V_291 -> V_207 = sizeof( * V_291 ) >> 2 ;
V_291 -> V_89 = F_156 ( V_311 [ V_312 ] ) ;
memcpy ( V_291 -> V_295 , & V_293 , V_296 ) ;
memcpy ( V_291 -> V_313 , & V_305 , V_296 ) ;
return 0 ;
}
int F_192 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_292 = & V_121 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
int V_81 ;
int V_136 ;
struct V_298 * V_299 ;
struct V_290 * V_314 ;
int V_297 ;
if ( V_31 -> V_52 . V_315 !=
V_316 )
return - V_317 ;
V_299 = (struct V_298 * ) V_57 -> V_59 ;
V_136 = F_19 ( V_299 -> V_136 ) & 0xffffff ;
V_81 = F_22 ( V_31 , V_55 , V_136 , V_20 , NULL ) ;
if ( V_81 ) {
F_190 ( L_22 , V_136 ) ;
return V_81 ;
}
V_314 = (struct V_290 * ) ( V_299 + 1 ) ;
V_297 = F_193 ( F_194 ( V_314 -> V_89 ) ) ;
switch ( V_297 ) {
case V_312 :
if ( F_186 ( V_55 , V_314 , V_292 ) ) {
V_81 = - V_127 ;
goto V_318;
}
break;
case V_319 :
break;
case V_308 :
case V_309 :
case V_310 :
F_195 ( L_23 ) ;
if ( F_191 ( V_31 , V_55 , V_57 , V_292 , V_297 ) ) {
V_81 = - V_127 ;
goto V_318;
}
V_176 -> V_181 +=
sizeof( struct V_300 ) >> 2 ;
break;
default:
F_190 ( L_24 ) ;
V_81 = - V_127 ;
goto V_318;
}
V_81 = F_196 ( V_31 , V_57 -> V_269 , & V_176 -> V_163 ,
V_176 -> V_181 , 0 ,
V_320 , V_321 ,
V_272 ) ;
if ( V_81 )
goto V_318;
V_81 = F_42 ( V_31 , V_55 , V_176 -> V_163 , 1 , V_28 , 0 ) ;
if ( V_81 ) {
F_197 ( V_31 , L_25 ) ;
F_157 ( V_31 , V_176 -> V_163 , 0 , 0 ,
V_322 , V_321 ,
V_272 ) ;
}
V_318:
F_29 ( V_31 , V_55 , V_136 , V_20 ) ;
return V_81 ;
}
int F_198 ( struct V_30 * V_31 , int V_55 ,
struct V_175 * V_176 ,
struct V_56 * V_57 ,
struct V_56 * V_177 ,
struct V_178 * V_161 )
{
int V_81 ;
if ( V_31 -> V_52 . V_315 !=
V_316 )
return - V_317 ;
V_81 = F_56 ( V_31 , V_55 , V_176 -> V_162 , 1 , V_28 , 0 ) ;
if ( V_81 ) {
F_197 ( V_31 , L_26 ) ;
return V_81 ;
}
V_81 = F_157 ( V_31 , V_176 -> V_162 , 0 , 0 ,
V_322 , V_321 ,
V_272 ) ;
return V_81 ;
}
int F_199 ( struct V_30 * V_31 , int V_55 ,
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
V_81 = F_127 ( V_31 , V_55 , V_176 , V_57 , V_177 , V_161 ) ;
F_29 ( V_31 , V_55 , V_143 , V_27 ) ;
return V_81 ;
}
static void F_200 ( struct V_30 * V_31 , int V_55 , struct V_90 * V_279 )
{
struct V_278 * V_323 ;
struct V_278 * V_173 ;
struct V_285 V_138 ;
F_92 (rgid, tmp, &rqp->mcg_list, list) {
V_138 . V_136 = V_279 -> V_94 ;
( void ) F_185 ( V_31 , & V_138 , V_323 -> V_280 , V_323 -> V_282 ,
V_323 -> V_284 ) ;
F_57 ( & V_323 -> V_123 ) ;
F_16 ( V_323 ) ;
}
}
static int F_201 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_324 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_292 = & V_121 -> V_39 [ V_55 ] . V_44 [ type ] ;
struct V_10 * V_80 ;
struct V_10 * V_173 ;
int V_325 ;
V_325 = 0 ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (r, tmp, rlist, list) {
if ( V_80 -> V_85 == V_55 ) {
if ( ! V_80 -> V_326 ) {
if ( V_80 -> V_2 == V_83 ) {
if ( V_324 )
F_12 ( V_31 ,
L_27 ,
F_7 ( type ) ,
V_80 -> V_7 ) ;
++ V_325 ;
} else {
V_80 -> V_87 = V_80 -> V_2 ;
V_80 -> V_2 = V_83 ;
V_80 -> V_326 = 1 ;
}
}
}
}
F_25 ( F_24 ( V_31 ) ) ;
return V_325 ;
}
static int F_202 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type )
{
unsigned long V_327 ;
int V_325 ;
V_327 = V_328 ;
do {
V_325 = F_201 ( V_31 , V_55 , type , 0 ) ;
if ( F_203 ( V_328 , V_327 + 5 * V_329 ) )
break;
if ( V_325 )
F_204 () ;
} while ( V_325 );
if ( V_325 )
V_325 = F_201 ( V_31 , V_55 , type , 1 ) ;
return V_325 ;
}
static void F_205 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_330 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_20 ] ;
struct V_90 * V_138 ;
struct V_90 * V_173 ;
int V_2 ;
T_1 V_162 ;
int V_136 ;
int V_81 ;
V_81 = F_202 ( V_31 , V_55 , V_20 ) ;
if ( V_81 )
F_206 ( V_31 , L_28
L_29 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (qp, tmp, qp_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_138 -> V_92 . V_85 == V_55 ) {
V_136 = V_138 -> V_92 . V_7 ;
F_200 ( V_31 , V_55 , V_138 ) ;
V_2 = V_138 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_93 :
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_138 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_20 ] ) ;
F_57 ( & V_138 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_138 ) ;
V_2 = 0 ;
break;
case V_140 :
if ( ! F_65 ( V_31 , V_55 , V_136 ) )
F_106 ( V_31 , V_136 ) ;
V_2 = V_93 ;
break;
case V_141 :
V_162 = V_55 ;
V_81 = F_157 ( V_31 , V_162 ,
V_138 -> V_94 , 2 ,
V_331 ,
V_321 ,
V_272 ) ;
if ( V_81 )
F_12 ( V_31 , L_30
L_31
L_32 , V_55 ,
V_138 -> V_94 ) ;
F_130 ( & V_138 -> V_221 -> V_99 ) ;
F_130 ( & V_138 -> V_222 -> V_99 ) ;
F_130 ( & V_138 -> V_208 -> V_99 ) ;
if ( V_138 -> V_156 )
F_130 ( & V_138 -> V_156 -> V_99 ) ;
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
static void F_207 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_332 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_22 ] ;
struct V_107 * V_156 ;
struct V_107 * V_173 ;
int V_2 ;
T_1 V_162 ;
F_208 ( V_333 ) ;
int V_168 ;
int V_81 ;
V_81 = F_202 ( V_31 , V_55 , V_22 ) ;
if ( V_81 )
F_206 ( V_31 , L_33
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (srq, tmp, srq_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_156 -> V_92 . V_85 == V_55 ) {
V_168 = V_156 -> V_92 . V_7 ;
V_2 = V_156 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_108 :
F_89 ( V_31 , V_168 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_156 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_22 ] ) ;
F_57 ( & V_156 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_156 ) ;
V_2 = 0 ;
break;
case V_157 :
V_162 = V_55 ;
V_81 = F_157 ( V_31 , V_162 , V_168 , 1 ,
V_334 ,
V_321 ,
V_272 ) ;
if ( V_81 )
F_12 ( V_31 , L_35
L_36
L_37 ,
V_55 , V_168 ) ;
F_130 ( & V_156 -> V_208 -> V_99 ) ;
if ( V_156 -> V_154 )
F_130 ( & V_156 -> V_154 -> V_99 ) ;
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
static void F_209 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_335 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_21 ] ;
struct V_105 * V_154 ;
struct V_105 * V_173 ;
int V_2 ;
T_1 V_162 ;
F_208 ( V_333 ) ;
int V_152 ;
int V_81 ;
V_81 = F_202 ( V_31 , V_55 , V_21 ) ;
if ( V_81 )
F_206 ( V_31 , L_38
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (cq, tmp, cq_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_154 -> V_92 . V_85 == V_55 && ! F_47 ( & V_154 -> V_99 ) ) {
V_152 = V_154 -> V_92 . V_7 ;
V_2 = V_154 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_106 :
F_86 ( V_31 , V_152 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_154 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_21 ] ) ;
F_57 ( & V_154 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_154 ) ;
V_2 = 0 ;
break;
case V_155 :
V_162 = V_55 ;
V_81 = F_157 ( V_31 , V_162 , V_152 , 1 ,
V_336 ,
V_321 ,
V_272 ) ;
if ( V_81 )
F_12 ( V_31 , L_39
L_40
L_37 ,
V_55 , V_152 ) ;
F_130 ( & V_154 -> V_208 -> V_99 ) ;
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
static void F_210 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_337 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_23 ] ;
struct V_101 * V_145 ;
struct V_101 * V_173 ;
int V_2 ;
T_1 V_162 ;
F_208 ( V_333 ) ;
int V_338 ;
int V_81 ;
V_81 = F_202 ( V_31 , V_55 , V_23 ) ;
if ( V_81 )
F_206 ( V_31 , L_41
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (mpt, tmp, mpt_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_145 -> V_92 . V_85 == V_55 ) {
V_338 = V_145 -> V_92 . V_7 ;
V_2 = V_145 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_102 :
F_82 ( V_31 , V_145 -> V_100 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_145 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_23 ] ) ;
F_57 ( & V_145 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_145 ) ;
V_2 = 0 ;
break;
case V_146 :
F_109 ( V_31 , V_145 -> V_100 ) ;
V_2 = V_102 ;
break;
case V_147 :
V_162 = V_55 ;
V_81 = F_157 ( V_31 , V_162 , V_338 , 0 ,
V_339 ,
V_321 ,
V_272 ) ;
if ( V_81 )
F_12 ( V_31 , L_42
L_43
L_37 ,
V_55 , V_338 ) ;
if ( V_145 -> V_208 )
F_130 ( & V_145 -> V_208 -> V_99 ) ;
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
static void F_211 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_340 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_24 ] ;
struct V_98 * V_208 ;
struct V_98 * V_173 ;
int V_2 ;
F_208 ( V_333 ) ;
int V_117 ;
int V_81 ;
V_81 = F_202 ( V_31 , V_55 , V_24 ) ;
if ( V_81 )
F_206 ( V_31 , L_44
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (mtt, tmp, mtt_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_208 -> V_92 . V_85 == V_55 ) {
V_117 = V_208 -> V_92 . V_7 ;
V_2 = V_208 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_79 ( V_31 , V_117 ,
V_208 -> V_97 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_208 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_24 ] ) ;
F_57 ( & V_208 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_208 ) ;
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
static void F_212 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_341 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_28 ] ;
struct V_113 * V_342 ;
struct V_113 * V_173 ;
int V_2 ;
T_1 V_117 ;
int V_81 ;
V_81 = F_202 ( V_31 , V_55 , V_28 ) ;
if ( V_81 )
F_206 ( V_31 , L_45 ,
V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (fs_rule, tmp, fs_rule_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_342 -> V_92 . V_85 == V_55 ) {
V_117 = V_342 -> V_92 . V_7 ;
V_2 = V_342 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_114 :
V_81 = F_157 ( V_31 , V_117 , 0 , 0 ,
V_322 ,
V_321 ,
V_272 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_342 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_28 ] ) ;
F_57 ( & V_342 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_342 ) ;
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
static void F_213 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_343 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_26 ] ;
struct V_103 * V_149 ;
struct V_103 * V_173 ;
int V_81 ;
int V_2 ;
F_208 ( V_333 ) ;
int V_237 ;
struct V_56 * V_260 ;
V_81 = F_202 ( V_31 , V_55 , V_26 ) ;
if ( V_81 )
F_206 ( V_31 , L_46
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (eq, tmp, eq_list, com.list) {
F_25 ( F_24 ( V_31 ) ) ;
if ( V_149 -> V_92 . V_85 == V_55 ) {
V_237 = V_149 -> V_92 . V_7 ;
V_2 = V_149 -> V_92 . V_87 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_104 :
F_23 ( F_24 ( V_31 ) ) ;
F_44 ( & V_149 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_26 ] ) ;
F_57 ( & V_149 -> V_92 . V_123 ) ;
F_25 ( F_24 ( V_31 ) ) ;
F_16 ( V_149 ) ;
V_2 = 0 ;
break;
case V_151 :
V_260 = F_153 ( V_31 ) ;
if ( F_154 ( V_260 ) ) {
F_204 () ;
continue;
}
V_81 = F_214 ( V_31 , V_55 , 0 ,
V_237 & 0xff , 0 ,
V_344 ,
V_321 ,
V_272 ) ;
if ( V_81 )
F_12 ( V_31 , L_47
L_48
L_37 , V_55 , V_237 ) ;
F_159 ( V_31 , V_260 ) ;
F_130 ( & V_149 -> V_208 -> V_99 ) ;
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
static void F_215 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_345 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_27 ] ;
struct V_109 * V_346 ;
struct V_109 * V_173 ;
int V_81 ;
int V_143 ;
V_81 = F_202 ( V_31 , V_55 , V_27 ) ;
if ( V_81 )
F_206 ( V_31 , L_49
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (counter, tmp, counter_list, com.list) {
if ( V_346 -> V_92 . V_85 == V_55 ) {
V_143 = V_346 -> V_92 . V_7 ;
F_44 ( & V_346 -> V_92 . V_9 ,
& V_121 -> V_46 [ V_27 ] ) ;
F_57 ( & V_346 -> V_92 . V_123 ) ;
F_16 ( V_346 ) ;
F_100 ( V_31 , V_143 ) ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
}
static void F_216 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_120 * V_121 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_171 * V_347 =
& V_121 -> V_39 [ V_55 ] . V_44 [ V_29 ] ;
struct V_111 * V_348 ;
struct V_111 * V_173 ;
int V_81 ;
int V_174 ;
V_81 = F_202 ( V_31 , V_55 , V_29 ) ;
if ( V_81 )
F_206 ( V_31 , L_50
L_34 , V_55 ) ;
F_23 ( F_24 ( V_31 ) ) ;
F_92 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_348 -> V_92 . V_85 == V_55 ) {
V_174 = V_348 -> V_92 . V_7 ;
F_44 ( & V_348 -> V_92 . V_9 , & V_121 -> V_46 [ V_29 ] ) ;
F_57 ( & V_348 -> V_92 . V_123 ) ;
F_16 ( V_348 ) ;
F_103 ( V_31 , V_174 ) ;
}
}
F_25 ( F_24 ( V_31 ) ) ;
}
void F_15 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
F_152 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_55 ] . V_45 ) ;
F_93 ( V_31 , V_55 ) ;
F_205 ( V_31 , V_55 ) ;
F_207 ( V_31 , V_55 ) ;
F_209 ( V_31 , V_55 ) ;
F_210 ( V_31 , V_55 ) ;
F_213 ( V_31 , V_55 ) ;
F_211 ( V_31 , V_55 ) ;
F_215 ( V_31 , V_55 ) ;
F_216 ( V_31 , V_55 ) ;
F_212 ( V_31 , V_55 ) ;
F_158 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_55 ] . V_45 ) ;
}
