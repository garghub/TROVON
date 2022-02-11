static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = ( unsigned long ) V_2 -> V_4 ;
unsigned long V_5 ;
V_3 &= ~ V_6 ;
V_3 |= V_7 ;
F_2 ( & V_8 , V_5 ) ;
F_3 ( V_9 , ( void V_10 * ) V_3 ) ;
while ( ( F_4 ( V_11 ) & V_12 ) == 0 )
;
F_5 ( & V_8 , V_5 ) ;
}
static void F_6 ( struct V_13 * V_14 , int V_2 )
{
switch ( V_2 ) {
case - 1 :
F_7 ( V_15 , 0 , V_16 ) ;
F_7 ( V_17 , 0 , V_16 ) ;
break;
case 0 :
F_7 ( 0 , V_17 , V_16 ) ;
F_7 ( 0 , V_15 , V_16 ) ;
break;
default:
F_8 () ;
}
}
static void F_9 ( struct V_13 * V_14 , int V_18 , unsigned int V_19 )
{
struct V_1 * V_20 = V_14 -> V_21 ;
unsigned long V_3 = ( unsigned long ) V_20 -> V_4 ;
unsigned long V_5 ;
if ( V_19 & V_22 ) {
V_3 &= ~ ( V_7 | V_6 ) ;
if ( V_19 & V_23 )
V_3 |= V_7 ;
else
V_3 |= V_6 ;
V_20 -> V_4 = ( void V_10 * ) V_3 ;
}
if ( V_18 != V_24 ) {
F_2 ( & V_8 , V_5 ) ;
F_3 ( V_18 , V_20 -> V_4 ) ;
while ( ( F_4 ( V_11 ) & V_12 ) == 0 )
;
F_5 ( & V_8 , V_5 ) ;
}
}
static int F_10 ( struct V_13 * V_14 )
{
return F_4 ( V_11 ) & V_25 ;
}
static unsigned char F_11 ( struct V_13 * V_14 )
{
struct V_1 * V_20 = V_14 -> V_21 ;
unsigned long V_3 = ( unsigned long ) V_20 -> V_26 ;
unsigned long V_5 ;
int V_27 ;
F_2 ( & V_8 , V_5 ) ;
V_27 = F_12 ( ( void V_10 * ) ( V_3 + V_28 ) ) ;
F_5 ( & V_8 , V_5 ) ;
return V_27 ;
}
static int F_13 ( struct V_29 * V_30 )
{
struct V_1 * V_20 = F_14 ( V_30 ) ;
unsigned long V_3 = ( unsigned long ) V_20 -> V_4 ;
const T_1 * V_31 = F_15 ( V_30 -> V_32 . V_33 ,
L_1 , NULL ) ;
T_2 V_34 = 0 ;
if ( V_31 && ( * V_31 == 1 ) )
V_34 = V_35 | V_36 ;
F_16 ( F_17 ( V_3 )
| F_18 ( 3 ) | V_37 , V_38 ) ;
F_16 ( V_39 | V_40 | V_41
| V_42 | V_43 | V_44
| V_45 , V_46 ) ;
F_16 ( V_17 | V_47 | V_48
| V_49 | V_50 | V_51
| V_34 , V_16 ) ;
F_1 ( V_20 ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
struct V_52 * V_53 ;
struct V_29 * V_30 ;
V_53 = F_20 ( NULL , NULL , L_2 ) ;
if ( ! V_53 )
return - V_54 ;
V_30 = F_21 ( V_53 ) ;
if ( ! V_30 )
return - V_55 ;
V_30 -> V_32 . V_56 = & V_57 ;
F_22 ( V_53 ) ;
return 0 ;
}
