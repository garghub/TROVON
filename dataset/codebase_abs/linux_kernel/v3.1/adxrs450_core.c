static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
struct V_12 V_13 [] = {
{
. V_14 = V_10 -> V_15 ,
. V_16 = 8 ,
. V_17 = 4 ,
. V_18 = 1 ,
} , {
. V_19 = V_10 -> V_20 ,
. V_16 = 8 ,
. V_17 = 4 ,
} ,
} ;
F_4 ( & V_10 -> V_21 ) ;
V_10 -> V_15 [ 0 ] = V_22 | ( V_3 >> 7 ) ;
V_10 -> V_15 [ 1 ] = V_3 << 1 ;
V_10 -> V_15 [ 2 ] = 0 ;
V_10 -> V_15 [ 3 ] = 0 ;
if ( ! ( F_5 ( F_6 ( * ( V_23 * ) V_10 -> V_15 ) ) & 1 ) )
V_10 -> V_15 [ 3 ] |= V_24 ;
F_7 ( & V_6 ) ;
F_8 ( & V_13 [ 0 ] , & V_6 ) ;
F_8 ( & V_13 [ 1 ] , & V_6 ) ;
V_11 = F_9 ( V_10 -> V_25 , & V_6 ) ;
if ( V_11 ) {
F_10 ( & V_10 -> V_25 -> V_2 , L_1 ,
V_3 ) ;
goto V_26;
}
* V_4 = ( F_6 ( * ( V_23 * ) V_10 -> V_20 ) >> 5 ) & 0xFFFF ;
V_26:
F_11 ( & V_10 -> V_21 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
struct V_12 V_13 = {
. V_14 = V_10 -> V_15 ,
. V_19 = V_10 -> V_20 ,
. V_16 = 8 ,
. V_17 = 4 ,
} ;
F_4 ( & V_10 -> V_21 ) ;
V_10 -> V_15 [ 0 ] = V_27 | V_3 >> 7 ;
V_10 -> V_15 [ 1 ] = V_3 << 1 | V_4 >> 15 ;
V_10 -> V_15 [ 2 ] = V_4 >> 7 ;
V_10 -> V_15 [ 3 ] = V_4 << 1 ;
if ( ! ( F_5 ( F_6 ( * ( V_23 * ) V_10 -> V_15 ) ) & 1 ) )
V_10 -> V_15 [ 3 ] |= V_24 ;
F_7 ( & V_6 ) ;
F_8 ( & V_13 , & V_6 ) ;
V_11 = F_9 ( V_10 -> V_25 , & V_6 ) ;
if ( V_11 )
F_10 ( & V_10 -> V_25 -> V_2 , L_2 ,
V_3 ) ;
F_13 ( 1 ) ;
F_11 ( & V_10 -> V_21 ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 , T_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
struct V_12 V_13 [] = {
{
. V_14 = V_10 -> V_15 ,
. V_16 = 8 ,
. V_17 = 4 ,
. V_18 = 1 ,
} , {
. V_19 = V_10 -> V_20 ,
. V_16 = 8 ,
. V_17 = 4 ,
} ,
} ;
F_4 ( & V_10 -> V_21 ) ;
V_10 -> V_15 [ 0 ] = V_28 ;
V_10 -> V_15 [ 1 ] = 0 ;
V_10 -> V_15 [ 2 ] = 0 ;
V_10 -> V_15 [ 3 ] = 0 ;
F_7 ( & V_6 ) ;
F_8 ( & V_13 [ 0 ] , & V_6 ) ;
F_8 ( & V_13 [ 1 ] , & V_6 ) ;
V_11 = F_9 ( V_10 -> V_25 , & V_6 ) ;
if ( V_11 ) {
F_10 ( & V_10 -> V_25 -> V_2 , L_3 ) ;
goto V_26;
}
* V_4 = ( F_6 ( * ( V_23 * ) V_10 -> V_20 ) >> 10 ) & 0xFFFF ;
V_26:
F_11 ( & V_10 -> V_21 ) ;
return V_11 ;
}
static int F_15 ( struct V_9 * V_10 ,
V_23 * V_4 , char V_29 )
{
struct V_5 V_6 ;
int V_11 ;
struct V_12 V_13 = {
. V_14 = V_10 -> V_15 ,
. V_19 = V_10 -> V_20 ,
. V_16 = 8 ,
. V_17 = 4 ,
} ;
F_4 ( & V_10 -> V_21 ) ;
V_10 -> V_15 [ 0 ] = V_28 ;
V_10 -> V_15 [ 1 ] = 0 ;
V_10 -> V_15 [ 2 ] = 0 ;
V_10 -> V_15 [ 3 ] = 0 ;
if ( V_29 )
V_10 -> V_15 [ 3 ] |= ( V_30 | V_24 ) ;
F_7 ( & V_6 ) ;
F_8 ( & V_13 , & V_6 ) ;
V_11 = F_9 ( V_10 -> V_25 , & V_6 ) ;
if ( V_11 ) {
F_10 ( & V_10 -> V_25 -> V_2 , L_4 ) ;
goto V_26;
}
* V_4 = F_6 ( * ( V_23 * ) V_10 -> V_20 ) ;
V_26:
F_11 ( & V_10 -> V_21 ) ;
return V_11 ;
}
static T_4 F_16 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
char * V_33 )
{
int V_11 ;
T_2 V_34 ;
V_11 = F_1 ( V_2 ,
V_35 ,
& V_34 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_33 , L_5 , V_34 >> 7 ) ;
}
static T_4 F_17 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
char * V_33 )
{
int V_11 ;
T_3 V_34 ;
V_11 = F_1 ( V_2 ,
V_36 ,
& V_34 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_33 , L_5 , V_34 ) ;
}
static T_4 F_18 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_5 V_17 )
{
int V_11 ;
long V_4 ;
V_11 = F_19 ( V_33 , 10 , & V_4 ) ;
if ( V_11 )
goto V_26;
V_11 = F_12 ( V_2 ,
V_37 ,
V_4 & 0x3FF ) ;
V_26:
return V_11 ? V_11 : V_17 ;
}
static T_4 F_20 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
char * V_33 )
{
int V_11 ;
T_3 V_34 ;
V_11 = F_14 ( V_2 , & V_34 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_33 , L_5 , V_34 ) ;
}
static int F_21 ( struct V_7 * V_8 )
{
V_23 V_34 ;
T_2 V_38 ;
int V_11 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_13 ( V_39 * 2 ) ;
V_11 = F_15 ( V_10 , & V_34 , 1 ) ;
if ( V_11 )
return V_11 ;
if ( V_34 != 0x01 )
F_22 ( & V_10 -> V_25 -> V_2 , L_6
L_7 ) ;
F_13 ( V_39 ) ;
V_11 = F_15 ( V_10 , & V_34 , 0 ) ;
if ( V_11 )
return V_11 ;
F_13 ( V_39 ) ;
V_11 = F_15 ( V_10 , & V_34 , 0 ) ;
if ( V_11 )
return V_11 ;
if ( ( ( V_34 & 0xff ) | 0x01 ) != 0xff || F_23 ( V_34 ) != 2 ) {
F_10 ( & V_10 -> V_25 -> V_2 , L_8 ) ;
return - V_40 ;
}
V_11 = F_15 ( V_10 , & V_34 , 0 ) ;
if ( V_11 )
return V_11 ;
if ( ( ( V_34 & 0xff ) | 0x01 ) != 0xff || F_23 ( V_34 ) != 2 ) {
F_10 ( & V_10 -> V_25 -> V_2 , L_9 ) ;
return - V_40 ;
}
V_11 = F_1 ( V_2 , V_41 , & V_38 ) ;
if ( V_11 )
return V_11 ;
if ( V_38 & 0x0fff ) {
F_10 ( & V_10 -> V_25 -> V_2 , L_10 ) ;
return - V_42 ;
}
V_11 = F_1 ( V_2 , V_43 , & V_38 ) ;
if ( V_11 )
return V_11 ;
F_24 ( & V_10 -> V_25 -> V_2 , L_11 , V_38 ) ;
V_11 = F_1 ( V_2 , V_44 , & V_38 ) ;
if ( V_11 )
return V_11 ;
V_34 = V_38 ;
V_11 = F_1 ( V_2 , V_45 , & V_38 ) ;
if ( V_11 )
return V_11 ;
V_34 |= V_38 << 16 ;
F_24 ( & V_10 -> V_25 -> V_2 , L_12 , V_34 ) ;
return 0 ;
}
static int T_6 F_25 ( struct V_46 * V_47 )
{
int V_11 , V_48 = 0 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
V_8 = F_26 ( sizeof( * V_10 ) ) ;
if ( V_8 == NULL ) {
V_11 = - V_49 ;
goto V_26;
}
V_10 = F_3 ( V_8 ) ;
V_10 -> V_25 = V_47 ;
F_27 ( & V_10 -> V_21 ) ;
F_28 ( V_47 , V_8 ) ;
V_8 -> V_2 . V_50 = & V_47 -> V_2 ;
V_8 -> V_51 = & V_52 ;
V_8 -> V_53 = V_54 ;
V_11 = F_29 ( V_8 ) ;
if ( V_11 )
goto V_55;
V_48 = 1 ;
V_11 = F_21 ( V_8 ) ;
if ( V_11 )
goto V_56;
return 0 ;
V_56:
V_55:
if ( V_48 )
F_30 ( V_8 ) ;
else
F_31 ( V_8 ) ;
V_26:
return V_11 ;
}
static int F_32 ( struct V_46 * V_47 )
{
F_30 ( F_33 ( V_47 ) ) ;
return 0 ;
}
static T_7 int F_34 ( void )
{
return F_35 ( & V_57 ) ;
}
static T_8 void F_36 ( void )
{
F_37 ( & V_57 ) ;
}
