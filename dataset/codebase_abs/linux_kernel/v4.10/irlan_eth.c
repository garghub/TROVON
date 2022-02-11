static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
V_2 -> V_3 = & V_4 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = 4 ;
}
struct V_1 * F_3 ( const char * V_11 )
{
return F_4 ( sizeof( struct V_12 ) , V_11 , V_13 ,
F_1 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_12 * V_14 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
V_14 -> V_15 = 0 ;
F_8 ( V_14 , V_14 -> V_16 , V_14 -> V_17 ) ;
return F_9 ( V_14 -> V_18 ,
! V_14 -> V_19 -> V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_12 * V_14 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_11 ( V_14 ) ;
F_12 ( V_14 ) ;
F_13 ( V_14 , V_21 , NULL ) ;
F_14 ( V_14 , V_21 , NULL ) ;
F_15 ( & V_14 -> V_22 . V_23 ) ;
V_14 -> V_22 . V_24 = 0 ;
return 0 ;
}
static T_1 F_16 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_12 * V_14 = F_6 ( V_2 ) ;
int V_27 ;
unsigned int V_28 ;
if ( ( F_17 ( V_26 ) < V_14 -> V_29 ) || ( F_18 ( V_26 ) ) ) {
struct V_25 * V_30 =
F_19 ( V_26 , V_14 -> V_29 ) ;
F_20 ( V_26 ) ;
if ( V_30 == NULL )
return V_31 ;
V_26 = V_30 ;
}
F_21 ( V_2 ) ;
V_28 = V_26 -> V_28 ;
if ( V_14 -> V_32 )
V_27 = F_22 ( V_14 -> V_19 , V_26 ) ;
else
V_27 = F_23 ( V_14 -> V_19 , V_26 ) ;
if ( V_27 < 0 ) {
V_2 -> V_33 . V_34 ++ ;
} else {
V_2 -> V_33 . V_35 ++ ;
V_2 -> V_33 . V_36 += V_28 ;
}
return V_31 ;
}
int F_24 ( void * V_37 , void * V_38 , struct V_25 * V_26 )
{
struct V_12 * V_14 = V_37 ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_26 == NULL ) {
V_2 -> V_33 . V_39 ++ ;
return 0 ;
}
if ( V_26 -> V_28 < V_40 ) {
F_25 ( L_1 ,
V_41 , V_26 -> V_28 ) ;
V_2 -> V_33 . V_39 ++ ;
F_20 ( V_26 ) ;
return 0 ;
}
V_26 -> V_42 = F_26 ( V_26 , V_2 ) ;
V_2 -> V_33 . V_43 ++ ;
V_2 -> V_33 . V_44 += V_26 -> V_28 ;
F_27 ( V_26 ) ;
return 0 ;
}
void F_28 ( void * V_37 , void * V_38 , T_2 V_45 )
{
struct V_12 * V_14 ;
struct V_1 * V_2 ;
V_14 = V_37 ;
F_29 (self != NULL, return;) ;
F_29 (self->magic == IRLAN_MAGIC, return;) ;
V_2 = V_14 -> V_2 ;
F_29 (dev != NULL, return;) ;
F_25 ( L_2 , V_41 ,
V_45 == V_46 ? L_3 : L_4 ,
F_30 ( V_2 ) ) ;
switch ( V_45 ) {
case V_46 :
F_7 ( V_2 ) ;
break;
case V_47 :
default:
F_31 ( V_2 ) ;
break;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_14 = F_6 ( V_2 ) ;
if ( V_14 -> V_22 . V_48 != V_49 ) {
F_25 ( L_5 , V_41 ) ;
return;
}
if ( V_2 -> V_50 & V_51 ) {
F_33 ( L_6 ) ;
} else if ( ( V_2 -> V_50 & V_52 ) ||
F_34 ( V_2 ) > V_53 ) {
F_25 ( L_7 , V_41 ) ;
F_35 ( V_14 , TRUE ) ;
} else if ( ! F_36 ( V_2 ) ) {
F_25 ( L_7 , V_41 ) ;
F_35 ( V_14 , TRUE ) ;
} else {
F_25 ( L_8 , V_41 ) ;
F_35 ( V_14 , FALSE ) ;
}
if ( V_2 -> V_50 & V_54 )
F_37 ( V_14 , TRUE ) ;
else
F_37 ( V_14 , FALSE ) ;
}
