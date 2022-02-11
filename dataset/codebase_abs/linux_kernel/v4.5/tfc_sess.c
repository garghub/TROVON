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
F_10 ( V_6 != V_3 -> V_8 [ V_9 ] ) ;
F_11 ( V_3 -> V_8 [ V_9 ] , NULL ) ;
V_5 = V_6 -> V_5 ;
if ( V_5 ) {
V_5 -> V_6 = NULL ;
V_6 -> V_5 = NULL ;
}
F_12 ( V_6 , V_14 ) ;
}
void F_13 ( struct V_2 * V_3 , void * V_15 )
{
F_14 ( & V_10 ) ;
F_1 ( V_3 ) ;
F_15 ( & V_10 ) ;
}
void F_16 ( struct V_2 * V_3 , void * V_15 )
{
struct V_1 * V_6 ;
F_14 ( & V_10 ) ;
V_6 = V_3 -> V_8 [ V_9 ] ;
if ( V_6 )
F_8 ( V_6 ) ;
F_15 ( & V_10 ) ;
}
int F_17 ( struct V_16 * V_17 , unsigned long V_18 , void * V_15 )
{
struct V_2 * V_3 = V_15 ;
switch ( V_18 ) {
case V_19 :
F_13 ( V_3 , NULL ) ;
break;
case V_20 :
F_16 ( V_3 , NULL ) ;
break;
}
return V_21 ;
}
static T_1 F_18 ( T_1 V_22 )
{
return F_19 ( V_22 , V_23 ) ;
}
static struct V_24 * F_20 ( struct V_2 * V_3 , T_1 V_22 )
{
struct V_1 * V_6 ;
struct V_25 * V_26 ;
struct V_24 * V_27 ;
F_21 () ;
V_6 = F_22 ( V_3 -> V_8 [ V_9 ] ) ;
if ( ! V_6 )
goto V_28;
V_26 = & V_6 -> V_13 [ F_18 ( V_22 ) ] ;
F_23 (sess, head, hash) {
if ( V_27 -> V_22 == V_22 ) {
F_24 ( & V_27 -> V_29 ) ;
F_25 () ;
F_26 ( L_1 , V_22 , V_27 ) ;
return V_27 ;
}
}
V_28:
F_25 () ;
F_26 ( L_2 , V_22 ) ;
return NULL ;
}
static struct V_24 * F_27 ( struct V_1 * V_6 , T_1 V_22 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_6 -> V_5 -> V_33 ;
struct V_34 * V_35 ;
struct V_24 * V_27 ;
struct V_25 * V_26 ;
unsigned char V_36 [ V_37 ] ;
F_28 ( & V_36 [ 0 ] , V_37 , V_31 -> V_38 . V_39 ) ;
V_26 = & V_6 -> V_13 [ F_18 ( V_22 ) ] ;
F_23 (sess, head, hash)
if ( V_27 -> V_22 == V_22 )
return V_27 ;
V_27 = F_5 ( sizeof( * V_27 ) , V_11 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_40 = F_29 ( V_41 ,
sizeof( struct V_42 ) ,
V_43 ) ;
if ( F_30 ( V_27 -> V_40 ) ) {
F_31 ( V_27 ) ;
return NULL ;
}
V_35 = F_32 ( V_33 , & V_36 [ 0 ] ) ;
if ( ! V_35 ) {
F_33 ( V_27 -> V_40 ) ;
F_31 ( V_27 ) ;
return NULL ;
}
V_27 -> V_40 -> V_34 = V_35 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_22 = V_22 ;
F_34 ( & V_27 -> V_29 ) ;
F_35 ( & V_27 -> V_13 , V_26 ) ;
V_6 -> V_44 ++ ;
F_26 ( L_3 , V_22 , V_27 ) ;
F_36 ( & V_6 -> V_5 -> V_33 , V_35 ,
V_27 -> V_40 , V_27 ) ;
return V_27 ;
}
static void F_37 ( struct V_24 * V_27 )
{
struct V_1 * V_6 = V_27 -> V_6 ;
F_38 ( & V_27 -> V_13 ) ;
F_10 ( ! V_6 -> V_44 ) ;
V_6 -> V_44 -- ;
V_27 -> V_22 = - 1 ;
V_27 -> V_45 = 0 ;
}
static struct V_24 * F_39 ( struct V_1 * V_6 , T_1 V_22 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
V_26 = & V_6 -> V_13 [ F_18 ( V_22 ) ] ;
F_23 (sess, head, hash) {
if ( V_27 -> V_22 == V_22 ) {
F_37 ( V_27 ) ;
return V_27 ;
}
}
return NULL ;
}
static void F_40 ( struct V_24 * V_27 )
{
F_41 ( V_27 -> V_40 ) ;
F_42 ( V_27 -> V_40 ) ;
F_43 ( V_27 -> V_40 ) ;
F_44 ( V_27 ) ;
}
static void F_9 ( struct V_1 * V_6 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
for ( V_26 = V_6 -> V_13 ;
V_26 < & V_6 -> V_13 [ V_12 ] ; V_26 ++ ) {
F_23 (sess, head, hash) {
F_37 ( V_27 ) ;
F_40 ( V_27 ) ;
}
}
}
int F_45 ( struct V_46 * V_40 )
{
struct V_24 * V_27 = V_40 -> V_47 ;
F_26 ( L_4 , V_27 -> V_22 ) ;
return 1 ;
}
void F_46 ( struct V_46 * V_40 )
{
struct V_24 * V_27 = V_40 -> V_47 ;
T_1 V_22 ;
F_14 ( & V_10 ) ;
V_22 = V_27 -> V_22 ;
if ( V_22 == - 1 ) {
F_15 ( & V_10 ) ;
return;
}
F_26 ( L_4 , V_22 ) ;
F_37 ( V_27 ) ;
F_15 ( & V_10 ) ;
F_40 ( V_27 ) ;
F_47 () ;
}
T_1 F_48 ( struct V_46 * V_40 )
{
struct V_24 * V_27 = V_40 -> V_47 ;
return V_27 -> V_22 ;
}
T_1 F_49 ( struct V_46 * V_40 ,
unsigned char * V_48 , T_1 V_49 )
{
struct V_24 * V_27 = V_40 -> V_47 ;
return F_28 ( V_48 , V_49 , V_27 -> V_39 ) ;
}
static int F_50 ( struct V_30 * V_31 , T_1 V_50 ,
const struct V_51 * V_52 , struct V_51 * V_53 )
{
struct V_1 * V_6 ;
struct V_24 * V_27 ;
T_1 V_54 ;
V_6 = F_1 ( V_31 -> V_55 ) ;
if ( ! V_6 )
goto V_56;
if ( ! V_52 )
goto V_57;
if ( V_52 -> V_58 & ( V_59 | V_60 ) )
return V_61 ;
V_54 = F_51 ( V_52 -> V_62 ) ;
if ( ! ( V_54 & ( V_63 | V_64 ) ) )
return V_65 ;
if ( V_52 -> V_58 & V_66 ) {
V_53 -> V_58 |= V_66 ;
if ( ! ( V_54 & V_63 ) )
return V_67 ;
V_27 = F_27 ( V_6 , V_31 -> V_38 . V_22 , V_31 ) ;
if ( ! V_27 )
return V_68 ;
if ( ! V_27 -> V_45 )
V_31 -> V_69 ++ ;
V_27 -> V_45 = V_54 ;
V_27 -> V_39 = V_31 -> V_38 . V_39 ;
V_27 -> V_70 = V_31 -> V_71 ;
}
V_57:
V_54 = F_51 ( V_53 -> V_62 ) ;
V_54 &= ~ V_72 ;
V_53 -> V_62 = F_52 ( V_54 | V_64 ) ;
return V_73 ;
V_56:
V_54 = F_51 ( V_53 -> V_62 ) ;
V_54 &= ~ V_64 ;
V_53 -> V_62 = F_52 ( V_54 ) ;
return 0 ;
}
static int F_53 ( struct V_30 * V_31 , T_1 V_50 ,
const struct V_51 * V_52 , struct V_51 * V_53 )
{
int V_74 ;
F_14 ( & V_10 ) ;
V_74 = F_50 ( V_31 , V_50 , V_52 , V_53 ) ;
F_15 ( & V_10 ) ;
F_26 ( L_5 ,
V_31 -> V_38 . V_22 , V_52 ? V_52 -> V_58 : 0 , V_74 ) ;
return V_74 ;
}
static void F_54 ( struct V_29 * V_29 )
{
struct V_24 * V_27 = F_55 ( V_29 , struct V_24 , V_29 ) ;
F_56 ( V_27 -> V_40 ) ;
F_12 ( V_27 , V_14 ) ;
}
void F_44 ( struct V_24 * V_27 )
{
int V_75 = F_57 ( & V_27 -> V_29 . V_76 ) ;
F_10 ( ! V_75 ) ;
F_58 ( & V_27 -> V_29 , F_54 ) ;
}
static void F_59 ( struct V_30 * V_31 )
{
struct V_24 * V_27 ;
struct V_1 * V_6 ;
F_14 ( & V_10 ) ;
V_6 = F_2 ( V_31 -> V_55 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( ! V_6 ) {
F_15 ( & V_10 ) ;
return;
}
V_27 = F_39 ( V_6 , V_31 -> V_38 . V_22 ) ;
if ( ! V_27 ) {
F_15 ( & V_10 ) ;
return;
}
F_15 ( & V_10 ) ;
F_40 ( V_27 ) ;
V_31 -> V_69 -- ;
}
static void F_60 ( struct V_2 * V_3 , struct V_77 * V_78 )
{
struct V_24 * V_27 ;
T_1 V_79 = F_61 ( V_78 ) ;
F_26 ( L_6 , V_79 ) ;
V_27 = F_20 ( V_3 , V_79 ) ;
if ( ! V_27 ) {
F_26 ( L_7 , V_79 ) ;
F_62 ( V_78 ) ;
return;
}
F_63 ( V_27 , V_78 ) ;
}
