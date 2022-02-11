static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 . V_6 =
F_3 ( V_7 ,
V_2 -> V_8 ) ||
F_3 ( V_9 ,
V_2 -> V_8 ) ||
F_3 ( V_10 ,
V_2 -> V_8 ) ;
V_4 -> V_5 . V_11 =
F_3 ( V_12 ,
V_2 -> V_8 ) ||
F_3 ( V_13 ,
V_2 -> V_8 ) ||
F_3 ( V_14 ,
V_2 -> V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 , bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
if ( V_15 ) {
V_16 = F_5 ( V_4 , true ) ;
if ( V_16 )
return V_16 ;
F_1 ( V_2 ) ;
if ( V_4 -> V_5 . V_6 ) {
V_16 = F_6 ( V_4 , true ,
V_17 ) ;
if ( V_16 )
return V_16 ;
}
if ( V_4 -> V_5 . V_11 ) {
V_16 = F_6 ( V_4 , true ,
V_18 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_7 ( V_2 ) ;
if ( V_16 )
return V_16 ;
} else {
V_16 = F_8 ( V_4 -> V_19 , V_4 -> V_20 -> V_21 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_8 ( V_4 -> V_19 , V_4 -> V_20 -> V_22 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_8 ( V_4 -> V_19 , V_4 -> V_20 -> V_23 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_6 ( V_4 , false ,
V_17 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_6 ( V_4 , false ,
V_18 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_5 ( V_4 , false ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_24 * V_25 ,
bool V_26 )
{
struct V_1 * V_2 = F_10 ( V_25 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
F_11 ( & V_4 -> V_27 ) ;
V_16 = F_4 ( V_2 , V_26 ) ;
F_12 ( & V_4 -> V_27 ) ;
return V_16 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_25 = F_14 ( & V_2 -> V_29 ,
L_1 ,
V_2 -> V_30 ,
V_2 -> V_31 ) ;
if ( ! V_4 -> V_25 )
return - V_32 ;
V_28 = F_15 ( & V_2 -> V_29 , V_4 -> V_33 ,
& V_34 ,
V_35 ,
L_2 ,
V_4 -> V_25 ) ;
if ( V_28 )
return V_28 ;
V_4 -> V_25 -> V_29 . V_36 = F_16 ( V_4 -> V_19 ) ;
V_4 -> V_25 -> V_37 = & V_38 ;
F_17 ( V_4 -> V_25 , V_2 ) ;
V_28 = F_18 ( V_4 -> V_25 ) ;
if ( V_28 )
return V_28 ;
V_2 -> V_25 = F_19 ( V_4 -> V_25 ) ;
return 0 ;
}
void F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 -> V_25 ) ;
}
