static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 , int V_7 )
{
struct V_1 * V_8 ;
int V_9 = sizeof( * V_8 ) + ( V_6 * sizeof( V_8 -> V_10 [ 0 ] ) ) +
( V_7 * sizeof( * V_8 -> V_11 ) ) ;
V_8 = F_2 ( V_9 , V_12 | V_13 | V_14 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_3 = V_3 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = F_3 ( F_4 ( V_17 ) ) ;
V_8 -> V_11 = ( void * ) & V_8 -> V_10 [ V_6 ] ;
V_8 -> V_6 = 0 ;
V_8 -> V_7 = 0 ;
F_5 ( & V_8 -> V_18 ) ;
F_5 ( & V_8 -> V_19 ) ;
F_6 ( & V_8 -> V_20 , & V_21 ) ;
return V_8 ;
}
void F_7 ( struct V_1 * V_8 )
{
F_8 ( V_8 -> V_15 ) ;
F_9 ( & V_8 -> V_18 ) ;
F_10 ( V_8 -> V_16 ) ;
F_11 ( V_8 ) ;
}
static inline unsigned long T_1
F_12 ( void * V_22 , const void T_2 * V_23 , unsigned long V_24 )
{
if ( F_13 ( V_25 , V_23 , V_24 ) )
return F_14 ( V_22 , V_23 , V_24 ) ;
return - V_26 ;
}
static int F_15 ( struct V_1 * V_8 ,
struct V_27 * args , struct V_28 * V_29 )
{
unsigned V_30 ;
int V_31 = 0 ;
F_16 ( & V_29 -> V_32 ) ;
F_17 () ;
for ( V_30 = 0 ; V_30 < args -> V_6 ; V_30 ++ ) {
struct V_33 V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
void T_2 * V_39 =
F_18 ( args -> V_10 + ( V_30 * sizeof( V_34 ) ) ) ;
V_8 -> V_10 [ V_30 ] . V_40 = 0 ;
if ( F_12 ( & V_34 , V_39 , sizeof( V_34 ) ) ) {
F_19 () ;
F_20 ( & V_29 -> V_32 ) ;
if ( F_21 ( & V_34 , V_39 , sizeof( V_34 ) ) ) {
V_31 = - V_26 ;
goto V_41;
}
F_16 ( & V_29 -> V_32 ) ;
F_17 () ;
}
if ( ( V_34 . V_40 & ~ V_42 ) ||
! ( V_34 . V_40 & V_42 ) ) {
F_22 ( L_1 , V_34 . V_40 ) ;
V_31 = - V_43 ;
goto V_44;
}
V_8 -> V_10 [ V_30 ] . V_40 = V_34 . V_40 ;
V_8 -> V_10 [ V_30 ] . V_45 = V_34 . V_46 ;
V_36 = F_23 ( & V_29 -> V_47 , V_34 . V_48 ) ;
if ( ! V_36 ) {
F_22 ( L_2 , V_34 . V_48 , V_30 ) ;
V_31 = - V_43 ;
goto V_44;
}
V_38 = F_24 ( V_36 ) ;
if ( ! F_25 ( & V_38 -> V_49 ) ) {
F_22 ( L_3 ,
V_34 . V_48 , V_30 ) ;
V_31 = - V_43 ;
goto V_44;
}
F_26 ( V_36 ) ;
V_8 -> V_10 [ V_30 ] . V_36 = V_38 ;
F_27 ( & V_38 -> V_49 , & V_8 -> V_19 ) ;
}
V_44:
F_19 () ;
F_20 ( & V_29 -> V_32 ) ;
V_41:
V_8 -> V_6 = V_30 ;
return V_31 ;
}
static void F_28 ( struct V_1 * V_8 , int V_30 )
{
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
if ( V_8 -> V_10 [ V_30 ] . V_40 & V_50 )
F_29 ( & V_38 -> V_51 , V_8 -> V_5 -> V_52 ) ;
if ( V_8 -> V_10 [ V_30 ] . V_40 & V_53 )
F_30 ( & V_38 -> V_54 -> V_55 ) ;
if ( ! ( V_8 -> V_10 [ V_30 ] . V_40 & V_56 ) )
V_8 -> V_10 [ V_30 ] . V_45 = 0 ;
V_8 -> V_10 [ V_30 ] . V_40 &= ~ ( V_53 | V_50 ) ;
}
static int F_31 ( struct V_1 * V_8 )
{
int V_57 , V_58 = - 1 , V_30 , V_31 = 0 ;
V_59:
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
if ( V_58 == V_30 )
V_58 = - 1 ;
V_57 = V_30 ;
if ( ! ( V_8 -> V_10 [ V_30 ] . V_40 & V_53 ) ) {
V_31 = F_32 ( & V_38 -> V_54 -> V_55 ,
& V_8 -> V_20 ) ;
if ( V_31 )
goto V_60;
V_8 -> V_10 [ V_30 ] . V_40 |= V_53 ;
}
}
F_33 ( & V_8 -> V_20 ) ;
return 0 ;
V_60:
for (; V_30 >= 0 ; V_30 -- )
F_28 ( V_8 , V_30 ) ;
if ( V_58 > 0 )
F_28 ( V_8 , V_58 ) ;
if ( V_31 == - V_61 ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_57 ] . V_36 ;
V_31 = F_34 ( & V_38 -> V_54 -> V_55 ,
& V_8 -> V_20 ) ;
if ( ! V_31 ) {
V_8 -> V_10 [ V_57 ] . V_40 |= V_53 ;
V_58 = V_57 ;
goto V_59;
}
}
return V_31 ;
}
static int F_35 ( struct V_1 * V_8 )
{
int V_30 , V_31 = 0 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
bool V_62 = V_8 -> V_10 [ V_30 ] . V_40 & V_63 ;
V_31 = F_36 ( & V_38 -> V_51 , V_8 -> V_5 -> V_64 , V_62 ) ;
if ( V_31 )
break;
}
return V_31 ;
}
static int F_37 ( struct V_1 * V_8 )
{
int V_30 , V_31 = 0 ;
V_8 -> V_65 = true ;
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
T_3 V_45 ;
V_31 = F_38 ( & V_38 -> V_51 ,
V_8 -> V_5 -> V_52 , & V_45 ) ;
if ( V_31 )
break;
V_8 -> V_10 [ V_30 ] . V_40 |= V_50 ;
if ( V_45 == V_8 -> V_10 [ V_30 ] . V_45 ) {
V_8 -> V_10 [ V_30 ] . V_40 |= V_56 ;
} else {
V_8 -> V_10 [ V_30 ] . V_45 = V_45 ;
V_8 -> V_10 [ V_30 ] . V_40 &= ~ V_56 ;
V_8 -> V_65 = false ;
}
}
return V_31 ;
}
static int V_34 ( struct V_1 * V_8 , T_4 V_66 ,
struct V_37 * * V_36 , T_3 * V_45 , bool * V_65 )
{
if ( V_66 >= V_8 -> V_6 ) {
F_22 ( L_4 ,
V_66 , V_8 -> V_6 ) ;
return - V_43 ;
}
if ( V_36 )
* V_36 = V_8 -> V_10 [ V_66 ] . V_36 ;
if ( V_45 )
* V_45 = V_8 -> V_10 [ V_66 ] . V_45 ;
if ( V_65 )
* V_65 = ! ! ( V_8 -> V_10 [ V_66 ] . V_40 & V_56 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_8 , struct V_37 * V_36 ,
T_4 V_67 , T_4 V_68 , T_3 V_69 )
{
T_4 V_30 , V_70 = 0 ;
T_4 * V_71 ;
int V_31 = 0 ;
if ( V_67 % 4 ) {
F_22 ( L_5 , V_67 ) ;
return - V_43 ;
}
V_71 = F_40 ( & V_36 -> V_51 ) ;
if ( F_41 ( V_71 ) ) {
V_31 = F_42 ( V_71 ) ;
F_43 ( L_6 , V_31 ) ;
return V_31 ;
}
for ( V_30 = 0 ; V_30 < V_68 ; V_30 ++ ) {
struct V_72 F_39 ;
void T_2 * V_39 =
F_18 ( V_69 + ( V_30 * sizeof( F_39 ) ) ) ;
T_4 V_73 ;
T_3 V_45 ;
bool V_65 ;
if ( F_21 ( & F_39 , V_39 , sizeof( F_39 ) ) ) {
V_31 = - V_26 ;
goto V_41;
}
if ( F_39 . V_74 % 4 ) {
F_22 ( L_7 ,
F_39 . V_74 ) ;
V_31 = - V_43 ;
goto V_41;
}
V_73 = F_39 . V_74 / 4 ;
if ( ( V_73 >= ( V_36 -> V_51 . V_75 / 4 ) ) ||
( V_73 < V_70 ) ) {
F_22 ( L_8 , V_73 , V_30 ) ;
V_31 = - V_43 ;
goto V_41;
}
V_31 = V_34 ( V_8 , F_39 . V_76 , NULL , & V_45 , & V_65 ) ;
if ( V_31 )
goto V_41;
if ( V_65 )
continue;
V_45 += F_39 . V_77 ;
if ( F_39 . V_78 < 0 )
V_45 >>= - F_39 . V_78 ;
else
V_45 <<= F_39 . V_78 ;
V_71 [ V_73 ] = V_45 | F_39 . V_79 ;
V_70 = V_73 ;
}
V_41:
F_44 ( & V_36 -> V_51 ) ;
return V_31 ;
}
static void F_45 ( struct V_1 * V_8 )
{
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
F_28 ( V_8 , V_30 ) ;
F_46 ( & V_38 -> V_49 ) ;
F_47 ( & V_38 -> V_51 ) ;
}
F_48 ( & V_8 -> V_20 ) ;
}
int F_49 ( struct V_2 * V_3 , void * V_80 ,
struct V_28 * V_29 )
{
struct V_81 * V_82 = V_3 -> V_83 ;
struct V_27 * args = V_80 ;
struct V_84 * V_85 = V_29 -> V_86 ;
struct V_1 * V_8 ;
struct V_4 * V_5 = V_82 -> V_5 ;
struct V_87 * V_88 = NULL ;
struct V_89 * V_89 = NULL ;
int V_90 = - 1 ;
unsigned V_30 ;
int V_31 ;
if ( ! V_5 )
return - V_91 ;
if ( F_50 ( args -> V_40 ) != V_92 )
return - V_43 ;
if ( F_51 ( args -> V_40 ) & ~ V_93 )
return - V_43 ;
V_31 = F_52 ( & V_3 -> V_94 ) ;
if ( V_31 )
return V_31 ;
if ( args -> V_40 & V_95 ) {
V_90 = F_53 ( V_96 ) ;
if ( V_90 < 0 ) {
V_31 = V_90 ;
goto V_44;
}
}
V_82 -> V_97 = V_17 ;
V_8 = F_1 ( V_3 , V_5 , args -> V_6 , args -> V_7 ) ;
if ( ! V_8 ) {
V_31 = - V_98 ;
goto V_44;
}
V_31 = F_15 ( V_8 , args , V_29 ) ;
if ( V_31 )
goto V_41;
V_31 = F_31 ( V_8 ) ;
if ( V_31 )
goto V_41;
if ( args -> V_40 & V_99 ) {
V_88 = F_54 ( args -> V_100 ) ;
if ( ! V_88 ) {
V_31 = - V_43 ;
goto V_41;
}
if ( V_88 -> V_101 != V_5 -> V_64 -> V_101 ) {
V_31 = F_55 ( V_88 , true ) ;
if ( V_31 )
goto V_41;
}
}
if ( ! ( args -> V_15 & V_102 ) ) {
V_31 = F_35 ( V_8 ) ;
if ( V_31 )
goto V_41;
}
V_31 = F_37 ( V_8 ) ;
if ( V_31 )
goto V_41;
for ( V_30 = 0 ; V_30 < args -> V_7 ; V_30 ++ ) {
struct V_103 V_104 ;
void T_2 * V_39 =
F_18 ( args -> V_105 + ( V_30 * sizeof( V_104 ) ) ) ;
struct V_37 * V_38 ;
T_3 V_45 ;
V_31 = F_21 ( & V_104 , V_39 , sizeof( V_104 ) ) ;
if ( V_31 ) {
V_31 = - V_26 ;
goto V_41;
}
switch ( V_104 . type ) {
case V_106 :
case V_107 :
case V_108 :
break;
default:
F_22 ( L_9 , V_104 . type ) ;
V_31 = - V_43 ;
goto V_41;
}
V_31 = V_34 ( V_8 , V_104 . V_109 ,
& V_38 , & V_45 , NULL ) ;
if ( V_31 )
goto V_41;
if ( V_104 . V_75 % 4 ) {
F_22 ( L_10 ,
V_104 . V_75 ) ;
V_31 = - V_43 ;
goto V_41;
}
if ( ( V_104 . V_75 + V_104 . V_74 ) >=
V_38 -> V_51 . V_75 ) {
F_22 ( L_11 , V_104 . V_75 ) ;
V_31 = - V_43 ;
goto V_41;
}
V_8 -> V_11 [ V_30 ] . type = V_104 . type ;
V_8 -> V_11 [ V_30 ] . V_75 = V_104 . V_75 / 4 ;
V_8 -> V_11 [ V_30 ] . V_45 = V_45 + V_104 . V_74 ;
V_8 -> V_11 [ V_30 ] . V_66 = V_104 . V_109 ;
if ( V_8 -> V_65 )
continue;
V_31 = F_39 ( V_8 , V_38 , V_104 . V_74 ,
V_104 . V_68 , V_104 . V_69 ) ;
if ( V_31 )
goto V_41;
}
V_8 -> V_7 = V_30 ;
V_8 -> V_15 = F_56 ( V_5 -> V_64 ) ;
if ( F_41 ( V_8 -> V_15 ) ) {
V_31 = F_42 ( V_8 -> V_15 ) ;
V_8 -> V_15 = NULL ;
goto V_41;
}
if ( args -> V_40 & V_95 ) {
V_89 = F_57 ( V_8 -> V_15 ) ;
if ( ! V_89 ) {
V_31 = - V_98 ;
goto V_41;
}
}
F_58 ( V_5 , V_8 , V_85 ) ;
args -> V_15 = V_8 -> V_15 -> V_110 ;
if ( args -> V_40 & V_95 ) {
F_59 ( V_90 , V_89 -> V_29 ) ;
args -> V_100 = V_90 ;
}
V_41:
if ( V_88 )
F_8 ( V_88 ) ;
F_45 ( V_8 ) ;
if ( V_31 )
F_7 ( V_8 ) ;
V_44:
if ( V_31 && ( V_90 >= 0 ) )
F_60 ( V_90 ) ;
V_82 -> V_97 = NULL ;
F_61 ( & V_3 -> V_94 ) ;
return V_31 ;
}
