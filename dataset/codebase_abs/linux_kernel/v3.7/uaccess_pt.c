static T_1 unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , int V_4 )
{
T_2 * V_5 ;
T_3 * V_6 ;
T_4 * V_7 ;
T_5 * V_8 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( * V_5 ) || F_4 ( F_5 ( * V_5 ) ) )
return - 0x3aUL ;
V_6 = F_6 ( V_5 , V_3 ) ;
if ( F_7 ( * V_6 ) || F_4 ( F_8 ( * V_6 ) ) )
return - 0x3bUL ;
V_7 = F_9 ( V_6 , V_3 ) ;
if ( F_10 ( * V_7 ) )
return - 0x10UL ;
if ( F_11 ( * V_7 ) ) {
if ( V_4 && ( F_12 ( * V_7 ) & V_9 ) )
return - 0x04UL ;
return ( F_12 ( * V_7 ) & V_10 ) + ( V_3 & ~ V_10 ) ;
}
if ( F_4 ( F_13 ( * V_7 ) ) )
return - 0x10UL ;
V_8 = F_14 ( V_7 , V_3 ) ;
if ( ! F_15 ( * V_8 ) )
return - 0x11UL ;
if ( V_4 && ! F_16 ( * V_8 ) )
return - 0x04UL ;
return ( F_17 ( * V_8 ) & V_11 ) + ( V_3 & ~ V_11 ) ;
}
static T_1 T_6 F_18 ( unsigned long V_12 , void * V_13 ,
T_6 V_14 , int V_15 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_17 , V_18 , V_19 , V_20 ;
void * V_21 , * V_22 ;
V_18 = 0 ;
V_23:
F_19 ( & V_2 -> V_24 ) ;
do {
V_20 = F_1 ( V_2 , V_12 , V_15 ) ;
if ( F_20 ( V_20 ) )
goto V_25;
V_17 = V_12 & ~ V_11 ;
V_19 = F_21 ( V_14 - V_18 , V_26 - V_17 ) ;
if ( V_15 ) {
V_22 = ( void * ) V_20 ;
V_21 = V_13 + V_18 ;
} else {
V_21 = ( void * ) V_20 ;
V_22 = V_13 + V_18 ;
}
memcpy ( V_22 , V_21 , V_19 ) ;
V_18 += V_19 ;
V_12 += V_19 ;
} while ( V_18 < V_14 );
F_22 ( & V_2 -> V_24 ) ;
return V_14 - V_18 ;
V_25:
F_22 ( & V_2 -> V_24 ) ;
if ( F_23 ( V_12 , - V_20 , V_15 ) )
return V_14 - V_18 ;
goto V_23;
}
static T_1 unsigned long F_24 ( unsigned long V_12 ,
int V_4 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_20 ;
int V_27 ;
V_23:
V_20 = F_1 ( V_2 , V_12 , V_4 ) ;
if ( F_20 ( V_20 ) )
goto V_25;
return V_20 ;
V_25:
F_22 ( & V_2 -> V_24 ) ;
V_27 = F_23 ( V_12 , - V_20 , V_4 ) ;
F_19 ( & V_2 -> V_24 ) ;
if ( ! V_27 )
goto V_23;
return 0 ;
}
T_6 F_25 ( T_6 V_14 , const void T_7 * V_21 , void * V_22 )
{
T_6 V_27 ;
if ( F_26 ( F_27 () , V_28 ) ) {
memcpy ( V_22 , ( void V_29 V_30 * ) V_21 , V_14 ) ;
return 0 ;
}
V_27 = F_18 ( ( unsigned long ) V_21 , V_22 , V_14 , 0 ) ;
if ( F_4 ( V_27 ) )
memset ( V_22 + V_14 - V_27 , 0 , V_27 ) ;
return V_27 ;
}
T_6 F_28 ( T_6 V_14 , void T_7 * V_22 , const void * V_21 )
{
if ( F_26 ( F_27 () , V_28 ) ) {
memcpy ( ( void V_29 V_30 * ) V_22 , V_21 , V_14 ) ;
return 0 ;
}
return F_18 ( ( unsigned long ) V_22 , ( void * ) V_21 , V_14 , 1 ) ;
}
static T_6 F_29 ( T_6 V_14 , void T_7 * V_22 )
{
long V_18 , V_19 , V_31 ;
if ( F_26 ( F_27 () , V_28 ) ) {
memset ( ( void V_29 V_30 * ) V_22 , 0 , V_14 ) ;
return 0 ;
}
V_18 = 0 ;
do {
if ( V_14 - V_18 > V_26 )
V_19 = V_26 ;
else
V_19 = V_14 - V_18 ;
V_31 = F_18 ( ( unsigned long ) V_22 + V_18 ,
& V_32 , V_19 , 1 ) ;
V_18 += V_19 ;
if ( V_31 )
return V_31 + V_14 - V_18 ;
} while ( V_18 < V_14 );
return 0 ;
}
static T_6 F_30 ( T_6 V_33 , const char T_7 * V_34 )
{
unsigned long V_12 = ( unsigned long ) V_34 ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_17 , V_18 , V_35 , V_20 ;
T_6 V_36 ;
if ( F_26 ( F_27 () , V_28 ) )
return F_31 ( ( const char V_29 V_30 * ) V_34 , V_33 ) + 1 ;
V_18 = 0 ;
V_23:
F_19 ( & V_2 -> V_24 ) ;
do {
V_20 = F_1 ( V_2 , V_12 , 0 ) ;
if ( F_20 ( V_20 ) )
goto V_25;
V_17 = V_12 & ~ V_11 ;
V_35 = F_21 ( V_33 - V_18 , V_26 - V_17 ) ;
V_36 = F_31 ( ( char * ) V_20 , V_35 ) ;
V_18 += V_36 ;
V_12 += V_36 ;
} while ( ( V_36 == V_35 ) && ( V_18 < V_33 ) );
F_22 ( & V_2 -> V_24 ) ;
return V_18 + 1 ;
V_25:
F_22 ( & V_2 -> V_24 ) ;
if ( F_23 ( V_12 , - V_20 , 0 ) )
return 0 ;
goto V_23;
}
static T_6 F_32 ( T_6 V_33 , const char T_7 * V_34 ,
char * V_37 )
{
T_6 V_14 = F_30 ( V_33 , V_34 ) ;
if ( ! V_14 )
return - V_38 ;
if ( V_14 > V_33 )
V_14 = V_33 ;
if ( F_26 ( F_27 () , V_28 ) ) {
memcpy ( V_37 , ( const char V_29 V_30 * ) V_34 , V_14 ) ;
if ( V_37 [ V_14 - 1 ] == '\0' )
return V_14 - 1 ;
else
return V_14 ;
}
if ( F_18 ( ( unsigned long ) V_34 , V_37 , V_14 , 0 ) )
return - V_38 ;
if ( V_37 [ V_14 - 1 ] == '\0' )
return V_14 - 1 ;
else
return V_14 ;
}
static T_6 F_33 ( T_6 V_14 , void T_7 * V_22 ,
const void T_7 * V_21 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_39 , V_12 , V_18 , V_19 , V_40 ;
unsigned long V_41 = ( unsigned long ) V_21 ;
unsigned long V_42 = ( unsigned long ) V_22 ;
unsigned long V_43 , V_44 ;
int V_15 ;
if ( F_26 ( F_27 () , V_28 ) ) {
memcpy ( ( void V_30 * ) V_22 , ( void V_30 * ) V_21 , V_14 ) ;
return 0 ;
}
V_18 = 0 ;
V_23:
F_19 ( & V_2 -> V_24 ) ;
do {
V_15 = 0 ;
V_12 = V_41 ;
V_44 = F_1 ( V_2 , V_41 , 0 ) ;
V_40 = V_44 ;
if ( F_20 ( V_40 ) )
goto V_25;
V_15 = 1 ;
V_12 = V_42 ;
V_43 = F_1 ( V_2 , V_42 , 1 ) ;
V_40 = ( unsigned long ) V_43 ;
if ( F_20 ( V_40 ) )
goto V_25;
V_39 = F_34 ( V_41 & ~ V_11 ,
V_42 & ~ V_11 ) ;
V_19 = F_21 ( V_14 - V_18 , V_26 - V_39 ) ;
memcpy ( ( void * ) V_43 , ( void * ) V_44 , V_19 ) ;
V_18 += V_19 ;
V_41 += V_19 ;
V_42 += V_19 ;
} while ( V_18 < V_14 );
F_22 ( & V_2 -> V_24 ) ;
return V_14 - V_18 ;
V_25:
F_22 ( & V_2 -> V_24 ) ;
if ( F_23 ( V_12 , - V_40 , V_15 ) )
return V_14 - V_18 ;
goto V_23;
}
static int F_35 ( int V_45 , T_8 T_7 * V_12 , int V_46 , int * V_47 )
{
int V_48 = 0 , V_49 , V_31 ;
switch ( V_45 ) {
case V_50 :
F_36 ( L_1 ,
V_31 , V_48 , V_49 , V_12 , V_46 ) ;
break;
case V_51 :
F_36 ( L_2 ,
V_31 , V_48 , V_49 , V_12 , V_46 ) ;
break;
case V_52 :
F_36 ( L_3 ,
V_31 , V_48 , V_49 , V_12 , V_46 ) ;
break;
case V_53 :
F_36 ( L_4 ,
V_31 , V_48 , V_49 , V_12 , V_46 ) ;
break;
case V_54 :
F_36 ( L_5 ,
V_31 , V_48 , V_49 , V_12 , V_46 ) ;
break;
default:
V_31 = - V_55 ;
}
if ( V_31 == 0 )
* V_47 = V_48 ;
return V_31 ;
}
int F_37 ( int V_45 , T_8 T_7 * V_12 , int V_46 , int * V_47 )
{
int V_31 ;
if ( F_26 ( F_27 () , V_28 ) )
return F_35 ( V_45 , V_12 , V_46 , V_47 ) ;
F_19 ( & V_16 -> V_2 -> V_24 ) ;
V_12 = ( T_8 V_30 T_7 * )
F_24 ( ( V_30 unsigned long ) V_12 , 1 ) ;
if ( ! V_12 ) {
F_22 ( & V_16 -> V_2 -> V_24 ) ;
return - V_38 ;
}
F_38 ( F_39 ( V_12 ) ) ;
F_22 ( & V_16 -> V_2 -> V_24 ) ;
V_31 = F_35 ( V_45 , V_12 , V_46 , V_47 ) ;
F_40 ( F_39 ( V_12 ) ) ;
return V_31 ;
}
static int F_41 ( T_8 * V_56 , T_8 T_7 * V_12 ,
T_8 V_48 , T_8 V_49 )
{
int V_31 ;
asm volatile("0: cs %1,%4,0(%5)\n"
"1: la %0,0\n"
"2:\n"
EX_TABLE(0b,2b) EX_TABLE(1b,2b)
: "=d" (ret), "+d" (oldval), "=m" (*uaddr)
: "0" (-EFAULT), "d" (newval), "a" (uaddr), "m" (*uaddr)
: "cc", "memory" );
* V_56 = V_48 ;
return V_31 ;
}
int F_42 ( T_8 * V_56 , T_8 T_7 * V_12 ,
T_8 V_48 , T_8 V_49 )
{
int V_31 ;
if ( F_26 ( F_27 () , V_28 ) )
return F_41 ( V_56 , V_12 , V_48 , V_49 ) ;
F_19 ( & V_16 -> V_2 -> V_24 ) ;
V_12 = ( T_8 V_30 T_7 * )
F_24 ( ( V_30 unsigned long ) V_12 , 1 ) ;
if ( ! V_12 ) {
F_22 ( & V_16 -> V_2 -> V_24 ) ;
return - V_38 ;
}
F_38 ( F_39 ( V_12 ) ) ;
F_22 ( & V_16 -> V_2 -> V_24 ) ;
V_31 = F_41 ( V_56 , V_12 , V_48 , V_49 ) ;
F_40 ( F_39 ( V_12 ) ) ;
return V_31 ;
}
