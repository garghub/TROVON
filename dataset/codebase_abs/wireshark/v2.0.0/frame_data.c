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
T_4 * V_13 ;
if ( V_7 == V_9 -> V_14 ) {
V_13 = V_7 ;
V_12 = & V_9 -> V_10 ;
} else {
V_13 = F_3 () ;
V_12 = & V_9 -> V_15 -> V_16 ;
}
V_11 = ( T_3 * ) F_4 ( V_13 , sizeof( T_3 ) ) ;
V_11 -> V_5 = V_5 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_10 = V_10 ;
* V_12 = F_5 ( * V_12 ,
( V_17 * ) V_11 ) ;
}
void *
F_6 ( T_4 * V_13 , struct V_8 * V_9 , int V_5 , T_5 V_6 )
{
T_3 V_18 , * V_11 ;
T_6 * V_19 ;
V_18 . V_5 = V_5 ;
V_18 . V_6 = V_6 ;
V_18 . V_10 = NULL ;
if ( V_13 == V_9 -> V_14 ) {
V_19 = F_7 ( V_9 -> V_10 , ( V_17 * ) & V_18 , F_1 ) ;
} else {
V_19 = F_7 ( V_9 -> V_15 -> V_16 , ( V_17 * ) & V_18 , F_1 ) ;
}
if ( V_19 ) {
V_11 = ( T_3 * ) V_19 -> V_20 ;
return V_11 -> V_10 ;
}
return NULL ;
}
void
F_8 ( T_4 * V_13 , struct V_8 * V_9 , int V_5 , T_5 V_6 )
{
T_3 V_18 ;
T_6 * V_19 ;
T_6 * * V_12 ;
V_18 . V_5 = V_5 ;
V_18 . V_6 = V_6 ;
V_18 . V_10 = NULL ;
if ( V_13 == V_9 -> V_14 ) {
V_19 = F_7 ( V_9 -> V_15 -> V_16 , ( V_17 * ) & V_18 , F_1 ) ;
V_12 = & V_9 -> V_10 ;
} else {
V_19 = F_7 ( V_9 -> V_15 -> V_16 , ( V_17 * ) & V_18 , F_1 ) ;
V_12 = & V_9 -> V_15 -> V_16 ;
}
if ( V_19 ) {
* V_12 = F_9 ( * V_12 , V_19 -> V_20 ) ;
}
}
T_7 *
F_10 ( T_4 * V_13 , struct V_8 * V_9 , T_8 V_21 ) {
T_3 * V_18 ;
if ( V_13 == V_9 -> V_14 ) {
V_18 = ( T_3 * ) F_11 ( V_9 -> V_10 , V_21 ) ;
} else {
V_18 = ( T_3 * ) F_11 ( V_9 -> V_15 -> V_16 , V_21 ) ;
}
return F_12 ( F_13 () , L_1 , F_14 ( V_18 -> V_5 ) , V_18 -> V_6 ) ;
}
void
F_15 ( const struct V_22 * V_23 , const T_9 * V_24 , T_5 V_25 , T_10 * V_26 )
{
const T_10 * V_27 = ( V_25 ) ? F_16 ( V_23 , V_25 ) : NULL ;
if ( V_27 ) {
F_17 ( V_26 , & V_24 -> V_28 , V_27 ) ;
} else {
F_18 ( V_26 ) ;
}
}
static T_1
F_19 ( const struct V_22 * V_23 , const T_9 * V_29 , const T_9 * V_30 )
{
T_10 V_31 , V_32 ;
F_15 ( V_23 , V_29 , V_29 -> V_33 - 1 , & V_31 ) ;
F_15 ( V_23 , V_30 , V_30 -> V_33 - 1 , & V_32 ) ;
return F_20 ( V_31 , V_32 ) ;
}
static T_1
F_21 ( const struct V_22 * V_23 , const T_9 * V_29 , const T_9 * V_30 )
{
T_10 V_34 , V_35 ;
F_15 ( V_23 , V_29 , V_29 -> V_36 , & V_34 ) ;
F_15 ( V_23 , V_30 , V_30 -> V_36 , & V_35 ) ;
return F_20 ( V_34 , V_35 ) ;
}
static T_1
F_22 ( const struct V_22 * V_23 , const T_9 * V_29 , const T_9 * V_30 )
{
T_10 V_37 , V_38 ;
F_15 ( V_23 , V_29 , V_29 -> V_39 , & V_37 ) ;
F_15 ( V_23 , V_30 , V_30 -> V_39 , & V_38 ) ;
return F_20 ( V_37 , V_38 ) ;
}
T_1
F_23 ( const struct V_22 * V_23 , const T_9 * V_29 , const T_9 * V_30 , int V_40 )
{
switch ( V_40 ) {
case V_41 :
return F_24 () ;
case V_42 :
switch ( F_25 () ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return F_26 ( V_28 ) ;
case V_50 :
return F_21 ( V_23 , V_29 , V_30 ) ;
case V_51 :
return F_19 ( V_23 , V_29 , V_30 ) ;
case V_52 :
return F_22 ( V_23 , V_29 , V_30 ) ;
case V_53 :
return 0 ;
}
return 0 ;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return F_26 ( V_28 ) ;
case V_60 :
return F_21 ( V_23 , V_29 , V_30 ) ;
case V_61 :
return F_19 ( V_23 , V_29 , V_30 ) ;
case V_62 :
return F_22 ( V_23 , V_29 , V_30 ) ;
case V_63 :
return F_27 ( V_64 ) ;
case V_65 :
return F_27 ( V_66 ) ;
}
F_28 ( 0 ) ;
}
void
F_29 ( T_9 * V_24 , T_5 V_33 ,
const struct V_67 * V_68 , T_11 V_69 ,
T_5 V_66 )
{
V_24 -> V_16 = NULL ;
V_24 -> V_33 = V_33 ;
V_24 -> V_64 = V_68 -> V_70 ;
V_24 -> V_66 = V_66 + V_68 -> V_70 ;
V_24 -> V_71 = V_68 -> V_72 ;
V_24 -> V_73 = V_69 ;
V_24 -> V_74 = 0 ;
F_30 ( V_68 -> V_75 <= V_76 ) ;
V_24 -> V_77 = ( V_78 ) V_68 -> V_75 ;
V_24 -> V_79 . V_80 = 0 ;
V_24 -> V_79 . V_81 = 0 ;
V_24 -> V_79 . V_82 = V_83 ;
V_24 -> V_79 . V_84 = 0 ;
V_24 -> V_79 . V_85 = 0 ;
V_24 -> V_79 . V_86 = 0 ;
V_24 -> V_79 . V_87 = 0 ;
V_24 -> V_79 . V_88 = ( V_68 -> V_89 & V_90 ) ? 1 : 0 ;
V_24 -> V_79 . V_91 = ( V_68 -> V_92 != NULL ) ;
V_24 -> V_79 . V_93 = 0 ;
V_24 -> V_94 = ( V_78 ) V_68 -> V_95 ;
V_24 -> V_96 = NULL ;
V_24 -> V_28 . V_97 = V_68 -> V_98 . V_97 ;
V_24 -> V_28 . V_99 = V_68 -> V_98 . V_99 ;
V_24 -> V_100 . V_97 = 0 ;
V_24 -> V_100 . V_99 = 0 ;
V_24 -> V_36 = 0 ;
V_24 -> V_39 = 0 ;
}
void
F_31 ( T_9 * V_24 ,
T_10 * V_101 ,
const T_9 * * V_102 ,
const T_9 * V_103 )
{
T_10 V_104 ;
if ( * V_102 == NULL )
* V_102 = V_24 ;
if( V_24 -> V_79 . V_86 )
* V_102 = V_24 ;
F_17 ( & V_104 , & V_24 -> V_28 , & ( * V_102 ) -> V_28 ) ;
if ( ( V_105 ) V_101 -> V_97 < V_104 . V_97
|| ( ( V_105 ) V_101 -> V_97 == V_104 . V_97 && ( V_105 ) V_101 -> V_99 < V_104 . V_99 ) ) {
* V_101 = V_104 ;
}
V_24 -> V_36 = ( * V_102 != V_24 ) ? ( * V_102 ) -> V_33 : 0 ;
V_24 -> V_39 = ( V_103 ) ? V_103 -> V_33 : 0 ;
}
void
F_32 ( T_9 * V_24 ,
T_5 * V_66 )
{
if( V_24 -> V_79 . V_86 ) {
* V_66 = V_24 -> V_64 ;
V_24 -> V_66 = * V_66 ;
} else {
* V_66 += V_24 -> V_64 ;
V_24 -> V_66 = * V_66 ;
}
}
void
F_33 ( T_9 * V_24 )
{
V_24 -> V_79 . V_84 = 0 ;
V_24 -> V_74 = 0 ;
if ( V_24 -> V_16 ) {
F_34 ( V_24 -> V_16 ) ;
V_24 -> V_16 = NULL ;
}
}
void
F_35 ( T_9 * V_24 )
{
if ( V_24 -> V_16 ) {
F_34 ( V_24 -> V_16 ) ;
V_24 -> V_16 = NULL ;
}
}
