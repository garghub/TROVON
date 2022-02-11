static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_5 . V_6 = V_2 -> V_6 ;
switch ( V_2 -> V_7 ) {
case V_8 :
V_4 -> V_9 . V_10 = V_11 ;
break;
case V_12 :
V_4 -> V_9 . V_10 = V_2 -> V_10 ;
V_4 -> V_9 . V_6 = V_2 -> V_6 ;
break;
}
V_4 -> type = V_13 ;
}
static int F_2 ( struct V_14 * V_15 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char V_16 [ 4 ] ;
int V_17 ;
F_3 ( & V_15 -> V_18 ) ;
F_4 (vmidi, &rdev->filelist, list) {
if ( ! V_2 -> V_19 )
continue;
if ( V_4 -> type == V_20 ) {
if ( ( V_4 -> V_21 & V_22 ) != V_23 )
continue;
F_5 ( V_4 , ( V_24 ) V_25 , V_2 -> V_26 ) ;
} else {
V_17 = F_6 ( V_2 -> V_27 , V_16 , sizeof( V_16 ) , V_4 ) ;
if ( V_17 > 0 )
V_25 ( V_2 -> V_26 , V_16 , V_17 ) ;
}
}
F_7 ( & V_15 -> V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 , int V_28 ,
void * V_29 , int V_30 , int V_31 )
{
struct V_14 * V_15 ;
V_15 = V_29 ;
if ( ! ( V_15 -> V_21 & V_32 ) )
return 0 ;
return F_2 ( V_15 , V_4 ) ;
}
static void F_9 ( struct V_33 * V_26 , int V_34 )
{
struct V_1 * V_2 = V_26 -> V_35 -> V_29 ;
if ( V_34 ) {
V_2 -> V_19 = 1 ;
} else {
V_2 -> V_19 = 0 ;
}
}
static void F_10 ( struct V_33 * V_26 , int V_34 )
{
struct V_1 * V_2 = V_26 -> V_35 -> V_29 ;
int V_36 , V_37 ;
unsigned char V_38 [ 32 ] , * V_39 ;
unsigned long V_21 ;
if ( V_34 ) {
V_2 -> V_19 = 1 ;
if ( V_2 -> V_7 == V_8 &&
! ( V_2 -> V_15 -> V_21 & V_40 ) ) {
while ( F_11 ( V_26 , V_38 ,
sizeof( V_38 ) ) > 0 ) {
}
return;
}
if ( V_2 -> V_41 . type != V_13 ) {
if ( F_12 ( V_2 -> V_10 , & V_2 -> V_41 , F_13 () , 0 ) < 0 )
return;
V_2 -> V_41 . type = V_13 ;
}
F_14 ( & V_26 -> V_35 -> V_42 , V_21 ) ;
while ( 1 ) {
V_36 = F_15 ( V_26 , V_38 , sizeof( V_38 ) ) ;
if ( V_36 <= 0 )
break;
V_39 = V_38 ;
while ( V_36 > 0 ) {
V_37 = F_16 ( V_2 -> V_27 , V_39 , V_36 , & V_2 -> V_41 ) ;
if ( V_37 < 0 ) {
F_17 ( V_2 -> V_27 ) ;
continue;
}
F_18 ( V_26 , V_37 ) ;
V_39 += V_37 ;
V_36 -= V_37 ;
if ( V_2 -> V_41 . type != V_13 ) {
if ( F_12 ( V_2 -> V_10 , & V_2 -> V_41 , F_13 () , 0 ) < 0 )
goto V_43;
V_2 -> V_41 . type = V_13 ;
}
}
}
V_43:
F_19 ( & V_26 -> V_35 -> V_42 , V_21 ) ;
} else {
V_2 -> V_19 = 0 ;
}
}
static int F_20 ( struct V_33 * V_26 )
{
struct V_14 * V_15 = V_26 -> V_44 -> V_29 ;
struct V_45 * V_35 = V_26 -> V_35 ;
struct V_1 * V_2 ;
unsigned long V_21 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_46 ) ;
if ( V_2 == NULL )
return - V_47 ;
V_2 -> V_26 = V_26 ;
if ( F_22 ( 0 , & V_2 -> V_27 ) < 0 ) {
F_23 ( V_2 ) ;
return - V_47 ;
}
V_2 -> V_7 = V_15 -> V_7 ;
V_2 -> V_10 = V_15 -> V_10 ;
V_2 -> V_6 = V_15 -> V_6 ;
V_35 -> V_29 = V_2 ;
F_24 ( & V_15 -> V_18 , V_21 ) ;
F_25 ( & V_2 -> V_48 , & V_15 -> V_49 ) ;
F_26 ( & V_15 -> V_18 , V_21 ) ;
V_2 -> V_15 = V_15 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_26 )
{
struct V_14 * V_15 = V_26 -> V_44 -> V_29 ;
struct V_45 * V_35 = V_26 -> V_35 ;
struct V_1 * V_2 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_46 ) ;
if ( V_2 == NULL )
return - V_47 ;
V_2 -> V_26 = V_26 ;
if ( F_22 ( V_50 , & V_2 -> V_27 ) < 0 ) {
F_23 ( V_2 ) ;
return - V_47 ;
}
V_2 -> V_7 = V_15 -> V_7 ;
V_2 -> V_10 = V_15 -> V_10 ;
V_2 -> V_6 = V_15 -> V_6 ;
F_1 ( V_2 , & V_2 -> V_41 ) ;
V_2 -> V_15 = V_15 ;
V_35 -> V_29 = V_2 ;
return 0 ;
}
static int F_28 ( struct V_33 * V_26 )
{
struct V_14 * V_15 = V_26 -> V_44 -> V_29 ;
struct V_1 * V_2 = V_26 -> V_35 -> V_29 ;
F_29 ( & V_15 -> V_18 ) ;
F_30 ( & V_2 -> V_48 ) ;
F_31 ( & V_15 -> V_18 ) ;
F_32 ( V_2 -> V_27 ) ;
V_26 -> V_35 -> V_29 = NULL ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_35 -> V_29 ;
F_32 ( V_2 -> V_27 ) ;
V_26 -> V_35 -> V_29 = NULL ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_34 ( void * V_29 ,
struct V_51 * V_52 )
{
struct V_14 * V_15 ;
V_15 = V_29 ;
if ( ! F_35 ( V_15 -> V_53 -> V_54 ) )
return - V_55 ;
V_15 -> V_21 |= V_40 ;
return 0 ;
}
static int F_36 ( void * V_29 ,
struct V_51 * V_52 )
{
struct V_14 * V_15 ;
V_15 = V_29 ;
V_15 -> V_21 &= ~ V_40 ;
F_37 ( V_15 -> V_53 -> V_54 ) ;
return 0 ;
}
static int F_38 ( void * V_29 ,
struct V_51 * V_52 )
{
struct V_14 * V_15 ;
V_15 = V_29 ;
if ( ! F_35 ( V_15 -> V_53 -> V_54 ) )
return - V_55 ;
V_15 -> V_21 |= V_32 ;
return 0 ;
}
static int F_39 ( void * V_29 ,
struct V_51 * V_52 )
{
struct V_14 * V_15 ;
V_15 = V_29 ;
V_15 -> V_21 &= ~ V_32 ;
F_37 ( V_15 -> V_53 -> V_54 ) ;
return 0 ;
}
static int F_40 ( struct V_14 * V_15 )
{
int V_10 ;
struct V_56 V_57 ;
struct V_58 * V_59 ;
int V_60 ;
if ( V_15 -> V_10 >= 0 )
return 0 ;
V_59 = F_21 ( sizeof( * V_59 ) , V_46 ) ;
if ( ! V_59 ) {
V_60 = - V_47 ;
goto V_61;
}
V_10 = F_41 ( V_15 -> V_53 , V_15 -> V_62 ,
L_1 , V_15 -> V_44 -> V_63 ,
V_15 -> V_53 -> V_64 ,
V_15 -> V_62 ) ;
if ( V_10 < 0 ) {
V_60 = V_10 ;
goto V_61;
}
V_15 -> V_10 = V_10 ;
V_59 -> V_65 . V_10 = V_10 ;
sprintf ( V_59 -> V_63 , L_2 , V_15 -> V_53 -> V_64 , V_15 -> V_62 ) ;
V_59 -> V_66 |= V_67 | V_68 | V_69 ;
V_59 -> V_66 |= V_70 | V_71 | V_72 ;
V_59 -> V_66 |= V_73 ;
V_59 -> type = V_74
| V_75
| V_76 ;
V_59 -> V_77 = 16 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_78 = V_79 ;
V_57 . V_29 = V_15 ;
V_57 . V_80 = F_34 ;
V_57 . V_81 = F_36 ;
V_57 . V_82 = F_38 ;
V_57 . V_83 = F_39 ;
V_57 . V_84 = F_8 ;
V_59 -> V_85 = & V_57 ;
V_60 = F_42 ( V_10 , V_86 , V_59 ) ;
if ( V_60 < 0 ) {
F_43 ( V_10 ) ;
V_15 -> V_10 = - 1 ;
goto V_61;
}
V_15 -> V_6 = V_59 -> V_65 . V_6 ;
V_60 = 0 ;
V_61:
F_23 ( V_59 ) ;
return V_60 ;
}
static void F_44 ( struct V_14 * V_15 )
{
if ( V_15 -> V_10 >= 0 ) {
F_43 ( V_15 -> V_10 ) ;
V_15 -> V_10 = - 1 ;
}
}
static int F_45 ( struct V_87 * V_44 )
{
struct V_14 * V_15 = V_44 -> V_29 ;
int V_60 ;
switch ( V_15 -> V_7 ) {
case V_8 :
V_60 = F_40 ( V_15 ) ;
if ( V_60 < 0 )
return V_60 ;
break;
case V_12 :
if ( V_15 -> V_10 == 0 )
return - V_88 ;
break;
default:
F_46 ( L_3 , V_15 -> V_7 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_47 ( struct V_87 * V_44 )
{
struct V_14 * V_15 = V_44 -> V_29 ;
if ( V_15 -> V_7 == V_8 )
F_44 ( V_15 ) ;
return 0 ;
}
static void F_48 ( struct V_87 * V_44 )
{
struct V_14 * V_15 = V_44 -> V_29 ;
F_23 ( V_15 ) ;
}
int F_49 ( struct V_89 * V_53 , int V_62 , struct V_87 * * V_90 )
{
struct V_87 * V_44 ;
struct V_14 * V_15 ;
int V_60 ;
* V_90 = NULL ;
if ( ( V_60 = F_50 ( V_53 , L_4 , V_62 ,
16 ,
16 ,
& V_44 ) ) < 0 )
return V_60 ;
strcpy ( V_44 -> V_63 , V_44 -> V_91 ) ;
V_15 = F_21 ( sizeof( * V_15 ) , V_46 ) ;
if ( V_15 == NULL ) {
F_51 ( V_53 , V_44 ) ;
return - V_47 ;
}
V_15 -> V_53 = V_53 ;
V_15 -> V_44 = V_44 ;
V_15 -> V_62 = V_62 ;
V_15 -> V_10 = - 1 ;
F_52 ( & V_15 -> V_18 ) ;
F_53 ( & V_15 -> V_49 ) ;
V_15 -> V_7 = V_8 ;
V_44 -> V_29 = V_15 ;
V_44 -> V_92 = F_48 ;
V_44 -> V_93 = & V_94 ;
F_54 ( V_44 , V_95 , & V_96 ) ;
F_54 ( V_44 , V_97 , & V_98 ) ;
V_44 -> V_99 = V_100 |
V_101 |
V_102 ;
* V_90 = V_44 ;
return 0 ;
}
static int T_1 F_55 ( void )
{
return 0 ;
}
static void T_2 F_56 ( void )
{
}
