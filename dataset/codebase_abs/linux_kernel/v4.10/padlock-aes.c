static inline int
F_1 ( T_1 V_1 )
{
if ( V_1 == 16 )
return 1 ;
return 0 ;
}
static inline struct V_2 * F_2 ( void * V_3 )
{
unsigned long V_4 = ( unsigned long ) V_3 ;
unsigned long V_5 = V_6 ;
if ( V_5 <= F_3 () )
V_5 = 1 ;
return (struct V_2 * ) F_4 ( V_4 , V_5 ) ;
}
static inline struct V_2 * V_2 ( struct V_7 * V_8 )
{
return F_2 ( F_5 ( V_8 ) ) ;
}
static inline struct V_2 * F_6 ( struct V_9 * V_8 )
{
return F_2 ( F_7 ( V_8 ) ) ;
}
static int F_8 ( struct V_7 * V_8 , const T_2 * V_10 ,
unsigned int V_1 )
{
struct V_2 * V_3 = V_2 ( V_8 ) ;
const T_3 * V_11 = ( const T_3 * ) V_10 ;
T_4 * V_12 = & V_8 -> V_13 ;
struct V_14 V_15 ;
int V_16 ;
if ( V_1 % 8 ) {
* V_12 |= V_17 ;
return - V_18 ;
}
V_3 -> V_19 = V_3 -> V_20 ;
V_3 -> V_20 [ 0 ] = F_9 ( V_11 [ 0 ] ) ;
V_3 -> V_20 [ 1 ] = F_9 ( V_11 [ 1 ] ) ;
V_3 -> V_20 [ 2 ] = F_9 ( V_11 [ 2 ] ) ;
V_3 -> V_20 [ 3 ] = F_9 ( V_11 [ 3 ] ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
V_3 -> V_21 . V_22 . V_23 = 1 ;
V_3 -> V_21 . V_24 . V_25 = 10 + ( V_1 - 16 ) / 4 ;
V_3 -> V_21 . V_22 . V_25 = V_3 -> V_21 . V_24 . V_25 ;
V_3 -> V_21 . V_24 . V_26 = ( V_1 - 16 ) / 8 ;
V_3 -> V_21 . V_22 . V_26 = V_3 -> V_21 . V_24 . V_26 ;
if ( F_1 ( V_1 ) )
goto V_27;
V_3 -> V_19 = V_3 -> V_28 ;
V_3 -> V_21 . V_24 . V_29 = 1 ;
V_3 -> V_21 . V_22 . V_29 = 1 ;
if ( F_10 ( & V_15 , V_10 , V_1 ) ) {
* V_12 |= V_17 ;
return - V_18 ;
}
memcpy ( V_3 -> V_20 , V_15 . V_30 , V_31 ) ;
memcpy ( V_3 -> V_19 , V_15 . V_32 , V_31 ) ;
V_27:
F_11 (cpu)
if ( & V_3 -> V_21 . V_24 == F_12 ( V_33 , V_16 ) ||
& V_3 -> V_21 . V_22 == F_12 ( V_33 , V_16 ) )
F_12 ( V_33 , V_16 ) = NULL ;
return 0 ;
}
static inline void F_13 ( struct V_21 * V_21 )
{
int V_16 = F_14 () ;
if ( V_21 != F_12 ( V_33 , V_16 ) )
#ifndef F_15
asm volatile ("pushfl; popfl");
#else
asm volatile ("pushfq; popfq");
#endif
}
static inline void F_16 ( struct V_21 * V_21 )
{
F_12 ( V_33 , F_14 () ) = V_21 ;
}
static inline void F_17 ( const T_2 * V_34 , T_2 * V_35 , void * V_11 ,
struct V_21 * V_36 , int V_37 )
{
asm volatile (".byte 0xf3,0x0f,0xa7,0xc8"
: "+S"(input), "+D"(output)
: "d"(control_word), "b"(key), "c"(count));
}
static inline T_2 * F_18 ( const T_2 * V_34 , T_2 * V_35 , void * V_11 ,
T_2 * V_38 , struct V_21 * V_36 , int V_37 )
{
asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"
: "+S" (input), "+D" (output), "+a" (iv)
: "d" (control_word), "b" (key), "c" (count));
return V_38 ;
}
static void F_19 ( const T_2 * V_39 , T_2 * V_40 , T_4 * V_11 ,
struct V_21 * V_21 , int V_37 )
{
T_2 V_41 [ V_42 * ( V_43 - 1 ) + V_6 - 1 ] ;
T_2 * V_44 = F_20 ( & V_41 [ 0 ] , V_6 ) ;
memcpy ( V_44 , V_39 , V_37 * V_42 ) ;
F_17 ( V_44 , V_40 , V_11 , V_21 , V_37 ) ;
}
static T_2 * F_21 ( const T_2 * V_39 , T_2 * V_40 , T_4 * V_11 ,
T_2 * V_38 , struct V_21 * V_21 , int V_37 )
{
T_2 V_41 [ V_42 * ( V_45 - 1 ) + V_6 - 1 ] ;
T_2 * V_44 = F_20 ( & V_41 [ 0 ] , V_6 ) ;
memcpy ( V_44 , V_39 , V_37 * V_42 ) ;
return F_18 ( V_44 , V_40 , V_11 , V_38 , V_21 , V_37 ) ;
}
static inline void F_22 ( const T_2 * V_39 , T_2 * V_40 , T_4 * V_11 ,
struct V_21 * V_21 , int V_37 )
{
if ( F_23 ( F_24 ( V_39 ) + V_46 > V_47 ) ) {
F_19 ( V_39 , V_40 , V_11 , V_21 , V_37 ) ;
return;
}
F_17 ( V_39 , V_40 , V_11 , V_21 , V_37 ) ;
}
static inline T_2 * F_25 ( const T_2 * V_39 , T_2 * V_40 , T_4 * V_11 ,
T_2 * V_38 , struct V_21 * V_21 , int V_37 )
{
if ( F_23 ( F_24 ( V_39 ) + V_48 > V_47 ) )
return F_21 ( V_39 , V_40 , V_11 , V_38 , V_21 , V_37 ) ;
return F_18 ( V_39 , V_40 , V_11 , V_38 , V_21 , V_37 ) ;
}
static inline void F_26 ( const T_2 * V_34 , T_2 * V_35 , void * V_11 ,
void * V_36 , T_4 V_37 )
{
T_4 V_49 = V_37 & ( V_50 - 1 ) ;
if ( V_37 < V_50 ) {
F_22 ( V_34 , V_35 , V_11 , V_36 , V_37 ) ;
return;
}
if ( V_49 )
asm volatile (".byte 0xf3,0x0f,0xa7,0xc8"
: "+S"(input), "+D"(output)
: "d"(control_word), "b"(key), "c"(initial));
asm volatile (".byte 0xf3,0x0f,0xa7,0xc8"
: "+S"(input), "+D"(output)
: "d"(control_word), "b"(key), "c"(count - initial));
}
static inline T_2 * F_27 ( const T_2 * V_34 , T_2 * V_35 , void * V_11 ,
T_2 * V_38 , void * V_36 , T_4 V_37 )
{
T_4 V_49 = V_37 & ( V_51 - 1 ) ;
if ( V_37 < V_51 )
return F_25 ( V_34 , V_35 , V_11 , V_38 , V_36 , V_37 ) ;
if ( V_49 )
asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"
: "+S" (input), "+D" (output), "+a" (iv)
: "d" (control_word), "b" (key), "c" (initial));
asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"
: "+S" (input), "+D" (output), "+a" (iv)
: "d" (control_word), "b" (key), "c" (count-initial));
return V_38 ;
}
static void F_28 ( struct V_7 * V_8 , T_2 * V_40 , const T_2 * V_39 )
{
struct V_2 * V_3 = V_2 ( V_8 ) ;
F_13 ( & V_3 -> V_21 . V_24 ) ;
F_22 ( V_39 , V_40 , V_3 -> V_20 , & V_3 -> V_21 . V_24 , 1 ) ;
F_16 ( & V_3 -> V_21 . V_24 ) ;
}
static void F_29 ( struct V_7 * V_8 , T_2 * V_40 , const T_2 * V_39 )
{
struct V_2 * V_3 = V_2 ( V_8 ) ;
F_13 ( & V_3 -> V_21 . V_24 ) ;
F_22 ( V_39 , V_40 , V_3 -> V_19 , & V_3 -> V_21 . V_22 , 1 ) ;
F_16 ( & V_3 -> V_21 . V_24 ) ;
}
static int F_30 ( struct V_52 * V_53 ,
struct V_54 * V_55 , struct V_54 * V_56 ,
unsigned int V_57 )
{
struct V_2 * V_3 = F_6 ( V_53 -> V_8 ) ;
struct V_58 V_59 ;
int V_60 ;
F_13 ( & V_3 -> V_21 . V_24 ) ;
F_31 ( & V_59 , V_55 , V_56 , V_57 ) ;
V_60 = F_32 ( V_53 , & V_59 ) ;
while ( ( V_57 = V_59 . V_57 ) ) {
F_26 ( V_59 . V_56 . V_61 . V_4 , V_59 . V_55 . V_61 . V_4 ,
V_3 -> V_20 , & V_3 -> V_21 . V_24 ,
V_57 / V_42 ) ;
V_57 &= V_42 - 1 ;
V_60 = F_33 ( V_53 , & V_59 , V_57 ) ;
}
F_16 ( & V_3 -> V_21 . V_24 ) ;
return V_60 ;
}
static int F_34 ( struct V_52 * V_53 ,
struct V_54 * V_55 , struct V_54 * V_56 ,
unsigned int V_57 )
{
struct V_2 * V_3 = F_6 ( V_53 -> V_8 ) ;
struct V_58 V_59 ;
int V_60 ;
F_13 ( & V_3 -> V_21 . V_22 ) ;
F_31 ( & V_59 , V_55 , V_56 , V_57 ) ;
V_60 = F_32 ( V_53 , & V_59 ) ;
while ( ( V_57 = V_59 . V_57 ) ) {
F_26 ( V_59 . V_56 . V_61 . V_4 , V_59 . V_55 . V_61 . V_4 ,
V_3 -> V_19 , & V_3 -> V_21 . V_22 ,
V_57 / V_42 ) ;
V_57 &= V_42 - 1 ;
V_60 = F_33 ( V_53 , & V_59 , V_57 ) ;
}
F_16 ( & V_3 -> V_21 . V_24 ) ;
return V_60 ;
}
static int F_35 ( struct V_52 * V_53 ,
struct V_54 * V_55 , struct V_54 * V_56 ,
unsigned int V_57 )
{
struct V_2 * V_3 = F_6 ( V_53 -> V_8 ) ;
struct V_58 V_59 ;
int V_60 ;
F_13 ( & V_3 -> V_21 . V_24 ) ;
F_31 ( & V_59 , V_55 , V_56 , V_57 ) ;
V_60 = F_32 ( V_53 , & V_59 ) ;
while ( ( V_57 = V_59 . V_57 ) ) {
T_2 * V_38 = F_27 ( V_59 . V_56 . V_61 . V_4 ,
V_59 . V_55 . V_61 . V_4 , V_3 -> V_20 ,
V_59 . V_38 , & V_3 -> V_21 . V_24 ,
V_57 / V_42 ) ;
memcpy ( V_59 . V_38 , V_38 , V_42 ) ;
V_57 &= V_42 - 1 ;
V_60 = F_33 ( V_53 , & V_59 , V_57 ) ;
}
F_16 ( & V_3 -> V_21 . V_22 ) ;
return V_60 ;
}
static int F_36 ( struct V_52 * V_53 ,
struct V_54 * V_55 , struct V_54 * V_56 ,
unsigned int V_57 )
{
struct V_2 * V_3 = F_6 ( V_53 -> V_8 ) ;
struct V_58 V_59 ;
int V_60 ;
F_13 ( & V_3 -> V_21 . V_24 ) ;
F_31 ( & V_59 , V_55 , V_56 , V_57 ) ;
V_60 = F_32 ( V_53 , & V_59 ) ;
while ( ( V_57 = V_59 . V_57 ) ) {
F_27 ( V_59 . V_56 . V_61 . V_4 , V_59 . V_55 . V_61 . V_4 ,
V_3 -> V_19 , V_59 . V_38 , & V_3 -> V_21 . V_22 ,
V_57 / V_42 ) ;
V_57 &= V_42 - 1 ;
V_60 = F_33 ( V_53 , & V_59 , V_57 ) ;
}
F_16 ( & V_3 -> V_21 . V_24 ) ;
return V_60 ;
}
static int T_5 F_37 ( void )
{
int V_62 ;
struct V_63 * V_64 = & F_38 ( 0 ) ;
if ( ! F_39 ( V_65 ) )
return - V_66 ;
if ( ! F_40 ( V_67 ) ) {
F_41 (KERN_NOTICE PFX L_1 ) ;
return - V_66 ;
}
if ( ( V_62 = F_42 ( & V_68 ) ) )
goto V_69;
if ( ( V_62 = F_42 ( & V_70 ) ) )
goto V_71;
if ( ( V_62 = F_42 ( & V_72 ) ) )
goto V_73;
F_41 (KERN_NOTICE PFX L_2 ) ;
if ( V_64 -> V_74 == 6 && V_64 -> V_75 == 15 && V_64 -> V_76 == 2 ) {
V_50 = V_43 ;
V_51 = V_45 ;
F_41 (KERN_NOTICE PFX L_3 ) ;
}
V_40:
return V_62 ;
V_73:
F_43 ( & V_70 ) ;
V_71:
F_43 ( & V_68 ) ;
V_69:
F_41 (KERN_ERR PFX L_4 ) ;
goto V_40;
}
static void T_6 F_44 ( void )
{
F_43 ( & V_72 ) ;
F_43 ( & V_70 ) ;
F_43 ( & V_68 ) ;
}
