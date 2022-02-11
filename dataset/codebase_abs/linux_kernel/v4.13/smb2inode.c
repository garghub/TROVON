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
V_20 . V_27 ) ;
break;
case V_31 :
V_13 = F_7 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 , ( T_2 * ) V_10 ) ;
break;
case V_32 :
V_13 = F_8 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 , ( T_2 * ) V_10 ) ;
break;
case V_33 :
V_13 = F_9 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 , V_34 -> V_35 ,
( V_36 * ) V_10 , false ) ;
break;
case V_37 :
V_13 = F_10 ( V_1 , V_3 , V_20 . V_26 ,
V_20 . V_27 ,
( V_38 * ) V_10 ) ;
break;
default:
F_11 ( V_39 , L_1 ) ;
break;
}
V_12 = F_12 ( V_1 , V_3 , V_20 . V_26 , V_20 . V_27 ) ;
if ( V_13 )
V_12 = V_13 ;
F_4 ( V_14 ) ;
return V_12 ;
}
void
F_13 ( T_4 * V_40 , struct V_28 * V_41 )
{
memcpy ( V_40 , V_41 , ( V_42 ) ( & V_41 -> V_43 ) - ( V_42 ) V_41 ) ;
V_40 -> V_43 = V_41 -> V_43 ;
V_40 -> V_44 = V_41 -> V_44 ;
V_40 -> V_45 = V_41 -> V_45 ;
V_40 -> V_46 = 0 ;
}
int
F_14 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_4 * V_10 , bool * V_47 , bool * V_48 )
{
int V_12 ;
struct V_28 * V_49 ;
* V_47 = false ;
* V_48 = false ;
V_49 = F_15 ( sizeof( struct V_28 ) + V_50 * 2 ,
V_51 ) ;
if ( V_49 == NULL )
return - V_21 ;
V_12 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_52 , V_53 , 0 ,
V_49 , V_25 ) ;
if ( V_12 == - V_54 ) {
* V_48 = true ;
V_12 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_52 , V_53 ,
V_55 , V_49 ,
V_25 ) ;
}
if ( V_12 )
goto V_56;
F_13 ( V_10 , V_49 ) ;
V_56:
F_4 ( V_49 ) ;
return V_12 ;
}
int
F_16 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_57 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_57 ,
V_58 , V_59 ,
V_60 , NULL , V_29 ) ;
}
void
F_17 ( struct V_61 * V_61 , const char * V_57 ,
struct V_4 * V_5 , struct V_2 * V_3 ,
const unsigned int V_1 )
{
V_38 V_10 ;
struct V_62 * V_63 ;
T_5 V_64 ;
int V_13 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_63 = F_18 ( V_61 ) ;
V_64 = V_63 -> V_65 | V_66 ;
V_10 . V_67 = F_19 ( V_64 ) ;
V_13 = F_1 ( V_1 , V_3 , V_5 , V_57 ,
V_58 , V_59 ,
V_60 , & V_10 , V_37 ) ;
if ( V_13 == 0 )
V_63 -> V_65 = V_64 ;
}
int
F_20 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_57 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_57 , V_68 , V_53 ,
V_60 ,
NULL , V_30 ) ;
}
int
F_21 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_57 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_57 , V_68 , V_53 ,
V_69 | V_55 ,
NULL , V_24 ) ;
}
static int
F_22 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_70 , const char * V_71 ,
struct V_4 * V_5 , T_1 V_72 , int V_11 )
{
T_2 * V_73 = NULL ;
int V_12 ;
V_73 = F_2 ( V_71 , V_5 ) ;
if ( V_73 == NULL ) {
V_12 = - V_21 ;
goto V_74;
}
V_12 = F_1 ( V_1 , V_3 , V_5 , V_70 , V_72 ,
V_53 , 0 , V_73 , V_11 ) ;
V_74:
F_4 ( V_73 ) ;
return V_12 ;
}
int
V_74 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_70 , const char * V_71 ,
struct V_4 * V_5 )
{
return F_22 ( V_1 , V_3 , V_70 , V_71 , V_5 ,
V_68 , V_31 ) ;
}
int
F_23 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_70 , const char * V_71 ,
struct V_4 * V_5 )
{
return F_22 ( V_1 , V_3 , V_70 , V_71 , V_5 ,
V_52 , V_32 ) ;
}
int
F_24 ( const unsigned int V_1 , struct V_2 * V_3 ,
const char * V_6 , T_6 V_75 ,
struct V_4 * V_5 , bool V_76 )
{
V_36 V_77 = F_25 ( V_75 ) ;
return F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_78 , V_53 , 0 , & V_77 ,
V_33 ) ;
}
int
F_26 ( struct V_61 * V_61 , const char * V_6 ,
V_38 * V_79 , const unsigned int V_1 )
{
struct V_4 * V_5 = F_27 ( V_61 -> V_80 ) ;
struct V_81 * V_82 ;
int V_12 ;
if ( ( V_79 -> V_83 == 0 ) && ( V_79 -> V_84 == 0 ) &&
( V_79 -> V_85 == 0 ) && ( V_79 -> V_86 ) &&
( V_79 -> V_67 == 0 ) )
return 0 ;
V_82 = F_28 ( V_5 ) ;
if ( F_29 ( V_82 ) )
return F_30 ( V_82 ) ;
V_12 = F_1 ( V_1 , F_31 ( V_82 ) , V_5 , V_6 ,
V_58 , V_53 , 0 , V_79 ,
V_37 ) ;
F_32 ( V_82 ) ;
return V_12 ;
}
