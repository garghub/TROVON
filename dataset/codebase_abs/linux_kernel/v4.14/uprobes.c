void F_1 ( struct V_1 * V_1 , unsigned long V_2 ,
void * V_3 , unsigned long V_4 )
{
void * V_5 = F_2 ( V_1 ) ;
void * V_6 = V_5 + ( V_2 & ~ V_7 ) ;
memcpy ( V_6 , V_3 , V_4 ) ;
F_3 ( V_6 , V_4 ) ;
F_4 ( V_5 ) ;
}
unsigned long F_5 ( struct V_8 * V_9 )
{
return F_6 ( V_9 ) ;
}
int F_7 ( struct V_10 * V_11 , struct V_12 * V_13 ,
unsigned long V_14 )
{
T_1 V_15 ;
if ( V_13 -> V_16 . V_17 & V_18 )
return - V_19 ;
else if ( ! F_8 ( V_14 , V_20 ) )
return - V_21 ;
V_15 = * ( T_1 * ) ( & V_11 -> V_15 [ 0 ] ) ;
switch ( F_9 ( V_15 , & V_11 -> V_22 ) ) {
case V_23 :
return - V_21 ;
case V_24 :
V_11 -> V_25 = true ;
break;
default:
break;
}
return 0 ;
}
int F_10 ( struct V_10 * V_11 , struct V_8 * V_9 )
{
struct V_26 * V_27 = V_28 -> V_27 ;
V_28 -> V_29 . V_30 = V_31 ;
F_11 ( V_9 , V_27 -> V_32 ) ;
F_12 ( V_28 ) ;
return 0 ;
}
int F_13 ( struct V_10 * V_11 , struct V_8 * V_9 )
{
struct V_26 * V_27 = V_28 -> V_27 ;
F_14 ( V_28 -> V_29 . V_30 != V_31 ) ;
F_11 ( V_9 , V_27 -> V_2 + 4 ) ;
F_15 ( V_28 ) ;
return 0 ;
}
bool F_16 ( struct V_33 * V_34 )
{
if ( V_34 -> V_29 . V_30 != V_31 )
return true ;
return false ;
}
bool F_17 ( struct V_10 * V_11 , struct V_8 * V_9 )
{
T_1 V_15 ;
unsigned long V_14 ;
if ( ! V_11 -> V_25 )
return false ;
V_15 = * ( T_1 * ) ( & V_11 -> V_15 [ 0 ] ) ;
V_14 = F_6 ( V_9 ) ;
if ( V_11 -> V_22 . V_35 )
V_11 -> V_22 . V_35 ( V_15 , V_14 , V_9 ) ;
return true ;
}
void F_18 ( struct V_10 * V_11 , struct V_8 * V_9 )
{
struct V_26 * V_27 = V_28 -> V_27 ;
F_11 ( V_9 , V_27 -> V_2 ) ;
F_15 ( V_28 ) ;
}
bool F_19 ( struct V_36 * V_37 , enum V_38 V_39 ,
struct V_8 * V_9 )
{
if ( V_39 == V_40 )
return V_9 -> V_41 <= V_37 -> V_42 ;
else
return V_9 -> V_41 < V_37 -> V_42 ;
}
unsigned long
F_20 ( unsigned long V_43 ,
struct V_8 * V_9 )
{
unsigned long V_44 ;
V_44 = F_21 ( V_9 ) ;
F_22 ( V_9 , V_43 ) ;
return V_44 ;
}
int F_23 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
return V_49 ;
}
static int F_24 ( struct V_8 * V_9 ,
unsigned int V_50 )
{
if ( F_25 ( V_9 ) && F_26 ( V_9 ) )
return V_51 ;
return V_52 ;
}
static int F_27 ( struct V_8 * V_9 ,
unsigned int V_50 )
{
struct V_26 * V_27 = V_28 -> V_27 ;
if ( F_25 ( V_9 ) ) {
F_28 ( V_27 &&
( F_6 ( V_9 ) != V_27 -> V_32 + 4 ) ) ;
if ( F_29 ( V_9 ) )
return V_51 ;
}
return V_52 ;
}
static int T_2 F_30 ( void )
{
F_31 ( & V_53 ) ;
F_32 ( & V_54 ) ;
return 0 ;
}
