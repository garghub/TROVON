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
static T_1 F_22 ( struct V_38 * V_38 , const char T_2 * V_39 ,
T_3 V_36 , T_4 * V_40 )
{
struct V_10 * V_11 = V_38 -> V_41 ;
struct V_42 V_13 ;
int V_18 = 0 ;
if ( V_36 != sizeof( struct V_42 ) )
return - V_31 ;
if ( F_23 ( & V_13 , V_39 , V_36 ) != 0 )
return - V_43 ;
switch ( V_13 . type ) {
case V_44 :
V_18 = F_7 ( V_11 , & V_13 . V_45 ) ;
break;
case V_46 :
V_18 = F_13 ( V_11 , & V_13 . V_47 ) ;
break;
case V_48 :
V_18 = F_18 ( V_11 , & V_13 . V_49 ) ;
break;
case V_50 :
V_18 = F_20 ( V_11 , & V_13 . V_51 ) ;
break;
case V_52 :
V_18 = F_24 ( & V_11 -> V_4 -> V_53 ) ;
break;
case V_54 :
F_25 ( & V_11 -> V_4 -> V_53 ) ;
break;
default:
return - V_31 ;
}
return V_18 < 0 ? V_18 : V_36 ;
}
static int F_26 ( struct V_55 * V_56 , void * V_57 )
{
struct V_10 * V_11 = V_56 -> V_58 ;
struct V_1 * V_2 ;
F_27 ( & V_11 -> V_59 ) ;
F_14 (rsv, &rc->reservations, rc_node) {
struct V_60 V_61 ;
char V_62 [ V_63 ] , V_17 [ V_63 ] ;
bool V_64 ;
F_28 ( V_62 , sizeof( V_62 ) , & V_2 -> V_62 -> V_65 ) ;
if ( V_2 -> V_17 . type == V_21 ) {
V_61 = V_2 -> V_17 . V_22 -> V_65 ;
V_64 = & V_11 -> V_16 == V_2 -> V_62 ;
} else {
V_61 = V_2 -> V_17 . V_61 ;
V_64 = true ;
}
F_28 ( V_17 , sizeof( V_17 ) , & V_61 ) ;
F_29 ( V_56 , L_2 ,
V_64 ? 'O' : 'T' ,
V_62 , V_17 , F_30 ( V_2 -> V_6 ) ) ;
F_29 ( V_56 , L_3 ,
V_2 -> V_66 , F_31 ( V_2 -> type ) ) ;
F_29 ( V_56 , L_4 , V_67 , V_2 -> V_68 . V_69 ) ;
}
F_32 ( & V_11 -> V_59 ) ;
return 0 ;
}
static int F_33 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
return F_34 ( V_38 , F_26 , V_70 -> V_71 ) ;
}
static int F_35 ( struct V_55 * V_56 , void * V_57 )
{
struct V_10 * V_11 = V_56 -> V_58 ;
F_29 ( V_56 , L_5 , V_67 , V_11 -> V_72 . V_73 ) ;
F_29 ( V_56 , L_6 , V_67 , V_11 -> V_72 . V_74 ) ;
F_29 ( V_56 , L_7 , V_67 , V_11 -> V_72 . V_75 ) ;
return 0 ;
}
static int F_36 ( struct V_70 * V_70 , struct V_38 * V_38 )
{
return F_34 ( V_38 , F_35 , V_70 -> V_71 ) ;
}
static void F_37 ( struct V_76 * V_53 , int V_77 )
{
struct V_78 * V_22 = & V_53 -> V_11 -> V_16 . V_22 ;
if ( V_77 > 0 )
F_38 ( V_22 , L_8 , V_77 ) ;
else
F_38 ( V_22 , L_9 ) ;
}
static void F_39 ( struct V_76 * V_53 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_40 ( V_53 , struct V_3 , V_53 ) ;
if ( V_4 -> V_79 ) {
F_3 ( & V_4 -> V_8 ) ;
F_12 ( & V_2 -> V_9 , & V_4 -> V_26 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_41 ( V_2 , F_1 , V_4 ) ;
}
}
void F_42 ( struct V_10 * V_11 )
{
V_11 -> V_4 = F_43 ( sizeof( struct V_3 ) , V_80 ) ;
if ( V_11 -> V_4 == NULL )
return;
F_44 ( & V_11 -> V_4 -> V_26 ) ;
F_45 ( & ( V_11 -> V_4 ) -> V_8 ) ;
F_46 ( & V_11 -> V_4 -> V_53 ) ;
V_11 -> V_4 -> V_53 . V_11 = V_11 ;
V_11 -> V_4 -> V_53 . V_81 = F_37 ;
V_11 -> V_4 -> V_53 . V_82 = F_39 ;
F_47 ( & V_11 -> V_4 -> V_53 ) ;
if ( V_83 ) {
V_11 -> V_4 -> V_84 = F_48 ( F_49 ( & V_11 -> V_16 . V_22 ) ,
V_83 ) ;
V_11 -> V_4 -> V_85 = F_50 ( L_10 , 0200 ,
V_11 -> V_4 -> V_84 , V_11 ,
& V_86 ) ;
V_11 -> V_4 -> V_87 = F_50 ( L_11 , 0444 ,
V_11 -> V_4 -> V_84 , V_11 ,
& V_88 ) ;
V_11 -> V_4 -> V_89 = F_51 ( L_12 , 0644 ,
V_11 -> V_4 -> V_84 ,
& V_11 -> V_4 -> V_79 ) ;
V_11 -> V_4 -> V_90 = F_50 ( L_13 , 0444 ,
V_11 -> V_4 -> V_84 , V_11 ,
& V_91 ) ;
}
}
void F_52 ( struct V_10 * V_11 )
{
struct V_1 * V_2 , * V_92 ;
if ( V_11 -> V_4 == NULL )
return;
F_53 (rsv, t, &rc->dbg->rsvs, pal_node) {
F_16 ( V_2 ) ;
}
F_54 ( & V_11 -> V_4 -> V_53 ) ;
if ( V_83 ) {
F_55 ( V_11 -> V_4 -> V_90 ) ;
F_55 ( V_11 -> V_4 -> V_89 ) ;
F_55 ( V_11 -> V_4 -> V_87 ) ;
F_55 ( V_11 -> V_4 -> V_85 ) ;
F_55 ( V_11 -> V_4 -> V_84 ) ;
}
}
void F_56 ( void )
{
V_83 = F_48 ( L_14 , NULL ) ;
}
void F_57 ( void )
{
F_55 ( V_83 ) ;
}
struct V_93 * F_58 ( struct V_76 * V_53 )
{
struct V_10 * V_11 = V_53 -> V_11 ;
if ( V_83 && V_11 -> V_4 && V_11 -> V_4 -> V_84 && V_53 -> V_94 )
return F_48 ( V_53 -> V_94 , V_11 -> V_4 -> V_84 ) ;
return NULL ;
}
