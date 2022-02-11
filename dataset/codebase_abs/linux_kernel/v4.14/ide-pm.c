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
F_7 ( V_8 ) -> type = V_16 ;
V_8 -> V_17 = & V_10 ;
V_10 . V_18 = V_19 ;
if ( V_3 . V_20 == V_21 )
V_3 . V_20 = V_22 ;
V_10 . V_23 = V_3 . V_20 ;
F_8 ( V_4 -> V_13 , NULL , V_8 , 0 ) ;
V_11 = F_9 ( V_8 ) -> V_24 ? - V_25 : 0 ;
F_10 ( V_8 ) ;
if ( V_11 == 0 && F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) || V_5 == NULL )
F_11 ( V_6 , 0 ) ;
}
return V_11 ;
}
static void F_12 ( struct V_7 * V_8 , T_4 error )
{
F_13 ( V_8 -> V_26 ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_27 * V_28 = V_8 -> V_28 ;
F_15 ( V_29 ) ;
V_8 -> V_26 = & V_29 ;
V_8 -> V_30 = F_12 ;
F_16 ( V_28 -> V_31 ) ;
if ( F_17 ( F_18 ( V_28 ) ) ) {
V_8 -> V_32 |= V_33 ;
F_9 ( V_8 ) -> V_24 = - V_34 ;
F_19 ( V_8 , V_35 ) ;
F_20 ( V_28 -> V_31 ) ;
return - V_34 ;
}
F_21 ( V_28 , V_8 , V_36 ) ;
F_22 ( V_28 ) ;
F_20 ( V_28 -> V_31 ) ;
F_23 ( & V_29 ) ;
return F_9 ( V_8 ) -> V_24 ? - V_25 : 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
T_2 * V_4 = F_2 ( V_2 ) ;
T_2 * V_5 = F_3 ( V_4 ) ;
T_3 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_37 ;
if ( F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) == 0 || V_5 == NULL ) {
F_11 ( V_6 , 1 ) ;
F_25 ( V_6 ) ;
}
F_26 ( V_4 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_8 = F_6 ( V_4 -> V_13 , V_14 , V_15 ) ;
F_7 ( V_8 ) -> type = V_38 ;
V_8 -> V_32 |= V_39 ;
V_8 -> V_17 = & V_10 ;
V_10 . V_18 = V_40 ;
V_10 . V_23 = V_41 ;
V_37 = F_14 ( V_8 ) ;
F_10 ( V_8 ) ;
if ( V_37 == 0 && V_2 -> V_42 ) {
struct V_43 * V_44 = F_27 ( V_2 -> V_42 ) ;
if ( V_44 -> V_45 )
V_44 -> V_45 ( V_4 ) ;
}
return V_37 ;
}
void F_28 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_46 = V_8 -> V_17 ;
#ifdef F_29
F_30 ( V_47 L_1 ,
V_4 -> V_48 , V_46 -> V_18 ) ;
#endif
if ( V_4 -> V_49 != V_50 )
return;
switch ( V_46 -> V_18 ) {
case V_51 :
if ( V_46 -> V_23 == V_22 )
V_46 -> V_18 = V_52 ;
else
V_46 -> V_18 = V_53 ;
break;
case V_53 :
V_46 -> V_18 = V_52 ;
break;
case V_54 :
V_46 -> V_18 = V_55 ;
break;
case V_55 :
V_46 -> V_18 = V_56 ;
break;
}
}
T_5 F_31 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_46 = V_8 -> V_17 ;
struct V_57 V_58 = { } ;
switch ( V_46 -> V_18 ) {
case V_51 :
if ( V_4 -> V_49 != V_50 )
break;
if ( F_32 ( V_4 -> V_59 ) == 0 ||
( V_4 -> V_60 & V_61 ) == 0 ) {
F_28 ( V_4 , V_8 ) ;
return V_62 ;
}
if ( F_33 ( V_4 -> V_59 ) )
V_58 . V_63 . V_64 = V_65 ;
else
V_58 . V_63 . V_64 = V_66 ;
goto V_67;
case V_53 :
V_58 . V_63 . V_64 = V_68 ;
goto V_67;
case V_54 :
F_34 ( V_4 ) ;
if ( V_4 -> V_49 != V_50 )
V_46 -> V_18 = V_56 ;
else
F_28 ( V_4 , V_8 ) ;
return V_62 ;
case V_55 :
V_58 . V_63 . V_64 = V_69 ;
goto V_67;
case V_56 :
if ( V_4 -> V_6 -> V_70 == NULL )
break;
F_35 ( V_4 ) ;
break;
}
V_46 -> V_18 = V_52 ;
return V_62 ;
V_67:
V_58 . V_71 . V_72 . V_63 = V_73 | V_74 ;
V_58 . V_71 . V_75 . V_63 = V_76 | V_74 ;
V_58 . V_77 = V_78 ;
return F_36 ( V_4 , & V_58 ) ;
}
void F_37 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_27 * V_28 = V_4 -> V_13 ;
struct V_9 * V_46 = V_8 -> V_17 ;
unsigned long V_79 ;
F_28 ( V_4 , V_8 ) ;
if ( V_46 -> V_18 != V_52 )
return;
#ifdef F_29
F_30 ( L_2 , V_4 -> V_48 ,
( F_7 ( V_8 ) -> type == V_16 ) ? L_3 : L_4 ) ;
#endif
F_38 ( V_28 -> V_31 , V_79 ) ;
if ( F_7 ( V_8 ) -> type == V_16 )
F_39 ( V_28 ) ;
else
V_4 -> V_60 &= ~ V_80 ;
F_40 ( V_28 -> V_31 , V_79 ) ;
V_4 -> V_6 -> V_8 = NULL ;
if ( F_41 ( V_8 , V_35 , 0 ) )
F_42 () ;
}
void F_43 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_46 = V_8 -> V_17 ;
if ( F_44 ( V_8 ) &&
F_7 ( V_8 ) -> type == V_16 &&
V_46 -> V_18 == V_19 )
V_4 -> V_60 |= V_80 ;
else if ( F_44 ( V_8 ) &&
F_7 ( V_8 ) -> type == V_38 &&
V_46 -> V_18 == V_40 ) {
T_3 * V_6 = V_4 -> V_6 ;
const struct V_81 * V_82 = V_6 -> V_82 ;
struct V_27 * V_28 = V_4 -> V_13 ;
unsigned long V_79 ;
int V_83 ;
#ifdef F_29
F_30 ( L_5 , V_4 -> V_48 ) ;
#endif
V_83 = F_45 ( V_6 , 35000 ) ;
if ( V_83 )
F_30 ( V_84 L_6 , V_4 -> V_48 ) ;
V_82 -> V_85 ( V_4 ) ;
V_82 -> V_86 ( V_6 , V_87 ) ;
V_83 = F_45 ( V_6 , 100000 ) ;
if ( V_83 )
F_30 ( V_84 L_7 , V_4 -> V_48 ) ;
F_38 ( V_28 -> V_31 , V_79 ) ;
F_46 ( V_28 ) ;
F_40 ( V_28 -> V_31 , V_79 ) ;
}
}
