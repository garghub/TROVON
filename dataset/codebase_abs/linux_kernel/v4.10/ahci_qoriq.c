static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 ,
unsigned long V_4 )
{
const unsigned long * V_5 = F_2 ( & V_2 -> V_6 ) ;
void T_1 * V_7 = F_3 ( V_2 -> V_8 ) ;
T_2 V_9 , V_10 , V_11 ;
struct V_12 * V_8 = V_2 -> V_8 ;
struct V_13 * V_14 = V_8 -> V_15 ;
struct V_16 * V_17 = V_8 -> V_18 -> V_15 ;
struct V_19 * V_20 = V_17 -> V_21 ;
T_3 * V_22 = V_14 -> V_23 + V_24 ;
struct V_25 V_26 ;
bool V_27 ;
int V_28 ;
bool V_29 = ( V_20 -> type == V_30 ) ;
F_4 ( L_1 ) ;
F_5 ( V_8 ) ;
if ( V_29 ) {
V_9 = F_6 ( V_7 + V_31 ) ;
V_10 = F_6 ( V_7 + V_32 ) ;
}
F_7 ( V_2 -> V_33 , & V_26 ) ;
V_26 . V_34 = V_35 ;
F_8 ( & V_26 , 0 , 0 , V_22 ) ;
V_28 = F_9 ( V_2 , V_5 , V_4 , & V_27 ,
V_36 ) ;
if ( V_29 ) {
V_11 = F_6 ( V_7 + V_31 ) ;
if ( V_11 != V_9 )
F_10 ( V_9 , V_7 + V_31 ) ;
V_11 = F_6 ( V_7 + V_32 ) ;
if ( V_11 != V_10 )
F_10 ( V_10 , V_7 + V_32 ) ;
}
V_17 -> V_37 ( V_8 ) ;
if ( V_27 )
* V_3 = F_11 ( V_8 ) ;
F_4 ( L_2 , V_28 , * V_3 ) ;
return V_28 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_19 * V_38 = V_17 -> V_21 ;
void T_1 * V_39 = V_17 -> V_40 ;
switch ( V_38 -> type ) {
case V_30 :
F_10 ( V_41 , V_38 -> V_42 ) ;
F_10 ( V_43 , V_39 + V_44 ) ;
F_10 ( V_45 , V_39 + V_46 ) ;
F_10 ( V_47 , V_39 + V_48 ) ;
F_10 ( V_49 , V_39 + V_50 ) ;
F_10 ( V_51 , V_39 + V_52 ) ;
F_10 ( V_53 , V_39 + V_54 ) ;
F_10 ( V_55 , V_39 + V_56 ) ;
break;
case V_57 :
F_10 ( V_43 , V_39 + V_44 ) ;
F_10 ( V_53 , V_39 + V_54 ) ;
F_10 ( V_55 , V_39 + V_58 ) ;
break;
case V_59 :
F_10 ( V_43 , V_39 + V_44 ) ;
F_10 ( V_53 , V_39 + V_54 ) ;
F_10 ( V_55 , V_39 + V_58 ) ;
break;
case V_60 :
F_10 ( V_61 , V_38 -> V_42 ) ;
F_10 ( V_43 , V_39 + V_44 ) ;
F_10 ( V_53 , V_39 + V_54 ) ;
F_10 ( V_55 , V_39 + V_58 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 . V_67 ;
struct V_33 * V_66 = & V_63 -> V_66 ;
struct V_16 * V_17 ;
struct V_19 * V_20 ;
const struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_28 ;
V_17 = F_14 ( V_63 ) ;
if ( F_15 ( V_17 ) )
return F_16 ( V_17 ) ;
V_69 = F_17 ( V_72 , V_65 ) ;
if ( ! V_69 )
return - V_73 ;
V_20 = F_18 ( V_66 , sizeof( * V_20 ) , V_74 ) ;
if ( ! V_20 )
return - V_75 ;
V_20 -> type = (enum V_76 ) V_69 -> V_77 ;
V_71 = F_19 ( V_63 , V_78 ,
L_3 ) ;
if ( V_71 ) {
V_20 -> V_42 = F_20 ( V_66 , V_71 ) ;
if ( F_15 ( V_20 -> V_42 ) )
return F_16 ( V_20 -> V_42 ) ;
}
V_28 = F_21 ( V_17 ) ;
if ( V_28 )
return V_28 ;
V_17 -> V_21 = V_20 ;
V_28 = F_12 ( V_17 ) ;
if ( V_28 )
goto V_79;
V_28 = F_22 ( V_63 , V_17 , & V_80 ,
& V_81 ) ;
if ( V_28 )
goto V_79;
return 0 ;
V_79:
F_23 ( V_17 ) ;
return V_28 ;
}
static int F_24 ( struct V_33 * V_66 )
{
struct V_82 * V_18 = F_25 ( V_66 ) ;
struct V_16 * V_17 = V_18 -> V_15 ;
int V_28 ;
V_28 = F_21 ( V_17 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_17 ) ;
if ( V_28 )
goto V_79;
V_28 = F_26 ( V_66 ) ;
if ( V_28 )
goto V_79;
F_27 ( V_66 ) ;
F_28 ( V_66 ) ;
F_29 ( V_66 ) ;
return 0 ;
V_79:
F_23 ( V_17 ) ;
return V_28 ;
}
