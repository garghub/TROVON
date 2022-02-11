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
F_8 ( & V_9 -> V_15 -> V_16 , L_1 ) ;
F_9 ( & V_9 -> V_17 , V_18 ) ;
return;
}
V_13 -> V_10 = V_10 ;
V_13 -> V_11 = V_11 ;
F_10 ( & V_13 -> V_6 , & V_9 -> V_19 ) ;
}
void F_11 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 -> V_20 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_21 ;
F_12 ( L_2 , V_3 -> V_11 ) ;
switch ( V_3 -> V_11 ) {
case 0 :
break;
case - V_22 :
F_13 ( & V_3 -> V_16 -> V_16 , L_3
L_4 ) ;
return;
case - V_23 :
F_13 ( & V_3 -> V_16 -> V_16 , L_5
L_6 ) ;
break;
case - V_24 :
F_13 ( & V_3 -> V_16 -> V_16 , L_7 ,
F_14 ( V_3 -> V_25 ) ) ;
break;
case - V_26 :
F_13 ( & V_3 -> V_16 -> V_16 , L_8 ) ;
break;
default:
F_13 ( & V_3 -> V_16 -> V_16 , L_9
L_10 , V_3 -> V_11 ) ;
break;
}
F_15 ( & V_9 -> V_27 , V_21 ) ;
if ( V_2 -> V_28 ) {
F_6 ( V_9 , V_2 -> V_10 , V_3 -> V_11 ) ;
F_1 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_6 , & V_9 -> V_29 ) ;
}
F_17 ( & V_9 -> V_27 , V_21 ) ;
F_18 ( & V_9 -> V_30 ) ;
}
static inline void F_19 ( struct V_31 * V_32 ,
T_1 V_33 , T_1 V_10 )
{
V_32 -> V_33 = V_33 ;
V_32 -> V_10 = V_10 ;
V_32 -> V_34 = 0 ;
V_32 -> V_35 = 0 ;
V_32 -> V_36 = 0 ;
}
static void F_20 ( struct V_37 * V_38 , struct V_3 * V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 -> V_20 ;
F_19 ( & V_38 -> V_32 , V_39 , V_2 -> V_10 ) ;
F_21 ( V_38 , V_3 , V_39 , 1 ) ;
}
static void F_22 ( struct V_37 * V_38 ,
struct V_12 * V_13 )
{
F_19 ( & V_38 -> V_32 , V_40 , V_13 -> V_10 ) ;
V_38 -> V_41 . V_42 . V_11 = V_13 -> V_11 ;
}
static struct V_1 * F_23 ( struct V_8 * V_9 )
{
unsigned long V_21 ;
struct V_1 * V_2 , * V_43 ;
F_15 ( & V_9 -> V_27 , V_21 ) ;
F_24 (priv, tmp, &sdev->priv_tx, list) {
F_16 ( & V_2 -> V_6 , & V_9 -> V_44 ) ;
F_17 ( & V_9 -> V_27 , V_21 ) ;
return V_2 ;
}
F_17 ( & V_9 -> V_27 , V_21 ) ;
return NULL ;
}
static int F_25 ( struct V_8 * V_9 )
{
unsigned long V_21 ;
struct V_1 * V_2 , * V_43 ;
struct V_45 V_46 ;
T_2 V_47 ;
T_2 V_48 = 0 ;
while ( ( V_2 = F_23 ( V_9 ) ) != NULL ) {
int V_49 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_37 V_50 ;
void * V_51 = NULL ;
struct V_52 * V_53 = NULL ;
int V_54 = 0 ;
V_47 = 0 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( F_26 ( V_3 -> V_25 ) == V_55 )
V_54 = 2 + V_3 -> V_56 ;
else
V_54 = 2 ;
V_53 = F_7 ( V_54 * sizeof( struct V_52 ) , V_57 ) ;
if ( ! V_53 ) {
F_9 ( & V_9 -> V_17 , V_58 ) ;
return - 1 ;
}
V_54 = 0 ;
F_20 ( & V_50 , V_3 ) ;
F_12 ( L_11 ,
V_50 . V_32 . V_10 , V_3 ) ;
F_27 ( & V_50 , 1 ) ;
V_53 [ V_54 ] . V_59 = & V_50 ;
V_53 [ V_54 ] . V_60 = sizeof( V_50 ) ;
V_54 ++ ;
V_47 += sizeof( V_50 ) ;
if ( F_28 ( V_3 -> V_25 ) &&
F_26 ( V_3 -> V_25 ) != V_55 &&
V_3 -> V_61 > 0 ) {
V_53 [ V_54 ] . V_59 = V_3 -> V_5 ;
V_53 [ V_54 ] . V_60 = V_3 -> V_61 ;
V_54 ++ ;
V_47 += V_3 -> V_61 ;
} else if ( F_28 ( V_3 -> V_25 ) &&
F_26 ( V_3 -> V_25 ) == V_55 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_3 -> V_56 ; V_62 ++ ) {
V_53 [ V_54 ] . V_59 = V_3 -> V_5 +
V_3 -> V_63 [ V_62 ] . V_64 ;
V_53 [ V_54 ] . V_60 =
V_3 -> V_63 [ V_62 ] . V_61 ;
V_54 ++ ;
V_47 += V_3 -> V_63 [ V_62 ] . V_61 ;
}
if ( V_47 != sizeof( V_50 ) + V_3 -> V_61 ) {
F_8 ( & V_9 -> V_15 -> V_16 ,
L_12
L_13 ,
V_3 -> V_61 ,
V_47 - sizeof( V_50 ) ) ;
F_2 ( V_53 ) ;
F_9 ( & V_9 -> V_17 ,
V_65 ) ;
return - 1 ;
}
}
if ( F_26 ( V_3 -> V_25 ) == V_55 ) {
T_3 V_66 = 0 ;
V_51 = F_29 ( V_3 , & V_66 ) ;
if ( ! V_51 ) {
F_9 ( & V_9 -> V_17 ,
V_58 ) ;
F_2 ( V_53 ) ;
return - 1 ;
}
V_53 [ V_54 ] . V_59 = V_51 ;
V_53 [ V_54 ] . V_60 = V_66 ;
V_47 += V_66 ;
V_54 ++ ;
}
V_49 = F_30 ( V_9 -> V_17 . V_67 , & V_46 ,
V_53 , V_54 , V_47 ) ;
if ( V_49 != V_47 ) {
F_8 ( & V_9 -> V_15 -> V_16 ,
L_14 ,
V_49 , V_47 ) ;
F_2 ( V_53 ) ;
F_2 ( V_51 ) ;
F_9 ( & V_9 -> V_17 , V_65 ) ;
return - 1 ;
}
F_2 ( V_53 ) ;
F_2 ( V_51 ) ;
V_48 += V_47 ;
}
F_15 ( & V_9 -> V_27 , V_21 ) ;
F_24 (priv, tmp, &sdev->priv_free, list) {
F_1 ( V_2 ) ;
}
F_17 ( & V_9 -> V_27 , V_21 ) ;
return V_48 ;
}
static struct V_12 * F_31 ( struct V_8 * V_9 )
{
unsigned long V_21 ;
struct V_12 * V_13 , * V_43 ;
F_15 ( & V_9 -> V_27 , V_21 ) ;
F_24 (unlink, tmp, &sdev->unlink_tx, list) {
F_16 ( & V_13 -> V_6 , & V_9 -> V_68 ) ;
F_17 ( & V_9 -> V_27 , V_21 ) ;
return V_13 ;
}
F_17 ( & V_9 -> V_27 , V_21 ) ;
return NULL ;
}
static int F_32 ( struct V_8 * V_9 )
{
unsigned long V_21 ;
struct V_12 * V_13 , * V_43 ;
struct V_45 V_46 ;
struct V_52 V_53 [ 1 ] ;
T_2 V_47 ;
T_2 V_48 = 0 ;
while ( ( V_13 = F_31 ( V_9 ) ) != NULL ) {
int V_49 ;
struct V_37 V_50 ;
V_47 = 0 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
F_12 ( L_15 , V_13 -> V_10 ) ;
F_22 ( & V_50 , V_13 ) ;
F_27 ( & V_50 , 1 ) ;
V_53 [ 0 ] . V_59 = & V_50 ;
V_53 [ 0 ] . V_60 = sizeof( V_50 ) ;
V_47 += sizeof( V_50 ) ;
V_49 = F_30 ( V_9 -> V_17 . V_67 , & V_46 , V_53 ,
1 , V_47 ) ;
if ( V_49 != V_47 ) {
F_8 ( & V_9 -> V_15 -> V_16 ,
L_14 ,
V_49 , V_47 ) ;
F_9 ( & V_9 -> V_17 , V_65 ) ;
return - 1 ;
}
F_12 ( L_16 ) ;
V_48 += V_47 ;
}
F_15 ( & V_9 -> V_27 , V_21 ) ;
F_24 (unlink, tmp, &sdev->unlink_free, list) {
F_3 ( & V_13 -> V_6 ) ;
F_2 ( V_13 ) ;
}
F_17 ( & V_9 -> V_27 , V_21 ) ;
return V_48 ;
}
int F_33 ( void * V_69 )
{
struct V_70 * V_17 = V_69 ;
struct V_8 * V_9 = F_34 ( V_17 , struct V_8 , V_17 ) ;
while ( ! F_35 () ) {
if ( F_36 ( V_17 ) )
break;
if ( F_25 ( V_9 ) < 0 )
break;
if ( F_32 ( V_9 ) < 0 )
break;
F_37 ( V_9 -> V_30 ,
( ! F_38 ( & V_9 -> V_29 ) ||
! F_38 ( & V_9 -> V_19 ) ||
F_35 () ) ) ;
}
return 0 ;
}
