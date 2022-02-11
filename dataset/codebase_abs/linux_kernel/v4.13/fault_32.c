static void T_1 F_1 ( unsigned long V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( ( unsigned long ) V_1 < V_6 ) {
F_2 ( V_7
L_1 ) ;
} else {
F_2 ( V_7 L_2 ,
V_1 ) ;
}
F_2 ( V_7 L_3 ,
( V_3 -> V_8 ? V_3 -> V_8 -> V_9 : V_3 -> V_10 -> V_9 ) ) ;
F_2 ( V_7 L_4 ,
( V_3 -> V_8 ? ( unsigned long ) V_3 -> V_8 -> V_11 :
( unsigned long ) V_3 -> V_10 -> V_11 ) ) ;
F_3 ( L_5 , V_5 ) ;
}
T_2 int F_4 ( unsigned long V_12 , unsigned long V_13 ,
unsigned long V_1 )
{
struct V_4 V_5 ;
unsigned long V_14 ;
unsigned int V_15 ;
int V_16 ;
V_16 = F_5 ( V_13 , & V_14 ) ;
switch ( V_16 ) {
case 3 :
return 3 ;
case 1 :
V_15 = * ( ( unsigned int * ) V_12 ) ;
if ( ( V_15 >> 21 ) & 1 )
return 1 ;
break;
case 2 :
V_15 = * ( ( unsigned int * ) V_12 ) ;
if ( ! ( ( V_15 >> 21 ) & 1 ) || ( ( V_15 >> 19 ) & 0x3f ) == 15 )
return 2 ;
break;
default:
break;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_12 = V_12 ;
V_5 . V_17 = V_12 + 4 ;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"nop\n\t"
"nop\n\t"
"nop\n" : "=r" (regs.psr));
F_1 ( V_1 , V_18 , & V_5 ) ;
return 0 ;
}
static inline void
F_6 ( struct V_4 * V_5 , int V_19 , int V_20 ,
unsigned long V_1 , struct V_2 * V_3 )
{
if ( ! F_7 ( V_3 , V_19 ) )
return;
if ( ! F_8 () )
return;
F_2 ( L_6 ,
F_9 ( V_3 ) > 1 ? V_21 : V_22 ,
V_3 -> V_23 , F_9 ( V_3 ) , V_1 ,
( void * ) V_5 -> V_12 , ( void * ) V_5 -> V_24 [ V_25 ] ,
( void * ) V_5 -> V_24 [ V_26 ] , V_20 ) ;
F_10 ( V_27 L_7 , V_5 -> V_12 ) ;
F_2 ( V_27 L_8 ) ;
}
static void F_11 ( int V_20 , int V_19 , struct V_4 * V_5 ,
unsigned long V_28 )
{
T_3 V_29 ;
V_29 . V_30 = V_19 ;
V_29 . V_31 = V_20 ;
V_29 . V_32 = 0 ;
V_29 . V_33 = ( void V_34 * ) V_28 ;
V_29 . V_35 = 0 ;
if ( F_12 ( V_36 ) )
F_6 ( V_5 , V_19 , V_29 . V_31 ,
V_28 , V_18 ) ;
F_13 ( V_19 , & V_29 , V_18 ) ;
}
static unsigned long F_14 ( struct V_4 * V_5 , int V_37 )
{
unsigned int V_15 ;
if ( V_37 )
return V_5 -> V_12 ;
if ( V_5 -> V_38 & V_39 )
V_15 = * ( unsigned int * ) V_5 -> V_12 ;
else
F_15 ( V_15 , ( unsigned int * ) V_5 -> V_12 ) ;
return F_16 ( V_5 , V_15 ) ;
}
static T_4 void F_17 ( int V_20 , int V_19 , struct V_4 * V_5 ,
int V_37 )
{
unsigned long V_28 = F_14 ( V_5 , V_37 ) ;
F_11 ( V_20 , V_19 , V_5 , V_28 ) ;
}
T_2 void F_18 ( struct V_4 * V_5 , int V_37 , int V_40 ,
unsigned long V_1 )
{
struct V_41 * V_42 ;
struct V_2 * V_3 = V_18 ;
struct V_43 * V_8 = V_3 -> V_8 ;
unsigned int V_44 ;
unsigned long V_14 ;
int V_45 = ! ( V_5 -> V_38 & V_39 ) ;
int V_46 , V_20 ;
unsigned int V_47 = V_48 | V_49 ;
if ( V_37 )
V_1 = V_5 -> V_12 ;
V_20 = V_50 ;
if ( V_1 >= V_51 )
goto V_52;
if ( F_19 () || ! V_8 )
goto V_53;
F_20 ( V_54 , 1 , V_5 , V_1 ) ;
V_55:
F_21 ( & V_8 -> V_56 ) ;
if ( ! V_45 && V_1 >= V_57 )
goto V_58;
V_42 = F_22 ( V_8 , V_1 ) ;
if ( ! V_42 )
goto V_58;
if ( V_42 -> V_59 <= V_1 )
goto V_60;
if ( ! ( V_42 -> V_61 & V_62 ) )
goto V_58;
if ( F_23 ( V_42 , V_1 ) )
goto V_58;
V_60:
V_20 = V_63 ;
if ( V_40 ) {
if ( ! ( V_42 -> V_61 & V_64 ) )
goto V_58;
} else {
if ( ! ( V_42 -> V_61 & ( V_65 | V_66 ) ) )
goto V_58;
}
if ( V_45 )
V_47 |= V_67 ;
if ( V_40 )
V_47 |= V_68 ;
V_46 = F_24 ( V_42 , V_1 , V_47 ) ;
if ( ( V_46 & V_69 ) && F_25 ( V_18 ) )
return;
if ( F_12 ( V_46 & V_70 ) ) {
if ( V_46 & V_71 )
goto V_72;
else if ( V_46 & V_73 )
goto V_58;
else if ( V_46 & V_74 )
goto V_75;
F_26 () ;
}
if ( V_47 & V_48 ) {
if ( V_46 & V_76 ) {
V_18 -> V_77 ++ ;
F_20 ( V_78 ,
1 , V_5 , V_1 ) ;
} else {
V_18 -> V_79 ++ ;
F_20 ( V_80 ,
1 , V_5 , V_1 ) ;
}
if ( V_46 & V_69 ) {
V_47 &= ~ V_48 ;
V_47 |= V_81 ;
goto V_55;
}
}
F_27 ( & V_8 -> V_56 ) ;
return;
V_58:
F_27 ( & V_8 -> V_56 ) ;
V_82:
if ( V_45 ) {
F_17 ( V_20 , V_83 , V_5 , V_37 ) ;
return;
}
V_53:
V_14 = V_5 -> V_24 [ V_84 ] ;
if ( ! V_45 ) {
V_44 = F_5 ( V_5 -> V_12 , & V_14 ) ;
if ( V_44 > 10 ) {
extern const unsigned int V_85 [] ;
extern const unsigned int V_86 [] ;
extern const unsigned int V_87 [] ;
extern const unsigned int V_88 [] ;
#ifdef F_28
F_2 ( L_9 ,
V_5 -> V_12 , V_1 ) ;
F_2 ( L_10 ,
V_5 -> V_12 , V_44 , V_14 ) ;
#endif
if ( ( V_5 -> V_12 >= ( unsigned long ) V_85 &&
V_5 -> V_12 < ( unsigned long ) V_86 ) ||
( V_5 -> V_12 >= ( unsigned long ) V_87 &&
V_5 -> V_12 < ( unsigned long ) V_88 ) ) {
V_5 -> V_24 [ V_89 ] = V_1 ;
V_5 -> V_24 [ V_90 ] = V_5 -> V_12 ;
}
V_5 -> V_24 [ V_84 ] = V_14 ;
V_5 -> V_12 = V_44 ;
V_5 -> V_17 = V_5 -> V_12 + 4 ;
return;
}
}
F_1 ( V_1 , V_3 , V_5 ) ;
F_29 ( V_91 ) ;
V_72:
F_27 ( & V_8 -> V_56 ) ;
if ( V_45 ) {
F_30 () ;
return;
}
goto V_53;
V_75:
F_27 ( & V_8 -> V_56 ) ;
F_17 ( V_92 , V_93 , V_5 , V_37 ) ;
if ( ! V_45 )
goto V_53;
V_52:
{
int V_94 = F_31 ( V_1 ) ;
T_5 * V_11 , * V_95 ;
T_6 * V_96 , * V_97 ;
V_11 = V_3 -> V_10 -> V_11 + V_94 ;
V_95 = V_98 . V_11 + V_94 ;
if ( ! F_32 ( * V_11 ) ) {
if ( ! F_32 ( * V_95 ) )
goto V_82;
F_33 ( * V_11 ) = F_33 ( * V_95 ) ;
return;
}
V_96 = F_34 ( V_11 , V_1 ) ;
V_97 = F_34 ( V_95 , V_1 ) ;
if ( F_35 ( * V_96 ) || ! F_35 ( * V_97 ) )
goto V_82;
* V_96 = * V_97 ;
return;
}
}
static void F_36 ( unsigned long V_1 , int V_40 )
{
struct V_41 * V_42 ;
struct V_2 * V_3 = V_18 ;
struct V_43 * V_8 = V_3 -> V_8 ;
unsigned int V_47 = V_67 ;
int V_20 ;
V_20 = V_50 ;
F_21 ( & V_8 -> V_56 ) ;
V_42 = F_22 ( V_8 , V_1 ) ;
if ( ! V_42 )
goto V_58;
if ( V_42 -> V_59 <= V_1 )
goto V_60;
if ( ! ( V_42 -> V_61 & V_62 ) )
goto V_58;
if ( F_23 ( V_42 , V_1 ) )
goto V_58;
V_60:
V_20 = V_63 ;
if ( V_40 ) {
if ( ! ( V_42 -> V_61 & V_64 ) )
goto V_58;
V_47 |= V_68 ;
} else {
if ( ! ( V_42 -> V_61 & ( V_65 | V_66 ) ) )
goto V_58;
}
switch ( F_24 ( V_42 , V_1 , V_47 ) ) {
case V_74 :
case V_71 :
goto V_75;
}
F_27 ( & V_8 -> V_56 ) ;
return;
V_58:
F_27 ( & V_8 -> V_56 ) ;
F_11 ( V_20 , V_83 , V_3 -> V_99 . V_100 , V_1 ) ;
return;
V_75:
F_27 ( & V_8 -> V_56 ) ;
F_11 ( V_92 , V_93 , V_3 -> V_99 . V_100 , V_1 ) ;
}
static void F_37 ( unsigned long V_101 )
{
if ( V_101 & 0x7UL )
F_38 ( V_102 , V_18 ) ;
}
void F_39 ( void )
{
unsigned long V_101 ;
V_101 = F_40 () -> V_103 [ 0 ] ;
if ( ( ( V_101 + 0x38 ) & V_104 ) != ( V_101 & V_104 ) )
F_36 ( V_101 + 0x38 , 1 ) ;
F_36 ( V_101 , 1 ) ;
F_37 ( V_101 ) ;
}
void F_41 ( unsigned long V_101 )
{
if ( ( ( V_101 + 0x38 ) & V_104 ) != ( V_101 & V_104 ) )
F_36 ( V_101 + 0x38 , 0 ) ;
F_36 ( V_101 , 0 ) ;
F_37 ( V_101 ) ;
}
void F_42 ( struct V_4 * V_5 )
{
unsigned long V_101 ;
V_101 = V_5 -> V_24 [ V_26 ] ;
if ( ( ( V_101 + 0x38 ) & V_104 ) != ( V_101 & V_104 ) )
F_36 ( V_101 + 0x38 , 0 ) ;
F_36 ( V_101 , 0 ) ;
F_37 ( V_101 ) ;
}
