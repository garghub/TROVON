static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
if ( V_3 -> V_5 > V_4 -> V_5 )
return 1 ;
else if ( V_3 -> V_5 == V_4 -> V_5 )
return 0 ;
else
return - 1 ;
}
void
F_2 ( T_4 * V_6 , int V_5 , void * V_7 )
{
T_3 * V_8 = F_3 ( sizeof( T_3 ) ) ;
V_8 -> V_5 = V_5 ;
V_8 -> V_7 = V_7 ;
V_6 -> V_9 = F_4 ( V_6 -> V_9 ,
( V_10 * ) V_8 ,
F_1 ) ;
}
void *
F_5 ( T_4 * V_6 , int V_5 )
{
T_3 V_11 , * V_8 ;
T_5 * V_12 ;
V_11 . V_5 = V_5 ;
V_11 . V_7 = NULL ;
V_12 = F_6 ( V_6 -> V_9 , ( V_10 * ) & V_11 , F_1 ) ;
if ( V_12 ) {
V_8 = ( T_3 * ) V_12 -> V_13 ;
return V_8 -> V_7 ;
}
return NULL ;
}
void
F_7 ( T_4 * V_6 , int V_5 )
{
T_3 V_11 ;
T_5 * V_12 ;
V_11 . V_5 = V_5 ;
V_11 . V_7 = NULL ;
V_12 = F_6 ( V_6 -> V_9 , ( V_10 * ) & V_11 , F_1 ) ;
if ( V_12 ) {
V_6 -> V_9 = F_8 ( V_6 -> V_9 , V_12 -> V_13 ) ;
}
}
T_1
F_9 ( const T_4 * V_14 , const T_4 * V_15 , int V_16 )
{
switch ( V_16 ) {
case V_17 :
return F_10 () ;
case V_18 :
switch ( F_11 () ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return F_12 ( V_24 ) ;
case V_25 :
return F_12 ( V_26 ) ;
case V_27 :
return F_12 ( V_28 ) ;
case V_29 :
return F_12 ( V_30 ) ;
case V_31 :
return 0 ;
}
return 0 ;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_12 ( V_24 ) ;
case V_36 :
return F_12 ( V_26 ) ;
case V_37 :
return F_12 ( V_28 ) ;
case V_38 :
return F_12 ( V_30 ) ;
case V_39 :
return F_13 ( V_40 ) ;
case V_41 :
return F_13 ( V_42 ) ;
}
F_14 ( 0 ) ;
}
void
F_15 ( T_4 * V_43 , T_6 V_44 ,
const struct V_45 * V_46 , T_7 V_47 ,
T_6 V_42 )
{
V_43 -> V_9 = NULL ;
V_43 -> V_44 = V_44 ;
V_43 -> V_48 = V_46 -> V_48 ;
V_43 -> V_40 = V_46 -> V_49 ;
V_43 -> V_42 = V_42 + V_46 -> V_49 ;
V_43 -> V_50 = V_46 -> V_51 ;
V_43 -> V_52 = V_47 ;
V_43 -> V_53 = 0 ;
F_16 ( V_46 -> V_54 <= V_55 ) ;
V_43 -> V_56 = ( V_57 ) V_46 -> V_54 ;
V_43 -> V_58 . V_59 = 0 ;
V_43 -> V_58 . V_60 = 0 ;
V_43 -> V_58 . V_61 = V_62 ;
V_43 -> V_58 . V_63 = 0 ;
V_43 -> V_58 . V_64 = 0 ;
V_43 -> V_58 . V_65 = 0 ;
V_43 -> V_58 . V_66 = 0 ;
V_43 -> V_58 . V_67 = ( V_46 -> V_68 & V_69 ) ? 1 : 0 ;
V_43 -> V_58 . V_70 = ( V_46 -> V_68 & V_71 ) ? 1 : 0 ;
V_43 -> V_72 = NULL ;
V_43 -> V_24 . V_73 = V_46 -> V_74 . V_73 ;
V_43 -> V_24 . V_75 = V_46 -> V_74 . V_75 ;
V_43 -> V_76 . V_73 = 0 ;
V_43 -> V_76 . V_75 = 0 ;
V_43 -> V_26 . V_73 = 0 ;
V_43 -> V_26 . V_75 = 0 ;
V_43 -> V_30 . V_73 = 0 ;
V_43 -> V_30 . V_75 = 0 ;
V_43 -> V_28 . V_73 = 0 ;
V_43 -> V_28 . V_75 = 0 ;
V_43 -> V_77 = V_46 -> V_77 ;
}
void
F_17 ( T_4 * V_43 ,
T_8 * V_78 ,
T_8 * V_79 ,
T_8 * V_80 ,
T_8 * V_81 )
{
if ( F_18 ( V_79 ) )
* V_79 = V_43 -> V_24 ;
if( V_43 -> V_58 . V_65 )
* V_79 = V_43 -> V_24 ;
if ( F_18 ( V_81 ) )
* V_81 = V_43 -> V_24 ;
F_19 ( & V_43 -> V_26 , & V_43 -> V_24 , V_79 ) ;
if ( ( V_82 ) V_78 -> V_73 < V_43 -> V_26 . V_73
|| ( ( V_82 ) V_78 -> V_73 == V_43 -> V_26 . V_73 && ( V_82 ) V_78 -> V_75 < V_43 -> V_26 . V_75 ) ) {
* V_78 = V_43 -> V_26 ;
}
if ( F_18 ( V_80 ) )
F_20 ( & V_43 -> V_30 ) ;
else
F_19 ( & V_43 -> V_30 , & V_43 -> V_24 , V_80 ) ;
F_19 ( & V_43 -> V_28 , & V_43 -> V_24 , V_81 ) ;
* V_81 = V_43 -> V_24 ;
}
void
F_21 ( T_4 * V_43 ,
T_6 * V_42 ,
T_8 * V_80 )
{
if( V_43 -> V_58 . V_65 ) {
* V_42 = V_43 -> V_40 ;
V_43 -> V_42 = * V_42 ;
} else {
* V_42 += V_43 -> V_40 ;
V_43 -> V_42 = * V_42 ;
}
* V_80 = V_43 -> V_24 ;
}
void
F_22 ( T_4 * V_43 )
{
if ( V_43 -> V_9 )
F_23 ( V_43 -> V_9 ) ;
V_43 -> V_9 = NULL ;
}
