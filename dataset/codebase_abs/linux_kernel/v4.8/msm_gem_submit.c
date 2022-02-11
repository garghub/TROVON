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
V_31 = F_12 ( & V_34 , V_39 , sizeof( V_34 ) ) ;
if ( F_19 ( V_31 ) ) {
F_20 () ;
F_21 ( & V_29 -> V_32 ) ;
V_31 = F_22 ( & V_34 , V_39 , sizeof( V_34 ) ) ;
if ( V_31 )
goto V_41;
F_16 ( & V_29 -> V_32 ) ;
F_17 () ;
}
if ( V_34 . V_40 & ~ V_42 ) {
F_23 ( L_1 , V_34 . V_40 ) ;
V_31 = - V_43 ;
goto V_44;
}
V_8 -> V_10 [ V_30 ] . V_40 = V_34 . V_40 ;
V_8 -> V_10 [ V_30 ] . V_45 = V_34 . V_46 ;
V_36 = F_24 ( & V_29 -> V_47 , V_34 . V_48 ) ;
if ( ! V_36 ) {
F_23 ( L_2 , V_34 . V_48 , V_30 ) ;
V_31 = - V_43 ;
goto V_44;
}
V_38 = F_25 ( V_36 ) ;
if ( ! F_26 ( & V_38 -> V_49 ) ) {
F_23 ( L_3 ,
V_34 . V_48 , V_30 ) ;
V_31 = - V_43 ;
goto V_44;
}
F_27 ( V_36 ) ;
V_8 -> V_10 [ V_30 ] . V_36 = V_38 ;
F_28 ( & V_38 -> V_49 , & V_8 -> V_19 ) ;
}
V_44:
F_20 () ;
F_21 ( & V_29 -> V_32 ) ;
V_41:
V_8 -> V_6 = V_30 ;
return V_31 ;
}
static void F_29 ( struct V_1 * V_8 , int V_30 )
{
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
if ( V_8 -> V_10 [ V_30 ] . V_40 & V_50 )
F_30 ( & V_38 -> V_51 , V_8 -> V_5 -> V_52 ) ;
if ( V_8 -> V_10 [ V_30 ] . V_40 & V_53 )
F_31 ( & V_38 -> V_54 -> V_55 ) ;
if ( ! ( V_8 -> V_10 [ V_30 ] . V_40 & V_56 ) )
V_8 -> V_10 [ V_30 ] . V_45 = 0 ;
V_8 -> V_10 [ V_30 ] . V_40 &= ~ ( V_53 | V_50 ) ;
}
static int F_32 ( struct V_1 * V_8 )
{
int V_57 , V_58 = - 1 , V_30 , V_31 = 0 ;
V_59:
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
if ( V_58 == V_30 )
V_58 = - 1 ;
V_57 = V_30 ;
if ( ! ( V_8 -> V_10 [ V_30 ] . V_40 & V_53 ) ) {
V_31 = F_33 ( & V_38 -> V_54 -> V_55 ,
& V_8 -> V_20 ) ;
if ( V_31 )
goto V_60;
V_8 -> V_10 [ V_30 ] . V_40 |= V_53 ;
}
}
F_34 ( & V_8 -> V_20 ) ;
return 0 ;
V_60:
for (; V_30 >= 0 ; V_30 -- )
F_29 ( V_8 , V_30 ) ;
if ( V_58 > 0 )
F_29 ( V_8 , V_58 ) ;
if ( V_31 == - V_61 ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_57 ] . V_36 ;
V_31 = F_35 ( & V_38 -> V_54 -> V_55 ,
& V_8 -> V_20 ) ;
if ( ! V_31 ) {
V_8 -> V_10 [ V_57 ] . V_40 |= V_53 ;
V_58 = V_57 ;
goto V_59;
}
}
return V_31 ;
}
static int F_36 ( struct V_1 * V_8 )
{
int V_30 , V_31 = 0 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
bool V_62 = V_8 -> V_10 [ V_30 ] . V_40 & V_63 ;
V_31 = F_37 ( & V_38 -> V_51 , V_8 -> V_5 -> V_64 , V_62 ) ;
if ( V_31 )
break;
}
return V_31 ;
}
static int F_38 ( struct V_1 * V_8 )
{
int V_30 , V_31 = 0 ;
V_8 -> V_65 = true ;
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
T_3 V_45 ;
V_31 = F_39 ( & V_38 -> V_51 ,
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
static int V_34 ( struct V_1 * V_8 , T_3 V_66 ,
struct V_37 * * V_36 , T_3 * V_45 , bool * V_65 )
{
if ( V_66 >= V_8 -> V_6 ) {
F_23 ( L_4 ,
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
static int F_40 ( struct V_1 * V_8 , struct V_37 * V_36 ,
T_3 V_67 , T_3 V_68 , T_4 V_69 )
{
T_3 V_30 , V_70 = 0 ;
T_3 * V_71 ;
int V_31 ;
if ( V_67 % 4 ) {
F_23 ( L_5 , V_67 ) ;
return - V_43 ;
}
V_71 = F_41 ( & V_36 -> V_51 ) ;
if ( F_42 ( V_71 ) ) {
V_31 = F_43 ( V_71 ) ;
F_44 ( L_6 , V_31 ) ;
return V_31 ;
}
for ( V_30 = 0 ; V_30 < V_68 ; V_30 ++ ) {
struct V_72 F_40 ;
void T_2 * V_39 =
F_18 ( V_69 + ( V_30 * sizeof( F_40 ) ) ) ;
T_3 V_45 , V_73 ;
bool V_65 ;
V_31 = F_22 ( & F_40 , V_39 , sizeof( F_40 ) ) ;
if ( V_31 )
return - V_26 ;
if ( F_40 . V_74 % 4 ) {
F_23 ( L_7 ,
F_40 . V_74 ) ;
return - V_43 ;
}
V_73 = F_40 . V_74 / 4 ;
if ( ( V_73 >= ( V_36 -> V_51 . V_75 / 4 ) ) ||
( V_73 < V_70 ) ) {
F_23 ( L_8 , V_73 , V_30 ) ;
return - V_43 ;
}
V_31 = V_34 ( V_8 , F_40 . V_76 , NULL , & V_45 , & V_65 ) ;
if ( V_31 )
return V_31 ;
if ( V_65 )
continue;
V_45 += F_40 . V_77 ;
if ( F_40 . V_78 < 0 )
V_45 >>= - F_40 . V_78 ;
else
V_45 <<= F_40 . V_78 ;
V_71 [ V_73 ] = V_45 | F_40 . V_79 ;
V_70 = V_73 ;
}
F_45 ( & V_36 -> V_51 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_8 )
{
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_6 ; V_30 ++ ) {
struct V_37 * V_38 = V_8 -> V_10 [ V_30 ] . V_36 ;
F_29 ( V_8 , V_30 ) ;
F_47 ( & V_38 -> V_49 ) ;
F_48 ( & V_38 -> V_51 ) ;
}
F_49 ( & V_8 -> V_20 ) ;
}
int F_50 ( struct V_2 * V_3 , void * V_80 ,
struct V_28 * V_29 )
{
struct V_81 * V_82 = V_3 -> V_83 ;
struct V_27 * args = V_80 ;
struct V_84 * V_85 = V_29 -> V_86 ;
struct V_1 * V_8 ;
struct V_4 * V_5 = V_82 -> V_5 ;
unsigned V_30 ;
int V_31 ;
if ( ! V_5 )
return - V_87 ;
if ( args -> V_88 != V_89 )
return - V_43 ;
V_31 = F_51 ( & V_3 -> V_90 ) ;
if ( V_31 )
return V_31 ;
V_82 -> V_91 = V_17 ;
V_8 = F_1 ( V_3 , V_5 , args -> V_6 , args -> V_7 ) ;
if ( ! V_8 ) {
V_31 = - V_92 ;
goto V_44;
}
V_31 = F_15 ( V_8 , args , V_29 ) ;
if ( V_31 )
goto V_41;
V_31 = F_32 ( V_8 ) ;
if ( V_31 )
goto V_41;
V_31 = F_36 ( V_8 ) ;
if ( V_31 )
goto V_41;
V_31 = F_38 ( V_8 ) ;
if ( V_31 )
goto V_41;
for ( V_30 = 0 ; V_30 < args -> V_7 ; V_30 ++ ) {
struct V_93 V_94 ;
void T_2 * V_39 =
F_18 ( args -> V_95 + ( V_30 * sizeof( V_94 ) ) ) ;
struct V_37 * V_38 ;
T_3 V_45 ;
V_31 = F_22 ( & V_94 , V_39 , sizeof( V_94 ) ) ;
if ( V_31 ) {
V_31 = - V_26 ;
goto V_41;
}
switch ( V_94 . type ) {
case V_96 :
case V_97 :
case V_98 :
break;
default:
F_23 ( L_9 , V_94 . type ) ;
V_31 = - V_43 ;
goto V_41;
}
V_31 = V_34 ( V_8 , V_94 . V_99 ,
& V_38 , & V_45 , NULL ) ;
if ( V_31 )
goto V_41;
if ( V_94 . V_75 % 4 ) {
F_23 ( L_10 ,
V_94 . V_75 ) ;
V_31 = - V_43 ;
goto V_41;
}
if ( ( V_94 . V_75 + V_94 . V_74 ) >=
V_38 -> V_51 . V_75 ) {
F_23 ( L_11 , V_94 . V_75 ) ;
V_31 = - V_43 ;
goto V_41;
}
V_8 -> V_11 [ V_30 ] . type = V_94 . type ;
V_8 -> V_11 [ V_30 ] . V_75 = V_94 . V_75 / 4 ;
V_8 -> V_11 [ V_30 ] . V_45 = V_45 + V_94 . V_74 ;
V_8 -> V_11 [ V_30 ] . V_66 = V_94 . V_99 ;
if ( V_8 -> V_65 )
continue;
V_31 = F_40 ( V_8 , V_38 , V_94 . V_74 ,
V_94 . V_68 , V_94 . V_69 ) ;
if ( V_31 )
goto V_41;
}
V_8 -> V_7 = V_30 ;
V_31 = F_52 ( V_5 , V_8 , V_85 ) ;
args -> V_15 = V_8 -> V_15 -> V_100 ;
V_41:
F_46 ( V_8 ) ;
if ( V_31 )
F_7 ( V_8 ) ;
V_44:
V_82 -> V_91 = NULL ;
F_53 ( & V_3 -> V_90 ) ;
return V_31 ;
}
