static bool F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
if ( V_2 -> V_7 & V_8 )
return false ;
V_5 = F_2 ( V_2 ) ;
V_6 = F_2 ( V_3 ) ;
if ( ( V_2 -> V_7 == V_3 -> V_7 ) &&
( V_2 -> V_9 == V_3 -> V_9 ) &&
( V_5 -> V_10 == V_6 -> V_10 ) &&
( ! V_5 -> V_10 || ! strcmp ( V_5 -> V_11 , V_6 -> V_11 ) ) )
return true ;
return false ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_1 * V_14 )
{
struct V_1 * V_15 ;
V_15 = F_4 ( V_13 -> V_16 , struct V_1 , V_13 ) ;
return F_1 ( V_15 , V_14 ) ;
}
int F_5 ( struct V_17 * V_18 ,
struct V_9 * V_9 ,
struct V_19 * V_20 ,
struct V_19 * V_21 ,
T_1 V_7 , const void * V_22 , int V_23 ,
const unsigned char * V_24 , T_1 V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_4 * V_14 ;
struct V_1 * V_30 ;
int V_31 ;
int V_32 = 0 ;
int V_33 = sizeof( struct V_4 ) ;
F_6 ( V_21 ) ;
if ( ( V_20 -> V_7 & V_34 ) &&
( V_23 == V_35 ) ) {
const struct V_36 * V_36 = V_22 ;
if ( F_7 ( V_36 -> V_37 ) )
return 0 ;
}
if ( V_24 ) {
V_32 = strlen ( V_24 ) ;
V_33 += V_32 + 1 ;
}
F_8 ( L_1 , V_38 , V_18 , V_9 ,
V_7 ) ;
V_29 = F_9 ( V_20 , struct V_28 ,
V_39 ) ;
V_14 = F_10 ( V_33 , V_40 ) ;
if ( F_11 ( ! V_14 ) )
return - V_41 ;
V_30 = & V_14 -> V_42 ;
F_12 ( V_30 , V_9 , V_7 ) ;
V_14 -> V_43 = V_29 -> V_43 ;
V_14 -> V_44 = V_25 ;
V_14 -> V_10 = V_32 ;
if ( V_32 )
strcpy ( V_14 -> V_11 , V_24 ) ;
V_31 = F_13 ( V_18 , V_30 , F_3 ) ;
if ( V_31 ) {
F_14 ( V_18 , V_30 ) ;
}
if ( V_20 -> V_7 & V_45 )
F_15 ( V_20 , V_18 ) ;
return 0 ;
}
static void F_16 ( struct V_19 * V_39 , struct V_17 * V_18 )
{
F_17 ( V_39 , V_18 ) ;
}
static int F_18 ( int V_46 , void * V_47 , void * V_22 )
{
struct V_19 * V_39 ;
struct V_28 * V_29 ;
static bool V_48 = false ;
if ( V_48 )
return 0 ;
V_48 = true ;
V_39 = V_47 ;
V_29 = F_9 ( V_39 , struct V_28 , V_39 ) ;
F_19 ( 1 , L_2
L_3 , V_46 , V_47 , V_22 ) ;
if ( V_39 )
F_20 ( V_49 L_4 ,
V_39 -> V_18 , V_29 -> V_43 ) ;
return 0 ;
}
static void F_21 ( struct V_17 * V_18 )
{
F_22 ( & V_18 -> V_50 . V_51 , F_18 , V_18 ) ;
F_23 ( & V_18 -> V_50 . V_51 ) ;
if ( V_18 -> V_50 . V_52 )
F_24 ( V_18 -> V_50 . V_52 ) ;
}
static void F_25 ( struct V_1 * V_30 )
{
F_26 ( F_2 ( V_30 ) ) ;
}
static void F_27 ( struct V_19 * V_39 )
{
struct V_28 * V_29 ;
V_29 = F_9 ( V_39 , struct V_28 , V_39 ) ;
F_28 ( V_53 , V_29 ) ;
}
