static inline void F_1 ( void )
{
unsigned int V_1 = 0 ;
F_2 ( V_2 , V_3 ) ;
V_1 = F_3 ( V_4 ) ;
V_1 |= 0x80 ;
F_2 ( V_2 , V_3 ) ;
F_2 ( V_1 , V_4 ) ;
#ifdef F_4
F_5 ( V_5
L_1 ,
V_1 ) ;
#endif
}
static inline void F_6 ( void )
{
unsigned int V_1 = 0 ;
F_2 ( 0x07 , V_3 ) ;
F_2 ( V_6 , V_4 ) ;
F_2 ( 0x30 , V_3 ) ;
V_1 = F_3 ( V_4 ) ;
V_1 |= 0x01 ;
F_2 ( 0x30 , V_3 ) ;
F_2 ( V_1 , V_4 ) ;
#ifdef F_4
F_5 ( V_5 L_2 ) ;
#endif
}
static void F_7 ( void )
{
unsigned char V_7 , V_8 = 0 ;
F_2 ( 0x60 , V_3 ) ;
V_8 = F_3 ( V_4 ) ;
F_2 ( 0x61 , V_3 ) ;
V_7 = F_3 ( V_4 ) ;
V_9 = ( V_8 << 8 ) + V_7 ;
#ifdef F_4
F_5 ( V_5
L_3 ,
V_7 , V_8 , V_9 ) ;
#endif
}
static inline void F_8 ( void )
{
F_2 ( F_3 ( V_9 + 0x0f ) | 0x03 , V_9 + 0x0f ) ;
#ifdef F_4
F_5 ( V_5 L_4 ) ;
#endif
}
static inline void F_9 ( char V_10 )
{
F_2 ( V_10 , V_9 + V_11 ) ;
#ifdef F_4
F_5 ( V_5 L_5 , V_10 ) ;
#endif
}
static inline void F_10 ( void )
{
F_2 ( F_3 ( V_9 + V_12 ) | 0x01 , V_9 + V_12 ) ;
#ifdef F_4
F_5 ( V_5 L_6 ) ;
#endif
}
static inline void F_11 ( void )
{
F_2 ( F_3 ( V_9 + V_13 ) | 0x80 , V_9 + V_13 ) ;
#ifdef F_4
F_5 ( V_5 L_7 ) ;
#endif
}
static inline void F_12 ( void )
{
F_2 ( F_3 ( V_9 + V_13 ) & 0x7f , V_9 + V_13 ) ;
#ifdef F_4
F_5 ( V_5 L_8 ) ;
#endif
}
static inline void F_13 ( void )
{
F_2 ( F_3 ( V_9 + V_12 ) | 0x80 , V_9 + V_12 ) ;
#ifdef F_4
F_5 ( V_5 L_9 ) ;
#endif
}
static inline void F_14 ( void )
{
F_2 ( F_3 ( V_9 + V_12 ) & 0x7f , V_9 + V_12 ) ;
#ifdef F_4
F_5 ( V_5 L_10 ) ;
#endif
}
static void F_15 ( void )
{
F_16 ( & V_14 ) ;
F_8 () ;
F_9 ( V_15 ) ;
F_10 () ;
F_11 () ;
F_13 () ;
F_17 ( & V_14 ) ;
}
static void F_18 ( void )
{
F_16 ( & V_14 ) ;
F_8 () ;
F_12 () ;
F_14 () ;
F_9 ( 0 ) ;
F_17 ( & V_14 ) ;
}
static void F_19 ( void )
{
F_16 ( & V_14 ) ;
F_8 () ;
F_12 () ;
F_14 () ;
F_9 ( V_15 ) ;
F_10 () ;
F_11 () ;
F_13 () ;
F_17 ( & V_14 ) ;
}
static int F_20 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( F_21 ( 0 , & V_18 ) )
return - V_19 ;
if ( V_20 )
F_22 ( V_21 ) ;
F_19 () ;
F_5 ( L_11 , V_15 ) ;
return F_23 ( V_16 , V_17 ) ;
}
static int F_24 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( V_22 == 42 ) {
F_18 () ;
F_5 ( L_12 ) ;
} else {
F_25 ( L_13 ) ;
F_19 () ;
}
F_26 ( 0 , & V_18 ) ;
V_22 = 0 ;
return 0 ;
}
static int F_27 ( void )
{
return 0 ;
}
static T_1 F_28 ( struct V_17 * V_17 , const char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
if ( V_24 ) {
if ( ! V_20 ) {
T_3 V_26 ;
V_22 = 0 ;
for ( V_26 = 0 ; V_26 != V_24 ; V_26 ++ ) {
char V_27 ;
if ( F_29 ( V_27 , V_23 + V_26 ) )
return - V_28 ;
if ( V_27 == 'V' )
V_22 = 42 ;
}
}
F_19 () ;
}
return V_24 ;
}
static long F_30 ( struct V_17 * V_17 , unsigned int V_29 ,
unsigned long V_30 )
{
int V_31 ;
union {
struct V_32 T_2 * V_33 ;
int T_2 * V_26 ;
} V_34 ;
static const struct V_32 V_33 = {
. V_35 = V_36 |
V_37 |
V_38 ,
. V_39 = 1 ,
. V_40 = L_14 ,
} ;
V_34 . V_26 = ( int T_2 * ) V_30 ;
switch ( V_29 ) {
case V_41 :
return F_31 ( V_34 . V_33 , & V_33 ,
sizeof( V_33 ) ) ? - V_28 : 0 ;
case V_42 :
return F_32 ( F_27 () , V_34 . V_26 ) ;
case V_43 :
return F_32 ( 0 , V_34 . V_26 ) ;
case V_44 :
{
int V_35 , V_45 = - V_46 ;
if ( F_29 ( V_35 , V_34 . V_26 ) )
return - V_28 ;
if ( V_35 & V_47 ) {
F_18 () ;
V_45 = 0 ;
}
if ( V_35 & V_48 ) {
F_15 () ;
V_45 = 0 ;
}
return V_45 ;
}
case V_49 :
F_19 () ;
#ifdef F_4
F_5 ( V_5 L_15 ) ;
#endif
return 0 ;
case V_50 :
if ( F_29 ( V_31 , V_34 . V_26 ) )
return - V_28 ;
V_31 /= 60 ;
if ( V_31 < 0 || V_31 > V_51 )
return - V_46 ;
V_15 = V_31 ;
F_19 () ;
case V_52 :
V_31 = V_15 * 60 ;
return F_32 ( V_31 , V_34 . V_26 ) ;
default:
return - V_53 ;
}
}
static int F_33 ( struct V_54 * V_55 ,
unsigned long V_56 ,
void * V_57 )
{
if ( V_56 == V_58 || V_56 == V_59 )
F_18 () ;
return V_60 ;
}
static int T_5 F_34 ( void )
{
int V_61 ;
F_5 ( L_16 V_62 L_17 ,
V_3 ) ;
if ( ! F_35 ( V_63 , 2 , V_64 ) )
return - V_19 ;
V_61 = F_36 ( & V_65 ) ;
if ( V_61 != 0 )
F_37 ( L_18 , V_61 ) ;
V_61 = F_38 ( & V_66 ) ;
if ( V_61 != 0 ) {
F_37 ( L_19 ,
V_67 , V_61 ) ;
goto V_68;
}
F_5 ( L_20 , V_15 ) ;
F_1 () ;
F_6 () ;
F_7 () ;
if ( ! F_39 ( V_9 , 0x20 , V_64 ) ) {
F_37 ( L_21 , V_9 ) ;
V_61 = - V_19 ;
goto V_69;
}
F_15 () ;
F_40 ( V_63 , 2 ) ;
return 0 ;
V_69:
F_41 ( & V_66 ) ;
V_68:
F_42 ( & V_65 ) ;
F_40 ( V_63 , 2 ) ;
return V_61 ;
}
static void T_6 F_43 ( void )
{
if ( ! V_20 ) {
F_18 () ;
F_5 ( L_22 ) ;
}
F_41 ( & V_66 ) ;
F_42 ( & V_65 ) ;
F_40 ( V_9 , 0x20 ) ;
F_5 ( L_23 ) ;
}
