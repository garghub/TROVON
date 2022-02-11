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
int V_4 ;
T_7 V_38 ;
T_7 V_39 ;
do
{
V_4 = F_6 ( V_1 , V_1 -> V_12 , & V_37 , V_2 , V_3 ) ;
if ( V_4 == - 1 ) {
return FALSE ;
}
V_37 . V_40 = F_4 ( & V_37 . V_40 ) ;
if( V_37 . V_40 != V_41 ) {
* V_2 = V_42 ;
* V_3 = F_5 ( L_4 ,
V_37 . V_40 ) ;
return FALSE ;
}
V_37 . V_43 =
F_4 ( & V_37 . V_43 ) ;
V_37 . V_44 =
F_4 ( & V_37 . V_44 ) ;
if( V_37 . V_43 != V_45 ) {
if ( F_7 ( V_1 -> V_12 , V_37 . V_44 , V_46 , V_2 ) == - 1 )
return FALSE ;
} else
break;
} while ( 1 );
V_38 = V_37 . V_44 ;
V_39 = V_37 . V_44 ;
if ( V_38 > V_47 ) {
* V_2 = V_42 ;
* V_3 = F_5 ( L_5 ,
V_38 , V_47 ) ;
return FALSE ;
}
* V_36 = F_8 ( V_1 -> V_12 ) ;
F_9 ( V_1 -> V_48 , V_38 ) ;
if ( ! F_10 ( V_1 -> V_12 , F_11 ( V_1 -> V_48 ) ,
V_38 , V_2 , V_3 ) )
return FALSE ;
V_37 . V_49 = F_4 ( & V_37 . V_49 ) ;
V_37 . V_50 =
F_4 ( & V_37 . V_50 ) ;
V_1 -> V_51 . V_52 = V_53 | V_54 ;
V_1 -> V_51 . V_55 . V_56 = V_37 . V_49 ;
V_1 -> V_51 . V_55 . V_57 = V_37 . V_50 ;
V_1 -> V_51 . V_58 = V_38 ;
V_1 -> V_51 . V_59 = V_39 ;
switch ( V_1 -> V_32 ) {
case V_23 :
V_1 -> V_51 . V_60 . V_61 . V_62 = 0 ;
break;
}
return TRUE ;
}
static T_4
F_10 ( T_8 V_12 , T_9 * V_63 , int V_64 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_8 = V_9 ;
V_4 = F_2 ( V_63 , V_64 , V_12 ) ;
if ( V_4 != V_64 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
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
* V_2 = V_13 ;
}
return - 1 ;
}
return V_4 ;
}
static T_4
V_31 ( T_1 * V_1 , T_5 V_68 ,
struct V_69 * V_51 , T_9 * V_63 , int V_64 ,
int * V_2 , T_2 * * V_3 )
{
union V_70 * V_60 = & V_51 -> V_60 ;
if ( F_7 ( V_1 -> V_71 , V_68 , V_72 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_10 ( V_1 -> V_71 , V_63 , V_64 , V_2 , V_3 ) )
return FALSE ;
switch ( V_1 -> V_32 ) {
case V_23 :
V_60 -> V_61 . V_62 = 0 ;
break;
}
return TRUE ;
}
int F_12 ( int V_6 )
{
if ( V_6 == V_73 )
return V_74 ;
if ( V_6 < 0 || ( unsigned ) V_6 >= V_75 || V_76 [ V_6 ] == - 1 )
return V_24 ;
return 0 ;
}
T_4 F_13 ( T_10 * V_77 , int * V_2 )
{
T_11 * V_78 ;
if ( F_14 ( V_77 , sizeof( T_3 ) , V_72 , V_2 ) == - 1 )
return FALSE ;
V_77 -> V_79 = V_80 ;
V_77 -> V_81 = V_82 ;
V_78 = ( T_11 * ) F_15 ( sizeof( T_11 ) ) ;
V_77 -> V_83 = ( void * ) V_78 ;
V_78 -> V_84 = 0 ;
return TRUE ;
}
static T_4 V_80 ( T_10 * V_77 ,
const struct V_69 * V_51 ,
const T_9 * V_63 , int * V_2 )
{
T_11 * V_78 = ( T_11 * ) V_77 -> V_83 ;
static T_6 V_85 ;
V_85 . V_40 = F_16 ( V_41 ) ;
V_85 . V_86 = F_17 ( sizeof( T_6 ) ) ;
V_85 . V_87 = F_17 ( V_88 ) ;
V_85 . V_89 = F_16 ( V_90 | V_91 ) ;
V_85 . V_43 = F_16 ( V_45 ) ;
V_85 . V_92 = F_16 ( 1 ) ;
V_85 . V_49 = F_16 ( V_51 -> V_55 . V_56 ) ;
V_85 . V_50 = F_16 ( V_51 -> V_55 . V_57 ) ;
V_85 . V_44 = F_16 ( V_51 -> V_59 ) ;
V_85 . V_93 = F_16 ( 0 ) ;
if ( ! F_18 ( V_77 , & V_85 ,
sizeof( T_6 ) , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_77 , V_63 , V_51 -> V_58 , V_2 ) )
return FALSE ;
V_78 -> V_84 ++ ;
return TRUE ;
}
static T_4 V_82 ( T_10 * V_77 , int * V_2 )
{
T_11 * V_78 = ( T_11 * ) V_77 -> V_83 ;
T_3 V_94 ;
if ( F_14 ( V_77 , 0 , V_72 , V_2 ) == - 1 )
return FALSE ;
V_94 . V_10 . V_14 = F_16 ( V_15 ) ;
V_94 . V_10 . V_95 = F_16 ( sizeof( V_11 ) ) ;
V_94 . V_10 . V_16 = F_16 ( V_17 ) ;
V_94 . V_10 . V_96 = F_16 ( sizeof( V_97 )
+ sizeof( V_98 )
+ sizeof( V_97 )
+ sizeof( V_98 ) ) ;
V_94 . V_10 . V_19 = F_16 ( V_76 [ V_77 -> V_6 ] ) ;
V_94 . V_10 . V_99 [ 0 ] = 0 ;
V_94 . V_10 . V_99 [ 1 ] = 0 ;
V_94 . V_10 . V_99 [ 2 ] = 0 ;
V_94 . V_25 . Type = F_16 ( V_100 ) ;
V_94 . V_25 . V_95 = F_17 ( sizeof( V_98 ) ) ;
V_94 . V_25 . V_101 = F_17 ( 1 ) ;
#ifdef F_19
F_20 () ;
#endif
V_94 . Time = F_16 ( time ( NULL ) ) ;
V_94 . V_102 . Type = F_16 ( V_103 ) ;
V_94 . V_102 . V_95 = F_17 ( sizeof( V_98 ) ) ;
V_94 . V_102 . V_101 = F_17 ( 1 ) ;
V_94 . V_104 = F_16 ( V_78 -> V_84 ) ;
if ( ! F_18 ( V_77 , & V_94 , sizeof( T_3 ) ,
V_2 ) )
return FALSE ;
return TRUE ;
}
