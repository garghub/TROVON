static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
bool V_6 = F_3 ( V_2 , V_3 ) ;
bool V_7 ;
int V_8 ;
V_8 = F_4 ( V_5 -> V_9 ,
V_10 + V_3 ,
V_11 , V_11 ,
& V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_7 && V_6 ) {
F_5 ( V_2 -> V_12 ) ;
F_6 ( V_2 -> V_12 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_13 , V_14 ;
int V_8 ;
V_13 = V_10 + V_3 ;
V_8 = F_8 ( V_5 -> V_9 , V_13 , & V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_14 & V_11 ) {
V_8 = F_9 ( V_2 -> V_12 ) ;
if ( V_8 < 0 ) {
F_10 ( V_2 -> V_12 , L_1 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_5 -> V_9 , V_13 , V_13 ) ;
if ( V_8 < 0 ) {
F_10 ( V_2 -> V_12 , L_2 ,
V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_5 -> V_9 , V_13 , & V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
F_5 ( V_2 -> V_12 ) ;
F_6 ( V_2 -> V_12 ) ;
}
if ( V_14 & V_15 )
return 1 ;
else
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_16 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
bool V_6 = F_3 ( V_2 , V_3 ) ;
unsigned int V_14 ;
int V_8 ;
V_8 = F_8 ( V_5 -> V_9 , V_10 + V_3 , & V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ( V_14 & V_11 ) && V_6 ) {
V_8 = F_9 ( V_2 -> V_12 ) ;
if ( V_8 < 0 ) {
F_10 ( V_2 -> V_12 , L_1 , V_8 ) ;
return V_8 ;
}
}
if ( V_16 )
V_16 = V_15 ;
return F_13 ( V_5 -> V_9 , V_10 + V_3 ,
V_11 | V_15 , V_16 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_16 )
V_16 = V_15 ;
F_13 ( V_5 -> V_9 , V_10 + V_3 ,
V_15 , V_16 ) ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_5 * V_5 = F_16 ( V_18 -> V_19 . V_12 ) ;
struct V_20 * V_21 = F_17 ( V_5 -> V_19 ) ;
struct V_4 * V_4 ;
int V_8 ;
V_4 = F_18 ( & V_18 -> V_19 , sizeof( * V_4 ) ,
V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_24 ;
V_4 -> V_1 . V_12 = & V_18 -> V_19 ;
#ifdef F_19
V_4 -> V_1 . V_25 = V_5 -> V_19 -> V_25 ;
#endif
switch ( V_5 -> type ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
V_4 -> V_1 . V_32 = 5 ;
break;
case V_33 :
case V_34 :
V_4 -> V_1 . V_32 = 2 ;
break;
default:
F_10 ( & V_18 -> V_19 , L_3 ,
V_5 -> type ) ;
return - V_35 ;
}
if ( V_21 && V_21 -> V_36 )
V_4 -> V_1 . V_37 = V_21 -> V_36 ;
else
V_4 -> V_1 . V_37 = - 1 ;
F_20 ( & V_18 -> V_19 ) ;
V_8 = F_21 ( & V_18 -> V_19 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_8 < 0 ) {
F_10 ( & V_18 -> V_19 , L_4 ,
V_8 ) ;
return V_8 ;
}
return 0 ;
}
