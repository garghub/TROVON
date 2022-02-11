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
static void F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_3 ( V_2 , V_10 , F_7 ( F_8 ( V_9 ) ) ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_3 ( V_2 , V_11 , F_7 ( F_8 ( V_9 ) ) ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int type )
{
unsigned char V_7 = V_12 [ type & V_13 ] ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_14 , V_15 , V_16 ;
unsigned long V_17 ;
unsigned long V_18 ;
if ( ! V_7 )
return - V_19 ;
V_15 = F_8 ( V_9 ) ;
F_11 ( L_1 , V_15 , V_7 ) ;
V_14 = F_12 ( V_15 >> 3 ) ;
V_16 = ( V_15 & 0x07 ) << 4 ;
F_13 ( & V_2 -> V_20 , V_17 ) ;
V_18 = F_1 ( V_2 , V_21 ) ;
V_18 &= ~ F_7 ( V_15 ) ;
F_3 ( V_2 , V_21 , V_18 ) ;
V_18 = F_1 ( V_2 , V_14 ) ;
V_18 &= ~ ( 0xf << V_16 ) ;
V_18 |= V_7 << V_16 ;
F_3 ( V_2 , V_14 , V_18 ) ;
F_3 ( V_2 , V_22 , F_7 ( V_15 ) ) ;
V_18 = F_1 ( V_2 , V_21 ) ;
V_18 |= F_7 ( V_15 ) ;
F_3 ( V_2 , V_21 , V_18 ) ;
F_14 ( & V_2 -> V_20 , V_17 ) ;
return 0 ;
}
static T_1 F_15 ( int V_23 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
unsigned long V_25 ;
unsigned int V_15 , V_26 = 0 ;
while ( ( V_25 = F_1 ( V_2 , V_27 ) ) ) {
V_15 = F_16 ( V_25 ) ;
F_3 ( V_2 , V_22 , F_7 ( V_15 ) ) ;
F_17 ( F_18 ( V_2 -> V_28 , V_15 ) ) ;
V_26 ++ ;
}
return V_26 ? V_29 : V_30 ;
}
static inline struct V_1 * F_19 ( struct V_31 * V_32 )
{
return F_20 ( V_32 , struct V_1 , V_31 ) ;
}
static int F_21 ( struct V_31 * V_32 , unsigned V_15 )
{
F_3 ( F_19 ( V_32 ) , V_33 , F_7 ( V_15 ) ) ;
return 0 ;
}
static int F_22 ( struct V_31 * V_32 , unsigned V_15 )
{
return ( int ) ( F_1 ( F_19 ( V_32 ) , V_34 ) & F_7 ( V_15 ) ) ;
}
static void F_23 ( struct V_31 * V_32 , unsigned int V_14 ,
unsigned V_16 , int V_7 )
{
F_3 ( F_19 ( V_32 ) , V_14 ,
( 1 << ( V_16 + 16 ) ) | ( V_7 << V_16 ) ) ;
}
static void F_24 ( struct V_31 * V_32 , unsigned V_15 , int V_7 )
{
if ( V_15 < 16 )
F_23 ( V_32 , V_35 , V_15 , V_7 ) ;
else
F_23 ( V_32 , V_36 , V_15 - 16 , V_7 ) ;
}
static int F_25 ( struct V_31 * V_32 , unsigned V_15 ,
int V_7 )
{
F_24 ( V_32 , V_15 , V_7 ) ;
F_3 ( F_19 ( V_32 ) , V_37 , F_7 ( V_15 ) ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_32 , unsigned V_15 )
{
return F_27 ( F_19 ( V_32 ) -> V_28 , V_15 ) ;
}
static int F_28 ( struct V_28 * V_38 , unsigned int V_39 ,
T_2 V_40 )
{
struct V_1 * V_2 = V_38 -> V_41 ;
F_11 ( L_2 , ( int ) V_40 , V_39 ) ;
F_29 ( V_39 , V_38 -> V_41 ) ;
F_30 ( V_39 , & V_2 -> V_42 , V_43 ) ;
F_31 ( V_39 , V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = V_46 -> V_49 . V_50 ;
struct V_1 * V_2 ;
struct V_51 * V_52 [ 2 ] , * V_23 [ 2 ] ;
struct V_31 * V_31 ;
struct V_42 * V_42 ;
const char * V_53 = F_33 ( & V_46 -> V_49 ) ;
int V_54 ;
V_2 = F_34 ( sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 ) {
F_35 ( & V_46 -> V_49 , L_3 ) ;
V_54 = - V_56 ;
goto V_57;
}
V_2 -> V_46 = V_46 ;
F_36 ( V_46 , V_2 ) ;
F_37 ( & V_2 -> V_20 ) ;
V_52 [ 0 ] = F_38 ( V_46 , V_58 , 0 ) ;
V_52 [ 1 ] = F_38 ( V_46 , V_58 , 1 ) ;
V_23 [ 0 ] = F_38 ( V_46 , V_59 , 0 ) ;
V_23 [ 1 ] = F_38 ( V_46 , V_59 , 1 ) ;
if ( ! V_52 [ 0 ] || ! V_52 [ 1 ] || ! V_23 [ 0 ] || ! V_23 [ 1 ] || ! V_48 ) {
F_35 ( & V_46 -> V_49 , L_4 ) ;
V_54 = - V_19 ;
goto V_60;
}
V_2 -> V_5 = F_39 ( V_52 [ 0 ] -> V_61 , F_40 ( V_52 [ 0 ] ) ) ;
if ( ! V_2 -> V_5 ) {
F_35 ( & V_46 -> V_49 , L_5 ) ;
V_54 = - V_62 ;
goto V_60;
}
V_2 -> V_6 = F_39 ( V_52 [ 1 ] -> V_61 , F_40 ( V_52 [ 1 ] ) ) ;
if ( ! V_2 -> V_6 ) {
F_35 ( & V_46 -> V_49 , L_6 ) ;
V_54 = - V_62 ;
goto V_63;
}
V_31 = & V_2 -> V_31 ;
V_31 -> V_64 = F_21 ;
V_31 -> V_65 = F_22 ;
V_31 -> V_66 = F_25 ;
V_31 -> V_67 = F_24 ;
V_31 -> V_68 = F_26 ;
V_31 -> V_69 = V_53 ;
V_31 -> V_70 = V_71 ;
V_31 -> V_72 = V_48 -> V_73 ;
V_31 -> V_74 = V_48 -> V_75 ;
V_42 = & V_2 -> V_42 ;
V_42 -> V_53 = V_53 ;
V_42 -> V_76 = F_5 ;
V_42 -> V_77 = F_9 ;
V_42 -> V_78 = F_9 ;
V_42 -> V_79 = F_5 ;
V_42 -> V_80 = F_10 ;
V_42 -> V_17 = V_81 ;
V_2 -> V_28 = F_41 ( V_46 -> V_49 . V_82 ,
V_48 -> V_75 ,
& V_83 , V_2 ) ;
if ( ! V_2 -> V_28 ) {
V_54 = - V_62 ;
F_35 ( & V_46 -> V_49 , L_7 ) ;
goto V_84;
}
if ( F_42 ( V_23 [ 0 ] -> V_61 , F_15 , 0 , V_53 , V_2 ) ) {
F_35 ( & V_46 -> V_49 , L_8 ) ;
V_54 = - V_85 ;
goto V_86;
}
if ( F_42 ( V_23 [ 1 ] -> V_61 , F_15 , 0 , V_53 , V_2 ) ) {
F_35 ( & V_46 -> V_49 , L_9 ) ;
V_54 = - V_85 ;
goto V_87;
}
V_54 = F_43 ( V_31 ) ;
if ( V_54 ) {
F_35 ( & V_46 -> V_49 , L_10 ) ;
goto V_88;
}
return 0 ;
V_88:
F_44 ( V_23 [ 1 ] -> V_61 , V_46 ) ;
V_87:
F_44 ( V_23 [ 0 ] -> V_61 , V_46 ) ;
V_86:
F_45 ( V_2 -> V_28 ) ;
V_84:
F_46 ( V_2 -> V_6 ) ;
V_63:
F_46 ( V_2 -> V_5 ) ;
V_60:
F_47 ( V_2 ) ;
V_57:
return V_54 ;
}
static int F_48 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_49 ( V_46 ) ;
struct V_51 * V_23 [ 2 ] ;
int V_54 ;
V_54 = F_50 ( & V_2 -> V_31 ) ;
if ( V_54 )
return V_54 ;
V_23 [ 0 ] = F_38 ( V_46 , V_59 , 0 ) ;
V_23 [ 1 ] = F_38 ( V_46 , V_59 , 1 ) ;
F_44 ( V_23 [ 1 ] -> V_61 , V_46 ) ;
F_44 ( V_23 [ 0 ] -> V_61 , V_46 ) ;
F_45 ( V_2 -> V_28 ) ;
F_46 ( V_2 -> V_6 ) ;
F_46 ( V_2 -> V_5 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
