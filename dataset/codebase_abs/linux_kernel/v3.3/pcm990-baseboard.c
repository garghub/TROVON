static void F_1 ( int V_1 , struct V_2 * V_3 )
{
if ( V_1 ) {
F_2 ( V_4 + V_5 ) =
V_6 + V_7 ;
} else {
F_2 ( V_4 + V_5 ) = 0x00 ;
}
}
static void F_3 ( struct V_8 * V_9 )
{
int V_10 = ( V_9 -> V_11 - F_4 ( 0 ) ) ;
V_12 = ( V_13 &= ~ ( 1 << V_10 ) ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
int V_10 = ( V_9 -> V_11 - F_4 ( 0 ) ) ;
V_14 |= 1 << V_10 ;
V_12 = ( V_13 |= ( 1 << V_10 ) ) ;
}
static void F_6 ( unsigned int V_11 , struct V_15 * V_16 )
{
unsigned long V_17 = ( ~ V_14 ) & V_13 ;
do {
V_16 -> V_8 . V_18 -> V_19 ( & V_16 -> V_8 ) ;
if ( F_7 ( V_17 ) ) {
V_11 = F_4 ( 0 ) + F_8 ( V_17 ) ;
F_9 ( V_11 ) ;
}
V_17 = ( ~ V_14 ) & V_13 ;
} while ( V_17 );
}
static void T_1 F_10 ( void )
{
int V_11 ;
for ( V_11 = F_4 ( 0 ) ; V_11 <= F_4 ( 3 ) ; V_11 ++ ) {
F_11 ( V_11 , & V_20 ,
V_21 ) ;
F_12 ( V_11 , V_22 | V_23 ) ;
}
V_12 = 0x00 ;
V_14 = 0xFF ;
F_13 ( V_24 , F_6 ) ;
F_14 ( V_24 , V_25 ) ;
}
static int F_15 ( struct V_26 * V_27 , T_2 V_28 ,
void * V_29 )
{
int V_30 ;
V_30 = F_16 ( V_31 , V_28 , V_32 ,
L_1 , V_29 ) ;
if ( V_30 )
F_17 ( V_33 L_2
L_3 ) ;
return V_30 ;
}
static void F_18 ( struct V_26 * V_27 , unsigned int V_34 )
{
struct V_35 * V_36 = V_27 -> V_37 ;
if ( ( 1 << V_34 ) & V_36 -> V_38 )
F_2 ( V_4 + V_39 ) =
V_40 ;
else
F_2 ( V_4 + V_39 ) =
~ V_40 ;
}
static void F_19 ( struct V_26 * V_27 , void * V_29 )
{
F_20 ( V_31 , V_29 ) ;
}
static int F_21 ( struct V_41 * V_42 ,
unsigned long V_43 )
{
if ( V_44 < 0 ) {
if ( V_43 == V_45 )
return 0 ;
else
return - V_46 ;
}
if ( V_43 & V_47 )
F_22 ( V_44 , 1 ) ;
else
F_22 ( V_44 , 0 ) ;
return 0 ;
}
static unsigned long F_23 ( struct V_41 * V_42 )
{
int V_48 ;
if ( V_44 < 0 ) {
V_48 = F_24 ( V_49 , L_4 ) ;
if ( ! V_48 ) {
V_44 = V_49 ;
F_25 ( V_44 , 0 ) ;
}
}
if ( V_44 >= 0 )
return V_47 | V_45 ;
else
return V_45 ;
}
static void F_26 ( struct V_41 * V_42 )
{
if ( V_44 < 0 )
return;
F_27 ( V_44 ) ;
V_44 = - V_46 ;
}
void T_1 F_28 ( void )
{
F_29 ( F_30 ( V_50 ) ) ;
F_31 ( F_30 ( V_51 ) ) ;
F_10 () ;
#ifndef F_32
F_33 ( NULL , & V_52 ) ;
#endif
F_34 ( & V_53 ) ;
F_35 ( & V_54 ) ;
F_36 ( & V_55 ) ;
F_37 ( NULL ) ;
F_38 ( NULL ) ;
#if F_39 ( V_56 ) || F_39 ( V_57 )
F_29 ( F_30 ( V_58 ) ) ;
F_40 ( & V_59 ) ;
F_41 ( 0 , F_30 ( V_60 ) ) ;
F_34 ( & V_61 [ 0 ] ) ;
F_34 ( & V_61 [ 1 ] ) ;
#endif
F_17 ( V_62 L_5 ) ;
}
