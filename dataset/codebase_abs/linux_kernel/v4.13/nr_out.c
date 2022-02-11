void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 ;
unsigned char V_6 [ V_7 ] ;
int V_8 , V_9 , V_10 ;
if ( V_4 -> V_10 - V_7 > V_11 ) {
F_2 ( V_4 , V_6 , V_7 ) ;
F_3 ( V_4 , V_7 ) ;
V_9 = F_4 ( V_4 ) ;
while ( V_4 -> V_10 > 0 ) {
if ( ( V_5 = F_5 ( V_2 , V_9 + V_11 , 0 , & V_8 ) ) == NULL )
return;
F_6 ( V_5 , V_9 ) ;
V_10 = ( V_11 > V_4 -> V_10 ) ? V_4 -> V_10 : V_11 ;
F_2 ( V_4 , F_7 ( V_5 , V_10 ) , V_10 ) ;
F_3 ( V_4 , V_10 ) ;
F_8 ( V_5 , V_7 ) ;
F_9 ( V_5 , V_6 ,
V_7 ) ;
if ( V_4 -> V_10 > 0 )
V_5 -> V_12 [ 4 ] |= V_13 ;
F_10 ( & V_2 -> V_14 , V_5 ) ;
}
F_11 ( V_4 ) ;
} else {
F_10 ( & V_2 -> V_14 , V_4 ) ;
}
F_12 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_4 -> V_12 [ 2 ] = V_16 -> V_17 ;
V_4 -> V_12 [ 3 ] = V_16 -> V_18 ;
if ( V_16 -> V_19 & V_20 )
V_4 -> V_12 [ 4 ] |= V_21 ;
F_15 ( V_2 ) ;
F_16 ( V_2 , V_4 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_15 * V_16 = F_14 ( V_2 ) ;
if ( ( V_4 = F_18 ( & V_16 -> V_22 ) ) == NULL )
return;
if ( ( V_5 = F_19 ( V_4 , V_23 ) ) == NULL )
return;
V_5 -> V_12 [ 2 ] = V_16 -> V_24 ;
V_5 -> V_12 [ 3 ] = V_16 -> V_18 ;
if ( V_16 -> V_19 & V_20 )
V_5 -> V_12 [ 4 ] |= V_21 ;
F_16 ( V_2 , V_5 ) ;
V_16 -> V_19 &= ~ V_25 ;
V_16 -> V_26 = V_16 -> V_18 ;
F_20 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
struct V_3 * V_4 , * V_5 ;
unsigned short V_27 , V_28 ;
if ( V_16 -> V_29 != V_30 )
return;
if ( V_16 -> V_19 & V_31 )
return;
if ( ! F_18 ( & V_2 -> V_14 ) )
return;
V_27 = ( F_18 ( & V_16 -> V_22 ) == NULL ) ? V_16 -> V_24 : V_16 -> V_17 ;
V_28 = ( V_16 -> V_24 + V_16 -> V_32 ) % V_33 ;
if ( V_27 == V_28 )
return;
V_16 -> V_17 = V_27 ;
V_4 = F_21 ( & V_2 -> V_14 ) ;
do {
if ( ( V_5 = F_19 ( V_4 , V_23 ) ) == NULL ) {
F_22 ( & V_2 -> V_14 , V_4 ) ;
break;
}
F_23 ( V_5 , V_2 ) ;
F_13 ( V_2 , V_5 ) ;
V_16 -> V_17 = ( V_16 -> V_17 + 1 ) % V_33 ;
F_10 ( & V_16 -> V_22 , V_4 ) ;
} while ( V_16 -> V_17 != V_28 &&
( V_4 = F_21 ( & V_2 -> V_14 ) ) != NULL );
V_16 -> V_26 = V_16 -> V_18 ;
V_16 -> V_19 &= ~ V_25 ;
if ( ! F_24 ( V_2 ) )
F_25 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
unsigned char * V_34 ;
V_34 = F_8 ( V_4 , V_35 ) ;
memcpy ( V_34 , & V_16 -> V_36 , V_37 ) ;
V_34 [ 6 ] &= ~ V_38 ;
V_34 [ 6 ] &= ~ V_39 ;
V_34 [ 6 ] |= V_40 ;
V_34 += V_37 ;
memcpy ( V_34 , & V_16 -> V_41 , V_37 ) ;
V_34 [ 6 ] &= ~ V_38 ;
V_34 [ 6 ] |= V_39 ;
V_34 [ 6 ] |= V_40 ;
V_34 += V_37 ;
* V_34 ++ = V_42 ;
if ( ! F_26 ( V_4 , NULL ) ) {
F_11 ( V_4 ) ;
F_27 ( V_2 , V_43 ) ;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
V_16 -> V_19 = 0x00 ;
V_16 -> V_44 = 0 ;
F_29 ( V_2 , V_45 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_25 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
int V_46 = V_47 ;
if ( V_16 -> V_19 & V_20 ) {
V_46 |= V_21 ;
} else {
if ( F_18 ( & V_16 -> V_48 ) != NULL )
V_46 |= V_49 ;
}
F_29 ( V_2 , V_46 ) ;
V_16 -> V_26 = V_16 -> V_18 ;
V_16 -> V_19 &= ~ V_25 ;
}
void F_34 ( struct V_1 * V_2 , unsigned short V_16 )
{
struct V_15 * V_50 = F_14 ( V_2 ) ;
if ( V_50 -> V_17 == V_16 ) {
F_35 ( V_2 , V_16 ) ;
F_20 ( V_2 ) ;
V_50 -> V_44 = 0 ;
} else {
if ( V_50 -> V_24 != V_16 ) {
F_35 ( V_2 , V_16 ) ;
F_25 ( V_2 ) ;
}
}
}
