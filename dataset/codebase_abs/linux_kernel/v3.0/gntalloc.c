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
struct V_1 * V_2 ;
V_12 = ! ( V_6 -> V_15 & V_16 ) ;
V_11 = - V_17 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_18 ; V_10 ++ ) {
V_2 = F_6 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
goto V_20;
F_7 ( & V_2 -> V_21 , & V_13 ) ;
F_7 ( & V_2 -> V_22 , & V_14 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_23 = V_6 -> V_24 + V_10 * V_25 ;
V_2 -> V_26 = F_8 ( V_19 | V_27 ) ;
if ( ! V_2 -> V_26 )
goto V_20;
V_2 -> V_28 = F_9 ( V_6 -> V_29 ,
F_10 ( F_11 ( V_2 -> V_26 ) ) , V_12 ) ;
if ( V_2 -> V_28 < 0 ) {
V_11 = V_2 -> V_28 ;
goto V_20;
}
V_7 [ V_10 ] = V_2 -> V_28 ;
}
F_12 ( & V_30 ) ;
F_13 ( & V_13 , & V_31 ) ;
F_13 ( & V_14 , & V_9 -> V_32 ) ;
F_14 ( & V_30 ) ;
return 0 ;
V_20:
F_12 ( & V_30 ) ;
V_33 -= ( V_6 -> V_18 - V_10 ) ;
F_15 (gref, &queue_file, next_file) {
F_3 ( V_2 ) ;
}
if ( F_16 ( ! F_17 ( & V_13 ) ) )
F_13 ( & V_13 , & V_31 ) ;
F_14 ( & V_30 ) ;
return V_11 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 . V_15 & V_35 ) {
T_2 * V_36 = F_18 ( V_2 -> V_26 ) ;
V_36 [ V_2 -> V_34 . V_37 ] = 0 ;
F_19 ( V_2 -> V_26 ) ;
}
if ( V_2 -> V_34 . V_15 & V_38 )
F_20 ( V_2 -> V_34 . V_39 ) ;
V_2 -> V_34 . V_15 = 0 ;
if ( V_2 -> V_28 > 0 ) {
if ( F_21 ( V_2 -> V_28 ) )
return;
if ( ! F_22 ( V_2 -> V_28 , 0 ) )
return;
}
V_33 -- ;
F_23 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_26 )
F_24 ( V_2 -> V_26 ) ;
F_25 ( V_2 ) ;
}
static struct V_1 * F_26 ( struct V_8 * V_9 ,
T_3 V_24 , T_1 V_18 )
{
struct V_1 * V_40 = NULL , * V_2 ;
F_15 (gref, &priv->list, next_file) {
if ( V_2 -> V_23 == V_24 && ! V_40 )
V_40 = V_2 ;
if ( V_40 ) {
if ( V_2 -> V_23 != V_24 )
return NULL ;
V_24 += V_25 ;
V_18 -- ;
if ( V_18 == 0 )
return V_40 ;
}
}
return NULL ;
}
static int F_27 ( struct V_41 * V_41 , struct V_42 * V_43 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
goto V_44;
F_28 ( & V_9 -> V_32 ) ;
V_43 -> V_45 = V_9 ;
F_29 ( L_1 , V_46 , V_9 ) ;
return 0 ;
V_44:
return - V_17 ;
}
static int F_30 ( struct V_41 * V_41 , struct V_42 * V_43 )
{
struct V_8 * V_9 = V_43 -> V_45 ;
struct V_1 * V_2 ;
F_29 ( L_1 , V_46 , V_9 ) ;
F_12 ( & V_30 ) ;
while ( ! F_17 ( & V_9 -> V_32 ) ) {
V_2 = F_31 ( V_9 -> V_32 . V_47 ,
struct V_1 , V_22 ) ;
F_23 ( & V_2 -> V_22 ) ;
V_2 -> V_4 -- ;
if ( V_2 -> V_4 == 0 )
F_3 ( V_2 ) ;
}
F_25 ( V_9 ) ;
F_14 ( & V_30 ) ;
return 0 ;
}
static long F_32 ( struct V_8 * V_9 ,
struct V_5 T_4 * V_48 )
{
int V_11 = 0 ;
struct V_5 V_6 ;
T_1 * V_7 ;
F_29 ( L_1 , V_46 , V_9 ) ;
if ( F_33 ( & V_6 , V_48 , sizeof( V_6 ) ) ) {
V_11 = - V_49 ;
goto V_50;
}
V_7 = F_6 ( sizeof( V_7 [ 0 ] ) * V_6 . V_18 , V_51 ) ;
if ( ! V_7 ) {
V_11 = - V_17 ;
goto V_50;
}
F_12 ( & V_30 ) ;
F_1 () ;
if ( V_33 + V_6 . V_18 > V_52 ) {
F_14 ( & V_30 ) ;
V_11 = - V_53 ;
goto V_54;
}
V_33 += V_6 . V_18 ;
V_6 . V_24 = V_9 -> V_24 ;
V_9 -> V_24 += V_6 . V_18 * V_25 ;
F_14 ( & V_30 ) ;
V_11 = F_4 ( & V_6 , V_7 , V_9 ) ;
if ( V_11 < 0 )
goto V_54;
if ( F_34 ( V_48 , & V_6 , sizeof( V_6 ) ) ) {
V_11 = - V_49 ;
goto V_54;
}
if ( F_34 ( V_48 -> V_7 , V_7 ,
sizeof( V_7 [ 0 ] ) * V_6 . V_18 ) ) {
V_11 = - V_49 ;
goto V_54;
}
V_54:
F_25 ( V_7 ) ;
V_50:
return V_11 ;
}
static long F_35 ( struct V_8 * V_9 ,
void T_4 * V_48 )
{
int V_10 , V_11 = 0 ;
struct V_55 V_6 ;
struct V_1 * V_2 , * V_3 ;
F_29 ( L_1 , V_46 , V_9 ) ;
if ( F_33 ( & V_6 , V_48 , sizeof( V_6 ) ) ) {
V_11 = - V_49 ;
goto V_56;
}
F_12 ( & V_30 ) ;
V_2 = F_26 ( V_9 , V_6 . V_24 , V_6 . V_18 ) ;
if ( V_2 ) {
for ( V_10 = 0 ; V_10 < V_6 . V_18 ; V_10 ++ ) {
V_3 = F_31 ( V_2 -> V_22 . V_47 ,
struct V_1 , V_22 ) ;
F_23 ( & V_2 -> V_22 ) ;
V_2 -> V_4 -- ;
V_2 = V_3 ;
}
} else {
V_11 = - V_57 ;
}
F_1 () ;
F_14 ( & V_30 ) ;
V_56:
return V_11 ;
}
static long F_36 ( struct V_8 * V_9 ,
void T_4 * V_48 )
{
struct V_58 V_6 ;
struct V_1 * V_2 ;
T_3 V_24 ;
int V_37 ;
int V_11 ;
if ( F_33 ( & V_6 , V_48 , sizeof( V_6 ) ) )
return - V_49 ;
V_24 = V_6 . V_24 & ~ ( V_25 - 1 ) ;
V_37 = V_6 . V_24 & ( V_25 - 1 ) ;
F_12 ( & V_30 ) ;
V_2 = F_26 ( V_9 , V_24 , 1 ) ;
if ( ! V_2 ) {
V_11 = - V_59 ;
goto V_60;
}
if ( V_6 . V_61 & ~ ( V_35 | V_38 ) ) {
V_11 = - V_57 ;
goto V_60;
}
V_2 -> V_34 . V_15 = V_6 . V_61 ;
V_2 -> V_34 . V_37 = V_37 ;
V_2 -> V_34 . V_39 = V_6 . V_62 ;
V_11 = 0 ;
V_60:
F_14 ( & V_30 ) ;
return V_11 ;
}
static long F_37 ( struct V_42 * V_43 , unsigned int V_63 ,
unsigned long V_48 )
{
struct V_8 * V_9 = V_43 -> V_45 ;
switch ( V_63 ) {
case V_64 :
return F_32 ( V_9 , ( void T_4 * ) V_48 ) ;
case V_65 :
return F_35 ( V_9 , ( void T_4 * ) V_48 ) ;
case V_66 :
return F_36 ( V_9 , ( void T_4 * ) V_48 ) ;
default:
return - V_67 ;
}
return 0 ;
}
static void F_38 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
if ( ! V_2 )
return;
F_12 ( & V_30 ) ;
V_2 -> V_4 ++ ;
F_14 ( & V_30 ) ;
}
static void F_39 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
if ( ! V_2 )
return;
F_12 ( & V_30 ) ;
V_2 -> V_4 -- ;
if ( V_2 -> V_4 == 0 )
F_3 ( V_2 ) ;
F_14 ( & V_30 ) ;
}
static int F_40 ( struct V_42 * V_43 , struct V_68 * V_69 )
{
struct V_8 * V_9 = V_43 -> V_45 ;
struct V_1 * V_2 ;
int V_18 = ( V_69 -> V_71 - V_69 -> V_72 ) >> V_73 ;
int V_40 , V_10 ;
F_29 ( L_2 , V_46 ,
V_9 , V_69 -> V_74 , V_18 ) ;
if ( ! ( V_69 -> V_75 & V_76 ) ) {
F_41 ( V_77 L_3 , V_46 ) ;
return - V_57 ;
}
F_12 ( & V_30 ) ;
V_2 = F_26 ( V_9 , V_69 -> V_74 << V_73 , V_18 ) ;
if ( V_2 == NULL ) {
V_40 = - V_59 ;
F_29 ( L_4 ,
V_46 ) ;
goto V_78;
}
V_69 -> V_70 = V_2 ;
V_69 -> V_75 |= V_79 ;
V_69 -> V_80 = & V_81 ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
V_2 -> V_4 ++ ;
V_40 = F_42 ( V_69 , V_69 -> V_72 + V_10 * V_25 ,
V_2 -> V_26 ) ;
if ( V_40 )
goto V_78;
V_2 = F_31 ( V_2 -> V_22 . V_47 ,
struct V_1 , V_22 ) ;
}
V_40 = 0 ;
V_78:
F_14 ( & V_30 ) ;
return V_40 ;
}
static int T_5 F_43 ( void )
{
int V_82 ;
if ( ! F_44 () )
return - V_83 ;
V_82 = F_45 ( & V_84 ) ;
if ( V_82 != 0 ) {
F_41 ( V_77 L_5 ) ;
return V_82 ;
}
F_29 ( L_6 ,
V_85 , V_84 . V_86 ) ;
return 0 ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_84 ) ;
}
