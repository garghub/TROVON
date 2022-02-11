static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_9 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_12 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_17 [ V_12 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_12 = F_5 ( V_2 , & V_11 -> V_13 ) ;
return F_7 ( V_6 , V_8 -> V_9 , V_11 ,
V_8 -> V_18 [ V_12 ] , & V_8 -> V_17 [ V_12 ] ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_9 ( V_6 , V_4 , V_8 -> V_19 ,
V_8 -> V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_11 ( V_6 , V_11 , V_8 -> V_19 ,
V_8 -> V_20 , V_8 -> V_21 . V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_13 ( V_6 , V_11 , V_8 -> V_19 ,
V_8 -> V_20 , & V_8 -> V_21 . V_22 ) ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_23 ;
int V_24 , V_25 ;
V_25 = F_15 ( V_6 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_19 ) {
V_25 = F_15 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_21 . V_28 ) {
V_25 = F_16 ( V_6 , V_8 -> V_21 . V_28 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_17 ( V_6 ,
& V_8 -> V_21 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_21 . V_29 = 1 ;
}
if ( V_8 -> V_30 ) {
V_25 = F_18 ( V_6 , V_8 -> V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_23 = F_19 ( V_6 , L_1 ) ;
for ( V_24 = 0 ; V_23 && V_24 < V_23 -> V_31 ; V_24 ++ ) {
V_25 = F_20 ( V_6 , V_23 , V_24 , V_8 -> V_18 [ V_24 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , const struct V_32 * V_33 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_34 ;
int V_35 [ 4 ] ;
int V_24 , V_36 ;
memset ( V_8 -> V_37 , 0 , sizeof( V_8 -> V_37 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
for ( V_24 = 0 ; V_24 < V_33 -> V_38 ; V_24 ++ ) {
V_34 = V_33 -> V_39 [ V_24 ] ;
if ( V_34 >= 0x0b && V_34 <= 0x0e ) {
V_8 -> V_37 [ V_24 ] = ( V_34 - 0x0b ) + 0x03 ;
V_35 [ V_34 - 0x0b ] = 1 ;
}
}
for ( V_24 = 0 ; V_24 < V_33 -> V_38 ; V_24 ++ ) {
V_34 = V_33 -> V_39 [ V_24 ] ;
if ( V_34 <= 0x0e )
continue;
for ( V_36 = 0 ; V_36 < V_33 -> V_38 ; V_36 ++ ) {
if ( ! V_35 [ V_36 ] ) {
V_8 -> V_37 [ V_24 ] = V_36 + 0x03 ;
V_35 [ V_36 ] = 1 ;
break;
}
}
}
V_8 -> V_40 = V_33 -> V_38 ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 , const struct V_32 * V_33 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_34 ;
int V_24 , V_36 , V_41 , V_42 ;
memset ( V_8 -> V_43 , 0 , sizeof( V_8 -> V_43 ) ) ;
for ( V_36 = 0 , V_24 = 0 ; V_24 < V_33 -> V_38 ; V_24 ++ ) {
T_1 V_44 [ 4 ] ;
V_34 = V_33 -> V_39 [ V_24 ] ;
V_8 -> V_43 [ V_36 ] . V_34 = V_34 ;
V_8 -> V_43 [ V_36 ] . V_45 = V_46 ;
V_8 -> V_43 [ V_36 ] . V_47 = V_48 ;
V_36 ++ ;
if ( V_34 > 0x0e ) {
V_8 -> V_43 [ V_36 ] . V_34 = V_34 ;
V_8 -> V_43 [ V_36 ] . V_45 = V_49 ;
V_8 -> V_43 [ V_36 ] . V_47 = 0 ;
V_42 = F_23 ( V_6 , V_34 , V_44 , 4 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
if ( V_44 [ V_41 ] == V_8 -> V_37 [ V_24 ] ) {
V_8 -> V_43 [ V_36 ] . V_47 = V_41 ;
break;
}
V_36 ++ ;
}
}
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_50 == V_51 )
F_25 ( V_6 , V_52 ) ;
else
F_25 ( V_6 , V_53 ) ;
if ( V_8 -> V_50 == V_54 )
F_25 ( V_6 , V_8 -> V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_27 ( V_6 , & V_8 -> V_21 , V_58 ,
V_56 ) ;
}
static int F_28 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
unsigned int V_59 ,
unsigned int V_60 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_29 ( V_6 , & V_8 -> V_21 , V_59 ,
V_60 , V_58 ) ;
}
static int F_30 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_31 ( V_6 , & V_8 -> V_21 ) ;
}
static int F_32 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_33 ( V_6 , & V_8 -> V_21 ) ;
}
static int F_34 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_35 ( V_6 , & V_8 -> V_21 ) ;
}
static int F_36 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
unsigned int V_59 ,
unsigned int V_60 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_37 ( V_6 , & V_8 -> V_21 , V_59 ,
V_60 , V_58 ) ;
}
static int F_38 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
unsigned int V_59 ,
unsigned int V_60 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_39 ( V_6 , V_8 -> V_18 [ V_58 -> V_61 ] ,
V_59 , 0 , V_60 ) ;
return 0 ;
}
static int F_40 ( struct V_55 * V_56 ,
struct V_5 * V_6 ,
struct V_57 * V_58 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_41 ( V_6 , V_8 -> V_18 [ V_58 -> V_61 ] ) ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_62 * V_63 = V_8 -> V_64 ;
V_6 -> V_65 = 1 ;
V_6 -> V_66 = V_63 ;
V_63 -> V_67 = L_2 ;
V_63 -> V_68 [ V_69 ] = V_70 ;
V_63 -> V_68 [ V_71 ] = V_72 ;
if ( V_8 -> V_21 . V_28 || V_8 -> V_30 ) {
V_6 -> V_65 ++ ;
V_63 ++ ;
V_63 -> V_67 = L_3 ;
V_63 -> V_73 = V_74 ;
if ( V_8 -> V_21 . V_28 ) {
V_63 -> V_68 [ V_69 ] = V_75 ;
V_63 -> V_68 [ V_69 ] . V_34 = V_8 -> V_21 . V_28 ;
}
if ( V_8 -> V_30 ) {
V_63 -> V_68 [ V_71 ] = V_76 ;
V_63 -> V_68 [ V_71 ] . V_34 = V_8 -> V_30 ;
}
}
return 0 ;
}
static void F_43 ( struct V_5 * V_6 )
{
F_44 ( V_6 -> V_8 ) ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_46 ( sizeof( * V_8 ) , V_77 ) ;
if ( V_8 == NULL )
return - V_78 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_50 = F_47 ( V_6 , V_79 ,
V_80 ,
V_81 ) ;
if ( V_8 -> V_50 < 0 ) {
F_48 ( V_82 L_4 ,
V_6 -> V_83 ) ;
V_8 -> V_50 = V_54 ;
}
memcpy ( V_8 -> V_37 , V_84 , sizeof( V_8 -> V_37 ) ) ;
V_8 -> V_40 = 4 ;
switch ( V_8 -> V_50 ) {
case V_85 :
case V_86 :
V_8 -> V_19 = V_87 ;
if ( V_8 -> V_50 == V_85 )
V_8 -> V_20 = 2 ;
else {
V_8 -> V_88 = 1 ;
V_8 -> V_20 = 3 ;
}
V_8 -> V_21 . V_22 = V_87 [ 0 ] . V_89 ;
V_8 -> V_9 = & V_90 ;
break;
case V_91 :
case V_92 :
V_8 -> V_88 = 1 ;
V_8 -> V_21 . V_22 = 8 ;
V_8 -> V_9 = & V_90 ;
if ( V_8 -> V_50 == V_92 ) {
V_8 -> V_21 . V_28 = V_93 ;
V_8 -> V_30 = V_94 ;
}
break;
case V_51 :
V_8 -> V_88 = 1 ;
V_8 -> V_21 . V_22 = 8 ;
V_8 -> V_95 = 1 ;
V_8 -> V_9 = & V_96 ;
V_8 -> V_21 . V_28 = V_93 ;
break;
case V_54 :
{
unsigned int V_97 , V_98 , V_99 , V_100 ;
unsigned int V_101 , V_102 ;
struct V_32 V_33 ;
V_97 = F_49 ( V_6 , 0x0f ) ;
V_98 = F_49 ( V_6 , 0x10 ) ;
V_8 -> V_88 = 1 ;
if ( F_50 ( V_97 ) == V_103 ||
F_50 ( V_98 ) == V_103 ) {
V_99 = F_49 ( V_6 , 0x1f ) ;
V_100 = F_49 ( V_6 , 0x20 ) ;
V_8 -> V_19 = V_87 ;
if ( F_50 ( V_99 ) == V_103 ||
F_50 ( V_100 ) == V_103 ) {
V_8 -> V_50 = V_85 ;
V_8 -> V_88 = 0 ;
V_8 -> V_20 = 2 ;
} else {
V_8 -> V_50 = V_86 ;
V_8 -> V_20 = 3 ;
}
V_8 -> V_9 = & V_90 ;
V_8 -> V_21 . V_22 = V_87 [ 0 ] . V_89 ;
} else {
V_8 -> V_9 = & V_90 ;
V_101 = F_49 ( V_6 , 0x13 ) ;
V_102 = F_49 ( V_6 , 0x12 ) ;
if ( F_50 ( V_102 ) != V_103 )
V_8 -> V_21 . V_28 = V_93 ;
if ( F_50 ( V_101 ) != V_103 )
V_8 -> V_30 = V_94 ;
V_8 -> V_21 . V_22 = 8 ;
}
F_51 ( V_6 , & V_33 , NULL ) ;
if ( V_33 . V_38 ) {
V_8 -> V_21 . V_22 = V_33 . V_38 * 2 ;
F_21 ( V_6 , & V_33 ) ;
F_22 ( V_6 , & V_33 ) ;
} else
F_52 ( L_5 ) ;
break;
}
}
V_8 -> V_21 . V_40 = V_8 -> V_40 ;
V_8 -> V_21 . V_37 = V_8 -> V_37 ;
V_8 -> V_18 = V_104 ;
V_6 -> V_105 = V_106 ;
return 0 ;
}
static int T_2 F_53 ( void )
{
return F_54 ( & V_107 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_107 ) ;
}
