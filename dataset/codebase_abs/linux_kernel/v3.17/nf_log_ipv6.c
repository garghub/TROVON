static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 , unsigned int V_7 ,
int V_8 )
{
T_1 V_9 ;
int V_10 ;
struct V_11 V_12 ;
const struct V_11 * V_13 ;
unsigned int V_14 ;
unsigned int V_15 = 0 ;
unsigned int V_16 ;
if ( V_4 -> type == V_17 )
V_16 = V_4 -> V_18 . log . V_16 ;
else
V_16 = V_19 ;
V_13 = F_2 ( V_6 , V_7 , sizeof( V_12 ) , & V_12 ) ;
if ( V_13 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_2 , & V_13 -> V_20 , & V_13 -> V_21 ) ;
F_3 ( V_2 , L_3 ,
F_4 ( V_13 -> V_22 ) + sizeof( struct V_11 ) ,
( F_5 ( * ( V_23 * ) V_13 ) & 0x0ff00000 ) >> 20 ,
V_13 -> V_24 ,
( F_5 ( * ( V_23 * ) V_13 ) & 0x000fffff ) ) ;
V_10 = 0 ;
V_14 = V_7 + sizeof( struct V_11 ) ;
V_9 = V_13 -> V_25 ;
while ( V_9 != V_26 && F_6 ( V_9 ) ) {
struct V_27 V_28 ;
const struct V_27 * V_29 ;
V_29 = F_2 ( V_6 , V_14 , sizeof( V_28 ) , & V_28 ) ;
if ( V_29 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
if ( V_16 & V_30 )
F_3 ( V_2 , L_4 ) ;
switch ( V_9 ) {
case V_31 : {
struct V_32 V_33 ;
const struct V_32 * V_34 ;
F_3 ( V_2 , L_5 ) ;
V_34 = F_2 ( V_6 , V_14 , sizeof( V_33 ) ,
& V_33 ) ;
if ( V_34 == NULL ) {
F_3 ( V_2 , L_6 ) ;
return;
}
F_3 ( V_2 , L_7 , F_4 ( V_34 -> V_35 ) & 0xFFF8 ) ;
if ( V_34 -> V_35 & F_7 ( 0x0001 ) )
F_3 ( V_2 , L_8 ) ;
F_3 ( V_2 , L_9 ,
F_5 ( V_34 -> V_36 ) ) ;
if ( F_4 ( V_34 -> V_35 ) & 0xFFF8 )
V_10 = 1 ;
V_15 = 8 ;
break;
}
case V_37 :
case V_38 :
case V_39 :
if ( V_10 ) {
if ( V_16 & V_30 )
F_3 ( V_2 , L_10 ) ;
return;
}
V_15 = F_8 ( V_29 ) ;
break;
case V_40 :
if ( V_16 & V_30 ) {
struct V_41 V_42 ;
const struct V_41 * V_43 ;
F_3 ( V_2 , L_11 ) ;
if ( V_10 ) {
F_3 ( V_2 , L_10 ) ;
return;
}
V_43 = F_2 ( V_6 , V_14 , sizeof( V_42 ) ,
& V_42 ) ;
if ( V_43 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_13 , F_5 ( V_43 -> V_45 ) ) ;
}
V_15 = ( V_29 -> V_15 + 2 ) << 2 ;
break;
case V_46 :
if ( V_16 & V_30 ) {
struct V_47 V_48 ;
const struct V_47 * V_49 ;
F_3 ( V_2 , L_14 ) ;
if ( V_10 ) {
F_3 ( V_2 , L_10 ) ;
return;
}
V_49 = F_2 ( V_6 , V_14 , sizeof( V_48 ) ,
& V_48 ) ;
if ( V_49 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_15 ,
F_5 ( V_49 -> V_45 ) ) ;
}
return;
default:
F_3 ( V_2 , L_16 , V_9 ) ;
return;
}
if ( V_16 & V_30 )
F_3 ( V_2 , L_17 ) ;
V_9 = V_29 -> V_25 ;
V_14 += V_15 ;
}
switch ( V_9 ) {
case V_50 :
if ( F_9 ( V_2 , V_6 , V_9 , V_10 ,
V_14 , V_16 ) )
return;
break;
case V_51 :
case V_52 :
if ( F_10 ( V_2 , V_6 , V_9 , V_10 , V_14 ) )
return;
break;
case V_53 : {
struct V_54 V_55 ;
const struct V_54 * V_56 ;
F_3 ( V_2 , L_18 ) ;
if ( V_10 )
break;
V_56 = F_2 ( V_6 , V_14 , sizeof( V_55 ) , & V_55 ) ;
if ( V_56 == NULL ) {
F_3 ( V_2 , L_19 ,
V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_20 ,
V_56 -> V_57 , V_56 -> V_58 ) ;
switch ( V_56 -> V_57 ) {
case V_59 :
case V_60 :
F_3 ( V_2 , L_21 ,
F_4 ( V_56 -> V_61 ) ,
F_4 ( V_56 -> V_62 ) ) ;
break;
case V_63 :
case V_64 :
case V_65 :
break;
case V_66 :
F_3 ( V_2 , L_22 ,
F_5 ( V_56 -> V_67 ) ) ;
case V_68 :
case V_69 :
case V_70 :
if ( V_8 ) {
F_3 ( V_2 , L_23 ) ;
F_1 ( V_2 , V_4 , V_6 ,
V_14 + sizeof( V_55 ) , 0 ) ;
F_3 ( V_2 , L_24 ) ;
}
if ( V_56 -> V_57 == V_69 ) {
F_3 ( V_2 , L_25 ,
F_5 ( V_56 -> V_71 ) ) ;
}
}
break;
}
default:
F_3 ( V_2 , L_26 , V_9 ) ;
}
if ( ( V_16 & V_72 ) && V_8 )
F_11 ( V_2 , V_6 -> V_73 ) ;
if ( V_8 && V_6 -> V_74 )
F_3 ( V_2 , L_27 , V_6 -> V_74 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_76 ;
unsigned int V_16 = 0 ;
if ( V_4 -> type == V_17 )
V_16 = V_4 -> V_18 . log . V_16 ;
if ( ! ( V_16 & V_77 ) )
goto V_78;
switch ( V_76 -> type ) {
case V_79 :
F_3 ( V_2 , L_28 ,
F_13 ( V_6 ) -> V_80 , F_13 ( V_6 ) -> V_81 ,
F_4 ( F_13 ( V_6 ) -> V_82 ) ) ;
return;
default:
break;
}
V_78:
F_3 ( V_2 , L_29 ) ;
if ( V_76 -> V_83 &&
V_6 -> V_84 != V_6 -> V_85 ) {
const unsigned char * V_86 = F_14 ( V_6 ) ;
unsigned int V_44 = V_76 -> V_83 ;
unsigned int V_87 ;
if ( V_76 -> type == V_88 ) {
V_86 -= V_89 ;
if ( V_86 < V_6 -> V_90 )
V_86 = NULL ;
}
if ( V_86 != NULL ) {
F_3 ( V_2 , L_30 , * V_86 ++ ) ;
for ( V_87 = 1 ; V_87 < V_44 ; V_87 ++ )
F_3 ( V_2 , L_31 , * V_86 ++ ) ;
}
F_3 ( V_2 , L_32 ) ;
if ( V_76 -> type == V_88 ) {
const struct V_91 * V_92 =
(struct V_91 * ) F_14 ( V_6 ) ;
F_3 ( V_2 , L_33 , & V_92 -> V_20 ,
& V_92 -> V_21 ) ;
}
} else {
F_3 ( V_2 , L_32 ) ;
}
}
static void F_15 ( struct V_93 * V_93 , T_1 V_94 ,
unsigned int V_95 , const struct V_5 * V_6 ,
const struct V_75 * V_96 ,
const struct V_75 * V_97 ,
const struct V_3 * V_98 ,
const char * V_99 )
{
struct V_1 * V_2 ;
if ( ! F_16 ( V_93 , & V_100 ) )
return;
V_2 = F_17 () ;
if ( ! V_98 )
V_98 = & V_101 ;
F_18 ( V_2 , V_94 , V_95 , V_6 , V_96 , V_97 ,
V_98 , V_99 ) ;
if ( V_96 != NULL )
F_12 ( V_2 , V_98 , V_6 ) ;
F_1 ( V_2 , V_98 , V_6 , F_19 ( V_6 ) , 1 ) ;
F_20 ( V_2 ) ;
}
static int T_2 F_21 ( struct V_93 * V_93 )
{
F_22 ( V_93 , V_102 , & V_103 ) ;
return 0 ;
}
static void T_3 F_23 ( struct V_93 * V_93 )
{
F_24 ( V_93 , & V_103 ) ;
}
static int T_4 F_25 ( void )
{
int V_104 ;
V_104 = F_26 ( & V_105 ) ;
if ( V_104 < 0 )
return V_104 ;
F_27 ( V_102 , & V_103 ) ;
return 0 ;
}
static void T_5 F_28 ( void )
{
F_29 ( & V_105 ) ;
F_30 ( & V_103 ) ;
}
