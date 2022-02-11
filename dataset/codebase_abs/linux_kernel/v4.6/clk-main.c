static inline bool F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return V_2 & V_4 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_1 = V_8 -> V_1 ;
T_1 V_9 ;
F_2 ( V_1 , V_10 , & V_9 ) ;
V_9 &= ~ V_11 ;
if ( V_9 & V_12 )
return 0 ;
if ( ! ( V_9 & V_13 ) ) {
V_9 |= V_13 | V_14 ;
F_5 ( V_1 , V_10 , V_9 ) ;
}
while ( ! F_1 ( V_1 ) )
F_6 () ;
return 0 ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_1 = V_8 -> V_1 ;
T_1 V_9 ;
F_2 ( V_1 , V_10 , & V_9 ) ;
if ( V_9 & V_12 )
return;
if ( ! ( V_9 & V_13 ) )
return;
V_9 &= ~ ( V_14 | V_13 ) ;
F_5 ( V_1 , V_10 , V_9 | V_14 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_1 = V_8 -> V_1 ;
T_1 V_9 , V_2 ;
F_2 ( V_1 , V_10 , & V_9 ) ;
if ( V_9 & V_12 )
return 1 ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return ( V_2 & V_4 ) && ( V_9 & V_13 ) ;
}
static struct V_15 * T_2
F_9 ( struct V_1 * V_1 ,
const char * V_16 ,
const char * V_17 ,
bool V_18 )
{
struct V_7 * V_8 ;
struct V_15 * V_15 = NULL ;
struct V_19 V_20 ;
if ( ! V_16 || ! V_17 )
return F_10 ( - V_21 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_22 ) ;
if ( ! V_8 )
return F_10 ( - V_23 ) ;
V_20 . V_16 = V_16 ;
V_20 . V_24 = & V_25 ;
V_20 . V_26 = & V_17 ;
V_20 . V_27 = 1 ;
V_20 . V_28 = V_29 ;
V_8 -> V_6 . V_20 = & V_20 ;
V_8 -> V_1 = V_1 ;
if ( V_18 )
F_12 ( V_1 ,
V_10 , V_11 |
V_13 ,
V_12 | V_14 ) ;
V_15 = F_13 ( NULL , & V_8 -> V_6 ) ;
if ( F_14 ( V_15 ) )
F_15 ( V_8 ) ;
return V_15 ;
}
static void T_2 F_16 ( struct V_30 * V_31 )
{
struct V_15 * V_15 ;
const char * V_16 = V_31 -> V_16 ;
const char * V_17 ;
struct V_1 * V_1 ;
bool V_18 ;
F_17 ( V_31 , L_1 , & V_16 ) ;
V_18 = F_18 ( V_31 , L_2 ) ;
V_17 = F_19 ( V_31 , 0 ) ;
V_1 = F_20 ( F_21 ( V_31 ) ) ;
if ( F_14 ( V_1 ) )
return;
V_15 = F_9 ( V_1 , V_16 , V_17 , V_18 ) ;
if ( F_14 ( V_15 ) )
return;
F_22 ( V_31 , V_32 , V_15 ) ;
}
static bool F_23 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return V_2 & V_33 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_34 * V_8 = F_25 ( V_6 ) ;
struct V_1 * V_1 = V_8 -> V_1 ;
unsigned int V_35 ;
F_2 ( V_1 , V_10 , & V_35 ) ;
if ( ! ( V_35 & V_36 ) )
F_12 ( V_1 , V_10 ,
V_11 | V_36 ,
V_36 | V_14 ) ;
while ( ! F_23 ( V_1 ) )
F_6 () ;
return 0 ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_34 * V_8 = F_25 ( V_6 ) ;
struct V_1 * V_1 = V_8 -> V_1 ;
unsigned int V_35 ;
F_2 ( V_1 , V_10 , & V_35 ) ;
if ( ! ( V_35 & V_36 ) )
return;
F_12 ( V_1 , V_10 ,
V_11 | V_36 , V_14 ) ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_34 * V_8 = F_25 ( V_6 ) ;
struct V_1 * V_1 = V_8 -> V_1 ;
unsigned int V_35 , V_2 ;
F_2 ( V_1 , V_10 , & V_35 ) ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return ( V_35 & V_36 ) && ( V_2 & V_33 ) ;
}
static unsigned long F_28 ( struct V_5 * V_6 ,
unsigned long V_37 )
{
struct V_34 * V_8 = F_25 ( V_6 ) ;
return V_8 -> V_38 ;
}
static unsigned long F_29 ( struct V_5 * V_6 ,
unsigned long V_39 )
{
struct V_34 * V_8 = F_25 ( V_6 ) ;
return V_8 -> V_40 ;
}
static struct V_15 * T_2
F_30 ( struct V_1 * V_1 ,
const char * V_16 ,
T_1 V_38 , T_1 V_40 )
{
struct V_34 * V_8 ;
struct V_15 * V_15 = NULL ;
struct V_19 V_20 ;
if ( ! V_16 || ! V_38 )
return F_10 ( - V_21 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_22 ) ;
if ( ! V_8 )
return F_10 ( - V_23 ) ;
V_20 . V_16 = V_16 ;
V_20 . V_24 = & V_41 ;
V_20 . V_26 = NULL ;
V_20 . V_27 = 0 ;
V_20 . V_28 = V_29 ;
V_8 -> V_6 . V_20 = & V_20 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_38 = V_38 ;
V_8 -> V_40 = V_40 ;
V_15 = F_13 ( NULL , & V_8 -> V_6 ) ;
if ( F_14 ( V_15 ) )
F_15 ( V_8 ) ;
return V_15 ;
}
static void T_2 F_31 ( struct V_30 * V_31 )
{
struct V_15 * V_15 ;
T_1 V_38 = 0 ;
T_1 V_40 = 0 ;
const char * V_16 = V_31 -> V_16 ;
struct V_1 * V_1 ;
F_17 ( V_31 , L_1 , & V_16 ) ;
F_32 ( V_31 , L_3 , & V_38 ) ;
F_32 ( V_31 , L_4 , & V_40 ) ;
V_1 = F_20 ( F_21 ( V_31 ) ) ;
if ( F_14 ( V_1 ) )
return;
V_15 = F_30 ( V_1 , V_16 , V_38 , V_40 ) ;
if ( F_14 ( V_15 ) )
return;
F_22 ( V_31 , V_32 , V_15 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
unsigned long V_42 , V_43 ;
unsigned int V_44 ;
V_43 = V_45 + F_34 ( V_46 ) ;
do {
V_42 = V_45 ;
F_2 ( V_1 , V_47 , & V_44 ) ;
if ( V_44 & V_48 )
return 0 ;
F_35 ( V_49 , V_50 ) ;
} while ( F_36 ( V_42 , V_43 ) );
return - V_51 ;
}
static unsigned long F_37 ( struct V_1 * V_1 ,
unsigned long V_37 )
{
unsigned int V_44 ;
if ( V_37 )
return V_37 ;
F_38 ( L_5 ) ;
F_2 ( V_1 , V_47 , & V_44 ) ;
if ( ! ( V_44 & V_48 ) )
return 0 ;
return ( ( V_44 & V_52 ) * V_53 ) / V_54 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_55 * V_56 = F_40 ( V_6 ) ;
return F_33 ( V_56 -> V_1 ) ;
}
static int F_41 ( struct V_5 * V_6 )
{
struct V_55 * V_56 = F_40 ( V_6 ) ;
unsigned int V_2 ;
F_2 ( V_56 -> V_1 , V_47 , & V_2 ) ;
return V_2 & V_48 ? 1 : 0 ;
}
static unsigned long F_42 ( struct V_5 * V_6 ,
unsigned long V_37 )
{
struct V_55 * V_56 = F_40 ( V_6 ) ;
return F_37 ( V_56 -> V_1 , V_37 ) ;
}
static struct V_15 * T_2
F_43 ( struct V_1 * V_1 ,
const char * V_16 ,
const char * V_17 )
{
struct V_55 * V_56 ;
struct V_15 * V_15 = NULL ;
struct V_19 V_20 ;
if ( ! V_16 )
return F_10 ( - V_21 ) ;
if ( ! V_17 )
return F_10 ( - V_21 ) ;
V_56 = F_11 ( sizeof( * V_56 ) , V_22 ) ;
if ( ! V_56 )
return F_10 ( - V_23 ) ;
V_20 . V_16 = V_16 ;
V_20 . V_24 = & V_57 ;
V_20 . V_26 = & V_17 ;
V_20 . V_27 = 1 ;
V_20 . V_28 = 0 ;
V_56 -> V_6 . V_20 = & V_20 ;
V_56 -> V_1 = V_1 ;
V_15 = F_13 ( NULL , & V_56 -> V_6 ) ;
if ( F_14 ( V_15 ) )
F_15 ( V_56 ) ;
return V_15 ;
}
static void T_2 F_44 ( struct V_30 * V_31 )
{
struct V_15 * V_15 ;
const char * V_17 ;
const char * V_16 = V_31 -> V_16 ;
struct V_1 * V_1 ;
V_17 = F_19 ( V_31 , 0 ) ;
F_17 ( V_31 , L_1 , & V_16 ) ;
V_1 = F_20 ( F_21 ( V_31 ) ) ;
if ( F_14 ( V_1 ) )
return;
V_15 = F_43 ( V_1 , V_16 , V_17 ) ;
if ( F_14 ( V_15 ) )
return;
F_22 ( V_31 , V_32 , V_15 ) ;
}
static inline bool F_45 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return V_2 & V_58 ? 1 : 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_59 * V_56 = F_47 ( V_6 ) ;
struct V_1 * V_1 = V_56 -> V_1 ;
while ( ! F_45 ( V_1 ) )
F_6 () ;
return F_33 ( V_1 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_59 * V_56 = F_47 ( V_6 ) ;
return F_45 ( V_56 -> V_1 ) ;
}
static unsigned long F_49 ( struct V_5 * V_6 ,
unsigned long V_37 )
{
struct V_59 * V_56 = F_47 ( V_6 ) ;
return F_37 ( V_56 -> V_1 , V_37 ) ;
}
static int F_50 ( struct V_5 * V_6 , T_3 V_60 )
{
struct V_59 * V_56 = F_47 ( V_6 ) ;
struct V_1 * V_1 = V_56 -> V_1 ;
unsigned int V_9 ;
if ( V_60 > 1 )
return - V_21 ;
F_2 ( V_1 , V_10 , & V_9 ) ;
V_9 &= ~ V_11 ;
if ( V_60 && ! ( V_9 & V_61 ) )
F_5 ( V_1 , V_10 , V_9 | V_61 ) ;
else if ( ! V_60 && ( V_9 & V_61 ) )
F_5 ( V_1 , V_10 , V_9 & ~ V_61 ) ;
while ( ! F_45 ( V_1 ) )
F_6 () ;
return 0 ;
}
static T_3 F_51 ( struct V_5 * V_6 )
{
struct V_59 * V_56 = F_47 ( V_6 ) ;
unsigned int V_2 ;
F_2 ( V_56 -> V_1 , V_10 , & V_2 ) ;
return V_2 & V_13 ? 1 : 0 ;
}
static struct V_15 * T_2
F_52 ( struct V_1 * V_1 ,
const char * V_16 ,
const char * * V_26 ,
int V_27 )
{
struct V_59 * V_56 ;
struct V_15 * V_15 = NULL ;
struct V_19 V_20 ;
unsigned int V_2 ;
if ( ! V_16 )
return F_10 ( - V_21 ) ;
if ( ! V_26 || ! V_27 )
return F_10 ( - V_21 ) ;
V_56 = F_11 ( sizeof( * V_56 ) , V_22 ) ;
if ( ! V_56 )
return F_10 ( - V_23 ) ;
V_20 . V_16 = V_16 ;
V_20 . V_24 = & V_62 ;
V_20 . V_26 = V_26 ;
V_20 . V_27 = V_27 ;
V_20 . V_28 = V_63 ;
V_56 -> V_6 . V_20 = & V_20 ;
V_56 -> V_1 = V_1 ;
F_2 ( V_56 -> V_1 , V_10 , & V_2 ) ;
V_56 -> V_64 = V_2 & V_13 ? 1 : 0 ;
V_15 = F_13 ( NULL , & V_56 -> V_6 ) ;
if ( F_14 ( V_15 ) )
F_15 ( V_56 ) ;
return V_15 ;
}
static void T_2 F_53 ( struct V_30 * V_31 )
{
struct V_15 * V_15 ;
const char * V_26 [ 2 ] ;
unsigned int V_27 ;
const char * V_16 = V_31 -> V_16 ;
struct V_1 * V_1 ;
V_27 = F_54 ( V_31 ) ;
if ( V_27 == 0 || V_27 > 2 )
return;
F_55 ( V_31 , V_26 , V_27 ) ;
V_1 = F_20 ( F_21 ( V_31 ) ) ;
if ( F_14 ( V_1 ) )
return;
F_17 ( V_31 , L_1 , & V_16 ) ;
V_15 = F_52 ( V_1 , V_16 , V_26 ,
V_27 ) ;
if ( F_14 ( V_15 ) )
return;
F_22 ( V_31 , V_32 , V_15 ) ;
}
