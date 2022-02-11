T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
const unsigned char * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_3 ( V_6 -> V_15 ) ;
const struct V_16 * V_17 ;
T_2 V_18 = 0 ;
F_4 () ;
V_17 = F_5 ( V_16 ) ;
if ( V_17 && V_17 -> V_19 ( V_2 ) ) {
F_6 () ;
return V_20 ;
}
F_7 ( & V_14 -> V_21 ) ;
V_14 -> V_22 ++ ;
V_14 -> V_23 += V_2 -> V_24 ;
F_8 ( & V_14 -> V_21 ) ;
F_9 ( V_2 ) -> V_25 = V_4 ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_26 ) ;
if ( ! F_12 ( V_6 , F_13 ( V_6 ) , V_2 , & V_18 ) )
goto V_27;
if ( F_14 ( V_7 ) ) {
F_15 ( V_6 , V_2 , false , false , true ) ;
} else if ( F_16 ( V_7 ) ) {
if ( F_17 ( F_18 ( V_4 ) ) ) {
F_15 ( V_6 , V_2 , false , false , true ) ;
goto V_27;
}
if ( F_19 ( V_6 , NULL , V_2 , V_18 ) ) {
F_20 ( V_2 ) ;
goto V_27;
}
V_12 = F_21 ( V_6 , V_2 , V_18 ) ;
if ( ( V_12 || F_22 ( V_2 ) ) &&
F_23 ( V_6 , F_24 ( V_2 ) ) )
F_25 ( V_12 , V_2 , false , true ) ;
else
F_15 ( V_6 , V_2 , false , false , true ) ;
} else if ( ( V_10 = F_26 ( V_6 , V_7 , V_18 ) ) != NULL ) {
F_27 ( V_10 -> V_10 , V_2 , false , true ) ;
} else {
F_15 ( V_6 , V_2 , true , false , true ) ;
}
V_27:
F_6 () ;
return V_20 ;
}
static void F_28 ( struct V_3 * V_4 )
{
F_29 ( & V_4 -> V_28 , & V_29 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_30 ;
V_6 -> V_15 = F_31 ( struct V_13 ) ;
if ( ! V_6 -> V_15 )
return - V_31 ;
V_30 = F_32 ( V_6 ) ;
if ( V_30 ) {
F_33 ( V_6 -> V_15 ) ;
return V_30 ;
}
V_30 = F_34 ( V_6 ) ;
if ( V_30 ) {
F_33 ( V_6 -> V_15 ) ;
F_35 ( V_6 ) ;
}
F_28 ( V_4 ) ;
return V_30 ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
return 0 ;
}
static void F_41 ( struct V_3 * V_4 )
{
}
static void F_42 ( struct V_3 * V_4 , int V_32 )
{
if ( V_32 & V_33 )
F_43 ( F_2 ( V_4 ) ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_45 ( V_6 ) ;
F_46 ( V_6 ) ;
F_47 ( V_4 ) ;
return 0 ;
}
static struct V_34 * F_48 ( struct V_3 * V_4 ,
struct V_34 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_35 , V_36 = { 0 } ;
unsigned int V_37 ;
F_49 (cpu) {
unsigned int V_38 ;
const struct V_13 * V_39
= F_50 ( V_6 -> V_15 , V_37 ) ;
do {
V_38 = F_51 ( & V_39 -> V_21 ) ;
memcpy ( & V_35 , V_39 , sizeof( V_35 ) ) ;
} while ( F_52 ( & V_39 -> V_21 , V_38 ) );
V_36 . V_23 += V_35 . V_23 ;
V_36 . V_22 += V_35 . V_22 ;
V_36 . V_40 += V_35 . V_40 ;
V_36 . V_41 += V_35 . V_41 ;
}
V_15 -> V_23 = V_36 . V_23 ;
V_15 -> V_22 = V_36 . V_22 ;
V_15 -> V_40 = V_36 . V_40 ;
V_15 -> V_41 = V_36 . V_41 ;
return V_15 ;
}
static int F_53 ( struct V_3 * V_4 , int V_42 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_42 < 68 || V_42 > F_54 ( V_6 ) )
return - V_43 ;
V_4 -> V_44 = V_42 ;
#if F_55 ( V_45 )
F_56 ( & V_6 -> V_46 . V_10 , V_47 , V_42 ) ;
#endif
return 0 ;
}
static int F_57 ( struct V_3 * V_4 , void * V_48 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_49 * V_50 = V_48 ;
if ( ! F_58 ( V_50 -> V_51 ) )
return - V_52 ;
F_59 ( & V_6 -> V_53 ) ;
if ( ! F_60 ( V_4 -> V_54 , V_50 -> V_51 ) ) {
F_61 ( V_6 , V_50 -> V_51 ) ;
}
F_62 ( & V_6 -> V_53 ) ;
return 0 ;
}
static void F_63 ( struct V_3 * V_4 , struct V_55 * V_56 )
{
F_64 ( V_56 -> V_57 , L_1 , sizeof( V_56 -> V_57 ) ) ;
F_64 ( V_56 -> V_58 , V_59 , sizeof( V_56 -> V_58 ) ) ;
F_64 ( V_56 -> V_60 , L_2 , sizeof( V_56 -> V_60 ) ) ;
F_64 ( V_56 -> V_61 , L_2 , sizeof( V_56 -> V_61 ) ) ;
}
static T_3 F_65 ( struct V_3 * V_4 ,
T_3 V_62 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_66 ( V_6 , V_62 ) ;
}
static void F_67 ( struct V_3 * V_63 )
{
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_64 * V_48 ;
F_69 (p, &br->port_list, list)
F_70 ( V_48 ) ;
}
static int F_71 ( struct V_64 * V_48 )
{
struct V_65 * V_66 ;
int V_30 ;
V_66 = F_72 ( sizeof( * V_48 -> V_66 ) , V_67 ) ;
if ( ! V_66 )
return - V_31 ;
V_30 = F_73 ( V_66 , V_48 -> V_4 ) ;
if ( V_30 ) {
F_74 ( V_66 ) ;
return V_30 ;
}
V_48 -> V_66 = V_66 ;
return V_30 ;
}
int F_75 ( struct V_64 * V_48 )
{
if ( ! V_48 -> V_6 -> V_4 -> V_68 )
return 0 ;
return F_71 ( V_48 ) ;
}
static int F_76 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_64 * V_48 ;
int V_30 = 0 ;
F_69 (p, &br->port_list, list) {
if ( ! V_48 -> V_4 )
continue;
V_30 = F_71 ( V_48 ) ;
if ( V_30 )
goto V_71;
}
V_27:
return V_30 ;
V_71:
F_68 ( V_4 ) ;
goto V_27;
}
void F_70 ( struct V_64 * V_48 )
{
struct V_65 * V_66 = V_48 -> V_66 ;
if ( ! V_66 )
return;
V_48 -> V_66 = NULL ;
F_77 ( V_66 ) ;
}
static int F_78 ( struct V_3 * V_4 , struct V_3 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_79 ( V_6 , V_72 ) ;
}
static int F_80 ( struct V_3 * V_4 , struct V_3 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_81 ( V_6 , V_72 ) ;
}
static void F_82 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_33 ( V_6 -> V_15 ) ;
F_83 ( V_4 ) ;
}
void F_84 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_85 ( V_4 ) ;
F_86 ( V_4 ) ;
V_4 -> V_73 = & V_74 ;
V_4 -> V_75 = F_82 ;
V_4 -> V_76 = & V_77 ;
F_87 ( V_4 , & V_78 ) ;
V_4 -> V_79 = V_80 | V_81 ;
V_4 -> V_62 = V_82 | V_83 | V_84 |
V_85 | V_86 ;
V_4 -> V_87 = V_82 | V_85 |
V_86 ;
V_4 -> V_88 = V_82 ;
V_6 -> V_4 = V_4 ;
F_88 ( & V_6 -> V_53 ) ;
F_89 ( & V_6 -> V_89 ) ;
F_88 ( & V_6 -> V_90 ) ;
V_6 -> V_91 . V_92 [ 0 ] = 0x80 ;
V_6 -> V_91 . V_92 [ 1 ] = 0x00 ;
F_90 ( V_6 -> V_93 , V_94 ) ;
V_6 -> V_95 = V_96 ;
V_6 -> V_97 = V_98 ;
V_6 -> V_99 = V_98 ;
V_6 -> V_100 = V_6 -> V_91 ;
V_6 -> V_101 = V_6 -> V_102 = 20 * V_103 ;
V_6 -> V_104 = V_6 -> V_105 = 2 * V_103 ;
V_6 -> V_106 = V_6 -> V_107 = 15 * V_103 ;
V_6 -> V_108 = V_109 ;
F_91 ( V_6 ) ;
F_92 ( V_6 ) ;
F_93 ( V_6 ) ;
}
