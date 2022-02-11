static inline int F_1 ( void )
{
int V_1 ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_2 ( V_7 , V_1 ) ;
V_1 &= 0xff ;
break;
case V_8 :
V_1 = F_3 ( V_9 ) ;
V_1 &= 0xff ;
break;
case V_10 :
V_11 = 0x20000 ;
( void ) V_11 ;
F_4 () ;
V_1 = F_5 ( ( V_12 * ) V_13 ) ;
F_4 () ;
V_1 &= 0xff ;
V_11 = 0 ;
break;
default:
F_6 ( L_1 ) ;
return - 1 ;
}
return V_1 ;
}
static inline int F_7 ( void )
{
unsigned long V_14 ;
int V_1 ;
F_8 ( & V_15 , V_14 ) ;
V_1 = F_1 () ;
F_9 ( & V_15 , V_14 ) ;
return V_1 ;
}
static void F_10 ( void )
{
int V_1 ;
V_1 = F_7 () ;
if ( V_1 < 0 ) {
return;
}
F_11 ( V_16 + V_1 ) ;
#ifdef F_12
if ( V_17 )
V_17 () ;
#endif
}
static T_1 F_13 ( int V_1 , void * V_18 )
{
F_10 () ;
return V_19 ;
}
static void F_14 ( void )
{
unsigned int V_20 , V_21 , V_22 , V_23 ;
unsigned int V_24 , V_25 , V_26 , V_27 ;
unsigned int V_28 , V_29 , V_30 ;
struct V_31 * V_32 = F_15 () ;
F_6 ( L_2 ) ;
F_6 ( L_3
L_4 ,
V_32 -> V_33 , V_32 -> V_34 ,
V_32 -> V_35 , V_32 -> V_36 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_16 () ;
break;
case V_8 :
V_28 = F_3 ( V_37 ) ;
V_29 = F_3 ( V_38 ) ;
V_30 = F_3 ( V_39 ) ;
F_6 ( L_5 , V_28 ) ;
F_6 ( L_6 ,
V_30 , V_29 ) ;
break;
case V_10 :
V_23 = V_40 ;
V_24 = V_41 ;
V_25 = V_42 ;
V_26 = V_43 ;
V_27 = V_44 ;
V_20 = V_45 ;
V_21 = V_46 ;
V_22 = V_47 ;
F_6 ( L_7 , V_25 ) ;
F_6 ( L_8 , V_26 ) ;
F_6 ( L_9 , V_27 ) ;
F_6 ( L_10 , V_20 ) ;
F_6 ( L_11 , V_21 ) ;
F_6 ( L_12 , V_22 ) ;
F_6 ( L_13 , V_23 ) ;
F_6 ( L_14 , V_24 ) ;
break;
}
F_17 ( L_15 , V_32 ) ;
}
static T_1 F_18 ( int V_1 , void * V_18 )
{
F_14 () ;
return V_19 ;
}
static void F_19 ( void )
{
F_11 ( V_48 + V_49 ) ;
}
static void F_20 ( void )
{
F_11 ( V_48 + V_50 ) ;
}
static T_1 F_21 ( int V_1 , void * V_18 )
{
#ifdef F_22
if ( V_17 )
V_17 () ;
#endif
F_23 () ;
return V_19 ;
}
static T_1 F_24 ( int V_1 , void * V_18 )
{
F_25 () ;
return V_19 ;
}
void T_2 F_26 ( int V_1 , struct V_51 * V_52 )
{
F_27 ( V_1 , V_52 ) ;
F_28 ( V_1 , V_53 ) ;
}
void T_2 F_29 ( void )
{
int V_54 , V_55 ;
F_30 () ;
if ( ! V_56 )
F_31 () ;
if ( F_32 () ) {
F_33 ( V_57 | V_58 ) ;
V_59 = 1 ;
} else {
if ( V_2 == V_4 ) {
V_60 = F_34 ( V_61 ,
V_62 ) ;
V_59 =
( F_5 ( V_60 + V_63 ) &
V_64 ) >>
V_65 ;
}
}
if ( V_59 )
F_35 ( L_16 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_56 )
F_36 ( V_66 ,
V_67 , V_68 ,
V_69 ) ;
else
F_36 ( V_66 ,
V_70 , V_71 ,
V_72 ) ;
break;
case V_5 :
case V_6 :
if ( V_56 )
F_36 ( V_73 ,
V_67 , V_68 ,
V_69 ) ;
else
F_36 ( V_73 ,
V_70 , V_71 ,
V_72 ) ;
}
if ( V_59 ) {
int V_74 ;
F_37 ( V_57 , V_75 , V_76 ,
V_77 ) ;
if ( ! F_32 () ) {
V_74 = F_5 ( V_60 + V_63 ) ;
F_38 ( V_74 | ( 0x1 << V_78 ) ,
V_60 + V_63 ) ;
F_35 ( L_17 ) ;
}
V_55 = V_77 + V_79 ;
V_54 = V_48 + V_80 ;
} else {
#if F_39 ( V_81 )
if ( V_56 ) {
F_40 ( V_82 , F_19 ) ;
F_40 ( V_83 , F_20 ) ;
V_84 = V_82 ;
V_85 = V_83 ;
} else {
V_84 = V_48 +
V_49 ;
V_85 = V_48 +
V_50 ;
}
F_26 ( V_84 , & V_86 ) ;
F_26 ( V_85 , & V_87 ) ;
#endif
if ( V_56 ) {
F_40 ( V_88 ,
F_10 ) ;
F_40 ( V_89 ,
F_14 ) ;
V_55 = V_67 + V_88 ;
V_54 = V_67 + V_89 ;
} else {
V_55 = V_48 + V_90 ;
V_54 = V_48 + V_80 ;
}
}
F_27 ( V_55 , & V_91 ) ;
F_27 ( V_54 , & V_92 ) ;
}
void F_41 ( void )
{
}
int F_42 ( struct V_31 * V_32 , int V_93 )
{
int V_94 = V_93 ? V_95 : V_96 ;
F_43 () ;
return V_94 ;
}
