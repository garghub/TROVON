static int F_1 ( bool V_1 , int V_2 , int V_3 )
{
struct V_4 * V_5 ;
unsigned int V_6 = F_2 () ;
bool V_7 ;
T_1 V_8 ;
struct V_9 * V_10 = & F_3 ( V_9 , V_6 ) ;
V_8 = F_4 () ;
if ( V_3 == V_11 ) {
if ( V_2 == V_12 )
V_5 = & V_10 -> V_13 ;
else if ( V_2 == V_14 )
V_5 = & V_10 -> V_15 ;
else
return 0 ;
} else if ( V_3 == V_16 ) {
if ( V_2 == V_12 )
V_5 = & V_10 -> V_17 ;
else if ( V_2 == V_14 )
V_5 = & V_10 -> V_18 ;
else
return 0 ;
} else
return 0 ;
V_7 = V_5 -> V_1 ;
V_5 -> V_1 = V_1 ;
if ( V_1 )
V_5 -> V_19 ++ ;
if ( F_5 ( V_8 , V_5 -> V_20 ) &&
V_5 -> V_19 != V_5 -> V_21 )
return 0 ;
V_5 -> V_20 = V_8 + V_22 ;
V_5 -> V_21 = V_5 -> V_19 ;
if ( V_1 ) {
if ( V_2 == V_12 )
F_6 ( V_23 L_1 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ,
V_5 -> V_19 ) ;
return 1 ;
}
if ( V_7 ) {
if ( V_2 == V_12 )
F_6 ( V_24 L_4 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_7 ( int V_3 , int V_2 )
{
struct V_4 * V_5 ;
unsigned int V_6 = F_2 () ;
struct V_9 * V_10 = & F_3 ( V_9 , V_6 ) ;
T_1 V_8 = F_4 () ;
if ( V_3 == V_16 )
V_5 = ( V_2 == 0 ) ? & V_10 -> V_25 :
& V_10 -> V_26 ;
else
V_5 = ( V_2 == 0 ) ? & V_10 -> V_27 :
& V_10 -> V_28 ;
if ( F_5 ( V_8 , V_5 -> V_20 ) )
return 0 ;
V_5 -> V_20 = V_8 + V_22 ;
return 1 ;
}
static int T_2 F_8 ( char * V_29 )
{
V_30 = true ;
return 1 ;
}
static int F_9 ( struct V_31 * V_32 , unsigned int V_33 )
{
int V_34 ;
struct V_35 * V_36 = & F_10 ( V_33 ) ;
V_34 = F_11 ( & V_32 -> V_37 , & V_38 ) ;
if ( V_34 )
return V_34 ;
if ( F_12 ( V_36 , V_39 ) && V_30 )
V_34 = F_13 ( & V_32 -> V_37 ,
& V_40 . V_41 ,
V_38 . V_42 ) ;
if ( F_12 ( V_36 , V_43 ) ) {
V_34 = F_13 ( & V_32 -> V_37 ,
& V_44 . V_41 ,
V_38 . V_42 ) ;
if ( F_12 ( V_36 , V_39 ) && V_30 )
V_34 = F_13 ( & V_32 -> V_37 ,
& V_45 . V_41 ,
V_38 . V_42 ) ;
}
return V_34 ;
}
static void F_14 ( struct V_31 * V_32 )
{
F_15 ( & V_32 -> V_37 , & V_38 ) ;
}
static int
F_16 ( struct V_46 * V_47 ,
unsigned long V_48 ,
void * V_49 )
{
unsigned int V_33 = ( unsigned long ) V_49 ;
struct V_31 * V_32 ;
int V_34 = 0 ;
V_32 = F_17 ( V_33 ) ;
switch ( V_48 ) {
case V_50 :
case V_51 :
F_18 ( & V_52 ) ;
V_34 = F_9 ( V_32 , V_33 ) ;
F_19 ( & V_52 ) ;
F_20 ( V_34 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
F_18 ( & V_52 ) ;
F_14 ( V_32 ) ;
F_19 ( & V_52 ) ;
break;
}
return F_21 ( V_34 ) ;
}
static T_2 int F_22 ( void )
{
unsigned int V_33 = 0 ;
int V_34 ;
if ( ! F_23 ( & V_57 ) )
return 0 ;
F_24 ( & V_58 ) ;
#ifdef F_25
F_18 ( & V_52 ) ;
#endif
F_26 (cpu) {
V_34 = F_9 ( F_17 ( V_33 ) , V_33 ) ;
F_20 ( V_34 ) ;
}
#ifdef F_25
F_19 ( & V_52 ) ;
#endif
return 0 ;
}
static void F_27 ( T_3 V_59 )
{
bool V_60 = false ;
bool V_61 = false ;
if ( ! V_62 )
return;
if ( V_59 & V_63 )
V_60 = true ;
if ( V_59 & V_64 )
V_61 = true ;
if ( ! V_60 && ! V_61 )
return;
if ( V_65 &&
V_65 () ) {
V_62 ( V_59 ) ;
return;
}
if ( V_60 && F_7 ( V_16 , 0 ) )
V_62 ( V_59 ) ;
if ( V_61 && F_7 ( V_16 , 1 ) )
V_62 ( V_59 ) ;
}
static void F_28 ( T_3 V_59 )
{
if ( ! V_66 )
return;
if ( ( V_59 & V_63 ) &&
F_7 ( V_11 , 0 ) )
V_66 ( V_59 ) ;
if ( ( V_59 & V_64 ) &&
F_7 ( V_11 , 1 ) )
V_66 ( V_59 ) ;
}
static void F_29 ( void )
{
T_3 V_59 ;
F_30 ( V_67 , V_59 ) ;
F_28 ( V_59 ) ;
if ( F_1 ( V_59 & V_68 ,
V_12 ,
V_11 ) != 0 )
F_31 ( V_59 ) ;
if ( F_32 ( V_39 ) && V_30 )
F_1 ( V_59 & V_69 ,
V_14 ,
V_11 ) ;
if ( F_32 ( V_43 ) ) {
F_30 ( V_70 , V_59 ) ;
F_27 ( V_59 ) ;
F_1 ( V_59 & V_71 ,
V_12 ,
V_16 ) ;
if ( F_32 ( V_39 ) && V_30 )
F_1 ( V_59 &
V_72 ,
V_14 ,
V_16 ) ;
}
}
static void F_33 ( void )
{
F_6 ( V_73 L_5 ,
F_2 () ) ;
}
static inline void F_34 ( void )
{
F_35 ( V_74 ) ;
F_36 () ;
}
T_4 void F_37 ( struct V_75 * V_76 )
{
F_38 () ;
F_34 () ;
F_39 () ;
}
T_4 void F_40 ( struct V_75 * V_76 )
{
F_38 () ;
F_41 ( V_77 ) ;
F_34 () ;
F_42 ( V_77 ) ;
F_39 () ;
}
static int F_43 ( struct V_35 * V_36 )
{
if ( ! V_78 )
return 0 ;
if ( ! F_12 ( V_36 , V_79 ) || ! F_12 ( V_36 , V_80 ) )
return 0 ;
return 1 ;
}
void T_2 F_44 ( void )
{
if ( F_43 ( & V_81 ) )
V_82 = F_45 ( V_83 ) ;
}
void F_46 ( struct V_35 * V_36 )
{
unsigned int V_33 = F_2 () ;
int V_84 = 0 ;
T_5 V_85 , V_86 ;
if ( ! F_43 ( V_36 ) )
return;
F_47 ( V_87 , V_85 , V_86 ) ;
V_86 = V_82 ;
if ( ( V_86 & V_88 ) != V_89 )
F_48 ( V_83 , V_82 ) ;
if ( ( V_85 & V_90 ) && ( V_86 & V_91 ) ) {
F_6 ( V_92
L_6 , V_33 ) ;
return;
}
if ( V_86 & V_93 ) {
F_6 ( V_92
L_7 ,
V_33 , ( V_86 & V_93 ) ) ;
return;
}
if ( F_12 ( V_36 , V_94 ) ) {
if ( V_36 -> V_95 == 6 && ( V_36 -> V_96 == 9 || V_36 -> V_96 == 13 ) ) {
F_47 ( V_97 , V_85 , V_86 ) ;
if ( V_85 & V_98 )
V_84 = 1 ;
} else if ( V_85 & V_99 )
V_84 = 1 ;
}
V_86 = V_77 | V_89 | V_100 ;
F_48 ( V_83 , V_86 ) ;
F_47 ( V_101 , V_85 , V_86 ) ;
if ( F_12 ( V_36 , V_39 ) && ! V_30 )
F_49 ( V_101 ,
( V_85 | ( V_102
| V_103 ) ) & ~ V_104 , V_86 ) ;
else if ( F_12 ( V_36 , V_39 ) && V_30 )
F_49 ( V_101 ,
V_85 | ( V_102
| V_103 | V_104 ) , V_86 ) ;
else
F_49 ( V_101 ,
V_85 | ( V_102 | V_103 ) , V_86 ) ;
if ( F_12 ( V_36 , V_43 ) ) {
F_47 ( V_105 , V_85 , V_86 ) ;
if ( F_12 ( V_36 , V_39 ) && ! V_30 )
F_49 ( V_105 ,
( V_85 | ( V_106
| V_107 ) )
& ~ V_108 , V_86 ) ;
else if ( F_12 ( V_36 , V_39 ) && V_30 )
F_49 ( V_105 ,
V_85 | ( V_106
| V_107
| V_108 ) , V_86 ) ;
else
F_49 ( V_105 ,
V_85 | ( V_106
| V_107 ) , V_86 ) ;
}
F_36 = F_29 ;
F_47 ( V_87 , V_85 , V_86 ) ;
F_49 ( V_87 , V_85 | V_90 , V_86 ) ;
V_85 = F_45 ( V_83 ) ;
F_48 ( V_83 , V_85 & ~ V_100 ) ;
F_50 ( V_24 L_8 ,
V_84 ? L_9 : L_10 ) ;
F_51 ( & V_57 , 1 ) ;
}
