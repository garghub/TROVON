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
V_34 = F_9 ( V_32 , V_33 ) ;
F_18 ( V_34 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
F_14 ( V_32 ) ;
break;
}
return F_19 ( V_34 ) ;
}
static T_2 int F_20 ( void )
{
unsigned int V_33 = 0 ;
int V_34 ;
if ( ! F_21 ( & V_56 ) )
return 0 ;
F_22 () ;
F_23 (cpu) {
V_34 = F_9 ( F_17 ( V_33 ) , V_33 ) ;
F_18 ( V_34 ) ;
}
F_24 ( & V_57 ) ;
F_25 () ;
return 0 ;
}
static void F_26 ( T_3 V_58 )
{
bool V_59 = false ;
bool V_60 = false ;
if ( ! V_61 )
return;
if ( V_58 & V_62 )
V_59 = true ;
if ( V_58 & V_63 )
V_60 = true ;
if ( ! V_59 && ! V_60 )
return;
if ( V_64 &&
V_64 () ) {
V_61 ( V_58 ) ;
return;
}
if ( V_59 && F_7 ( V_16 , 0 ) )
V_61 ( V_58 ) ;
if ( V_60 && F_7 ( V_16 , 1 ) )
V_61 ( V_58 ) ;
}
static void F_27 ( T_3 V_58 )
{
if ( ! V_65 )
return;
if ( ( V_58 & V_62 ) &&
F_7 ( V_11 , 0 ) )
V_65 ( V_58 ) ;
if ( ( V_58 & V_63 ) &&
F_7 ( V_11 , 1 ) )
V_65 ( V_58 ) ;
}
static void F_28 ( void )
{
T_3 V_58 ;
F_29 ( V_66 , V_58 ) ;
F_27 ( V_58 ) ;
if ( F_1 ( V_58 & V_67 ,
V_12 ,
V_11 ) != 0 )
F_30 ( V_58 ) ;
if ( F_31 ( V_39 ) && V_30 )
F_1 ( V_58 & V_68 ,
V_14 ,
V_11 ) ;
if ( F_31 ( V_43 ) ) {
F_29 ( V_69 , V_58 ) ;
F_26 ( V_58 ) ;
F_1 ( V_58 & V_70 ,
V_12 ,
V_16 ) ;
if ( F_31 ( V_39 ) && V_30 )
F_1 ( V_58 &
V_71 ,
V_14 ,
V_16 ) ;
}
}
static void F_32 ( void )
{
F_6 ( V_72 L_5 ,
F_2 () ) ;
}
static inline void F_33 ( void )
{
F_34 ( V_73 ) ;
F_35 () ;
}
T_4 T_5 void F_36 ( struct V_74 * V_75 )
{
F_37 () ;
F_33 () ;
F_38 () ;
}
T_4 T_5 void F_39 ( struct V_74 * V_75 )
{
F_37 () ;
F_40 ( V_76 ) ;
F_33 () ;
F_41 ( V_76 ) ;
F_38 () ;
}
static int F_42 ( struct V_35 * V_36 )
{
if ( ! V_77 )
return 0 ;
if ( ! F_12 ( V_36 , V_78 ) || ! F_12 ( V_36 , V_79 ) )
return 0 ;
return 1 ;
}
void T_2 F_43 ( void )
{
if ( F_42 ( & V_80 ) )
V_81 = F_44 ( V_82 ) ;
}
void F_45 ( struct V_35 * V_36 )
{
unsigned int V_33 = F_2 () ;
int V_83 = 0 ;
T_6 V_84 , V_85 ;
if ( ! F_42 ( V_36 ) )
return;
F_46 ( V_86 , V_84 , V_85 ) ;
V_85 = V_81 ;
if ( ( V_85 & V_87 ) != V_88 )
F_47 ( V_82 , V_81 ) ;
if ( ( V_84 & V_89 ) && ( V_85 & V_90 ) ) {
F_6 ( V_91
L_6 , V_33 ) ;
return;
}
if ( V_85 & V_92 ) {
F_6 ( V_91
L_7 ,
V_33 , ( V_85 & V_92 ) ) ;
return;
}
if ( F_12 ( V_36 , V_93 ) ) {
if ( V_36 -> V_94 == 6 && ( V_36 -> V_95 == 9 || V_36 -> V_95 == 13 ) ) {
F_46 ( V_96 , V_84 , V_85 ) ;
if ( V_84 & V_97 )
V_83 = 1 ;
} else if ( V_84 & V_98 )
V_83 = 1 ;
}
V_85 = V_76 | V_88 | V_99 ;
F_47 ( V_82 , V_85 ) ;
F_46 ( V_100 , V_84 , V_85 ) ;
if ( F_12 ( V_36 , V_39 ) && ! V_30 )
F_48 ( V_100 ,
( V_84 | ( V_101
| V_102 ) ) & ~ V_103 , V_85 ) ;
else if ( F_12 ( V_36 , V_39 ) && V_30 )
F_48 ( V_100 ,
V_84 | ( V_101
| V_102 | V_103 ) , V_85 ) ;
else
F_48 ( V_100 ,
V_84 | ( V_101 | V_102 ) , V_85 ) ;
if ( F_12 ( V_36 , V_43 ) ) {
F_46 ( V_104 , V_84 , V_85 ) ;
if ( F_12 ( V_36 , V_39 ) && ! V_30 )
F_48 ( V_104 ,
( V_84 | ( V_105
| V_106 ) )
& ~ V_107 , V_85 ) ;
else if ( F_12 ( V_36 , V_39 ) && V_30 )
F_48 ( V_104 ,
V_84 | ( V_105
| V_106
| V_107 ) , V_85 ) ;
else
F_48 ( V_104 ,
V_84 | ( V_105
| V_106 ) , V_85 ) ;
}
F_35 = F_28 ;
F_46 ( V_86 , V_84 , V_85 ) ;
F_48 ( V_86 , V_84 | V_89 , V_85 ) ;
V_84 = F_44 ( V_82 ) ;
F_47 ( V_82 , V_84 & ~ V_99 ) ;
F_49 ( V_24 L_8 ,
V_83 ? L_9 : L_10 ) ;
F_50 ( & V_56 , 1 ) ;
}
