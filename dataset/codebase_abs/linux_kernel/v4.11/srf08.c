static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_2 -> V_4 ,
V_9 , V_10 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_1 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
V_7 = 1 + V_2 -> V_12 / 172 ;
F_6 ( V_7 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_5 = F_7 ( V_2 -> V_4 ,
V_13 ) ;
if ( V_5 < 255 && V_5 > 0 )
break;
F_6 ( 5 ) ;
}
if ( V_5 >= 255 || V_5 <= 0 ) {
F_4 ( & V_4 -> V_11 , L_2 ) ;
F_5 ( & V_2 -> V_8 ) ;
return - V_14 ;
}
V_5 = F_8 ( V_2 -> V_4 ,
V_15 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_3 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_18 const * V_19 , int * V_20 ,
int * V_21 , long V_22 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
int V_5 ;
if ( V_19 -> type != V_23 )
return - V_24 ;
switch ( V_22 ) {
case V_25 :
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_20 = V_5 ;
return V_26 ;
case V_27 :
* V_20 = 0 ;
* V_21 = 10000 ;
return V_28 ;
default:
return - V_24 ;
}
}
static T_1 F_11 ( struct V_29 * V_11 ,
struct V_30 * V_31 , char * V_32 )
{
return sprintf ( V_32 , L_4 ) ;
}
static T_1 F_12 ( struct V_29 * V_11 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_16 * V_17 = F_13 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
return sprintf ( V_32 , L_5 , V_2 -> V_12 / 1000 ,
V_2 -> V_12 % 1000 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , unsigned int V_20 )
{
int V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_33 ;
T_2 V_34 ;
V_5 = V_20 / 43 - 1 ;
V_33 = V_20 % 43 ;
if ( V_33 || ( V_5 < 0 ) || ( V_5 > 255 ) )
return - V_24 ;
V_34 = V_5 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_4 , V_35 , V_34 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_6 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
V_2 -> V_12 = V_20 ;
F_5 ( & V_2 -> V_8 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_29 * V_11 ,
struct V_30 * V_31 ,
const char * V_32 , T_3 V_36 )
{
struct V_16 * V_17 = F_13 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
int V_5 ;
int integer , V_37 ;
V_5 = F_16 ( V_32 , 100 , & integer , & V_37 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_2 , integer * 1000 + V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_36 ;
}
static T_1 F_17 ( struct V_29 * V_11 ,
struct V_30 * V_31 , char * V_32 )
{
int V_6 , V_36 = 0 ;
for ( V_6 = 0 ; V_6 < F_18 ( V_38 ) ; V_6 ++ )
V_36 += sprintf ( V_32 + V_36 , L_7 , V_38 [ V_6 ] ) ;
V_36 += sprintf ( V_32 + V_36 , L_8 ) ;
return V_36 ;
}
static T_1 F_19 ( struct V_29 * V_11 ,
struct V_30 * V_31 , char * V_32 )
{
struct V_16 * V_17 = F_13 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
int V_36 ;
V_36 = sprintf ( V_32 , L_9 , V_2 -> V_39 ) ;
return V_36 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 , V_6 ;
T_2 V_34 ;
for ( V_6 = 0 ; V_6 < F_18 ( V_38 ) ; V_6 ++ )
if ( V_20 == V_38 [ V_6 ] ) {
V_34 = V_6 ;
break;
}
if ( V_6 >= F_18 ( V_38 ) )
return - V_24 ;
F_2 ( & V_2 -> V_8 ) ;
V_5 = F_3 ( V_4 ,
V_40 , V_34 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_11 , L_10 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
return V_5 ;
}
V_2 -> V_39 = V_20 ;
F_5 ( & V_2 -> V_8 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_29 * V_11 ,
struct V_30 * V_31 ,
const char * V_32 , T_3 V_36 )
{
struct V_16 * V_17 = F_13 ( V_11 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
int V_5 ;
unsigned int V_20 ;
V_5 = F_22 ( V_32 , 10 , & V_20 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_20 ( V_2 , V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_36 ;
}
static int F_23 ( struct V_3 * V_4 ,
const struct V_41 * V_42 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_5 ;
if ( ! F_24 ( V_4 -> V_43 ,
V_44 |
V_45 |
V_46 ) )
return - V_47 ;
V_17 = F_25 ( & V_4 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_48 ;
V_2 = F_10 ( V_17 ) ;
F_26 ( V_4 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_17 -> V_49 = L_11 ;
V_17 -> V_11 . V_50 = & V_4 -> V_11 ;
V_17 -> V_51 = V_52 ;
V_17 -> V_53 = & V_54 ;
V_17 -> V_55 = V_56 ;
V_17 -> V_57 = F_18 ( V_56 ) ;
F_27 ( & V_2 -> V_8 ) ;
V_5 = F_14 ( V_2 , V_58 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_20 ( V_2 , V_59 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_28 ( & V_4 -> V_11 , V_17 ) ;
}
