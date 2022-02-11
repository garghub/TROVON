static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_3 -> V_8 [ V_9 ] ) ;
if ( V_6 && V_6 -> V_5 )
return V_6 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return NULL ;
if ( V_6 ) {
V_6 -> V_5 = V_5 ;
return V_6 ;
}
V_6 = F_4 ( sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = V_5 ;
V_5 -> V_6 = V_6 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ )
F_5 ( & V_6 -> V_12 [ V_7 ] ) ;
F_6 ( V_3 -> V_8 [ V_9 ] , V_6 ) ;
return V_6 ;
}
static void F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_6 = F_8 ( V_14 , struct V_1 , V_14 ) ;
F_9 ( V_6 ) ;
}
static void F_10 ( struct V_1 * V_6 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
F_11 ( V_6 ) ;
V_3 = V_6 -> V_3 ;
F_12 ( V_6 != V_3 -> V_8 [ V_9 ] ) ;
F_6 ( V_3 -> V_8 [ V_9 ] , NULL ) ;
V_5 = V_6 -> V_5 ;
if ( V_5 ) {
V_5 -> V_6 = NULL ;
V_6 -> V_5 = NULL ;
}
F_13 ( & V_6 -> V_14 , F_7 ) ;
}
void F_14 ( struct V_2 * V_3 , void * V_15 )
{
F_15 ( & V_16 ) ;
F_1 ( V_3 ) ;
F_16 ( & V_16 ) ;
}
void F_17 ( struct V_2 * V_3 , void * V_15 )
{
struct V_1 * V_6 ;
F_15 ( & V_16 ) ;
V_6 = V_3 -> V_8 [ V_9 ] ;
if ( V_6 )
F_10 ( V_6 ) ;
F_16 ( & V_16 ) ;
}
int F_18 ( struct V_17 * V_18 , unsigned long V_19 , void * V_15 )
{
struct V_2 * V_3 = V_15 ;
switch ( V_19 ) {
case V_20 :
F_14 ( V_3 , NULL ) ;
break;
case V_21 :
F_17 ( V_3 , NULL ) ;
break;
}
return V_22 ;
}
static T_1 F_19 ( T_1 V_23 )
{
return F_20 ( V_23 , V_24 ) ;
}
static struct V_25 * F_21 ( struct V_2 * V_3 , T_1 V_23 )
{
struct V_1 * V_6 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_25 * V_30 ;
F_22 () ;
V_6 = F_2 ( V_3 -> V_8 [ V_9 ] ) ;
if ( ! V_6 )
goto V_31;
V_27 = & V_6 -> V_12 [ F_19 ( V_23 ) ] ;
F_23 (sess, pos, head, hash) {
if ( V_30 -> V_23 == V_23 ) {
F_24 ( & V_30 -> V_32 ) ;
F_25 () ;
F_26 ( L_1 , V_23 , V_30 ) ;
return V_30 ;
}
}
V_31:
F_25 () ;
F_26 ( L_2 , V_23 ) ;
return NULL ;
}
static struct V_25 * F_27 ( struct V_1 * V_6 , T_1 V_23 ,
struct V_33 * V_34 )
{
struct V_25 * V_30 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = & V_6 -> V_12 [ F_19 ( V_23 ) ] ;
F_23 (sess, pos, head, hash)
if ( V_30 -> V_23 == V_23 )
return V_30 ;
V_30 = F_4 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_35 = F_28 () ;
if ( F_29 ( V_30 -> V_35 ) ) {
F_9 ( V_30 ) ;
return NULL ;
}
V_30 -> V_35 -> V_36 = & V_34 -> V_36 ;
V_30 -> V_6 = V_6 ;
V_30 -> V_23 = V_23 ;
F_30 ( & V_30 -> V_32 ) ;
F_31 ( & V_30 -> V_12 , V_27 ) ;
V_6 -> V_37 ++ ;
F_26 ( L_3 , V_23 , V_30 ) ;
F_32 ( & V_6 -> V_5 -> V_38 , & V_34 -> V_36 ,
V_30 -> V_35 , V_30 ) ;
return V_30 ;
}
static void F_33 ( struct V_25 * V_30 )
{
struct V_1 * V_6 = V_30 -> V_6 ;
F_34 ( & V_30 -> V_12 ) ;
F_12 ( ! V_6 -> V_37 ) ;
V_6 -> V_37 -- ;
V_30 -> V_23 = - 1 ;
V_30 -> V_39 = 0 ;
}
static struct V_25 * F_35 ( struct V_1 * V_6 , T_1 V_23 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_25 * V_30 ;
V_27 = & V_6 -> V_12 [ F_19 ( V_23 ) ] ;
F_23 (sess, pos, head, hash) {
if ( V_30 -> V_23 == V_23 ) {
F_33 ( V_30 ) ;
return V_30 ;
}
}
return NULL ;
}
static void F_11 ( struct V_1 * V_6 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_25 * V_30 ;
for ( V_27 = V_6 -> V_12 ;
V_27 < & V_6 -> V_12 [ V_11 ] ; V_27 ++ ) {
F_23 (sess, pos, head, hash) {
F_33 ( V_30 ) ;
F_36 ( V_30 -> V_35 ) ;
F_37 ( V_30 ) ;
}
}
}
int F_38 ( struct V_40 * V_35 )
{
struct V_25 * V_30 = V_35 -> V_41 ;
F_26 ( L_4 , V_30 -> V_23 ) ;
return 1 ;
}
void F_39 ( struct V_40 * V_35 )
{
struct V_25 * V_30 = V_35 -> V_41 ;
struct V_2 * V_3 ;
T_1 V_23 ;
F_15 ( & V_16 ) ;
V_3 = V_30 -> V_6 -> V_3 ;
V_23 = V_30 -> V_23 ;
if ( V_23 == - 1 ) {
F_16 ( & V_16 ) ;
return;
}
F_26 ( L_4 , V_23 ) ;
F_33 ( V_30 ) ;
F_16 ( & V_16 ) ;
F_36 ( V_35 ) ;
F_37 ( V_30 ) ;
F_40 () ;
}
void F_41 ( struct V_40 * V_35 , int V_42 , int V_43 )
{
struct V_25 * V_30 = V_35 -> V_41 ;
F_26 ( L_4 , V_30 -> V_23 ) ;
}
int F_42 ( struct V_40 * V_35 )
{
struct V_25 * V_30 = V_35 -> V_41 ;
return V_30 -> V_23 != - 1 ;
}
T_1 F_43 ( struct V_40 * V_35 )
{
struct V_25 * V_30 = V_35 -> V_41 ;
return V_30 -> V_23 ;
}
T_1 F_44 ( struct V_40 * V_35 ,
unsigned char * V_44 , T_1 V_45 )
{
struct V_25 * V_30 = V_35 -> V_41 ;
return F_45 ( V_44 , V_45 , V_30 -> V_46 ) ;
}
void F_46 ( struct V_40 * V_35 )
{
}
static int F_47 ( struct V_47 * V_48 , T_1 V_49 ,
const struct V_50 * V_51 , struct V_50 * V_52 )
{
struct V_1 * V_6 ;
struct V_25 * V_30 ;
struct V_33 * V_34 ;
T_1 V_53 ;
V_6 = F_1 ( V_48 -> V_54 ) ;
if ( ! V_6 )
return 0 ;
V_34 = F_48 ( V_6 -> V_5 , V_48 ) ;
if ( ! V_34 )
return 0 ;
if ( ! V_51 )
goto V_55;
if ( V_51 -> V_56 & ( V_57 | V_58 ) )
return V_59 ;
V_53 = F_49 ( V_51 -> V_60 ) ;
if ( ! ( V_53 & ( V_61 | V_62 ) ) )
return V_63 ;
if ( V_51 -> V_56 & V_64 ) {
V_52 -> V_56 |= V_64 ;
if ( ! ( V_53 & V_61 ) )
return V_65 ;
V_30 = F_27 ( V_6 , V_48 -> V_66 . V_23 , V_34 ) ;
if ( ! V_30 )
return V_67 ;
if ( ! V_30 -> V_39 )
V_48 -> V_68 ++ ;
V_30 -> V_39 = V_53 ;
V_30 -> V_46 = V_48 -> V_66 . V_46 ;
V_30 -> V_69 = V_48 -> V_70 ;
}
V_55:
V_53 = F_49 ( V_52 -> V_60 ) ;
V_52 -> V_60 = F_50 ( V_53 | V_62 ) ;
return V_71 ;
}
static int F_51 ( struct V_47 * V_48 , T_1 V_49 ,
const struct V_50 * V_51 , struct V_50 * V_52 )
{
int V_72 ;
F_15 ( & V_16 ) ;
V_72 = F_47 ( V_48 , V_49 , V_51 , V_52 ) ;
F_16 ( & V_16 ) ;
F_26 ( L_5 ,
V_48 -> V_66 . V_23 , V_51 ? V_51 -> V_56 : 0 , V_72 ) ;
return V_72 ;
}
static void F_52 ( struct V_13 * V_14 )
{
struct V_25 * V_30 = F_8 ( V_14 , struct V_25 , V_14 ) ;
F_53 ( V_30 -> V_35 ) ;
F_9 ( V_30 ) ;
}
static void F_54 ( struct V_32 * V_32 )
{
struct V_25 * V_30 = F_8 ( V_32 , struct V_25 , V_32 ) ;
F_13 ( & V_30 -> V_14 , F_52 ) ;
}
void F_37 ( struct V_25 * V_30 )
{
int V_73 = F_55 ( & V_30 -> V_32 . V_74 ) ;
F_12 ( ! V_73 ) ;
F_56 ( & V_30 -> V_32 , F_54 ) ;
}
static void F_57 ( struct V_47 * V_48 )
{
struct V_25 * V_30 ;
struct V_1 * V_6 ;
F_15 ( & V_16 ) ;
V_6 = F_2 ( V_48 -> V_54 -> V_8 [ V_9 ] ) ;
if ( ! V_6 ) {
F_16 ( & V_16 ) ;
return;
}
V_30 = F_35 ( V_6 , V_48 -> V_66 . V_23 ) ;
if ( ! V_30 ) {
F_16 ( & V_16 ) ;
return;
}
F_16 ( & V_16 ) ;
F_36 ( V_30 -> V_35 ) ;
F_37 ( V_30 ) ;
V_48 -> V_68 -- ;
}
static void F_58 ( struct V_2 * V_3 , struct V_75 * V_76 )
{
struct V_25 * V_30 ;
T_1 V_77 = F_59 ( V_76 ) ;
F_26 ( L_6 , V_77 ) ;
V_30 = F_21 ( V_3 , V_77 ) ;
if ( ! V_30 ) {
F_26 ( L_7 , V_77 ) ;
F_60 ( V_76 ) ;
return;
}
F_61 ( V_30 , V_76 ) ;
}
