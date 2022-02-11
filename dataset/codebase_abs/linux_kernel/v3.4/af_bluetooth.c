void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ! V_2 ) ;
F_2 ( F_3 ( V_2 ) ) ;
F_4 ( V_2 ,
V_4 [ V_3 ] , & V_5 [ V_3 ] ,
V_6 [ V_3 ] , & V_7 [ V_3 ] ) ;
}
int F_5 ( int V_3 , const struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
F_6 ( & V_13 ) ;
if ( V_14 [ V_3 ] )
V_10 = - V_15 ;
else
V_14 [ V_3 ] = V_9 ;
F_7 ( & V_13 ) ;
return V_10 ;
}
int F_8 ( int V_3 )
{
int V_10 = 0 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
F_6 ( & V_13 ) ;
if ( ! V_14 [ V_3 ] )
V_10 = - V_16 ;
else
V_14 [ V_3 ] = NULL ;
F_7 ( & V_13 ) ;
return V_10 ;
}
static int F_9 ( struct V_17 * V_17 , struct V_18 * V_1 , int V_3 ,
int V_19 )
{
int V_10 ;
if ( V_17 != & V_20 )
return - V_21 ;
if ( V_3 < 0 || V_3 >= V_11 )
return - V_12 ;
if ( ! V_14 [ V_3 ] )
F_10 ( L_1 , V_3 ) ;
V_10 = - V_22 ;
F_11 ( & V_13 ) ;
if ( V_14 [ V_3 ] && F_12 ( V_14 [ V_3 ] -> V_23 ) ) {
V_10 = V_14 [ V_3 ] -> F_13 ( V_17 , V_1 , V_3 , V_19 ) ;
if ( ! V_10 )
F_1 ( V_1 -> V_2 , V_3 ) ;
F_14 ( V_14 [ V_3 ] -> V_23 ) ;
}
F_15 ( & V_13 ) ;
return V_10 ;
}
void F_16 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
F_6 ( & V_25 -> V_26 ) ;
F_17 ( V_2 , & V_25 -> V_27 ) ;
F_7 ( & V_25 -> V_26 ) ;
}
void F_18 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
F_6 ( & V_25 -> V_26 ) ;
F_19 ( V_2 ) ;
F_7 ( & V_25 -> V_26 ) ;
}
void F_20 ( struct V_1 * V_28 , struct V_1 * V_2 )
{
F_21 ( L_2 , V_28 , V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( & F_24 ( V_2 ) -> V_29 , & F_24 ( V_28 ) -> V_29 ) ;
F_24 ( V_2 ) -> V_28 = V_28 ;
V_28 -> V_30 ++ ;
}
void F_25 ( struct V_1 * V_2 )
{
F_21 ( L_3 , V_2 , V_2 -> V_31 ) ;
F_26 ( & F_24 ( V_2 ) -> V_29 ) ;
F_24 ( V_2 ) -> V_28 -> V_30 -- ;
F_24 ( V_2 ) -> V_28 = NULL ;
F_27 ( V_2 ) ;
}
struct V_1 * F_28 ( struct V_1 * V_28 , struct V_18 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
struct V_1 * V_2 ;
F_21 ( L_4 , V_28 ) ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_34 , struct V_36 , V_29 ) ;
F_31 ( V_2 ) ;
if ( V_2 -> V_31 == V_37 ) {
F_32 ( V_2 ) ;
F_25 ( V_2 ) ;
continue;
}
if ( V_2 -> V_31 == V_38 || ! V_32 ||
F_24 ( V_28 ) -> V_39 ) {
F_25 ( V_2 ) ;
if ( V_32 )
F_33 ( V_2 , V_32 ) ;
F_32 ( V_2 ) ;
return V_2 ;
}
F_32 ( V_2 ) ;
}
return NULL ;
}
int F_34 ( struct V_40 * V_41 , struct V_18 * V_1 ,
struct V_42 * V_43 , T_1 V_44 , int V_45 )
{
int V_46 = V_45 & V_47 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_48 * V_49 ;
T_1 V_50 ;
int V_10 ;
F_21 ( L_5 , V_1 , V_2 , V_44 ) ;
if ( V_45 & ( V_51 ) )
return - V_52 ;
V_49 = F_35 ( V_2 , V_45 , V_46 , & V_10 ) ;
if ( ! V_49 ) {
if ( V_2 -> V_53 & V_54 )
return 0 ;
return V_10 ;
}
V_43 -> V_55 = 0 ;
V_50 = V_49 -> V_44 ;
if ( V_44 < V_50 ) {
V_43 -> V_56 |= V_57 ;
V_50 = V_44 ;
}
F_36 ( V_49 ) ;
V_10 = F_37 ( V_49 , 0 , V_43 -> V_58 , V_50 ) ;
if ( V_10 == 0 )
F_38 ( V_43 , V_2 , V_49 ) ;
F_39 ( V_2 , V_49 ) ;
return V_10 ? : V_50 ;
}
static long F_40 ( struct V_1 * V_2 , long V_59 )
{
F_41 ( V_60 , V_61 ) ;
F_42 ( F_43 ( V_2 ) , & V_60 ) ;
for (; ; ) {
F_44 ( V_62 ) ;
if ( ! F_45 ( & V_2 -> V_63 ) )
break;
if ( V_2 -> V_64 || ( V_2 -> V_53 & V_54 ) )
break;
if ( F_46 ( V_61 ) || ! V_59 )
break;
F_47 ( V_65 , & V_2 -> V_66 -> V_45 ) ;
F_32 ( V_2 ) ;
V_59 = F_48 ( V_59 ) ;
F_31 ( V_2 ) ;
F_49 ( V_65 , & V_2 -> V_66 -> V_45 ) ;
}
F_50 ( V_67 ) ;
F_51 ( F_43 ( V_2 ) , & V_60 ) ;
return V_59 ;
}
int F_52 ( struct V_40 * V_41 , struct V_18 * V_1 ,
struct V_42 * V_43 , T_1 V_68 , int V_45 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_10 = 0 ;
T_1 V_69 , V_50 = 0 ;
long V_59 ;
if ( V_45 & V_51 )
return - V_52 ;
V_43 -> V_55 = 0 ;
F_21 ( L_6 , V_2 , V_68 ) ;
F_31 ( V_2 ) ;
V_69 = F_53 ( V_2 , V_45 & V_70 , V_68 ) ;
V_59 = F_54 ( V_2 , V_45 & V_47 ) ;
do {
struct V_48 * V_49 ;
int V_71 ;
V_49 = F_55 ( & V_2 -> V_63 ) ;
if ( ! V_49 ) {
if ( V_50 >= V_69 )
break;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
if ( V_2 -> V_53 & V_54 )
break;
V_10 = - V_72 ;
if ( ! V_59 )
break;
V_59 = F_40 ( V_2 , V_59 ) ;
if ( F_46 ( V_61 ) ) {
V_10 = F_57 ( V_59 ) ;
goto V_73;
}
continue;
}
V_71 = F_58 (unsigned int, skb->len, size) ;
if ( F_37 ( V_49 , 0 , V_43 -> V_58 , V_71 ) ) {
F_59 ( & V_2 -> V_63 , V_49 ) ;
if ( ! V_50 )
V_50 = - V_74 ;
break;
}
V_50 += V_71 ;
V_68 -= V_71 ;
F_38 ( V_43 , V_2 , V_49 ) ;
if ( ! ( V_45 & V_75 ) ) {
int V_76 = F_60 ( V_49 ) ;
if ( V_71 <= V_76 ) {
F_61 ( V_49 , V_71 ) ;
} else {
struct V_48 * V_77 ;
F_61 ( V_49 , V_76 ) ;
V_71 -= V_76 ;
F_62 (skb, frag) {
if ( V_71 <= V_77 -> V_44 ) {
V_49 -> V_44 -= V_71 ;
V_49 -> V_78 -= V_71 ;
F_61 ( V_77 , V_71 ) ;
break;
} else if ( V_77 -> V_44 ) {
V_71 -= V_77 -> V_44 ;
V_49 -> V_44 -= V_77 -> V_44 ;
V_49 -> V_78 -= V_77 -> V_44 ;
F_61 ( V_77 , V_77 -> V_44 ) ;
}
}
}
if ( V_49 -> V_44 ) {
F_59 ( & V_2 -> V_63 , V_49 ) ;
break;
}
F_63 ( V_49 ) ;
} else {
F_59 ( & V_2 -> V_63 , V_49 ) ;
break;
}
} while ( V_68 );
V_73:
F_32 ( V_2 ) ;
return V_50 ? : V_10 ;
}
static inline unsigned int F_64 ( struct V_1 * V_28 )
{
struct V_33 * V_34 , * V_35 ;
struct V_1 * V_2 ;
F_29 (p, n, &bt_sk(parent)->accept_q) {
V_2 = (struct V_1 * ) F_30 ( V_34 , struct V_36 , V_29 ) ;
if ( V_2 -> V_31 == V_38 ||
( F_24 ( V_28 ) -> V_39 &&
V_2 -> V_31 == V_79 ) )
return V_80 | V_81 ;
}
return 0 ;
}
unsigned int F_65 ( struct V_82 * V_82 , struct V_18 * V_1 , T_2 * V_60 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned int V_83 = 0 ;
F_21 ( L_7 , V_1 , V_2 ) ;
F_66 ( V_82 , F_43 ( V_2 ) , V_60 ) ;
if ( V_2 -> V_31 == V_84 )
return F_64 ( V_2 ) ;
if ( V_2 -> V_64 || ! F_45 ( & V_2 -> V_85 ) )
V_83 |= V_86 ;
if ( V_2 -> V_53 & V_54 )
V_83 |= V_87 | V_80 | V_81 ;
if ( V_2 -> V_53 == V_88 )
V_83 |= V_89 ;
if ( ! F_45 ( & V_2 -> V_63 ) )
V_83 |= V_80 | V_81 ;
if ( V_2 -> V_31 == V_37 )
V_83 |= V_89 ;
if ( V_2 -> V_31 == V_90 ||
V_2 -> V_31 == V_79 ||
V_2 -> V_31 == V_91 )
return V_83 ;
if ( ! F_24 ( V_2 ) -> V_92 && F_67 ( V_2 ) )
V_83 |= V_93 | V_94 | V_95 ;
else
F_47 ( V_96 , & V_2 -> V_66 -> V_45 ) ;
return V_83 ;
}
int F_68 ( struct V_18 * V_1 , unsigned int V_97 , unsigned long V_98 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_48 * V_49 ;
long V_99 ;
int V_10 ;
F_21 ( L_8 , V_2 , V_97 , V_98 ) ;
switch ( V_97 ) {
case V_100 :
if ( V_2 -> V_31 == V_84 )
return - V_12 ;
V_99 = V_2 -> V_101 - F_69 ( V_2 ) ;
if ( V_99 < 0 )
V_99 = 0 ;
V_10 = F_70 ( V_99 , ( int V_102 * ) V_98 ) ;
break;
case V_103 :
if ( V_2 -> V_31 == V_84 )
return - V_12 ;
F_31 ( V_2 ) ;
V_49 = F_71 ( & V_2 -> V_63 ) ;
V_99 = V_49 ? V_49 -> V_44 : 0 ;
F_32 ( V_2 ) ;
V_10 = F_70 ( V_99 , ( int V_102 * ) V_98 ) ;
break;
case V_104 :
V_10 = F_72 ( V_2 , (struct V_105 V_102 * ) V_98 ) ;
break;
case V_106 :
V_10 = F_73 ( V_2 , (struct V_107 V_102 * ) V_98 ) ;
break;
default:
V_10 = - V_108 ;
break;
}
return V_10 ;
}
int F_74 ( struct V_1 * V_2 , int V_109 , unsigned long V_59 )
{
F_41 ( V_60 , V_61 ) ;
int V_10 = 0 ;
F_21 ( L_9 , V_2 ) ;
F_42 ( F_43 ( V_2 ) , & V_60 ) ;
F_44 ( V_62 ) ;
while ( V_2 -> V_31 != V_109 ) {
if ( ! V_59 ) {
V_10 = - V_110 ;
break;
}
if ( F_46 ( V_61 ) ) {
V_10 = F_57 ( V_59 ) ;
break;
}
F_32 ( V_2 ) ;
V_59 = F_48 ( V_59 ) ;
F_31 ( V_2 ) ;
F_44 ( V_62 ) ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 )
break;
}
F_50 ( V_67 ) ;
F_51 ( F_43 ( V_2 ) , & V_60 ) ;
return V_10 ;
}
static int T_3 F_75 ( void )
{
int V_10 ;
F_76 ( L_10 , V_111 ) ;
V_10 = F_77 () ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_78 ( & V_112 ) ;
if ( V_10 < 0 ) {
F_79 () ;
return V_10 ;
}
F_76 ( L_11 ) ;
V_10 = F_80 () ;
if ( V_10 < 0 )
goto error;
V_10 = F_81 () ;
if ( V_10 < 0 )
goto V_113;
V_10 = F_82 () ;
if ( V_10 < 0 ) {
F_83 () ;
goto V_113;
}
return 0 ;
V_113:
F_84 () ;
error:
F_85 ( V_114 ) ;
F_79 () ;
return V_10 ;
}
static void T_4 F_86 ( void )
{
F_87 () ;
F_83 () ;
F_84 () ;
F_85 ( V_114 ) ;
F_79 () ;
}
