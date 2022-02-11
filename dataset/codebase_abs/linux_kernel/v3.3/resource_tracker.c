static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
case V_5 : return L_3 ;
case V_6 : return L_4 ;
default: return L_5 ;
}
}
static inline const char * F_2 ( enum V_7 V_2 )
{
switch ( V_2 ) {
case V_8 : return L_6 ;
case V_9 : return L_7 ;
default: return L_5 ;
}
}
static inline const char * F_3 ( enum V_10 V_2 )
{
switch ( V_2 ) {
case V_11 : return L_8 ;
case V_12 : return L_9 ;
case V_13 : return L_10 ;
default: return L_5 ;
}
}
static inline const char * F_4 ( enum V_14 V_2 )
{
switch ( V_2 ) {
case V_15 : return L_11 ;
case V_16 : return L_12 ;
default: return L_5 ;
}
}
static const char * F_5 ( enum V_17 V_18 )
{
switch ( V_18 ) {
case V_19 : return L_13 ;
case V_20 : return L_14 ;
case V_21 : return L_15 ;
case V_22 : return L_16 ;
case V_23 : return L_17 ;
case V_24 : return L_18 ;
case V_25 : return L_19 ;
case V_26 : return L_20 ;
default: return L_21 ;
} ;
}
int F_6 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
int V_31 ;
int V_32 ;
V_30 -> V_33 . V_34 . V_35 . V_36 =
F_7 ( V_28 -> V_37 * sizeof( struct V_36 ) ,
V_38 ) ;
if ( ! V_30 -> V_33 . V_34 . V_35 . V_36 )
return - V_39 ;
for ( V_31 = 0 ; V_31 < V_28 -> V_37 ; V_31 ++ ) {
for ( V_32 = 0 ; V_32 < V_40 ; ++ V_32 )
F_8 ( & V_30 -> V_33 . V_34 . V_35 .
V_36 [ V_31 ] . V_41 [ V_32 ] ) ;
F_9 ( & V_30 -> V_33 . V_34 . V_35 . V_36 [ V_31 ] . V_42 ) ;
}
F_10 ( V_28 , L_22 ,
V_28 -> V_37 ) ;
for ( V_31 = 0 ; V_31 < V_40 ; V_31 ++ )
F_11 ( & V_30 -> V_33 . V_34 . V_35 . V_43 [ V_31 ] ,
V_44 | V_45 ) ;
F_12 ( & V_30 -> V_33 . V_34 . V_35 . V_46 ) ;
return 0 ;
}
void F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
int V_31 ;
if ( V_30 -> V_33 . V_34 . V_35 . V_36 ) {
for ( V_31 = 0 ; V_31 < V_28 -> V_37 ; V_31 ++ )
F_14 ( V_28 , V_31 ) ;
F_15 ( V_30 -> V_33 . V_34 . V_35 . V_36 ) ;
}
}
static void F_16 ( struct V_27 * V_28 ,
struct V_47 * V_48 , T_1 V_49 )
{
T_2 V_50 = ( F_17 ( V_48 -> V_51 ) >> 16 ) & 0xff ;
if ( V_52 == V_50 )
V_48 -> V_53 . V_54 = 0x80 | V_49 ;
F_10 ( V_28 , L_23 ,
V_49 , V_48 -> V_53 . V_54 ) ;
}
static int F_18 ( struct V_27 * V_28 )
{
return V_28 -> V_55 . V_56 - 1 ;
}
static void * F_19 ( struct V_27 * V_28 , int V_57 ,
enum V_17 type )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
return F_20 ( & V_30 -> V_33 . V_34 . V_35 . V_43 [ type ] ,
V_57 ) ;
}
static int F_21 ( struct V_27 * V_28 , int V_49 , int V_57 ,
enum V_17 type ,
void * V_58 )
{
struct V_59 * V_60 ;
int V_61 = 0 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_19 ( V_28 , V_57 , type ) ;
if ( ! V_60 ) {
V_61 = - V_62 ;
goto exit;
}
if ( V_60 -> V_2 == V_63 ) {
V_61 = - V_64 ;
goto exit;
}
if ( V_60 -> V_65 != V_49 ) {
V_61 = - V_66 ;
goto exit;
}
V_60 -> V_67 = V_60 -> V_2 ;
V_60 -> V_2 = V_63 ;
F_10 ( V_28 , L_24 ,
F_5 ( type ) , V_60 -> V_57 ) ;
if ( V_58 )
* ( (struct V_59 * * ) V_58 ) = V_60 ;
exit:
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
int F_25 ( struct V_27 * V_28 ,
enum V_17 type ,
int V_57 , int * V_49 )
{
struct V_59 * V_60 ;
int V_61 = - V_68 ;
int V_69 = V_57 ;
if ( type == V_19 )
V_69 &= 0x7fffff ;
F_26 ( F_23 ( V_28 ) ) ;
V_60 = F_19 ( V_28 , V_69 , type ) ;
if ( V_60 ) {
* V_49 = V_60 -> V_65 ;
V_61 = 0 ;
}
F_27 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static void F_28 ( struct V_27 * V_28 , int V_49 , int V_57 ,
enum V_17 type )
{
struct V_59 * V_60 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_19 ( V_28 , V_57 , type ) ;
if ( V_60 )
V_60 -> V_2 = V_60 -> V_67 ;
F_24 ( F_23 ( V_28 ) ) ;
}
static struct V_59 * F_29 ( int V_69 )
{
struct V_70 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_72 . V_2 = V_4 ;
V_71 -> V_73 = V_69 ;
F_8 ( & V_71 -> V_74 ) ;
F_12 ( & V_71 -> V_75 ) ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_30 ( int V_69 , int V_76 )
{
struct V_77 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_76 = V_76 ;
V_71 -> V_72 . V_2 = V_9 ;
F_31 ( & V_71 -> V_78 , 0 ) ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_32 ( int V_69 , int V_79 )
{
struct V_80 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_72 . V_2 = V_81 ;
V_71 -> V_79 = V_79 ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_33 ( int V_69 )
{
struct V_82 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_72 . V_2 = V_83 ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_34 ( int V_69 )
{
struct V_84 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_72 . V_2 = V_85 ;
F_31 ( & V_71 -> V_78 , 0 ) ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_35 ( int V_69 )
{
struct V_86 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_72 . V_2 = V_12 ;
F_31 ( & V_71 -> V_78 , 0 ) ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_36 ( int V_69 )
{
struct V_87 * V_71 ;
V_71 = F_7 ( sizeof *V_71 , V_38 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_72 . V_57 = V_69 ;
V_71 -> V_72 . V_2 = V_16 ;
return & V_71 -> V_72 ;
}
static struct V_59 * F_37 ( int V_69 , enum V_17 type , int V_49 ,
int V_88 )
{
struct V_59 * V_71 ;
switch ( type ) {
case V_19 :
V_71 = F_29 ( V_69 ) ;
break;
case V_22 :
V_71 = F_32 ( V_69 , V_88 ) ;
break;
case V_23 :
V_71 = F_30 ( V_69 , V_88 ) ;
break;
case V_25 :
V_71 = F_33 ( V_69 ) ;
break;
case V_20 :
V_71 = F_34 ( V_69 ) ;
break;
case V_21 :
V_71 = F_35 ( V_69 ) ;
break;
case V_24 :
F_38 ( V_89 L_25 ) ;
return NULL ;
case V_26 :
V_71 = F_36 ( V_69 ) ;
break;
default:
return NULL ;
}
if ( V_71 )
V_71 -> V_65 = V_49 ;
return V_71 ;
}
static int F_39 ( struct V_27 * V_28 , int V_49 , int V_90 , int V_91 ,
enum V_17 type , int V_88 )
{
int V_31 ;
int V_61 ;
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_59 * * V_92 ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_95 * V_96 = & V_94 -> V_43 [ type ] ;
V_92 = F_7 ( V_91 * sizeof *V_92 , V_38 ) ;
if ( ! V_92 )
return - V_39 ;
for ( V_31 = 0 ; V_31 < V_91 ; ++ V_31 ) {
V_92 [ V_31 ] = F_37 ( V_90 + V_31 , type , V_49 , V_88 ) ;
if ( ! V_92 [ V_31 ] ) {
for ( -- V_31 ; V_31 >= 0 ; -- V_31 )
F_15 ( V_92 [ V_31 ] ) ;
F_15 ( V_92 ) ;
return - V_39 ;
}
}
F_22 ( F_23 ( V_28 ) ) ;
for ( V_31 = 0 ; V_31 < V_91 ; ++ V_31 ) {
if ( F_19 ( V_28 , V_90 + V_31 , type ) ) {
V_61 = - V_97 ;
goto V_98;
}
V_61 = F_40 ( V_96 , V_90 + V_31 , V_92 [ V_31 ] ) ;
if ( V_61 )
goto V_98;
F_41 ( & V_92 [ V_31 ] -> V_99 ,
& V_94 -> V_36 [ V_49 ] . V_41 [ type ] ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_92 ) ;
return 0 ;
V_98:
for ( -- V_31 ; V_31 >= V_90 ; -- V_31 )
F_42 ( & V_94 -> V_43 [ type ] , V_31 ) ;
F_24 ( F_23 ( V_28 ) ) ;
for ( V_31 = 0 ; V_31 < V_91 ; ++ V_31 )
F_15 ( V_92 [ V_31 ] ) ;
F_15 ( V_92 ) ;
return V_61 ;
}
static int F_43 ( struct V_70 * V_58 )
{
if ( V_58 -> V_72 . V_2 == V_3 )
return - V_64 ;
else if ( V_58 -> V_72 . V_2 != V_4 )
return - V_66 ;
return 0 ;
}
static int F_44 ( struct V_77 * V_58 , int V_76 )
{
if ( V_58 -> V_72 . V_2 == V_8 ||
F_45 ( & V_58 -> V_78 ) ) {
F_38 ( V_100 L_26 ,
V_101 , __LINE__ ,
F_2 ( V_58 -> V_72 . V_2 ) ,
F_45 ( & V_58 -> V_78 ) ) ;
return - V_64 ;
} else if ( V_58 -> V_72 . V_2 != V_9 )
return - V_66 ;
else if ( V_58 -> V_76 != V_76 )
return - V_102 ;
return 0 ;
}
static int F_46 ( struct V_80 * V_58 )
{
if ( V_58 -> V_72 . V_2 == V_103 )
return - V_64 ;
else if ( V_58 -> V_72 . V_2 != V_81 )
return - V_66 ;
return 0 ;
}
static int F_47 ( struct V_82 * V_58 )
{
if ( V_58 -> V_72 . V_2 == V_103 )
return - V_64 ;
else if ( V_58 -> V_72 . V_2 != V_81 )
return - V_66 ;
return 0 ;
}
static int F_48 ( struct V_87 * V_58 )
{
if ( V_58 -> V_72 . V_2 == V_15 )
return - V_64 ;
else if ( V_58 -> V_72 . V_2 != V_16 )
return - V_66 ;
return 0 ;
}
static int F_49 ( struct V_84 * V_58 )
{
if ( V_58 -> V_72 . V_2 == V_104 )
return - V_64 ;
else if ( V_58 -> V_72 . V_2 != V_85 )
return - V_66 ;
return 0 ;
}
static int F_50 ( struct V_86 * V_58 )
{
if ( V_58 -> V_72 . V_2 == V_11 )
return - V_64 ;
else if ( V_58 -> V_72 . V_2 != V_12 )
return - V_66 ;
return 0 ;
}
static int F_51 ( struct V_59 * V_58 , enum V_17 type , int V_88 )
{
switch ( type ) {
case V_19 :
return F_43 ( (struct V_70 * ) V_58 ) ;
case V_20 :
return F_49 ( (struct V_84 * ) V_58 ) ;
case V_21 :
return F_50 ( (struct V_86 * ) V_58 ) ;
case V_22 :
return F_46 ( (struct V_80 * ) V_58 ) ;
case V_23 :
return F_44 ( (struct V_77 * ) V_58 , V_88 ) ;
case V_24 :
return - V_105 ;
case V_25 :
return F_47 ( (struct V_82 * ) V_58 ) ;
case V_26 :
return F_48 ( (struct V_87 * ) V_58 ) ;
default:
return - V_102 ;
}
}
static int F_52 ( struct V_27 * V_28 , int V_49 , int V_90 , int V_91 ,
enum V_17 type , int V_88 )
{
int V_31 ;
int V_61 ;
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_59 * V_60 ;
F_22 ( F_23 ( V_28 ) ) ;
for ( V_31 = V_90 ; V_31 < V_90 + V_91 ; ++ V_31 ) {
V_60 = F_20 ( & V_94 -> V_43 [ type ] , V_31 ) ;
if ( ! V_60 ) {
V_61 = - V_68 ;
goto V_106;
}
if ( V_60 -> V_65 != V_49 ) {
V_61 = - V_66 ;
goto V_106;
}
V_61 = F_51 ( V_60 , type , V_88 ) ;
if ( V_61 )
goto V_106;
}
for ( V_31 = V_90 ; V_31 < V_90 + V_91 ; ++ V_31 ) {
V_60 = F_20 ( & V_94 -> V_43 [ type ] , V_31 ) ;
F_42 ( & V_94 -> V_43 [ type ] , V_31 ) ;
F_53 ( & V_60 -> V_99 ) ;
F_15 ( V_60 ) ;
}
V_61 = 0 ;
V_106:
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static int F_54 ( struct V_27 * V_28 , int V_49 , int V_107 ,
enum V_1 V_2 , struct V_70 * * V_108 ,
int V_109 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_70 * V_60 ;
int V_61 = 0 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ V_19 ] , V_107 ) ;
if ( ! V_60 )
V_61 = - V_68 ;
else if ( V_60 -> V_72 . V_65 != V_49 )
V_61 = - V_66 ;
else {
switch ( V_2 ) {
case V_3 :
F_10 ( V_28 , L_27 ,
V_101 , V_60 -> V_72 . V_57 ) ;
V_61 = - V_64 ;
break;
case V_4 :
if ( V_60 -> V_72 . V_2 == V_5 && ! V_109 )
break;
F_10 ( V_28 , L_28 , V_60 -> V_72 . V_57 ) ;
V_61 = - V_102 ;
break;
case V_5 :
if ( ( V_60 -> V_72 . V_2 == V_4 && V_109 ) ||
V_60 -> V_72 . V_2 == V_6 )
break;
else {
F_10 ( V_28 , L_28 ,
V_60 -> V_72 . V_57 ) ;
V_61 = - V_102 ;
}
break;
case V_6 :
if ( V_60 -> V_72 . V_2 != V_5 )
V_61 = - V_102 ;
break;
default:
V_61 = - V_102 ;
}
if ( ! V_61 ) {
V_60 -> V_72 . V_67 = V_60 -> V_72 . V_2 ;
V_60 -> V_72 . V_110 = V_2 ;
V_60 -> V_72 . V_2 = V_3 ;
if ( V_108 )
* V_108 = (struct V_70 * ) V_60 ;
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static int F_55 ( struct V_27 * V_28 , int V_49 , int V_111 ,
enum V_112 V_2 , struct V_80 * * V_113 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_80 * V_60 ;
int V_61 = 0 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ V_22 ] , V_111 ) ;
if ( ! V_60 )
V_61 = - V_68 ;
else if ( V_60 -> V_72 . V_65 != V_49 )
V_61 = - V_66 ;
else {
switch ( V_2 ) {
case V_103 :
V_61 = - V_102 ;
break;
case V_81 :
if ( V_60 -> V_72 . V_2 != V_114 )
V_61 = - V_102 ;
break;
case V_114 :
if ( V_60 -> V_72 . V_2 != V_81 &&
V_60 -> V_72 . V_2 != V_115 )
V_61 = - V_102 ;
break;
case V_115 :
if ( V_60 -> V_72 . V_2 != V_114 )
V_61 = - V_102 ;
break;
default:
V_61 = - V_102 ;
}
if ( ! V_61 ) {
V_60 -> V_72 . V_67 = V_60 -> V_72 . V_2 ;
V_60 -> V_72 . V_110 = V_2 ;
V_60 -> V_72 . V_2 = V_103 ;
if ( V_113 )
* V_113 = (struct V_80 * ) V_60 ;
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static int F_56 ( struct V_27 * V_28 , int V_49 , int V_111 ,
enum V_116 V_2 , struct V_82 * * V_117 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_82 * V_60 ;
int V_61 = 0 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ V_25 ] , V_111 ) ;
if ( ! V_60 )
V_61 = - V_68 ;
else if ( V_60 -> V_72 . V_65 != V_49 )
V_61 = - V_66 ;
else {
switch ( V_2 ) {
case V_118 :
V_61 = - V_102 ;
break;
case V_83 :
if ( V_60 -> V_72 . V_2 != V_119 )
V_61 = - V_102 ;
break;
case V_119 :
if ( V_60 -> V_72 . V_2 != V_83 )
V_61 = - V_102 ;
break;
default:
V_61 = - V_102 ;
}
if ( ! V_61 ) {
V_60 -> V_72 . V_67 = V_60 -> V_72 . V_2 ;
V_60 -> V_72 . V_110 = V_2 ;
V_60 -> V_72 . V_2 = V_118 ;
if ( V_117 )
* V_117 = V_60 ;
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static int F_57 ( struct V_27 * V_28 , int V_49 , int V_120 ,
enum V_121 V_2 , struct V_84 * * V_122 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_84 * V_60 ;
int V_61 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ V_20 ] , V_120 ) ;
if ( ! V_60 )
V_61 = - V_68 ;
else if ( V_60 -> V_72 . V_65 != V_49 )
V_61 = - V_66 ;
else {
switch ( V_2 ) {
case V_104 :
V_61 = - V_64 ;
break;
case V_85 :
if ( V_60 -> V_72 . V_2 != V_123 )
V_61 = - V_102 ;
else if ( F_45 ( & V_60 -> V_78 ) )
V_61 = - V_64 ;
else
V_61 = 0 ;
break;
case V_123 :
if ( V_60 -> V_72 . V_2 != V_85 )
V_61 = - V_102 ;
else
V_61 = 0 ;
break;
default:
V_61 = - V_102 ;
}
if ( ! V_61 ) {
V_60 -> V_72 . V_67 = V_60 -> V_72 . V_2 ;
V_60 -> V_72 . V_110 = V_2 ;
V_60 -> V_72 . V_2 = V_104 ;
if ( V_122 )
* V_122 = V_60 ;
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static int F_58 ( struct V_27 * V_28 , int V_49 , int V_111 ,
enum V_121 V_2 , struct V_86 * * V_124 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_86 * V_60 ;
int V_61 = 0 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ V_21 ] , V_111 ) ;
if ( ! V_60 )
V_61 = - V_68 ;
else if ( V_60 -> V_72 . V_65 != V_49 )
V_61 = - V_66 ;
else {
switch ( V_2 ) {
case V_11 :
V_61 = - V_102 ;
break;
case V_12 :
if ( V_60 -> V_72 . V_2 != V_13 )
V_61 = - V_102 ;
else if ( F_45 ( & V_60 -> V_78 ) )
V_61 = - V_64 ;
break;
case V_13 :
if ( V_60 -> V_72 . V_2 != V_12 )
V_61 = - V_102 ;
break;
default:
V_61 = - V_102 ;
}
if ( ! V_61 ) {
V_60 -> V_72 . V_67 = V_60 -> V_72 . V_2 ;
V_60 -> V_72 . V_110 = V_2 ;
V_60 -> V_72 . V_2 = V_11 ;
if ( V_124 )
* V_124 = V_60 ;
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
static void F_59 ( struct V_27 * V_28 , int V_49 ,
enum V_17 type , int V_69 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_59 * V_60 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ type ] , V_69 ) ;
if ( V_60 && ( V_60 -> V_65 == V_49 ) )
V_60 -> V_2 = V_60 -> V_67 ;
F_24 ( F_23 ( V_28 ) ) ;
}
static void F_60 ( struct V_27 * V_28 , int V_49 ,
enum V_17 type , int V_69 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_59 * V_60 ;
F_22 ( F_23 ( V_28 ) ) ;
V_60 = F_20 ( & V_94 -> V_43 [ type ] , V_69 ) ;
if ( V_60 && ( V_60 -> V_65 == V_49 ) )
V_60 -> V_2 = V_60 -> V_110 ;
F_24 ( F_23 ( V_28 ) ) ;
}
static int F_61 ( struct V_27 * V_28 , int V_49 , int V_107 )
{
return F_62 ( V_28 , V_107 ) ;
}
static int F_63 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_61 ;
int V_91 ;
int V_129 ;
int V_90 ;
int V_107 ;
switch ( V_125 ) {
case V_130 :
V_91 = F_64 ( & V_127 ) ;
V_129 = F_65 ( & V_127 ) ;
V_61 = F_66 ( V_28 , V_91 , V_129 , & V_90 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_39 ( V_28 , V_49 , V_90 , V_91 , V_19 , 0 ) ;
if ( V_61 ) {
F_67 ( V_28 , V_90 , V_91 ) ;
return V_61 ;
}
F_68 ( V_128 , V_90 ) ;
break;
case V_131 :
V_107 = F_64 ( & V_127 ) & 0x7fffff ;
if ( F_61 ( V_28 , V_49 , V_107 ) ) {
V_61 = F_39 ( V_28 , V_49 , V_107 , 1 , V_19 , 0 ) ;
if ( V_61 )
return V_61 ;
}
V_61 = F_54 ( V_28 , V_49 , V_107 , V_5 ,
NULL , 1 ) ;
if ( V_61 )
return V_61 ;
if ( ! F_61 ( V_28 , V_49 , V_107 ) ) {
V_61 = F_69 ( V_28 , V_107 ) ;
if ( V_61 ) {
F_59 ( V_28 , V_49 , V_19 , V_107 ) ;
return V_61 ;
}
}
F_60 ( V_28 , V_49 , V_19 , V_107 ) ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_70 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_61 = - V_102 ;
int V_90 ;
int V_76 ;
if ( V_125 != V_132 )
return V_61 ;
V_76 = F_64 ( & V_127 ) ;
V_90 = F_71 ( V_28 , V_76 ) ;
if ( V_90 == - 1 )
return - V_39 ;
V_61 = F_39 ( V_28 , V_49 , V_90 , 1 , V_23 , V_76 ) ;
if ( V_61 )
F_72 ( V_28 , V_90 , V_76 ) ;
else
F_68 ( V_128 , V_90 ) ;
return V_61 ;
}
static int F_73 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_61 = - V_102 ;
int V_111 ;
int V_69 ;
struct V_80 * V_113 ;
switch ( V_125 ) {
case V_130 :
V_111 = F_74 ( V_28 ) ;
if ( V_111 == - 1 )
break;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_39 ( V_28 , V_49 , V_69 , 1 , V_22 , V_111 ) ;
if ( V_61 ) {
F_75 ( V_28 , V_111 ) ;
break;
}
F_68 ( V_128 , V_111 ) ;
break;
case V_131 :
V_111 = F_64 ( & V_127 ) ;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_55 ( V_28 , V_49 , V_69 ,
V_114 , & V_113 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_76 ( V_28 , V_113 -> V_79 ) ;
if ( V_61 ) {
F_59 ( V_28 , V_49 , V_22 , V_69 ) ;
return V_61 ;
}
F_60 ( V_28 , V_49 , V_22 , V_69 ) ;
break;
}
return V_61 ;
}
static int F_77 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_120 ;
int V_61 ;
switch ( V_125 ) {
case V_132 :
V_61 = F_78 ( V_28 , & V_120 ) ;
if ( V_61 )
break;
V_61 = F_39 ( V_28 , V_49 , V_120 , 1 , V_20 , 0 ) ;
if ( V_61 ) {
F_79 ( V_28 , V_120 ) ;
break;
}
F_68 ( V_128 , V_120 ) ;
break;
default:
V_61 = - V_102 ;
}
return V_61 ;
}
static int F_80 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_133 ;
int V_61 ;
switch ( V_125 ) {
case V_132 :
V_61 = F_81 ( V_28 , & V_133 ) ;
if ( V_61 )
break;
V_61 = F_39 ( V_28 , V_49 , V_133 , 1 , V_21 , 0 ) ;
if ( V_61 ) {
F_82 ( V_28 , V_133 ) ;
break;
}
F_68 ( V_128 , V_133 ) ;
break;
default:
V_61 = - V_102 ;
}
return V_61 ;
}
static int F_83 ( struct V_27 * V_28 , int V_49 , T_3 V_134 , int V_135 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_136 * V_58 ;
V_58 = F_7 ( sizeof *V_58 , V_38 ) ;
if ( ! V_58 )
return - V_39 ;
V_58 -> V_134 = V_134 ;
V_58 -> V_135 = ( T_1 ) V_135 ;
F_41 ( & V_58 -> V_99 ,
& V_94 -> V_36 [ V_49 ] . V_41 [ V_24 ] ) ;
return 0 ;
}
static void F_84 ( struct V_27 * V_28 , int V_49 , T_3 V_134 ,
int V_135 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_138 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_24 ] ;
struct V_136 * V_58 , * V_139 ;
F_85 (res, tmp, mac_list, list) {
if ( V_58 -> V_134 == V_134 && V_58 -> V_135 == ( T_1 ) V_135 ) {
F_53 ( & V_58 -> V_99 ) ;
F_15 ( V_58 ) ;
break;
}
}
}
static void F_86 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_138 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_24 ] ;
struct V_136 * V_58 , * V_139 ;
F_85 (res, tmp, mac_list, list) {
F_53 ( & V_58 -> V_99 ) ;
F_87 ( V_28 , V_58 -> V_135 , V_58 -> V_134 ) ;
F_15 ( V_58 ) ;
}
}
static int F_88 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_61 = - V_102 ;
int V_135 ;
T_3 V_134 ;
if ( V_125 != V_132 )
return V_61 ;
V_135 = F_64 ( V_128 ) ;
V_134 = V_127 ;
V_61 = F_89 ( V_28 , V_135 , V_134 ) ;
if ( V_61 >= 0 ) {
F_68 ( V_128 , V_61 ) ;
V_61 = 0 ;
}
if ( ! V_61 ) {
V_61 = F_83 ( V_28 , V_49 , V_134 , V_135 ) ;
if ( V_61 )
F_87 ( V_28 , V_135 , V_134 ) ;
}
return V_61 ;
}
static int F_90 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
return 0 ;
}
int F_91 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_146 = V_141 -> V_147 ;
switch ( V_141 -> V_148 ) {
case V_19 :
V_61 = F_63 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_23 :
V_61 = F_70 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_22 :
V_61 = F_73 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_20 :
V_61 = F_77 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_21 :
V_61 = F_80 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_24 :
V_61 = F_88 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_149 :
V_61 = F_90 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_92 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 )
{
int V_61 ;
int V_91 ;
int V_90 ;
int V_107 ;
switch ( V_125 ) {
case V_130 :
V_90 = F_64 ( & V_127 ) & 0x7fffff ;
V_91 = F_65 ( & V_127 ) ;
V_61 = F_52 ( V_28 , V_49 , V_90 , V_91 , V_19 , 0 ) ;
if ( V_61 )
break;
F_67 ( V_28 , V_90 , V_91 ) ;
break;
case V_131 :
V_107 = F_64 ( & V_127 ) & 0x7fffff ;
V_61 = F_54 ( V_28 , V_49 , V_107 , V_4 ,
NULL , 0 ) ;
if ( V_61 )
return V_61 ;
if ( ! F_61 ( V_28 , V_49 , V_107 ) )
F_93 ( V_28 , V_107 ) ;
F_60 ( V_28 , V_49 , V_19 , V_107 ) ;
if ( F_61 ( V_28 , V_49 , V_107 ) )
V_61 = F_52 ( V_28 , V_49 , V_107 , 1 , V_19 , 0 ) ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_94 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_61 = - V_102 ;
int V_90 ;
int V_76 ;
if ( V_125 != V_132 )
return V_61 ;
V_90 = F_64 ( & V_127 ) ;
V_76 = F_65 ( & V_127 ) ;
V_61 = F_52 ( V_28 , V_49 , V_90 , 1 , V_23 , V_76 ) ;
if ( ! V_61 )
F_72 ( V_28 , V_90 , V_76 ) ;
return V_61 ;
}
static int F_95 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 )
{
int V_61 = - V_102 ;
int V_111 ;
int V_69 ;
struct V_80 * V_113 ;
switch ( V_125 ) {
case V_130 :
V_111 = F_64 ( & V_127 ) ;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_21 ( V_28 , V_49 , V_69 , V_22 , & V_113 ) ;
if ( V_61 )
break;
V_111 = V_113 -> V_79 ;
F_28 ( V_28 , V_49 , V_69 , V_22 ) ;
V_61 = F_52 ( V_28 , V_49 , V_69 , 1 , V_22 , 0 ) ;
if ( V_61 )
break;
F_75 ( V_28 , V_111 ) ;
break;
case V_131 :
V_111 = F_64 ( & V_127 ) ;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_55 ( V_28 , V_49 , V_69 ,
V_81 , & V_113 ) ;
if ( V_61 )
return V_61 ;
F_96 ( V_28 , V_113 -> V_79 ) ;
F_60 ( V_28 , V_49 , V_22 , V_69 ) ;
return V_61 ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_97 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_120 ;
int V_61 ;
switch ( V_125 ) {
case V_132 :
V_120 = F_64 ( & V_127 ) ;
V_61 = F_52 ( V_28 , V_49 , V_120 , 1 , V_20 , 0 ) ;
if ( V_61 )
break;
F_79 ( V_28 , V_120 ) ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_98 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_133 ;
int V_61 ;
switch ( V_125 ) {
case V_132 :
V_133 = F_64 ( & V_127 ) ;
V_61 = F_52 ( V_28 , V_49 , V_133 , 1 , V_21 , 0 ) ;
if ( V_61 )
break;
F_82 ( V_28 , V_133 ) ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_99 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
int V_135 ;
int V_61 = 0 ;
switch ( V_125 ) {
case V_132 :
V_135 = F_64 ( V_128 ) ;
F_84 ( V_28 , V_49 , V_127 , V_135 ) ;
F_87 ( V_28 , V_135 , V_127 ) ;
break;
default:
V_61 = - V_102 ;
break;
}
return V_61 ;
}
static int F_100 ( struct V_27 * V_28 , int V_49 , int V_125 , int V_126 ,
T_3 V_127 , T_3 * V_128 )
{
return 0 ;
}
int F_101 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 = - V_102 ;
int V_146 = V_141 -> V_147 ;
switch ( V_141 -> V_148 ) {
case V_19 :
V_61 = F_92 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 ) ;
break;
case V_23 :
V_61 = F_94 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_22 :
V_61 = F_95 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 ) ;
break;
case V_20 :
V_61 = F_97 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_21 :
V_61 = F_98 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_24 :
V_61 = F_99 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
case V_149 :
V_61 = F_100 ( V_28 , V_49 , V_141 -> V_147 , V_146 ,
V_141 -> V_127 , & V_141 -> V_128 ) ;
break;
default:
break;
}
return V_61 ;
}
static int F_102 ( struct V_150 * V_113 )
{
return ( F_17 ( V_113 -> V_51 ) >> 9 ) & 1 ;
}
static int F_103 ( struct V_150 * V_113 )
{
return ( int ) F_104 ( V_113 -> V_151 ) & 0xfffffff8 ;
}
static int F_105 ( struct V_150 * V_113 )
{
return F_17 ( V_113 -> V_152 ) ;
}
static int F_106 ( struct V_47 * V_153 )
{
return F_17 ( V_153 -> V_154 ) & 0xfffffff8 ;
}
static int F_107 ( struct V_155 * V_156 )
{
return F_17 ( V_156 -> V_154 ) & 0xfffffff8 ;
}
static int F_108 ( struct V_47 * V_153 )
{
int V_157 = ( V_153 -> V_158 & 0x3f ) + 12 ;
int V_159 = ( V_153 -> V_160 >> 3 ) & 0xf ;
int V_161 = V_153 -> V_160 & 7 ;
int V_162 = ( V_153 -> V_163 >> 3 ) & 0xf ;
int V_164 = V_153 -> V_163 & 7 ;
int V_124 = ( F_17 ( V_153 -> V_133 ) >> 24 ) & 1 ;
int V_165 = ( F_17 ( V_153 -> V_51 ) >> 13 ) & 1 ;
int V_166 = ( F_17 ( V_153 -> V_73 ) >> 23 ) & 1 ;
int V_167 ;
int V_168 ;
int V_169 ;
int V_170 ;
int V_171 = ( F_17 ( V_153 -> V_172 ) >> 6 ) & 0x3f ;
V_167 = 1 << ( V_159 + V_161 + 4 ) ;
V_168 = ( V_124 | V_165 | V_166 ) ? 0 : ( 1 << ( V_162 + V_164 + 4 ) ) ;
V_170 = V_167 + V_168 ;
V_169 =
F_109 ( ( V_170 + ( V_171 << 6 ) ) >>
V_157 ) ;
return V_169 ;
}
static int F_110 ( struct V_27 * V_28 , int V_49 , int V_173 ,
int V_174 , struct V_77 * V_175 )
{
int V_176 = V_175 -> V_72 . V_57 ;
int V_177 = ( 1 << V_175 -> V_76 ) ;
if ( V_173 < V_176 || V_173 + V_174 > V_176 + V_177 )
return - V_66 ;
return 0 ;
}
int F_111 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_111 = V_141 -> V_148 ;
struct V_77 * V_175 ;
struct V_80 * V_113 ;
int V_178 = F_103 ( V_143 -> V_179 ) / V_28 -> V_55 . V_180 ;
int V_181 ;
int V_69 ;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_55 ( V_28 , V_49 , V_69 , V_115 , & V_113 ) ;
if ( V_61 )
return V_61 ;
V_181 = F_102 ( V_143 -> V_179 ) ;
if ( ! V_181 ) {
V_61 = F_21 ( V_28 , V_49 , V_178 , V_23 , & V_175 ) ;
if ( V_61 )
goto V_182;
V_61 = F_110 ( V_28 , V_49 , V_178 ,
F_105 ( V_143 -> V_179 ) , V_175 ) ;
if ( V_61 )
goto V_183;
V_113 -> V_175 = V_175 ;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_183;
if ( ! V_181 ) {
F_113 ( & V_175 -> V_78 ) ;
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
}
F_60 ( V_28 , V_49 , V_22 , V_69 ) ;
return 0 ;
V_183:
if ( ! V_181 )
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
V_182:
F_59 ( V_28 , V_49 , V_22 , V_69 ) ;
return V_61 ;
}
int F_114 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_111 = V_141 -> V_148 ;
struct V_80 * V_113 ;
int V_69 ;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_55 ( V_28 , V_49 , V_69 , V_114 , & V_113 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_182;
if ( V_113 -> V_175 )
F_115 ( & V_113 -> V_175 -> V_78 ) ;
F_60 ( V_28 , V_49 , V_22 , V_69 ) ;
return 0 ;
V_182:
F_59 ( V_28 , V_49 , V_22 , V_69 ) ;
return V_61 ;
}
int F_116 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_111 = V_141 -> V_148 ;
struct V_80 * V_113 ;
int V_69 ;
V_69 = V_111 & F_18 ( V_28 ) ;
V_61 = F_21 ( V_28 , V_49 , V_69 , V_22 , & V_113 ) ;
if ( V_61 )
return V_61 ;
if ( V_113 -> V_72 . V_67 != V_115 ) {
V_61 = - V_64 ;
goto V_106;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_106:
F_28 ( V_28 , V_49 , V_69 , V_22 ) ;
return V_61 ;
}
static int F_117 ( struct V_47 * V_153 )
{
return F_17 ( V_153 -> V_184 ) & 0xffffff ;
}
static int F_118 ( struct V_47 * V_153 )
{
return F_17 ( V_153 -> V_185 ) & 0xffffff ;
}
static T_2 F_119 ( struct V_47 * V_153 )
{
return F_17 ( V_153 -> V_133 ) & 0x1ffffff ;
}
int F_120 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_107 = V_141 -> V_148 & 0x7fffff ;
struct V_77 * V_175 ;
struct V_70 * V_108 ;
struct V_47 * V_153 = V_143 -> V_179 + 8 ;
int V_178 = F_106 ( V_153 ) / V_28 -> V_55 . V_180 ;
int V_186 = F_108 ( V_153 ) ;
struct V_84 * V_187 ;
struct V_84 * V_188 ;
int V_189 = F_117 ( V_153 ) ;
int V_190 = F_118 ( V_153 ) ;
T_2 V_133 = F_119 ( V_153 ) & 0xffffff ;
int V_191 = ( F_119 ( V_153 ) >> 24 ) & 1 ;
struct V_86 * V_124 ;
int V_73 = F_17 ( V_153 -> V_73 ) & 0xffffff ;
V_61 = F_54 ( V_28 , V_49 , V_107 , V_6 , & V_108 , 0 ) ;
if ( V_61 )
return V_61 ;
V_108 -> V_73 = V_73 ;
V_61 = F_21 ( V_28 , V_49 , V_178 , V_23 , & V_175 ) ;
if ( V_61 )
goto V_182;
V_61 = F_110 ( V_28 , V_49 , V_178 , V_186 , V_175 ) ;
if ( V_61 )
goto V_192;
V_61 = F_21 ( V_28 , V_49 , V_189 , V_20 , & V_187 ) ;
if ( V_61 )
goto V_192;
if ( V_190 != V_189 ) {
V_61 = F_21 ( V_28 , V_49 , V_190 , V_20 , & V_188 ) ;
if ( V_61 )
goto V_193;
} else
V_188 = V_187 ;
if ( V_191 ) {
V_61 = F_21 ( V_28 , V_49 , V_133 , V_21 , & V_124 ) ;
if ( V_61 )
goto V_194;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_195;
F_113 ( & V_175 -> V_78 ) ;
V_108 -> V_175 = V_175 ;
F_113 ( & V_187 -> V_78 ) ;
V_108 -> V_187 = V_187 ;
F_113 ( & V_188 -> V_78 ) ;
V_108 -> V_188 = V_188 ;
if ( V_190 != V_189 )
F_28 ( V_28 , V_49 , V_190 , V_20 ) ;
if ( V_191 ) {
F_113 ( & V_124 -> V_78 ) ;
F_28 ( V_28 , V_49 , V_133 , V_21 ) ;
V_108 -> V_124 = V_124 ;
}
F_28 ( V_28 , V_49 , V_189 , V_20 ) ;
F_28 ( V_28 , V_49 , V_178 , V_23 ) ;
F_60 ( V_28 , V_49 , V_19 , V_107 ) ;
return 0 ;
V_195:
if ( V_191 )
F_28 ( V_28 , V_49 , V_133 , V_21 ) ;
V_194:
if ( V_190 != V_189 )
F_28 ( V_28 , V_49 , V_190 , V_20 ) ;
V_193:
F_28 ( V_28 , V_49 , V_189 , V_20 ) ;
V_192:
F_28 ( V_28 , V_49 , V_178 , V_23 ) ;
V_182:
F_59 ( V_28 , V_49 , V_19 , V_107 ) ;
return V_61 ;
}
static int F_121 ( struct V_196 * V_197 )
{
return F_17 ( V_197 -> V_154 ) & 0xfffffff8 ;
}
static int F_122 ( struct V_196 * V_197 )
{
int V_198 = V_197 -> V_198 & 0x1f ;
int V_157 = ( V_197 -> V_158 & 0x3f ) + 12 ;
if ( V_198 + 5 < V_157 )
return 1 ;
return 1 << ( V_198 + 5 - V_157 ) ;
}
static int F_123 ( struct V_199 * V_200 )
{
return F_17 ( V_200 -> V_154 ) & 0xfffffff8 ;
}
static int F_124 ( struct V_199 * V_200 )
{
int V_201 = ( F_17 ( V_200 -> V_202 ) >> 24 ) & 0x1f ;
int V_157 = ( V_200 -> V_158 & 0x3f ) + 12 ;
if ( V_201 + 5 < V_157 )
return 1 ;
return 1 << ( V_201 + 5 - V_157 ) ;
}
int F_125 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_203 = V_141 -> V_148 ;
int V_57 = ( V_49 << 8 ) | V_203 ;
struct V_196 * V_197 = V_143 -> V_179 ;
int V_178 = F_121 ( V_197 ) / V_28 -> V_55 . V_180 ;
int V_186 = F_122 ( V_197 ) ;
struct V_82 * V_117 ;
struct V_77 * V_175 ;
V_61 = F_39 ( V_28 , V_49 , V_57 , 1 , V_25 , 0 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_56 ( V_28 , V_49 , V_57 , V_119 , & V_117 ) ;
if ( V_61 )
goto V_204;
V_61 = F_21 ( V_28 , V_49 , V_178 , V_23 , & V_175 ) ;
if ( V_61 )
goto V_205;
V_61 = F_110 ( V_28 , V_49 , V_178 , V_186 , V_175 ) ;
if ( V_61 )
goto V_206;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_206;
F_113 ( & V_175 -> V_78 ) ;
V_117 -> V_175 = V_175 ;
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
F_60 ( V_28 , V_49 , V_25 , V_57 ) ;
return 0 ;
V_206:
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
V_205:
F_59 ( V_28 , V_49 , V_25 , V_57 ) ;
V_204:
F_52 ( V_28 , V_49 , V_57 , 1 , V_25 , 0 ) ;
return V_61 ;
}
static int F_126 ( struct V_27 * V_28 , int V_49 , int V_173 ,
int V_207 , struct V_77 * * V_58 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_77 * V_175 ;
int V_61 = - V_102 ;
F_22 ( F_23 ( V_28 ) ) ;
F_127 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_110 ( V_28 , V_49 , V_173 , V_207 , V_175 ) ) {
* V_58 = V_175 ;
V_175 -> V_72 . V_67 = V_175 -> V_72 . V_2 ;
V_175 -> V_72 . V_2 = V_8 ;
V_61 = 0 ;
break;
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_61 ;
}
int F_128 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
struct V_208 V_175 ;
T_4 * V_209 = V_143 -> V_179 ;
T_3 * V_210 = ( T_3 * ) V_209 ;
int V_31 ;
struct V_77 * V_211 = NULL ;
int V_173 = F_104 ( V_209 [ 0 ] ) ;
int V_212 = V_141 -> V_148 ;
int V_61 ;
V_61 = F_126 ( V_28 , V_49 , V_173 , V_212 , & V_211 ) ;
if ( V_61 )
return V_61 ;
V_175 . V_213 = 0 ;
V_175 . V_76 = 0 ;
V_175 . V_157 = 0 ;
for ( V_31 = 0 ; V_31 < V_212 ; ++ V_31 )
V_210 [ V_31 + 2 ] = ( F_104 ( V_209 [ V_31 + 2 ] ) & ~ 1ULL ) ;
V_61 = F_129 ( V_28 , & V_175 , F_104 ( V_209 [ 0 ] ) , V_212 ,
( ( T_3 * ) V_209 + 2 ) ) ;
if ( V_211 )
F_28 ( V_28 , V_49 , V_211 -> V_72 . V_57 , V_23 ) ;
return V_61 ;
}
int F_130 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_203 = V_141 -> V_148 ;
int V_57 = V_203 | ( V_49 << 8 ) ;
struct V_82 * V_117 ;
int V_61 ;
V_61 = F_56 ( V_28 , V_49 , V_57 , V_83 , & V_117 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_21 ( V_28 , V_49 , V_117 -> V_175 -> V_72 . V_57 , V_23 , NULL ) ;
if ( V_61 )
goto V_182;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_183;
F_115 ( & V_117 -> V_175 -> V_78 ) ;
F_28 ( V_28 , V_49 , V_117 -> V_175 -> V_72 . V_57 , V_23 ) ;
F_60 ( V_28 , V_49 , V_25 , V_57 ) ;
F_52 ( V_28 , V_49 , V_57 , 1 , V_25 , 0 ) ;
return 0 ;
V_183:
F_28 ( V_28 , V_49 , V_117 -> V_175 -> V_72 . V_57 , V_23 ) ;
V_182:
F_59 ( V_28 , V_49 , V_25 , V_57 ) ;
return V_61 ;
}
int F_131 ( struct V_27 * V_28 , int V_49 , struct V_214 * V_215 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_216 * V_217 ;
struct V_142 * V_218 ;
T_2 V_148 = 0 ;
int V_61 ;
int V_57 ;
struct V_82 * V_219 ;
if ( ! V_30 -> V_33 . V_34 . V_220 )
return - V_102 ;
V_217 = & V_30 -> V_33 . V_34 . V_220 [ V_49 ] . V_217 [ V_215 -> type ] ;
if ( V_217 -> V_203 < 0 )
return 0 ;
F_132 ( & V_30 -> V_33 . V_34 . V_221 [ V_49 ] ) ;
V_57 = ( V_49 << 8 ) | V_217 -> V_203 ;
V_61 = F_21 ( V_28 , V_49 , V_57 , V_25 , & V_219 ) ;
if ( V_61 )
goto V_222;
if ( V_219 -> V_72 . V_67 != V_119 ) {
V_61 = - V_102 ;
goto V_223;
}
V_218 = F_133 ( V_28 ) ;
if ( F_134 ( V_218 ) ) {
V_61 = F_135 ( V_218 ) ;
goto V_223;
}
if ( V_215 -> type == V_224 ) {
++ V_217 -> V_225 ;
V_215 -> V_226 . V_126 . V_225 = F_136 ( V_217 -> V_225 ) ;
}
memcpy ( V_218 -> V_179 , ( T_1 * ) V_215 , 28 ) ;
V_148 = ( V_49 & 0xff ) | ( ( V_217 -> V_203 & 0xff ) << 16 ) ;
V_61 = F_137 ( V_28 , V_218 -> V_227 , V_148 , 0 ,
V_228 , V_229 ,
V_230 ) ;
F_28 ( V_28 , V_49 , V_57 , V_25 ) ;
F_138 ( & V_30 -> V_33 . V_34 . V_221 [ V_49 ] ) ;
F_139 ( V_28 , V_218 ) ;
return V_61 ;
V_223:
F_28 ( V_28 , V_49 , V_57 , V_25 ) ;
V_222:
F_138 ( & V_30 -> V_33 . V_34 . V_221 [ V_49 ] ) ;
return V_61 ;
}
int F_140 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_203 = V_141 -> V_148 ;
int V_57 = V_203 | ( V_49 << 8 ) ;
struct V_82 * V_117 ;
int V_61 ;
V_61 = F_21 ( V_28 , V_49 , V_57 , V_25 , & V_117 ) ;
if ( V_61 )
return V_61 ;
if ( V_117 -> V_72 . V_67 != V_119 ) {
V_61 = - V_102 ;
goto V_183;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_183:
F_28 ( V_28 , V_49 , V_57 , V_25 ) ;
return V_61 ;
}
int F_141 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_120 = V_141 -> V_148 ;
struct V_199 * V_200 = V_143 -> V_179 ;
int V_178 = F_123 ( V_200 ) / V_28 -> V_55 . V_180 ;
struct V_84 * V_122 ;
struct V_77 * V_175 ;
V_61 = F_57 ( V_28 , V_49 , V_120 , V_123 , & V_122 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_21 ( V_28 , V_49 , V_178 , V_23 , & V_175 ) ;
if ( V_61 )
goto V_205;
V_61 = F_110 ( V_28 , V_49 , V_178 , F_124 ( V_200 ) , V_175 ) ;
if ( V_61 )
goto V_206;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_206;
F_113 ( & V_175 -> V_78 ) ;
V_122 -> V_175 = V_175 ;
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
F_60 ( V_28 , V_49 , V_20 , V_120 ) ;
return 0 ;
V_206:
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
V_205:
F_59 ( V_28 , V_49 , V_20 , V_120 ) ;
return V_61 ;
}
int F_142 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_120 = V_141 -> V_148 ;
struct V_84 * V_122 ;
V_61 = F_57 ( V_28 , V_49 , V_120 , V_85 , & V_122 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_205;
F_115 ( & V_122 -> V_175 -> V_78 ) ;
F_60 ( V_28 , V_49 , V_20 , V_120 ) ;
return 0 ;
V_205:
F_59 ( V_28 , V_49 , V_20 , V_120 ) ;
return V_61 ;
}
int F_143 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_120 = V_141 -> V_148 ;
struct V_84 * V_122 ;
int V_61 ;
V_61 = F_21 ( V_28 , V_49 , V_120 , V_20 , & V_122 ) ;
if ( V_61 )
return V_61 ;
if ( V_122 -> V_72 . V_67 != V_123 )
goto V_183;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_183:
F_28 ( V_28 , V_49 , V_120 , V_20 ) ;
return V_61 ;
}
static int F_144 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 ,
struct V_84 * V_122 )
{
int V_61 ;
struct V_77 * V_231 ;
struct V_77 * V_175 ;
struct V_199 * V_200 = V_143 -> V_179 ;
int V_178 = F_123 ( V_200 ) / V_28 -> V_55 . V_180 ;
V_61 = F_21 ( V_28 , V_49 , V_122 -> V_175 -> V_72 . V_57 , V_23 , & V_231 ) ;
if ( V_61 )
return V_61 ;
if ( V_231 != V_122 -> V_175 ) {
V_61 = - V_102 ;
goto V_183;
}
V_61 = F_21 ( V_28 , V_49 , V_178 , V_23 , & V_175 ) ;
if ( V_61 )
goto V_183;
V_61 = F_110 ( V_28 , V_49 , V_178 , F_124 ( V_200 ) , V_175 ) ;
if ( V_61 )
goto V_232;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_232;
F_115 ( & V_231 -> V_78 ) ;
F_28 ( V_28 , V_49 , V_231 -> V_72 . V_57 , V_23 ) ;
F_113 ( & V_175 -> V_78 ) ;
V_122 -> V_175 = V_175 ;
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
return 0 ;
V_232:
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
V_183:
F_28 ( V_28 , V_49 , V_231 -> V_72 . V_57 , V_23 ) ;
return V_61 ;
}
int F_145 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_120 = V_141 -> V_148 ;
struct V_84 * V_122 ;
int V_61 ;
V_61 = F_21 ( V_28 , V_49 , V_120 , V_20 , & V_122 ) ;
if ( V_61 )
return V_61 ;
if ( V_122 -> V_72 . V_67 != V_123 )
goto V_183;
if ( V_141 -> V_147 == 0 ) {
V_61 = F_144 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 , V_122 ) ;
goto V_183;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_183:
F_28 ( V_28 , V_49 , V_120 , V_20 ) ;
return V_61 ;
}
static int F_146 ( struct V_155 * V_156 )
{
int V_233 = ( F_17 ( V_156 -> V_234 ) >> 24 ) & 0xf ;
int V_164 = V_156 -> V_235 & 7 ;
int V_157 = ( V_156 -> V_158 & 0x3f ) + 12 ;
if ( V_233 + V_164 + 4 < V_157 )
return 1 ;
return 1 << ( V_233 + V_164 + 4 - V_157 ) ;
}
int F_147 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_133 = V_141 -> V_148 ;
struct V_77 * V_175 ;
struct V_86 * V_124 ;
struct V_155 * V_156 = V_143 -> V_179 ;
int V_178 = F_107 ( V_156 ) / V_28 -> V_55 . V_180 ;
if ( V_133 != ( F_17 ( V_156 -> V_234 ) & 0xffffff ) )
return - V_102 ;
V_61 = F_58 ( V_28 , V_49 , V_133 , V_13 , & V_124 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_21 ( V_28 , V_49 , V_178 , V_23 , & V_175 ) ;
if ( V_61 )
goto V_182;
V_61 = F_110 ( V_28 , V_49 , V_178 , F_146 ( V_156 ) ,
V_175 ) ;
if ( V_61 )
goto V_192;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_192;
F_113 ( & V_175 -> V_78 ) ;
V_124 -> V_175 = V_175 ;
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
F_60 ( V_28 , V_49 , V_21 , V_133 ) ;
return 0 ;
V_192:
F_28 ( V_28 , V_49 , V_175 -> V_72 . V_57 , V_23 ) ;
V_182:
F_59 ( V_28 , V_49 , V_21 , V_133 ) ;
return V_61 ;
}
int F_148 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_133 = V_141 -> V_148 ;
struct V_86 * V_124 ;
V_61 = F_58 ( V_28 , V_49 , V_133 , V_12 , & V_124 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_182;
F_115 ( & V_124 -> V_175 -> V_78 ) ;
if ( V_124 -> V_122 )
F_115 ( & V_124 -> V_122 -> V_78 ) ;
F_60 ( V_28 , V_49 , V_21 , V_133 ) ;
return 0 ;
V_182:
F_59 ( V_28 , V_49 , V_21 , V_133 ) ;
return V_61 ;
}
int F_149 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_133 = V_141 -> V_148 ;
struct V_86 * V_124 ;
V_61 = F_21 ( V_28 , V_49 , V_133 , V_21 , & V_124 ) ;
if ( V_61 )
return V_61 ;
if ( V_124 -> V_72 . V_67 != V_13 ) {
V_61 = - V_64 ;
goto V_106;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_106:
F_28 ( V_28 , V_49 , V_133 , V_21 ) ;
return V_61 ;
}
int F_150 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_133 = V_141 -> V_148 ;
struct V_86 * V_124 ;
V_61 = F_21 ( V_28 , V_49 , V_133 , V_21 , & V_124 ) ;
if ( V_61 )
return V_61 ;
if ( V_124 -> V_72 . V_67 != V_13 ) {
V_61 = - V_64 ;
goto V_106;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_106:
F_28 ( V_28 , V_49 , V_133 , V_21 ) ;
return V_61 ;
}
int F_151 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_107 = V_141 -> V_148 & 0x7fffff ;
struct V_70 * V_108 ;
V_61 = F_21 ( V_28 , V_49 , V_107 , V_19 , & V_108 ) ;
if ( V_61 )
return V_61 ;
if ( V_108 -> V_72 . V_67 != V_6 ) {
V_61 = - V_64 ;
goto V_106;
}
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
V_106:
F_28 ( V_28 , V_49 , V_107 , V_19 ) ;
return V_61 ;
}
int F_152 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
struct V_47 * V_153 = V_143 -> V_179 + 8 ;
F_16 ( V_28 , V_153 , ( T_1 ) V_49 ) ;
return F_151 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
}
int F_153 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_107 = V_141 -> V_148 & 0x7fffff ;
struct V_70 * V_108 ;
V_61 = F_54 ( V_28 , V_49 , V_107 , V_5 , & V_108 , 0 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
if ( V_61 )
goto V_182;
F_115 ( & V_108 -> V_175 -> V_78 ) ;
F_115 ( & V_108 -> V_187 -> V_78 ) ;
F_115 ( & V_108 -> V_188 -> V_78 ) ;
if ( V_108 -> V_124 )
F_115 ( & V_108 -> V_124 -> V_78 ) ;
F_60 ( V_28 , V_49 , V_19 , V_107 ) ;
return 0 ;
V_182:
F_59 ( V_28 , V_49 , V_19 , V_107 ) ;
return V_61 ;
}
static struct V_236 * F_154 ( struct V_27 * V_28 , int V_49 ,
struct V_70 * V_237 , T_1 * V_238 )
{
struct V_236 * V_58 ;
F_127 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_58 -> V_238 , V_238 , 16 ) )
return V_58 ;
}
return NULL ;
}
static int F_155 ( struct V_27 * V_28 , int V_49 , struct V_70 * V_237 ,
T_1 * V_238 , enum V_239 V_240 ,
enum V_241 V_242 )
{
struct V_236 * V_58 ;
int V_61 ;
V_58 = F_7 ( sizeof *V_58 , V_38 ) ;
if ( ! V_58 )
return - V_39 ;
F_22 ( & V_237 -> V_75 ) ;
if ( F_154 ( V_28 , V_49 , V_237 , V_238 ) ) {
F_15 ( V_58 ) ;
V_61 = - V_97 ;
} else {
memcpy ( V_58 -> V_238 , V_238 , 16 ) ;
V_58 -> V_240 = V_240 ;
V_58 -> V_242 = V_242 ;
F_41 ( & V_58 -> V_99 , & V_237 -> V_74 ) ;
V_61 = 0 ;
}
F_24 ( & V_237 -> V_75 ) ;
return V_61 ;
}
static int F_156 ( struct V_27 * V_28 , int V_49 , struct V_70 * V_237 ,
T_1 * V_238 , enum V_239 V_240 ,
enum V_241 V_242 )
{
struct V_236 * V_58 ;
int V_61 ;
F_22 ( & V_237 -> V_75 ) ;
V_58 = F_154 ( V_28 , V_49 , V_237 , V_238 ) ;
if ( ! V_58 || V_58 -> V_240 != V_240 || V_58 -> V_242 != V_242 )
V_61 = - V_102 ;
else {
F_53 ( & V_58 -> V_99 ) ;
F_15 ( V_58 ) ;
V_61 = 0 ;
}
F_24 ( & V_237 -> V_75 ) ;
return V_61 ;
}
int F_157 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
struct V_243 V_108 ;
T_1 * V_238 = V_143 -> V_179 ;
enum V_239 V_240 = ( V_141 -> V_148 >> 28 ) & 0x7 ;
int V_61 , V_244 ;
int V_107 ;
struct V_70 * V_237 ;
int V_245 = V_141 -> V_147 ;
int V_246 = V_141 -> V_148 >> 31 ;
T_1 V_247 = 2 ;
enum V_241 type = ( V_238 [ 7 ] & V_247 ) >> 1 ;
V_107 = V_141 -> V_148 & 0xffffff ;
V_61 = F_21 ( V_28 , V_49 , V_107 , V_19 , & V_237 ) ;
if ( V_61 )
return V_61 ;
V_108 . V_107 = V_107 ;
if ( V_245 ) {
V_61 = F_155 ( V_28 , V_49 , V_237 , V_238 , V_240 , type ) ;
if ( V_61 )
goto V_183;
V_61 = F_158 ( V_28 , & V_108 , V_238 ,
V_246 , V_240 , type ) ;
if ( V_61 )
goto V_248;
} else {
V_61 = F_156 ( V_28 , V_49 , V_237 , V_238 , V_240 , type ) ;
if ( V_61 )
goto V_183;
V_61 = F_159 ( V_28 , & V_108 , V_238 , V_240 , type ) ;
}
F_28 ( V_28 , V_49 , V_107 , V_19 ) ;
return 0 ;
V_248:
V_244 = F_156 ( V_28 , V_49 , V_237 , V_238 , V_240 , type ) ;
V_183:
F_28 ( V_28 , V_49 , V_107 , V_19 ) ;
return V_61 ;
}
int F_160 ( struct V_27 * V_28 , int V_49 ,
struct V_140 * V_141 ,
struct V_142 * V_143 ,
struct V_142 * V_144 ,
struct V_145 * V_126 )
{
int V_61 ;
int V_111 = V_141 -> V_148 & 0xffff ;
V_61 = F_21 ( V_28 , V_49 , V_111 , V_26 , NULL ) ;
if ( V_61 )
return V_61 ;
V_61 = F_112 ( V_28 , V_49 , V_141 , V_143 , V_144 , V_126 ) ;
F_28 ( V_28 , V_49 , V_111 , V_26 ) ;
return V_61 ;
}
static void F_161 ( struct V_27 * V_28 , int V_49 , struct V_70 * V_237 )
{
struct V_236 * V_249 ;
struct V_236 * V_139 ;
int V_61 ;
struct V_243 V_108 ;
F_85 (rgid, tmp, &rqp->mcg_list, list) {
V_108 . V_107 = V_237 -> V_73 ;
V_61 = F_159 ( V_28 , & V_108 , V_249 -> V_238 , V_249 -> V_240 ,
V_249 -> V_242 ) ;
F_53 ( & V_249 -> V_99 ) ;
F_15 ( V_249 ) ;
}
}
static int F_162 ( struct V_27 * V_28 , int V_49 ,
enum V_17 type , int V_250 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 =
& V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_251 = & V_94 -> V_36 [ V_49 ] . V_41 [ type ] ;
struct V_59 * V_60 ;
struct V_59 * V_139 ;
int V_252 ;
V_252 = 0 ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (r, tmp, rlist, list) {
if ( V_60 -> V_65 == V_49 ) {
if ( ! V_60 -> V_253 ) {
if ( V_60 -> V_2 == V_63 ) {
if ( V_250 )
F_10 ( V_28 ,
L_29 ,
F_5 ( type ) ,
V_60 -> V_57 ) ;
++ V_252 ;
} else {
V_60 -> V_67 = V_60 -> V_2 ;
V_60 -> V_2 = V_63 ;
V_60 -> V_253 = 1 ;
}
}
}
}
F_24 ( F_23 ( V_28 ) ) ;
return V_252 ;
}
static int F_163 ( struct V_27 * V_28 , int V_49 ,
enum V_17 type )
{
unsigned long V_254 ;
int V_252 ;
V_254 = V_255 ;
do {
V_252 = F_162 ( V_28 , V_49 , type , 0 ) ;
if ( F_164 ( V_255 , V_254 + 5 * V_256 ) )
break;
if ( V_252 )
F_165 () ;
} while ( V_252 );
if ( V_252 )
V_252 = F_162 ( V_28 , V_49 , type , 1 ) ;
return V_252 ;
}
static void F_166 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_257 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_19 ] ;
struct V_70 * V_108 ;
struct V_70 * V_139 ;
int V_2 ;
T_3 V_127 ;
int V_107 ;
int V_61 ;
V_61 = F_163 ( V_28 , V_49 , V_19 ) ;
if ( V_61 )
F_167 ( V_28 , L_30
L_31 , V_49 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (qp, tmp, qp_list, com.list) {
F_24 ( F_23 ( V_28 ) ) ;
if ( V_108 -> V_72 . V_65 == V_49 ) {
V_107 = V_108 -> V_72 . V_57 ;
F_161 ( V_28 , V_49 , V_108 ) ;
V_2 = V_108 -> V_72 . V_67 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_22 ( F_23 ( V_28 ) ) ;
F_42 ( & V_94 -> V_43 [ V_19 ] ,
V_108 -> V_72 . V_57 ) ;
F_53 ( & V_108 -> V_72 . V_99 ) ;
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_108 ) ;
V_2 = 0 ;
break;
case V_5 :
if ( ! F_61 ( V_28 , V_49 , V_107 ) )
F_93 ( V_28 , V_107 ) ;
V_2 = V_4 ;
break;
case V_6 :
V_127 = V_49 ;
V_61 = F_137 ( V_28 , V_127 ,
V_108 -> V_73 , 2 ,
V_258 ,
V_259 ,
V_230 ) ;
if ( V_61 )
F_10 ( V_28 , L_32
L_33
L_34 , V_49 ,
V_108 -> V_73 ) ;
F_115 ( & V_108 -> V_187 -> V_78 ) ;
F_115 ( & V_108 -> V_188 -> V_78 ) ;
F_115 ( & V_108 -> V_175 -> V_78 ) ;
if ( V_108 -> V_124 )
F_115 ( & V_108 -> V_124 -> V_78 ) ;
V_2 = V_5 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_28 ) ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
}
static void F_168 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_260 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_21 ] ;
struct V_86 * V_124 ;
struct V_86 * V_139 ;
int V_2 ;
T_3 V_127 ;
F_169 ( V_261 ) ;
int V_133 ;
int V_61 ;
V_61 = F_163 ( V_28 , V_49 , V_21 ) ;
if ( V_61 )
F_167 ( V_28 , L_35
L_36 , V_49 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (srq, tmp, srq_list, com.list) {
F_24 ( F_23 ( V_28 ) ) ;
if ( V_124 -> V_72 . V_65 == V_49 ) {
V_133 = V_124 -> V_72 . V_57 ;
V_2 = V_124 -> V_72 . V_67 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_12 :
F_82 ( V_28 , V_133 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_42 ( & V_94 -> V_43 [ V_21 ] ,
V_133 ) ;
F_53 ( & V_124 -> V_72 . V_99 ) ;
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_124 ) ;
V_2 = 0 ;
break;
case V_13 :
V_127 = V_49 ;
V_61 = F_137 ( V_28 , V_127 , V_133 , 1 ,
V_262 ,
V_259 ,
V_230 ) ;
if ( V_61 )
F_10 ( V_28 , L_37
L_38
L_39 ,
V_49 , V_133 ) ;
F_115 ( & V_124 -> V_175 -> V_78 ) ;
if ( V_124 -> V_122 )
F_115 ( & V_124 -> V_122 -> V_78 ) ;
V_2 = V_12 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_28 ) ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
}
static void F_170 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_263 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_20 ] ;
struct V_84 * V_122 ;
struct V_84 * V_139 ;
int V_2 ;
T_3 V_127 ;
F_169 ( V_261 ) ;
int V_120 ;
int V_61 ;
V_61 = F_163 ( V_28 , V_49 , V_20 ) ;
if ( V_61 )
F_167 ( V_28 , L_40
L_36 , V_49 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (cq, tmp, cq_list, com.list) {
F_24 ( F_23 ( V_28 ) ) ;
if ( V_122 -> V_72 . V_65 == V_49 && ! F_45 ( & V_122 -> V_78 ) ) {
V_120 = V_122 -> V_72 . V_57 ;
V_2 = V_122 -> V_72 . V_67 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_85 :
F_79 ( V_28 , V_120 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_42 ( & V_94 -> V_43 [ V_20 ] ,
V_120 ) ;
F_53 ( & V_122 -> V_72 . V_99 ) ;
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_122 ) ;
V_2 = 0 ;
break;
case V_123 :
V_127 = V_49 ;
V_61 = F_137 ( V_28 , V_127 , V_120 , 1 ,
V_264 ,
V_259 ,
V_230 ) ;
if ( V_61 )
F_10 ( V_28 , L_41
L_42
L_39 ,
V_49 , V_120 ) ;
F_115 ( & V_122 -> V_175 -> V_78 ) ;
V_2 = V_85 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_28 ) ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
}
static void F_171 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_265 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_22 ] ;
struct V_80 * V_113 ;
struct V_80 * V_139 ;
int V_2 ;
T_3 V_127 ;
F_169 ( V_261 ) ;
int V_266 ;
int V_61 ;
V_61 = F_163 ( V_28 , V_49 , V_22 ) ;
if ( V_61 )
F_167 ( V_28 , L_43
L_36 , V_49 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (mpt, tmp, mpt_list, com.list) {
F_24 ( F_23 ( V_28 ) ) ;
if ( V_113 -> V_72 . V_65 == V_49 ) {
V_266 = V_113 -> V_72 . V_57 ;
V_2 = V_113 -> V_72 . V_67 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_81 :
F_75 ( V_28 , V_113 -> V_79 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_42 ( & V_94 -> V_43 [ V_22 ] ,
V_266 ) ;
F_53 ( & V_113 -> V_72 . V_99 ) ;
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_113 ) ;
V_2 = 0 ;
break;
case V_114 :
F_96 ( V_28 , V_113 -> V_79 ) ;
V_2 = V_81 ;
break;
case V_115 :
V_127 = V_49 ;
V_61 = F_137 ( V_28 , V_127 , V_266 , 0 ,
V_267 ,
V_259 ,
V_230 ) ;
if ( V_61 )
F_10 ( V_28 , L_44
L_45
L_39 ,
V_49 , V_266 ) ;
if ( V_113 -> V_175 )
F_115 ( & V_113 -> V_175 -> V_78 ) ;
V_2 = V_114 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_28 ) ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
}
static void F_172 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 =
& V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_268 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_23 ] ;
struct V_77 * V_175 ;
struct V_77 * V_139 ;
int V_2 ;
F_169 ( V_261 ) ;
int V_90 ;
int V_61 ;
V_61 = F_163 ( V_28 , V_49 , V_23 ) ;
if ( V_61 )
F_167 ( V_28 , L_46
L_36 , V_49 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (mtt, tmp, mtt_list, com.list) {
F_24 ( F_23 ( V_28 ) ) ;
if ( V_175 -> V_72 . V_65 == V_49 ) {
V_90 = V_175 -> V_72 . V_57 ;
V_2 = V_175 -> V_72 . V_67 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_9 :
F_72 ( V_28 , V_90 ,
V_175 -> V_76 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_42 ( & V_94 -> V_43 [ V_23 ] ,
V_90 ) ;
F_53 ( & V_175 -> V_72 . V_99 ) ;
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_175 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_28 ) ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
}
static void F_173 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
struct V_93 * V_94 = & V_30 -> V_33 . V_34 . V_35 ;
struct V_137 * V_269 =
& V_94 -> V_36 [ V_49 ] . V_41 [ V_25 ] ;
struct V_82 * V_117 ;
struct V_82 * V_139 ;
int V_61 ;
int V_2 ;
F_169 ( V_261 ) ;
int V_203 ;
struct V_142 * V_218 ;
V_61 = F_163 ( V_28 , V_49 , V_25 ) ;
if ( V_61 )
F_167 ( V_28 , L_47
L_36 , V_49 ) ;
F_22 ( F_23 ( V_28 ) ) ;
F_85 (eq, tmp, eq_list, com.list) {
F_24 ( F_23 ( V_28 ) ) ;
if ( V_117 -> V_72 . V_65 == V_49 ) {
V_203 = V_117 -> V_72 . V_57 ;
V_2 = V_117 -> V_72 . V_67 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_83 :
F_22 ( F_23 ( V_28 ) ) ;
F_42 ( & V_94 -> V_43 [ V_25 ] ,
V_203 ) ;
F_53 ( & V_117 -> V_72 . V_99 ) ;
F_24 ( F_23 ( V_28 ) ) ;
F_15 ( V_117 ) ;
V_2 = 0 ;
break;
case V_119 :
V_218 = F_133 ( V_28 ) ;
if ( F_134 ( V_218 ) ) {
F_165 () ;
continue;
}
V_61 = F_174 ( V_28 , V_49 , 0 ,
V_203 & 0xff , 0 ,
V_270 ,
V_259 ,
V_230 ) ;
F_10 ( V_28 , L_48
L_49
L_39 , V_49 , V_203 ) ;
F_139 ( V_28 , V_218 ) ;
if ( ! V_61 ) {
F_115 ( & V_117 -> V_175 -> V_78 ) ;
V_2 = V_83 ;
}
break;
default:
V_2 = 0 ;
}
}
}
F_22 ( F_23 ( V_28 ) ) ;
}
F_24 ( F_23 ( V_28 ) ) ;
}
void F_14 ( struct V_27 * V_28 , int V_49 )
{
struct V_29 * V_30 = V_29 ( V_28 ) ;
F_132 ( & V_30 -> V_33 . V_34 . V_35 . V_36 [ V_49 ] . V_42 ) ;
F_86 ( V_28 , V_49 ) ;
F_166 ( V_28 , V_49 ) ;
F_168 ( V_28 , V_49 ) ;
F_170 ( V_28 , V_49 ) ;
F_171 ( V_28 , V_49 ) ;
F_173 ( V_28 , V_49 ) ;
F_172 ( V_28 , V_49 ) ;
F_138 ( & V_30 -> V_33 . V_34 . V_35 . V_36 [ V_49 ] . V_42 ) ;
}
