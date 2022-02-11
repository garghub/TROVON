static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
V_4 = 1 ;
}
static void F_3 ( void )
{
F_4 ( V_3 ) ;
F_4 ( V_2 ) ;
F_4 ( V_1 ) ;
V_4 = 0 ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_9 T_1 * V_10 = V_8 -> V_10 ;
F_7 ( & V_6 -> V_11 , L_1 ) ;
F_1 () ;
F_8 ( 0 , & V_10 -> V_12 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_9 T_1 * V_10 = V_8 -> V_10 ;
F_7 ( & V_6 -> V_11 , L_2 ) ;
F_8 ( 0 , & V_10 -> V_12 ) ;
F_3 () ;
}
static int F_10 ( const struct V_13 * V_14 ,
struct V_5 * V_6 )
{
int V_15 ;
struct V_7 * V_8 = NULL ;
if ( V_6 -> V_16 != 2 ) {
F_11 ( L_3 ) ;
return - V_17 ;
}
if ( ( V_6 -> V_18 [ 0 ] . V_19 != V_20 )
|| ( V_6 -> V_18 [ 1 ] . V_19 != V_21 ) ) {
F_11 ( L_4 ) ;
return - V_17 ;
}
V_8 = F_12 ( V_14 , & V_6 -> V_11 , L_5 ) ;
if ( ! V_8 )
return - V_22 ;
V_8 -> V_23 = V_6 -> V_18 [ 0 ] . V_24 ;
V_8 -> V_25 = V_6 -> V_18 [ 0 ] . V_26 - V_6 -> V_18 [ 0 ] . V_24 + 1 ;
if ( ! F_13 ( V_8 -> V_23 , V_8 -> V_25 , V_27 ) ) {
F_11 ( L_6 ) ;
V_15 = - V_28 ;
goto V_29;
}
V_8 -> V_10 = F_14 ( V_8 -> V_23 , V_8 -> V_25 ) ;
if ( ! V_8 -> V_10 ) {
F_11 ( L_7 ) ;
V_15 = - V_30 ;
goto V_31;
}
V_2 = F_15 ( & V_6 -> V_11 , L_8 ) ;
if ( F_16 ( V_2 ) ) {
F_17 ( & V_6 -> V_11 , L_9 ) ;
V_15 = F_18 ( V_2 ) ;
goto V_32;
}
V_3 = F_15 ( & V_6 -> V_11 , L_10 ) ;
if ( F_16 ( V_3 ) ) {
F_17 ( & V_6 -> V_11 , L_11 ) ;
V_15 = F_18 ( V_3 ) ;
goto V_33;
}
V_1 = F_15 ( & V_6 -> V_11 , L_12 ) ;
if ( F_16 ( V_1 ) ) {
F_17 ( & V_6 -> V_11 , L_13 ) ;
V_15 = F_18 ( V_1 ) ;
goto V_34;
}
F_5 ( V_6 ) ;
F_19 ( F_20 ( V_8 ) ) ;
V_15 = F_21 ( V_8 , V_6 -> V_18 [ 1 ] . V_24 , V_35 ) ;
if ( V_15 == 0 )
return V_15 ;
F_9 ( V_6 ) ;
F_22 ( V_1 ) ;
V_34:
F_22 ( V_3 ) ;
V_33:
F_22 ( V_2 ) ;
V_32:
F_23 ( V_8 -> V_10 ) ;
V_31:
F_24 ( V_8 -> V_23 , V_8 -> V_25 ) ;
V_29:
F_25 ( V_8 ) ;
return V_15 ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_27 ( V_8 ) ;
F_9 ( V_6 ) ;
F_23 ( V_8 -> V_10 ) ;
F_24 ( V_8 -> V_23 , V_8 -> V_25 ) ;
F_25 ( V_8 ) ;
F_22 ( V_1 ) ;
F_22 ( V_3 ) ;
F_22 ( V_2 ) ;
V_3 = V_2 = V_1 = NULL ;
F_28 ( & V_6 -> V_11 , NULL ) ;
}
static int T_2
F_29 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 . V_39 -> V_40 ;
struct V_41 * V_42 = F_20 ( V_8 ) ;
int V_43 ;
if ( ( V_43 = F_30 ( V_42 ) ) < 0 )
return V_43 ;
V_42 -> V_44 = V_37 -> V_45 ;
if ( ( V_43 = F_31 ( V_42 ) ) < 0 ) {
F_32 ( L_14 , V_8 -> V_38 . V_46 ) ;
F_33 ( V_8 ) ;
return V_43 ;
}
return 0 ;
}
static void F_34 ( struct V_36 * V_47 , int V_48 , int V_49 )
{
if ( V_48 < 0 || V_48 >= 2 )
return;
if ( ! F_35 ( V_47 -> V_50 [ V_48 ] ) )
return;
F_36 ( V_47 -> V_50 [ V_48 ] ,
! V_47 -> V_51 [ V_48 ] ^ V_49 ) ;
}
static int F_37 ( struct V_36 * V_47 , int V_48 )
{
if ( V_48 < 0 || V_48 >= 2 )
return - V_52 ;
if ( ! F_35 ( V_47 -> V_50 [ V_48 ] ) )
return - V_52 ;
return F_38 ( V_47 -> V_50 [ V_48 ] ) ^
! V_47 -> V_51 [ V_48 ] ;
}
static int F_39 ( struct V_7 * V_8 , char * V_53 )
{
struct V_36 * V_47 = V_8 -> V_38 . V_39 -> V_40 ;
int V_54 = F_40 ( V_8 , V_53 ) ;
int V_48 ;
for ( V_48 = 0 ; V_48 < F_41 ( V_47 -> V_55 ) ; V_48 ++ ) {
if ( V_47 -> V_56 [ V_48 ] ) {
if ( ! V_54 )
V_54 = 1 ;
V_53 [ 0 ] |= 1 << ( V_48 + 1 ) ;
}
}
return V_54 ;
}
static int F_42 ( struct V_7 * V_8 , T_3 V_57 , T_3 V_58 ,
T_3 V_59 , char * V_53 , T_3 V_60 )
{
struct V_36 * V_47 = V_8 -> V_38 . V_39 -> V_40 ;
struct V_61 * V_62 ;
int V_43 = - V_52 ;
T_4 * V_63 = ( T_4 * ) V_53 ;
F_7 ( V_8 -> V_38 . V_39 ,
L_15 ,
V_8 , V_57 , V_58 , V_59 , V_53 , V_60 ) ;
switch ( V_57 ) {
case V_64 :
if ( V_58 == V_65 ) {
F_7 ( V_8 -> V_38 . V_39 , L_16 ) ;
F_34 ( V_47 , V_59 - 1 , 1 ) ;
goto V_66;
}
break;
case V_67 :
switch ( V_58 ) {
case V_68 :
F_7 ( V_8 -> V_38 . V_39 ,
L_17 ) ;
if ( V_59 == 1 || V_59 == 2 ) {
V_47 -> V_56 [ V_59 - 1 ] = 0 ;
V_47 -> V_69 [ V_59 - 1 ] = 0 ;
}
goto V_66;
case V_70 :
F_7 ( V_8 -> V_38 . V_39 ,
L_18 ) ;
if ( V_59 == 1 || V_59 == 2 ) {
V_47 -> V_69 [ V_59 - 1 ] = 0 ;
}
goto V_66;
case V_65 :
F_7 ( V_8 -> V_38 . V_39 ,
L_19 ) ;
if ( V_59 == 1 || V_59 == 2 ) {
F_34 ( V_47 , V_59 - 1 , 0 ) ;
return 0 ;
}
}
break;
}
V_43 = F_43 ( V_8 , V_57 , V_58 , V_59 , V_53 , V_60 ) ;
if ( V_43 )
goto V_66;
switch ( V_57 ) {
case V_71 :
V_62 = (struct V_61 * ) V_53 ;
F_7 ( V_8 -> V_38 . V_39 , L_20 ,
V_62 -> V_72 ) ;
V_62 -> V_72 &= ~ F_44 ( V_73 ) ;
V_62 -> V_72 |= F_44 ( 0x0001 ) ;
if ( V_47 -> V_74 ) {
V_62 -> V_72 &= ~ F_44 ( V_75 ) ;
V_62 -> V_72 |= F_44 ( 0x0008 | 0x0001 ) ;
}
F_7 ( V_8 -> V_38 . V_39 , L_21 ,
V_62 -> V_72 ) ;
return V_43 ;
case V_76 :
F_7 ( V_8 -> V_38 . V_39 , L_22 , V_59 ) ;
if ( V_59 == 1 || V_59 == 2 ) {
if ( ! F_37 ( V_47 , V_59 - 1 ) ) {
* V_63 &= ~ F_45 ( V_77 ) ;
}
if ( V_47 -> V_56 [ V_59 - 1 ] ) {
* V_63 |= F_45 ( V_78 ) ;
}
if ( V_47 -> V_69 [ V_59 - 1 ] ) {
* V_63 |= F_45 ( V_79 ) ;
}
}
}
V_66:
return V_43 ;
}
static T_5 F_46 ( int V_80 , void * V_63 )
{
struct V_5 * V_6 = V_63 ;
struct V_36 * V_47 = V_6 -> V_11 . V_40 ;
int V_81 , V_82 , V_48 ;
V_82 = F_47 ( V_80 ) ;
for ( V_48 = 0 ; V_48 < F_41 ( V_47 -> V_55 ) ; V_48 ++ ) {
if ( V_47 -> V_55 [ V_48 ] == V_82 )
break;
}
if ( V_48 == F_41 ( V_47 -> V_55 ) ) {
F_17 ( & V_6 -> V_11 , L_23 ) ;
return V_83 ;
}
V_81 = F_38 ( V_82 ) ;
if ( ! V_81 ) {
F_34 ( V_47 , V_48 , 0 ) ;
V_47 -> V_69 [ V_48 ] = 1 ;
V_47 -> V_56 [ V_48 ] = 1 ;
}
F_7 ( & V_6 -> V_11 , L_24 ,
V_81 ? L_25 : L_26 ) ;
return V_83 ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_36 * V_47 = V_6 -> V_11 . V_40 ;
int V_84 ;
if ( V_47 ) {
for ( V_84 = 0 ; V_84 < F_41 ( V_47 -> V_50 ) ; V_84 ++ ) {
if ( ! F_35 ( V_47 -> V_50 [ V_84 ] ) )
continue;
F_49 ( V_47 -> V_50 [ V_84 ] , L_27 ) ;
F_34 ( V_47 , V_84 , 1 ) ;
}
for ( V_84 = 0 ; V_84 < F_41 ( V_47 -> V_55 ) ; V_84 ++ ) {
int V_43 ;
if ( ! F_35 ( V_47 -> V_55 [ V_84 ] ) )
continue;
F_49 ( V_47 -> V_55 [ V_84 ] , L_28 ) ;
V_43 = F_50 ( F_51 ( V_47 -> V_55 [ V_84 ] ) ,
F_46 ,
V_35 , L_28 , V_6 ) ;
if ( V_43 ) {
F_52 ( V_47 -> V_55 [ V_84 ] ) ;
F_53 ( & V_6 -> V_11 , L_29 ) ;
}
}
}
F_54 ( & V_6 -> V_11 , 1 ) ;
return F_10 ( & V_85 , V_6 ) ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_36 * V_47 = V_6 -> V_11 . V_40 ;
int V_84 ;
if ( V_47 ) {
for ( V_84 = 0 ; V_84 < F_41 ( V_47 -> V_50 ) ; V_84 ++ ) {
if ( ! F_35 ( V_47 -> V_50 [ V_84 ] ) )
continue;
F_34 ( V_47 , V_84 , 0 ) ;
F_52 ( V_47 -> V_50 [ V_84 ] ) ;
}
for ( V_84 = 0 ; V_84 < F_41 ( V_47 -> V_55 ) ; V_84 ++ ) {
if ( ! F_35 ( V_47 -> V_55 [ V_84 ] ) )
continue;
F_56 ( F_51 ( V_47 -> V_55 [ V_84 ] ) , V_6 ) ;
F_52 ( V_47 -> V_55 [ V_84 ] ) ;
}
}
F_54 ( & V_6 -> V_11 , 0 ) ;
F_26 ( F_6 ( V_6 ) , V_6 ) ;
return 0 ;
}
static int
F_57 ( struct V_5 * V_6 , T_6 V_86 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_41 * V_42 = F_20 ( V_8 ) ;
if ( F_58 ( & V_6 -> V_11 ) )
F_59 ( V_8 -> V_80 ) ;
if ( F_60 () ) {
F_61 ( V_42 ) ;
( void ) F_62 ( V_42 , & V_42 -> V_10 -> V_12 ) ;
F_3 () ;
}
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
if ( F_58 ( & V_6 -> V_11 ) )
F_64 ( V_8 -> V_80 ) ;
if ( ! V_4 )
F_1 () ;
F_65 ( V_8 ) ;
return 0 ;
}
