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
T_6 * V_28 = F_15 ( V_1 -> V_29 . V_30 -> V_31 ) -> V_32 ;
T_7 V_33 = V_11 [ V_28 -> V_34 - 1 ] ;
if ( ( V_3 == 1 ) || ( V_3 == 2 ) ) {
char V_35 ;
if ( F_16 ( V_35 , V_26 ) )
return - V_9 ;
switch ( V_35 ) {
case '0' :
V_33 -> V_36 . V_37 &=
~ V_38 ;
break;
case '1' :
V_33 -> V_36 . V_37 |=
V_38 ;
break;
default:
return ( - V_39 ) ;
}
return ( V_3 ) ;
}
return ( - V_39 ) ;
}
static T_1 F_17 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( V_1 -> V_29 . V_30 -> V_31 ) -> V_32 ;
T_7 V_33 = V_11 [ V_28 -> V_34 - 1 ] ;
if ( ( V_3 == 1 ) || ( V_3 == 2 ) ) {
char V_35 ;
if ( F_16 ( V_35 , V_26 ) )
return - V_9 ;
switch ( V_35 ) {
case '0' :
V_33 -> V_36 . V_37 &=
~ V_40 ;
break;
case '1' :
V_33 -> V_36 . V_37 |=
V_40 ;
break;
default:
return ( - V_39 ) ;
}
return ( V_3 ) ;
}
return ( - V_39 ) ;
}
static int F_18 ( struct V_41 * V_42 , void * V_43 )
{
T_6 * V_28 = V_42 -> V_44 ;
T_7 V_33 = V_11 [ V_28 -> V_34 - 1 ] ;
F_19 ( V_42 , L_2 ,
( V_33 -> V_36 .
V_37 & V_40 ) ? L_3 :
L_4 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_21 ( V_1 , F_18 , F_15 ( V_19 ) -> V_32 ) ;
}
static int F_22 ( struct V_41 * V_42 , void * V_43 )
{
T_6 * V_28 = V_42 -> V_44 ;
T_7 V_33 = V_11 [ V_28 -> V_34 - 1 ] ;
F_19 ( V_42 , L_2 ,
( V_33 -> V_36 .
V_37 & V_38 )
? L_3 : L_4 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_21 ( V_1 , F_22 , F_15 ( V_19 ) -> V_32 ) ;
}
static T_1 F_24 ( struct V_1 * V_1 , const char T_2 * V_26 ,
T_3 V_3 , T_4 * V_27 )
{
T_6 * V_28 = F_15 ( V_1 -> V_29 . V_30 -> V_31 ) -> V_32 ;
T_7 V_33 = V_11 [ V_28 -> V_34 - 1 ] ;
char V_35 [ 4 ] ;
if ( V_3 <= 4 )
return - V_39 ;
if ( F_25 ( V_35 , V_26 , 4 ) )
return - V_9 ;
if ( ! memcmp ( V_35 , L_5 , 4 ) ) {
( * ( V_33 -> V_45 ) ) ( V_33 , V_33 -> V_46 ) ;
return ( V_3 ) ;
}
return ( - V_39 ) ;
}
static int F_26 ( struct V_41 * V_42 , void * V_43 )
{
int V_47 = 0 ;
char * V_48 ;
char V_8 [ 16 ] ;
T_6 * V_28 = V_42 -> V_44 ;
T_7 V_33 = V_11 [ V_28 -> V_34 - 1 ] ;
F_19 ( V_42 , L_6 , V_33 -> V_12 . V_13 ) ;
F_19 ( V_42 , L_7 , V_28 -> V_49 ) ;
F_19 ( V_42 , L_8 , V_33 -> V_12 . V_50 ) ;
F_19 ( V_42 , L_9 ,
V_33 -> V_51 , V_33 -> V_52 ) ;
F_4 ( V_33 , V_8 ) ;
F_19 ( V_42 , L_10 , V_8 ) ;
F_19 ( V_42 , L_11 , V_33 -> V_14 . V_15 ) ;
F_19 ( V_42 , L_12 , V_28 -> V_53 ) ;
F_19 ( V_42 , L_13 , V_28 -> V_54 ) ;
F_19 ( V_42 , L_14 , V_28 -> V_34 ) ;
F_19 ( V_42 , L_15 ,
( V_28 -> V_55 ==
V_56 ) ? L_16 : L_17 ) ;
F_19 ( V_42 , L_18 , V_28 -> V_57 ) ;
if ( V_28 -> V_55 == V_58 ) {
F_19 ( V_42 , L_19 , V_28 -> V_59 . V_60 . V_61 ) ;
F_19 ( V_42 , L_20 , V_28 -> V_59 . V_60 . V_62 ) ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
if ( V_28 -> V_59 . V_60 . V_63 [ V_47 ] ) {
F_19 ( V_42 ,
L_21 ,
V_47 , V_28 -> V_59 . V_60 . V_63 [ V_47 ] ,
( unsigned long ) V_28 -> V_59 .
V_60 . V_64 [ V_47 ] ) ;
if ( V_28 -> V_59 . V_60 . V_65 [ V_47 ] ) {
F_19 ( V_42 ,
L_22 ,
V_28 -> V_59 . V_60 .
V_65 [ V_47 ] ) ;
}
F_27 ( V_42 , '\n' ) ;
}
}
}
if ( ( ! V_28 -> V_66 . V_67 ) &&
( ( ! V_28 -> V_66 . V_68 ) ||
( ! V_28 -> V_66 . V_69 )
|| ( ! V_28 -> V_66 . V_70 ) ) ) {
if ( ! V_33 -> V_14 . V_15 ) {
V_48 = L_23 ;
} else {
V_48 = L_24 ;
}
} else if ( V_28 -> V_66 . V_71 ) {
V_48 = L_25 ;
} else if ( V_28 -> V_66 . V_72 ) {
V_48 = L_26 ;
} else {
V_48 = L_27 ;
}
F_19 ( V_42 , L_28 , V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_19 * V_19 , struct V_1 * V_1 )
{
return F_21 ( V_1 , F_26 , F_15 ( V_19 ) -> V_32 ) ;
}
int F_29 ( T_6 * V_28 )
{
struct V_73 * V_74 , * V_75 ;
char V_76 [ 16 ] ;
sprintf ( V_76 , L_29 , V_77 , V_28 -> V_34 ) ;
if ( ! ( V_74 = F_30 ( V_76 , V_24 ) ) )
return ( 0 ) ;
V_28 -> V_78 = ( void * ) V_74 ;
V_75 = F_31 ( V_79 , V_23 | V_80 , V_74 ,
& V_81 , V_28 ) ;
if ( ! V_75 )
return ( 0 ) ;
V_28 -> V_82 = ( void * ) V_75 ;
V_75 = F_31 ( V_83 , V_23 | V_80 , V_74 ,
& V_84 , V_28 ) ;
if ( V_75 )
V_28 -> V_85 = ( void * ) V_75 ;
V_75 = F_31 ( V_86 , V_23 | V_80 , V_74 ,
& V_87 , V_28 ) ;
if ( V_75 )
V_28 -> V_88 = ( void * ) V_75 ;
F_32 ( ( L_30 , V_76 ) ) ;
return ( 1 ) ;
}
void F_33 ( T_6 * V_28 )
{
char V_76 [ 16 ] ;
if ( V_28 -> V_78 ) {
if ( V_28 -> V_88 ) {
F_13 ( V_86 ,
(struct V_73 * ) V_28 -> V_78 ) ;
}
if ( V_28 -> V_85 ) {
F_13 ( V_83 ,
(struct V_73 * ) V_28 -> V_78 ) ;
}
if ( V_28 -> V_82 ) {
F_13 ( V_79 ,
(struct V_73 * ) V_28 -> V_78 ) ;
}
sprintf ( V_76 , L_29 , V_77 , V_28 -> V_34 ) ;
F_13 ( V_76 , V_24 ) ;
F_32 ( ( L_31 , V_77 ,
V_28 -> V_34 ) ) ;
}
}
