static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
T_1 V_7 ;
int V_8 ;
F_4 ( & V_6 -> V_9 ) ;
if ( F_5 ( V_10 , V_6 -> V_11 + V_12 / 10 ) || ! V_6 -> V_13 ) {
F_6 ( & V_5 -> V_3 , L_1 ) ;
for ( V_8 = 0 ; V_8 < F_7 ( V_6 -> V_14 ) ; V_8 ++ ) {
V_7 = F_8 ( V_5 , V_8 ) ;
if ( F_9 ( V_7 < 0 ) )
V_6 -> V_14 [ V_8 ] = 0 ;
else
V_6 -> V_14 [ V_8 ] = V_7 ;
}
V_6 -> V_11 = V_10 ;
V_6 -> V_13 = 1 ;
}
F_10 ( & V_6 -> V_9 ) ;
return V_6 ;
}
static int F_11 ( struct V_2 * V_3 , T_2 V_15 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
const T_2 V_16 = V_6 -> V_14 [ V_15 ] ;
T_3 V_17 = 0 ;
switch ( V_15 ) {
case V_18 :
V_17 = V_16 * 151 / 1000 ;
break;
case V_19 :
V_17 = V_16 * 605 / 10 ;
break;
case V_20 :
V_17 = V_16 * 482 * 125 / 1000 ;
break;
default:
F_12 ( 1 ) ;
break;
}
return V_17 ;
}
static unsigned int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
const unsigned int V_17 = V_6 -> V_14 [ V_18 ] * 151 ;
const unsigned int V_21 = V_17 / 4 ;
return V_21 ;
}
static T_4 F_14 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_15 ( V_23 ) ;
const int V_17 = F_11 ( V_3 , V_26 -> V_27 ) ;
return snprintf ( V_24 , V_28 , L_2 , V_17 ) ;
}
static T_4 F_16 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
const unsigned int V_21 = F_13 ( V_3 ) ;
return snprintf ( V_24 , V_28 , L_3 , V_21 ) ;
}
static T_4 F_17 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
const unsigned int V_21 = F_13 ( V_3 ) ;
const int V_29 = F_11 ( V_3 , V_20 ) ;
const unsigned int V_30 = abs ( V_29 * V_21 ) ;
return snprintf ( V_24 , V_28 , L_3 , V_30 ) ;
}
static T_4 F_18 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_31 * V_26 = F_19 ( V_23 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
const T_2 V_15 = V_6 -> V_14 [ V_26 -> V_27 ] ;
const T_3 V_32 = V_26 -> V_33 ;
return snprintf ( V_24 , V_28 , L_3 , ( V_15 & V_32 ) ? 1 : 0 ) ;
}
static int F_20 ( struct V_4 * V_5 ,
const struct V_34 * V_35 )
{
struct V_36 * V_37 = V_5 -> V_37 ;
struct V_1 * V_6 ;
int V_38 ;
if ( ! F_21 ( V_37 , V_39 ) )
return - V_40 ;
V_6 = F_22 ( & V_5 -> V_3 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 )
return - V_42 ;
F_23 ( V_5 , V_6 ) ;
F_24 ( & V_6 -> V_9 ) ;
F_25 ( V_5 , V_43 , 0x00 ) ;
V_38 = F_26 ( & V_5 -> V_3 . V_44 , & V_45 ) ;
if ( V_38 )
return V_38 ;
V_6 -> V_46 = F_27 ( & V_5 -> V_3 ) ;
if ( F_28 ( V_6 -> V_46 ) ) {
V_38 = F_29 ( V_6 -> V_46 ) ;
goto V_47;
}
return 0 ;
V_47:
F_30 ( & V_5 -> V_3 . V_44 , & V_45 ) ;
return V_38 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_32 ( V_6 -> V_46 ) ;
F_30 ( & V_5 -> V_3 . V_44 , & V_45 ) ;
return 0 ;
}
