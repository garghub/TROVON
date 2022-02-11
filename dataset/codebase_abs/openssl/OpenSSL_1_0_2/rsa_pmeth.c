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
V_2 -> V_11 = NULL ;
V_2 -> V_12 = 0 ;
V_1 -> V_13 = V_2 ;
V_1 -> V_14 = V_2 -> V_15 ;
V_1 -> V_16 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_17 , T_1 * V_18 )
{
T_2 * V_19 , * V_20 ;
if ( ! F_1 ( V_17 ) )
return 0 ;
V_20 = V_18 -> V_13 ;
V_19 = V_17 -> V_13 ;
V_19 -> V_3 = V_20 -> V_3 ;
if ( V_20 -> V_4 ) {
V_19 -> V_4 = F_4 ( V_20 -> V_4 ) ;
if ( ! V_19 -> V_4 )
return 0 ;
}
V_19 -> V_5 = V_20 -> V_5 ;
V_19 -> V_7 = V_20 -> V_7 ;
V_19 -> V_8 = V_20 -> V_8 ;
if ( V_20 -> V_11 ) {
if ( V_19 -> V_11 )
F_5 ( V_19 -> V_11 ) ;
V_19 -> V_11 = F_6 ( V_20 -> V_11 , V_20 -> V_12 ) ;
if ( ! V_19 -> V_11 )
return 0 ;
V_19 -> V_12 = V_20 -> V_12 ;
}
return 1 ;
}
static int F_7 ( T_2 * V_1 , T_1 * V_21 )
{
if ( V_1 -> V_9 )
return 1 ;
V_1 -> V_9 = F_2 ( F_8 ( V_21 -> V_22 ) ) ;
if ( ! V_1 -> V_9 )
return 0 ;
return 1 ;
}
static void F_9 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_13 ;
if ( V_2 ) {
if ( V_2 -> V_4 )
F_10 ( V_2 -> V_4 ) ;
if ( V_2 -> V_9 )
F_5 ( V_2 -> V_9 ) ;
if ( V_2 -> V_11 )
F_5 ( V_2 -> V_11 ) ;
F_5 ( V_2 ) ;
}
}
static int F_11 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_13 ;
T_3 * V_23 = V_1 -> V_22 -> V_22 . V_23 ;
int V_24 = - 1 ;
if ( ! F_12 () )
return 0 ;
if ( V_23 -> V_25 & V_26 )
V_24 = 0 ;
if ( ! ( V_23 -> V_27 -> V_25 & V_28 ) && V_24 )
return - 1 ;
if ( V_2 -> V_7 ) {
const T_4 * V_29 ;
V_29 = F_13 ( F_14 ( V_2 -> V_7 ) ) ;
if ( ! V_29 || ! ( V_29 -> V_25 & V_30 ) )
return V_24 ;
}
if ( V_2 -> V_8 && ! ( V_2 -> V_8 -> V_25 & V_30 ) ) {
const T_4 * V_29 ;
V_29 = F_13 ( F_14 ( V_2 -> V_8 ) ) ;
if ( ! V_29 || ! ( V_29 -> V_25 & V_30 ) )
return V_24 ;
}
return 1 ;
}
static int F_15 ( T_1 * V_1 , unsigned char * V_31 ,
T_5 * V_32 , const unsigned char * V_33 ,
T_5 V_34 )
{
int V_35 ;
T_2 * V_2 = V_1 -> V_13 ;
T_3 * V_23 = V_1 -> V_22 -> V_22 . V_23 ;
#ifdef F_16
V_35 = F_11 ( V_1 ) ;
if ( V_35 < 0 ) {
F_17 ( V_36 , V_37 ) ;
return - 1 ;
}
#endif
if ( V_2 -> V_7 ) {
if ( V_34 != ( T_5 ) F_18 ( V_2 -> V_7 ) ) {
F_17 ( V_36 , V_38 ) ;
return - 1 ;
}
#ifdef F_16
if ( V_35 > 0 ) {
unsigned int V_39 ;
V_35 = F_19 ( V_23 , V_33 , V_34 , V_2 -> V_7 ,
V_2 -> V_5 ,
V_2 -> V_10 ,
V_2 -> V_8 , V_31 , & V_39 ) ;
if ( V_35 > 0 )
* V_32 = V_39 ;
else
* V_32 = 0 ;
return V_35 ;
}
#endif
if ( F_14 ( V_2 -> V_7 ) == V_40 ) {
unsigned int V_41 ;
if ( V_2 -> V_5 != V_6 )
return - 1 ;
V_35 = F_20 ( V_40 ,
V_33 , V_34 , V_31 , & V_41 , V_23 ) ;
if ( V_35 <= 0 )
return V_35 ;
V_35 = V_41 ;
} else if ( V_2 -> V_5 == V_42 ) {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
memcpy ( V_2 -> V_9 , V_33 , V_34 ) ;
V_2 -> V_9 [ V_34 ] = F_21 ( F_14 ( V_2 -> V_7 ) ) ;
V_35 = F_22 ( V_34 + 1 , V_2 -> V_9 ,
V_31 , V_23 , V_42 ) ;
} else if ( V_2 -> V_5 == V_6 ) {
unsigned int V_41 ;
V_35 = F_23 ( F_14 ( V_2 -> V_7 ) ,
V_33 , V_34 , V_31 , & V_41 , V_23 ) ;
if ( V_35 <= 0 )
return V_35 ;
V_35 = V_41 ;
} else if ( V_2 -> V_5 == V_43 ) {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
if ( ! F_24 ( V_23 ,
V_2 -> V_9 , V_33 ,
V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_10 ) )
return - 1 ;
V_35 = F_22 ( F_25 ( V_23 ) , V_2 -> V_9 ,
V_31 , V_23 , V_44 ) ;
} else
return - 1 ;
} else
V_35 = F_22 ( V_34 , V_33 , V_31 , V_1 -> V_22 -> V_22 . V_23 ,
V_2 -> V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_32 = V_35 ;
return 1 ;
}
static int F_26 ( T_1 * V_1 ,
unsigned char * V_45 , T_5 * V_46 ,
const unsigned char * V_31 , T_5 V_32 )
{
int V_35 ;
T_2 * V_2 = V_1 -> V_13 ;
if ( V_2 -> V_7 ) {
if ( V_2 -> V_5 == V_42 ) {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_35 = F_27 ( V_32 , V_31 ,
V_2 -> V_9 , V_1 -> V_22 -> V_22 . V_23 ,
V_42 ) ;
if ( V_35 < 1 )
return 0 ;
V_35 -- ;
if ( V_2 -> V_9 [ V_35 ] != F_21 ( F_14 ( V_2 -> V_7 ) ) ) {
F_17 ( V_47 ,
V_48 ) ;
return 0 ;
}
if ( V_35 != F_18 ( V_2 -> V_7 ) ) {
F_17 ( V_47 ,
V_38 ) ;
return 0 ;
}
if ( V_45 )
memcpy ( V_45 , V_2 -> V_9 , V_35 ) ;
} else if ( V_2 -> V_5 == V_6 ) {
T_5 V_41 ;
V_35 = F_28 ( F_14 ( V_2 -> V_7 ) ,
NULL , 0 , V_45 , & V_41 ,
V_31 , V_32 , V_1 -> V_22 -> V_22 . V_23 ) ;
if ( V_35 <= 0 )
return 0 ;
V_35 = V_41 ;
} else
return - 1 ;
} else
V_35 = F_27 ( V_32 , V_31 , V_45 , V_1 -> V_22 -> V_22 . V_23 ,
V_2 -> V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_46 = V_35 ;
return 1 ;
}
static int F_29 ( T_1 * V_1 ,
const unsigned char * V_31 , T_5 V_32 ,
const unsigned char * V_33 , T_5 V_34 )
{
T_2 * V_2 = V_1 -> V_13 ;
T_3 * V_23 = V_1 -> V_22 -> V_22 . V_23 ;
T_5 V_49 ;
#ifdef F_16
int V_24 ;
V_24 = F_11 ( V_1 ) ;
if ( V_24 < 0 ) {
F_17 ( V_50 ,
V_37 ) ;
return - 1 ;
}
#endif
if ( V_2 -> V_7 ) {
#ifdef F_16
if ( V_24 > 0 ) {
return F_30 ( V_23 ,
V_33 , V_34 ,
V_2 -> V_7 ,
V_2 -> V_5 ,
V_2 -> V_10 ,
V_2 -> V_8 , V_31 , V_32 ) ;
}
#endif
if ( V_2 -> V_5 == V_6 )
return F_31 ( F_14 ( V_2 -> V_7 ) , V_33 , V_34 ,
V_31 , V_32 , V_23 ) ;
if ( V_2 -> V_5 == V_42 ) {
if ( F_26 ( V_1 , NULL , & V_49 , V_31 , V_32 ) <= 0 )
return 0 ;
} else if ( V_2 -> V_5 == V_43 ) {
int V_35 ;
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_35 = F_27 ( V_32 , V_31 , V_2 -> V_9 ,
V_23 , V_44 ) ;
if ( V_35 <= 0 )
return 0 ;
V_35 = F_32 ( V_23 , V_33 ,
V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
if ( V_35 <= 0 )
return 0 ;
return 1 ;
} else
return - 1 ;
} else {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_49 = F_27 ( V_32 , V_31 , V_2 -> V_9 ,
V_23 , V_2 -> V_5 ) ;
if ( V_49 == 0 )
return 0 ;
}
if ( ( V_49 != V_34 ) || memcmp ( V_33 , V_2 -> V_9 , V_49 ) )
return 0 ;
return 1 ;
}
static int F_33 ( T_1 * V_1 ,
unsigned char * V_51 , T_5 * V_52 ,
const unsigned char * V_53 , T_5 V_54 )
{
int V_35 ;
T_2 * V_2 = V_1 -> V_13 ;
if ( V_2 -> V_5 == V_55 ) {
int V_56 = F_25 ( V_1 -> V_22 -> V_22 . V_23 ) ;
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
if ( ! F_34 ( V_2 -> V_9 , V_56 ,
V_53 , V_54 ,
V_2 -> V_11 ,
V_2 -> V_12 ,
V_2 -> V_7 , V_2 -> V_8 ) )
return - 1 ;
V_35 = F_35 ( V_56 , V_2 -> V_9 , V_51 ,
V_1 -> V_22 -> V_22 . V_23 , V_44 ) ;
} else
V_35 = F_35 ( V_54 , V_53 , V_51 , V_1 -> V_22 -> V_22 . V_23 ,
V_2 -> V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_52 = V_35 ;
return 1 ;
}
static int F_36 ( T_1 * V_1 ,
unsigned char * V_51 , T_5 * V_52 ,
const unsigned char * V_53 , T_5 V_54 )
{
int V_35 ;
T_2 * V_2 = V_1 -> V_13 ;
if ( V_2 -> V_5 == V_55 ) {
int V_57 ;
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_35 = F_37 ( V_54 , V_53 , V_2 -> V_9 ,
V_1 -> V_22 -> V_22 . V_23 , V_44 ) ;
if ( V_35 <= 0 )
return V_35 ;
for ( V_57 = 0 ; V_57 < V_35 ; V_57 ++ ) {
if ( V_2 -> V_9 [ V_57 ] )
break;
}
V_35 = F_38 ( V_51 , V_35 , V_2 -> V_9 + V_57 ,
V_35 - V_57 , V_35 ,
V_2 -> V_11 ,
V_2 -> V_12 ,
V_2 -> V_7 , V_2 -> V_8 ) ;
} else
V_35 = F_37 ( V_54 , V_53 , V_51 , V_1 -> V_22 -> V_22 . V_23 ,
V_2 -> V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_52 = V_35 ;
return 1 ;
}
static int F_39 ( const T_4 * V_7 , int V_58 )
{
if ( ! V_7 )
return 1 ;
if ( V_58 == V_44 ) {
F_17 ( V_59 , V_60 ) ;
return 0 ;
}
if ( V_58 == V_42 ) {
if ( F_21 ( F_14 ( V_7 ) ) == - 1 ) {
F_17 ( V_59 , V_61 ) ;
return 0 ;
}
return 1 ;
}
return 1 ;
}
static int F_40 ( T_1 * V_1 , int type , int V_62 , void * V_63 )
{
T_2 * V_2 = V_1 -> V_13 ;
switch ( type ) {
case V_64 :
if ( ( V_62 >= V_6 ) && ( V_62 <= V_43 ) ) {
if ( ! F_39 ( V_2 -> V_7 , V_62 ) )
return 0 ;
if ( V_62 == V_43 ) {
if ( ! ( V_1 -> V_65 &
( V_66 | V_67 ) ) )
goto V_68;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_41 () ;
}
if ( V_62 == V_55 ) {
if ( ! ( V_1 -> V_65 & V_69 ) )
goto V_68;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_41 () ;
}
V_2 -> V_5 = V_62 ;
return 1 ;
}
V_68:
F_17 ( V_70 ,
V_71 ) ;
return - 2 ;
case V_72 :
* ( int * ) V_63 = V_2 -> V_5 ;
return 1 ;
case V_73 :
case V_74 :
if ( V_2 -> V_5 != V_43 ) {
F_17 ( V_70 , V_75 ) ;
return - 2 ;
}
if ( type == V_74 )
* ( int * ) V_63 = V_2 -> V_10 ;
else {
if ( V_62 < - 2 )
return - 2 ;
V_2 -> V_10 = V_62 ;
}
return 1 ;
case V_76 :
if ( V_62 < 256 ) {
F_17 ( V_70 , V_77 ) ;
return - 2 ;
}
V_2 -> V_3 = V_62 ;
return 1 ;
case V_78 :
if ( ! V_63 )
return - 2 ;
F_10 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_63 ;
return 1 ;
case V_79 :
case V_80 :
if ( V_2 -> V_5 != V_55 ) {
F_17 ( V_70 , V_60 ) ;
return - 2 ;
}
if ( type == V_80 )
* ( const T_4 * * ) V_63 = V_2 -> V_7 ;
else
V_2 -> V_7 = V_63 ;
return 1 ;
case V_81 :
if ( ! F_39 ( V_63 , V_2 -> V_5 ) )
return 0 ;
V_2 -> V_7 = V_63 ;
return 1 ;
case V_82 :
* ( const T_4 * * ) V_63 = V_2 -> V_7 ;
return 1 ;
case V_83 :
case V_84 :
if ( V_2 -> V_5 != V_43
&& V_2 -> V_5 != V_55 ) {
F_17 ( V_70 , V_85 ) ;
return - 2 ;
}
if ( type == V_84 ) {
if ( V_2 -> V_8 )
* ( const T_4 * * ) V_63 = V_2 -> V_8 ;
else
* ( const T_4 * * ) V_63 = V_2 -> V_7 ;
} else
V_2 -> V_8 = V_63 ;
return 1 ;
case V_86 :
if ( V_2 -> V_5 != V_55 ) {
F_17 ( V_70 , V_60 ) ;
return - 2 ;
}
if ( V_2 -> V_11 )
F_5 ( V_2 -> V_11 ) ;
if ( V_63 && V_62 > 0 ) {
V_2 -> V_11 = V_63 ;
V_2 -> V_12 = V_62 ;
} else {
V_2 -> V_11 = NULL ;
V_2 -> V_12 = 0 ;
}
return 1 ;
case V_87 :
if ( V_2 -> V_5 != V_55 ) {
F_17 ( V_70 , V_60 ) ;
return - 2 ;
}
* ( unsigned char * * ) V_63 = V_2 -> V_11 ;
return V_2 -> V_12 ;
case V_88 :
case V_89 :
case V_90 :
case V_91 :
return 1 ;
#ifndef F_42
case V_92 :
case V_93 :
case V_94 :
return 1 ;
#endif
case V_95 :
F_17 ( V_70 ,
V_96 ) ;
return - 2 ;
default:
return - 2 ;
}
}
static int F_43 ( T_1 * V_1 ,
const char * type , const char * V_97 )
{
if ( ! V_97 ) {
F_17 ( V_98 , V_99 ) ;
return 0 ;
}
if ( ! strcmp ( type , L_1 ) ) {
int V_100 ;
if ( ! strcmp ( V_97 , L_2 ) )
V_100 = V_6 ;
else if ( ! strcmp ( V_97 , L_3 ) )
V_100 = V_101 ;
else if ( ! strcmp ( V_97 , L_4 ) )
V_100 = V_44 ;
else if ( ! strcmp ( V_97 , L_5 ) )
V_100 = V_55 ;
else if ( ! strcmp ( V_97 , L_6 ) )
V_100 = V_55 ;
else if ( ! strcmp ( V_97 , L_7 ) )
V_100 = V_42 ;
else if ( ! strcmp ( V_97 , L_8 ) )
V_100 = V_43 ;
else {
F_17 ( V_98 , V_102 ) ;
return - 2 ;
}
return F_44 ( V_1 , V_100 ) ;
}
if ( ! strcmp ( type , L_9 ) ) {
int V_10 ;
V_10 = atoi ( V_97 ) ;
return F_45 ( V_1 , V_10 ) ;
}
if ( ! strcmp ( type , L_10 ) ) {
int V_3 ;
V_3 = atoi ( V_97 ) ;
return F_46 ( V_1 , V_3 ) ;
}
if ( ! strcmp ( type , L_11 ) ) {
int V_35 ;
T_6 * V_103 = NULL ;
if ( ! F_47 ( & V_103 , V_97 ) )
return 0 ;
V_35 = F_48 ( V_1 , V_103 ) ;
if ( V_35 <= 0 )
F_10 ( V_103 ) ;
return V_35 ;
}
if ( ! strcmp ( type , L_12 ) ) {
const T_4 * V_7 ;
if ( ! ( V_7 = F_49 ( V_97 ) ) ) {
F_17 ( V_98 , V_104 ) ;
return 0 ;
}
return F_50 ( V_1 , V_7 ) ;
}
if ( ! strcmp ( type , L_13 ) ) {
const T_4 * V_7 ;
if ( ! ( V_7 = F_49 ( V_97 ) ) ) {
F_17 ( V_98 , V_104 ) ;
return 0 ;
}
return F_51 ( V_1 , V_7 ) ;
}
if ( ! strcmp ( type , L_14 ) ) {
unsigned char * V_105 ;
long V_106 ;
int V_35 ;
V_105 = F_52 ( V_97 , & V_106 ) ;
if ( ! V_105 )
return 0 ;
V_35 = F_53 ( V_1 , V_105 , V_106 ) ;
if ( V_35 <= 0 )
F_5 ( V_105 ) ;
return V_35 ;
}
return - 2 ;
}
static int F_54 ( T_1 * V_1 , T_7 * V_22 )
{
T_3 * V_23 = NULL ;
T_2 * V_2 = V_1 -> V_13 ;
T_8 * V_107 , V_108 ;
int V_35 ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = F_55 () ;
if ( ! V_2 -> V_4 || ! F_56 ( V_2 -> V_4 , V_109 ) )
return 0 ;
}
V_23 = F_57 () ;
if ( ! V_23 )
return 0 ;
if ( V_1 -> V_110 ) {
V_107 = & V_108 ;
F_58 ( V_107 , V_1 ) ;
} else
V_107 = NULL ;
V_35 = F_59 ( V_23 , V_2 -> V_3 , V_2 -> V_4 , V_107 ) ;
if ( V_35 > 0 )
F_60 ( V_22 , V_23 ) ;
else
F_61 ( V_23 ) ;
return V_35 ;
}
