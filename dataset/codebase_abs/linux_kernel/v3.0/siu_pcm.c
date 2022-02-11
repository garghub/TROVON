static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_9 ;
T_1 V_10 ;
if ( ! V_8 -> V_11 )
return - V_12 ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 & ~ 0x0c180c18 ) ;
F_4 ( L_1 , V_14 ,
V_10 , V_10 & ~ 0x0c180c18 ) ;
V_8 -> V_11 = 0 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = & V_2 -> V_9 ;
if ( V_8 -> V_11 )
return - V_12 ;
V_2 -> V_9 . V_15 = 0 ;
V_8 -> V_11 = V_16 ;
F_6 ( & V_8 -> V_17 ) ;
return 0 ;
}
static void F_7 ( void * V_18 )
{
struct V_8 * V_8 = V_18 ;
if ( ! V_8 -> V_11 )
return;
if ( ++ V_8 -> V_15 >=
F_8 ( V_8 -> V_19 ,
V_8 -> V_20 ) )
V_8 -> V_15 = 0 ;
F_4 ( L_2 ,
V_14 , V_8 -> V_15 ,
V_8 -> V_15 * V_8 -> V_20 ,
V_8 -> V_19 , V_8 -> V_21 ) ;
F_6 ( & V_8 -> V_17 ) ;
F_9 ( V_8 -> V_22 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_3 V_23 , T_1 V_24 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_9 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_30 * V_31 ;
T_4 V_21 ;
struct V_32 V_33 ;
T_1 V_10 ;
F_11 ( & V_33 , 1 ) ;
F_12 ( & V_33 , F_13 ( F_14 ( V_23 ) ) ,
V_24 , F_15 ( V_23 ) ) ;
F_16 ( & V_33 ) = V_24 ;
F_17 ( & V_33 ) = V_23 ;
V_31 = V_8 -> V_34 -> V_26 -> V_35 ( V_8 -> V_34 ,
& V_33 , 1 , V_36 , V_37 | V_38 ) ;
if ( ! V_31 ) {
F_18 ( V_27 , L_3 ) ;
return - V_39 ;
}
V_31 -> V_40 = F_7 ;
V_31 -> V_41 = V_8 ;
V_21 = V_31 -> V_42 ( V_31 ) ;
if ( V_21 < 0 ) {
F_18 ( V_27 , L_4 ) ;
return V_21 ;
}
V_8 -> V_43 = V_31 ;
V_8 -> V_21 = V_21 ;
F_19 ( V_8 -> V_34 ) ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 | ( V_2 -> V_10 & 0x0c180c18 ) ) ;
F_20 ( V_27 , L_1 , V_14 ,
V_10 , V_10 | ( V_2 -> V_10 & 0x0c180c18 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_23 , T_5 V_24 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_44 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_30 * V_31 ;
T_4 V_21 ;
struct V_32 V_33 ;
T_1 V_10 ;
F_20 ( V_27 , L_5 , V_14 , V_24 , ( unsigned long long ) V_23 ) ;
F_11 ( & V_33 , 1 ) ;
F_12 ( & V_33 , F_13 ( F_14 ( V_23 ) ) ,
V_24 , F_15 ( V_23 ) ) ;
F_16 ( & V_33 ) = V_24 ;
F_17 ( & V_33 ) = V_23 ;
V_31 = V_8 -> V_34 -> V_26 -> V_35 ( V_8 -> V_34 ,
& V_33 , 1 , V_45 , V_37 | V_38 ) ;
if ( ! V_31 ) {
F_18 ( V_27 , L_6 ) ;
return - V_39 ;
}
V_31 -> V_40 = F_7 ;
V_31 -> V_41 = V_8 ;
V_21 = V_31 -> V_42 ( V_31 ) ;
if ( V_21 < 0 ) {
F_18 ( V_27 , L_7 ) ;
return V_21 ;
}
V_8 -> V_43 = V_31 ;
V_8 -> V_21 = V_21 ;
F_19 ( V_8 -> V_34 ) ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , F_2 ( V_6 + V_13 ) |
( V_2 -> V_10 & 0x13071307 ) ) ;
F_20 ( V_27 , L_1 , V_14 ,
V_10 , V_10 | ( V_2 -> V_10 & 0x13071307 ) ) ;
return 0 ;
}
static void F_22 ( unsigned long V_46 )
{
struct V_8 * V_8 = (struct V_8 * ) V_46 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_47 * V_48 = V_22 -> V_49 ;
struct V_1 * V_2 = F_23 ( V_22 ) ;
F_20 ( V_27 , L_8 , V_14 , V_8 -> V_11 ) ;
if ( ! V_8 -> V_11 ) {
F_20 ( V_27 , L_9 , V_14 ) ;
return;
}
if ( V_22 -> V_50 == V_51 ) {
T_3 V_23 ;
T_5 V_52 ;
T_6 * V_53 ;
V_23 = ( T_3 ) F_24 ( V_48 -> V_54 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ;
V_53 = F_24 ( V_48 -> V_55 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ;
V_52 = V_8 -> V_20 ;
F_21 ( V_2 , V_23 , V_52 ) ;
} else {
F_10 ( V_2 ,
( T_3 ) F_24 ( V_48 -> V_54 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ,
V_8 -> V_20 ) ;
}
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = & V_2 -> V_44 ;
if ( V_8 -> V_56 > 0x1000000 )
return - V_57 ;
if ( V_8 -> V_11 )
return - V_12 ;
V_8 -> V_15 = 0 ;
V_8 -> V_11 = V_58 ;
F_6 ( & V_8 -> V_17 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_44 ;
struct V_26 * V_27 = V_8 -> V_22 -> V_28 -> V_29 -> V_27 ;
T_1 V_10 ;
if ( ! V_8 -> V_11 )
return - V_12 ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 & ~ 0x13071307 ) ;
F_20 ( V_27 , L_1 , V_14 ,
V_10 , V_10 & ~ 0x13071307 ) ;
V_8 -> V_11 = 0 ;
return 0 ;
}
static int F_27 ( struct V_25 * V_59 ,
struct V_60 * V_61 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
int V_62 ;
F_20 ( V_27 , L_10 , V_14 , V_4 -> V_63 ) ;
V_62 = F_28 ( V_59 , F_29 ( V_61 ) ) ;
if ( V_62 < 0 )
F_18 ( V_27 , L_11 ) ;
return V_62 ;
}
static int F_30 ( struct V_25 * V_59 )
{
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_23 ( V_59 ) ;
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
struct V_8 * V_8 ;
if ( V_59 -> V_50 == V_64 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_44 ;
F_20 ( V_27 , L_10 , V_14 , V_4 -> V_63 ) ;
return F_31 ( V_59 ) ;
}
static bool F_32 ( struct V_65 * V_34 , void * V_66 )
{
struct V_67 * V_68 = V_66 ;
F_4 ( L_12 , V_14 , V_68 -> V_69 ) ;
if ( F_33 ( V_68 -> V_70 != V_34 -> V_26 -> V_27 ) )
return false ;
V_34 -> V_71 = V_68 ;
return true ;
}
static int F_34 ( struct V_25 * V_59 )
{
struct V_72 * V_73 = V_59 -> V_74 ;
struct V_75 * V_76 = V_73 -> V_77 -> V_27 -> V_78 ;
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_23 ( V_59 ) ;
struct V_8 * V_8 ;
T_1 V_79 = V_4 -> V_63 ;
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
T_7 V_80 ;
struct V_67 * V_68 ;
F_35 ( V_80 ) ;
F_36 ( V_81 , V_80 ) ;
F_20 ( V_27 , L_13 , V_14 , V_79 , V_2 ) ;
if ( V_59 -> V_50 == V_64 ) {
V_8 = & V_2 -> V_9 ;
V_68 = & V_8 -> V_68 ;
V_68 -> V_69 = V_79 ? V_76 -> V_82 :
V_76 -> V_83 ;
} else {
V_8 = & V_2 -> V_44 ;
V_68 = & V_8 -> V_68 ;
V_68 -> V_69 = V_79 ? V_76 -> V_84 :
V_76 -> V_85 ;
}
V_68 -> V_70 = V_76 -> V_70 ;
V_8 -> V_34 = F_37 ( V_80 , F_32 , V_68 ) ;
if ( ! V_8 -> V_34 ) {
F_18 ( V_27 , L_14 ) ;
return - V_86 ;
}
V_8 -> V_22 = V_59 ;
return 0 ;
}
static int F_38 ( struct V_25 * V_59 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
struct V_1 * V_2 = F_23 ( V_59 ) ;
struct V_8 * V_8 ;
F_20 ( V_27 , L_10 , V_14 , V_4 -> V_63 ) ;
if ( V_59 -> V_50 == V_64 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_44 ;
F_39 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
V_8 -> V_22 = NULL ;
return 0 ;
}
static int F_40 ( struct V_25 * V_59 )
{
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_23 ( V_59 ) ;
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
struct V_47 * V_48 = V_59 -> V_49 ;
struct V_8 * V_8 ;
T_8 V_56 ;
if ( V_59 -> V_50 == V_64 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_44 ;
V_48 = V_8 -> V_22 -> V_49 ;
V_8 -> V_19 = F_41 ( V_59 ) ;
V_8 -> V_20 = F_42 ( V_59 ) ;
F_20 ( V_27 , L_15 , V_14 ,
V_4 -> V_63 , V_48 -> V_87 , V_8 -> V_20 ) ;
if ( V_8 -> V_19 % V_8 -> V_20 ) {
F_18 ( V_27 , L_16 ,
V_14 , V_8 -> V_19 ,
V_8 -> V_20 ) ;
return - V_57 ;
}
V_56 = F_43 ( V_48 , V_8 -> V_20 ) ;
if ( ! V_56 || V_56 > 0x1000000 )
return - V_57 ;
V_8 -> V_88 = V_48 -> V_88 ;
V_8 -> V_56 = V_56 ;
F_20 ( V_27 , L_17
L_18 , V_4 -> V_63 ,
( unsigned long ) V_48 -> V_54 , V_8 -> V_19 ,
V_8 -> V_20 ,
V_8 -> V_88 , V_48 -> V_87 , ( int ) V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_25 * V_59 , int V_89 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
struct V_1 * V_2 = F_23 ( V_59 ) ;
int V_62 ;
F_20 ( V_27 , L_19 , V_14 ,
V_4 -> V_63 , V_2 , V_89 ) ;
switch ( V_89 ) {
case V_90 :
if ( V_59 -> V_50 == V_64 )
V_62 = F_5 ( V_2 ) ;
else
V_62 = F_25 ( V_2 ) ;
if ( V_62 < 0 )
F_45 ( V_27 , L_20 ,
V_14 , V_4 -> V_63 ) ;
break;
case V_91 :
if ( V_59 -> V_50 == V_64 )
F_1 ( V_2 ) ;
else
F_26 ( V_2 ) ;
V_62 = 0 ;
break;
default:
F_18 ( V_27 , L_21 , V_14 , V_89 ) ;
V_62 = - V_57 ;
}
return V_62 ;
}
static T_9 F_46 ( struct V_25 * V_59 )
{
struct V_26 * V_27 = V_59 -> V_28 -> V_29 -> V_27 ;
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = F_23 ( V_59 ) ;
struct V_47 * V_48 = V_59 -> V_49 ;
T_5 V_92 ;
struct V_8 * V_8 ;
if ( V_59 -> V_50 == V_64 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_44 ;
V_92 = F_24 ( V_48 -> V_54 ,
V_8 -> V_15 ,
V_8 -> V_20 ) - V_48 -> V_54 ;
F_20 ( V_27 ,
L_22 ,
V_14 , V_4 -> V_63 , F_2 ( V_6 + V_93 ) ,
F_2 ( V_6 + V_94 ) , V_92 , V_8 -> V_19 ,
V_8 -> V_21 ) ;
if ( V_92 >= V_8 -> V_19 )
V_92 = 0 ;
return F_43 ( V_59 -> V_49 , V_92 ) ;
}
static int F_47 ( struct V_95 * V_29 , struct V_96 * V_97 ,
struct V_98 * V_28 )
{
struct V_3 * V_4 = V_5 ;
struct V_99 * V_100 = F_48 ( V_29 -> V_27 ) ;
int V_62 ;
int V_101 ;
if ( V_100 -> V_102 < 0 || V_100 -> V_102 >= V_103 )
return - V_57 ;
V_4 -> V_63 = V_100 -> V_102 ;
for ( V_101 = V_100 -> V_102 ; V_101 < V_100 -> V_102 + 1 ; V_101 ++ ) {
struct V_1 * * V_2 = & V_104 [ V_101 ] ;
V_62 = F_49 ( V_101 , V_2 , V_29 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_50 ( V_28 ,
V_105 , NULL ,
V_106 , V_106 ) ;
if ( V_62 < 0 ) {
F_18 ( V_29 -> V_27 ,
L_23 ,
V_62 ) ;
goto V_107;
}
( * V_2 ) -> V_28 = V_28 ;
F_51 ( & ( * V_2 ) -> V_9 . V_17 , F_22 ,
( unsigned long ) & ( * V_2 ) -> V_9 ) ;
F_51 ( & ( * V_2 ) -> V_44 . V_17 , F_22 ,
( unsigned long ) & ( * V_2 ) -> V_44 ) ;
}
F_52 ( V_29 -> V_27 , L_24 ) ;
return 0 ;
V_107:
F_53 ( V_104 [ V_100 -> V_102 ] ) ;
F_18 ( V_29 -> V_27 , L_25 ) ;
return V_62 ;
}
static void F_54 ( struct V_98 * V_28 )
{
struct V_99 * V_100 = F_48 ( V_28 -> V_29 -> V_27 ) ;
struct V_1 * V_2 = V_104 [ V_100 -> V_102 ] ;
F_55 ( & V_2 -> V_44 . V_17 ) ;
F_55 ( & V_2 -> V_9 . V_17 ) ;
F_53 ( V_2 ) ;
F_56 ( V_28 ) ;
F_20 ( V_28 -> V_29 -> V_27 , L_26 , V_14 ) ;
}
