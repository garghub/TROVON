static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
V_4 = F_2 ( V_2 ,
V_9 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 , L_1 ) ;
return V_4 ;
}
F_4 ( 100 , 500 ) ;
break;
default:
F_3 ( & V_2 -> V_10 ,
L_2 , V_11 , V_3 ) ;
return - V_12 ;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_15 * V_16 = F_7 ( V_14 ) ;
int V_4 ;
V_4 = F_1 ( V_2 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_8 ( V_2 , V_17 ,
3 , V_16 -> V_18 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 , L_3 ) ;
return V_4 ;
}
V_4 = F_1 ( V_2 , V_8 ) ;
if ( V_4 < 0 )
return V_4 ;
V_16 -> V_19 [ 0 ] = F_9 ( V_16 -> V_18 [ 0 ] ) ;
V_16 -> V_19 [ 1 ] = F_9 ( V_16 -> V_18 [ 1 ] ) ;
V_16 -> V_19 [ 2 ] = F_9 ( V_16 -> V_18 [ 2 ] ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_20 [ 2 ] ;
int V_4 ;
V_4 = F_8 ( V_2 , V_21 ,
2 , V_20 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 , L_4 ) ;
return V_4 ;
}
F_11 ( & V_2 -> V_10 , L_5 , V_20 [ 0 ] , V_20 [ 1 ] ) ;
if ( V_20 [ 0 ] != V_22 ||
V_20 [ 1 ] != V_23 ) {
F_3 ( & V_2 -> V_10 , L_6 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
T_1 V_25 ;
T_2 V_26 = V_27 ;
int V_4 ;
while ( V_26 ) {
F_13 ( V_28 ) ;
V_4 = F_14 ( V_2 , V_29 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 , L_7 ) ;
return V_4 ;
}
V_25 = V_4 & 0x01 ;
if ( V_25 )
break;
V_26 -= V_28 ;
}
if ( ! V_26 ) {
F_3 ( & V_2 -> V_10 , L_8 ) ;
return - V_30 ;
}
return V_25 ;
}
static int F_15 ( struct V_13 * V_14 , int V_31 , int * V_32 )
{
struct V_15 * V_16 = F_7 ( V_14 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_4 ;
F_16 ( & V_16 -> V_33 ) ;
V_4 = F_1 ( V_2 , V_5 ) ;
if ( V_4 < 0 )
goto V_34;
V_4 = F_12 ( V_16 ) ;
if ( V_4 < 0 )
goto V_34;
V_4 = F_17 ( V_2 , V_35 [ V_31 ] ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_10 , L_9 ) ;
goto V_34;
}
F_18 ( & V_16 -> V_33 ) ;
* V_32 = F_19 ( F_20 ( V_36 , V_4 , - 8192 , 8191 ) , 13 ) ;
return V_37 ;
V_34:
F_18 ( & V_16 -> V_33 ) ;
return V_4 ;
}
static int F_21 ( struct V_13 * V_14 ,
struct V_38 const * V_39 ,
int * V_32 , int * V_40 ,
long V_41 )
{
struct V_15 * V_16 = F_7 ( V_14 ) ;
switch ( V_41 ) {
case V_42 :
return F_15 ( V_14 , V_39 -> V_43 , V_32 ) ;
case V_44 :
* V_32 = 0 ;
* V_40 = V_16 -> V_19 [ V_39 -> V_43 ] ;
return V_45 ;
}
return - V_12 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
const char * V_48 ;
int V_4 ;
V_4 = F_10 ( V_2 ) ;
if ( V_4 ) {
F_3 ( & V_2 -> V_10 , L_10 ) ;
return - V_24 ;
}
V_14 = F_23 ( & V_2 -> V_10 , sizeof( * V_16 ) ) ;
if ( V_14 == NULL )
return - V_49 ;
V_16 = F_7 ( V_14 ) ;
F_24 ( V_2 , V_14 ) ;
V_16 -> V_2 = V_2 ;
F_25 ( & V_16 -> V_33 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_47 )
V_48 = V_47 -> V_48 ;
else if ( F_26 ( & V_2 -> V_10 ) )
V_48 = F_27 ( & V_2 -> V_10 ) ;
else
return - V_24 ;
F_11 ( & V_2 -> V_10 , L_11 , V_48 ) ;
V_14 -> V_10 . V_50 = & V_2 -> V_10 ;
V_14 -> V_51 = V_52 ;
V_14 -> V_53 = F_28 ( V_52 ) ;
V_14 -> V_54 = & V_55 ;
V_14 -> V_56 = V_57 ;
V_14 -> V_48 = V_48 ;
return F_29 ( & V_2 -> V_10 , V_14 ) ;
}
