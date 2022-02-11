static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 1 ;
V_2 -> V_7 = 0 ;
F_3 ( & V_2 -> V_8 ) ;
}
static struct V_1 * F_4 ( T_1 V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_9 ) ;
if ( V_2 ) {
F_1 ( V_2 ) ;
F_6 ( V_10 ) ;
}
return V_2 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
F_8 (chunk, &msg->chunks, frag_list)
F_9 ( V_12 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_15 ;
struct V_11 * V_12 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 = NULL ;
int error = 0 , V_22 ;
V_22 = V_2 -> V_4 ? - 1 : 0 ;
F_12 (pos, temp, &msg->chunks) {
F_13 ( V_14 ) ;
V_12 = F_14 ( V_14 , struct V_11 , V_23 ) ;
if ( V_22 < 0 ) {
V_21 = V_12 -> V_21 ;
if ( V_2 -> V_5 )
error = V_2 -> V_5 ;
else
error = V_21 -> V_24 . error ;
V_17 = F_15 ( V_21 -> V_25 . V_26 ) ;
V_22 = F_16 ( V_27 ,
& V_17 -> V_28 ) ;
}
if ( V_22 > 0 ) {
int V_29 ;
if ( V_12 -> V_30 )
V_29 = V_31 ;
else
V_29 = V_32 ;
V_19 = F_17 ( V_21 , V_12 , V_29 ,
error , V_33 ) ;
if ( V_19 )
F_18 ( & V_21 -> V_34 , V_19 ) ;
}
F_19 ( V_12 ) ;
}
F_20 ( V_10 ) ;
F_21 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_3 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( F_24 ( & V_2 -> V_3 ) )
F_11 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_22 ( V_2 ) ;
V_12 -> V_2 = V_2 ;
}
struct V_1 * F_26 ( struct V_20 * V_21 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
int V_39 , V_40 , V_41 , V_42 , V_43 , V_44 ;
int V_45 , V_46 ;
int V_47 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 , * V_15 ;
T_2 V_48 = F_27 ( V_38 ) ;
T_3 V_49 ;
V_2 = F_4 ( V_50 ) ;
if ( ! V_2 )
return F_28 ( - V_51 ) ;
if ( V_21 -> V_52 . V_53 && V_36 -> V_54 &&
( F_29 ( V_36 -> V_55 ) ||
! F_30 ( V_36 -> V_55 ) ) )
V_2 -> V_7 = V_56 +
F_31 ( V_36 -> V_54 ) ;
V_47 = V_21 -> V_57 -
F_15 ( V_21 -> V_25 . V_26 ) -> V_58 -> V_59 -> V_60 -
sizeof( struct V_61 ) - sizeof( struct V_62 ) ;
V_47 = F_32 ( V_47 ) ;
V_39 = V_21 -> V_63 ;
if ( F_33 ( V_64 , V_21 ) ) {
struct V_65 * V_66 = F_34 ( V_21 ) ;
if ( V_66 )
V_47 -= F_35 ( sizeof( V_67 ) +
V_66 -> V_68 ) ;
}
if ( V_39 > V_47 )
V_39 = V_47 ;
V_40 = 0 ;
V_46 = V_39 ;
if ( F_36 ( & V_21 -> V_69 [ V_70 ] ) &&
V_21 -> V_24 . V_71 == 0 &&
F_37 ( & V_21 -> V_24 . V_72 ) &&
V_48 > V_39 )
V_47 -= F_35 ( sizeof( V_73 ) ) ;
if ( V_21 -> V_74 < V_75 )
V_47 -= V_76 ;
if ( V_46 > V_47 )
V_46 = V_47 ;
if ( V_48 >= V_46 ) {
V_48 -= V_46 ;
V_40 = 1 ;
V_2 -> V_6 = 0 ;
}
V_40 += V_48 / V_39 ;
V_43 = V_48 % V_39 ;
V_42 = 0 ;
if ( ( V_40 > 1 ) || ( V_40 && V_43 ) )
F_38 ( F_39 ( V_21 -> V_25 . V_26 ) , V_77 ) ;
for ( V_41 = 0 , V_45 = V_46 ; V_41 < V_40 ; V_41 ++ ) {
V_49 = V_78 ;
if ( 0 == V_41 )
V_49 |= V_79 ;
if ( ( V_41 == ( V_40 - 1 ) ) && ! V_43 ) {
V_49 |= V_80 ;
if ( ( V_36 -> V_55 & V_81 ) ||
( V_36 -> V_55 & V_82 ) )
V_49 |= V_83 ;
}
V_12 = F_40 ( V_21 , V_36 , V_45 , V_49 ,
0 , V_50 ) ;
if ( ! V_12 ) {
V_44 = - V_51 ;
goto V_84;
}
V_44 = F_41 ( V_12 , V_45 , V_38 ) ;
if ( V_44 < 0 )
goto V_85;
F_42 ( V_12 -> V_86 , ( T_3 * ) V_12 -> V_87
- ( T_3 * ) V_12 -> V_86 -> V_88 ) ;
F_25 ( V_2 , V_12 ) ;
F_43 ( & V_12 -> V_23 , & V_2 -> V_8 ) ;
if ( 0 == V_41 )
V_45 = V_39 ;
}
if ( V_43 ) {
if ( ! V_40 )
V_49 = V_89 ;
else
V_49 = V_80 ;
if ( ( V_36 -> V_55 & V_81 ) ||
( V_36 -> V_55 & V_82 ) )
V_49 |= V_83 ;
V_12 = F_40 ( V_21 , V_36 , V_43 , V_49 ,
0 , V_50 ) ;
if ( ! V_12 ) {
V_44 = - V_51 ;
goto V_84;
}
V_44 = F_41 ( V_12 , V_43 , V_38 ) ;
F_42 ( V_12 -> V_86 , ( T_3 * ) V_12 -> V_87
- ( T_3 * ) V_12 -> V_86 -> V_88 ) ;
if ( V_44 < 0 )
goto V_85;
F_25 ( V_2 , V_12 ) ;
F_43 ( & V_12 -> V_23 , & V_2 -> V_8 ) ;
}
return V_2 ;
V_85:
F_9 ( V_12 ) ;
V_84:
F_12 (pos, temp, &msg->chunks) {
F_13 ( V_14 ) ;
V_12 = F_14 ( V_14 , struct V_11 , V_23 ) ;
F_9 ( V_12 ) ;
}
F_10 ( V_2 ) ;
return F_28 ( V_44 ) ;
}
int F_44 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_21 -> V_52 . V_53 )
return 0 ;
if ( F_29 ( V_12 -> V_36 . V_55 ) &&
F_45 ( V_56 , V_12 -> V_2 -> V_7 ) ) {
if ( V_12 -> V_90 )
V_12 -> V_21 -> V_91 [ F_46 ( V_92 ) ] ++ ;
else
V_12 -> V_21 -> V_93 [ F_46 ( V_92 ) ] ++ ;
return 1 ;
} else if ( F_47 ( V_12 -> V_36 . V_55 ) &&
V_12 -> V_90 > V_12 -> V_36 . V_54 ) {
V_12 -> V_21 -> V_91 [ F_46 ( V_94 ) ] ++ ;
return 1 ;
} else if ( ! F_30 ( V_12 -> V_36 . V_55 ) &&
V_12 -> V_2 -> V_7 &&
F_45 ( V_56 , V_12 -> V_2 -> V_7 ) ) {
return 1 ;
}
return 0 ;
}
void F_48 ( struct V_11 * V_12 , int error )
{
V_12 -> V_2 -> V_4 = 1 ;
V_12 -> V_2 -> V_5 = error ;
}
