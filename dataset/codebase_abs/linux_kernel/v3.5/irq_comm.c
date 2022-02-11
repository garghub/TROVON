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
int F_22 ( struct V_6 * V_6 , struct V_44 * V_33 )
{
struct V_4 V_45 ;
if ( ! F_23 ( V_6 ) || V_33 -> V_46 != 0 )
return - V_47 ;
V_45 . V_33 . V_34 = V_33 -> V_34 ;
V_45 . V_33 . V_48 = V_33 -> V_48 ;
V_45 . V_33 . V_35 = V_33 -> V_35 ;
return F_20 ( & V_45 , V_6 , V_49 , 1 ) ;
}
int F_24 ( struct V_6 * V_6 , int V_2 , T_1 V_17 , int V_3 )
{
struct V_4 * V_5 , V_50 [ V_51 ] ;
int V_52 = - 1 , V_24 = 0 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
F_25 ( V_17 , V_3 , V_2 ) ;
F_26 () ;
V_54 = F_27 ( V_6 -> V_57 ) ;
if ( V_17 < V_54 -> V_58 )
F_28 (e, n, &irq_rt->map[irq], link)
V_50 [ V_24 ++ ] = * V_5 ;
F_29 () ;
while( V_24 -- ) {
int V_25 ;
V_25 = V_50 [ V_24 ] . F_30 ( & V_50 [ V_24 ] , V_6 , V_2 , V_3 ) ;
if ( V_25 < 0 )
continue;
V_52 = V_25 + ( ( V_52 < 0 ) ? 0 : V_52 ) ;
}
return V_52 ;
}
void F_31 ( struct V_6 * V_6 , unsigned V_10 , unsigned V_11 )
{
struct V_59 * V_60 ;
struct V_55 * V_56 ;
int V_61 ;
F_32 ( V_10 , V_11 ) ;
F_26 () ;
V_61 = F_27 ( V_6 -> V_57 ) -> V_62 [ V_10 ] [ V_11 ] ;
if ( V_61 != - 1 )
F_33 (kian, n, &kvm->irq_ack_notifier_list,
link)
if ( V_60 -> V_61 == V_61 )
V_60 -> V_63 ( V_60 ) ;
F_29 () ;
}
void F_34 ( struct V_6 * V_6 ,
struct V_59 * V_60 )
{
F_35 ( & V_6 -> V_64 ) ;
F_36 ( & V_60 -> V_65 , & V_6 -> V_66 ) ;
F_37 ( & V_6 -> V_64 ) ;
}
void F_38 ( struct V_6 * V_6 ,
struct V_59 * V_60 )
{
F_35 ( & V_6 -> V_64 ) ;
F_39 ( & V_60 -> V_65 ) ;
F_37 ( & V_6 -> V_64 ) ;
F_40 () ;
}
int F_41 ( struct V_6 * V_6 )
{
unsigned long * V_67 = & V_6 -> V_14 . V_68 ;
int V_2 ;
F_35 ( & V_6 -> V_64 ) ;
V_2 = F_42 ( V_67 , V_69 ) ;
if ( V_2 >= V_69 ) {
F_13 ( V_70 L_2 ) ;
V_2 = - V_71 ;
goto V_72;
}
ASSERT ( V_2 != V_49 ) ;
F_2 ( V_2 , V_67 ) ;
V_72:
F_37 ( & V_6 -> V_64 ) ;
return V_2 ;
}
void F_43 ( struct V_6 * V_6 , int V_2 )
{
int V_24 ;
ASSERT ( V_2 != V_49 ) ;
F_35 ( & V_6 -> V_64 ) ;
if ( V_2 < 0 ||
V_2 >= V_69 ) {
F_13 ( V_73 L_3 ) ;
goto V_72;
}
F_3 ( V_2 , & V_6 -> V_14 . V_68 ) ;
if ( ! F_23 ( V_6 ) )
goto V_72;
for ( V_24 = 0 ; V_24 < V_74 ; V_24 ++ ) {
F_3 ( V_2 , & V_6 -> V_14 . V_15 -> V_9 [ V_24 ] ) ;
if ( V_24 >= 16 )
continue;
#ifdef F_5
F_3 ( V_2 , & F_6 ( V_6 ) -> V_9 [ V_24 ] ) ;
#endif
}
V_72:
F_37 ( & V_6 -> V_64 ) ;
}
void F_44 ( struct V_6 * V_6 , int V_17 ,
struct V_75 * V_76 )
{
F_35 ( & V_6 -> V_64 ) ;
V_76 -> V_17 = V_17 ;
F_36 ( & V_76 -> V_65 , & V_6 -> V_77 ) ;
F_37 ( & V_6 -> V_64 ) ;
}
void F_45 ( struct V_6 * V_6 , int V_17 ,
struct V_75 * V_76 )
{
F_35 ( & V_6 -> V_64 ) ;
F_46 ( & V_76 -> V_65 ) ;
F_37 ( & V_6 -> V_64 ) ;
F_40 () ;
}
void F_47 ( struct V_6 * V_6 , unsigned V_10 , unsigned V_11 ,
bool V_78 )
{
struct V_75 * V_76 ;
struct V_55 * V_56 ;
int V_61 ;
F_26 () ;
V_61 = F_27 ( V_6 -> V_57 ) -> V_62 [ V_10 ] [ V_11 ] ;
if ( V_61 != - 1 )
F_33 (kimn, n, &kvm->mask_notifier_list, link)
if ( V_76 -> V_17 == V_61 )
V_76 -> V_79 ( V_76 , V_78 ) ;
F_29 () ;
}
void F_48 ( struct V_6 * V_6 )
{
F_49 ( V_6 -> V_57 ) ;
}
static int F_50 ( struct V_53 * V_80 ,
struct V_4 * V_5 ,
const struct V_81 * V_82 )
{
int V_25 = - V_47 ;
int V_83 ;
unsigned V_84 ;
struct V_4 * V_85 ;
struct V_55 * V_56 ;
F_28 (ei, n, &rt->map[ue->gsi], link)
if ( V_85 -> type == V_86 ||
V_82 -> type == V_86 ||
V_82 -> V_87 . V_10 . V_10 == V_85 -> V_10 . V_10 )
return V_25 ;
V_5 -> V_61 = V_82 -> V_61 ;
V_5 -> type = V_82 -> type ;
switch ( V_82 -> type ) {
case V_88 :
V_83 = 0 ;
switch ( V_82 -> V_87 . V_10 . V_10 ) {
case V_89 :
V_5 -> F_30 = F_4 ;
V_84 = 16 ;
break;
case V_90 :
V_5 -> F_30 = F_4 ;
V_84 = 16 ;
V_83 = 8 ;
break;
case V_91 :
V_84 = V_74 ;
V_5 -> F_30 = F_8 ;
break;
default:
goto V_92;
}
V_5 -> V_10 . V_10 = V_82 -> V_87 . V_10 . V_10 ;
V_5 -> V_10 . V_11 = V_82 -> V_87 . V_10 . V_11 + V_83 ;
if ( V_5 -> V_10 . V_11 >= V_84 )
goto V_92;
V_80 -> V_62 [ V_82 -> V_87 . V_10 . V_10 ] [ V_5 -> V_10 . V_11 ] = V_82 -> V_61 ;
break;
case V_86 :
V_5 -> F_30 = F_20 ;
V_5 -> V_33 . V_34 = V_82 -> V_87 . V_33 . V_34 ;
V_5 -> V_33 . V_48 = V_82 -> V_87 . V_33 . V_48 ;
V_5 -> V_33 . V_35 = V_82 -> V_87 . V_33 . V_35 ;
break;
default:
goto V_92;
}
F_51 ( & V_5 -> V_65 , & V_80 -> V_93 [ V_5 -> V_61 ] ) ;
V_25 = 0 ;
V_92:
return V_25 ;
}
int F_52 ( struct V_6 * V_6 ,
const struct V_81 * V_82 ,
unsigned V_94 ,
unsigned V_46 )
{
struct V_53 * V_95 , * V_96 ;
T_1 V_24 , V_97 , V_58 = 0 ;
int V_25 ;
for ( V_24 = 0 ; V_24 < V_94 ; ++ V_24 ) {
if ( V_82 [ V_24 ] . V_61 >= V_98 )
return - V_47 ;
V_58 = F_53 ( V_58 , V_82 [ V_24 ] . V_61 ) ;
}
V_58 += 1 ;
V_95 = F_54 ( sizeof( * V_95 ) + ( V_58 * sizeof( struct V_99 ) )
+ ( V_94 * sizeof( struct V_4 ) ) ,
V_100 ) ;
if ( ! V_95 )
return - V_101 ;
V_95 -> V_102 = ( void * ) & V_95 -> V_93 [ V_58 ] ;
V_95 -> V_58 = V_58 ;
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ )
for ( V_97 = 0 ; V_97 < V_74 ; V_97 ++ )
V_95 -> V_62 [ V_24 ] [ V_97 ] = - 1 ;
for ( V_24 = 0 ; V_24 < V_94 ; ++ V_24 ) {
V_25 = - V_47 ;
if ( V_82 -> V_46 )
goto V_92;
V_25 = F_50 ( V_95 , & V_95 -> V_102 [ V_24 ] , V_82 ) ;
if ( V_25 )
goto V_92;
++ V_82 ;
}
F_35 ( & V_6 -> V_64 ) ;
V_96 = V_6 -> V_57 ;
F_55 ( V_6 , V_95 ) ;
F_37 ( & V_6 -> V_64 ) ;
F_40 () ;
V_95 = V_96 ;
V_25 = 0 ;
V_92:
F_49 ( V_95 ) ;
return V_25 ;
}
int F_56 ( struct V_6 * V_6 )
{
return F_52 ( V_6 , V_103 ,
F_57 ( V_103 ) , 0 ) ;
}
