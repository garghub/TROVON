int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_10 ;
T_1 V_11 = 0 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
if ( ! ( V_7 -> V_14 & ( 1 << V_12 ) ) )
continue;
V_11 |= F_2 ( V_2 , V_15 [ V_12 ] ) << V_12 ;
}
return F_3 ( V_2 , V_11 ) ;
}
int
F_4 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_10 ;
int V_11 , V_12 ;
V_11 = F_5 ( V_2 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
if ( ! ( V_7 -> V_14 & ( 1 << V_12 ) ) )
continue;
F_6 ( V_2 , V_15 [ V_12 ] , ! ! ( V_11 & ( 1 << V_12 ) ) ) ;
}
return 0 ;
}
int
F_5 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_10 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_16 ; V_12 ++ ) {
if ( V_7 -> V_17 [ V_12 ] . V_10 == V_10 )
return V_7 -> V_17 [ V_12 ] . V_11 ;
}
return - V_18 ;
}
int
F_3 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_10 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_7 -> V_16 ; V_12 ++ ) {
if ( V_7 -> V_17 [ V_12 ] . V_11 == V_11 )
return V_7 -> V_17 [ V_12 ] . V_10 ;
}
return - V_18 ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_9 = & V_4 -> V_8 . V_9 ;
struct V_6 * V_10 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_4 -> V_22 ;
struct V_23 V_24 ;
T_1 * V_7 = NULL , * V_25 ;
int V_12 , V_26 , V_27 , V_28 , V_29 , V_30 ;
if ( V_21 -> type == V_31 ) {
if ( F_8 ( V_2 , 'P' , & V_24 ) )
return;
if ( V_24 . V_32 == 1 )
V_7 = F_9 ( V_2 , V_24 . V_33 [ 16 ] ) ;
else
if ( V_24 . V_32 == 2 )
V_7 = F_9 ( V_2 , V_24 . V_33 [ 12 ] ) ;
else {
F_10 ( V_2 , L_1 , V_24 . V_32 ) ;
}
} else {
if ( V_21 -> V_33 [ V_21 -> V_34 + 6 ] < 0x27 ) {
F_11 ( V_2 , L_2 ) ;
return;
}
V_7 = F_9 ( V_2 , V_21 -> V_33 [ V_21 -> V_34 + 0x98 ] ) ;
}
if ( ! V_7 ) {
F_11 ( V_2 , L_3 ) ;
return;
}
switch ( V_7 [ 0 ] ) {
case 0x10 :
case 0x11 :
case 0x12 :
V_26 = 5 ;
V_27 = V_7 [ 1 ] ;
V_28 = V_7 [ 2 ] ;
V_30 = 0 ;
V_29 = V_7 [ 4 ] ;
break;
case 0x20 :
V_26 = V_7 [ 1 ] ;
V_27 = V_7 [ 3 ] ;
V_28 = V_7 [ 2 ] ;
V_30 = 0 ;
V_29 = V_7 [ 5 ] ;
break;
case 0x30 :
V_26 = V_7 [ 1 ] ;
V_27 = V_7 [ 2 ] ;
V_28 = V_7 [ 3 ] ;
V_29 = V_7 [ 4 ] ;
V_30 = 2 ;
break;
case 0x40 :
V_26 = V_7 [ 1 ] ;
V_27 = V_7 [ 2 ] ;
V_28 = V_7 [ 3 ] ;
V_29 = V_7 [ 11 ] ;
V_30 = 0 ;
break;
default:
F_10 ( V_2 , L_4 , V_7 [ 0 ] ) ;
return;
}
V_10 -> V_14 = V_29 ;
if ( ! V_10 -> V_14 )
return;
V_12 = 0 ;
while ( V_29 ) {
if ( V_12 > V_13 ) {
F_11 ( V_2 , L_5 , V_12 ) ;
return;
}
if ( ! F_12 ( V_2 , V_15 [ V_12 ] ) ) {
F_11 ( V_2 , L_6 , V_12 ) ;
return;
}
V_29 >>= 1 ;
V_12 ++ ;
}
V_10 -> V_32 = V_7 [ 0 ] ;
if ( V_10 -> V_32 < 0x40 ) {
V_10 -> V_16 = V_28 ;
V_10 -> V_17 =
F_13 ( V_28 , sizeof( * V_10 -> V_17 ) , V_35 ) ;
if ( ! V_10 -> V_17 )
return;
V_25 = V_7 + V_26 ;
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ , V_25 += V_27 ) {
V_10 -> V_17 [ V_12 ] . V_10 = V_25 [ 0 ] * 10000 ;
V_10 -> V_17 [ V_12 ] . V_11 = V_25 [ 1 ] >> V_30 ;
}
} else {
T_2 V_36 = F_14 ( V_7 [ 4 ] ) ;
T_3 V_37 = F_15 ( V_7 [ 8 ] ) ;
T_1 V_11 ;
V_10 -> V_16 = V_10 -> V_14 + 1 ;
V_10 -> V_17 = F_13 ( V_10 -> V_16 ,
sizeof( * V_10 -> V_17 ) , V_35 ) ;
if ( ! V_10 -> V_17 )
return;
for ( V_11 = 0 ; V_11 <= V_10 -> V_14 ; V_11 ++ ) {
V_10 -> V_17 [ V_11 ] . V_10 = V_36 ;
V_10 -> V_17 [ V_11 ] . V_11 = V_11 ;
V_36 += V_37 ;
}
}
V_10 -> V_38 = true ;
}
void
F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_10 ;
F_17 ( V_7 -> V_17 ) ;
}
