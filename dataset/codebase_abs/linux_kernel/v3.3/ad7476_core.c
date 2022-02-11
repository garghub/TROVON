static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , & V_2 -> V_5 ) ;
if ( V_3 )
return V_3 ;
return ( V_2 -> V_6 [ 0 ] << 8 ) | V_2 -> V_6 [ 1 ] ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int * V_11 ,
int * V_12 ,
long V_13 )
{
int V_3 ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned int V_14 ;
switch ( V_13 ) {
case 0 :
F_5 ( & V_8 -> V_15 ) ;
if ( F_6 ( V_8 ) )
V_3 = - V_16 ;
else
V_3 = F_1 ( V_2 ) ;
F_7 ( & V_8 -> V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_11 = ( V_3 >> V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_20 ) &
F_8 ( V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_21 ) ;
return V_22 ;
case V_23 :
V_14 = ( V_2 -> V_24 * 1000 )
>> V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_21 ;
* V_11 = V_14 / 1000 ;
* V_12 = ( V_14 % 1000 ) * 1000 ;
return V_25 ;
}
return - V_26 ;
}
static int T_1 F_9 ( struct V_27 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_30 . V_31 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_3 , V_32 = 0 ;
V_8 = F_10 ( sizeof( * V_2 ) ) ;
if ( V_8 == NULL ) {
V_3 = - V_33 ;
goto V_34;
}
V_2 = F_4 ( V_8 ) ;
V_2 -> V_35 = F_11 ( & V_4 -> V_30 , L_1 ) ;
if ( ! F_12 ( V_2 -> V_35 ) ) {
V_3 = F_13 ( V_2 -> V_35 ) ;
if ( V_3 )
goto V_36;
V_32 = F_14 ( V_2 -> V_35 ) ;
}
V_2 -> V_17 =
& V_37 [ F_15 ( V_4 ) -> V_38 ] ;
if ( V_2 -> V_17 -> V_24 )
V_2 -> V_24 = V_2 -> V_17 -> V_24 ;
else if ( V_29 && V_29 -> V_39 )
V_2 -> V_24 = V_29 -> V_39 ;
else if ( V_32 )
V_2 -> V_24 = V_32 / 1000 ;
else
F_16 ( & V_4 -> V_30 , L_2 ) ;
F_17 ( V_4 , V_8 ) ;
V_2 -> V_4 = V_4 ;
V_8 -> V_30 . V_40 = & V_4 -> V_30 ;
V_8 -> V_41 = F_15 ( V_4 ) -> V_41 ;
V_8 -> V_42 = V_43 ;
V_8 -> V_44 = V_2 -> V_17 -> V_18 ;
V_8 -> V_45 = 2 ;
V_8 -> V_46 = & V_47 ;
V_2 -> V_48 . V_49 = & V_2 -> V_6 ;
V_2 -> V_48 . V_50 = V_2 -> V_17 -> V_18 [ 0 ] . V_19 . V_51 / 8 ;
F_18 ( & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_48 , & V_2 -> V_5 ) ;
V_3 = F_20 ( V_8 ) ;
if ( V_3 )
goto V_52;
V_3 = F_21 ( V_8 ,
V_2 -> V_17 -> V_18 ,
F_22 ( V_2 -> V_17 -> V_18 ) ) ;
if ( V_3 )
goto V_53;
V_3 = F_23 ( V_8 ) ;
if ( V_3 )
goto V_54;
return 0 ;
V_54:
F_24 ( V_8 ) ;
V_53:
F_25 ( V_8 ) ;
V_52:
if ( ! F_12 ( V_2 -> V_35 ) )
F_26 ( V_2 -> V_35 ) ;
V_36:
if ( ! F_12 ( V_2 -> V_35 ) )
F_27 ( V_2 -> V_35 ) ;
F_28 ( V_8 ) ;
V_34:
return V_3 ;
}
static int F_29 ( struct V_27 * V_4 )
{
struct V_7 * V_8 = F_30 ( V_4 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_31 ( V_8 ) ;
F_24 ( V_8 ) ;
F_25 ( V_8 ) ;
if ( ! F_12 ( V_2 -> V_35 ) ) {
F_26 ( V_2 -> V_35 ) ;
F_27 ( V_2 -> V_35 ) ;
}
F_28 ( V_8 ) ;
return 0 ;
}
