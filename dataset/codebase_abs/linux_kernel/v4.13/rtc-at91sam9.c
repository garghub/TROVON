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
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
F_17 ( V_34 , L_7 ,
( V_23 & V_26 ) ? L_8 : L_9 ) ;
return 0 ;
}
static T_2 F_18 ( struct V_1 * V_2 )
{
T_1 V_35 , V_23 ;
V_23 = F_7 ( V_2 , V_24 ) & ( V_25 | V_26 ) ;
V_35 = F_7 ( V_2 , V_36 ) & ( V_23 >> 16 ) ;
if ( ! V_35 )
return V_37 ;
if ( V_35 & V_38 )
V_2 -> V_39 |= ( V_40 | V_41 ) ;
if ( V_35 & V_42 )
V_2 -> V_39 |= ( V_43 | V_41 ) ;
return V_44 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_39 )
return;
F_20 ( V_2 -> V_45 , 1 , V_2 -> V_39 ) ;
V_2 -> V_39 = 0 ;
F_21 ( L_10 , V_46 ,
V_2 -> V_39 >> 8 , V_2 -> V_39 & 0x000000FF ) ;
}
static T_2 F_22 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
int V_49 ;
F_23 ( & V_2 -> V_50 ) ;
V_49 = F_18 ( V_2 ) ;
if ( V_2 -> V_51 ) {
F_12 ( V_2 , V_24 ,
F_7 ( V_2 , V_24 ) &
~ ( V_25 | V_26 ) ) ;
F_24 () ;
} else {
F_19 ( V_2 ) ;
}
F_25 ( & V_2 -> V_50 ) ;
return V_49 ;
}
static int F_26 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 ;
int V_49 , V_47 ;
T_1 V_23 ;
unsigned int V_56 ;
V_47 = F_27 ( V_53 , 0 ) ;
if ( V_47 < 0 ) {
F_28 ( & V_53 -> V_7 , L_11 ) ;
return V_47 ;
}
V_2 = F_29 ( & V_53 -> V_7 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
F_30 ( & V_2 -> V_50 ) ;
V_2 -> V_47 = V_47 ;
if ( ! F_31 ( & V_53 -> V_7 ) )
F_32 ( & V_53 -> V_7 , 1 ) ;
F_33 ( V_53 , V_2 ) ;
V_55 = F_34 ( V_53 , V_59 , 0 ) ;
V_2 -> V_60 = F_35 ( & V_53 -> V_7 , V_55 ) ;
if ( F_36 ( V_2 -> V_60 ) )
return F_37 ( V_2 -> V_60 ) ;
if ( ! V_53 -> V_7 . V_61 ) {
void T_3 * V_4 ;
V_55 = F_34 ( V_53 , V_59 , 1 ) ;
V_4 = F_35 ( & V_53 -> V_7 , V_55 ) ;
if ( F_36 ( V_4 ) )
return F_37 ( V_4 ) ;
V_2 -> V_4 = F_38 ( NULL , V_4 ,
& V_62 ) ;
} else {
struct V_63 args ;
V_49 = F_39 ( V_53 -> V_7 . V_61 ,
L_12 , 1 , 0 ,
& args ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_4 = F_40 ( args . V_64 ) ;
V_2 -> V_5 = args . args [ 0 ] ;
}
if ( F_36 ( V_2 -> V_4 ) ) {
F_28 ( & V_53 -> V_7 , L_13 ) ;
return - V_58 ;
}
V_2 -> V_65 = F_41 ( & V_53 -> V_7 , NULL ) ;
if ( F_36 ( V_2 -> V_65 ) )
return F_37 ( V_2 -> V_65 ) ;
V_49 = F_42 ( V_2 -> V_65 ) ;
if ( V_49 ) {
F_28 ( & V_53 -> V_7 , L_14 ) ;
return V_49 ;
}
V_56 = F_43 ( V_2 -> V_65 ) ;
if ( ! V_56 || V_56 > V_66 ) {
F_28 ( & V_53 -> V_7 , L_15 ) ;
V_49 = - V_67 ;
goto V_68;
}
V_23 = F_7 ( V_2 , V_24 ) ;
if ( ( V_23 & V_66 ) != V_56 ) {
V_23 = V_29 | ( V_56 & V_66 ) ;
F_3 ( V_2 , 0 ) ;
}
V_23 &= ~ ( V_25 | V_26 ) ;
F_12 ( V_2 , V_24 , V_23 ) ;
V_2 -> V_45 = F_44 ( & V_53 -> V_7 , V_53 -> V_69 ,
& V_70 , V_71 ) ;
if ( F_36 ( V_2 -> V_45 ) ) {
V_49 = F_37 ( V_2 -> V_45 ) ;
goto V_68;
}
V_49 = F_45 ( & V_53 -> V_7 , V_2 -> V_47 , F_22 ,
V_72 | V_73 ,
F_46 ( & V_2 -> V_45 -> V_7 ) , V_2 ) ;
if ( V_49 ) {
F_9 ( & V_53 -> V_7 , L_16 , V_2 -> V_47 ) ;
goto V_68;
}
if ( F_1 ( V_2 ) == 0 )
F_47 ( & V_53 -> V_7 , L_17 ,
F_46 ( & V_2 -> V_45 -> V_7 ) ) ;
return 0 ;
V_68:
F_48 ( V_2 -> V_65 ) ;
return V_49 ;
}
static int F_49 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_50 ( V_53 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
F_12 ( V_2 , V_24 , V_23 & ~ ( V_25 | V_26 ) ) ;
F_48 ( V_2 -> V_65 ) ;
return 0 ;
}
static void F_51 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_50 ( V_53 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
V_2 -> V_74 = V_23 & ( V_25 | V_26 ) ;
F_12 ( V_2 , V_24 , V_23 & ~ V_2 -> V_74 ) ;
}
static int F_52 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_23 = F_7 ( V_2 , V_24 ) ;
V_2 -> V_74 = V_23 & ( V_25 | V_26 ) ;
if ( V_2 -> V_74 ) {
if ( F_53 ( V_7 ) && ( V_23 & V_25 ) ) {
unsigned long V_75 ;
F_54 ( V_2 -> V_47 ) ;
F_55 ( & V_2 -> V_50 , V_75 ) ;
V_2 -> V_51 = true ;
F_56 ( & V_2 -> V_50 , V_75 ) ;
if ( V_23 & V_26 )
F_12 ( V_2 , V_24 , V_23 & ~ V_26 ) ;
} else
F_12 ( V_2 , V_24 , V_23 & ~ V_2 -> V_74 ) ;
}
return 0 ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_23 ;
if ( V_2 -> V_74 ) {
unsigned long V_75 ;
if ( F_53 ( V_7 ) )
F_58 ( V_2 -> V_47 ) ;
V_23 = F_7 ( V_2 , V_24 ) ;
F_12 ( V_2 , V_24 , V_23 | V_2 -> V_74 ) ;
F_55 ( & V_2 -> V_50 , V_75 ) ;
V_2 -> V_51 = false ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_56 ( & V_2 -> V_50 , V_75 ) ;
}
return 0 ;
}
