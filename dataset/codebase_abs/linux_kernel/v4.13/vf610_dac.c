static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = V_5 ;
V_3 = V_6 | V_7 |
V_8 ;
F_2 ( V_3 , V_2 -> V_9 + V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 -> V_9 + V_10 ) ;
V_3 &= ~ V_6 ;
F_2 ( V_3 , V_2 -> V_9 + V_10 ) ;
}
static int F_5 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
unsigned int V_15 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_3 ;
F_7 ( & V_12 -> V_16 ) ;
V_2 -> V_4 = V_15 ;
V_3 = F_4 ( V_2 -> V_9 + V_10 ) ;
if ( V_15 )
V_3 |= V_8 ;
else
V_3 &= ~ V_8 ;
F_2 ( V_3 , V_2 -> V_9 + V_10 ) ;
F_8 ( & V_12 -> V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
return V_2 -> V_4 ;
}
static int F_10 ( struct V_11 * V_12 ,
struct V_13 const * V_14 ,
int * V_3 , int * V_17 ,
long V_18 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
switch ( V_18 ) {
case V_19 :
* V_3 = F_11 ( F_4 ( V_2 -> V_9 ) ) ;
return V_20 ;
case V_21 :
* V_3 = 3300 ;
* V_17 = 12 ;
return V_22 ;
default:
return - V_23 ;
}
}
static int F_12 ( struct V_11 * V_12 ,
struct V_13 const * V_14 ,
int V_3 , int V_17 ,
long V_18 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
switch ( V_18 ) {
case V_19 :
F_7 ( & V_12 -> V_16 ) ;
F_2 ( F_11 ( V_3 ) , V_2 -> V_9 ) ;
F_8 ( & V_12 -> V_16 ) ;
return 0 ;
default:
return - V_23 ;
}
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
int V_28 ;
V_12 = F_14 ( & V_25 -> V_29 ,
sizeof( struct V_1 ) ) ;
if ( ! V_12 ) {
F_15 ( & V_25 -> V_29 , L_1 ) ;
return - V_30 ;
}
V_2 = F_6 ( V_12 ) ;
V_2 -> V_29 = & V_25 -> V_29 ;
V_27 = F_16 ( V_25 , V_31 , 0 ) ;
V_2 -> V_9 = F_17 ( & V_25 -> V_29 , V_27 ) ;
if ( F_18 ( V_2 -> V_9 ) )
return F_19 ( V_2 -> V_9 ) ;
V_2 -> V_32 = F_20 ( & V_25 -> V_29 , L_2 ) ;
if ( F_18 ( V_2 -> V_32 ) ) {
F_15 ( & V_25 -> V_29 , L_3 ,
F_19 ( V_2 -> V_32 ) ) ;
return F_19 ( V_2 -> V_32 ) ;
}
F_21 ( V_25 , V_12 ) ;
V_12 -> V_33 = F_22 ( & V_25 -> V_29 ) ;
V_12 -> V_29 . V_34 = & V_25 -> V_29 ;
V_12 -> V_29 . V_35 = V_25 -> V_29 . V_35 ;
V_12 -> V_2 = & V_36 ;
V_12 -> V_37 = V_38 ;
V_12 -> V_39 = V_40 ;
V_12 -> V_41 = F_23 ( V_40 ) ;
V_28 = F_24 ( V_2 -> V_32 ) ;
if ( V_28 ) {
F_15 ( & V_25 -> V_29 ,
L_4 ) ;
return V_28 ;
}
F_1 ( V_2 ) ;
V_28 = F_25 ( V_12 ) ;
if ( V_28 ) {
F_15 ( & V_25 -> V_29 , L_5 ) ;
goto V_42;
}
return 0 ;
V_42:
F_26 ( V_2 -> V_32 ) ;
return V_28 ;
}
static int F_27 ( struct V_24 * V_25 )
{
struct V_11 * V_12 = F_28 ( V_25 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_29 ( V_12 ) ;
F_3 ( V_2 ) ;
F_26 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_30 ( struct V_43 * V_29 )
{
struct V_11 * V_12 = F_31 ( V_29 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_3 ( V_2 ) ;
F_26 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_32 ( struct V_43 * V_29 )
{
struct V_11 * V_12 = F_31 ( V_29 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_28 ;
V_28 = F_24 ( V_2 -> V_32 ) ;
if ( V_28 )
return V_28 ;
F_1 ( V_2 ) ;
return 0 ;
}
