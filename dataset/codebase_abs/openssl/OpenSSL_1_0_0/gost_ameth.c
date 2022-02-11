int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_3 * V_3 = F_2 () ;
for ( V_2 = V_4 ; V_2 -> V_3 != NULL ; V_2 ++ )
{
F_3 ( & V_3 , V_2 -> V_3 ) ;
if ( ! F_4 ( V_3 , V_1 -> V_3 ) )
{
F_5 ( V_3 ) ;
return V_2 -> V_5 ;
}
}
F_5 ( V_3 ) ;
return V_6 ;
}
static T_4 * F_6 ( const T_5 * V_7 )
{
T_4 * V_8 = F_7 () ;
T_6 * V_9 = F_8 () ;
int V_10 = V_6 ;
int V_11 = V_6 ;
if ( ! V_8 || ! V_9 )
{
F_9 ( V_12 ,
V_13 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
goto V_14;
}
switch ( F_11 ( V_7 ) )
{
case V_15 :
V_10 = F_12 ( F_13 ( F_14 ( ( T_5 * ) V_7 ) ) ) ;
V_11 = F_15 ( NULL ) -> V_5 ;
break;
case V_16 :
V_10 = ( int ) F_1 ( F_14 ( ( T_5 * ) V_7 ) ) ;
if ( V_10 == V_6 )
{
F_9 ( V_12 ,
V_17 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
goto V_14;
}
V_11 = F_15 ( NULL ) -> V_5 ;
break;
}
V_9 -> V_18 = F_16 ( V_10 ) ;
V_9 -> V_19 = F_16 ( V_20 ) ;
V_8 -> V_21 = F_17 ( V_9 , & V_8 -> V_22 ) ;
if ( V_8 -> V_21 <= 0 )
{
F_9 ( V_12 ,
V_13 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
goto V_14;
}
V_8 -> type = V_23 ;
V_14:
F_18 ( V_9 ) ;
return V_8 ;
}
static int F_19 ( T_5 * V_24 , T_7 * V_25 )
{
T_8 * V_26 = NULL ;
int V_27 = V_28 ;
int V_29 = V_6 , V_30 = V_6 ;
void * V_31 ;
T_4 * V_32 = NULL ;
const unsigned char * V_1 ;
T_6 * V_9 = NULL ;
F_20 ( & V_26 , & V_27 , & V_31 , V_25 ) ;
V_32 = V_31 ;
if ( V_27 != V_23 )
{
F_9 ( V_33 ,
V_34 ) ;
return 0 ;
}
V_1 = V_32 -> V_22 ;
V_29 = F_21 ( V_26 ) ;
V_9 = F_22 ( NULL , & V_1 , V_32 -> V_21 ) ;
if ( ! V_9 )
{
F_9 ( V_33 ,
V_35 ) ;
return 0 ;
}
V_30 = F_21 ( V_9 -> V_18 ) ;
F_18 ( V_9 ) ;
F_23 ( V_24 , V_29 ) ;
switch ( V_29 )
{
case V_16 :
{
T_1 * V_36 = F_14 ( V_24 ) ;
if ( ! V_36 )
{
V_36 = F_24 () ;
if ( ! F_25 ( V_24 , V_29 , V_36 ) ) return 0 ;
}
if ( ! F_26 ( V_36 , V_30 ) ) return 0 ;
break;
}
case V_15 :
{
T_9 * V_37 = F_14 ( V_24 ) ;
if ( ! V_37 )
{
V_37 = F_27 () ;
if ( ! F_25 ( V_24 , V_29 , V_37 ) ) return 0 ;
}
if ( ! F_28 ( V_37 , V_30 ) ) return 0 ;
}
}
return 1 ;
}
static int F_29 ( T_5 * V_24 , T_3 * V_38 )
{
switch ( F_11 ( V_24 ) )
{
case V_16 :
{
T_1 * V_36 = F_14 ( V_24 ) ;
if ( ! V_36 )
{
V_36 = F_24 () ;
F_25 ( V_24 , F_11 ( V_24 ) , V_36 ) ;
}
V_36 -> V_39 = F_30 ( V_38 ) ;
if ( ! F_31 ( V_24 ) )
F_32 ( V_36 ) ;
break;
}
case V_15 :
{
T_9 * V_37 = F_14 ( V_24 ) ;
if ( ! V_37 )
{
V_37 = F_27 () ;
F_25 ( V_24 , F_11 ( V_24 ) , V_37 ) ;
}
if ( ! F_33 ( V_37 , V_38 ) ) return 0 ;
if ( ! F_31 ( V_24 ) )
F_34 ( V_37 ) ;
break;
}
}
return 1 ;
}
T_3 * F_35 ( const T_5 * V_24 )
{
switch ( F_11 ( V_24 ) )
{
case V_16 :
{
T_1 * V_36 = F_14 ( ( T_5 * ) V_24 ) ;
if ( ! V_36 )
{
return NULL ;
}
if ( ! V_36 -> V_39 ) return NULL ;
return V_36 -> V_39 ;
break;
}
case V_15 :
{
T_9 * V_37 = F_14 ( ( T_5 * ) V_24 ) ;
const T_3 * V_38 ;
if ( ! V_37 )
{
return NULL ;
}
if ( ! ( V_38 = F_36 ( V_37 ) ) ) return NULL ;
return ( T_3 * ) V_38 ;
break;
}
}
return NULL ;
}
static int F_37 ( T_5 * V_24 , int V_40 ,
long V_41 , void * V_42 )
{
switch ( V_40 )
{
case V_43 :
if ( V_41 == 0 )
{
T_7 * V_44 = NULL , * V_45 = NULL ;
int V_5 = F_11 ( V_24 ) ;
F_38 ( ( V_46 * ) V_42 ,
NULL , & V_44 , & V_45 ) ;
F_39 ( V_44 , F_16 ( V_47 ) ,
V_48 , 0 ) ;
if ( V_5 == V_6 )
{
return ( - 1 ) ;
}
F_39 ( V_45 , F_16 ( V_5 ) , V_48 , 0 ) ;
}
return 1 ;
case V_49 :
if ( V_41 == 0 )
{
T_7 * V_50 ;
T_4 * V_8 = F_6 ( V_24 ) ;
if ( ! V_8 )
{
return - 1 ;
}
F_40 ( ( V_51 * ) V_42 , & V_50 ) ;
F_39 ( V_50 , F_16 ( V_24 -> type ) ,
V_23 , V_8 ) ;
}
return 1 ;
case V_52 :
* ( int * ) V_42 = V_47 ;
return 2 ;
}
return - 2 ;
}
static void F_41 ( T_5 * V_7 )
{
if ( V_7 -> V_24 . V_36 )
{
F_42 ( V_7 -> V_24 . V_36 ) ;
}
}
static void F_43 ( T_5 * V_7 )
{
if ( V_7 -> V_24 . V_37 )
{
F_44 ( V_7 -> V_24 . V_37 ) ;
}
}
static int F_45 ( T_5 * V_53 , T_10 * V_54 )
{
const unsigned char * V_55 = NULL , * V_1 = NULL ;
int V_56 = 0 ;
T_3 * V_57 = NULL ;
int V_58 = 0 ;
T_7 * V_25 = NULL ;
T_8 * V_26 = NULL ;
T_11 * V_39 = NULL ;
if ( ! F_46 ( & V_26 , & V_55 , & V_56 , & V_25 , V_54 ) )
return 0 ;
V_1 = V_55 ;
if ( ! F_19 ( V_53 , V_25 ) )
{
return 0 ;
}
if ( V_59 == * V_1 )
{
unsigned char V_60 [ 32 ] ;
int V_61 ;
T_12 * V_62 = F_47 ( NULL , & V_1 , V_56 ) ;
if ( ! V_62 || V_62 -> V_21 != 32 )
{
F_9 ( V_63 ,
V_64 ) ;
return 0 ;
}
for ( V_61 = 0 ; V_61 < 32 ; V_61 ++ )
{
V_60 [ 31 - V_61 ] = V_62 -> V_22 [ V_61 ] ;
}
F_10 ( V_62 ) ;
V_57 = F_48 ( V_60 , 32 ) ;
}
else
{
V_39 = F_49 ( NULL , & V_1 , V_56 ) ;
if ( ! V_39 ) return 0 ;
V_58 = ( ( V_57 = F_50 ( V_39 , NULL ) ) != NULL ) ;
F_51 ( V_39 ) ;
if ( ! V_58 )
{
F_9 ( V_63 ,
V_64 ) ;
return 0 ;
}
}
V_58 = F_29 ( V_53 , V_57 ) ;
F_5 ( V_57 ) ;
return V_58 ;
}
static int F_52 ( T_10 * V_65 , const T_5 * V_53 )
{
T_8 * V_66 = F_16 ( F_11 ( V_53 ) ) ;
T_4 * V_8 = F_6 ( V_53 ) ;
unsigned char * V_67 = NULL ;
int V_56 ;
T_11 * V_68 = NULL ;
if ( ! V_8 )
{
return 0 ;
}
V_68 = F_53 ( F_35 ( V_53 ) , NULL ) ;
V_56 = F_54 ( V_68 , & V_67 ) ;
F_51 ( V_68 ) ;
return F_55 ( V_65 , V_66 , 0 , V_23 , V_8 ,
V_67 , V_56 ) ;
}
static int F_56 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 , int type )
{
int V_30 = V_6 ;
if ( type == 2 )
{
T_3 * V_7 ;
if ( ! F_57 ( V_69 , V_70 , 128 ) ) return 0 ;
F_58 ( V_69 , L_1 ) ;
V_7 = F_35 ( V_24 ) ;
if ( ! V_7 )
F_58 ( V_69 , L_2 ) ;
else
F_59 ( V_69 , V_7 ) ;
F_58 ( V_69 , L_3 ) ;
}
if ( type >= 1 )
{
T_3 * V_72 ;
V_72 = ( ( T_1 * ) F_14 ( ( T_5 * ) V_24 ) ) -> V_73 ;
F_57 ( V_69 , V_70 , 128 ) ;
F_58 ( V_69 , L_4 ) ;
F_59 ( V_69 , V_72 ) ;
F_58 ( V_69 , L_3 ) ;
}
V_30 = F_1 ( F_14 ( ( T_5 * ) V_24 ) ) ;
F_57 ( V_69 , V_70 , 128 ) ;
F_58 ( V_69 , L_5 , F_60 ( V_30 ) ) ;
return 1 ;
}
static int F_61 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 )
{
return F_56 ( V_69 , V_24 , V_70 , V_71 , 0 ) ;
}
static int F_62 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 )
{
return F_56 ( V_69 , V_24 , V_70 , V_71 , 1 ) ;
}
static int F_63 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 )
{
return F_56 ( V_69 , V_24 , V_70 , V_71 , 2 ) ;
}
static int F_64 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 , int type )
{
int V_30 = V_6 ;
if ( type == 2 )
{
T_3 * V_7 ;
if ( ! F_57 ( V_69 , V_70 , 128 ) ) return 0 ;
F_58 ( V_69 , L_1 ) ;
V_7 = F_35 ( V_24 ) ;
if ( ! V_7 )
F_58 ( V_69 , L_6 ) ;
else
F_59 ( V_69 , V_7 ) ;
F_58 ( V_69 , L_3 ) ;
}
if ( type >= 1 )
{
T_15 * V_74 = F_65 () ;
T_3 * V_75 , * V_76 ;
const T_16 * V_72 ;
const T_17 * V_77 ;
if ( ! V_74 )
{
F_9 ( V_78 , V_13 ) ;
return 0 ;
}
F_66 ( V_74 ) ;
V_75 = F_67 ( V_74 ) ;
V_76 = F_67 ( V_74 ) ;
V_72 = F_68 ( ( T_9 * ) F_14 ( ( T_5 * ) V_24 ) ) ;
V_77 = F_13 ( ( T_9 * ) F_14 ( ( T_5 * ) V_24 ) ) ;
if ( ! F_69 ( V_77 , V_72 , V_75 , V_76 , V_74 ) )
{
F_9 ( V_78 , V_79 ) ;
F_70 ( V_74 ) ;
return 0 ;
}
if ( ! F_57 ( V_69 , V_70 , 128 ) ) return 0 ;
F_58 ( V_69 , L_7 ) ;
if ( ! F_57 ( V_69 , V_70 + 3 , 128 ) ) return 0 ;
F_58 ( V_69 , L_8 ) ;
F_59 ( V_69 , V_75 ) ;
F_58 ( V_69 , L_3 ) ;
F_57 ( V_69 , V_70 + 3 , 128 ) ;
F_58 ( V_69 , L_9 ) ;
F_59 ( V_69 , V_76 ) ;
F_58 ( V_69 , L_3 ) ;
F_71 ( V_74 ) ;
F_70 ( V_74 ) ;
}
V_30 = F_12 ( F_13 ( F_14 ( ( T_5 * ) V_24 ) ) ) ;
if ( ! F_57 ( V_69 , V_70 , 128 ) ) return 0 ;
F_58 ( V_69 , L_5 , F_60 ( V_30 ) ) ;
return 1 ;
}
static int F_72 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 )
{
return F_64 ( V_69 , V_24 , V_70 , V_71 , 0 ) ;
}
static int F_73 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 )
{
return F_64 ( V_69 , V_24 , V_70 , V_71 , 1 ) ;
}
static int F_74 ( T_13 * V_69 , const T_5 * V_24 , int V_70 ,
T_14 * V_71 )
{
return F_64 ( V_69 , V_24 , V_70 , V_71 , 2 ) ;
}
static int F_75 ( const T_5 * V_53 )
{
const T_1 * V_36 = F_14 ( ( T_5 * ) V_53 ) ;
if ( ! V_36 ) return 1 ;
if ( ! V_36 -> V_3 ) return 1 ;
return 0 ;
}
static int F_76 ( const T_5 * V_53 )
{
const T_9 * V_37 = F_14 ( ( T_5 * ) V_53 ) ;
if ( ! V_37 ) return 1 ;
if ( ! F_13 ( V_37 ) ) return 1 ;
return 0 ;
}
static int F_77 ( T_5 * V_80 , const T_5 * V_81 )
{
const T_1 * V_82 = F_14 ( ( T_5 * ) V_81 ) ;
T_1 * V_83 = F_14 ( V_80 ) ;
if ( F_11 ( V_81 ) != F_11 ( V_80 ) )
{
F_9 ( V_84 ,
V_85 ) ;
return 0 ;
}
if ( ! V_82 )
{
F_9 ( V_84 ,
V_86 ) ;
return 0 ;
}
if ( ! V_83 )
{
V_83 = F_24 () ;
F_25 ( V_80 , F_11 ( V_81 ) , V_83 ) ;
}
#define F_78 ( T_18 , T_19 , T_20 ) if (a->x) BN_free(a->x); a->x=BN_dup(b->x);
F_78 (dto,dfrom,p)
F_78 (dto,dfrom,q)
F_78 (dto,dfrom,g)
if ( V_83 -> V_39 )
F_32 ( V_83 ) ;
return 1 ;
}
static int F_79 ( T_5 * V_80 , const T_5 * V_81 )
{
T_9 * V_87 = F_14 ( V_80 ) ;
const T_9 * V_88 = F_14 ( ( T_5 * ) V_81 ) ;
if ( F_11 ( V_81 ) != F_11 ( V_80 ) )
{
F_9 ( V_89 ,
V_85 ) ;
return 0 ;
}
if ( ! V_88 )
{
F_9 ( V_89 ,
V_86 ) ;
return 0 ;
}
if ( ! V_87 )
{
V_87 = F_27 () ;
F_25 ( V_80 , F_11 ( V_81 ) , V_87 ) ;
}
F_80 ( V_87 , F_13 ( V_88 ) ) ;
if ( F_36 ( V_87 ) )
{
F_34 ( V_87 ) ;
}
return 1 ;
}
static int F_81 ( const T_5 * T_18 , const T_5 * T_19 )
{
const T_1 * V_90 = F_14 ( ( T_5 * ) T_18 ) ;
const T_1 * V_91 = F_14 ( ( T_5 * ) T_19 ) ;
if ( ! F_4 ( V_90 -> V_3 , V_91 -> V_3 ) ) return 1 ;
return 0 ;
}
static int F_82 ( const T_5 * T_18 , const T_5 * T_19 )
{
if ( F_12 ( F_13 ( F_14 ( ( T_5 * ) T_18 ) ) ) ==
F_12 ( F_13 ( F_14 ( ( T_5 * ) T_19 ) ) ) )
{
return 1 ;
}
return 0 ;
}
static int F_83 ( T_5 * V_53 , T_21 * V_92 )
{
T_7 * V_25 = NULL ;
const unsigned char * V_93 = NULL ;
unsigned char * V_94 ;
T_8 * V_95 = NULL ;
int V_96 , V_61 , V_97 ;
T_1 * V_36 ;
T_12 * V_98 = NULL ;
if ( ! F_84 ( & V_95 , & V_93 , & V_96 ,
& V_25 , V_92 ) ) return 0 ;
F_25 ( V_53 , F_21 ( V_95 ) , NULL ) ;
if ( ! F_19 ( V_53 , V_25 ) ) return 0 ;
V_98 = F_47 ( NULL , & V_93 , V_96 ) ;
if ( ! V_98 )
{
F_9 ( V_99 , V_13 ) ;
return 0 ;
}
V_94 = F_85 ( V_98 -> V_21 ) ;
for ( V_61 = 0 , V_97 = V_98 -> V_21 - 1 ; V_61 < V_98 -> V_21 ; V_61 ++ , V_97 -- )
{
V_94 [ V_97 ] = V_98 -> V_22 [ V_61 ] ;
}
V_36 = F_14 ( V_53 ) ;
V_36 -> V_73 = F_86 ( V_94 , V_98 -> V_21 , NULL ) ;
F_87 ( V_98 ) ;
F_88 ( V_94 ) ;
return 1 ;
}
static int F_89 ( T_21 * V_92 , const T_5 * V_53 )
{
T_8 * V_66 = NULL ;
T_12 * V_98 = NULL ;
void * V_32 = NULL ;
unsigned char * V_100 = NULL , * V_94 , * V_101 ;
int V_61 , V_97 , V_102 , V_58 = 0 ;
int V_27 = V_28 ;
T_1 * V_36 = F_14 ( ( T_5 * ) V_53 ) ;
V_66 = F_16 ( F_11 ( V_53 ) ) ;
if ( V_53 -> V_103 )
{
T_4 * V_8 = F_6 ( V_53 ) ;
V_32 = V_8 ;
V_27 = V_23 ;
}
V_102 = F_90 ( V_36 -> V_73 ) ;
V_94 = F_85 ( V_102 ) ;
F_91 ( V_36 -> V_73 , V_94 ) ;
V_98 = F_92 () ;
F_93 ( V_98 , NULL , V_102 ) ;
V_101 = F_94 ( V_98 ) ;
for ( V_61 = 0 , V_97 = V_102 - 1 ; V_61 < V_102 ; V_61 ++ , V_97 -- )
{
V_101 [ V_61 ] = V_94 [ V_97 ] ;
}
F_88 ( V_94 ) ;
V_58 = F_95 ( V_98 , & V_100 ) ;
F_96 ( V_98 ) ;
if ( V_58 < 0 ) return 0 ;
return F_97 ( V_92 , V_66 , V_27 , V_32 , V_100 , V_58 ) ;
}
static int F_98 ( T_5 * V_53 , T_21 * V_92 )
{
T_7 * V_25 = NULL ;
const unsigned char * V_93 = NULL ;
unsigned char * V_94 ;
T_8 * V_95 = NULL ;
int V_96 , V_61 , V_97 ;
T_16 * V_73 ;
T_3 * V_75 , * V_76 ;
T_12 * V_98 = NULL ;
int V_104 ;
const T_17 * V_77 ;
if ( ! F_84 ( & V_95 , & V_93 , & V_96 ,
& V_25 , V_92 ) ) return 0 ;
F_25 ( V_53 , F_21 ( V_95 ) , NULL ) ;
if ( ! F_19 ( V_53 , V_25 ) ) return 0 ;
V_77 = F_13 ( F_14 ( V_53 ) ) ;
V_98 = F_47 ( NULL , & V_93 , V_96 ) ;
if ( ! V_98 )
{
F_9 ( V_105 , V_13 ) ;
return 0 ;
}
V_94 = F_85 ( V_98 -> V_21 ) ;
for ( V_61 = 0 , V_97 = V_98 -> V_21 - 1 ; V_61 < V_98 -> V_21 ; V_61 ++ , V_97 -- )
{
V_94 [ V_97 ] = V_98 -> V_22 [ V_61 ] ;
}
V_104 = V_98 -> V_21 / 2 ;
F_87 ( V_98 ) ;
V_76 = F_48 ( V_94 , V_104 ) ;
V_75 = F_48 ( V_94 + V_104 , V_104 ) ;
F_88 ( V_94 ) ;
V_73 = F_99 ( V_77 ) ;
if ( ! F_100 ( V_77
, V_73 , V_75 , V_76 , NULL ) )
{
F_9 ( V_105 ,
V_79 ) ;
F_101 ( V_73 ) ;
F_5 ( V_75 ) ;
F_5 ( V_76 ) ;
return 0 ;
}
F_5 ( V_75 ) ;
F_5 ( V_76 ) ;
if ( ! F_102 ( F_14 ( V_53 ) , V_73 ) )
{
F_9 ( V_105 ,
V_79 ) ;
F_101 ( V_73 ) ;
return 0 ;
}
F_101 ( V_73 ) ;
return 1 ;
}
static int F_103 ( T_21 * V_92 , const T_5 * V_53 )
{
T_8 * V_66 = NULL ;
T_12 * V_98 = NULL ;
void * V_32 = NULL ;
unsigned char * V_100 = NULL , * V_94 , * V_101 ;
int V_61 , V_97 , V_102 , V_58 = 0 ;
const T_16 * V_73 ;
T_3 * V_75 , * V_76 , * V_106 ;
const T_9 * V_37 = F_14 ( ( T_5 * ) V_53 ) ;
int V_27 = V_28 ;
V_66 = F_16 ( F_11 ( V_53 ) ) ;
if ( V_53 -> V_103 )
{
T_4 * V_8 = F_6 ( V_53 ) ;
V_32 = V_8 ;
V_27 = V_23 ;
}
V_106 = F_2 () ;
F_104 ( F_13 ( V_37 ) , V_106 , NULL ) ;
V_73 = F_68 ( V_37 ) ;
if ( ! V_73 )
{
F_9 ( V_107 ,
V_108 ) ;
return 0 ;
}
V_75 = F_2 () ;
V_76 = F_2 () ;
F_69 ( F_13 ( V_37 ) ,
V_73 , V_75 , V_76 , NULL ) ;
V_102 = 2 * F_90 ( V_106 ) ;
F_5 ( V_106 ) ;
V_94 = F_85 ( V_102 ) ;
memset ( V_94 , 0 , V_102 ) ;
F_105 ( V_75 , V_94 + V_102 / 2 , V_102 / 2 ) ;
F_105 ( V_76 , V_94 , V_102 / 2 ) ;
F_5 ( V_75 ) ;
F_5 ( V_76 ) ;
V_98 = F_92 () ;
F_93 ( V_98 , NULL , V_102 ) ;
V_101 = F_94 ( V_98 ) ;
for ( V_61 = 0 , V_97 = V_102 - 1 ; V_61 < V_102 ; V_61 ++ , V_97 -- )
{
V_101 [ V_61 ] = V_94 [ V_97 ] ;
}
F_88 ( V_94 ) ;
V_58 = F_95 ( V_98 , & V_100 ) ;
F_96 ( V_98 ) ;
if ( V_58 < 0 ) return 0 ;
return F_97 ( V_92 , V_66 , V_27 , V_32 , V_100 , V_58 ) ;
}
static int F_106 ( const T_5 * T_18 , const T_5 * T_19 )
{
const T_1 * V_90 = F_14 ( ( T_5 * ) T_18 ) ;
const T_1 * V_91 = F_14 ( ( T_5 * ) T_19 ) ;
if ( V_90 && V_91 && V_90 -> V_73 && V_91 -> V_73
&& ! F_4 ( V_90 -> V_73 , V_91 -> V_73 ) )
{
return 1 ;
}
return 0 ;
}
static int F_107 ( const T_5 * T_18 , const T_5 * T_19 )
{
const T_9 * V_109 = F_14 ( ( T_5 * ) T_18 ) ;
const T_9 * V_110 = F_14 ( ( T_5 * ) T_19 ) ;
const T_16 * V_111 , * V_112 ;
int V_58 = 0 ;
if ( ! V_109 || ! V_110 ) return 0 ;
V_111 = F_68 ( V_109 ) ;
V_112 = F_68 ( V_110 ) ;
if ( ! V_111 || ! V_112 ) return 0 ;
V_58 = ( 0 == F_108 ( F_13 ( V_109 ) , V_111 , V_112 , NULL ) ) ;
return V_58 ;
}
static int F_109 ( const T_5 * V_53 )
{
return 64 ;
}
static int F_110 ( const T_5 * V_53 )
{
return 256 ;
}
static void F_111 ( T_5 * V_53 )
{
if ( V_53 -> V_24 . V_113 ) {
F_88 ( V_53 -> V_24 . V_113 ) ;
}
}
static int F_112 ( T_5 * V_24 , int V_40 , long V_41 , void * V_42 )
{
switch ( V_40 )
{
case V_52 :
* ( int * ) V_42 = V_6 ;
return 2 ;
}
return - 2 ;
}
static int F_113 ( const T_5 * V_24 , unsigned char * * V_114 )
{
int V_5 = F_1 ( F_14 ( ( T_5 * ) V_24 ) ) ;
return F_114 ( F_16 ( V_5 ) , V_114 ) ;
}
static int F_115 ( const T_5 * V_24 , unsigned char * * V_114 )
{
int V_5 = F_12 ( F_13 ( F_14 ( ( T_5 * ) V_24 ) ) ) ;
return F_114 ( F_16 ( V_5 ) , V_114 ) ;
}
static int F_116 ( T_5 * V_24 , const unsigned char * * V_114 , int V_115 )
{
T_8 * V_116 = NULL ;
T_1 * V_36 = F_14 ( V_24 ) ;
int V_5 ;
if ( F_117 ( & V_116 , V_114 , V_115 ) == NULL ) {
return 0 ;
}
V_5 = F_21 ( V_116 ) ;
F_118 ( V_116 ) ;
if ( ! V_36 )
{
V_36 = F_24 () ;
if ( ! F_25 ( V_24 , V_16 , V_36 ) ) return 0 ;
}
if ( ! F_26 ( V_36 , V_5 ) ) return 0 ;
return 1 ;
}
static int F_119 ( T_5 * V_24 , const unsigned char * * V_114 , int V_115 ) {
T_8 * V_116 = NULL ;
int V_5 ;
T_9 * V_37 = F_14 ( V_24 ) ;
if ( F_117 ( & V_116 , V_114 , V_115 ) == NULL ) {
return 0 ;
}
V_5 = F_21 ( V_116 ) ;
F_118 ( V_116 ) ;
if ( ! V_37 )
{
V_37 = F_27 () ;
if ( ! F_25 ( V_24 , V_15 , V_37 ) ) return 0 ;
}
if ( ! F_28 ( V_37 , V_5 ) ) return 0 ;
return 1 ;
}
int F_120 ( int V_5 , T_22 * * V_117 , const char * V_118 , const char * V_119 )
{
* V_117 = F_121 ( V_5 ,
V_120 , V_118 , V_119 ) ;
if ( ! * V_117 ) return 0 ;
switch ( V_5 )
{
case V_16 :
F_122 ( * V_117 , F_41 ) ;
F_123 ( * V_117 ,
F_45 , F_52 ,
F_63 ) ;
F_124 ( * V_117 ,
F_116 , F_113 ,
F_75 , F_77 ,
F_81 , F_61 ) ;
F_125 ( * V_117 ,
F_83 , F_89 ,
F_106 , F_62 ,
F_109 , F_110 ) ;
F_126 ( * V_117 , F_37 ) ;
break;
case V_15 :
F_122 ( * V_117 , F_43 ) ;
F_123 ( * V_117 ,
F_45 , F_52 ,
F_74 ) ;
F_124 ( * V_117 ,
F_119 , F_115 ,
F_76 , F_79 ,
F_82 , F_72 ) ;
F_125 ( * V_117 ,
F_98 , F_103 ,
F_107 , F_73 ,
F_109 , F_110 ) ;
F_126 ( * V_117 , F_37 ) ;
break;
case V_121 :
F_122 ( * V_117 , F_111 ) ;
F_126 ( * V_117 , F_112 ) ;
break;
}
return 1 ;
}
