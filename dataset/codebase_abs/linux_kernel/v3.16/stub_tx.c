static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
F_2 ( V_3 -> V_4 ) ;
F_2 ( V_3 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( V_7 , V_2 ) ;
F_5 ( V_3 ) ;
}
void F_6 ( struct V_8 * V_9 , T_1 V_10 ,
T_1 V_11 )
{
struct V_12 * V_13 ;
V_13 = F_7 ( sizeof( struct V_12 ) , V_14 ) ;
if ( ! V_13 ) {
F_8 ( & V_9 -> V_15 , V_16 ) ;
return;
}
V_13 -> V_10 = V_10 ;
V_13 -> V_11 = V_11 ;
F_9 ( & V_13 -> V_6 , & V_9 -> V_17 ) ;
}
void F_10 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 -> V_18 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_19 ;
F_11 ( L_1 , V_3 -> V_11 ) ;
switch ( V_3 -> V_11 ) {
case 0 :
break;
case - V_20 :
F_12 ( & V_3 -> V_21 -> V_21 ,
L_2 ) ;
return;
case - V_22 :
F_12 ( & V_3 -> V_21 -> V_21 ,
L_3 ) ;
break;
case - V_23 :
F_12 ( & V_3 -> V_21 -> V_21 , L_4 ,
F_13 ( V_3 -> V_24 ) ) ;
break;
case - V_25 :
F_12 ( & V_3 -> V_21 -> V_21 , L_5 ) ;
break;
default:
F_12 ( & V_3 -> V_21 -> V_21 ,
L_6 ,
V_3 -> V_11 ) ;
break;
}
F_14 ( & V_9 -> V_26 , V_19 ) ;
if ( V_2 -> V_27 ) {
F_6 ( V_9 , V_2 -> V_10 , V_3 -> V_11 ) ;
F_1 ( V_2 ) ;
} else {
F_15 ( & V_2 -> V_6 , & V_9 -> V_28 ) ;
}
F_16 ( & V_9 -> V_26 , V_19 ) ;
F_17 ( & V_9 -> V_29 ) ;
}
static inline void F_18 ( struct V_30 * V_31 ,
T_1 V_32 , T_1 V_10 )
{
V_31 -> V_32 = V_32 ;
V_31 -> V_10 = V_10 ;
V_31 -> V_33 = 0 ;
V_31 -> V_34 = 0 ;
V_31 -> V_35 = 0 ;
}
static void F_19 ( struct V_36 * V_37 , struct V_3 * V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 -> V_18 ;
F_18 ( & V_37 -> V_31 , V_38 , V_2 -> V_10 ) ;
F_20 ( V_37 , V_3 , V_38 , 1 ) ;
}
static void F_21 ( struct V_36 * V_37 ,
struct V_12 * V_13 )
{
F_18 ( & V_37 -> V_31 , V_39 , V_13 -> V_10 ) ;
V_37 -> V_40 . V_41 . V_11 = V_13 -> V_11 ;
}
static struct V_1 * F_22 ( struct V_8 * V_9 )
{
unsigned long V_19 ;
struct V_1 * V_2 , * V_42 ;
F_14 ( & V_9 -> V_26 , V_19 ) ;
F_23 (priv, tmp, &sdev->priv_tx, list) {
F_15 ( & V_2 -> V_6 , & V_9 -> V_43 ) ;
F_16 ( & V_9 -> V_26 , V_19 ) ;
return V_2 ;
}
F_16 ( & V_9 -> V_26 , V_19 ) ;
return NULL ;
}
static int F_24 ( struct V_8 * V_9 )
{
unsigned long V_19 ;
struct V_1 * V_2 , * V_42 ;
struct V_44 V_45 ;
T_2 V_46 ;
T_2 V_47 = 0 ;
while ( ( V_2 = F_22 ( V_9 ) ) != NULL ) {
int V_48 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_36 V_49 ;
struct V_50 * V_51 = NULL ;
struct V_52 * V_53 = NULL ;
int V_54 = 0 ;
V_46 = 0 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( F_25 ( V_3 -> V_24 ) == V_55 )
V_54 = 2 + V_3 -> V_56 ;
else
V_54 = 2 ;
V_53 = F_26 ( V_54 , sizeof( struct V_52 ) , V_57 ) ;
if ( ! V_53 ) {
F_8 ( & V_9 -> V_15 , V_58 ) ;
return - 1 ;
}
V_54 = 0 ;
F_19 ( & V_49 , V_3 ) ;
F_11 ( L_7 ,
V_49 . V_31 . V_10 , V_3 ) ;
F_27 ( & V_49 , 1 ) ;
V_53 [ V_54 ] . V_59 = & V_49 ;
V_53 [ V_54 ] . V_60 = sizeof( V_49 ) ;
V_54 ++ ;
V_46 += sizeof( V_49 ) ;
if ( F_28 ( V_3 -> V_24 ) &&
F_25 ( V_3 -> V_24 ) != V_55 &&
V_3 -> V_61 > 0 ) {
V_53 [ V_54 ] . V_59 = V_3 -> V_5 ;
V_53 [ V_54 ] . V_60 = V_3 -> V_61 ;
V_54 ++ ;
V_46 += V_3 -> V_61 ;
} else if ( F_28 ( V_3 -> V_24 ) &&
F_25 ( V_3 -> V_24 ) == V_55 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_56 ; V_62 ++ ) {
V_53 [ V_54 ] . V_59 = V_3 -> V_5 +
V_3 -> V_63 [ V_62 ] . V_64 ;
V_53 [ V_54 ] . V_60 =
V_3 -> V_63 [ V_62 ] . V_61 ;
V_54 ++ ;
V_46 += V_3 -> V_63 [ V_62 ] . V_61 ;
}
if ( V_46 != sizeof( V_49 ) + V_3 -> V_61 ) {
F_29 ( & V_9 -> V_65 -> V_21 ,
L_8 ,
V_3 -> V_61 ,
V_46 - sizeof( V_49 ) ) ;
F_2 ( V_53 ) ;
F_8 ( & V_9 -> V_15 ,
V_66 ) ;
return - 1 ;
}
}
if ( F_25 ( V_3 -> V_24 ) == V_55 ) {
T_3 V_67 = 0 ;
V_51 = F_30 ( V_3 , & V_67 ) ;
if ( ! V_51 ) {
F_8 ( & V_9 -> V_15 ,
V_58 ) ;
F_2 ( V_53 ) ;
return - 1 ;
}
V_53 [ V_54 ] . V_59 = V_51 ;
V_53 [ V_54 ] . V_60 = V_67 ;
V_46 += V_67 ;
V_54 ++ ;
}
V_48 = F_31 ( V_9 -> V_15 . V_68 , & V_45 ,
V_53 , V_54 , V_46 ) ;
if ( V_48 != V_46 ) {
F_29 ( & V_9 -> V_65 -> V_21 ,
L_9 ,
V_48 , V_46 ) ;
F_2 ( V_53 ) ;
F_2 ( V_51 ) ;
F_8 ( & V_9 -> V_15 , V_66 ) ;
return - 1 ;
}
F_2 ( V_53 ) ;
F_2 ( V_51 ) ;
V_47 += V_46 ;
}
F_14 ( & V_9 -> V_26 , V_19 ) ;
F_23 (priv, tmp, &sdev->priv_free, list) {
F_1 ( V_2 ) ;
}
F_16 ( & V_9 -> V_26 , V_19 ) ;
return V_47 ;
}
static struct V_12 * F_32 ( struct V_8 * V_9 )
{
unsigned long V_19 ;
struct V_12 * V_13 , * V_42 ;
F_14 ( & V_9 -> V_26 , V_19 ) ;
F_23 (unlink, tmp, &sdev->unlink_tx, list) {
F_15 ( & V_13 -> V_6 , & V_9 -> V_69 ) ;
F_16 ( & V_9 -> V_26 , V_19 ) ;
return V_13 ;
}
F_16 ( & V_9 -> V_26 , V_19 ) ;
return NULL ;
}
static int F_33 ( struct V_8 * V_9 )
{
unsigned long V_19 ;
struct V_12 * V_13 , * V_42 ;
struct V_44 V_45 ;
struct V_52 V_53 [ 1 ] ;
T_2 V_46 ;
T_2 V_47 = 0 ;
while ( ( V_13 = F_32 ( V_9 ) ) != NULL ) {
int V_48 ;
struct V_36 V_49 ;
V_46 = 0 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
F_11 ( L_10 , V_13 -> V_10 ) ;
F_21 ( & V_49 , V_13 ) ;
F_27 ( & V_49 , 1 ) ;
V_53 [ 0 ] . V_59 = & V_49 ;
V_53 [ 0 ] . V_60 = sizeof( V_49 ) ;
V_46 += sizeof( V_49 ) ;
V_48 = F_31 ( V_9 -> V_15 . V_68 , & V_45 , V_53 ,
1 , V_46 ) ;
if ( V_48 != V_46 ) {
F_29 ( & V_9 -> V_65 -> V_21 ,
L_9 ,
V_48 , V_46 ) ;
F_8 ( & V_9 -> V_15 , V_66 ) ;
return - 1 ;
}
F_11 ( L_11 ) ;
V_47 += V_46 ;
}
F_14 ( & V_9 -> V_26 , V_19 ) ;
F_23 (unlink, tmp, &sdev->unlink_free, list) {
F_3 ( & V_13 -> V_6 ) ;
F_2 ( V_13 ) ;
}
F_16 ( & V_9 -> V_26 , V_19 ) ;
return V_47 ;
}
int F_34 ( void * V_70 )
{
struct V_71 * V_15 = V_70 ;
struct V_8 * V_9 = F_35 ( V_15 , struct V_8 , V_15 ) ;
while ( ! F_36 () ) {
if ( F_37 ( V_15 ) )
break;
if ( F_24 ( V_9 ) < 0 )
break;
if ( F_33 ( V_9 ) < 0 )
break;
F_38 ( V_9 -> V_29 ,
( ! F_39 ( & V_9 -> V_28 ) ||
! F_39 ( & V_9 -> V_17 ) ||
F_36 () ) ) ;
}
return 0 ;
}
