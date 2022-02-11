static inline struct V_1 *
F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
static inline struct V_4 *
F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_5 , struct V_4 , V_5 ) ;
}
static int
F_4 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
F_5 ( & V_2 -> V_3 ) ;
F_6 ( & V_2 -> V_7 ) ;
F_7 ( V_2 -> V_8 , NULL ) ;
if ( F_8 ( V_9 , & V_2 -> V_3 . V_10 ) ) {
struct V_4 * V_11 = F_3 ( V_2 ) ;
if ( ! -- V_11 -> V_12 )
V_6 = 1 ;
}
F_9 ( & V_2 -> V_3 ) ;
return V_6 ;
}
static struct V_1 *
F_10 ( struct V_2 * V_2 , struct V_13 * V_14 ) {
struct V_15 * V_16 = ( void * ) V_14 -> V_2 ;
if ( V_2 -> V_17 != & V_18 &&
V_2 -> V_17 != & V_19 )
return NULL ;
if ( V_2 -> V_20 < V_16 -> V_21 ||
V_2 -> V_20 >= V_16 -> V_21 + V_16 -> V_22 )
return NULL ;
return F_1 ( V_2 ) ;
}
void
F_11 ( struct V_4 * V_11 )
{
struct V_1 * V_2 ;
F_12 ( & V_11 -> V_5 ) ;
while ( ! F_13 ( & V_11 -> V_23 ) ) {
V_2 = F_14 ( V_11 -> V_23 . V_24 , F_15 ( * V_2 ) , V_7 ) ;
if ( F_4 ( V_2 ) )
F_16 ( & V_11 -> V_25 ) ;
}
F_17 ( & V_11 -> V_5 ) ;
F_18 ( & V_11 -> V_25 ) ;
V_11 -> V_26 = 1 ;
F_19 () ;
}
static void
F_20 ( struct V_27 * V_28 )
{
F_21 ( F_2 ( V_28 , struct V_4 , V_28 ) ) ;
}
void
F_22 ( struct V_4 * V_11 )
{
F_23 ( & V_11 -> V_28 , F_20 ) ;
}
static int
F_24 ( struct V_29 * V_30 , struct V_4 * V_11 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
T_1 V_31 = V_11 -> V_32 ( V_30 ) ;
while ( ! F_13 ( & V_11 -> V_23 ) ) {
V_2 = F_14 ( V_11 -> V_23 . V_24 , F_15 ( * V_2 ) , V_7 ) ;
if ( ( int ) ( V_31 - V_2 -> V_3 . V_33 ) < 0 )
break;
V_6 |= F_4 ( V_2 ) ;
}
return V_6 ;
}
static int
F_25 ( struct V_34 * V_25 )
{
struct V_4 * V_11 =
F_2 ( V_25 , F_15 ( * V_11 ) , V_25 ) ;
unsigned long V_10 ;
int V_35 = V_36 ;
F_26 ( & V_11 -> V_5 , V_10 ) ;
if ( ! F_13 ( & V_11 -> V_23 ) ) {
struct V_1 * V_2 ;
struct V_29 * V_30 ;
V_2 = F_14 ( V_11 -> V_23 . V_24 , F_15 ( * V_2 ) , V_7 ) ;
V_30 = F_27 ( V_2 -> V_8 , F_28 ( & V_11 -> V_5 ) ) ;
if ( F_24 ( V_2 -> V_8 , V_11 ) )
V_35 = V_37 ;
}
F_29 ( & V_11 -> V_5 , V_10 ) ;
return V_35 ;
}
void
F_30 ( struct V_29 * V_30 , struct V_4 * V_11 )
{
struct V_15 * V_16 = ( void * ) V_30 -> V_14 -> V_2 ;
struct V_38 * V_39 = ( void * ) V_30 -> V_40 . V_41 ;
int V_35 ;
F_31 ( & V_11 -> V_42 ) ;
F_31 ( & V_11 -> V_23 ) ;
F_32 ( & V_11 -> V_5 ) ;
V_11 -> V_20 = V_16 -> V_21 + V_30 -> V_43 ;
if ( V_30 == V_30 -> V_14 -> V_44 )
strcpy ( V_11 -> V_45 , L_1 ) ;
else if ( V_30 == V_30 -> V_14 -> V_8 )
strcpy ( V_11 -> V_45 , L_2 ) ;
else
strcpy ( V_11 -> V_45 , F_33 ( & V_39 -> V_3 ) -> V_45 ) ;
F_34 ( & V_11 -> V_28 ) ;
if ( ! V_16 -> V_46 )
return;
V_35 = F_35 (&chan->user, nouveau_fence_wait_uevent_handler,
false, G82_CHANNEL_DMA_V0_NTFY_UEVENT,
&(struct nvif_notify_uevent_req) { },
sizeof(struct nvif_notify_uevent_req),
sizeof(struct nvif_notify_uevent_rep),
&fctx->notify) ;
F_36 ( V_35 ) ;
}
static void
F_37 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_2 ( V_48 , F_15 ( * V_50 ) , V_50 ) ;
V_50 -> V_51 ( V_50 -> V_52 ) ;
F_21 ( V_50 ) ;
}
static void F_38 ( struct V_2 * V_2 , struct V_53 * V_54 )
{
struct V_49 * V_50 = F_2 ( V_54 , F_15 ( * V_50 ) , V_54 ) ;
F_39 ( & V_50 -> V_50 ) ;
}
void
V_49 ( struct V_2 * V_2 ,
void (* V_51)( void * ) , void * V_52 )
{
struct V_49 * V_50 ;
if ( F_40 ( V_2 ) )
goto V_55;
V_50 = F_41 ( sizeof( * V_50 ) , V_56 ) ;
if ( ! V_50 ) {
F_36 ( F_42 ( (struct V_1 * ) V_2 ,
true , false ) ) ;
goto V_55;
}
F_43 ( & V_50 -> V_50 , F_37 ) ;
V_50 -> V_51 = V_51 ;
V_50 -> V_52 = V_52 ;
if ( F_44 ( V_2 , & V_50 -> V_54 , F_38 ) < 0 )
goto V_57;
return;
V_57:
F_21 ( V_50 ) ;
V_55:
V_51 ( V_52 ) ;
}
int
F_45 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_4 * V_11 = V_30 -> V_2 ;
struct V_15 * V_16 = ( void * ) V_30 -> V_14 -> V_2 ;
int V_35 ;
V_2 -> V_8 = V_30 ;
V_2 -> V_58 = V_59 + ( 15 * V_60 ) ;
if ( V_16 -> V_46 )
F_46 ( & V_2 -> V_3 , & V_19 ,
& V_11 -> V_5 , V_11 -> V_20 , ++ V_11 -> V_61 ) ;
else
F_46 ( & V_2 -> V_3 , & V_18 ,
& V_11 -> V_5 , V_11 -> V_20 , ++ V_11 -> V_61 ) ;
F_47 ( & V_11 -> V_28 ) ;
F_48 ( & V_2 -> V_3 ) ;
V_35 = V_11 -> V_62 ( V_2 ) ;
if ( ! V_35 ) {
F_49 ( & V_2 -> V_3 ) ;
F_12 ( & V_11 -> V_5 ) ;
if ( F_24 ( V_30 , V_11 ) )
F_16 ( & V_11 -> V_25 ) ;
F_50 ( & V_2 -> V_7 , & V_11 -> V_23 ) ;
F_17 ( & V_11 -> V_5 ) ;
}
return V_35 ;
}
bool
F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_17 == & V_18 ||
V_2 -> V_3 . V_17 == & V_19 ) {
struct V_4 * V_11 = F_3 ( V_2 ) ;
struct V_29 * V_30 ;
unsigned long V_10 ;
if ( F_8 ( V_63 , & V_2 -> V_3 . V_10 ) )
return true ;
F_26 ( & V_11 -> V_5 , V_10 ) ;
V_30 = F_27 ( V_2 -> V_8 , F_28 ( & V_11 -> V_5 ) ) ;
if ( V_30 && F_24 ( V_30 , V_11 ) )
F_16 ( & V_11 -> V_25 ) ;
F_29 ( & V_11 -> V_5 , V_10 ) ;
}
return F_40 ( & V_2 -> V_3 ) ;
}
static long
F_52 ( struct V_2 * V_64 , bool V_65 , long V_66 )
{
struct V_1 * V_2 = F_1 ( V_64 ) ;
unsigned long V_67 = V_68 / 1000 ;
unsigned long V_69 = V_59 , V_58 = V_69 + V_66 ;
while ( ! F_51 ( V_2 ) ) {
T_2 V_70 ;
V_69 = V_59 ;
if ( V_66 != V_71 && F_53 ( V_69 , V_58 ) ) {
F_54 ( V_72 ) ;
return 0 ;
}
F_54 ( V_65 ? V_73 :
V_74 ) ;
V_70 = F_55 ( 0 , V_67 ) ;
F_56 ( & V_70 , V_75 ) ;
V_67 *= 2 ;
if ( V_67 > V_68 )
V_67 = V_68 ;
if ( V_65 && F_57 ( V_76 ) )
return - V_77 ;
}
F_54 ( V_72 ) ;
return V_58 - V_69 ;
}
static int
F_58 ( struct V_1 * V_2 , bool V_65 )
{
int V_35 = 0 ;
while ( ! F_51 ( V_2 ) ) {
if ( F_53 ( V_59 , V_2 -> V_58 ) ) {
V_35 = - V_78 ;
break;
}
F_54 ( V_65 ?
V_73 :
V_74 ) ;
if ( V_65 && F_57 ( V_76 ) ) {
V_35 = - V_77 ;
break;
}
}
F_54 ( V_72 ) ;
return V_35 ;
}
int
F_42 ( struct V_1 * V_2 , bool V_79 , bool V_65 )
{
long V_35 ;
if ( ! V_79 )
return F_58 ( V_2 , V_65 ) ;
V_35 = F_59 ( & V_2 -> V_3 , V_65 , 15 * V_60 ) ;
if ( V_35 < 0 )
return V_35 ;
else if ( ! V_35 )
return - V_78 ;
else
return 0 ;
}
int
F_60 ( struct V_80 * V_81 , struct V_29 * V_30 , bool V_82 , bool V_65 )
{
struct V_4 * V_11 = V_30 -> V_2 ;
struct V_2 * V_2 ;
struct V_83 * V_84 = V_81 -> V_85 . V_84 ;
struct V_86 * V_87 ;
struct V_1 * V_64 ;
int V_35 = 0 , V_88 ;
if ( ! V_82 ) {
V_35 = F_61 ( V_84 ) ;
if ( V_35 )
return V_35 ;
}
V_87 = F_62 ( V_84 ) ;
V_2 = F_63 ( V_84 ) ;
if ( V_2 && ( ! V_82 || ! V_87 || ! V_87 -> V_89 ) ) {
struct V_29 * V_90 = NULL ;
bool V_91 = true ;
V_64 = F_10 ( V_2 , V_30 -> V_14 ) ;
if ( V_64 ) {
F_64 () ;
V_90 = F_65 ( V_64 -> V_8 ) ;
if ( V_90 && ( V_90 == V_30 || V_11 -> V_92 ( V_64 , V_90 , V_30 ) == 0 ) )
V_91 = false ;
F_66 () ;
}
if ( V_91 )
V_35 = F_67 ( V_2 , V_65 ) ;
return V_35 ;
}
if ( ! V_82 || ! V_87 )
return V_35 ;
for ( V_88 = 0 ; V_88 < V_87 -> V_89 && ! V_35 ; ++ V_88 ) {
struct V_29 * V_90 = NULL ;
bool V_91 = true ;
V_2 = F_27 ( V_87 -> V_93 [ V_88 ] ,
F_68 ( V_84 ) ) ;
V_64 = F_10 ( V_2 , V_30 -> V_14 ) ;
if ( V_64 ) {
F_64 () ;
V_90 = F_65 ( V_64 -> V_8 ) ;
if ( V_90 && ( V_90 == V_30 || V_11 -> V_92 ( V_64 , V_90 , V_30 ) == 0 ) )
V_91 = false ;
F_66 () ;
}
if ( V_91 )
V_35 = F_67 ( V_2 , V_65 ) ;
}
return V_35 ;
}
void
F_69 ( struct V_1 * * V_94 )
{
if ( * V_94 )
F_9 ( & ( * V_94 ) -> V_3 ) ;
* V_94 = NULL ;
}
int
F_70 ( struct V_29 * V_30 , bool V_95 ,
struct V_1 * * V_94 )
{
struct V_1 * V_2 ;
int V_35 = 0 ;
if ( F_71 ( ! V_30 -> V_2 ) )
return - V_96 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_97 ;
V_2 -> V_95 = V_95 ;
V_35 = F_45 ( V_2 , V_30 ) ;
if ( V_35 )
F_69 ( & V_2 ) ;
* V_94 = V_2 ;
return V_35 ;
}
static const char * F_73 ( struct V_2 * V_2 )
{
return L_3 ;
}
static const char * F_74 ( struct V_2 * V_64 )
{
struct V_1 * V_2 = F_1 ( V_64 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
return ! V_11 -> V_26 ? V_11 -> V_45 : L_4 ;
}
static bool F_75 ( struct V_2 * V_64 )
{
struct V_1 * V_2 = F_1 ( V_64 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
struct V_29 * V_30 ;
bool V_35 = false ;
F_64 () ;
V_30 = F_65 ( V_2 -> V_8 ) ;
if ( V_30 )
V_35 = ( int ) ( V_11 -> V_32 ( V_30 ) - V_2 -> V_3 . V_33 ) >= 0 ;
F_66 () ;
return V_35 ;
}
static bool F_76 ( struct V_2 * V_64 )
{
struct V_1 * V_2 = F_1 ( V_64 ) ;
F_36 ( F_77 ( & V_2 -> V_3 . V_98 . V_98 ) <= 1 ) ;
if ( F_75 ( V_64 ) ) {
F_6 ( & V_2 -> V_7 ) ;
F_9 ( & V_2 -> V_3 ) ;
return false ;
}
return true ;
}
static void F_78 ( struct V_2 * V_64 )
{
struct V_1 * V_2 = F_1 ( V_64 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
F_23 ( & V_11 -> V_28 , F_20 ) ;
F_79 ( & V_2 -> V_3 ) ;
}
static bool F_80 ( struct V_2 * V_64 )
{
struct V_1 * V_2 = F_1 ( V_64 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
bool V_35 ;
if ( ! V_11 -> V_12 ++ )
F_81 ( & V_11 -> V_25 ) ;
V_35 = F_76 ( V_64 ) ;
if ( V_35 )
F_82 ( V_9 , & V_2 -> V_3 . V_10 ) ;
else if ( ! -- V_11 -> V_12 )
F_16 ( & V_11 -> V_25 ) ;
return V_35 ;
}
