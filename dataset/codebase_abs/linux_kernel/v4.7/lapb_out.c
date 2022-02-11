static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
unsigned char * V_6 ;
if ( ! V_4 )
return;
if ( V_2 -> V_7 & V_8 ) {
V_6 = F_2 ( V_4 , 2 ) ;
V_6 [ 0 ] = V_9 ;
V_6 [ 0 ] |= V_2 -> V_10 << 1 ;
V_6 [ 1 ] = V_5 ? V_11 : 0 ;
V_6 [ 1 ] |= V_2 -> V_12 << 1 ;
} else {
V_6 = F_2 ( V_4 , 1 ) ;
* V_6 = V_9 ;
* V_6 |= V_5 ? V_13 : 0 ;
* V_6 |= V_2 -> V_12 << 5 ;
* V_6 |= V_2 -> V_10 << 1 ;
}
F_3 ( 1 , L_1 ,
V_2 -> V_14 , V_2 -> V_15 , V_5 , V_2 -> V_10 , V_2 -> V_12 ) ;
F_4 ( V_2 , V_4 , V_16 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_17 ;
unsigned short V_18 , V_19 , V_20 ;
V_18 = ( V_2 -> V_7 & V_8 ) ? V_21 : V_22 ;
V_19 = ! F_6 ( & V_2 -> V_23 ) ? V_2 -> V_24 : V_2 -> V_10 ;
V_20 = ( V_2 -> V_24 + V_2 -> V_25 ) % V_18 ;
if ( ! ( V_2 -> V_26 & V_27 ) &&
V_19 != V_20 && F_6 ( & V_2 -> V_28 ) ) {
V_2 -> V_10 = V_19 ;
V_4 = F_7 ( & V_2 -> V_28 ) ;
do {
if ( ( V_17 = F_8 ( V_4 , V_29 ) ) == NULL ) {
F_9 ( & V_2 -> V_28 , V_4 ) ;
break;
}
if ( V_4 -> V_30 )
F_10 ( V_17 , V_4 -> V_30 ) ;
F_1 ( V_2 , V_17 , V_31 ) ;
V_2 -> V_10 = ( V_2 -> V_10 + 1 ) % V_18 ;
F_11 ( & V_2 -> V_23 , V_4 ) ;
} while ( V_2 -> V_10 != V_20 && ( V_4 = F_7 ( & V_2 -> V_28 ) ) != NULL );
V_2 -> V_26 &= ~ V_32 ;
if ( ! F_12 ( V_2 ) )
F_13 ( V_2 ) ;
}
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , int type )
{
unsigned char * V_33 ;
V_33 = F_2 ( V_4 , 1 ) ;
if ( V_2 -> V_7 & V_34 ) {
if ( V_2 -> V_7 & V_35 ) {
if ( type == V_16 )
* V_33 = V_36 ;
if ( type == V_37 )
* V_33 = V_38 ;
} else {
if ( type == V_16 )
* V_33 = V_38 ;
if ( type == V_37 )
* V_33 = V_36 ;
}
} else {
if ( V_2 -> V_7 & V_35 ) {
if ( type == V_16 )
* V_33 = V_39 ;
if ( type == V_37 )
* V_33 = V_40 ;
} else {
if ( type == V_16 )
* V_33 = V_40 ;
if ( type == V_37 )
* V_33 = V_39 ;
}
}
F_3 ( 2 , L_2 , V_2 -> V_14 , V_2 -> V_15 , V_4 -> V_41 ) ;
if ( ! F_14 ( V_2 , V_4 ) )
F_15 ( V_4 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_26 = 0x00 ;
V_2 -> V_42 = 0 ;
if ( V_2 -> V_7 & V_8 ) {
F_3 ( 1 , L_3 , V_2 -> V_14 , V_2 -> V_15 ) ;
F_17 ( V_2 , V_43 , V_44 , V_16 ) ;
} else {
F_3 ( 1 , L_4 , V_2 -> V_14 , V_2 -> V_15 ) ;
F_17 ( V_2 , V_45 , V_44 , V_16 ) ;
}
F_13 ( V_2 ) ;
F_18 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_3 ( 1 , L_5 ,
V_2 -> V_14 , V_2 -> V_15 , V_2 -> V_12 ) ;
F_17 ( V_2 , V_46 , V_44 , V_37 ) ;
V_2 -> V_26 &= ~ V_32 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_3 ( 1 , L_6 ,
V_2 -> V_14 , V_2 -> V_15 , V_2 -> V_12 ) ;
F_17 ( V_2 , V_46 , V_31 , V_37 ) ;
V_2 -> V_26 &= ~ V_32 ;
}
void F_21 ( struct V_1 * V_2 , unsigned short V_47 )
{
if ( V_2 -> V_10 == V_47 ) {
F_22 ( V_2 , V_47 ) ;
F_23 ( V_2 ) ;
V_2 -> V_42 = 0 ;
} else if ( V_2 -> V_24 != V_47 ) {
F_22 ( V_2 , V_47 ) ;
F_13 ( V_2 ) ;
}
}
void F_24 ( struct V_1 * V_2 , int type , int V_48 )
{
if ( type == V_16 && V_48 )
F_19 ( V_2 ) ;
}
