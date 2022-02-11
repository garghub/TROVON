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
F_7 ( V_8 ) ;
F_8 ( V_8 ) -> type = V_16 ;
V_8 -> V_17 = & V_10 ;
V_10 . V_18 = V_19 ;
if ( V_3 . V_20 == V_21 )
V_3 . V_20 = V_22 ;
V_10 . V_23 = V_3 . V_20 ;
V_11 = F_9 ( V_4 -> V_13 , NULL , V_8 , 0 ) ;
F_10 ( V_8 ) ;
if ( V_11 == 0 && F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) || V_5 == NULL )
F_11 ( V_6 , 0 ) ;
}
return V_11 ;
}
static void F_12 ( struct V_7 * V_8 , int error )
{
F_13 ( V_8 -> V_24 ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = V_8 -> V_26 ;
F_15 ( V_27 ) ;
V_8 -> V_24 = & V_27 ;
V_8 -> V_28 = F_12 ;
F_16 ( V_26 -> V_29 ) ;
if ( F_17 ( F_18 ( V_26 ) ) ) {
V_8 -> V_30 |= V_31 ;
V_8 -> V_32 = - V_33 ;
F_19 ( V_8 , V_8 -> V_32 ) ;
F_20 ( V_26 -> V_29 ) ;
return - V_33 ;
}
F_21 ( V_26 , V_8 , V_34 ) ;
F_22 ( V_26 ) ;
F_20 ( V_26 -> V_29 ) ;
F_23 ( & V_27 ) ;
return V_8 -> V_32 ? - V_35 : 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
T_2 * V_4 = F_2 ( V_2 ) ;
T_2 * V_5 = F_3 ( V_4 ) ;
T_3 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_36 ;
if ( F_4 ( V_6 ) ) {
if ( ( V_4 -> V_12 & 1 ) == 0 || V_5 == NULL ) {
F_11 ( V_6 , 1 ) ;
F_25 ( V_6 ) ;
}
F_26 ( V_4 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_8 = F_6 ( V_4 -> V_13 , V_14 , V_15 ) ;
F_7 ( V_8 ) ;
F_8 ( V_8 ) -> type = V_37 ;
V_8 -> V_30 |= V_38 ;
V_8 -> V_17 = & V_10 ;
V_10 . V_18 = V_39 ;
V_10 . V_23 = V_40 ;
V_36 = F_14 ( V_8 ) ;
F_10 ( V_8 ) ;
if ( V_36 == 0 && V_2 -> V_41 ) {
struct V_42 * V_43 = F_27 ( V_2 -> V_41 ) ;
if ( V_43 -> V_44 )
V_43 -> V_44 ( V_4 ) ;
}
return V_36 ;
}
void F_28 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_45 = V_8 -> V_17 ;
#ifdef F_29
F_30 ( V_46 L_1 ,
V_4 -> V_47 , V_45 -> V_18 ) ;
#endif
if ( V_4 -> V_48 != V_49 )
return;
switch ( V_45 -> V_18 ) {
case V_50 :
if ( V_45 -> V_23 == V_22 )
V_45 -> V_18 = V_51 ;
else
V_45 -> V_18 = V_52 ;
break;
case V_52 :
V_45 -> V_18 = V_51 ;
break;
case V_53 :
V_45 -> V_18 = V_54 ;
break;
case V_54 :
V_45 -> V_18 = V_55 ;
break;
}
}
T_4 F_31 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_45 = V_8 -> V_17 ;
struct V_56 V_57 = { } ;
switch ( V_45 -> V_18 ) {
case V_50 :
if ( V_4 -> V_48 != V_49 )
break;
if ( F_32 ( V_4 -> V_58 ) == 0 ||
( V_4 -> V_59 & V_60 ) == 0 ) {
F_28 ( V_4 , V_8 ) ;
return V_61 ;
}
if ( F_33 ( V_4 -> V_58 ) )
V_57 . V_62 . V_63 = V_64 ;
else
V_57 . V_62 . V_63 = V_65 ;
goto V_66;
case V_52 :
V_57 . V_62 . V_63 = V_67 ;
goto V_66;
case V_53 :
F_34 ( V_4 ) ;
if ( V_4 -> V_48 != V_49 )
V_45 -> V_18 = V_55 ;
else
F_28 ( V_4 , V_8 ) ;
return V_61 ;
case V_54 :
V_57 . V_62 . V_63 = V_68 ;
goto V_66;
case V_55 :
if ( V_4 -> V_6 -> V_69 == NULL )
break;
F_35 ( V_4 ) ;
break;
}
V_45 -> V_18 = V_51 ;
return V_61 ;
V_66:
V_57 . V_70 . V_71 . V_62 = V_72 | V_73 ;
V_57 . V_70 . V_74 . V_62 = V_75 | V_73 ;
V_57 . V_76 = V_77 ;
return F_36 ( V_4 , & V_57 ) ;
}
void F_37 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_25 * V_26 = V_4 -> V_13 ;
struct V_9 * V_45 = V_8 -> V_17 ;
unsigned long V_78 ;
F_28 ( V_4 , V_8 ) ;
if ( V_45 -> V_18 != V_51 )
return;
#ifdef F_29
F_30 ( L_2 , V_4 -> V_47 ,
( F_8 ( V_8 ) -> type == V_16 ) ? L_3 : L_4 ) ;
#endif
F_38 ( V_26 -> V_29 , V_78 ) ;
if ( F_8 ( V_8 ) -> type == V_16 )
F_39 ( V_26 ) ;
else
V_4 -> V_59 &= ~ V_79 ;
F_40 ( V_26 -> V_29 , V_78 ) ;
V_4 -> V_6 -> V_8 = NULL ;
if ( F_41 ( V_8 , 0 , 0 ) )
F_42 () ;
}
void F_43 ( T_2 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_45 = V_8 -> V_17 ;
if ( F_44 ( V_8 ) &&
F_8 ( V_8 ) -> type == V_16 &&
V_45 -> V_18 == V_19 )
V_4 -> V_59 |= V_79 ;
else if ( F_44 ( V_8 ) &&
F_8 ( V_8 ) -> type == V_37 &&
V_45 -> V_18 == V_39 ) {
T_3 * V_6 = V_4 -> V_6 ;
const struct V_80 * V_81 = V_6 -> V_81 ;
struct V_25 * V_26 = V_4 -> V_13 ;
unsigned long V_78 ;
int V_82 ;
#ifdef F_29
F_30 ( L_5 , V_4 -> V_47 ) ;
#endif
V_82 = F_45 ( V_6 , 35000 ) ;
if ( V_82 )
F_30 ( V_83 L_6 , V_4 -> V_47 ) ;
V_81 -> V_84 ( V_4 ) ;
V_81 -> V_85 ( V_6 , V_86 ) ;
V_82 = F_45 ( V_6 , 100000 ) ;
if ( V_82 )
F_30 ( V_83 L_7 , V_4 -> V_47 ) ;
F_38 ( V_26 -> V_29 , V_78 ) ;
F_46 ( V_26 ) ;
F_40 ( V_26 -> V_29 , V_78 ) ;
}
}
