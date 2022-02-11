static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 , T_3 V_4 , T_2 V_5 , int V_6 )
{
struct V_1 * V_1 = V_2 -> V_7 ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ->
V_9 ;
T_4 V_10 = ( F_2 ( V_1 -> V_7 ->
V_11 -> V_12 ) ) - 1 ;
int V_13 ;
int V_14 ;
T_2 V_15 = V_5 | V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
T_2 V_20 ;
if ( F_3 ( V_8 ) && F_4 ( V_8 ) ) {
return 0 ;
}
if ( ! ( F_5 ( V_3 , V_4 ) ) ) {
V_13 = F_6 ( ( V_21 - 1 )
+ V_4
- 1 ) + 1 ;
} else {
V_13 = F_6 ( V_4
- 1 ) + 1 ;
}
V_14 = F_7 ( V_8 , V_13 ) ;
if ( V_14 < 0 )
return 0 ;
if ( F_4 ( V_8 ) )
V_15 &= ~ ( V_22 ) ;
if ( F_8 ( V_6 == V_23 ) )
V_19 = F_3 ( V_8 ) ? F_9 ( V_3 ) :
F_10 ( V_3 ) ;
else
V_19 = V_3 ;
V_20 = F_11 ( V_19 ) ;
V_17 = V_15 | ( V_19 - V_20 ) ;
if ( F_3 ( V_8 ) ) {
V_17 |= ( V_8 -> V_24 << V_25 ) ;
}
if ( V_6 & V_26 ) {
V_17 |= V_27 ;
if ( F_12 ( V_8 ) )
V_17 |= V_28 ;
}
F_13 ( V_8 , V_14 , V_13 , V_17 ) ;
V_18 = V_29 + V_20 + V_21 * V_14 ;
if ( V_8 -> V_30 [ V_10 ] & V_31 )
F_14 ( V_18 ) ;
return V_18 ;
}
static T_1
F_15 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_32 , int V_6 )
{
struct V_8 * V_8 = (struct V_8 * )
( ( V_2 -> V_7 ) -> V_9 ) ;
T_2 V_18 ;
if ( F_8 ( V_6 ) == V_23 )
V_18 = F_3 ( V_8 ) ?
F_9 ( V_3 ) :
F_10 ( V_3 ) ;
else
V_18 = V_3 ;
V_18 |= V_32 ;
if ( F_4 ( V_8 ) )
V_18 &= ~ V_33 ;
if ( F_3 ( V_8 ) ) {
V_18 |=
( ( T_2 ) V_8 ->
V_24 << V_34 ) ;
} else
V_18 |= ( V_6 & V_26 ) ?
V_35 :
V_36 ;
if ( ! F_4 ( V_8 ) && F_16 ( V_2 -> V_11 -> V_12 ) )
V_18 |= V_37 ;
return V_18 ;
}
static T_1
F_17 ( struct V_1 * V_2 ,
T_2 V_3 , T_3 V_4 , T_2 V_5 , int V_6 )
{
struct V_1 * V_1 = V_2 -> V_7 ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ->
V_9 ;
T_2 V_19 ;
T_2 V_38 ;
T_2 V_20 ;
T_2 V_39 ;
if ( F_4 ( V_8 ) ) {
return 0 ;
}
if ( V_6 & V_26 )
return 0 ;
if ( F_8 ( V_6 ) == V_23 )
V_19 = F_3 ( V_8 ) ? F_9 ( V_3 ) :
F_10 ( V_3 ) ;
else
V_19 = V_3 ;
V_38 = V_8 -> V_40 ;
V_20 = V_19 - V_38 ;
V_39 = V_4 + V_20 ;
if ( ( V_4 > ( 1ULL << 31 ) ) ||
( V_19 < V_38 ) ||
( V_39 > ( 1ULL << 31 ) ) ) {
return 0 ;
}
return V_41 | V_20 ;
}
void
F_18 ( struct V_42 * V_43 , T_1 V_44 , int V_45 )
{
struct V_1 * V_1 = F_19 ( V_43 ) ;
struct V_8 * V_8 =
(struct V_8 * ) V_1 -> V_9 ;
if ( F_20 ( V_44 ) ) {
int V_14 ;
V_14 =
F_6 ( ( F_21 ( V_44 ) - V_29 ) ) ;
F_22 ( V_8 , V_14 ) ;
}
}
void F_23 ( T_2 V_46 )
{
T_5 V_47 ;
int V_48 ;
int V_49 ;
int V_50 , V_51 ;
unsigned long V_5 ;
T_2 V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
if ( ! V_61 )
return;
V_47 = F_24 ( V_46 ) ;
if ( - 1 == F_25 ( V_47 ) )
return;
V_54 = ( F_26 ( F_25 ( V_47 ) ) ) -> V_62 ;
F_27 ( ! V_54 ) ;
V_60 = & V_54 -> V_63 ;
if ( V_60 -> V_64 == NULL )
return;
V_48 = ( V_47 & 1 ) ;
if ( V_48 ) {
int V_65 ;
if ( F_28 ( V_46 ) )
V_65 = 0 ;
else if ( F_29 ( V_46 ) )
V_65 = F_29 ( V_46 ) ;
else
V_65 = - 1 ;
if ( V_65 >= 0 ) {
V_52 = V_60 -> V_66 [ V_65 ] ;
if ( ! F_30 ( V_52 ) )
return;
V_49 = F_31 ( V_52 ) ;
} else
V_49 = F_32 ( V_46 ) ;
} else {
if ( F_33 ( V_46 ) ) {
V_52 = V_60 -> V_66 [ F_33 ( V_46 ) ] ;
V_49 = F_34 ( V_52 ) ;
} else
V_49 = F_35 ( V_46 ) ;
}
if ( V_60 -> V_64 [ V_49 ] == NULL )
return;
V_56 = & V_60 -> V_64 [ V_49 ] [ 0 ] ;
for ( V_50 = 0 ; V_50 < V_67 ; V_50 ++ , V_56 ++ ) {
V_58 = V_56 -> V_58 ;
for ( V_51 = 0 ; V_51 < V_68 ; V_51 ++ ) {
if ( V_58 -> V_69 [ V_51 ] . V_70 == 0 )
break;
if ( V_46 >= V_58 -> V_69 [ V_51 ] . V_70
&& V_46 <= V_58 -> V_69 [ V_51 ] . V_71 )
break;
}
if ( V_51 < V_68 && V_58 -> V_69 [ V_51 ] . V_70 != 0 )
break;
}
if ( V_50 == V_67 )
return;
if ( V_48 ) {
T_6 V_72 = F_36 ( F_37 ( V_47 , V_73 ) ) ;
T_6 V_74 = F_38 ( V_72 ) ;
if ( ( 1 << F_39 ( V_74 ) ) & V_75 ) {
return;
} else {
F_40 ( V_58 -> V_76 ,
( V_58 -> V_77 - 1 ) ) ;
}
} else {
F_41 ( & V_56 -> V_78 , V_5 ) ;
* V_58 -> V_79 = 0 ;
* ( volatile T_6 * ) ( V_58 -> V_80 ) = 1 ;
while ( * ( V_58 -> V_79 ) != 0x10f )
F_42 () ;
F_43 ( & V_56 -> V_78 , V_5 ) ;
}
return;
}
T_1
F_44 ( struct V_42 * V_43 , unsigned long V_81 , T_3 V_82 , int V_6 )
{
T_1 V_44 ;
struct V_1 * V_1 = F_19 ( V_43 ) ;
if ( V_43 -> V_83 < 0x7fffffff ) {
return 0 ;
}
if ( V_43 -> V_83 == ~ 0UL ) {
V_44 = F_15 ( V_1 , V_81 ,
V_33 , V_6 ) ;
} else {
V_44 = F_17 ( V_1 , V_81 ,
V_82 , 0 , V_6 ) ;
if ( ! V_44 ) {
V_44 = F_1 ( V_1 , V_81 ,
V_82 , V_22 ,
V_6 ) ;
}
}
return V_44 ;
}
T_1
F_45 ( struct V_42 * V_43 , unsigned long V_81 ,
T_3 V_82 , int V_6 )
{
T_1 V_44 ;
struct V_1 * V_1 = F_19 ( V_43 ) ;
if ( V_43 -> V_84 . V_85 == ~ 0UL ) {
V_44 = F_15 ( V_1 , V_81 ,
V_86 , V_6 ) ;
} else {
V_44 = ( T_1 ) F_1 ( V_1 ,
V_81 , V_82 ,
V_87 , V_6 ) ;
}
return V_44 ;
}
