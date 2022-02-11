static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = - 2 ;
V_1 -> V_7 = V_2 ;
V_1 -> V_8 = V_2 -> V_9 ;
V_1 -> V_10 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_11 , T_1 * V_12 )
{
T_2 * V_13 , * V_14 ;
if ( ! F_1 ( V_11 ) )
return 0 ;
V_14 = V_12 -> V_7 ;
V_13 = V_11 -> V_7 ;
V_13 -> V_3 = V_14 -> V_3 ;
if ( V_14 -> V_15 ) {
V_13 -> V_15 = F_4 ( V_14 -> V_15 ) ;
if ( ! V_13 -> V_15 )
return 0 ;
}
V_13 -> V_4 = V_14 -> V_4 ;
V_13 -> V_16 = V_14 -> V_16 ;
V_13 -> V_17 = V_14 -> V_17 ;
if ( V_14 -> V_18 ) {
F_5 ( V_13 -> V_18 ) ;
V_13 -> V_18 = F_6 ( V_14 -> V_18 , V_14 -> V_19 ) ;
if ( ! V_13 -> V_18 )
return 0 ;
V_13 -> V_19 = V_14 -> V_19 ;
}
return 1 ;
}
static int F_7 ( T_2 * V_1 , T_1 * V_20 )
{
if ( V_1 -> V_21 )
return 1 ;
V_1 -> V_21 = F_8 ( F_9 ( V_20 -> V_22 ) ) ;
if ( V_1 -> V_21 == NULL )
return 0 ;
return 1 ;
}
static void F_10 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_7 ;
if ( V_2 ) {
F_11 ( V_2 -> V_15 ) ;
F_5 ( V_2 -> V_21 ) ;
F_5 ( V_2 -> V_18 ) ;
F_5 ( V_2 ) ;
}
}
static int F_12 ( T_1 * V_1 , unsigned char * V_23 ,
T_3 * V_24 , const unsigned char * V_25 ,
T_3 V_26 )
{
int V_27 ;
T_2 * V_2 = V_1 -> V_7 ;
T_4 * V_28 = V_1 -> V_22 -> V_22 . V_28 ;
if ( V_2 -> V_16 ) {
if ( V_26 != ( T_3 ) F_13 ( V_2 -> V_16 ) ) {
F_14 ( V_29 , V_30 ) ;
return - 1 ;
}
if ( F_15 ( V_2 -> V_16 ) == V_31 ) {
unsigned int V_32 ;
if ( V_2 -> V_4 != V_5 )
return - 1 ;
V_27 = F_16 ( 0 ,
V_25 , V_26 , V_23 , & V_32 , V_28 ) ;
if ( V_27 <= 0 )
return V_27 ;
V_27 = V_32 ;
} else if ( V_2 -> V_4 == V_33 ) {
if ( ( T_3 ) F_9 ( V_1 -> V_22 ) < V_26 + 1 ) {
F_14 ( V_29 , V_34 ) ;
return - 1 ;
}
if ( ! F_7 ( V_2 , V_1 ) ) {
F_14 ( V_29 , V_35 ) ;
return - 1 ;
}
memcpy ( V_2 -> V_21 , V_25 , V_26 ) ;
V_2 -> V_21 [ V_26 ] = F_17 ( F_15 ( V_2 -> V_16 ) ) ;
V_27 = F_18 ( V_26 + 1 , V_2 -> V_21 ,
V_23 , V_28 , V_33 ) ;
} else if ( V_2 -> V_4 == V_5 ) {
unsigned int V_32 ;
V_27 = F_19 ( F_15 ( V_2 -> V_16 ) ,
V_25 , V_26 , V_23 , & V_32 , V_28 ) ;
if ( V_27 <= 0 )
return V_27 ;
V_27 = V_32 ;
} else if ( V_2 -> V_4 == V_36 ) {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
if ( ! F_20 ( V_28 ,
V_2 -> V_21 , V_25 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_2 -> V_6 ) )
return - 1 ;
V_27 = F_18 ( F_21 ( V_28 ) , V_2 -> V_21 ,
V_23 , V_28 , V_37 ) ;
} else
return - 1 ;
} else
V_27 = F_18 ( V_26 , V_25 , V_23 , V_1 -> V_22 -> V_22 . V_28 ,
V_2 -> V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
* V_24 = V_27 ;
return 1 ;
}
static int F_22 ( T_1 * V_1 ,
unsigned char * V_38 , T_3 * V_39 ,
const unsigned char * V_23 , T_3 V_24 )
{
int V_27 ;
T_2 * V_2 = V_1 -> V_7 ;
if ( V_2 -> V_16 ) {
if ( V_2 -> V_4 == V_33 ) {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_27 = F_23 ( V_24 , V_23 ,
V_2 -> V_21 , V_1 -> V_22 -> V_22 . V_28 ,
V_33 ) ;
if ( V_27 < 1 )
return 0 ;
V_27 -- ;
if ( V_2 -> V_21 [ V_27 ] != F_17 ( F_15 ( V_2 -> V_16 ) ) ) {
F_14 ( V_40 ,
V_41 ) ;
return 0 ;
}
if ( V_27 != F_13 ( V_2 -> V_16 ) ) {
F_14 ( V_40 ,
V_30 ) ;
return 0 ;
}
if ( V_38 )
memcpy ( V_38 , V_2 -> V_21 , V_27 ) ;
} else if ( V_2 -> V_4 == V_5 ) {
T_3 V_32 ;
V_27 = F_24 ( F_15 ( V_2 -> V_16 ) ,
NULL , 0 , V_38 , & V_32 ,
V_23 , V_24 , V_1 -> V_22 -> V_22 . V_28 ) ;
if ( V_27 <= 0 )
return 0 ;
V_27 = V_32 ;
} else
return - 1 ;
} else
V_27 = F_23 ( V_24 , V_23 , V_38 , V_1 -> V_22 -> V_22 . V_28 ,
V_2 -> V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
* V_39 = V_27 ;
return 1 ;
}
static int F_25 ( T_1 * V_1 ,
const unsigned char * V_23 , T_3 V_24 ,
const unsigned char * V_25 , T_3 V_26 )
{
T_2 * V_2 = V_1 -> V_7 ;
T_4 * V_28 = V_1 -> V_22 -> V_22 . V_28 ;
T_3 V_42 ;
if ( V_2 -> V_16 ) {
if ( V_2 -> V_4 == V_5 )
return F_26 ( F_15 ( V_2 -> V_16 ) , V_25 , V_26 ,
V_23 , V_24 , V_28 ) ;
if ( V_2 -> V_4 == V_33 ) {
if ( F_22 ( V_1 , NULL , & V_42 , V_23 , V_24 ) <= 0 )
return 0 ;
} else if ( V_2 -> V_4 == V_36 ) {
int V_27 ;
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_27 = F_23 ( V_24 , V_23 , V_2 -> V_21 ,
V_28 , V_37 ) ;
if ( V_27 <= 0 )
return 0 ;
V_27 = F_27 ( V_28 , V_25 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_2 -> V_21 , V_2 -> V_6 ) ;
if ( V_27 <= 0 )
return 0 ;
return 1 ;
} else
return - 1 ;
} else {
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_42 = F_23 ( V_24 , V_23 , V_2 -> V_21 ,
V_28 , V_2 -> V_4 ) ;
if ( V_42 == 0 )
return 0 ;
}
if ( ( V_42 != V_26 ) || memcmp ( V_25 , V_2 -> V_21 , V_42 ) )
return 0 ;
return 1 ;
}
static int F_28 ( T_1 * V_1 ,
unsigned char * V_43 , T_3 * V_44 ,
const unsigned char * V_45 , T_3 V_46 )
{
int V_27 ;
T_2 * V_2 = V_1 -> V_7 ;
if ( V_2 -> V_4 == V_47 ) {
int V_48 = F_21 ( V_1 -> V_22 -> V_22 . V_28 ) ;
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
if ( ! F_29 ( V_2 -> V_21 , V_48 ,
V_45 , V_46 ,
V_2 -> V_18 ,
V_2 -> V_19 ,
V_2 -> V_16 , V_2 -> V_17 ) )
return - 1 ;
V_27 = F_30 ( V_48 , V_2 -> V_21 , V_43 ,
V_1 -> V_22 -> V_22 . V_28 , V_37 ) ;
} else
V_27 = F_30 ( V_46 , V_45 , V_43 , V_1 -> V_22 -> V_22 . V_28 ,
V_2 -> V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
* V_44 = V_27 ;
return 1 ;
}
static int F_31 ( T_1 * V_1 ,
unsigned char * V_43 , T_3 * V_44 ,
const unsigned char * V_45 , T_3 V_46 )
{
int V_27 ;
T_2 * V_2 = V_1 -> V_7 ;
if ( V_2 -> V_4 == V_47 ) {
int V_49 ;
if ( ! F_7 ( V_2 , V_1 ) )
return - 1 ;
V_27 = F_32 ( V_46 , V_45 , V_2 -> V_21 ,
V_1 -> V_22 -> V_22 . V_28 , V_37 ) ;
if ( V_27 <= 0 )
return V_27 ;
for ( V_49 = 0 ; V_49 < V_27 ; V_49 ++ ) {
if ( V_2 -> V_21 [ V_49 ] )
break;
}
V_27 = F_33 ( V_43 , V_27 , V_2 -> V_21 + V_49 ,
V_27 - V_49 , V_27 ,
V_2 -> V_18 ,
V_2 -> V_19 ,
V_2 -> V_16 , V_2 -> V_17 ) ;
} else
V_27 = F_32 ( V_46 , V_45 , V_43 , V_1 -> V_22 -> V_22 . V_28 ,
V_2 -> V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
* V_44 = V_27 ;
return 1 ;
}
static int F_34 ( const T_5 * V_16 , int V_50 )
{
int V_51 ;
if ( ! V_16 )
return 1 ;
V_51 = F_15 ( V_16 ) ;
if ( V_50 == V_37 ) {
F_14 ( V_52 , V_53 ) ;
return 0 ;
}
if ( V_50 == V_33 ) {
if ( F_17 ( V_51 ) == - 1 ) {
F_14 ( V_52 , V_54 ) ;
return 0 ;
}
} else {
switch( V_51 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_31 :
case V_64 :
return 1 ;
default:
F_14 ( V_52 , V_65 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_35 ( T_1 * V_1 , int type , int V_66 , void * V_67 )
{
T_2 * V_2 = V_1 -> V_7 ;
switch ( type ) {
case V_68 :
if ( ( V_66 >= V_5 ) && ( V_66 <= V_36 ) ) {
if ( ! F_34 ( V_2 -> V_16 , V_66 ) )
return 0 ;
if ( V_66 == V_36 ) {
if ( ! ( V_1 -> V_69 &
( V_70 | V_71 ) ) )
goto V_72;
if ( ! V_2 -> V_16 )
V_2 -> V_16 = F_36 () ;
}
if ( V_66 == V_47 ) {
if ( ! ( V_1 -> V_69 & V_73 ) )
goto V_72;
if ( ! V_2 -> V_16 )
V_2 -> V_16 = F_36 () ;
}
V_2 -> V_4 = V_66 ;
return 1 ;
}
V_72:
F_14 ( V_74 ,
V_75 ) ;
return - 2 ;
case V_76 :
* ( int * ) V_67 = V_2 -> V_4 ;
return 1 ;
case V_77 :
case V_78 :
if ( V_2 -> V_4 != V_36 ) {
F_14 ( V_74 , V_79 ) ;
return - 2 ;
}
if ( type == V_78 )
* ( int * ) V_67 = V_2 -> V_6 ;
else {
if ( V_66 < - 2 )
return - 2 ;
V_2 -> V_6 = V_66 ;
}
return 1 ;
case V_80 :
if ( V_66 < 512 ) {
F_14 ( V_74 , V_34 ) ;
return - 2 ;
}
V_2 -> V_3 = V_66 ;
return 1 ;
case V_81 :
if ( V_67 == NULL || ! F_37 ( ( V_82 * ) V_67 ) || F_38 ( ( V_82 * ) V_67 ) ) {
F_14 ( V_74 , V_83 ) ;
return - 2 ;
}
F_11 ( V_2 -> V_15 ) ;
V_2 -> V_15 = V_67 ;
return 1 ;
case V_84 :
case V_85 :
if ( V_2 -> V_4 != V_47 ) {
F_14 ( V_74 , V_53 ) ;
return - 2 ;
}
if ( type == V_85 )
* ( const T_5 * * ) V_67 = V_2 -> V_16 ;
else
V_2 -> V_16 = V_67 ;
return 1 ;
case V_86 :
if ( ! F_34 ( V_67 , V_2 -> V_4 ) )
return 0 ;
V_2 -> V_16 = V_67 ;
return 1 ;
case V_87 :
* ( const T_5 * * ) V_67 = V_2 -> V_16 ;
return 1 ;
case V_88 :
case V_89 :
if ( V_2 -> V_4 != V_36
&& V_2 -> V_4 != V_47 ) {
F_14 ( V_74 , V_90 ) ;
return - 2 ;
}
if ( type == V_89 ) {
if ( V_2 -> V_17 )
* ( const T_5 * * ) V_67 = V_2 -> V_17 ;
else
* ( const T_5 * * ) V_67 = V_2 -> V_16 ;
} else
V_2 -> V_17 = V_67 ;
return 1 ;
case V_91 :
if ( V_2 -> V_4 != V_47 ) {
F_14 ( V_74 , V_53 ) ;
return - 2 ;
}
F_5 ( V_2 -> V_18 ) ;
if ( V_67 && V_66 > 0 ) {
V_2 -> V_18 = V_67 ;
V_2 -> V_19 = V_66 ;
} else {
V_2 -> V_18 = NULL ;
V_2 -> V_19 = 0 ;
}
return 1 ;
case V_92 :
if ( V_2 -> V_4 != V_47 ) {
F_14 ( V_74 , V_53 ) ;
return - 2 ;
}
* ( unsigned char * * ) V_67 = V_2 -> V_18 ;
return V_2 -> V_19 ;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
return 1 ;
#ifndef F_39
case V_97 :
case V_98 :
case V_99 :
return 1 ;
#endif
case V_100 :
F_14 ( V_74 ,
V_101 ) ;
return - 2 ;
default:
return - 2 ;
}
}
static int F_40 ( T_1 * V_1 ,
const char * type , const char * V_102 )
{
if ( ! V_102 ) {
F_14 ( V_103 , V_104 ) ;
return 0 ;
}
if ( strcmp ( type , L_1 ) == 0 ) {
int V_105 ;
if ( strcmp ( V_102 , L_2 ) == 0 )
V_105 = V_5 ;
else if ( strcmp ( V_102 , L_3 ) == 0 )
V_105 = V_106 ;
else if ( strcmp ( V_102 , L_4 ) == 0 )
V_105 = V_37 ;
else if ( strcmp ( V_102 , L_5 ) == 0 )
V_105 = V_47 ;
else if ( strcmp ( V_102 , L_6 ) == 0 )
V_105 = V_47 ;
else if ( strcmp ( V_102 , L_7 ) == 0 )
V_105 = V_33 ;
else if ( strcmp ( V_102 , L_8 ) == 0 )
V_105 = V_36 ;
else {
F_14 ( V_103 , V_107 ) ;
return - 2 ;
}
return F_41 ( V_1 , V_105 ) ;
}
if ( strcmp ( type , L_9 ) == 0 ) {
int V_6 ;
V_6 = atoi ( V_102 ) ;
return F_42 ( V_1 , V_6 ) ;
}
if ( strcmp ( type , L_10 ) == 0 ) {
int V_3 ;
V_3 = atoi ( V_102 ) ;
return F_43 ( V_1 , V_3 ) ;
}
if ( strcmp ( type , L_11 ) == 0 ) {
int V_27 ;
V_82 * V_108 = NULL ;
if ( ! F_44 ( & V_108 , V_102 ) )
return 0 ;
V_27 = F_45 ( V_1 , V_108 ) ;
if ( V_27 <= 0 )
F_11 ( V_108 ) ;
return V_27 ;
}
if ( strcmp ( type , L_12 ) == 0 ) {
const T_5 * V_16 ;
if ( ( V_16 = F_46 ( V_102 ) ) == NULL ) {
F_14 ( V_103 , V_65 ) ;
return 0 ;
}
return F_47 ( V_1 , V_16 ) ;
}
if ( strcmp ( type , L_13 ) == 0 ) {
const T_5 * V_16 ;
if ( ( V_16 = F_46 ( V_102 ) ) == NULL ) {
F_14 ( V_103 , V_65 ) ;
return 0 ;
}
return F_48 ( V_1 , V_16 ) ;
}
if ( strcmp ( type , L_14 ) == 0 ) {
unsigned char * V_109 ;
long V_110 ;
int V_27 ;
V_109 = F_49 ( V_102 , & V_110 ) ;
if ( ! V_109 )
return 0 ;
V_27 = F_50 ( V_1 , V_109 , V_110 ) ;
if ( V_27 <= 0 )
F_5 ( V_109 ) ;
return V_27 ;
}
return - 2 ;
}
static int F_51 ( T_1 * V_1 , T_6 * V_22 )
{
T_4 * V_28 = NULL ;
T_2 * V_2 = V_1 -> V_7 ;
T_7 * V_111 ;
int V_27 ;
if ( V_2 -> V_15 == NULL ) {
V_2 -> V_15 = F_52 () ;
if ( V_2 -> V_15 == NULL || ! F_53 ( V_2 -> V_15 , V_112 ) )
return 0 ;
}
V_28 = F_54 () ;
if ( V_28 == NULL )
return 0 ;
if ( V_1 -> V_113 ) {
V_111 = F_55 () ;
if ( V_111 == NULL ) {
F_56 ( V_28 ) ;
return 0 ;
}
F_57 ( V_111 , V_1 ) ;
} else
V_111 = NULL ;
V_27 = F_58 ( V_28 , V_2 -> V_3 , V_2 -> V_15 , V_111 ) ;
F_59 ( V_111 ) ;
if ( V_27 > 0 )
F_60 ( V_22 , V_28 ) ;
else
F_56 ( V_28 ) ;
return V_27 ;
}
