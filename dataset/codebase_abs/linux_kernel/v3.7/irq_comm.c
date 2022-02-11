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
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 )
{
struct V_14 V_15 ;
if ( ! V_5 )
return - 1 ;
F_19 ( V_2 -> V_32 . V_33 , V_2 -> V_32 . V_34 ) ;
V_15 . V_28 = ( V_2 -> V_32 . V_33 &
V_35 ) >> V_36 ;
V_15 . V_37 = ( V_2 -> V_32 . V_34 &
V_38 ) >> V_39 ;
V_15 . V_27 = ( 1 << V_40 ) & V_2 -> V_32 . V_33 ;
V_15 . V_41 = ( 1 << V_42 ) & V_2 -> V_32 . V_34 ;
V_15 . V_16 = V_2 -> V_32 . V_34 & 0x700 ;
V_15 . V_5 = 1 ;
V_15 . V_31 = 0 ;
return F_9 ( V_3 , NULL , & V_15 ) ;
}
int F_20 ( struct V_3 * V_3 , struct V_43 * V_32 )
{
struct V_1 V_44 ;
if ( ! F_21 ( V_3 ) || V_32 -> V_45 != 0 )
return - V_46 ;
V_44 . V_32 . V_33 = V_32 -> V_33 ;
V_44 . V_32 . V_47 = V_32 -> V_47 ;
V_44 . V_32 . V_34 = V_32 -> V_34 ;
return F_18 ( & V_44 , V_3 , V_48 , 1 ) ;
}
int F_22 ( struct V_3 * V_3 , int V_4 , T_1 V_15 , int V_5 )
{
struct V_1 * V_2 , V_49 [ V_50 ] ;
int V_51 = - 1 , V_22 = 0 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_23 ( V_15 , V_5 , V_4 ) ;
F_24 () ;
V_53 = F_25 ( V_3 -> V_56 ) ;
if ( V_15 < V_53 -> V_57 )
F_26 (e, n, &irq_rt->map[irq], link)
V_49 [ V_22 ++ ] = * V_2 ;
F_27 () ;
while( V_22 -- ) {
int V_23 ;
V_23 = V_49 [ V_22 ] . F_28 ( & V_49 [ V_22 ] , V_3 , V_4 , V_5 ) ;
if ( V_23 < 0 )
continue;
V_51 = V_23 + ( ( V_51 < 0 ) ? 0 : V_51 ) ;
}
return V_51 ;
}
void F_29 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 )
{
struct V_58 * V_59 ;
struct V_54 * V_55 ;
int V_60 ;
F_30 ( V_8 , V_9 ) ;
F_24 () ;
V_60 = F_25 ( V_3 -> V_56 ) -> V_61 [ V_8 ] [ V_9 ] ;
if ( V_60 != - 1 )
F_31 (kian, n, &kvm->irq_ack_notifier_list,
link)
if ( V_59 -> V_60 == V_60 )
V_59 -> V_62 ( V_59 ) ;
F_27 () ;
}
void F_32 ( struct V_3 * V_3 ,
struct V_58 * V_59 )
{
F_33 ( & V_3 -> V_63 ) ;
F_34 ( & V_59 -> V_64 , & V_3 -> V_65 ) ;
F_35 ( & V_3 -> V_63 ) ;
}
void F_36 ( struct V_3 * V_3 ,
struct V_58 * V_59 )
{
F_33 ( & V_3 -> V_63 ) ;
F_37 ( & V_59 -> V_64 ) ;
F_35 ( & V_3 -> V_63 ) ;
F_38 () ;
}
int F_39 ( struct V_3 * V_3 )
{
unsigned long * V_66 = & V_3 -> V_12 . V_67 ;
int V_4 ;
F_33 ( & V_3 -> V_63 ) ;
V_4 = F_40 ( V_66 , V_68 ) ;
if ( V_4 >= V_68 ) {
F_10 ( V_69 L_2 ) ;
V_4 = - V_70 ;
goto V_71;
}
ASSERT ( V_4 != V_48 ) ;
#ifdef F_2
ASSERT ( V_4 != V_72 ) ;
#endif
F_41 ( V_4 , V_66 ) ;
V_71:
F_35 ( & V_3 -> V_63 ) ;
return V_4 ;
}
void F_42 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_48 ) ;
#ifdef F_2
ASSERT ( V_4 != V_72 ) ;
#endif
F_33 ( & V_3 -> V_63 ) ;
if ( V_4 < 0 ||
V_4 >= V_68 ) {
F_10 ( V_73 L_3 ) ;
goto V_71;
}
F_43 ( V_4 , & V_3 -> V_12 . V_67 ) ;
if ( ! F_21 ( V_3 ) )
goto V_71;
F_44 ( V_3 -> V_12 . V_13 , V_4 ) ;
#ifdef F_2
F_45 ( F_3 ( V_3 ) , V_4 ) ;
#endif
V_71:
F_35 ( & V_3 -> V_63 ) ;
}
void F_46 ( struct V_3 * V_3 , int V_15 ,
struct V_74 * V_75 )
{
F_33 ( & V_3 -> V_63 ) ;
V_75 -> V_15 = V_15 ;
F_34 ( & V_75 -> V_64 , & V_3 -> V_76 ) ;
F_35 ( & V_3 -> V_63 ) ;
}
void F_47 ( struct V_3 * V_3 , int V_15 ,
struct V_74 * V_75 )
{
F_33 ( & V_3 -> V_63 ) ;
F_48 ( & V_75 -> V_64 ) ;
F_35 ( & V_3 -> V_63 ) ;
F_38 () ;
}
void F_49 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 ,
bool V_77 )
{
struct V_74 * V_75 ;
struct V_54 * V_55 ;
int V_60 ;
F_24 () ;
V_60 = F_25 ( V_3 -> V_56 ) -> V_61 [ V_8 ] [ V_9 ] ;
if ( V_60 != - 1 )
F_31 (kimn, n, &kvm->mask_notifier_list, link)
if ( V_75 -> V_15 == V_60 )
V_75 -> V_78 ( V_75 , V_77 ) ;
F_27 () ;
}
void F_50 ( struct V_3 * V_3 )
{
F_51 ( V_3 -> V_56 ) ;
}
static int F_52 ( struct V_52 * V_79 ,
struct V_1 * V_2 ,
const struct V_80 * V_81 )
{
int V_23 = - V_46 ;
int V_82 ;
unsigned V_83 ;
struct V_1 * V_84 ;
struct V_54 * V_55 ;
F_26 (ei, n, &rt->map[ue->gsi], link)
if ( V_84 -> type == V_85 ||
V_81 -> type == V_85 ||
V_81 -> V_86 . V_8 . V_8 == V_84 -> V_8 . V_8 )
return V_23 ;
V_2 -> V_60 = V_81 -> V_60 ;
V_2 -> type = V_81 -> type ;
switch ( V_81 -> type ) {
case V_87 :
V_82 = 0 ;
switch ( V_81 -> V_86 . V_8 . V_8 ) {
case V_88 :
V_2 -> F_28 = F_1 ;
V_83 = V_89 ;
break;
case V_90 :
V_2 -> F_28 = F_1 ;
V_83 = V_89 ;
V_82 = 8 ;
break;
case V_91 :
V_83 = V_92 ;
V_2 -> F_28 = F_5 ;
break;
default:
goto V_93;
}
V_2 -> V_8 . V_8 = V_81 -> V_86 . V_8 . V_8 ;
V_2 -> V_8 . V_9 = V_81 -> V_86 . V_8 . V_9 + V_82 ;
if ( V_2 -> V_8 . V_9 >= V_83 )
goto V_93;
V_79 -> V_61 [ V_81 -> V_86 . V_8 . V_8 ] [ V_2 -> V_8 . V_9 ] = V_81 -> V_60 ;
break;
case V_85 :
V_2 -> F_28 = F_18 ;
V_2 -> V_32 . V_33 = V_81 -> V_86 . V_32 . V_33 ;
V_2 -> V_32 . V_47 = V_81 -> V_86 . V_32 . V_47 ;
V_2 -> V_32 . V_34 = V_81 -> V_86 . V_32 . V_34 ;
break;
default:
goto V_93;
}
F_53 ( & V_2 -> V_64 , & V_79 -> V_94 [ V_2 -> V_60 ] ) ;
V_23 = 0 ;
V_93:
return V_23 ;
}
int F_54 ( struct V_3 * V_3 ,
const struct V_80 * V_81 ,
unsigned V_95 ,
unsigned V_45 )
{
struct V_52 * V_96 , * V_97 ;
T_1 V_22 , V_98 , V_57 = 0 ;
int V_23 ;
for ( V_22 = 0 ; V_22 < V_95 ; ++ V_22 ) {
if ( V_81 [ V_22 ] . V_60 >= V_99 )
return - V_46 ;
V_57 = F_55 ( V_57 , V_81 [ V_22 ] . V_60 ) ;
}
V_57 += 1 ;
V_96 = F_56 ( sizeof( * V_96 ) + ( V_57 * sizeof( struct V_100 ) )
+ ( V_95 * sizeof( struct V_1 ) ) ,
V_101 ) ;
if ( ! V_96 )
return - V_102 ;
V_96 -> V_103 = ( void * ) & V_96 -> V_94 [ V_57 ] ;
V_96 -> V_57 = V_57 ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
for ( V_98 = 0 ; V_98 < V_92 ; V_98 ++ )
V_96 -> V_61 [ V_22 ] [ V_98 ] = - 1 ;
for ( V_22 = 0 ; V_22 < V_95 ; ++ V_22 ) {
V_23 = - V_46 ;
if ( V_81 -> V_45 )
goto V_93;
V_23 = F_52 ( V_96 , & V_96 -> V_103 [ V_22 ] , V_81 ) ;
if ( V_23 )
goto V_93;
++ V_81 ;
}
F_33 ( & V_3 -> V_63 ) ;
V_97 = V_3 -> V_56 ;
F_57 ( V_3 , V_96 ) ;
F_35 ( & V_3 -> V_63 ) ;
F_38 () ;
V_96 = V_97 ;
V_23 = 0 ;
V_93:
F_51 ( V_96 ) ;
return V_23 ;
}
int F_58 ( struct V_3 * V_3 )
{
return F_54 ( V_3 , V_104 ,
F_59 ( V_104 ) , 0 ) ;
}
