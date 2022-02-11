static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static inline void F_2 ( struct V_5 * V_2 ,
T_2 V_3 )
{
V_2 -> V_6 = V_3 ;
}
int F_3 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
F_4 (self != NULL, return -1;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_5 ( 4 , L_1 ,
V_10 , V_11 [ V_7 ] , V_12 [ V_2 -> V_6 ] ) ;
return (* V_6 [ V_2 -> V_6 ]) ( V_2 , V_7 , V_9 ) ;
}
void F_6 ( struct V_1 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
F_4 (self != NULL, return;) ;
F_4 (self->magic == LMP_LAP_MAGIC, return;) ;
F_5 ( 4 , L_1 , V_10 ,
V_11 [ V_7 ] ,
V_13 [ V_2 -> V_4 ] ) ;
(* V_4 [ V_2 -> V_4 ]) ( V_2 , V_7 , V_9 ) ;
}
void F_7 ( void * V_14 )
{
F_5 ( 4 , L_2 , V_10 ) ;
F_8 () ;
F_9 ( V_15 ) ;
F_10 ( V_16 , V_17 * V_18 ) ;
}
void F_11 ( void * V_14 )
{
struct V_5 * V_2 = (struct V_5 * ) V_14 ;
F_5 ( 2 , L_2 , V_10 ) ;
F_4 (self != NULL, return;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return;) ;
F_3 ( V_2 , V_19 , NULL ) ;
}
void F_12 ( void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_5 ( 2 , L_2 , V_10 ) ;
F_4 (self != NULL, return;) ;
F_4 (self->magic == LMP_LAP_MAGIC, return;) ;
F_6 ( V_2 , V_20 , NULL ) ;
}
static inline void
F_13 ( T_4 * V_21 ,
T_3 V_7 )
{
struct V_5 * V_22 ;
struct V_5 * V_23 ;
V_22 = (struct V_5 * ) F_14 ( V_21 ) ;
while ( NULL != F_15 ( V_21 ,
( long ) V_22 ,
NULL ,
( void * ) & V_23 ) ) {
F_3 ( V_22 , V_7 , NULL ) ;
V_22 = V_23 ;
}
}
static void F_16 ( struct V_1 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
F_5 ( 4 , L_2 , V_10 ) ;
F_4 (self->irlap != NULL, return;) ;
switch ( V_7 ) {
case V_24 :
F_17 ( V_2 -> V_25 , & V_16 -> V_26 ) ;
break;
case V_27 :
F_1 ( V_2 , V_28 ) ;
F_18 ( V_2 -> V_25 , V_9 ) ;
break;
case V_29 :
F_5 ( 4 , L_3 , V_10 ) ;
F_1 ( V_2 , V_30 ) ;
F_19 ( V_2 -> V_25 , V_2 -> V_31 , NULL , 0 ) ;
break;
case V_32 :
F_5 ( 4 , L_4 ,
V_10 ) ;
F_1 ( V_2 , V_33 ) ;
break;
default:
F_5 ( 0 , L_5 ,
V_10 , V_11 [ V_7 ] ) ;
break;
}
}
static void F_20 ( struct V_1 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
F_5 ( 2 , L_6 , V_10 , V_11 [ V_7 ] ) ;
switch ( V_7 ) {
case V_27 :
F_1 ( V_2 , V_28 ) ;
F_18 ( V_2 -> V_25 , V_9 ) ;
F_13 ( V_2 -> V_34 , V_35 ) ;
if ( F_21 ( V_2 -> V_34 ) == 0 ) {
F_5 ( 0 , L_7 , V_10 ) ;
F_22 ( V_2 , V_36 ) ;
}
break;
case V_29 :
break;
case V_35 :
F_1 ( V_2 , V_28 ) ;
F_13 ( V_2 -> V_34 , V_35 ) ;
if ( F_21 ( V_2 -> V_34 ) == 0 ) {
F_5 ( 0 , L_7 , V_10 ) ;
F_22 ( V_2 , V_36 ) ;
}
break;
case V_32 :
F_5 ( 4 , L_8 , V_10 ) ;
F_1 ( V_2 , V_33 ) ;
F_13 ( V_2 -> V_34 ,
V_32 ) ;
break;
case V_37 :
F_5 ( 4 , L_9 , V_10 ) ;
if ( F_21 ( V_2 -> V_34 ) <= 1 ) {
F_23 ( V_2 -> V_25 ) ;
}
break;
default:
F_5 ( 0 , L_5 ,
V_10 , V_11 [ V_7 ] ) ;
break;
}
}
static void F_24 ( struct V_1 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
F_5 ( 4 , L_2 , V_10 ) ;
switch ( V_7 ) {
case V_29 :
F_5 ( 4 , L_10 , V_10 ) ;
F_25 ( V_2 -> V_25 ) ;
F_13 ( V_2 -> V_34 , V_35 ) ;
F_13 ( V_16 -> V_38 ,
V_35 ) ;
break;
case V_37 :
if ( F_21 ( V_2 -> V_34 ) > 0 ) {
F_22 ( V_2 , V_39 * V_18 / 1000 ) ;
} else {
F_23 ( V_2 -> V_25 ) ;
}
break;
case V_20 :
if ( F_21 ( V_2 -> V_34 ) == 0 ) {
F_23 ( V_2 -> V_25 ) ;
}
break;
case V_32 :
F_1 ( V_2 , V_33 ) ;
F_26 ( V_2 ) ;
F_13 ( V_2 -> V_34 ,
V_32 ) ;
F_8 () ;
break;
default:
F_5 ( 0 , L_5 ,
V_10 , V_11 [ V_7 ] ) ;
break;
}
}
static int F_27 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
int V_40 = 0 ;
F_5 ( 4 , L_2 , V_10 ) ;
F_4 (self != NULL, return -1;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
switch ( V_7 ) {
#ifdef F_28
case V_41 :
F_29 ( V_2 , V_9 ) ;
break;
#endif
case V_42 :
F_5 ( 4 , L_11 , V_10 ) ;
if ( V_2 -> V_43 ) {
F_30 ( L_12 ,
V_10 ) ;
return - V_44 ;
}
F_31 ( V_9 ) ;
V_2 -> V_43 = V_9 ;
F_2 ( V_2 , V_45 ) ;
F_32 ( V_2 , 5 * V_18 ) ;
F_6 ( V_2 -> V_46 , V_29 , NULL ) ;
break;
case V_47 :
if ( V_2 -> V_43 ) {
F_30 ( L_12 ,
V_10 ) ;
return - V_44 ;
}
F_31 ( V_9 ) ;
V_2 -> V_43 = V_9 ;
F_2 ( V_2 , V_48 ) ;
F_32 ( V_2 , 1 * V_18 ) ;
F_6 ( V_2 -> V_46 , V_29 , NULL ) ;
break;
default:
F_5 ( 1 , L_13 ,
V_10 , V_11 [ V_7 ] , V_2 -> V_49 ) ;
break;
}
return V_40 ;
}
static int F_33 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
struct V_5 * V_22 ;
int V_40 = 0 ;
F_5 ( 4 , L_2 , V_10 ) ;
F_4 (self != NULL, return -1;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
switch ( V_7 ) {
case V_50 :
V_22 = F_34 ( V_16 -> V_38 , ( long ) V_2 ,
NULL ) ;
F_4 (lsap == self, return -1;) ;
F_4 (self->lap != NULL, return -1;) ;
F_4 (self->lap->lsaps != NULL, return -1;) ;
F_35 ( V_2 -> V_46 -> V_34 , ( V_51 * ) V_2 ,
( long ) V_2 , NULL ) ;
F_36 ( 0 , & V_2 -> V_52 ) ;
F_37 ( V_2 -> V_46 , V_2 -> V_53 ,
V_2 -> V_49 , V_54 , V_9 ) ;
F_38 ( & V_2 -> V_55 ) ;
F_2 ( V_2 , V_56 ) ;
break;
case V_19 :
F_5 ( 0 , L_14 , V_10 ) ;
V_2 -> V_46 = NULL ;
V_2 -> V_53 = V_57 ;
F_2 ( V_2 , V_58 ) ;
break;
default:
F_5 ( 0 , L_13 ,
V_10 , V_11 [ V_7 ] , V_2 -> V_49 ) ;
break;
}
return V_40 ;
}
static int F_39 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
struct V_8 * V_59 ;
int V_40 = 0 ;
F_5 ( 4 , L_2 , V_10 ) ;
F_4 (self != NULL, return -1;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
switch ( V_7 ) {
case V_42 :
break;
case V_50 :
F_5 ( 0 , L_15
L_16 , V_10 ) ;
break;
case V_60 :
F_5 ( 0 , L_17
L_18 , V_10 ) ;
break;
case V_35 :
F_5 ( 4 , L_19 , V_10 ) ;
F_2 ( V_2 , V_61 ) ;
V_59 = V_2 -> V_43 ;
V_2 -> V_43 = NULL ;
F_40 ( V_2 , V_59 ) ;
F_41 ( V_59 ) ;
break;
case V_19 :
F_5 ( 0 , L_14 , V_10 ) ;
V_2 -> V_46 = NULL ;
V_2 -> V_53 = V_57 ;
if( V_2 -> V_43 )
F_41 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
F_2 ( V_2 , V_58 ) ;
break;
default:
F_5 ( 0 , L_13 ,
V_10 , V_11 [ V_7 ] , V_2 -> V_49 ) ;
break;
}
return V_40 ;
}
static int F_42 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
T_5 V_62 ;
int V_40 = 0 ;
F_5 ( 4 , L_2 , V_10 ) ;
F_4 (self != NULL, return -1;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_4 (self->lap != NULL, return -1;) ;
switch ( V_7 ) {
case V_63 :
F_43 ( V_2 -> V_46 , V_2 -> V_53 ,
V_2 -> V_49 , FALSE , V_9 ) ;
break;
case V_64 :
F_44 ( V_2 , V_9 ) ;
break;
case V_65 :
F_4 (skb != NULL, return -1;) ;
F_43 ( V_2 -> V_46 , V_2 -> V_53 ,
V_2 -> V_49 , TRUE , V_9 ) ;
break;
case V_41 :
F_45 ( V_2 , V_9 ) ;
break;
case V_42 :
F_5 ( 0 , L_20
L_21 , V_10 ) ;
break;
case V_50 :
F_5 ( 0 , L_15
L_21 , V_10 ) ;
break;
case V_60 :
F_37 ( V_2 -> V_46 , V_2 -> V_53 , V_2 -> V_49 ,
V_66 , V_9 ) ;
F_2 ( V_2 , V_58 ) ;
if ( V_2 -> V_46 ) {
F_5 ( 4 , L_22 ,
V_10 ) ;
F_6 ( V_2 -> V_46 ,
V_37 ,
NULL ) ;
}
break;
case V_32 :
F_2 ( V_2 , V_58 ) ;
V_62 = F_46 ( V_2 -> V_46 -> V_62 ) ;
F_47 ( V_2 , V_62 , NULL ) ;
break;
case V_67 :
F_2 ( V_2 , V_58 ) ;
F_4 (self->lap != NULL, return -1;) ;
F_4 (self->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_4 (skb != NULL, return -1;) ;
F_4 (skb->len > 3 , return -1;) ;
V_62 = V_9 -> V_14 [ 3 ] ;
F_5 ( 4 , L_22 , V_10 ) ;
F_6 ( V_2 -> V_46 , V_37 , NULL ) ;
F_47 ( V_2 , V_62 , V_9 ) ;
break;
default:
F_5 ( 0 , L_13 ,
V_10 , V_11 [ V_7 ] , V_2 -> V_49 ) ;
break;
}
return V_40 ;
}
static int F_48 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
T_5 V_62 ;
int V_40 = 0 ;
F_4 (self != NULL, return -1;) ;
F_4 (self->magic == LMP_LSAP_MAGIC, return -1;) ;
F_5 ( 4 , L_2 , V_10 ) ;
switch ( V_7 ) {
case V_68 :
F_2 ( V_2 , V_56 ) ;
F_38 ( & V_2 -> V_55 ) ;
F_49 ( V_2 , V_9 ) ;
break;
case V_67 :
F_2 ( V_2 , V_58 ) ;
F_4 (self->lap != NULL, return -1;) ;
F_4 (self->lap->magic == LMP_LAP_MAGIC, return -1;) ;
F_4 (skb != NULL, return -1;) ;
F_4 (skb->len > 3 , return -1;) ;
V_62 = V_9 -> V_14 [ 3 ] ;
F_5 ( 4 , L_22 , V_10 ) ;
F_6 ( V_2 -> V_46 , V_37 , NULL ) ;
F_47 ( V_2 , V_62 , V_9 ) ;
break;
case V_32 :
F_2 ( V_2 , V_58 ) ;
F_38 ( & V_2 -> V_55 ) ;
F_4 (self->lap != NULL, return -1;) ;
F_4 (self->lap->magic == LMP_LAP_MAGIC, return -1;) ;
V_62 = F_46 ( V_2 -> V_46 -> V_62 ) ;
F_47 ( V_2 , V_62 , V_9 ) ;
break;
case V_19 :
F_5 ( 0 , L_14 , V_10 ) ;
F_4 (self->lap != NULL, return -1;) ;
F_6 ( V_2 -> V_46 , V_37 , NULL ) ;
F_2 ( V_2 , V_58 ) ;
F_47 ( V_2 , V_69 , NULL ) ;
break;
default:
F_5 ( 0 , L_13 ,
V_10 , V_11 [ V_7 ] , V_2 -> V_49 ) ;
break;
}
return V_40 ;
}
static int F_50 ( struct V_5 * V_2 , T_3 V_7 ,
struct V_8 * V_9 )
{
struct V_8 * V_59 ;
T_5 V_62 ;
int V_40 = 0 ;
F_5 ( 4 , L_2 , V_10 ) ;
F_4 (self != NULL, return -1;) ;
F_4 (irlmp != NULL, return -1;) ;
switch ( V_7 ) {
case V_35 :
F_4 (self->conn_skb != NULL, return -1;) ;
V_59 = V_2 -> V_43 ;
V_2 -> V_43 = NULL ;
F_37 ( V_2 -> V_46 , V_2 -> V_53 ,
V_2 -> V_49 , V_70 , V_59 ) ;
F_41 ( V_59 ) ;
F_2 ( V_2 , V_71 ) ;
break;
case V_19 :
F_5 ( 0 , L_23 , V_10 ) ;
F_4 (self->lap != NULL, return -1;) ;
F_6 ( V_2 -> V_46 , V_37 , NULL ) ;
F_2 ( V_2 , V_58 ) ;
F_47 ( V_2 , V_69 , NULL ) ;
break;
case V_32 :
F_38 ( & V_2 -> V_55 ) ;
F_2 ( V_2 , V_58 ) ;
V_62 = F_46 ( V_2 -> V_46 -> V_62 ) ;
F_47 ( V_2 , V_62 , NULL ) ;
break;
default:
F_5 ( 0 , L_13 ,
V_10 , V_11 [ V_7 ] , V_2 -> V_49 ) ;
break;
}
return V_40 ;
}
