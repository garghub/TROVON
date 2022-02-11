T_1
F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
int V_5 = V_6 ;
if ( ! F_2 ( V_1 -> V_7 , & V_4 . V_8 ,
sizeof( V_9 ) , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
if( V_4 . V_8 . V_13 != V_14 )
{
return V_12 ;
}
V_4 . V_8 . V_15 =
F_3 ( & V_4 . V_8 . V_15 ) ;
switch ( V_4 . V_8 . V_15 ) {
case V_16 :
break;
default:
* V_2 = V_17 ;
* V_3 = F_4 ( L_1 , V_4 . V_8 . V_15 ) ;
return V_11 ;
}
V_4 . V_8 . V_18 =
F_3 ( & V_4 . V_8 . V_18 ) ;
if( ( V_4 . V_8 . V_18 & V_19 ) != V_20 )
{
* V_2 = V_17 ;
* V_3 = F_4 ( L_2 , V_4 . V_8 . V_15 ) ;
return V_11 ;
}
switch ( V_4 . V_8 . V_18 ) {
case V_21 :
V_5 = V_22 ;
break;
default:
* V_2 = V_17 ;
* V_3 = F_4 ( L_3 ,
V_4 . V_8 . V_18 ) ;
return V_11 ;
}
if ( ! F_2 ( V_1 -> V_7 , & V_4 . V_23 ,
sizeof ( T_4 ) - sizeof( V_9 ) , V_2 , V_3 ) )
return V_11 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_5 ;
V_1 -> V_31 = 0 ;
V_1 -> V_32 = V_33 ;
return V_34 ;
}
static T_5
V_27 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_6 * V_35 )
{
T_7 V_36 ;
do
{
* V_35 = F_5 ( V_1 -> V_7 ) ;
if ( ! F_6 ( V_1 , V_1 -> V_7 , & V_36 ,
& V_1 -> V_37 , V_2 , V_3 ) )
return FALSE ;
if ( V_36 . V_38 == V_39 ) {
break;
}
if ( ! F_2 ( V_1 -> V_7 , NULL , V_36 . V_40 , V_2 , V_3 ) )
return FALSE ;
} while ( 1 );
if ( V_1 -> V_37 . V_41 > V_42 ) {
* V_2 = V_43 ;
* V_3 = F_4 ( L_4 ,
V_1 -> V_37 . V_41 , V_42 ) ;
return FALSE ;
}
return F_7 ( V_1 -> V_7 , V_1 -> V_44 ,
V_1 -> V_37 . V_41 , V_2 , V_3 ) ;
}
static T_5
V_29 ( T_2 * V_1 , T_6 V_45 , struct V_46 * V_37 ,
T_8 * V_47 , int * V_2 , T_3 * * V_3 )
{
T_7 V_36 ;
if ( F_8 ( V_1 -> V_48 , V_45 , V_49 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_1 , V_1 -> V_48 , & V_36 ,
V_37 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_10 ;
return FALSE ;
}
return F_7 ( V_1 -> V_48 , V_47 , V_37 -> V_41 ,
V_2 , V_3 ) ;
}
static T_5
F_6 ( T_2 * V_1 , T_9 V_7 , T_7 * V_50 ,
struct V_46 * V_37 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_9 ( V_7 , V_50 , ( unsigned int ) sizeof( T_7 ) ,
V_2 , V_3 ) )
return FALSE ;
V_50 -> V_51 = F_3 ( & V_50 -> V_51 ) ;
if ( V_50 -> V_51 != V_52 ) {
* V_2 = V_43 ;
* V_3 = F_4 ( L_5 ,
V_50 -> V_51 ) ;
return FALSE ;
}
V_50 -> V_38 = F_3 ( & V_50 -> V_38 ) ;
V_50 -> V_40 = F_3 ( & V_50 -> V_40 ) ;
V_50 -> V_53 = F_3 ( & V_50 -> V_53 ) ;
V_50 -> V_54 = F_3 ( & V_50 -> V_54 ) ;
V_37 -> V_55 = V_56 ;
V_37 -> V_57 = V_58 ;
V_37 -> V_59 . V_60 = V_50 -> V_53 ;
V_37 -> V_59 . V_61 = V_50 -> V_54 ;
V_37 -> V_41 = V_50 -> V_40 ;
V_37 -> V_62 = V_50 -> V_40 ;
switch ( V_1 -> V_30 ) {
case V_22 :
V_37 -> V_63 . V_64 . V_65 = 0 ;
break;
}
return TRUE ;
}
int F_10 ( int V_5 )
{
if ( V_5 == V_66 )
return V_67 ;
if ( V_5 < 0 || ( unsigned int ) V_5 >= V_68 || V_69 [ V_5 ] == - 1 )
return V_70 ;
return 0 ;
}
T_5 F_11 ( T_10 * V_71 , int * V_2 )
{
T_11 * V_72 ;
if ( F_12 ( V_71 , sizeof( T_4 ) , V_49 , V_2 ) == - 1 )
return FALSE ;
V_71 -> V_73 = V_74 ;
V_71 -> V_75 = V_76 ;
V_72 = ( T_11 * ) F_13 ( sizeof( T_11 ) ) ;
V_71 -> V_77 = ( void * ) V_72 ;
V_72 -> V_78 = 0 ;
return TRUE ;
}
static T_5 V_74 ( T_10 * V_71 ,
const struct V_46 * V_37 ,
const T_12 * V_79 , int * V_2 , T_3 * * V_3 V_80 )
{
T_11 * V_72 = ( T_11 * ) V_71 -> V_77 ;
T_7 V_81 ;
if ( V_37 -> V_55 != V_56 ) {
* V_2 = V_82 ;
return FALSE ;
}
if ( V_37 -> V_41 > V_42 ) {
* V_2 = V_83 ;
return FALSE ;
}
V_81 . V_51 = F_14 ( V_52 ) ;
V_81 . V_84 = F_15 ( sizeof( T_7 ) ) ;
V_81 . V_85 = F_15 ( V_86 ) ;
V_81 . V_87 = F_14 ( V_88 | V_89 ) ;
V_81 . V_38 = F_14 ( V_39 ) ;
V_81 . V_90 = F_14 ( 1 ) ;
V_81 . V_53 = F_14 ( V_37 -> V_59 . V_60 ) ;
V_81 . V_54 = F_14 ( V_37 -> V_59 . V_61 ) ;
V_81 . V_40 = F_14 ( V_37 -> V_62 ) ;
V_81 . V_91 = F_14 ( 0 ) ;
if ( ! F_16 ( V_71 , & V_81 ,
sizeof( T_7 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_71 , V_79 , V_37 -> V_41 , V_2 ) )
return FALSE ;
V_72 -> V_78 ++ ;
return TRUE ;
}
static T_5 V_76 ( T_10 * V_71 , int * V_2 )
{
T_11 * V_72 = ( T_11 * ) V_71 -> V_77 ;
T_4 V_92 ;
if ( F_12 ( V_71 , 0 , V_49 , V_2 ) == - 1 )
return FALSE ;
V_92 . V_8 . V_13 = F_14 ( V_14 ) ;
V_92 . V_8 . V_93 = F_14 ( sizeof( V_9 ) ) ;
V_92 . V_8 . V_15 = F_14 ( V_16 ) ;
V_92 . V_8 . V_94 = F_14 ( sizeof( V_95 )
+ sizeof( V_96 )
+ sizeof( V_95 )
+ sizeof( V_96 ) ) ;
V_92 . V_8 . V_18 = F_14 ( V_69 [ V_71 -> V_5 ] ) ;
V_92 . V_8 . V_97 [ 0 ] = 0 ;
V_92 . V_8 . V_97 [ 1 ] = 0 ;
V_92 . V_8 . V_97 [ 2 ] = 0 ;
V_92 . V_23 . Type = F_14 ( V_98 ) ;
V_92 . V_23 . V_93 = F_15 ( sizeof( V_96 ) ) ;
V_92 . V_23 . V_99 = F_15 ( 1 ) ;
#ifdef F_17
F_18 () ;
#endif
V_92 . Time = F_14 ( time ( NULL ) ) ;
V_92 . V_100 . Type = F_14 ( V_101 ) ;
V_92 . V_100 . V_93 = F_15 ( sizeof( V_96 ) ) ;
V_92 . V_100 . V_99 = F_15 ( 1 ) ;
V_92 . V_102 = F_14 ( V_72 -> V_78 ) ;
if ( ! F_16 ( V_71 , & V_92 , sizeof( T_4 ) ,
V_2 ) )
return FALSE ;
return TRUE ;
}
