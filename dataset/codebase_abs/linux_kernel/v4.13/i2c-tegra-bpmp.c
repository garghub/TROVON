static int F_1 ( T_1 V_1 , T_1 * V_2 )
{
if ( V_1 & V_3 ) {
* V_2 |= V_4 ;
V_1 &= ~ V_3 ;
}
if ( V_1 & V_5 ) {
* V_2 |= V_6 ;
V_1 &= ~ V_5 ;
}
if ( V_1 & V_7 ) {
* V_2 |= V_8 ;
V_1 &= ~ V_7 ;
}
if ( V_1 & V_9 ) {
* V_2 |= V_10 ;
V_1 &= ~ V_9 ;
}
if ( V_1 & V_11 ) {
* V_2 |= V_12 ;
V_1 &= ~ V_11 ;
}
if ( V_1 & V_13 ) {
* V_2 |= V_14 ;
V_1 &= ~ V_13 ;
}
if ( V_1 & V_15 ) {
* V_2 |= V_16 ;
V_1 &= ~ V_15 ;
}
if ( V_1 & V_17 ) {
* V_2 |= V_18 ;
V_1 &= ~ V_17 ;
}
return ( V_1 != 0 ) ? - V_19 : 0 ;
}
static int F_2 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_24 * V_25 ,
unsigned int V_26 )
{
char * V_27 = V_23 -> V_28 . V_29 ;
unsigned int V_30 , V_31 , V_32 = 0 ;
int V_33 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ ) {
struct V_24 * V_34 = & V_25 [ V_30 ] ;
T_1 V_1 = 0 ;
V_33 = F_1 ( V_34 -> V_1 , & V_1 ) ;
if ( V_33 < 0 )
return V_33 ;
V_27 [ V_32 ++ ] = V_34 -> V_35 & 0xff ;
V_27 [ V_32 ++ ] = ( V_34 -> V_35 & 0xff00 ) >> 8 ;
V_27 [ V_32 ++ ] = V_1 & 0xff ;
V_27 [ V_32 ++ ] = ( V_1 & 0xff00 ) >> 8 ;
V_27 [ V_32 ++ ] = V_34 -> V_36 & 0xff ;
V_27 [ V_32 ++ ] = ( V_34 -> V_36 & 0xff00 ) >> 8 ;
if ( ( V_1 & V_6 ) == 0 ) {
for ( V_31 = 0 ; V_31 < V_34 -> V_36 ; V_31 ++ )
V_27 [ V_32 ++ ] = V_34 -> V_27 [ V_31 ] ;
}
}
V_23 -> V_28 . V_37 = V_32 ;
return 0 ;
}
static int F_3 ( struct V_20 * V_21 ,
struct V_38 * V_39 ,
struct V_24 * V_25 ,
unsigned int V_26 )
{
T_2 V_40 = V_39 -> V_28 . V_37 , V_36 = 0 , V_32 = 0 ;
char * V_27 = V_39 -> V_28 . V_29 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
if ( V_25 [ V_30 ] . V_1 & V_5 )
V_36 += V_25 [ V_30 ] . V_36 ;
if ( V_36 != V_40 )
return - V_19 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ ) {
if ( V_25 [ V_30 ] . V_1 & V_5 ) {
memcpy ( V_25 [ V_30 ] . V_27 , V_27 + V_32 , V_25 [ V_30 ] . V_36 ) ;
V_32 += V_25 [ V_30 ] . V_36 ;
}
}
return 0 ;
}
static int F_4 ( struct V_24 * V_25 , unsigned int V_26 )
{
T_2 V_41 = 0 , V_42 = 0 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
if ( ! ( V_25 [ V_30 ] . V_1 & V_5 ) )
V_41 += V_43 + V_25 [ V_30 ] . V_36 ;
if ( V_41 > V_44 )
return - V_19 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ )
if ( ( V_25 [ V_30 ] . V_1 & V_5 ) )
V_42 += V_25 [ V_30 ] . V_36 ;
if ( V_42 > V_45 )
return - V_19 ;
return 0 ;
}
static int F_5 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
struct V_38 * V_39 )
{
struct V_46 V_34 ;
int V_33 ;
V_23 -> V_47 = V_48 ;
V_23 -> V_28 . V_49 = V_21 -> V_50 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_51 = V_52 ;
V_34 . V_53 . V_54 = V_23 ;
V_34 . V_53 . V_40 = sizeof( * V_23 ) ;
V_34 . V_55 . V_54 = V_39 ;
V_34 . V_55 . V_40 = sizeof( * V_39 ) ;
if ( F_6 () )
V_33 = F_7 ( V_21 -> V_56 , & V_34 ) ;
else
V_33 = F_8 ( V_21 -> V_56 , & V_34 ) ;
return V_33 ;
}
static int F_9 ( struct V_57 * V_58 ,
struct V_24 * V_25 , int V_26 )
{
struct V_20 * V_21 = F_10 ( V_58 ) ;
struct V_38 V_39 ;
struct V_22 V_23 ;
int V_33 ;
V_33 = F_4 ( V_25 , V_26 ) ;
if ( V_33 < 0 ) {
F_11 ( V_21 -> V_59 , L_1 ) ;
return V_33 ;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_33 = F_2 ( V_21 , & V_23 , V_25 , V_26 ) ;
if ( V_33 < 0 ) {
F_11 ( V_21 -> V_59 , L_2 , V_33 ) ;
return V_33 ;
}
V_33 = F_5 ( V_21 , & V_23 , & V_39 ) ;
if ( V_33 < 0 ) {
F_11 ( V_21 -> V_59 , L_3 , V_33 ) ;
return V_33 ;
}
V_33 = F_3 ( V_21 , & V_39 , V_25 , V_26 ) ;
if ( V_33 < 0 ) {
F_11 ( V_21 -> V_59 , L_4 , V_33 ) ;
return V_33 ;
}
return V_26 ;
}
static T_3 F_12 ( struct V_57 * V_58 )
{
return V_60 | V_61 | V_62 |
V_63 | V_64 ;
}
static int F_13 ( struct V_65 * V_66 )
{
struct V_20 * V_21 ;
T_3 V_67 ;
int V_33 ;
V_21 = F_14 ( & V_66 -> V_59 , sizeof( * V_21 ) , V_68 ) ;
if ( ! V_21 )
return - V_69 ;
V_21 -> V_59 = & V_66 -> V_59 ;
V_21 -> V_56 = F_15 ( V_66 -> V_59 . V_70 ) ;
if ( ! V_21 -> V_56 )
return - V_71 ;
V_33 = F_16 ( V_66 -> V_59 . V_72 , L_5 ,
& V_67 ) ;
if ( V_33 < 0 )
return V_33 ;
V_21 -> V_50 = V_67 ;
F_17 ( & V_21 -> V_58 , V_21 ) ;
V_21 -> V_58 . V_73 = V_74 ;
F_18 ( V_21 -> V_58 . V_75 , L_6 ,
sizeof( V_21 -> V_58 . V_75 ) ) ;
V_21 -> V_58 . V_76 = & V_77 ;
V_21 -> V_58 . V_59 . V_70 = & V_66 -> V_59 ;
V_21 -> V_58 . V_59 . V_72 = V_66 -> V_59 . V_72 ;
F_19 ( V_66 , V_21 ) ;
return F_20 ( & V_21 -> V_58 ) ;
}
static int F_21 ( struct V_65 * V_66 )
{
struct V_20 * V_21 = F_22 ( V_66 ) ;
F_23 ( & V_21 -> V_58 ) ;
return 0 ;
}
