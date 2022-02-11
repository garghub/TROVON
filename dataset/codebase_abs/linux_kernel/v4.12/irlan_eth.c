static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
V_2 -> V_3 = & V_4 ;
V_2 -> V_5 = true ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 4 ;
}
struct V_1 * F_3 ( const char * V_10 )
{
return F_4 ( sizeof( struct V_11 ) , V_10 , V_12 ,
F_1 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_13 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
V_13 -> V_14 = 0 ;
F_8 ( V_13 , V_13 -> V_15 , V_13 -> V_16 ) ;
return F_9 ( V_13 -> V_17 ,
! V_13 -> V_18 -> V_19 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_13 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_11 ( V_13 ) ;
F_12 ( V_13 ) ;
F_13 ( V_13 , V_20 , NULL ) ;
F_14 ( V_13 , V_20 , NULL ) ;
F_15 ( & V_13 -> V_21 . V_22 ) ;
V_13 -> V_21 . V_23 = 0 ;
return 0 ;
}
static T_1 F_16 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_11 * V_13 = F_6 ( V_2 ) ;
int V_26 ;
unsigned int V_27 ;
if ( ( F_17 ( V_25 ) < V_13 -> V_28 ) || ( F_18 ( V_25 ) ) ) {
struct V_24 * V_29 =
F_19 ( V_25 , V_13 -> V_28 ) ;
F_20 ( V_25 ) ;
if ( V_29 == NULL )
return V_30 ;
V_25 = V_29 ;
}
F_21 ( V_2 ) ;
V_27 = V_25 -> V_27 ;
if ( V_13 -> V_31 )
V_26 = F_22 ( V_13 -> V_18 , V_25 ) ;
else
V_26 = F_23 ( V_13 -> V_18 , V_25 ) ;
if ( V_26 < 0 ) {
V_2 -> V_32 . V_33 ++ ;
} else {
V_2 -> V_32 . V_34 ++ ;
V_2 -> V_32 . V_35 += V_27 ;
}
return V_30 ;
}
int F_24 ( void * V_36 , void * V_37 , struct V_24 * V_25 )
{
struct V_11 * V_13 = V_36 ;
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_25 == NULL ) {
V_2 -> V_32 . V_38 ++ ;
return 0 ;
}
if ( V_25 -> V_27 < V_39 ) {
F_25 ( L_1 ,
V_40 , V_25 -> V_27 ) ;
V_2 -> V_32 . V_38 ++ ;
F_20 ( V_25 ) ;
return 0 ;
}
V_25 -> V_41 = F_26 ( V_25 , V_2 ) ;
V_2 -> V_32 . V_42 ++ ;
V_2 -> V_32 . V_43 += V_25 -> V_27 ;
F_27 ( V_25 ) ;
return 0 ;
}
void F_28 ( void * V_36 , void * V_37 , T_2 V_44 )
{
struct V_11 * V_13 ;
struct V_1 * V_2 ;
V_13 = V_36 ;
F_29 (self != NULL, return;) ;
F_29 (self->magic == IRLAN_MAGIC, return;) ;
V_2 = V_13 -> V_2 ;
F_29 (dev != NULL, return;) ;
F_25 ( L_2 , V_40 ,
V_44 == V_45 ? L_3 : L_4 ,
F_30 ( V_2 ) ) ;
switch ( V_44 ) {
case V_45 :
F_7 ( V_2 ) ;
break;
case V_46 :
default:
F_31 ( V_2 ) ;
break;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_13 = F_6 ( V_2 ) ;
if ( V_13 -> V_21 . V_47 != V_48 ) {
F_25 ( L_5 , V_40 ) ;
return;
}
if ( V_2 -> V_49 & V_50 ) {
F_33 ( L_6 ) ;
} else if ( ( V_2 -> V_49 & V_51 ) ||
F_34 ( V_2 ) > V_52 ) {
F_25 ( L_7 , V_40 ) ;
F_35 ( V_13 , TRUE ) ;
} else if ( ! F_36 ( V_2 ) ) {
F_25 ( L_7 , V_40 ) ;
F_35 ( V_13 , TRUE ) ;
} else {
F_25 ( L_8 , V_40 ) ;
F_35 ( V_13 , FALSE ) ;
}
if ( V_2 -> V_49 & V_53 )
F_37 ( V_13 , TRUE ) ;
else
F_37 ( V_13 , FALSE ) ;
}
