static unsigned int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned int V_4 , V_5 , V_6 ;
V_3 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_3 & ( 1 << V_9 ) )
V_4 = V_3 & V_10 ;
else
V_4 = 0 ;
F_3 ( V_4 > V_11 ) ;
V_3 = F_2 ( V_2 -> V_7 + V_12 ) ;
V_5 = ( V_3 >> ( V_13 * V_4 ) ) &
V_14 ;
V_3 = F_2 ( V_2 -> V_7 + V_15 ) ;
V_6 = V_16 &
( V_3 >> V_17 ) ;
if ( V_5 != V_6 ) {
F_4 ( L_1 , V_18 , V_5 ,
V_6 ) ;
V_5 = V_6 ;
}
F_4 ( L_2 , V_18 , V_5 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
int V_19 ;
T_1 V_3 ;
V_5 = F_1 ( V_2 ) ;
switch ( V_5 ) {
case V_20 :
case V_21 :
V_19 = 1 ;
break;
case V_22 :
V_3 = F_2 ( V_2 -> V_7 + V_23 ) ;
V_19 = V_3 & V_24 ;
if ( V_19 == 0 )
V_19 = 256 ;
break;
case V_25 :
V_3 = F_2 ( V_2 -> V_7 + V_26 ) ;
V_19 = V_3 & V_27 ;
if ( V_19 == 0 )
V_19 = 256 ;
break;
default:
V_19 = - V_28 ;
}
return V_19 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned int V_29 , V_30 , V_31 ;
V_3 = F_2 ( V_2 -> V_7 + V_32 ) ;
if ( V_3 & ( 1 << V_33 ) ) {
V_29 = ( V_3 >> V_34 ) &
V_35 ;
if ( V_29 == 0 )
V_29 = 256 ;
V_30 = V_3 & V_36 ;
} else {
V_3 = F_2 ( V_2 -> V_7 + V_37 ) ;
V_29 = ( V_3 >> V_38 ) &
V_39 ;
if ( V_29 == 0 )
V_29 = 1024 ;
V_3 = F_2 ( V_2 -> V_7 + V_40 ) ;
V_30 = V_3 & V_41 ;
}
V_31 = ( V_29 << 20 ) | V_30 ;
return V_31 ;
}
static unsigned long F_7 ( struct V_42 * V_43 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_8 ( V_43 ) ;
T_1 V_3 ;
int V_19 ;
T_2 V_31 ;
unsigned int V_45 ;
V_3 = F_2 ( V_2 -> V_7 + V_23 ) ;
if ( V_3 & ( 1 << V_46 ) ) {
V_2 -> V_47 = V_44 ;
return V_2 -> V_47 ;
}
V_3 = F_2 ( V_2 -> V_7 + V_37 ) ;
if ( ! ( V_3 & ( 1 << V_48 ) ) ) {
V_2 -> V_47 = 0 ;
return 0 ;
}
V_45 = ( V_3 >> V_49 ) &
V_50 ;
if ( V_45 == 0 )
V_45 = 16 ;
V_31 = F_6 ( V_2 ) ;
V_19 = F_5 ( V_2 ) ;
if ( V_19 <= 0 ) {
V_2 -> V_47 = 0 ;
return 0 ;
}
V_2 -> V_47 = ( V_31 * V_44 ) >> 20 ;
V_2 -> V_47 = ( V_2 -> V_47 / V_45 ) / V_19 ;
F_4 ( L_3 , V_18 ,
V_2 -> V_47 , V_44 ) ;
F_4 ( L_4 , V_18 ,
( unsigned int ) ( V_31 >> 20 ) , V_45 , V_19 ) ;
return V_2 -> V_47 ;
}
void T_3 F_9 ( struct V_51 * V_52 )
{
int V_53 ;
struct V_1 * V_2 ;
struct V_54 V_55 ;
const char * V_56 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_57 ) ;
if ( F_11 ( ! V_2 ) )
return;
V_2 -> V_7 = F_12 ( V_52 , 0 ) ;
if ( F_11 ( ! V_2 -> V_7 ) )
goto V_58;
V_55 . V_59 = V_52 -> V_59 ;
V_55 . V_60 = & V_61 ;
V_55 . V_62 = 0 ;
V_56 = F_13 ( V_52 , 0 ) ;
V_55 . V_63 = ( V_56 ? & V_56 : NULL ) ;
V_55 . V_64 = ( V_56 ? 1 : 0 ) ;
V_2 -> V_43 . V_55 = & V_55 ;
V_53 = F_14 ( NULL , & V_2 -> V_43 ) ;
if ( F_11 ( V_53 ) )
goto V_65;
V_53 = F_15 ( V_52 , V_66 , & V_2 -> V_43 ) ;
if ( F_11 ( V_53 ) )
goto V_67;
return;
V_67:
F_16 ( & V_2 -> V_43 ) ;
V_65:
F_17 ( V_2 -> V_7 ) ;
V_58:
F_18 ( V_2 ) ;
}
