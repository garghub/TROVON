int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
int V_6 = V_7 ;
V_8 = V_9 ;
V_4 = F_2 ( & V_5 . V_10 , sizeof( V_11 ) , V_1 -> V_12 ) ;
if ( V_4 != sizeof( V_11 ) ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if( V_5 . V_10 . V_13 != V_14 )
{
return 0 ;
}
V_5 . V_10 . V_15 =
F_4 ( & V_5 . V_10 . V_15 ) ;
switch ( V_5 . V_10 . V_15 ) {
case V_16 :
break;
default:
* V_2 = V_17 ;
* V_3 = F_5 ( L_1 , V_5 . V_10 . V_15 ) ;
return - 1 ;
}
V_5 . V_10 . V_18 =
F_4 ( & V_5 . V_10 . V_18 ) ;
if( ( V_5 . V_10 . V_18 & V_19 ) != V_20 )
{
* V_2 = V_17 ;
* V_3 = F_5 ( L_2 , V_5 . V_10 . V_15 ) ;
return - 1 ;
}
switch ( V_5 . V_10 . V_18 ) {
case V_21 :
V_6 = V_22 ;
break;
default:
* V_2 = V_23 ;
* V_3 = F_5 ( L_3 ,
V_5 . V_10 . V_18 ) ;
return - 1 ;
}
V_4 = F_2 ( & V_5 . V_24 , sizeof ( T_3 ) - sizeof( V_11 ) , V_1 -> V_12 ) ;
if ( V_4 != sizeof ( T_3 ) - sizeof( V_11 ) ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_6 ;
V_1 -> V_32 = 0 ;
V_1 -> V_33 = V_34 ;
return 1 ;
}
static T_4
V_28 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_35 )
{
T_6 V_36 ;
int V_4 ;
T_7 V_37 ;
T_7 V_38 ;
do
{
V_4 = F_6 ( V_1 , V_1 -> V_12 , & V_36 , V_2 , V_3 ) ;
if ( V_4 == - 1 ) {
return FALSE ;
}
V_36 . V_39 = F_4 ( & V_36 . V_39 ) ;
if( V_36 . V_39 != V_40 ) {
* V_2 = V_41 ;
* V_3 = F_5 ( L_4 ,
V_36 . V_39 ) ;
return FALSE ;
}
V_36 . V_42 =
F_4 ( & V_36 . V_42 ) ;
V_36 . V_43 =
F_4 ( & V_36 . V_43 ) ;
if( V_36 . V_42 != V_44 ) {
if ( F_7 ( V_1 -> V_12 , V_36 . V_43 , V_45 , V_2 ) == - 1 )
return FALSE ;
} else
break;
} while ( 1 );
V_37 = V_36 . V_43 ;
V_38 = V_36 . V_43 ;
if ( V_37 > V_46 ) {
* V_2 = V_41 ;
* V_3 = F_5 ( L_5 ,
V_37 , V_46 ) ;
return FALSE ;
}
* V_35 = F_8 ( V_1 -> V_12 ) ;
F_9 ( V_1 -> V_47 , V_37 ) ;
if ( ! F_10 ( V_1 -> V_12 , F_11 ( V_1 -> V_47 ) ,
V_37 , V_2 , V_3 ) )
return FALSE ;
V_36 . V_48 = F_4 ( & V_36 . V_48 ) ;
V_36 . V_49 =
F_4 ( & V_36 . V_49 ) ;
V_1 -> V_50 . V_51 = V_52 | V_53 ;
V_1 -> V_50 . V_54 . V_55 = V_36 . V_48 ;
V_1 -> V_50 . V_54 . V_56 = V_36 . V_49 ;
V_1 -> V_50 . V_57 = V_37 ;
V_1 -> V_50 . V_58 = V_38 ;
switch ( V_1 -> V_31 ) {
case V_22 :
V_1 -> V_59 . V_60 . V_61 = 0 ;
break;
}
return TRUE ;
}
static T_4
F_10 ( T_8 V_12 , T_9 * V_62 , int V_63 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_8 = V_9 ;
V_4 = F_2 ( V_62 , V_63 , V_12 ) ;
if ( V_4 != V_63 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_64 ;
return FALSE ;
}
return TRUE ;
}
static int
F_6 ( T_1 * V_1 V_65 , T_8 V_12 , T_6 * V_66 , int * V_2 , T_2 * * V_3 )
{
int V_4 , V_67 ;
V_67 = sizeof( T_6 ) ;
V_4 = F_2 ( V_66 , V_67 , V_12 ) ;
if ( V_4 != V_67 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_64 ;
}
return - 1 ;
}
return V_4 ;
}
static T_4
V_30 ( T_1 * V_1 , T_5 V_68 ,
union V_69 * V_59 , T_9 * V_62 , int V_63 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_7 ( V_1 -> V_70 , V_68 , V_71 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 -> V_70 , V_62 , V_63 , V_2 , V_3 ) )
return FALSE ;
switch ( V_1 -> V_31 ) {
case V_22 :
V_59 -> V_60 . V_61 = 0 ;
break;
}
return TRUE ;
}
int F_12 ( int V_6 )
{
if ( V_6 == V_72 )
return V_73 ;
if ( V_6 < 0 || ( unsigned ) V_6 >= V_74 || V_75 [ V_6 ] == - 1 )
return V_23 ;
return 0 ;
}
T_4 F_13 ( T_10 * V_76 , int * V_2 )
{
T_11 * V_77 ;
if ( fseek ( V_76 -> V_12 , sizeof( T_3 ) , V_71 ) == - 1 ) {
* V_2 = V_8 ;
return FALSE ;
}
V_76 -> V_78 = V_79 ;
V_76 -> V_80 = V_81 ;
V_77 = ( T_11 * ) F_14 ( sizeof( T_11 ) ) ;
V_76 -> V_82 = ( void * ) V_77 ;
V_77 -> V_83 = 0 ;
return TRUE ;
}
static T_4 V_79 ( T_10 * V_76 ,
const struct V_84 * V_50 ,
const union V_69 * V_59 V_65 ,
const T_9 * V_62 , int * V_2 )
{
T_11 * V_77 = ( T_11 * ) V_76 -> V_82 ;
static T_6 V_85 ;
V_85 . V_39 = F_15 ( V_40 ) ;
V_85 . V_86 = F_16 ( sizeof( T_6 ) ) ;
V_85 . V_87 = F_16 ( V_88 ) ;
V_85 . V_89 = F_15 ( V_90 | V_91 ) ;
V_85 . V_42 = F_15 ( V_44 ) ;
V_85 . V_92 = F_15 ( 1 ) ;
V_85 . V_48 = F_15 ( V_50 -> V_54 . V_55 ) ;
V_85 . V_49 = F_15 ( V_50 -> V_54 . V_56 ) ;
V_85 . V_43 = F_15 ( V_50 -> V_58 ) ;
V_85 . V_93 = F_15 ( 0 ) ;
if ( ! F_17 ( V_76 , & V_85 ,
sizeof( T_6 ) , V_2 ) )
return FALSE ;
if ( ! F_17 ( V_76 , V_62 , V_50 -> V_57 , V_2 ) )
return FALSE ;
V_77 -> V_83 ++ ;
return TRUE ;
}
static T_4 V_81 ( T_10 * V_76 , int * V_2 )
{
T_11 * V_77 = ( T_11 * ) V_76 -> V_82 ;
T_3 V_94 ;
if ( fseek ( V_76 -> V_12 , 0 , V_71 ) == - 1 ) {
* V_2 = V_8 ;
return FALSE ;
}
V_94 . V_10 . V_13 = F_15 ( V_14 ) ;
V_94 . V_10 . V_95 = F_15 ( sizeof( V_11 ) ) ;
V_94 . V_10 . V_15 = F_15 ( V_16 ) ;
V_94 . V_10 . V_96 = F_15 ( sizeof( V_97 )
+ sizeof( V_98 )
+ sizeof( V_97 )
+ sizeof( V_98 ) ) ;
V_94 . V_10 . V_18 = F_15 ( V_75 [ V_76 -> V_6 ] ) ;
V_94 . V_10 . V_99 [ 0 ] = 0 ;
V_94 . V_10 . V_99 [ 1 ] = 0 ;
V_94 . V_10 . V_99 [ 2 ] = 0 ;
V_94 . V_24 . Type = F_15 ( V_100 ) ;
V_94 . V_24 . V_95 = F_16 ( sizeof( V_98 ) ) ;
V_94 . V_24 . V_101 = F_16 ( 1 ) ;
#ifdef F_18
F_19 () ;
#endif
V_94 . Time = F_15 ( time ( NULL ) ) ;
V_94 . V_102 . Type = F_15 ( V_103 ) ;
V_94 . V_102 . V_95 = F_16 ( sizeof( V_98 ) ) ;
V_94 . V_102 . V_101 = F_16 ( 1 ) ;
V_94 . V_104 = F_15 ( V_77 -> V_83 ) ;
if ( ! F_17 ( V_76 , & V_94 , sizeof( T_3 ) ,
V_2 ) )
return FALSE ;
return TRUE ;
}
