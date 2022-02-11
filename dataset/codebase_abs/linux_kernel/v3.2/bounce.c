static T_1 int F_1 ( void )
{
#ifndef F_2
if ( V_1 <= V_2 )
return 0 ;
#endif
V_3 = F_3 ( V_4 , 0 ) ;
F_4 ( ! V_3 ) ;
F_5 ( L_1 , V_4 ) ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 , unsigned char * V_7 )
{
unsigned long V_8 ;
unsigned char * V_9 ;
F_7 ( V_8 ) ;
V_9 = F_8 ( V_6 -> V_10 , V_11 ) ;
memcpy ( V_9 + V_6 -> V_12 , V_7 , V_6 -> V_13 ) ;
F_9 ( V_9 , V_11 ) ;
F_10 ( V_8 ) ;
}
static void * F_11 ( T_2 V_14 , void * V_15 )
{
return F_12 ( V_14 | V_16 , V_15 ) ;
}
int F_13 ( void )
{
if ( V_17 )
return 0 ;
V_17 = F_14 ( V_18 , F_11 ,
V_19 , ( void * ) 0 ) ;
F_4 ( ! V_17 ) ;
F_5 ( L_2 , V_18 ) ;
return 0 ;
}
static void F_15 ( struct V_20 * V_6 , struct V_20 * V_21 )
{
unsigned char * V_7 ;
struct V_5 * V_22 , * V_23 ;
int V_24 ;
F_16 (tovec, to, i, 0 ) {
V_23 = V_21 -> V_25 + V_24 ;
if ( V_22 -> V_10 == V_23 -> V_10 )
continue;
V_7 = F_17 ( V_23 -> V_10 ) + V_22 -> V_12 ;
F_6 ( V_22 , V_7 ) ;
F_18 ( V_22 -> V_10 ) ;
}
}
static void F_19 ( struct V_20 * V_20 , T_3 * V_26 , int V_27 )
{
struct V_20 * V_28 = V_20 -> V_29 ;
struct V_5 * V_30 , * V_31 ;
int V_24 ;
if ( F_20 ( V_32 , & V_20 -> V_33 ) )
F_21 ( V_32 , & V_28 -> V_33 ) ;
F_16 (bvec, bio, i, 0 ) {
V_31 = V_28 -> V_25 + V_24 ;
if ( V_30 -> V_10 == V_31 -> V_10 )
continue;
F_22 ( V_30 -> V_10 , V_34 ) ;
F_23 ( V_30 -> V_10 , V_26 ) ;
}
F_24 ( V_28 , V_27 ) ;
F_25 ( V_20 ) ;
}
static void F_26 ( struct V_20 * V_20 , int V_27 )
{
F_19 ( V_20 , V_3 , V_27 ) ;
}
static void F_27 ( struct V_20 * V_20 , int V_27 )
{
F_19 ( V_20 , V_17 , V_27 ) ;
}
static void F_28 ( struct V_20 * V_20 , T_3 * V_26 , int V_27 )
{
struct V_20 * V_28 = V_20 -> V_29 ;
if ( F_20 ( V_35 , & V_20 -> V_33 ) )
F_15 ( V_28 , V_20 ) ;
F_19 ( V_20 , V_26 , V_27 ) ;
}
static void F_29 ( struct V_20 * V_20 , int V_27 )
{
F_28 ( V_20 , V_3 , V_27 ) ;
}
static void F_30 ( struct V_20 * V_20 , int V_27 )
{
F_28 ( V_20 , V_17 , V_27 ) ;
}
static void F_31 ( struct V_36 * V_37 , struct V_20 * * V_28 ,
T_3 * V_26 )
{
struct V_38 * V_38 ;
struct V_20 * V_20 = NULL ;
int V_24 , V_39 = F_32 ( * V_28 ) ;
struct V_5 * V_6 , * V_21 ;
F_33 (from, *bio_orig, i) {
V_38 = V_21 -> V_10 ;
if ( F_34 ( V_38 ) <= F_35 ( V_37 ) )
continue;
if ( ! V_20 ) {
unsigned int V_40 = ( * V_28 ) -> V_41 ;
V_20 = F_36 ( V_42 , V_40 ) ;
memset ( V_20 -> V_25 , 0 , V_40 * sizeof( struct V_5 ) ) ;
}
V_6 = V_20 -> V_25 + V_24 ;
V_6 -> V_10 = F_37 ( V_26 , V_37 -> V_43 ) ;
V_6 -> V_13 = V_21 -> V_13 ;
V_6 -> V_12 = V_21 -> V_12 ;
F_38 ( V_6 -> V_10 , V_34 ) ;
if ( V_39 == V_44 ) {
char * V_9 , * V_7 ;
F_18 ( V_21 -> V_10 ) ;
V_9 = F_17 ( V_6 -> V_10 ) + V_6 -> V_12 ;
V_7 = F_39 ( V_21 -> V_10 ) + V_21 -> V_12 ;
memcpy ( V_9 , V_7 , V_6 -> V_13 ) ;
F_40 ( V_21 -> V_10 ) ;
}
}
if ( ! V_20 )
return;
F_41 ( V_37 , * V_28 ) ;
F_16 (from, *bio_orig, i, 0 ) {
V_6 = F_42 ( V_20 , V_24 ) ;
if ( ! V_6 -> V_10 ) {
V_6 -> V_10 = V_21 -> V_10 ;
V_6 -> V_13 = V_21 -> V_13 ;
V_6 -> V_12 = V_21 -> V_12 ;
}
}
V_20 -> V_45 = ( * V_28 ) -> V_45 ;
V_20 -> V_33 |= ( 1 << V_46 ) ;
V_20 -> V_47 = ( * V_28 ) -> V_47 ;
V_20 -> V_48 = ( * V_28 ) -> V_48 ;
V_20 -> V_41 = ( * V_28 ) -> V_41 ;
V_20 -> V_49 = ( * V_28 ) -> V_49 ;
V_20 -> V_50 = ( * V_28 ) -> V_50 ;
if ( V_26 == V_3 ) {
V_20 -> V_51 = F_26 ;
if ( V_39 == V_52 )
V_20 -> V_51 = F_29 ;
} else {
V_20 -> V_51 = F_27 ;
if ( V_39 == V_52 )
V_20 -> V_51 = F_30 ;
}
V_20 -> V_29 = * V_28 ;
* V_28 = V_20 ;
}
void F_43 ( struct V_36 * V_37 , struct V_20 * * V_28 )
{
T_3 * V_26 ;
if ( ! F_44 ( * V_28 ) )
return;
if ( ! ( V_37 -> V_43 & V_16 ) ) {
if ( F_35 ( V_37 ) >= V_53 )
return;
V_26 = V_3 ;
} else {
F_4 ( ! V_17 ) ;
V_26 = V_17 ;
}
F_31 ( V_37 , V_28 , V_26 ) ;
}
