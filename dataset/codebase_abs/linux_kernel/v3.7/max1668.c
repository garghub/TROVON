static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_1 * V_7 = V_6 ;
T_1 V_8 ;
int V_9 ;
F_4 ( & V_6 -> V_10 ) ;
if ( V_6 -> V_11 && ! F_5 ( V_12 ,
V_6 -> V_13 + V_14 + V_14 / 2 ) )
goto abort;
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
V_8 = F_6 ( V_5 , F_7 ( V_9 ) ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_15 [ V_9 ] = ( V_16 ) V_8 ;
V_8 = F_6 ( V_5 , F_10 ( V_9 ) ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_17 [ V_9 ] = ( V_16 ) V_8 ;
V_8 = F_6 ( V_5 , F_11 ( V_9 ) ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_18 [ V_9 ] = ( V_16 ) V_8 ;
}
V_8 = F_6 ( V_5 , V_19 ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_20 = V_8 << 8 ;
V_8 = F_6 ( V_5 , V_21 ) ;
if ( F_8 ( V_8 < 0 ) ) {
V_7 = F_9 ( V_8 ) ;
goto abort;
}
V_6 -> V_20 |= V_8 ;
V_6 -> V_13 = V_12 ;
V_6 -> V_11 = 1 ;
abort:
F_12 ( & V_6 -> V_10 ) ;
return V_7 ;
}
static T_2 F_13 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_14 ( V_23 ) -> V_25 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_24 , L_1 , V_6 -> V_15 [ V_25 ] * 1000 ) ;
}
static T_2 F_17 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_14 ( V_23 ) -> V_25 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_24 , L_1 , V_6 -> V_17 [ V_25 ] * 1000 ) ;
}
static T_2 F_18 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_14 ( V_23 ) -> V_25 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_24 , L_1 , V_6 -> V_18 [ V_25 ] * 1000 ) ;
}
static T_2 F_19 ( struct V_2 * V_3 , struct V_22 * V_26 ,
char * V_24 )
{
int V_25 = F_14 ( V_26 ) -> V_25 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_24 , L_2 , ( V_6 -> V_20 >> V_25 ) & 0x1 ) ;
}
static T_2 F_20 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
int V_25 = F_14 ( V_23 ) -> V_25 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_15 ( V_6 ) )
return F_16 ( V_6 ) ;
return sprintf ( V_24 , L_2 ,
( V_6 -> V_20 & ( 1 << 12 ) ) && V_6 -> V_15 [ V_25 ] == 127 ) ;
}
static T_2 F_21 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
const char * V_24 , T_3 V_27 )
{
int V_25 = F_14 ( V_23 ) -> V_25 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
long V_15 ;
int V_7 ;
V_7 = F_22 ( V_24 , 10 , & V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_17 [ V_25 ] = F_23 ( V_15 / 1000 , - 128 , 127 ) ;
if ( F_24 ( V_5 ,
F_25 ( V_25 ) ,
V_6 -> V_17 [ V_25 ] ) )
V_27 = - V_28 ;
F_12 ( & V_6 -> V_10 ) ;
return V_27 ;
}
static T_2 F_26 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
const char * V_24 , T_3 V_27 )
{
int V_25 = F_14 ( V_23 ) -> V_25 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_3 ( V_5 ) ;
long V_15 ;
int V_7 ;
V_7 = F_22 ( V_24 , 10 , & V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_18 [ V_25 ] = F_23 ( V_15 / 1000 , - 128 , 127 ) ;
if ( F_24 ( V_5 ,
F_27 ( V_25 ) ,
V_6 -> V_17 [ V_25 ] ) )
V_27 = - V_28 ;
F_12 ( & V_6 -> V_10 ) ;
return V_27 ;
}
static T_4 F_28 ( struct V_29 * V_30 ,
struct V_31 * V_26 , int V_25 )
{
T_4 V_7 = V_32 ;
if ( V_33 )
return V_7 ;
if ( V_26 == & V_34 . V_35 . V_26 ||
V_26 == & V_36 . V_35 . V_26 ||
V_26 == & V_37 . V_35 . V_26 ||
V_26 == & V_38 . V_35 . V_26 ||
V_26 == & V_39 . V_35 . V_26 ||
V_26 == & V_40 . V_35 . V_26 ||
V_26 == & V_41 . V_35 . V_26 ||
V_26 == & V_42 . V_35 . V_26 ||
V_26 == & V_43 . V_35 . V_26 ||
V_26 == & V_44 . V_35 . V_26 )
V_7 |= V_45 ;
return V_7 ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = V_5 -> V_49 ;
const char * V_50 ;
int V_51 , V_52 ;
if ( ! F_30 ( V_49 , V_53 ) )
return - V_54 ;
V_51 = F_6 ( V_5 , V_55 ) ;
if ( V_51 != V_56 )
return - V_54 ;
V_52 = F_6 ( V_5 , V_57 ) ;
if ( V_52 < 0 )
return - V_54 ;
V_50 = NULL ;
if ( V_52 == V_58 )
V_50 = L_3 ;
else if ( V_52 == V_59 )
V_50 = L_4 ;
else if ( V_52 == V_60 )
V_50 = L_5 ;
if ( ! V_50 )
return - V_54 ;
F_31 ( V_47 -> type , V_50 , V_61 ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
const struct V_62 * V_63 )
{
struct V_48 * V_49 = V_5 -> V_49 ;
struct V_1 * V_6 ;
int V_64 ;
if ( ! F_30 ( V_49 , V_53 ) )
return - V_54 ;
V_6 = F_33 ( & V_5 -> V_3 , sizeof( struct V_1 ) ,
V_65 ) ;
if ( ! V_6 )
return - V_66 ;
F_34 ( V_5 , V_6 ) ;
V_6 -> type = V_63 -> V_67 ;
F_35 ( & V_6 -> V_10 ) ;
V_64 = F_36 ( & V_5 -> V_3 . V_30 , & V_68 ) ;
if ( V_64 )
return V_64 ;
if ( V_6 -> type == V_69 || V_6 -> type == V_70 ) {
V_64 = F_36 ( & V_5 -> V_3 . V_30 ,
& V_71 ) ;
if ( V_64 )
goto V_72;
}
V_6 -> V_73 = F_37 ( & V_5 -> V_3 ) ;
if ( F_15 ( V_6 -> V_73 ) ) {
V_64 = F_16 ( V_6 -> V_73 ) ;
goto V_74;
}
return 0 ;
V_74:
if ( V_6 -> type == V_69 || V_6 -> type == V_70 )
F_38 ( & V_5 -> V_3 . V_30 , & V_71 ) ;
V_72:
F_38 ( & V_5 -> V_3 . V_30 , & V_68 ) ;
return V_64 ;
}
static int F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_40 ( V_6 -> V_73 ) ;
if ( V_6 -> type == V_69 || V_6 -> type == V_70 )
F_38 ( & V_5 -> V_3 . V_30 , & V_71 ) ;
F_38 ( & V_5 -> V_3 . V_30 , & V_68 ) ;
return 0 ;
}
