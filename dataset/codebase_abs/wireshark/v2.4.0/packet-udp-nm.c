static T_1
F_1 ( void * V_1 , char * * V_2 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
char V_4 ;
* V_2 = NULL ;
if ( V_3 -> V_5 == 0 ) {
* V_2 = F_2 ( L_1 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_5 ) ;
return ( * V_2 == NULL ) ;
}
if ( V_3 -> V_5 > 4 ) {
* V_2 = F_2 ( L_2 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_5 ) ;
return ( * V_2 == NULL ) ;
}
if ( V_3 -> V_7 < 2 ) {
* V_2 = F_2 ( L_3 , V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_5 ) ;
return ( * V_2 == NULL ) ;
}
if ( V_3 -> V_8 >= V_9 ) {
* V_2 = F_2 ( L_4 , V_3 -> V_6 ) ;
return ( * V_2 == NULL ) ;
}
if ( V_3 -> V_6 == NULL ) {
* V_2 = F_2 ( L_5 ) ;
return ( * V_2 == NULL ) ;
}
F_3 ( V_3 -> V_6 ) ;
if ( V_3 -> V_6 [ 0 ] == 0 ) {
* V_2 = F_2 ( L_5 ) ;
return ( * V_2 == NULL ) ;
}
V_4 = F_4 ( V_3 -> V_6 ) ;
if ( V_4 ) {
* V_2 = F_2 ( L_6 , V_4 ) ;
return ( * V_2 == NULL ) ;
}
return ( * V_2 == NULL ) ;
}
static void *
F_5 ( void * V_10 , const void * V_11 , T_3 T_4 V_12 )
{
T_2 * V_13 = ( T_2 * ) V_10 ;
const T_2 * V_14 = ( const T_2 * ) V_11 ;
if ( V_14 -> V_6 ) {
V_13 -> V_6 = F_6 ( V_14 -> V_6 ) ;
}
else {
V_13 -> V_6 = NULL ;
}
if ( V_14 -> V_15 ) {
V_13 -> V_15 = F_6 ( V_14 -> V_15 ) ;
}
else {
V_13 -> V_15 = NULL ;
}
V_13 -> V_7 = V_14 -> V_7 ;
V_13 -> V_5 = V_14 -> V_5 ;
V_13 -> V_8 = V_14 -> V_8 ;
if ( V_14 -> V_16 ) {
V_13 -> V_16 = F_6 ( V_14 -> V_16 ) ;
}
else {
V_13 -> V_16 = NULL ;
}
return V_13 ;
}
static void
F_7 ( void * V_1 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
if ( V_3 -> V_6 ) F_8 ( V_3 -> V_6 ) ;
if ( V_3 -> V_15 ) F_8 ( V_3 -> V_15 ) ;
if ( V_3 -> V_16 ) F_8 ( V_3 -> V_16 ) ;
}
static T_5
F_9 ( T_6 V_17 , T_6 V_18 )
{
T_5 V_19 = V_17 ;
return ( V_19 * 0x100000000 ) ^ V_18 ;
}
static T_7 *
F_10 ( T_2 V_20 )
{
T_7 * V_19 = NULL ;
V_19 = F_2 ( L_7 , V_20 . V_7 , V_20 . V_5 , V_20 . V_8 , V_20 . V_6 ) ;
return V_19 ;
}
static T_8 *
F_11 ( T_7 * V_21 )
{
T_8 * V_22 = NULL ;
if ( V_23 ) {
V_22 = ( T_8 * ) F_12 ( V_23 , V_21 ) ;
}
else {
V_22 = NULL ;
}
return V_22 ;
}
static T_8 *
F_13 ( T_6 V_17 , T_6 V_18 )
{
T_8 * V_24 = NULL ;
T_5 V_21 = F_9 ( V_17 , V_18 ) ;
if ( V_25 ) {
V_24 = ( T_8 * ) F_12 ( V_25 , & V_21 ) ;
}
else {
V_24 = NULL ;
}
return V_24 ;
}
static void
F_14 ( void )
{
static T_9 * V_26 ;
T_8 * V_22 ;
T_10 V_27 ;
T_7 * V_28 = NULL ;
T_5 * V_21 = NULL ;
static T_8 V_29 = - 1 ;
static T_8 * V_30 [] = {
& V_29 ,
} ;
static T_8 * V_24 ;
if ( V_23 && V_26 ) {
T_10 V_31 = F_15 ( V_23 ) ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
F_16 ( V_32 , * ( V_26 [ V_27 ] . V_33 ) ) ;
}
F_17 ( V_23 ) ;
V_23 = NULL ;
}
if ( V_34 ) {
V_23 = F_18 ( V_35 , V_36 ) ;
V_26 = F_19 ( T_9 , V_34 ) ;
if ( V_25 == NULL ) {
V_25 = F_18 ( V_37 , V_38 ) ;
}
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
V_22 = F_20 ( T_8 , 1 ) ;
* V_22 = - 1 ;
V_26 [ V_27 ] . V_33 = V_22 ;
V_26 [ V_27 ] . V_39 . V_40 = NULL ;
V_26 [ V_27 ] . V_39 . V_41 = V_42 [ V_27 ] . V_8 ;
V_26 [ V_27 ] . V_39 . V_43 = NULL ;
V_26 [ V_27 ] . V_39 . V_44 = - 1 ;
if ( V_42 [ V_27 ] . V_8 == 0 || V_42 [ V_27 ] . V_5 <= 0 || V_42 [ V_27 ] . V_5 > 4 ) {
V_26 [ V_27 ] . V_39 . V_45 = F_6 ( V_42 [ V_27 ] . V_6 ) ;
V_26 [ V_27 ] . V_39 . V_46 = F_2 ( L_8 , V_42 [ V_27 ] . V_6 ) ;
V_26 [ V_27 ] . V_39 . type = V_47 ;
V_26 [ V_27 ] . V_39 . V_48 = V_49 ;
V_26 [ V_27 ] . V_39 . V_41 = 0 ;
V_26 [ V_27 ] . V_39 . V_50 = F_6 ( V_42 [ V_27 ] . V_15 ) ;
}
else {
V_26 [ V_27 ] . V_39 . V_45 = F_6 ( V_42 [ V_27 ] . V_16 ) ;
V_26 [ V_27 ] . V_39 . V_46 = F_2 ( L_9 , V_42 [ V_27 ] . V_6 , V_42 [ V_27 ] . V_16 ) ;
V_26 [ V_27 ] . V_39 . type = V_51 ;
V_26 [ V_27 ] . V_39 . V_48 = 8 * ( V_42 [ V_27 ] . V_5 ) ;
V_26 [ V_27 ] . V_39 . V_50 = F_6 ( V_42 [ V_27 ] . V_16 ) ;
}
V_28 = F_10 ( V_42 [ V_27 ] ) ;
F_21 ( V_23 , V_28 , V_22 ) ;
if ( F_13 ( V_42 [ V_27 ] . V_7 , V_42 [ V_27 ] . V_5 ) == NULL ) {
V_29 = - 1 ;
F_22 ( V_30 , F_23 ( V_30 ) ) ;
V_24 = F_20 ( T_8 , 1 ) ;
* V_24 = V_29 ;
V_21 = F_20 ( T_5 , 1 ) ;
* V_21 = F_9 ( V_42 [ V_27 ] . V_7 , V_42 [ V_27 ] . V_5 ) ;
F_21 ( V_25 , V_21 , V_24 ) ;
}
}
F_24 ( V_32 , V_26 , V_34 ) ;
}
}
static int
F_25 ( T_11 * V_52 , T_12 * T_13 V_12 , T_14 * V_53 , void * T_15 V_12 )
{
T_16 * V_54 ;
T_14 * V_55 ;
T_14 * V_56 = NULL ;
T_7 * V_28 = NULL ;
T_6 V_17 = 0 ;
T_6 V_18 = 0 ;
T_6 V_57 = 0 ;
T_6 V_58 ;
T_6 V_59 = 0 ;
T_10 V_27 = 0 ;
int * V_22 ;
int V_24 ;
T_6 V_60 = 1 ;
T_6 V_61 = 0 ;
static const int * V_62 [] = {
& V_63 ,
& V_64 ,
& V_65 ,
& V_66 ,
NULL
} ;
if ( V_67 == TRUE ) {
V_60 = 0 ;
V_61 = 1 ;
}
F_26 ( T_13 -> V_68 , V_69 , L_10 ) ;
F_27 ( T_13 -> V_68 , V_70 ) ;
V_57 = F_28 ( V_52 ) ;
V_54 = F_29 ( V_53 , V_32 , V_52 , 0 , - 1 , V_71 ) ;
V_55 = F_30 ( V_54 , V_72 ) ;
if ( V_67 == FALSE ) {
F_31 ( V_55 , V_73 , V_52 , V_61 , 1 , V_74 , & V_59 ) ;
}
F_32 ( V_55 , V_52 , V_60 , V_75 , V_76 , V_62 , V_74 ) ;
V_58 = F_33 ( V_52 , V_60 ) ;
if ( V_67 == TRUE ) {
F_31 ( V_55 , V_73 , V_52 , V_61 , 1 , V_74 , & V_59 ) ;
}
F_34 ( T_13 -> V_68 , V_70 , L_11 , V_58 , V_59 ) ;
F_35 ( V_54 , L_12 , V_58 , V_59 ) ;
V_17 = 2 ;
V_54 = F_29 ( V_55 , V_77 , V_52 , V_17 , V_57 - V_17 , V_71 ) ;
V_55 = F_30 ( V_54 , V_78 ) ;
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
V_28 = F_10 ( V_42 [ V_27 ] ) ;
V_22 = F_11 ( V_28 ) ;
V_17 = V_42 [ V_27 ] . V_7 ;
V_18 = V_42 [ V_27 ] . V_5 ;
V_24 = * ( F_13 ( V_17 , V_18 ) ) ;
if ( V_22 && V_57 >= V_18 + V_17 ) {
if ( V_42 [ V_27 ] . V_8 == 0 ) {
V_54 = F_29 ( V_55 , * V_22 , V_52 , V_17 , V_18 , V_74 ) ;
V_56 = F_30 ( V_54 , V_24 ) ;
}
else {
if ( V_56 != NULL ) {
F_29 ( V_56 , * V_22 , V_52 , V_17 , V_18 , V_74 ) ;
}
}
}
else {
}
F_8 ( V_28 ) ;
}
return 8 ;
}
void F_36 ( void )
{
T_17 * V_79 ;
T_18 * V_80 ;
static T_9 V_81 [] = {
{ & V_75 ,
{ L_13 , L_14 , V_82 , V_83 , NULL , 0x0 , L_15 , V_84 } } ,
{ & V_63 ,
{ L_16 , L_17 , V_51 , 8 , F_37 ( & V_85 ) , 0x01 , L_18 , V_84 } } ,
{ & V_64 ,
{ L_19 , L_20 , V_51 , 8 , F_37 ( & V_86 ) , 0x08 , L_21 , V_84 } } ,
{ & V_65 ,
{ L_22 , L_23 , V_51 , 8 , F_37 ( & V_87 ) , 0x10 , L_24 , V_84 } } ,
{ & V_66 ,
{ L_25 , L_26 , V_51 , 8 , F_37 ( & V_88 ) , 0x40 , L_27 , V_84 } } ,
{ & V_73 ,
{ L_28 , L_29 , V_82 , V_89 , NULL , 0x0 , L_30 , V_84 } } ,
{ & V_77 ,
{ L_31 , L_32 , V_47 , V_49 , NULL , 0x0 , L_33 , V_84 } } ,
} ;
static T_8 * V_30 [] = {
& V_72 ,
& V_76 ,
& V_78 ,
} ;
static T_19 V_90 [] = {
F_38 ( V_42 , V_6 , L_34 , L_35 ) ,
F_38 ( V_42 , V_15 , L_36 , L_37 ) ,
F_39 ( V_42 , V_7 , L_38 , L_39 ) ,
F_39 ( V_42 , V_5 , L_40 , L_41 ) ,
F_39 ( V_42 , V_8 , L_42 , L_43 ) ,
F_38 ( V_42 , V_16 , L_44 , L_45 ) ,
V_91
} ;
V_32 = F_40 ( L_46 , L_10 , L_47 ) ;
F_24 ( V_32 , V_81 , F_23 ( V_81 ) ) ;
F_22 ( V_30 , F_23 ( V_30 ) ) ;
V_79 = F_41 ( V_32 , NULL ) ;
F_42 ( V_79 , L_48 ,
L_49 ,
L_50
L_51
L_52 ,
& V_67 ) ;
V_80 = F_43 ( L_53 ,
sizeof( T_2 ) ,
L_54 ,
TRUE ,
& V_42 ,
& V_34 ,
V_92 | V_93 ,
NULL ,
F_5 ,
F_1 ,
F_7 ,
F_14 ,
NULL ,
V_90 ) ;
F_44 ( V_79 , L_55 , L_56 ,
L_57 ,
V_80 ) ;
}
void F_45 ( void )
{
T_20 V_94 = F_46 ( F_25 , V_32 ) ;
F_47 ( L_58 , V_94 ) ;
F_48 ( L_59 , V_94 ) ;
}
