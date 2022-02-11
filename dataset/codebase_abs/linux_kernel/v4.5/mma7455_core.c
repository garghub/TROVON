static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 = 3 ;
int V_5 ;
while ( V_4 -- > 0 ) {
V_5 = F_2 ( V_2 -> V_6 , V_7 , & V_3 ) ;
if ( V_5 )
return V_5 ;
if ( V_3 & V_8 )
return 0 ;
F_3 ( 20 ) ;
}
F_4 ( V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
static T_1 F_5 ( int V_11 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
T_2 V_17 [ 16 ] ;
int V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
goto V_18;
V_5 = F_7 ( V_2 -> V_6 , V_19 , V_17 ,
sizeof( V_20 ) * 3 ) ;
if ( V_5 )
goto V_18;
F_8 ( V_16 , V_17 , F_9 () ) ;
V_18:
F_10 ( V_16 -> V_21 ) ;
return V_22 ;
}
static int F_11 ( struct V_15 * V_16 ,
struct V_23 const * V_24 ,
int * V_25 , int * V_26 , long V_27 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
unsigned int V_3 ;
V_20 V_28 ;
int V_5 ;
switch ( V_27 ) {
case V_29 :
if ( F_12 ( V_16 ) )
return - V_30 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( V_2 -> V_6 , V_24 -> V_31 , & V_28 ,
sizeof( V_28 ) ) ;
if ( V_5 )
return V_5 ;
* V_25 = F_13 ( F_14 ( V_28 ) , 9 ) ;
return V_32 ;
case V_33 :
* V_25 = 0 ;
* V_26 = V_34 ;
return V_35 ;
case V_36 :
V_5 = F_2 ( V_2 -> V_6 , V_37 , & V_3 ) ;
if ( V_5 )
return V_5 ;
if ( V_3 & V_38 )
* V_25 = 250 ;
else
* V_25 = 125 ;
return V_32 ;
}
return - V_39 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_23 const * V_24 ,
int V_25 , int V_26 , long V_27 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
int V_40 ;
switch ( V_27 ) {
case V_36 :
if ( V_25 == 250 && V_26 == 0 )
V_40 = V_41 ;
else if ( V_25 == 125 && V_26 == 0 )
V_40 = V_42 ;
else
return - V_39 ;
return F_16 ( V_2 -> V_6 , V_37 ,
V_38 , V_40 ) ;
case V_33 :
if ( V_25 == 0 && V_26 == V_34 )
return 0 ;
break;
}
return - V_39 ;
}
int F_17 ( struct V_43 * V_9 , struct V_6 * V_6 ,
const char * V_44 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
unsigned int V_3 ;
int V_5 ;
V_5 = F_2 ( V_6 , V_45 , & V_3 ) ;
if ( V_5 ) {
F_18 ( V_9 , L_2 ) ;
return V_5 ;
}
if ( V_3 != V_46 ) {
F_18 ( V_9 , L_3 ) ;
return - V_47 ;
}
V_16 = F_19 ( V_9 , sizeof( * V_2 ) ) ;
if ( ! V_16 )
return - V_48 ;
F_20 ( V_9 , V_16 ) ;
V_2 = F_6 ( V_16 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_9 = V_9 ;
V_16 -> V_49 = & V_50 ;
V_16 -> V_44 = V_44 ;
V_16 -> V_9 . V_51 = V_9 ;
V_16 -> V_52 = V_53 ;
V_16 -> V_54 = V_55 ;
V_16 -> V_56 = F_21 ( V_55 ) ;
V_16 -> V_57 = V_58 ;
F_22 ( V_2 -> V_6 , V_59 ,
V_60 ) ;
V_5 = F_23 ( V_16 , NULL ,
F_5 , NULL ) ;
if ( V_5 ) {
F_18 ( V_9 , L_4 ) ;
return V_5 ;
}
V_5 = F_24 ( V_16 ) ;
if ( V_5 ) {
F_18 ( V_9 , L_5 ) ;
F_25 ( V_16 ) ;
return V_5 ;
}
return 0 ;
}
int F_26 ( struct V_43 * V_9 )
{
struct V_15 * V_16 = F_27 ( V_9 ) ;
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_28 ( V_16 ) ;
F_25 ( V_16 ) ;
F_22 ( V_2 -> V_6 , V_59 ,
V_61 ) ;
return 0 ;
}
