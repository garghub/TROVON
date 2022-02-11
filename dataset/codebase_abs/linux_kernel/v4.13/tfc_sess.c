static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_3 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( V_6 && V_6 -> V_5 )
return V_6 ;
V_5 = F_4 ( V_3 ) ;
if ( ! V_5 )
return NULL ;
if ( V_6 ) {
V_6 -> V_5 = V_5 ;
V_5 -> V_6 = V_6 ;
return V_6 ;
}
V_6 = F_5 ( sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = V_5 ;
V_5 -> V_6 = V_6 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ )
F_6 ( & V_6 -> V_13 [ V_7 ] ) ;
F_7 ( V_3 -> V_8 [ V_9 ] , V_6 ) ;
return V_6 ;
}
static void F_8 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
F_9 ( V_6 ) ;
V_3 = V_6 -> V_3 ;
V_3 -> V_14 &= ~ V_15 ;
F_10 ( V_6 != V_3 -> V_8 [ V_9 ] ) ;
F_11 ( V_3 -> V_8 [ V_9 ] , NULL ) ;
V_5 = V_6 -> V_5 ;
if ( V_5 ) {
V_5 -> V_6 = NULL ;
V_6 -> V_5 = NULL ;
}
F_12 ( V_6 , V_16 ) ;
}
void F_13 ( struct V_2 * V_3 , void * V_17 )
{
F_14 ( & V_10 ) ;
F_1 ( V_3 ) ;
V_3 -> V_14 |= V_15 ;
F_15 ( & V_10 ) ;
}
void F_16 ( struct V_2 * V_3 , void * V_17 )
{
struct V_1 * V_6 ;
F_14 ( & V_10 ) ;
V_6 = V_3 -> V_8 [ V_9 ] ;
if ( V_6 )
F_8 ( V_6 ) ;
F_15 ( & V_10 ) ;
}
int F_17 ( struct V_18 * V_19 , unsigned long V_20 , void * V_17 )
{
struct V_2 * V_3 = V_17 ;
switch ( V_20 ) {
case V_21 :
F_13 ( V_3 , NULL ) ;
break;
case V_22 :
F_16 ( V_3 , NULL ) ;
break;
}
return V_23 ;
}
static T_1 F_18 ( T_1 V_24 )
{
return F_19 ( V_24 , V_25 ) ;
}
static struct V_26 * F_20 ( struct V_2 * V_3 , T_1 V_24 )
{
struct V_1 * V_6 ;
struct V_27 * V_28 ;
struct V_26 * V_29 ;
char * V_30 = L_1 ;
F_21 () ;
V_6 = F_22 ( V_3 -> V_8 [ V_9 ] ) ;
if ( ! V_6 ) {
V_30 = L_2 ;
goto V_31;
}
V_28 = & V_6 -> V_13 [ F_18 ( V_24 ) ] ;
F_23 (sess, head, hash) {
if ( V_29 -> V_24 == V_24 ) {
F_24 ( & V_29 -> V_32 ) ;
F_25 () ;
F_26 ( V_3 , L_3 ,
V_24 , V_29 ) ;
return V_29 ;
}
}
V_31:
F_25 () ;
F_26 ( V_3 , L_4 ,
V_24 , V_30 ) ;
return NULL ;
}
static int F_27 ( struct V_33 * V_34 ,
struct V_35 * V_36 , void * V_37 )
{
struct V_26 * V_29 = V_37 ;
struct V_1 * V_6 = V_29 -> V_6 ;
struct V_27 * V_28 = & V_6 -> V_13 [ F_18 ( V_29 -> V_24 ) ] ;
F_26 ( V_6 -> V_3 , L_5 , V_29 -> V_24 , V_29 ) ;
F_28 ( & V_29 -> V_13 , V_28 ) ;
V_6 -> V_38 ++ ;
return 0 ;
}
static struct V_26 * F_29 ( struct V_1 * V_6 , T_1 V_24 ,
struct V_39 * V_40 )
{
struct V_33 * V_34 = & V_6 -> V_5 -> V_34 ;
struct V_26 * V_29 ;
struct V_27 * V_28 ;
unsigned char V_41 [ V_42 ] ;
F_30 ( & V_41 [ 0 ] , V_42 , V_40 -> V_43 . V_44 ) ;
V_28 = & V_6 -> V_13 [ F_18 ( V_24 ) ] ;
F_23 (sess, head, hash)
if ( V_29 -> V_24 == V_24 )
return V_29 ;
V_29 = F_5 ( sizeof( * V_29 ) , V_11 ) ;
if ( ! V_29 )
return F_31 ( - V_45 ) ;
F_32 ( & V_29 -> V_32 ) ;
V_29 -> V_6 = V_6 ;
V_29 -> V_24 = V_24 ;
V_29 -> V_36 = F_33 ( V_34 , V_46 ,
sizeof( struct V_47 ) ,
V_48 , & V_41 [ 0 ] ,
V_29 , F_27 ) ;
if ( F_34 ( V_29 -> V_36 ) ) {
int V_49 = F_35 ( V_29 -> V_36 ) ;
F_36 ( V_29 ) ;
V_29 = F_31 ( V_49 ) ;
}
return V_29 ;
}
static void F_37 ( struct V_26 * V_29 )
{
struct V_1 * V_6 = V_29 -> V_6 ;
F_38 ( & V_29 -> V_13 ) ;
F_10 ( ! V_6 -> V_38 ) ;
V_6 -> V_38 -- ;
V_29 -> V_24 = - 1 ;
V_29 -> V_50 = 0 ;
}
static struct V_26 * F_39 ( struct V_1 * V_6 , T_1 V_24 )
{
struct V_27 * V_28 ;
struct V_26 * V_29 ;
V_28 = & V_6 -> V_13 [ F_18 ( V_24 ) ] ;
F_23 (sess, head, hash) {
if ( V_29 -> V_24 == V_24 ) {
F_37 ( V_29 ) ;
return V_29 ;
}
}
return NULL ;
}
static void F_40 ( struct V_26 * V_29 )
{
F_41 ( V_29 -> V_36 ) ;
F_42 ( V_29 -> V_36 ) ;
F_43 ( V_29 -> V_36 ) ;
F_44 ( V_29 ) ;
}
static void F_9 ( struct V_1 * V_6 )
{
struct V_27 * V_28 ;
struct V_26 * V_29 ;
for ( V_28 = V_6 -> V_13 ;
V_28 < & V_6 -> V_13 [ V_12 ] ; V_28 ++ ) {
F_23 (sess, head, hash) {
F_37 ( V_29 ) ;
F_40 ( V_29 ) ;
}
}
}
void F_45 ( struct V_35 * V_36 )
{
struct V_26 * V_29 = V_36 -> V_51 ;
T_1 V_24 ;
F_14 ( & V_10 ) ;
V_24 = V_29 -> V_24 ;
if ( V_24 == - 1 ) {
F_15 ( & V_10 ) ;
return;
}
F_26 ( V_29 -> V_6 -> V_3 , L_6 , V_24 ) ;
F_37 ( V_29 ) ;
F_15 ( & V_10 ) ;
F_40 ( V_29 ) ;
F_46 () ;
}
T_1 F_47 ( struct V_35 * V_36 )
{
struct V_26 * V_29 = V_36 -> V_51 ;
return V_29 -> V_24 ;
}
T_1 F_48 ( struct V_35 * V_36 ,
unsigned char * V_52 , T_1 V_53 )
{
struct V_26 * V_29 = V_36 -> V_51 ;
return F_30 ( V_52 , V_53 , V_29 -> V_44 ) ;
}
static int F_49 ( struct V_39 * V_40 , T_1 V_54 ,
const struct V_55 * V_56 , struct V_55 * V_57 )
{
struct V_1 * V_6 ;
struct V_26 * V_29 ;
T_1 V_58 ;
V_6 = F_1 ( V_40 -> V_59 ) ;
if ( ! V_6 )
goto V_60;
if ( ! V_56 )
goto V_61;
if ( V_56 -> V_62 & ( V_63 | V_64 ) )
return V_65 ;
V_58 = F_50 ( V_56 -> V_66 ) ;
if ( ! ( V_58 & ( V_67 | V_15 ) ) )
return V_68 ;
if ( V_56 -> V_62 & V_69 ) {
V_57 -> V_62 |= V_69 ;
if ( ! ( V_58 & V_67 ) )
return V_70 ;
V_29 = F_29 ( V_6 , V_40 -> V_43 . V_24 , V_40 ) ;
if ( F_34 ( V_29 ) ) {
if ( F_35 ( V_29 ) == - V_71 ) {
V_57 -> V_62 &= ~ V_69 ;
return V_70 ;
} else
return V_72 ;
}
if ( ! V_29 -> V_50 )
V_40 -> V_73 ++ ;
V_29 -> V_50 = V_58 ;
V_29 -> V_44 = V_40 -> V_43 . V_44 ;
V_29 -> V_74 = V_40 -> V_75 ;
}
V_61:
V_58 = F_50 ( V_57 -> V_66 ) ;
V_58 &= ~ V_76 ;
V_57 -> V_66 = F_51 ( V_58 | V_15 ) ;
return V_77 ;
V_60:
V_58 = F_50 ( V_57 -> V_66 ) ;
V_58 &= ~ V_15 ;
V_57 -> V_66 = F_51 ( V_58 ) ;
return 0 ;
}
static int F_52 ( struct V_39 * V_40 , T_1 V_54 ,
const struct V_55 * V_56 , struct V_55 * V_57 )
{
int V_78 ;
F_14 ( & V_10 ) ;
V_78 = F_49 ( V_40 , V_54 , V_56 , V_57 ) ;
F_15 ( & V_10 ) ;
F_26 ( V_40 -> V_59 , L_7 ,
V_40 -> V_43 . V_24 , V_56 ? V_56 -> V_62 : 0 , V_78 ) ;
return V_78 ;
}
static void F_53 ( struct V_32 * V_32 )
{
struct V_26 * V_29 = F_54 ( V_32 , struct V_26 , V_32 ) ;
F_55 ( V_29 -> V_36 ) ;
F_12 ( V_29 , V_16 ) ;
}
void F_44 ( struct V_26 * V_29 )
{
int V_79 = F_56 ( & V_29 -> V_32 ) ;
F_10 ( ! V_79 ) ;
F_57 ( & V_29 -> V_32 , F_53 ) ;
}
static void F_58 ( struct V_39 * V_40 )
{
struct V_26 * V_29 ;
struct V_1 * V_6 ;
F_14 ( & V_10 ) ;
V_6 = F_2 ( V_40 -> V_59 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( ! V_6 ) {
F_15 ( & V_10 ) ;
return;
}
V_29 = F_39 ( V_6 , V_40 -> V_43 . V_24 ) ;
if ( ! V_29 ) {
F_15 ( & V_10 ) ;
return;
}
F_15 ( & V_10 ) ;
F_40 ( V_29 ) ;
V_40 -> V_73 -- ;
}
static void F_59 ( struct V_2 * V_3 , struct V_80 * V_81 )
{
struct V_26 * V_29 ;
T_1 V_82 = F_60 ( V_81 ) ;
F_26 ( V_3 , L_8 , V_82 ) ;
V_29 = F_20 ( V_3 , V_82 ) ;
if ( ! V_29 ) {
F_26 ( V_3 , L_9 , V_82 ) ;
F_61 ( V_81 ) ;
return;
}
F_62 ( V_29 , V_81 ) ;
}
