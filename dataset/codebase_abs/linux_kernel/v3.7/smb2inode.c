static int
F_1 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_1 V_7 , T_1 V_8 ,
T_1 V_9 , T_1 V_10 ,
void * V_11 , int V_12 )
{
int V_13 , V_14 = 0 ;
T_2 V_15 , V_16 ;
T_3 * V_17 ;
T_4 V_18 = V_19 ;
V_17 = F_2 ( V_6 , V_5 ) ;
if ( ! V_17 )
return - V_20 ;
V_13 = F_3 ( V_1 , V_3 , V_17 , & V_15 , & V_16 ,
V_7 , V_8 , V_9 ,
V_10 , & V_18 , NULL ) ;
if ( V_13 ) {
F_4 ( V_17 ) ;
return V_13 ;
}
switch ( V_12 ) {
case V_21 :
break;
case V_22 :
V_14 = F_5 ( V_1 , V_3 , V_15 ,
V_16 ,
(struct V_23 * ) V_11 ) ;
break;
case V_24 :
break;
case V_25 :
V_14 = F_6 ( V_1 , V_3 , V_15 , V_16 ,
( T_3 * ) V_11 ) ;
break;
case V_26 :
V_14 = F_7 ( V_1 , V_3 , V_15 ,
V_16 , ( T_3 * ) V_11 ) ;
break;
case V_27 :
V_14 = F_8 ( V_1 , V_3 , V_15 , V_16 ,
V_28 -> V_29 , ( V_30 * ) V_11 ) ;
break;
case V_31 :
V_14 = F_9 ( V_1 , V_3 , V_15 , V_16 ,
( V_32 * ) V_11 ) ;
break;
default:
F_10 ( 1 , L_1 ) ;
break;
}
V_13 = F_11 ( V_1 , V_3 , V_15 , V_16 ) ;
if ( V_14 )
V_13 = V_14 ;
F_4 ( V_17 ) ;
return V_13 ;
}
void
F_12 ( T_5 * V_33 , struct V_23 * V_34 )
{
memcpy ( V_33 , V_34 , ( V_35 ) ( & V_34 -> V_36 ) - ( V_35 ) V_34 ) ;
V_33 -> V_36 = V_34 -> V_36 ;
V_33 -> V_37 = V_34 -> V_37 ;
V_33 -> V_38 = V_34 -> V_38 ;
V_33 -> V_39 = 0 ;
}
int
F_13 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_5 * V_11 , bool * V_40 )
{
int V_13 ;
struct V_23 * V_41 ;
* V_40 = false ;
V_41 = F_14 ( sizeof( struct V_23 ) + V_42 * 2 ,
V_43 ) ;
if ( V_41 == NULL )
return - V_20 ;
V_13 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_44 , V_45 , 0 , 0 ,
V_41 , V_22 ) ;
if ( V_13 )
goto V_46;
F_12 ( V_11 , V_41 ) ;
V_46:
F_4 ( V_41 ) ;
return V_13 ;
}
int
F_15 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_47 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_47 ,
V_48 , V_49 , 0 ,
V_50 , NULL , V_24 ) ;
}
void
F_16 ( struct V_51 * V_51 , const char * V_47 ,
struct V_4 * V_5 , struct V_2 * V_3 ,
const unsigned int V_1 )
{
V_32 V_11 ;
struct V_52 * V_53 ;
T_6 V_54 ;
int V_14 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_53 = F_17 ( V_51 ) ;
V_54 = V_53 -> V_55 | V_56 ;
V_11 . V_57 = F_18 ( V_54 ) ;
V_14 = F_1 ( V_1 , V_3 , V_5 , V_47 ,
V_48 , V_49 , 0 ,
V_50 , & V_11 , V_31 ) ;
if ( V_14 == 0 )
V_53 -> V_55 = V_54 ;
}
int
F_19 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_47 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_47 , V_58 , V_45 ,
0 , V_50 | V_59 ,
NULL , V_21 ) ;
}
int
F_20 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_47 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_47 , V_58 , V_45 ,
0 , V_59 , NULL ,
V_21 ) ;
}
static int
F_21 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_60 , const char * V_61 ,
struct V_4 * V_5 , T_1 V_62 , int V_12 )
{
T_3 * V_63 = NULL ;
int V_13 ;
V_63 = F_2 ( V_61 , V_5 ) ;
if ( V_63 == NULL ) {
V_13 = - V_20 ;
goto V_64;
}
V_13 = F_1 ( V_1 , V_3 , V_5 , V_60 , V_62 ,
V_45 , 0 , 0 , V_63 , V_12 ) ;
V_64:
F_4 ( V_63 ) ;
return V_13 ;
}
int
V_64 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_60 , const char * V_61 ,
struct V_4 * V_5 )
{
return F_21 ( V_1 , V_3 , V_60 , V_61 , V_5 ,
V_58 , V_25 ) ;
}
int
F_22 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_60 , const char * V_61 ,
struct V_4 * V_5 )
{
return F_21 ( V_1 , V_3 , V_60 , V_61 , V_5 ,
V_44 , V_26 ) ;
}
int
F_23 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_6 , T_7 V_65 ,
struct V_4 * V_5 , bool V_66 )
{
V_30 V_67 = F_24 ( V_65 ) ;
return F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_68 , V_45 , 0 , 0 , & V_67 ,
V_27 ) ;
}
int
F_25 ( struct V_51 * V_51 , const char * V_6 ,
V_32 * V_69 , const unsigned int V_1 )
{
struct V_4 * V_5 = F_26 ( V_51 -> V_70 ) ;
struct V_71 * V_72 ;
int V_13 ;
V_72 = F_27 ( V_5 ) ;
if ( F_28 ( V_72 ) )
return F_29 ( V_72 ) ;
V_13 = F_1 ( V_1 , F_30 ( V_72 ) , V_5 , V_6 ,
V_48 , V_45 , 0 , 0 , V_69 ,
V_31 ) ;
F_31 ( V_72 ) ;
return V_13 ;
}
