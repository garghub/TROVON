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
else
F_6 ( V_23 L_4 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ,
V_5 -> V_19 ) ;
return 1 ;
}
if ( V_7 ) {
if ( V_2 == V_12 )
F_6 ( V_24 L_5 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ) ;
else
F_6 ( V_24 L_6 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_7 ( int V_2 )
{
struct V_4 * V_5 ;
unsigned int V_6 = F_2 () ;
struct V_9 * V_10 = & F_3 ( V_9 , V_6 ) ;
T_1 V_8 = F_4 () ;
V_5 = ( V_2 == 0 ) ? & V_10 -> V_25 : & V_10 -> V_26 ;
if ( F_5 ( V_8 , V_5 -> V_20 ) )
return 0 ;
V_5 -> V_20 = V_8 + V_22 ;
return 1 ;
}
static T_2 int F_8 ( struct V_27 * V_28 ,
unsigned int V_29 )
{
int V_30 ;
struct V_31 * V_32 = & F_9 ( V_29 ) ;
V_30 = F_10 ( & V_28 -> V_33 , & V_34 ) ;
if ( V_30 )
return V_30 ;
if ( F_11 ( V_32 , V_35 ) )
V_30 = F_12 ( & V_28 -> V_33 ,
& V_36 . V_37 ,
V_34 . V_38 ) ;
if ( F_11 ( V_32 , V_39 ) ) {
V_30 = F_12 ( & V_28 -> V_33 ,
& V_40 . V_37 ,
V_34 . V_38 ) ;
if ( F_11 ( V_32 , V_35 ) )
V_30 = F_12 ( & V_28 -> V_33 ,
& V_41 . V_37 ,
V_34 . V_38 ) ;
}
return V_30 ;
}
static T_2 void F_13 ( struct V_27 * V_28 )
{
F_14 ( & V_28 -> V_33 , & V_34 ) ;
}
static T_2 int
F_15 ( struct V_42 * V_43 ,
unsigned long V_44 ,
void * V_45 )
{
unsigned int V_29 = ( unsigned long ) V_45 ;
struct V_27 * V_28 ;
int V_30 = 0 ;
V_28 = F_16 ( V_29 ) ;
switch ( V_44 ) {
case V_46 :
case V_47 :
F_17 ( & V_48 ) ;
V_30 = F_8 ( V_28 , V_29 ) ;
F_18 ( & V_48 ) ;
F_19 ( V_30 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_17 ( & V_48 ) ;
F_13 ( V_28 ) ;
F_18 ( & V_48 ) ;
break;
}
return F_20 ( V_30 ) ;
}
static T_3 int F_21 ( void )
{
unsigned int V_29 = 0 ;
int V_30 ;
if ( ! F_22 ( & V_53 ) )
return 0 ;
F_23 ( & V_54 ) ;
#ifdef F_24
F_17 ( & V_48 ) ;
#endif
F_25 (cpu) {
V_30 = F_8 ( F_16 ( V_29 ) , V_29 ) ;
F_19 ( V_30 ) ;
}
#ifdef F_24
F_18 ( & V_48 ) ;
#endif
return 0 ;
}
static void F_26 ( T_4 V_55 )
{
if ( ! V_56 )
return;
if ( ( V_55 & V_57 ) && F_7 ( 0 ) )
V_56 ( V_55 ) ;
if ( ( V_55 & V_58 ) && F_7 ( 1 ) )
V_56 ( V_55 ) ;
}
static void F_27 ( void )
{
T_4 V_55 ;
F_28 ( V_59 , V_55 ) ;
F_26 ( V_55 ) ;
if ( F_1 ( V_55 & V_60 ,
V_12 ,
V_11 ) != 0 )
F_29 ( V_61 | V_55 ) ;
if ( F_30 ( V_35 ) )
if ( F_1 ( V_55 & V_62 ,
V_14 ,
V_11 ) != 0 )
F_29 ( V_63 | V_55 ) ;
if ( F_30 ( V_39 ) ) {
F_28 ( V_64 , V_55 ) ;
if ( F_1 ( V_55 & V_65 ,
V_12 ,
V_16 ) != 0 )
F_29 ( V_66 | V_55 ) ;
if ( F_30 ( V_35 ) )
if ( F_1 ( V_55 &
V_67 ,
V_14 ,
V_16 ) != 0 )
F_29 ( V_68
| V_55 ) ;
}
}
static void F_31 ( void )
{
F_6 ( V_69 L_7 ,
F_2 () ) ;
}
T_5 void F_32 ( struct V_70 * V_71 )
{
F_33 () ;
F_34 () ;
F_35 ( V_72 ) ;
F_36 () ;
F_37 () ;
F_38 () ;
}
static int F_39 ( struct V_31 * V_32 )
{
if ( ! V_73 )
return 0 ;
if ( ! F_11 ( V_32 , V_74 ) || ! F_11 ( V_32 , V_75 ) )
return 0 ;
return 1 ;
}
void T_3 F_40 ( void )
{
if ( F_39 ( & V_76 ) )
V_77 = F_41 ( V_78 ) ;
}
void F_42 ( struct V_31 * V_32 )
{
unsigned int V_29 = F_2 () ;
int V_79 = 0 ;
T_6 V_80 , V_81 ;
if ( ! F_39 ( V_32 ) )
return;
F_43 ( V_82 , V_80 , V_81 ) ;
V_81 = V_77 ;
if ( ( V_81 & V_83 ) != V_84 )
F_44 ( V_78 , V_77 ) ;
if ( ( V_80 & V_85 ) && ( V_81 & V_86 ) ) {
F_6 ( V_87
L_8 , V_29 ) ;
return;
}
if ( V_81 & V_88 ) {
F_6 ( V_87
L_9 ,
V_29 , ( V_81 & V_88 ) ) ;
return;
}
if ( F_11 ( V_32 , V_89 ) ) {
if ( V_32 -> V_90 == 6 && ( V_32 -> V_91 == 9 || V_32 -> V_91 == 13 ) ) {
F_43 ( V_92 , V_80 , V_81 ) ;
if ( V_80 & V_93 )
V_79 = 1 ;
} else if ( V_80 & V_94 )
V_79 = 1 ;
}
V_81 = V_95 | V_84 | V_96 ;
F_44 ( V_78 , V_81 ) ;
F_43 ( V_97 , V_80 , V_81 ) ;
if ( F_11 ( V_32 , V_35 ) )
F_45 ( V_97 ,
V_80 | ( V_98
| V_99 | V_100 ) , V_81 ) ;
else
F_45 ( V_97 ,
V_80 | ( V_98 | V_99 ) , V_81 ) ;
if ( F_11 ( V_32 , V_39 ) ) {
F_43 ( V_101 , V_80 , V_81 ) ;
if ( F_11 ( V_32 , V_35 ) )
F_45 ( V_101 ,
V_80 | ( V_102
| V_103
| V_104 ) , V_81 ) ;
else
F_45 ( V_101 ,
V_80 | ( V_102
| V_103 ) , V_81 ) ;
}
F_36 = F_27 ;
F_43 ( V_82 , V_80 , V_81 ) ;
F_45 ( V_82 , V_80 | V_85 , V_81 ) ;
V_80 = F_41 ( V_78 ) ;
F_44 ( V_78 , V_80 & ~ V_96 ) ;
F_46 ( V_24 L_10 ,
V_79 ? L_11 : L_12 ) ;
F_47 ( & V_53 , 1 ) ;
}
