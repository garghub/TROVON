static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
return F_3 ( V_2 -> V_5 , & V_4 , sizeof( V_4 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_4 [ 3 ] ;
V_4 [ 0 ] = ( V_3 >> 16 ) & 0xFF ;
V_4 [ 1 ] = ( V_3 >> 8 ) & 0xFF ;
V_4 [ 2 ] = V_3 & 0xFF ;
return F_3 ( V_2 -> V_5 , V_4 , sizeof( V_4 ) ) ;
}
static T_3 F_5 ( struct V_6 * V_7 ,
T_4 V_8 , const struct V_9 * V_10 , char * V_11 )
{
return sprintf ( V_11 , L_1 , V_12 [ 1 ] ,
V_12 [ 2 ] , V_12 [ 3 ] ) ;
}
static T_3 F_6 ( struct V_6 * V_7 ,
T_4 V_8 ,
const struct V_9 * V_10 ,
const char * V_11 , T_5 V_13 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
int V_14 ;
for ( V_14 = 1 ; V_14 < F_8 ( V_12 ) ; V_14 ++ ) {
if ( F_9 ( V_11 , V_12 [ V_14 ] ) ) {
V_2 -> V_15 = V_14 ;
break;
}
}
if ( V_14 == F_8 ( V_12 ) )
return - V_16 ;
return V_13 ;
}
static T_3 F_10 ( struct V_6 * V_7 ,
T_4 V_8 ,
const struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
return sprintf ( V_11 , L_2 , V_12 [ V_2 -> V_15 ] ) ;
}
static T_3 F_11 ( struct V_6 * V_7 ,
T_4 V_8 ,
const struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
return sprintf ( V_11 , L_3 , V_2 -> V_17 ) ;
}
static T_3 F_12 ( struct V_6 * V_7 ,
T_4 V_8 ,
const struct V_9 * V_10 ,
const char * V_11 , T_5 V_13 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
unsigned int V_18 ;
unsigned int V_3 ;
bool V_19 ;
int V_20 ;
V_20 = F_13 ( V_11 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_7 -> V_21 ) ;
V_2 -> V_17 = V_19 ;
if ( V_2 -> V_17 ) {
V_18 = V_10 -> V_22 . V_23 + V_10 -> V_22 . V_18 ;
V_3 = V_2 -> V_15 << V_18 ;
} else {
V_3 = V_2 -> V_24 ;
}
V_20 = V_2 -> V_25 -> V_26 ( V_2 , V_3 ) ;
F_15 ( & V_7 -> V_21 ) ;
return V_20 ? V_20 : V_13 ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_9 const * V_10 ,
int * V_3 ,
int * V_27 ,
long V_28 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
unsigned long V_29 ;
switch ( V_28 ) {
case V_30 :
* V_3 = V_2 -> V_24 ;
return V_31 ;
case V_32 :
V_29 = ( V_2 -> V_33 * 1000 ) >> V_10 -> V_22 . V_23 ;
* V_3 = V_29 / 1000 ;
* V_27 = ( V_29 % 1000 ) * 1000 ;
return V_34 ;
}
return - V_16 ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_9 const * V_10 ,
int V_3 ,
int V_27 ,
long V_35 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
int V_20 = 0 ;
switch ( V_35 ) {
case V_30 :
if ( V_3 >= ( 1 << V_10 -> V_22 . V_23 ) || V_3 < 0 )
return - V_16 ;
V_3 <<= V_10 -> V_22 . V_18 ;
F_14 ( & V_7 -> V_21 ) ;
V_2 -> V_24 = V_3 ;
if ( ! V_2 -> V_17 )
V_20 = V_2 -> V_25 -> V_26 ( V_2 , V_3 ) ;
F_15 ( & V_7 -> V_21 ) ;
break;
default:
V_20 = - V_16 ;
}
return V_20 ;
}
static int T_6 F_18 ( struct V_36 * V_5 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_37 * V_38 ;
int V_20 , V_39 = 0 ;
V_38 = F_19 ( & V_5 -> V_40 , L_4 ) ;
if ( ! F_20 ( V_38 ) ) {
V_20 = F_21 ( V_38 ) ;
if ( V_20 )
goto V_41;
V_39 = F_22 ( V_38 ) ;
}
V_7 = F_23 ( sizeof( * V_2 ) ) ;
if ( V_7 == NULL ) {
V_20 = - V_42 ;
goto V_43;
}
V_2 = F_7 ( V_7 ) ;
V_2 -> V_25 =
& V_44 [ F_24 ( V_5 ) -> V_45 ] ;
F_25 ( V_5 , V_7 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_5 = V_5 ;
V_7 -> V_40 . V_46 = & V_5 -> V_40 ;
V_7 -> V_47 = F_24 ( V_5 ) -> V_47 ;
V_7 -> V_48 = & V_49 ;
V_7 -> V_50 = V_51 ;
V_7 -> V_52 = & V_2 -> V_25 -> V_53 ;
V_7 -> V_54 = 1 ;
if ( V_2 -> V_25 -> V_55 )
V_2 -> V_33 = V_2 -> V_25 -> V_55 ;
else if ( V_39 )
V_2 -> V_33 = V_39 / 1000 ;
else
F_26 ( & V_5 -> V_40 , L_5 ) ;
V_20 = F_27 ( V_7 ) ;
if ( V_20 )
goto V_56;
return 0 ;
V_56:
F_28 ( V_7 ) ;
V_43:
if ( ! F_20 ( V_38 ) )
F_29 ( V_38 ) ;
V_41:
if ( ! F_20 ( V_38 ) )
F_30 ( V_38 ) ;
return V_20 ;
}
static int F_31 ( struct V_36 * V_5 )
{
struct V_6 * V_7 = F_32 ( V_5 ) ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
F_33 ( V_7 ) ;
if ( ! F_20 ( V_2 -> V_38 ) ) {
F_29 ( V_2 -> V_38 ) ;
F_30 ( V_2 -> V_38 ) ;
}
F_28 ( V_7 ) ;
return 0 ;
}
