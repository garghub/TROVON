const struct V_1 * F_1 ( int V_2 )
{
int V_3 = 9600 , V_4 = 0 ;
unsigned int V_5 = 0 ;
int V_6 = V_7 | V_8 | V_9 | V_10 | V_11 ;
const struct V_1 * V_12 ;
int V_13 ;
if ( V_2 >= F_2 ( V_14 ) ) {
F_3 ( L_1 , V_2 ) ;
return NULL ;
}
V_12 = V_14 + V_2 ;
V_4 = V_12 -> V_15 / V_3 ;
V_5 = V_6 & ( V_16 | V_17 ) ;
#if F_4 ( V_18 ) || F_4 ( V_19 )
V_5 >>= 8 ;
#else
V_5 >>= 4 ;
#endif
if ( V_6 & V_20 )
V_5 |= V_21 ;
if ( ! ( V_6 & V_22 ) )
V_5 |= V_23 ;
if ( F_5 ( V_12 -> V_24 , 8 ) ) {
F_3 ( L_2 ) ;
F_6 ( & V_25 , V_12 -> V_24 , 8 ) ;
V_13 = F_5 ( V_12 -> V_24 , 8 ) ;
if ( V_13 ) {
F_7 ( L_3 ,
V_12 -> V_24 , V_13 ) ;
return NULL ;
}
}
F_8 ( V_5 | V_26 , V_12 -> V_24 + V_27 ) ;
F_8 ( V_4 & 0xff , V_12 -> V_24 + V_28 ) ;
F_8 ( V_4 >> 8 , V_12 -> V_24 + V_29 ) ;
F_8 ( V_5 , V_12 -> V_24 + V_27 ) ;
F_8 ( 0 , V_12 -> V_24 + V_30 ) ;
F_8 ( V_31 | V_32 , V_12 -> V_24 + V_33 ) ;
if ( F_9 ( V_12 -> V_24 + V_34 ) == 0xff ) {
F_10 ( V_12 -> V_24 , 8 ) ;
V_35 = NULL ;
return NULL ;
}
F_11 ( 1 ) ;
V_36 . V_37 = V_12 -> V_24 ;
V_35 = V_12 ;
F_12 ( V_12 -> V_38 ) ;
return V_12 ;
}
static T_1 F_13 ( int V_38 , void * V_39 )
{
unsigned long V_40 ;
int V_41 ;
F_14 ( & V_36 . V_42 , V_40 ) ;
while ( F_15 ( V_36 . V_37 + V_34 ) & V_43 ) {
V_41 = F_15 ( V_36 . V_37 + V_44 ) ;
V_45 -> V_46 ( ( V_47 ) V_41 ) ;
}
F_16 ( & V_36 . V_42 , V_40 ) ;
return V_48 ;
}
static void F_12 ( int V_38 )
{
int V_49 ;
if ( ! V_45 -> V_46 )
return;
V_49 = F_17 ( V_38 , F_13 , V_50 ,
L_4 , ( void * ) F_13 ) ;
if ( V_49 )
F_18 ( L_5 ) ;
F_8 ( V_31 | V_32 | V_51 ,
V_36 . V_37 + V_33 ) ;
F_8 ( V_52 | V_53 | V_54 ,
V_36 . V_37 + V_30 ) ;
F_9 ( V_36 . V_37 + V_34 ) ;
F_9 ( V_36 . V_37 + V_44 ) ;
F_9 ( V_36 . V_37 + V_55 ) ;
F_9 ( V_36 . V_37 + V_56 ) ;
F_8 ( 1 , V_36 . V_37 + V_57 ) ;
}
void F_19 ( void )
{
if ( V_36 . V_37 == 0 )
return;
if ( ! V_45 -> V_46 )
return;
F_8 ( 0 , V_36 . V_37 + V_30 ) ;
F_20 ( V_35 -> V_38 , ( void * ) F_13 ) ;
}
int F_21 ( void )
{
int V_58 = V_59 ;
if ( ( V_45 -> V_60 ) && ( V_61 >= V_62 ) ) {
F_7 ( L_6 ,
V_45 -> V_63 ) ;
V_45 -> V_60 = 0 ;
F_22 () ;
V_61 = 0 ;
return 0 ;
}
while ( F_23 () ) {
if ( -- V_58 == 0 ) {
F_7 ( L_7 , V_45 -> V_63 ) ;
V_61 ++ ;
return 0 ;
}
F_24 ( 1 ) ;
}
V_58 = V_64 ;
while ( ! ( ( F_15 ( V_36 . V_37 + V_56 ) ) & V_65 ) ) {
if ( -- V_58 == 0 ) {
V_61 ++ ;
return 0 ;
}
F_24 ( 1 ) ;
}
V_61 = 0 ;
return 1 ;
}
unsigned char F_25 ( void )
{
int V_58 = V_66 ;
while ( ! ( F_15 ( V_36 . V_37 + V_34 ) & V_43 ) ) {
if ( -- V_58 == 0 ) {
F_7 ( L_8 ) ;
return 0xff ;
}
F_24 ( 1 ) ;
}
return F_15 ( V_36 . V_37 + V_44 ) ;
}
unsigned char F_26 ( void )
{
unsigned char V_67 ;
V_67 = F_15 ( V_36 . V_37 + V_34 ) ;
if ( ! ( V_67 & V_43 ) )
return 0 ;
return F_15 ( V_36 . V_37 + V_44 ) ;
}
int F_27 ( const char V_68 )
{
if ( V_45 -> V_60 && F_21 () ) {
F_28 ( V_68 , V_36 . V_37 ) ;
return 1 ;
}
return 0 ;
}
void F_29 ( void )
{
if ( V_36 . V_37 == 0 )
return;
F_10 ( V_36 . V_37 , 8 ) ;
V_36 . V_37 = 0 ;
}
