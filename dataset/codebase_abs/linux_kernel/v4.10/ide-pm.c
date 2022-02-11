int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = F_2 ( V_2 ) ;
T_2 * V_5 = F_3 ( V_4 ) ;
T_3 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_11 ;
if ( F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) == 0 || V_5 == NULL )
F_5 ( V_6 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_8 = F_6 ( V_4 -> V_13 , V_14 , V_15 ) ;
V_8 -> V_16 = V_17 ;
V_8 -> V_18 = & V_10 ;
V_10 . V_19 = V_20 ;
if ( V_3 . V_21 == V_22 )
V_3 . V_21 = V_23 ;
V_10 . V_24 = V_3 . V_21 ;
V_11 = F_7 ( V_4 -> V_13 , NULL , V_8 , 0 ) ;
F_8 ( V_8 ) ;
if ( V_11 == 0 && F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) || V_5 == NULL )
F_9 ( V_6 , 0 ) ;
}
return V_11 ;
}
static void F_10 ( struct V_7 * V_8 , int error )
{
F_11 ( V_8 -> V_25 ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_26 * V_27 = V_8 -> V_27 ;
F_13 ( V_28 ) ;
V_8 -> V_25 = & V_28 ;
V_8 -> V_29 = F_10 ;
F_14 ( V_27 -> V_30 ) ;
if ( F_15 ( F_16 ( V_27 ) ) ) {
V_8 -> V_31 |= V_32 ;
V_8 -> V_33 = - V_34 ;
F_17 ( V_8 , V_8 -> V_33 ) ;
F_18 ( V_27 -> V_30 ) ;
return - V_34 ;
}
F_19 ( V_27 , V_8 , V_35 ) ;
F_20 ( V_27 ) ;
F_18 ( V_27 -> V_30 ) ;
F_21 ( & V_28 ) ;
return V_8 -> V_33 ? - V_36 : 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
T_2 * V_4 = F_2 ( V_2 ) ;
T_2 * V_5 = F_3 ( V_4 ) ;
T_3 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_37 ;
if ( F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) == 0 || V_5 == NULL ) {
F_9 ( V_6 , 1 ) ;
F_23 ( V_6 ) ;
}
F_24 ( V_4 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_8 = F_6 ( V_4 -> V_13 , V_14 , V_15 ) ;
V_8 -> V_16 = V_38 ;
V_8 -> V_31 |= V_39 ;
V_8 -> V_18 = & V_10 ;
V_10 . V_19 = V_40 ;
V_10 . V_24 = V_41 ;
V_37 = F_12 ( V_8 ) ;
F_8 ( V_8 ) ;
if ( V_37 == 0 && V_2 -> V_42 ) {
struct V_43 * V_44 = F_25 ( V_2 -> V_42 ) ;
if ( V_44 -> V_45 )
V_44 -> V_45 ( V_4 ) ;
}
return V_37 ;
}
void F_26 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_46 = V_8 -> V_18 ;
#ifdef F_27
F_28 ( V_47 L_1 ,
V_4 -> V_48 , V_46 -> V_19 ) ;
#endif
if ( V_4 -> V_49 != V_50 )
return;
switch ( V_46 -> V_19 ) {
case V_51 :
if ( V_46 -> V_24 == V_23 )
V_46 -> V_19 = V_52 ;
else
V_46 -> V_19 = V_53 ;
break;
case V_53 :
V_46 -> V_19 = V_52 ;
break;
case V_54 :
V_46 -> V_19 = V_55 ;
break;
case V_55 :
V_46 -> V_19 = V_56 ;
break;
}
}
T_4 F_29 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_46 = V_8 -> V_18 ;
struct V_57 V_58 = { } ;
switch ( V_46 -> V_19 ) {
case V_51 :
if ( V_4 -> V_49 != V_50 )
break;
if ( F_30 ( V_4 -> V_59 ) == 0 ||
( V_4 -> V_60 & V_61 ) == 0 ) {
F_26 ( V_4 , V_8 ) ;
return V_62 ;
}
if ( F_31 ( V_4 -> V_59 ) )
V_58 . V_63 . V_64 = V_65 ;
else
V_58 . V_63 . V_64 = V_66 ;
goto V_67;
case V_53 :
V_58 . V_63 . V_64 = V_68 ;
goto V_67;
case V_54 :
F_32 ( V_4 ) ;
if ( V_4 -> V_49 != V_50 )
V_46 -> V_19 = V_56 ;
else
F_26 ( V_4 , V_8 ) ;
return V_62 ;
case V_55 :
V_58 . V_63 . V_64 = V_69 ;
goto V_67;
case V_56 :
if ( V_4 -> V_6 -> V_70 == NULL )
break;
F_33 ( V_4 ) ;
break;
}
V_46 -> V_19 = V_52 ;
return V_62 ;
V_67:
V_58 . V_71 . V_72 . V_63 = V_73 | V_74 ;
V_58 . V_71 . V_75 . V_63 = V_76 | V_74 ;
V_58 . V_77 = V_78 ;
return F_34 ( V_4 , & V_58 ) ;
}
void F_35 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_26 * V_27 = V_4 -> V_13 ;
struct V_9 * V_46 = V_8 -> V_18 ;
unsigned long V_79 ;
F_26 ( V_4 , V_8 ) ;
if ( V_46 -> V_19 != V_52 )
return;
#ifdef F_27
F_28 ( L_2 , V_4 -> V_48 ,
( V_8 -> V_16 == V_17 ) ? L_3 : L_4 ) ;
#endif
F_36 ( V_27 -> V_30 , V_79 ) ;
if ( V_8 -> V_16 == V_17 )
F_37 ( V_27 ) ;
else
V_4 -> V_60 &= ~ V_80 ;
F_38 ( V_27 -> V_30 , V_79 ) ;
V_4 -> V_6 -> V_8 = NULL ;
if ( F_39 ( V_8 , 0 , 0 ) )
F_40 () ;
}
void F_41 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_46 = V_8 -> V_18 ;
if ( V_8 -> V_16 == V_17 &&
V_46 -> V_19 == V_20 )
V_4 -> V_60 |= V_80 ;
else if ( V_8 -> V_16 == V_38 &&
V_46 -> V_19 == V_40 ) {
T_3 * V_6 = V_4 -> V_6 ;
const struct V_81 * V_82 = V_6 -> V_82 ;
struct V_26 * V_27 = V_4 -> V_13 ;
unsigned long V_79 ;
int V_83 ;
#ifdef F_27
F_28 ( L_5 , V_4 -> V_48 ) ;
#endif
V_83 = F_42 ( V_6 , 35000 ) ;
if ( V_83 )
F_28 ( V_84 L_6 , V_4 -> V_48 ) ;
V_82 -> V_85 ( V_4 ) ;
V_82 -> V_86 ( V_6 , V_87 ) ;
V_83 = F_42 ( V_6 , 100000 ) ;
if ( V_83 )
F_28 ( V_84 L_7 , V_4 -> V_48 ) ;
F_36 ( V_27 -> V_30 , V_79 ) ;
F_43 ( V_27 ) ;
F_38 ( V_27 -> V_30 , V_79 ) ;
}
}
