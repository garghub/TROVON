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
return - V_13 ;
if ( V_10 -> V_14 != V_7 )
return - V_15 ;
* V_8 = V_10 -> V_2 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
int V_16 , T_2 V_7 , int * V_8 )
{
struct V_17 * V_18 =
(struct V_17 * ) V_6 ;
if ( ! ( V_18 -> V_11 & V_12 ) )
return - V_13 ;
if ( V_16 && ( V_18 -> V_19 == V_7 ) ) {
* V_8 = V_18 -> V_20 ;
return 0 ;
}
return - V_15 ;
}
static int F_5 ( struct V_5 * V_6 ,
int V_16 , T_2 V_7 , int * V_8 )
{
struct V_21 * V_22 =
(struct V_21 * ) V_6 ;
if ( ! ( V_22 -> V_11 & V_12 ) )
return - V_13 ;
if ( V_16 ) {
if ( ( V_6 -> V_23 < 16 ) || ( V_22 -> V_19 != V_7 ) )
return - V_15 ;
} else if ( V_22 -> V_14 != V_7 )
return - V_15 ;
* V_8 = ( V_22 -> V_2 << 8 ) | V_22 -> V_24 ;
return 0 ;
}
static int F_6 ( int type , T_2 V_7 )
{
unsigned long V_25 , V_6 ;
static struct V_26 * V_27 ;
static int V_28 ;
int V_8 = - 1 ;
if ( ! V_28 ) {
if ( F_7 ( F_8 ( V_29 , 0 ,
(struct V_30 * * ) & V_27 ) ) )
V_27 = NULL ;
V_28 ++ ;
}
if ( ! V_27 )
return V_8 ;
V_6 = ( unsigned long ) V_27 ;
V_25 = V_6 + V_27 -> V_31 . V_23 ;
V_6 += sizeof( struct V_26 ) ;
while ( V_6 + sizeof( struct V_5 ) < V_25 ) {
struct V_5 * V_31 =
(struct V_5 * ) V_6 ;
if ( V_31 -> type == V_32 ) {
if ( ! F_3 ( V_31 , V_7 , & V_8 ) )
break;
} else if ( V_31 -> type == V_33 ) {
if ( ! F_4 ( V_31 , type , V_7 , & V_8 ) )
break;
} else if ( V_31 -> type == V_34 ) {
if ( ! F_5 ( V_31 , type , V_7 , & V_8 ) )
break;
}
V_6 += V_31 -> V_23 ;
}
return V_8 ;
}
static int F_9 ( T_3 V_35 , int type , T_2 V_7 )
{
struct V_36 V_37 = { V_38 , NULL } ;
union V_39 * V_40 ;
struct V_5 * V_31 ;
int V_8 = - 1 ;
if ( F_7 ( F_10 ( V_35 , L_3 , NULL , & V_37 ) ) )
goto exit;
if ( ! V_37 . V_23 || ! V_37 . V_41 )
goto exit;
V_40 = V_37 . V_41 ;
if ( V_40 -> type != V_42 ||
V_40 -> V_37 . V_23 < sizeof( struct V_5 ) ) {
goto exit;
}
V_31 = (struct V_5 * ) V_40 -> V_37 . V_41 ;
if ( V_31 -> type == V_32 ) {
F_3 ( V_31 , V_7 , & V_8 ) ;
} else if ( V_31 -> type == V_34 ) {
F_5 ( V_31 , type , V_7 , & V_8 ) ;
}
exit:
F_11 ( V_37 . V_41 ) ;
return V_8 ;
}
int F_12 ( T_3 V_35 , int type , T_2 V_7 )
{
int V_8 ;
V_8 = F_9 ( V_35 , type , V_7 ) ;
if ( V_8 == - 1 )
V_8 = F_6 ( type , V_7 ) ;
return V_8 ;
}
int F_13 ( int V_8 , T_2 V_7 )
{
#ifdef F_14
int V_43 ;
#endif
if ( V_8 == - 1 ) {
if ( V_44 <= 1 && V_7 == 0 )
return V_7 ;
else
return V_8 ;
}
#ifdef F_14
F_15 (i) {
if ( F_16 ( V_43 ) == V_8 )
return V_43 ;
}
#else
if ( V_8 == 0 )
return V_8 ;
#endif
return - 1 ;
}
int F_17 ( T_3 V_35 , int type , T_2 V_7 )
{
int V_8 ;
V_8 = F_12 ( V_35 , type , V_7 ) ;
return F_13 ( V_8 , V_7 ) ;
}
static bool T_1 F_18 ( T_3 V_35 )
{
int V_45 , type ;
T_2 V_7 ;
T_4 V_46 ;
T_5 V_47 ;
unsigned long long V_48 ;
union V_39 V_49 = { 0 } ;
struct V_36 V_37 = { sizeof( union V_39 ) , & V_49 } ;
V_46 = F_19 ( V_35 , & V_47 ) ;
if ( F_7 ( V_46 ) )
return false ;
switch ( V_47 ) {
case V_50 :
V_46 = F_10 ( V_35 , NULL , NULL , & V_37 ) ;
if ( F_7 ( V_46 ) )
return false ;
V_7 = V_49 . V_51 . V_52 ;
break;
case V_53 :
V_46 = F_20 ( V_35 , L_4 , NULL , & V_48 ) ;
if ( F_7 ( V_46 ) )
return false ;
V_7 = V_48 ;
break;
default:
return false ;
}
type = ( V_47 == V_53 ) ? 1 : 0 ;
V_45 = F_17 ( V_35 , type , V_7 ) ;
if ( V_45 == - 1 )
return false ;
return true ;
}
static void F_21 ( T_2 * V_54 )
{
V_54 [ 0 ] = V_55 ;
V_54 [ 1 ] = 1 ;
V_54 [ 2 ] = V_56 ;
F_22 ( V_54 ) ;
}
static struct V_57 * F_23 ( void )
{
struct V_57 * V_58 ;
union V_39 * V_40 ;
T_2 * V_54 ;
V_58 = F_24 ( sizeof( struct V_57 ) , V_59 ) ;
if ( ! V_58 ) {
F_2 ( V_60 L_5 ) ;
return NULL ;
}
V_40 = F_24 ( sizeof( union V_39 ) , V_59 ) ;
if ( ! V_40 ) {
F_2 ( V_60 L_5 ) ;
F_11 ( V_58 ) ;
return NULL ;
}
V_54 = F_24 ( 12 , V_59 ) ;
if ( ! V_54 ) {
F_2 ( V_60 L_5 ) ;
F_11 ( V_40 ) ;
F_11 ( V_58 ) ;
return NULL ;
}
F_21 ( V_54 ) ;
V_40 -> type = V_42 ;
V_40 -> V_37 . V_23 = 12 ;
V_40 -> V_37 . V_41 = ( V_61 * ) V_54 ;
V_58 -> V_62 = 1 ;
V_58 -> V_41 = V_40 ;
return V_58 ;
}
static int
F_25 ( T_3 V_35 , struct V_57 * V_63 )
{
T_4 V_46 = V_64 ;
if ( V_3 == V_4 ) {
union V_39 * V_40 ;
T_2 * V_37 = NULL ;
V_40 = V_63 -> V_41 ;
V_37 = ( T_2 * ) ( V_40 -> V_37 . V_41 ) ;
V_37 [ 2 ] &= ~ ( V_65 | V_66 ) ;
}
V_46 = F_10 ( V_35 , L_6 , V_63 , NULL ) ;
if ( F_7 ( V_46 ) )
F_26 ( ( V_67 ,
L_7 ) ) ;
return V_46 ;
}
void F_27 ( T_3 V_35 )
{
struct V_57 * V_58 ;
if ( F_28 () == false )
return;
V_58 = F_23 () ;
if ( ! V_58 )
return;
F_25 ( V_35 , V_58 ) ;
F_11 ( V_58 -> V_41 -> V_37 . V_41 ) ;
F_11 ( V_58 -> V_41 ) ;
F_11 ( V_58 ) ;
}
static T_4 T_1
F_29 ( T_3 V_35 , T_2 V_68 , void * V_69 , void * * V_70 )
{
if ( F_18 ( V_35 ) == false )
return V_64 ;
F_27 ( V_35 ) ;
return V_64 ;
}
void T_1 F_30 ( void )
{
F_31 ( V_71 ) ;
F_32 ( V_50 , V_72 ,
V_73 ,
F_29 , NULL , NULL , NULL ) ;
F_33 ( L_8 , F_29 , NULL , NULL ) ;
}
