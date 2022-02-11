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
F_7 ( V_15 ) )
F_10 ( V_29 L_1 ) ;
F_11 (i, vcpu, kvm) {
if ( ! F_12 ( V_25 ) )
continue;
if ( ! F_13 ( V_25 , V_21 , V_15 -> V_30 ,
V_15 -> V_28 , V_15 -> V_27 ) )
continue;
if ( ! F_7 ( V_15 ) ) {
if ( V_23 < 0 )
V_23 = 0 ;
V_23 += F_14 ( V_25 , V_15 ) ;
} else if ( F_15 ( V_25 ) ) {
if ( ! V_26 )
V_26 = V_25 ;
else if ( F_16 ( V_25 , V_26 ) < 0 )
V_26 = V_25 ;
}
}
if ( V_26 )
V_23 = F_14 ( V_26 , V_15 ) ;
return V_23 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 , int V_5 )
{
struct V_14 V_15 ;
if ( ! V_5 )
return - 1 ;
F_18 ( V_2 -> V_31 . V_32 , V_2 -> V_31 . V_33 ) ;
V_15 . V_28 = ( V_2 -> V_31 . V_32 &
V_34 ) >> V_35 ;
V_15 . V_36 = ( V_2 -> V_31 . V_33 &
V_37 ) >> V_38 ;
V_15 . V_27 = ( 1 << V_39 ) & V_2 -> V_31 . V_32 ;
V_15 . V_40 = ( 1 << V_41 ) & V_2 -> V_31 . V_33 ;
V_15 . V_16 = V_2 -> V_31 . V_33 & 0x700 ;
V_15 . V_5 = 1 ;
V_15 . V_30 = 0 ;
return F_9 ( V_3 , NULL , & V_15 ) ;
}
int F_19 ( struct V_3 * V_3 , struct V_42 * V_31 )
{
struct V_1 V_43 ;
if ( ! F_20 ( V_3 ) || V_31 -> V_44 != 0 )
return - V_45 ;
V_43 . V_31 . V_32 = V_31 -> V_32 ;
V_43 . V_31 . V_46 = V_31 -> V_46 ;
V_43 . V_31 . V_33 = V_31 -> V_33 ;
return F_17 ( & V_43 , V_3 , V_47 , 1 ) ;
}
int F_21 ( struct V_3 * V_3 , int V_4 , T_1 V_15 , int V_5 )
{
struct V_1 * V_2 , V_48 [ V_49 ] ;
int V_50 = - 1 , V_22 = 0 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
F_22 ( V_15 , V_5 , V_4 ) ;
F_23 () ;
V_52 = F_24 ( V_3 -> V_55 ) ;
if ( V_15 < V_52 -> V_56 )
F_25 (e, n, &irq_rt->map[irq], link)
V_48 [ V_22 ++ ] = * V_2 ;
F_26 () ;
while( V_22 -- ) {
int V_23 ;
V_23 = V_48 [ V_22 ] . F_27 ( & V_48 [ V_22 ] , V_3 , V_4 , V_5 ) ;
if ( V_23 < 0 )
continue;
V_50 = V_23 + ( ( V_50 < 0 ) ? 0 : V_50 ) ;
}
return V_50 ;
}
void F_28 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 )
{
struct V_57 * V_58 ;
struct V_53 * V_54 ;
int V_59 ;
F_29 ( V_8 , V_9 ) ;
F_23 () ;
V_59 = F_24 ( V_3 -> V_55 ) -> V_60 [ V_8 ] [ V_9 ] ;
if ( V_59 != - 1 )
F_30 (kian, n, &kvm->irq_ack_notifier_list,
link)
if ( V_58 -> V_59 == V_59 )
V_58 -> V_61 ( V_58 ) ;
F_26 () ;
}
void F_31 ( struct V_3 * V_3 ,
struct V_57 * V_58 )
{
F_32 ( & V_3 -> V_62 ) ;
F_33 ( & V_58 -> V_63 , & V_3 -> V_64 ) ;
F_34 ( & V_3 -> V_62 ) ;
}
void F_35 ( struct V_3 * V_3 ,
struct V_57 * V_58 )
{
F_32 ( & V_3 -> V_62 ) ;
F_36 ( & V_58 -> V_63 ) ;
F_34 ( & V_3 -> V_62 ) ;
F_37 () ;
}
int F_38 ( struct V_3 * V_3 )
{
unsigned long * V_65 = & V_3 -> V_12 . V_66 ;
int V_4 ;
F_32 ( & V_3 -> V_62 ) ;
V_4 = F_39 ( V_65 , V_67 ) ;
if ( V_4 >= V_67 ) {
F_10 ( V_68 L_2 ) ;
V_4 = - V_69 ;
goto V_70;
}
ASSERT ( V_4 != V_47 ) ;
F_40 ( V_4 , V_65 ) ;
V_70:
F_34 ( & V_3 -> V_62 ) ;
return V_4 ;
}
void F_41 ( struct V_3 * V_3 , int V_4 )
{
ASSERT ( V_4 != V_47 ) ;
F_32 ( & V_3 -> V_62 ) ;
if ( V_4 < 0 ||
V_4 >= V_67 ) {
F_10 ( V_71 L_3 ) ;
goto V_70;
}
F_42 ( V_4 , & V_3 -> V_12 . V_66 ) ;
if ( ! F_20 ( V_3 ) )
goto V_70;
F_43 ( V_3 -> V_12 . V_13 , V_4 ) ;
#ifdef F_2
F_44 ( F_3 ( V_3 ) , V_4 ) ;
#endif
V_70:
F_34 ( & V_3 -> V_62 ) ;
}
void F_45 ( struct V_3 * V_3 , int V_15 ,
struct V_72 * V_73 )
{
F_32 ( & V_3 -> V_62 ) ;
V_73 -> V_15 = V_15 ;
F_33 ( & V_73 -> V_63 , & V_3 -> V_74 ) ;
F_34 ( & V_3 -> V_62 ) ;
}
void F_46 ( struct V_3 * V_3 , int V_15 ,
struct V_72 * V_73 )
{
F_32 ( & V_3 -> V_62 ) ;
F_47 ( & V_73 -> V_63 ) ;
F_34 ( & V_3 -> V_62 ) ;
F_37 () ;
}
void F_48 ( struct V_3 * V_3 , unsigned V_8 , unsigned V_9 ,
bool V_75 )
{
struct V_72 * V_73 ;
struct V_53 * V_54 ;
int V_59 ;
F_23 () ;
V_59 = F_24 ( V_3 -> V_55 ) -> V_60 [ V_8 ] [ V_9 ] ;
if ( V_59 != - 1 )
F_30 (kimn, n, &kvm->mask_notifier_list, link)
if ( V_73 -> V_15 == V_59 )
V_73 -> V_76 ( V_73 , V_75 ) ;
F_26 () ;
}
void F_49 ( struct V_3 * V_3 )
{
F_50 ( V_3 -> V_55 ) ;
}
static int F_51 ( struct V_51 * V_77 ,
struct V_1 * V_2 ,
const struct V_78 * V_79 )
{
int V_23 = - V_45 ;
int V_80 ;
unsigned V_81 ;
struct V_1 * V_82 ;
struct V_53 * V_54 ;
F_25 (ei, n, &rt->map[ue->gsi], link)
if ( V_82 -> type == V_83 ||
V_79 -> type == V_83 ||
V_79 -> V_84 . V_8 . V_8 == V_82 -> V_8 . V_8 )
return V_23 ;
V_2 -> V_59 = V_79 -> V_59 ;
V_2 -> type = V_79 -> type ;
switch ( V_79 -> type ) {
case V_85 :
V_80 = 0 ;
switch ( V_79 -> V_84 . V_8 . V_8 ) {
case V_86 :
V_2 -> F_27 = F_1 ;
V_81 = 16 ;
break;
case V_87 :
V_2 -> F_27 = F_1 ;
V_81 = 16 ;
V_80 = 8 ;
break;
case V_88 :
V_81 = V_89 ;
V_2 -> F_27 = F_5 ;
break;
default:
goto V_90;
}
V_2 -> V_8 . V_8 = V_79 -> V_84 . V_8 . V_8 ;
V_2 -> V_8 . V_9 = V_79 -> V_84 . V_8 . V_9 + V_80 ;
if ( V_2 -> V_8 . V_9 >= V_81 )
goto V_90;
V_77 -> V_60 [ V_79 -> V_84 . V_8 . V_8 ] [ V_2 -> V_8 . V_9 ] = V_79 -> V_59 ;
break;
case V_83 :
V_2 -> F_27 = F_17 ;
V_2 -> V_31 . V_32 = V_79 -> V_84 . V_31 . V_32 ;
V_2 -> V_31 . V_46 = V_79 -> V_84 . V_31 . V_46 ;
V_2 -> V_31 . V_33 = V_79 -> V_84 . V_31 . V_33 ;
break;
default:
goto V_90;
}
F_52 ( & V_2 -> V_63 , & V_77 -> V_91 [ V_2 -> V_59 ] ) ;
V_23 = 0 ;
V_90:
return V_23 ;
}
int F_53 ( struct V_3 * V_3 ,
const struct V_78 * V_79 ,
unsigned V_92 ,
unsigned V_44 )
{
struct V_51 * V_93 , * V_94 ;
T_1 V_22 , V_95 , V_56 = 0 ;
int V_23 ;
for ( V_22 = 0 ; V_22 < V_92 ; ++ V_22 ) {
if ( V_79 [ V_22 ] . V_59 >= V_96 )
return - V_45 ;
V_56 = F_54 ( V_56 , V_79 [ V_22 ] . V_59 ) ;
}
V_56 += 1 ;
V_93 = F_55 ( sizeof( * V_93 ) + ( V_56 * sizeof( struct V_97 ) )
+ ( V_92 * sizeof( struct V_1 ) ) ,
V_98 ) ;
if ( ! V_93 )
return - V_99 ;
V_93 -> V_100 = ( void * ) & V_93 -> V_91 [ V_56 ] ;
V_93 -> V_56 = V_56 ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ )
for ( V_95 = 0 ; V_95 < V_89 ; V_95 ++ )
V_93 -> V_60 [ V_22 ] [ V_95 ] = - 1 ;
for ( V_22 = 0 ; V_22 < V_92 ; ++ V_22 ) {
V_23 = - V_45 ;
if ( V_79 -> V_44 )
goto V_90;
V_23 = F_51 ( V_93 , & V_93 -> V_100 [ V_22 ] , V_79 ) ;
if ( V_23 )
goto V_90;
++ V_79 ;
}
F_32 ( & V_3 -> V_62 ) ;
V_94 = V_3 -> V_55 ;
F_56 ( V_3 , V_93 ) ;
F_34 ( & V_3 -> V_62 ) ;
F_37 () ;
V_93 = V_94 ;
V_23 = 0 ;
V_90:
F_50 ( V_93 ) ;
return V_23 ;
}
int F_57 ( struct V_3 * V_3 )
{
return F_53 ( V_3 , V_101 ,
F_58 ( V_101 ) , 0 ) ;
}
