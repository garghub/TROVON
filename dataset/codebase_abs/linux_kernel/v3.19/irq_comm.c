static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
return F_3 ( V_8 , V_2 -> V_9 . V_10 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_11 * V_12 = V_3 -> V_13 . V_14 ;
return F_5 ( V_12 , V_2 -> V_9 . V_10 , V_4 , V_5 ,
V_6 ) ;
}
inline static bool F_6 ( struct V_15 * V_16 )
{
return V_16 -> V_17 == V_18 ;
}
int F_7 ( struct V_3 * V_3 , struct V_19 * V_20 ,
struct V_15 * V_16 , unsigned long * V_21 )
{
int V_22 , V_23 = - 1 ;
struct V_24 * V_25 , * V_26 = NULL ;
if ( V_16 -> V_27 == 0 && V_16 -> V_28 == 0xff &&
F_6 ( V_16 ) ) {
F_8 ( V_29 L_1 ) ;
V_16 -> V_17 = V_30 ;
}
if ( F_9 ( V_3 , V_20 , V_16 , & V_23 , V_21 ) )
return V_23 ;
F_10 (i, vcpu, kvm) {
if ( ! F_11 ( V_25 ) )
continue;
if ( ! F_12 ( V_25 , V_20 , V_16 -> V_31 ,
V_16 -> V_28 , V_16 -> V_27 ) )
continue;
if ( ! F_6 ( V_16 ) ) {
if ( V_23 < 0 )
V_23 = 0 ;
V_23 += F_13 ( V_25 , V_16 , V_21 ) ;
} else if ( F_14 ( V_25 ) ) {
if ( ! V_26 )
V_26 = V_25 ;
else if ( F_15 ( V_25 , V_26 ) < 0 )
V_26 = V_25 ;
}
}
if ( V_26 )
V_23 = F_13 ( V_26 , V_16 , V_21 ) ;
return V_23 ;
}
static inline void F_16 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_17 ( V_2 -> V_32 . V_33 , V_2 -> V_32 . V_34 ) ;
V_16 -> V_28 = ( V_2 -> V_32 . V_33 &
V_35 ) >> V_36 ;
V_16 -> V_37 = ( V_2 -> V_32 . V_34 &
V_38 ) >> V_39 ;
V_16 -> V_27 = ( 1 << V_40 ) & V_2 -> V_32 . V_33 ;
V_16 -> V_41 = ( 1 << V_42 ) & V_2 -> V_32 . V_34 ;
V_16 -> V_17 = V_2 -> V_32 . V_34 & 0x700 ;
V_16 -> V_5 = 1 ;
V_16 -> V_31 = 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_15 V_16 ;
if ( ! V_5 )
return - 1 ;
F_16 ( V_2 , & V_16 ) ;
return F_7 ( V_3 , NULL , & V_16 , NULL ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_15 V_16 ;
int V_23 ;
F_16 ( V_2 , & V_16 ) ;
if ( F_9 ( V_3 , NULL , & V_16 , & V_23 , NULL ) )
return V_23 ;
else
return - V_43 ;
}
int F_20 ( struct V_3 * V_3 , int V_4 , T_1 V_16 , int V_5 )
{
struct V_1 V_44 [ V_45 ] ;
struct V_1 * V_2 ;
int V_46 = - V_47 ;
int V_48 ;
F_21 ( V_16 , V_5 , V_4 ) ;
V_48 = F_22 ( & V_3 -> V_49 ) ;
if ( F_23 ( V_3 , V_44 , V_16 ) > 0 ) {
V_2 = & V_44 [ 0 ] ;
if ( F_24 ( V_2 -> type == V_50 ) )
V_46 = F_19 ( V_2 , V_3 ) ;
else
V_46 = - V_43 ;
}
F_25 ( & V_3 -> V_49 , V_48 ) ;
return V_46 ;
}
int F_26 ( struct V_3 * V_3 )
{
unsigned long * V_51 = & V_3 -> V_13 . V_52 ;
int V_4 ;
F_27 ( & V_3 -> V_53 ) ;
V_4 = F_28 ( V_51 , V_54 ) ;
if ( V_4 >= V_54 ) {
F_8 ( V_55 L_2 ) ;
V_4 = - V_56 ;
goto V_57;
}
ASSERT ( V_4 != V_58 ) ;
ASSERT ( V_4 != V_59 ) ;
F_29 ( V_4 , V_51 ) ;
V_57:
F_30 ( & V_3 -> V_53 ) ;
return V_4 ;
}
void F_31 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_58 ) ;
ASSERT ( V_4 != V_59 ) ;
F_27 ( & V_3 -> V_53 ) ;
if ( V_4 < 0 ||
V_4 >= V_54 ) {
F_8 ( V_60 L_3 ) ;
goto V_57;
}
F_32 ( V_4 , & V_3 -> V_13 . V_52 ) ;
if ( ! F_33 ( V_3 ) )
goto V_57;
F_34 ( V_3 -> V_13 . V_14 , V_4 ) ;
F_35 ( F_2 ( V_3 ) , V_4 ) ;
V_57:
F_30 ( & V_3 -> V_53 ) ;
}
void F_36 ( struct V_3 * V_3 , int V_16 ,
struct V_61 * V_62 )
{
F_27 ( & V_3 -> V_53 ) ;
V_62 -> V_16 = V_16 ;
F_37 ( & V_62 -> V_63 , & V_3 -> V_13 . V_64 ) ;
F_30 ( & V_3 -> V_53 ) ;
}
void F_38 ( struct V_3 * V_3 , int V_16 ,
struct V_61 * V_62 )
{
F_27 ( & V_3 -> V_53 ) ;
F_39 ( & V_62 -> V_63 ) ;
F_30 ( & V_3 -> V_53 ) ;
F_40 ( & V_3 -> V_49 ) ;
}
void F_41 ( struct V_3 * V_3 , unsigned V_9 , unsigned V_10 ,
bool V_65 )
{
struct V_61 * V_62 ;
int V_48 , V_66 ;
V_48 = F_22 ( & V_3 -> V_49 ) ;
V_66 = F_42 ( V_3 , V_9 , V_10 ) ;
if ( V_66 != - 1 )
F_43 (kimn, &kvm->arch.mask_notifier_list, link)
if ( V_62 -> V_16 == V_66 )
V_62 -> V_67 ( V_62 , V_65 ) ;
F_25 ( & V_3 -> V_49 , V_48 ) ;
}
int F_44 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
int V_23 = - V_47 ;
int V_70 ;
unsigned V_71 ;
switch ( V_69 -> type ) {
case V_72 :
V_70 = 0 ;
switch ( V_69 -> V_73 . V_9 . V_9 ) {
case V_74 :
V_2 -> V_75 = F_1 ;
V_71 = V_76 ;
break;
case V_77 :
V_2 -> V_75 = F_1 ;
V_71 = V_76 ;
V_70 = 8 ;
break;
case V_78 :
V_71 = V_79 ;
V_2 -> V_75 = F_4 ;
break;
default:
goto V_80;
}
V_2 -> V_9 . V_9 = V_69 -> V_73 . V_9 . V_9 ;
V_2 -> V_9 . V_10 = V_69 -> V_73 . V_9 . V_10 + V_70 ;
if ( V_2 -> V_9 . V_10 >= V_71 )
goto V_80;
break;
case V_50 :
V_2 -> V_75 = F_18 ;
V_2 -> V_32 . V_33 = V_69 -> V_73 . V_32 . V_33 ;
V_2 -> V_32 . V_81 = V_69 -> V_73 . V_32 . V_81 ;
V_2 -> V_32 . V_34 = V_69 -> V_73 . V_32 . V_34 ;
break;
default:
goto V_80;
}
V_23 = 0 ;
V_80:
return V_23 ;
}
int F_45 ( struct V_3 * V_3 )
{
return F_46 ( V_3 , V_82 ,
F_47 ( V_82 ) , 0 ) ;
}
