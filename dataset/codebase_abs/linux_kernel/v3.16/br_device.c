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
static void F_37 ( struct V_3 * V_4 , int V_29 )
{
if ( V_29 & V_30 )
F_38 ( F_2 ( V_4 ) ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_40 ( V_6 ) ;
F_41 ( V_6 ) ;
F_42 ( V_4 ) ;
return 0 ;
}
static struct V_31 * F_43 ( struct V_3 * V_4 ,
struct V_31 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_32 , V_33 = { 0 } ;
unsigned int V_34 ;
F_44 (cpu) {
unsigned int V_35 ;
const struct V_13 * V_36
= F_45 ( V_6 -> V_15 , V_34 ) ;
do {
V_35 = F_46 ( & V_36 -> V_21 ) ;
memcpy ( & V_32 , V_36 , sizeof( V_32 ) ) ;
} while ( F_47 ( & V_36 -> V_21 , V_35 ) );
V_33 . V_23 += V_32 . V_23 ;
V_33 . V_22 += V_32 . V_22 ;
V_33 . V_37 += V_32 . V_37 ;
V_33 . V_38 += V_32 . V_38 ;
}
V_15 -> V_23 = V_33 . V_23 ;
V_15 -> V_22 = V_33 . V_22 ;
V_15 -> V_37 = V_33 . V_37 ;
V_15 -> V_38 = V_33 . V_38 ;
return V_15 ;
}
static int F_48 ( struct V_3 * V_4 , int V_39 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_39 < 68 || V_39 > F_49 ( V_6 ) )
return - V_40 ;
V_4 -> V_41 = V_39 ;
#ifdef F_5
F_50 ( & V_6 -> V_42 . V_10 , V_43 , V_39 ) ;
#endif
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , void * V_44 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_45 * V_46 = V_44 ;
if ( ! F_52 ( V_46 -> V_47 ) )
return - V_48 ;
F_53 ( & V_6 -> V_49 ) ;
if ( ! F_54 ( V_4 -> V_50 , V_46 -> V_47 ) ) {
F_55 ( V_6 , V_46 -> V_47 ) ;
}
F_56 ( & V_6 -> V_49 ) ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_51 * V_52 )
{
F_58 ( V_52 -> V_53 , L_1 , sizeof( V_52 -> V_53 ) ) ;
F_58 ( V_52 -> V_54 , V_55 , sizeof( V_52 -> V_54 ) ) ;
F_58 ( V_52 -> V_56 , L_2 , sizeof( V_52 -> V_56 ) ) ;
F_58 ( V_52 -> V_57 , L_2 , sizeof( V_52 -> V_57 ) ) ;
}
static T_3 F_59 ( struct V_3 * V_4 ,
T_3 V_58 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_60 ( V_6 , V_58 ) ;
}
static void F_61 ( struct V_3 * V_59 )
{
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_60 * V_44 ;
F_63 (p, &br->port_list, list)
F_64 ( V_44 ) ;
}
static int F_65 ( struct V_60 * V_44 )
{
struct V_61 * V_62 ;
int V_63 ;
V_62 = F_66 ( sizeof( * V_44 -> V_62 ) , V_64 ) ;
if ( ! V_62 )
return - V_28 ;
V_63 = F_67 ( V_62 , V_44 -> V_4 ) ;
if ( V_63 ) {
F_68 ( V_62 ) ;
return V_63 ;
}
V_44 -> V_62 = V_62 ;
return V_63 ;
}
int F_69 ( struct V_60 * V_44 )
{
if ( ! V_44 -> V_6 -> V_4 -> V_65 )
return 0 ;
return F_65 ( V_44 ) ;
}
static int F_70 ( struct V_3 * V_4 , struct V_66 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_60 * V_44 ;
int V_63 = 0 ;
F_63 (p, &br->port_list, list) {
if ( ! V_44 -> V_4 )
continue;
V_63 = F_65 ( V_44 ) ;
if ( V_63 )
goto V_68;
}
V_27:
return V_63 ;
V_68:
F_62 ( V_4 ) ;
goto V_27;
}
void F_64 ( struct V_60 * V_44 )
{
struct V_61 * V_62 = V_44 -> V_62 ;
if ( ! V_62 )
return;
V_44 -> V_62 = NULL ;
F_71 ( V_62 ) ;
}
static int F_72 ( struct V_3 * V_4 , struct V_3 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_73 ( V_6 , V_69 ) ;
}
static int F_74 ( struct V_3 * V_4 , struct V_3 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_75 ( V_6 , V_69 ) ;
}
static void F_76 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_77 ( V_6 -> V_15 ) ;
F_78 ( V_4 ) ;
}
void F_79 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_80 ( V_4 ) ;
F_81 ( V_4 ) ;
V_4 -> V_70 = & V_71 ;
V_4 -> V_72 = F_76 ;
V_4 -> V_73 = & V_74 ;
F_82 ( V_4 , & V_75 ) ;
V_4 -> V_76 = 0 ;
V_4 -> V_77 = V_78 ;
V_4 -> V_58 = V_79 | V_80 | V_81 |
V_82 | V_83 ;
V_4 -> V_84 = V_79 | V_82 |
V_83 ;
V_4 -> V_85 = V_79 ;
V_6 -> V_4 = V_4 ;
F_83 ( & V_6 -> V_49 ) ;
F_84 ( & V_6 -> V_86 ) ;
F_83 ( & V_6 -> V_87 ) ;
V_6 -> V_88 . V_89 [ 0 ] = 0x80 ;
V_6 -> V_88 . V_89 [ 1 ] = 0x00 ;
F_85 ( V_6 -> V_90 , V_91 ) ;
V_6 -> V_92 = V_93 ;
V_6 -> V_94 = V_95 ;
V_6 -> V_96 = V_95 ;
V_6 -> V_97 = V_6 -> V_88 ;
V_6 -> V_98 = V_6 -> V_99 = 20 * V_100 ;
V_6 -> V_101 = V_6 -> V_102 = 2 * V_100 ;
V_6 -> V_103 = V_6 -> V_104 = 15 * V_100 ;
V_6 -> V_105 = 300 * V_100 ;
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
F_88 ( V_6 ) ;
F_89 ( V_6 ) ;
}
