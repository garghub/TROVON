static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_4 )
return F_2 ( V_2 -> V_5 + V_3 ) ;
else
return F_2 ( V_2 -> V_6 + ( V_3 - V_4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_7 )
{
if ( V_3 < V_4 )
F_4 ( V_7 , V_2 -> V_5 + V_3 ) ;
else
F_4 ( V_7 , V_2 -> V_6 + ( V_3 - V_4 ) ) ;
}
static inline struct V_1 * F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
return F_7 ( V_11 , struct V_1 , V_10 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_3 ( V_2 , V_12 , F_9 ( F_10 ( V_9 ) ) ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_3 ( V_2 , V_13 , F_9 ( F_10 ( V_9 ) ) ) ;
}
static int F_12 ( struct V_8 * V_9 , unsigned int type )
{
unsigned char V_7 = V_14 [ type & V_15 ] ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_16 , V_17 , V_18 ;
unsigned long V_19 ;
unsigned long V_20 ;
if ( ! V_7 )
return - V_21 ;
V_17 = F_10 ( V_9 ) ;
F_13 ( L_1 , V_17 , V_7 ) ;
V_16 = F_14 ( V_17 >> 3 ) ;
V_18 = ( V_17 & 0x07 ) << 4 ;
F_15 ( & V_2 -> V_22 , V_19 ) ;
V_20 = F_1 ( V_2 , V_23 ) ;
V_20 &= ~ F_9 ( V_17 ) ;
F_3 ( V_2 , V_23 , V_20 ) ;
V_20 = F_1 ( V_2 , V_16 ) ;
V_20 &= ~ ( 0xf << V_18 ) ;
V_20 |= V_7 << V_18 ;
F_3 ( V_2 , V_16 , V_20 ) ;
F_3 ( V_2 , V_24 , F_9 ( V_17 ) ) ;
V_20 = F_1 ( V_2 , V_23 ) ;
V_20 |= F_9 ( V_17 ) ;
F_3 ( V_2 , V_23 , V_20 ) ;
F_16 ( & V_2 -> V_22 , V_19 ) ;
return 0 ;
}
static T_1 F_17 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
unsigned long V_27 ;
unsigned int V_17 , V_28 = 0 ;
while ( ( V_27 = F_1 ( V_2 , V_29 ) ) ) {
V_17 = F_18 ( V_27 ) ;
F_3 ( V_2 , V_24 , F_9 ( V_17 ) ) ;
F_19 ( F_20 ( V_2 -> V_30 , V_17 ) ) ;
V_28 ++ ;
}
return V_28 ? V_31 : V_32 ;
}
static inline struct V_1 * F_21 ( struct V_33 * V_11 )
{
return F_7 ( V_11 , struct V_1 , V_33 ) ;
}
static int F_22 ( struct V_33 * V_11 , unsigned V_17 )
{
F_3 ( F_21 ( V_11 ) , V_34 , F_9 ( V_17 ) ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_11 , unsigned V_17 )
{
return ( int ) ( F_1 ( F_21 ( V_11 ) , V_35 ) & F_9 ( V_17 ) ) ;
}
static void F_24 ( struct V_33 * V_11 , unsigned int V_16 ,
unsigned V_18 , int V_7 )
{
F_3 ( F_21 ( V_11 ) , V_16 ,
( 1 << ( V_18 + 16 ) ) | ( V_7 << V_18 ) ) ;
}
static void F_25 ( struct V_33 * V_11 , unsigned V_17 , int V_7 )
{
if ( V_17 < 16 )
F_24 ( V_11 , V_36 , V_17 , V_7 ) ;
else
F_24 ( V_11 , V_37 , V_17 - 16 , V_7 ) ;
}
static int F_26 ( struct V_33 * V_11 , unsigned V_17 ,
int V_7 )
{
F_25 ( V_11 , V_17 , V_7 ) ;
F_3 ( F_21 ( V_11 ) , V_38 , F_9 ( V_17 ) ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_11 , unsigned V_17 )
{
return F_20 ( F_21 ( V_11 ) -> V_30 , V_17 ) ;
}
static int F_28 ( struct V_30 * V_39 , unsigned int V_40 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_39 -> V_42 ;
F_13 ( L_2 , ( int ) V_41 , V_40 ) ;
F_29 ( V_40 , V_39 -> V_42 ) ;
F_30 ( V_40 , & V_2 -> V_10 , V_43 ) ;
F_31 ( V_40 , V_44 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_47 * V_48 = V_46 -> V_49 . V_50 ;
V_2 -> V_51 = F_33 ( V_48 -> V_51 , 0 ,
V_48 -> V_52 , F_34 () ) ;
if ( F_35 ( V_2 -> V_51 ) ) {
F_36 ( & V_46 -> V_49 , L_3 ) ;
return - V_53 ;
}
F_13 ( L_4 ,
V_48 -> V_54 , V_48 -> V_52 , V_2 -> V_51 ) ;
V_2 -> V_30 = F_37 ( V_46 -> V_49 . V_55 ,
V_48 -> V_52 ,
V_2 -> V_51 , 0 ,
& V_56 , V_2 ) ;
if ( ! V_2 -> V_30 ) {
F_38 ( V_2 -> V_51 , V_48 -> V_52 ) ;
return - V_53 ;
}
return 0 ;
}
static void T_4 F_39 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = V_2 -> V_46 -> V_49 . V_50 ;
F_38 ( V_2 -> V_51 , V_48 -> V_52 ) ;
}
static int T_3 F_40 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = V_46 -> V_49 . V_50 ;
struct V_1 * V_2 ;
struct V_57 * V_58 [ 2 ] , * V_25 [ 2 ] ;
struct V_33 * V_33 ;
struct V_10 * V_10 ;
const char * V_59 = F_41 ( & V_46 -> V_49 ) ;
int V_60 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 ) {
F_36 ( & V_46 -> V_49 , L_5 ) ;
V_60 = - V_62 ;
goto V_63;
}
V_2 -> V_46 = V_46 ;
F_43 ( V_46 , V_2 ) ;
F_44 ( & V_2 -> V_22 ) ;
V_58 [ 0 ] = F_45 ( V_46 , V_64 , 0 ) ;
V_58 [ 1 ] = F_45 ( V_46 , V_64 , 1 ) ;
V_25 [ 0 ] = F_45 ( V_46 , V_65 , 0 ) ;
V_25 [ 1 ] = F_45 ( V_46 , V_65 , 1 ) ;
if ( ! V_58 [ 0 ] || ! V_58 [ 1 ] || ! V_25 [ 0 ] || ! V_25 [ 1 ] || ! V_48 ) {
F_36 ( & V_46 -> V_49 , L_6 ) ;
V_60 = - V_21 ;
goto V_66;
}
V_2 -> V_5 = F_46 ( V_58 [ 0 ] -> V_67 , F_47 ( V_58 [ 0 ] ) ) ;
if ( ! V_2 -> V_5 ) {
F_36 ( & V_46 -> V_49 , L_7 ) ;
V_60 = - V_53 ;
goto V_66;
}
V_2 -> V_6 = F_46 ( V_58 [ 1 ] -> V_67 , F_47 ( V_58 [ 1 ] ) ) ;
if ( ! V_2 -> V_6 ) {
F_36 ( & V_46 -> V_49 , L_8 ) ;
V_60 = - V_53 ;
goto V_68;
}
V_33 = & V_2 -> V_33 ;
V_33 -> V_69 = F_22 ;
V_33 -> V_70 = F_23 ;
V_33 -> V_71 = F_26 ;
V_33 -> V_72 = F_25 ;
V_33 -> V_73 = F_27 ;
V_33 -> V_74 = V_59 ;
V_33 -> V_75 = V_76 ;
V_33 -> V_77 = V_48 -> V_54 ;
V_33 -> V_78 = V_48 -> V_52 ;
V_10 = & V_2 -> V_10 ;
V_10 -> V_59 = V_59 ;
V_10 -> V_79 = F_8 ;
V_10 -> V_80 = F_11 ;
V_10 -> V_81 = F_11 ;
V_10 -> V_82 = F_8 ;
V_10 -> V_83 = F_12 ;
V_10 -> V_19 = V_84 ;
V_60 = F_32 ( V_2 ) ;
if ( V_60 ) {
F_36 ( & V_46 -> V_49 , L_9 ) ;
goto V_85;
}
if ( F_48 ( V_25 [ 0 ] -> V_67 , F_17 , 0 , V_59 , V_2 ) ) {
F_36 ( & V_46 -> V_49 , L_10 ) ;
V_60 = - V_86 ;
goto V_87;
}
if ( F_48 ( V_25 [ 1 ] -> V_67 , F_17 , 0 , V_59 , V_2 ) ) {
F_36 ( & V_46 -> V_49 , L_11 ) ;
V_60 = - V_86 ;
goto V_88;
}
V_60 = F_49 ( V_33 ) ;
if ( V_60 ) {
F_36 ( & V_46 -> V_49 , L_12 ) ;
goto V_89;
}
return 0 ;
V_89:
F_50 ( V_25 [ 1 ] -> V_67 , V_46 ) ;
V_88:
F_50 ( V_25 [ 0 ] -> V_67 , V_46 ) ;
V_87:
F_39 ( V_2 ) ;
V_85:
F_51 ( V_2 -> V_6 ) ;
V_68:
F_51 ( V_2 -> V_5 ) ;
V_66:
F_52 ( V_2 ) ;
V_63:
return V_60 ;
}
static int T_4 F_53 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_54 ( V_46 ) ;
struct V_57 * V_25 [ 2 ] ;
int V_60 ;
V_60 = F_55 ( & V_2 -> V_33 ) ;
if ( V_60 )
return V_60 ;
V_25 [ 0 ] = F_45 ( V_46 , V_65 , 0 ) ;
V_25 [ 1 ] = F_45 ( V_46 , V_65 , 1 ) ;
F_50 ( V_25 [ 1 ] -> V_67 , V_46 ) ;
F_50 ( V_25 [ 0 ] -> V_67 , V_46 ) ;
F_39 ( V_2 ) ;
F_51 ( V_2 -> V_6 ) ;
F_51 ( V_2 -> V_5 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
