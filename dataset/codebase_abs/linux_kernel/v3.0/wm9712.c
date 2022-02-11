static inline void F_1 ( int V_1 )
{
F_2 ( 3 * V_2 + V_3 [ V_1 ] ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
T_1 V_6 = 0 ;
T_1 V_7 = V_8 | F_4 ( 1 ) ;
if ( V_9 ) {
V_7 &= 0xffc0 ;
V_7 |= F_4 ( V_9 ) ;
F_5 ( V_5 -> V_10 , L_1 ,
64000 / V_9 ) ;
}
if ( V_11 ) {
V_7 |= V_12 ;
F_5 ( V_5 -> V_10 , L_2 ) ;
if ( V_13 ) {
F_6 ( V_5 -> V_10 , L_3
L_4 ) ;
V_13 = 0 ;
}
}
if ( V_13 == 2 ) {
V_7 |= V_14 ;
F_5 ( V_5 -> V_10 ,
L_5 ) ;
} else if ( V_13 )
F_5 ( V_5 -> V_10 ,
L_6 ) ;
if ( ! V_13 )
V_15 = 0 ;
if ( V_16 < 0 || V_16 > 15 ) {
F_5 ( V_5 -> V_10 , L_7 ) ;
V_16 = 4 ;
}
V_6 &= 0xff0f ;
V_6 |= F_7 ( V_16 ) ;
F_5 ( V_5 -> V_10 , L_8 ,
V_3 [ V_16 ] ) ;
V_7 |= ( ( V_17 & 0x3 ) << 6 ) ;
if ( V_17 ) {
T_1 V_18 ;
V_18 = F_8 ( V_5 , V_19 ) ;
F_9 ( V_5 , V_19 , V_18 | V_20 ) ;
V_18 = F_8 ( V_5 , V_21 ) ;
F_9 ( V_5 , V_21 , V_18 | V_20 ) ;
}
if ( V_22 )
V_7 |= V_23 ;
F_9 ( V_5 , V_24 , V_6 ) ;
F_9 ( V_5 , V_25 , V_7 ) ;
}
static void F_10 ( struct V_4 * V_5 , int V_26 )
{
T_1 V_7 = V_5 -> V_27 [ 2 ] ;
if ( V_26 ) {
F_9 ( V_5 , V_25 ,
V_7 | V_28 ) ;
F_8 ( V_5 , V_29 ) ;
} else
F_9 ( V_5 , V_25 ,
V_7 & ~ V_28 ) ;
}
static void F_11 ( struct V_4 * V_5 )
{
memcpy ( V_5 -> V_30 , V_5 -> V_27 , sizeof( V_5 -> V_27 ) ) ;
F_9 ( V_5 , V_24 , 0 ) ;
F_9 ( V_5 , V_25 , V_28 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_9 ( V_5 , V_24 , V_5 -> V_30 [ 1 ] ) ;
F_9 ( V_5 , V_25 , V_5 -> V_30 [ 2 ] ) ;
}
static inline int F_13 ( struct V_4 * V_5 )
{
return V_5 -> V_27 [ 2 ] & V_31 ;
}
static int F_14 ( struct V_4 * V_5 , int V_32 , int * V_33 )
{
int V_34 = 5 * V_16 ;
if ( ! V_5 -> V_35 ) {
T_1 V_36 = F_8 ( V_5 , V_29 ) ;
if ( ! ( V_36 & V_37 ) )
return V_38 ;
V_5 -> V_35 = 1 ;
}
if ( V_32 & 0x8000 )
V_32 = ( ( V_32 & 0x7fff ) + 3 ) << 12 ;
if ( V_5 -> V_39 && V_5 -> V_39 -> V_40 )
V_5 -> V_39 -> V_40 ( V_32 ) ;
F_9 ( V_5 , V_24 ,
V_32 | V_41 | F_7 ( V_16 ) ) ;
F_1 ( V_16 ) ;
while ( ( F_8 ( V_5 , V_24 ) & V_41 )
&& V_34 ) {
F_2 ( V_2 ) ;
V_34 -- ;
}
if ( V_34 <= 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_35 = 0 ;
else
F_5 ( V_5 -> V_10 , L_9 ) ;
return V_38 ;
}
* V_33 = F_8 ( V_5 , V_29 ) ;
if ( V_5 -> V_39 && V_5 -> V_39 -> V_42 )
V_5 -> V_39 -> V_42 ( V_32 ) ;
if ( ( * V_33 & V_43 ) != V_32 ) {
F_5 ( V_5 -> V_10 , L_10 , V_32 ,
* V_33 & V_43 ) ;
return V_38 ;
}
if ( ! ( * V_33 & V_37 ) ) {
V_5 -> V_35 = 0 ;
return V_38 ;
}
return V_44 ;
}
static int F_15 ( struct V_4 * V_5 , struct V_45 * V_36 )
{
int V_34 = 5 * V_16 ;
if ( ! V_5 -> V_35 ) {
T_1 V_46 = F_8 ( V_5 , V_29 ) ;
if ( ! ( V_46 & V_37 ) )
return V_38 ;
V_5 -> V_35 = 1 ;
}
if ( V_5 -> V_39 && V_5 -> V_39 -> V_40 )
V_5 -> V_39 -> V_40 ( V_47 | V_48 ) ;
F_9 ( V_5 , V_24 ,
V_49 | V_41 | F_7 ( V_16 ) ) ;
F_1 ( V_16 ) ;
V_36 -> V_50 = F_8 ( V_5 , V_29 ) ;
while ( ( F_8 ( V_5 , V_24 ) & V_41 )
&& V_34 ) {
F_2 ( V_2 ) ;
V_34 -- ;
}
if ( V_34 <= 0 ) {
if ( F_13 ( V_5 ) )
V_5 -> V_35 = 0 ;
else
F_5 ( V_5 -> V_10 , L_9 ) ;
return V_38 ;
}
V_36 -> V_51 = F_8 ( V_5 , V_29 ) ;
if ( V_13 )
V_36 -> V_52 = F_8 ( V_5 , V_29 ) ;
else
V_36 -> V_52 = V_53 ;
if ( V_5 -> V_39 && V_5 -> V_39 -> V_42 )
V_5 -> V_39 -> V_42 ( V_47 | V_48 ) ;
if ( ! ( V_36 -> V_50 & V_47 ) || ! ( V_36 -> V_51 & V_48 ) )
goto V_54;
if ( V_13 && ! ( V_36 -> V_52 & V_55 ) )
goto V_54;
if ( ! ( V_36 -> V_50 & V_37 ) || ! ( V_36 -> V_51 & V_37 ) ) {
V_5 -> V_35 = 0 ;
return V_38 ;
}
return V_44 ;
V_54:
return 0 ;
}
static int F_16 ( struct V_4 * V_5 , struct V_45 * V_36 )
{
int V_56 ;
if ( V_22 ) {
V_56 = F_15 ( V_5 , V_36 ) ;
if ( V_56 != V_44 )
return V_56 ;
} else {
V_56 = F_14 ( V_5 , V_47 , & V_36 -> V_50 ) ;
if ( V_56 != V_44 )
return V_56 ;
V_56 = F_14 ( V_5 , V_48 , & V_36 -> V_51 ) ;
if ( V_56 != V_44 )
return V_56 ;
if ( V_13 && ! V_11 ) {
V_56 = F_14 ( V_5 , V_55 ,
& V_36 -> V_52 ) ;
if ( V_56 != V_44 )
return V_56 ;
} else
V_36 -> V_52 = V_53 ;
}
return V_44 ;
}
static int F_17 ( struct V_4 * V_5 , int V_26 )
{
T_1 V_6 , V_7 ;
int V_57 = 0 ;
V_6 = V_5 -> V_27 [ 1 ] ;
V_7 = V_5 -> V_27 [ 2 ] ;
if ( V_26 ) {
if ( V_5 -> V_39 -> V_58 ) {
V_57 = V_5 -> V_39 -> V_58 ( V_5 ) ;
if ( V_57 < 0 )
return V_57 ;
}
V_6 &= ~ ( V_59 | V_43 |
V_60 | V_61 ) ;
V_6 |= V_62 | V_49 | V_63 |
F_7 ( V_16 ) |
F_18 ( V_5 -> V_64 ) |
F_19 ( V_5 -> V_65 ) ;
if ( V_13 )
V_6 |= V_55 ;
V_7 |= V_31 ;
} else {
V_6 &= ~ ( V_62 | V_49 | V_63 ) ;
V_7 &= ~ V_31 ;
if ( V_5 -> V_39 -> V_66 )
V_5 -> V_39 -> V_66 ( V_5 ) ;
}
F_9 ( V_5 , V_24 , V_6 ) ;
F_9 ( V_5 , V_25 , V_7 ) ;
return 0 ;
}
