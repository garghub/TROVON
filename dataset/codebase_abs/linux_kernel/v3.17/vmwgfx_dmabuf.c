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
int V_11 = 0 ;
if ( V_14 )
V_6 = V_19 ;
else
V_6 = V_20 ;
V_6 . V_21 = V_9 -> V_22 ;
V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
if ( F_3 ( V_11 != 0 ) )
return V_11 ;
if ( V_14 )
F_4 ( V_2 ) ;
V_11 = F_5 ( V_9 , V_7 , false , false , NULL ) ;
if ( F_3 ( V_11 != 0 ) )
goto V_23;
if ( V_9 -> V_24 . V_25 == V_26 &&
V_9 -> V_24 . V_27 < V_9 -> V_22 &&
V_9 -> V_24 . V_27 > 0 )
( void ) F_6 ( V_9 , & V_28 , false , false ) ;
V_11 = F_6 ( V_9 , & V_6 , V_7 , false ) ;
F_13 ( V_11 == 0 && V_9 -> V_29 != 0 ) ;
F_7 ( V_9 ) ;
V_23:
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_7 )
{
return F_1 ( V_2 , V_4 ,
& V_30 ,
V_7 ) ;
}
void F_15 ( const struct V_8 * V_9 ,
T_1 * V_31 )
{
if ( V_9 -> V_24 . V_25 == V_26 ) {
V_31 -> V_32 = V_33 ;
V_31 -> V_29 = V_9 -> V_29 ;
} else {
V_31 -> V_32 = V_9 -> V_24 . V_27 ;
V_31 -> V_29 = 0 ;
}
}
void F_16 ( struct V_8 * V_9 , bool V_14 )
{
T_2 V_34 ;
struct V_5 V_6 ;
T_2 V_35 = V_9 -> V_24 . V_25 ;
int V_11 ;
F_17 ( & V_9 -> V_36 -> V_37 . V_10 ) ;
V_34 = V_38 | V_39 | V_40
| V_41 | V_42 ;
if ( V_14 )
V_34 |= V_43 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_44 = 1 ;
V_6 . V_6 = & V_34 ;
V_11 = F_6 ( V_9 , & V_6 , false , true ) ;
F_18 ( V_11 != 0 || V_9 -> V_24 . V_25 != V_35 ) ;
}
