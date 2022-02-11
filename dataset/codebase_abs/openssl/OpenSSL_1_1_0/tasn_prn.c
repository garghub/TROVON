T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
return NULL ;
}
return V_1 ;
}
void F_4 ( T_1 * V_4 )
{
F_5 ( V_4 ) ;
}
unsigned long F_6 ( const T_1 * V_4 )
{
return V_4 -> V_5 ;
}
void F_7 ( T_1 * V_4 , unsigned long V_5 )
{
V_4 -> V_5 = V_5 ;
}
unsigned long F_8 ( const T_1 * V_4 )
{
return V_4 -> V_6 ;
}
void F_9 ( T_1 * V_4 , unsigned long V_5 )
{
V_4 -> V_6 = V_5 ;
}
unsigned long F_10 ( const T_1 * V_4 )
{
return V_4 -> V_7 ;
}
void F_11 ( T_1 * V_4 , unsigned long V_5 )
{
V_4 -> V_7 = V_5 ;
}
unsigned long F_12 ( const T_1 * V_4 )
{
return V_4 -> V_8 ;
}
void F_13 ( T_1 * V_4 , unsigned long V_5 )
{
V_4 -> V_8 = V_5 ;
}
unsigned long F_14 ( const T_1 * V_4 )
{
return V_4 -> V_9 ;
}
void F_15 ( T_1 * V_4 , unsigned long V_5 )
{
V_4 -> V_9 = V_5 ;
}
int F_16 ( T_2 * V_10 , T_3 * V_11 , int V_12 ,
const T_4 * V_13 , const T_1 * V_14 )
{
const char * V_15 ;
if ( V_14 == NULL )
V_14 = & V_16 ;
if ( V_14 -> V_5 & V_17 )
V_15 = NULL ;
else
V_15 = V_13 -> V_15 ;
return F_17 ( V_10 , & V_11 , V_12 , V_13 , NULL , V_15 , 0 , V_14 ) ;
}
static int F_17 ( T_2 * V_10 , T_3 * * V_18 , int V_12 ,
const T_4 * V_13 ,
const char * V_19 , const char * V_15 ,
int V_20 , const T_1 * V_14 )
{
const T_5 * V_21 ;
const T_6 * V_22 ;
T_3 * * V_23 ;
const T_7 * V_24 = V_13 -> V_25 ;
T_8 * V_26 ;
T_9 V_27 ;
int V_28 ;
if ( V_24 && V_24 -> V_26 ) {
V_27 . V_10 = V_10 ;
V_27 . V_12 = V_12 ;
V_27 . V_14 = V_14 ;
V_26 = V_24 -> V_26 ;
} else
V_26 = 0 ;
if ( ( ( V_13 -> V_29 != V_30 )
|| ( V_13 -> V_31 != V_32 ) ) && * V_18 == NULL ) {
if ( V_14 -> V_5 & V_33 ) {
if ( ! V_20 && ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
if ( F_19 ( V_10 , L_1 ) <= 0 )
return 0 ;
}
return 1 ;
}
switch ( V_13 -> V_29 ) {
case V_30 :
if ( V_13 -> V_34 ) {
if ( ! F_20 ( V_10 , V_18 , V_12 ,
V_13 -> V_34 , V_14 ) )
return 0 ;
break;
}
case V_35 :
if ( ! F_21 ( V_10 , V_18 , V_13 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
break;
case V_36 :
if ( ! V_20 && ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
V_22 = V_13 -> V_25 ;
if ( V_22 && V_22 -> V_37 ) {
V_28 = V_22 -> V_37 ( V_10 , V_18 , V_12 , L_2 , V_14 ) ;
if ( ! V_28 )
return 0 ;
if ( ( V_28 == 2 ) && ( F_19 ( V_10 , L_3 ) <= 0 ) )
return 0 ;
return 1 ;
} else if ( V_15 &&
F_22 ( V_10 , L_4 , V_15 ) <= 0 )
return 0 ;
break;
case V_38 :
V_28 = F_23 ( V_18 , V_13 ) ;
if ( ( V_28 < 0 ) || ( V_28 >= V_13 -> V_39 ) ) {
if ( F_22 ( V_10 , L_5 , V_28 ) <= 0 )
return 0 ;
return 1 ;
}
V_21 = V_13 -> V_34 + V_28 ;
V_23 = F_24 ( V_18 , V_21 ) ;
if ( ! F_20 ( V_10 , V_23 , V_12 , V_21 , V_14 ) )
return 0 ;
break;
case V_40 :
case V_41 :
if ( ! V_20 && ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
if ( V_19 || V_15 ) {
if ( V_14 -> V_5 & V_42 ) {
if ( F_19 ( V_10 , L_6 ) <= 0 )
return 0 ;
} else {
if ( F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
}
}
if ( V_26 ) {
V_28 = V_26 ( V_43 , V_18 , V_13 , & V_27 ) ;
if ( V_28 == 0 )
return 0 ;
if ( V_28 == 2 )
return 1 ;
}
for ( V_28 = 0 , V_21 = V_13 -> V_34 ; V_28 < V_13 -> V_39 ; V_28 ++ , V_21 ++ ) {
const T_5 * V_44 ;
V_44 = F_25 ( V_18 , V_21 , 1 ) ;
if ( ! V_44 )
return 0 ;
V_23 = F_24 ( V_18 , V_44 ) ;
if ( ! F_20 ( V_10 , V_23 ,
V_12 + 2 , V_44 , V_14 ) )
return 0 ;
}
if ( V_14 -> V_5 & V_42 ) {
if ( F_22 ( V_10 , L_7 , V_12 , L_2 ) < 0 )
return 0 ;
}
if ( V_26 ) {
V_28 = V_26 ( V_45 , V_18 , V_13 , & V_27 ) ;
if ( V_28 == 0 )
return 0 ;
}
break;
default:
F_22 ( V_10 , L_8 , V_13 -> V_29 ) ;
return 0 ;
}
return 1 ;
}
static int F_20 ( T_2 * V_10 , T_3 * * V_18 , int V_12 ,
const T_5 * V_21 , const T_1 * V_14 )
{
int V_28 , V_5 ;
const char * V_15 , * V_19 ;
T_3 * V_46 ;
V_5 = V_21 -> V_5 ;
if ( V_14 -> V_5 & V_47 )
V_15 = F_26 ( V_21 -> V_48 ) -> V_15 ;
else
V_15 = NULL ;
if ( V_14 -> V_5 & V_49 )
V_19 = NULL ;
else
V_19 = V_21 -> V_50 ;
if ( V_5 & V_51 ) {
V_46 = ( T_3 * ) V_18 ;
V_18 = & V_46 ;
}
if ( V_5 & V_52 ) {
char * V_53 ;
T_3 * V_54 ;
F_27 ( T_3 ) * V_55 ;
if ( V_19 ) {
if ( V_14 -> V_5 & V_56 ) {
if ( V_5 & V_57 )
V_53 = L_9 ;
else
V_53 = L_10 ;
if ( F_22 ( V_10 , L_11 ,
V_12 , L_2 , V_53 , V_21 -> V_50 ) <= 0 )
return 0 ;
} else if ( F_22 ( V_10 , L_12 , V_12 , L_2 , V_19 ) <= 0 )
return 0 ;
}
V_55 = ( F_27 ( T_3 ) * ) * V_18 ;
for ( V_28 = 0 ; V_28 < F_28 ( V_55 ) ; V_28 ++ ) {
if ( ( V_28 > 0 ) && ( F_19 ( V_10 , L_3 ) <= 0 ) )
return 0 ;
V_54 = F_29 ( V_55 , V_28 ) ;
if ( ! F_17 ( V_10 , & V_54 , V_12 + 2 ,
F_26 ( V_21 -> V_48 ) , NULL , NULL , 1 ,
V_14 ) )
return 0 ;
}
if ( ! V_28 && F_22 ( V_10 , L_13 , V_12 + 2 , L_2 ) <= 0 )
return 0 ;
if ( V_14 -> V_5 & V_42 ) {
if ( F_22 ( V_10 , L_7 , V_12 , L_2 ) <= 0 )
return 0 ;
}
return 1 ;
}
return F_17 ( V_10 , V_18 , V_12 , F_26 ( V_21 -> V_48 ) ,
V_19 , V_15 , 0 , V_14 ) ;
}
static int F_18 ( T_2 * V_10 , int V_12 ,
const char * V_19 , const char * V_15 ,
const T_1 * V_14 )
{
static const char V_58 [] = L_14 ;
static const int V_59 = sizeof( V_58 ) - 1 ;
while ( V_12 > V_59 ) {
if ( F_30 ( V_10 , V_58 , V_59 ) != V_59 )
return 0 ;
V_12 -= V_59 ;
}
if ( F_30 ( V_10 , V_58 , V_12 ) != V_12 )
return 0 ;
if ( V_14 -> V_5 & V_17 )
V_15 = NULL ;
if ( V_14 -> V_5 & V_49 )
V_19 = NULL ;
if ( ! V_15 && ! V_19 )
return 1 ;
if ( V_19 ) {
if ( F_19 ( V_10 , V_19 ) <= 0 )
return 0 ;
}
if ( V_15 ) {
if ( V_19 ) {
if ( F_22 ( V_10 , L_15 , V_15 ) <= 0 )
return 0 ;
} else {
if ( F_19 ( V_10 , V_15 ) <= 0 )
return 0 ;
}
}
if ( F_30 ( V_10 , L_16 , 2 ) != 2 )
return 0 ;
return 1 ;
}
static int F_31 ( T_2 * V_10 , int V_60 )
{
const char * V_61 ;
switch ( V_60 ) {
case - 1 :
V_61 = L_17 ;
break;
case 0 :
V_61 = L_18 ;
break;
default:
V_61 = L_19 ;
break;
}
if ( F_19 ( V_10 , V_61 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_32 ( T_2 * V_10 , const T_10 * V_61 )
{
char * V_62 ;
int V_1 = 1 ;
V_62 = F_33 ( NULL , V_61 ) ;
if ( V_62 == NULL )
return 0 ;
if ( F_19 ( V_10 , V_62 ) <= 0 )
V_1 = 0 ;
F_5 ( V_62 ) ;
return V_1 ;
}
static int F_34 ( T_2 * V_10 , const T_11 * V_63 )
{
char V_64 [ 80 ] ;
const char * V_65 ;
V_65 = F_35 ( F_36 ( V_63 ) ) ;
if ( ! V_65 )
V_65 = L_2 ;
F_37 ( V_64 , sizeof V_64 , V_63 , 1 ) ;
if ( F_22 ( V_10 , L_20 , V_65 , V_64 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_38 ( T_2 * V_10 , const T_12 * V_61 , int V_12 )
{
if ( V_61 -> type == V_66 ) {
if ( F_22 ( V_10 , L_21 , V_61 -> V_5 & 0x7 ) <= 0 )
return 0 ;
} else if ( F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
if ( ( V_61 -> V_67 > 0 )
&& F_39 ( V_10 , ( const char * ) V_61 -> V_68 , V_61 -> V_67 ,
V_12 + 2 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_21 ( T_2 * V_10 , T_3 * * V_18 ,
const T_4 * V_13 , int V_12 ,
const char * V_19 , const char * V_15 ,
const T_1 * V_14 )
{
long V_31 ;
T_12 * V_61 ;
int V_1 = 1 , V_69 = 1 ;
const char * V_70 ;
const T_13 * V_71 ;
V_71 = V_13 -> V_25 ;
if ( ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
if ( V_71 && V_71 -> V_72 )
return V_71 -> V_72 ( V_10 , V_18 , V_13 , V_12 , V_14 ) ;
if ( V_13 -> V_29 == V_35 ) {
V_61 = ( T_12 * ) * V_18 ;
V_31 = V_61 -> type & ~ V_73 ;
} else {
V_31 = V_13 -> V_31 ;
if ( V_31 == V_32 )
V_61 = NULL ;
else
V_61 = ( T_12 * ) * V_18 ;
}
if ( V_31 == V_74 ) {
T_14 * V_75 = ( T_14 * ) * V_18 ;
V_31 = V_75 -> type ;
V_18 = & V_75 -> V_76 . V_77 ;
V_61 = ( T_12 * ) * V_18 ;
if ( V_14 -> V_5 & V_78 )
V_70 = NULL ;
else
V_70 = F_40 ( V_31 ) ;
} else {
if ( V_14 -> V_5 & V_79 )
V_70 = F_40 ( V_31 ) ;
else
V_70 = NULL ;
}
if ( V_31 == V_80 ) {
if ( F_19 ( V_10 , L_22 ) <= 0 )
return 0 ;
return 1 ;
}
if ( V_70 ) {
if ( F_19 ( V_10 , V_70 ) <= 0 )
return 0 ;
if ( F_19 ( V_10 , L_23 ) <= 0 )
return 0 ;
}
switch ( V_31 ) {
case V_32 :
{
int V_60 = * ( int * ) V_18 ;
if ( V_60 == - 1 )
V_60 = V_13 -> V_81 ;
V_1 = F_31 ( V_10 , V_60 ) ;
}
break;
case V_82 :
case V_83 :
V_1 = F_32 ( V_10 , V_61 ) ;
break;
case V_84 :
V_1 = F_41 ( V_10 , V_61 ) ;
break;
case V_85 :
V_1 = F_42 ( V_10 , V_61 ) ;
break;
case V_86 :
V_1 = F_34 ( V_10 , ( const T_11 * ) * V_18 ) ;
break;
case V_87 :
case V_66 :
V_1 = F_38 ( V_10 , V_61 , V_12 ) ;
V_69 = 0 ;
break;
case V_88 :
case V_89 :
case V_90 :
if ( F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
if ( F_43 ( V_10 , V_61 -> V_68 , V_61 -> V_67 , V_12 , 0 ) <= 0 )
V_1 = 0 ;
V_69 = 0 ;
break;
default:
V_1 = F_44 ( V_10 , V_61 , V_14 -> V_9 ) ;
}
if ( ! V_1 )
return 0 ;
if ( V_69 && F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
return 1 ;
}
