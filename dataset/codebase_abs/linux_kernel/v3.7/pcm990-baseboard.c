static T_1 F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static void F_3 ( T_1 V_3 , unsigned int V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static void F_5 ( int V_4 , struct V_5 * V_6 )
{
if ( V_4 ) {
F_3 ( V_7 + V_8 ,
V_9 ) ;
} else {
F_3 ( 0 , V_9 ) ;
}
}
static void F_6 ( struct V_10 * V_11 )
{
int V_12 = ( V_11 -> V_13 - F_7 ( 0 ) ) ;
V_14 &= ~ ( 1 << V_12 ) ;
F_3 ( V_14 , V_15 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
int V_12 = ( V_11 -> V_13 - F_7 ( 0 ) ) ;
T_1 V_16 ;
V_14 |= ( 1 << V_12 ) ;
V_16 = F_1 ( V_17 ) ;
V_16 |= 1 << V_12 ;
F_3 ( V_16 , V_17 ) ;
F_3 ( V_14 , V_15 ) ;
}
static void F_9 ( unsigned int V_13 , struct V_18 * V_19 )
{
unsigned long V_20 ;
V_20 = ~ F_1 ( V_17 ) ;
V_20 &= V_14 ;
do {
V_19 -> V_10 . V_21 -> V_22 ( & V_19 -> V_10 ) ;
if ( F_10 ( V_20 ) ) {
V_13 = F_7 ( 0 ) + F_11 ( V_20 ) ;
F_12 ( V_13 ) ;
}
V_20 = ~ F_1 ( V_17 ) ;
V_20 &= V_14 ;
} while ( V_20 );
}
static void T_2 F_13 ( void )
{
int V_13 ;
for ( V_13 = F_7 ( 0 ) ; V_13 <= F_7 ( 3 ) ; V_13 ++ ) {
F_14 ( V_13 , & V_23 ,
V_24 ) ;
F_15 ( V_13 , V_25 | V_26 ) ;
}
F_3 ( 0x0 , V_15 ) ;
F_3 ( 0xff , V_17 ) ;
F_16 ( V_27 , F_9 ) ;
F_17 ( V_27 , V_28 ) ;
}
static int F_18 ( struct V_29 * V_30 , T_3 V_31 ,
void * V_32 )
{
int V_33 ;
V_33 = F_19 ( V_34 , V_31 , V_35 ,
L_1 , V_32 ) ;
if ( V_33 )
F_20 ( V_36 L_2
L_3 ) ;
return V_33 ;
}
static void F_21 ( struct V_29 * V_30 , unsigned int V_37 )
{
struct V_38 * V_39 = V_30 -> V_40 ;
T_1 V_16 ;
V_16 = F_1 ( V_41 ) ;
if ( ( 1 << V_37 ) & V_39 -> V_42 )
V_16 |= V_43 ;
else
V_16 &= ~ V_43 ;
F_3 ( V_43 , V_41 ) ;
}
static void F_22 ( struct V_29 * V_30 , void * V_32 )
{
F_23 ( V_34 , V_32 ) ;
}
static int F_24 ( struct V_44 * V_45 ,
unsigned long V_46 )
{
if ( V_47 < 0 ) {
if ( V_46 == V_48 )
return 0 ;
else
return - V_49 ;
}
if ( V_46 & V_50 )
F_25 ( V_47 , 1 ) ;
else
F_25 ( V_47 , 0 ) ;
return 0 ;
}
static unsigned long F_26 ( struct V_44 * V_45 )
{
int V_51 ;
if ( V_47 < 0 ) {
V_51 = F_27 ( V_52 , L_4 ) ;
if ( ! V_51 ) {
V_47 = V_52 ;
F_28 ( V_47 , 0 ) ;
}
}
if ( V_47 >= 0 )
return V_50 | V_48 ;
else
return V_48 ;
}
static void F_29 ( struct V_44 * V_45 )
{
if ( V_47 < 0 )
return;
F_30 ( V_47 ) ;
V_47 = - V_49 ;
}
void T_2 F_31 ( void )
{
F_32 ( F_33 ( V_53 ) ) ;
V_2 = F_34 ( V_54 , V_55 ) ;
if ( ! V_2 ) {
F_35 ( L_5 ) ;
return;
}
F_13 () ;
#ifndef F_36
F_37 ( NULL , & V_56 ) ;
#endif
F_38 ( & V_57 ) ;
F_39 ( & V_58 ) ;
F_40 ( & V_59 ) ;
F_41 ( NULL ) ;
F_42 ( NULL ) ;
#if F_43 ( V_60 ) || F_43 ( V_61 )
F_32 ( F_33 ( V_62 ) ) ;
F_44 ( & V_63 ) ;
F_45 ( 0 , F_33 ( V_64 ) ) ;
F_38 ( & V_65 [ 0 ] ) ;
F_38 ( & V_65 [ 1 ] ) ;
#endif
F_20 ( V_66 L_6 ) ;
}
