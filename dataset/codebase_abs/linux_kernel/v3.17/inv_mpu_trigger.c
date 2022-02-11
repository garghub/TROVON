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
V_16 = F_8 ( V_4 , V_4 -> V_19 -> V_20 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_8 ( V_4 , V_4 -> V_19 -> V_21 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_8 ( V_4 , V_4 -> V_19 -> V_22 , 0 ) ;
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
V_4 -> V_5 . V_15 = V_15 ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 ,
bool V_25 )
{
return F_4 ( F_10 ( V_24 ) , V_25 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_24 = F_12 ( L_1 ,
V_2 -> V_27 ,
V_2 -> V_28 ) ;
if ( V_4 -> V_24 == NULL ) {
V_26 = - V_29 ;
goto V_30;
}
V_26 = F_13 ( V_4 -> V_31 -> V_32 , & V_33 ,
V_34 ,
L_2 ,
V_4 -> V_24 ) ;
if ( V_26 )
goto V_35;
V_4 -> V_24 -> V_36 . V_37 = & V_4 -> V_31 -> V_36 ;
V_4 -> V_24 -> V_38 = & V_39 ;
F_14 ( V_4 -> V_24 , V_2 ) ;
V_26 = F_15 ( V_4 -> V_24 ) ;
if ( V_26 )
goto V_40;
V_2 -> V_24 = F_16 ( V_4 -> V_24 ) ;
return 0 ;
V_40:
F_17 ( V_4 -> V_31 -> V_32 , V_4 -> V_24 ) ;
V_35:
F_18 ( V_4 -> V_24 ) ;
V_30:
return V_26 ;
}
void F_19 ( struct V_3 * V_4 )
{
F_20 ( V_4 -> V_24 ) ;
F_17 ( V_4 -> V_31 -> V_32 , V_4 -> V_24 ) ;
F_18 ( V_4 -> V_24 ) ;
}
