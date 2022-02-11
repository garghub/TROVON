static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , struct V_4 * * V_5 ,
struct V_4 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
V_9 -> V_5 = V_5 ;
V_9 -> V_3 = V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
V_9 -> V_12 = V_11 -> V_13 ;
return F_4 ( V_9 -> V_14 , V_9 -> V_5 ,
V_9 -> V_3 , V_9 -> V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_6 ( V_9 -> V_14 , V_9 -> V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
V_9 -> V_5 = NULL ;
V_9 -> V_3 = 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_2 ) ;
F_9 ( V_9 ) ;
}
struct V_1 * F_10 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_17 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_2 . V_18 = & V_19 ;
V_9 -> V_14 = F_2 ( V_16 , struct V_20 , V_16 ) ;
return & V_9 -> V_2 ;
}
int F_12 ( struct V_15 * V_16 , T_2 V_21 )
{
return 0 ;
}
int F_13 ( struct V_15 * V_16 , T_2 type ,
struct V_22 * V_23 )
{
switch ( type ) {
case V_24 :
V_23 -> V_21 = V_25 ;
V_23 -> V_26 = V_27 ;
V_23 -> V_28 = V_27 ;
break;
case V_29 :
V_23 -> V_18 = & V_30 ;
V_23 -> V_31 = 0 ;
V_23 -> V_21 = V_32 | V_25 ;
V_23 -> V_26 = V_27 ;
V_23 -> V_28 = V_27 ;
break;
case V_33 :
V_23 -> V_18 = & V_34 ;
V_23 -> V_31 = 0 ;
V_23 -> V_21 = V_35 | V_25 ;
V_23 -> V_26 = V_27 ;
V_23 -> V_28 = V_27 ;
break;
default:
F_14 ( L_1 , ( unsigned ) type ) ;
return - V_36 ;
}
return 0 ;
}
void F_15 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
* V_40 = V_41 ;
}
static int F_16 ( struct V_37 * V_38 , struct V_42 * V_43 )
{
return 0 ;
}
static int F_17 ( struct V_15 * V_16 , struct V_10 * V_44 )
{
struct V_22 * V_23 = & V_16 -> V_23 [ V_44 -> V_45 ] ;
struct V_20 * V_14 = F_2 ( V_16 , struct V_20 , V_16 ) ;
V_44 -> V_46 . V_47 = NULL ;
V_44 -> V_46 . V_48 = false ;
V_44 -> V_46 . V_49 = 0 ;
V_44 -> V_46 . V_50 = V_44 -> V_3 << V_51 ;
V_44 -> V_46 . V_52 = 0 ;
if ( ! ( V_23 -> V_21 & V_25 ) )
return - V_36 ;
switch ( V_44 -> V_45 ) {
case V_24 :
case V_33 :
return 0 ;
case V_29 :
V_44 -> V_46 . V_49 = V_44 -> V_13 << V_51 ;
V_44 -> V_46 . V_52 = V_14 -> V_53 ;
V_44 -> V_46 . V_48 = true ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static void F_18 ( struct V_15 * V_16 , struct V_10 * V_44 )
{
}
static int F_19 ( struct V_37 * V_38 )
{
return 0 ;
}
static void * F_20 ( void * V_54 )
{
return ( void * )
F_21 ( (struct V_55 * ) V_54 ) ;
}
static void F_22 ( void * * V_54 )
{
F_23 ( (struct V_55 * * ) V_54 ) ;
}
static int F_24 ( void * V_54 , void * V_56 )
{
F_25 ( (struct V_55 * ) V_54 ) ;
return 0 ;
}
static bool F_26 ( void * V_54 , void * V_56 )
{
unsigned long V_21 = ( unsigned long ) V_56 ;
return F_27 ( (struct V_55 * ) V_54 ,
( T_2 ) V_21 ) ;
}
static int F_28 ( void * V_54 , void * V_56 ,
bool V_57 , bool V_58 )
{
unsigned long V_21 = ( unsigned long ) V_56 ;
return F_29 ( (struct V_55 * ) V_54 ,
( T_2 ) V_21 ,
V_57 , V_58 ,
V_59 ) ;
}
