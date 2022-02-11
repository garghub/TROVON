static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_3 * V_5 = ( T_3 * ) * V_2 ;
if( ! V_5 || ! V_5 -> V_6 ) return 1 ;
switch( V_1 ) {
case V_7 :
( void ) F_2 ( V_5 -> V_6 , V_8 ) ;
break;
}
return 1 ;
}
int F_3 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_4 * V_9 = ( T_4 * ) * V_2 ;
F_4 ( V_10 ) * V_11 ;
V_10 * V_12 ;
int V_13 ;
switch( V_1 )
{
case V_14 :
V_9 -> V_15 = NULL ;
V_9 -> V_16 = NULL ;
V_9 -> V_17 = 0 ;
V_9 -> V_18 = 0 ;
V_9 -> V_19 = V_20 ;
V_9 -> V_21 = V_22 ;
V_9 -> V_23 = NULL ;
V_9 -> V_24 = NULL ;
V_9 -> V_25 = NULL ;
V_9 -> V_26 = NULL ;
break;
case V_7 :
#ifndef F_5
F_6 ( V_9 , F_7 () , V_9 -> V_27 , NULL ) ;
#endif
V_9 -> V_15 = F_8 ( V_9 ,
V_28 , NULL , NULL ) ;
if ( V_9 -> V_15 )
F_9 ( V_9 , V_9 -> V_15 ) ;
V_9 -> V_16 = F_8 ( V_9 ,
V_29 , NULL , NULL ) ;
V_9 -> V_25 = F_8 ( V_9 ,
V_30 , NULL , NULL ) ;
V_9 -> V_26 = F_8 ( V_9 ,
V_31 , NULL , NULL ) ;
if ( V_9 -> V_26 && ! V_9 -> V_25 )
V_9 -> V_17 |= V_32 ;
V_11 = V_9 -> V_9 -> V_33 ;
for ( V_13 = 0 ; V_13 < F_10 ( V_11 ) ; V_13 ++ )
{
int V_34 ;
V_12 = F_11 ( V_11 , V_13 ) ;
V_34 = F_12 ( V_12 -> V_35 ) ;
if ( V_34 == V_36 )
V_9 -> V_17 |= V_37 ;
if ( V_12 -> V_38 > 0 )
{
if ( ( V_34 == V_28 )
|| ( V_34 == V_31 ) )
break; ;
V_9 -> V_17 |= V_39 ;
break;
}
}
if ( ! F_13 ( V_9 ) )
return 0 ;
if ( V_9 -> V_21 -> V_40 )
{
if ( V_9 -> V_21 -> V_40 ( V_9 ) == 0 )
return 0 ;
}
break;
case V_41 :
if ( V_9 -> V_21 -> V_42 )
{
if ( ! V_9 -> V_21 -> V_42 ( V_9 ) )
return 0 ;
}
if ( V_9 -> V_16 )
F_14 ( V_9 -> V_16 ) ;
if ( V_9 -> V_15 )
F_15 ( V_9 -> V_15 ) ;
F_16 ( V_9 -> V_25 ) ;
F_16 ( V_9 -> V_26 ) ;
F_17 ( V_9 -> V_24 , V_43 ) ;
break;
}
return 1 ;
}
static void F_9 ( T_4 * V_9 , T_5 * V_15 )
{
int V_44 = 0 ;
V_9 -> V_18 |= V_45 ;
if ( V_15 -> V_46 > 0 )
{
V_44 ++ ;
V_9 -> V_18 |= V_47 ;
}
if ( V_15 -> V_48 > 0 )
{
V_44 ++ ;
V_9 -> V_18 |= V_49 ;
}
if ( V_15 -> V_50 > 0 )
{
V_44 ++ ;
V_9 -> V_18 |= V_51 ;
}
if ( V_44 > 1 )
V_9 -> V_18 |= V_52 ;
if ( V_15 -> V_53 > 0 )
V_9 -> V_18 |= V_54 ;
if ( V_15 -> V_55 )
{
V_9 -> V_18 |= V_56 ;
if ( V_15 -> V_55 -> V_57 > 0 )
V_9 -> V_19 = V_15 -> V_55 -> V_58 [ 0 ] ;
if ( V_15 -> V_55 -> V_57 > 1 )
V_9 -> V_19 |=
( V_15 -> V_55 -> V_58 [ 1 ] << 8 ) ;
V_9 -> V_19 &= V_20 ;
}
F_18 ( V_15 -> V_59 , F_19 ( V_9 ) ) ;
}
int F_20 ( T_4 * V_9 , T_6 * V_60 )
{
T_3 * V_61 ;
V_61 = V_9 -> V_9 ;
if( ! V_61 -> V_6 )
V_61 -> V_6 = F_21 ( V_8 ) ;
if( ! V_61 -> V_6 || ! F_22 ( V_61 -> V_6 , V_60 ) ) {
F_23 ( V_62 , V_63 ) ;
return 0 ;
}
V_61 -> V_64 . V_65 = 1 ;
return 1 ;
}
int F_24 ( T_4 * V_9 , T_7 * V_66 )
{
if ( V_9 -> V_21 -> V_67 )
return V_9 -> V_21 -> V_67 ( V_9 , V_66 ) ;
return 0 ;
}
int F_25 ( T_4 * V_9 ,
T_6 * * V_68 , T_8 * V_69 )
{
if ( V_9 -> V_21 -> V_70 )
return V_9 -> V_21 -> V_70 ( V_9 , V_68 , V_69 , NULL ) ;
return 0 ;
}
int F_26 ( T_4 * V_9 , T_6 * * V_68 , T_9 * V_71 )
{
if ( V_9 -> V_21 -> V_70 )
return V_9 -> V_21 -> V_70 ( V_9 , V_68 ,
F_27 ( V_71 ) ,
F_28 ( V_71 ) ) ;
return 0 ;
}
static int F_29 ( T_4 * V_9 , T_7 * V_66 )
{
return ( F_30 ( F_31 ( T_3 ) ,
V_9 -> V_72 , V_9 -> V_73 , V_9 -> V_9 , V_66 ) ) ;
}
static int F_32 ( T_4 * V_9 , T_10 * V_74 ,
T_6 * V_60 )
{
int V_75 ;
if ( ! V_60 -> V_76 )
{
if ( ! V_74 )
return 1 ;
if ( ! F_33 ( V_74 , F_19 ( V_9 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_74 )
V_74 = F_19 ( V_9 ) ;
for ( V_75 = 0 ; V_75 < F_34 ( V_60 -> V_76 ) ; V_75 ++ )
{
T_11 * V_77 = F_35 ( V_60 -> V_76 , V_75 ) ;
if ( V_77 -> type != V_78 )
continue;
if ( ! F_33 ( V_74 , V_77 -> V_79 . V_80 ) )
return 1 ;
}
return 0 ;
}
static int F_36 ( T_4 * V_9 ,
T_6 * * V_68 , T_8 * V_69 , T_10 * V_76 )
{
T_6 V_81 , * V_60 ;
int V_13 ;
V_81 . V_82 = V_69 ;
if ( ! F_37 ( V_9 -> V_9 -> V_6 ) )
{
F_38 ( V_83 ) ;
F_39 ( V_9 -> V_9 -> V_6 ) ;
F_40 ( V_83 ) ;
}
V_13 = F_41 ( V_9 -> V_9 -> V_6 , & V_81 ) ;
if( V_13 < 0 )
return 0 ;
for(; V_13 < F_42 ( V_9 -> V_9 -> V_6 ) ; V_13 ++ )
{
V_60 = F_43 ( V_9 -> V_9 -> V_6 , V_13 ) ;
if ( F_44 ( V_60 -> V_82 , V_69 ) )
return 0 ;
if ( F_32 ( V_9 , V_76 , V_60 ) )
{
if ( V_68 )
* V_68 = V_60 ;
if ( V_60 -> V_84 == V_85 )
return 2 ;
return 1 ;
}
}
return 0 ;
}
void F_45 ( const T_12 * V_21 )
{
if ( V_21 == NULL )
V_22 = & V_86 ;
else
V_22 = V_21 ;
}
T_12 * F_46 (
int (* V_40)( T_4 * V_9 ) ,
int (* V_42)( T_4 * V_9 ) ,
int (* V_70)( T_4 * V_9 , T_6 * * V_68 ,
T_8 * V_87 , T_10 * V_76 ) ,
int (* V_67)( T_4 * V_9 , T_7 * V_88 ) )
{
T_12 * V_89 ;
V_89 = F_47 ( sizeof( T_12 ) ) ;
if ( ! V_89 )
return NULL ;
V_89 -> V_40 = V_40 ;
V_89 -> V_42 = V_42 ;
V_89 -> V_70 = V_70 ;
V_89 -> V_67 = V_67 ;
V_89 -> V_17 = V_90 ;
return V_89 ;
}
void F_48 ( T_12 * V_89 )
{
if ( ! ( V_89 -> V_17 & V_90 ) )
return;
F_49 ( V_89 ) ;
}
void F_50 ( T_4 * V_9 , void * V_91 )
{
V_9 -> V_23 = V_91 ;
}
void * F_51 ( T_4 * V_9 )
{
return V_9 -> V_23 ;
}
