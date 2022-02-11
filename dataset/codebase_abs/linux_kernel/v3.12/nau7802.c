static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = 0 ;
V_4 = F_3 ( V_2 -> V_7 , V_8 ) ;
if ( V_4 < 0 )
goto V_9;
V_4 = F_4 ( V_2 -> V_7 , V_8 ,
( V_4 & ( ~ V_10 ) ) |
V_3 ) ;
V_9:
F_5 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_11 ;
F_2 ( & V_2 -> V_12 ) ;
V_11 = F_3 ( V_2 -> V_7 , V_13 ) ;
if ( V_11 < 0 )
goto V_14;
V_2 -> V_15 = V_11 << 16 ;
V_11 = F_3 ( V_2 -> V_7 , V_16 ) ;
if ( V_11 < 0 )
goto V_14;
V_2 -> V_15 |= V_11 << 8 ;
V_11 = F_3 ( V_2 -> V_7 , V_17 ) ;
if ( V_11 < 0 )
goto V_14;
V_2 -> V_15 |= V_11 ;
V_2 -> V_15 = F_7 ( V_2 -> V_15 , 23 ) ;
V_14:
F_5 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_3 ( V_2 -> V_7 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 -> V_7 , V_18 ,
V_4 | V_19 ) ;
return V_4 ;
}
static T_1 F_9 ( int V_20 , void * V_21 )
{
struct V_22 * V_23 = V_21 ;
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_24 ;
V_24 = F_3 ( V_2 -> V_7 , V_18 ) ;
if ( V_24 < 0 )
return V_25 ;
if ( ! ( V_24 & V_26 ) )
return V_27 ;
if ( F_6 ( V_2 ) < 0 )
return V_25 ;
if ( V_2 -> V_6 < V_28 )
V_2 -> V_6 ++ ;
if ( V_2 -> V_6 >= V_28 )
F_11 ( & V_2 -> V_29 ) ;
return V_25 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_30 const * V_31 ,
int * V_32 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_4 ;
F_13 ( V_2 -> V_29 ) ;
F_14 ( V_2 -> V_7 -> V_20 ) ;
F_8 ( V_2 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 < 0 )
goto V_33;
V_4 = F_15 ( & V_2 -> V_29 ,
F_16 ( 1000 ) ) ;
if ( V_4 == 0 )
V_4 = - V_34 ;
if ( V_4 < 0 )
goto V_33;
F_17 ( V_2 -> V_7 -> V_20 ) ;
* V_32 = V_2 -> V_15 ;
return V_35 ;
V_33:
F_17 ( V_2 -> V_7 -> V_20 ) ;
return V_4 ;
}
static int F_18 ( struct V_22 * V_23 ,
struct V_30 const * V_31 ,
int * V_32 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_4 ;
F_8 ( V_2 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
do {
V_4 = F_3 ( V_2 -> V_7 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
while ( ! ( V_4 & V_26 ) ) {
if ( V_2 -> V_36 != V_37 )
F_19 ( 20 ) ;
else
F_20 ( 4 ) ;
V_4 = F_3 ( V_2 -> V_7 ,
V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_4 = F_6 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_2 -> V_6 < V_28 )
V_2 -> V_6 ++ ;
} while ( V_2 -> V_6 < V_28 );
* V_32 = V_2 -> V_15 ;
return V_35 ;
}
static int F_21 ( struct V_22 * V_23 ,
struct V_30 const * V_31 ,
int * V_32 , int * V_38 , long V_39 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_4 ;
switch ( V_39 ) {
case V_40 :
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_7 , V_41 ) ;
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_5 ) ;
return V_4 ;
}
if ( ( ( V_4 & V_42 ) && ! V_31 -> V_43 ) ||
( ! ( V_4 & V_42 ) &&
V_31 -> V_43 ) ) {
V_2 -> V_6 = 0 ;
V_4 = F_4 ( V_2 -> V_7 ,
V_41 ,
F_22 ( V_31 -> V_43 ) |
F_23 ( V_2 -> V_36 ) ) ;
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_5 ) ;
return V_4 ;
}
}
if ( V_2 -> V_7 -> V_20 )
V_4 = F_12 ( V_23 , V_31 , V_32 ) ;
else
V_4 = F_18 ( V_23 , V_31 , V_32 ) ;
F_5 ( & V_2 -> V_5 ) ;
return V_4 ;
case V_44 :
V_4 = F_3 ( V_2 -> V_7 , V_8 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_32 = V_2 -> V_45 ;
* V_38 = 23 + ( V_4 & V_10 ) ;
return V_46 ;
case V_47 :
* V_32 = V_48 [ V_2 -> V_36 ] ;
* V_38 = 0 ;
return V_35 ;
default:
break;
}
return - V_49 ;
}
static int F_24 ( struct V_22 * V_23 ,
struct V_30 const * V_31 ,
int V_32 , int V_38 , long V_39 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
int V_50 , V_4 ;
switch ( V_39 ) {
case V_44 :
for ( V_50 = 0 ; V_50 < F_25 ( V_2 -> V_51 ) ; V_50 ++ )
if ( V_38 == V_2 -> V_51 [ V_50 ] )
return F_1 ( V_2 , V_50 ) ;
break;
case V_47 :
for ( V_50 = 0 ; V_50 < F_25 ( V_48 ) ; V_50 ++ )
if ( V_32 == V_48 [ V_50 ] ) {
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_36 = V_50 ;
V_2 -> V_6 = 0 ;
V_4 = F_4 ( V_2 -> V_7 ,
V_41 ,
F_23 ( V_2 -> V_36 ) ) ;
F_5 ( & V_2 -> V_5 ) ;
return V_4 ;
}
break;
default:
break;
}
return - V_49 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_30 const * V_31 ,
long V_39 )
{
return V_52 ;
}
static int F_27 ( struct V_53 * V_7 ,
const struct V_54 * V_55 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_56 * V_57 = V_7 -> V_58 . V_59 ;
int V_50 , V_4 ;
T_2 V_11 ;
T_3 V_60 = 0 ;
if ( ! V_7 -> V_58 . V_59 ) {
F_28 ( & V_7 -> V_58 , L_1 ) ;
return - V_49 ;
}
V_23 = F_29 ( & V_7 -> V_58 , sizeof( * V_2 ) ) ;
if ( V_23 == NULL )
return - V_61 ;
V_2 = F_10 ( V_23 ) ;
F_30 ( V_7 , V_23 ) ;
V_23 -> V_58 . V_62 = & V_7 -> V_58 ;
V_23 -> V_63 = F_31 ( & V_7 -> V_58 ) ;
V_23 -> V_64 = V_65 ;
V_23 -> V_66 = & V_67 ;
V_2 -> V_7 = V_7 ;
V_4 = F_4 ( V_2 -> V_7 , V_18 ,
V_68 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 -> V_7 , V_18 ,
V_69 ) ;
if ( V_4 < 0 )
return V_4 ;
F_32 ( 210 ) ;
V_4 = F_3 ( V_2 -> V_7 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_70 ) )
return V_4 ;
F_33 ( V_57 , L_2 , & V_60 ) ;
V_2 -> V_45 = V_60 ;
V_11 = V_69 | V_71 |
V_19 ;
if ( V_60 >= 2400 )
V_11 |= V_72 ;
V_4 = F_4 ( V_2 -> V_7 , V_18 , V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 -> V_7 , V_73 , 0x30 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_60 >= 2400 ) {
V_11 = F_34 ( ( 4500 - V_60 ) / 300 ) ;
V_4 = F_4 ( V_2 -> V_7 , V_8 ,
V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
}
for ( V_50 = 0 ; V_50 < F_25 ( V_2 -> V_51 ) ; V_50 ++ )
V_2 -> V_51 [ V_50 ] = ( ( ( V_74 ) V_2 -> V_45 ) * 1000000000ULL )
>> ( 23 + V_50 ) ;
F_35 ( & V_2 -> V_29 ) ;
if ( V_7 -> V_20 ) {
V_4 = F_36 ( V_7 -> V_20 ,
NULL ,
F_9 ,
V_75 | V_76 ,
V_7 -> V_58 . V_77 -> V_63 ,
V_23 ) ;
if ( V_4 ) {
F_37 ( & V_7 -> V_58 ,
L_3 ) ;
V_7 -> V_20 = 0 ;
} else
F_17 ( V_7 -> V_20 ) ;
}
if ( ! V_7 -> V_20 ) {
V_2 -> V_36 = V_37 ;
V_4 = F_4 ( V_2 -> V_7 , V_41 ,
F_23 ( V_2 -> V_36 ) ) ;
if ( V_4 )
goto V_78;
}
V_23 -> V_79 = F_25 ( V_80 ) ;
V_23 -> V_81 = V_80 ;
F_38 ( & V_2 -> V_5 ) ;
F_38 ( & V_2 -> V_12 ) ;
V_4 = F_39 ( V_23 ) ;
if ( V_4 < 0 ) {
F_28 ( & V_7 -> V_58 , L_4 ) ;
goto V_82;
}
return 0 ;
V_82:
F_40 ( & V_2 -> V_5 ) ;
F_40 ( & V_2 -> V_12 ) ;
V_78:
if ( V_7 -> V_20 )
F_41 ( V_7 -> V_20 , V_23 ) ;
return V_4 ;
}
static int F_42 ( struct V_53 * V_7 )
{
struct V_22 * V_23 = F_43 ( V_7 ) ;
struct V_1 * V_2 = F_10 ( V_23 ) ;
F_44 ( V_23 ) ;
F_40 ( & V_2 -> V_5 ) ;
F_40 ( & V_2 -> V_12 ) ;
if ( V_7 -> V_20 )
F_41 ( V_7 -> V_20 , V_23 ) ;
return 0 ;
}
