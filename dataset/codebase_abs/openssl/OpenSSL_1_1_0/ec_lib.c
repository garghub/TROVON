T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 ;
if ( V_1 == NULL ) {
F_2 ( V_3 , V_4 ) ;
return NULL ;
}
if ( V_1 -> V_5 == 0 ) {
F_2 ( V_3 , V_6 ) ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_2 ( V_3 , V_7 ) ;
return NULL ;
}
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_1 -> V_8 & V_9 ) == 0 ) {
V_2 -> V_10 = F_4 () ;
if ( V_2 -> V_10 == NULL )
goto V_11;
V_2 -> V_12 = F_4 () ;
if ( V_2 -> V_12 == NULL )
goto V_11;
}
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
if ( ! V_1 -> V_5 ( V_2 ) )
goto V_11;
return V_2 ;
V_11:
F_5 ( V_2 -> V_10 ) ;
F_5 ( V_2 -> V_12 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
void F_7 ( T_1 * V_17 )
{
switch ( V_17 -> V_18 ) {
default:
break;
#ifdef F_8
case V_19 :
F_9 ( V_17 -> V_20 . V_21 ) ;
break;
#endif
#ifndef F_10
case V_22 :
F_11 ( V_17 -> V_20 . V_23 ) ;
break;
case V_24 :
F_12 ( V_17 -> V_20 . V_25 ) ;
break;
case V_26 :
F_13 ( V_17 -> V_20 . V_27 ) ;
break;
#endif
case V_28 :
F_14 ( V_17 -> V_20 . V_29 ) ;
break;
}
V_17 -> V_20 . V_29 = NULL ;
}
void F_15 ( T_1 * V_17 )
{
if ( ! V_17 )
return;
if ( V_17 -> V_1 -> V_30 != 0 )
V_17 -> V_1 -> V_30 ( V_17 ) ;
F_7 ( V_17 ) ;
F_16 ( V_17 -> V_31 ) ;
F_17 ( V_17 -> V_32 ) ;
F_5 ( V_17 -> V_10 ) ;
F_5 ( V_17 -> V_12 ) ;
F_6 ( V_17 -> V_33 ) ;
F_6 ( V_17 ) ;
}
void F_18 ( T_1 * V_17 )
{
if ( ! V_17 )
return;
if ( V_17 -> V_1 -> V_34 != 0 )
V_17 -> V_1 -> V_34 ( V_17 ) ;
else if ( V_17 -> V_1 -> V_30 != 0 )
V_17 -> V_1 -> V_30 ( V_17 ) ;
F_7 ( V_17 ) ;
F_16 ( V_17 -> V_31 ) ;
F_19 ( V_17 -> V_32 ) ;
F_20 ( V_17 -> V_10 ) ;
F_20 ( V_17 -> V_12 ) ;
F_21 ( V_17 -> V_33 , V_17 -> V_35 ) ;
F_21 ( V_17 , sizeof( * V_17 ) ) ;
}
int F_22 ( T_1 * V_36 , const T_1 * V_37 )
{
if ( V_36 -> V_1 -> V_38 == 0 ) {
F_2 ( V_39 , V_6 ) ;
return 0 ;
}
if ( V_36 -> V_1 != V_37 -> V_1 ) {
F_2 ( V_39 , V_40 ) ;
return 0 ;
}
if ( V_36 == V_37 )
return 1 ;
V_36 -> V_18 = V_37 -> V_18 ;
switch ( V_37 -> V_18 ) {
default:
V_36 -> V_20 . V_29 = NULL ;
break;
#ifdef F_8
case V_19 :
V_36 -> V_20 . V_21 = F_23 ( V_37 -> V_20 . V_21 ) ;
break;
#endif
#ifndef F_10
case V_22 :
V_36 -> V_20 . V_23 = F_24 ( V_37 -> V_20 . V_23 ) ;
break;
case V_24 :
V_36 -> V_20 . V_25 = F_25 ( V_37 -> V_20 . V_25 ) ;
break;
case V_26 :
V_36 -> V_20 . V_27 = F_26 ( V_37 -> V_20 . V_27 ) ;
break;
#endif
case V_28 :
V_36 -> V_20 . V_29 = F_27 ( V_37 -> V_20 . V_29 ) ;
break;
}
if ( V_37 -> V_31 != NULL ) {
if ( V_36 -> V_31 == NULL ) {
V_36 -> V_31 = F_28 () ;
if ( V_36 -> V_31 == NULL )
return 0 ;
}
if ( ! F_29 ( V_36 -> V_31 , V_37 -> V_31 ) )
return 0 ;
} else {
F_16 ( V_36 -> V_31 ) ;
V_36 -> V_31 = NULL ;
}
if ( V_37 -> V_32 != NULL ) {
if ( V_36 -> V_32 == NULL ) {
V_36 -> V_32 = F_30 ( V_36 ) ;
if ( V_36 -> V_32 == NULL )
return 0 ;
}
if ( ! F_31 ( V_36 -> V_32 , V_37 -> V_32 ) )
return 0 ;
} else {
F_19 ( V_36 -> V_32 ) ;
V_36 -> V_32 = NULL ;
}
if ( ( V_37 -> V_1 -> V_8 & V_9 ) == 0 ) {
if ( ! F_32 ( V_36 -> V_10 , V_37 -> V_10 ) )
return 0 ;
if ( ! F_32 ( V_36 -> V_12 , V_37 -> V_12 ) )
return 0 ;
}
V_36 -> V_41 = V_37 -> V_41 ;
V_36 -> V_13 = V_37 -> V_13 ;
V_36 -> V_15 = V_37 -> V_15 ;
if ( V_37 -> V_33 ) {
F_6 ( V_36 -> V_33 ) ;
V_36 -> V_33 = F_33 ( V_37 -> V_35 ) ;
if ( V_36 -> V_33 == NULL )
return 0 ;
if ( ! memcpy ( V_36 -> V_33 , V_37 -> V_33 , V_37 -> V_35 ) )
return 0 ;
V_36 -> V_35 = V_37 -> V_35 ;
} else {
F_6 ( V_36 -> V_33 ) ;
V_36 -> V_33 = NULL ;
V_36 -> V_35 = 0 ;
}
return V_36 -> V_1 -> V_38 ( V_36 , V_37 ) ;
}
T_1 * F_34 ( const T_1 * V_42 )
{
T_1 * V_43 = NULL ;
int V_44 = 0 ;
if ( V_42 == NULL )
return NULL ;
if ( ( V_43 = F_1 ( V_42 -> V_1 ) ) == NULL )
return ( NULL ) ;
if ( ! F_22 ( V_43 , V_42 ) )
goto V_11;
V_44 = 1 ;
V_11:
if ( ! V_44 ) {
F_15 ( V_43 ) ;
return NULL ;
}
return V_43 ;
}
const T_2 * F_35 ( const T_1 * V_17 )
{
return V_17 -> V_1 ;
}
int F_36 ( const T_2 * V_1 )
{
return V_1 -> V_45 ;
}
int F_37 ( T_1 * V_17 , const T_3 * V_32 ,
const T_4 * V_10 , const T_4 * V_12 )
{
if ( V_32 == NULL ) {
F_2 ( V_46 , V_47 ) ;
return 0 ;
}
if ( V_17 -> V_32 == NULL ) {
V_17 -> V_32 = F_30 ( V_17 ) ;
if ( V_17 -> V_32 == NULL )
return 0 ;
}
if ( ! F_31 ( V_17 -> V_32 , V_32 ) )
return 0 ;
if ( V_10 != NULL ) {
if ( ! F_32 ( V_17 -> V_10 , V_10 ) )
return 0 ;
} else
F_38 ( V_17 -> V_10 ) ;
if ( V_12 != NULL ) {
if ( ! F_32 ( V_17 -> V_12 , V_12 ) )
return 0 ;
} else
F_38 ( V_17 -> V_12 ) ;
if ( F_39 ( V_17 -> V_10 ) ) {
return F_40 ( V_17 ) ;
}
F_16 ( V_17 -> V_31 ) ;
V_17 -> V_31 = NULL ;
return 1 ;
}
const T_3 * F_41 ( const T_1 * V_17 )
{
return V_17 -> V_32 ;
}
T_5 * F_42 ( const T_1 * V_17 )
{
return V_17 -> V_31 ;
}
int F_43 ( const T_1 * V_17 , T_4 * V_10 , T_6 * V_48 )
{
if ( V_17 -> V_10 == NULL )
return 0 ;
if ( ! F_32 ( V_10 , V_17 -> V_10 ) )
return 0 ;
return ! F_44 ( V_10 ) ;
}
const T_4 * F_45 ( const T_1 * V_17 )
{
return V_17 -> V_10 ;
}
int F_46 ( const T_1 * V_17 )
{
F_47 ( V_17 -> V_1 -> V_49 != NULL ) ;
return V_17 -> V_1 -> V_49 ( V_17 ) ;
}
int F_48 ( const T_1 * V_17 , T_4 * V_12 ,
T_6 * V_48 )
{
if ( V_17 -> V_12 == NULL )
return 0 ;
if ( ! F_32 ( V_12 , V_17 -> V_12 ) )
return 0 ;
return ! F_44 ( V_17 -> V_12 ) ;
}
const T_4 * F_49 ( const T_1 * V_17 )
{
return V_17 -> V_12 ;
}
void F_50 ( T_1 * V_17 , int V_50 )
{
V_17 -> V_41 = V_50 ;
}
int F_51 ( const T_1 * V_17 )
{
return V_17 -> V_41 ;
}
void F_52 ( T_1 * V_17 , int V_51 )
{
V_17 -> V_13 = V_51 ;
}
int F_53 ( const T_1 * V_17 )
{
return V_17 -> V_13 ;
}
void F_54 ( T_1 * V_17 ,
T_7 V_52 )
{
V_17 -> V_15 = V_52 ;
}
T_7 F_55 ( const T_1
* V_17 )
{
return V_17 -> V_15 ;
}
T_8 F_56 ( T_1 * V_17 , const unsigned char * V_53 , T_8 V_54 )
{
F_6 ( V_17 -> V_33 ) ;
V_17 -> V_33 = NULL ;
V_17 -> V_35 = 0 ;
if ( ! V_54 || ! V_53 )
return 1 ;
if ( ( V_17 -> V_33 = F_33 ( V_54 ) ) == NULL )
return 0 ;
memcpy ( V_17 -> V_33 , V_53 , V_54 ) ;
V_17 -> V_35 = V_54 ;
return V_54 ;
}
unsigned char * F_57 ( const T_1 * V_17 )
{
return V_17 -> V_33 ;
}
T_8 F_58 ( const T_1 * V_17 )
{
return V_17 -> V_35 ;
}
int F_59 ( T_1 * V_17 , const T_4 * V_53 , const T_4 * V_42 ,
const T_4 * V_55 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_56 == 0 ) {
F_2 ( V_57 , V_6 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_56 ( V_17 , V_53 , V_42 , V_55 , V_48 ) ;
}
int F_60 ( const T_1 * V_17 , T_4 * V_53 , T_4 * V_42 ,
T_4 * V_55 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_58 == 0 ) {
F_2 ( V_59 , V_6 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_58 ( V_17 , V_53 , V_42 , V_55 , V_48 ) ;
}
int F_61 ( T_1 * V_17 , const T_4 * V_53 , const T_4 * V_42 ,
const T_4 * V_55 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_56 == 0 ) {
F_2 ( V_60 ,
V_6 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_56 ( V_17 , V_53 , V_42 , V_55 , V_48 ) ;
}
int F_62 ( const T_1 * V_17 , T_4 * V_53 , T_4 * V_42 ,
T_4 * V_55 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_58 == 0 ) {
F_2 ( V_61 ,
V_6 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_58 ( V_17 , V_53 , V_42 , V_55 , V_48 ) ;
}
int F_63 ( const T_1 * V_17 )
{
if ( V_17 -> V_1 -> V_62 == 0 ) {
F_2 ( V_63 , V_6 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_62 ( V_17 ) ;
}
int F_64 ( const T_1 * V_17 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_64 == 0 ) {
F_2 ( V_65 ,
V_6 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_64 ( V_17 , V_48 ) ;
}
int F_65 ( const T_1 * V_42 , const T_1 * V_55 , T_6 * V_48 )
{
int V_66 = 0 ;
T_4 * V_67 , * V_68 , * V_69 , * V_70 , * V_71 , * V_72 ;
T_6 * V_73 = NULL ;
if ( F_36 ( F_35 ( V_42 ) ) !=
F_36 ( F_35 ( V_55 ) ) )
return 1 ;
if ( F_51 ( V_42 ) && F_51 ( V_55 ) &&
F_51 ( V_42 ) != F_51 ( V_55 ) )
return 1 ;
if ( V_42 -> V_1 -> V_8 & V_9 )
return 0 ;
if ( V_48 == NULL )
V_73 = V_48 = F_66 () ;
if ( V_48 == NULL )
return - 1 ;
F_67 ( V_48 ) ;
V_67 = F_68 ( V_48 ) ;
V_68 = F_68 ( V_48 ) ;
V_69 = F_68 ( V_48 ) ;
V_70 = F_68 ( V_48 ) ;
V_71 = F_68 ( V_48 ) ;
V_72 = F_68 ( V_48 ) ;
if ( V_72 == NULL ) {
F_69 ( V_48 ) ;
F_70 ( V_73 ) ;
return - 1 ;
}
if ( ! V_42 -> V_1 -> V_58 ( V_42 , V_67 , V_68 , V_69 , V_48 ) ||
! V_55 -> V_1 -> V_58 ( V_55 , V_70 , V_71 , V_72 , V_48 ) )
V_66 = 1 ;
if ( V_66 || F_71 ( V_67 , V_70 ) || F_71 ( V_68 , V_71 ) || F_71 ( V_69 , V_72 ) )
V_66 = 1 ;
if ( V_66 || F_72 ( V_42 , F_41 ( V_42 ) ,
F_41 ( V_55 ) , V_48 ) )
V_66 = 1 ;
if ( ! V_66 ) {
const T_4 * V_74 , * V_75 , * V_76 , * V_77 ;
V_74 = F_45 ( V_42 ) ;
V_75 = F_45 ( V_55 ) ;
V_76 = F_49 ( V_42 ) ;
V_77 = F_49 ( V_55 ) ;
if ( V_74 == NULL || V_75 == NULL ) {
F_69 ( V_48 ) ;
F_70 ( V_73 ) ;
return - 1 ;
}
if ( F_71 ( V_74 , V_75 ) || F_71 ( V_76 , V_77 ) )
V_66 = 1 ;
}
F_69 ( V_48 ) ;
F_70 ( V_73 ) ;
return V_66 ;
}
T_3 * F_30 ( const T_1 * V_17 )
{
T_3 * V_2 ;
if ( V_17 == NULL ) {
F_2 ( V_78 , V_47 ) ;
return NULL ;
}
if ( V_17 -> V_1 -> V_79 == 0 ) {
F_2 ( V_78 , V_6 ) ;
return NULL ;
}
V_2 = F_3 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_2 ( V_78 , V_7 ) ;
return NULL ;
}
V_2 -> V_1 = V_17 -> V_1 ;
if ( ! V_2 -> V_1 -> V_79 ( V_2 ) ) {
F_6 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_17 ( T_3 * V_80 )
{
if ( ! V_80 )
return;
if ( V_80 -> V_1 -> V_81 != 0 )
V_80 -> V_1 -> V_81 ( V_80 ) ;
F_6 ( V_80 ) ;
}
void F_19 ( T_3 * V_80 )
{
if ( ! V_80 )
return;
if ( V_80 -> V_1 -> V_82 != 0 )
V_80 -> V_1 -> V_82 ( V_80 ) ;
else if ( V_80 -> V_1 -> V_81 != 0 )
V_80 -> V_1 -> V_81 ( V_80 ) ;
F_21 ( V_80 , sizeof( * V_80 ) ) ;
}
int F_31 ( T_3 * V_36 , const T_3 * V_37 )
{
if ( V_36 -> V_1 -> V_83 == 0 ) {
F_2 ( V_84 , V_6 ) ;
return 0 ;
}
if ( V_36 -> V_1 != V_37 -> V_1 ) {
F_2 ( V_84 , V_40 ) ;
return 0 ;
}
if ( V_36 == V_37 )
return 1 ;
return V_36 -> V_1 -> V_83 ( V_36 , V_37 ) ;
}
T_3 * F_73 ( const T_3 * V_42 , const T_1 * V_17 )
{
T_3 * V_43 ;
int V_66 ;
if ( V_42 == NULL )
return NULL ;
V_43 = F_30 ( V_17 ) ;
if ( V_43 == NULL )
return ( NULL ) ;
V_66 = F_31 ( V_43 , V_42 ) ;
if ( ! V_66 ) {
F_17 ( V_43 ) ;
return NULL ;
}
return V_43 ;
}
const T_2 * F_74 ( const T_3 * V_80 )
{
return V_80 -> V_1 ;
}
int F_75 ( const T_1 * V_17 , T_3 * V_80 )
{
if ( V_17 -> V_1 -> V_85 == 0 ) {
F_2 ( V_86 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_86 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_85 ( V_17 , V_80 ) ;
}
int F_76 ( const T_1 * V_17 ,
T_3 * V_80 , const T_4 * V_87 ,
const T_4 * V_88 , const T_4 * V_89 ,
T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_90 == 0 ) {
F_2 ( V_91 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_91 ,
V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_90 ( V_17 , V_80 , V_87 ,
V_88 , V_89 , V_48 ) ;
}
int F_77 ( const T_1 * V_17 ,
const T_3 * V_80 , T_4 * V_87 ,
T_4 * V_88 , T_4 * V_89 ,
T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_92 == 0 ) {
F_2 ( V_93 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_93 ,
V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_92 ( V_17 , V_80 , V_87 ,
V_88 , V_89 , V_48 ) ;
}
int F_78 ( const T_1 * V_17 ,
T_3 * V_80 , const T_4 * V_87 ,
const T_4 * V_88 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_94 == 0 ) {
F_2 ( V_95 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_95 ,
V_40 ) ;
return 0 ;
}
if ( ! V_17 -> V_1 -> V_94 ( V_17 , V_80 , V_87 , V_88 , V_48 ) )
return 0 ;
if ( F_79 ( V_17 , V_80 , V_48 ) <= 0 ) {
F_2 ( V_95 ,
V_96 ) ;
return 0 ;
}
return 1 ;
}
int F_80 ( const T_1 * V_17 ,
T_3 * V_80 , const T_4 * V_87 ,
const T_4 * V_88 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_94 == 0 ) {
F_2 ( V_97 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_97 ,
V_40 ) ;
return 0 ;
}
if ( ! V_17 -> V_1 -> V_94 ( V_17 , V_80 , V_87 , V_88 , V_48 ) )
return 0 ;
if ( F_79 ( V_17 , V_80 , V_48 ) <= 0 ) {
F_2 ( V_97 ,
V_96 ) ;
return 0 ;
}
return 1 ;
}
int F_81 ( const T_1 * V_17 ,
const T_3 * V_80 , T_4 * V_87 ,
T_4 * V_88 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_98 == 0 ) {
F_2 ( V_99 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_99 ,
V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_98 ( V_17 , V_80 , V_87 , V_88 , V_48 ) ;
}
int F_82 ( const T_1 * V_17 ,
const T_3 * V_80 , T_4 * V_87 ,
T_4 * V_88 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_98 == 0 ) {
F_2 ( V_100 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_100 ,
V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_98 ( V_17 , V_80 , V_87 , V_88 , V_48 ) ;
}
int F_83 ( const T_1 * V_17 , T_3 * V_66 , const T_3 * V_42 ,
const T_3 * V_55 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_101 == 0 ) {
F_2 ( V_102 , V_6 ) ;
return 0 ;
}
if ( ( V_17 -> V_1 != V_66 -> V_1 ) || ( V_66 -> V_1 != V_42 -> V_1 )
|| ( V_42 -> V_1 != V_55 -> V_1 ) ) {
F_2 ( V_102 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_101 ( V_17 , V_66 , V_42 , V_55 , V_48 ) ;
}
int F_84 ( const T_1 * V_17 , T_3 * V_66 , const T_3 * V_42 ,
T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_103 == 0 ) {
F_2 ( V_104 , V_6 ) ;
return 0 ;
}
if ( ( V_17 -> V_1 != V_66 -> V_1 ) || ( V_66 -> V_1 != V_42 -> V_1 ) ) {
F_2 ( V_104 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_103 ( V_17 , V_66 , V_42 , V_48 ) ;
}
int F_85 ( const T_1 * V_17 , T_3 * V_42 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_105 == 0 ) {
F_2 ( V_106 , V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_42 -> V_1 ) {
F_2 ( V_106 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_105 ( V_17 , V_42 , V_48 ) ;
}
int F_86 ( const T_1 * V_17 , const T_3 * V_80 )
{
if ( V_17 -> V_1 -> V_107 == 0 ) {
F_2 ( V_108 ,
V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_108 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_107 ( V_17 , V_80 ) ;
}
int F_79 ( const T_1 * V_17 , const T_3 * V_80 ,
T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_109 == 0 ) {
F_2 ( V_110 , V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_110 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_109 ( V_17 , V_80 , V_48 ) ;
}
int F_72 ( const T_1 * V_17 , const T_3 * V_42 , const T_3 * V_55 ,
T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_111 == 0 ) {
F_2 ( V_112 , V_6 ) ;
return - 1 ;
}
if ( ( V_17 -> V_1 != V_42 -> V_1 ) || ( V_42 -> V_1 != V_55 -> V_1 ) ) {
F_2 ( V_112 , V_40 ) ;
return - 1 ;
}
return V_17 -> V_1 -> V_111 ( V_17 , V_42 , V_55 , V_48 ) ;
}
int F_87 ( const T_1 * V_17 , T_3 * V_80 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_113 == 0 ) {
F_2 ( V_114 , V_6 ) ;
return 0 ;
}
if ( V_17 -> V_1 != V_80 -> V_1 ) {
F_2 ( V_114 , V_40 ) ;
return 0 ;
}
return V_17 -> V_1 -> V_113 ( V_17 , V_80 , V_48 ) ;
}
int F_88 ( const T_1 * V_17 , T_8 V_115 ,
T_3 * V_116 [] , T_6 * V_48 )
{
T_8 V_117 ;
if ( V_17 -> V_1 -> V_118 == 0 ) {
F_2 ( V_119 , V_6 ) ;
return 0 ;
}
for ( V_117 = 0 ; V_117 < V_115 ; V_117 ++ ) {
if ( V_17 -> V_1 != V_116 [ V_117 ] -> V_1 ) {
F_2 ( V_119 , V_40 ) ;
return 0 ;
}
}
return V_17 -> V_1 -> V_118 ( V_17 , V_115 , V_116 , V_48 ) ;
}
int F_89 ( const T_1 * V_17 , T_3 * V_66 , const T_4 * V_120 ,
T_8 V_115 , const T_3 * V_116 [] ,
const T_4 * V_121 [] , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_122 == 0 )
return F_90 ( V_17 , V_66 , V_120 , V_115 , V_116 , V_121 , V_48 ) ;
return V_17 -> V_1 -> V_122 ( V_17 , V_66 , V_120 , V_115 , V_116 , V_121 , V_48 ) ;
}
int F_91 ( const T_1 * V_17 , T_3 * V_66 , const T_4 * V_123 ,
const T_3 * V_80 , const T_4 * V_124 , T_6 * V_48 )
{
const T_3 * V_116 [ 1 ] ;
const T_4 * V_121 [ 1 ] ;
V_116 [ 0 ] = V_80 ;
V_121 [ 0 ] = V_124 ;
return F_89 ( V_17 , V_66 , V_123 ,
( V_80 != NULL
&& V_124 != NULL ) , V_116 , V_121 , V_48 ) ;
}
int F_92 ( T_1 * V_17 , T_6 * V_48 )
{
if ( V_17 -> V_1 -> V_122 == 0 )
return F_93 ( V_17 , V_48 ) ;
if ( V_17 -> V_1 -> V_125 != 0 )
return V_17 -> V_1 -> V_125 ( V_17 , V_48 ) ;
else
return 1 ;
}
int F_94 ( const T_1 * V_17 )
{
if ( V_17 -> V_1 -> V_122 == 0 )
return F_95 ( V_17 ) ;
if ( V_17 -> V_1 -> V_126 != 0 )
return V_17 -> V_1 -> V_126 ( V_17 ) ;
else
return 0 ;
}
int F_40 ( T_1 * V_17 )
{
T_6 * V_48 = F_66 () ;
int V_2 = 0 ;
F_16 ( V_17 -> V_31 ) ;
V_17 -> V_31 = NULL ;
if ( V_48 == NULL )
goto V_11;
V_17 -> V_31 = F_28 () ;
if ( V_17 -> V_31 == NULL )
goto V_11;
if ( ! F_96 ( V_17 -> V_31 , V_17 -> V_10 , V_48 ) ) {
F_16 ( V_17 -> V_31 ) ;
V_17 -> V_31 = NULL ;
goto V_11;
}
V_2 = 1 ;
V_11:
F_70 ( V_48 ) ;
return V_2 ;
}
int F_97 ( T_9 * V_127 , int V_128 , void * V_129 )
{
return F_98 ( & V_127 -> V_130 , V_128 , V_129 ) ;
}
void * F_99 ( const T_9 * V_127 , int V_128 )
{
return F_100 ( & V_127 -> V_130 , V_128 ) ;
}
int F_101 ( const T_1 * V_17 )
{
if ( V_17 -> V_10 == NULL )
return 0 ;
return F_102 ( V_17 -> V_10 ) ;
}
