static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return ( ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ) ;
}
const T_1 * F_2 ( int type )
{
T_1 V_4 ;
const T_1 * V_5 = & V_4 , * * V_6 ;
V_4 . V_3 = type ;
if ( V_7 )
{
int V_8 ;
V_8 = F_3 ( V_7 , & V_4 ) ;
if ( V_8 >= 0 )
return F_4 ( V_7 , V_8 ) ;
}
V_6 = F_5 ( & V_5 , V_9 ,
sizeof( V_9 ) / sizeof( T_1 * ) ) ;
if ( ! V_6 || ! * V_6 )
return NULL ;
return * V_6 ;
}
static T_2 * F_6 ( T_3 * V_10 , T_4 * V_11 , int V_12 )
{
T_2 * V_6 ;
const T_1 * V_13 ;
if ( V_12 == - 1 )
{
if ( ! V_10 || ! V_10 -> V_14 )
return NULL ;
V_12 = V_10 -> V_14 -> V_3 ;
}
#ifndef F_7
if ( V_11 )
{
if ( ! F_8 ( V_11 ) )
{
F_9 ( V_15 , V_16 ) ;
return NULL ;
}
}
else
V_11 = F_10 ( V_12 ) ;
if ( V_11 )
V_13 = F_11 ( V_11 , V_12 ) ;
else
#endif
V_13 = F_2 ( V_12 ) ;
if ( V_13 == NULL )
{
F_9 ( V_15 , V_17 ) ;
return NULL ;
}
V_6 = F_12 ( sizeof( T_2 ) ) ;
if ( ! V_6 )
{
#ifndef F_7
if ( V_11 )
F_13 ( V_11 ) ;
#endif
F_9 ( V_15 , V_18 ) ;
return NULL ;
}
V_6 -> V_19 = V_11 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_22 = NULL ;
if ( V_10 )
F_14 ( & V_10 -> V_23 , 1 , V_24 ) ;
V_6 -> V_25 = NULL ;
if ( V_13 -> V_26 )
{
if ( V_13 -> V_26 ( V_6 ) <= 0 )
{
F_15 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
T_1 * F_16 ( int V_12 , int V_27 )
{
T_1 * V_13 ;
V_13 = F_12 ( sizeof( T_1 ) ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_3 = V_12 ;
V_13 -> V_27 = V_27 | V_28 ;
V_13 -> V_26 = 0 ;
V_13 -> V_29 = 0 ;
V_13 -> V_30 = 0 ;
V_13 -> V_31 = 0 ;
V_13 -> V_32 = 0 ;
V_13 -> V_33 = 0 ;
V_13 -> V_34 = 0 ;
V_13 -> V_35 = 0 ;
V_13 -> V_36 = 0 ;
V_13 -> V_37 = 0 ;
V_13 -> V_38 = 0 ;
V_13 -> V_39 = 0 ;
V_13 -> V_40 = 0 ;
V_13 -> V_41 = 0 ;
V_13 -> V_42 = 0 ;
V_13 -> V_43 = 0 ;
V_13 -> V_44 = 0 ;
V_13 -> V_45 = 0 ;
V_13 -> V_46 = 0 ;
V_13 -> V_47 = 0 ;
V_13 -> V_48 = 0 ;
V_13 -> V_49 = 0 ;
V_13 -> V_50 = 0 ;
V_13 -> V_51 = 0 ;
V_13 -> V_52 = 0 ;
return V_13 ;
}
void F_17 ( T_1 * V_13 )
{
if ( V_13 && ( V_13 -> V_27 & V_28 ) )
F_18 ( V_13 ) ;
}
T_2 * F_19 ( T_3 * V_10 , T_4 * V_11 )
{
return F_6 ( V_10 , V_11 , - 1 ) ;
}
T_2 * F_20 ( int V_12 , T_4 * V_11 )
{
return F_6 ( NULL , V_11 , V_12 ) ;
}
T_2 * F_21 ( T_2 * V_53 )
{
T_2 * V_54 ;
if ( ! V_53 -> V_13 || ! V_53 -> V_13 -> V_29 )
return NULL ;
#ifndef F_7
if ( V_53 -> V_19 && ! F_8 ( V_53 -> V_19 ) )
{
F_9 ( V_55 , V_16 ) ;
return 0 ;
}
#endif
V_54 = F_12 ( sizeof( T_2 ) ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_13 = V_53 -> V_13 ;
#ifndef F_7
V_54 -> V_19 = V_53 -> V_19 ;
#endif
if ( V_53 -> V_10 )
F_14 ( & V_53 -> V_10 -> V_23 , 1 , V_24 ) ;
V_54 -> V_10 = V_53 -> V_10 ;
if ( V_53 -> V_22 )
F_14 ( & V_53 -> V_22 -> V_23 , 1 , V_24 ) ;
V_54 -> V_22 = V_53 -> V_22 ;
V_54 -> V_25 = NULL ;
V_54 -> V_56 = NULL ;
V_54 -> V_20 = V_53 -> V_20 ;
if ( V_53 -> V_13 -> V_29 ( V_54 , V_53 ) > 0 )
return V_54 ;
F_15 ( V_54 ) ;
return NULL ;
}
int F_22 ( const T_1 * V_13 )
{
if ( V_7 == NULL )
{
V_7 = F_23 ( F_1 ) ;
if ( ! V_7 )
return 0 ;
}
if ( ! F_24 ( V_7 , V_13 ) )
return 0 ;
F_25 ( V_7 ) ;
return 1 ;
}
void F_15 ( T_2 * V_57 )
{
if ( V_57 == NULL )
return;
if ( V_57 -> V_13 && V_57 -> V_13 -> V_30 )
V_57 -> V_13 -> V_30 ( V_57 ) ;
if ( V_57 -> V_10 )
F_26 ( V_57 -> V_10 ) ;
if ( V_57 -> V_22 )
F_26 ( V_57 -> V_22 ) ;
#ifndef F_7
if( V_57 -> V_19 )
F_13 ( V_57 -> V_19 ) ;
#endif
F_18 ( V_57 ) ;
}
int F_27 ( T_2 * V_57 , int V_58 , int V_59 ,
int V_60 , int V_61 , void * V_62 )
{
int V_6 ;
if ( ! V_57 || ! V_57 -> V_13 || ! V_57 -> V_13 -> V_51 )
{
F_9 ( V_63 , V_64 ) ;
return - 2 ;
}
if ( ( V_58 != - 1 ) && ( V_57 -> V_13 -> V_3 != V_58 ) )
return - 1 ;
if ( V_57 -> V_20 == V_21 )
{
F_9 ( V_63 , V_65 ) ;
return - 1 ;
}
if ( ( V_59 != - 1 ) && ! ( V_57 -> V_20 & V_59 ) )
{
F_9 ( V_63 , V_66 ) ;
return - 1 ;
}
V_6 = V_57 -> V_13 -> V_51 ( V_57 , V_60 , V_61 , V_62 ) ;
if ( V_6 == - 2 )
F_9 ( V_63 , V_64 ) ;
return V_6 ;
}
int F_28 ( T_2 * V_57 ,
const char * V_67 , const char * V_68 )
{
if ( ! V_57 || ! V_57 -> V_13 || ! V_57 -> V_13 -> V_52 )
{
F_9 ( V_69 ,
V_64 ) ;
return - 2 ;
}
if ( ! strcmp ( V_67 , L_1 ) )
{
const T_5 * V_70 ;
if ( ! V_68 || ! ( V_70 = F_29 ( V_68 ) ) )
{
F_9 ( V_69 ,
V_71 ) ;
return 0 ;
}
return F_30 ( V_57 , V_70 ) ;
}
return V_57 -> V_13 -> V_52 ( V_57 , V_67 , V_68 ) ;
}
int F_31 ( T_2 * V_57 )
{
return V_57 -> V_20 ;
}
void F_32 ( T_2 * V_57 , int * V_72 , int V_73 )
{
V_57 -> V_74 = V_72 ;
V_57 -> V_75 = V_73 ;
}
void F_33 ( T_2 * V_57 , void * V_25 )
{
V_57 -> V_25 = V_25 ;
}
void * F_34 ( T_2 * V_57 )
{
return V_57 -> V_25 ;
}
T_3 * F_35 ( T_2 * V_57 )
{
return V_57 -> V_10 ;
}
T_3 * F_36 ( T_2 * V_57 )
{
return V_57 -> V_22 ;
}
void F_37 ( T_2 * V_57 , void * V_25 )
{
V_57 -> V_56 = V_25 ;
}
void * F_38 ( T_2 * V_57 )
{
return V_57 -> V_56 ;
}
void F_39 ( T_1 * V_13 ,
int (* V_26)( T_2 * V_57 ) )
{
V_13 -> V_26 = V_26 ;
}
void F_40 ( T_1 * V_13 ,
int (* V_29)( T_2 * V_76 , T_2 * V_77 ) )
{
V_13 -> V_29 = V_29 ;
}
void F_41 ( T_1 * V_13 ,
void (* V_30)( T_2 * V_57 ) )
{
V_13 -> V_30 = V_30 ;
}
void F_42 ( T_1 * V_13 ,
int (* V_31)( T_2 * V_57 ) ,
int (* V_32)( T_2 * V_57 , T_3 * V_10 ) )
{
V_13 -> V_31 = V_31 ;
V_13 -> V_32 = V_32 ;
}
void F_43 ( T_1 * V_13 ,
int (* V_33)( T_2 * V_57 ) ,
int (* V_34)( T_2 * V_57 , T_3 * V_10 ) )
{
V_13 -> V_33 = V_33 ;
V_13 -> V_34 = V_34 ;
}
void F_44 ( T_1 * V_13 ,
int (* V_35)( T_2 * V_57 ) ,
int (* V_36)( T_2 * V_57 , unsigned char * V_78 , T_6 * V_79 ,
const unsigned char * V_80 , T_6 V_81 ) )
{
V_13 -> V_35 = V_35 ;
V_13 -> V_36 = V_36 ;
}
void F_45 ( T_1 * V_13 ,
int (* V_37)( T_2 * V_57 ) ,
int (* V_38)( T_2 * V_57 , const unsigned char * V_78 , T_6 V_79 ,
const unsigned char * V_80 , T_6 V_81 ) )
{
V_13 -> V_37 = V_37 ;
V_13 -> V_38 = V_38 ;
}
void F_46 ( T_1 * V_13 ,
int (* V_39)( T_2 * V_57 ) ,
int (* V_40)( T_2 * V_57 ,
unsigned char * V_78 , T_6 * V_79 ,
const unsigned char * V_80 , T_6 V_81 ) )
{
V_13 -> V_39 = V_39 ;
V_13 -> V_40 = V_40 ;
}
void F_47 ( T_1 * V_13 ,
int (* V_41)( T_2 * V_57 , T_7 * V_82 ) ,
int (* V_42)( T_2 * V_57 , unsigned char * V_78 , T_6 * V_79 ,
T_7 * V_82 ) )
{
V_13 -> V_41 = V_41 ;
V_13 -> V_42 = V_42 ;
}
void F_48 ( T_1 * V_13 ,
int (* V_43)( T_2 * V_57 , T_7 * V_82 ) ,
int (* V_44)( T_2 * V_57 , const unsigned char * V_78 , int V_79 ,
T_7 * V_82 ) )
{
V_13 -> V_43 = V_43 ;
V_13 -> V_44 = V_44 ;
}
void F_49 ( T_1 * V_13 ,
int (* V_45)( T_2 * V_57 ) ,
int (* F_50)( T_2 * V_57 , unsigned char * V_83 , T_6 * V_84 ,
const unsigned char * V_85 , T_6 V_86 ) )
{
V_13 -> V_45 = V_45 ;
V_13 -> V_46 = F_50 ;
}
void F_51 ( T_1 * V_13 ,
int (* V_47)( T_2 * V_57 ) ,
int (* V_48)( T_2 * V_57 , unsigned char * V_83 , T_6 * V_84 ,
const unsigned char * V_85 , T_6 V_86 ) )
{
V_13 -> V_47 = V_47 ;
V_13 -> V_48 = V_48 ;
}
void F_52 ( T_1 * V_13 ,
int (* V_49)( T_2 * V_57 ) ,
int (* V_50)( T_2 * V_57 , unsigned char * V_87 , T_6 * V_88 ) )
{
V_13 -> V_49 = V_49 ;
V_13 -> V_50 = V_50 ;
}
void F_53 ( T_1 * V_13 ,
int (* V_51)( T_2 * V_57 , int type , int V_61 , void * V_62 ) ,
int (* V_52)( T_2 * V_57 , const char * type , const char * V_68 ) )
{
V_13 -> V_51 = V_51 ;
V_13 -> V_52 = V_52 ;
}
