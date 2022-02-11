static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 , V_6 ;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
V_4 = V_2 -> V_7 . V_3 . V_8 ;
if ( ! V_4 )
return;
V_6 = F_2 ( V_9 , F_3 ( V_4 -> V_10 ) , V_11 ) ;
if ( ( void * ) & V_4 -> V_12 [ V_6 ] > V_2 -> V_7 . V_3 . V_13 )
return;
for ( V_5 = 0 ; V_5 < V_6 ; ++ V_5 ) {
unsigned long V_14 = F_4 ( V_4 -> V_12 [ V_5 ] . V_15 ) ;
unsigned long V_16 = F_4 ( V_4 -> V_12 [ V_5 ] . V_17 ) ;
V_14 = ( V_14 & ~ 0xFFFul ) | V_5 ;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static long F_5 ( struct V_1 * V_2 )
{
unsigned long V_18 = V_2 -> V_7 . V_19 . V_20 ;
struct V_21 V_22 ;
long V_23 = 1 ;
if ( V_18 & V_24 ) {
unsigned long V_25 = V_2 -> V_7 . V_19 . V_25 ;
if ( V_25 & ( V_26 | V_27 |
V_28 | V_29 ) ) {
F_1 ( V_2 ) ;
V_25 &= ~ ( V_26 | V_27 |
V_28 | V_29 ) ;
}
if ( V_25 & V_30 ) {
if ( V_31 && V_31 -> V_32 )
V_31 -> V_32 ( V_33 ) ;
V_25 &= ~ V_30 ;
}
if ( V_25 & 0xffffffffUL )
V_23 = 0 ;
}
switch ( ( V_18 >> V_34 ) & V_35 ) {
case 0 :
break;
case V_36 :
case V_37 :
case V_38 :
F_1 ( V_2 ) ;
break;
case V_39 :
if ( V_31 && V_31 -> V_32 )
V_31 -> V_32 ( V_33 ) ;
break;
default:
V_23 = 0 ;
}
if ( ! F_6 ( & V_22 , V_40 ) )
goto V_41;
if ( V_22 . V_42 == V_43 &&
( V_22 . V_44 == V_45 ||
V_22 . V_46 == V_47 ) )
V_23 = 1 ;
V_41:
if ( V_2 -> V_48 -> V_7 . V_49 ) {
memset ( & V_2 -> V_7 . V_22 , 0 , sizeof( V_2 -> V_7 . V_22 ) ) ;
if ( F_6 ( & V_22 , V_50 ) ) {
V_2 -> V_7 . V_22 = V_22 ;
}
} else
F_7 () ;
return V_23 ;
}
long F_8 ( struct V_1 * V_2 )
{
return F_5 ( V_2 ) ;
}
static inline int F_9 ( void )
{
if ( V_51 -> V_52 . V_53 )
return V_51 -> V_52 . V_53 -> V_54 ;
return V_55 ;
}
void F_10 ( void )
{
int V_56 , V_57 ;
V_56 = F_11 ( V_51 -> V_58 ) ;
V_57 = V_56 / F_9 () ;
V_51 -> V_59 -> V_60 [ V_57 ] = 1 ;
}
void F_12 ( void )
{
int V_56 , V_57 ;
V_56 = F_11 ( V_51 -> V_58 ) ;
V_57 = V_56 / F_9 () ;
V_51 -> V_59 -> V_60 [ V_57 ] = 0 ;
}
static bool F_13 ( void )
{
if ( F_14 ( V_61 ,
& V_51 -> V_59 -> V_62 ) )
return false ;
return true ;
}
static void F_15 ( void )
{
F_16 ( V_61 ,
& V_51 -> V_59 -> V_62 ) ;
}
long F_17 ( void )
{
int V_63 = V_51 -> V_52 . V_63 ;
bool V_64 ;
F_18 ( V_63 != 0 ) ;
F_19 ( V_65 . V_66 ) ;
V_64 = F_13 () ;
F_12 () ;
F_20 () ;
if ( V_67 . V_68 )
V_67 . V_68 ( NULL ) ;
if ( V_64 ) {
F_21 () ;
F_15 () ;
} else {
F_22 () ;
}
return 0 ;
}
