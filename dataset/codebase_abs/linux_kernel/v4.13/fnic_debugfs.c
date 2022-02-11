int F_1 ( void )
{
int V_1 = - 1 ;
V_2 = F_2 ( L_1 , NULL ) ;
if ( ! V_2 ) {
F_3 ( V_3 L_2 ) ;
return V_1 ;
}
if ( ! V_2 ) {
F_3 ( V_3
L_3 ) ;
return V_1 ;
}
V_4 = F_2 ( L_4 ,
V_2 ) ;
if ( ! V_4 ) {
F_3 ( V_3 L_5 ) ;
return V_1 ;
}
V_5 = (struct V_6 * )
F_4 ( sizeof( struct V_6 ) ) ;
if ( V_5 ) {
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 1 ;
V_5 -> V_9 = 2 ;
V_5 -> V_10 = 3 ;
V_5 -> V_11 = 4 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_5 ( void )
{
F_6 ( V_4 ) ;
V_4 = NULL ;
F_6 ( V_2 ) ;
V_2 = NULL ;
if ( V_5 )
F_7 ( V_5 ) ;
}
static int F_8 ( struct V_12 * V_12 , struct V_13 * V_14 )
{
V_14 -> V_15 = V_12 -> V_16 ;
return 0 ;
}
static T_1 F_9 ( struct V_13 * V_14 ,
char T_2 * V_17 ,
T_3 V_18 , T_4 * V_19 )
{
char V_20 [ 64 ] ;
int V_21 ;
T_5 * V_22 ;
V_21 = 0 ;
V_22 = ( T_5 * ) V_14 -> V_15 ;
if ( * V_22 == V_5 -> V_9 )
V_21 = sprintf ( V_20 , L_6 , V_23 ) ;
else if ( * V_22 == V_5 -> V_10 )
V_21 = sprintf ( V_20 , L_6 , V_24 ) ;
else if ( * V_22 == V_5 -> V_11 )
V_21 = sprintf ( V_20 , L_6 , V_25 ) ;
else
F_10 ( L_7 ) ;
return F_11 ( V_17 , V_18 , V_19 , V_20 , V_21 ) ;
}
static T_1 F_12 ( struct V_13 * V_14 ,
const char T_2 * V_17 ,
T_3 V_18 , T_4 * V_19 )
{
char V_20 [ 64 ] ;
unsigned long V_26 ;
int V_27 ;
T_5 * V_22 ;
V_22 = ( T_5 * ) V_14 -> V_15 ;
if ( V_18 >= sizeof( V_20 ) )
return - V_28 ;
if ( F_13 ( & V_20 , V_17 , V_18 ) )
return - V_29 ;
V_20 [ V_18 ] = 0 ;
V_27 = F_14 ( V_20 , 10 , & V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( * V_22 == V_5 -> V_9 )
V_23 = V_26 ;
else if ( * V_22 == V_5 -> V_10 )
V_24 = V_26 ;
else if ( * V_22 == V_5 -> V_11 )
V_25 = V_26 ;
else
F_10 ( L_8 ) ;
( * V_19 ) ++ ;
return V_18 ;
}
static int F_15 ( struct V_12 * V_12 ,
struct V_13 * V_13 )
{
T_6 * V_30 ;
T_5 * V_31 ;
V_31 = ( T_5 * ) V_12 -> V_16 ;
V_30 = F_16 ( sizeof( T_6 ) , V_32 ) ;
if ( ! V_30 )
return - V_33 ;
if ( * V_31 == V_5 -> V_9 ) {
V_30 -> V_34 = F_4 ( 3 *
( V_35 * V_36 ) ) ;
if ( ! V_30 -> V_34 ) {
F_17 ( V_30 ) ;
return - V_33 ;
}
memset ( ( void * ) V_30 -> V_34 , 0 ,
3 * ( V_35 * V_36 ) ) ;
V_30 -> V_37 = F_18 ( V_30 ) ;
} else {
V_30 -> V_34 =
F_4 ( 3 * ( V_38 * V_36 ) ) ;
if ( ! V_30 -> V_34 ) {
F_17 ( V_30 ) ;
return - V_33 ;
}
memset ( ( void * ) V_30 -> V_34 , 0 ,
3 * ( V_38 * V_36 ) ) ;
V_30 -> V_37 =
F_19 ( V_30 , * V_31 ) ;
}
V_13 -> V_15 = V_30 ;
return 0 ;
}
static T_4 F_20 ( struct V_13 * V_13 ,
T_4 V_39 ,
int V_40 )
{
T_6 * V_30 = V_13 -> V_15 ;
return F_21 ( V_13 , V_39 , V_40 ,
V_30 -> V_37 ) ;
}
static T_1 F_22 ( struct V_13 * V_13 ,
char T_2 * V_17 ,
T_3 V_41 ,
T_4 * V_42 )
{
T_6 * V_30 = V_13 -> V_15 ;
int V_1 = 0 ;
V_1 = F_11 ( V_17 , V_41 , V_42 ,
V_30 -> V_34 ,
V_30 -> V_37 ) ;
return V_1 ;
}
static int F_23 ( struct V_12 * V_12 ,
struct V_13 * V_13 )
{
T_6 * V_30 = V_13 -> V_15 ;
F_7 ( V_30 -> V_34 ) ;
F_17 ( V_30 ) ;
return 0 ;
}
int F_24 ( void )
{
int V_1 = - 1 ;
if ( ! V_2 ) {
F_3 ( V_3
L_9 ) ;
return V_1 ;
}
V_43 = F_25 ( L_10 ,
V_44 | V_45 | V_46 ,
V_2 ,
& ( V_5 -> V_9 ) ,
& V_47 ) ;
if ( ! V_43 ) {
F_3 ( V_3
L_11 ) ;
return V_1 ;
}
V_48 = F_25 ( L_12 ,
V_44 | V_45 | V_46 ,
V_2 ,
& ( V_5 -> V_9 ) ,
& V_49 ) ;
if ( ! V_48 ) {
F_3 ( V_3
L_13 ) ;
return V_1 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_26 ( void )
{
F_6 ( V_48 ) ;
V_48 = NULL ;
F_6 ( V_43 ) ;
V_43 = NULL ;
}
int F_27 ( void )
{
int V_1 = - 1 ;
if ( ! V_2 ) {
F_10 ( L_14 ) ;
return V_1 ;
}
V_50 = F_25 ( L_15 ,
V_44 | V_45 | V_46 ,
V_2 ,
& ( V_5 -> V_10 ) ,
& V_47 ) ;
if ( ! V_50 ) {
F_10 ( L_16 ) ;
return V_1 ;
}
V_51 = F_25 ( L_17 ,
V_44 | V_45 | V_46 ,
V_2 ,
& ( V_5 -> V_11 ) ,
& V_47 ) ;
if ( ! V_51 ) {
F_10 ( L_18 ) ;
return V_1 ;
}
V_52 =
F_25 ( L_19 ,
V_44 | V_45 | V_46 ,
V_2 ,
& ( V_5 -> V_8 ) ,
& V_49 ) ;
if ( ! V_52 ) {
F_10 ( L_20 ) ;
return V_1 ;
}
V_53 =
F_25 ( L_21 ,
V_44 | V_45 | V_46 ,
V_2 ,
& ( V_5 -> V_7 ) ,
& V_49 ) ;
if ( ! V_53 ) {
F_10 ( L_22 ) ;
return V_1 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_28 ( void )
{
F_6 ( V_53 ) ;
V_53 = NULL ;
F_6 ( V_52 ) ;
V_52 = NULL ;
F_6 ( V_50 ) ;
V_50 = NULL ;
F_6 ( V_51 ) ;
V_51 = NULL ;
}
static int F_29 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
struct V_54 * V_55 ;
V_55 = F_16 ( sizeof( struct V_54 ) , V_32 ) ;
if ( ! V_55 )
return - V_33 ;
V_55 -> V_16 = V_12 -> V_16 ;
V_13 -> V_15 = V_55 ;
return 0 ;
}
static T_1 F_30 ( struct V_13 * V_13 ,
char T_2 * V_17 ,
T_3 V_18 , T_4 * V_19 )
{
struct V_54 * V_55 = V_13 -> V_15 ;
struct V_56 * V_56 = (struct V_56 * ) V_55 -> V_16 ;
char V_20 [ 64 ] ;
int V_21 ;
V_21 = sprintf ( V_20 , L_6 , V_56 -> V_57 ) ;
return F_11 ( V_17 , V_18 , V_19 , V_20 , V_21 ) ;
}
static T_1 F_31 ( struct V_13 * V_13 ,
const char T_2 * V_17 ,
T_3 V_18 , T_4 * V_19 )
{
struct V_54 * V_55 = V_13 -> V_15 ;
struct V_56 * V_56 = (struct V_56 * ) V_55 -> V_16 ;
struct V_58 * V_59 = & V_56 -> V_58 ;
T_7 * V_60 = ( T_7 * ) & V_59 -> V_61 ;
T_7 * V_62 = ( T_7 * ) & V_59 -> V_63 ;
char V_20 [ 64 ] ;
unsigned long V_26 ;
int V_27 ;
if ( V_18 >= sizeof( V_20 ) )
return - V_28 ;
if ( F_13 ( & V_20 , V_17 , V_18 ) )
return - V_29 ;
V_20 [ V_18 ] = 0 ;
V_27 = F_14 ( V_20 , 10 , & V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
V_56 -> V_57 = V_26 ;
if ( V_56 -> V_57 ) {
F_32 ( & V_56 -> V_64 ,
F_33 ( & V_59 -> V_61 . V_65 ) ) ;
memset ( & V_59 -> V_66 , 0 , sizeof( struct V_67 ) ) ;
memset ( & V_59 -> V_68 , 0 ,
sizeof( struct V_69 ) ) ;
memset ( & V_59 -> V_57 , 0 , sizeof( struct V_57 ) ) ;
memset ( & V_59 -> V_70 , 0 , sizeof( struct V_70 ) ) ;
memset ( & V_59 -> V_71 , 0 , sizeof( struct V_71 ) ) ;
memset ( V_60 + 1 , 0 ,
sizeof( struct V_72 ) - sizeof( T_7 ) ) ;
memset ( V_62 + 1 , 0 ,
sizeof( struct V_63 ) - sizeof( T_7 ) ) ;
F_34 ( & V_59 -> V_73 . V_74 ) ;
}
( * V_19 ) ++ ;
return V_18 ;
}
static int F_35 ( struct V_12 * V_12 ,
struct V_13 * V_13 )
{
struct V_54 * V_55 = V_13 -> V_15 ;
F_17 ( V_55 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_12 ,
struct V_13 * V_13 )
{
struct V_56 * V_56 = V_12 -> V_16 ;
struct V_58 * V_58 = & V_56 -> V_58 ;
struct V_54 * V_55 ;
int V_75 = 2 * V_36 ;
V_55 = F_16 ( sizeof( struct V_54 ) , V_32 ) ;
if ( ! V_55 )
return - V_33 ;
V_55 -> V_76 = F_4 ( V_75 ) ;
if ( ! V_55 -> V_76 ) {
F_17 ( V_55 ) ;
return - V_33 ;
}
V_55 -> V_75 = V_75 ;
memset ( ( void * ) V_55 -> V_76 , 0 , V_75 ) ;
V_55 -> V_37 = F_37 ( V_55 , V_58 ) ;
V_13 -> V_15 = V_55 ;
return 0 ;
}
static T_1 F_38 ( struct V_13 * V_13 ,
char T_2 * V_17 ,
T_3 V_41 ,
T_4 * V_42 )
{
struct V_54 * V_55 = V_13 -> V_15 ;
int V_1 = 0 ;
V_1 = F_11 ( V_17 , V_41 , V_42 ,
V_55 -> V_76 ,
V_55 -> V_37 ) ;
return V_1 ;
}
static int F_39 ( struct V_12 * V_12 ,
struct V_13 * V_13 )
{
struct V_54 * V_55 = V_13 -> V_15 ;
F_7 ( V_55 -> V_76 ) ;
F_17 ( V_55 ) ;
return 0 ;
}
int F_40 ( struct V_56 * V_56 )
{
int V_1 = - 1 ;
char V_77 [ 16 ] ;
snprintf ( V_77 , sizeof( V_77 ) , L_23 , V_56 -> V_78 -> V_79 -> V_80 ) ;
if ( ! V_4 ) {
F_3 ( V_3 L_24 ) ;
return V_1 ;
}
V_56 -> V_81 = F_2 ( V_77 ,
V_4 ) ;
if ( ! V_56 -> V_81 ) {
F_3 ( V_3 L_25 ) ;
return V_1 ;
}
V_56 -> V_82 = F_25 ( L_26 ,
V_44 | V_45 | V_46 ,
V_56 -> V_81 ,
V_56 ,
& V_83 ) ;
if ( ! V_56 -> V_82 ) {
F_3 ( V_3 L_27 ) ;
return V_1 ;
}
V_56 -> V_84 = F_25 ( L_28 ,
V_44 | V_45 | V_46 ,
V_56 -> V_81 ,
V_56 ,
& V_85 ) ;
if ( ! V_56 -> V_84 ) {
F_3 ( V_3 L_27 ) ;
return V_1 ;
}
V_1 = 0 ;
return V_1 ;
}
void F_41 ( struct V_56 * V_56 )
{
if ( ! V_56 )
return;
F_6 ( V_56 -> V_82 ) ;
V_56 -> V_82 = NULL ;
F_6 ( V_56 -> V_84 ) ;
V_56 -> V_84 = NULL ;
F_6 ( V_56 -> V_81 ) ;
V_56 -> V_81 = NULL ;
}
