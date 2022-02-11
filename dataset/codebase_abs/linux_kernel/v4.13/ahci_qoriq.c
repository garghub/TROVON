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
if ( ! V_38 -> V_41 )
return - V_42 ;
F_10 ( V_43 , V_38 -> V_41 ) ;
F_10 ( V_44 , V_39 + V_45 ) ;
F_10 ( V_46 , V_39 + V_47 ) ;
F_10 ( V_48 , V_39 + V_49 ) ;
F_10 ( V_50 , V_39 + V_51 ) ;
F_10 ( V_52 , V_39 + V_53 ) ;
F_10 ( V_54 , V_39 + V_55 ) ;
if ( V_38 -> V_56 )
F_10 ( V_57 ,
V_39 + V_58 ) ;
break;
case V_59 :
if ( ! V_38 -> V_41 )
return - V_42 ;
F_10 ( F_6 ( V_38 -> V_41 ) | V_60 ,
V_38 -> V_41 ) ;
F_10 ( V_44 , V_39 + V_45 ) ;
F_10 ( V_54 , V_39 + V_55 ) ;
if ( V_38 -> V_56 )
F_10 ( V_57 , V_39 + V_61 ) ;
break;
case V_62 :
F_10 ( V_44 , V_39 + V_45 ) ;
F_10 ( V_54 , V_39 + V_55 ) ;
if ( V_38 -> V_56 )
F_10 ( V_57 , V_39 + V_61 ) ;
break;
case V_63 :
if ( ! V_38 -> V_41 )
return - V_42 ;
F_10 ( F_6 ( V_38 -> V_41 ) | V_60 ,
V_38 -> V_41 ) ;
F_10 ( V_44 , V_39 + V_45 ) ;
F_10 ( V_54 , V_39 + V_55 ) ;
if ( V_38 -> V_56 )
F_10 ( V_57 , V_39 + V_61 ) ;
break;
case V_64 :
if ( ! V_38 -> V_41 )
return - V_42 ;
F_10 ( F_6 ( V_38 -> V_41 ) | V_65 ,
V_38 -> V_41 ) ;
F_10 ( V_44 , V_39 + V_45 ) ;
F_10 ( V_54 , V_39 + V_55 ) ;
if ( V_38 -> V_56 )
F_10 ( V_57 , V_39 + V_61 ) ;
break;
case V_66 :
F_10 ( V_44 , V_39 + V_45 ) ;
F_10 ( V_54 , V_39 + V_55 ) ;
if ( V_38 -> V_56 )
F_10 ( V_57 , V_39 + V_61 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = V_68 -> V_71 . V_72 ;
struct V_33 * V_71 = & V_68 -> V_71 ;
struct V_16 * V_17 ;
struct V_19 * V_20 ;
const struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_28 ;
V_17 = F_14 ( V_68 ) ;
if ( F_15 ( V_17 ) )
return F_16 ( V_17 ) ;
V_74 = F_17 ( V_77 , V_70 ) ;
if ( ! V_74 )
return - V_78 ;
V_20 = F_18 ( V_71 , sizeof( * V_20 ) , V_79 ) ;
if ( ! V_20 )
return - V_80 ;
V_20 -> type = (enum V_81 ) V_74 -> V_82 ;
V_76 = F_19 ( V_68 , V_83 ,
L_3 ) ;
if ( V_76 ) {
V_20 -> V_41 = F_20 ( V_71 , V_76 ) ;
if ( F_15 ( V_20 -> V_41 ) )
return F_16 ( V_20 -> V_41 ) ;
}
V_20 -> V_56 = F_21 ( V_70 ) ;
V_28 = F_22 ( V_17 ) ;
if ( V_28 )
return V_28 ;
V_17 -> V_21 = V_20 ;
V_28 = F_12 ( V_17 ) ;
if ( V_28 )
goto V_84;
V_28 = F_23 ( V_68 , V_17 , & V_85 ,
& V_86 ) ;
if ( V_28 )
goto V_84;
return 0 ;
V_84:
F_24 ( V_17 ) ;
return V_28 ;
}
static int F_25 ( struct V_33 * V_71 )
{
struct V_87 * V_18 = F_26 ( V_71 ) ;
struct V_16 * V_17 = V_18 -> V_15 ;
int V_28 ;
V_28 = F_22 ( V_17 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( V_17 ) ;
if ( V_28 )
goto V_84;
V_28 = F_27 ( V_71 ) ;
if ( V_28 )
goto V_84;
F_28 ( V_71 ) ;
F_29 ( V_71 ) ;
F_30 ( V_71 ) ;
return 0 ;
V_84:
F_24 ( V_17 ) ;
return V_28 ;
}
