static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = & V_3 ;
}
static inline void F_1 ( struct V_1 * V_2 )
{
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_4 = & V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_5 = & V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
}
static void F_4 ( T_1 V_6 , T_2 V_7 )
{
T_2 V_8 ;
V_8 = F_5 ( V_9 ) ;
V_8 &= ~ F_6 ( V_6 , V_7 ) ;
F_7 ( V_8 , V_9 ) ;
}
static void F_8 ( T_1 V_6 , T_2 V_7 )
{
T_2 V_8 ;
V_8 = F_5 ( V_9 ) ;
V_8 |= F_6 ( V_6 , V_7 ) ;
F_7 ( V_8 , V_9 ) ;
}
static void F_9 ( void )
{
T_2 V_8 ;
V_8 = F_5 ( V_9 ) ;
V_8 &= ~ ( F_6 ( 2 , V_10 ) | V_11 ) ;
F_7 ( V_8 , V_9 ) ;
}
static void F_10 ( void )
{
T_2 V_8 ;
V_8 = F_5 ( V_9 ) ;
V_8 |= F_6 ( 2 , V_12 ) | V_11 ;
F_7 ( V_8 , V_9 ) ;
}
static T_2 T_3 F_11 ( unsigned V_13 , unsigned V_14 )
{
T_2 V_15 = 0 ;
F_4 ( 0 , V_10 ) ;
if ( V_13 == 0 )
return 0 ;
if ( V_14 )
F_12 ( L_1 , 0 ) ;
F_12 ( L_2 , 0 ) ;
F_12 ( L_3 , 0 ) ;
F_12 ( L_4 , 0 ) ;
if ( V_13 != 3 )
F_12 ( L_5 , 0 ) ;
switch ( V_13 ) {
case 3 :
V_15 = 2 ;
F_8 ( 0 , V_16 ) ;
break;
case 4 :
V_15 = 1 ;
F_8 ( 0 , V_16 ) ;
break;
case 6 :
V_15 = 3 ;
F_12 ( L_6 , 0 ) ;
F_12 ( L_7 , 0 ) ;
F_8 ( 0 , V_17 ) ;
break;
default:
F_13 ( V_18 L_8 ,
0 , V_13 ) ;
}
return V_15 << 16 ;
}
static T_2 T_3 F_14 ( unsigned V_13 )
{
T_2 V_15 = 0 ;
F_4 ( 1 , V_10 ) ;
if ( V_13 == 0 )
return 0 ;
switch ( V_13 ) {
case 2 :
V_15 = 1 ;
F_8 ( 1 , V_10 ) ;
break;
case 3 :
V_15 = 2 ;
F_8 ( 1 , V_16 ) ;
break;
case 4 :
V_15 = 1 ;
F_8 ( 1 , V_16 ) ;
break;
case 6 :
default:
F_13 ( V_18 L_8 ,
1 , V_13 ) ;
}
return V_15 << 20 ;
}
static T_2 T_3 F_15 ( unsigned V_13 , unsigned V_19 )
{
T_2 V_15 = 0 ;
F_9 () ;
V_19 = 0 ;
if ( V_19 || V_13 == 0 )
return 0 ;
F_12 ( L_9 , 0 ) ;
F_12 ( L_10 , 0 ) ;
if ( V_13 > 2 )
F_12 ( L_11 , 0 ) ;
if ( V_13 > 3 )
F_12 ( L_12 , 0 ) ;
switch ( V_13 ) {
case 2 :
V_15 = 1 ;
F_8 ( 2 , V_10 ) ;
break;
case 3 :
V_15 = 2 ;
F_8 ( 2 , V_16 ) ;
break;
case 4 :
V_15 = 1 ;
F_8 ( 2 , V_16 ) ;
break;
case 5 :
V_15 = 3 ;
F_10 () ;
break;
case 6 :
default:
F_13 ( V_18 L_8 ,
2 , V_13 ) ;
}
return V_15 << 24 ;
}
void T_3 F_16 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
if ( ! F_17 () )
return;
V_21 = F_18 ( NULL , L_13 ) ;
if ( F_19 ( V_21 ) )
return;
F_20 ( V_21 ) ;
V_2 -> V_22 = F_11 ;
V_2 -> V_23 = F_14 ;
V_2 -> V_24 = F_15 ;
F_1 ( V_2 ) ;
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_21 ) ;
F_23 ( V_21 ) ;
}
