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
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = 0 ;
F_18 ( V_46 , V_2 , & V_2 -> V_47 ) ;
V_2 -> V_48 = 1 ;
V_2 -> V_49 = 0 ;
return V_2 ;
}
static void V_45 ( T_4 * V_24 )
{
if ( V_24 -> type == V_26 )
{
F_19 ( V_24 -> V_27 . V_28 ) ;
}
else if ( V_24 -> type == V_29 )
{
F_20 ( V_24 -> V_27 . V_30 ) ;
}
else
{
}
F_3 ( V_24 ) ;
}
void F_21 ( T_6 * V_50 )
{
int V_51 ;
F_22 ( T_1 ) * V_52 ;
T_1 * V_53 ;
if ( V_50 == NULL )
return;
V_52 = V_50 -> V_33 ;
for ( V_51 = 0 ; V_51 < F_23 ( V_52 ) ; V_51 ++ )
{
V_53 = F_24 ( V_52 , V_51 ) ;
F_6 ( V_53 ) ;
F_4 ( V_53 ) ;
}
F_25 ( V_52 ) ;
F_26 ( V_50 -> V_31 , V_45 ) ;
F_27 ( V_46 , V_50 , & V_50 -> V_47 ) ;
F_3 ( V_50 ) ;
}
T_1 * F_28 ( T_6 * V_54 , T_2 * V_55 )
{
int V_51 ;
F_22 ( T_1 ) * V_52 ;
T_1 * V_53 ;
V_52 = V_54 -> V_33 ;
for ( V_51 = 0 ; V_51 < F_23 ( V_52 ) ; V_51 ++ )
{
V_53 = F_24 ( V_52 , V_51 ) ;
if ( V_55 == V_53 -> V_1 )
{
return V_53 ;
}
}
V_53 = F_1 ( V_55 ) ;
if ( V_53 == NULL )
return NULL ;
else
{
V_53 -> V_6 = V_54 ;
if ( F_29 ( V_54 -> V_33 , V_53 ) )
return V_53 ;
else
{
F_4 ( V_53 ) ;
return NULL ;
}
}
}
int F_30 ( T_7 * V_56 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
T_6 * V_8 = V_56 -> V_8 ;
T_1 * V_53 ;
T_4 V_57 , * V_58 ;
int V_51 , V_59 ;
V_58 = F_31 ( V_8 -> V_31 , type , V_14 ) ;
if ( V_58 == NULL )
{
for ( V_51 = V_56 -> V_60 ; V_51 < F_23 ( V_8 -> V_33 ) ; V_51 ++ )
{
V_53 = F_24 ( V_8 -> V_33 , V_51 ) ;
V_59 = F_8 ( V_53 , type , V_14 , & V_57 ) ;
if ( V_59 < 0 )
{
V_56 -> V_60 = V_59 ;
return V_59 ;
}
else if ( V_59 )
{
V_58 = & V_57 ;
break;
}
}
V_56 -> V_60 = 0 ;
if ( V_58 == NULL )
return 0 ;
}
V_2 -> type = V_58 -> type ;
V_2 -> V_27 . V_61 = V_58 -> V_27 . V_61 ;
F_32 ( V_2 ) ;
return 1 ;
}
int F_33 ( T_6 * V_8 , T_8 * V_62 )
{
T_4 * V_63 ;
int V_2 = 1 ;
if ( V_62 == NULL ) return 0 ;
V_63 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_63 == NULL )
{
F_34 ( V_64 , V_65 ) ;
return 0 ;
}
V_63 -> type = V_26 ;
V_63 -> V_27 . V_28 = V_62 ;
F_35 ( V_66 ) ;
F_32 ( V_63 ) ;
if ( F_36 ( V_8 -> V_31 , V_63 ) )
{
F_37 ( V_63 ) ;
F_3 ( V_63 ) ;
F_34 ( V_64 , V_67 ) ;
V_2 = 0 ;
}
else F_38 ( V_8 -> V_31 , V_63 ) ;
F_39 ( V_66 ) ;
return V_2 ;
}
int F_40 ( T_6 * V_8 , T_9 * V_62 )
{
T_4 * V_63 ;
int V_2 = 1 ;
if ( V_62 == NULL ) return 0 ;
V_63 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_63 == NULL )
{
F_34 ( V_68 , V_65 ) ;
return 0 ;
}
V_63 -> type = V_29 ;
V_63 -> V_27 . V_30 = V_62 ;
F_35 ( V_66 ) ;
F_32 ( V_63 ) ;
if ( F_36 ( V_8 -> V_31 , V_63 ) )
{
F_37 ( V_63 ) ;
F_3 ( V_63 ) ;
F_34 ( V_68 , V_67 ) ;
V_2 = 0 ;
}
else F_38 ( V_8 -> V_31 , V_63 ) ;
F_39 ( V_66 ) ;
return V_2 ;
}
void F_32 ( T_4 * V_24 )
{
switch ( V_24 -> type )
{
case V_26 :
F_41 ( & V_24 -> V_27 . V_28 -> V_48 , 1 , V_69 ) ;
break;
case V_29 :
F_41 ( & V_24 -> V_27 . V_30 -> V_48 , 1 , V_70 ) ;
break;
}
}
void F_37 ( T_4 * V_24 )
{
switch ( V_24 -> type )
{
case V_26 :
F_19 ( V_24 -> V_27 . V_28 ) ;
break;
case V_29 :
F_20 ( V_24 -> V_27 . V_30 ) ;
break;
}
}
int F_42 ( T_8 * * V_71 , T_7 * V_8 , T_8 * V_62 )
{
T_3 * V_72 ;
T_4 V_63 , * V_73 ;
int V_51 , V_74 , V_75 ;
V_72 = F_43 ( V_62 ) ;
V_74 = F_30 ( V_8 , V_26 , V_72 , & V_63 ) ;
if ( V_74 != V_26 )
{
if ( V_74 == V_76 )
{
F_37 ( & V_63 ) ;
F_34 ( V_77 , V_78 ) ;
return - 1 ;
}
else if ( V_74 != V_16 )
{
F_37 ( & V_63 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_8 -> V_40 ( V_8 , V_62 , V_63 . V_27 . V_28 ) )
{
* V_71 = V_63 . V_27 . V_28 ;
return 1 ;
}
F_37 ( & V_63 ) ;
V_75 = F_44 ( V_8 -> V_8 -> V_31 , V_26 , V_72 ) ;
if ( V_75 == - 1 ) return 0 ;
for ( V_51 = V_75 ; V_51 < F_45 ( V_8 -> V_8 -> V_31 ) ; V_51 ++ )
{
V_73 = F_46 ( V_8 -> V_8 -> V_31 , V_51 ) ;
if ( V_73 -> type != V_26 ) return 0 ;
if ( F_47 ( V_72 , F_48 ( V_73 -> V_27 . V_28 ) ) ) return 0 ;
if ( V_8 -> V_40 ( V_8 , V_62 , V_73 -> V_27 . V_28 ) )
{
* V_71 = V_73 -> V_27 . V_28 ;
F_32 ( V_73 ) ;
return 1 ;
}
}
return 0 ;
}
void F_49 ( T_6 * V_8 , long V_38 )
{
V_8 -> V_38 |= V_38 ;
}
int F_50 ( T_6 * V_8 , int V_36 )
{
return F_51 ( & V_8 -> V_36 , V_36 ) ;
}
int F_52 ( T_6 * V_8 , int V_37 )
{
return F_53 ( & V_8 -> V_37 , V_37 ) ;
}
