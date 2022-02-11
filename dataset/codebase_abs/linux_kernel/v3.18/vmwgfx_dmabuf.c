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
F_7 ( V_9 ) ;
V_13:
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_14 , bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
struct V_5 * V_6 ;
int V_11 ;
V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
if ( V_14 )
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_13;
if ( V_14 )
V_6 = & V_15 ;
else
V_6 = & V_16 ;
V_11 = F_6 ( V_9 , V_6 , V_7 , false ) ;
if ( F_10 ( V_11 == 0 ) || V_11 == - V_17 )
goto V_18;
if ( V_14 )
V_6 = & V_19 ;
else
V_6 = & V_20 ;
V_11 = F_6 ( V_9 , V_6 , V_7 , false ) ;
V_18:
F_7 ( V_9 ) ;
V_13:
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_14 , bool V_7 )
{
struct V_5 * V_6 ;
if ( V_14 )
V_6 = & V_19 ;
else
V_6 = & V_20 ;
return F_1 ( V_2 , V_4 ,
V_6 ,
V_7 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_14 , bool V_7 )
{
struct V_8 * V_9 = & V_4 -> V_10 ;
struct V_5 V_6 ;
struct V_21 V_22 ;
int V_11 = 0 ;
if ( V_14 )
V_22 = V_19 . V_6 [ 0 ] ;
else
V_22 = V_20 . V_6 [ 0 ] ;
V_22 . V_23 = V_9 -> V_24 ;
V_6 . V_25 = 1 ;
V_6 . V_6 = & V_22 ;
V_6 . V_26 = 1 ;
V_6 . V_27 = & V_22 ;
V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
if ( V_14 )
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_28;
if ( V_9 -> V_29 . V_30 == V_31 &&
V_9 -> V_29 . V_32 < V_9 -> V_24 &&
V_9 -> V_29 . V_32 > 0 )
( void ) F_6 ( V_9 , & V_33 , false , false ) ;
V_11 = F_6 ( V_9 , & V_6 , V_7 , false ) ;
F_13 ( V_11 == 0 && V_9 -> V_34 != 0 ) ;
F_7 ( V_9 ) ;
V_28:
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
return F_1 ( V_2 , V_4 ,
& V_35 ,
V_7 ) ;
}
void F_15 ( const struct V_8 * V_9 ,
T_1 * V_36 )
{
if ( V_9 -> V_29 . V_30 == V_31 ) {
V_36 -> V_37 = V_38 ;
V_36 -> V_34 = V_9 -> V_34 ;
} else {
V_36 -> V_37 = V_9 -> V_29 . V_32 ;
V_36 -> V_34 = 0 ;
}
}
void F_16 ( struct V_8 * V_9 , bool V_14 )
{
struct V_21 V_39 ;
struct V_5 V_6 ;
T_2 V_40 = V_9 -> V_29 . V_30 ;
int V_11 ;
F_17 ( & V_9 -> V_41 -> V_42 . V_10 ) ;
V_39 . V_43 = 0 ;
V_39 . V_23 = 0 ;
V_39 . V_44 = V_45 | V_46 | V_47
| V_48 | V_49 ;
if ( V_14 )
V_39 . V_44 |= V_50 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_25 = 1 ;
V_6 . V_6 = & V_39 ;
V_11 = F_6 ( V_9 , & V_6 , false , true ) ;
F_18 ( V_11 != 0 || V_9 -> V_29 . V_30 != V_40 ) ;
}
