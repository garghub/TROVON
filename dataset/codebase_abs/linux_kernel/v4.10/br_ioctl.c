static int F_1 ( struct V_1 * V_1 , int * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 = 0 ;
F_2 () ;
F_3 (net, dev) {
if ( V_6 >= V_3 )
break;
if ( V_5 -> V_7 & V_8 )
V_2 [ V_6 ++ ] = V_5 -> V_9 ;
}
F_4 () ;
return V_6 ;
}
static void F_5 ( struct V_10 * V_11 , int * V_12 , int V_3 )
{
struct V_13 * V_14 ;
F_6 (p, &br->port_list, list) {
if ( V_14 -> V_15 < V_3 )
V_12 [ V_14 -> V_15 ] = V_14 -> V_5 -> V_9 ;
}
}
static int F_7 ( struct V_10 * V_11 , void T_1 * V_16 ,
unsigned long V_17 , unsigned long V_18 )
{
int V_3 ;
void * V_19 ;
T_2 V_20 ;
if ( V_17 > V_21 / sizeof( struct V_22 ) )
V_17 = V_21 / sizeof( struct V_22 ) ;
V_20 = V_17 * sizeof( struct V_22 ) ;
V_19 = F_8 ( V_20 , V_23 ) ;
if ( ! V_19 )
return - V_24 ;
V_3 = F_9 ( V_11 , V_19 , V_17 , V_18 ) ;
if ( V_3 > 0 ) {
if ( F_10 ( V_16 , V_19 , V_3 * sizeof( struct V_22 ) ) )
V_3 = - V_25 ;
}
F_11 ( V_19 ) ;
return V_3 ;
}
static int F_12 ( struct V_10 * V_11 , int V_9 , int V_26 )
{
struct V_1 * V_1 = F_13 ( V_11 -> V_5 ) ;
struct V_4 * V_5 ;
int V_27 ;
if ( ! F_14 ( V_1 -> V_28 , V_29 ) )
return - V_30 ;
V_5 = F_15 ( V_1 , V_9 ) ;
if ( V_5 == NULL )
return - V_31 ;
if ( V_26 )
V_27 = F_16 ( V_11 , V_5 ) ;
else
V_27 = F_17 ( V_11 , V_5 ) ;
return V_27 ;
}
static int F_18 ( struct V_4 * V_5 , struct V_32 * V_33 , int V_34 )
{
struct V_10 * V_11 = F_19 ( V_5 ) ;
struct V_13 * V_14 = NULL ;
unsigned long args [ 4 ] ;
int V_27 = - V_35 ;
if ( F_20 ( args , V_33 -> V_36 , sizeof( args ) ) )
return - V_25 ;
switch ( args [ 0 ] ) {
case V_37 :
case V_38 :
return F_12 ( V_11 , args [ 1 ] , args [ 0 ] == V_37 ) ;
case V_39 :
{
struct V_40 V_41 ;
memset ( & V_41 , 0 , sizeof( struct V_40 ) ) ;
F_2 () ;
memcpy ( & V_41 . V_42 , & V_11 -> V_42 , 8 ) ;
memcpy ( & V_41 . V_43 , & V_11 -> V_43 , 8 ) ;
V_41 . V_44 = V_11 -> V_44 ;
V_41 . V_45 = F_21 ( V_11 -> V_45 ) ;
V_41 . V_46 = F_21 ( V_11 -> V_46 ) ;
V_41 . V_47 = V_11 -> V_47 ;
V_41 . V_48 = V_11 -> V_48 ;
V_41 . V_49 = V_11 -> V_49 ;
V_41 . V_50 = F_21 ( V_11 -> V_50 ) ;
V_41 . V_51 = V_11 -> V_51 ;
V_41 . V_52 = V_11 -> V_52 ;
V_41 . V_53 = V_11 -> V_53 ;
V_41 . V_54 = ( V_11 -> V_54 != V_55 ) ;
V_41 . V_56 = F_21 ( V_11 -> V_56 ) ;
V_41 . V_57 = F_22 ( & V_11 -> V_58 ) ;
V_41 . V_59 = F_22 ( & V_11 -> V_60 ) ;
V_41 . V_61 = F_22 ( & V_11 -> V_62 ) ;
V_41 . V_63 = F_22 ( & V_11 -> V_64 ) ;
F_4 () ;
if ( F_10 ( ( void T_1 * ) args [ 1 ] , & V_41 , sizeof( V_41 ) ) )
return - V_25 ;
return 0 ;
}
case V_65 :
{
int V_3 , * V_2 ;
V_3 = args [ 2 ] ;
if ( V_3 < 0 )
return - V_31 ;
if ( V_3 == 0 )
V_3 = 256 ;
if ( V_3 > V_66 )
V_3 = V_66 ;
V_2 = F_23 ( V_3 , sizeof( int ) , V_67 ) ;
if ( V_2 == NULL )
return - V_24 ;
F_5 ( V_11 , V_2 , V_3 ) ;
if ( F_10 ( ( void T_1 * ) args [ 1 ] , V_2 , V_3 * sizeof( int ) ) )
V_3 = - V_25 ;
F_11 ( V_2 ) ;
return V_3 ;
}
case V_68 :
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
V_27 = F_24 ( V_11 , args [ 1 ] ) ;
break;
case V_69 :
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
V_27 = F_25 ( V_11 , args [ 1 ] ) ;
break;
case V_70 :
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
V_27 = F_26 ( V_11 , args [ 1 ] ) ;
break;
case V_71 :
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
V_27 = F_27 ( V_11 , args [ 1 ] ) ;
break;
case V_72 :
{
struct V_73 V_14 ;
struct V_13 * V_74 ;
F_2 () ;
if ( ( V_74 = F_28 ( V_11 , args [ 2 ] ) ) == NULL ) {
F_4 () ;
return - V_31 ;
}
memset ( & V_14 , 0 , sizeof( struct V_73 ) ) ;
memcpy ( & V_14 . V_42 , & V_74 -> V_42 , 8 ) ;
memcpy ( & V_14 . V_75 , & V_74 -> V_75 , 8 ) ;
V_14 . V_76 = V_74 -> V_76 ;
V_14 . V_77 = V_74 -> V_77 ;
V_14 . V_78 = V_74 -> V_78 ;
V_14 . V_79 = V_74 -> V_79 ;
V_14 . V_80 = V_74 -> V_80 ;
V_14 . V_81 = V_74 -> V_82 ;
V_14 . V_83 = V_74 -> V_83 ;
V_14 . V_84 = F_22 ( & V_74 -> V_85 ) ;
V_14 . V_86 = F_22 ( & V_74 -> V_87 ) ;
V_14 . V_88 = F_22 ( & V_74 -> V_89 ) ;
F_4 () ;
if ( F_10 ( ( void T_1 * ) args [ 1 ] , & V_14 , sizeof( V_14 ) ) )
return - V_25 ;
return 0 ;
}
case V_90 :
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
F_29 ( V_11 , args [ 1 ] ) ;
V_27 = 0 ;
break;
case V_91 :
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
F_30 ( V_11 , args [ 1 ] ) ;
V_27 = 0 ;
break;
case V_92 :
{
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
F_31 ( & V_11 -> V_93 ) ;
if ( ( V_14 = F_28 ( V_11 , args [ 1 ] ) ) == NULL )
V_27 = - V_31 ;
else
V_27 = F_32 ( V_14 , args [ 2 ] ) ;
F_33 ( & V_11 -> V_93 ) ;
break;
}
case V_94 :
{
if ( ! F_14 ( F_13 ( V_5 ) -> V_28 , V_29 ) )
return - V_30 ;
F_31 ( & V_11 -> V_93 ) ;
if ( ( V_14 = F_28 ( V_11 , args [ 1 ] ) ) == NULL )
V_27 = - V_31 ;
else
V_27 = F_34 ( V_14 , args [ 2 ] ) ;
F_33 ( & V_11 -> V_93 ) ;
break;
}
case V_95 :
return F_7 ( V_11 , ( void T_1 * ) args [ 1 ] ,
args [ 2 ] , args [ 3 ] ) ;
}
if ( ! V_27 ) {
if ( V_14 )
F_35 ( V_96 , V_14 ) ;
else
F_36 ( V_11 -> V_5 ) ;
}
return V_27 ;
}
static int F_37 ( struct V_1 * V_1 , void T_1 * V_97 )
{
unsigned long args [ 3 ] ;
if ( F_20 ( args , V_97 , sizeof( args ) ) )
return - V_25 ;
switch ( args [ 0 ] ) {
case V_98 :
return V_99 ;
case V_100 :
{
int * V_2 ;
int V_27 = 0 ;
if ( args [ 2 ] >= 2048 )
return - V_24 ;
V_2 = F_23 ( args [ 2 ] , sizeof( int ) , V_67 ) ;
if ( V_2 == NULL )
return - V_24 ;
args [ 2 ] = F_1 ( V_1 , V_2 , args [ 2 ] ) ;
V_27 = F_10 ( ( void T_1 * ) args [ 1 ] , V_2 , args [ 2 ] * sizeof( int ) )
? - V_25 : args [ 2 ] ;
F_11 ( V_2 ) ;
return V_27 ;
}
case V_101 :
case V_102 :
{
char V_19 [ V_103 ] ;
if ( ! F_14 ( V_1 -> V_28 , V_29 ) )
return - V_30 ;
if ( F_20 ( V_19 , ( void T_1 * ) args [ 1 ] , V_103 ) )
return - V_25 ;
V_19 [ V_103 - 1 ] = 0 ;
if ( args [ 0 ] == V_101 )
return F_38 ( V_1 , V_19 ) ;
return F_39 ( V_1 , V_19 ) ;
}
}
return - V_35 ;
}
int F_40 ( struct V_1 * V_1 , unsigned int V_34 , void T_1 * V_97 )
{
switch ( V_34 ) {
case V_104 :
case V_105 :
return F_37 ( V_1 , V_97 ) ;
case V_106 :
case V_107 :
{
char V_19 [ V_103 ] ;
if ( ! F_14 ( V_1 -> V_28 , V_29 ) )
return - V_30 ;
if ( F_20 ( V_19 , V_97 , V_103 ) )
return - V_25 ;
V_19 [ V_103 - 1 ] = 0 ;
if ( V_34 == V_106 )
return F_38 ( V_1 , V_19 ) ;
return F_39 ( V_1 , V_19 ) ;
}
}
return - V_35 ;
}
int F_41 ( struct V_4 * V_5 , struct V_32 * V_33 , int V_34 )
{
struct V_10 * V_11 = F_19 ( V_5 ) ;
switch ( V_34 ) {
case V_108 :
return F_18 ( V_5 , V_33 , V_34 ) ;
case V_109 :
case V_110 :
return F_12 ( V_11 , V_33 -> V_111 , V_34 == V_109 ) ;
}
F_42 ( V_11 , L_1 , V_34 ) ;
return - V_35 ;
}
