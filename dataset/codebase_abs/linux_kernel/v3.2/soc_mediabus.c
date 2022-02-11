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
switch ( V_2 -> V_5 ) {
case V_6 :
return V_13 * V_2 -> V_14 / 8 ;
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
const struct V_1 * F_3 (
enum V_15 V_16 ,
const struct V_17 * V_18 ,
int V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ )
if ( V_18 [ V_20 ] . V_16 == V_16 )
return & V_18 [ V_20 ] . V_21 ;
return NULL ;
}
const struct V_1 * F_4 (
enum V_15 V_16 )
{
return F_3 ( V_16 , V_22 , F_5 ( V_22 ) ) ;
}
unsigned int F_6 ( const struct V_23 * V_24 ,
unsigned int V_25 )
{
unsigned long V_26 ;
bool V_27 = true , V_28 = true , V_29 , V_30 , V_31 ;
bool V_32 , V_33 ;
V_26 = V_24 -> V_25 & V_25 ;
switch ( V_24 -> type ) {
case V_34 :
V_27 = V_26 & ( V_35 |
V_36 ) ;
V_28 = V_26 & ( V_37 |
V_38 ) ;
case V_39 :
V_29 = V_26 & ( V_40 |
V_41 ) ;
V_30 = V_26 & ( V_42 |
V_43 ) ;
V_31 = V_26 & ( V_44 | V_45 ) ;
return ( ! V_27 || ! V_28 || ! V_29 || ! V_30 || ! V_31 ) ?
0 : V_26 ;
case V_46 :
V_32 = V_26 & V_47 ;
V_33 = V_26 & ( V_48 |
V_49 ) ;
return ( ! V_32 || ! V_33 ) ? 0 : V_26 ;
}
return 0 ;
}
static int T_3 F_7 ( void )
{
return 0 ;
}
static void T_4 F_8 ( void )
{
}
