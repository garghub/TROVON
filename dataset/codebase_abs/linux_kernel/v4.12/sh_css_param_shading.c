static void
F_1 ( unsigned int V_1 ,
unsigned int V_2 ,
unsigned int V_3 ,
int V_4 ,
int V_5 ,
const struct V_6 * V_7 ,
struct V_6 * V_8 ,
enum V_9 V_10 )
{
unsigned int V_11 , V_12 ,
V_13 ,
V_14 ,
V_15 ,
V_16 ,
V_17 ,
V_18 ,
V_19 ,
V_20 ,
V_21 ;
int V_22 ,
V_23 ;
unsigned short * V_24 ,
* V_25 ;
assert ( V_7 != NULL ) ;
assert ( V_8 != NULL ) ;
V_13 = V_7 -> V_13 ;
V_14 = V_7 -> V_14 ;
V_15 = V_7 -> V_26 ;
V_16 = V_7 -> V_27 ;
V_24 = V_7 -> V_28 [ V_10 ] ;
V_25 = V_8 -> V_28 [ V_10 ] ;
V_21 = V_1 + V_3 + V_4 ;
V_18 = F_2 ( V_21 , V_8 -> V_26 - 1 ) ;
V_19 = F_2 ( V_13 , V_15 - 1 ) ;
V_22 = ( ( int ) V_13 - ( int ) V_1 ) / 2 - V_3 ;
V_20 = ( ( int ) V_14 - ( int ) V_2 ) / 2 - V_5 ;
V_23 = ( int ) ( ( V_15 - 1 ) * V_19 ) ;
V_17 = ( V_16 - 1 ) * V_19 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_27 ; V_11 ++ ) {
int V_29 , V_30 , V_31 ;
unsigned int V_32 , V_33 , V_34 , V_35 , V_36 ;
V_29 = V_20 + V_11 * V_18 ;
V_30 = V_29 / ( int ) V_19 ;
if ( V_19 < V_18 )
V_31 = ( V_29 + V_18 ) / V_19 ;
else
V_31 = V_30 + 1 ;
V_30 = F_3 ( V_30 , 0 , ( int ) V_16 - 1 ) ;
V_31 = F_3 ( V_31 , 0 , ( int ) V_16 - 1 ) ;
V_29 = F_4 ( F_3 ( V_29 , 0 , ( int ) V_14 - 1 ) ,
( int ) V_17 ) ;
V_32 = F_4 ( V_30 * V_19 , V_14 - 1 ) ;
V_33 = F_4 ( V_31 * V_19 , V_14 - 1 ) ;
V_34 = V_29 - V_32 ;
V_35 = V_33 - V_29 ;
V_36 = V_33 - V_32 ;
if ( V_36 == 0 ) {
V_34 = 1 ;
V_36 = 1 ;
}
for ( V_12 = 0 ; V_12 < V_8 -> V_26 ; V_12 ++ , V_25 ++ ) {
int V_37 , V_38 , V_39 ;
unsigned int V_40 , V_41 , V_42 , V_43 , V_44 ;
unsigned short V_45 , V_46 , V_47 , V_48 ;
V_37 = V_22 + V_12 * V_18 ;
V_38 = V_37 / ( int ) V_19 ;
if ( V_19 < V_18 ) {
V_39 = ( V_37 + V_18 ) /
( int ) V_19 ;
} else {
V_39 = V_38 + 1 ;
}
V_38 = F_3 ( V_38 , 0 , ( int ) V_15 - 1 ) ;
V_39 = F_3 ( V_39 , 0 , ( int ) V_15 - 1 ) ;
V_37 = F_4 ( F_3 ( V_37 , 0 , ( int ) V_13 - 1 ) ,
( int ) V_23 ) ;
V_40 = F_4 ( V_38 * V_19 , V_13 - 1 ) ;
V_41 = F_4 ( V_39 * V_19 , V_13 - 1 ) ;
V_42 = V_37 - V_40 ;
V_43 = V_41 - V_37 ;
V_44 = V_41 - V_40 ;
if ( V_44 == 0 ) {
V_42 = 1 ;
V_44 = 1 ;
}
V_45 = V_24 [ ( V_15 * V_30 ) + V_38 ] ;
V_46 = V_24 [ ( V_15 * V_30 ) + V_39 ] ;
V_47 = V_24 [ ( V_15 * V_31 ) + V_38 ] ;
V_48 = V_24 [ ( V_15 * V_31 ) + V_39 ] ;
* V_25 = ( unsigned short ) ( ( V_42 * V_34 * V_48 + V_42 * V_35 * V_46 + V_43 * V_34 * V_47 + V_43 * V_35 * V_45 ) /
( V_44 * V_36 ) ) ;
}
}
}
void
F_5 ( const struct V_6 * V_7 ,
unsigned int V_49 ,
struct V_6 * * V_50 ,
const struct V_51 * V_52 ,
unsigned int V_53 )
{
unsigned int V_54 ,
V_55 ,
V_15 ,
V_16 ,
V_3 ,
V_5 ,
V_21 ,
V_56 ,
V_11 ;
unsigned int V_57 , V_58 ;
int V_4 ;
struct V_6 * V_59 ;
assert ( V_50 != NULL ) ;
assert ( V_52 != NULL ) ;
if ( ! V_7 ) {
#ifndef F_6
F_7 ( V_50 , V_52 ) ;
#else
F_7 ( V_50 ,
V_52 -> V_60 , V_52 -> V_61 ) ;
#endif
return;
}
V_21 = V_52 -> V_62 . V_21 ;
#if F_8 ( V_63 )
V_21 = F_9 ( V_52 -> V_64 . V_26 + 2 * V_65 ,
2 * V_65 ) ;
#endif
V_55 = V_52 -> V_62 . V_66 . V_27 ;
V_54 = V_52 -> V_62 . V_66 . V_26 ;
V_3 = V_52 -> V_3 ;
V_56 = ( V_52 -> V_67 -> V_68 . V_69 . V_56 == 0 ) ?
V_52 -> V_70 . V_26 : 2 * V_65 ;
F_10
( V_53 , & V_57 , & V_58 ) ;
V_3 = ( V_3 + V_52 -> V_67 -> V_68 . V_69 . V_56 ) * V_57 / V_58 - V_52 -> V_67 -> V_68 . V_69 . V_56 ;
V_4 = ( V_52 -> V_71 . V_66 . V_26 - V_52 -> V_64 . V_26 * V_58 / V_57 - V_56 ) * V_57 / V_58 ;
V_5 = V_52 -> V_67 -> V_68 . V_69 . V_72 * V_57 / V_58 - V_52 -> V_67 -> V_68 . V_69 . V_72 ;
#if ! F_8 ( V_73 )
V_54 <<= V_49 ;
V_55 <<= V_49 ;
V_3 <<= V_49 ;
V_4 <<= V_49 ;
V_5 <<= V_49 ;
#else
V_54 *= V_49 ;
V_55 *= V_49 ;
V_3 *= V_49 ;
V_4 *= V_49 ;
V_5 *= V_49 ;
#endif
V_54 = F_4 ( V_54 , V_7 -> V_13 ) ;
V_55 = F_4 ( V_55 , V_7 -> V_14 ) ;
#ifndef F_6
V_15 = V_52 -> V_74 ;
V_16 = V_52 -> V_75 ;
#else
V_15 = V_52 -> V_60 ;
V_16 = V_52 -> V_61 ;
#endif
V_59 = F_11 ( V_15 , V_16 ) ;
if ( V_59 == NULL ) {
* V_50 = NULL ;
return;
}
V_59 -> V_13 = V_7 -> V_13 ;
V_59 -> V_14 = V_7 -> V_14 ;
V_59 -> V_76 = V_7 -> V_76 ;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ ) {
F_1 ( V_54 , V_55 ,
V_3 , V_4 , V_5 ,
V_7 ,
V_59 , V_11 ) ;
}
* V_50 = V_59 ;
}
struct V_6 *
F_11 (
unsigned int V_26 ,
unsigned int V_27 )
{
unsigned int V_11 ;
struct V_6 * V_78 ;
F_12 ( L_1 ) ;
V_78 = F_13 ( sizeof( * V_78 ) , V_79 ) ;
if ( V_78 == NULL ) {
F_14 ( L_2 ) ;
return V_78 ;
}
V_78 -> V_26 = V_26 ;
V_78 -> V_27 = V_27 ;
V_78 -> V_13 = 0 ;
V_78 -> V_14 = 0 ;
V_78 -> V_76 = 0 ;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ ) {
V_78 -> V_28 [ V_11 ] =
F_15 ( V_26 * V_27 * sizeof( * V_78 -> V_28 [ 0 ] ) ) ;
if ( V_78 -> V_28 [ V_11 ] == NULL ) {
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
F_16 ( V_78 -> V_28 [ V_12 ] ) ;
V_78 -> V_28 [ V_12 ] = NULL ;
}
F_17 ( V_78 ) ;
return NULL ;
}
}
F_18 ( L_1 ) ;
return V_78 ;
}
void
F_19 ( struct V_6 * V_80 )
{
unsigned int V_11 ;
if ( V_80 == NULL )
return;
F_12 ( L_1 ) ;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ ) {
if ( V_80 -> V_28 [ V_11 ] ) {
F_16 ( V_80 -> V_28 [ V_11 ] ) ;
V_80 -> V_28 [ V_11 ] = NULL ;
}
}
F_17 ( V_80 ) ;
F_18 ( L_1 ) ;
}
