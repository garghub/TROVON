static void T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const char * V_5 = L_1 ;
const char * V_6 = L_2 ;
void T_2 * V_7 ;
unsigned long V_8 ;
int V_9 ;
V_7 = F_2 ( V_2 , 0 ) ;
if ( F_3 ( ! V_7 ) )
return;
V_10 . V_11 = 2 + V_4 -> V_12 ;
V_10 . V_13 = F_4 ( V_10 . V_11 * sizeof( struct V_14 * ) ,
V_15 ) ;
if ( F_3 ( ! V_10 . V_13 ) )
return;
F_5 ( V_2 , L_3 , 0 ,
& V_5 ) ;
V_8 = V_4 -> V_16 ( V_7 ) ;
V_10 . V_13 [ 0 ] = F_6 ( NULL , V_5 , NULL ,
V_17 , V_8 ) ;
F_3 ( F_7 ( V_10 . V_13 [ 0 ] ) ) ;
F_5 ( V_2 , L_3 , 1 ,
& V_6 ) ;
V_8 = V_4 -> V_18 ( V_7 ) ;
V_10 . V_13 [ 1 ] = F_6 ( NULL , V_6 , NULL ,
V_17 , V_8 ) ;
F_3 ( F_7 ( V_10 . V_13 [ 1 ] ) ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_12 ; V_9 ++ ) {
const char * V_19 = V_4 -> V_20 [ V_9 ] . V_21 ;
int V_22 , div ;
F_5 ( V_2 , L_3 ,
2 + V_9 , & V_19 ) ;
V_4 -> V_23 ( V_7 , V_4 -> V_20 [ V_9 ] . V_24 ,
& V_22 , & div ) ;
V_10 . V_13 [ 2 + V_9 ] = F_8 ( NULL , V_19 ,
V_6 , 0 , V_22 , div ) ;
F_3 ( F_7 ( V_10 . V_13 [ 2 + V_9 ] ) ) ;
} ;
F_9 ( V_7 ) ;
F_10 ( V_2 , V_25 , & V_10 ) ;
}
static T_3 T_1 F_11 ( void T_2 * V_26 )
{
T_4 V_27 = 0 ;
V_27 = ( ( F_12 ( V_26 ) >> V_28 ) &
V_29 ) ;
return V_30 [ V_27 ] ;
}
static T_3 T_1 F_13 ( void T_2 * V_26 )
{
T_3 V_31 ;
T_4 V_32 = 0 ;
V_32 = ( ( F_12 ( V_26 ) >> V_33 ) &
V_34 ) ;
if ( V_32 >= F_14 ( V_35 ) ) {
F_15 ( L_4 , V_32 ) ;
V_31 = 0 ;
} else
V_31 = V_35 [ V_32 ] ;
return V_31 ;
}
static void T_1 F_16 ( T_3 V_36 ,
void T_2 * V_26 , int V_24 , int * V_22 , int * div )
{
switch ( V_24 ) {
case V_37 :
* V_22 = V_38 [ V_36 ] [ 0 ] ;
* div = V_38 [ V_36 ] [ 1 ] ;
break;
case V_39 :
* V_22 = V_40 [ V_36 ] [ 0 ] ;
* div = V_40 [ V_36 ] [ 1 ] ;
break;
case V_41 :
* V_22 = V_42 [ V_36 ] [ 0 ] ;
* div = V_42 [ V_36 ] [ 1 ] ;
break;
}
}
static void T_1 F_17 (
void T_2 * V_26 , int V_24 , int * V_22 , int * div )
{
T_3 V_36 = ( ( F_12 ( V_26 ) >> V_43 ) &
V_44 ) ;
F_16 ( V_36 , V_26 , V_24 , V_22 , div ) ;
}
static T_3 T_1 F_18 ( void T_2 * V_26 )
{
return 250 * 1000 * 1000 ;
}
static T_3 T_1 F_19 ( void T_2 * V_26 )
{
T_3 V_31 ;
T_4 V_32 = 0 ;
V_32 = ( ( F_12 ( V_26 ) >> V_45 ) &
V_46 ) ;
V_32 |= ( ( ( F_12 ( V_26 + 4 ) >> V_47 ) &
V_48 )
<< V_49 ) ;
if ( V_32 >= F_14 ( V_50 ) ) {
F_15 ( L_5 , V_32 ) ;
V_31 = 0 ;
} else
V_31 = V_50 [ V_32 ] ;
return V_31 ;
}
static void T_1 F_20 (
void T_2 * V_26 , int V_24 , int * V_22 , int * div )
{
T_3 V_36 = ( ( F_12 ( V_26 ) >> V_51 ) &
V_52 ) ;
V_36 |= ( ( ( F_12 ( V_26 + 4 ) >> V_53 ) &
V_54 )
<< V_55 ) ;
F_16 ( V_36 , V_26 , V_24 , V_22 , div ) ;
}
static T_3 T_1 F_21 ( void T_2 * V_26 )
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_56 ) &
V_57 ;
return V_58 [ V_36 ] ;
}
static T_3 T_1 F_22 ( void T_2 * V_26 )
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_59 ) &
V_60 ;
return V_61 [ V_36 ] ;
}
static void T_1 F_23 (
void T_2 * V_26 , int V_24 , int * V_22 , int * div )
{
switch ( V_24 ) {
case V_62 :
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_63 ) &
V_64 ;
* V_22 = V_65 [ V_36 ] [ 0 ] ;
* div = V_65 [ V_36 ] [ 1 ] ;
break;
}
case V_66 :
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_67 ) &
V_68 ;
* V_22 = V_69 [ V_36 ] [ 0 ] ;
* div = V_69 [ V_36 ] [ 1 ] ;
break;
}
}
}
static T_3 T_1 F_24 ( void T_2 * V_26 )
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_70 ) &
V_71 ;
return ( V_36 ) ? 166666667 : 200000000 ;
}
static T_3 T_1 F_25 ( void T_2 * V_26 )
{
T_3 V_36 = F_26 ( F_12 ( V_26 ) ) ;
return V_72 [ V_36 ] ;
}
static void T_1 F_27 (
void T_2 * V_26 , int V_24 , int * V_22 , int * div )
{
switch ( V_24 ) {
case V_73 :
{
T_3 V_36 = F_28 ( F_12 ( V_26 ) ) ;
* V_22 = V_74 [ V_36 ] [ 0 ] ;
* div = V_74 [ V_36 ] [ 1 ] ;
break;
}
case V_75 :
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_76 ) &
V_77 ;
* V_22 = V_78 [ V_36 ] [ 0 ] ;
* div = V_78 [ V_36 ] [ 1 ] ;
break;
}
}
}
static T_3 T_1 F_29 ( void T_2 * V_26 )
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_79 ) & V_80 ;
return V_81 [ V_36 ] ;
}
static void T_1 F_30 (
void T_2 * V_26 , int V_24 , int * V_22 , int * div )
{
switch ( V_24 ) {
case V_73 :
{
* V_22 = 1 ;
* div = 2 ;
break;
}
case V_75 :
{
T_3 V_36 = ( F_12 ( V_26 ) >> V_79 ) &
V_80 ;
* V_22 = V_82 [ V_36 ] [ 0 ] ;
* div = V_82 [ V_36 ] [ 1 ] ;
break;
}
}
}
void T_1 F_31 ( void )
{
struct V_1 * V_2 ;
F_32 (np, clk_core_match) {
const struct V_83 * V_84 =
F_33 ( V_85 , V_2 ) ;
F_1 ( V_2 , (struct V_3 * ) V_84 -> V_86 ) ;
}
}
