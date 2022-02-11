static bool F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
bool V_5 = false ;
T_1 V_6 ;
while ( V_3 -- ) {
V_6 = F_2 ( V_2 -> V_7 + V_8 ) ;
V_5 = ! ! ( V_6 & V_9 ) ;
if ( V_5 )
break;
F_3 ( V_4 ) ;
}
F_4 ( L_1 , V_5 ? L_2 : L_3 ) ;
return V_5 ;
}
static int F_5 ( struct V_10 * V_11 , unsigned long V_12 ,
unsigned long V_13 )
{
struct V_14 * V_15 = F_6 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
void T_2 * V_16 = V_2 -> V_7 ;
T_1 V_6 , V_17 , V_18 ;
F_4 ( L_4 , V_12 , V_13 ) ;
V_17 = V_12 / 10 ;
V_6 = V_19 / 10 ;
V_18 = ( V_17 * V_20 ) / V_6 ;
V_18 = V_18 / 2 - 1 ;
F_8 ( V_16 + V_21 ,
V_18 & 0xff ) ;
V_6 = F_2 ( V_16 + V_22 ) ;
V_6 |= ( V_18 >> 8 ) & 0x07 ;
F_8 ( V_16 + V_22 ,
V_6 ) ;
V_6 = F_2 ( V_16 + V_23 ) ;
V_6 |= ( V_20 - 1 ) & 0x3f ;
F_8 ( V_16 + V_23 ,
V_6 ) ;
F_8 ( V_16 + V_24 ,
0xf ) ;
V_6 = F_2 ( V_16 + V_25 ) ;
V_6 |= 0x7 << 4 ;
F_8 ( V_16 + V_25 ,
V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_6 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
return F_1 ( V_2 , V_26 ,
V_27 ) ;
}
static unsigned long F_10 ( struct V_10 * V_11 ,
unsigned long V_13 )
{
struct V_14 * V_15 = F_6 ( V_11 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
void T_2 * V_16 = V_2 -> V_7 ;
unsigned long V_28 ;
T_1 V_29 , V_18 , V_17 , V_30 ;
F_11 ( L_5 , V_13 ) ;
V_29 = F_2 ( V_16 + V_31 ) ;
if ( V_29 & V_32 ) {
V_18 = F_2 ( V_16 + V_21 ) ;
V_18 &= 0xff ;
V_17 = F_2 ( V_16 + V_22 ) & 0x07 ;
V_18 = ( V_17 << 8 ) | V_18 ;
V_18 += 1 ;
V_30 = F_2 ( V_16 + V_23 ) ;
V_30 &= 0x3f ;
V_30 += 1 ;
V_28 = ( V_13 / V_30 ) * V_18 * 2 ;
} else {
V_28 = 0 ;
}
F_4 ( L_6 , V_28 ) ;
return V_28 ;
}
static unsigned long F_12 ( struct V_10 * V_11 ,
unsigned long V_13 )
{
struct V_33 * V_34 = F_13 ( V_11 ) ;
unsigned int div ;
div = F_2 ( V_34 -> V_35 ) & 0xff ;
return V_13 / ( div + 1 ) ;
}
static unsigned int F_14 ( unsigned long V_36 )
{
unsigned long V_37 ;
V_37 = ( V_36 * 8 ) / 1000000 ;
if ( V_37 < 125 )
return 64 ;
else if ( V_37 < 250 )
return 32 ;
else if ( V_37 < 600 )
return 16 ;
else
return 8 ;
}
static long F_15 ( struct V_10 * V_11 , unsigned long V_12 ,
unsigned long * V_38 )
{
unsigned long V_39 ;
unsigned int V_40 ;
V_40 = F_14 ( V_12 ) ;
V_39 = V_12 * V_40 ;
* V_38 = F_16 ( F_17 ( V_11 ) , V_39 ) ;
return * V_38 / V_40 ;
}
static int F_18 ( struct V_10 * V_11 , unsigned long V_12 ,
unsigned long V_13 )
{
struct V_33 * V_34 = F_13 ( V_11 ) ;
T_1 V_6 ;
unsigned int V_40 ;
V_40 = F_14 ( V_12 ) ;
V_6 = F_2 ( V_34 -> V_35 ) ;
V_6 |= ( V_40 - 1 ) & 0xff ;
F_8 ( V_34 -> V_35 , V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_41 * V_42 = & V_2 -> V_43 -> V_42 ;
void T_2 * V_16 = V_2 -> V_7 ;
bool V_44 ;
unsigned int V_45 , V_46 ;
int V_47 = 1000 , V_4 = 100 ;
T_1 V_6 ;
F_4 ( L_7 , V_2 -> V_48 ) ;
V_6 = F_2 ( V_16 + V_49 ) ;
V_46 = V_6 + 1 ;
V_45 = V_46 / 8 ;
V_6 = F_2 ( V_16 + V_25 ) ;
V_6 &= ~ 0xf ;
V_6 |= ( V_45 - 1 ) ;
F_8 ( V_16 + V_25 , V_6 ) ;
F_8 ( V_16 + V_31 ,
V_32 ) ;
V_44 = F_1 ( V_2 , V_47 , V_4 ) ;
if ( F_20 ( ! V_44 ) )
F_21 ( V_42 , L_8 ) ;
else
F_4 ( L_9 ) ;
return V_44 ? 0 : - V_50 ;
}
static void F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_4 ( L_7 , V_2 -> V_48 ) ;
F_8 ( V_2 -> V_7 + V_31 , 0x00 ) ;
}
static void F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_51 * V_52 = & V_2 -> V_52 ;
void T_2 * V_16 = V_2 -> V_7 ;
V_52 -> V_53 =
F_2 ( V_16 + V_54 ) ;
V_52 -> V_55 =
F_2 ( V_16 + V_49 ) ;
V_52 -> V_56 =
F_2 ( V_16 + V_25 ) ;
V_52 -> V_28 = F_24 ( & V_15 -> V_10 ) ;
}
static int F_25 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
struct V_51 * V_52 = & V_2 -> V_52 ;
void T_2 * V_16 = V_2 -> V_7 ;
int V_57 ;
V_57 = F_5 ( & V_15 -> V_10 ,
V_52 -> V_28 , 0 ) ;
if ( V_57 ) {
F_21 ( & V_2 -> V_43 -> V_42 ,
L_10 , V_57 ) ;
return V_57 ;
}
F_8 ( V_16 + V_54 ,
V_52 -> V_53 ) ;
F_8 ( V_16 + V_49 ,
V_52 -> V_55 ) ;
F_8 ( V_16 + V_25 ,
V_52 -> V_56 ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 ,
struct V_58 * * V_59 ,
struct V_58 * * V_60 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
if ( V_59 )
* V_59 = V_2 -> V_61 [ V_62 ] ;
if ( V_60 )
* V_60 =
V_2 -> V_61 [ V_63 ] ;
return 0 ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_28 ( V_2 -> V_43 ,
V_2 -> V_64 , V_2 -> V_65 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
char * V_66 , * V_67 , * V_68 ;
struct V_69 V_70 = {
. V_71 = ( const char * [] ) { L_11 } ,
. V_72 = 1 ,
. V_73 = & V_74 ,
} ;
struct V_41 * V_42 = & V_2 -> V_43 -> V_42 ;
struct V_58 * * V_64 = V_2 -> V_64 ;
struct V_58 * * V_61 = V_2 -> V_61 ;
struct V_33 * V_34 ;
struct V_69 V_75 = { } ;
int V_57 , V_76 = 0 ;
F_4 ( L_12 , V_2 -> V_48 ) ;
V_34 = F_30 ( V_42 , sizeof( * V_34 ) , V_77 ) ;
if ( ! V_34 )
return - V_78 ;
V_68 = F_30 ( V_42 , 32 , V_77 ) ;
if ( ! V_68 )
return - V_78 ;
V_67 = F_30 ( V_42 , 32 , V_77 ) ;
if ( ! V_67 )
return - V_78 ;
V_66 = F_30 ( V_42 , 32 , V_77 ) ;
if ( ! V_66 )
return - V_78 ;
V_2 -> V_34 = V_34 ;
snprintf ( V_68 , 32 , L_13 , V_2 -> V_48 ) ;
V_70 . V_79 = V_68 ;
V_2 -> V_16 . V_10 . V_80 = & V_70 ;
V_64 [ V_76 ++ ] = F_31 ( V_42 , & V_2 -> V_16 . V_10 ) ;
V_34 -> V_11 . V_80 = & V_75 ;
V_34 -> V_35 = V_2 -> V_7 + V_49 ;
snprintf ( V_67 , 32 , L_13 , V_2 -> V_48 ) ;
snprintf ( V_66 , 32 , L_14 , V_2 -> V_48 ) ;
V_75 . V_79 = V_66 ;
V_75 . V_73 = & V_81 ;
V_75 . V_82 = V_83 ;
V_75 . V_71 = ( const char * const * ) & V_67 ;
V_75 . V_72 = 1 ;
V_64 [ V_76 ++ ] = V_61 [ V_62 ] =
F_31 ( V_42 , & V_34 -> V_11 ) ;
snprintf ( V_66 , 32 , L_15 , V_2 -> V_48 ) ;
V_64 [ V_76 ++ ] = V_61 [ V_63 ] =
F_32 ( V_42 , V_66 ,
V_67 , 0 , V_2 -> V_7 +
V_54 ,
0 , 8 , 0 , NULL ) ;
V_2 -> V_65 = V_76 ;
V_2 -> V_84 . V_85 = V_86 ;
V_2 -> V_84 . V_64 = V_61 ;
V_57 = F_33 ( V_42 -> V_87 ,
V_88 , & V_2 -> V_84 ) ;
if ( V_57 ) {
F_21 ( V_42 , L_16 , V_57 ) ;
return V_57 ;
}
return 0 ;
}
struct V_14 * F_34 ( struct V_89 * V_43 ,
int V_48 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_57 ;
if ( ! V_43 )
return F_35 ( - V_90 ) ;
V_2 = F_30 ( & V_43 -> V_42 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return F_35 ( - V_78 ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_48 = V_48 + 1 ;
V_2 -> V_7 = F_36 ( V_43 , L_17 , L_18 ) ;
if ( F_37 ( V_2 -> V_7 ) ) {
F_21 ( & V_43 -> V_42 , L_19 , V_91 ) ;
return F_35 ( - V_78 ) ;
}
V_15 = & V_2 -> V_16 ;
V_15 -> V_92 = V_93 ;
V_15 -> V_94 = V_95 ;
V_15 -> V_96 = F_26 ;
V_15 -> V_97 = F_27 ;
V_15 -> V_98 = F_22 ;
V_15 -> V_99 = F_23 ;
V_15 -> V_100 = F_25 ;
V_15 -> V_101 = 1 ;
V_15 -> V_102 [ 0 ] = F_19 ;
V_57 = F_29 ( V_2 ) ;
if ( V_57 ) {
F_21 ( & V_43 -> V_42 , L_20 , V_57 ) ;
return F_35 ( V_57 ) ;
}
return V_15 ;
}
