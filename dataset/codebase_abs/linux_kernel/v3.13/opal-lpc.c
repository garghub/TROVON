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
void F_24 ( void )
{
struct V_11 * V_12 ;
F_25 (np, NULL, L_1 ) {
if ( ! F_26 ( V_12 ) )
continue;
if ( ! F_27 ( V_12 , L_2 , NULL ) )
continue;
V_4 = F_28 ( V_12 ) ;
break;
}
if ( V_4 < 0 )
return;
V_13 = V_14 ;
V_15 = true ;
F_29 ( L_3 , V_4 ) ;
}
