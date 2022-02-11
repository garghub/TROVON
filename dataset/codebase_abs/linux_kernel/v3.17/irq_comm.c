static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
#ifdef F_2
struct V_7 * V_8 = F_3 ( V_3 ) ;
return F_4 ( V_8 , V_2 -> V_9 . V_10 , V_4 , V_5 ) ;
#else
return - 1 ;
#endif
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 ,
bool V_6 )
{
struct V_11 * V_12 = V_3 -> V_13 . V_14 ;
return F_6 ( V_12 , V_2 -> V_9 . V_10 , V_4 , V_5 ,
V_6 ) ;
}
inline static bool F_7 ( struct V_15 * V_16 )
{
#ifdef F_8
return V_16 -> V_17 ==
( V_18 << V_19 ) ;
#else
return V_16 -> V_17 == V_20 ;
#endif
}
int F_9 ( struct V_3 * V_3 , struct V_21 * V_22 ,
struct V_15 * V_16 , unsigned long * V_23 )
{
int V_24 , V_25 = - 1 ;
struct V_26 * V_27 , * V_28 = NULL ;
if ( V_16 -> V_29 == 0 && V_16 -> V_30 == 0xff &&
F_7 ( V_16 ) ) {
F_10 ( V_31 L_1 ) ;
V_16 -> V_17 = V_32 ;
}
if ( F_11 ( V_3 , V_22 , V_16 , & V_25 , V_23 ) )
return V_25 ;
F_12 (i, vcpu, kvm) {
if ( ! F_13 ( V_27 ) )
continue;
if ( ! F_14 ( V_27 , V_22 , V_16 -> V_33 ,
V_16 -> V_30 , V_16 -> V_29 ) )
continue;
if ( ! F_7 ( V_16 ) ) {
if ( V_25 < 0 )
V_25 = 0 ;
V_25 += F_15 ( V_27 , V_16 , V_23 ) ;
} else if ( F_16 ( V_27 ) ) {
if ( ! V_28 )
V_28 = V_27 ;
else if ( F_17 ( V_27 , V_28 ) < 0 )
V_28 = V_27 ;
}
}
if ( V_28 )
V_25 = F_15 ( V_28 , V_16 , V_23 ) ;
return V_25 ;
}
static inline void F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_19 ( V_2 -> V_34 . V_35 , V_2 -> V_34 . V_36 ) ;
V_16 -> V_30 = ( V_2 -> V_34 . V_35 &
V_37 ) >> V_38 ;
V_16 -> V_39 = ( V_2 -> V_34 . V_36 &
V_40 ) >> V_41 ;
V_16 -> V_29 = ( 1 << V_42 ) & V_2 -> V_34 . V_35 ;
V_16 -> V_43 = ( 1 << V_44 ) & V_2 -> V_34 . V_36 ;
V_16 -> V_17 = V_2 -> V_34 . V_36 & 0x700 ;
V_16 -> V_5 = 1 ;
V_16 -> V_33 = 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 , bool V_6 )
{
struct V_15 V_16 ;
if ( ! V_5 )
return - 1 ;
F_18 ( V_2 , & V_16 ) ;
return F_9 ( V_3 , NULL , & V_16 , NULL ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_15 V_16 ;
int V_25 ;
F_18 ( V_2 , & V_16 ) ;
if ( F_11 ( V_3 , NULL , & V_16 , & V_25 , NULL ) )
return V_25 ;
else
return - V_45 ;
}
int F_22 ( struct V_3 * V_3 , int V_4 , T_1 V_16 , int V_5 )
{
struct V_1 V_46 [ V_47 ] ;
struct V_1 * V_2 ;
int V_48 = - V_49 ;
int V_50 ;
F_23 ( V_16 , V_5 , V_4 ) ;
V_50 = F_24 ( & V_3 -> V_51 ) ;
if ( F_25 ( V_3 , V_46 , V_16 ) > 0 ) {
V_2 = & V_46 [ 0 ] ;
if ( F_26 ( V_2 -> type == V_52 ) )
V_48 = F_21 ( V_2 , V_3 ) ;
else
V_48 = - V_45 ;
}
F_27 ( & V_3 -> V_51 , V_50 ) ;
return V_48 ;
}
int F_28 ( struct V_3 * V_3 )
{
unsigned long * V_53 = & V_3 -> V_13 . V_54 ;
int V_4 ;
F_29 ( & V_3 -> V_55 ) ;
V_4 = F_30 ( V_53 , V_56 ) ;
if ( V_4 >= V_56 ) {
F_10 ( V_57 L_2 ) ;
V_4 = - V_58 ;
goto V_59;
}
ASSERT ( V_4 != V_60 ) ;
#ifdef F_2
ASSERT ( V_4 != V_61 ) ;
#endif
F_31 ( V_4 , V_53 ) ;
V_59:
F_32 ( & V_3 -> V_55 ) ;
return V_4 ;
}
void F_33 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_60 ) ;
#ifdef F_2
ASSERT ( V_4 != V_61 ) ;
#endif
F_29 ( & V_3 -> V_55 ) ;
if ( V_4 < 0 ||
V_4 >= V_56 ) {
F_10 ( V_62 L_3 ) ;
goto V_59;
}
F_34 ( V_4 , & V_3 -> V_13 . V_54 ) ;
if ( ! F_35 ( V_3 ) )
goto V_59;
F_36 ( V_3 -> V_13 . V_14 , V_4 ) ;
#ifdef F_2
F_37 ( F_3 ( V_3 ) , V_4 ) ;
#endif
V_59:
F_32 ( & V_3 -> V_55 ) ;
}
void F_38 ( struct V_3 * V_3 , int V_16 ,
struct V_63 * V_64 )
{
F_29 ( & V_3 -> V_55 ) ;
V_64 -> V_16 = V_16 ;
F_39 ( & V_64 -> V_65 , & V_3 -> V_66 ) ;
F_32 ( & V_3 -> V_55 ) ;
}
void F_40 ( struct V_3 * V_3 , int V_16 ,
struct V_63 * V_64 )
{
F_29 ( & V_3 -> V_55 ) ;
F_41 ( & V_64 -> V_65 ) ;
F_32 ( & V_3 -> V_55 ) ;
F_42 ( & V_3 -> V_51 ) ;
}
void F_43 ( struct V_3 * V_3 , unsigned V_9 , unsigned V_10 ,
bool V_67 )
{
struct V_63 * V_64 ;
int V_50 , V_68 ;
V_50 = F_24 ( & V_3 -> V_51 ) ;
V_68 = F_44 ( V_3 , V_9 , V_10 ) ;
if ( V_68 != - 1 )
F_45 (kimn, &kvm->mask_notifier_list, link)
if ( V_64 -> V_16 == V_68 )
V_64 -> V_69 ( V_64 , V_67 ) ;
F_27 ( & V_3 -> V_51 , V_50 ) ;
}
int F_46 ( struct V_1 * V_2 ,
const struct V_70 * V_71 )
{
int V_25 = - V_49 ;
int V_72 ;
unsigned V_73 ;
switch ( V_71 -> type ) {
case V_74 :
V_72 = 0 ;
switch ( V_71 -> V_75 . V_9 . V_9 ) {
case V_76 :
V_2 -> V_77 = F_1 ;
V_73 = V_78 ;
break;
case V_79 :
V_2 -> V_77 = F_1 ;
V_73 = V_78 ;
V_72 = 8 ;
break;
case V_80 :
V_73 = V_81 ;
V_2 -> V_77 = F_5 ;
break;
default:
goto V_82;
}
V_2 -> V_9 . V_9 = V_71 -> V_75 . V_9 . V_9 ;
V_2 -> V_9 . V_10 = V_71 -> V_75 . V_9 . V_10 + V_72 ;
if ( V_2 -> V_9 . V_10 >= V_73 )
goto V_82;
break;
case V_52 :
V_2 -> V_77 = F_20 ;
V_2 -> V_34 . V_35 = V_71 -> V_75 . V_34 . V_35 ;
V_2 -> V_34 . V_83 = V_71 -> V_75 . V_34 . V_83 ;
V_2 -> V_34 . V_36 = V_71 -> V_75 . V_34 . V_36 ;
break;
default:
goto V_82;
}
V_25 = 0 ;
V_82:
return V_25 ;
}
int F_47 ( struct V_3 * V_3 )
{
return F_48 ( V_3 , V_84 ,
F_49 ( V_84 ) , 0 ) ;
}
