static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
unsigned short V_12 ;
int V_13 , V_14 = 0 ;
if ( ! V_6 -> V_15 )
return - V_16 ;
if ( V_4 -> V_17 . V_18 . V_19 [ 0 ] >= V_10 -> V_20 )
return - V_21 ;
F_3 ( & V_6 -> V_22 ) ;
V_12 = V_23 [ V_4 -> V_17 . V_18 . V_19 [ 0 ] ] ;
V_13 = ! ! ( V_12 & ( 1 << V_24 ) ) ;
if ( V_13 != F_4 ( V_8 , L_1 ) ) {
V_14 = 1 ;
if ( V_13 )
F_5 ( V_8 , L_1 ) ;
else
F_6 ( V_8 , L_1 ) ;
}
V_13 = ! ! ( V_12 & ( 1 << V_25 ) ) ;
if ( V_13 != F_4 ( V_8 , L_2 ) ) {
V_14 = 1 ;
if ( V_13 )
F_5 ( V_8 , L_2 ) ;
else
F_6 ( V_8 , L_2 ) ;
}
V_13 = ! ! ( V_12 & ( 1 << V_26 ) ) ;
if ( V_13 != F_4 ( V_8 , L_3 ) ) {
V_14 = 1 ;
if ( V_13 )
F_5 ( V_8 , L_3 ) ;
else
F_6 ( V_8 , L_3 ) ;
}
V_13 = ! ! ( V_12 & ( 1 << V_27 ) ) ;
if ( V_13 != F_4 ( V_8 , L_4 ) ) {
V_14 = 1 ;
if ( V_13 )
F_5 ( V_8 , L_4 ) ;
else
F_6 ( V_8 , L_4 ) ;
}
V_13 = ! ! ( V_12 & ( 1 << V_28 ) ) ;
if ( V_13 != V_29 ) {
V_29 = V_13 ;
V_14 = 1 ;
if ( V_13 )
F_5 ( V_8 , L_5 ) ;
else
F_6 ( V_8 , L_5 ) ;
}
if ( V_14 )
F_7 ( V_8 ) ;
F_8 ( & V_6 -> V_22 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_8 ;
unsigned short V_12 , V_30 ;
V_12 = ( ( F_4 ( V_8 , L_1 ) <<
V_24 ) |
( F_4 ( V_8 , L_2 ) <<
V_25 ) ) ;
if ( V_12 )
V_12 |= ( F_4 ( V_8 , L_3 ) <<
V_26 ) ;
else
V_12 = ( ( F_4 ( V_8 , L_3 ) <<
V_26 ) |
( F_4 ( V_8 , L_4 ) <<
V_27 ) |
( V_29 << V_28 ) ) ;
for ( V_30 = 0 ; V_30 < F_10 ( V_31 ) ; V_30 ++ )
if ( V_12 == V_23 [ V_30 ] )
break;
if ( V_30 >= F_10 ( V_31 ) )
return - V_21 ;
V_4 -> V_17 . V_18 . V_19 [ 0 ] = V_30 ;
return 0 ;
}
static void F_11 ( unsigned long V_32 )
{
int V_33 ;
F_12 ( & V_34 ) ;
V_35 = 0 ;
V_33 = V_36 ;
F_13 ( & V_34 ) ;
if ( ! V_33 )
F_14 ( V_37 , 0 ) ;
}
static int F_15 ( struct V_38 * V_39 )
{
int V_40 ;
if ( ! V_41 )
return - V_42 ;
V_39 -> V_43 = V_41 ;
V_40 = V_44 . V_45 ( V_39 ) ;
if ( V_40 < 0 )
V_39 -> V_43 = NULL ;
return V_40 ;
}
static void F_16 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_43 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
F_17 ( & V_46 ) ;
F_18 ( & V_47 . V_12 ) ;
if ( ! V_6 )
return;
V_44 . V_48 ( V_39 ) ;
F_6 ( V_8 , L_1 ) ;
F_5 ( V_8 , L_2 ) ;
F_5 ( V_8 , L_3 ) ;
F_6 ( V_8 , L_4 ) ;
F_6 ( V_8 , L_5 ) ;
F_7 ( V_8 ) ;
}
static int F_19 ( struct V_38 * V_39 )
{
F_16 ( V_39 ) ;
return 0 ;
}
static void F_20 ( struct V_38 * V_39 ,
const unsigned char * V_49 , char * V_50 , int V_51 )
{
struct V_5 * V_6 = V_39 -> V_43 ;
const unsigned char * V_52 ;
int V_53 , V_40 ;
if ( ! V_6 )
return;
if ( ! V_6 -> V_15 ) {
F_21 ( & V_46 , F_11 , 0 ) ;
V_44 . V_54 ( V_39 , V_49 , V_50 , V_51 ) ;
V_40 = F_22 ( & V_47 ,
F_10 ( V_55 ) ,
V_55 ) ;
if ( V_40 )
F_23 ( V_6 -> V_56 ,
L_6
L_7 ) ;
return;
}
V_44 . V_54 ( V_39 , V_49 , V_50 , V_51 ) ;
for ( V_52 = & V_49 [ V_51 - 1 ] ; V_52 >= V_49 ; V_52 -- ) {
if ( * V_52 != '\r' )
continue;
F_24 ( & V_34 ) ;
F_25 ( & V_46 , V_57 + F_26 ( 150 ) ) ;
V_53 = ! V_36 && ! V_35 ;
V_35 = 1 ;
F_27 ( & V_34 ) ;
if ( V_53 )
F_14 ( V_37 ,
V_37 ) ;
break;
}
}
static void F_28 ( struct V_38 * V_39 )
{
V_44 . V_58 ( V_39 ) ;
}
static int F_29 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
return F_30 ( V_64 -> V_66 ,
V_67 |
V_68 |
V_69 ) ;
}
static int F_31 ( struct V_70 * V_71 ,
struct V_7 * V_8 ,
enum V_72 V_73 )
{
switch ( V_73 ) {
case V_74 :
case V_75 :
case V_76 :
if ( V_71 -> V_8 . V_77 == V_78 )
F_14 ( V_79 ,
V_79 ) ;
break;
case V_78 :
if ( V_71 -> V_8 . V_77 != V_78 )
F_14 ( V_79 ,
0 ) ;
}
V_71 -> V_8 . V_77 = V_73 ;
return 0 ;
}
static int F_32 ( struct V_80 * V_81 , int V_82 )
{
int V_53 ;
if ( V_36 == V_82 )
return 0 ;
F_24 ( & V_34 ) ;
V_36 = V_82 ;
V_53 = ! V_35 ;
F_27 ( & V_34 ) ;
if ( V_53 )
F_14 ( V_37 ,
V_82 ? V_37 : 0 ) ;
return 0 ;
}
static int F_33 ( struct V_59 * V_60 )
{
return F_32 ( NULL , 0 ) ;
}
static void F_34 ( struct V_59 * V_60 )
{
F_32 ( NULL , 1 ) ;
}
static int F_35 ( struct V_63 * V_64 )
{
struct V_5 * V_6 = V_64 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_80 * V_83 = V_64 -> V_83 ;
struct V_70 * V_71 = V_64 -> V_71 ;
int V_40 ;
V_41 = V_6 ;
if ( ! V_83 -> V_84 -> V_85 ) {
V_83 -> V_84 -> V_85 = & V_86 ;
} else {
V_87 . V_88 = F_33 ;
V_87 . V_89 = F_34 ;
}
F_31 ( V_71 , V_8 , V_76 ) ;
V_40 = F_36 ( V_64 -> V_6 , L_8 ,
V_90 , & V_47 ) ;
if ( V_40 )
F_23 ( V_71 -> V_56 ,
L_9
L_10 ) ;
else {
V_40 = F_37 ( & V_47 ,
F_10 ( V_91 ) ,
V_91 ) ;
if ( V_40 )
F_23 ( V_71 -> V_56 ,
L_11
L_12 ) ;
}
V_40 = F_38 ( V_92 , & V_93 ) ;
if ( V_40 ) {
F_23 ( V_71 -> V_56 ,
L_13
L_14 ) ;
return 0 ;
}
V_40 = F_39 ( V_8 , V_94 ,
F_10 ( V_94 ) ) ;
if ( V_40 ) {
F_23 ( V_71 -> V_56 ,
L_15
L_16 ) ;
return 0 ;
}
V_40 = F_40 ( V_8 , V_95 ,
F_10 ( V_95 ) ) ;
if ( V_40 ) {
F_23 ( V_71 -> V_56 ,
L_17
L_18 ) ;
return 0 ;
}
F_6 ( V_8 , L_1 ) ;
F_5 ( V_8 , L_2 ) ;
F_5 ( V_8 , L_3 ) ;
F_6 ( V_8 , L_4 ) ;
F_6 ( V_8 , L_5 ) ;
F_6 ( V_8 , L_19 ) ;
V_40 = F_41 ( V_6 , V_96 ,
F_10 ( V_96 ) ) ;
if ( V_40 )
F_23 ( V_71 -> V_56 ,
L_20
L_21 ) ;
return 0 ;
}
static int T_1 F_42 ( void )
{
int V_40 ;
if ( ! ( F_43 () ) )
return - V_42 ;
V_97 =
F_44 ( L_22 , - 1 ) ;
if ( ! V_97 )
return - V_98 ;
F_45 ( V_97 ,
& V_99 ) ;
V_40 = F_46 ( V_97 ) ;
if ( V_40 )
goto V_100;
V_101 =
F_47 ( L_23 , - 1 , NULL , 0 ) ;
return 0 ;
V_100:
F_48 ( V_97 ) ;
return V_40 ;
}
static void T_2 F_49 ( void )
{
if ( F_50 ( V_92 ) != 0 )
F_23 ( & V_97 -> V_56 ,
L_24 ) ;
F_51 ( & V_47 ,
F_10 ( V_91 ) ,
V_91 ) ;
F_31 ( & V_99 ,
& V_99 . V_64 [ 0 ] . V_6 -> V_8 ,
V_76 ) ;
F_52 ( V_101 ) ;
F_52 ( V_97 ) ;
}
