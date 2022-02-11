static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 10 ;
int V_6 = F_3 ( V_4 -> V_7 , V_8 ,
V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
while ( V_5 -- ) {
V_6 = F_4 ( V_4 -> V_7 , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & V_9 ) )
break;
F_5 ( 20 ) ;
}
if ( V_5 < 0 ) {
F_6 ( & V_4 -> V_7 -> V_10 ,
L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_12 , int * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_4 -> V_7 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_13 = V_6 & V_14 ;
return 0 ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
T_3 V_15 , const struct V_16 * V_17 , char * V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_6 ;
V_6 = F_8 ( V_4 -> V_7 ,
F_10 ( V_17 -> V_19 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return sprintf ( V_18 , L_2 , V_6 & V_20 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 ,
T_3 V_15 , const struct V_16 * V_17 , const char * V_18 ,
T_5 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_22 ;
int V_6 ;
V_6 = F_12 ( V_18 , 10 , & V_22 ) ;
if ( V_6 )
return V_6 ;
if ( V_22 > V_20 )
return - V_23 ;
V_6 = F_13 ( V_4 -> V_7 ,
F_10 ( V_17 -> V_19 ) , V_22 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_21 ;
}
static T_6 F_14 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
T_7 V_30 = F_15 () ;
int V_21 = 0 ;
int V_31 , V_32 = 0 ;
int V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
goto V_33;
F_16 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_6 = F_8 ( V_4 -> V_7 ,
F_17 ( V_31 ) ) ;
if ( V_6 < 0 )
goto V_33;
V_4 -> V_29 [ V_32 ++ ] = V_6 & V_14 ;
V_21 += 2 ;
}
if ( V_2 -> V_34 )
* ( T_7 * ) ( ( T_1 * ) V_4 -> V_29 + F_18 ( V_21 , sizeof( T_7 ) ) )
= V_30 ;
F_19 ( V_29 , ( T_1 * ) V_4 -> V_29 , V_30 ) ;
V_33:
F_20 ( V_2 -> V_35 ) ;
return V_36 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_16 const * V_17 ,
int * V_13 , int * V_37 , long V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_38 ) {
case V_39 :
V_6 = F_7 ( V_2 , V_17 -> V_19 , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_40 ;
case V_41 :
V_6 = F_4 ( V_4 -> V_7 ,
F_22 ( V_17 -> V_19 ) ) ;
if ( V_6 < 0 )
return V_6 ;
* V_13 = V_6 & V_42 ;
return V_40 ;
}
return - V_23 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_16 const * V_17 ,
int V_13 , int V_37 , long V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_38 ) {
case V_41 :
if ( V_13 < 0 || V_13 > V_42 )
return - V_23 ;
V_6 = F_3 ( V_4 -> V_7 ,
F_22 ( V_17 -> V_19 ) , V_13 ) ;
return V_6 ;
}
return - V_23 ;
}
static int F_24 ( struct V_1 * V_2 ,
const unsigned long * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 -> V_29 ) ;
V_4 -> V_29 = F_26 ( V_2 -> V_44 , V_45 ) ;
if ( V_4 -> V_29 == NULL )
return - V_46 ;
return 0 ;
}
static int T_8 F_27 ( struct V_47 * V_7 ,
const struct V_48 * V_49 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_50 ;
V_2 = F_28 ( sizeof( * V_4 ) ) ;
if ( V_2 == NULL ) {
V_50 = - V_46 ;
goto exit;
}
V_4 = F_2 ( V_2 ) ;
F_29 ( V_7 , V_2 ) ;
V_4 -> V_7 = V_7 ;
V_2 -> V_10 . V_51 = & V_7 -> V_10 ;
V_2 -> V_52 = & V_53 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = F_30 ( V_57 ) ;
V_2 -> V_59 = V_60 ;
V_50 = F_31 ( V_2 , NULL ,
F_14 , NULL ) ;
if ( V_50 < 0 )
goto V_61;
V_50 = F_32 ( V_2 ) ;
if ( V_50 )
goto V_62;
F_33 ( & V_7 -> V_10 , L_3 ) ;
return 0 ;
V_62:
F_34 ( V_2 ) ;
V_61:
F_35 ( V_2 ) ;
exit:
return V_50 ;
}
static int T_9 F_36 ( struct V_47 * V_7 )
{
struct V_1 * V_2 = F_37 ( V_7 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_2 ) ;
F_34 ( V_2 ) ;
F_25 ( V_4 -> V_29 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
