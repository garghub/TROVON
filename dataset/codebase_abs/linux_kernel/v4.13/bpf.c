static inline T_1 F_1 ( const void * V_1 )
{
return ( T_1 ) ( unsigned long ) V_1 ;
}
static inline int F_2 ( enum V_2 V_3 , union V_4 * V_5 ,
unsigned int V_6 )
{
return F_3 ( V_7 , V_3 , V_5 , V_6 ) ;
}
int F_4 ( enum V_8 V_9 , int V_10 ,
int V_11 , int V_12 , T_2 V_13 )
{
union V_4 V_5 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = V_9 ;
V_5 . V_10 = V_10 ;
V_5 . V_11 = V_11 ;
V_5 . V_12 = V_12 ;
V_5 . V_13 = V_13 ;
return F_2 ( V_14 , & V_5 , sizeof( V_5 ) ) ;
}
int F_5 ( enum V_8 V_9 , int V_10 ,
int V_15 , int V_12 , T_2 V_13 )
{
union V_4 V_5 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = V_9 ;
V_5 . V_10 = V_10 ;
V_5 . V_11 = 4 ;
V_5 . V_15 = V_15 ;
V_5 . V_12 = V_12 ;
V_5 . V_13 = V_13 ;
return F_2 ( V_14 , & V_5 , sizeof( V_5 ) ) ;
}
int F_6 ( enum V_16 type , const struct V_17 * V_18 ,
T_3 V_19 , const char * V_20 ,
T_2 V_21 , char * V_22 , T_3 V_23 )
{
int V_24 ;
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_25 = type ;
V_5 . V_26 = ( T_2 ) V_19 ;
V_5 . V_18 = F_1 ( V_18 ) ;
V_5 . V_20 = F_1 ( V_20 ) ;
V_5 . V_22 = F_1 ( NULL ) ;
V_5 . V_27 = 0 ;
V_5 . V_28 = 0 ;
V_5 . V_21 = V_21 ;
V_24 = F_2 ( V_29 , & V_5 , sizeof( V_5 ) ) ;
if ( V_24 >= 0 || ! V_22 || ! V_23 )
return V_24 ;
V_5 . V_22 = F_1 ( V_22 ) ;
V_5 . V_27 = V_23 ;
V_5 . V_28 = 1 ;
V_22 [ 0 ] = 0 ;
return F_2 ( V_29 , & V_5 , sizeof( V_5 ) ) ;
}
int F_8 ( enum V_16 type , const struct V_17 * V_18 ,
T_3 V_19 , int V_30 ,
const char * V_20 , T_2 V_21 ,
char * V_22 , T_3 V_23 , int V_28 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_25 = type ;
V_5 . V_26 = ( T_2 ) V_19 ;
V_5 . V_18 = F_1 ( V_18 ) ;
V_5 . V_20 = F_1 ( V_20 ) ;
V_5 . V_22 = F_1 ( V_22 ) ;
V_5 . V_27 = V_23 ;
V_5 . V_28 = V_28 ;
V_22 [ 0 ] = 0 ;
V_5 . V_21 = V_21 ;
V_5 . V_31 = V_30 ? V_32 : 0 ;
return F_2 ( V_29 , & V_5 , sizeof( V_5 ) ) ;
}
int F_9 ( int V_24 , const void * V_33 , const void * V_34 ,
T_1 V_35 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_36 = V_24 ;
V_5 . V_33 = F_1 ( V_33 ) ;
V_5 . V_34 = F_1 ( V_34 ) ;
V_5 . V_35 = V_35 ;
return F_2 ( V_37 , & V_5 , sizeof( V_5 ) ) ;
}
int F_10 ( int V_24 , const void * V_33 , void * V_34 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_36 = V_24 ;
V_5 . V_33 = F_1 ( V_33 ) ;
V_5 . V_34 = F_1 ( V_34 ) ;
return F_2 ( V_38 , & V_5 , sizeof( V_5 ) ) ;
}
int F_11 ( int V_24 , const void * V_33 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_36 = V_24 ;
V_5 . V_33 = F_1 ( V_33 ) ;
return F_2 ( V_39 , & V_5 , sizeof( V_5 ) ) ;
}
int F_12 ( int V_24 , const void * V_33 , void * V_40 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_36 = V_24 ;
V_5 . V_33 = F_1 ( V_33 ) ;
V_5 . V_40 = F_1 ( V_40 ) ;
return F_2 ( V_41 , & V_5 , sizeof( V_5 ) ) ;
}
int F_13 ( int V_24 , const char * V_42 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_42 = F_1 ( ( void * ) V_42 ) ;
V_5 . V_43 = V_24 ;
return F_2 ( V_44 , & V_5 , sizeof( V_5 ) ) ;
}
int F_14 ( const char * V_42 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_42 = F_1 ( ( void * ) V_42 ) ;
return F_2 ( V_45 , & V_5 , sizeof( V_5 ) ) ;
}
int F_15 ( int V_46 , int V_47 , enum V_48 type ,
unsigned int V_35 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_47 = V_47 ;
V_5 . V_49 = V_46 ;
V_5 . V_50 = type ;
V_5 . V_51 = V_35 ;
return F_2 ( V_52 , & V_5 , sizeof( V_5 ) ) ;
}
int F_16 ( int V_47 , enum V_48 type )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_47 = V_47 ;
V_5 . V_50 = type ;
return F_2 ( V_53 , & V_5 , sizeof( V_5 ) ) ;
}
int F_17 ( int V_46 , int V_54 , void * V_55 , T_2 V_6 ,
void * V_56 , T_2 * V_57 , T_2 * V_58 ,
T_2 * V_59 )
{
union V_4 V_5 ;
int V_60 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_61 . V_46 = V_46 ;
V_5 . V_61 . V_62 = F_1 ( V_55 ) ;
V_5 . V_61 . V_56 = F_1 ( V_56 ) ;
V_5 . V_61 . V_63 = V_6 ;
V_5 . V_61 . V_54 = V_54 ;
V_60 = F_2 ( V_64 , & V_5 , sizeof( V_5 ) ) ;
if ( V_57 )
* V_57 = V_5 . V_61 . V_65 ;
if ( V_58 )
* V_58 = V_5 . V_61 . V_58 ;
if ( V_59 )
* V_59 = V_5 . V_61 . V_59 ;
return V_60 ;
}
int F_18 ( T_2 V_66 , T_2 * V_67 )
{
union V_4 V_5 ;
int V_68 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_66 = V_66 ;
V_68 = F_2 ( V_69 , & V_5 , sizeof( V_5 ) ) ;
if ( ! V_68 )
* V_67 = V_5 . V_67 ;
return V_68 ;
}
int F_19 ( T_2 V_66 , T_2 * V_67 )
{
union V_4 V_5 ;
int V_68 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_66 = V_66 ;
V_68 = F_2 ( V_70 , & V_5 , sizeof( V_5 ) ) ;
if ( ! V_68 )
* V_67 = V_5 . V_67 ;
return V_68 ;
}
int F_20 ( T_2 V_71 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_72 = V_71 ;
return F_2 ( V_73 , & V_5 , sizeof( V_5 ) ) ;
}
int F_21 ( T_2 V_71 )
{
union V_4 V_5 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_74 = V_71 ;
return F_2 ( V_75 , & V_5 , sizeof( V_5 ) ) ;
}
int F_22 ( int V_46 , void * V_76 , T_2 * V_77 )
{
union V_4 V_5 ;
int V_68 ;
F_7 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_76 . V_43 = V_46 ;
V_5 . V_76 . V_77 = * V_77 ;
V_5 . V_76 . V_76 = F_1 ( V_76 ) ;
V_68 = F_2 ( V_78 , & V_5 , sizeof( V_5 ) ) ;
if ( ! V_68 )
* V_77 = V_5 . V_76 . V_77 ;
return V_68 ;
}
