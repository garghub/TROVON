static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 , unsigned int V_7 )
{
struct V_8 V_9 ;
const struct V_8 * V_10 ;
unsigned int V_11 ;
if ( V_4 -> type == V_12 )
V_11 = V_4 -> V_13 . log . V_11 ;
else
V_11 = V_14 ;
V_10 = F_2 ( V_6 , V_7 , sizeof( V_9 ) , & V_9 ) ;
if ( V_10 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_2 , & V_10 -> V_15 , & V_10 -> V_16 ) ;
F_3 ( V_2 , L_3 ,
F_4 ( V_10 -> V_17 ) , V_10 -> V_18 & V_19 ,
V_10 -> V_18 & V_20 , V_10 -> V_21 , F_4 ( V_10 -> V_22 ) ) ;
if ( F_4 ( V_10 -> V_23 ) & V_24 )
F_3 ( V_2 , L_4 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_25 )
F_3 ( V_2 , L_5 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_26 )
F_3 ( V_2 , L_6 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
F_3 ( V_2 , L_7 , F_4 ( V_10 -> V_23 ) & V_27 ) ;
if ( ( V_11 & V_28 ) &&
V_10 -> V_29 * 4 > sizeof( struct V_8 ) ) {
const unsigned char * V_30 ;
unsigned char V_31 [ 4 * 15 - sizeof( struct V_8 ) ] ;
unsigned int V_32 , V_33 ;
V_33 = V_10 -> V_29 * 4 - sizeof( struct V_8 ) ;
V_30 = F_2 ( V_6 , V_7 + sizeof( V_9 ) ,
V_33 , V_31 ) ;
if ( V_30 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_8 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_3 ( V_2 , L_9 , V_30 [ V_32 ] ) ;
F_3 ( V_2 , L_10 ) ;
}
switch ( V_10 -> V_34 ) {
case V_35 :
if ( F_5 ( V_2 , V_6 , V_10 -> V_34 ,
F_4 ( V_10 -> V_23 ) & V_27 ,
V_7 + V_10 -> V_29 * 4 , V_11 ) )
return;
break;
case V_36 :
case V_37 :
if ( F_6 ( V_2 , V_6 , V_10 -> V_34 ,
F_4 ( V_10 -> V_23 ) & V_27 ,
V_7 + V_10 -> V_29 * 4 ) )
return;
break;
case V_38 : {
struct V_39 V_40 ;
const struct V_39 * V_41 ;
static const T_1 V_42 [ V_43 + 1 ]
= { [ V_44 ] = 4 ,
[ V_45 ]
= 8 + sizeof( struct V_8 ) ,
[ V_46 ]
= 8 + sizeof( struct V_8 ) ,
[ V_47 ]
= 8 + sizeof( struct V_8 ) ,
[ V_48 ] = 4 ,
[ V_49 ]
= 8 + sizeof( struct V_8 ) ,
[ V_50 ]
= 8 + sizeof( struct V_8 ) ,
[ V_51 ] = 20 ,
[ V_52 ] = 20 ,
[ V_53 ] = 12 ,
[ V_54 ] = 12 } ;
F_3 ( V_2 , L_11 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
V_41 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_40 ) , & V_40 ) ;
if ( V_41 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_55 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_13 , V_41 -> type , V_41 -> V_56 ) ;
if ( V_41 -> type <= V_43 &&
V_42 [ V_41 -> type ] &&
V_6 -> V_55 - V_7 - V_10 -> V_29 * 4 < V_42 [ V_41 -> type ] ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_55 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
switch ( V_41 -> type ) {
case V_44 :
case V_48 :
F_3 ( V_2 , L_14 ,
F_4 ( V_41 -> V_57 . V_58 . V_22 ) ,
F_4 ( V_41 -> V_57 . V_58 . V_59 ) ) ;
break;
case V_50 :
F_3 ( V_2 , L_15 ,
F_7 ( V_41 -> V_57 . V_60 ) >> 24 ) ;
break;
case V_47 :
F_3 ( V_2 , L_16 , & V_41 -> V_57 . V_60 ) ;
case V_45 :
case V_46 :
case V_49 :
if ( ! V_7 ) {
F_3 ( V_2 , L_17 ) ;
F_1 ( V_2 , V_4 , V_6 ,
V_7 + V_10 -> V_29 * 4 + sizeof( V_40 ) ) ;
F_3 ( V_2 , L_18 ) ;
}
if ( V_41 -> type == V_45 &&
V_41 -> V_56 == V_61 ) {
F_3 ( V_2 , L_19 ,
F_4 ( V_41 -> V_57 . V_62 . V_63 ) ) ;
}
}
break;
}
case V_64 : {
struct V_65 V_66 ;
const struct V_65 * V_67 ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
F_3 ( V_2 , L_20 ) ;
V_67 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_66 ) , & V_66 ) ;
if ( V_67 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_55 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_21 , F_7 ( V_67 -> V_68 ) ) ;
break;
}
case V_69 : {
struct V_70 V_71 ;
const struct V_70 * V_72 ;
F_3 ( V_2 , L_22 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
V_72 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_71 ) , & V_71 ) ;
if ( V_72 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_55 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_21 , F_7 ( V_72 -> V_68 ) ) ;
break;
}
default:
F_3 ( V_2 , L_23 , V_10 -> V_34 ) ;
}
if ( ( V_11 & V_73 ) && ! V_7 )
F_8 ( V_2 , V_6 -> V_74 ) ;
if ( ! V_7 && V_6 -> V_75 )
F_3 ( V_2 , L_24 , V_6 -> V_75 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_76 * V_77 = V_6 -> V_77 ;
unsigned int V_11 = 0 ;
if ( V_4 -> type == V_12 )
V_11 = V_4 -> V_13 . log . V_11 ;
if ( ! ( V_11 & V_78 ) )
goto V_79;
switch ( V_77 -> type ) {
case V_80 :
F_3 ( V_2 , L_25 ,
F_10 ( V_6 ) -> V_81 , F_10 ( V_6 ) -> V_82 ,
F_4 ( F_10 ( V_6 ) -> V_83 ) ) ;
return;
default:
break;
}
V_79:
F_3 ( V_2 , L_26 ) ;
if ( V_77 -> V_84 &&
V_6 -> V_85 != V_6 -> V_86 ) {
const unsigned char * V_87 = F_11 ( V_6 ) ;
unsigned int V_32 ;
F_3 ( V_2 , L_27 , * V_87 ++ ) ;
for ( V_32 = 1 ; V_32 < V_77 -> V_84 ; V_32 ++ , V_87 ++ )
F_3 ( V_2 , L_28 , * V_87 ) ;
}
F_3 ( V_2 , L_29 ) ;
}
static void F_12 ( struct V_88 * V_88 , T_2 V_89 ,
unsigned int V_90 , const struct V_5 * V_6 ,
const struct V_76 * V_91 ,
const struct V_76 * V_92 ,
const struct V_3 * V_93 ,
const char * V_94 )
{
struct V_1 * V_2 ;
if ( ! F_13 ( V_88 , & V_95 ) )
return;
V_2 = F_14 () ;
if ( ! V_93 )
V_93 = & V_96 ;
F_15 ( V_2 , V_89 , V_90 , V_6 , V_91 ,
V_92 , V_93 , V_94 ) ;
if ( V_91 != NULL )
F_9 ( V_2 , V_93 , V_6 ) ;
F_1 ( V_2 , V_93 , V_6 , 0 ) ;
F_16 ( V_2 ) ;
}
static int T_3 F_17 ( struct V_88 * V_88 )
{
F_18 ( V_88 , V_97 , & V_98 ) ;
return 0 ;
}
static void T_4 F_19 ( struct V_88 * V_88 )
{
F_20 ( V_88 , & V_98 ) ;
}
static int T_5 F_21 ( void )
{
int V_99 ;
V_99 = F_22 ( & V_100 ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_23 ( V_97 , & V_98 ) ;
if ( V_99 < 0 ) {
F_24 ( L_30 ) ;
goto V_101;
}
return 0 ;
V_101:
F_25 ( & V_100 ) ;
return V_99 ;
}
static void T_6 F_26 ( void )
{
F_25 ( & V_100 ) ;
F_27 ( & V_98 ) ;
}
