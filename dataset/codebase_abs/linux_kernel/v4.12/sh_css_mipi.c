enum V_1
F_1 ( const unsigned int V_2 ,
const bool V_3 )
{
enum V_1 V_4 = V_5 ;
V_6 . V_2 = V_2 ;
( void ) V_3 ;
return V_4 ;
}
static bool F_2 ( struct V_7 * V_8 ,
unsigned int * V_9 )
{
bool V_10 = true ;
unsigned int V_11 = 0 ;
unsigned int V_12 = 0 ;
switch ( V_8 -> V_13 -> V_14 . V_15 ) {
case V_16 :
V_11 = ( unsigned int ) V_8 -> V_13 -> V_14 . V_17 . V_11 . V_11 ;
V_12 = V_18 ;
break;
case V_19 :
V_11 = ( unsigned int ) V_8 -> V_13 -> V_14 . V_17 . V_20 . V_21 ;
V_12 = V_22 ;
break;
case V_23 :
V_11 = ( unsigned int ) V_8 -> V_13 -> V_14 . V_17 . V_24 . V_21 ;
V_12 = V_25 ;
break;
default:
assert ( false ) ;
V_10 = false ;
break;
}
if ( V_10 ) {
assert ( V_11 < V_12 ) ;
if ( V_11 >= V_12 )
V_10 = false ;
}
* V_9 = V_11 ;
return V_10 ;
}
enum V_1
F_3 ( const unsigned int V_26 ,
const unsigned int V_27 ,
const enum V_28 V_29 ,
const bool V_30 ,
const unsigned int V_31 ,
unsigned int * V_2 )
{
enum V_1 V_4 = V_5 ;
unsigned int V_32 = 0 ;
unsigned int V_33 = 0 ;
unsigned int V_34 = 0 ;
unsigned int V_35 = 0 ;
unsigned int V_36 = 0 ;
unsigned int V_37 = 0 ;
unsigned int V_38 = 0 ;
unsigned int V_39 = 0 ;
unsigned int V_40 = 0 ;
unsigned int V_41 = 0 ;
unsigned int V_42 = 0 ;
unsigned int V_43 = V_26 ;
#if F_4 ( V_44 )
V_43 += ( 2 * V_45 ) ;
#endif
F_5 ( L_1 ,
V_43 , V_27 , V_29 , V_30 , V_31 ) ;
switch ( V_29 ) {
case V_46 :
V_32 = 6 ; break;
case V_47 :
V_32 = 7 ; break;
case V_48 :
case V_49 :
case V_50 :
V_32 = 8 ; break;
case V_51 :
case V_52 :
#if ! F_4 ( V_53 )
V_32 = 10 ;
#else
V_32 = 16 ;
#endif
break;
case V_54 :
case V_55 :
V_32 = 12 ; break;
case V_56 :
V_32 = 14 ; break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_32 = 16 ; break;
case V_61 :
V_32 = 18 ; break;
case V_62 :
V_32 = 20 ; break;
case V_63 :
V_32 = 24 ; break;
case V_64 :
case V_65 :
case V_66 :
default:
return V_67 ;
}
V_34 = ( V_43 * V_32 + 7 ) >> 3 ;
if ( V_29 == V_50
|| V_29 == V_51
|| V_29 == V_64 ) {
V_33 = ( V_43 * 2 * V_32 + 7 ) >> 3 ;
} else {
V_33 = V_34 ;
}
V_35 = ( V_34 + 3 ) >> 2 ;
V_37 = ( V_33 + 3 ) >> 2 ;
V_36 = V_35 + 2 + ( V_30 ? 1 : 0 ) ;
V_35 += ( 1 + ( V_30 ? 2 : 0 ) ) ;
V_37 += ( 1 + ( V_30 ? 2 : 0 ) ) ;
V_39 = ( V_35 + 7 ) >> 3 ;
V_40 = ( V_36 + 7 ) >> 3 ;
V_38 = ( V_37 + 7 ) >> 3 ;
V_41 = 1 ;
V_42 = ( ( V_31 + 7 ) >> 3 ) +
V_40 +
( ( ( V_27 + 1 ) >> 1 ) - 1 ) * V_39 +
( V_27 >> 1 ) * V_38 +
V_41 ;
* V_2 = V_42 ;
F_6 ( V_4 ) ;
return V_4 ;
}
enum V_1
F_7 ( const enum V_68 V_11 ,
const unsigned int V_2 )
{
T_1 V_69 ;
enum V_1 V_4 = V_70 ;
F_8 ( V_11 < V_18 ) ;
F_8 ( V_2 != 0 ) ;
for ( V_69 = 0 ; V_69 < V_71 &&
V_6 . V_72 [ V_11 ] [ V_69 ] != 0 ;
V_69 ++ ) {
}
if ( V_69 < V_71 ) {
V_6 . V_72 [ V_11 ] [ V_69 ] = V_2 ;
V_4 = V_5 ;
}
return V_4 ;
}
void
F_9 ( void )
{
#if F_4 ( V_73 ) || F_4 ( V_44 )
unsigned int V_74 ;
for ( V_74 = 0 ; V_74 < V_18 ; V_74 ++ )
V_75 [ V_74 ] = 0 ;
#endif
}
enum V_1
F_10 (
struct V_76 * V_77 ,
unsigned int * V_2 )
{
#if ! F_4 ( V_44 )
enum V_1 V_4 = V_78 ;
( void ) V_77 ;
( void ) V_2 ;
#else
unsigned int V_26 ;
unsigned int V_27 ;
enum V_28 V_29 ;
bool V_79 ;
unsigned int V_43 ;
unsigned int V_32 = 0 ;
unsigned int V_33 = 0 ;
unsigned int V_34 = 0 ;
unsigned int V_35 = 0 ;
unsigned int V_37 = 0 ;
unsigned int V_38 = 0 ;
unsigned int V_39 = 0 ;
unsigned int V_80 = 0 ;
unsigned int V_81 = 0 ;
enum V_1 V_4 = V_5 ;
V_26 = V_77 -> V_82 . V_83 . V_26 ;
V_27 = V_77 -> V_82 . V_83 . V_27 ;
V_29 = V_77 -> V_82 . V_29 ;
V_79 = V_77 -> V_79 ;
V_43 = V_26 + ( 2 * V_45 ) ;
F_5 ( L_2 ,
V_43 , V_27 , V_29 ) ;
V_32 = F_11 ( V_29 ) ;
V_32 =
( V_29 == V_52 && V_79 ) ? V_32 : 16 ;
if ( V_32 == 0 )
return V_78 ;
V_34 = ( V_43 * V_32 + 7 ) >> 3 ;
if ( V_29 == V_50
|| V_29 == V_51 ) {
V_33 = ( V_43 * 2 * V_32 + 7 ) >> 3 ;
} else {
V_33 = V_34 ;
}
V_35 = ( V_34 + 3 ) >> 2 ;
V_37 = ( V_33 + 3 ) >> 2 ;
V_39 = ( V_35 + 7 ) >> 3 ;
V_38 = ( V_37 + 7 ) >> 3 ;
V_80 =
( V_39 > V_38 ) ? V_39 : V_38 ;
V_81 = V_80 * V_27 ;
* V_2 = V_81 ;
F_6 ( V_4 ) ;
#endif
return V_4 ;
}
enum V_1
F_12 ( struct V_7 * V_8 )
{
#if F_4 ( V_73 ) || F_4 ( V_44 )
enum V_1 V_4 = V_78 ;
unsigned int V_74 ;
#ifndef F_13
unsigned int V_11 ;
#else
unsigned int V_11 = 0 ;
#endif
F_14 ( L_3 , V_8 ) ;
assert ( V_8 != NULL ) ;
assert ( V_8 -> V_13 != NULL ) ;
if ( V_8 == NULL || V_8 -> V_13 == NULL ) {
F_15 ( L_4 ) ;
return V_67 ;
}
#ifndef F_13
if ( V_8 -> V_13 -> V_14 . V_15 != V_16 ) {
#else
if ( ! ( V_8 -> V_13 -> V_14 . V_15 == V_16 ||
V_8 -> V_13 -> V_14 . V_15 == V_19 ||
V_8 -> V_13 -> V_14 . V_15 == V_23 ) ) {
#endif
F_16 ( L_5 ) ;
return V_5 ;
}
#ifndef F_13
V_11 = ( unsigned int ) V_8 -> V_13 -> V_14 . V_17 . V_11 . V_11 ;
assert ( V_11 < V_18 ) ;
if ( V_11 >= V_18 ) {
F_15 ( L_6 , V_11 ) ;
#else
if ( ! F_2 ( V_8 , & V_11 ) ) {
F_15 ( L_7 , V_8 , V_11 ) ;
#endif
return V_4 ;
}
for ( V_74 = 0 ; V_74 < V_6 . V_84 [ V_11 ] ; V_74 ++ ) {
F_17 ( V_11 * V_85 + V_74 ,
V_6 . V_86 [ V_11 ] [ V_74 ] ) ;
F_18 ( V_11 * V_85 + V_74 ,
V_6 . V_87 [ V_11 ] [ V_74 ] ) ;
}
F_19 ( V_6 . V_84 [ V_11 ] ) ;
if ( ! F_20 () ) {
F_15 ( L_8 ) ;
return V_4 ;
}
F_21 (
V_88 ,
( V_89 ) V_11 ,
( V_89 ) V_6 . V_84 [ V_11 ] ,
0 ) ;
F_22 ( V_5 ) ;
#else
( void ) V_8 ;
#endif
return V_5 ;
}
