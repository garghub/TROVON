static T_1 int F_1 ( void )
{
#if F_2 ( V_1 ) && ! F_2 ( V_2 )
if ( V_3 <= V_4 )
return 0 ;
#endif
V_5 = F_3 ( V_6 , 0 ) ;
F_4 ( ! V_5 ) ;
F_5 ( L_1 , V_6 ) ;
V_7 = F_6 ( V_8 , 0 , V_9 ) ;
F_4 ( ! V_7 ) ;
if ( F_7 ( V_7 , V_8 ) )
F_4 ( 1 ) ;
V_10 = F_6 ( V_8 , 0 , 0 ) ;
F_4 ( ! V_10 ) ;
return 0 ;
}
static void F_8 ( struct V_11 * V_12 , unsigned char * V_13 )
{
unsigned long V_14 ;
unsigned char * V_15 ;
F_9 ( V_14 ) ;
V_15 = F_10 ( V_12 -> V_16 ) ;
memcpy ( V_15 + V_12 -> V_17 , V_13 , V_12 -> V_18 ) ;
F_11 ( V_15 ) ;
F_12 ( V_14 ) ;
}
static void * F_13 ( T_2 V_19 , void * V_20 )
{
return F_14 ( V_19 | V_21 , V_20 ) ;
}
int F_15 ( void )
{
if ( V_22 )
return 0 ;
V_22 = F_16 ( V_23 , F_13 ,
V_24 , ( void * ) 0 ) ;
F_4 ( ! V_22 ) ;
F_5 ( L_2 , V_23 ) ;
return 0 ;
}
static void F_17 ( struct V_25 * V_12 , struct V_25 * V_26 )
{
unsigned char * V_13 ;
struct V_11 V_27 , * V_28 = V_26 -> V_29 ;
struct V_30 V_31 ;
F_18 (tovec, to, iter) {
if ( V_27 . V_16 != V_28 -> V_16 ) {
V_13 = F_19 ( V_28 -> V_16 ) +
V_27 . V_17 ;
F_8 ( & V_27 , V_13 ) ;
F_20 ( V_27 . V_16 ) ;
}
V_28 ++ ;
}
}
static void F_21 ( struct V_25 * V_25 , T_3 * V_32 )
{
struct V_25 * V_33 = V_25 -> V_34 ;
struct V_11 * V_35 , * V_36 ;
int V_37 ;
int V_38 = V_33 -> V_39 . V_40 ;
F_22 (bvec, bio, i) {
V_36 = V_33 -> V_29 + V_37 + V_38 ;
if ( V_35 -> V_16 == V_36 -> V_16 )
continue;
F_23 ( V_35 -> V_16 , V_41 ) ;
F_24 ( V_35 -> V_16 , V_32 ) ;
}
V_33 -> V_42 = V_25 -> V_42 ;
F_25 ( V_33 ) ;
F_26 ( V_25 ) ;
}
static void F_27 ( struct V_25 * V_25 )
{
F_21 ( V_25 , V_5 ) ;
}
static void F_28 ( struct V_25 * V_25 )
{
F_21 ( V_25 , V_22 ) ;
}
static void F_29 ( struct V_25 * V_25 , T_3 * V_32 )
{
struct V_25 * V_33 = V_25 -> V_34 ;
if ( ! V_25 -> V_42 )
F_17 ( V_33 , V_25 ) ;
F_21 ( V_25 , V_32 ) ;
}
static void F_30 ( struct V_25 * V_25 )
{
F_29 ( V_25 , V_5 ) ;
}
static void F_31 ( struct V_25 * V_25 )
{
F_29 ( V_25 , V_22 ) ;
}
static void F_32 ( struct V_43 * V_44 , struct V_25 * * V_33 ,
T_3 * V_32 )
{
struct V_25 * V_25 ;
int V_45 = F_33 ( * V_33 ) ;
struct V_11 * V_12 , V_26 ;
struct V_30 V_31 ;
unsigned V_37 = 0 ;
bool V_46 = false ;
int V_47 = 0 ;
F_18 (from, *bio_orig, iter) {
if ( V_37 ++ < V_48 )
V_47 += V_26 . V_18 >> 9 ;
if ( F_34 ( V_26 . V_16 ) > V_44 -> V_49 . V_50 )
V_46 = true ;
}
if ( ! V_46 )
return;
if ( V_47 < F_35 ( * V_33 ) ) {
V_25 = F_36 ( * V_33 , V_47 , V_51 , V_10 ) ;
F_37 ( V_25 , * V_33 ) ;
F_38 ( * V_33 ) ;
* V_33 = V_25 ;
}
V_25 = F_39 ( * V_33 , V_51 , V_7 ) ;
F_22 (to, bio, i) {
struct V_52 * V_52 = V_12 -> V_16 ;
if ( F_34 ( V_52 ) <= V_44 -> V_49 . V_50 )
continue;
V_12 -> V_16 = F_40 ( V_32 , V_44 -> V_53 ) ;
F_41 ( V_12 -> V_16 , V_41 ) ;
if ( V_45 == V_54 ) {
char * V_15 , * V_13 ;
F_20 ( V_52 ) ;
V_15 = F_19 ( V_12 -> V_16 ) + V_12 -> V_17 ;
V_13 = F_10 ( V_52 ) + V_12 -> V_17 ;
memcpy ( V_15 , V_13 , V_12 -> V_18 ) ;
F_11 ( V_13 ) ;
}
}
F_42 ( V_44 , * V_33 ) ;
V_25 -> V_55 |= ( 1 << V_56 ) ;
if ( V_32 == V_5 ) {
V_25 -> V_57 = F_27 ;
if ( V_45 == V_58 )
V_25 -> V_57 = F_30 ;
} else {
V_25 -> V_57 = F_28 ;
if ( V_45 == V_58 )
V_25 -> V_57 = F_31 ;
}
V_25 -> V_34 = * V_33 ;
* V_33 = V_25 ;
}
void F_43 ( struct V_43 * V_44 , struct V_25 * * V_33 )
{
T_3 * V_32 ;
if ( ! F_44 ( * V_33 ) )
return;
if ( ! ( V_44 -> V_53 & V_21 ) ) {
if ( V_44 -> V_49 . V_50 >= V_59 )
return;
V_32 = V_5 ;
} else {
F_4 ( ! V_22 ) ;
V_32 = V_22 ;
}
F_32 ( V_44 , V_33 , V_32 ) ;
}
