static void F_1 ( void )
{
struct V_1 * V_2 , * V_3 ;
F_2 (gref, n, &gref_list, next_gref) {
if ( ! V_2 -> V_4 )
F_3 ( V_2 ) ;
}
}
static int F_4 ( struct V_5 * V_6 ,
T_1 * V_7 , struct V_8 * V_9 )
{
int V_10 , V_11 , V_12 ;
F_5 ( V_13 ) ;
F_5 ( V_14 ) ;
struct V_1 * V_2 , * V_15 ;
V_12 = ! ( V_6 -> V_16 & V_17 ) ;
for ( V_10 = 0 ; V_10 < V_6 -> V_18 ; V_10 ++ ) {
V_2 = F_6 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 ) {
V_11 = - V_20 ;
goto V_21;
}
F_7 ( & V_2 -> V_22 , & V_13 ) ;
F_7 ( & V_2 -> V_23 , & V_14 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_24 = V_6 -> V_25 + V_10 * V_26 ;
V_2 -> V_27 = F_8 ( V_19 | V_28 ) ;
if ( ! V_2 -> V_27 ) {
V_11 = - V_20 ;
goto V_21;
}
V_11 = F_9 ( V_6 -> V_29 ,
F_10 ( V_2 -> V_27 ) ,
V_12 ) ;
if ( V_11 < 0 )
goto V_21;
V_7 [ V_10 ] = V_2 -> V_30 = V_11 ;
}
F_11 ( & V_31 ) ;
F_12 ( & V_13 , & V_32 ) ;
F_12 ( & V_14 , & V_9 -> V_33 ) ;
F_13 ( & V_31 ) ;
return 0 ;
V_21:
F_11 ( & V_31 ) ;
V_34 -= ( V_6 -> V_18 - V_10 ) ;
F_2 (gref, next, &queue_file, next_file) {
F_14 ( & V_2 -> V_23 ) ;
F_3 ( V_2 ) ;
}
if ( F_15 ( ! F_16 ( & V_13 ) ) )
F_12 ( & V_13 , & V_32 ) ;
F_13 ( & V_31 ) ;
return V_11 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 . V_16 & V_36 ) {
T_2 * V_37 = F_17 ( V_2 -> V_27 ) ;
V_37 [ V_2 -> V_35 . V_38 ] = 0 ;
F_18 ( V_2 -> V_27 ) ;
}
if ( V_2 -> V_35 . V_16 & V_39 ) {
F_19 ( V_2 -> V_35 . V_40 ) ;
F_20 ( V_2 -> V_35 . V_40 ) ;
}
V_2 -> V_35 . V_16 = 0 ;
if ( V_2 -> V_30 ) {
if ( F_21 ( V_2 -> V_30 ) )
return;
if ( ! F_22 ( V_2 -> V_30 , 0 ) )
return;
F_23 ( V_2 -> V_30 ) ;
}
V_34 -- ;
F_14 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_27 )
F_24 ( V_2 -> V_27 ) ;
F_25 ( V_2 ) ;
}
static struct V_1 * F_26 ( struct V_8 * V_9 ,
T_3 V_25 , T_1 V_18 )
{
struct V_1 * V_41 = NULL , * V_2 ;
F_27 (gref, &priv->list, next_file) {
if ( V_2 -> V_24 == V_25 && ! V_41 )
V_41 = V_2 ;
if ( V_41 ) {
if ( V_2 -> V_24 != V_25 )
return NULL ;
V_25 += V_26 ;
V_18 -- ;
if ( V_18 == 0 )
return V_41 ;
}
}
return NULL ;
}
static int F_28 ( struct V_42 * V_42 , struct V_43 * V_44 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
goto V_45;
F_29 ( & V_9 -> V_33 ) ;
V_44 -> V_46 = V_9 ;
F_30 ( L_1 , V_47 , V_9 ) ;
return 0 ;
V_45:
return - V_20 ;
}
static int F_31 ( struct V_42 * V_42 , struct V_43 * V_44 )
{
struct V_8 * V_9 = V_44 -> V_46 ;
struct V_1 * V_2 ;
F_30 ( L_1 , V_47 , V_9 ) ;
F_11 ( & V_31 ) ;
while ( ! F_16 ( & V_9 -> V_33 ) ) {
V_2 = F_32 ( V_9 -> V_33 . V_15 ,
struct V_1 , V_23 ) ;
F_14 ( & V_2 -> V_23 ) ;
V_2 -> V_4 -- ;
if ( V_2 -> V_4 == 0 )
F_3 ( V_2 ) ;
}
F_25 ( V_9 ) ;
F_13 ( & V_31 ) ;
return 0 ;
}
static long F_33 ( struct V_8 * V_9 ,
struct V_5 T_4 * V_48 )
{
int V_11 = 0 ;
struct V_5 V_6 ;
T_1 * V_7 ;
F_30 ( L_1 , V_47 , V_9 ) ;
if ( F_34 ( & V_6 , V_48 , sizeof( V_6 ) ) ) {
V_11 = - V_49 ;
goto V_50;
}
V_7 = F_35 ( V_6 . V_18 , sizeof( V_7 [ 0 ] ) , V_19 ) ;
if ( ! V_7 ) {
V_11 = - V_20 ;
goto V_50;
}
F_11 ( & V_31 ) ;
F_1 () ;
if ( V_34 + V_6 . V_18 > V_51 ) {
F_13 ( & V_31 ) ;
V_11 = - V_52 ;
goto V_53;
}
V_34 += V_6 . V_18 ;
V_6 . V_25 = V_9 -> V_25 ;
V_9 -> V_25 += V_6 . V_18 * V_26 ;
F_13 ( & V_31 ) ;
V_11 = F_4 ( & V_6 , V_7 , V_9 ) ;
if ( V_11 < 0 )
goto V_53;
if ( F_36 ( V_48 , & V_6 , sizeof( V_6 ) ) ) {
V_11 = - V_49 ;
goto V_53;
}
if ( F_36 ( V_48 -> V_7 , V_7 ,
sizeof( V_7 [ 0 ] ) * V_6 . V_18 ) ) {
V_11 = - V_49 ;
goto V_53;
}
V_53:
F_25 ( V_7 ) ;
V_50:
return V_11 ;
}
static long F_37 ( struct V_8 * V_9 ,
void T_4 * V_48 )
{
int V_10 , V_11 = 0 ;
struct V_54 V_6 ;
struct V_1 * V_2 , * V_3 ;
F_30 ( L_1 , V_47 , V_9 ) ;
if ( F_34 ( & V_6 , V_48 , sizeof( V_6 ) ) ) {
V_11 = - V_49 ;
goto V_55;
}
F_11 ( & V_31 ) ;
V_2 = F_26 ( V_9 , V_6 . V_25 , V_6 . V_18 ) ;
if ( V_2 ) {
for ( V_10 = 0 ; V_10 < V_6 . V_18 ; V_10 ++ ) {
V_3 = F_32 ( V_2 -> V_23 . V_15 ,
struct V_1 , V_23 ) ;
F_14 ( & V_2 -> V_23 ) ;
V_2 -> V_4 -- ;
V_2 = V_3 ;
}
} else {
V_11 = - V_56 ;
}
F_1 () ;
F_13 ( & V_31 ) ;
V_55:
return V_11 ;
}
static long F_38 ( struct V_8 * V_9 ,
void T_4 * V_48 )
{
struct V_57 V_6 ;
struct V_1 * V_2 ;
T_3 V_25 ;
int V_38 ;
int V_11 ;
if ( F_34 ( & V_6 , V_48 , sizeof( V_6 ) ) )
return - V_49 ;
V_25 = V_6 . V_25 & ~ ( V_26 - 1 ) ;
V_38 = V_6 . V_25 & ( V_26 - 1 ) ;
F_11 ( & V_31 ) ;
V_2 = F_26 ( V_9 , V_25 , 1 ) ;
if ( ! V_2 ) {
V_11 = - V_58 ;
goto V_59;
}
if ( V_6 . V_60 & ~ ( V_36 | V_39 ) ) {
V_11 = - V_56 ;
goto V_59;
}
if ( V_6 . V_60 & V_39 ) {
if ( F_39 ( V_6 . V_61 ) ) {
V_11 = - V_56 ;
goto V_59;
}
}
if ( V_2 -> V_35 . V_16 & V_39 )
F_20 ( V_2 -> V_35 . V_40 ) ;
V_2 -> V_35 . V_16 = V_6 . V_60 ;
V_2 -> V_35 . V_38 = V_38 ;
V_2 -> V_35 . V_40 = V_6 . V_61 ;
V_11 = 0 ;
V_59:
F_13 ( & V_31 ) ;
return V_11 ;
}
static long F_40 ( struct V_43 * V_44 , unsigned int V_62 ,
unsigned long V_48 )
{
struct V_8 * V_9 = V_44 -> V_46 ;
switch ( V_62 ) {
case V_63 :
return F_33 ( V_9 , ( void T_4 * ) V_48 ) ;
case V_64 :
return F_37 ( V_9 , ( void T_4 * ) V_48 ) ;
case V_65 :
return F_38 ( V_9 , ( void T_4 * ) V_48 ) ;
default:
return - V_66 ;
}
return 0 ;
}
static void F_41 ( struct V_67 * V_68 )
{
struct V_69 * V_9 = V_68 -> V_70 ;
if ( ! V_9 )
return;
F_11 ( & V_31 ) ;
V_9 -> V_4 ++ ;
F_13 ( & V_31 ) ;
}
static void F_42 ( struct V_67 * V_68 )
{
struct V_69 * V_9 = V_68 -> V_70 ;
struct V_1 * V_2 , * V_15 ;
int V_10 ;
if ( ! V_9 )
return;
F_11 ( & V_31 ) ;
V_9 -> V_4 -- ;
if ( V_9 -> V_4 == 0 ) {
V_2 = V_9 -> V_2 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_18 ; V_10 ++ ) {
V_2 -> V_4 -- ;
V_15 = F_32 ( V_2 -> V_22 . V_15 ,
struct V_1 , V_22 ) ;
if ( V_2 -> V_4 == 0 )
F_3 ( V_2 ) ;
V_2 = V_15 ;
}
F_25 ( V_9 ) ;
}
F_13 ( & V_31 ) ;
}
static int F_43 ( struct V_43 * V_44 , struct V_67 * V_68 )
{
struct V_8 * V_9 = V_44 -> V_46 ;
struct V_69 * V_71 ;
struct V_1 * V_2 ;
int V_18 = F_44 ( V_68 ) ;
int V_41 , V_10 ;
if ( ! ( V_68 -> V_72 & V_73 ) ) {
F_45 ( L_2 , V_47 ) ;
return - V_56 ;
}
V_71 = F_46 ( sizeof( * V_71 ) , V_19 ) ;
if ( ! V_71 )
return - V_20 ;
F_11 ( & V_31 ) ;
F_30 ( L_3 , V_47 ,
V_9 , V_71 , V_68 -> V_74 , V_18 ) ;
V_2 = F_26 ( V_9 , V_68 -> V_74 << V_75 , V_18 ) ;
if ( V_2 == NULL ) {
V_41 = - V_58 ;
F_30 ( L_4 ,
V_47 ) ;
F_25 ( V_71 ) ;
goto V_76;
}
V_71 -> V_2 = V_2 ;
V_71 -> V_4 = 1 ;
V_71 -> V_18 = V_18 ;
V_68 -> V_70 = V_71 ;
V_68 -> V_72 |= V_77 | V_78 ;
V_68 -> V_79 = & V_80 ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
V_2 -> V_4 ++ ;
V_41 = F_47 ( V_68 , V_68 -> V_81 + V_10 * V_26 ,
V_2 -> V_27 ) ;
if ( V_41 )
goto V_76;
V_2 = F_32 ( V_2 -> V_23 . V_15 ,
struct V_1 , V_23 ) ;
}
V_41 = 0 ;
V_76:
F_13 ( & V_31 ) ;
return V_41 ;
}
static int T_5 F_48 ( void )
{
int V_82 ;
if ( ! F_49 () )
return - V_83 ;
V_82 = F_50 ( & V_84 ) ;
if ( V_82 != 0 ) {
F_45 ( L_5 ) ;
return V_82 ;
}
F_30 ( L_6 ,
V_85 , V_84 . V_86 ) ;
return 0 ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_84 ) ;
}
