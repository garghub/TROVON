static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 , V_2 ) ;
if ( V_2 -> V_6 == V_7 ) {
F_3 ( & V_4 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_6 ( V_2 ) ;
}
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 V_15 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
memcpy ( & V_15 , V_13 -> V_17 , sizeof( V_15 ) ) ;
V_17 = F_8 ( V_11 , & V_15 ) ;
if ( V_17 == NULL )
return - V_19 ;
V_2 = F_9 ( V_11 , F_1 , V_11 -> V_4 ) ;
if ( V_2 == NULL ) {
F_10 ( V_17 ) ;
return - V_20 ;
}
V_2 -> V_17 . type = V_21 ;
V_2 -> V_17 . V_22 = V_17 ;
V_2 -> type = V_13 -> type ;
V_2 -> V_23 = V_13 -> V_23 ;
V_2 -> V_24 = V_13 -> V_24 ;
V_2 -> V_25 = V_13 -> V_25 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
F_6 ( V_2 ) ;
else {
F_3 ( & ( V_11 -> V_4 ) -> V_8 ) ;
F_12 ( & V_2 -> V_9 , & V_11 -> V_4 -> V_26 ) ;
F_5 ( & ( V_11 -> V_4 ) -> V_8 ) ;
}
return V_18 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_27 * V_13 )
{
struct V_1 * V_2 , * V_28 = NULL ;
int V_29 = 0 ;
F_3 ( & ( V_11 -> V_4 ) -> V_8 ) ;
F_14 (rsv, &rc->dbg->rsvs, pal_node) {
if ( V_29 == V_13 -> V_30 ) {
V_28 = V_2 ;
F_15 ( V_28 ) ;
break;
}
V_29 ++ ;
}
F_5 ( & ( V_11 -> V_4 ) -> V_8 ) ;
if ( ! V_28 )
return - V_31 ;
F_16 ( V_28 ) ;
F_17 ( V_28 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 , struct V_32 * V_33 )
{
return F_19 ( V_11 ,
( const struct V_34 * ) V_33 -> V_35 ,
V_33 -> V_36 ) ;
}
static int F_20 ( struct V_10 * V_11 , struct V_32 * V_37 )
{
return F_21 ( V_11 , V_37 -> V_35 [ 0 ] ) ;
}
static int F_22 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
V_39 -> V_40 = V_38 -> V_41 ;
return 0 ;
}
static T_1 F_23 ( struct V_39 * V_39 , const char T_2 * V_42 ,
T_3 V_36 , T_4 * V_43 )
{
struct V_10 * V_11 = V_39 -> V_40 ;
struct V_44 V_13 ;
int V_18 = 0 ;
if ( V_36 != sizeof( struct V_44 ) )
return - V_31 ;
if ( F_24 ( & V_13 , V_42 , V_36 ) != 0 )
return - V_45 ;
switch ( V_13 . type ) {
case V_46 :
V_18 = F_7 ( V_11 , & V_13 . V_47 ) ;
break;
case V_48 :
V_18 = F_13 ( V_11 , & V_13 . V_49 ) ;
break;
case V_50 :
V_18 = F_18 ( V_11 , & V_13 . V_51 ) ;
break;
case V_52 :
V_18 = F_20 ( V_11 , & V_13 . V_53 ) ;
break;
case V_54 :
V_18 = F_25 ( & V_11 -> V_4 -> V_55 ) ;
break;
case V_56 :
F_26 ( & V_11 -> V_4 -> V_55 ) ;
break;
default:
return - V_31 ;
}
return V_18 < 0 ? V_18 : V_36 ;
}
static int F_27 ( struct V_57 * V_58 , void * V_59 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_1 * V_2 ;
F_28 ( & V_11 -> V_61 ) ;
F_14 (rsv, &rc->reservations, rc_node) {
struct V_62 V_63 ;
char V_64 [ V_65 ] , V_17 [ V_65 ] ;
bool V_66 ;
char V_42 [ 72 ] ;
F_29 ( V_64 , sizeof( V_64 ) , & V_2 -> V_64 -> V_67 ) ;
if ( V_2 -> V_17 . type == V_21 ) {
V_63 = V_2 -> V_17 . V_22 -> V_67 ;
V_66 = & V_11 -> V_16 == V_2 -> V_64 ;
} else {
V_63 = V_2 -> V_17 . V_63 ;
V_66 = true ;
}
F_29 ( V_17 , sizeof( V_17 ) , & V_63 ) ;
F_30 ( V_58 , L_2 ,
V_66 ? 'O' : 'T' ,
V_64 , V_17 , F_31 ( V_2 -> V_6 ) ) ;
F_30 ( V_58 , L_3 ,
V_2 -> V_68 , F_32 ( V_2 -> type ) ) ;
F_33 ( V_42 , sizeof( V_42 ) , V_2 -> V_69 . V_70 , V_71 ) ;
F_30 ( V_58 , L_4 , V_42 ) ;
}
F_34 ( & V_11 -> V_61 ) ;
return 0 ;
}
static int F_35 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_36 ( V_39 , F_27 , V_38 -> V_41 ) ;
}
static int F_37 ( struct V_57 * V_58 , void * V_59 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
char V_42 [ 72 ] ;
F_33 ( V_42 , sizeof( V_42 ) , V_11 -> V_72 . V_73 , V_71 ) ;
F_30 ( V_58 , L_5 , V_42 ) ;
F_33 ( V_42 , sizeof( V_42 ) , V_11 -> V_72 . V_74 , V_71 ) ;
F_30 ( V_58 , L_6 , V_42 ) ;
F_33 ( V_42 , sizeof( V_42 ) , V_11 -> V_72 . V_75 , V_71 ) ;
F_30 ( V_58 , L_7 , V_42 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_36 ( V_39 , F_37 , V_38 -> V_41 ) ;
}
static void F_39 ( struct V_76 * V_55 , int V_77 )
{
struct V_78 * V_22 = & V_55 -> V_11 -> V_16 . V_22 ;
if ( V_77 > 0 )
F_40 ( V_22 , L_8 , V_77 ) ;
else
F_40 ( V_22 , L_9 ) ;
}
static void F_41 ( struct V_76 * V_55 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_42 ( V_55 , struct V_3 , V_55 ) ;
if ( V_4 -> V_79 ) {
F_3 ( & V_4 -> V_8 ) ;
F_12 ( & V_2 -> V_9 , & V_4 -> V_26 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_43 ( V_2 , F_1 , V_4 ) ;
}
}
void F_44 ( struct V_10 * V_11 )
{
V_11 -> V_4 = F_45 ( sizeof( struct V_3 ) , V_80 ) ;
if ( V_11 -> V_4 == NULL )
return;
F_46 ( & V_11 -> V_4 -> V_26 ) ;
F_47 ( & ( V_11 -> V_4 ) -> V_8 ) ;
F_48 ( & V_11 -> V_4 -> V_55 ) ;
V_11 -> V_4 -> V_55 . V_11 = V_11 ;
V_11 -> V_4 -> V_55 . V_81 = F_39 ;
V_11 -> V_4 -> V_55 . V_82 = F_41 ;
F_49 ( & V_11 -> V_4 -> V_55 ) ;
if ( V_83 ) {
V_11 -> V_4 -> V_84 = F_50 ( F_51 ( & V_11 -> V_16 . V_22 ) ,
V_83 ) ;
V_11 -> V_4 -> V_85 = F_52 ( L_10 , 0200 ,
V_11 -> V_4 -> V_84 , V_11 ,
& V_86 ) ;
V_11 -> V_4 -> V_87 = F_52 ( L_11 , 0444 ,
V_11 -> V_4 -> V_84 , V_11 ,
& V_88 ) ;
V_11 -> V_4 -> V_89 = F_53 ( L_12 , 0644 ,
V_11 -> V_4 -> V_84 ,
& V_11 -> V_4 -> V_79 ) ;
V_11 -> V_4 -> V_90 = F_52 ( L_13 , 0444 ,
V_11 -> V_4 -> V_84 , V_11 ,
& V_91 ) ;
}
}
void F_54 ( struct V_10 * V_11 )
{
struct V_1 * V_2 , * V_92 ;
if ( V_11 -> V_4 == NULL )
return;
F_55 (rsv, t, &rc->dbg->rsvs, pal_node) {
F_16 ( V_2 ) ;
}
F_56 ( & V_11 -> V_4 -> V_55 ) ;
if ( V_83 ) {
F_57 ( V_11 -> V_4 -> V_90 ) ;
F_57 ( V_11 -> V_4 -> V_89 ) ;
F_57 ( V_11 -> V_4 -> V_87 ) ;
F_57 ( V_11 -> V_4 -> V_85 ) ;
F_57 ( V_11 -> V_4 -> V_84 ) ;
}
}
void F_58 ( void )
{
V_83 = F_50 ( L_14 , NULL ) ;
}
void F_59 ( void )
{
F_57 ( V_83 ) ;
}
struct V_93 * F_60 ( struct V_76 * V_55 )
{
struct V_10 * V_11 = V_55 -> V_11 ;
if ( V_83 && V_11 -> V_4 && V_11 -> V_4 -> V_84 && V_55 -> V_94 )
return F_50 ( V_55 -> V_94 , V_11 -> V_4 -> V_84 ) ;
return NULL ;
}
