static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = F_2 ( V_1 -> V_6 ) ;
int V_7 ;
T_1 * V_8 ;
F_3 ( & V_3 -> V_9 -> V_10 , L_1 \
L_2 ,
V_11 , V_5 == V_12 ? L_3 : L_4 ,
V_1 -> V_13 , V_1 -> V_14 ,
V_1 -> V_15 ,
V_1 -> V_16 , V_1 -> V_17 ) ;
switch ( V_1 -> V_13 ) {
case 0 :
case - V_18 :
break;
case - V_19 :
case - V_20 :
case - V_21 :
return;
default:
F_3 ( & V_3 -> V_9 -> V_10 ,
L_5 ,
V_11 , V_1 -> V_13 ) ;
break;
}
V_8 = ( T_1 * ) V_1 -> V_22 ;
switch ( V_5 ) {
case V_12 :
for ( V_7 = 0 ; V_7 < V_1 -> V_16 ; V_7 ++ ) {
if ( V_1 -> V_23 [ V_7 ] . V_13 != 0 )
F_4 ( & V_3 -> V_9 -> V_10 , L_6 \
L_7 ,
V_11 ,
V_1 -> V_23 [ V_7 ] . V_13 ) ;
else if ( V_1 -> V_23 [ V_7 ] . V_14 > 0 )
V_3 -> V_24 ( V_3 ,
V_8 + V_1 -> V_23 [ V_7 ] . V_25 ,
V_1 -> V_23 [ V_7 ] . V_14 ) ;
V_1 -> V_23 [ V_7 ] . V_13 = 0 ;
V_1 -> V_23 [ V_7 ] . V_14 = 0 ;
}
break;
case V_26 :
if ( V_1 -> V_14 > 0 )
V_3 -> V_24 ( V_3 , V_8 , V_1 -> V_14 ) ;
break;
default:
F_5 ( & V_3 -> V_9 -> V_10 , L_8 \
L_9 , V_27 ) ;
return;
}
F_6 ( V_1 , V_28 ) ;
}
int F_7 ( struct V_2 * V_3 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_29 ; V_7 ++ ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_10 , V_11 , V_7 ) ;
F_8 ( V_3 -> V_30 [ V_7 ] ) ;
}
V_3 -> V_29 = 0 ;
return 0 ;
}
int F_9 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
int V_7 , V_33 ;
if ( V_32 ) {
V_33 = F_10 ( V_3 , V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
}
for ( V_7 = 0 ; V_7 < V_3 -> V_34 ; V_7 ++ ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_11 , V_11 , V_7 ) ;
V_33 = F_6 ( V_3 -> V_30 [ V_7 ] , V_28 ) ;
if ( V_33 ) {
F_5 ( & V_3 -> V_9 -> V_10 , L_12 \
L_13 ,
V_27 , V_7 ) ;
F_7 ( V_3 ) ;
return V_33 ;
}
V_3 -> V_29 ++ ;
}
return 0 ;
}
int F_11 ( struct V_2 * V_3 )
{
int V_7 ;
F_7 ( V_3 ) ;
for ( V_7 = V_3 -> V_34 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_3 -> V_30 [ V_7 ] ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_14 ,
V_11 , V_7 ) ;
F_12 ( V_3 -> V_30 [ V_7 ] ) ;
}
}
V_3 -> V_34 = 0 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_7 , V_35 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_32 . V_36 ; V_7 ++ ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_15 , V_11 , V_7 ) ;
V_3 -> V_30 [ V_7 ] = F_14 ( 0 , V_28 ) ;
if ( ! V_3 -> V_30 [ V_7 ] ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_16 , V_11 ) ;
for ( V_35 = 0 ; V_35 < V_7 ; V_35 ++ )
F_12 ( V_3 -> V_30 [ V_35 ] ) ;
return - V_37 ;
}
F_15 ( V_3 -> V_30 [ V_7 ] ,
V_3 -> V_9 ,
F_16 ( V_3 -> V_9 ,
V_3 -> V_32 . V_38 ) ,
V_3 -> V_39 [ V_7 ] ,
V_3 -> V_32 . V_40 . V_41 . V_42 ,
F_1 , V_3 ) ;
V_3 -> V_30 [ V_7 ] -> V_43 = V_44 ;
V_3 -> V_30 [ V_7 ] -> V_45 = V_3 -> V_46 [ V_7 ] ;
V_3 -> V_34 ++ ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
int V_7 , V_35 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_32 . V_36 ; V_7 ++ ) {
struct V_1 * V_1 ;
int V_47 = 0 ;
F_4 ( & V_3 -> V_9 -> V_10 , L_15 , V_11 , V_7 ) ;
V_3 -> V_30 [ V_7 ] = F_14 (
V_3 -> V_32 . V_40 . V_48 . V_49 , V_28 ) ;
if ( ! V_3 -> V_30 [ V_7 ] ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_16 , V_11 ) ;
for ( V_35 = 0 ; V_35 < V_7 ; V_35 ++ )
F_12 ( V_3 -> V_30 [ V_35 ] ) ;
return - V_37 ;
}
V_1 = V_3 -> V_30 [ V_7 ] ;
V_1 -> V_10 = V_3 -> V_9 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_24 = F_1 ;
V_1 -> V_6 = F_18 ( V_3 -> V_9 ,
V_3 -> V_32 . V_38 ) ;
V_1 -> V_43 = V_50 | V_44 ;
V_1 -> V_51 = V_3 -> V_32 . V_40 . V_48 . V_51 ;
V_1 -> V_16 = V_3 -> V_32 . V_40 . V_48 . V_49 ;
V_1 -> V_15 = V_3 -> V_32 . V_40 . V_48 . V_52 *
V_3 -> V_32 . V_40 . V_48 . V_49 ;
V_1 -> V_22 = V_3 -> V_39 [ V_7 ] ;
V_1 -> V_45 = V_3 -> V_46 [ V_7 ] ;
for ( V_35 = 0 ; V_35 < V_3 -> V_32 . V_40 . V_48 . V_49 ; V_35 ++ ) {
V_1 -> V_23 [ V_35 ] . V_25 = V_47 ;
V_1 -> V_23 [ V_35 ] . V_53 =
V_3 -> V_32 . V_40 . V_48 . V_52 ;
V_47 += V_3 -> V_32 . V_40 . V_48 . V_52 ;
}
V_3 -> V_34 ++ ;
}
return 0 ;
}
int F_19 ( struct V_2 * V_3 )
{
if ( V_3 -> V_54 & V_55 ) {
while ( V_3 -> V_56 ) {
V_3 -> V_56 -- ;
F_4 ( & V_3 -> V_9 -> V_10 , L_17 ,
V_11 , V_3 -> V_56 ) ;
F_20 ( V_3 -> V_9 , V_3 -> V_57 ,
V_3 -> V_39 [ V_3 -> V_56 ] ,
V_3 -> V_46 [ V_3 -> V_56 ] ) ;
}
}
V_3 -> V_54 &= ~ V_55 ;
return 0 ;
}
int F_21 ( struct V_2 * V_3 , int V_58 ,
unsigned long V_59 )
{
V_3 -> V_56 = 0 ;
V_3 -> V_57 = V_59 ;
F_4 ( & V_3 -> V_9 -> V_10 , L_18 \
L_19 , V_11 , V_58 * V_59 ) ;
for ( V_3 -> V_56 = 0 ; V_3 -> V_56 < V_58 ; V_3 -> V_56 ++ ) {
V_3 -> V_39 [ V_3 -> V_56 ] = F_22 (
V_3 -> V_9 , V_59 , V_28 ,
& V_3 -> V_46 [ V_3 -> V_56 ] ) ;
if ( ! V_3 -> V_39 [ V_3 -> V_56 ] ) {
F_4 ( & V_3 -> V_9 -> V_10 , L_20 ,
V_11 , V_3 -> V_56 ) ;
F_19 ( V_3 ) ;
return - V_37 ;
}
F_4 ( & V_3 -> V_9 -> V_10 , L_21 ,
V_11 , V_3 -> V_56 ,
V_3 -> V_39 [ V_3 -> V_56 ] ,
( long long ) V_3 -> V_46 [ V_3 -> V_56 ] ) ;
memset ( V_3 -> V_39 [ V_3 -> V_56 ] , 0 , V_59 ) ;
V_3 -> V_54 |= V_55 ;
}
return 0 ;
}
int F_10 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
int V_57 ;
if ( ! V_32 )
return 0 ;
if ( V_32 -> type == V_60 ) {
V_57 = V_3 -> V_32 . V_40 . V_41 . V_42 ;
} else if ( V_32 -> type == V_61 ) {
V_57 = V_32 -> V_40 . V_48 . V_52 * V_32 -> V_40 . V_48 . V_49 ;
} else {
F_5 ( & V_3 -> V_9 -> V_10 , L_22 ,
V_27 , V_32 -> type ) ;
return - V_62 ;
}
if ( V_3 -> V_56 < V_32 -> V_36 || V_3 -> V_57 < V_57 ) {
F_5 ( & V_3 -> V_9 -> V_10 , L_23 \
L_24 ,
V_27 ) ;
return - V_62 ;
}
if ( V_3 -> V_32 . type == V_32 -> type &&
V_3 -> V_32 . V_36 == V_32 -> V_36 &&
V_3 -> V_32 . V_38 == V_32 -> V_38 ) {
if ( V_32 -> type == V_60 &&
V_32 -> V_40 . V_41 . V_42 ==
V_3 -> V_32 . V_40 . V_41 . V_42 )
return 0 ;
else if ( V_32 -> type == V_61 &&
V_32 -> V_40 . V_48 . V_49 ==
V_3 -> V_32 . V_40 . V_48 . V_49 &&
V_32 -> V_40 . V_48 . V_52 ==
V_3 -> V_32 . V_40 . V_48 . V_52 &&
V_32 -> V_40 . V_48 . V_51 ==
V_3 -> V_32 . V_40 . V_48 . V_51 )
return 0 ;
}
F_4 ( & V_3 -> V_9 -> V_10 , L_25 , V_11 ) ;
F_11 ( V_3 ) ;
memcpy ( & V_3 -> V_32 , V_32 , sizeof( * V_32 ) ) ;
if ( V_32 -> type == V_60 )
return F_13 ( V_3 ) ;
else if ( V_32 -> type == V_61 )
return F_17 ( V_3 ) ;
return 0 ;
}
int F_23 ( struct V_2 * V_3 ,
const struct V_31 * V_32 )
{
int V_33 ;
if ( ! V_3 || ! V_32 )
return - V_62 ;
memcpy ( & V_3 -> V_32 , V_32 , sizeof( * V_32 ) ) ;
if ( ! V_3 -> V_24 ) {
F_5 ( & V_3 -> V_9 -> V_10 , L_26 \
L_27 , V_27 ) ;
return - V_62 ;
}
switch ( V_3 -> V_32 . type ) {
case V_60 :
V_33 = F_21 ( V_3 , V_3 -> V_32 . V_36 ,
V_3 -> V_32 . V_40 . V_41 . V_42 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_13 ( V_3 ) ;
case V_61 :
V_33 = F_21 ( V_3 , V_3 -> V_32 . V_36 ,
V_3 -> V_32 . V_40 . V_48 . V_52 *
V_3 -> V_32 . V_40 . V_48 . V_49 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_17 ( V_3 ) ;
default:
F_5 ( & V_3 -> V_9 -> V_10 , L_28 \
L_29 , V_27 ) ;
return - V_62 ;
}
}
int F_24 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
F_19 ( V_3 ) ;
return 0 ;
}
