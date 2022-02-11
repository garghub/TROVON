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
F_21 () ;
V_6 = F_22 ( V_3 -> V_8 [ V_9 ] ) ;
if ( ! V_6 )
goto V_30;
V_28 = & V_6 -> V_13 [ F_18 ( V_24 ) ] ;
F_23 (sess, head, hash) {
if ( V_29 -> V_24 == V_24 ) {
F_24 ( & V_29 -> V_31 ) ;
F_25 () ;
F_26 ( L_1 , V_24 , V_29 ) ;
return V_29 ;
}
}
V_30:
F_25 () ;
F_26 ( L_2 , V_24 ) ;
return NULL ;
}
static int F_27 ( struct V_32 * V_33 ,
struct V_34 * V_35 , void * V_36 )
{
struct V_26 * V_29 = V_36 ;
struct V_1 * V_6 = V_29 -> V_6 ;
struct V_27 * V_28 = & V_6 -> V_13 [ F_18 ( V_29 -> V_24 ) ] ;
F_26 ( L_3 , V_29 -> V_24 , V_29 ) ;
F_28 ( & V_29 -> V_13 , V_28 ) ;
V_6 -> V_37 ++ ;
return 0 ;
}
static struct V_26 * F_29 ( struct V_1 * V_6 , T_1 V_24 ,
struct V_38 * V_39 )
{
struct V_32 * V_33 = & V_6 -> V_5 -> V_33 ;
struct V_26 * V_29 ;
struct V_27 * V_28 ;
unsigned char V_40 [ V_41 ] ;
F_30 ( & V_40 [ 0 ] , V_41 , V_39 -> V_42 . V_43 ) ;
V_28 = & V_6 -> V_13 [ F_18 ( V_24 ) ] ;
F_23 (sess, head, hash)
if ( V_29 -> V_24 == V_24 )
return V_29 ;
V_29 = F_5 ( sizeof( * V_29 ) , V_11 ) ;
if ( ! V_29 )
return NULL ;
F_31 ( & V_29 -> V_31 ) ;
V_29 -> V_6 = V_6 ;
V_29 -> V_24 = V_24 ;
V_29 -> V_35 = F_32 ( V_33 , V_44 ,
sizeof( struct V_45 ) ,
V_46 , & V_40 [ 0 ] ,
V_29 , F_27 ) ;
if ( F_33 ( V_29 -> V_35 ) ) {
F_34 ( V_29 ) ;
return NULL ;
}
return V_29 ;
}
static void F_35 ( struct V_26 * V_29 )
{
struct V_1 * V_6 = V_29 -> V_6 ;
F_36 ( & V_29 -> V_13 ) ;
F_10 ( ! V_6 -> V_37 ) ;
V_6 -> V_37 -- ;
V_29 -> V_24 = - 1 ;
V_29 -> V_47 = 0 ;
}
static struct V_26 * F_37 ( struct V_1 * V_6 , T_1 V_24 )
{
struct V_27 * V_28 ;
struct V_26 * V_29 ;
V_28 = & V_6 -> V_13 [ F_18 ( V_24 ) ] ;
F_23 (sess, head, hash) {
if ( V_29 -> V_24 == V_24 ) {
F_35 ( V_29 ) ;
return V_29 ;
}
}
return NULL ;
}
static void F_38 ( struct V_26 * V_29 )
{
F_39 ( V_29 -> V_35 ) ;
F_40 ( V_29 -> V_35 ) ;
F_41 ( V_29 -> V_35 ) ;
F_42 ( V_29 ) ;
}
static void F_9 ( struct V_1 * V_6 )
{
struct V_27 * V_28 ;
struct V_26 * V_29 ;
for ( V_28 = V_6 -> V_13 ;
V_28 < & V_6 -> V_13 [ V_12 ] ; V_28 ++ ) {
F_23 (sess, head, hash) {
F_35 ( V_29 ) ;
F_38 ( V_29 ) ;
}
}
}
void F_43 ( struct V_34 * V_35 )
{
struct V_26 * V_29 = V_35 -> V_48 ;
T_1 V_24 ;
F_14 ( & V_10 ) ;
V_24 = V_29 -> V_24 ;
if ( V_24 == - 1 ) {
F_15 ( & V_10 ) ;
return;
}
F_26 ( L_4 , V_24 ) ;
F_35 ( V_29 ) ;
F_15 ( & V_10 ) ;
F_38 ( V_29 ) ;
F_44 () ;
}
T_1 F_45 ( struct V_34 * V_35 )
{
struct V_26 * V_29 = V_35 -> V_48 ;
return V_29 -> V_24 ;
}
T_1 F_46 ( struct V_34 * V_35 ,
unsigned char * V_49 , T_1 V_50 )
{
struct V_26 * V_29 = V_35 -> V_48 ;
return F_30 ( V_49 , V_50 , V_29 -> V_43 ) ;
}
static int F_47 ( struct V_38 * V_39 , T_1 V_51 ,
const struct V_52 * V_53 , struct V_52 * V_54 )
{
struct V_1 * V_6 ;
struct V_26 * V_29 ;
T_1 V_55 ;
V_6 = F_1 ( V_39 -> V_56 ) ;
if ( ! V_6 )
goto V_57;
if ( ! V_53 )
goto V_58;
if ( V_53 -> V_59 & ( V_60 | V_61 ) )
return V_62 ;
V_55 = F_48 ( V_53 -> V_63 ) ;
if ( ! ( V_55 & ( V_64 | V_15 ) ) )
return V_65 ;
if ( V_53 -> V_59 & V_66 ) {
V_54 -> V_59 |= V_66 ;
if ( ! ( V_55 & V_64 ) )
return V_67 ;
V_29 = F_29 ( V_6 , V_39 -> V_42 . V_24 , V_39 ) ;
if ( ! V_29 )
return V_68 ;
if ( ! V_29 -> V_47 )
V_39 -> V_69 ++ ;
V_29 -> V_47 = V_55 ;
V_29 -> V_43 = V_39 -> V_42 . V_43 ;
V_29 -> V_70 = V_39 -> V_71 ;
}
V_58:
V_55 = F_48 ( V_54 -> V_63 ) ;
V_55 &= ~ V_72 ;
V_54 -> V_63 = F_49 ( V_55 | V_15 ) ;
return V_73 ;
V_57:
V_55 = F_48 ( V_54 -> V_63 ) ;
V_55 &= ~ V_15 ;
V_54 -> V_63 = F_49 ( V_55 ) ;
return 0 ;
}
static int F_50 ( struct V_38 * V_39 , T_1 V_51 ,
const struct V_52 * V_53 , struct V_52 * V_54 )
{
int V_74 ;
F_14 ( & V_10 ) ;
V_74 = F_47 ( V_39 , V_51 , V_53 , V_54 ) ;
F_15 ( & V_10 ) ;
F_26 ( L_5 ,
V_39 -> V_42 . V_24 , V_53 ? V_53 -> V_59 : 0 , V_74 ) ;
return V_74 ;
}
static void F_51 ( struct V_31 * V_31 )
{
struct V_26 * V_29 = F_52 ( V_31 , struct V_26 , V_31 ) ;
F_53 ( V_29 -> V_35 ) ;
F_12 ( V_29 , V_16 ) ;
}
void F_42 ( struct V_26 * V_29 )
{
int V_75 = F_54 ( & V_29 -> V_31 . V_76 ) ;
F_10 ( ! V_75 ) ;
F_55 ( & V_29 -> V_31 , F_51 ) ;
}
static void F_56 ( struct V_38 * V_39 )
{
struct V_26 * V_29 ;
struct V_1 * V_6 ;
F_14 ( & V_10 ) ;
V_6 = F_2 ( V_39 -> V_56 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( ! V_6 ) {
F_15 ( & V_10 ) ;
return;
}
V_29 = F_37 ( V_6 , V_39 -> V_42 . V_24 ) ;
if ( ! V_29 ) {
F_15 ( & V_10 ) ;
return;
}
F_15 ( & V_10 ) ;
F_38 ( V_29 ) ;
V_39 -> V_69 -- ;
}
static void F_57 ( struct V_2 * V_3 , struct V_77 * V_78 )
{
struct V_26 * V_29 ;
T_1 V_79 = F_58 ( V_78 ) ;
F_26 ( L_6 , V_79 ) ;
V_29 = F_20 ( V_3 , V_79 ) ;
if ( ! V_29 ) {
F_26 ( L_7 , V_79 ) ;
F_59 ( V_78 ) ;
return;
}
F_60 ( V_29 , V_78 ) ;
}
