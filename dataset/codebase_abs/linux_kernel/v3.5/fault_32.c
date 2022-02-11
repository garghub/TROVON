unsigned long F_1 ( void )
{
unsigned long V_1 = 0 ;
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 ; V_2 ++ )
V_1 += V_3 [ V_2 ] . V_4 ;
return V_1 ;
}
static void T_1 F_2 ( unsigned long V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
if ( ( unsigned long ) V_5 < V_10 ) {
F_3 ( V_11
L_1 ) ;
} else {
F_3 ( V_11 L_2 ,
V_5 ) ;
}
F_3 ( V_11 L_3 ,
( V_7 -> V_12 ? V_7 -> V_12 -> V_13 : V_7 -> V_14 -> V_13 ) ) ;
F_3 ( V_11 L_4 ,
( V_7 -> V_12 ? ( unsigned long ) V_7 -> V_12 -> V_15 :
( unsigned long ) V_7 -> V_14 -> V_15 ) ) ;
F_4 ( L_5 , V_9 ) ;
}
T_2 int F_5 ( unsigned long V_16 , unsigned long V_17 ,
unsigned long V_5 )
{
struct V_8 V_9 ;
unsigned long V_18 ;
unsigned int V_19 ;
int V_2 ;
V_2 = F_6 ( V_17 , & V_18 ) ;
switch ( V_2 ) {
case 3 :
return 3 ;
case 1 :
V_19 = * ( ( unsigned int * ) V_16 ) ;
if ( ( V_19 >> 21 ) & 1 )
return 1 ;
break;
case 2 :
V_19 = * ( ( unsigned int * ) V_16 ) ;
if ( ! ( ( V_19 >> 21 ) & 1 ) || ( ( V_19 >> 19 ) & 0x3f ) == 15 )
return 2 ;
break;
default:
break;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_16 ;
V_9 . V_20 = V_16 + 4 ;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"nop\n\t"
"nop\n\t"
"nop\n" : "=r" (regs.psr));
F_2 ( V_5 , V_21 , & V_9 ) ;
return 0 ;
}
static inline void
F_7 ( struct V_8 * V_9 , int V_22 , int V_23 ,
unsigned long V_5 , struct V_6 * V_7 )
{
if ( ! F_8 ( V_7 , V_22 ) )
return;
if ( ! F_9 () )
return;
F_3 ( L_6 ,
F_10 ( V_7 ) > 1 ? V_24 : V_25 ,
V_7 -> V_26 , F_10 ( V_7 ) , V_5 ,
( void * ) V_9 -> V_16 , ( void * ) V_9 -> V_27 [ V_28 ] ,
( void * ) V_9 -> V_27 [ V_29 ] , V_23 ) ;
F_11 ( V_30 L_7 , V_9 -> V_16 ) ;
F_3 ( V_30 L_8 ) ;
}
static void F_12 ( int V_23 , int V_22 , struct V_8 * V_9 ,
unsigned long V_31 )
{
T_3 V_32 ;
V_32 . V_33 = V_22 ;
V_32 . V_34 = V_23 ;
V_32 . V_35 = 0 ;
V_32 . V_36 = ( void V_37 * ) V_31 ;
V_32 . V_38 = 0 ;
if ( F_13 ( V_39 ) )
F_7 ( V_9 , V_22 , V_32 . V_34 ,
V_31 , V_21 ) ;
F_14 ( V_22 , & V_32 , V_21 ) ;
}
static unsigned long F_15 ( struct V_8 * V_9 , int V_40 )
{
unsigned int V_19 ;
if ( V_40 )
return V_9 -> V_16 ;
if ( V_9 -> V_41 & V_42 )
V_19 = * ( unsigned int * ) V_9 -> V_16 ;
else
F_16 ( V_19 , ( unsigned int * ) V_9 -> V_16 ) ;
return F_17 ( V_9 , V_19 ) ;
}
static T_4 void F_18 ( int V_23 , int V_22 , struct V_8 * V_9 ,
int V_40 )
{
unsigned long V_31 = F_15 ( V_9 , V_40 ) ;
F_12 ( V_23 , V_22 , V_9 , V_31 ) ;
}
T_2 void F_19 ( struct V_8 * V_9 , int V_40 , int V_43 ,
unsigned long V_5 )
{
struct V_44 * V_45 ;
struct V_6 * V_7 = V_21 ;
struct V_46 * V_12 = V_7 -> V_12 ;
unsigned int V_47 ;
unsigned long V_18 ;
int V_48 = ! ( V_9 -> V_41 & V_42 ) ;
int V_49 , V_23 ;
unsigned int V_50 = ( V_51 | V_52 |
( V_43 ? V_53 : 0 ) ) ;
if ( V_40 )
V_5 = V_9 -> V_16 ;
V_23 = V_54 ;
if ( V_5 >= V_55 )
goto V_56;
if ( F_20 () || ! V_12 )
goto V_57;
F_21 ( V_58 , 1 , V_9 , V_5 ) ;
V_59:
F_22 ( & V_12 -> V_60 ) ;
if ( ! V_48 && V_5 >= V_61 )
goto V_62;
V_45 = F_23 ( V_12 , V_5 ) ;
if ( ! V_45 )
goto V_62;
if ( V_45 -> V_63 <= V_5 )
goto V_64;
if ( ! ( V_45 -> V_65 & V_66 ) )
goto V_62;
if ( F_24 ( V_45 , V_5 ) )
goto V_62;
V_64:
V_23 = V_67 ;
if ( V_43 ) {
if ( ! ( V_45 -> V_65 & V_68 ) )
goto V_62;
} else {
if ( ! ( V_45 -> V_65 & ( V_69 | V_70 ) ) )
goto V_62;
}
V_49 = F_25 ( V_12 , V_45 , V_5 , V_50 ) ;
if ( ( V_49 & V_71 ) && F_26 ( V_21 ) )
return;
if ( F_13 ( V_49 & V_72 ) ) {
if ( V_49 & V_73 )
goto V_74;
else if ( V_49 & V_75 )
goto V_76;
F_27 () ;
}
if ( V_50 & V_51 ) {
if ( V_49 & V_77 ) {
V_21 -> V_78 ++ ;
F_21 ( V_79 ,
1 , V_9 , V_5 ) ;
} else {
V_21 -> V_80 ++ ;
F_21 ( V_81 ,
1 , V_9 , V_5 ) ;
}
if ( V_49 & V_71 ) {
V_50 &= ~ V_51 ;
goto V_59;
}
}
F_28 ( & V_12 -> V_60 ) ;
return;
V_62:
F_28 ( & V_12 -> V_60 ) ;
V_82:
if ( V_48 ) {
F_18 ( V_23 , V_83 , V_9 , V_40 ) ;
return;
}
V_57:
V_18 = V_9 -> V_27 [ V_84 ] ;
if ( ! V_48 ) {
V_47 = F_6 ( V_9 -> V_16 , & V_18 ) ;
if ( V_47 > 10 ) {
extern const unsigned V_85 [] ;
extern const unsigned V_86 [] ;
extern const unsigned V_87 [] ;
extern const unsigned V_88 [] ;
#ifdef F_29
F_3 ( L_9 ,
V_9 -> V_16 , V_5 ) ;
F_3 ( L_10 ,
V_9 -> V_16 , V_47 , V_18 ) ;
#endif
if ( ( V_9 -> V_16 >= ( unsigned long ) V_85 &&
V_9 -> V_16 < ( unsigned long ) V_86 ) ||
( V_9 -> V_16 >= ( unsigned long ) V_87 &&
V_9 -> V_16 < ( unsigned long ) V_88 ) ) {
V_9 -> V_27 [ V_89 ] = V_5 ;
V_9 -> V_27 [ V_90 ] = V_9 -> V_16 ;
}
V_9 -> V_27 [ V_84 ] = V_18 ;
V_9 -> V_16 = V_47 ;
V_9 -> V_20 = V_9 -> V_16 + 4 ;
return;
}
}
F_2 ( V_5 , V_7 , V_9 ) ;
F_30 ( V_91 ) ;
V_74:
F_28 ( & V_12 -> V_60 ) ;
if ( V_48 ) {
F_31 () ;
return;
}
goto V_57;
V_76:
F_28 ( & V_12 -> V_60 ) ;
F_18 ( V_92 , V_93 , V_9 , V_40 ) ;
if ( ! V_48 )
goto V_57;
V_56:
{
int V_94 = F_32 ( V_5 ) ;
T_5 * V_15 , * V_95 ;
T_6 * V_96 , * V_97 ;
V_15 = V_7 -> V_14 -> V_15 + V_94 ;
V_95 = V_98 . V_15 + V_94 ;
if ( ! F_33 ( * V_15 ) ) {
if ( ! F_33 ( * V_95 ) )
goto V_82;
F_34 ( * V_15 ) = F_34 ( * V_95 ) ;
return;
}
V_96 = F_35 ( V_15 , V_5 ) ;
V_97 = F_35 ( V_95 , V_5 ) ;
if ( F_36 ( * V_96 ) || ! F_36 ( * V_97 ) )
goto V_82;
* V_96 = * V_97 ;
return;
}
}
static void F_37 ( unsigned long V_5 , int V_43 )
{
struct V_44 * V_45 ;
struct V_6 * V_7 = V_21 ;
struct V_46 * V_12 = V_7 -> V_12 ;
int V_23 ;
V_23 = V_54 ;
F_22 ( & V_12 -> V_60 ) ;
V_45 = F_23 ( V_12 , V_5 ) ;
if ( ! V_45 )
goto V_62;
if ( V_45 -> V_63 <= V_5 )
goto V_64;
if ( ! ( V_45 -> V_65 & V_66 ) )
goto V_62;
if ( F_24 ( V_45 , V_5 ) )
goto V_62;
V_64:
V_23 = V_67 ;
if ( V_43 ) {
if ( ! ( V_45 -> V_65 & V_68 ) )
goto V_62;
} else {
if ( ! ( V_45 -> V_65 & ( V_69 | V_70 ) ) )
goto V_62;
}
switch ( F_25 ( V_12 , V_45 , V_5 , V_43 ? V_53 : 0 ) ) {
case V_75 :
case V_73 :
goto V_76;
}
F_28 ( & V_12 -> V_60 ) ;
return;
V_62:
F_28 ( & V_12 -> V_60 ) ;
F_12 ( V_23 , V_83 , V_7 -> V_99 . V_100 , V_5 ) ;
return;
V_76:
F_28 ( & V_12 -> V_60 ) ;
F_12 ( V_92 , V_93 , V_7 -> V_99 . V_100 , V_5 ) ;
}
static void F_38 ( unsigned long V_101 )
{
if ( V_101 & 0x7UL )
F_39 ( V_102 , V_21 ) ;
}
void F_40 ( void )
{
unsigned long V_101 ;
V_101 = F_41 () -> V_103 [ 0 ] ;
if ( ( ( V_101 + 0x38 ) & V_104 ) != ( V_101 & V_104 ) )
F_37 ( V_101 + 0x38 , 1 ) ;
F_37 ( V_101 , 1 ) ;
F_38 ( V_101 ) ;
}
void F_42 ( unsigned long V_101 )
{
if ( ( ( V_101 + 0x38 ) & V_104 ) != ( V_101 & V_104 ) )
F_37 ( V_101 + 0x38 , 0 ) ;
F_37 ( V_101 , 0 ) ;
F_38 ( V_101 ) ;
}
void F_43 ( struct V_8 * V_9 )
{
unsigned long V_101 ;
V_101 = V_9 -> V_27 [ V_29 ] ;
if ( ( ( V_101 + 0x38 ) & V_104 ) != ( V_101 & V_104 ) )
F_37 ( V_101 + 0x38 , 0 ) ;
F_37 ( V_101 , 0 ) ;
F_38 ( V_101 ) ;
}
