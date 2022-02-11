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
V_31 = F_18 ( V_8 -> V_34 ,
& V_33 , 1 , V_35 , V_36 | V_37 ) ;
if ( ! V_31 ) {
F_19 ( V_27 , L_3 ) ;
return - V_38 ;
}
V_31 -> V_39 = F_7 ;
V_31 -> V_40 = V_8 ;
V_21 = V_31 -> V_41 ( V_31 ) ;
if ( V_21 < 0 ) {
F_19 ( V_27 , L_4 ) ;
return V_21 ;
}
V_8 -> V_42 = V_31 ;
V_8 -> V_21 = V_21 ;
F_20 ( V_8 -> V_34 ) ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 | ( V_2 -> V_10 & 0x0c180c18 ) ) ;
F_21 ( V_27 , L_1 , V_14 ,
V_10 , V_10 | ( V_2 -> V_10 & 0x0c180c18 ) ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
T_3 V_23 , T_5 V_24 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_43 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_30 * V_31 ;
T_4 V_21 ;
struct V_32 V_33 ;
T_1 V_10 ;
F_21 ( V_27 , L_5 , V_14 , V_24 , ( unsigned long long ) V_23 ) ;
F_11 ( & V_33 , 1 ) ;
F_12 ( & V_33 , F_13 ( F_14 ( V_23 ) ) ,
V_24 , F_15 ( V_23 ) ) ;
F_16 ( & V_33 ) = V_24 ;
F_17 ( & V_33 ) = V_23 ;
V_31 = F_18 ( V_8 -> V_34 ,
& V_33 , 1 , V_44 , V_36 | V_37 ) ;
if ( ! V_31 ) {
F_19 ( V_27 , L_6 ) ;
return - V_38 ;
}
V_31 -> V_39 = F_7 ;
V_31 -> V_40 = V_8 ;
V_21 = V_31 -> V_41 ( V_31 ) ;
if ( V_21 < 0 ) {
F_19 ( V_27 , L_7 ) ;
return V_21 ;
}
V_8 -> V_42 = V_31 ;
V_8 -> V_21 = V_21 ;
F_20 ( V_8 -> V_34 ) ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , F_2 ( V_6 + V_13 ) |
( V_2 -> V_10 & 0x13071307 ) ) ;
F_21 ( V_27 , L_1 , V_14 ,
V_10 , V_10 | ( V_2 -> V_10 & 0x13071307 ) ) ;
return 0 ;
}
static void F_23 ( unsigned long V_45 )
{
struct V_8 * V_8 = (struct V_8 * ) V_45 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_46 * V_47 = V_22 -> V_48 ;
struct V_1 * V_2 = F_24 ( V_22 ) ;
F_21 ( V_27 , L_8 , V_14 , V_8 -> V_11 ) ;
if ( ! V_8 -> V_11 ) {
F_21 ( V_27 , L_9 , V_14 ) ;
return;
}
if ( V_22 -> V_49 == V_50 ) {
T_3 V_23 ;
T_5 V_51 ;
T_6 * V_52 ;
V_23 = ( T_3 ) F_25 ( V_47 -> V_53 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ;
V_52 = F_25 ( V_47 -> V_54 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ;
V_51 = V_8 -> V_20 ;
F_22 ( V_2 , V_23 , V_51 ) ;
} else {
F_10 ( V_2 ,
( T_3 ) F_25 ( V_47 -> V_53 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ,
V_8 -> V_20 ) ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = & V_2 -> V_43 ;
if ( V_8 -> V_55 > 0x1000000 )
return - V_56 ;
if ( V_8 -> V_11 )
return - V_12 ;
V_8 -> V_15 = 0 ;
V_8 -> V_11 = V_57 ;
F_6 ( & V_8 -> V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_43 ;
struct V_26 * V_27 = V_8 -> V_22 -> V_28 -> V_29 -> V_27 ;
T_1 V_10 ;
if ( ! V_8 -> V_11 )
return - V_12 ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 & ~ 0x13071307 ) ;
F_21 ( V_27 , L_1 , V_14 ,
V_10 , V_10 & ~ 0x13071307 ) ;
V_8 -> V_11 = 0 ;
return 0 ;
}
static int F_28 ( struct V_25 * V_58 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
int V_61 ;
F_21 ( V_27 , L_10 , V_14 , V_4 -> V_62 ) ;
V_61 = F_29 ( V_58 , F_30 ( V_60 ) ) ;
if ( V_61 < 0 )
F_19 ( V_27 , L_11 ) ;
return V_61 ;
}
static int F_31 ( struct V_25 * V_58 )
{
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_24 ( V_58 ) ;
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
struct V_8 * V_8 ;
if ( V_58 -> V_49 == V_63 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_43 ;
F_21 ( V_27 , L_10 , V_14 , V_4 -> V_62 ) ;
return F_32 ( V_58 ) ;
}
static bool F_33 ( struct V_64 * V_34 , void * V_65 )
{
struct V_66 * V_67 = V_65 ;
F_4 ( L_12 , V_14 , V_67 -> V_68 . V_69 ) ;
V_34 -> V_70 = & V_67 -> V_68 ;
return true ;
}
static int F_34 ( struct V_25 * V_58 )
{
struct V_71 * V_72 = V_58 -> V_73 ;
struct V_74 * V_75 = V_72 -> V_76 -> V_27 -> V_77 ;
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_24 ( V_58 ) ;
struct V_8 * V_8 ;
T_1 V_78 = V_4 -> V_62 ;
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
T_7 V_79 ;
struct V_66 * V_67 ;
F_35 ( V_79 ) ;
F_36 ( V_80 , V_79 ) ;
F_21 ( V_27 , L_13 , V_14 , V_78 , V_2 ) ;
if ( V_58 -> V_49 == V_63 ) {
V_8 = & V_2 -> V_9 ;
V_67 = & V_8 -> V_67 ;
V_67 -> V_68 . V_69 = V_78 ? V_75 -> V_81 :
V_75 -> V_82 ;
} else {
V_8 = & V_2 -> V_43 ;
V_67 = & V_8 -> V_67 ;
V_67 -> V_68 . V_69 = V_78 ? V_75 -> V_83 :
V_75 -> V_84 ;
}
V_8 -> V_34 = F_37 ( V_79 , F_33 , V_67 ) ;
if ( ! V_8 -> V_34 ) {
F_19 ( V_27 , L_14 ) ;
return - V_85 ;
}
V_8 -> V_22 = V_58 ;
return 0 ;
}
static int F_38 ( struct V_25 * V_58 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
struct V_1 * V_2 = F_24 ( V_58 ) ;
struct V_8 * V_8 ;
F_21 ( V_27 , L_10 , V_14 , V_4 -> V_62 ) ;
if ( V_58 -> V_49 == V_63 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_43 ;
F_39 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
V_8 -> V_22 = NULL ;
return 0 ;
}
static int F_40 ( struct V_25 * V_58 )
{
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_24 ( V_58 ) ;
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
struct V_46 * V_47 = V_58 -> V_48 ;
struct V_8 * V_8 ;
T_8 V_55 ;
if ( V_58 -> V_49 == V_63 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_43 ;
V_47 = V_8 -> V_22 -> V_48 ;
V_8 -> V_19 = F_41 ( V_58 ) ;
V_8 -> V_20 = F_42 ( V_58 ) ;
F_21 ( V_27 , L_15 , V_14 ,
V_4 -> V_62 , V_47 -> V_86 , V_8 -> V_20 ) ;
if ( V_8 -> V_19 % V_8 -> V_20 ) {
F_19 ( V_27 , L_16 ,
V_14 , V_8 -> V_19 ,
V_8 -> V_20 ) ;
return - V_56 ;
}
V_55 = F_43 ( V_47 , V_8 -> V_20 ) ;
if ( ! V_55 || V_55 > 0x1000000 )
return - V_56 ;
V_8 -> V_87 = V_47 -> V_87 ;
V_8 -> V_55 = V_55 ;
F_21 ( V_27 , L_17
L_18 , V_4 -> V_62 ,
( unsigned long ) V_47 -> V_53 , V_8 -> V_19 ,
V_8 -> V_20 ,
V_8 -> V_87 , V_47 -> V_86 , ( int ) V_55 ) ;
return 0 ;
}
static int F_44 ( struct V_25 * V_58 , int V_88 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
struct V_1 * V_2 = F_24 ( V_58 ) ;
int V_61 ;
F_21 ( V_27 , L_19 , V_14 ,
V_4 -> V_62 , V_2 , V_88 ) ;
switch ( V_88 ) {
case V_89 :
if ( V_58 -> V_49 == V_63 )
V_61 = F_5 ( V_2 ) ;
else
V_61 = F_26 ( V_2 ) ;
if ( V_61 < 0 )
F_45 ( V_27 , L_20 ,
V_14 , V_4 -> V_62 ) ;
break;
case V_90 :
if ( V_58 -> V_49 == V_63 )
F_1 ( V_2 ) ;
else
F_27 ( V_2 ) ;
V_61 = 0 ;
break;
default:
F_19 ( V_27 , L_21 , V_14 , V_88 ) ;
V_61 = - V_56 ;
}
return V_61 ;
}
static T_9 F_46 ( struct V_25 * V_58 )
{
struct V_26 * V_27 = V_58 -> V_28 -> V_29 -> V_27 ;
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = F_24 ( V_58 ) ;
struct V_46 * V_47 = V_58 -> V_48 ;
T_5 V_91 ;
struct V_8 * V_8 ;
if ( V_58 -> V_49 == V_63 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_43 ;
V_91 = F_25 ( V_47 -> V_53 ,
V_8 -> V_15 ,
V_8 -> V_20 ) - V_47 -> V_53 ;
F_21 ( V_27 ,
L_22 ,
V_14 , V_4 -> V_62 , F_2 ( V_6 + V_92 ) ,
F_2 ( V_6 + V_93 ) , V_91 , V_8 -> V_19 ,
V_8 -> V_21 ) ;
if ( V_91 >= V_8 -> V_19 )
V_91 = 0 ;
return F_43 ( V_58 -> V_48 , V_91 ) ;
}
static int F_47 ( struct V_71 * V_72 )
{
struct V_94 * V_29 = V_72 -> V_29 -> V_94 ;
struct V_95 * V_28 = V_72 -> V_28 ;
struct V_3 * V_4 = V_5 ;
struct V_96 * V_97 = F_48 ( V_29 -> V_27 ) ;
int V_61 ;
int V_98 ;
if ( V_97 -> V_99 < 0 || V_97 -> V_99 >= V_100 )
return - V_56 ;
V_4 -> V_62 = V_97 -> V_99 ;
for ( V_98 = V_97 -> V_99 ; V_98 < V_97 -> V_99 + 1 ; V_98 ++ ) {
struct V_1 * * V_2 = & V_101 [ V_98 ] ;
V_61 = F_49 ( V_98 , V_2 , V_29 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_50 ( V_28 ,
V_102 , NULL ,
V_103 , V_103 ) ;
if ( V_61 < 0 ) {
F_19 ( V_29 -> V_27 ,
L_23 ,
V_61 ) ;
goto V_104;
}
( * V_2 ) -> V_28 = V_28 ;
F_51 ( & ( * V_2 ) -> V_9 . V_17 , F_23 ,
( unsigned long ) & ( * V_2 ) -> V_9 ) ;
F_51 ( & ( * V_2 ) -> V_43 . V_17 , F_23 ,
( unsigned long ) & ( * V_2 ) -> V_43 ) ;
}
F_52 ( V_29 -> V_27 , L_24 ) ;
return 0 ;
V_104:
F_53 ( V_101 [ V_97 -> V_99 ] ) ;
F_19 ( V_29 -> V_27 , L_25 ) ;
return V_61 ;
}
static void F_54 ( struct V_95 * V_28 )
{
struct V_96 * V_97 = F_48 ( V_28 -> V_29 -> V_27 ) ;
struct V_1 * V_2 = V_101 [ V_97 -> V_99 ] ;
F_55 ( & V_2 -> V_43 . V_17 ) ;
F_55 ( & V_2 -> V_9 . V_17 ) ;
F_53 ( V_2 ) ;
F_56 ( V_28 ) ;
F_21 ( V_28 -> V_29 -> V_27 , L_26 , V_14 ) ;
}
