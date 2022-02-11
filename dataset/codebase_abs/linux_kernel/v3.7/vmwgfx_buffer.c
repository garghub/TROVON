static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
V_6 -> V_7 = V_4 -> V_8 ;
return F_3 ( V_6 -> V_9 , V_2 -> V_10 ,
V_2 -> V_11 , V_6 -> V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
F_5 ( V_6 -> V_9 , V_6 -> V_7 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_6 ) ;
}
struct V_1 * F_9 ( struct V_12 * V_13 ,
unsigned long V_14 , T_1 V_15 ,
struct V_16 * V_17 )
{
struct V_5 * V_6 ;
V_6 = F_10 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_2 . V_19 = & V_20 ;
V_6 -> V_9 = F_2 ( V_13 , struct V_21 , V_13 ) ;
if ( F_11 ( & V_6 -> V_2 , V_13 , V_14 , V_15 , V_17 ) ) {
F_8 ( V_6 ) ;
return NULL ;
}
return & V_6 -> V_2 ;
}
int F_12 ( struct V_12 * V_13 , T_1 V_22 )
{
return 0 ;
}
int F_13 ( struct V_12 * V_13 , T_1 type ,
struct V_23 * V_24 )
{
switch ( type ) {
case V_25 :
V_24 -> V_22 = V_26 ;
V_24 -> V_27 = V_28 ;
V_24 -> V_29 = V_28 ;
break;
case V_30 :
V_24 -> V_19 = & V_31 ;
V_24 -> V_32 = 0 ;
V_24 -> V_22 = V_33 | V_26 ;
V_24 -> V_27 = V_28 ;
V_24 -> V_29 = V_28 ;
break;
case V_34 :
V_24 -> V_19 = & V_35 ;
V_24 -> V_32 = 0 ;
V_24 -> V_22 = V_36 | V_26 ;
V_24 -> V_27 = V_28 ;
V_24 -> V_29 = V_28 ;
break;
default:
F_14 ( L_1 , ( unsigned ) type ) ;
return - V_37 ;
}
return 0 ;
}
void F_15 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
* V_41 = V_42 ;
}
static int F_16 ( struct V_38 * V_39 , struct V_43 * V_44 )
{
return 0 ;
}
static int F_17 ( struct V_12 * V_13 , struct V_3 * V_45 )
{
struct V_23 * V_24 = & V_13 -> V_24 [ V_45 -> V_46 ] ;
struct V_21 * V_9 = F_2 ( V_13 , struct V_21 , V_13 ) ;
V_45 -> V_47 . V_48 = NULL ;
V_45 -> V_47 . V_49 = false ;
V_45 -> V_47 . V_50 = 0 ;
V_45 -> V_47 . V_14 = V_45 -> V_11 << V_51 ;
V_45 -> V_47 . V_52 = 0 ;
if ( ! ( V_24 -> V_22 & V_26 ) )
return - V_37 ;
switch ( V_45 -> V_46 ) {
case V_25 :
case V_34 :
return 0 ;
case V_30 :
V_45 -> V_47 . V_50 = V_45 -> V_8 << V_51 ;
V_45 -> V_47 . V_52 = V_9 -> V_53 ;
V_45 -> V_47 . V_49 = true ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static void F_18 ( struct V_12 * V_13 , struct V_3 * V_45 )
{
}
static int F_19 ( struct V_38 * V_39 )
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
unsigned long V_22 = ( unsigned long ) V_56 ;
return F_27 ( (struct V_55 * ) V_54 ,
( T_1 ) V_22 ) ;
}
static int F_28 ( void * V_54 , void * V_56 ,
bool V_57 , bool V_58 )
{
unsigned long V_22 = ( unsigned long ) V_56 ;
return F_29 ( (struct V_55 * ) V_54 ,
( T_1 ) V_22 ,
V_57 , V_58 ,
V_59 ) ;
}
