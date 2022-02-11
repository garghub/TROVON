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
F_21 ( V_2 ) ;
V_25 = V_23 -> V_25 ;
if ( V_11 -> V_29 )
V_24 = F_22 ( V_11 -> V_16 , V_23 ) ;
else
V_24 = F_23 ( V_11 -> V_16 , V_23 ) ;
if ( V_24 < 0 ) {
V_2 -> V_30 . V_31 ++ ;
} else {
V_2 -> V_30 . V_32 ++ ;
V_2 -> V_30 . V_33 += V_25 ;
}
return V_28 ;
}
int F_24 ( void * V_34 , void * V_35 , struct V_22 * V_23 )
{
struct V_9 * V_11 = V_34 ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( V_23 == NULL ) {
V_2 -> V_30 . V_36 ++ ;
return 0 ;
}
if ( V_23 -> V_25 < V_37 ) {
F_25 ( L_1 ,
V_38 , V_23 -> V_25 ) ;
V_2 -> V_30 . V_36 ++ ;
F_20 ( V_23 ) ;
return 0 ;
}
V_23 -> V_39 = F_26 ( V_23 , V_2 ) ;
V_2 -> V_30 . V_40 ++ ;
V_2 -> V_30 . V_41 += V_23 -> V_25 ;
F_27 ( V_23 ) ;
return 0 ;
}
void F_28 ( void * V_34 , void * V_35 , T_2 V_42 )
{
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = V_34 ;
F_29 (self != NULL, return;) ;
F_29 (self->magic == IRLAN_MAGIC, return;) ;
V_2 = V_11 -> V_2 ;
F_29 (dev != NULL, return;) ;
F_25 ( L_2 , V_38 ,
V_42 == V_43 ? L_3 : L_4 ,
F_30 ( V_2 ) ) ;
switch ( V_42 ) {
case V_43 :
F_7 ( V_2 ) ;
break;
case V_44 :
default:
F_31 ( V_2 ) ;
break;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
if ( V_11 -> V_19 . V_45 != V_46 ) {
F_25 ( L_5 , V_38 ) ;
return;
}
if ( V_2 -> V_47 & V_48 ) {
F_33 ( L_6 ) ;
} else if ( ( V_2 -> V_47 & V_49 ) ||
F_34 ( V_2 ) > V_50 ) {
F_25 ( L_7 , V_38 ) ;
F_35 ( V_11 , TRUE ) ;
} else if ( ! F_36 ( V_2 ) ) {
F_25 ( L_7 , V_38 ) ;
F_35 ( V_11 , TRUE ) ;
} else {
F_25 ( L_8 , V_38 ) ;
F_35 ( V_11 , FALSE ) ;
}
if ( V_2 -> V_47 & V_51 )
F_37 ( V_11 , TRUE ) ;
else
F_37 ( V_11 , FALSE ) ;
}
