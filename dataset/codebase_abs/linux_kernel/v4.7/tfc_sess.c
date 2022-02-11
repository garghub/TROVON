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
static int F_27 ( struct V_30 * V_31 ,
struct V_32 * V_33 , void * V_34 )
{
struct V_24 * V_27 = V_34 ;
struct V_1 * V_6 = V_27 -> V_6 ;
struct V_25 * V_26 = & V_6 -> V_13 [ F_18 ( V_27 -> V_22 ) ] ;
F_26 ( L_3 , V_27 -> V_22 , V_27 ) ;
F_28 ( & V_27 -> V_13 , V_26 ) ;
V_6 -> V_35 ++ ;
return 0 ;
}
static struct V_24 * F_29 ( struct V_1 * V_6 , T_1 V_22 ,
struct V_36 * V_37 )
{
struct V_30 * V_31 = & V_6 -> V_5 -> V_31 ;
struct V_24 * V_27 ;
struct V_25 * V_26 ;
unsigned char V_38 [ V_39 ] ;
F_30 ( & V_38 [ 0 ] , V_39 , V_37 -> V_40 . V_41 ) ;
V_26 = & V_6 -> V_13 [ F_18 ( V_22 ) ] ;
F_23 (sess, head, hash)
if ( V_27 -> V_22 == V_22 )
return V_27 ;
V_27 = F_5 ( sizeof( * V_27 ) , V_11 ) ;
if ( ! V_27 )
return NULL ;
F_31 ( & V_27 -> V_29 ) ;
V_27 -> V_6 = V_6 ;
V_27 -> V_22 = V_22 ;
V_27 -> V_33 = F_32 ( V_31 , V_42 ,
sizeof( struct V_43 ) ,
V_44 , & V_38 [ 0 ] ,
V_27 , F_27 ) ;
if ( F_33 ( V_27 -> V_33 ) ) {
F_34 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static void F_35 ( struct V_24 * V_27 )
{
struct V_1 * V_6 = V_27 -> V_6 ;
F_36 ( & V_27 -> V_13 ) ;
F_10 ( ! V_6 -> V_35 ) ;
V_6 -> V_35 -- ;
V_27 -> V_22 = - 1 ;
V_27 -> V_45 = 0 ;
}
static struct V_24 * F_37 ( struct V_1 * V_6 , T_1 V_22 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
V_26 = & V_6 -> V_13 [ F_18 ( V_22 ) ] ;
F_23 (sess, head, hash) {
if ( V_27 -> V_22 == V_22 ) {
F_35 ( V_27 ) ;
return V_27 ;
}
}
return NULL ;
}
static void F_38 ( struct V_24 * V_27 )
{
F_39 ( V_27 -> V_33 ) ;
F_40 ( V_27 -> V_33 ) ;
F_41 ( V_27 -> V_33 ) ;
F_42 ( V_27 ) ;
}
static void F_9 ( struct V_1 * V_6 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
for ( V_26 = V_6 -> V_13 ;
V_26 < & V_6 -> V_13 [ V_12 ] ; V_26 ++ ) {
F_23 (sess, head, hash) {
F_35 ( V_27 ) ;
F_38 ( V_27 ) ;
}
}
}
void F_43 ( struct V_32 * V_33 )
{
struct V_24 * V_27 = V_33 -> V_46 ;
T_1 V_22 ;
F_14 ( & V_10 ) ;
V_22 = V_27 -> V_22 ;
if ( V_22 == - 1 ) {
F_15 ( & V_10 ) ;
return;
}
F_26 ( L_4 , V_22 ) ;
F_35 ( V_27 ) ;
F_15 ( & V_10 ) ;
F_38 ( V_27 ) ;
F_44 () ;
}
T_1 F_45 ( struct V_32 * V_33 )
{
struct V_24 * V_27 = V_33 -> V_46 ;
return V_27 -> V_22 ;
}
T_1 F_46 ( struct V_32 * V_33 ,
unsigned char * V_47 , T_1 V_48 )
{
struct V_24 * V_27 = V_33 -> V_46 ;
return F_30 ( V_47 , V_48 , V_27 -> V_41 ) ;
}
static int F_47 ( struct V_36 * V_37 , T_1 V_49 ,
const struct V_50 * V_51 , struct V_50 * V_52 )
{
struct V_1 * V_6 ;
struct V_24 * V_27 ;
T_1 V_53 ;
V_6 = F_1 ( V_37 -> V_54 ) ;
if ( ! V_6 )
goto V_55;
if ( ! V_51 )
goto V_56;
if ( V_51 -> V_57 & ( V_58 | V_59 ) )
return V_60 ;
V_53 = F_48 ( V_51 -> V_61 ) ;
if ( ! ( V_53 & ( V_62 | V_63 ) ) )
return V_64 ;
if ( V_51 -> V_57 & V_65 ) {
V_52 -> V_57 |= V_65 ;
if ( ! ( V_53 & V_62 ) )
return V_66 ;
V_27 = F_29 ( V_6 , V_37 -> V_40 . V_22 , V_37 ) ;
if ( ! V_27 )
return V_67 ;
if ( ! V_27 -> V_45 )
V_37 -> V_68 ++ ;
V_27 -> V_45 = V_53 ;
V_27 -> V_41 = V_37 -> V_40 . V_41 ;
V_27 -> V_69 = V_37 -> V_70 ;
}
V_56:
V_53 = F_48 ( V_52 -> V_61 ) ;
V_53 &= ~ V_71 ;
V_52 -> V_61 = F_49 ( V_53 | V_63 ) ;
return V_72 ;
V_55:
V_53 = F_48 ( V_52 -> V_61 ) ;
V_53 &= ~ V_63 ;
V_52 -> V_61 = F_49 ( V_53 ) ;
return 0 ;
}
static int F_50 ( struct V_36 * V_37 , T_1 V_49 ,
const struct V_50 * V_51 , struct V_50 * V_52 )
{
int V_73 ;
F_14 ( & V_10 ) ;
V_73 = F_47 ( V_37 , V_49 , V_51 , V_52 ) ;
F_15 ( & V_10 ) ;
F_26 ( L_5 ,
V_37 -> V_40 . V_22 , V_51 ? V_51 -> V_57 : 0 , V_73 ) ;
return V_73 ;
}
static void F_51 ( struct V_29 * V_29 )
{
struct V_24 * V_27 = F_52 ( V_29 , struct V_24 , V_29 ) ;
F_53 ( V_27 -> V_33 ) ;
F_12 ( V_27 , V_14 ) ;
}
void F_42 ( struct V_24 * V_27 )
{
int V_74 = F_54 ( & V_27 -> V_29 . V_75 ) ;
F_10 ( ! V_74 ) ;
F_55 ( & V_27 -> V_29 , F_51 ) ;
}
static void F_56 ( struct V_36 * V_37 )
{
struct V_24 * V_27 ;
struct V_1 * V_6 ;
F_14 ( & V_10 ) ;
V_6 = F_2 ( V_37 -> V_54 -> V_8 [ V_9 ] ,
F_3 ( & V_10 ) ) ;
if ( ! V_6 ) {
F_15 ( & V_10 ) ;
return;
}
V_27 = F_37 ( V_6 , V_37 -> V_40 . V_22 ) ;
if ( ! V_27 ) {
F_15 ( & V_10 ) ;
return;
}
F_15 ( & V_10 ) ;
F_38 ( V_27 ) ;
V_37 -> V_68 -- ;
}
static void F_57 ( struct V_2 * V_3 , struct V_76 * V_77 )
{
struct V_24 * V_27 ;
T_1 V_78 = F_58 ( V_77 ) ;
F_26 ( L_6 , V_78 ) ;
V_27 = F_20 ( V_3 , V_78 ) ;
if ( ! V_27 ) {
F_26 ( L_7 , V_78 ) ;
F_59 ( V_77 ) ;
return;
}
F_60 ( V_27 , V_77 ) ;
}
