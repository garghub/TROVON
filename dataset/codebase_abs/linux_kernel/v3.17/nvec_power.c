static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
if ( V_3 != V_10 )
return V_11 ;
if ( V_9 -> V_12 == 0 ) {
if ( V_6 -> V_13 != V_9 -> V_14 ) {
V_6 -> V_13 = V_9 -> V_14 ;
F_3 ( & V_15 ) ;
}
return V_16 ;
}
return V_17 ;
}
static void F_4 ( struct V_5 * V_6 )
{
int V_18 ;
char V_19 [] = { V_20 , V_21 } ;
for ( V_18 = 0 ; V_18 < F_5 ( V_22 ) ; V_18 ++ ) {
V_19 [ 1 ] = V_22 [ V_18 ] ;
F_6 ( V_6 -> V_23 , V_19 , 2 ) ;
}
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
int V_24 = 0 ;
if ( V_3 != V_20 )
return V_11 ;
switch ( V_9 -> V_12 ) {
case V_21 :
if ( V_9 -> V_25 [ 0 ] & 1 ) {
if ( V_6 -> V_26 == 0 ) {
V_24 = 1 ;
F_4 ( V_6 ) ;
}
V_6 -> V_26 = 1 ;
switch ( ( V_9 -> V_25 [ 0 ] >> 1 ) & 3 ) {
case 0 :
V_6 -> V_27 =
V_28 ;
break;
case 1 :
V_6 -> V_27 =
V_29 ;
break;
case 2 :
V_6 -> V_27 =
V_30 ;
break;
default:
V_6 -> V_27 = V_31 ;
}
} else {
if ( V_6 -> V_26 == 1 )
V_24 = 1 ;
V_6 -> V_26 = 0 ;
V_6 -> V_27 = V_31 ;
}
V_6 -> V_32 = V_9 -> V_25 [ 1 ] ;
if ( V_24 )
F_3 ( & V_33 ) ;
break;
case V_34 :
V_6 -> V_35 = V_9 -> V_14 * 1000 ;
break;
case V_36 :
V_6 -> V_37 = V_9 -> V_14 * 3600 ;
break;
case V_38 :
V_6 -> V_39 = V_9 -> V_40 * 1000 ;
break;
case V_41 :
V_6 -> V_42 = V_9 -> V_40 * 1000 ;
break;
case V_43 :
V_6 -> V_44 = V_9 -> V_14 * 1000 ;
break;
case V_45 :
V_6 -> V_46 = V_9 -> V_14 * 1000 ;
break;
case V_47 :
V_6 -> V_48 = V_9 -> V_14 * 1000 ;
break;
case V_49 :
V_6 -> V_50 = V_9 -> V_14 * 1000 ;
break;
case V_51 :
V_6 -> V_52 = V_9 -> V_14 - 2732 ;
break;
case V_53 :
memcpy ( V_6 -> V_54 , & V_9 -> V_25 , V_9 -> V_55 - 2 ) ;
V_6 -> V_56 [ V_9 -> V_55 - 2 ] = '\0' ;
break;
case V_57 :
memcpy ( V_6 -> V_56 , & V_9 -> V_25 , V_9 -> V_55 - 2 ) ;
V_6 -> V_56 [ V_9 -> V_55 - 2 ] = '\0' ;
break;
case TYPE :
memcpy ( V_6 -> V_58 , & V_9 -> V_25 , V_9 -> V_55 - 2 ) ;
V_6 -> V_58 [ V_9 -> V_55 - 2 ] = '\0' ;
if ( ! strncmp ( V_6 -> V_58 , L_1 , 30 ) )
V_6 -> V_59 = V_60 ;
else
V_6 -> V_59 = V_61 ;
break;
default:
return V_16 ;
}
return V_16 ;
}
static int F_8 ( struct V_62 * V_63 ,
enum V_64 V_65 ,
union V_66 * V_67 )
{
struct V_5 * V_6 = F_9 ( V_63 -> V_68 -> V_69 ) ;
switch ( V_65 ) {
case V_70 :
V_67 -> V_71 = V_6 -> V_13 ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static int F_10 ( struct V_62 * V_63 ,
enum V_64 V_65 ,
union V_66 * V_67 )
{
struct V_5 * V_6 = F_9 ( V_63 -> V_68 -> V_69 ) ;
switch ( V_65 ) {
case V_73 :
V_67 -> V_71 = V_6 -> V_27 ;
break;
case V_74 :
V_67 -> V_71 = V_6 -> V_32 ;
break;
case V_75 :
V_67 -> V_71 = V_6 -> V_26 ;
break;
case V_76 :
V_67 -> V_71 = V_6 -> V_35 ;
break;
case V_77 :
V_67 -> V_71 = V_6 -> V_39 ;
break;
case V_78 :
V_67 -> V_71 = V_6 -> V_42 ;
break;
case V_79 :
V_67 -> V_71 = V_6 -> V_37 ;
break;
case V_80 :
V_67 -> V_71 = V_6 -> V_48 ;
break;
case V_81 :
V_67 -> V_71 = V_6 -> V_46 ;
break;
case V_82 :
V_67 -> V_71 = V_6 -> V_50 ;
break;
case V_83 :
V_67 -> V_71 = V_6 -> V_44 ;
break;
case V_84 :
V_67 -> V_71 = V_6 -> V_52 ;
break;
case V_85 :
V_67 -> V_86 = V_6 -> V_54 ;
break;
case V_87 :
V_67 -> V_86 = V_6 -> V_56 ;
break;
case V_88 :
V_67 -> V_71 = V_6 -> V_59 ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static void F_11 ( struct V_89 * V_90 )
{
char V_19 [] = { V_10 , V_91 } ;
struct V_5 * V_6 = F_2 ( V_90 , struct V_5 ,
V_92 . V_90 ) ;
if ( V_93 >= F_5 ( V_94 ) )
V_93 = 0 ;
F_6 ( V_6 -> V_23 , V_19 , 2 ) ;
F_12 ( 100 ) ;
V_19 [ 0 ] = V_20 ;
V_19 [ 1 ] = V_94 [ V_93 ++ ] ;
F_6 ( V_6 -> V_23 , V_19 , 2 ) ;
F_13 ( F_14 ( V_90 ) , F_15 ( 5000 ) ) ;
}
static int F_16 ( struct V_95 * V_96 )
{
struct V_62 * V_63 ;
struct V_5 * V_6 ;
struct V_97 * V_23 = F_9 ( V_96 -> V_68 . V_69 ) ;
V_6 = F_17 ( & V_96 -> V_68 , sizeof( struct V_5 ) , V_98 ) ;
if ( V_6 == NULL )
return - V_99 ;
F_18 ( & V_96 -> V_68 , V_6 ) ;
V_6 -> V_23 = V_23 ;
switch ( V_96 -> V_100 ) {
case V_101 :
V_63 = & V_15 ;
V_6 -> V_7 . V_102 = F_1 ;
F_19 ( & V_6 -> V_92 , F_11 ) ;
F_13 ( & V_6 -> V_92 , F_15 ( 5000 ) ) ;
break;
case V_103 :
V_63 = & V_33 ;
V_6 -> V_7 . V_102 = F_7 ;
break;
default:
return - V_104 ;
}
F_20 ( V_23 , & V_6 -> V_7 , V_10 ) ;
if ( V_96 -> V_100 == V_103 )
F_4 ( V_6 ) ;
return F_21 ( & V_96 -> V_68 , V_63 ) ;
}
static int F_22 ( struct V_95 * V_96 )
{
struct V_5 * V_6 = F_23 ( V_96 ) ;
F_24 ( & V_6 -> V_92 ) ;
F_25 ( V_6 -> V_23 , & V_6 -> V_7 ) ;
switch ( V_96 -> V_100 ) {
case V_101 :
F_26 ( & V_15 ) ;
break;
case V_103 :
F_26 ( & V_33 ) ;
}
return 0 ;
}
