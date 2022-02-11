void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 ) {
F_2 ( V_5 , V_2 -> V_6 ,
V_7 , 0 ) ;
} else {
F_3 ( V_8 , V_9 ) ;
if ( V_2 -> V_3 & V_10 ) {
F_4 ( & V_2 -> V_11 -> V_12 ,
F_5 ( & V_2 -> V_11 -> V_13 ) ) ;
F_4 ( & V_2 -> V_11 -> V_14 ,
F_5 ( & V_2 -> V_11 -> V_15 ) ) ;
}
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_16 T_1 * V_17 = V_2 -> V_17 ;
struct V_16 T_1 * V_18 = V_2 -> V_18 ;
unsigned int V_19 = F_7 ( V_2 -> V_20 , V_21 ) ;
unsigned int V_22 ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_22 = V_2 -> V_25 -> V_26 - V_2 -> V_20 ;
if ( V_2 -> V_27 == V_2 -> V_28 )
F_8 ( & V_18 -> V_29 , V_2 -> V_27 ) ;
else
F_8 ( & V_18 -> V_29 , V_2 -> V_27 + V_22 ) ;
F_4 ( & V_18 -> V_30 , 0 ) ;
F_4 ( & V_18 -> V_31 , V_32 | V_33 | V_34 ) ;
if ( V_2 -> V_35 == V_2 -> V_36 )
F_8 ( & V_17 -> V_29 , V_2 -> V_35 ) ;
else
F_8 ( & V_17 -> V_29 , V_2 -> V_35 + V_22 ) ;
F_4 ( & V_17 -> V_30 , V_19 ) ;
F_4 ( & V_17 -> V_31 , V_37 | V_33 | V_34 |
V_38 ) ;
F_9 ( & V_24 -> V_39 , V_40 ) ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_41 * V_42 , bool V_43 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_43 ) {
V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
} else {
V_2 -> V_46 = 1 ;
V_2 -> V_47 = 1 ;
}
if ( ! V_42 -> V_48 ) {
V_2 -> V_35 = V_2 -> V_36 ;
V_2 -> V_46 = 0 ;
}
if ( ! V_42 -> V_49 ) {
V_2 -> V_27 = V_2 -> V_28 ;
V_2 -> V_47 = 0 ;
}
if ( V_2 -> V_46 ) {
void * V_50 = ( void * ) V_2 -> V_51 ;
V_2 -> V_35 = F_11 ( V_45 , V_50 , V_42 -> V_26 ,
V_52 ) ;
if ( F_12 ( V_45 , V_2 -> V_35 ) ) {
F_13 ( V_45 , L_1 ) ;
return - V_53 ;
}
} else if ( V_42 -> V_48 ) {
V_2 -> V_35 = V_42 -> V_35 ;
}
if ( V_2 -> V_47 ) {
V_2 -> V_27 = F_11 ( V_45 , V_2 -> V_54 , V_42 -> V_26 ,
V_55 ) ;
if ( F_12 ( V_45 , V_2 -> V_27 ) ) {
F_13 ( V_45 , L_2 ) ;
goto V_56;
}
} else if ( V_42 -> V_49 ) {
V_2 -> V_27 = V_42 -> V_27 ;
}
F_9 ( & V_24 -> V_57 , V_58 ) ;
V_2 -> V_25 = V_42 ;
V_2 -> V_20 = V_42 -> V_26 ;
F_6 ( V_2 ) ;
return 0 ;
V_56:
if ( V_2 -> V_46 )
F_14 ( V_45 , V_2 -> V_35 , V_42 -> V_26 , V_52 ) ;
return - V_53 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_41 * V_42 = V_2 -> V_25 ;
if ( V_2 -> V_46 )
F_14 ( V_45 , V_2 -> V_35 , V_42 -> V_26 , V_52 ) ;
if ( V_2 -> V_47 )
F_14 ( V_45 , V_2 -> V_27 , V_42 -> V_26 , V_55 ) ;
V_2 -> V_25 = NULL ;
}
void F_16 ( struct V_1 * V_2 , T_2 V_59 )
{
T_3 V_26 ;
struct V_23 * V_24 = V_2 -> V_24 ;
F_17 ( V_2 -> V_45 , L_3 , V_60 ,
F_5 ( & V_2 -> V_18 -> V_30 ) , V_2 -> V_20 ) ;
V_26 = F_5 ( & V_2 -> V_18 -> V_30 ) ;
if ( V_26 > V_2 -> V_20 ) {
F_18 ( 1 ) ;
V_26 = V_2 -> V_20 ;
}
F_9 ( & V_24 -> V_61 , V_59 ) ;
V_2 -> V_20 -= V_26 ;
if ( V_2 -> V_20 )
F_6 ( V_2 ) ;
else
F_19 ( & V_2 -> V_62 ) ;
}
static void * F_20 ( void )
{
F_21 ( & V_63 ) ;
if ( ! V_64 )
V_64 = F_22 ( V_21 , V_65 ) ;
if ( V_64 )
V_66 ++ ;
F_23 ( & V_63 ) ;
return V_64 ;
}
static void F_24 ( void )
{
F_21 ( & V_63 ) ;
switch ( V_66 ) {
case 0 :
F_18 ( 1 ) ;
break;
case 1 :
F_25 ( V_64 ) ;
V_64 = NULL ;
default:
V_66 -- ;
break;
}
F_23 ( & V_63 ) ;
}
static unsigned long F_26 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_67 * V_68 = V_45 -> V_69 ;
const T_2 * V_70 ;
int V_71 ;
void T_1 * V_72 ;
unsigned long V_73 = - V_53 ;
V_70 = F_27 ( V_68 , L_4 , & V_71 ) ;
if ( V_2 -> V_3 & V_4 && V_70 && V_71 == sizeof( * V_70 ) * 4 )
return F_28 ( V_70 [ 2 ] , V_74 ) ;
if ( V_2 -> V_3 & V_4 ) {
V_73 = F_29 ( V_74 , 64 ) ;
F_2 ( V_75 , V_2 -> V_6 ,
V_7 , V_73 ) ;
return V_73 ;
}
V_72 = F_30 ( V_68 , 1 ) ;
if ( V_72 == NULL )
return - V_76 ;
if ( V_2 -> V_3 & V_77 ) {
V_73 = F_29 ( V_74 , 64 ) ;
F_4 ( V_72 , V_73 ) ;
} else {
struct V_78 T_1 * V_11 = V_72 ;
T_3 V_79 = F_5 ( & V_11 -> V_79 ) ;
if ( V_79 ) {
V_73 = V_79 ;
} else {
V_73 = F_29 ( V_74 , 64 ) ;
F_4 ( V_72 , V_73 ) ;
}
}
F_31 ( V_72 ) ;
return V_73 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_67 * V_68 = V_45 -> V_69 ;
const T_2 * V_70 ;
int V_71 ;
unsigned long V_73 ;
unsigned long V_80 ;
if ( ! ( V_2 -> V_3 & V_81 ) )
return 0 ;
if ( ! F_20 () )
return - V_53 ;
if ( V_2 -> V_3 & V_4 ) {
V_70 = F_27 ( V_68 , L_5 , & V_71 ) ;
if ( V_70 && V_71 == sizeof( * V_70 ) )
V_2 -> V_6 = * V_70 ;
switch ( V_2 -> V_6 ) {
default:
F_33 ( V_45 , L_6 ) ;
case 0 :
V_2 -> V_6 = V_82 ;
break;
case 1 :
V_2 -> V_6 = V_83 ;
break;
}
}
V_73 = F_26 ( V_2 ) ;
if ( F_34 ( V_73 ) ) {
F_13 ( V_45 , L_7 ) ;
goto V_84;
}
V_80 = F_29 ( sizeof( * V_2 -> V_17 ) +
sizeof( * V_2 -> V_18 ) , 8 ) ;
if ( F_34 ( V_80 ) ) {
F_13 ( V_45 , L_8 ) ;
goto V_85;
}
V_2 -> V_36 = F_11 ( V_45 , V_86 , V_87 ,
V_52 ) ;
if ( F_12 ( V_45 , V_2 -> V_36 ) ) {
F_13 ( V_45 , L_9 ) ;
goto V_88;
}
V_2 -> V_28 = F_11 ( V_45 , V_64 , V_21 ,
V_55 ) ;
if ( F_12 ( V_45 , V_2 -> V_28 ) ) {
F_13 ( V_45 , L_10 ) ;
goto V_89;
}
V_2 -> V_11 = F_35 ( V_73 ) ;
V_2 -> V_17 = F_35 ( V_80 ) ;
V_2 -> V_18 = F_35 ( V_80 + sizeof( * V_2 -> V_17 ) ) ;
F_4 ( & V_2 -> V_11 -> V_15 , F_36 ( V_2 -> V_17 ) ) ;
F_4 ( & V_2 -> V_11 -> V_13 , F_36 ( V_2 -> V_18 ) ) ;
F_37 ( & V_2 -> V_11 -> V_90 , V_91 | V_92 ) ;
F_37 ( & V_2 -> V_11 -> V_93 , V_91 | V_92 ) ;
F_4 ( & V_2 -> V_11 -> V_94 , V_21 ) ;
F_8 ( & V_2 -> V_11 -> V_95 , 0 ) ;
F_8 ( & V_2 -> V_11 -> V_96 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_12 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_97 , 0 ) ;
F_8 ( & V_2 -> V_11 -> V_98 , 0 ) ;
F_8 ( & V_2 -> V_11 -> V_99 , 0 ) ;
F_8 ( & V_2 -> V_11 -> V_100 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_14 , 0 ) ;
F_4 ( & V_2 -> V_11 -> V_101 , 0 ) ;
F_8 ( & V_2 -> V_11 -> V_102 , 0 ) ;
return 0 ;
V_89:
F_14 ( V_45 , V_2 -> V_36 , V_87 , V_52 ) ;
V_88:
F_38 ( V_80 ) ;
V_85:
F_38 ( V_73 ) ;
V_84:
F_24 () ;
return - V_53 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
if ( ! ( V_2 -> V_3 & V_81 ) )
return;
F_14 ( V_45 , V_2 -> V_28 , V_21 , V_55 ) ;
F_14 ( V_45 , V_2 -> V_36 , V_87 , V_52 ) ;
F_38 ( F_36 ( V_2 -> V_17 ) ) ;
F_38 ( F_36 ( V_2 -> V_11 ) ) ;
F_24 () ;
}
