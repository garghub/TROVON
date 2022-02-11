static inline int F_1 ( T_1 V_1 )
{
return F_2 ( ( ( V_2 ) V_1 / 16 ) * 625 , 10 ) ;
}
static inline T_1 F_3 ( long V_3 , T_2 V_4 )
{
V_3 = F_4 ( V_3 , V_5 , V_6 ) ;
V_3 = F_2 ( V_3 * ( 1 << ( 8 - V_4 ) ) , 1000 ) << V_4 ;
return V_3 ;
}
static void F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
T_2 V_11 , V_12 , V_13 , V_14 ;
V_12 = V_11 = F_6 ( V_10 , V_15 ) ;
V_12 &= ~ V_16 ;
if ( V_17 == 0 )
V_12 &= ~ V_18 ;
else if ( V_17 == 1 )
V_12 |= V_18 ;
if ( V_11 != V_12 )
F_7 ( V_10 , V_15 , V_12 ) ;
switch ( V_8 -> V_19 ) {
case V_20 :
V_8 -> V_21 = V_22 ;
V_8 -> V_4 = 7 ;
V_13 = V_23 ;
break;
case V_24 :
case V_25 :
case V_26 :
V_14 = ( V_12 & V_27 ) >>
V_28 ;
V_8 -> V_21 = V_29 [ V_14 ] ;
V_8 -> V_4 = 7 - V_14 ;
V_13 = V_30 ;
break;
default:
V_8 -> V_21 = V_31 ;
V_8 -> V_4 = 7 ;
V_13 = V_23 ;
break;
}
F_8 ( V_10 , V_13 ) ;
}
static struct V_7 * F_9 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_10 ( V_33 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_2 V_12 ;
F_11 ( & V_8 -> V_34 ) ;
if ( F_12 ( V_35 , V_8 -> V_36 + V_8 -> V_21 ) ||
! V_8 -> V_37 ) {
int V_38 ;
F_13 ( & V_10 -> V_33 , L_1 ) ;
V_8 -> V_11 = F_6 ( V_10 , V_15 ) ;
for ( V_38 = 0 ; V_38 < F_14 ( V_8 -> V_3 ) ; V_38 ++ )
V_8 -> V_3 [ V_38 ] = F_15 ( V_10 ,
V_39 [ V_38 ] ) ;
V_12 = V_8 -> V_11 ;
if ( V_8 -> V_3 [ 0 ] > V_8 -> V_3 [ 1 ] )
V_12 &= ~ V_40 ;
if ( V_8 -> V_3 [ 0 ] < V_8 -> V_3 [ 2 ] )
V_12 &= ~ V_41 ;
if ( V_8 -> V_11 != V_12 )
F_7 ( V_10 , V_15 ,
V_12 ) ;
V_8 -> V_36 = V_35 ;
V_8 -> V_37 = 1 ;
}
F_16 ( & V_8 -> V_34 ) ;
return V_8 ;
}
static T_3 F_17 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_45 * V_46 = F_18 ( V_43 ) ;
struct V_7 * V_8 = F_9 ( V_33 ) ;
return sprintf ( V_44 , L_2 ,
F_1 ( V_8 -> V_3 [ V_46 -> V_47 ] ) ) ;
}
static T_3 F_19 ( struct V_32 * V_33 , struct V_42 * V_43 ,
const char * V_44 , T_4 V_48 )
{
struct V_45 * V_46 = F_18 ( V_43 ) ;
struct V_7 * V_8 = F_10 ( V_33 ) ;
long V_49 ;
int V_50 ;
V_50 = F_20 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
F_11 ( & V_8 -> V_34 ) ;
V_8 -> V_3 [ V_46 -> V_47 ] = F_3 ( V_49 , V_8 -> V_4 ) ;
F_21 ( V_8 -> V_10 , V_39 [ V_46 -> V_47 ] ,
V_8 -> V_3 [ V_46 -> V_47 ] ) ;
F_16 ( & V_8 -> V_34 ) ;
return V_48 ;
}
static T_3 F_22 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_7 * V_8 = F_9 ( V_33 ) ;
return sprintf ( V_44 , L_2 , F_23 ( V_8 -> V_11 ) ) ;
}
static T_3 F_24 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_45 * V_46 = F_18 ( V_43 ) ;
struct V_7 * V_8 = F_9 ( V_33 ) ;
return sprintf ( V_44 , L_2 , ! ! ( V_8 -> V_11 & V_46 -> V_47 ) ) ;
}
static T_3 F_25 ( struct V_32 * V_33 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_7 * V_8 = F_10 ( V_33 ) ;
return F_26 ( V_44 , V_51 , L_3 , V_8 -> V_21 ) ;
}
static T_3 F_27 ( struct V_32 * V_33 ,
struct V_42 * V_43 ,
const char * V_44 , T_4 V_48 )
{
struct V_7 * V_8 = F_10 ( V_33 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
unsigned long V_52 ;
T_5 V_50 ;
int V_14 = 0 ;
V_50 = F_28 ( V_44 , 10 , & V_52 ) ;
if ( V_50 )
return V_50 ;
while ( V_14 < ( F_14 ( V_29 ) - 1 ) &&
V_52 > V_29 [ V_14 ] )
V_14 ++ ;
F_11 ( & V_8 -> V_34 ) ;
V_8 -> V_11 = F_6 ( V_10 , V_15 ) ;
V_8 -> V_11 &= ~ V_27 ;
V_8 -> V_11 |= ( V_14 << V_28 ) ;
F_7 ( V_10 , V_15 , V_8 -> V_11 ) ;
V_8 -> V_21 = V_29 [ V_14 ] ;
V_8 -> V_4 = 7 - V_14 ;
F_16 ( & V_8 -> V_34 ) ;
return V_48 ;
}
static T_6 F_29 ( struct V_53 * V_54 ,
struct V_55 * V_46 , int V_47 )
{
struct V_32 * V_33 = F_30 ( V_54 , struct V_32 , V_54 ) ;
struct V_7 * V_8 = F_10 ( V_33 ) ;
if ( V_46 == & V_56 . V_46 )
if ( V_8 -> V_19 == V_57 || V_8 -> V_19 == V_20 )
return 0 ;
return V_46 -> V_58 ;
}
static int F_31 ( struct V_9 * V_10 ,
const struct V_59 * V_60 )
{
struct V_7 * V_8 ;
struct V_32 * V_61 ;
V_8 = F_32 ( & V_10 -> V_33 , sizeof( struct V_7 ) ,
V_62 ) ;
if ( ! V_8 )
return - V_63 ;
F_33 ( & V_8 -> V_34 ) ;
V_8 -> V_19 = V_60 -> V_64 ;
V_8 -> V_10 = V_10 ;
F_5 ( V_8 , V_10 ) ;
V_61 = F_34 ( & V_10 -> V_33 ,
V_10 -> V_65 , V_8 ,
V_66 ) ;
return F_35 ( V_61 ) ;
}
