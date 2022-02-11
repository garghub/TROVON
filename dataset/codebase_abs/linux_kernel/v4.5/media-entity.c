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
default:
return L_16 ;
}
}
T_1 int F_3 ( struct V_18 * V_19 ,
int V_20 )
{
V_19 -> V_21 = F_4 ( F_5 ( V_20 , V_22 ) ,
sizeof( long ) , V_23 ) ;
if ( ! V_19 -> V_21 )
return - V_24 ;
F_6 ( V_19 -> V_21 , V_20 ) ;
V_19 -> V_20 = V_20 ;
return 0 ;
}
void F_7 ( struct V_18 * V_19 )
{
F_8 ( V_19 -> V_21 ) ;
}
static void F_9 ( const char * V_25 , struct V_26 * V_27 )
{
#if F_10 ( V_28 ) || F_10 ( V_29 )
switch ( F_11 ( V_27 ) ) {
case V_2 :
F_12 ( V_27 -> V_30 -> V_31 ,
L_17 ,
V_25 , F_13 ( V_27 ) ,
F_14 ( V_27 ) -> V_32 ) ;
break;
case V_4 :
{
struct V_33 * V_34 = F_15 ( V_27 ) ;
F_12 ( V_27 -> V_30 -> V_31 ,
L_18 ,
V_25 , F_13 ( V_27 ) ,
F_11 ( V_34 -> V_35 ) == V_3 ?
L_19 : L_20 ,
F_13 ( V_34 -> V_35 ) ,
F_13 ( V_34 -> V_36 ) ) ;
break;
}
case V_3 :
{
struct V_37 * V_38 = F_16 ( V_27 ) ;
F_12 ( V_27 -> V_30 -> V_31 ,
L_21 ,
V_25 , F_13 ( V_27 ) ,
V_38 -> V_39 & V_40 ? L_22 : L_23 ,
V_38 -> V_39 & V_41 ? L_24 : L_23 ,
V_38 -> V_42 -> V_32 , V_38 -> V_43 ) ;
break;
}
case V_5 :
{
struct V_6 * V_7 = F_17 ( V_27 ) ;
struct V_44 * V_45 = F_18 ( V_7 ) ;
F_12 ( V_27 -> V_30 -> V_31 ,
L_25 ,
V_25 , F_13 ( V_27 ) ,
F_2 ( V_7 ) ,
V_45 -> V_46 , V_45 -> V_47 ) ;
break;
}
}
#endif
}
void F_19 ( struct V_48 * V_30 ,
enum V_1 type ,
struct V_26 * V_27 )
{
F_20 ( ! V_30 ) ;
V_27 -> V_30 = V_30 ;
V_27 -> V_49 = F_21 ( type , ++ V_30 -> V_49 ) ;
switch ( type ) {
case V_2 :
F_22 ( & V_27 -> V_50 , & V_30 -> V_51 ) ;
break;
case V_3 :
F_22 ( & V_27 -> V_50 , & V_30 -> V_52 ) ;
break;
case V_4 :
F_22 ( & V_27 -> V_50 , & V_30 -> V_53 ) ;
break;
case V_5 :
F_22 ( & V_27 -> V_50 , & V_30 -> V_54 ) ;
break;
}
V_30 -> V_55 ++ ;
F_9 ( V_56 , V_27 ) ;
}
void F_23 ( struct V_26 * V_27 )
{
F_9 ( V_56 , V_27 ) ;
V_27 -> V_30 -> V_55 ++ ;
F_24 ( & V_27 -> V_50 ) ;
}
int F_25 ( struct V_57 * V_42 , T_2 V_58 ,
struct V_37 * V_52 )
{
struct V_48 * V_30 = V_42 -> V_59 . V_30 ;
unsigned int V_60 ;
V_42 -> V_58 = V_58 ;
V_42 -> V_52 = V_52 ;
if ( V_30 )
F_26 ( & V_30 -> V_61 ) ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 ++ ) {
V_52 [ V_60 ] . V_42 = V_42 ;
V_52 [ V_60 ] . V_43 = V_60 ;
if ( V_30 )
F_19 ( V_30 , V_3 ,
& V_42 -> V_52 [ V_60 ] . V_59 ) ;
}
if ( V_30 )
F_27 ( & V_30 -> V_61 ) ;
return 0 ;
}
static struct V_57 *
F_28 ( struct V_57 * V_42 , struct V_33 * V_34 )
{
if ( V_34 -> V_62 -> V_42 == V_42 )
return V_34 -> V_63 -> V_42 ;
else
return V_34 -> V_62 -> V_42 ;
}
static void F_29 ( struct V_64 * V_65 ,
struct V_57 * V_42 )
{
if ( V_65 -> V_66 == V_67 - 1 ) {
F_30 ( 1 ) ;
return;
}
V_65 -> V_66 ++ ;
V_65 -> V_68 [ V_65 -> V_66 ] . V_34 = V_42 -> V_53 . V_69 ;
V_65 -> V_68 [ V_65 -> V_66 ] . V_42 = V_42 ;
}
static struct V_57 * F_31 ( struct V_64 * V_65 )
{
struct V_57 * V_42 ;
V_42 = V_65 -> V_68 [ V_65 -> V_66 ] . V_42 ;
V_65 -> V_66 -- ;
return V_42 ;
}
T_1 int F_32 (
struct V_64 * V_65 , struct V_48 * V_30 )
{
return F_33 ( & V_65 -> V_19 , V_30 ) ;
}
void F_34 ( struct V_64 * V_65 )
{
F_7 ( & V_65 -> V_19 ) ;
}
void F_35 ( struct V_64 * V_65 ,
struct V_57 * V_42 )
{
F_36 ( & V_65 -> V_19 ) ;
F_37 ( & V_65 -> V_19 , V_42 ) ;
V_65 -> V_66 = 0 ;
V_65 -> V_68 [ V_65 -> V_66 ] . V_42 = NULL ;
F_29 ( V_65 , V_42 ) ;
}
struct V_57 *
F_38 ( struct V_64 * V_65 )
{
if ( F_39 ( V_65 ) == NULL )
return NULL ;
while ( F_40 ( V_65 ) != & F_39 ( V_65 ) -> V_53 ) {
struct V_57 * V_42 = F_39 ( V_65 ) ;
struct V_33 * V_34 ;
struct V_57 * V_69 ;
V_34 = F_41 ( F_40 ( V_65 ) , F_42 ( * V_34 ) , V_50 ) ;
if ( ! ( V_34 -> V_39 & V_70 ) ) {
F_40 ( V_65 ) = F_40 ( V_65 ) -> V_69 ;
continue;
}
V_69 = F_28 ( V_42 , V_34 ) ;
if ( F_43 ( & V_65 -> V_19 , V_69 ) ) {
F_40 ( V_65 ) = F_40 ( V_65 ) -> V_69 ;
continue;
}
F_40 ( V_65 ) = F_40 ( V_65 ) -> V_69 ;
F_29 ( V_65 , V_69 ) ;
}
return F_31 ( V_65 ) ;
}
T_1 int F_44 ( struct V_57 * V_42 ,
struct V_71 * V_72 )
{
struct V_48 * V_30 = V_42 -> V_59 . V_30 ;
struct V_64 * V_65 = & V_72 -> V_65 ;
struct V_57 * V_73 = V_42 ;
struct V_33 * V_34 ;
int V_74 ;
F_45 ( & V_30 -> V_75 ) ;
if ( ! V_72 -> V_76 ++ ) {
V_74 = F_32 ( & V_72 -> V_65 , V_30 ) ;
if ( V_74 )
goto V_77;
}
F_35 ( & V_72 -> V_65 , V_42 ) ;
while ( ( V_42 = F_38 ( V_65 ) ) ) {
F_46 ( V_78 , V_79 ) ;
F_46 ( V_80 , V_79 ) ;
V_42 -> V_81 ++ ;
if ( F_30 ( V_42 -> V_72 && V_42 -> V_72 != V_72 ) ) {
V_74 = - V_82 ;
goto error;
}
V_42 -> V_72 = V_72 ;
if ( V_42 -> V_81 > 1 )
continue;
if ( ! V_42 -> V_83 || ! V_42 -> V_83 -> V_84 )
continue;
F_6 ( V_78 , V_42 -> V_58 ) ;
F_47 ( V_80 , V_42 -> V_58 ) ;
F_48 (link, &entity->links, list) {
struct V_37 * V_38 = V_34 -> V_63 -> V_42 == V_42
? V_34 -> V_63 : V_34 -> V_62 ;
F_49 ( V_80 , V_38 -> V_43 , 1 ) ;
if ( ! ( V_38 -> V_39 & V_85 ) ||
V_34 -> V_39 & V_70 )
F_50 ( V_78 , V_38 -> V_43 , 1 ) ;
if ( V_34 -> V_63 != V_38 ||
! ( V_34 -> V_39 & V_70 ) )
continue;
V_74 = V_42 -> V_83 -> V_84 ( V_34 ) ;
if ( V_74 < 0 && V_74 != - V_86 ) {
F_12 ( V_42 -> V_59 . V_30 -> V_31 ,
L_26 ,
V_34 -> V_62 -> V_42 -> V_32 ,
V_34 -> V_62 -> V_43 ,
V_42 -> V_32 , V_34 -> V_63 -> V_43 , V_74 ) ;
goto error;
}
}
F_51 ( V_78 , V_78 , V_80 , V_42 -> V_58 ) ;
if ( ! F_52 ( V_78 , V_42 -> V_58 ) ) {
V_74 = - V_87 ;
F_12 ( V_42 -> V_59 . V_30 -> V_31 ,
L_27 ,
V_42 -> V_32 ,
( unsigned ) F_53 (
V_78 , V_42 -> V_58 ) ) ;
goto error;
}
}
F_54 ( & V_30 -> V_75 ) ;
return 0 ;
error:
F_35 ( V_65 , V_73 ) ;
while ( ( V_73 = F_38 ( V_65 ) ) ) {
V_73 -> V_81 -- ;
if ( V_73 -> V_81 == 0 )
V_73 -> V_72 = NULL ;
if ( V_73 == V_42 )
break;
}
V_77:
if ( ! -- V_72 -> V_76 )
F_34 ( V_65 ) ;
F_54 ( & V_30 -> V_75 ) ;
return V_74 ;
}
void F_55 ( struct V_57 * V_42 )
{
struct V_48 * V_30 = V_42 -> V_59 . V_30 ;
struct V_64 * V_65 = & V_42 -> V_72 -> V_65 ;
struct V_71 * V_72 = V_42 -> V_72 ;
F_45 ( & V_30 -> V_75 ) ;
F_30 ( ! V_72 -> V_76 ) ;
F_35 ( V_65 , V_42 ) ;
while ( ( V_42 = F_38 ( V_65 ) ) ) {
V_42 -> V_81 -- ;
if ( V_42 -> V_81 == 0 )
V_42 -> V_72 = NULL ;
}
if ( ! -- V_72 -> V_76 )
F_34 ( V_65 ) ;
F_54 ( & V_30 -> V_75 ) ;
}
struct V_57 * F_56 ( struct V_57 * V_42 )
{
if ( V_42 == NULL )
return NULL ;
if ( V_42 -> V_59 . V_30 -> V_31 &&
! F_57 ( V_42 -> V_59 . V_30 -> V_31 -> V_88 -> V_89 ) )
return NULL ;
return V_42 ;
}
void F_58 ( struct V_57 * V_42 )
{
if ( V_42 == NULL )
return;
if ( V_42 -> V_59 . V_30 -> V_31 )
F_59 ( V_42 -> V_59 . V_30 -> V_31 -> V_88 -> V_89 ) ;
}
static struct V_33 * F_60 ( struct V_90 * V_91 )
{
struct V_33 * V_34 ;
V_34 = F_61 ( sizeof( * V_34 ) , V_23 ) ;
if ( V_34 == NULL )
return NULL ;
F_22 ( & V_34 -> V_50 , V_91 ) ;
return V_34 ;
}
static void F_62 ( struct V_57 * V_42 ,
struct V_33 * V_34 )
{
struct V_33 * V_92 , * V_93 ;
struct V_57 * V_94 ;
if ( V_34 -> V_62 -> V_42 == V_42 )
V_94 = V_34 -> V_63 -> V_42 ;
else
V_94 = V_34 -> V_62 -> V_42 ;
F_63 (rlink, tmp, &remote->links, list) {
if ( V_92 != V_34 -> V_95 )
continue;
if ( V_34 -> V_62 -> V_42 == V_42 )
V_94 -> V_96 -- ;
F_24 ( & V_92 -> V_50 ) ;
F_23 ( & V_92 -> V_59 ) ;
F_8 ( V_92 ) ;
if ( -- V_94 -> V_97 == 0 )
break;
}
F_24 ( & V_34 -> V_50 ) ;
F_23 ( & V_34 -> V_59 ) ;
F_8 ( V_34 ) ;
}
int
F_64 ( struct V_57 * V_62 , T_2 V_98 ,
struct V_57 * V_63 , T_2 V_99 , T_3 V_39 )
{
struct V_33 * V_34 ;
struct V_33 * V_100 ;
F_20 ( V_62 == NULL || V_63 == NULL ) ;
F_20 ( V_98 >= V_62 -> V_58 ) ;
F_20 ( V_99 >= V_63 -> V_58 ) ;
V_34 = F_60 ( & V_62 -> V_53 ) ;
if ( V_34 == NULL )
return - V_24 ;
V_34 -> V_62 = & V_62 -> V_52 [ V_98 ] ;
V_34 -> V_63 = & V_63 -> V_52 [ V_99 ] ;
V_34 -> V_39 = V_39 & ~ V_101 ;
F_19 ( V_62 -> V_59 . V_30 , V_4 ,
& V_34 -> V_59 ) ;
V_100 = F_60 ( & V_63 -> V_53 ) ;
if ( V_100 == NULL ) {
F_62 ( V_62 , V_34 ) ;
return - V_24 ;
}
V_100 -> V_62 = & V_62 -> V_52 [ V_98 ] ;
V_100 -> V_63 = & V_63 -> V_52 [ V_99 ] ;
V_100 -> V_39 = V_39 ;
V_100 -> V_102 = true ;
F_19 ( V_63 -> V_59 . V_30 , V_4 ,
& V_100 -> V_59 ) ;
V_34 -> V_95 = V_100 ;
V_100 -> V_95 = V_34 ;
V_63 -> V_96 ++ ;
V_63 -> V_97 ++ ;
V_62 -> V_97 ++ ;
return 0 ;
}
int F_65 ( const struct V_48 * V_30 ,
const T_3 V_103 ,
struct V_57 * V_62 ,
const T_2 V_98 ,
const T_3 V_104 ,
struct V_57 * V_63 ,
const T_2 V_99 ,
T_3 V_39 ,
const bool V_105 )
{
struct V_57 * V_42 ;
unsigned V_106 ;
int V_74 ;
if ( V_62 && V_63 )
return F_64 ( V_62 , V_98 ,
V_63 , V_99 , V_39 ) ;
if ( ! V_62 && ! V_63 ) {
if ( ! V_105 )
return 0 ;
F_66 (source, mdev) {
if ( V_62 -> V_106 != V_103 )
continue;
F_66 (sink, mdev) {
if ( V_63 -> V_106 != V_104 )
continue;
V_74 = F_64 ( V_62 , V_98 ,
V_63 , V_99 ,
V_39 ) ;
if ( V_74 )
return V_74 ;
V_39 &= ~ ( V_70 |
V_107 ) ;
}
}
return 0 ;
}
if ( V_62 )
V_106 = V_104 ;
else
V_106 = V_103 ;
F_66 (entity, mdev) {
if ( V_42 -> V_106 != V_106 )
continue;
if ( V_62 )
V_74 = F_64 ( V_62 , V_98 ,
V_42 , V_99 , V_39 ) ;
else
V_74 = F_64 ( V_42 , V_98 ,
V_63 , V_99 , V_39 ) ;
if ( V_74 )
return V_74 ;
V_39 &= ~ ( V_70 | V_107 ) ;
}
return 0 ;
}
void F_67 ( struct V_57 * V_42 )
{
struct V_33 * V_34 , * V_93 ;
F_63 (link, tmp, &entity->links, list)
F_62 ( V_42 , V_34 ) ;
V_42 -> V_97 = 0 ;
V_42 -> V_96 = 0 ;
}
void F_68 ( struct V_57 * V_42 )
{
struct V_48 * V_30 = V_42 -> V_59 . V_30 ;
if ( V_30 == NULL )
return;
F_26 ( & V_30 -> V_61 ) ;
F_67 ( V_42 ) ;
F_27 ( & V_30 -> V_61 ) ;
}
static int F_69 ( struct V_33 * V_34 , T_3 V_39 )
{
int V_74 ;
V_74 = F_70 ( V_34 -> V_62 -> V_42 , V_108 ,
V_34 -> V_62 , V_34 -> V_63 , V_39 ) ;
if ( V_74 < 0 && V_74 != - V_86 )
return V_74 ;
V_74 = F_70 ( V_34 -> V_63 -> V_42 , V_108 ,
V_34 -> V_63 , V_34 -> V_62 , V_39 ) ;
if ( V_74 < 0 && V_74 != - V_86 ) {
F_70 ( V_34 -> V_62 -> V_42 , V_108 ,
V_34 -> V_62 , V_34 -> V_63 , V_34 -> V_39 ) ;
return V_74 ;
}
V_34 -> V_39 = V_39 ;
V_34 -> V_95 -> V_39 = V_34 -> V_39 ;
return 0 ;
}
int F_71 ( struct V_33 * V_34 , T_3 V_39 )
{
const T_3 V_109 = V_70 ;
struct V_48 * V_30 ;
struct V_57 * V_62 , * V_63 ;
int V_74 = - V_82 ;
if ( V_34 == NULL )
return - V_110 ;
if ( ( V_34 -> V_39 & ~ V_109 ) != ( V_39 & ~ V_109 ) )
return - V_110 ;
if ( V_34 -> V_39 & V_107 )
return V_34 -> V_39 == V_39 ? 0 : - V_110 ;
if ( V_34 -> V_39 == V_39 )
return 0 ;
V_62 = V_34 -> V_62 -> V_42 ;
V_63 = V_34 -> V_63 -> V_42 ;
if ( ! ( V_34 -> V_39 & V_111 ) &&
( V_62 -> V_81 || V_63 -> V_81 ) )
return - V_82 ;
V_30 = V_62 -> V_59 . V_30 ;
if ( V_30 -> V_112 ) {
V_74 = V_30 -> V_112 ( V_34 , V_39 ,
V_113 ) ;
if ( V_74 < 0 )
return V_74 ;
}
V_74 = F_69 ( V_34 , V_39 ) ;
if ( V_30 -> V_112 )
V_30 -> V_112 ( V_34 , V_39 , V_114 ) ;
return V_74 ;
}
int F_72 ( struct V_33 * V_34 , T_3 V_39 )
{
int V_74 ;
F_45 ( & V_34 -> V_59 . V_30 -> V_75 ) ;
V_74 = F_71 ( V_34 , V_39 ) ;
F_54 ( & V_34 -> V_59 . V_30 -> V_75 ) ;
return V_74 ;
}
struct V_33 *
F_73 ( struct V_37 * V_62 , struct V_37 * V_63 )
{
struct V_33 * V_34 ;
F_48 (link, &source->entity->links, list) {
if ( V_34 -> V_62 -> V_42 == V_62 -> V_42 &&
V_34 -> V_62 -> V_43 == V_62 -> V_43 &&
V_34 -> V_63 -> V_42 == V_63 -> V_42 &&
V_34 -> V_63 -> V_43 == V_63 -> V_43 )
return V_34 ;
}
return NULL ;
}
struct V_37 * F_74 ( struct V_37 * V_38 )
{
struct V_33 * V_34 ;
F_48 (link, &pad->entity->links, list) {
if ( ! ( V_34 -> V_39 & V_70 ) )
continue;
if ( V_34 -> V_62 == V_38 )
return V_34 -> V_63 ;
if ( V_34 -> V_63 == V_38 )
return V_34 -> V_62 ;
}
return NULL ;
}
static void F_75 ( struct V_48 * V_30 ,
struct V_6 * V_7 ,
T_3 F_1 ,
T_3 F_2 , T_3 V_39 )
{
V_7 -> type = F_2 ;
V_7 -> V_39 = V_39 ;
F_76 ( & V_7 -> V_53 ) ;
F_19 ( V_30 , F_1 , & V_7 -> V_59 ) ;
}
struct V_44 * F_77 ( struct V_48 * V_30 ,
T_3 type , T_3 V_39 ,
T_3 V_46 , T_3 V_47 )
{
struct V_44 * V_45 ;
V_45 = F_61 ( sizeof( * V_45 ) , V_23 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_46 = V_46 ;
V_45 -> V_47 = V_47 ;
F_75 ( V_30 , & V_45 -> V_7 , V_5 ,
type , V_39 ) ;
return V_45 ;
}
void F_78 ( struct V_44 * V_45 )
{
F_79 ( & V_45 -> V_7 ) ;
F_23 ( & V_45 -> V_7 . V_59 ) ;
F_8 ( V_45 ) ;
}
struct V_33 * F_80 ( struct V_57 * V_42 ,
struct V_6 * V_7 ,
T_3 V_39 )
{
struct V_33 * V_34 ;
V_34 = F_60 ( & V_7 -> V_53 ) ;
if ( V_34 == NULL )
return NULL ;
V_34 -> V_7 = V_7 ;
V_34 -> V_42 = V_42 ;
V_34 -> V_39 = V_39 | V_101 ;
F_19 ( V_7 -> V_59 . V_30 , V_4 ,
& V_34 -> V_59 ) ;
return V_34 ;
}
void F_81 ( struct V_33 * V_34 )
{
F_24 ( & V_34 -> V_50 ) ;
F_23 ( & V_34 -> V_59 ) ;
F_8 ( V_34 ) ;
}
void F_82 ( struct V_33 * V_34 )
{
struct V_48 * V_30 = V_34 -> V_59 . V_30 ;
if ( V_30 == NULL )
return;
F_26 ( & V_30 -> V_61 ) ;
F_81 ( V_34 ) ;
F_27 ( & V_30 -> V_61 ) ;
}
void F_83 ( struct V_6 * V_7 )
{
struct V_33 * V_34 , * V_93 ;
F_63 (link, tmp, &intf->links, list)
F_81 ( V_34 ) ;
}
void F_79 ( struct V_6 * V_7 )
{
struct V_48 * V_30 = V_7 -> V_59 . V_30 ;
if ( V_30 == NULL )
return;
F_26 ( & V_30 -> V_61 ) ;
F_83 ( V_7 ) ;
F_27 ( & V_30 -> V_61 ) ;
}
