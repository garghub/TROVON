static int F_1 ( int V_1 , int V_2 )
{
const T_1 V_3 = F_2 () -> V_4 / 1000000 ;
union V_5 V_6 ;
union V_7 V_8 ;
union V_9 V_10 ;
V_10 . V_11 = F_3 ( F_4 ( V_2 , V_1 ) ) ;
V_10 . V_12 . V_13 = 0 ;
F_5 ( F_4 ( V_2 , V_1 ) , V_10 . V_11 ) ;
V_6 . V_11 =
F_3 ( F_6 ( V_2 , V_1 ) ) ;
V_8 . V_11 =
F_3 ( F_7 ( V_2 , V_1 ) ) ;
if ( V_6 . V_12 . V_14 ) {
V_8 . V_12 . V_15 =
( 10000ull * V_3 ) >> 10 ;
} else {
V_8 . V_12 . V_15 =
( 1600ull * V_3 ) >> 10 ;
}
F_5 ( F_7 ( V_2 , V_1 ) ,
V_8 . V_11 ) ;
if ( V_6 . V_12 . V_14 ) {
union V_16 V_17 ;
V_17 . V_11 =
F_3 ( F_8 ( V_2 , V_1 ) ) ;
V_17 . V_12 . V_18 = 0 ;
V_17 . V_12 . V_19 = 3 ;
V_17 . V_12 . V_20 = 1 ;
V_17 . V_12 . V_21 = 1 ;
F_5 ( F_8 ( V_2 , V_1 ) ,
V_17 . V_11 ) ;
} else {
union V_5 V_22 ;
V_22 . V_11 =
F_3 ( F_6 ( V_2 , V_1 ) ) ;
if ( V_22 . V_12 . V_23 ) {
union V_24 V_25 ;
V_25 . V_11 =
F_3 ( F_9
( V_2 , V_1 ) ) ;
V_25 . V_12 . V_26 = 1 ;
V_25 . V_12 . V_27 = 1 ;
V_25 . V_12 . V_28 = 2 ;
F_5 ( F_9
( V_2 , V_1 ) ,
V_25 . V_11 ) ;
} else {
}
}
return 0 ;
}
static int F_10 ( int V_1 , int V_2 )
{
union V_29 V_30 ;
V_30 . V_11 =
F_3 ( F_11 ( V_2 , V_1 ) ) ;
if ( F_2 () -> V_31 != V_32 ) {
V_30 . V_12 . V_33 = 1 ;
F_5 ( F_11 ( V_2 , V_1 ) ,
V_30 . V_11 ) ;
if ( F_12
( F_11 ( V_2 , V_1 ) ,
union V_29 , V_33 , == , 0 , 10000 ) ) {
F_13 ( L_1
L_2 ,
V_1 , V_2 ) ;
return - 1 ;
}
}
V_30 . V_12 . V_34 = 1 ;
V_30 . V_12 . V_35 = 1 ;
V_30 . V_12 . V_36 = 0 ;
F_5 ( F_11 ( V_2 , V_1 ) ,
V_30 . V_11 ) ;
if ( ( F_2 () -> V_31 != V_32 ) &&
F_12 ( F_14 ( V_2 , V_1 ) ,
union V_37 , V_38 , == , 1 ,
10000 ) ) {
return - 1 ;
}
return 0 ;
}
static int F_15 ( int V_1 ,
int V_2 ,
T_2
V_39 )
{
int V_40 ;
union V_9 V_10 ;
union V_5 V_22 ;
V_10 . V_11 = F_3 ( F_4 ( V_2 , V_1 ) ) ;
V_40 = V_10 . V_12 . V_13 ;
V_10 . V_12 . V_13 = 0 ;
F_5 ( F_4 ( V_2 , V_1 ) , V_10 . V_11 ) ;
if ( F_12
( F_4 ( V_2 , V_1 ) , union V_9 ,
V_41 , == , 1 , 10000 )
|| F_12 ( F_4 ( V_2 , V_1 ) ,
union V_9 , V_42 , == , 1 ,
10000 ) ) {
F_13
( L_3 ,
V_1 , V_2 ) ;
return - 1 ;
}
V_10 . V_11 = F_3 ( F_4 ( V_2 , V_1 ) ) ;
V_22 . V_11 =
F_3 ( F_6 ( V_2 , V_1 ) ) ;
V_22 . V_12 . V_43 = ! V_39 . V_12 . V_44 ;
if ( V_39 . V_12 . V_44 )
V_10 . V_12 . V_45 = V_39 . V_12 . V_46 ;
switch ( V_39 . V_12 . V_28 ) {
case 10 :
V_10 . V_12 . V_28 = 0 ;
V_10 . V_12 . V_47 = 1 ;
V_10 . V_12 . V_48 = 0 ;
V_22 . V_12 . V_49 = 25 ;
F_5 ( F_16 ( V_2 , V_1 ) , 64 ) ;
F_5 ( F_17 ( V_2 , V_1 ) , 0 ) ;
break;
case 100 :
V_10 . V_12 . V_28 = 0 ;
V_10 . V_12 . V_47 = 0 ;
V_10 . V_12 . V_48 = 0 ;
V_22 . V_12 . V_49 = 0x5 ;
F_5 ( F_16 ( V_2 , V_1 ) , 64 ) ;
F_5 ( F_17 ( V_2 , V_1 ) , 0 ) ;
break;
case 1000 :
V_10 . V_12 . V_28 = 1 ;
V_10 . V_12 . V_47 = 0 ;
V_10 . V_12 . V_48 = 1 ;
V_22 . V_12 . V_49 = 1 ;
F_5 ( F_16 ( V_2 , V_1 ) , 512 ) ;
F_5 ( F_17 ( V_2 , V_1 ) , 8192 ) ;
break;
default:
break;
}
F_5 ( F_6 ( V_2 , V_1 ) ,
V_22 . V_11 ) ;
F_5 ( F_4 ( V_2 , V_1 ) , V_10 . V_11 ) ;
V_10 . V_11 = F_3 ( F_4 ( V_2 , V_1 ) ) ;
V_10 . V_12 . V_13 = V_40 ;
F_5 ( F_4 ( V_2 , V_1 ) , V_10 . V_11 ) ;
return 0 ;
}
static int F_18 ( int V_1 , int V_50 )
{
int V_2 ;
F_19 ( V_1 , V_50 ) ;
for ( V_2 = 0 ; V_2 < V_50 ; V_2 ++ ) {
int V_51 = F_20 ( V_1 , V_2 ) ;
F_1 ( V_1 , V_2 ) ;
F_21 ( V_51 ,
F_22
( V_51 ) ) ;
}
return 0 ;
}
int F_23 ( int V_1 )
{
return 4 ;
}
int F_24 ( int V_1 )
{
union V_52 V_14 ;
V_14 . V_11 = F_3 ( F_25 ( V_1 ) ) ;
V_14 . V_12 . V_13 = 1 ;
F_5 ( F_25 ( V_1 ) , V_14 . V_11 ) ;
return F_23 ( V_1 ) ;
}
int F_26 ( int V_1 )
{
int V_50 = F_27 ( V_1 ) ;
int V_2 ;
F_18 ( V_1 , V_50 ) ;
for ( V_2 = 0 ; V_2 < V_50 ; V_2 ++ ) {
union V_9 V_10 ;
V_10 . V_11 =
F_3 ( F_4 ( V_2 , V_1 ) ) ;
V_10 . V_12 . V_13 = 1 ;
F_5 ( F_4 ( V_2 , V_1 ) ,
V_10 . V_11 ) ;
F_28 ( V_2 , V_1 ) ;
}
F_29 ( V_1 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
T_2 F_22 ( int V_51 )
{
T_2 V_53 ;
union V_5 V_6 ;
int V_1 = F_31 ( V_51 ) ;
int V_2 = F_32 ( V_51 ) ;
union V_29 V_54 ;
V_53 . V_11 = 0 ;
if ( F_2 () -> V_31 == V_32 ) {
V_53 . V_12 . V_44 = 1 ;
V_53 . V_12 . V_46 = 1 ;
V_53 . V_12 . V_28 = 1000 ;
return V_53 ;
}
V_54 . V_11 =
F_3 ( F_11 ( V_2 , V_1 ) ) ;
if ( V_54 . V_12 . V_55 ) {
V_53 . V_12 . V_44 = 1 ;
V_53 . V_12 . V_46 = 1 ;
V_53 . V_12 . V_28 = 1000 ;
return V_53 ;
}
V_6 . V_11 =
F_3 ( F_6 ( V_2 , V_1 ) ) ;
if ( V_6 . V_12 . V_14 ) {
} else {
union V_5 V_22 ;
V_22 . V_11 =
F_3 ( F_6 ( V_2 , V_1 ) ) ;
if ( V_22 . V_12 . V_23 ) {
union V_37 V_56 ;
union V_57 V_58 ;
V_56 . V_11 =
F_3 ( F_14
( V_2 , V_1 ) ) ;
if ( V_56 . V_12 . V_59 == 0 ) {
if ( F_10
( V_1 , V_2 ) != 0 )
return V_53 ;
}
V_58 . V_11 =
F_3 ( F_33
( V_2 , V_1 ) ) ;
if ( V_58 . V_12 . V_38 ) {
V_53 . V_12 . V_46 =
V_58 . V_12 . V_27 ;
V_53 . V_12 . V_44 =
V_58 . V_12 . V_60 ;
switch ( V_58 . V_12 . V_61 ) {
case 0 :
V_53 . V_12 . V_28 = 10 ;
break;
case 1 :
V_53 . V_12 . V_28 = 100 ;
break;
case 2 :
V_53 . V_12 . V_28 = 1000 ;
break;
default:
V_53 . V_12 . V_28 = 0 ;
V_53 . V_12 . V_44 = 0 ;
break;
}
} else {
V_53 . V_12 . V_28 = 0 ;
V_53 . V_12 . V_44 = 0 ;
}
} else {
V_53 = F_34 ( V_51 ) ;
}
}
return V_53 ;
}
int F_21 ( int V_51 ,
T_2 V_39 )
{
int V_1 = F_31 ( V_51 ) ;
int V_2 = F_32 ( V_51 ) ;
F_10 ( V_1 , V_2 ) ;
return F_15 ( V_1 , V_2 ,
V_39 ) ;
}
int F_35 ( int V_51 , int V_62 ,
int V_63 )
{
int V_1 = F_31 ( V_51 ) ;
int V_2 = F_32 ( V_51 ) ;
union V_29 V_54 ;
union V_5 V_22 ;
V_54 . V_11 =
F_3 ( F_11 ( V_2 , V_1 ) ) ;
V_54 . V_12 . V_55 = V_62 ;
F_5 ( F_11 ( V_2 , V_1 ) ,
V_54 . V_11 ) ;
V_22 . V_11 =
F_3 ( F_6 ( V_2 , V_1 ) ) ;
V_22 . V_12 . V_64 = V_63 ;
F_5 ( F_6 ( V_2 , V_1 ) ,
V_22 . V_11 ) ;
F_10 ( V_1 , V_2 ) ;
return 0 ;
}
