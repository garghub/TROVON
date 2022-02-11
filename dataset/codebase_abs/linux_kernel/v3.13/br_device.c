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
if ( F_20 ( V_6 , NULL , V_2 , V_16 ) ) {
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
int V_28 ;
V_6 -> V_15 = F_30 ( struct V_13 ) ;
if ( ! V_6 -> V_15 )
return - V_29 ;
F_31 (i) {
struct V_13 * V_30 ;
V_30 = F_32 ( V_6 -> V_15 , V_28 ) ;
F_33 ( & V_30 -> V_21 ) ;
}
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_41 ( V_6 ) ;
F_42 ( V_6 ) ;
F_43 ( V_4 ) ;
return 0 ;
}
static struct V_31 * F_44 ( struct V_3 * V_4 ,
struct V_31 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_32 , V_33 = { 0 } ;
unsigned int V_34 ;
F_31 (cpu) {
unsigned int V_35 ;
const struct V_13 * V_36
= F_32 ( V_6 -> V_15 , V_34 ) ;
do {
V_35 = F_45 ( & V_36 -> V_21 ) ;
memcpy ( & V_32 , V_36 , sizeof( V_32 ) ) ;
} while ( F_46 ( & V_36 -> V_21 , V_35 ) );
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
static int F_47 ( struct V_3 * V_4 , int V_39 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_39 < 68 || V_39 > F_48 ( V_6 ) )
return - V_40 ;
V_4 -> V_41 = V_39 ;
#ifdef F_5
F_49 ( & V_6 -> V_42 . V_10 , V_43 , V_39 ) ;
#endif
return 0 ;
}
static int F_50 ( struct V_3 * V_4 , void * V_44 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_45 * V_46 = V_44 ;
if ( ! F_51 ( V_46 -> V_47 ) )
return - V_48 ;
F_52 ( & V_6 -> V_49 ) ;
if ( ! F_53 ( V_4 -> V_50 , V_46 -> V_47 ) ) {
memcpy ( V_4 -> V_50 , V_46 -> V_47 , V_51 ) ;
F_54 ( V_6 , V_46 -> V_47 ) ;
F_55 ( V_6 , V_46 -> V_47 ) ;
}
F_56 ( & V_6 -> V_49 ) ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 , struct V_52 * V_53 )
{
F_58 ( V_53 -> V_54 , L_1 , sizeof( V_53 -> V_54 ) ) ;
F_58 ( V_53 -> V_55 , V_56 , sizeof( V_53 -> V_55 ) ) ;
F_58 ( V_53 -> V_57 , L_2 , sizeof( V_53 -> V_57 ) ) ;
F_58 ( V_53 -> V_58 , L_2 , sizeof( V_53 -> V_58 ) ) ;
}
static T_3 F_59 ( struct V_3 * V_4 ,
T_3 V_59 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_60 ( V_6 , V_59 ) ;
}
static void F_61 ( struct V_3 * V_60 )
{
}
static void F_62 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_61 * V_44 ;
F_63 (p, &br->port_list, list)
F_64 ( V_44 ) ;
}
static int F_65 ( struct V_3 * V_4 , struct V_62 * V_63 ,
T_4 V_64 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_61 * V_44 ;
int V_65 = 0 ;
F_63 (p, &br->port_list, list) {
if ( ! V_44 -> V_4 )
continue;
V_65 = F_66 ( V_44 , V_64 ) ;
if ( V_65 )
goto V_66;
}
V_25:
return V_65 ;
V_66:
F_62 ( V_4 ) ;
goto V_25;
}
int F_66 ( struct V_61 * V_44 , T_4 V_64 )
{
struct V_67 * V_68 ;
int V_65 ;
if ( ! V_44 -> V_6 -> V_4 -> V_69 )
return 0 ;
V_68 = F_67 ( sizeof( * V_44 -> V_68 ) , V_64 ) ;
if ( ! V_68 )
return - V_29 ;
V_65 = F_68 ( V_68 , V_44 -> V_4 , V_64 ) ;
if ( V_65 ) {
F_69 ( V_68 ) ;
return V_65 ;
}
V_44 -> V_68 = V_68 ;
return V_65 ;
}
void F_64 ( struct V_61 * V_44 )
{
struct V_67 * V_68 = V_44 -> V_68 ;
if ( ! V_68 )
return;
V_44 -> V_68 = NULL ;
F_70 ( V_68 ) ;
}
static int F_71 ( struct V_3 * V_4 , struct V_3 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_72 ( V_6 , V_70 ) ;
}
static int F_73 ( struct V_3 * V_4 , struct V_3 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_74 ( V_6 , V_70 ) ;
}
static void F_75 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_76 ( V_6 -> V_15 ) ;
F_77 ( V_4 ) ;
}
void F_78 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_79 ( V_4 ) ;
F_80 ( V_4 ) ;
V_4 -> V_71 = & V_72 ;
V_4 -> V_73 = F_75 ;
F_81 ( V_4 , & V_74 ) ;
F_82 ( V_4 , & V_75 ) ;
V_4 -> V_76 = 0 ;
V_4 -> V_77 = V_78 ;
V_4 -> V_59 = V_79 | V_80 | V_81 |
V_82 ;
V_4 -> V_83 = V_79 | V_82 ;
V_4 -> V_84 = V_79 ;
V_6 -> V_4 = V_4 ;
F_83 ( & V_6 -> V_49 ) ;
F_84 ( & V_6 -> V_85 ) ;
F_83 ( & V_6 -> V_86 ) ;
V_6 -> V_87 . V_88 [ 0 ] = 0x80 ;
V_6 -> V_87 . V_88 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_89 , V_90 , V_51 ) ;
V_6 -> V_91 = V_92 ;
V_6 -> V_93 = V_94 ;
V_6 -> V_95 = V_6 -> V_87 ;
V_6 -> V_96 = V_6 -> V_97 = 20 * V_98 ;
V_6 -> V_99 = V_6 -> V_100 = 2 * V_98 ;
V_6 -> V_101 = V_6 -> V_102 = 15 * V_98 ;
V_6 -> V_103 = 300 * V_98 ;
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
}
