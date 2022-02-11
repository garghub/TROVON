static inline void F_1 ( T_1 V_1 , struct V_2 * V_3 , int V_4 )
{
F_2 ( V_1 , V_3 -> V_5 + ( V_4 << V_3 -> V_6 ) ) ;
}
static inline T_1 F_3 ( struct V_2 * V_3 , int V_4 )
{
return F_4 ( V_3 -> V_5 + ( V_4 << V_3 -> V_6 ) ) ;
}
static inline void F_5 ( struct V_2 * V_3 )
{
F_1 ( V_3 -> V_7 , V_3 , V_3 -> V_8 ) ;
F_6 ( L_1 ,
V_3 -> V_7 , V_3 -> V_8 << V_3 -> V_6 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
}
static void F_8 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_9 ( V_10 ) ;
V_3 -> V_11 &= ~ ( 1 << ( V_10 -> V_12 - V_3 -> V_13 ) ) ;
F_6 ( L_2 , V_10 -> V_12 , V_3 -> V_11 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_9 ( V_10 ) ;
V_3 -> V_11 |= 1 << ( V_10 -> V_12 - V_3 -> V_13 ) ;
F_6 ( L_3 , V_10 -> V_12 , V_3 -> V_11 ) ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_12 ( V_15 ) ;
int V_16 ;
unsigned long V_17 = F_3 ( V_3 , V_3 -> V_8 ) ;
F_6 ( L_4 , ( unsigned int ) V_17 ) ;
F_5 ( V_3 ) ;
V_17 &= V_3 -> V_11 ;
F_13 (irqpin, &readval, ei->nirqs) {
F_6 ( L_5 , V_16 ) ;
F_14 ( V_3 -> V_13 + V_16 ) ;
}
}
int F_15 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_16 ( V_19 ) ;
T_1 V_17 = F_3 ( V_3 , V_3 -> V_8 ) ;
F_5 ( V_3 ) ;
V_17 &= V_3 -> V_11 ;
return V_3 -> V_13 + F_17 ( V_17 ) - 1 ;
}
static inline int F_18 ( struct V_2 * V_3 , int V_20 )
{
return V_20 >> V_3 -> V_21 ;
}
static inline int F_19 ( struct V_2 * V_3 , int V_20 )
{
return 1 << ( V_20 & ( ( 1 << V_3 -> V_21 ) - 1 ) ) ;
}
static int F_20 ( struct V_22 * V_23 , unsigned V_24 )
{
struct V_25 * V_26 ;
struct V_2 * V_3 ;
unsigned V_20 ;
int V_4 ;
int V_1 ;
F_6 ( L_6 , V_23 -> V_27 + V_24 ) ;
V_26 = F_21 ( V_23 ) ;
V_3 = F_16 ( V_26 -> V_19 ) ;
V_20 = F_19 ( V_3 , V_24 ) ;
V_4 = V_26 -> V_28 + F_18 ( V_3 , V_24 ) ;
V_1 = F_3 ( V_3 , V_4 ) ;
F_6 ( L_7 ,
V_3 -> V_5 , V_4 << V_3 -> V_6 , V_1 ) ;
return ! ! ( V_1 & V_20 ) ;
}
static int F_22 ( struct V_22 * V_23 , unsigned V_24 )
{
struct V_25 * V_26 ;
V_26 = F_21 ( V_23 ) ;
return F_23 ( V_24 , & V_26 -> V_29 ) ? - V_30 : 0 ;
}
static void F_24 ( struct V_22 * V_23 , unsigned V_24 , int V_1 )
{
unsigned long V_31 ;
struct V_25 * V_26 ;
struct V_2 * V_3 ;
unsigned V_20 ;
int V_32 ;
int V_4 ;
int V_33 ;
F_6 ( L_8 ,
V_23 -> V_34 , V_24 , V_24 + V_23 -> V_27 , V_1 ) ;
V_26 = F_21 ( V_23 ) ;
V_3 = F_16 ( V_26 -> V_19 ) ;
V_20 = F_19 ( V_3 , V_24 ) ;
V_32 = F_18 ( V_3 , V_24 ) ;
V_4 = V_26 -> V_28 + V_32 ;
V_33 = V_32 << V_3 -> V_21 ;
F_6 ( L_9 , V_1 ? L_10 : L_11 ,
V_4 , ( V_26 -> V_35 >> V_33 ) & V_3 -> V_36 ) ;
F_25 ( & V_3 -> V_37 , V_31 ) ;
if ( V_1 )
V_26 -> V_35 |= ( 1 << V_24 ) ;
else
V_26 -> V_35 &= ~ ( 1 << V_24 ) ;
F_1 ( ( V_26 -> V_35 >> V_33 ) & V_3 -> V_36 , V_3 , V_4 ) ;
F_26 ( & V_3 -> V_37 , V_31 ) ;
}
static int F_27 ( struct V_22 * V_23 ,
unsigned V_24 , int V_1 )
{
struct V_25 * V_26 ;
V_26 = F_21 ( V_23 ) ;
if ( F_23 ( V_24 , & V_26 -> V_29 ) ) {
F_24 ( V_23 , V_24 , V_1 ) ;
return 0 ;
} else {
return - V_30 ;
}
}
static void F_28 ( struct V_2 * V_3 )
{
int V_38 ;
struct V_25 * V_26 ;
int V_33 ;
for ( V_38 = 0 ; V_38 < V_3 -> V_39 ; V_38 ++ ) {
V_26 = & ( V_3 -> V_23 [ V_38 ] ) ;
if ( ! V_26 -> V_29 )
continue;
for ( V_33 = 0 ; V_33 < V_26 -> V_23 . V_40 ;
V_33 += ( 1 << V_3 -> V_21 ) ) {
int V_4 = V_26 -> V_28 + F_18 ( V_3 , V_33 ) ;
if ( ! ( ( V_26 -> V_29 >> V_33 ) & V_3 -> V_36 ) )
continue;
F_6 ( L_12 , V_4 ,
( V_26 -> V_35 >> V_33 ) & V_3 -> V_36 ,
F_3 ( V_3 , V_4 ) ) ;
F_1 ( ( V_26 -> V_35 >> V_33 )
& V_3 -> V_36 , V_3 , V_4 ) ;
}
}
}
static int T_2 F_29 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_30 ( & V_42 -> V_19 ) ;
struct V_45 * V_46 ;
struct V_2 * V_3 ;
struct V_22 * V_23 ;
unsigned int V_12 , V_47 ;
int V_38 ;
int V_48 ;
V_3 = F_31 ( & V_42 -> V_19 , sizeof( * V_3 ) , V_49 ) ;
if ( ! V_3 )
return - V_50 ;
F_32 ( & V_3 -> V_37 ) ;
V_48 = - V_30 ;
V_46 = F_33 ( V_42 , V_51 , 0 ) ;
if ( V_46 )
V_3 -> V_52 = V_46 -> V_53 ;
V_46 = F_33 ( V_42 , V_54 , 0 ) ;
if ( ! V_46 )
goto V_55;
V_3 -> V_5 = F_34 ( & V_42 -> V_19 , V_46 -> V_53 ,
F_35 ( V_46 ) ) ;
if ( ! V_3 -> V_5 )
goto V_55;
F_6 ( L_13 , ( V_56 ) V_46 -> V_53 , V_3 -> V_5 ) ;
if ( ( V_44 -> V_57 != 16 ) && ( V_44 -> V_57 != 32 ) )
goto V_55;
V_3 -> V_6 = F_36 ( V_44 -> V_57 - 1 ) - 3 ;
F_6 ( L_14 , V_3 -> V_6 ) ;
if ( ( V_44 -> V_58 != 8 ) && ( V_44 -> V_58 != 16 ) )
goto V_55;
V_3 -> V_21 = F_36 ( V_44 -> V_58 - 1 ) ;
F_6 ( L_15 , V_3 -> V_21 ) ;
V_3 -> V_36 = ( 1 << V_44 -> V_58 ) - 1 ;
F_37 ( V_42 , V_3 ) ;
V_3 -> V_39 = V_44 -> V_59 ;
V_3 -> V_23 = F_31 ( & V_42 -> V_19 ,
sizeof( struct V_25 ) * V_3 -> V_39 ,
V_49 ) ;
if ( ! V_3 -> V_23 ) {
V_48 = - V_50 ;
goto V_55;
}
for ( V_38 = 0 ; V_38 < V_3 -> V_39 ; V_38 ++ ) {
V_3 -> V_23 [ V_38 ] . V_28 = V_44 -> V_23 [ V_38 ] . V_28 ;
V_3 -> V_23 [ V_38 ] . V_35 = V_44 -> V_23 [ V_38 ] . V_60 ;
V_3 -> V_23 [ V_38 ] . V_29 = V_44 -> V_23 [ V_38 ] . V_61 ;
V_3 -> V_23 [ V_38 ] . V_19 = & ( V_42 -> V_19 ) ;
V_23 = & ( V_3 -> V_23 [ V_38 ] . V_23 ) ;
V_23 -> V_34 = L_16 ;
V_23 -> V_62 = & V_42 -> V_19 ;
V_23 -> V_63 = V_64 ;
V_23 -> V_65 = F_20 ;
V_23 -> V_66 = F_24 ;
V_23 -> V_67 = F_22 ;
V_23 -> V_68 = F_27 ;
V_23 -> V_27 = V_44 -> V_23 [ V_38 ] . V_69 ;
V_23 -> V_40 = V_44 -> V_23 [ V_38 ] . V_70 ;
F_38 ( V_23 , & V_3 -> V_23 [ V_38 ] ) ;
}
F_28 ( V_3 ) ;
V_3 -> V_13 = V_44 -> V_71 ;
V_3 -> V_72 = V_44 -> V_73 ;
V_3 -> V_8 = V_44 -> V_8 ;
if ( V_3 -> V_52 ) {
V_3 -> V_7 = 0xFFFF ;
if ( V_44 -> V_74 )
V_3 -> V_7 = 0 ;
V_47 = V_3 -> V_13 + V_3 -> V_72 ;
for ( V_12 = V_3 -> V_13 ; V_12 < V_47 ; V_12 ++ ) {
F_39 ( V_12 , & V_75 ,
V_76 ) ;
F_40 ( V_12 , V_3 ) ;
F_41 ( V_12 , V_77 | V_78 ) ;
}
F_42 ( V_3 -> V_52 , V_79 ) ;
F_43 ( V_3 -> V_52 ,
F_11 , V_3 ) ;
F_5 ( V_3 ) ;
F_44 ( & V_42 -> V_19 , 1 ) ;
}
return 0 ;
V_55:
F_45 ( V_80 L_17 ) ;
return V_48 ;
}
static int T_3 F_46 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_47 ( V_42 ) ;
unsigned int V_12 , V_47 ;
if ( V_3 -> V_52 ) {
V_47 = V_3 -> V_13 + V_3 -> V_72 ;
for ( V_12 = V_3 -> V_13 ; V_12 < V_47 ; V_12 ++ ) {
F_39 ( V_12 , NULL , NULL ) ;
F_48 ( V_12 , V_77 | V_78 ) ;
}
F_49 ( V_3 -> V_52 , NULL ) ;
F_44 ( & V_42 -> V_19 , 0 ) ;
}
return 0 ;
}
static int F_50 ( struct V_41 * V_42 , T_4 V_81 )
{
struct V_2 * V_3 = F_47 ( V_42 ) ;
if ( V_3 -> V_52 && F_51 ( & V_42 -> V_19 ) )
F_52 ( V_3 -> V_52 ) ;
return 0 ;
}
static int F_53 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_47 ( V_42 ) ;
if ( V_3 -> V_52 && F_51 ( & V_42 -> V_19 ) )
F_54 ( V_3 -> V_52 ) ;
F_28 ( V_3 ) ;
return 0 ;
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_82 , F_29 ) ;
}
static void T_3 F_57 ( void )
{
F_58 ( & V_82 ) ;
}
