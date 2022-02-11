static int F_1 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
void T_1 * V_8 ;
T_2 V_9 ;
if ( V_2 -> V_10 < 8 )
V_8 = V_6 -> V_11 + V_12 ;
else
V_8 = V_6 -> V_11 + V_13 ;
V_9 = F_3 ( V_8 ) ;
switch ( type ) {
case V_14 :
V_9 &= ~ F_4 ( 4 * ( V_2 -> V_10 % 8 ) ) ;
break;
case V_15 :
V_9 |= F_4 ( 4 * ( V_2 -> V_10 % 8 ) ) ;
break;
default:
return - V_16 ;
}
F_5 ( V_9 , V_8 ) ;
return 0 ;
}
static T_3 F_6 ( int V_17 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
T_2 V_19 = F_3 ( V_6 -> V_11 + V_20 ) ;
V_19 &= F_3 ( V_6 -> V_11 + V_21 ) ;
if ( ! V_19 )
return V_22 ;
while ( V_19 ) {
T_2 V_23 = F_7 ( V_19 ) ;
V_19 &= ~ F_4 ( V_23 ) ;
F_8 ( F_9 ( V_6 -> V_24 , V_23 ) ) ;
}
return V_25 ;
}
static int F_10 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const T_2 * V_30 , T_2 V_31 , T_4 * V_32 ,
T_2 * V_33 )
{
T_2 line , type ;
if ( V_29 != F_11 ( V_27 ) )
return - V_16 ;
if ( V_31 < 2 )
return - V_16 ;
line = * V_30 ;
* V_32 = line ;
V_30 ++ ;
type = * V_30 ;
switch ( type ) {
case V_15 :
case V_14 :
* V_33 = type ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 ;
int V_38 ;
V_6 -> V_39 = F_13 ( & V_35 -> V_40 , - 1 , 0 ,
V_41 , - 1 ) ;
if ( V_6 -> V_39 < 0 )
return V_6 -> V_39 ;
F_5 ( 0 , V_6 -> V_11 + V_21 ) ;
F_5 ( ( 1 << 11 ) - 1 , V_6 -> V_11 + V_20 ) ;
V_38 = F_14 ( & V_35 -> V_40 , V_35 -> V_17 ,
F_6 , V_42 ,
L_1 , V_6 ) ;
if ( V_38 )
return V_38 ;
V_6 -> V_4 = F_15 ( L_2 , 1 , V_6 -> V_39 ,
V_6 -> V_11 , V_43 ) ;
if ( ! V_6 -> V_4 )
return - V_44 ;
V_6 -> V_4 -> V_7 = V_6 ;
V_37 = V_6 -> V_4 -> V_45 ;
V_37 -> type = V_14 | V_15 ;
V_37 -> V_46 . V_47 = V_20 ;
V_37 -> V_46 . V_48 = V_21 ;
V_37 -> V_49 . V_50 = V_51 ;
V_37 -> V_49 . V_52 = V_53 ;
V_37 -> V_49 . V_54 = V_55 ;
V_37 -> V_49 . V_56 = F_1 ;
F_16 ( V_6 -> V_4 , F_17 ( V_41 ) ,
V_57 , V_58 ,
V_59 | V_60 ) ;
V_6 -> V_24 = F_18 ( V_35 -> V_40 . V_61 , V_41 ,
V_6 -> V_39 , 0 , & V_62 , V_6 ) ;
if ( ! V_6 -> V_24 )
return - V_63 ;
return 0 ;
}
static int F_19 ( struct V_34 * V_35 ,
const struct V_64 * V_65 )
{
struct V_5 * V_6 ;
unsigned long V_66 ;
const void * V_67 ;
int V_68 ;
int V_38 ;
T_2 V_69 ;
V_6 = F_20 ( sizeof( struct V_5 ) , V_70 ) ;
if ( ! V_6 )
return - V_44 ;
V_38 = F_21 ( V_35 ) ;
if ( V_38 ) {
F_22 ( & V_35 -> V_40 , L_3 ) ;
goto V_71;
}
V_38 = F_23 ( V_35 , V_72 , V_73 ) ;
if ( V_38 ) {
F_22 ( & V_35 -> V_40 , L_4 , V_72 ) ;
goto V_74;
}
V_66 = F_24 ( V_35 , V_72 ) ;
if ( ! V_66 ) {
V_38 = - V_63 ;
goto V_75;
}
V_6 -> V_11 = F_25 ( V_66 , F_26 ( V_35 , V_72 ) ) ;
V_67 = F_27 ( V_35 -> V_40 . V_61 , L_5 , & V_68 ) ;
if ( V_67 && V_68 == 4 ) {
V_69 = F_28 ( V_67 , 1 ) ;
F_5 ( V_69 , V_6 -> V_11 + V_76 ) ;
}
V_38 = F_29 ( & V_6 -> V_49 , & V_35 -> V_40 , 4 ,
V_6 -> V_11 + V_77 , V_6 -> V_11 + V_78 ,
NULL , V_6 -> V_11 + V_79 , NULL , 0 ) ;
if ( V_38 )
goto V_80;
V_6 -> V_49 . V_81 = V_41 ;
V_38 = F_30 ( & V_6 -> V_49 , V_6 ) ;
if ( V_38 < 0 ) {
F_22 ( & V_35 -> V_40 , L_6 ) ;
goto V_80;
}
V_38 = F_12 ( V_6 , V_35 ) ;
if ( V_38 )
goto V_80;
F_31 ( V_35 , V_6 ) ;
F_32 ( & V_35 -> V_40 , L_7 ) ;
return 0 ;
V_80:
F_33 ( V_6 -> V_11 ) ;
V_75:
F_34 ( V_35 , V_72 ) ;
V_74:
F_35 ( V_35 ) ;
V_71:
F_36 ( V_6 ) ;
return V_38 ;
}
