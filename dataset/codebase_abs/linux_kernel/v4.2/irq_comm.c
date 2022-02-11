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
int F_6 ( struct V_3 * V_3 , struct V_15 * V_16 ,
struct V_17 * V_18 , unsigned long * V_19 )
{
int V_20 , V_21 = - 1 ;
struct V_22 * V_23 , * V_24 = NULL ;
if ( V_18 -> V_25 == 0 && V_18 -> V_26 == 0xff &&
F_7 ( V_18 ) ) {
F_8 ( V_27 L_1 ) ;
V_18 -> V_28 = V_29 ;
}
if ( F_9 ( V_3 , V_16 , V_18 , & V_21 , V_19 ) )
return V_21 ;
F_10 (i, vcpu, kvm) {
if ( ! F_11 ( V_23 ) )
continue;
if ( ! F_12 ( V_23 , V_16 , V_18 -> V_30 ,
V_18 -> V_26 , V_18 -> V_25 ) )
continue;
if ( ! F_7 ( V_18 ) ) {
if ( V_21 < 0 )
V_21 = 0 ;
V_21 += F_13 ( V_23 , V_18 , V_19 ) ;
} else if ( F_14 ( V_23 ) ) {
if ( ! V_24 )
V_24 = V_23 ;
else if ( F_15 ( V_23 , V_24 ) < 0 )
V_24 = V_23 ;
}
}
if ( V_24 )
V_21 = F_13 ( V_24 , V_18 , V_19 ) ;
return V_21 ;
}
static inline void F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
F_17 ( V_2 -> V_31 . V_32 , V_2 -> V_31 . V_33 ) ;
V_18 -> V_26 = ( V_2 -> V_31 . V_32 &
V_34 ) >> V_35 ;
V_18 -> V_36 = ( V_2 -> V_31 . V_33 &
V_37 ) >> V_38 ;
V_18 -> V_25 = ( 1 << V_39 ) & V_2 -> V_31 . V_32 ;
V_18 -> V_40 = ( 1 << V_41 ) & V_2 -> V_31 . V_33 ;
V_18 -> V_28 = V_2 -> V_31 . V_33 & 0x700 ;
V_18 -> V_42 = ( ( V_2 -> V_31 . V_32
& V_43 ) > 0 ) ;
V_18 -> V_5 = 1 ;
V_18 -> V_30 = 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_17 V_18 ;
if ( ! V_5 )
return - 1 ;
F_16 ( V_2 , & V_18 ) ;
return F_6 ( V_3 , NULL , & V_18 , NULL ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_17 V_18 ;
int V_21 ;
F_16 ( V_2 , & V_18 ) ;
if ( F_9 ( V_3 , NULL , & V_18 , & V_21 , NULL ) )
return V_21 ;
else
return - V_44 ;
}
int F_20 ( struct V_3 * V_3 , int V_4 , T_1 V_18 , int V_5 )
{
struct V_1 V_45 [ V_46 ] ;
struct V_1 * V_2 ;
int V_47 = - V_48 ;
int V_49 ;
F_21 ( V_18 , V_5 , V_4 ) ;
V_49 = F_22 ( & V_3 -> V_50 ) ;
if ( F_23 ( V_3 , V_45 , V_18 ) > 0 ) {
V_2 = & V_45 [ 0 ] ;
if ( F_24 ( V_2 -> type == V_51 ) )
V_47 = F_19 ( V_2 , V_3 ) ;
else
V_47 = - V_44 ;
}
F_25 ( & V_3 -> V_50 , V_49 ) ;
return V_47 ;
}
int F_26 ( struct V_3 * V_3 )
{
unsigned long * V_52 = & V_3 -> V_13 . V_53 ;
int V_4 ;
F_27 ( & V_3 -> V_54 ) ;
V_4 = F_28 ( V_52 , V_55 ) ;
if ( V_4 >= V_55 ) {
F_8 ( V_56 L_2 ) ;
V_4 = - V_57 ;
goto V_58;
}
ASSERT ( V_4 != V_59 ) ;
ASSERT ( V_4 != V_60 ) ;
F_29 ( V_4 , V_52 ) ;
V_58:
F_30 ( & V_3 -> V_54 ) ;
return V_4 ;
}
void F_31 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_59 ) ;
ASSERT ( V_4 != V_60 ) ;
F_27 ( & V_3 -> V_54 ) ;
if ( V_4 < 0 ||
V_4 >= V_55 ) {
F_8 ( V_61 L_3 ) ;
goto V_58;
}
F_32 ( V_4 , & V_3 -> V_13 . V_53 ) ;
if ( ! F_33 ( V_3 ) )
goto V_58;
F_34 ( V_3 -> V_13 . V_14 , V_4 ) ;
F_35 ( F_2 ( V_3 ) , V_4 ) ;
V_58:
F_30 ( & V_3 -> V_54 ) ;
}
void F_36 ( struct V_3 * V_3 , int V_18 ,
struct V_62 * V_63 )
{
F_27 ( & V_3 -> V_54 ) ;
V_63 -> V_18 = V_18 ;
F_37 ( & V_63 -> V_64 , & V_3 -> V_13 . V_65 ) ;
F_30 ( & V_3 -> V_54 ) ;
}
void F_38 ( struct V_3 * V_3 , int V_18 ,
struct V_62 * V_63 )
{
F_27 ( & V_3 -> V_54 ) ;
F_39 ( & V_63 -> V_64 ) ;
F_30 ( & V_3 -> V_54 ) ;
F_40 ( & V_3 -> V_50 ) ;
}
void F_41 ( struct V_3 * V_3 , unsigned V_9 , unsigned V_10 ,
bool V_66 )
{
struct V_62 * V_63 ;
int V_49 , V_67 ;
V_49 = F_22 ( & V_3 -> V_50 ) ;
V_67 = F_42 ( V_3 , V_9 , V_10 ) ;
if ( V_67 != - 1 )
F_43 (kimn, &kvm->arch.mask_notifier_list, link)
if ( V_63 -> V_18 == V_67 )
V_63 -> V_68 ( V_63 , V_66 ) ;
F_25 ( & V_3 -> V_50 , V_49 ) ;
}
int F_44 ( struct V_1 * V_2 ,
const struct V_69 * V_70 )
{
int V_21 = - V_48 ;
int V_71 ;
unsigned V_72 ;
switch ( V_70 -> type ) {
case V_73 :
V_71 = 0 ;
switch ( V_70 -> V_74 . V_9 . V_9 ) {
case V_75 :
V_2 -> V_76 = F_1 ;
V_72 = V_77 ;
break;
case V_78 :
V_2 -> V_76 = F_1 ;
V_72 = V_77 ;
V_71 = 8 ;
break;
case V_79 :
V_72 = V_80 ;
V_2 -> V_76 = F_4 ;
break;
default:
goto V_81;
}
V_2 -> V_9 . V_9 = V_70 -> V_74 . V_9 . V_9 ;
V_2 -> V_9 . V_10 = V_70 -> V_74 . V_9 . V_10 + V_71 ;
if ( V_2 -> V_9 . V_10 >= V_72 )
goto V_81;
break;
case V_51 :
V_2 -> V_76 = F_18 ;
V_2 -> V_31 . V_32 = V_70 -> V_74 . V_31 . V_32 ;
V_2 -> V_31 . V_82 = V_70 -> V_74 . V_31 . V_82 ;
V_2 -> V_31 . V_33 = V_70 -> V_74 . V_31 . V_33 ;
break;
default:
goto V_81;
}
V_21 = 0 ;
V_81:
return V_21 ;
}
int F_45 ( struct V_3 * V_3 )
{
return F_46 ( V_3 , V_83 ,
F_47 ( V_83 ) , 0 ) ;
}
