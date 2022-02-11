static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 ;
struct V_10 V_11 = {
. V_12 = V_7 -> V_13 ,
. V_14 = V_7 -> V_13 ,
. V_15 = 4 ,
} ;
F_3 ( & V_7 -> V_16 ) ;
V_7 -> V_13 [ 0 ] = V_17 | V_3 ;
V_7 -> V_13 [ 1 ] = V_7 -> V_13 [ 2 ] = V_7 -> V_13 [ 3 ] = 0 ;
F_4 ( & V_9 ) ;
F_5 ( & V_11 , & V_9 ) ;
V_5 = F_6 ( V_7 -> V_18 , & V_9 ) ;
if ( V_5 == 0 )
* V_4 = ( V_7 -> V_13 [ 1 ] << 16 ) | ( V_7 -> V_13 [ 2 ] << 8 ) | V_7 -> V_13 [ 3 ] ;
F_7 ( & V_7 -> V_16 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_19 const * V_20 ,
int * V_4 , int * V_21 ,
long V_22 )
{
int V_5 ;
T_2 V_23 ;
switch ( V_22 ) {
case V_24 :
F_3 ( & V_2 -> V_25 ) ;
V_5 = F_1 ( V_2 , V_20 -> V_26 , & V_23 ) ;
F_7 ( & V_2 -> V_25 ) ;
if ( V_5 )
return V_5 ;
* V_4 = V_23 ;
return V_27 ;
case V_28 :
switch ( V_20 -> type ) {
case V_29 :
* V_4 = 250 ;
* V_21 = 336440817 ;
return V_30 ;
case V_31 :
* V_4 = 105000 ;
* V_21 = 9516048 - 8036283 ;
return V_30 ;
default:
return - V_32 ;
}
break;
case V_33 :
switch ( V_20 -> type ) {
case V_29 :
* V_4 = - 8388608 ;
return V_27 ;
case V_31 :
* V_4 = - 8036283 ;
return V_27 ;
default:
return - V_32 ;
}
break;
}
return - V_32 ;
}
static int F_9 ( struct V_34 * V_35 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_36 ;
goto V_37;
}
V_7 = F_2 ( V_2 ) ;
F_11 ( V_35 , V_2 ) ;
V_7 -> V_18 = V_35 ;
F_12 ( & V_7 -> V_16 ) ;
V_2 -> V_38 = V_35 -> V_39 . V_40 -> V_38 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = F_13 ( V_42 ) ;
V_2 -> V_39 . V_44 = & V_35 -> V_39 ;
V_2 -> V_45 = & V_46 ;
V_2 -> V_47 = V_48 ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 )
goto V_49;
return 0 ;
V_49:
F_15 ( V_2 ) ;
V_37:
return V_5 ;
}
static int F_16 ( struct V_34 * V_35 )
{
F_17 ( F_18 ( V_35 ) ) ;
F_15 ( F_18 ( V_35 ) ) ;
return 0 ;
}
