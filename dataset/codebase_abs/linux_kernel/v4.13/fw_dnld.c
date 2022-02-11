static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_3 -> V_8 , ( V_9 + V_4 ) , V_10 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_7 = F_4 ( V_5 , V_9 ) ;
V_7 -> V_11 = V_12 ;
V_7 -> V_13 = 0 ;
V_7 -> V_4 = V_4 ;
F_5 ( ( V_14 * ) V_7 , V_15 ) ;
F_6 ( ( V_14 * ) V_7 , V_16 ) ;
return V_5 ;
}
static void F_7 ( struct V_2 * V_3 , T_2 error )
{
if ( V_3 -> V_17 . V_18 ) {
F_8 ( V_3 -> V_17 . V_18 ) ;
V_3 -> V_17 . V_18 = NULL ;
V_3 -> V_17 . V_19 = NULL ;
V_3 -> V_17 . V_20 = NULL ;
}
F_9 ( & V_3 -> V_8 -> V_21 , 0 ) ;
if ( F_10 ( & V_3 -> V_8 -> V_22 ) )
F_11 ( & V_3 -> V_8 -> V_22 ) ;
if ( F_10 ( & V_3 -> V_17 . V_23 ) )
F_11 ( & V_3 -> V_17 . V_23 ) ;
F_12 ( V_3 -> V_24 , L_2 , error ) ;
if ( error != 0 ) {
F_13 ( V_3 ) ;
}
F_14 ( V_3 -> V_8 -> V_25 , V_3 -> V_17 . V_26 , error ) ;
}
static void F_15 ( unsigned long V_27 )
{
struct V_2 * V_3 = (struct V_2 * ) V_27 ;
F_16 ( V_3 -> V_24 , L_3 ) ;
V_3 -> V_17 . V_28 = V_29 ;
F_7 ( V_3 , - V_30 ) ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( sizeof( V_31 ) != V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_31 ,
sizeof( V_31 ) ) )
return - V_34 ;
F_12 ( V_3 -> V_24 , L_4 ) ;
V_3 -> V_17 . V_28 = V_35 ;
F_18 ( V_3 -> V_8 , V_36 , 0 , NULL ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
struct V_37 V_38 ;
if ( sizeof( V_39 ) >= V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_39 ,
sizeof( V_39 ) ) )
return - V_34 ;
V_38 . V_40 = 1 ;
V_38 . V_41 . V_42 = V_43 ;
V_38 . V_41 . V_32 = 4 ;
memcpy ( V_38 . V_41 . V_44 , & V_3 -> V_17 . V_19 -> V_45 , 4 ) ;
F_18 ( V_3 -> V_8 , V_46 , 3 + V_38 . V_41 . V_32 ,
& V_38 ) ;
V_3 -> V_17 . V_28 = V_47 ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
T_1 V_41 [ 2 ] = { V_48 , 0x0 } ;
V_3 -> V_17 . V_28 = V_49 ;
F_18 ( V_3 -> V_8 , V_50 , 2 , V_41 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_37 V_38 ;
if ( sizeof( V_51 ) != V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_51 , V_5 -> V_32 ) )
return - V_34 ;
V_38 . V_40 = 1 ;
V_38 . V_41 . V_42 = V_52 ;
switch ( V_3 -> V_53 ) {
case V_54 :
V_38 . V_41 . V_32 = 5 ;
memcpy ( V_38 . V_41 . V_44 ,
& V_3 -> V_17 . V_20 -> V_55 . V_56 ,
4 ) ;
V_38 . V_41 . V_44 [ 4 ] =
V_3 -> V_17 . V_20 -> V_55 . V_57 ;
break;
case V_58 :
V_38 . V_41 . V_32 = 5 ;
memcpy ( V_38 . V_41 . V_44 ,
& V_3 -> V_17 . V_20 -> V_59 . V_60 ,
4 ) ;
V_38 . V_41 . V_44 [ 4 ] = 0 ;
break;
case V_61 :
V_38 . V_41 . V_32 = 5 ;
memcpy ( V_38 . V_41 . V_44 ,
& V_3 -> V_17 . V_20 -> V_62 . V_60 ,
4 ) ;
V_38 . V_41 . V_44 [ 4 ] = 0 ;
break;
default:
F_20 ( V_3 ) ;
return 0 ;
}
V_3 -> V_17 . V_28 = V_63 ;
F_18 ( V_3 -> V_8 , V_46 , 3 + V_38 . V_41 . V_32 ,
& V_38 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( sizeof( V_51 ) != V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_51 , V_5 -> V_32 ) )
return - V_34 ;
F_20 ( V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( sizeof( V_64 ) >= V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_64 ,
sizeof( V_64 ) ) )
return - V_34 ;
V_3 -> V_17 . V_28 = V_65 ;
V_3 -> V_17 . V_66 = V_67 ;
V_3 -> V_17 . V_68 = V_3 -> V_17 . V_20 -> V_68 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
T_3 V_32 ;
T_3 V_69 ;
struct V_1 * V_70 ;
switch ( V_3 -> V_17 . V_66 ) {
case V_67 :
F_25 ( V_5 , 3 ) ;
if ( V_5 -> V_33 [ 0 ] != V_71 || V_5 -> V_32 != 5 ) {
F_16 ( V_3 -> V_24 , L_5 ) ;
return - V_34 ;
}
F_25 ( V_5 , 1 ) ;
V_32 = F_26 ( V_5 -> V_33 ) ;
F_25 ( V_5 , 2 ) ;
V_69 = F_26 ( V_5 -> V_33 ) ;
memcpy ( & V_69 , V_5 -> V_33 , 2 ) ;
F_25 ( V_5 , 2 ) ;
if ( ( ( ~ V_32 ) & 0xFFFF ) != V_69 ) {
F_16 ( V_3 -> V_24 , L_6 ,
V_32 , V_69 , ( ~ V_32 & 0xFFFF ) ) ;
V_70 = F_1 ( V_3 , 1 ) ;
if ( ! V_70 )
return - V_72 ;
F_27 ( V_70 , 0xBF ) ;
F_28 ( V_3 -> V_8 , V_70 ) ;
V_3 -> V_17 . V_66 = V_73 ;
return 0 ;
}
V_3 -> V_17 . V_74 = V_32 ;
V_70 = F_1 ( V_3 , 1 ) ;
if ( ! V_70 )
return - V_72 ;
F_27 ( V_70 , V_75 ) ;
F_28 ( V_3 -> V_8 , V_70 ) ;
V_3 -> V_17 . V_66 = V_76 ;
break;
case V_76 :
if ( sizeof( V_77 ) != V_5 -> V_32 ||
memcmp ( V_77 , V_5 -> V_33 ,
V_5 -> V_32 ) ) {
F_16 ( V_3 -> V_24 , L_7 ) ;
return - V_34 ;
}
if ( V_3 -> V_17 . V_74 == 0 ) {
T_1 V_11 = V_12 ;
V_3 -> V_17 . V_28 = V_78 ;
F_18 ( V_3 -> V_8 , V_79 ,
1 , & V_11 ) ;
} else {
V_70 = F_1 ( V_3 , V_3 -> V_17 . V_74 ) ;
if ( ! V_70 )
return - V_72 ;
F_29 ( V_70 ,
( ( T_1 * ) V_3 -> V_17 . V_18 -> V_33 ) + V_3 -> V_17 . V_68 ,
V_3 -> V_17 . V_74 ) ;
F_28 ( V_3 -> V_8 , V_70 ) ;
V_3 -> V_17 . V_66 = V_80 ;
}
break;
case V_80 :
if ( sizeof( V_77 ) != V_5 -> V_32 ||
memcmp ( V_77 , V_5 -> V_33 ,
V_5 -> V_32 ) ) {
F_16 ( V_3 -> V_24 , L_7 ) ;
return - V_34 ;
}
V_3 -> V_17 . V_68 += V_3 -> V_17 . V_74 ;
V_3 -> V_17 . V_74 = 0 ;
V_3 -> V_17 . V_66 = V_67 ;
break;
case V_73 :
if ( sizeof( V_77 ) != V_5 -> V_32 ||
memcmp ( V_77 , V_5 -> V_33 ,
V_5 -> V_32 ) ) {
F_16 ( V_3 -> V_24 , L_7 ) ;
return - V_34 ;
}
V_3 -> V_17 . V_66 = V_67 ;
break;
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( sizeof( V_81 ) != V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_81 , V_5 -> V_32 ) )
return - V_34 ;
V_3 -> V_17 . V_28 = V_82 ;
F_18 ( V_3 -> V_8 , V_83 , 0 , NULL ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
if ( sizeof( V_84 ) != V_5 -> V_32 ||
memcmp ( V_5 -> V_33 , V_84 , V_5 -> V_32 ) )
return - V_34 ;
V_3 -> V_85 -> V_86 ( V_3 ,
& V_3 -> V_17 . V_20 -> V_87 ) ;
if ( V_3 -> V_17 . V_20 == & V_3 -> V_17 . V_19 -> V_88 ) {
V_3 -> V_17 . V_28 = V_29 ;
V_3 -> V_17 . V_20 = & V_3 -> V_17 . V_19 -> V_89 ;
F_12 ( V_3 -> V_24 , L_8 ) ;
} else {
F_12 ( V_3 -> V_24 , L_9 ) ;
F_7 ( V_3 , 0 ) ;
}
return 0 ;
}
static void F_32 ( struct V_90 * V_91 )
{
int V_92 ;
struct V_1 * V_5 ;
struct V_93 * V_17 = F_33 ( V_91 ,
struct V_93 ,
V_94 ) ;
struct V_2 * V_3 = F_33 ( V_17 ,
struct V_2 ,
V_17 ) ;
while ( ( V_5 = F_34 ( & V_17 -> V_95 ) ) ) {
F_35 ( V_3 -> V_8 -> V_25 , V_5 ,
V_96 , V_97 ) ;
switch ( V_17 -> V_28 ) {
case V_29 :
V_92 = F_17 ( V_3 , V_5 ) ;
break;
case V_35 :
V_92 = F_19 ( V_3 , V_5 ) ;
break;
case V_47 :
V_92 = F_21 ( V_3 , V_5 ) ;
break;
case V_63 :
V_92 = F_22 ( V_3 , V_5 ) ;
break;
case V_49 :
V_92 = F_23 ( V_3 , V_5 ) ;
break;
case V_65 :
V_92 = F_24 ( V_3 , V_5 ) ;
break;
case V_78 :
V_92 = F_30 ( V_3 , V_5 ) ;
break;
case V_82 :
V_92 = F_31 ( V_3 , V_5 ) ;
break;
default:
V_92 = - V_98 ;
}
F_36 ( V_5 ) ;
if ( V_92 != 0 ) {
F_16 ( V_3 -> V_24 , L_10 ) ;
F_7 ( V_3 , V_92 ) ;
break;
}
}
}
int F_37 ( struct V_2 * V_3 )
{
char V_26 [ 32 ] ;
F_38 ( & V_3 -> V_17 . V_94 , F_32 ) ;
snprintf ( V_26 , sizeof( V_26 ) , L_11 ,
F_39 ( & V_3 -> V_8 -> V_25 -> V_24 ) ) ;
V_3 -> V_17 . V_99 = F_40 ( V_26 ) ;
if ( ! V_3 -> V_17 . V_99 )
return - V_72 ;
F_41 ( & V_3 -> V_17 . V_95 ) ;
return 0 ;
}
void F_42 ( struct V_2 * V_3 )
{
F_43 ( V_3 -> V_17 . V_99 ) ;
}
void F_44 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( F_10 ( & V_3 -> V_8 -> V_22 ) )
F_11 ( & V_3 -> V_8 -> V_22 ) ;
F_9 ( & V_3 -> V_8 -> V_21 , 1 ) ;
F_45 ( & V_3 -> V_17 . V_95 , V_5 ) ;
F_46 ( V_3 -> V_17 . V_99 , & V_3 -> V_17 . V_94 ) ;
}
void F_47 ( struct V_2 * V_3 )
{
F_7 ( V_3 , - V_100 ) ;
}
int F_48 ( struct V_101 * V_8 , const char * V_102 )
{
struct V_2 * V_3 = F_49 ( V_8 ) ;
struct V_93 * V_17 = & V_3 -> V_17 ;
int V_103 ;
if ( ! V_3 -> V_104 )
return - V_105 ;
if ( ! V_102 || ! V_102 [ 0 ] )
return - V_34 ;
strcpy ( V_17 -> V_26 , V_102 ) ;
V_103 = F_50 ( & V_17 -> V_18 , V_102 ,
& V_8 -> V_25 -> V_24 ) ;
if ( V_103 < 0 ) {
F_16 ( V_3 -> V_24 , L_12 , V_102 ) ;
return - V_106 ;
}
V_17 -> V_19 = ( const struct V_107 * ) V_3 -> V_17 . V_18 -> V_33 ;
if ( V_17 -> V_19 -> V_108 != V_109 ||
V_17 -> V_19 -> V_53 != V_3 -> V_53 ) {
F_16 ( V_3 -> V_24 , L_13 ,
V_102 , V_17 -> V_19 -> V_108 ,
V_17 -> V_19 -> V_53 ) ;
F_8 ( V_17 -> V_18 ) ;
V_17 -> V_19 = NULL ;
return - V_34 ;
}
if ( V_17 -> V_19 -> V_88 . V_68 != 0 ) {
F_12 ( V_3 -> V_24 , L_14 ) ;
V_17 -> V_20 = & V_17 -> V_19 -> V_88 ;
} else {
F_12 ( V_3 -> V_24 , L_15 ) ;
V_17 -> V_20 = & V_17 -> V_19 -> V_89 ;
}
F_51 ( & V_3 -> V_17 . V_23 , F_15 ,
( unsigned long ) V_3 ) ;
F_52 ( & V_3 -> V_17 . V_23 ,
V_110 + F_53 ( V_111 ) ) ;
V_3 -> V_85 -> V_86 ( V_3 ,
& V_17 -> V_19 -> V_112 . V_87 ) ;
F_9 ( & V_3 -> V_8 -> V_21 , 1 ) ;
V_3 -> V_17 . V_28 = V_29 ;
F_54 ( V_3 ) ;
return 0 ;
}
