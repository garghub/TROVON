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
V_17 = F_2 ( V_6 , V_5 ) ;
if ( ! V_17 )
return - V_18 ;
V_13 = F_3 ( V_1 , V_3 , V_17 , & V_15 , & V_16 ,
V_7 , V_8 , V_9 ,
V_10 ) ;
if ( V_13 ) {
F_4 ( V_17 ) ;
return V_13 ;
}
switch ( V_12 ) {
case V_19 :
break;
case V_20 :
V_14 = F_5 ( V_1 , V_3 , V_15 ,
V_16 ,
(struct V_21 * ) V_11 ) ;
break;
case V_22 :
break;
default:
F_6 ( 1 , L_1 ) ;
break;
}
V_13 = F_7 ( V_1 , V_3 , V_15 , V_16 ) ;
if ( V_14 )
V_13 = V_14 ;
F_4 ( V_17 ) ;
return V_13 ;
}
static void
F_8 ( T_4 * V_23 , struct V_21 * V_24 )
{
memcpy ( V_23 , V_24 , ( V_25 ) ( & V_24 -> V_26 ) - ( V_25 ) V_24 ) ;
V_23 -> V_26 = V_24 -> V_26 ;
V_23 -> V_27 = V_24 -> V_27 ;
V_23 -> V_28 = V_24 -> V_28 ;
V_23 -> V_29 = 0 ;
}
int
F_9 ( const unsigned int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , const char * V_6 ,
T_4 * V_11 , bool * V_30 )
{
int V_13 ;
struct V_21 * V_31 ;
* V_30 = false ;
V_31 = F_10 ( sizeof( struct V_21 ) + V_32 * 2 ,
V_33 ) ;
if ( V_31 == NULL )
return - V_18 ;
V_13 = F_1 ( V_1 , V_3 , V_5 , V_6 ,
V_34 , V_35 , 0 , 0 ,
V_31 , V_20 ) ;
if ( V_13 )
goto V_36;
F_8 ( V_11 , V_31 ) ;
V_36:
F_4 ( V_31 ) ;
return V_13 ;
}
int
F_11 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_37 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_37 ,
V_38 , V_39 , 0 ,
V_40 , NULL , V_22 ) ;
}
void
F_12 ( struct V_41 * V_41 , const char * V_37 ,
struct V_4 * V_5 , struct V_2 * V_3 ,
const unsigned int V_1 )
{
T_5 V_11 ;
struct V_42 * V_43 ;
T_6 V_44 ;
int V_14 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_43 = F_13 ( V_41 ) ;
V_44 = V_43 -> V_45 | V_46 ;
V_11 . V_47 = F_14 ( V_44 ) ;
V_14 = F_1 ( V_1 , V_3 , V_5 , V_37 ,
V_38 , V_39 , 0 ,
V_40 , & V_11 , V_48 ) ;
if ( V_14 == 0 )
V_43 -> V_45 = V_44 ;
}
int
F_15 ( const unsigned int V_1 , struct V_2 * V_3 , const char * V_37 ,
struct V_4 * V_5 )
{
return F_1 ( V_1 , V_3 , V_5 , V_37 , V_49 , V_35 ,
0 , V_40 | V_50 ,
NULL , V_19 ) ;
}
