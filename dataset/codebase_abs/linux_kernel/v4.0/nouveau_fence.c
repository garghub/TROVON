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
struct V_38 * V_39 = ( void * ) F_31 ( V_30 -> V_40 ) ;
int V_35 ;
F_32 ( & V_11 -> V_41 ) ;
F_32 ( & V_11 -> V_23 ) ;
F_33 ( & V_11 -> V_5 ) ;
V_11 -> V_20 = V_16 -> V_21 + V_30 -> V_42 ;
if ( V_30 == V_30 -> V_14 -> V_43 )
strcpy ( V_11 -> V_44 , L_1 ) ;
else if ( V_30 == V_30 -> V_14 -> V_8 )
strcpy ( V_11 -> V_44 , L_2 ) ;
else
strcpy ( V_11 -> V_44 , F_34 ( & V_39 -> V_3 ) -> V_44 ) ;
F_35 ( & V_11 -> V_28 ) ;
if ( ! V_16 -> V_45 )
return;
V_35 = F_36 (chan->object, NULL,
nouveau_fence_wait_uevent_handler, false,
G82_CHANNEL_DMA_V0_NTFY_UEVENT,
&(struct nvif_notify_uevent_req) { },
sizeof(struct nvif_notify_uevent_req),
sizeof(struct nvif_notify_uevent_rep),
&fctx->notify) ;
F_37 ( V_35 ) ;
}
static void
F_38 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_2 ( V_47 , F_15 ( * V_49 ) , V_49 ) ;
V_49 -> V_50 ( V_49 -> V_51 ) ;
F_21 ( V_49 ) ;
}
static void F_39 ( struct V_2 * V_2 , struct V_52 * V_53 )
{
struct V_48 * V_49 = F_2 ( V_53 , F_15 ( * V_49 ) , V_53 ) ;
F_40 ( & V_49 -> V_49 ) ;
}
void
V_48 ( struct V_2 * V_2 ,
void (* V_50)( void * ) , void * V_51 )
{
struct V_48 * V_49 ;
if ( F_41 ( V_2 ) )
goto V_54;
V_49 = F_42 ( sizeof( * V_49 ) , V_55 ) ;
if ( ! V_49 ) {
F_37 ( F_43 ( (struct V_1 * ) V_2 ,
true , false ) ) ;
goto V_54;
}
F_44 ( & V_49 -> V_49 , F_38 ) ;
V_49 -> V_50 = V_50 ;
V_49 -> V_51 = V_51 ;
if ( F_45 ( V_2 , & V_49 -> V_53 , F_39 ) < 0 )
goto V_56;
return;
V_56:
F_21 ( V_49 ) ;
V_54:
V_50 ( V_51 ) ;
}
int
F_46 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_4 * V_11 = V_30 -> V_2 ;
struct V_15 * V_16 = ( void * ) V_30 -> V_14 -> V_2 ;
int V_35 ;
V_2 -> V_8 = V_30 ;
V_2 -> V_57 = V_58 + ( 15 * V_59 ) ;
if ( V_16 -> V_45 )
F_47 ( & V_2 -> V_3 , & V_19 ,
& V_11 -> V_5 , V_11 -> V_20 , ++ V_11 -> V_60 ) ;
else
F_47 ( & V_2 -> V_3 , & V_18 ,
& V_11 -> V_5 , V_11 -> V_20 , ++ V_11 -> V_60 ) ;
F_48 ( & V_11 -> V_28 ) ;
F_49 ( & V_2 -> V_3 ) ;
V_35 = V_11 -> V_61 ( V_2 ) ;
if ( ! V_35 ) {
F_50 ( & V_2 -> V_3 ) ;
F_12 ( & V_11 -> V_5 ) ;
if ( F_24 ( V_30 , V_11 ) )
F_16 ( & V_11 -> V_25 ) ;
F_51 ( & V_2 -> V_7 , & V_11 -> V_23 ) ;
F_17 ( & V_11 -> V_5 ) ;
}
return V_35 ;
}
bool
F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_17 == & V_18 ||
V_2 -> V_3 . V_17 == & V_19 ) {
struct V_4 * V_11 = F_3 ( V_2 ) ;
struct V_29 * V_30 ;
unsigned long V_10 ;
if ( F_8 ( V_62 , & V_2 -> V_3 . V_10 ) )
return true ;
F_26 ( & V_11 -> V_5 , V_10 ) ;
V_30 = F_27 ( V_2 -> V_8 , F_28 ( & V_11 -> V_5 ) ) ;
if ( V_30 && F_24 ( V_30 , V_11 ) )
F_16 ( & V_11 -> V_25 ) ;
F_29 ( & V_11 -> V_5 , V_10 ) ;
}
return F_41 ( & V_2 -> V_3 ) ;
}
static long
F_53 ( struct V_2 * V_63 , bool V_64 , long V_65 )
{
struct V_1 * V_2 = F_1 ( V_63 ) ;
unsigned long V_66 = V_67 / 1000 ;
unsigned long V_68 = V_58 , V_57 = V_68 + V_65 ;
while ( ! F_52 ( V_2 ) ) {
T_2 V_69 ;
V_68 = V_58 ;
if ( V_65 != V_70 && F_54 ( V_68 , V_57 ) ) {
F_55 ( V_71 ) ;
return 0 ;
}
F_55 ( V_64 ? V_72 :
V_73 ) ;
V_69 = F_56 ( 0 , V_66 ) ;
F_57 ( & V_69 , V_74 ) ;
V_66 *= 2 ;
if ( V_66 > V_67 )
V_66 = V_67 ;
if ( V_64 && F_58 ( V_75 ) )
return - V_76 ;
}
F_55 ( V_71 ) ;
return V_57 - V_68 ;
}
static int
F_59 ( struct V_1 * V_2 , bool V_64 )
{
int V_35 = 0 ;
while ( ! F_52 ( V_2 ) ) {
if ( F_54 ( V_58 , V_2 -> V_57 ) ) {
V_35 = - V_77 ;
break;
}
F_55 ( V_64 ?
V_72 :
V_73 ) ;
if ( V_64 && F_58 ( V_75 ) ) {
V_35 = - V_76 ;
break;
}
}
F_55 ( V_71 ) ;
return V_35 ;
}
int
F_43 ( struct V_1 * V_2 , bool V_78 , bool V_64 )
{
long V_35 ;
if ( ! V_78 )
return F_59 ( V_2 , V_64 ) ;
V_35 = F_60 ( & V_2 -> V_3 , V_64 , 15 * V_59 ) ;
if ( V_35 < 0 )
return V_35 ;
else if ( ! V_35 )
return - V_77 ;
else
return 0 ;
}
int
F_61 ( struct V_79 * V_80 , struct V_29 * V_30 , bool V_81 , bool V_64 )
{
struct V_4 * V_11 = V_30 -> V_2 ;
struct V_2 * V_2 ;
struct V_82 * V_83 = V_80 -> V_84 . V_83 ;
struct V_85 * V_86 ;
struct V_1 * V_63 ;
int V_35 = 0 , V_87 ;
if ( ! V_81 ) {
V_35 = F_62 ( V_83 ) ;
if ( V_35 )
return V_35 ;
}
V_86 = F_63 ( V_83 ) ;
V_2 = F_64 ( V_83 ) ;
if ( V_2 && ( ! V_81 || ! V_86 || ! V_86 -> V_88 ) ) {
struct V_29 * V_89 = NULL ;
bool V_90 = true ;
V_63 = F_10 ( V_2 , V_30 -> V_14 ) ;
if ( V_63 ) {
F_65 () ;
V_89 = F_66 ( V_63 -> V_8 ) ;
if ( V_89 && ( V_89 == V_30 || V_11 -> V_91 ( V_63 , V_89 , V_30 ) == 0 ) )
V_90 = false ;
F_67 () ;
}
if ( V_90 )
V_35 = F_68 ( V_2 , V_64 ) ;
return V_35 ;
}
if ( ! V_81 || ! V_86 )
return V_35 ;
for ( V_87 = 0 ; V_87 < V_86 -> V_88 && ! V_35 ; ++ V_87 ) {
struct V_29 * V_89 = NULL ;
bool V_90 = true ;
V_2 = F_27 ( V_86 -> V_92 [ V_87 ] ,
F_69 ( V_83 ) ) ;
V_63 = F_10 ( V_2 , V_30 -> V_14 ) ;
if ( V_63 ) {
F_65 () ;
V_89 = F_66 ( V_63 -> V_8 ) ;
if ( V_89 && ( V_89 == V_30 || V_11 -> V_91 ( V_63 , V_89 , V_30 ) == 0 ) )
V_90 = false ;
F_67 () ;
}
if ( V_90 )
V_35 = F_68 ( V_2 , V_64 ) ;
}
return V_35 ;
}
void
F_70 ( struct V_1 * * V_93 )
{
if ( * V_93 )
F_9 ( & ( * V_93 ) -> V_3 ) ;
* V_93 = NULL ;
}
int
F_71 ( struct V_29 * V_30 , bool V_94 ,
struct V_1 * * V_93 )
{
struct V_1 * V_2 ;
int V_35 = 0 ;
if ( F_72 ( ! V_30 -> V_2 ) )
return - V_95 ;
V_2 = F_73 ( sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_94 = V_94 ;
V_35 = F_46 ( V_2 , V_30 ) ;
if ( V_35 )
F_70 ( & V_2 ) ;
* V_93 = V_2 ;
return V_35 ;
}
static const char * F_74 ( struct V_2 * V_2 )
{
return L_3 ;
}
static const char * F_75 ( struct V_2 * V_63 )
{
struct V_1 * V_2 = F_1 ( V_63 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
return ! V_11 -> V_26 ? V_11 -> V_44 : L_4 ;
}
static bool F_76 ( struct V_2 * V_63 )
{
struct V_1 * V_2 = F_1 ( V_63 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
struct V_29 * V_30 ;
bool V_35 = false ;
F_65 () ;
V_30 = F_66 ( V_2 -> V_8 ) ;
if ( V_30 )
V_35 = ( int ) ( V_11 -> V_32 ( V_30 ) - V_2 -> V_3 . V_33 ) >= 0 ;
F_67 () ;
return V_35 ;
}
static bool F_77 ( struct V_2 * V_63 )
{
struct V_1 * V_2 = F_1 ( V_63 ) ;
F_37 ( F_78 ( & V_2 -> V_3 . V_97 . V_97 ) <= 1 ) ;
if ( F_76 ( V_63 ) ) {
F_6 ( & V_2 -> V_7 ) ;
F_9 ( & V_2 -> V_3 ) ;
return false ;
}
return true ;
}
static void F_79 ( struct V_2 * V_63 )
{
struct V_1 * V_2 = F_1 ( V_63 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
F_23 ( & V_11 -> V_28 , F_20 ) ;
F_80 ( & V_2 -> V_3 ) ;
}
static bool F_81 ( struct V_2 * V_63 )
{
struct V_1 * V_2 = F_1 ( V_63 ) ;
struct V_4 * V_11 = F_3 ( V_2 ) ;
bool V_35 ;
if ( ! V_11 -> V_12 ++ )
F_82 ( & V_11 -> V_25 ) ;
V_35 = F_77 ( V_63 ) ;
if ( V_35 )
F_83 ( V_9 , & V_2 -> V_3 . V_10 ) ;
else if ( ! -- V_11 -> V_12 )
F_16 ( & V_11 -> V_25 ) ;
return V_35 ;
}
