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
F_6 ( L_1 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ,
V_5 -> V_19 ) ;
return 1 ;
}
if ( V_7 ) {
if ( V_2 == V_12 )
F_7 ( L_4 , V_6 ,
V_3 == V_11 ? L_2 : L_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_8 ( int V_3 , int V_2 )
{
struct V_4 * V_5 ;
unsigned int V_6 = F_2 () ;
struct V_9 * V_10 = & F_3 ( V_9 , V_6 ) ;
T_1 V_8 = F_4 () ;
if ( V_3 == V_16 )
V_5 = ( V_2 == 0 ) ? & V_10 -> V_23 :
& V_10 -> V_24 ;
else
V_5 = ( V_2 == 0 ) ? & V_10 -> V_25 :
& V_10 -> V_26 ;
if ( F_5 ( V_8 , V_5 -> V_20 ) )
return 0 ;
V_5 -> V_20 = V_8 + V_22 ;
return 1 ;
}
static int T_2 F_9 ( char * V_27 )
{
V_28 = true ;
return 1 ;
}
static int F_10 ( struct V_29 * V_30 , unsigned int V_31 )
{
int V_32 ;
struct V_33 * V_34 = & F_11 ( V_31 ) ;
V_32 = F_12 ( & V_30 -> V_35 , & V_36 ) ;
if ( V_32 )
return V_32 ;
if ( F_13 ( V_34 , V_37 ) && V_28 )
V_32 = F_14 ( & V_30 -> V_35 ,
& V_38 . V_39 ,
V_36 . V_40 ) ;
if ( F_13 ( V_34 , V_41 ) ) {
V_32 = F_14 ( & V_30 -> V_35 ,
& V_42 . V_39 ,
V_36 . V_40 ) ;
if ( F_13 ( V_34 , V_37 ) && V_28 )
V_32 = F_14 ( & V_30 -> V_35 ,
& V_43 . V_39 ,
V_36 . V_40 ) ;
}
return V_32 ;
}
static void F_15 ( struct V_29 * V_30 )
{
F_16 ( & V_30 -> V_35 , & V_36 ) ;
}
static int
F_17 ( struct V_44 * V_45 ,
unsigned long V_46 ,
void * V_47 )
{
unsigned int V_31 = ( unsigned long ) V_47 ;
struct V_29 * V_30 ;
int V_32 = 0 ;
V_30 = F_18 ( V_31 ) ;
switch ( V_46 ) {
case V_48 :
case V_49 :
V_32 = F_10 ( V_30 , V_31 ) ;
F_19 ( V_32 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_15 ( V_30 ) ;
break;
}
return F_20 ( V_32 ) ;
}
static T_2 int F_21 ( void )
{
unsigned int V_31 = 0 ;
int V_32 ;
if ( ! F_22 ( & V_54 ) )
return 0 ;
F_23 () ;
F_24 (cpu) {
V_32 = F_10 ( F_18 ( V_31 ) , V_31 ) ;
F_19 ( V_32 ) ;
}
F_25 ( & V_55 ) ;
F_26 () ;
return 0 ;
}
static void F_27 ( T_3 V_56 )
{
bool V_57 = false ;
bool V_58 = false ;
if ( ! V_59 )
return;
if ( V_56 & V_60 )
V_57 = true ;
if ( V_56 & V_61 )
V_58 = true ;
if ( ! V_57 && ! V_58 )
return;
if ( V_62 &&
V_62 () ) {
V_59 ( V_56 ) ;
return;
}
if ( V_57 && F_8 ( V_16 , 0 ) )
V_59 ( V_56 ) ;
if ( V_58 && F_8 ( V_16 , 1 ) )
V_59 ( V_56 ) ;
}
static void F_28 ( T_3 V_56 )
{
if ( ! V_63 )
return;
if ( ( V_56 & V_60 ) &&
F_8 ( V_11 , 0 ) )
V_63 ( V_56 ) ;
if ( ( V_56 & V_61 ) &&
F_8 ( V_11 , 1 ) )
V_63 ( V_56 ) ;
}
static void F_29 ( void )
{
T_3 V_56 ;
if ( F_30 ( V_64 ) )
F_31 ( V_65 , 0 ) ;
F_32 ( V_66 , V_56 ) ;
F_28 ( V_56 ) ;
if ( F_1 ( V_56 & V_67 ,
V_12 ,
V_11 ) != 0 )
F_33 ( V_56 ) ;
if ( F_34 ( V_37 ) && V_28 )
F_1 ( V_56 & V_68 ,
V_14 ,
V_11 ) ;
if ( F_34 ( V_41 ) ) {
F_32 ( V_69 , V_56 ) ;
F_27 ( V_56 ) ;
F_1 ( V_56 & V_70 ,
V_12 ,
V_16 ) ;
if ( F_34 ( V_37 ) && V_28 )
F_1 ( V_56 &
V_71 ,
V_14 ,
V_16 ) ;
}
}
static void F_35 ( void )
{
F_36 ( L_5 ,
F_2 () ) ;
}
static inline void F_37 ( void )
{
F_38 ( V_72 ) ;
F_39 () ;
}
T_4 T_5 void F_40 ( struct V_73 * V_74 )
{
F_41 () ;
F_37 () ;
F_42 () ;
}
T_4 T_5 void F_43 ( struct V_73 * V_74 )
{
F_41 () ;
F_44 ( V_75 ) ;
F_37 () ;
F_45 ( V_75 ) ;
F_42 () ;
}
static int F_46 ( struct V_33 * V_34 )
{
if ( ! V_76 )
return 0 ;
if ( ! F_13 ( V_34 , V_77 ) || ! F_13 ( V_34 , V_78 ) )
return 0 ;
return 1 ;
}
void T_2 F_47 ( void )
{
if ( F_46 ( & V_79 ) )
V_80 = F_48 ( V_81 ) ;
}
void F_49 ( struct V_33 * V_34 )
{
unsigned int V_31 = F_2 () ;
int V_82 = 0 ;
T_6 V_83 , V_84 ;
if ( ! F_46 ( V_34 ) )
return;
F_50 ( V_85 , V_83 , V_84 ) ;
V_84 = V_80 ;
if ( ( V_84 & V_86 ) != V_87 )
F_51 ( V_81 , V_80 ) ;
if ( ( V_83 & V_88 ) && ( V_84 & V_89 ) ) {
if ( V_90 == V_91 )
F_52 ( L_6 , V_31 ) ;
return;
}
if ( F_13 ( V_34 , V_92 ) ) {
if ( V_34 -> V_93 == 6 && ( V_34 -> V_94 == 9 || V_34 -> V_94 == 13 ) ) {
F_50 ( V_95 , V_83 , V_84 ) ;
if ( V_83 & V_96 )
V_82 = 1 ;
} else if ( V_83 & V_97 )
V_82 = 1 ;
}
V_84 = V_75 | V_87 | V_98 ;
F_51 ( V_81 , V_84 ) ;
F_50 ( V_99 , V_83 , V_84 ) ;
if ( F_13 ( V_34 , V_37 ) && ! V_28 )
F_53 ( V_99 ,
( V_83 | ( V_100
| V_101 ) ) & ~ V_102 , V_84 ) ;
else if ( F_13 ( V_34 , V_37 ) && V_28 )
F_53 ( V_99 ,
V_83 | ( V_100
| V_101 | V_102 ) , V_84 ) ;
else
F_53 ( V_99 ,
V_83 | ( V_100 | V_101 ) , V_84 ) ;
if ( F_13 ( V_34 , V_41 ) ) {
F_50 ( V_103 , V_83 , V_84 ) ;
if ( F_13 ( V_34 , V_37 ) && ! V_28 )
F_53 ( V_103 ,
( V_83 | ( V_104
| V_105 ) )
& ~ V_106 , V_84 ) ;
else if ( F_13 ( V_34 , V_37 ) && V_28 )
F_53 ( V_103 ,
V_83 | ( V_104
| V_105
| V_106 ) , V_84 ) ;
else
F_53 ( V_103 ,
V_83 | ( V_104
| V_105 ) , V_84 ) ;
}
F_39 = F_29 ;
F_50 ( V_85 , V_83 , V_84 ) ;
F_53 ( V_85 , V_83 | V_88 , V_84 ) ;
V_83 = F_48 ( V_81 ) ;
F_51 ( V_81 , V_83 & ~ V_98 ) ;
F_54 ( L_7 ,
V_82 ? L_8 : L_9 ) ;
F_55 ( & V_54 , 1 ) ;
}
