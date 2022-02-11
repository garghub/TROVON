static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_2)( struct V_1 * V_2 , struct V_5 * V_6 ) )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_5 * V_6 ;
int V_10 = 0 ;
F_3 ( & V_8 -> V_11 ) ;
F_4 (mark, &group->marks_list, g_list) {
V_10 = F_2 ( V_2 , V_6 ) ;
if ( V_10 )
break;
}
F_5 ( & V_8 -> V_11 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
struct {
struct V_13 V_14 ;
T_1 V_15 [ 64 ] ;
} V_4 ;
int V_16 , V_10 , V_17 ;
V_4 . V_14 . V_18 = sizeof( V_4 . V_15 ) ;
V_16 = V_4 . V_14 . V_18 >> 2 ;
V_10 = F_7 ( V_12 , (struct V_19 * ) V_4 . V_14 . V_20 , & V_16 , 0 ) ;
if ( ( V_10 == 255 ) || ( V_10 == - V_21 ) ) {
F_8 ( 1 , L_1 , V_10 ) ;
return 0 ;
}
V_4 . V_14 . V_22 = V_10 ;
V_4 . V_14 . V_18 = V_16 * sizeof( V_23 ) ;
V_10 = F_9 ( V_2 , L_2 ,
V_4 . V_14 . V_18 , V_4 . V_14 . V_22 ) ;
for ( V_17 = 0 ; V_17 < V_4 . V_14 . V_18 ; V_17 ++ )
V_10 |= F_9 ( V_2 , L_3 , ( int ) V_4 . V_14 . V_20 [ V_17 ] ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_24 * V_25 ;
struct V_12 * V_12 ;
int V_10 = 0 ;
if ( ! ( V_6 -> V_26 & ( V_27 | V_28 ) ) )
return 0 ;
V_25 = F_11 ( V_6 , struct V_24 , V_29 ) ;
V_12 = F_12 ( V_6 -> V_17 . V_12 ) ;
if ( V_12 ) {
V_10 = F_9 ( V_2 , L_4
L_5 ,
V_25 -> V_30 , V_12 -> V_31 ,
V_12 -> V_32 -> V_33 ,
V_6 -> V_34 , V_6 -> V_35 ) ;
V_10 |= F_6 ( V_2 , V_12 ) ;
V_10 |= F_13 ( V_2 , '\n' ) ;
F_14 ( V_12 ) ;
}
return V_10 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_1 ( V_2 , V_4 , F_10 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned int V_36 = 0 ;
struct V_12 * V_12 ;
int V_10 = 0 ;
if ( ! ( V_6 -> V_26 & V_27 ) )
return 0 ;
if ( V_6 -> V_26 & V_37 )
V_36 |= V_38 ;
if ( V_6 -> V_26 & V_28 ) {
V_12 = F_12 ( V_6 -> V_17 . V_12 ) ;
if ( ! V_12 )
goto V_39;
V_10 = F_9 ( V_2 , L_6
L_7 ,
V_12 -> V_31 , V_12 -> V_32 -> V_33 ,
V_36 , V_6 -> V_34 , V_6 -> V_35 ) ;
V_10 |= F_6 ( V_2 , V_12 ) ;
V_10 |= F_13 ( V_2 , '\n' ) ;
F_14 ( V_12 ) ;
} else if ( V_6 -> V_26 & V_40 ) {
struct V_41 * V_42 = F_17 ( V_6 -> V_2 . V_42 ) ;
V_10 = F_9 ( V_2 , L_8
L_9 , V_42 -> V_43 , V_36 ,
V_6 -> V_34 , V_6 -> V_35 ) ;
}
V_39:
return V_10 ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
unsigned int V_26 = 0 ;
switch ( V_8 -> V_44 ) {
case V_45 :
V_26 |= V_46 ;
break;
case V_47 :
V_26 |= V_48 ;
break;
case V_49 :
V_26 |= V_50 ;
break;
}
if ( V_8 -> V_51 == V_52 )
V_26 |= V_53 ;
if ( V_8 -> V_54 . V_55 == V_52 )
V_26 |= V_56 ;
F_9 ( V_2 , L_10 ,
V_26 , V_8 -> V_54 . V_57 ) ;
return F_1 ( V_2 , V_4 , F_16 ) ;
}
