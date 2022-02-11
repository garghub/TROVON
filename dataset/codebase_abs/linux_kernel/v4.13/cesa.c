struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_1 * * V_4 )
{
struct V_1 * V_5 ;
* V_4 = F_2 ( & V_3 -> V_6 ) ;
V_5 = F_3 ( & V_3 -> V_6 ) ;
if ( ! V_5 )
return NULL ;
return V_5 ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = NULL , * V_4 = NULL ;
struct V_7 * V_8 ;
F_5 ( & V_3 -> V_9 ) ;
if ( ! V_3 -> V_5 ) {
V_5 = F_1 ( V_3 , & V_4 ) ;
V_3 -> V_5 = V_5 ;
}
F_6 ( & V_3 -> V_9 ) ;
if ( ! V_5 )
return;
if ( V_4 )
V_4 -> V_10 ( V_4 , - V_11 ) ;
V_8 = F_7 ( V_5 -> V_12 ) ;
V_8 -> V_13 -> V_14 ( V_5 ) ;
return;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_15 )
{
struct V_1 * V_5 ;
struct V_7 * V_8 ;
int V_16 ;
V_5 = V_3 -> V_5 ;
V_8 = F_7 ( V_5 -> V_12 ) ;
V_16 = V_8 -> V_13 -> V_17 ( V_5 , V_15 ) ;
if ( V_16 == 0 ) {
V_8 -> V_13 -> V_10 ( V_5 ) ;
F_9 ( V_3 , V_5 ) ;
} else if ( V_16 == - V_11 ) {
V_8 -> V_13 -> V_14 ( V_5 ) ;
}
return V_16 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_15 )
{
if ( V_3 -> V_18 . V_19 && V_3 -> V_18 . V_20 )
return F_11 ( V_3 , V_15 ) ;
return F_8 ( V_3 , V_15 ) ;
}
static inline void
F_12 ( struct V_7 * V_8 , struct V_1 * V_5 ,
int V_16 )
{
V_8 -> V_13 -> V_21 ( V_5 ) ;
F_13 () ;
V_5 -> V_10 ( V_5 , V_16 ) ;
F_14 () ;
}
static T_2 F_15 ( int V_22 , void * V_23 )
{
struct V_2 * V_3 = V_23 ;
struct V_1 * V_5 ;
struct V_7 * V_8 ;
T_1 V_15 , V_24 ;
T_2 V_25 = V_26 ;
while ( true ) {
int V_16 ;
V_24 = F_16 ( V_3 ) ;
V_15 = F_17 ( V_3 -> V_27 + V_28 ) ;
if ( ! ( V_15 & V_24 ) )
break;
F_18 ( ~ V_15 , V_3 -> V_27 + V_29 ) ;
F_18 ( ~ V_15 , V_3 -> V_27 + V_28 ) ;
V_16 = F_10 ( V_3 , V_15 & V_24 ) ;
V_25 = V_30 ;
F_5 ( & V_3 -> V_9 ) ;
V_5 = V_3 -> V_5 ;
if ( V_16 != - V_11 )
V_3 -> V_5 = NULL ;
F_6 ( & V_3 -> V_9 ) ;
V_8 = F_7 ( V_5 -> V_12 ) ;
if ( V_16 && V_16 != - V_11 )
F_12 ( V_8 , V_5 , V_16 ) ;
F_4 ( V_3 ) ;
while ( true ) {
V_5 = F_19 ( V_3 ) ;
if ( ! V_5 )
break;
V_8 = F_7 ( V_5 -> V_12 ) ;
F_12 ( V_8 , V_5 , 0 ) ;
}
}
return V_25 ;
}
int F_20 ( struct V_1 * V_5 ,
struct V_31 * V_32 )
{
int V_25 ;
struct V_2 * V_3 = V_32 -> V_3 ;
F_5 ( & V_3 -> V_9 ) ;
V_25 = F_21 ( & V_3 -> V_6 , V_5 ) ;
if ( ( F_22 ( V_32 ) == V_33 ) &&
( V_25 == - V_11 ||
( V_25 == - V_34 && V_5 -> V_35 & V_36 ) ) )
F_23 ( V_3 , V_32 ) ;
F_6 ( & V_3 -> V_9 ) ;
if ( V_25 != - V_11 )
return V_25 ;
F_4 ( V_3 ) ;
return - V_11 ;
}
static int F_24 ( struct V_37 * V_38 )
{
int V_25 ;
int V_39 , V_40 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_41 -> V_42 ; V_39 ++ ) {
V_25 = F_25 ( V_38 -> V_41 -> V_43 [ V_39 ] ) ;
if ( V_25 )
goto V_44;
}
for ( V_39 = 0 ; V_39 < V_38 -> V_41 -> V_45 ; V_39 ++ ) {
V_25 = F_26 ( V_38 -> V_41 -> V_46 [ V_39 ] ) ;
if ( V_25 )
goto V_47;
}
return 0 ;
V_47:
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_27 ( V_38 -> V_41 -> V_46 [ V_40 ] ) ;
V_39 = V_38 -> V_41 -> V_42 ;
V_44:
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_28 ( V_38 -> V_41 -> V_43 [ V_40 ] ) ;
return V_25 ;
}
static void F_29 ( struct V_37 * V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_41 -> V_45 ; V_39 ++ )
F_27 ( V_38 -> V_41 -> V_46 [ V_39 ] ) ;
for ( V_39 = 0 ; V_39 < V_38 -> V_41 -> V_42 ; V_39 ++ )
F_28 ( V_38 -> V_41 -> V_43 [ V_39 ] ) ;
}
static void
F_30 ( struct V_2 * V_3 ,
const struct V_48 * V_49 )
{
void T_3 * V_50 = V_3 -> V_27 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
F_18 ( 0 , V_50 + F_31 ( V_39 ) ) ;
F_18 ( 0 , V_50 + F_32 ( V_39 ) ) ;
}
for ( V_39 = 0 ; V_39 < V_49 -> V_51 ; V_39 ++ ) {
const struct V_52 * V_53 = V_49 -> V_53 + V_39 ;
F_18 ( ( ( V_53 -> V_54 - 1 ) & 0xffff0000 ) |
( V_53 -> V_55 << 8 ) |
( V_49 -> V_56 << 4 ) | 1 ,
V_50 + F_31 ( V_39 ) ) ;
F_18 ( V_53 -> V_57 , V_50 + F_32 ( V_39 ) ) ;
}
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_58 * V_59 = V_38 -> V_59 ;
struct V_60 * V_61 ;
if ( ! V_38 -> V_41 -> V_62 )
return 0 ;
V_61 = F_34 ( V_59 , sizeof( * V_61 ) , V_63 ) ;
if ( ! V_61 )
return - V_64 ;
V_61 -> V_65 = F_35 ( L_1 , V_59 ,
sizeof( struct V_66 ) ,
16 , 0 ) ;
if ( ! V_61 -> V_65 )
return - V_64 ;
V_61 -> V_67 = F_35 ( L_2 , V_59 ,
sizeof( struct V_68 ) , 16 , 0 ) ;
if ( ! V_61 -> V_67 )
return - V_64 ;
V_61 -> V_69 = F_35 ( L_3 , V_59 ,
V_70 , 1 , 0 ) ;
if ( ! V_61 -> V_69 )
return - V_64 ;
V_61 -> V_71 = F_35 ( L_4 , V_59 , 72 , 1 , 0 ) ;
if ( ! V_61 -> V_71 )
return - V_64 ;
V_38 -> V_61 = V_61 ;
return 0 ;
}
static int F_36 ( struct V_72 * V_73 , int V_74 )
{
struct V_37 * V_38 = F_37 ( V_73 ) ;
struct V_2 * V_3 = & V_38 -> V_75 [ V_74 ] ;
const char * V_76 = L_5 ;
struct V_77 * V_16 ;
V_3 -> V_78 = F_38 ( V_38 -> V_59 -> V_79 ,
L_6 , V_74 ) ;
if ( V_3 -> V_78 ) {
V_3 -> V_80 = F_39 ( V_3 -> V_78 ,
V_38 -> V_81 ,
& V_3 -> V_82 ) ;
if ( V_3 -> V_80 )
return 0 ;
V_3 -> V_78 = NULL ;
return - V_64 ;
}
if ( V_38 -> V_41 -> V_83 > 1 ) {
if ( ! V_74 )
V_76 = L_7 ;
else
V_76 = L_8 ;
}
V_16 = F_40 ( V_73 , V_84 ,
V_76 ) ;
if ( ! V_16 || F_41 ( V_16 ) < V_38 -> V_81 )
return - V_85 ;
V_3 -> V_80 = F_42 ( V_38 -> V_59 , V_16 ) ;
if ( F_43 ( V_3 -> V_80 ) )
return F_44 ( V_3 -> V_80 ) ;
V_3 -> V_82 = F_45 ( V_38 -> V_59 ,
( V_86 ) V_16 -> V_87 ) ;
return 0 ;
}
static void F_46 ( struct V_72 * V_73 , int V_74 )
{
struct V_37 * V_38 = F_37 ( V_73 ) ;
struct V_2 * V_3 = & V_38 -> V_75 [ V_74 ] ;
if ( ! V_3 -> V_78 )
return;
F_47 ( V_3 -> V_78 , ( unsigned long ) V_3 -> V_80 ,
V_38 -> V_81 ) ;
}
static int F_48 ( struct V_72 * V_73 )
{
const struct V_88 * V_41 = & V_89 ;
const struct V_48 * V_49 ;
const struct V_90 * V_91 ;
struct V_58 * V_59 = & V_73 -> V_59 ;
struct V_37 * V_38 ;
struct V_2 * V_75 ;
struct V_77 * V_16 ;
int V_22 , V_25 , V_39 ;
T_1 V_81 ;
if ( V_92 ) {
F_49 ( & V_73 -> V_59 , L_9 ) ;
return - V_93 ;
}
if ( V_59 -> V_79 ) {
V_91 = F_50 ( V_94 , V_59 -> V_79 ) ;
if ( ! V_91 || ! V_91 -> V_95 )
return - V_96 ;
V_41 = V_91 -> V_95 ;
}
if ( ( V_41 == & V_89 || V_41 == & V_97 ) && ! V_98 )
return - V_96 ;
V_38 = F_34 ( V_59 , sizeof( * V_38 ) , V_63 ) ;
if ( ! V_38 )
return - V_64 ;
V_38 -> V_41 = V_41 ;
V_38 -> V_59 = V_59 ;
V_81 = V_99 ;
F_51 ( V_38 -> V_59 -> V_79 , L_10 ,
& V_81 ) ;
if ( V_81 < V_100 )
V_81 = V_100 ;
V_38 -> V_81 = V_81 ;
V_38 -> V_75 = F_34 ( V_59 , V_41 -> V_83 * sizeof( * V_75 ) ,
V_63 ) ;
if ( ! V_38 -> V_75 )
return - V_64 ;
F_52 ( & V_38 -> V_9 ) ;
V_16 = F_40 ( V_73 , V_84 , L_11 ) ;
V_38 -> V_27 = F_42 ( V_59 , V_16 ) ;
if ( F_43 ( V_38 -> V_27 ) )
return F_44 ( V_38 -> V_27 ) ;
V_25 = F_33 ( V_38 ) ;
if ( V_25 )
return V_25 ;
V_49 = F_53 () ;
F_54 ( V_73 , V_38 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_83 ; V_39 ++ ) {
struct V_2 * V_3 = & V_38 -> V_75 [ V_39 ] ;
char V_76 [ 7 ] ;
V_3 -> V_101 = V_39 ;
F_52 ( & V_3 -> V_9 ) ;
V_25 = F_36 ( V_73 , V_39 ) ;
if ( V_25 )
goto V_102;
V_22 = F_55 ( V_73 , V_39 ) ;
if ( V_22 < 0 ) {
V_25 = V_22 ;
goto V_102;
}
snprintf ( V_76 , sizeof( V_76 ) , L_12 , V_39 ) ;
V_3 -> V_103 = F_56 ( V_59 , V_76 ) ;
if ( F_43 ( V_3 -> V_103 ) ) {
V_3 -> V_103 = F_56 ( V_59 , NULL ) ;
if ( F_43 ( V_3 -> V_103 ) )
V_3 -> V_103 = NULL ;
}
snprintf ( V_76 , sizeof( V_76 ) , L_13 , V_39 ) ;
V_3 -> V_104 = F_56 ( V_59 , V_76 ) ;
if ( F_43 ( V_3 -> V_104 ) )
V_3 -> V_104 = NULL ;
V_25 = F_57 ( V_3 -> V_103 ) ;
if ( V_25 )
goto V_102;
V_25 = F_57 ( V_3 -> V_104 ) ;
if ( V_25 )
goto V_102;
V_3 -> V_27 = V_38 -> V_27 + F_58 ( V_39 ) ;
if ( V_49 && V_38 -> V_41 -> V_62 )
F_30 ( V_3 , V_49 ) ;
F_18 ( 0 , V_3 -> V_27 + V_28 ) ;
F_18 ( V_105 ,
V_3 -> V_27 + V_106 ) ;
F_18 ( V_3 -> V_82 & V_107 ,
V_3 -> V_27 + V_108 ) ;
V_25 = F_59 ( V_59 , V_22 , NULL , F_15 ,
V_109 ,
F_60 ( & V_73 -> V_59 ) ,
V_3 ) ;
if ( V_25 )
goto V_102;
F_61 ( & V_3 -> V_6 , V_110 ) ;
F_62 ( & V_3 -> V_111 , 0 ) ;
F_63 ( & V_3 -> V_112 ) ;
}
V_92 = V_38 ;
V_25 = F_24 ( V_38 ) ;
if ( V_25 ) {
V_92 = NULL ;
goto V_102;
}
F_64 ( V_59 , L_14 ) ;
return 0 ;
V_102:
for ( V_39 = 0 ; V_39 < V_41 -> V_83 ; V_39 ++ ) {
F_65 ( V_38 -> V_75 [ V_39 ] . V_104 ) ;
F_65 ( V_38 -> V_75 [ V_39 ] . V_103 ) ;
F_46 ( V_73 , V_39 ) ;
}
return V_25 ;
}
static int F_66 ( struct V_72 * V_73 )
{
struct V_37 * V_38 = F_37 ( V_73 ) ;
int V_39 ;
F_29 ( V_38 ) ;
for ( V_39 = 0 ; V_39 < V_38 -> V_41 -> V_83 ; V_39 ++ ) {
F_65 ( V_38 -> V_75 [ V_39 ] . V_104 ) ;
F_65 ( V_38 -> V_75 [ V_39 ] . V_103 ) ;
F_46 ( V_73 , V_39 ) ;
}
return 0 ;
}
