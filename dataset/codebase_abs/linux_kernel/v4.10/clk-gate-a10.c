static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 div = 1 , V_6 ;
if ( V_5 -> V_7 )
div = V_5 -> V_7 ;
else if ( V_5 -> V_8 ) {
V_6 = F_3 ( V_5 -> V_8 ) >> V_5 -> V_9 ;
V_6 &= F_4 ( V_5 -> V_10 - 1 , 0 ) ;
div = ( 1 << V_6 ) ;
}
return V_3 / div ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_11 ;
T_1 V_12 ;
T_1 V_13 [ 2 ] ;
if ( V_5 -> V_13 [ 0 ] || V_5 -> V_13 [ 1 ] ) {
for ( V_11 = 0 ; V_11 < F_6 ( V_13 ) ; V_11 ++ ) {
switch ( V_5 -> V_13 [ V_11 ] ) {
case 0 :
V_13 [ V_11 ] = 0 ;
break;
case 45 :
V_13 [ V_11 ] = 1 ;
break;
case 90 :
V_13 [ V_11 ] = 2 ;
break;
case 135 :
V_13 [ V_11 ] = 3 ;
break;
case 180 :
V_13 [ V_11 ] = 4 ;
break;
case 225 :
V_13 [ V_11 ] = 5 ;
break;
case 270 :
V_13 [ V_11 ] = 6 ;
break;
case 315 :
V_13 [ V_11 ] = 7 ;
break;
default:
V_13 [ V_11 ] = 0 ;
break;
}
}
V_12 = F_7 ( V_13 [ 0 ] , V_13 [ 1 ] ) ;
if ( ! F_8 ( V_5 -> V_14 ) )
F_9 ( V_5 -> V_14 ,
V_15 , V_12 ) ;
else
F_10 ( L_1 ,
V_16 ) ;
}
return 0 ;
}
static void T_2 F_11 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
T_1 V_21 [ 2 ] ;
T_1 V_8 [ 3 ] ;
T_1 V_13 [ 2 ] ;
T_1 V_7 ;
struct V_22 * V_22 ;
struct V_4 * V_23 ;
const char * V_24 = V_18 -> V_25 ;
const char * V_26 [ V_27 ] ;
struct V_28 V_29 ;
int V_30 ;
V_23 = F_12 ( sizeof( * V_23 ) , V_31 ) ;
if ( F_13 ( ! V_23 ) )
return;
V_30 = F_14 ( V_18 , L_2 , V_21 , 2 ) ;
if ( V_30 )
V_21 [ 0 ] = 0 ;
if ( V_21 [ 0 ] ) {
V_23 -> V_32 . V_33 = V_34 + V_21 [ 0 ] ;
V_23 -> V_32 . V_35 = V_21 [ 1 ] ;
V_36 . V_37 = V_38 . V_37 ;
V_36 . V_39 = V_38 . V_39 ;
}
V_30 = F_15 ( V_18 , L_3 , & V_7 ) ;
if ( V_30 )
V_23 -> V_7 = 0 ;
else
V_23 -> V_7 = V_7 ;
V_30 = F_14 ( V_18 , L_4 , V_8 , 3 ) ;
if ( ! V_30 ) {
V_23 -> V_8 = V_34 + V_8 [ 0 ] ;
V_23 -> V_9 = V_8 [ 1 ] ;
V_23 -> V_10 = V_8 [ 2 ] ;
} else {
V_23 -> V_8 = NULL ;
}
V_30 = F_14 ( V_18 , L_5 , V_13 , 2 ) ;
if ( ! V_30 ) {
V_23 -> V_13 [ 0 ] = V_13 [ 0 ] ;
V_23 -> V_13 [ 1 ] = V_13 [ 1 ] ;
V_23 -> V_14 =
F_16 ( L_6 ) ;
if ( F_8 ( V_23 -> V_14 ) ) {
F_10 ( L_7 ,
V_16 ) ;
return;
}
}
F_17 ( V_18 , L_8 , & V_24 ) ;
V_29 . V_25 = V_24 ;
V_29 . V_20 = V_20 ;
V_29 . V_40 = 0 ;
V_29 . V_41 = F_18 ( V_18 , V_26 , V_27 ) ;
V_29 . V_42 = V_26 ;
V_23 -> V_32 . V_32 . V_29 = & V_29 ;
V_22 = F_19 ( NULL , & V_23 -> V_32 . V_32 ) ;
if ( F_13 ( F_8 ( V_22 ) ) ) {
F_20 ( V_23 ) ;
return;
}
V_30 = F_21 ( V_18 , V_43 , V_22 ) ;
if ( F_13 ( V_30 ) )
return;
}
void T_2 F_22 ( struct V_17 * V_18 )
{
F_11 ( V_18 , & V_36 ) ;
}
