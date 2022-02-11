void F_1 ( struct V_1 * V_2 ,
void (* exit)( struct V_3 * ) )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 (q, hctx, i) {
if ( exit && V_4 -> V_6 )
exit ( V_4 ) ;
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
F_5 ( V_2 -> V_14 ) ;
V_13 = F_6 ( V_11 , V_2 ) ;
F_7 ( V_2 -> V_14 ) ;
if ( ! V_13 ) {
V_13 = F_8 ( V_11 , V_2 , V_15 ) ;
if ( ! V_13 )
return;
}
V_8 -> V_16 . V_13 = V_13 ;
if ( ! F_9 ( V_2 , V_8 , V_9 ) ) {
V_8 -> V_17 |= V_18 ;
F_10 ( V_13 -> V_11 ) ;
return;
}
V_8 -> V_16 . V_13 = NULL ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_10 * V_11 ;
V_11 = F_12 ( V_9 ) ;
if ( V_11 )
F_4 ( V_2 , V_8 , V_9 , V_11 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( F_14 ( V_19 , & V_4 -> V_20 ) )
return;
if ( V_4 -> V_21 & V_22 ) {
struct V_1 * V_2 = V_4 -> V_23 ;
if ( ! F_15 ( V_19 , & V_4 -> V_20 ) )
F_16 ( & V_2 -> V_24 ) ;
} else
F_17 ( V_19 , & V_4 -> V_20 ) ;
}
static bool F_18 ( struct V_3 * V_4 )
{
if ( ! F_14 ( V_19 , & V_4 -> V_20 ) )
return false ;
if ( V_4 -> V_21 & V_22 ) {
struct V_1 * V_2 = V_4 -> V_23 ;
if ( F_19 ( V_19 , & V_4 -> V_20 ) )
F_20 ( & V_2 -> V_24 ) ;
} else
F_21 ( V_19 , & V_4 -> V_20 ) ;
if ( F_22 ( V_4 ) ) {
F_23 ( V_4 , true ) ;
return true ;
}
return false ;
}
struct V_7 * F_24 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
unsigned int V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_7 * V_8 ;
F_25 ( V_2 ) ;
V_27 -> V_2 = V_2 ;
if ( F_26 ( ! V_27 -> V_31 ) )
V_27 -> V_31 = F_27 ( V_2 ) ;
if ( F_26 ( ! V_27 -> V_4 ) )
V_27 -> V_4 = F_28 ( V_2 , V_27 -> V_31 -> V_32 ) ;
if ( V_29 ) {
V_27 -> V_21 |= V_33 ;
if ( ! F_29 ( V_25 ) && V_29 -> type -> V_34 . V_35 . V_36 ) {
V_8 = V_29 -> type -> V_34 . V_35 . V_36 ( V_2 , V_25 , V_27 ) ;
if ( V_8 )
V_8 -> V_17 |= V_37 ;
} else
V_8 = F_30 ( V_27 , V_25 ) ;
} else {
V_8 = F_30 ( V_27 , V_25 ) ;
}
if ( V_8 ) {
if ( ! F_29 ( V_25 ) ) {
V_8 -> V_16 . V_13 = NULL ;
if ( V_29 && V_29 -> type -> V_38 )
F_11 ( V_2 , V_8 , V_9 ) ;
}
V_27 -> V_4 -> V_39 ++ ;
return V_8 ;
}
F_31 ( V_2 ) ;
return NULL ;
}
void F_32 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_28 * V_29 = V_2 -> V_30 ;
if ( V_8 -> V_17 & V_18 ) {
F_33 ( V_8 -> V_2 , V_8 ) ;
if ( V_8 -> V_16 . V_13 ) {
F_34 ( V_8 -> V_16 . V_13 -> V_11 ) ;
V_8 -> V_16 . V_13 = NULL ;
}
}
if ( ( V_8 -> V_17 & V_37 ) && V_29 && V_29 -> type -> V_34 . V_35 . V_40 )
V_29 -> type -> V_34 . V_35 . V_40 ( V_8 ) ;
else
F_35 ( V_8 ) ;
}
void F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_28 * V_29 = V_2 -> V_30 ;
const bool V_41 = V_29 && V_29 -> type -> V_34 . V_35 . V_42 ;
bool V_43 = false ;
F_37 ( V_44 ) ;
if ( F_38 ( F_39 ( V_4 ) ) )
return;
V_4 -> V_45 ++ ;
if ( ! F_40 ( & V_4 -> V_46 ) ) {
F_41 ( & V_4 -> V_47 ) ;
if ( ! F_42 ( & V_4 -> V_46 ) )
F_43 ( & V_4 -> V_46 , & V_44 ) ;
F_44 ( & V_4 -> V_47 ) ;
}
if ( ! F_42 ( & V_44 ) ) {
F_13 ( V_4 ) ;
V_43 = F_45 ( V_2 , & V_44 ) ;
} else if ( ! V_41 ) {
F_46 ( V_4 , & V_44 ) ;
F_45 ( V_2 , & V_44 ) ;
}
if ( ! V_43 && V_41 ) {
do {
struct V_7 * V_8 ;
V_8 = V_29 -> type -> V_34 . V_35 . V_42 ( V_4 ) ;
if ( ! V_8 )
break;
F_47 ( & V_8 -> V_48 , & V_44 ) ;
} while ( F_45 ( V_2 , & V_44 ) );
}
}
bool F_48 ( struct V_1 * V_2 , struct V_9 * V_9 ,
struct V_7 * * V_49 )
{
struct V_7 * V_8 ;
switch ( F_49 ( V_2 , & V_8 , V_9 ) ) {
case V_50 :
if ( ! F_50 ( V_2 , V_8 , V_9 ) )
return false ;
if ( ! F_51 ( V_2 , V_8 , V_9 ) )
return false ;
* V_49 = F_52 ( V_2 , V_8 ) ;
if ( ! * V_49 )
F_53 ( V_2 , V_8 , V_50 ) ;
return true ;
case V_51 :
if ( ! F_50 ( V_2 , V_8 , V_9 ) )
return false ;
if ( ! F_54 ( V_2 , V_8 , V_9 ) )
return false ;
* V_49 = F_55 ( V_2 , V_8 ) ;
if ( ! * V_49 )
F_53 ( V_2 , V_8 , V_51 ) ;
return true ;
default:
return false ;
}
}
bool F_56 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
if ( V_29 -> type -> V_34 . V_35 . V_52 ) {
struct V_53 * V_31 = F_27 ( V_2 ) ;
struct V_3 * V_4 = F_28 ( V_2 , V_31 -> V_32 ) ;
F_57 ( V_31 ) ;
return V_29 -> type -> V_34 . V_35 . V_52 ( V_4 , V_9 ) ;
}
return false ;
}
bool F_58 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
return F_59 ( V_8 ) && F_60 ( V_2 , V_8 ) ;
}
void F_61 ( struct V_7 * V_8 )
{
F_62 ( V_8 -> V_2 , V_8 ) ;
}
static bool F_63 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_54 == - 1 ) {
V_8 -> V_17 |= V_55 ;
return false ;
}
F_41 ( & V_4 -> V_47 ) ;
F_47 ( & V_8 -> V_48 , & V_4 -> V_46 ) ;
F_44 ( & V_4 -> V_47 ) ;
return true ;
}
void F_64 ( struct V_3 * const V_4 )
{
struct V_56 * const V_57 = V_4 -> V_57 ;
struct V_58 * const V_59 = V_4 -> V_23 -> V_60 ;
struct V_1 * const V_23 = V_4 -> V_23 , * V_2 ;
struct V_3 * V_61 ;
unsigned int V_5 , V_62 ;
if ( V_59 -> V_21 & V_22 ) {
if ( ! F_65 ( & V_23 -> V_24 ) )
return;
F_66 () ;
F_67 (q, queue, &set->tag_list,
tag_set_list) {
F_2 (q, hctx2, i)
if ( V_61 -> V_57 == V_57 &&
F_18 ( V_61 ) )
goto V_63;
}
V_62 = V_4 -> V_64 + 1 ;
for ( V_5 = 0 ; V_5 < V_23 -> V_65 ; V_5 ++ , V_62 ++ ) {
if ( V_62 == V_23 -> V_65 )
V_62 = 0 ;
V_61 = V_23 -> V_66 [ V_62 ] ;
if ( V_61 -> V_57 == V_57 &&
F_18 ( V_61 ) )
break;
}
V_63:
F_68 () ;
} else {
F_18 ( V_4 ) ;
}
}
static void F_69 ( struct V_3 * V_4 ,
struct V_7 * V_8 , bool V_67 )
{
if ( F_70 ( V_8 , & V_4 , V_67 ) ) {
F_71 ( V_8 ) ;
F_23 ( V_4 , true ) ;
} else
F_72 ( V_8 , false , true ) ;
}
void F_73 ( struct V_7 * V_8 , bool V_68 ,
bool V_69 , bool V_70 , bool V_67 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_53 * V_31 = V_8 -> V_71 ;
struct V_3 * V_4 = F_28 ( V_2 , V_31 -> V_32 ) ;
if ( V_8 -> V_54 == - 1 && F_29 ( V_8 -> V_72 ) ) {
F_69 ( V_4 , V_8 , V_67 ) ;
return;
}
if ( V_29 && F_63 ( V_4 , V_8 ) )
goto V_45;
if ( V_29 && V_29 -> type -> V_34 . V_35 . V_73 ) {
F_37 ( V_74 ) ;
F_47 ( & V_8 -> V_48 , & V_74 ) ;
V_29 -> type -> V_34 . V_35 . V_73 ( V_4 , & V_74 , V_68 ) ;
} else {
F_41 ( & V_31 -> V_47 ) ;
F_74 ( V_4 , V_8 , V_68 ) ;
F_44 ( & V_31 -> V_47 ) ;
}
V_45:
if ( V_69 )
F_23 ( V_4 , V_70 ) ;
}
void F_75 ( struct V_1 * V_2 ,
struct V_53 * V_31 ,
struct V_75 * V_74 , bool V_76 )
{
struct V_3 * V_4 = F_28 ( V_2 , V_31 -> V_32 ) ;
struct V_28 * V_29 = V_4 -> V_23 -> V_30 ;
if ( V_29 ) {
struct V_7 * V_8 , * V_77 ;
F_76 (rq, next, list, queuelist) {
if ( F_77 ( V_8 -> V_54 != - 1 ) ) {
F_78 ( & V_8 -> V_48 ) ;
F_63 ( V_4 , V_8 ) ;
}
}
}
if ( V_29 && V_29 -> type -> V_34 . V_35 . V_73 )
V_29 -> type -> V_34 . V_35 . V_73 ( V_4 , V_74 , false ) ;
else
F_79 ( V_4 , V_31 , V_74 ) ;
F_23 ( V_4 , V_76 ) ;
}
static void F_80 ( struct V_58 * V_59 ,
struct V_3 * V_4 ,
unsigned int V_78 )
{
if ( V_4 -> V_79 ) {
F_81 ( V_59 , V_4 -> V_79 , V_78 ) ;
F_82 ( V_4 -> V_79 ) ;
V_4 -> V_79 = NULL ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_78 )
{
struct V_58 * V_59 = V_2 -> V_60 ;
int V_80 ;
V_4 -> V_79 = F_84 ( V_59 , V_78 , V_2 -> V_81 ,
V_59 -> V_82 ) ;
if ( ! V_4 -> V_79 )
return - V_83 ;
V_80 = F_85 ( V_59 , V_4 -> V_79 , V_78 , V_2 -> V_81 ) ;
if ( V_80 )
F_80 ( V_59 , V_4 , V_78 ) ;
return V_80 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = V_2 -> V_60 ;
struct V_3 * V_4 ;
int V_5 ;
F_2 (q, hctx, i)
F_80 ( V_59 , V_4 , V_5 ) ;
}
int F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_78 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
int V_80 ;
if ( ! V_29 )
return 0 ;
V_80 = F_83 ( V_2 , V_4 , V_78 ) ;
if ( V_80 )
return V_80 ;
if ( V_29 -> type -> V_34 . V_35 . V_84 ) {
V_80 = V_29 -> type -> V_34 . V_35 . V_84 ( V_4 , V_78 ) ;
if ( V_80 ) {
F_80 ( V_2 -> V_60 , V_4 , V_78 ) ;
return V_80 ;
}
}
F_88 ( V_2 , V_4 ) ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_78 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
if ( ! V_29 )
return;
F_90 ( V_4 ) ;
if ( V_29 -> type -> V_34 . V_35 . V_85 && V_4 -> V_6 ) {
V_29 -> type -> V_34 . V_35 . V_85 ( V_4 , V_78 ) ;
V_4 -> V_6 = NULL ;
}
F_80 ( V_2 -> V_60 , V_4 , V_78 ) ;
}
int F_91 ( struct V_1 * V_2 , struct V_86 * V_29 )
{
struct V_3 * V_4 ;
struct V_28 * V_87 ;
unsigned int V_5 ;
int V_80 ;
if ( ! V_29 ) {
V_2 -> V_30 = NULL ;
return 0 ;
}
V_2 -> V_81 = 2 * V_88 ;
F_2 (q, hctx, i) {
V_80 = F_83 ( V_2 , V_4 , V_5 ) ;
if ( V_80 )
goto V_89;
}
V_80 = V_29 -> V_34 . V_35 . V_90 ( V_2 , V_29 ) ;
if ( V_80 )
goto V_89;
F_92 ( V_2 ) ;
F_2 (q, hctx, i) {
if ( V_29 -> V_34 . V_35 . V_84 ) {
V_80 = V_29 -> V_34 . V_35 . V_84 ( V_4 , V_5 ) ;
if ( V_80 ) {
V_87 = V_2 -> V_30 ;
F_93 ( V_2 , V_87 ) ;
F_94 ( & V_87 -> V_91 ) ;
return V_80 ;
}
}
F_88 ( V_2 , V_4 ) ;
}
return 0 ;
V_89:
F_86 ( V_2 ) ;
V_2 -> V_30 = NULL ;
return V_80 ;
}
void F_93 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
F_2 (q, hctx, i) {
F_90 ( V_4 ) ;
if ( V_29 -> type -> V_34 . V_35 . V_85 && V_4 -> V_6 ) {
V_29 -> type -> V_34 . V_35 . V_85 ( V_4 , V_5 ) ;
V_4 -> V_6 = NULL ;
}
}
F_95 ( V_2 ) ;
if ( V_29 -> type -> V_34 . V_35 . V_92 )
V_29 -> type -> V_34 . V_35 . V_92 ( V_29 ) ;
F_86 ( V_2 ) ;
V_2 -> V_30 = NULL ;
}
int F_96 ( struct V_1 * V_2 )
{
int V_80 ;
F_97 ( & V_2 -> V_93 ) ;
V_80 = F_98 ( V_2 , NULL ) ;
F_99 ( & V_2 -> V_93 ) ;
return V_80 ;
}
