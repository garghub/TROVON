static void F_1 ( char * V_1 )
{
V_2 -> V_3 = V_4 ;
while ( 1 ) ;
}
static inline void F_2 ( void )
{
F_3 () ;
}
static void F_3 ( void )
{
unsigned char V_5 , V_6 , V_7 ;
F_4 ( V_8 ) ;
V_5 = F_5 ( V_9 ) ;
V_5 &= ~ V_10 ;
V_5 |= V_11 ;
F_6 ( V_5 | V_12 , V_9 ) ;
F_7 () ;
V_7 = F_5 ( V_13 )
| V_14 | V_15 ;
F_6 ( V_7 , V_13 ) ;
V_6 = F_5 ( V_16 ) & ~ V_17 ;
F_6 ( V_6 , V_16 ) ;
F_7 () ;
F_6 ( V_6 | V_18 , V_16 ) ;
F_6 ( V_5 , V_9 ) ;
F_7 () ;
while ( 1 ) ;
}
static void F_8 ( unsigned long V_19 )
{
F_3 () ;
}
static void F_9 ( unsigned long V_19 )
{
unsigned long V_20 = V_21 -> V_22 . V_23 . V_24 ^ V_25 ;
V_21 -> V_22 . V_23 . V_24 = V_20 ;
F_10 ( & V_26 , V_27 + V_19 ) ;
}
static void F_11 ( unsigned long V_19 )
{
unsigned char V_5 , V_28 , V_6 ;
V_28 = F_5 ( V_29 ) ;
V_5 = F_5 ( V_9 ) ;
F_6 ( V_5 | V_12 , V_9 ) ;
F_7 () ;
V_6 = F_5 ( V_16 ) ;
if ( ( V_6 & V_17 ) || ( V_28 & V_30 ) ) {
V_31 . V_32 = V_27 + 50 ;
F_12 ( & V_31 ) ;
F_6 ( V_6 & ~ V_17 , V_16 ) ;
F_6 ( V_5 & ~ V_12 , V_9 ) ;
return;
}
F_6 ( V_5 & ~ V_12 , V_9 ) ;
if ( V_33 )
F_1 ( NULL ) ;
F_13 ( V_8 ) ;
}
static inline void F_14 ( void )
{
if ( V_33 )
return;
if ( V_34 || F_15 ( V_35 , 1 ) ) {
F_3 () ;
}
V_34 = 1 ;
V_26 . V_19 = V_36 ;
F_9 ( V_36 ) ;
F_16 ( & V_37 ) ;
V_37 . V_38 = F_8 ;
V_37 . V_32 = V_27 + V_39 * V_40 ;
F_12 ( & V_37 ) ;
}
static T_1 F_17 ( int V_41 , void * V_42 )
{
unsigned char V_28 ;
V_28 = F_5 ( V_29 ) ;
if ( ! ( V_28 & V_30 ) ) {
F_18 ( V_43
L_1 , V_44 ) ;
}
F_19 ( V_8 ) ;
F_16 ( & V_31 ) ;
V_31 . V_38 = F_11 ;
V_31 . V_32 = V_27 + 50 ;
F_12 ( & V_31 ) ;
F_18 ( V_45 L_2 ) ;
F_14 () ;
return V_46 ;
}
static int F_20 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_50 )
{
unsigned long V_20 ;
if ( V_33 )
return V_51 ;
V_33 = 1 ;
V_20 = V_21 -> V_22 . V_23 . V_24 | V_52 ;
V_21 -> V_22 . V_23 . V_24 = V_20 ;
V_26 . V_19 = V_53 ;
F_9 ( V_53 ) ;
return V_51 ;
}
static T_2 int F_21 ( void )
{
unsigned long V_20 = V_21 -> V_22 . V_23 . V_24 ;
V_20 |= V_25 ;
V_20 &= ~ V_52 ;
V_21 -> V_22 . V_23 . V_24 = V_20 ;
V_54 = F_1 ;
V_55 = F_2 ;
V_56 = F_3 ;
F_16 ( & V_26 ) ;
V_26 . V_38 = F_9 ;
F_22 ( & V_57 , & V_58 ) ;
if ( F_23 ( V_8 , F_17 , 0 , L_3 , NULL ) )
F_24 ( L_4 ) ;
return 0 ;
}
