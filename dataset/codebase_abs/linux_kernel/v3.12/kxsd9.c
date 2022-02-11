static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_8 = false ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ )
if ( V_3 == V_9 [ V_5 ] ) {
V_8 = true ;
break;
}
if ( ! V_8 )
return - V_10 ;
F_3 ( & V_7 -> V_11 ) ;
V_4 = F_4 ( V_7 -> V_12 , F_5 ( V_13 ) ) ;
if ( V_4 )
goto V_14;
V_7 -> V_15 [ 0 ] = F_6 ( V_13 ) ;
V_7 -> V_15 [ 1 ] = ( V_4 & ~ V_16 ) | V_5 ;
V_4 = F_7 ( V_7 -> V_12 , V_7 -> V_15 , 2 ) ;
V_14:
F_8 ( & V_7 -> V_11 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_18 V_19 [] = {
{
. V_20 = 8 ,
. V_21 = 1 ,
. V_22 = 200 ,
. V_23 = V_7 -> V_15 ,
} , {
. V_20 = 8 ,
. V_21 = 2 ,
. V_24 = V_7 -> V_25 ,
} ,
} ;
F_3 ( & V_7 -> V_11 ) ;
V_7 -> V_15 [ 0 ] = F_5 ( V_17 ) ;
V_4 = F_10 ( V_7 -> V_12 , V_19 , F_11 ( V_19 ) ) ;
if ( V_4 )
return V_4 ;
return ( ( ( V_26 ) ( V_7 -> V_25 [ 0 ] ) ) << 8 ) | ( V_7 -> V_25 [ 1 ] & 0xF0 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_27 const * V_28 ,
int V_29 ,
int V_30 ,
long V_31 )
{
int V_4 = - V_10 ;
if ( V_31 == V_32 ) {
if ( V_29 )
return - V_10 ;
V_4 = F_1 ( V_2 , V_30 ) ;
}
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_27 const * V_28 ,
int * V_29 , int * V_30 , long V_31 )
{
int V_4 = - V_10 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_31 ) {
case V_33 :
V_4 = F_9 ( V_2 , V_28 -> V_17 ) ;
if ( V_4 < 0 )
goto V_14;
* V_29 = V_4 ;
break;
case V_32 :
V_4 = F_4 ( V_7 -> V_12 , F_5 ( V_13 ) ) ;
if ( V_4 )
goto V_14;
* V_30 = V_9 [ V_4 & V_16 ] ;
V_4 = V_34 ;
break;
}
V_14:
return V_4 ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_4 ;
V_7 -> V_15 [ 0 ] = 0x0d ;
V_7 -> V_15 [ 1 ] = 0x40 ;
V_4 = F_7 ( V_7 -> V_12 , V_7 -> V_15 , 2 ) ;
if ( V_4 )
return V_4 ;
V_7 -> V_15 [ 0 ] = 0x0c ;
V_7 -> V_15 [ 1 ] = 0x9b ;
return F_7 ( V_7 -> V_12 , V_7 -> V_15 , 2 ) ;
}
static int F_15 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_4 ;
V_2 = F_16 ( & V_36 -> V_37 , sizeof( * V_7 ) ) ;
if ( ! V_2 )
return - V_38 ;
V_7 = F_2 ( V_2 ) ;
F_17 ( V_36 , V_2 ) ;
V_7 -> V_12 = V_36 ;
F_18 ( & V_7 -> V_11 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = F_11 ( V_40 ) ;
V_2 -> V_42 = F_19 ( V_36 ) -> V_42 ;
V_2 -> V_37 . V_43 = & V_36 -> V_37 ;
V_2 -> V_44 = & V_45 ;
V_2 -> V_46 = V_47 ;
V_36 -> V_48 = V_49 ;
F_20 ( V_36 ) ;
F_14 ( V_7 ) ;
V_4 = F_21 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 )
{
F_23 ( F_24 ( V_36 ) ) ;
return 0 ;
}
