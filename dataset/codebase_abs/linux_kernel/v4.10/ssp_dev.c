static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 0 ) ;
F_3 ( 1000 , 1200 ) ;
F_2 ( V_2 -> V_3 , 1 ) ;
F_4 ( 50 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < V_6 ; ++ V_4 ) {
if ( V_2 -> V_7 & F_6 ( V_4 ) ) {
V_5 = F_7 ( V_2 , V_4 , V_2 -> V_8 [ V_4 ] ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_1 , V_4 ) ;
continue;
}
}
}
V_5 = F_9 ( V_2 , V_11 ,
V_2 -> V_12 ) ;
if ( V_5 < 0 )
F_8 ( & V_2 -> V_9 -> V_10 ,
L_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , bool V_13 )
{
F_11 ( & V_2 -> V_9 -> V_10 , L_3 , V_13 ,
V_2 -> V_14 ) ;
if ( V_13 && V_2 -> V_14 ) {
V_2 -> V_14 = false ;
F_12 ( V_2 -> V_9 -> V_15 ) ;
F_13 ( V_2 -> V_9 -> V_15 ) ;
} else if ( ! V_13 && ! V_2 -> V_14 ) {
V_2 -> V_14 = true ;
F_14 ( V_2 -> V_9 -> V_15 ) ;
F_15 ( V_2 -> V_9 -> V_15 ) ;
} else {
F_16 ( & V_2 -> V_9 -> V_10 , L_3 ,
V_13 , V_2 -> V_14 ) ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
while ( V_16 ++ < 5 ) {
V_2 -> V_17 = F_18 ( V_2 ) ;
if ( V_2 -> V_17 == V_18 ||
V_2 -> V_17 == V_19 ) {
F_16 ( & V_2 -> V_9 -> V_10 ,
L_4 , V_16 ) ;
} else {
break;
}
}
if ( V_2 -> V_17 == V_18 ||
V_2 -> V_17 == V_19 ) {
F_8 ( & V_2 -> V_9 -> V_10 , L_5 ) ;
return V_20 ;
}
F_11 ( & V_2 -> V_9 -> V_10 ,
L_6 ,
V_2 -> V_17 ,
V_2 -> V_21 -> V_22 ) ;
if ( V_2 -> V_17 != V_2 -> V_21 -> V_22 )
return V_20 ;
return V_23 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_10 ( V_2 , false ) ;
F_20 ( V_2 ) ;
F_1 ( V_2 ) ;
F_10 ( V_2 , true ) ;
}
static void F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_22 ( V_25 , struct V_1 , V_26 ) ;
F_8 ( & V_2 -> V_9 -> V_10 , L_7 ,
V_27 , V_2 -> V_7 , V_2 -> V_28 ,
V_2 -> V_29 ) ;
F_19 ( V_2 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
}
static void F_23 ( unsigned long V_31 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
switch ( V_2 -> V_32 ) {
case V_33 :
case V_34 :
case V_35 :
goto V_36;
}
if ( V_2 -> V_30 > V_37 ||
V_2 -> V_29 > V_38 )
F_24 ( V_39 , & V_2 -> V_26 ) ;
V_36:
F_25 ( & V_2 -> V_40 , V_41 + F_26 ( V_42 ) ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_40 , V_41 + F_26 ( V_42 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_40 ) ;
F_30 ( & V_2 -> V_26 ) ;
}
T_1 F_31 ( struct V_1 * V_2 , enum V_43 type )
{
return V_2 -> V_8 [ type ] ;
}
int F_7 ( struct V_1 * V_2 , enum V_43 type ,
T_1 V_44 )
{
int V_5 ;
struct V_45 V_46 ;
V_46 . V_47 = F_32 ( V_44 ) ;
V_46 . V_48 = F_32 ( V_2 -> V_49 [ type ] ) ;
V_46 . V_50 = V_2 -> V_51 [ type ] ;
switch ( V_2 -> V_52 [ type ] ) {
case V_53 :
case V_54 :
V_5 = F_33 ( V_2 ,
V_55 ,
type ,
( V_56 * ) & V_46 , sizeof( V_46 ) ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 , L_8 ) ;
V_2 -> V_52 [ type ] = V_57 ;
goto V_58;
}
V_2 -> V_59 |= F_6 ( type ) ;
V_2 -> V_52 [ type ] = V_60 ;
break;
case V_60 :
V_5 = F_33 ( V_2 ,
V_61 , type ,
( V_56 * ) & V_46 , sizeof( V_46 ) ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_9 ) ;
goto V_58;
}
break;
default:
V_2 -> V_52 [ type ] = V_54 ;
break;
}
V_2 -> V_8 [ type ] = V_44 ;
if ( F_34 ( & V_2 -> V_62 ) == 1 )
F_27 ( V_2 ) ;
return 0 ;
V_58:
return V_5 ;
}
int F_35 ( struct V_1 * V_2 , enum V_43 type ,
T_1 V_44 )
{
int V_5 ;
struct V_45 V_46 ;
V_46 . V_47 = F_32 ( V_44 ) ;
V_46 . V_48 = F_32 ( V_2 -> V_49 [ type ] ) ;
V_46 . V_50 = V_2 -> V_51 [ type ] ;
V_5 = F_33 ( V_2 , V_61 , type ,
( V_56 * ) & V_46 , sizeof( V_46 ) ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 , L_9 ) ;
return V_5 ;
}
V_2 -> V_8 [ type ] = V_44 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , enum V_43 type )
{
int V_5 ;
T_2 V_63 ;
if ( V_2 -> V_59 & F_6 ( type ) ) {
V_63 = F_32 ( V_2 -> V_8 [ type ] ) ;
V_5 = F_33 ( V_2 ,
V_64 ,
type , ( V_56 * ) & V_63 ,
sizeof( V_63 ) ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 , L_10 ) ;
return V_5 ;
}
V_2 -> V_59 &= ~ F_6 ( type ) ;
}
V_2 -> V_52 [ type ] = V_54 ;
if ( F_37 ( & V_2 -> V_62 ) )
F_28 ( V_2 ) ;
return 0 ;
}
static T_3 F_38 ( int V_15 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
F_39 ( V_2 ) ;
return V_66 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_5 ;
F_20 ( V_2 ) ;
V_5 = F_41 ( V_2 ) ;
if ( V_5 != V_67 ) {
F_8 ( & V_2 -> V_9 -> V_10 , L_11 , V_27 ,
V_5 < 0 ? L_12 : L_13 ,
V_5 ) ;
return V_5 < 0 ? V_5 : - V_68 ;
}
F_11 ( & V_2 -> V_9 -> V_10 , L_14 , V_5 ) ;
V_5 = F_42 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_15 , V_27 ) ;
return V_5 ;
}
V_2 -> V_7 = F_43 ( V_2 ) ;
if ( V_2 -> V_7 == 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_16 , V_27 ) ;
return - V_69 ;
}
V_2 -> V_17 = F_18 ( V_2 ) ;
F_11 ( & V_2 -> V_9 -> V_10 , L_17 ,
V_2 -> V_17 ) ;
return F_9 ( V_2 , V_70 , 0 ) ;
}
static void F_44 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_22 ( (struct V_71 * ) V_25 ,
struct V_1 , V_72 ) ;
F_11 ( & V_2 -> V_9 -> V_10 , L_18 ) ;
V_2 -> V_28 ++ ;
if ( F_40 ( V_2 ) >= 0 ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_73 != 0 )
F_9 ( V_2 , V_2 -> V_73 , 0 ) ;
if ( V_2 -> V_74 != 0 )
F_9 ( V_2 , V_2 -> V_74 , 0 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_29 = 0 ;
}
}
int F_45 ( struct V_1 * V_2 , unsigned int V_44 )
{
F_46 ( & V_2 -> V_72 ) ;
return F_47 ( V_39 ,
& V_2 -> V_72 ,
F_26 ( V_44 ) ) ;
}
static struct V_1 * F_48 ( struct V_75 * V_10 )
{
int V_5 ;
struct V_1 * V_2 ;
struct V_76 * V_77 = V_10 -> V_78 ;
const struct V_79 * V_80 ;
V_2 = F_49 ( V_10 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_82 = F_50 ( V_77 , L_19 , 0 ) ;
if ( V_2 -> V_82 < 0 )
goto V_83;
V_2 -> V_84 = F_50 ( V_77 , L_20 , 0 ) ;
if ( V_2 -> V_84 < 0 )
goto V_83;
V_2 -> V_3 = F_50 ( V_77 , L_21 , 0 ) ;
if ( V_2 -> V_3 < 0 )
goto V_83;
V_5 = F_51 ( V_10 , V_2 -> V_84 , V_85 ,
L_20 ) ;
if ( V_5 )
goto V_83;
V_5 = F_51 ( V_10 , V_2 -> V_3 ,
V_85 , L_21 ) ;
if ( V_5 )
goto V_86;
V_80 = F_52 ( V_87 , V_77 ) ;
if ( ! V_80 )
goto V_88;
V_2 -> V_21 = (struct V_89 * ) V_80 -> V_2 ;
F_53 ( V_10 , V_2 ) ;
return V_2 ;
V_88:
F_54 ( V_10 , V_2 -> V_3 ) ;
V_86:
F_54 ( V_10 , V_2 -> V_84 ) ;
V_83:
F_55 ( V_10 , V_2 ) ;
return NULL ;
}
static struct V_1 * F_48 ( struct V_75 * V_90 )
{
return NULL ;
}
void F_56 ( struct V_91 * V_92 , enum V_43 type )
{
struct V_1 * V_2 = F_57 ( V_92 -> V_10 . V_93 -> V_93 ) ;
V_2 -> V_94 [ type ] = V_92 ;
}
static int F_58 ( struct V_95 * V_9 )
{
int V_5 , V_4 ;
struct V_1 * V_2 ;
V_2 = F_48 ( & V_9 -> V_10 ) ;
if ( ! V_2 ) {
F_8 ( & V_9 -> V_10 , L_22 ) ;
return - V_68 ;
}
V_5 = F_59 ( & V_9 -> V_10 , - 1 , V_96 ,
F_60 ( V_96 ) , NULL , 0 , NULL ) ;
if ( V_5 < 0 ) {
F_8 ( & V_9 -> V_10 , L_23 ) ;
return V_5 ;
}
V_9 -> V_97 = V_98 ;
V_5 = F_61 ( V_9 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_9 -> V_10 , L_24 ) ;
return V_5 ;
}
V_2 -> V_32 = V_23 ;
V_2 -> V_9 = V_9 ;
F_62 ( V_9 , V_2 ) ;
F_63 ( & V_2 -> V_99 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; ++ V_4 ) {
V_2 -> V_8 [ V_4 ] = V_100 ;
V_2 -> V_49 [ V_4 ] = 0 ;
V_2 -> V_51 [ V_4 ] = 0 ;
V_2 -> V_52 [ V_4 ] = V_53 ;
}
V_2 -> V_8 [ V_101 ] = 100 ;
V_2 -> V_102 = true ;
F_63 ( & V_2 -> V_103 ) ;
F_64 ( & V_2 -> V_104 ) ;
F_65 ( & V_2 -> V_62 , 0 ) ;
F_66 ( & V_2 -> V_26 , F_21 ) ;
F_67 ( & V_2 -> V_72 , F_44 ) ;
F_68 ( & V_2 -> V_40 , F_23 , ( unsigned long ) V_2 ) ;
V_5 = F_69 ( V_2 -> V_9 -> V_15 , NULL ,
F_38 ,
V_105 | V_106 ,
L_25 , V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_9 -> V_10 , L_26 ) ;
goto V_107;
}
V_2 -> V_14 = false ;
F_13 ( V_2 -> V_9 -> V_15 ) ;
V_2 -> V_32 = F_17 ( V_2 ) ;
if ( V_2 -> V_32 == V_23 ) {
V_5 = F_40 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_9 -> V_10 , L_27 ) ;
goto V_108;
}
} else {
F_8 ( & V_9 -> V_10 , L_28 ) ;
V_5 = - V_109 ;
goto V_108;
}
return 0 ;
V_108:
F_70 ( V_2 -> V_9 -> V_15 , V_2 ) ;
V_107:
F_71 ( & V_2 -> V_103 ) ;
F_71 ( & V_2 -> V_99 ) ;
F_8 ( & V_9 -> V_10 , L_29 ) ;
return V_5 ;
}
static int F_72 ( struct V_95 * V_9 )
{
struct V_1 * V_2 = F_73 ( V_9 ) ;
if ( F_9 ( V_2 , V_110 , 0 ) < 0 )
F_8 ( & V_2 -> V_9 -> V_10 ,
L_30 ) ;
F_10 ( V_2 , false ) ;
F_28 ( V_2 ) ;
F_20 ( V_2 ) ;
F_70 ( V_2 -> V_9 -> V_15 , V_2 ) ;
F_29 ( & V_2 -> V_40 ) ;
F_30 ( & V_2 -> V_26 ) ;
F_71 ( & V_2 -> V_99 ) ;
F_71 ( & V_2 -> V_103 ) ;
F_74 ( & V_9 -> V_10 ) ;
return 0 ;
}
static int F_75 ( struct V_75 * V_10 )
{
int V_5 ;
struct V_1 * V_2 = F_73 ( F_76 ( V_10 ) ) ;
V_2 -> V_74 = V_111 ;
if ( F_77 ( & V_2 -> V_62 ) > 0 )
F_28 ( V_2 ) ;
V_5 = F_9 ( V_2 , V_111 , 0 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_31 , V_27 ) ;
F_27 ( V_2 ) ;
return V_5 ;
}
V_2 -> V_102 = false ;
F_14 ( V_2 -> V_9 -> V_15 ) ;
return 0 ;
}
static int F_78 ( struct V_75 * V_10 )
{
int V_5 ;
struct V_1 * V_2 = F_73 ( F_76 ( V_10 ) ) ;
F_12 ( V_2 -> V_9 -> V_15 ) ;
if ( F_77 ( & V_2 -> V_62 ) > 0 )
F_27 ( V_2 ) ;
V_5 = F_9 ( V_2 , V_112 , 0 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_2 -> V_9 -> V_10 ,
L_32 , V_27 ) ;
F_28 ( V_2 ) ;
return V_5 ;
}
V_2 -> V_74 = V_112 ;
return 0 ;
}
