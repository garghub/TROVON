static inline unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_2 ( V_2 -> V_4 , V_2 -> V_5 , & V_3 ) ;
return V_3 ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_4 ( V_2 -> V_4 , V_2 -> V_5 , V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_10 , V_11 ;
T_1 V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 == 0 )
return - V_13 ;
V_10 = F_7 ( V_2 , V_14 ) ;
V_11 = F_7 ( V_2 , V_14 ) ;
if ( V_10 != V_11 )
V_10 = F_7 ( V_2 , V_14 ) ;
F_8 ( V_12 + V_10 , V_9 ) ;
F_9 ( V_7 , L_1 , L_2 ,
1900 + V_9 -> V_15 , V_9 -> V_16 , V_9 -> V_17 ,
V_9 -> V_18 , V_9 -> V_19 , V_9 -> V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_21 ;
T_1 V_12 , V_22 , V_23 ;
unsigned long V_10 ;
F_9 ( V_7 , L_1 , L_3 ,
1900 + V_9 -> V_15 , V_9 -> V_16 , V_9 -> V_17 ,
V_9 -> V_18 , V_9 -> V_19 , V_9 -> V_20 ) ;
V_21 = F_11 ( V_9 , & V_10 ) ;
if ( V_21 != 0 )
return V_21 ;
V_23 = F_7 ( V_2 , V_24 ) ;
F_12 ( V_2 , V_24 , V_23 & ~ ( V_25 | V_26 ) ) ;
V_12 = F_1 ( V_2 ) ;
V_10 += 1 ;
F_3 ( V_2 , V_10 ) ;
V_22 = F_7 ( V_2 , V_27 ) ;
if ( V_22 != V_28 ) {
if ( V_12 > V_10 ) {
V_22 += ( V_12 - V_10 ) ;
} else if ( ( V_22 + V_12 ) > V_10 ) {
V_22 -= ( V_10 - V_12 ) ;
} else {
V_22 = V_28 ;
V_23 &= ~ V_25 ;
}
F_12 ( V_2 , V_27 , V_22 ) ;
}
F_12 ( V_2 , V_24 , V_23 | V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_8 * V_9 = & V_31 -> time ;
T_1 V_22 = F_7 ( V_2 , V_27 ) ;
T_1 V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 == 0 )
return - V_13 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
if ( V_22 != V_28 && V_12 != 0 ) {
F_8 ( V_12 + V_22 , V_9 ) ;
F_9 ( V_7 , L_1 , L_4 ,
1900 + V_9 -> V_15 , V_9 -> V_16 , V_9 -> V_17 ,
V_9 -> V_18 , V_9 -> V_19 , V_9 -> V_20 ) ;
if ( F_7 ( V_2 , V_24 ) & V_25 )
V_31 -> V_32 = 1 ;
}
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_8 * V_9 = & V_31 -> time ;
unsigned long V_10 ;
T_1 V_12 ;
T_1 V_23 ;
int V_21 ;
V_21 = F_11 ( V_9 , & V_10 ) ;
if ( V_21 != 0 )
return V_21 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 == 0 ) {
return - V_13 ;
}
V_23 = F_7 ( V_2 , V_24 ) ;
F_12 ( V_2 , V_24 , V_23 & ~ V_25 ) ;
if ( V_10 <= V_12 ) {
F_12 ( V_2 , V_27 , V_28 ) ;
return 0 ;
}
F_12 ( V_2 , V_27 , V_10 - V_12 ) ;
if ( V_31 -> V_32 )
F_12 ( V_2 , V_24 , V_23 | V_25 ) ;
F_9 ( V_7 , L_1 , L_5 ,
V_9 -> V_15 , V_9 -> V_16 , V_9 -> V_17 , V_9 -> V_18 ,
V_9 -> V_19 , V_9 -> V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , unsigned int V_32 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
F_9 ( V_7 , L_6 , V_32 , V_23 ) ;
if ( V_32 )
F_12 ( V_2 , V_24 , V_23 | V_25 ) ;
else
F_12 ( V_2 , V_24 , V_23 & ~ V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_23 = V_23 = F_7 ( V_2 , V_24 ) ;
F_17 ( V_34 , L_7 ,
( V_23 & V_26 ) ? L_8 : L_9 ) ;
return 0 ;
}
static T_2 F_18 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
T_1 V_37 , V_23 ;
unsigned long V_38 = 0 ;
V_23 = F_7 ( V_2 , V_24 ) & ( V_25 | V_26 ) ;
V_37 = F_7 ( V_2 , V_39 ) & ( V_23 >> 16 ) ;
if ( ! V_37 )
return V_40 ;
if ( V_37 & V_41 )
V_38 |= ( V_42 | V_43 ) ;
if ( V_37 & V_44 )
V_38 |= ( V_45 | V_43 ) ;
F_19 ( V_2 -> V_46 , 1 , V_38 ) ;
F_20 ( L_10 , V_47 ,
V_38 >> 8 , V_38 & 0x000000FF ) ;
return V_48 ;
}
static int F_21 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
int V_53 , V_35 ;
T_1 V_23 ;
unsigned int V_54 ;
V_35 = F_22 ( V_50 , 0 ) ;
if ( V_35 < 0 ) {
F_23 ( & V_50 -> V_7 , L_11 ) ;
return V_35 ;
}
V_2 = F_24 ( & V_50 -> V_7 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_35 = V_35 ;
if ( ! F_25 ( & V_50 -> V_7 ) )
F_26 ( & V_50 -> V_7 , 1 ) ;
F_27 ( V_50 , V_2 ) ;
V_52 = F_28 ( V_50 , V_57 , 0 ) ;
V_2 -> V_58 = F_29 ( & V_50 -> V_7 , V_52 ) ;
if ( F_30 ( V_2 -> V_58 ) )
return F_31 ( V_2 -> V_58 ) ;
if ( ! V_50 -> V_7 . V_59 ) {
void T_3 * V_4 ;
V_52 = F_28 ( V_50 , V_57 , 1 ) ;
V_4 = F_29 ( & V_50 -> V_7 , V_52 ) ;
if ( F_30 ( V_4 ) )
return F_31 ( V_4 ) ;
V_2 -> V_4 = F_32 ( NULL , V_4 ,
& V_60 ) ;
} else {
struct V_61 args ;
V_53 = F_33 ( V_50 -> V_7 . V_59 ,
L_12 , 1 , 0 ,
& args ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_4 = F_34 ( args . V_62 ) ;
V_2 -> V_5 = args . args [ 0 ] ;
}
if ( F_30 ( V_2 -> V_4 ) ) {
F_23 ( & V_50 -> V_7 , L_13 ) ;
return - V_56 ;
}
V_2 -> V_63 = F_35 ( & V_50 -> V_7 , NULL ) ;
if ( F_30 ( V_2 -> V_63 ) )
return F_31 ( V_2 -> V_63 ) ;
V_54 = F_36 ( V_2 -> V_63 ) ;
if ( ! V_54 || V_54 > V_64 ) {
F_23 ( & V_50 -> V_7 , L_14 ) ;
return - V_65 ;
}
V_53 = F_37 ( V_2 -> V_63 ) ;
if ( V_53 ) {
F_23 ( & V_50 -> V_7 , L_15 ) ;
return V_53 ;
}
V_23 = F_7 ( V_2 , V_24 ) ;
if ( ( V_23 & V_64 ) != V_54 ) {
V_23 = V_29 | ( V_54 & V_64 ) ;
F_3 ( V_2 , 0 ) ;
}
V_23 &= ~ ( V_25 | V_26 ) ;
F_12 ( V_2 , V_24 , V_23 ) ;
V_2 -> V_46 = F_38 ( & V_50 -> V_7 , V_50 -> V_66 ,
& V_67 , V_68 ) ;
if ( F_30 ( V_2 -> V_46 ) )
return F_31 ( V_2 -> V_46 ) ;
V_53 = F_39 ( & V_50 -> V_7 , V_2 -> V_35 , F_18 ,
V_69 , F_40 ( & V_2 -> V_46 -> V_7 ) , V_2 ) ;
if ( V_53 ) {
F_9 ( & V_50 -> V_7 , L_16 , V_2 -> V_35 ) ;
return V_53 ;
}
if ( F_1 ( V_2 ) == 0 )
F_41 ( & V_50 -> V_7 , L_17 ,
F_40 ( & V_2 -> V_46 -> V_7 ) ) ;
return 0 ;
}
static int F_42 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_43 ( V_50 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
F_12 ( V_2 , V_24 , V_23 & ~ ( V_25 | V_26 ) ) ;
if ( ! F_30 ( V_2 -> V_63 ) )
F_44 ( V_2 -> V_63 ) ;
return 0 ;
}
static void F_45 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_43 ( V_50 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
V_2 -> V_70 = V_23 & ( V_25 | V_26 ) ;
F_12 ( V_2 , V_24 , V_23 & ~ V_2 -> V_70 ) ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
V_2 -> V_70 = V_23 & ( V_25 | V_26 ) ;
if ( V_2 -> V_70 ) {
if ( F_47 ( V_7 ) && ( V_23 & V_25 ) ) {
F_48 ( V_2 -> V_35 ) ;
if ( V_23 & V_26 )
F_12 ( V_2 , V_24 , V_23 & ~ V_26 ) ;
} else
F_12 ( V_2 , V_24 , V_23 & ~ V_2 -> V_70 ) ;
}
return 0 ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_23 ;
if ( V_2 -> V_70 ) {
if ( F_47 ( V_7 ) )
F_50 ( V_2 -> V_35 ) ;
V_23 = F_7 ( V_2 , V_24 ) ;
F_12 ( V_2 , V_24 , V_23 | V_2 -> V_70 ) ;
}
return 0 ;
}
