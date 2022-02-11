static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = - 2 ;
V_1 -> V_11 = V_2 ;
V_1 -> V_12 = V_2 -> V_13 ;
V_1 -> V_14 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_15 , T_1 * V_16 )
{
T_2 * V_17 , * V_18 ;
if ( ! F_1 ( V_15 ) )
return 0 ;
V_18 = V_16 -> V_11 ;
V_17 = V_15 -> V_11 ;
V_17 -> V_3 = V_18 -> V_3 ;
if ( V_18 -> V_4 )
{
V_17 -> V_4 = F_4 ( V_18 -> V_4 ) ;
if ( ! V_17 -> V_4 )
return 0 ;
}
V_17 -> V_5 = V_18 -> V_5 ;
V_17 -> V_7 = V_18 -> V_7 ;
return 1 ;
}
static int F_5 ( T_2 * V_1 , T_1 * V_19 )
{
if ( V_1 -> V_9 )
return 1 ;
V_1 -> V_9 = F_2 ( F_6 ( V_19 -> V_20 ) ) ;
if ( ! V_1 -> V_9 )
return 0 ;
return 1 ;
}
static void F_7 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_11 ;
if ( V_2 )
{
if ( V_2 -> V_4 )
F_8 ( V_2 -> V_4 ) ;
if ( V_2 -> V_9 )
F_9 ( V_2 -> V_9 ) ;
F_9 ( V_2 ) ;
}
}
static int F_10 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_11 ;
T_3 * V_21 = V_1 -> V_20 -> V_20 . V_21 ;
int V_22 = - 1 ;
if ( ! F_11 () )
return 0 ;
if ( V_21 -> V_23 & V_24 )
V_22 = 0 ;
if ( ! ( V_21 -> V_25 -> V_23 & V_26 ) && V_22 )
return - 1 ;
if ( V_2 -> V_7 && ! ( V_2 -> V_7 -> V_23 & V_27 ) )
return V_22 ;
if ( V_2 -> V_8 && ! ( V_2 -> V_8 -> V_23 & V_27 ) )
return V_22 ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_28 , T_4 * V_29 ,
const unsigned char * V_30 , T_4 V_31 )
{
int V_32 ;
T_2 * V_2 = V_1 -> V_11 ;
T_3 * V_21 = V_1 -> V_20 -> V_20 . V_21 ;
#ifdef F_13
V_32 = F_10 ( V_1 ) ;
if ( V_32 < 0 )
{
F_14 ( V_33 , V_34 ) ;
return - 1 ;
}
#endif
if ( V_2 -> V_7 )
{
if ( V_31 != ( T_4 ) F_15 ( V_2 -> V_7 ) )
{
F_14 ( V_33 ,
V_35 ) ;
return - 1 ;
}
#ifdef F_13
if ( V_32 > 0 )
{
unsigned int V_36 ;
V_32 = F_16 ( V_21 , V_30 , V_31 , V_2 -> V_7 ,
V_2 -> V_5 ,
V_2 -> V_10 ,
V_2 -> V_8 ,
V_28 , & V_36 ) ;
if ( V_32 > 0 )
* V_29 = V_36 ;
else
* V_29 = 0 ;
return V_32 ;
}
#endif
if ( F_17 ( V_2 -> V_7 ) == V_37 )
{
unsigned int V_38 ;
if ( V_2 -> V_5 != V_6 )
return - 1 ;
V_32 = F_18 ( V_37 ,
V_30 , V_31 , V_28 , & V_38 , V_21 ) ;
if ( V_32 <= 0 )
return V_32 ;
V_32 = V_38 ;
}
else if ( V_2 -> V_5 == V_39 )
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
memcpy ( V_2 -> V_9 , V_30 , V_31 ) ;
V_2 -> V_9 [ V_31 ] =
F_19 ( F_17 ( V_2 -> V_7 ) ) ;
V_32 = F_20 ( V_31 + 1 , V_2 -> V_9 ,
V_28 , V_21 , V_39 ) ;
}
else if ( V_2 -> V_5 == V_6 )
{
unsigned int V_38 ;
V_32 = F_21 ( F_17 ( V_2 -> V_7 ) ,
V_30 , V_31 , V_28 , & V_38 , V_21 ) ;
if ( V_32 <= 0 )
return V_32 ;
V_32 = V_38 ;
}
else if ( V_2 -> V_5 == V_40 )
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
if ( ! F_22 ( V_21 ,
V_2 -> V_9 , V_30 ,
V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_10 ) )
return - 1 ;
V_32 = F_20 ( F_23 ( V_21 ) , V_2 -> V_9 ,
V_28 , V_21 , V_41 ) ;
}
else
return - 1 ;
}
else
V_32 = F_20 ( V_31 , V_30 , V_28 , V_1 -> V_20 -> V_20 . V_21 ,
V_2 -> V_5 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_29 = V_32 ;
return 1 ;
}
static int F_24 ( T_1 * V_1 ,
unsigned char * V_42 , T_4 * V_43 ,
const unsigned char * V_28 , T_4 V_29 )
{
int V_32 ;
T_2 * V_2 = V_1 -> V_11 ;
if ( V_2 -> V_7 )
{
if ( V_2 -> V_5 == V_39 )
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
V_32 = F_25 ( V_29 , V_28 ,
V_2 -> V_9 , V_1 -> V_20 -> V_20 . V_21 ,
V_39 ) ;
if ( V_32 < 1 )
return 0 ;
V_32 -- ;
if ( V_2 -> V_9 [ V_32 ] !=
F_19 ( F_17 ( V_2 -> V_7 ) ) )
{
F_14 ( V_44 ,
V_45 ) ;
return 0 ;
}
if ( V_32 != F_15 ( V_2 -> V_7 ) )
{
F_14 ( V_44 ,
V_35 ) ;
return 0 ;
}
if ( V_42 )
memcpy ( V_42 , V_2 -> V_9 , V_32 ) ;
}
else if ( V_2 -> V_5 == V_6 )
{
T_4 V_38 ;
V_32 = F_26 ( F_17 ( V_2 -> V_7 ) ,
NULL , 0 , V_42 , & V_38 ,
V_28 , V_29 , V_1 -> V_20 -> V_20 . V_21 ) ;
if ( V_32 <= 0 )
return 0 ;
V_32 = V_38 ;
}
else
return - 1 ;
}
else
V_32 = F_25 ( V_29 , V_28 , V_42 , V_1 -> V_20 -> V_20 . V_21 ,
V_2 -> V_5 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_43 = V_32 ;
return 1 ;
}
static int F_27 ( T_1 * V_1 ,
const unsigned char * V_28 , T_4 V_29 ,
const unsigned char * V_30 , T_4 V_31 )
{
T_2 * V_2 = V_1 -> V_11 ;
T_3 * V_21 = V_1 -> V_20 -> V_20 . V_21 ;
T_4 V_46 ;
#ifdef F_13
int V_22 ;
V_22 = F_10 ( V_1 ) ;
if ( V_22 < 0 )
{
F_14 ( V_47 , V_34 ) ;
return - 1 ;
}
#endif
if ( V_2 -> V_7 )
{
#ifdef F_13
if ( V_22 > 0 )
{
return F_28 ( V_21 ,
V_30 , V_31 ,
V_2 -> V_7 ,
V_2 -> V_5 ,
V_2 -> V_10 ,
V_2 -> V_8 ,
V_28 , V_29 ) ;
}
#endif
if ( V_2 -> V_5 == V_6 )
return F_29 ( F_17 ( V_2 -> V_7 ) , V_30 , V_31 ,
V_28 , V_29 , V_21 ) ;
if ( V_2 -> V_5 == V_39 )
{
if ( F_24 ( V_1 , NULL , & V_46 ,
V_28 , V_29 ) <= 0 )
return 0 ;
}
else if ( V_2 -> V_5 == V_40 )
{
int V_32 ;
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
V_32 = F_25 ( V_29 , V_28 , V_2 -> V_9 ,
V_21 , V_41 ) ;
if ( V_32 <= 0 )
return 0 ;
V_32 = F_30 ( V_21 , V_30 ,
V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
if ( V_32 <= 0 )
return 0 ;
return 1 ;
}
else
return - 1 ;
}
else
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
V_46 = F_25 ( V_29 , V_28 , V_2 -> V_9 ,
V_21 , V_2 -> V_5 ) ;
if ( V_46 == 0 )
return 0 ;
}
if ( ( V_46 != V_31 ) || memcmp ( V_30 , V_2 -> V_9 , V_46 ) )
return 0 ;
return 1 ;
}
static int F_31 ( T_1 * V_1 ,
unsigned char * V_48 , T_4 * V_49 ,
const unsigned char * V_50 , T_4 V_51 )
{
int V_32 ;
T_2 * V_2 = V_1 -> V_11 ;
V_32 = F_32 ( V_51 , V_50 , V_48 , V_1 -> V_20 -> V_20 . V_21 ,
V_2 -> V_5 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_49 = V_32 ;
return 1 ;
}
static int F_33 ( T_1 * V_1 ,
unsigned char * V_48 , T_4 * V_49 ,
const unsigned char * V_50 , T_4 V_51 )
{
int V_32 ;
T_2 * V_2 = V_1 -> V_11 ;
V_32 = F_34 ( V_51 , V_50 , V_48 , V_1 -> V_20 -> V_20 . V_21 ,
V_2 -> V_5 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_49 = V_32 ;
return 1 ;
}
static int F_35 ( const T_5 * V_7 , int V_52 )
{
if ( ! V_7 )
return 1 ;
if ( V_52 == V_41 )
{
F_14 ( V_53 , V_54 ) ;
return 0 ;
}
if ( V_52 == V_39 )
{
if ( F_19 ( F_17 ( V_7 ) ) == - 1 )
{
F_14 ( V_53 ,
V_55 ) ;
return 0 ;
}
return 1 ;
}
return 1 ;
}
static int F_36 ( T_1 * V_1 , int type , int V_56 , void * V_57 )
{
T_2 * V_2 = V_1 -> V_11 ;
switch ( type )
{
case V_58 :
if ( ( V_56 >= V_6 ) && ( V_56 <= V_40 ) )
{
if ( ! F_35 ( V_2 -> V_7 , V_56 ) )
return 0 ;
if ( V_56 == V_40 )
{
if ( ! ( V_1 -> V_59 &
( V_60 | V_61 ) ) )
goto V_62;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_37 () ;
}
if ( V_56 == V_63 )
{
if ( ! ( V_1 -> V_59 & V_64 ) )
goto V_62;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_37 () ;
}
V_2 -> V_5 = V_56 ;
return 1 ;
}
V_62:
F_14 ( V_65 ,
V_66 ) ;
return - 2 ;
case V_67 :
* ( int * ) V_57 = V_2 -> V_5 ;
return 1 ;
case V_68 :
case V_69 :
if ( V_2 -> V_5 != V_40 )
{
F_14 ( V_65 , V_70 ) ;
return - 2 ;
}
if ( type == V_69 )
* ( int * ) V_57 = V_2 -> V_10 ;
else
{
if ( V_56 < - 2 )
return - 2 ;
V_2 -> V_10 = V_56 ;
}
return 1 ;
case V_71 :
if ( V_56 < 256 )
{
F_14 ( V_65 , V_72 ) ;
return - 2 ;
}
V_2 -> V_3 = V_56 ;
return 1 ;
case V_73 :
if ( ! V_57 )
return - 2 ;
V_2 -> V_4 = V_57 ;
return 1 ;
case V_74 :
if ( ! F_35 ( V_57 , V_2 -> V_5 ) )
return 0 ;
V_2 -> V_7 = V_57 ;
return 1 ;
case V_75 :
case V_76 :
if ( V_2 -> V_5 != V_40 )
{
F_14 ( V_65 , V_77 ) ;
return - 2 ;
}
if ( type == V_76 )
{
if ( V_2 -> V_8 )
* ( const T_5 * * ) V_57 = V_2 -> V_8 ;
else
* ( const T_5 * * ) V_57 = V_2 -> V_7 ;
}
else
V_2 -> V_8 = V_57 ;
return 1 ;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
return 1 ;
#ifndef F_38
case V_82 :
{
T_6 * V_83 = NULL ;
T_7 * V_84 = NULL ;
if ( V_57 )
F_39 ( V_57 , NULL , NULL , & V_83 ) ;
if ( V_83 )
F_40 ( & V_84 , NULL , NULL , V_83 ) ;
if ( V_84 && F_41 ( V_84 ) == V_85 )
V_2 -> V_5 = V_63 ;
}
case V_86 :
case V_87 :
return 1 ;
#endif
case V_88 :
F_14 ( V_65 ,
V_89 ) ;
return - 2 ;
default:
return - 2 ;
}
}
static int F_42 ( T_1 * V_1 ,
const char * type , const char * V_90 )
{
if ( ! V_90 )
{
F_14 ( V_91 , V_92 ) ;
return 0 ;
}
if ( ! strcmp ( type , L_1 ) )
{
int V_93 ;
if ( ! strcmp ( V_90 , L_2 ) )
V_93 = V_6 ;
else if ( ! strcmp ( V_90 , L_3 ) )
V_93 = V_94 ;
else if ( ! strcmp ( V_90 , L_4 ) )
V_93 = V_41 ;
else if ( ! strcmp ( V_90 , L_5 ) )
V_93 = V_63 ;
else if ( ! strcmp ( V_90 , L_6 ) )
V_93 = V_39 ;
else if ( ! strcmp ( V_90 , L_7 ) )
V_93 = V_40 ;
else
{
F_14 ( V_91 ,
V_95 ) ;
return - 2 ;
}
return F_43 ( V_1 , V_93 ) ;
}
if ( ! strcmp ( type , L_8 ) )
{
int V_10 ;
V_10 = atoi ( V_90 ) ;
return F_44 ( V_1 , V_10 ) ;
}
if ( ! strcmp ( type , L_9 ) )
{
int V_3 ;
V_3 = atoi ( V_90 ) ;
return F_45 ( V_1 , V_3 ) ;
}
if ( ! strcmp ( type , L_10 ) )
{
int V_32 ;
T_8 * V_96 = NULL ;
if ( ! F_46 ( & V_96 , V_90 ) )
return 0 ;
V_32 = F_47 ( V_1 , V_96 ) ;
if ( V_32 <= 0 )
F_8 ( V_96 ) ;
return V_32 ;
}
return - 2 ;
}
static int F_48 ( T_1 * V_1 , T_9 * V_20 )
{
T_3 * V_21 = NULL ;
T_2 * V_2 = V_1 -> V_11 ;
T_10 * V_97 , V_98 ;
int V_32 ;
if ( ! V_2 -> V_4 )
{
V_2 -> V_4 = F_49 () ;
if ( ! V_2 -> V_4 || ! F_50 ( V_2 -> V_4 , V_99 ) )
return 0 ;
}
V_21 = F_51 () ;
if ( ! V_21 )
return 0 ;
if ( V_1 -> V_100 )
{
V_97 = & V_98 ;
F_52 ( V_97 , V_1 ) ;
}
else
V_97 = NULL ;
V_32 = F_53 ( V_21 , V_2 -> V_3 , V_2 -> V_4 , V_97 ) ;
if ( V_32 > 0 )
F_54 ( V_20 , V_21 ) ;
else
F_55 ( V_21 ) ;
return V_32 ;
}
