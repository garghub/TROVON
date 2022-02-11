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
F_10 ( V_6 != V_3 -> V_8 [ V_9 ] ) ;
F_7 ( V_3 -> V_8 [ V_9 ] , NULL ) ;
V_5 = V_6 -> V_5 ;
if ( V_5 ) {
V_5 -> V_6 = NULL ;
V_6 -> V_5 = NULL ;
}
F_11 ( V_6 , V_14 ) ;
}
void F_12 ( struct V_2 * V_3 , void * V_15 )
{
F_13 ( & V_10 ) ;
F_1 ( V_3 ) ;
F_14 ( & V_10 ) ;
}
void F_15 ( struct V_2 * V_3 , void * V_15 )
{
struct V_1 * V_6 ;
F_13 ( & V_10 ) ;
V_6 = V_3 -> V_8 [ V_9 ] ;
if ( V_6 )
F_8 ( V_6 ) ;
F_14 ( & V_10 ) ;
}
int F_16 ( struct V_16 * V_17 , unsigned long V_18 , void * V_15 )
{
struct V_2 * V_3 = V_15 ;
switch ( V_18 ) {
case V_19 :
F_12 ( V_3 , NULL ) ;
break;
case V_20 :
F_15 ( V_3 , NULL ) ;
break;
}
return V_21 ;
}
static T_1 F_17 ( T_1 V_22 )
{
return F_18 ( V_22 , V_23 ) ;
}
static struct V_24 * F_19 ( struct V_2 * V_3 , T_1 V_22 )
{
struct V_1 * V_6 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_24 * V_29 ;
F_20 () ;
V_6 = F_21 ( V_3 -> V_8 [ V_9 ] ) ;
if ( ! V_6 )
goto V_30;
V_26 = & V_6 -> V_13 [ F_17 ( V_22 ) ] ;
F_22 (sess, pos, head, hash) {
if ( V_29 -> V_22 == V_22 ) {
F_23 ( & V_29 -> V_31 ) ;
F_24 () ;
F_25 ( L_1 , V_22 , V_29 ) ;
return V_29 ;
}
}
V_30:
F_24 () ;
F_25 ( L_2 , V_22 ) ;
return NULL ;
}
static struct V_24 * F_26 ( struct V_1 * V_6 , T_1 V_22 ,
struct V_32 * V_33 )
{
struct V_24 * V_29 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_26 = & V_6 -> V_13 [ F_17 ( V_22 ) ] ;
F_22 (sess, pos, head, hash)
if ( V_29 -> V_22 == V_22 )
return V_29 ;
V_29 = F_5 ( sizeof( * V_29 ) , V_11 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_34 = F_27 () ;
if ( F_28 ( V_29 -> V_34 ) ) {
F_29 ( V_29 ) ;
return NULL ;
}
V_29 -> V_34 -> V_35 = & V_33 -> V_35 ;
V_29 -> V_6 = V_6 ;
V_29 -> V_22 = V_22 ;
F_30 ( & V_29 -> V_31 ) ;
F_31 ( & V_29 -> V_13 , V_26 ) ;
V_6 -> V_36 ++ ;
F_25 ( L_3 , V_22 , V_29 ) ;
F_32 ( & V_6 -> V_5 -> V_37 , & V_33 -> V_35 ,
V_29 -> V_34 , V_29 ) ;
return V_29 ;
}
static void F_33 ( struct V_24 * V_29 )
{
struct V_1 * V_6 = V_29 -> V_6 ;
F_34 ( & V_29 -> V_13 ) ;
F_10 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
V_29 -> V_22 = - 1 ;
V_29 -> V_38 = 0 ;
}
static struct V_24 * F_35 ( struct V_1 * V_6 , T_1 V_22 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_24 * V_29 ;
V_26 = & V_6 -> V_13 [ F_17 ( V_22 ) ] ;
F_22 (sess, pos, head, hash) {
if ( V_29 -> V_22 == V_22 ) {
F_33 ( V_29 ) ;
return V_29 ;
}
}
return NULL ;
}
static void F_9 ( struct V_1 * V_6 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_24 * V_29 ;
for ( V_26 = V_6 -> V_13 ;
V_26 < & V_6 -> V_13 [ V_12 ] ; V_26 ++ ) {
F_22 (sess, pos, head, hash) {
F_33 ( V_29 ) ;
F_36 ( V_29 -> V_34 ) ;
F_37 ( V_29 ) ;
}
}
}
int F_38 ( struct V_39 * V_34 )
{
struct V_24 * V_29 = V_34 -> V_40 ;
F_25 ( L_4 , V_29 -> V_22 ) ;
return 1 ;
}
void F_39 ( struct V_39 * V_34 )
{
struct V_24 * V_29 = V_34 -> V_40 ;
T_1 V_22 ;
F_13 ( & V_10 ) ;
V_22 = V_29 -> V_22 ;
if ( V_22 == - 1 ) {
F_14 ( & V_10 ) ;
return;
}
F_25 ( L_4 , V_22 ) ;
F_33 ( V_29 ) ;
F_14 ( & V_10 ) ;
F_36 ( V_34 ) ;
F_37 ( V_29 ) ;
F_40 () ;
}
T_1 F_41 ( struct V_39 * V_34 )
{
struct V_24 * V_29 = V_34 -> V_40 ;
return V_29 -> V_22 ;
}
T_1 F_42 ( struct V_39 * V_34 ,
unsigned char * V_41 , T_1 V_42 )
{
struct V_24 * V_29 = V_34 -> V_40 ;
return F_43 ( V_41 , V_42 , V_29 -> V_43 ) ;
}
static int F_44 ( struct V_44 * V_45 , T_1 V_46 ,
const struct V_47 * V_48 , struct V_47 * V_49 )
{
struct V_1 * V_6 ;
struct V_24 * V_29 ;
struct V_32 * V_33 ;
T_1 V_50 ;
V_6 = F_1 ( V_45 -> V_51 ) ;
if ( ! V_6 )
goto V_52;
V_33 = F_45 ( V_6 -> V_5 , V_45 ) ;
if ( ! V_33 )
goto V_52;
if ( ! V_48 )
goto V_53;
if ( V_48 -> V_54 & ( V_55 | V_56 ) )
return V_57 ;
V_50 = F_46 ( V_48 -> V_58 ) ;
if ( ! ( V_50 & ( V_59 | V_60 ) ) )
return V_61 ;
if ( V_48 -> V_54 & V_62 ) {
V_49 -> V_54 |= V_62 ;
if ( ! ( V_50 & V_59 ) )
return V_63 ;
V_29 = F_26 ( V_6 , V_45 -> V_64 . V_22 , V_33 ) ;
if ( ! V_29 )
return V_65 ;
if ( ! V_29 -> V_38 )
V_45 -> V_66 ++ ;
V_29 -> V_38 = V_50 ;
V_29 -> V_43 = V_45 -> V_64 . V_43 ;
V_29 -> V_67 = V_45 -> V_68 ;
}
V_53:
V_50 = F_46 ( V_49 -> V_58 ) ;
V_50 &= ~ V_69 ;
V_49 -> V_58 = F_47 ( V_50 | V_60 ) ;
return V_70 ;
V_52:
V_50 = F_46 ( V_49 -> V_58 ) ;
V_50 &= ~ V_60 ;
V_49 -> V_58 = F_47 ( V_50 ) ;
return 0 ;
}
static int F_48 ( struct V_44 * V_45 , T_1 V_46 ,
const struct V_47 * V_48 , struct V_47 * V_49 )
{
int V_71 ;
F_13 ( & V_10 ) ;
V_71 = F_44 ( V_45 , V_46 , V_48 , V_49 ) ;
F_14 ( & V_10 ) ;
F_25 ( L_5 ,
V_45 -> V_64 . V_22 , V_48 ? V_48 -> V_54 : 0 , V_71 ) ;
return V_71 ;
}
static void F_49 ( struct V_72 * V_14 )
{
struct V_24 * V_29 = F_50 ( V_14 , struct V_24 , V_14 ) ;
F_29 ( V_29 ) ;
}
static void F_51 ( struct V_31 * V_31 )
{
struct V_24 * V_29 = F_50 ( V_31 , struct V_24 , V_31 ) ;
F_52 ( V_29 -> V_34 ) ;
F_53 ( & V_29 -> V_14 , F_49 ) ;
}
void F_37 ( struct V_24 * V_29 )
{
int V_73 = F_54 ( & V_29 -> V_31 . V_74 ) ;
F_10 ( ! V_73 ) ;
F_55 ( & V_29 -> V_31 , F_51 ) ;
}
static void F_56 ( struct V_44 * V_45 )
{
struct V_24 * V_29 ;
struct V_1 * V_6 ;
F_13 ( & V_10 ) ;
V_6 = F_2 ( V_45 -> V_51 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( ! V_6 ) {
F_14 ( & V_10 ) ;
return;
}
V_29 = F_35 ( V_6 , V_45 -> V_64 . V_22 ) ;
if ( ! V_29 ) {
F_14 ( & V_10 ) ;
return;
}
F_14 ( & V_10 ) ;
F_36 ( V_29 -> V_34 ) ;
F_37 ( V_29 ) ;
V_45 -> V_66 -- ;
}
static void F_57 ( struct V_2 * V_3 , struct V_75 * V_76 )
{
struct V_24 * V_29 ;
T_1 V_77 = F_58 ( V_76 ) ;
F_25 ( L_6 , V_77 ) ;
V_29 = F_19 ( V_3 , V_77 ) ;
if ( ! V_29 ) {
F_25 ( L_7 , V_77 ) ;
F_59 ( V_76 ) ;
return;
}
F_60 ( V_29 , V_76 ) ;
}
