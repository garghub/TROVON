static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
int V_8 , V_9 = 0 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_7 -> V_10 ) ; V_8 ++ )
V_9 += F_5 ( V_5 + V_9 , V_11 - V_9 , L_1 ,
V_7 -> V_10 [ V_8 ] ) ;
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static int F_6 ( struct V_6 * V_7 , int V_12 )
{
int V_13 ;
F_7 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = 0 ;
V_13 = F_8 ( V_7 -> V_16 , V_17 ) ;
if ( V_13 < 0 )
goto V_18;
V_13 = F_9 ( V_7 -> V_16 , V_17 ,
( V_13 & ( ~ V_19 ) ) |
V_12 ) ;
V_18:
F_10 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static int F_11 ( struct V_6 * V_7 )
{
int V_20 ;
F_7 ( & V_7 -> V_21 ) ;
V_20 = F_8 ( V_7 -> V_16 , V_22 ) ;
if ( V_20 < 0 )
goto V_23;
V_7 -> V_24 = V_20 << 16 ;
V_20 = F_8 ( V_7 -> V_16 , V_25 ) ;
if ( V_20 < 0 )
goto V_23;
V_7 -> V_24 |= V_20 << 8 ;
V_20 = F_8 ( V_7 -> V_16 , V_26 ) ;
if ( V_20 < 0 )
goto V_23;
V_7 -> V_24 |= V_20 ;
V_7 -> V_24 = F_12 ( V_7 -> V_24 , 23 ) ;
V_23:
F_10 ( & V_7 -> V_21 ) ;
return V_20 ;
}
static int F_13 ( struct V_6 * V_7 )
{
int V_13 ;
V_13 = F_8 ( V_7 -> V_16 , V_27 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_7 -> V_16 , V_27 ,
V_13 | V_28 ) ;
return V_13 ;
}
static T_2 F_14 ( int V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_6 * V_7 = F_2 ( V_32 ) ;
int V_33 ;
V_33 = F_8 ( V_7 -> V_16 , V_27 ) ;
if ( V_33 < 0 )
return V_34 ;
if ( ! ( V_33 & V_35 ) )
return V_36 ;
if ( F_11 ( V_7 ) < 0 )
return V_34 ;
if ( V_7 -> V_15 < V_37 )
V_7 -> V_15 ++ ;
if ( V_7 -> V_15 >= V_37 )
F_15 ( & V_7 -> V_38 ) ;
return V_34 ;
}
static int F_16 ( struct V_31 * V_32 ,
struct V_39 const * V_40 ,
int * V_41 )
{
struct V_6 * V_7 = F_2 ( V_32 ) ;
int V_13 ;
F_17 ( & V_7 -> V_38 ) ;
F_18 ( V_7 -> V_16 -> V_29 ) ;
F_13 ( V_7 ) ;
V_13 = F_11 ( V_7 ) ;
if ( V_13 < 0 )
goto V_42;
V_13 = F_19 ( & V_7 -> V_38 ,
F_20 ( 1000 ) ) ;
if ( V_13 == 0 )
V_13 = - V_43 ;
if ( V_13 < 0 )
goto V_42;
F_21 ( V_7 -> V_16 -> V_29 ) ;
* V_41 = V_7 -> V_24 ;
return V_44 ;
V_42:
F_21 ( V_7 -> V_16 -> V_29 ) ;
return V_13 ;
}
static int F_22 ( struct V_31 * V_32 ,
struct V_39 const * V_40 ,
int * V_41 )
{
struct V_6 * V_7 = F_2 ( V_32 ) ;
int V_13 ;
F_13 ( V_7 ) ;
V_13 = F_11 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
do {
V_13 = F_8 ( V_7 -> V_16 , V_27 ) ;
if ( V_13 < 0 )
return V_13 ;
while ( ! ( V_13 & V_35 ) ) {
if ( V_7 -> V_45 != V_46 )
F_23 ( 20 ) ;
else
F_24 ( 4 ) ;
V_13 = F_8 ( V_7 -> V_16 ,
V_27 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_13 = F_11 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_7 -> V_15 < V_37 )
V_7 -> V_15 ++ ;
} while ( V_7 -> V_15 < V_37 );
* V_41 = V_7 -> V_24 ;
return V_44 ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_39 const * V_40 ,
int * V_41 , int * V_47 , long V_48 )
{
struct V_6 * V_7 = F_2 ( V_32 ) ;
int V_13 ;
switch ( V_48 ) {
case V_49 :
F_7 ( & V_7 -> V_14 ) ;
V_13 = F_8 ( V_7 -> V_16 , V_50 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_7 -> V_14 ) ;
return V_13 ;
}
if ( ( ( V_13 & V_51 ) && ! V_40 -> V_52 ) ||
( ! ( V_13 & V_51 ) &&
V_40 -> V_52 ) ) {
V_7 -> V_15 = 0 ;
V_13 = F_9 ( V_7 -> V_16 ,
V_50 ,
F_26 ( V_40 -> V_52 ) |
F_27 ( V_7 -> V_45 ) ) ;
if ( V_13 < 0 ) {
F_10 ( & V_7 -> V_14 ) ;
return V_13 ;
}
}
if ( V_7 -> V_16 -> V_29 )
V_13 = F_16 ( V_32 , V_40 , V_41 ) ;
else
V_13 = F_22 ( V_32 , V_40 , V_41 ) ;
F_10 ( & V_7 -> V_14 ) ;
return V_13 ;
case V_53 :
V_13 = F_8 ( V_7 -> V_16 , V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_41 = V_7 -> V_54 ;
* V_47 = 23 + ( V_13 & V_19 ) ;
return V_55 ;
case V_56 :
* V_41 = V_57 [ V_7 -> V_45 ] ;
* V_47 = 0 ;
return V_44 ;
default:
break;
}
return - V_58 ;
}
static int F_28 ( struct V_31 * V_32 ,
struct V_39 const * V_40 ,
int V_41 , int V_47 , long V_48 )
{
struct V_6 * V_7 = F_2 ( V_32 ) ;
int V_8 , V_13 ;
switch ( V_48 ) {
case V_53 :
for ( V_8 = 0 ; V_8 < F_4 ( V_7 -> V_10 ) ; V_8 ++ )
if ( V_47 == V_7 -> V_10 [ V_8 ] )
return F_6 ( V_7 , V_8 ) ;
break;
case V_56 :
for ( V_8 = 0 ; V_8 < F_4 ( V_57 ) ; V_8 ++ )
if ( V_41 == V_57 [ V_8 ] ) {
F_7 ( & V_7 -> V_14 ) ;
V_7 -> V_45 = V_8 ;
V_7 -> V_15 = 0 ;
V_13 = F_9 ( V_7 -> V_16 ,
V_50 ,
F_27 ( V_7 -> V_45 ) ) ;
F_10 ( & V_7 -> V_14 ) ;
return V_13 ;
}
break;
default:
break;
}
return - V_58 ;
}
static int F_29 ( struct V_31 * V_32 ,
struct V_39 const * V_40 ,
long V_48 )
{
return V_59 ;
}
static int F_30 ( struct V_60 * V_16 ,
const struct V_61 * V_62 )
{
struct V_31 * V_32 ;
struct V_6 * V_7 ;
struct V_63 * V_64 = V_16 -> V_2 . V_65 ;
int V_8 , V_13 ;
T_3 V_20 ;
T_4 V_66 = 0 ;
if ( ! V_16 -> V_2 . V_65 ) {
F_31 ( & V_16 -> V_2 , L_2 ) ;
return - V_58 ;
}
V_32 = F_32 ( & V_16 -> V_2 , sizeof( * V_7 ) ) ;
if ( V_32 == NULL )
return - V_67 ;
V_7 = F_2 ( V_32 ) ;
F_33 ( V_16 , V_32 ) ;
V_32 -> V_2 . V_68 = & V_16 -> V_2 ;
V_32 -> V_2 . V_65 = V_16 -> V_2 . V_65 ;
V_32 -> V_69 = F_34 ( & V_16 -> V_2 ) ;
V_32 -> V_70 = V_71 ;
V_32 -> V_72 = & V_73 ;
V_7 -> V_16 = V_16 ;
V_13 = F_9 ( V_7 -> V_16 , V_27 ,
V_74 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_7 -> V_16 , V_27 ,
V_75 ) ;
if ( V_13 < 0 )
return V_13 ;
F_35 ( 210 ) ;
V_13 = F_8 ( V_7 -> V_16 , V_27 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! ( V_13 & V_76 ) )
return V_13 ;
F_36 ( V_64 , L_3 , & V_66 ) ;
V_7 -> V_54 = V_66 ;
V_20 = V_75 | V_77 |
V_28 ;
if ( V_66 >= 2400 )
V_20 |= V_78 ;
V_13 = F_9 ( V_7 -> V_16 , V_27 , V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_7 -> V_16 , V_79 , 0x30 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_66 >= 2400 ) {
V_20 = F_37 ( ( 4500 - V_66 ) / 300 ) ;
V_13 = F_9 ( V_7 -> V_16 , V_17 ,
V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_8 = 0 ; V_8 < F_4 ( V_7 -> V_10 ) ; V_8 ++ )
V_7 -> V_10 [ V_8 ] = ( ( ( V_80 ) V_7 -> V_54 ) * 1000000000ULL )
>> ( 23 + V_8 ) ;
F_38 ( & V_7 -> V_38 ) ;
if ( V_16 -> V_29 ) {
V_13 = F_39 ( V_16 -> V_29 ,
NULL ,
F_14 ,
V_81 | V_82 ,
V_16 -> V_2 . V_83 -> V_69 ,
V_32 ) ;
if ( V_13 ) {
F_40 ( & V_16 -> V_2 ,
L_4 ) ;
V_16 -> V_29 = 0 ;
} else
F_21 ( V_16 -> V_29 ) ;
}
if ( ! V_16 -> V_29 ) {
V_7 -> V_45 = V_46 ;
V_13 = F_9 ( V_7 -> V_16 , V_50 ,
F_27 ( V_7 -> V_45 ) ) ;
if ( V_13 )
goto V_84;
}
V_32 -> V_85 = F_4 ( V_86 ) ;
V_32 -> V_87 = V_86 ;
F_41 ( & V_7 -> V_14 ) ;
F_41 ( & V_7 -> V_21 ) ;
V_13 = F_42 ( V_32 ) ;
if ( V_13 < 0 ) {
F_31 ( & V_16 -> V_2 , L_5 ) ;
goto V_88;
}
return 0 ;
V_88:
F_43 ( & V_7 -> V_14 ) ;
F_43 ( & V_7 -> V_21 ) ;
V_84:
if ( V_16 -> V_29 )
F_44 ( V_16 -> V_29 , V_32 ) ;
return V_13 ;
}
static int F_45 ( struct V_60 * V_16 )
{
struct V_31 * V_32 = F_46 ( V_16 ) ;
struct V_6 * V_7 = F_2 ( V_32 ) ;
F_47 ( V_32 ) ;
F_43 ( & V_7 -> V_14 ) ;
F_43 ( & V_7 -> V_21 ) ;
if ( V_16 -> V_29 )
F_44 ( V_16 -> V_29 , V_32 ) ;
return 0 ;
}
