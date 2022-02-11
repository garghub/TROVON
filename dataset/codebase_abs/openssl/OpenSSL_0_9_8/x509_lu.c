T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL ) return NULL ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
if ( ( V_1 -> V_7 != NULL ) && ! V_1 -> V_7 ( V_2 ) )
{
F_3 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_4 ( T_1 * V_8 )
{
if ( V_8 == NULL ) return;
if ( ( V_8 -> V_1 != NULL ) &&
( V_8 -> V_1 -> free != NULL ) )
V_8 -> V_1 -> free ( V_8 ) ;
F_3 ( V_8 ) ;
}
int F_5 ( T_1 * V_8 )
{
if ( V_8 -> V_1 == NULL ) return 0 ;
if ( V_8 -> V_1 -> V_3 != NULL )
return V_8 -> V_1 -> V_3 ( V_8 ) ;
else
return 1 ;
}
int F_6 ( T_1 * V_8 )
{
if ( V_8 -> V_1 == NULL ) return 0 ;
if ( V_8 -> V_1 -> V_9 != NULL )
return V_8 -> V_1 -> V_9 ( V_8 ) ;
else
return 1 ;
}
int F_7 ( T_1 * V_8 , int V_10 , const char * V_11 , long V_12 ,
char * * V_2 )
{
if ( V_8 -> V_1 == NULL ) return - 1 ;
if ( V_8 -> V_1 -> V_13 != NULL )
return V_8 -> V_1 -> V_13 ( V_8 , V_10 , V_11 , V_12 , V_2 ) ;
else
return 1 ;
}
int F_8 ( T_1 * V_8 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_15 == NULL ) )
return V_16 ;
if ( V_8 -> V_4 ) return 0 ;
return V_8 -> V_1 -> V_15 ( V_8 , type , V_14 , V_2 ) ;
}
int F_9 ( T_1 * V_8 , int type , T_3 * V_14 ,
T_5 * V_17 , T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) ||
( V_8 -> V_1 -> V_18 == NULL ) )
return V_16 ;
return V_8 -> V_1 -> V_18 ( V_8 , type , V_14 , V_17 , V_2 ) ;
}
int F_10 ( T_1 * V_8 , int type ,
unsigned char * V_19 , int V_20 , T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_21 == NULL ) )
return V_16 ;
return V_8 -> V_1 -> V_21 ( V_8 , type , V_19 , V_20 , V_2 ) ;
}
int F_11 ( T_1 * V_8 , int type , char * V_22 , int V_20 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_23 == NULL ) )
return V_16 ;
return V_8 -> V_1 -> V_23 ( V_8 , type , V_22 , V_20 , V_2 ) ;
}
static int F_12 ( const T_4 * const * V_24 , const T_4 * const * V_25 )
{
int V_2 ;
V_2 = ( ( * V_24 ) -> type - ( * V_25 ) -> type ) ;
if ( V_2 ) return V_2 ;
switch ( ( * V_24 ) -> type )
{
case V_26 :
V_2 = F_13 ( ( * V_24 ) -> V_27 . V_28 , ( * V_25 ) -> V_27 . V_28 ) ;
break;
case V_29 :
V_2 = F_14 ( ( * V_24 ) -> V_27 . V_30 , ( * V_25 ) -> V_27 . V_30 ) ;
break;
default:
return 0 ;
}
return V_2 ;
}
T_6 * F_15 ( void )
{
T_6 * V_2 ;
if ( ( V_2 = ( T_6 * ) F_2 ( sizeof( T_6 ) ) ) == NULL )
return NULL ;
V_2 -> V_31 = F_16 ( F_12 ) ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = F_17 () ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
if ( ( V_2 -> V_36 = F_18 () ) == NULL )
return NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
F_19 ( V_44 , V_2 , & V_2 -> V_45 ) ;
V_2 -> V_46 = 1 ;
return V_2 ;
}
static void V_43 ( T_4 * V_24 )
{
if ( V_24 -> type == V_26 )
{
F_20 ( V_24 -> V_27 . V_28 ) ;
}
else if ( V_24 -> type == V_29 )
{
F_21 ( V_24 -> V_27 . V_30 ) ;
}
else
{
}
F_3 ( V_24 ) ;
}
void F_22 ( T_6 * V_47 )
{
int V_48 ;
F_23 ( T_1 ) * V_49 ;
T_1 * V_50 ;
if ( V_47 == NULL )
return;
V_49 = V_47 -> V_33 ;
for ( V_48 = 0 ; V_48 < F_24 ( V_49 ) ; V_48 ++ )
{
V_50 = F_25 ( V_49 , V_48 ) ;
F_6 ( V_50 ) ;
F_4 ( V_50 ) ;
}
F_26 ( V_49 ) ;
F_27 ( V_47 -> V_31 , V_43 ) ;
F_28 ( V_44 , V_47 , & V_47 -> V_45 ) ;
if ( V_47 -> V_36 )
F_29 ( V_47 -> V_36 ) ;
F_3 ( V_47 ) ;
}
T_1 * F_30 ( T_6 * V_51 , T_2 * V_52 )
{
int V_48 ;
F_23 ( T_1 ) * V_49 ;
T_1 * V_50 ;
V_49 = V_51 -> V_33 ;
for ( V_48 = 0 ; V_48 < F_24 ( V_49 ) ; V_48 ++ )
{
V_50 = F_25 ( V_49 , V_48 ) ;
if ( V_52 == V_50 -> V_1 )
{
return V_50 ;
}
}
V_50 = F_1 ( V_52 ) ;
if ( V_50 == NULL )
return NULL ;
else
{
V_50 -> V_6 = V_51 ;
if ( F_31 ( V_51 -> V_33 , V_50 ) )
return V_50 ;
else
{
F_4 ( V_50 ) ;
return NULL ;
}
}
}
int F_32 ( T_7 * V_53 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
T_6 * V_8 = V_53 -> V_8 ;
T_1 * V_50 ;
T_4 V_54 , * V_55 ;
int V_48 , V_56 ;
V_55 = F_33 ( V_8 -> V_31 , type , V_14 ) ;
if ( V_55 == NULL )
{
for ( V_48 = V_53 -> V_57 ; V_48 < F_24 ( V_8 -> V_33 ) ; V_48 ++ )
{
V_50 = F_25 ( V_8 -> V_33 , V_48 ) ;
V_56 = F_8 ( V_50 , type , V_14 , & V_54 ) ;
if ( V_56 < 0 )
{
V_53 -> V_57 = V_56 ;
return V_56 ;
}
else if ( V_56 )
{
V_55 = & V_54 ;
break;
}
}
V_53 -> V_57 = 0 ;
if ( V_55 == NULL )
return 0 ;
}
V_2 -> type = V_55 -> type ;
V_2 -> V_27 . V_58 = V_55 -> V_27 . V_58 ;
F_34 ( V_2 ) ;
return 1 ;
}
int F_35 ( T_6 * V_8 , T_8 * V_59 )
{
T_4 * V_60 ;
int V_2 = 1 ;
if ( V_59 == NULL ) return 0 ;
V_60 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_60 == NULL )
{
F_36 ( V_61 , V_62 ) ;
return 0 ;
}
V_60 -> type = V_26 ;
V_60 -> V_27 . V_28 = V_59 ;
F_37 ( V_63 ) ;
F_34 ( V_60 ) ;
if ( F_38 ( V_8 -> V_31 , V_60 ) )
{
F_39 ( V_60 ) ;
F_3 ( V_60 ) ;
F_36 ( V_61 , V_64 ) ;
V_2 = 0 ;
}
else F_40 ( V_8 -> V_31 , V_60 ) ;
F_41 ( V_63 ) ;
return V_2 ;
}
int F_42 ( T_6 * V_8 , T_9 * V_59 )
{
T_4 * V_60 ;
int V_2 = 1 ;
if ( V_59 == NULL ) return 0 ;
V_60 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_60 == NULL )
{
F_36 ( V_65 , V_62 ) ;
return 0 ;
}
V_60 -> type = V_29 ;
V_60 -> V_27 . V_30 = V_59 ;
F_37 ( V_63 ) ;
F_34 ( V_60 ) ;
if ( F_38 ( V_8 -> V_31 , V_60 ) )
{
F_39 ( V_60 ) ;
F_3 ( V_60 ) ;
F_36 ( V_65 , V_64 ) ;
V_2 = 0 ;
}
else F_40 ( V_8 -> V_31 , V_60 ) ;
F_41 ( V_63 ) ;
return V_2 ;
}
void F_34 ( T_4 * V_24 )
{
switch ( V_24 -> type )
{
case V_26 :
F_43 ( & V_24 -> V_27 . V_28 -> V_46 , 1 , V_66 ) ;
break;
case V_29 :
F_43 ( & V_24 -> V_27 . V_30 -> V_46 , 1 , V_67 ) ;
break;
}
}
void F_39 ( T_4 * V_24 )
{
switch ( V_24 -> type )
{
case V_26 :
F_20 ( V_24 -> V_27 . V_28 ) ;
break;
case V_29 :
F_21 ( V_24 -> V_27 . V_30 ) ;
break;
}
}
int F_44 ( T_8 * * V_68 , T_7 * V_8 , T_8 * V_59 )
{
T_3 * V_69 ;
T_4 V_60 , * V_70 ;
int V_48 , V_71 , V_72 ;
V_69 = F_45 ( V_59 ) ;
V_71 = F_32 ( V_8 , V_26 , V_69 , & V_60 ) ;
if ( V_71 != V_26 )
{
if ( V_71 == V_73 )
{
F_39 ( & V_60 ) ;
F_36 ( V_74 , V_75 ) ;
return - 1 ;
}
else if ( V_71 != V_16 )
{
F_39 ( & V_60 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_8 -> V_38 ( V_8 , V_59 , V_60 . V_27 . V_28 ) )
{
* V_68 = V_60 . V_27 . V_28 ;
return 1 ;
}
F_39 ( & V_60 ) ;
V_72 = F_46 ( V_8 -> V_8 -> V_31 , V_26 , V_69 ) ;
if ( V_72 == - 1 ) return 0 ;
for ( V_48 = V_72 ; V_48 < F_47 ( V_8 -> V_8 -> V_31 ) ; V_48 ++ )
{
V_70 = F_48 ( V_8 -> V_8 -> V_31 , V_48 ) ;
if ( V_70 -> type != V_26 ) return 0 ;
if ( F_49 ( V_69 , F_50 ( V_70 -> V_27 . V_28 ) ) ) return 0 ;
if ( V_8 -> V_38 ( V_8 , V_59 , V_70 -> V_27 . V_28 ) )
{
* V_68 = V_70 -> V_27 . V_28 ;
F_34 ( V_70 ) ;
return 1 ;
}
}
return 0 ;
}
int F_51 ( T_6 * V_8 , unsigned long V_76 )
{
return F_52 ( V_8 -> V_36 , V_76 ) ;
}
int F_53 ( T_6 * V_8 , int V_77 )
{
F_54 ( V_8 -> V_36 , V_77 ) ;
return 1 ;
}
int F_55 ( T_6 * V_8 , int V_78 )
{
return F_56 ( V_8 -> V_36 , V_78 ) ;
}
int F_57 ( T_6 * V_8 , int V_79 )
{
return F_58 ( V_8 -> V_36 , V_79 ) ;
}
int F_59 ( T_6 * V_8 , T_10 * V_36 )
{
return F_60 ( V_8 -> V_36 , V_36 ) ;
}
