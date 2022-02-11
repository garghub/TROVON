void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
V_8 = & V_6 -> V_9 . V_8 ;
if ( F_3 ( V_8 -> V_10 ) >
V_2 -> V_11 ) {
F_4 ( V_2 ,
L_1 ,
F_3 ( V_8 -> V_10 ) ,
F_3 ( V_8 -> V_12 ) ,
F_3 ( V_8 -> V_13 ) ,
F_3 ( V_8 -> V_14 ) ) ;
if ( ! F_5 ( V_15 , & V_2 -> V_16 ) )
F_6 ( V_2 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int V_19 = 0 ;
int V_20 = 0 ;
int V_21 , V_22 , V_23 ;
int V_24 ;
V_18 = & ( V_2 -> V_25 . V_26 . V_27 . V_28 ) ;
V_21 =
F_3 ( V_18 -> V_29 ) & V_30 ;
V_22 =
F_3 ( V_18 -> V_31 ) & V_30 ;
V_23 =
F_3 ( V_18 -> V_32 ) & V_30 ;
if ( V_21 ) {
V_20 += V_21 ;
V_19 ++ ;
}
if ( V_22 ) {
V_20 += V_22 ;
V_19 ++ ;
}
if ( V_23 ) {
V_20 += V_23 ;
V_19 ++ ;
}
if ( V_19 )
V_24 = ( V_20 / V_19 ) - 107 ;
else
V_24 = V_33 ;
F_4 ( V_2 , L_2 ,
V_21 , V_22 , V_23 ,
V_24 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 * V_34 )
{
int V_35 , V_36 ;
T_1 * V_37 ;
T_2 * V_38 ;
T_2 * V_39 , * V_40 ;
struct V_41 * V_28 , * V_42 ;
struct V_43 * V_44 , * V_45 ;
V_37 = ( T_1 * ) & V_2 -> V_25 . V_26 ;
V_38 = ( T_2 * ) & V_2 -> V_25 . V_46 ;
V_36 = sizeof( struct V_47 ) ;
V_28 = & V_2 -> V_25 . V_26 . V_28 . V_48 ;
V_42 = & V_2 -> V_25 . V_46 . V_28 . V_48 ;
V_44 = & V_2 -> V_25 . V_26 . V_44 ;
V_45 = & V_2 -> V_25 . V_46 . V_44 ;
V_39 = ( T_2 * ) & V_2 -> V_25 . V_49 ;
V_40 = ( T_2 * ) & V_2 -> V_25 . V_40 ;
for ( V_35 = sizeof( T_1 ) ; V_35 < V_36 ;
V_35 += sizeof( T_1 ) , V_34 ++ , V_37 ++ , V_39 ++ ,
V_40 ++ , V_38 ++ ) {
if ( F_3 ( * V_34 ) > F_3 ( * V_37 ) ) {
* V_39 = ( F_3 ( * V_34 ) -
F_3 ( * V_37 ) ) ;
* V_38 += * V_39 ;
if ( * V_39 > * V_40 )
* V_40 = * V_39 ;
}
}
V_42 -> V_50 = V_28 -> V_50 ;
V_42 -> V_51 = V_28 -> V_51 ;
}
bool F_9 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
bool V_52 = true ;
int V_53 ;
unsigned int V_54 ;
unsigned long V_55 ;
if ( V_2 -> V_56 -> V_57 -> V_58 ==
V_59 ) {
F_10 ( V_2 , L_3 ) ;
return V_52 ;
}
V_55 = V_60 ;
V_54 = F_11 ( ( long ) V_55 -
( long ) V_2 -> V_61 ) ;
V_2 -> V_61 = V_55 ;
if ( V_54 ) {
struct V_62 * V_63 ;
struct V_64 * V_65 ;
V_63 = & V_6 -> V_9 . V_34 . V_27 . V_63 ;
V_65 = & V_6 -> V_9 . V_34 . V_27 . V_65 ;
V_53 =
( F_3 ( V_63 -> V_66 ) -
F_3 ( V_2 -> V_25 . V_26 .
V_27 . V_63 . V_66 ) ) +
( F_3 ( V_65 -> V_66 ) -
F_3 ( V_2 -> V_25 . V_26 .
V_27 . V_65 . V_66 ) ) ;
if ( ( V_53 > 0 ) &&
( ( V_53 * 100 ) / V_54 ) >
V_2 -> V_56 -> V_57 -> V_58 ) {
F_10 ( V_2 , L_4
L_5 ,
V_2 -> V_56 -> V_57 -> V_58 ,
F_3 ( V_63 -> V_66 ) ,
F_3 ( V_63 -> V_66 ) ,
F_3 ( V_65 -> V_66 ) ,
F_3 ( V_65 -> V_66 ) ,
V_53 , V_54 ) ;
V_52 = false ;
}
}
return V_52 ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_67 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_13 ( V_2 ,
L_6 ,
( int ) sizeof( struct V_47 ) ,
F_3 ( V_6 -> V_68 ) &
V_69 ) ;
V_67 = ( ( V_2 -> V_25 . V_26 . V_28 . V_48 . V_50 !=
V_6 -> V_9 . V_34 . V_28 . V_48 . V_50 ) ||
( ( V_2 -> V_25 . V_26 . V_70 &
V_71 ) !=
( V_6 -> V_9 . V_34 . V_70 &
V_71 ) ) ) ;
#ifdef F_14
F_8 ( V_2 , ( T_1 * ) & V_6 -> V_9 . V_34 ) ;
#endif
F_15 ( V_2 , V_6 ) ;
memcpy ( & V_2 -> V_25 . V_26 , & V_6 -> V_9 . V_34 ,
sizeof( V_2 -> V_25 . V_26 ) ) ;
F_16 ( V_72 , & V_2 -> V_16 ) ;
F_17 ( & V_2 -> V_73 , V_60 +
F_18 ( V_74 * 1000 ) ) ;
if ( F_19 ( ! F_5 ( V_15 , & V_2 -> V_16 ) ) &&
( V_6 -> V_75 . V_76 == V_77 ) ) {
F_7 ( V_2 ) ;
F_20 ( V_2 -> V_78 , & V_2 -> V_79 ) ;
}
if ( V_2 -> V_56 -> V_80 -> V_81 -> V_82 . V_50 && V_67 )
V_2 -> V_56 -> V_80 -> V_81 -> V_82 . V_50 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( F_3 ( V_6 -> V_9 . V_34 . V_70 ) & V_83 ) {
#ifdef F_14
memset ( & V_2 -> V_25 . V_46 , 0 ,
sizeof( struct V_47 ) ) ;
memset ( & V_2 -> V_25 . V_49 , 0 ,
sizeof( struct V_47 ) ) ;
memset ( & V_2 -> V_25 . V_40 , 0 ,
sizeof( struct V_47 ) ) ;
#endif
F_13 ( V_2 , L_7 ) ;
}
F_12 ( V_2 , V_4 ) ;
}
