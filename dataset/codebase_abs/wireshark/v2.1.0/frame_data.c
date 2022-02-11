void
F_1 ( const struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 , T_3 * V_5 )
{
const T_3 * V_6 = ( V_4 ) ? F_2 ( V_2 , V_4 ) : NULL ;
if ( V_6 ) {
F_3 ( V_5 , & V_3 -> V_7 , V_6 ) ;
} else {
F_4 ( V_5 ) ;
}
}
static T_4
F_5 ( const struct V_1 * V_2 , const T_1 * V_8 , const T_1 * V_9 )
{
T_3 V_10 , V_11 ;
F_1 ( V_2 , V_8 , V_8 -> V_12 - 1 , & V_10 ) ;
F_1 ( V_2 , V_9 , V_9 -> V_12 - 1 , & V_11 ) ;
return F_6 ( V_10 , V_11 ) ;
}
static T_4
F_7 ( const struct V_1 * V_2 , const T_1 * V_8 , const T_1 * V_9 )
{
T_3 V_13 , V_14 ;
F_1 ( V_2 , V_8 , V_8 -> V_15 , & V_13 ) ;
F_1 ( V_2 , V_9 , V_9 -> V_15 , & V_14 ) ;
return F_6 ( V_13 , V_14 ) ;
}
static T_4
F_8 ( const struct V_1 * V_2 , const T_1 * V_8 , const T_1 * V_9 )
{
T_3 V_16 , V_17 ;
F_1 ( V_2 , V_8 , V_8 -> V_18 , & V_16 ) ;
F_1 ( V_2 , V_9 , V_9 -> V_18 , & V_17 ) ;
return F_6 ( V_16 , V_17 ) ;
}
T_4
F_9 ( const struct V_1 * V_2 , const T_1 * V_8 , const T_1 * V_9 , int V_19 )
{
switch ( V_19 ) {
case V_20 :
return F_10 () ;
case V_21 :
switch ( F_11 () ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return F_12 ( V_7 ) ;
case V_29 :
return F_7 ( V_2 , V_8 , V_9 ) ;
case V_30 :
return F_5 ( V_2 , V_8 , V_9 ) ;
case V_31 :
return F_8 ( V_2 , V_8 , V_9 ) ;
case V_32 :
return 0 ;
}
return 0 ;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
return F_12 ( V_7 ) ;
case V_39 :
return F_7 ( V_2 , V_8 , V_9 ) ;
case V_40 :
return F_5 ( V_2 , V_8 , V_9 ) ;
case V_41 :
return F_8 ( V_2 , V_8 , V_9 ) ;
case V_42 :
return F_13 ( V_43 ) ;
case V_44 :
return F_13 ( V_45 ) ;
}
F_14 ( 0 ) ;
}
void
F_15 ( T_1 * V_3 , T_2 V_12 ,
const struct V_46 * V_47 , T_5 V_48 ,
T_2 V_45 )
{
V_3 -> V_49 = NULL ;
V_3 -> V_12 = V_12 ;
V_3 -> V_43 = V_47 -> V_50 ;
V_3 -> V_45 = V_45 + V_47 -> V_50 ;
V_3 -> V_51 = V_47 -> V_52 ;
V_3 -> V_53 = V_48 ;
V_3 -> V_54 = 0 ;
F_16 ( V_47 -> V_55 <= V_56 ) ;
V_3 -> V_57 . V_58 = 0 ;
V_3 -> V_57 . V_59 = 0 ;
V_3 -> V_57 . V_60 = V_61 ;
V_3 -> V_57 . V_62 = 0 ;
V_3 -> V_57 . V_63 = 0 ;
V_3 -> V_57 . V_64 = 0 ;
V_3 -> V_57 . V_65 = 0 ;
V_3 -> V_57 . V_66 = ( V_47 -> V_67 & V_68 ) ? 1 : 0 ;
V_3 -> V_57 . V_69 = ( V_47 -> V_70 != NULL ) ;
V_3 -> V_57 . V_71 = 0 ;
V_3 -> V_57 . V_72 = 0 ;
V_3 -> V_73 = ( V_74 ) V_47 -> V_75 ;
V_3 -> V_76 = NULL ;
V_3 -> V_7 = V_47 -> V_77 ;
V_3 -> V_78 . V_79 = 0 ;
V_3 -> V_78 . V_80 = 0 ;
V_3 -> V_15 = 0 ;
V_3 -> V_18 = 0 ;
}
void
F_17 ( T_1 * V_3 ,
T_3 * V_81 ,
const T_1 * * V_82 ,
const T_1 * V_83 )
{
T_3 V_84 ;
if ( * V_82 == NULL )
* V_82 = V_3 ;
if( V_3 -> V_57 . V_64 )
* V_82 = V_3 ;
F_3 ( & V_84 , & V_3 -> V_7 , & ( * V_82 ) -> V_7 ) ;
if ( ( V_85 ) V_81 -> V_79 < V_84 . V_79
|| ( ( V_85 ) V_81 -> V_79 == V_84 . V_79 && ( V_85 ) V_81 -> V_80 < V_84 . V_80 ) ) {
* V_81 = V_84 ;
}
V_3 -> V_15 = ( * V_82 != V_3 ) ? ( * V_82 ) -> V_12 : 0 ;
V_3 -> V_18 = ( V_83 ) ? V_83 -> V_12 : 0 ;
}
void
F_18 ( T_1 * V_3 ,
T_2 * V_45 )
{
if( V_3 -> V_57 . V_64 ) {
* V_45 = V_3 -> V_43 ;
V_3 -> V_45 = * V_45 ;
} else {
* V_45 += V_3 -> V_43 ;
V_3 -> V_45 = * V_45 ;
}
}
void
F_19 ( T_1 * V_3 )
{
V_3 -> V_57 . V_62 = 0 ;
V_3 -> V_54 = 0 ;
if ( V_3 -> V_49 ) {
F_20 ( V_3 -> V_49 ) ;
V_3 -> V_49 = NULL ;
}
}
void
F_21 ( T_1 * V_3 )
{
if ( V_3 -> V_49 ) {
F_20 ( V_3 -> V_49 ) ;
V_3 -> V_49 = NULL ;
}
}
