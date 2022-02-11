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
int F_13 ( struct V_16 * V_17 ,
T_1 V_18 , int V_19 , int V_20 )
{
struct V_21 * V_22 ;
struct V_1 * V_23 ;
V_23 = F_12 ( V_17 -> V_2 ) ;
if ( ! V_23 )
return - V_24 ;
V_22 = & V_23 -> V_25 ;
if ( V_22 -> V_26 )
return V_22 -> V_26 ( V_17 -> V_2 ,
V_17 -> V_27 , V_18 ,
V_19 , V_20 ) ;
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
int V_28 ;
if ( ! V_1 )
return - V_24 ;
if ( ! V_1 -> V_25 . V_29 )
return - V_30 ;
V_28 = V_1 -> V_25 . V_29 (
V_1 -> V_2 ) ;
return V_28 ;
}
static void F_22 ( struct V_4 * V_5 , int V_2 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_2 [ V_2 ] ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_25 . V_31 )
return;
V_1 -> V_25 . V_31 ( V_1 -> V_2 ) ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_32 * V_33 )
{
int V_14 ;
if ( ! V_33 -> V_34 )
return;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_22 ( V_5 , V_14 ) ;
}
void F_24 ( struct V_35 * V_36 )
{
F_25 ( V_36 ) ;
F_26 ( V_36 ) ;
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
static int F_31 ( struct V_4 * V_5 , unsigned long V_37 )
{
struct V_7 * V_8 ;
struct V_35 * V_36 ;
int V_28 ;
V_8 = F_32 ( V_5 -> V_11 , sizeof( * V_8 ) , V_38 ) ;
if ( ! V_8 )
return - V_39 ;
V_8 -> V_5 = V_5 ;
V_5 -> V_9 = V_8 ;
V_5 -> V_40 = true ;
V_5 -> V_41 . V_42 = 64 ;
V_5 -> V_41 . V_43 = 64 ;
V_5 -> V_41 . V_44 = 4096 ;
V_5 -> V_41 . V_45 = 4096 ;
V_5 -> V_41 . V_46 = & V_47 ;
F_33 ( V_5 ) ;
V_28 = F_34 ( V_5 , V_15 ) ;
if ( V_28 )
goto V_48;
V_5 -> V_49 = true ;
F_11 ( V_5 -> V_12 , V_5 ) ;
V_28 = F_35 ( V_5 -> V_11 , V_5 ) ;
if ( V_28 )
goto V_50;
F_36 (connector, &drm->mode_config.connector_list, head) {
V_28 = F_37 ( V_36 ) ;
if ( V_28 ) {
F_38 ( V_5 -> V_11 ,
L_1 ,
V_36 -> V_51 . V_52 ,
V_36 -> V_53 , V_28 ) ;
goto V_54;
}
}
#if F_3 ( V_6 )
if ( V_55 != 16 && V_55 != 32 ) {
F_39 ( V_5 -> V_11 , L_2 ) ;
V_55 = 16 ;
}
V_8 -> V_10 = F_40 ( V_5 , V_55 ,
V_5 -> V_41 . V_56 , V_15 ) ;
if ( F_41 ( V_8 -> V_10 ) ) {
V_28 = F_42 ( V_8 -> V_10 ) ;
V_8 -> V_10 = NULL ;
goto V_54;
}
#endif
F_43 ( V_5 ) ;
return 0 ;
V_54:
F_8 ( V_5 -> V_11 , V_5 ) ;
V_50:
F_9 ( V_5 ) ;
V_48:
F_10 ( V_5 ) ;
return V_28 ;
}
int F_44 ( struct V_4 * V_5 , struct V_13 * V_2 ,
struct V_1 * * V_57 ,
const struct V_21 * V_25 ,
struct V_58 * V_59 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 ;
int V_28 ;
if ( V_8 -> V_60 >= V_15 )
return - V_24 ;
if ( V_8 -> V_5 -> V_61 )
return - V_62 ;
V_1 = F_45 ( sizeof( * V_1 ) , V_38 ) ;
if ( ! V_1 )
return - V_39 ;
V_1 -> V_25 = * V_25 ;
V_1 -> V_3 = V_8 -> V_60 ++ ;
V_1 -> V_59 = V_59 ;
V_1 -> V_2 = V_2 ;
V_8 -> V_2 [ V_1 -> V_3 ] = V_1 ;
* V_57 = V_1 ;
V_28 = F_46 ( V_1 -> V_2 , 256 ) ;
if ( V_28 )
goto V_63;
F_47 ( V_2 ,
V_1 -> V_25 . V_64 ) ;
F_48 ( V_5 , V_2 ,
V_1 -> V_25 . V_65 ) ;
return 0 ;
V_63:
V_8 -> V_2 [ V_1 -> V_3 ] = NULL ;
F_49 ( V_1 ) ;
return V_28 ;
}
int F_50 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 -> V_11 -> V_9 ;
F_51 ( V_1 -> V_2 ) ;
V_8 -> V_2 [ V_1 -> V_3 ] = NULL ;
F_49 ( V_1 ) ;
return 0 ;
}
static T_2 F_52 ( struct V_7 * V_8 ,
struct V_58 * V_66 )
{
struct V_58 * V_59 ;
unsigned V_14 ;
V_59 = F_53 ( V_66 ) ;
if ( ! V_59 )
return 0 ;
F_54 ( V_59 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
struct V_1 * V_1 = V_8 -> V_2 [ V_14 ] ;
if ( V_1 && V_1 -> V_59 == V_59 )
return F_55 ( V_1 -> V_2 ) ;
}
return 0 ;
}
static struct V_58 * F_56 (
const struct V_58 * V_67 , struct V_58 * V_68 )
{
struct V_58 * V_69 = F_57 ( V_67 , V_68 ) ;
F_54 ( V_68 ) ;
return V_69 ;
}
int F_58 ( struct V_4 * V_5 ,
struct V_16 * V_17 , struct V_58 * V_70 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_58 * V_71 = NULL ;
T_2 V_72 = 0 ;
int V_14 ;
for ( V_14 = 0 ; ; V_14 ++ ) {
T_1 V_73 ;
V_71 = F_56 ( V_70 , V_71 ) ;
if ( ! V_71 )
break;
V_73 = F_52 ( V_8 , V_71 ) ;
if ( V_73 == 0 )
return - V_74 ;
V_72 |= V_73 ;
}
F_54 ( V_71 ) ;
if ( V_14 == 0 )
return - V_75 ;
V_17 -> V_76 = V_72 ;
V_17 -> V_77 = ~ 0 ;
return 0 ;
}
int F_59 ( struct V_58 * V_69 ,
struct V_16 * V_17 )
{
struct V_1 * V_23 = F_12 ( V_17 -> V_2 ) ;
struct V_58 * V_71 = NULL ;
struct V_78 V_66 ;
struct V_58 * V_59 ;
int V_28 ;
if ( ! V_69 || ! V_23 )
return - V_24 ;
do {
V_71 = F_56 ( V_69 , V_71 ) ;
if ( ! V_71 )
break;
V_59 = F_53 ( V_71 ) ;
F_54 ( V_59 ) ;
if ( V_59 == V_23 -> V_59 ) {
V_28 = F_60 ( V_71 , & V_66 ) ;
return V_28 ? V_28 : V_66 . V_59 ;
}
} while ( V_71 );
return - V_24 ;
}
static int F_61 ( struct V_79 * V_11 , void * V_80 )
{
struct V_58 * V_70 = V_80 ;
if ( F_62 ( V_70 -> V_53 , L_3 ) == 0 ) {
V_70 = F_63 ( V_70 ) ;
F_54 ( V_70 ) ;
}
return V_11 -> V_81 == V_70 ;
}
static int F_64 ( struct V_79 * V_11 )
{
return F_65 ( & V_82 , F_66 ( V_11 ) ) ;
}
static void F_67 ( struct V_79 * V_11 )
{
F_68 ( F_69 ( V_11 ) ) ;
}
static int F_70 ( struct V_83 * V_84 )
{
struct V_58 * V_71 , * V_59 , * V_85 ;
struct V_86 * V_87 = NULL ;
int V_28 ;
int V_14 ;
for ( V_14 = 0 ; ; V_14 ++ ) {
V_59 = F_71 ( V_84 -> V_11 . V_81 , L_4 , V_14 ) ;
if ( ! V_59 )
break;
F_72 ( & V_84 -> V_11 , & V_87 , F_61 , V_59 ) ;
}
if ( V_14 == 0 ) {
F_38 ( & V_84 -> V_11 , L_5 ) ;
return - V_88 ;
}
for ( V_14 = 0 ; ; V_14 ++ ) {
V_59 = F_71 ( V_84 -> V_11 . V_81 , L_4 , V_14 ) ;
if ( ! V_59 )
break;
F_73 (port, ep) {
V_85 = F_74 ( V_71 ) ;
if ( ! V_85 || ! F_75 ( V_85 ) ) {
F_54 ( V_85 ) ;
continue;
} else if ( ! F_75 ( V_85 -> V_67 ) ) {
F_39 ( & V_84 -> V_11 , L_6 ,
V_85 -> V_89 ) ;
F_54 ( V_85 ) ;
continue;
}
F_72 ( & V_84 -> V_11 , & V_87 , F_61 , V_85 ) ;
F_54 ( V_85 ) ;
}
F_54 ( V_59 ) ;
}
V_28 = F_76 ( & V_84 -> V_11 , F_77 ( 32 ) ) ;
if ( V_28 )
return V_28 ;
return F_78 ( & V_84 -> V_11 , & V_90 , V_87 ) ;
}
static int F_79 ( struct V_83 * V_84 )
{
F_80 ( & V_84 -> V_11 , & V_90 ) ;
return 0 ;
}
static int F_81 ( struct V_79 * V_11 )
{
struct V_4 * V_91 = F_69 ( V_11 ) ;
if ( V_91 == NULL )
return 0 ;
F_82 ( V_91 ) ;
return 0 ;
}
static int F_83 ( struct V_79 * V_11 )
{
struct V_4 * V_91 = F_69 ( V_11 ) ;
if ( V_91 == NULL )
return 0 ;
F_84 ( V_91 ) ;
F_85 ( V_91 ) ;
return 0 ;
}
