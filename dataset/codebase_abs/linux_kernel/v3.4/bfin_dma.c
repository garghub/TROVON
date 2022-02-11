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
F_5 ( V_9 , L_2 ) ;
F_5 ( V_10 , L_2 ) ;
#if F_6 ( V_11 )
F_7 ( F_8 ()
| V_12 | V_13 | V_14 ) ;
#endif
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , void * V_17 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 )
if ( F_10 ( V_1 ) )
F_11 ( V_16 , L_3 , V_1 , V_5 [ V_1 ] . V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
return F_13 ( V_20 , F_9 , NULL ) ;
}
static int T_1 F_14 ( void )
{
return F_15 ( L_4 , 0 , NULL , & V_21 ) != NULL ;
}
static void F_16 ( unsigned int V_22 , const char * V_18 )
{
#ifdef F_17
unsigned int V_23 ;
switch ( V_22 ) {
case V_24 : V_23 = 0xC << 12 ; break;
case V_25 : V_23 = 0xD << 12 ; break;
case V_26 : V_23 = 0xE << 12 ; break;
case V_27 : V_23 = 0xF << 12 ; break;
default: return;
}
if ( strncmp ( V_18 , L_5 , 9 ) == 0 )
V_5 [ V_22 ] . V_7 -> V_28 = V_23 ;
#endif
}
int F_5 ( unsigned int V_22 , const char * V_18 )
{
F_18 ( L_6 ) ;
if ( V_18 == NULL )
F_2 ( V_29 L_7 , V_22 ) ;
#if F_6 ( V_30 ) && V_31
if ( V_22 >= V_32 && V_22 <= V_33 ) {
if ( F_19 () > 500000000 ) {
F_2 ( V_29
L_8 ) ;
return - V_34 ;
}
}
#endif
if ( F_20 ( & V_5 [ V_22 ] . V_6 , 0 , 1 ) ) {
F_18 ( L_9 ) ;
return - V_35 ;
}
F_16 ( V_22 , V_18 ) ;
V_5 [ V_22 ] . V_18 = V_18 ;
V_5 [ V_22 ] . V_36 = 0 ;
F_18 ( L_10 ) ;
return 0 ;
}
int F_21 ( unsigned int V_22 , T_2 V_37 , void * V_38 )
{
int V_39 ;
unsigned int V_36 ;
F_22 ( V_22 >= V_4 || ! V_37 ||
! F_23 ( & V_5 [ V_22 ] . V_6 ) ) ;
V_36 = F_24 ( V_22 ) ;
V_39 = F_25 ( V_36 , V_37 , 0 , V_5 [ V_22 ] . V_18 , V_38 ) ;
if ( V_39 )
return V_39 ;
V_5 [ V_22 ] . V_36 = V_36 ;
V_5 [ V_22 ] . V_38 = V_38 ;
return 0 ;
}
static void F_26 ( unsigned int V_22 )
{
V_5 [ V_22 ] . V_7 -> V_40 |= V_41 ;
F_27 () ;
V_5 [ V_22 ] . V_7 -> V_40 &= ~ V_41 ;
}
void F_28 ( unsigned int V_22 )
{
F_18 ( L_11 ) ;
F_22 ( V_22 >= V_4 ||
! F_23 ( & V_5 [ V_22 ] . V_6 ) ) ;
F_29 ( V_22 ) ;
F_26 ( V_22 ) ;
if ( V_5 [ V_22 ] . V_36 )
F_30 ( V_5 [ V_22 ] . V_36 , V_5 [ V_22 ] . V_38 ) ;
F_4 ( & V_5 [ V_22 ] . V_6 , 0 ) ;
F_18 ( L_12 ) ;
}
int F_31 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; ++ V_1 ) {
if ( V_5 [ V_1 ] . V_7 -> V_40 & V_42 ) {
F_2 ( V_43 L_13 , V_1 ) ;
return - V_35 ;
}
if ( V_1 < V_44 )
V_5 [ V_1 ] . V_45 = V_5 [ V_1 ] . V_7 -> V_28 ;
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
V_5 [ V_1 ] . V_7 -> V_40 = 0 ;
if ( V_1 < V_44 )
V_5 [ V_1 ] . V_7 -> V_28 = V_5 [ V_1 ] . V_45 ;
}
#if V_3
F_3 ( 0x0111 ) ;
#endif
}
void T_1 F_33 ( void )
{
F_34 () ;
F_35 ( 0 ) ;
F_36 ( 0 ) ;
}
void T_1 F_37 ( void * V_46 , const void * V_47 , T_3 V_48 )
{
unsigned long V_49 = ( unsigned long ) V_46 ;
unsigned long V_50 = ( unsigned long ) V_47 ;
struct V_51 * V_52 , * V_53 ;
F_34 () ;
F_22 ( V_49 % 4 ) ;
F_22 ( V_50 % 4 ) ;
F_22 ( V_48 % 4 ) ;
V_53 = 0 ;
while ( 1 ) {
if ( V_53 == (struct V_51 * ) V_54 ) {
V_52 = (struct V_51 * ) V_55 ;
V_53 = (struct V_51 * ) V_56 ;
} else {
V_52 = (struct V_51 * ) V_57 ;
V_53 = (struct V_51 * ) V_54 ;
}
if ( ! F_38 ( & V_53 -> V_40 ) )
break;
else if ( F_38 ( & V_52 -> V_58 ) & V_59 ) {
F_39 ( & V_53 -> V_40 , 0 ) ;
break;
}
}
F_40 () ;
F_41 ( & V_52 -> V_60 , V_49 ) ;
F_39 ( & V_52 -> V_61 , V_48 >> 2 ) ;
F_39 ( & V_52 -> V_62 , 1 << 2 ) ;
F_39 ( & V_52 -> V_58 , V_59 | V_63 ) ;
F_41 ( & V_53 -> V_60 , V_50 ) ;
F_39 ( & V_53 -> V_61 , V_48 >> 2 ) ;
F_39 ( & V_53 -> V_62 , 1 << 2 ) ;
F_39 ( & V_53 -> V_58 , V_59 | V_63 ) ;
F_39 ( & V_53 -> V_40 , V_42 | V_64 ) ;
F_39 ( & V_52 -> V_40 , V_65 | V_66 | V_42 | V_64 ) ;
F_40 () ;
}
void T_1 F_42 ( void )
{
F_34 () ;
while ( ( F_43 () && ! ( F_44 () & V_59 ) ) ||
( F_45 () && ! ( F_46 () & V_59 ) ) )
continue;
F_47 ( V_59 | V_63 ) ;
F_48 ( V_59 | V_63 ) ;
F_35 ( 0 ) ;
F_36 ( 0 ) ;
F_49 ( 0 ) ;
F_50 ( 0 ) ;
F_40 () ;
}
static void F_51 ( T_4 V_67 , T_5 V_68 , T_4 V_69 , T_5 V_70 , T_3 V_71 , T_4 V_72 )
{
static F_52 ( V_73 ) ;
unsigned long V_74 ;
F_53 ( & V_73 , V_74 ) ;
F_40 () ;
if ( F_43 () )
while ( ! ( F_44 () & V_59 ) )
continue;
if ( V_72 & V_75 ) {
T_4 V_76 = abs ( V_68 ) >> 1 ;
T_3 V_77 = V_71 >> ( 16 - V_76 ) ;
V_71 = 1 << ( 16 - V_76 ) ;
F_54 ( V_77 ) ;
F_55 ( V_77 ) ;
F_56 ( V_68 ) ;
F_57 ( V_70 ) ;
}
F_58 ( V_67 ) ;
F_59 ( V_71 ) ;
F_60 ( V_68 ) ;
F_47 ( V_59 | V_63 ) ;
F_61 ( V_69 ) ;
F_62 ( V_71 ) ;
F_63 ( V_70 ) ;
F_64 ( V_59 | V_63 ) ;
F_35 ( V_42 | V_72 ) ;
F_49 ( V_65 | V_66 | V_42 | V_72 ) ;
F_65 ( & V_73 , V_74 ) ;
F_27 () ;
while ( ! ( F_44 () & V_59 ) )
if ( F_43 () )
continue;
else
return;
F_47 ( V_59 | V_63 ) ;
F_35 ( 0 ) ;
F_49 ( 0 ) ;
}
static void * F_66 ( void * V_46 , const void * V_47 , T_3 V_48 )
{
T_4 V_72 , V_76 ;
T_5 V_78 ;
unsigned long V_49 = ( unsigned long ) V_46 ;
unsigned long V_50 = ( unsigned long ) V_47 ;
if ( V_48 == 0 )
return NULL ;
if ( V_49 % 4 == 0 && V_50 % 4 == 0 && V_48 % 4 == 0 ) {
V_72 = V_64 ;
V_76 = 2 ;
} else if ( V_49 % 2 == 0 && V_50 % 2 == 0 && V_48 % 2 == 0 ) {
V_72 = V_79 ;
V_76 = 1 ;
} else {
V_72 = V_80 ;
V_76 = 0 ;
}
V_78 = 1 << V_76 ;
if ( V_50 < V_49 ) {
V_78 *= - 1 ;
V_49 += V_48 + V_78 ;
V_50 += V_48 + V_78 ;
}
V_48 >>= V_76 ;
if ( V_48 > 0x10000 )
V_72 |= V_75 ;
F_51 ( V_49 , V_78 , V_50 , V_78 , V_48 , V_72 ) ;
return V_46 ;
}
void * F_67 ( void * V_46 , const void * V_47 , T_3 V_48 )
{
unsigned long V_49 = ( unsigned long ) V_46 ;
unsigned long V_50 = ( unsigned long ) V_47 ;
if ( F_68 ( V_50 ) )
F_69 ( V_50 , V_50 + V_48 ) ;
if ( F_68 ( V_49 ) )
F_70 ( V_49 , V_49 + V_48 ) ;
return F_71 ( V_46 , V_47 , V_48 ) ;
}
void * F_71 ( void * V_46 , const void * V_47 , T_3 V_48 )
{
T_3 V_81 , V_82 ;
V_81 = V_48 & ~ 0xffff ;
V_82 = V_48 - V_81 ;
if ( V_81 )
F_66 ( V_46 , V_47 , V_81 ) ;
F_66 ( V_46 + V_81 , V_47 + V_81 , V_82 ) ;
return V_46 ;
}
void * F_72 ( void * V_49 , const void * V_50 , T_3 V_48 )
{
if ( ! F_73 ( V_83 , V_49 , V_48 ) )
return NULL ;
if ( ! F_73 ( V_84 , V_50 , V_48 ) )
return NULL ;
return F_67 ( V_49 , V_50 , V_48 ) ;
}
static void F_74 ( unsigned long V_85 , unsigned long V_86 , unsigned short V_87 ,
T_6 V_48 , T_6 V_88 )
{
F_69 ( V_86 , V_86 + V_87 * V_48 ) ;
F_51 ( V_85 , 0 , V_86 , V_48 , V_87 , V_88 ) ;
}
static void F_75 ( unsigned long V_85 , unsigned long V_86 , unsigned short V_87 ,
T_6 V_48 , T_6 V_88 )
{
F_70 ( V_86 , V_86 + V_87 * V_48 ) ;
F_51 ( V_86 , V_48 , V_85 , 0 , V_87 , V_88 ) ;
}
