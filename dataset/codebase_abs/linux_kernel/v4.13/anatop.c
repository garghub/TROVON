static void F_1 ( bool V_1 )
{
T_1 V_2 , V_3 ;
F_2 ( V_4 , V_5 , & V_3 ) ;
V_2 = V_6 ;
V_2 += ( V_1 && ( V_3 & V_7 ) == 0 ) ?
V_8 : V_9 ;
F_3 ( V_4 , V_2 , V_10 ) ;
}
static void F_4 ( bool V_1 )
{
F_3 ( V_4 , V_11 + ( V_1 ? V_8 : V_9 ) ,
V_12 ) ;
}
static inline void F_5 ( bool V_1 )
{
F_3 ( V_4 , V_6 + ( V_1 ? V_8 : V_9 ) ,
V_13 ) ;
}
static inline void F_6 ( bool V_1 )
{
F_3 ( V_4 , V_5 + ( V_1 ? V_8 : V_9 ) ,
V_14 ) ;
}
void F_7 ( void )
{
if ( F_8 () == V_15 )
F_5 ( true ) ;
else
F_1 ( true ) ;
F_4 ( true ) ;
if ( F_9 () )
F_6 ( true ) ;
}
void F_10 ( void )
{
if ( F_8 () == V_15 )
F_5 ( false ) ;
else
F_1 ( false ) ;
F_4 ( false ) ;
if ( F_9 () )
F_6 ( false ) ;
}
static void F_11 ( void )
{
F_3 ( V_4 , V_16 ,
V_17
| V_18 ) ;
F_3 ( V_4 , V_19 ,
V_17 |
V_18 ) ;
}
void T_2 F_12 ( void )
{
struct V_20 * V_21 ;
void T_3 * V_22 ;
unsigned int V_23 ;
T_1 V_24 ;
T_4 V_25 = V_26 ;
V_21 = F_13 ( NULL , NULL , L_1 ) ;
V_22 = F_14 ( V_21 , 0 ) ;
F_15 ( ! V_22 ) ;
if ( F_16 ( V_21 , L_2 ) )
V_25 = V_27 ;
if ( F_16 ( V_21 , L_3 ) )
V_25 = V_28 ;
V_24 = F_17 ( V_22 + V_25 ) ;
F_18 ( V_22 ) ;
switch ( V_24 & 0xff ) {
case 0 :
if ( V_24 >> 8 & 0x01 )
V_23 = V_29 ;
else
V_23 = V_30 ;
break;
case 1 :
V_23 = V_31 ;
break;
case 2 :
V_23 = V_32 ;
break;
case 3 :
V_23 = V_33 ;
break;
case 4 :
V_23 = V_34 ;
break;
case 5 :
V_23 = V_35 ;
break;
default:
V_23 = V_24 & 0xff ;
}
F_19 ( V_24 >> 16 & 0xff ) ;
F_20 ( V_23 ) ;
}
void T_2 F_21 ( void )
{
V_4 = F_22 ( L_1 ) ;
if ( F_23 ( V_4 ) ) {
F_24 ( L_4 , V_36 ) ;
return;
}
F_11 () ;
}
