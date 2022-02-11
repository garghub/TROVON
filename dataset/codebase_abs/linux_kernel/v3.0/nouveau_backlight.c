static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = ( F_3 ( V_4 , V_6 ) & V_7 )
>> 16 ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_8 . V_9 ;
int V_10 = F_3 ( V_4 , V_6 ) ;
F_5 ( V_4 , V_6 ,
( V_5 << 16 ) | ( V_10 & ~ V_7 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_8 . V_9 ;
F_5 ( V_4 , V_11 ,
V_5 | V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_4 ;
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_18 V_8 ;
struct V_1 * V_2 ;
if ( ! ( F_3 ( V_4 , V_6 ) & V_7 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_18 ) ) ;
V_8 . type = V_19 ;
V_8 . V_20 = 31 ;
V_2 = F_9 ( L_1 , & V_14 -> V_21 , V_4 ,
& V_22 , & V_8 ) ;
if ( F_10 ( V_2 ) )
return F_11 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_2 -> V_8 . V_9 = F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_4 ;
struct V_15 * V_16 = V_4 -> V_17 ;
struct V_18 V_8 ;
struct V_1 * V_2 ;
if ( ! F_3 ( V_4 , V_11 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_18 ) ) ;
V_8 . type = V_19 ;
V_8 . V_20 = 1025 ;
V_2 = F_9 ( L_1 , & V_14 -> V_21 , V_4 ,
& V_24 , & V_8 ) ;
if ( F_10 ( V_2 ) )
return F_11 ( V_2 ) ;
V_16 -> V_23 = V_2 ;
V_2 -> V_8 . V_9 = F_6 ( V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
int F_14 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_4 ;
struct V_15 * V_16 = V_4 -> V_17 ;
#ifdef F_15
if ( F_16 () ) {
F_17 ( V_4 , L_2
L_3 ) ;
return 0 ;
}
#endif
switch ( V_16 -> V_25 ) {
case V_26 :
return F_8 ( V_14 ) ;
case V_27 :
return F_13 ( V_14 ) ;
default:
break;
}
return 0 ;
}
void F_18 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_4 ;
struct V_15 * V_16 = V_4 -> V_17 ;
if ( V_16 -> V_23 ) {
F_19 ( V_16 -> V_23 ) ;
V_16 -> V_23 = NULL ;
}
}
