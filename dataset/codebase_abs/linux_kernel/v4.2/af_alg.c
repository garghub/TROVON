static const struct V_1 * F_1 ( const char * V_2 )
{
const struct V_1 * type = F_2 ( - V_3 ) ;
struct V_4 * V_5 ;
F_3 ( & V_6 ) ;
F_4 (node, &alg_types, list) {
if ( strcmp ( V_5 -> type -> V_2 , V_2 ) )
continue;
if ( F_5 ( V_5 -> type -> V_7 ) )
type = V_5 -> type ;
break;
}
F_6 ( & V_6 ) ;
return type ;
}
int F_7 ( const struct V_1 * type )
{
struct V_4 * V_5 ;
int V_8 = - V_9 ;
F_8 ( & V_6 ) ;
F_4 (node, &alg_types, list) {
if ( ! strcmp ( V_5 -> type -> V_2 , type -> V_2 ) )
goto V_10;
}
V_5 = F_9 ( sizeof( * V_5 ) , V_11 ) ;
V_8 = - V_12 ;
if ( ! V_5 )
goto V_10;
type -> V_13 -> V_7 = V_14 ;
V_5 -> type = type ;
F_10 ( & V_5 -> V_15 , & V_16 ) ;
V_8 = 0 ;
V_10:
F_11 ( & V_6 ) ;
return V_8 ;
}
int F_12 ( const struct V_1 * type )
{
struct V_4 * V_5 ;
int V_8 = - V_3 ;
F_8 ( & V_6 ) ;
F_4 (node, &alg_types, list) {
if ( strcmp ( V_5 -> type -> V_2 , type -> V_2 ) )
continue;
F_13 ( & V_5 -> V_15 ) ;
F_14 ( V_5 ) ;
V_8 = 0 ;
break;
}
F_11 ( & V_6 ) ;
return V_8 ;
}
static void F_15 ( const struct V_1 * type , void * V_17 )
{
if ( ! type )
return;
type -> V_18 ( V_17 ) ;
F_16 ( type -> V_7 ) ;
}
int F_17 ( struct V_19 * V_20 )
{
if ( V_20 -> V_21 )
F_18 ( V_20 -> V_21 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 , struct V_22 * V_23 , int V_24 )
{
const T_1 V_25 = V_26 ;
struct V_20 * V_21 = V_20 -> V_21 ;
struct V_27 * V_28 = F_20 ( V_21 ) ;
struct V_29 * V_30 = ( void * ) V_23 ;
const struct V_1 * type ;
void * V_17 ;
if ( V_20 -> V_31 == V_32 )
return - V_33 ;
if ( V_24 != sizeof( * V_30 ) )
return - V_33 ;
V_30 -> V_34 [ sizeof( V_30 -> V_34 ) - 1 ] = 0 ;
V_30 -> V_35 [ sizeof( V_30 -> V_35 ) - 1 ] = 0 ;
type = F_1 ( V_30 -> V_34 ) ;
if ( F_21 ( type ) && F_22 ( type ) == - V_3 ) {
F_23 ( L_1 , V_30 -> V_34 ) ;
type = F_1 ( V_30 -> V_34 ) ;
}
if ( F_21 ( type ) )
return F_22 ( type ) ;
V_17 = type -> V_36 ( V_30 -> V_35 ,
V_30 -> V_37 & ~ V_25 ,
V_30 -> V_38 & ~ V_25 ) ;
if ( F_21 ( V_17 ) ) {
F_16 ( type -> V_7 ) ;
return F_22 ( V_17 ) ;
}
F_24 ( V_21 ) ;
F_25 ( V_28 -> type , type ) ;
F_25 ( V_28 -> V_17 , V_17 ) ;
F_26 ( V_21 ) ;
F_15 ( type , V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 , char T_2 * V_39 ,
unsigned int V_40 )
{
struct V_27 * V_28 = F_20 ( V_21 ) ;
const struct V_1 * type = V_28 -> type ;
T_3 * V_41 ;
int V_8 ;
V_41 = F_28 ( V_21 , V_40 , V_11 ) ;
if ( ! V_41 )
return - V_12 ;
V_8 = - V_42 ;
if ( F_29 ( V_41 , V_39 , V_40 ) )
goto V_43;
V_8 = type -> V_44 ( V_28 -> V_17 , V_41 , V_40 ) ;
V_43:
F_30 ( V_21 , V_41 , V_40 ) ;
return V_8 ;
}
static int F_31 ( struct V_19 * V_20 , int V_45 , int V_46 ,
char T_2 * V_47 , unsigned int V_48 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
struct V_27 * V_28 = F_20 ( V_21 ) ;
const struct V_1 * type ;
int V_8 = - V_49 ;
F_24 ( V_21 ) ;
type = V_28 -> type ;
if ( V_45 != V_50 || ! type )
goto V_10;
switch ( V_46 ) {
case V_51 :
if ( V_20 -> V_31 == V_32 )
goto V_10;
if ( ! type -> V_44 )
goto V_10;
V_8 = F_27 ( V_21 , V_47 , V_48 ) ;
break;
case V_52 :
if ( V_20 -> V_31 == V_32 )
goto V_10;
if ( ! type -> V_53 )
goto V_10;
V_8 = type -> V_53 ( V_28 -> V_17 , V_48 ) ;
}
V_10:
F_26 ( V_21 ) ;
return V_8 ;
}
int F_32 ( struct V_20 * V_21 , struct V_19 * V_54 )
{
struct V_27 * V_28 = F_20 ( V_21 ) ;
const struct V_1 * type ;
struct V_20 * V_55 ;
int V_8 ;
F_24 ( V_21 ) ;
type = V_28 -> type ;
V_8 = - V_33 ;
if ( ! type )
goto V_10;
V_55 = F_33 ( F_34 ( V_21 ) , V_56 , V_11 , & V_57 , 0 ) ;
V_8 = - V_12 ;
if ( ! V_55 )
goto V_10;
F_35 ( V_54 , V_55 ) ;
F_36 ( V_55 , V_54 ) ;
F_37 ( V_21 , V_55 ) ;
V_8 = type -> V_58 ( V_28 -> V_17 , V_55 ) ;
if ( V_8 ) {
F_38 ( V_55 ) ;
goto V_10;
}
V_55 -> V_59 = V_56 ;
F_39 ( V_21 ) ;
F_20 ( V_55 ) -> V_60 = V_21 ;
F_20 ( V_55 ) -> type = type ;
V_54 -> V_13 = type -> V_13 ;
V_54 -> V_31 = V_32 ;
V_8 = 0 ;
V_10:
F_26 ( V_21 ) ;
return V_8 ;
}
static int F_40 ( struct V_19 * V_20 , struct V_19 * V_54 , int V_61 )
{
return F_32 ( V_20 -> V_21 , V_54 ) ;
}
static void F_41 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = F_20 ( V_21 ) ;
F_15 ( V_28 -> type , V_28 -> V_17 ) ;
}
static int F_42 ( struct V_62 * V_62 , struct V_19 * V_20 , int V_63 ,
int V_64 )
{
struct V_20 * V_21 ;
int V_8 ;
if ( V_20 -> type != V_65 )
return - V_66 ;
if ( V_63 != 0 )
return - V_67 ;
V_8 = - V_12 ;
V_21 = F_33 ( V_62 , V_56 , V_11 , & V_57 , V_64 ) ;
if ( ! V_21 )
goto V_43;
V_20 -> V_13 = & V_68 ;
F_35 ( V_20 , V_21 ) ;
V_21 -> V_59 = V_56 ;
V_21 -> V_69 = F_41 ;
return 0 ;
V_43:
return V_8 ;
}
int F_43 ( struct V_70 * V_71 , struct V_72 * V_73 , int V_74 )
{
T_4 V_75 ;
T_5 V_76 ;
int V_77 , V_78 ;
V_76 = F_44 ( V_73 , V_71 -> V_79 , V_74 , V_80 , & V_75 ) ;
if ( V_76 < 0 )
return V_76 ;
V_77 = ( V_75 + V_76 + V_81 - 1 ) >> V_82 ;
if ( F_45 ( V_77 == 0 ) )
return - V_33 ;
F_46 ( V_71 -> V_83 , V_77 + 1 ) ;
for ( V_78 = 0 , V_74 = V_76 ; V_78 < V_77 ; V_78 ++ ) {
int V_84 = F_47 ( int , V_74 , V_81 - V_75 ) ;
F_48 ( V_71 -> V_83 + V_78 , V_71 -> V_79 [ V_78 ] , V_84 , V_75 ) ;
V_75 = 0 ;
V_74 -= V_84 ;
}
F_49 ( V_71 -> V_83 + V_77 - 1 ) ;
V_71 -> V_77 = V_77 ;
return V_76 ;
}
void F_50 ( struct V_70 * V_85 , struct V_70 * V_86 )
{
F_51 ( V_85 -> V_83 + V_85 -> V_77 - 1 ) ;
F_52 ( V_85 -> V_83 , V_85 -> V_77 + 1 , V_86 -> V_83 ) ;
}
void F_53 ( struct V_70 * V_71 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_71 -> V_77 ; V_78 ++ )
F_54 ( V_71 -> V_79 [ V_78 ] ) ;
}
int F_55 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
struct V_91 * V_92 ;
F_56 (cmsg, msg) {
if ( ! F_57 ( V_88 , V_92 ) )
return - V_33 ;
if ( V_92 -> V_93 != V_50 )
continue;
switch ( V_92 -> V_94 ) {
case V_95 :
if ( V_92 -> V_96 < F_58 ( sizeof( * V_90 -> V_97 ) ) )
return - V_33 ;
V_90 -> V_97 = ( void * ) F_59 ( V_92 ) ;
if ( V_92 -> V_96 < F_58 ( V_90 -> V_97 -> V_98 +
sizeof( * V_90 -> V_97 ) ) )
return - V_33 ;
break;
case V_99 :
if ( V_92 -> V_96 < F_58 ( sizeof( T_1 ) ) )
return - V_33 ;
V_90 -> V_100 = * ( T_1 * ) F_59 ( V_92 ) ;
break;
case V_101 :
if ( V_92 -> V_96 < F_58 ( sizeof( T_1 ) ) )
return - V_33 ;
V_90 -> V_102 = * ( T_1 * ) F_59 ( V_92 ) ;
break;
default:
return - V_33 ;
}
}
return 0 ;
}
int F_60 ( int V_8 , struct V_103 * V_104 )
{
switch ( V_8 ) {
case - V_105 :
case - V_106 :
F_61 ( & V_104 -> V_104 ) ;
F_62 ( & V_104 -> V_104 ) ;
V_8 = V_104 -> V_8 ;
break;
} ;
return V_8 ;
}
void F_63 ( struct V_107 * V_108 , int V_8 )
{
struct V_103 * V_104 = V_108 -> V_109 ;
if ( V_8 == - V_105 )
return;
V_104 -> V_8 = V_8 ;
F_64 ( & V_104 -> V_104 ) ;
}
static int T_6 F_65 ( void )
{
int V_8 = F_66 ( & V_57 , 0 ) ;
if ( V_8 )
goto V_43;
V_8 = F_67 ( & V_110 ) ;
if ( V_8 != 0 )
goto V_111;
V_43:
return V_8 ;
V_111:
F_68 ( & V_57 ) ;
goto V_43;
}
static void T_7 F_69 ( void )
{
F_70 ( V_56 ) ;
F_68 ( & V_57 ) ;
}
