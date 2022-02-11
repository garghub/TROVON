static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 T_1 * V_6 )
{
struct V_5 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
F_4 ( V_7 . V_8 , V_4 -> V_4 -> V_8 -> V_9 , sizeof( V_7 . V_8 ) ) ;
F_4 ( V_7 . V_10 , V_4 -> V_10 , sizeof( V_7 . V_10 ) ) ;
F_4 ( V_7 . V_11 , V_4 -> V_11 , sizeof( V_7 . V_11 ) ) ;
F_4 ( V_7 . V_12 , V_4 -> V_12 , sizeof( V_7 . V_12 ) ) ;
V_7 . V_13 = V_14 ;
V_7 . V_15 = V_4 -> V_15 ;
V_7 . V_16 = V_4 -> V_16 ;
if ( F_5 ( V_6 , & V_7 , sizeof( * V_6 ) ) )
return - V_17 ;
return 0 ;
}
static struct V_18 * F_6 ( struct V_3 * V_19 , T_2 V_20 )
{
struct V_18 * V_21 ;
int V_22 = V_20 & V_23 ;
V_20 &= ~ V_23 ;
F_7 ( & V_19 -> V_24 ) ;
F_8 (entity, mdev) {
if ( ( V_21 -> V_20 == V_20 && ! V_22 ) ||
( V_21 -> V_20 > V_20 && V_22 ) ) {
F_9 ( & V_19 -> V_24 ) ;
return V_21 ;
}
}
F_9 ( & V_19 -> V_24 ) ;
return NULL ;
}
static long F_10 ( struct V_3 * V_19 ,
struct V_25 T_1 * V_26 )
{
struct V_18 * V_27 ;
struct V_25 V_28 ;
if ( F_11 ( & V_28 . V_20 , & V_26 -> V_20 , sizeof( V_28 . V_20 ) ) )
return - V_17 ;
V_27 = F_6 ( V_19 , V_28 . V_20 ) ;
if ( V_27 == NULL )
return - V_29 ;
V_28 . V_20 = V_27 -> V_20 ;
if ( V_27 -> V_9 ) {
strncpy ( V_28 . V_9 , V_27 -> V_9 , sizeof( V_28 . V_9 ) ) ;
V_28 . V_9 [ sizeof( V_28 . V_9 ) - 1 ] = '\0' ;
} else {
memset ( V_28 . V_9 , 0 , sizeof( V_28 . V_9 ) ) ;
}
V_28 . type = V_27 -> type ;
V_28 . V_30 = V_27 -> V_30 ;
V_28 . V_31 = V_27 -> V_31 ;
V_28 . V_32 = V_27 -> V_32 ;
V_28 . V_33 = V_27 -> V_34 ;
V_28 . V_35 = V_27 -> V_36 - V_27 -> V_37 ;
memcpy ( & V_28 . V_38 , & V_27 -> V_7 , sizeof( V_27 -> V_7 ) ) ;
if ( F_5 ( V_26 , & V_28 , sizeof( V_28 ) ) )
return - V_17 ;
return 0 ;
}
static void F_12 ( const struct V_39 * V_40 ,
struct V_41 * V_42 )
{
V_42 -> V_21 = V_40 -> V_21 -> V_20 ;
V_42 -> V_43 = V_40 -> V_43 ;
V_42 -> V_31 = V_40 -> V_31 ;
}
static long F_13 ( struct V_3 * V_19 ,
struct V_44 * V_35 )
{
struct V_18 * V_21 ;
V_21 = F_6 ( V_19 , V_35 -> V_21 ) ;
if ( V_21 == NULL )
return - V_29 ;
if ( V_35 -> V_33 ) {
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < V_21 -> V_34 ; V_45 ++ ) {
struct V_41 V_46 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
F_12 ( & V_21 -> V_33 [ V_45 ] , & V_46 ) ;
if ( F_5 ( & V_35 -> V_33 [ V_45 ] , & V_46 , sizeof( V_46 ) ) )
return - V_17 ;
}
}
if ( V_35 -> V_35 ) {
struct V_47 T_1 * V_48 ;
unsigned int V_49 ;
for ( V_49 = 0 , V_48 = V_35 -> V_35 ; V_49 < V_21 -> V_36 ; V_49 ++ ) {
struct V_47 V_50 ;
if ( V_21 -> V_35 [ V_49 ] . V_51 -> V_21 != V_21 )
continue;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
F_12 ( V_21 -> V_35 [ V_49 ] . V_51 ,
& V_50 . V_51 ) ;
F_12 ( V_21 -> V_35 [ V_49 ] . V_52 ,
& V_50 . V_52 ) ;
V_50 . V_31 = V_21 -> V_35 [ V_49 ] . V_31 ;
if ( F_5 ( V_48 , & V_50 , sizeof( * V_48 ) ) )
return - V_17 ;
V_48 ++ ;
}
}
return 0 ;
}
static long F_14 ( struct V_3 * V_19 ,
struct V_44 T_1 * V_53 )
{
struct V_44 V_35 ;
int V_54 ;
if ( F_11 ( & V_35 , V_53 , sizeof( V_35 ) ) )
return - V_17 ;
V_54 = F_13 ( V_19 , & V_35 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_5 ( V_53 , & V_35 , sizeof( * V_53 ) ) )
return - V_17 ;
return 0 ;
}
static long F_15 ( struct V_3 * V_19 ,
struct V_47 T_1 * V_55 )
{
struct V_56 * V_50 = NULL ;
struct V_47 V_48 ;
struct V_18 * V_51 ;
struct V_18 * V_52 ;
int V_57 ;
if ( F_11 ( & V_48 , V_55 , sizeof( V_48 ) ) )
return - V_17 ;
V_51 = F_6 ( V_19 , V_48 . V_51 . V_21 ) ;
V_52 = F_6 ( V_19 , V_48 . V_52 . V_21 ) ;
if ( V_51 == NULL || V_52 == NULL )
return - V_29 ;
if ( V_48 . V_51 . V_43 >= V_51 -> V_34 ||
V_48 . V_52 . V_43 >= V_52 -> V_34 )
return - V_29 ;
V_50 = F_16 ( & V_51 -> V_33 [ V_48 . V_51 . V_43 ] ,
& V_52 -> V_33 [ V_48 . V_52 . V_43 ] ) ;
if ( V_50 == NULL )
return - V_29 ;
V_57 = F_17 ( V_50 , V_48 . V_31 ) ;
if ( F_5 ( V_55 , & V_48 , sizeof( V_48 ) ) )
return - V_17 ;
return V_57 ;
}
static long F_18 ( struct V_1 * V_2 , unsigned int V_58 ,
unsigned long V_59 )
{
struct V_60 * V_61 = F_19 ( V_2 ) ;
struct V_3 * V_4 = F_20 ( V_61 ) ;
long V_57 ;
switch ( V_58 ) {
case V_62 :
V_57 = F_3 ( V_4 ,
(struct V_5 T_1 * ) V_59 ) ;
break;
case V_63 :
V_57 = F_10 ( V_4 ,
(struct V_25 T_1 * ) V_59 ) ;
break;
case V_64 :
F_21 ( & V_4 -> V_65 ) ;
V_57 = F_14 ( V_4 ,
(struct V_44 T_1 * ) V_59 ) ;
F_22 ( & V_4 -> V_65 ) ;
break;
case V_66 :
F_21 ( & V_4 -> V_65 ) ;
V_57 = F_15 ( V_4 ,
(struct V_47 T_1 * ) V_59 ) ;
F_22 ( & V_4 -> V_65 ) ;
break;
default:
V_57 = - V_67 ;
}
return V_57 ;
}
static long F_23 ( struct V_3 * V_19 ,
struct V_68 T_1 * V_53 )
{
struct V_44 V_35 ;
T_3 V_69 , V_70 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
if ( F_24 ( V_35 . V_21 , & V_53 -> V_21 )
|| F_24 ( V_69 , & V_53 -> V_33 )
|| F_24 ( V_70 , & V_53 -> V_35 ) )
return - V_17 ;
V_35 . V_33 = F_25 ( V_69 ) ;
V_35 . V_35 = F_25 ( V_70 ) ;
return F_13 ( V_19 , & V_35 ) ;
}
static long F_26 ( struct V_1 * V_2 , unsigned int V_58 ,
unsigned long V_59 )
{
struct V_60 * V_61 = F_19 ( V_2 ) ;
struct V_3 * V_4 = F_20 ( V_61 ) ;
long V_57 ;
switch ( V_58 ) {
case V_62 :
case V_63 :
case V_66 :
return F_18 ( V_2 , V_58 , V_59 ) ;
case V_71 :
F_21 ( & V_4 -> V_65 ) ;
V_57 = F_23 ( V_4 ,
(struct V_68 T_1 * ) V_59 ) ;
F_22 ( & V_4 -> V_65 ) ;
break;
default:
V_57 = - V_67 ;
}
return V_57 ;
}
static T_4 F_27 ( struct V_72 * V_73 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_3 * V_19 = F_20 ( F_28 ( V_73 ) ) ;
return sprintf ( V_76 , L_1 , ( int ) sizeof( V_19 -> V_10 ) , V_19 -> V_10 ) ;
}
static void F_29 ( struct V_60 * V_19 )
{
}
int T_5 F_30 ( struct V_3 * V_19 )
{
int V_57 ;
if ( F_31 ( V_19 -> V_4 == NULL || V_19 -> V_10 [ 0 ] == 0 ) )
return - V_29 ;
V_19 -> V_77 = 1 ;
F_32 ( & V_19 -> V_78 ) ;
F_33 ( & V_19 -> V_24 ) ;
F_34 ( & V_19 -> V_65 ) ;
V_19 -> V_61 . V_79 = & V_80 ;
V_19 -> V_61 . V_81 = V_19 -> V_4 ;
V_19 -> V_61 . V_82 = F_29 ;
V_57 = F_35 ( & V_19 -> V_61 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_36 ( & V_19 -> V_61 . V_4 , & V_83 ) ;
if ( V_57 < 0 ) {
F_37 ( & V_19 -> V_61 ) ;
return V_57 ;
}
return 0 ;
}
void F_38 ( struct V_3 * V_19 )
{
struct V_18 * V_21 ;
struct V_18 * V_22 ;
F_39 (entity, next, &mdev->entities, list)
F_40 ( V_21 ) ;
F_41 ( & V_19 -> V_61 . V_4 , & V_83 ) ;
F_37 ( & V_19 -> V_61 ) ;
}
int T_5 F_42 ( struct V_3 * V_19 ,
struct V_18 * V_21 )
{
F_31 ( V_21 -> V_81 != NULL ) ;
V_21 -> V_81 = V_19 ;
F_7 ( & V_19 -> V_24 ) ;
if ( V_21 -> V_20 == 0 )
V_21 -> V_20 = V_19 -> V_77 ++ ;
else
V_19 -> V_77 = F_43 ( V_21 -> V_20 + 1 , V_19 -> V_77 ) ;
F_44 ( & V_21 -> V_84 , & V_19 -> V_78 ) ;
F_9 ( & V_19 -> V_24 ) ;
return 0 ;
}
void F_40 ( struct V_18 * V_21 )
{
struct V_3 * V_19 = V_21 -> V_81 ;
if ( V_19 == NULL )
return;
F_7 ( & V_19 -> V_24 ) ;
F_45 ( & V_21 -> V_84 ) ;
F_9 ( & V_19 -> V_24 ) ;
V_21 -> V_81 = NULL ;
}
