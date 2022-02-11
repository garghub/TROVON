static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 &= ~ ( 1 << ( V_2 -> V_6 - V_4 -> V_7 ) ) ;
F_3 ( L_1 , V_2 -> V_6 , V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 |= 1 << ( V_2 -> V_6 - V_4 -> V_7 ) ;
F_3 ( L_2 , V_2 -> V_6 , V_4 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_8 & ~ V_9 )
return - V_10 ;
if ( V_8 & ( V_11 | V_12 ) )
return - V_10 ;
V_4 -> V_13 = V_8 ;
return 0 ;
}
static T_1 F_6 ( int V_6 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
unsigned int V_17 ;
unsigned long V_8 ;
int V_18 ;
if ( ! V_16 ) {
F_3 ( L_3 ) ;
return V_19 ;
}
for ( V_17 = 0 ; V_17 < V_16 -> V_20 ; V_17 ++ ) {
struct V_3 * V_4 = & V_16 -> V_4 [ V_17 ] ;
struct V_21 * V_22 ;
int V_23 ;
unsigned long V_24 , V_25 ;
if ( ! V_4 ) {
F_3 ( L_4 , V_17 ) ;
continue;
}
if ( V_4 -> V_26 == 0 )
continue;
V_22 = V_4 -> V_22 ;
if ( ! V_22 ) {
F_3 ( L_5 , V_17 ) ;
continue;
}
V_23 = F_7 ( V_22 , V_4 -> V_27 ) ;
if ( V_23 < 0 ) {
F_8 ( V_4 -> V_14 , L_6 ,
V_23 ) ;
continue;
}
V_24 = ( unsigned long ) V_23 ;
F_9 ( & V_4 -> V_28 , V_8 ) ;
V_25 = V_4 -> V_29 ;
V_4 -> V_29 = V_24 ;
F_10 ( & V_4 -> V_28 , V_8 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_26 ; V_18 ++ ) {
unsigned V_30 , V_31 , type = V_4 -> V_13 ;
V_6 = V_4 -> V_7 + V_18 ;
V_30 = ( V_25 >> V_18 ) & 1 ;
V_31 = ( V_24 >> V_18 ) & 1 ;
if ( ( ! V_30 && V_31 && ( type & V_32 ) ) ||
( V_30 && ! V_31 && ( type & V_33 ) ) ) {
F_3 ( L_7 , V_18 ) ;
F_11 ( V_6 ) ;
}
}
}
if ( V_16 -> V_34 )
F_12 ( V_16 -> V_34 , 1 ) ;
if ( V_16 -> V_35 )
F_12 ( V_16 -> V_35 , 0 ) ;
return V_19 ;
}
static void F_13 ( struct V_36 * V_4 , unsigned V_37 , int V_23 )
{
struct V_21 * V_22 ;
struct V_3 * V_38 ;
unsigned long V_8 ;
V_38 = F_14 ( V_4 , struct V_3 , V_39 ) ;
if ( ! V_38 )
return;
V_22 = V_38 -> V_22 ;
if ( V_22 == NULL )
return;
F_9 ( & V_38 -> V_28 , V_8 ) ;
if ( V_23 )
V_38 -> V_27 |= ( 1 << V_37 ) ;
else
V_38 -> V_27 &= ~ ( 1 << V_37 ) ;
F_10 ( & V_38 -> V_28 , V_8 ) ;
F_15 ( & ( V_38 -> V_40 ) ) ;
}
static void F_16 ( struct V_41 * V_42 )
{
struct V_3 * V_38 ;
struct V_21 * V_22 ;
V_38 = F_14 ( V_42 , struct V_3 , V_40 ) ;
V_22 = V_38 -> V_22 ;
F_7 ( V_22 , V_38 -> V_27 ) ;
}
static int F_17 ( struct V_36 * V_4 , unsigned V_37 )
{
struct V_3 * V_38 ;
int V_23 = 0 ;
int V_43 = 0 ;
V_38 = F_14 ( V_4 , struct V_3 , V_39 ) ;
if ( ! V_38 ) {
V_43 = 1 ;
V_38 = F_14 ( V_4 , struct V_3 , V_44 ) ;
if ( ! V_38 )
return - V_10 ;
}
if ( ! V_43 )
V_23 = ( V_38 -> V_27 >> V_37 ) & 1 ;
else
V_23 = ( V_38 -> V_29 >> V_37 ) & 1 ;
if ( V_23 )
return 1 ;
else
return 0 ;
}
static int F_18 ( struct V_36 * V_4 ,
unsigned V_37 , int V_45 )
{
F_13 ( V_4 , V_37 , V_45 ) ;
return 0 ;
}
static int F_19 ( struct V_36 * V_4 ,
unsigned V_37 )
{
return ( V_37 < V_4 -> V_46 ) ? 0 : - V_10 ;
}
static int F_20 ( struct V_36 * V_4 , unsigned V_37 )
{
struct V_3 * V_38 ;
V_38 = F_14 ( V_4 , struct V_3 , V_44 ) ;
if ( V_37 < V_38 -> V_26 )
return V_38 -> V_7 + V_37 ;
else
return - V_10 ;
}
static void F_21 ( struct V_21 * V_22 )
{
struct V_3 * V_38 = F_22 ( V_22 ) ;
if ( ! V_38 )
return;
F_7 (
V_22 , ( V_38 -> V_27 = V_38 -> V_47 ) ) ;
}
static int F_23 (
struct V_48 * V_49 ,
int V_50 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
unsigned int V_6 , V_51 ;
int V_52 = 0 ;
V_16 = F_24 ( V_49 ) ;
V_4 = & V_16 -> V_4 [ V_50 ] ;
V_51 = V_4 -> V_7 + V_4 -> V_26 ;
for ( V_6 = V_4 -> V_7 ; V_6 < V_51 ; V_6 ++ ) {
F_25 ( V_6 , & V_53 ,
V_54 ) ;
F_26 ( V_6 , V_4 ) ;
#ifdef F_27
F_28 ( V_6 , V_55 | V_56 ) ;
#else
F_29 ( V_6 ) ;
#endif
}
return V_52 ;
}
static int F_30 (
struct V_48 * V_49 ,
int V_50 )
{
struct V_15 * V_16 ;
struct V_57 * V_14 = & V_49 -> V_14 ;
struct V_58 * V_59 ;
struct V_3 * V_4 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_21 * V_22 ;
struct V_64 V_65 ;
V_59 = F_31 ( V_14 ) ;
V_16 = F_24 ( V_49 ) ;
V_4 = & V_16 -> V_4 [ V_50 ] ;
V_61 = & V_59 -> V_4 [ V_50 ] ;
V_63 = F_32 ( V_59 -> V_66 ) ;
if ( V_63 == NULL ) {
F_8 ( V_14 , L_8 ,
V_61 -> V_67 , V_59 -> V_66 ) ;
return - V_68 ;
}
if ( ! F_33 ( V_63 , V_69 ) ) {
F_8 ( V_14 , L_9 ,
V_59 -> V_66 ) ;
return - V_10 ;
}
memset ( & V_65 , 0 , sizeof( struct V_64 ) ) ;
V_65 . V_67 = V_61 -> V_67 ;
F_34 ( V_65 . type , L_10 , V_70 ) ;
V_65 . V_71 = V_4 ;
V_22 = F_35 ( V_63 , & V_65 ) ;
if ( ! V_22 ) {
F_8 ( V_14 , L_11 ,
V_61 -> V_67 ) ;
return - V_68 ;
}
F_36 ( V_22 , V_4 ) ;
snprintf ( V_22 -> V_72 , V_70 , L_12 , V_22 -> V_67 ) ;
V_4 -> V_22 = V_22 ;
F_21 ( V_22 ) ;
V_4 -> V_29 = F_7 ( V_22 , V_4 -> V_27 ) ;
return 0 ;
}
static void F_37 (
struct V_48 * V_49 ,
int V_50 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
V_16 = F_24 ( V_49 ) ;
V_4 = & V_16 -> V_4 [ V_50 ] ;
if ( V_4 -> V_22 )
F_38 ( V_4 -> V_22 ) ;
}
static int F_39 (
struct V_48 * V_49 ,
int V_50 )
{
struct V_15 * V_16 ;
struct V_57 * V_14 = & V_49 -> V_14 ;
struct V_58 * V_59 ;
struct V_3 * V_4 ;
struct V_60 * V_61 ;
struct V_36 * V_36 ;
int V_52 = 0 ;
V_59 = F_31 ( V_14 ) ;
V_16 = F_24 ( V_49 ) ;
V_4 = & V_16 -> V_4 [ V_50 ] ;
V_61 = & V_59 -> V_4 [ V_50 ] ;
V_36 = & ( V_4 -> V_39 ) ;
V_36 -> V_73 = L_13 ;
V_36 -> V_14 = V_14 ;
V_36 -> V_74 = V_75 ;
V_36 -> V_76 = F_17 ;
V_36 -> V_77 = F_13 ;
V_36 -> V_78 = NULL ;
V_36 -> V_79 = F_18 ;
V_36 -> V_80 = V_61 -> V_81 ;
V_36 -> V_46 = V_61 -> V_82 ;
V_36 = & ( V_4 -> V_44 ) ;
V_36 -> V_73 = L_14 ;
V_36 -> V_14 = V_14 ;
V_36 -> V_74 = V_75 ;
V_36 -> V_76 = F_17 ;
V_36 -> V_77 = NULL ;
V_36 -> V_78 = F_19 ;
V_36 -> V_79 = NULL ;
V_36 -> V_83 = F_20 ;
V_36 -> V_80 = V_61 -> V_84 ;
V_36 -> V_46 = V_61 -> V_82 ;
V_52 = F_40 ( & ( V_4 -> V_39 ) ) ;
if ( V_52 ) {
F_8 ( V_14 , L_15 ,
V_61 -> V_67 , V_52 ) ;
return V_52 ;
}
V_52 = F_40 ( & ( V_4 -> V_44 ) ) ;
if ( V_52 ) {
int error ;
F_8 ( V_14 , L_16 ,
V_61 -> V_67 , V_52 ) ;
error = F_41 ( & ( V_4 -> V_39 ) ) ;
if ( error )
F_8 ( V_14 , L_17 , error ) ;
return V_52 ;
}
return 0 ;
}
static int F_42 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
struct V_57 * V_14 = & V_49 -> V_14 ;
struct V_58 * V_59 ;
int V_17 ;
V_59 = F_31 ( V_14 ) ;
V_16 = F_24 ( V_49 ) ;
V_16 -> V_20 = V_59 -> V_85 ;
V_16 -> V_4 = F_43 ( V_14 , sizeof( struct V_3 ) * V_16 -> V_20 ,
V_86 ) ;
if ( ! V_16 -> V_4 ) {
F_8 ( V_14 , L_18 ) ;
return - V_87 ;
}
for ( V_17 = 0 ; V_17 < V_16 -> V_20 ; V_17 ++ ) {
int V_52 ;
V_16 -> V_4 [ V_17 ] . V_47 = V_59 -> V_4 [ V_17 ] . V_47 ;
V_16 -> V_4 [ V_17 ] . V_27 = V_59 -> V_4 [ V_17 ] . V_47 ;
V_16 -> V_4 [ V_17 ] . V_29 = 0 ;
V_16 -> V_4 [ V_17 ] . V_14 = V_14 ;
V_16 -> V_4 [ V_17 ] . V_7 = V_59 -> V_4 [ V_17 ] . V_88 ;
V_16 -> V_4 [ V_17 ] . V_26 = V_59 -> V_4 [ V_17 ] . V_89 ;
F_44 ( & ( V_16 -> V_4 [ V_17 ] . V_40 ) , & F_16 ) ;
F_45 ( & ( V_16 -> V_4 [ V_17 ] . V_28 ) ) ;
if ( V_16 -> V_90 ) {
V_52 = F_23 ( V_49 , V_17 ) ;
if ( V_52 )
continue;
}
V_52 = F_30 ( V_49 , V_17 ) ;
if ( V_52 )
continue;
V_52 = F_39 ( V_49 , V_17 ) ;
if ( V_52 ) {
F_37 ( V_49 , V_17 ) ;
continue;
}
F_46 ( V_14 , L_19 , V_59 -> V_4 [ V_17 ] . V_67 ) ;
}
return 0 ;
}
static int F_47 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
struct V_57 * V_14 = & V_49 -> V_14 ;
struct V_58 * V_59 ;
struct V_91 * V_92 ;
int V_52 = 0 ;
if ( ! V_14 )
return - V_68 ;
V_59 = F_31 ( V_14 ) ;
if ( ! V_59 ) {
F_8 ( V_14 , L_20 ) ;
return - V_93 ;
}
V_16 = F_43 ( V_14 , sizeof( struct V_15 ) , V_86 ) ;
if ( ! V_16 )
return - V_87 ;
V_92 = F_48 ( V_49 , V_94 , 0 ) ;
if ( V_92 ) {
int V_8 ;
V_16 -> V_90 = V_92 -> V_95 ;
V_8 = V_96 | V_97 ;
V_52 = F_49 ( V_16 -> V_90 ,
NULL , F_6 ,
V_8 , V_49 -> V_72 , V_16 ) ;
if ( V_52 ) {
F_8 ( V_14 , L_21 , V_52 ) ;
return V_52 ;
} else
F_50 ( V_14 , 0 ) ;
}
F_51 ( V_49 , V_16 ) ;
V_52 = F_42 ( V_49 ) ;
if ( V_52 )
return V_52 ;
if ( V_59 -> V_34 ) {
V_52 = F_52 ( V_59 -> V_34 , L_22 ) ;
if ( V_52 ) {
F_8 ( V_14 , L_23 ) ;
V_16 -> V_34 = 0 ;
} else {
V_16 -> V_34 = V_59 -> V_34 ;
F_12 ( V_16 -> V_34 , 1 ) ;
}
}
if ( V_59 -> V_35 ) {
V_52 = F_52 ( V_59 -> V_35 , L_22 ) ;
if ( V_52 ) {
F_8 ( V_14 , L_24 ) ;
V_16 -> V_35 = 0 ;
} else {
V_16 -> V_35 = V_59 -> V_35 ;
F_12 ( V_16 -> V_35 , 0 ) ;
}
}
F_46 ( V_14 , L_25 ) ;
return 0 ;
}
static int T_2 F_53 ( void )
{
int V_52 ;
V_52 = F_54 ( & V_98 ) ;
if ( V_52 )
return V_52 ;
return F_55 ( & V_99 , F_47 ) ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_98 ) ;
F_58 ( & V_99 ) ;
}
