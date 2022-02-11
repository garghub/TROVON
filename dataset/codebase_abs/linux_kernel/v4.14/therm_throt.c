static void F_1 ( bool V_1 , int V_2 , int V_3 )
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
return;
} else if ( V_3 == V_16 ) {
if ( V_2 == V_12 )
V_5 = & V_10 -> V_17 ;
else if ( V_2 == V_14 )
V_5 = & V_10 -> V_18 ;
else
return;
} else
return;
V_7 = V_5 -> V_1 ;
V_5 -> V_1 = V_1 ;
if ( V_1 )
V_5 -> V_19 ++ ;
if ( F_5 ( V_8 , V_5 -> V_20 ) &&
V_5 -> V_19 != V_5 -> V_21 )
return;
V_5 -> V_20 = V_8 + V_22 ;
V_5 -> V_21 = V_5 -> V_19 ;
if ( V_1 ) {
if ( V_2 == V_12 )
F_6 ( L_1 ,
V_6 ,
V_3 == V_11 ? L_2 : L_3 ,
V_5 -> V_19 ) ;
return;
}
if ( V_7 ) {
if ( V_2 == V_12 )
F_7 ( L_4 , V_6 ,
V_3 == V_11 ? L_2 : L_3 ) ;
return;
}
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
static int F_17 ( unsigned int V_31 )
{
struct V_29 * V_30 = F_18 ( V_31 ) ;
return F_10 ( V_30 , V_31 ) ;
}
static int F_19 ( unsigned int V_31 )
{
struct V_29 * V_30 = F_18 ( V_31 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static T_2 int F_20 ( void )
{
int V_44 ;
if ( ! F_21 ( & V_45 ) )
return 0 ;
V_44 = F_22 ( V_46 , L_5 ,
F_17 ,
F_19 ) ;
return V_44 < 0 ? V_44 : 0 ;
}
static void F_23 ( T_3 V_47 )
{
bool V_48 = false ;
bool V_49 = false ;
if ( ! V_50 )
return;
if ( V_47 & V_51 )
V_48 = true ;
if ( V_47 & V_52 )
V_49 = true ;
if ( ! V_48 && ! V_49 )
return;
if ( V_53 &&
V_53 () ) {
V_50 ( V_47 ) ;
return;
}
if ( V_48 && F_8 ( V_16 , 0 ) )
V_50 ( V_47 ) ;
if ( V_49 && F_8 ( V_16 , 1 ) )
V_50 ( V_47 ) ;
}
static void F_24 ( T_3 V_47 )
{
if ( ! V_54 )
return;
if ( ( V_47 & V_51 ) &&
F_8 ( V_11 , 0 ) )
V_54 ( V_47 ) ;
if ( ( V_47 & V_52 ) &&
F_8 ( V_11 , 1 ) )
V_54 ( V_47 ) ;
}
static void F_25 ( void )
{
T_3 V_47 ;
if ( F_26 ( V_55 ) )
F_27 ( V_56 , 0 ) ;
F_28 ( V_57 , V_47 ) ;
F_24 ( V_47 ) ;
F_1 ( V_47 & V_58 ,
V_12 ,
V_11 ) ;
if ( F_29 ( V_37 ) && V_28 )
F_1 ( V_47 & V_59 ,
V_14 ,
V_11 ) ;
if ( F_29 ( V_41 ) ) {
F_28 ( V_60 , V_47 ) ;
F_23 ( V_47 ) ;
F_1 ( V_47 & V_61 ,
V_12 ,
V_16 ) ;
if ( F_29 ( V_37 ) && V_28 )
F_1 ( V_47 &
V_62 ,
V_14 ,
V_16 ) ;
}
}
static void F_30 ( void )
{
F_31 ( L_6 ,
F_2 () ) ;
}
T_4 T_5 void T_6 F_32 ( struct V_63 * V_64 )
{
F_33 () ;
F_34 ( V_65 ) ;
F_35 ( V_66 ) ;
F_36 () ;
F_37 ( V_65 ) ;
F_38 () ;
}
static int F_39 ( struct V_33 * V_34 )
{
if ( ! F_40 ( V_67 ) )
return 0 ;
if ( ! F_13 ( V_34 , V_68 ) || ! F_13 ( V_34 , V_69 ) )
return 0 ;
return 1 ;
}
void T_2 F_41 ( void )
{
if ( F_39 ( & V_70 ) )
V_71 = F_42 ( V_72 ) ;
}
void F_43 ( struct V_33 * V_34 )
{
unsigned int V_31 = F_2 () ;
int V_73 = 0 ;
T_7 V_74 , V_75 ;
if ( ! F_39 ( V_34 ) )
return;
F_44 ( V_76 , V_74 , V_75 ) ;
V_75 = V_71 ;
if ( ( V_75 & V_77 ) != V_78 )
F_45 ( V_72 , V_71 ) ;
if ( ( V_74 & V_79 ) && ( V_75 & V_80 ) ) {
if ( V_81 == V_82 )
F_46 ( L_7 , V_31 ) ;
return;
}
if ( F_13 ( V_34 , V_83 ) ) {
if ( V_34 -> V_84 == 6 && ( V_34 -> V_85 == 9 || V_34 -> V_85 == 13 ) ) {
F_44 ( V_86 , V_74 , V_75 ) ;
if ( V_74 & V_87 )
V_73 = 1 ;
} else if ( V_74 & V_88 )
V_73 = 1 ;
}
V_75 = V_65 | V_78 | V_89 ;
F_45 ( V_72 , V_75 ) ;
F_44 ( V_90 , V_74 , V_75 ) ;
if ( F_13 ( V_34 , V_37 ) && ! V_28 )
F_47 ( V_90 ,
( V_74 | ( V_91
| V_92 ) ) & ~ V_93 , V_75 ) ;
else if ( F_13 ( V_34 , V_37 ) && V_28 )
F_47 ( V_90 ,
V_74 | ( V_91
| V_92 | V_93 ) , V_75 ) ;
else
F_47 ( V_90 ,
V_74 | ( V_91 | V_92 ) , V_75 ) ;
if ( F_13 ( V_34 , V_41 ) ) {
F_44 ( V_94 , V_74 , V_75 ) ;
if ( F_13 ( V_34 , V_37 ) && ! V_28 )
F_47 ( V_94 ,
( V_74 | ( V_95
| V_96 ) )
& ~ V_97 , V_75 ) ;
else if ( F_13 ( V_34 , V_37 ) && V_28 )
F_47 ( V_94 ,
V_74 | ( V_95
| V_96
| V_97 ) , V_75 ) ;
else
F_47 ( V_94 ,
V_74 | ( V_95
| V_96 ) , V_75 ) ;
}
F_36 = F_25 ;
F_44 ( V_76 , V_74 , V_75 ) ;
F_47 ( V_76 , V_74 | V_79 , V_75 ) ;
V_74 = F_42 ( V_72 ) ;
F_45 ( V_72 , V_74 & ~ V_89 ) ;
F_48 ( L_8 ,
V_73 ? L_9 : L_10 ) ;
F_49 ( & V_45 , 1 ) ;
}
