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
V_2 -> V_10 = F_8 ( V_2 -> V_7 ) ;
F_3 ( V_2 , V_11 , 0x40000000 ) ;
F_3 ( V_2 , V_12 , 0x00000000 ) ;
F_3 ( V_2 , V_13 , 3 ) ;
F_3 ( V_2 , V_14 , 3 ) ;
F_3 ( V_2 , V_15 , 1 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_13 , 3 ) ;
F_10 ( V_2 -> V_7 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_16 ;
unsigned long V_17 ;
F_12 ( & V_2 -> V_18 , V_17 ) ;
V_16 = ( T_1 ) ( F_1 ( V_2 , V_19 ) & 0xffff ) << 32 ;
V_16 |= F_1 ( V_2 , V_20 ) ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
return V_16 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_21 )
{
unsigned long V_17 ;
F_12 ( & V_2 -> V_18 , V_17 ) ;
F_3 ( V_2 , V_13 , 1 ) ;
F_3 ( V_2 , V_22 , V_21 >> 32 ) ;
F_3 ( V_2 , V_23 , V_21 & 0xffffffff ) ;
F_3 ( V_2 , V_14 , 1 ) ;
F_3 ( V_2 , V_24 , 1 ) ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
return V_21 ;
}
static T_2 F_15 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
V_2 -> V_27 . V_28 ( & V_2 -> V_27 ) ;
return V_29 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_30 )
{
unsigned long V_17 ;
int V_31 ;
int V_6 = 0 ;
F_12 ( & V_2 -> V_18 , V_17 ) ;
V_31 = V_2 -> V_32 [ V_33 ] | V_2 -> V_32 [ V_34 ] ;
if ( ! V_31 )
V_6 = F_5 ( V_2 ) ;
if ( ! V_6 )
V_2 -> V_32 [ V_30 ] = 1 ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
return V_6 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_30 )
{
unsigned long V_17 ;
int V_31 , V_35 ;
F_12 ( & V_2 -> V_18 , V_17 ) ;
V_31 = V_2 -> V_32 [ V_33 ] | V_2 -> V_32 [ V_34 ] ;
V_2 -> V_32 [ V_30 ] = 0 ;
V_35 = V_2 -> V_32 [ V_33 ] | V_2 -> V_32 [ V_34 ] ;
if ( V_31 && ! V_35 )
F_9 ( V_2 ) ;
F_13 ( & V_2 -> V_18 , V_17 ) ;
}
static struct V_1 * F_18 ( struct V_36 * V_37 )
{
return F_19 ( V_37 , struct V_1 , V_37 ) ;
}
static T_1 F_20 ( struct V_36 * V_37 )
{
return F_11 ( F_18 ( V_37 ) ) ;
}
static int F_21 ( struct V_36 * V_37 )
{
int V_6 ;
struct V_1 * V_2 = F_18 ( V_37 ) ;
V_6 = F_16 ( V_2 , V_33 ) ;
if ( ! V_6 )
F_22 ( V_37 , V_2 -> V_10 ) ;
return V_6 ;
}
static void F_23 ( struct V_36 * V_37 )
{
F_17 ( F_18 ( V_37 ) , V_33 ) ;
}
static void F_24 ( struct V_36 * V_37 )
{
F_21 ( V_37 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_37 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_38 = F_26 ( & V_2 -> V_8 -> V_9 ) ;
V_37 -> V_39 = 200 ;
V_37 -> V_40 = F_20 ;
V_37 -> V_41 = F_21 ;
V_37 -> V_42 = F_23 ;
V_37 -> V_43 = F_23 ;
V_37 -> V_44 = F_24 ;
V_37 -> V_45 = F_27 ( 48 ) ;
V_37 -> V_17 = V_46 ;
F_28 ( & V_2 -> V_8 -> V_9 , L_2 ) ;
F_29 ( V_37 , 1 ) ;
return 0 ;
}
static struct V_1 * F_30 ( struct V_47 * V_27 )
{
return F_19 ( V_27 , struct V_1 , V_27 ) ;
}
static void F_31 ( enum V_48 V_49 ,
struct V_47 * V_27 )
{
struct V_1 * V_2 = F_30 ( V_27 ) ;
switch ( V_27 -> V_49 ) {
case V_50 :
F_17 ( V_2 , V_34 ) ;
break;
default:
break;
}
switch ( V_49 ) {
case V_50 :
F_28 ( & V_2 -> V_8 -> V_9 , L_3 ) ;
F_16 ( V_2 , V_34 ) ;
F_32 ( & V_2 -> V_27 , V_2 -> V_10 ) ;
break;
case V_51 :
case V_52 :
F_17 ( V_2 , V_34 ) ;
break;
default:
break;
}
}
static int F_33 ( unsigned long V_53 ,
struct V_47 * V_27 )
{
struct V_1 * V_2 = F_30 ( V_27 ) ;
T_1 V_21 ;
int V_54 ;
V_21 = F_14 ( V_2 , F_11 ( V_2 ) + V_53 ) ;
V_54 = F_11 ( V_2 ) < ( V_21 - 1 ) ;
return ! V_54 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_47 * V_27 = & V_2 -> V_27 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_38 = F_26 ( & V_2 -> V_8 -> V_9 ) ;
V_27 -> V_55 = V_56 ;
V_27 -> V_39 = 200 ;
V_27 -> V_57 = V_58 ;
V_27 -> V_59 = F_33 ;
V_27 -> V_60 = F_31 ;
F_28 ( & V_2 -> V_8 -> V_9 , L_4 ) ;
F_35 ( V_27 , 1 , 2 , 0xffffffff ) ;
}
static int F_36 ( struct V_61 * V_8 )
{
struct V_1 * V_2 ;
struct V_62 * V_63 ;
int V_25 ;
V_2 = F_37 ( & V_8 -> V_9 , sizeof( * V_2 ) , V_64 ) ;
if ( V_2 == NULL )
return - V_65 ;
V_2 -> V_8 = V_8 ;
F_38 ( V_8 , V_2 ) ;
V_25 = F_39 ( V_8 , 0 ) ;
if ( V_25 < 0 ) {
F_7 ( & V_8 -> V_9 , L_5 ) ;
return - V_66 ;
}
V_63 = F_40 ( V_8 , V_67 , 0 ) ;
V_2 -> V_4 = F_41 ( & V_8 -> V_9 , V_63 ) ;
if ( F_42 ( V_2 -> V_4 ) )
return F_43 ( V_2 -> V_4 ) ;
V_2 -> V_7 = F_44 ( & V_8 -> V_9 , L_6 ) ;
if ( F_42 ( V_2 -> V_7 ) ) {
F_7 ( & V_8 -> V_9 , L_7 ) ;
return F_43 ( V_2 -> V_7 ) ;
}
if ( F_45 ( & V_8 -> V_9 , V_25 , F_15 ,
V_68 | V_69 | V_70 ,
F_26 ( & V_8 -> V_9 ) , V_2 ) ) {
F_7 ( & V_8 -> V_9 , L_8 ) ;
return - V_71 ;
}
F_46 ( & V_2 -> V_18 ) ;
F_34 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_61 * V_8 )
{
return - V_72 ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_73 ) ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_73 ) ;
}
