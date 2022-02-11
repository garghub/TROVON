int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
int V_6 = V_7 ;
V_8 = V_9 ;
V_4 = F_2 ( & V_5 . V_10 , sizeof( V_11 ) , V_1 -> V_12 ) ;
if ( V_4 != sizeof( V_11 ) ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
if( V_5 . V_10 . V_14 != V_15 )
{
return 0 ;
}
V_5 . V_10 . V_16 =
F_4 ( & V_5 . V_10 . V_16 ) ;
switch ( V_5 . V_10 . V_16 ) {
case V_17 :
break;
default:
* V_2 = V_18 ;
* V_3 = F_5 ( L_1 , V_5 . V_10 . V_16 ) ;
return - 1 ;
}
V_5 . V_10 . V_19 =
F_4 ( & V_5 . V_10 . V_19 ) ;
if( ( V_5 . V_10 . V_19 & V_20 ) != V_21 )
{
* V_2 = V_18 ;
* V_3 = F_5 ( L_2 , V_5 . V_10 . V_16 ) ;
return - 1 ;
}
switch ( V_5 . V_10 . V_19 ) {
case V_22 :
V_6 = V_23 ;
break;
default:
* V_2 = V_24 ;
* V_3 = F_5 ( L_3 ,
V_5 . V_10 . V_19 ) ;
return - 1 ;
}
V_4 = F_2 ( & V_5 . V_25 , sizeof ( T_3 ) - sizeof( V_11 ) , V_1 -> V_12 ) ;
if ( V_4 != sizeof ( T_3 ) - sizeof( V_11 ) ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
return - 1 ;
}
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_6 ;
V_1 -> V_33 = 0 ;
V_1 -> V_34 = V_35 ;
return 1 ;
}
static T_4
V_29 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_36 )
{
T_6 V_37 ;
do
{
* V_36 = F_6 ( V_1 -> V_12 ) ;
if ( ! F_7 ( V_1 , V_1 -> V_12 , & V_37 ,
& V_1 -> V_38 , V_2 , V_3 ) )
return FALSE ;
if ( V_37 . V_39 == V_40 ) {
break;
}
if ( F_8 ( V_1 -> V_12 , V_37 . V_41 , V_42 , V_2 ) == - 1 )
return FALSE ;
} while ( 1 );
if ( V_1 -> V_38 . V_43 > V_44 ) {
* V_2 = V_45 ;
* V_3 = F_5 ( L_4 ,
V_1 -> V_38 . V_43 , V_44 ) ;
return FALSE ;
}
return F_9 ( V_1 -> V_12 , V_1 -> V_46 ,
V_1 -> V_38 . V_43 , V_2 , V_3 ) ;
}
static T_4
V_31 ( T_1 * V_1 , T_5 V_47 , struct V_48 * V_38 ,
T_7 * V_49 , int V_50 , int * V_2 , T_2 * * V_3 )
{
T_6 V_37 ;
if ( F_8 ( V_1 -> V_51 , V_47 , V_52 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_7 ( V_1 , V_1 -> V_51 , & V_37 ,
V_38 , V_2 , V_3 ) )
return FALSE ;
return F_9 ( V_1 -> V_51 , V_49 , V_50 ,
V_2 , V_3 ) ;
}
static T_4
F_7 ( T_1 * V_1 , T_8 V_12 , T_6 * V_53 ,
struct V_48 * V_38 , int * V_2 , T_2 * * V_3 )
{
int V_4 , V_54 ;
V_54 = sizeof( T_6 ) ;
V_4 = F_2 ( V_53 , V_54 , V_12 ) ;
if ( V_4 != V_54 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_13 ;
}
return FALSE ;
}
V_53 -> V_55 = F_4 ( & V_53 -> V_55 ) ;
if ( V_53 -> V_55 != V_56 ) {
* V_2 = V_45 ;
* V_3 = F_5 ( L_5 ,
V_53 -> V_55 ) ;
return FALSE ;
}
V_53 -> V_39 = F_4 ( & V_53 -> V_39 ) ;
V_53 -> V_41 = F_4 ( & V_53 -> V_41 ) ;
V_53 -> V_57 = F_4 ( & V_53 -> V_57 ) ;
V_53 -> V_58 = F_4 ( & V_53 -> V_58 ) ;
V_38 -> V_59 = V_60 | V_61 ;
V_38 -> V_62 . V_63 = V_53 -> V_57 ;
V_38 -> V_62 . V_64 = V_53 -> V_58 ;
V_38 -> V_43 = V_53 -> V_41 ;
V_38 -> V_65 = V_53 -> V_41 ;
switch ( V_1 -> V_32 ) {
case V_23 :
V_38 -> V_66 . V_67 . V_68 = 0 ;
break;
}
return TRUE ;
}
int F_10 ( int V_6 )
{
if ( V_6 == V_69 )
return V_70 ;
if ( V_6 < 0 || ( unsigned ) V_6 >= V_71 || V_72 [ V_6 ] == - 1 )
return V_24 ;
return 0 ;
}
T_4 F_11 ( T_9 * V_73 , int * V_2 )
{
T_10 * V_74 ;
if ( F_12 ( V_73 , sizeof( T_3 ) , V_52 , V_2 ) == - 1 )
return FALSE ;
V_73 -> V_75 = V_76 ;
V_73 -> V_77 = V_78 ;
V_74 = ( T_10 * ) F_13 ( sizeof( T_10 ) ) ;
V_73 -> V_79 = ( void * ) V_74 ;
V_74 -> V_80 = 0 ;
return TRUE ;
}
static T_4 V_76 ( T_9 * V_73 ,
const struct V_48 * V_38 ,
const T_11 * V_81 , int * V_2 )
{
T_10 * V_74 = ( T_10 * ) V_73 -> V_79 ;
T_6 V_82 ;
V_82 . V_55 = F_14 ( V_56 ) ;
V_82 . V_83 = F_15 ( sizeof( T_6 ) ) ;
V_82 . V_84 = F_15 ( V_85 ) ;
V_82 . V_86 = F_14 ( V_87 | V_88 ) ;
V_82 . V_39 = F_14 ( V_40 ) ;
V_82 . V_89 = F_14 ( 1 ) ;
V_82 . V_57 = F_14 ( V_38 -> V_62 . V_63 ) ;
V_82 . V_58 = F_14 ( V_38 -> V_62 . V_64 ) ;
V_82 . V_41 = F_14 ( V_38 -> V_65 ) ;
V_82 . V_90 = F_14 ( 0 ) ;
if ( ! F_16 ( V_73 , & V_82 ,
sizeof( T_6 ) , V_2 ) )
return FALSE ;
if ( ! F_16 ( V_73 , V_81 , V_38 -> V_43 , V_2 ) )
return FALSE ;
V_74 -> V_80 ++ ;
return TRUE ;
}
static T_4 V_78 ( T_9 * V_73 , int * V_2 )
{
T_10 * V_74 = ( T_10 * ) V_73 -> V_79 ;
T_3 V_91 ;
if ( F_12 ( V_73 , 0 , V_52 , V_2 ) == - 1 )
return FALSE ;
V_91 . V_10 . V_14 = F_14 ( V_15 ) ;
V_91 . V_10 . V_92 = F_14 ( sizeof( V_11 ) ) ;
V_91 . V_10 . V_16 = F_14 ( V_17 ) ;
V_91 . V_10 . V_93 = F_14 ( sizeof( V_94 )
+ sizeof( V_95 )
+ sizeof( V_94 )
+ sizeof( V_95 ) ) ;
V_91 . V_10 . V_19 = F_14 ( V_72 [ V_73 -> V_6 ] ) ;
V_91 . V_10 . V_96 [ 0 ] = 0 ;
V_91 . V_10 . V_96 [ 1 ] = 0 ;
V_91 . V_10 . V_96 [ 2 ] = 0 ;
V_91 . V_25 . Type = F_14 ( V_97 ) ;
V_91 . V_25 . V_92 = F_15 ( sizeof( V_95 ) ) ;
V_91 . V_25 . V_98 = F_15 ( 1 ) ;
#ifdef F_17
F_18 () ;
#endif
V_91 . Time = F_14 ( time ( NULL ) ) ;
V_91 . V_99 . Type = F_14 ( V_100 ) ;
V_91 . V_99 . V_92 = F_15 ( sizeof( V_95 ) ) ;
V_91 . V_99 . V_98 = F_15 ( 1 ) ;
V_91 . V_101 = F_14 ( V_74 -> V_80 ) ;
if ( ! F_16 ( V_73 , & V_91 , sizeof( T_3 ) ,
V_2 ) )
return FALSE ;
return TRUE ;
}
