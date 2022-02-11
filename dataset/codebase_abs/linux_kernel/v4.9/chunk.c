static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = 0 ;
F_3 ( & V_2 -> V_9 ) ;
}
static struct V_1 * F_4 ( T_1 V_10 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_10 ) ;
if ( V_2 ) {
F_1 ( V_2 ) ;
F_6 ( V_11 ) ;
}
return V_2 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
F_8 (chunk, &msg->chunks, frag_list)
F_9 ( V_13 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_16 ;
struct V_12 * V_13 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
int error = 0 , V_23 ;
V_23 = V_2 -> V_4 ? - 1 : 0 ;
F_12 (pos, temp, &msg->chunks) {
F_13 ( V_15 ) ;
V_13 = F_14 ( V_15 , struct V_12 , V_24 ) ;
if ( V_23 < 0 ) {
V_22 = V_13 -> V_22 ;
if ( V_2 -> V_5 )
error = V_2 -> V_5 ;
else
error = V_22 -> V_25 . error ;
V_18 = F_15 ( V_22 -> V_26 . V_27 ) ;
V_23 = F_16 ( V_28 ,
& V_18 -> V_29 ) ;
}
if ( V_23 > 0 ) {
int V_30 ;
if ( V_13 -> V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
V_20 = F_17 ( V_22 , V_13 , V_30 ,
error , V_34 ) ;
if ( V_20 )
F_18 ( & V_22 -> V_35 , V_20 ) ;
}
F_19 ( V_13 ) ;
}
F_20 ( V_11 ) ;
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
static void F_25 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_22 ( V_2 ) ;
V_13 -> V_2 = V_2 ;
}
struct V_1 * F_26 ( struct V_21 * V_22 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
int V_40 , V_41 , V_42 , V_43 , V_44 , V_45 ;
int V_46 , V_47 ;
int V_48 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_14 * V_15 , * V_16 ;
T_2 V_49 = F_27 ( V_39 ) ;
T_3 V_50 ;
V_2 = F_4 ( V_51 ) ;
if ( ! V_2 )
return F_28 ( - V_52 ) ;
if ( V_37 -> V_53 ) {
V_2 -> V_8 = V_54 +
F_29 ( V_37 -> V_53 ) ;
V_2 -> V_6 = 1 ;
F_30 ( L_1 , V_55 ,
V_2 , V_2 -> V_8 , V_54 ) ;
}
if ( V_22 -> V_56 . V_57 &&
F_31 ( V_37 -> V_58 ) )
V_2 -> V_8 =
V_54 + F_29 ( V_37 -> V_53 ) ;
V_48 = V_22 -> V_59 -
F_15 ( V_22 -> V_26 . V_27 ) -> V_60 -> V_61 -> V_62 -
sizeof( struct V_63 ) - sizeof( struct V_64 ) ;
V_48 = F_32 ( V_48 ) ;
V_40 = V_22 -> V_65 ;
if ( F_33 ( V_66 , V_22 ) ) {
struct V_67 * V_68 = F_34 ( V_22 ) ;
if ( V_68 )
V_48 -= F_35 ( sizeof( V_69 ) +
V_68 -> V_70 ) ;
}
if ( V_40 > V_48 )
V_40 = V_48 ;
V_41 = 0 ;
V_47 = V_40 ;
if ( F_36 ( & V_22 -> V_71 [ V_72 ] ) &&
V_22 -> V_25 . V_73 == 0 &&
F_37 ( & V_22 -> V_25 . V_74 ) &&
V_49 > V_40 )
V_48 -= F_35 ( sizeof( V_75 ) ) ;
if ( V_22 -> V_76 < V_77 )
V_48 -= V_78 ;
if ( V_47 > V_48 )
V_47 = V_48 ;
if ( V_49 >= V_47 ) {
V_49 -= V_47 ;
V_41 = 1 ;
V_2 -> V_7 = 0 ;
}
V_41 += V_49 / V_40 ;
V_44 = V_49 % V_40 ;
V_43 = 0 ;
if ( ( V_41 > 1 ) || ( V_41 && V_44 ) )
F_38 ( F_39 ( V_22 -> V_26 . V_27 ) , V_79 ) ;
for ( V_42 = 0 , V_46 = V_47 ; V_42 < V_41 ; V_42 ++ ) {
V_50 = V_80 ;
if ( 0 == V_42 )
V_50 |= V_81 ;
if ( ( V_42 == ( V_41 - 1 ) ) && ! V_44 ) {
V_50 |= V_82 ;
if ( ( V_37 -> V_58 & V_83 ) ||
( V_37 -> V_58 & V_84 ) )
V_50 |= V_85 ;
}
V_13 = F_40 ( V_22 , V_37 , V_46 , V_50 ,
0 , V_51 ) ;
if ( ! V_13 ) {
V_45 = - V_52 ;
goto V_86;
}
V_45 = F_41 ( V_13 , V_46 , V_39 ) ;
if ( V_45 < 0 )
goto V_87;
F_42 ( V_13 -> V_88 , ( T_3 * ) V_13 -> V_89
- ( T_3 * ) V_13 -> V_88 -> V_90 ) ;
F_25 ( V_2 , V_13 ) ;
F_43 ( & V_13 -> V_24 , & V_2 -> V_9 ) ;
if ( 0 == V_42 )
V_46 = V_40 ;
}
if ( V_44 ) {
if ( ! V_41 )
V_50 = V_91 ;
else
V_50 = V_82 ;
if ( ( V_37 -> V_58 & V_83 ) ||
( V_37 -> V_58 & V_84 ) )
V_50 |= V_85 ;
V_13 = F_40 ( V_22 , V_37 , V_44 , V_50 ,
0 , V_51 ) ;
if ( ! V_13 ) {
V_45 = - V_52 ;
goto V_86;
}
V_45 = F_41 ( V_13 , V_44 , V_39 ) ;
F_42 ( V_13 -> V_88 , ( T_3 * ) V_13 -> V_89
- ( T_3 * ) V_13 -> V_88 -> V_90 ) ;
if ( V_45 < 0 )
goto V_87;
F_25 ( V_2 , V_13 ) ;
F_43 ( & V_13 -> V_24 , & V_2 -> V_9 ) ;
}
return V_2 ;
V_87:
F_9 ( V_13 ) ;
V_86:
F_12 (pos, temp, &msg->chunks) {
F_13 ( V_15 ) ;
V_13 = F_14 ( V_15 , struct V_12 , V_24 ) ;
F_9 ( V_13 ) ;
}
F_10 ( V_2 ) ;
return F_28 ( V_45 ) ;
}
int F_44 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_22 -> V_56 . V_57 ||
! F_45 ( V_13 -> V_37 . V_58 ) ) {
struct V_1 * V_2 = V_13 -> V_2 ;
if ( ! V_2 -> V_6 )
return 0 ;
if ( F_46 ( V_54 , V_2 -> V_8 ) )
return 1 ;
return 0 ;
}
if ( F_31 ( V_13 -> V_37 . V_58 ) &&
F_46 ( V_54 , V_13 -> V_2 -> V_8 ) ) {
if ( V_13 -> V_92 )
V_13 -> V_22 -> V_93 [ F_47 ( V_94 ) ] ++ ;
else
V_13 -> V_22 -> V_95 [ F_47 ( V_94 ) ] ++ ;
return 1 ;
} else if ( F_48 ( V_13 -> V_37 . V_58 ) &&
V_13 -> V_92 > V_13 -> V_37 . V_53 ) {
V_13 -> V_22 -> V_93 [ F_47 ( V_96 ) ] ++ ;
return 1 ;
}
return 0 ;
}
void F_49 ( struct V_12 * V_13 , int error )
{
V_13 -> V_2 -> V_4 = 1 ;
V_13 -> V_2 -> V_5 = error ;
}
