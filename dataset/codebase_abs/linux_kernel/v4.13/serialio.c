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
static void F_19 ( char V_58 )
{
int V_59 = V_60 ;
while ( F_20 () ) {
if ( ! -- V_59 )
break;
F_21 ( 1 ) ;
}
F_8 ( V_58 , V_36 . V_37 ) ;
}
static void F_22 ( unsigned int V_61 , unsigned int V_62 )
{
int V_63 = F_9 ( V_36 . V_37 + V_33 ) ;
F_8 ( ( V_63 & ~ V_62 ) | V_61 , V_36 . V_37 + V_33 ) ;
}
int F_23 ( struct V_64 * V_45 )
{
const struct V_1 * V_12 ;
int V_65 = 0 ;
if ( ( V_45 -> V_12 >= V_66 ) && ( V_45 -> V_12 <= V_67 ) ) {
V_12 = F_1 ( V_45 -> V_12 ) ;
if ( ! V_12 ) {
V_65 = - 1 ;
} else {
F_24 ( 0 , V_12 -> V_24 ) ;
F_11 ( 1 ) ;
F_24 ( '\r' , V_12 -> V_24 ) ;
}
} else {
V_65 = - 1 ;
F_7 ( L_6 , V_45 -> V_12 ) ;
}
if ( V_65 ) {
F_3 ( L_7 , V_45 -> V_68 ) ;
return - V_69 ;
}
F_3 ( L_8 ,
V_45 -> V_68 , V_45 -> V_12 , V_45 -> V_70 ) ;
V_45 -> V_71 = 1 ;
return 0 ;
}
void F_25 ( void )
{
if ( V_36 . V_37 == 0 )
return;
if ( ! V_45 -> V_46 )
return;
F_8 ( 0 , V_36 . V_37 + V_30 ) ;
F_26 ( V_35 -> V_38 , ( void * ) F_13 ) ;
}
int F_27 ( struct V_64 * V_72 )
{
int V_73 = V_60 ;
if ( ( V_72 -> V_71 ) && ( V_74 >= V_75 ) ) {
F_7 ( L_9 ,
V_72 -> V_68 ) ;
V_72 -> V_71 = 0 ;
F_28 () ;
V_74 = 0 ;
return 0 ;
}
while ( F_20 () ) {
if ( -- V_73 == 0 ) {
F_7 ( L_10 ,
V_72 -> V_68 ) ;
V_74 ++ ;
return 0 ;
}
F_21 ( 1 ) ;
}
V_73 = V_76 ;
while ( ! ( ( F_15 ( V_36 . V_37 + V_56 ) ) & V_77 ) ) {
if ( -- V_73 == 0 ) {
V_74 ++ ;
return 0 ;
}
F_21 ( 1 ) ;
}
V_74 = 0 ;
return 1 ;
}
static unsigned char F_29 ( void )
{
int V_73 = V_78 ;
while ( ! ( F_15 ( V_36 . V_37 + V_34 ) & V_43 ) ) {
if ( -- V_73 == 0 ) {
F_7 ( L_11 ) ;
return 0xff ;
}
F_21 ( 1 ) ;
}
return F_15 ( V_36 . V_37 + V_44 ) ;
}
static unsigned char F_30 ( void )
{
unsigned char V_79 ;
V_79 = F_15 ( V_36 . V_37 + V_34 ) ;
if ( ! ( V_79 & V_43 ) )
return 0 ;
return F_15 ( V_36 . V_37 + V_44 ) ;
}
static void F_31 ( void )
{
}
static int F_32 ( struct V_64 * V_72 , const char V_58 )
{
if ( V_72 -> V_71 && F_27 ( V_72 ) ) {
F_24 ( V_58 , V_36 . V_37 ) ;
return 1 ;
}
return 0 ;
}
const char * F_33 ( struct V_64 * V_45 ,
const char * V_80 )
{
V_47 V_58 ;
while ( ( V_58 = * V_80 ) ) {
if ( V_58 == '\n' )
V_58 = V_45 -> V_81 ;
if ( F_27 ( V_45 ) )
F_8 ( V_58 , V_36 . V_37 ) ;
else
return V_80 ;
V_80 ++ ;
}
return NULL ;
}
void F_34 ( void )
{
F_25 () ;
if ( V_36 . V_37 == 0 )
return;
F_10 ( V_36 . V_37 , 8 ) ;
V_36 . V_37 = 0 ;
}
