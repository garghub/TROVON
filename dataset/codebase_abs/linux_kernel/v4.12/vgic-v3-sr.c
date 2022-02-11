static T_1 T_2 F_1 ( unsigned int V_1 )
{
switch ( V_1 & 0xf ) {
case 0 :
return F_2 ( V_2 ) ;
case 1 :
return F_2 ( V_3 ) ;
case 2 :
return F_2 ( V_4 ) ;
case 3 :
return F_2 ( V_5 ) ;
case 4 :
return F_2 ( V_6 ) ;
case 5 :
return F_2 ( V_7 ) ;
case 6 :
return F_2 ( V_8 ) ;
case 7 :
return F_2 ( V_9 ) ;
case 8 :
return F_2 ( V_10 ) ;
case 9 :
return F_2 ( V_11 ) ;
case 10 :
return F_2 ( V_12 ) ;
case 11 :
return F_2 ( V_13 ) ;
case 12 :
return F_2 ( V_14 ) ;
case 13 :
return F_2 ( V_15 ) ;
case 14 :
return F_2 ( V_16 ) ;
case 15 :
return F_2 ( V_17 ) ;
}
F_3 () ;
}
static void T_2 F_4 ( T_1 V_18 , int V_1 )
{
switch ( V_1 & 0xf ) {
case 0 :
F_5 ( V_18 , V_2 ) ;
break;
case 1 :
F_5 ( V_18 , V_3 ) ;
break;
case 2 :
F_5 ( V_18 , V_4 ) ;
break;
case 3 :
F_5 ( V_18 , V_5 ) ;
break;
case 4 :
F_5 ( V_18 , V_6 ) ;
break;
case 5 :
F_5 ( V_18 , V_7 ) ;
break;
case 6 :
F_5 ( V_18 , V_8 ) ;
break;
case 7 :
F_5 ( V_18 , V_9 ) ;
break;
case 8 :
F_5 ( V_18 , V_10 ) ;
break;
case 9 :
F_5 ( V_18 , V_11 ) ;
break;
case 10 :
F_5 ( V_18 , V_12 ) ;
break;
case 11 :
F_5 ( V_18 , V_13 ) ;
break;
case 12 :
F_5 ( V_18 , V_14 ) ;
break;
case 13 :
F_5 ( V_18 , V_15 ) ;
break;
case 14 :
F_5 ( V_18 , V_16 ) ;
break;
case 15 :
F_5 ( V_18 , V_17 ) ;
break;
}
}
void T_2 F_6 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_23 . V_24 . V_25 ;
T_1 V_26 = V_20 -> V_23 . V_24 . V_26 ;
T_1 V_18 ;
if ( ! V_22 -> V_27 ) {
F_7 ( V_28 ) ;
V_22 -> V_29 = F_2 ( V_30 ) ;
}
if ( V_26 ) {
int V_31 ;
T_3 V_32 ;
V_22 -> V_33 = F_2 ( V_34 ) ;
F_5 ( 0 , V_35 ) ;
V_18 = F_2 ( V_36 ) ;
V_32 = F_8 ( V_18 ) ;
for ( V_31 = 0 ; V_31 < V_26 ; V_31 ++ ) {
if ( V_22 -> V_33 & ( 1 << V_31 ) )
V_22 -> V_37 [ V_31 ] &= ~ V_38 ;
else
V_22 -> V_37 [ V_31 ] = F_1 ( V_31 ) ;
F_4 ( 0 , V_31 ) ;
}
switch ( V_32 ) {
case 7 :
V_22 -> V_39 [ 3 ] = F_2 ( V_40 ) ;
V_22 -> V_39 [ 2 ] = F_2 ( V_41 ) ;
case 6 :
V_22 -> V_39 [ 1 ] = F_2 ( V_42 ) ;
default:
V_22 -> V_39 [ 0 ] = F_2 ( V_43 ) ;
}
switch ( V_32 ) {
case 7 :
V_22 -> V_44 [ 3 ] = F_2 ( V_45 ) ;
V_22 -> V_44 [ 2 ] = F_2 ( V_46 ) ;
case 6 :
V_22 -> V_44 [ 1 ] = F_2 ( V_47 ) ;
default:
V_22 -> V_44 [ 0 ] = F_2 ( V_48 ) ;
}
} else {
V_22 -> V_33 = 0xffff ;
V_22 -> V_39 [ 0 ] = 0 ;
V_22 -> V_39 [ 1 ] = 0 ;
V_22 -> V_39 [ 2 ] = 0 ;
V_22 -> V_39 [ 3 ] = 0 ;
V_22 -> V_44 [ 0 ] = 0 ;
V_22 -> V_44 [ 1 ] = 0 ;
V_22 -> V_44 [ 2 ] = 0 ;
V_22 -> V_44 [ 3 ] = 0 ;
}
V_18 = F_2 ( V_49 ) ;
F_5 ( V_18 | V_50 , V_49 ) ;
if ( ! V_22 -> V_27 ) {
F_9 () ;
F_5 ( 1 , V_51 ) ;
}
}
void T_2 F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_23 . V_24 . V_25 ;
T_1 V_26 = V_20 -> V_23 . V_24 . V_26 ;
T_1 V_18 ;
T_3 V_32 ;
int V_31 ;
if ( ! V_22 -> V_27 ) {
F_5 ( 0 , V_51 ) ;
F_9 () ;
F_5 ( V_22 -> V_29 , V_30 ) ;
}
V_18 = F_2 ( V_36 ) ;
V_32 = F_8 ( V_18 ) ;
if ( V_26 ) {
F_5 ( V_22 -> V_52 , V_35 ) ;
switch ( V_32 ) {
case 7 :
F_5 ( V_22 -> V_39 [ 3 ] , V_40 ) ;
F_5 ( V_22 -> V_39 [ 2 ] , V_41 ) ;
case 6 :
F_5 ( V_22 -> V_39 [ 1 ] , V_42 ) ;
default:
F_5 ( V_22 -> V_39 [ 0 ] , V_43 ) ;
}
switch ( V_32 ) {
case 7 :
F_5 ( V_22 -> V_44 [ 3 ] , V_45 ) ;
F_5 ( V_22 -> V_44 [ 2 ] , V_46 ) ;
case 6 :
F_5 ( V_22 -> V_44 [ 1 ] , V_47 ) ;
default:
F_5 ( V_22 -> V_44 [ 0 ] , V_48 ) ;
}
for ( V_31 = 0 ; V_31 < V_26 ; V_31 ++ )
F_4 ( V_22 -> V_37 [ V_31 ] , V_31 ) ;
}
if ( ! V_22 -> V_27 ) {
F_9 () ;
F_7 ( V_53 ) ;
}
F_5 ( F_2 ( V_49 ) & ~ V_50 ,
V_49 ) ;
}
void T_2 F_11 ( void )
{
int V_54 = F_12 ( F_2 ( V_36 ) ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 <= V_54 ; V_31 ++ )
F_4 ( 0 , V_31 ) ;
}
T_1 T_2 F_13 ( void )
{
return F_2 ( V_36 ) ;
}
T_1 T_2 F_14 ( void )
{
return F_2 ( V_30 ) ;
}
void T_2 F_15 ( T_3 V_55 )
{
F_5 ( V_55 , V_30 ) ;
}
