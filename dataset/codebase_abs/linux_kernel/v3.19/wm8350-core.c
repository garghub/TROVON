int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
return F_2 ( V_1 -> V_4 , V_2 , V_3 , 0 ) ;
}
int F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
return F_2 ( V_1 -> V_4 , V_2 , V_3 , V_3 ) ;
}
T_1 F_4 ( struct V_1 * V_1 , int V_2 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_5 ( V_1 -> V_4 , V_2 , & V_5 ) ;
if ( V_6 )
F_6 ( V_1 -> V_7 , L_1 , V_2 ) ;
return V_5 ;
}
int F_7 ( struct V_1 * V_1 , int V_2 , T_1 V_8 )
{
int V_9 ;
V_9 = F_8 ( V_1 -> V_4 , V_2 , V_8 ) ;
if ( V_9 )
F_6 ( V_1 -> V_7 , L_2 , V_2 ) ;
return V_9 ;
}
int F_9 ( struct V_1 * V_1 , int V_10 , int V_11 ,
T_1 * V_12 )
{
int V_6 = 0 ;
V_6 = F_10 ( V_1 -> V_4 , V_10 , V_12 , V_11 ) ;
if ( V_6 )
F_6 ( V_1 -> V_7 , L_3 ,
V_10 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_1 , int V_10 , int V_11 ,
T_1 * V_13 )
{
int V_9 = 0 ;
V_9 = F_12 ( V_1 -> V_4 , V_10 , V_13 , V_11 ) ;
if ( V_9 )
F_6 ( V_1 -> V_7 , L_4 ,
V_10 ) ;
return V_9 ;
}
int F_13 ( struct V_1 * V_1 )
{
int V_9 ;
F_14 ( & V_14 ) ;
F_15 ( V_15 ) ;
V_9 = F_7 ( V_1 , V_16 , V_17 ) ;
if ( V_9 )
F_6 ( V_1 -> V_7 , L_5 ) ;
V_1 -> V_18 = false ;
F_16 ( & V_14 ) ;
return V_9 ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_9 ;
F_14 ( & V_14 ) ;
F_15 ( V_15 ) ;
V_9 = F_7 ( V_1 , V_16 , V_19 ) ;
if ( V_9 )
F_6 ( V_1 -> V_7 , L_6 ) ;
V_1 -> V_18 = true ;
F_16 ( & V_14 ) ;
return V_9 ;
}
int F_18 ( struct V_1 * V_1 , int V_20 , int V_21 , int V_22 )
{
T_1 V_2 , V_23 = 0 ;
if ( V_20 < V_24 || V_20 > V_25 )
return - V_26 ;
if ( V_20 >= V_27 && V_20 <= V_25
&& ( V_21 != 0 || V_22 != 0 ) )
return - V_26 ;
F_14 ( & V_1 -> V_28 ) ;
V_2 = F_4 ( V_1 , V_29 ) ;
F_7 ( V_1 , V_29 , V_2 | V_30 ) ;
if ( V_21 || V_22 ) {
V_2 = V_21 << 13 ;
V_2 |= V_22 << 12 ;
F_7 ( V_1 , V_31 + V_20 , V_2 ) ;
}
V_2 = F_4 ( V_1 , V_32 ) ;
V_2 |= 1 << V_20 | V_33 ;
F_7 ( V_1 , V_32 , V_2 ) ;
F_19 ( & V_1 -> V_34 ) ;
F_20 ( & V_1 -> V_34 , F_21 ( 5 ) ) ;
V_2 = F_4 ( V_1 , V_32 ) ;
if ( V_2 & V_33 )
F_6 ( V_1 -> V_7 , L_7 , V_20 ) ;
else
V_23 = F_4 ( V_1 ,
V_31 + V_20 ) ;
V_2 = F_4 ( V_1 , V_29 ) ;
F_7 ( V_1 , V_29 ,
V_2 & ~ V_30 ) ;
F_16 ( & V_1 -> V_28 ) ;
return V_23 & V_35 ;
}
static T_2 F_22 ( int V_36 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
F_23 ( & V_1 -> V_34 ) ;
return V_38 ;
}
static void F_24 ( struct V_1 * V_1 ,
const char * V_39 ,
struct V_40 * * V_41 )
{
int V_9 ;
* V_41 = F_25 ( V_39 , - 1 ) ;
if ( * V_41 == NULL ) {
F_6 ( V_1 -> V_7 , L_8 , V_39 ) ;
return;
}
( * V_41 ) -> V_7 . V_42 = V_1 -> V_7 ;
F_26 ( * V_41 , V_1 ) ;
V_9 = F_27 ( * V_41 ) ;
if ( V_9 != 0 ) {
F_6 ( V_1 -> V_7 , L_9 , V_39 , V_9 ) ;
F_28 ( * V_41 ) ;
* V_41 = NULL ;
}
}
int F_29 ( struct V_1 * V_1 , int V_36 ,
struct V_43 * V_44 )
{
int V_9 ;
unsigned int V_45 , V_46 , V_47 ;
unsigned int V_48 , V_49 , V_50 ;
F_30 ( V_1 -> V_7 , V_1 ) ;
V_9 = F_5 ( V_1 -> V_4 , V_51 , & V_45 ) ;
if ( V_9 != 0 ) {
F_6 ( V_1 -> V_7 , L_10 , V_9 ) ;
goto V_6;
}
V_9 = F_5 ( V_1 -> V_4 , V_52 , & V_46 ) ;
if ( V_9 != 0 ) {
F_6 ( V_1 -> V_7 , L_10 , V_9 ) ;
goto V_6;
}
V_9 = F_5 ( V_1 -> V_4 , V_53 , & V_47 ) ;
if ( V_9 != 0 ) {
F_6 ( V_1 -> V_7 , L_11 , V_9 ) ;
goto V_6;
}
if ( V_45 != 0x6143 ) {
F_6 ( V_1 -> V_7 ,
L_12 , V_45 ) ;
V_9 = - V_54 ;
goto V_6;
}
V_49 = ( V_46 & V_55 ) >> 10 ;
V_48 = V_46 & V_56 ;
V_50 = ( V_46 & V_57 ) >> 12 ;
F_31 ( V_1 -> V_7 ,
L_13 ,
V_49 , V_48 , V_47 , V_50 ) ;
if ( V_48 != 0 ) {
F_6 ( V_1 -> V_7 , L_14 ) ;
V_9 = - V_54 ;
goto V_6;
}
switch ( V_47 ) {
case 0 :
V_1 -> V_58 . V_59 = V_60 ;
V_1 -> V_58 . V_61 = V_62 ;
switch ( V_50 ) {
case V_63 :
F_31 ( V_1 -> V_7 , L_15 ) ;
break;
case V_64 :
F_31 ( V_1 -> V_7 , L_16 ) ;
break;
case V_65 :
F_31 ( V_1 -> V_7 , L_17 ) ;
V_1 -> V_66 . V_67 = 1 ;
break;
case V_68 :
F_31 ( V_1 -> V_7 , L_18 ) ;
V_1 -> V_66 . V_67 = 1 ;
break;
default:
F_6 ( V_1 -> V_7 , L_19 ) ;
V_9 = - V_54 ;
goto V_6;
}
break;
case 1 :
V_1 -> V_58 . V_59 = V_69 ;
V_1 -> V_58 . V_61 = V_70 ;
switch ( V_50 ) {
case 0 :
F_31 ( V_1 -> V_7 , L_20 ) ;
V_1 -> V_66 . V_67 = 1 ;
break;
case 1 :
F_31 ( V_1 -> V_7 , L_21 ) ;
V_1 -> V_66 . V_67 = 1 ;
break;
default:
F_6 ( V_1 -> V_7 , L_22 ) ;
V_9 = - V_54 ;
goto V_6;
}
break;
case 2 :
V_1 -> V_58 . V_59 = V_60 ;
V_1 -> V_58 . V_61 = V_62 ;
switch ( V_50 ) {
case 0 :
F_31 ( V_1 -> V_7 , L_23 ) ;
V_1 -> V_66 . V_67 = 1 ;
break;
default:
F_6 ( V_1 -> V_7 , L_24 ) ;
V_9 = - V_54 ;
goto V_6;
}
break;
default:
F_6 ( V_1 -> V_7 , L_25 ) ;
V_9 = - V_54 ;
goto V_6;
}
F_32 ( & V_1 -> V_28 ) ;
F_33 ( & V_1 -> V_34 ) ;
V_9 = F_34 ( V_1 , V_36 , V_44 ) ;
if ( V_9 < 0 )
goto V_6;
if ( V_1 -> V_71 ) {
V_9 = F_35 ( V_1 -> V_71 +
V_72 ,
NULL , F_22 , 0 ,
L_26 , V_1 ) ;
if ( V_9 < 0 )
F_36 ( V_1 -> V_7 ,
L_27 , V_9 ) ;
}
if ( V_44 && V_44 -> V_73 ) {
V_9 = V_44 -> V_73 ( V_1 ) ;
if ( V_9 != 0 ) {
F_6 ( V_1 -> V_7 , L_28 ,
V_9 ) ;
goto V_74;
}
}
F_7 ( V_1 , V_75 , 0x0 ) ;
F_24 ( V_1 , L_29 ,
& ( V_1 -> V_76 . V_41 ) ) ;
F_24 ( V_1 , L_30 ,
& ( V_1 -> V_77 . V_41 ) ) ;
F_24 ( V_1 , L_31 ,
& ( V_1 -> V_78 . V_41 ) ) ;
F_24 ( V_1 , L_32 ,
& ( V_1 -> V_66 . V_41 ) ) ;
F_24 ( V_1 , L_33 , & ( V_1 -> V_79 . V_41 ) ) ;
F_24 ( V_1 , L_34 , & ( V_1 -> V_80 . V_41 ) ) ;
return 0 ;
V_74:
F_37 ( V_1 ) ;
V_6:
return V_9 ;
}
void F_38 ( struct V_1 * V_1 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < F_39 ( V_1 -> V_58 . V_82 ) ; V_81 ++ )
F_40 ( V_1 -> V_58 . V_82 [ V_81 ] . V_41 ) ;
for ( V_81 = 0 ; V_81 < F_39 ( V_1 -> V_58 . V_41 ) ; V_81 ++ )
F_40 ( V_1 -> V_58 . V_41 [ V_81 ] ) ;
F_40 ( V_1 -> V_80 . V_41 ) ;
F_40 ( V_1 -> V_79 . V_41 ) ;
F_40 ( V_1 -> V_66 . V_41 ) ;
F_40 ( V_1 -> V_78 . V_41 ) ;
F_40 ( V_1 -> V_77 . V_41 ) ;
F_40 ( V_1 -> V_76 . V_41 ) ;
if ( V_1 -> V_71 )
F_41 ( V_1 -> V_71 + V_72 , V_1 ) ;
F_37 ( V_1 ) ;
}
