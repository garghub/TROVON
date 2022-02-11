int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_9 * V_10 = & V_4 -> V_8 . V_11 . V_12 ;
T_1 V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! ( V_10 -> V_16 & ( 1 << V_14 ) ) )
continue;
V_13 |= V_7 -> V_17 ( V_2 , V_18 [ V_14 ] ) << V_14 ;
}
return F_2 ( V_2 , V_13 ) ;
}
int
F_3 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_7 ;
struct V_9 * V_10 = & V_4 -> V_8 . V_11 . V_12 ;
int V_13 , V_14 ;
V_13 = F_4 ( V_2 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! ( V_10 -> V_16 & ( 1 << V_14 ) ) )
continue;
V_7 -> V_19 ( V_2 , V_18 [ V_14 ] , ! ! ( V_13 & ( 1 << V_14 ) ) ) ;
}
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_10 = & V_4 -> V_8 . V_11 . V_12 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_10 -> V_20 ; V_14 ++ ) {
if ( V_10 -> V_21 [ V_14 ] . V_12 == V_12 )
return V_10 -> V_21 [ V_14 ] . V_13 ;
}
return - V_22 ;
}
int
F_2 ( struct V_1 * V_2 , int V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_10 = & V_4 -> V_8 . V_11 . V_12 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_10 -> V_20 ; V_14 ++ ) {
if ( V_10 -> V_21 [ V_14 ] . V_13 == V_13 )
return V_10 -> V_21 [ V_14 ] . V_12 ;
}
return - V_22 ;
}
void
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_11 = & V_4 -> V_8 . V_11 ;
struct V_9 * V_12 = & V_11 -> V_12 ;
struct V_24 * V_25 = & V_4 -> V_26 ;
struct V_27 V_28 ;
T_1 * V_10 = NULL , * V_29 ;
int V_14 , V_30 , V_31 , V_32 , V_33 , V_34 ;
if ( V_25 -> type == V_35 ) {
if ( F_6 ( V_2 , 'P' , & V_28 ) )
return;
if ( V_28 . V_36 == 1 )
V_10 = F_7 ( V_25 , V_28 . V_37 [ 16 ] ) ;
else
if ( V_28 . V_36 == 2 )
V_10 = F_7 ( V_25 , V_28 . V_37 [ 12 ] ) ;
else {
F_8 ( V_2 , L_1 , V_28 . V_36 ) ;
}
} else {
if ( V_25 -> V_37 [ V_25 -> V_38 + 6 ] < 0x27 ) {
F_9 ( V_2 , L_2 ) ;
return;
}
V_10 = F_7 ( V_25 , V_25 -> V_37 [ V_25 -> V_38 + 0x98 ] ) ;
}
if ( ! V_10 ) {
F_9 ( V_2 , L_3 ) ;
return;
}
switch ( V_10 [ 0 ] ) {
case 0x10 :
case 0x11 :
case 0x12 :
V_30 = 5 ;
V_31 = V_10 [ 1 ] ;
V_32 = V_10 [ 2 ] ;
V_34 = 0 ;
V_33 = V_10 [ 4 ] ;
break;
case 0x20 :
V_30 = V_10 [ 1 ] ;
V_31 = V_10 [ 3 ] ;
V_32 = V_10 [ 2 ] ;
V_34 = 0 ;
V_33 = V_10 [ 5 ] ;
break;
case 0x30 :
V_30 = V_10 [ 1 ] ;
V_31 = V_10 [ 2 ] ;
V_32 = V_10 [ 3 ] ;
V_33 = V_10 [ 4 ] ;
V_34 = 2 ;
break;
case 0x40 :
V_30 = V_10 [ 1 ] ;
V_31 = V_10 [ 2 ] ;
V_32 = V_10 [ 3 ] ;
V_33 = V_10 [ 11 ] ;
V_34 = 0 ;
break;
default:
F_8 ( V_2 , L_4 , V_10 [ 0 ] ) ;
return;
}
V_12 -> V_16 = V_33 ;
if ( ! V_12 -> V_16 )
return;
V_14 = 0 ;
while ( V_33 ) {
if ( V_14 > V_15 ) {
F_9 ( V_2 , L_5 , V_14 ) ;
return;
}
if ( ! F_10 ( V_2 , V_18 [ V_14 ] ) ) {
F_9 ( V_2 , L_6 , V_14 ) ;
return;
}
V_33 >>= 1 ;
V_14 ++ ;
}
V_12 -> V_36 = V_10 [ 0 ] ;
if ( V_12 -> V_36 < 0x40 ) {
V_12 -> V_20 = V_32 ;
V_12 -> V_21 =
F_11 ( V_32 , sizeof( * V_12 -> V_21 ) , V_39 ) ;
if ( ! V_12 -> V_21 )
return;
V_29 = V_10 + V_30 ;
for ( V_14 = 0 ; V_14 < V_32 ; V_14 ++ , V_29 += V_31 ) {
V_12 -> V_21 [ V_14 ] . V_12 = V_29 [ 0 ] * 10000 ;
V_12 -> V_21 [ V_14 ] . V_13 = V_29 [ 1 ] >> V_34 ;
}
} else {
T_2 V_40 = F_12 ( V_10 [ 4 ] ) ;
T_3 V_41 = F_13 ( V_10 [ 8 ] ) ;
T_1 V_13 ;
V_12 -> V_20 = V_12 -> V_16 + 1 ;
V_12 -> V_21 = F_11 ( V_12 -> V_20 ,
sizeof( * V_12 -> V_21 ) , V_39 ) ;
if ( ! V_12 -> V_21 )
return;
for ( V_13 = 0 ; V_13 <= V_12 -> V_16 ; V_13 ++ ) {
V_12 -> V_21 [ V_13 ] . V_12 = V_40 ;
V_12 -> V_21 [ V_13 ] . V_13 = V_13 ;
V_40 += V_41 ;
}
}
V_12 -> V_42 = true ;
}
void
F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_10 = & V_4 -> V_8 . V_11 . V_12 ;
F_15 ( V_10 -> V_21 ) ;
}
