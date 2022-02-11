static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( T_1 ,
V_4 -> V_6 - V_4 -> V_7 , V_2 -> V_8 . V_9 - V_2 -> V_8 . V_10 ) ;
memcpy ( V_2 -> V_8 . V_11 + V_2 -> V_8 . V_10 , V_4 -> V_12 + V_4 -> V_7 , V_5 ) ;
V_4 -> V_7 += V_5 ;
V_2 -> V_8 . V_10 += V_5 ;
if ( V_2 -> V_8 . V_10 == V_2 -> V_8 . V_9 ) {
V_2 -> V_8 . V_10 = 0 ;
return true ;
}
return false ;
}
static enum V_13 F_3 ( struct V_1 * V_2 , const T_2 * V_12 ,
T_1 * V_7 , T_1 V_6 )
{
T_2 V_14 ;
if ( V_2 -> V_10 == 0 )
V_2 -> V_15 = 0 ;
while ( * V_7 < V_6 ) {
V_14 = V_12 [ * V_7 ] ;
++ * V_7 ;
V_2 -> V_15 |= ( V_16 ) ( V_14 & 0x7F ) << V_2 -> V_10 ;
if ( ( V_14 & 0x80 ) == 0 ) {
if ( V_14 == 0 && V_2 -> V_10 != 0 )
return V_17 ;
V_2 -> V_10 = 0 ;
return V_18 ;
}
V_2 -> V_10 += 7 ;
if ( V_2 -> V_10 == 7 * V_19 )
return V_17 ;
}
return V_20 ;
}
static enum V_13 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
enum V_13 V_21 ;
V_2 -> V_22 = V_4 -> V_7 ;
V_2 -> V_23 = V_4 -> V_24 ;
#ifdef F_5
if ( V_2 -> V_25 )
V_21 = F_6 ( V_2 -> V_26 , V_2 -> V_27 , V_4 ) ;
else
#endif
V_21 = F_7 ( V_2 -> V_27 , V_4 ) ;
V_2 -> V_28 . V_29 += V_4 -> V_7 - V_2 -> V_22 ;
V_2 -> V_28 . V_30 += V_4 -> V_24 - V_2 -> V_23 ;
if ( V_2 -> V_28 . V_29 > V_2 -> V_31 . V_29
|| V_2 -> V_28 . V_30
> V_2 -> V_31 . V_30 )
return V_17 ;
if ( V_2 -> V_32 == V_33 )
V_2 -> V_34 = F_8 ( V_4 -> V_35 + V_2 -> V_23 ,
V_4 -> V_24 - V_2 -> V_23 , V_2 -> V_34 ) ;
if ( V_21 == V_18 ) {
if ( V_2 -> V_31 . V_29 != V_36
&& V_2 -> V_31 . V_29
!= V_2 -> V_28 . V_29 )
return V_17 ;
if ( V_2 -> V_31 . V_30 != V_36
&& V_2 -> V_31 . V_30
!= V_2 -> V_28 . V_30 )
return V_17 ;
V_2 -> V_28 . V_37 . V_38 += V_2 -> V_31 . V_9
+ V_2 -> V_28 . V_29 ;
#ifdef F_9
V_2 -> V_28 . V_37 . V_38 += V_39 [ V_2 -> V_32 ] ;
#else
if ( V_2 -> V_32 == V_33 )
V_2 -> V_28 . V_37 . V_38 += 4 ;
#endif
V_2 -> V_28 . V_37 . V_30 += V_2 -> V_28 . V_30 ;
V_2 -> V_28 . V_37 . V_34 = F_8 (
( const T_2 * ) & V_2 -> V_28 . V_37 ,
sizeof( V_2 -> V_28 . V_37 ) , V_2 -> V_28 . V_37 . V_34 ) ;
++ V_2 -> V_28 . V_40 ;
}
return V_21 ;
}
static void F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_1 V_41 = V_4 -> V_7 - V_2 -> V_22 ;
V_2 -> V_42 . V_9 += V_41 ;
V_2 -> V_34 = F_8 ( V_4 -> V_12 + V_2 -> V_22 , V_41 , V_2 -> V_34 ) ;
}
static enum V_13 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
enum V_13 V_21 ;
do {
V_21 = F_3 ( V_2 , V_4 -> V_12 , & V_4 -> V_7 , V_4 -> V_6 ) ;
if ( V_21 != V_18 ) {
F_10 ( V_2 , V_4 ) ;
return V_21 ;
}
switch ( V_2 -> V_42 . V_43 ) {
case V_44 :
V_2 -> V_42 . V_40 = V_2 -> V_15 ;
if ( V_2 -> V_42 . V_40 != V_2 -> V_28 . V_40 )
return V_17 ;
V_2 -> V_42 . V_43 = V_45 ;
break;
case V_45 :
V_2 -> V_42 . V_37 . V_38 += V_2 -> V_15 ;
V_2 -> V_42 . V_43 = V_46 ;
break;
case V_46 :
V_2 -> V_42 . V_37 . V_30 += V_2 -> V_15 ;
V_2 -> V_42 . V_37 . V_34 = F_8 (
( const T_2 * ) & V_2 -> V_42 . V_37 ,
sizeof( V_2 -> V_42 . V_37 ) ,
V_2 -> V_42 . V_37 . V_34 ) ;
-- V_2 -> V_42 . V_40 ;
V_2 -> V_42 . V_43 = V_45 ;
break;
}
} while ( V_2 -> V_42 . V_40 > 0 );
return V_18 ;
}
static enum V_13 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
do {
if ( V_4 -> V_7 == V_4 -> V_6 )
return V_20 ;
if ( ( ( V_2 -> V_34 >> V_2 -> V_10 ) & 0xFF ) != V_4 -> V_12 [ V_4 -> V_7 ++ ] )
return V_17 ;
V_2 -> V_10 += 8 ;
} while ( V_2 -> V_10 < 32 );
V_2 -> V_34 = 0 ;
V_2 -> V_10 = 0 ;
return V_18 ;
}
static bool F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
while ( V_2 -> V_10 < V_39 [ V_2 -> V_32 ] ) {
if ( V_4 -> V_7 == V_4 -> V_6 )
return false ;
++ V_4 -> V_7 ;
++ V_2 -> V_10 ;
}
V_2 -> V_10 = 0 ;
return true ;
}
static enum V_13 F_14 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_2 -> V_8 . V_11 , V_47 , V_48 ) )
return V_49 ;
if ( F_8 ( V_2 -> V_8 . V_11 + V_48 , 2 , 0 )
!= F_16 ( V_2 -> V_8 . V_11 + V_48 + 2 ) )
return V_17 ;
if ( V_2 -> V_8 . V_11 [ V_48 ] != 0 )
return V_50 ;
V_2 -> V_32 = V_2 -> V_8 . V_11 [ V_48 + 1 ] ;
#ifdef F_9
if ( V_2 -> V_32 > V_51 )
return V_50 ;
if ( V_2 -> V_32 > V_33 )
return V_52 ;
#else
if ( V_2 -> V_32 > V_33 )
return V_50 ;
#endif
return V_20 ;
}
static enum V_13 F_17 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_2 -> V_8 . V_11 + 10 , V_53 , V_54 ) )
return V_17 ;
if ( F_8 ( V_2 -> V_8 . V_11 + 4 , 6 , 0 ) != F_16 ( V_2 -> V_8 . V_11 ) )
return V_17 ;
if ( ( V_2 -> V_42 . V_9 >> 2 ) != F_16 ( V_2 -> V_8 . V_11 + 4 ) )
return V_17 ;
if ( V_2 -> V_8 . V_11 [ 8 ] != 0 || V_2 -> V_8 . V_11 [ 9 ] != V_2 -> V_32 )
return V_17 ;
return V_18 ;
}
static enum V_13 F_18 ( struct V_1 * V_2 )
{
enum V_13 V_21 ;
V_2 -> V_8 . V_9 -= 4 ;
if ( F_8 ( V_2 -> V_8 . V_11 , V_2 -> V_8 . V_9 , 0 )
!= F_16 ( V_2 -> V_8 . V_11 + V_2 -> V_8 . V_9 ) )
return V_17 ;
V_2 -> V_8 . V_10 = 2 ;
#ifdef F_5
if ( V_2 -> V_8 . V_11 [ 1 ] & 0x3E )
#else
if ( V_2 -> V_8 . V_11 [ 1 ] & 0x3F )
#endif
return V_50 ;
if ( V_2 -> V_8 . V_11 [ 1 ] & 0x40 ) {
if ( F_3 ( V_2 , V_2 -> V_8 . V_11 , & V_2 -> V_8 . V_10 , V_2 -> V_8 . V_9 )
!= V_18 )
return V_17 ;
V_2 -> V_31 . V_29 = V_2 -> V_15 ;
} else {
V_2 -> V_31 . V_29 = V_36 ;
}
if ( V_2 -> V_8 . V_11 [ 1 ] & 0x80 ) {
if ( F_3 ( V_2 , V_2 -> V_8 . V_11 , & V_2 -> V_8 . V_10 , V_2 -> V_8 . V_9 )
!= V_18 )
return V_17 ;
V_2 -> V_31 . V_30 = V_2 -> V_15 ;
} else {
V_2 -> V_31 . V_30 = V_36 ;
}
#ifdef F_5
V_2 -> V_25 = V_2 -> V_8 . V_11 [ 1 ] & 0x01 ;
if ( V_2 -> V_25 ) {
if ( V_2 -> V_8 . V_9 - V_2 -> V_8 . V_10 < 2 )
return V_50 ;
V_21 = F_19 ( V_2 -> V_26 , V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ++ ] ) ;
if ( V_21 != V_20 )
return V_21 ;
if ( V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ++ ] != 0x00 )
return V_50 ;
}
#endif
if ( V_2 -> V_8 . V_9 - V_2 -> V_8 . V_10 < 2 )
return V_17 ;
if ( V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ++ ] != 0x21 )
return V_50 ;
if ( V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ++ ] != 0x01 )
return V_50 ;
if ( V_2 -> V_8 . V_9 - V_2 -> V_8 . V_10 < 1 )
return V_17 ;
V_21 = F_20 ( V_2 -> V_27 , V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ++ ] ) ;
if ( V_21 != V_20 )
return V_21 ;
while ( V_2 -> V_8 . V_10 < V_2 -> V_8 . V_9 )
if ( V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ++ ] != 0x00 )
return V_50 ;
V_2 -> V_8 . V_10 = 0 ;
V_2 -> V_28 . V_29 = 0 ;
V_2 -> V_28 . V_30 = 0 ;
return V_20 ;
}
static enum V_13 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
enum V_13 V_21 ;
V_2 -> V_22 = V_4 -> V_7 ;
while ( true ) {
switch ( V_2 -> V_43 ) {
case V_55 :
if ( ! F_1 ( V_2 , V_4 ) )
return V_20 ;
V_2 -> V_43 = V_56 ;
V_21 = F_14 ( V_2 ) ;
if ( V_21 != V_20 )
return V_21 ;
case V_56 :
if ( V_4 -> V_7 == V_4 -> V_6 )
return V_20 ;
if ( V_4 -> V_12 [ V_4 -> V_7 ] == 0 ) {
V_2 -> V_22 = V_4 -> V_7 ++ ;
V_2 -> V_43 = V_57 ;
break;
}
V_2 -> V_31 . V_9
= ( ( V_58 ) V_4 -> V_12 [ V_4 -> V_7 ] + 1 ) * 4 ;
V_2 -> V_8 . V_9 = V_2 -> V_31 . V_9 ;
V_2 -> V_8 . V_10 = 0 ;
V_2 -> V_43 = V_59 ;
case V_59 :
if ( ! F_1 ( V_2 , V_4 ) )
return V_20 ;
V_21 = F_18 ( V_2 ) ;
if ( V_21 != V_20 )
return V_21 ;
V_2 -> V_43 = V_60 ;
case V_60 :
V_21 = F_4 ( V_2 , V_4 ) ;
if ( V_21 != V_18 )
return V_21 ;
V_2 -> V_43 = V_61 ;
case V_61 :
while ( V_2 -> V_28 . V_29 & 3 ) {
if ( V_4 -> V_7 == V_4 -> V_6 )
return V_20 ;
if ( V_4 -> V_12 [ V_4 -> V_7 ++ ] != 0 )
return V_17 ;
++ V_2 -> V_28 . V_29 ;
}
V_2 -> V_43 = V_62 ;
case V_62 :
if ( V_2 -> V_32 == V_33 ) {
V_21 = F_12 ( V_2 , V_4 ) ;
if ( V_21 != V_18 )
return V_21 ;
}
#ifdef F_9
else if ( ! F_13 ( V_2 , V_4 ) ) {
return V_20 ;
}
#endif
V_2 -> V_43 = V_56 ;
break;
case V_57 :
V_21 = F_11 ( V_2 , V_4 ) ;
if ( V_21 != V_18 )
return V_21 ;
V_2 -> V_43 = V_63 ;
case V_63 :
while ( ( V_2 -> V_42 . V_9 + ( V_4 -> V_7 - V_2 -> V_22 ) )
& 3 ) {
if ( V_4 -> V_7 == V_4 -> V_6 ) {
F_10 ( V_2 , V_4 ) ;
return V_20 ;
}
if ( V_4 -> V_12 [ V_4 -> V_7 ++ ] != 0 )
return V_17 ;
}
F_10 ( V_2 , V_4 ) ;
if ( ! F_15 ( & V_2 -> V_28 . V_37 , & V_2 -> V_42 . V_37 ,
sizeof( V_2 -> V_28 . V_37 ) ) )
return V_17 ;
V_2 -> V_43 = V_64 ;
case V_64 :
V_21 = F_12 ( V_2 , V_4 ) ;
if ( V_21 != V_18 )
return V_21 ;
V_2 -> V_8 . V_9 = V_65 ;
V_2 -> V_43 = V_66 ;
case V_66 :
if ( ! F_1 ( V_2 , V_4 ) )
return V_20 ;
return F_17 ( V_2 ) ;
}
}
}
T_3 enum V_13 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_22 ;
T_1 V_23 ;
enum V_13 V_21 ;
if ( F_23 ( V_2 -> V_67 ) )
F_24 ( V_2 ) ;
V_22 = V_4 -> V_7 ;
V_23 = V_4 -> V_24 ;
V_21 = F_21 ( V_2 , V_4 ) ;
if ( F_23 ( V_2 -> V_67 ) ) {
if ( V_21 == V_20 )
V_21 = V_4 -> V_7 == V_4 -> V_6
? V_17 : V_68 ;
if ( V_21 != V_18 ) {
V_4 -> V_7 = V_22 ;
V_4 -> V_24 = V_23 ;
}
} else if ( V_21 == V_20 && V_22 == V_4 -> V_7
&& V_23 == V_4 -> V_24 ) {
if ( V_2 -> V_69 )
V_21 = V_68 ;
V_2 -> V_69 = true ;
} else {
V_2 -> V_69 = false ;
}
return V_21 ;
}
T_3 struct V_1 * F_25 ( enum V_70 V_67 , V_58 V_71 )
{
struct V_1 * V_2 = F_26 ( sizeof( * V_2 ) , V_72 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_67 = V_67 ;
#ifdef F_5
V_2 -> V_26 = F_27 ( F_23 ( V_67 ) ) ;
if ( V_2 -> V_26 == NULL )
goto V_73;
#endif
V_2 -> V_27 = F_28 ( V_67 , V_71 ) ;
if ( V_2 -> V_27 == NULL )
goto V_74;
F_24 ( V_2 ) ;
return V_2 ;
V_74:
#ifdef F_5
F_29 ( V_2 -> V_26 ) ;
V_73:
#endif
F_30 ( V_2 ) ;
return NULL ;
}
T_3 void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_43 = V_55 ;
V_2 -> V_69 = false ;
V_2 -> V_10 = 0 ;
V_2 -> V_34 = 0 ;
F_31 ( & V_2 -> V_28 , sizeof( V_2 -> V_28 ) ) ;
F_31 ( & V_2 -> V_42 , sizeof( V_2 -> V_42 ) ) ;
V_2 -> V_8 . V_10 = 0 ;
V_2 -> V_8 . V_9 = V_65 ;
}
T_3 void F_32 ( struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_33 ( V_2 -> V_27 ) ;
#ifdef F_5
F_29 ( V_2 -> V_26 ) ;
#endif
F_30 ( V_2 ) ;
}
}
