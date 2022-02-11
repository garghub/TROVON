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
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
V_27 = F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_27 )
goto V_13;
if ( V_24 . V_17 + V_17 > V_28 )
return F_16 ( & V_4 -> V_8 , V_14 , V_17 , V_13 ) ;
V_26 = ( ( V_24 . V_17 - 1 ) & ( V_29 - 1 ) ) + 1 ;
V_25 = V_29 - V_26 ;
if ( V_25 ) {
if ( V_17 > V_25 ) {
V_27 = F_6 ( & V_4 -> V_8 , V_14 , V_25 ) ? :
F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_27 )
goto V_13;
V_17 -= V_25 ;
V_14 += V_25 ;
} else {
memcpy ( V_24 . V_30 + V_26 , V_14 , V_17 ) ;
V_14 = V_24 . V_30 ;
V_17 += V_26 ;
V_24 . V_17 &= ~ ( V_29 - 1 ) ;
}
}
memcpy ( V_22 , & V_24 . V_24 , V_31 ) ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xc8"
: \
: "c"((unsigned long)state.count + count), \
"a"((unsigned long)state.count), \
"S"(in), "D"(result));
F_11 ( ( T_2 * ) V_22 , ( T_2 * ) V_13 , 5 ) ;
V_13:
return V_27 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_18 [ 4 ] ;
return F_13 ( V_2 , V_18 , 0 , V_13 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_14 ,
unsigned int V_17 , T_1 * V_13 )
{
char V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
char * V_22 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
int V_27 ;
V_4 -> V_8 . V_9 = V_2 -> V_9 & V_10 ;
V_27 = F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_27 )
goto V_13;
if ( V_24 . V_17 + V_17 > V_28 )
return F_16 ( & V_4 -> V_8 , V_14 , V_17 , V_13 ) ;
V_26 = ( ( V_24 . V_17 - 1 ) & ( V_33 - 1 ) ) + 1 ;
V_25 = V_33 - V_26 ;
if ( V_25 ) {
if ( V_17 > V_25 ) {
V_27 = F_6 ( & V_4 -> V_8 , V_14 , V_25 ) ? :
F_8 ( & V_4 -> V_8 , & V_24 ) ;
if ( V_27 )
goto V_13;
V_17 -= V_25 ;
V_14 += V_25 ;
} else {
memcpy ( V_24 . V_18 + V_26 , V_14 , V_17 ) ;
V_14 = V_24 . V_18 ;
V_17 += V_26 ;
V_24 . V_17 &= ~ ( V_29 - 1 ) ;
}
}
memcpy ( V_22 , & V_24 . V_24 , V_34 ) ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xd0"
: \
: "c"((unsigned long)state.count + count), \
"a"((unsigned long)state.count), \
"S"(in), "D"(result));
F_11 ( ( T_2 * ) V_22 , ( T_2 * ) V_13 , 8 ) ;
V_13:
return V_27 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_18 [ 4 ] ;
return F_18 ( V_2 , V_18 , 0 , V_13 ) ;
}
static int F_20 ( struct V_35 * V_7 )
{
struct V_36 * V_37 = F_21 ( V_7 ) ;
const char * V_38 = F_22 ( V_7 ) ;
struct V_5 * V_6 = F_23 ( V_7 ) ;
struct V_36 * V_39 ;
int V_27 = - V_40 ;
V_39 = F_24 ( V_38 , 0 ,
V_41 ) ;
if ( F_25 ( V_39 ) ) {
F_26 (KERN_WARNING PFX L_1 ,
fallback_driver_name) ;
V_27 = F_27 ( V_39 ) ;
goto V_13;
}
V_6 -> V_8 = V_39 ;
V_37 -> V_42 += F_28 ( V_39 ) ;
return 0 ;
V_13:
return V_27 ;
}
static void F_29 ( struct V_35 * V_7 )
{
struct V_5 * V_6 = F_23 ( V_7 ) ;
F_30 ( V_6 -> V_8 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_23 * V_43 = F_2 ( V_2 ) ;
* V_43 = (struct V_23 ) {
. V_24 = { V_44 , V_45 , V_46 , V_47 , V_48 } ,
} ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const T_1 * V_11 , unsigned int V_49 )
{
struct V_23 * V_43 = F_2 ( V_2 ) ;
unsigned int V_50 , V_51 ;
const T_1 * V_15 ;
T_1 V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
T_1 * V_16 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
V_50 = V_43 -> V_17 & 0x3f ;
V_43 -> V_17 += V_49 ;
V_51 = 0 ;
V_15 = V_11 ;
memcpy ( V_16 , ( T_1 * ) ( V_43 -> V_24 ) , V_31 ) ;
if ( ( V_50 + V_49 ) >= V_29 ) {
if ( V_50 ) {
V_51 = - V_50 ;
memcpy ( V_43 -> V_30 + V_50 , V_11 ,
V_51 + V_29 ) ;
V_15 = V_43 -> V_30 ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xc8"
: "+S"(src), "+D"(dst) \
: "a"((long)-1), "c"((unsigned long)1));
V_51 += V_29 ;
V_15 = V_11 + V_51 ;
}
if ( V_49 - V_51 >= V_29 ) {
asm volatile (".byte 0xf3,0x0f,0xa6,0xc8"
: "+S"(src), "+D"(dst)
: "a"((long)-1),
"c"((unsigned long)((len - done) / SHA1_BLOCK_SIZE)));
V_51 += ( ( V_49 - V_51 ) - ( V_49 - V_51 ) % V_29 ) ;
V_15 = V_11 + V_51 ;
}
V_50 = 0 ;
}
memcpy ( ( T_1 * ) ( V_43 -> V_24 ) , V_16 , V_31 ) ;
memcpy ( V_43 -> V_30 + V_50 , V_15 , V_49 - V_51 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_23 * V_24 = (struct V_23 * ) F_2 ( V_2 ) ;
unsigned int V_50 , V_52 ;
T_4 V_53 ;
static const T_1 V_54 [ 64 ] = { 0x80 , } ;
V_53 = F_34 ( V_24 -> V_17 << 3 ) ;
V_50 = V_24 -> V_17 & 0x3f ;
V_52 = ( V_50 < 56 ) ? ( 56 - V_50 ) : ( ( 64 + 56 ) - V_50 ) ;
F_32 ( V_2 , V_54 , V_52 ) ;
F_32 ( V_2 , ( const T_1 * ) & V_53 , sizeof( V_53 ) ) ;
F_11 ( ( T_2 * ) ( V_24 -> V_24 ) , ( T_2 * ) V_13 , 5 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_32 * V_43 = F_2 ( V_2 ) ;
* V_43 = (struct V_32 ) {
. V_24 = { V_55 , V_56 , V_57 , V_58 , \
V_59 , V_60 , V_61 , V_62 } ,
} ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_49 )
{
struct V_32 * V_43 = F_2 ( V_2 ) ;
unsigned int V_50 , V_51 ;
const T_1 * V_15 ;
T_1 V_18 [ 128 + V_19 - V_20 ] V_21
( ( F_14 ( V_20 ) ) ) ;
T_1 * V_16 = F_15 ( & V_18 [ 0 ] , V_19 ) ;
V_50 = V_43 -> V_17 & 0x3f ;
V_43 -> V_17 += V_49 ;
V_51 = 0 ;
V_15 = V_11 ;
memcpy ( V_16 , ( T_1 * ) ( V_43 -> V_24 ) , V_34 ) ;
if ( ( V_50 + V_49 ) >= V_33 ) {
if ( V_50 ) {
V_51 = - V_50 ;
memcpy ( V_43 -> V_18 + V_50 , V_11 ,
V_51 + V_33 ) ;
V_15 = V_43 -> V_18 ;
asm volatile (".byte 0xf3,0x0f,0xa6,0xd0"
: "+S"(src), "+D"(dst)
: "a"((long)-1), "c"((unsigned long)1));
V_51 += V_33 ;
V_15 = V_11 + V_51 ;
}
if ( V_49 - V_51 >= V_33 ) {
asm volatile (".byte 0xf3,0x0f,0xa6,0xd0"
: "+S"(src), "+D"(dst)
: "a"((long)-1),
"c"((unsigned long)((len - done) / 64)));
V_51 += ( ( V_49 - V_51 ) - ( V_49 - V_51 ) % 64 ) ;
V_15 = V_11 + V_51 ;
}
V_50 = 0 ;
}
memcpy ( ( T_1 * ) ( V_43 -> V_24 ) , V_16 , V_34 ) ;
memcpy ( V_43 -> V_18 + V_50 , V_15 , V_49 - V_51 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_32 * V_24 =
(struct V_32 * ) F_2 ( V_2 ) ;
unsigned int V_50 , V_52 ;
T_4 V_53 ;
static const T_1 V_54 [ 64 ] = { 0x80 , } ;
V_53 = F_34 ( V_24 -> V_17 << 3 ) ;
V_50 = V_24 -> V_17 & 0x3f ;
V_52 = ( V_50 < 56 ) ? ( 56 - V_50 ) : ( ( 64 + 56 ) - V_50 ) ;
F_36 ( V_2 , V_54 , V_52 ) ;
F_36 ( V_2 , ( const T_1 * ) & V_53 , sizeof( V_53 ) ) ;
F_11 ( ( T_2 * ) ( V_24 -> V_24 ) , ( T_2 * ) V_13 , 8 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
void * V_13 )
{
int V_63 = F_39 ( V_2 -> V_7 ) ;
void * V_43 = F_2 ( V_2 ) ;
memcpy ( V_13 , V_43 , V_63 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
const void * V_14 )
{
int V_63 = F_39 ( V_2 -> V_7 ) ;
void * V_43 = F_2 ( V_2 ) ;
memcpy ( V_43 , V_14 , V_63 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
int V_64 = - V_65 ;
struct V_66 * V_67 = & F_42 ( 0 ) ;
struct V_68 * V_69 ;
struct V_68 * V_70 ;
if ( ! F_43 ( V_71 ) || ! F_44 ( V_72 ) )
return - V_65 ;
if ( V_67 -> V_73 < 0x0f ) {
V_69 = & V_74 ;
V_70 = & V_75 ;
} else {
V_69 = & V_76 ;
V_70 = & V_77 ;
}
V_64 = F_45 ( V_69 ) ;
if ( V_64 )
goto V_13;
V_64 = F_45 ( V_70 ) ;
if ( V_64 )
goto V_78;
F_26 (KERN_NOTICE PFX L_2 ) ;
return 0 ;
V_78:
F_46 ( V_69 ) ;
V_13:
F_26 (KERN_ERR PFX L_3 ) ;
return V_64 ;
}
static void T_6 F_47 ( void )
{
struct V_66 * V_67 = & F_42 ( 0 ) ;
if ( V_67 -> V_73 >= 0x0f ) {
F_46 ( & V_76 ) ;
F_46 ( & V_77 ) ;
} else {
F_46 ( & V_74 ) ;
F_46 ( & V_75 ) ;
}
}
