static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_7 ) ;
if ( F_4 ( V_8 , V_4 -> V_9 + V_10 * 2 ) || ! V_4 -> V_11 ) {
int V_12 ;
F_5 ( & V_6 -> V_3 , L_1 ) ;
for ( V_12 = 0 ; V_12 < 9 ; V_12 ++ ) {
V_4 -> V_13 [ V_12 ] =
F_6 ( V_6 ,
V_14 [ V_12 ] ) ;
}
V_4 -> V_15 =
F_6 ( V_6 , V_16 )
+ ( F_6 ( V_6 , V_17 )
<< 8 ) ;
V_4 -> V_9 = V_8 ;
V_4 -> V_11 = 1 ;
}
F_7 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static T_1 F_8 ( struct V_2 * V_3 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_20 , L_2 , F_10 ( V_4 -> V_13 [ V_22 -> V_23 ] ) ) ;
}
static T_1 F_11 ( struct V_2 * V_3 , struct V_18 * V_19 ,
const char * V_20 , T_2 V_24 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_25 ;
int V_12 = V_22 -> V_23 ;
int V_26 ;
V_26 = F_12 ( V_20 , 10 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_13 [ V_12 ] = F_13 ( V_25 ) ;
F_14 ( V_6 , V_27 [ V_12 - 4 ] ,
V_4 -> V_13 [ V_12 ] ) ;
F_7 ( & V_4 -> V_7 ) ;
return V_24 ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_18 * V_28 ,
char * V_20 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_20 , L_2 , V_4 -> V_15 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_18
* V_19 , char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_29 = V_22 -> V_23 ;
return sprintf ( V_20 , L_2 , ( V_4 -> V_15 >> V_29 ) & 1 ) ;
}
static int F_17 ( struct V_5 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_30 -> V_34 ;
const char * V_35 ;
T_3 V_36 , V_37 ;
if ( ! F_18 ( V_34 , V_38 ) )
return - V_39 ;
if ( ( F_6 ( V_30 , V_16 ) & 0xA8 ) ||
( F_6 ( V_30 , V_17 ) & 0x48 ) ||
( F_6 ( V_30 , V_40 ) & 0x41 ) ) {
F_5 ( & V_34 -> V_3 , L_3 ,
V_30 -> V_41 ) ;
return - V_39 ;
}
V_36 = F_6 ( V_30 , V_42 ) ;
if ( V_36 != 0x01 )
return - V_39 ;
V_37 = F_6 ( V_30 , V_43 ) ;
switch ( V_37 ) {
case 0x03 :
V_35 = L_4 ;
break;
case 0x01 :
V_35 = L_5 ;
break;
default:
F_19 ( & V_34 -> V_3 ,
L_6 ,
V_36 , V_37 ) ;
return - V_39 ;
}
F_20 ( V_32 -> type , V_35 , V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_30 ,
const struct V_45 * V_46 )
{
struct V_2 * V_47 ;
struct V_1 * V_4 ;
V_4 = F_22 ( & V_30 -> V_3 , sizeof( struct V_1 ) ,
V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_4 -> V_6 = V_30 ;
F_23 ( & V_4 -> V_7 ) ;
V_4 -> V_50 [ 0 ] = & V_51 ;
if ( V_46 -> V_52 == V_53 )
V_4 -> V_50 [ 1 ] = & V_54 ;
V_47 = F_24 ( & V_30 -> V_3 ,
V_30 -> V_35 ,
V_4 , V_4 -> V_50 ) ;
return F_25 ( V_47 ) ;
}
