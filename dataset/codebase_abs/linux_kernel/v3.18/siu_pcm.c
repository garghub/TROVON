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
V_21 = F_20 ( V_31 ) ;
if ( V_21 < 0 ) {
F_19 ( V_27 , L_4 ) ;
return V_21 ;
}
V_8 -> V_41 = V_31 ;
V_8 -> V_21 = V_21 ;
F_21 ( V_8 -> V_34 ) ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 | ( V_2 -> V_10 & 0x0c180c18 ) ) ;
F_22 ( V_27 , L_1 , V_14 ,
V_10 , V_10 | ( V_2 -> V_10 & 0x0c180c18 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_3 V_23 , T_5 V_24 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_42 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_30 * V_31 ;
T_4 V_21 ;
struct V_32 V_33 ;
T_1 V_10 ;
F_22 ( V_27 , L_5 , V_14 , V_24 , ( unsigned long long ) V_23 ) ;
F_11 ( & V_33 , 1 ) ;
F_12 ( & V_33 , F_13 ( F_14 ( V_23 ) ) ,
V_24 , F_15 ( V_23 ) ) ;
F_16 ( & V_33 ) = V_24 ;
F_17 ( & V_33 ) = V_23 ;
V_31 = F_18 ( V_8 -> V_34 ,
& V_33 , 1 , V_43 , V_36 | V_37 ) ;
if ( ! V_31 ) {
F_19 ( V_27 , L_6 ) ;
return - V_38 ;
}
V_31 -> V_39 = F_7 ;
V_31 -> V_40 = V_8 ;
V_21 = F_20 ( V_31 ) ;
if ( V_21 < 0 ) {
F_19 ( V_27 , L_7 ) ;
return V_21 ;
}
V_8 -> V_41 = V_31 ;
V_8 -> V_21 = V_21 ;
F_21 ( V_8 -> V_34 ) ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , F_2 ( V_6 + V_13 ) |
( V_2 -> V_10 & 0x13071307 ) ) ;
F_22 ( V_27 , L_1 , V_14 ,
V_10 , V_10 | ( V_2 -> V_10 & 0x13071307 ) ) ;
return 0 ;
}
static void F_24 ( unsigned long V_44 )
{
struct V_8 * V_8 = (struct V_8 * ) V_44 ;
struct V_25 * V_22 = V_8 -> V_22 ;
struct V_26 * V_27 = V_22 -> V_28 -> V_29 -> V_27 ;
struct V_45 * V_46 = V_22 -> V_47 ;
struct V_1 * V_2 = F_25 ( V_22 ) ;
F_22 ( V_27 , L_8 , V_14 , V_8 -> V_11 ) ;
if ( ! V_8 -> V_11 ) {
F_22 ( V_27 , L_9 , V_14 ) ;
return;
}
if ( V_22 -> V_48 == V_49 ) {
T_3 V_23 ;
T_5 V_50 ;
T_6 * V_51 ;
V_23 = ( T_3 ) F_26 ( V_46 -> V_52 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ;
V_51 = F_26 ( V_46 -> V_53 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ;
V_50 = V_8 -> V_20 ;
F_23 ( V_2 , V_23 , V_50 ) ;
} else {
F_10 ( V_2 ,
( T_3 ) F_26 ( V_46 -> V_52 ,
V_8 -> V_15 ,
V_8 -> V_20 ) ,
V_8 -> V_20 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = & V_2 -> V_42 ;
if ( V_8 -> V_54 > 0x1000000 )
return - V_55 ;
if ( V_8 -> V_11 )
return - V_12 ;
V_8 -> V_15 = 0 ;
V_8 -> V_11 = V_56 ;
F_6 ( & V_8 -> V_17 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = & V_2 -> V_42 ;
struct V_26 * V_27 = V_8 -> V_22 -> V_28 -> V_29 -> V_27 ;
T_1 V_10 ;
if ( ! V_8 -> V_11 )
return - V_12 ;
V_10 = F_2 ( V_6 + V_13 ) ;
F_3 ( V_6 + V_13 , V_10 & ~ 0x13071307 ) ;
F_22 ( V_27 , L_1 , V_14 ,
V_10 , V_10 & ~ 0x13071307 ) ;
V_8 -> V_11 = 0 ;
return 0 ;
}
static int F_29 ( struct V_25 * V_57 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
int V_60 ;
F_22 ( V_27 , L_10 , V_14 , V_4 -> V_61 ) ;
V_60 = F_30 ( V_57 , F_31 ( V_59 ) ) ;
if ( V_60 < 0 )
F_19 ( V_27 , L_11 ) ;
return V_60 ;
}
static int F_32 ( struct V_25 * V_57 )
{
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_25 ( V_57 ) ;
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
struct V_8 * V_8 ;
if ( V_57 -> V_48 == V_62 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_42 ;
F_22 ( V_27 , L_10 , V_14 , V_4 -> V_61 ) ;
return F_33 ( V_57 ) ;
}
static bool F_34 ( struct V_63 * V_34 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
F_4 ( L_12 , V_14 , V_66 -> V_67 . V_68 ) ;
V_34 -> V_69 = & V_66 -> V_67 ;
return true ;
}
static int F_35 ( struct V_25 * V_57 )
{
struct V_70 * V_71 = V_57 -> V_72 ;
struct V_73 * V_74 = V_71 -> V_75 -> V_27 -> V_76 ;
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_25 ( V_57 ) ;
struct V_8 * V_8 ;
T_1 V_77 = V_4 -> V_61 ;
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
T_7 V_78 ;
struct V_65 * V_66 ;
F_36 ( V_78 ) ;
F_37 ( V_79 , V_78 ) ;
F_22 ( V_27 , L_13 , V_14 , V_77 , V_2 ) ;
if ( V_57 -> V_48 == V_62 ) {
V_8 = & V_2 -> V_9 ;
V_66 = & V_8 -> V_66 ;
V_66 -> V_67 . V_68 = V_77 ? V_74 -> V_80 :
V_74 -> V_81 ;
} else {
V_8 = & V_2 -> V_42 ;
V_66 = & V_8 -> V_66 ;
V_66 -> V_67 . V_68 = V_77 ? V_74 -> V_82 :
V_74 -> V_83 ;
}
V_8 -> V_34 = F_38 ( V_78 , F_34 , V_66 ) ;
if ( ! V_8 -> V_34 ) {
F_19 ( V_27 , L_14 ) ;
return - V_84 ;
}
V_8 -> V_22 = V_57 ;
return 0 ;
}
static int F_39 ( struct V_25 * V_57 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
struct V_1 * V_2 = F_25 ( V_57 ) ;
struct V_8 * V_8 ;
F_22 ( V_27 , L_10 , V_14 , V_4 -> V_61 ) ;
if ( V_57 -> V_48 == V_62 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_42 ;
F_40 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
V_8 -> V_22 = NULL ;
return 0 ;
}
static int F_41 ( struct V_25 * V_57 )
{
struct V_3 * V_4 = V_5 ;
struct V_1 * V_2 = F_25 ( V_57 ) ;
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
struct V_45 * V_46 = V_57 -> V_47 ;
struct V_8 * V_8 ;
T_8 V_54 ;
if ( V_57 -> V_48 == V_62 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_42 ;
V_46 = V_8 -> V_22 -> V_47 ;
V_8 -> V_19 = F_42 ( V_57 ) ;
V_8 -> V_20 = F_43 ( V_57 ) ;
F_22 ( V_27 , L_15 , V_14 ,
V_4 -> V_61 , V_46 -> V_85 , V_8 -> V_20 ) ;
if ( V_8 -> V_19 % V_8 -> V_20 ) {
F_19 ( V_27 , L_16 ,
V_14 , V_8 -> V_19 ,
V_8 -> V_20 ) ;
return - V_55 ;
}
V_54 = F_44 ( V_46 , V_8 -> V_20 ) ;
if ( ! V_54 || V_54 > 0x1000000 )
return - V_55 ;
V_8 -> V_86 = V_46 -> V_86 ;
V_8 -> V_54 = V_54 ;
F_22 ( V_27 , L_17
L_18 , V_4 -> V_61 ,
( unsigned long ) V_46 -> V_52 , V_8 -> V_19 ,
V_8 -> V_20 ,
V_8 -> V_86 , V_46 -> V_85 , ( int ) V_54 ) ;
return 0 ;
}
static int F_45 ( struct V_25 * V_57 , int V_87 )
{
struct V_3 * V_4 = V_5 ;
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
struct V_1 * V_2 = F_25 ( V_57 ) ;
int V_60 ;
F_22 ( V_27 , L_19 , V_14 ,
V_4 -> V_61 , V_2 , V_87 ) ;
switch ( V_87 ) {
case V_88 :
if ( V_57 -> V_48 == V_62 )
V_60 = F_5 ( V_2 ) ;
else
V_60 = F_27 ( V_2 ) ;
if ( V_60 < 0 )
F_46 ( V_27 , L_20 ,
V_14 , V_4 -> V_61 ) ;
break;
case V_89 :
if ( V_57 -> V_48 == V_62 )
F_1 ( V_2 ) ;
else
F_28 ( V_2 ) ;
V_60 = 0 ;
break;
default:
F_19 ( V_27 , L_21 , V_14 , V_87 ) ;
V_60 = - V_55 ;
}
return V_60 ;
}
static T_9 F_47 ( struct V_25 * V_57 )
{
struct V_26 * V_27 = V_57 -> V_28 -> V_29 -> V_27 ;
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 = F_25 ( V_57 ) ;
struct V_45 * V_46 = V_57 -> V_47 ;
T_5 V_90 ;
struct V_8 * V_8 ;
if ( V_57 -> V_48 == V_62 )
V_8 = & V_2 -> V_9 ;
else
V_8 = & V_2 -> V_42 ;
V_90 = F_26 ( V_46 -> V_52 ,
V_8 -> V_15 ,
V_8 -> V_20 ) - V_46 -> V_52 ;
F_22 ( V_27 ,
L_22 ,
V_14 , V_4 -> V_61 , F_2 ( V_6 + V_91 ) ,
F_2 ( V_6 + V_92 ) , V_90 , V_8 -> V_19 ,
V_8 -> V_21 ) ;
if ( V_90 >= V_8 -> V_19 )
V_90 = 0 ;
return F_44 ( V_57 -> V_47 , V_90 ) ;
}
static int F_48 ( struct V_70 * V_71 )
{
struct V_93 * V_29 = V_71 -> V_29 -> V_93 ;
struct V_94 * V_28 = V_71 -> V_28 ;
struct V_3 * V_4 = V_5 ;
struct V_95 * V_96 = F_49 ( V_29 -> V_27 ) ;
int V_60 ;
int V_97 ;
if ( V_96 -> V_98 < 0 || V_96 -> V_98 >= V_99 )
return - V_55 ;
V_4 -> V_61 = V_96 -> V_98 ;
for ( V_97 = V_96 -> V_98 ; V_97 < V_96 -> V_98 + 1 ; V_97 ++ ) {
struct V_1 * * V_2 = & V_100 [ V_97 ] ;
V_60 = F_50 ( V_97 , V_2 , V_29 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = F_51 ( V_28 ,
V_101 , NULL ,
V_102 , V_102 ) ;
if ( V_60 < 0 ) {
F_19 ( V_29 -> V_27 ,
L_23 ,
V_60 ) ;
goto V_103;
}
( * V_2 ) -> V_28 = V_28 ;
F_52 ( & ( * V_2 ) -> V_9 . V_17 , F_24 ,
( unsigned long ) & ( * V_2 ) -> V_9 ) ;
F_52 ( & ( * V_2 ) -> V_42 . V_17 , F_24 ,
( unsigned long ) & ( * V_2 ) -> V_42 ) ;
}
F_53 ( V_29 -> V_27 , L_24 ) ;
return 0 ;
V_103:
F_54 ( V_100 [ V_96 -> V_98 ] ) ;
F_19 ( V_29 -> V_27 , L_25 ) ;
return V_60 ;
}
static void F_55 ( struct V_94 * V_28 )
{
struct V_95 * V_96 = F_49 ( V_28 -> V_29 -> V_27 ) ;
struct V_1 * V_2 = V_100 [ V_96 -> V_98 ] ;
F_56 ( & V_2 -> V_42 . V_17 ) ;
F_56 ( & V_2 -> V_9 . V_17 ) ;
F_54 ( V_2 ) ;
F_57 ( V_28 ) ;
F_22 ( V_28 -> V_29 -> V_27 , L_26 , V_14 ) ;
}
