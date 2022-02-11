static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 [ V_7 -> V_13 ] ;
if ( V_11 -> V_14 )
return sprintf ( V_5 , L_1 , V_9 -> V_15 ) ;
return sprintf ( V_5 , L_2 , V_11 -> V_16 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_17 , V_18 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 [ V_7 -> V_13 ] ;
F_5 ( & V_11 -> V_19 ) ;
F_6 ( V_11 -> V_20 , V_11 -> V_21 , & V_17 , & V_18 ) ;
F_7 ( & V_11 -> V_19 ) ;
return sprintf ( V_5 , L_3 , ( V_17 >> 5 ) & 1 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_9 -> V_12 [ V_7 -> V_13 ] -> V_22 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_9 -> V_12 [ V_7 -> V_13 ] -> V_23 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_17 , V_18 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 [ V_7 -> V_13 ] ;
F_5 ( & V_11 -> V_19 ) ;
if ( ! V_11 -> V_24 || F_11 ( V_25 , V_11 -> V_26 + V_27 ) ) {
F_6 ( V_11 -> V_20 , V_11 -> V_21 , & V_17 , & V_18 ) ;
V_11 -> V_28 = V_11 -> V_22 - ( ( V_17 >> 16 ) & 0x7f ) * 1000 ;
V_11 -> V_24 = 1 ;
V_11 -> V_26 = V_25 ;
}
F_7 ( & V_11 -> V_19 ) ;
return sprintf ( V_5 , L_3 , V_11 -> V_28 ) ;
}
static int F_12 ( struct V_29 * V_30 , T_2 V_31 , struct V_1 * V_2 )
{
int V_22 = 100000 ;
int V_32 = 85000 ;
int V_33 = 1 ;
int V_34 ;
T_2 V_17 , V_18 ;
int V_35 ;
struct V_36 * V_37 = F_13 ( 0 , F_14 ( 0 , 0 ) ) ;
if ( V_37 && V_37 -> V_38 == V_39 ) {
for ( V_35 = 0 ; V_35 < F_15 ( V_40 ) ; V_35 ++ ) {
if ( V_37 -> V_1 == V_40 [ V_35 ] . V_1 )
return V_40 [ V_35 ] . V_22 ;
}
}
for ( V_35 = 0 ; V_35 < F_15 ( V_41 ) ; V_35 ++ ) {
if ( strstr ( V_30 -> V_42 , V_41 [ V_35 ] . V_31 ) )
return V_41 [ V_35 ] . V_22 ;
}
for ( V_35 = 0 ; V_35 < F_15 ( V_43 ) ; V_35 ++ ) {
const struct V_44 * V_45 = & V_43 [ V_35 ] ;
if ( V_30 -> V_46 == V_45 -> V_47 &&
( V_45 -> V_48 == V_49 || V_30 -> V_50 == V_45 -> V_48 ) )
return V_45 -> V_22 ;
}
if ( V_30 -> V_46 == 0xf && V_30 -> V_50 < 4 )
V_33 = 0 ;
if ( V_30 -> V_46 > 0xe && V_33 ) {
T_3 V_51 ;
V_34 = F_16 ( V_31 , 0x17 , & V_17 , & V_18 ) ;
if ( V_34 ) {
F_17 ( V_2 ,
L_4
L_5 ) ;
V_33 = 0 ;
} else if ( V_30 -> V_46 < 0x17 && ! ( V_17 & 0x10000000 ) ) {
V_33 = 0 ;
} else {
V_51 = ( V_18 >> 18 ) & 0x7 ;
if ( V_30 -> V_46 == 0x17 &&
( V_51 == 5 || V_51 == 7 ) ) {
V_32 = 90000 ;
V_22 = 105000 ;
}
}
}
if ( V_33 ) {
V_34 = F_16 ( V_31 , 0xee , & V_17 , & V_18 ) ;
if ( V_34 ) {
F_17 ( V_2 ,
L_6
L_7 ) ;
} else if ( V_17 & 0x40000000 ) {
V_22 = V_32 ;
}
} else if ( V_22 == 100000 ) {
F_17 ( V_2 , L_8 ) ;
}
return V_22 ;
}
static bool F_18 ( struct V_29 * V_30 )
{
T_3 V_47 = V_30 -> V_46 ;
return V_47 > 0xe &&
V_47 != 0x1c &&
V_47 != 0x26 &&
V_47 != 0x27 &&
V_47 != 0x35 &&
V_47 != 0x36 ;
}
static int F_19 ( struct V_29 * V_30 , T_2 V_31 , struct V_1 * V_2 )
{
int V_34 ;
T_2 V_17 , V_18 ;
T_2 V_52 ;
V_34 = F_16 ( V_31 , V_53 , & V_17 , & V_18 ) ;
if ( V_34 ) {
if ( F_18 ( V_30 ) )
F_17 ( V_2 , L_9 , V_31 ) ;
} else {
V_52 = ( V_17 >> 16 ) & 0xff ;
if ( V_52 ) {
F_20 ( V_2 , L_10 , V_52 ) ;
return V_52 * 1000 ;
}
}
if ( V_54 ) {
F_21 ( V_2 , L_11 ,
V_54 ) ;
return V_54 * 1000 ;
}
return F_12 ( V_30 , V_31 , V_2 ) ;
}
static int F_22 ( struct V_10 * V_11 , struct V_1 * V_2 ,
int V_55 )
{
int V_35 ;
static T_1 ( * const V_56 [ V_57 ] ) ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ) = {
F_1 , F_4 , F_10 , F_8 ,
F_9 } ;
static const char * const V_58 [ V_57 ] = {
L_12 , L_13 , L_14 , L_15 , L_16
} ;
for ( V_35 = 0 ; V_35 < V_11 -> V_59 ; V_35 ++ ) {
snprintf ( V_11 -> V_60 [ V_35 ] , V_61 ,
L_17 , V_55 , V_58 [ V_35 ] ) ;
F_23 ( & V_11 -> V_62 [ V_35 ] . V_63 . V_7 ) ;
V_11 -> V_62 [ V_35 ] . V_63 . V_7 . V_64 = V_11 -> V_60 [ V_35 ] ;
V_11 -> V_62 [ V_35 ] . V_63 . V_7 . V_65 = V_66 ;
V_11 -> V_62 [ V_35 ] . V_63 . V_67 = V_56 [ V_35 ] ;
V_11 -> V_62 [ V_35 ] . V_13 = V_55 ;
V_11 -> V_68 [ V_35 ] = & V_11 -> V_62 [ V_35 ] . V_63 . V_7 ;
}
V_11 -> V_69 . V_68 = V_11 -> V_68 ;
return F_24 ( & V_2 -> V_70 , & V_11 -> V_69 ) ;
}
static int F_25 ( unsigned int V_20 )
{
struct V_29 * V_30 = & F_26 ( V_20 ) ;
if ( V_30 -> V_46 == 0xe && V_30 -> V_50 < 0xc && V_30 -> V_71 < 0x39 ) {
F_27 ( L_18 ) ;
return - V_72 ;
}
return 0 ;
}
static struct V_73 * F_28 ( unsigned int V_20 )
{
int V_74 = F_29 ( V_20 ) ;
if ( V_74 >= 0 && V_74 < V_75 )
return V_76 [ V_74 ] ;
return NULL ;
}
static struct V_10 * F_30 ( unsigned int V_20 , int V_77 )
{
struct V_10 * V_11 ;
V_11 = F_31 ( sizeof( struct V_10 ) , V_78 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_21 = V_77 ? V_79 :
V_80 ;
V_11 -> V_14 = V_77 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_16 = F_32 ( V_20 ) ;
V_11 -> V_59 = V_81 ;
F_33 ( & V_11 -> V_19 ) ;
return V_11 ;
}
static int F_34 ( struct V_73 * V_82 , unsigned int V_20 ,
int V_77 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 = F_35 ( V_82 ) ;
struct V_29 * V_30 = & F_26 ( V_20 ) ;
T_2 V_17 , V_18 ;
int V_34 , V_55 ;
V_55 = V_77 ? V_83 : F_36 ( V_20 ) ;
if ( V_55 > V_84 - 1 )
return - V_85 ;
V_11 = F_30 ( V_20 , V_77 ) ;
if ( ! V_11 )
return - V_86 ;
V_34 = F_16 ( V_20 , V_11 -> V_21 , & V_17 , & V_18 ) ;
if ( V_34 )
goto V_87;
V_11 -> V_22 = F_19 ( V_30 , V_20 , & V_82 -> V_2 ) ;
if ( V_30 -> V_46 > 0xe && V_30 -> V_46 != 0x1c ) {
V_34 = F_16 ( V_20 , V_53 ,
& V_17 , & V_18 ) ;
if ( ! V_34 ) {
V_11 -> V_23
= V_11 -> V_22 - ( ( V_17 >> 8 ) & 0xff ) * 1000 ;
V_11 -> V_59 ++ ;
}
}
V_9 -> V_12 [ V_55 ] = V_11 ;
V_34 = F_22 ( V_11 , V_9 -> V_88 , V_55 ) ;
if ( V_34 )
goto V_87;
return 0 ;
V_87:
V_9 -> V_12 [ V_55 ] = NULL ;
F_37 ( V_11 ) ;
return V_34 ;
}
static void
F_38 ( struct V_73 * V_82 , unsigned int V_20 , int V_77 )
{
if ( F_34 ( V_82 , V_20 , V_77 ) )
F_39 ( & V_82 -> V_2 , L_19 , V_20 ) ;
}
static void F_40 ( struct V_8 * V_9 , int V_89 )
{
struct V_10 * V_11 = V_9 -> V_12 [ V_89 ] ;
F_41 ( & V_9 -> V_88 -> V_70 , & V_11 -> V_69 ) ;
F_37 ( V_9 -> V_12 [ V_89 ] ) ;
V_9 -> V_12 [ V_89 ] = NULL ;
}
static int F_42 ( struct V_73 * V_82 )
{
struct V_1 * V_2 = & V_82 -> V_2 ;
struct V_8 * V_9 ;
V_9 = F_43 ( V_2 , sizeof( struct V_8 ) , V_78 ) ;
if ( ! V_9 )
return - V_86 ;
V_9 -> V_15 = V_82 -> V_31 ;
F_44 ( V_82 , V_9 ) ;
V_9 -> V_88 = F_45 ( V_2 , V_90 ,
V_9 , NULL ) ;
return F_46 ( V_9 -> V_88 ) ;
}
static int F_47 ( struct V_73 * V_82 )
{
struct V_8 * V_9 = F_35 ( V_82 ) ;
int V_35 ;
for ( V_35 = V_84 - 1 ; V_35 >= 0 ; -- V_35 )
if ( V_9 -> V_12 [ V_35 ] )
F_40 ( V_9 , V_35 ) ;
return 0 ;
}
static struct V_73 * F_48 ( unsigned int V_20 )
{
int V_34 , V_74 = F_29 ( V_20 ) ;
struct V_73 * V_82 ;
if ( V_74 < 0 )
return F_49 ( - V_86 ) ;
V_82 = F_50 ( V_90 , V_74 ) ;
if ( ! V_82 )
return F_49 ( - V_86 ) ;
V_34 = F_51 ( V_82 ) ;
if ( V_34 ) {
F_52 ( V_82 ) ;
return F_49 ( V_34 ) ;
}
V_76 [ V_74 ] = V_82 ;
return V_82 ;
}
static int F_53 ( unsigned int V_20 )
{
struct V_73 * V_82 = F_28 ( V_20 ) ;
struct V_29 * V_30 = & F_26 ( V_20 ) ;
struct V_8 * V_9 ;
if ( ! F_54 ( V_30 , V_91 ) )
return - V_72 ;
if ( ! V_82 ) {
if ( F_25 ( V_20 ) )
return - V_92 ;
V_82 = F_48 ( V_20 ) ;
if ( F_55 ( V_82 ) )
return F_56 ( V_82 ) ;
if ( F_54 ( V_30 , V_93 ) )
F_38 ( V_82 , V_20 , 1 ) ;
}
V_9 = F_35 ( V_82 ) ;
if ( ! F_57 ( & V_9 -> V_94 , F_58 ( V_20 ) ) )
F_38 ( V_82 , V_20 , 0 ) ;
F_59 ( V_20 , & V_9 -> V_94 ) ;
return 0 ;
}
static int F_60 ( unsigned int V_20 )
{
struct V_73 * V_82 = F_28 ( V_20 ) ;
struct V_8 * V_95 ;
struct V_10 * V_11 ;
int V_89 , V_96 ;
if ( ! V_82 )
return 0 ;
V_89 = F_36 ( V_20 ) ;
if ( V_89 > V_84 - 1 )
return 0 ;
V_95 = F_35 ( V_82 ) ;
V_11 = V_95 -> V_12 [ V_89 ] ;
F_61 ( V_20 , & V_95 -> V_94 ) ;
V_96 = F_62 ( & V_95 -> V_94 , F_58 ( V_20 ) ) ;
if ( V_96 >= V_97 ) {
F_40 ( V_95 , V_89 ) ;
} else if ( V_11 && V_11 -> V_20 == V_20 ) {
F_5 ( & V_11 -> V_19 ) ;
V_11 -> V_20 = V_96 ;
F_7 ( & V_11 -> V_19 ) ;
}
if ( F_63 ( & V_95 -> V_94 ) ) {
V_76 [ F_29 ( V_20 ) ] = NULL ;
F_64 ( V_82 ) ;
return 0 ;
}
V_11 = V_95 -> V_12 [ V_83 ] ;
if ( V_11 && V_11 -> V_20 == V_20 ) {
V_96 = F_65 ( & V_95 -> V_94 ) ;
F_5 ( & V_11 -> V_19 ) ;
V_11 -> V_20 = V_96 ;
F_7 ( & V_11 -> V_19 ) ;
}
return 0 ;
}
static int T_4 F_66 ( void )
{
int V_34 ;
if ( ! F_67 ( V_98 ) )
return - V_72 ;
V_75 = F_68 () ;
V_76 = F_31 ( V_75 * sizeof( struct V_73 * ) ,
V_78 ) ;
if ( ! V_76 )
return - V_86 ;
V_34 = F_69 ( & V_99 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_70 ( V_100 , L_20 ,
F_53 , F_60 ) ;
if ( V_34 < 0 )
goto V_101;
V_102 = V_34 ;
return 0 ;
V_101:
F_71 ( & V_99 ) ;
F_37 ( V_76 ) ;
return V_34 ;
}
static void T_5 F_72 ( void )
{
F_73 ( V_102 ) ;
F_71 ( & V_99 ) ;
F_37 ( V_76 ) ;
}
