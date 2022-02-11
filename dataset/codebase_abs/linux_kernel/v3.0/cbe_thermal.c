static inline T_1 F_1 ( T_1 V_1 )
{
return ( ( V_1 & 0x3f ) << 1 ) + V_2 ;
}
static inline T_1 F_2 ( T_1 V_3 )
{
return ( ( V_3 - V_2 ) >> 1 ) & 0x3f ;
}
static struct V_4 T_2 * F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( V_6 , struct V_7 , V_6 ) ;
return F_5 ( F_6 ( V_7 ) ) ;
}
static T_1 F_7 ( struct V_5 * V_6 , union V_8 T_2 * V_9 )
{
union V_8 V_10 ;
struct V_7 * V_7 ;
V_7 = F_4 ( V_6 , struct V_7 , V_6 ) ;
V_10 . V_11 = F_8 ( & V_9 -> V_11 ) ;
return V_10 . V_12 [ V_7 -> V_13 ] ;
}
static T_3 F_9 ( struct V_5 * V_6 , struct V_14 * V_15 ,
char * V_16 )
{
T_1 V_10 ;
struct V_4 T_2 * V_17 ;
V_17 = F_3 ( V_6 ) ;
V_10 = F_7 ( V_6 , & V_17 -> V_18 ) ;
return sprintf ( V_16 , L_1 , F_1 ( V_10 ) ) ;
}
static T_3 F_10 ( struct V_4 T_2 * V_17 , char * V_16 , int V_19 )
{
T_4 V_10 ;
V_10 = F_8 ( & V_17 -> V_20 . V_11 ) ;
V_10 >>= V_19 ;
V_10 &= 0x3F ;
return sprintf ( V_16 , L_1 , F_1 ( V_10 ) ) ;
}
static T_3 F_11 ( struct V_4 T_2 * V_17 , const char * V_16 , T_5 V_21 , int V_19 )
{
T_4 V_1 ;
int V_3 ;
T_4 V_22 ;
int V_23 ;
V_23 = sscanf ( V_16 , L_2 , & V_3 ) ;
if ( V_23 != 1 || V_3 < V_2 || V_3 > V_24 )
return - V_25 ;
V_22 = F_2 ( V_3 ) ;
V_1 = F_8 ( & V_17 -> V_20 . V_11 ) ;
V_1 &= ~ ( 0xffull << V_19 ) ;
V_1 |= V_22 << V_19 ;
F_12 ( & V_17 -> V_20 . V_11 , V_1 ) ;
return V_21 ;
}
static T_3 F_13 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_10 ( F_3 ( V_6 ) , V_16 , 0 ) ;
}
static T_3 F_14 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_10 ( F_3 ( V_6 ) , V_16 , 8 ) ;
}
static T_3 F_15 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_10 ( F_3 ( V_6 ) , V_16 , 16 ) ;
}
static T_3 F_16 ( struct V_5 * V_6 ,
struct V_14 * V_15 , const char * V_16 , T_5 V_21 )
{
return F_11 ( F_3 ( V_6 ) , V_16 , V_21 , 0 ) ;
}
static T_3 F_17 ( struct V_5 * V_6 ,
struct V_14 * V_15 , const char * V_16 , T_5 V_21 )
{
return F_11 ( F_3 ( V_6 ) , V_16 , V_21 , 8 ) ;
}
static T_3 F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 , const char * V_16 , T_5 V_21 )
{
return F_11 ( F_3 ( V_6 ) , V_16 , V_21 , 16 ) ;
}
static T_3 F_19 ( struct V_5 * V_6 , char * V_16 , int V_19 )
{
struct V_4 T_2 * V_17 ;
T_4 V_10 ;
V_17 = F_20 ( V_6 -> V_26 ) ;
V_10 = F_8 ( & V_17 -> V_27 ) ;
V_10 = ( V_10 >> V_19 ) & 0x3f ;
return sprintf ( V_16 , L_1 , F_1 ( V_10 ) ) ;
}
static T_3 F_21 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_19 ( V_6 , V_16 , 32 ) ;
}
static T_3 F_22 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_19 ( V_6 , V_16 , 0 ) ;
}
static T_3 F_23 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_10 ( F_20 ( V_6 -> V_26 ) , V_16 , 32 ) ;
}
static T_3 F_24 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_10 ( F_20 ( V_6 -> V_26 ) , V_16 , 40 ) ;
}
static T_3 F_25 ( struct V_5 * V_6 ,
struct V_14 * V_15 , char * V_16 )
{
return F_10 ( F_20 ( V_6 -> V_26 ) , V_16 , 48 ) ;
}
static T_3 F_26 ( struct V_5 * V_6 ,
struct V_14 * V_15 , const char * V_16 , T_5 V_21 )
{
return F_11 ( F_20 ( V_6 -> V_26 ) , V_16 , V_21 , 32 ) ;
}
static T_3 F_27 ( struct V_5 * V_6 ,
struct V_14 * V_15 , const char * V_16 , T_5 V_21 )
{
return F_11 ( F_20 ( V_6 -> V_26 ) , V_16 , V_21 , 40 ) ;
}
static T_3 F_28 ( struct V_5 * V_6 ,
struct V_14 * V_15 , const char * V_16 , T_5 V_21 )
{
return F_11 ( F_20 ( V_6 -> V_26 ) , V_16 , V_21 , 48 ) ;
}
static int T_6 F_29 ( void )
{
int V_28 ;
struct V_4 T_2 * V_17 ;
struct V_5 * V_6 ;
union V_29 V_30 ;
union V_8 V_31 ;
T_4 V_32 ;
union V_8 V_33 ;
T_4 V_34 ;
V_30 . V_35 = 0x1F0803 ;
V_30 . V_12 = 0x100803 ;
V_31 . V_11 = 0x1010101010101010ull ;
V_32 = 0x10 ;
V_33 . V_11 = 0x0404040404040404ull ;
V_34 = 0x04 ;
F_30 (cpu) {
F_31 ( L_3 , V_28 ) ;
V_6 = F_32 ( V_28 ) ;
if ( ! V_6 ) {
F_33 ( L_4 ) ;
return - V_25 ;
}
V_17 = F_20 ( V_6 -> V_26 ) ;
if ( ! V_17 ) {
F_33 ( L_5 ) ;
return - V_25 ;
}
F_12 ( & V_17 -> V_36 , V_32 ) ;
F_12 ( & V_17 -> V_37 . V_11 , V_31 . V_11 ) ;
F_12 ( & V_17 -> V_20 . V_11 , V_30 . V_11 ) ;
F_12 ( & V_17 -> V_38 . V_11 , V_33 . V_11 ) ;
F_12 ( & V_17 -> V_39 , V_34 ) ;
}
return 0 ;
}
static int T_6 F_34 ( void )
{
int V_40 = F_29 () ;
if ( V_40 == 0 ) {
F_35 ( & V_41 ) ;
F_36 ( & V_42 ) ;
}
return V_40 ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_41 ) ;
F_39 ( & V_42 ) ;
}
