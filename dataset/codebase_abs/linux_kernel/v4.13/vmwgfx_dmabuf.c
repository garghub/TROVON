int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 ;
T_1 V_12 ;
V_11 = F_2 ( & V_2 -> V_13 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_14;
if ( V_4 -> V_15 > 0 )
V_11 = F_6 ( V_6 , & V_9 -> V_16 ,
& V_12 ) == true ? 0 : - V_17 ;
else
V_11 = F_7 ( V_9 , V_6 , V_7 , false ) ;
if ( ! V_11 )
F_8 ( V_4 , true ) ;
F_9 ( V_9 ) ;
V_14:
F_10 ( & V_2 -> V_13 ) ;
return V_11 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 ;
T_1 V_12 ;
V_11 = F_2 ( & V_2 -> V_13 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_14;
if ( V_4 -> V_15 > 0 ) {
V_11 = F_6 ( & V_18 , & V_9 -> V_16 ,
& V_12 ) == true ? 0 : - V_17 ;
goto V_19;
}
V_11 = F_7 ( V_9 , & V_18 , V_7 ,
false ) ;
if ( F_12 ( V_11 == 0 ) || V_11 == - V_20 )
goto V_19;
V_11 = F_7 ( V_9 , & V_21 , V_7 , false ) ;
V_19:
if ( ! V_11 )
F_8 ( V_4 , true ) ;
F_9 ( V_9 ) ;
V_14:
F_10 ( & V_2 -> V_13 ) ;
return V_11 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
return F_1 ( V_2 , V_4 , & V_21 ,
V_7 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
struct V_5 V_6 ;
struct V_22 V_23 ;
int V_11 = 0 ;
T_1 V_12 ;
V_23 = V_21 . V_6 [ 0 ] ;
V_23 . V_24 = V_9 -> V_25 ;
V_6 . V_26 = 1 ;
V_6 . V_6 = & V_23 ;
V_6 . V_27 = 1 ;
V_6 . V_28 = & V_23 ;
V_11 = F_2 ( & V_2 -> V_13 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_29;
if ( V_9 -> V_16 . V_30 == V_31 &&
V_9 -> V_16 . V_32 < V_9 -> V_25 &&
V_9 -> V_16 . V_32 > 0 &&
V_4 -> V_15 == 0 )
( void ) F_7 ( V_9 , & V_33 , false , false ) ;
if ( V_4 -> V_15 > 0 )
V_11 = F_6 ( & V_6 , & V_9 -> V_16 ,
& V_12 ) == true ? 0 : - V_17 ;
else
V_11 = F_7 ( V_9 , & V_6 , V_7 , false ) ;
F_15 ( V_11 == 0 && V_9 -> V_34 != 0 ) ;
if ( ! V_11 )
F_8 ( V_4 , true ) ;
F_9 ( V_9 ) ;
V_29:
F_10 ( & V_2 -> V_13 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 ;
V_11 = F_17 ( & V_2 -> V_13 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_5 ( V_9 , V_7 , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_14;
F_8 ( V_4 , false ) ;
F_9 ( V_9 ) ;
V_14:
F_18 ( & V_2 -> V_13 ) ;
return V_11 ;
}
void F_19 ( const struct V_8 * V_9 ,
T_2 * V_35 )
{
if ( V_9 -> V_16 . V_30 == V_31 ) {
V_35 -> V_36 = V_37 ;
V_35 -> V_34 = V_9 -> V_34 ;
} else {
V_35 -> V_36 = V_9 -> V_16 . V_32 ;
V_35 -> V_34 = 0 ;
}
}
void F_8 ( struct V_3 * V_38 , bool V_39 )
{
struct V_22 V_40 ;
struct V_5 V_6 ;
struct V_8 * V_9 = & V_38 -> V_10 ;
T_1 V_41 = V_9 -> V_16 . V_30 ;
int V_11 ;
F_20 ( & V_9 -> V_42 -> V_43 . V_10 ) ;
if ( V_39 ) {
if ( V_38 -> V_15 ++ > 0 )
return;
} else {
F_15 ( V_38 -> V_15 <= 0 ) ;
if ( -- V_38 -> V_15 > 0 )
return;
}
V_40 . V_44 = 0 ;
V_40 . V_24 = 0 ;
V_40 . V_45 = V_46 | V_47 | V_48
| V_49 | V_50 ;
if ( V_39 )
V_40 . V_45 |= V_51 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_26 = 1 ;
V_6 . V_6 = & V_40 ;
V_11 = F_7 ( V_9 , & V_6 , false , true ) ;
F_21 ( V_11 != 0 || V_9 -> V_16 . V_30 != V_41 ) ;
}
