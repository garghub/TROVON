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
F_14 ( const T_4 * V_16 , const T_4 * V_17 , T_9 * V_18 )
{
if ( V_17 ) {
F_15 ( V_18 , & V_16 -> V_19 , & V_17 -> V_19 ) ;
} else {
F_16 ( V_18 ) ;
}
}
static T_1
F_17 ( const T_4 * V_20 , const T_4 * V_21 )
{
T_9 V_22 , V_23 ;
F_14 ( V_20 , V_20 -> V_24 , & V_22 ) ;
F_14 ( V_21 , V_21 -> V_24 , & V_23 ) ;
return F_18 ( V_22 , V_23 ) ;
}
static T_1
F_19 ( const T_4 * V_20 , const T_4 * V_21 )
{
T_9 V_25 , V_26 ;
F_14 ( V_20 , V_20 -> V_27 , & V_25 ) ;
F_14 ( V_21 , V_21 -> V_27 , & V_26 ) ;
return F_18 ( V_25 , V_26 ) ;
}
T_1
F_20 ( const T_4 * V_20 , const T_4 * V_21 , int V_28 )
{
switch ( V_28 ) {
case V_29 :
return F_21 () ;
case V_30 :
switch ( F_22 () ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_23 ( V_19 ) ;
case V_36 :
return F_23 ( V_37 ) ;
case V_38 :
return F_17 ( V_20 , V_21 ) ;
case V_39 :
return F_19 ( V_20 , V_21 ) ;
case V_40 :
return 0 ;
}
return 0 ;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return F_23 ( V_19 ) ;
case V_45 :
return F_23 ( V_37 ) ;
case V_46 :
return F_17 ( V_20 , V_21 ) ;
case V_47 :
return F_19 ( V_20 , V_21 ) ;
case V_48 :
return F_24 ( V_49 ) ;
case V_50 :
return F_24 ( V_51 ) ;
}
F_25 ( 0 ) ;
}
void
F_26 ( T_4 * V_16 , T_10 V_52 ,
const struct V_53 * V_54 , T_11 V_55 ,
T_10 V_51 )
{
V_16 -> V_10 = NULL ;
V_16 -> V_52 = V_52 ;
V_16 -> V_56 = V_54 -> V_56 ;
V_16 -> V_49 = V_54 -> V_57 ;
V_16 -> V_51 = V_51 + V_54 -> V_57 ;
V_16 -> V_58 = V_54 -> V_59 ;
V_16 -> V_60 = V_55 ;
V_16 -> V_61 = 0 ;
F_27 ( V_54 -> V_62 <= V_63 ) ;
V_16 -> V_64 = ( V_65 ) V_54 -> V_62 ;
V_16 -> V_66 = V_54 -> V_66 ;
V_16 -> V_67 . V_68 = 0 ;
V_16 -> V_67 . V_69 = 0 ;
V_16 -> V_67 . V_70 = V_71 ;
V_16 -> V_67 . V_72 = 0 ;
V_16 -> V_67 . V_73 = 0 ;
V_16 -> V_67 . V_74 = 0 ;
V_16 -> V_67 . V_75 = 0 ;
V_16 -> V_67 . V_76 = ( V_54 -> V_77 & V_78 ) ? 1 : 0 ;
V_16 -> V_67 . V_79 = ( V_54 -> V_77 & V_80 ) ? 1 : 0 ;
V_16 -> V_67 . V_81 = ( V_54 -> V_77 & V_82 ) ? 1 : 0 ;
V_16 -> V_83 = NULL ;
V_16 -> V_19 . V_84 = V_54 -> V_85 . V_84 ;
V_16 -> V_19 . V_86 = V_54 -> V_85 . V_86 ;
V_16 -> V_87 . V_84 = 0 ;
V_16 -> V_87 . V_86 = 0 ;
V_16 -> V_37 . V_84 = 0 ;
V_16 -> V_37 . V_86 = 0 ;
V_16 -> V_27 = NULL ;
V_16 -> V_24 = NULL ;
V_16 -> V_88 = V_54 -> V_88 ;
}
void
F_28 ( T_4 * V_16 ,
T_9 * V_89 ,
T_9 * V_90 ,
const T_4 * V_27 ,
const T_4 * V_24 )
{
if ( F_29 ( V_90 ) )
* V_90 = V_16 -> V_19 ;
if( V_16 -> V_67 . V_74 )
* V_90 = V_16 -> V_19 ;
F_15 ( & V_16 -> V_37 , & V_16 -> V_19 , V_90 ) ;
if ( ( V_91 ) V_89 -> V_84 < V_16 -> V_37 . V_84
|| ( ( V_91 ) V_89 -> V_84 == V_16 -> V_37 . V_84 && ( V_91 ) V_89 -> V_86 < V_16 -> V_37 . V_86 ) ) {
* V_89 = V_16 -> V_37 ;
}
V_16 -> V_27 = V_27 ;
V_16 -> V_24 = V_24 ;
}
void
F_30 ( T_4 * V_16 ,
T_10 * V_51 )
{
if( V_16 -> V_67 . V_74 ) {
* V_51 = V_16 -> V_49 ;
V_16 -> V_51 = * V_51 ;
} else {
* V_51 += V_16 -> V_49 ;
V_16 -> V_51 = * V_51 ;
}
}
void
F_31 ( T_4 * V_16 )
{
V_16 -> V_67 . V_72 = 0 ;
if ( V_16 -> V_10 ) {
F_32 ( V_16 -> V_10 ) ;
V_16 -> V_10 = NULL ;
}
}
void
F_33 ( T_4 * V_16 )
{
if ( V_16 -> V_10 ) {
F_32 ( V_16 -> V_10 ) ;
V_16 -> V_10 = NULL ;
}
if ( V_16 -> V_88 ) {
F_34 ( V_16 -> V_88 ) ;
V_16 -> V_88 = NULL ;
}
}
