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
if ( F_20 ( V_35 , & V_21 -> V_36 ) )
F_21 ( V_35 , & V_30 -> V_36 ) ;
F_22 (bvec, bio, i) {
V_33 = V_30 -> V_25 + V_34 ;
if ( V_32 -> V_12 == V_33 -> V_12 )
continue;
F_23 ( V_32 -> V_12 , V_37 ) ;
F_24 ( V_32 -> V_12 , V_28 ) ;
}
F_25 ( V_30 , V_29 ) ;
F_26 ( V_21 ) ;
}
static void F_27 ( struct V_21 * V_21 , int V_29 )
{
F_19 ( V_21 , V_5 , V_29 ) ;
}
static void F_28 ( struct V_21 * V_21 , int V_29 )
{
F_19 ( V_21 , V_18 , V_29 ) ;
}
static void F_29 ( struct V_21 * V_21 , T_3 * V_28 , int V_29 )
{
struct V_21 * V_30 = V_21 -> V_31 ;
if ( F_20 ( V_38 , & V_21 -> V_36 ) )
F_15 ( V_30 , V_21 ) ;
F_19 ( V_21 , V_28 , V_29 ) ;
}
static void F_30 ( struct V_21 * V_21 , int V_29 )
{
F_29 ( V_21 , V_5 , V_29 ) ;
}
static void F_31 ( struct V_21 * V_21 , int V_29 )
{
F_29 ( V_21 , V_18 , V_29 ) ;
}
static int F_32 ( struct V_39 * V_40 , struct V_21 * V_21 )
{
if ( F_33 ( V_21 ) != V_41 )
return 0 ;
if ( ! F_34 ( & V_40 -> V_42 ) )
return 0 ;
return F_20 ( V_43 , & V_21 -> V_36 ) ;
}
static int F_32 ( struct V_39 * V_40 , struct V_21 * V_21 )
{
return 0 ;
}
static void F_35 ( struct V_39 * V_40 , struct V_21 * * V_30 ,
T_3 * V_28 , int V_44 )
{
struct V_21 * V_21 ;
int V_45 = F_33 ( * V_30 ) ;
struct V_7 * V_8 , V_22 ;
struct V_26 V_27 ;
unsigned V_34 ;
if ( V_44 )
goto V_46;
F_16 (from, *bio_orig, iter)
if ( F_36 ( V_22 . V_12 ) > F_37 ( V_40 ) )
goto V_46;
return;
V_46:
V_21 = F_38 ( * V_30 , V_47 , V_48 ) ;
F_22 (to, bio, i) {
struct V_49 * V_49 = V_8 -> V_12 ;
if ( F_36 ( V_49 ) <= F_37 ( V_40 ) && ! V_44 )
continue;
V_8 -> V_12 = F_39 ( V_28 , V_40 -> V_50 ) ;
F_40 ( V_8 -> V_12 , V_37 ) ;
if ( V_45 == V_41 ) {
char * V_11 , * V_9 ;
F_18 ( V_49 ) ;
V_11 = F_17 ( V_8 -> V_12 ) + V_8 -> V_13 ;
V_9 = F_8 ( V_49 ) + V_8 -> V_13 ;
memcpy ( V_11 , V_9 , V_8 -> V_14 ) ;
F_9 ( V_9 ) ;
}
}
F_41 ( V_40 , * V_30 ) ;
V_21 -> V_36 |= ( 1 << V_51 ) ;
if ( V_28 == V_5 ) {
V_21 -> V_52 = F_27 ;
if ( V_45 == V_53 )
V_21 -> V_52 = F_30 ;
} else {
V_21 -> V_52 = F_28 ;
if ( V_45 == V_53 )
V_21 -> V_52 = F_31 ;
}
V_21 -> V_31 = * V_30 ;
* V_30 = V_21 ;
}
void F_42 ( struct V_39 * V_40 , struct V_21 * * V_30 )
{
int V_54 ;
T_3 * V_28 ;
if ( ! F_43 ( * V_30 ) )
return;
V_54 = F_32 ( V_40 , * V_30 ) ;
if ( ! ( V_40 -> V_50 & V_17 ) ) {
if ( F_37 ( V_40 ) >= V_55 && ! V_54 )
return;
V_28 = V_5 ;
} else {
F_4 ( ! V_18 ) ;
V_28 = V_18 ;
}
F_35 ( V_40 , V_30 , V_28 , V_54 ) ;
}
