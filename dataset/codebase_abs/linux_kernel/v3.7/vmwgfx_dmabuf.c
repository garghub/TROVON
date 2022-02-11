int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
bool V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_4 -> V_13 ;
int V_14 ;
V_14 = F_2 ( & V_9 -> V_15 , V_7 ) ;
if ( F_3 ( V_14 != 0 ) )
return V_14 ;
F_4 ( V_2 , false , 0 ) ;
V_14 = F_5 ( V_12 , V_7 , false , false , 0 ) ;
if ( F_3 ( V_14 != 0 ) )
goto V_16;
V_14 = F_6 ( V_12 , V_6 , V_7 , false , false ) ;
F_7 ( V_12 ) ;
V_16:
F_8 ( & V_9 -> V_15 ) ;
return V_14 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_17 , bool V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_4 -> V_13 ;
struct V_5 * V_6 ;
int V_14 ;
V_14 = F_2 ( & V_9 -> V_15 , V_7 ) ;
if ( F_3 ( V_14 != 0 ) )
return V_14 ;
if ( V_17 )
F_4 ( V_2 , false , 0 ) ;
V_14 = F_5 ( V_12 , V_7 , false , false , 0 ) ;
if ( F_3 ( V_14 != 0 ) )
goto V_16;
if ( V_17 )
V_6 = & V_18 ;
else
V_6 = & V_19 ;
V_14 = F_6 ( V_12 , V_6 , V_7 , false , false ) ;
if ( F_10 ( V_14 == 0 ) || V_14 == - V_20 )
goto V_21;
if ( V_17 )
V_6 = & V_22 ;
else
V_6 = & V_23 ;
V_14 = F_6 ( V_12 , V_6 , V_7 , false , false ) ;
V_21:
F_7 ( V_12 ) ;
V_16:
F_8 ( & V_9 -> V_15 ) ;
return V_14 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_17 , bool V_7 )
{
struct V_5 * V_6 ;
if ( V_17 )
V_6 = & V_22 ;
else
V_6 = & V_23 ;
return F_1 ( V_2 , V_4 ,
V_6 ,
V_7 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_17 , bool V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_4 -> V_13 ;
struct V_5 V_6 ;
int V_14 = 0 ;
if ( V_17 )
V_6 = V_22 ;
else
V_6 = V_23 ;
V_6 . V_24 = V_12 -> V_25 ;
V_14 = F_2 ( & V_9 -> V_15 , V_7 ) ;
if ( F_3 ( V_14 != 0 ) )
return V_14 ;
if ( V_17 )
F_4 ( V_2 , false , 0 ) ;
V_14 = F_5 ( V_12 , V_7 , false , false , 0 ) ;
if ( F_3 ( V_14 != 0 ) )
goto V_26;
if ( V_12 -> V_27 . V_28 == V_29 &&
V_12 -> V_27 . V_30 < V_12 -> V_25 &&
V_12 -> V_27 . V_30 > 0 )
( void ) F_6 ( V_12 , & V_31 , false ,
false , false ) ;
V_14 = F_6 ( V_12 , & V_6 , V_7 , false , false ) ;
F_13 ( V_14 == 0 && V_12 -> V_32 != 0 ) ;
F_7 ( V_12 ) ;
V_26:
F_8 ( & V_9 -> V_15 ) ;
return V_14 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
return F_1 ( V_2 , V_4 ,
& V_33 ,
V_7 ) ;
}
void F_15 ( const struct V_11 * V_12 ,
T_1 * V_34 )
{
if ( V_12 -> V_27 . V_28 == V_29 ) {
V_34 -> V_35 = V_36 ;
V_34 -> V_32 = V_12 -> V_32 ;
} else {
V_34 -> V_35 = V_12 -> V_27 . V_30 ;
V_34 -> V_32 = 0 ;
}
}
void F_16 ( struct V_11 * V_12 , bool V_17 )
{
T_2 V_37 ;
struct V_5 V_6 ;
T_2 V_38 = V_12 -> V_27 . V_28 ;
int V_14 ;
F_17 ( ! F_18 ( & V_12 -> V_39 ) ) ;
F_17 ( V_38 != V_29 &&
V_38 != V_40 ) ;
V_37 = V_41 | V_42 | V_43 ;
if ( V_17 )
V_37 |= V_44 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_45 = 1 ;
V_6 . V_6 = & V_37 ;
V_14 = F_6 ( V_12 , & V_6 , false , true , true ) ;
F_17 ( V_14 != 0 || V_12 -> V_27 . V_28 != V_38 ) ;
}
