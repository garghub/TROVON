static int F_1 ( unsigned int V_1 )
{
int V_2 = 1 ;
if ( ! V_1 )
return 128 ;
while ( V_1 -- > 0 )
V_2 *= 2 ;
return V_2 ;
}
int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_5 * V_7 ;
unsigned char V_8 [ V_9 ] ;
int V_10 , V_11 , V_12 ;
int V_13 = 0 , V_14 = F_3 ( V_6 ) -> V_15 & V_16 ;
struct V_17 * V_18 = F_4 ( V_4 ) ;
int V_19 = V_18 -> V_20 -> V_21 ? V_9 :
V_22 ;
int V_23 = F_1 ( V_18 -> V_24 . V_25 ) ;
if ( V_6 -> V_12 - V_19 > V_23 ) {
F_5 ( V_6 , V_8 , V_19 ) ;
F_6 ( V_6 , V_19 ) ;
V_11 = F_7 ( V_6 ) ;
while ( V_6 -> V_12 > 0 ) {
F_8 ( V_4 ) ;
V_7 = F_9 ( V_4 , V_11 + V_23 ,
V_14 , & V_10 ) ;
F_10 ( V_4 ) ;
if ( ! V_7 ) {
if ( V_10 == - V_26 && V_14 ) {
F_11 ( V_6 ) ;
return V_13 ;
}
F_12 ( V_4 , L_1
L_2
L_3 , V_10 , V_13 ) ;
return V_10 ;
}
F_13 ( V_7 , V_11 ) ;
V_12 = V_23 > V_6 -> V_12 ? V_6 -> V_12 : V_23 ;
F_5 ( V_6 , F_14 ( V_7 , V_12 ) , V_12 ) ;
F_6 ( V_6 , V_12 ) ;
F_15 ( V_7 , V_19 ) ;
F_16 ( V_7 , V_8 , V_19 ) ;
if ( V_6 -> V_12 > 0 ) {
if ( V_18 -> V_20 -> V_21 )
V_7 -> V_27 [ 3 ] |= V_28 ;
else
V_7 -> V_27 [ 2 ] |= V_29 ;
}
F_17 ( & V_4 -> V_30 , V_7 ) ;
V_13 += V_12 ;
}
F_11 ( V_6 ) ;
} else {
F_17 ( & V_4 -> V_30 , V_6 ) ;
V_13 = V_6 -> V_12 - V_19 ;
}
return V_13 ;
}
static void F_18 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_17 * V_18 = F_4 ( V_4 ) ;
if ( ! V_6 )
return;
if ( V_18 -> V_20 -> V_21 ) {
V_6 -> V_27 [ 2 ] = ( V_18 -> V_31 << 1 ) & 0xFE ;
V_6 -> V_27 [ 3 ] &= V_28 ;
V_6 -> V_27 [ 3 ] |= ( V_18 -> V_32 << 1 ) & 0xFE ;
} else {
V_6 -> V_27 [ 2 ] &= V_29 ;
V_6 -> V_27 [ 2 ] |= ( V_18 -> V_31 << 1 ) & 0x0E ;
V_6 -> V_27 [ 2 ] |= ( V_18 -> V_32 << 5 ) & 0xE0 ;
}
F_19 ( V_6 , V_18 -> V_20 ) ;
}
void F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_7 ;
unsigned short V_33 , V_34 ;
int V_35 ;
struct V_17 * V_18 = F_4 ( V_4 ) ;
if ( V_18 -> V_36 != V_37 )
return;
if ( F_21 ( & V_18 -> V_38 ) != NULL &&
! F_22 ( V_39 , & V_18 -> V_15 ) ) {
V_6 = F_23 ( & V_18 -> V_38 ) ;
F_19 ( V_6 , V_18 -> V_20 ) ;
}
if ( V_18 -> V_40 & V_41 )
return;
if ( ! F_21 ( & V_4 -> V_30 ) )
return;
V_35 = V_18 -> V_20 -> V_21 ? V_42 : V_43 ;
V_33 = F_21 ( & V_18 -> V_44 ) ? V_18 -> V_31 : V_18 -> V_45 ;
V_34 = ( V_18 -> V_45 + V_18 -> V_24 . V_46 ) % V_35 ;
if ( V_33 == V_34 )
return;
V_18 -> V_31 = V_33 ;
V_6 = F_23 ( & V_4 -> V_30 ) ;
do {
if ( ( V_7 = F_24 ( V_6 , V_47 ) ) == NULL ) {
F_25 ( & V_4 -> V_30 , V_6 ) ;
break;
}
F_26 ( V_7 , V_4 ) ;
F_18 ( V_4 , V_7 ) ;
V_18 -> V_31 = ( V_18 -> V_31 + 1 ) % V_35 ;
F_17 ( & V_18 -> V_44 , V_6 ) ;
} while ( V_18 -> V_31 != V_34 &&
( V_6 = F_23 ( & V_4 -> V_30 ) ) != NULL );
V_18 -> V_48 = V_18 -> V_32 ;
V_18 -> V_40 &= ~ V_49 ;
F_27 ( V_4 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = F_4 ( V_4 ) ;
if ( V_18 -> V_40 & V_50 )
F_29 ( V_4 , V_51 ) ;
else
F_29 ( V_4 , V_52 ) ;
V_18 -> V_48 = V_18 -> V_32 ;
V_18 -> V_40 &= ~ V_49 ;
F_27 ( V_4 ) ;
}
