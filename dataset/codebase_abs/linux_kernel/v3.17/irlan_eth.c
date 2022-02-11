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
F_7 ( 2 , L_1 , V_12 ) ;
F_8 ( V_2 ) ;
V_11 -> V_13 = 0 ;
F_9 ( V_11 , V_11 -> V_14 , V_11 -> V_15 ) ;
return F_10 ( V_11 -> V_16 ,
! V_11 -> V_17 -> V_18 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
F_7 ( 2 , L_1 , V_12 ) ;
F_8 ( V_2 ) ;
F_12 ( V_11 ) ;
F_13 ( V_11 ) ;
F_14 ( V_11 , V_19 , NULL ) ;
F_15 ( V_11 , V_19 , NULL ) ;
F_16 ( & V_11 -> V_20 . V_21 ) ;
V_11 -> V_20 . V_22 = 0 ;
return 0 ;
}
static T_1 F_17 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_9 * V_11 = F_6 ( V_2 ) ;
int V_25 ;
unsigned int V_26 ;
if ( ( F_18 ( V_24 ) < V_11 -> V_27 ) || ( F_19 ( V_24 ) ) ) {
struct V_23 * V_28 =
F_20 ( V_24 , V_11 -> V_27 ) ;
F_21 ( V_24 ) ;
if ( V_28 == NULL )
return V_29 ;
V_24 = V_28 ;
}
V_2 -> V_30 = V_31 ;
V_26 = V_24 -> V_26 ;
if ( V_11 -> V_32 )
V_25 = F_22 ( V_11 -> V_17 , V_24 ) ;
else
V_25 = F_23 ( V_11 -> V_17 , V_24 ) ;
if ( V_25 < 0 ) {
V_2 -> V_33 . V_34 ++ ;
} else {
V_2 -> V_33 . V_35 ++ ;
V_2 -> V_33 . V_36 += V_26 ;
}
return V_29 ;
}
int F_24 ( void * V_37 , void * V_38 , struct V_23 * V_24 )
{
struct V_9 * V_11 = V_37 ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( V_24 == NULL ) {
V_2 -> V_33 . V_39 ++ ;
return 0 ;
}
if ( V_24 -> V_26 < V_40 ) {
F_7 ( 0 , L_2 ,
V_12 , V_24 -> V_26 ) ;
V_2 -> V_33 . V_39 ++ ;
F_21 ( V_24 ) ;
return 0 ;
}
V_24 -> V_41 = F_25 ( V_24 , V_2 ) ;
V_2 -> V_33 . V_42 ++ ;
V_2 -> V_33 . V_43 += V_24 -> V_26 ;
F_26 ( V_24 ) ;
return 0 ;
}
void F_27 ( void * V_37 , void * V_38 , T_2 V_44 )
{
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = V_37 ;
F_28 (self != NULL, return;) ;
F_28 (self->magic == IRLAN_MAGIC, return;) ;
V_2 = V_11 -> V_2 ;
F_28 (dev != NULL, return;) ;
F_7 ( 0 , L_3 , V_12 ,
V_44 == V_45 ? L_4 : L_5 ,
F_29 ( V_2 ) ) ;
switch ( V_44 ) {
case V_45 :
F_8 ( V_2 ) ;
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
F_7 ( 2 , L_1 , V_12 ) ;
if ( V_11 -> V_20 . V_47 != V_48 ) {
F_7 ( 1 , L_6 , V_12 ) ;
return;
}
if ( V_2 -> V_49 & V_50 ) {
F_32 ( L_7 ) ;
} else if ( ( V_2 -> V_49 & V_51 ) ||
F_33 ( V_2 ) > V_52 ) {
F_7 ( 4 , L_8 , V_12 ) ;
F_34 ( V_11 , TRUE ) ;
} else if ( ! F_35 ( V_2 ) ) {
F_7 ( 4 , L_8 , V_12 ) ;
F_34 ( V_11 , TRUE ) ;
} else {
F_7 ( 4 , L_9 , V_12 ) ;
F_34 ( V_11 , FALSE ) ;
}
if ( V_2 -> V_49 & V_53 )
F_36 ( V_11 , TRUE ) ;
else
F_36 ( V_11 , FALSE ) ;
}
