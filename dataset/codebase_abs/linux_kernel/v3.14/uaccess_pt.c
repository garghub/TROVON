static T_1 F_1 ( T_1 V_1 , const char T_2 * V_2 )
{
register unsigned long T_3 V_3 ( L_1 ) = 0UL ;
unsigned long V_4 , V_5 ;
asm volatile(
" la %2,0(%1)\n"
" la %3,0(%0,%1)\n"
" "SLR" %0,%0\n"
"0: srst %3,%2\n"
" jo 0b\n"
" la %0,1(%3)\n"
" "SLR" %0,%1\n"
"1:\n"
EX_TABLE(0b,1b)
: "+a" (count), "+a" (src), "=a" (tmp1), "=a" (tmp2)
: "d" (reg0) : "cc", "memory");
return V_1 ;
}
static T_1 F_2 ( T_1 V_1 , void T_2 * V_6 ,
const void T_2 * V_7 )
{
unsigned long V_4 ;
asm volatile(
" "AHI" %0,-1\n"
" jo 5f\n"
" bras %3,3f\n"
"0:"AHI" %0,257\n"
"1: mvc 0(1,%1),0(%2)\n"
" la %1,1(%1)\n"
" la %2,1(%2)\n"
" "AHI" %0,-1\n"
" jnz 1b\n"
" j 5f\n"
"2: mvc 0(256,%1),0(%2)\n"
" la %1,256(%1)\n"
" la %2,256(%2)\n"
"3:"AHI" %0,-256\n"
" jnm 2b\n"
"4: ex %0,1b-0b(%3)\n"
"5:"SLR" %0,%0\n"
"6:\n"
EX_TABLE(1b,6b) EX_TABLE(2b,0b) EX_TABLE(4b,0b)
: "+a" (count), "+a" (to), "+a" (from), "=a" (tmp1)
: : "cc", "memory");
return V_1 ;
}
static unsigned long F_3 ( struct V_8 * V_9 ,
unsigned long V_10 , int V_11 )
{
unsigned long * V_12 = ( unsigned long * ) F_4 ( V_9 -> V_13 ) ;
if ( F_5 ( V_10 > V_9 -> V_14 . V_15 - 1 ) )
return - 0x38UL ;
switch ( V_9 -> V_14 . V_16 & V_17 ) {
case V_18 :
V_12 = V_12 + ( ( V_10 >> 53 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_19 ) )
return - 0x39UL ;
V_12 = ( unsigned long * ) ( * V_12 & V_20 ) ;
case V_21 :
V_12 = V_12 + ( ( V_10 >> 42 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_19 ) )
return - 0x3aUL ;
V_12 = ( unsigned long * ) ( * V_12 & V_20 ) ;
case V_22 :
V_12 = V_12 + ( ( V_10 >> 31 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_19 ) )
return - 0x3bUL ;
V_12 = ( unsigned long * ) ( * V_12 & V_20 ) ;
case V_23 :
V_12 = V_12 + ( ( V_10 >> 20 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_24 ) )
return - 0x10UL ;
if ( F_5 ( * V_12 & V_25 ) ) {
if ( V_11 && ( * V_12 & V_26 ) )
return - 0x04UL ;
return ( * V_12 & V_27 ) +
( V_10 & ~ V_27 ) ;
}
V_12 = ( unsigned long * ) ( * V_12 & V_28 ) ;
}
V_12 = V_12 + ( ( V_10 >> 12 ) & 0xff ) ;
if ( F_5 ( * V_12 & V_29 ) )
return - 0x11UL ;
if ( V_11 && ( * V_12 & V_30 ) )
return - 0x04UL ;
return ( * V_12 & V_31 ) + ( V_10 & ~ V_31 ) ;
}
static unsigned long F_3 ( struct V_8 * V_9 ,
unsigned long V_10 , int V_11 )
{
unsigned long * V_12 = ( unsigned long * ) F_4 ( V_9 -> V_13 ) ;
V_12 = V_12 + ( ( V_10 >> 20 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_24 ) )
return - 0x10UL ;
V_12 = ( unsigned long * ) ( * V_12 & V_28 ) ;
V_12 = V_12 + ( ( V_10 >> 12 ) & 0xff ) ;
if ( F_5 ( * V_12 & V_29 ) )
return - 0x11UL ;
if ( V_11 && ( * V_12 & V_30 ) )
return - 0x04UL ;
return ( * V_12 & V_31 ) + ( V_10 & ~ V_31 ) ;
}
static T_4 T_1 F_6 ( unsigned long V_32 , void * V_33 ,
T_1 V_34 , int V_35 )
{
struct V_8 * V_9 = V_36 -> V_9 ;
unsigned long V_37 , V_38 , V_39 , V_40 ;
void * V_7 , * V_6 ;
if ( ! V_9 )
return V_34 ;
V_38 = 0 ;
V_41:
F_7 ( & V_9 -> V_42 ) ;
do {
V_40 = F_3 ( V_9 , V_32 , V_35 ) ;
if ( F_8 ( V_40 ) )
goto V_43;
V_37 = V_32 & ~ V_31 ;
V_39 = F_9 ( V_34 - V_38 , V_44 - V_37 ) ;
if ( V_35 ) {
V_6 = ( void * ) V_40 ;
V_7 = V_33 + V_38 ;
} else {
V_7 = ( void * ) V_40 ;
V_6 = V_33 + V_38 ;
}
memcpy ( V_6 , V_7 , V_39 ) ;
V_38 += V_39 ;
V_32 += V_39 ;
} while ( V_38 < V_34 );
F_10 ( & V_9 -> V_42 ) ;
return V_34 - V_38 ;
V_43:
F_10 ( & V_9 -> V_42 ) ;
if ( F_11 ( V_32 , - V_40 , V_35 ) )
return V_34 - V_38 ;
goto V_41;
}
static T_4 unsigned long F_12 ( unsigned long V_32 ,
int V_11 )
{
struct V_8 * V_9 = V_36 -> V_9 ;
unsigned long V_40 ;
int V_45 ;
V_41:
V_40 = F_3 ( V_9 , V_32 , V_11 ) ;
if ( F_8 ( V_40 ) )
goto V_43;
return V_40 ;
V_43:
F_10 ( & V_9 -> V_42 ) ;
V_45 = F_11 ( V_32 , - V_40 , V_11 ) ;
F_7 ( & V_9 -> V_42 ) ;
if ( ! V_45 )
goto V_41;
return 0 ;
}
static T_1 F_13 ( T_1 V_34 , const void T_2 * V_7 , void * V_6 )
{
T_1 V_45 ;
if ( F_14 ( F_15 () , V_46 ) )
return F_2 ( V_34 , ( void T_2 * ) V_6 , V_7 ) ;
V_45 = F_6 ( ( unsigned long ) V_7 , V_6 , V_34 , 0 ) ;
if ( F_5 ( V_45 ) )
memset ( V_6 + V_34 - V_45 , 0 , V_45 ) ;
return V_45 ;
}
static T_1 F_16 ( T_1 V_34 , void T_2 * V_6 , const void * V_7 )
{
if ( F_14 ( F_15 () , V_46 ) )
return F_2 ( V_34 , V_6 , ( void T_2 * ) V_7 ) ;
return F_6 ( ( unsigned long ) V_6 , ( void * ) V_7 , V_34 , 1 ) ;
}
static T_1 F_17 ( T_1 V_34 , void T_2 * V_6 )
{
void * V_47 = ( void * ) V_48 ;
long V_38 , V_39 , V_49 ;
V_38 = 0 ;
do {
if ( V_34 - V_38 > V_44 )
V_39 = V_44 ;
else
V_39 = V_34 - V_38 ;
if ( F_14 ( F_15 () , V_46 ) )
V_49 = F_2 ( V_34 , V_6 , ( void T_2 * ) V_47 ) ;
else
V_49 = F_6 ( ( unsigned long ) V_6 , V_47 , V_39 , 1 ) ;
V_38 += V_39 ;
V_6 += V_39 ;
if ( V_49 )
return V_49 + V_34 - V_38 ;
} while ( V_38 < V_34 );
return 0 ;
}
static T_1 F_18 ( T_1 V_1 , const char T_2 * V_2 )
{
unsigned long V_32 = ( unsigned long ) V_2 ;
struct V_8 * V_9 = V_36 -> V_9 ;
unsigned long V_37 , V_38 , V_50 , V_40 ;
T_1 V_51 ;
if ( F_5 ( ! V_1 ) )
return 0 ;
if ( F_14 ( F_15 () , V_46 ) )
return F_1 ( V_1 , V_2 ) ;
if ( ! V_9 )
return 0 ;
V_38 = 0 ;
V_41:
F_7 ( & V_9 -> V_42 ) ;
do {
V_40 = F_3 ( V_9 , V_32 , 0 ) ;
if ( F_8 ( V_40 ) )
goto V_43;
V_37 = V_32 & ~ V_31 ;
V_50 = F_9 ( V_1 - V_38 , V_44 - V_37 ) ;
V_51 = F_19 ( ( char * ) V_40 , V_50 ) ;
V_38 += V_51 ;
V_32 += V_51 ;
} while ( ( V_51 == V_50 ) && ( V_38 < V_1 ) );
F_10 ( & V_9 -> V_42 ) ;
return V_38 + 1 ;
V_43:
F_10 ( & V_9 -> V_42 ) ;
if ( F_11 ( V_32 , - V_40 , 0 ) )
return 0 ;
goto V_41;
}
static T_1 F_20 ( T_1 V_1 , const char T_2 * V_2 ,
char * V_52 )
{
T_1 V_38 , V_50 , V_37 , V_51 ;
if ( F_5 ( ! V_1 ) )
return 0 ;
V_38 = 0 ;
do {
V_37 = ( T_1 ) V_2 & ~ V_31 ;
V_50 = F_9 ( V_1 - V_38 , V_44 - V_37 ) ;
if ( F_14 ( F_15 () , V_46 ) ) {
if ( F_2 ( V_50 , ( void T_2 * ) V_52 , V_2 ) )
return - V_53 ;
} else {
if ( F_6 ( ( unsigned long ) V_2 , V_52 , V_50 , 0 ) )
return - V_53 ;
}
V_51 = F_19 ( V_52 , V_50 ) ;
V_38 += V_51 ;
V_2 += V_51 ;
V_52 += V_51 ;
} while ( ( V_51 == V_50 ) && ( V_38 < V_1 ) );
return V_38 ;
}
static T_1 F_21 ( T_1 V_34 , void T_2 * V_6 ,
const void T_2 * V_7 )
{
struct V_8 * V_9 = V_36 -> V_9 ;
unsigned long V_54 , V_32 , V_38 , V_39 , V_55 ;
unsigned long V_56 = ( unsigned long ) V_7 ;
unsigned long V_57 = ( unsigned long ) V_6 ;
unsigned long V_58 , V_59 ;
int V_35 ;
if ( F_14 ( F_15 () , V_46 ) )
return F_2 ( V_34 , V_6 , V_7 ) ;
if ( ! V_9 )
return V_34 ;
V_38 = 0 ;
V_41:
F_7 ( & V_9 -> V_42 ) ;
do {
V_35 = 0 ;
V_32 = V_56 ;
V_59 = F_3 ( V_9 , V_56 , 0 ) ;
V_55 = V_59 ;
if ( F_8 ( V_55 ) )
goto V_43;
V_35 = 1 ;
V_32 = V_57 ;
V_58 = F_3 ( V_9 , V_57 , 1 ) ;
V_55 = ( unsigned long ) V_58 ;
if ( F_8 ( V_55 ) )
goto V_43;
V_54 = F_22 ( V_56 & ~ V_31 ,
V_57 & ~ V_31 ) ;
V_39 = F_9 ( V_34 - V_38 , V_44 - V_54 ) ;
memcpy ( ( void * ) V_58 , ( void * ) V_59 , V_39 ) ;
V_38 += V_39 ;
V_56 += V_39 ;
V_57 += V_39 ;
} while ( V_38 < V_34 );
F_10 ( & V_9 -> V_42 ) ;
return V_34 - V_38 ;
V_43:
F_10 ( & V_9 -> V_42 ) ;
if ( F_11 ( V_32 , - V_55 , V_35 ) )
return V_34 - V_38 ;
goto V_41;
}
static int F_23 ( int V_60 , T_5 T_2 * V_32 , int V_61 , int * V_62 )
{
int V_63 = 0 , V_64 , V_49 ;
switch ( V_60 ) {
case V_65 :
F_24 ( L_2 ,
V_49 , V_63 , V_64 , V_32 , V_61 ) ;
break;
case V_66 :
F_24 ( L_3 ,
V_49 , V_63 , V_64 , V_32 , V_61 ) ;
break;
case V_67 :
F_24 ( L_4 ,
V_49 , V_63 , V_64 , V_32 , V_61 ) ;
break;
case V_68 :
F_24 ( L_5 ,
V_49 , V_63 , V_64 , V_32 , V_61 ) ;
break;
case V_69 :
F_24 ( L_6 ,
V_49 , V_63 , V_64 , V_32 , V_61 ) ;
break;
default:
V_49 = - V_70 ;
}
if ( V_49 == 0 )
* V_62 = V_63 ;
return V_49 ;
}
int F_25 ( int V_60 , T_5 T_2 * V_32 , int V_61 , int * V_62 )
{
int V_49 ;
if ( F_14 ( F_15 () , V_46 ) )
return F_23 ( V_60 , V_32 , V_61 , V_62 ) ;
if ( F_5 ( ! V_36 -> V_9 ) )
return - V_53 ;
F_7 ( & V_36 -> V_9 -> V_42 ) ;
V_32 = ( T_5 V_71 T_2 * )
F_12 ( ( V_71 unsigned long ) V_32 , 1 ) ;
if ( ! V_32 ) {
F_10 ( & V_36 -> V_9 -> V_42 ) ;
return - V_53 ;
}
F_26 ( F_27 ( V_32 ) ) ;
F_10 ( & V_36 -> V_9 -> V_42 ) ;
V_49 = F_23 ( V_60 , V_32 , V_61 , V_62 ) ;
F_28 ( F_27 ( V_32 ) ) ;
return V_49 ;
}
static int F_29 ( T_5 * V_72 , T_5 T_2 * V_32 ,
T_5 V_63 , T_5 V_64 )
{
int V_49 ;
asm volatile("0: cs %1,%4,0(%5)\n"
"1: la %0,0\n"
"2:\n"
EX_TABLE(0b,2b) EX_TABLE(1b,2b)
: "=d" (ret), "+d" (oldval), "=m" (*uaddr)
: "0" (-EFAULT), "d" (newval), "a" (uaddr), "m" (*uaddr)
: "cc", "memory" );
* V_72 = V_63 ;
return V_49 ;
}
int F_30 ( T_5 * V_72 , T_5 T_2 * V_32 ,
T_5 V_63 , T_5 V_64 )
{
int V_49 ;
if ( F_14 ( F_15 () , V_46 ) )
return F_29 ( V_72 , V_32 , V_63 , V_64 ) ;
if ( F_5 ( ! V_36 -> V_9 ) )
return - V_53 ;
F_7 ( & V_36 -> V_9 -> V_42 ) ;
V_32 = ( T_5 V_71 T_2 * )
F_12 ( ( V_71 unsigned long ) V_32 , 1 ) ;
if ( ! V_32 ) {
F_10 ( & V_36 -> V_9 -> V_42 ) ;
return - V_53 ;
}
F_26 ( F_27 ( V_32 ) ) ;
F_10 ( & V_36 -> V_9 -> V_42 ) ;
V_49 = F_29 ( V_72 , V_32 , V_63 , V_64 ) ;
F_28 ( F_27 ( V_32 ) ) ;
return V_49 ;
}
