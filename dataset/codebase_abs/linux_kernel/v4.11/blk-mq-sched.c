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
int F_4 ( struct V_1 * V_2 , T_1 V_7 ,
int (* F_5)( struct V_3 * ) ,
void (* exit)( struct V_3 * ) )
{
struct V_3 * V_4 ;
int V_8 ;
int V_5 ;
F_2 (q, hctx, i) {
V_4 -> V_6 = F_6 ( V_7 , V_9 , V_4 -> V_10 ) ;
if ( ! V_4 -> V_6 ) {
V_8 = - V_11 ;
goto error;
}
if ( F_5 ) {
V_8 = F_5 ( V_4 ) ;
if ( V_8 ) {
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
goto error;
}
}
}
return 0 ;
error:
F_1 ( V_2 , exit ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 ;
F_8 ( V_2 -> V_19 ) ;
V_18 = F_9 ( V_16 , V_2 ) ;
F_10 ( V_2 -> V_19 ) ;
if ( ! V_18 ) {
V_18 = F_11 ( V_16 , V_2 , V_20 ) ;
if ( ! V_18 )
return;
}
V_13 -> V_21 . V_18 = V_18 ;
if ( ! F_12 ( V_2 , V_13 , V_14 ) ) {
V_13 -> V_22 |= V_23 ;
F_13 ( V_18 -> V_16 ) ;
return;
}
V_13 -> V_21 . V_18 = NULL ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 , struct V_14 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_15 ( V_14 ) ;
if ( V_16 )
F_7 ( V_2 , V_13 , V_14 , V_16 ) ;
}
struct V_12 * F_16 ( struct V_1 * V_2 ,
struct V_14 * V_14 ,
unsigned int V_24 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
struct V_12 * V_13 ;
F_17 ( V_2 ) ;
V_26 -> V_2 = V_2 ;
if ( F_18 ( ! V_26 -> V_30 ) )
V_26 -> V_30 = F_19 ( V_2 ) ;
if ( F_18 ( ! V_26 -> V_4 ) )
V_26 -> V_4 = F_20 ( V_2 , V_26 -> V_30 -> V_31 ) ;
if ( V_28 ) {
V_26 -> V_32 |= V_33 ;
if ( ! F_21 ( V_24 ) && V_28 -> type -> V_34 . V_35 . V_36 ) {
V_13 = V_28 -> type -> V_34 . V_35 . V_36 ( V_2 , V_24 , V_26 ) ;
if ( V_13 )
V_13 -> V_22 |= V_37 ;
} else
V_13 = F_22 ( V_26 , V_24 ) ;
} else {
V_13 = F_22 ( V_26 , V_24 ) ;
}
if ( V_13 ) {
if ( ! F_21 ( V_24 ) ) {
V_13 -> V_21 . V_18 = NULL ;
if ( V_28 && V_28 -> type -> V_38 )
F_14 ( V_2 , V_13 , V_14 ) ;
}
V_26 -> V_4 -> V_39 ++ ;
return V_13 ;
}
F_23 ( V_2 ) ;
return NULL ;
}
void F_24 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_27 * V_28 = V_2 -> V_29 ;
if ( V_13 -> V_22 & V_23 ) {
F_25 ( V_13 -> V_2 , V_13 ) ;
if ( V_13 -> V_21 . V_18 ) {
F_26 ( V_13 -> V_21 . V_18 -> V_16 ) ;
V_13 -> V_21 . V_18 = NULL ;
}
}
if ( ( V_13 -> V_22 & V_37 ) && V_28 && V_28 -> type -> V_34 . V_35 . V_40 )
V_28 -> type -> V_34 . V_35 . V_40 ( V_13 ) ;
else
F_27 ( V_13 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
struct V_27 * V_28 = V_2 -> V_29 ;
const bool V_42 = V_28 && V_28 -> type -> V_34 . V_35 . V_43 ;
bool V_44 = false ;
F_29 ( V_45 ) ;
if ( F_30 ( F_31 ( V_4 ) ) )
return;
V_4 -> V_46 ++ ;
if ( ! F_32 ( & V_4 -> V_47 ) ) {
F_33 ( & V_4 -> V_48 ) ;
if ( ! F_34 ( & V_4 -> V_47 ) )
F_35 ( & V_4 -> V_47 , & V_45 ) ;
F_36 ( & V_4 -> V_48 ) ;
}
if ( ! F_34 ( & V_45 ) ) {
F_37 ( V_4 ) ;
V_44 = F_38 ( V_2 , & V_45 ) ;
} else if ( ! V_42 ) {
F_39 ( V_4 , & V_45 ) ;
F_38 ( V_2 , & V_45 ) ;
}
if ( ! V_44 && V_42 ) {
do {
struct V_12 * V_13 ;
V_13 = V_28 -> type -> V_34 . V_35 . V_43 ( V_4 ) ;
if ( ! V_13 )
break;
F_40 ( & V_13 -> V_49 , & V_45 ) ;
} while ( F_38 ( V_2 , & V_45 ) );
}
}
bool F_41 ( struct V_1 * V_2 , struct V_14 * V_14 ,
struct V_12 * * V_50 )
{
struct V_12 * V_13 ;
switch ( F_42 ( V_2 , & V_13 , V_14 ) ) {
case V_51 :
if ( ! F_43 ( V_2 , V_13 , V_14 ) )
return false ;
if ( ! F_44 ( V_2 , V_13 , V_14 ) )
return false ;
* V_50 = F_45 ( V_2 , V_13 ) ;
if ( ! * V_50 )
F_46 ( V_2 , V_13 , V_51 ) ;
return true ;
case V_52 :
if ( ! F_43 ( V_2 , V_13 , V_14 ) )
return false ;
if ( ! F_47 ( V_2 , V_13 , V_14 ) )
return false ;
* V_50 = F_48 ( V_2 , V_13 ) ;
if ( ! * V_50 )
F_46 ( V_2 , V_13 , V_52 ) ;
return true ;
default:
return false ;
}
}
bool F_49 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
if ( V_28 -> type -> V_34 . V_35 . V_53 ) {
struct V_54 * V_30 = F_19 ( V_2 ) ;
struct V_3 * V_4 = F_20 ( V_2 , V_30 -> V_31 ) ;
F_50 ( V_30 ) ;
return V_28 -> type -> V_34 . V_35 . V_53 ( V_4 , V_14 ) ;
}
return false ;
}
bool F_51 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_52 ( V_13 ) && F_53 ( V_2 , V_13 ) ;
}
void F_54 ( struct V_12 * V_13 )
{
F_55 ( V_13 -> V_2 , V_13 ) ;
}
static bool F_56 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
if ( V_13 -> V_55 == - 1 ) {
V_13 -> V_22 |= V_56 ;
return false ;
}
F_33 ( & V_4 -> V_48 ) ;
F_40 ( & V_13 -> V_49 , & V_4 -> V_47 ) ;
F_36 ( & V_4 -> V_48 ) ;
return true ;
}
static bool F_57 ( struct V_3 * V_4 )
{
if ( F_58 ( V_57 , & V_4 -> V_58 ) ) {
F_59 ( V_57 , & V_4 -> V_58 ) ;
if ( F_60 ( V_4 ) ) {
F_61 ( V_4 , true ) ;
return true ;
}
}
return false ;
}
void F_62 ( struct V_3 * const V_4 )
{
struct V_59 * const V_60 = V_4 -> V_60 ;
struct V_61 * const V_62 = V_4 -> V_41 -> V_63 ;
struct V_1 * const V_41 = V_4 -> V_41 , * V_2 ;
struct V_3 * V_64 ;
unsigned int V_5 , V_65 ;
if ( V_62 -> V_32 & V_66 ) {
F_63 () ;
F_64 (q, queue, &set->tag_list,
tag_set_list) {
F_2 (q, hctx2, i)
if ( V_64 -> V_60 == V_60 &&
F_57 ( V_64 ) )
goto V_67;
}
V_65 = V_4 -> V_68 + 1 ;
for ( V_5 = 0 ; V_5 < V_41 -> V_69 ; V_5 ++ , V_65 ++ ) {
if ( V_65 == V_41 -> V_69 )
V_65 = 0 ;
V_64 = V_41 -> V_70 [ V_65 ] ;
if ( V_64 -> V_60 == V_60 &&
F_57 ( V_64 ) )
break;
}
V_67:
F_65 () ;
} else {
F_57 ( V_4 ) ;
}
}
static void F_66 ( struct V_3 * V_4 ,
struct V_12 * V_13 , bool V_71 )
{
if ( F_67 ( V_13 , & V_4 , V_71 ) ) {
F_68 ( V_13 ) ;
F_61 ( V_4 , true ) ;
} else
F_69 ( V_13 , false , true ) ;
}
void F_70 ( struct V_12 * V_13 , bool V_72 ,
bool V_73 , bool V_74 , bool V_71 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_27 * V_28 = V_2 -> V_29 ;
struct V_54 * V_30 = V_13 -> V_75 ;
struct V_3 * V_4 = F_20 ( V_2 , V_30 -> V_31 ) ;
if ( V_13 -> V_55 == - 1 && F_21 ( V_13 -> V_76 ) ) {
F_66 ( V_4 , V_13 , V_71 ) ;
return;
}
if ( V_28 && F_56 ( V_4 , V_13 ) )
goto V_46;
if ( V_28 && V_28 -> type -> V_34 . V_35 . V_77 ) {
F_29 ( V_78 ) ;
F_40 ( & V_13 -> V_49 , & V_78 ) ;
V_28 -> type -> V_34 . V_35 . V_77 ( V_4 , & V_78 , V_72 ) ;
} else {
F_33 ( & V_30 -> V_48 ) ;
F_71 ( V_4 , V_13 , V_72 ) ;
F_36 ( & V_30 -> V_48 ) ;
}
V_46:
if ( V_73 )
F_61 ( V_4 , V_74 ) ;
}
void F_72 ( struct V_1 * V_2 ,
struct V_54 * V_30 ,
struct V_79 * V_78 , bool V_80 )
{
struct V_3 * V_4 = F_20 ( V_2 , V_30 -> V_31 ) ;
struct V_27 * V_28 = V_4 -> V_41 -> V_29 ;
if ( V_28 ) {
struct V_12 * V_13 , * V_81 ;
F_73 (rq, next, list, queuelist) {
if ( F_74 ( V_13 -> V_55 != - 1 ) ) {
F_75 ( & V_13 -> V_49 ) ;
F_56 ( V_4 , V_13 ) ;
}
}
}
if ( V_28 && V_28 -> type -> V_34 . V_35 . V_77 )
V_28 -> type -> V_34 . V_35 . V_77 ( V_4 , V_78 , false ) ;
else
F_76 ( V_4 , V_30 , V_78 ) ;
F_61 ( V_4 , V_80 ) ;
}
static void F_77 ( struct V_61 * V_62 ,
struct V_3 * V_4 ,
unsigned int V_82 )
{
if ( V_4 -> V_83 ) {
F_78 ( V_62 , V_4 -> V_83 , V_82 ) ;
F_79 ( V_4 -> V_83 ) ;
V_4 -> V_83 = NULL ;
}
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_82 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
int V_8 ;
V_4 -> V_83 = F_81 ( V_62 , V_82 , V_2 -> V_84 ,
V_62 -> V_85 ) ;
if ( ! V_4 -> V_83 )
return - V_11 ;
V_8 = F_82 ( V_62 , V_4 -> V_83 , V_82 , V_2 -> V_84 ) ;
if ( V_8 )
F_77 ( V_62 , V_4 , V_82 ) ;
return V_8 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
struct V_3 * V_4 ;
int V_5 ;
F_2 (q, hctx, i)
F_77 ( V_62 , V_4 , V_5 ) ;
}
int F_84 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_82 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
if ( ! V_28 )
return 0 ;
return F_80 ( V_2 , V_4 , V_82 ) ;
}
void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_82 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
if ( ! V_28 )
return;
F_77 ( V_2 -> V_63 , V_4 , V_82 ) ;
}
int F_86 ( struct V_1 * V_2 , struct V_86 * V_28 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
int V_8 ;
if ( ! V_28 ) {
V_2 -> V_29 = NULL ;
return 0 ;
}
V_2 -> V_84 = 2 * V_87 ;
F_2 (q, hctx, i) {
V_8 = F_80 ( V_2 , V_4 , V_5 ) ;
if ( V_8 )
goto V_88;
}
V_8 = V_28 -> V_34 . V_35 . V_89 ( V_2 , V_28 ) ;
if ( V_8 )
goto V_88;
return 0 ;
V_88:
F_83 ( V_2 ) ;
V_2 -> V_29 = NULL ;
return V_8 ;
}
void F_87 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
if ( V_28 -> type -> V_34 . V_35 . V_90 )
V_28 -> type -> V_34 . V_35 . V_90 ( V_28 ) ;
F_83 ( V_2 ) ;
V_2 -> V_29 = NULL ;
}
int F_88 ( struct V_1 * V_2 )
{
int V_8 ;
F_89 ( & V_2 -> V_91 ) ;
V_8 = F_90 ( V_2 , NULL ) ;
F_91 ( & V_2 -> V_91 ) ;
return V_8 ;
}
