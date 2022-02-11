void T_1 F_1 ( void )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_3 ( V_3 , V_2 [ V_1 ] . V_4 ,
V_2 [ V_1 ] . V_5 ) ;
}
static void F_4 ( struct V_6 * V_7 ,
unsigned int V_8 , unsigned int V_9 )
{
if ( V_7 -> V_10 && V_7 -> V_11 -> V_12 < V_8 ) {
F_5 ( V_7 -> V_13 -> V_14 ,
L_1 ,
V_15 , V_9 ,
V_7 -> V_11 -> V_12 ) ;
while ( V_7 -> V_10 &&
V_7 -> V_11 -> V_12 < V_8 ) {
V_7 -> V_11 ++ ;
V_7 -> V_10 -- ;
}
}
}
static bool F_6 ( struct V_6 * V_7 ,
T_2 * V_16 , unsigned int V_17 , unsigned int V_18 )
{
unsigned int V_5 = F_7 ( V_19 , V_17 + V_18 ) ;
unsigned int V_20 = V_17 , V_8 ;
F_8 (st_offset, etnaviv_states, size) {
V_8 = ( V_16 - V_7 -> V_21 +
V_20 - V_17 ) * 4 ;
F_4 ( V_7 , V_8 , V_20 * 4 ) ;
if ( V_7 -> V_10 &&
V_7 -> V_11 -> V_12 == V_8 ) {
V_7 -> V_11 ++ ;
V_7 -> V_10 -- ;
continue;
}
F_9 ( V_7 -> V_13 -> V_14 ,
L_2 ,
V_15 , V_20 * 4 , V_8 ) ;
return false ;
}
if ( V_7 -> V_10 ) {
V_8 = ( V_16 - V_7 -> V_21 + V_18 ) * 4 ;
F_4 ( V_7 , V_8 , V_20 * 4 +
V_7 -> V_11 -> V_12 -
V_8 ) ;
}
return true ;
}
bool F_10 ( struct V_22 * V_13 , T_2 * V_23 ,
unsigned int V_5 ,
struct V_24 * V_11 ,
unsigned int V_25 )
{
struct V_6 V_7 ;
T_2 * V_26 = V_23 ;
T_2 * V_27 = V_26 + V_5 ;
V_7 . V_13 = V_13 ;
V_7 . V_11 = V_11 ;
V_7 . V_10 = V_25 ;
V_7 . V_21 = V_23 ;
while ( V_26 < V_27 ) {
T_2 V_28 = * V_26 ;
unsigned int V_29 , V_30 , V_31 ;
unsigned int V_32 = V_28 >> 27 ;
switch ( V_32 ) {
case V_33 :
V_30 = F_11 ( V_28 , V_34 ) ;
V_29 = F_12 ( 1 + V_30 , 2 ) ;
if ( V_26 + V_29 > V_27 )
break;
V_31 = F_11 ( V_28 , V_35 ) ;
if ( ! F_6 ( & V_7 , V_26 + 1 ,
V_31 , V_30 ) )
return false ;
break;
case V_36 :
V_30 = F_11 ( V_28 , V_37 ) ;
if ( V_30 == 0 )
V_30 = 256 ;
V_29 = 2 + V_30 * 2 ;
break;
default:
V_29 = V_38 [ V_32 ] ;
if ( V_29 == 0 ) {
F_13 ( V_13 -> V_14 , L_3 ,
V_15 , V_32 , V_26 - V_7 . V_21 ) ;
return false ;
}
break;
}
V_26 += V_29 ;
}
if ( V_26 > V_27 ) {
F_13 ( V_13 -> V_14 , L_4 ,
V_15 , V_26 - V_7 . V_21 , V_5 ) ;
return false ;
}
return true ;
}
