int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
int V_5 = V_6 ;
V_7 = V_8 ;
if ( ! F_2 ( V_1 -> V_9 , & V_4 . V_10 ,
sizeof( V_11 ) , V_2 , V_3 ) ) {
if ( * V_2 != V_12 )
return - 1 ;
return 0 ;
}
if( V_4 . V_10 . V_13 != V_14 )
{
return 0 ;
}
V_4 . V_10 . V_15 =
F_3 ( & V_4 . V_10 . V_15 ) ;
switch ( V_4 . V_10 . V_15 ) {
case V_16 :
break;
default:
* V_2 = V_17 ;
* V_3 = F_4 ( L_1 , V_4 . V_10 . V_15 ) ;
return - 1 ;
}
V_4 . V_10 . V_18 =
F_3 ( & V_4 . V_10 . V_18 ) ;
if( ( V_4 . V_10 . V_18 & V_19 ) != V_20 )
{
* V_2 = V_17 ;
* V_3 = F_4 ( L_2 , V_4 . V_10 . V_15 ) ;
return - 1 ;
}
switch ( V_4 . V_10 . V_18 ) {
case V_21 :
V_5 = V_22 ;
break;
default:
* V_2 = V_23 ;
* V_3 = F_4 ( L_3 ,
V_4 . V_10 . V_18 ) ;
return - 1 ;
}
if ( ! F_2 ( V_1 -> V_9 , & V_4 . V_24 ,
sizeof ( T_3 ) - sizeof( V_11 ) , V_2 , V_3 ) )
return - 1 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_5 ;
V_1 -> V_32 = 0 ;
V_1 -> V_33 = V_34 ;
return 1 ;
}
static T_4
V_28 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_35 )
{
T_6 V_36 ;
do
{
* V_35 = F_5 ( V_1 -> V_9 ) ;
if ( ! F_6 ( V_1 , V_1 -> V_9 , & V_36 ,
& V_1 -> V_37 , V_2 , V_3 ) )
return FALSE ;
if ( V_36 . V_38 == V_39 ) {
break;
}
if ( F_7 ( V_1 -> V_9 , V_36 . V_40 , V_41 , V_2 ) == - 1 )
return FALSE ;
} while ( 1 );
if ( V_1 -> V_37 . V_42 > V_43 ) {
* V_2 = V_44 ;
* V_3 = F_4 ( L_4 ,
V_1 -> V_37 . V_42 , V_43 ) ;
return FALSE ;
}
return F_8 ( V_1 -> V_9 , V_1 -> V_45 ,
V_1 -> V_37 . V_42 , V_2 , V_3 ) ;
}
static T_4
V_30 ( T_1 * V_1 , T_5 V_46 , struct V_47 * V_37 ,
T_7 * V_48 , int * V_2 , T_2 * * V_3 )
{
T_6 V_36 ;
if ( F_7 ( V_1 -> V_49 , V_46 , V_50 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_1 , V_1 -> V_49 , & V_36 ,
V_37 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
return F_8 ( V_1 -> V_49 , V_48 , V_37 -> V_42 ,
V_2 , V_3 ) ;
}
static T_4
F_6 ( T_1 * V_1 , T_8 V_9 , T_6 * V_51 ,
struct V_47 * V_37 , int * V_2 , T_2 * * V_3 )
{
if ( ! F_9 ( V_9 , V_51 , ( unsigned int ) sizeof( T_6 ) ,
V_2 , V_3 ) )
return FALSE ;
V_51 -> V_52 = F_3 ( & V_51 -> V_52 ) ;
if ( V_51 -> V_52 != V_53 ) {
* V_2 = V_44 ;
* V_3 = F_4 ( L_5 ,
V_51 -> V_52 ) ;
return FALSE ;
}
V_51 -> V_38 = F_3 ( & V_51 -> V_38 ) ;
V_51 -> V_40 = F_3 ( & V_51 -> V_40 ) ;
V_51 -> V_54 = F_3 ( & V_51 -> V_54 ) ;
V_51 -> V_55 = F_3 ( & V_51 -> V_55 ) ;
V_37 -> V_56 = V_57 ;
V_37 -> V_58 = V_59 ;
V_37 -> V_60 . V_61 = V_51 -> V_54 ;
V_37 -> V_60 . V_62 = V_51 -> V_55 ;
V_37 -> V_42 = V_51 -> V_40 ;
V_37 -> V_63 = V_51 -> V_40 ;
switch ( V_1 -> V_31 ) {
case V_22 :
V_37 -> V_64 . V_65 . V_66 = 0 ;
break;
}
return TRUE ;
}
int F_10 ( int V_5 )
{
if ( V_5 == V_67 )
return V_68 ;
if ( V_5 < 0 || ( unsigned int ) V_5 >= V_69 || V_70 [ V_5 ] == - 1 )
return V_23 ;
return 0 ;
}
T_4 F_11 ( T_9 * V_71 , int * V_2 )
{
T_10 * V_72 ;
if ( F_12 ( V_71 , sizeof( T_3 ) , V_50 , V_2 ) == - 1 )
return FALSE ;
V_71 -> V_73 = V_74 ;
V_71 -> V_75 = V_76 ;
V_72 = ( T_10 * ) F_13 ( sizeof( T_10 ) ) ;
V_71 -> V_77 = ( void * ) V_72 ;
V_72 -> V_78 = 0 ;
return TRUE ;
}
static T_4 V_74 ( T_9 * V_71 ,
const struct V_47 * V_37 ,
const T_11 * V_79 , int * V_2 )
{
T_10 * V_72 = ( T_10 * ) V_71 -> V_77 ;
T_6 V_80 ;
if ( V_37 -> V_56 != V_57 ) {
* V_2 = V_81 ;
return FALSE ;
}
if ( V_37 -> V_42 > V_43 ) {
* V_2 = V_82 ;
return FALSE ;
}
V_80 . V_52 = F_14 ( V_53 ) ;
V_80 . V_83 = F_15 ( sizeof( T_6 ) ) ;
V_80 . V_84 = F_15 ( V_85 ) ;
V_80 . V_86 = F_14 ( V_87 | V_88 ) ;
V_80 . V_38 = F_14 ( V_39 ) ;
V_80 . V_89 = F_14 ( 1 ) ;
V_80 . V_54 = F_14 ( V_37 -> V_60 . V_61 ) ;
V_80 . V_55 = F_14 ( V_37 -> V_60 . V_62 ) ;
V_80 . V_40 = F_14 ( V_37 -> V_63 ) ;
V_80 . V_90 = F_14 ( 0 ) ;
if ( ! F_16 ( V_71 , & V_80 ,
sizeof( T_6 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_71 , V_79 , V_37 -> V_42 , V_2 ) )
return FALSE ;
V_72 -> V_78 ++ ;
return TRUE ;
}
static T_4 V_76 ( T_9 * V_71 , int * V_2 )
{
T_10 * V_72 = ( T_10 * ) V_71 -> V_77 ;
T_3 V_91 ;
if ( F_12 ( V_71 , 0 , V_50 , V_2 ) == - 1 )
return FALSE ;
V_91 . V_10 . V_13 = F_14 ( V_14 ) ;
V_91 . V_10 . V_92 = F_14 ( sizeof( V_11 ) ) ;
V_91 . V_10 . V_15 = F_14 ( V_16 ) ;
V_91 . V_10 . V_93 = F_14 ( sizeof( V_94 )
+ sizeof( V_95 )
+ sizeof( V_94 )
+ sizeof( V_95 ) ) ;
V_91 . V_10 . V_18 = F_14 ( V_70 [ V_71 -> V_5 ] ) ;
V_91 . V_10 . V_96 [ 0 ] = 0 ;
V_91 . V_10 . V_96 [ 1 ] = 0 ;
V_91 . V_10 . V_96 [ 2 ] = 0 ;
V_91 . V_24 . Type = F_14 ( V_97 ) ;
V_91 . V_24 . V_92 = F_15 ( sizeof( V_95 ) ) ;
V_91 . V_24 . V_98 = F_15 ( 1 ) ;
#ifdef F_17
F_18 () ;
#endif
V_91 . Time = F_14 ( time ( NULL ) ) ;
V_91 . V_99 . Type = F_14 ( V_100 ) ;
V_91 . V_99 . V_92 = F_15 ( sizeof( V_95 ) ) ;
V_91 . V_99 . V_98 = F_15 ( 1 ) ;
V_91 . V_101 = F_14 ( V_72 -> V_78 ) ;
if ( ! F_16 ( V_71 , & V_91 , sizeof( T_3 ) ,
V_2 ) )
return FALSE ;
return TRUE ;
}
