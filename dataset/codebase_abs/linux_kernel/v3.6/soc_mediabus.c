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
case V_9 :
* V_3 = 2 ;
* V_4 = 1 ;
return 0 ;
case V_10 :
* V_3 = 3 ;
* V_4 = 2 ;
return 0 ;
case V_11 :
* V_3 = 0 ;
* V_4 = 1 ;
return 0 ;
}
return - V_12 ;
}
T_1 F_2 ( T_2 V_13 , const struct V_1 * V_2 )
{
if ( V_2 -> V_14 == V_15 )
return 0 ;
if ( V_2 -> V_16 != V_17 )
return V_13 * V_2 -> V_18 / 8 ;
switch ( V_2 -> V_5 ) {
case V_6 :
return V_13 * V_2 -> V_18 / 8 ;
case V_8 :
case V_9 :
case V_7 :
return V_13 * 2 ;
case V_10 :
return V_13 * 3 / 2 ;
case V_11 :
return 0 ;
}
return - V_12 ;
}
T_1 F_3 ( const struct V_1 * V_2 ,
T_2 V_19 , T_2 V_20 )
{
if ( V_2 -> V_14 == V_15 )
return 0 ;
if ( V_2 -> V_16 == V_17 )
return V_19 * V_20 ;
switch ( V_2 -> V_5 ) {
case V_8 :
case V_9 :
return V_19 * V_20 * 2 ;
case V_10 :
return V_19 * V_20 * 3 / 2 ;
default:
return - V_12 ;
}
}
const struct V_1 * F_4 (
enum V_21 V_22 ,
const struct V_23 * V_24 ,
int V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ )
if ( V_24 [ V_26 ] . V_22 == V_22 )
return & V_24 [ V_26 ] . V_27 ;
return NULL ;
}
const struct V_1 * F_5 (
enum V_21 V_22 )
{
return F_4 ( V_22 , V_28 , F_6 ( V_28 ) ) ;
}
unsigned int F_7 ( const struct V_29 * V_30 ,
unsigned int V_31 )
{
unsigned long V_32 ;
bool V_33 = true , V_34 = true , V_35 , V_36 , V_37 ;
bool V_38 , V_39 ;
V_32 = V_30 -> V_31 & V_31 ;
switch ( V_30 -> type ) {
case V_40 :
V_33 = V_32 & ( V_41 |
V_42 ) ;
V_34 = V_32 & ( V_43 |
V_44 ) ;
case V_45 :
V_35 = V_32 & ( V_46 |
V_47 ) ;
V_36 = V_32 & ( V_48 |
V_49 ) ;
V_37 = V_32 & ( V_50 | V_51 ) ;
return ( ! V_33 || ! V_34 || ! V_35 || ! V_36 || ! V_37 ) ?
0 : V_32 ;
case V_52 :
V_38 = V_32 & V_53 ;
V_39 = V_32 & ( V_54 |
V_55 ) ;
return ( ! V_38 || ! V_39 ) ? 0 : V_32 ;
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
