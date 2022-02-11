T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
const unsigned char * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_3 ( V_6 -> V_15 ) ;
T_2 V_16 = 0 ;
F_4 () ;
#if F_5 ( V_17 )
if ( V_2 -> V_18 && ( V_2 -> V_18 -> V_19 & V_20 ) ) {
F_6 ( V_2 ) ;
F_7 () ;
return V_21 ;
}
#endif
F_8 ( & V_14 -> V_22 ) ;
V_14 -> V_23 ++ ;
V_14 -> V_24 += V_2 -> V_25 ;
F_9 ( & V_14 -> V_22 ) ;
F_10 ( V_2 ) -> V_26 = V_4 ;
F_11 ( V_2 ) ;
F_12 ( V_2 , V_27 ) ;
if ( ! F_13 ( V_6 , F_14 ( V_6 ) , V_2 , & V_16 ) )
goto V_28;
if ( F_15 ( V_7 ) )
F_16 ( V_6 , V_2 , false ) ;
else if ( F_17 ( V_7 ) ) {
if ( F_18 ( F_19 ( V_4 ) ) ) {
F_16 ( V_6 , V_2 , false ) ;
goto V_28;
}
if ( F_20 ( V_6 , NULL , V_2 , V_16 ) ) {
F_21 ( V_2 ) ;
goto V_28;
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
V_28:
F_7 () ;
return V_21 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_29 ;
V_6 -> V_15 = F_30 ( struct V_13 ) ;
if ( ! V_6 -> V_15 )
return - V_30 ;
V_29 = F_31 ( V_6 ) ;
if ( V_29 )
F_32 ( V_6 -> V_15 ) ;
return V_29 ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
return 0 ;
}
static void F_38 ( struct V_3 * V_4 )
{
}
static void F_39 ( struct V_3 * V_4 , int V_31 )
{
if ( V_31 & V_32 )
F_40 ( F_2 ( V_4 ) ) ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
F_44 ( V_4 ) ;
return 0 ;
}
static struct V_33 * F_45 ( struct V_3 * V_4 ,
struct V_33 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_34 , V_35 = { 0 } ;
unsigned int V_36 ;
F_46 (cpu) {
unsigned int V_37 ;
const struct V_13 * V_38
= F_47 ( V_6 -> V_15 , V_36 ) ;
do {
V_37 = F_48 ( & V_38 -> V_22 ) ;
memcpy ( & V_34 , V_38 , sizeof( V_34 ) ) ;
} while ( F_49 ( & V_38 -> V_22 , V_37 ) );
V_35 . V_24 += V_34 . V_24 ;
V_35 . V_23 += V_34 . V_23 ;
V_35 . V_39 += V_34 . V_39 ;
V_35 . V_40 += V_34 . V_40 ;
}
V_15 -> V_24 = V_35 . V_24 ;
V_15 -> V_23 = V_35 . V_23 ;
V_15 -> V_39 = V_35 . V_39 ;
V_15 -> V_40 = V_35 . V_40 ;
return V_15 ;
}
static int F_50 ( struct V_3 * V_4 , int V_41 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_41 < 68 || V_41 > F_51 ( V_6 ) )
return - V_42 ;
V_4 -> V_43 = V_41 ;
#if F_5 ( V_17 )
F_52 ( & V_6 -> V_44 . V_10 , V_45 , V_41 ) ;
#endif
return 0 ;
}
static int F_53 ( struct V_3 * V_4 , void * V_46 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_47 * V_48 = V_46 ;
if ( ! F_54 ( V_48 -> V_49 ) )
return - V_50 ;
F_55 ( & V_6 -> V_51 ) ;
if ( ! F_56 ( V_4 -> V_52 , V_48 -> V_49 ) ) {
F_57 ( V_6 , V_48 -> V_49 ) ;
}
F_58 ( & V_6 -> V_51 ) ;
return 0 ;
}
static void F_59 ( struct V_3 * V_4 , struct V_53 * V_54 )
{
F_60 ( V_54 -> V_55 , L_1 , sizeof( V_54 -> V_55 ) ) ;
F_60 ( V_54 -> V_56 , V_57 , sizeof( V_54 -> V_56 ) ) ;
F_60 ( V_54 -> V_58 , L_2 , sizeof( V_54 -> V_58 ) ) ;
F_60 ( V_54 -> V_59 , L_2 , sizeof( V_54 -> V_59 ) ) ;
}
static T_3 F_61 ( struct V_3 * V_4 ,
T_3 V_60 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_62 ( V_6 , V_60 ) ;
}
static void F_63 ( struct V_3 * V_61 )
{
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_62 * V_46 ;
F_65 (p, &br->port_list, list)
F_66 ( V_46 ) ;
}
static int F_67 ( struct V_62 * V_46 )
{
struct V_63 * V_64 ;
int V_29 ;
V_64 = F_68 ( sizeof( * V_46 -> V_64 ) , V_65 ) ;
if ( ! V_64 )
return - V_30 ;
V_29 = F_69 ( V_64 , V_46 -> V_4 ) ;
if ( V_29 ) {
F_70 ( V_64 ) ;
return V_29 ;
}
V_46 -> V_64 = V_64 ;
return V_29 ;
}
int F_71 ( struct V_62 * V_46 )
{
if ( ! V_46 -> V_6 -> V_4 -> V_66 )
return 0 ;
return F_67 ( V_46 ) ;
}
static int F_72 ( struct V_3 * V_4 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_62 * V_46 ;
int V_29 = 0 ;
F_65 (p, &br->port_list, list) {
if ( ! V_46 -> V_4 )
continue;
V_29 = F_67 ( V_46 ) ;
if ( V_29 )
goto V_69;
}
V_28:
return V_29 ;
V_69:
F_64 ( V_4 ) ;
goto V_28;
}
void F_66 ( struct V_62 * V_46 )
{
struct V_63 * V_64 = V_46 -> V_64 ;
if ( ! V_64 )
return;
V_46 -> V_64 = NULL ;
F_73 ( V_64 ) ;
}
static int F_74 ( struct V_3 * V_4 , struct V_3 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_75 ( V_6 , V_70 ) ;
}
static int F_76 ( struct V_3 * V_4 , struct V_3 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_77 ( V_6 , V_70 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_32 ( V_6 -> V_15 ) ;
F_79 ( V_4 ) ;
}
void F_80 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_81 ( V_4 ) ;
F_82 ( V_4 ) ;
V_4 -> V_71 = & V_72 ;
V_4 -> V_73 = F_78 ;
V_4 -> V_74 = & V_75 ;
F_83 ( V_4 , & V_76 ) ;
V_4 -> V_77 = 0 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_60 = V_80 | V_81 | V_82 |
V_83 | V_84 ;
V_4 -> V_85 = V_80 | V_83 |
V_84 ;
V_4 -> V_86 = V_80 ;
V_6 -> V_4 = V_4 ;
F_84 ( & V_6 -> V_51 ) ;
F_85 ( & V_6 -> V_87 ) ;
F_84 ( & V_6 -> V_88 ) ;
V_6 -> V_89 . V_90 [ 0 ] = 0x80 ;
V_6 -> V_89 . V_90 [ 1 ] = 0x00 ;
F_86 ( V_6 -> V_91 , V_92 ) ;
V_6 -> V_93 = V_94 ;
V_6 -> V_95 = V_96 ;
V_6 -> V_97 = V_96 ;
V_6 -> V_98 = V_6 -> V_89 ;
V_6 -> V_99 = V_6 -> V_100 = 20 * V_101 ;
V_6 -> V_102 = V_6 -> V_103 = 2 * V_101 ;
V_6 -> V_104 = V_6 -> V_105 = 15 * V_101 ;
V_6 -> V_106 = 300 * V_101 ;
F_87 ( V_6 ) ;
F_88 ( V_6 ) ;
F_89 ( V_6 ) ;
}
