static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ,
struct V_4 ,
V_6 ) ;
V_3 = F_4 ( V_5 -> V_7 ) ;
if ( V_3 ) {
F_5 ( V_5 -> V_8 ,
V_9 [ V_10 ] ,
false ) ;
F_5 ( V_5 -> V_8 ,
V_9 [ V_11 ] ,
true ) ;
} else {
F_5 ( V_5 -> V_8 ,
V_9 [ V_11 ] ,
false ) ;
F_5 ( V_5 -> V_8 ,
V_9 [ V_10 ] ,
true ) ;
}
}
static T_1 F_6 ( int V_12 , void * V_13 )
{
struct V_4 * V_5 = V_13 ;
F_7 ( V_14 , & V_5 -> V_6 ,
V_5 -> V_15 ) ;
return V_16 ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_4 * V_5 ;
int V_24 ;
if ( ! V_22 )
return - V_25 ;
V_5 = F_9 ( & V_18 -> V_20 , sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return - V_27 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_7 = F_10 ( & V_18 -> V_20 , L_1 ) ;
if ( F_11 ( V_5 -> V_7 ) ) {
F_12 ( V_20 , L_2 ) ;
return F_13 ( V_5 -> V_7 ) ;
}
V_5 -> V_8 = F_14 ( V_20 , V_9 ) ;
if ( F_11 ( V_5 -> V_8 ) ) {
F_12 ( V_20 , L_3 ) ;
return - V_27 ;
}
V_24 = F_15 ( V_20 , V_5 -> V_8 ) ;
if ( V_24 < 0 ) {
F_12 ( V_20 , L_4 ) ;
return V_24 ;
}
V_24 = F_16 ( V_5 -> V_7 ,
V_28 * 1000 ) ;
if ( V_24 < 0 )
V_5 -> V_15 = F_17 ( V_28 ) ;
F_18 ( & V_5 -> V_6 , F_1 ) ;
V_5 -> V_29 = F_19 ( V_5 -> V_7 ) ;
if ( V_5 -> V_29 < 0 ) {
F_12 ( V_20 , L_5 ) ;
return V_5 -> V_29 ;
}
V_24 = F_20 ( V_20 , V_5 -> V_29 , NULL ,
F_6 ,
V_30 |
V_31 | V_32 ,
V_18 -> V_33 , V_5 ) ;
if ( V_24 < 0 ) {
F_12 ( V_20 , L_6 ) ;
return V_24 ;
}
F_21 ( V_18 , V_5 ) ;
F_22 ( V_20 , 1 ) ;
F_1 ( & V_5 -> V_6 . V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = F_24 ( V_18 ) ;
F_25 ( & V_5 -> V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 )
{
struct V_4 * V_5 = F_27 ( V_20 ) ;
int V_24 = 0 ;
if ( F_28 ( V_20 ) ) {
V_24 = F_29 ( V_5 -> V_29 ) ;
if ( V_24 )
return V_24 ;
}
F_30 ( V_5 -> V_29 ) ;
return V_24 ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_4 * V_5 = F_27 ( V_20 ) ;
int V_24 = 0 ;
if ( F_28 ( V_20 ) ) {
V_24 = F_32 ( V_5 -> V_29 ) ;
if ( V_24 )
return V_24 ;
}
F_33 ( V_5 -> V_29 ) ;
return V_24 ;
}
