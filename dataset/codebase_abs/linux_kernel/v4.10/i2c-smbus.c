static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 ;
if ( ! V_5 || V_5 -> V_10 != V_7 -> V_10 )
return 0 ;
if ( V_5 -> V_11 & V_12 )
return 0 ;
F_3 ( V_2 ) ;
if ( V_5 -> V_2 . V_9 ) {
V_9 = F_4 ( V_5 -> V_2 . V_9 ) ;
if ( V_9 -> V_13 )
V_9 -> V_13 ( V_5 , V_7 -> type , V_7 -> V_7 ) ;
else
F_5 ( & V_5 -> V_2 , L_1 ) ;
} else
F_6 ( & V_5 -> V_2 , L_2 ) ;
F_7 ( V_2 ) ;
return - V_14 ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_13 ;
struct V_4 * V_18 ;
unsigned short V_19 = 0 ;
V_13 = F_9 ( V_16 , struct V_17 , V_13 ) ;
V_18 = V_13 -> V_18 ;
for (; ; ) {
T_1 V_20 ;
struct V_6 V_7 ;
V_20 = F_10 ( V_18 ) ;
if ( V_20 < 0 )
break;
V_7 . V_7 = V_20 & 1 ;
V_7 . V_10 = V_20 >> 1 ;
V_7 . type = V_21 ;
if ( V_7 . V_10 == V_19 ) {
F_5 ( & V_18 -> V_2 , L_3
L_4 , V_7 . V_10 ) ;
break;
}
F_6 ( & V_18 -> V_2 , L_5 ,
V_7 . V_10 , V_7 . V_7 ) ;
F_11 ( & V_18 -> V_22 -> V_2 , & V_7 ,
F_1 ) ;
V_19 = V_7 . V_10 ;
}
if ( ! V_13 -> V_23 )
F_12 ( V_13 -> V_24 ) ;
}
static T_2 F_13 ( int V_24 , void * V_25 )
{
struct V_17 * V_13 = V_25 ;
if ( ! V_13 -> V_23 )
F_14 ( V_24 ) ;
F_15 ( & V_13 -> V_13 ) ;
return V_26 ;
}
static int F_16 ( struct V_4 * V_18 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 = F_17 ( & V_18 -> V_2 ) ;
struct V_17 * V_13 ;
struct V_31 * V_22 = V_18 -> V_22 ;
int V_32 ;
V_13 = F_18 ( & V_18 -> V_2 , sizeof( struct V_17 ) ,
V_33 ) ;
if ( ! V_13 )
return - V_34 ;
V_13 -> V_23 = V_30 -> V_23 ;
V_13 -> V_24 = V_30 -> V_24 ;
F_19 ( & V_13 -> V_13 , F_8 ) ;
V_13 -> V_18 = V_18 ;
if ( V_30 -> V_24 > 0 ) {
V_32 = F_20 ( & V_18 -> V_2 , V_30 -> V_24 , F_13 ,
0 , L_6 , V_13 ) ;
if ( V_32 )
return V_32 ;
}
F_21 ( V_18 , V_13 ) ;
F_22 ( & V_22 -> V_2 , L_7 ,
V_30 -> V_23 ? L_8 : L_9 ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_18 )
{
struct V_17 * V_13 = F_24 ( V_18 ) ;
F_25 ( & V_13 -> V_13 ) ;
return 0 ;
}
struct V_4 * F_26 ( struct V_31 * V_22 ,
struct V_29 * V_30 )
{
struct V_35 V_36 = {
F_27 ( L_6 , 0x0c ) ,
. V_37 = V_30 ,
} ;
return F_28 ( V_22 , & V_36 ) ;
}
int F_29 ( struct V_4 * V_18 )
{
struct V_17 * V_13 = F_24 ( V_18 ) ;
return F_15 ( & V_13 -> V_13 ) ;
}
