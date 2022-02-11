static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_4 ( V_9 -> V_12 , V_7 -> V_13 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_14 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_4 ( V_9 -> V_12 , V_7 -> V_15 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_2 , ! ! ( V_10 & V_7 -> V_13 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
if ( F_8 ( V_5 , 10 , & V_10 ) )
return - V_17 ;
V_11 = F_9 ( V_9 -> V_12 , V_7 -> V_13 ,
F_10 ( V_10 , 1000 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return V_16 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_16 )
{
struct V_14 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
if ( F_8 ( V_5 , 10 , & V_10 ) )
return - V_17 ;
V_11 = F_12 ( V_9 -> V_12 , V_7 -> V_15 , V_7 -> V_13 ,
V_10 ? V_7 -> V_13 : 0 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_16 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ,
bool V_18 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
unsigned int V_19 ;
unsigned int V_20 ;
int V_11 ;
V_11 = F_4 ( V_12 , V_7 -> V_13 , & V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_12 , 0x21 , & V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_18 ? V_19 + V_20 : V_19 - V_20 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_13 ( V_2 , V_4 , V_5 , false ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_13 ( V_2 , V_4 , V_5 , true ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
unsigned int V_19 ;
int V_11 ;
int V_20 ;
unsigned long V_10 ;
if ( F_8 ( V_5 , 10 , & V_10 ) )
return - V_17 ;
F_17 ( & V_9 -> V_21 ) ;
V_11 = F_4 ( V_12 , V_7 -> V_13 , & V_19 ) ;
if ( V_11 < 0 )
goto V_22;
V_20 = V_19 * 1000 - V_10 ;
V_20 = F_18 ( F_10 ( V_20 , 1000 ) , 0 , 255 ) ;
V_11 = F_9 ( V_12 , 0x21 , V_20 ) ;
if ( V_11 == 0 )
V_11 = V_16 ;
V_22:
F_19 ( & V_9 -> V_21 ) ;
return V_11 ;
}
static int F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
int V_27 ;
V_27 = F_21 ( V_24 , V_28 ) ;
if ( V_27 != 0x5d )
return - V_29 ;
V_27 = F_21 ( V_24 , V_30 ) ;
switch ( V_27 ) {
case 0x20 :
F_22 ( V_26 -> type , L_3 , V_31 ) ;
break;
case 0x21 :
F_22 ( V_26 -> type , L_4 , V_31 ) ;
break;
case 0x22 :
F_22 ( V_26 -> type , L_5 , V_31 ) ;
break;
case 0x23 :
F_22 ( V_26 -> type , L_6 , V_31 ) ;
break;
case 0x25 :
F_22 ( V_26 -> type , L_7 , V_31 ) ;
break;
case 0x27 :
F_22 ( V_26 -> type , L_8 , V_31 ) ;
break;
default:
return - V_29 ;
}
V_27 = F_21 ( V_24 , V_32 ) ;
if ( V_27 < 0x01 || V_27 > 0x04 )
return - V_29 ;
return 0 ;
}
static bool F_23 ( struct V_1 * V_2 , unsigned int V_33 )
{
switch ( V_33 ) {
case 0x00 :
case 0x01 :
case 0x02 :
case 0x10 :
case 0x1b :
case 0x23 :
case 0x24 :
case 0x29 :
case 0x2a :
case 0x2b :
case 0x35 :
case 0x36 :
case 0x37 :
return true ;
default:
return false ;
}
}
static int F_24 ( struct V_23 * V_24 ,
const struct V_34 * V_27 )
{
struct V_8 * V_9 ;
struct V_1 * V_35 ;
V_9 = F_25 ( & V_24 -> V_2 , sizeof( struct V_8 ) ,
V_36 ) ;
if ( V_9 == NULL )
return - V_37 ;
V_9 -> V_12 = F_26 ( V_24 , & V_38 ) ;
if ( F_27 ( V_9 -> V_12 ) )
return F_28 ( V_9 -> V_12 ) ;
F_29 ( & V_9 -> V_21 ) ;
switch ( V_27 -> V_39 ) {
case V_40 :
V_9 -> V_41 [ 2 ] = & V_42 ;
case V_43 :
V_9 -> V_41 [ 1 ] = & V_44 ;
case V_45 :
V_9 -> V_41 [ 0 ] = & V_46 ;
}
if ( V_27 -> V_39 == V_45 )
V_9 -> V_41 [ 1 ] = & V_47 ;
V_35 = F_30 ( & V_24 -> V_2 ,
V_24 -> V_48 , V_9 ,
V_9 -> V_41 ) ;
if ( F_27 ( V_35 ) )
return F_28 ( V_35 ) ;
F_31 ( & V_24 -> V_2 , L_9 , V_27 -> V_48 ) ;
return 0 ;
}
