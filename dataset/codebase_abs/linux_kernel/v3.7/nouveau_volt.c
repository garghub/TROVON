int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
T_1 V_10 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( ! ( V_4 -> V_13 & ( 1 << V_11 ) ) )
continue;
V_10 |= V_9 -> V_14 ( V_9 , 0 , V_15 [ V_11 ] , 0xff ) << V_11 ;
}
return F_4 ( V_2 , V_10 ) ;
}
int
F_5 ( struct V_1 * V_2 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_3 * V_4 = & F_2 ( V_2 ) -> V_5 ;
int V_10 , V_11 ;
V_10 = F_6 ( V_2 , V_5 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( ! ( V_4 -> V_13 & ( 1 << V_11 ) ) )
continue;
V_9 -> V_16 ( V_9 , 0 , V_15 [ V_11 ] , 0xff , ! ! ( V_10 & ( 1 << V_11 ) ) ) ;
}
return 0 ;
}
int
F_6 ( struct V_1 * V_2 , int V_5 )
{
struct V_3 * V_4 = & F_2 ( V_2 ) -> V_5 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_17 ; V_11 ++ ) {
if ( V_4 -> V_18 [ V_11 ] . V_5 == V_5 )
return V_4 -> V_18 [ V_11 ] . V_10 ;
}
return - V_19 ;
}
int
F_4 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_4 = & F_2 ( V_2 ) -> V_5 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_17 ; V_11 ++ ) {
if ( V_4 -> V_18 [ V_11 ] . V_10 == V_10 )
return V_4 -> V_18 [ V_11 ] . V_5 ;
}
return - V_19 ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_20 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_21 -> V_7 ) ;
struct F_2 * V_22 = F_2 ( V_2 ) ;
struct V_3 * V_5 = & V_22 -> V_5 ;
struct V_23 * V_24 = & V_21 -> V_25 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
T_1 * V_4 = NULL , * V_30 ;
int V_11 , V_31 , V_32 , V_33 , V_34 , V_35 ;
if ( V_24 -> type == V_36 ) {
if ( F_8 ( V_2 , 'P' , & V_29 ) )
return;
if ( V_29 . V_37 == 1 )
V_4 = F_9 ( V_2 , V_29 . V_38 [ 16 ] ) ;
else
if ( V_29 . V_37 == 2 )
V_4 = F_9 ( V_2 , V_29 . V_38 [ 12 ] ) ;
else {
F_10 ( V_21 , L_1 , V_29 . V_37 ) ;
}
} else {
if ( V_24 -> V_38 [ V_24 -> V_39 + 6 ] < 0x27 ) {
F_11 ( V_21 , L_2 ) ;
return;
}
V_4 = F_9 ( V_2 , V_24 -> V_38 [ V_24 -> V_39 + 0x98 ] ) ;
}
if ( ! V_4 ) {
F_11 ( V_21 , L_3 ) ;
return;
}
switch ( V_4 [ 0 ] ) {
case 0x10 :
case 0x11 :
case 0x12 :
V_31 = 5 ;
V_32 = V_4 [ 1 ] ;
V_33 = V_4 [ 2 ] ;
V_35 = 0 ;
V_34 = V_4 [ 4 ] ;
break;
case 0x20 :
V_31 = V_4 [ 1 ] ;
V_32 = V_4 [ 3 ] ;
V_33 = V_4 [ 2 ] ;
V_35 = 0 ;
V_34 = V_4 [ 5 ] ;
break;
case 0x30 :
V_31 = V_4 [ 1 ] ;
V_32 = V_4 [ 2 ] ;
V_33 = V_4 [ 3 ] ;
V_34 = V_4 [ 4 ] ;
V_35 = 2 ;
break;
case 0x40 :
V_31 = V_4 [ 1 ] ;
V_32 = V_4 [ 2 ] ;
V_33 = V_4 [ 3 ] ;
V_34 = V_4 [ 11 ] ;
V_35 = 0 ;
break;
default:
F_10 ( V_21 , L_4 , V_4 [ 0 ] ) ;
return;
}
V_5 -> V_13 = V_34 ;
if ( ! V_5 -> V_13 )
return;
V_11 = 0 ;
while ( V_34 ) {
if ( V_11 > V_12 ) {
F_11 ( V_21 , L_5 , V_11 ) ;
return;
}
if ( V_9 && V_9 -> V_40 ( V_9 , 0 , V_15 [ V_11 ] , 0xff , & V_27 ) ) {
F_11 ( V_21 , L_6 , V_11 ) ;
return;
}
V_34 >>= 1 ;
V_11 ++ ;
}
V_5 -> V_37 = V_4 [ 0 ] ;
if ( V_5 -> V_37 < 0x40 ) {
V_5 -> V_17 = V_33 ;
V_5 -> V_18 =
F_12 ( V_33 , sizeof( * V_5 -> V_18 ) , V_41 ) ;
if ( ! V_5 -> V_18 )
return;
V_30 = V_4 + V_31 ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ , V_30 += V_32 ) {
V_5 -> V_18 [ V_11 ] . V_5 = V_30 [ 0 ] * 10000 ;
V_5 -> V_18 [ V_11 ] . V_10 = V_30 [ 1 ] >> V_35 ;
}
} else {
T_2 V_42 = F_13 ( V_4 [ 4 ] ) ;
T_3 V_43 = F_14 ( V_4 [ 8 ] ) ;
T_1 V_10 ;
V_5 -> V_17 = V_5 -> V_13 + 1 ;
V_5 -> V_18 = F_12 ( V_5 -> V_17 ,
sizeof( * V_5 -> V_18 ) , V_41 ) ;
if ( ! V_5 -> V_18 )
return;
for ( V_10 = 0 ; V_10 <= V_5 -> V_13 ; V_10 ++ ) {
V_5 -> V_18 [ V_10 ] . V_5 = V_42 ;
V_5 -> V_18 [ V_10 ] . V_10 = V_10 ;
V_42 += V_43 ;
}
}
V_5 -> V_44 = true ;
}
void
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & F_2 ( V_2 ) -> V_5 ;
F_16 ( V_4 -> V_18 ) ;
}
