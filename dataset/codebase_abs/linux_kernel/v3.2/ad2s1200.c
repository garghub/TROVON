static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
int V_8 = 0 ;
T_1 V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
F_3 ( & V_11 -> V_12 ) ;
F_4 ( V_11 -> V_13 , 0 ) ;
F_5 ( 1 ) ;
F_4 ( V_11 -> V_13 , 1 ) ;
F_4 ( V_11 -> V_14 , ! ! ( V_4 -> type == V_15 ) ) ;
V_8 = F_6 ( V_11 -> V_16 , V_11 -> V_17 , 2 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_11 -> V_12 ) ;
return V_8 ;
}
switch ( V_4 -> type ) {
case V_15 :
* V_5 = ( ( ( V_18 ) ( V_11 -> V_17 [ 0 ] ) ) << 4 ) | ( ( V_11 -> V_17 [ 1 ] & 0xF0 ) >> 4 ) ;
break;
case V_19 :
V_9 = ( ( ( T_1 ) ( V_11 -> V_17 [ 0 ] ) ) << 4 ) | ( ( V_11 -> V_17 [ 1 ] & 0xF0 ) >> 4 ) ;
V_9 = ( V_9 << 4 ) >> 4 ;
* V_5 = V_9 ;
default:
F_7 ( & V_11 -> V_12 ) ;
return - V_20 ;
}
F_5 ( 1 ) ;
F_7 ( & V_11 -> V_12 ) ;
return V_21 ;
}
static int T_2 F_8 ( struct V_22 * V_23 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_24 , V_8 = 0 ;
unsigned short * V_25 = V_23 -> V_26 . V_27 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
if ( F_9 ( V_25 [ V_24 ] , V_29 , V_30 ) ) {
F_10 ( L_1 ,
V_30 , V_25 [ V_24 ] ) ;
goto V_31;
}
V_2 = F_11 ( sizeof( * V_11 ) ) ;
if ( V_2 == NULL ) {
V_8 = - V_32 ;
goto V_31;
}
F_12 ( V_23 , V_2 ) ;
V_11 = F_2 ( V_2 ) ;
F_13 ( & V_11 -> V_12 ) ;
V_11 -> V_16 = V_23 ;
V_11 -> V_13 = V_25 [ 0 ] ;
V_11 -> V_14 = V_25 [ 1 ] ;
V_2 -> V_26 . V_33 = & V_23 -> V_26 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = F_14 ( V_39 ) ;
V_2 -> V_41 = F_15 ( V_23 ) -> V_41 ;
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
goto V_42;
V_23 -> V_43 = V_44 ;
V_23 -> V_45 = V_46 ;
F_17 ( V_23 ) ;
return 0 ;
V_42:
F_18 ( V_2 ) ;
V_31:
for ( -- V_24 ; V_24 >= 0 ; V_24 -- )
F_19 ( V_25 [ V_24 ] ) ;
return V_8 ;
}
static int T_3 F_20 ( struct V_22 * V_23 )
{
F_21 ( F_22 ( V_23 ) ) ;
F_18 ( F_22 ( V_23 ) ) ;
return 0 ;
}
static T_4 int F_23 ( void )
{
return F_24 ( & V_47 ) ;
}
static T_5 void F_25 ( void )
{
F_26 ( & V_47 ) ;
}
