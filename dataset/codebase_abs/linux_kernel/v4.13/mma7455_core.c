static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned int V_6 ;
int V_7 = 3 ;
int V_8 ;
while ( V_7 -- > 0 ) {
V_8 = F_3 ( V_2 -> V_5 , V_9 , & V_6 ) ;
if ( V_8 )
return V_8 ;
if ( V_6 & V_10 )
return 0 ;
F_4 ( 20 ) ;
}
F_5 ( V_4 , L_1 ) ;
return - V_11 ;
}
static T_1 F_6 ( int V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_1 * V_2 = F_7 ( V_17 ) ;
T_2 V_18 [ 16 ] ;
int V_8 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_19;
V_8 = F_8 ( V_2 -> V_5 , V_20 , V_18 ,
sizeof( V_21 ) * 3 ) ;
if ( V_8 )
goto V_19;
F_9 ( V_17 , V_18 ,
F_10 ( V_17 ) ) ;
V_19:
F_11 ( V_17 -> V_22 ) ;
return V_23 ;
}
static int F_12 ( struct V_16 * V_17 ,
struct V_24 const * V_25 ,
int * V_26 , int * V_27 , long V_28 )
{
struct V_1 * V_2 = F_7 ( V_17 ) ;
unsigned int V_6 ;
V_21 V_29 ;
int V_8 ;
switch ( V_28 ) {
case V_30 :
if ( F_13 ( V_17 ) )
return - V_31 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_8 ( V_2 -> V_5 , V_25 -> V_32 , & V_29 ,
sizeof( V_29 ) ) ;
if ( V_8 )
return V_8 ;
* V_26 = F_14 ( F_15 ( V_29 ) , 9 ) ;
return V_33 ;
case V_34 :
* V_26 = 0 ;
* V_27 = V_35 ;
return V_36 ;
case V_37 :
V_8 = F_3 ( V_2 -> V_5 , V_38 , & V_6 ) ;
if ( V_8 )
return V_8 ;
if ( V_6 & V_39 )
* V_26 = 250 ;
else
* V_26 = 125 ;
return V_33 ;
}
return - V_40 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_24 const * V_25 ,
int V_26 , int V_27 , long V_28 )
{
struct V_1 * V_2 = F_7 ( V_17 ) ;
int V_41 ;
switch ( V_28 ) {
case V_37 :
if ( V_26 == 250 && V_27 == 0 )
V_41 = V_42 ;
else if ( V_26 == 125 && V_27 == 0 )
V_41 = V_43 ;
else
return - V_40 ;
return F_17 ( V_2 -> V_5 , V_38 ,
V_39 , V_41 ) ;
case V_34 :
if ( V_26 == 0 && V_27 == V_35 )
return 0 ;
break;
}
return - V_40 ;
}
int F_18 ( struct V_3 * V_4 , struct V_5 * V_5 ,
const char * V_44 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
unsigned int V_6 ;
int V_8 ;
V_8 = F_3 ( V_5 , V_45 , & V_6 ) ;
if ( V_8 ) {
F_19 ( V_4 , L_2 ) ;
return V_8 ;
}
if ( V_6 != V_46 ) {
F_19 ( V_4 , L_3 ) ;
return - V_47 ;
}
V_17 = F_20 ( V_4 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_48 ;
F_21 ( V_4 , V_17 ) ;
V_2 = F_7 ( V_17 ) ;
V_2 -> V_5 = V_5 ;
V_17 -> V_49 = & V_50 ;
V_17 -> V_44 = V_44 ;
V_17 -> V_4 . V_51 = V_4 ;
V_17 -> V_52 = V_53 ;
V_17 -> V_54 = V_55 ;
V_17 -> V_56 = F_22 ( V_55 ) ;
V_17 -> V_57 = V_58 ;
F_23 ( V_2 -> V_5 , V_59 ,
V_60 ) ;
V_8 = F_24 ( V_17 , NULL ,
F_6 , NULL ) ;
if ( V_8 ) {
F_19 ( V_4 , L_4 ) ;
return V_8 ;
}
V_8 = F_25 ( V_17 ) ;
if ( V_8 ) {
F_19 ( V_4 , L_5 ) ;
F_26 ( V_17 ) ;
return V_8 ;
}
return 0 ;
}
int F_27 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = F_28 ( V_4 ) ;
struct V_1 * V_2 = F_7 ( V_17 ) ;
F_29 ( V_17 ) ;
F_26 ( V_17 ) ;
F_23 ( V_2 -> V_5 , V_59 ,
V_61 ) ;
return 0 ;
}
