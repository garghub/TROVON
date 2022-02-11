static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void (* F_2)( struct V_1 * V_2 ,
struct V_5 * V_6 ) )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_5 * V_6 ;
F_3 ( & V_8 -> V_10 ) ;
F_4 (mark, &group->marks_list, g_list) {
F_2 ( V_2 , V_6 ) ;
if ( F_5 ( V_2 ) )
break;
}
F_6 ( & V_8 -> V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct {
struct V_12 V_13 ;
T_1 V_14 [ V_15 ] ;
} V_4 ;
int V_16 , V_17 , V_18 ;
V_4 . V_13 . V_19 = sizeof( V_4 . V_14 ) ;
V_16 = V_4 . V_13 . V_19 >> 2 ;
V_17 = F_8 ( V_11 , (struct V_20 * ) V_4 . V_13 . V_21 , & V_16 , 0 ) ;
if ( ( V_17 == V_22 ) || ( V_17 < 0 ) ) {
F_9 ( 1 , L_1 , V_17 ) ;
return;
}
V_4 . V_13 . V_23 = V_17 ;
V_4 . V_13 . V_19 = V_16 * sizeof( V_24 ) ;
F_10 ( V_2 , L_2 ,
V_4 . V_13 . V_19 , V_4 . V_13 . V_23 ) ;
for ( V_18 = 0 ; V_18 < V_4 . V_13 . V_19 ; V_18 ++ )
F_10 ( V_2 , L_3 , ( int ) V_4 . V_13 . V_21 [ V_18 ] ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
}
static void F_11 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_25 * V_26 ;
struct V_11 * V_11 ;
if ( ! ( V_6 -> V_27 & ( V_28 | V_29 ) ) )
return;
V_26 = F_12 ( V_6 , struct V_25 , V_30 ) ;
V_11 = F_13 ( V_6 -> V_11 ) ;
if ( V_11 ) {
F_10 ( V_2 , L_4 ,
V_26 -> V_31 , V_11 -> V_32 , V_11 -> V_33 -> V_34 ,
V_6 -> V_35 , V_6 -> V_36 ) ;
F_7 ( V_2 , V_11 ) ;
F_14 ( V_2 , '\n' ) ;
F_15 ( V_11 ) ;
}
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 , F_11 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned int V_37 = 0 ;
struct V_11 * V_11 ;
if ( ! ( V_6 -> V_27 & V_28 ) )
return;
if ( V_6 -> V_27 & V_38 )
V_37 |= V_39 ;
if ( V_6 -> V_27 & V_29 ) {
V_11 = F_13 ( V_6 -> V_11 ) ;
if ( ! V_11 )
return;
F_10 ( V_2 , L_5 ,
V_11 -> V_32 , V_11 -> V_33 -> V_34 ,
V_37 , V_6 -> V_35 , V_6 -> V_36 ) ;
F_7 ( V_2 , V_11 ) ;
F_14 ( V_2 , '\n' ) ;
F_15 ( V_11 ) ;
} else if ( V_6 -> V_27 & V_40 ) {
struct V_41 * V_42 = F_18 ( V_6 -> V_42 ) ;
F_10 ( V_2 , L_6 ,
V_42 -> V_43 , V_37 , V_6 -> V_35 , V_6 -> V_36 ) ;
}
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
unsigned int V_27 = 0 ;
switch ( V_8 -> V_44 ) {
case V_45 :
V_27 |= V_46 ;
break;
case V_47 :
V_27 |= V_48 ;
break;
case V_49 :
V_27 |= V_50 ;
break;
}
if ( V_8 -> V_51 == V_52 )
V_27 |= V_53 ;
if ( V_8 -> V_54 . V_55 == V_52 )
V_27 |= V_56 ;
F_10 ( V_2 , L_7 ,
V_27 , V_8 -> V_54 . V_57 ) ;
F_1 ( V_2 , V_4 , F_17 ) ;
}
