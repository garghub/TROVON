static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , & V_2 -> V_4 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_6 , V_7 , V_8 ;
T_1 V_9 = F_4 ( V_2 -> V_10 ) ;
V_8 = F_5 ( V_9 , V_3 ) ;
V_7 = V_8 / 2 ;
V_6 = V_8 - V_7 ;
V_2 -> V_11 = V_9 / V_8 ;
F_2 ( F_6 ( V_7 ) | F_7 ( V_6 ) ,
& V_2 -> V_4 -> V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_12 ,
T_1 V_3 )
{
F_2 ( V_3 , & V_2 -> V_4 -> V_13 [ V_12 ] ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 -> V_14 , L_1 ) ) {
return F_11 ( & V_2 -> V_4 -> V_15 . V_16 ) &
V_17 ;
} else {
return F_11 ( & V_2 -> V_18 -> V_15 ) &
V_17 ;
}
}
static void F_12 ( struct V_1 * V_2 , T_1 V_19 )
{
if ( F_10 ( V_2 -> V_14 , L_1 ) ) {
F_2 ( F_13 ( V_19 ) ,
& V_2 -> V_4 -> V_20 ) ;
F_2 ( F_14 ( V_19 ) ,
& V_2 -> V_4 -> V_21 ) ;
} else {
F_2 ( V_19 , & V_2 -> V_18 -> V_22 ) ;
}
}
static int F_15 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_3 ,
int * V_27 ,
long V_28 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
T_1 V_5 ;
switch ( V_28 ) {
case V_29 :
F_17 ( & V_24 -> V_30 ) ;
V_5 = F_18 ( V_26 -> V_31 ) |
F_19 ( V_2 -> V_32 ) |
V_33 |
V_34 ;
if ( V_2 -> V_35 == 0 )
V_5 |= V_36 ;
F_1 ( V_2 , V_5 ) ;
F_20 ( & V_2 -> V_37 ) ;
* V_3 = V_2 -> V_38 ;
F_21 ( & V_24 -> V_30 ) ;
return V_39 ;
case V_40 :
* V_3 = V_2 -> V_35 ;
* V_27 = V_41 ;
return V_42 ;
case V_43 :
* V_3 = V_2 -> V_11 ;
return V_39 ;
}
return - V_44 ;
}
static int F_22 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int V_3 ,
int V_27 ,
long V_28 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
int V_45 = 0 ;
if ( V_28 != V_43 )
return - V_44 ;
F_17 ( & V_24 -> V_30 ) ;
if ( ( V_3 < V_46 ) ||
( V_3 > V_47 ) ||
( V_27 != 0 ) ) {
V_45 = - V_44 ;
goto V_48;
}
F_3 ( V_2 , V_3 ) ;
V_48:
F_21 ( & V_24 -> V_30 ) ;
return V_45 ;
}
static T_2 F_23 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
V_2 -> V_38 = F_9 ( V_2 ) ;
F_24 ( & V_2 -> V_37 ) ;
return V_51 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_52 ;
F_1 ( V_2 , 0 ) ;
F_2 ( 0 , & V_2 -> V_4 -> V_10 ) ;
for ( V_52 = 0 ; V_52 < 8 ; V_52 ++ )
F_8 ( V_2 , V_52 , 0 ) ;
F_12 ( V_2 , 0 ) ;
F_3 ( V_2 , V_2 -> V_53 ) ;
return 0 ;
}
static int F_26 ( struct V_54 * V_55 )
{
struct V_56 * V_14 = V_55 -> V_57 . V_58 ;
struct V_59 * V_57 = & V_55 -> V_57 ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_23 * V_24 = NULL ;
int V_45 = - V_62 ;
int V_49 ;
V_24 = F_27 ( V_57 , sizeof( struct V_1 ) ) ;
if ( ! V_24 ) {
F_28 ( V_57 , L_2 ) ;
return - V_63 ;
}
V_2 = F_16 ( V_24 ) ;
V_2 -> V_14 = V_14 ;
V_61 = F_29 ( V_55 , V_64 , 0 ) ;
V_2 -> V_4 = F_30 ( & V_55 -> V_57 , V_61 ) ;
if ( F_31 ( V_2 -> V_4 ) )
return F_32 ( V_2 -> V_4 ) ;
V_2 -> V_18 =
(struct V_65 V_66 * ) V_2 -> V_4 ;
V_2 -> V_10 = F_33 ( V_57 , NULL ) ;
if ( F_31 ( V_2 -> V_10 ) ) {
F_28 ( V_57 , L_3 ) ;
return F_32 ( V_2 -> V_10 ) ;
}
V_45 = F_34 ( V_2 -> V_10 ) ;
if ( V_45 ) {
F_28 ( V_57 , L_4 ) ;
return V_45 ;
}
V_49 = F_35 ( V_55 , 0 ) ;
if ( V_49 <= 0 ) {
F_28 ( V_57 , L_5 ) ;
V_45 = - V_44 ;
goto V_67;
}
V_45 = F_36 ( V_57 , V_49 , F_23 , 0 , V_68 ,
V_2 ) ;
if ( V_45 < 0 ) {
F_28 ( V_57 , L_6 ) ;
goto V_67;
}
if ( F_37 ( V_14 , L_7 ,
& V_2 -> V_53 ) ) {
F_28 ( V_57 , L_8 ) ;
V_45 = - V_44 ;
goto V_67;
}
F_37 ( V_14 , L_9 , & V_2 -> V_32 ) ;
F_37 ( V_14 , L_10 , & V_2 -> V_35 ) ;
F_25 ( V_2 ) ;
F_38 ( V_55 , V_24 ) ;
F_39 ( & V_2 -> V_37 ) ;
V_24 -> V_69 = V_68 ;
V_24 -> V_57 . V_70 = V_57 ;
V_24 -> V_71 = & V_72 ;
V_24 -> V_73 = V_74 ;
V_24 -> V_75 = V_76 ;
V_24 -> V_77 = F_40 ( V_76 ) ;
V_45 = F_41 ( V_24 ) ;
if ( V_45 )
goto V_67;
F_42 ( V_57 , L_11 , V_49 ) ;
return 0 ;
V_67:
F_43 ( V_2 -> V_10 ) ;
return V_45 ;
}
static int F_44 ( struct V_54 * V_55 )
{
struct V_23 * V_24 = F_45 ( V_55 ) ;
struct V_1 * V_2 = F_16 ( V_24 ) ;
F_46 ( V_24 ) ;
F_43 ( V_2 -> V_10 ) ;
return 0 ;
}
