T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
const unsigned char * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_3 ( V_6 -> V_15 ) ;
#ifdef F_4
if ( V_2 -> V_16 && ( V_2 -> V_16 -> V_17 & V_18 ) ) {
F_5 ( V_2 ) ;
return V_19 ;
}
#endif
F_6 ( & V_14 -> V_20 ) ;
V_14 -> V_21 ++ ;
V_14 -> V_22 += V_2 -> V_23 ;
F_7 ( & V_14 -> V_20 ) ;
F_8 ( V_2 ) -> V_24 = V_4 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_25 ) ;
F_11 () ;
if ( F_12 ( V_7 ) )
F_13 ( V_6 , V_2 ) ;
else if ( F_14 ( V_7 ) ) {
if ( F_15 ( F_16 ( V_4 ) ) ) {
F_13 ( V_6 , V_2 ) ;
goto V_26;
}
if ( F_17 ( V_6 , NULL , V_2 ) ) {
F_18 ( V_2 ) ;
goto V_26;
}
V_12 = F_19 ( V_6 , V_2 ) ;
if ( V_12 || F_20 ( V_2 ) )
F_21 ( V_12 , V_2 ) ;
else
F_13 ( V_6 , V_2 ) ;
} else if ( ( V_10 = F_22 ( V_6 , V_7 ) ) != NULL )
F_23 ( V_10 -> V_10 , V_2 ) ;
else
F_13 ( V_6 , V_2 ) ;
V_26:
F_24 () ;
return V_19 ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_15 = F_26 ( struct V_13 ) ;
if ( ! V_6 -> V_15 )
return - V_27 ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_28 ( V_4 ) ;
F_29 ( V_4 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 )
{
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
F_36 ( V_4 ) ;
return 0 ;
}
static struct V_28 * F_37 ( struct V_3 * V_4 ,
struct V_28 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 V_29 , V_30 = { 0 } ;
unsigned int V_31 ;
F_38 (cpu) {
unsigned int V_32 ;
const struct V_13 * V_33
= F_39 ( V_6 -> V_15 , V_31 ) ;
do {
V_32 = F_40 ( & V_33 -> V_20 ) ;
memcpy ( & V_29 , V_33 , sizeof( V_29 ) ) ;
} while ( F_41 ( & V_33 -> V_20 , V_32 ) );
V_30 . V_22 += V_29 . V_22 ;
V_30 . V_21 += V_29 . V_21 ;
V_30 . V_34 += V_29 . V_34 ;
V_30 . V_35 += V_29 . V_35 ;
}
V_15 -> V_22 = V_30 . V_22 ;
V_15 -> V_21 = V_30 . V_21 ;
V_15 -> V_34 = V_30 . V_34 ;
V_15 -> V_35 = V_30 . V_35 ;
return V_15 ;
}
static int F_42 ( struct V_3 * V_4 , int V_36 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_36 < 68 || V_36 > F_43 ( V_6 ) )
return - V_37 ;
V_4 -> V_38 = V_36 ;
#ifdef F_4
F_44 ( & V_6 -> V_39 . V_10 , V_40 , V_36 ) ;
#endif
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , void * V_41 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_42 * V_43 = V_41 ;
if ( ! F_46 ( V_43 -> V_44 ) )
return - V_37 ;
F_47 ( & V_6 -> V_45 ) ;
memcpy ( V_4 -> V_46 , V_43 -> V_44 , V_47 ) ;
F_48 ( V_6 , V_43 -> V_44 ) ;
V_6 -> V_48 |= V_49 ;
F_49 ( & V_6 -> V_45 ) ;
return 0 ;
}
static void F_50 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
strcpy ( V_51 -> V_52 , L_1 ) ;
strcpy ( V_51 -> V_53 , V_54 ) ;
strcpy ( V_51 -> V_55 , L_2 ) ;
strcpy ( V_51 -> V_56 , L_2 ) ;
}
static T_2 F_51 ( struct V_3 * V_4 , T_2 V_57 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_52 ( V_6 , V_57 ) ;
}
static void F_53 ( struct V_3 * V_58 )
{
}
static void F_54 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_41 , * V_60 ;
F_55 (p, n, &br->port_list, list) {
F_56 ( V_41 ) ;
}
}
static int F_57 ( struct V_3 * V_4 , struct V_61 * V_62 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_59 * V_41 , * V_60 ;
int V_63 = 0 ;
F_55 (p, n, &br->port_list, list) {
if ( ! V_41 -> V_4 )
continue;
V_63 = F_58 ( V_41 ) ;
if ( V_63 )
goto V_64;
}
V_26:
return V_63 ;
V_64:
F_54 ( V_4 ) ;
goto V_26;
}
int F_58 ( struct V_59 * V_41 )
{
struct V_65 * V_66 ;
int V_63 = 0 ;
V_66 = F_59 ( sizeof( * V_41 -> V_66 ) , V_67 ) ;
V_63 = - V_27 ;
if ( ! V_66 )
goto V_26;
V_66 -> V_4 = V_41 -> V_4 ;
F_60 ( V_66 -> V_68 , V_41 -> V_4 -> V_69 , V_70 ) ;
V_63 = F_61 ( V_66 ) ;
if ( V_63 ) {
F_62 ( V_66 ) ;
goto V_26;
}
V_41 -> V_66 = V_66 ;
V_26:
return V_63 ;
}
void F_56 ( struct V_59 * V_41 )
{
struct V_65 * V_66 = V_41 -> V_66 ;
if ( ! V_66 )
return;
V_41 -> V_66 = NULL ;
F_63 () ;
F_64 ( V_66 ) ;
F_62 ( V_66 ) ;
}
static int F_65 ( struct V_3 * V_4 , struct V_3 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_66 ( V_6 , V_71 ) ;
}
static int F_67 ( struct V_3 * V_4 , struct V_3 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return F_68 ( V_6 , V_71 ) ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_70 ( V_6 -> V_15 ) ;
F_71 ( V_4 ) ;
}
void F_72 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_73 ( V_4 -> V_46 ) ;
F_74 ( V_4 ) ;
V_4 -> V_72 = & V_73 ;
V_4 -> V_74 = F_69 ;
F_75 ( V_4 , & V_75 ) ;
F_76 ( V_4 , & V_76 ) ;
V_4 -> V_77 = 0 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_57 = V_80 | V_81 | V_82 |
V_83 | V_84 | V_85 |
V_86 | V_87 ;
V_4 -> V_88 = V_80 | V_81 | V_82 |
V_83 | V_84 |
V_87 ;
V_6 -> V_4 = V_4 ;
F_77 ( & V_6 -> V_45 ) ;
F_78 ( & V_6 -> V_89 ) ;
F_77 ( & V_6 -> V_90 ) ;
V_6 -> V_91 . V_92 [ 0 ] = 0x80 ;
V_6 -> V_91 . V_92 [ 1 ] = 0x00 ;
memcpy ( V_6 -> V_93 , V_94 , V_47 ) ;
V_6 -> V_95 = V_96 ;
V_6 -> V_97 = V_6 -> V_91 ;
V_6 -> V_98 = V_6 -> V_99 = 20 * V_100 ;
V_6 -> V_101 = V_6 -> V_102 = 2 * V_100 ;
V_6 -> V_103 = V_6 -> V_104 = 15 * V_100 ;
V_6 -> V_105 = 300 * V_100 ;
F_79 ( V_6 ) ;
F_80 ( V_6 ) ;
F_81 ( V_6 ) ;
}
