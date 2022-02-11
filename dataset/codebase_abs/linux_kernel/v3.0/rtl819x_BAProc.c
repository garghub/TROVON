void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 Time )
{
V_3 -> V_4 = true ;
if( Time != 0 )
F_2 ( & V_3 -> V_5 , V_6 + F_3 ( Time ) ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
V_3 -> V_4 = false ;
F_5 ( & V_3 -> V_5 ) ;
}
T_3 F_6 ( struct V_1 * V_2 , T_4 V_7 )
{
T_1 V_8 = & V_7 -> V_9 ;
T_1 V_10 = & V_7 -> V_11 ;
T_3 V_12 = false ;
if( V_10 -> V_4 )
{
F_4 ( V_2 , V_10 ) ;
V_12 = true ;
}
if( V_8 -> V_4 )
{
F_4 ( V_2 , V_8 ) ;
V_12 = true ;
}
return V_12 ;
}
T_3 F_7 ( struct V_1 * V_2 , T_5 V_13 )
{
T_1 V_14 = & V_13 -> V_15 ;
T_3 V_12 = false ;
if( V_14 -> V_4 )
{
F_4 ( V_2 , V_14 ) ;
V_12 = true ;
}
return V_12 ;
}
void F_8 ( T_1 V_3 )
{
V_3 -> V_4 = false ;
V_3 -> V_16 . V_17 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_19 = 0 ;
V_3 -> V_20 . V_21 = 0 ;
}
static struct V_22 * F_9 ( struct V_1 * V_2 , T_3 * V_23 , T_1 V_3 , T_2 V_24 , T_3 type )
{
struct V_22 * V_25 = NULL ;
struct V_26 * V_27 = NULL ;
T_3 * V_28 = NULL ;
T_2 V_29 = 0 ;
T_2 V_30 = V_2 -> V_31 + 9 ;
F_10 ( V_32 | V_33 , L_1 , V_34 , type , V_23 , V_2 -> V_35 ) ;
if ( V_3 == NULL || V_2 == NULL )
{
F_10 ( V_36 , L_2 , V_3 , V_2 ) ;
return NULL ;
}
V_25 = F_11 ( V_30 + sizeof( struct V_26 ) ) ;
if ( V_25 == NULL )
{
F_10 ( V_36 , L_3 ) ;
return NULL ;
}
memset ( V_25 -> V_37 , 0 , sizeof( struct V_26 ) ) ;
F_12 ( V_25 , V_2 -> V_31 ) ;
V_27 = ( struct V_26 * ) F_13 ( V_25 , sizeof( struct V_26 ) ) ;
memcpy ( V_27 -> V_38 , V_23 , V_39 ) ;
memcpy ( V_27 -> V_40 , V_2 -> V_35 -> V_41 , V_39 ) ;
memcpy ( V_27 -> V_42 , V_2 -> V_43 . V_44 , V_39 ) ;
V_27 -> V_45 = F_14 ( V_46 ) ;
V_28 = ( T_3 * ) F_13 ( V_25 , 9 ) ;
* V_28 ++ = V_47 ;
* V_28 ++ = type ;
* V_28 ++ = V_3 -> V_19 ;
if ( V_48 == type )
{
F_15 ( L_4 ) ;
V_29 = F_14 ( V_24 ) ;
memcpy ( V_28 , ( T_3 * ) & V_29 , 2 ) ;
V_28 += 2 ;
}
V_29 = F_14 ( V_3 -> V_16 . V_17 ) ;
memcpy ( V_28 , ( T_3 * ) & V_29 , 2 ) ;
V_28 += 2 ;
V_29 = F_14 ( V_3 -> V_18 ) ;
memcpy ( V_28 , ( T_3 * ) & V_29 , 2 ) ;
V_28 += 2 ;
if ( V_49 == type )
{
memcpy ( V_28 , ( T_3 * ) & ( V_3 -> V_20 ) , 2 ) ;
V_28 += 2 ;
}
F_16 ( V_50 | V_33 , V_25 -> V_37 , V_25 -> V_30 ) ;
return V_25 ;
}
static struct V_22 * F_17 (
struct V_1 * V_2 ,
T_3 * V_51 ,
T_1 V_3 ,
T_6 V_52 ,
T_2 V_53
)
{
T_7 V_54 ;
struct V_22 * V_25 = NULL ;
struct V_26 * V_55 = NULL ;
T_3 * V_28 = NULL ;
T_2 V_29 = 0 ;
T_2 V_30 = 6 + V_2 -> V_31 ;
if ( F_18 () )
F_10 ( V_32 | V_33 , L_5 , V_34 , V_53 , V_51 ) ;
memset ( & V_54 , 0 , 2 ) ;
V_54 . V_56 . V_57 = ( V_52 == V_58 ) ? 1 : 0 ;
V_54 . V_56 . V_59 = V_3 -> V_16 . V_56 . V_59 ;
V_25 = F_11 ( V_30 + sizeof( struct V_26 ) ) ;
if ( V_25 == NULL )
{
F_10 ( V_36 , L_3 ) ;
return NULL ;
}
F_12 ( V_25 , V_2 -> V_31 ) ;
V_55 = ( struct V_26 * ) F_13 ( V_25 , sizeof( struct V_26 ) ) ;
memcpy ( V_55 -> V_38 , V_51 , V_39 ) ;
memcpy ( V_55 -> V_40 , V_2 -> V_35 -> V_41 , V_39 ) ;
memcpy ( V_55 -> V_42 , V_2 -> V_43 . V_44 , V_39 ) ;
V_55 -> V_45 = F_14 ( V_46 ) ;
V_28 = ( T_3 * ) F_13 ( V_25 , 6 ) ;
* V_28 ++ = V_47 ;
* V_28 ++ = V_60 ;
V_29 = F_14 ( V_54 . V_17 ) ;
memcpy ( V_28 , ( T_3 * ) & V_29 , 2 ) ;
V_28 += 2 ;
V_29 = F_14 ( V_53 ) ;
memcpy ( V_28 , ( T_3 * ) & V_29 , 2 ) ;
V_28 += 2 ;
F_16 ( V_50 | V_33 , V_25 -> V_37 , V_25 -> V_30 ) ;
if ( F_18 () )
F_10 ( V_32 | V_33 , L_6 , V_34 ) ;
return V_25 ;
}
void F_19 ( struct V_1 * V_2 , T_3 * V_51 , T_1 V_3 )
{
struct V_22 * V_25 = NULL ;
V_25 = F_9 ( V_2 , V_51 , V_3 , 0 , V_49 ) ;
if ( V_25 )
{
F_20 ( V_25 , V_2 ) ;
}
else
{
F_10 ( V_36 , L_7 , V_34 ) ;
}
}
void F_21 ( struct V_1 * V_2 , T_3 * V_51 , T_1 V_3 , T_2 V_24 )
{
struct V_22 * V_25 = NULL ;
V_25 = F_9 ( V_2 , V_51 , V_3 , V_24 , V_48 ) ;
if ( V_25 )
{
F_20 ( V_25 , V_2 ) ;
}
else
{
F_10 ( V_36 , L_7 , V_34 ) ;
}
}
void F_22 ( struct V_1 * V_2 , T_3 * V_51 , T_1 V_3 , T_6 V_52 , T_2 V_53 )
{
struct V_22 * V_25 = NULL ;
V_25 = F_17 ( V_2 , V_51 , V_3 , V_52 , V_53 ) ;
if ( V_25 )
{
F_20 ( V_25 , V_2 ) ;
}
else
{
F_10 ( V_36 , L_7 , V_34 ) ;
}
return ;
}
int F_23 ( struct V_1 * V_2 , struct V_22 * V_25 )
{
struct V_26 * V_61 = NULL ;
T_2 V_62 = 0 ;
T_3 * V_51 = NULL , * V_63 = NULL , * V_28 = NULL ;
T_1 V_3 = NULL ;
T_8 V_64 = NULL ;
T_2 * V_65 = NULL ;
T_9 V_66 = NULL ;
T_5 V_67 = NULL ;
if ( V_25 -> V_30 < sizeof( struct V_26 ) + 9 )
{
F_10 ( V_36 , L_8 , V_25 -> V_30 , ( sizeof( struct V_26 ) + 9 ) ) ;
return - 1 ;
}
F_16 ( V_50 | V_33 , V_25 -> V_37 , V_25 -> V_30 ) ;
V_61 = ( struct V_26 * ) V_25 -> V_37 ;
V_28 = ( T_3 * ) V_61 ;
V_51 = ( T_3 * ) ( & V_61 -> V_40 [ 0 ] ) ;
V_28 += sizeof( struct V_26 ) ;
V_63 = V_28 + 2 ;
V_64 = ( T_8 ) ( V_28 + 3 ) ;
V_65 = ( T_2 * ) ( V_28 + 5 ) ;
V_66 = ( T_9 ) ( V_61 + 7 ) ;
F_15 ( L_9 , V_51 ) ;
if( ( V_2 -> V_43 . V_68 . V_69 == 0 ) ||
( V_2 -> V_70 -> V_71 == false ) )
{
V_62 = V_72 ;
F_10 ( V_36 , L_10 , V_2 -> V_43 . V_68 . V_69 , V_2 -> V_70 -> V_71 ) ;
goto V_73;
}
if( ! F_24 (
V_2 ,
( V_74 * ) ( & V_67 ) ,
V_51 ,
( T_3 ) ( V_64 -> V_56 . V_59 ) ,
V_75 ,
true ) )
{
V_62 = V_72 ;
F_10 ( V_36 , L_11 , V_34 ) ;
goto V_73;
}
V_3 = & V_67 -> V_15 ;
if( V_64 -> V_56 . V_76 == V_77 )
{
V_62 = V_78 ;
F_10 ( V_36 , L_12 , V_34 ) ;
goto V_73;
}
F_4 ( V_2 , V_3 ) ;
V_3 -> V_19 = * V_63 ;
V_3 -> V_16 = * V_64 ;
V_3 -> V_18 = * V_65 ;
V_3 -> V_20 = * V_66 ;
if ( V_2 -> V_79 ( V_2 ) )
V_3 -> V_16 . V_56 . V_80 = 1 ;
else
V_3 -> V_16 . V_56 . V_80 = 32 ;
F_1 ( V_2 , V_3 , V_3 -> V_18 ) ;
F_21 ( V_2 , V_51 , V_3 , V_81 ) ;
return 0 ;
V_73:
{
T_10 V_82 ;
V_82 . V_16 = * V_64 ;
V_82 . V_18 = * V_65 ;
V_82 . V_19 = * V_63 ;
V_82 . V_16 . V_56 . V_76 = V_83 ;
F_21 ( V_2 , V_51 , & V_82 , V_62 ) ;
return 0 ;
}
}
int F_25 ( struct V_1 * V_2 , struct V_22 * V_25 )
{
struct V_26 * V_84 = NULL ;
T_1 V_85 , V_86 ;
T_4 V_67 = NULL ;
T_3 * V_51 = NULL , * V_63 = NULL , * V_28 = NULL ;
T_2 * V_87 = NULL , * V_65 = NULL ;
T_8 V_64 = NULL ;
T_2 V_53 ;
if ( V_25 -> V_30 < sizeof( struct V_26 ) + 9 )
{
F_10 ( V_36 , L_13 , V_25 -> V_30 , ( sizeof( struct V_26 ) + 9 ) ) ;
return - 1 ;
}
V_84 = ( struct V_26 * ) V_25 -> V_37 ;
V_28 = ( T_3 * ) V_84 ;
V_51 = ( T_3 * ) ( & V_84 -> V_40 [ 0 ] ) ;
V_28 += sizeof( struct V_26 ) ;
V_63 = V_28 + 2 ;
V_87 = ( T_2 * ) ( V_28 + 3 ) ;
V_64 = ( T_8 ) ( V_28 + 5 ) ;
V_65 = ( T_2 * ) ( V_28 + 7 ) ;
if( V_2 -> V_43 . V_68 . V_69 == 0 ||
V_2 -> V_70 -> V_71 == false ||
V_2 -> V_70 -> V_88 == false )
{
F_10 ( V_36 , L_14 , V_2 -> V_43 . V_68 . V_69 , V_2 -> V_70 -> V_71 , V_2 -> V_70 -> V_88 ) ;
V_53 = V_89 ;
goto V_90;
}
if ( ! F_24 (
V_2 ,
( V_74 * ) ( & V_67 ) ,
V_51 ,
( T_3 ) ( V_64 -> V_56 . V_59 ) ,
V_58 ,
false ) )
{
F_10 ( V_36 , L_11 , V_34 ) ;
V_53 = V_89 ;
goto V_90;
}
V_67 -> V_91 = false ;
V_85 = & V_67 -> V_11 ;
V_86 = & V_67 -> V_9 ;
if( ( V_86 -> V_4 == true ) )
{
F_10 ( V_33 , L_15 ) ;
return - 1 ;
}
else if( ( V_85 -> V_4 == false ) || ( * V_63 != V_85 -> V_19 ) )
{
F_10 ( V_36 , L_16 ) ;
V_53 = V_89 ;
goto V_90;
}
else
{
F_10 ( V_33 , L_17 , * V_87 ) ;
F_4 ( V_2 , V_85 ) ;
}
if( * V_87 == V_81 )
{
if( V_64 -> V_56 . V_76 == V_77 )
{
V_67 -> V_92 = true ;
F_4 ( V_2 , V_86 ) ;
V_53 = V_93 ;
goto V_90;
}
V_86 -> V_19 = * V_63 ;
V_86 -> V_18 = * V_65 ;
V_86 -> V_20 = V_85 -> V_20 ;
V_86 -> V_16 = * V_64 ;
F_4 ( V_2 , V_86 ) ;
F_1 ( V_2 , V_86 , * V_65 ) ;
}
else
{
V_67 -> V_92 = true ;
}
return 0 ;
V_90:
{
T_10 V_82 ;
V_82 . V_16 = * V_64 ;
F_22 ( V_2 , V_51 , & V_82 , V_58 , V_53 ) ;
return 0 ;
}
}
int F_26 ( struct V_1 * V_2 , struct V_22 * V_25 )
{
struct V_26 * V_94 = NULL ;
T_11 V_95 = NULL ;
T_2 * V_96 = NULL ;
T_3 * V_51 = NULL ;
if ( V_25 -> V_30 < sizeof( struct V_26 ) + 6 )
{
F_10 ( V_36 , L_18 , V_25 -> V_30 , ( sizeof( struct V_26 ) + 6 ) ) ;
return - 1 ;
}
if( V_2 -> V_43 . V_68 . V_69 == 0 ||
V_2 -> V_70 -> V_71 == false )
{
F_10 ( V_36 , L_19 , V_2 -> V_43 . V_68 . V_69 , V_2 -> V_70 -> V_71 ) ;
return - 1 ;
}
F_16 ( V_50 | V_33 , V_25 -> V_37 , V_25 -> V_30 ) ;
V_94 = ( struct V_26 * ) V_25 -> V_37 ;
V_51 = ( T_3 * ) ( & V_94 -> V_40 [ 0 ] ) ;
V_94 += sizeof( struct V_26 ) ;
V_95 = ( T_11 ) ( V_94 + 2 ) ;
V_96 = ( T_2 * ) ( V_94 + 4 ) ;
if( V_95 -> V_56 . V_57 == 1 )
{
T_5 V_13 ;
if( ! F_24 (
V_2 ,
( V_74 * ) & V_13 ,
V_51 ,
( T_3 ) V_95 -> V_56 . V_59 ,
V_75 ,
false ) )
{
F_10 ( V_36 , L_20 , V_34 ) ;
return - 1 ;
}
F_7 ( V_2 , V_13 ) ;
}
else
{
T_4 V_7 ;
if( ! F_24 (
V_2 ,
( V_74 * ) & V_7 ,
V_51 ,
( T_3 ) V_95 -> V_56 . V_59 ,
V_58 ,
false ) )
{
F_10 ( V_36 , L_21 , V_34 ) ;
return - 1 ;
}
V_7 -> V_97 = false ;
V_7 -> V_91 = false ;
V_7 -> V_92 = false ;
F_5 ( & V_7 -> V_98 ) ;
F_6 ( V_2 , V_7 ) ;
}
return 0 ;
}
void
F_27 (
struct V_1 * V_2 ,
T_4 V_67 ,
T_3 V_99 ,
T_3 V_100
)
{
T_1 V_3 = & V_67 -> V_11 ;
if( V_3 -> V_4 == true && V_100 == false )
return;
F_4 ( V_2 , V_3 ) ;
V_3 -> V_19 ++ ;
V_3 -> V_16 . V_56 . V_101 = 0 ;
V_3 -> V_16 . V_56 . V_76 = V_99 ;
V_3 -> V_16 . V_56 . V_59 = V_67 -> V_102 . V_103 . V_104 . V_105 . V_56 . V_106 ;
V_3 -> V_16 . V_56 . V_80 = 32 ;
V_3 -> V_18 = 0 ;
V_3 -> V_20 . V_56 . V_107 = ( V_67 -> V_108 + 3 ) % 4096 ;
F_1 ( V_2 , V_3 , V_109 ) ;
F_19 ( V_2 , V_67 -> V_102 . V_110 , V_3 ) ;
}
void
F_28 ( struct V_1 * V_2 , V_74 V_111 , T_6 V_52 )
{
if( V_52 == V_58 )
{
T_4 V_7 = ( T_4 ) V_111 ;
if( F_6 ( V_2 , V_7 ) )
F_22 (
V_2 ,
V_111 -> V_110 ,
( V_7 -> V_9 . V_4 ) ? ( & V_7 -> V_9 ) : ( & V_7 -> V_11 ) ,
V_52 ,
V_93 ) ;
}
else if( V_52 == V_75 )
{
T_5 V_13 = ( T_5 ) V_111 ;
if( F_7 ( V_2 , V_13 ) )
F_22 (
V_2 ,
V_111 -> V_110 ,
& V_13 -> V_15 ,
V_52 ,
V_93 ) ;
}
}
void F_29 ( unsigned long V_37 )
{
T_4 V_7 = ( T_4 ) V_37 ;
V_7 -> V_91 = false ;
V_7 -> V_92 = true ;
V_7 -> V_11 . V_4 = false ;
}
void F_30 ( unsigned long V_37 )
{
T_4 V_7 = ( T_4 ) V_37 ;
struct V_1 * V_2 = F_31 ( V_7 , struct V_1 , V_112 [ V_7 -> V_113 ] ) ;
F_6 ( V_2 , V_7 ) ;
F_22 (
V_2 ,
V_7 -> V_102 . V_110 ,
& V_7 -> V_9 ,
V_58 ,
V_114 ) ;
}
void F_32 ( unsigned long V_37 )
{
T_5 V_13 = ( T_5 ) V_37 ;
struct V_1 * V_2 = F_31 ( V_13 , struct V_1 , V_115 [ V_13 -> V_113 ] ) ;
F_7 ( V_2 , V_13 ) ;
F_22 (
V_2 ,
V_13 -> V_102 . V_110 ,
& V_13 -> V_15 ,
V_75 ,
V_114 ) ;
}
