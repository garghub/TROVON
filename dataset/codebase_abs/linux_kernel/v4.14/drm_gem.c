int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_4 = F_4 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 ) {
F_5 ( L_1 ) ;
return - V_8 ;
}
V_2 -> V_4 = V_4 ;
F_6 ( V_4 ,
V_9 ,
V_10 ) ;
return 0 ;
}
void
F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_4 ) ;
F_9 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 ;
F_11 ( V_2 , V_12 , V_13 ) ;
V_15 = F_12 ( L_2 , V_13 , V_16 ) ;
if ( F_13 ( V_15 ) )
return F_14 ( V_15 ) ;
V_12 -> V_15 = V_15 ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_13 )
{
F_15 ( ( V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_15 = NULL ;
F_16 ( & V_12 -> V_18 ) ;
V_12 -> V_19 = 0 ;
V_12 -> V_13 = V_13 ;
F_17 ( & V_12 -> V_20 ) ;
}
static void
F_18 ( struct V_11 * V_12 , struct V_21 * V_15 )
{
F_19 ( & V_15 -> V_22 . V_23 ) ;
if ( V_12 -> V_24 ) {
F_20 ( & V_15 -> V_22 ,
V_12 -> V_24 ) ;
}
F_21 ( & V_15 -> V_22 . V_23 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_12 -> V_25 ) {
F_23 ( & V_2 -> V_6 , V_12 -> V_25 ) ;
V_12 -> V_25 = 0 ;
}
}
static void F_24 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 ) {
F_25 ( V_12 -> V_24 ) ;
V_12 -> V_24 = NULL ;
}
}
static void
F_26 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
bool V_26 = false ;
if ( F_27 ( V_12 -> V_19 == 0 ) )
return;
F_19 ( & V_2 -> V_5 ) ;
if ( -- V_12 -> V_19 == 0 ) {
F_22 ( V_12 ) ;
F_24 ( V_12 ) ;
V_26 = true ;
}
F_21 ( & V_2 -> V_5 ) ;
if ( V_26 )
F_28 ( V_12 ) ;
}
static int
F_29 ( int V_27 , void * V_28 , void * V_29 )
{
struct V_21 * V_30 = V_29 ;
struct V_11 * V_12 = V_28 ;
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_2 -> V_31 -> V_32 )
V_2 -> V_31 -> V_32 ( V_12 , V_30 ) ;
if ( F_30 ( V_2 , V_33 ) )
F_18 ( V_12 , V_30 ) ;
F_31 ( & V_12 -> V_20 , V_30 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
int
F_32 ( struct V_21 * V_15 , T_2 V_34 )
{
struct V_11 * V_12 ;
F_33 ( & V_15 -> V_35 ) ;
V_12 = F_34 ( & V_15 -> V_36 , NULL , V_34 ) ;
F_35 ( & V_15 -> V_35 ) ;
if ( F_36 ( V_12 ) )
return - V_37 ;
F_29 ( V_34 , V_12 , V_15 ) ;
F_33 ( & V_15 -> V_35 ) ;
F_23 ( & V_15 -> V_36 , V_34 ) ;
F_35 ( & V_15 -> V_35 ) ;
return 0 ;
}
int F_37 ( struct V_21 * V_14 , struct V_1 * V_2 ,
T_2 V_34 , T_3 * V_38 )
{
struct V_11 * V_12 ;
int V_39 ;
V_12 = F_38 ( V_14 , V_34 ) ;
if ( ! V_12 )
return - V_40 ;
V_39 = F_39 ( V_12 ) ;
if ( V_39 )
goto V_41;
* V_38 = F_40 ( & V_12 -> V_20 ) ;
V_41:
F_28 ( V_12 ) ;
return V_39 ;
}
int F_41 ( struct V_21 * V_14 ,
struct V_1 * V_2 ,
T_4 V_34 )
{
return F_32 ( V_14 , V_34 ) ;
}
int
F_42 ( struct V_21 * V_30 ,
struct V_11 * V_12 ,
T_2 * V_42 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_2 V_34 ;
int V_39 ;
F_27 ( ! F_43 ( & V_2 -> V_5 ) ) ;
if ( V_12 -> V_19 ++ == 0 )
F_44 ( V_12 ) ;
F_45 ( V_7 ) ;
F_33 ( & V_30 -> V_35 ) ;
V_39 = F_46 ( & V_30 -> V_36 , V_12 , 1 , 0 , V_43 ) ;
F_35 ( & V_30 -> V_35 ) ;
F_47 () ;
F_21 ( & V_2 -> V_5 ) ;
if ( V_39 < 0 )
goto V_44;
V_34 = V_39 ;
V_39 = F_48 ( & V_12 -> V_20 , V_30 ) ;
if ( V_39 )
goto V_45;
if ( V_2 -> V_31 -> V_46 ) {
V_39 = V_2 -> V_31 -> V_46 ( V_12 , V_30 ) ;
if ( V_39 )
goto V_47;
}
* V_42 = V_34 ;
return 0 ;
V_47:
F_31 ( & V_12 -> V_20 , V_30 ) ;
V_45:
F_33 ( & V_30 -> V_35 ) ;
F_23 ( & V_30 -> V_36 , V_34 ) ;
F_35 ( & V_30 -> V_35 ) ;
V_44:
F_26 ( V_12 ) ;
return V_39 ;
}
int F_49 ( struct V_21 * V_30 ,
struct V_11 * V_12 ,
T_2 * V_42 )
{
F_19 ( & V_12 -> V_2 -> V_5 ) ;
return F_42 ( V_30 , V_12 , V_42 ) ;
}
void
F_50 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_51 ( V_2 -> V_4 , & V_12 -> V_20 ) ;
}
int
F_52 ( struct V_11 * V_12 , T_1 V_13 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
return F_53 ( V_2 -> V_4 , & V_12 -> V_20 ,
V_13 / V_17 ) ;
}
int F_39 ( struct V_11 * V_12 )
{
return F_52 ( V_12 , V_12 -> V_13 ) ;
}
struct V_48 * * F_54 ( struct V_11 * V_12 )
{
struct V_49 * V_50 ;
struct V_48 * V_51 , * * V_52 ;
int V_53 , V_54 ;
V_50 = V_12 -> V_15 -> V_55 ;
F_27 ( ( V_12 -> V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_54 = V_12 -> V_13 >> V_56 ;
V_52 = F_55 ( V_54 , sizeof( struct V_48 * ) , V_7 ) ;
if ( V_52 == NULL )
return F_56 ( - V_8 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
V_51 = F_57 ( V_50 , V_53 ) ;
if ( F_13 ( V_51 ) )
goto V_57;
V_52 [ V_53 ] = V_51 ;
F_15 ( F_58 ( V_50 , V_58 ) &&
( F_59 ( V_51 ) >= 0x00100000UL ) ) ;
}
return V_52 ;
V_57:
while ( V_53 -- )
F_60 ( V_52 [ V_53 ] ) ;
F_61 ( V_52 ) ;
return F_62 ( V_51 ) ;
}
void F_63 ( struct V_11 * V_12 , struct V_48 * * V_52 ,
bool V_59 , bool V_60 )
{
int V_53 , V_54 ;
F_27 ( ( V_12 -> V_13 & ( V_17 - 1 ) ) != 0 ) ;
V_54 = V_12 -> V_13 >> V_56 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
if ( V_59 )
F_64 ( V_52 [ V_53 ] ) ;
if ( V_60 )
F_65 ( V_52 [ V_53 ] ) ;
F_60 ( V_52 [ V_53 ] ) ;
}
F_61 ( V_52 ) ;
}
struct V_11 *
F_38 ( struct V_21 * V_15 , T_2 V_34 )
{
struct V_11 * V_12 ;
F_33 ( & V_15 -> V_35 ) ;
V_12 = F_66 ( & V_15 -> V_36 , V_34 ) ;
if ( V_12 )
F_44 ( V_12 ) ;
F_35 ( & V_15 -> V_35 ) ;
return V_12 ;
}
int
F_67 ( struct V_1 * V_2 , void * V_29 ,
struct V_21 * V_30 )
{
struct V_61 * args = V_29 ;
int V_39 ;
if ( ! F_30 ( V_2 , V_62 ) )
return - V_63 ;
V_39 = F_32 ( V_30 , args -> V_34 ) ;
return V_39 ;
}
int
F_68 ( struct V_1 * V_2 , void * V_29 ,
struct V_21 * V_30 )
{
struct V_64 * args = V_29 ;
struct V_11 * V_12 ;
int V_39 ;
if ( ! F_30 ( V_2 , V_62 ) )
return - V_63 ;
V_12 = F_38 ( V_30 , args -> V_34 ) ;
if ( V_12 == NULL )
return - V_40 ;
F_19 ( & V_2 -> V_5 ) ;
if ( V_12 -> V_19 == 0 ) {
V_39 = - V_40 ;
goto V_65;
}
if ( ! V_12 -> V_25 ) {
V_39 = F_46 ( & V_2 -> V_6 , V_12 , 1 , 0 , V_7 ) ;
if ( V_39 < 0 )
goto V_65;
V_12 -> V_25 = V_39 ;
}
args -> V_25 = ( V_66 ) V_12 -> V_25 ;
V_39 = 0 ;
V_65:
F_21 ( & V_2 -> V_5 ) ;
F_28 ( V_12 ) ;
return V_39 ;
}
int
F_69 ( struct V_1 * V_2 , void * V_29 ,
struct V_21 * V_30 )
{
struct V_67 * args = V_29 ;
struct V_11 * V_12 ;
int V_39 ;
T_2 V_34 ;
if ( ! F_30 ( V_2 , V_62 ) )
return - V_63 ;
F_19 ( & V_2 -> V_5 ) ;
V_12 = F_66 ( & V_2 -> V_6 , ( int ) args -> V_25 ) ;
if ( V_12 ) {
F_44 ( V_12 ) ;
} else {
F_21 ( & V_2 -> V_5 ) ;
return - V_40 ;
}
V_39 = F_42 ( V_30 , V_12 , & V_34 ) ;
F_28 ( V_12 ) ;
if ( V_39 )
return V_39 ;
args -> V_34 = V_34 ;
args -> V_13 = V_12 -> V_13 ;
return 0 ;
}
void
V_67 ( struct V_1 * V_2 , struct V_21 * V_68 )
{
F_3 ( & V_68 -> V_36 ) ;
F_70 ( & V_68 -> V_35 ) ;
}
void
F_71 ( struct V_1 * V_2 , struct V_21 * V_68 )
{
F_72 ( & V_68 -> V_36 ,
& F_29 , V_68 ) ;
F_73 ( & V_68 -> V_36 ) ;
}
void
F_74 ( struct V_11 * V_12 )
{
F_27 ( V_12 -> V_24 ) ;
if ( V_12 -> V_15 )
F_75 ( V_12 -> V_15 ) ;
F_50 ( V_12 ) ;
}
void
F_76 ( struct V_69 * V_69 )
{
struct V_11 * V_12 =
F_77 ( V_69 , struct V_11 , V_18 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_2 -> V_31 -> V_70 ) {
V_2 -> V_31 -> V_70 ( V_12 ) ;
} else if ( V_2 -> V_31 -> V_71 ) {
F_27 ( ! F_43 ( & V_2 -> V_72 ) ) ;
V_2 -> V_31 -> V_71 ( V_12 ) ;
}
}
void
F_28 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
if ( ! V_12 )
return;
V_2 = V_12 -> V_2 ;
if ( V_2 -> V_31 -> V_70 ) {
F_78 ( & V_12 -> V_18 , F_76 ) ;
} else {
F_79 ( & V_2 -> V_72 ) ;
if ( F_80 ( & V_12 -> V_18 , F_76 ,
& V_2 -> V_72 ) )
F_21 ( & V_2 -> V_72 ) ;
}
}
void
F_81 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_27 ( ! F_43 ( & V_12 -> V_2 -> V_72 ) ) ;
F_78 ( & V_12 -> V_18 , F_76 ) ;
}
}
void F_82 ( struct V_73 * V_74 )
{
struct V_11 * V_12 = V_74 -> V_75 ;
F_44 ( V_12 ) ;
}
void F_83 ( struct V_73 * V_74 )
{
struct V_11 * V_12 = V_74 -> V_75 ;
F_28 ( V_12 ) ;
}
int F_84 ( struct V_11 * V_12 , unsigned long V_76 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_76 < V_74 -> V_77 - V_74 -> V_78 )
return - V_37 ;
if ( ! V_2 -> V_31 -> V_79 )
return - V_37 ;
V_74 -> V_80 |= V_81 | V_82 | V_83 | V_84 ;
V_74 -> V_85 = V_2 -> V_31 -> V_79 ;
V_74 -> V_75 = V_12 ;
V_74 -> V_86 = F_85 ( F_86 ( V_74 -> V_80 ) ) ;
V_74 -> V_86 = F_87 ( V_74 -> V_86 ) ;
F_44 ( V_12 ) ;
return 0 ;
}
int F_88 ( struct V_14 * V_15 , struct V_73 * V_74 )
{
struct V_21 * V_87 = V_15 -> V_88 ;
struct V_1 * V_2 = V_87 -> V_89 -> V_2 ;
struct V_11 * V_12 = NULL ;
struct V_90 * V_91 ;
int V_39 ;
if ( F_89 ( V_2 ) )
return - V_63 ;
F_90 ( V_2 -> V_4 ) ;
V_91 = F_91 ( V_2 -> V_4 ,
V_74 -> V_92 ,
F_92 ( V_74 ) ) ;
if ( F_93 ( V_91 ) ) {
V_12 = F_77 ( V_91 , struct V_11 , V_20 ) ;
if ( ! F_94 ( & V_12 -> V_18 ) )
V_12 = NULL ;
}
F_95 ( V_2 -> V_4 ) ;
if ( ! V_12 )
return - V_37 ;
if ( ! F_96 ( V_91 , V_87 ) ) {
F_28 ( V_12 ) ;
return - V_93 ;
}
V_39 = F_84 ( V_12 , F_97 ( V_91 ) << V_56 ,
V_74 ) ;
F_28 ( V_12 ) ;
return V_39 ;
}
