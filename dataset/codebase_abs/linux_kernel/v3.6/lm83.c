static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_14 ) ;
long V_15 ;
int V_16 = V_7 -> V_11 ;
int V_17 ;
V_17 = F_8 ( V_5 , 10 , & V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
F_9 ( & V_9 -> V_18 ) ;
V_9 -> V_10 [ V_16 ] = F_10 ( V_15 ) ;
F_11 ( V_14 , V_19 [ V_16 - 4 ] ,
V_9 -> V_10 [ V_16 ] ) ;
F_12 ( & V_9 -> V_18 ) ;
return V_12 ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_20 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_21 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_22 = V_7 -> V_11 ;
return sprintf ( V_5 , L_1 , ( V_9 -> V_21 >> V_22 ) & 1 ) ;
}
static int F_15 ( struct V_13 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_27 ;
const char * V_28 ;
T_3 V_29 , V_30 ;
if ( ! F_16 ( V_27 , V_31 ) )
return - V_32 ;
if ( ( F_17 ( V_23 , V_33 ) & 0xA8 ) ||
( F_17 ( V_23 , V_34 ) & 0x48 ) ||
( F_17 ( V_23 , V_35 ) & 0x41 ) ) {
F_18 ( & V_27 -> V_2 , L_2 ,
V_23 -> V_36 ) ;
return - V_32 ;
}
V_29 = F_17 ( V_23 , V_37 ) ;
if ( V_29 != 0x01 )
return - V_32 ;
V_30 = F_17 ( V_23 , V_38 ) ;
switch ( V_30 ) {
case 0x03 :
V_28 = L_3 ;
break;
case 0x01 :
V_28 = L_4 ;
break;
default:
F_19 ( & V_27 -> V_2 ,
L_5 ,
V_29 , V_30 ) ;
return - V_32 ;
}
F_20 ( V_25 -> type , V_28 , V_39 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_23 ,
const struct V_40 * V_41 )
{
struct V_8 * V_9 ;
int V_17 ;
V_9 = F_22 ( & V_23 -> V_2 , sizeof( struct V_8 ) ,
V_42 ) ;
if ( ! V_9 )
return - V_43 ;
F_23 ( V_23 , V_9 ) ;
V_9 -> V_44 = 0 ;
F_24 ( & V_9 -> V_18 ) ;
V_17 = F_25 ( & V_23 -> V_2 . V_45 , & V_46 ) ;
if ( V_17 )
return V_17 ;
if ( V_41 -> V_47 == V_48 ) {
V_17 = F_25 ( & V_23 -> V_2 . V_45 ,
& V_49 ) ;
if ( V_17 )
goto V_50;
}
V_9 -> V_51 = F_26 ( & V_23 -> V_2 ) ;
if ( F_27 ( V_9 -> V_51 ) ) {
V_17 = F_28 ( V_9 -> V_51 ) ;
goto V_50;
}
return 0 ;
V_50:
F_29 ( & V_23 -> V_2 . V_45 , & V_46 ) ;
F_29 ( & V_23 -> V_2 . V_45 , & V_49 ) ;
return V_17 ;
}
static int F_30 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_7 ( V_14 ) ;
F_31 ( V_9 -> V_51 ) ;
F_29 ( & V_14 -> V_2 . V_45 , & V_46 ) ;
F_29 ( & V_14 -> V_2 . V_45 , & V_49 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_14 ) ;
F_9 ( & V_9 -> V_18 ) ;
if ( F_32 ( V_52 , V_9 -> V_53 + V_54 * 2 ) || ! V_9 -> V_44 ) {
int V_16 ;
F_18 ( & V_14 -> V_2 , L_6 ) ;
for ( V_16 = 0 ; V_16 < 9 ; V_16 ++ ) {
V_9 -> V_10 [ V_16 ] =
F_17 ( V_14 ,
V_55 [ V_16 ] ) ;
}
V_9 -> V_21 =
F_17 ( V_14 , V_33 )
+ ( F_17 ( V_14 , V_34 )
<< 8 ) ;
V_9 -> V_53 = V_52 ;
V_9 -> V_44 = 1 ;
}
F_12 ( & V_9 -> V_18 ) ;
return V_9 ;
}
