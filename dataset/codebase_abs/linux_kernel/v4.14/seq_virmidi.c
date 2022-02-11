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
struct V_3 * V_4 ,
bool V_16 )
{
struct V_1 * V_2 ;
unsigned char V_17 [ 4 ] ;
int V_18 ;
if ( V_16 )
F_3 ( & V_15 -> V_19 ) ;
else
F_4 ( & V_15 -> V_20 ) ;
F_5 (vmidi, &rdev->filelist, list) {
if ( ! V_2 -> V_21 )
continue;
if ( V_4 -> type == V_22 ) {
if ( ( V_4 -> V_23 & V_24 ) != V_25 )
continue;
F_6 ( V_4 , ( V_26 ) V_27 , V_2 -> V_28 ) ;
} else {
V_18 = F_7 ( V_2 -> V_29 , V_17 , sizeof( V_17 ) , V_4 ) ;
if ( V_18 > 0 )
V_27 ( V_2 -> V_28 , V_17 , V_18 ) ;
}
}
if ( V_16 )
F_8 ( & V_15 -> V_19 ) ;
else
F_9 ( & V_15 -> V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 , int V_30 ,
void * V_31 , int V_16 , int V_32 )
{
struct V_14 * V_15 ;
V_15 = V_31 ;
if ( ! ( V_15 -> V_23 & V_33 ) )
return 0 ;
return F_2 ( V_15 , V_4 , V_16 ) ;
}
static void F_11 ( struct V_34 * V_28 , int V_35 )
{
struct V_1 * V_2 = V_28 -> V_36 -> V_31 ;
if ( V_35 ) {
V_2 -> V_21 = 1 ;
} else {
V_2 -> V_21 = 0 ;
}
}
static void F_12 ( struct V_34 * V_28 , int V_35 )
{
struct V_1 * V_2 = V_28 -> V_36 -> V_31 ;
int V_37 , V_38 ;
unsigned char V_39 [ 32 ] , * V_40 ;
unsigned long V_23 ;
if ( V_35 ) {
V_2 -> V_21 = 1 ;
if ( V_2 -> V_7 == V_8 &&
! ( V_2 -> V_15 -> V_23 & V_41 ) ) {
while ( F_13 ( V_28 , V_39 ,
sizeof( V_39 ) ) > 0 ) {
}
return;
}
if ( V_2 -> V_42 . type != V_13 ) {
if ( F_14 ( V_2 -> V_10 , & V_2 -> V_42 , F_15 () , 0 ) < 0 )
return;
V_2 -> V_42 . type = V_13 ;
}
F_16 ( & V_28 -> V_36 -> V_43 , V_23 ) ;
while ( 1 ) {
V_37 = F_17 ( V_28 , V_39 , sizeof( V_39 ) ) ;
if ( V_37 <= 0 )
break;
V_40 = V_39 ;
while ( V_37 > 0 ) {
V_38 = F_18 ( V_2 -> V_29 , V_40 , V_37 , & V_2 -> V_42 ) ;
if ( V_38 < 0 ) {
F_19 ( V_2 -> V_29 ) ;
continue;
}
F_20 ( V_28 , V_38 ) ;
V_40 += V_38 ;
V_37 -= V_38 ;
if ( V_2 -> V_42 . type != V_13 ) {
if ( F_14 ( V_2 -> V_10 , & V_2 -> V_42 , F_15 () , 0 ) < 0 )
goto V_44;
V_2 -> V_42 . type = V_13 ;
}
}
}
V_44:
F_21 ( & V_28 -> V_36 -> V_43 , V_23 ) ;
} else {
V_2 -> V_21 = 0 ;
}
}
static int F_22 ( struct V_34 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_45 -> V_31 ;
struct V_46 * V_36 = V_28 -> V_36 ;
struct V_1 * V_2 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_47 ) ;
if ( V_2 == NULL )
return - V_48 ;
V_2 -> V_28 = V_28 ;
if ( F_24 ( 0 , & V_2 -> V_29 ) < 0 ) {
F_25 ( V_2 ) ;
return - V_48 ;
}
V_2 -> V_7 = V_15 -> V_7 ;
V_2 -> V_10 = V_15 -> V_10 ;
V_2 -> V_6 = V_15 -> V_6 ;
V_36 -> V_31 = V_2 ;
F_26 ( & V_15 -> V_20 ) ;
F_27 ( & V_15 -> V_19 ) ;
F_28 ( & V_2 -> V_49 , & V_15 -> V_50 ) ;
F_29 ( & V_15 -> V_19 ) ;
F_30 ( & V_15 -> V_20 ) ;
V_2 -> V_15 = V_15 ;
return 0 ;
}
static int F_31 ( struct V_34 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_45 -> V_31 ;
struct V_46 * V_36 = V_28 -> V_36 ;
struct V_1 * V_2 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_47 ) ;
if ( V_2 == NULL )
return - V_48 ;
V_2 -> V_28 = V_28 ;
if ( F_24 ( V_51 , & V_2 -> V_29 ) < 0 ) {
F_25 ( V_2 ) ;
return - V_48 ;
}
V_2 -> V_7 = V_15 -> V_7 ;
V_2 -> V_10 = V_15 -> V_10 ;
V_2 -> V_6 = V_15 -> V_6 ;
F_1 ( V_2 , & V_2 -> V_42 ) ;
V_2 -> V_15 = V_15 ;
V_36 -> V_31 = V_2 ;
return 0 ;
}
static int F_32 ( struct V_34 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_45 -> V_31 ;
struct V_1 * V_2 = V_28 -> V_36 -> V_31 ;
F_26 ( & V_15 -> V_20 ) ;
F_27 ( & V_15 -> V_19 ) ;
F_33 ( & V_2 -> V_49 ) ;
F_29 ( & V_15 -> V_19 ) ;
F_30 ( & V_15 -> V_20 ) ;
F_34 ( V_2 -> V_29 ) ;
V_28 -> V_36 -> V_31 = NULL ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_34 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_36 -> V_31 ;
F_34 ( V_2 -> V_29 ) ;
V_28 -> V_36 -> V_31 = NULL ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_36 ( void * V_31 ,
struct V_52 * V_53 )
{
struct V_14 * V_15 ;
V_15 = V_31 ;
if ( ! F_37 ( V_15 -> V_54 -> V_55 ) )
return - V_56 ;
V_15 -> V_23 |= V_41 ;
return 0 ;
}
static int F_38 ( void * V_31 ,
struct V_52 * V_53 )
{
struct V_14 * V_15 ;
V_15 = V_31 ;
V_15 -> V_23 &= ~ V_41 ;
F_39 ( V_15 -> V_54 -> V_55 ) ;
return 0 ;
}
static int F_40 ( void * V_31 ,
struct V_52 * V_53 )
{
struct V_14 * V_15 ;
V_15 = V_31 ;
if ( ! F_37 ( V_15 -> V_54 -> V_55 ) )
return - V_56 ;
V_15 -> V_23 |= V_33 ;
return 0 ;
}
static int F_41 ( void * V_31 ,
struct V_52 * V_53 )
{
struct V_14 * V_15 ;
V_15 = V_31 ;
V_15 -> V_23 &= ~ V_33 ;
F_39 ( V_15 -> V_54 -> V_55 ) ;
return 0 ;
}
static int F_42 ( struct V_14 * V_15 )
{
int V_10 ;
struct V_57 V_58 ;
struct V_59 * V_60 ;
int V_61 ;
if ( V_15 -> V_10 >= 0 )
return 0 ;
V_60 = F_23 ( sizeof( * V_60 ) , V_47 ) ;
if ( ! V_60 ) {
V_61 = - V_48 ;
goto V_62;
}
V_10 = F_43 ( V_15 -> V_54 , V_15 -> V_63 ,
L_1 , V_15 -> V_45 -> V_64 ,
V_15 -> V_54 -> V_65 ,
V_15 -> V_63 ) ;
if ( V_10 < 0 ) {
V_61 = V_10 ;
goto V_62;
}
V_15 -> V_10 = V_10 ;
V_60 -> V_66 . V_10 = V_10 ;
sprintf ( V_60 -> V_64 , L_2 , V_15 -> V_54 -> V_65 , V_15 -> V_63 ) ;
V_60 -> V_67 |= V_68 | V_69 | V_70 ;
V_60 -> V_67 |= V_71 | V_72 | V_73 ;
V_60 -> V_67 |= V_74 ;
V_60 -> type = V_75
| V_76
| V_77 ;
V_60 -> V_78 = 16 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_79 = V_80 ;
V_58 . V_31 = V_15 ;
V_58 . V_81 = F_36 ;
V_58 . V_82 = F_38 ;
V_58 . V_83 = F_40 ;
V_58 . V_84 = F_41 ;
V_58 . V_85 = F_10 ;
V_60 -> V_86 = & V_58 ;
V_61 = F_44 ( V_10 , V_87 , V_60 ) ;
if ( V_61 < 0 ) {
F_45 ( V_10 ) ;
V_15 -> V_10 = - 1 ;
goto V_62;
}
V_15 -> V_6 = V_60 -> V_66 . V_6 ;
V_61 = 0 ;
V_62:
F_25 ( V_60 ) ;
return V_61 ;
}
static void F_46 ( struct V_14 * V_15 )
{
if ( V_15 -> V_10 >= 0 ) {
F_45 ( V_15 -> V_10 ) ;
V_15 -> V_10 = - 1 ;
}
}
static int F_47 ( struct V_88 * V_45 )
{
struct V_14 * V_15 = V_45 -> V_31 ;
int V_61 ;
switch ( V_15 -> V_7 ) {
case V_8 :
V_61 = F_42 ( V_15 ) ;
if ( V_61 < 0 )
return V_61 ;
break;
case V_12 :
if ( V_15 -> V_10 == 0 )
return - V_89 ;
break;
default:
F_48 ( L_3 , V_15 -> V_7 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_49 ( struct V_88 * V_45 )
{
struct V_14 * V_15 = V_45 -> V_31 ;
if ( V_15 -> V_7 == V_8 )
F_46 ( V_15 ) ;
return 0 ;
}
static void F_50 ( struct V_88 * V_45 )
{
struct V_14 * V_15 = V_45 -> V_31 ;
F_25 ( V_15 ) ;
}
int F_51 ( struct V_90 * V_54 , int V_63 , struct V_88 * * V_91 )
{
struct V_88 * V_45 ;
struct V_14 * V_15 ;
int V_61 ;
* V_91 = NULL ;
if ( ( V_61 = F_52 ( V_54 , L_4 , V_63 ,
16 ,
16 ,
& V_45 ) ) < 0 )
return V_61 ;
strcpy ( V_45 -> V_64 , V_45 -> V_92 ) ;
V_15 = F_23 ( sizeof( * V_15 ) , V_47 ) ;
if ( V_15 == NULL ) {
F_53 ( V_54 , V_45 ) ;
return - V_48 ;
}
V_15 -> V_54 = V_54 ;
V_15 -> V_45 = V_45 ;
V_15 -> V_63 = V_63 ;
V_15 -> V_10 = - 1 ;
F_54 ( & V_15 -> V_20 ) ;
F_55 ( & V_15 -> V_19 ) ;
F_56 ( & V_15 -> V_50 ) ;
V_15 -> V_7 = V_8 ;
V_45 -> V_31 = V_15 ;
V_45 -> V_93 = F_50 ;
V_45 -> V_94 = & V_95 ;
F_57 ( V_45 , V_96 , & V_97 ) ;
F_57 ( V_45 , V_98 , & V_99 ) ;
V_45 -> V_100 = V_101 |
V_102 |
V_103 ;
* V_91 = V_45 ;
return 0 ;
}
static int T_1 F_58 ( void )
{
return 0 ;
}
static void T_2 F_59 ( void )
{
}
