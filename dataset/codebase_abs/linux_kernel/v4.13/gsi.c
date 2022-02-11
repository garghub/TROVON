static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static bool F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_7 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_4 . V_12 ;
struct V_13 * V_14 ;
T_1 V_15 ;
for ( V_15 = V_9 -> V_16 ; V_15 != V_9 -> V_17 ;
V_15 ++ ) {
V_14 = & V_9 -> V_18 [ V_15 % V_9 -> V_19 . V_20 ] ;
if ( ! V_14 -> V_21 )
break;
if ( V_9 -> V_22 == V_23 ||
V_14 -> V_24 & V_25 )
F_6 ( F_7 ( V_11 , & V_14 -> V_26 ) ) ;
V_14 -> V_21 = false ;
}
V_9 -> V_16 = V_15 ;
}
static void F_8 ( struct V_10 * V_27 , struct V_28 * V_26 )
{
struct V_1 * V_9 = V_27 -> V_29 ;
struct V_13 * V_14 =
F_2 ( V_26 -> V_30 , struct V_13 , V_31 ) ;
T_2 V_32 ;
unsigned long V_33 ;
F_9 ( & V_9 -> V_34 , V_33 ) ;
V_14 -> V_21 = true ;
V_32 = V_14 -> V_26 . V_32 ;
V_14 -> V_26 = * V_26 ;
V_14 -> V_26 . V_32 = V_32 ;
V_14 -> V_26 . V_3 = & V_9 -> V_4 ;
F_5 ( V_9 ) ;
F_10 ( & V_9 -> V_34 , V_33 ) ;
}
struct V_2 * F_11 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_12 ( V_36 -> V_39 ) ;
struct V_1 * V_9 ;
struct V_37 V_40 = * V_38 ;
const T_3 V_41 = V_38 -> V_41 ;
const int V_42 = V_36 -> V_39 -> V_43 . V_44 ;
const int V_45 = F_3 ( V_6 ) ? V_42 : 0 ;
int V_46 ;
F_13 ( V_6 , L_1 ) ;
if ( V_41 > F_14 ( V_6 -> V_47 . V_48 ) || V_41 < 1 ) {
F_15 ( V_6 ,
L_2 ,
V_41 ) ;
return F_16 ( - V_49 ) ;
}
V_9 = F_17 ( sizeof( * V_9 ) , V_50 ) ;
if ( ! V_9 )
return F_16 ( - V_51 ) ;
V_9 -> V_52 = F_18 ( V_45 , sizeof( * V_9 -> V_52 ) , V_50 ) ;
if ( ! V_9 -> V_52 ) {
V_46 = - V_51 ;
goto V_53;
}
V_9 -> V_18 = F_18 ( V_38 -> V_19 . V_20 ,
sizeof( * V_9 -> V_18 ) ,
V_50 ) ;
if ( ! V_9 -> V_18 ) {
V_46 = - V_51 ;
goto V_54;
}
F_19 ( & V_9 -> V_55 ) ;
F_20 ( & V_6 -> V_47 . V_55 ) ;
if ( V_6 -> V_47 . V_48 [ V_41 - 1 ] . V_9 ) {
F_15 ( V_6 , L_3 ,
V_41 ) ;
V_46 = - V_56 ;
goto V_57;
}
V_9 -> V_45 = V_45 ;
F_21 ( & V_9 -> V_34 ) ;
V_9 -> V_19 = V_38 -> V_19 ;
V_9 -> V_22 = V_38 -> V_22 ;
V_9 -> V_4 . V_58 = 1 ;
V_9 -> V_41 = V_41 ;
V_9 -> V_27 = F_22 ( V_36 -> V_39 , V_9 , V_38 -> V_19 . V_20 , 0 ,
V_59 ) ;
if ( F_23 ( V_9 -> V_27 ) ) {
F_15 ( V_6 , L_4 ,
F_24 ( V_9 -> V_27 ) ) ;
V_46 = F_24 ( V_9 -> V_27 ) ;
goto V_57;
}
V_40 . V_60 = V_61 ;
V_40 . V_12 = V_9 -> V_27 ;
if ( V_45 ) {
V_40 . V_19 . V_20 = 0 ;
V_40 . V_19 . V_62 = 0 ;
V_40 . V_19 . V_63 = 0 ;
}
V_9 -> V_64 = F_25 ( V_36 , & V_40 ) ;
if ( F_23 ( V_9 -> V_64 ) ) {
F_15 ( V_6 , L_5 ,
F_24 ( V_9 -> V_64 ) ) ;
V_46 = F_24 ( V_9 -> V_64 ) ;
goto V_65;
}
V_6 -> V_47 . V_48 [ V_38 -> V_41 - 1 ] . V_9 = V_9 ;
F_26 ( & V_6 -> V_47 . V_55 ) ;
return & V_9 -> V_4 ;
V_65:
F_27 ( V_9 -> V_27 ) ;
V_57:
F_26 ( & V_6 -> V_47 . V_55 ) ;
F_28 ( V_9 -> V_18 ) ;
V_54:
F_28 ( V_9 -> V_52 ) ;
V_53:
F_28 ( V_9 ) ;
return F_16 ( V_46 ) ;
}
int F_29 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_12 ( V_3 -> V_39 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
const int V_41 = V_9 -> V_41 ;
int V_66 ;
int V_46 ;
F_13 ( V_6 , L_6 ) ;
F_20 ( & V_6 -> V_47 . V_55 ) ;
V_46 = F_30 ( V_9 -> V_64 ) ;
if ( V_46 ) {
F_15 ( V_6 , L_7 ,
V_46 ) ;
F_26 ( & V_6 -> V_47 . V_55 ) ;
return V_46 ;
}
V_6 -> V_47 . V_48 [ V_41 - 1 ] . V_9 = NULL ;
F_26 ( & V_6 -> V_47 . V_55 ) ;
V_9 -> V_64 = NULL ;
for ( V_66 = 0 ; V_66 < V_9 -> V_45 ; ++ V_66 ) {
if ( ! V_9 -> V_52 [ V_66 ] )
continue;
F_6 ( F_30 ( V_9 -> V_52 [ V_66 ] ) ) ;
V_9 -> V_52 [ V_66 ] = NULL ;
}
F_27 ( V_9 -> V_27 ) ;
F_28 ( V_9 -> V_18 ) ;
F_28 ( V_9 -> V_52 ) ;
F_28 ( V_9 ) ;
return 0 ;
}
static struct V_2 * F_31 ( struct V_1 * V_9 )
{
struct V_35 * V_36 = V_9 -> V_64 -> V_36 ;
struct V_37 V_38 = {
. V_67 = V_9 -> V_64 -> V_67 ,
. V_68 = V_9 -> V_64 -> V_68 ,
. V_12 = V_9 -> V_27 ,
. V_69 = V_9 -> V_64 -> V_69 ,
. V_19 = {
. V_20 = V_9 -> V_19 . V_20 ,
. V_62 = V_9 -> V_19 . V_62 ,
. V_63 = V_9 -> V_19 . V_63 ,
} ,
. V_22 = V_9 -> V_22 ,
. V_60 = V_70 ,
. V_71 = F_32 () ,
} ;
return F_25 ( V_36 , & V_38 ) ;
}
static int F_33 ( struct V_1 * V_9 , struct V_2 * V_3 ,
T_4 V_66 )
{
struct V_5 * V_6 = F_12 ( V_3 -> V_39 ) ;
struct V_72 V_73 ;
int V_74 ;
int V_46 ;
V_74 = V_75 | V_76 | V_77 | V_78 ;
V_73 . V_79 = V_80 ;
V_73 . V_81 = V_66 ;
V_73 . V_82 = V_83 ;
V_73 . V_41 = V_9 -> V_41 ;
V_46 = F_34 ( V_3 , & V_73 , V_74 ) ;
if ( V_46 ) {
F_35 ( V_6 , L_8 ,
V_3 -> V_58 , V_46 ) ;
return V_46 ;
}
V_73 . V_79 = V_84 ;
V_46 = F_34 ( V_3 , & V_73 , V_75 ) ;
if ( V_46 ) {
F_35 ( V_6 , L_9 ,
V_3 -> V_58 , V_46 ) ;
return V_46 ;
}
V_73 . V_79 = V_85 ;
V_73 . V_86 = 0 ;
V_46 = F_34 ( V_3 , & V_73 , V_75 | V_87 ) ;
if ( V_46 ) {
F_35 ( V_6 , L_10 ,
V_3 -> V_58 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_9 , T_4 V_66 )
{
struct V_88 * V_39 = V_9 -> V_64 -> V_39 ;
struct V_5 * V_6 = F_12 ( V_39 ) ;
struct V_2 * V_3 ;
unsigned long V_33 ;
T_4 V_89 ;
int V_46 ;
V_46 = F_37 ( V_39 , V_9 -> V_41 , V_66 , & V_89 ) ;
if ( V_46 ) {
F_15 ( V_6 , L_11 ,
V_9 -> V_41 , V_66 ) ;
return;
}
if ( ! V_89 ) {
F_13 ( V_6 , L_12 ,
V_9 -> V_41 , V_66 ) ;
return;
}
F_9 ( & V_9 -> V_34 , V_33 ) ;
V_3 = V_9 -> V_52 [ V_66 ] ;
F_10 ( & V_9 -> V_34 , V_33 ) ;
if ( V_3 ) {
F_13 ( V_6 , L_13 ,
V_9 -> V_41 , V_66 ) ;
return;
}
V_3 = F_31 ( V_9 ) ;
if ( F_23 ( V_3 ) ) {
F_15 ( V_6 , L_14 ,
F_24 ( V_3 ) ) ;
return;
}
V_46 = F_33 ( V_9 , V_3 , V_66 ) ;
if ( V_46 )
goto V_90;
F_9 ( & V_9 -> V_34 , V_33 ) ;
F_6 ( V_9 -> V_52 [ V_66 ] ) ;
V_9 -> V_52 [ V_66 ] = V_3 ;
F_10 ( & V_9 -> V_34 , V_33 ) ;
return;
V_90:
F_6 ( V_3 ) ;
}
static void F_38 ( struct V_1 * V_9 )
{
T_4 V_66 ;
for ( V_66 = 0 ; V_66 < V_9 -> V_45 ; ++ V_66 )
F_36 ( V_9 , V_66 ) ;
}
int F_39 ( struct V_2 * V_3 , struct V_72 * V_73 ,
int V_91 )
{
struct V_5 * V_6 = F_12 ( V_3 -> V_39 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_46 ;
F_13 ( V_6 , L_15 , V_73 -> V_79 ) ;
F_20 ( & V_9 -> V_55 ) ;
V_46 = F_34 ( V_9 -> V_64 , V_73 , V_91 ) ;
if ( V_46 ) {
F_15 ( V_6 , L_16 , V_46 ) ;
goto V_92;
}
if ( F_40 ( V_9 -> V_64 ) -> V_93 == V_85 )
F_38 ( V_9 ) ;
V_92:
F_26 ( & V_9 -> V_55 ) ;
return V_46 ;
}
int F_41 ( struct V_2 * V_3 , struct V_72 * V_94 ,
int V_95 ,
struct V_37 * V_96 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_46 ;
F_20 ( & V_9 -> V_55 ) ;
V_46 = F_42 ( V_9 -> V_64 , V_94 , V_95 , V_96 ) ;
V_96 -> V_19 = V_9 -> V_19 ;
F_26 ( & V_9 -> V_55 ) ;
return V_46 ;
}
static int F_43 ( struct V_1 * V_9 ,
struct V_97 * V_14 , struct V_28 * V_26 )
{
struct V_5 * V_6 = F_12 ( V_9 -> V_64 -> V_39 ) ;
struct V_13 * V_98 ;
if ( V_9 -> V_17 == V_9 -> V_16 + V_9 -> V_19 . V_20 ) {
F_15 ( V_6 , L_17 ) ;
return - V_51 ;
}
V_98 = & V_9 -> V_18 [ V_9 -> V_17 %
V_9 -> V_19 . V_20 ] ;
V_9 -> V_17 ++ ;
if ( ! V_26 ) {
memset ( & V_98 -> V_26 , 0 , sizeof( V_98 -> V_26 ) ) ;
V_98 -> V_26 . V_81 = V_14 -> V_81 ;
V_98 -> V_26 . V_32 = V_14 -> V_14 . V_32 ;
} else {
V_98 -> V_26 = * V_26 ;
V_98 -> V_21 = true ;
}
V_98 -> V_31 . V_99 = & F_8 ;
V_14 -> V_14 . V_30 = & V_98 -> V_31 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_9 ,
struct V_97 * V_14 )
{
struct V_28 V_26 = {
{ . V_32 = V_14 -> V_14 . V_32 } ,
. V_100 = V_101 ,
. V_102 = V_103 ,
. V_3 = & V_9 -> V_4 ,
} ;
int V_46 ;
V_46 = F_43 ( V_9 , V_14 , & V_26 ) ;
if ( V_46 )
return V_46 ;
F_5 ( V_9 ) ;
return 0 ;
}
static struct V_2 * F_45 ( struct V_1 * V_9 , struct V_97 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_9 -> V_64 -> V_39 ) ;
int V_66 = V_14 -> V_81 ;
if ( ! F_3 ( V_6 ) )
return V_9 -> V_64 ;
if ( V_66 >= V_9 -> V_45 )
return NULL ;
return V_9 -> V_52 [ V_66 ] ;
}
int F_46 ( struct V_2 * V_3 , struct V_104 * V_14 ,
struct V_104 * * V_105 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_2 * V_106 ;
unsigned long V_33 ;
int V_46 ;
for (; V_14 ; V_14 = V_14 -> V_107 ) {
struct V_97 V_108 = * F_47 ( V_14 ) ;
V_108 . V_14 . V_107 = NULL ;
F_9 ( & V_9 -> V_34 , V_33 ) ;
V_106 = F_45 ( V_9 , & V_108 ) ;
if ( ! V_106 ) {
V_46 = F_44 ( V_9 , & V_108 ) ;
if ( V_46 )
goto V_109;
F_10 ( & V_9 -> V_34 , V_33 ) ;
continue;
}
V_46 = F_43 ( V_9 , & V_108 , NULL ) ;
if ( V_46 )
goto V_109;
V_46 = F_48 ( V_106 , & V_108 . V_14 , V_105 ) ;
if ( V_46 ) {
V_9 -> V_17 = ( V_9 -> V_17 - 1 ) %
V_9 -> V_19 . V_20 ;
goto V_109;
}
F_10 ( & V_9 -> V_34 , V_33 ) ;
}
return 0 ;
V_109:
F_10 ( & V_9 -> V_34 , V_33 ) ;
* V_105 = V_14 ;
return V_46 ;
}
int F_49 ( struct V_2 * V_3 , struct V_110 * V_14 ,
struct V_110 * * V_105 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_50 ( V_9 -> V_64 , V_14 , V_105 ) ;
}
void F_51 ( struct V_1 * V_9 )
{
if ( ! V_9 )
return;
F_20 ( & V_9 -> V_55 ) ;
F_38 ( V_9 ) ;
F_26 ( & V_9 -> V_55 ) ;
}
