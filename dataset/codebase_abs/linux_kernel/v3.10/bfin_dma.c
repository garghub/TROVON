static int T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 L_1 ) ;
#if V_3
F_3 ( 0x0111 ) ;
#endif
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
F_4 ( & V_5 [ V_1 ] . V_6 , 0 ) ;
V_5 [ V_1 ] . V_7 = V_8 [ V_1 ] ;
}
#if F_5 ( V_9 ) && F_5 ( V_10 )
F_6 ( V_11 , L_2 ) ;
F_6 ( V_9 , L_2 ) ;
#else
F_6 ( V_12 , L_2 ) ;
F_6 ( V_13 , L_2 ) ;
#endif
#if F_5 ( V_14 )
F_7 ( F_8 ()
| V_15 | V_16 | V_17 ) ;
#endif
return 0 ;
}
static int F_9 ( struct V_18 * V_19 , void * V_20 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 )
if ( F_10 ( V_1 ) )
F_11 ( V_19 , L_3 , V_1 , V_5 [ V_1 ] . V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
return F_13 ( V_23 , F_9 , NULL ) ;
}
static int T_1 F_14 ( void )
{
F_15 ( L_4 , 0 , NULL , & V_24 ) ;
return 0 ;
}
static void F_16 ( unsigned int V_25 , const char * V_21 )
{
#ifdef F_17
unsigned int V_26 ;
switch ( V_25 ) {
case V_27 : V_26 = 0xC << 12 ; break;
case V_28 : V_26 = 0xD << 12 ; break;
case V_29 : V_26 = 0xE << 12 ; break;
case V_30 : V_26 = 0xF << 12 ; break;
default: return;
}
if ( strncmp ( V_21 , L_5 , 9 ) == 0 )
V_5 [ V_25 ] . V_7 -> V_31 = V_26 ;
#endif
}
int F_6 ( unsigned int V_25 , const char * V_21 )
{
F_18 ( L_6 ) ;
if ( V_21 == NULL )
F_2 ( V_32 L_7 , V_25 ) ;
#if F_5 ( V_33 ) && V_34
if ( V_25 >= V_35 && V_25 <= V_36 ) {
if ( F_19 () > 500000000 ) {
F_2 ( V_32
L_8 ) ;
return - V_37 ;
}
}
#endif
if ( F_20 ( & V_5 [ V_25 ] . V_6 , 0 , 1 ) ) {
F_18 ( L_9 ) ;
return - V_38 ;
}
F_16 ( V_25 , V_21 ) ;
V_5 [ V_25 ] . V_21 = V_21 ;
V_5 [ V_25 ] . V_39 = 0 ;
F_18 ( L_10 ) ;
return 0 ;
}
int F_21 ( unsigned int V_25 , T_2 V_40 , void * V_41 )
{
int V_42 ;
unsigned int V_39 ;
F_22 ( V_25 >= V_4 || ! V_40 ||
! F_23 ( & V_5 [ V_25 ] . V_6 ) ) ;
V_39 = F_24 ( V_25 ) ;
V_42 = F_25 ( V_39 , V_40 , 0 , V_5 [ V_25 ] . V_21 , V_41 ) ;
if ( V_42 )
return V_42 ;
V_5 [ V_25 ] . V_39 = V_39 ;
V_5 [ V_25 ] . V_41 = V_41 ;
return 0 ;
}
static void F_26 ( unsigned int V_25 )
{
V_5 [ V_25 ] . V_7 -> V_43 |= V_44 ;
F_27 () ;
V_5 [ V_25 ] . V_7 -> V_43 &= ~ V_44 ;
}
void F_28 ( unsigned int V_25 )
{
F_18 ( L_11 ) ;
F_22 ( V_25 >= V_4 ||
! F_23 ( & V_5 [ V_25 ] . V_6 ) ) ;
F_29 ( V_25 ) ;
F_26 ( V_25 ) ;
if ( V_5 [ V_25 ] . V_39 )
F_30 ( V_5 [ V_25 ] . V_39 , V_5 [ V_25 ] . V_41 ) ;
F_4 ( & V_5 [ V_25 ] . V_6 , 0 ) ;
F_18 ( L_12 ) ;
}
int F_31 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 ) {
if ( V_5 [ V_1 ] . V_7 -> V_43 & V_45 ) {
F_2 ( V_46 L_13 , V_1 ) ;
return - V_38 ;
}
if ( V_1 < V_47 )
V_5 [ V_1 ] . V_48 = V_5 [ V_1 ] . V_7 -> V_31 ;
}
#if V_3
F_3 ( 0x0 ) ;
#endif
return 0 ;
}
void F_32 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 ) {
V_5 [ V_1 ] . V_7 -> V_43 = 0 ;
if ( V_1 < V_47 )
V_5 [ V_1 ] . V_7 -> V_31 = V_5 [ V_1 ] . V_48 ;
}
#if V_3
F_3 ( 0x0111 ) ;
#endif
}
int F_31 ( void )
{
return 0 ;
}
void F_32 ( void )
{
}
void T_1 F_33 ( void )
{
F_34 () ;
F_35 ( 0 ) ;
F_36 ( 0 ) ;
}
void T_1 F_37 ( void * V_49 , const void * V_50 , T_3 V_51 )
{
unsigned long V_52 = ( unsigned long ) V_49 ;
unsigned long V_53 = ( unsigned long ) V_50 ;
struct V_54 * V_55 , * V_56 ;
F_34 () ;
F_22 ( V_52 % 4 ) ;
F_22 ( V_53 % 4 ) ;
F_22 ( V_51 % 4 ) ;
V_56 = 0 ;
while ( 1 ) {
if ( V_56 == (struct V_54 * ) V_57 ) {
V_55 = (struct V_54 * ) V_58 ;
V_56 = (struct V_54 * ) V_59 ;
} else {
V_55 = (struct V_54 * ) V_60 ;
V_56 = (struct V_54 * ) V_57 ;
}
if ( ! F_38 ( & V_56 -> V_43 ) )
break;
else if ( F_38 ( & V_55 -> V_61 ) & V_62 ) {
F_39 ( & V_56 -> V_43 , 0 ) ;
break;
}
}
F_40 () ;
F_41 ( & V_55 -> V_63 , V_52 ) ;
F_39 ( & V_55 -> V_64 , V_51 >> 2 ) ;
F_39 ( & V_55 -> V_65 , 1 << 2 ) ;
F_39 ( & V_55 -> V_61 , V_62 | V_66 ) ;
F_41 ( & V_56 -> V_63 , V_53 ) ;
F_39 ( & V_56 -> V_64 , V_51 >> 2 ) ;
F_39 ( & V_56 -> V_65 , 1 << 2 ) ;
F_39 ( & V_56 -> V_61 , V_62 | V_66 ) ;
F_39 ( & V_56 -> V_43 , V_45 | V_67 ) ;
F_39 ( & V_55 -> V_43 , V_68 | V_69 | V_45 | V_67 ) ;
F_40 () ;
#ifdef V_10
while ( ! ( F_38 ( & V_55 -> V_61 ) & V_62 ) )
continue;
#endif
}
void T_1 F_42 ( void )
{
F_34 () ;
while ( ( F_43 () && ! ( F_44 () & V_62 ) ) ||
( F_45 () && ! ( F_46 () & V_62 ) ) )
continue;
F_47 ( V_62 | V_66 ) ;
F_48 ( V_62 | V_66 ) ;
F_35 ( 0 ) ;
F_36 ( 0 ) ;
F_49 ( 0 ) ;
F_50 ( 0 ) ;
F_40 () ;
}
static void F_51 ( T_4 V_70 , T_5 V_71 , T_4 V_72 , T_5 V_73 , T_3 V_74 , T_4 V_75 )
{
static F_52 ( V_76 ) ;
unsigned long V_77 ;
F_53 ( & V_76 , V_77 ) ;
F_40 () ;
if ( F_54 () )
while ( ! ( F_55 () & V_62 ) )
continue;
if ( V_75 & V_78 ) {
T_4 V_79 = abs ( V_71 ) >> 1 ;
T_3 V_80 = V_74 >> ( 16 - V_79 ) ;
V_74 = 1 << ( 16 - V_79 ) ;
F_56 ( V_80 ) ;
F_57 ( V_80 ) ;
F_58 ( V_71 ) ;
F_59 ( V_73 ) ;
}
F_60 ( V_70 ) ;
F_61 ( V_74 ) ;
F_62 ( V_71 ) ;
F_63 ( V_62 | V_66 ) ;
F_64 ( V_72 ) ;
F_65 ( V_74 ) ;
F_66 ( V_73 ) ;
F_67 ( V_62 | V_66 ) ;
F_68 ( V_45 | V_75 ) ;
if ( V_75 & V_78 )
F_69 ( V_68 | V_81 | V_45 | V_75 ) ;
else
F_69 ( V_68 | V_69 | V_45 | V_75 ) ;
F_70 ( & V_76 , V_77 ) ;
F_27 () ;
while ( ! ( F_55 () & V_62 ) )
if ( F_54 () )
continue;
else
return;
F_63 ( V_62 | V_66 ) ;
F_68 ( 0 ) ;
F_69 ( 0 ) ;
}
static void * F_71 ( void * V_49 , const void * V_50 , T_3 V_51 )
{
T_4 V_75 , V_79 ;
T_5 V_82 ;
unsigned long V_52 = ( unsigned long ) V_49 ;
unsigned long V_53 = ( unsigned long ) V_50 ;
if ( V_51 == 0 )
return NULL ;
if ( V_52 % 4 == 0 && V_53 % 4 == 0 && V_51 % 4 == 0 ) {
V_75 = V_67 ;
V_79 = 2 ;
} else if ( V_52 % 2 == 0 && V_53 % 2 == 0 && V_51 % 2 == 0 ) {
V_75 = V_83 ;
V_79 = 1 ;
} else {
V_75 = V_84 ;
V_79 = 0 ;
}
V_82 = 1 << V_79 ;
if ( V_53 < V_52 ) {
V_82 *= - 1 ;
V_52 += V_51 + V_82 ;
V_53 += V_51 + V_82 ;
}
V_51 >>= V_79 ;
#ifndef F_72
if ( V_51 > 0x10000 )
V_75 |= V_78 ;
#endif
F_51 ( V_52 , V_82 , V_53 , V_82 , V_51 , V_75 ) ;
return V_49 ;
}
void * F_73 ( void * V_49 , const void * V_50 , T_3 V_51 )
{
unsigned long V_52 = ( unsigned long ) V_49 ;
unsigned long V_53 = ( unsigned long ) V_50 ;
if ( F_74 ( V_53 ) )
F_75 ( V_53 , V_53 + V_51 ) ;
if ( F_74 ( V_52 ) )
F_76 ( V_52 , V_52 + V_51 ) ;
return F_77 ( V_49 , V_50 , V_51 ) ;
}
void * F_77 ( void * V_49 , const void * V_50 , T_3 V_51 )
{
#ifdef F_72
F_71 ( V_49 , V_50 , V_51 ) ;
#else
T_3 V_85 , V_86 ;
V_85 = V_51 & ~ 0xffff ;
V_86 = V_51 - V_85 ;
if ( V_85 )
F_71 ( V_49 , V_50 , V_85 ) ;
F_71 ( V_49 + V_85 , V_50 + V_85 , V_86 ) ;
#endif
return V_49 ;
}
void * F_78 ( void * V_52 , const void * V_53 , T_3 V_51 )
{
if ( ! F_79 ( V_87 , V_52 , V_51 ) )
return NULL ;
if ( ! F_79 ( V_88 , V_53 , V_51 ) )
return NULL ;
return F_73 ( V_52 , V_53 , V_51 ) ;
}
static void F_80 ( unsigned long V_89 , unsigned long V_90 , unsigned T_6 V_91 ,
T_7 V_51 , T_7 V_92 )
{
F_75 ( V_90 , V_90 + V_91 * V_51 ) ;
F_51 ( V_89 , 0 , V_90 , V_51 , V_91 , V_92 ) ;
}
static void F_81 ( unsigned long V_89 , unsigned long V_90 , unsigned T_6 V_91 ,
T_7 V_51 , T_7 V_92 )
{
F_76 ( V_90 , V_90 + V_91 * V_51 ) ;
F_51 ( V_90 , V_51 , V_89 , 0 , V_91 , V_92 ) ;
}
