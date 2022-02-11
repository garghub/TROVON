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
static void F_5 ( struct V_7 * V_8 )
{
T_2 V_9 , V_10 , V_11 , V_12 ;
struct V_13 * V_14 = F_6 ( V_8 ) ;
V_10 = V_9 = F_7 ( V_8 , V_15 ) ;
V_10 &= ~ V_16 ;
if ( V_17 == 0 )
V_10 &= ~ V_18 ;
else if ( V_17 == 1 )
V_10 |= V_18 ;
if ( V_9 != V_10 )
F_8 ( V_8 , V_15 , V_10 ) ;
switch ( V_14 -> V_19 ) {
case V_20 :
V_14 -> V_21 = V_22 ;
V_14 -> V_4 = 7 ;
V_11 = V_23 ;
break;
case V_24 :
case V_25 :
case V_26 :
V_12 = ( V_10 & V_27 ) >>
V_28 ;
V_14 -> V_21 = V_29 [ V_12 ] ;
V_14 -> V_4 = 7 - V_12 ;
V_11 = V_30 ;
break;
default:
V_14 -> V_21 = V_31 ;
V_14 -> V_4 = 7 ;
V_11 = V_23 ;
break;
}
F_9 ( V_8 , V_11 ) ;
}
static struct V_13 * F_10 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_11 ( V_33 ) ;
struct V_13 * V_14 = F_6 ( V_8 ) ;
T_2 V_10 ;
F_12 ( & V_14 -> V_34 ) ;
if ( F_13 ( V_35 , V_14 -> V_36 + V_14 -> V_21 ) ||
! V_14 -> V_37 ) {
int V_38 ;
F_14 ( & V_8 -> V_33 , L_1 ) ;
V_14 -> V_9 = F_7 ( V_8 , V_15 ) ;
for ( V_38 = 0 ; V_38 < F_15 ( V_14 -> V_3 ) ; V_38 ++ )
V_14 -> V_3 [ V_38 ] = F_16 ( V_8 ,
V_39 [ V_38 ] ) ;
V_10 = V_14 -> V_9 ;
if ( V_14 -> V_3 [ 0 ] > V_14 -> V_3 [ 1 ] )
V_10 &= ~ V_40 ;
if ( V_14 -> V_3 [ 0 ] < V_14 -> V_3 [ 2 ] )
V_10 &= ~ V_41 ;
if ( V_14 -> V_9 != V_10 )
F_8 ( V_8 , V_15 ,
V_10 ) ;
V_14 -> V_36 = V_35 ;
V_14 -> V_37 = 1 ;
}
F_17 ( & V_14 -> V_34 ) ;
return V_14 ;
}
static T_3 F_18 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_45 * V_46 = F_19 ( V_43 ) ;
struct V_13 * V_14 = F_10 ( V_33 ) ;
return sprintf ( V_44 , L_2 ,
F_1 ( V_14 -> V_3 [ V_46 -> V_47 ] ) ) ;
}
static T_3 F_20 ( struct V_32 * V_33 , struct V_42 * V_43 ,
const char * V_44 , T_4 V_48 )
{
struct V_45 * V_46 = F_19 ( V_43 ) ;
struct V_7 * V_8 = F_11 ( V_33 ) ;
struct V_13 * V_14 = F_6 ( V_8 ) ;
long V_49 ;
int V_50 ;
V_50 = F_21 ( V_44 , 10 , & V_49 ) ;
if ( V_50 )
return V_50 ;
F_12 ( & V_14 -> V_34 ) ;
V_14 -> V_3 [ V_46 -> V_47 ] = F_3 ( V_49 , V_14 -> V_4 ) ;
F_22 ( V_8 , V_39 [ V_46 -> V_47 ] ,
V_14 -> V_3 [ V_46 -> V_47 ] ) ;
F_17 ( & V_14 -> V_34 ) ;
return V_48 ;
}
static T_3 F_23 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_13 * V_14 = F_10 ( V_33 ) ;
return sprintf ( V_44 , L_2 , F_24 ( V_14 -> V_9 ) ) ;
}
static T_3 F_25 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_45 * V_46 = F_19 ( V_43 ) ;
struct V_13 * V_14 = F_10 ( V_33 ) ;
return sprintf ( V_44 , L_2 , ! ! ( V_14 -> V_9 & V_46 -> V_47 ) ) ;
}
static T_3 F_26 ( struct V_32 * V_33 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_7 * V_8 = F_11 ( V_33 ) ;
struct V_13 * V_14 = F_6 ( V_8 ) ;
return F_27 ( V_44 , V_51 , L_3 , V_14 -> V_21 ) ;
}
static T_3 F_28 ( struct V_32 * V_33 , struct V_42 * V_43 ,
const char * V_44 , T_4 V_48 )
{
struct V_7 * V_8 = F_11 ( V_33 ) ;
struct V_13 * V_14 = F_6 ( V_8 ) ;
unsigned long V_52 ;
T_5 V_50 ;
int V_12 = 0 ;
V_50 = F_29 ( V_44 , 10 , & V_52 ) ;
if ( V_50 )
return V_50 ;
while ( V_12 < ( F_15 ( V_29 ) - 1 ) &&
V_52 > V_29 [ V_12 ] )
V_12 ++ ;
F_12 ( & V_14 -> V_34 ) ;
V_14 -> V_9 = F_7 ( V_8 , V_15 ) ;
V_14 -> V_9 &= ~ V_27 ;
V_14 -> V_9 |= ( V_12 << V_28 ) ;
F_8 ( V_8 , V_15 , V_14 -> V_9 ) ;
V_14 -> V_21 = V_29 [ V_12 ] ;
F_17 ( & V_14 -> V_34 ) ;
return V_48 ;
}
static T_6 F_30 ( struct V_53 * V_54 ,
struct V_55 * V_46 , int V_47 )
{
struct V_32 * V_33 = F_31 ( V_54 , struct V_32 , V_54 ) ;
struct V_7 * V_8 = F_11 ( V_33 ) ;
struct V_13 * V_14 = F_6 ( V_8 ) ;
if ( V_46 == & V_56 . V_46 )
if ( V_14 -> V_19 == V_57 || V_14 -> V_19 == V_20 )
return 0 ;
return V_46 -> V_58 ;
}
static int F_32 ( struct V_7 * V_8 ,
const struct V_59 * V_60 )
{
struct V_13 * V_14 ;
int V_50 ;
V_14 = F_33 ( & V_8 -> V_33 , sizeof( struct V_13 ) ,
V_61 ) ;
if ( ! V_14 )
return - V_62 ;
F_34 ( V_8 , V_14 ) ;
F_35 ( & V_14 -> V_34 ) ;
V_14 -> V_19 = V_60 -> V_63 ;
F_5 ( V_8 ) ;
V_50 = F_36 ( & V_8 -> V_33 . V_54 , & V_64 ) ;
if ( V_50 )
return V_50 ;
V_14 -> V_65 = F_37 ( & V_8 -> V_33 ) ;
if ( F_38 ( V_14 -> V_65 ) ) {
V_50 = F_39 ( V_14 -> V_65 ) ;
goto V_66;
}
return 0 ;
V_66:
F_40 ( & V_8 -> V_33 . V_54 , & V_64 ) ;
return V_50 ;
}
static int F_41 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_6 ( V_8 ) ;
F_42 ( V_14 -> V_65 ) ;
F_40 ( & V_8 -> V_33 . V_54 , & V_64 ) ;
return 0 ;
}
