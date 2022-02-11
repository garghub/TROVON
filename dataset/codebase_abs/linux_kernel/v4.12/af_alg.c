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
if ( type -> V_15 )
type -> V_15 -> V_7 = V_14 ;
V_5 -> type = type ;
F_10 ( & V_5 -> V_16 , & V_17 ) ;
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
F_13 ( & V_5 -> V_16 ) ;
F_14 ( V_5 ) ;
V_8 = 0 ;
break;
}
F_11 ( & V_6 ) ;
return V_8 ;
}
static void F_15 ( const struct V_1 * type , void * V_18 )
{
if ( ! type )
return;
type -> V_19 ( V_18 ) ;
F_16 ( type -> V_7 ) ;
}
int F_17 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 )
F_18 ( V_21 -> V_22 ) ;
return 0 ;
}
void F_19 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
unsigned int V_25 = V_24 -> V_26 ;
bool V_27 = V_25 && ! V_24 -> V_28 ;
V_22 = V_24 -> V_29 ;
V_24 = F_20 ( V_22 ) ;
F_21 ( V_22 ) ;
V_24 -> V_26 -= V_25 ;
if ( ! V_27 )
V_27 = ! -- V_24 -> V_28 ;
F_22 ( V_22 ) ;
if ( V_27 )
F_18 ( V_22 ) ;
}
static int F_23 ( struct V_20 * V_21 , struct V_30 * V_31 , int V_32 )
{
const T_1 V_33 = V_34 ;
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
struct V_35 * V_36 = ( void * ) V_31 ;
const struct V_1 * type ;
void * V_18 ;
int V_8 ;
if ( V_21 -> V_37 == V_38 )
return - V_39 ;
if ( V_32 < sizeof( * V_36 ) )
return - V_39 ;
V_36 -> V_40 [ sizeof( V_36 -> V_40 ) - 1 ] = 0 ;
V_36 -> V_41 [ sizeof( V_36 -> V_41 ) + V_32 - sizeof( * V_36 ) - 1 ] = 0 ;
type = F_1 ( V_36 -> V_40 ) ;
if ( F_24 ( type ) && F_25 ( type ) == - V_3 ) {
F_26 ( L_1 , V_36 -> V_40 ) ;
type = F_1 ( V_36 -> V_40 ) ;
}
if ( F_24 ( type ) )
return F_25 ( type ) ;
V_18 = type -> V_42 ( V_36 -> V_41 ,
V_36 -> V_43 & ~ V_33 ,
V_36 -> V_44 & ~ V_33 ) ;
if ( F_24 ( V_18 ) ) {
F_16 ( type -> V_7 ) ;
return F_25 ( V_18 ) ;
}
V_8 = - V_45 ;
F_21 ( V_22 ) ;
if ( V_24 -> V_28 | V_24 -> V_26 )
goto V_10;
F_27 ( V_24 -> type , type ) ;
F_27 ( V_24 -> V_18 , V_18 ) ;
V_8 = 0 ;
V_10:
F_22 ( V_22 ) ;
F_15 ( type , V_18 ) ;
return V_8 ;
}
static int F_28 ( struct V_21 * V_22 , char T_2 * V_46 ,
unsigned int V_47 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
const struct V_1 * type = V_24 -> type ;
T_3 * V_48 ;
int V_8 ;
V_48 = F_29 ( V_22 , V_47 , V_11 ) ;
if ( ! V_48 )
return - V_12 ;
V_8 = - V_49 ;
if ( F_30 ( V_48 , V_46 , V_47 ) )
goto V_50;
V_8 = type -> V_51 ( V_24 -> V_18 , V_48 , V_47 ) ;
V_50:
F_31 ( V_22 , V_48 , V_47 ) ;
return V_8 ;
}
static int F_32 ( struct V_20 * V_21 , int V_52 , int V_53 ,
char T_2 * V_54 , unsigned int V_55 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
struct V_23 * V_24 = F_20 ( V_22 ) ;
const struct V_1 * type ;
int V_8 = - V_45 ;
F_21 ( V_22 ) ;
if ( V_24 -> V_28 )
goto V_10;
type = V_24 -> type ;
V_8 = - V_56 ;
if ( V_52 != V_57 || ! type )
goto V_10;
switch ( V_53 ) {
case V_58 :
if ( V_21 -> V_37 == V_38 )
goto V_10;
if ( ! type -> V_51 )
goto V_10;
V_8 = F_28 ( V_22 , V_54 , V_55 ) ;
break;
case V_59 :
if ( V_21 -> V_37 == V_38 )
goto V_10;
if ( ! type -> V_60 )
goto V_10;
V_8 = type -> V_60 ( V_24 -> V_18 , V_55 ) ;
}
V_10:
F_22 ( V_22 ) ;
return V_8 ;
}
int F_33 ( struct V_21 * V_22 , struct V_20 * V_61 , bool V_62 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
const struct V_1 * type ;
struct V_21 * V_63 ;
unsigned int V_25 ;
int V_8 ;
F_21 ( V_22 ) ;
type = V_24 -> type ;
V_8 = - V_39 ;
if ( ! type )
goto V_10;
V_63 = F_34 ( F_35 ( V_22 ) , V_64 , V_11 , & V_65 , V_62 ) ;
V_8 = - V_12 ;
if ( ! V_63 )
goto V_10;
F_36 ( V_61 , V_63 ) ;
F_37 ( V_63 , V_61 ) ;
F_38 ( V_22 , V_63 ) ;
V_8 = type -> V_66 ( V_24 -> V_18 , V_63 ) ;
V_25 = V_8 == - V_67 ;
if ( V_25 && type -> V_68 )
V_8 = type -> V_68 ( V_24 -> V_18 , V_63 ) ;
if ( V_8 )
goto V_10;
V_63 -> V_69 = V_64 ;
if ( V_25 || ! V_24 -> V_28 ++ )
F_39 ( V_22 ) ;
V_24 -> V_26 += V_25 ;
F_20 ( V_63 ) -> V_29 = V_22 ;
F_20 ( V_63 ) -> type = type ;
F_20 ( V_63 ) -> V_26 = V_25 ;
V_61 -> V_13 = type -> V_13 ;
V_61 -> V_37 = V_38 ;
if ( V_25 )
V_61 -> V_13 = type -> V_15 ;
V_8 = 0 ;
V_10:
F_22 ( V_22 ) ;
return V_8 ;
}
static int F_40 ( struct V_20 * V_21 , struct V_20 * V_61 , int V_70 ,
bool V_62 )
{
return F_33 ( V_21 -> V_22 , V_61 , V_62 ) ;
}
static void F_41 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_20 ( V_22 ) ;
F_15 ( V_24 -> type , V_24 -> V_18 ) ;
}
static int F_42 ( struct V_71 * V_71 , struct V_20 * V_21 , int V_72 ,
int V_62 )
{
struct V_21 * V_22 ;
int V_8 ;
if ( V_21 -> type != V_73 )
return - V_74 ;
if ( V_72 != 0 )
return - V_75 ;
V_8 = - V_12 ;
V_22 = F_34 ( V_71 , V_64 , V_11 , & V_65 , V_62 ) ;
if ( ! V_22 )
goto V_50;
V_21 -> V_13 = & V_76 ;
F_36 ( V_21 , V_22 ) ;
V_22 -> V_69 = V_64 ;
V_22 -> V_77 = F_41 ;
return 0 ;
V_50:
return V_8 ;
}
int F_43 ( struct V_78 * V_79 , struct V_80 * V_81 , int V_82 )
{
T_4 V_83 ;
T_5 V_84 ;
int V_85 , V_86 ;
V_84 = F_44 ( V_81 , V_79 -> V_87 , V_82 , V_88 , & V_83 ) ;
if ( V_84 < 0 )
return V_84 ;
V_85 = ( V_83 + V_84 + V_89 - 1 ) >> V_90 ;
if ( F_45 ( V_85 == 0 ) )
return - V_39 ;
F_46 ( V_79 -> V_91 , V_85 + 1 ) ;
for ( V_86 = 0 , V_82 = V_84 ; V_86 < V_85 ; V_86 ++ ) {
int V_92 = F_47 ( int , V_82 , V_89 - V_83 ) ;
F_48 ( V_79 -> V_91 + V_86 , V_79 -> V_87 [ V_86 ] , V_92 , V_83 ) ;
V_83 = 0 ;
V_82 -= V_92 ;
}
F_49 ( V_79 -> V_91 + V_85 - 1 ) ;
V_79 -> V_85 = V_85 ;
return V_84 ;
}
void F_50 ( struct V_78 * V_93 , struct V_78 * V_94 )
{
F_51 ( V_93 -> V_91 + V_93 -> V_85 - 1 ) ;
F_52 ( V_93 -> V_91 , V_93 -> V_85 + 1 , V_94 -> V_91 ) ;
}
void F_53 ( struct V_78 * V_79 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_79 -> V_85 ; V_86 ++ )
F_54 ( V_79 -> V_87 [ V_86 ] ) ;
}
int F_55 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_99 * V_100 ;
F_56 (cmsg, msg) {
if ( ! F_57 ( V_96 , V_100 ) )
return - V_39 ;
if ( V_100 -> V_101 != V_57 )
continue;
switch ( V_100 -> V_102 ) {
case V_103 :
if ( V_100 -> V_104 < F_58 ( sizeof( * V_98 -> V_105 ) ) )
return - V_39 ;
V_98 -> V_105 = ( void * ) F_59 ( V_100 ) ;
if ( V_100 -> V_104 < F_58 ( V_98 -> V_105 -> V_106 +
sizeof( * V_98 -> V_105 ) ) )
return - V_39 ;
break;
case V_107 :
if ( V_100 -> V_104 < F_58 ( sizeof( T_1 ) ) )
return - V_39 ;
V_98 -> V_108 = * ( T_1 * ) F_59 ( V_100 ) ;
break;
case V_109 :
if ( V_100 -> V_104 < F_58 ( sizeof( T_1 ) ) )
return - V_39 ;
V_98 -> V_110 = * ( T_1 * ) F_59 ( V_100 ) ;
break;
default:
return - V_39 ;
}
}
return 0 ;
}
int F_60 ( int V_8 , struct V_111 * V_112 )
{
switch ( V_8 ) {
case - V_113 :
case - V_45 :
F_61 ( & V_112 -> V_112 ) ;
F_62 ( & V_112 -> V_112 ) ;
V_8 = V_112 -> V_8 ;
break;
} ;
return V_8 ;
}
void F_63 ( struct V_114 * V_115 , int V_8 )
{
struct V_111 * V_112 = V_115 -> V_116 ;
if ( V_8 == - V_113 )
return;
V_112 -> V_8 = V_8 ;
F_64 ( & V_112 -> V_112 ) ;
}
static int T_6 F_65 ( void )
{
int V_8 = F_66 ( & V_65 , 0 ) ;
if ( V_8 )
goto V_50;
V_8 = F_67 ( & V_117 ) ;
if ( V_8 != 0 )
goto V_118;
V_50:
return V_8 ;
V_118:
F_68 ( & V_65 ) ;
goto V_50;
}
static void T_7 F_69 ( void )
{
F_70 ( V_64 ) ;
F_68 ( & V_65 ) ;
}
