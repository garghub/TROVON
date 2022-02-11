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
V_27 . V_38 . V_39 = V_26 -> V_38 . V_39 ;
V_27 . V_38 . V_40 = V_26 -> V_38 . V_40 ;
if ( F_5 ( V_25 , & V_27 , sizeof( V_27 ) ) )
return - V_28 ;
return 0 ;
}
static void F_12 ( const struct V_41 * V_42 ,
struct V_43 * V_44 )
{
V_44 -> V_20 = V_42 -> V_20 -> V_19 ;
V_44 -> V_45 = V_42 -> V_45 ;
V_44 -> V_31 = V_42 -> V_31 ;
}
static long F_13 ( struct V_3 * V_18 ,
struct V_46 T_1 * V_47 )
{
struct V_17 * V_20 ;
struct V_46 V_35 ;
if ( F_11 ( & V_35 , V_47 , sizeof( V_35 ) ) )
return - V_28 ;
V_20 = F_6 ( V_18 , V_35 . V_20 ) ;
if ( V_20 == NULL )
return - V_29 ;
if ( V_35 . V_33 ) {
unsigned int V_48 ;
for ( V_48 = 0 ; V_48 < V_20 -> V_34 ; V_48 ++ ) {
struct V_43 V_49 ;
F_12 ( & V_20 -> V_33 [ V_48 ] , & V_49 ) ;
if ( F_5 ( & V_35 . V_33 [ V_48 ] , & V_49 , sizeof( V_49 ) ) )
return - V_28 ;
}
}
if ( V_35 . V_35 ) {
struct V_50 T_1 * V_51 ;
unsigned int V_52 ;
for ( V_52 = 0 , V_51 = V_35 . V_35 ; V_52 < V_20 -> V_36 ; V_52 ++ ) {
struct V_50 V_53 ;
if ( V_20 -> V_35 [ V_52 ] . V_54 -> V_20 != V_20 )
continue;
F_12 ( V_20 -> V_35 [ V_52 ] . V_54 ,
& V_53 . V_54 ) ;
F_12 ( V_20 -> V_35 [ V_52 ] . V_55 ,
& V_53 . V_55 ) ;
V_53 . V_31 = V_20 -> V_35 [ V_52 ] . V_31 ;
if ( F_5 ( V_51 , & V_53 , sizeof( * V_51 ) ) )
return - V_28 ;
V_51 ++ ;
}
}
if ( F_5 ( V_47 , & V_35 , sizeof( * V_47 ) ) )
return - V_28 ;
return 0 ;
}
static long F_14 ( struct V_3 * V_18 ,
struct V_50 T_1 * V_56 )
{
struct V_57 * V_53 = NULL ;
struct V_50 V_51 ;
struct V_17 * V_54 ;
struct V_17 * V_55 ;
int V_58 ;
if ( F_11 ( & V_51 , V_56 , sizeof( V_51 ) ) )
return - V_28 ;
V_54 = F_6 ( V_18 , V_51 . V_54 . V_20 ) ;
V_55 = F_6 ( V_18 , V_51 . V_55 . V_20 ) ;
if ( V_54 == NULL || V_55 == NULL )
return - V_29 ;
if ( V_51 . V_54 . V_45 >= V_54 -> V_34 ||
V_51 . V_55 . V_45 >= V_55 -> V_34 )
return - V_29 ;
V_53 = F_15 ( & V_54 -> V_33 [ V_51 . V_54 . V_45 ] ,
& V_55 -> V_33 [ V_51 . V_55 . V_45 ] ) ;
if ( V_53 == NULL )
return - V_29 ;
V_58 = F_16 ( V_53 , V_51 . V_31 ) ;
if ( F_5 ( V_56 , & V_51 , sizeof( V_51 ) ) )
return - V_28 ;
return V_58 ;
}
static long F_17 ( struct V_1 * V_2 , unsigned int V_59 ,
unsigned long V_60 )
{
struct V_61 * V_62 = F_18 ( V_2 ) ;
struct V_3 * V_4 = F_19 ( V_62 ) ;
long V_58 ;
switch ( V_59 ) {
case V_63 :
V_58 = F_3 ( V_4 ,
(struct V_5 T_1 * ) V_60 ) ;
break;
case V_64 :
V_58 = F_10 ( V_4 ,
(struct V_24 T_1 * ) V_60 ) ;
break;
case V_65 :
F_20 ( & V_4 -> V_66 ) ;
V_58 = F_13 ( V_4 ,
(struct V_46 T_1 * ) V_60 ) ;
F_21 ( & V_4 -> V_66 ) ;
break;
case V_67 :
F_20 ( & V_4 -> V_66 ) ;
V_58 = F_14 ( V_4 ,
(struct V_50 T_1 * ) V_60 ) ;
F_21 ( & V_4 -> V_66 ) ;
break;
default:
V_58 = - V_68 ;
}
return V_58 ;
}
static T_3 F_22 ( struct V_69 * V_70 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_3 * V_18 = F_19 ( F_23 ( V_70 ) ) ;
return sprintf ( V_73 , L_1 , ( int ) sizeof( V_18 -> V_10 ) , V_18 -> V_10 ) ;
}
static void F_24 ( struct V_61 * V_18 )
{
}
int T_4 F_25 ( struct V_3 * V_18 )
{
int V_58 ;
if ( F_26 ( V_18 -> V_4 == NULL || V_18 -> V_10 [ 0 ] == 0 ) )
return - V_29 ;
V_18 -> V_74 = 1 ;
F_27 ( & V_18 -> V_75 ) ;
F_28 ( & V_18 -> V_23 ) ;
F_29 ( & V_18 -> V_66 ) ;
V_18 -> V_62 . V_76 = & V_77 ;
V_18 -> V_62 . V_78 = V_18 -> V_4 ;
V_18 -> V_62 . V_79 = F_24 ;
V_58 = F_30 ( & V_18 -> V_62 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_31 ( & V_18 -> V_62 . V_4 , & V_80 ) ;
if ( V_58 < 0 ) {
F_32 ( & V_18 -> V_62 ) ;
return V_58 ;
}
return 0 ;
}
void F_33 ( struct V_3 * V_18 )
{
struct V_17 * V_20 ;
struct V_17 * V_21 ;
F_34 (entity, next, &mdev->entities, list)
F_35 ( V_20 ) ;
F_36 ( & V_18 -> V_62 . V_4 , & V_80 ) ;
F_32 ( & V_18 -> V_62 ) ;
}
int T_4 F_37 ( struct V_3 * V_18 ,
struct V_17 * V_20 )
{
F_26 ( V_20 -> V_78 != NULL ) ;
V_20 -> V_78 = V_18 ;
F_7 ( & V_18 -> V_23 ) ;
if ( V_20 -> V_19 == 0 )
V_20 -> V_19 = V_18 -> V_74 ++ ;
else
V_18 -> V_74 = F_38 ( V_20 -> V_19 + 1 , V_18 -> V_74 ) ;
F_39 ( & V_20 -> V_81 , & V_18 -> V_75 ) ;
F_9 ( & V_18 -> V_23 ) ;
return 0 ;
}
void F_35 ( struct V_17 * V_20 )
{
struct V_3 * V_18 = V_20 -> V_78 ;
if ( V_18 == NULL )
return;
F_7 ( & V_18 -> V_23 ) ;
F_40 ( & V_20 -> V_81 ) ;
F_9 ( & V_18 -> V_23 ) ;
V_20 -> V_78 = NULL ;
}
