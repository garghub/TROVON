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
T_2 V_41 ;
F_3 ( V_4 , 0 ,
(struct V_5 * * ) & V_2 ) ;
if ( ! V_2 )
return V_36 ;
V_41 = F_9 ( V_2 , 1 , V_8 , true ) ;
F_11 ( (struct V_5 * ) V_2 ) ;
return V_41 ;
}
static T_2 F_12 ( T_4 V_42 , int type , T_1 V_8 ,
bool V_10 )
{
struct V_43 V_44 = { V_45 , NULL } ;
union V_46 * V_47 ;
struct V_6 * V_13 ;
T_2 V_35 = V_36 ;
if ( F_2 ( F_13 ( V_42 , L_1 , NULL , & V_44 ) ) )
goto exit;
if ( ! V_44 . V_27 || ! V_44 . V_48 )
goto exit;
V_47 = V_44 . V_48 ;
if ( V_47 -> type != V_49 ||
V_47 -> V_44 . V_27 < sizeof( struct V_6 ) ) {
goto exit;
}
V_13 = (struct V_6 * ) V_47 -> V_44 . V_48 ;
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
F_14 ( V_44 . V_48 ) ;
return V_35 ;
}
static T_2 F_15 ( T_4 V_42 , int type ,
T_1 V_8 , bool V_10 )
{
T_2 V_35 ;
V_35 = F_12 ( V_42 , type , V_8 , V_10 ) ;
if ( F_16 ( V_35 ) )
V_35 = F_9 ( F_1 () , type , V_8 ,
V_10 ) ;
return V_35 ;
}
T_2 F_17 ( T_4 V_42 , int type , T_1 V_8 )
{
return F_15 ( V_42 , type , V_8 , true ) ;
}
int F_18 ( T_2 V_35 , T_1 V_8 )
{
#ifdef F_19
int V_50 ;
#endif
if ( F_16 ( V_35 ) ) {
if ( V_51 <= 1 && V_8 == 0 )
return V_8 ;
else
return - V_18 ;
}
#ifdef F_19
F_20 (i) {
if ( F_21 ( V_50 ) == V_35 )
return V_50 ;
}
#else
if ( V_35 == 0 )
return V_35 ;
#endif
return - V_16 ;
}
int F_22 ( T_4 V_42 , int type , T_1 V_8 )
{
T_2 V_35 ;
V_35 = F_17 ( V_42 , type , V_8 ) ;
return F_18 ( V_35 , V_8 ) ;
}
static bool T_3
F_23 ( T_4 V_42 , T_2 * V_35 , int * V_52 )
{
int type , V_19 ;
T_1 V_8 ;
T_5 V_53 ;
T_6 V_54 ;
unsigned long long V_55 ;
union V_46 V_56 = { 0 } ;
struct V_43 V_44 = { sizeof( union V_46 ) , & V_56 } ;
V_53 = F_24 ( V_42 , & V_54 ) ;
if ( F_2 ( V_53 ) )
return false ;
switch ( V_54 ) {
case V_57 :
V_53 = F_13 ( V_42 , NULL , NULL , & V_44 ) ;
if ( F_2 ( V_53 ) )
return false ;
V_8 = V_56 . V_58 . V_59 ;
if( F_25 ( V_8 ) )
return false ;
break;
case V_60 :
V_53 = F_26 ( V_42 , L_2 , NULL , & V_55 ) ;
if ( F_2 ( V_53 ) )
return false ;
V_8 = V_55 ;
break;
default:
return false ;
}
type = ( V_54 == V_60 ) ? 1 : 0 ;
* V_35 = F_15 ( V_42 , type , V_8 , false ) ;
V_19 = F_18 ( * V_35 , V_8 ) ;
if ( V_19 < 0 )
return false ;
* V_52 = V_19 ;
return true ;
}
static T_5 T_3
F_27 ( T_4 V_42 , T_1 V_61 , void * V_62 ,
void * * V_41 )
{
T_2 V_35 ;
int V_63 ;
if ( ! F_23 ( V_42 , & V_35 , & V_63 ) )
return V_64 ;
F_28 ( V_42 , V_63 , V_35 ) ;
return V_65 ;
}
void T_3 F_29 ( void )
{
F_30 ( V_57 , V_66 ,
V_67 , F_27 ,
NULL , NULL , NULL ) ;
}
void T_3 F_29 ( void ) {}
static int F_31 ( struct V_6 * V_7 , T_1 V_68 ,
T_7 * V_69 , int * V_70 )
{
struct V_71 * V_72 = (struct V_71 * ) V_7 ;
if ( V_72 -> V_73 != V_68 )
return 0 ;
* V_69 = V_72 -> V_74 ;
* V_70 = V_72 -> V_19 ;
return 1 ;
}
static int F_32 ( T_1 V_68 , T_7 * V_69 )
{
struct V_6 * V_75 ;
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
V_75 = (struct V_6 * ) V_7 ;
if ( V_75 -> type == V_76 &&
F_31 ( V_75 , V_68 , V_69 , & V_9 ) )
break;
else
V_7 += V_75 -> V_27 ;
}
return V_9 ;
}
static int F_33 ( T_4 V_42 , T_1 V_68 ,
T_7 * V_69 )
{
struct V_43 V_44 = { V_45 , NULL } ;
struct V_6 * V_13 ;
union V_46 * V_47 ;
int V_9 = - 1 ;
if ( F_2 ( F_13 ( V_42 , L_1 , NULL , & V_44 ) ) )
goto exit;
if ( ! V_44 . V_27 || ! V_44 . V_48 )
goto exit;
V_47 = V_44 . V_48 ;
if ( V_47 -> type != V_49 ||
V_47 -> V_44 . V_27 < sizeof( struct V_6 ) )
goto exit;
V_13 = (struct V_6 * ) V_47 -> V_44 . V_48 ;
if ( V_13 -> type == V_76 )
F_31 ( V_13 , V_68 , V_69 , & V_9 ) ;
exit:
F_14 ( V_44 . V_48 ) ;
return V_9 ;
}
int F_34 ( T_4 V_42 , T_1 V_68 , T_7 * V_69 )
{
int V_9 ;
V_9 = F_33 ( V_42 , V_68 , V_69 ) ;
if ( V_9 == - 1 )
V_9 = F_32 ( V_68 , V_69 ) ;
return V_9 ;
}
