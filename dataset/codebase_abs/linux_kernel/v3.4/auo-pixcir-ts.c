static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
T_1 V_11 [ 8 ] ;
T_1 V_12 [ 4 ] ;
int V_13 , V_14 ;
V_14 = F_2 ( V_6 , V_15 ,
8 , V_11 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_1 , V_14 ) ;
return V_14 ;
}
V_14 = F_2 ( V_6 , V_16 ,
4 , V_12 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_2 , V_14 ) ;
return V_14 ;
}
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
V_4 [ V_13 ] . V_18 =
V_11 [ 4 * V_13 + 1 ] << 8 | V_11 [ 4 * V_13 ] ;
V_4 [ V_13 ] . V_19 =
V_11 [ 4 * V_13 + 3 ] << 8 | V_11 [ 4 * V_13 + 2 ] ;
if ( V_4 [ V_13 ] . V_18 > V_8 -> V_20 ||
V_4 [ V_13 ] . V_19 > V_8 -> V_21 ) {
F_4 ( & V_6 -> V_9 , L_3 ,
V_4 [ V_13 ] . V_18 , V_4 [ V_13 ] . V_19 ) ;
V_4 [ V_13 ] . V_18 = V_4 [ V_13 ] . V_19 = 0 ;
}
V_4 [ V_13 ] . V_22 = F_5 ( V_12 [ 2 * V_13 ] , V_12 [ 2 * V_13 + 1 ] ) ;
V_4 [ V_13 ] . V_23 = F_6 ( V_12 [ 2 * V_13 ] , V_12 [ 2 * V_13 + 1 ] ) ;
V_4 [ V_13 ] . V_24 = V_12 [ 2 * V_13 ] > V_12 [ 2 * V_13 + 1 ] ;
}
return 0 ;
}
static T_2 F_7 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
struct V_3 V_4 [ V_17 ] ;
int V_13 ;
int V_14 ;
int V_27 = 0 ;
int abs = - 1 ;
while ( ! V_2 -> V_28 ) {
if ( V_2 -> V_29 ) {
if ( F_8 ( V_8 -> V_30 ) == 0 ) {
F_9 ( V_2 -> V_31 ) ;
F_10 ( V_2 -> V_31 , V_32 , 0 ) ;
F_11 ( V_2 -> V_31 ) ;
break;
}
}
V_14 = F_1 ( V_2 , V_4 ) ;
if ( V_14 < 0 ) {
if ( ! V_2 -> V_29 )
break;
F_12 ( V_2 -> V_33 , V_2 -> V_28 ,
F_13 ( V_34 ) ) ;
continue;
}
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
if ( V_4 [ V_13 ] . V_18 > 0 || V_4 [ V_13 ] . V_19 > 0 ) {
F_14 ( V_2 -> V_31 , V_35 ,
V_4 [ V_13 ] . V_18 ) ;
F_14 ( V_2 -> V_31 , V_36 ,
V_4 [ V_13 ] . V_19 ) ;
F_14 ( V_2 -> V_31 , V_37 ,
V_4 [ V_13 ] . V_22 ) ;
F_14 ( V_2 -> V_31 , V_38 ,
V_4 [ V_13 ] . V_23 ) ;
F_14 ( V_2 -> V_31 , V_39 ,
V_4 [ V_13 ] . V_24 ) ;
F_9 ( V_2 -> V_31 ) ;
if ( V_27 == 0 )
abs = V_13 ;
V_27 ++ ;
}
}
F_10 ( V_2 -> V_31 , V_32 , V_27 > 0 ) ;
if ( abs > - 1 ) {
F_14 ( V_2 -> V_31 , V_40 , V_4 [ abs ] . V_18 ) ;
F_14 ( V_2 -> V_31 , V_41 , V_4 [ abs ] . V_19 ) ;
}
F_11 ( V_2 -> V_31 ) ;
if ( ! V_2 -> V_29 )
break;
F_12 ( V_2 -> V_33 , V_2 -> V_28 ,
F_13 ( V_34 ) ) ;
}
return V_42 ;
}
static int F_15 ( struct V_1 * V_2 , int V_43 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_14 ;
V_14 = F_16 ( V_6 , V_44 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_4 ,
V_44 , V_14 ) ;
return V_14 ;
}
V_14 &= ~ V_45 ;
V_14 |= V_43 ;
V_14 = F_17 ( V_6 , V_44 , V_14 ) ;
if ( V_14 ) {
F_3 ( & V_6 -> V_9 , L_5 ,
V_44 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static T_3 int F_18 ( struct V_1 * V_2 ,
int V_46 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
int V_14 ;
V_14 = F_16 ( V_6 , V_47 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_4 ,
V_47 , V_14 ) ;
return V_14 ;
}
V_14 &= ~ V_48 ;
V_14 |= V_46 ;
V_14 |= V_49 ;
V_14 = F_17 ( V_6 , V_47 ,
V_14 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_5 ,
V_47 , V_14 ) ;
return V_14 ;
}
V_2 -> V_29 = V_8 -> V_46 == V_50 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , bool V_51 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_14 ;
V_14 = F_16 ( V_6 , V_47 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_4 ,
V_47 , V_14 ) ;
return V_14 ;
}
if ( V_51 )
V_14 |= V_52 ;
else
V_14 &= ~ V_52 ;
V_14 = F_17 ( V_6 , V_47 ,
V_14 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_5 ,
V_47 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_14 ;
V_14 = F_15 ( V_2 , V_53 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_6 ,
V_14 ) ;
return V_14 ;
}
V_2 -> V_28 = false ;
F_21 () ;
F_22 ( V_6 -> V_25 ) ;
V_14 = F_19 ( V_2 , 1 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_7 ,
V_14 ) ;
F_23 ( V_6 -> V_25 ) ;
return V_14 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_14 ;
V_14 = F_19 ( V_2 , 0 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_6 -> V_9 , L_8 ,
V_14 ) ;
return V_14 ;
}
F_23 ( V_6 -> V_25 ) ;
V_2 -> V_28 = true ;
F_21 () ;
F_25 ( & V_2 -> V_33 ) ;
return F_15 ( V_2 , V_54 ) ;
}
static int F_26 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
int V_14 ;
V_14 = F_20 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static void F_28 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
F_24 ( V_2 ) ;
return;
}
static int F_29 ( struct V_56 * V_9 )
{
struct V_5 * V_6 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_31 ( V_6 ) ;
struct V_55 * V_31 = V_2 -> V_31 ;
int V_14 = 0 ;
F_32 ( & V_31 -> V_57 ) ;
if ( F_33 ( & V_6 -> V_9 ) ) {
if ( ! V_31 -> V_58 ) {
V_14 = F_20 ( V_2 ) ;
if ( V_14 )
goto V_59;
}
F_34 ( V_6 -> V_25 ) ;
V_14 = F_15 ( V_2 , V_60 ) ;
} else if ( V_31 -> V_58 ) {
V_14 = F_24 ( V_2 ) ;
}
V_59:
F_35 ( & V_31 -> V_57 ) ;
return V_14 ;
}
static int F_36 ( struct V_56 * V_9 )
{
struct V_5 * V_6 = F_30 ( V_9 ) ;
struct V_1 * V_2 = F_31 ( V_6 ) ;
struct V_55 * V_31 = V_2 -> V_31 ;
int V_14 = 0 ;
F_32 ( & V_31 -> V_57 ) ;
if ( F_33 ( & V_6 -> V_9 ) ) {
F_37 ( V_6 -> V_25 ) ;
if ( ! V_31 -> V_58 ) {
V_14 = F_24 ( V_2 ) ;
if ( V_14 )
goto V_59;
}
} else if ( V_31 -> V_58 ) {
V_14 = F_20 ( V_2 ) ;
}
V_59:
F_35 ( & V_31 -> V_57 ) ;
return V_14 ;
}
static int T_3 F_38 ( struct V_5 * V_6 ,
const struct V_61 * V_62 )
{
const struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
struct V_1 * V_2 ;
struct V_55 * V_55 ;
int V_14 ;
if ( ! V_8 )
return - V_63 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_14 = F_40 ( V_8 -> V_30 , L_9 ) ;
if ( V_14 ) {
F_3 ( & V_6 -> V_9 , L_10 ,
V_8 -> V_30 , V_14 ) ;
goto V_66;
}
if ( V_8 -> V_67 )
V_8 -> V_67 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_29 = 0 ;
F_41 ( & V_2 -> V_33 ) ;
snprintf ( V_2 -> V_68 , sizeof( V_2 -> V_68 ) ,
L_11 , F_42 ( & V_6 -> V_9 ) ) ;
V_55 = F_43 () ;
if ( ! V_55 ) {
F_3 ( & V_6 -> V_9 , L_12 ) ;
goto V_69;
}
V_2 -> V_31 = V_55 ;
V_55 -> V_70 = L_13 ;
V_55 -> V_68 = V_2 -> V_68 ;
V_55 -> V_62 . V_71 = V_72 ;
V_55 -> V_9 . V_73 = & V_6 -> V_9 ;
V_55 -> V_74 = F_26 ;
V_55 -> V_75 = F_28 ;
F_44 ( V_76 , V_55 -> V_77 ) ;
F_44 ( V_78 , V_55 -> V_77 ) ;
F_44 ( V_32 , V_55 -> V_79 ) ;
F_45 ( V_55 , V_40 , 0 , V_8 -> V_20 , 0 , 0 ) ;
F_45 ( V_55 , V_41 , 0 , V_8 -> V_21 , 0 , 0 ) ;
F_45 ( V_55 , V_35 , 0 ,
V_8 -> V_20 , 0 , 0 ) ;
F_45 ( V_55 , V_36 , 0 ,
V_8 -> V_21 , 0 , 0 ) ;
F_45 ( V_55 , V_37 , 0 ,
V_80 , 0 , 0 ) ;
F_45 ( V_55 , V_38 , 0 ,
V_80 , 0 , 0 ) ;
F_45 ( V_55 , V_39 , 0 , 1 , 0 , 0 ) ;
V_14 = F_16 ( V_6 , V_81 ) ;
if ( V_14 < 0 )
goto V_82;
F_46 ( & V_6 -> V_9 , L_14 , V_14 ) ;
V_14 = F_18 ( V_2 , V_8 -> V_46 ) ;
if ( V_14 )
goto V_82;
F_47 ( V_2 -> V_31 , V_2 ) ;
V_2 -> V_28 = true ;
V_14 = F_48 ( V_6 -> V_25 , NULL , F_7 ,
V_83 | V_84 ,
V_55 -> V_70 , V_2 ) ;
if ( V_14 ) {
F_3 ( & V_6 -> V_9 , L_15 , V_6 -> V_25 ) ;
goto V_82;
}
V_14 = F_24 ( V_2 ) ;
if ( V_14 < 0 )
goto V_85;
V_14 = F_49 ( V_55 ) ;
if ( V_14 ) {
F_3 ( & V_6 -> V_9 , L_16 ) ;
goto V_85;
}
F_50 ( V_6 , V_2 ) ;
return 0 ;
V_85:
F_51 ( V_6 -> V_25 , V_2 ) ;
V_82:
F_52 ( V_55 ) ;
V_69:
if ( V_8 -> V_86 )
V_8 -> V_86 ( V_6 ) ;
F_53 ( V_8 -> V_30 ) ;
V_66:
F_54 ( V_2 ) ;
return V_14 ;
}
static int T_4 F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
const struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
F_51 ( V_6 -> V_25 , V_2 ) ;
F_56 ( V_2 -> V_31 ) ;
if ( V_8 -> V_86 )
V_8 -> V_86 ( V_6 ) ;
F_53 ( V_8 -> V_30 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
