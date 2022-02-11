static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_6 ( V_2 -> V_7 ) ;
if ( V_6 ) {
F_7 ( & V_2 -> V_8 -> V_9 , L_1 ) ;
return V_6 ;
}
F_3 ( V_2 , V_10 , 0x40000000 ) ;
F_3 ( V_2 , V_11 , 0x00000000 ) ;
F_3 ( V_2 , V_12 , 3 ) ;
F_3 ( V_2 , V_13 , 3 ) ;
F_3 ( V_2 , V_14 , 1 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_12 , 3 ) ;
F_9 ( V_2 -> V_7 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_15 ;
unsigned long V_16 ;
F_11 ( & V_2 -> V_17 , V_16 ) ;
V_15 = ( T_1 ) ( F_1 ( V_2 , V_18 ) & 0xffff ) << 32 ;
V_15 |= F_1 ( V_2 , V_19 ) ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
return V_15 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_1 V_20 )
{
unsigned long V_16 ;
F_11 ( & V_2 -> V_17 , V_16 ) ;
F_3 ( V_2 , V_12 , 1 ) ;
F_3 ( V_2 , V_21 , V_20 >> 32 ) ;
F_3 ( V_2 , V_22 , V_20 & 0xffffffff ) ;
F_3 ( V_2 , V_13 , 1 ) ;
F_3 ( V_2 , V_23 , 1 ) ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
return V_20 ;
}
static T_2 F_14 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
V_2 -> V_26 . V_27 ( & V_2 -> V_26 ) ;
return V_28 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_29 )
{
unsigned long V_16 ;
int V_30 ;
int V_6 = 0 ;
F_11 ( & V_2 -> V_17 , V_16 ) ;
V_30 = V_2 -> V_31 [ V_32 ] | V_2 -> V_31 [ V_33 ] ;
if ( ! V_30 )
V_6 = F_5 ( V_2 ) ;
if ( ! V_6 )
V_2 -> V_31 [ V_29 ] = 1 ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
return V_6 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_29 )
{
unsigned long V_16 ;
int V_30 , V_34 ;
F_11 ( & V_2 -> V_17 , V_16 ) ;
V_30 = V_2 -> V_31 [ V_32 ] | V_2 -> V_31 [ V_33 ] ;
V_2 -> V_31 [ V_29 ] = 0 ;
V_34 = V_2 -> V_31 [ V_32 ] | V_2 -> V_31 [ V_33 ] ;
if ( V_30 && ! V_34 )
F_8 ( V_2 ) ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
}
static struct V_1 * F_17 ( struct V_35 * V_36 )
{
return F_18 ( V_36 , struct V_1 , V_36 ) ;
}
static T_1 F_19 ( struct V_35 * V_36 )
{
return F_10 ( F_17 ( V_36 ) ) ;
}
static int F_20 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
return F_15 ( V_2 , V_32 ) ;
}
static void F_21 ( struct V_35 * V_36 )
{
F_16 ( F_17 ( V_36 ) , V_32 ) ;
}
static void F_22 ( struct V_35 * V_36 )
{
F_20 ( V_36 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = & V_2 -> V_36 ;
V_36 -> V_37 = F_24 ( & V_2 -> V_8 -> V_9 ) ;
V_36 -> V_38 = 200 ;
V_36 -> V_39 = F_19 ;
V_36 -> V_40 = F_20 ;
V_36 -> V_41 = F_21 ;
V_36 -> V_42 = F_21 ;
V_36 -> V_43 = F_22 ;
V_36 -> V_44 = F_25 ( 48 ) ;
V_36 -> V_16 = V_45 ;
F_26 ( & V_2 -> V_8 -> V_9 , L_2 ) ;
F_27 ( V_36 , V_2 -> V_46 ) ;
return 0 ;
}
static struct V_1 * F_28 ( struct V_47 * V_26 )
{
return F_18 ( V_26 , struct V_1 , V_26 ) ;
}
static int F_29 ( struct V_47 * V_26 )
{
struct V_1 * V_2 = F_28 ( V_26 ) ;
F_16 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_30 ( struct V_47 * V_26 )
{
struct V_1 * V_2 = F_28 ( V_26 ) ;
F_26 ( & V_2 -> V_8 -> V_9 , L_3 ) ;
F_15 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_31 ( unsigned long V_48 ,
struct V_47 * V_26 )
{
struct V_1 * V_2 = F_28 ( V_26 ) ;
T_1 V_20 ;
int V_49 ;
V_20 = F_13 ( V_2 , F_10 ( V_2 ) + V_48 ) ;
V_49 = F_10 ( V_2 ) < ( V_20 - 1 ) ;
return ! V_49 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_47 * V_26 = & V_2 -> V_26 ;
V_26 -> V_37 = F_24 ( & V_2 -> V_8 -> V_9 ) ;
V_26 -> V_50 = V_51 ;
V_26 -> V_38 = 200 ;
V_26 -> V_52 = V_53 ;
V_26 -> V_54 = F_31 ;
V_26 -> V_55 = F_29 ;
V_26 -> V_56 = F_30 ;
F_26 ( & V_2 -> V_8 -> V_9 , L_4 ) ;
F_33 ( V_26 , V_2 -> V_46 , 2 , 0xffffffff ) ;
}
static int F_34 ( struct V_57 * V_8 )
{
struct V_1 * V_2 ;
struct V_58 * V_59 ;
int V_24 ;
int V_6 ;
V_2 = F_35 ( & V_8 -> V_9 , sizeof( * V_2 ) , V_60 ) ;
if ( V_2 == NULL )
return - V_61 ;
V_2 -> V_8 = V_8 ;
F_36 ( V_8 , V_2 ) ;
V_24 = F_37 ( V_8 , 0 ) ;
if ( V_24 < 0 ) {
F_7 ( & V_8 -> V_9 , L_5 ) ;
return - V_62 ;
}
V_59 = F_38 ( V_8 , V_63 , 0 ) ;
V_2 -> V_4 = F_39 ( & V_8 -> V_9 , V_59 ) ;
if ( F_40 ( V_2 -> V_4 ) )
return F_41 ( V_2 -> V_4 ) ;
if ( F_42 ( & V_8 -> V_9 , V_24 , F_14 ,
V_64 | V_65 | V_66 ,
F_24 ( & V_8 -> V_9 ) , V_2 ) ) {
F_7 ( & V_8 -> V_9 , L_6 ) ;
return - V_67 ;
}
V_2 -> V_7 = F_43 ( & V_8 -> V_9 , L_7 ) ;
if ( F_40 ( V_2 -> V_7 ) ) {
F_7 ( & V_8 -> V_9 , L_8 ) ;
return F_41 ( V_2 -> V_7 ) ;
}
V_6 = F_44 ( V_2 -> V_7 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_8 -> V_9 , L_9 ) ;
return V_6 ;
}
V_6 = F_6 ( V_2 -> V_7 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_8 -> V_9 , L_1 ) ;
F_45 ( V_2 -> V_7 ) ;
return V_6 ;
}
V_2 -> V_46 = F_46 ( V_2 -> V_7 ) ;
F_9 ( V_2 -> V_7 ) ;
F_47 ( & V_2 -> V_17 ) ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_57 * V_8 )
{
return - V_68 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_69 ) ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_69 ) ;
}
