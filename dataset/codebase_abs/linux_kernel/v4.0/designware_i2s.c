static inline void F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( struct V_4 * V_5 , T_2 V_6 )
{
T_2 V_7 = 0 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_6 ( V_7 ) , 0 ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_7 ( V_7 ) , 0 ) ;
}
}
static inline void F_8 ( struct V_4 * V_5 , T_2 V_6 )
{
T_2 V_7 = 0 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_9 ( V_7 ) , 0 ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_10 ( V_7 ) , 0 ) ;
}
}
static void F_11 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
F_1 ( V_5 -> V_9 , V_12 , 1 ) ;
if ( V_11 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_13 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_14 , 1 ) ;
F_1 ( V_5 -> V_9 , V_15 , 1 ) ;
}
static void F_12 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
T_2 V_7 = 0 , V_16 ;
F_8 ( V_5 , V_11 -> V_6 ) ;
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , V_13 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_7 ) , V_16 | 0x30 ) ;
}
} else {
F_1 ( V_5 -> V_9 , V_14 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_7 ) , V_16 | 0x03 ) ;
}
}
if ( ! V_5 -> V_17 ) {
F_1 ( V_5 -> V_9 , V_15 , 0 ) ;
F_1 ( V_5 -> V_9 , V_12 , 0 ) ;
}
}
static int F_14 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = F_15 ( V_19 ) ;
union V_20 * V_21 = NULL ;
if ( ! ( V_5 -> V_22 & V_23 ) &&
( V_11 -> V_6 == V_24 ) )
return - V_25 ;
if ( ! ( V_5 -> V_22 & V_26 ) &&
( V_11 -> V_6 == V_8 ) )
return - V_25 ;
if ( V_11 -> V_6 == V_8 )
V_21 = & V_5 -> V_27 ;
else if ( V_11 -> V_6 == V_24 )
V_21 = & V_5 -> V_28 ;
F_16 ( V_19 , V_11 , ( void * ) V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 ,
struct V_29 * V_30 , struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
struct V_32 * V_33 = & V_5 -> V_33 ;
T_2 V_34 , V_35 , V_36 , V_16 ;
int V_37 ;
switch ( F_18 ( V_30 ) ) {
case V_38 :
V_33 -> V_39 = 16 ;
V_34 = 0x00 ;
V_35 = 0x02 ;
break;
case V_40 :
V_33 -> V_39 = 24 ;
V_34 = 0x08 ;
V_35 = 0x04 ;
break;
case V_41 :
V_33 -> V_39 = 32 ;
V_34 = 0x10 ;
V_35 = 0x05 ;
break;
default:
F_19 ( V_5 -> V_5 , L_1 ) ;
return - V_25 ;
}
V_33 -> V_42 = F_20 ( V_30 ) ;
switch ( V_33 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
break;
default:
F_19 ( V_5 -> V_5 , L_2 ) ;
return - V_25 ;
}
F_5 ( V_5 , V_11 -> V_6 ) ;
for ( V_36 = 0 ; V_36 < ( V_33 -> V_42 / 2 ) ; V_36 ++ ) {
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , F_21 ( V_36 ) ,
V_35 ) ;
F_1 ( V_5 -> V_9 , F_22 ( V_36 ) , 0x02 ) ;
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_36 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_36 ) , V_16 & ~ 0x30 ) ;
F_1 ( V_5 -> V_9 , F_6 ( V_36 ) , 1 ) ;
} else {
F_1 ( V_5 -> V_9 , F_23 ( V_36 ) ,
V_35 ) ;
F_1 ( V_5 -> V_9 , F_24 ( V_36 ) , 0x07 ) ;
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_36 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_36 ) , V_16 & ~ 0x03 ) ;
F_1 ( V_5 -> V_9 , F_7 ( V_36 ) , 1 ) ;
}
}
F_1 ( V_5 -> V_9 , V_47 , V_34 ) ;
V_33 -> V_48 = F_25 ( V_30 ) ;
if ( V_5 -> V_49 ) {
V_37 = V_5 -> V_49 ( V_33 ) ;
if ( V_37 < 0 ) {
F_19 ( V_5 -> V_5 , L_3 ) ;
return V_37 ;
}
} else {
T_2 V_50 = V_33 -> V_48 * V_33 -> V_39 * 2 ;
V_37 = F_26 ( V_5 -> V_51 , V_50 ) ;
if ( V_37 ) {
F_19 ( V_5 -> V_5 , L_4 ,
V_37 ) ;
return V_37 ;
}
}
return 0 ;
}
static void F_27 ( struct V_10 * V_11 ,
struct V_18 * V_31 )
{
F_16 ( V_31 , V_11 , NULL ) ;
}
static int F_28 ( struct V_10 * V_11 ,
struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
if ( V_11 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_52 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_53 , 1 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 ,
int V_54 , struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
int V_37 = 0 ;
switch ( V_54 ) {
case V_55 :
case V_56 :
case V_57 :
V_5 -> V_17 ++ ;
F_11 ( V_5 , V_11 ) ;
break;
case V_58 :
case V_59 :
case V_60 :
V_5 -> V_17 -- ;
F_12 ( V_5 , V_11 ) ;
break;
default:
V_37 = - V_25 ;
break;
}
return V_37 ;
}
static int F_30 ( struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
F_31 ( V_5 -> V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
F_33 ( V_5 -> V_51 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
unsigned int V_63 )
{
T_2 V_64 = F_3 ( V_5 -> V_9 , V_65 ) ;
T_2 V_66 = F_3 ( V_5 -> V_9 , V_67 ) ;
T_2 V_68 ;
if ( F_35 ( V_64 ) ) {
F_36 ( V_5 -> V_5 , L_5 ) ;
V_68 = F_37 ( V_64 ) ;
if ( F_38 ( V_68 >= F_39 ( V_69 ) ) )
return - V_25 ;
V_62 -> V_70 . V_71 = V_72 ;
V_62 -> V_70 . V_73 =
1 << ( F_40 ( V_64 ) + 1 ) ;
V_62 -> V_70 . V_69 = V_69 [ V_68 ] ;
V_62 -> V_70 . V_63 = V_63 ;
}
if ( F_41 ( V_64 ) ) {
F_36 ( V_5 -> V_5 , L_6 ) ;
V_68 = F_42 ( V_66 ) ;
if ( F_38 ( V_68 >= F_39 ( V_69 ) ) )
return - V_25 ;
V_62 -> V_74 . V_71 = V_72 ;
V_62 -> V_74 . V_73 =
1 << ( F_43 ( V_64 ) + 1 ) ;
V_62 -> V_74 . V_69 = V_69 [ V_68 ] ;
V_62 -> V_74 . V_63 = V_63 ;
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
T_2 V_64 = F_3 ( V_5 -> V_9 , V_65 ) ;
T_2 V_68 = F_45 ( V_64 ) ;
int V_37 ;
if ( F_38 ( V_68 >= F_39 ( V_79 ) ) )
return - V_25 ;
V_37 = F_34 ( V_5 , V_62 , V_78 -> V_80 ) ;
if ( V_37 < 0 )
return V_37 ;
V_5 -> V_27 . V_81 . V_82 = V_78 -> V_27 ;
V_5 -> V_28 . V_81 . V_82 = V_78 -> V_28 ;
V_5 -> V_27 . V_81 . V_83 = V_76 -> V_84 + V_85 ;
V_5 -> V_28 . V_81 . V_83 = V_76 -> V_84 + V_86 ;
V_5 -> V_27 . V_81 . V_87 = 16 ;
V_5 -> V_28 . V_81 . V_87 = 16 ;
V_5 -> V_27 . V_81 . V_88 = V_79 [ V_68 ] ;
V_5 -> V_28 . V_81 . V_88 = V_79 [ V_68 ] ;
V_5 -> V_27 . V_81 . V_89 = V_78 -> V_89 ;
V_5 -> V_28 . V_81 . V_89 = V_78 -> V_89 ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
struct V_75 * V_76 )
{
T_2 V_64 = F_3 ( V_5 -> V_9 , V_65 ) ;
T_2 V_66 = F_3 ( V_5 -> V_9 , V_67 ) ;
T_2 V_90 = 1 << ( 1 + F_47 ( V_64 ) ) ;
T_2 V_68 = F_45 ( V_64 ) ;
T_2 V_91 ;
int V_37 ;
if ( F_38 ( V_68 >= F_39 ( V_79 ) ) )
return - V_25 ;
V_37 = F_34 ( V_5 , V_62 , V_92 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( F_35 ( V_64 ) ) {
V_91 = F_37 ( V_64 ) ;
V_5 -> V_22 |= V_26 ;
V_5 -> V_27 . V_93 . V_83 = V_76 -> V_84 + V_85 ;
V_5 -> V_27 . V_93 . V_88 = V_79 [ V_68 ] ;
V_5 -> V_27 . V_93 . V_94 = L_7 ;
V_5 -> V_27 . V_93 . V_95 = V_90 *
( V_96 [ V_91 ] ) >> 8 ;
V_5 -> V_27 . V_93 . V_97 = 16 ;
}
if ( F_41 ( V_64 ) ) {
V_91 = F_42 ( V_66 ) ;
V_5 -> V_22 |= V_23 ;
V_5 -> V_28 . V_93 . V_83 = V_76 -> V_84 + V_86 ;
V_5 -> V_28 . V_93 . V_88 = V_79 [ V_68 ] ;
V_5 -> V_28 . V_93 . V_94 = L_8 ;
V_5 -> V_28 . V_93 . V_95 = V_90 *
( V_96 [ V_91 ] >> 8 ) ;
V_5 -> V_28 . V_93 . V_97 = 16 ;
}
return 0 ;
}
static int F_48 ( struct V_98 * V_99 )
{
const struct V_77 * V_78 = V_99 -> V_5 . V_100 ;
struct V_4 * V_5 ;
struct V_75 * V_76 ;
int V_37 ;
struct V_61 * V_62 ;
V_5 = F_49 ( & V_99 -> V_5 , sizeof( * V_5 ) , V_101 ) ;
if ( ! V_5 ) {
F_50 ( & V_99 -> V_5 , L_9 ) ;
return - V_102 ;
}
V_62 = F_49 ( & V_99 -> V_5 , sizeof( * V_62 ) , V_101 ) ;
if ( ! V_62 )
return - V_102 ;
V_62 -> V_103 = & V_104 ;
V_62 -> V_105 = F_30 ;
V_62 -> V_106 = F_32 ;
V_76 = F_51 ( V_99 , V_107 , 0 ) ;
V_5 -> V_9 = F_52 ( & V_99 -> V_5 , V_76 ) ;
if ( F_53 ( V_5 -> V_9 ) )
return F_54 ( V_5 -> V_9 ) ;
V_5 -> V_5 = & V_99 -> V_5 ;
if ( V_78 ) {
V_37 = F_44 ( V_5 , V_62 , V_76 , V_78 ) ;
if ( V_37 < 0 )
return V_37 ;
V_5 -> V_22 = V_78 -> V_108 ;
V_5 -> V_49 = V_78 -> V_49 ;
if ( ! V_5 -> V_49 ) {
F_19 ( & V_99 -> V_5 , L_10 ) ;
return - V_109 ;
}
V_5 -> V_51 = F_55 ( & V_99 -> V_5 , NULL ) ;
} else {
V_37 = F_46 ( V_5 , V_62 , V_76 ) ;
if ( V_37 < 0 )
return V_37 ;
V_5 -> V_51 = F_55 ( & V_99 -> V_5 , L_11 ) ;
}
if ( F_53 ( V_5 -> V_51 ) )
return F_54 ( V_5 -> V_51 ) ;
V_37 = F_56 ( V_5 -> V_51 ) ;
if ( V_37 < 0 )
return V_37 ;
F_57 ( & V_99 -> V_5 , V_5 ) ;
V_37 = F_58 ( & V_99 -> V_5 , & V_110 ,
V_62 , 1 ) ;
if ( V_37 != 0 ) {
F_19 ( & V_99 -> V_5 , L_12 ) ;
goto V_111;
}
if ( ! V_78 ) {
V_37 = F_59 ( & V_99 -> V_5 , NULL , 0 ) ;
if ( V_37 ) {
F_19 ( & V_99 -> V_5 ,
L_13 , V_37 ) ;
goto V_111;
}
}
return 0 ;
V_111:
F_60 ( V_5 -> V_51 ) ;
return V_37 ;
}
static int F_61 ( struct V_98 * V_99 )
{
struct V_4 * V_5 = F_62 ( & V_99 -> V_5 ) ;
F_60 ( V_5 -> V_51 ) ;
return 0 ;
}
