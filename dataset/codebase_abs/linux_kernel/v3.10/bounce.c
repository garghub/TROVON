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
F_16 (tovec, to, i) {
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
F_22 (bvec, bio, i) {
V_32 = V_29 -> V_26 + V_25 ;
if ( V_31 -> V_12 == V_32 -> V_12 )
continue;
F_23 ( V_31 -> V_12 , V_35 ) ;
F_24 ( V_31 -> V_12 , V_27 ) ;
}
F_25 ( V_29 , V_28 ) ;
F_26 ( V_21 ) ;
}
static void F_27 ( struct V_21 * V_21 , int V_28 )
{
F_19 ( V_21 , V_5 , V_28 ) ;
}
static void F_28 ( struct V_21 * V_21 , int V_28 )
{
F_19 ( V_21 , V_18 , V_28 ) ;
}
static void F_29 ( struct V_21 * V_21 , T_3 * V_27 , int V_28 )
{
struct V_21 * V_29 = V_21 -> V_30 ;
if ( F_20 ( V_36 , & V_21 -> V_34 ) )
F_15 ( V_29 , V_21 ) ;
F_19 ( V_21 , V_27 , V_28 ) ;
}
static void F_30 ( struct V_21 * V_21 , int V_28 )
{
F_29 ( V_21 , V_5 , V_28 ) ;
}
static void F_31 ( struct V_21 * V_21 , int V_28 )
{
F_29 ( V_21 , V_18 , V_28 ) ;
}
static int F_32 ( struct V_37 * V_38 , struct V_21 * V_21 )
{
if ( F_33 ( V_21 ) != V_39 )
return 0 ;
if ( ! F_34 ( & V_38 -> V_40 ) )
return 0 ;
return F_20 ( V_41 , & V_21 -> V_34 ) ;
}
static int F_32 ( struct V_37 * V_38 , struct V_21 * V_21 )
{
return 0 ;
}
static void F_35 ( struct V_37 * V_38 , struct V_21 * * V_29 ,
T_3 * V_27 , int V_42 )
{
struct V_21 * V_21 ;
int V_43 = F_33 ( * V_29 ) ;
struct V_7 * V_8 , * V_22 ;
unsigned V_25 ;
F_16 (from, *bio_orig, i)
if ( F_36 ( V_22 -> V_12 ) > F_37 ( V_38 ) )
goto V_44;
return;
V_44:
V_21 = F_38 ( * V_29 , V_45 , V_46 ) ;
F_22 (to, bio, i) {
struct V_47 * V_47 = V_8 -> V_12 ;
if ( F_36 ( V_47 ) <= F_37 ( V_38 ) && ! V_42 )
continue;
F_39 ( V_8 -> V_12 , V_35 ) ;
V_8 -> V_12 = F_40 ( V_27 , V_38 -> V_48 ) ;
if ( V_43 == V_39 ) {
char * V_11 , * V_9 ;
F_18 ( V_47 ) ;
V_11 = F_17 ( V_8 -> V_12 ) + V_8 -> V_13 ;
V_9 = F_8 ( V_47 ) + V_8 -> V_13 ;
memcpy ( V_11 , V_9 , V_8 -> V_14 ) ;
F_9 ( V_9 ) ;
}
}
F_41 ( V_38 , * V_29 ) ;
V_21 -> V_34 |= ( 1 << V_49 ) ;
if ( V_27 == V_5 ) {
V_21 -> V_50 = F_27 ;
if ( V_43 == V_51 )
V_21 -> V_50 = F_30 ;
} else {
V_21 -> V_50 = F_28 ;
if ( V_43 == V_51 )
V_21 -> V_50 = F_31 ;
}
V_21 -> V_30 = * V_29 ;
* V_29 = V_21 ;
}
void F_42 ( struct V_37 * V_38 , struct V_21 * * V_29 )
{
int V_52 ;
T_3 * V_27 ;
if ( ! F_43 ( * V_29 ) )
return;
V_52 = F_32 ( V_38 , * V_29 ) ;
if ( ! ( V_38 -> V_48 & V_17 ) ) {
if ( F_37 ( V_38 ) >= V_53 && ! V_52 )
return;
V_27 = V_5 ;
} else {
F_4 ( ! V_18 ) ;
V_27 = V_18 ;
}
F_35 ( V_38 , V_29 , V_27 , V_52 ) ;
}
