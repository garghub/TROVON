static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_2 ( L_1 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> V_8 , V_5 -> V_9 , V_5 -> V_10 , V_5 -> V_11 ,
V_5 -> V_12 , V_5 -> V_13 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 ;
int V_17 ;
if ( V_15 -> V_18 != 0x4f525851 ) {
F_4 ( L_2 , V_15 -> V_18 ) ;
return false ;
}
F_5 ( L_3 , V_15 -> V_6 , V_15 -> V_19 ) ;
F_5 ( L_4 , V_15 -> V_20 ,
V_15 -> V_21 ) ;
F_5 ( L_5 ,
V_15 -> V_22 , V_15 -> V_23 ) ;
F_5 ( L_6 ,
V_15 -> V_24 , V_15 -> V_25 ) ;
F_5 ( L_7 ,
V_15 -> V_26 , V_15 -> V_27 ) ;
V_2 -> V_28 = V_15 -> V_26 ;
F_5 ( L_8 , V_15 -> V_29 ) ;
V_16 = V_15 -> V_23 / 4 ;
V_2 -> V_30 . V_31 = ( ( V_32 * ) V_15 ) [ V_16 ] ;
F_5 ( L_9 , V_15 -> V_23 ,
V_2 -> V_30 . V_31 ) ;
V_2 -> V_30 . V_33 = ( void * ) ( ( V_34 * ) V_15 + V_16 + 1 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_30 . V_31 ; V_17 ++ )
F_1 ( V_2 , V_2 -> V_30 . V_33 + V_17 ) ;
return true ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_35 ,
unsigned long V_36 , unsigned long V_37 )
{
T_2 V_38 ;
struct V_39 * V_40 ;
T_1 V_41 ;
struct V_42 * V_43 = V_2 -> V_43 ;
V_41 = V_2 -> V_15 -> V_44 + V_35 ;
V_40 = & V_2 -> V_45 [ V_41 ] ;
V_40 -> V_36 = V_36 ;
V_40 -> V_37 = V_37 ;
V_43 -> V_46 . V_47 = V_40 -> V_36 ;
V_43 -> V_46 . V_48 = V_40 -> V_37 ;
F_7 ( V_2 , V_41 ) ;
V_40 -> V_49 = V_2 -> V_15 -> V_50 ;
V_38 = V_41 << V_2 -> V_51 ;
V_38 |= V_40 -> V_49 ;
V_38 <<= ( 64 - ( V_2 -> V_51 + V_2 -> V_52 ) ) ;
V_40 -> V_38 = V_38 ;
return V_41 ;
}
static void F_8 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_9 ( V_54 , struct V_1 , V_55 ) ;
F_10 ( V_2 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_58 * V_59 ,
unsigned long V_60 )
{
int V_61 ;
V_2 -> V_62 = & V_59 -> V_62 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_60 = V_60 ;
F_12 ( & V_2 -> V_63 . V_64 ) ;
F_12 ( & V_2 -> V_65 ) ;
F_12 ( & V_2 -> V_66 ) ;
F_12 ( & V_2 -> V_67 ) ;
F_13 ( & V_2 -> V_63 . V_68 ) ;
V_2 -> V_69 = F_14 ( V_59 , 2 ) ;
V_2 -> V_70 = F_15 ( V_59 , 2 ) ;
V_2 -> V_71 = F_14 ( V_59 , 0 ) ;
V_2 -> V_72 = F_14 ( V_59 , 1 ) ;
V_2 -> V_73 = F_15 ( V_59 , 1 ) ;
V_2 -> V_74 = F_14 ( V_59 , 3 ) ;
V_2 -> V_75 = F_16 ( V_2 -> V_71 , F_15 ( V_59 , 0 ) ) ;
V_2 -> V_76 = F_16 ( V_2 -> V_72 , V_2 -> V_73 ) ;
F_2 ( L_10 ,
( unsigned long long ) V_2 -> V_71 ,
( unsigned long long ) F_17 ( V_59 , 0 ) ,
( int ) F_15 ( V_59 , 0 ) / 1024 / 1024 ,
( int ) F_15 ( V_59 , 0 ) / 1024 ,
( unsigned long long ) V_2 -> V_72 ,
( unsigned long long ) F_17 ( V_59 , 1 ) ,
( int ) V_2 -> V_73 / 1024 / 1024 ,
( int ) V_2 -> V_73 / 1024 ) ;
V_2 -> V_15 = F_18 ( V_2 -> V_69 , V_2 -> V_70 ) ;
if ( ! V_2 -> V_15 ) {
F_19 ( L_11 ) ;
return - V_77 ;
}
F_3 ( V_2 ) ;
V_61 = F_20 ( V_2 ) ;
if ( V_61 ) {
F_4 ( L_12 , V_61 ) ;
return V_61 ;
}
V_2 -> V_43 = F_18 ( V_2 -> V_71 +
V_2 -> V_15 -> V_29 ,
sizeof( * V_2 -> V_43 ) ) ;
V_2 -> V_78 = F_21 ( & ( V_2 -> V_43 -> V_79 ) ,
sizeof( struct V_80 ) ,
V_81 ,
V_2 -> V_74 + V_82 ,
false ,
& V_2 -> V_83 ) ;
V_2 -> V_84 = F_21 (
& ( V_2 -> V_43 -> V_85 ) ,
sizeof( struct V_80 ) ,
V_86 ,
V_2 -> V_74 + V_82 ,
false ,
& V_2 -> V_87 ) ;
V_2 -> V_88 = F_21 (
& ( V_2 -> V_43 -> V_89 ) ,
sizeof( T_2 ) ,
V_90 , 0 , true ,
NULL ) ;
V_2 -> V_91 = V_2 -> V_15 -> V_92 ;
V_2 -> V_51 = V_2 -> V_15 -> V_51 ;
V_2 -> V_52 = V_2 -> V_15 -> V_52 ;
V_2 -> V_93 =
( ~ ( T_2 ) 0 ) >> ( V_2 -> V_52 + V_2 -> V_51 ) ;
V_2 -> V_45 =
F_22 ( V_2 -> V_91 * sizeof( struct V_39 ) ,
V_94 ) ;
F_23 ( & V_2 -> V_95 ) ;
F_24 ( & V_2 -> V_96 ) ;
F_23 ( & V_2 -> V_97 ) ;
F_24 ( & V_2 -> V_98 ) ;
F_12 ( & V_2 -> V_99 ) ;
F_25 ( V_2 ) ;
V_61 = F_26 ( V_2 ) ;
if ( V_61 )
return V_61 ;
V_2 -> V_100 = F_6 ( V_2 , 0 ,
( unsigned long ) V_2 -> V_71 ,
( unsigned long ) V_2 -> V_71 + V_2 -> V_15 -> V_29 ) ;
V_2 -> V_101 = F_6 ( V_2 , 1 ,
( unsigned long ) V_2 -> V_72 ,
( unsigned long ) V_2 -> V_72 + V_2 -> V_73 ) ;
F_5 ( L_13 ,
V_2 -> V_100 ,
( unsigned long ) V_2 -> V_71 , V_2 -> V_15 -> V_29 ) ;
V_2 -> V_102 = F_27 ( L_14 ) ;
F_28 ( & V_2 -> V_55 , F_8 ) ;
V_61 = F_29 ( V_2 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_103 [ 0 ] )
F_31 ( & V_2 -> V_103 [ 0 ] ) ;
if ( V_2 -> V_103 [ 1 ] )
F_31 ( & V_2 -> V_103 [ 1 ] ) ;
F_32 ( V_2 -> V_102 ) ;
F_33 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
F_34 ( V_2 -> V_78 ) ;
F_34 ( V_2 -> V_84 ) ;
F_34 ( V_2 -> V_88 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 -> V_76 ) ;
F_36 ( V_2 -> V_75 ) ;
F_37 ( V_2 -> V_43 ) ;
F_37 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_30 . V_33 = NULL ;
V_2 -> V_30 . V_31 = 0 ;
F_38 ( V_2 ) ;
}
int F_39 ( struct V_56 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_104 ;
if ( V_2 == NULL )
return 0 ;
F_40 ( V_2 ) ;
F_30 ( V_2 ) ;
F_41 ( V_2 ) ;
V_62 -> V_104 = NULL ;
return 0 ;
}
int F_42 ( struct V_56 * V_62 , unsigned long V_60 )
{
struct V_1 * V_2 ;
int V_61 ;
if ( ! F_43 ( V_62 , V_105 ) )
return - V_106 ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_94 ) ;
if ( V_2 == NULL )
return - V_77 ;
V_62 -> V_104 = V_2 ;
V_61 = F_11 ( V_2 , V_62 , V_62 -> V_59 , V_60 ) ;
if ( V_61 )
goto V_107;
V_61 = F_45 ( V_2 ) ;
if ( V_61 ) {
F_39 ( V_62 ) ;
goto V_107;
}
return 0 ;
V_107:
F_41 ( V_2 ) ;
return V_61 ;
}
