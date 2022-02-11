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
static void F_17 ( struct V_30 * V_31 ,
struct V_55 * V_56 , T_2 V_57 )
{
T_3 V_58 = ( F_18 ( V_56 -> V_59 ) >> 16 ) & 0xff ;
if ( V_60 == V_58 )
V_56 -> V_61 . V_62 = 0x80 | V_57 ;
F_12 ( V_31 , L_16 ,
V_57 , V_56 -> V_61 . V_62 ) ;
}
static int F_19 ( struct V_30 * V_31 )
{
return V_31 -> V_52 . V_63 - 1 ;
}
static void * F_20 ( struct V_30 * V_31 , int V_7 ,
enum V_18 type )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
return F_2 ( & V_33 -> V_36 . V_37 . V_38 . V_46 [ type ] ,
V_7 ) ;
}
static int F_21 ( struct V_30 * V_31 , int V_57 , T_1 V_7 ,
enum V_18 type ,
void * V_11 )
{
struct V_10 * V_64 ;
int V_65 = 0 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_20 ( V_31 , V_7 , type ) ;
if ( ! V_64 ) {
V_65 = - V_66 ;
goto exit;
}
if ( V_64 -> V_2 == V_67 ) {
V_65 = - V_68 ;
goto exit;
}
if ( V_64 -> V_69 != V_57 ) {
V_65 = - V_70 ;
goto exit;
}
V_64 -> V_71 = V_64 -> V_2 ;
V_64 -> V_2 = V_67 ;
F_12 ( V_31 , L_17 ,
F_7 ( type ) , V_64 -> V_7 ) ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_64 ;
exit:
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
int F_25 ( struct V_30 * V_31 ,
enum V_18 type ,
T_1 V_7 , int * V_57 )
{
struct V_10 * V_64 ;
int V_65 = - V_72 ;
int V_73 = V_7 ;
if ( type == V_20 )
V_73 &= 0x7fffff ;
F_26 ( F_23 ( V_31 ) ) ;
V_64 = F_20 ( V_31 , V_73 , type ) ;
if ( V_64 ) {
* V_57 = V_64 -> V_69 ;
V_65 = 0 ;
}
F_27 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static void F_28 ( struct V_30 * V_31 , int V_57 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_64 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_20 ( V_31 , V_7 , type ) ;
if ( V_64 )
V_64 -> V_2 = V_64 -> V_71 ;
F_24 ( F_23 ( V_31 ) ) ;
}
static struct V_10 * F_29 ( int V_73 )
{
struct V_74 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_77 ;
V_75 -> V_78 = V_73 ;
F_10 ( & V_75 -> V_79 ) ;
F_13 ( & V_75 -> V_80 ) ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_30 ( int V_73 , int V_81 )
{
struct V_82 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_81 = V_81 ;
V_75 -> V_76 . V_2 = V_4 ;
F_31 ( & V_75 -> V_83 , 0 ) ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_32 ( int V_73 , int V_84 )
{
struct V_85 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_86 ;
V_75 -> V_84 = V_84 ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_33 ( int V_73 )
{
struct V_87 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_88 ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_34 ( int V_73 )
{
struct V_89 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_90 ;
F_31 ( & V_75 -> V_83 , 0 ) ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_35 ( int V_73 )
{
struct V_91 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_92 ;
F_31 ( & V_75 -> V_83 , 0 ) ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_36 ( int V_73 )
{
struct V_93 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_94 ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_37 ( int V_73 )
{
struct V_95 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_96 ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_38 ( T_1 V_73 )
{
struct V_97 * V_75 ;
V_75 = F_9 ( sizeof *V_75 , V_41 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_76 . V_7 = V_73 ;
V_75 -> V_76 . V_2 = V_98 ;
return & V_75 -> V_76 ;
}
static struct V_10 * F_39 ( T_1 V_73 , enum V_18 type , int V_57 ,
int V_99 )
{
struct V_10 * V_75 ;
switch ( type ) {
case V_20 :
V_75 = F_29 ( V_73 ) ;
break;
case V_23 :
V_75 = F_32 ( V_73 , V_99 ) ;
break;
case V_24 :
V_75 = F_30 ( V_73 , V_99 ) ;
break;
case V_26 :
V_75 = F_33 ( V_73 ) ;
break;
case V_21 :
V_75 = F_34 ( V_73 ) ;
break;
case V_22 :
V_75 = F_35 ( V_73 ) ;
break;
case V_25 :
F_40 ( V_100 L_18 ) ;
return NULL ;
case V_27 :
V_75 = F_36 ( V_73 ) ;
break;
case V_29 :
V_75 = F_37 ( V_73 ) ;
break;
case V_28 :
V_75 = F_38 ( V_73 ) ;
break;
default:
return NULL ;
}
if ( V_75 )
V_75 -> V_69 = V_57 ;
return V_75 ;
}
static int F_41 ( struct V_30 * V_31 , int V_57 , T_1 V_101 , int V_102 ,
enum V_18 type , int V_99 )
{
int V_34 ;
int V_65 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_10 * * V_103 ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_5 * V_6 = & V_105 -> V_46 [ type ] ;
V_103 = F_9 ( V_102 * sizeof *V_103 , V_41 ) ;
if ( ! V_103 )
return - V_42 ;
for ( V_34 = 0 ; V_34 < V_102 ; ++ V_34 ) {
V_103 [ V_34 ] = F_39 ( V_101 + V_34 , type , V_57 , V_99 ) ;
if ( ! V_103 [ V_34 ] ) {
for ( -- V_34 ; V_34 >= 0 ; -- V_34 )
F_16 ( V_103 [ V_34 ] ) ;
F_16 ( V_103 ) ;
return - V_42 ;
}
}
F_22 ( F_23 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_102 ; ++ V_34 ) {
if ( F_20 ( V_31 , V_101 + V_34 , type ) ) {
V_65 = - V_17 ;
goto V_106;
}
V_65 = F_4 ( V_6 , V_103 [ V_34 ] ) ;
if ( V_65 )
goto V_106;
F_42 ( & V_103 [ V_34 ] -> V_107 ,
& V_105 -> V_39 [ V_57 ] . V_44 [ type ] ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_103 ) ;
return 0 ;
V_106:
for ( -- V_34 ; V_34 >= V_101 ; -- V_34 )
F_43 ( & V_103 [ V_34 ] -> V_9 , V_6 ) ;
F_24 ( F_23 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_102 ; ++ V_34 )
F_16 ( V_103 [ V_34 ] ) ;
F_16 ( V_103 ) ;
return V_65 ;
}
static int F_44 ( struct V_74 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_108 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_77 )
return - V_70 ;
return 0 ;
}
static int F_45 ( struct V_82 * V_11 , int V_81 )
{
if ( V_11 -> V_76 . V_2 == V_3 ||
F_46 ( & V_11 -> V_83 ) ) {
F_40 ( V_109 L_19 ,
V_110 , __LINE__ ,
F_1 ( V_11 -> V_76 . V_2 ) ,
F_46 ( & V_11 -> V_83 ) ) ;
return - V_68 ;
} else if ( V_11 -> V_76 . V_2 != V_4 )
return - V_70 ;
else if ( V_11 -> V_81 != V_81 )
return - V_111 ;
return 0 ;
}
static int F_47 ( struct V_85 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_112 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_86 )
return - V_70 ;
return 0 ;
}
static int F_48 ( struct V_87 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_112 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_86 )
return - V_70 ;
return 0 ;
}
static int F_49 ( struct V_93 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_113 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_94 )
return - V_70 ;
return 0 ;
}
static int F_50 ( struct V_95 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_114 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_96 )
return - V_70 ;
return 0 ;
}
static int F_51 ( struct V_97 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_115 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_98 )
return - V_70 ;
return 0 ;
}
static int F_52 ( struct V_89 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_116 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_90 )
return - V_70 ;
return 0 ;
}
static int F_53 ( struct V_91 * V_11 )
{
if ( V_11 -> V_76 . V_2 == V_117 )
return - V_68 ;
else if ( V_11 -> V_76 . V_2 != V_92 )
return - V_70 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , enum V_18 type , int V_99 )
{
switch ( type ) {
case V_20 :
return F_44 ( (struct V_74 * ) V_11 ) ;
case V_21 :
return F_52 ( (struct V_89 * ) V_11 ) ;
case V_22 :
return F_53 ( (struct V_91 * ) V_11 ) ;
case V_23 :
return F_47 ( (struct V_85 * ) V_11 ) ;
case V_24 :
return F_45 ( (struct V_82 * ) V_11 , V_99 ) ;
case V_25 :
return - V_118 ;
case V_26 :
return F_48 ( (struct V_87 * ) V_11 ) ;
case V_27 :
return F_49 ( (struct V_93 * ) V_11 ) ;
case V_29 :
return F_50 ( (struct V_95 * ) V_11 ) ;
case V_28 :
return F_51 ( (struct V_97 * ) V_11 ) ;
default:
return - V_111 ;
}
}
static int F_55 ( struct V_30 * V_31 , int V_57 , T_1 V_101 , int V_102 ,
enum V_18 type , int V_99 )
{
T_1 V_34 ;
int V_65 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_64 ;
F_22 ( F_23 ( V_31 ) ) ;
for ( V_34 = V_101 ; V_34 < V_101 + V_102 ; ++ V_34 ) {
V_64 = F_2 ( & V_105 -> V_46 [ type ] , V_34 ) ;
if ( ! V_64 ) {
V_65 = - V_72 ;
goto V_119;
}
if ( V_64 -> V_69 != V_57 ) {
V_65 = - V_70 ;
goto V_119;
}
V_65 = F_54 ( V_64 , type , V_99 ) ;
if ( V_65 )
goto V_119;
}
for ( V_34 = V_101 ; V_34 < V_101 + V_102 ; ++ V_34 ) {
V_64 = F_2 ( & V_105 -> V_46 [ type ] , V_34 ) ;
F_43 ( & V_64 -> V_9 , & V_105 -> V_46 [ type ] ) ;
F_56 ( & V_64 -> V_107 ) ;
F_16 ( V_64 ) ;
}
V_65 = 0 ;
V_119:
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static int F_57 ( struct V_30 * V_31 , int V_57 , int V_120 ,
enum V_121 V_2 , struct V_74 * * V_122 ,
int V_123 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_74 * V_64 ;
int V_65 = 0 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ V_20 ] , V_120 ) ;
if ( ! V_64 )
V_65 = - V_72 ;
else if ( V_64 -> V_76 . V_69 != V_57 )
V_65 = - V_70 ;
else {
switch ( V_2 ) {
case V_108 :
F_12 ( V_31 , L_20 ,
V_110 , V_64 -> V_76 . V_7 ) ;
V_65 = - V_68 ;
break;
case V_77 :
if ( V_64 -> V_76 . V_2 == V_124 && ! V_123 )
break;
F_12 ( V_31 , L_21 , V_64 -> V_76 . V_7 ) ;
V_65 = - V_111 ;
break;
case V_124 :
if ( ( V_64 -> V_76 . V_2 == V_77 && V_123 ) ||
V_64 -> V_76 . V_2 == V_125 )
break;
else {
F_12 ( V_31 , L_21 ,
V_64 -> V_76 . V_7 ) ;
V_65 = - V_111 ;
}
break;
case V_125 :
if ( V_64 -> V_76 . V_2 != V_124 )
V_65 = - V_111 ;
break;
default:
V_65 = - V_111 ;
}
if ( ! V_65 ) {
V_64 -> V_76 . V_71 = V_64 -> V_76 . V_2 ;
V_64 -> V_76 . V_126 = V_2 ;
V_64 -> V_76 . V_2 = V_108 ;
if ( V_122 )
* V_122 = V_64 ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static int F_58 ( struct V_30 * V_31 , int V_57 , int V_127 ,
enum V_128 V_2 , struct V_85 * * V_129 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_85 * V_64 ;
int V_65 = 0 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ V_23 ] , V_127 ) ;
if ( ! V_64 )
V_65 = - V_72 ;
else if ( V_64 -> V_76 . V_69 != V_57 )
V_65 = - V_70 ;
else {
switch ( V_2 ) {
case V_112 :
V_65 = - V_111 ;
break;
case V_86 :
if ( V_64 -> V_76 . V_2 != V_130 )
V_65 = - V_111 ;
break;
case V_130 :
if ( V_64 -> V_76 . V_2 != V_86 &&
V_64 -> V_76 . V_2 != V_131 )
V_65 = - V_111 ;
break;
case V_131 :
if ( V_64 -> V_76 . V_2 != V_130 )
V_65 = - V_111 ;
break;
default:
V_65 = - V_111 ;
}
if ( ! V_65 ) {
V_64 -> V_76 . V_71 = V_64 -> V_76 . V_2 ;
V_64 -> V_76 . V_126 = V_2 ;
V_64 -> V_76 . V_2 = V_112 ;
if ( V_129 )
* V_129 = V_64 ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static int F_59 ( struct V_30 * V_31 , int V_57 , int V_127 ,
enum V_132 V_2 , struct V_87 * * V_133 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_87 * V_64 ;
int V_65 = 0 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ V_26 ] , V_127 ) ;
if ( ! V_64 )
V_65 = - V_72 ;
else if ( V_64 -> V_76 . V_69 != V_57 )
V_65 = - V_70 ;
else {
switch ( V_2 ) {
case V_134 :
V_65 = - V_111 ;
break;
case V_88 :
if ( V_64 -> V_76 . V_2 != V_135 )
V_65 = - V_111 ;
break;
case V_135 :
if ( V_64 -> V_76 . V_2 != V_88 )
V_65 = - V_111 ;
break;
default:
V_65 = - V_111 ;
}
if ( ! V_65 ) {
V_64 -> V_76 . V_71 = V_64 -> V_76 . V_2 ;
V_64 -> V_76 . V_126 = V_2 ;
V_64 -> V_76 . V_2 = V_134 ;
if ( V_133 )
* V_133 = V_64 ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static int F_60 ( struct V_30 * V_31 , int V_57 , int V_136 ,
enum V_137 V_2 , struct V_89 * * V_138 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_89 * V_64 ;
int V_65 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ V_21 ] , V_136 ) ;
if ( ! V_64 )
V_65 = - V_72 ;
else if ( V_64 -> V_76 . V_69 != V_57 )
V_65 = - V_70 ;
else {
switch ( V_2 ) {
case V_116 :
V_65 = - V_68 ;
break;
case V_90 :
if ( V_64 -> V_76 . V_2 != V_139 )
V_65 = - V_111 ;
else if ( F_46 ( & V_64 -> V_83 ) )
V_65 = - V_68 ;
else
V_65 = 0 ;
break;
case V_139 :
if ( V_64 -> V_76 . V_2 != V_90 )
V_65 = - V_111 ;
else
V_65 = 0 ;
break;
default:
V_65 = - V_111 ;
}
if ( ! V_65 ) {
V_64 -> V_76 . V_71 = V_64 -> V_76 . V_2 ;
V_64 -> V_76 . V_126 = V_2 ;
V_64 -> V_76 . V_2 = V_116 ;
if ( V_138 )
* V_138 = V_64 ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static int F_61 ( struct V_30 * V_31 , int V_57 , int V_127 ,
enum V_137 V_2 , struct V_91 * * V_140 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_91 * V_64 ;
int V_65 = 0 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ V_22 ] , V_127 ) ;
if ( ! V_64 )
V_65 = - V_72 ;
else if ( V_64 -> V_76 . V_69 != V_57 )
V_65 = - V_70 ;
else {
switch ( V_2 ) {
case V_117 :
V_65 = - V_111 ;
break;
case V_92 :
if ( V_64 -> V_76 . V_2 != V_141 )
V_65 = - V_111 ;
else if ( F_46 ( & V_64 -> V_83 ) )
V_65 = - V_68 ;
break;
case V_141 :
if ( V_64 -> V_76 . V_2 != V_92 )
V_65 = - V_111 ;
break;
default:
V_65 = - V_111 ;
}
if ( ! V_65 ) {
V_64 -> V_76 . V_71 = V_64 -> V_76 . V_2 ;
V_64 -> V_76 . V_126 = V_2 ;
V_64 -> V_76 . V_2 = V_117 ;
if ( V_140 )
* V_140 = V_64 ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
static void F_62 ( struct V_30 * V_31 , int V_57 ,
enum V_18 type , int V_73 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_64 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ type ] , V_73 ) ;
if ( V_64 && ( V_64 -> V_69 == V_57 ) )
V_64 -> V_2 = V_64 -> V_71 ;
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_63 ( struct V_30 * V_31 , int V_57 ,
enum V_18 type , int V_73 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_64 ;
F_22 ( F_23 ( V_31 ) ) ;
V_64 = F_2 ( & V_105 -> V_46 [ type ] , V_73 ) ;
if ( V_64 && ( V_64 -> V_69 == V_57 ) )
V_64 -> V_2 = V_64 -> V_126 ;
F_24 ( F_23 ( V_31 ) ) ;
}
static int F_64 ( struct V_30 * V_31 , int V_57 , int V_120 )
{
return F_65 ( V_31 , V_120 ) ;
}
static int F_66 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_65 ;
int V_102 ;
int V_146 ;
int V_101 ;
int V_120 ;
switch ( V_142 ) {
case V_147 :
V_102 = F_67 ( & V_144 ) ;
V_146 = F_68 ( & V_144 ) ;
V_65 = F_69 ( V_31 , V_102 , V_146 , & V_101 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_41 ( V_31 , V_57 , V_101 , V_102 , V_20 , 0 ) ;
if ( V_65 ) {
F_70 ( V_31 , V_101 , V_102 ) ;
return V_65 ;
}
F_71 ( V_145 , V_101 ) ;
break;
case V_148 :
V_120 = F_67 ( & V_144 ) & 0x7fffff ;
if ( F_64 ( V_31 , V_57 , V_120 ) ) {
V_65 = F_41 ( V_31 , V_57 , V_120 , 1 , V_20 , 0 ) ;
if ( V_65 )
return V_65 ;
}
V_65 = F_57 ( V_31 , V_57 , V_120 , V_124 ,
NULL , 1 ) ;
if ( V_65 )
return V_65 ;
if ( ! F_64 ( V_31 , V_57 , V_120 ) ) {
V_65 = F_72 ( V_31 , V_120 ) ;
if ( V_65 ) {
F_62 ( V_31 , V_57 , V_20 , V_120 ) ;
return V_65 ;
}
}
F_63 ( V_31 , V_57 , V_20 , V_120 ) ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_73 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_65 = - V_111 ;
int V_101 ;
int V_81 ;
if ( V_142 != V_149 )
return V_65 ;
V_81 = F_67 ( & V_144 ) ;
V_101 = F_74 ( V_31 , V_81 ) ;
if ( V_101 == - 1 )
return - V_42 ;
V_65 = F_41 ( V_31 , V_57 , V_101 , 1 , V_24 , V_81 ) ;
if ( V_65 )
F_75 ( V_31 , V_101 , V_81 ) ;
else
F_71 ( V_145 , V_101 ) ;
return V_65 ;
}
static int F_76 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_65 = - V_111 ;
int V_127 ;
int V_73 ;
struct V_85 * V_129 ;
switch ( V_142 ) {
case V_147 :
V_127 = F_77 ( V_31 ) ;
if ( V_127 == - 1 )
break;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_41 ( V_31 , V_57 , V_73 , 1 , V_23 , V_127 ) ;
if ( V_65 ) {
F_78 ( V_31 , V_127 ) ;
break;
}
F_71 ( V_145 , V_127 ) ;
break;
case V_148 :
V_127 = F_67 ( & V_144 ) ;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_58 ( V_31 , V_57 , V_73 ,
V_130 , & V_129 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_79 ( V_31 , V_129 -> V_84 ) ;
if ( V_65 ) {
F_62 ( V_31 , V_57 , V_23 , V_73 ) ;
return V_65 ;
}
F_63 ( V_31 , V_57 , V_23 , V_73 ) ;
break;
}
return V_65 ;
}
static int F_80 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_136 ;
int V_65 ;
switch ( V_142 ) {
case V_149 :
V_65 = F_81 ( V_31 , & V_136 ) ;
if ( V_65 )
break;
V_65 = F_41 ( V_31 , V_57 , V_136 , 1 , V_21 , 0 ) ;
if ( V_65 ) {
F_82 ( V_31 , V_136 ) ;
break;
}
F_71 ( V_145 , V_136 ) ;
break;
default:
V_65 = - V_111 ;
}
return V_65 ;
}
static int F_83 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_150 ;
int V_65 ;
switch ( V_142 ) {
case V_149 :
V_65 = F_84 ( V_31 , & V_150 ) ;
if ( V_65 )
break;
V_65 = F_41 ( V_31 , V_57 , V_150 , 1 , V_22 , 0 ) ;
if ( V_65 ) {
F_85 ( V_31 , V_150 ) ;
break;
}
F_71 ( V_145 , V_150 ) ;
break;
default:
V_65 = - V_111 ;
}
return V_65 ;
}
static int F_86 ( struct V_30 * V_31 , int V_57 , T_1 V_151 , int V_152 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_153 * V_11 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
V_11 -> V_151 = V_151 ;
V_11 -> V_152 = ( T_2 ) V_152 ;
F_42 ( & V_11 -> V_107 ,
& V_105 -> V_39 [ V_57 ] . V_44 [ V_25 ] ) ;
return 0 ;
}
static void F_87 ( struct V_30 * V_31 , int V_57 , T_1 V_151 ,
int V_152 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_155 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_25 ] ;
struct V_153 * V_11 , * V_156 ;
F_88 (res, tmp, mac_list, list) {
if ( V_11 -> V_151 == V_151 && V_11 -> V_152 == ( T_2 ) V_152 ) {
F_56 ( & V_11 -> V_107 ) ;
F_16 ( V_11 ) ;
break;
}
}
}
static void F_89 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_155 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_25 ] ;
struct V_153 * V_11 , * V_156 ;
F_88 (res, tmp, mac_list, list) {
F_56 ( & V_11 -> V_107 ) ;
F_90 ( V_31 , V_11 -> V_152 , V_11 -> V_151 ) ;
F_16 ( V_11 ) ;
}
}
static int F_91 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_65 = - V_111 ;
int V_152 ;
T_1 V_151 ;
if ( V_142 != V_149 )
return V_65 ;
V_152 = F_67 ( V_145 ) ;
V_151 = V_144 ;
V_65 = F_92 ( V_31 , V_152 , V_151 ) ;
if ( V_65 >= 0 ) {
F_71 ( V_145 , V_65 ) ;
V_65 = 0 ;
}
if ( ! V_65 ) {
V_65 = F_86 ( V_31 , V_57 , V_151 , V_152 ) ;
if ( V_65 )
F_90 ( V_31 , V_152 , V_151 ) ;
}
return V_65 ;
}
static int F_93 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
return 0 ;
}
static int F_94 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
T_3 V_127 ;
int V_65 ;
if ( V_142 != V_147 )
return - V_111 ;
V_65 = F_95 ( V_31 , & V_127 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_41 ( V_31 , V_57 , V_127 , 1 , V_27 , 0 ) ;
if ( V_65 )
F_96 ( V_31 , V_127 ) ;
else
F_71 ( V_145 , V_127 ) ;
return V_65 ;
}
static int F_97 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
T_3 V_157 ;
int V_65 ;
if ( V_142 != V_147 )
return - V_111 ;
V_65 = F_98 ( V_31 , & V_157 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_41 ( V_31 , V_57 , V_157 , 1 , V_29 , 0 ) ;
if ( V_65 )
F_99 ( V_31 , V_157 ) ;
else
F_71 ( V_145 , V_157 ) ;
return V_65 ;
}
int F_100 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_164 = V_159 -> V_165 ;
switch ( V_159 -> V_166 ) {
case V_20 :
V_65 = F_66 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_24 :
V_65 = F_73 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_23 :
V_65 = F_76 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_21 :
V_65 = F_80 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_22 :
V_65 = F_83 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_25 :
V_65 = F_91 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_167 :
V_65 = F_93 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_27 :
V_65 = F_94 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_29 :
V_65 = F_97 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_101 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 )
{
int V_65 ;
int V_102 ;
int V_101 ;
int V_120 ;
switch ( V_142 ) {
case V_147 :
V_101 = F_67 ( & V_144 ) & 0x7fffff ;
V_102 = F_68 ( & V_144 ) ;
V_65 = F_55 ( V_31 , V_57 , V_101 , V_102 , V_20 , 0 ) ;
if ( V_65 )
break;
F_70 ( V_31 , V_101 , V_102 ) ;
break;
case V_148 :
V_120 = F_67 ( & V_144 ) & 0x7fffff ;
V_65 = F_57 ( V_31 , V_57 , V_120 , V_77 ,
NULL , 0 ) ;
if ( V_65 )
return V_65 ;
if ( ! F_64 ( V_31 , V_57 , V_120 ) )
F_102 ( V_31 , V_120 ) ;
F_63 ( V_31 , V_57 , V_20 , V_120 ) ;
if ( F_64 ( V_31 , V_57 , V_120 ) )
V_65 = F_55 ( V_31 , V_57 , V_120 , 1 , V_20 , 0 ) ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_103 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_65 = - V_111 ;
int V_101 ;
int V_81 ;
if ( V_142 != V_149 )
return V_65 ;
V_101 = F_67 ( & V_144 ) ;
V_81 = F_68 ( & V_144 ) ;
V_65 = F_55 ( V_31 , V_57 , V_101 , 1 , V_24 , V_81 ) ;
if ( ! V_65 )
F_75 ( V_31 , V_101 , V_81 ) ;
return V_65 ;
}
static int F_104 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 )
{
int V_65 = - V_111 ;
int V_127 ;
int V_73 ;
struct V_85 * V_129 ;
switch ( V_142 ) {
case V_147 :
V_127 = F_67 ( & V_144 ) ;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_21 ( V_31 , V_57 , V_73 , V_23 , & V_129 ) ;
if ( V_65 )
break;
V_127 = V_129 -> V_84 ;
F_28 ( V_31 , V_57 , V_73 , V_23 ) ;
V_65 = F_55 ( V_31 , V_57 , V_73 , 1 , V_23 , 0 ) ;
if ( V_65 )
break;
F_78 ( V_31 , V_127 ) ;
break;
case V_148 :
V_127 = F_67 ( & V_144 ) ;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_58 ( V_31 , V_57 , V_73 ,
V_86 , & V_129 ) ;
if ( V_65 )
return V_65 ;
F_105 ( V_31 , V_129 -> V_84 ) ;
F_63 ( V_31 , V_57 , V_23 , V_73 ) ;
return V_65 ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_106 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_136 ;
int V_65 ;
switch ( V_142 ) {
case V_149 :
V_136 = F_67 ( & V_144 ) ;
V_65 = F_55 ( V_31 , V_57 , V_136 , 1 , V_21 , 0 ) ;
if ( V_65 )
break;
F_82 ( V_31 , V_136 ) ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_107 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_150 ;
int V_65 ;
switch ( V_142 ) {
case V_149 :
V_150 = F_67 ( & V_144 ) ;
V_65 = F_55 ( V_31 , V_57 , V_150 , 1 , V_22 , 0 ) ;
if ( V_65 )
break;
F_85 ( V_31 , V_150 ) ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_108 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_152 ;
int V_65 = 0 ;
switch ( V_142 ) {
case V_149 :
V_152 = F_67 ( V_145 ) ;
F_87 ( V_31 , V_57 , V_144 , V_152 ) ;
F_90 ( V_31 , V_152 , V_144 ) ;
break;
default:
V_65 = - V_111 ;
break;
}
return V_65 ;
}
static int F_109 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
return 0 ;
}
static int F_110 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_127 ;
int V_65 ;
if ( V_142 != V_147 )
return - V_111 ;
V_127 = F_67 ( & V_144 ) ;
V_65 = F_55 ( V_31 , V_57 , V_127 , 1 , V_27 , 0 ) ;
if ( V_65 )
return V_65 ;
F_96 ( V_31 , V_127 ) ;
return V_65 ;
}
static int F_111 ( struct V_30 * V_31 , int V_57 , int V_142 , int V_143 ,
T_1 V_144 , T_1 * V_145 )
{
int V_157 ;
int V_65 ;
if ( V_142 != V_147 )
return - V_111 ;
V_157 = F_67 ( & V_144 ) ;
V_65 = F_55 ( V_31 , V_57 , V_157 , 1 , V_29 , 0 ) ;
if ( V_65 )
return V_65 ;
F_99 ( V_31 , V_157 ) ;
return V_65 ;
}
int F_112 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 = - V_111 ;
int V_164 = V_159 -> V_165 ;
switch ( V_159 -> V_166 ) {
case V_20 :
V_65 = F_101 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 ) ;
break;
case V_24 :
V_65 = F_103 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_23 :
V_65 = F_104 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 ) ;
break;
case V_21 :
V_65 = F_106 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_22 :
V_65 = F_107 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_25 :
V_65 = F_108 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_167 :
V_65 = F_109 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_27 :
V_65 = F_110 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
break;
case V_29 :
V_65 = F_111 ( V_31 , V_57 , V_159 -> V_165 , V_164 ,
V_159 -> V_144 , & V_159 -> V_145 ) ;
default:
break;
}
return V_65 ;
}
static int F_113 ( struct V_168 * V_129 )
{
return ( F_18 ( V_129 -> V_59 ) >> 9 ) & 1 ;
}
static int F_114 ( struct V_168 * V_129 )
{
return ( int ) F_115 ( V_129 -> V_169 ) & 0xfffffff8 ;
}
static int F_116 ( struct V_168 * V_129 )
{
return F_18 ( V_129 -> V_170 ) ;
}
static int F_117 ( struct V_55 * V_171 )
{
return F_18 ( V_171 -> V_172 ) & 0xfffffff8 ;
}
static int F_118 ( struct V_173 * V_174 )
{
return F_18 ( V_174 -> V_172 ) & 0xfffffff8 ;
}
static int F_119 ( struct V_55 * V_171 )
{
int V_175 = ( V_171 -> V_176 & 0x3f ) + 12 ;
int V_177 = ( V_171 -> V_178 >> 3 ) & 0xf ;
int V_179 = V_171 -> V_178 & 7 ;
int V_180 = ( V_171 -> V_181 >> 3 ) & 0xf ;
int V_182 = V_171 -> V_181 & 7 ;
int V_140 = ( F_18 ( V_171 -> V_150 ) >> 24 ) & 1 ;
int V_183 = ( F_18 ( V_171 -> V_59 ) >> 13 ) & 1 ;
int V_184 = ( F_18 ( V_171 -> V_78 ) >> 23 ) & 1 ;
int V_185 ;
int V_186 ;
int V_187 ;
int V_188 ;
int V_189 = ( F_18 ( V_171 -> V_190 ) >> 6 ) & 0x3f ;
V_185 = 1 << ( V_177 + V_179 + 4 ) ;
V_186 = ( V_140 | V_183 | V_184 ) ? 0 : ( 1 << ( V_180 + V_182 + 4 ) ) ;
V_188 = V_185 + V_186 ;
V_187 =
F_120 ( ( V_188 + ( V_189 << 6 ) ) >>
V_175 ) ;
return V_187 ;
}
static int F_121 ( struct V_30 * V_31 , int V_57 , int V_191 ,
int V_192 , struct V_82 * V_193 )
{
int V_194 = V_193 -> V_76 . V_7 ;
int V_195 = ( 1 << V_193 -> V_81 ) ;
if ( V_191 < V_194 || V_191 + V_192 > V_194 + V_195 )
return - V_70 ;
return 0 ;
}
int F_122 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_127 = V_159 -> V_166 ;
struct V_82 * V_193 ;
struct V_85 * V_129 ;
int V_196 = F_114 ( V_161 -> V_197 ) / V_31 -> V_52 . V_198 ;
int V_199 ;
int V_73 ;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_58 ( V_31 , V_57 , V_73 , V_131 , & V_129 ) ;
if ( V_65 )
return V_65 ;
V_199 = F_113 ( V_161 -> V_197 ) ;
if ( ! V_199 ) {
V_65 = F_21 ( V_31 , V_57 , V_196 , V_24 , & V_193 ) ;
if ( V_65 )
goto V_200;
V_65 = F_121 ( V_31 , V_57 , V_196 ,
F_116 ( V_161 -> V_197 ) , V_193 ) ;
if ( V_65 )
goto V_201;
V_129 -> V_193 = V_193 ;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_201;
if ( ! V_199 ) {
F_124 ( & V_193 -> V_83 ) ;
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
}
F_63 ( V_31 , V_57 , V_23 , V_73 ) ;
return 0 ;
V_201:
if ( ! V_199 )
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
V_200:
F_62 ( V_31 , V_57 , V_23 , V_73 ) ;
return V_65 ;
}
int F_125 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_127 = V_159 -> V_166 ;
struct V_85 * V_129 ;
int V_73 ;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_58 ( V_31 , V_57 , V_73 , V_130 , & V_129 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_200;
if ( V_129 -> V_193 )
F_126 ( & V_129 -> V_193 -> V_83 ) ;
F_63 ( V_31 , V_57 , V_23 , V_73 ) ;
return 0 ;
V_200:
F_62 ( V_31 , V_57 , V_23 , V_73 ) ;
return V_65 ;
}
int F_127 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_127 = V_159 -> V_166 ;
struct V_85 * V_129 ;
int V_73 ;
V_73 = V_127 & F_19 ( V_31 ) ;
V_65 = F_21 ( V_31 , V_57 , V_73 , V_23 , & V_129 ) ;
if ( V_65 )
return V_65 ;
if ( V_129 -> V_76 . V_71 != V_131 ) {
V_65 = - V_68 ;
goto V_119;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_119:
F_28 ( V_31 , V_57 , V_73 , V_23 ) ;
return V_65 ;
}
static int F_128 ( struct V_55 * V_171 )
{
return F_18 ( V_171 -> V_202 ) & 0xffffff ;
}
static int F_129 ( struct V_55 * V_171 )
{
return F_18 ( V_171 -> V_203 ) & 0xffffff ;
}
static T_3 F_130 ( struct V_55 * V_171 )
{
return F_18 ( V_171 -> V_150 ) & 0x1ffffff ;
}
int F_131 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_120 = V_159 -> V_166 & 0x7fffff ;
struct V_82 * V_193 ;
struct V_74 * V_122 ;
struct V_55 * V_171 = V_161 -> V_197 + 8 ;
int V_196 = F_117 ( V_171 ) / V_31 -> V_52 . V_198 ;
int V_204 = F_119 ( V_171 ) ;
struct V_89 * V_205 ;
struct V_89 * V_206 ;
int V_207 = F_128 ( V_171 ) ;
int V_208 = F_129 ( V_171 ) ;
T_3 V_150 = F_130 ( V_171 ) & 0xffffff ;
int V_209 = ( F_130 ( V_171 ) >> 24 ) & 1 ;
struct V_91 * V_140 ;
int V_78 = F_18 ( V_171 -> V_78 ) & 0xffffff ;
V_65 = F_57 ( V_31 , V_57 , V_120 , V_125 , & V_122 , 0 ) ;
if ( V_65 )
return V_65 ;
V_122 -> V_78 = V_78 ;
V_65 = F_21 ( V_31 , V_57 , V_196 , V_24 , & V_193 ) ;
if ( V_65 )
goto V_200;
V_65 = F_121 ( V_31 , V_57 , V_196 , V_204 , V_193 ) ;
if ( V_65 )
goto V_210;
V_65 = F_21 ( V_31 , V_57 , V_207 , V_21 , & V_205 ) ;
if ( V_65 )
goto V_210;
if ( V_208 != V_207 ) {
V_65 = F_21 ( V_31 , V_57 , V_208 , V_21 , & V_206 ) ;
if ( V_65 )
goto V_211;
} else
V_206 = V_205 ;
if ( V_209 ) {
V_65 = F_21 ( V_31 , V_57 , V_150 , V_22 , & V_140 ) ;
if ( V_65 )
goto V_212;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_213;
F_124 ( & V_193 -> V_83 ) ;
V_122 -> V_193 = V_193 ;
F_124 ( & V_205 -> V_83 ) ;
V_122 -> V_205 = V_205 ;
F_124 ( & V_206 -> V_83 ) ;
V_122 -> V_206 = V_206 ;
if ( V_208 != V_207 )
F_28 ( V_31 , V_57 , V_208 , V_21 ) ;
if ( V_209 ) {
F_124 ( & V_140 -> V_83 ) ;
F_28 ( V_31 , V_57 , V_150 , V_22 ) ;
V_122 -> V_140 = V_140 ;
}
F_28 ( V_31 , V_57 , V_207 , V_21 ) ;
F_28 ( V_31 , V_57 , V_196 , V_24 ) ;
F_63 ( V_31 , V_57 , V_20 , V_120 ) ;
return 0 ;
V_213:
if ( V_209 )
F_28 ( V_31 , V_57 , V_150 , V_22 ) ;
V_212:
if ( V_208 != V_207 )
F_28 ( V_31 , V_57 , V_208 , V_21 ) ;
V_211:
F_28 ( V_31 , V_57 , V_207 , V_21 ) ;
V_210:
F_28 ( V_31 , V_57 , V_196 , V_24 ) ;
V_200:
F_62 ( V_31 , V_57 , V_20 , V_120 ) ;
return V_65 ;
}
static int F_132 ( struct V_214 * V_215 )
{
return F_18 ( V_215 -> V_172 ) & 0xfffffff8 ;
}
static int F_133 ( struct V_214 * V_215 )
{
int V_216 = V_215 -> V_216 & 0x1f ;
int V_175 = ( V_215 -> V_176 & 0x3f ) + 12 ;
if ( V_216 + 5 < V_175 )
return 1 ;
return 1 << ( V_216 + 5 - V_175 ) ;
}
static int F_134 ( struct V_217 * V_218 )
{
return F_18 ( V_218 -> V_172 ) & 0xfffffff8 ;
}
static int F_135 ( struct V_217 * V_218 )
{
int V_219 = ( F_18 ( V_218 -> V_220 ) >> 24 ) & 0x1f ;
int V_175 = ( V_218 -> V_176 & 0x3f ) + 12 ;
if ( V_219 + 5 < V_175 )
return 1 ;
return 1 << ( V_219 + 5 - V_175 ) ;
}
int F_136 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_221 = V_159 -> V_166 ;
int V_7 = ( V_57 << 8 ) | V_221 ;
struct V_214 * V_215 = V_161 -> V_197 ;
int V_196 = F_132 ( V_215 ) / V_31 -> V_52 . V_198 ;
int V_204 = F_133 ( V_215 ) ;
struct V_87 * V_133 ;
struct V_82 * V_193 ;
V_65 = F_41 ( V_31 , V_57 , V_7 , 1 , V_26 , 0 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_59 ( V_31 , V_57 , V_7 , V_135 , & V_133 ) ;
if ( V_65 )
goto V_222;
V_65 = F_21 ( V_31 , V_57 , V_196 , V_24 , & V_193 ) ;
if ( V_65 )
goto V_223;
V_65 = F_121 ( V_31 , V_57 , V_196 , V_204 , V_193 ) ;
if ( V_65 )
goto V_224;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_224;
F_124 ( & V_193 -> V_83 ) ;
V_133 -> V_193 = V_193 ;
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
F_63 ( V_31 , V_57 , V_26 , V_7 ) ;
return 0 ;
V_224:
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
V_223:
F_62 ( V_31 , V_57 , V_26 , V_7 ) ;
V_222:
F_55 ( V_31 , V_57 , V_7 , 1 , V_26 , 0 ) ;
return V_65 ;
}
static int F_137 ( struct V_30 * V_31 , int V_57 , int V_191 ,
int V_225 , struct V_82 * * V_11 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_82 * V_193 ;
int V_65 = - V_111 ;
F_22 ( F_23 ( V_31 ) ) ;
F_138 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_121 ( V_31 , V_57 , V_191 , V_225 , V_193 ) ) {
* V_11 = V_193 ;
V_193 -> V_76 . V_71 = V_193 -> V_76 . V_2 ;
V_193 -> V_76 . V_2 = V_3 ;
V_65 = 0 ;
break;
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_65 ;
}
int F_139 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
struct V_226 V_193 ;
T_4 * V_227 = V_161 -> V_197 ;
T_1 * V_228 = ( T_1 * ) V_227 ;
int V_34 ;
struct V_82 * V_229 = NULL ;
int V_191 = F_115 ( V_227 [ 0 ] ) ;
int V_230 = V_159 -> V_166 ;
int V_65 ;
V_65 = F_137 ( V_31 , V_57 , V_191 , V_230 , & V_229 ) ;
if ( V_65 )
return V_65 ;
V_193 . V_231 = 0 ;
V_193 . V_81 = 0 ;
V_193 . V_175 = 0 ;
for ( V_34 = 0 ; V_34 < V_230 ; ++ V_34 )
V_228 [ V_34 + 2 ] = ( F_115 ( V_227 [ V_34 + 2 ] ) & ~ 1ULL ) ;
V_65 = F_140 ( V_31 , & V_193 , F_115 ( V_227 [ 0 ] ) , V_230 ,
( ( T_1 * ) V_227 + 2 ) ) ;
if ( V_229 )
F_28 ( V_31 , V_57 , V_229 -> V_76 . V_7 , V_24 ) ;
return V_65 ;
}
int F_141 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_221 = V_159 -> V_166 ;
int V_7 = V_221 | ( V_57 << 8 ) ;
struct V_87 * V_133 ;
int V_65 ;
V_65 = F_59 ( V_31 , V_57 , V_7 , V_88 , & V_133 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_21 ( V_31 , V_57 , V_133 -> V_193 -> V_76 . V_7 , V_24 , NULL ) ;
if ( V_65 )
goto V_200;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_201;
F_126 ( & V_133 -> V_193 -> V_83 ) ;
F_28 ( V_31 , V_57 , V_133 -> V_193 -> V_76 . V_7 , V_24 ) ;
F_63 ( V_31 , V_57 , V_26 , V_7 ) ;
F_55 ( V_31 , V_57 , V_7 , 1 , V_26 , 0 ) ;
return 0 ;
V_201:
F_28 ( V_31 , V_57 , V_133 -> V_193 -> V_76 . V_7 , V_24 ) ;
V_200:
F_62 ( V_31 , V_57 , V_26 , V_7 ) ;
return V_65 ;
}
int F_142 ( struct V_30 * V_31 , int V_57 , struct V_232 * V_233 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_234 * V_235 ;
struct V_160 * V_236 ;
T_3 V_166 = 0 ;
int V_65 ;
int V_7 ;
struct V_87 * V_237 ;
if ( ! V_33 -> V_36 . V_37 . V_238 )
return - V_111 ;
V_235 = & V_33 -> V_36 . V_37 . V_238 [ V_57 ] . V_235 [ V_233 -> type ] ;
if ( V_235 -> V_221 < 0 )
return 0 ;
F_143 ( & V_33 -> V_36 . V_37 . V_239 [ V_57 ] ) ;
V_7 = ( V_57 << 8 ) | V_235 -> V_221 ;
V_65 = F_21 ( V_31 , V_57 , V_7 , V_26 , & V_237 ) ;
if ( V_65 )
goto V_240;
if ( V_237 -> V_76 . V_71 != V_135 ) {
V_65 = - V_111 ;
goto V_241;
}
V_236 = F_144 ( V_31 ) ;
if ( F_145 ( V_236 ) ) {
V_65 = F_146 ( V_236 ) ;
goto V_241;
}
if ( V_233 -> type == V_242 ) {
++ V_235 -> V_243 ;
V_233 -> V_244 . V_143 . V_243 = F_147 ( V_235 -> V_243 ) ;
}
memcpy ( V_236 -> V_197 , ( T_2 * ) V_233 , 28 ) ;
V_166 = ( V_57 & 0xff ) | ( ( V_235 -> V_221 & 0xff ) << 16 ) ;
V_65 = F_148 ( V_31 , V_236 -> V_245 , V_166 , 0 ,
V_246 , V_247 ,
V_248 ) ;
F_28 ( V_31 , V_57 , V_7 , V_26 ) ;
F_149 ( & V_33 -> V_36 . V_37 . V_239 [ V_57 ] ) ;
F_150 ( V_31 , V_236 ) ;
return V_65 ;
V_241:
F_28 ( V_31 , V_57 , V_7 , V_26 ) ;
V_240:
F_149 ( & V_33 -> V_36 . V_37 . V_239 [ V_57 ] ) ;
return V_65 ;
}
int F_151 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_221 = V_159 -> V_166 ;
int V_7 = V_221 | ( V_57 << 8 ) ;
struct V_87 * V_133 ;
int V_65 ;
V_65 = F_21 ( V_31 , V_57 , V_7 , V_26 , & V_133 ) ;
if ( V_65 )
return V_65 ;
if ( V_133 -> V_76 . V_71 != V_135 ) {
V_65 = - V_111 ;
goto V_201;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_201:
F_28 ( V_31 , V_57 , V_7 , V_26 ) ;
return V_65 ;
}
int F_152 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_136 = V_159 -> V_166 ;
struct V_217 * V_218 = V_161 -> V_197 ;
int V_196 = F_134 ( V_218 ) / V_31 -> V_52 . V_198 ;
struct V_89 * V_138 ;
struct V_82 * V_193 ;
V_65 = F_60 ( V_31 , V_57 , V_136 , V_139 , & V_138 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_21 ( V_31 , V_57 , V_196 , V_24 , & V_193 ) ;
if ( V_65 )
goto V_223;
V_65 = F_121 ( V_31 , V_57 , V_196 , F_135 ( V_218 ) , V_193 ) ;
if ( V_65 )
goto V_224;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_224;
F_124 ( & V_193 -> V_83 ) ;
V_138 -> V_193 = V_193 ;
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
F_63 ( V_31 , V_57 , V_21 , V_136 ) ;
return 0 ;
V_224:
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
V_223:
F_62 ( V_31 , V_57 , V_21 , V_136 ) ;
return V_65 ;
}
int F_153 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_136 = V_159 -> V_166 ;
struct V_89 * V_138 ;
V_65 = F_60 ( V_31 , V_57 , V_136 , V_90 , & V_138 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_223;
F_126 ( & V_138 -> V_193 -> V_83 ) ;
F_63 ( V_31 , V_57 , V_21 , V_136 ) ;
return 0 ;
V_223:
F_62 ( V_31 , V_57 , V_21 , V_136 ) ;
return V_65 ;
}
int F_154 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_136 = V_159 -> V_166 ;
struct V_89 * V_138 ;
int V_65 ;
V_65 = F_21 ( V_31 , V_57 , V_136 , V_21 , & V_138 ) ;
if ( V_65 )
return V_65 ;
if ( V_138 -> V_76 . V_71 != V_139 )
goto V_201;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_201:
F_28 ( V_31 , V_57 , V_136 , V_21 ) ;
return V_65 ;
}
static int F_155 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 ,
struct V_89 * V_138 )
{
int V_65 ;
struct V_82 * V_249 ;
struct V_82 * V_193 ;
struct V_217 * V_218 = V_161 -> V_197 ;
int V_196 = F_134 ( V_218 ) / V_31 -> V_52 . V_198 ;
V_65 = F_21 ( V_31 , V_57 , V_138 -> V_193 -> V_76 . V_7 , V_24 , & V_249 ) ;
if ( V_65 )
return V_65 ;
if ( V_249 != V_138 -> V_193 ) {
V_65 = - V_111 ;
goto V_201;
}
V_65 = F_21 ( V_31 , V_57 , V_196 , V_24 , & V_193 ) ;
if ( V_65 )
goto V_201;
V_65 = F_121 ( V_31 , V_57 , V_196 , F_135 ( V_218 ) , V_193 ) ;
if ( V_65 )
goto V_250;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_250;
F_126 ( & V_249 -> V_83 ) ;
F_28 ( V_31 , V_57 , V_249 -> V_76 . V_7 , V_24 ) ;
F_124 ( & V_193 -> V_83 ) ;
V_138 -> V_193 = V_193 ;
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
return 0 ;
V_250:
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
V_201:
F_28 ( V_31 , V_57 , V_249 -> V_76 . V_7 , V_24 ) ;
return V_65 ;
}
int F_156 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_136 = V_159 -> V_166 ;
struct V_89 * V_138 ;
int V_65 ;
V_65 = F_21 ( V_31 , V_57 , V_136 , V_21 , & V_138 ) ;
if ( V_65 )
return V_65 ;
if ( V_138 -> V_76 . V_71 != V_139 )
goto V_201;
if ( V_159 -> V_165 == 0 ) {
V_65 = F_155 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 , V_138 ) ;
goto V_201;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_201:
F_28 ( V_31 , V_57 , V_136 , V_21 ) ;
return V_65 ;
}
static int F_157 ( struct V_173 * V_174 )
{
int V_251 = ( F_18 ( V_174 -> V_252 ) >> 24 ) & 0xf ;
int V_182 = V_174 -> V_253 & 7 ;
int V_175 = ( V_174 -> V_176 & 0x3f ) + 12 ;
if ( V_251 + V_182 + 4 < V_175 )
return 1 ;
return 1 << ( V_251 + V_182 + 4 - V_175 ) ;
}
int F_158 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_150 = V_159 -> V_166 ;
struct V_82 * V_193 ;
struct V_91 * V_140 ;
struct V_173 * V_174 = V_161 -> V_197 ;
int V_196 = F_118 ( V_174 ) / V_31 -> V_52 . V_198 ;
if ( V_150 != ( F_18 ( V_174 -> V_252 ) & 0xffffff ) )
return - V_111 ;
V_65 = F_61 ( V_31 , V_57 , V_150 , V_141 , & V_140 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_21 ( V_31 , V_57 , V_196 , V_24 , & V_193 ) ;
if ( V_65 )
goto V_200;
V_65 = F_121 ( V_31 , V_57 , V_196 , F_157 ( V_174 ) ,
V_193 ) ;
if ( V_65 )
goto V_210;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_210;
F_124 ( & V_193 -> V_83 ) ;
V_140 -> V_193 = V_193 ;
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
F_63 ( V_31 , V_57 , V_22 , V_150 ) ;
return 0 ;
V_210:
F_28 ( V_31 , V_57 , V_193 -> V_76 . V_7 , V_24 ) ;
V_200:
F_62 ( V_31 , V_57 , V_22 , V_150 ) ;
return V_65 ;
}
int F_159 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_150 = V_159 -> V_166 ;
struct V_91 * V_140 ;
V_65 = F_61 ( V_31 , V_57 , V_150 , V_92 , & V_140 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_200;
F_126 ( & V_140 -> V_193 -> V_83 ) ;
if ( V_140 -> V_138 )
F_126 ( & V_140 -> V_138 -> V_83 ) ;
F_63 ( V_31 , V_57 , V_22 , V_150 ) ;
return 0 ;
V_200:
F_62 ( V_31 , V_57 , V_22 , V_150 ) ;
return V_65 ;
}
int F_160 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_150 = V_159 -> V_166 ;
struct V_91 * V_140 ;
V_65 = F_21 ( V_31 , V_57 , V_150 , V_22 , & V_140 ) ;
if ( V_65 )
return V_65 ;
if ( V_140 -> V_76 . V_71 != V_141 ) {
V_65 = - V_68 ;
goto V_119;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_119:
F_28 ( V_31 , V_57 , V_150 , V_22 ) ;
return V_65 ;
}
int F_161 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_150 = V_159 -> V_166 ;
struct V_91 * V_140 ;
V_65 = F_21 ( V_31 , V_57 , V_150 , V_22 , & V_140 ) ;
if ( V_65 )
return V_65 ;
if ( V_140 -> V_76 . V_71 != V_141 ) {
V_65 = - V_68 ;
goto V_119;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_119:
F_28 ( V_31 , V_57 , V_150 , V_22 ) ;
return V_65 ;
}
int F_162 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_120 = V_159 -> V_166 & 0x7fffff ;
struct V_74 * V_122 ;
V_65 = F_21 ( V_31 , V_57 , V_120 , V_20 , & V_122 ) ;
if ( V_65 )
return V_65 ;
if ( V_122 -> V_76 . V_71 != V_125 ) {
V_65 = - V_68 ;
goto V_119;
}
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
V_119:
F_28 ( V_31 , V_57 , V_120 , V_20 ) ;
return V_65 ;
}
int F_163 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
struct V_55 * V_171 = V_161 -> V_197 + 8 ;
F_17 ( V_31 , V_171 , ( T_2 ) V_57 ) ;
return F_162 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
}
int F_164 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_120 = V_159 -> V_166 & 0x7fffff ;
struct V_74 * V_122 ;
V_65 = F_57 ( V_31 , V_57 , V_120 , V_124 , & V_122 , 0 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
if ( V_65 )
goto V_200;
F_126 ( & V_122 -> V_193 -> V_83 ) ;
F_126 ( & V_122 -> V_205 -> V_83 ) ;
F_126 ( & V_122 -> V_206 -> V_83 ) ;
if ( V_122 -> V_140 )
F_126 ( & V_122 -> V_140 -> V_83 ) ;
F_63 ( V_31 , V_57 , V_20 , V_120 ) ;
return 0 ;
V_200:
F_62 ( V_31 , V_57 , V_20 , V_120 ) ;
return V_65 ;
}
static struct V_254 * F_165 ( struct V_30 * V_31 , int V_57 ,
struct V_74 * V_255 , T_2 * V_256 )
{
struct V_254 * V_11 ;
F_138 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_256 , V_256 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_166 ( struct V_30 * V_31 , int V_57 , struct V_74 * V_255 ,
T_2 * V_256 , enum V_257 V_258 ,
enum V_259 V_260 )
{
struct V_254 * V_11 ;
int V_65 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
F_22 ( & V_255 -> V_80 ) ;
if ( F_165 ( V_31 , V_57 , V_255 , V_256 ) ) {
F_16 ( V_11 ) ;
V_65 = - V_17 ;
} else {
memcpy ( V_11 -> V_256 , V_256 , 16 ) ;
V_11 -> V_258 = V_258 ;
V_11 -> V_260 = V_260 ;
F_42 ( & V_11 -> V_107 , & V_255 -> V_79 ) ;
V_65 = 0 ;
}
F_24 ( & V_255 -> V_80 ) ;
return V_65 ;
}
static int F_167 ( struct V_30 * V_31 , int V_57 , struct V_74 * V_255 ,
T_2 * V_256 , enum V_257 V_258 ,
enum V_259 V_260 )
{
struct V_254 * V_11 ;
int V_65 ;
F_22 ( & V_255 -> V_80 ) ;
V_11 = F_165 ( V_31 , V_57 , V_255 , V_256 ) ;
if ( ! V_11 || V_11 -> V_258 != V_258 || V_11 -> V_260 != V_260 )
V_65 = - V_111 ;
else {
F_56 ( & V_11 -> V_107 ) ;
F_16 ( V_11 ) ;
V_65 = 0 ;
}
F_24 ( & V_255 -> V_80 ) ;
return V_65 ;
}
int F_168 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
struct V_261 V_122 ;
T_2 * V_256 = V_161 -> V_197 ;
enum V_257 V_258 = ( V_159 -> V_166 >> 28 ) & 0x7 ;
int V_65 ;
int V_120 ;
struct V_74 * V_255 ;
int V_262 = V_159 -> V_165 ;
int V_263 = V_159 -> V_166 >> 31 ;
T_2 V_264 = 2 ;
enum V_259 type = ( V_256 [ 7 ] & V_264 ) >> 1 ;
V_120 = V_159 -> V_166 & 0xffffff ;
V_65 = F_21 ( V_31 , V_57 , V_120 , V_20 , & V_255 ) ;
if ( V_65 )
return V_65 ;
V_122 . V_120 = V_120 ;
if ( V_262 ) {
V_65 = F_166 ( V_31 , V_57 , V_255 , V_256 , V_258 , type ) ;
if ( V_65 )
goto V_201;
V_65 = F_169 ( V_31 , & V_122 , V_256 ,
V_263 , V_258 , type ) ;
if ( V_65 )
goto V_265;
} else {
V_65 = F_167 ( V_31 , V_57 , V_255 , V_256 , V_258 , type ) ;
if ( V_65 )
goto V_201;
V_65 = F_170 ( V_31 , & V_122 , V_256 , V_258 , type ) ;
}
F_28 ( V_31 , V_57 , V_120 , V_20 ) ;
return 0 ;
V_265:
( void ) F_167 ( V_31 , V_57 , V_255 , V_256 , V_258 , type ) ;
V_201:
F_28 ( V_31 , V_57 , V_120 , V_20 ) ;
return V_65 ;
}
static int F_171 ( int V_57 , struct V_266 * V_267 ,
struct V_154 * V_268 )
{
struct V_153 * V_11 , * V_156 ;
T_4 V_269 ;
if ( ! F_172 ( V_267 -> V_270 . V_271 ) &&
! F_173 ( V_267 -> V_270 . V_271 ) ) {
F_88 (res, tmp, rlist, list) {
V_269 = F_174 ( V_11 -> V_151 << 16 ) ;
if ( ! memcmp ( & V_269 , V_267 -> V_270 . V_271 , V_272 ) )
return 0 ;
}
F_175 ( L_22 ,
V_267 -> V_270 . V_271 , V_57 ) ;
return - V_111 ;
}
return 0 ;
}
static int F_176 ( struct V_30 * V_31 , int V_57 ,
struct V_160 * V_161 ,
struct V_154 * V_268 , int V_273 )
{
struct V_153 * V_11 , * V_156 ;
T_2 V_152 ;
struct V_274 * V_275 ;
struct V_276 * V_267 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
T_4 V_269 = 0 ;
T_4 V_281 = F_174 ( V_282 << 16 ) ;
V_275 = (struct V_274 * ) V_161 -> V_197 ;
V_152 = F_18 ( V_275 -> V_283 ) & 0xff ;
V_267 = (struct V_276 * ) ( V_275 + 1 ) ;
switch ( V_273 ) {
case V_284 :
V_278 =
(struct V_277 * ) ( V_267 + 1 ) ;
memmove ( V_278 , V_267 ,
sizeof( * V_278 ) + sizeof( * V_280 ) ) ;
break;
case V_285 :
case V_286 :
V_280 = (struct V_279 * )
( V_267 + 1 ) ;
memmove ( V_280 , V_267 , sizeof( * V_280 ) ) ;
break;
default:
return - V_111 ;
}
F_88 (res, tmp, rlist, list) {
if ( V_152 == V_11 -> V_152 ) {
V_269 = F_174 ( V_11 -> V_151 << 16 ) ;
break;
}
}
if ( ! V_269 ) {
F_175 ( L_23 ,
V_152 ) ;
return - V_111 ;
}
memset ( V_267 , 0 , sizeof( * V_267 ) ) ;
V_267 -> V_192 = sizeof( * V_267 ) >> 2 ;
V_267 -> V_73 = F_147 ( V_287 [ V_288 ] ) ;
memcpy ( V_267 -> V_271 , & V_269 , V_272 ) ;
memcpy ( V_267 -> V_289 , & V_281 , V_272 ) ;
return 0 ;
}
int F_177 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_268 = & V_105 -> V_39 [ V_57 ] . V_44 [ V_25 ] ;
int V_65 ;
struct V_274 * V_275 ;
struct V_266 * V_290 ;
int V_273 ;
if ( V_31 -> V_52 . V_291 !=
V_292 )
return - V_293 ;
V_275 = (struct V_274 * ) V_161 -> V_197 ;
V_290 = (struct V_266 * ) ( V_275 + 1 ) ;
V_273 = F_178 ( F_179 ( V_290 -> V_73 ) ) ;
switch ( V_273 ) {
case V_288 :
if ( F_171 ( V_57 , V_290 , V_268 ) )
return - V_111 ;
break;
case V_284 :
case V_285 :
case V_286 :
F_180 ( L_24 ) ;
if ( F_176 ( V_31 , V_57 , V_161 , V_268 , V_273 ) )
return - V_111 ;
V_159 -> V_166 +=
sizeof( struct V_276 ) >> 2 ;
break;
default:
F_175 ( L_25 ) ;
return - V_111 ;
}
V_65 = F_181 ( V_31 , V_161 -> V_245 , & V_159 -> V_145 ,
V_159 -> V_166 , 0 ,
V_294 , V_295 ,
V_248 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_41 ( V_31 , V_57 , V_159 -> V_145 , 1 , V_28 , 0 ) ;
if ( V_65 ) {
F_182 ( V_31 , L_26 ) ;
F_148 ( V_31 , V_159 -> V_145 , 0 , 0 ,
V_294 , V_295 ,
V_248 ) ;
}
return V_65 ;
}
int F_183 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
if ( V_31 -> V_52 . V_291 !=
V_292 )
return - V_293 ;
V_65 = F_55 ( V_31 , V_57 , V_159 -> V_144 , 1 , V_28 , 0 ) ;
if ( V_65 ) {
F_182 ( V_31 , L_27 ) ;
return V_65 ;
}
V_65 = F_148 ( V_31 , V_159 -> V_144 , 0 , 0 ,
V_296 , V_295 ,
V_248 ) ;
return V_65 ;
}
int F_184 ( struct V_30 * V_31 , int V_57 ,
struct V_158 * V_159 ,
struct V_160 * V_161 ,
struct V_160 * V_162 ,
struct V_163 * V_143 )
{
int V_65 ;
int V_127 = V_159 -> V_166 & 0xffff ;
V_65 = F_21 ( V_31 , V_57 , V_127 , V_27 , NULL ) ;
if ( V_65 )
return V_65 ;
V_65 = F_123 ( V_31 , V_57 , V_159 , V_161 , V_162 , V_143 ) ;
F_28 ( V_31 , V_57 , V_127 , V_27 ) ;
return V_65 ;
}
static void F_185 ( struct V_30 * V_31 , int V_57 , struct V_74 * V_255 )
{
struct V_254 * V_297 ;
struct V_254 * V_156 ;
struct V_261 V_122 ;
F_88 (rgid, tmp, &rqp->mcg_list, list) {
V_122 . V_120 = V_255 -> V_78 ;
( void ) F_170 ( V_31 , & V_122 , V_297 -> V_256 , V_297 -> V_258 ,
V_297 -> V_260 ) ;
F_56 ( & V_297 -> V_107 ) ;
F_16 ( V_297 ) ;
}
}
static int F_186 ( struct V_30 * V_31 , int V_57 ,
enum V_18 type , int V_298 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_268 = & V_105 -> V_39 [ V_57 ] . V_44 [ type ] ;
struct V_10 * V_64 ;
struct V_10 * V_156 ;
int V_299 ;
V_299 = 0 ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (r, tmp, rlist, list) {
if ( V_64 -> V_69 == V_57 ) {
if ( ! V_64 -> V_300 ) {
if ( V_64 -> V_2 == V_67 ) {
if ( V_298 )
F_12 ( V_31 ,
L_28 ,
F_7 ( type ) ,
V_64 -> V_7 ) ;
++ V_299 ;
} else {
V_64 -> V_71 = V_64 -> V_2 ;
V_64 -> V_2 = V_67 ;
V_64 -> V_300 = 1 ;
}
}
}
}
F_24 ( F_23 ( V_31 ) ) ;
return V_299 ;
}
static int F_187 ( struct V_30 * V_31 , int V_57 ,
enum V_18 type )
{
unsigned long V_301 ;
int V_299 ;
V_301 = V_302 ;
do {
V_299 = F_186 ( V_31 , V_57 , type , 0 ) ;
if ( F_188 ( V_302 , V_301 + 5 * V_303 ) )
break;
if ( V_299 )
F_189 () ;
} while ( V_299 );
if ( V_299 )
V_299 = F_186 ( V_31 , V_57 , type , 1 ) ;
return V_299 ;
}
static void F_190 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_304 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_20 ] ;
struct V_74 * V_122 ;
struct V_74 * V_156 ;
int V_2 ;
T_1 V_144 ;
int V_120 ;
int V_65 ;
V_65 = F_187 ( V_31 , V_57 , V_20 ) ;
if ( V_65 )
F_191 ( V_31 , L_29
L_30 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (qp, tmp, qp_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_122 -> V_76 . V_69 == V_57 ) {
V_120 = V_122 -> V_76 . V_7 ;
F_185 ( V_31 , V_57 , V_122 ) ;
V_2 = V_122 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_77 :
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_122 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_20 ] ) ;
F_56 ( & V_122 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_122 ) ;
V_2 = 0 ;
break;
case V_124 :
if ( ! F_64 ( V_31 , V_57 , V_120 ) )
F_102 ( V_31 , V_120 ) ;
V_2 = V_77 ;
break;
case V_125 :
V_144 = V_57 ;
V_65 = F_148 ( V_31 , V_144 ,
V_122 -> V_78 , 2 ,
V_305 ,
V_295 ,
V_248 ) ;
if ( V_65 )
F_12 ( V_31 , L_31
L_32
L_33 , V_57 ,
V_122 -> V_78 ) ;
F_126 ( & V_122 -> V_205 -> V_83 ) ;
F_126 ( & V_122 -> V_206 -> V_83 ) ;
F_126 ( & V_122 -> V_193 -> V_83 ) ;
if ( V_122 -> V_140 )
F_126 ( & V_122 -> V_140 -> V_83 ) ;
V_2 = V_124 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_192 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_306 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_22 ] ;
struct V_91 * V_140 ;
struct V_91 * V_156 ;
int V_2 ;
T_1 V_144 ;
F_193 ( V_307 ) ;
int V_150 ;
int V_65 ;
V_65 = F_187 ( V_31 , V_57 , V_22 ) ;
if ( V_65 )
F_191 ( V_31 , L_34
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (srq, tmp, srq_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_140 -> V_76 . V_69 == V_57 ) {
V_150 = V_140 -> V_76 . V_7 ;
V_2 = V_140 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_92 :
F_85 ( V_31 , V_150 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_140 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_22 ] ) ;
F_56 ( & V_140 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_140 ) ;
V_2 = 0 ;
break;
case V_141 :
V_144 = V_57 ;
V_65 = F_148 ( V_31 , V_144 , V_150 , 1 ,
V_308 ,
V_295 ,
V_248 ) ;
if ( V_65 )
F_12 ( V_31 , L_36
L_37
L_38 ,
V_57 , V_150 ) ;
F_126 ( & V_140 -> V_193 -> V_83 ) ;
if ( V_140 -> V_138 )
F_126 ( & V_140 -> V_138 -> V_83 ) ;
V_2 = V_92 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_194 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_309 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_21 ] ;
struct V_89 * V_138 ;
struct V_89 * V_156 ;
int V_2 ;
T_1 V_144 ;
F_193 ( V_307 ) ;
int V_136 ;
int V_65 ;
V_65 = F_187 ( V_31 , V_57 , V_21 ) ;
if ( V_65 )
F_191 ( V_31 , L_39
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (cq, tmp, cq_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_138 -> V_76 . V_69 == V_57 && ! F_46 ( & V_138 -> V_83 ) ) {
V_136 = V_138 -> V_76 . V_7 ;
V_2 = V_138 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_90 :
F_82 ( V_31 , V_136 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_138 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_21 ] ) ;
F_56 ( & V_138 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_138 ) ;
V_2 = 0 ;
break;
case V_139 :
V_144 = V_57 ;
V_65 = F_148 ( V_31 , V_144 , V_136 , 1 ,
V_310 ,
V_295 ,
V_248 ) ;
if ( V_65 )
F_12 ( V_31 , L_40
L_41
L_38 ,
V_57 , V_136 ) ;
F_126 ( & V_138 -> V_193 -> V_83 ) ;
V_2 = V_90 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_195 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_311 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_23 ] ;
struct V_85 * V_129 ;
struct V_85 * V_156 ;
int V_2 ;
T_1 V_144 ;
F_193 ( V_307 ) ;
int V_312 ;
int V_65 ;
V_65 = F_187 ( V_31 , V_57 , V_23 ) ;
if ( V_65 )
F_191 ( V_31 , L_42
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (mpt, tmp, mpt_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_129 -> V_76 . V_69 == V_57 ) {
V_312 = V_129 -> V_76 . V_7 ;
V_2 = V_129 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_86 :
F_78 ( V_31 , V_129 -> V_84 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_129 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_23 ] ) ;
F_56 ( & V_129 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_129 ) ;
V_2 = 0 ;
break;
case V_130 :
F_105 ( V_31 , V_129 -> V_84 ) ;
V_2 = V_86 ;
break;
case V_131 :
V_144 = V_57 ;
V_65 = F_148 ( V_31 , V_144 , V_312 , 0 ,
V_313 ,
V_295 ,
V_248 ) ;
if ( V_65 )
F_12 ( V_31 , L_43
L_44
L_38 ,
V_57 , V_312 ) ;
if ( V_129 -> V_193 )
F_126 ( & V_129 -> V_193 -> V_83 ) ;
V_2 = V_130 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_196 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_314 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_24 ] ;
struct V_82 * V_193 ;
struct V_82 * V_156 ;
int V_2 ;
F_193 ( V_307 ) ;
int V_101 ;
int V_65 ;
V_65 = F_187 ( V_31 , V_57 , V_24 ) ;
if ( V_65 )
F_191 ( V_31 , L_45
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (mtt, tmp, mtt_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_193 -> V_76 . V_69 == V_57 ) {
V_101 = V_193 -> V_76 . V_7 ;
V_2 = V_193 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_75 ( V_31 , V_101 ,
V_193 -> V_81 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_193 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_24 ] ) ;
F_56 ( & V_193 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_193 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_197 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_315 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_28 ] ;
struct V_97 * V_316 ;
struct V_97 * V_156 ;
int V_2 ;
T_1 V_101 ;
int V_65 ;
V_65 = F_187 ( V_31 , V_57 , V_28 ) ;
if ( V_65 )
F_191 ( V_31 , L_46 ,
V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (fs_rule, tmp, fs_rule_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_316 -> V_76 . V_69 == V_57 ) {
V_101 = V_316 -> V_76 . V_7 ;
V_2 = V_316 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_98 :
V_65 = F_148 ( V_31 , V_101 , 0 , 0 ,
V_296 ,
V_295 ,
V_248 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_316 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_28 ] ) ;
F_56 ( & V_316 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_316 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_198 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_317 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_26 ] ;
struct V_87 * V_133 ;
struct V_87 * V_156 ;
int V_65 ;
int V_2 ;
F_193 ( V_307 ) ;
int V_221 ;
struct V_160 * V_236 ;
V_65 = F_187 ( V_31 , V_57 , V_26 ) ;
if ( V_65 )
F_191 ( V_31 , L_47
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (eq, tmp, eq_list, com.list) {
F_24 ( F_23 ( V_31 ) ) ;
if ( V_133 -> V_76 . V_69 == V_57 ) {
V_221 = V_133 -> V_76 . V_7 ;
V_2 = V_133 -> V_76 . V_71 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_88 :
F_22 ( F_23 ( V_31 ) ) ;
F_43 ( & V_133 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_26 ] ) ;
F_56 ( & V_133 -> V_76 . V_107 ) ;
F_24 ( F_23 ( V_31 ) ) ;
F_16 ( V_133 ) ;
V_2 = 0 ;
break;
case V_135 :
V_236 = F_144 ( V_31 ) ;
if ( F_145 ( V_236 ) ) {
F_189 () ;
continue;
}
V_65 = F_199 ( V_31 , V_57 , 0 ,
V_221 & 0xff , 0 ,
V_318 ,
V_295 ,
V_248 ) ;
if ( V_65 )
F_12 ( V_31 , L_48
L_49
L_38 , V_57 , V_221 ) ;
F_150 ( V_31 , V_236 ) ;
F_126 ( & V_133 -> V_193 -> V_83 ) ;
V_2 = V_88 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_31 ) ) ;
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_200 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_319 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_27 ] ;
struct V_93 * V_320 ;
struct V_93 * V_156 ;
int V_65 ;
int V_127 ;
V_65 = F_187 ( V_31 , V_57 , V_27 ) ;
if ( V_65 )
F_191 ( V_31 , L_50
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (counter, tmp, counter_list, com.list) {
if ( V_320 -> V_76 . V_69 == V_57 ) {
V_127 = V_320 -> V_76 . V_7 ;
F_43 ( & V_320 -> V_76 . V_9 ,
& V_105 -> V_46 [ V_27 ] ) ;
F_56 ( & V_320 -> V_76 . V_107 ) ;
F_16 ( V_320 ) ;
F_96 ( V_31 , V_127 ) ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
}
static void F_201 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_104 * V_105 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_154 * V_321 =
& V_105 -> V_39 [ V_57 ] . V_44 [ V_29 ] ;
struct V_95 * V_322 ;
struct V_95 * V_156 ;
int V_65 ;
int V_157 ;
V_65 = F_187 ( V_31 , V_57 , V_29 ) ;
if ( V_65 )
F_191 ( V_31 , L_51
L_35 , V_57 ) ;
F_22 ( F_23 ( V_31 ) ) ;
F_88 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_322 -> V_76 . V_69 == V_57 ) {
V_157 = V_322 -> V_76 . V_7 ;
F_43 ( & V_322 -> V_76 . V_9 , & V_105 -> V_46 [ V_29 ] ) ;
F_56 ( & V_322 -> V_76 . V_107 ) ;
F_16 ( V_322 ) ;
F_99 ( V_31 , V_157 ) ;
}
}
F_24 ( F_23 ( V_31 ) ) ;
}
void F_15 ( struct V_30 * V_31 , int V_57 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
F_143 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_57 ] . V_45 ) ;
F_89 ( V_31 , V_57 ) ;
F_190 ( V_31 , V_57 ) ;
F_192 ( V_31 , V_57 ) ;
F_194 ( V_31 , V_57 ) ;
F_195 ( V_31 , V_57 ) ;
F_198 ( V_31 , V_57 ) ;
F_196 ( V_31 , V_57 ) ;
F_200 ( V_31 , V_57 ) ;
F_201 ( V_31 , V_57 ) ;
F_197 ( V_31 , V_57 ) ;
F_149 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_57 ] . V_45 ) ;
}
