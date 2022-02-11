static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 ,
T_1 * V_6 , int V_7 ,
T_1 * V_8 , int V_9 )
{
struct V_10 V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 , V_16 ;
T_1 V_17 , V_18 ;
int V_19 , V_20 ;
if ( V_5 >= 1 << 12 ) {
F_2 ( & V_2 -> V_21 , L_1 ) ;
return - V_22 ;
}
V_17 = 1 + V_23 + V_7 ;
V_11 . V_24 = 0 ;
V_11 . V_3 = V_3 ;
V_11 . V_25 = V_4 | ( V_5 >> 8 ) ;
V_11 . V_26 = V_5 ;
if ( V_4 == V_27 )
V_11 . V_28 = V_7 ;
else
V_11 . V_28 = V_9 ;
if ( V_7 )
memcpy ( V_11 . V_29 , V_6 , V_7 ) ;
V_16 . V_30 = V_2 -> V_30 ;
V_16 . V_31 = 0 ;
V_16 . V_32 = V_17 ;
V_16 . V_29 = ( T_1 * ) & V_11 ;
V_19 = F_3 ( V_2 -> V_33 , & V_16 , 1 ) ;
if ( V_19 < 0 ) {
F_2 ( & V_2 -> V_21 , L_2 ) ;
return V_19 ;
}
V_20 = V_34 ;
do {
F_4 ( V_35 ) ;
V_15 . V_30 = V_2 -> V_30 ;
V_15 . V_31 = V_36 ;
V_15 . V_32 = sizeof( V_13 ) ;
V_15 . V_29 = ( T_1 * ) & V_13 ;
V_19 = F_3 ( V_2 -> V_33 , & V_15 , 1 ) ;
if ( V_19 < 0 ) {
F_2 ( & V_2 -> V_21 , L_3 ) ;
return V_19 ;
}
if ( V_13 . V_37 & V_38 )
break;
} while ( -- V_20 > 0 );
if ( V_20 == 0 ) {
F_2 ( & V_2 -> V_21 ,
L_4 ) ;
return - V_39 ;
}
if ( V_13 . V_3 != V_3 ) {
F_2 ( & V_2 -> V_21 ,
L_5 ,
V_13 . V_3 , V_3 ) ;
return - V_22 ;
}
V_18 = V_13 . V_37 & ~ V_38 ;
if ( V_18 != V_40 ) {
F_2 ( & V_2 -> V_21 , L_6 , V_18 ) ;
return - V_22 ;
}
if ( V_13 . V_28 != V_13 . V_41 ) {
F_2 ( & V_2 -> V_21 ,
L_7 ,
V_13 . V_28 , V_13 . V_41 ) ;
return - V_22 ;
}
if ( V_9 )
memcpy ( V_8 , V_13 . V_29 , V_9 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 * V_43 )
{
return F_1 ( V_2 , V_3 , V_44 ,
V_42 , NULL , 0 , V_43 , 1 ) ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 V_43 )
{
return F_1 ( V_2 , V_3 , V_27 , V_42 ,
& V_43 , 1 , NULL , 0 ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 * V_43 )
{
return F_1 ( V_2 , V_3 , V_45 ,
V_42 , NULL , 0 , V_43 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_2 * V_43 )
{
int V_19 ;
T_3 V_46 ;
V_19 = F_1 ( V_2 , V_3 , V_44 ,
V_42 , NULL , 0 , ( T_1 * ) & V_46 , 2 ) ;
* V_43 = F_9 ( V_46 ) ;
return V_19 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_2 V_43 )
{
T_3 V_46 = F_11 ( V_43 ) ;
return F_1 ( V_2 , V_3 , V_27 , V_42 ,
( T_1 * ) & V_46 , 2 , NULL , 0 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_2 * V_43 )
{
int V_19 ;
T_3 V_46 ;
V_19 = F_1 ( V_2 , V_3 , V_45 ,
V_42 , NULL , 0 , ( T_1 * ) & V_46 , 2 ) ;
* V_43 = F_9 ( V_46 ) ;
return V_19 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 V_32 , T_2 * V_29 )
{
int V_19 , V_47 ;
T_3 V_48 [ V_49 / 2 ] ;
if ( V_32 > F_14 ( V_48 ) ) {
F_2 ( & V_2 -> V_21 , L_8 , V_32 ) ;
return - V_22 ;
}
V_19 = F_1 ( V_2 , V_3 , V_44 ,
V_42 , NULL , 0 , ( T_1 * ) V_48 , V_32 * sizeof( T_2 ) ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_47 = 0 ; V_47 < V_32 ; V_47 ++ )
V_29 [ V_47 ] = F_9 ( V_48 [ V_47 ] ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 V_32 , T_2 * V_29 )
{
int V_19 , V_47 ;
T_3 V_48 [ V_49 / 2 ] ;
if ( V_32 > F_14 ( V_48 ) ) {
F_2 ( & V_2 -> V_21 , L_8 , V_32 ) ;
return - V_22 ;
}
V_19 = F_1 ( V_2 , V_3 , V_45 ,
V_42 , NULL , 0 , ( T_1 * ) V_48 , V_32 * sizeof( T_2 ) ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_47 = 0 ; V_47 < V_32 ; V_47 ++ )
V_29 [ V_47 ] = F_9 ( V_48 [ V_47 ] ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 V_32 , T_2 * V_29 )
{
int V_47 ;
T_3 V_48 [ ( V_49 - 1 ) / 2 ] ;
if ( V_32 > F_14 ( V_48 ) ) {
F_2 ( & V_2 -> V_21 , L_8 , V_32 ) ;
return - V_22 ;
}
for ( V_47 = 0 ; V_47 < V_32 ; V_47 ++ )
V_48 [ V_47 ] = F_11 ( V_29 [ V_47 ] ) ;
return F_1 ( V_2 , V_3 , V_27 ,
V_42 , ( T_1 * ) V_48 , V_32 * sizeof( T_2 ) , NULL , 0 ) ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_42 , T_1 V_50 , T_1 V_43 )
{
int V_19 ;
T_1 V_51 , V_52 ;
V_19 = F_5 ( V_2 , V_3 , V_42 , & V_52 ) ;
if ( V_19 < 0 )
return V_19 ;
V_51 = V_52 & ~ V_50 ;
V_51 |= V_43 & V_50 ;
if ( V_51 == V_52 )
return 0 ;
return F_6 ( V_2 , V_3 , V_42 , V_51 ) ;
}
int F_18 ( struct V_1 * V_2 , enum V_53 V_54 ,
T_1 V_3 , T_1 V_55 , int V_56 )
{
T_1 V_42 , V_57 , V_58 ;
int V_19 ;
if ( V_54 > V_59 ) {
F_2 ( & V_2 -> V_21 , L_9 ) ;
return - V_22 ;
}
V_42 = V_54 * 2 ;
V_19 = F_6 ( V_2 , V_60 ,
V_42 , V_3 ) ;
if ( V_19 < 0 ) {
F_2 ( & V_2 -> V_21 , L_10 ) ;
return V_19 ;
}
V_19 = F_6 ( V_2 , V_60 ,
V_42 + 1 , V_55 ) ;
if ( V_19 < 0 ) {
F_2 ( & V_2 -> V_21 , L_11 ) ;
return V_19 ;
}
switch ( V_54 ) {
case V_61 :
V_42 = V_62 ;
V_57 = 1 << 6 ;
break;
case V_63 :
V_42 = V_62 ;
V_57 = 1 << 7 ;
break;
case V_64 :
V_42 = V_65 ;
V_57 = 1 << 0 ;
break;
case V_66 :
V_42 = V_65 ;
V_57 = 1 << 1 ;
break;
}
V_58 = V_56 ? V_57 : 0 ;
V_19 = F_17 ( V_2 , V_60 , V_42 ,
V_57 , V_58 ) ;
if ( V_19 < 0 )
F_2 ( & V_2 -> V_21 , L_12 ) ;
return V_19 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_67 V_68 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_69 , 0x00 , 0x00 ,
NULL , 0 , ( T_1 * ) & V_68 , sizeof( V_68 ) ) ;
if ( V_19 < 0 )
return V_19 ;
F_20 ( & V_2 -> V_21 , L_13 ,
F_21 ( V_68 . V_70 ) , V_68 . V_71 [ 0 ] ,
V_68 . V_71 [ 1 ] ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , bool V_72 )
{
return F_17 ( V_2 , V_73 ,
V_74 ,
V_75 |
V_76 |
V_77 ,
V_72 ? V_77 |
V_76 :
V_75 ) ;
}
int F_23 ( struct V_1 * V_2 , bool V_78 )
{
#ifdef F_24
int V_19 ;
if ( V_78 )
V_19 = F_25 ( & V_2 -> V_21 ) ;
else {
F_26 ( & V_2 -> V_21 ) ;
V_19 = F_27 ( & V_2 -> V_21 ) ;
}
if ( V_19 < 0 ) {
F_2 ( & V_2 -> V_21 ,
L_14 , V_78 ) ;
if ( V_78 )
F_28 ( & V_2 -> V_21 ) ;
return V_19 ;
}
#endif
return 0 ;
}
void F_29 ( int V_79 )
{
int V_80 = 1000 / V_79 ;
if ( V_80 < 20 )
F_30 ( V_80 * 1000 , 20000 ) ;
else
F_31 ( V_80 ) ;
}
int F_32 ( struct V_1 * V_2 ,
const struct V_81 * V_82 ,
int * V_43 , int * V_83 )
{
T_2 V_84 ;
T_4 V_85 ;
int V_19 ;
switch ( V_82 -> V_86 ) {
case V_87 :
V_84 = V_88 ;
break;
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
default:
return - V_22 ;
}
V_19 = F_23 ( V_2 , true ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_12 ( V_2 , V_93 ,
V_84 , & V_85 ) ;
if ( V_19 < 0 )
goto V_94;
* V_43 = V_85 ;
V_19 = V_95 ;
V_94:
F_23 ( V_2 , false ) ;
return V_19 ;
}
int F_33 ( int * V_43 , int * V_83 )
{
* V_43 = 0 ;
* V_83 = 2440 ;
return V_96 ;
}
int F_34 ( struct V_1 * V_2 , T_5 V_97 )
{
return F_6 ( V_2 , V_98 ,
V_99 +
F_35 ( V_97 ) ,
F_36 ( V_97 ) ) ;
}
