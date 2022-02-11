static struct V_1 * F_1 ( void )
{
static struct V_1 * V_2 ;
static int V_3 ;
if ( ! V_3 ) {
if ( F_2 ( F_3 ( V_4 , 0 ,
(struct V_5 * * ) & V_2 ) ) )
V_2 = NULL ;
V_3 ++ ;
}
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 ,
T_1 V_8 , T_2 * V_9 , bool V_10 )
{
struct V_11 * V_12 =
F_5 ( V_7 , struct V_11 , V_13 ) ;
if ( V_10 && ! ( V_12 -> V_14 & V_15 ) )
return - V_16 ;
if ( V_12 -> V_17 != V_8 )
return - V_18 ;
* V_9 = V_12 -> V_19 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
int V_20 , T_1 V_8 , T_2 * V_9 ,
bool V_10 )
{
struct V_21 * V_22 =
F_5 ( V_7 , struct V_21 , V_13 ) ;
if ( V_10 && ! ( V_22 -> V_14 & V_15 ) )
return - V_16 ;
if ( V_20 && ( V_22 -> V_23 == V_8 ) ) {
* V_9 = V_22 -> V_24 ;
return 0 ;
}
return - V_18 ;
}
static int F_7 ( struct V_6 * V_7 ,
int V_20 , T_1 V_8 , T_2 * V_9 ,
bool V_10 )
{
struct V_25 * V_26 =
F_5 ( V_7 , struct V_25 , V_13 ) ;
if ( V_10 && ! ( V_26 -> V_14 & V_15 ) )
return - V_16 ;
if ( V_20 ) {
if ( ( V_7 -> V_27 < 16 ) || ( V_26 -> V_23 != V_8 ) )
return - V_18 ;
} else if ( V_26 -> V_17 != V_8 )
return - V_18 ;
* V_9 = ( V_26 -> V_19 << 8 ) | V_26 -> V_28 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
int V_20 , T_1 V_8 , T_2 * V_29 ,
bool V_10 )
{
struct V_30 * V_31 =
F_5 ( V_7 , struct V_30 , V_13 ) ;
if ( V_10 && ! ( V_31 -> V_32 & V_15 ) )
return - V_16 ;
if ( V_20 && ( V_31 -> V_23 == V_8 ) ) {
* V_29 = V_31 -> V_33 ;
return 0 ;
}
return - V_18 ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
int type , T_1 V_8 , bool V_10 )
{
unsigned long V_34 , V_7 ;
T_2 V_35 = V_36 ;
if ( ! V_2 )
return V_35 ;
V_7 = ( unsigned long ) V_2 ;
V_34 = V_7 + V_2 -> V_13 . V_27 ;
V_7 += sizeof( struct V_1 ) ;
while ( V_7 + sizeof( struct V_6 ) < V_34 ) {
struct V_6 * V_13 =
(struct V_6 * ) V_7 ;
if ( V_13 -> type == V_37 ) {
if ( ! F_4 ( V_13 , V_8 , & V_35 ,
V_10 ) )
break;
} else if ( V_13 -> type == V_38 ) {
if ( ! F_6 ( V_13 , type , V_8 , & V_35 ,
V_10 ) )
break;
} else if ( V_13 -> type == V_39 ) {
if ( ! F_7 ( V_13 , type , V_8 , & V_35 ,
V_10 ) )
break;
} else if ( V_13 -> type == V_40 ) {
if ( ! F_8 ( V_13 , type , V_8 , & V_35 ,
V_10 ) )
break;
}
V_7 += V_13 -> V_27 ;
}
return V_35 ;
}
T_2 T_3 F_10 ( T_1 V_8 )
{
struct V_1 * V_2 = NULL ;
T_4 V_41 ;
T_2 V_42 ;
F_11 ( V_4 , 0 ,
(struct V_5 * * ) & V_2 ,
& V_41 ) ;
if ( ! V_2 )
return V_36 ;
V_42 = F_9 ( V_2 , 1 , V_8 , true ) ;
F_12 ( V_2 , V_41 ) ;
return V_42 ;
}
static T_2 F_13 ( T_5 V_43 , int type , T_1 V_8 ,
bool V_10 )
{
struct V_44 V_45 = { V_46 , NULL } ;
union V_47 * V_48 ;
struct V_6 * V_13 ;
T_2 V_35 = V_36 ;
if ( F_2 ( F_14 ( V_43 , L_1 , NULL , & V_45 ) ) )
goto exit;
if ( ! V_45 . V_27 || ! V_45 . V_49 )
goto exit;
V_48 = V_45 . V_49 ;
if ( V_48 -> type != V_50 ||
V_48 -> V_45 . V_27 < sizeof( struct V_6 ) ) {
goto exit;
}
V_13 = (struct V_6 * ) V_48 -> V_45 . V_49 ;
if ( V_13 -> type == V_37 )
F_4 ( V_13 , V_8 , & V_35 , V_10 ) ;
else if ( V_13 -> type == V_39 )
F_7 ( V_13 , type , V_8 , & V_35 , V_10 ) ;
else if ( V_13 -> type == V_38 )
F_6 ( V_13 , type , V_8 , & V_35 , V_10 ) ;
else if ( V_13 -> type == V_40 )
F_8 ( V_13 , type , V_8 , & V_35 ,
V_10 ) ;
exit:
F_15 ( V_45 . V_49 ) ;
return V_35 ;
}
static T_2 F_16 ( T_5 V_43 , int type ,
T_1 V_8 , bool V_10 )
{
T_2 V_35 ;
V_35 = F_13 ( V_43 , type , V_8 , V_10 ) ;
if ( F_17 ( V_35 ) )
V_35 = F_9 ( F_1 () , type , V_8 ,
V_10 ) ;
return V_35 ;
}
T_2 F_18 ( T_5 V_43 , int type , T_1 V_8 )
{
return F_16 ( V_43 , type , V_8 , true ) ;
}
int F_19 ( T_2 V_35 , T_1 V_8 )
{
#ifdef F_20
int V_51 ;
#endif
if ( F_17 ( V_35 ) ) {
if ( V_52 <= 1 && V_8 == 0 )
return V_8 ;
else
return - V_18 ;
}
#ifdef F_20
F_21 (i) {
if ( F_22 ( V_51 ) == V_35 )
return V_51 ;
}
#else
if ( V_35 == 0 )
return V_35 ;
#endif
return - V_16 ;
}
int F_23 ( T_5 V_43 , int type , T_1 V_8 )
{
T_2 V_35 ;
V_35 = F_18 ( V_43 , type , V_8 ) ;
return F_19 ( V_35 , V_8 ) ;
}
static bool T_3
F_24 ( T_5 V_43 , T_2 * V_35 , int * V_53 )
{
int type , V_19 ;
T_1 V_8 ;
T_6 V_54 ;
T_7 V_55 ;
unsigned long long V_56 ;
union V_47 V_57 = { 0 } ;
struct V_44 V_45 = { sizeof( union V_47 ) , & V_57 } ;
V_54 = F_25 ( V_43 , & V_55 ) ;
if ( F_2 ( V_54 ) )
return false ;
switch ( V_55 ) {
case V_58 :
V_54 = F_14 ( V_43 , NULL , NULL , & V_45 ) ;
if ( F_2 ( V_54 ) )
return false ;
V_8 = V_57 . V_59 . V_60 ;
if( F_26 ( V_8 ) )
return false ;
break;
case V_61 :
V_54 = F_27 ( V_43 , L_2 , NULL , & V_56 ) ;
if ( F_2 ( V_54 ) )
return false ;
V_8 = V_56 ;
break;
default:
return false ;
}
type = ( V_55 == V_61 ) ? 1 : 0 ;
* V_35 = F_16 ( V_43 , type , V_8 , false ) ;
V_19 = F_19 ( * V_35 , V_8 ) ;
if ( V_19 < 0 )
return false ;
* V_53 = V_19 ;
return true ;
}
static T_6 T_3
F_28 ( T_5 V_43 , T_1 V_62 , void * V_63 ,
void * * V_42 )
{
T_2 V_35 ;
int V_64 ;
if ( ! F_24 ( V_43 , & V_35 , & V_64 ) )
return V_65 ;
F_29 ( V_43 , V_64 , V_35 ) ;
return V_66 ;
}
void T_3 F_30 ( void )
{
F_31 ( V_58 , V_67 ,
V_68 , F_28 ,
NULL , NULL , NULL ) ;
}
void T_3 F_30 ( void ) {}
static int F_32 ( struct V_6 * V_7 , T_1 V_69 ,
T_8 * V_70 , int * V_71 )
{
struct V_72 * V_73 = (struct V_72 * ) V_7 ;
if ( V_73 -> V_74 != V_69 )
return 0 ;
* V_70 = V_73 -> V_75 ;
* V_71 = V_73 -> V_19 ;
return 1 ;
}
static int F_33 ( T_1 V_69 , T_8 * V_70 )
{
struct V_6 * V_76 ;
unsigned long V_34 , V_7 ;
struct V_1 * V_2 ;
int V_9 = - 1 ;
V_2 = F_1 () ;
if ( ! V_2 )
return V_9 ;
V_7 = ( unsigned long ) V_2 ;
V_34 = V_7 + V_2 -> V_13 . V_27 ;
V_7 += sizeof( struct V_1 ) ;
while ( V_7 + sizeof( struct V_6 ) < V_34 ) {
V_76 = (struct V_6 * ) V_7 ;
if ( V_76 -> type == V_77 &&
F_32 ( V_76 , V_69 , V_70 , & V_9 ) )
break;
else
V_7 += V_76 -> V_27 ;
}
return V_9 ;
}
static int F_34 ( T_5 V_43 , T_1 V_69 ,
T_8 * V_70 )
{
struct V_44 V_45 = { V_46 , NULL } ;
struct V_6 * V_13 ;
union V_47 * V_48 ;
int V_9 = - 1 ;
if ( F_2 ( F_14 ( V_43 , L_1 , NULL , & V_45 ) ) )
goto exit;
if ( ! V_45 . V_27 || ! V_45 . V_49 )
goto exit;
V_48 = V_45 . V_49 ;
if ( V_48 -> type != V_50 ||
V_48 -> V_45 . V_27 < sizeof( struct V_6 ) )
goto exit;
V_13 = (struct V_6 * ) V_48 -> V_45 . V_49 ;
if ( V_13 -> type == V_77 )
F_32 ( V_13 , V_69 , V_70 , & V_9 ) ;
exit:
F_15 ( V_45 . V_49 ) ;
return V_9 ;
}
int F_35 ( T_5 V_43 , T_1 V_69 , T_8 * V_70 )
{
int V_9 ;
V_9 = F_34 ( V_43 , V_69 , V_70 ) ;
if ( V_9 == - 1 )
V_9 = F_33 ( V_69 , V_70 ) ;
return V_9 ;
}
