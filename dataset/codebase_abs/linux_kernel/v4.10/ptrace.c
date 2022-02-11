void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
F_3 ( V_2 ) -> V_5 = 0 ;
F_3 ( V_2 ) -> V_6 = 0 ;
F_3 ( V_2 ) -> V_7 = 0 ;
F_3 ( V_2 ) -> V_8 = 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 ) ;
F_6 ( V_2 , V_3 ) ;
if ( F_3 ( V_2 ) -> V_9 ) {
struct V_10 V_11 ;
F_7 ( V_2 ) -> V_12 [ 0 ] = F_7 ( V_2 ) -> V_12 [ 1 ] ;
F_7 ( V_2 ) -> V_13 [ 0 ] = F_7 ( V_2 ) -> V_13 [ 1 ] ;
F_7 ( V_2 ) -> V_12 [ 1 ] = F_7 ( V_2 ) -> V_12 [ 0 ] + 4 ;
F_3 ( V_2 ) -> V_9 = 0 ;
F_3 ( V_2 ) -> V_14 = 0 ;
F_3 ( V_2 ) -> V_15 = 0 ;
F_3 ( V_2 ) -> V_16 = 0 ;
F_3 ( V_2 ) -> V_17 = 0 ;
F_1 ( V_2 ) ;
V_11 . V_18 = V_19 ;
V_11 . V_20 = ( void V_21 * ) ( F_7 ( V_2 ) -> V_12 [ 0 ] & ~ 3 ) ;
V_11 . V_22 = V_23 ;
V_11 . V_24 = 0 ;
F_8 ( V_23 , & V_11 , V_2 ) ;
return;
}
F_3 ( V_2 ) -> V_5 = 1 ;
F_3 ( V_2 ) -> V_6 = 0 ;
F_3 ( V_2 ) -> V_7 = 0 ;
F_3 ( V_2 ) -> V_8 = 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_4 ) ;
F_3 ( V_2 ) -> V_5 = 0 ;
F_3 ( V_2 ) -> V_6 = 1 ;
F_3 ( V_2 ) -> V_7 = 0 ;
F_3 ( V_2 ) -> V_8 = 0 ;
}
long F_10 ( struct V_1 * V_25 , long V_26 ,
unsigned long V_27 , unsigned long V_28 )
{
unsigned long V_21 * V_29 = ( unsigned long V_21 * ) V_28 ;
unsigned long V_30 ;
long V_31 = - V_32 ;
switch ( V_26 ) {
case V_33 :
if ( ( V_27 & (sizeof( unsigned long ) - 1 ) ) ||
V_27 >= sizeof( struct V_34 ) )
break;
V_30 = * ( unsigned long * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) ;
V_31 = F_11 ( V_30 , V_29 ) ;
break;
case V_35 :
if ( V_27 == V_36 ) {
V_28 &= V_37 ;
F_7 ( V_25 ) -> V_38 [ 0 ] &= ~ V_37 ;
F_7 ( V_25 ) -> V_38 [ 0 ] |= V_28 ;
V_31 = 0 ;
break;
}
if ( ( V_27 & (sizeof( unsigned long ) - 1 ) ) ||
V_27 >= sizeof( struct V_34 ) )
break;
if ( ( V_27 >= V_39 && V_27 <= V_40 ) ||
V_27 == V_41 || V_27 == V_42 ||
( V_27 >= V_43 && V_27 <= V_44 + 4 ) ||
V_27 == V_45 ) {
* ( unsigned long * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) = V_28 ;
V_31 = 0 ;
}
break;
case V_46 :
return F_12 ( V_25 ,
F_13 ( V_47 ) ,
V_48 ,
0 , sizeof( struct V_49 ) ,
V_29 ) ;
case V_50 :
return F_14 ( V_25 ,
F_13 ( V_47 ) ,
V_48 ,
0 , sizeof( struct V_49 ) ,
V_29 ) ;
case V_51 :
return F_12 ( V_25 ,
F_13 ( V_47 ) ,
V_52 ,
0 , sizeof( struct V_53 ) ,
V_29 ) ;
case V_54 :
return F_14 ( V_25 ,
F_13 ( V_47 ) ,
V_52 ,
0 , sizeof( struct V_53 ) ,
V_29 ) ;
default:
V_31 = F_15 ( V_25 , V_26 , V_27 , V_28 ) ;
break;
}
return V_31 ;
}
static T_1 F_16 ( T_1 V_55 )
{
if ( V_55 < 0 )
return sizeof( struct V_34 ) ;
else if ( V_55 <= 32 * 4 )
return V_55 * 2 + 4 ;
else if ( V_55 <= 32 * 4 + 32 * 8 )
return V_55 + 32 * 4 ;
else if ( V_55 < sizeof( struct V_34 ) / 2 + 32 * 4 )
return V_55 * 2 + 4 - 32 * 8 ;
else
return sizeof( struct V_34 ) ;
}
long F_17 ( struct V_1 * V_25 , T_2 V_26 ,
T_1 V_27 , T_1 V_28 )
{
T_3 V_30 ;
long V_31 = - V_32 ;
switch ( V_26 ) {
case V_33 :
if ( V_27 & ( sizeof( T_3 ) - 1 ) )
break;
V_27 = F_16 ( V_27 ) ;
if ( V_27 >= sizeof( struct V_34 ) )
break;
V_30 = * ( T_3 * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) ;
V_31 = F_11 ( V_30 , ( T_3 * ) ( unsigned long ) V_28 ) ;
break;
case V_35 :
if ( V_27 == V_36 ) {
V_31 = F_10 ( V_25 , V_26 , V_27 , V_28 ) ;
} else {
if ( V_27 & ( sizeof( T_3 ) - 1 ) )
break;
V_27 = F_16 ( V_27 ) ;
if ( V_27 >= sizeof( struct V_34 ) )
break;
if ( V_27 >= V_43 && V_27 <= V_44 + 4 ) {
* ( V_56 * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) = V_28 ;
V_31 = 0 ;
}
else if ( ( V_27 >= V_39 + 4 && V_27 <= V_40 + 4 ) ||
V_27 == V_41 + 4 || V_27 == V_42 + 4 ||
V_27 == V_45 + 4 ) {
* ( V_57 * ) ( ( char * ) F_7 ( V_25 ) + V_27 - 4 ) = 0 ;
* ( V_57 * ) ( ( char * ) F_7 ( V_25 ) + V_27 ) = V_28 ;
V_31 = 0 ;
}
}
break;
default:
V_31 = F_18 ( V_25 , V_26 , V_27 , V_28 ) ;
break;
}
return V_31 ;
}
long F_19 ( struct V_34 * V_58 )
{
if ( F_20 ( V_59 ) &&
F_21 ( V_58 ) ) {
V_58 -> V_38 [ 20 ] = - 1UL ;
goto V_60;
}
if ( F_22 ( NULL ) == - 1 )
return - 1 ;
#ifdef F_23
if ( F_24 ( F_20 ( V_61 ) ) )
F_25 ( V_58 , V_58 -> V_38 [ 20 ] ) ;
#endif
#ifdef F_26
if ( ! F_27 () )
F_28 ( V_58 -> V_38 [ 20 ] , V_58 -> V_38 [ 26 ] , V_58 -> V_38 [ 25 ] ,
V_58 -> V_38 [ 24 ] , V_58 -> V_38 [ 23 ] ) ;
else
#endif
F_28 ( V_58 -> V_38 [ 20 ] & 0xffffffff ,
V_58 -> V_38 [ 26 ] & 0xffffffff ,
V_58 -> V_38 [ 25 ] & 0xffffffff ,
V_58 -> V_38 [ 24 ] & 0xffffffff ,
V_58 -> V_38 [ 23 ] & 0xffffffff ) ;
V_60:
return ( int ) ( ( V_62 ) V_58 -> V_38 [ 20 ] ) ;
}
void F_29 ( struct V_34 * V_58 )
{
int V_63 = F_20 ( V_3 ) ||
F_20 ( V_4 ) ;
F_30 ( V_58 ) ;
#ifdef F_23
if ( F_24 ( F_20 ( V_61 ) ) )
F_31 ( V_58 , V_58 -> V_38 [ 20 ] ) ;
#endif
if ( V_63 || F_20 ( V_59 ) )
F_32 ( V_58 , V_63 ) ;
}
static int F_33 ( struct V_1 * V_64 ,
const struct V_65 * V_66 ,
unsigned int V_67 , unsigned int V_68 ,
void * V_69 , void V_21 * V_70 )
{
struct V_34 * V_58 = F_7 ( V_64 ) ;
V_56 * V_71 = V_69 ;
V_56 V_21 * V_72 = V_70 ;
V_56 V_73 ;
V_67 /= sizeof( V_73 ) ;
V_68 /= sizeof( V_73 ) ;
if ( V_69 )
for (; V_68 > 0 && V_67 < V_74 ; -- V_68 )
* V_71 ++ = V_58 -> V_75 [ V_67 ++ ] ;
else
for (; V_68 > 0 && V_67 < V_74 ; -- V_68 )
if ( F_34 ( V_58 -> V_75 [ V_67 ++ ] , V_72 ++ ) )
return - V_76 ;
V_69 = V_71 ;
V_70 = V_72 ;
V_67 *= sizeof( V_73 ) ;
V_68 *= sizeof( V_73 ) ;
return F_35 ( & V_67 , & V_68 , & V_69 , & V_70 ,
V_74 * sizeof( V_73 ) , - 1 ) ;
}
static int F_36 ( struct V_1 * V_64 ,
const struct V_65 * V_66 ,
unsigned int V_67 , unsigned int V_68 ,
const void * V_69 , const void V_21 * V_70 )
{
struct V_34 * V_58 = F_7 ( V_64 ) ;
const V_56 * V_71 = V_69 ;
const V_56 V_21 * V_72 = V_70 ;
V_56 V_73 ;
V_67 /= sizeof( V_73 ) ;
V_68 /= sizeof( V_73 ) ;
if ( V_69 )
for (; V_68 > 0 && V_67 < V_74 ; -- V_68 )
V_58 -> V_75 [ V_67 ++ ] = * V_71 ++ ;
else
for (; V_68 > 0 && V_67 < V_74 ; -- V_68 ) {
if ( F_37 ( V_73 , V_72 ++ ) )
return - V_76 ;
V_58 -> V_75 [ V_67 ++ ] = V_73 ;
}
V_69 = V_71 ;
V_70 = V_72 ;
V_67 *= sizeof( V_73 ) ;
V_68 *= sizeof( V_73 ) ;
return F_38 ( & V_67 , & V_68 , & V_69 , & V_70 ,
V_74 * sizeof( V_73 ) , - 1 ) ;
}
static unsigned long F_39 ( struct V_34 * V_58 , int V_77 )
{
switch ( V_77 ) {
case F_40 ( V_38 [ 0 ] ) ... F_40 ( V_38 [ 31 ] ) : return V_58 -> V_38 [ V_77 - F_40 ( V_38 [ 0 ] ) ] ;
case F_40 ( V_78 [ 0 ] ) ... F_40 ( V_78 [ 7 ] ) : return V_58 -> V_78 [ V_77 - F_40 ( V_78 [ 0 ] ) ] ;
case F_40 ( V_13 [ 0 ] ) : return V_58 -> V_13 [ 0 ] ;
case F_40 ( V_13 [ 1 ] ) : return V_58 -> V_13 [ 1 ] ;
case F_40 ( V_12 [ 0 ] ) : return V_58 -> V_12 [ 0 ] ;
case F_40 ( V_12 [ 1 ] ) : return V_58 -> V_12 [ 1 ] ;
case F_40 ( V_79 ) : return V_58 -> V_79 ;
case F_40 ( V_80 ) : return V_58 -> V_80 ;
case F_40 ( V_81 ) : return V_58 -> V_81 ;
case F_40 ( V_82 ) : return V_58 -> V_82 ;
case F_40 ( V_83 ) : return V_58 -> V_83 ;
case F_40 ( V_84 ) : return V_58 -> V_84 ;
case F_40 ( V_85 ) : return F_41 ( 0 ) ;
case F_40 ( V_86 ) : return F_41 ( 24 ) ;
case F_40 ( V_87 ) : return F_41 ( 25 ) ;
case F_40 ( V_88 ) : return F_41 ( 26 ) ;
case F_40 ( V_89 ) : return F_41 ( 28 ) ;
case F_40 ( V_90 ) : return F_41 ( 29 ) ;
case F_40 ( V_91 ) : return F_41 ( 30 ) ;
case F_40 ( V_92 ) : return F_41 ( 31 ) ;
case F_40 ( V_93 ) : return F_41 ( 8 ) ;
case F_40 ( V_94 ) : return F_41 ( 9 ) ;
case F_40 ( V_95 ) : return F_41 ( 12 ) ;
case F_40 ( V_96 ) : return F_41 ( 13 ) ;
case F_40 ( V_97 ) : return F_41 ( 10 ) ;
case F_40 ( V_98 ) : return F_41 ( 15 ) ;
default: return 0 ;
}
}
static void F_42 ( struct V_34 * V_58 , int V_77 , unsigned long V_99 )
{
switch ( V_77 ) {
case F_40 ( V_38 [ 0 ] ) :
V_99 &= V_37 ;
V_58 -> V_38 [ 0 ] &= ~ V_37 ;
V_58 -> V_38 [ 0 ] |= V_99 ;
return;
case F_40 ( V_38 [ 1 ] ) ... F_40 ( V_38 [ 31 ] ) :
V_58 -> V_38 [ V_77 - F_40 ( V_38 [ 0 ] ) ] = V_99 ;
return;
case F_40 ( V_12 [ 0 ] ) :
case F_40 ( V_12 [ 1 ] ) :
V_58 -> V_12 [ V_77 - F_40 ( V_12 [ 0 ] ) ] = V_99 ;
return;
case F_40 ( V_79 ) : V_58 -> V_79 = V_99 ;
return;
default: return;
#if 0
case RI(sr[0]) ... RI(sr[7]): return regs->sr[num - RI(sr[0])];
case RI(iasq[0]): return regs->iasq[0];
case RI(iasq[1]): return regs->iasq[1];
case RI(iir): return regs->iir;
case RI(isr): return regs->isr;
case RI(ior): return regs->ior;
case RI(ipsw): return regs->ipsw;
case RI(cr27): return regs->cr27;
case cr0, cr24, cr25, cr26, cr27, cr28, cr29, cr30, cr31;
case cr8, cr9, cr12, cr13, cr10, cr15;
#endif
}
}
static int F_43 ( struct V_1 * V_64 ,
const struct V_65 * V_66 ,
unsigned int V_67 , unsigned int V_68 ,
void * V_69 , void V_21 * V_70 )
{
struct V_34 * V_58 = F_7 ( V_64 ) ;
unsigned long * V_71 = V_69 ;
unsigned long V_21 * V_72 = V_70 ;
unsigned long V_73 ;
V_67 /= sizeof( V_73 ) ;
V_68 /= sizeof( V_73 ) ;
if ( V_69 )
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 )
* V_71 ++ = F_39 ( V_58 , V_67 ++ ) ;
else
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 )
if ( F_34 ( F_39 ( V_58 , V_67 ++ ) , V_72 ++ ) )
return - V_76 ;
V_69 = V_71 ;
V_70 = V_72 ;
V_67 *= sizeof( V_73 ) ;
V_68 *= sizeof( V_73 ) ;
return F_35 ( & V_67 , & V_68 , & V_69 , & V_70 ,
V_100 * sizeof( V_73 ) , - 1 ) ;
}
static int F_44 ( struct V_1 * V_64 ,
const struct V_65 * V_66 ,
unsigned int V_67 , unsigned int V_68 ,
const void * V_69 , const void V_21 * V_70 )
{
struct V_34 * V_58 = F_7 ( V_64 ) ;
const unsigned long * V_71 = V_69 ;
const unsigned long V_21 * V_72 = V_70 ;
unsigned long V_73 ;
V_67 /= sizeof( V_73 ) ;
V_68 /= sizeof( V_73 ) ;
if ( V_69 )
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 )
F_42 ( V_58 , V_67 ++ , * V_71 ++ ) ;
else
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 ) {
if ( F_37 ( V_73 , V_72 ++ ) )
return - V_76 ;
F_42 ( V_58 , V_67 ++ , V_73 ) ;
}
V_69 = V_71 ;
V_70 = V_72 ;
V_67 *= sizeof( V_73 ) ;
V_68 *= sizeof( V_73 ) ;
return F_38 ( & V_67 , & V_68 , & V_69 , & V_70 ,
V_100 * sizeof( V_73 ) , - 1 ) ;
}
static int F_45 ( struct V_1 * V_64 ,
const struct V_65 * V_66 ,
unsigned int V_67 , unsigned int V_68 ,
void * V_69 , void V_21 * V_70 )
{
struct V_34 * V_58 = F_7 ( V_64 ) ;
T_1 * V_71 = V_69 ;
T_1 V_21 * V_72 = V_70 ;
T_1 V_73 ;
V_67 /= sizeof( V_73 ) ;
V_68 /= sizeof( V_73 ) ;
if ( V_69 )
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 )
* V_71 ++ = F_39 ( V_58 , V_67 ++ ) ;
else
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 )
if ( F_34 ( ( T_1 ) F_39 ( V_58 , V_67 ++ ) , V_72 ++ ) )
return - V_76 ;
V_69 = V_71 ;
V_70 = V_72 ;
V_67 *= sizeof( V_73 ) ;
V_68 *= sizeof( V_73 ) ;
return F_35 ( & V_67 , & V_68 , & V_69 , & V_70 ,
V_100 * sizeof( V_73 ) , - 1 ) ;
}
static int F_46 ( struct V_1 * V_64 ,
const struct V_65 * V_66 ,
unsigned int V_67 , unsigned int V_68 ,
const void * V_69 , const void V_21 * V_70 )
{
struct V_34 * V_58 = F_7 ( V_64 ) ;
const T_1 * V_71 = V_69 ;
const T_1 V_21 * V_72 = V_70 ;
T_1 V_73 ;
V_67 /= sizeof( V_73 ) ;
V_68 /= sizeof( V_73 ) ;
if ( V_69 )
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 )
F_42 ( V_58 , V_67 ++ , * V_71 ++ ) ;
else
for (; V_68 > 0 && V_67 < V_100 ; -- V_68 ) {
if ( F_37 ( V_73 , V_72 ++ ) )
return - V_76 ;
F_42 ( V_58 , V_67 ++ , V_73 ) ;
}
V_69 = V_71 ;
V_70 = V_72 ;
V_67 *= sizeof( V_73 ) ;
V_68 *= sizeof( V_73 ) ;
return F_38 ( & V_67 , & V_68 , & V_69 , & V_70 ,
V_100 * sizeof( V_73 ) , - 1 ) ;
}
const struct V_101 * F_13 ( struct V_1 * V_2 )
{
F_47 ( sizeof( struct V_49 ) / sizeof( long ) != V_100 ) ;
F_47 ( sizeof( struct V_53 ) / sizeof( V_56 ) != V_74 ) ;
#ifdef F_26
if ( F_27 () )
return & V_102 ;
#endif
return & V_103 ;
}
