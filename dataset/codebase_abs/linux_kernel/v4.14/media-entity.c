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
case V_26 :
return L_24 ;
default:
return L_25 ;
}
}
T_1 int F_3 ( struct V_27 * V_28 ,
int V_29 )
{
V_29 = F_4 ( V_29 , V_30 ) ;
V_28 -> V_31 = F_5 ( V_29 / V_30 , sizeof( long ) ,
V_32 ) ;
if ( ! V_28 -> V_31 )
return - V_33 ;
F_6 ( V_28 -> V_31 , V_29 ) ;
V_28 -> V_29 = V_29 ;
return 0 ;
}
void F_7 ( struct V_27 * V_28 )
{
F_8 ( V_28 -> V_31 ) ;
}
static void F_9 ( const char * V_34 , struct V_35 * V_36 )
{
#if F_10 ( V_37 ) || F_10 ( V_38 )
switch ( F_11 ( V_36 ) ) {
case V_2 :
F_12 ( V_36 -> V_39 -> V_40 ,
L_26 ,
V_34 , F_13 ( V_36 ) ,
F_14 ( V_36 ) -> V_41 ) ;
break;
case V_4 :
{
struct V_42 * V_43 = F_15 ( V_36 ) ;
F_12 ( V_36 -> V_39 -> V_40 ,
L_27 ,
V_34 , F_13 ( V_36 ) ,
F_11 ( V_43 -> V_44 ) == V_3 ?
L_28 : L_29 ,
F_13 ( V_43 -> V_44 ) ,
F_13 ( V_43 -> V_45 ) ) ;
break;
}
case V_3 :
{
struct V_46 * V_47 = F_16 ( V_36 ) ;
F_12 ( V_36 -> V_39 -> V_40 ,
L_30 ,
V_34 , F_13 ( V_36 ) ,
V_47 -> V_48 & V_49 ? L_31 : L_32 ,
V_47 -> V_48 & V_50 ? L_33 : L_32 ,
V_47 -> V_51 -> V_41 , V_47 -> V_52 ) ;
break;
}
case V_5 :
{
struct V_6 * V_7 = F_17 ( V_36 ) ;
struct V_53 * V_54 = F_18 ( V_7 ) ;
F_12 ( V_36 -> V_39 -> V_40 ,
L_34 ,
V_34 , F_13 ( V_36 ) ,
F_2 ( V_7 ) ,
V_54 -> V_55 , V_54 -> V_56 ) ;
break;
}
}
#endif
}
void F_19 ( struct V_57 * V_39 ,
enum V_1 type ,
struct V_35 * V_36 )
{
F_20 ( ! V_39 ) ;
V_36 -> V_39 = V_39 ;
V_36 -> V_58 = F_21 ( type , ++ V_39 -> V_58 ) ;
switch ( type ) {
case V_2 :
F_22 ( & V_36 -> V_59 , & V_39 -> V_60 ) ;
break;
case V_3 :
F_22 ( & V_36 -> V_59 , & V_39 -> V_61 ) ;
break;
case V_4 :
F_22 ( & V_36 -> V_59 , & V_39 -> V_62 ) ;
break;
case V_5 :
F_22 ( & V_36 -> V_59 , & V_39 -> V_63 ) ;
break;
}
V_39 -> V_64 ++ ;
F_9 ( V_65 , V_36 ) ;
}
void F_23 ( struct V_35 * V_36 )
{
if ( V_36 -> V_39 == NULL )
return;
F_9 ( V_65 , V_36 ) ;
V_36 -> V_39 -> V_64 ++ ;
F_24 ( & V_36 -> V_59 ) ;
V_36 -> V_39 = NULL ;
}
int F_25 ( struct V_66 * V_51 , T_2 V_67 ,
struct V_46 * V_61 )
{
struct V_57 * V_39 = V_51 -> V_68 . V_39 ;
unsigned int V_69 ;
V_51 -> V_67 = V_67 ;
V_51 -> V_61 = V_61 ;
if ( V_39 )
F_26 ( & V_39 -> V_70 ) ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ ) {
V_61 [ V_69 ] . V_51 = V_51 ;
V_61 [ V_69 ] . V_52 = V_69 ;
if ( V_39 )
F_19 ( V_39 , V_3 ,
& V_51 -> V_61 [ V_69 ] . V_68 ) ;
}
if ( V_39 )
F_27 ( & V_39 -> V_70 ) ;
return 0 ;
}
static struct V_66 *
F_28 ( struct V_66 * V_51 , struct V_42 * V_43 )
{
if ( V_43 -> V_71 -> V_51 == V_51 )
return V_43 -> V_72 -> V_51 ;
else
return V_43 -> V_71 -> V_51 ;
}
static void F_29 ( struct V_73 * V_74 ,
struct V_66 * V_51 )
{
if ( V_74 -> V_75 == V_76 - 1 ) {
F_30 ( 1 ) ;
return;
}
V_74 -> V_75 ++ ;
V_74 -> V_77 [ V_74 -> V_75 ] . V_43 = V_51 -> V_62 . V_78 ;
V_74 -> V_77 [ V_74 -> V_75 ] . V_51 = V_51 ;
}
static struct V_66 * F_31 ( struct V_73 * V_74 )
{
struct V_66 * V_51 ;
V_51 = V_74 -> V_77 [ V_74 -> V_75 ] . V_51 ;
V_74 -> V_75 -- ;
return V_51 ;
}
T_1 int F_32 (
struct V_73 * V_74 , struct V_57 * V_39 )
{
return F_33 ( & V_74 -> V_28 , V_39 ) ;
}
void F_34 ( struct V_73 * V_74 )
{
F_7 ( & V_74 -> V_28 ) ;
}
void F_35 ( struct V_73 * V_74 ,
struct V_66 * V_51 )
{
F_36 ( & V_74 -> V_28 ) ;
F_37 ( & V_74 -> V_28 , V_51 ) ;
V_74 -> V_75 = 0 ;
V_74 -> V_77 [ V_74 -> V_75 ] . V_51 = NULL ;
F_29 ( V_74 , V_51 ) ;
F_12 ( V_51 -> V_68 . V_39 -> V_40 ,
L_35 , V_51 -> V_41 ) ;
}
static void F_38 ( struct V_73 * V_74 )
{
struct V_66 * V_51 = F_39 ( V_74 ) ;
struct V_42 * V_43 ;
struct V_66 * V_78 ;
V_43 = F_40 ( F_41 ( V_74 ) , F_42 ( * V_43 ) , V_59 ) ;
if ( ! ( V_43 -> V_48 & V_79 ) ) {
F_41 ( V_74 ) = F_41 ( V_74 ) -> V_78 ;
F_12 ( V_51 -> V_68 . V_39 -> V_40 ,
L_36 ,
V_43 -> V_71 -> V_51 -> V_41 , V_43 -> V_71 -> V_52 ,
V_43 -> V_72 -> V_51 -> V_41 , V_43 -> V_72 -> V_52 ) ;
return;
}
V_78 = F_28 ( V_51 , V_43 ) ;
if ( F_43 ( & V_74 -> V_28 , V_78 ) ) {
F_41 ( V_74 ) = F_41 ( V_74 ) -> V_78 ;
F_12 ( V_51 -> V_68 . V_39 -> V_40 ,
L_37 ,
V_78 -> V_41 ) ;
return;
}
F_41 ( V_74 ) = F_41 ( V_74 ) -> V_78 ;
F_29 ( V_74 , V_78 ) ;
F_12 ( V_51 -> V_68 . V_39 -> V_40 , L_38 ,
V_78 -> V_41 ) ;
}
struct V_66 * F_44 ( struct V_73 * V_74 )
{
struct V_66 * V_51 ;
if ( F_39 ( V_74 ) == NULL )
return NULL ;
while ( F_41 ( V_74 ) != & F_39 ( V_74 ) -> V_62 )
F_38 ( V_74 ) ;
V_51 = F_31 ( V_74 ) ;
F_12 ( V_51 -> V_68 . V_39 -> V_40 ,
L_39 , V_51 -> V_41 ) ;
return V_51 ;
}
int F_45 ( struct V_66 * V_51 ,
struct V_80 * V_81 ,
unsigned long V_82 )
{
struct V_83 V_84 ;
unsigned int V_69 ;
int V_85 ;
if ( ! V_51 -> V_86 || ! V_51 -> V_86 -> V_87 ) {
for ( V_69 = 0 ; V_69 < V_51 -> V_67 ; V_69 ++ ) {
if ( V_51 -> V_61 [ V_69 ] . V_48 & V_82 )
return V_69 ;
}
return - V_88 ;
}
V_85 = F_46 ( V_81 , & V_84 ) ;
if ( V_85 )
return V_85 ;
V_85 = V_51 -> V_86 -> V_87 ( & V_84 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( V_85 >= V_51 -> V_67 )
return - V_88 ;
if ( ! ( V_51 -> V_61 [ V_85 ] . V_48 & V_82 ) )
return - V_88 ;
return V_85 ;
}
T_1 int F_47 ( struct V_66 * V_51 ,
struct V_89 * V_90 )
{
struct V_57 * V_39 = V_51 -> V_68 . V_39 ;
struct V_73 * V_74 = & V_90 -> V_74 ;
struct V_66 * V_91 = V_51 ;
struct V_42 * V_43 ;
int V_85 ;
if ( ! V_90 -> V_92 ++ ) {
V_85 = F_32 ( & V_90 -> V_74 , V_39 ) ;
if ( V_85 )
goto V_93;
}
F_35 ( & V_90 -> V_74 , V_51 ) ;
while ( ( V_51 = F_44 ( V_74 ) ) ) {
F_48 ( V_94 , V_95 ) ;
F_48 ( V_96 , V_95 ) ;
V_51 -> V_97 ++ ;
if ( F_30 ( V_51 -> V_90 && V_51 -> V_90 != V_90 ) ) {
V_85 = - V_98 ;
goto error;
}
V_51 -> V_90 = V_90 ;
if ( V_51 -> V_97 > 1 )
continue;
if ( ! V_51 -> V_86 || ! V_51 -> V_86 -> V_99 )
continue;
F_6 ( V_94 , V_51 -> V_67 ) ;
F_49 ( V_96 , V_51 -> V_67 ) ;
F_50 (link, &entity->links, list) {
struct V_46 * V_47 = V_43 -> V_72 -> V_51 == V_51
? V_43 -> V_72 : V_43 -> V_71 ;
F_51 ( V_96 , V_47 -> V_52 , 1 ) ;
if ( ! ( V_47 -> V_48 & V_100 ) ||
V_43 -> V_48 & V_79 )
F_52 ( V_94 , V_47 -> V_52 , 1 ) ;
if ( V_43 -> V_72 != V_47 ||
! ( V_43 -> V_48 & V_79 ) )
continue;
V_85 = V_51 -> V_86 -> V_99 ( V_43 ) ;
if ( V_85 < 0 && V_85 != - V_101 ) {
F_12 ( V_51 -> V_68 . V_39 -> V_40 ,
L_40 ,
V_43 -> V_71 -> V_51 -> V_41 ,
V_43 -> V_71 -> V_52 ,
V_51 -> V_41 , V_43 -> V_72 -> V_52 , V_85 ) ;
goto error;
}
}
F_53 ( V_94 , V_94 , V_96 , V_51 -> V_67 ) ;
if ( ! F_54 ( V_94 , V_51 -> V_67 ) ) {
V_85 = - V_102 ;
F_12 ( V_51 -> V_68 . V_39 -> V_40 ,
L_41 ,
V_51 -> V_41 ,
( unsigned ) F_55 (
V_94 , V_51 -> V_67 ) ) ;
goto error;
}
}
return 0 ;
error:
F_35 ( V_74 , V_91 ) ;
while ( ( V_91 = F_44 ( V_74 ) ) ) {
if ( ! F_56 ( V_91 -> V_97 <= 0 ) ) {
V_91 -> V_97 -- ;
if ( V_91 -> V_97 == 0 )
V_91 -> V_90 = NULL ;
}
if ( V_91 == V_51 )
break;
}
V_93:
if ( ! -- V_90 -> V_92 )
F_34 ( V_74 ) ;
return V_85 ;
}
T_1 int F_57 ( struct V_66 * V_51 ,
struct V_89 * V_90 )
{
struct V_57 * V_39 = V_51 -> V_68 . V_39 ;
int V_85 ;
F_26 ( & V_39 -> V_70 ) ;
V_85 = F_47 ( V_51 , V_90 ) ;
F_27 ( & V_39 -> V_70 ) ;
return V_85 ;
}
void F_58 ( struct V_66 * V_51 )
{
struct V_73 * V_74 = & V_51 -> V_90 -> V_74 ;
struct V_89 * V_90 = V_51 -> V_90 ;
if ( F_30 ( ! V_90 ) )
return;
F_35 ( V_74 , V_51 ) ;
while ( ( V_51 = F_44 ( V_74 ) ) ) {
if ( ! F_56 ( V_51 -> V_97 <= 0 ) ) {
V_51 -> V_97 -- ;
if ( V_51 -> V_97 == 0 )
V_51 -> V_90 = NULL ;
}
}
if ( ! -- V_90 -> V_92 )
F_34 ( V_74 ) ;
}
void F_59 ( struct V_66 * V_51 )
{
struct V_57 * V_39 = V_51 -> V_68 . V_39 ;
F_26 ( & V_39 -> V_70 ) ;
F_58 ( V_51 ) ;
F_27 ( & V_39 -> V_70 ) ;
}
struct V_66 * F_60 ( struct V_66 * V_51 )
{
if ( V_51 == NULL )
return NULL ;
if ( V_51 -> V_68 . V_39 -> V_40 &&
! F_61 ( V_51 -> V_68 . V_39 -> V_40 -> V_103 -> V_104 ) )
return NULL ;
return V_51 ;
}
void F_62 ( struct V_66 * V_51 )
{
if ( V_51 == NULL )
return;
if ( V_51 -> V_68 . V_39 -> V_40 )
F_63 ( V_51 -> V_68 . V_39 -> V_40 -> V_103 -> V_104 ) ;
}
static struct V_42 * F_64 ( struct V_105 * V_106 )
{
struct V_42 * V_43 ;
V_43 = F_65 ( sizeof( * V_43 ) , V_32 ) ;
if ( V_43 == NULL )
return NULL ;
F_22 ( & V_43 -> V_59 , V_106 ) ;
return V_43 ;
}
static void F_66 ( struct V_66 * V_51 ,
struct V_42 * V_43 )
{
struct V_42 * V_107 , * V_108 ;
struct V_66 * V_109 ;
if ( V_43 -> V_71 -> V_51 == V_51 )
V_109 = V_43 -> V_72 -> V_51 ;
else
V_109 = V_43 -> V_71 -> V_51 ;
F_67 (rlink, tmp, &remote->links, list) {
if ( V_107 != V_43 -> V_110 )
continue;
if ( V_43 -> V_71 -> V_51 == V_51 )
V_109 -> V_111 -- ;
F_24 ( & V_107 -> V_59 ) ;
F_23 ( & V_107 -> V_68 ) ;
F_8 ( V_107 ) ;
if ( -- V_109 -> V_112 == 0 )
break;
}
F_24 ( & V_43 -> V_59 ) ;
F_23 ( & V_43 -> V_68 ) ;
F_8 ( V_43 ) ;
}
int
F_68 ( struct V_66 * V_71 , T_2 V_113 ,
struct V_66 * V_72 , T_2 V_114 , T_3 V_48 )
{
struct V_42 * V_43 ;
struct V_42 * V_115 ;
F_20 ( V_71 == NULL || V_72 == NULL ) ;
F_20 ( V_113 >= V_71 -> V_67 ) ;
F_20 ( V_114 >= V_72 -> V_67 ) ;
V_43 = F_64 ( & V_71 -> V_62 ) ;
if ( V_43 == NULL )
return - V_33 ;
V_43 -> V_71 = & V_71 -> V_61 [ V_113 ] ;
V_43 -> V_72 = & V_72 -> V_61 [ V_114 ] ;
V_43 -> V_48 = V_48 & ~ V_116 ;
F_19 ( V_71 -> V_68 . V_39 , V_4 ,
& V_43 -> V_68 ) ;
V_115 = F_64 ( & V_72 -> V_62 ) ;
if ( V_115 == NULL ) {
F_66 ( V_71 , V_43 ) ;
return - V_33 ;
}
V_115 -> V_71 = & V_71 -> V_61 [ V_113 ] ;
V_115 -> V_72 = & V_72 -> V_61 [ V_114 ] ;
V_115 -> V_48 = V_48 ;
V_115 -> V_117 = true ;
F_19 ( V_72 -> V_68 . V_39 , V_4 ,
& V_115 -> V_68 ) ;
V_43 -> V_110 = V_115 ;
V_115 -> V_110 = V_43 ;
V_72 -> V_111 ++ ;
V_72 -> V_112 ++ ;
V_71 -> V_112 ++ ;
return 0 ;
}
int F_69 ( const struct V_57 * V_39 ,
const T_3 V_118 ,
struct V_66 * V_71 ,
const T_2 V_113 ,
const T_3 V_119 ,
struct V_66 * V_72 ,
const T_2 V_114 ,
T_3 V_48 ,
const bool V_120 )
{
struct V_66 * V_51 ;
unsigned V_121 ;
int V_85 ;
if ( V_71 && V_72 )
return F_68 ( V_71 , V_113 ,
V_72 , V_114 , V_48 ) ;
if ( ! V_71 && ! V_72 ) {
if ( ! V_120 )
return 0 ;
F_70 (source, mdev) {
if ( V_71 -> V_121 != V_118 )
continue;
F_70 (sink, mdev) {
if ( V_72 -> V_121 != V_119 )
continue;
V_85 = F_68 ( V_71 , V_113 ,
V_72 , V_114 ,
V_48 ) ;
if ( V_85 )
return V_85 ;
V_48 &= ~ ( V_79 |
V_122 ) ;
}
}
return 0 ;
}
if ( V_71 )
V_121 = V_119 ;
else
V_121 = V_118 ;
F_70 (entity, mdev) {
if ( V_51 -> V_121 != V_121 )
continue;
if ( V_71 )
V_85 = F_68 ( V_71 , V_113 ,
V_51 , V_114 , V_48 ) ;
else
V_85 = F_68 ( V_51 , V_113 ,
V_72 , V_114 , V_48 ) ;
if ( V_85 )
return V_85 ;
V_48 &= ~ ( V_79 | V_122 ) ;
}
return 0 ;
}
void F_71 ( struct V_66 * V_51 )
{
struct V_42 * V_43 , * V_108 ;
F_67 (link, tmp, &entity->links, list)
F_66 ( V_51 , V_43 ) ;
V_51 -> V_112 = 0 ;
V_51 -> V_111 = 0 ;
}
void F_72 ( struct V_66 * V_51 )
{
struct V_57 * V_39 = V_51 -> V_68 . V_39 ;
if ( V_39 == NULL )
return;
F_26 ( & V_39 -> V_70 ) ;
F_71 ( V_51 ) ;
F_27 ( & V_39 -> V_70 ) ;
}
static int F_73 ( struct V_42 * V_43 , T_3 V_48 )
{
int V_85 ;
V_85 = F_74 ( V_43 -> V_71 -> V_51 , V_123 ,
V_43 -> V_71 , V_43 -> V_72 , V_48 ) ;
if ( V_85 < 0 && V_85 != - V_101 )
return V_85 ;
V_85 = F_74 ( V_43 -> V_72 -> V_51 , V_123 ,
V_43 -> V_72 , V_43 -> V_71 , V_48 ) ;
if ( V_85 < 0 && V_85 != - V_101 ) {
F_74 ( V_43 -> V_71 -> V_51 , V_123 ,
V_43 -> V_71 , V_43 -> V_72 , V_43 -> V_48 ) ;
return V_85 ;
}
V_43 -> V_48 = V_48 ;
V_43 -> V_110 -> V_48 = V_43 -> V_48 ;
return 0 ;
}
int F_75 ( struct V_42 * V_43 , T_3 V_48 )
{
const T_3 V_124 = V_79 ;
struct V_57 * V_39 ;
struct V_66 * V_71 , * V_72 ;
int V_85 = - V_98 ;
if ( V_43 == NULL )
return - V_125 ;
if ( ( V_43 -> V_48 & ~ V_124 ) != ( V_48 & ~ V_124 ) )
return - V_125 ;
if ( V_43 -> V_48 & V_122 )
return V_43 -> V_48 == V_48 ? 0 : - V_125 ;
if ( V_43 -> V_48 == V_48 )
return 0 ;
V_71 = V_43 -> V_71 -> V_51 ;
V_72 = V_43 -> V_72 -> V_51 ;
if ( ! ( V_43 -> V_48 & V_126 ) &&
( V_71 -> V_97 || V_72 -> V_97 ) )
return - V_98 ;
V_39 = V_71 -> V_68 . V_39 ;
if ( V_39 -> V_86 && V_39 -> V_86 -> V_127 ) {
V_85 = V_39 -> V_86 -> V_127 ( V_43 , V_48 ,
V_128 ) ;
if ( V_85 < 0 )
return V_85 ;
}
V_85 = F_73 ( V_43 , V_48 ) ;
if ( V_39 -> V_86 && V_39 -> V_86 -> V_127 )
V_39 -> V_86 -> V_127 ( V_43 , V_48 ,
V_129 ) ;
return V_85 ;
}
int F_76 ( struct V_42 * V_43 , T_3 V_48 )
{
int V_85 ;
F_26 ( & V_43 -> V_68 . V_39 -> V_70 ) ;
V_85 = F_75 ( V_43 , V_48 ) ;
F_27 ( & V_43 -> V_68 . V_39 -> V_70 ) ;
return V_85 ;
}
struct V_42 *
F_77 ( struct V_46 * V_71 , struct V_46 * V_72 )
{
struct V_42 * V_43 ;
F_50 (link, &source->entity->links, list) {
if ( V_43 -> V_71 -> V_51 == V_71 -> V_51 &&
V_43 -> V_71 -> V_52 == V_71 -> V_52 &&
V_43 -> V_72 -> V_51 == V_72 -> V_51 &&
V_43 -> V_72 -> V_52 == V_72 -> V_52 )
return V_43 ;
}
return NULL ;
}
struct V_46 * F_78 ( const struct V_46 * V_47 )
{
struct V_42 * V_43 ;
F_50 (link, &pad->entity->links, list) {
if ( ! ( V_43 -> V_48 & V_79 ) )
continue;
if ( V_43 -> V_71 == V_47 )
return V_43 -> V_72 ;
if ( V_43 -> V_72 == V_47 )
return V_43 -> V_71 ;
}
return NULL ;
}
static void F_79 ( struct V_57 * V_39 ,
struct V_6 * V_7 ,
T_3 F_1 ,
T_3 F_2 , T_3 V_48 )
{
V_7 -> type = F_2 ;
V_7 -> V_48 = V_48 ;
F_80 ( & V_7 -> V_62 ) ;
F_19 ( V_39 , F_1 , & V_7 -> V_68 ) ;
}
struct V_53 * F_81 ( struct V_57 * V_39 ,
T_3 type , T_3 V_48 ,
T_3 V_55 , T_3 V_56 )
{
struct V_53 * V_54 ;
V_54 = F_65 ( sizeof( * V_54 ) , V_32 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_55 = V_55 ;
V_54 -> V_56 = V_56 ;
F_79 ( V_39 , & V_54 -> V_7 , V_5 ,
type , V_48 ) ;
return V_54 ;
}
void F_82 ( struct V_53 * V_54 )
{
F_83 ( & V_54 -> V_7 ) ;
F_23 ( & V_54 -> V_7 . V_68 ) ;
F_8 ( V_54 ) ;
}
struct V_42 * F_84 ( struct V_66 * V_51 ,
struct V_6 * V_7 ,
T_3 V_48 )
{
struct V_42 * V_43 ;
V_43 = F_64 ( & V_7 -> V_62 ) ;
if ( V_43 == NULL )
return NULL ;
V_43 -> V_7 = V_7 ;
V_43 -> V_51 = V_51 ;
V_43 -> V_48 = V_48 | V_116 ;
F_19 ( V_7 -> V_68 . V_39 , V_4 ,
& V_43 -> V_68 ) ;
return V_43 ;
}
void F_85 ( struct V_42 * V_43 )
{
F_24 ( & V_43 -> V_59 ) ;
F_23 ( & V_43 -> V_68 ) ;
F_8 ( V_43 ) ;
}
void F_86 ( struct V_42 * V_43 )
{
struct V_57 * V_39 = V_43 -> V_68 . V_39 ;
if ( V_39 == NULL )
return;
F_26 ( & V_39 -> V_70 ) ;
F_85 ( V_43 ) ;
F_27 ( & V_39 -> V_70 ) ;
}
void F_87 ( struct V_6 * V_7 )
{
struct V_42 * V_43 , * V_108 ;
F_67 (link, tmp, &intf->links, list)
F_85 ( V_43 ) ;
}
void F_83 ( struct V_6 * V_7 )
{
struct V_57 * V_39 = V_7 -> V_68 . V_39 ;
if ( V_39 == NULL )
return;
F_26 ( & V_39 -> V_70 ) ;
F_87 ( V_7 ) ;
F_27 ( & V_39 -> V_70 ) ;
}
