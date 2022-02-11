static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_1 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_6 , struct V_5 , V_6 ) ;
}
static int
F_4 ( struct V_1 * V_3 )
{
int V_7 = 0 ;
F_5 ( & V_3 -> V_4 ) ;
F_6 ( & V_3 -> V_8 ) ;
F_7 ( V_3 -> V_9 , NULL ) ;
if ( F_8 ( V_10 , & V_3 -> V_4 . V_11 ) ) {
struct V_5 * V_12 = F_3 ( V_3 ) ;
if ( ! -- V_12 -> V_13 )
V_7 = 1 ;
}
F_9 ( & V_3 -> V_4 ) ;
return V_7 ;
}
static struct V_1 *
F_10 ( struct V_2 * V_3 , struct V_14 * V_15 ) {
struct V_16 * V_17 = ( void * ) V_15 -> V_3 ;
if ( V_3 -> V_18 != & V_19 &&
V_3 -> V_18 != & V_20 )
return NULL ;
if ( V_3 -> V_21 < V_17 -> V_22 ||
V_3 -> V_21 >= V_17 -> V_22 + V_17 -> V_23 )
return NULL ;
return F_1 ( V_3 ) ;
}
void
F_11 ( struct V_5 * V_12 )
{
struct V_1 * V_3 ;
F_12 ( & V_12 -> V_6 ) ;
while ( ! F_13 ( & V_12 -> V_24 ) ) {
V_3 = F_14 ( V_12 -> V_24 . V_25 , F_15 ( * V_3 ) , V_8 ) ;
if ( F_4 ( V_3 ) )
F_16 ( & V_12 -> V_26 ) ;
}
F_17 ( & V_12 -> V_6 ) ;
F_18 ( & V_12 -> V_26 ) ;
V_12 -> V_27 = 1 ;
F_19 () ;
}
static void
F_20 ( struct V_28 * V_29 )
{
F_21 ( F_2 ( V_29 , struct V_5 , V_29 ) ) ;
}
void
F_22 ( struct V_5 * V_12 )
{
F_23 ( & V_12 -> V_29 , F_20 ) ;
}
static int
F_24 ( struct V_30 * V_31 , struct V_5 * V_12 )
{
struct V_1 * V_3 ;
int V_7 = 0 ;
T_1 V_32 = V_12 -> V_33 ( V_31 ) ;
while ( ! F_13 ( & V_12 -> V_24 ) ) {
V_3 = F_14 ( V_12 -> V_24 . V_25 , F_15 ( * V_3 ) , V_8 ) ;
if ( ( int ) ( V_32 - V_3 -> V_4 . V_34 ) < 0 )
break;
V_7 |= F_4 ( V_3 ) ;
}
return V_7 ;
}
static int
F_25 ( struct V_35 * V_26 )
{
struct V_5 * V_12 =
F_2 ( V_26 , F_15 ( * V_12 ) , V_26 ) ;
unsigned long V_11 ;
int V_36 = V_37 ;
F_26 ( & V_12 -> V_6 , V_11 ) ;
if ( ! F_13 ( & V_12 -> V_24 ) ) {
struct V_1 * V_3 ;
struct V_30 * V_31 ;
V_3 = F_14 ( V_12 -> V_24 . V_25 , F_15 ( * V_3 ) , V_8 ) ;
V_31 = F_27 ( V_3 -> V_9 , F_28 ( & V_12 -> V_6 ) ) ;
if ( F_24 ( V_3 -> V_9 , V_12 ) )
V_36 = V_38 ;
}
F_29 ( & V_12 -> V_6 , V_11 ) ;
return V_36 ;
}
void
F_30 ( struct V_30 * V_31 , struct V_5 * V_12 )
{
struct V_16 * V_17 = ( void * ) V_31 -> V_15 -> V_3 ;
struct V_39 * V_40 = ( void * ) V_31 -> V_41 . V_42 ;
int V_36 ;
F_31 ( & V_12 -> V_43 ) ;
F_31 ( & V_12 -> V_24 ) ;
F_32 ( & V_12 -> V_6 ) ;
V_12 -> V_21 = V_17 -> V_22 + V_31 -> V_44 ;
if ( V_31 == V_31 -> V_15 -> V_45 )
strcpy ( V_12 -> V_46 , L_1 ) ;
else if ( V_31 == V_31 -> V_15 -> V_9 )
strcpy ( V_12 -> V_46 , L_2 ) ;
else
strcpy ( V_12 -> V_46 , F_33 ( & V_40 -> V_4 ) -> V_46 ) ;
F_34 ( & V_12 -> V_29 ) ;
if ( ! V_17 -> V_47 )
return;
V_36 = F_35 (&chan->user, nouveau_fence_wait_uevent_handler,
false, G82_CHANNEL_DMA_V0_NTFY_UEVENT,
&(struct nvif_notify_uevent_req) { },
sizeof(struct nvif_notify_uevent_req),
sizeof(struct nvif_notify_uevent_rep),
&fctx->notify) ;
F_36 ( V_36 ) ;
}
static void
F_37 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_2 ( V_49 , F_15 ( * V_51 ) , V_51 ) ;
V_51 -> V_52 ( V_51 -> V_53 ) ;
F_21 ( V_51 ) ;
}
static void F_38 ( struct V_2 * V_3 , struct V_54 * V_55 )
{
struct V_50 * V_51 = F_2 ( V_55 , F_15 ( * V_51 ) , V_55 ) ;
F_39 ( & V_51 -> V_51 ) ;
}
void
V_50 ( struct V_2 * V_3 ,
void (* V_52)( void * ) , void * V_53 )
{
struct V_50 * V_51 ;
if ( F_40 ( V_3 ) )
goto V_56;
V_51 = F_41 ( sizeof( * V_51 ) , V_57 ) ;
if ( ! V_51 ) {
F_36 ( F_42 ( (struct V_1 * ) V_3 ,
true , false ) ) ;
goto V_56;
}
F_43 ( & V_51 -> V_51 , F_37 ) ;
V_51 -> V_52 = V_52 ;
V_51 -> V_53 = V_53 ;
if ( F_44 ( V_3 , & V_51 -> V_55 , F_38 ) < 0 )
goto V_58;
return;
V_58:
F_21 ( V_51 ) ;
V_56:
V_52 ( V_53 ) ;
}
int
F_45 ( struct V_1 * V_3 , struct V_30 * V_31 )
{
struct V_5 * V_12 = V_31 -> V_3 ;
struct V_16 * V_17 = ( void * ) V_31 -> V_15 -> V_3 ;
int V_36 ;
V_3 -> V_9 = V_31 ;
V_3 -> V_59 = V_60 + ( 15 * V_61 ) ;
if ( V_17 -> V_47 )
F_46 ( & V_3 -> V_4 , & V_20 ,
& V_12 -> V_6 , V_12 -> V_21 , ++ V_12 -> V_62 ) ;
else
F_46 ( & V_3 -> V_4 , & V_19 ,
& V_12 -> V_6 , V_12 -> V_21 , ++ V_12 -> V_62 ) ;
F_47 ( & V_12 -> V_29 ) ;
F_48 ( & V_3 -> V_4 ) ;
V_36 = V_12 -> V_63 ( V_3 ) ;
if ( ! V_36 ) {
F_49 ( & V_3 -> V_4 ) ;
F_12 ( & V_12 -> V_6 ) ;
if ( F_24 ( V_31 , V_12 ) )
F_16 ( & V_12 -> V_26 ) ;
F_50 ( & V_3 -> V_8 , & V_12 -> V_24 ) ;
F_17 ( & V_12 -> V_6 ) ;
}
return V_36 ;
}
bool
F_51 ( struct V_1 * V_3 )
{
if ( V_3 -> V_4 . V_18 == & V_19 ||
V_3 -> V_4 . V_18 == & V_20 ) {
struct V_5 * V_12 = F_3 ( V_3 ) ;
struct V_30 * V_31 ;
unsigned long V_11 ;
if ( F_8 ( V_64 , & V_3 -> V_4 . V_11 ) )
return true ;
F_26 ( & V_12 -> V_6 , V_11 ) ;
V_31 = F_27 ( V_3 -> V_9 , F_28 ( & V_12 -> V_6 ) ) ;
if ( V_31 && F_24 ( V_31 , V_12 ) )
F_16 ( & V_12 -> V_26 ) ;
F_29 ( & V_12 -> V_6 , V_11 ) ;
}
return F_40 ( & V_3 -> V_4 ) ;
}
static long
F_52 ( struct V_2 * V_65 , bool V_66 , long V_67 )
{
struct V_1 * V_3 = F_1 ( V_65 ) ;
unsigned long V_68 = V_69 / 1000 ;
unsigned long V_70 = V_60 , V_59 = V_70 + V_67 ;
while ( ! F_51 ( V_3 ) ) {
T_2 V_71 ;
V_70 = V_60 ;
if ( V_67 != V_72 && F_53 ( V_70 , V_59 ) ) {
F_54 ( V_73 ) ;
return 0 ;
}
F_54 ( V_66 ? V_74 :
V_75 ) ;
V_71 = V_68 ;
F_55 ( & V_71 , V_76 ) ;
V_68 *= 2 ;
if ( V_68 > V_69 )
V_68 = V_69 ;
if ( V_66 && F_56 ( V_77 ) )
return - V_78 ;
}
F_54 ( V_73 ) ;
return V_59 - V_70 ;
}
static int
F_57 ( struct V_1 * V_3 , bool V_66 )
{
int V_36 = 0 ;
while ( ! F_51 ( V_3 ) ) {
if ( F_53 ( V_60 , V_3 -> V_59 ) ) {
V_36 = - V_79 ;
break;
}
F_54 ( V_66 ?
V_74 :
V_75 ) ;
if ( V_66 && F_56 ( V_77 ) ) {
V_36 = - V_78 ;
break;
}
}
F_54 ( V_73 ) ;
return V_36 ;
}
int
F_42 ( struct V_1 * V_3 , bool V_80 , bool V_66 )
{
long V_36 ;
if ( ! V_80 )
return F_57 ( V_3 , V_66 ) ;
V_36 = F_58 ( & V_3 -> V_4 , V_66 , 15 * V_61 ) ;
if ( V_36 < 0 )
return V_36 ;
else if ( ! V_36 )
return - V_79 ;
else
return 0 ;
}
int
F_59 ( struct V_81 * V_82 , struct V_30 * V_31 , bool V_83 , bool V_66 )
{
struct V_5 * V_12 = V_31 -> V_3 ;
struct V_2 * V_3 ;
struct V_84 * V_85 = V_82 -> V_86 . V_85 ;
struct V_87 * V_88 ;
struct V_1 * V_65 ;
int V_36 = 0 , V_89 ;
if ( ! V_83 ) {
V_36 = F_60 ( V_85 ) ;
if ( V_36 )
return V_36 ;
}
V_88 = F_61 ( V_85 ) ;
V_3 = F_62 ( V_85 ) ;
if ( V_3 && ( ! V_83 || ! V_88 || ! V_88 -> V_90 ) ) {
struct V_30 * V_91 = NULL ;
bool V_92 = true ;
V_65 = F_10 ( V_3 , V_31 -> V_15 ) ;
if ( V_65 ) {
F_63 () ;
V_91 = F_64 ( V_65 -> V_9 ) ;
if ( V_91 && ( V_91 == V_31 || V_12 -> V_93 ( V_65 , V_91 , V_31 ) == 0 ) )
V_92 = false ;
F_65 () ;
}
if ( V_92 )
V_36 = F_66 ( V_3 , V_66 ) ;
return V_36 ;
}
if ( ! V_83 || ! V_88 )
return V_36 ;
for ( V_89 = 0 ; V_89 < V_88 -> V_90 && ! V_36 ; ++ V_89 ) {
struct V_30 * V_91 = NULL ;
bool V_92 = true ;
V_3 = F_27 ( V_88 -> V_94 [ V_89 ] ,
F_67 ( V_85 ) ) ;
V_65 = F_10 ( V_3 , V_31 -> V_15 ) ;
if ( V_65 ) {
F_63 () ;
V_91 = F_64 ( V_65 -> V_9 ) ;
if ( V_91 && ( V_91 == V_31 || V_12 -> V_93 ( V_65 , V_91 , V_31 ) == 0 ) )
V_92 = false ;
F_65 () ;
}
if ( V_92 )
V_36 = F_66 ( V_3 , V_66 ) ;
}
return V_36 ;
}
void
F_68 ( struct V_1 * * V_95 )
{
if ( * V_95 )
F_9 ( & ( * V_95 ) -> V_4 ) ;
* V_95 = NULL ;
}
int
F_69 ( struct V_30 * V_31 , bool V_96 ,
struct V_1 * * V_95 )
{
struct V_1 * V_3 ;
int V_36 = 0 ;
if ( F_70 ( ! V_31 -> V_3 ) )
return - V_97 ;
V_3 = F_71 ( sizeof( * V_3 ) , V_57 ) ;
if ( ! V_3 )
return - V_98 ;
V_3 -> V_96 = V_96 ;
V_36 = F_45 ( V_3 , V_31 ) ;
if ( V_36 )
F_68 ( & V_3 ) ;
* V_95 = V_3 ;
return V_36 ;
}
static const char * F_72 ( struct V_2 * V_3 )
{
return L_3 ;
}
static const char * F_73 ( struct V_2 * V_65 )
{
struct V_1 * V_3 = F_1 ( V_65 ) ;
struct V_5 * V_12 = F_3 ( V_3 ) ;
return ! V_12 -> V_27 ? V_12 -> V_46 : L_4 ;
}
static bool F_74 ( struct V_2 * V_65 )
{
struct V_1 * V_3 = F_1 ( V_65 ) ;
struct V_5 * V_12 = F_3 ( V_3 ) ;
struct V_30 * V_31 ;
bool V_36 = false ;
F_63 () ;
V_31 = F_64 ( V_3 -> V_9 ) ;
if ( V_31 )
V_36 = ( int ) ( V_12 -> V_33 ( V_31 ) - V_3 -> V_4 . V_34 ) >= 0 ;
F_65 () ;
return V_36 ;
}
static bool F_75 ( struct V_2 * V_65 )
{
struct V_1 * V_3 = F_1 ( V_65 ) ;
F_36 ( F_76 ( & V_3 -> V_4 . V_99 . V_99 ) <= 1 ) ;
if ( F_74 ( V_65 ) ) {
F_6 ( & V_3 -> V_8 ) ;
F_9 ( & V_3 -> V_4 ) ;
return false ;
}
return true ;
}
static void F_77 ( struct V_2 * V_65 )
{
struct V_1 * V_3 = F_1 ( V_65 ) ;
struct V_5 * V_12 = F_3 ( V_3 ) ;
F_23 ( & V_12 -> V_29 , F_20 ) ;
F_78 ( & V_3 -> V_4 ) ;
}
static bool F_79 ( struct V_2 * V_65 )
{
struct V_1 * V_3 = F_1 ( V_65 ) ;
struct V_5 * V_12 = F_3 ( V_3 ) ;
bool V_36 ;
if ( ! V_12 -> V_13 ++ )
F_80 ( & V_12 -> V_26 ) ;
V_36 = F_75 ( V_65 ) ;
if ( V_36 )
F_81 ( V_10 , & V_3 -> V_4 . V_11 ) ;
else if ( ! -- V_12 -> V_13 )
F_16 ( & V_12 -> V_26 ) ;
return V_36 ;
}
