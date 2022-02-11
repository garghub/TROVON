static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
T_1 V_8 ;
int V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_11 && ! F_4 ( V_12 ,
V_4 -> V_13 + V_14 + V_14 / 2 ) )
goto abort;
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
V_8 = F_5 ( V_6 , F_6 ( V_9 ) ) ;
if ( F_7 ( V_8 < 0 ) ) {
V_7 = F_8 ( V_8 ) ;
goto abort;
}
V_4 -> V_15 [ V_9 ] = ( V_16 ) V_8 ;
V_8 = F_5 ( V_6 , F_9 ( V_9 ) ) ;
if ( F_7 ( V_8 < 0 ) ) {
V_7 = F_8 ( V_8 ) ;
goto abort;
}
V_4 -> V_17 [ V_9 ] = ( V_16 ) V_8 ;
V_8 = F_5 ( V_6 , F_10 ( V_9 ) ) ;
if ( F_7 ( V_8 < 0 ) ) {
V_7 = F_8 ( V_8 ) ;
goto abort;
}
V_4 -> V_18 [ V_9 ] = ( V_16 ) V_8 ;
}
V_8 = F_5 ( V_6 , V_19 ) ;
if ( F_7 ( V_8 < 0 ) ) {
V_7 = F_8 ( V_8 ) ;
goto abort;
}
V_4 -> V_20 = V_8 << 8 ;
V_8 = F_5 ( V_6 , V_21 ) ;
if ( F_7 ( V_8 < 0 ) ) {
V_7 = F_8 ( V_8 ) ;
goto abort;
}
V_4 -> V_20 |= V_8 ;
V_4 -> V_13 = V_12 ;
V_4 -> V_11 = 1 ;
abort:
F_11 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static T_2 F_12 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_13 ( V_23 ) -> V_25 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_24 , L_1 , V_4 -> V_15 [ V_25 ] * 1000 ) ;
}
static T_2 F_16 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_13 ( V_23 ) -> V_25 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_24 , L_1 , V_4 -> V_17 [ V_25 ] * 1000 ) ;
}
static T_2 F_17 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_13 ( V_23 ) -> V_25 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_24 , L_1 , V_4 -> V_18 [ V_25 ] * 1000 ) ;
}
static T_2 F_18 ( struct V_2 * V_3 , struct V_22 * V_26 ,
char * V_24 )
{
int V_25 = F_13 ( V_26 ) -> V_25 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_24 , L_2 , ( V_4 -> V_20 >> V_25 ) & 0x1 ) ;
}
static T_2 F_19 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_13 ( V_23 ) -> V_25 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
return sprintf ( V_24 , L_2 ,
( V_4 -> V_20 & ( 1 << 12 ) ) && V_4 -> V_15 [ V_25 ] == 127 ) ;
}
static T_2 F_20 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
const char * V_24 , T_3 V_27 )
{
int V_25 = F_13 ( V_23 ) -> V_25 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_15 ;
int V_7 ;
V_7 = F_21 ( V_24 , 10 , & V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_17 [ V_25 ] = F_22 ( V_15 / 1000 , - 128 , 127 ) ;
V_7 = F_23 ( V_6 ,
F_24 ( V_25 ) ,
V_4 -> V_17 [ V_25 ] ) ;
if ( V_7 < 0 )
V_27 = V_7 ;
F_11 ( & V_4 -> V_10 ) ;
return V_27 ;
}
static T_2 F_25 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
const char * V_24 , T_3 V_27 )
{
int V_25 = F_13 ( V_23 ) -> V_25 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
long V_15 ;
int V_7 ;
V_7 = F_21 ( V_24 , 10 , & V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_18 [ V_25 ] = F_22 ( V_15 / 1000 , - 128 , 127 ) ;
V_7 = F_23 ( V_6 ,
F_26 ( V_25 ) ,
V_4 -> V_18 [ V_25 ] ) ;
if ( V_7 < 0 )
V_27 = V_7 ;
F_11 ( & V_4 -> V_10 ) ;
return V_27 ;
}
static T_4 F_27 ( struct V_28 * V_29 ,
struct V_30 * V_26 , int V_25 )
{
T_4 V_7 = V_31 ;
if ( V_32 )
return V_7 ;
if ( V_26 == & V_33 . V_34 . V_26 ||
V_26 == & V_35 . V_34 . V_26 ||
V_26 == & V_36 . V_34 . V_26 ||
V_26 == & V_37 . V_34 . V_26 ||
V_26 == & V_38 . V_34 . V_26 ||
V_26 == & V_39 . V_34 . V_26 ||
V_26 == & V_40 . V_34 . V_26 ||
V_26 == & V_41 . V_34 . V_26 ||
V_26 == & V_42 . V_34 . V_26 ||
V_26 == & V_43 . V_34 . V_26 )
V_7 |= V_44 ;
return V_7 ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = V_6 -> V_48 ;
const char * V_49 ;
int V_50 , V_51 ;
if ( ! F_29 ( V_48 , V_52 ) )
return - V_53 ;
V_50 = F_5 ( V_6 , V_54 ) ;
if ( V_50 != V_55 )
return - V_53 ;
V_51 = F_5 ( V_6 , V_56 ) ;
if ( V_51 < 0 )
return - V_53 ;
V_49 = NULL ;
if ( V_51 == V_57 )
V_49 = L_3 ;
else if ( V_51 == V_58 )
V_49 = L_4 ;
else if ( V_51 == V_59 )
V_49 = L_5 ;
if ( ! V_49 )
return - V_53 ;
F_30 ( V_46 -> type , V_49 , V_60 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_61 * V_62 )
{
struct V_47 * V_48 = V_6 -> V_48 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_2 * V_63 ;
struct V_1 * V_4 ;
if ( ! F_29 ( V_48 , V_52 ) )
return - V_53 ;
V_4 = F_32 ( V_3 , sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_4 -> V_6 = V_6 ;
V_4 -> type = V_62 -> V_66 ;
F_33 ( & V_4 -> V_10 ) ;
V_4 -> V_67 [ 0 ] = & V_68 ;
if ( V_4 -> type == V_69 || V_4 -> type == V_70 )
V_4 -> V_67 [ 1 ] = & V_71 ;
V_63 = F_34 ( V_3 , V_6 -> V_72 ,
V_4 , V_4 -> V_67 ) ;
return F_35 ( V_63 ) ;
}
