static inline int F_1 ( unsigned long * V_1 ,
int V_2 , int V_3 )
{
if ( V_3 )
F_2 ( V_2 , V_1 ) ;
else
F_3 ( V_2 , V_1 ) ;
return ! ! ( * V_1 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
struct V_6 * V_6 , int V_2 , int V_3 )
{
#ifdef F_5
struct V_7 * V_8 = F_6 ( V_6 ) ;
V_3 = F_1 ( & V_8 -> V_9 [ V_5 -> V_10 . V_11 ] ,
V_2 , V_3 ) ;
return F_7 ( V_8 , V_5 -> V_10 . V_11 , V_3 ) ;
#else
return - 1 ;
#endif
}
static int F_8 ( struct V_4 * V_5 ,
struct V_6 * V_6 , int V_2 , int V_3 )
{
struct V_12 * V_13 = V_6 -> V_14 . V_15 ;
V_3 = F_1 ( & V_13 -> V_9 [ V_5 -> V_10 . V_11 ] ,
V_2 , V_3 ) ;
return F_9 ( V_13 , V_5 -> V_10 . V_11 , V_3 ) ;
}
inline static bool F_10 ( struct V_16 * V_17 )
{
#ifdef F_11
return V_17 -> V_18 ==
( V_19 << V_20 ) ;
#else
return V_17 -> V_18 == V_21 ;
#endif
}
int F_12 ( struct V_6 * V_6 , struct V_22 * V_23 ,
struct V_16 * V_17 )
{
int V_24 , V_25 = - 1 ;
struct V_26 * V_27 , * V_28 = NULL ;
if ( V_17 -> V_29 == 0 && V_17 -> V_30 == 0xff &&
F_10 ( V_17 ) )
F_13 ( V_31 L_1 ) ;
F_14 (i, vcpu, kvm) {
if ( ! F_15 ( V_27 ) )
continue;
if ( ! F_16 ( V_27 , V_23 , V_17 -> V_32 ,
V_17 -> V_30 , V_17 -> V_29 ) )
continue;
if ( ! F_10 ( V_17 ) ) {
if ( V_25 < 0 )
V_25 = 0 ;
V_25 += F_17 ( V_27 , V_17 ) ;
} else if ( F_18 ( V_27 ) ) {
if ( ! V_28 )
V_28 = V_27 ;
else if ( F_19 ( V_27 , V_28 ) < 0 )
V_28 = V_27 ;
}
}
if ( V_28 )
V_25 = F_17 ( V_28 , V_17 ) ;
return V_25 ;
}
int F_20 ( struct V_4 * V_5 ,
struct V_6 * V_6 , int V_2 , int V_3 )
{
struct V_16 V_17 ;
if ( ! V_3 )
return - 1 ;
F_21 ( V_5 -> V_33 . V_34 , V_5 -> V_33 . V_35 ) ;
V_17 . V_30 = ( V_5 -> V_33 . V_34 &
V_36 ) >> V_37 ;
V_17 . V_38 = ( V_5 -> V_33 . V_35 &
V_39 ) >> V_40 ;
V_17 . V_29 = ( 1 << V_41 ) & V_5 -> V_33 . V_34 ;
V_17 . V_42 = ( 1 << V_43 ) & V_5 -> V_33 . V_35 ;
V_17 . V_18 = V_5 -> V_33 . V_35 & 0x700 ;
V_17 . V_3 = 1 ;
V_17 . V_32 = 0 ;
return F_12 ( V_6 , NULL , & V_17 ) ;
}
int F_22 ( struct V_6 * V_6 , int V_2 , T_1 V_17 , int V_3 )
{
struct V_4 * V_5 , V_44 [ V_45 ] ;
int V_46 = - 1 , V_24 = 0 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
F_23 ( V_17 , V_3 , V_2 ) ;
F_24 () ;
V_48 = F_25 ( V_6 -> V_51 ) ;
if ( V_17 < V_48 -> V_52 )
F_26 (e, n, &irq_rt->map[irq], link)
V_44 [ V_24 ++ ] = * V_5 ;
F_27 () ;
while( V_24 -- ) {
int V_25 ;
V_25 = V_44 [ V_24 ] . F_28 ( & V_44 [ V_24 ] , V_6 , V_2 , V_3 ) ;
if ( V_25 < 0 )
continue;
V_46 = V_25 + ( ( V_46 < 0 ) ? 0 : V_46 ) ;
}
return V_46 ;
}
void F_29 ( struct V_6 * V_6 , unsigned V_10 , unsigned V_11 )
{
struct V_53 * V_54 ;
struct V_49 * V_50 ;
int V_55 ;
F_30 ( V_10 , V_11 ) ;
F_24 () ;
V_55 = F_25 ( V_6 -> V_51 ) -> V_56 [ V_10 ] [ V_11 ] ;
if ( V_55 != - 1 )
F_31 (kian, n, &kvm->irq_ack_notifier_list,
link)
if ( V_54 -> V_55 == V_55 )
V_54 -> V_57 ( V_54 ) ;
F_27 () ;
}
void F_32 ( struct V_6 * V_6 ,
struct V_53 * V_54 )
{
F_33 ( & V_6 -> V_58 ) ;
F_34 ( & V_54 -> V_59 , & V_6 -> V_60 ) ;
F_35 ( & V_6 -> V_58 ) ;
}
void F_36 ( struct V_6 * V_6 ,
struct V_53 * V_54 )
{
F_33 ( & V_6 -> V_58 ) ;
F_37 ( & V_54 -> V_59 ) ;
F_35 ( & V_6 -> V_58 ) ;
F_38 () ;
}
int F_39 ( struct V_6 * V_6 )
{
unsigned long * V_61 = & V_6 -> V_14 . V_62 ;
int V_2 ;
F_33 ( & V_6 -> V_58 ) ;
V_2 = F_40 ( V_61 , V_63 ) ;
if ( V_2 >= V_63 ) {
F_13 ( V_64 L_2 ) ;
V_2 = - V_65 ;
goto V_66;
}
ASSERT ( V_2 != V_67 ) ;
F_2 ( V_2 , V_61 ) ;
V_66:
F_35 ( & V_6 -> V_58 ) ;
return V_2 ;
}
void F_41 ( struct V_6 * V_6 , int V_2 )
{
int V_24 ;
ASSERT ( V_2 != V_67 ) ;
F_33 ( & V_6 -> V_58 ) ;
if ( V_2 < 0 ||
V_2 >= V_63 ) {
F_13 ( V_68 L_3 ) ;
goto V_66;
}
F_3 ( V_2 , & V_6 -> V_14 . V_62 ) ;
if ( ! F_42 ( V_6 ) )
goto V_66;
for ( V_24 = 0 ; V_24 < V_69 ; V_24 ++ ) {
F_3 ( V_2 , & V_6 -> V_14 . V_15 -> V_9 [ V_24 ] ) ;
if ( V_24 >= 16 )
continue;
#ifdef F_5
F_3 ( V_2 , & F_6 ( V_6 ) -> V_9 [ V_24 ] ) ;
#endif
}
V_66:
F_35 ( & V_6 -> V_58 ) ;
}
void F_43 ( struct V_6 * V_6 , int V_17 ,
struct V_70 * V_71 )
{
F_33 ( & V_6 -> V_58 ) ;
V_71 -> V_17 = V_17 ;
F_34 ( & V_71 -> V_59 , & V_6 -> V_72 ) ;
F_35 ( & V_6 -> V_58 ) ;
}
void F_44 ( struct V_6 * V_6 , int V_17 ,
struct V_70 * V_71 )
{
F_33 ( & V_6 -> V_58 ) ;
F_45 ( & V_71 -> V_59 ) ;
F_35 ( & V_6 -> V_58 ) ;
F_38 () ;
}
void F_46 ( struct V_6 * V_6 , unsigned V_10 , unsigned V_11 ,
bool V_73 )
{
struct V_70 * V_71 ;
struct V_49 * V_50 ;
int V_55 ;
F_24 () ;
V_55 = F_25 ( V_6 -> V_51 ) -> V_56 [ V_10 ] [ V_11 ] ;
if ( V_55 != - 1 )
F_31 (kimn, n, &kvm->mask_notifier_list, link)
if ( V_71 -> V_17 == V_55 )
V_71 -> V_74 ( V_71 , V_73 ) ;
F_27 () ;
}
void F_47 ( struct V_6 * V_6 )
{
F_48 ( V_6 -> V_51 ) ;
}
static int F_49 ( struct V_47 * V_75 ,
struct V_4 * V_5 ,
const struct V_76 * V_77 )
{
int V_25 = - V_78 ;
int V_79 ;
unsigned V_80 ;
struct V_4 * V_81 ;
struct V_49 * V_50 ;
F_26 (ei, n, &rt->map[ue->gsi], link)
if ( V_81 -> type == V_82 ||
V_77 -> V_83 . V_10 . V_10 == V_81 -> V_10 . V_10 )
return V_25 ;
V_5 -> V_55 = V_77 -> V_55 ;
V_5 -> type = V_77 -> type ;
switch ( V_77 -> type ) {
case V_84 :
V_79 = 0 ;
switch ( V_77 -> V_83 . V_10 . V_10 ) {
case V_85 :
V_5 -> F_28 = F_4 ;
V_80 = 16 ;
break;
case V_86 :
V_5 -> F_28 = F_4 ;
V_80 = 16 ;
V_79 = 8 ;
break;
case V_87 :
V_80 = V_69 ;
V_5 -> F_28 = F_8 ;
break;
default:
goto V_88;
}
V_5 -> V_10 . V_10 = V_77 -> V_83 . V_10 . V_10 ;
V_5 -> V_10 . V_11 = V_77 -> V_83 . V_10 . V_11 + V_79 ;
if ( V_5 -> V_10 . V_11 >= V_80 )
goto V_88;
V_75 -> V_56 [ V_77 -> V_83 . V_10 . V_10 ] [ V_5 -> V_10 . V_11 ] = V_77 -> V_55 ;
break;
case V_82 :
V_5 -> F_28 = F_20 ;
V_5 -> V_33 . V_34 = V_77 -> V_83 . V_33 . V_34 ;
V_5 -> V_33 . V_89 = V_77 -> V_83 . V_33 . V_89 ;
V_5 -> V_33 . V_35 = V_77 -> V_83 . V_33 . V_35 ;
break;
default:
goto V_88;
}
F_50 ( & V_5 -> V_59 , & V_75 -> V_90 [ V_5 -> V_55 ] ) ;
V_25 = 0 ;
V_88:
return V_25 ;
}
int F_51 ( struct V_6 * V_6 ,
const struct V_76 * V_77 ,
unsigned V_91 ,
unsigned V_92 )
{
struct V_47 * V_93 , * V_94 ;
T_1 V_24 , V_95 , V_52 = 0 ;
int V_25 ;
for ( V_24 = 0 ; V_24 < V_91 ; ++ V_24 ) {
if ( V_77 [ V_24 ] . V_55 >= V_96 )
return - V_78 ;
V_52 = F_52 ( V_52 , V_77 [ V_24 ] . V_55 ) ;
}
V_52 += 1 ;
V_93 = F_53 ( sizeof( * V_93 ) + ( V_52 * sizeof( struct V_97 ) )
+ ( V_91 * sizeof( struct V_4 ) ) ,
V_98 ) ;
if ( ! V_93 )
return - V_99 ;
V_93 -> V_100 = ( void * ) & V_93 -> V_90 [ V_52 ] ;
V_93 -> V_52 = V_52 ;
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ )
for ( V_95 = 0 ; V_95 < V_69 ; V_95 ++ )
V_93 -> V_56 [ V_24 ] [ V_95 ] = - 1 ;
for ( V_24 = 0 ; V_24 < V_91 ; ++ V_24 ) {
V_25 = - V_78 ;
if ( V_77 -> V_92 )
goto V_88;
V_25 = F_49 ( V_93 , & V_93 -> V_100 [ V_24 ] , V_77 ) ;
if ( V_25 )
goto V_88;
++ V_77 ;
}
F_33 ( & V_6 -> V_58 ) ;
V_94 = V_6 -> V_51 ;
F_54 ( V_6 , V_93 ) ;
F_35 ( & V_6 -> V_58 ) ;
F_38 () ;
V_93 = V_94 ;
V_25 = 0 ;
V_88:
F_48 ( V_93 ) ;
return V_25 ;
}
int F_55 ( struct V_6 * V_6 )
{
return F_51 ( V_6 , V_101 ,
F_56 ( V_101 ) , 0 ) ;
}
