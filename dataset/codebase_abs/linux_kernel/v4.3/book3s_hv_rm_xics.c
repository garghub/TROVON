static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
F_2 ( & V_4 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
struct V_10 * V_11 = & V_4 -> V_12 [ V_7 ] ;
if ( ! V_11 -> V_13 )
continue;
F_3 ( & V_4 -> V_8 ) ;
F_4 ( V_2 , V_6 , V_11 -> V_14 ) ;
F_2 ( & V_4 -> V_8 ) ;
}
F_3 ( & V_4 -> V_8 ) ;
}
static void F_5 ( struct V_15 * V_16 ,
struct V_15 * V_17 )
{
struct V_5 * V_18 = V_17 -> V_19 . V_6 ;
int V_20 ;
V_16 -> V_21 . V_22 ++ ;
F_6 ( V_23 , & V_16 -> V_19 . V_24 ) ;
if ( V_16 == V_17 ) {
F_7 ( V_25 , F_8 ( V_25 ) | V_26 ) ;
return;
}
V_20 = V_16 -> V_19 . V_27 ;
if ( V_20 < 0 || V_20 >= V_28 ) {
V_18 -> V_29 |= V_30 ;
V_18 -> V_31 = V_16 ;
return;
}
F_9 () ;
F_10 ( V_20 ) ;
}
static void F_11 ( struct V_15 * V_16 )
{
F_12 ( V_23 ,
& V_16 -> V_19 . V_24 ) ;
F_7 ( V_25 , F_8 ( V_25 ) & ~ V_26 ) ;
}
static inline bool F_13 ( struct V_5 * V_6 ,
union V_32 V_33 ,
union V_32 V_34 )
{
struct V_15 * V_17 = V_35 -> V_36 . V_15 ;
bool V_37 ;
V_34 . V_38 = ( V_34 . V_39 && ( V_34 . V_40 < V_34 . V_41 ) ) ;
V_37 = F_14 ( & V_6 -> V_11 . V_42 , V_33 . V_42 , V_34 . V_42 ) == V_33 . V_42 ;
if ( ! V_37 )
goto V_43;
if ( V_34 . V_38 )
F_5 ( V_6 -> V_16 , V_17 ) ;
V_17 -> V_19 . V_6 -> V_44 = V_34 ;
V_17 -> V_19 . V_6 -> V_45 = V_6 -> V_16 ;
V_43:
return V_37 ;
}
static inline int F_15 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
return ( V_2 -> V_46 || V_6 -> V_29 ) ? V_47 : V_48 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_49 ;
F_17 () ;
F_18 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_3 * V_4 = V_2 -> V_4 [ V_49 ] ;
if ( ! F_19 ( V_49 , V_6 -> V_50 ) )
continue;
if ( ! V_4 )
continue;
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
static bool F_20 ( struct V_5 * V_6 , T_1 V_51 , T_2 V_52 ,
T_1 * V_53 )
{
union V_32 V_54 , V_55 ;
bool V_37 ;
do {
V_54 = V_55 = F_21 ( V_6 -> V_11 ) ;
* V_53 = 0 ;
V_37 = V_55 . V_41 > V_52 &&
V_55 . V_56 > V_52 &&
V_55 . V_40 > V_52 ;
if ( V_37 ) {
* V_53 = V_55 . V_39 ;
V_55 . V_39 = V_51 ;
V_55 . V_40 = V_52 ;
} else {
V_55 . V_57 = true ;
}
} while ( ! F_13 ( V_6 , V_54 , V_55 ) );
return V_37 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_58 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
T_1 V_53 ;
T_3 V_59 ;
V_60:
V_4 = F_22 ( V_2 , V_58 , & V_59 ) ;
if ( ! V_4 ) {
V_2 -> V_61 ++ ;
return;
}
V_11 = & V_4 -> V_12 [ V_59 ] ;
F_2 ( & V_4 -> V_8 ) ;
if ( ! V_6 || V_11 -> V_62 != V_6 -> V_63 ) {
V_6 = F_23 ( V_2 -> V_64 , V_11 -> V_62 ) ;
if ( ! V_6 ) {
V_2 -> V_65 ++ ;
goto V_66;
}
}
V_11 -> V_13 = 0 ;
if ( V_11 -> V_52 == V_67 ) {
V_11 -> V_68 = 1 ;
goto V_66;
}
if ( F_20 ( V_6 , V_58 , V_11 -> V_52 , & V_53 ) ) {
if ( V_53 && V_53 != V_69 ) {
F_3 ( & V_4 -> V_8 ) ;
V_58 = V_53 ;
goto V_60;
}
} else {
F_6 ( V_4 -> V_49 , V_6 -> V_50 ) ;
V_11 -> V_13 = 1 ;
F_9 () ;
if ( ! V_6 -> V_11 . V_57 ) {
F_3 ( & V_4 -> V_8 ) ;
goto V_60;
}
}
V_66:
F_3 ( & V_4 -> V_8 ) ;
}
static void F_24 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_2 V_70 )
{
union V_32 V_54 , V_55 ;
bool V_13 ;
do {
V_54 = V_55 = F_21 ( V_6 -> V_11 ) ;
V_55 . V_41 = V_70 ;
if ( V_55 . V_56 < V_70 &&
V_55 . V_56 <= V_55 . V_40 ) {
V_55 . V_40 = V_55 . V_56 ;
V_55 . V_39 = V_69 ;
}
V_13 = V_55 . V_57 ;
V_55 . V_57 = 0 ;
} while ( ! F_13 ( V_6 , V_54 , V_55 ) );
if ( V_13 ) {
V_6 -> V_71 ++ ;
F_16 ( V_2 , V_6 ) ;
}
}
unsigned long F_25 ( struct V_15 * V_16 )
{
union V_32 V_54 , V_55 ;
struct V_1 * V_2 = V_16 -> V_64 -> V_19 . V_2 ;
struct V_5 * V_6 = V_16 -> V_19 . V_6 ;
T_1 V_72 ;
if ( ! V_2 || ! V_2 -> V_73 )
return V_47 ;
F_11 ( V_6 -> V_16 ) ;
do {
V_54 = V_55 = F_21 ( V_6 -> V_11 ) ;
V_72 = V_54 . V_39 | ( ( ( T_1 ) V_54 . V_41 ) << 24 ) ;
if ( ! V_54 . V_39 )
break;
V_55 . V_41 = V_55 . V_40 ;
V_55 . V_40 = 0xff ;
V_55 . V_39 = 0 ;
} while ( ! F_13 ( V_6 , V_54 , V_55 ) );
V_16 -> V_19 . V_74 [ 4 ] = V_72 ;
return F_15 ( V_2 , V_6 ) ;
}
int F_26 ( struct V_15 * V_16 , unsigned long V_62 ,
unsigned long V_56 )
{
union V_32 V_54 , V_55 ;
struct V_1 * V_2 = V_16 -> V_64 -> V_19 . V_2 ;
struct V_5 * V_6 , * V_18 = V_16 -> V_19 . V_6 ;
T_1 V_53 ;
bool V_13 ;
bool V_75 ;
if ( ! V_2 || ! V_2 -> V_73 )
return V_47 ;
V_75 = V_18 -> V_63 == V_62 ;
if ( V_75 )
V_6 = V_18 ;
else
V_6 = F_23 ( V_16 -> V_64 , V_62 ) ;
if ( ! V_6 )
return V_76 ;
do {
V_54 = V_55 = F_21 ( V_6 -> V_11 ) ;
V_55 . V_56 = V_56 ;
V_53 = 0 ;
V_13 = false ;
if ( V_56 < V_55 . V_41 ) {
if ( V_56 <= V_55 . V_40 ) {
V_53 = V_55 . V_39 ;
V_55 . V_40 = V_56 ;
V_55 . V_39 = V_69 ;
}
}
if ( V_56 > V_54 . V_56 ) {
V_13 = V_55 . V_57 ;
V_55 . V_57 = 0 ;
}
} while ( ! F_13 ( V_6 , V_54 , V_55 ) );
if ( V_53 && V_53 != V_69 ) {
V_18 -> V_77 ++ ;
F_4 ( V_2 , V_6 , V_53 ) ;
}
if ( V_13 ) {
V_18 -> V_71 ++ ;
F_16 ( V_2 , V_6 ) ;
}
return F_15 ( V_2 , V_18 ) ;
}
int F_27 ( struct V_15 * V_16 , unsigned long V_41 )
{
union V_32 V_54 , V_55 ;
struct V_1 * V_2 = V_16 -> V_64 -> V_19 . V_2 ;
struct V_5 * V_6 = V_16 -> V_19 . V_6 ;
T_1 V_53 ;
if ( ! V_2 || ! V_2 -> V_73 )
return V_47 ;
if ( V_41 > V_6 -> V_11 . V_41 ) {
F_24 ( V_2 , V_6 , V_41 ) ;
goto V_43;
} else if ( V_41 == V_6 -> V_11 . V_41 )
return V_48 ;
F_11 ( V_6 -> V_16 ) ;
do {
V_54 = V_55 = F_21 ( V_6 -> V_11 ) ;
V_53 = 0 ;
V_55 . V_41 = V_41 ;
if ( V_41 <= V_55 . V_40 ) {
V_53 = V_55 . V_39 ;
V_55 . V_39 = 0 ;
V_55 . V_40 = 0xff ;
}
} while ( ! F_13 ( V_6 , V_54 , V_55 ) );
if ( V_53 && V_53 != V_69 ) {
V_6 -> V_77 ++ ;
F_4 ( V_2 , V_6 , V_53 ) ;
}
V_43:
return F_15 ( V_2 , V_6 ) ;
}
int F_28 ( struct V_15 * V_16 , unsigned long V_72 )
{
struct V_1 * V_2 = V_16 -> V_64 -> V_19 . V_2 ;
struct V_5 * V_6 = V_16 -> V_19 . V_6 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
T_1 V_51 = V_72 & 0x00ffffff ;
T_3 V_59 ;
if ( ! V_2 || ! V_2 -> V_73 )
return V_47 ;
F_24 ( V_2 , V_6 , V_72 >> 24 ) ;
if ( V_51 == V_69 )
goto V_43;
V_4 = F_22 ( V_2 , V_51 , & V_59 ) ;
if ( ! V_4 )
goto V_43;
V_11 = & V_4 -> V_12 [ V_59 ] ;
if ( V_11 -> V_78 ) {
V_6 -> V_77 ++ ;
F_4 ( V_2 , V_6 , V_51 ) ;
}
if ( ! F_29 ( & V_16 -> V_64 -> V_79 ) ) {
V_6 -> V_29 |= V_80 ;
V_6 -> V_81 = V_51 ;
}
V_43:
return F_15 ( V_2 , V_6 ) ;
}
