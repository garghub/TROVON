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
#ifdef F_5
F_6 ( V_9 , L_2 ) ;
F_6 ( F_5 , L_2 ) ;
#else
F_6 ( V_10 , L_2 ) ;
F_6 ( V_11 , L_2 ) ;
#endif
#if F_7 ( V_12 )
F_8 ( F_9 ()
| V_13 | V_14 | V_15 ) ;
#endif
return 0 ;
}
static int F_10 ( struct V_16 * V_17 , void * V_18 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 )
if ( F_11 ( V_1 ) )
F_12 ( V_17 , L_3 , V_1 , V_5 [ V_1 ] . V_19 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
return F_14 ( V_21 , F_10 , NULL ) ;
}
static int T_1 F_15 ( void )
{
F_16 ( L_4 , 0 , NULL , & V_22 ) ;
return 0 ;
}
static void F_17 ( unsigned int V_23 , const char * V_19 )
{
#ifdef F_18
unsigned int V_24 ;
switch ( V_23 ) {
case V_25 : V_24 = 0xC << 12 ; break;
case V_26 : V_24 = 0xD << 12 ; break;
case V_27 : V_24 = 0xE << 12 ; break;
case V_28 : V_24 = 0xF << 12 ; break;
default: return;
}
if ( strncmp ( V_19 , L_5 , 9 ) == 0 )
V_5 [ V_23 ] . V_7 -> V_29 = V_24 ;
#endif
}
int F_6 ( unsigned int V_23 , const char * V_19 )
{
F_19 ( L_6 ) ;
if ( V_19 == NULL )
F_2 ( V_30 L_7 , V_23 ) ;
#if F_7 ( V_31 ) && V_32
if ( V_23 >= V_33 && V_23 <= V_34 ) {
if ( F_20 () > 500000000 ) {
F_2 ( V_30
L_8 ) ;
return - V_35 ;
}
}
#endif
if ( F_21 ( & V_5 [ V_23 ] . V_6 , 0 , 1 ) ) {
F_19 ( L_9 ) ;
return - V_36 ;
}
F_17 ( V_23 , V_19 ) ;
V_5 [ V_23 ] . V_19 = V_19 ;
V_5 [ V_23 ] . V_37 = 0 ;
F_19 ( L_10 ) ;
return 0 ;
}
int F_22 ( unsigned int V_23 , T_2 V_38 , void * V_39 )
{
int V_40 ;
unsigned int V_37 ;
F_23 ( V_23 >= V_4 || ! V_38 ||
! F_24 ( & V_5 [ V_23 ] . V_6 ) ) ;
V_37 = F_25 ( V_23 ) ;
V_40 = F_26 ( V_37 , V_38 , 0 , V_5 [ V_23 ] . V_19 , V_39 ) ;
if ( V_40 )
return V_40 ;
V_5 [ V_23 ] . V_37 = V_37 ;
V_5 [ V_23 ] . V_39 = V_39 ;
return 0 ;
}
static void F_27 ( unsigned int V_23 )
{
V_5 [ V_23 ] . V_7 -> V_41 |= V_42 ;
F_28 () ;
V_5 [ V_23 ] . V_7 -> V_41 &= ~ V_42 ;
}
void F_29 ( unsigned int V_23 )
{
F_19 ( L_11 ) ;
F_23 ( V_23 >= V_4 ||
! F_24 ( & V_5 [ V_23 ] . V_6 ) ) ;
F_30 ( V_23 ) ;
F_27 ( V_23 ) ;
if ( V_5 [ V_23 ] . V_37 )
F_31 ( V_5 [ V_23 ] . V_37 , V_5 [ V_23 ] . V_39 ) ;
F_4 ( & V_5 [ V_23 ] . V_6 , 0 ) ;
F_19 ( L_12 ) ;
}
int F_32 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 ) {
if ( V_5 [ V_1 ] . V_7 -> V_41 & V_43 ) {
F_2 ( V_44 L_13 , V_1 ) ;
return - V_36 ;
}
if ( V_1 < V_45 )
V_5 [ V_1 ] . V_46 = V_5 [ V_1 ] . V_7 -> V_29 ;
}
#if V_3
F_3 ( 0x0 ) ;
#endif
return 0 ;
}
void F_33 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 ) {
V_5 [ V_1 ] . V_7 -> V_41 = 0 ;
if ( V_1 < V_45 )
V_5 [ V_1 ] . V_7 -> V_29 = V_5 [ V_1 ] . V_46 ;
}
#if V_3
F_3 ( 0x0111 ) ;
#endif
}
int F_32 ( void )
{
return 0 ;
}
void F_33 ( void )
{
}
void T_1 F_34 ( void )
{
F_35 () ;
F_36 ( 0 ) ;
F_37 ( 0 ) ;
}
void T_1 F_38 ( void * V_47 , const void * V_48 , T_3 V_49 )
{
unsigned long V_50 = ( unsigned long ) V_47 ;
unsigned long V_51 = ( unsigned long ) V_48 ;
struct V_52 * V_53 , * V_54 ;
F_35 () ;
F_23 ( V_50 % 4 ) ;
F_23 ( V_51 % 4 ) ;
F_23 ( V_49 % 4 ) ;
V_54 = 0 ;
while ( 1 ) {
if ( V_54 == (struct V_52 * ) V_55 ) {
V_53 = (struct V_52 * ) V_56 ;
V_54 = (struct V_52 * ) V_57 ;
} else {
V_53 = (struct V_52 * ) V_58 ;
V_54 = (struct V_52 * ) V_55 ;
}
if ( ! F_39 ( & V_54 -> V_41 ) )
break;
else if ( F_39 ( & V_53 -> V_59 ) & V_60 ) {
F_40 ( & V_54 -> V_41 , 0 ) ;
break;
}
}
F_41 () ;
F_42 ( & V_53 -> V_61 , V_50 ) ;
F_40 ( & V_53 -> V_62 , V_49 >> 2 ) ;
F_40 ( & V_53 -> V_63 , 1 << 2 ) ;
F_40 ( & V_53 -> V_59 , V_60 | V_64 ) ;
F_42 ( & V_54 -> V_61 , V_51 ) ;
F_40 ( & V_54 -> V_62 , V_49 >> 2 ) ;
F_40 ( & V_54 -> V_63 , 1 << 2 ) ;
F_40 ( & V_54 -> V_59 , V_60 | V_64 ) ;
F_40 ( & V_54 -> V_41 , V_43 | V_65 ) ;
F_40 ( & V_53 -> V_41 , V_66 | V_67 | V_43 | V_65 ) ;
F_41 () ;
#ifdef F_43
while ( ! ( F_39 ( & V_53 -> V_59 ) & V_60 ) )
continue;
#endif
}
void T_1 F_44 ( void )
{
F_35 () ;
while ( ( F_45 () && ! ( F_46 () & V_60 ) ) ||
( F_47 () && ! ( F_48 () & V_60 ) ) )
continue;
F_49 ( V_60 | V_64 ) ;
F_50 ( V_60 | V_64 ) ;
F_36 ( 0 ) ;
F_37 ( 0 ) ;
F_51 ( 0 ) ;
F_52 ( 0 ) ;
F_41 () ;
}
static void F_53 ( T_4 V_68 , T_5 V_69 , T_4 V_70 , T_5 V_71 , T_3 V_72 , T_4 V_73 )
{
static F_54 ( V_74 ) ;
unsigned long V_75 ;
F_55 ( & V_74 , V_75 ) ;
F_41 () ;
if ( F_56 () )
while ( ! ( F_57 () & V_60 ) )
continue;
if ( V_73 & V_76 ) {
T_4 V_77 = abs ( V_69 ) >> 1 ;
T_3 V_78 = V_72 >> ( 16 - V_77 ) ;
V_72 = 1 << ( 16 - V_77 ) ;
F_58 ( V_78 ) ;
F_59 ( V_78 ) ;
F_60 ( V_69 ) ;
F_61 ( V_71 ) ;
}
F_62 ( V_68 ) ;
F_63 ( V_72 ) ;
F_64 ( V_69 ) ;
F_65 ( V_60 | V_64 ) ;
F_66 ( V_70 ) ;
F_67 ( V_72 ) ;
F_68 ( V_71 ) ;
F_69 ( V_60 | V_64 ) ;
F_70 ( V_43 | V_73 ) ;
if ( V_73 & V_76 )
F_71 ( V_66 | V_79 | V_43 | V_73 ) ;
else
F_71 ( V_66 | V_67 | V_43 | V_73 ) ;
F_72 ( & V_74 , V_75 ) ;
F_28 () ;
while ( ! ( F_57 () & V_60 ) )
if ( F_56 () )
continue;
else
return;
F_65 ( V_60 | V_64 ) ;
F_70 ( 0 ) ;
F_71 ( 0 ) ;
}
static void * F_73 ( void * V_47 , const void * V_48 , T_3 V_49 )
{
T_4 V_73 , V_77 ;
T_5 V_80 ;
unsigned long V_50 = ( unsigned long ) V_47 ;
unsigned long V_51 = ( unsigned long ) V_48 ;
if ( V_49 == 0 )
return NULL ;
if ( V_50 % 4 == 0 && V_51 % 4 == 0 && V_49 % 4 == 0 ) {
V_73 = V_65 ;
V_77 = 2 ;
} else if ( V_50 % 2 == 0 && V_51 % 2 == 0 && V_49 % 2 == 0 ) {
V_73 = V_81 ;
V_77 = 1 ;
} else {
V_73 = V_82 ;
V_77 = 0 ;
}
V_80 = 1 << V_77 ;
if ( V_51 < V_50 ) {
V_80 *= - 1 ;
V_50 += V_49 + V_80 ;
V_51 += V_49 + V_80 ;
}
V_49 >>= V_77 ;
#ifndef F_74
if ( V_49 > 0x10000 )
V_73 |= V_76 ;
#endif
F_53 ( V_50 , V_80 , V_51 , V_80 , V_49 , V_73 ) ;
return V_47 ;
}
void * F_75 ( void * V_47 , const void * V_48 , T_3 V_49 )
{
unsigned long V_50 = ( unsigned long ) V_47 ;
unsigned long V_51 = ( unsigned long ) V_48 ;
if ( F_76 ( V_51 ) )
F_77 ( V_51 , V_51 + V_49 ) ;
if ( F_76 ( V_50 ) )
F_78 ( V_50 , V_50 + V_49 ) ;
return F_79 ( V_47 , V_48 , V_49 ) ;
}
void * F_79 ( void * V_47 , const void * V_48 , T_3 V_49 )
{
#ifdef F_74
F_73 ( V_47 , V_48 , V_49 ) ;
#else
T_3 V_83 , V_84 ;
V_83 = V_49 & ~ 0xffff ;
V_84 = V_49 - V_83 ;
if ( V_83 )
F_73 ( V_47 , V_48 , V_83 ) ;
F_73 ( V_47 + V_83 , V_48 + V_83 , V_84 ) ;
#endif
return V_47 ;
}
void * F_80 ( void * V_50 , const void * V_51 , T_3 V_49 )
{
if ( ! F_81 ( V_85 , V_50 , V_49 ) )
return NULL ;
if ( ! F_81 ( V_86 , V_51 , V_49 ) )
return NULL ;
return F_75 ( V_50 , V_51 , V_49 ) ;
}
static void F_82 ( unsigned long V_87 , unsigned long V_88 , unsigned T_6 V_89 ,
T_7 V_49 , T_7 V_90 )
{
F_77 ( V_88 , V_88 + V_89 * V_49 ) ;
F_53 ( V_87 , 0 , V_88 , V_49 , V_89 , V_90 ) ;
}
static void F_83 ( unsigned long V_87 , unsigned long V_88 , unsigned T_6 V_89 ,
T_7 V_49 , T_7 V_90 )
{
F_78 ( V_88 , V_88 + V_89 * V_49 ) ;
F_53 ( V_88 , V_49 , V_87 , 0 , V_89 , V_90 ) ;
}
