static inline int F_1 ( int V_1 )
{
V_1 = V_1 >> 2 ;
return ( F_2 ( V_1 * 1650 , 16382 ) - 400 ) * 100 ;
}
static inline int F_3 ( int V_1 )
{
V_1 &= ~ 0xC000 ;
return F_2 ( V_1 * 1000 , 16382 ) * 100 ;
}
static int F_4 ( struct V_2 * V_3 )
{
int V_4 = 0 ;
int V_5 ;
struct V_6 * V_6 = F_5 ( V_3 ) ;
unsigned char V_7 [ 4 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_3 -> V_10 ,
. V_11 = V_12 ,
. V_13 = 4 ,
. V_14 = V_7 ,
}
} ;
F_6 ( & V_6 -> V_15 ) ;
if ( F_7 ( V_16 , V_6 -> V_17 + V_18 ) || ! V_6 -> V_19 ) {
V_7 [ 0 ] = 0 ;
V_4 = F_8 ( V_3 , V_7 , V_6 -> V_20 ) ;
if ( V_4 < 0 )
goto V_21;
F_9 ( 40 ) ;
V_4 = F_10 ( V_3 -> V_22 , V_9 , 1 ) ;
if ( V_4 < 0 )
goto V_21;
if ( ( V_7 [ 0 ] & 0xC0 ) != 0 ) {
F_11 ( & V_3 -> V_23 , L_1 ) ;
V_4 = - V_24 ;
goto V_21;
}
V_5 = ( V_7 [ 0 ] << 8 ) + V_7 [ 1 ] ;
V_6 -> V_25 = F_3 ( V_5 ) ;
V_5 = ( V_7 [ 2 ] << 8 ) + V_7 [ 3 ] ;
V_6 -> V_26 = F_1 ( V_5 ) ;
V_6 -> V_17 = V_16 ;
V_6 -> V_19 = true ;
}
V_21:
F_12 ( & V_6 -> V_15 ) ;
return V_4 >= 0 ? 0 : V_4 ;
}
static T_1 F_13 ( struct V_27 * V_23 ,
struct V_28 * V_29 ,
char * V_14 )
{
struct V_2 * V_3 = F_14 ( V_23 ) ;
struct V_6 * V_6 = F_5 ( V_3 ) ;
int V_4 = F_4 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_14 , L_2 , V_6 -> V_26 ) ;
}
static T_1 F_15 ( struct V_27 * V_23 ,
struct V_28 * V_29 , char * V_14 )
{
struct V_2 * V_3 = F_14 ( V_23 ) ;
struct V_6 * V_6 = F_5 ( V_3 ) ;
int V_4 = F_4 ( V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return sprintf ( V_14 , L_2 , V_6 -> V_25 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_30 * V_31 )
{
struct V_6 * V_6 ;
int V_32 ;
if ( ! F_17 ( V_3 -> V_22 , V_33 ) ) {
F_11 ( & V_3 -> V_23 , L_3 ) ;
return - V_34 ;
}
V_6 = F_18 ( & V_3 -> V_23 , sizeof( * V_6 ) , V_35 ) ;
if ( ! V_6 )
return - V_36 ;
F_19 ( V_3 , V_6 ) ;
F_20 ( & V_6 -> V_15 ) ;
V_32 = F_21 ( & V_3 -> V_23 . V_37 , & V_38 ) ;
if ( V_32 ) {
F_22 ( & V_3 -> V_23 , L_4 ) ;
return V_32 ;
}
V_6 -> V_39 = F_23 ( & V_3 -> V_23 ) ;
if ( F_24 ( V_6 -> V_39 ) ) {
F_22 ( & V_3 -> V_23 , L_5 ) ;
V_32 = F_25 ( V_6 -> V_39 ) ;
goto V_40;
}
if ( ! F_17 ( V_3 -> V_22 , V_41 ) )
V_6 -> V_20 = 1 ;
return 0 ;
V_40:
F_26 ( & V_3 -> V_23 . V_37 , & V_38 ) ;
return V_32 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_5 ( V_3 ) ;
F_28 ( V_6 -> V_39 ) ;
F_26 ( & V_3 -> V_23 . V_37 , & V_38 ) ;
return 0 ;
}
