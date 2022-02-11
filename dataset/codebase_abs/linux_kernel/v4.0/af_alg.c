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
struct V_20 * V_21 = V_20 -> V_21 ;
struct V_25 * V_26 = F_20 ( V_21 ) ;
struct V_27 * V_28 = ( void * ) V_23 ;
const struct V_1 * type ;
void * V_17 ;
if ( V_20 -> V_29 == V_30 )
return - V_31 ;
if ( V_24 != sizeof( * V_28 ) )
return - V_31 ;
V_28 -> V_32 [ sizeof( V_28 -> V_32 ) - 1 ] = 0 ;
V_28 -> V_33 [ sizeof( V_28 -> V_33 ) - 1 ] = 0 ;
type = F_1 ( V_28 -> V_32 ) ;
if ( F_21 ( type ) && F_22 ( type ) == - V_3 ) {
F_23 ( L_1 , V_28 -> V_32 ) ;
type = F_1 ( V_28 -> V_32 ) ;
}
if ( F_21 ( type ) )
return F_22 ( type ) ;
V_17 = type -> V_34 ( V_28 -> V_33 , V_28 -> V_35 , V_28 -> V_36 ) ;
if ( F_21 ( V_17 ) ) {
F_16 ( type -> V_7 ) ;
return F_22 ( V_17 ) ;
}
F_24 ( V_21 ) ;
F_25 ( V_26 -> type , type ) ;
F_25 ( V_26 -> V_17 , V_17 ) ;
F_26 ( V_21 ) ;
F_15 ( type , V_17 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 , char T_1 * V_37 ,
unsigned int V_38 )
{
struct V_25 * V_26 = F_20 ( V_21 ) ;
const struct V_1 * type = V_26 -> type ;
T_2 * V_39 ;
int V_8 ;
V_39 = F_28 ( V_21 , V_38 , V_11 ) ;
if ( ! V_39 )
return - V_12 ;
V_8 = - V_40 ;
if ( F_29 ( V_39 , V_37 , V_38 ) )
goto V_41;
V_8 = type -> V_42 ( V_26 -> V_17 , V_39 , V_38 ) ;
V_41:
F_30 ( V_21 , V_39 , V_38 ) ;
return V_8 ;
}
static int F_31 ( struct V_19 * V_20 , int V_43 , int V_44 ,
char T_1 * V_45 , unsigned int V_46 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
struct V_25 * V_26 = F_20 ( V_21 ) ;
const struct V_1 * type ;
int V_8 = - V_47 ;
F_24 ( V_21 ) ;
type = V_26 -> type ;
if ( V_43 != V_48 || ! type )
goto V_10;
switch ( V_44 ) {
case V_49 :
if ( V_20 -> V_29 == V_30 )
goto V_10;
if ( ! type -> V_42 )
goto V_10;
V_8 = F_27 ( V_21 , V_45 , V_46 ) ;
break;
case V_50 :
if ( V_20 -> V_29 == V_30 )
goto V_10;
if ( ! type -> V_51 )
goto V_10;
V_8 = type -> V_51 ( V_26 -> V_17 , V_46 ) ;
}
V_10:
F_26 ( V_21 ) ;
return V_8 ;
}
int F_32 ( struct V_20 * V_21 , struct V_19 * V_52 )
{
struct V_25 * V_26 = F_20 ( V_21 ) ;
const struct V_1 * type ;
struct V_20 * V_53 ;
int V_8 ;
F_24 ( V_21 ) ;
type = V_26 -> type ;
V_8 = - V_31 ;
if ( ! type )
goto V_10;
V_53 = F_33 ( F_34 ( V_21 ) , V_54 , V_11 , & V_55 ) ;
V_8 = - V_12 ;
if ( ! V_53 )
goto V_10;
F_35 ( V_52 , V_53 ) ;
F_36 ( V_53 , V_52 ) ;
F_37 ( V_21 , V_53 ) ;
V_8 = type -> V_56 ( V_26 -> V_17 , V_53 ) ;
if ( V_8 ) {
F_38 ( V_53 ) ;
goto V_10;
}
V_53 -> V_57 = V_54 ;
F_39 ( V_21 ) ;
F_20 ( V_53 ) -> V_58 = V_21 ;
F_20 ( V_53 ) -> type = type ;
V_52 -> V_13 = type -> V_13 ;
V_52 -> V_29 = V_30 ;
V_8 = 0 ;
V_10:
F_26 ( V_21 ) ;
return V_8 ;
}
static int F_40 ( struct V_19 * V_20 , struct V_19 * V_52 , int V_59 )
{
return F_32 ( V_20 -> V_21 , V_52 ) ;
}
static void F_41 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = F_20 ( V_21 ) ;
F_15 ( V_26 -> type , V_26 -> V_17 ) ;
}
static int F_42 ( struct V_60 * V_60 , struct V_19 * V_20 , int V_61 ,
int V_62 )
{
struct V_20 * V_21 ;
int V_8 ;
if ( V_20 -> type != V_63 )
return - V_64 ;
if ( V_61 != 0 )
return - V_65 ;
V_8 = - V_12 ;
V_21 = F_33 ( V_60 , V_54 , V_11 , & V_55 ) ;
if ( ! V_21 )
goto V_41;
V_20 -> V_13 = & V_66 ;
F_35 ( V_20 , V_21 ) ;
V_21 -> V_57 = V_54 ;
V_21 -> V_67 = F_41 ;
return 0 ;
V_41:
return V_8 ;
}
int F_43 ( struct V_68 * V_69 , struct V_70 * V_71 , int V_72 )
{
T_3 V_73 ;
T_4 V_74 ;
int V_75 , V_76 ;
V_74 = F_44 ( V_71 , V_69 -> V_77 , V_72 , V_78 , & V_73 ) ;
if ( V_74 < 0 )
return V_74 ;
V_75 = ( V_73 + V_74 + V_79 - 1 ) >> V_80 ;
if ( F_45 ( V_75 == 0 ) )
return - V_31 ;
F_46 ( V_69 -> V_81 , V_75 ) ;
for ( V_76 = 0 , V_72 = V_74 ; V_76 < V_75 ; V_76 ++ ) {
int V_82 = F_47 ( int , V_72 , V_79 - V_73 ) ;
F_48 ( V_69 -> V_81 + V_76 , V_69 -> V_77 [ V_76 ] , V_82 , V_73 ) ;
V_73 = 0 ;
V_72 -= V_82 ;
}
return V_74 ;
}
void F_49 ( struct V_68 * V_69 )
{
int V_76 ;
V_76 = 0 ;
do {
F_50 ( V_69 -> V_77 [ V_76 ] ) ;
} while ( ! F_51 ( V_69 -> V_81 + ( V_76 ++ ) ) );
}
int F_52 ( struct V_83 * V_84 , struct V_85 * V_86 )
{
struct V_87 * V_88 ;
F_53 (cmsg, msg) {
if ( ! F_54 ( V_84 , V_88 ) )
return - V_31 ;
if ( V_88 -> V_89 != V_48 )
continue;
switch ( V_88 -> V_90 ) {
case V_91 :
if ( V_88 -> V_92 < F_55 ( sizeof( * V_86 -> V_93 ) ) )
return - V_31 ;
V_86 -> V_93 = ( void * ) F_56 ( V_88 ) ;
if ( V_88 -> V_92 < F_55 ( V_86 -> V_93 -> V_94 +
sizeof( * V_86 -> V_93 ) ) )
return - V_31 ;
break;
case V_95 :
if ( V_88 -> V_92 < F_55 ( sizeof( V_96 ) ) )
return - V_31 ;
V_86 -> V_97 = * ( V_96 * ) F_56 ( V_88 ) ;
break;
case V_98 :
if ( V_88 -> V_92 < F_55 ( sizeof( V_96 ) ) )
return - V_31 ;
V_86 -> V_99 = * ( V_96 * ) F_56 ( V_88 ) ;
break;
default:
return - V_31 ;
}
}
return 0 ;
}
int F_57 ( int V_8 , struct V_100 * V_101 )
{
switch ( V_8 ) {
case - V_102 :
case - V_103 :
F_58 ( & V_101 -> V_101 ) ;
F_59 ( & V_101 -> V_101 ) ;
V_8 = V_101 -> V_8 ;
break;
} ;
return V_8 ;
}
void F_60 ( struct V_104 * V_105 , int V_8 )
{
struct V_100 * V_101 = V_105 -> V_106 ;
if ( V_8 == - V_102 )
return;
V_101 -> V_8 = V_8 ;
F_61 ( & V_101 -> V_101 ) ;
}
static int T_5 F_62 ( void )
{
int V_8 = F_63 ( & V_55 , 0 ) ;
if ( V_8 )
goto V_41;
V_8 = F_64 ( & V_107 ) ;
if ( V_8 != 0 )
goto V_108;
V_41:
return V_8 ;
V_108:
F_65 ( & V_55 ) ;
goto V_41;
}
static void T_6 F_66 ( void )
{
F_67 ( V_54 ) ;
F_65 ( & V_55 ) ;
}
