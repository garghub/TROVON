static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
if ( V_3 -> V_5 > V_4 -> V_5 ) {
return 1 ;
} else if ( V_3 -> V_5 == V_4 -> V_5 ) {
if ( V_3 -> V_6 > V_4 -> V_6 ) {
return 1 ;
} else if ( V_3 -> V_6 == V_4 -> V_6 ) {
return 0 ;
}
return - 1 ;
} else{
return - 1 ;
}
}
void
F_2 ( T_4 * V_7 , int V_5 , T_5 V_6 , void * V_8 )
{
T_3 * V_9 = ( T_3 * ) F_3 ( F_4 () , sizeof( T_3 ) ) ;
V_9 -> V_5 = V_5 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_8 = V_8 ;
V_7 -> V_10 = F_5 ( V_7 -> V_10 ,
( V_11 * ) V_9 ,
F_1 ) ;
}
void *
F_6 ( T_4 * V_7 , int V_5 , T_5 V_6 )
{
T_3 V_12 , * V_9 ;
T_6 * V_13 ;
V_12 . V_5 = V_5 ;
V_12 . V_6 = V_6 ;
V_12 . V_8 = NULL ;
V_13 = F_7 ( V_7 -> V_10 , ( V_11 * ) & V_12 , F_1 ) ;
if ( V_13 ) {
V_9 = ( T_3 * ) V_13 -> V_14 ;
return V_9 -> V_8 ;
}
return NULL ;
}
void
F_8 ( T_4 * V_7 , int V_5 , T_5 V_6 )
{
T_3 V_12 ;
T_6 * V_13 ;
V_12 . V_5 = V_5 ;
V_12 . V_6 = V_6 ;
V_12 . V_8 = NULL ;
V_13 = F_7 ( V_7 -> V_10 , ( V_11 * ) & V_12 , F_1 ) ;
if ( V_13 ) {
V_7 -> V_10 = F_9 ( V_7 -> V_10 , V_13 -> V_14 ) ;
}
}
T_7 *
F_10 ( T_4 * V_7 , T_8 V_15 ) {
T_3 * V_12 ;
V_12 = ( T_3 * ) F_11 ( V_7 -> V_10 , V_15 ) ;
return F_12 ( L_1 , F_13 ( V_12 -> V_5 ) , V_12 -> V_6 ) ;
}
void
F_14 ( const struct V_16 * V_17 , const T_4 * V_18 , T_9 V_19 , T_10 * V_20 )
{
const T_10 * V_21 = ( V_19 ) ? F_15 ( V_17 , V_19 ) : NULL ;
if ( V_21 ) {
F_16 ( V_20 , & V_18 -> V_22 , V_21 ) ;
} else {
F_17 ( V_20 ) ;
}
}
static T_1
F_18 ( const struct V_16 * V_17 , const T_4 * V_23 , const T_4 * V_24 )
{
T_10 V_25 , V_26 ;
F_14 ( V_17 , V_23 , V_23 -> V_27 - 1 , & V_25 ) ;
F_14 ( V_17 , V_24 , V_24 -> V_27 - 1 , & V_26 ) ;
return F_19 ( V_25 , V_26 ) ;
}
static T_1
F_20 ( const struct V_16 * V_17 , const T_4 * V_23 , const T_4 * V_24 )
{
T_10 V_28 , V_29 ;
F_14 ( V_17 , V_23 , V_23 -> V_30 , & V_28 ) ;
F_14 ( V_17 , V_24 , V_24 -> V_30 , & V_29 ) ;
return F_19 ( V_28 , V_29 ) ;
}
static T_1
F_21 ( const struct V_16 * V_17 , const T_4 * V_23 , const T_4 * V_24 )
{
T_10 V_31 , V_32 ;
F_14 ( V_17 , V_23 , V_23 -> V_33 , & V_31 ) ;
F_14 ( V_17 , V_24 , V_24 -> V_33 , & V_32 ) ;
return F_19 ( V_31 , V_32 ) ;
}
T_1
F_22 ( const struct V_16 * V_17 , const T_4 * V_23 , const T_4 * V_24 , int V_34 )
{
switch ( V_34 ) {
case V_35 :
return F_23 () ;
case V_36 :
switch ( F_24 () ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return F_25 ( V_22 ) ;
case V_42 :
return F_20 ( V_17 , V_23 , V_24 ) ;
case V_43 :
return F_18 ( V_17 , V_23 , V_24 ) ;
case V_44 :
return F_21 ( V_17 , V_23 , V_24 ) ;
case V_45 :
return 0 ;
}
return 0 ;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return F_25 ( V_22 ) ;
case V_50 :
return F_20 ( V_17 , V_23 , V_24 ) ;
case V_51 :
return F_18 ( V_17 , V_23 , V_24 ) ;
case V_52 :
return F_21 ( V_17 , V_23 , V_24 ) ;
case V_53 :
return F_26 ( V_54 ) ;
case V_55 :
return F_26 ( V_56 ) ;
}
F_27 ( 0 ) ;
}
void
F_28 ( T_4 * V_18 , T_9 V_27 ,
const struct V_57 * V_58 , T_11 V_59 ,
T_9 V_56 )
{
V_18 -> V_10 = NULL ;
V_18 -> V_27 = V_27 ;
V_18 -> V_54 = V_58 -> V_60 ;
V_18 -> V_56 = V_56 + V_58 -> V_60 ;
V_18 -> V_61 = V_58 -> V_62 ;
V_18 -> V_63 = V_59 ;
V_18 -> V_64 = 0 ;
F_29 ( V_58 -> V_65 <= V_66 ) ;
V_18 -> V_67 = ( V_68 ) V_58 -> V_65 ;
V_18 -> V_69 . V_70 = 0 ;
V_18 -> V_69 . V_71 = 0 ;
V_18 -> V_69 . V_72 = V_73 ;
V_18 -> V_69 . V_74 = 0 ;
V_18 -> V_69 . V_75 = 0 ;
V_18 -> V_69 . V_76 = 0 ;
V_18 -> V_69 . V_77 = 0 ;
V_18 -> V_69 . V_78 = ( V_58 -> V_79 & V_80 ) ? 1 : 0 ;
V_18 -> V_69 . V_81 = ( V_58 -> V_82 != NULL ) ;
V_18 -> V_69 . V_83 = 0 ;
V_18 -> V_84 = NULL ;
V_18 -> V_22 . V_85 = V_58 -> V_86 . V_85 ;
V_18 -> V_22 . V_87 = V_58 -> V_86 . V_87 ;
V_18 -> V_88 . V_85 = 0 ;
V_18 -> V_88 . V_87 = 0 ;
V_18 -> V_30 = 0 ;
V_18 -> V_33 = 0 ;
}
void
F_30 ( T_4 * V_18 ,
T_10 * V_89 ,
const T_4 * * V_90 ,
const T_4 * V_91 )
{
T_10 V_92 ;
if ( * V_90 == NULL )
* V_90 = V_18 ;
if( V_18 -> V_69 . V_76 )
* V_90 = V_18 ;
F_16 ( & V_92 , & V_18 -> V_22 , & ( * V_90 ) -> V_22 ) ;
if ( ( V_93 ) V_89 -> V_85 < V_92 . V_85
|| ( ( V_93 ) V_89 -> V_85 == V_92 . V_85 && ( V_93 ) V_89 -> V_87 < V_92 . V_87 ) ) {
* V_89 = V_92 ;
}
V_18 -> V_30 = ( * V_90 != V_18 ) ? ( * V_90 ) -> V_27 : 0 ;
V_18 -> V_33 = ( V_91 ) ? V_91 -> V_27 : 0 ;
}
void
F_31 ( T_4 * V_18 ,
T_9 * V_56 )
{
if( V_18 -> V_69 . V_76 ) {
* V_56 = V_18 -> V_54 ;
V_18 -> V_56 = * V_56 ;
} else {
* V_56 += V_18 -> V_54 ;
V_18 -> V_56 = * V_56 ;
}
}
void
F_32 ( T_4 * V_18 )
{
V_18 -> V_69 . V_74 = 0 ;
if ( V_18 -> V_10 ) {
F_33 ( V_18 -> V_10 ) ;
V_18 -> V_10 = NULL ;
}
}
void
F_34 ( T_4 * V_18 )
{
if ( V_18 -> V_10 ) {
F_33 ( V_18 -> V_10 ) ;
V_18 -> V_10 = NULL ;
}
}
