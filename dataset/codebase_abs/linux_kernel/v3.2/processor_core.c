static int T_1 F_1 ( const struct V_1 * V_2 )
{
F_2 (KERN_NOTICE PREFIX L_1
L_2 , id->ident) ;
V_3 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
T_2 V_7 , int * V_8 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_6 ;
if ( ! ( V_10 -> V_11 & V_12 ) )
return 0 ;
if ( V_10 -> V_13 != V_7 )
return 0 ;
* V_8 = V_10 -> V_2 ;
return 1 ;
}
static int F_4 ( struct V_5 * V_6 ,
int V_14 , T_2 V_7 , int * V_8 )
{
struct V_15 * V_16 =
(struct V_15 * ) V_6 ;
if ( ! ( V_16 -> V_11 & V_12 ) )
return 0 ;
if ( V_14 && ( V_16 -> V_17 == V_7 ) ) {
* V_8 = V_16 -> V_18 ;
return 1 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
int V_14 , T_2 V_7 , int * V_8 )
{
struct V_19 * V_20 =
(struct V_19 * ) V_6 ;
if ( ! ( V_20 -> V_11 & V_12 ) )
return 0 ;
if ( V_14 ) {
if ( ( V_6 -> V_21 < 16 ) || ( V_20 -> V_17 != V_7 ) )
return 0 ;
} else if ( V_20 -> V_13 != V_7 )
return 0 ;
* V_8 = ( V_20 -> V_2 << 8 ) | V_20 -> V_22 ;
return 1 ;
}
static int F_6 ( int type , T_2 V_7 )
{
unsigned long V_23 , V_6 ;
static struct V_24 * V_25 ;
static int V_26 ;
int V_8 = - 1 ;
if ( ! V_26 ) {
if ( F_7 ( F_8 ( V_27 , 0 ,
(struct V_28 * * ) & V_25 ) ) )
V_25 = NULL ;
V_26 ++ ;
}
if ( ! V_25 )
return V_8 ;
V_6 = ( unsigned long ) V_25 ;
V_23 = V_6 + V_25 -> V_29 . V_21 ;
V_6 += sizeof( struct V_24 ) ;
while ( V_6 + sizeof( struct V_5 ) < V_23 ) {
struct V_5 * V_29 =
(struct V_5 * ) V_6 ;
if ( V_29 -> type == V_30 ) {
if ( F_3 ( V_29 , V_7 , & V_8 ) )
break;
} else if ( V_29 -> type == V_31 ) {
if ( F_4 ( V_29 , type , V_7 , & V_8 ) )
break;
} else if ( V_29 -> type == V_32 ) {
if ( F_5 ( V_29 , type , V_7 , & V_8 ) )
break;
}
V_6 += V_29 -> V_21 ;
}
return V_8 ;
}
static int F_9 ( T_3 V_33 , int type , T_2 V_7 )
{
struct V_34 V_35 = { V_36 , NULL } ;
union V_37 * V_38 ;
struct V_5 * V_29 ;
int V_8 = - 1 ;
if ( F_7 ( F_10 ( V_33 , L_3 , NULL , & V_35 ) ) )
goto exit;
if ( ! V_35 . V_21 || ! V_35 . V_39 )
goto exit;
V_38 = V_35 . V_39 ;
if ( V_38 -> type != V_40 ||
V_38 -> V_35 . V_21 < sizeof( struct V_5 ) ) {
goto exit;
}
V_29 = (struct V_5 * ) V_38 -> V_35 . V_39 ;
if ( V_29 -> type == V_30 ) {
F_3 ( V_29 , V_7 , & V_8 ) ;
} else if ( V_29 -> type == V_32 ) {
F_5 ( V_29 , type , V_7 , & V_8 ) ;
}
exit:
if ( V_35 . V_39 )
F_11 ( V_35 . V_39 ) ;
return V_8 ;
}
int F_12 ( T_3 V_33 , int type , T_2 V_7 )
{
#ifdef F_13
int V_41 ;
#endif
int V_8 = - 1 ;
V_8 = F_9 ( V_33 , type , V_7 ) ;
if ( V_8 == - 1 )
V_8 = F_6 ( type , V_7 ) ;
if ( V_8 == - 1 )
return V_8 ;
#ifdef F_13
F_14 (i) {
if ( F_15 ( V_41 ) == V_8 )
return V_41 ;
}
#else
if ( V_8 == 0 )
return V_8 ;
#endif
return - 1 ;
}
static bool T_1 F_16 ( T_3 V_33 )
{
int V_42 , type ;
T_2 V_7 ;
T_4 V_43 ;
T_5 V_44 ;
unsigned long long V_45 ;
union V_37 V_46 = { 0 } ;
struct V_34 V_35 = { sizeof( union V_37 ) , & V_46 } ;
V_43 = F_17 ( V_33 , & V_44 ) ;
if ( F_7 ( V_43 ) )
return false ;
switch ( V_44 ) {
case V_47 :
V_43 = F_10 ( V_33 , NULL , NULL , & V_35 ) ;
if ( F_7 ( V_43 ) )
return false ;
V_7 = V_46 . V_48 . V_49 ;
break;
case V_50 :
V_43 = F_18 ( V_33 , L_4 , NULL , & V_45 ) ;
if ( F_7 ( V_43 ) )
return false ;
V_7 = V_45 ;
break;
default:
return false ;
}
type = ( V_44 == V_50 ) ? 1 : 0 ;
V_42 = F_12 ( V_33 , type , V_7 ) ;
if ( V_42 == - 1 )
return false ;
return true ;
}
static void T_6 F_19 ( T_2 * V_51 )
{
V_51 [ 0 ] = V_52 ;
V_51 [ 1 ] = 1 ;
V_51 [ 2 ] = V_53 ;
F_20 ( V_51 ) ;
}
static struct V_54 * T_6 F_21 ( void )
{
struct V_54 * V_55 ;
union V_37 * V_38 ;
T_2 * V_51 ;
V_55 = F_22 ( sizeof( struct V_54 ) , V_56 ) ;
if ( ! V_55 ) {
F_2 ( V_57 L_5 ) ;
return NULL ;
}
V_38 = F_22 ( sizeof( union V_37 ) , V_56 ) ;
if ( ! V_38 ) {
F_2 ( V_57 L_5 ) ;
F_11 ( V_55 ) ;
return NULL ;
}
V_51 = F_22 ( 12 , V_56 ) ;
if ( ! V_51 ) {
F_2 ( V_57 L_5 ) ;
F_11 ( V_38 ) ;
F_11 ( V_55 ) ;
return NULL ;
}
F_19 ( V_51 ) ;
V_38 -> type = V_40 ;
V_38 -> V_35 . V_21 = 12 ;
V_38 -> V_35 . V_39 = ( V_58 * ) V_51 ;
V_55 -> V_59 = 1 ;
V_55 -> V_39 = V_38 ;
return V_55 ;
}
static int T_6
F_23 ( T_3 V_33 , struct V_54 * V_60 )
{
T_4 V_43 = V_61 ;
if ( V_3 == V_4 ) {
union V_37 * V_38 ;
T_2 * V_35 = NULL ;
V_38 = V_60 -> V_39 ;
V_35 = ( T_2 * ) ( V_38 -> V_35 . V_39 ) ;
V_35 [ 2 ] &= ~ ( V_62 | V_63 ) ;
}
V_43 = F_10 ( V_33 , L_6 , V_60 , NULL ) ;
if ( F_7 ( V_43 ) )
F_24 ( ( V_64 ,
L_7 ) ) ;
return V_43 ;
}
void T_6 F_25 ( T_3 V_33 )
{
struct V_54 * V_55 ;
if ( F_26 () == false )
return;
V_55 = F_21 () ;
if ( ! V_55 )
return;
F_23 ( V_33 , V_55 ) ;
F_11 ( V_55 -> V_39 -> V_35 . V_39 ) ;
F_11 ( V_55 -> V_39 ) ;
F_11 ( V_55 ) ;
}
static T_4 T_1
F_27 ( T_3 V_33 , T_2 V_65 , void * V_66 , void * * V_67 )
{
if ( F_16 ( V_33 ) == false )
return V_61 ;
F_25 ( V_33 ) ;
return V_61 ;
}
void T_1 F_28 ( void )
{
F_29 ( V_68 ) ;
F_30 ( V_47 , V_69 ,
V_70 ,
F_27 , NULL , NULL , NULL ) ;
F_31 ( L_8 , F_27 , NULL , NULL ) ;
}
