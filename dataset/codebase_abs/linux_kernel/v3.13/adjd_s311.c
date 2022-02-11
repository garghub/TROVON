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
int V_20 = 0 ;
int V_21 , V_22 = 0 ;
int V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
goto V_23;
F_11 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_6 = F_8 ( V_4 -> V_7 ,
F_12 ( V_21 ) ) ;
if ( V_6 < 0 )
goto V_23;
V_4 -> V_24 [ V_22 ++ ] = V_6 & V_14 ;
V_20 += 2 ;
}
F_13 ( V_2 , V_4 -> V_24 , V_19 ) ;
V_23:
F_14 ( V_2 -> V_25 ) ;
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_27 const * V_28 ,
int * V_13 , int * V_29 , long V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_30 ) {
case V_31 :
V_6 = F_7 ( V_2 ,
F_12 ( V_28 -> V_32 ) , V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_33 ;
case V_34 :
V_6 = F_4 ( V_4 -> V_7 ,
F_16 ( V_28 -> V_32 ) ) ;
if ( V_6 < 0 )
return V_6 ;
* V_13 = V_6 & V_35 ;
return V_33 ;
case V_36 :
V_6 = F_8 ( V_4 -> V_7 ,
F_17 ( V_28 -> V_32 ) ) ;
if ( V_6 < 0 )
return V_6 ;
* V_13 = 0 ;
* V_29 = V_6 & V_37 ;
return V_38 ;
}
return - V_39 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_27 const * V_28 ,
int V_13 , int V_29 , long V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_30 ) {
case V_34 :
if ( V_13 < 0 || V_13 > V_35 )
return - V_39 ;
return F_3 ( V_4 -> V_7 ,
F_16 ( V_28 -> V_32 ) , V_13 ) ;
case V_36 :
if ( V_13 != 0 || V_29 < 0 || V_29 > V_37 )
return - V_39 ;
return F_19 ( V_4 -> V_7 ,
F_17 ( V_28 -> V_32 ) , V_29 ) ;
}
return - V_39 ;
}
static int F_20 ( struct V_1 * V_2 ,
const unsigned long * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_21 ( V_4 -> V_24 ) ;
V_4 -> V_24 = F_22 ( V_2 -> V_41 , V_42 ) ;
if ( V_4 -> V_24 == NULL )
return - V_43 ;
return 0 ;
}
static int F_23 ( struct V_44 * V_7 ,
const struct V_45 * V_46 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_47 ;
V_2 = F_24 ( & V_7 -> V_10 , sizeof( * V_4 ) ) ;
if ( V_2 == NULL )
return - V_43 ;
V_4 = F_2 ( V_2 ) ;
F_25 ( V_7 , V_2 ) ;
V_4 -> V_7 = V_7 ;
V_2 -> V_10 . V_48 = & V_7 -> V_10 ;
V_2 -> V_49 = & V_50 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = F_26 ( V_54 ) ;
V_2 -> V_56 = V_57 ;
V_47 = F_27 ( V_2 , NULL ,
F_9 , NULL ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_28 ( V_2 ) ;
if ( V_47 )
goto V_58;
F_29 ( & V_7 -> V_10 , L_2 ) ;
return 0 ;
V_58:
F_30 ( V_2 ) ;
return V_47 ;
}
static int F_31 ( struct V_44 * V_7 )
{
struct V_1 * V_2 = F_32 ( V_7 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
F_30 ( V_2 ) ;
F_21 ( V_4 -> V_24 ) ;
return 0 ;
}
