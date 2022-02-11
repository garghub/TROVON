static T_1 int F_1 ( void )
{
#if F_2 ( V_1 ) && ! F_2 ( V_2 )
if ( V_3 <= V_4 )
return 0 ;
#endif
V_5 = F_3 ( V_6 , 0 ) ;
F_4 ( ! V_5 ) ;
F_5 ( L_1 , V_6 ) ;
return 0 ;
}
static void F_6 ( struct V_7 * V_8 , unsigned char * V_9 )
{
unsigned long V_10 ;
unsigned char * V_11 ;
F_7 ( V_10 ) ;
V_11 = F_8 ( V_8 -> V_12 ) ;
memcpy ( V_11 + V_8 -> V_13 , V_9 , V_8 -> V_14 ) ;
F_9 ( V_11 ) ;
F_10 ( V_10 ) ;
}
static void * F_11 ( T_2 V_15 , void * V_16 )
{
return F_12 ( V_15 | V_17 , V_16 ) ;
}
int F_13 ( void )
{
if ( V_18 )
return 0 ;
V_18 = F_14 ( V_19 , F_11 ,
V_20 , ( void * ) 0 ) ;
F_4 ( ! V_18 ) ;
F_5 ( L_2 , V_19 ) ;
return 0 ;
}
static void F_15 ( struct V_21 * V_8 , struct V_21 * V_22 )
{
unsigned char * V_9 ;
struct V_7 * V_23 , * V_24 ;
int V_25 ;
F_16 (tovec, to, i, 0 ) {
V_24 = V_22 -> V_26 + V_25 ;
if ( V_23 -> V_12 == V_24 -> V_12 )
continue;
V_9 = F_17 ( V_24 -> V_12 ) + V_23 -> V_13 ;
F_6 ( V_23 , V_9 ) ;
F_18 ( V_23 -> V_12 ) ;
}
}
static void F_19 ( struct V_21 * V_21 , T_3 * V_27 , int V_28 )
{
struct V_21 * V_29 = V_21 -> V_30 ;
struct V_7 * V_31 , * V_32 ;
int V_25 ;
if ( F_20 ( V_33 , & V_21 -> V_34 ) )
F_21 ( V_33 , & V_29 -> V_34 ) ;
F_16 (bvec, bio, i, 0 ) {
V_32 = V_29 -> V_26 + V_25 ;
if ( V_31 -> V_12 == V_32 -> V_12 )
continue;
F_22 ( V_31 -> V_12 , V_35 ) ;
F_23 ( V_31 -> V_12 , V_27 ) ;
}
F_24 ( V_29 , V_28 ) ;
F_25 ( V_21 ) ;
}
static void F_26 ( struct V_21 * V_21 , int V_28 )
{
F_19 ( V_21 , V_5 , V_28 ) ;
}
static void F_27 ( struct V_21 * V_21 , int V_28 )
{
F_19 ( V_21 , V_18 , V_28 ) ;
}
static void F_28 ( struct V_21 * V_21 , T_3 * V_27 , int V_28 )
{
struct V_21 * V_29 = V_21 -> V_30 ;
if ( F_20 ( V_36 , & V_21 -> V_34 ) )
F_15 ( V_29 , V_21 ) ;
F_19 ( V_21 , V_27 , V_28 ) ;
}
static void F_29 ( struct V_21 * V_21 , int V_28 )
{
F_28 ( V_21 , V_5 , V_28 ) ;
}
static void F_30 ( struct V_21 * V_21 , int V_28 )
{
F_28 ( V_21 , V_18 , V_28 ) ;
}
static void F_31 ( struct V_37 * V_38 , struct V_21 * * V_29 ,
T_3 * V_27 )
{
struct V_39 * V_39 ;
struct V_21 * V_21 = NULL ;
int V_25 , V_40 = F_32 ( * V_29 ) ;
struct V_7 * V_8 , * V_22 ;
F_33 (from, *bio_orig, i) {
V_39 = V_22 -> V_12 ;
if ( F_34 ( V_39 ) <= F_35 ( V_38 ) )
continue;
if ( ! V_21 ) {
unsigned int V_41 = ( * V_29 ) -> V_42 ;
V_21 = F_36 ( V_43 , V_41 ) ;
memset ( V_21 -> V_26 , 0 , V_41 * sizeof( struct V_7 ) ) ;
}
V_8 = V_21 -> V_26 + V_25 ;
V_8 -> V_12 = F_37 ( V_27 , V_38 -> V_44 ) ;
V_8 -> V_14 = V_22 -> V_14 ;
V_8 -> V_13 = V_22 -> V_13 ;
F_38 ( V_8 -> V_12 , V_35 ) ;
if ( V_40 == V_45 ) {
char * V_11 , * V_9 ;
F_18 ( V_22 -> V_12 ) ;
V_11 = F_17 ( V_8 -> V_12 ) + V_8 -> V_13 ;
V_9 = F_39 ( V_22 -> V_12 ) + V_22 -> V_13 ;
memcpy ( V_11 , V_9 , V_8 -> V_14 ) ;
F_40 ( V_22 -> V_12 ) ;
}
}
if ( ! V_21 )
return;
F_41 ( V_38 , * V_29 ) ;
F_16 (from, *bio_orig, i, 0 ) {
V_8 = F_42 ( V_21 , V_25 ) ;
if ( ! V_8 -> V_12 ) {
V_8 -> V_12 = V_22 -> V_12 ;
V_8 -> V_14 = V_22 -> V_14 ;
V_8 -> V_13 = V_22 -> V_13 ;
}
}
V_21 -> V_46 = ( * V_29 ) -> V_46 ;
V_21 -> V_34 |= ( 1 << V_47 ) ;
V_21 -> V_48 = ( * V_29 ) -> V_48 ;
V_21 -> V_49 = ( * V_29 ) -> V_49 ;
V_21 -> V_42 = ( * V_29 ) -> V_42 ;
V_21 -> V_50 = ( * V_29 ) -> V_50 ;
V_21 -> V_51 = ( * V_29 ) -> V_51 ;
if ( V_27 == V_5 ) {
V_21 -> V_52 = F_26 ;
if ( V_40 == V_53 )
V_21 -> V_52 = F_29 ;
} else {
V_21 -> V_52 = F_27 ;
if ( V_40 == V_53 )
V_21 -> V_52 = F_30 ;
}
V_21 -> V_30 = * V_29 ;
* V_29 = V_21 ;
}
void F_43 ( struct V_37 * V_38 , struct V_21 * * V_29 )
{
T_3 * V_27 ;
if ( ! F_44 ( * V_29 ) )
return;
if ( ! ( V_38 -> V_44 & V_17 ) ) {
if ( F_35 ( V_38 ) >= V_54 )
return;
V_27 = V_5 ;
} else {
F_4 ( ! V_18 ) ;
V_27 = V_18 ;
}
F_31 ( V_38 , V_29 , V_27 ) ;
}
