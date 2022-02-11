void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 ) ;
}
void F_4 ( struct V_1 * V_2 , unsigned short V_4 )
{
struct V_3 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
if ( V_9 -> V_12 != V_4 ) {
while ( F_5 ( & V_9 -> V_6 ) != NULL && V_9 -> V_12 != V_4 ) {
V_11 = F_6 ( & V_9 -> V_6 ) ;
F_7 ( V_11 ) ;
V_9 -> V_12 = ( V_9 -> V_12 + 1 ) % V_13 ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_14 = NULL ;
while ( ( V_11 = F_6 ( & F_2 ( V_2 ) -> V_6 ) ) != NULL ) {
if ( V_14 == NULL )
F_9 ( & V_2 -> V_5 , V_11 ) ;
else
F_10 ( V_14 , V_11 , & V_2 -> V_5 ) ;
V_14 = V_11 ;
}
}
int F_11 ( struct V_1 * V_2 , unsigned short V_4 )
{
struct V_3 * V_9 = F_2 ( V_2 ) ;
unsigned short V_15 = V_9 -> V_12 ;
while ( V_15 != V_9 -> V_16 ) {
if ( V_4 == V_15 ) return 1 ;
V_15 = ( V_15 + 1 ) % V_13 ;
}
return V_4 == V_9 -> V_16 ;
}
int F_12 ( struct V_1 * V_2 , unsigned short V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_15 = V_4 -> V_18 ;
unsigned short V_19 = ( V_4 -> V_20 + V_4 -> V_21 ) % V_13 ;
while ( V_15 != V_19 ) {
if ( V_17 == V_15 ) return 1 ;
V_15 = ( V_15 + 1 ) % V_13 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 , int V_22 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
unsigned char * V_23 ;
int V_24 , V_25 ;
V_24 = V_26 + V_27 ;
switch ( V_22 & 0x0F ) {
case V_28 :
V_24 += 17 ;
break;
case V_29 :
V_24 += ( V_4 -> V_30 ) ? 2 : 1 ;
break;
case V_31 :
case V_32 :
case V_33 :
break;
default:
F_14 ( V_34 L_1 , V_22 ) ;
return;
}
if ( ( V_11 = F_15 ( V_24 , V_35 ) ) == NULL )
return;
F_16 ( V_11 , V_26 ) ;
V_23 = F_17 ( V_11 , F_18 ( V_11 ) ) ;
switch ( V_22 & 0x0F ) {
case V_28 :
V_25 = V_4 -> V_36 / V_37 ;
* V_23 ++ = V_4 -> V_38 ;
* V_23 ++ = V_4 -> V_39 ;
* V_23 ++ = 0 ;
* V_23 ++ = 0 ;
* V_23 ++ = V_22 ;
* V_23 ++ = V_4 -> V_21 ;
memcpy ( V_23 , & V_4 -> V_40 , V_41 ) ;
V_23 [ 6 ] &= ~ V_42 ;
V_23 [ 6 ] &= ~ V_43 ;
V_23 [ 6 ] |= V_44 ;
V_23 += V_41 ;
memcpy ( V_23 , & V_4 -> V_45 , V_41 ) ;
V_23 [ 6 ] &= ~ V_42 ;
V_23 [ 6 ] &= ~ V_43 ;
V_23 [ 6 ] |= V_44 ;
V_23 += V_41 ;
* V_23 ++ = V_25 % 256 ;
* V_23 ++ = V_25 / 256 ;
break;
case V_29 :
* V_23 ++ = V_4 -> V_46 ;
* V_23 ++ = V_4 -> V_47 ;
* V_23 ++ = V_4 -> V_38 ;
* V_23 ++ = V_4 -> V_39 ;
* V_23 ++ = V_22 ;
* V_23 ++ = V_4 -> V_21 ;
if ( V_4 -> V_30 ) * V_23 ++ = V_48 ;
break;
case V_31 :
case V_32 :
* V_23 ++ = V_4 -> V_46 ;
* V_23 ++ = V_4 -> V_47 ;
* V_23 ++ = 0 ;
* V_23 ++ = 0 ;
* V_23 ++ = V_22 ;
break;
case V_33 :
* V_23 ++ = V_4 -> V_46 ;
* V_23 ++ = V_4 -> V_47 ;
* V_23 ++ = 0 ;
* V_23 ++ = V_4 -> V_18 ;
* V_23 ++ = V_22 ;
break;
}
F_19 ( V_2 , V_11 ) ;
}
void F_20 ( struct V_10 * V_11 , int V_49 , unsigned char V_50 )
{
struct V_10 * V_51 ;
unsigned char * V_23 ;
int V_24 ;
V_24 = V_26 + V_27 + 1 ;
if ( ( V_51 = F_15 ( V_24 , V_35 ) ) == NULL )
return;
F_16 ( V_51 , 0 ) ;
V_23 = F_17 ( V_51 , V_26 + V_27 ) ;
F_21 ( V_11 , 7 , V_23 , V_41 ) ;
V_23 [ 6 ] &= ~ V_42 ;
V_23 [ 6 ] &= ~ V_43 ;
V_23 [ 6 ] |= V_44 ;
V_23 += V_41 ;
F_22 ( V_11 , V_23 , V_41 ) ;
V_23 [ 6 ] &= ~ V_42 ;
V_23 [ 6 ] |= V_43 ;
V_23 [ 6 ] |= V_44 ;
V_23 += V_41 ;
* V_23 ++ = V_48 ;
if ( V_49 ) {
* V_23 ++ = 0 ;
* V_23 ++ = 0 ;
* V_23 ++ = V_11 -> V_52 [ 15 ] ;
* V_23 ++ = V_11 -> V_52 [ 16 ] ;
} else {
* V_23 ++ = V_11 -> V_52 [ 15 ] ;
* V_23 ++ = V_11 -> V_52 [ 16 ] ;
* V_23 ++ = 0 ;
* V_23 ++ = 0 ;
}
* V_23 ++ = V_50 ;
* V_23 ++ = 0 ;
if ( ! F_23 ( V_51 , NULL ) )
F_7 ( V_51 ) ;
}
void F_24 ( struct V_1 * V_2 , int V_53 )
{
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_1 ( V_2 ) ;
F_2 ( V_2 ) -> V_54 = V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = V_53 ;
V_2 -> V_59 |= V_60 ;
if ( ! F_29 ( V_2 , V_61 ) ) {
V_2 -> V_62 ( V_2 ) ;
F_30 ( V_2 , V_61 ) ;
}
}
