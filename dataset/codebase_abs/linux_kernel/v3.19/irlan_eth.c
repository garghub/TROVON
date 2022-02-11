static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
V_2 -> V_3 = & V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 4 ;
}
struct V_1 * F_3 ( const char * V_8 )
{
return F_4 ( sizeof( struct V_9 ) , V_8 , V_10 ,
F_1 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
V_11 -> V_12 = 0 ;
F_8 ( V_11 , V_11 -> V_13 , V_11 -> V_14 ) ;
return F_9 ( V_11 -> V_15 ,
! V_11 -> V_16 -> V_17 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
F_13 ( V_11 , V_18 , NULL ) ;
F_14 ( V_11 , V_18 , NULL ) ;
F_15 ( & V_11 -> V_19 . V_20 ) ;
V_11 -> V_19 . V_21 = 0 ;
return 0 ;
}
static T_1 F_16 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
int V_24 ;
unsigned int V_25 ;
if ( ( F_17 ( V_23 ) < V_11 -> V_26 ) || ( F_18 ( V_23 ) ) ) {
struct V_22 * V_27 =
F_19 ( V_23 , V_11 -> V_26 ) ;
F_20 ( V_23 ) ;
if ( V_27 == NULL )
return V_28 ;
V_23 = V_27 ;
}
V_2 -> V_29 = V_30 ;
V_25 = V_23 -> V_25 ;
if ( V_11 -> V_31 )
V_24 = F_21 ( V_11 -> V_16 , V_23 ) ;
else
V_24 = F_22 ( V_11 -> V_16 , V_23 ) ;
if ( V_24 < 0 ) {
V_2 -> V_32 . V_33 ++ ;
} else {
V_2 -> V_32 . V_34 ++ ;
V_2 -> V_32 . V_35 += V_25 ;
}
return V_28 ;
}
int F_23 ( void * V_36 , void * V_37 , struct V_22 * V_23 )
{
struct V_9 * V_11 = V_36 ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( V_23 == NULL ) {
V_2 -> V_32 . V_38 ++ ;
return 0 ;
}
if ( V_23 -> V_25 < V_39 ) {
F_24 ( L_1 ,
V_40 , V_23 -> V_25 ) ;
V_2 -> V_32 . V_38 ++ ;
F_20 ( V_23 ) ;
return 0 ;
}
V_23 -> V_41 = F_25 ( V_23 , V_2 ) ;
V_2 -> V_32 . V_42 ++ ;
V_2 -> V_32 . V_43 += V_23 -> V_25 ;
F_26 ( V_23 ) ;
return 0 ;
}
void F_27 ( void * V_36 , void * V_37 , T_2 V_44 )
{
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = V_36 ;
F_28 (self != NULL, return;) ;
F_28 (self->magic == IRLAN_MAGIC, return;) ;
V_2 = V_11 -> V_2 ;
F_28 (dev != NULL, return;) ;
F_24 ( L_2 , V_40 ,
V_44 == V_45 ? L_3 : L_4 ,
F_29 ( V_2 ) ) ;
switch ( V_44 ) {
case V_45 :
F_7 ( V_2 ) ;
break;
case V_46 :
default:
F_30 ( V_2 ) ;
break;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
if ( V_11 -> V_19 . V_47 != V_48 ) {
F_24 ( L_5 , V_40 ) ;
return;
}
if ( V_2 -> V_49 & V_50 ) {
F_32 ( L_6 ) ;
} else if ( ( V_2 -> V_49 & V_51 ) ||
F_33 ( V_2 ) > V_52 ) {
F_24 ( L_7 , V_40 ) ;
F_34 ( V_11 , TRUE ) ;
} else if ( ! F_35 ( V_2 ) ) {
F_24 ( L_7 , V_40 ) ;
F_34 ( V_11 , TRUE ) ;
} else {
F_24 ( L_8 , V_40 ) ;
F_34 ( V_11 , FALSE ) ;
}
if ( V_2 -> V_49 & V_53 )
F_36 ( V_11 , TRUE ) ;
else
F_36 ( V_11 , FALSE ) ;
}
