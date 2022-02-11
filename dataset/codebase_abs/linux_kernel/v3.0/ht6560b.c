static inline T_1 F_1 ( T_2 * V_1 )
{
return ( ( unsigned long ) F_2 ( V_1 ) & 0xff00 ) >> 8 ;
}
static inline T_1 F_3 ( T_2 * V_1 )
{
return ( unsigned long ) F_2 ( V_1 ) & 0x00ff ;
}
static void F_4 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
unsigned long V_3 ;
static T_1 V_4 = 0 ;
static T_1 V_5 = 0 ;
T_1 V_6 , V_7 ;
F_5 ( V_3 ) ;
V_6 = F_1 ( V_1 ) ;
V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_8 != V_9 ||
( V_1 -> V_10 & V_11 ) == 0 )
V_6 |= V_12 ;
if ( V_6 != V_4 || V_7 != V_5 ) {
V_4 = V_6 ;
V_5 = V_7 ;
( void ) F_6 ( V_13 ) ;
( void ) F_6 ( V_13 ) ;
( void ) F_6 ( V_13 ) ;
( void ) F_6 ( V_13 ) ;
F_7 ( V_6 , V_13 ) ;
F_7 ( V_7 , V_2 -> V_14 . V_15 ) ;
( void ) F_6 ( V_2 -> V_14 . V_16 ) ;
#ifdef F_8
F_9 ( L_1 ,
V_1 -> V_17 , V_6 , V_7 ) ;
#endif
}
F_10 ( V_3 ) ;
F_7 ( V_1 -> V_6 | V_18 , V_2 -> V_14 . V_15 ) ;
}
static int T_4 F_11 ( void )
{
T_1 V_19 ;
int V_20 ;
if ( ( V_19 = F_6 ( V_13 ) ) == 0xff )
return 0 ;
for ( V_20 = 3 ; V_20 > 0 ; V_20 -- ) {
F_7 ( 0x00 , V_13 ) ;
if ( ! ( ( ~ F_6 ( V_13 ) ) & 0x3f ) ) {
F_7 ( V_19 , V_13 ) ;
return 0 ;
}
}
F_7 ( 0x00 , V_13 ) ;
if ( ( ~ F_6 ( V_13 ) ) & 0x3f ) {
F_7 ( V_19 , V_13 ) ;
return 0 ;
}
F_7 ( V_21 , V_13 ) ;
F_7 ( V_22 , 0x1f6 ) ;
( void ) F_6 ( 0x1f7 ) ;
F_9 ( L_2 V_23
L_3
#ifdef F_8
L_4
#endif
L_5
) ;
return 1 ;
}
static T_1 F_12 ( T_2 * V_1 , const T_1 V_24 )
{
int V_25 , V_26 ;
int V_27 , V_28 ;
int V_29 = V_30 ? V_30 : 50 ;
if ( V_24 ) {
unsigned int V_31 ;
struct V_32 * V_33 = F_13 ( V_34 + V_24 ) ;
V_31 = F_14 ( V_1 , V_24 ) ;
V_25 = V_33 -> V_35 ;
V_26 = V_31 - V_25 - V_33 -> V_36 ;
V_27 = ( V_25 * V_29 + 999 ) / 1000 ;
V_28 = ( V_26 * V_29 + 999 ) / 1000 ;
if ( V_27 < 2 ) V_27 = 2 ;
if ( V_28 < 2 ) V_28 = 2 ;
if ( V_27 > 15 ) V_27 = 15 ;
if ( V_28 > 15 ) V_28 = 0 ;
#ifdef F_8
F_9 ( L_6 , V_1 -> V_17 , V_24 , V_28 , V_26 , V_27 , V_25 ) ;
#endif
return ( T_1 ) ( ( V_28 << 4 ) | V_27 ) ;
} else {
#ifdef F_8
F_9 ( L_7 , V_1 -> V_17 ) ;
#endif
return V_22 ;
}
}
static void F_15 ( T_2 * V_1 , T_1 V_37 )
{
unsigned long V_3 , V_38 ;
int V_33 = V_12 << 8 ;
F_16 ( & V_39 , V_3 ) ;
V_38 = ( unsigned long ) F_2 ( V_1 ) ;
if ( V_37 ) {
V_38 |= V_33 ;
V_1 -> V_10 |= V_40 ;
V_1 -> V_10 &= ~ V_41 ;
} else {
V_38 &= ~ V_33 ;
V_1 -> V_10 &= ~ V_40 ;
}
F_17 ( V_1 , ( void * ) V_38 ) ;
F_18 ( & V_39 , V_3 ) ;
#ifdef F_8
F_9 ( L_8 , V_1 -> V_17 , ( V_37 ? L_9 : L_10 ) ) ;
#endif
}
static void F_19 ( T_3 * V_2 , T_2 * V_1 )
{
unsigned long V_3 , V_38 ;
const T_1 V_24 = V_1 -> V_42 - V_34 ;
T_1 V_7 ;
switch ( V_24 ) {
case 8 :
case 9 :
F_15 ( V_1 , V_24 & 1 ) ;
return;
}
V_7 = F_12 ( V_1 , V_24 ) ;
F_16 ( & V_39 , V_3 ) ;
V_38 = ( unsigned long ) F_2 ( V_1 ) ;
V_38 &= 0xff00 ;
V_38 |= V_7 ;
F_17 ( V_1 , ( void * ) V_38 ) ;
F_18 ( & V_39 , V_3 ) ;
#ifdef F_8
F_9 ( L_11 , V_1 -> V_17 , V_24 , V_7 ) ;
#endif
}
static void T_4 F_20 ( T_2 * V_1 )
{
T_3 * V_2 = V_1 -> V_2 ;
int V_33 = ( V_21 << 8 ) | V_22 ;
if ( V_2 -> V_43 )
V_33 |= ( V_44 << 8 ) ;
F_17 ( V_1 , ( void * ) V_33 ) ;
}
static int T_4 F_21 ( void )
{
if ( V_45 == 0 )
return - V_46 ;
if ( ! F_22 ( V_13 , 1 , V_47 ) ) {
F_9 ( V_48 L_12 ,
V_49 ) ;
return - V_46 ;
}
if ( ! F_11 () ) {
F_9 ( V_48 L_13 , V_49 ) ;
goto V_50;
}
return F_23 ( & V_51 , 0 ) ;
V_50:
V_50 ( V_13 , 1 ) ;
return - V_46 ;
}
