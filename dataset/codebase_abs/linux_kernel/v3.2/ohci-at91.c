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
V_3 = F_15 ( & V_6 -> V_11 , L_9 ) ;
V_1 = F_15 ( & V_6 -> V_11 , L_10 ) ;
F_5 ( V_6 ) ;
F_16 ( F_17 ( V_8 ) ) ;
V_15 = F_18 ( V_8 , V_6 -> V_18 [ 1 ] . V_24 , V_32 ) ;
if ( V_15 == 0 )
return V_15 ;
F_9 ( V_6 ) ;
F_19 ( V_1 ) ;
F_19 ( V_3 ) ;
F_19 ( V_2 ) ;
F_20 ( V_8 -> V_10 ) ;
V_31:
F_21 ( V_8 -> V_23 , V_8 -> V_25 ) ;
V_29:
F_22 ( V_8 ) ;
return V_15 ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_24 ( V_8 ) ;
F_9 ( V_6 ) ;
F_20 ( V_8 -> V_10 ) ;
F_21 ( V_8 -> V_23 , V_8 -> V_25 ) ;
F_22 ( V_8 ) ;
F_19 ( V_1 ) ;
F_19 ( V_3 ) ;
F_19 ( V_2 ) ;
V_3 = V_2 = V_1 = NULL ;
F_25 ( & V_6 -> V_11 , NULL ) ;
}
static int T_2
F_26 ( struct V_7 * V_8 )
{
struct V_33 * V_34 = V_8 -> V_35 . V_36 -> V_37 ;
struct V_38 * V_39 = F_17 ( V_8 ) ;
int V_40 ;
if ( ( V_40 = F_27 ( V_39 ) ) < 0 )
return V_40 ;
V_39 -> V_41 = V_34 -> V_42 ;
if ( ( V_40 = F_28 ( V_39 ) ) < 0 ) {
F_29 ( L_11 , V_8 -> V_35 . V_43 ) ;
F_30 ( V_8 ) ;
return V_40 ;
}
return 0 ;
}
static void F_31 ( struct V_33 * V_44 , int V_45 , int V_46 )
{
if ( V_45 < 0 || V_45 >= 2 )
return;
if ( V_44 -> V_47 [ V_45 ] <= 0 )
return;
F_32 ( V_44 -> V_47 [ V_45 ] , ! V_44 -> V_48 ^ V_46 ) ;
}
static int F_33 ( struct V_33 * V_44 , int V_45 )
{
if ( V_45 < 0 || V_45 >= 2 )
return - V_49 ;
if ( V_44 -> V_47 [ V_45 ] <= 0 )
return - V_49 ;
return F_34 ( V_44 -> V_47 [ V_45 ] ) ^ ! V_44 -> V_48 ;
}
static int F_35 ( struct V_7 * V_8 , char * V_50 )
{
struct V_33 * V_44 = V_8 -> V_35 . V_36 -> V_37 ;
int V_51 = F_36 ( V_8 , V_50 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_37 ( V_44 -> V_52 ) ; V_45 ++ ) {
if ( V_44 -> V_53 [ V_45 ] ) {
if ( ! V_51 )
V_51 = 1 ;
V_50 [ 0 ] |= 1 << ( V_45 + 1 ) ;
}
}
return V_51 ;
}
static int F_38 ( struct V_7 * V_8 , T_3 V_54 , T_3 V_55 ,
T_3 V_56 , char * V_50 , T_3 V_57 )
{
struct V_33 * V_44 = V_8 -> V_35 . V_36 -> V_37 ;
struct V_58 * V_59 ;
int V_40 = - V_49 ;
T_4 * V_60 = ( T_4 * ) V_50 ;
F_7 ( V_8 -> V_35 . V_36 ,
L_12 ,
V_8 , V_54 , V_55 , V_56 , V_50 , V_57 ) ;
switch ( V_54 ) {
case V_61 :
if ( V_55 == V_62 ) {
F_7 ( V_8 -> V_35 . V_36 , L_13 ) ;
F_31 ( V_44 , V_56 - 1 , 1 ) ;
goto V_63;
}
break;
case V_64 :
switch ( V_55 ) {
case V_65 :
F_7 ( V_8 -> V_35 . V_36 ,
L_14 ) ;
if ( V_56 == 1 || V_56 == 2 ) {
V_44 -> V_53 [ V_56 - 1 ] = 0 ;
V_44 -> V_66 [ V_56 - 1 ] = 0 ;
}
goto V_63;
case V_67 :
F_7 ( V_8 -> V_35 . V_36 ,
L_15 ) ;
if ( V_56 == 1 || V_56 == 2 ) {
V_44 -> V_66 [ V_56 - 1 ] = 0 ;
}
goto V_63;
case V_62 :
F_7 ( V_8 -> V_35 . V_36 ,
L_16 ) ;
if ( V_56 == 1 || V_56 == 2 ) {
F_31 ( V_44 , V_56 - 1 , 0 ) ;
return 0 ;
}
}
break;
}
V_40 = F_39 ( V_8 , V_54 , V_55 , V_56 , V_50 , V_57 ) ;
if ( V_40 )
goto V_63;
switch ( V_54 ) {
case V_68 :
V_59 = (struct V_58 * ) V_50 ;
F_7 ( V_8 -> V_35 . V_36 , L_17 ,
V_59 -> V_69 ) ;
V_59 -> V_69 &= ~ F_40 ( V_70 ) ;
V_59 -> V_69 |= F_40 ( 0x0001 ) ;
if ( V_44 -> V_71 ) {
V_59 -> V_69 &= ~ F_40 ( V_72 ) ;
V_59 -> V_69 |= F_40 ( 0x0008 | 0x0001 ) ;
}
F_7 ( V_8 -> V_35 . V_36 , L_18 ,
V_59 -> V_69 ) ;
return V_40 ;
case V_73 :
F_7 ( V_8 -> V_35 . V_36 , L_19 , V_56 ) ;
if ( V_56 == 1 || V_56 == 2 ) {
if ( ! F_33 ( V_44 , V_56 - 1 ) ) {
* V_60 &= ~ F_41 ( V_74 ) ;
}
if ( V_44 -> V_53 [ V_56 - 1 ] ) {
* V_60 |= F_41 ( V_75 ) ;
}
if ( V_44 -> V_66 [ V_56 - 1 ] ) {
* V_60 |= F_41 ( V_76 ) ;
}
}
}
V_63:
return V_40 ;
}
static T_5 F_42 ( int V_77 , void * V_60 )
{
struct V_5 * V_6 = V_60 ;
struct V_33 * V_44 = V_6 -> V_11 . V_37 ;
int V_78 , V_79 , V_45 ;
V_79 = F_43 ( V_77 ) ;
for ( V_45 = 0 ; V_45 < F_37 ( V_44 -> V_52 ) ; V_45 ++ ) {
if ( V_44 -> V_52 [ V_45 ] == V_79 )
break;
}
if ( V_45 == F_37 ( V_44 -> V_52 ) ) {
F_44 ( & V_6 -> V_11 , L_20 ) ;
return V_80 ;
}
V_78 = F_34 ( V_79 ) ;
if ( ! V_78 ) {
F_31 ( V_44 , V_45 , 0 ) ;
V_44 -> V_66 [ V_45 ] = 1 ;
V_44 -> V_53 [ V_45 ] = 1 ;
}
F_7 ( & V_6 -> V_11 , L_21 ,
V_78 ? L_22 : L_23 ) ;
return V_80 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_33 * V_44 = V_6 -> V_11 . V_37 ;
int V_81 ;
if ( V_44 ) {
for ( V_81 = 0 ; V_81 < F_37 ( V_44 -> V_47 ) ; V_81 ++ ) {
if ( V_44 -> V_47 [ V_81 ] <= 0 )
continue;
F_46 ( V_44 -> V_47 [ V_81 ] , L_24 ) ;
F_31 ( V_44 , V_81 , 1 ) ;
}
for ( V_81 = 0 ; V_81 < F_37 ( V_44 -> V_52 ) ; V_81 ++ ) {
int V_40 ;
if ( V_44 -> V_52 [ V_81 ] <= 0 )
continue;
F_46 ( V_44 -> V_52 [ V_81 ] , L_25 ) ;
V_40 = F_47 ( F_48 ( V_44 -> V_52 [ V_81 ] ) ,
F_42 ,
V_32 , L_25 , V_6 ) ;
if ( V_40 ) {
F_49 ( V_44 -> V_52 [ V_81 ] ) ;
F_50 ( & V_6 -> V_11 , L_26 ) ;
}
}
}
F_51 ( & V_6 -> V_11 , 1 ) ;
return F_10 ( & V_82 , V_6 ) ;
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_33 * V_44 = V_6 -> V_11 . V_37 ;
int V_81 ;
if ( V_44 ) {
for ( V_81 = 0 ; V_81 < F_37 ( V_44 -> V_47 ) ; V_81 ++ ) {
if ( V_44 -> V_47 [ V_81 ] <= 0 )
continue;
F_31 ( V_44 , V_81 , 0 ) ;
F_49 ( V_44 -> V_47 [ V_81 ] ) ;
}
for ( V_81 = 0 ; V_81 < F_37 ( V_44 -> V_52 ) ; V_81 ++ ) {
if ( V_44 -> V_52 [ V_81 ] <= 0 )
continue;
F_53 ( F_48 ( V_44 -> V_52 [ V_81 ] ) , V_6 ) ;
F_49 ( V_44 -> V_52 [ V_81 ] ) ;
}
}
F_51 ( & V_6 -> V_11 , 0 ) ;
F_23 ( F_6 ( V_6 ) , V_6 ) ;
return 0 ;
}
static int
F_54 ( struct V_5 * V_6 , T_6 V_83 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_38 * V_39 = F_17 ( V_8 ) ;
if ( F_55 ( & V_6 -> V_11 ) )
F_56 ( V_8 -> V_77 ) ;
if ( F_57 () ) {
F_58 ( V_39 ) ;
( void ) F_59 ( V_39 , & V_39 -> V_10 -> V_12 ) ;
F_3 () ;
}
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
if ( F_55 ( & V_6 -> V_11 ) )
F_61 ( V_8 -> V_77 ) ;
if ( ! V_4 )
F_1 () ;
F_62 ( V_8 ) ;
return 0 ;
}
