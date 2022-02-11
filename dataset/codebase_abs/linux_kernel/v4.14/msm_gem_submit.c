static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
struct V_1 * V_8 ;
T_2 V_9 = sizeof( * V_8 ) + ( ( V_10 ) V_6 * sizeof( V_8 -> V_11 [ 0 ] ) ) +
( ( V_10 ) V_7 * sizeof( V_8 -> V_12 [ 0 ] ) ) ;
if ( V_9 > V_13 )
return NULL ;
V_8 = F_2 ( V_9 , V_14 | V_15 | V_16 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_3 = V_3 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_17 = NULL ;
V_8 -> V_18 = F_3 ( F_4 ( V_19 ) ) ;
V_8 -> V_12 = ( void * ) & V_8 -> V_11 [ V_6 ] ;
V_8 -> V_6 = 0 ;
V_8 -> V_7 = 0 ;
F_5 ( & V_8 -> V_20 ) ;
F_5 ( & V_8 -> V_21 ) ;
F_6 ( & V_8 -> V_22 , & V_23 ) ;
return V_8 ;
}
void F_7 ( struct V_1 * V_8 )
{
F_8 ( V_8 -> V_17 ) ;
F_9 ( & V_8 -> V_20 ) ;
F_10 ( V_8 -> V_18 ) ;
F_11 ( V_8 ) ;
}
static inline unsigned long T_3
F_12 ( void * V_24 , const void T_4 * V_25 , unsigned long V_26 )
{
if ( F_13 ( V_27 , V_25 , V_26 ) )
return F_14 ( V_24 , V_25 , V_26 ) ;
return - V_28 ;
}
static int F_15 ( struct V_1 * V_8 ,
struct V_29 * args , struct V_30 * V_31 )
{
unsigned V_32 ;
int V_33 = 0 ;
F_16 ( & V_31 -> V_34 ) ;
F_17 () ;
for ( V_32 = 0 ; V_32 < args -> V_6 ; V_32 ++ ) {
struct V_35 V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
void T_4 * V_41 =
F_18 ( args -> V_11 + ( V_32 * sizeof( V_36 ) ) ) ;
V_8 -> V_11 [ V_32 ] . V_42 = 0 ;
if ( F_12 ( & V_36 , V_41 , sizeof( V_36 ) ) ) {
F_19 () ;
F_20 ( & V_31 -> V_34 ) ;
if ( F_21 ( & V_36 , V_41 , sizeof( V_36 ) ) ) {
V_33 = - V_28 ;
goto V_43;
}
F_16 ( & V_31 -> V_34 ) ;
F_17 () ;
}
if ( ( V_36 . V_42 & ~ V_44 ) ||
! ( V_36 . V_42 & V_44 ) ) {
F_22 ( L_1 , V_36 . V_42 ) ;
V_33 = - V_45 ;
goto V_46;
}
V_8 -> V_11 [ V_32 ] . V_42 = V_36 . V_42 ;
V_8 -> V_11 [ V_32 ] . V_47 = V_36 . V_48 ;
V_38 = F_23 ( & V_31 -> V_49 , V_36 . V_50 ) ;
if ( ! V_38 ) {
F_22 ( L_2 , V_36 . V_50 , V_32 ) ;
V_33 = - V_45 ;
goto V_46;
}
V_40 = F_24 ( V_38 ) ;
if ( ! F_25 ( & V_40 -> V_51 ) ) {
F_22 ( L_3 ,
V_36 . V_50 , V_32 ) ;
V_33 = - V_45 ;
goto V_46;
}
F_26 ( V_38 ) ;
V_8 -> V_11 [ V_32 ] . V_38 = V_40 ;
F_27 ( & V_40 -> V_51 , & V_8 -> V_21 ) ;
}
V_46:
F_19 () ;
F_20 ( & V_31 -> V_34 ) ;
V_43:
V_8 -> V_6 = V_32 ;
return V_33 ;
}
static void F_28 ( struct V_1 * V_8 , int V_32 )
{
struct V_39 * V_40 = V_8 -> V_11 [ V_32 ] . V_38 ;
if ( V_8 -> V_11 [ V_32 ] . V_42 & V_52 )
F_29 ( & V_40 -> V_53 , V_8 -> V_5 -> V_54 ) ;
if ( V_8 -> V_11 [ V_32 ] . V_42 & V_55 )
F_30 ( & V_40 -> V_56 -> V_57 ) ;
if ( ! ( V_8 -> V_11 [ V_32 ] . V_42 & V_58 ) )
V_8 -> V_11 [ V_32 ] . V_47 = 0 ;
V_8 -> V_11 [ V_32 ] . V_42 &= ~ ( V_55 | V_52 ) ;
}
static int F_31 ( struct V_1 * V_8 )
{
int V_59 , V_60 = - 1 , V_32 , V_33 = 0 ;
V_61:
for ( V_32 = 0 ; V_32 < V_8 -> V_6 ; V_32 ++ ) {
struct V_39 * V_40 = V_8 -> V_11 [ V_32 ] . V_38 ;
if ( V_60 == V_32 )
V_60 = - 1 ;
V_59 = V_32 ;
if ( ! ( V_8 -> V_11 [ V_32 ] . V_42 & V_55 ) ) {
V_33 = F_32 ( & V_40 -> V_56 -> V_57 ,
& V_8 -> V_22 ) ;
if ( V_33 )
goto V_62;
V_8 -> V_11 [ V_32 ] . V_42 |= V_55 ;
}
}
F_33 ( & V_8 -> V_22 ) ;
return 0 ;
V_62:
for (; V_32 >= 0 ; V_32 -- )
F_28 ( V_8 , V_32 ) ;
if ( V_60 > 0 )
F_28 ( V_8 , V_60 ) ;
if ( V_33 == - V_63 ) {
struct V_39 * V_40 = V_8 -> V_11 [ V_59 ] . V_38 ;
V_33 = F_34 ( & V_40 -> V_56 -> V_57 ,
& V_8 -> V_22 ) ;
if ( ! V_33 ) {
V_8 -> V_11 [ V_59 ] . V_42 |= V_55 ;
V_60 = V_59 ;
goto V_61;
}
}
return V_33 ;
}
static int F_35 ( struct V_1 * V_8 , bool V_64 )
{
int V_32 , V_33 = 0 ;
for ( V_32 = 0 ; V_32 < V_8 -> V_6 ; V_32 ++ ) {
struct V_39 * V_40 = V_8 -> V_11 [ V_32 ] . V_38 ;
bool V_65 = V_8 -> V_11 [ V_32 ] . V_42 & V_66 ;
if ( ! V_65 ) {
V_33 = F_36 ( V_40 -> V_56 ) ;
if ( V_33 )
return V_33 ;
}
if ( V_64 )
continue;
V_33 = F_37 ( & V_40 -> V_53 , V_8 -> V_5 -> V_67 , V_65 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static int F_38 ( struct V_1 * V_8 )
{
int V_32 , V_33 = 0 ;
V_8 -> V_68 = true ;
for ( V_32 = 0 ; V_32 < V_8 -> V_6 ; V_32 ++ ) {
struct V_39 * V_40 = V_8 -> V_11 [ V_32 ] . V_38 ;
T_2 V_47 ;
V_33 = F_39 ( & V_40 -> V_53 ,
V_8 -> V_5 -> V_54 , & V_47 ) ;
if ( V_33 )
break;
V_8 -> V_11 [ V_32 ] . V_42 |= V_52 ;
if ( V_47 == V_8 -> V_11 [ V_32 ] . V_47 ) {
V_8 -> V_11 [ V_32 ] . V_42 |= V_58 ;
} else {
V_8 -> V_11 [ V_32 ] . V_47 = V_47 ;
V_8 -> V_11 [ V_32 ] . V_42 &= ~ V_58 ;
V_8 -> V_68 = false ;
}
}
return V_33 ;
}
static int V_36 ( struct V_1 * V_8 , T_1 V_69 ,
struct V_39 * * V_38 , T_2 * V_47 , bool * V_68 )
{
if ( V_69 >= V_8 -> V_6 ) {
F_22 ( L_4 ,
V_69 , V_8 -> V_6 ) ;
return - V_45 ;
}
if ( V_38 )
* V_38 = V_8 -> V_11 [ V_69 ] . V_38 ;
if ( V_47 )
* V_47 = V_8 -> V_11 [ V_69 ] . V_47 ;
if ( V_68 )
* V_68 = ! ! ( V_8 -> V_11 [ V_69 ] . V_42 & V_58 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_8 , struct V_39 * V_38 ,
T_1 V_70 , T_1 V_71 , T_2 V_72 )
{
T_1 V_32 , V_73 = 0 ;
T_1 * V_74 ;
int V_33 = 0 ;
if ( V_70 % 4 ) {
F_22 ( L_5 , V_70 ) ;
return - V_45 ;
}
V_74 = F_41 ( & V_38 -> V_53 ) ;
if ( F_42 ( V_74 ) ) {
V_33 = F_43 ( V_74 ) ;
F_44 ( L_6 , V_33 ) ;
return V_33 ;
}
for ( V_32 = 0 ; V_32 < V_71 ; V_32 ++ ) {
struct V_75 F_40 ;
void T_4 * V_41 =
F_18 ( V_72 + ( V_32 * sizeof( F_40 ) ) ) ;
T_1 V_76 ;
T_2 V_47 ;
bool V_68 ;
if ( F_21 ( & F_40 , V_41 , sizeof( F_40 ) ) ) {
V_33 = - V_28 ;
goto V_43;
}
if ( F_40 . V_77 % 4 ) {
F_22 ( L_7 ,
F_40 . V_77 ) ;
V_33 = - V_45 ;
goto V_43;
}
V_76 = F_40 . V_77 / 4 ;
if ( ( V_76 >= ( V_38 -> V_53 . V_78 / 4 ) ) ||
( V_76 < V_73 ) ) {
F_22 ( L_8 , V_76 , V_32 ) ;
V_33 = - V_45 ;
goto V_43;
}
V_33 = V_36 ( V_8 , F_40 . V_79 , NULL , & V_47 , & V_68 ) ;
if ( V_33 )
goto V_43;
if ( V_68 )
continue;
V_47 += F_40 . V_80 ;
if ( F_40 . V_81 < 0 )
V_47 >>= - F_40 . V_81 ;
else
V_47 <<= F_40 . V_81 ;
V_74 [ V_76 ] = V_47 | F_40 . V_82 ;
V_73 = V_76 ;
}
V_43:
F_45 ( & V_38 -> V_53 ) ;
return V_33 ;
}
static void F_46 ( struct V_1 * V_8 )
{
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_8 -> V_6 ; V_32 ++ ) {
struct V_39 * V_40 = V_8 -> V_11 [ V_32 ] . V_38 ;
F_28 ( V_8 , V_32 ) ;
F_47 ( & V_40 -> V_51 ) ;
F_48 ( & V_40 -> V_53 ) ;
}
F_49 ( & V_8 -> V_22 ) ;
}
int F_50 ( struct V_2 * V_3 , void * V_83 ,
struct V_30 * V_31 )
{
struct V_84 * V_85 = V_3 -> V_86 ;
struct V_29 * args = V_83 ;
struct V_87 * V_88 = V_31 -> V_89 ;
struct V_1 * V_8 ;
struct V_4 * V_5 = V_85 -> V_5 ;
struct V_90 * V_91 = NULL ;
struct V_92 * V_92 = NULL ;
int V_93 = - 1 ;
unsigned V_32 ;
int V_33 ;
if ( ! V_5 )
return - V_94 ;
if ( F_51 ( args -> V_42 ) != V_95 )
return - V_45 ;
if ( F_52 ( args -> V_42 ) & ~ V_96 )
return - V_45 ;
if ( args -> V_42 & V_97 ) {
V_91 = F_53 ( args -> V_98 ) ;
if ( ! V_91 )
return - V_45 ;
if ( ! F_54 ( V_91 , V_5 -> V_67 -> V_99 ) ) {
V_33 = F_55 ( V_91 , true ) ;
if ( V_33 )
return V_33 ;
}
}
V_33 = F_56 ( & V_3 -> V_100 ) ;
if ( V_33 )
return V_33 ;
if ( args -> V_42 & V_101 ) {
V_93 = F_57 ( V_102 ) ;
if ( V_93 < 0 ) {
V_33 = V_93 ;
goto V_46;
}
}
V_85 -> V_103 = V_19 ;
V_8 = F_1 ( V_3 , V_5 , args -> V_6 , args -> V_7 ) ;
if ( ! V_8 ) {
V_33 = - V_104 ;
goto V_46;
}
V_33 = F_15 ( V_8 , args , V_31 ) ;
if ( V_33 )
goto V_43;
V_33 = F_31 ( V_8 ) ;
if ( V_33 )
goto V_43;
V_33 = F_35 ( V_8 , ! ! ( args -> V_42 & V_105 ) ) ;
if ( V_33 )
goto V_43;
V_33 = F_38 ( V_8 ) ;
if ( V_33 )
goto V_43;
for ( V_32 = 0 ; V_32 < args -> V_7 ; V_32 ++ ) {
struct V_106 V_107 ;
void T_4 * V_41 =
F_18 ( args -> V_108 + ( V_32 * sizeof( V_107 ) ) ) ;
struct V_39 * V_40 ;
T_2 V_47 ;
V_33 = F_21 ( & V_107 , V_41 , sizeof( V_107 ) ) ;
if ( V_33 ) {
V_33 = - V_28 ;
goto V_43;
}
switch ( V_107 . type ) {
case V_109 :
case V_110 :
case V_111 :
break;
default:
F_22 ( L_9 , V_107 . type ) ;
V_33 = - V_45 ;
goto V_43;
}
V_33 = V_36 ( V_8 , V_107 . V_112 ,
& V_40 , & V_47 , NULL ) ;
if ( V_33 )
goto V_43;
if ( V_107 . V_78 % 4 ) {
F_22 ( L_10 ,
V_107 . V_78 ) ;
V_33 = - V_45 ;
goto V_43;
}
if ( ! V_107 . V_78 ||
( ( V_107 . V_78 + V_107 . V_77 ) >
V_40 -> V_53 . V_78 ) ) {
F_22 ( L_11 , V_107 . V_78 ) ;
V_33 = - V_45 ;
goto V_43;
}
V_8 -> V_12 [ V_32 ] . type = V_107 . type ;
V_8 -> V_12 [ V_32 ] . V_78 = V_107 . V_78 / 4 ;
V_8 -> V_12 [ V_32 ] . V_47 = V_47 + V_107 . V_77 ;
V_8 -> V_12 [ V_32 ] . V_69 = V_107 . V_112 ;
if ( V_8 -> V_68 )
continue;
V_33 = F_40 ( V_8 , V_40 , V_107 . V_77 ,
V_107 . V_71 , V_107 . V_72 ) ;
if ( V_33 )
goto V_43;
}
V_8 -> V_7 = V_32 ;
V_8 -> V_17 = F_58 ( V_5 -> V_67 ) ;
if ( F_42 ( V_8 -> V_17 ) ) {
V_33 = F_43 ( V_8 -> V_17 ) ;
V_8 -> V_17 = NULL ;
goto V_43;
}
if ( args -> V_42 & V_101 ) {
V_92 = F_59 ( V_8 -> V_17 ) ;
if ( ! V_92 ) {
V_33 = - V_104 ;
goto V_43;
}
}
F_60 ( V_5 , V_8 , V_88 ) ;
args -> V_17 = V_8 -> V_17 -> V_113 ;
if ( args -> V_42 & V_101 ) {
F_61 ( V_93 , V_92 -> V_31 ) ;
args -> V_98 = V_93 ;
}
V_43:
if ( V_91 )
F_8 ( V_91 ) ;
F_46 ( V_8 ) ;
if ( V_33 )
F_7 ( V_8 ) ;
V_46:
if ( V_33 && ( V_93 >= 0 ) )
F_62 ( V_93 ) ;
V_85 -> V_103 = NULL ;
F_63 ( & V_3 -> V_100 ) ;
return V_33 ;
}
