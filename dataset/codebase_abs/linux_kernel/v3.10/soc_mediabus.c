int F_1 ( const struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
case V_7 :
* V_3 = 1 ;
* V_4 = 1 ;
return 0 ;
case V_8 :
* V_3 = 1 ;
* V_4 = 1 ;
return 0 ;
case V_9 :
case V_10 :
* V_3 = 2 ;
* V_4 = 1 ;
return 0 ;
case V_11 :
* V_3 = 3 ;
* V_4 = 2 ;
return 0 ;
case V_12 :
* V_3 = 0 ;
* V_4 = 1 ;
return 0 ;
}
return - V_13 ;
}
T_1 F_2 ( T_2 V_14 , const struct V_1 * V_2 )
{
if ( V_2 -> V_15 != V_16 )
return V_14 * V_2 -> V_17 / 8 ;
switch ( V_2 -> V_5 ) {
case V_6 :
return V_14 * V_2 -> V_17 / 8 ;
case V_9 :
case V_10 :
case V_7 :
return V_14 * 2 ;
case V_11 :
return V_14 * 3 / 2 ;
case V_12 :
return 0 ;
case V_8 :
return V_14 * 4 ;
}
return - V_13 ;
}
T_1 F_3 ( const struct V_1 * V_2 ,
T_2 V_18 , T_2 V_19 )
{
if ( V_2 -> V_15 == V_16 )
return V_18 * V_19 ;
switch ( V_2 -> V_5 ) {
case V_9 :
case V_10 :
return V_18 * V_19 * 2 ;
case V_11 :
return V_18 * V_19 * 3 / 2 ;
default:
return - V_13 ;
}
}
const struct V_1 * F_4 (
enum V_20 V_21 ,
const struct V_22 * V_23 ,
int V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ )
if ( V_23 [ V_25 ] . V_21 == V_21 )
return & V_23 [ V_25 ] . V_26 ;
return NULL ;
}
const struct V_1 * F_5 (
enum V_20 V_21 )
{
return F_4 ( V_21 , V_27 , F_6 ( V_27 ) ) ;
}
unsigned int F_7 ( const struct V_28 * V_29 ,
unsigned int V_30 )
{
unsigned long V_31 ;
bool V_32 = true , V_33 = true , V_34 , V_35 , V_36 ;
bool V_37 , V_38 ;
V_31 = V_29 -> V_30 & V_30 ;
switch ( V_29 -> type ) {
case V_39 :
V_32 = V_31 & ( V_40 |
V_41 ) ;
V_33 = V_31 & ( V_42 |
V_43 ) ;
case V_44 :
V_34 = V_31 & ( V_45 |
V_46 ) ;
V_35 = V_31 & ( V_47 |
V_48 ) ;
V_36 = V_31 & ( V_49 | V_50 ) ;
return ( ! V_32 || ! V_33 || ! V_34 || ! V_35 || ! V_36 ) ?
0 : V_31 ;
case V_51 :
V_37 = V_31 & V_52 ;
V_38 = V_31 & ( V_53 |
V_54 ) ;
return ( ! V_37 || ! V_38 ) ? 0 : V_31 ;
}
return 0 ;
}
static int T_3 F_8 ( void )
{
return 0 ;
}
static void T_4 F_9 ( void )
{
}
