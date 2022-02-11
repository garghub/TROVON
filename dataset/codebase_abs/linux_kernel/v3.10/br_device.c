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
F_16 ( V_6 , V_2 ) ;
else if ( F_17 ( V_7 ) ) {
if ( F_18 ( F_19 ( V_4 ) ) ) {
F_16 ( V_6 , V_2 ) ;
goto V_25;
}
if ( F_20 ( V_6 , NULL , V_2 ) ) {
F_21 ( V_2 ) ;
goto V_25;
}
V_12 = F_22 ( V_6 , V_2 , V_16 ) ;
if ( V_12 || F_23 ( V_2 ) )
F_24 ( V_12 , V_2 ) ;
else
F_16 ( V_6 , V_2 ) ;
} else if ( ( V_10 = F_25 ( V_6 , V_7 , V_16 ) ) != NULL )
F_26 ( V_10 -> V_10 , V_2 ) ;
else
F_16 ( V_6 , V_2 ) ;
V_25:
F_7 () ;
return V_20 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_15 = F_28 ( struct V_13 ) ;
if ( ! V_6 -> V_15 )
return - V_28 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_30 ( V_4 ) ;
F_31 ( V_4 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 )
{
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static struct V_29 * F_39 ( struct V_3 * V_4 ,
struct V_29 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_30 , V_31 = { 0 } ;
unsigned int V_32 ;
F_40 (cpu) {
unsigned int V_33 ;
const struct V_13 * V_34
= F_41 ( V_6 -> V_15 , V_32 ) ;
do {
V_33 = F_42 ( & V_34 -> V_21 ) ;
memcpy ( & V_30 , V_34 , sizeof( V_30 ) ) ;
} while ( F_43 ( & V_34 -> V_21 , V_33 ) );
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
static int F_44 ( struct V_3 * V_4 , int V_37 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_37 < 68 || V_37 > F_45 ( V_6 ) )
return - V_38 ;
V_4 -> V_39 = V_37 ;
#ifdef F_5
F_46 ( & V_6 -> V_40 . V_10 , V_41 , V_37 ) ;
#endif
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , void * V_42 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_43 * V_44 = V_42 ;
if ( ! F_48 ( V_44 -> V_45 ) )
return - V_46 ;
F_49 ( & V_6 -> V_47 ) ;
if ( ! F_50 ( V_4 -> V_48 , V_44 -> V_45 ) ) {
memcpy ( V_4 -> V_48 , V_44 -> V_45 , V_49 ) ;
F_51 ( V_6 , V_44 -> V_45 ) ;
F_52 ( V_6 , V_44 -> V_45 ) ;
}
F_53 ( & V_6 -> V_47 ) ;
return 0 ;
}
static void F_54 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
F_55 ( V_51 -> V_52 , L_1 , sizeof( V_51 -> V_52 ) ) ;
F_55 ( V_51 -> V_53 , V_54 , sizeof( V_51 -> V_53 ) ) ;
F_55 ( V_51 -> V_55 , L_2 , sizeof( V_51 -> V_55 ) ) ;
F_55 ( V_51 -> V_56 , L_2 , sizeof( V_51 -> V_56 ) ) ;
}
static T_3 F_56 ( struct V_3 * V_4 ,
T_3 V_57 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_57 ( V_6 , V_57 ) ;
}
static void F_58 ( struct V_3 * V_58 )
{
}
static void F_59 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_42 ;
F_60 (p, &br->port_list, list)
F_61 ( V_42 ) ;
}
static int F_62 ( struct V_3 * V_4 , struct V_60 * V_61 ,
T_4 V_62 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_42 ;
int V_63 = 0 ;
F_60 (p, &br->port_list, list) {
if ( ! V_42 -> V_4 )
continue;
V_63 = F_63 ( V_42 , V_62 ) ;
if ( V_63 )
goto V_64;
}
V_25:
return V_63 ;
V_64:
F_59 ( V_4 ) ;
goto V_25;
}
int F_63 ( struct V_59 * V_42 , T_4 V_62 )
{
struct V_65 * V_66 ;
int V_63 = 0 ;
V_66 = F_64 ( sizeof( * V_42 -> V_66 ) , V_62 ) ;
V_63 = - V_28 ;
if ( ! V_66 )
goto V_25;
V_63 = F_65 ( V_66 , V_42 -> V_4 , V_62 ) ;
if ( V_63 ) {
F_66 ( V_66 ) ;
goto V_25;
}
V_42 -> V_66 = V_66 ;
V_25:
return V_63 ;
}
void F_61 ( struct V_59 * V_42 )
{
struct V_65 * V_66 = V_42 -> V_66 ;
if ( ! V_66 )
return;
V_42 -> V_66 = NULL ;
F_67 ( V_66 ) ;
}
static int F_68 ( struct V_3 * V_4 , struct V_3 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_69 ( V_6 , V_67 ) ;
}
static int F_70 ( struct V_3 * V_4 , struct V_3 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_71 ( V_6 , V_67 ) ;
}
static void F_72 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_73 ( V_6 -> V_15 ) ;
F_74 ( V_4 ) ;
}
void F_75 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_76 ( V_4 ) ;
F_77 ( V_4 ) ;
V_4 -> V_68 = & V_69 ;
V_4 -> V_70 = F_72 ;
F_78 ( V_4 , & V_71 ) ;
F_79 ( V_4 , & V_72 ) ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_57 = V_76 | V_77 | V_78 |
V_79 | V_80 | V_81 |
V_82 | V_83 ;
V_4 -> V_84 = V_76 | V_77 | V_78 |
V_79 | V_80 |
V_83 ;
V_6 -> V_4 = V_4 ;
F_80 ( & V_6 -> V_47 ) ;
F_81 ( & V_6 -> V_85 ) ;
F_80 ( & V_6 -> V_86 ) ;
V_6 -> V_87 . V_88 [ 0 ] = 0x80 ;
V_6 -> V_87 . V_88 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_89 , V_90 , V_49 ) ;
V_6 -> V_91 = V_92 ;
V_6 -> V_93 = V_94 ;
V_6 -> V_95 = V_6 -> V_87 ;
V_6 -> V_96 = V_6 -> V_97 = 20 * V_98 ;
V_6 -> V_99 = V_6 -> V_100 = 2 * V_98 ;
V_6 -> V_101 = V_6 -> V_102 = 15 * V_98 ;
V_6 -> V_103 = 300 * V_98 ;
F_82 ( V_6 ) ;
F_83 ( V_6 ) ;
F_84 ( V_6 ) ;
}
