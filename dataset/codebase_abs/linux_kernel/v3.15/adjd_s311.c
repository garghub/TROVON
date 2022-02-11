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
static T_2 F_9 ( int V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_19 = F_10 () ;
int V_20 , V_21 = 0 ;
int V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
goto V_22;
F_11 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_6 = F_8 ( V_4 -> V_7 ,
F_12 ( V_20 ) ) ;
if ( V_6 < 0 )
goto V_22;
V_4 -> V_23 [ V_21 ++ ] = V_6 & V_14 ;
}
F_13 ( V_2 , V_4 -> V_23 , V_19 ) ;
V_22:
F_14 ( V_2 -> V_24 ) ;
return V_25 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_26 const * V_27 ,
int * V_13 , int * V_28 , long V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_29 ) {
case V_30 :
V_6 = F_7 ( V_2 ,
F_12 ( V_27 -> V_31 ) , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_32 ;
case V_33 :
V_6 = F_4 ( V_4 -> V_7 ,
F_16 ( V_27 -> V_31 ) ) ;
if ( V_6 < 0 )
return V_6 ;
* V_13 = V_6 & V_34 ;
return V_32 ;
case V_35 :
V_6 = F_8 ( V_4 -> V_7 ,
F_17 ( V_27 -> V_31 ) ) ;
if ( V_6 < 0 )
return V_6 ;
* V_13 = 0 ;
* V_28 = V_6 & V_36 ;
return V_37 ;
}
return - V_38 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_26 const * V_27 ,
int V_13 , int V_28 , long V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_29 ) {
case V_33 :
if ( V_13 < 0 || V_13 > V_34 )
return - V_38 ;
return F_3 ( V_4 -> V_7 ,
F_16 ( V_27 -> V_31 ) , V_13 ) ;
case V_35 :
if ( V_13 != 0 || V_28 < 0 || V_28 > V_36 )
return - V_38 ;
return F_19 ( V_4 -> V_7 ,
F_17 ( V_27 -> V_31 ) , V_28 ) ;
}
return - V_38 ;
}
static int F_20 ( struct V_1 * V_2 ,
const unsigned long * V_39 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_21 ( V_4 -> V_23 ) ;
V_4 -> V_23 = F_22 ( V_2 -> V_40 , V_41 ) ;
if ( V_4 -> V_23 == NULL )
return - V_42 ;
return 0 ;
}
static int F_23 ( struct V_43 * V_7 ,
const struct V_44 * V_45 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_24 ( & V_7 -> V_10 , sizeof( * V_4 ) ) ;
if ( V_2 == NULL )
return - V_42 ;
V_4 = F_2 ( V_2 ) ;
F_25 ( V_7 , V_2 ) ;
V_4 -> V_7 = V_7 ;
V_2 -> V_10 . V_47 = & V_7 -> V_10 ;
V_2 -> V_48 = & V_49 ;
V_2 -> V_50 = V_51 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = F_26 ( V_53 ) ;
V_2 -> V_55 = V_56 ;
V_46 = F_27 ( V_2 , NULL ,
F_9 , NULL ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_28 ( V_2 ) ;
if ( V_46 )
goto V_57;
F_29 ( & V_7 -> V_10 , L_2 ) ;
return 0 ;
V_57:
F_30 ( V_2 ) ;
return V_46 ;
}
static int F_31 ( struct V_43 * V_7 )
{
struct V_1 * V_2 = F_32 ( V_7 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
F_30 ( V_2 ) ;
F_21 ( V_4 -> V_23 ) ;
return 0 ;
}
