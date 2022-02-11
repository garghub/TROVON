const struct V_1 * F_1 ( int V_2 )
{
int V_3 = 9600 , V_4 = 0 ;
unsigned int V_5 = 0 ;
int V_6 = V_7 | V_8 | V_9 | V_10 | V_11 ;
const struct V_1 * V_12 = V_13 + V_2 ;
int V_14 ;
V_4 = V_12 -> V_15 / V_3 ;
V_5 = V_6 & ( V_16 | V_17 ) ;
#if F_2 ( V_18 ) || F_2 ( V_19 )
V_5 >>= 8 ;
#else
V_5 >>= 4 ;
#endif
if ( V_6 & V_20 )
V_5 |= V_21 ;
if ( ! ( V_6 & V_22 ) )
V_5 |= V_23 ;
if ( F_3 ( V_12 -> V_24 , 8 ) ) {
F_4 ( V_25 L_1 ) ;
F_5 ( & V_26 , V_12 -> V_24 , 8 ) ;
V_14 = F_3 ( V_12 -> V_24 , 8 ) ;
if ( V_14 ) {
F_6 ( L_2 ,
V_12 -> V_24 , V_14 ) ;
return NULL ;
}
}
F_7 ( V_5 | V_27 , V_12 -> V_24 + V_28 ) ;
F_7 ( V_4 & 0xff , V_12 -> V_24 + V_29 ) ;
F_7 ( V_4 >> 8 , V_12 -> V_24 + V_30 ) ;
F_7 ( V_5 , V_12 -> V_24 + V_28 ) ;
F_7 ( 0 , V_12 -> V_24 + V_31 ) ;
F_7 ( V_32 | V_33 , V_12 -> V_24 + V_34 ) ;
if ( F_8 ( V_12 -> V_24 + V_35 ) == 0xff ) {
F_9 ( V_12 -> V_24 , 8 ) ;
V_36 = NULL ;
return NULL ;
}
F_10 ( 1 ) ;
V_37 . V_38 = V_12 -> V_24 ;
V_36 = V_12 ;
F_11 ( V_12 -> V_39 ) ;
return V_12 ;
}
static T_1 F_12 ( int V_39 , void * V_40 )
{
unsigned long V_41 ;
int V_42 ;
F_13 ( & V_37 . V_43 , V_41 ) ;
while ( F_14 ( V_37 . V_38 + V_35 ) & V_44 ) {
V_42 = F_14 ( V_37 . V_38 + V_45 ) ;
V_46 -> V_47 ( ( V_48 ) V_42 ) ;
}
F_15 ( & V_37 . V_43 , V_41 ) ;
return V_49 ;
}
static void F_11 ( int V_39 )
{
int V_50 ;
if ( V_46 -> V_47 == NULL )
return;
V_50 = F_16 ( V_39 , F_12 , V_51 ,
L_3 , ( void * ) F_12 ) ;
if ( V_50 )
F_4 ( V_52 L_4 ) ;
F_7 ( V_32 | V_33 | V_53 ,
V_37 . V_38 + V_34 ) ;
F_7 ( V_54 | V_55 | V_56 ,
V_37 . V_38 + V_31 ) ;
F_8 ( V_37 . V_38 + V_35 ) ;
F_8 ( V_37 . V_38 + V_45 ) ;
F_8 ( V_37 . V_38 + V_57 ) ;
F_8 ( V_37 . V_38 + V_58 ) ;
F_7 ( 1 , V_37 . V_38 + V_59 ) ;
}
void F_17 ( void )
{
if ( V_37 . V_38 == 0 )
return;
if ( V_46 -> V_47 == NULL )
return;
F_7 ( 0 , V_37 . V_38 + V_31 ) ;
F_18 ( V_36 -> V_39 , ( void * ) F_12 ) ;
}
int F_19 ( void )
{
int V_60 = V_61 ;
if ( ( V_46 -> V_62 ) && ( V_63 >= V_64 ) ) {
F_6 ( L_5 ,
V_46 -> V_65 ) ;
V_46 -> V_62 = 0 ;
F_20 () ;
V_63 = 0 ;
return 0 ;
}
while ( F_21 () ) {
if ( -- V_60 == 0 ) {
F_6 ( L_6 , V_46 -> V_65 ) ;
V_63 ++ ;
return 0 ;
}
F_22 ( 1 ) ;
}
V_60 = V_66 ;
while ( ! ( ( F_14 ( V_37 . V_38 + V_58 ) ) & V_67 ) ) {
if ( -- V_60 == 0 ) {
V_63 ++ ;
return 0 ;
}
F_22 ( 1 ) ;
}
V_63 = 0 ;
return 1 ;
}
unsigned char F_23 ( void )
{
int V_60 = V_68 ;
while ( ! ( F_14 ( V_37 . V_38 + V_35 ) & V_44 ) ) {
if ( -- V_60 == 0 ) {
F_6 ( L_7 ) ;
return 0xff ;
}
F_22 ( 1 ) ;
}
return F_14 ( V_37 . V_38 + V_45 ) ;
}
unsigned char F_24 ( void )
{
unsigned char V_69 ;
V_69 = F_14 ( V_37 . V_38 + V_35 ) ;
if ( ! ( V_69 & V_44 ) )
return 0 ;
return F_14 ( V_37 . V_38 + V_45 ) ;
}
int F_25 ( const char V_70 )
{
if ( V_46 -> V_62 && F_19 () ) {
F_26 ( V_70 , V_37 . V_38 ) ;
return 1 ;
}
return 0 ;
}
void F_27 ( void )
{
if ( V_37 . V_38 == 0 )
return;
F_9 ( V_37 . V_38 , 8 ) ;
V_37 . V_38 = 0 ;
}
