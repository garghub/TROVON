static T_1
F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
int V_5 = 0 ;
int V_6 ;
char V_7 [ 80 ] ;
char V_8 [ 16 ] ;
if ( * V_4 )
return 0 ;
F_2 ( V_7 ) ;
if ( F_3 ( V_2 + V_5 , & V_7 , strlen ( V_7 ) ) )
return - V_9 ;
V_5 += strlen ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
if ( V_11 [ V_6 ] ) {
F_4 ( V_11 [ V_6 ] ,
V_8 ) ;
sprintf ( V_7 ,
L_1 ,
V_6 + 1 ,
V_11 [ V_6 ] -> V_12 . V_13 ,
V_8 ,
V_11 [ V_6 ] -> V_14 . V_15 ) ;
if ( ( strlen ( V_7 ) + V_5 ) > V_3 )
break;
if ( F_3
( V_2 + V_5 , & V_7 ,
strlen ( V_7 ) ) ) return - V_9 ;
V_5 += strlen ( V_7 ) ;
}
}
* V_4 += V_5 ;
return ( V_5 ) ;
}
static T_1
F_5 ( struct V_1 * V_1 , const char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
return ( - V_16 ) ;
}
static unsigned int F_6 ( struct V_1 * V_1 , T_5 * V_17 )
{
return ( V_18 ) ;
}
static int F_7 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_8 ( V_19 , V_1 ) ;
}
static int F_9 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return ( 0 ) ;
}
int F_10 ( void )
{
V_20 = F_11 ( V_21 , V_22 | V_23 ,
V_24 , & V_25 ) ;
if ( ! V_20 )
return ( 0 ) ;
return ( 1 ) ;
}
void F_12 ( void )
{
if ( V_20 ) {
F_13 ( V_21 , V_24 ) ;
V_20 = NULL ;
}
}
static T_1 F_14 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( F_16 ( V_1 ) ) ;
T_7 V_29 = V_11 [ V_28 -> V_30 - 1 ] ;
if ( ( V_3 == 1 ) || ( V_3 == 2 ) ) {
char V_31 ;
if ( F_17 ( V_31 , V_26 ) )
return - V_9 ;
switch ( V_31 ) {
case '0' :
V_29 -> V_32 . V_33 &=
~ V_34 ;
break;
case '1' :
V_29 -> V_32 . V_33 |=
V_34 ;
break;
default:
return ( - V_35 ) ;
}
return ( V_3 ) ;
}
return ( - V_35 ) ;
}
static T_1 F_18 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( F_16 ( V_1 ) ) ;
T_7 V_29 = V_11 [ V_28 -> V_30 - 1 ] ;
if ( ( V_3 == 1 ) || ( V_3 == 2 ) ) {
char V_31 ;
if ( F_17 ( V_31 , V_26 ) )
return - V_9 ;
switch ( V_31 ) {
case '0' :
V_29 -> V_32 . V_33 &=
~ V_36 ;
break;
case '1' :
V_29 -> V_32 . V_33 |=
V_36 ;
break;
default:
return ( - V_35 ) ;
}
return ( V_3 ) ;
}
return ( - V_35 ) ;
}
static int F_19 ( struct V_37 * V_38 , void * V_39 )
{
T_6 * V_28 = V_38 -> V_40 ;
T_7 V_29 = V_11 [ V_28 -> V_30 - 1 ] ;
F_20 ( V_38 , L_2 ,
( V_29 -> V_32 .
V_33 & V_36 ) ? L_3 :
L_4 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_22 ( V_1 , F_19 , F_15 ( V_19 ) ) ;
}
static int F_23 ( struct V_37 * V_38 , void * V_39 )
{
T_6 * V_28 = V_38 -> V_40 ;
T_7 V_29 = V_11 [ V_28 -> V_30 - 1 ] ;
F_20 ( V_38 , L_2 ,
( V_29 -> V_32 .
V_33 & V_34 )
? L_3 : L_4 ) ;
return 0 ;
}
static int F_24 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_22 ( V_1 , F_23 , F_15 ( V_19 ) ) ;
}
static T_1 F_25 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( F_16 ( V_1 ) ) ;
T_7 V_29 = V_11 [ V_28 -> V_30 - 1 ] ;
char V_31 [ 4 ] ;
if ( V_3 <= 4 )
return - V_35 ;
if ( F_26 ( V_31 , V_26 , 4 ) )
return - V_9 ;
if ( ! memcmp ( V_31 , L_5 , 4 ) ) {
( * ( V_29 -> V_41 ) ) ( V_29 , V_29 -> V_42 ) ;
return ( V_3 ) ;
}
return ( - V_35 ) ;
}
static int F_27 ( struct V_37 * V_38 , void * V_39 )
{
int V_43 = 0 ;
char * V_44 ;
char V_8 [ 16 ] ;
T_6 * V_28 = V_38 -> V_40 ;
T_7 V_29 = V_11 [ V_28 -> V_30 - 1 ] ;
F_20 ( V_38 , L_6 , V_29 -> V_12 . V_13 ) ;
F_20 ( V_38 , L_7 , V_28 -> V_45 ) ;
F_20 ( V_38 , L_8 , V_29 -> V_12 . V_46 ) ;
F_20 ( V_38 , L_9 ,
V_29 -> V_47 , V_29 -> V_48 ) ;
F_4 ( V_29 , V_8 ) ;
F_20 ( V_38 , L_10 , V_8 ) ;
F_20 ( V_38 , L_11 , V_29 -> V_14 . V_15 ) ;
F_20 ( V_38 , L_12 , V_28 -> V_49 ) ;
F_20 ( V_38 , L_13 , V_28 -> V_50 ) ;
F_20 ( V_38 , L_14 , V_28 -> V_30 ) ;
F_20 ( V_38 , L_15 ,
( V_28 -> V_51 ==
V_52 ) ? L_16 : L_17 ) ;
F_20 ( V_38 , L_18 , V_28 -> V_53 ) ;
if ( V_28 -> V_51 == V_54 ) {
F_20 ( V_38 , L_19 , V_28 -> V_55 . V_56 . V_57 ) ;
F_20 ( V_38 , L_20 , V_28 -> V_55 . V_56 . V_58 ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( V_28 -> V_55 . V_56 . V_59 [ V_43 ] ) {
F_20 ( V_38 ,
L_21 ,
V_43 , V_28 -> V_55 . V_56 . V_59 [ V_43 ] ,
( unsigned long ) V_28 -> V_55 .
V_56 . V_60 [ V_43 ] ) ;
if ( V_28 -> V_55 . V_56 . V_61 [ V_43 ] ) {
F_20 ( V_38 ,
L_22 ,
V_28 -> V_55 . V_56 .
V_61 [ V_43 ] ) ;
}
F_28 ( V_38 , '\n' ) ;
}
}
}
if ( ( ! V_28 -> V_62 . V_63 ) &&
( ( ! V_28 -> V_62 . V_64 ) ||
( ! V_28 -> V_62 . V_65 )
|| ( ! V_28 -> V_62 . V_66 ) ) ) {
if ( ! V_29 -> V_14 . V_15 ) {
V_44 = L_23 ;
} else {
V_44 = L_24 ;
}
} else if ( V_28 -> V_62 . V_67 ) {
V_44 = L_25 ;
} else if ( V_28 -> V_62 . V_68 ) {
V_44 = L_26 ;
} else {
V_44 = L_27 ;
}
F_20 ( V_38 , L_28 , V_44 ) ;
return 0 ;
}
static int F_29 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_22 ( V_1 , F_27 , F_15 ( V_19 ) ) ;
}
int F_30 ( T_6 * V_28 )
{
struct V_69 * V_70 , * V_71 ;
char V_72 [ 16 ] ;
sprintf ( V_72 , L_29 , V_73 , V_28 -> V_30 ) ;
if ( ! ( V_70 = F_31 ( V_72 , V_24 ) ) )
return ( 0 ) ;
V_28 -> V_74 = ( void * ) V_70 ;
V_71 = F_32 ( V_75 , V_23 | V_76 , V_70 ,
& V_77 , V_28 ) ;
if ( ! V_71 )
return ( 0 ) ;
V_28 -> V_78 = ( void * ) V_71 ;
V_71 = F_32 ( V_79 , V_23 | V_76 , V_70 ,
& V_80 , V_28 ) ;
if ( V_71 )
V_28 -> V_81 = ( void * ) V_71 ;
V_71 = F_32 ( V_82 , V_23 | V_76 , V_70 ,
& V_83 , V_28 ) ;
if ( V_71 )
V_28 -> V_84 = ( void * ) V_71 ;
F_33 ( ( L_30 , V_72 ) ) ;
return ( 1 ) ;
}
void F_34 ( T_6 * V_28 )
{
char V_72 [ 16 ] ;
if ( V_28 -> V_74 ) {
if ( V_28 -> V_84 ) {
F_13 ( V_82 ,
(struct V_69 * ) V_28 -> V_74 ) ;
}
if ( V_28 -> V_81 ) {
F_13 ( V_79 ,
(struct V_69 * ) V_28 -> V_74 ) ;
}
if ( V_28 -> V_78 ) {
F_13 ( V_75 ,
(struct V_69 * ) V_28 -> V_74 ) ;
}
sprintf ( V_72 , L_29 , V_73 , V_28 -> V_30 ) ;
F_13 ( V_72 , V_24 ) ;
F_33 ( ( L_31 , V_73 ,
V_28 -> V_30 ) ) ;
}
}
