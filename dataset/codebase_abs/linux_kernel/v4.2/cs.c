struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_4 ) ;
if ( ! V_4 )
return NULL ;
return F_3 ( V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_5 = F_3 ( V_4 ) ;
F_7 ( & V_5 -> V_6 ) ;
}
int F_8 ( struct V_1 * V_5 )
{
struct V_7 * V_8 ;
int V_9 ;
if ( ! V_5 || ! V_5 -> V_10 || ! V_5 -> V_4 . V_11 || ! V_5 -> V_12 )
return - V_13 ;
F_9 ( & V_5 -> V_4 , L_1 , V_5 -> V_10 ) ;
F_10 ( & V_14 ) ;
if ( F_11 ( & V_15 ) )
V_5 -> V_16 = 0 ;
else {
unsigned int V_17 , V_18 = 1 ;
struct V_1 * V_19 ;
do {
V_17 = 1 ;
F_12 (tmp, &pcmcia_socket_list, socket_list) {
if ( V_19 -> V_16 == V_18 )
V_17 = 0 ;
}
V_18 ++ ;
} while ( ! V_17 );
V_5 -> V_16 = V_18 - 1 ;
}
F_13 ( & V_5 -> V_20 , & V_15 ) ;
F_14 ( & V_14 ) ;
#ifndef F_15
V_5 -> V_21 &= ~ V_22 ;
#endif
F_16 ( & V_5 -> V_4 , V_5 ) ;
V_5 -> V_4 . V_23 = & V_24 ;
F_17 ( & V_5 -> V_4 , L_2 , V_5 -> V_16 ) ;
V_5 -> V_25 . V_26 = 0 ;
V_5 -> V_25 . V_27 = V_28 ;
F_18 ( & V_5 -> V_29 ) ;
F_19 ( & V_5 -> V_6 ) ;
F_19 ( & V_5 -> V_30 ) ;
F_20 ( & V_5 -> V_31 ) ;
F_20 ( & V_5 -> V_32 ) ;
F_21 ( & V_5 -> V_33 ) ;
if ( V_5 -> V_12 -> V_34 ) {
F_22 ( & V_5 -> V_32 ) ;
V_9 = V_5 -> V_12 -> V_34 ( V_5 ) ;
F_23 ( & V_5 -> V_32 ) ;
if ( V_9 )
goto V_35;
}
V_8 = F_24 ( V_36 , V_5 , L_3 ) ;
if ( F_25 ( V_8 ) ) {
V_9 = F_26 ( V_8 ) ;
goto V_35;
}
F_27 ( & V_5 -> V_30 ) ;
if ( ! V_5 -> V_37 ) {
F_28 ( & V_5 -> V_4 ,
L_4 ) ;
return - V_38 ;
}
F_29 ( V_5 , V_39 ) ;
F_30 ( L_5 ) ;
return 0 ;
V_35:
F_10 ( & V_14 ) ;
F_31 ( & V_5 -> V_20 ) ;
F_14 ( & V_14 ) ;
return V_9 ;
}
void F_32 ( struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_9 ( & V_5 -> V_4 , L_6 , V_5 -> V_10 ) ;
if ( V_5 -> V_37 )
F_33 ( V_5 -> V_37 ) ;
F_10 ( & V_14 ) ;
F_31 ( & V_5 -> V_20 ) ;
F_14 ( & V_14 ) ;
if ( V_5 -> V_12 -> exit ) {
F_22 ( & V_5 -> V_32 ) ;
V_5 -> V_12 -> exit ( V_5 ) ;
F_23 ( & V_5 -> V_32 ) ;
}
F_27 ( & V_5 -> V_6 ) ;
}
struct V_1 * F_34 ( unsigned int V_40 )
{
struct V_1 * V_41 ;
F_35 ( & V_14 ) ;
F_12 (s, &pcmcia_socket_list, socket_list)
if ( V_41 -> V_16 == V_40 ) {
F_36 ( & V_14 ) ;
return V_41 ;
}
F_36 ( & V_14 ) ;
return NULL ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_42 , V_18 ;
F_9 ( & V_2 -> V_4 , L_7 ) ;
V_2 -> V_5 . V_26 |= V_43 | V_44 ;
V_2 -> V_10 -> V_45 ( V_2 , & V_2 -> V_5 ) ;
F_38 ( ( long ) V_46 ) ;
V_2 -> V_5 . V_26 &= ~ V_44 ;
V_2 -> V_10 -> V_45 ( V_2 , & V_2 -> V_5 ) ;
F_39 ( V_47 * 10 ) ;
for ( V_18 = 0 ; V_18 < V_48 ; V_18 ++ ) {
V_2 -> V_10 -> V_49 ( V_2 , & V_42 ) ;
if ( ! ( V_42 & V_39 ) )
return - V_50 ;
if ( V_42 & V_51 )
return 0 ;
F_39 ( V_52 * 10 ) ;
}
F_40 ( & V_2 -> V_4 , L_8 ) ;
return - V_53 ;
}
static void F_41 ( struct V_1 * V_41 )
{
int V_42 ;
F_9 ( & V_41 -> V_4 , L_9 ) ;
if ( V_41 -> V_54 )
V_41 -> V_54 -> remove ( V_41 ) ;
F_22 ( & V_41 -> V_32 ) ;
V_41 -> V_55 &= V_56 | V_57 ;
F_39 ( V_58 * 10 ) ;
V_41 -> V_55 &= V_56 ;
V_41 -> V_5 = V_59 ;
V_41 -> V_10 -> V_34 ( V_41 ) ;
V_41 -> V_10 -> V_45 ( V_41 , & V_41 -> V_5 ) ;
V_41 -> V_60 = 0 ;
F_42 ( V_41 -> V_61 ) ;
V_41 -> V_61 = NULL ;
V_41 -> V_62 = 0 ;
F_23 ( & V_41 -> V_32 ) ;
#ifdef F_15
F_43 ( V_41 ) ;
#endif
F_39 ( 100 ) ;
V_41 -> V_10 -> V_49 ( V_41 , & V_42 ) ;
if ( V_42 & V_63 ) {
F_40 ( & V_41 -> V_4 ,
L_10 ) ;
}
V_41 -> V_55 &= ~ V_56 ;
}
static int F_44 ( struct V_1 * V_2 , int V_64 )
{
int V_42 , V_18 ;
F_9 ( & V_2 -> V_4 , L_11 ) ;
V_2 -> V_10 -> V_49 ( V_2 , & V_42 ) ;
if ( ! ( V_42 & V_39 ) )
return - V_50 ;
F_39 ( V_64 * 10 ) ;
for ( V_18 = 0 ; V_18 < 100 ; V_18 ++ ) {
V_2 -> V_10 -> V_49 ( V_2 , & V_42 ) ;
if ( ! ( V_42 & V_39 ) )
return - V_50 ;
if ( ! ( V_42 & V_65 ) )
break;
F_39 ( 100 ) ;
}
if ( V_42 & V_65 ) {
F_40 ( & V_2 -> V_4 , L_12 ) ;
return - V_53 ;
}
if ( V_42 & V_66 ) {
if ( ! ( V_2 -> V_21 & V_22 ) ) {
F_40 ( & V_2 -> V_4 , L_13 ) ;
return - V_13 ;
}
V_2 -> V_55 |= V_67 ;
} else
V_2 -> V_55 &= ~ V_67 ;
if ( V_42 & V_68 )
V_2 -> V_5 . V_69 = V_2 -> V_5 . V_70 = 33 ;
else if ( ! ( V_42 & V_71 ) )
V_2 -> V_5 . V_69 = V_2 -> V_5 . V_70 = 50 ;
else {
F_40 ( & V_2 -> V_4 , L_14 ) ;
return - V_38 ;
}
if ( V_2 -> V_72 )
V_2 -> V_72 ( V_2 , V_73 ) ;
V_2 -> V_5 . V_26 = 0 ;
V_2 -> V_10 -> V_45 ( V_2 , & V_2 -> V_5 ) ;
F_39 ( V_74 * 10 ) ;
V_2 -> V_10 -> V_49 ( V_2 , & V_42 ) ;
if ( ! ( V_42 & V_63 ) ) {
F_40 ( & V_2 -> V_4 , L_15 ) ;
return - V_38 ;
}
V_42 = F_37 ( V_2 ) ;
if ( V_2 -> V_72 )
V_2 -> V_72 ( V_2 , V_75 ) ;
return V_42 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_9 ;
F_9 ( & V_2 -> V_4 , L_16 ) ;
F_22 ( & V_2 -> V_32 ) ;
if ( V_2 -> V_55 & V_56 ) {
F_23 ( & V_2 -> V_32 ) ;
return - V_13 ;
}
V_2 -> V_55 |= V_56 ;
V_9 = F_44 ( V_2 , V_76 ) ;
if ( V_9 == 0 ) {
V_2 -> V_55 |= V_57 ;
F_46 ( & V_2 -> V_4 , L_17 ,
( V_2 -> V_55 & V_67 ) ? L_18 : L_19 ,
V_2 -> V_16 ) ;
#ifdef F_15
if ( V_2 -> V_55 & V_67 ) {
F_47 ( V_2 ) ;
V_2 -> V_55 |= V_77 ;
}
#endif
F_9 ( & V_2 -> V_4 , L_20 ) ;
F_23 ( & V_2 -> V_32 ) ;
if ( ! ( V_2 -> V_55 & V_67 ) && ( V_2 -> V_54 ) )
V_2 -> V_54 -> V_78 ( V_2 ) ;
} else {
F_23 ( & V_2 -> V_32 ) ;
F_41 ( V_2 ) ;
}
return V_9 ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_55 & V_79 )
return - V_80 ;
F_22 ( & V_2 -> V_32 ) ;
V_2 -> V_81 = V_2 -> V_55 ;
V_2 -> V_5 = V_59 ;
V_2 -> V_10 -> V_45 ( V_2 , & V_2 -> V_5 ) ;
if ( V_2 -> V_10 -> V_82 )
V_2 -> V_10 -> V_82 ( V_2 ) ;
V_2 -> V_55 |= V_79 ;
F_23 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_32 ) ;
V_2 -> V_5 = V_59 ;
V_2 -> V_10 -> V_34 ( V_2 ) ;
V_2 -> V_10 -> V_45 ( V_2 , & V_2 -> V_5 ) ;
if ( V_2 -> V_55 & V_57 )
V_2 -> V_83 = F_44 ( V_2 , V_84 ) ;
F_23 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
F_22 ( & V_2 -> V_32 ) ;
V_2 -> V_55 &= ~ V_79 ;
F_23 ( & V_2 -> V_32 ) ;
if ( ! ( V_2 -> V_55 & V_57 ) ) {
V_9 = F_45 ( V_2 ) ;
if ( V_9 == - V_50 )
V_9 = 0 ;
return V_9 ;
}
if ( V_2 -> V_83 ) {
F_41 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_81 != V_2 -> V_55 ) {
F_9 ( & V_2 -> V_4 ,
L_21 ,
V_2 -> V_81 , V_2 -> V_55 ) ;
F_41 ( V_2 ) ;
return F_45 ( V_2 ) ;
}
if ( ! ( V_2 -> V_55 & V_67 ) && ( V_2 -> V_54 ) )
V_9 = V_2 -> V_54 -> V_85 ( V_2 ) ;
return V_9 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
#ifdef F_15
if ( V_2 -> V_55 & V_67 ) {
F_43 ( V_2 ) ;
V_9 = F_47 ( V_2 ) ;
if ( V_9 )
F_43 ( V_2 ) ;
}
#endif
return V_9 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_35 ;
if ( ! ( V_2 -> V_55 & V_79 ) )
return - V_80 ;
F_49 ( V_2 ) ;
V_35 = F_50 ( V_2 ) ;
if ( ! V_35 )
V_35 = F_51 ( V_2 ) ;
return V_35 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_4 , L_22 , V_2 -> V_16 ) ;
F_41 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_55 & V_79 ) ) {
int V_42 ;
if ( ! ( V_2 -> V_55 & V_57 ) )
F_39 ( 20 ) ;
V_2 -> V_10 -> V_49 ( V_2 , & V_42 ) ;
if ( ( V_2 -> V_55 & V_57 ) &&
! ( V_42 & V_39 ) )
F_53 ( V_2 ) ;
if ( ! ( V_2 -> V_55 & V_57 ) &&
( V_42 & V_39 ) )
F_45 ( V_2 ) ;
}
}
static int V_36 ( void * V_86 )
{
struct V_1 * V_2 = V_86 ;
int V_9 ;
V_2 -> V_37 = V_87 ;
V_2 -> V_5 = V_59 ;
V_2 -> V_10 -> V_34 ( V_2 ) ;
V_2 -> V_10 -> V_45 ( V_2 , & V_2 -> V_5 ) ;
V_9 = F_55 ( & V_2 -> V_4 ) ;
if ( V_9 ) {
F_28 ( & V_2 -> V_4 , L_23 ) ;
V_2 -> V_37 = NULL ;
F_7 ( & V_2 -> V_30 ) ;
return 0 ;
}
V_9 = F_56 ( & V_2 -> V_4 ) ;
if ( V_9 )
F_28 ( & V_2 -> V_4 , L_24 , V_9 ) ;
F_7 ( & V_2 -> V_30 ) ;
F_39 ( 250 ) ;
F_57 () ;
for (; ; ) {
unsigned long V_26 ;
unsigned int V_88 ;
unsigned int V_89 ;
F_58 ( & V_2 -> V_33 , V_26 ) ;
V_88 = V_2 -> V_90 ;
V_2 -> V_90 = 0 ;
V_89 = V_2 -> V_89 ;
V_2 -> V_89 = 0 ;
F_59 ( & V_2 -> V_33 , V_26 ) ;
F_22 ( & V_2 -> V_31 ) ;
if ( V_88 & V_39 )
F_54 ( V_2 ) ;
if ( V_89 ) {
if ( V_89 & V_91 )
F_53 ( V_2 ) ;
if ( V_89 & V_92 )
F_45 ( V_2 ) ;
if ( ( V_89 & V_93 ) &&
! ( V_2 -> V_55 & V_67 ) ) {
if ( V_2 -> V_54 )
V_9 = V_2 -> V_54 -> V_82 ( V_2 ) ;
else
V_9 = 0 ;
if ( ! V_9 ) {
F_48 ( V_2 ) ;
F_39 ( 100 ) ;
}
}
if ( ( V_89 & V_94 ) &&
! ( V_2 -> V_55 & V_67 ) ) {
V_9 = F_52 ( V_2 ) ;
if ( ! V_9 && V_2 -> V_54 )
V_2 -> V_54 -> V_95 ( V_2 ) ;
}
if ( ( V_89 & V_96 ) &&
! ( V_2 -> V_55 & V_67 ) ) {
if ( ! V_9 && V_2 -> V_54 )
V_2 -> V_54 -> V_97 ( V_2 ) ;
}
}
F_23 ( & V_2 -> V_31 ) ;
if ( V_88 || V_89 )
continue;
if ( F_60 () )
break;
F_61 ( V_98 ) ;
F_62 () ;
F_63 ( V_99 ) ;
F_64 () ;
}
if ( V_2 -> V_55 & V_57 ) {
F_22 ( & V_2 -> V_31 ) ;
F_53 ( V_2 ) ;
F_23 ( & V_2 -> V_31 ) ;
}
F_65 ( & V_2 -> V_4 ) ;
F_66 ( & V_2 -> V_4 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_41 , T_1 V_88 )
{
unsigned long V_26 ;
F_9 ( & V_41 -> V_4 , L_25 , V_88 ) ;
if ( V_41 -> V_37 ) {
F_58 ( & V_41 -> V_33 , V_26 ) ;
V_41 -> V_90 |= V_88 ;
F_59 ( & V_41 -> V_33 , V_26 ) ;
F_67 ( V_41 -> V_37 ) ;
}
}
void F_68 ( struct V_1 * V_41 , T_1 V_88 )
{
unsigned long V_26 ;
F_9 ( & V_41 -> V_4 , L_26 , V_88 ) ;
if ( V_41 -> V_37 ) {
F_58 ( & V_41 -> V_33 , V_26 ) ;
V_41 -> V_89 |= V_88 ;
F_59 ( & V_41 -> V_33 , V_26 ) ;
F_67 ( V_41 -> V_37 ) ;
}
}
int F_69 ( struct V_1 * V_41 , struct V_100 * V_101 )
{
int V_9 = 0 ;
F_22 ( & V_41 -> V_31 ) ;
if ( V_101 ) {
if ( V_41 -> V_54 ) {
V_9 = - V_80 ;
goto V_35;
}
V_41 -> V_54 = V_101 ;
if ( ( V_41 -> V_55 & ( V_57 | V_67 ) ) == V_57 )
V_41 -> V_54 -> V_78 ( V_41 ) ;
} else
V_41 -> V_54 = NULL ;
V_35:
F_23 ( & V_41 -> V_31 ) ;
return V_9 ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_9 ;
F_9 ( & V_2 -> V_4 , L_27 ) ;
F_22 ( & V_2 -> V_31 ) ;
do {
if ( ! ( V_2 -> V_55 & V_57 ) ) {
F_9 ( & V_2 -> V_4 , L_28 ) ;
V_9 = - V_50 ;
break;
}
if ( V_2 -> V_55 & V_79 ) {
F_9 ( & V_2 -> V_4 , L_29 ) ;
V_9 = - V_80 ;
break;
}
if ( V_2 -> V_55 & V_67 ) {
F_9 ( & V_2 -> V_4 , L_30 ) ;
V_9 = - V_102 ;
break;
}
if ( V_2 -> V_54 )
V_2 -> V_54 -> V_82 ( V_2 ) ;
F_22 ( & V_2 -> V_32 ) ;
V_9 = F_37 ( V_2 ) ;
F_23 ( & V_2 -> V_32 ) ;
if ( ( V_9 == 0 ) && ( V_2 -> V_54 ) )
V_2 -> V_54 -> V_95 ( V_2 ) ;
V_9 = 0 ;
} while ( 0 );
F_23 ( & V_2 -> V_31 ) ;
return V_9 ;
}
static int F_71 ( struct V_3 * V_4 ,
struct V_103 * V_104 )
{
struct V_1 * V_41 = F_72 ( V_4 , struct V_1 , V_4 ) ;
if ( F_73 ( V_104 , L_31 , V_41 -> V_16 ) )
return - V_105 ;
return 0 ;
}
static void F_74 ( struct V_23 * V_106 )
{
F_7 ( & V_107 ) ;
}
static int F_75 ( struct V_3 * V_4 ,
int (* V_54) ( struct V_1 * V_2 ) )
{
struct V_1 * V_41 = F_72 ( V_4 , struct V_1 , V_4 ) ;
int V_9 ;
F_22 ( & V_41 -> V_31 ) ;
V_9 = V_54 ( V_41 ) ;
F_23 ( & V_41 -> V_31 ) ;
return V_9 ;
}
static int F_76 ( struct V_3 * V_4 )
{
return F_75 ( V_4 , F_48 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
return F_75 ( V_4 , F_49 ) ;
}
static int T_2 F_78 ( struct V_3 * V_4 )
{
return F_75 ( V_4 , F_50 ) ;
}
static void T_2 F_79 ( struct V_3 * V_4 )
{
F_80 ( F_75 ( V_4 , F_51 ) ,
L_32 ) ;
}
static int T_3 F_81 ( void )
{
F_19 ( & V_107 ) ;
return F_82 ( & V_24 ) ;
}
static void T_4 F_83 ( void )
{
F_84 ( & V_24 ) ;
F_27 ( & V_107 ) ;
}
