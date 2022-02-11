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
}
V_10:
F_26 ( V_21 ) ;
return V_8 ;
}
int F_32 ( struct V_20 * V_21 , struct V_19 * V_50 )
{
struct V_25 * V_26 = F_20 ( V_21 ) ;
const struct V_1 * type ;
struct V_20 * V_51 ;
int V_8 ;
F_24 ( V_21 ) ;
type = V_26 -> type ;
V_8 = - V_31 ;
if ( ! type )
goto V_10;
V_51 = F_33 ( F_34 ( V_21 ) , V_52 , V_11 , & V_53 ) ;
V_8 = - V_12 ;
if ( ! V_51 )
goto V_10;
F_35 ( V_50 , V_51 ) ;
F_36 ( V_51 , V_50 ) ;
F_37 ( V_21 , V_51 ) ;
V_8 = type -> V_54 ( V_26 -> V_17 , V_51 ) ;
if ( V_8 ) {
F_38 ( V_51 ) ;
goto V_10;
}
V_51 -> V_55 = V_52 ;
F_39 ( V_21 ) ;
F_20 ( V_51 ) -> V_56 = V_21 ;
F_20 ( V_51 ) -> type = type ;
V_50 -> V_13 = type -> V_13 ;
V_50 -> V_29 = V_30 ;
V_8 = 0 ;
V_10:
F_26 ( V_21 ) ;
return V_8 ;
}
static int F_40 ( struct V_19 * V_20 , struct V_19 * V_50 , int V_57 )
{
return F_32 ( V_20 -> V_21 , V_50 ) ;
}
static void F_41 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = F_20 ( V_21 ) ;
F_15 ( V_26 -> type , V_26 -> V_17 ) ;
}
static int F_42 ( struct V_58 * V_58 , struct V_19 * V_20 , int V_59 ,
int V_60 )
{
struct V_20 * V_21 ;
int V_8 ;
if ( V_20 -> type != V_61 )
return - V_62 ;
if ( V_59 != 0 )
return - V_63 ;
V_8 = - V_12 ;
V_21 = F_33 ( V_58 , V_52 , V_11 , & V_53 ) ;
if ( ! V_21 )
goto V_41;
V_20 -> V_13 = & V_64 ;
F_35 ( V_20 , V_21 ) ;
V_21 -> V_55 = V_52 ;
V_21 -> V_65 = F_41 ;
return 0 ;
V_41:
return V_8 ;
}
int F_43 ( struct V_66 * V_67 , void T_1 * V_68 , int V_69 ,
int V_70 )
{
unsigned long V_71 = ( unsigned long ) V_68 ;
unsigned long V_72 ;
unsigned V_73 ;
int V_8 ;
int V_74 ;
V_8 = - V_40 ;
if ( ! F_44 ( V_70 ? V_75 : V_76 , V_68 , V_69 ) )
goto V_41;
V_73 = V_71 & ~ V_77 ;
V_72 = ( V_73 + V_69 + V_78 - 1 ) >> V_79 ;
if ( V_72 > V_80 )
V_72 = V_80 ;
V_8 = F_45 ( V_71 , V_72 , V_70 , V_67 -> V_81 ) ;
if ( V_8 < 0 )
goto V_41;
V_72 = V_8 ;
V_8 = - V_31 ;
if ( F_46 ( V_72 == 0 ) )
goto V_41;
V_8 = 0 ;
F_47 ( V_67 -> V_82 , V_72 ) ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
int V_83 = F_48 ( int , V_69 , V_78 - V_73 ) ;
F_49 ( V_67 -> V_82 + V_74 , V_67 -> V_81 [ V_74 ] , V_83 , V_73 ) ;
V_73 = 0 ;
V_69 -= V_83 ;
V_8 += V_83 ;
}
V_41:
return V_8 ;
}
void F_50 ( struct V_66 * V_67 )
{
int V_74 ;
V_74 = 0 ;
do {
F_51 ( V_67 -> V_81 [ V_74 ] ) ;
} while ( ! F_52 ( V_67 -> V_82 + ( V_74 ++ ) ) );
}
int F_53 ( struct V_84 * V_85 , struct V_86 * V_87 )
{
struct V_88 * V_89 ;
for ( V_89 = F_54 ( V_85 ) ; V_89 ; V_89 = F_55 ( V_85 , V_89 ) ) {
if ( ! F_56 ( V_85 , V_89 ) )
return - V_31 ;
if ( V_89 -> V_90 != V_48 )
continue;
switch( V_89 -> V_91 ) {
case V_92 :
if ( V_89 -> V_93 < F_57 ( sizeof( * V_87 -> V_94 ) ) )
return - V_31 ;
V_87 -> V_94 = ( void * ) F_58 ( V_89 ) ;
if ( V_89 -> V_93 < F_57 ( V_87 -> V_94 -> V_95 +
sizeof( * V_87 -> V_94 ) ) )
return - V_31 ;
break;
case V_96 :
if ( V_89 -> V_93 < F_57 ( sizeof( V_97 ) ) )
return - V_31 ;
V_87 -> V_98 = * ( V_97 * ) F_58 ( V_89 ) ;
break;
default:
return - V_31 ;
}
}
return 0 ;
}
int F_59 ( int V_8 , struct V_99 * V_100 )
{
switch ( V_8 ) {
case - V_101 :
case - V_102 :
F_60 ( & V_100 -> V_100 ) ;
F_61 ( & V_100 -> V_100 ) ;
V_8 = V_100 -> V_8 ;
break;
} ;
return V_8 ;
}
void F_62 ( struct V_103 * V_104 , int V_8 )
{
struct V_99 * V_100 = V_104 -> V_105 ;
V_100 -> V_8 = V_8 ;
F_63 ( & V_100 -> V_100 ) ;
}
static int T_3 F_64 ( void )
{
int V_8 = F_65 ( & V_53 , 0 ) ;
if ( V_8 )
goto V_41;
V_8 = F_66 ( & V_106 ) ;
if ( V_8 != 0 )
goto V_107;
V_41:
return V_8 ;
V_107:
F_67 ( & V_53 ) ;
goto V_41;
}
static void T_4 F_68 ( void )
{
F_69 ( V_52 ) ;
F_67 ( & V_53 ) ;
}
