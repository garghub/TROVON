static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 )
{
#ifdef F_2
struct V_6 * V_7 = F_3 ( V_3 ) ;
return F_4 ( V_7 , V_2 -> V_8 . V_9 , V_4 , V_5 ) ;
#else
return - 1 ;
#endif
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 )
{
struct V_10 * V_11 = V_3 -> V_12 . V_13 ;
return F_6 ( V_11 , V_2 -> V_8 . V_9 , V_4 , V_5 ) ;
}
inline static bool F_7 ( struct V_14 * V_15 )
{
#ifdef F_8
return V_15 -> V_16 ==
( V_17 << V_18 ) ;
#else
return V_15 -> V_16 == V_19 ;
#endif
}
int F_9 ( struct V_3 * V_3 , struct V_20 * V_21 ,
struct V_14 * V_15 )
{
int V_22 , V_23 = - 1 ;
struct V_24 * V_25 , * V_26 = NULL ;
if ( V_15 -> V_27 == 0 && V_15 -> V_28 == 0xff &&
F_7 ( V_15 ) ) {
F_10 ( V_29 L_1 ) ;
V_15 -> V_16 = V_30 ;
}
if ( F_11 ( V_3 , V_21 , V_15 , & V_23 ) )
return V_23 ;
F_12 (i, vcpu, kvm) {
if ( ! F_13 ( V_25 ) )
continue;
if ( ! F_14 ( V_25 , V_21 , V_15 -> V_31 ,
V_15 -> V_28 , V_15 -> V_27 ) )
continue;
if ( ! F_7 ( V_15 ) ) {
if ( V_23 < 0 )
V_23 = 0 ;
V_23 += F_15 ( V_25 , V_15 ) ;
} else if ( F_16 ( V_25 ) ) {
if ( ! V_26 )
V_26 = V_25 ;
else if ( F_17 ( V_25 , V_26 ) < 0 )
V_26 = V_25 ;
}
}
if ( V_26 )
V_23 = F_15 ( V_26 , V_15 ) ;
return V_23 ;
}
static inline void F_18 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_19 ( V_2 -> V_32 . V_33 , V_2 -> V_32 . V_34 ) ;
V_15 -> V_28 = ( V_2 -> V_32 . V_33 &
V_35 ) >> V_36 ;
V_15 -> V_37 = ( V_2 -> V_32 . V_34 &
V_38 ) >> V_39 ;
V_15 -> V_27 = ( 1 << V_40 ) & V_2 -> V_32 . V_33 ;
V_15 -> V_41 = ( 1 << V_42 ) & V_2 -> V_32 . V_34 ;
V_15 -> V_16 = V_2 -> V_32 . V_34 & 0x700 ;
V_15 -> V_5 = 1 ;
V_15 -> V_31 = 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 )
{
struct V_14 V_15 ;
if ( ! V_5 )
return - 1 ;
F_18 ( V_2 , & V_15 ) ;
return F_9 ( V_3 , NULL , & V_15 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_14 V_15 ;
int V_23 ;
F_18 ( V_2 , & V_15 ) ;
if ( F_11 ( V_3 , NULL , & V_15 , & V_23 ) )
return V_23 ;
else
return - V_43 ;
}
int F_22 ( struct V_3 * V_3 , struct V_44 * V_32 )
{
struct V_1 V_45 ;
if ( ! F_23 ( V_3 ) || V_32 -> V_46 != 0 )
return - V_47 ;
V_45 . V_32 . V_33 = V_32 -> V_33 ;
V_45 . V_32 . V_48 = V_32 -> V_48 ;
V_45 . V_32 . V_34 = V_32 -> V_34 ;
return F_20 ( & V_45 , V_3 , V_49 , 1 ) ;
}
int F_24 ( struct V_3 * V_3 , int V_4 , T_1 V_15 , int V_5 )
{
struct V_1 * V_2 , V_50 [ V_51 ] ;
int V_52 = - 1 , V_22 = 0 ;
struct V_53 * V_54 ;
F_25 ( V_15 , V_5 , V_4 ) ;
F_26 () ;
V_54 = F_27 ( V_3 -> V_55 ) ;
if ( V_15 < V_54 -> V_56 )
F_28 (e, &irq_rt->map[irq], link)
V_50 [ V_22 ++ ] = * V_2 ;
F_29 () ;
while( V_22 -- ) {
int V_23 ;
V_23 = V_50 [ V_22 ] . F_30 ( & V_50 [ V_22 ] , V_3 , V_4 , V_5 ) ;
if ( V_23 < 0 )
continue;
V_52 = V_23 + ( ( V_52 < 0 ) ? 0 : V_52 ) ;
}
return V_52 ;
}
int F_31 ( struct V_3 * V_3 , int V_4 , T_1 V_15 , int V_5 )
{
struct V_1 * V_2 ;
int V_52 = - V_47 ;
struct V_53 * V_54 ;
F_25 ( V_15 , V_5 , V_4 ) ;
F_26 () ;
V_54 = F_27 ( V_3 -> V_55 ) ;
if ( V_15 < V_54 -> V_56 )
F_28 (e, &irq_rt->map[irq], link) {
if ( F_32 ( V_2 -> type == V_57 ) )
V_52 = F_21 ( V_2 , V_3 ) ;
else
V_52 = - V_43 ;
break;
}
F_29 () ;
return V_52 ;
}
bool F_33 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 )
{
struct V_58 * V_59 ;
int V_60 ;
F_26 () ;
V_60 = F_27 ( V_3 -> V_55 ) -> V_61 [ V_8 ] [ V_9 ] ;
if ( V_60 != - 1 )
F_34 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_59 -> V_60 == V_60 ) {
F_29 () ;
return true ;
}
F_29 () ;
return false ;
}
void F_35 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 )
{
struct V_58 * V_59 ;
int V_60 ;
F_36 ( V_8 , V_9 ) ;
F_26 () ;
V_60 = F_27 ( V_3 -> V_55 ) -> V_61 [ V_8 ] [ V_9 ] ;
if ( V_60 != - 1 )
F_34 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_59 -> V_60 == V_60 )
V_59 -> V_62 ( V_59 ) ;
F_29 () ;
}
void F_37 ( struct V_3 * V_3 ,
struct V_58 * V_59 )
{
F_38 ( & V_3 -> V_63 ) ;
F_39 ( & V_59 -> V_64 , & V_3 -> V_65 ) ;
F_40 ( & V_3 -> V_63 ) ;
F_41 ( V_3 ) ;
}
void F_42 ( struct V_3 * V_3 ,
struct V_58 * V_59 )
{
F_38 ( & V_3 -> V_63 ) ;
F_43 ( & V_59 -> V_64 ) ;
F_40 ( & V_3 -> V_63 ) ;
F_44 () ;
F_41 ( V_3 ) ;
}
int F_45 ( struct V_3 * V_3 )
{
unsigned long * V_66 = & V_3 -> V_12 . V_67 ;
int V_4 ;
F_38 ( & V_3 -> V_63 ) ;
V_4 = F_46 ( V_66 , V_68 ) ;
if ( V_4 >= V_68 ) {
F_10 ( V_69 L_2 ) ;
V_4 = - V_70 ;
goto V_71;
}
ASSERT ( V_4 != V_49 ) ;
#ifdef F_2
ASSERT ( V_4 != V_72 ) ;
#endif
F_47 ( V_4 , V_66 ) ;
V_71:
F_40 ( & V_3 -> V_63 ) ;
return V_4 ;
}
void F_48 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_49 ) ;
#ifdef F_2
ASSERT ( V_4 != V_72 ) ;
#endif
F_38 ( & V_3 -> V_63 ) ;
if ( V_4 < 0 ||
V_4 >= V_68 ) {
F_10 ( V_73 L_3 ) ;
goto V_71;
}
F_49 ( V_4 , & V_3 -> V_12 . V_67 ) ;
if ( ! F_23 ( V_3 ) )
goto V_71;
F_50 ( V_3 -> V_12 . V_13 , V_4 ) ;
#ifdef F_2
F_51 ( F_3 ( V_3 ) , V_4 ) ;
#endif
V_71:
F_40 ( & V_3 -> V_63 ) ;
}
void F_52 ( struct V_3 * V_3 , int V_15 ,
struct V_74 * V_75 )
{
F_38 ( & V_3 -> V_63 ) ;
V_75 -> V_15 = V_15 ;
F_39 ( & V_75 -> V_64 , & V_3 -> V_76 ) ;
F_40 ( & V_3 -> V_63 ) ;
}
void F_53 ( struct V_3 * V_3 , int V_15 ,
struct V_74 * V_75 )
{
F_38 ( & V_3 -> V_63 ) ;
F_54 ( & V_75 -> V_64 ) ;
F_40 ( & V_3 -> V_63 ) ;
F_44 () ;
}
void F_55 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 ,
bool V_77 )
{
struct V_74 * V_75 ;
int V_60 ;
F_26 () ;
V_60 = F_27 ( V_3 -> V_55 ) -> V_61 [ V_8 ] [ V_9 ] ;
if ( V_60 != - 1 )
F_34 (kimn, &kvm->mask_notifier_list, link)
if ( V_75 -> V_15 == V_60 )
V_75 -> V_78 ( V_75 , V_77 ) ;
F_29 () ;
}
void F_56 ( struct V_3 * V_3 )
{
F_57 ( V_3 -> V_55 ) ;
}
static int F_58 ( struct V_53 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
int V_23 = - V_47 ;
int V_82 ;
unsigned V_83 ;
struct V_1 * V_84 ;
F_28 (ei, &rt->map[ue->gsi], link)
if ( V_84 -> type == V_57 ||
V_81 -> type == V_57 ||
V_81 -> V_85 . V_8 . V_8 == V_84 -> V_8 . V_8 )
return V_23 ;
V_2 -> V_60 = V_81 -> V_60 ;
V_2 -> type = V_81 -> type ;
switch ( V_81 -> type ) {
case V_86 :
V_82 = 0 ;
switch ( V_81 -> V_85 . V_8 . V_8 ) {
case V_87 :
V_2 -> F_30 = F_1 ;
V_83 = V_88 ;
break;
case V_89 :
V_2 -> F_30 = F_1 ;
V_83 = V_88 ;
V_82 = 8 ;
break;
case V_90 :
V_83 = V_91 ;
V_2 -> F_30 = F_5 ;
break;
default:
goto V_92;
}
V_2 -> V_8 . V_8 = V_81 -> V_85 . V_8 . V_8 ;
V_2 -> V_8 . V_9 = V_81 -> V_85 . V_8 . V_9 + V_82 ;
if ( V_2 -> V_8 . V_9 >= V_83 )
goto V_92;
V_79 -> V_61 [ V_81 -> V_85 . V_8 . V_8 ] [ V_2 -> V_8 . V_9 ] = V_81 -> V_60 ;
break;
case V_57 :
V_2 -> F_30 = F_20 ;
V_2 -> V_32 . V_33 = V_81 -> V_85 . V_32 . V_33 ;
V_2 -> V_32 . V_48 = V_81 -> V_85 . V_32 . V_48 ;
V_2 -> V_32 . V_34 = V_81 -> V_85 . V_32 . V_34 ;
break;
default:
goto V_92;
}
F_59 ( & V_2 -> V_64 , & V_79 -> V_93 [ V_2 -> V_60 ] ) ;
V_23 = 0 ;
V_92:
return V_23 ;
}
int F_60 ( struct V_3 * V_3 ,
const struct V_80 * V_81 ,
unsigned V_94 ,
unsigned V_46 )
{
struct V_53 * V_95 , * V_96 ;
T_1 V_22 , V_97 , V_56 = 0 ;
int V_23 ;
for ( V_22 = 0 ; V_22 < V_94 ; ++ V_22 ) {
if ( V_81 [ V_22 ] . V_60 >= V_98 )
return - V_47 ;
V_56 = F_61 ( V_56 , V_81 [ V_22 ] . V_60 ) ;
}
V_56 += 1 ;
V_95 = F_62 ( sizeof( * V_95 ) + ( V_56 * sizeof( struct V_99 ) )
+ ( V_94 * sizeof( struct V_1 ) ) ,
V_100 ) ;
if ( ! V_95 )
return - V_101 ;
V_95 -> V_102 = ( void * ) & V_95 -> V_93 [ V_56 ] ;
V_95 -> V_56 = V_56 ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
for ( V_97 = 0 ; V_97 < V_91 ; V_97 ++ )
V_95 -> V_61 [ V_22 ] [ V_97 ] = - 1 ;
for ( V_22 = 0 ; V_22 < V_94 ; ++ V_22 ) {
V_23 = - V_47 ;
if ( V_81 -> V_46 )
goto V_92;
V_23 = F_58 ( V_95 , & V_95 -> V_102 [ V_22 ] , V_81 ) ;
if ( V_23 )
goto V_92;
++ V_81 ;
}
F_38 ( & V_3 -> V_63 ) ;
V_96 = V_3 -> V_55 ;
F_63 ( V_3 , V_95 ) ;
F_40 ( & V_3 -> V_63 ) ;
F_44 () ;
V_95 = V_96 ;
V_23 = 0 ;
V_92:
F_57 ( V_95 ) ;
return V_23 ;
}
int F_64 ( struct V_3 * V_3 )
{
return F_60 ( V_3 , V_103 ,
F_65 ( V_103 ) , 0 ) ;
}
