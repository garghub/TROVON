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
void F_4 ( struct V_7 * V_8 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_12 * V_13 ;
F_6 ( V_2 -> V_14 ) ;
V_13 = F_7 ( V_11 , V_2 ) ;
F_8 ( V_2 -> V_14 ) ;
if ( ! V_13 ) {
V_13 = F_9 ( V_11 , V_2 , V_15 ) ;
if ( ! V_13 )
return;
}
F_10 ( V_13 -> V_11 ) ;
V_8 -> V_16 . V_13 = V_13 ;
}
static void F_11 ( struct V_3 * V_4 )
{
if ( F_12 ( V_17 , & V_4 -> V_18 ) )
return;
if ( V_4 -> V_19 & V_20 ) {
struct V_1 * V_2 = V_4 -> V_21 ;
if ( ! F_13 ( V_17 , & V_4 -> V_18 ) )
F_14 ( & V_2 -> V_22 ) ;
} else
F_15 ( V_17 , & V_4 -> V_18 ) ;
}
static bool F_16 ( struct V_3 * V_4 )
{
if ( ! F_12 ( V_17 , & V_4 -> V_18 ) )
return false ;
if ( V_4 -> V_19 & V_20 ) {
struct V_1 * V_2 = V_4 -> V_21 ;
if ( F_17 ( V_17 , & V_4 -> V_18 ) )
F_18 ( & V_2 -> V_22 ) ;
} else
F_19 ( V_17 , & V_4 -> V_18 ) ;
if ( F_20 ( V_4 ) ) {
F_21 ( V_4 , true ) ;
return true ;
}
return false ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_21 ;
struct V_23 * V_24 = V_2 -> V_25 ;
const bool V_26 = V_24 && V_24 -> type -> V_27 . V_28 . V_29 ;
bool V_30 = false ;
F_23 ( V_31 ) ;
if ( F_24 ( F_25 ( V_4 ) || F_26 ( V_2 ) ) )
return;
V_4 -> V_32 ++ ;
if ( ! F_27 ( & V_4 -> V_33 ) ) {
F_28 ( & V_4 -> V_34 ) ;
if ( ! F_29 ( & V_4 -> V_33 ) )
F_30 ( & V_4 -> V_33 , & V_31 ) ;
F_31 ( & V_4 -> V_34 ) ;
}
if ( ! F_29 ( & V_31 ) ) {
F_11 ( V_4 ) ;
V_30 = F_32 ( V_2 , & V_31 ) ;
} else if ( ! V_26 ) {
F_33 ( V_4 , & V_31 ) ;
F_32 ( V_2 , & V_31 ) ;
}
if ( ! V_30 && V_26 ) {
do {
struct V_7 * V_8 ;
V_8 = V_24 -> type -> V_27 . V_28 . V_29 ( V_4 ) ;
if ( ! V_8 )
break;
F_34 ( & V_8 -> V_35 , & V_31 ) ;
} while ( F_32 ( V_2 , & V_31 ) );
}
}
bool F_35 ( struct V_1 * V_2 , struct V_9 * V_9 ,
struct V_7 * * V_36 )
{
struct V_7 * V_8 ;
switch ( F_36 ( V_2 , & V_8 , V_9 ) ) {
case V_37 :
if ( ! F_37 ( V_2 , V_8 , V_9 ) )
return false ;
if ( ! F_38 ( V_2 , V_8 , V_9 ) )
return false ;
* V_36 = F_39 ( V_2 , V_8 ) ;
if ( ! * V_36 )
F_40 ( V_2 , V_8 , V_37 ) ;
return true ;
case V_38 :
if ( ! F_37 ( V_2 , V_8 , V_9 ) )
return false ;
if ( ! F_41 ( V_2 , V_8 , V_9 ) )
return false ;
* V_36 = F_42 ( V_2 , V_8 ) ;
if ( ! * V_36 )
F_40 ( V_2 , V_8 , V_38 ) ;
return true ;
default:
return false ;
}
}
static bool F_43 ( struct V_1 * V_2 ,
struct V_39 * V_40 , struct V_9 * V_9 )
{
struct V_7 * V_8 ;
int V_41 = 8 ;
F_44 ( & V_40 -> V_34 ) ;
F_45 (rq, &ctx->rq_list, queuelist) {
bool V_42 = false ;
if ( ! V_41 -- )
break;
if ( ! F_46 ( V_8 , V_9 ) )
continue;
switch ( F_47 ( V_8 , V_9 ) ) {
case V_37 :
if ( F_37 ( V_2 , V_8 , V_9 ) )
V_42 = F_38 ( V_2 , V_8 , V_9 ) ;
break;
case V_38 :
if ( F_37 ( V_2 , V_8 , V_9 ) )
V_42 = F_41 ( V_2 , V_8 , V_9 ) ;
break;
case V_43 :
V_42 = F_48 ( V_2 , V_8 , V_9 ) ;
break;
default:
continue;
}
if ( V_42 )
V_40 -> V_44 ++ ;
return V_42 ;
}
return false ;
}
bool F_49 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_39 * V_40 = F_50 ( V_2 ) ;
struct V_3 * V_4 = F_51 ( V_2 , V_40 -> V_45 ) ;
bool V_46 = false ;
if ( V_24 && V_24 -> type -> V_27 . V_28 . V_47 ) {
F_52 ( V_40 ) ;
return V_24 -> type -> V_27 . V_28 . V_47 ( V_4 , V_9 ) ;
}
if ( V_4 -> V_19 & V_48 ) {
F_28 ( & V_40 -> V_34 ) ;
V_46 = F_43 ( V_2 , V_40 , V_9 ) ;
F_31 ( & V_40 -> V_34 ) ;
}
F_52 ( V_40 ) ;
return V_46 ;
}
bool F_53 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
return F_54 ( V_8 ) && F_55 ( V_2 , V_8 ) ;
}
void F_56 ( struct V_7 * V_8 )
{
F_57 ( V_8 -> V_2 , V_8 ) ;
}
static bool F_58 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_49 == - 1 ) {
V_8 -> V_50 |= V_51 ;
return false ;
}
F_28 ( & V_4 -> V_34 ) ;
F_34 ( & V_8 -> V_35 , & V_4 -> V_33 ) ;
F_31 ( & V_4 -> V_34 ) ;
return true ;
}
void F_59 ( struct V_3 * const V_4 )
{
struct V_52 * const V_53 = V_4 -> V_53 ;
struct V_54 * const V_55 = V_4 -> V_21 -> V_56 ;
struct V_1 * const V_21 = V_4 -> V_21 , * V_2 ;
struct V_3 * V_57 ;
unsigned int V_5 , V_58 ;
if ( V_55 -> V_19 & V_20 ) {
if ( ! F_60 ( & V_21 -> V_22 ) )
return;
F_61 () ;
F_62 (q, queue, &set->tag_list,
tag_set_list) {
F_2 (q, hctx2, i)
if ( V_57 -> V_53 == V_53 &&
F_16 ( V_57 ) )
goto V_59;
}
V_58 = V_4 -> V_60 + 1 ;
for ( V_5 = 0 ; V_5 < V_21 -> V_61 ; V_5 ++ , V_58 ++ ) {
if ( V_58 == V_21 -> V_61 )
V_58 = 0 ;
V_57 = V_21 -> V_62 [ V_58 ] ;
if ( V_57 -> V_53 == V_53 &&
F_16 ( V_57 ) )
break;
}
V_59:
F_63 () ;
} else {
F_16 ( V_4 ) ;
}
}
static void F_64 ( struct V_3 * V_4 ,
struct V_7 * V_8 , bool V_63 )
{
if ( F_65 ( V_8 , & V_4 , V_63 ) ) {
F_66 ( V_8 ) ;
F_21 ( V_4 , true ) ;
} else
F_67 ( V_8 , false , true ) ;
}
void F_68 ( struct V_7 * V_8 , bool V_64 ,
bool V_65 , bool V_66 , bool V_63 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_39 * V_40 = V_8 -> V_67 ;
struct V_3 * V_4 = F_51 ( V_2 , V_40 -> V_45 ) ;
if ( V_8 -> V_49 == - 1 && F_69 ( V_8 -> V_68 ) ) {
F_64 ( V_4 , V_8 , V_63 ) ;
return;
}
if ( V_24 && F_58 ( V_4 , V_8 ) )
goto V_32;
if ( V_24 && V_24 -> type -> V_27 . V_28 . V_69 ) {
F_23 ( V_70 ) ;
F_34 ( & V_8 -> V_35 , & V_70 ) ;
V_24 -> type -> V_27 . V_28 . V_69 ( V_4 , & V_70 , V_64 ) ;
} else {
F_28 ( & V_40 -> V_34 ) ;
F_70 ( V_4 , V_8 , V_64 ) ;
F_31 ( & V_40 -> V_34 ) ;
}
V_32:
if ( V_65 )
F_21 ( V_4 , V_66 ) ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_71 * V_70 , bool V_72 )
{
struct V_3 * V_4 = F_51 ( V_2 , V_40 -> V_45 ) ;
struct V_23 * V_24 = V_4 -> V_21 -> V_25 ;
if ( V_24 ) {
struct V_7 * V_8 , * V_73 ;
F_72 (rq, next, list, queuelist) {
if ( F_73 ( V_8 -> V_49 != - 1 ) ) {
F_74 ( & V_8 -> V_35 ) ;
F_58 ( V_4 , V_8 ) ;
}
}
}
if ( V_24 && V_24 -> type -> V_27 . V_28 . V_69 )
V_24 -> type -> V_27 . V_28 . V_69 ( V_4 , V_70 , false ) ;
else
F_75 ( V_4 , V_40 , V_70 ) ;
F_21 ( V_4 , V_72 ) ;
}
static void F_76 ( struct V_54 * V_55 ,
struct V_3 * V_4 ,
unsigned int V_74 )
{
if ( V_4 -> V_75 ) {
F_77 ( V_55 , V_4 -> V_75 , V_74 ) ;
F_78 ( V_4 -> V_75 ) ;
V_4 -> V_75 = NULL ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_74 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
int V_46 ;
V_4 -> V_75 = F_80 ( V_55 , V_74 , V_2 -> V_76 ,
V_55 -> V_77 ) ;
if ( ! V_4 -> V_75 )
return - V_78 ;
V_46 = F_81 ( V_55 , V_4 -> V_75 , V_74 , V_2 -> V_76 ) ;
if ( V_46 )
F_76 ( V_55 , V_4 , V_74 ) ;
return V_46 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
struct V_3 * V_4 ;
int V_5 ;
F_2 (q, hctx, i)
F_76 ( V_55 , V_4 , V_5 ) ;
}
int F_83 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_74 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_46 ;
if ( ! V_24 )
return 0 ;
V_46 = F_79 ( V_2 , V_4 , V_74 ) ;
if ( V_46 )
return V_46 ;
if ( V_24 -> type -> V_27 . V_28 . V_79 ) {
V_46 = V_24 -> type -> V_27 . V_28 . V_79 ( V_4 , V_74 ) ;
if ( V_46 ) {
F_76 ( V_2 -> V_56 , V_4 , V_74 ) ;
return V_46 ;
}
}
F_84 ( V_2 , V_4 ) ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_74 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
if ( ! V_24 )
return;
F_86 ( V_4 ) ;
if ( V_24 -> type -> V_27 . V_28 . V_80 && V_4 -> V_6 ) {
V_24 -> type -> V_27 . V_28 . V_80 ( V_4 , V_74 ) ;
V_4 -> V_6 = NULL ;
}
F_76 ( V_2 -> V_56 , V_4 , V_74 ) ;
}
int F_87 ( struct V_1 * V_2 , struct V_81 * V_24 )
{
struct V_3 * V_4 ;
struct V_23 * V_82 ;
unsigned int V_5 ;
int V_46 ;
if ( ! V_24 ) {
V_2 -> V_25 = NULL ;
return 0 ;
}
V_2 -> V_76 = 2 * F_88 (unsigned int, q->tag_set->queue_depth,
BLKDEV_MAX_RQ) ;
F_2 (q, hctx, i) {
V_46 = F_79 ( V_2 , V_4 , V_5 ) ;
if ( V_46 )
goto V_83;
}
V_46 = V_24 -> V_27 . V_28 . V_84 ( V_2 , V_24 ) ;
if ( V_46 )
goto V_83;
F_89 ( V_2 ) ;
F_2 (q, hctx, i) {
if ( V_24 -> V_27 . V_28 . V_79 ) {
V_46 = V_24 -> V_27 . V_28 . V_79 ( V_4 , V_5 ) ;
if ( V_46 ) {
V_82 = V_2 -> V_25 ;
F_90 ( V_2 , V_82 ) ;
F_91 ( & V_82 -> V_85 ) ;
return V_46 ;
}
}
F_84 ( V_2 , V_4 ) ;
}
return 0 ;
V_83:
F_82 ( V_2 ) ;
V_2 -> V_25 = NULL ;
return V_46 ;
}
void F_90 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
F_2 (q, hctx, i) {
F_86 ( V_4 ) ;
if ( V_24 -> type -> V_27 . V_28 . V_80 && V_4 -> V_6 ) {
V_24 -> type -> V_27 . V_28 . V_80 ( V_4 , V_5 ) ;
V_4 -> V_6 = NULL ;
}
}
F_92 ( V_2 ) ;
if ( V_24 -> type -> V_27 . V_28 . V_86 )
V_24 -> type -> V_27 . V_28 . V_86 ( V_24 ) ;
F_82 ( V_2 ) ;
V_2 -> V_25 = NULL ;
}
int F_93 ( struct V_1 * V_2 )
{
int V_46 ;
F_94 ( & V_2 -> V_87 ) ;
V_46 = F_95 ( V_2 , NULL ) ;
F_96 ( & V_2 -> V_87 ) ;
return V_46 ;
}
