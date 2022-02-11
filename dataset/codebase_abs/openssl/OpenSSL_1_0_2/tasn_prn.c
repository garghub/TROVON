T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
return NULL ;
}
V_1 -> V_4 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 = 0 ;
V_1 -> V_8 = 0 ;
return V_1 ;
}
void F_4 ( T_1 * V_9 )
{
F_5 ( V_9 ) ;
}
unsigned long F_6 ( T_1 * V_9 )
{
return V_9 -> V_4 ;
}
void F_7 ( T_1 * V_9 , unsigned long V_4 )
{
V_9 -> V_4 = V_4 ;
}
unsigned long F_8 ( T_1 * V_9 )
{
return V_9 -> V_5 ;
}
void F_9 ( T_1 * V_9 , unsigned long V_4 )
{
V_9 -> V_5 = V_4 ;
}
unsigned long F_10 ( T_1 * V_9 )
{
return V_9 -> V_6 ;
}
void F_11 ( T_1 * V_9 , unsigned long V_4 )
{
V_9 -> V_6 = V_4 ;
}
unsigned long F_12 ( T_1 * V_9 )
{
return V_9 -> V_7 ;
}
void F_13 ( T_1 * V_9 , unsigned long V_4 )
{
V_9 -> V_7 = V_4 ;
}
unsigned long F_14 ( T_1 * V_9 )
{
return V_9 -> V_8 ;
}
void F_15 ( T_1 * V_9 , unsigned long V_4 )
{
V_9 -> V_8 = V_4 ;
}
int F_16 ( T_2 * V_10 , T_3 * V_11 , int V_12 ,
const T_4 * V_13 , const T_1 * V_14 )
{
const char * V_15 ;
if ( V_14 == NULL )
V_14 = & V_16 ;
if ( V_14 -> V_4 & V_17 )
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
if ( * V_18 == NULL ) {
if ( V_14 -> V_4 & V_29 ) {
if ( ! V_20 && ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
if ( F_19 ( V_10 , L_1 ) <= 0 )
return 0 ;
}
return 1 ;
}
switch ( V_13 -> V_30 ) {
case V_31 :
if ( V_13 -> V_32 ) {
if ( ! F_20 ( V_10 , V_18 , V_12 ,
V_13 -> V_32 , V_14 ) )
return 0 ;
}
case V_33 :
if ( ! F_21 ( V_10 , V_18 , V_13 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
break;
case V_34 :
if ( ! V_20 && ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
V_22 = V_13 -> V_25 ;
if ( V_22 && V_22 -> V_35 ) {
V_28 = V_22 -> V_35 ( V_10 , V_18 , V_12 , L_2 , V_14 ) ;
if ( ! V_28 )
return 0 ;
if ( ( V_28 == 2 ) && ( F_19 ( V_10 , L_3 ) <= 0 ) )
return 0 ;
return 1 ;
} else if ( V_15 &&
F_22 ( V_10 , L_4 , V_15 ) <= 0 )
return 0 ;
break;
case V_36 :
#if 0
if (!nohdr && !asn1_print_fsname(out, indent, fname, sname, pctx))
return 0;
#endif
V_28 = F_23 ( V_18 , V_13 ) ;
if ( ( V_28 < 0 ) || ( V_28 >= V_13 -> V_37 ) ) {
if ( F_22 ( V_10 , L_5 , V_28 ) <= 0 )
return 0 ;
return 1 ;
}
V_21 = V_13 -> V_32 + V_28 ;
V_23 = F_24 ( V_18 , V_21 ) ;
if ( ! F_20 ( V_10 , V_23 , V_12 , V_21 , V_14 ) )
return 0 ;
break;
case V_38 :
case V_39 :
if ( ! V_20 && ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
if ( V_19 || V_15 ) {
if ( V_14 -> V_4 & V_40 ) {
if ( F_19 ( V_10 , L_6 ) <= 0 )
return 0 ;
} else {
if ( F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
}
}
if ( V_26 ) {
V_28 = V_26 ( V_41 , V_18 , V_13 , & V_27 ) ;
if ( V_28 == 0 )
return 0 ;
if ( V_28 == 2 )
return 1 ;
}
for ( V_28 = 0 , V_21 = V_13 -> V_32 ; V_28 < V_13 -> V_37 ; V_28 ++ , V_21 ++ ) {
const T_5 * V_42 ;
V_42 = F_25 ( V_18 , V_21 , 1 ) ;
V_23 = F_24 ( V_18 , V_42 ) ;
if ( ! F_20 ( V_10 , V_23 ,
V_12 + 2 , V_42 , V_14 ) )
return 0 ;
}
if ( V_14 -> V_4 & V_40 ) {
if ( F_22 ( V_10 , L_7 , V_12 , L_2 ) < 0 )
return 0 ;
}
if ( V_26 ) {
V_28 = V_26 ( V_43 , V_18 , V_13 , & V_27 ) ;
if ( V_28 == 0 )
return 0 ;
}
break;
default:
F_22 ( V_10 , L_8 , V_13 -> V_30 ) ;
return 0 ;
}
return 1 ;
}
int F_20 ( T_2 * V_10 , T_3 * * V_18 , int V_12 ,
const T_5 * V_21 , const T_1 * V_14 )
{
int V_28 , V_4 ;
const char * V_15 , * V_19 ;
V_4 = V_21 -> V_4 ;
if ( V_14 -> V_4 & V_44 )
V_15 = F_26 ( V_21 -> V_45 ) -> V_15 ;
else
V_15 = NULL ;
if ( V_14 -> V_4 & V_46 )
V_19 = NULL ;
else
V_19 = V_21 -> V_47 ;
if ( V_4 & V_48 ) {
char * V_49 ;
T_3 * V_50 ;
F_27 ( T_3 ) * V_51 ;
if ( V_19 ) {
if ( V_14 -> V_4 & V_52 ) {
if ( V_4 & V_53 )
V_49 = L_9 ;
else
V_49 = L_10 ;
if ( F_22 ( V_10 , L_11 ,
V_12 , L_2 , V_49 , V_21 -> V_47 ) <= 0 )
return 0 ;
} else if ( F_22 ( V_10 , L_12 , V_12 , L_2 , V_19 ) <= 0 )
return 0 ;
}
V_51 = ( F_27 ( T_3 ) * ) * V_18 ;
for ( V_28 = 0 ; V_28 < F_28 ( V_51 ) ; V_28 ++ ) {
if ( ( V_28 > 0 ) && ( F_19 ( V_10 , L_3 ) <= 0 ) )
return 0 ;
V_50 = F_29 ( V_51 , V_28 ) ;
if ( ! F_17 ( V_10 , & V_50 , V_12 + 2 ,
F_26 ( V_21 -> V_45 ) , NULL , NULL , 1 ,
V_14 ) )
return 0 ;
}
if ( ! V_28 && F_22 ( V_10 , L_13 , V_12 + 2 , L_2 ) <= 0 )
return 0 ;
if ( V_14 -> V_4 & V_40 ) {
if ( F_22 ( V_10 , L_7 , V_12 , L_2 ) <= 0 )
return 0 ;
}
return 1 ;
}
return F_17 ( V_10 , V_18 , V_12 , F_26 ( V_21 -> V_45 ) ,
V_19 , V_15 , 0 , V_14 ) ;
}
static int F_18 ( T_2 * V_10 , int V_12 ,
const char * V_19 , const char * V_15 ,
const T_1 * V_14 )
{
static char V_54 [] = L_14 ;
const int V_55 = sizeof( V_54 ) - 1 ;
#if 0
if (!sname && !fname)
return 1;
#endif
while ( V_12 > V_55 ) {
if ( F_30 ( V_10 , V_54 , V_55 ) != V_55 )
return 0 ;
V_12 -= V_55 ;
}
if ( F_30 ( V_10 , V_54 , V_12 ) != V_12 )
return 0 ;
if ( V_14 -> V_4 & V_17 )
V_15 = NULL ;
if ( V_14 -> V_4 & V_46 )
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
static int F_31 ( T_2 * V_10 , int V_56 ,
const T_1 * V_14 )
{
const char * V_57 ;
switch ( V_56 ) {
case - 1 :
V_57 = L_17 ;
break;
case 0 :
V_57 = L_18 ;
break;
default:
V_57 = L_19 ;
break;
}
if ( F_19 ( V_10 , V_57 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_32 ( T_2 * V_10 , T_10 * V_57 ,
const T_1 * V_14 )
{
char * V_58 ;
int V_1 = 1 ;
V_58 = F_33 ( NULL , V_57 ) ;
if ( F_19 ( V_10 , V_58 ) <= 0 )
V_1 = 0 ;
F_5 ( V_58 ) ;
return V_1 ;
}
static int F_34 ( T_2 * V_10 , const T_11 * V_59 ,
const T_1 * V_14 )
{
char V_60 [ 80 ] ;
const char * V_61 ;
V_61 = F_35 ( F_36 ( V_59 ) ) ;
if ( ! V_61 )
V_61 = L_2 ;
F_37 ( V_60 , sizeof V_60 , V_59 , 1 ) ;
if ( F_22 ( V_10 , L_20 , V_61 , V_60 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_38 ( T_2 * V_10 , T_12 * V_57 , int V_12 ,
const T_1 * V_14 )
{
if ( V_57 -> type == V_62 ) {
if ( F_22 ( V_10 , L_21 , V_57 -> V_4 & 0x7 ) <= 0 )
return 0 ;
} else if ( F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
if ( ( V_57 -> V_63 > 0 )
&& F_39 ( V_10 , ( char * ) V_57 -> V_64 , V_57 -> V_63 ,
V_12 + 2 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_21 ( T_2 * V_10 , T_3 * * V_18 ,
const T_4 * V_13 , int V_12 ,
const char * V_19 , const char * V_15 ,
const T_1 * V_14 )
{
long V_65 ;
T_12 * V_57 ;
int V_1 = 1 , V_66 = 1 ;
const char * V_67 ;
const T_13 * V_68 ;
V_68 = V_13 -> V_25 ;
if ( ! F_18 ( V_10 , V_12 , V_19 , V_15 , V_14 ) )
return 0 ;
if ( V_68 && V_68 -> V_69 )
return V_68 -> V_69 ( V_10 , V_18 , V_13 , V_12 , V_14 ) ;
V_57 = ( T_12 * ) * V_18 ;
if ( V_13 -> V_30 == V_33 )
V_65 = V_57 -> type & ~ V_70 ;
else
V_65 = V_13 -> V_65 ;
if ( V_65 == V_71 ) {
T_14 * V_72 = ( T_14 * ) * V_18 ;
V_65 = V_72 -> type ;
V_18 = & V_72 -> V_73 . V_74 ;
V_57 = ( T_12 * ) * V_18 ;
if ( V_14 -> V_4 & V_75 )
V_67 = NULL ;
else
V_67 = F_40 ( V_65 ) ;
} else {
if ( V_14 -> V_4 & V_76 )
V_67 = F_40 ( V_65 ) ;
else
V_67 = NULL ;
}
if ( V_65 == V_77 ) {
if ( F_19 ( V_10 , L_22 ) <= 0 )
return 0 ;
return 1 ;
}
if ( V_67 ) {
if ( F_19 ( V_10 , V_67 ) <= 0 )
return 0 ;
if ( F_19 ( V_10 , L_23 ) <= 0 )
return 0 ;
}
switch ( V_65 ) {
case V_78 :
{
int V_56 = * ( int * ) V_18 ;
if ( V_56 == - 1 )
V_56 = V_13 -> V_79 ;
V_1 = F_31 ( V_10 , V_56 , V_14 ) ;
}
break;
case V_80 :
case V_81 :
V_1 = F_32 ( V_10 , V_57 , V_14 ) ;
break;
case V_82 :
V_1 = F_41 ( V_10 , V_57 ) ;
break;
case V_83 :
V_1 = F_42 ( V_10 , V_57 ) ;
break;
case V_84 :
V_1 = F_34 ( V_10 , ( const T_11 * ) * V_18 , V_14 ) ;
break;
case V_85 :
case V_62 :
V_1 = F_38 ( V_10 , V_57 , V_12 , V_14 ) ;
V_66 = 0 ;
break;
case V_86 :
case V_87 :
case V_88 :
if ( F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
if ( F_43 ( V_10 , V_57 -> V_64 , V_57 -> V_63 , V_12 , 0 ) <= 0 )
V_1 = 0 ;
V_66 = 0 ;
break;
default:
V_1 = F_44 ( V_10 , V_57 , V_14 -> V_8 ) ;
}
if ( ! V_1 )
return 0 ;
if ( V_66 && F_19 ( V_10 , L_3 ) <= 0 )
return 0 ;
return 1 ;
}
