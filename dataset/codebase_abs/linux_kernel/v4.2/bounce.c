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
struct V_7 V_23 , * V_24 = V_22 -> V_25 ;
struct V_26 V_27 ;
F_16 (tovec, to, iter) {
if ( V_23 . V_12 != V_24 -> V_12 ) {
V_9 = F_17 ( V_24 -> V_12 ) +
V_23 . V_13 ;
F_6 ( & V_23 , V_9 ) ;
F_18 ( V_23 . V_12 ) ;
}
V_24 ++ ;
}
}
static void F_19 ( struct V_21 * V_21 , T_3 * V_28 , int V_29 )
{
struct V_21 * V_30 = V_21 -> V_31 ;
struct V_7 * V_32 , * V_33 ;
int V_34 ;
F_20 (bvec, bio, i) {
V_33 = V_30 -> V_25 + V_34 ;
if ( V_32 -> V_12 == V_33 -> V_12 )
continue;
F_21 ( V_32 -> V_12 , V_35 ) ;
F_22 ( V_32 -> V_12 , V_28 ) ;
}
F_23 ( V_30 , V_29 ) ;
F_24 ( V_21 ) ;
}
static void F_25 ( struct V_21 * V_21 , int V_29 )
{
F_19 ( V_21 , V_5 , V_29 ) ;
}
static void F_26 ( struct V_21 * V_21 , int V_29 )
{
F_19 ( V_21 , V_18 , V_29 ) ;
}
static void F_27 ( struct V_21 * V_21 , T_3 * V_28 , int V_29 )
{
struct V_21 * V_30 = V_21 -> V_31 ;
if ( F_28 ( V_36 , & V_21 -> V_37 ) )
F_15 ( V_30 , V_21 ) ;
F_19 ( V_21 , V_28 , V_29 ) ;
}
static void F_29 ( struct V_21 * V_21 , int V_29 )
{
F_27 ( V_21 , V_5 , V_29 ) ;
}
static void F_30 ( struct V_21 * V_21 , int V_29 )
{
F_27 ( V_21 , V_18 , V_29 ) ;
}
static int F_31 ( struct V_38 * V_39 , struct V_21 * V_21 )
{
if ( F_32 ( V_21 ) != V_40 )
return 0 ;
if ( ! F_33 ( & V_39 -> V_41 ) )
return 0 ;
return F_28 ( V_42 , & V_21 -> V_37 ) ;
}
static int F_31 ( struct V_38 * V_39 , struct V_21 * V_21 )
{
return 0 ;
}
static void F_34 ( struct V_38 * V_39 , struct V_21 * * V_30 ,
T_3 * V_28 , int V_43 )
{
struct V_21 * V_21 ;
int V_44 = F_32 ( * V_30 ) ;
struct V_7 * V_8 , V_22 ;
struct V_26 V_27 ;
unsigned V_34 ;
if ( V_43 )
goto V_45;
F_16 (from, *bio_orig, iter)
if ( F_35 ( V_22 . V_12 ) > F_36 ( V_39 ) )
goto V_45;
return;
V_45:
V_21 = F_37 ( * V_30 , V_46 , V_47 ) ;
F_20 (to, bio, i) {
struct V_48 * V_48 = V_8 -> V_12 ;
if ( F_35 ( V_48 ) <= F_36 ( V_39 ) && ! V_43 )
continue;
V_8 -> V_12 = F_38 ( V_28 , V_39 -> V_49 ) ;
F_39 ( V_8 -> V_12 , V_35 ) ;
if ( V_44 == V_40 ) {
char * V_11 , * V_9 ;
F_18 ( V_48 ) ;
V_11 = F_17 ( V_8 -> V_12 ) + V_8 -> V_13 ;
V_9 = F_8 ( V_48 ) + V_8 -> V_13 ;
memcpy ( V_11 , V_9 , V_8 -> V_14 ) ;
F_9 ( V_9 ) ;
}
}
F_40 ( V_39 , * V_30 ) ;
V_21 -> V_37 |= ( 1 << V_50 ) ;
if ( V_28 == V_5 ) {
V_21 -> V_51 = F_25 ;
if ( V_44 == V_52 )
V_21 -> V_51 = F_29 ;
} else {
V_21 -> V_51 = F_26 ;
if ( V_44 == V_52 )
V_21 -> V_51 = F_30 ;
}
V_21 -> V_31 = * V_30 ;
* V_30 = V_21 ;
}
void F_41 ( struct V_38 * V_39 , struct V_21 * * V_30 )
{
int V_53 ;
T_3 * V_28 ;
if ( ! F_42 ( * V_30 ) )
return;
V_53 = F_31 ( V_39 , * V_30 ) ;
if ( ! ( V_39 -> V_49 & V_17 ) ) {
if ( F_36 ( V_39 ) >= V_54 && ! V_53 )
return;
V_28 = V_5 ;
} else {
F_4 ( ! V_18 ) ;
V_28 = V_18 ;
}
F_34 ( V_39 , V_30 , V_28 , V_53 ) ;
}
