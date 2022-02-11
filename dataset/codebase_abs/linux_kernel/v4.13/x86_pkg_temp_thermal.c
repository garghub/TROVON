static int F_1 ( void )
{
struct V_1 * V_2 ;
V_3 = F_2 ( L_1 , NULL ) ;
if ( ! V_3 )
return - V_4 ;
V_2 = F_3 ( L_2 , V_5 , V_3 ,
( V_6 * ) & V_7 ) ;
if ( ! V_2 )
goto V_8;
V_2 = F_3 ( L_3 , V_5 , V_3 ,
( V_6 * ) & V_9 ) ;
if ( ! V_2 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_3 ) ;
return - V_4 ;
}
static struct V_10 * F_5 ( unsigned int V_11 )
{
int V_12 = F_6 ( V_11 ) ;
if ( V_12 >= 0 && V_12 < V_13 )
return V_14 [ V_12 ] ;
return NULL ;
}
static int F_7 ( int V_11 , V_6 * V_15 )
{
V_6 V_16 , V_17 , V_18 ;
int V_19 ;
V_19 = F_8 ( V_11 , V_20 , & V_16 , & V_17 ) ;
if ( V_19 )
return V_19 ;
V_18 = ( V_16 >> 16 ) & 0xff ;
* V_15 = V_18 * 1000 ;
return V_18 ? 0 : - V_21 ;
}
static int F_9 ( struct V_22 * V_23 , int * V_24 )
{
struct V_10 * V_25 = V_23 -> V_26 ;
V_6 V_16 , V_17 ;
F_10 ( V_25 -> V_11 , V_27 , & V_16 , & V_17 ) ;
if ( V_16 & 0x80000000 ) {
* V_24 = V_25 -> V_15 - ( ( V_16 >> 16 ) & 0x7f ) * 1000 ;
F_11 ( L_4 , * V_24 ) ;
return 0 ;
}
return - V_21 ;
}
static int F_12 ( struct V_22 * V_23 ,
int V_28 , int * V_24 )
{
struct V_10 * V_25 = V_23 -> V_26 ;
unsigned long V_29 ;
V_6 V_30 , V_31 , V_16 , V_17 ;
int V_32 ;
if ( V_28 >= V_33 )
return - V_21 ;
if ( V_28 ) {
V_30 = V_34 ;
V_31 = V_35 ;
} else {
V_30 = V_36 ;
V_31 = V_37 ;
}
V_32 = F_10 ( V_25 -> V_11 , V_38 ,
& V_16 , & V_17 ) ;
if ( V_32 < 0 )
return V_32 ;
V_29 = ( V_16 & V_30 ) >> V_31 ;
if ( V_29 )
* V_24 = V_25 -> V_15 - V_29 * 1000 ;
else
* V_24 = 0 ;
F_11 ( L_5 , * V_24 ) ;
return 0 ;
}
static int
F_13 ( struct V_22 * V_23 , int V_28 , int V_24 )
{
struct V_10 * V_25 = V_23 -> V_26 ;
V_6 V_39 , V_40 , V_30 , V_31 , V_41 ;
int V_32 ;
if ( V_28 >= V_33 || V_24 >= V_25 -> V_15 )
return - V_21 ;
V_32 = F_10 ( V_25 -> V_11 , V_38 ,
& V_39 , & V_40 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_28 ) {
V_30 = V_34 ;
V_31 = V_35 ;
V_41 = V_42 ;
} else {
V_30 = V_36 ;
V_31 = V_37 ;
V_41 = V_43 ;
}
V_39 &= ~ V_30 ;
if ( ! V_24 ) {
V_39 &= ~ V_41 ;
} else {
V_39 |= ( V_25 -> V_15 - V_24 ) / 1000 << V_31 ;
V_39 |= V_41 ;
}
return F_14 ( V_25 -> V_11 , V_38 , V_39 , V_40 ) ;
}
static int F_15 ( struct V_22 * V_44 , int V_28 ,
enum V_45 * type )
{
* type = V_46 ;
return 0 ;
}
static bool F_16 ( void )
{
return true ;
}
static inline void F_17 ( void )
{
T_1 V_47 , V_48 ;
V_6 V_39 , V_40 ;
F_18 ( V_38 , V_39 , V_40 ) ;
V_47 = ( V_39 & V_36 ) >> V_37 ;
V_48 = ( V_39 & V_34 ) >> V_35 ;
if ( V_47 )
V_39 |= V_43 ;
if ( V_48 )
V_39 |= V_42 ;
F_19 ( V_38 , V_39 , V_40 ) ;
}
static inline void F_20 ( void )
{
V_6 V_39 , V_40 ;
F_18 ( V_38 , V_39 , V_40 ) ;
V_39 &= ~ ( V_43 | V_42 ) ;
F_19 ( V_38 , V_39 , V_40 ) ;
}
static void F_21 ( struct V_49 * V_50 )
{
struct V_22 * V_51 = NULL ;
int V_11 = F_22 () ;
struct V_10 * V_25 ;
T_2 V_52 , V_53 ;
F_23 ( & V_54 ) ;
F_24 ( & V_55 ) ;
++ V_9 ;
V_25 = F_5 ( V_11 ) ;
if ( ! V_25 ) {
F_25 ( & V_55 ) ;
F_26 ( & V_54 ) ;
return;
}
V_25 -> V_56 = false ;
F_27 ( V_27 , V_52 ) ;
V_53 = V_52 & ~ ( V_57 | V_58 ) ;
if ( V_53 != V_52 ) {
F_28 ( V_27 , V_53 ) ;
V_51 = V_25 -> V_51 ;
}
F_17 () ;
F_25 ( & V_55 ) ;
if ( V_51 )
F_29 ( V_51 , V_59 ) ;
F_26 ( & V_54 ) ;
}
static void F_30 ( int V_11 , struct V_60 * V_50 )
{
unsigned long V_61 = F_31 ( V_62 ) ;
F_32 ( V_11 , V_50 , V_61 ) ;
}
static int F_33 ( T_2 V_52 )
{
int V_11 = F_22 () ;
struct V_10 * V_25 ;
unsigned long V_63 ;
F_34 ( & V_55 , V_63 ) ;
++ V_7 ;
F_20 () ;
V_25 = F_5 ( V_11 ) ;
if ( V_25 && ! V_25 -> V_56 ) {
V_25 -> V_56 = true ;
F_30 ( V_25 -> V_11 , & V_25 -> V_50 ) ;
}
F_35 ( & V_55 , V_63 ) ;
return 0 ;
}
static int F_36 ( unsigned int V_11 )
{
int V_12 = F_6 ( V_11 ) ;
V_6 V_15 , V_16 , V_64 , V_65 , V_17 ;
struct V_10 * V_25 ;
int V_66 , V_19 ;
if ( V_12 >= V_13 )
return - V_67 ;
F_37 ( 6 , & V_16 , & V_64 , & V_65 , & V_17 ) ;
V_66 = V_64 & 0x07 ;
if ( ! V_66 )
return - V_68 ;
V_66 = F_38 ( V_66 , 0 , V_33 ) ;
V_19 = F_7 ( V_11 , & V_15 ) ;
if ( V_19 )
return V_19 ;
V_25 = F_39 ( sizeof( * V_25 ) , V_69 ) ;
if ( ! V_25 )
return - V_67 ;
F_40 ( & V_25 -> V_50 , F_21 ) ;
V_25 -> V_11 = V_11 ;
V_25 -> V_15 = V_15 ;
V_25 -> V_51 = F_41 ( L_6 ,
V_66 ,
( V_66 == V_33 ) ? 0x03 : 0x01 ,
V_25 , & V_70 , & V_71 , 0 , 0 ) ;
if ( F_42 ( V_25 -> V_51 ) ) {
V_19 = F_43 ( V_25 -> V_51 ) ;
F_44 ( V_25 ) ;
return V_19 ;
}
F_18 ( V_38 , V_25 -> V_72 ,
V_25 -> V_73 ) ;
F_45 ( V_11 , & V_25 -> V_74 ) ;
F_24 ( & V_55 ) ;
V_14 [ V_12 ] = V_25 ;
F_25 ( & V_55 ) ;
return 0 ;
}
static int F_46 ( unsigned int V_11 )
{
struct V_10 * V_25 = F_5 ( V_11 ) ;
bool V_75 , V_76 ;
int V_77 ;
if ( ! V_25 )
return 0 ;
V_77 = F_47 ( & V_25 -> V_74 , V_11 ) ;
F_48 ( V_11 , & V_25 -> V_74 ) ;
V_75 = V_77 >= V_78 ;
if ( V_75 ) {
struct V_22 * V_51 = V_25 -> V_51 ;
F_23 ( & V_54 ) ;
V_25 -> V_51 = NULL ;
F_26 ( & V_54 ) ;
F_49 ( V_51 ) ;
}
F_24 ( & V_55 ) ;
V_76 = V_25 -> V_11 == V_11 ;
V_25 -> V_11 = V_77 ;
if ( V_75 ) {
V_14 [ F_6 ( V_11 ) ] = NULL ;
F_19 ( V_38 ,
V_25 -> V_72 , V_25 -> V_73 ) ;
}
if ( V_25 -> V_56 && V_76 ) {
F_25 ( & V_55 ) ;
F_50 ( & V_25 -> V_50 ) ;
F_24 ( & V_55 ) ;
if ( ! V_75 && V_25 -> V_56 )
F_30 ( V_77 , & V_25 -> V_50 ) ;
}
F_25 ( & V_55 ) ;
if ( V_75 )
F_44 ( V_25 ) ;
return 0 ;
}
static int F_51 ( unsigned int V_11 )
{
struct V_10 * V_25 = F_5 ( V_11 ) ;
struct V_79 * V_80 = & F_52 ( V_11 ) ;
if ( ! F_53 ( V_80 , V_81 ) || ! F_53 ( V_80 , V_82 ) )
return - V_68 ;
if ( V_25 ) {
F_45 ( V_11 , & V_25 -> V_74 ) ;
return 0 ;
}
return F_36 ( V_11 ) ;
}
static int T_3 F_54 ( void )
{
int V_32 ;
if ( ! F_55 ( V_83 ) )
return - V_68 ;
V_13 = F_56 () ;
V_14 = F_39 ( V_13 * sizeof( struct V_10 * ) , V_69 ) ;
if ( ! V_14 )
return - V_67 ;
V_32 = F_57 ( V_84 , L_7 ,
F_51 , F_46 ) ;
if ( V_32 < 0 )
goto V_19;
V_85 = V_32 ;
V_86 = F_33 ;
V_87 = F_16 ;
F_1 () ;
return 0 ;
V_19:
F_44 ( V_14 ) ;
return V_32 ;
}
static void T_4 F_58 ( void )
{
V_86 = NULL ;
V_87 = NULL ;
F_59 ( V_85 ) ;
F_4 ( V_3 ) ;
F_44 ( V_14 ) ;
}
