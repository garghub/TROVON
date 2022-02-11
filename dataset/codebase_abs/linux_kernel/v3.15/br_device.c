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
F_10 ( V_2 ) -> V_25 = V_4 ;
F_11 ( V_2 ) ;
F_12 ( V_2 , V_26 ) ;
if ( ! F_13 ( V_6 , F_14 ( V_6 ) , V_2 , & V_16 ) )
goto V_27;
if ( F_15 ( V_7 ) )
F_16 ( V_6 , V_2 , false ) ;
else if ( F_17 ( V_7 ) ) {
if ( F_18 ( F_19 ( V_4 ) ) ) {
F_16 ( V_6 , V_2 , false ) ;
goto V_27;
}
if ( F_20 ( V_6 , NULL , V_2 , V_16 ) ) {
F_21 ( V_2 ) ;
goto V_27;
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
V_27:
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
F_53 ( V_6 , V_44 -> V_45 ) ;
}
F_54 ( & V_6 -> V_47 ) ;
return 0 ;
}
static void F_55 ( struct V_3 * V_4 , struct V_49 * V_50 )
{
F_56 ( V_50 -> V_51 , L_1 , sizeof( V_50 -> V_51 ) ) ;
F_56 ( V_50 -> V_52 , V_53 , sizeof( V_50 -> V_52 ) ) ;
F_56 ( V_50 -> V_54 , L_2 , sizeof( V_50 -> V_54 ) ) ;
F_56 ( V_50 -> V_55 , L_2 , sizeof( V_50 -> V_55 ) ) ;
}
static T_3 F_57 ( struct V_3 * V_4 ,
T_3 V_56 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_58 ( V_6 , V_56 ) ;
}
static void F_59 ( struct V_3 * V_57 )
{
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_58 * V_42 ;
F_61 (p, &br->port_list, list)
F_62 ( V_42 ) ;
}
static int F_63 ( struct V_58 * V_42 )
{
struct V_59 * V_60 ;
int V_61 ;
V_60 = F_64 ( sizeof( * V_42 -> V_60 ) , V_62 ) ;
if ( ! V_60 )
return - V_28 ;
V_61 = F_65 ( V_60 , V_42 -> V_4 ) ;
if ( V_61 ) {
F_66 ( V_60 ) ;
return V_61 ;
}
V_42 -> V_60 = V_60 ;
return V_61 ;
}
int F_67 ( struct V_58 * V_42 )
{
if ( ! V_42 -> V_6 -> V_4 -> V_63 )
return 0 ;
return F_63 ( V_42 ) ;
}
static int F_68 ( struct V_3 * V_4 , struct V_64 * V_65 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_58 * V_42 ;
int V_61 = 0 ;
F_61 (p, &br->port_list, list) {
if ( ! V_42 -> V_4 )
continue;
V_61 = F_63 ( V_42 ) ;
if ( V_61 )
goto V_66;
}
V_27:
return V_61 ;
V_66:
F_60 ( V_4 ) ;
goto V_27;
}
void F_62 ( struct V_58 * V_42 )
{
struct V_59 * V_60 = V_42 -> V_60 ;
if ( ! V_60 )
return;
V_42 -> V_60 = NULL ;
F_69 ( V_60 ) ;
}
static int F_70 ( struct V_3 * V_4 , struct V_3 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_71 ( V_6 , V_67 ) ;
}
static int F_72 ( struct V_3 * V_4 , struct V_3 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_73 ( V_6 , V_67 ) ;
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
V_4 -> V_68 = & V_69 ;
V_4 -> V_70 = F_74 ;
F_80 ( V_4 , & V_71 ) ;
F_81 ( V_4 , & V_72 ) ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = V_75 ;
V_4 -> V_56 = V_76 | V_77 | V_78 |
V_79 ;
V_4 -> V_80 = V_76 | V_79 ;
V_4 -> V_81 = V_76 ;
V_6 -> V_4 = V_4 ;
F_82 ( & V_6 -> V_47 ) ;
F_83 ( & V_6 -> V_82 ) ;
F_82 ( & V_6 -> V_83 ) ;
V_6 -> V_84 . V_85 [ 0 ] = 0x80 ;
V_6 -> V_84 . V_85 [ 1 ] = 0x00 ;
F_84 ( V_6 -> V_86 , V_87 ) ;
V_6 -> V_88 = V_89 ;
V_6 -> V_90 = V_91 ;
V_6 -> V_92 = V_6 -> V_84 ;
V_6 -> V_93 = V_6 -> V_94 = 20 * V_95 ;
V_6 -> V_96 = V_6 -> V_97 = 2 * V_95 ;
V_6 -> V_98 = V_6 -> V_99 = 15 * V_95 ;
V_6 -> V_100 = 300 * V_95 ;
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
}
