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
T_6 * V_28 = F_15 ( F_16 ( V_1 ) ) -> V_29 ;
T_7 V_30 = V_11 [ V_28 -> V_31 - 1 ] ;
if ( ( V_3 == 1 ) || ( V_3 == 2 ) ) {
char V_32 ;
if ( F_17 ( V_32 , V_26 ) )
return - V_9 ;
switch ( V_32 ) {
case '0' :
V_30 -> V_33 . V_34 &=
~ V_35 ;
break;
case '1' :
V_30 -> V_33 . V_34 |=
V_35 ;
break;
default:
return ( - V_36 ) ;
}
return ( V_3 ) ;
}
return ( - V_36 ) ;
}
static T_1 F_18 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( F_16 ( V_1 ) ) -> V_29 ;
T_7 V_30 = V_11 [ V_28 -> V_31 - 1 ] ;
if ( ( V_3 == 1 ) || ( V_3 == 2 ) ) {
char V_32 ;
if ( F_17 ( V_32 , V_26 ) )
return - V_9 ;
switch ( V_32 ) {
case '0' :
V_30 -> V_33 . V_34 &=
~ V_37 ;
break;
case '1' :
V_30 -> V_33 . V_34 |=
V_37 ;
break;
default:
return ( - V_36 ) ;
}
return ( V_3 ) ;
}
return ( - V_36 ) ;
}
static int F_19 ( struct V_38 * V_39 , void * V_40 )
{
T_6 * V_28 = V_39 -> V_41 ;
T_7 V_30 = V_11 [ V_28 -> V_31 - 1 ] ;
F_20 ( V_39 , L_2 ,
( V_30 -> V_33 .
V_34 & V_37 ) ? L_3 :
L_4 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_22 ( V_1 , F_19 , F_15 ( V_19 ) -> V_29 ) ;
}
static int F_23 ( struct V_38 * V_39 , void * V_40 )
{
T_6 * V_28 = V_39 -> V_41 ;
T_7 V_30 = V_11 [ V_28 -> V_31 - 1 ] ;
F_20 ( V_39 , L_2 ,
( V_30 -> V_33 .
V_34 & V_35 )
? L_3 : L_4 ) ;
return 0 ;
}
static int F_24 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_22 ( V_1 , F_23 , F_15 ( V_19 ) -> V_29 ) ;
}
static T_1 F_25 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( F_16 ( V_1 ) ) -> V_29 ;
T_7 V_30 = V_11 [ V_28 -> V_31 - 1 ] ;
char V_32 [ 4 ] ;
if ( V_3 <= 4 )
return - V_36 ;
if ( F_26 ( V_32 , V_26 , 4 ) )
return - V_9 ;
if ( ! memcmp ( V_32 , L_5 , 4 ) ) {
( * ( V_30 -> V_42 ) ) ( V_30 , V_30 -> V_43 ) ;
return ( V_3 ) ;
}
return ( - V_36 ) ;
}
static int F_27 ( struct V_38 * V_39 , void * V_40 )
{
int V_44 = 0 ;
char * V_45 ;
char V_8 [ 16 ] ;
T_6 * V_28 = V_39 -> V_41 ;
T_7 V_30 = V_11 [ V_28 -> V_31 - 1 ] ;
F_20 ( V_39 , L_6 , V_30 -> V_12 . V_13 ) ;
F_20 ( V_39 , L_7 , V_28 -> V_46 ) ;
F_20 ( V_39 , L_8 , V_30 -> V_12 . V_47 ) ;
F_20 ( V_39 , L_9 ,
V_30 -> V_48 , V_30 -> V_49 ) ;
F_4 ( V_30 , V_8 ) ;
F_20 ( V_39 , L_10 , V_8 ) ;
F_20 ( V_39 , L_11 , V_30 -> V_14 . V_15 ) ;
F_20 ( V_39 , L_12 , V_28 -> V_50 ) ;
F_20 ( V_39 , L_13 , V_28 -> V_51 ) ;
F_20 ( V_39 , L_14 , V_28 -> V_31 ) ;
F_20 ( V_39 , L_15 ,
( V_28 -> V_52 ==
V_53 ) ? L_16 : L_17 ) ;
F_20 ( V_39 , L_18 , V_28 -> V_54 ) ;
if ( V_28 -> V_52 == V_55 ) {
F_20 ( V_39 , L_19 , V_28 -> V_56 . V_57 . V_58 ) ;
F_20 ( V_39 , L_20 , V_28 -> V_56 . V_57 . V_59 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
if ( V_28 -> V_56 . V_57 . V_60 [ V_44 ] ) {
F_20 ( V_39 ,
L_21 ,
V_44 , V_28 -> V_56 . V_57 . V_60 [ V_44 ] ,
( unsigned long ) V_28 -> V_56 .
V_57 . V_61 [ V_44 ] ) ;
if ( V_28 -> V_56 . V_57 . V_62 [ V_44 ] ) {
F_20 ( V_39 ,
L_22 ,
V_28 -> V_56 . V_57 .
V_62 [ V_44 ] ) ;
}
F_28 ( V_39 , '\n' ) ;
}
}
}
if ( ( ! V_28 -> V_63 . V_64 ) &&
( ( ! V_28 -> V_63 . V_65 ) ||
( ! V_28 -> V_63 . V_66 )
|| ( ! V_28 -> V_63 . V_67 ) ) ) {
if ( ! V_30 -> V_14 . V_15 ) {
V_45 = L_23 ;
} else {
V_45 = L_24 ;
}
} else if ( V_28 -> V_63 . V_68 ) {
V_45 = L_25 ;
} else if ( V_28 -> V_63 . V_69 ) {
V_45 = L_26 ;
} else {
V_45 = L_27 ;
}
F_20 ( V_39 , L_28 , V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_22 ( V_1 , F_27 , F_15 ( V_19 ) -> V_29 ) ;
}
int F_30 ( T_6 * V_28 )
{
struct V_70 * V_71 , * V_72 ;
char V_73 [ 16 ] ;
sprintf ( V_73 , L_29 , V_74 , V_28 -> V_31 ) ;
if ( ! ( V_71 = F_31 ( V_73 , V_24 ) ) )
return ( 0 ) ;
V_28 -> V_75 = ( void * ) V_71 ;
V_72 = F_32 ( V_76 , V_23 | V_77 , V_71 ,
& V_78 , V_28 ) ;
if ( ! V_72 )
return ( 0 ) ;
V_28 -> V_79 = ( void * ) V_72 ;
V_72 = F_32 ( V_80 , V_23 | V_77 , V_71 ,
& V_81 , V_28 ) ;
if ( V_72 )
V_28 -> V_82 = ( void * ) V_72 ;
V_72 = F_32 ( V_83 , V_23 | V_77 , V_71 ,
& V_84 , V_28 ) ;
if ( V_72 )
V_28 -> V_85 = ( void * ) V_72 ;
F_33 ( ( L_30 , V_73 ) ) ;
return ( 1 ) ;
}
void F_34 ( T_6 * V_28 )
{
char V_73 [ 16 ] ;
if ( V_28 -> V_75 ) {
if ( V_28 -> V_85 ) {
F_13 ( V_83 ,
(struct V_70 * ) V_28 -> V_75 ) ;
}
if ( V_28 -> V_82 ) {
F_13 ( V_80 ,
(struct V_70 * ) V_28 -> V_75 ) ;
}
if ( V_28 -> V_79 ) {
F_13 ( V_76 ,
(struct V_70 * ) V_28 -> V_75 ) ;
}
sprintf ( V_73 , L_29 , V_74 , V_28 -> V_31 ) ;
F_13 ( V_73 , V_24 ) ;
F_33 ( ( L_31 , V_74 ,
V_28 -> V_31 ) ) ;
}
}
