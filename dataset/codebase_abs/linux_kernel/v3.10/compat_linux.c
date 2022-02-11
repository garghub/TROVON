T_1 long F_1 ( const char T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
return F_2 ( V_1 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_5 ( const char T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
return F_6 ( V_1 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_7 ( unsigned int V_4 , T_3 V_2 , T_3 V_3 )
{
return F_8 ( V_4 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_9 ( T_3 V_5 , T_3 V_6 )
{
return F_10 ( F_4 ( V_5 ) , F_4 ( V_6 ) ) ;
}
T_1 long F_11 ( T_3 V_7 )
{
return F_12 ( ( V_8 ) V_7 ) ;
}
T_1 long F_13 ( T_3 V_9 , T_3 V_10 )
{
return F_14 ( F_3 ( V_9 ) , F_3 ( V_10 ) ) ;
}
T_1 long F_15 ( T_3 V_11 )
{
return F_16 ( ( V_12 ) V_11 ) ;
}
T_1 long F_17 ( T_3 V_9 , T_3 V_10 , T_3 V_13 )
{
return F_18 ( F_3 ( V_9 ) , F_3 ( V_10 ) ,
F_3 ( V_13 ) ) ;
}
T_1 long F_19 ( T_3 T_2 * V_14 , T_3 T_2 * V_15 , T_3 T_2 * V_16 )
{
const struct V_17 * V_17 = F_20 () ;
int V_18 ;
T_3 V_9 , V_10 , V_13 ;
V_9 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_11 ) ) ;
V_10 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_10 ) ) ;
V_13 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_13 ) ) ;
if ( ! ( V_18 = F_23 ( V_9 , V_14 ) ) &&
! ( V_18 = F_23 ( V_10 , V_15 ) ) )
V_18 = F_23 ( V_13 , V_16 ) ;
return V_18 ;
}
T_1 long F_24 ( T_3 V_5 , T_3 V_6 , T_3 V_20 )
{
return F_25 ( F_4 ( V_5 ) , F_4 ( V_6 ) ,
F_4 ( V_20 ) ) ;
}
T_1 long F_26 ( T_3 T_2 * V_21 , T_3 T_2 * V_22 , T_3 T_2 * V_23 )
{
const struct V_17 * V_17 = F_20 () ;
int V_18 ;
T_3 V_5 , V_6 , V_20 ;
V_5 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_7 ) ) ;
V_6 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_6 ) ) ;
V_20 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_20 ) ) ;
if ( ! ( V_18 = F_23 ( V_5 , V_21 ) ) &&
! ( V_18 = F_23 ( V_6 , V_22 ) ) )
V_18 = F_23 ( V_20 , V_23 ) ;
return V_18 ;
}
T_1 long F_29 ( T_3 V_11 )
{
return F_30 ( ( V_12 ) V_11 ) ;
}
T_1 long F_31 ( T_3 V_7 )
{
return F_32 ( ( V_8 ) V_7 ) ;
}
static int F_33 ( T_3 T_2 * V_24 , struct V_25 * V_25 )
{
struct V_26 * V_19 = F_34 () ;
int V_27 ;
T_3 V_3 ;
T_4 V_28 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_29 ; V_27 ++ ) {
V_28 = F_35 ( V_25 , V_27 ) ;
V_3 = ( T_3 ) F_28 ( V_19 , V_28 ) ;
if ( F_23 ( V_3 , V_24 + V_27 ) )
return - V_30 ;
}
return 0 ;
}
static int F_36 ( struct V_25 * V_25 , T_3 T_2 * V_24 )
{
struct V_26 * V_19 = F_34 () ;
int V_27 ;
T_3 V_3 ;
T_4 V_28 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_29 ; V_27 ++ ) {
if ( F_37 ( V_3 , V_24 + V_27 ) )
return - V_30 ;
V_28 = F_38 ( V_19 , ( V_8 ) V_3 ) ;
if ( ! F_39 ( V_28 ) )
return - V_31 ;
F_35 ( V_25 , V_27 ) = V_28 ;
}
return 0 ;
}
T_1 long F_40 ( int V_32 , T_3 T_2 * V_24 )
{
int V_27 ;
if ( V_32 < 0 )
return - V_31 ;
F_41 ( V_33 -> V_17 -> V_25 ) ;
V_27 = V_33 -> V_17 -> V_25 -> V_29 ;
if ( V_32 ) {
if ( V_27 > V_32 ) {
V_27 = - V_31 ;
goto V_34;
}
if ( F_33 ( V_24 , V_33 -> V_17 -> V_25 ) ) {
V_27 = - V_30 ;
goto V_34;
}
}
V_34:
F_42 ( V_33 -> V_17 -> V_25 ) ;
return V_27 ;
}
T_1 long F_43 ( int V_32 , T_3 T_2 * V_24 )
{
struct V_25 * V_25 ;
int V_18 ;
if ( ! F_44 ( V_35 ) )
return - V_36 ;
if ( ( unsigned ) V_32 > V_37 )
return - V_31 ;
V_25 = F_45 ( V_32 ) ;
if ( ! V_25 )
return - V_38 ;
V_18 = F_36 ( V_25 , V_24 ) ;
if ( V_18 ) {
F_42 ( V_25 ) ;
return V_18 ;
}
V_18 = F_46 ( V_25 ) ;
F_42 ( V_25 ) ;
return V_18 ;
}
T_1 long F_47 ( void )
{
return F_21 ( F_22 ( F_34 () , F_48 () ) ) ;
}
T_1 long F_49 ( void )
{
return F_21 ( F_22 ( F_34 () , F_50 () ) ) ;
}
T_1 long F_51 ( void )
{
return F_27 ( F_28 ( F_34 () , F_52 () ) ) ;
}
T_1 long F_53 ( void )
{
return F_27 ( F_28 ( F_34 () , F_54 () ) ) ;
}
T_1 long F_55 ( const char T_2 * V_39 , unsigned long V_40 , unsigned long V_41 )
{
if ( ( int ) V_40 < 0 )
return - V_31 ;
else
return F_56 ( V_39 , ( V_40 << 32 ) | V_41 ) ;
}
T_1 long F_57 ( unsigned int V_4 , unsigned long V_40 , unsigned long V_41 )
{
if ( ( int ) V_40 < 0 )
return - V_31 ;
else
return F_58 ( V_4 , ( V_40 << 32 ) | V_41 ) ;
}
T_1 long F_59 ( unsigned int V_4 , char T_2 * V_42 ,
T_5 V_43 , T_6 V_44 , T_6 V_45 )
{
if ( ( V_46 ) V_43 < 0 )
return - V_31 ;
return F_60 ( V_4 , V_42 , V_43 , ( ( V_47 ) F_61 ( V_44 ) << 32 ) | F_61 ( V_45 ) ) ;
}
T_1 long F_62 ( unsigned int V_4 , const char T_2 * V_42 ,
T_5 V_43 , T_6 V_44 , T_6 V_45 )
{
if ( ( V_46 ) V_43 < 0 )
return - V_31 ;
return F_63 ( V_4 , V_42 , V_43 , ( ( V_47 ) F_61 ( V_44 ) << 32 ) | F_61 ( V_45 ) ) ;
}
T_1 V_46 F_64 ( int V_4 , T_6 V_48 , T_6 V_49 , T_7 V_43 )
{
return F_65 ( V_4 , ( ( V_47 ) F_61 ( V_48 ) << 32 ) | F_61 ( V_49 ) , V_43 ) ;
}
static int F_66 ( struct V_50 T_2 * V_42 , struct V_51 * V_52 )
{
struct V_50 V_53 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_54 = F_67 ( V_52 -> V_55 ) ;
V_53 . V_56 = V_52 -> V_57 ;
V_53 . V_58 = ( T_6 ) V_52 -> V_57 ;
V_53 . V_59 = V_52 -> V_60 ;
V_53 . V_61 = ( unsigned int ) V_52 -> V_62 ;
V_53 . V_63 = F_22 ( F_34 () , V_52 -> V_11 ) ;
V_53 . V_64 = F_28 ( F_34 () , V_52 -> V_7 ) ;
V_53 . V_65 = F_67 ( V_52 -> V_66 ) ;
V_53 . V_67 = V_52 -> V_68 ;
V_53 . V_69 = ( T_6 ) V_52 -> V_70 ;
V_53 . V_71 = ( T_6 ) V_52 -> V_72 ;
V_53 . V_73 = ( T_6 ) V_52 -> V_74 . V_75 ;
V_53 . V_76 = ( T_6 ) V_52 -> V_77 . V_75 ;
V_53 . V_78 = ( T_6 ) V_52 -> ctime . V_75 ;
return F_68 ( V_42 , & V_53 , sizeof( V_53 ) ) ? - V_30 : 0 ;
}
T_1 long F_69 ( const char T_2 * V_1 , struct V_50 T_2 * V_79 )
{
struct V_51 V_52 ;
int V_80 = F_70 ( V_1 , & V_52 ) ;
if ( ! V_80 )
V_80 = F_66 ( V_79 , & V_52 ) ;
return V_80 ;
}
T_1 long F_71 ( const char T_2 * V_1 , struct V_50 T_2 * V_79 )
{
struct V_51 V_52 ;
int V_80 = F_72 ( V_1 , & V_52 ) ;
if ( ! V_80 )
V_80 = F_66 ( V_79 , & V_52 ) ;
return V_80 ;
}
T_1 long F_73 ( unsigned long V_4 , struct V_50 T_2 * V_79 )
{
struct V_51 V_52 ;
int V_80 = F_74 ( V_4 , & V_52 ) ;
if ( ! V_80 )
V_80 = F_66 ( V_79 , & V_52 ) ;
return V_80 ;
}
T_1 long F_75 ( unsigned int V_81 , const char T_2 * V_1 ,
struct V_50 T_2 * V_79 , int V_82 )
{
struct V_51 V_52 ;
int error ;
error = F_76 ( V_81 , V_1 , & V_52 , V_82 ) ;
if ( error )
return error ;
return F_66 ( V_79 , & V_52 ) ;
}
T_1 unsigned long F_77 ( struct V_83 T_2 * V_84 )
{
struct V_83 V_85 ;
if ( F_78 ( & V_85 , V_84 , sizeof( V_85 ) ) )
return - V_30 ;
if ( V_85 . V_86 & ~ V_87 )
return - V_31 ;
return F_79 ( V_85 . V_88 , V_85 . V_89 , V_85 . V_90 , V_85 . V_91 , V_85 . V_4 ,
V_85 . V_86 >> V_92 ) ;
}
T_1 long F_80 ( struct V_83 T_2 * V_84 )
{
struct V_83 V_85 ;
if ( F_78 ( & V_85 , V_84 , sizeof( V_85 ) ) )
return - V_30 ;
return F_79 ( V_85 . V_88 , V_85 . V_89 , V_85 . V_90 , V_85 . V_91 , V_85 . V_4 , V_85 . V_86 ) ;
}
T_1 long F_81 ( unsigned int V_4 , char T_2 * V_93 , T_5 V_43 )
{
if ( ( V_46 ) V_43 < 0 )
return - V_31 ;
return F_82 ( V_4 , V_93 , V_43 ) ;
}
T_1 long F_83 ( unsigned int V_4 , const char T_2 * V_93 , T_5 V_43 )
{
if ( ( V_46 ) V_43 < 0 )
return - V_31 ;
return F_84 ( V_4 , V_93 , V_43 ) ;
}
T_1 long
F_85 ( int V_4 , V_47 V_86 , T_5 V_89 , int V_94 )
{
if ( V_94 == 4 )
V_94 = V_95 ;
else if ( V_94 == 5 )
V_94 = V_96 ;
return F_86 ( V_4 , V_86 , V_89 , V_94 ) ;
}
T_1 long
F_87 ( struct V_97 T_2 * args )
{
struct V_97 V_85 ;
if ( F_78 ( & V_85 , args , sizeof( V_85 ) ) )
return - V_30 ;
if ( V_85 . V_98 == 4 )
V_85 . V_98 = V_95 ;
else if ( V_85 . V_98 == 5 )
V_85 . V_98 = V_96 ;
return F_88 ( V_85 . V_4 , V_85 . V_86 , V_85 . V_89 , V_85 . V_98 ) ;
}
