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
const unsigned char * V_24 , T_1 V_25 )
{
struct V_26 * V_27 ;
struct V_4 * V_14 ;
struct V_1 * V_28 ;
int V_29 ;
int V_30 = 0 ;
int V_31 = sizeof( struct V_4 ) ;
F_6 ( V_21 ) ;
if ( ( V_20 -> V_7 & V_32 ) &&
( V_23 == V_33 ) ) {
const struct V_34 * V_34 = V_22 ;
if ( F_7 ( V_34 -> V_35 ) )
return 0 ;
}
if ( V_24 ) {
V_30 = strlen ( V_24 ) ;
V_31 += V_30 + 1 ;
}
F_8 ( L_1 , V_36 , V_18 , V_9 ,
V_7 ) ;
V_27 = F_9 ( V_20 , struct V_26 ,
V_37 ) ;
V_14 = F_10 ( V_31 , V_38 ) ;
if ( F_11 ( ! V_14 ) )
return - V_39 ;
V_28 = & V_14 -> V_40 ;
F_12 ( V_28 , V_9 , V_7 ) ;
V_14 -> V_41 = V_27 -> V_41 ;
V_14 -> V_42 = V_25 ;
V_14 -> V_10 = V_30 ;
if ( V_30 )
strcpy ( V_14 -> V_11 , V_24 ) ;
V_29 = F_13 ( V_18 , V_28 , F_3 ) ;
if ( V_29 ) {
F_14 ( V_18 , V_28 ) ;
}
if ( V_20 -> V_7 & V_43 )
F_15 ( V_20 , V_18 ) ;
return 0 ;
}
static void F_16 ( struct V_19 * V_37 , struct V_17 * V_18 )
{
F_17 ( V_37 , V_18 ) ;
}
static int F_18 ( int V_44 , void * V_45 , void * V_22 )
{
struct V_19 * V_37 ;
struct V_26 * V_27 ;
static bool V_46 = false ;
if ( V_46 )
return 0 ;
V_46 = true ;
V_37 = V_45 ;
V_27 = F_9 ( V_37 , struct V_26 , V_37 ) ;
F_19 ( 1 , L_2
L_3 , V_44 , V_45 , V_22 ) ;
if ( V_37 )
F_20 ( V_47 L_4 ,
V_37 -> V_18 , V_37 -> V_9 , V_27 -> V_41 ) ;
return 0 ;
}
static void F_21 ( struct V_17 * V_18 )
{
F_22 ( & V_18 -> V_48 . V_49 , F_18 , V_18 ) ;
F_23 ( & V_18 -> V_48 . V_49 ) ;
if ( V_18 -> V_48 . V_50 ) {
F_24 ( & V_18 -> V_48 . V_50 -> V_51 ) ;
F_25 ( V_18 -> V_48 . V_50 ) ;
}
}
static void F_26 ( struct V_1 * V_28 )
{
F_27 ( F_2 ( V_28 ) ) ;
}
