static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_3 ;
if ( ! V_5 || V_5 -> V_8 != V_7 -> V_8 )
return 0 ;
if ( V_5 -> V_9 & V_10 )
return 0 ;
F_3 ( V_2 ) ;
if ( V_5 -> V_11 ) {
if ( V_5 -> V_11 -> V_12 )
V_5 -> V_11 -> V_12 ( V_5 , V_7 -> V_13 ) ;
else
F_4 ( & V_5 -> V_2 , L_1 ) ;
} else
F_5 ( & V_5 -> V_2 , L_2 ) ;
F_6 ( V_2 ) ;
return - V_14 ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_12 ;
struct V_4 * V_18 ;
unsigned short V_19 = 0 ;
V_12 = F_8 ( V_16 , struct V_17 , V_12 ) ;
V_18 = V_12 -> V_18 ;
for (; ; ) {
T_1 V_20 ;
struct V_6 V_7 ;
V_20 = F_9 ( V_18 ) ;
if ( V_20 < 0 )
break;
V_7 . V_13 = V_20 & 1 ;
V_7 . V_8 = V_20 >> 1 ;
if ( V_7 . V_8 == V_19 ) {
F_4 ( & V_18 -> V_2 , L_3
L_4 , V_7 . V_8 ) ;
break;
}
F_5 ( & V_18 -> V_2 , L_5 ,
V_7 . V_8 , V_7 . V_13 ) ;
F_10 ( & V_18 -> V_21 -> V_2 , & V_7 ,
F_1 ) ;
V_19 = V_7 . V_8 ;
}
if ( ! V_12 -> V_22 )
F_11 ( V_12 -> V_23 ) ;
}
static T_2 F_12 ( int V_23 , void * V_24 )
{
struct V_17 * V_12 = V_24 ;
if ( ! V_12 -> V_22 )
F_13 ( V_23 ) ;
F_14 ( & V_12 -> V_12 ) ;
return V_25 ;
}
static int F_15 ( struct V_4 * V_18 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_18 -> V_2 . V_30 ;
struct V_17 * V_12 ;
struct V_31 * V_21 = V_18 -> V_21 ;
int V_32 ;
V_12 = F_16 ( sizeof( struct V_17 ) , V_33 ) ;
if ( ! V_12 )
return - V_34 ;
V_12 -> V_22 = V_29 -> V_22 ;
V_12 -> V_23 = V_29 -> V_23 ;
F_17 ( & V_12 -> V_12 , F_7 ) ;
V_12 -> V_18 = V_18 ;
if ( V_29 -> V_23 > 0 ) {
V_32 = F_18 ( & V_18 -> V_2 , V_29 -> V_23 , F_12 ,
0 , L_6 , V_12 ) ;
if ( V_32 ) {
F_19 ( V_12 ) ;
return V_32 ;
}
}
F_20 ( V_18 , V_12 ) ;
F_21 ( & V_21 -> V_2 , L_7 ,
V_29 -> V_22 ? L_8 : L_9 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_18 )
{
struct V_17 * V_12 = F_23 ( V_18 ) ;
F_24 ( & V_12 -> V_12 ) ;
F_19 ( V_12 ) ;
return 0 ;
}
struct V_4 * F_25 ( struct V_31 * V_21 ,
struct V_28 * V_29 )
{
struct V_35 V_36 = {
F_26 ( L_6 , 0x0c ) ,
. V_30 = V_29 ,
} ;
return F_27 ( V_21 , & V_36 ) ;
}
int F_28 ( struct V_4 * V_18 )
{
struct V_17 * V_12 = F_23 ( V_18 ) ;
return F_14 ( & V_12 -> V_12 ) ;
}
