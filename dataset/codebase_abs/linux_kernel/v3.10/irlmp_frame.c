inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
int V_5 , struct V_6 * V_7 )
{
V_7 -> V_8 [ 0 ] = V_3 ;
V_7 -> V_8 [ 1 ] = V_4 ;
if ( V_5 ) {
F_2 ( 4 , L_1 , V_9 ) ;
F_3 ( V_2 -> V_10 , V_7 , TRUE ) ;
} else
F_3 ( V_2 -> V_10 , V_7 , FALSE ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_11 , struct V_6 * V_7 )
{
T_1 * V_12 ;
F_2 ( 2 , L_2 , V_9 ) ;
F_5 (self != NULL, return;) ;
F_5 (self->magic == LMP_LAP_MAGIC, return;) ;
F_5 (skb != NULL, return;) ;
V_12 = V_7 -> V_8 ;
V_12 [ 0 ] = V_3 | V_13 ;
V_12 [ 1 ] = V_4 ;
V_12 [ 2 ] = V_11 ;
if ( V_11 == V_14 )
V_12 [ 3 ] = 0x01 ;
else
V_12 [ 3 ] = 0x00 ;
F_3 ( V_2 -> V_10 , V_7 , FALSE ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_15 )
{
struct V_16 * V_17 ;
T_1 V_18 ;
T_1 V_19 ;
T_1 * V_20 ;
F_2 ( 4 , L_2 , V_9 ) ;
F_5 (self != NULL, return;) ;
F_5 (self->magic == LMP_LAP_MAGIC, return;) ;
F_5 (skb->len > 2 , return;) ;
V_20 = V_7 -> V_8 ;
V_18 = V_20 [ 0 ] & V_21 ;
V_19 = V_20 [ 1 ] ;
if ( ( V_20 [ 0 ] & V_13 ) && ( V_20 [ 2 ] == V_22 ) ) {
F_2 ( 3 , L_3
L_4 ,
V_9 , V_18 , V_19 ) ;
V_17 = F_7 ( V_2 , V_19 , V_18 , V_22 ,
V_23 -> V_24 ) ;
if ( ! V_17 ) {
F_2 ( 1 , L_5 , V_9 ) ;
V_17 = F_7 ( V_2 , V_19 , V_18 , 0 ,
V_2 -> V_25 ) ;
}
} else
V_17 = F_7 ( V_2 , V_19 , V_18 , 0 ,
V_2 -> V_25 ) ;
if ( V_17 == NULL ) {
F_2 ( 2 , L_6 ) ;
F_2 ( 2 , L_7 ,
V_9 , V_18 , V_19 ) ;
if ( V_20 [ 0 ] & V_13 ) {
F_2 ( 2 , L_8 ,
V_9 , V_20 [ 2 ] ) ;
} else {
F_2 ( 2 , L_9 , V_9 ) ;
}
return;
}
if ( V_20 [ 0 ] & V_13 ) {
switch ( V_20 [ 2 ] ) {
case V_22 :
V_17 -> V_26 = V_2 ;
F_8 ( V_17 , V_27 , V_7 ) ;
break;
case V_28 :
F_8 ( V_17 , V_29 , V_7 ) ;
break;
case V_14 :
F_2 ( 4 , L_10 ,
V_9 ) ;
F_8 ( V_17 , V_30 ,
V_7 ) ;
break;
case V_31 :
F_2 ( 0 , L_11 ) ;
break;
case V_32 :
F_2 ( 0 , L_12 ) ;
break;
default:
F_2 ( 0 , L_13 ,
V_9 , V_20 [ 2 ] ) ;
break;
}
} else if ( V_15 ) {
if ( V_17 -> V_33 == V_34 )
F_9 ( V_17 , V_7 ) ;
else
F_8 ( V_17 , V_35 , V_7 ) ;
} else {
if ( V_17 -> V_33 == V_34 )
F_10 ( V_17 , V_7 ) ;
else
F_8 ( V_17 , V_36 , V_7 ) ;
}
}
void F_11 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_16 * V_17 ;
T_1 V_18 ;
T_1 V_19 ;
T_1 V_37 ;
T_1 * V_20 ;
unsigned long V_38 ;
F_2 ( 4 , L_2 , V_9 ) ;
F_5 (self != NULL, return;) ;
F_5 (self->magic == LMP_LAP_MAGIC, return;) ;
F_5 (skb->len > 2 , return;) ;
V_20 = V_7 -> V_8 ;
V_18 = V_20 [ 0 ] & V_21 ;
V_19 = V_20 [ 1 ] ;
V_37 = V_20 [ 2 ] ;
if ( V_37 & 0x80 ) {
F_2 ( 0 , L_14 ,
V_9 ) ;
return;
}
if ( ( V_18 != V_39 ) || ( V_19 != V_39 ) ) {
F_2 ( 0 , L_15 , V_9 ) ;
return;
}
F_12 ( & V_23 -> V_24 -> V_40 , V_38 ) ;
V_17 = (struct V_16 * ) F_13 ( V_23 -> V_24 ) ;
while ( V_17 != NULL ) {
if ( ( V_17 -> V_18 == V_18 ) &&
( V_17 -> V_19 == V_19 ) &&
( V_17 -> V_37 == V_37 ) )
{
break;
}
V_17 = (struct V_16 * ) F_14 ( V_23 -> V_24 ) ;
}
F_15 ( & V_23 -> V_24 -> V_40 , V_38 ) ;
if ( V_17 )
F_16 ( V_17 , V_7 ) ;
else {
F_2 ( 0 , L_16 , V_9 ) ;
}
}
void F_17 ( struct V_1 * V_26 ,
struct V_41 * V_10 ,
T_2 V_42 ,
struct V_6 * V_7 )
{
F_2 ( 2 , L_2 , V_9 ) ;
F_5 (lap != NULL, return;) ;
F_5 (lap->magic == LMP_LAP_MAGIC, return;) ;
V_26 -> V_42 = V_42 ;
V_26 -> V_43 = V_44 ;
F_18 ( V_26 , V_45 , NULL ) ;
}
void F_19 ( struct V_1 * V_2 , T_3 V_46 ,
T_3 V_43 , struct V_47 * V_48 ,
struct V_6 * V_7 )
{
F_2 ( 4 , L_2 , V_9 ) ;
V_2 -> V_48 = V_48 ;
V_2 -> V_43 = V_43 ;
F_5 (self->saddr == saddr, return;) ;
F_18 ( V_2 , V_49 , V_7 ) ;
}
void F_20 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_6 * V_7 )
{
F_2 ( 4 , L_2 , V_9 ) ;
F_5 (self != NULL, return;) ;
F_5 (self->magic == LMP_LAP_MAGIC, return;) ;
F_5 (qos != NULL, return;) ;
V_2 -> V_48 = V_48 ;
F_18 ( V_2 , V_50 , NULL ) ;
}
void F_21 ( struct V_1 * V_2 ,
T_4 * V_51 )
{
F_5 (self != NULL, return;) ;
F_5 (self->magic == LMP_LAP_MAGIC, return;) ;
F_22 ( V_23 -> V_52 , V_51 ) ;
F_23 ( V_23 -> V_52 , V_53 ) ;
}
void F_24 ( struct V_1 * V_2 , T_5 * log )
{
F_2 ( 4 , L_2 , V_9 ) ;
F_5 (self != NULL, return;) ;
F_5 (self->magic == LMP_LAP_MAGIC, return;) ;
F_25 ( V_23 -> V_52 , log ) ;
F_23 ( V_23 -> V_52 , V_54 ) ;
}
static inline void F_26 ( struct V_1 * V_26 ,
struct V_16 * V_17 )
{
V_26 -> V_55 . V_56 = FALSE ;
V_26 -> V_55 . V_19 = V_17 -> V_19 ;
V_26 -> V_55 . V_18 = V_17 -> V_18 ;
V_26 -> V_55 . V_17 = V_17 ;
V_26 -> V_55 . V_56 = TRUE ;
}
static struct V_16 * F_7 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_18 , int V_57 ,
T_5 * V_58 )
{
struct V_16 * V_17 ;
unsigned long V_38 ;
#ifdef F_27
if ( ( V_2 -> V_55 . V_56 ) &&
( V_2 -> V_55 . V_18 == V_18 ) &&
( V_2 -> V_55 . V_19 == V_19 ) )
{
return V_2 -> V_55 . V_17 ;
}
#endif
F_12 ( & V_58 -> V_40 , V_38 ) ;
V_17 = (struct V_16 * ) F_13 ( V_58 ) ;
while ( V_17 != NULL ) {
if ( ( V_57 == V_22 ) &&
( V_17 -> V_18 == V_18 ) &&
( V_17 -> V_19 == V_59 ) ) {
V_17 -> V_19 = V_19 ;
break;
}
if ( ( V_17 -> V_18 == V_18 ) &&
( V_17 -> V_19 == V_19 ) )
break;
V_17 = (struct V_16 * ) F_14 ( V_58 ) ;
}
#ifdef F_27
if( V_17 )
F_26 ( V_2 , V_17 ) ;
#endif
F_15 ( & V_58 -> V_40 , V_38 ) ;
return V_17 ;
}
