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
#if V_14 > 1
F_3 ( V_15 L_1 ,
V_2 -> V_16 , V_2 -> V_17 , V_5 , V_2 -> V_10 , V_2 -> V_12 ) ;
#endif
F_4 ( V_2 , V_4 , V_18 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_19 ;
unsigned short V_20 , V_21 , V_22 ;
V_20 = ( V_2 -> V_7 & V_8 ) ? V_23 : V_24 ;
V_21 = ! F_6 ( & V_2 -> V_25 ) ? V_2 -> V_26 : V_2 -> V_10 ;
V_22 = ( V_2 -> V_26 + V_2 -> V_27 ) % V_20 ;
if ( ! ( V_2 -> V_28 & V_29 ) &&
V_21 != V_22 && F_6 ( & V_2 -> V_30 ) ) {
V_2 -> V_10 = V_21 ;
V_4 = F_7 ( & V_2 -> V_30 ) ;
do {
if ( ( V_19 = F_8 ( V_4 , V_31 ) ) == NULL ) {
F_9 ( & V_2 -> V_30 , V_4 ) ;
break;
}
if ( V_4 -> V_32 )
F_10 ( V_19 , V_4 -> V_32 ) ;
F_1 ( V_2 , V_19 , V_33 ) ;
V_2 -> V_10 = ( V_2 -> V_10 + 1 ) % V_20 ;
F_11 ( & V_2 -> V_25 , V_4 ) ;
} while ( V_2 -> V_10 != V_22 && ( V_4 = F_7 ( & V_2 -> V_30 ) ) != NULL );
V_2 -> V_28 &= ~ V_34 ;
if ( ! F_12 ( V_2 ) )
F_13 ( V_2 ) ;
}
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , int type )
{
unsigned char * V_35 ;
V_35 = F_2 ( V_4 , 1 ) ;
if ( V_2 -> V_7 & V_36 ) {
if ( V_2 -> V_7 & V_37 ) {
if ( type == V_18 )
* V_35 = V_38 ;
if ( type == V_39 )
* V_35 = V_40 ;
} else {
if ( type == V_18 )
* V_35 = V_40 ;
if ( type == V_39 )
* V_35 = V_38 ;
}
} else {
if ( V_2 -> V_7 & V_37 ) {
if ( type == V_18 )
* V_35 = V_41 ;
if ( type == V_39 )
* V_35 = V_42 ;
} else {
if ( type == V_18 )
* V_35 = V_42 ;
if ( type == V_39 )
* V_35 = V_41 ;
}
}
#if V_14 > 2
F_3 ( V_15 L_2 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_4 -> V_43 [ 0 ] , V_4 -> V_43 [ 1 ] , V_4 -> V_43 [ 2 ] ) ;
#endif
if ( ! F_14 ( V_2 , V_4 ) )
F_15 ( V_4 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0x00 ;
V_2 -> V_44 = 0 ;
if ( V_2 -> V_7 & V_8 ) {
#if V_14 > 1
F_3 ( V_15 L_3 ,
V_2 -> V_16 , V_2 -> V_17 ) ;
#endif
F_17 ( V_2 , V_45 , V_46 , V_18 ) ;
} else {
#if V_14 > 1
F_3 ( V_15 L_4 ,
V_2 -> V_16 , V_2 -> V_17 ) ;
#endif
F_17 ( V_2 , V_47 , V_46 , V_18 ) ;
}
F_13 ( V_2 ) ;
F_18 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
#if V_14 > 1
F_3 ( V_15 L_5 ,
V_2 -> V_16 , V_2 -> V_17 , V_2 -> V_12 ) ;
#endif
F_17 ( V_2 , V_48 , V_46 , V_39 ) ;
V_2 -> V_28 &= ~ V_34 ;
}
void F_20 ( struct V_1 * V_2 )
{
#if V_14 > 1
F_3 ( V_15 L_6 ,
V_2 -> V_16 , V_2 -> V_17 , V_2 -> V_12 ) ;
#endif
F_17 ( V_2 , V_48 , V_33 , V_39 ) ;
V_2 -> V_28 &= ~ V_34 ;
}
void F_21 ( struct V_1 * V_2 , unsigned short V_49 )
{
if ( V_2 -> V_10 == V_49 ) {
F_22 ( V_2 , V_49 ) ;
F_23 ( V_2 ) ;
V_2 -> V_44 = 0 ;
} else if ( V_2 -> V_26 != V_49 ) {
F_22 ( V_2 , V_49 ) ;
F_13 ( V_2 ) ;
}
}
void F_24 ( struct V_1 * V_2 , int type , int V_50 )
{
if ( type == V_18 && V_50 )
F_19 ( V_2 ) ;
}
