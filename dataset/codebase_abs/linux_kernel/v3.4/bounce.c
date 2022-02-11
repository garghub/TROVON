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
V_9 = F_8 ( V_6 -> V_10 ) ;
memcpy ( V_9 + V_6 -> V_11 , V_7 , V_6 -> V_12 ) ;
F_9 ( V_9 ) ;
F_10 ( V_8 ) ;
}
static void * F_11 ( T_2 V_13 , void * V_14 )
{
return F_12 ( V_13 | V_15 , V_14 ) ;
}
int F_13 ( void )
{
if ( V_16 )
return 0 ;
V_16 = F_14 ( V_17 , F_11 ,
V_18 , ( void * ) 0 ) ;
F_4 ( ! V_16 ) ;
F_5 ( L_2 , V_17 ) ;
return 0 ;
}
static void F_15 ( struct V_19 * V_6 , struct V_19 * V_20 )
{
unsigned char * V_7 ;
struct V_5 * V_21 , * V_22 ;
int V_23 ;
F_16 (tovec, to, i, 0 ) {
V_22 = V_20 -> V_24 + V_23 ;
if ( V_21 -> V_10 == V_22 -> V_10 )
continue;
V_7 = F_17 ( V_22 -> V_10 ) + V_21 -> V_11 ;
F_6 ( V_21 , V_7 ) ;
F_18 ( V_21 -> V_10 ) ;
}
}
static void F_19 ( struct V_19 * V_19 , T_3 * V_25 , int V_26 )
{
struct V_19 * V_27 = V_19 -> V_28 ;
struct V_5 * V_29 , * V_30 ;
int V_23 ;
if ( F_20 ( V_31 , & V_19 -> V_32 ) )
F_21 ( V_31 , & V_27 -> V_32 ) ;
F_16 (bvec, bio, i, 0 ) {
V_30 = V_27 -> V_24 + V_23 ;
if ( V_29 -> V_10 == V_30 -> V_10 )
continue;
F_22 ( V_29 -> V_10 , V_33 ) ;
F_23 ( V_29 -> V_10 , V_25 ) ;
}
F_24 ( V_27 , V_26 ) ;
F_25 ( V_19 ) ;
}
static void F_26 ( struct V_19 * V_19 , int V_26 )
{
F_19 ( V_19 , V_3 , V_26 ) ;
}
static void F_27 ( struct V_19 * V_19 , int V_26 )
{
F_19 ( V_19 , V_16 , V_26 ) ;
}
static void F_28 ( struct V_19 * V_19 , T_3 * V_25 , int V_26 )
{
struct V_19 * V_27 = V_19 -> V_28 ;
if ( F_20 ( V_34 , & V_19 -> V_32 ) )
F_15 ( V_27 , V_19 ) ;
F_19 ( V_19 , V_25 , V_26 ) ;
}
static void F_29 ( struct V_19 * V_19 , int V_26 )
{
F_28 ( V_19 , V_3 , V_26 ) ;
}
static void F_30 ( struct V_19 * V_19 , int V_26 )
{
F_28 ( V_19 , V_16 , V_26 ) ;
}
static void F_31 ( struct V_35 * V_36 , struct V_19 * * V_27 ,
T_3 * V_25 )
{
struct V_37 * V_37 ;
struct V_19 * V_19 = NULL ;
int V_23 , V_38 = F_32 ( * V_27 ) ;
struct V_5 * V_6 , * V_20 ;
F_33 (from, *bio_orig, i) {
V_37 = V_20 -> V_10 ;
if ( F_34 ( V_37 ) <= F_35 ( V_36 ) )
continue;
if ( ! V_19 ) {
unsigned int V_39 = ( * V_27 ) -> V_40 ;
V_19 = F_36 ( V_41 , V_39 ) ;
memset ( V_19 -> V_24 , 0 , V_39 * sizeof( struct V_5 ) ) ;
}
V_6 = V_19 -> V_24 + V_23 ;
V_6 -> V_10 = F_37 ( V_25 , V_36 -> V_42 ) ;
V_6 -> V_12 = V_20 -> V_12 ;
V_6 -> V_11 = V_20 -> V_11 ;
F_38 ( V_6 -> V_10 , V_33 ) ;
if ( V_38 == V_43 ) {
char * V_9 , * V_7 ;
F_18 ( V_20 -> V_10 ) ;
V_9 = F_17 ( V_6 -> V_10 ) + V_6 -> V_11 ;
V_7 = F_39 ( V_20 -> V_10 ) + V_20 -> V_11 ;
memcpy ( V_9 , V_7 , V_6 -> V_12 ) ;
F_40 ( V_20 -> V_10 ) ;
}
}
if ( ! V_19 )
return;
F_41 ( V_36 , * V_27 ) ;
F_16 (from, *bio_orig, i, 0 ) {
V_6 = F_42 ( V_19 , V_23 ) ;
if ( ! V_6 -> V_10 ) {
V_6 -> V_10 = V_20 -> V_10 ;
V_6 -> V_12 = V_20 -> V_12 ;
V_6 -> V_11 = V_20 -> V_11 ;
}
}
V_19 -> V_44 = ( * V_27 ) -> V_44 ;
V_19 -> V_32 |= ( 1 << V_45 ) ;
V_19 -> V_46 = ( * V_27 ) -> V_46 ;
V_19 -> V_47 = ( * V_27 ) -> V_47 ;
V_19 -> V_40 = ( * V_27 ) -> V_40 ;
V_19 -> V_48 = ( * V_27 ) -> V_48 ;
V_19 -> V_49 = ( * V_27 ) -> V_49 ;
if ( V_25 == V_3 ) {
V_19 -> V_50 = F_26 ;
if ( V_38 == V_51 )
V_19 -> V_50 = F_29 ;
} else {
V_19 -> V_50 = F_27 ;
if ( V_38 == V_51 )
V_19 -> V_50 = F_30 ;
}
V_19 -> V_28 = * V_27 ;
* V_27 = V_19 ;
}
void F_43 ( struct V_35 * V_36 , struct V_19 * * V_27 )
{
T_3 * V_25 ;
if ( ! F_44 ( * V_27 ) )
return;
if ( ! ( V_36 -> V_42 & V_15 ) ) {
if ( F_35 ( V_36 ) >= V_52 )
return;
V_25 = V_3 ;
} else {
F_4 ( ! V_16 ) ;
V_25 = V_16 ;
}
F_31 ( V_36 , V_27 , V_25 ) ;
}
