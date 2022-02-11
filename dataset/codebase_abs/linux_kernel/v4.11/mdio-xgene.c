static T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
void T_2 * V_3 , * V_4 , * V_5 , * V_6 ;
T_1 V_7 , V_8 = V_9 ;
T_3 V_10 = 10 ;
V_3 = V_1 + V_11 ;
V_4 = V_1 + V_12 ;
V_5 = V_1 + V_13 ;
V_6 = V_1 + V_14 ;
F_2 ( V_2 , V_3 ) ;
F_2 ( V_15 , V_5 ) ;
while ( V_10 -- ) {
V_7 = F_3 ( V_6 ) ;
if ( V_7 )
break;
F_4 ( 1 ) ;
}
if ( ! V_7 )
return V_8 ;
V_8 = F_3 ( V_4 ) ;
F_2 ( 0 , V_5 ) ;
return V_8 ;
}
static void F_5 ( void T_2 * V_1 , T_1 V_16 , T_1 V_17 )
{
void T_2 * V_3 , * V_18 , * V_5 , * V_6 ;
T_3 V_10 = 10 ;
T_1 V_7 ;
V_3 = V_1 + V_11 ;
V_18 = V_1 + V_19 ;
V_5 = V_1 + V_13 ;
V_6 = V_1 + V_14 ;
F_2 ( V_16 , V_3 ) ;
F_2 ( V_17 , V_18 ) ;
F_2 ( V_20 , V_5 ) ;
while ( V_10 -- ) {
V_7 = F_3 ( V_6 ) ;
if ( V_7 )
break;
F_4 ( 1 ) ;
}
if ( ! V_7 )
F_6 ( L_1 , V_16 ) ;
F_2 ( 0 , V_5 ) ;
}
int F_7 ( struct V_21 * V_22 , int V_23 , int V_24 )
{
void T_2 * V_3 = ( void T_2 * ) V_22 -> V_25 ;
T_1 V_26 , V_7 ;
T_3 V_10 = 10 ;
V_26 = F_8 ( V_27 , V_23 ) | F_8 ( V_28 , V_24 ) ;
F_5 ( V_3 , V_29 , V_26 ) ;
F_5 ( V_3 , V_30 , V_31 ) ;
do {
F_9 ( 5 , 10 ) ;
V_7 = F_1 ( V_3 , V_32 ) ;
} while ( ( V_7 & V_9 ) && V_10 -- );
if ( V_7 & V_9 ) {
F_10 ( & V_22 -> V_33 , L_2 ) ;
return - V_34 ;
}
V_26 = F_1 ( V_3 , V_35 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
return V_26 ;
}
int F_11 ( struct V_21 * V_22 , int V_23 , int V_24 , T_4 V_26 )
{
void T_2 * V_3 = ( void T_2 * ) V_22 -> V_25 ;
T_1 V_36 , V_7 ;
T_3 V_10 = 10 ;
V_36 = F_8 ( V_27 , V_23 ) | F_8 ( V_28 , V_24 ) ;
F_5 ( V_3 , V_29 , V_36 ) ;
F_5 ( V_3 , V_37 , V_26 ) ;
do {
F_9 ( 5 , 10 ) ;
V_7 = F_1 ( V_3 , V_32 ) ;
} while ( ( V_7 & V_9 ) && V_10 -- );
if ( V_7 & V_9 ) {
F_10 ( & V_22 -> V_33 , L_3 ) ;
return - V_34 ;
}
return 0 ;
}
static T_1 F_12 ( struct V_38 * V_39 , T_1 V_40 )
{
return F_3 ( V_39 -> V_41 + V_40 ) ;
}
static void F_13 ( struct V_38 * V_39 ,
T_1 V_40 , T_1 V_36 )
{
F_2 ( V_36 , V_39 -> V_41 + V_40 ) ;
}
static int F_14 ( struct V_38 * V_39 )
{
T_1 V_26 ;
T_3 V_10 = 10 ;
F_13 ( V_39 , V_42 , 0x0 ) ;
do {
F_9 ( 100 , 110 ) ;
V_26 = F_12 ( V_39 , V_43 ) ;
} while ( ( V_26 != 0xffffffff ) && V_10 -- );
if ( V_26 != 0xffffffff ) {
F_10 ( V_39 -> V_33 , L_4 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_15 ( struct V_38 * V_39 )
{
F_5 ( V_39 -> V_45 , V_46 , V_47 ) ;
F_5 ( V_39 -> V_45 , V_46 , 0 ) ;
}
static int F_16 ( struct V_38 * V_39 )
{
int V_48 ;
if ( V_39 -> V_33 -> V_49 ) {
F_17 ( V_39 -> V_50 ) ;
F_4 ( 5 ) ;
F_18 ( V_39 -> V_50 ) ;
F_4 ( 5 ) ;
F_17 ( V_39 -> V_50 ) ;
F_4 ( 5 ) ;
} else {
#ifdef F_19
F_20 ( F_21 ( V_39 -> V_33 ) ,
L_5 , NULL , NULL ) ;
#endif
}
V_48 = F_14 ( V_39 ) ;
if ( V_48 )
return V_48 ;
F_15 ( V_39 ) ;
return 0 ;
}
static void F_22 ( void T_2 * V_1 ,
T_1 V_40 , T_1 * V_36 )
{
void T_2 * V_3 = V_1 + V_40 ;
* V_36 = F_3 ( V_3 ) ;
}
static void F_23 ( void T_2 * V_1 ,
T_1 V_40 , T_1 V_36 )
{
void T_2 * V_3 = V_1 + V_40 ;
F_2 ( V_36 , V_3 ) ;
}
static int F_24 ( struct V_21 * V_22 , int V_23 ,
int V_24 , T_4 V_26 )
{
void T_2 * V_3 = ( void T_2 * ) V_22 -> V_25 ;
int V_51 = 100 ;
T_1 V_52 , V_36 ;
V_36 = F_8 ( V_53 , V_23 ) | F_8 ( V_54 , V_24 ) |
F_8 ( V_55 , V_26 ) ;
F_23 ( V_3 , V_56 , V_26 ) ;
V_36 = V_57 | F_8 ( V_58 , V_59 ) ;
F_23 ( V_3 , V_60 , V_36 ) ;
do {
F_9 ( 5 , 10 ) ;
F_22 ( V_3 , V_61 , & V_52 ) ;
} while ( ( V_52 & V_9 ) && V_51 -- );
F_23 ( V_3 , V_60 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 , int V_23 , int V_24 )
{
void T_2 * V_3 = ( void T_2 * ) V_22 -> V_25 ;
T_1 V_26 , V_52 , V_36 ;
int V_51 = 100 ;
V_36 = F_8 ( V_53 , V_23 ) | F_8 ( V_54 , V_24 ) ;
F_23 ( V_3 , V_56 , V_36 ) ;
V_36 = V_57 | F_8 ( V_58 , V_62 ) ;
F_23 ( V_3 , V_60 , V_36 ) ;
do {
F_9 ( 5 , 10 ) ;
F_22 ( V_3 , V_61 , & V_52 ) ;
} while ( ( V_52 & V_9 ) && V_51 -- );
if ( V_52 & V_9 ) {
F_6 ( L_6 ) ;
return - V_34 ;
}
F_22 ( V_3 , V_63 , & V_26 ) ;
F_23 ( V_3 , V_60 , 0 ) ;
return V_26 ;
}
struct V_64 * F_26 ( struct V_21 * V_22 , int V_65 )
{
struct V_64 * V_66 ;
V_66 = F_27 ( V_22 , V_65 , false ) ;
if ( ! V_66 || F_28 ( V_66 ) )
return NULL ;
if ( F_29 ( V_66 ) )
F_30 ( V_66 ) ;
return V_66 ;
}
static T_5 F_31 ( T_6 V_67 , T_1 V_68 ,
void * V_69 , void * * V_48 )
{
struct V_21 * V_70 = V_69 ;
struct V_71 * V_72 ;
struct V_64 * V_66 ;
const union V_73 * V_74 ;
T_1 V_65 ;
if ( F_32 ( V_67 , & V_72 ) )
return V_75 ;
if ( F_33 ( V_72 , L_7 , V_76 , & V_74 ) )
return V_75 ;
V_65 = V_74 -> integer . V_77 ;
V_66 = F_26 ( V_70 , V_65 ) ;
V_72 -> V_78 = V_66 ;
return V_75 ;
}
static int F_34 ( struct V_79 * V_80 )
{
struct V_81 * V_33 = & V_80 -> V_33 ;
struct V_21 * V_82 ;
const struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_38 * V_39 ;
void T_2 * V_87 ;
int V_88 = 0 , V_48 = 0 ;
V_84 = F_35 ( V_89 , & V_80 -> V_33 ) ;
if ( V_84 ) {
V_88 = (enum V_90 ) V_84 -> V_26 ;
} else {
#ifdef F_19
const struct V_91 * V_92 ;
V_92 = F_36 ( V_93 , & V_80 -> V_33 ) ;
if ( V_92 )
V_88 = (enum V_90 ) V_92 -> V_78 ;
#endif
}
if ( ! V_88 )
return - V_44 ;
V_39 = F_37 ( V_33 , sizeof( struct V_38 ) , V_94 ) ;
if ( ! V_39 )
return - V_95 ;
V_39 -> V_88 = V_88 ;
V_39 -> V_33 = V_33 ;
V_86 = F_38 ( V_80 , V_96 , 0 ) ;
V_87 = F_39 ( V_33 , V_86 ) ;
if ( F_28 ( V_87 ) )
return F_40 ( V_87 ) ;
V_39 -> V_45 = V_87 ;
V_39 -> V_97 = V_87 + V_98 ;
V_39 -> V_41 = V_87 + V_99 ;
if ( V_33 -> V_49 ) {
V_39 -> V_50 = F_41 ( V_33 , NULL ) ;
if ( F_28 ( V_39 -> V_50 ) ) {
F_10 ( V_33 , L_8 ) ;
return F_40 ( V_39 -> V_50 ) ;
}
}
V_48 = F_16 ( V_39 ) ;
if ( V_48 )
return V_48 ;
V_82 = F_42 () ;
if ( ! V_82 )
return - V_95 ;
V_82 -> V_100 = L_9 ;
if ( V_88 == V_101 ) {
V_82 -> V_102 = F_7 ;
V_82 -> V_103 = F_11 ;
V_82 -> V_25 = ( void V_104 * ) V_39 -> V_45 ;
snprintf ( V_82 -> V_105 , V_106 , L_10 ,
L_11 ) ;
} else {
V_82 -> V_102 = F_25 ;
V_82 -> V_103 = F_24 ;
V_82 -> V_25 = ( void V_104 * ) V_39 -> V_97 ;
snprintf ( V_82 -> V_105 , V_106 , L_10 ,
L_12 ) ;
}
V_82 -> V_107 = V_33 ;
F_43 ( V_80 , V_39 ) ;
if ( V_33 -> V_49 ) {
V_48 = F_44 ( V_82 , V_33 -> V_49 ) ;
} else {
#ifdef F_19
V_82 -> V_108 = ~ 0 ;
V_48 = F_45 ( V_82 ) ;
if ( V_48 )
goto V_109;
F_46 ( V_110 , F_21 ( V_33 ) , 1 ,
F_31 , NULL , V_82 , NULL ) ;
#endif
}
if ( V_48 )
goto V_109;
V_39 -> V_82 = V_82 ;
V_111 = true ;
return 0 ;
V_109:
F_47 ( V_82 ) ;
return V_48 ;
}
static int F_48 ( struct V_79 * V_80 )
{
struct V_38 * V_39 = F_49 ( V_80 ) ;
struct V_21 * V_82 = V_39 -> V_82 ;
struct V_81 * V_33 = & V_80 -> V_33 ;
F_50 ( V_82 ) ;
F_47 ( V_82 ) ;
if ( V_33 -> V_49 )
F_18 ( V_39 -> V_50 ) ;
return 0 ;
}
