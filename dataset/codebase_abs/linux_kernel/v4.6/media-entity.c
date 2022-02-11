static inline const char * F_1 ( enum V_1 type )
{
switch ( type ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
default:
return L_5 ;
}
}
static inline const char * F_2 ( struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_8 :
return L_6 ;
case V_9 :
return L_7 ;
case V_10 :
return L_8 ;
case V_11 :
return L_9 ;
case V_12 :
return L_10 ;
case V_13 :
return L_11 ;
case V_14 :
return L_12 ;
case V_15 :
return L_13 ;
case V_16 :
return L_14 ;
case V_17 :
return L_15 ;
case V_18 :
return L_16 ;
case V_19 :
return L_17 ;
case V_20 :
return L_18 ;
case V_21 :
return L_19 ;
case V_22 :
return L_20 ;
case V_23 :
return L_21 ;
case V_24 :
return L_22 ;
case V_25 :
return L_23 ;
default:
return L_24 ;
}
}
T_1 int F_3 ( struct V_26 * V_27 ,
int V_28 )
{
V_28 = F_4 ( V_28 , V_29 ) ;
V_27 -> V_30 = F_5 ( V_28 / V_29 , sizeof( long ) ,
V_31 ) ;
if ( ! V_27 -> V_30 )
return - V_32 ;
F_6 ( V_27 -> V_30 , V_28 ) ;
V_27 -> V_28 = V_28 ;
return 0 ;
}
void F_7 ( struct V_26 * V_27 )
{
F_8 ( V_27 -> V_30 ) ;
}
static void F_9 ( const char * V_33 , struct V_34 * V_35 )
{
#if F_10 ( V_36 ) || F_10 ( V_37 )
switch ( F_11 ( V_35 ) ) {
case V_2 :
F_12 ( V_35 -> V_38 -> V_39 ,
L_25 ,
V_33 , F_13 ( V_35 ) ,
F_14 ( V_35 ) -> V_40 ) ;
break;
case V_4 :
{
struct V_41 * V_42 = F_15 ( V_35 ) ;
F_12 ( V_35 -> V_38 -> V_39 ,
L_26 ,
V_33 , F_13 ( V_35 ) ,
F_11 ( V_42 -> V_43 ) == V_3 ?
L_27 : L_28 ,
F_13 ( V_42 -> V_43 ) ,
F_13 ( V_42 -> V_44 ) ) ;
break;
}
case V_3 :
{
struct V_45 * V_46 = F_16 ( V_35 ) ;
F_12 ( V_35 -> V_38 -> V_39 ,
L_29 ,
V_33 , F_13 ( V_35 ) ,
V_46 -> V_47 & V_48 ? L_30 : L_31 ,
V_46 -> V_47 & V_49 ? L_32 : L_31 ,
V_46 -> V_50 -> V_40 , V_46 -> V_51 ) ;
break;
}
case V_5 :
{
struct V_6 * V_7 = F_17 ( V_35 ) ;
struct V_52 * V_53 = F_18 ( V_7 ) ;
F_12 ( V_35 -> V_38 -> V_39 ,
L_33 ,
V_33 , F_13 ( V_35 ) ,
F_2 ( V_7 ) ,
V_53 -> V_54 , V_53 -> V_55 ) ;
break;
}
}
#endif
}
void F_19 ( struct V_56 * V_38 ,
enum V_1 type ,
struct V_34 * V_35 )
{
F_20 ( ! V_38 ) ;
V_35 -> V_38 = V_38 ;
V_35 -> V_57 = F_21 ( type , ++ V_38 -> V_57 ) ;
switch ( type ) {
case V_2 :
F_22 ( & V_35 -> V_58 , & V_38 -> V_59 ) ;
break;
case V_3 :
F_22 ( & V_35 -> V_58 , & V_38 -> V_60 ) ;
break;
case V_4 :
F_22 ( & V_35 -> V_58 , & V_38 -> V_61 ) ;
break;
case V_5 :
F_22 ( & V_35 -> V_58 , & V_38 -> V_62 ) ;
break;
}
V_38 -> V_63 ++ ;
F_9 ( V_64 , V_35 ) ;
}
void F_23 ( struct V_34 * V_35 )
{
F_9 ( V_64 , V_35 ) ;
V_35 -> V_38 -> V_63 ++ ;
F_24 ( & V_35 -> V_58 ) ;
}
int F_25 ( struct V_65 * V_50 , T_2 V_66 ,
struct V_45 * V_60 )
{
struct V_56 * V_38 = V_50 -> V_67 . V_38 ;
unsigned int V_68 ;
V_50 -> V_66 = V_66 ;
V_50 -> V_60 = V_60 ;
if ( V_38 )
F_26 ( & V_38 -> V_69 ) ;
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ ) {
V_60 [ V_68 ] . V_50 = V_50 ;
V_60 [ V_68 ] . V_51 = V_68 ;
if ( V_38 )
F_19 ( V_38 , V_3 ,
& V_50 -> V_60 [ V_68 ] . V_67 ) ;
}
if ( V_38 )
F_27 ( & V_38 -> V_69 ) ;
return 0 ;
}
static struct V_65 *
F_28 ( struct V_65 * V_50 , struct V_41 * V_42 )
{
if ( V_42 -> V_70 -> V_50 == V_50 )
return V_42 -> V_71 -> V_50 ;
else
return V_42 -> V_70 -> V_50 ;
}
static void F_29 ( struct V_72 * V_73 ,
struct V_65 * V_50 )
{
if ( V_73 -> V_74 == V_75 - 1 ) {
F_30 ( 1 ) ;
return;
}
V_73 -> V_74 ++ ;
V_73 -> V_76 [ V_73 -> V_74 ] . V_42 = V_50 -> V_61 . V_77 ;
V_73 -> V_76 [ V_73 -> V_74 ] . V_50 = V_50 ;
}
static struct V_65 * F_31 ( struct V_72 * V_73 )
{
struct V_65 * V_50 ;
V_50 = V_73 -> V_76 [ V_73 -> V_74 ] . V_50 ;
V_73 -> V_74 -- ;
return V_50 ;
}
T_1 int F_32 (
struct V_72 * V_73 , struct V_56 * V_38 )
{
return F_33 ( & V_73 -> V_27 , V_38 ) ;
}
void F_34 ( struct V_72 * V_73 )
{
F_7 ( & V_73 -> V_27 ) ;
}
void F_35 ( struct V_72 * V_73 ,
struct V_65 * V_50 )
{
F_36 ( & V_73 -> V_27 ) ;
F_37 ( & V_73 -> V_27 , V_50 ) ;
V_73 -> V_74 = 0 ;
V_73 -> V_76 [ V_73 -> V_74 ] . V_50 = NULL ;
F_29 ( V_73 , V_50 ) ;
}
struct V_65 *
F_38 ( struct V_72 * V_73 )
{
if ( F_39 ( V_73 ) == NULL )
return NULL ;
while ( F_40 ( V_73 ) != & F_39 ( V_73 ) -> V_61 ) {
struct V_65 * V_50 = F_39 ( V_73 ) ;
struct V_41 * V_42 ;
struct V_65 * V_77 ;
V_42 = F_41 ( F_40 ( V_73 ) , F_42 ( * V_42 ) , V_58 ) ;
if ( ! ( V_42 -> V_47 & V_78 ) ) {
F_40 ( V_73 ) = F_40 ( V_73 ) -> V_77 ;
continue;
}
V_77 = F_28 ( V_50 , V_42 ) ;
if ( F_43 ( & V_73 -> V_27 , V_77 ) ) {
F_40 ( V_73 ) = F_40 ( V_73 ) -> V_77 ;
continue;
}
F_40 ( V_73 ) = F_40 ( V_73 ) -> V_77 ;
F_29 ( V_73 , V_77 ) ;
}
return F_31 ( V_73 ) ;
}
T_1 int F_44 ( struct V_65 * V_50 ,
struct V_79 * V_80 )
{
struct V_56 * V_38 = V_50 -> V_67 . V_38 ;
struct V_72 * V_73 = & V_80 -> V_73 ;
struct V_65 * V_81 = V_50 ;
struct V_41 * V_42 ;
int V_82 ;
if ( ! V_80 -> V_83 ++ ) {
V_82 = F_32 ( & V_80 -> V_73 , V_38 ) ;
if ( V_82 )
goto V_84;
}
F_35 ( & V_80 -> V_73 , V_50 ) ;
while ( ( V_50 = F_38 ( V_73 ) ) ) {
F_45 ( V_85 , V_86 ) ;
F_45 ( V_87 , V_86 ) ;
V_50 -> V_88 ++ ;
if ( F_30 ( V_50 -> V_80 && V_50 -> V_80 != V_80 ) ) {
V_82 = - V_89 ;
goto error;
}
V_50 -> V_80 = V_80 ;
if ( V_50 -> V_88 > 1 )
continue;
if ( ! V_50 -> V_90 || ! V_50 -> V_90 -> V_91 )
continue;
F_6 ( V_85 , V_50 -> V_66 ) ;
F_46 ( V_87 , V_50 -> V_66 ) ;
F_47 (link, &entity->links, list) {
struct V_45 * V_46 = V_42 -> V_71 -> V_50 == V_50
? V_42 -> V_71 : V_42 -> V_70 ;
F_48 ( V_87 , V_46 -> V_51 , 1 ) ;
if ( ! ( V_46 -> V_47 & V_92 ) ||
V_42 -> V_47 & V_78 )
F_49 ( V_85 , V_46 -> V_51 , 1 ) ;
if ( V_42 -> V_71 != V_46 ||
! ( V_42 -> V_47 & V_78 ) )
continue;
V_82 = V_50 -> V_90 -> V_91 ( V_42 ) ;
if ( V_82 < 0 && V_82 != - V_93 ) {
F_12 ( V_50 -> V_67 . V_38 -> V_39 ,
L_34 ,
V_42 -> V_70 -> V_50 -> V_40 ,
V_42 -> V_70 -> V_51 ,
V_50 -> V_40 , V_42 -> V_71 -> V_51 , V_82 ) ;
goto error;
}
}
F_50 ( V_85 , V_85 , V_87 , V_50 -> V_66 ) ;
if ( ! F_51 ( V_85 , V_50 -> V_66 ) ) {
V_82 = - V_94 ;
F_12 ( V_50 -> V_67 . V_38 -> V_39 ,
L_35 ,
V_50 -> V_40 ,
( unsigned ) F_52 (
V_85 , V_50 -> V_66 ) ) ;
goto error;
}
}
return 0 ;
error:
F_35 ( V_73 , V_81 ) ;
while ( ( V_81 = F_38 ( V_73 ) ) ) {
if ( V_50 -> V_88 > 0 ) {
V_81 -> V_88 -- ;
if ( V_81 -> V_88 == 0 )
V_81 -> V_80 = NULL ;
}
if ( V_81 == V_50 )
break;
}
V_84:
if ( ! -- V_80 -> V_83 )
F_34 ( V_73 ) ;
return V_82 ;
}
T_1 int F_53 ( struct V_65 * V_50 ,
struct V_79 * V_80 )
{
struct V_56 * V_38 = V_50 -> V_67 . V_38 ;
int V_82 ;
F_54 ( & V_38 -> V_95 ) ;
V_82 = F_44 ( V_50 , V_80 ) ;
F_55 ( & V_38 -> V_95 ) ;
return V_82 ;
}
void F_56 ( struct V_65 * V_50 )
{
struct V_72 * V_73 = & V_50 -> V_80 -> V_73 ;
struct V_79 * V_80 = V_50 -> V_80 ;
F_30 ( ! V_80 -> V_83 ) ;
F_35 ( V_73 , V_50 ) ;
while ( ( V_50 = F_38 ( V_73 ) ) ) {
if ( V_50 -> V_88 > 0 ) {
V_50 -> V_88 -- ;
if ( V_50 -> V_88 == 0 )
V_50 -> V_80 = NULL ;
}
}
if ( ! -- V_80 -> V_83 )
F_34 ( V_73 ) ;
}
void F_57 ( struct V_65 * V_50 )
{
struct V_56 * V_38 = V_50 -> V_67 . V_38 ;
F_54 ( & V_38 -> V_95 ) ;
F_56 ( V_50 ) ;
F_55 ( & V_38 -> V_95 ) ;
}
struct V_65 * F_58 ( struct V_65 * V_50 )
{
if ( V_50 == NULL )
return NULL ;
if ( V_50 -> V_67 . V_38 -> V_39 &&
! F_59 ( V_50 -> V_67 . V_38 -> V_39 -> V_96 -> V_97 ) )
return NULL ;
return V_50 ;
}
void F_60 ( struct V_65 * V_50 )
{
if ( V_50 == NULL )
return;
if ( V_50 -> V_67 . V_38 -> V_39 )
F_61 ( V_50 -> V_67 . V_38 -> V_39 -> V_96 -> V_97 ) ;
}
static struct V_41 * F_62 ( struct V_98 * V_99 )
{
struct V_41 * V_42 ;
V_42 = F_63 ( sizeof( * V_42 ) , V_31 ) ;
if ( V_42 == NULL )
return NULL ;
F_22 ( & V_42 -> V_58 , V_99 ) ;
return V_42 ;
}
static void F_64 ( struct V_65 * V_50 ,
struct V_41 * V_42 )
{
struct V_41 * V_100 , * V_101 ;
struct V_65 * V_102 ;
if ( V_42 -> V_70 -> V_50 == V_50 )
V_102 = V_42 -> V_71 -> V_50 ;
else
V_102 = V_42 -> V_70 -> V_50 ;
F_65 (rlink, tmp, &remote->links, list) {
if ( V_100 != V_42 -> V_103 )
continue;
if ( V_42 -> V_70 -> V_50 == V_50 )
V_102 -> V_104 -- ;
F_24 ( & V_100 -> V_58 ) ;
F_23 ( & V_100 -> V_67 ) ;
F_8 ( V_100 ) ;
if ( -- V_102 -> V_105 == 0 )
break;
}
F_24 ( & V_42 -> V_58 ) ;
F_23 ( & V_42 -> V_67 ) ;
F_8 ( V_42 ) ;
}
int
F_66 ( struct V_65 * V_70 , T_2 V_106 ,
struct V_65 * V_71 , T_2 V_107 , T_3 V_47 )
{
struct V_41 * V_42 ;
struct V_41 * V_108 ;
F_20 ( V_70 == NULL || V_71 == NULL ) ;
F_20 ( V_106 >= V_70 -> V_66 ) ;
F_20 ( V_107 >= V_71 -> V_66 ) ;
V_42 = F_62 ( & V_70 -> V_61 ) ;
if ( V_42 == NULL )
return - V_32 ;
V_42 -> V_70 = & V_70 -> V_60 [ V_106 ] ;
V_42 -> V_71 = & V_71 -> V_60 [ V_107 ] ;
V_42 -> V_47 = V_47 & ~ V_109 ;
F_19 ( V_70 -> V_67 . V_38 , V_4 ,
& V_42 -> V_67 ) ;
V_108 = F_62 ( & V_71 -> V_61 ) ;
if ( V_108 == NULL ) {
F_64 ( V_70 , V_42 ) ;
return - V_32 ;
}
V_108 -> V_70 = & V_70 -> V_60 [ V_106 ] ;
V_108 -> V_71 = & V_71 -> V_60 [ V_107 ] ;
V_108 -> V_47 = V_47 ;
V_108 -> V_110 = true ;
F_19 ( V_71 -> V_67 . V_38 , V_4 ,
& V_108 -> V_67 ) ;
V_42 -> V_103 = V_108 ;
V_108 -> V_103 = V_42 ;
V_71 -> V_104 ++ ;
V_71 -> V_105 ++ ;
V_70 -> V_105 ++ ;
return 0 ;
}
int F_67 ( const struct V_56 * V_38 ,
const T_3 V_111 ,
struct V_65 * V_70 ,
const T_2 V_106 ,
const T_3 V_112 ,
struct V_65 * V_71 ,
const T_2 V_107 ,
T_3 V_47 ,
const bool V_113 )
{
struct V_65 * V_50 ;
unsigned V_114 ;
int V_82 ;
if ( V_70 && V_71 )
return F_66 ( V_70 , V_106 ,
V_71 , V_107 , V_47 ) ;
if ( ! V_70 && ! V_71 ) {
if ( ! V_113 )
return 0 ;
F_68 (source, mdev) {
if ( V_70 -> V_114 != V_111 )
continue;
F_68 (sink, mdev) {
if ( V_71 -> V_114 != V_112 )
continue;
V_82 = F_66 ( V_70 , V_106 ,
V_71 , V_107 ,
V_47 ) ;
if ( V_82 )
return V_82 ;
V_47 &= ~ ( V_78 |
V_115 ) ;
}
}
return 0 ;
}
if ( V_70 )
V_114 = V_112 ;
else
V_114 = V_111 ;
F_68 (entity, mdev) {
if ( V_50 -> V_114 != V_114 )
continue;
if ( V_70 )
V_82 = F_66 ( V_70 , V_106 ,
V_50 , V_107 , V_47 ) ;
else
V_82 = F_66 ( V_50 , V_106 ,
V_71 , V_107 , V_47 ) ;
if ( V_82 )
return V_82 ;
V_47 &= ~ ( V_78 | V_115 ) ;
}
return 0 ;
}
void F_69 ( struct V_65 * V_50 )
{
struct V_41 * V_42 , * V_101 ;
F_65 (link, tmp, &entity->links, list)
F_64 ( V_50 , V_42 ) ;
V_50 -> V_105 = 0 ;
V_50 -> V_104 = 0 ;
}
void F_70 ( struct V_65 * V_50 )
{
struct V_56 * V_38 = V_50 -> V_67 . V_38 ;
if ( V_38 == NULL )
return;
F_26 ( & V_38 -> V_69 ) ;
F_69 ( V_50 ) ;
F_27 ( & V_38 -> V_69 ) ;
}
static int F_71 ( struct V_41 * V_42 , T_3 V_47 )
{
int V_82 ;
V_82 = F_72 ( V_42 -> V_70 -> V_50 , V_116 ,
V_42 -> V_70 , V_42 -> V_71 , V_47 ) ;
if ( V_82 < 0 && V_82 != - V_93 )
return V_82 ;
V_82 = F_72 ( V_42 -> V_71 -> V_50 , V_116 ,
V_42 -> V_71 , V_42 -> V_70 , V_47 ) ;
if ( V_82 < 0 && V_82 != - V_93 ) {
F_72 ( V_42 -> V_70 -> V_50 , V_116 ,
V_42 -> V_70 , V_42 -> V_71 , V_42 -> V_47 ) ;
return V_82 ;
}
V_42 -> V_47 = V_47 ;
V_42 -> V_103 -> V_47 = V_42 -> V_47 ;
return 0 ;
}
int F_73 ( struct V_41 * V_42 , T_3 V_47 )
{
const T_3 V_117 = V_78 ;
struct V_56 * V_38 ;
struct V_65 * V_70 , * V_71 ;
int V_82 = - V_89 ;
if ( V_42 == NULL )
return - V_118 ;
if ( ( V_42 -> V_47 & ~ V_117 ) != ( V_47 & ~ V_117 ) )
return - V_118 ;
if ( V_42 -> V_47 & V_115 )
return V_42 -> V_47 == V_47 ? 0 : - V_118 ;
if ( V_42 -> V_47 == V_47 )
return 0 ;
V_70 = V_42 -> V_70 -> V_50 ;
V_71 = V_42 -> V_71 -> V_50 ;
if ( ! ( V_42 -> V_47 & V_119 ) &&
( V_70 -> V_88 || V_71 -> V_88 ) )
return - V_89 ;
V_38 = V_70 -> V_67 . V_38 ;
if ( V_38 -> V_120 ) {
V_82 = V_38 -> V_120 ( V_42 , V_47 ,
V_121 ) ;
if ( V_82 < 0 )
return V_82 ;
}
V_82 = F_71 ( V_42 , V_47 ) ;
if ( V_38 -> V_120 )
V_38 -> V_120 ( V_42 , V_47 , V_122 ) ;
return V_82 ;
}
int F_74 ( struct V_41 * V_42 , T_3 V_47 )
{
int V_82 ;
F_54 ( & V_42 -> V_67 . V_38 -> V_95 ) ;
V_82 = F_73 ( V_42 , V_47 ) ;
F_55 ( & V_42 -> V_67 . V_38 -> V_95 ) ;
return V_82 ;
}
struct V_41 *
F_75 ( struct V_45 * V_70 , struct V_45 * V_71 )
{
struct V_41 * V_42 ;
F_47 (link, &source->entity->links, list) {
if ( V_42 -> V_70 -> V_50 == V_70 -> V_50 &&
V_42 -> V_70 -> V_51 == V_70 -> V_51 &&
V_42 -> V_71 -> V_50 == V_71 -> V_50 &&
V_42 -> V_71 -> V_51 == V_71 -> V_51 )
return V_42 ;
}
return NULL ;
}
struct V_45 * F_76 ( struct V_45 * V_46 )
{
struct V_41 * V_42 ;
F_47 (link, &pad->entity->links, list) {
if ( ! ( V_42 -> V_47 & V_78 ) )
continue;
if ( V_42 -> V_70 == V_46 )
return V_42 -> V_71 ;
if ( V_42 -> V_71 == V_46 )
return V_42 -> V_70 ;
}
return NULL ;
}
static void F_77 ( struct V_56 * V_38 ,
struct V_6 * V_7 ,
T_3 F_1 ,
T_3 F_2 , T_3 V_47 )
{
V_7 -> type = F_2 ;
V_7 -> V_47 = V_47 ;
F_78 ( & V_7 -> V_61 ) ;
F_19 ( V_38 , F_1 , & V_7 -> V_67 ) ;
}
struct V_52 * F_79 ( struct V_56 * V_38 ,
T_3 type , T_3 V_47 ,
T_3 V_54 , T_3 V_55 )
{
struct V_52 * V_53 ;
V_53 = F_63 ( sizeof( * V_53 ) , V_31 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_54 = V_54 ;
V_53 -> V_55 = V_55 ;
F_77 ( V_38 , & V_53 -> V_7 , V_5 ,
type , V_47 ) ;
return V_53 ;
}
void F_80 ( struct V_52 * V_53 )
{
F_81 ( & V_53 -> V_7 ) ;
F_23 ( & V_53 -> V_7 . V_67 ) ;
F_8 ( V_53 ) ;
}
struct V_41 * F_82 ( struct V_65 * V_50 ,
struct V_6 * V_7 ,
T_3 V_47 )
{
struct V_41 * V_42 ;
V_42 = F_62 ( & V_7 -> V_61 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_7 = V_7 ;
V_42 -> V_50 = V_50 ;
V_42 -> V_47 = V_47 | V_109 ;
F_19 ( V_7 -> V_67 . V_38 , V_4 ,
& V_42 -> V_67 ) ;
return V_42 ;
}
void F_83 ( struct V_41 * V_42 )
{
F_24 ( & V_42 -> V_58 ) ;
F_23 ( & V_42 -> V_67 ) ;
F_8 ( V_42 ) ;
}
void F_84 ( struct V_41 * V_42 )
{
struct V_56 * V_38 = V_42 -> V_67 . V_38 ;
if ( V_38 == NULL )
return;
F_26 ( & V_38 -> V_69 ) ;
F_83 ( V_42 ) ;
F_27 ( & V_38 -> V_69 ) ;
}
void F_85 ( struct V_6 * V_7 )
{
struct V_41 * V_42 , * V_101 ;
F_65 (link, tmp, &intf->links, list)
F_83 ( V_42 ) ;
}
void F_81 ( struct V_6 * V_7 )
{
struct V_56 * V_38 = V_7 -> V_67 . V_38 ;
if ( V_38 == NULL )
return;
F_26 ( & V_38 -> V_69 ) ;
F_85 ( V_7 ) ;
F_27 ( & V_38 -> V_69 ) ;
}
