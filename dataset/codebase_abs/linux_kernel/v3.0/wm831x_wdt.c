static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 ) ;
if ( V_3 == 0 ) {
V_3 = F_4 ( V_1 , V_5 ,
V_6 , V_2 ) ;
F_5 ( V_1 ) ;
} else {
F_6 ( V_1 -> V_7 , L_1 ,
V_3 ) ;
}
F_7 ( & V_4 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_1 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 ) ;
if ( V_3 == 0 ) {
V_3 = F_4 ( V_1 , V_5 ,
V_8 , V_8 ) ;
F_5 ( V_1 ) ;
} else {
F_6 ( V_1 -> V_7 , L_1 ,
V_3 ) ;
}
F_7 ( & V_4 ) ;
return V_3 ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 ) ;
if ( V_3 == 0 ) {
V_3 = F_4 ( V_1 , V_5 ,
V_8 , 0 ) ;
F_5 ( V_1 ) ;
} else {
F_6 ( V_1 -> V_7 , L_1 ,
V_3 ) ;
}
F_7 ( & V_4 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_1 )
{
int V_3 ;
T_1 V_9 ;
F_2 ( & V_4 ) ;
if ( V_10 ) {
F_11 ( V_10 , V_11 ) ;
V_11 = ! V_11 ;
V_3 = 0 ;
goto V_12;
}
V_9 = F_12 ( V_1 , V_5 ) ;
if ( ! ( V_9 & V_13 ) ) {
F_6 ( V_1 -> V_7 , L_2 ) ;
V_3 = - V_14 ;
goto V_12;
}
V_9 |= V_15 ;
V_3 = F_3 ( V_1 ) ;
if ( V_3 == 0 ) {
V_3 = F_13 ( V_1 , V_5 , V_9 ) ;
F_5 ( V_1 ) ;
} else {
F_6 ( V_1 -> V_7 , L_1 ,
V_3 ) ;
}
V_12:
F_7 ( & V_4 ) ;
return V_3 ;
}
static int F_14 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
int V_3 ;
if ( ! V_1 )
return - V_18 ;
if ( F_15 ( 0 , & V_19 ) )
return - V_20 ;
V_3 = F_8 ( V_1 ) ;
if ( V_3 != 0 )
return V_3 ;
return F_16 ( V_16 , V_17 ) ;
}
static int F_17 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( V_21 )
F_9 ( V_1 ) ;
else {
F_18 ( V_1 -> V_7 , L_3 ) ;
F_10 ( V_1 ) ;
}
F_19 ( 0 , & V_19 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_17 * V_17 ,
const char T_3 * V_22 , T_4 V_23 ,
T_5 * V_24 )
{
T_4 V_25 ;
if ( V_23 ) {
F_10 ( V_1 ) ;
if ( ! V_26 ) {
V_21 = 0 ;
for ( V_25 = 0 ; V_25 != V_23 ; V_25 ++ ) {
char V_27 ;
if ( F_21 ( V_27 , V_22 + V_25 ) )
return - V_28 ;
if ( V_27 == 'V' )
V_21 = 42 ;
}
}
}
return V_23 ;
}
static long F_22 ( struct V_17 * V_17 , unsigned int V_29 ,
unsigned long V_30 )
{
int V_3 = - V_31 , time , V_25 ;
void T_3 * V_32 = ( void T_3 * ) V_30 ;
int T_3 * V_33 = V_32 ;
T_1 V_9 ;
switch ( V_29 ) {
case V_34 :
V_3 = F_23 ( V_32 , & V_35 , sizeof( V_35 ) ) ? - V_28 : 0 ;
break;
case V_36 :
case V_37 :
V_3 = F_24 ( 0 , V_33 ) ;
break;
case V_38 :
{
int V_39 ;
if ( F_21 ( V_39 , V_33 ) )
return - V_28 ;
V_3 = - V_14 ;
if ( V_39 == V_40 )
V_3 = F_8 ( V_1 ) ;
if ( V_39 == V_41 )
V_3 = F_9 ( V_1 ) ;
break;
}
case V_42 :
V_3 = F_10 ( V_1 ) ;
break;
case V_43 :
V_3 = F_21 ( time , V_33 ) ;
if ( V_3 )
break;
if ( time == 0 ) {
if ( V_26 )
V_3 = - V_14 ;
else
F_9 ( V_1 ) ;
break;
}
for ( V_25 = 0 ; V_25 < F_25 ( V_44 ) ; V_25 ++ )
if ( V_44 [ V_25 ] . time == time )
break;
if ( V_25 == F_25 ( V_44 ) )
V_3 = - V_14 ;
else
V_3 = F_1 ( V_1 ,
V_44 [ V_25 ] . V_45 ) ;
break;
case V_46 :
V_9 = F_12 ( V_1 , V_5 ) ;
V_9 &= V_6 ;
for ( V_25 = 0 ; V_25 < F_25 ( V_44 ) ; V_25 ++ )
if ( V_44 [ V_25 ] . V_45 == V_9 )
break;
if ( V_25 == F_25 ( V_44 ) ) {
F_18 ( V_1 -> V_7 ,
L_4 , V_9 ) ;
V_3 = - V_14 ;
} else
V_3 = F_24 ( V_44 [ V_25 ] . time , V_33 ) ;
}
return V_3 ;
}
static int T_6 F_26 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_9 , V_3 ;
if ( V_1 ) {
F_6 ( & V_48 -> V_7 , L_5 ) ;
return - V_20 ;
}
V_1 = F_27 ( V_48 -> V_7 . V_53 ) ;
V_3 = F_12 ( V_1 , V_5 ) ;
if ( V_3 < 0 ) {
F_6 ( V_1 -> V_7 , L_6 ,
V_3 ) ;
goto V_54;
}
V_9 = V_3 ;
if ( V_9 & V_55 )
F_18 ( V_1 -> V_7 , L_7 ) ;
if ( V_48 -> V_7 . V_53 -> V_56 ) {
V_50 = V_48 -> V_7 . V_53 -> V_56 ;
V_52 = V_50 -> V_57 ;
} else {
V_52 = NULL ;
}
if ( V_52 ) {
V_9 &= ~ ( V_58 | V_59 |
V_13 ) ;
V_9 |= V_52 -> V_60 << V_61 ;
V_9 |= V_52 -> V_62 << V_63 ;
V_9 |= V_52 -> V_64 << V_65 ;
if ( V_52 -> V_10 ) {
V_3 = F_28 ( V_52 -> V_10 ,
L_8 ) ;
if ( V_3 < 0 ) {
F_6 ( V_1 -> V_7 ,
L_9 ,
V_3 ) ;
goto V_54;
}
V_3 = F_29 ( V_52 -> V_10 , 0 ) ;
if ( V_3 != 0 ) {
F_6 ( V_1 -> V_7 ,
L_10 ,
V_3 ) ;
goto V_66;
}
V_10 = V_52 -> V_10 ;
V_9 |= V_13 ;
}
V_3 = F_3 ( V_1 ) ;
if ( V_3 == 0 ) {
V_3 = F_13 ( V_1 , V_5 , V_9 ) ;
F_5 ( V_1 ) ;
} else {
F_6 ( V_1 -> V_7 ,
L_1 , V_3 ) ;
goto V_66;
}
}
V_67 . V_53 = & V_48 -> V_7 ;
V_3 = F_30 ( & V_67 ) ;
if ( V_3 != 0 ) {
F_6 ( V_1 -> V_7 , L_11 , V_3 ) ;
goto V_66;
}
return 0 ;
V_66:
if ( V_10 ) {
F_31 ( V_10 ) ;
V_10 = 0 ;
}
V_54:
return V_3 ;
}
static int T_7 F_32 ( struct V_47 * V_48 )
{
if ( V_10 ) {
F_31 ( V_10 ) ;
V_10 = 0 ;
}
F_33 ( & V_67 ) ;
return 0 ;
}
static int T_8 F_34 ( void )
{
return F_35 ( & V_68 ) ;
}
static void T_9 F_36 ( void )
{
F_37 ( & V_68 ) ;
}
