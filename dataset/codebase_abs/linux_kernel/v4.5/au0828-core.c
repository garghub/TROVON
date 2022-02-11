T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 = 0 ;
F_2 ( V_2 , V_5 , 0 , V_3 , & V_4 , 1 ) ;
F_3 ( 8 , L_1 , V_6 , V_3 , V_4 ) ;
return V_4 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
F_3 ( 8 , L_2 , V_6 , V_3 , V_7 ) ;
return F_5 ( V_2 , V_8 , V_7 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 )
{
int V_12 = - V_13 ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_7 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_15 | V_16 |
V_17 ,
V_10 , V_11 , NULL , 0 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( L_3 ,
V_6 , V_12 ) ;
}
}
return V_12 ;
}
static int F_2 ( struct V_1 * V_2 , T_2 V_9 , T_1 V_10 ,
T_2 V_11 , unsigned char * V_18 , T_2 V_19 )
{
int V_12 = - V_13 ;
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_14 ) {
V_12 = F_6 ( V_2 -> V_14 ,
F_11 ( V_2 -> V_14 , 0 ) ,
V_9 ,
V_21 | V_16 | V_17 ,
V_10 , V_11 ,
V_2 -> V_22 , V_19 , 1000 ) ;
V_12 = F_8 ( V_12 , 0 ) ;
if ( V_12 < 0 ) {
F_9 ( L_4 ,
V_6 , V_12 ) ;
}
memcpy ( V_18 , V_2 -> V_22 , V_19 ) ;
}
F_12 ( & V_2 -> V_20 ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
if ( V_2 -> V_23 ) {
F_15 ( V_2 -> V_23 ) ;
F_16 ( V_2 -> V_23 ) ;
F_17 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
#endif
}
static void F_18 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_19 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
#ifdef F_14
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( F_21 ( V_24 ) . type == V_26 )
return;
F_22 ( & V_2 -> V_27 [ V_24 ] ) ;
}
#endif
}
static void F_23 ( struct V_28 * V_29 )
{
struct V_1 * V_2 =
F_24 ( V_29 , struct V_1 , V_29 ) ;
F_25 ( & V_2 -> V_30 ) ;
F_26 ( & V_2 -> V_29 ) ;
F_20 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static void F_27 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_28 ( V_32 ) ;
F_3 ( 1 , L_5 , V_6 ) ;
V_2 -> V_33 = V_34 ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_32 , NULL ) ;
F_10 ( & V_2 -> V_20 ) ;
V_2 -> V_14 = NULL ;
F_12 ( & V_2 -> V_20 ) ;
#ifdef F_32
if ( F_21 ( 0 ) . type != V_26 ) {
F_33 ( V_2 ) ;
F_34 ( & V_2 -> V_29 ) ;
F_35 ( & V_2 -> V_29 ) ;
return;
}
#endif
F_18 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
#ifdef F_14
struct V_37 * V_38 ;
V_38 = F_37 ( sizeof( * V_38 ) , V_39 ) ;
if ( ! V_38 )
return - V_40 ;
V_38 -> V_2 = & V_36 -> V_2 ;
if ( ! V_2 -> V_41 . V_42 )
F_38 ( V_38 -> V_43 , L_6 , sizeof( V_38 -> V_43 ) ) ;
else
F_38 ( V_38 -> V_43 , V_2 -> V_41 . V_42 , sizeof( V_38 -> V_43 ) ) ;
if ( V_36 -> V_44 )
F_38 ( V_38 -> V_44 , V_36 -> V_44 , sizeof( V_38 -> V_44 ) ) ;
strcpy ( V_38 -> V_45 , V_36 -> V_46 ) ;
V_38 -> V_47 = F_39 ( V_36 -> V_48 . V_49 ) ;
V_38 -> V_50 = V_51 ;
F_40 ( V_38 ) ;
V_2 -> V_23 = V_38 ;
#endif
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
#ifdef F_14
struct V_37 * V_38 = V_2 -> V_23 ;
struct V_52 * V_53 ;
struct V_52 * V_54 = NULL , * V_55 = NULL ;
int V_24 , V_56 ;
if ( ! V_38 )
return 0 ;
F_42 (entity, mdev) {
switch ( V_53 -> V_57 ) {
case V_58 :
V_54 = V_53 ;
break;
case V_59 :
V_55 = V_53 ;
break;
}
}
if ( ! V_55 )
return - V_60 ;
if ( V_54 ) {
V_56 = F_43 ( V_54 , V_61 ,
V_55 , 0 ,
V_62 ) ;
if ( V_56 )
return V_56 ;
}
V_56 = F_43 ( V_55 , 1 , & V_2 -> V_63 . V_53 , 0 ,
V_62 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_43 ( V_55 , 2 , & V_2 -> V_64 . V_53 , 0 ,
V_62 ) ;
if ( V_56 )
return V_56 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
struct V_52 * V_65 = & V_2 -> V_27 [ V_24 ] ;
if ( F_21 ( V_24 ) . type == V_26 )
break;
switch ( F_21 ( V_24 ) . type ) {
case V_66 :
case V_67 :
case V_68 :
if ( ! V_54 )
break;
V_56 = F_43 ( V_65 , 0 , V_54 ,
V_69 ,
V_62 ) ;
if ( V_56 )
return V_56 ;
break;
case V_70 :
case V_71 :
default:
V_56 = F_43 ( V_65 , 0 , V_55 , 0 , 0 ) ;
if ( V_56 )
return V_56 ;
break;
}
}
#endif
return 0 ;
}
static int F_44 ( struct V_31 * V_32 ,
const struct V_72 * V_73 )
{
int V_74 ;
int V_75 = 0 ;
struct V_1 * V_2 ;
struct V_35 * V_14 = F_45 ( V_32 ) ;
V_74 = V_32 -> V_76 -> V_77 . V_78 ;
if ( V_74 != 0 )
return - V_13 ;
F_3 ( 1 , L_7 , V_6 ,
F_39 ( V_14 -> V_48 . V_79 ) ,
F_39 ( V_14 -> V_48 . V_80 ) ,
V_74 ) ;
if ( V_14 -> V_81 != V_82 && V_83 == 0 ) {
F_9 ( L_8 ) ;
F_9 ( L_9 ) ;
return - V_13 ;
}
V_2 = F_37 ( sizeof( * V_2 ) , V_39 ) ;
if ( V_2 == NULL ) {
F_9 ( L_10 , V_6 ) ;
return - V_40 ;
}
F_46 ( & V_2 -> V_84 ) ;
F_10 ( & V_2 -> V_84 ) ;
F_46 ( & V_2 -> V_20 ) ;
F_46 ( & V_2 -> V_85 . V_84 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_86 = V_73 -> V_87 ;
V_2 -> V_41 = V_88 [ V_2 -> V_86 ] ;
V_75 = F_36 ( V_2 , V_14 ) ;
if ( V_75 ) {
F_9 ( L_11 ,
V_6 ) ;
F_12 ( & V_2 -> V_84 ) ;
F_17 ( V_2 ) ;
return V_75 ;
}
#ifdef F_32
V_2 -> V_29 . V_89 = F_23 ;
#ifdef F_14
V_2 -> V_29 . V_38 = V_2 -> V_23 ;
#endif
V_75 = F_47 ( & V_32 -> V_2 , & V_2 -> V_29 ) ;
if ( V_75 ) {
F_9 ( L_12 ,
V_6 ) ;
F_12 ( & V_2 -> V_84 ) ;
F_17 ( V_2 ) ;
return V_75 ;
}
V_75 = F_48 ( & V_2 -> V_30 , 4 ) ;
if ( V_75 ) {
F_9 ( L_13 ,
V_6 ) ;
F_12 ( & V_2 -> V_84 ) ;
F_17 ( V_2 ) ;
return V_75 ;
}
V_2 -> V_29 . V_90 = & V_2 -> V_30 ;
#endif
F_49 ( V_2 , V_91 , 1 << 4 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
#ifdef F_32
if ( F_21 ( 0 ) . type != V_26 )
F_53 ( V_2 , V_32 ) ;
#endif
V_75 = F_54 ( V_2 ) ;
if ( V_75 )
F_9 ( L_14 ,
V_6 ) ;
F_55 ( V_2 ) ;
F_31 ( V_32 , V_2 ) ;
F_56 ( L_15 ,
V_2 -> V_41 . V_42 == NULL ? L_16 : V_2 -> V_41 . V_42 ) ;
F_12 ( & V_2 -> V_84 ) ;
V_75 = F_41 ( V_2 ) ;
if ( V_75 ) {
F_9 ( L_17 ,
V_6 ) ;
goto V_92;
}
#ifdef F_14
V_75 = F_57 ( V_2 -> V_23 ) ;
#endif
V_92:
if ( V_75 < 0 )
F_27 ( V_32 ) ;
return V_75 ;
}
static int F_58 ( struct V_31 * V_32 ,
T_4 V_93 )
{
struct V_1 * V_2 = F_28 ( V_32 ) ;
if ( ! V_2 )
return 0 ;
F_56 ( L_18 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_28 ( V_32 ) ;
if ( ! V_2 )
return 0 ;
F_56 ( L_19 ) ;
F_49 ( V_2 , V_91 , 1 << 4 ) ;
F_50 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int T_5 F_66 ( void )
{
int V_56 ;
if ( V_94 & 1 )
F_56 ( L_20 , V_6 ) ;
if ( V_94 & 2 )
F_56 ( L_21 , V_6 ) ;
if ( V_94 & 4 )
F_56 ( L_22 , V_6 ) ;
if ( V_94 & 8 )
F_56 ( L_23 ,
V_6 ) ;
if ( V_94 & 16 )
F_56 ( L_24 ,
V_6 ) ;
F_56 ( L_25 ) ;
V_56 = F_67 ( & V_95 ) ;
if ( V_56 )
F_9 ( L_26 , V_56 ) ;
return V_56 ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_95 ) ;
}
