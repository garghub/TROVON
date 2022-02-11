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
T_1 struct V_1 * F_4 ( T_2 V_10 )
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
struct V_38 * V_39 , int V_40 )
{
int V_41 , V_42 , V_43 , V_44 , V_45 , V_46 ;
int V_47 , V_48 ;
int V_49 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_14 * V_15 , * V_16 ;
T_3 V_50 ;
V_2 = F_4 ( V_51 ) ;
if ( ! V_2 )
return NULL ;
if ( V_37 -> V_52 ) {
V_2 -> V_8 = V_53 +
F_27 ( V_37 -> V_52 ) ;
V_2 -> V_6 = 1 ;
F_28 ( L_1 ,
V_54 , V_2 , V_2 -> V_8 , V_53 ) ;
}
V_49 = V_22 -> V_55 -
F_15 ( V_22 -> V_26 . V_27 ) -> V_56 -> V_57 -> V_58 -
sizeof( struct V_59 ) - sizeof( struct V_60 ) ;
V_41 = V_22 -> V_61 ;
if ( F_29 ( V_62 , V_22 ) ) {
struct V_63 * V_64 = F_30 ( V_22 ) ;
if ( V_64 )
V_49 -= F_31 ( sizeof( V_65 ) +
V_64 -> V_66 ) ;
}
if ( V_41 > V_49 )
V_41 = V_49 ;
V_42 = 0 ;
V_48 = V_41 ;
if ( F_32 ( & V_22 -> V_67 [ V_68 ] ) &&
V_22 -> V_25 . V_69 == 0 &&
F_33 ( & V_22 -> V_25 . V_70 ) &&
V_40 > V_41 )
V_49 -= F_31 ( sizeof( V_71 ) ) ;
if ( V_22 -> V_72 < V_73 )
V_49 -= V_74 ;
if ( V_48 > V_49 )
V_48 = V_49 ;
if ( V_40 >= V_48 ) {
V_40 -= V_48 ;
V_42 = 1 ;
V_2 -> V_7 = 0 ;
}
V_42 += V_40 / V_41 ;
V_45 = V_40 % V_41 ;
V_44 = 0 ;
if ( ( V_42 > 1 ) || ( V_42 && V_45 ) )
F_34 ( V_75 ) ;
for ( V_43 = 0 , V_47 = V_48 ; V_43 < V_42 ; V_43 ++ ) {
V_50 = V_76 ;
if ( 0 == V_43 )
V_50 |= V_77 ;
if ( ( V_43 == ( V_42 - 1 ) ) && ! V_45 ) {
V_50 |= V_78 ;
if ( ( V_37 -> V_79 & V_80 ) ||
( V_37 -> V_79 & V_81 ) )
V_50 |= V_82 ;
}
V_13 = F_35 ( V_22 , V_37 , V_47 , V_50 , 0 ) ;
if ( ! V_13 )
goto V_83;
V_46 = F_36 ( V_13 , V_44 , V_47 , V_39 -> V_84 ) ;
if ( V_46 < 0 )
goto V_83;
V_44 += V_47 ;
F_37 ( V_13 -> V_85 , ( T_3 * ) V_13 -> V_86
- ( T_3 * ) V_13 -> V_85 -> V_87 ) ;
F_25 ( V_2 , V_13 ) ;
F_38 ( & V_13 -> V_24 , & V_2 -> V_9 ) ;
if ( 0 == V_43 )
V_47 = V_41 ;
}
if ( V_45 ) {
if ( ! V_42 )
V_50 = V_88 ;
else
V_50 = V_78 ;
if ( ( V_37 -> V_79 & V_80 ) ||
( V_37 -> V_79 & V_81 ) )
V_50 |= V_82 ;
V_13 = F_35 ( V_22 , V_37 , V_45 , V_50 , 0 ) ;
if ( ! V_13 )
goto V_83;
V_46 = F_36 ( V_13 , V_44 , V_45 , V_39 -> V_84 ) ;
F_37 ( V_13 -> V_85 , ( T_3 * ) V_13 -> V_86
- ( T_3 * ) V_13 -> V_85 -> V_87 ) ;
if ( V_46 < 0 )
goto V_83;
F_25 ( V_2 , V_13 ) ;
F_38 ( & V_13 -> V_24 , & V_2 -> V_9 ) ;
}
return V_2 ;
V_83:
F_12 (pos, temp, &msg->chunks) {
F_13 ( V_15 ) ;
V_13 = F_14 ( V_15 , struct V_12 , V_24 ) ;
F_9 ( V_13 ) ;
}
F_10 ( V_2 ) ;
return NULL ;
}
int F_39 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
if ( ! V_2 -> V_6 )
return 0 ;
if ( F_40 ( V_53 , V_2 -> V_8 ) )
return 1 ;
return 0 ;
}
void F_41 ( struct V_12 * V_13 , int error )
{
V_13 -> V_2 -> V_4 = 1 ;
V_13 -> V_2 -> V_5 = error ;
}
