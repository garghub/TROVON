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
struct V_55 * V_56 ;
F_25 ( V_15 , V_5 , V_4 ) ;
F_26 () ;
V_54 = F_27 ( V_3 -> V_57 ) ;
if ( V_15 < V_54 -> V_58 )
F_28 (e, n, &irq_rt->map[irq], link)
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
struct V_55 * V_56 ;
F_25 ( V_15 , V_5 , V_4 ) ;
F_26 () ;
V_54 = F_27 ( V_3 -> V_57 ) ;
if ( V_15 < V_54 -> V_58 )
F_28 (e, n, &irq_rt->map[irq], link) {
if ( F_32 ( V_2 -> type == V_59 ) )
V_52 = F_21 ( V_2 , V_3 ) ;
else
V_52 = - V_43 ;
break;
}
F_29 () ;
return V_52 ;
}
void F_33 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 )
{
struct V_60 * V_61 ;
struct V_55 * V_56 ;
int V_62 ;
F_34 ( V_8 , V_9 ) ;
F_26 () ;
V_62 = F_27 ( V_3 -> V_57 ) -> V_63 [ V_8 ] [ V_9 ] ;
if ( V_62 != - 1 )
F_35 (kian, n, &kvm->irq_ack_notifier_list,
link)
if ( V_61 -> V_62 == V_62 )
V_61 -> V_64 ( V_61 ) ;
F_29 () ;
}
void F_36 ( struct V_3 * V_3 ,
struct V_60 * V_61 )
{
F_37 ( & V_3 -> V_65 ) ;
F_38 ( & V_61 -> V_66 , & V_3 -> V_67 ) ;
F_39 ( & V_3 -> V_65 ) ;
}
void F_40 ( struct V_3 * V_3 ,
struct V_60 * V_61 )
{
F_37 ( & V_3 -> V_65 ) ;
F_41 ( & V_61 -> V_66 ) ;
F_39 ( & V_3 -> V_65 ) ;
F_42 () ;
}
int F_43 ( struct V_3 * V_3 )
{
unsigned long * V_68 = & V_3 -> V_12 . V_69 ;
int V_4 ;
F_37 ( & V_3 -> V_65 ) ;
V_4 = F_44 ( V_68 , V_70 ) ;
if ( V_4 >= V_70 ) {
F_10 ( V_71 L_2 ) ;
V_4 = - V_72 ;
goto V_73;
}
ASSERT ( V_4 != V_49 ) ;
#ifdef F_2
ASSERT ( V_4 != V_74 ) ;
#endif
F_45 ( V_4 , V_68 ) ;
V_73:
F_39 ( & V_3 -> V_65 ) ;
return V_4 ;
}
void F_46 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_49 ) ;
#ifdef F_2
ASSERT ( V_4 != V_74 ) ;
#endif
F_37 ( & V_3 -> V_65 ) ;
if ( V_4 < 0 ||
V_4 >= V_70 ) {
F_10 ( V_75 L_3 ) ;
goto V_73;
}
F_47 ( V_4 , & V_3 -> V_12 . V_69 ) ;
if ( ! F_23 ( V_3 ) )
goto V_73;
F_48 ( V_3 -> V_12 . V_13 , V_4 ) ;
#ifdef F_2
F_49 ( F_3 ( V_3 ) , V_4 ) ;
#endif
V_73:
F_39 ( & V_3 -> V_65 ) ;
}
void F_50 ( struct V_3 * V_3 , int V_15 ,
struct V_76 * V_77 )
{
F_37 ( & V_3 -> V_65 ) ;
V_77 -> V_15 = V_15 ;
F_38 ( & V_77 -> V_66 , & V_3 -> V_78 ) ;
F_39 ( & V_3 -> V_65 ) ;
}
void F_51 ( struct V_3 * V_3 , int V_15 ,
struct V_76 * V_77 )
{
F_37 ( & V_3 -> V_65 ) ;
F_52 ( & V_77 -> V_66 ) ;
F_39 ( & V_3 -> V_65 ) ;
F_42 () ;
}
void F_53 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 ,
bool V_79 )
{
struct V_76 * V_77 ;
struct V_55 * V_56 ;
int V_62 ;
F_26 () ;
V_62 = F_27 ( V_3 -> V_57 ) -> V_63 [ V_8 ] [ V_9 ] ;
if ( V_62 != - 1 )
F_35 (kimn, n, &kvm->mask_notifier_list, link)
if ( V_77 -> V_15 == V_62 )
V_77 -> V_80 ( V_77 , V_79 ) ;
F_29 () ;
}
void F_54 ( struct V_3 * V_3 )
{
F_55 ( V_3 -> V_57 ) ;
}
static int F_56 ( struct V_53 * V_81 ,
struct V_1 * V_2 ,
const struct V_82 * V_83 )
{
int V_23 = - V_47 ;
int V_84 ;
unsigned V_85 ;
struct V_1 * V_86 ;
struct V_55 * V_56 ;
F_28 (ei, n, &rt->map[ue->gsi], link)
if ( V_86 -> type == V_59 ||
V_83 -> type == V_59 ||
V_83 -> V_87 . V_8 . V_8 == V_86 -> V_8 . V_8 )
return V_23 ;
V_2 -> V_62 = V_83 -> V_62 ;
V_2 -> type = V_83 -> type ;
switch ( V_83 -> type ) {
case V_88 :
V_84 = 0 ;
switch ( V_83 -> V_87 . V_8 . V_8 ) {
case V_89 :
V_2 -> F_30 = F_1 ;
V_85 = V_90 ;
break;
case V_91 :
V_2 -> F_30 = F_1 ;
V_85 = V_90 ;
V_84 = 8 ;
break;
case V_92 :
V_85 = V_93 ;
V_2 -> F_30 = F_5 ;
break;
default:
goto V_94;
}
V_2 -> V_8 . V_8 = V_83 -> V_87 . V_8 . V_8 ;
V_2 -> V_8 . V_9 = V_83 -> V_87 . V_8 . V_9 + V_84 ;
if ( V_2 -> V_8 . V_9 >= V_85 )
goto V_94;
V_81 -> V_63 [ V_83 -> V_87 . V_8 . V_8 ] [ V_2 -> V_8 . V_9 ] = V_83 -> V_62 ;
break;
case V_59 :
V_2 -> F_30 = F_20 ;
V_2 -> V_32 . V_33 = V_83 -> V_87 . V_32 . V_33 ;
V_2 -> V_32 . V_48 = V_83 -> V_87 . V_32 . V_48 ;
V_2 -> V_32 . V_34 = V_83 -> V_87 . V_32 . V_34 ;
break;
default:
goto V_94;
}
F_57 ( & V_2 -> V_66 , & V_81 -> V_95 [ V_2 -> V_62 ] ) ;
V_23 = 0 ;
V_94:
return V_23 ;
}
int F_58 ( struct V_3 * V_3 ,
const struct V_82 * V_83 ,
unsigned V_96 ,
unsigned V_46 )
{
struct V_53 * V_97 , * V_98 ;
T_1 V_22 , V_99 , V_58 = 0 ;
int V_23 ;
for ( V_22 = 0 ; V_22 < V_96 ; ++ V_22 ) {
if ( V_83 [ V_22 ] . V_62 >= V_100 )
return - V_47 ;
V_58 = F_59 ( V_58 , V_83 [ V_22 ] . V_62 ) ;
}
V_58 += 1 ;
V_97 = F_60 ( sizeof( * V_97 ) + ( V_58 * sizeof( struct V_101 ) )
+ ( V_96 * sizeof( struct V_1 ) ) ,
V_102 ) ;
if ( ! V_97 )
return - V_103 ;
V_97 -> V_104 = ( void * ) & V_97 -> V_95 [ V_58 ] ;
V_97 -> V_58 = V_58 ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
for ( V_99 = 0 ; V_99 < V_93 ; V_99 ++ )
V_97 -> V_63 [ V_22 ] [ V_99 ] = - 1 ;
for ( V_22 = 0 ; V_22 < V_96 ; ++ V_22 ) {
V_23 = - V_47 ;
if ( V_83 -> V_46 )
goto V_94;
V_23 = F_56 ( V_97 , & V_97 -> V_104 [ V_22 ] , V_83 ) ;
if ( V_23 )
goto V_94;
++ V_83 ;
}
F_37 ( & V_3 -> V_65 ) ;
V_98 = V_3 -> V_57 ;
F_61 ( V_3 , V_97 ) ;
F_39 ( & V_3 -> V_65 ) ;
F_42 () ;
V_97 = V_98 ;
V_23 = 0 ;
V_94:
F_55 ( V_97 ) ;
return V_23 ;
}
int F_62 ( struct V_3 * V_3 )
{
return F_58 ( V_3 , V_105 ,
F_63 ( V_105 ) , 0 ) ;
}
