static T_1 int F_1 ( void )
{
struct V_1 V_2 ;
F_2 ( & V_2 ) ;
F_3 ( & V_2 ) ;
if ( ! V_2 . V_3 )
return 0 ;
V_4 = F_4 ( V_5 , 0 ) ;
F_5 ( ! V_4 ) ;
F_6 ( L_1 , V_5 ) ;
return 0 ;
}
static void F_7 ( struct V_6 * V_7 , unsigned char * V_8 )
{
unsigned long V_9 ;
unsigned char * V_10 ;
F_8 ( V_9 ) ;
V_10 = F_9 ( V_7 -> V_11 , V_12 ) ;
memcpy ( V_10 + V_7 -> V_13 , V_8 , V_7 -> V_14 ) ;
F_10 ( V_10 , V_12 ) ;
F_11 ( V_9 ) ;
}
static void * F_12 ( T_2 V_15 , void * V_16 )
{
return F_13 ( V_15 | V_17 , V_16 ) ;
}
int F_14 ( void )
{
if ( V_18 )
return 0 ;
V_18 = F_15 ( V_19 , F_12 ,
V_20 , ( void * ) 0 ) ;
F_5 ( ! V_18 ) ;
F_6 ( L_2 , V_19 ) ;
return 0 ;
}
static void F_16 ( struct V_21 * V_7 , struct V_21 * V_22 )
{
unsigned char * V_8 ;
struct V_6 * V_23 , * V_24 ;
int V_2 ;
F_17 (tovec, to, i, 0 ) {
V_24 = V_22 -> V_25 + V_2 ;
if ( V_23 -> V_11 == V_24 -> V_11 )
continue;
V_8 = F_18 ( V_24 -> V_11 ) + V_23 -> V_13 ;
F_7 ( V_23 , V_8 ) ;
F_19 ( V_23 -> V_11 ) ;
}
}
static void F_20 ( struct V_21 * V_21 , T_3 * V_26 , int V_27 )
{
struct V_21 * V_28 = V_21 -> V_29 ;
struct V_6 * V_30 , * V_31 ;
int V_2 ;
if ( F_21 ( V_32 , & V_21 -> V_33 ) )
F_22 ( V_32 , & V_28 -> V_33 ) ;
F_17 (bvec, bio, i, 0 ) {
V_31 = V_28 -> V_25 + V_2 ;
if ( V_30 -> V_11 == V_31 -> V_11 )
continue;
F_23 ( V_30 -> V_11 , V_34 ) ;
F_24 ( V_30 -> V_11 , V_26 ) ;
}
F_25 ( V_28 , V_27 ) ;
F_26 ( V_21 ) ;
}
static void F_27 ( struct V_21 * V_21 , int V_27 )
{
F_20 ( V_21 , V_4 , V_27 ) ;
}
static void F_28 ( struct V_21 * V_21 , int V_27 )
{
F_20 ( V_21 , V_18 , V_27 ) ;
}
static void F_29 ( struct V_21 * V_21 , T_3 * V_26 , int V_27 )
{
struct V_21 * V_28 = V_21 -> V_29 ;
if ( F_21 ( V_35 , & V_21 -> V_33 ) )
F_16 ( V_28 , V_21 ) ;
F_20 ( V_21 , V_26 , V_27 ) ;
}
static void F_30 ( struct V_21 * V_21 , int V_27 )
{
F_29 ( V_21 , V_4 , V_27 ) ;
}
static void F_31 ( struct V_21 * V_21 , int V_27 )
{
F_29 ( V_21 , V_18 , V_27 ) ;
}
static void F_32 ( struct V_36 * V_37 , struct V_21 * * V_28 ,
T_3 * V_26 )
{
struct V_38 * V_38 ;
struct V_21 * V_21 = NULL ;
int V_2 , V_39 = F_33 ( * V_28 ) ;
struct V_6 * V_7 , * V_22 ;
F_34 (from, *bio_orig, i) {
V_38 = V_22 -> V_11 ;
if ( F_35 ( V_38 ) <= F_36 ( V_37 ) )
continue;
if ( ! V_21 ) {
unsigned int V_40 = ( * V_28 ) -> V_41 ;
V_21 = F_37 ( V_42 , V_40 ) ;
memset ( V_21 -> V_25 , 0 , V_40 * sizeof( struct V_6 ) ) ;
}
V_7 = V_21 -> V_25 + V_2 ;
V_7 -> V_11 = F_38 ( V_26 , V_37 -> V_43 ) ;
V_7 -> V_14 = V_22 -> V_14 ;
V_7 -> V_13 = V_22 -> V_13 ;
F_39 ( V_7 -> V_11 , V_34 ) ;
if ( V_39 == V_44 ) {
char * V_10 , * V_8 ;
F_19 ( V_22 -> V_11 ) ;
V_10 = F_18 ( V_7 -> V_11 ) + V_7 -> V_13 ;
V_8 = F_40 ( V_22 -> V_11 ) + V_22 -> V_13 ;
memcpy ( V_10 , V_8 , V_7 -> V_14 ) ;
F_41 ( V_22 -> V_11 ) ;
}
}
if ( ! V_21 )
return;
F_42 ( V_37 , * V_28 ) ;
F_17 (from, *bio_orig, i, 0 ) {
V_7 = F_43 ( V_21 , V_2 ) ;
if ( ! V_7 -> V_11 ) {
V_7 -> V_11 = V_22 -> V_11 ;
V_7 -> V_14 = V_22 -> V_14 ;
V_7 -> V_13 = V_22 -> V_13 ;
}
}
V_21 -> V_45 = ( * V_28 ) -> V_45 ;
V_21 -> V_33 |= ( 1 << V_46 ) ;
V_21 -> V_47 = ( * V_28 ) -> V_47 ;
V_21 -> V_48 = ( * V_28 ) -> V_48 ;
V_21 -> V_41 = ( * V_28 ) -> V_41 ;
V_21 -> V_49 = ( * V_28 ) -> V_49 ;
V_21 -> V_50 = ( * V_28 ) -> V_50 ;
if ( V_26 == V_4 ) {
V_21 -> V_51 = F_27 ;
if ( V_39 == V_52 )
V_21 -> V_51 = F_30 ;
} else {
V_21 -> V_51 = F_28 ;
if ( V_39 == V_52 )
V_21 -> V_51 = F_31 ;
}
V_21 -> V_29 = * V_28 ;
* V_28 = V_21 ;
}
void F_44 ( struct V_36 * V_37 , struct V_21 * * V_28 )
{
T_3 * V_26 ;
if ( ! F_45 ( * V_28 ) )
return;
if ( ! ( V_37 -> V_43 & V_17 ) ) {
if ( F_36 ( V_37 ) >= V_53 )
return;
V_26 = V_4 ;
} else {
F_5 ( ! V_18 ) ;
V_26 = V_18 ;
}
F_32 ( V_37 , V_28 , V_26 ) ;
}
