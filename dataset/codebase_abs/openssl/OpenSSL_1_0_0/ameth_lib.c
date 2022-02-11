void main ()
{
int V_1 ;
for ( V_1 = 0 ;
V_1 < sizeof( V_2 ) / sizeof( V_3 * ) ;
V_1 ++ )
fprintf ( V_4 , L_1 , V_1 ,
V_2 [ V_1 ] -> V_5 ,
F_1 ( V_2 [ V_1 ] -> V_5 ) ) ;
}
static int F_2 ( const V_3 * const * V_6 ,
const V_3 * const * V_7 )
{
return ( ( * V_6 ) -> V_5 - ( * V_7 ) -> V_5 ) ;
}
int F_3 ( void )
{
int V_8 = sizeof( V_2 ) / sizeof( V_3 * ) ;
if ( V_9 )
V_8 += F_4 ( V_9 ) ;
return V_8 ;
}
const V_3 * F_5 ( int V_10 )
{
int V_8 = sizeof( V_2 ) / sizeof( V_3 * ) ;
if ( V_10 < 0 )
return NULL ;
if ( V_10 < V_8 )
return V_2 [ V_10 ] ;
V_10 -= V_8 ;
return F_6 ( V_9 , V_10 ) ;
}
static const V_3 * F_7 ( int type )
{
V_3 V_11 ;
const V_3 * V_12 = & V_11 , * * V_13 ;
V_11 . V_5 = type ;
if ( V_9 )
{
int V_10 ;
V_10 = F_8 ( V_9 , & V_11 ) ;
if ( V_10 >= 0 )
return F_6 ( V_9 , V_10 ) ;
}
V_13 = F_9 ( & V_12 , V_2 ,
sizeof( V_2 )
/ sizeof( V_3 * ) ) ;
if ( ! V_13 || ! * V_13 )
return NULL ;
return * V_13 ;
}
const V_3 * F_10 ( T_1 * * V_14 , int type )
{
const V_3 * V_12 ;
T_1 * V_15 ;
for (; ; )
{
V_12 = F_7 ( type ) ;
if ( ! V_12 || ! ( V_12 -> V_16 & V_17 ) )
break;
type = V_12 -> V_18 ;
}
if ( V_14 )
{
#ifndef F_11
V_15 = F_12 ( type ) ;
if ( V_15 )
{
* V_14 = V_15 ;
return F_13 ( V_15 , type ) ;
}
#endif
* V_14 = NULL ;
}
return V_12 ;
}
const V_3 * F_14 ( T_1 * * V_14 ,
const char * V_19 , int V_20 )
{
int V_1 ;
const V_3 * V_21 ;
if ( V_20 == - 1 )
V_20 = strlen ( V_19 ) ;
if ( V_14 )
{
#ifndef F_11
T_1 * V_15 ;
V_21 = F_15 ( & V_15 , V_19 , V_20 ) ;
if ( V_21 )
{
if ( ! F_16 ( V_15 ) )
V_21 = NULL ;
F_17 ( V_15 ) ;
* V_14 = V_15 ;
return V_21 ;
}
#endif
* V_14 = NULL ;
}
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ )
{
V_21 = F_5 ( V_1 ) ;
if ( V_21 -> V_16 & V_17 )
continue;
if ( ( ( int ) strlen ( V_21 -> V_22 ) == V_20 ) &&
! strncasecmp ( V_21 -> V_22 , V_19 , V_20 ) )
return V_21 ;
}
return NULL ;
}
int F_18 ( const V_3 * V_21 )
{
if ( V_9 == NULL )
{
V_9 = F_19 ( F_2 ) ;
if ( ! V_9 )
return 0 ;
}
if ( ! F_20 ( V_9 , V_21 ) )
return 0 ;
F_21 ( V_9 ) ;
return 1 ;
}
int F_22 ( int V_23 , int V_24 )
{
V_3 * V_21 ;
V_21 = F_23 ( V_24 , V_17 , NULL , NULL ) ;
if ( ! V_21 )
return 0 ;
V_21 -> V_18 = V_23 ;
return F_18 ( V_21 ) ;
}
int F_24 ( int * V_25 , int * V_26 , int * V_27 ,
const char * * V_28 , const char * * V_29 ,
const V_3 * V_21 )
{
if ( ! V_21 )
return 0 ;
if ( V_25 )
* V_25 = V_21 -> V_5 ;
if ( V_26 )
* V_26 = V_21 -> V_18 ;
if ( V_27 )
* V_27 = V_21 -> V_16 ;
if ( V_28 )
* V_28 = V_21 -> V_30 ;
if ( V_29 )
* V_29 = V_21 -> V_22 ;
return 1 ;
}
const V_3 * F_25 ( T_2 * V_31 )
{
return V_31 -> V_21 ;
}
V_3 * F_23 ( int V_32 , int V_33 ,
const char * V_22 , const char * V_30 )
{
V_3 * V_21 ;
V_21 = F_26 ( sizeof( V_3 ) ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_5 = V_32 ;
V_21 -> V_18 = V_32 ;
V_21 -> V_16 = V_33 | V_34 ;
if ( V_30 )
{
V_21 -> V_30 = F_27 ( V_30 ) ;
if ( ! V_21 -> V_30 )
goto V_35;
}
else
V_21 -> V_30 = NULL ;
if ( V_22 )
{
V_21 -> V_22 = F_27 ( V_22 ) ;
if ( ! V_21 -> V_22 )
goto V_35;
}
else
V_21 -> V_22 = NULL ;
V_21 -> V_36 = 0 ;
V_21 -> V_37 = 0 ;
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
V_21 -> V_40 = 0 ;
V_21 -> V_41 = 0 ;
V_21 -> V_42 = 0 ;
V_21 -> V_43 = 0 ;
V_21 -> V_44 = 0 ;
V_21 -> V_45 = 0 ;
V_21 -> V_46 = 0 ;
V_21 -> V_47 = 0 ;
V_21 -> V_48 = 0 ;
V_21 -> V_49 = 0 ;
V_21 -> V_50 = 0 ;
V_21 -> V_51 = 0 ;
V_21 -> V_52 = 0 ;
V_21 -> V_53 = 0 ;
V_21 -> V_54 = 0 ;
return V_21 ;
V_35:
F_28 ( V_21 ) ;
return NULL ;
}
void F_29 ( V_3 * V_55 ,
const V_3 * V_56 )
{
V_55 -> V_36 = V_56 -> V_36 ;
V_55 -> V_37 = V_56 -> V_37 ;
V_55 -> V_38 = V_56 -> V_38 ;
V_55 -> V_39 = V_56 -> V_39 ;
V_55 -> V_40 = V_56 -> V_40 ;
V_55 -> V_41 = V_56 -> V_41 ;
V_55 -> V_42 = V_56 -> V_42 ;
V_55 -> V_43 = V_56 -> V_43 ;
V_55 -> V_44 = V_56 -> V_44 ;
V_55 -> V_45 = V_56 -> V_45 ;
V_55 -> V_46 = V_56 -> V_46 ;
V_55 -> V_47 = V_56 -> V_47 ;
V_55 -> V_48 = V_56 -> V_48 ;
V_55 -> V_49 = V_56 -> V_49 ;
V_55 -> V_50 = V_56 -> V_50 ;
V_55 -> V_51 = V_56 -> V_51 ;
V_55 -> V_52 = V_56 -> V_52 ;
V_55 -> V_53 = V_56 -> V_53 ;
V_55 -> V_54 = V_56 -> V_54 ;
}
void F_28 ( V_3 * V_21 )
{
if ( V_21 && ( V_21 -> V_16 & V_34 ) )
{
if ( V_21 -> V_22 )
F_30 ( V_21 -> V_22 ) ;
if ( V_21 -> V_30 )
F_30 ( V_21 -> V_30 ) ;
F_30 ( V_21 ) ;
}
}
void F_31 ( V_3 * V_21 ,
int (* V_36)( T_2 * V_57 , T_3 * V_58 ) ,
int (* V_37)( T_3 * V_58 , const T_2 * V_57 ) ,
int (* V_38)( const T_2 * V_6 , const T_2 * V_7 ) ,
int (* V_39)( T_4 * V_59 , const T_2 * V_31 , int V_60 ,
T_5 * V_61 ) ,
int (* V_45)( const T_2 * V_57 ) ,
int (* V_46)( const T_2 * V_57 ) )
{
V_21 -> V_36 = V_36 ;
V_21 -> V_37 = V_37 ;
V_21 -> V_38 = V_38 ;
V_21 -> V_39 = V_39 ;
V_21 -> V_45 = V_45 ;
V_21 -> V_46 = V_46 ;
}
void F_32 ( V_3 * V_21 ,
int (* V_40)( T_2 * V_57 , T_6 * V_62 ) ,
int (* V_41)( T_6 * V_63 , const T_2 * V_57 ) ,
int (* V_42)( T_4 * V_59 , const T_2 * V_31 , int V_60 ,
T_5 * V_61 ) )
{
V_21 -> V_40 = V_40 ;
V_21 -> V_41 = V_41 ;
V_21 -> V_42 = V_42 ;
}
void F_33 ( V_3 * V_21 ,
int (* V_47)( T_2 * V_31 ,
const unsigned char * * V_64 , int V_65 ) ,
int (* V_48)( const T_2 * V_31 , unsigned char * * V_64 ) ,
int (* V_49)( const T_2 * V_57 ) ,
int (* V_50)( T_2 * V_23 , const T_2 * V_24 ) ,
int (* V_51)( const T_2 * V_6 , const T_2 * V_7 ) ,
int (* V_52)( T_4 * V_59 , const T_2 * V_31 , int V_60 ,
T_5 * V_61 ) )
{
V_21 -> V_47 = V_47 ;
V_21 -> V_48 = V_48 ;
V_21 -> V_49 = V_49 ;
V_21 -> V_50 = V_50 ;
V_21 -> V_51 = V_51 ;
V_21 -> V_52 = V_52 ;
}
void F_34 ( V_3 * V_21 ,
void (* V_53)( T_2 * V_31 ) )
{
V_21 -> V_53 = V_53 ;
}
void F_35 ( V_3 * V_21 ,
int (* V_54)( T_2 * V_31 , int V_66 ,
long V_67 , void * V_68 ) )
{
V_21 -> V_54 = V_54 ;
}
