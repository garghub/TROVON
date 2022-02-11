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
F_10 ( V_33 , L_1 ) ;
break;
}
V_13 = F_11 ( V_1 , V_3 , V_15 , V_16 ) ;
if ( V_14 )
V_13 = V_14 ;
F_4 ( V_17 ) ;
return V_13 ;
}
void
F_12 ( T_5 * V_34 , struct V_23 * V_35 )
{
memcpy ( V_34 , V_35 , ( V_36 ) ( & V_35 -> V_37 ) - ( V_36 ) V_35 ) ;
V_34 -> V_37 = V_35 -> V_37 ;
V_34 -> V_38 = V_35 -> V_38 ;
V_34 -> V_39 = V_35 -> V_39 ;
V_34 -> V_40 = 0 ;
}
int
F_13 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_5 * V_11 , bool * V_41 )
{
int V_13 ;
struct V_23 * V_42 ;
* V_41 = false ;
V_42 = F_14 ( sizeof( struct V_23 ) + V_43 * 2 ,
V_44 ) ;
if ( V_42 == NULL )
return - V_20 ;
V_13 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_45 , V_46 , 0 , 0 ,
V_42 , V_22 ) ;
if ( V_13 )
goto V_47;
F_12 ( V_11 , V_42 ) ;
V_47:
F_4 ( V_42 ) ;
return V_13 ;
}
int
F_15 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_48 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_48 ,
V_49 , V_50 , 0 ,
V_51 , NULL , V_24 ) ;
}
void
F_16 ( struct V_52 * V_52 , const char * V_48 ,
struct V_4 * V_5 , struct V_2 * V_3 ,
const unsigned int V_1 )
{
V_32 V_11 ;
struct V_53 * V_54 ;
T_6 V_55 ;
int V_14 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_54 = F_17 ( V_52 ) ;
V_55 = V_54 -> V_56 | V_57 ;
V_11 . V_58 = F_18 ( V_55 ) ;
V_14 = F_1 ( V_1 , V_3 , V_5 , V_48 ,
V_49 , V_50 , 0 ,
V_51 , & V_11 , V_31 ) ;
if ( V_14 == 0 )
V_54 -> V_56 = V_55 ;
}
int
F_19 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_48 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_48 , V_59 , V_46 ,
0 , V_51 | V_60 ,
NULL , V_21 ) ;
}
int
F_20 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_48 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_48 , V_59 , V_46 ,
0 , V_60 , NULL ,
V_21 ) ;
}
static int
F_21 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_61 , const char * V_62 ,
struct V_4 * V_5 , T_1 V_63 , int V_12 )
{
T_3 * V_64 = NULL ;
int V_13 ;
V_64 = F_2 ( V_62 , V_5 ) ;
if ( V_64 == NULL ) {
V_13 = - V_20 ;
goto V_65;
}
V_13 = F_1 ( V_1 , V_3 , V_5 , V_61 , V_63 ,
V_46 , 0 , 0 , V_64 , V_12 ) ;
V_65:
F_4 ( V_64 ) ;
return V_13 ;
}
int
V_65 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_61 , const char * V_62 ,
struct V_4 * V_5 )
{
return F_21 ( V_1 , V_3 , V_61 , V_62 , V_5 ,
V_59 , V_25 ) ;
}
int
F_22 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_61 , const char * V_62 ,
struct V_4 * V_5 )
{
return F_21 ( V_1 , V_3 , V_61 , V_62 , V_5 ,
V_45 , V_26 ) ;
}
int
F_23 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_6 , T_7 V_66 ,
struct V_4 * V_5 , bool V_67 )
{
V_30 V_68 = F_24 ( V_66 ) ;
return F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_69 , V_46 , 0 , 0 , & V_68 ,
V_27 ) ;
}
int
F_25 ( struct V_52 * V_52 , const char * V_6 ,
V_32 * V_70 , const unsigned int V_1 )
{
struct V_4 * V_5 = F_26 ( V_52 -> V_71 ) ;
struct V_72 * V_73 ;
int V_13 ;
V_73 = F_27 ( V_5 ) ;
if ( F_28 ( V_73 ) )
return F_29 ( V_73 ) ;
V_13 = F_1 ( V_1 , F_30 ( V_73 ) , V_5 , V_6 ,
V_49 , V_46 , 0 , 0 , V_70 ,
V_31 ) ;
F_31 ( V_73 ) ;
return V_13 ;
}
