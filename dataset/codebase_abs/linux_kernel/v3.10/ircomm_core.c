static int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 ) ;
if ( V_1 == NULL ) {
F_3 ( L_1 , V_3 ) ;
return - V_4 ;
}
#ifdef F_4
{ struct V_5 * V_6 ;
V_6 = F_5 ( L_2 , 0 , V_7 , & V_8 ) ;
if ( ! V_6 ) {
F_6 ( V_9 L_3 ) ;
return - V_10 ;
}
}
#endif
F_7 ( L_4 ) ;
return 0 ;
}
static void T_2 F_8 ( void )
{
F_9 ( 2 , L_5 , V_3 ) ;
F_10 ( V_1 , ( V_11 ) V_12 ) ;
#ifdef F_4
F_11 ( L_2 , V_7 ) ;
#endif
}
struct V_13 * F_12 ( T_3 * V_14 , T_4 V_15 , int line )
{
struct V_13 * V_16 = NULL ;
int V_17 ;
F_9 ( 2 , L_6 , V_3 ,
V_15 ) ;
F_13 (ircomm != NULL, return NULL;) ;
V_16 = F_14 ( sizeof( struct V_13 ) , V_18 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_14 = * V_14 ;
V_16 -> V_19 = V_20 ;
if ( V_15 & V_21 ) {
V_16 -> V_22 = V_23 ;
V_17 = F_15 ( V_16 ) ;
} else
V_17 = F_16 ( V_16 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 ) ;
return NULL ;
}
V_16 -> V_15 = V_15 ;
V_16 -> line = line ;
F_18 ( V_1 , ( V_24 * ) V_16 , line , NULL ) ;
F_19 ( V_16 , V_25 ) ;
return V_16 ;
}
static int V_12 ( struct V_13 * V_16 )
{
F_9 ( 2 , L_5 , V_3 ) ;
F_20 ( V_16 , V_26 , NULL , NULL ) ;
if ( V_16 -> V_27 ) {
F_21 ( V_16 -> V_27 ) ;
V_16 -> V_27 = NULL ;
}
if ( V_16 -> V_28 ) {
F_22 ( V_16 -> V_28 ) ;
V_16 -> V_28 = NULL ;
}
V_16 -> V_19 = 0 ;
F_17 ( V_16 ) ;
return 0 ;
}
int F_23 ( struct V_13 * V_16 )
{
struct V_13 * V_29 ;
F_13 (self != NULL, return -EIO;) ;
F_13 (self->magic == IRCOMM_MAGIC, return -EIO;) ;
F_9 ( 0 , L_5 , V_3 ) ;
V_29 = F_24 ( V_1 , V_16 -> line , NULL ) ;
F_13 (entry == self, return -1;) ;
return V_12 ( V_16 ) ;
}
int F_25 ( struct V_13 * V_16 , T_4 V_30 ,
T_5 V_31 , T_5 V_32 , struct V_33 * V_34 ,
T_4 V_15 )
{
struct V_35 V_36 ;
int V_17 ;
F_9 ( 2 , L_5 , V_3 ) ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_MAGIC, return -1;) ;
V_16 -> V_15 = V_15 ;
V_36 . V_30 = V_30 ;
V_36 . V_31 = V_31 ;
V_36 . V_32 = V_32 ;
V_17 = F_20 ( V_16 , V_37 , V_34 , & V_36 ) ;
return V_17 ;
}
void F_26 ( struct V_13 * V_16 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_9 ( 2 , L_5 , V_3 ) ;
if ( V_16 -> V_14 . V_38 )
V_16 -> V_14 . V_38 ( V_16 -> V_14 . V_39 , V_16 ,
V_36 -> V_40 , V_36 -> V_41 ,
V_36 -> V_42 , V_34 ) ;
else {
F_9 ( 0 , L_7 , V_3 ) ;
}
}
int F_27 ( struct V_13 * V_16 , struct V_33 * V_43 )
{
int V_17 ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_MAGIC, return -1;) ;
F_9 ( 4 , L_5 , V_3 ) ;
V_17 = F_20 ( V_16 , V_44 , V_43 , NULL ) ;
return V_17 ;
}
void F_28 ( struct V_13 * V_16 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_9 ( 4 , L_5 , V_3 ) ;
if ( V_16 -> V_14 . V_45 )
V_16 -> V_14 . V_45 ( V_16 -> V_14 . V_39 ,
V_16 , V_36 -> V_40 ,
V_36 -> V_41 ,
V_36 -> V_42 , V_34 ) ;
else {
F_9 ( 0 , L_7 , V_3 ) ;
}
}
int F_29 ( struct V_13 * V_16 , struct V_33 * V_34 )
{
int V_17 ;
F_9 ( 4 , L_5 , V_3 ) ;
F_13 (self != NULL, return -EFAULT;) ;
F_13 (self->magic == IRCOMM_MAGIC, return -EFAULT;) ;
F_13 (skb != NULL, return -EFAULT;) ;
V_17 = F_20 ( V_16 , V_46 , V_34 , NULL ) ;
return V_17 ;
}
void F_30 ( struct V_13 * V_16 , struct V_33 * V_34 )
{
F_9 ( 4 , L_5 , V_3 ) ;
F_13 (skb->len > 0 , return;) ;
if ( V_16 -> V_14 . V_47 )
V_16 -> V_14 . V_47 ( V_16 -> V_14 . V_39 , V_16 , V_34 ) ;
else {
F_9 ( 0 , L_7 , V_3 ) ;
}
}
void F_31 ( struct V_13 * V_16 , struct V_33 * V_34 )
{
int V_48 ;
F_13 (skb->len > 0 , return;) ;
V_48 = V_34 -> V_49 [ 0 ] ;
if ( F_32 ( V_34 -> V_50 < ( V_48 + 1 ) ) ) {
F_9 ( 2 , L_8 ,
V_3 ) ;
return;
}
if ( V_48 > 0 )
F_33 ( V_16 , V_34 , V_48 ) ;
F_34 ( V_34 , V_48 + 1 ) ;
if ( V_34 -> V_50 )
F_30 ( V_16 , V_34 ) ;
else {
F_9 ( 4 , L_9 ,
V_3 ) ;
}
}
int F_35 ( struct V_13 * V_16 , struct V_33 * V_34 )
{
int V_17 ;
F_9 ( 2 , L_5 , V_3 ) ;
F_13 (self != NULL, return -EFAULT;) ;
F_13 (self->magic == IRCOMM_MAGIC, return -EFAULT;) ;
F_13 (skb != NULL, return -EFAULT;) ;
V_17 = F_20 ( V_16 , V_51 , V_34 , NULL ) ;
return V_17 ;
}
static void F_33 ( struct V_13 * V_16 ,
struct V_33 * V_34 , int V_48 )
{
F_9 ( 2 , L_5 , V_3 ) ;
if ( V_16 -> V_14 . V_52 ) {
struct V_33 * V_53 ;
V_53 = F_36 ( V_34 , V_54 ) ;
if ( ! V_53 )
return;
F_37 ( V_53 , V_48 + 1 ) ;
V_16 -> V_14 . V_52 ( V_16 -> V_14 . V_39 , V_16 ,
V_53 ) ;
F_38 ( V_53 ) ;
} else {
F_9 ( 0 , L_7 , V_3 ) ;
}
}
int F_39 ( struct V_13 * V_16 , struct V_33 * V_43 )
{
struct V_35 V_36 ;
int V_17 ;
F_9 ( 2 , L_5 , V_3 ) ;
F_13 (self != NULL, return -1;) ;
F_13 (self->magic == IRCOMM_MAGIC, return -1;) ;
V_17 = F_20 ( V_16 , V_26 , V_43 ,
& V_36 ) ;
return V_17 ;
}
void F_40 ( struct V_13 * V_16 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
F_9 ( 2 , L_5 , V_3 ) ;
F_13 (info != NULL, return;) ;
if ( V_16 -> V_14 . V_55 ) {
V_16 -> V_14 . V_55 ( V_16 -> V_14 . V_39 , V_16 ,
V_36 -> V_56 , V_34 ) ;
} else {
F_9 ( 0 , L_7 , V_3 ) ;
}
}
void F_41 ( struct V_13 * V_16 , T_6 V_57 )
{
F_9 ( 2 , L_5 , V_3 ) ;
F_13 (self != NULL, return;) ;
F_13 (self->magic == IRCOMM_MAGIC, return;) ;
if ( V_16 -> V_15 == V_21 )
return;
F_42 ( V_16 -> V_27 , V_57 ) ;
}
static void * F_43 ( struct V_58 * V_59 , T_7 * V_60 )
{
struct V_13 * V_16 ;
T_7 V_61 = 0 ;
F_44 ( & V_1 -> V_62 ) ;
for ( V_16 = (struct V_13 * ) F_45 ( V_1 ) ;
V_16 != NULL ;
V_16 = (struct V_13 * ) F_46 ( V_1 ) ) {
if ( V_61 ++ == * V_60 )
break;
}
return V_16 ;
}
static void * F_47 ( struct V_58 * V_59 , void * V_63 , T_7 * V_60 )
{
++ * V_60 ;
return ( void * ) F_46 ( V_1 ) ;
}
static void F_48 ( struct V_58 * V_59 , void * V_63 )
{
F_49 ( & V_1 -> V_62 ) ;
}
static int F_50 ( struct V_58 * V_59 , void * V_63 )
{
const struct V_13 * V_16 = V_63 ;
F_13 (self->magic == IRCOMM_MAGIC, return -EINVAL; ) ;
if( V_16 -> line < 0x10 )
F_51 ( V_59 , L_10 , V_16 -> line ) ;
else
F_51 ( V_59 , L_11 , V_16 -> line - 0x10 ) ;
F_51 ( V_59 ,
L_12 ,
V_64 [ V_16 -> V_65 ] ,
V_16 -> V_66 , V_16 -> V_30 ) ;
if( V_16 -> V_15 & V_21 )
F_51 ( V_59 , L_13 ) ;
if( V_16 -> V_15 & V_67 )
F_51 ( V_59 , L_14 ) ;
if( V_16 -> V_15 & V_68 )
F_51 ( V_59 , L_15 ) ;
if( V_16 -> V_15 & V_69 )
F_51 ( V_59 , L_16 ) ;
F_52 ( V_59 , '\n' ) ;
return 0 ;
}
static int F_53 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_54 ( V_71 , & V_72 ) ;
}
