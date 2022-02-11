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
V_28 . V_9 [ 0 ] = '\0' ;
if ( V_27 -> V_9 )
F_4 ( V_28 . V_9 , V_27 -> V_9 , sizeof( V_28 . V_9 ) ) ;
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
struct V_44 T_1 * V_45 )
{
struct V_18 * V_21 ;
struct V_44 V_35 ;
if ( F_11 ( & V_35 , V_45 , sizeof( V_35 ) ) )
return - V_17 ;
V_21 = F_6 ( V_19 , V_35 . V_21 ) ;
if ( V_21 == NULL )
return - V_29 ;
if ( V_35 . V_33 ) {
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_21 -> V_34 ; V_46 ++ ) {
struct V_41 V_47 ;
F_12 ( & V_21 -> V_33 [ V_46 ] , & V_47 ) ;
if ( F_5 ( & V_35 . V_33 [ V_46 ] , & V_47 , sizeof( V_47 ) ) )
return - V_17 ;
}
}
if ( V_35 . V_35 ) {
struct V_48 T_1 * V_49 ;
unsigned int V_50 ;
for ( V_50 = 0 , V_49 = V_35 . V_35 ; V_50 < V_21 -> V_36 ; V_50 ++ ) {
struct V_48 V_51 ;
if ( V_21 -> V_35 [ V_50 ] . V_52 -> V_21 != V_21 )
continue;
F_12 ( V_21 -> V_35 [ V_50 ] . V_52 ,
& V_51 . V_52 ) ;
F_12 ( V_21 -> V_35 [ V_50 ] . V_53 ,
& V_51 . V_53 ) ;
V_51 . V_31 = V_21 -> V_35 [ V_50 ] . V_31 ;
if ( F_5 ( V_49 , & V_51 , sizeof( * V_49 ) ) )
return - V_17 ;
V_49 ++ ;
}
}
if ( F_5 ( V_45 , & V_35 , sizeof( * V_45 ) ) )
return - V_17 ;
return 0 ;
}
static long F_14 ( struct V_3 * V_19 ,
struct V_48 T_1 * V_54 )
{
struct V_55 * V_51 = NULL ;
struct V_48 V_49 ;
struct V_18 * V_52 ;
struct V_18 * V_53 ;
int V_56 ;
if ( F_11 ( & V_49 , V_54 , sizeof( V_49 ) ) )
return - V_17 ;
V_52 = F_6 ( V_19 , V_49 . V_52 . V_21 ) ;
V_53 = F_6 ( V_19 , V_49 . V_53 . V_21 ) ;
if ( V_52 == NULL || V_53 == NULL )
return - V_29 ;
if ( V_49 . V_52 . V_43 >= V_52 -> V_34 ||
V_49 . V_53 . V_43 >= V_53 -> V_34 )
return - V_29 ;
V_51 = F_15 ( & V_52 -> V_33 [ V_49 . V_52 . V_43 ] ,
& V_53 -> V_33 [ V_49 . V_53 . V_43 ] ) ;
if ( V_51 == NULL )
return - V_29 ;
V_56 = F_16 ( V_51 , V_49 . V_31 ) ;
if ( F_5 ( V_54 , & V_49 , sizeof( V_49 ) ) )
return - V_17 ;
return V_56 ;
}
static long F_17 ( struct V_1 * V_2 , unsigned int V_57 ,
unsigned long V_58 )
{
struct V_59 * V_60 = F_18 ( V_2 ) ;
struct V_3 * V_4 = F_19 ( V_60 ) ;
long V_56 ;
switch ( V_57 ) {
case V_61 :
V_56 = F_3 ( V_4 ,
(struct V_5 T_1 * ) V_58 ) ;
break;
case V_62 :
V_56 = F_10 ( V_4 ,
(struct V_25 T_1 * ) V_58 ) ;
break;
case V_63 :
F_20 ( & V_4 -> V_64 ) ;
V_56 = F_13 ( V_4 ,
(struct V_44 T_1 * ) V_58 ) ;
F_21 ( & V_4 -> V_64 ) ;
break;
case V_65 :
F_20 ( & V_4 -> V_64 ) ;
V_56 = F_14 ( V_4 ,
(struct V_48 T_1 * ) V_58 ) ;
F_21 ( & V_4 -> V_64 ) ;
break;
default:
V_56 = - V_66 ;
}
return V_56 ;
}
static T_3 F_22 ( struct V_67 * V_68 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_3 * V_19 = F_19 ( F_23 ( V_68 ) ) ;
return sprintf ( V_71 , L_1 , ( int ) sizeof( V_19 -> V_10 ) , V_19 -> V_10 ) ;
}
static void F_24 ( struct V_59 * V_19 )
{
}
int T_4 F_25 ( struct V_3 * V_19 )
{
int V_56 ;
if ( F_26 ( V_19 -> V_4 == NULL || V_19 -> V_10 [ 0 ] == 0 ) )
return - V_29 ;
V_19 -> V_72 = 1 ;
F_27 ( & V_19 -> V_73 ) ;
F_28 ( & V_19 -> V_24 ) ;
F_29 ( & V_19 -> V_64 ) ;
V_19 -> V_60 . V_74 = & V_75 ;
V_19 -> V_60 . V_76 = V_19 -> V_4 ;
V_19 -> V_60 . V_77 = F_24 ;
V_56 = F_30 ( & V_19 -> V_60 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_31 ( & V_19 -> V_60 . V_4 , & V_78 ) ;
if ( V_56 < 0 ) {
F_32 ( & V_19 -> V_60 ) ;
return V_56 ;
}
return 0 ;
}
void F_33 ( struct V_3 * V_19 )
{
struct V_18 * V_21 ;
struct V_18 * V_22 ;
F_34 (entity, next, &mdev->entities, list)
F_35 ( V_21 ) ;
F_36 ( & V_19 -> V_60 . V_4 , & V_78 ) ;
F_32 ( & V_19 -> V_60 ) ;
}
int T_4 F_37 ( struct V_3 * V_19 ,
struct V_18 * V_21 )
{
F_26 ( V_21 -> V_76 != NULL ) ;
V_21 -> V_76 = V_19 ;
F_7 ( & V_19 -> V_24 ) ;
if ( V_21 -> V_20 == 0 )
V_21 -> V_20 = V_19 -> V_72 ++ ;
else
V_19 -> V_72 = F_38 ( V_21 -> V_20 + 1 , V_19 -> V_72 ) ;
F_39 ( & V_21 -> V_79 , & V_19 -> V_73 ) ;
F_9 ( & V_19 -> V_24 ) ;
return 0 ;
}
void F_35 ( struct V_18 * V_21 )
{
struct V_3 * V_19 = V_21 -> V_76 ;
if ( V_19 == NULL )
return;
F_7 ( & V_19 -> V_24 ) ;
F_40 ( & V_21 -> V_79 ) ;
F_9 ( & V_19 -> V_24 ) ;
V_21 -> V_76 = NULL ;
}
