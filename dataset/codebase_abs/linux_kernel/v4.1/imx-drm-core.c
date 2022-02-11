int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static void F_2 ( struct V_4 * V_5 )
{
#if F_3 ( V_6 )
struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_10 )
F_4 ( V_8 -> V_10 ) ;
#endif
}
static int F_5 ( struct V_4 * V_5 )
{
#if F_3 ( V_6 )
struct V_7 * V_8 = V_5 -> V_9 ;
#endif
F_6 ( V_5 ) ;
#if F_3 ( V_6 )
if ( V_8 -> V_10 )
F_7 ( V_8 -> V_10 ) ;
#endif
F_8 ( V_5 -> V_11 , V_5 ) ;
F_9 ( V_5 ) ;
F_10 ( V_5 ) ;
F_11 ( V_5 -> V_12 , NULL ) ;
return 0 ;
}
static struct V_1 * F_12 ( struct V_13 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_11 -> V_9 ;
unsigned V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
if ( V_8 -> V_2 [ V_14 ] && V_8 -> V_2 [ V_14 ] -> V_2 == V_2 )
return V_8 -> V_2 [ V_14 ] ;
return NULL ;
}
int F_13 ( struct V_16 * V_17 , T_1 V_18 ,
int V_19 , int V_20 )
{
struct V_21 * V_22 ;
struct V_1 * V_23 ;
V_23 = F_12 ( V_17 -> V_2 ) ;
if ( ! V_23 )
return - V_24 ;
V_22 = & V_23 -> V_25 ;
if ( V_22 -> V_26 )
return V_22 -> V_26 ( V_17 -> V_2 ,
V_18 , V_19 , V_20 ) ;
return 0 ;
}
int F_14 ( struct V_16 * V_17 , T_1 V_18 )
{
return F_13 ( V_17 , V_18 , 2 , 3 ) ;
}
int F_15 ( struct V_1 * V_1 )
{
return F_16 ( V_1 -> V_2 -> V_11 , V_1 -> V_3 ) ;
}
void F_17 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_2 -> V_11 , V_1 -> V_3 ) ;
}
void F_19 ( struct V_1 * V_1 )
{
F_20 ( V_1 -> V_2 -> V_11 , V_1 -> V_3 ) ;
}
static int F_21 ( struct V_4 * V_5 , int V_2 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_2 [ V_2 ] ;
int V_27 ;
if ( ! V_1 )
return - V_24 ;
if ( ! V_1 -> V_25 . V_28 )
return - V_29 ;
V_27 = V_1 -> V_25 . V_28 (
V_1 -> V_2 ) ;
return V_27 ;
}
static void F_22 ( struct V_4 * V_5 , int V_2 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_2 [ V_2 ] ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_25 . V_30 )
return;
V_1 -> V_25 . V_30 ( V_1 -> V_2 ) ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_31 * V_32 )
{
int V_14 ;
if ( ! V_32 -> V_33 )
return;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_22 ( V_5 , V_14 ) ;
}
void F_24 ( struct V_34 * V_35 )
{
F_25 ( V_35 ) ;
F_26 ( V_35 ) ;
}
void F_27 ( struct V_16 * V_17 )
{
F_28 ( V_17 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
#if F_3 ( V_6 )
struct V_7 * V_8 = V_5 -> V_9 ;
F_30 ( V_8 -> V_10 ) ;
#endif
}
static int F_31 ( struct V_4 * V_5 , unsigned long V_36 )
{
struct V_7 * V_8 ;
struct V_34 * V_35 ;
int V_27 ;
V_8 = F_32 ( V_5 -> V_11 , sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return - V_38 ;
V_8 -> V_5 = V_5 ;
V_5 -> V_9 = V_8 ;
V_5 -> V_39 = true ;
V_5 -> V_40 . V_41 = 64 ;
V_5 -> V_40 . V_42 = 64 ;
V_5 -> V_40 . V_43 = 4096 ;
V_5 -> V_40 . V_44 = 4096 ;
V_5 -> V_40 . V_45 = & V_46 ;
F_33 ( V_5 ) ;
V_27 = F_34 ( V_5 , V_15 ) ;
if ( V_27 )
goto V_47;
V_5 -> V_48 = true ;
F_11 ( V_5 -> V_12 , V_5 ) ;
V_27 = F_35 ( V_5 -> V_11 , V_5 ) ;
if ( V_27 )
goto V_49;
F_36 (connector, &drm->mode_config.connector_list, head) {
V_27 = F_37 ( V_35 ) ;
if ( V_27 ) {
F_38 ( V_5 -> V_11 ,
L_1 ,
V_35 -> V_50 . V_51 ,
V_35 -> V_52 , V_27 ) ;
goto V_53;
}
}
#if F_3 ( V_6 )
if ( V_54 != 16 && V_54 != 32 ) {
F_39 ( V_5 -> V_11 , L_2 ) ;
V_54 = 16 ;
}
V_8 -> V_10 = F_40 ( V_5 , V_54 ,
V_5 -> V_40 . V_55 , V_15 ) ;
if ( F_41 ( V_8 -> V_10 ) ) {
V_27 = F_42 ( V_8 -> V_10 ) ;
V_8 -> V_10 = NULL ;
goto V_53;
}
#endif
F_43 ( V_5 ) ;
return 0 ;
V_53:
F_8 ( V_5 -> V_11 , V_5 ) ;
V_49:
F_9 ( V_5 ) ;
V_47:
F_10 ( V_5 ) ;
return V_27 ;
}
int F_44 ( struct V_4 * V_5 , struct V_13 * V_2 ,
struct V_1 * * V_56 ,
const struct V_21 * V_25 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 ;
int V_27 ;
if ( V_8 -> V_59 >= V_15 )
return - V_24 ;
if ( V_8 -> V_5 -> V_60 )
return - V_61 ;
V_1 = F_45 ( sizeof( * V_1 ) , V_37 ) ;
if ( ! V_1 )
return - V_38 ;
V_1 -> V_25 = * V_25 ;
V_1 -> V_3 = V_8 -> V_59 ++ ;
V_1 -> V_2 = V_2 ;
V_2 -> V_58 = V_58 ;
V_8 -> V_2 [ V_1 -> V_3 ] = V_1 ;
* V_56 = V_1 ;
V_27 = F_46 ( V_1 -> V_2 , 256 ) ;
if ( V_27 )
goto V_62;
F_47 ( V_2 ,
V_1 -> V_25 . V_63 ) ;
F_48 ( V_5 , V_2 ,
V_1 -> V_25 . V_64 ) ;
return 0 ;
V_62:
V_8 -> V_2 [ V_1 -> V_3 ] = NULL ;
F_49 ( V_1 ) ;
return V_27 ;
}
int F_50 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 -> V_11 -> V_9 ;
F_51 ( V_1 -> V_2 ) ;
V_8 -> V_2 [ V_1 -> V_3 ] = NULL ;
F_49 ( V_1 ) ;
return 0 ;
}
int F_52 ( struct V_4 * V_5 ,
struct V_16 * V_17 , struct V_57 * V_65 )
{
T_2 V_66 = F_53 ( V_5 , V_65 ) ;
if ( V_66 == 0 )
return - V_67 ;
V_17 -> V_68 = V_66 ;
V_17 -> V_69 = ~ 0 ;
return 0 ;
}
int F_54 ( struct V_57 * V_70 ,
struct V_16 * V_17 )
{
struct V_1 * V_23 = F_12 ( V_17 -> V_2 ) ;
struct V_57 * V_71 ;
struct V_72 V_73 ;
struct V_57 * V_58 ;
int V_27 ;
if ( ! V_70 || ! V_23 )
return - V_24 ;
F_55 (node, ep) {
V_58 = F_56 ( V_71 ) ;
F_57 ( V_58 ) ;
if ( V_58 == V_23 -> V_2 -> V_58 ) {
V_27 = F_58 ( V_71 , & V_73 ) ;
F_57 ( V_71 ) ;
return V_27 ? V_27 : V_73 . V_58 ;
}
}
return - V_24 ;
}
static int F_59 ( struct V_74 * V_11 , void * V_75 )
{
struct V_57 * V_65 = V_75 ;
if ( F_60 ( V_65 -> V_52 , L_3 ) == 0 ) {
V_65 = F_61 ( V_65 ) ;
F_57 ( V_65 ) ;
}
return V_11 -> V_76 == V_65 ;
}
static int F_62 ( struct V_74 * V_11 )
{
return F_63 ( & V_77 , F_64 ( V_11 ) ) ;
}
static void F_65 ( struct V_74 * V_11 )
{
F_66 ( F_67 ( V_11 ) ) ;
}
static int F_68 ( struct V_78 * V_79 )
{
struct V_57 * V_71 , * V_58 , * V_80 ;
struct V_81 * V_82 = NULL ;
int V_27 ;
int V_14 ;
for ( V_14 = 0 ; ; V_14 ++ ) {
V_58 = F_69 ( V_79 -> V_11 . V_76 , L_4 , V_14 ) ;
if ( ! V_58 )
break;
F_70 ( & V_79 -> V_11 , & V_82 , F_59 , V_58 ) ;
}
if ( V_14 == 0 ) {
F_38 ( & V_79 -> V_11 , L_5 ) ;
return - V_83 ;
}
for ( V_14 = 0 ; ; V_14 ++ ) {
V_58 = F_69 ( V_79 -> V_11 . V_76 , L_4 , V_14 ) ;
if ( ! V_58 )
break;
F_71 (port, ep) {
V_80 = F_72 ( V_71 ) ;
if ( ! V_80 || ! F_73 ( V_80 ) ) {
F_57 ( V_80 ) ;
continue;
} else if ( ! F_73 ( V_80 -> V_84 ) ) {
F_39 ( & V_79 -> V_11 , L_6 ,
V_80 -> V_85 ) ;
F_57 ( V_80 ) ;
continue;
}
F_70 ( & V_79 -> V_11 , & V_82 , F_59 ,
V_80 ) ;
F_57 ( V_80 ) ;
}
F_57 ( V_58 ) ;
}
V_27 = F_74 ( & V_79 -> V_11 , F_75 ( 32 ) ) ;
if ( V_27 )
return V_27 ;
return F_76 ( & V_79 -> V_11 , & V_86 , V_82 ) ;
}
static int F_77 ( struct V_78 * V_79 )
{
F_78 ( & V_79 -> V_11 , & V_86 ) ;
return 0 ;
}
static int F_79 ( struct V_74 * V_11 )
{
struct V_4 * V_87 = F_67 ( V_11 ) ;
if ( V_87 == NULL )
return 0 ;
F_80 ( V_87 ) ;
return 0 ;
}
static int F_81 ( struct V_74 * V_11 )
{
struct V_4 * V_87 = F_67 ( V_11 ) ;
if ( V_87 == NULL )
return 0 ;
F_82 ( V_87 ) ;
F_83 ( V_87 ) ;
return 0 ;
}
