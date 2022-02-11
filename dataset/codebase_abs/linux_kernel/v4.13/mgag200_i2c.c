static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_4 ) ;
return F_3 ( V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_6 , int V_7 )
{
int V_8 ;
F_2 ( V_3 , V_9 ) ;
V_8 = ( F_3 ( V_5 ) & V_6 ) | V_7 ;
F_5 ( V_9 , V_8 ) ;
F_5 ( V_4 , 0 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_6 , int V_10 )
{
if ( V_10 )
V_10 = 0 ;
else
V_10 = V_6 ;
F_4 ( V_2 , ~ V_6 , V_10 ) ;
}
static void F_7 ( void * V_11 , int V_10 )
{
struct V_12 * V_13 = V_11 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
F_6 ( V_2 , V_13 -> V_11 , V_10 ) ;
}
static void F_8 ( void * V_11 , int V_10 )
{
struct V_12 * V_13 = V_11 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
F_6 ( V_2 , V_13 -> clock , V_10 ) ;
}
static int F_9 ( void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
return ( F_1 ( V_2 ) & V_13 -> V_11 ) ? 1 : 0 ;
}
static int F_10 ( void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_1 * V_2 = V_13 -> V_14 -> V_15 ;
return ( F_1 ( V_2 ) & V_13 -> clock ) ? 1 : 0 ;
}
struct V_12 * F_11 ( struct V_16 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_12 * V_13 ;
int V_17 ;
int V_11 , clock ;
F_5 ( V_18 , 1 ) ;
F_5 ( V_4 , 0xff ) ;
F_5 ( V_9 , 0 ) ;
switch ( V_2 -> type ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_11 = 1 ;
clock = 2 ;
break;
case V_24 :
case V_25 :
case V_26 :
V_11 = 2 ;
clock = 1 ;
break;
default:
V_11 = 2 ;
clock = 8 ;
break;
}
V_13 = F_12 ( sizeof( struct V_12 ) , V_27 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_11 = V_11 ;
V_13 -> clock = clock ;
V_13 -> V_28 . V_29 = V_30 ;
V_13 -> V_28 . V_31 = V_32 ;
V_13 -> V_28 . V_14 . V_33 = & V_14 -> V_34 -> V_14 ;
V_13 -> V_14 = V_14 ;
F_13 ( & V_13 -> V_28 , V_13 ) ;
snprintf ( V_13 -> V_28 . V_35 , sizeof( V_13 -> V_28 . V_35 ) , L_1 ) ;
V_13 -> V_28 . V_36 = & V_13 -> V_37 ;
V_13 -> V_37 . V_38 = 10 ;
V_13 -> V_37 . V_39 = 2 ;
V_13 -> V_37 . V_11 = V_13 ;
V_13 -> V_37 . V_40 = F_7 ;
V_13 -> V_37 . V_41 = F_8 ;
V_13 -> V_37 . V_42 = F_9 ;
V_13 -> V_37 . V_43 = F_10 ;
V_17 = F_14 ( & V_13 -> V_28 ) ;
if ( V_17 ) {
F_15 ( V_13 ) ;
V_13 = NULL ;
}
return V_13 ;
}
void F_16 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_17 ( & V_13 -> V_28 ) ;
F_15 ( V_13 ) ;
}
