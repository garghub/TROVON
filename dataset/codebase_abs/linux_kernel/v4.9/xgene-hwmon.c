static T_1 F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( F_3 ( * V_1 ) ) ;
V_3 = V_4 & V_2 ;
V_4 &= ~ V_2 ;
F_4 ( * V_1 , F_5 ( V_4 ) ) ;
return V_3 ;
}
static int F_6 ( struct V_5 * V_6 , T_2 * V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 * V_11 = ( void * ) ( V_9 + 1 ) ;
int V_12 , V_13 ;
T_1 V_4 ;
F_7 ( & V_6 -> V_14 ) ;
F_8 ( & V_6 -> V_15 ) ;
V_6 -> V_16 = true ;
F_4 ( V_9 -> V_17 ,
F_9 ( V_18 | V_6 -> V_19 ) ) ;
F_4 ( V_9 -> V_20 ,
F_5 ( F_10 ( V_7 [ 0 ] ) | V_21 ) ) ;
V_4 = F_2 ( F_3 ( V_9 -> V_22 ) ) ;
V_4 &= ~ V_23 ;
F_4 ( V_9 -> V_22 , F_5 ( V_4 ) ) ;
for ( V_13 = 0 ; V_13 < sizeof( struct V_24 ) / 4 ; V_13 ++ )
F_4 ( V_11 [ V_13 ] , F_9 ( V_7 [ V_13 ] ) ) ;
V_12 = F_11 ( V_6 -> V_25 , V_7 ) ;
if ( V_12 < 0 ) {
F_12 ( V_6 -> V_26 , L_1 , V_12 ) ;
goto V_27;
}
if ( ! F_13 ( & V_6 -> V_15 ,
F_14 ( V_6 -> V_28 ) ) ) {
F_12 ( V_6 -> V_26 , L_2 ) ;
V_12 = - V_29 ;
goto V_27;
}
if ( F_10 ( V_6 -> V_30 . V_7 ) == V_31 ) {
V_12 = - V_32 ;
goto V_27;
}
V_7 [ 0 ] = V_6 -> V_30 . V_7 ;
V_7 [ 1 ] = V_6 -> V_30 . V_33 ;
V_7 [ 2 ] = V_6 -> V_30 . V_34 ;
V_27:
F_15 ( V_6 -> V_25 , 0 ) ;
V_6 -> V_16 = false ;
F_16 ( & V_6 -> V_14 ) ;
return V_12 ;
}
static int F_17 ( struct V_5 * V_6 , T_2 * V_7 )
{
int V_12 ;
F_7 ( & V_6 -> V_14 ) ;
F_8 ( & V_6 -> V_15 ) ;
V_6 -> V_16 = true ;
V_12 = F_11 ( V_6 -> V_25 , V_7 ) ;
if ( V_12 < 0 ) {
F_12 ( V_6 -> V_26 , L_1 , V_12 ) ;
goto V_27;
}
if ( ! F_13 ( & V_6 -> V_15 ,
F_18 ( V_35 ) ) ) {
F_12 ( V_6 -> V_26 , L_2 ) ;
V_12 = - V_29 ;
goto V_27;
}
if ( F_10 ( V_6 -> V_30 . V_7 ) == V_31 ) {
V_12 = - V_32 ;
goto V_27;
}
V_7 [ 0 ] = V_6 -> V_30 . V_7 ;
V_7 [ 1 ] = V_6 -> V_30 . V_33 ;
V_7 [ 2 ] = V_6 -> V_30 . V_34 ;
V_27:
V_6 -> V_16 = false ;
F_16 ( & V_6 -> V_14 ) ;
return V_12 ;
}
static int F_19 ( struct V_5 * V_6 , T_2 V_1 ,
T_2 * V_36 )
{
T_2 V_7 [ 3 ] ;
int V_12 ;
V_7 [ 0 ] = V_37 ;
V_7 [ 1 ] = F_20 ( V_1 ) ;
V_7 [ 2 ] = 0 ;
if ( V_38 )
V_12 = F_17 ( V_6 , V_7 ) ;
else
V_12 = F_6 ( V_6 , V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_7 [ 1 ] & V_39 )
return - V_40 ;
* V_36 = V_7 [ 1 ] ;
return V_12 ;
}
static int F_21 ( struct V_5 * V_6 ,
T_2 * V_41 )
{
T_2 V_7 [ 3 ] ;
int V_12 ;
V_7 [ 0 ] = F_22 ( V_42 , V_43 , 0 ) ;
V_7 [ 1 ] = 0 ;
V_7 [ 2 ] = 0 ;
V_12 = F_6 ( V_6 , V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
V_41 [ 0 ] = V_7 [ 0 ] ;
V_41 [ 1 ] = V_7 [ 1 ] ;
V_41 [ 2 ] = V_7 [ 2 ] ;
return V_12 ;
}
static int F_23 ( struct V_5 * V_6 , T_2 * V_4 )
{
T_2 V_44 , V_45 ;
int V_12 ;
V_12 = F_19 ( V_6 , V_46 , & V_44 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_19 ( V_6 , V_47 , & V_45 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = F_24 ( V_44 ) + V_45 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_2 * V_4 )
{
T_2 V_44 , V_45 ;
int V_12 ;
V_12 = F_19 ( V_6 , V_48 , & V_44 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_19 ( V_6 , V_49 , & V_45 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = F_24 ( V_44 ) + V_45 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 , T_2 * V_4 )
{
return F_19 ( V_6 , V_50 , V_4 ) ;
}
static T_3 F_27 ( struct V_51 * V_26 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
int V_12 , V_55 ;
T_2 V_4 ;
V_12 = F_26 ( V_6 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_55 = F_29 ( V_4 , V_56 ) ;
return snprintf ( V_54 , V_57 , L_3 , F_30 ( V_55 ) ) ;
}
static T_3 F_31 ( struct V_51 * V_26 ,
struct V_52 * V_53 ,
char * V_54 )
{
return snprintf ( V_54 , V_57 , L_4 ) ;
}
static T_3 F_32 ( struct V_51 * V_26 ,
struct V_52 * V_58 ,
char * V_54 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
return snprintf ( V_54 , V_57 , L_3 , V_6 -> V_59 ) ;
}
static T_3 F_33 ( struct V_51 * V_26 ,
struct V_52 * V_53 ,
char * V_54 )
{
return snprintf ( V_54 , V_57 , L_5 ) ;
}
static T_3 F_34 ( struct V_51 * V_26 ,
struct V_52 * V_53 ,
char * V_54 )
{
return snprintf ( V_54 , V_57 , L_6 ) ;
}
static T_3 F_35 ( struct V_51 * V_26 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_2 V_4 ;
int V_12 ;
V_12 = F_23 ( V_6 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
return snprintf ( V_54 , V_57 , L_7 , F_36 ( V_4 ) ) ;
}
static T_3 F_37 ( struct V_51 * V_26 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_5 * V_6 = F_28 ( V_26 ) ;
T_2 V_4 ;
int V_12 ;
V_12 = F_25 ( V_6 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
return snprintf ( V_54 , V_57 , L_7 , F_36 ( V_4 ) ) ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_24 * V_41 )
{
V_6 -> V_59 = ! ! V_41 -> V_34 ;
F_39 ( & V_6 -> V_26 -> V_60 , NULL , L_8 ) ;
return 0 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_24 * V_41 )
{
if ( ( F_41 ( V_41 -> V_7 ) == V_42 ) &&
( F_42 ( V_41 -> V_7 ) == V_61 ) )
F_38 ( V_6 , V_41 ) ;
}
static void F_43 ( struct V_62 * V_63 )
{
struct V_24 V_41 ;
struct V_5 * V_6 ;
int V_3 ;
V_6 = F_44 ( V_63 , struct V_5 , V_64 ) ;
while ( F_45 ( & V_6 -> V_65 , & V_41 ,
sizeof( struct V_24 ) ,
& V_6 -> V_66 ) ) {
if ( ! V_38 ) {
V_3 = F_21 ( V_6 ,
( T_2 * ) & V_41 ) ;
if ( V_3 < 0 )
continue;
}
if ( F_10 ( V_41 . V_7 ) == V_67 )
F_40 ( V_6 , & V_41 ) ;
}
}
static int F_46 ( struct V_5 * V_6 , void * V_7 )
{
if ( F_47 ( V_6 -> V_68 ) && ! V_6 -> V_16 ) {
F_48 ( & V_6 -> V_65 , V_7 ,
sizeof( struct V_24 ) ,
& V_6 -> V_66 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_49 ( struct V_70 * V_71 , void * V_7 )
{
struct V_5 * V_6 = F_50 ( V_71 ) ;
if ( F_46 ( V_6 , V_7 ) < 0 )
return;
if ( V_6 -> V_16 &&
( ( F_10 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_31 ) ||
( F_10 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_72 &&
F_41 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_73 ) ||
( F_10 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_67 &&
F_41 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_42 &&
F_42 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_61 ) ) ) {
V_6 -> V_30 . V_7 = ( ( T_2 * ) V_7 ) [ 0 ] ;
V_6 -> V_30 . V_33 = ( ( T_2 * ) V_7 ) [ 1 ] ;
V_6 -> V_30 . V_34 = ( ( T_2 * ) V_7 ) [ 2 ] ;
F_51 ( & V_6 -> V_15 ) ;
return;
}
F_48 ( & V_6 -> V_65 , V_7 ,
sizeof( struct V_24 ) , & V_6 -> V_66 ) ;
F_52 ( & V_6 -> V_64 ) ;
}
static void F_53 ( struct V_70 * V_71 , void * V_7 )
{
struct V_5 * V_6 = F_50 ( V_71 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_24 V_41 ;
if ( F_46 ( V_6 , & V_41 ) < 0 )
return;
V_7 = V_9 + 1 ;
if ( ! F_1 ( & V_9 -> V_22 ,
V_74 ) )
return;
if ( V_6 -> V_16 &&
( ( F_10 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_31 ) ||
( F_10 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_72 &&
F_41 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_73 ) ||
( F_10 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_67 &&
F_41 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_42 &&
F_42 ( ( ( T_2 * ) V_7 ) [ 0 ] ) == V_61 ) ) ) {
if ( F_1 ( & V_9 -> V_22 ,
V_23 ) ) {
V_6 -> V_30 . V_7 = ( ( T_2 * ) V_7 ) [ 0 ] ;
V_6 -> V_30 . V_33 = ( ( T_2 * ) V_7 ) [ 1 ] ;
V_6 -> V_30 . V_34 = ( ( T_2 * ) V_7 ) [ 2 ] ;
F_51 ( & V_6 -> V_15 ) ;
return;
}
}
F_48 ( & V_6 -> V_65 , & V_41 ,
sizeof( struct V_24 ) , & V_6 -> V_66 ) ;
F_52 ( & V_6 -> V_64 ) ;
}
static void F_54 ( struct V_70 * V_71 , void * V_7 , int V_3 )
{
if ( V_3 ) {
F_55 ( V_71 -> V_26 , L_9 ,
* ( T_1 * ) V_7 , V_3 ) ;
} else {
F_55 ( V_71 -> V_26 , L_10 ,
* ( T_1 * ) V_7 , V_3 ) ;
}
}
static int F_56 ( struct V_75 * V_76 )
{
struct V_5 * V_6 ;
struct V_70 * V_71 ;
int V_12 ;
V_6 = F_57 ( & V_76 -> V_26 , sizeof( * V_6 ) , V_77 ) ;
if ( ! V_6 )
return - V_78 ;
V_6 -> V_26 = & V_76 -> V_26 ;
F_58 ( V_76 , V_6 ) ;
V_71 = & V_6 -> V_70 ;
F_59 ( & V_6 -> V_66 ) ;
F_60 ( & V_6 -> V_14 ) ;
V_12 = F_61 ( & V_6 -> V_65 ,
sizeof( struct V_24 ) * V_79 ,
V_77 ) ;
if ( V_12 )
goto V_80;
F_62 ( & V_6 -> V_64 , F_43 ) ;
V_71 -> V_26 = & V_76 -> V_26 ;
V_71 -> V_81 = F_54 ;
V_71 -> V_82 = false ;
V_71 -> V_83 = V_35 ;
V_71 -> V_84 = false ;
if ( V_38 ) {
V_71 -> V_85 = F_49 ;
V_6 -> V_25 = F_63 ( V_71 , 0 ) ;
if ( F_64 ( V_6 -> V_25 ) ) {
F_12 ( & V_76 -> V_26 ,
L_11 ) ;
return - V_69 ;
}
} else {
struct V_86 * V_87 ;
if ( F_65 ( & V_76 -> V_26 , L_12 ,
& V_6 -> V_19 ) ) {
F_12 ( & V_76 -> V_26 , L_13 ) ;
return - V_69 ;
}
V_71 -> V_85 = F_53 ;
V_6 -> V_25 = F_66 ( V_71 , V_6 -> V_19 ) ;
if ( F_64 ( V_6 -> V_25 ) ) {
F_12 ( & V_76 -> V_26 ,
L_14 ) ;
return - V_69 ;
}
V_87 = V_6 -> V_25 -> V_88 ;
if ( ! V_87 ) {
F_12 ( & V_76 -> V_26 , L_15 ) ;
V_12 = - V_69 ;
goto V_80;
}
if ( ! V_6 -> V_25 -> V_89 -> V_90 ) {
F_12 ( & V_76 -> V_26 , L_16 ) ;
V_12 = - V_69 ;
goto V_80;
}
V_6 -> V_91 = V_87 -> V_92 ;
if ( V_6 -> V_91 ) {
V_6 -> V_10 = F_67 ( V_6 -> V_91 ,
V_87 -> V_93 ,
V_94 ) ;
} else {
F_12 ( & V_76 -> V_26 , L_17 ) ;
V_12 = - V_69 ;
goto V_80;
}
if ( ! V_6 -> V_10 ) {
F_12 ( & V_76 -> V_26 ,
L_18 ) ;
V_12 = - V_78 ;
goto V_80;
}
V_6 -> V_28 = V_95 * V_87 -> V_96 ;
}
V_6 -> V_68 = F_68 ( V_6 -> V_26 ,
L_19 ,
V_6 ,
V_97 ) ;
if ( F_64 ( V_6 -> V_68 ) ) {
F_12 ( & V_76 -> V_26 , L_20 ) ;
V_12 = F_69 ( V_6 -> V_68 ) ;
goto V_98;
}
F_52 ( & V_6 -> V_64 ) ;
F_70 ( & V_76 -> V_26 , L_21 ) ;
return 0 ;
V_98:
if ( V_38 )
F_71 ( V_6 -> V_25 ) ;
else
F_72 ( V_6 -> V_25 ) ;
V_80:
F_73 ( & V_6 -> V_65 ) ;
return V_12 ;
}
static int F_74 ( struct V_75 * V_76 )
{
struct V_5 * V_6 = F_75 ( V_76 ) ;
F_76 ( V_6 -> V_68 ) ;
F_73 ( & V_6 -> V_65 ) ;
if ( V_38 )
F_71 ( V_6 -> V_25 ) ;
else
F_72 ( V_6 -> V_25 ) ;
return 0 ;
}
