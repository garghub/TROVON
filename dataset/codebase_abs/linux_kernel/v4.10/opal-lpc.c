static T_1 F_1 ( unsigned long V_1 )
{
T_2 V_2 ;
T_3 V_3 ;
if ( V_4 < 0 || V_1 > 0xffff )
return 0xff ;
V_2 = F_2 ( V_4 , V_5 , V_1 , & V_3 , 1 ) ;
return V_2 ? 0xff : F_3 ( V_3 ) ;
}
static T_4 F_4 ( unsigned long V_1 )
{
T_2 V_2 ;
T_3 V_3 ;
if ( V_4 < 0 || V_1 > 0xfffe )
return 0xffff ;
if ( V_1 & 1 )
return ( T_4 ) F_1 ( V_1 ) << 8 | F_1 ( V_1 + 1 ) ;
V_2 = F_2 ( V_4 , V_5 , V_1 , & V_3 , 2 ) ;
return V_2 ? 0xffff : F_3 ( V_3 ) ;
}
static T_5 F_5 ( unsigned long V_1 )
{
return F_6 ( F_4 ( V_1 ) ) ;
}
static T_6 F_7 ( unsigned long V_1 )
{
T_2 V_2 ;
T_3 V_3 ;
if ( V_4 < 0 || V_1 > 0xfffc )
return 0xffffffff ;
if ( V_1 & 3 )
return ( T_6 ) F_1 ( V_1 ) << 24 |
( T_6 ) F_1 ( V_1 + 1 ) << 16 |
( T_6 ) F_1 ( V_1 + 2 ) << 8 |
F_1 ( V_1 + 3 ) ;
V_2 = F_2 ( V_4 , V_5 , V_1 , & V_3 , 4 ) ;
return V_2 ? 0xffffffff : F_3 ( V_3 ) ;
}
static T_7 F_8 ( unsigned long V_1 )
{
return F_9 ( F_7 ( V_1 ) ) ;
}
static void F_10 ( T_1 V_6 , unsigned long V_1 )
{
if ( V_4 < 0 || V_1 > 0xffff )
return;
F_11 ( V_4 , V_5 , V_1 , V_6 , 1 ) ;
}
static void F_12 ( T_4 V_6 , unsigned long V_1 )
{
if ( V_4 < 0 || V_1 > 0xfffe )
return;
if ( V_1 & 1 ) {
F_10 ( V_6 >> 8 , V_1 ) ;
F_10 ( V_6 , V_1 + 1 ) ;
return;
}
F_11 ( V_4 , V_5 , V_1 , V_6 , 2 ) ;
}
static void F_13 ( T_5 V_6 , unsigned long V_1 )
{
F_12 ( F_14 ( V_6 ) , V_1 ) ;
}
static void F_15 ( T_6 V_6 , unsigned long V_1 )
{
if ( V_4 < 0 || V_1 > 0xfffc )
return;
if ( V_1 & 3 ) {
F_10 ( V_6 >> 24 , V_1 ) ;
F_10 ( V_6 >> 16 , V_1 + 1 ) ;
F_10 ( V_6 >> 8 , V_1 + 2 ) ;
F_10 ( V_6 , V_1 + 3 ) ;
return;
}
F_11 ( V_4 , V_5 , V_1 , V_6 , 4 ) ;
}
static void F_16 ( T_7 V_6 , unsigned long V_1 )
{
F_15 ( F_17 ( V_6 ) , V_1 ) ;
}
static void F_18 ( unsigned long V_7 , void * V_8 , unsigned long V_9 )
{
T_1 * V_10 = V_8 ;
while( V_9 -- )
* ( V_10 ++ ) = F_1 ( V_7 ) ;
}
static void F_19 ( unsigned long V_7 , void * V_8 , unsigned long V_9 )
{
T_4 * V_10 = V_8 ;
while( V_9 -- )
* ( V_10 ++ ) = F_4 ( V_7 ) ;
}
static void F_20 ( unsigned long V_7 , void * V_8 , unsigned long V_9 )
{
T_6 * V_10 = V_8 ;
while( V_9 -- )
* ( V_10 ++ ) = F_7 ( V_7 ) ;
}
static void F_21 ( unsigned long V_7 , const void * V_8 , unsigned long V_9 )
{
const T_1 * V_10 = V_8 ;
while( V_9 -- )
F_10 ( * ( V_10 ++ ) , V_7 ) ;
}
static void F_22 ( unsigned long V_7 , const void * V_8 , unsigned long V_9 )
{
const T_4 * V_10 = V_8 ;
while( V_9 -- )
F_12 ( * ( V_10 ++ ) , V_7 ) ;
}
static void F_23 ( unsigned long V_7 , const void * V_8 , unsigned long V_9 )
{
const T_6 * V_10 = V_8 ;
while( V_9 -- )
F_15 ( * ( V_10 ++ ) , V_7 ) ;
}
static T_8 F_24 ( struct V_11 * V_12 , char T_9 * V_13 ,
T_10 V_14 , T_11 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
T_7 V_3 , V_19 , V_20 , V_21 ;
int V_2 ;
if ( ! F_25 ( V_22 , V_13 , V_14 ) )
return - V_23 ;
V_21 = V_14 ;
while ( V_21 ) {
V_19 = * V_15 ;
V_20 = 1 ;
if ( V_17 -> V_24 == V_25 ) {
if ( V_21 > 3 && ( V_19 & 3 ) == 0 )
V_20 = 4 ;
else if ( V_21 > 1 && ( V_19 & 1 ) == 0 )
V_20 = 2 ;
}
V_2 = F_2 ( V_4 , V_17 -> V_24 , V_19 ,
& V_3 , V_20 ) ;
if ( V_2 )
return - V_26 ;
switch( V_20 ) {
case 4 :
V_2 = F_26 ( ( T_7 ) V_3 , ( T_7 T_9 * ) V_13 ) ;
break;
case 2 :
#ifdef F_27
V_3 >>= 16 ;
#endif
V_2 = F_26 ( ( T_5 ) V_3 , ( T_5 T_9 * ) V_13 ) ;
break;
default:
#ifdef F_27
V_3 >>= 24 ;
#endif
V_2 = F_26 ( ( T_1 ) V_3 , ( T_1 T_9 * ) V_13 ) ;
break;
}
if ( V_2 )
return - V_23 ;
* V_15 += V_20 ;
V_13 += V_20 ;
V_21 -= V_20 ;
}
return V_14 ;
}
static T_8 F_28 ( struct V_11 * V_12 , const char T_9 * V_13 ,
T_10 V_14 , T_11 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
T_7 V_3 , V_19 , V_20 , V_21 ;
int V_2 ;
if ( ! F_25 ( V_27 , V_13 , V_14 ) )
return - V_23 ;
V_21 = V_14 ;
while ( V_21 ) {
V_19 = * V_15 ;
V_20 = 1 ;
if ( V_17 -> V_24 == V_25 ) {
if ( V_21 > 3 && ( V_19 & 3 ) == 0 )
V_20 = 4 ;
else if ( V_21 > 1 && ( V_19 & 1 ) == 0 )
V_20 = 2 ;
}
switch( V_20 ) {
case 4 :
V_2 = F_29 ( V_3 , ( T_7 T_9 * ) V_13 ) ;
V_3 = F_30 ( V_3 ) ;
break;
case 2 :
V_2 = F_29 ( V_3 , ( T_5 T_9 * ) V_13 ) ;
V_3 = F_31 ( V_3 ) ;
break;
default:
V_2 = F_29 ( V_3 , ( T_1 T_9 * ) V_13 ) ;
break;
}
if ( V_2 )
return - V_23 ;
V_2 = F_11 ( V_4 , V_17 -> V_24 , V_19 ,
V_3 , V_20 ) ;
if ( V_2 )
return - V_26 ;
* V_15 += V_20 ;
V_13 += V_20 ;
V_21 -= V_20 ;
}
return V_14 ;
}
static int F_32 ( struct V_28 * V_29 ,
const char * V_30 ,
enum V_31 type )
{
struct V_16 * V_32 ;
V_32 = F_33 ( sizeof( * V_32 ) , V_33 ) ;
if ( ! V_32 )
return - V_34 ;
V_32 -> V_24 = type ;
F_34 ( V_30 , 0600 , V_29 , V_32 , & V_35 ) ;
return 0 ;
}
static int F_35 ( void )
{
struct V_28 * V_36 ;
int V_2 = 0 ;
if ( V_4 < 0 )
return - V_37 ;
V_36 = F_36 ( L_1 , V_38 ) ;
V_2 |= F_32 ( V_36 , L_2 , V_5 ) ;
V_2 |= F_32 ( V_36 , L_3 , V_39 ) ;
V_2 |= F_32 ( V_36 , L_4 , V_25 ) ;
return V_2 ;
}
void F_37 ( void )
{
struct V_40 * V_41 ;
F_38 (np, NULL, L_5 ) {
if ( ! F_39 ( V_41 ) )
continue;
if ( ! F_40 ( V_41 , L_6 , NULL ) )
continue;
V_4 = F_41 ( V_41 ) ;
break;
}
if ( V_4 < 0 )
return;
V_42 = V_43 ;
V_44 = true ;
F_42 ( L_7 , V_4 ) ;
}
