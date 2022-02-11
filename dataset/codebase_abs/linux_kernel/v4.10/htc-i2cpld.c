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
struct V_3 * V_38 = F_14 ( V_4 ) ;
unsigned long V_8 ;
V_22 = V_38 -> V_22 ;
if ( ! V_22 )
return;
F_9 ( & V_38 -> V_28 , V_8 ) ;
if ( V_23 )
V_38 -> V_27 |= ( 1 << V_37 ) ;
else
V_38 -> V_27 &= ~ ( 1 << V_37 ) ;
F_10 ( & V_38 -> V_28 , V_8 ) ;
F_15 ( & ( V_38 -> V_39 ) ) ;
}
static void F_16 ( struct V_40 * V_41 )
{
struct V_3 * V_38 ;
struct V_21 * V_22 ;
V_38 = F_17 ( V_41 , struct V_3 , V_39 ) ;
V_22 = V_38 -> V_22 ;
F_7 ( V_22 , V_38 -> V_27 ) ;
}
static int F_18 ( struct V_36 * V_4 , unsigned V_37 )
{
struct V_3 * V_38 = F_14 ( V_4 ) ;
T_2 V_42 ;
if ( ! strncmp ( V_4 -> V_43 , L_8 , 10 ) ) {
V_42 = V_38 -> V_27 ;
} else if ( ! strncmp ( V_4 -> V_43 , L_9 , 9 ) ) {
V_42 = V_38 -> V_29 ;
} else
return - V_10 ;
return ( V_42 >> V_37 ) & 1 ;
}
static int F_19 ( struct V_36 * V_4 ,
unsigned V_37 , int V_44 )
{
F_13 ( V_4 , V_37 , V_44 ) ;
return 0 ;
}
static int F_20 ( struct V_36 * V_4 ,
unsigned V_37 )
{
return ( V_37 < V_4 -> V_45 ) ? 0 : - V_10 ;
}
static int F_21 ( struct V_36 * V_4 , unsigned V_37 )
{
struct V_3 * V_38 = F_14 ( V_4 ) ;
if ( V_37 < V_38 -> V_26 )
return V_38 -> V_7 + V_37 ;
else
return - V_10 ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_3 * V_38 = F_23 ( V_22 ) ;
if ( ! V_38 )
return;
F_7 (
V_22 , ( V_38 -> V_27 = V_38 -> V_46 ) ) ;
}
static int F_24 (
struct V_47 * V_48 ,
int V_49 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
unsigned int V_6 , V_50 ;
V_16 = F_25 ( V_48 ) ;
V_4 = & V_16 -> V_4 [ V_49 ] ;
V_50 = V_4 -> V_7 + V_4 -> V_26 ;
for ( V_6 = V_4 -> V_7 ; V_6 < V_50 ; V_6 ++ ) {
F_26 ( V_6 , & V_51 ,
V_52 ) ;
F_27 ( V_6 , V_4 ) ;
F_28 ( V_6 , V_53 | V_54 ) ;
}
return 0 ;
}
static int F_29 (
struct V_47 * V_48 ,
int V_49 )
{
struct V_15 * V_16 ;
struct V_55 * V_14 = & V_48 -> V_14 ;
struct V_56 * V_57 ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_21 * V_22 ;
struct V_62 V_63 ;
V_57 = F_30 ( V_14 ) ;
V_16 = F_25 ( V_48 ) ;
V_4 = & V_16 -> V_4 [ V_49 ] ;
V_59 = & V_57 -> V_4 [ V_49 ] ;
V_61 = F_31 ( V_57 -> V_64 ) ;
if ( ! V_61 ) {
F_8 ( V_14 , L_10 ,
V_59 -> V_65 , V_57 -> V_64 ) ;
return - V_66 ;
}
if ( ! F_32 ( V_61 , V_67 ) ) {
F_8 ( V_14 , L_11 ,
V_57 -> V_64 ) ;
return - V_10 ;
}
memset ( & V_63 , 0 , sizeof( struct V_62 ) ) ;
V_63 . V_65 = V_59 -> V_65 ;
F_33 ( V_63 . type , L_12 , V_68 ) ;
V_63 . V_69 = V_4 ;
V_22 = F_34 ( V_61 , & V_63 ) ;
if ( ! V_22 ) {
F_8 ( V_14 , L_13 ,
V_59 -> V_65 ) ;
return - V_66 ;
}
F_35 ( V_22 , V_4 ) ;
snprintf ( V_22 -> V_70 , V_68 , L_14 , V_22 -> V_65 ) ;
V_4 -> V_22 = V_22 ;
F_22 ( V_22 ) ;
V_4 -> V_29 = F_7 ( V_22 , V_4 -> V_27 ) ;
return 0 ;
}
static void F_36 (
struct V_47 * V_48 ,
int V_49 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
V_16 = F_25 ( V_48 ) ;
V_4 = & V_16 -> V_4 [ V_49 ] ;
if ( V_4 -> V_22 )
F_37 ( V_4 -> V_22 ) ;
}
static int F_38 (
struct V_47 * V_48 ,
int V_49 )
{
struct V_15 * V_16 ;
struct V_55 * V_14 = & V_48 -> V_14 ;
struct V_56 * V_57 ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
struct V_36 * V_36 ;
int V_71 = 0 ;
V_57 = F_30 ( V_14 ) ;
V_16 = F_25 ( V_48 ) ;
V_4 = & V_16 -> V_4 [ V_49 ] ;
V_59 = & V_57 -> V_4 [ V_49 ] ;
V_36 = & ( V_4 -> V_72 ) ;
V_36 -> V_43 = L_8 ;
V_36 -> V_73 = V_14 ;
V_36 -> V_74 = V_75 ;
V_36 -> V_76 = F_18 ;
V_36 -> V_77 = F_13 ;
V_36 -> V_78 = NULL ;
V_36 -> V_79 = F_19 ;
V_36 -> V_80 = V_59 -> V_81 ;
V_36 -> V_45 = V_59 -> V_82 ;
V_36 = & ( V_4 -> V_83 ) ;
V_36 -> V_43 = L_9 ;
V_36 -> V_73 = V_14 ;
V_36 -> V_74 = V_75 ;
V_36 -> V_76 = F_18 ;
V_36 -> V_77 = NULL ;
V_36 -> V_78 = F_20 ;
V_36 -> V_79 = NULL ;
V_36 -> V_84 = F_21 ;
V_36 -> V_80 = V_59 -> V_85 ;
V_36 -> V_45 = V_59 -> V_82 ;
V_71 = F_39 ( & ( V_4 -> V_72 ) , V_4 ) ;
if ( V_71 ) {
F_8 ( V_14 , L_15 ,
V_59 -> V_65 , V_71 ) ;
return V_71 ;
}
V_71 = F_39 ( & ( V_4 -> V_83 ) , V_4 ) ;
if ( V_71 ) {
F_8 ( V_14 , L_16 ,
V_59 -> V_65 , V_71 ) ;
F_40 ( & ( V_4 -> V_72 ) ) ;
return V_71 ;
}
return 0 ;
}
static int F_41 ( struct V_47 * V_48 )
{
struct V_15 * V_16 ;
struct V_55 * V_14 = & V_48 -> V_14 ;
struct V_56 * V_57 ;
int V_17 ;
V_57 = F_30 ( V_14 ) ;
V_16 = F_25 ( V_48 ) ;
V_16 -> V_20 = V_57 -> V_86 ;
V_16 -> V_4 = F_42 ( V_14 , sizeof( struct V_3 ) * V_16 -> V_20 ,
V_87 ) ;
if ( ! V_16 -> V_4 ) {
F_8 ( V_14 , L_17 ) ;
return - V_88 ;
}
for ( V_17 = 0 ; V_17 < V_16 -> V_20 ; V_17 ++ ) {
int V_71 ;
V_16 -> V_4 [ V_17 ] . V_46 = V_57 -> V_4 [ V_17 ] . V_46 ;
V_16 -> V_4 [ V_17 ] . V_27 = V_57 -> V_4 [ V_17 ] . V_46 ;
V_16 -> V_4 [ V_17 ] . V_29 = 0 ;
V_16 -> V_4 [ V_17 ] . V_14 = V_14 ;
V_16 -> V_4 [ V_17 ] . V_7 = V_57 -> V_4 [ V_17 ] . V_89 ;
V_16 -> V_4 [ V_17 ] . V_26 = V_57 -> V_4 [ V_17 ] . V_90 ;
F_43 ( & ( V_16 -> V_4 [ V_17 ] . V_39 ) , & F_16 ) ;
F_44 ( & ( V_16 -> V_4 [ V_17 ] . V_28 ) ) ;
if ( V_16 -> V_91 ) {
V_71 = F_24 ( V_48 , V_17 ) ;
if ( V_71 )
continue;
}
V_71 = F_29 ( V_48 , V_17 ) ;
if ( V_71 )
continue;
V_71 = F_38 ( V_48 , V_17 ) ;
if ( V_71 ) {
F_36 ( V_48 , V_17 ) ;
continue;
}
F_45 ( V_14 , L_18 , V_57 -> V_4 [ V_17 ] . V_65 ) ;
}
return 0 ;
}
static int F_46 ( struct V_47 * V_48 )
{
struct V_15 * V_16 ;
struct V_55 * V_14 = & V_48 -> V_14 ;
struct V_56 * V_57 ;
struct V_92 * V_93 ;
int V_71 = 0 ;
if ( ! V_14 )
return - V_66 ;
V_57 = F_30 ( V_14 ) ;
if ( ! V_57 ) {
F_8 ( V_14 , L_19 ) ;
return - V_94 ;
}
V_16 = F_42 ( V_14 , sizeof( struct V_15 ) , V_87 ) ;
if ( ! V_16 )
return - V_88 ;
V_93 = F_47 ( V_48 , V_95 , 0 ) ;
if ( V_93 ) {
int V_8 ;
V_16 -> V_91 = V_93 -> V_96 ;
V_8 = V_97 | V_98 |
V_99 ;
V_71 = F_48 ( V_16 -> V_91 ,
NULL , F_6 ,
V_8 , V_48 -> V_70 , V_16 ) ;
if ( V_71 ) {
F_8 ( V_14 , L_20 , V_71 ) ;
return V_71 ;
} else
F_49 ( V_14 , 0 ) ;
}
F_50 ( V_48 , V_16 ) ;
V_71 = F_41 ( V_48 ) ;
if ( V_71 )
return V_71 ;
if ( V_57 -> V_34 ) {
V_71 = F_51 ( V_57 -> V_34 , L_21 ) ;
if ( V_71 ) {
F_8 ( V_14 , L_22 ) ;
V_16 -> V_34 = 0 ;
} else {
V_16 -> V_34 = V_57 -> V_34 ;
F_12 ( V_16 -> V_34 , 1 ) ;
}
}
if ( V_57 -> V_35 ) {
V_71 = F_51 ( V_57 -> V_35 , L_21 ) ;
if ( V_71 ) {
F_8 ( V_14 , L_23 ) ;
V_16 -> V_35 = 0 ;
} else {
V_16 -> V_35 = V_57 -> V_35 ;
F_12 ( V_16 -> V_35 , 0 ) ;
}
}
F_45 ( V_14 , L_24 ) ;
return 0 ;
}
static int T_3 F_52 ( void )
{
int V_71 ;
V_71 = F_53 ( & V_100 ) ;
if ( V_71 )
return V_71 ;
return F_54 ( & V_101 , F_46 ) ;
}
static void T_4 F_55 ( void )
{
F_56 ( & V_100 ) ;
F_57 ( & V_101 ) ;
}
