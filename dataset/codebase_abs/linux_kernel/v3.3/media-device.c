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
return F_5 ( V_6 , & V_7 , sizeof( * V_6 ) ) ;
}
static struct V_17 * F_6 ( struct V_3 * V_18 , T_2 V_19 )
{
struct V_17 * V_20 ;
int V_21 = V_19 & V_22 ;
V_19 &= ~ V_22 ;
F_7 ( & V_18 -> V_23 ) ;
F_8 (entity, mdev) {
if ( ( V_20 -> V_19 == V_19 && ! V_21 ) ||
( V_20 -> V_19 > V_19 && V_21 ) ) {
F_9 ( & V_18 -> V_23 ) ;
return V_20 ;
}
}
F_9 ( & V_18 -> V_23 ) ;
return NULL ;
}
static long F_10 ( struct V_3 * V_18 ,
struct V_24 T_1 * V_25 )
{
struct V_17 * V_26 ;
struct V_24 V_27 ;
if ( F_11 ( & V_27 . V_19 , & V_25 -> V_19 , sizeof( V_27 . V_19 ) ) )
return - V_28 ;
V_26 = F_6 ( V_18 , V_27 . V_19 ) ;
if ( V_26 == NULL )
return - V_29 ;
V_27 . V_19 = V_26 -> V_19 ;
V_27 . V_9 [ 0 ] = '\0' ;
if ( V_26 -> V_9 )
F_4 ( V_27 . V_9 , V_26 -> V_9 , sizeof( V_27 . V_9 ) ) ;
V_27 . type = V_26 -> type ;
V_27 . V_30 = V_26 -> V_30 ;
V_27 . V_31 = V_26 -> V_31 ;
V_27 . V_32 = V_26 -> V_32 ;
V_27 . V_33 = V_26 -> V_34 ;
V_27 . V_35 = V_26 -> V_36 - V_26 -> V_37 ;
memcpy ( & V_27 . V_38 , & V_26 -> V_7 , sizeof( V_26 -> V_7 ) ) ;
if ( F_5 ( V_25 , & V_27 , sizeof( V_27 ) ) )
return - V_28 ;
return 0 ;
}
static void F_12 ( const struct V_39 * V_40 ,
struct V_41 * V_42 )
{
V_42 -> V_20 = V_40 -> V_20 -> V_19 ;
V_42 -> V_43 = V_40 -> V_43 ;
V_42 -> V_31 = V_40 -> V_31 ;
}
static long F_13 ( struct V_3 * V_18 ,
struct V_44 T_1 * V_45 )
{
struct V_17 * V_20 ;
struct V_44 V_35 ;
if ( F_11 ( & V_35 , V_45 , sizeof( V_35 ) ) )
return - V_28 ;
V_20 = F_6 ( V_18 , V_35 . V_20 ) ;
if ( V_20 == NULL )
return - V_29 ;
if ( V_35 . V_33 ) {
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_20 -> V_34 ; V_46 ++ ) {
struct V_41 V_47 ;
F_12 ( & V_20 -> V_33 [ V_46 ] , & V_47 ) ;
if ( F_5 ( & V_35 . V_33 [ V_46 ] , & V_47 , sizeof( V_47 ) ) )
return - V_28 ;
}
}
if ( V_35 . V_35 ) {
struct V_48 T_1 * V_49 ;
unsigned int V_50 ;
for ( V_50 = 0 , V_49 = V_35 . V_35 ; V_50 < V_20 -> V_36 ; V_50 ++ ) {
struct V_48 V_51 ;
if ( V_20 -> V_35 [ V_50 ] . V_52 -> V_20 != V_20 )
continue;
F_12 ( V_20 -> V_35 [ V_50 ] . V_52 ,
& V_51 . V_52 ) ;
F_12 ( V_20 -> V_35 [ V_50 ] . V_53 ,
& V_51 . V_53 ) ;
V_51 . V_31 = V_20 -> V_35 [ V_50 ] . V_31 ;
if ( F_5 ( V_49 , & V_51 , sizeof( * V_49 ) ) )
return - V_28 ;
V_49 ++ ;
}
}
if ( F_5 ( V_45 , & V_35 , sizeof( * V_45 ) ) )
return - V_28 ;
return 0 ;
}
static long F_14 ( struct V_3 * V_18 ,
struct V_48 T_1 * V_54 )
{
struct V_55 * V_51 = NULL ;
struct V_48 V_49 ;
struct V_17 * V_52 ;
struct V_17 * V_53 ;
int V_56 ;
if ( F_11 ( & V_49 , V_54 , sizeof( V_49 ) ) )
return - V_28 ;
V_52 = F_6 ( V_18 , V_49 . V_52 . V_20 ) ;
V_53 = F_6 ( V_18 , V_49 . V_53 . V_20 ) ;
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
return - V_28 ;
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
(struct V_24 T_1 * ) V_58 ) ;
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
struct V_3 * V_18 = F_19 ( F_23 ( V_68 ) ) ;
return sprintf ( V_71 , L_1 , ( int ) sizeof( V_18 -> V_10 ) , V_18 -> V_10 ) ;
}
static void F_24 ( struct V_59 * V_18 )
{
}
int T_4 F_25 ( struct V_3 * V_18 )
{
int V_56 ;
if ( F_26 ( V_18 -> V_4 == NULL || V_18 -> V_10 [ 0 ] == 0 ) )
return - V_29 ;
V_18 -> V_72 = 1 ;
F_27 ( & V_18 -> V_73 ) ;
F_28 ( & V_18 -> V_23 ) ;
F_29 ( & V_18 -> V_64 ) ;
V_18 -> V_60 . V_74 = & V_75 ;
V_18 -> V_60 . V_76 = V_18 -> V_4 ;
V_18 -> V_60 . V_77 = F_24 ;
V_56 = F_30 ( & V_18 -> V_60 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_31 ( & V_18 -> V_60 . V_4 , & V_78 ) ;
if ( V_56 < 0 ) {
F_32 ( & V_18 -> V_60 ) ;
return V_56 ;
}
return 0 ;
}
void F_33 ( struct V_3 * V_18 )
{
struct V_17 * V_20 ;
struct V_17 * V_21 ;
F_34 (entity, next, &mdev->entities, list)
F_35 ( V_20 ) ;
F_36 ( & V_18 -> V_60 . V_4 , & V_78 ) ;
F_32 ( & V_18 -> V_60 ) ;
}
int T_4 F_37 ( struct V_3 * V_18 ,
struct V_17 * V_20 )
{
F_26 ( V_20 -> V_76 != NULL ) ;
V_20 -> V_76 = V_18 ;
F_7 ( & V_18 -> V_23 ) ;
if ( V_20 -> V_19 == 0 )
V_20 -> V_19 = V_18 -> V_72 ++ ;
else
V_18 -> V_72 = F_38 ( V_20 -> V_19 + 1 , V_18 -> V_72 ) ;
F_39 ( & V_20 -> V_79 , & V_18 -> V_73 ) ;
F_9 ( & V_18 -> V_23 ) ;
return 0 ;
}
void F_35 ( struct V_17 * V_20 )
{
struct V_3 * V_18 = V_20 -> V_76 ;
if ( V_18 == NULL )
return;
F_7 ( & V_18 -> V_23 ) ;
F_40 ( & V_20 -> V_79 ) ;
F_9 ( & V_18 -> V_23 ) ;
V_20 -> V_76 = NULL ;
}
