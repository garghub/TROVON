static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
struct {
T_2 V_5 ;
T_2 V_6 ;
} V_7 ;
unsigned V_8 = sizeof( V_7 ) ;
V_7 . V_5 = V_2 -> V_5 ;
if ( V_3 ) {
V_4 = V_9 ;
V_8 -= sizeof( V_7 . V_6 ) ;
} else {
V_7 . V_6 = V_10 ;
V_4 = V_11 ;
}
return F_2 ( V_2 -> V_12 , V_4 , & V_7 , V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_13 )
{
struct {
T_2 V_5 ;
T_2 V_14 ;
} V_7 ;
V_7 . V_5 = V_2 -> V_5 ;
V_7 . V_14 = ~ V_13 ;
return F_2 ( V_2 -> V_12 , V_15 , & V_7 , sizeof( V_7 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_14 )
{
return F_3 ( V_2 , F_5 ( V_14 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_13 , bool V_3 )
{
struct {
T_2 V_5 ;
T_2 V_14 ;
} V_7 ;
T_1 V_4 ;
V_7 . V_5 = V_2 -> V_5 ;
V_7 . V_14 = V_13 ;
V_4 = V_3 ? V_16 : V_17 ;
return F_2 ( V_2 -> V_12 , V_4 , & V_7 , sizeof( V_7 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_3 )
{
T_2 V_13 = F_8 ( V_2 -> V_18 -> V_19 - 1 , 0 ) ;
return F_6 ( V_2 , V_13 , V_3 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_20 )
{
int V_21 ;
struct {
T_2 V_5 ;
} V_7 ;
struct {
T_3 V_22 ;
} V_23 ;
unsigned V_24 = sizeof( V_23 ) ;
V_7 . V_5 = V_2 -> V_5 ;
V_21 = F_10 ( V_2 -> V_12 , V_25 , & V_7 , sizeof( V_7 ) ,
& V_23 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_24 < sizeof( V_23 ) )
return - V_26 ;
* V_20 = F_11 ( V_23 . V_22 ) ;
F_12 ( & V_2 -> V_12 -> V_27 , L_1 , * V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_4 * V_28 )
{
int V_21 ;
struct {
T_2 V_5 ;
} V_7 ;
struct {
T_5 V_29 ;
} V_23 ;
unsigned V_24 = sizeof( V_23 ) ;
V_7 . V_5 = V_2 -> V_5 ;
V_21 = F_10 ( V_2 -> V_12 , V_4 , & V_7 , sizeof( V_7 ) , & V_23 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_24 < sizeof( V_23 ) )
return - V_26 ;
* V_28 = F_14 ( V_23 . V_29 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_4 * V_30 , T_4 * V_31 )
{
int V_21 ;
V_21 = F_13 ( V_2 , V_32 , V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_13 ( V_2 , V_33 , V_31 ) ;
if ( V_21 < 0 )
return V_21 ;
F_12 ( & V_2 -> V_12 -> V_27 , L_2 ,
* V_30 , * V_31 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_29 )
{
int V_21 ;
struct {
T_2 V_5 ;
T_5 V_29 ;
} V_34 V_7 ;
struct {
T_5 V_29 ;
} V_23 ;
int V_24 = sizeof( V_23 ) ;
V_7 . V_5 = V_2 -> V_5 ;
V_7 . V_29 = F_17 ( V_29 ) ;
V_21 = F_10 ( V_2 -> V_12 , V_35 , & V_7 , sizeof( V_7 ) ,
& V_23 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_24 < sizeof( V_23 ) )
return - V_26 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_36 )
{
struct {
T_2 V_5 ;
T_2 V_36 ;
} V_7 ;
V_7 . V_5 = V_2 -> V_5 ;
V_7 . V_36 = V_36 ;
return F_2 ( V_2 -> V_12 , V_37 , & V_7 , sizeof( V_7 ) ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_38 )
{
struct {
T_2 V_5 ;
T_2 V_38 ;
} V_7 ;
V_7 . V_5 = V_2 -> V_5 ;
V_7 . V_38 = V_38 ;
return F_2 ( V_2 -> V_12 , V_39 ,
& V_7 , sizeof( V_7 ) ) ;
}
static int F_20 ( struct V_1 * V_2 ,
T_4 * V_40 )
{
int V_21 ;
struct {
T_2 V_5 ;
} V_7 ;
struct {
T_2 V_41 ;
T_2 V_42 [ 36 ] ;
} * V_23 = V_2 -> V_43 ;
unsigned V_24 = sizeof( * V_23 ) ;
int V_44 ;
V_7 . V_5 = V_2 -> V_5 ;
V_21 = F_10 ( V_2 -> V_12 , V_45 ,
& V_7 , sizeof( V_7 ) , V_23 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_24 < sizeof( * V_23 ) )
return - V_26 ;
if ( V_23 -> V_41 > F_21 ( V_23 -> V_42 ) )
return - V_26 ;
* V_40 = 0 ;
for ( V_44 = 0 ; V_44 < V_23 -> V_41 ; V_44 ++ )
* V_40 |= F_5 ( V_23 -> V_42 [ V_44 ] - 1 ) ;
F_12 ( & V_2 -> V_12 -> V_27 , L_3 , * V_40 ) ;
return 0 ;
}
static int F_22 ( T_2 * V_46 , const T_2 * V_47 , T_1 V_8 , T_2 V_38 )
{
#ifdef F_23
memcpy ( V_46 , V_47 , V_8 ) ;
#else
if ( V_38 <= 8 ) {
memcpy ( V_46 , V_47 , V_8 ) ;
} else if ( V_38 <= 16 ) {
T_3 * V_48 = ( T_3 * ) V_46 ;
T_1 * V_49 = ( T_1 * ) V_47 ;
V_8 = V_8 / 2 ;
while ( V_8 -- )
* V_48 ++ = F_24 ( V_49 ++ ) ;
} else {
T_5 * V_48 = ( T_5 * ) V_46 ;
T_4 * V_49 = ( T_4 * ) V_47 ;
V_8 = V_8 / 4 ;
while ( V_8 -- )
* V_48 ++ = F_25 ( V_49 ++ ) ;
}
#endif
return 0 ;
}
static int F_26 ( T_2 * V_50 , const T_2 * V_46 , T_1 V_8 , T_2 V_38 )
{
#ifdef F_23
memcpy ( V_50 , V_46 , V_8 ) ;
#else
if ( V_38 <= 8 ) {
memcpy ( V_50 , V_46 , V_8 ) ;
} else if ( V_38 <= 16 ) {
T_1 * V_48 = ( T_1 * ) V_50 ;
T_3 * V_49 = ( T_3 * ) V_46 ;
V_8 = V_8 / 2 ;
while ( V_8 -- )
* V_48 ++ = F_27 ( V_49 ++ ) ;
} else {
T_4 * V_48 = ( T_4 * ) V_50 ;
T_5 * V_49 = ( T_5 * ) V_46 ;
V_8 = V_8 / 4 ;
while ( V_8 -- )
* V_48 ++ = F_28 ( V_49 ++ ) ;
}
#endif
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , const T_2 * V_51 ,
T_1 V_52 , T_2 V_53 )
{
struct {
T_2 V_5 ;
T_3 V_54 ;
T_2 V_53 ;
T_2 V_43 [ V_55 ] ;
} V_34 * V_7 = V_2 -> V_43 ;
unsigned V_56 ;
F_30 ( sizeof( * V_7 ) > V_57 ) ;
if ( V_52 > V_55 )
return - V_58 ;
V_7 -> V_5 = V_2 -> V_5 ;
V_7 -> V_54 = F_31 ( V_52 ) ;
V_7 -> V_53 = V_53 ;
F_22 ( V_7 -> V_43 , V_51 , V_52 , V_2 -> V_38 ) ;
V_56 = sizeof( * V_7 ) + V_52 - V_55 ;
return F_2 ( V_2 -> V_12 , V_59 , V_7 , V_56 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_2 * V_51 ,
T_1 V_52 , T_2 V_53 )
{
int V_21 ;
struct {
T_2 V_5 ;
T_3 V_54 ;
T_2 V_53 ;
} V_34 V_7 ;
struct {
T_3 V_54 ;
T_2 V_43 [ V_55 ] ;
} V_34 * V_23 = V_2 -> V_43 ;
unsigned V_24 = sizeof( * V_23 ) ;
F_30 ( sizeof( * V_23 ) > V_57 ) ;
if ( V_52 > V_55 )
return - V_58 ;
V_7 . V_5 = V_2 -> V_5 ;
V_7 . V_54 = F_31 ( V_52 ) ;
V_7 . V_53 = V_53 ;
V_21 = F_10 ( V_2 -> V_12 , V_60 , & V_7 , sizeof( V_7 ) ,
V_23 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_24 < sizeof( V_23 -> V_54 ) + V_52 )
return - V_26 ;
if ( F_11 ( V_23 -> V_54 ) != V_52 )
return - V_26 ;
F_26 ( V_51 , V_23 -> V_43 , V_52 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , const T_2 * V_61 ,
T_2 * V_62 , T_1 V_52 , T_2 V_53 )
{
int V_21 ;
struct {
T_2 V_5 ;
T_3 V_54 ;
T_2 V_53 ;
T_2 V_43 [ V_55 ] ;
} V_34 * V_7 ;
struct {
T_3 V_54 ;
T_2 V_43 [ V_55 ] ;
} V_34 * V_23 ;
unsigned V_56 , V_24 ;
F_30 ( sizeof( * V_7 ) > V_57 ||
sizeof( * V_23 ) > V_57 ) ;
if ( V_52 > V_55 )
return - V_58 ;
V_7 = V_2 -> V_43 ;
V_23 = V_2 -> V_43 ;
V_7 -> V_5 = V_2 -> V_5 ;
V_7 -> V_54 = F_31 ( V_52 ) ;
V_7 -> V_53 = V_53 ;
F_22 ( V_7 -> V_43 , V_61 , V_52 , V_2 -> V_38 ) ;
V_56 = sizeof( * V_7 ) + V_52 - V_55 ;
V_24 = sizeof( * V_23 ) ;
V_21 = F_10 ( V_2 -> V_12 , V_63 , V_7 , V_56 ,
V_23 , & V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_24 < sizeof( V_23 -> V_54 ) + V_52 )
return - V_26 ;
if ( F_11 ( V_23 -> V_54 ) != V_52 )
return - V_26 ;
F_26 ( V_62 , V_23 -> V_43 , V_52 , V_2 -> V_38 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , const T_2 * V_61 ,
T_2 * V_62 , T_1 V_52 , T_2 V_53 ) {
int V_21 ;
T_1 V_8 ;
T_2 V_64 ;
T_1 V_65 = V_52 ;
T_1 V_66 ;
do {
if ( V_65 > V_55 ) {
V_8 = V_55 ;
V_64 = V_67 ;
} else {
V_8 = V_65 ;
V_64 = V_53 ;
}
V_66 = V_52 - V_65 ;
if ( V_61 && V_62 ) {
V_21 = F_33 ( V_2 ,
V_61 + V_66 ,
V_62 + V_66 ,
V_8 , V_64 ) ;
} else if ( V_61 ) {
V_21 = F_29 ( V_2 ,
V_61 + V_66 ,
V_8 , V_64 ) ;
} else if ( V_62 ) {
V_21 = F_32 ( V_2 ,
V_62 + V_66 ,
V_8 , V_64 ) ;
} else {
return - V_58 ;
}
if ( V_21 < 0 )
return V_21 ;
V_65 -= V_8 ;
} while ( V_65 );
return 0 ;
}
static int F_35 ( struct V_68 * V_18 ,
struct V_69 * V_70 )
{
int V_21 ;
struct V_1 * V_2 = F_36 ( V_18 ) ;
struct V_71 * V_72 = V_70 -> V_72 ;
if ( V_2 -> V_14 != V_72 -> V_73 ) {
V_21 = F_4 ( V_2 , V_72 -> V_73 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_14 = V_72 -> V_73 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_4 V_29 ,
T_2 V_38 , T_2 V_36 )
{
int V_21 ;
bool V_74 ;
V_74 = V_2 -> V_29 != V_29 || V_2 -> V_36 != V_36 ||
V_2 -> V_38 != V_38 ;
if ( ! V_74 )
return 0 ;
V_21 = F_1 ( V_2 , false ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_2 -> V_29 != V_29 ) {
V_21 = F_16 ( V_2 , V_29 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_29 = V_29 ;
}
if ( V_2 -> V_36 != V_36 ) {
V_21 = F_18 ( V_2 , V_36 & 0x3 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_36 = V_36 ;
}
if ( V_2 -> V_38 != V_38 ) {
V_21 = F_19 ( V_2 , V_38 ) ;
if ( V_21 < 0 )
return V_21 ;
V_2 -> V_38 = V_38 ;
}
return F_1 ( V_2 , true ) ;
}
static int F_38 ( struct V_68 * V_18 ,
struct V_71 * V_72 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_36 ( V_18 ) ;
int V_77 ;
T_2 V_53 = 0 ;
V_77 = F_37 ( V_2 , V_76 -> V_78 ,
V_76 -> V_79 ,
V_72 -> V_36 ) ;
if ( V_77 < 0 ) {
F_39 ( & V_2 -> V_12 -> V_27 , L_4 ) ;
return V_77 ;
}
if ( ! V_76 -> V_80 && ! F_40 ( V_18 , V_76 ) )
V_53 = V_67 ;
V_77 = F_34 ( V_2 , V_76 -> V_81 , V_76 -> V_82 ,
V_76 -> V_8 , V_53 ) ;
if ( V_77 < 0 )
F_39 ( & V_2 -> V_12 -> V_27 , L_5 ) ;
return V_77 ;
}
static int F_41 ( struct V_83 * V_12 )
{
struct V_68 * V_18 ;
struct V_1 * V_2 ;
struct V_84 * V_85 = F_42 ( & V_12 -> V_27 ) ;
int V_21 ;
V_18 = F_43 ( & V_12 -> V_27 , sizeof( * V_2 ) ) ;
if ( ! V_18 )
return - V_86 ;
F_44 ( V_12 , V_18 ) ;
V_2 = F_36 ( V_18 ) ;
V_2 -> V_43 = F_45 ( & V_12 -> V_27 , V_57 , V_87 ) ;
if ( ! V_2 -> V_43 ) {
V_21 = - V_86 ;
goto V_88;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_5 = V_85 -> V_5 ;
V_2 -> V_14 = 0xff ;
V_2 -> V_36 = 0xff ;
V_21 = F_1 ( V_2 , false ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_6 ) ;
goto V_88;
}
V_21 = F_9 ( V_2 , & V_18 -> V_19 ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_7 ) ;
goto V_88;
}
V_21 = F_15 ( V_2 ,
& V_18 -> V_89 ,
& V_18 -> V_90 ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_8 ) ;
goto V_88;
}
V_21 = F_20 ( V_2 ,
& V_18 -> V_91 ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_9 ) ;
goto V_88;
}
V_21 = F_7 ( V_2 , true ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_10 ) ;
goto V_88;
}
V_18 -> V_92 = - 1 ;
V_18 -> V_93 = V_94 | V_95 ;
V_18 -> V_96 = F_35 ;
V_18 -> V_97 = F_38 ;
V_18 -> V_98 = true ;
V_21 = F_1 ( V_2 , true ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_11 ) ;
goto V_88;
}
F_46 ( & V_12 -> V_27 ,
V_99 ) ;
F_47 ( & V_12 -> V_27 ) ;
F_48 ( & V_12 -> V_27 ) ;
F_49 ( & V_12 -> V_27 ) ;
V_21 = F_50 ( & V_12 -> V_27 , V_18 ) ;
if ( V_21 < 0 ) {
F_39 ( & V_12 -> V_27 , L_12 ) ;
goto V_100;
}
return V_21 ;
V_100:
F_51 ( & V_12 -> V_27 ) ;
F_52 ( & V_12 -> V_27 ) ;
if ( F_1 ( V_2 , false ) < 0 )
F_39 ( & V_12 -> V_27 , L_6 ) ;
V_88:
F_53 ( V_18 ) ;
return V_21 ;
}
static int F_54 ( struct V_83 * V_12 )
{
struct V_68 * V_18 = F_55 ( F_56 ( V_12 ) ) ;
struct V_1 * V_2 = F_36 ( V_18 ) ;
F_51 ( & V_12 -> V_27 ) ;
if ( F_1 ( V_2 , false ) < 0 )
F_39 ( & V_12 -> V_27 , L_6 ) ;
return 0 ;
}
static int F_57 ( struct V_101 * V_27 )
{
int V_21 ;
struct V_68 * V_18 = F_58 ( V_27 ) ;
struct V_1 * V_2 = F_36 ( V_18 ) ;
V_21 = F_59 ( V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! F_60 ( V_27 ) ) {
V_21 = F_1 ( V_2 , false ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_2 -> V_14 = 0xff ;
V_2 -> V_29 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_36 = 0xff ;
return 0 ;
}
static int F_61 ( struct V_101 * V_27 )
{
int V_21 ;
struct V_68 * V_18 = F_58 ( V_27 ) ;
struct V_1 * V_2 = F_36 ( V_18 ) ;
if ( ! F_60 ( V_27 ) ) {
V_21 = F_7 ( V_2 , true ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_1 ( V_2 , true ) ;
if ( V_21 < 0 )
return V_21 ;
}
return F_62 ( V_18 ) ;
}
static int F_63 ( struct V_101 * V_27 )
{
struct V_68 * V_18 = F_58 ( V_27 ) ;
struct V_1 * V_2 = F_36 ( V_18 ) ;
return F_1 ( V_2 , false ) ;
}
static int F_64 ( struct V_101 * V_27 )
{
struct V_68 * V_18 = F_58 ( V_27 ) ;
struct V_1 * V_2 = F_36 ( V_18 ) ;
return F_1 ( V_2 , true ) ;
}
