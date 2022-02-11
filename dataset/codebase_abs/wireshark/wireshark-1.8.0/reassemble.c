static void F_1 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
for( V_3 = V_1 ; V_3 -> V_4 ; V_3 = V_3 -> V_4 ) {
if ( V_2 -> V_5 < V_3 -> V_4 -> V_5 )
break;
}
V_2 -> V_4 = V_3 -> V_4 ;
V_3 -> V_4 = V_2 ;
}
static void * F_2 ( const void * V_6 )
{
const T_2 * V_7 = ( const T_2 * ) V_6 ;
T_2 * V_8 = F_3 ( T_2 ) ;
F_4 ( & V_8 -> V_9 , & V_7 -> V_9 ) ;
F_4 ( & V_8 -> V_10 , & V_7 -> V_10 ) ;
V_8 -> V_11 = V_7 -> V_11 ;
return V_8 ;
}
static void * F_5 ( const void * V_6 )
{
const T_3 * V_7 = ( const T_3 * ) V_6 ;
T_3 * V_8 = F_3 ( T_3 ) ;
F_4 ( & V_8 -> V_9 , & V_7 -> V_9 ) ;
F_4 ( & V_8 -> V_10 , & V_7 -> V_10 ) ;
V_8 -> V_11 = V_7 -> V_11 ;
V_8 -> V_12 = V_7 -> V_12 ;
return V_8 ;
}
static T_4
F_6 ( T_5 V_13 , T_5 V_14 )
{
const T_2 * V_15 = ( const T_2 * ) V_13 ;
const T_2 * V_16 = ( const T_2 * ) V_14 ;
return ( ( ( V_15 -> V_11 == V_16 -> V_11 ) &&
( F_7 ( & V_15 -> V_9 , & V_16 -> V_9 ) ) &&
( F_7 ( & V_15 -> V_10 , & V_16 -> V_10 ) )
) ?
TRUE : FALSE ) ;
}
static T_6
F_8 ( T_5 V_6 )
{
const T_2 * V_7 = ( const T_2 * ) V_6 ;
T_6 V_17 ;
V_17 = 0 ;
V_17 += V_7 -> V_11 ;
return V_17 ;
}
static T_4
F_9 ( T_5 V_13 , T_5 V_14 )
{
const T_3 * V_15 = ( const T_3 * ) V_13 ;
const T_3 * V_16 = ( const T_3 * ) V_14 ;
return ( ( ( V_15 -> V_11 == V_16 -> V_11 )
&& ( F_7 ( & V_15 -> V_9 , & V_16 -> V_9 ) )
&& ( F_7 ( & V_15 -> V_10 , & V_16 -> V_10 ) )
&& ( memcmp ( & V_15 -> V_12 , & V_16 -> V_12 , sizeof ( V_18 ) ) == 0 ) )
? TRUE : FALSE ) ;
}
static T_6
F_10 ( T_5 V_6 )
{
const T_3 * V_7 = ( const T_3 * ) V_6 ;
T_6 V_17 ;
V_17 = 0 ;
V_17 += V_7 -> V_11 ;
V_17 += V_7 -> V_12 . V_19 ;
V_17 += V_7 -> V_12 . V_20 << 16 ;
V_17 += V_7 -> V_12 . V_21 ;
return V_17 ;
}
static T_4
F_11 ( T_5 V_13 , T_5 V_14 )
{
const T_7 * V_15 = ( const T_7 * ) V_13 ;
const T_7 * V_16 = ( const T_7 * ) V_14 ;
return V_15 -> V_22 == V_16 -> V_22 && V_15 -> V_11 == V_16 -> V_11 ;
}
static T_6
F_12 ( T_5 V_6 )
{
const T_7 * V_7 = ( const T_7 * ) V_6 ;
return V_7 -> V_22 ;
}
static T_8
F_13 ( T_9 T_10 V_23 , T_9 V_24 , T_9 T_11 V_23 )
{
T_1 * V_1 , * V_25 ;
for ( V_1 = V_24 ; V_1 != NULL ; V_1 = V_25 ) {
V_25 = V_1 -> V_4 ;
if( V_1 -> V_26 && ! ( V_1 -> V_27 & V_28 ) )
F_14 ( V_1 -> V_26 ) ;
F_15 ( T_1 , V_1 ) ;
}
return TRUE ;
}
static T_1 * F_16 ( const T_12 V_27 )
{
T_1 * V_1 ;
V_1 = F_17 ( T_1 ) ;
V_1 -> V_27 = V_27 ;
return V_1 ;
}
static T_8
F_18 ( T_9 T_10 V_23 , T_9 V_24 ,
T_9 T_11 V_23 )
{
T_1 * V_1 ;
for ( V_1 = V_24 ; V_1 != NULL ; V_1 = V_1 -> V_4 ) {
if( V_1 -> V_26 && ! ( V_1 -> V_27 & V_28 ) ) {
F_14 ( V_1 -> V_26 ) ;
V_1 -> V_26 = NULL ;
}
}
return TRUE ;
}
static void
F_19 ( void * V_29 )
{
T_2 * V_7 = ( T_2 * ) V_29 ;
if( V_7 ) {
F_14 ( ( T_9 ) V_7 -> V_9 . V_26 ) ;
F_14 ( ( T_9 ) V_7 -> V_10 . V_26 ) ;
F_15 ( T_2 , V_7 ) ;
}
}
static void
F_20 ( void * V_29 )
{
T_3 * V_7 = ( T_3 * ) V_29 ;
if( V_7 ) {
F_14 ( ( T_9 ) V_7 -> V_9 . V_26 ) ;
F_14 ( ( T_9 ) V_7 -> V_10 . V_26 ) ;
F_15 ( T_3 , V_7 ) ;
}
}
void
F_21 ( T_13 * * V_30 )
{
if ( * V_30 != NULL ) {
F_22 ( * V_30 ,
F_13 , NULL ) ;
} else {
* V_30 = F_23 ( F_8 ,
F_6 , F_19 , NULL ) ;
}
}
void
F_24 ( T_13 * * V_30 )
{
if ( * V_30 != NULL ) {
F_22 ( * V_30 ,
F_13 , NULL ) ;
} else {
* V_30 = F_23 ( F_10 ,
F_9 , F_20 , NULL ) ;
}
}
void
F_25 ( T_13 * * V_31 )
{
if ( * V_31 != NULL ) {
F_22 ( * V_31 ,
F_18 , NULL ) ;
} else {
* V_31 = F_26 ( F_12 ,
F_11 ) ;
}
}
unsigned char *
F_27 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 )
{
T_1 * V_1 , * V_2 ;
T_2 V_7 ;
unsigned char * V_26 = NULL ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
if( V_1 == NULL ) {
return NULL ;
}
V_26 = V_1 -> V_26 ;
for( V_2 = V_1 -> V_4 ; V_2 ; ) {
T_1 * V_25 ;
V_25 = V_2 -> V_4 ;
if( ! ( V_2 -> V_27 & V_28 ) )
F_14 ( V_2 -> V_26 ) ;
F_15 ( T_1 , V_2 ) ;
V_2 = V_25 ;
}
F_15 ( T_1 , V_1 ) ;
F_29 ( V_30 , & V_7 ) ;
return V_26 ;
}
T_1 *
F_30 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 )
{
T_1 * V_1 ;
T_2 V_7 ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
return V_1 ;
}
T_1 *
F_31 ( const T_12 V_11 , T_13 * V_31 )
{
T_1 * V_1 ;
T_7 V_7 ;
V_7 . V_22 = V_11 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_31 , & V_7 ) ;
return V_1 ;
}
T_1 *
F_32 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_31 )
{
T_1 * V_1 ;
T_7 V_7 ;
V_7 . V_22 = V_32 -> V_2 -> V_33 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_31 , & V_7 ) ;
return V_1 ;
}
void
F_33 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 ,
const T_12 V_34 )
{
T_1 * V_1 ;
T_2 V_7 ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
if( V_1 ) {
V_1 -> V_35 = V_34 ;
V_1 -> V_27 |= V_36 ;
}
return;
}
T_12
F_34 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 )
{
T_1 * V_1 ;
T_2 V_7 ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
if( V_1 ) {
return V_1 -> V_35 ;
}
return 0 ;
}
void
F_35 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 )
{
T_1 * V_1 ;
T_2 V_7 ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
if( V_1 ) {
V_1 -> V_27 |= V_37 ;
}
}
static void
F_36 ( T_13 * V_30 , T_2 * V_7 )
{
F_29 ( V_30 , V_7 ) ;
}
static void
F_37 ( T_1 * V_1 , const T_14 * V_32 ,
T_13 * V_31 , const T_12 V_11 )
{
T_7 * V_8 ;
T_1 * V_2 ;
if ( V_1 -> V_4 == NULL ) {
V_8 = F_38 ( sizeof( T_7 ) ) ;
V_8 -> V_22 = V_32 -> V_2 -> V_33 ;
V_8 -> V_11 = V_11 ;
F_39 ( V_31 , V_8 , V_1 ) ;
} else {
for ( V_2 = V_1 -> V_4 ; V_2 != NULL ; V_2 = V_2 -> V_4 ) {
V_8 = F_38 ( sizeof( T_7 ) ) ;
V_8 -> V_22 = V_2 -> V_22 ;
V_8 -> V_11 = V_11 ;
F_39 ( V_31 , V_8 ,
V_1 ) ;
}
}
V_1 -> V_27 |= V_38 ;
V_1 -> V_39 = V_32 -> V_2 -> V_33 ;
}
static T_8
F_40 ( T_1 * V_1 , T_15 * V_40 , const int V_5 ,
const T_14 * V_32 , const T_12 V_41 ,
const T_12 V_42 , const T_8 V_43 )
{
T_1 * V_2 ;
T_1 * V_3 ;
T_12 V_44 , V_45 ;
unsigned char * V_46 ;
V_2 = F_3 ( T_1 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_27 = 0 ;
V_2 -> V_22 = V_32 -> V_2 -> V_33 ;
if ( V_2 -> V_22 > V_1 -> V_22 )
V_1 -> V_22 = V_2 -> V_22 ;
V_2 -> V_5 = V_41 ;
V_2 -> V_47 = V_42 ;
V_2 -> V_26 = NULL ;
if( V_1 -> V_27 & V_38 && ( V_41 + V_42 ) >= V_1 -> V_35 &&
V_1 -> V_27 & V_37 ) {
for( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if( ! V_3 -> V_26 ) {
V_3 -> V_26 = V_1 -> V_26 + V_3 -> V_5 ;
V_3 -> V_27 |= V_28 ;
}
V_3 -> V_27 &= ( ~ V_48 ) & ( ~ V_49 ) ;
}
V_1 -> V_27 &= ~ ( V_38 | V_37 | V_36 ) ;
V_1 -> V_27 &= ( ~ V_48 ) & ( ~ V_49 ) ;
V_1 -> V_35 = 0 ;
V_1 -> V_39 = 0 ;
}
if ( ! V_43 ) {
if ( V_1 -> V_27 & V_36 ) {
if ( V_1 -> V_35 != ( V_2 -> V_5 + V_2 -> V_47 ) ) {
V_2 -> V_27 |= V_49 ;
V_1 -> V_27 |= V_49 ;
}
} else {
V_1 -> V_35 = V_2 -> V_5 + V_2 -> V_47 ;
V_1 -> V_27 |= V_36 ;
}
}
if ( V_1 -> V_27 & V_38 ) {
T_12 V_50 = V_2 -> V_5 + V_2 -> V_47 ;
V_2 -> V_27 |= V_51 ;
V_1 -> V_27 |= V_51 ;
if ( V_50 > V_1 -> V_35 || V_50 < V_2 -> V_5 || V_50 < V_2 -> V_47 ) {
V_2 -> V_27 |= V_48 ;
V_1 -> V_27 |= V_48 ;
}
else if ( memcmp ( V_1 -> V_26 + V_2 -> V_5 ,
F_41 ( V_40 , V_5 , V_2 -> V_47 ) , V_2 -> V_47 ) ) {
V_2 -> V_27 |= V_52 ;
V_1 -> V_27 |= V_52 ;
}
F_1 ( V_1 , V_2 ) ;
return TRUE ;
}
V_2 -> V_26 = F_42 ( V_2 -> V_47 ) ;
F_43 ( V_40 , V_2 -> V_26 , V_5 , V_2 -> V_47 ) ;
F_1 ( V_1 , V_2 ) ;
if( ! ( V_1 -> V_27 & V_36 ) ) {
return FALSE ;
}
V_44 = 0 ;
for ( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if ( ( ( V_3 -> V_5 ) <= V_44 ) &&
( ( V_3 -> V_5 + V_3 -> V_47 ) > V_44 ) ) {
V_44 = V_3 -> V_5 + V_3 -> V_47 ;
}
}
if ( V_44 < ( V_1 -> V_35 ) ) {
return FALSE ;
}
if ( V_44 > ( V_1 -> V_35 ) ) {
V_2 -> V_27 |= V_48 ;
V_1 -> V_27 |= V_48 ;
}
V_46 = V_1 -> V_26 ;
V_1 -> V_26 = F_42 ( V_44 ) ;
for ( V_45 = 0 , V_3 = V_1 ; V_3 ; V_3 = V_3 -> V_4 ) {
if ( V_3 -> V_47 ) {
if ( V_3 -> V_5 + V_3 -> V_47 > V_45 ) {
if ( V_3 -> V_5 + V_3 -> V_47 > V_44 )
F_44 ( L_1 ,
V_32 -> V_2 -> V_33 , V_3 -> V_5 ,
V_3 -> V_47 , V_44 ) ;
else if ( V_45 < V_3 -> V_5 )
F_44 ( L_2 ,
V_32 -> V_2 -> V_33 , V_45 , V_3 -> V_5 ) ;
else if ( V_45 - V_3 -> V_5 > V_3 -> V_47 )
F_44 ( L_3 ,
V_32 -> V_2 -> V_33 , V_45 , V_3 -> V_5 ,
V_3 -> V_47 ) ;
else if ( ! V_1 -> V_26 )
F_44 ( L_4 ,
V_32 -> V_2 -> V_33 ) ;
else {
if ( V_3 -> V_5 < V_45 ) {
V_3 -> V_27 |= V_51 ;
V_1 -> V_27 |= V_51 ;
if ( memcmp ( V_1 -> V_26 + V_3 -> V_5 ,
V_3 -> V_26 ,
F_45 ( V_3 -> V_47 , ( V_45 - V_3 -> V_5 ) )
) ) {
V_3 -> V_27 |= V_52 ;
V_1 -> V_27 |= V_52 ;
}
}
memcpy ( V_1 -> V_26 + V_45 ,
V_3 -> V_26 + ( V_45 - V_3 -> V_5 ) ,
V_3 -> V_47 - ( V_45 - V_3 -> V_5 ) ) ;
}
} else {
if ( V_3 -> V_5 + V_3 -> V_47 < V_3 -> V_5 )
F_44 ( L_5 ,
V_32 -> V_2 -> V_33 , V_3 -> V_5 ,
V_3 -> V_47 ) ;
}
if( V_3 -> V_27 & V_28 )
V_3 -> V_27 &= ~ V_28 ;
else
F_14 ( V_3 -> V_26 ) ;
V_3 -> V_26 = NULL ;
V_45 = F_46 ( V_45 , ( V_3 -> V_5 + V_3 -> V_47 ) ) ;
}
}
F_14 ( V_46 ) ;
V_1 -> V_27 |= V_38 ;
V_1 -> V_39 = V_32 -> V_2 -> V_33 ;
return TRUE ;
}
static T_1 *
F_47 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 , const T_12 V_11 ,
T_13 * V_30 , const T_12 V_41 ,
const T_12 V_42 , const T_8 V_43 ,
const T_8 V_53 )
{
T_2 V_7 , * V_8 ;
T_1 * V_1 ;
T_1 * V_54 ;
T_8 V_55 = V_32 -> V_2 -> V_27 . V_56 ;
F_48 ( F_49 ( V_40 , V_5 , V_42 ) ) ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
#if 0
if(strcmp(pinfo->current_proto, "DCERPC") == 0) {
printf("proto:%s num:%u id:%u offset:%u len:%u more:%u visited:%u\n",
pinfo->current_proto, pinfo->fd->num, id, frag_offset, frag_data_len, more_frags, pinfo->fd->flags.visited);
if(fd_head != NULL) {
for(fd_item=fd_head->next;fd_item;fd_item=fd_item->next){
printf("fd_frame:%u fd_offset:%u len:%u datalen:%u\n",
fd_item->frame, fd_item->offset, fd_item->len, fd_item->datalen);
}
}
}
#endif
if ( ! V_55 && V_53 && V_1 != NULL ) {
if ( V_32 -> V_2 -> V_33 <= V_1 -> V_22 ) {
for( V_54 = V_1 -> V_4 ; V_54 ; V_54 = V_54 -> V_4 ) {
if( V_32 -> V_2 -> V_33 == V_54 -> V_22 && V_41 == V_54 -> V_5 ) {
V_55 = TRUE ;
}
}
}
}
if ( V_55 ) {
if ( V_1 != NULL && V_1 -> V_27 & V_38 ) {
return V_1 ;
} else {
return NULL ;
}
}
if ( V_1 == NULL ) {
V_1 = F_16 ( 0 ) ;
V_8 = F_3 ( T_2 ) ;
F_4 ( & V_8 -> V_9 , & V_7 . V_9 ) ;
F_4 ( & V_8 -> V_10 , & V_7 . V_10 ) ;
V_8 -> V_11 = V_7 . V_11 ;
F_39 ( V_30 , V_8 , V_1 ) ;
}
if ( F_40 ( V_1 , V_40 , V_5 , V_32 , V_41 ,
V_42 , V_43 ) ) {
return V_1 ;
} else {
return NULL ;
}
}
T_1 *
F_50 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 , const T_12 V_11 ,
T_13 * V_30 , const T_12 V_41 ,
const T_12 V_42 , const T_8 V_43 )
{
return F_47 ( V_40 , V_5 , V_32 , V_11 , V_30 ,
V_41 , V_42 , V_43 , TRUE ) ;
}
T_1 *
F_51 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 ,
const T_12 V_11 , T_13 * V_30 ,
const T_12 V_41 , const T_12 V_42 ,
const T_8 V_43 )
{
return F_47 ( V_40 , V_5 , V_32 , V_11 , V_30 ,
V_41 , V_42 , V_43 , FALSE ) ;
}
T_1 *
F_52 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 ,
const T_12 V_11 , T_13 * V_30 ,
T_13 * V_31 , const T_12 V_41 ,
const T_12 V_42 , const T_8 V_43 )
{
T_7 V_57 ;
T_2 V_7 , * V_8 , * V_58 ;
T_9 V_59 , V_24 ;
T_1 * V_1 ;
if ( V_32 -> V_2 -> V_27 . V_56 ) {
V_57 . V_22 = V_32 -> V_2 -> V_33 ;
V_57 . V_11 = V_11 ;
return F_28 ( V_31 , & V_57 ) ;
}
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
if ( ! F_53 ( V_30 , & V_7 ,
& V_59 , & V_24 ) ) {
V_1 = F_16 ( 0 ) ;
V_8 = F_3 ( T_2 ) ;
F_4 ( & V_8 -> V_9 , & V_7 . V_9 ) ;
F_4 ( & V_8 -> V_10 , & V_7 . V_10 ) ;
V_8 -> V_11 = V_7 . V_11 ;
F_39 ( V_30 , V_8 , V_1 ) ;
V_59 = V_8 ;
} else {
V_1 = V_24 ;
}
if ( F_54 ( V_40 ) > F_55 ( V_40 ) )
return NULL ;
if ( F_40 ( V_1 , V_40 , V_5 , V_32 , V_41 ,
V_42 , V_43 ) ) {
V_58 = V_59 ;
F_36 ( V_30 , V_58 ) ;
F_37 ( V_1 , V_32 , V_31 , V_11 ) ;
return V_1 ;
} else {
return NULL ;
}
}
static void
F_56 ( T_1 * V_1 , const T_14 * V_32 )
{
T_1 * V_3 = NULL ;
T_1 * V_60 = NULL ;
T_12 V_45 = 0 , V_61 = 0 ;
void * V_46 = NULL ;
for( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if( ! V_60 || V_60 -> V_5 != V_3 -> V_5 ) {
V_61 += V_3 -> V_47 ;
}
V_60 = V_3 ;
}
V_46 = V_1 -> V_26 ;
V_1 -> V_26 = F_42 ( V_61 ) ;
V_1 -> V_47 = V_61 ;
V_60 = NULL ;
for ( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if ( V_3 -> V_47 ) {
if( ! V_60 || V_60 -> V_5 != V_3 -> V_5 ) {
memcpy ( V_1 -> V_26 + V_45 , V_3 -> V_26 , V_3 -> V_47 ) ;
V_45 += V_3 -> V_47 ;
} else {
V_3 -> V_27 |= V_51 ;
V_1 -> V_27 |= V_51 ;
if( V_60 -> V_47 != V_3 -> V_47
|| memcmp ( V_60 -> V_26 , V_3 -> V_26 , V_60 -> V_47 ) ) {
V_3 -> V_27 |= V_52 ;
V_1 -> V_27 |= V_52 ;
}
}
}
V_60 = V_3 ;
}
for ( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if( V_3 -> V_27 & V_28 )
V_3 -> V_27 &= ~ V_28 ;
else
F_14 ( V_3 -> V_26 ) ;
V_3 -> V_26 = NULL ;
}
F_14 ( V_46 ) ;
V_1 -> V_27 |= V_38 ;
V_1 -> V_39 = V_32 -> V_2 -> V_33 ;
}
static T_8
F_57 ( T_1 * V_1 , T_15 * V_40 , const int V_5 ,
const T_14 * V_32 , const T_12 V_62 ,
const T_12 V_42 , const T_8 V_43 ,
const T_12 V_27 V_23 )
{
T_1 * V_2 ;
T_1 * V_3 ;
T_1 * V_60 ;
T_12 V_44 , V_45 ;
if( V_1 -> V_27 & V_38 && V_62 >= V_1 -> V_35 &&
V_1 -> V_27 & V_37 ) {
T_12 V_63 = 0 ;
V_45 = 0 ;
for( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if( ! V_3 -> V_26 ) {
if( V_3 -> V_27 & V_51 ) {
V_3 -> V_26 = V_1 -> V_26 + V_63 ;
} else {
V_3 -> V_26 = V_1 -> V_26 + V_45 ;
V_63 = V_45 ;
V_45 += V_3 -> V_47 ;
}
V_3 -> V_27 |= V_28 ;
}
V_3 -> V_27 &= ( ~ V_48 ) & ( ~ V_49 ) ;
}
V_1 -> V_27 &= ~ ( V_38 | V_37 | V_36 ) ;
V_1 -> V_27 &= ( ~ V_48 ) & ( ~ V_49 ) ;
V_1 -> V_35 = 0 ;
V_1 -> V_39 = 0 ;
}
V_2 = F_3 ( T_1 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_27 = 0 ;
V_2 -> V_22 = V_32 -> V_2 -> V_33 ;
V_2 -> V_5 = V_62 ;
V_2 -> V_47 = V_42 ;
V_2 -> V_26 = NULL ;
if ( ! V_43 ) {
if ( V_1 -> V_27 & V_36 ) {
if ( V_1 -> V_35 != V_2 -> V_5 ) {
V_2 -> V_27 |= V_49 ;
V_1 -> V_27 |= V_49 ;
}
} else {
V_1 -> V_35 = V_2 -> V_5 ;
V_1 -> V_27 |= V_36 ;
}
}
if ( V_1 -> V_27 & V_38 ) {
V_2 -> V_27 |= V_51 ;
V_1 -> V_27 |= V_51 ;
if ( V_2 -> V_5 > V_1 -> V_35 ) {
V_2 -> V_27 |= V_48 ;
V_1 -> V_27 |= V_48 ;
F_1 ( V_1 , V_2 ) ;
return TRUE ;
}
V_45 = 0 ;
V_60 = NULL ;
for ( V_3 = V_1 -> V_4 ; V_3 && ( V_3 -> V_5 != V_2 -> V_5 ) ; V_3 = V_3 -> V_4 ) {
if ( ! V_60 || V_60 -> V_5 != V_3 -> V_5 ) {
V_45 += V_3 -> V_47 ;
}
V_60 = V_3 ;
}
if( V_3 ) {
if( V_3 -> V_47 != V_2 -> V_47 ) {
V_2 -> V_27 |= V_52 ;
V_1 -> V_27 |= V_52 ;
F_1 ( V_1 , V_2 ) ;
return TRUE ;
}
F_48 ( V_1 -> V_47 >= V_45 + V_2 -> V_47 ) ;
if ( memcmp ( V_1 -> V_26 + V_45 ,
F_41 ( V_40 , V_5 , V_2 -> V_47 ) , V_2 -> V_47 ) ) {
V_2 -> V_27 |= V_52 ;
V_1 -> V_27 |= V_52 ;
F_1 ( V_1 , V_2 ) ;
return TRUE ;
}
F_1 ( V_1 , V_2 ) ;
return TRUE ;
} else {
F_1 ( V_1 , V_2 ) ;
return TRUE ;
}
}
if ( V_2 -> V_47 ) {
V_2 -> V_26 = F_42 ( V_2 -> V_47 ) ;
F_43 ( V_40 , V_2 -> V_26 , V_5 , V_2 -> V_47 ) ;
}
F_1 ( V_1 , V_2 ) ;
if( ! ( V_1 -> V_27 & V_36 ) ) {
return FALSE ;
}
V_44 = 0 ;
for( V_3 = V_1 -> V_4 ; V_3 ; V_3 = V_3 -> V_4 ) {
if ( V_3 -> V_5 == V_44 ) {
V_44 ++ ;
}
}
if ( V_44 <= V_1 -> V_35 ) {
return FALSE ;
}
if ( V_44 > ( V_1 -> V_35 + 1 ) ) {
V_2 -> V_27 |= V_48 ;
V_1 -> V_27 |= V_48 ;
}
F_56 ( V_1 , V_32 ) ;
return TRUE ;
}
T_1 *
F_58 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 , const T_12 V_11 ,
T_13 * V_30 , const T_12 V_62 ,
const T_12 V_42 , const T_8 V_43 )
{
T_2 V_7 ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
return F_59 ( V_40 , V_5 , V_32 ,
& V_7 , F_2 ,
V_30 , V_62 ,
V_42 , V_43 , 0 ) ;
}
T_1 *
F_60 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 , const T_12 V_11 ,
void * V_64 ,
T_13 * V_30 , const T_12 V_62 ,
const T_12 V_42 , const T_8 V_43 )
{
V_18 * V_12 = ( V_18 * ) V_64 ;
T_3 V_7 ;
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_7 . V_12 = * V_12 ;
return F_59 ( V_40 , V_5 , V_32 ,
& V_7 , F_5 ,
V_30 , V_62 ,
V_42 , V_43 , 0 ) ;
}
T_1 *
F_59 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 ,
void * V_7 , T_16 V_65 ,
T_13 * V_30 , T_12 V_62 ,
const T_12 V_42 , const T_8 V_43 ,
const T_12 V_27 )
{
T_1 * V_1 ;
V_1 = F_28 ( V_30 , V_7 ) ;
if ( V_32 -> V_2 -> V_27 . V_56 ) {
if ( V_1 != NULL && V_1 -> V_27 & V_38 ) {
return V_1 ;
} else {
return NULL ;
}
}
if ( V_1 == NULL ) {
V_1 = F_16 ( V_66 ) ;
if( ( V_27 & ( V_67 | V_68 ) )
&& ! V_43 ) {
V_1 -> V_39 = V_32 -> V_2 -> V_33 ;
return V_1 ;
}
if( V_65 != NULL )
V_7 = V_65 ( V_7 ) ;
F_39 ( V_30 , V_7 , V_1 ) ;
if ( V_27 & V_67 )
V_62 = 0 ;
} else {
if ( V_27 & V_67 ) {
T_1 * V_2 ;
for ( V_2 = V_1 ; V_2 != NULL ; V_2 = V_2 -> V_4 ) {
if ( V_2 -> V_4 == NULL )
V_62 = V_2 -> V_5 + 1 ;
}
}
}
if ( ( V_27 & V_69 ) &&
! F_49 ( V_40 , V_5 , V_42 ) ) {
if ( ! V_43 ) {
T_9 V_59 ;
if ( F_53 ( V_30 , V_7 ,
& V_59 , NULL ) ) {
F_36 ( V_30 , ( T_2 * ) V_59 ) ;
}
}
V_1 -> V_27 |= V_70 ;
return V_62 == 0 ? V_1 : NULL ;
}
if ( F_57 ( V_1 , V_40 , V_5 , V_32 ,
V_62 , V_42 , V_43 , V_27 ) ) {
return V_1 ;
} else {
return NULL ;
}
}
static T_1 *
F_61 ( T_15 * V_40 , const int V_5 ,
const T_14 * V_32 , const T_12 V_11 ,
T_13 * V_30 ,
T_13 * V_31 ,
const T_12 V_62 ,
const T_12 V_42 ,
const T_8 V_43 , const T_12 V_27 )
{
T_7 V_57 ;
T_2 V_7 ;
T_1 * V_1 ;
if ( V_32 -> V_2 -> V_27 . V_56 ) {
V_57 . V_22 = V_32 -> V_2 -> V_33 ;
V_57 . V_11 = V_11 ;
return F_28 ( V_31 , & V_57 ) ;
}
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_59 ( V_40 , V_5 , V_32 ,
& V_7 , F_2 ,
V_30 , V_62 ,
V_42 , V_43 , V_27 | V_69 ) ;
if ( V_1 ) {
T_9 V_59 ;
if( V_1 -> V_27 & V_70 ) {
return V_1 ;
}
if ( F_53 ( V_30 , & V_7 ,
& V_59 , NULL ) ) {
F_36 ( V_30 , ( T_2 * ) V_59 ) ;
}
F_37 ( V_1 , V_32 , V_31 , V_11 ) ;
return V_1 ;
} else {
return NULL ;
}
}
T_1 *
F_62 ( T_15 * V_40 , const int V_5 ,
const T_14 * V_32 , const T_12 V_11 ,
T_13 * V_30 ,
T_13 * V_31 , const T_12 V_62 ,
const T_12 V_42 , const T_8 V_43 )
{
return F_61 ( V_40 , V_5 , V_32 , V_11 ,
V_30 , V_31 ,
V_62 , V_42 ,
V_43 , 0 ) ;
}
T_1 *
F_63 ( T_15 * V_40 , const int V_5 ,
const T_14 * V_32 , const T_12 V_11 ,
T_13 * V_30 ,
T_13 * V_31 ,
const T_12 V_62 , const T_12 V_42 ,
const T_8 V_43 )
{
return F_61 ( V_40 , V_5 , V_32 , V_11 ,
V_30 , V_31 ,
V_62 , V_42 ,
V_43 ,
V_68 ) ;
}
T_1 *
F_64 ( T_15 * V_40 , const int V_5 , const T_14 * V_32 ,
const T_12 V_11 , T_13 * V_30 ,
T_13 * V_31 , const T_12 V_42 ,
const T_8 V_43 )
{
return F_61 ( V_40 , V_5 , V_32 , V_11 ,
V_30 , V_31 , 0 ,
V_42 , V_43 ,
V_67 ) ;
}
void
F_65 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 ,
const T_12 V_34 )
{
T_2 V_7 , * V_8 ;
T_1 * V_1 ;
if ( V_32 -> V_2 -> V_27 . V_56 ) {
return;
}
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
if ( V_1 == NULL ) {
V_1 = F_3 ( T_1 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_35 = V_34 ;
V_1 -> V_5 = 0 ;
V_1 -> V_47 = 0 ;
V_1 -> V_27 = V_66 | V_36 ;
V_1 -> V_26 = NULL ;
V_1 -> V_39 = 0 ;
V_8 = F_2 ( & V_7 ) ;
F_39 ( V_30 , V_8 , V_1 ) ;
}
}
T_1 *
F_66 ( const T_14 * V_32 , const T_12 V_11 , T_13 * V_30 ,
T_13 * V_31 )
{
T_7 V_57 ;
T_7 * V_8 ;
T_2 V_7 ;
T_1 * V_1 ;
if ( V_32 -> V_2 -> V_27 . V_56 ) {
V_57 . V_22 = V_32 -> V_2 -> V_33 ;
V_57 . V_11 = V_11 ;
return F_28 ( V_31 , & V_57 ) ;
}
V_7 . V_9 = V_32 -> V_9 ;
V_7 . V_10 = V_32 -> V_10 ;
V_7 . V_11 = V_11 ;
V_1 = F_28 ( V_30 , & V_7 ) ;
if ( V_1 ) {
T_9 V_59 ;
if ( V_1 -> V_27 & V_70 ) {
return NULL ;
}
V_1 -> V_35 = V_1 -> V_5 ;
V_1 -> V_27 |= V_36 ;
F_56 ( V_1 , V_32 ) ;
if ( F_53 ( V_30 , & V_7 ,
& V_59 , NULL ) ) {
F_36 ( V_30 , ( T_2 * ) V_59 ) ;
}
F_37 ( V_1 , V_32 , V_31 , V_11 ) ;
if ( V_1 -> V_4 != NULL ) {
V_8 = F_38 ( sizeof( T_7 ) ) ;
V_8 -> V_22 = V_32 -> V_2 -> V_33 ;
V_8 -> V_11 = V_11 ;
F_39 ( V_31 , V_8 , V_1 ) ;
}
return V_1 ;
} else {
return NULL ;
}
}
T_15 *
F_67 ( T_15 * V_40 , const int V_5 , T_14 * V_32 ,
const char * V_71 , T_1 * V_1 , const T_17 * V_72 ,
T_8 * V_73 , T_18 * V_74 )
{
T_15 * V_75 ;
T_8 V_76 ;
T_19 * V_77 ;
if ( V_1 != NULL && V_32 -> V_2 -> V_33 == V_1 -> V_39 ) {
if ( V_1 -> V_4 != NULL ) {
if ( V_1 -> V_27 & V_66 ) {
V_75 = F_68 ( V_1 -> V_26 ,
V_1 -> V_47 , V_1 -> V_47 ) ;
} else {
V_75 = F_68 ( V_1 -> V_26 ,
V_1 -> V_35 , V_1 -> V_35 ) ;
}
F_69 ( V_40 , V_75 ) ;
F_70 ( V_32 , V_75 , V_71 ) ;
if ( V_1 -> V_27 & V_66 ) {
V_76 = ! F_71 (
V_1 , V_72 , V_74 , V_32 , V_75 , & V_77 ) ;
} else {
V_76 = ! F_72 ( V_1 ,
V_72 , V_74 , V_32 , V_75 , & V_77 ) ;
}
} else {
V_75 = F_73 ( V_40 , V_5 ) ;
V_32 -> V_78 = FALSE ;
V_76 = TRUE ;
}
if ( V_73 != NULL )
* V_73 = V_76 ;
} else {
V_75 = NULL ;
if ( V_1 != NULL && V_72 -> V_79 != NULL ) {
F_74 ( V_74 ,
* ( V_72 -> V_79 ) , V_40 ,
0 , 0 , V_1 -> V_39 ) ;
}
}
return V_75 ;
}
static void
F_75 ( T_1 * V_2 , const int V_5 , const T_17 * V_72 ,
T_18 * V_80 , T_19 * V_81 , const T_8 V_82 ,
const T_12 V_83 , T_15 * V_40 , T_14 * V_32 )
{
T_19 * V_84 = NULL ;
int V_85 ;
if ( V_82 ) {
T_20 * V_71 ;
if ( V_83 == 1 ) {
V_71 = F_76 ( F_77 ( * ( V_72 -> V_86 ) ) ) ;
} else {
V_71 = F_76 ( F_77 ( * ( V_72 -> V_87 ) ) ) ;
}
F_78 ( V_81 , L_6 , V_83 , V_71 , F_55 ( V_40 ) ,
F_79 ( F_55 ( V_40 ) , L_7 , L_8 ) ) ;
F_14 ( V_71 ) ;
} else {
F_80 ( V_81 , L_9 ) ;
}
F_80 ( V_81 , L_10 , V_2 -> V_22 , V_2 -> V_47 ) ;
if ( V_2 -> V_27 & ( V_52
| V_49 | V_48 ) ) {
V_85 = * ( V_72 -> V_88 ) ;
} else {
V_85 = * ( V_72 -> V_86 ) ;
}
if ( V_2 -> V_47 == 0 ) {
V_84 = F_81 ( V_80 , V_85 ,
V_40 , V_5 , V_2 -> V_47 ,
V_2 -> V_22 ,
L_11 ,
V_2 -> V_22 ) ;
} else {
V_84 = F_81 ( V_80 , V_85 ,
V_40 , V_5 , V_2 -> V_47 ,
V_2 -> V_22 ,
L_12 ,
V_2 -> V_22 ,
V_5 ,
V_5 + V_2 -> V_47 - 1 ,
V_2 -> V_47 ,
F_79 ( V_2 -> V_47 , L_7 , L_8 ) ) ;
}
F_82 ( V_84 ) ;
F_83 ( V_32 , V_2 -> V_22 ) ;
if ( V_2 -> V_27 & ( V_51 | V_52
| V_49 | V_48 ) ) {
T_18 * V_89 = NULL ;
V_89 = F_84 ( V_84 , * ( V_72 -> V_90 ) ) ;
if ( V_2 -> V_27 & V_51 ) {
V_84 = F_85 ( V_89 ,
* ( V_72 -> V_91 ) ,
V_40 , 0 , 0 ,
TRUE ) ;
F_82 ( V_84 ) ;
}
if ( V_2 -> V_27 & V_52 ) {
V_84 = F_85 ( V_89 ,
* ( V_72 -> V_92 ) ,
V_40 , 0 , 0 ,
TRUE ) ;
F_82 ( V_84 ) ;
}
if ( V_2 -> V_27 & V_49 ) {
V_84 = F_85 ( V_89 ,
* ( V_72 -> V_93 ) ,
V_40 , 0 , 0 ,
TRUE ) ;
F_82 ( V_84 ) ;
}
if ( V_2 -> V_27 & V_48 ) {
V_84 = F_85 ( V_89 ,
* ( V_72 -> V_94 ) ,
V_40 , 0 , 0 ,
TRUE ) ;
F_82 ( V_84 ) ;
}
}
}
static T_8
F_86 ( T_1 * V_1 , const T_17 * V_72 ,
T_14 * V_32 )
{
if ( V_1 -> V_27 & ( V_52
| V_49 | V_48 ) ) {
if ( F_87 ( V_32 -> V_95 , V_96 ) ) {
F_88 ( V_32 -> V_95 , V_96 ,
L_13 , V_72 -> V_97 ) ;
return TRUE ;
}
}
return FALSE ;
}
T_8
F_72 ( T_1 * V_1 , const T_17 * V_72 ,
T_18 * V_74 , T_14 * V_32 , T_15 * V_40 , T_19 * * V_81 )
{
T_1 * V_2 ;
T_18 * V_80 ;
T_8 V_82 ;
T_12 V_83 = 0 ;
V_32 -> V_78 = FALSE ;
* V_81 = F_89 ( V_74 , * ( V_72 -> V_87 ) , V_40 , 0 , - 1 , V_98 ) ;
F_82 ( * V_81 ) ;
V_80 = F_84 ( * V_81 , * ( V_72 -> V_99 ) ) ;
V_82 = TRUE ;
for ( V_2 = V_1 -> V_4 ; V_2 != NULL ; V_2 = V_2 -> V_4 ) {
V_83 ++ ;
}
for ( V_2 = V_1 -> V_4 ; V_2 != NULL ; V_2 = V_2 -> V_4 ) {
F_75 ( V_2 , V_2 -> V_5 , V_72 , V_80 , * V_81 , V_82 , V_83 , V_40 , V_32 ) ;
V_82 = FALSE ;
}
if ( V_72 -> V_100 ) {
T_19 * V_101 = F_74 ( V_80 , * ( V_72 -> V_100 ) ,
V_40 , 0 , 0 , V_83 ) ;
F_82 ( V_101 ) ;
}
if ( V_72 -> V_102 ) {
T_19 * V_101 = F_74 ( V_80 , * ( V_72 -> V_102 ) ,
V_40 , 0 , 0 , F_55 ( V_40 ) ) ;
F_82 ( V_101 ) ;
}
return F_86 ( V_1 , V_72 , V_32 ) ;
}
T_8
F_71 ( T_1 * V_1 , const T_17 * V_72 ,
T_18 * V_74 , T_14 * V_32 , T_15 * V_40 , T_19 * * V_81 )
{
T_12 V_5 , V_103 , V_83 = 0 ;
T_1 * V_2 , * V_60 ;
T_18 * V_80 ;
T_8 V_82 ;
V_32 -> V_78 = FALSE ;
* V_81 = F_89 ( V_74 , * ( V_72 -> V_87 ) , V_40 , 0 , - 1 , V_98 ) ;
F_82 ( * V_81 ) ;
V_80 = F_84 ( * V_81 , * ( V_72 -> V_99 ) ) ;
V_5 = 0 ;
V_103 = 0 ;
V_60 = NULL ;
V_82 = TRUE ;
for ( V_2 = V_1 -> V_4 ; V_2 != NULL ; V_2 = V_2 -> V_4 ) {
V_83 ++ ;
}
for ( V_2 = V_1 -> V_4 ; V_2 != NULL ; V_2 = V_2 -> V_4 ) {
if ( V_60 == NULL || V_60 -> V_5 != V_2 -> V_5 ) {
V_5 = V_103 ;
V_103 += V_2 -> V_47 ;
}
V_60 = V_2 ;
F_75 ( V_2 , V_5 , V_72 , V_80 , * V_81 , V_82 , V_83 , V_40 , V_32 ) ;
V_82 = FALSE ;
}
if ( V_72 -> V_100 ) {
T_19 * V_101 = F_74 ( V_80 , * ( V_72 -> V_100 ) ,
V_40 , 0 , 0 , V_83 ) ;
F_82 ( V_101 ) ;
}
if ( V_72 -> V_102 ) {
T_19 * V_101 = F_74 ( V_80 , * ( V_72 -> V_102 ) ,
V_40 , 0 , 0 , F_55 ( V_40 ) ) ;
F_82 ( V_101 ) ;
}
return F_86 ( V_1 , V_72 , V_32 ) ;
}
