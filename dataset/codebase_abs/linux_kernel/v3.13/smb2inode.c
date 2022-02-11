static int
F_1 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_1 V_7 , T_1 V_8 ,
T_1 V_9 , void * V_10 , int V_11 )
{
int V_12 , V_13 = 0 ;
T_2 * V_14 ;
T_3 V_15 = V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
V_14 = F_2 ( V_6 , V_5 ) ;
if ( ! V_14 )
return - V_21 ;
V_18 . V_3 = V_3 ;
V_18 . V_7 = V_7 ;
V_18 . V_22 = V_8 ;
V_18 . V_9 = V_9 ;
V_18 . V_20 = & V_20 ;
V_18 . V_23 = false ;
V_12 = F_3 ( V_1 , & V_18 , V_14 , & V_15 , NULL , NULL ) ;
if ( V_12 ) {
F_4 ( V_14 ) ;
return V_12 ;
}
switch ( V_11 ) {
case V_24 :
break;
case V_25 :
V_13 = F_5 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 ,
(struct V_28 * ) V_10 ) ;
break;
case V_29 :
break;
case V_30 :
V_13 = F_6 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 , ( T_2 * ) V_10 ) ;
break;
case V_31 :
V_13 = F_7 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 , ( T_2 * ) V_10 ) ;
break;
case V_32 :
V_13 = F_8 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 , V_33 -> V_34 ,
( V_35 * ) V_10 ) ;
break;
case V_36 :
V_13 = F_9 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 ,
( V_37 * ) V_10 ) ;
break;
default:
F_10 ( V_38 , L_1 ) ;
break;
}
V_12 = F_11 ( V_1 , V_3 , V_20 . V_26 , V_20 . V_27 ) ;
if ( V_13 )
V_12 = V_13 ;
F_4 ( V_14 ) ;
return V_12 ;
}
void
F_12 ( T_4 * V_39 , struct V_28 * V_40 )
{
memcpy ( V_39 , V_40 , ( V_41 ) ( & V_40 -> V_42 ) - ( V_41 ) V_40 ) ;
V_39 -> V_42 = V_40 -> V_42 ;
V_39 -> V_43 = V_40 -> V_43 ;
V_39 -> V_44 = V_40 -> V_44 ;
V_39 -> V_45 = 0 ;
}
int
F_13 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_4 * V_10 , bool * V_46 , bool * V_47 )
{
int V_12 ;
struct V_28 * V_48 ;
* V_46 = false ;
* V_47 = false ;
V_48 = F_14 ( sizeof( struct V_28 ) + V_49 * 2 ,
V_50 ) ;
if ( V_48 == NULL )
return - V_21 ;
V_12 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_51 , V_52 , 0 ,
V_48 , V_25 ) ;
if ( V_12 == - V_53 ) {
* V_47 = true ;
V_12 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_51 , V_52 ,
V_54 , V_48 ,
V_25 ) ;
}
if ( V_12 )
goto V_55;
F_12 ( V_10 , V_48 ) ;
V_55:
F_4 ( V_48 ) ;
return V_12 ;
}
int
F_15 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_56 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_56 ,
V_57 , V_58 ,
V_59 , NULL , V_29 ) ;
}
void
F_16 ( struct V_60 * V_60 , const char * V_56 ,
struct V_4 * V_5 , struct V_2 * V_3 ,
const unsigned int V_1 )
{
V_37 V_10 ;
struct V_61 * V_62 ;
T_5 V_63 ;
int V_13 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_62 = F_17 ( V_60 ) ;
V_63 = V_62 -> V_64 | V_65 ;
V_10 . V_66 = F_18 ( V_63 ) ;
V_13 = F_1 ( V_1 , V_3 , V_5 , V_56 ,
V_57 , V_58 ,
V_59 , & V_10 , V_36 ) ;
if ( V_13 == 0 )
V_62 -> V_64 = V_63 ;
}
int
F_19 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_56 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_56 , V_67 , V_52 ,
V_59 | V_68 ,
NULL , V_24 ) ;
}
int
F_20 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_56 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_56 , V_67 , V_52 ,
V_68 | V_54 ,
NULL , V_24 ) ;
}
static int
F_21 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_69 , const char * V_70 ,
struct V_4 * V_5 , T_1 V_71 , int V_11 )
{
T_2 * V_72 = NULL ;
int V_12 ;
V_72 = F_2 ( V_70 , V_5 ) ;
if ( V_72 == NULL ) {
V_12 = - V_21 ;
goto V_73;
}
V_12 = F_1 ( V_1 , V_3 , V_5 , V_69 , V_71 ,
V_52 , 0 , V_72 , V_11 ) ;
V_73:
F_4 ( V_72 ) ;
return V_12 ;
}
int
V_73 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_69 , const char * V_70 ,
struct V_4 * V_5 )
{
return F_21 ( V_1 , V_3 , V_69 , V_70 , V_5 ,
V_67 , V_30 ) ;
}
int
F_22 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_69 , const char * V_70 ,
struct V_4 * V_5 )
{
return F_21 ( V_1 , V_3 , V_69 , V_70 , V_5 ,
V_51 , V_31 ) ;
}
int
F_23 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_6 , T_6 V_74 ,
struct V_4 * V_5 , bool V_75 )
{
V_35 V_76 = F_24 ( V_74 ) ;
return F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_77 , V_52 , 0 , & V_76 ,
V_32 ) ;
}
int
F_25 ( struct V_60 * V_60 , const char * V_6 ,
V_37 * V_78 , const unsigned int V_1 )
{
struct V_4 * V_5 = F_26 ( V_60 -> V_79 ) ;
struct V_80 * V_81 ;
int V_12 ;
V_81 = F_27 ( V_5 ) ;
if ( F_28 ( V_81 ) )
return F_29 ( V_81 ) ;
V_12 = F_1 ( V_1 , F_30 ( V_81 ) , V_5 , V_6 ,
V_57 , V_52 , 0 , V_78 ,
V_36 ) ;
F_31 ( V_81 ) ;
return V_12 ;
}
