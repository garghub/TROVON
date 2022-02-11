void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_6 = F_2 ( V_4 , struct V_5 , V_7 ) ;
F_3 ( V_8 , L_1 ) ;
F_4 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_10 || V_6 -> V_11 == V_12 )
goto V_13;
F_3 ( V_8 , L_2 ) ;
F_5 ( V_6 , V_14 , V_15 ) ;
V_6 -> V_10 = true ;
V_13:
F_6 ( & V_6 -> V_9 ) ;
}
void F_7 ( struct V_5 * V_6 )
{
unsigned long V_16 ;
if ( V_6 -> V_11 != V_12 ) {
V_16 = F_8 ( V_17 ) ;
F_9 ( V_6 -> V_18 , & V_6 -> V_7 , V_16 ) ;
}
}
int F_10 ( struct V_5 * V_6 )
{
unsigned long V_19 , V_20 ;
T_1 V_21 ;
if ( F_11 ( & V_6 -> V_7 ) )
F_12 ( & V_6 -> V_7 ) ;
if ( ! V_6 -> V_10 )
return 0 ;
F_3 ( V_8 , L_3 ) ;
V_20 = V_22 ;
V_19 = V_22 + F_8 ( V_23 ) ;
F_5 ( V_6 , V_14 , V_24 ) ;
V_21 = F_13 ( V_6 , V_14 ) ;
while ( ! ( V_21 & V_25 ) ) {
if ( F_14 ( V_22 , V_19 ) ) {
F_15 ( L_4 ) ;
return - V_26 ;
}
F_16 ( 1 ) ;
V_21 = F_13 ( V_6 , V_14 ) ;
}
F_3 ( V_8 , L_5 ,
F_17 ( V_22 - V_20 ) ) ;
V_6 -> V_10 = false ;
return 0 ;
}
int F_18 ( struct V_5 * V_6 , enum V_27 V_28 )
{
int V_29 ;
switch ( V_28 ) {
case V_30 :
F_3 ( V_8 , L_6 ) ;
V_29 = F_19 ( V_6 , true ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_20 ( V_6 ,
V_31 ,
V_6 -> V_32 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_21 ( V_6 , V_33 ,
V_34 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_22 ( V_6 , V_35 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_23 ( V_6 , V_36 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
case V_37 :
F_3 ( V_8 , L_7 ) ;
V_29 = F_23 ( V_6 , V_36 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_24 ( V_6 , V_38 , NULL , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
case V_12 :
default:
F_3 ( V_8 , L_8 ) ;
V_29 = F_23 ( V_6 , V_39 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_21 ( V_6 , V_40 ,
V_34 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_19 ( V_6 , false ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_20 ( V_6 ,
V_31 ,
V_6 -> V_32 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_22 ( V_6 , V_41 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
}
V_6 -> V_11 = V_28 ;
return V_29 ;
}
