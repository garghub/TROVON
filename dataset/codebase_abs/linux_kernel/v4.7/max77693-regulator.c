static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = V_2 -> V_6 -> V_7 ;
unsigned int V_8 = V_2 -> V_6 -> V_9 ;
unsigned int V_10 , V_11 ;
unsigned int V_12 ;
int V_13 ;
V_13 = F_3 ( V_2 -> V_14 , V_4 -> V_15 , & V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = V_10 & V_4 -> V_16 ;
if ( V_11 <= V_4 -> V_17 )
V_11 = 0 ;
else
V_11 -= V_4 -> V_17 ;
V_12 = V_5 + V_4 -> V_18 * V_11 ;
if ( V_12 > V_8 )
return - V_19 ;
return V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_7 , int V_9 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = V_2 -> V_6 -> V_7 ;
int V_11 = 0 ;
while ( V_5 + V_4 -> V_18 * V_11 < V_7 )
V_11 ++ ;
if ( V_5 + V_4 -> V_18 * V_11 > V_9 )
return - V_19 ;
V_11 += V_4 -> V_17 ;
return F_5 ( V_2 -> V_14 , V_4 -> V_15 , V_11 ) ;
}
static struct V_14 * F_6 ( enum V_20 type ,
struct V_21 * V_22 ,
int V_23 )
{
if ( type == V_24 )
return V_22 -> V_14 ;
switch ( V_23 ) {
case V_25 :
case V_26 :
return V_22 -> V_14 ;
case V_27 :
return V_22 -> V_28 ;
default:
return V_22 -> V_14 ;
}
}
static int F_7 ( struct V_29 * V_30 )
{
enum V_20 type = F_8 ( V_30 ) -> V_31 ;
struct V_21 * V_32 = F_9 ( V_30 -> V_33 . V_34 ) ;
const struct V_35 * V_36 ;
unsigned int V_37 ;
int V_38 ;
struct V_39 V_40 = { } ;
V_40 . V_33 = V_32 -> V_33 ;
switch ( type ) {
case V_24 :
V_36 = V_41 ;
V_37 = F_10 ( V_41 ) ;
V_40 . V_31 = ( void * ) & V_42 ;
break;
case V_43 :
V_36 = V_44 ;
V_37 = F_10 ( V_44 ) ;
V_40 . V_31 = ( void * ) & V_45 ;
break;
default:
F_11 ( & V_30 -> V_33 , L_1 , type ) ;
return - V_46 ;
}
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
struct V_1 * V_2 ;
V_40 . V_14 = F_6 ( type , V_32 ,
V_36 [ V_38 ] . V_47 ) ;
V_2 = F_12 ( & V_30 -> V_33 ,
& V_36 [ V_38 ] , & V_40 ) ;
if ( F_13 ( V_2 ) ) {
F_11 ( & V_30 -> V_33 ,
L_2 , V_38 ) ;
return F_14 ( V_2 ) ;
}
}
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_48 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_48 ) ;
}
