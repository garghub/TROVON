static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
char * V_8 ;
char * V_9 ;
char * V_10 ;
T_1 V_11 = 0 ;
V_9 = F_2 ( V_12 , V_13 ) ;
if ( ! V_9 )
return false ;
V_8 = V_9 ;
V_11 = F_3 ( V_4 , 0x5f ,
0 , V_8 , V_12 ) ;
if ( V_11 > 5 ) {
F_4 ( L_1 \
L_2 ,
V_11 , V_8 [ 0 ] ,
V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] , V_8 [ 4 ] , V_8 [ 5 ] , V_8 [ 6 ] ,
V_8 [ 7 ] , V_8 [ 8 ] , V_8 [ 9 ] , V_8 [ 10 ] ) ;
if ( ( V_8 [ 0 ] != V_11 ) ||
( V_8 [ 1 ] != 0x5f ) ||
( V_8 [ 2 ] != 0x01 ) ||
( V_8 [ 3 ] != 0x00 ) ||
( V_8 [ 4 ] != V_11 - 2 ) )
goto V_14;
V_10 = V_8 + V_11 ;
V_8 += 5 ;
while ( V_8 < V_10 ) {
T_1 V_15 ;
T_2 V_16 ;
V_16 = F_5 ( * ( ( T_2 * ) V_8 ) ) ;
V_8 += sizeof( T_2 ) ;
V_15 = * V_8 ;
V_8 ++ ;
switch ( V_16 ) {
case 0x0200 : {
T_3 V_17 ;
V_17 = F_6 ( * ( ( T_3 * ) V_8 ) ) ;
F_7 ( L_3 ,
V_17 ) ;
V_6 -> V_18 = V_17 ;
break;
}
default:
break;
}
V_8 += V_15 ;
}
}
goto V_19;
V_14:
F_8 ( L_4 ) ;
V_19:
F_9 ( V_9 ) ;
return true ;
}
static void F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 , struct V_22 ,
V_24 . V_21 ) ;
F_12 ( & V_23 -> V_2 -> V_25 . V_26 ) ;
}
void F_13 ( struct V_27 * V_27 )
{
struct V_22 * V_23 = V_27 -> V_28 ;
struct V_5 * V_6 = V_23 -> V_2 ;
unsigned long V_29 ;
if ( V_27 -> V_30 ) {
if ( ! ( V_27 -> V_30 == - V_31 ||
V_27 -> V_30 == - V_32 ||
V_27 -> V_30 == - V_33 ) ) {
F_8 ( L_5 ,
V_34 , V_27 -> V_30 ) ;
F_14 ( & V_6 -> V_35 , 1 ) ;
}
}
V_27 -> V_36 = V_6 -> V_25 . V_37 ;
F_15 ( & V_6 -> V_25 . V_38 , V_29 ) ;
F_16 ( & V_23 -> V_39 , & V_6 -> V_25 . V_40 ) ;
V_6 -> V_25 . V_41 ++ ;
F_17 ( & V_6 -> V_25 . V_38 , V_29 ) ;
#if 0
if (fb_defio)
schedule_delayed_work(&unode->release_urb_work, 0);
else
#endif
F_12 ( & V_6 -> V_25 . V_26 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_42 = V_6 -> V_25 . V_42 ;
struct V_43 * V_44 ;
struct V_22 * V_23 ;
struct V_27 * V_27 ;
int V_45 ;
unsigned long V_29 ;
F_7 ( L_6 ) ;
while ( V_42 -- ) {
V_45 = F_19 ( & V_6 -> V_25 . V_26 ) ;
if ( V_45 )
break;
F_15 ( & V_6 -> V_25 . V_38 , V_29 ) ;
V_44 = V_6 -> V_25 . V_40 . V_46 ;
F_20 ( V_44 ) ;
F_17 ( & V_6 -> V_25 . V_38 , V_29 ) ;
V_23 = F_21 ( V_44 , struct V_22 , V_39 ) ;
V_27 = V_23 -> V_27 ;
F_22 ( V_27 -> V_2 , V_6 -> V_25 . V_37 ,
V_27 -> V_47 , V_27 -> V_48 ) ;
F_23 ( V_27 ) ;
F_9 ( V_44 ) ;
}
V_6 -> V_25 . V_42 = 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_42 , T_4 V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_49 = 0 ;
struct V_27 * V_27 ;
struct V_22 * V_23 ;
char * V_9 ;
F_25 ( & V_6 -> V_25 . V_38 ) ;
V_6 -> V_25 . V_37 = V_37 ;
F_26 ( & V_6 -> V_25 . V_40 ) ;
while ( V_49 < V_42 ) {
V_23 = F_2 ( sizeof( struct V_22 ) , V_13 ) ;
if ( ! V_23 )
break;
V_23 -> V_2 = V_6 ;
F_27 ( & V_23 -> V_24 ,
F_10 ) ;
V_27 = F_28 ( 0 , V_13 ) ;
if ( ! V_27 ) {
F_9 ( V_23 ) ;
break;
}
V_23 -> V_27 = V_27 ;
V_9 = F_29 ( V_6 -> V_50 -> V_4 , V_51 , V_13 ,
& V_27 -> V_48 ) ;
if ( ! V_9 ) {
F_9 ( V_23 ) ;
F_23 ( V_27 ) ;
break;
}
F_30 ( V_27 , V_6 -> V_50 -> V_4 , F_31 ( V_6 -> V_50 -> V_4 , 1 ) ,
V_9 , V_37 , F_13 , V_23 ) ;
V_27 -> V_52 |= V_53 ;
F_16 ( & V_23 -> V_39 , & V_6 -> V_25 . V_40 ) ;
V_49 ++ ;
}
F_32 ( & V_6 -> V_25 . V_26 , V_49 ) ;
V_6 -> V_25 . V_42 = V_49 ;
V_6 -> V_25 . V_41 = V_49 ;
F_7 ( L_7 , V_49 , ( int ) V_37 ) ;
return V_49 ;
}
struct V_27 * F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_45 = 0 ;
struct V_43 * V_39 ;
struct V_22 * V_23 ;
struct V_27 * V_27 = NULL ;
unsigned long V_29 ;
V_45 = F_34 ( & V_6 -> V_25 . V_26 , V_54 ) ;
if ( V_45 ) {
F_14 ( & V_6 -> V_35 , 1 ) ;
F_4 ( L_8 ,
V_45 , V_6 -> V_25 . V_41 ) ;
goto error;
}
F_15 ( & V_6 -> V_25 . V_38 , V_29 ) ;
F_35 ( F_36 ( & V_6 -> V_25 . V_40 ) ) ;
V_39 = V_6 -> V_25 . V_40 . V_46 ;
F_20 ( V_39 ) ;
V_6 -> V_25 . V_41 -- ;
F_17 ( & V_6 -> V_25 . V_38 , V_29 ) ;
V_23 = F_21 ( V_39 , struct V_22 , V_39 ) ;
V_27 = V_23 -> V_27 ;
error:
return V_27 ;
}
int F_37 ( struct V_1 * V_2 , struct V_27 * V_27 , T_4 V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_45 ;
F_35 ( V_55 > V_6 -> V_25 . V_37 ) ;
V_27 -> V_36 = V_55 ;
V_45 = F_38 ( V_27 , V_56 ) ;
if ( V_45 ) {
F_13 ( V_27 ) ;
F_14 ( & V_6 -> V_35 , 1 ) ;
F_8 ( L_9 , V_45 ) ;
}
return V_45 ;
}
int F_39 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_5 * V_6 ;
int V_45 ;
F_7 ( L_10 ) ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( ! V_6 )
return - V_57 ;
V_6 -> V_50 = V_2 ;
V_2 -> V_7 = V_6 ;
if ( ! F_1 ( V_2 , V_2 -> V_4 ) ) {
F_8 ( L_11 ) ;
goto V_58;
}
if ( ! F_24 ( V_2 , V_59 , V_51 ) ) {
V_45 = - V_57 ;
F_8 ( L_12 ) ;
goto V_58;
}
F_7 ( L_10 ) ;
V_45 = F_40 ( V_2 ) ;
V_45 = F_41 ( V_2 ) ;
return 0 ;
V_58:
F_9 ( V_6 ) ;
F_8 ( L_13 , V_45 ) ;
return V_45 ;
}
int F_42 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_25 . V_42 )
F_18 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
