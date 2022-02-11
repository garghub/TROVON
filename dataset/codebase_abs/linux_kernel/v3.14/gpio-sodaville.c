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
if ( V_29 != V_27 -> V_34 )
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
static int F_11 ( struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 ;
int V_39 ;
V_6 -> V_40 = F_12 ( - 1 , 0 , V_41 , - 1 ) ;
if ( V_6 -> V_40 < 0 )
return V_6 -> V_40 ;
F_5 ( 0 , V_6 -> V_11 + V_21 ) ;
F_5 ( ( 1 << 11 ) - 1 , V_6 -> V_11 + V_20 ) ;
V_39 = F_13 ( V_36 -> V_17 , F_6 , V_42 ,
L_1 , V_6 ) ;
if ( V_39 )
goto V_43;
V_6 -> V_4 = F_14 ( L_2 , 1 , V_6 -> V_40 ,
V_6 -> V_11 , V_44 ) ;
if ( ! V_6 -> V_4 ) {
V_39 = - V_45 ;
goto V_46;
}
V_6 -> V_4 -> V_7 = V_6 ;
V_38 = V_6 -> V_4 -> V_47 ;
V_38 -> type = V_14 | V_15 ;
V_38 -> V_48 . V_49 = V_20 ;
V_38 -> V_48 . V_50 = V_21 ;
V_38 -> V_51 . V_52 = V_53 ;
V_38 -> V_51 . V_54 = V_55 ;
V_38 -> V_51 . V_56 = V_57 ;
V_38 -> V_51 . V_58 = F_1 ;
F_15 ( V_6 -> V_4 , F_16 ( V_41 ) ,
V_59 , V_60 ,
V_61 | V_62 ) ;
V_6 -> V_24 = F_17 ( V_36 -> V_63 . V_34 , V_41 ,
V_6 -> V_40 , 0 , & V_64 , V_6 ) ;
if ( ! V_6 -> V_24 ) {
V_39 = - V_65 ;
goto V_46;
}
return 0 ;
V_46:
F_18 ( V_36 -> V_17 , V_6 ) ;
V_43:
F_19 ( V_6 -> V_40 , V_41 ) ;
return V_39 ;
}
static int F_20 ( struct V_35 * V_36 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 ;
unsigned long V_68 ;
const void * V_69 ;
int V_70 ;
int V_39 ;
T_2 V_71 ;
V_6 = F_21 ( sizeof( struct V_5 ) , V_72 ) ;
if ( ! V_6 )
return - V_45 ;
V_39 = F_22 ( V_36 ) ;
if ( V_39 ) {
F_23 ( & V_36 -> V_63 , L_3 ) ;
goto V_73;
}
V_39 = F_24 ( V_36 , V_74 , V_75 ) ;
if ( V_39 ) {
F_23 ( & V_36 -> V_63 , L_4 , V_74 ) ;
goto V_76;
}
V_68 = F_25 ( V_36 , V_74 ) ;
if ( ! V_68 ) {
V_39 = - V_65 ;
goto V_77;
}
V_6 -> V_11 = F_26 ( V_68 , F_27 ( V_36 , V_74 ) ) ;
V_69 = F_28 ( V_36 -> V_63 . V_34 , L_5 , & V_70 ) ;
if ( V_69 && V_70 == 4 ) {
V_71 = F_29 ( V_69 , 1 ) ;
F_5 ( V_71 , V_6 -> V_11 + V_78 ) ;
}
V_39 = F_30 ( & V_6 -> V_79 , & V_36 -> V_63 , 4 ,
V_6 -> V_11 + V_80 , V_6 -> V_11 + V_81 ,
NULL , V_6 -> V_11 + V_82 , NULL , 0 ) ;
if ( V_39 )
goto V_83;
V_6 -> V_79 . V_4 . V_84 = V_41 ;
V_39 = F_31 ( & V_6 -> V_79 . V_4 ) ;
if ( V_39 < 0 ) {
F_23 ( & V_36 -> V_63 , L_6 ) ;
goto V_83;
}
V_39 = F_11 ( V_6 , V_36 ) ;
if ( V_39 )
goto V_83;
F_32 ( V_36 , V_6 ) ;
F_33 ( & V_36 -> V_63 , L_7 ) ;
return 0 ;
V_83:
F_34 ( V_6 -> V_11 ) ;
V_77:
F_35 ( V_36 , V_74 ) ;
V_76:
F_36 ( V_36 ) ;
V_73:
F_37 ( V_6 ) ;
return V_39 ;
}
static void F_38 ( struct V_35 * V_36 )
{
struct V_5 * V_6 = F_39 ( V_36 ) ;
F_18 ( V_36 -> V_17 , V_6 ) ;
F_19 ( V_6 -> V_40 , V_41 ) ;
if ( F_40 ( & V_6 -> V_79 . V_4 ) )
F_23 ( & V_36 -> V_63 , L_8 ) ;
F_35 ( V_36 , V_74 ) ;
F_34 ( V_6 -> V_11 ) ;
F_36 ( V_36 ) ;
F_37 ( V_6 ) ;
}
