static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
V_2 -> V_3 = & V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 4 ;
}
struct V_1 * F_3 ( const char * V_8 )
{
return F_4 ( sizeof( struct V_9 ) , V_8 ,
F_1 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
F_7 ( 2 , L_1 , V_11 ) ;
F_8 ( V_2 ) ;
V_10 -> V_12 = 0 ;
F_9 ( V_10 , V_10 -> V_13 , V_10 -> V_14 ) ;
return F_10 ( V_10 -> V_15 ,
! V_10 -> V_16 -> V_17 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
F_7 ( 2 , L_1 , V_11 ) ;
F_8 ( V_2 ) ;
F_12 ( V_10 ) ;
F_13 ( V_10 ) ;
F_14 ( V_10 , V_18 , NULL ) ;
F_15 ( V_10 , V_18 , NULL ) ;
F_16 ( & V_10 -> V_19 . V_20 ) ;
V_10 -> V_19 . V_21 = 0 ;
return 0 ;
}
static T_1 F_17 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
int V_24 ;
unsigned int V_25 ;
if ( ( F_18 ( V_23 ) < V_10 -> V_26 ) || ( F_19 ( V_23 ) ) ) {
struct V_22 * V_27 =
F_20 ( V_23 , V_10 -> V_26 ) ;
F_21 ( V_23 ) ;
if ( V_27 == NULL )
return V_28 ;
V_23 = V_27 ;
}
V_2 -> V_29 = V_30 ;
V_25 = V_23 -> V_25 ;
if ( V_10 -> V_31 )
V_24 = F_22 ( V_10 -> V_16 , V_23 ) ;
else
V_24 = F_23 ( V_10 -> V_16 , V_23 ) ;
if ( V_24 < 0 ) {
V_2 -> V_32 . V_33 ++ ;
} else {
V_2 -> V_32 . V_34 ++ ;
V_2 -> V_32 . V_35 += V_25 ;
}
return V_28 ;
}
int F_24 ( void * V_36 , void * V_37 , struct V_22 * V_23 )
{
struct V_9 * V_10 = V_36 ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_23 == NULL ) {
V_2 -> V_32 . V_38 ++ ;
return 0 ;
}
if ( V_23 -> V_25 < V_39 ) {
F_7 ( 0 , L_2 ,
V_11 , V_23 -> V_25 ) ;
V_2 -> V_32 . V_38 ++ ;
F_21 ( V_23 ) ;
return 0 ;
}
V_23 -> V_40 = F_25 ( V_23 , V_2 ) ;
V_2 -> V_32 . V_41 ++ ;
V_2 -> V_32 . V_42 += V_23 -> V_25 ;
F_26 ( V_23 ) ;
return 0 ;
}
void F_27 ( void * V_36 , void * V_37 , T_2 V_43 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = (struct V_9 * ) V_36 ;
F_28 (self != NULL, return;) ;
F_28 (self->magic == IRLAN_MAGIC, return;) ;
V_2 = V_10 -> V_2 ;
F_28 (dev != NULL, return;) ;
F_7 ( 0 , L_3 , V_11 ,
V_43 == V_44 ? L_4 : L_5 ,
F_29 ( V_2 ) ) ;
switch ( V_43 ) {
case V_44 :
F_8 ( V_2 ) ;
break;
case V_45 :
default:
F_30 ( V_2 ) ;
break;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_6 ( V_2 ) ;
F_7 ( 2 , L_1 , V_11 ) ;
if ( V_10 -> V_19 . V_46 != V_47 ) {
F_7 ( 1 , L_6 , V_11 ) ;
return;
}
if ( V_2 -> V_48 & V_49 ) {
F_32 ( L_7 ) ;
}
else if ( ( V_2 -> V_48 & V_50 ) ||
F_33 ( V_2 ) > V_51 ) {
F_7 ( 4 , L_8 , V_11 ) ;
F_34 ( V_10 , TRUE ) ;
}
else if ( ! F_35 ( V_2 ) ) {
F_7 ( 4 , L_8 , V_11 ) ;
F_34 ( V_10 , TRUE ) ;
}
else {
F_7 ( 4 , L_9 , V_11 ) ;
F_34 ( V_10 , FALSE ) ;
}
if ( V_2 -> V_48 & V_52 )
F_36 ( V_10 , TRUE ) ;
else
F_36 ( V_10 , FALSE ) ;
}
