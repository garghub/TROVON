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
struct V_24 * V_27 ;
F_20 () ;
V_6 = F_21 ( V_3 -> V_8 [ V_9 ] ) ;
if ( ! V_6 )
goto V_28;
V_26 = & V_6 -> V_13 [ F_17 ( V_22 ) ] ;
F_22 (sess, head, hash) {
if ( V_27 -> V_22 == V_22 ) {
F_23 ( & V_27 -> V_29 ) ;
F_24 () ;
F_25 ( L_1 , V_22 , V_27 ) ;
return V_27 ;
}
}
V_28:
F_24 () ;
F_25 ( L_2 , V_22 ) ;
return NULL ;
}
static struct V_24 * F_26 ( struct V_1 * V_6 , T_1 V_22 ,
struct V_30 * V_31 )
{
struct V_24 * V_27 ;
struct V_25 * V_26 ;
V_26 = & V_6 -> V_13 [ F_17 ( V_22 ) ] ;
F_22 (sess, head, hash)
if ( V_27 -> V_22 == V_22 )
return V_27 ;
V_27 = F_5 ( sizeof( * V_27 ) , V_11 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_32 = F_27 ( V_33 ,
sizeof( struct V_34 ) ,
V_35 ) ;
if ( F_28 ( V_27 -> V_32 ) ) {
F_29 ( V_27 ) ;
return NULL ;
}
V_27 -> V_32 -> V_36 = & V_31 -> V_36 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_22 = V_22 ;
F_30 ( & V_27 -> V_29 ) ;
F_31 ( & V_27 -> V_13 , V_26 ) ;
V_6 -> V_37 ++ ;
F_25 ( L_3 , V_22 , V_27 ) ;
F_32 ( & V_6 -> V_5 -> V_38 , & V_31 -> V_36 ,
V_27 -> V_32 , V_27 ) ;
return V_27 ;
}
static void F_33 ( struct V_24 * V_27 )
{
struct V_1 * V_6 = V_27 -> V_6 ;
F_34 ( & V_27 -> V_13 ) ;
F_10 ( ! V_6 -> V_37 ) ;
V_6 -> V_37 -- ;
V_27 -> V_22 = - 1 ;
V_27 -> V_39 = 0 ;
}
static struct V_24 * F_35 ( struct V_1 * V_6 , T_1 V_22 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
V_26 = & V_6 -> V_13 [ F_17 ( V_22 ) ] ;
F_22 (sess, head, hash) {
if ( V_27 -> V_22 == V_22 ) {
F_33 ( V_27 ) ;
return V_27 ;
}
}
return NULL ;
}
static void F_9 ( struct V_1 * V_6 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
for ( V_26 = V_6 -> V_13 ;
V_26 < & V_6 -> V_13 [ V_12 ] ; V_26 ++ ) {
F_22 (sess, head, hash) {
F_33 ( V_27 ) ;
F_36 ( V_27 -> V_32 ) ;
F_37 ( V_27 ) ;
}
}
}
int F_38 ( struct V_40 * V_32 )
{
struct V_24 * V_27 = V_32 -> V_41 ;
F_25 ( L_4 , V_27 -> V_22 ) ;
return 1 ;
}
void F_39 ( struct V_40 * V_32 )
{
struct V_24 * V_27 = V_32 -> V_41 ;
T_1 V_22 ;
F_13 ( & V_10 ) ;
V_22 = V_27 -> V_22 ;
if ( V_22 == - 1 ) {
F_14 ( & V_10 ) ;
return;
}
F_25 ( L_4 , V_22 ) ;
F_33 ( V_27 ) ;
F_14 ( & V_10 ) ;
F_36 ( V_32 ) ;
F_37 ( V_27 ) ;
F_40 () ;
}
T_1 F_41 ( struct V_40 * V_32 )
{
struct V_24 * V_27 = V_32 -> V_41 ;
return V_27 -> V_22 ;
}
T_1 F_42 ( struct V_40 * V_32 ,
unsigned char * V_42 , T_1 V_43 )
{
struct V_24 * V_27 = V_32 -> V_41 ;
return F_43 ( V_42 , V_43 , V_27 -> V_44 ) ;
}
static int F_44 ( struct V_45 * V_46 , T_1 V_47 ,
const struct V_48 * V_49 , struct V_48 * V_50 )
{
struct V_1 * V_6 ;
struct V_24 * V_27 ;
struct V_30 * V_31 ;
T_1 V_51 ;
V_6 = F_1 ( V_46 -> V_52 ) ;
if ( ! V_6 )
goto V_53;
V_31 = F_45 ( V_6 -> V_5 , V_46 ) ;
if ( ! V_31 )
goto V_53;
if ( ! V_49 )
goto V_54;
if ( V_49 -> V_55 & ( V_56 | V_57 ) )
return V_58 ;
V_51 = F_46 ( V_49 -> V_59 ) ;
if ( ! ( V_51 & ( V_60 | V_61 ) ) )
return V_62 ;
if ( V_49 -> V_55 & V_63 ) {
V_50 -> V_55 |= V_63 ;
if ( ! ( V_51 & V_60 ) )
return V_64 ;
V_27 = F_26 ( V_6 , V_46 -> V_65 . V_22 , V_31 ) ;
if ( ! V_27 )
return V_66 ;
if ( ! V_27 -> V_39 )
V_46 -> V_67 ++ ;
V_27 -> V_39 = V_51 ;
V_27 -> V_44 = V_46 -> V_65 . V_44 ;
V_27 -> V_68 = V_46 -> V_69 ;
}
V_54:
V_51 = F_46 ( V_50 -> V_59 ) ;
V_51 &= ~ V_70 ;
V_50 -> V_59 = F_47 ( V_51 | V_61 ) ;
return V_71 ;
V_53:
V_51 = F_46 ( V_50 -> V_59 ) ;
V_51 &= ~ V_61 ;
V_50 -> V_59 = F_47 ( V_51 ) ;
return 0 ;
}
static int F_48 ( struct V_45 * V_46 , T_1 V_47 ,
const struct V_48 * V_49 , struct V_48 * V_50 )
{
int V_72 ;
F_13 ( & V_10 ) ;
V_72 = F_44 ( V_46 , V_47 , V_49 , V_50 ) ;
F_14 ( & V_10 ) ;
F_25 ( L_5 ,
V_46 -> V_65 . V_22 , V_49 ? V_49 -> V_55 : 0 , V_72 ) ;
return V_72 ;
}
static void F_49 ( struct V_29 * V_29 )
{
struct V_24 * V_27 = F_50 ( V_29 , struct V_24 , V_29 ) ;
F_51 ( V_27 -> V_32 ) ;
F_11 ( V_27 , V_14 ) ;
}
void F_37 ( struct V_24 * V_27 )
{
int V_73 = F_52 ( & V_27 -> V_29 . V_74 ) ;
F_10 ( ! V_73 ) ;
F_53 ( & V_27 -> V_29 , F_49 ) ;
}
static void F_54 ( struct V_45 * V_46 )
{
struct V_24 * V_27 ;
struct V_1 * V_6 ;
F_13 ( & V_10 ) ;
V_6 = F_2 ( V_46 -> V_52 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( ! V_6 ) {
F_14 ( & V_10 ) ;
return;
}
V_27 = F_35 ( V_6 , V_46 -> V_65 . V_22 ) ;
if ( ! V_27 ) {
F_14 ( & V_10 ) ;
return;
}
F_14 ( & V_10 ) ;
F_36 ( V_27 -> V_32 ) ;
F_37 ( V_27 ) ;
V_46 -> V_67 -- ;
}
static void F_55 ( struct V_2 * V_3 , struct V_75 * V_76 )
{
struct V_24 * V_27 ;
T_1 V_77 = F_56 ( V_76 ) ;
F_25 ( L_6 , V_77 ) ;
V_27 = F_19 ( V_3 , V_77 ) ;
if ( ! V_27 ) {
F_25 ( L_7 , V_77 ) ;
F_57 ( V_76 ) ;
return;
}
F_58 ( V_27 , V_76 ) ;
}
