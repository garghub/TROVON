static inline T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( * V_4 ) || F_4 ( F_5 ( * V_4 ) ) )
return ( T_1 * ) 0x3a ;
V_5 = F_6 ( V_4 , V_3 ) ;
if ( F_7 ( * V_5 ) || F_4 ( F_8 ( * V_5 ) ) )
return ( T_1 * ) 0x3b ;
V_6 = F_9 ( V_5 , V_3 ) ;
if ( F_10 ( * V_6 ) || F_4 ( F_11 ( * V_6 ) ) )
return ( T_1 * ) 0x10 ;
return F_12 ( V_6 , V_3 ) ;
}
static T_5 T_6 F_13 ( unsigned long V_7 , void * V_8 ,
T_6 V_9 , int V_10 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_12 , V_13 , V_14 , V_15 ;
T_1 * V_16 ;
void * V_17 , * V_18 ;
V_14 = 0 ;
V_19:
F_14 ( & V_2 -> V_20 ) ;
do {
V_16 = F_1 ( V_2 , V_7 ) ;
if ( ( unsigned long ) V_16 < 0x1000 )
goto V_21;
if ( ! F_15 ( * V_16 ) ) {
V_16 = ( T_1 * ) 0x11 ;
goto V_21;
} else if ( V_10 && ! F_16 ( * V_16 ) ) {
V_16 = ( T_1 * ) 0x04 ;
goto V_21;
}
V_13 = F_17 ( * V_16 ) ;
V_12 = V_7 & ( V_22 - 1 ) ;
V_15 = F_18 ( V_9 - V_14 , V_22 - V_12 ) ;
if ( V_10 ) {
V_18 = ( void * ) ( ( V_13 << V_23 ) + V_12 ) ;
V_17 = V_8 + V_14 ;
} else {
V_17 = ( void * ) ( ( V_13 << V_23 ) + V_12 ) ;
V_18 = V_8 + V_14 ;
}
memcpy ( V_18 , V_17 , V_15 ) ;
V_14 += V_15 ;
V_7 += V_15 ;
} while ( V_14 < V_9 );
F_19 ( & V_2 -> V_20 ) ;
return V_9 - V_14 ;
V_21:
F_19 ( & V_2 -> V_20 ) ;
if ( F_20 ( V_7 , ( unsigned long ) V_16 , V_10 ) )
return V_9 - V_14 ;
goto V_19;
}
static T_5 unsigned long F_21 ( unsigned long V_7 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_13 ;
T_1 * V_16 ;
int V_24 ;
V_19:
V_16 = F_1 ( V_2 , V_7 ) ;
if ( ( unsigned long ) V_16 < 0x1000 )
goto V_21;
if ( ! F_15 ( * V_16 ) ) {
V_16 = ( T_1 * ) 0x11 ;
goto V_21;
}
V_13 = F_17 ( * V_16 ) ;
return ( V_13 << V_23 ) + ( V_7 & ( V_22 - 1 ) ) ;
V_21:
F_19 ( & V_2 -> V_20 ) ;
V_24 = F_20 ( V_7 , ( unsigned long ) V_16 , 0 ) ;
F_14 ( & V_2 -> V_20 ) ;
if ( ! V_24 )
goto V_19;
return 0 ;
}
T_6 F_22 ( T_6 V_9 , const void T_7 * V_17 , void * V_18 )
{
T_6 V_24 ;
if ( F_23 ( F_24 () , V_25 ) ) {
memcpy ( V_18 , ( void V_26 V_27 * ) V_17 , V_9 ) ;
return 0 ;
}
V_24 = F_13 ( ( unsigned long ) V_17 , V_18 , V_9 , 0 ) ;
if ( F_4 ( V_24 ) )
memset ( V_18 + V_9 - V_24 , 0 , V_24 ) ;
return V_24 ;
}
T_6 F_25 ( T_6 V_9 , void T_7 * V_18 , const void * V_17 )
{
if ( F_23 ( F_24 () , V_25 ) ) {
memcpy ( ( void V_26 V_27 * ) V_18 , V_17 , V_9 ) ;
return 0 ;
}
return F_13 ( ( unsigned long ) V_18 , ( void * ) V_17 , V_9 , 1 ) ;
}
static T_6 F_26 ( T_6 V_9 , void T_7 * V_18 )
{
long V_14 , V_15 , V_28 ;
if ( F_23 ( F_24 () , V_25 ) ) {
memset ( ( void V_26 V_27 * ) V_18 , 0 , V_9 ) ;
return 0 ;
}
V_14 = 0 ;
do {
if ( V_9 - V_14 > V_22 )
V_15 = V_22 ;
else
V_15 = V_9 - V_14 ;
V_28 = F_13 ( ( unsigned long ) V_18 + V_14 ,
& V_29 , V_15 , 1 ) ;
V_14 += V_15 ;
if ( V_28 )
return V_28 + V_9 - V_14 ;
} while ( V_14 < V_9 );
return 0 ;
}
static T_6 F_27 ( T_6 V_30 , const char T_7 * V_31 )
{
char * V_3 ;
unsigned long V_7 = ( unsigned long ) V_31 ;
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_12 , V_13 , V_14 , V_32 ;
T_1 * V_16 ;
T_6 V_33 ;
if ( F_23 ( F_24 () , V_25 ) )
return F_28 ( ( const char V_26 V_27 * ) V_31 , V_30 ) + 1 ;
V_14 = 0 ;
V_19:
F_14 ( & V_2 -> V_20 ) ;
do {
V_16 = F_1 ( V_2 , V_7 ) ;
if ( ( unsigned long ) V_16 < 0x1000 )
goto V_21;
if ( ! F_15 ( * V_16 ) ) {
V_16 = ( T_1 * ) 0x11 ;
goto V_21;
}
V_13 = F_17 ( * V_16 ) ;
V_12 = V_7 & ( V_22 - 1 ) ;
V_3 = ( char * ) ( V_13 << V_23 ) + V_12 ;
V_32 = F_18 ( V_30 - V_14 , V_22 - V_12 ) ;
V_33 = F_28 ( V_3 , V_32 ) ;
V_14 += V_33 ;
V_7 += V_33 ;
} while ( ( V_33 == V_32 ) && ( V_14 < V_30 ) );
F_19 ( & V_2 -> V_20 ) ;
return V_14 + 1 ;
V_21:
F_19 ( & V_2 -> V_20 ) ;
if ( F_20 ( V_7 , ( unsigned long ) V_16 , 0 ) )
return 0 ;
goto V_19;
}
static T_6 F_29 ( T_6 V_30 , const char T_7 * V_31 ,
char * V_34 )
{
T_6 V_9 = F_27 ( V_30 , V_31 ) ;
if ( ! V_9 )
return - V_35 ;
if ( V_9 > V_30 )
V_9 = V_30 ;
if ( F_23 ( F_24 () , V_25 ) ) {
memcpy ( V_34 , ( const char V_26 V_27 * ) V_31 , V_9 ) ;
if ( V_34 [ V_9 - 1 ] == '\0' )
return V_9 - 1 ;
else
return V_9 ;
}
if ( F_13 ( ( unsigned long ) V_31 , V_34 , V_9 , 0 ) )
return - V_35 ;
if ( V_34 [ V_9 - 1 ] == '\0' )
return V_9 - 1 ;
else
return V_9 ;
}
static T_6 F_30 ( T_6 V_9 , void T_7 * V_18 ,
const void T_7 * V_17 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_36 , V_37 , V_38 , V_39 , V_40 ,
V_7 , V_14 , V_15 , V_41 ;
unsigned long V_42 = ( unsigned long ) V_17 ;
unsigned long V_43 = ( unsigned long ) V_18 ;
T_1 * V_44 , * V_45 ;
int V_10 ;
if ( F_23 ( F_24 () , V_25 ) ) {
memcpy ( ( void V_27 * ) V_18 , ( void V_27 * ) V_17 , V_9 ) ;
return 0 ;
}
V_14 = 0 ;
V_19:
F_14 ( & V_2 -> V_20 ) ;
do {
V_10 = 0 ;
V_7 = V_42 ;
V_44 = F_1 ( V_2 , V_42 ) ;
V_41 = ( unsigned long ) V_44 ;
if ( V_41 < 0x1000 )
goto V_21;
if ( ! F_15 ( * V_44 ) ) {
V_41 = 0x11 ;
goto V_21;
}
V_10 = 1 ;
V_7 = V_43 ;
V_45 = F_1 ( V_2 , V_43 ) ;
V_41 = ( unsigned long ) V_45 ;
if ( V_41 < 0x1000 )
goto V_21;
if ( ! F_15 ( * V_45 ) ) {
V_41 = 0x11 ;
goto V_21;
} else if ( ! F_16 ( * V_45 ) ) {
V_41 = 0x04 ;
goto V_21;
}
V_39 = F_17 ( * V_44 ) ;
V_40 = F_17 ( * V_45 ) ;
V_36 = V_42 & ( V_22 - 1 ) ;
V_37 = V_42 & ( V_22 - 1 ) ;
V_38 = F_31 ( V_36 , V_37 ) ;
V_15 = F_18 ( V_9 - V_14 , V_22 - V_38 ) ;
memcpy ( ( void * ) ( V_40 << V_23 ) + V_37 ,
( void * ) ( V_39 << V_23 ) + V_36 , V_15 ) ;
V_14 += V_15 ;
V_42 += V_15 ;
V_43 += V_15 ;
} while ( V_14 < V_9 );
F_19 ( & V_2 -> V_20 ) ;
return V_9 - V_14 ;
V_21:
F_19 ( & V_2 -> V_20 ) ;
if ( F_20 ( V_7 , V_41 , V_10 ) )
return V_9 - V_14 ;
goto V_19;
}
static int F_32 ( int V_46 , T_8 T_7 * V_7 , int V_47 , int * V_48 )
{
int V_49 = 0 , V_50 , V_28 ;
switch ( V_46 ) {
case V_51 :
F_33 ( L_1 ,
V_28 , V_49 , V_50 , V_7 , V_47 ) ;
break;
case V_52 :
F_33 ( L_2 ,
V_28 , V_49 , V_50 , V_7 , V_47 ) ;
break;
case V_53 :
F_33 ( L_3 ,
V_28 , V_49 , V_50 , V_7 , V_47 ) ;
break;
case V_54 :
F_33 ( L_4 ,
V_28 , V_49 , V_50 , V_7 , V_47 ) ;
break;
case V_55 :
F_33 ( L_5 ,
V_28 , V_49 , V_50 , V_7 , V_47 ) ;
break;
default:
V_28 = - V_56 ;
}
if ( V_28 == 0 )
* V_48 = V_49 ;
return V_28 ;
}
int F_34 ( int V_46 , T_8 T_7 * V_7 , int V_47 , int * V_48 )
{
int V_28 ;
if ( F_23 ( F_24 () , V_25 ) )
return F_32 ( V_46 , V_7 , V_47 , V_48 ) ;
F_14 ( & V_11 -> V_2 -> V_20 ) ;
V_7 = ( int T_7 * ) F_21 ( ( unsigned long ) V_7 ) ;
if ( ! V_7 ) {
F_19 ( & V_11 -> V_2 -> V_20 ) ;
return - V_35 ;
}
F_35 ( F_36 ( V_7 ) ) ;
F_19 ( & V_11 -> V_2 -> V_20 ) ;
V_28 = F_32 ( V_46 , V_7 , V_47 , V_48 ) ;
F_37 ( F_36 ( V_7 ) ) ;
return V_28 ;
}
static int F_38 ( T_8 * V_57 , T_8 T_7 * V_7 ,
T_8 V_49 , T_8 V_50 )
{
int V_28 ;
asm volatile("0: cs %1,%4,0(%5)\n"
"1: la %0,0\n"
"2:\n"
EX_TABLE(0b,2b) EX_TABLE(1b,2b)
: "=d" (ret), "+d" (oldval), "=m" (*uaddr)
: "0" (-EFAULT), "d" (newval), "a" (uaddr), "m" (*uaddr)
: "cc", "memory" );
* V_57 = V_49 ;
return V_28 ;
}
int F_39 ( T_8 * V_57 , T_8 T_7 * V_7 ,
T_8 V_49 , T_8 V_50 )
{
int V_28 ;
if ( F_23 ( F_24 () , V_25 ) )
return F_38 ( V_57 , V_7 , V_49 , V_50 ) ;
F_14 ( & V_11 -> V_2 -> V_20 ) ;
V_7 = ( int T_7 * ) F_21 ( ( unsigned long ) V_7 ) ;
if ( ! V_7 ) {
F_19 ( & V_11 -> V_2 -> V_20 ) ;
return - V_35 ;
}
F_35 ( F_36 ( V_7 ) ) ;
F_19 ( & V_11 -> V_2 -> V_20 ) ;
V_28 = F_38 ( V_57 , V_7 , V_49 , V_50 ) ;
F_37 ( F_36 ( V_7 ) ) ;
return V_28 ;
}
