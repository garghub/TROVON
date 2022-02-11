T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_3 ( V_6 -> V_13 ) ;
const struct V_14 * V_15 ;
const unsigned char * V_16 ;
T_2 V_17 = 0 ;
F_4 () ;
V_15 = F_5 ( V_14 ) ;
if ( V_15 && V_15 -> V_18 ( V_2 ) ) {
F_6 () ;
return V_19 ;
}
F_7 ( & V_12 -> V_20 ) ;
V_12 -> V_21 ++ ;
V_12 -> V_22 += V_2 -> V_23 ;
F_8 ( & V_12 -> V_20 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) -> V_24 = V_4 ;
F_11 ( V_2 ) ;
F_12 ( V_2 , V_25 ) ;
if ( ! F_13 ( V_6 , F_14 ( V_6 ) , V_2 , & V_17 ) )
goto V_26;
V_16 = F_15 ( V_2 ) -> V_27 ;
if ( F_16 ( V_16 ) ) {
F_17 ( V_6 , V_2 , V_28 , false , true ) ;
} else if ( F_18 ( V_16 ) ) {
if ( F_19 ( F_20 ( V_4 ) ) ) {
F_17 ( V_6 , V_2 , V_29 , false , true ) ;
goto V_26;
}
if ( F_21 ( V_6 , NULL , V_2 , V_17 ) ) {
F_22 ( V_2 ) ;
goto V_26;
}
V_10 = F_23 ( V_6 , V_2 , V_17 ) ;
if ( ( V_10 || F_24 ( V_2 ) ) &&
F_25 ( V_6 , F_15 ( V_2 ) ) )
F_26 ( V_10 , V_2 , false , true ) ;
else
F_17 ( V_6 , V_2 , V_29 , false , true ) ;
} else if ( ( V_8 = F_27 ( V_6 , V_16 , V_17 ) ) != NULL ) {
F_28 ( V_8 -> V_8 , V_2 , false , true ) ;
} else {
F_17 ( V_6 , V_2 , V_30 , false , true ) ;
}
V_26:
F_6 () ;
return V_19 ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_30 ( & V_4 -> V_31 , & V_32 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_33 ;
V_6 -> V_13 = F_32 ( struct V_11 ) ;
if ( ! V_6 -> V_13 )
return - V_34 ;
V_33 = F_33 ( V_6 ) ;
if ( V_33 ) {
F_34 ( V_6 -> V_13 ) ;
return V_33 ;
}
V_33 = F_35 ( V_6 ) ;
if ( V_33 ) {
F_34 ( V_6 -> V_13 ) ;
F_36 ( V_6 ) ;
}
F_29 ( V_4 ) ;
return V_33 ;
}
static void F_37 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_36 ( V_6 ) ;
F_34 ( V_6 -> V_13 ) ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_41 ( V_4 ) ;
F_42 ( V_4 ) ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
}
static void F_46 ( struct V_3 * V_4 , int V_35 )
{
if ( V_35 & V_36 )
F_47 ( F_2 ( V_4 ) ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_49 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_4 ) ;
return 0 ;
}
static void F_52 ( struct V_3 * V_4 ,
struct V_37 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 V_38 , V_39 = { 0 } ;
unsigned int V_40 ;
F_53 (cpu) {
unsigned int V_41 ;
const struct V_11 * V_42
= F_54 ( V_6 -> V_13 , V_40 ) ;
do {
V_41 = F_55 ( & V_42 -> V_20 ) ;
memcpy ( & V_38 , V_42 , sizeof( V_38 ) ) ;
} while ( F_56 ( & V_42 -> V_20 , V_41 ) );
V_39 . V_22 += V_38 . V_22 ;
V_39 . V_21 += V_38 . V_21 ;
V_39 . V_43 += V_38 . V_43 ;
V_39 . V_44 += V_38 . V_44 ;
}
V_13 -> V_22 = V_39 . V_22 ;
V_13 -> V_21 = V_39 . V_21 ;
V_13 -> V_43 = V_39 . V_43 ;
V_13 -> V_44 = V_39 . V_44 ;
}
static int F_57 ( struct V_3 * V_4 , int V_45 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_45 > F_58 ( V_6 ) )
return - V_46 ;
V_4 -> V_47 = V_45 ;
#if F_59 ( V_48 )
F_60 ( & V_6 -> V_49 . V_8 , V_50 , V_45 ) ;
#endif
return 0 ;
}
static int F_61 ( struct V_3 * V_4 , void * V_51 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_52 * V_53 = V_51 ;
if ( ! F_62 ( V_53 -> V_54 ) )
return - V_55 ;
F_63 ( & V_6 -> V_56 ) ;
if ( ! F_64 ( V_4 -> V_57 , V_53 -> V_54 ) ) {
F_65 ( V_6 , V_53 -> V_54 ) ;
}
F_66 ( & V_6 -> V_56 ) ;
return 0 ;
}
static void F_67 ( struct V_3 * V_4 , struct V_58 * V_59 )
{
F_68 ( V_59 -> V_60 , L_1 , sizeof( V_59 -> V_60 ) ) ;
F_68 ( V_59 -> V_61 , V_62 , sizeof( V_59 -> V_61 ) ) ;
F_68 ( V_59 -> V_63 , L_2 , sizeof( V_59 -> V_63 ) ) ;
F_68 ( V_59 -> V_64 , L_2 , sizeof( V_59 -> V_64 ) ) ;
}
static T_3 F_69 ( struct V_3 * V_4 ,
T_3 V_65 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_70 ( V_6 , V_65 ) ;
}
static void F_71 ( struct V_3 * V_66 )
{
}
static void F_72 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_67 * V_51 ;
F_73 (p, &br->port_list, list)
F_74 ( V_51 ) ;
}
static int F_75 ( struct V_67 * V_51 )
{
struct V_68 * V_69 ;
int V_33 ;
V_69 = F_76 ( sizeof( * V_51 -> V_69 ) , V_70 ) ;
if ( ! V_69 )
return - V_34 ;
V_33 = F_77 ( V_69 , V_51 -> V_4 ) ;
if ( V_33 ) {
F_78 ( V_69 ) ;
return V_33 ;
}
V_51 -> V_69 = V_69 ;
return V_33 ;
}
int F_79 ( struct V_67 * V_51 )
{
if ( ! V_51 -> V_6 -> V_4 -> V_71 )
return 0 ;
return F_75 ( V_51 ) ;
}
static int F_80 ( struct V_3 * V_4 , struct V_72 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_67 * V_51 ;
int V_33 = 0 ;
F_73 (p, &br->port_list, list) {
if ( ! V_51 -> V_4 )
continue;
V_33 = F_75 ( V_51 ) ;
if ( V_33 )
goto V_74;
}
V_26:
return V_33 ;
V_74:
F_72 ( V_4 ) ;
goto V_26;
}
void F_74 ( struct V_67 * V_51 )
{
struct V_68 * V_69 = V_51 -> V_69 ;
if ( ! V_69 )
return;
V_51 -> V_69 = NULL ;
F_81 ( V_69 ) ;
}
static int F_82 ( struct V_3 * V_4 , struct V_3 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_83 ( V_6 , V_75 ) ;
}
static int F_84 ( struct V_3 * V_4 , struct V_3 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_85 ( V_6 , V_75 ) ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_87 ( V_4 ) ;
F_88 ( V_4 ) ;
V_4 -> V_76 = & V_77 ;
V_4 -> V_78 = true ;
V_4 -> V_79 = & V_80 ;
F_89 ( V_4 , & V_81 ) ;
V_4 -> V_82 = V_83 | V_84 ;
V_4 -> V_65 = V_85 | V_86 | V_87 |
V_88 | V_89 ;
V_4 -> V_90 = V_85 | V_88 |
V_89 ;
V_4 -> V_91 = V_85 ;
V_6 -> V_4 = V_4 ;
F_90 ( & V_6 -> V_56 ) ;
F_91 ( & V_6 -> V_92 ) ;
F_90 ( & V_6 -> V_93 ) ;
V_6 -> V_94 . V_95 [ 0 ] = 0x80 ;
V_6 -> V_94 . V_95 [ 1 ] = 0x00 ;
F_92 ( V_6 -> V_96 , V_97 ) ;
V_6 -> V_98 = V_99 ;
V_6 -> V_100 = V_101 ;
V_6 -> V_102 = V_101 ;
V_6 -> V_103 = V_6 -> V_94 ;
V_6 -> V_104 = V_6 -> V_105 = 20 * V_106 ;
V_6 -> V_107 = V_6 -> V_108 = 2 * V_106 ;
V_6 -> V_109 = V_6 -> V_110 = 15 * V_106 ;
V_6 -> V_111 = V_6 -> V_112 = V_113 ;
V_4 -> V_114 = V_115 ;
F_93 ( V_6 ) ;
F_94 ( V_6 ) ;
F_95 ( V_6 ) ;
F_96 ( & V_6 -> V_116 , V_117 ) ;
}
