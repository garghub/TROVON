static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 -> V_7 ) ;
V_4 -> V_8 . V_7 = V_6 -> V_8 ;
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
return F_4 ( & V_4 -> V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_11 , unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
return F_6 ( & V_4 -> V_8 , V_11 , V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_8 ( & V_4 -> V_8 , V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 , const void * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 -> V_7 ) ;
V_4 -> V_8 . V_7 = V_6 -> V_8 ;
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
return F_10 ( & V_4 -> V_8 , V_14 ) ;
}
static inline void F_11 ( T_2 * V_15 ,
T_2 * V_16 , T_3 V_17 )
{
while ( V_17 -- )
* V_16 ++ = F_12 ( * V_15 ++ ) ;
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_14 ,
unsigned int V_17 , T_1 * V_13 )
{
char V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
char * V_22 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_23 V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
int V_27 ;
int V_28 ;
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
V_28 = F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_28 )
goto V_13;
if ( V_24 . V_17 + V_17 > V_29 )
return F_16 ( & V_4 -> V_8 , V_14 , V_17 , V_13 ) ;
V_26 = ( ( V_24 . V_17 - 1 ) & ( V_30 - 1 ) ) + 1 ;
V_25 = V_30 - V_26 ;
if ( V_25 ) {
if ( V_17 > V_25 ) {
V_28 = F_6 ( & V_4 -> V_8 , V_14 , V_25 ) ? :
F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_28 )
goto V_13;
V_17 -= V_25 ;
V_14 += V_25 ;
} else {
memcpy ( V_24 . V_31 + V_26 , V_14 , V_17 ) ;
V_14 = V_24 . V_31 ;
V_17 += V_26 ;
V_24 . V_17 &= ~ ( V_30 - 1 ) ;
}
}
memcpy ( V_22 , & V_24 . V_24 , V_32 ) ;
V_27 = F_17 () ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xc8"
: \
: "c"((unsigned long)state.count + count), \
"a"((unsigned long)state.count), \
"S"(in), "D"(result));
F_18 ( V_27 ) ;
F_11 ( ( T_2 * ) V_22 , ( T_2 * ) V_13 , 5 ) ;
V_13:
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_18 [ 4 ] ;
return F_13 ( V_2 , V_18 , 0 , V_13 ) ;
}
static int F_20 ( struct V_1 * V_2 , const T_1 * V_14 ,
unsigned int V_17 , T_1 * V_13 )
{
char V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
char * V_22 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_33 V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
int V_27 ;
int V_28 ;
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
V_28 = F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_28 )
goto V_13;
if ( V_24 . V_17 + V_17 > V_29 )
return F_16 ( & V_4 -> V_8 , V_14 , V_17 , V_13 ) ;
V_26 = ( ( V_24 . V_17 - 1 ) & ( V_34 - 1 ) ) + 1 ;
V_25 = V_34 - V_26 ;
if ( V_25 ) {
if ( V_17 > V_25 ) {
V_28 = F_6 ( & V_4 -> V_8 , V_14 , V_25 ) ? :
F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_28 )
goto V_13;
V_17 -= V_25 ;
V_14 += V_25 ;
} else {
memcpy ( V_24 . V_18 + V_26 , V_14 , V_17 ) ;
V_14 = V_24 . V_18 ;
V_17 += V_26 ;
V_24 . V_17 &= ~ ( V_30 - 1 ) ;
}
}
memcpy ( V_22 , & V_24 . V_24 , V_35 ) ;
V_27 = F_17 () ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xd0"
: \
: "c"((unsigned long)state.count + count), \
"a"((unsigned long)state.count), \
"S"(in), "D"(result));
F_18 ( V_27 ) ;
F_11 ( ( T_2 * ) V_22 , ( T_2 * ) V_13 , 8 ) ;
V_13:
return V_28 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_18 [ 4 ] ;
return F_20 ( V_2 , V_18 , 0 , V_13 ) ;
}
static int F_22 ( struct V_36 * V_7 )
{
struct V_37 * V_38 = F_23 ( V_7 ) ;
const char * V_39 = V_7 -> V_40 -> V_41 ;
struct V_5 * V_6 = F_24 ( V_7 ) ;
struct V_37 * V_42 ;
int V_28 = - V_43 ;
V_42 = F_25 ( V_39 , 0 ,
V_44 ) ;
if ( F_26 ( V_42 ) ) {
F_27 (KERN_WARNING PFX L_1 ,
fallback_driver_name) ;
V_28 = F_28 ( V_42 ) ;
goto V_13;
}
V_6 -> V_8 = V_42 ;
V_38 -> V_45 += F_29 ( V_42 ) ;
return 0 ;
V_13:
return V_28 ;
}
static void F_30 ( struct V_36 * V_7 )
{
struct V_5 * V_6 = F_24 ( V_7 ) ;
F_31 ( V_6 -> V_8 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_23 * V_46 = F_2 ( V_2 ) ;
* V_46 = (struct V_23 ) {
. V_24 = { V_47 , V_48 , V_49 , V_50 , V_51 } ,
} ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const T_1 * V_11 , unsigned int V_52 )
{
struct V_23 * V_46 = F_2 ( V_2 ) ;
unsigned int V_53 , V_54 ;
const T_1 * V_15 ;
T_1 V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
T_1 * V_16 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
int V_27 ;
V_53 = V_46 -> V_17 & 0x3f ;
V_46 -> V_17 += V_52 ;
V_54 = 0 ;
V_15 = V_11 ;
memcpy ( V_16 , ( T_1 * ) ( V_46 -> V_24 ) , V_32 ) ;
if ( ( V_53 + V_52 ) >= V_30 ) {
if ( V_53 ) {
V_54 = - V_53 ;
memcpy ( V_46 -> V_31 + V_53 , V_11 ,
V_54 + V_30 ) ;
V_15 = V_46 -> V_31 ;
V_27 = F_17 () ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xc8"
: "+S"(src), "+D"(dst) \
: "a"((long)-1), "c"((unsigned long)1));
F_18 ( V_27 ) ;
V_54 += V_30 ;
V_15 = V_11 + V_54 ;
}
if ( V_52 - V_54 >= V_30 ) {
V_27 = F_17 () ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xc8"
: "+S"(src), "+D"(dst)
: "a"((long)-1),
"c"((unsigned long)((len - done) / SHA1_BLOCK_SIZE)));
F_18 ( V_27 ) ;
V_54 += ( ( V_52 - V_54 ) - ( V_52 - V_54 ) % V_30 ) ;
V_15 = V_11 + V_54 ;
}
V_53 = 0 ;
}
memcpy ( ( T_1 * ) ( V_46 -> V_24 ) , V_16 , V_32 ) ;
memcpy ( V_46 -> V_31 + V_53 , V_15 , V_52 - V_54 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_23 * V_24 = (struct V_23 * ) F_2 ( V_2 ) ;
unsigned int V_53 , V_55 ;
T_4 V_56 ;
static const T_1 V_57 [ 64 ] = { 0x80 , } ;
V_56 = F_35 ( V_24 -> V_17 << 3 ) ;
V_53 = V_24 -> V_17 & 0x3f ;
V_55 = ( V_53 < 56 ) ? ( 56 - V_53 ) : ( ( 64 + 56 ) - V_53 ) ;
F_33 ( V_2 , V_57 , V_55 ) ;
F_33 ( V_2 , ( const T_1 * ) & V_56 , sizeof( V_56 ) ) ;
F_11 ( ( T_2 * ) ( V_24 -> V_24 ) , ( T_2 * ) V_13 , 5 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_33 * V_46 = F_2 ( V_2 ) ;
* V_46 = (struct V_33 ) {
. V_24 = { V_58 , V_59 , V_60 , V_61 , \
V_62 , V_63 , V_64 , V_65 } ,
} ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_52 )
{
struct V_33 * V_46 = F_2 ( V_2 ) ;
unsigned int V_53 , V_54 ;
const T_1 * V_15 ;
T_1 V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
T_1 * V_16 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
int V_27 ;
V_53 = V_46 -> V_17 & 0x3f ;
V_46 -> V_17 += V_52 ;
V_54 = 0 ;
V_15 = V_11 ;
memcpy ( V_16 , ( T_1 * ) ( V_46 -> V_24 ) , V_35 ) ;
if ( ( V_53 + V_52 ) >= V_34 ) {
if ( V_53 ) {
V_54 = - V_53 ;
memcpy ( V_46 -> V_18 + V_53 , V_11 ,
V_54 + V_34 ) ;
V_15 = V_46 -> V_18 ;
V_27 = F_17 () ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xd0"
: "+S"(src), "+D"(dst)
: "a"((long)-1), "c"((unsigned long)1));
F_18 ( V_27 ) ;
V_54 += V_34 ;
V_15 = V_11 + V_54 ;
}
if ( V_52 - V_54 >= V_34 ) {
V_27 = F_17 () ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xd0"
: "+S"(src), "+D"(dst)
: "a"((long)-1),
"c"((unsigned long)((len - done) / 64)));
F_18 ( V_27 ) ;
V_54 += ( ( V_52 - V_54 ) - ( V_52 - V_54 ) % 64 ) ;
V_15 = V_11 + V_54 ;
}
V_53 = 0 ;
}
memcpy ( ( T_1 * ) ( V_46 -> V_24 ) , V_16 , V_35 ) ;
memcpy ( V_46 -> V_18 + V_53 , V_15 , V_52 - V_54 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_33 * V_24 =
(struct V_33 * ) F_2 ( V_2 ) ;
unsigned int V_53 , V_55 ;
T_4 V_56 ;
static const T_1 V_57 [ 64 ] = { 0x80 , } ;
V_56 = F_35 ( V_24 -> V_17 << 3 ) ;
V_53 = V_24 -> V_17 & 0x3f ;
V_55 = ( V_53 < 56 ) ? ( 56 - V_53 ) : ( ( 64 + 56 ) - V_53 ) ;
F_37 ( V_2 , V_57 , V_55 ) ;
F_37 ( V_2 , ( const T_1 * ) & V_56 , sizeof( V_56 ) ) ;
F_11 ( ( T_2 * ) ( V_24 -> V_24 ) , ( T_2 * ) V_13 , 8 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
void * V_13 )
{
int V_66 = F_40 ( V_2 -> V_7 ) ;
void * V_46 = F_2 ( V_2 ) ;
memcpy ( V_13 , V_46 , V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
const void * V_14 )
{
int V_66 = F_40 ( V_2 -> V_7 ) ;
void * V_46 = F_2 ( V_2 ) ;
memcpy ( V_46 , V_14 , V_66 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
int V_67 = - V_68 ;
struct V_69 * V_70 = & F_43 ( 0 ) ;
struct V_71 * V_72 ;
struct V_71 * V_73 ;
if ( ! F_44 ( V_74 ) || ! V_75 )
return - V_68 ;
if ( V_70 -> V_76 < 0x0f ) {
V_72 = & V_77 ;
V_73 = & V_78 ;
} else {
V_72 = & V_79 ;
V_73 = & V_80 ;
}
V_67 = F_45 ( V_72 ) ;
if ( V_67 )
goto V_13;
V_67 = F_45 ( V_73 ) ;
if ( V_67 )
goto V_81;
F_27 (KERN_NOTICE PFX L_2 ) ;
return 0 ;
V_81:
F_46 ( V_72 ) ;
V_13:
F_27 (KERN_ERR PFX L_3 ) ;
return V_67 ;
}
static void T_6 F_47 ( void )
{
struct V_69 * V_70 = & F_43 ( 0 ) ;
if ( V_70 -> V_76 >= 0x0f ) {
F_46 ( & V_79 ) ;
F_46 ( & V_80 ) ;
} else {
F_46 ( & V_77 ) ;
F_46 ( & V_78 ) ;
}
}
