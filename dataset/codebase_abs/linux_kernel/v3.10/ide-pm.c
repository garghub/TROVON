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
int F_10 ( struct V_1 * V_2 )
{
T_2 * V_4 = F_2 ( V_2 ) ;
T_2 * V_5 = F_3 ( V_4 ) ;
T_3 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_25 ;
if ( F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) == 0 || V_5 == NULL ) {
F_9 ( V_6 , 1 ) ;
F_11 ( V_6 ) ;
}
F_12 ( V_4 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_8 = F_6 ( V_4 -> V_13 , V_14 , V_15 ) ;
V_8 -> V_16 = V_26 ;
V_8 -> V_27 |= V_28 ;
V_8 -> V_18 = & V_10 ;
V_10 . V_19 = V_29 ;
V_10 . V_24 = V_30 ;
V_25 = F_7 ( V_4 -> V_13 , NULL , V_8 , 1 ) ;
F_8 ( V_8 ) ;
if ( V_25 == 0 && V_2 -> V_31 ) {
struct V_32 * V_33 = F_13 ( V_2 -> V_31 ) ;
if ( V_33 -> V_34 )
V_33 -> V_34 ( V_4 ) ;
}
return V_25 ;
}
void F_14 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_35 = V_8 -> V_18 ;
#ifdef F_15
F_16 ( V_36 L_1 ,
V_4 -> V_37 , V_35 -> V_19 ) ;
#endif
if ( V_4 -> V_38 != V_39 )
return;
switch ( V_35 -> V_19 ) {
case V_40 :
if ( V_35 -> V_24 == V_23 )
V_35 -> V_19 = V_41 ;
else
V_35 -> V_19 = V_42 ;
break;
case V_42 :
V_35 -> V_19 = V_41 ;
break;
case V_43 :
V_35 -> V_19 = V_44 ;
break;
case V_44 :
V_35 -> V_19 = V_45 ;
break;
}
}
T_4 F_17 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_35 = V_8 -> V_18 ;
struct V_46 V_47 = { } ;
switch ( V_35 -> V_19 ) {
case V_40 :
if ( V_4 -> V_38 != V_39 )
break;
if ( F_18 ( V_4 -> V_48 ) == 0 ||
( V_4 -> V_49 & V_50 ) == 0 ) {
F_14 ( V_4 , V_8 ) ;
return V_51 ;
}
if ( F_19 ( V_4 -> V_48 ) )
V_47 . V_52 . V_53 = V_54 ;
else
V_47 . V_52 . V_53 = V_55 ;
goto V_56;
case V_42 :
V_47 . V_52 . V_53 = V_57 ;
goto V_56;
case V_43 :
F_20 ( V_4 ) ;
if ( V_4 -> V_38 != V_39 )
V_35 -> V_19 = V_45 ;
else
F_14 ( V_4 , V_8 ) ;
return V_51 ;
case V_44 :
V_47 . V_52 . V_53 = V_58 ;
goto V_56;
case V_45 :
if ( V_4 -> V_6 -> V_59 == NULL )
break;
F_21 ( V_4 ) ;
break;
}
V_35 -> V_19 = V_41 ;
return V_51 ;
V_56:
V_47 . V_60 . V_61 . V_52 = V_62 | V_63 ;
V_47 . V_60 . V_64 . V_52 = V_65 | V_63 ;
V_47 . V_66 = V_67 ;
return F_22 ( V_4 , & V_47 ) ;
}
void F_23 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_68 * V_69 = V_4 -> V_13 ;
struct V_9 * V_35 = V_8 -> V_18 ;
unsigned long V_70 ;
F_14 ( V_4 , V_8 ) ;
if ( V_35 -> V_19 != V_41 )
return;
#ifdef F_15
F_16 ( L_2 , V_4 -> V_37 ,
( V_8 -> V_16 == V_17 ) ? L_3 : L_4 ) ;
#endif
F_24 ( V_69 -> V_71 , V_70 ) ;
if ( V_8 -> V_16 == V_17 )
F_25 ( V_69 ) ;
else
V_4 -> V_49 &= ~ V_72 ;
F_26 ( V_69 -> V_71 , V_70 ) ;
V_4 -> V_6 -> V_8 = NULL ;
if ( F_27 ( V_8 , 0 , 0 ) )
F_28 () ;
}
void F_29 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_35 = V_8 -> V_18 ;
if ( V_8 -> V_16 == V_17 &&
V_35 -> V_19 == V_20 )
V_4 -> V_49 |= V_72 ;
else if ( V_8 -> V_16 == V_26 &&
V_35 -> V_19 == V_29 ) {
T_3 * V_6 = V_4 -> V_6 ;
const struct V_73 * V_74 = V_6 -> V_74 ;
struct V_68 * V_69 = V_4 -> V_13 ;
unsigned long V_70 ;
int V_75 ;
#ifdef F_15
F_16 ( L_5 , V_4 -> V_37 ) ;
#endif
V_75 = F_30 ( V_6 , 35000 ) ;
if ( V_75 )
F_16 ( V_76 L_6 , V_4 -> V_37 ) ;
V_74 -> V_77 ( V_4 ) ;
V_74 -> V_78 ( V_6 , V_79 ) ;
V_75 = F_30 ( V_6 , 100000 ) ;
if ( V_75 )
F_16 ( V_76 L_7 , V_4 -> V_37 ) ;
F_24 ( V_69 -> V_71 , V_70 ) ;
F_31 ( V_69 ) ;
F_26 ( V_69 -> V_71 , V_70 ) ;
}
}
