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
F_4 ( L_1 ,
V_11 , V_8 ) ;
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
F_7 ( L_2 ,
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
F_8 ( L_3 ) ;
V_19:
F_9 ( V_9 ) ;
return true ;
}
static int F_10 ( struct V_5 * V_6 )
{
int V_20 ;
static const T_1 V_21 [] = { 0x57 , 0xCD , 0xDC , 0xA7 ,
0x1C , 0x88 , 0x5E , 0x15 ,
0x60 , 0xFE , 0xC6 , 0x97 ,
0x16 , 0x3D , 0x47 , 0xF2 } ;
void * V_22 ;
V_22 = F_11 ( V_21 , sizeof( V_21 ) , V_13 ) ;
if ( ! V_22 )
return - V_23 ;
V_20 = F_12 ( V_6 -> V_24 ,
F_13 ( V_6 -> V_24 , 0 ) ,
V_25 ,
( V_26 | V_27 ) , 0 , 0 ,
V_22 , sizeof( V_21 ) ,
V_28 ) ;
F_9 ( V_22 ) ;
return V_20 < 0 ? V_20 : 0 ;
}
static void F_14 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_15 ( V_30 , struct V_31 ,
V_33 . V_30 ) ;
F_16 ( & V_32 -> V_2 -> V_34 . V_35 ) ;
}
void F_17 ( struct V_36 * V_36 )
{
struct V_31 * V_32 = V_36 -> V_37 ;
struct V_5 * V_6 = V_32 -> V_2 ;
unsigned long V_38 ;
if ( V_36 -> V_39 ) {
if ( ! ( V_36 -> V_39 == - V_40 ||
V_36 -> V_39 == - V_41 ||
V_36 -> V_39 == - V_42 ) ) {
F_8 ( L_4 ,
V_43 , V_36 -> V_39 ) ;
F_18 ( & V_6 -> V_44 , 1 ) ;
}
}
V_36 -> V_45 = V_6 -> V_34 . V_46 ;
F_19 ( & V_6 -> V_34 . V_47 , V_38 ) ;
F_20 ( & V_32 -> V_48 , & V_6 -> V_34 . V_49 ) ;
V_6 -> V_34 . V_50 ++ ;
F_21 ( & V_6 -> V_34 . V_47 , V_38 ) ;
#if 0
if (fb_defio)
schedule_delayed_work(&unode->release_urb_work, 0);
else
#endif
F_16 ( & V_6 -> V_34 . V_35 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_51 = V_6 -> V_34 . V_51 ;
struct V_52 * V_53 ;
struct V_31 * V_32 ;
struct V_36 * V_36 ;
int V_20 ;
unsigned long V_38 ;
F_7 ( L_5 ) ;
while ( V_51 -- ) {
V_20 = F_23 ( & V_6 -> V_34 . V_35 ) ;
if ( V_20 )
break;
F_19 ( & V_6 -> V_34 . V_47 , V_38 ) ;
V_53 = V_6 -> V_34 . V_49 . V_54 ;
F_24 ( V_53 ) ;
F_21 ( & V_6 -> V_34 . V_47 , V_38 ) ;
V_32 = F_25 ( V_53 , struct V_31 , V_48 ) ;
V_36 = V_32 -> V_36 ;
F_26 ( V_36 -> V_2 , V_6 -> V_34 . V_46 ,
V_36 -> V_55 , V_36 -> V_56 ) ;
F_27 ( V_36 ) ;
F_9 ( V_53 ) ;
}
V_6 -> V_34 . V_51 = 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_51 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_57 = 0 ;
struct V_36 * V_36 ;
struct V_31 * V_32 ;
char * V_9 ;
F_29 ( & V_6 -> V_34 . V_47 ) ;
V_6 -> V_34 . V_46 = V_46 ;
F_30 ( & V_6 -> V_34 . V_49 ) ;
while ( V_57 < V_51 ) {
V_32 = F_2 ( sizeof( struct V_31 ) , V_13 ) ;
if ( ! V_32 )
break;
V_32 -> V_2 = V_6 ;
F_31 ( & V_32 -> V_33 ,
F_14 ) ;
V_36 = F_32 ( 0 , V_13 ) ;
if ( ! V_36 ) {
F_9 ( V_32 ) ;
break;
}
V_32 -> V_36 = V_36 ;
V_9 = F_33 ( V_6 -> V_24 , V_58 , V_13 ,
& V_36 -> V_56 ) ;
if ( ! V_9 ) {
F_9 ( V_32 ) ;
F_27 ( V_36 ) ;
break;
}
F_34 ( V_36 , V_6 -> V_24 , F_35 ( V_6 -> V_24 , 1 ) ,
V_9 , V_46 , F_17 , V_32 ) ;
V_36 -> V_59 |= V_60 ;
F_20 ( & V_32 -> V_48 , & V_6 -> V_34 . V_49 ) ;
V_57 ++ ;
}
F_36 ( & V_6 -> V_34 . V_35 , V_57 ) ;
V_6 -> V_34 . V_51 = V_57 ;
V_6 -> V_34 . V_50 = V_57 ;
F_7 ( L_6 , V_57 , ( int ) V_46 ) ;
return V_57 ;
}
struct V_36 * F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_20 = 0 ;
struct V_52 * V_48 ;
struct V_31 * V_32 ;
struct V_36 * V_36 = NULL ;
unsigned long V_38 ;
V_20 = F_38 ( & V_6 -> V_34 . V_35 , V_61 ) ;
if ( V_20 ) {
F_18 ( & V_6 -> V_44 , 1 ) ;
F_4 ( L_7 ,
V_20 , V_6 -> V_34 . V_50 ) ;
goto error;
}
F_19 ( & V_6 -> V_34 . V_47 , V_38 ) ;
F_39 ( F_40 ( & V_6 -> V_34 . V_49 ) ) ;
V_48 = V_6 -> V_34 . V_49 . V_54 ;
F_24 ( V_48 ) ;
V_6 -> V_34 . V_50 -- ;
F_21 ( & V_6 -> V_34 . V_47 , V_38 ) ;
V_32 = F_25 ( V_48 , struct V_31 , V_48 ) ;
V_36 = V_32 -> V_36 ;
error:
return V_36 ;
}
int F_41 ( struct V_1 * V_2 , struct V_36 * V_36 , T_4 V_62 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_20 ;
F_39 ( V_62 > V_6 -> V_34 . V_46 ) ;
V_36 -> V_45 = V_62 ;
V_20 = F_42 ( V_36 , V_63 ) ;
if ( V_20 ) {
F_17 ( V_36 ) ;
F_18 ( & V_6 -> V_44 , 1 ) ;
F_8 ( L_8 , V_20 ) ;
}
return V_20 ;
}
int F_43 ( struct V_1 * V_2 , unsigned long V_38 )
{
struct V_3 * V_24 = ( void * ) V_38 ;
struct V_5 * V_6 ;
int V_20 = - V_23 ;
F_7 ( L_9 ) ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( ! V_6 )
return - V_23 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_64 = V_2 ;
V_2 -> V_7 = V_6 ;
if ( ! F_1 ( V_2 , V_6 -> V_24 ) ) {
V_20 = - V_65 ;
F_8 ( L_10 ) ;
goto V_66;
}
if ( F_10 ( V_6 ) )
F_8 ( L_11 ) ;
if ( ! F_28 ( V_2 , V_67 , V_58 ) ) {
F_8 ( L_12 ) ;
goto V_66;
}
F_7 ( L_9 ) ;
V_20 = F_44 ( V_2 ) ;
if ( V_20 )
goto V_66;
V_20 = F_45 ( V_2 ) ;
if ( V_20 )
goto V_66;
V_20 = F_46 ( V_2 , 1 ) ;
if ( V_20 )
goto V_68;
return 0 ;
V_68:
F_47 ( V_2 ) ;
V_66:
if ( V_6 -> V_34 . V_51 )
F_22 ( V_2 ) ;
F_9 ( V_6 ) ;
F_8 ( L_13 , V_20 ) ;
return V_20 ;
}
int F_48 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_34 . V_51 )
F_22 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 ) ;
F_9 ( V_6 ) ;
}
