static int F_1 ( enum V_1 type , int V_2 )
{
if ( type == V_3 )
return V_4 ;
if ( type == V_5 )
return V_6 + V_2 ;
return - V_7 ;
}
static int
F_2 ( struct V_8 * V_9 , enum V_1 type , T_1 V_10 ,
int V_2 , long * V_11 )
{
static const struct {
enum V_1 type ;
T_1 V_10 ;
long V_11 ;
} V_12 [] = {
{ V_3 , V_13 , V_14 } ,
{ V_3 , V_15 , V_16 } ,
{ V_5 , V_17 , V_18 } ,
} ;
struct V_19 * V_20 = F_3 ( V_9 ) ;
enum V_21 V_22 ;
int V_23 , V_24 ;
for ( V_24 = 0 ; V_24 < F_4 ( V_12 ) ; V_24 ++ )
if ( V_12 [ V_24 ] . type == type && V_12 [ V_24 ] . V_10 == V_10 ) {
* V_11 = V_12 [ V_24 ] . V_11 ;
return 0 ;
}
V_23 = F_1 ( type , V_2 ) ;
if ( V_23 < 0 )
return V_23 ;
V_22 = V_23 ;
if ( ! ( V_20 -> V_25 -> V_26 & F_5 ( V_22 ) ) )
return - V_27 ;
if ( type == V_3 && V_10 == V_28 )
return F_6 ( V_20 -> V_29 , V_22 , V_11 ) ;
if ( type == V_5 && V_10 == V_30 )
return F_6 ( V_20 -> V_29 , V_22 , V_11 ) ;
return - V_7 ;
}
static T_2
F_7 ( const void * V_31 , enum V_1 type , T_1 V_10 ,
int V_2 )
{
if ( type == V_3 ) {
switch ( V_10 ) {
case V_28 :
case V_15 :
case V_13 :
return 0444 ;
}
} else if ( type == V_5 ) {
switch ( V_10 ) {
case V_30 :
case V_17 :
return 0444 ;
}
}
return 0 ;
}
int F_8 ( struct V_19 * V_20 )
{
if ( ! F_9 ( V_32 ) )
return 0 ;
if ( ! V_20 -> V_25 ) {
F_10 ( V_20 -> V_29 , L_1 ) ;
return 0 ;
}
if ( ! V_20 -> V_25 -> V_26 ) {
F_11 ( V_20 -> V_29 ,
L_2 ) ;
return 0 ;
}
V_20 -> V_33 = F_12 ( & V_20 -> V_34 -> V_9 , L_3 ,
V_20 , & V_35 ,
NULL ) ;
return F_13 ( V_20 -> V_33 ) ;
}
void F_14 ( struct V_19 * V_20 )
{
if ( ! F_9 ( V_32 ) || ! V_20 -> V_33 )
return;
F_15 ( V_20 -> V_33 ) ;
}
