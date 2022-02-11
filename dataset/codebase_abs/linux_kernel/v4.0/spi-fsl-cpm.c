void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 ) {
F_2 ( V_5 , V_2 -> V_6 ,
V_7 , 0 ) ;
} else {
if ( V_2 -> V_3 & V_8 ) {
F_3 ( & V_2 -> V_9 -> V_10 , 0 ) ;
F_4 ( & V_2 -> V_9 -> V_11 ,
F_5 ( & V_2 -> V_9 -> V_12 ) ) ;
F_3 ( & V_2 -> V_9 -> V_13 , 0 ) ;
F_4 ( & V_2 -> V_9 -> V_14 ,
F_5 ( & V_2 -> V_9 -> V_15 ) ) ;
} else {
F_6 ( V_16 , V_17 ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_18 T_1 * V_19 = V_2 -> V_19 ;
struct V_18 T_1 * V_20 = V_2 -> V_20 ;
unsigned int V_21 = F_8 ( V_2 -> V_22 , V_23 ) ;
unsigned int V_24 ;
struct V_25 * V_26 = V_2 -> V_26 ;
V_24 = V_2 -> V_27 -> V_28 - V_2 -> V_22 ;
if ( V_2 -> V_29 == V_2 -> V_30 )
F_3 ( & V_20 -> V_31 , V_2 -> V_29 ) ;
else
F_3 ( & V_20 -> V_31 , V_2 -> V_29 + V_24 ) ;
F_4 ( & V_20 -> V_32 , 0 ) ;
F_4 ( & V_20 -> V_33 , V_34 | V_35 | V_36 ) ;
if ( V_2 -> V_37 == V_2 -> V_38 )
F_3 ( & V_19 -> V_31 , V_2 -> V_37 ) ;
else
F_3 ( & V_19 -> V_31 , V_2 -> V_37 + V_24 ) ;
F_4 ( & V_19 -> V_32 , V_21 ) ;
F_4 ( & V_19 -> V_33 , V_39 | V_35 | V_36 |
V_40 ) ;
F_9 ( & V_26 -> V_41 , V_42 ) ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_43 * V_44 , bool V_45 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_45 ) {
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
} else {
V_2 -> V_48 = 1 ;
V_2 -> V_49 = 1 ;
}
if ( ! V_44 -> V_50 ) {
V_2 -> V_37 = V_2 -> V_38 ;
V_2 -> V_48 = 0 ;
}
if ( ! V_44 -> V_51 ) {
V_2 -> V_29 = V_2 -> V_30 ;
V_2 -> V_49 = 0 ;
}
if ( V_2 -> V_48 ) {
void * V_52 = ( void * ) V_2 -> V_53 ;
V_2 -> V_37 = F_11 ( V_47 , V_52 , V_44 -> V_28 ,
V_54 ) ;
if ( F_12 ( V_47 , V_2 -> V_37 ) ) {
F_13 ( V_47 , L_1 ) ;
return - V_55 ;
}
} else if ( V_44 -> V_50 ) {
V_2 -> V_37 = V_44 -> V_37 ;
}
if ( V_2 -> V_49 ) {
V_2 -> V_29 = F_11 ( V_47 , V_2 -> V_56 , V_44 -> V_28 ,
V_57 ) ;
if ( F_12 ( V_47 , V_2 -> V_29 ) ) {
F_13 ( V_47 , L_2 ) ;
goto V_58;
}
} else if ( V_44 -> V_51 ) {
V_2 -> V_29 = V_44 -> V_29 ;
}
F_9 ( & V_26 -> V_59 , V_60 ) ;
V_2 -> V_27 = V_44 ;
V_2 -> V_22 = V_44 -> V_28 ;
F_7 ( V_2 ) ;
return 0 ;
V_58:
if ( V_2 -> V_48 )
F_14 ( V_47 , V_2 -> V_37 , V_44 -> V_28 , V_54 ) ;
return - V_55 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_43 * V_44 = V_2 -> V_27 ;
if ( V_2 -> V_48 )
F_14 ( V_47 , V_2 -> V_37 , V_44 -> V_28 , V_54 ) ;
if ( V_2 -> V_49 )
F_14 ( V_47 , V_2 -> V_29 , V_44 -> V_28 , V_57 ) ;
V_2 -> V_27 = NULL ;
}
void F_16 ( struct V_1 * V_2 , T_2 V_61 )
{
T_3 V_28 ;
struct V_25 * V_26 = V_2 -> V_26 ;
F_17 ( V_2 -> V_47 , L_3 , V_62 ,
F_5 ( & V_2 -> V_20 -> V_32 ) , V_2 -> V_22 ) ;
V_28 = F_5 ( & V_2 -> V_20 -> V_32 ) ;
if ( V_28 > V_2 -> V_22 ) {
F_18 ( 1 ) ;
V_28 = V_2 -> V_22 ;
}
F_9 ( & V_26 -> V_63 , V_61 ) ;
V_2 -> V_22 -= V_28 ;
if ( V_2 -> V_22 )
F_7 ( V_2 ) ;
else
F_19 ( & V_2 -> V_64 ) ;
}
static void * F_20 ( void )
{
F_21 ( & V_65 ) ;
if ( ! V_66 )
V_66 = F_22 ( V_23 , V_67 ) ;
if ( V_66 )
V_68 ++ ;
F_23 ( & V_65 ) ;
return V_66 ;
}
static void F_24 ( void )
{
F_21 ( & V_65 ) ;
switch ( V_68 ) {
case 0 :
F_18 ( 1 ) ;
break;
case 1 :
F_25 ( V_66 ) ;
V_66 = NULL ;
default:
V_68 -- ;
break;
}
F_23 ( & V_65 ) ;
}
static unsigned long F_26 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_69 * V_70 = V_47 -> V_71 ;
const T_2 * V_72 ;
int V_73 ;
void T_1 * V_74 ;
unsigned long V_75 = - V_55 ;
V_72 = F_27 ( V_70 , L_4 , & V_73 ) ;
if ( V_2 -> V_3 & V_4 && V_72 && V_73 == sizeof( * V_72 ) * 4 )
return F_28 ( V_72 [ 2 ] , V_76 ) ;
if ( V_2 -> V_3 & V_4 ) {
V_75 = F_29 ( V_76 , 64 ) ;
F_2 ( V_77 , V_2 -> V_6 ,
V_7 , V_75 ) ;
return V_75 ;
}
V_74 = F_30 ( V_70 , 1 ) ;
if ( V_74 == NULL )
return - V_78 ;
if ( V_2 -> V_3 & V_79 ) {
V_75 = F_29 ( V_76 , 64 ) ;
F_4 ( V_74 , V_75 ) ;
} else {
struct V_80 T_1 * V_9 = V_74 ;
T_3 V_81 = F_5 ( & V_9 -> V_81 ) ;
if ( V_81 ) {
V_75 = V_81 ;
} else {
V_75 = F_29 ( V_76 , 64 ) ;
F_4 ( V_74 , V_75 ) ;
}
}
F_31 ( V_74 ) ;
return V_75 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_69 * V_70 = V_47 -> V_71 ;
const T_2 * V_72 ;
int V_73 ;
unsigned long V_75 ;
unsigned long V_82 ;
if ( ! ( V_2 -> V_3 & V_83 ) )
return 0 ;
if ( ! F_20 () )
return - V_55 ;
if ( V_2 -> V_3 & V_4 ) {
V_72 = F_27 ( V_70 , L_5 , & V_73 ) ;
if ( V_72 && V_73 == sizeof( * V_72 ) )
V_2 -> V_6 = * V_72 ;
switch ( V_2 -> V_6 ) {
default:
F_33 ( V_47 , L_6 ) ;
case 0 :
V_2 -> V_6 = V_84 ;
break;
case 1 :
V_2 -> V_6 = V_85 ;
break;
}
}
V_75 = F_26 ( V_2 ) ;
if ( F_34 ( V_75 ) ) {
F_13 ( V_47 , L_7 ) ;
goto V_86;
}
V_82 = F_29 ( sizeof( * V_2 -> V_19 ) +
sizeof( * V_2 -> V_20 ) , 8 ) ;
if ( F_34 ( V_82 ) ) {
F_13 ( V_47 , L_8 ) ;
goto V_87;
}
V_2 -> V_38 = F_11 ( V_47 , V_88 , V_89 ,
V_54 ) ;
if ( F_12 ( V_47 , V_2 -> V_38 ) ) {
F_13 ( V_47 , L_9 ) ;
goto V_90;
}
V_2 -> V_30 = F_11 ( V_47 , V_66 , V_23 ,
V_57 ) ;
if ( F_12 ( V_47 , V_2 -> V_30 ) ) {
F_13 ( V_47 , L_10 ) ;
goto V_91;
}
V_2 -> V_9 = F_35 ( V_75 ) ;
V_2 -> V_19 = F_35 ( V_82 ) ;
V_2 -> V_20 = F_35 ( V_82 + sizeof( * V_2 -> V_19 ) ) ;
F_4 ( & V_2 -> V_9 -> V_15 , F_36 ( V_2 -> V_19 ) ) ;
F_4 ( & V_2 -> V_9 -> V_12 , F_36 ( V_2 -> V_20 ) ) ;
F_37 ( & V_2 -> V_9 -> V_92 , V_93 | V_94 ) ;
F_37 ( & V_2 -> V_9 -> V_95 , V_93 | V_94 ) ;
F_4 ( & V_2 -> V_9 -> V_96 , V_23 ) ;
F_3 ( & V_2 -> V_9 -> V_10 , 0 ) ;
F_3 ( & V_2 -> V_9 -> V_97 , 0 ) ;
F_4 ( & V_2 -> V_9 -> V_11 , 0 ) ;
F_4 ( & V_2 -> V_9 -> V_98 , 0 ) ;
F_3 ( & V_2 -> V_9 -> V_99 , 0 ) ;
F_3 ( & V_2 -> V_9 -> V_13 , 0 ) ;
F_3 ( & V_2 -> V_9 -> V_100 , 0 ) ;
F_4 ( & V_2 -> V_9 -> V_14 , 0 ) ;
F_4 ( & V_2 -> V_9 -> V_101 , 0 ) ;
F_3 ( & V_2 -> V_9 -> V_102 , 0 ) ;
return 0 ;
V_91:
F_14 ( V_47 , V_2 -> V_38 , V_89 , V_54 ) ;
V_90:
F_38 ( V_82 ) ;
V_87:
F_38 ( V_75 ) ;
V_86:
F_24 () ;
return - V_55 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
if ( ! ( V_2 -> V_3 & V_83 ) )
return;
F_14 ( V_47 , V_2 -> V_30 , V_23 , V_57 ) ;
F_14 ( V_47 , V_2 -> V_38 , V_89 , V_54 ) ;
F_38 ( F_36 ( V_2 -> V_19 ) ) ;
F_38 ( F_36 ( V_2 -> V_9 ) ) ;
F_24 () ;
}
