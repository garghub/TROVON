T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 = NULL ;
#ifndef F_2
T_3 * V_3 = NULL ;
#endif
#ifndef F_3
T_4 * V_4 = NULL ;
T_5 * V_5 , * V_6 ;
T_6 * V_7 ;
F_4 ( T_5 ) * V_8 = NULL ;
#endif
#ifndef F_5
T_7 * V_9 = NULL ;
const unsigned char * V_10 ;
#endif
#if ! F_6 ( F_3 ) || ! F_6 ( F_5 )
T_5 * V_11 = NULL ;
T_8 * V_12 = NULL ;
int V_13 ;
#endif
T_9 * V_14 ;
const unsigned char * V_15 ;
const unsigned char * V_16 ;
int V_17 ;
int V_18 ;
char V_19 [ 80 ] ;
if( V_1 -> V_2 -> type == V_20 ) {
V_1 -> V_21 = V_22 ;
V_15 = V_1 -> V_2 -> V_23 . V_24 -> V_25 ;
V_17 = V_1 -> V_2 -> V_23 . V_24 -> V_26 ;
} else {
V_1 -> V_21 = V_27 ;
V_15 = V_1 -> V_2 -> V_23 . V_28 -> V_25 ;
V_17 = V_1 -> V_2 -> V_23 . V_28 -> V_26 ;
}
if ( ! ( V_2 = F_7 () ) ) {
F_8 ( V_29 , V_30 ) ;
return NULL ;
}
V_14 = V_1 -> V_31 ;
V_18 = F_9 ( V_14 -> V_32 ) ;
switch( V_18 )
{
#ifndef F_2
case V_33 :
V_16 = V_15 ;
if ( ! ( V_3 = F_10 ( NULL , & V_16 , V_17 ) ) ) {
F_8 ( V_29 , V_34 ) ;
return NULL ;
}
F_11 ( V_2 , V_3 ) ;
break;
#endif
#ifndef F_3
case V_35 :
if( * V_15 == ( V_36 | V_37 ) ) {
if( ! ( V_8 = F_12 ( V_15 , V_17 ,
V_38 ,
V_39 ) ) ) {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
if( F_13 ( V_8 ) != 2 ) {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
V_5 = F_14 ( V_8 , 0 ) ;
V_6 = F_14 ( V_8 , 1 ) ;
if( V_5 -> type == V_36 ) {
V_1 -> V_21 = V_41 ;
V_11 = V_5 ;
} else if( V_14 -> V_42 -> type == V_36 ) {
V_1 -> V_21 = V_43 ;
V_11 = V_14 -> V_42 ;
} else {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
if( V_6 -> type != V_44 ) {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
V_7 = V_6 -> V_23 . integer ;
} else {
if ( ! ( V_7 = F_15 ( NULL , & V_15 , V_17 ) ) ) {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
V_11 = V_1 -> V_31 -> V_42 ;
}
if ( ! V_11 || ( V_11 -> type != V_36 ) ) {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
V_16 = V_15 = V_11 -> V_23 . V_28 -> V_25 ;
V_13 = V_11 -> V_23 . V_28 -> V_26 ;
if ( ! ( V_4 = F_16 ( NULL , & V_16 , V_13 ) ) ) {
F_8 ( V_29 , V_34 ) ;
goto V_40;
}
if ( ! ( V_4 -> V_45 = F_17 ( V_7 , NULL ) ) ) {
F_8 ( V_29 , V_46 ) ;
goto V_40;
}
if ( ! ( V_4 -> V_47 = F_18 () ) ) {
F_8 ( V_29 , V_30 ) ;
goto V_40;
}
if ( ! ( V_12 = F_19 () ) ) {
F_8 ( V_29 , V_30 ) ;
goto V_40;
}
if ( ! F_20 ( V_4 -> V_47 , V_4 -> V_48 ,
V_4 -> V_45 , V_4 -> V_15 , V_12 ) ) {
F_8 ( V_29 , V_49 ) ;
goto V_40;
}
F_21 ( V_2 , V_4 ) ;
F_22 ( V_12 ) ;
if( V_8 ) F_23 ( V_8 , V_39 ) ;
else F_24 ( V_7 ) ;
break;
V_40:
F_22 ( V_12 ) ;
F_23 ( V_8 , V_39 ) ;
F_25 ( V_4 ) ;
F_26 ( V_2 ) ;
return NULL ;
break;
#endif
#ifndef F_5
case V_50 :
V_10 = V_15 ;
V_11 = V_1 -> V_31 -> V_42 ;
if ( ! V_11 || ( ( V_11 -> type != V_36 ) &&
( V_11 -> type != V_51 ) ) )
{
F_8 ( V_29 , V_34 ) ;
goto V_52;
}
if ( V_11 -> type == V_36 )
{
V_16 = V_15 = V_11 -> V_23 . V_28 -> V_25 ;
V_13 = V_11 -> V_23 . V_28 -> V_26 ;
if ( ! ( V_9 = F_27 ( NULL , & V_16 , V_13 ) ) )
{
F_8 ( V_29 ,
V_34 ) ;
goto V_52;
}
}
else
{
T_10 * V_53 ;
V_16 = V_15 = V_11 -> V_23 . V_54 -> V_25 ;
V_13 = V_11 -> V_23 . V_54 -> V_26 ;
if ( ( V_9 = F_28 () ) == NULL )
{
F_8 ( V_29 ,
V_30 ) ;
goto V_52;
}
V_53 = F_29 ( F_9 ( V_14 -> V_42 -> V_23 . V_54 ) ) ;
if ( V_53 == NULL )
goto V_52;
F_30 ( V_53 , V_55 ) ;
if ( F_31 ( V_9 , V_53 ) == 0 )
goto V_52;
F_32 ( V_53 ) ;
}
if ( ! F_33 ( & V_9 , & V_10 , V_17 ) )
{
F_8 ( V_29 , V_34 ) ;
goto V_52;
}
if ( F_34 ( V_9 ) == NULL )
{
const T_11 * V_45 ;
const T_10 * V_53 ;
T_12 * V_47 ;
V_53 = F_35 ( V_9 ) ;
V_47 = F_36 ( V_53 ) ;
if ( V_47 == NULL )
{
F_8 ( V_29 , V_56 ) ;
goto V_52;
}
if ( ! F_37 ( V_47 , F_38 ( V_53 ) ) )
{
F_39 ( V_47 ) ;
F_8 ( V_29 , V_56 ) ;
goto V_52;
}
V_45 = F_40 ( V_9 ) ;
if ( ! F_41 ( V_53 , V_47 , V_45 , NULL , NULL , V_12 ) )
{
F_39 ( V_47 ) ;
F_8 ( V_29 , V_56 ) ;
goto V_52;
}
if ( F_42 ( V_9 , V_47 ) == 0 )
{
F_39 ( V_47 ) ;
F_8 ( V_29 , V_56 ) ;
goto V_52;
}
F_39 ( V_47 ) ;
}
F_43 ( V_2 , V_9 ) ;
if ( V_12 )
F_22 ( V_12 ) ;
break;
V_52:
if ( V_12 )
F_22 ( V_12 ) ;
if ( V_9 )
F_44 ( V_9 ) ;
if ( V_2 )
F_26 ( V_2 ) ;
return NULL ;
#endif
default:
F_8 ( V_29 , V_57 ) ;
if ( ! V_14 -> V_32 ) F_45 ( V_19 , L_1 , sizeof V_19 ) ;
else F_46 ( V_19 , 80 , V_14 -> V_32 ) ;
F_47 ( 2 , L_2 , V_19 ) ;
F_26 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_2 * F_48 ( T_1 * V_2 )
{
return F_49 ( V_2 , V_22 ) ;
}
T_2 * F_49 ( T_1 * V_2 , int V_21 )
{
T_2 * V_1 ;
if ( ! ( V_1 = F_50 () ) ) {
F_8 ( V_58 , V_30 ) ;
return NULL ;
}
V_1 -> V_21 = V_21 ;
if ( ! F_51 ( V_1 -> V_59 , 0 ) ) {
F_8 ( V_58 , V_30 ) ;
F_52 ( V_1 ) ;
return NULL ;
}
if ( ! ( V_1 -> V_31 -> V_42 = F_53 () ) ) {
F_8 ( V_58 , V_30 ) ;
F_52 ( V_1 ) ;
return NULL ;
}
V_1 -> V_2 -> type = V_20 ;
switch ( F_54 ( V_2 -> type ) ) {
#ifndef F_2
case V_60 :
if( V_1 -> V_21 == V_27 ) V_1 -> V_2 -> type = V_36 ;
V_1 -> V_31 -> V_32 = F_55 ( V_33 ) ;
V_1 -> V_31 -> V_42 -> type = V_61 ;
if ( ! F_56 ( T_1 , V_2 , V_62 ,
& V_1 -> V_2 -> V_23 . V_24 ) ) {
F_8 ( V_58 , V_30 ) ;
F_52 ( V_1 ) ;
return NULL ;
}
break;
#endif
#ifndef F_3
case V_63 :
if( ! F_57 ( V_1 , V_2 ) ) {
F_52 ( V_1 ) ;
return NULL ;
}
break;
#endif
#ifndef F_5
case V_64 :
if ( ! F_58 ( V_1 , V_2 ) )
{
F_52 ( V_1 ) ;
return ( NULL ) ;
}
break;
#endif
default:
F_8 ( V_58 , V_57 ) ;
F_52 ( V_1 ) ;
return NULL ;
}
F_59 ( V_1 -> V_2 -> V_23 . V_24 -> V_25 ,
V_1 -> V_2 -> V_23 . V_24 -> V_26 , 0.0 ) ;
return V_1 ;
}
T_2 * F_60 ( T_2 * V_1 , int V_21 )
{
switch ( V_21 ) {
case V_22 :
V_1 -> V_21 = V_22 ;
return V_1 ;
break;
case V_27 :
V_1 -> V_21 = V_27 ;
V_1 -> V_2 -> type = V_36 ;
return V_1 ;
break;
default:
F_8 ( V_65 , V_66 ) ;
return NULL ;
}
}
static int F_57 ( T_2 * V_1 , T_1 * V_2 )
{
T_13 * V_67 = NULL ;
T_6 * V_68 = NULL ;
T_5 * V_69 = NULL ;
F_4 ( T_5 ) * V_8 = NULL ;
unsigned char * V_15 = NULL , * V_70 ;
int V_71 ;
V_1 -> V_31 -> V_32 = F_55 ( V_35 ) ;
V_71 = F_61 ( V_2 -> V_2 . V_4 , NULL ) ;
if ( ! ( V_15 = F_62 ( V_71 ) ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
V_70 = V_15 ;
F_61 ( V_2 -> V_2 . V_4 , & V_70 ) ;
if ( ! ( V_67 = F_63 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! F_64 ( V_67 , V_15 , V_71 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
F_65 ( V_15 ) ;
V_15 = NULL ;
if ( ! ( V_68 = F_66 ( V_2 -> V_2 . V_4 -> V_45 , NULL ) ) ) {
F_8 ( V_72 , V_74 ) ;
goto V_73;
}
switch( V_1 -> V_21 ) {
case V_22 :
case V_27 :
if ( ! F_56 ( T_6 , V_68 , V_75 ,
& V_1 -> V_2 -> V_23 . V_24 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
F_67 ( V_68 ) ;
V_68 = NULL ;
V_1 -> V_31 -> V_42 -> V_23 . V_28 = V_67 ;
V_67 = NULL ;
V_1 -> V_31 -> V_42 -> type = V_36 ;
break;
case V_43 :
V_1 -> V_31 -> V_42 -> V_23 . V_28 = V_67 ;
V_67 = NULL ;
V_1 -> V_31 -> V_42 -> type = V_36 ;
if ( ! ( V_8 = F_68 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! ( V_69 = F_53 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! ( V_69 -> V_23 . integer =
F_66 ( V_2 -> V_2 . V_4 -> V_47 , NULL ) ) ) {
F_8 ( V_72 , V_74 ) ;
goto V_73;
}
V_69 -> type = V_44 ;
if ( ! F_69 ( V_8 , V_69 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! ( V_69 = F_53 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
V_69 -> V_23 . integer = V_68 ;
V_68 = NULL ;
V_69 -> type = V_44 ;
if ( ! F_69 ( V_8 , V_69 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
V_69 = NULL ;
if ( ! ( V_1 -> V_2 -> V_23 . V_24 = F_70 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! F_71 ( V_8 , V_76 ,
& V_1 -> V_2 -> V_23 . V_24 -> V_25 ,
& V_1 -> V_2 -> V_23 . V_24 -> V_26 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
F_23 ( V_8 , V_39 ) ;
break;
case V_41 :
V_1 -> V_31 -> V_42 -> type = V_61 ;
if ( ! ( V_8 = F_68 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! ( V_69 = F_53 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
V_69 -> V_23 . V_28 = V_67 ;
V_67 = NULL ;
V_69 -> type = V_36 ;
if ( ! F_69 ( V_8 , V_69 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! ( V_69 = F_53 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
V_69 -> V_23 . integer = V_68 ;
V_68 = NULL ;
V_69 -> type = V_44 ;
if ( ! F_69 ( V_8 , V_69 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
V_69 = NULL ;
if ( ! ( V_1 -> V_2 -> V_23 . V_24 = F_70 () ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
if ( ! F_71 ( V_8 , V_76 ,
& V_1 -> V_2 -> V_23 . V_24 -> V_25 ,
& V_1 -> V_2 -> V_23 . V_24 -> V_26 ) ) {
F_8 ( V_72 , V_30 ) ;
goto V_73;
}
F_23 ( V_8 , V_39 ) ;
break;
}
return 1 ;
V_73:
if ( V_15 != NULL ) F_65 ( V_15 ) ;
if ( V_67 != NULL ) F_72 ( V_67 ) ;
if ( V_68 != NULL ) F_67 ( V_68 ) ;
if ( V_69 != NULL ) V_39 ( V_69 ) ;
if ( V_8 != NULL ) F_23 ( V_8 , V_39 ) ;
return 0 ;
}
static int F_58 ( T_2 * V_1 , T_1 * V_2 )
{
T_7 * V_77 ;
const T_10 * V_53 ;
unsigned char * V_15 , * V_78 ;
int V_18 , V_79 , V_80 = 0 ;
unsigned int V_81 , V_82 ;
V_77 = V_2 -> V_2 . V_83 ;
if ( V_77 == NULL || ( V_53 = F_35 ( V_77 ) ) == NULL )
{
F_8 ( V_84 , V_85 ) ;
return 0 ;
}
if ( V_1 -> V_31 -> V_32 )
F_73 ( V_1 -> V_31 -> V_32 ) ;
V_1 -> V_31 -> V_32 = F_55 ( V_50 ) ;
if ( V_1 -> V_31 -> V_42 )
{
V_39 ( V_1 -> V_31 -> V_42 ) ;
V_1 -> V_31 -> V_42 = NULL ;
}
if ( ( V_1 -> V_31 -> V_42 = F_53 () ) == NULL )
{
F_8 ( V_84 , V_30 ) ;
return 0 ;
}
if ( F_74 ( V_53 )
&& ( V_18 = F_75 ( V_53 ) ) )
{
V_1 -> V_31 -> V_42 -> type = V_51 ;
V_1 -> V_31 -> V_42 -> V_23 . V_54 = F_55 ( V_18 ) ;
}
else
{
if ( ( V_79 = F_76 ( V_77 , NULL ) ) == 0 )
{
F_8 ( V_84 , V_56 ) ;
return 0 ;
}
if ( ( V_15 = ( unsigned char * ) F_62 ( V_79 ) ) == NULL )
{
F_8 ( V_84 , V_30 ) ;
return 0 ;
}
V_78 = V_15 ;
if ( ! F_76 ( V_77 , & V_78 ) )
{
F_8 ( V_84 , V_56 ) ;
F_65 ( V_15 ) ;
return 0 ;
}
V_1 -> V_31 -> V_42 -> type = V_36 ;
if ( ( V_1 -> V_31 -> V_42 -> V_23 . V_28
= F_63 () ) == NULL )
{
F_8 ( V_84 , V_86 ) ;
F_65 ( V_15 ) ;
return 0 ;
}
F_64 ( V_1 -> V_31 -> V_42 -> V_23 . V_28 , V_15 , V_79 ) ;
F_65 ( V_15 ) ;
}
V_82 = F_77 ( V_2 -> V_2 . V_83 ) ;
V_81 = V_82 | V_87 ;
F_78 ( V_2 -> V_2 . V_83 , V_81 ) ;
V_79 = F_79 ( V_2 -> V_2 . V_83 , NULL ) ;
if ( ! V_79 )
{
F_78 ( V_2 -> V_2 . V_83 , V_82 ) ;
F_8 ( V_84 , V_56 ) ;
return 0 ;
}
V_15 = ( unsigned char * ) F_62 ( V_79 ) ;
if ( ! V_15 )
{
F_78 ( V_2 -> V_2 . V_83 , V_82 ) ;
F_8 ( V_84 , V_30 ) ;
return 0 ;
}
V_78 = V_15 ;
if ( ! F_79 ( V_2 -> V_2 . V_83 , & V_78 ) )
{
F_78 ( V_2 -> V_2 . V_83 , V_82 ) ;
F_8 ( V_84 , V_56 ) ;
F_65 ( V_15 ) ;
return 0 ;
}
F_78 ( V_2 -> V_2 . V_83 , V_82 ) ;
switch( V_1 -> V_21 ) {
case V_22 :
V_1 -> V_2 -> V_23 . V_24 = F_70 () ;
if ( ! V_1 -> V_2 -> V_23 . V_24 ||
! F_80 ( V_1 -> V_2 -> V_23 . V_24 ,
( const void * ) V_15 , V_79 ) )
{
F_8 ( V_84 , V_30 ) ;
}
else
V_80 = 1 ;
break;
case V_27 :
case V_43 :
case V_41 :
default:
F_8 ( V_84 , V_74 ) ;
}
F_81 ( V_15 , ( V_88 ) V_79 ) ;
F_65 ( V_15 ) ;
return V_80 ;
}
int F_82 ( const T_1 * V_89 )
{
return F_83 ( V_89 -> V_90 ) ;
}
int F_84 ( const T_1 * V_89 , int V_18 ,
int V_91 )
{
return F_85 ( V_89 -> V_90 , V_18 , V_91 ) ;
}
int F_86 ( const T_1 * V_89 , T_14 * V_92 ,
int V_91 )
{
return F_87 ( V_89 -> V_90 , V_92 , V_91 ) ;
}
T_15 * F_88 ( const T_1 * V_89 , int V_93 )
{
return F_89 ( V_89 -> V_90 , V_93 ) ;
}
T_15 * F_90 ( T_1 * V_89 , int V_93 )
{
return F_91 ( V_89 -> V_90 , V_93 ) ;
}
int F_92 ( T_1 * V_89 , T_15 * V_94 )
{
if( F_93 ( & V_89 -> V_90 , V_94 ) ) return 1 ;
return 0 ;
}
int F_94 ( T_1 * V_89 ,
const T_14 * V_92 , int type ,
const unsigned char * V_95 , int V_71 )
{
if( F_95 ( & V_89 -> V_90 , V_92 ,
type , V_95 , V_71 ) ) return 1 ;
return 0 ;
}
int F_96 ( T_1 * V_89 ,
int V_18 , int type ,
const unsigned char * V_95 , int V_71 )
{
if( F_97 ( & V_89 -> V_90 , V_18 ,
type , V_95 , V_71 ) ) return 1 ;
return 0 ;
}
int F_98 ( T_1 * V_89 ,
const char * V_96 , int type ,
const unsigned char * V_95 , int V_71 )
{
if( F_99 ( & V_89 -> V_90 , V_96 ,
type , V_95 , V_71 ) ) return 1 ;
return 0 ;
}
