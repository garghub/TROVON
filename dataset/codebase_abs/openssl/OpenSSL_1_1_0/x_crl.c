static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_3 * V_5 = ( T_3 * ) * V_2 ;
if ( ! V_5 || ! V_5 -> V_6 )
return 1 ;
switch ( V_1 ) {
case V_7 :
( void ) F_2 ( V_5 -> V_6 , V_8 ) ;
break;
}
return 1 ;
}
int F_3 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_4 * V_9 = ( T_4 * ) * V_2 ;
F_4 ( V_10 ) * V_11 ;
V_10 * V_12 ;
int V_13 ;
switch ( V_1 ) {
case V_14 :
V_9 -> V_15 = NULL ;
V_9 -> V_16 = NULL ;
V_9 -> V_17 = 0 ;
V_9 -> V_18 = 0 ;
V_9 -> V_19 = V_20 ;
V_9 -> V_21 = V_22 ;
V_9 -> V_23 = NULL ;
V_9 -> V_24 = NULL ;
V_9 -> V_25 = NULL ;
V_9 -> V_26 = NULL ;
break;
case V_7 :
F_5 ( V_9 , F_6 () , V_9 -> V_27 , NULL ) ;
V_9 -> V_15 = F_7 ( V_9 ,
V_28 , NULL ,
NULL ) ;
if ( V_9 -> V_15 )
F_8 ( V_9 , V_9 -> V_15 ) ;
V_9 -> V_16 = F_7 ( V_9 ,
V_29 , NULL ,
NULL ) ;
V_9 -> V_25 = F_7 ( V_9 ,
V_30 , NULL , NULL ) ;
V_9 -> V_26 = F_7 ( V_9 ,
V_31 , NULL ,
NULL ) ;
if ( V_9 -> V_26 && ! V_9 -> V_25 )
V_9 -> V_17 |= V_32 ;
V_11 = V_9 -> V_9 . V_33 ;
for ( V_13 = 0 ; V_13 < F_9 ( V_11 ) ; V_13 ++ ) {
int V_34 ;
V_12 = F_10 ( V_11 , V_13 ) ;
V_34 = F_11 ( F_12 ( V_12 ) ) ;
if ( V_34 == V_35 )
V_9 -> V_17 |= V_36 ;
if ( F_13 ( V_12 ) ) {
if ( ( V_34 == V_28 )
|| ( V_34 == V_29 )
|| ( V_34 == V_31 ) )
break; ;
V_9 -> V_17 |= V_37 ;
break;
}
}
if ( ! F_14 ( V_9 ) )
return 0 ;
if ( V_9 -> V_21 -> V_38 ) {
if ( V_9 -> V_21 -> V_38 ( V_9 ) == 0 )
return 0 ;
}
break;
case V_39 :
if ( V_9 -> V_21 -> V_40 ) {
if ( ! V_9 -> V_21 -> V_40 ( V_9 ) )
return 0 ;
}
F_15 ( V_9 -> V_16 ) ;
F_16 ( V_9 -> V_15 ) ;
F_17 ( V_9 -> V_25 ) ;
F_17 ( V_9 -> V_26 ) ;
F_18 ( V_9 -> V_24 , V_41 ) ;
break;
}
return 1 ;
}
static void F_8 ( T_4 * V_9 , T_5 * V_15 )
{
int V_42 = 0 ;
V_9 -> V_18 |= V_43 ;
if ( V_15 -> V_44 > 0 ) {
V_42 ++ ;
V_9 -> V_18 |= V_45 ;
}
if ( V_15 -> V_46 > 0 ) {
V_42 ++ ;
V_9 -> V_18 |= V_47 ;
}
if ( V_15 -> V_48 > 0 ) {
V_42 ++ ;
V_9 -> V_18 |= V_49 ;
}
if ( V_42 > 1 )
V_9 -> V_18 |= V_50 ;
if ( V_15 -> V_51 > 0 )
V_9 -> V_18 |= V_52 ;
if ( V_15 -> V_53 ) {
V_9 -> V_18 |= V_54 ;
if ( V_15 -> V_53 -> V_55 > 0 )
V_9 -> V_19 = V_15 -> V_53 -> V_56 [ 0 ] ;
if ( V_15 -> V_53 -> V_55 > 1 )
V_9 -> V_19 |= ( V_15 -> V_53 -> V_56 [ 1 ] << 8 ) ;
V_9 -> V_19 &= V_20 ;
}
F_19 ( V_15 -> V_57 , F_20 ( V_9 ) ) ;
}
int F_21 ( T_4 * V_9 , T_6 * V_58 )
{
T_3 * V_59 ;
V_59 = & V_9 -> V_9 ;
if ( V_59 -> V_6 == NULL )
V_59 -> V_6 = F_22 ( V_8 ) ;
if ( V_59 -> V_6 == NULL || ! F_23 ( V_59 -> V_6 , V_58 ) ) {
F_24 ( V_60 , V_61 ) ;
return 0 ;
}
V_59 -> V_62 . V_63 = 1 ;
return 1 ;
}
int F_25 ( T_4 * V_9 , T_7 * V_64 )
{
if ( V_9 -> V_21 -> V_65 )
return V_9 -> V_21 -> V_65 ( V_9 , V_64 ) ;
return 0 ;
}
int F_26 ( T_4 * V_9 ,
T_6 * * V_66 , T_8 * V_67 )
{
if ( V_9 -> V_21 -> V_68 )
return V_9 -> V_21 -> V_68 ( V_9 , V_66 , V_67 , NULL ) ;
return 0 ;
}
int F_27 ( T_4 * V_9 , T_6 * * V_66 , T_9 * V_69 )
{
if ( V_9 -> V_21 -> V_68 )
return V_9 -> V_21 -> V_68 ( V_9 , V_66 ,
F_28 ( V_69 ) ,
F_29 ( V_69 ) ) ;
return 0 ;
}
static int F_30 ( T_4 * V_9 , T_7 * V_64 )
{
return ( F_31 ( F_32 ( T_3 ) ,
& V_9 -> V_70 , & V_9 -> V_71 , & V_9 -> V_9 , V_64 ) ) ;
}
static int F_33 ( T_4 * V_9 , T_10 * V_72 ,
T_6 * V_58 )
{
int V_73 ;
if ( ! V_58 -> V_74 ) {
if ( ! V_72 )
return 1 ;
if ( ! F_34 ( V_72 , F_20 ( V_9 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_72 )
V_72 = F_20 ( V_9 ) ;
for ( V_73 = 0 ; V_73 < F_35 ( V_58 -> V_74 ) ; V_73 ++ ) {
T_11 * V_75 = F_36 ( V_58 -> V_74 , V_73 ) ;
if ( V_75 -> type != V_76 )
continue;
if ( ! F_34 ( V_72 , V_75 -> V_77 . V_78 ) )
return 1 ;
}
return 0 ;
}
static int F_37 ( T_4 * V_9 ,
T_6 * * V_66 , T_8 * V_67 ,
T_10 * V_74 )
{
T_6 V_79 , * V_58 ;
int V_13 ;
V_79 . V_80 = * V_67 ;
if ( ! F_38 ( V_9 -> V_9 . V_6 ) ) {
F_39 ( V_9 -> V_81 ) ;
F_40 ( V_9 -> V_9 . V_6 ) ;
F_41 ( V_9 -> V_81 ) ;
}
V_13 = F_42 ( V_9 -> V_9 . V_6 , & V_79 ) ;
if ( V_13 < 0 )
return 0 ;
for (; V_13 < F_43 ( V_9 -> V_9 . V_6 ) ; V_13 ++ ) {
V_58 = F_44 ( V_9 -> V_9 . V_6 , V_13 ) ;
if ( F_45 ( & V_58 -> V_80 , V_67 ) )
return 0 ;
if ( F_33 ( V_9 , V_74 , V_58 ) ) {
if ( V_66 )
* V_66 = V_58 ;
if ( V_58 -> V_82 == V_83 )
return 2 ;
return 1 ;
}
}
return 0 ;
}
void F_46 ( const T_12 * V_21 )
{
if ( V_21 == NULL )
V_22 = & V_84 ;
else
V_22 = V_21 ;
}
T_12 * F_47 ( int (* V_38) ( T_4 * V_9 ) ,
int (* V_40) ( T_4 * V_9 ) ,
int (* V_68) ( T_4 * V_9 ,
T_6 * * V_66 ,
T_8 * V_85 ,
T_10 * V_74 ) ,
int (* V_65) ( T_4 * V_9 ,
T_7 * V_86 ) )
{
T_12 * V_87 ;
V_87 = F_48 ( sizeof( * V_87 ) ) ;
if ( V_87 == NULL )
return NULL ;
V_87 -> V_38 = V_38 ;
V_87 -> V_40 = V_40 ;
V_87 -> V_68 = V_68 ;
V_87 -> V_65 = V_65 ;
V_87 -> V_17 = V_88 ;
return V_87 ;
}
void F_49 ( T_12 * V_87 )
{
if ( ! ( V_87 -> V_17 & V_88 ) )
return;
F_50 ( V_87 ) ;
}
void F_51 ( T_4 * V_9 , void * V_89 )
{
V_9 -> V_23 = V_89 ;
}
void * F_52 ( T_4 * V_9 )
{
return V_9 -> V_23 ;
}
