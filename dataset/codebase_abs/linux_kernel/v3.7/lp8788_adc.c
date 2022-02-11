static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
int * V_5 )
{
unsigned int V_6 ;
unsigned int V_7 ;
unsigned int V_8 ;
T_1 V_9 ;
T_1 V_10 [ 2 ] ;
int V_11 = F_2 ( V_10 ) ;
int V_12 = 5 ;
int V_13 ;
V_9 = ( V_4 << 1 ) | V_14 ;
V_13 = F_3 ( V_2 -> V_15 , V_16 , V_9 ) ;
if ( V_13 )
goto V_17;
V_9 = 0 ;
while ( V_12 -- ) {
F_4 ( 100 , 200 ) ;
V_13 = F_5 ( V_2 -> V_15 , V_18 , & V_9 ) ;
if ( V_13 )
goto V_17;
if ( V_9 )
break;
}
V_13 = F_6 ( V_2 -> V_15 , V_19 , V_10 , V_11 ) ;
if ( V_13 )
goto V_17;
V_6 = ( V_10 [ 0 ] << 4 ) & 0x00000ff0 ;
V_7 = ( V_10 [ 1 ] >> 4 ) & 0x0000000f ;
V_8 = V_6 | V_7 ;
* V_5 = V_8 ;
return 0 ;
V_17:
return V_13 ;
}
static int F_7 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_5 , int * V_24 , long V_25 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
enum V_3 V_4 = V_23 -> V_26 ;
int V_13 ;
F_9 ( & V_2 -> V_27 ) ;
switch ( V_25 ) {
case V_28 :
V_13 = F_1 ( V_2 , V_4 , V_5 ) ? - V_29 : V_30 ;
break;
case V_31 :
* V_5 = V_32 [ V_4 ] / 1000000 ;
* V_24 = V_32 [ V_4 ] % 1000000 ;
V_13 = V_33 ;
break;
default:
V_13 = - V_34 ;
break;
}
F_10 ( & V_2 -> V_27 ) ;
return V_13 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_35 * V_36 ,
struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_13 ;
V_38 = ( ! V_36 || ! V_36 -> V_39 ) ?
V_40 : V_36 -> V_39 ;
V_13 = F_12 ( V_21 , V_38 ) ;
if ( V_13 ) {
F_13 ( V_2 -> V_15 -> V_41 , L_1 , V_13 ) ;
return V_13 ;
}
V_2 -> V_38 = V_38 ;
return 0 ;
}
static inline void F_14 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
F_15 ( V_21 , V_2 -> V_38 ) ;
}
static int T_2 F_16 ( struct V_42 * V_43 )
{
struct V_44 * V_15 = F_17 ( V_43 -> V_41 . V_45 ) ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_13 ;
V_21 = F_18 ( sizeof( * V_2 ) ) ;
if ( ! V_21 )
return - V_46 ;
V_2 = F_8 ( V_21 ) ;
V_2 -> V_15 = V_15 ;
F_19 ( V_43 , V_21 ) ;
V_13 = F_11 ( V_21 , V_15 -> V_36 , V_2 ) ;
if ( V_13 )
goto V_47;
F_20 ( & V_2 -> V_27 ) ;
V_21 -> V_41 . V_45 = V_15 -> V_41 ;
V_21 -> V_48 = V_43 -> V_48 ;
V_21 -> V_49 = V_50 ;
V_21 -> V_51 = & V_52 ;
V_21 -> V_53 = V_54 ;
V_21 -> V_55 = F_2 ( V_54 ) ;
V_13 = F_21 ( V_21 ) ;
if ( V_13 ) {
F_13 ( V_15 -> V_41 , L_2 , V_13 ) ;
goto V_56;
}
return 0 ;
V_56:
F_14 ( V_21 , V_2 ) ;
V_47:
F_22 ( V_21 ) ;
return V_13 ;
}
static int T_3 F_23 ( struct V_42 * V_43 )
{
struct V_20 * V_21 = F_24 ( V_43 ) ;
struct V_1 * V_2 = F_8 ( V_21 ) ;
F_25 ( V_21 ) ;
F_14 ( V_21 , V_2 ) ;
F_22 ( V_21 ) ;
return 0 ;
}
