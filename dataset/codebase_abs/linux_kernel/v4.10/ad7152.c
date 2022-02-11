static inline T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 ,
T_3 V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 * V_13 = F_4 ( V_4 ) ;
bool V_14 ;
int V_15 , V_16 = 10 ;
V_15 = F_5 ( V_5 , & V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_14 )
return 0 ;
if ( V_13 -> V_17 == 0 )
V_7 |= V_18 ;
else
V_7 |= V_19 ;
F_6 ( & V_11 -> V_20 ) ;
V_15 = F_7 ( V_11 -> V_21 , V_22 , V_7 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_11 -> V_20 ) ;
return V_15 ;
}
do {
F_9 ( 20 ) ;
V_15 = F_10 ( V_11 -> V_21 , V_22 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_11 -> V_20 ) ;
return V_15 ;
}
} while ( ( V_15 == V_7 ) && V_16 -- );
F_8 ( & V_11 -> V_20 ) ;
return V_6 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 ,
V_23 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 ,
V_24 ) ;
}
static int F_13 ( struct V_1 * V_2 , int * V_25 )
{
struct V_10 * V_11 = F_3 ( F_2 ( V_2 ) ) ;
* V_25 = V_26 [ V_11 -> V_27 ] [ 0 ] ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_25 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_15 , V_28 ;
for ( V_28 = 0 ; V_28 < F_15 ( V_26 ) ; V_28 ++ )
if ( V_25 >= V_26 [ V_28 ] [ 0 ] )
break;
if ( V_28 >= F_15 ( V_26 ) )
V_28 = F_15 ( V_26 ) - 1 ;
F_6 ( & V_11 -> V_20 ) ;
V_15 = F_7 ( V_11 -> V_21 ,
V_29 , F_16 ( V_28 ) ) ;
if ( V_15 < 0 ) {
F_8 ( & V_11 -> V_20 ) ;
return V_15 ;
}
V_11 -> V_27 = V_28 ;
F_8 ( & V_11 -> V_20 ) ;
return V_15 ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_30 const * V_31 ,
int V_25 ,
int V_32 ,
long V_33 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_15 , V_28 ;
F_6 ( & V_11 -> V_20 ) ;
switch ( V_33 ) {
case V_34 :
if ( V_25 != 1 ) {
V_15 = - V_35 ;
goto V_36;
}
V_25 = ( V_32 * 1024 ) / 15625 ;
V_15 = F_18 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_39 ] ,
F_19 ( V_25 ) ) ;
if ( V_15 < 0 )
goto V_36;
V_15 = 0 ;
break;
case V_40 :
if ( ( V_25 < 0 ) | ( V_25 > 0xFFFF ) ) {
V_15 = - V_35 ;
goto V_36;
}
V_15 = F_18 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_41 ] ,
F_19 ( V_25 ) ) ;
if ( V_15 < 0 )
goto V_36;
V_15 = 0 ;
break;
case V_42 :
if ( V_25 ) {
V_15 = - V_35 ;
goto V_36;
}
for ( V_28 = 0 ; V_28 < F_15 ( V_43 ) ; V_28 ++ )
if ( V_32 == V_43 [ V_28 ] )
break;
V_11 -> V_44 [ V_31 -> V_38 ] &= ~ V_45 ;
V_11 -> V_44 [ V_31 -> V_38 ] |= F_20 ( V_28 ) ;
V_15 = F_7 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_46 ] ,
V_11 -> V_44 [ V_31 -> V_38 ] ) ;
if ( V_15 < 0 )
goto V_36;
V_15 = 0 ;
break;
case V_47 :
if ( V_32 ) {
V_15 = - V_35 ;
goto V_36;
}
V_15 = F_14 ( & V_9 -> V_2 , V_25 ) ;
if ( V_15 < 0 )
goto V_36;
V_15 = 0 ;
break;
default:
V_15 = - V_35 ;
}
V_36:
F_8 ( & V_11 -> V_20 ) ;
return V_15 ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_30 const * V_31 ,
int * V_25 , int * V_32 ,
long V_33 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_15 ;
T_3 V_7 = 0 ;
F_6 ( & V_11 -> V_20 ) ;
switch ( V_33 ) {
case V_48 :
V_7 = V_11 -> V_44 [ V_31 -> V_38 ] ;
if ( V_31 -> V_49 )
V_11 -> V_44 [ V_31 -> V_38 ] |= V_50 ;
else
V_11 -> V_44 [ V_31 -> V_38 ] &= ~ V_50 ;
if ( V_7 != V_11 -> V_44 [ V_31 -> V_38 ] ) {
V_15 = F_7 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_46 ] ,
V_11 -> V_44 [ V_31 -> V_38 ] ) ;
if ( V_15 < 0 )
goto V_36;
}
if ( V_31 -> V_38 == 0 )
V_7 = V_18 ;
else
V_7 = V_19 ;
V_7 |= V_51 ;
V_15 = F_7 ( V_11 -> V_21 , V_22 ,
V_7 ) ;
if ( V_15 < 0 )
goto V_36;
F_22 ( V_26 [ V_11 -> V_27 ] [ 1 ] ) ;
V_15 = F_23 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_52 ] ) ;
if ( V_15 < 0 )
goto V_36;
* V_25 = F_19 ( V_15 ) ;
if ( V_31 -> V_49 )
* V_25 -= 0x8000 ;
V_15 = V_53 ;
break;
case V_34 :
V_15 = F_23 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_39 ] ) ;
if ( V_15 < 0 )
goto V_36;
* V_25 = 1 ;
* V_32 = ( 15625 * F_19 ( V_15 ) ) / 1024 ;
V_15 = V_54 ;
break;
case V_40 :
V_15 = F_23 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_41 ] ) ;
if ( V_15 < 0 )
goto V_36;
* V_25 = F_19 ( V_15 ) ;
V_15 = V_53 ;
break;
case V_42 :
V_15 = F_10 ( V_11 -> V_21 ,
V_37 [ V_31 -> V_38 ] [ V_46 ] ) ;
if ( V_15 < 0 )
goto V_36;
* V_25 = 0 ;
* V_32 = V_43 [ V_15 >> 6 ] ;
V_15 = V_55 ;
break;
case V_47 :
V_15 = F_13 ( & V_9 -> V_2 , V_25 ) ;
if ( V_15 < 0 )
goto V_36;
V_15 = V_53 ;
break;
default:
V_15 = - V_35 ;
}
V_36:
F_8 ( & V_11 -> V_20 ) ;
return V_15 ;
}
static int F_24 ( struct V_8 * V_9 ,
struct V_30 const * V_31 ,
long V_33 )
{
switch ( V_33 ) {
case V_42 :
return V_55 ;
default:
return V_54 ;
}
}
static int F_25 ( struct V_56 * V_21 ,
const struct V_57 * V_58 )
{
int V_15 = 0 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_26 ( & V_21 -> V_2 , sizeof( * V_11 ) ) ;
if ( ! V_9 )
return - V_59 ;
V_11 = F_3 ( V_9 ) ;
F_27 ( V_21 , V_9 ) ;
V_11 -> V_21 = V_21 ;
F_28 ( & V_11 -> V_20 ) ;
V_9 -> V_60 = V_58 -> V_60 ;
V_9 -> V_2 . V_61 = & V_21 -> V_2 ;
V_9 -> V_62 = & V_63 ;
V_9 -> V_64 = V_65 ;
if ( V_58 -> V_66 == 0 )
V_9 -> V_67 = F_15 ( V_65 ) ;
else
V_9 -> V_67 = 2 ;
V_9 -> V_67 = F_15 ( V_65 ) ;
V_9 -> V_68 = V_69 ;
V_15 = F_29 ( V_9 -> V_2 . V_61 , V_9 ) ;
if ( V_15 )
return V_15 ;
F_30 ( & V_21 -> V_2 , L_1 , V_58 -> V_60 ) ;
return 0 ;
}
