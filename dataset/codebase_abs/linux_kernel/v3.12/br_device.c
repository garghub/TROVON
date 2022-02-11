T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
const unsigned char * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_3 ( V_6 -> V_15 ) ;
T_2 V_16 = 0 ;
F_4 () ;
#ifdef F_5
if ( V_2 -> V_17 && ( V_2 -> V_17 -> V_18 & V_19 ) ) {
F_6 ( V_2 ) ;
F_7 () ;
return V_20 ;
}
#endif
F_8 ( & V_14 -> V_21 ) ;
V_14 -> V_22 ++ ;
V_14 -> V_23 += V_2 -> V_24 ;
F_9 ( & V_14 -> V_21 ) ;
if ( ! F_10 ( V_6 , F_11 ( V_6 ) , V_2 , & V_16 ) )
goto V_25;
F_12 ( V_2 ) -> V_26 = V_4 ;
F_13 ( V_2 ) ;
F_14 ( V_2 , V_27 ) ;
if ( F_15 ( V_7 ) )
F_16 ( V_6 , V_2 , false ) ;
else if ( F_17 ( V_7 ) ) {
if ( F_18 ( F_19 ( V_4 ) ) ) {
F_16 ( V_6 , V_2 , false ) ;
goto V_25;
}
if ( F_20 ( V_6 , NULL , V_2 ) ) {
F_21 ( V_2 ) ;
goto V_25;
}
V_12 = F_22 ( V_6 , V_2 , V_16 ) ;
if ( ( V_12 || F_23 ( V_2 ) ) &&
F_24 ( V_6 , F_25 ( V_2 ) ) )
F_26 ( V_12 , V_2 ) ;
else
F_16 ( V_6 , V_2 , false ) ;
} else if ( ( V_10 = F_27 ( V_6 , V_7 , V_16 ) ) != NULL )
F_28 ( V_10 -> V_10 , V_2 ) ;
else
F_16 ( V_6 , V_2 , true ) ;
V_25:
F_7 () ;
return V_20 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_15 = F_30 ( struct V_13 ) ;
if ( ! V_6 -> V_15 )
return - V_28 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_32 ( V_4 ) ;
F_33 ( V_4 ) ;
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_40 ( V_4 ) ;
return 0 ;
}
static struct V_29 * F_41 ( struct V_3 * V_4 ,
struct V_29 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_30 , V_31 = { 0 } ;
unsigned int V_32 ;
F_42 (cpu) {
unsigned int V_33 ;
const struct V_13 * V_34
= F_43 ( V_6 -> V_15 , V_32 ) ;
do {
V_33 = F_44 ( & V_34 -> V_21 ) ;
memcpy ( & V_30 , V_34 , sizeof( V_30 ) ) ;
} while ( F_45 ( & V_34 -> V_21 , V_33 ) );
V_31 . V_23 += V_30 . V_23 ;
V_31 . V_22 += V_30 . V_22 ;
V_31 . V_35 += V_30 . V_35 ;
V_31 . V_36 += V_30 . V_36 ;
}
V_15 -> V_23 = V_31 . V_23 ;
V_15 -> V_22 = V_31 . V_22 ;
V_15 -> V_35 = V_31 . V_35 ;
V_15 -> V_36 = V_31 . V_36 ;
return V_15 ;
}
static int F_46 ( struct V_3 * V_4 , int V_37 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_37 < 68 || V_37 > F_47 ( V_6 ) )
return - V_38 ;
V_4 -> V_39 = V_37 ;
#ifdef F_5
F_48 ( & V_6 -> V_40 . V_10 , V_41 , V_37 ) ;
#endif
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , void * V_42 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_43 * V_44 = V_42 ;
if ( ! F_50 ( V_44 -> V_45 ) )
return - V_46 ;
F_51 ( & V_6 -> V_47 ) ;
if ( ! F_52 ( V_4 -> V_48 , V_44 -> V_45 ) ) {
memcpy ( V_4 -> V_48 , V_44 -> V_45 , V_49 ) ;
F_53 ( V_6 , V_44 -> V_45 ) ;
F_54 ( V_6 , V_44 -> V_45 ) ;
}
F_55 ( & V_6 -> V_47 ) ;
return 0 ;
}
static void F_56 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
F_57 ( V_51 -> V_52 , L_1 , sizeof( V_51 -> V_52 ) ) ;
F_57 ( V_51 -> V_53 , V_54 , sizeof( V_51 -> V_53 ) ) ;
F_57 ( V_51 -> V_55 , L_2 , sizeof( V_51 -> V_55 ) ) ;
F_57 ( V_51 -> V_56 , L_2 , sizeof( V_51 -> V_56 ) ) ;
}
static T_3 F_58 ( struct V_3 * V_4 ,
T_3 V_57 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_59 ( V_6 , V_57 ) ;
}
static void F_60 ( struct V_3 * V_58 )
{
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_42 ;
F_62 (p, &br->port_list, list)
F_63 ( V_42 ) ;
}
static int F_64 ( struct V_3 * V_4 , struct V_60 * V_61 ,
T_4 V_62 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_42 ;
int V_63 = 0 ;
F_62 (p, &br->port_list, list) {
if ( ! V_42 -> V_4 )
continue;
V_63 = F_65 ( V_42 , V_62 ) ;
if ( V_63 )
goto V_64;
}
V_25:
return V_63 ;
V_64:
F_61 ( V_4 ) ;
goto V_25;
}
int F_65 ( struct V_59 * V_42 , T_4 V_62 )
{
struct V_65 * V_66 ;
int V_63 ;
if ( ! V_42 -> V_6 -> V_4 -> V_67 )
return 0 ;
V_66 = F_66 ( sizeof( * V_42 -> V_66 ) , V_62 ) ;
if ( ! V_66 )
return - V_28 ;
V_63 = F_67 ( V_66 , V_42 -> V_4 , V_62 ) ;
if ( V_63 ) {
F_68 ( V_66 ) ;
return V_63 ;
}
V_42 -> V_66 = V_66 ;
return V_63 ;
}
void F_63 ( struct V_59 * V_42 )
{
struct V_65 * V_66 = V_42 -> V_66 ;
if ( ! V_66 )
return;
V_42 -> V_66 = NULL ;
F_69 ( V_66 ) ;
}
static int F_70 ( struct V_3 * V_4 , struct V_3 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_71 ( V_6 , V_68 ) ;
}
static int F_72 ( struct V_3 * V_4 , struct V_3 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_73 ( V_6 , V_68 ) ;
}
static void F_74 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_75 ( V_6 -> V_15 ) ;
F_76 ( V_4 ) ;
}
void F_77 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_78 ( V_4 ) ;
F_79 ( V_4 ) ;
V_4 -> V_69 = & V_70 ;
V_4 -> V_71 = F_74 ;
F_80 ( V_4 , & V_72 ) ;
F_81 ( V_4 , & V_73 ) ;
V_4 -> V_74 = 0 ;
V_4 -> V_75 = V_76 ;
V_4 -> V_57 = V_77 | V_78 | V_79 |
V_80 ;
V_4 -> V_81 = V_77 | V_80 ;
V_4 -> V_82 = V_77 ;
V_6 -> V_4 = V_4 ;
F_82 ( & V_6 -> V_47 ) ;
F_83 ( & V_6 -> V_83 ) ;
F_82 ( & V_6 -> V_84 ) ;
V_6 -> V_85 . V_86 [ 0 ] = 0x80 ;
V_6 -> V_85 . V_86 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_87 , V_88 , V_49 ) ;
V_6 -> V_89 = V_90 ;
V_6 -> V_91 = V_92 ;
V_6 -> V_93 = V_6 -> V_85 ;
V_6 -> V_94 = V_6 -> V_95 = 20 * V_96 ;
V_6 -> V_97 = V_6 -> V_98 = 2 * V_96 ;
V_6 -> V_99 = V_6 -> V_100 = 15 * V_96 ;
V_6 -> V_101 = 300 * V_96 ;
F_84 ( V_6 ) ;
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
}
