static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
T_2 V_4 ;
unsigned long V_5 = 0 ;
V_4 = F_2 ( V_3 -> V_6 ) ;
if ( ! V_4 )
return V_7 ;
if ( V_4 & ( 1 << V_8 ) ) {
F_3 ( & V_3 -> V_9 [ V_8 ] ) ;
F_4 ( V_3 ) ;
}
if ( V_4 & ( 1 << V_10 ) ) {
F_3 ( & V_3 -> V_9 [ V_10 ] ) ;
F_5 ( V_3 ) ;
}
if ( V_4 & ( 1 << V_11 ) ) {
V_5 += F_6 ( V_3 , - 1 ) ;
V_5 += F_7 ( V_3 , - 1 ) ;
V_5 += F_8 ( V_3 , - 1 ) ;
F_9 ( & V_3 -> V_9 [ V_11 ] ,
V_5 ,
1 ,
1 ) ;
}
return V_12 ;
}
static T_1 F_10 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_5 = 0 ;
V_5 += F_6 ( V_3 , - 1 ) ;
V_5 += F_7 ( V_3 , - 1 ) ;
V_5 += F_8 ( V_3 , - 1 ) ;
F_9 ( & V_3 -> V_9 [ 0 ] ,
V_5 ,
1 ,
1 ) ;
return V_12 ;
}
static T_1 F_11 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_13 = 0 ;
V_13 = F_8 ( V_3 , - 1 ) ;
F_9 ( & V_3 -> V_9 [ V_14 ] ,
V_13 ,
1 ,
1 ) ;
return V_12 ;
}
static T_1 F_12 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_15 = 0 ;
V_15 = F_7 ( V_3 , - 1 ) ;
F_9 ( & V_3 -> V_9 [ V_16 ] ,
V_15 ,
1 ,
1 ) ;
return V_12 ;
}
static T_1 F_13 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_17 = 0 ;
V_17 = F_6 ( V_3 , - 1 ) ;
F_9 ( & V_3 -> V_9 [ V_18 ] ,
V_17 ,
1 ,
1 ) ;
return V_12 ;
}
static T_1 F_14 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
F_3 ( & V_3 -> V_9 [ V_19 ] ) ;
F_5 ( V_3 ) ;
F_4 ( V_3 ) ;
return V_12 ;
}
void F_15 ( struct V_3 * V_3 )
{
int V_20 ;
switch ( F_16 ( V_3 -> V_21 ) ) {
case V_22 :
case V_23 :
F_17 ( V_3 -> V_24 -> V_1 , V_3 ) ;
break;
case V_25 :
for ( V_20 = 0 ; V_20 < F_18 ( V_3 -> V_26 ) ; V_20 ++ )
if ( V_3 -> V_26 [ V_20 ] . V_27 )
F_17 ( V_3 -> V_28 [ V_20 ] . V_29 ,
V_3 -> V_26 [ V_20 ] . V_30 ) ;
break;
default:
break;
}
}
int F_19 ( struct V_3 * V_3 )
{
int V_31 = 0 ;
int V_20 ;
switch ( F_16 ( V_3 -> V_21 ) ) {
case V_22 :
V_31 = F_20 ( V_3 -> V_24 -> V_1 , & F_1 ,
V_32 , V_33 , V_3 ) ;
break;
case V_23 :
V_31 = F_20 ( V_3 -> V_24 -> V_1 , & F_10 ,
0 , V_3 -> V_34 , V_3 ) ;
break;
case V_25 :
sprintf ( V_3 -> V_26 [ V_14 ] . V_35 ,
L_1 , V_3 -> V_34 ) ;
V_3 -> V_26 [ V_14 ] . V_36 = F_11 ;
V_3 -> V_26 [ V_14 ] . V_30 = V_3 ;
sprintf ( V_3 -> V_26 [ V_16 ] . V_35 ,
L_2 , V_3 -> V_34 ) ;
V_3 -> V_26 [ V_16 ] . V_36 = F_12 ;
V_3 -> V_26 [ V_16 ] . V_30 = V_3 ;
sprintf ( V_3 -> V_26 [ V_18 ] . V_35 ,
L_3 , V_3 -> V_34 ) ;
V_3 -> V_26 [ V_18 ] . V_36 = F_13 ;
V_3 -> V_26 [ V_18 ] . V_30 = V_3 ;
sprintf ( V_3 -> V_26 [ V_19 ] . V_35 ,
L_4 , V_3 -> V_34 ) ;
V_3 -> V_26 [ V_19 ] . V_36 =
F_14 ;
V_3 -> V_26 [ V_19 ] . V_30 = V_3 ;
for ( V_20 = 0 ; V_20 < F_18 ( V_3 -> V_26 ) ; V_20 ++ ) {
V_31 = F_20 ( V_3 -> V_28 [ V_20 ] . V_29 ,
V_3 -> V_26 [ V_20 ] . V_36 , 0 ,
V_3 -> V_26 [ V_20 ] . V_35 ,
V_3 -> V_26 [ V_20 ] . V_30 ) ;
if ( V_31 ) {
F_21 ( V_37 , V_3 -> V_38 -> V_39 ,
L_5
L_6 , V_31 ) ;
F_15 ( V_3 ) ;
break;
}
V_3 -> V_26 [ V_20 ] . V_27 = 1 ;
}
break;
default:
break;
}
return V_31 ;
}
int F_22 ( struct V_3 * V_3 )
{
unsigned int V_40 = F_18 ( V_3 -> V_41 ) ;
unsigned int V_42 = F_18 ( V_3 -> V_43 ) ;
unsigned int V_44 = F_18 ( V_3 -> V_45 ) ;
unsigned int V_20 ;
F_23 ( F_18 ( V_3 -> V_28 ) < V_40 + V_42 + V_44 + 1 ) ;
for ( V_20 = 0 ; V_20 < V_40 + V_42 + V_44 + 1 ; V_20 ++ )
V_3 -> V_28 [ V_20 ] . V_46 = V_20 ;
if ( V_3 -> V_47 >= V_40 &&
V_3 -> V_48 >= V_42 &&
V_3 -> V_49 >= V_44 &&
V_3 -> V_50 >= V_40 + V_42 + V_44 ) {
if ( ! F_24 ( V_3 -> V_24 , V_3 -> V_28 ,
V_40 + V_42 + V_44 + 1 ) ) {
V_3 -> V_47 = V_40 ;
V_3 -> V_48 = V_42 ;
V_3 -> V_49 = V_44 ;
V_3 -> V_51 = V_42 + V_44 ;
V_3 -> V_50 = V_40 + V_42 + V_44 ;
V_3 -> V_52 = V_40 + V_42 + V_44 + 1 ;
V_3 -> V_53 = V_19 ;
F_25 ( V_54 , V_3 -> V_38 -> V_39 ,
L_7 ) ;
F_26 ( V_3 -> V_21 ,
V_25 ) ;
return 0 ;
}
}
if ( V_3 -> V_47 >= 1 &&
V_3 -> V_48 >= 1 &&
V_3 -> V_49 >= 1 &&
V_3 -> V_50 >= 3 &&
V_3 -> V_52 >= 1 &&
! F_27 ( V_3 -> V_24 ) ) {
V_3 -> V_47 = 1 ;
V_3 -> V_48 = 1 ;
V_3 -> V_49 = 1 ;
V_3 -> V_51 = 2 ;
V_3 -> V_50 = 3 ;
V_3 -> V_52 = 1 ;
V_3 -> V_53 = 0 ;
F_25 ( V_54 , V_3 -> V_38 -> V_39 ,
L_8 ) ;
F_26 ( V_3 -> V_21 , V_23 ) ;
return 0 ;
}
if ( V_3 -> V_47 >= 1 &&
V_3 -> V_48 >= 1 &&
V_3 -> V_49 >= 1 &&
V_3 -> V_50 >= 3 &&
V_3 -> V_52 >= 3 ) {
V_3 -> V_47 = 1 ;
V_3 -> V_48 = 1 ;
V_3 -> V_49 = 1 ;
V_3 -> V_50 = 3 ;
V_3 -> V_52 = 3 ;
F_25 ( V_54 , V_3 -> V_38 -> V_39 ,
L_9 ) ;
F_26 ( V_3 -> V_21 , V_22 ) ;
return 0 ;
}
F_26 ( V_3 -> V_21 , V_55 ) ;
return - V_56 ;
}
void F_28 ( struct V_3 * V_3 )
{
switch ( F_16 ( V_3 -> V_21 ) ) {
case V_25 :
F_29 ( V_3 -> V_24 ) ;
break;
case V_23 :
F_30 ( V_3 -> V_24 ) ;
break;
default:
break;
}
F_26 ( V_3 -> V_21 , V_22 ) ;
}
