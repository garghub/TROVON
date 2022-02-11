static inline void F_1 ( int V_1 )
{
F_2 ( V_2 , V_1 ? V_2 : 0 ) ;
}
static inline void F_3 ( int V_3 )
{
F_2 ( V_4 , V_3 ? V_4 : 0 ) ;
}
static inline int F_4 ( void )
{
return F_5 () & V_4 ;
}
static inline void F_6 ( int V_5 )
{
F_7 ( V_4 , V_5 ? V_4 : 0 ) ;
}
static inline void F_8 ( void )
{
F_9 ( V_6 , 0 ) ;
F_9 ( V_6 , V_6 ) ;
}
static inline void F_10 ( unsigned long * V_7 )
{
F_11 ( & V_8 , * V_7 ) ;
}
static inline void F_12 ( unsigned long * V_7 )
{
F_13 ( & V_8 , * V_7 ) ;
}
static inline void F_14 ( int V_9 )
{
unsigned long V_7 ;
F_11 ( & V_8 , V_7 ) ;
F_2 ( V_10 , V_9 ? V_10 : 0 ) ;
F_13 ( & V_8 , V_7 ) ;
}
static inline int F_15 ( void )
{
if ( ( V_11 & 0xf000 ) == 0x4000 )
return V_12 ;
return ( F_5 () & V_10 ) ? V_13 : V_14 ;
}
static void F_16 ( int V_15 , int V_16 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
F_3 ( V_16 & 1 ) ;
F_1 ( 0 ) ;
F_17 ( 1 ) ;
F_1 ( 1 ) ;
F_17 ( 1 ) ;
V_16 >>= 1 ;
}
}
static unsigned int F_18 ( int V_15 )
{
unsigned int V_16 = 0 , V_17 = 1 ;
int V_9 ;
F_3 ( 0 ) ;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
F_1 ( 0 ) ;
F_17 ( 1 ) ;
if ( F_4 () )
V_16 |= V_17 ;
V_17 <<= 1 ;
F_1 ( 1 ) ;
F_17 ( 1 ) ;
}
return V_16 ;
}
static void F_19 ( int V_18 , int V_19 , int V_16 )
{
unsigned long V_7 ;
F_10 ( & V_7 ) ;
F_1 ( 1 ) ;
F_6 ( 0 ) ;
F_8 () ;
F_17 ( 1 ) ;
F_16 ( 8 , V_18 ) ;
if ( V_19 )
F_16 ( V_19 , V_16 ) ;
F_17 ( 1 ) ;
F_8 () ;
F_12 ( & V_7 ) ;
F_20 ( 20 ) ;
}
static unsigned int F_21 ( int V_18 , int V_19 )
{
unsigned long V_7 ;
unsigned int V_16 ;
F_10 ( & V_7 ) ;
F_1 ( 1 ) ;
F_6 ( 0 ) ;
F_8 () ;
F_17 ( 1 ) ;
F_16 ( 8 , V_18 ) ;
F_6 ( 1 ) ;
V_16 = F_18 ( V_19 ) ;
F_8 () ;
F_12 ( & V_7 ) ;
return V_16 ;
}
static int F_22 ( unsigned int V_20 )
{
if ( V_20 & 0x100 )
V_20 |= 0xfffffe00 ;
return V_20 ;
}
static void F_23 ( struct V_21 * V_21 )
{
F_19 ( V_22 , 8 , V_23 ) ;
F_19 ( V_24 , 9 , V_21 -> V_25 ) ;
F_19 ( V_26 , 9 , V_21 -> V_27 ) ;
F_19 ( V_28 , 0 , 0 ) ;
}
static void F_24 ( struct V_21 * V_21 )
{
V_21 -> V_25 = F_22 ( F_21 ( V_29 , 9 ) ) ;
V_21 -> V_27 = F_22 ( F_21 ( V_30 , 9 ) ) ;
}
static int F_25 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
return F_26 ( V_31 , V_32 ) ;
}
static T_1
F_27 ( struct V_32 * V_32 , char T_2 * V_33 , T_3 V_34 , T_4 * V_35 )
{
signed int V_36 ;
signed char V_37 ;
V_36 = F_22 ( F_21 ( V_38 , 9 ) ) >> 1 ;
V_37 = ( V_36 * 9 ) / 5 + 32 ;
if ( F_28 ( V_33 , & V_37 , 1 ) )
return - V_39 ;
return 1 ;
}
static int
F_29 ( struct V_32 * V_32 , unsigned int V_18 , unsigned long V_40 )
{
struct V_21 V_21 ;
union {
struct V_21 T_2 * V_21 ;
int T_2 * V_9 ;
} V_41 ;
int V_9 ;
V_41 . V_9 = ( int T_2 * ) V_40 ;
switch( V_18 ) {
case V_42 :
case V_43 :
if ( ! F_30 ( V_44 ) )
return - V_45 ;
if ( V_18 == V_42 ) {
if ( F_31 ( V_21 . V_27 , V_41 . V_9 ) )
return - V_39 ;
V_21 . V_25 = V_21 . V_27 - 3 ;
} else {
if ( F_32 ( & V_21 , V_41 . V_21 , sizeof( V_21 ) ) )
return - V_39 ;
}
V_21 . V_25 <<= 1 ;
V_21 . V_27 <<= 1 ;
F_23 ( & V_21 ) ;
break;
case V_46 :
case V_47 :
F_24 ( & V_21 ) ;
V_21 . V_25 >>= 1 ;
V_21 . V_27 >>= 1 ;
if ( V_18 == V_46 ) {
if ( F_33 ( V_21 . V_27 , V_41 . V_9 ) )
return - V_39 ;
} else {
if ( F_28 ( V_41 . V_21 , & V_21 , sizeof( V_21 ) ) )
return - V_39 ;
}
break;
case V_48 :
case V_49 :
V_9 = F_22 ( F_21 ( V_38 , 9 ) ) ;
if ( V_18 == V_48 )
V_9 >>= 1 ;
return F_33 ( V_9 , V_41 . V_9 ) ? - V_39 : 0 ;
case V_50 :
V_9 = F_21 ( V_51 , 8 ) & 0xe3 ;
return F_33 ( V_9 , V_41 . V_9 ) ? - V_39 : 0 ;
case V_52 :
V_9 = F_15 () ;
return F_33 ( V_9 , V_41 . V_9 ) ? - V_39 : 0 ;
case V_53 :
if ( ! F_30 ( V_44 ) )
return - V_45 ;
if ( F_31 ( V_9 , V_41 . V_9 ) )
return - V_39 ;
F_14 ( V_9 ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static long
F_34 ( struct V_32 * V_32 , unsigned int V_18 , unsigned long V_40 )
{
int V_55 ;
F_35 ( & V_56 ) ;
V_55 = F_29 ( V_32 , V_18 , V_40 ) ;
F_36 ( & V_56 ) ;
return V_55 ;
}
static int F_37 ( struct V_57 * V_58 , void * V_59 )
{
struct V_21 V_60 ;
int V_61 ;
F_24 ( & V_60 ) ;
V_61 = F_22 ( F_21 ( V_38 , 9 ) ) ;
F_38 ( V_58 , L_1 ,
V_60 . V_27 >> 1 , V_60 . V_27 & 1 ? 5 : 0 ,
V_60 . V_25 >> 1 , V_60 . V_25 & 1 ? 5 : 0 ,
V_61 >> 1 , V_61 & 1 ? 5 : 0 ,
V_62 [ F_15 () ] ) ;
return 0 ;
}
static int F_39 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
return F_40 ( V_32 , F_37 , NULL ) ;
}
static int T_5 F_41 ( void )
{
int V_55 ;
struct V_21 V_60 , V_63 ;
if ( ! F_42 () )
return - V_64 ;
F_19 ( V_65 , 0 , 0 ) ;
F_19 ( V_22 , 8 , V_23 ) ;
F_19 ( V_28 , 0 , 0 ) ;
F_24 ( & V_60 ) ;
V_63 . V_25 = 0 ;
V_63 . V_27 = 1 ;
F_23 ( & V_63 ) ;
F_20 ( 2000 ) ;
F_23 ( & V_60 ) ;
V_55 = F_43 ( & V_66 ) ;
if ( V_55 < 0 )
return V_55 ;
#ifdef F_44
if ( ! F_45 ( L_2 , 0 , NULL , & V_67 ) )
F_46 ( V_68 L_3 ) ;
#endif
F_24 ( & V_60 ) ;
V_55 = F_22 ( F_21 ( V_38 , 9 ) ) ;
F_46 ( V_69 L_4
L_5 ,
V_60 . V_27 >> 1 , V_60 . V_27 & 1 ? 5 : 0 ,
V_60 . V_25 >> 1 , V_60 . V_25 & 1 ? 5 : 0 ,
V_55 >> 1 , V_55 & 1 ? 5 : 0 ,
V_62 [ F_15 () ] ) ;
return 0 ;
}
static void T_6 F_47 ( void )
{
#ifdef F_44
F_48 ( L_2 , NULL ) ;
#endif
F_49 ( & V_66 ) ;
}
