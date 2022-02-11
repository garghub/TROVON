T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 , * V_5 , * V_6 , * V_7 ;
T_1 V_8 , V_9 = V_10 ;
T_3 V_11 = 10 ;
V_4 = V_2 -> V_12 + V_13 ;
V_5 = V_2 -> V_12 + V_14 ;
V_6 = V_2 -> V_12 + V_15 ;
V_7 = V_2 -> V_12 + V_16 ;
F_2 ( & V_2 -> V_17 ) ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_18 , V_6 ) ;
while ( ! ( V_8 = F_4 ( V_7 ) ) && V_11 -- )
F_5 ( 1 ) ;
if ( V_8 )
V_9 = F_4 ( V_5 ) ;
F_3 ( 0 , V_6 ) ;
F_6 ( & V_2 -> V_17 ) ;
return V_9 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 )
{
void T_2 * V_4 , * V_21 , * V_6 , * V_7 ;
T_3 V_11 = 10 ;
T_1 V_8 ;
V_4 = V_2 -> V_12 + V_13 ;
V_21 = V_2 -> V_12 + V_22 ;
V_6 = V_2 -> V_12 + V_15 ;
V_7 = V_2 -> V_12 + V_16 ;
F_2 ( & V_2 -> V_17 ) ;
F_3 ( V_19 , V_4 ) ;
F_3 ( V_20 , V_21 ) ;
F_3 ( V_23 , V_6 ) ;
while ( ! ( V_8 = F_4 ( V_7 ) ) && V_11 -- )
F_5 ( 1 ) ;
if ( ! V_8 )
F_8 ( L_1 , V_19 ) ;
F_3 ( 0 , V_6 ) ;
F_6 ( & V_2 -> V_17 ) ;
}
int F_9 ( struct V_24 * V_25 , int V_26 , int V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 -> V_28 ;
T_1 V_20 , V_8 ;
T_3 V_11 = 10 ;
V_20 = F_10 ( V_29 , V_26 ) | F_10 ( V_30 , V_27 ) ;
F_7 ( V_2 , V_31 , V_20 ) ;
F_7 ( V_2 , V_32 , V_33 ) ;
do {
F_11 ( 5 , 10 ) ;
V_8 = F_1 ( V_2 , V_34 ) ;
} while ( ( V_8 & V_10 ) && V_11 -- );
if ( V_8 & V_10 ) {
F_12 ( & V_25 -> V_35 , L_2 ) ;
return - V_36 ;
}
V_20 = F_1 ( V_2 , V_37 ) ;
F_7 ( V_2 , V_32 , 0 ) ;
return V_20 ;
}
int F_13 ( struct V_24 * V_25 , int V_26 , int V_27 , T_4 V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 -> V_28 ;
T_1 V_38 , V_8 ;
T_3 V_11 = 10 ;
V_38 = F_10 ( V_29 , V_26 ) | F_10 ( V_30 , V_27 ) ;
F_7 ( V_2 , V_31 , V_38 ) ;
F_7 ( V_2 , V_39 , V_20 ) ;
do {
F_11 ( 5 , 10 ) ;
V_8 = F_1 ( V_2 , V_34 ) ;
} while ( ( V_8 & V_10 ) && V_11 -- );
if ( V_8 & V_10 ) {
F_12 ( & V_25 -> V_35 , L_3 ) ;
return - V_36 ;
}
return 0 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_40 )
{
return F_4 ( V_2 -> V_41 + V_40 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
T_1 V_40 , T_1 V_38 )
{
F_3 ( V_38 , V_2 -> V_41 + V_40 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_20 ;
T_3 V_11 = 10 ;
F_15 ( V_2 , V_42 , 0x0 ) ;
do {
F_11 ( 100 , 110 ) ;
V_20 = F_14 ( V_2 , V_43 ) ;
} while ( ( V_20 != 0xffffffff ) && V_11 -- );
if ( V_20 != 0xffffffff ) {
F_12 ( V_2 -> V_35 , L_4 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_45 , V_46 ) ;
F_7 ( V_2 , V_45 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_47 ;
if ( V_2 -> V_35 -> V_48 ) {
F_19 ( V_2 -> V_49 ) ;
F_5 ( 5 ) ;
F_20 ( V_2 -> V_49 ) ;
F_5 ( 5 ) ;
F_19 ( V_2 -> V_49 ) ;
F_5 ( 5 ) ;
} else {
#ifdef F_21
F_22 ( F_23 ( V_2 -> V_35 ) ,
L_5 , NULL , NULL ) ;
#endif
}
V_47 = F_16 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_17 ( V_2 ) ;
return 0 ;
}
static void F_24 ( void T_2 * V_50 ,
T_1 V_40 , T_1 * V_38 )
{
void T_2 * V_4 = V_50 + V_40 ;
* V_38 = F_4 ( V_4 ) ;
}
static void F_25 ( void T_2 * V_50 ,
T_1 V_40 , T_1 V_38 )
{
void T_2 * V_4 = V_50 + V_40 ;
F_3 ( V_38 , V_4 ) ;
}
static int F_26 ( struct V_24 * V_25 , int V_26 ,
int V_27 , T_4 V_20 )
{
void T_2 * V_4 = ( void T_2 * ) V_25 -> V_28 ;
int V_51 = 100 ;
T_1 V_52 , V_38 ;
V_38 = F_10 ( V_53 , V_26 ) | F_10 ( V_54 , V_27 ) |
F_10 ( V_55 , V_20 ) ;
F_25 ( V_4 , V_56 , V_38 ) ;
V_38 = V_57 | F_10 ( V_58 , V_59 ) ;
F_25 ( V_4 , V_60 , V_38 ) ;
do {
F_11 ( 5 , 10 ) ;
F_24 ( V_4 , V_61 , & V_52 ) ;
} while ( ( V_52 & V_10 ) && V_51 -- );
F_25 ( V_4 , V_60 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_24 * V_25 , int V_26 , int V_27 )
{
void T_2 * V_4 = ( void T_2 * ) V_25 -> V_28 ;
T_1 V_20 , V_52 , V_38 ;
int V_51 = 100 ;
V_38 = F_10 ( V_53 , V_26 ) | F_10 ( V_54 , V_27 ) ;
F_25 ( V_4 , V_56 , V_38 ) ;
V_38 = V_57 | F_10 ( V_58 , V_62 ) ;
F_25 ( V_4 , V_60 , V_38 ) ;
do {
F_11 ( 5 , 10 ) ;
F_24 ( V_4 , V_61 , & V_52 ) ;
} while ( ( V_52 & V_10 ) && V_51 -- );
if ( V_52 & V_10 ) {
F_8 ( L_6 ) ;
return - V_36 ;
}
F_24 ( V_4 , V_63 , & V_20 ) ;
F_25 ( V_4 , V_60 , 0 ) ;
return V_20 ;
}
struct V_64 * F_28 ( struct V_24 * V_25 , int V_65 )
{
struct V_64 * V_66 ;
V_66 = F_29 ( V_25 , V_65 , false ) ;
if ( ! V_66 || F_30 ( V_66 ) )
return NULL ;
if ( F_31 ( V_66 ) )
F_32 ( V_66 ) ;
return V_66 ;
}
static T_5 F_33 ( T_6 V_67 , T_1 V_68 ,
void * V_69 , void * * V_47 )
{
struct V_24 * V_70 = V_69 ;
struct V_71 * V_72 ;
struct V_64 * V_66 ;
const union V_73 * V_74 ;
T_1 V_65 ;
if ( F_34 ( V_67 , & V_72 ) )
return V_75 ;
if ( F_35 ( V_72 , L_7 , V_76 , & V_74 ) )
return V_75 ;
V_65 = V_74 -> integer . V_77 ;
V_66 = F_28 ( V_70 , V_65 ) ;
V_72 -> V_78 = V_66 ;
return V_75 ;
}
static int F_36 ( struct V_79 * V_80 )
{
struct V_81 * V_35 = & V_80 -> V_35 ;
struct V_24 * V_82 ;
const struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_1 * V_2 ;
void T_2 * V_87 ;
int V_88 = 0 , V_47 = 0 ;
V_84 = F_37 ( V_89 , & V_80 -> V_35 ) ;
if ( V_84 ) {
V_88 = (enum V_90 ) V_84 -> V_20 ;
} else {
#ifdef F_21
const struct V_91 * V_92 ;
V_92 = F_38 ( V_93 , & V_80 -> V_35 ) ;
if ( V_92 )
V_88 = (enum V_90 ) V_92 -> V_78 ;
#endif
}
if ( ! V_88 )
return - V_44 ;
V_2 = F_39 ( V_35 , sizeof( struct V_1 ) , V_94 ) ;
if ( ! V_2 )
return - V_95 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_35 = V_35 ;
V_86 = F_40 ( V_80 , V_96 , 0 ) ;
V_87 = F_41 ( V_35 , V_86 ) ;
if ( F_30 ( V_87 ) )
return F_42 ( V_87 ) ;
V_2 -> V_12 = V_87 ;
V_2 -> V_97 = V_87 + V_98 ;
V_2 -> V_41 = V_87 + V_99 ;
if ( V_88 == V_100 )
F_43 ( & V_2 -> V_17 ) ;
if ( V_35 -> V_48 ) {
V_2 -> V_49 = F_44 ( V_35 , NULL ) ;
if ( F_30 ( V_2 -> V_49 ) ) {
F_12 ( V_35 , L_8 ) ;
return F_42 ( V_2 -> V_49 ) ;
}
}
V_47 = F_18 ( V_2 ) ;
if ( V_47 )
return V_47 ;
V_82 = F_45 () ;
if ( ! V_82 )
return - V_95 ;
V_82 -> V_101 = L_9 ;
if ( V_88 == V_100 ) {
V_82 -> V_102 = F_9 ;
V_82 -> V_103 = F_13 ;
V_82 -> V_28 = ( void V_104 * ) V_2 ;
snprintf ( V_82 -> V_105 , V_106 , L_10 ,
L_11 ) ;
} else {
V_82 -> V_102 = F_27 ;
V_82 -> V_103 = F_26 ;
V_82 -> V_28 = ( void V_104 * ) V_2 -> V_97 ;
snprintf ( V_82 -> V_105 , V_106 , L_10 ,
L_12 ) ;
}
V_82 -> V_107 = V_35 ;
F_46 ( V_80 , V_2 ) ;
if ( V_35 -> V_48 ) {
V_47 = F_47 ( V_82 , V_35 -> V_48 ) ;
} else {
#ifdef F_21
V_82 -> V_108 = ~ 0 ;
V_47 = F_48 ( V_82 ) ;
if ( V_47 )
goto V_109;
F_49 ( V_110 , F_23 ( V_35 ) , 1 ,
F_33 , NULL , V_82 , NULL ) ;
#endif
}
if ( V_47 )
goto V_109;
V_2 -> V_82 = V_82 ;
V_111 = true ;
return 0 ;
V_109:
F_50 ( V_82 ) ;
return V_47 ;
}
static int F_51 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_52 ( V_80 ) ;
struct V_24 * V_82 = V_2 -> V_82 ;
struct V_81 * V_35 = & V_80 -> V_35 ;
F_53 ( V_82 ) ;
F_50 ( V_82 ) ;
if ( V_35 -> V_48 )
F_20 ( V_2 -> V_49 ) ;
return 0 ;
}
