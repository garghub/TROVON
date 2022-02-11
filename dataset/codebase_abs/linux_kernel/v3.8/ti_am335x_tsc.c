static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_6 , unsigned int V_3 ,
unsigned int V_7 )
{
F_4 ( V_7 , V_6 -> V_4 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_8 )
{
unsigned int V_9 ;
int V_10 , V_11 ;
V_11 = 2 * V_8 -> V_12 ;
V_9 = V_13 |
V_14 | V_15 ;
switch ( V_8 -> V_16 ) {
case 4 :
V_9 |= V_17 | V_18 ;
break;
case 5 :
V_9 |= V_19 |
V_20 | V_18 |
V_21 ;
break;
case 8 :
V_9 |= V_17 | V_18 ;
break;
}
for ( V_10 = 1 ; V_10 <= V_8 -> V_12 ; V_10 ++ ) {
F_3 ( V_8 , F_6 ( V_10 ) , V_9 ) ;
F_3 ( V_8 , F_7 ( V_10 ) , V_22 ) ;
}
V_9 = 0 ;
V_9 = V_13 |
V_14 | V_19 |
V_23 | V_24 ;
switch ( V_8 -> V_16 ) {
case 4 :
V_9 |= V_21 ;
break;
case 5 :
V_9 |= V_15 | V_20 |
V_25 | V_26 ;
break;
case 8 :
V_9 |= V_21 ;
break;
}
for ( V_10 = ( V_8 -> V_12 + 1 ) ; V_10 <= V_11 ; V_10 ++ ) {
F_3 ( V_8 , F_6 ( V_10 ) , V_9 ) ;
F_3 ( V_8 , F_7 ( V_10 ) , V_22 ) ;
}
V_9 = 0 ;
V_9 = V_15 | V_19 |
V_27 | V_28 |
V_29 | V_30 ;
F_3 ( V_8 , V_31 , V_9 ) ;
F_3 ( V_8 , V_32 , V_33 ) ;
V_9 = 0 ;
V_9 = V_13 |
V_14 | V_21 |
V_18 | V_23 ;
F_3 ( V_8 , F_6 ( V_11 + 1 ) , V_9 ) ;
F_3 ( V_8 , F_7 ( V_11 + 1 ) ,
V_22 ) ;
V_9 |= V_34 | V_24 ;
F_3 ( V_8 , F_6 ( V_11 + 2 ) , V_9 ) ;
F_3 ( V_8 , F_7 ( V_11 + 2 ) ,
V_22 ) ;
F_3 ( V_8 , V_35 , V_36 ) ;
}
static void F_8 ( struct V_1 * V_8 ,
unsigned int * V_37 , unsigned int * V_38 )
{
unsigned int V_39 = F_1 ( V_8 , V_40 ) ;
unsigned int V_41 = ~ 0 , V_42 = ~ 0 ;
unsigned int V_43 = ~ 0 , V_44 = ~ 0 ;
unsigned int V_45 , V_46 ;
unsigned int V_10 , V_47 ;
for ( V_10 = 0 ; V_10 < V_39 - 1 ; V_10 ++ ) {
V_45 = F_1 ( V_8 , V_48 ) ;
V_47 = V_45 & 0xf0000 ;
V_47 = V_47 >> 0x10 ;
if ( ( V_47 >= 0 ) && ( V_47 < V_8 -> V_12 ) ) {
V_45 &= 0xfff ;
V_46 = abs ( V_45 - V_41 ) ;
if ( V_46 < V_43 ) {
V_43 = V_46 ;
* V_37 = V_45 ;
}
V_41 = V_45 ;
}
V_45 = F_1 ( V_8 , V_49 ) ;
V_47 = V_45 & 0xf0000 ;
V_47 = V_47 >> 0x10 ;
if ( ( V_47 >= V_8 -> V_12 ) &&
( V_47 < ( 2 * V_8 -> V_12 - 1 ) ) ) {
V_45 &= 0xfff ;
V_46 = abs ( V_45 - V_42 ) ;
if ( V_46 < V_44 ) {
V_44 = V_46 ;
* V_38 = V_45 ;
}
V_42 = V_45 ;
}
}
}
static T_1 F_9 ( int V_50 , void * V_51 )
{
struct V_1 * V_8 = V_51 ;
struct V_52 * V_52 = V_8 -> V_53 ;
unsigned int V_54 , V_55 = 0 ;
unsigned int V_37 = 0 , V_38 = 0 ;
unsigned int V_56 , V_57 , V_58 ;
unsigned int V_59 ;
unsigned int V_60 , V_61 ;
int V_10 ;
V_54 = F_1 ( V_8 , V_62 ) ;
if ( V_54 & V_63 ) {
F_8 ( V_8 , & V_37 , & V_38 ) ;
V_56 = F_1 ( V_8 , V_48 ) & 0xfff ;
V_57 = F_1 ( V_8 , V_49 ) & 0xfff ;
V_60 = F_1 ( V_8 , V_64 ) ;
for ( V_10 = 0 ; V_10 < V_60 ; V_10 ++ )
F_1 ( V_8 , V_49 ) ;
V_61 = F_1 ( V_8 , V_40 ) ;
for ( V_10 = 0 ; V_10 < V_61 ; V_10 ++ )
F_1 ( V_8 , V_48 ) ;
if ( V_8 -> V_65 && V_56 != 0 && V_57 != 0 ) {
V_58 = V_57 - V_56 ;
V_58 *= V_37 ;
V_58 *= V_8 -> V_66 ;
V_58 /= V_56 ;
V_58 = ( V_58 + 2047 ) >> 12 ;
if ( V_58 <= V_67 ) {
F_10 ( V_52 , V_68 , V_37 ) ;
F_10 ( V_52 , V_69 , V_38 ) ;
F_10 ( V_52 , V_70 , V_58 ) ;
F_11 ( V_52 , V_71 , 1 ) ;
F_12 ( V_52 ) ;
}
}
V_55 |= V_63 ;
}
F_13 ( V_72 ) ;
V_54 = F_1 ( V_8 , V_73 ) ;
if ( V_54 & V_74 ) {
V_59 = F_1 ( V_8 , V_75 ) ;
if ( V_59 == V_76 ) {
V_8 -> V_65 = false ;
F_11 ( V_52 , V_71 , 0 ) ;
F_10 ( V_52 , V_70 , 0 ) ;
F_12 ( V_52 ) ;
} else {
V_8 -> V_65 = true ;
}
V_55 |= V_74 ;
}
F_3 ( V_8 , V_62 , V_55 ) ;
F_3 ( V_8 , V_35 , V_36 ) ;
return V_77 ;
}
static int F_14 ( struct V_78 * V_79 )
{
struct V_1 * V_8 ;
struct V_52 * V_52 ;
struct V_80 * V_81 = V_79 -> V_51 . V_82 ;
struct V_83 * V_84 ;
int V_85 ;
V_84 = V_81 -> V_51 -> V_82 ;
if ( ! V_84 ) {
F_15 ( & V_79 -> V_51 , L_1 ) ;
return - V_86 ;
}
V_8 = F_16 ( sizeof( struct V_1 ) , V_87 ) ;
V_52 = F_17 () ;
if ( ! V_8 || ! V_52 ) {
F_15 ( & V_79 -> V_51 , L_2 ) ;
V_85 = - V_88 ;
goto V_89;
}
V_81 -> V_6 = V_8 ;
V_8 -> V_4 = V_81 ;
V_8 -> V_53 = V_52 ;
V_8 -> V_50 = V_81 -> V_50 ;
V_8 -> V_16 = V_84 -> V_90 -> V_16 ;
V_8 -> V_66 = V_84 -> V_90 -> V_66 ;
V_8 -> V_12 = V_84 -> V_90 -> V_12 ;
V_85 = F_18 ( V_8 -> V_50 , F_9 ,
0 , V_79 -> V_51 . V_91 -> V_92 , V_8 ) ;
if ( V_85 ) {
F_15 ( & V_79 -> V_51 , L_3 ) ;
goto V_89;
}
F_3 ( V_8 , V_93 , V_63 ) ;
F_5 ( V_8 ) ;
F_3 ( V_8 , V_94 , V_8 -> V_12 ) ;
V_52 -> V_92 = L_4 ;
V_52 -> V_51 . V_95 = & V_79 -> V_51 ;
V_52 -> V_96 [ 0 ] = F_19 ( V_97 ) | F_19 ( V_98 ) ;
V_52 -> V_99 [ F_20 ( V_71 ) ] = F_19 ( V_71 ) ;
F_21 ( V_52 , V_68 , 0 , V_67 , 0 , 0 ) ;
F_21 ( V_52 , V_69 , 0 , V_67 , 0 , 0 ) ;
F_21 ( V_52 , V_70 , 0 , V_67 , 0 , 0 ) ;
V_85 = F_22 ( V_52 ) ;
if ( V_85 )
goto V_100;
F_23 ( V_79 , V_8 ) ;
return 0 ;
V_100:
F_24 ( V_8 -> V_50 , V_8 ) ;
V_89:
F_25 ( V_52 ) ;
F_26 ( V_8 ) ;
return V_85 ;
}
static int F_27 ( struct V_78 * V_79 )
{
struct V_80 * V_81 = V_79 -> V_51 . V_82 ;
struct V_1 * V_8 = V_81 -> V_6 ;
F_24 ( V_8 -> V_50 , V_8 ) ;
F_28 ( V_8 -> V_53 ) ;
F_23 ( V_79 , NULL ) ;
F_26 ( V_8 ) ;
return 0 ;
}
static int F_29 ( struct V_101 * V_51 )
{
struct V_80 * V_81 = V_51 -> V_82 ;
struct V_1 * V_8 = V_81 -> V_6 ;
unsigned int V_102 ;
if ( F_30 ( V_81 -> V_51 ) ) {
V_102 = F_1 ( V_8 , V_93 ) ;
F_3 ( V_8 , V_93 ,
( V_102 | V_103 ) ) ;
F_3 ( V_8 , V_104 , V_105 ) ;
}
return 0 ;
}
static int F_31 ( struct V_101 * V_51 )
{
struct V_80 * V_81 = V_51 -> V_82 ;
struct V_1 * V_8 = V_81 -> V_6 ;
if ( F_30 ( V_81 -> V_51 ) ) {
F_3 ( V_8 , V_104 ,
0x00 ) ;
F_3 ( V_8 , V_106 , V_103 ) ;
}
F_5 ( V_8 ) ;
F_3 ( V_8 , V_94 ,
V_8 -> V_12 ) ;
return 0 ;
}
