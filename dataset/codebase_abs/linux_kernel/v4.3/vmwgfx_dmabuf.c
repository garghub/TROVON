int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 ;
V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_13;
V_11 = F_6 ( V_9 , V_6 , V_7 , false ) ;
if ( ! V_11 )
F_7 ( V_4 , true ) ;
F_8 ( V_9 ) ;
V_13:
F_9 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 ;
V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_13;
V_11 = F_6 ( V_9 , & V_14 , V_7 ,
false ) ;
if ( F_11 ( V_11 == 0 ) || V_11 == - V_15 )
goto V_16;
V_11 = F_6 ( V_9 , & V_17 , V_7 , false ) ;
V_16:
if ( ! V_11 )
F_7 ( V_4 , true ) ;
F_8 ( V_9 ) ;
V_13:
F_9 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
return F_1 ( V_2 , V_4 , & V_17 ,
V_7 ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
struct V_5 V_6 ;
struct V_18 V_19 ;
int V_11 = 0 ;
V_19 = V_17 . V_6 [ 0 ] ;
V_19 . V_20 = V_9 -> V_21 ;
V_6 . V_22 = 1 ;
V_6 . V_6 = & V_19 ;
V_6 . V_23 = 1 ;
V_6 . V_24 = & V_19 ;
V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_25;
if ( V_9 -> V_26 . V_27 == V_28 &&
V_9 -> V_26 . V_29 < V_9 -> V_21 &&
V_9 -> V_26 . V_29 > 0 )
( void ) F_6 ( V_9 , & V_30 , false , false ) ;
V_11 = F_6 ( V_9 , & V_6 , V_7 , false ) ;
F_14 ( V_11 == 0 && V_9 -> V_31 != 0 ) ;
if ( ! V_11 )
F_7 ( V_4 , true ) ;
F_8 ( V_9 ) ;
V_25:
F_9 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 ;
V_11 = F_16 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_13;
F_7 ( V_4 , false ) ;
F_8 ( V_9 ) ;
V_13:
F_17 ( & V_2 -> V_12 ) ;
return V_11 ;
}
void F_18 ( const struct V_8 * V_9 ,
T_1 * V_32 )
{
if ( V_9 -> V_26 . V_27 == V_28 ) {
V_32 -> V_33 = V_34 ;
V_32 -> V_31 = V_9 -> V_31 ;
} else {
V_32 -> V_33 = V_9 -> V_26 . V_29 ;
V_32 -> V_31 = 0 ;
}
}
void F_7 ( struct V_3 * V_35 , bool V_36 )
{
struct V_18 V_37 ;
struct V_5 V_6 ;
struct V_8 * V_9 = & V_35 -> V_10 ;
T_2 V_38 = V_9 -> V_26 . V_27 ;
int V_11 ;
F_19 ( & V_9 -> V_39 -> V_40 . V_10 ) ;
if ( V_36 ) {
if ( V_35 -> V_41 ++ > 0 )
return;
} else {
F_14 ( V_35 -> V_41 <= 0 ) ;
if ( -- V_35 -> V_41 > 0 )
return;
}
V_37 . V_42 = 0 ;
V_37 . V_20 = 0 ;
V_37 . V_43 = V_44 | V_45 | V_46
| V_47 | V_48 ;
if ( V_36 )
V_37 . V_43 |= V_49 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_22 = 1 ;
V_6 . V_6 = & V_37 ;
V_11 = F_6 ( V_9 , & V_6 , false , true ) ;
F_20 ( V_11 != 0 || V_9 -> V_26 . V_27 != V_38 ) ;
}
