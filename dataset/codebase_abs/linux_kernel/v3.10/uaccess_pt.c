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
switch ( V_9 -> V_14 . V_15 & V_16 ) {
case V_17 :
V_12 = V_12 + ( ( V_10 >> 53 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_18 ) )
return - 0x39UL ;
V_12 = ( unsigned long * ) ( * V_12 & V_19 ) ;
case V_20 :
V_12 = V_12 + ( ( V_10 >> 42 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_18 ) )
return - 0x3aUL ;
V_12 = ( unsigned long * ) ( * V_12 & V_19 ) ;
case V_21 :
V_12 = V_12 + ( ( V_10 >> 31 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_18 ) )
return - 0x3bUL ;
V_12 = ( unsigned long * ) ( * V_12 & V_19 ) ;
case V_22 :
V_12 = V_12 + ( ( V_10 >> 20 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_23 ) )
return - 0x10UL ;
if ( F_5 ( * V_12 & V_24 ) ) {
if ( V_11 && ( * V_12 & V_25 ) )
return - 0x04UL ;
return ( * V_12 & V_26 ) +
( V_10 & ~ V_26 ) ;
}
V_12 = ( unsigned long * ) ( * V_12 & V_27 ) ;
}
V_12 = V_12 + ( ( V_10 >> 12 ) & 0xff ) ;
if ( F_5 ( * V_12 & V_28 ) )
return - 0x11UL ;
if ( V_11 && ( * V_12 & V_29 ) )
return - 0x04UL ;
return ( * V_12 & V_30 ) + ( V_10 & ~ V_30 ) ;
}
static unsigned long F_3 ( struct V_8 * V_9 ,
unsigned long V_10 , int V_11 )
{
unsigned long * V_12 = ( unsigned long * ) F_4 ( V_9 -> V_13 ) ;
V_12 = V_12 + ( ( V_10 >> 20 ) & 0x7ff ) ;
if ( F_5 ( * V_12 & V_23 ) )
return - 0x10UL ;
V_12 = ( unsigned long * ) ( * V_12 & V_27 ) ;
V_12 = V_12 + ( ( V_10 >> 12 ) & 0xff ) ;
if ( F_5 ( * V_12 & V_28 ) )
return - 0x11UL ;
if ( V_11 && ( * V_12 & V_29 ) )
return - 0x04UL ;
return ( * V_12 & V_30 ) + ( V_10 & ~ V_30 ) ;
}
static T_4 T_1 F_6 ( unsigned long V_31 , void * V_32 ,
T_1 V_33 , int V_34 )
{
struct V_8 * V_9 = V_35 -> V_9 ;
unsigned long V_36 , V_37 , V_38 , V_39 ;
void * V_7 , * V_6 ;
V_37 = 0 ;
V_40:
F_7 ( & V_9 -> V_41 ) ;
do {
V_39 = F_3 ( V_9 , V_31 , V_34 ) ;
if ( F_8 ( V_39 ) )
goto V_42;
V_36 = V_31 & ~ V_30 ;
V_38 = F_9 ( V_33 - V_37 , V_43 - V_36 ) ;
if ( V_34 ) {
V_6 = ( void * ) V_39 ;
V_7 = V_32 + V_37 ;
} else {
V_7 = ( void * ) V_39 ;
V_6 = V_32 + V_37 ;
}
memcpy ( V_6 , V_7 , V_38 ) ;
V_37 += V_38 ;
V_31 += V_38 ;
} while ( V_37 < V_33 );
F_10 ( & V_9 -> V_41 ) ;
return V_33 - V_37 ;
V_42:
F_10 ( & V_9 -> V_41 ) ;
if ( F_11 ( V_31 , - V_39 , V_34 ) )
return V_33 - V_37 ;
goto V_40;
}
static T_4 unsigned long F_12 ( unsigned long V_31 ,
int V_11 )
{
struct V_8 * V_9 = V_35 -> V_9 ;
unsigned long V_39 ;
int V_44 ;
V_40:
V_39 = F_3 ( V_9 , V_31 , V_11 ) ;
if ( F_8 ( V_39 ) )
goto V_42;
return V_39 ;
V_42:
F_10 ( & V_9 -> V_41 ) ;
V_44 = F_11 ( V_31 , - V_39 , V_11 ) ;
F_7 ( & V_9 -> V_41 ) ;
if ( ! V_44 )
goto V_40;
return 0 ;
}
T_1 F_13 ( T_1 V_33 , const void T_2 * V_7 , void * V_6 )
{
T_1 V_44 ;
if ( F_14 ( F_15 () , V_45 ) )
return F_2 ( V_33 , ( void T_2 * ) V_6 , V_7 ) ;
V_44 = F_6 ( ( unsigned long ) V_7 , V_6 , V_33 , 0 ) ;
if ( F_5 ( V_44 ) )
memset ( V_6 + V_33 - V_44 , 0 , V_44 ) ;
return V_44 ;
}
T_1 F_16 ( T_1 V_33 , void T_2 * V_6 , const void * V_7 )
{
if ( F_14 ( F_15 () , V_45 ) )
return F_2 ( V_33 , V_6 , ( void T_2 * ) V_7 ) ;
return F_6 ( ( unsigned long ) V_6 , ( void * ) V_7 , V_33 , 1 ) ;
}
static T_1 F_17 ( T_1 V_33 , void T_2 * V_6 )
{
void * V_46 = ( void * ) V_47 ;
long V_37 , V_38 , V_48 ;
V_37 = 0 ;
do {
if ( V_33 - V_37 > V_43 )
V_38 = V_43 ;
else
V_38 = V_33 - V_37 ;
if ( F_14 ( F_15 () , V_45 ) )
V_48 = F_2 ( V_33 , V_6 , ( void T_2 * ) V_46 ) ;
else
V_48 = F_6 ( ( unsigned long ) V_6 , V_46 , V_38 , 1 ) ;
V_37 += V_38 ;
V_6 += V_38 ;
if ( V_48 )
return V_48 + V_33 - V_37 ;
} while ( V_37 < V_33 );
return 0 ;
}
static T_1 F_18 ( T_1 V_1 , const char T_2 * V_2 )
{
unsigned long V_31 = ( unsigned long ) V_2 ;
struct V_8 * V_9 = V_35 -> V_9 ;
unsigned long V_36 , V_37 , V_49 , V_39 ;
T_1 V_50 ;
if ( F_5 ( ! V_1 ) )
return 0 ;
if ( F_14 ( F_15 () , V_45 ) )
return F_1 ( V_1 , V_2 ) ;
V_37 = 0 ;
V_40:
F_7 ( & V_9 -> V_41 ) ;
do {
V_39 = F_3 ( V_9 , V_31 , 0 ) ;
if ( F_8 ( V_39 ) )
goto V_42;
V_36 = V_31 & ~ V_30 ;
V_49 = F_9 ( V_1 - V_37 , V_43 - V_36 ) ;
V_50 = F_19 ( ( char * ) V_39 , V_49 ) ;
V_37 += V_50 ;
V_31 += V_50 ;
} while ( ( V_50 == V_49 ) && ( V_37 < V_1 ) );
F_10 ( & V_9 -> V_41 ) ;
return V_37 + 1 ;
V_42:
F_10 ( & V_9 -> V_41 ) ;
if ( F_11 ( V_31 , - V_39 , 0 ) )
return 0 ;
goto V_40;
}
static T_1 F_20 ( T_1 V_1 , const char T_2 * V_2 ,
char * V_51 )
{
T_1 V_37 , V_49 , V_36 , V_50 ;
if ( F_5 ( ! V_1 ) )
return 0 ;
V_37 = 0 ;
do {
V_36 = ( T_1 ) V_2 & ~ V_30 ;
V_49 = F_9 ( V_1 - V_37 , V_43 - V_36 ) ;
if ( F_14 ( F_15 () , V_45 ) ) {
if ( F_2 ( V_49 , ( void T_2 * ) V_51 , V_2 ) )
return - V_52 ;
} else {
if ( F_6 ( ( unsigned long ) V_2 , V_51 , V_49 , 0 ) )
return - V_52 ;
}
V_50 = F_19 ( V_51 , V_49 ) ;
V_37 += V_50 ;
V_2 += V_50 ;
V_51 += V_50 ;
} while ( ( V_50 == V_49 ) && ( V_37 < V_1 ) );
return V_37 ;
}
static T_1 F_21 ( T_1 V_33 , void T_2 * V_6 ,
const void T_2 * V_7 )
{
struct V_8 * V_9 = V_35 -> V_9 ;
unsigned long V_53 , V_31 , V_37 , V_38 , V_54 ;
unsigned long V_55 = ( unsigned long ) V_7 ;
unsigned long V_56 = ( unsigned long ) V_6 ;
unsigned long V_57 , V_58 ;
int V_34 ;
if ( F_14 ( F_15 () , V_45 ) )
return F_2 ( V_33 , V_6 , V_7 ) ;
V_37 = 0 ;
V_40:
F_7 ( & V_9 -> V_41 ) ;
do {
V_34 = 0 ;
V_31 = V_55 ;
V_58 = F_3 ( V_9 , V_55 , 0 ) ;
V_54 = V_58 ;
if ( F_8 ( V_54 ) )
goto V_42;
V_34 = 1 ;
V_31 = V_56 ;
V_57 = F_3 ( V_9 , V_56 , 1 ) ;
V_54 = ( unsigned long ) V_57 ;
if ( F_8 ( V_54 ) )
goto V_42;
V_53 = F_22 ( V_55 & ~ V_30 ,
V_56 & ~ V_30 ) ;
V_38 = F_9 ( V_33 - V_37 , V_43 - V_53 ) ;
memcpy ( ( void * ) V_57 , ( void * ) V_58 , V_38 ) ;
V_37 += V_38 ;
V_55 += V_38 ;
V_56 += V_38 ;
} while ( V_37 < V_33 );
F_10 ( & V_9 -> V_41 ) ;
return V_33 - V_37 ;
V_42:
F_10 ( & V_9 -> V_41 ) ;
if ( F_11 ( V_31 , - V_54 , V_34 ) )
return V_33 - V_37 ;
goto V_40;
}
static int F_23 ( int V_59 , T_5 T_2 * V_31 , int V_60 , int * V_61 )
{
int V_62 = 0 , V_63 , V_48 ;
switch ( V_59 ) {
case V_64 :
F_24 ( L_2 ,
V_48 , V_62 , V_63 , V_31 , V_60 ) ;
break;
case V_65 :
F_24 ( L_3 ,
V_48 , V_62 , V_63 , V_31 , V_60 ) ;
break;
case V_66 :
F_24 ( L_4 ,
V_48 , V_62 , V_63 , V_31 , V_60 ) ;
break;
case V_67 :
F_24 ( L_5 ,
V_48 , V_62 , V_63 , V_31 , V_60 ) ;
break;
case V_68 :
F_24 ( L_6 ,
V_48 , V_62 , V_63 , V_31 , V_60 ) ;
break;
default:
V_48 = - V_69 ;
}
if ( V_48 == 0 )
* V_61 = V_62 ;
return V_48 ;
}
int F_25 ( int V_59 , T_5 T_2 * V_31 , int V_60 , int * V_61 )
{
int V_48 ;
if ( F_14 ( F_15 () , V_45 ) )
return F_23 ( V_59 , V_31 , V_60 , V_61 ) ;
F_7 ( & V_35 -> V_9 -> V_41 ) ;
V_31 = ( T_5 V_70 T_2 * )
F_12 ( ( V_70 unsigned long ) V_31 , 1 ) ;
if ( ! V_31 ) {
F_10 ( & V_35 -> V_9 -> V_41 ) ;
return - V_52 ;
}
F_26 ( F_27 ( V_31 ) ) ;
F_10 ( & V_35 -> V_9 -> V_41 ) ;
V_48 = F_23 ( V_59 , V_31 , V_60 , V_61 ) ;
F_28 ( F_27 ( V_31 ) ) ;
return V_48 ;
}
static int F_29 ( T_5 * V_71 , T_5 T_2 * V_31 ,
T_5 V_62 , T_5 V_63 )
{
int V_48 ;
asm volatile("0: cs %1,%4,0(%5)\n"
"1: la %0,0\n"
"2:\n"
EX_TABLE(0b,2b) EX_TABLE(1b,2b)
: "=d" (ret), "+d" (oldval), "=m" (*uaddr)
: "0" (-EFAULT), "d" (newval), "a" (uaddr), "m" (*uaddr)
: "cc", "memory" );
* V_71 = V_62 ;
return V_48 ;
}
int F_30 ( T_5 * V_71 , T_5 T_2 * V_31 ,
T_5 V_62 , T_5 V_63 )
{
int V_48 ;
if ( F_14 ( F_15 () , V_45 ) )
return F_29 ( V_71 , V_31 , V_62 , V_63 ) ;
F_7 ( & V_35 -> V_9 -> V_41 ) ;
V_31 = ( T_5 V_70 T_2 * )
F_12 ( ( V_70 unsigned long ) V_31 , 1 ) ;
if ( ! V_31 ) {
F_10 ( & V_35 -> V_9 -> V_41 ) ;
return - V_52 ;
}
F_26 ( F_27 ( V_31 ) ) ;
F_10 ( & V_35 -> V_9 -> V_41 ) ;
V_48 = F_29 ( V_71 , V_31 , V_62 , V_63 ) ;
F_28 ( F_27 ( V_31 ) ) ;
return V_48 ;
}
