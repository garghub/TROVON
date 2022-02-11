static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
T_2 V_4 ;
unsigned long V_5 = 0 ;
V_4 = F_2 ( V_3 -> V_6 ) ;
if ( ! V_4 )
return V_7 ;
V_3 -> V_8 . V_9 . V_10 = V_11 ;
F_3 ( & V_3 -> V_8 . V_9 . V_12 ) ;
if ( V_4 & ( 1 << V_13 ) ) {
F_4 ( & V_3 -> V_14 [ V_13 ] ) ;
F_5 ( V_3 ) ;
}
if ( V_4 & ( 1 << V_15 ) ) {
F_4 ( & V_3 -> V_14 [ V_15 ] ) ;
F_6 ( V_3 ) ;
}
if ( V_4 & ( 1 << V_16 ) ) {
V_5 += F_7 ( V_3 , - 1 ) ;
V_5 += F_8 ( V_3 , - 1 ) ;
V_5 += F_9 ( V_3 , - 1 ) ;
F_10 ( & V_3 -> V_14 [ V_16 ] ,
V_5 ,
1 ,
1 ) ;
}
return V_17 ;
}
static T_1 F_11 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_5 = 0 ;
V_3 -> V_8 . V_9 . V_10 = V_11 ;
F_3 ( & V_3 -> V_8 . V_9 . V_12 ) ;
V_5 += F_7 ( V_3 , - 1 ) ;
V_5 += F_8 ( V_3 , - 1 ) ;
V_5 += F_9 ( V_3 , - 1 ) ;
F_10 ( & V_3 -> V_14 [ 0 ] ,
V_5 ,
1 ,
1 ) ;
return V_17 ;
}
static T_1 F_12 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_18 = 0 ;
V_3 -> V_8 . V_9 . V_10 = V_11 ;
F_3 ( & V_3 -> V_8 . V_9 . V_12 ) ;
V_18 = F_9 ( V_3 , - 1 ) ;
F_10 ( & V_3 -> V_14 [ V_19 ] ,
V_18 ,
1 ,
1 ) ;
return V_17 ;
}
static T_1 F_13 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_20 = 0 ;
V_3 -> V_8 . V_9 . V_10 = V_11 ;
F_3 ( & V_3 -> V_8 . V_9 . V_12 ) ;
V_20 = F_8 ( V_3 , - 1 ) ;
F_10 ( & V_3 -> V_14 [ V_21 ] ,
V_20 ,
1 ,
1 ) ;
return V_17 ;
}
static T_1 F_14 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned long V_22 = 0 ;
V_3 -> V_8 . V_9 . V_10 = V_11 ;
F_3 ( & V_3 -> V_8 . V_9 . V_12 ) ;
V_22 = F_7 ( V_3 , - 1 ) ;
F_10 ( & V_3 -> V_14 [ V_23 ] ,
V_22 ,
1 ,
1 ) ;
return V_17 ;
}
static T_1 F_15 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
V_3 -> V_8 . V_9 . V_10 = V_11 ;
F_3 ( & V_3 -> V_8 . V_9 . V_12 ) ;
F_4 ( & V_3 -> V_14 [ V_24 ] ) ;
F_6 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_17 ;
}
void F_16 ( struct V_3 * V_3 )
{
int V_25 ;
switch ( F_17 ( V_3 -> V_26 ) ) {
case V_27 :
case V_28 :
F_18 ( V_3 -> V_29 -> V_1 , V_3 ) ;
break;
case V_30 :
for ( V_25 = 0 ; V_25 < F_19 ( V_3 -> V_31 ) ; V_25 ++ )
if ( V_3 -> V_31 [ V_25 ] . V_32 )
F_18 ( V_3 -> V_33 [ V_25 ] . V_34 ,
V_3 -> V_31 [ V_25 ] . V_35 ) ;
break;
default:
break;
}
}
int F_20 ( struct V_3 * V_3 )
{
int V_36 = 0 ;
int V_25 ;
switch ( F_17 ( V_3 -> V_26 ) ) {
case V_27 :
V_36 = F_21 ( V_3 -> V_29 -> V_1 , & F_1 ,
V_37 , V_38 , V_3 ) ;
break;
case V_28 :
V_36 = F_21 ( V_3 -> V_29 -> V_1 , & F_11 ,
0 , V_3 -> V_39 , V_3 ) ;
break;
case V_30 :
sprintf ( V_3 -> V_31 [ V_19 ] . V_40 ,
L_1 , V_3 -> V_39 ) ;
V_3 -> V_31 [ V_19 ] . V_41 = F_12 ;
V_3 -> V_31 [ V_19 ] . V_35 = V_3 ;
sprintf ( V_3 -> V_31 [ V_21 ] . V_40 ,
L_2 , V_3 -> V_39 ) ;
V_3 -> V_31 [ V_21 ] . V_41 = F_13 ;
V_3 -> V_31 [ V_21 ] . V_35 = V_3 ;
sprintf ( V_3 -> V_31 [ V_23 ] . V_40 ,
L_3 , V_3 -> V_39 ) ;
V_3 -> V_31 [ V_23 ] . V_41 = F_14 ;
V_3 -> V_31 [ V_23 ] . V_35 = V_3 ;
sprintf ( V_3 -> V_31 [ V_24 ] . V_40 ,
L_4 , V_3 -> V_39 ) ;
V_3 -> V_31 [ V_24 ] . V_41 =
F_15 ;
V_3 -> V_31 [ V_24 ] . V_35 = V_3 ;
for ( V_25 = 0 ; V_25 < F_19 ( V_3 -> V_31 ) ; V_25 ++ ) {
V_36 = F_21 ( V_3 -> V_33 [ V_25 ] . V_34 ,
V_3 -> V_31 [ V_25 ] . V_41 , 0 ,
V_3 -> V_31 [ V_25 ] . V_40 ,
V_3 -> V_31 [ V_25 ] . V_35 ) ;
if ( V_36 ) {
F_22 ( V_42 , V_3 -> V_43 -> V_44 ,
L_5
L_6 , V_36 ) ;
F_16 ( V_3 ) ;
break;
}
V_3 -> V_31 [ V_25 ] . V_32 = 1 ;
}
break;
default:
break;
}
return V_36 ;
}
int F_23 ( struct V_3 * V_3 )
{
unsigned int V_45 = F_19 ( V_3 -> V_46 ) ;
unsigned int V_47 = F_19 ( V_3 -> V_48 ) ;
unsigned int V_49 = F_19 ( V_3 -> V_50 ) ;
unsigned int V_25 ;
F_24 ( F_19 ( V_3 -> V_33 ) < V_45 + V_47 + V_49 + 1 ) ;
for ( V_25 = 0 ; V_25 < V_45 + V_47 + V_49 + 1 ; V_25 ++ )
V_3 -> V_33 [ V_25 ] . V_51 = V_25 ;
if ( V_3 -> V_52 >= V_45 &&
V_3 -> V_53 >= V_47 &&
V_3 -> V_54 >= V_49 &&
V_3 -> V_55 >= V_45 + V_47 + V_49 ) {
if ( ! F_25 ( V_3 -> V_29 , V_3 -> V_33 ,
V_45 + V_47 + V_49 + 1 ) ) {
V_3 -> V_52 = V_45 ;
V_3 -> V_53 = V_47 ;
V_3 -> V_54 = V_49 ;
V_3 -> V_56 = V_47 + V_49 ;
V_3 -> V_55 = V_45 + V_47 + V_49 ;
V_3 -> V_57 = V_45 + V_47 + V_49 + 1 ;
V_3 -> V_58 = V_24 ;
F_26 ( V_59 , V_3 -> V_43 -> V_44 ,
L_7 ) ;
F_27 ( V_3 -> V_26 ,
V_30 ) ;
return 0 ;
}
}
if ( V_3 -> V_52 >= 1 &&
V_3 -> V_53 >= 1 &&
V_3 -> V_54 >= 1 &&
V_3 -> V_55 >= 3 &&
V_3 -> V_57 >= 1 &&
! F_28 ( V_3 -> V_29 ) ) {
V_3 -> V_52 = 1 ;
V_3 -> V_53 = 1 ;
V_3 -> V_54 = 1 ;
V_3 -> V_56 = 2 ;
V_3 -> V_55 = 3 ;
V_3 -> V_57 = 1 ;
V_3 -> V_58 = 0 ;
F_26 ( V_59 , V_3 -> V_43 -> V_44 ,
L_8 ) ;
F_27 ( V_3 -> V_26 , V_28 ) ;
return 0 ;
}
if ( V_3 -> V_52 >= 1 &&
V_3 -> V_53 >= 1 &&
V_3 -> V_54 >= 1 &&
V_3 -> V_55 >= 3 &&
V_3 -> V_57 >= 3 ) {
V_3 -> V_52 = 1 ;
V_3 -> V_53 = 1 ;
V_3 -> V_54 = 1 ;
V_3 -> V_55 = 3 ;
V_3 -> V_57 = 3 ;
F_26 ( V_59 , V_3 -> V_43 -> V_44 ,
L_9 ) ;
F_27 ( V_3 -> V_26 , V_27 ) ;
return 0 ;
}
F_27 ( V_3 -> V_26 , V_60 ) ;
return - V_61 ;
}
void F_29 ( struct V_3 * V_3 )
{
switch ( F_17 ( V_3 -> V_26 ) ) {
case V_30 :
F_30 ( V_3 -> V_29 ) ;
break;
case V_28 :
F_31 ( V_3 -> V_29 ) ;
break;
default:
break;
}
F_27 ( V_3 -> V_26 , V_27 ) ;
}
