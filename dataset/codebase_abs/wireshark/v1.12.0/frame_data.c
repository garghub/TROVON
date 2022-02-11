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
F_2 ( T_4 * V_7 , struct V_8 * V_9 , int V_5 , T_5 V_6 , void * V_10 )
{
T_3 * V_11 ;
T_6 * * V_12 ;
if ( V_7 == V_9 -> V_13 ) {
V_11 = ( T_3 * ) F_3 ( V_7 , sizeof( T_3 ) ) ;
V_12 = & V_9 -> V_10 ;
} else {
V_11 = ( T_3 * ) F_3 ( F_4 () , sizeof( T_3 ) ) ;
V_12 = & V_9 -> V_14 -> V_15 ;
}
V_11 -> V_5 = V_5 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_10 = V_10 ;
* V_12 = F_5 ( * V_12 ,
( V_16 * ) V_11 ,
F_1 ) ;
}
void *
F_6 ( T_4 * V_7 , struct V_8 * V_9 , int V_5 , T_5 V_6 )
{
T_3 V_17 , * V_11 ;
T_6 * V_18 ;
V_17 . V_5 = V_5 ;
V_17 . V_6 = V_6 ;
V_17 . V_10 = NULL ;
if ( V_7 == V_9 -> V_13 ) {
V_18 = F_7 ( V_9 -> V_10 , ( V_16 * ) & V_17 , F_1 ) ;
} else {
V_18 = F_7 ( V_9 -> V_14 -> V_15 , ( V_16 * ) & V_17 , F_1 ) ;
}
if ( V_18 ) {
V_11 = ( T_3 * ) V_18 -> V_19 ;
return V_11 -> V_10 ;
}
return NULL ;
}
void
F_8 ( T_4 * V_7 , struct V_8 * V_9 , int V_5 , T_5 V_6 )
{
T_3 V_17 ;
T_6 * V_18 ;
T_6 * * V_12 ;
V_17 . V_5 = V_5 ;
V_17 . V_6 = V_6 ;
V_17 . V_10 = NULL ;
if ( V_7 == V_9 -> V_13 ) {
V_18 = F_7 ( V_9 -> V_14 -> V_15 , ( V_16 * ) & V_17 , F_1 ) ;
V_12 = & V_9 -> V_10 ;
} else {
V_18 = F_7 ( V_9 -> V_14 -> V_15 , ( V_16 * ) & V_17 , F_1 ) ;
V_12 = & V_9 -> V_14 -> V_15 ;
}
if ( V_18 ) {
* V_12 = F_9 ( * V_12 , V_18 -> V_19 ) ;
}
}
T_7 *
F_10 ( T_4 * V_7 , struct V_8 * V_9 , T_8 V_20 ) {
T_3 * V_17 ;
if ( V_7 == V_9 -> V_13 ) {
V_17 = ( T_3 * ) F_11 ( V_9 -> V_10 , V_20 ) ;
} else {
V_17 = ( T_3 * ) F_11 ( V_9 -> V_14 -> V_15 , V_20 ) ;
}
return F_12 ( L_1 , F_13 ( V_17 -> V_5 ) , V_17 -> V_6 ) ;
}
void
F_14 ( const struct V_21 * V_22 , const T_9 * V_23 , T_5 V_24 , T_10 * V_25 )
{
const T_10 * V_26 = ( V_24 ) ? F_15 ( V_22 , V_24 ) : NULL ;
if ( V_26 ) {
F_16 ( V_25 , & V_23 -> V_27 , V_26 ) ;
} else {
F_17 ( V_25 ) ;
}
}
static T_1
F_18 ( const struct V_21 * V_22 , const T_9 * V_28 , const T_9 * V_29 )
{
T_10 V_30 , V_31 ;
F_14 ( V_22 , V_28 , V_28 -> V_32 - 1 , & V_30 ) ;
F_14 ( V_22 , V_29 , V_29 -> V_32 - 1 , & V_31 ) ;
return F_19 ( V_30 , V_31 ) ;
}
static T_1
F_20 ( const struct V_21 * V_22 , const T_9 * V_28 , const T_9 * V_29 )
{
T_10 V_33 , V_34 ;
F_14 ( V_22 , V_28 , V_28 -> V_35 , & V_33 ) ;
F_14 ( V_22 , V_29 , V_29 -> V_35 , & V_34 ) ;
return F_19 ( V_33 , V_34 ) ;
}
static T_1
F_21 ( const struct V_21 * V_22 , const T_9 * V_28 , const T_9 * V_29 )
{
T_10 V_36 , V_37 ;
F_14 ( V_22 , V_28 , V_28 -> V_38 , & V_36 ) ;
F_14 ( V_22 , V_29 , V_29 -> V_38 , & V_37 ) ;
return F_19 ( V_36 , V_37 ) ;
}
T_1
F_22 ( const struct V_21 * V_22 , const T_9 * V_28 , const T_9 * V_29 , int V_39 )
{
switch ( V_39 ) {
case V_40 :
return F_23 () ;
case V_41 :
switch ( F_24 () ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
return F_25 ( V_27 ) ;
case V_49 :
return F_20 ( V_22 , V_28 , V_29 ) ;
case V_50 :
return F_18 ( V_22 , V_28 , V_29 ) ;
case V_51 :
return F_21 ( V_22 , V_28 , V_29 ) ;
case V_52 :
return 0 ;
}
return 0 ;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return F_25 ( V_27 ) ;
case V_59 :
return F_20 ( V_22 , V_28 , V_29 ) ;
case V_60 :
return F_18 ( V_22 , V_28 , V_29 ) ;
case V_61 :
return F_21 ( V_22 , V_28 , V_29 ) ;
case V_62 :
return F_26 ( V_63 ) ;
case V_64 :
return F_26 ( V_65 ) ;
}
F_27 ( 0 ) ;
}
void
F_28 ( T_9 * V_23 , T_5 V_32 ,
const struct V_66 * V_67 , T_11 V_68 ,
T_5 V_65 )
{
V_23 -> V_15 = NULL ;
V_23 -> V_32 = V_32 ;
V_23 -> V_63 = V_67 -> V_69 ;
V_23 -> V_65 = V_65 + V_67 -> V_69 ;
V_23 -> V_70 = V_67 -> V_71 ;
V_23 -> V_72 = V_68 ;
V_23 -> V_73 = 0 ;
F_29 ( V_67 -> V_74 <= V_75 ) ;
V_23 -> V_76 = ( V_77 ) V_67 -> V_74 ;
V_23 -> V_78 . V_79 = 0 ;
V_23 -> V_78 . V_80 = 0 ;
V_23 -> V_78 . V_81 = V_82 ;
V_23 -> V_78 . V_83 = 0 ;
V_23 -> V_78 . V_84 = 0 ;
V_23 -> V_78 . V_85 = 0 ;
V_23 -> V_78 . V_86 = 0 ;
V_23 -> V_78 . V_87 = ( V_67 -> V_88 & V_89 ) ? 1 : 0 ;
V_23 -> V_78 . V_90 = ( V_67 -> V_91 != NULL ) ;
V_23 -> V_78 . V_92 = 0 ;
V_23 -> V_93 = NULL ;
V_23 -> V_27 . V_94 = V_67 -> V_95 . V_94 ;
V_23 -> V_27 . V_96 = V_67 -> V_95 . V_96 ;
V_23 -> V_97 . V_94 = 0 ;
V_23 -> V_97 . V_96 = 0 ;
V_23 -> V_35 = 0 ;
V_23 -> V_38 = 0 ;
}
void
F_30 ( T_9 * V_23 ,
T_10 * V_98 ,
const T_9 * * V_99 ,
const T_9 * V_100 )
{
T_10 V_101 ;
if ( * V_99 == NULL )
* V_99 = V_23 ;
if( V_23 -> V_78 . V_85 )
* V_99 = V_23 ;
F_16 ( & V_101 , & V_23 -> V_27 , & ( * V_99 ) -> V_27 ) ;
if ( ( V_102 ) V_98 -> V_94 < V_101 . V_94
|| ( ( V_102 ) V_98 -> V_94 == V_101 . V_94 && ( V_102 ) V_98 -> V_96 < V_101 . V_96 ) ) {
* V_98 = V_101 ;
}
V_23 -> V_35 = ( * V_99 != V_23 ) ? ( * V_99 ) -> V_32 : 0 ;
V_23 -> V_38 = ( V_100 ) ? V_100 -> V_32 : 0 ;
}
void
F_31 ( T_9 * V_23 ,
T_5 * V_65 )
{
if( V_23 -> V_78 . V_85 ) {
* V_65 = V_23 -> V_63 ;
V_23 -> V_65 = * V_65 ;
} else {
* V_65 += V_23 -> V_63 ;
V_23 -> V_65 = * V_65 ;
}
}
void
F_32 ( T_9 * V_23 )
{
V_23 -> V_78 . V_83 = 0 ;
if ( V_23 -> V_15 ) {
F_33 ( V_23 -> V_15 ) ;
V_23 -> V_15 = NULL ;
}
}
void
F_34 ( T_9 * V_23 )
{
if ( V_23 -> V_15 ) {
F_33 ( V_23 -> V_15 ) ;
V_23 -> V_15 = NULL ;
}
}
