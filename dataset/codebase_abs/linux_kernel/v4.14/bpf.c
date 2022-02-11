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
int V_11 , int V_12 , T_2 V_13 ,
int V_14 )
{
union V_4 V_5 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = V_9 ;
V_5 . V_10 = V_10 ;
V_5 . V_11 = V_11 ;
V_5 . V_12 = V_12 ;
V_5 . V_13 = V_13 ;
if ( V_14 >= 0 ) {
V_5 . V_13 |= V_15 ;
V_5 . V_16 = V_14 ;
}
return F_2 ( V_17 , & V_5 , sizeof( V_5 ) ) ;
}
int F_5 ( enum V_8 V_9 , int V_10 ,
int V_11 , int V_12 , T_2 V_13 )
{
return F_4 ( V_9 , V_10 , V_11 ,
V_12 , V_13 , - 1 ) ;
}
int F_6 ( enum V_8 V_9 , int V_10 ,
int V_18 , int V_12 ,
T_2 V_13 , int V_14 )
{
union V_4 V_5 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = V_9 ;
V_5 . V_10 = V_10 ;
V_5 . V_11 = 4 ;
V_5 . V_18 = V_18 ;
V_5 . V_12 = V_12 ;
V_5 . V_13 = V_13 ;
if ( V_14 >= 0 ) {
V_5 . V_13 |= V_15 ;
V_5 . V_16 = V_14 ;
}
return F_2 ( V_17 , & V_5 , sizeof( V_5 ) ) ;
}
int F_7 ( enum V_8 V_9 , int V_10 ,
int V_18 , int V_12 , T_2 V_13 )
{
return F_6 ( V_9 , V_10 , V_18 ,
V_12 , V_13 , - 1 ) ;
}
int F_8 ( enum V_19 type , const struct V_20 * V_21 ,
T_3 V_22 , const char * V_23 ,
T_2 V_24 , char * V_25 , T_3 V_26 )
{
int V_27 ;
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_28 = type ;
V_5 . V_29 = ( T_2 ) V_22 ;
V_5 . V_21 = F_1 ( V_21 ) ;
V_5 . V_23 = F_1 ( V_23 ) ;
V_5 . V_25 = F_1 ( NULL ) ;
V_5 . V_30 = 0 ;
V_5 . V_31 = 0 ;
V_5 . V_24 = V_24 ;
V_27 = F_2 ( V_32 , & V_5 , sizeof( V_5 ) ) ;
if ( V_27 >= 0 || ! V_25 || ! V_26 )
return V_27 ;
V_5 . V_25 = F_1 ( V_25 ) ;
V_5 . V_30 = V_26 ;
V_5 . V_31 = 1 ;
V_25 [ 0 ] = 0 ;
return F_2 ( V_32 , & V_5 , sizeof( V_5 ) ) ;
}
int F_10 ( enum V_19 type , const struct V_20 * V_21 ,
T_3 V_22 , int V_33 ,
const char * V_23 , T_2 V_24 ,
char * V_25 , T_3 V_26 , int V_31 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_28 = type ;
V_5 . V_29 = ( T_2 ) V_22 ;
V_5 . V_21 = F_1 ( V_21 ) ;
V_5 . V_23 = F_1 ( V_23 ) ;
V_5 . V_25 = F_1 ( V_25 ) ;
V_5 . V_30 = V_26 ;
V_5 . V_31 = V_31 ;
V_25 [ 0 ] = 0 ;
V_5 . V_24 = V_24 ;
V_5 . V_34 = V_33 ? V_35 : 0 ;
return F_2 ( V_32 , & V_5 , sizeof( V_5 ) ) ;
}
int F_11 ( int V_27 , const void * V_36 , const void * V_37 ,
T_1 V_38 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_39 = V_27 ;
V_5 . V_36 = F_1 ( V_36 ) ;
V_5 . V_37 = F_1 ( V_37 ) ;
V_5 . V_38 = V_38 ;
return F_2 ( V_40 , & V_5 , sizeof( V_5 ) ) ;
}
int F_12 ( int V_27 , const void * V_36 , void * V_37 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_39 = V_27 ;
V_5 . V_36 = F_1 ( V_36 ) ;
V_5 . V_37 = F_1 ( V_37 ) ;
return F_2 ( V_41 , & V_5 , sizeof( V_5 ) ) ;
}
int F_13 ( int V_27 , const void * V_36 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_39 = V_27 ;
V_5 . V_36 = F_1 ( V_36 ) ;
return F_2 ( V_42 , & V_5 , sizeof( V_5 ) ) ;
}
int F_14 ( int V_27 , const void * V_36 , void * V_43 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_39 = V_27 ;
V_5 . V_36 = F_1 ( V_36 ) ;
V_5 . V_43 = F_1 ( V_43 ) ;
return F_2 ( V_44 , & V_5 , sizeof( V_5 ) ) ;
}
int F_15 ( int V_27 , const char * V_45 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_45 = F_1 ( ( void * ) V_45 ) ;
V_5 . V_46 = V_27 ;
return F_2 ( V_47 , & V_5 , sizeof( V_5 ) ) ;
}
int F_16 ( const char * V_45 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_45 = F_1 ( ( void * ) V_45 ) ;
return F_2 ( V_48 , & V_5 , sizeof( V_5 ) ) ;
}
int F_17 ( int V_49 , int V_50 , enum V_51 type ,
unsigned int V_38 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_50 = V_50 ;
V_5 . V_52 = V_49 ;
V_5 . V_53 = type ;
V_5 . V_54 = V_38 ;
return F_2 ( V_55 , & V_5 , sizeof( V_5 ) ) ;
}
int F_18 ( int V_50 , enum V_51 type )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_50 = V_50 ;
V_5 . V_53 = type ;
return F_2 ( V_56 , & V_5 , sizeof( V_5 ) ) ;
}
int F_19 ( int V_49 , int V_57 , void * V_58 , T_2 V_6 ,
void * V_59 , T_2 * V_60 , T_2 * V_61 ,
T_2 * V_62 )
{
union V_4 V_5 ;
int V_63 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_64 . V_49 = V_49 ;
V_5 . V_64 . V_65 = F_1 ( V_58 ) ;
V_5 . V_64 . V_59 = F_1 ( V_59 ) ;
V_5 . V_64 . V_66 = V_6 ;
V_5 . V_64 . V_57 = V_57 ;
V_63 = F_2 ( V_67 , & V_5 , sizeof( V_5 ) ) ;
if ( V_60 )
* V_60 = V_5 . V_64 . V_68 ;
if ( V_61 )
* V_61 = V_5 . V_64 . V_61 ;
if ( V_62 )
* V_62 = V_5 . V_64 . V_62 ;
return V_63 ;
}
int F_20 ( T_2 V_69 , T_2 * V_70 )
{
union V_4 V_5 ;
int V_71 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_69 = V_69 ;
V_71 = F_2 ( V_72 , & V_5 , sizeof( V_5 ) ) ;
if ( ! V_71 )
* V_70 = V_5 . V_70 ;
return V_71 ;
}
int F_21 ( T_2 V_69 , T_2 * V_70 )
{
union V_4 V_5 ;
int V_71 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_69 = V_69 ;
V_71 = F_2 ( V_73 , & V_5 , sizeof( V_5 ) ) ;
if ( ! V_71 )
* V_70 = V_5 . V_70 ;
return V_71 ;
}
int F_22 ( T_2 V_74 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_75 = V_74 ;
return F_2 ( V_76 , & V_5 , sizeof( V_5 ) ) ;
}
int F_23 ( T_2 V_74 )
{
union V_4 V_5 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_77 = V_74 ;
return F_2 ( V_78 , & V_5 , sizeof( V_5 ) ) ;
}
int F_24 ( int V_49 , void * V_79 , T_2 * V_80 )
{
union V_4 V_5 ;
int V_71 ;
F_9 ( & V_5 , sizeof( V_5 ) ) ;
V_5 . V_79 . V_46 = V_49 ;
V_5 . V_79 . V_80 = * V_80 ;
V_5 . V_79 . V_79 = F_1 ( V_79 ) ;
V_71 = F_2 ( V_81 , & V_5 , sizeof( V_5 ) ) ;
if ( ! V_71 )
* V_80 = V_5 . V_79 . V_80 ;
return V_71 ;
}
