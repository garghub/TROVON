static int F_1 ( struct V_1 * V_1 , int * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 = 0 ;
F_2 (net, dev) {
if ( V_6 >= V_3 )
break;
if ( V_5 -> V_7 & V_8 )
V_2 [ V_6 ++ ] = V_5 -> V_9 ;
}
return V_6 ;
}
static void F_3 ( struct V_10 * V_11 , int * V_12 , int V_3 )
{
struct V_13 * V_14 ;
F_4 (p, &br->port_list, list) {
if ( V_14 -> V_15 < V_3 )
V_12 [ V_14 -> V_15 ] = V_14 -> V_5 -> V_9 ;
}
}
static int F_5 ( struct V_10 * V_11 , void T_1 * V_16 ,
unsigned long V_17 , unsigned long V_18 )
{
int V_3 ;
void * V_19 ;
T_2 V_20 ;
if ( V_17 > V_21 / sizeof( struct V_22 ) )
V_17 = V_21 / sizeof( struct V_22 ) ;
V_20 = V_17 * sizeof( struct V_22 ) ;
V_19 = F_6 ( V_20 , V_23 ) ;
if ( ! V_19 )
return - V_24 ;
V_3 = F_7 ( V_11 , V_19 , V_17 , V_18 ) ;
if ( V_3 > 0 ) {
if ( F_8 ( V_16 , V_19 , V_3 * sizeof( struct V_22 ) ) )
V_3 = - V_25 ;
}
F_9 ( V_19 ) ;
return V_3 ;
}
static int F_10 ( struct V_10 * V_11 , int V_9 , int V_26 )
{
struct V_4 * V_5 ;
int V_27 ;
if ( ! F_11 ( V_28 ) )
return - V_29 ;
V_5 = F_12 ( F_13 ( V_11 -> V_5 ) , V_9 ) ;
if ( V_5 == NULL )
return - V_30 ;
if ( V_26 )
V_27 = F_14 ( V_11 , V_5 ) ;
else
V_27 = F_15 ( V_11 , V_5 ) ;
return V_27 ;
}
static int F_16 ( struct V_4 * V_5 , struct V_31 * V_32 , int V_33 )
{
struct V_10 * V_11 = F_17 ( V_5 ) ;
unsigned long args [ 4 ] ;
if ( F_18 ( args , V_32 -> V_34 , sizeof( args ) ) )
return - V_25 ;
switch ( args [ 0 ] ) {
case V_35 :
case V_36 :
return F_10 ( V_11 , args [ 1 ] , args [ 0 ] == V_35 ) ;
case V_37 :
{
struct V_38 V_39 ;
memset ( & V_39 , 0 , sizeof( struct V_38 ) ) ;
F_19 () ;
memcpy ( & V_39 . V_40 , & V_11 -> V_40 , 8 ) ;
memcpy ( & V_39 . V_41 , & V_11 -> V_41 , 8 ) ;
V_39 . V_42 = V_11 -> V_42 ;
V_39 . V_43 = F_20 ( V_11 -> V_43 ) ;
V_39 . V_44 = F_20 ( V_11 -> V_44 ) ;
V_39 . V_45 = V_11 -> V_45 ;
V_39 . V_46 = V_11 -> V_46 ;
V_39 . V_47 = V_11 -> V_47 ;
V_39 . V_48 = F_20 ( V_11 -> V_48 ) ;
V_39 . V_49 = V_11 -> V_49 ;
V_39 . V_50 = V_11 -> V_50 ;
V_39 . V_51 = V_11 -> V_51 ;
V_39 . V_52 = ( V_11 -> V_52 != V_53 ) ;
V_39 . V_54 = F_20 ( V_11 -> V_54 ) ;
V_39 . V_55 = F_21 ( & V_11 -> V_56 ) ;
V_39 . V_57 = F_21 ( & V_11 -> V_58 ) ;
V_39 . V_59 = F_21 ( & V_11 -> V_60 ) ;
V_39 . V_61 = F_21 ( & V_11 -> V_62 ) ;
F_22 () ;
if ( F_8 ( ( void T_1 * ) args [ 1 ] , & V_39 , sizeof( V_39 ) ) )
return - V_25 ;
return 0 ;
}
case V_63 :
{
int V_3 , * V_2 ;
V_3 = args [ 2 ] ;
if ( V_3 < 0 )
return - V_30 ;
if ( V_3 == 0 )
V_3 = 256 ;
if ( V_3 > V_64 )
V_3 = V_64 ;
V_2 = F_23 ( V_3 , sizeof( int ) , V_65 ) ;
if ( V_2 == NULL )
return - V_24 ;
F_3 ( V_11 , V_2 , V_3 ) ;
if ( F_8 ( ( void T_1 * ) args [ 1 ] , V_2 , V_3 * sizeof( int ) ) )
V_3 = - V_25 ;
F_9 ( V_2 ) ;
return V_3 ;
}
case V_66 :
if ( ! F_11 ( V_28 ) )
return - V_29 ;
return F_24 ( V_11 , args [ 1 ] ) ;
case V_67 :
if ( ! F_11 ( V_28 ) )
return - V_29 ;
return F_25 ( V_11 , args [ 1 ] ) ;
case V_68 :
if ( ! F_11 ( V_28 ) )
return - V_29 ;
return F_26 ( V_11 , args [ 1 ] ) ;
case V_69 :
if ( ! F_11 ( V_28 ) )
return - V_29 ;
V_11 -> V_54 = F_27 ( args [ 1 ] ) ;
return 0 ;
case V_70 :
{
struct V_71 V_14 ;
struct V_13 * V_72 ;
F_19 () ;
if ( ( V_72 = F_28 ( V_11 , args [ 2 ] ) ) == NULL ) {
F_22 () ;
return - V_30 ;
}
memset ( & V_14 , 0 , sizeof( struct V_71 ) ) ;
memcpy ( & V_14 . V_40 , & V_72 -> V_40 , 8 ) ;
memcpy ( & V_14 . V_73 , & V_72 -> V_73 , 8 ) ;
V_14 . V_74 = V_72 -> V_74 ;
V_14 . V_75 = V_72 -> V_75 ;
V_14 . V_76 = V_72 -> V_76 ;
V_14 . V_77 = V_72 -> V_77 ;
V_14 . V_78 = V_72 -> V_78 ;
V_14 . V_79 = V_72 -> V_80 ;
V_14 . V_81 = V_72 -> V_81 ;
V_14 . V_82 = F_21 ( & V_72 -> V_83 ) ;
V_14 . V_84 = F_21 ( & V_72 -> V_85 ) ;
V_14 . V_86 = F_21 ( & V_72 -> V_87 ) ;
F_22 () ;
if ( F_8 ( ( void T_1 * ) args [ 1 ] , & V_14 , sizeof( V_14 ) ) )
return - V_25 ;
return 0 ;
}
case V_88 :
if ( ! F_11 ( V_28 ) )
return - V_29 ;
F_29 ( V_11 , args [ 1 ] ) ;
return 0 ;
case V_89 :
if ( ! F_11 ( V_28 ) )
return - V_29 ;
F_30 ( & V_11 -> V_90 ) ;
F_31 ( V_11 , args [ 1 ] ) ;
F_32 ( & V_11 -> V_90 ) ;
return 0 ;
case V_91 :
{
struct V_13 * V_14 ;
int V_27 ;
if ( ! F_11 ( V_28 ) )
return - V_29 ;
F_30 ( & V_11 -> V_90 ) ;
if ( ( V_14 = F_28 ( V_11 , args [ 1 ] ) ) == NULL )
V_27 = - V_30 ;
else
V_27 = F_33 ( V_14 , args [ 2 ] ) ;
F_32 ( & V_11 -> V_90 ) ;
return V_27 ;
}
case V_92 :
{
struct V_13 * V_14 ;
int V_27 ;
if ( ! F_11 ( V_28 ) )
return - V_29 ;
F_30 ( & V_11 -> V_90 ) ;
if ( ( V_14 = F_28 ( V_11 , args [ 1 ] ) ) == NULL )
V_27 = - V_30 ;
else
V_27 = F_34 ( V_14 , args [ 2 ] ) ;
F_32 ( & V_11 -> V_90 ) ;
return V_27 ;
}
case V_93 :
return F_5 ( V_11 , ( void T_1 * ) args [ 1 ] ,
args [ 2 ] , args [ 3 ] ) ;
}
return - V_94 ;
}
static int F_35 ( struct V_1 * V_1 , void T_1 * V_95 )
{
unsigned long args [ 3 ] ;
if ( F_18 ( args , V_95 , sizeof( args ) ) )
return - V_25 ;
switch ( args [ 0 ] ) {
case V_96 :
return V_97 ;
case V_98 :
{
int * V_2 ;
int V_27 = 0 ;
if ( args [ 2 ] >= 2048 )
return - V_24 ;
V_2 = F_23 ( args [ 2 ] , sizeof( int ) , V_65 ) ;
if ( V_2 == NULL )
return - V_24 ;
args [ 2 ] = F_1 ( V_1 , V_2 , args [ 2 ] ) ;
V_27 = F_8 ( ( void T_1 * ) args [ 1 ] , V_2 , args [ 2 ] * sizeof( int ) )
? - V_25 : args [ 2 ] ;
F_9 ( V_2 ) ;
return V_27 ;
}
case V_99 :
case V_100 :
{
char V_19 [ V_101 ] ;
if ( ! F_11 ( V_28 ) )
return - V_29 ;
if ( F_18 ( V_19 , ( void T_1 * ) args [ 1 ] , V_101 ) )
return - V_25 ;
V_19 [ V_101 - 1 ] = 0 ;
if ( args [ 0 ] == V_99 )
return F_36 ( V_1 , V_19 ) ;
return F_37 ( V_1 , V_19 ) ;
}
}
return - V_94 ;
}
int F_38 ( struct V_1 * V_1 , unsigned int V_33 , void T_1 * V_95 )
{
switch ( V_33 ) {
case V_102 :
case V_103 :
return F_35 ( V_1 , V_95 ) ;
case V_104 :
case V_105 :
{
char V_19 [ V_101 ] ;
if ( ! F_11 ( V_28 ) )
return - V_29 ;
if ( F_18 ( V_19 , V_95 , V_101 ) )
return - V_25 ;
V_19 [ V_101 - 1 ] = 0 ;
if ( V_33 == V_104 )
return F_36 ( V_1 , V_19 ) ;
return F_37 ( V_1 , V_19 ) ;
}
}
return - V_94 ;
}
int F_39 ( struct V_4 * V_5 , struct V_31 * V_32 , int V_33 )
{
struct V_10 * V_11 = F_17 ( V_5 ) ;
switch( V_33 ) {
case V_106 :
return F_16 ( V_5 , V_32 , V_33 ) ;
case V_107 :
case V_108 :
return F_10 ( V_11 , V_32 -> V_109 , V_33 == V_107 ) ;
}
F_40 ( V_11 , L_1 , V_33 ) ;
return - V_94 ;
}
