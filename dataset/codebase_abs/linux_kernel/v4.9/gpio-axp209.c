static int F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
case 0 :
return V_2 ;
case 1 :
return V_3 ;
case 2 :
return V_4 ;
}
return - V_5 ;
}
static int F_2 ( struct V_6 * V_7 , unsigned V_1 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_4 ( V_9 -> V_11 , V_10 ,
V_12 ,
V_13 ) ;
}
static int F_5 ( struct V_6 * V_7 , unsigned V_1 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_14 ;
int V_10 , V_15 ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_15 = F_6 ( V_9 -> V_11 , V_10 , & V_14 ) ;
if ( V_15 )
return V_15 ;
return ! ! ( V_14 & F_7 ( V_1 + 4 ) ) ;
}
static int F_8 ( struct V_6 * V_7 , unsigned V_1 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_14 ;
int V_10 , V_15 ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_15 = F_6 ( V_9 -> V_11 , V_10 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( ( V_14 & V_12 ) > 2 )
return 0 ;
return V_14 & 2 ;
}
static int F_9 ( struct V_6 * V_7 , unsigned V_1 ,
int V_16 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_4 ( V_9 -> V_11 , V_10 ,
V_12 ,
V_16 ? V_17
: V_18 ) ;
}
static void F_10 ( struct V_6 * V_7 , unsigned V_1 ,
int V_16 )
{
F_9 ( V_7 , V_1 , V_16 ) ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_12 ( V_20 -> V_23 . V_24 ) ;
struct V_8 * V_9 ;
int V_15 ;
if ( ! F_13 ( V_20 -> V_23 . V_25 ) )
return - V_26 ;
if ( ! V_22 ) {
F_14 ( & V_20 -> V_23 , L_1 ) ;
return - V_5 ;
}
V_9 = F_15 ( & V_20 -> V_23 , sizeof( * V_9 ) , V_27 ) ;
if ( ! V_9 )
return - V_28 ;
V_9 -> V_7 . V_29 = - 1 ;
V_9 -> V_7 . V_30 = true ;
V_9 -> V_7 . V_24 = & V_20 -> V_23 ;
V_9 -> V_7 . V_31 = F_16 ( & V_20 -> V_23 ) ;
V_9 -> V_7 . V_32 = V_33 ;
V_9 -> V_7 . V_34 = F_5 ;
V_9 -> V_7 . V_35 = F_8 ;
V_9 -> V_7 . V_36 = F_10 ;
V_9 -> V_7 . V_37 = F_2 ;
V_9 -> V_7 . V_38 = F_9 ;
V_9 -> V_7 . V_39 = 3 ;
V_9 -> V_11 = V_22 -> V_11 ;
V_15 = F_17 ( & V_20 -> V_23 , & V_9 -> V_7 , V_9 ) ;
if ( V_15 ) {
F_14 ( & V_20 -> V_23 , L_2 ) ;
return V_15 ;
}
F_18 ( & V_20 -> V_23 , L_3 ) ;
return 0 ;
}
