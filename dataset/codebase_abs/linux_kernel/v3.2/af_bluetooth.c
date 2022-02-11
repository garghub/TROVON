static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_2 * V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return;
F_2 ( F_3 ( V_4 ) ) ;
F_4 ( V_4 ,
V_5 [ V_3 ] , & V_6 [ V_3 ] ,
V_7 [ V_3 ] , & V_8 [ V_3 ] ) ;
}
int F_5 ( int V_3 , const struct V_9 * V_10 )
{
int V_11 = 0 ;
if ( V_3 < 0 || V_3 >= V_12 )
return - V_13 ;
F_6 ( & V_14 ) ;
if ( V_15 [ V_3 ] )
V_11 = - V_16 ;
else
V_15 [ V_3 ] = V_10 ;
F_7 ( & V_14 ) ;
return V_11 ;
}
int F_8 ( int V_3 )
{
int V_11 = 0 ;
if ( V_3 < 0 || V_3 >= V_12 )
return - V_13 ;
F_6 ( & V_14 ) ;
if ( ! V_15 [ V_3 ] )
V_11 = - V_17 ;
else
V_15 [ V_3 ] = NULL ;
F_7 ( & V_14 ) ;
return V_11 ;
}
static int F_9 ( struct V_18 * V_18 , struct V_1 * V_2 , int V_3 ,
int V_19 )
{
int V_11 ;
if ( V_18 != & V_20 )
return - V_21 ;
if ( V_3 < 0 || V_3 >= V_12 )
return - V_13 ;
if ( ! V_15 [ V_3 ] )
F_10 ( L_1 , V_3 ) ;
V_11 = - V_22 ;
F_11 ( & V_14 ) ;
if ( V_15 [ V_3 ] && F_12 ( V_15 [ V_3 ] -> V_23 ) ) {
V_11 = V_15 [ V_3 ] -> F_13 ( V_18 , V_2 , V_3 , V_19 ) ;
F_1 ( V_2 , V_3 ) ;
F_14 ( V_15 [ V_3 ] -> V_23 ) ;
}
F_15 ( & V_14 ) ;
return V_11 ;
}
void F_16 ( struct V_24 * V_25 , struct V_2 * V_4 )
{
F_17 ( & V_25 -> V_26 ) ;
F_18 ( V_4 , & V_25 -> V_27 ) ;
F_19 ( & V_25 -> V_26 ) ;
}
void F_20 ( struct V_24 * V_25 , struct V_2 * V_4 )
{
F_17 ( & V_25 -> V_26 ) ;
F_21 ( V_4 ) ;
F_19 ( & V_25 -> V_26 ) ;
}
void F_22 ( struct V_2 * V_28 , struct V_2 * V_4 )
{
F_23 ( L_2 , V_28 , V_4 ) ;
F_24 ( V_4 ) ;
F_25 ( & F_26 ( V_4 ) -> V_29 , & F_26 ( V_28 ) -> V_29 ) ;
F_26 ( V_4 ) -> V_28 = V_28 ;
V_28 -> V_30 ++ ;
}
void F_27 ( struct V_2 * V_4 )
{
F_23 ( L_3 , V_4 , V_4 -> V_31 ) ;
F_28 ( & F_26 ( V_4 ) -> V_29 ) ;
F_26 ( V_4 ) -> V_28 -> V_30 -- ;
F_26 ( V_4 ) -> V_28 = NULL ;
F_29 ( V_4 ) ;
}
struct V_2 * F_30 ( struct V_2 * V_28 , struct V_1 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
struct V_2 * V_4 ;
F_23 ( L_4 , V_28 ) ;
F_31 () ;
F_32 (p, n, &bt_sk(parent)->accept_q) {
V_4 = (struct V_2 * ) F_33 ( V_34 , struct V_36 , V_29 ) ;
F_34 ( V_4 ) ;
if ( V_4 -> V_31 == V_37 ) {
F_35 ( V_4 ) ;
F_27 ( V_4 ) ;
continue;
}
if ( V_4 -> V_31 == V_38 || ! V_32 ||
F_26 ( V_28 ) -> V_39 ) {
F_27 ( V_4 ) ;
if ( V_32 )
F_36 ( V_4 , V_32 ) ;
F_35 ( V_4 ) ;
F_37 () ;
return V_4 ;
}
F_35 ( V_4 ) ;
}
F_37 () ;
return NULL ;
}
int F_38 ( struct V_40 * V_41 , struct V_1 * V_2 ,
struct V_42 * V_43 , T_1 V_44 , int V_45 )
{
int V_46 = V_45 & V_47 ;
struct V_2 * V_4 = V_2 -> V_4 ;
struct V_48 * V_49 ;
T_1 V_50 ;
int V_11 ;
F_23 ( L_5 , V_2 , V_4 , V_44 ) ;
if ( V_45 & ( V_51 ) )
return - V_52 ;
V_49 = F_39 ( V_4 , V_45 , V_46 , & V_11 ) ;
if ( ! V_49 ) {
if ( V_4 -> V_53 & V_54 )
return 0 ;
return V_11 ;
}
V_43 -> V_55 = 0 ;
V_50 = V_49 -> V_44 ;
if ( V_44 < V_50 ) {
V_43 -> V_56 |= V_57 ;
V_50 = V_44 ;
}
F_40 ( V_49 ) ;
V_11 = F_41 ( V_49 , 0 , V_43 -> V_58 , V_50 ) ;
if ( V_11 == 0 )
F_42 ( V_43 , V_4 , V_49 ) ;
F_43 ( V_4 , V_49 ) ;
return V_11 ? : V_50 ;
}
static long F_44 ( struct V_2 * V_4 , long V_59 )
{
F_45 ( V_60 , V_61 ) ;
F_46 ( F_47 ( V_4 ) , & V_60 ) ;
for (; ; ) {
F_48 ( V_62 ) ;
if ( ! F_49 ( & V_4 -> V_63 ) )
break;
if ( V_4 -> V_64 || ( V_4 -> V_53 & V_54 ) )
break;
if ( F_50 ( V_61 ) || ! V_59 )
break;
F_51 ( V_65 , & V_4 -> V_66 -> V_45 ) ;
F_52 ( V_4 ) ;
V_59 = F_53 ( V_59 ) ;
F_54 ( V_4 ) ;
F_55 ( V_65 , & V_4 -> V_66 -> V_45 ) ;
}
F_56 ( V_67 ) ;
F_57 ( F_47 ( V_4 ) , & V_60 ) ;
return V_59 ;
}
int F_58 ( struct V_40 * V_41 , struct V_1 * V_2 ,
struct V_42 * V_43 , T_1 V_68 , int V_45 )
{
struct V_2 * V_4 = V_2 -> V_4 ;
int V_11 = 0 ;
T_1 V_69 , V_50 = 0 ;
long V_59 ;
if ( V_45 & V_51 )
return - V_52 ;
V_43 -> V_55 = 0 ;
F_23 ( L_6 , V_4 , V_68 ) ;
F_54 ( V_4 ) ;
V_69 = F_59 ( V_4 , V_45 & V_70 , V_68 ) ;
V_59 = F_60 ( V_4 , V_45 & V_47 ) ;
do {
struct V_48 * V_49 ;
int V_71 ;
V_49 = F_61 ( & V_4 -> V_63 ) ;
if ( ! V_49 ) {
if ( V_50 >= V_69 )
break;
V_11 = F_62 ( V_4 ) ;
if ( V_11 )
break;
if ( V_4 -> V_53 & V_54 )
break;
V_11 = - V_72 ;
if ( ! V_59 )
break;
V_59 = F_44 ( V_4 , V_59 ) ;
if ( F_50 ( V_61 ) ) {
V_11 = F_63 ( V_59 ) ;
goto V_73;
}
continue;
}
V_71 = F_64 (unsigned int, skb->len, size) ;
if ( F_41 ( V_49 , 0 , V_43 -> V_58 , V_71 ) ) {
F_65 ( & V_4 -> V_63 , V_49 ) ;
if ( ! V_50 )
V_50 = - V_74 ;
break;
}
V_50 += V_71 ;
V_68 -= V_71 ;
F_42 ( V_43 , V_4 , V_49 ) ;
if ( ! ( V_45 & V_75 ) ) {
int V_76 = F_66 ( V_49 ) ;
if ( V_71 <= V_76 ) {
F_67 ( V_49 , V_71 ) ;
} else {
struct V_48 * V_77 ;
F_67 ( V_49 , V_76 ) ;
V_71 -= V_76 ;
F_68 (skb, frag) {
if ( V_71 <= V_77 -> V_44 ) {
V_49 -> V_44 -= V_71 ;
V_49 -> V_78 -= V_71 ;
F_67 ( V_77 , V_71 ) ;
break;
} else if ( V_77 -> V_44 ) {
V_71 -= V_77 -> V_44 ;
V_49 -> V_44 -= V_77 -> V_44 ;
V_49 -> V_78 -= V_77 -> V_44 ;
F_67 ( V_77 , V_77 -> V_44 ) ;
}
}
}
if ( V_49 -> V_44 ) {
F_65 ( & V_4 -> V_63 , V_49 ) ;
break;
}
F_69 ( V_49 ) ;
} else {
F_65 ( & V_4 -> V_63 , V_49 ) ;
break;
}
} while ( V_68 );
V_73:
F_52 ( V_4 ) ;
return V_50 ? : V_11 ;
}
static inline unsigned int F_70 ( struct V_2 * V_28 )
{
struct V_33 * V_34 , * V_35 ;
struct V_2 * V_4 ;
F_32 (p, n, &bt_sk(parent)->accept_q) {
V_4 = (struct V_2 * ) F_33 ( V_34 , struct V_36 , V_29 ) ;
if ( V_4 -> V_31 == V_38 ||
( F_26 ( V_28 ) -> V_39 &&
V_4 -> V_31 == V_79 ) )
return V_80 | V_81 ;
}
return 0 ;
}
unsigned int F_71 ( struct V_82 * V_82 , struct V_1 * V_2 , T_2 * V_60 )
{
struct V_2 * V_4 = V_2 -> V_4 ;
unsigned int V_83 = 0 ;
F_23 ( L_7 , V_2 , V_4 ) ;
F_72 ( V_82 , F_47 ( V_4 ) , V_60 ) ;
if ( V_4 -> V_31 == V_84 )
return F_70 ( V_4 ) ;
if ( V_4 -> V_64 || ! F_49 ( & V_4 -> V_85 ) )
V_83 |= V_86 ;
if ( V_4 -> V_53 & V_54 )
V_83 |= V_87 | V_80 | V_81 ;
if ( V_4 -> V_53 == V_88 )
V_83 |= V_89 ;
if ( ! F_49 ( & V_4 -> V_63 ) )
V_83 |= V_80 | V_81 ;
if ( V_4 -> V_31 == V_37 )
V_83 |= V_89 ;
if ( V_4 -> V_31 == V_90 ||
V_4 -> V_31 == V_79 ||
V_4 -> V_31 == V_91 )
return V_83 ;
if ( F_73 ( V_4 ) )
V_83 |= V_92 | V_93 | V_94 ;
else
F_51 ( V_95 , & V_4 -> V_66 -> V_45 ) ;
return V_83 ;
}
int F_74 ( struct V_1 * V_2 , unsigned int V_96 , unsigned long V_97 )
{
struct V_2 * V_4 = V_2 -> V_4 ;
struct V_48 * V_49 ;
long V_98 ;
int V_11 ;
F_23 ( L_8 , V_4 , V_96 , V_97 ) ;
switch ( V_96 ) {
case V_99 :
if ( V_4 -> V_31 == V_84 )
return - V_13 ;
V_98 = V_4 -> V_100 - F_75 ( V_4 ) ;
if ( V_98 < 0 )
V_98 = 0 ;
V_11 = F_76 ( V_98 , ( int V_101 * ) V_97 ) ;
break;
case V_102 :
if ( V_4 -> V_31 == V_84 )
return - V_13 ;
F_54 ( V_4 ) ;
V_49 = F_77 ( & V_4 -> V_63 ) ;
V_98 = V_49 ? V_49 -> V_44 : 0 ;
F_52 ( V_4 ) ;
V_11 = F_76 ( V_98 , ( int V_101 * ) V_97 ) ;
break;
case V_103 :
V_11 = F_78 ( V_4 , (struct V_104 V_101 * ) V_97 ) ;
break;
case V_105 :
V_11 = F_79 ( V_4 , (struct V_106 V_101 * ) V_97 ) ;
break;
default:
V_11 = - V_107 ;
break;
}
return V_11 ;
}
int F_80 ( struct V_2 * V_4 , int V_108 , unsigned long V_59 )
{
F_45 ( V_60 , V_61 ) ;
int V_11 = 0 ;
F_23 ( L_9 , V_4 ) ;
F_46 ( F_47 ( V_4 ) , & V_60 ) ;
F_48 ( V_62 ) ;
while ( V_4 -> V_31 != V_108 ) {
if ( ! V_59 ) {
V_11 = - V_109 ;
break;
}
if ( F_50 ( V_61 ) ) {
V_11 = F_63 ( V_59 ) ;
break;
}
F_52 ( V_4 ) ;
V_59 = F_53 ( V_59 ) ;
F_54 ( V_4 ) ;
F_48 ( V_62 ) ;
V_11 = F_62 ( V_4 ) ;
if ( V_11 )
break;
}
F_56 ( V_67 ) ;
F_57 ( F_47 ( V_4 ) , & V_60 ) ;
return V_11 ;
}
static int T_3 F_81 ( void )
{
int V_11 ;
F_82 ( L_10 , V_110 ) ;
V_11 = F_83 () ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_84 ( & V_111 ) ;
if ( V_11 < 0 ) {
F_85 () ;
return V_11 ;
}
F_82 ( L_11 ) ;
V_11 = F_86 () ;
if ( V_11 < 0 )
goto error;
V_11 = F_87 () ;
if ( V_11 < 0 )
goto V_112;
V_11 = F_88 () ;
if ( V_11 < 0 ) {
F_89 () ;
goto V_112;
}
return 0 ;
V_112:
F_90 () ;
error:
F_91 ( V_113 ) ;
F_85 () ;
return V_11 ;
}
static void T_4 F_92 ( void )
{
F_93 () ;
F_89 () ;
F_90 () ;
F_91 ( V_113 ) ;
F_85 () ;
}
