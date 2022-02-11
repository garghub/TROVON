static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 , bool V_5 )
{
unsigned int V_6 = V_3 % V_7 ;
unsigned int V_8 = V_3 / V_7 ;
F_2 ( V_2 -> V_9 , V_8 * 0x100 +
( V_5 ? F_3 ( V_4 ) : F_4 ( V_4 ) ) , F_5 ( V_6 ) ) ;
}
static inline bool F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
unsigned int V_6 = V_3 % V_7 ;
unsigned int V_8 = V_3 / V_7 ;
unsigned int V_10 ;
F_7 ( V_2 -> V_9 , V_8 * 0x100 + V_4 , & V_10 ) ;
return V_10 & F_5 ( V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_3 , int V_11 )
{
unsigned int V_6 = V_3 % V_7 ;
unsigned int V_8 = V_3 / V_7 ;
F_9 ( V_2 -> V_12 , L_1 ,
'A' + V_8 , V_6 , V_11 ) ;
if ( V_2 -> V_13 >= V_14 ) {
F_1 ( V_2 , V_3 , V_15 , false ) ;
F_1 ( V_2 , V_3 , V_16 , false ) ;
F_1 ( V_2 , V_3 , V_17 , V_11 & 0x2 ) ;
F_1 ( V_2 , V_3 , V_18 , V_11 & 0x1 ) ;
} else {
F_1 ( V_2 , V_3 , V_19 , true ) ;
F_1 ( V_2 , V_3 , V_20 , V_11 & 0x2 ) ;
F_1 ( V_2 , V_3 , V_21 , V_11 > 0 ) ;
}
return 0 ;
}
static int F_10 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
struct V_26 * V_11 ;
struct V_27 * V_28 ;
unsigned int V_29 ;
V_11 = F_12 ( V_23 , V_24 ) ;
if ( ! V_11 )
return - V_30 ;
V_28 = F_13 ( V_23 , V_25 ) ;
if ( ! V_28 )
return - V_30 ;
F_9 ( V_23 -> V_12 , L_2 ,
V_11 -> V_31 , V_28 -> V_31 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_32 ; V_29 ++ ) {
int * V_33 = V_28 -> V_34 ;
F_8 ( V_2 , V_28 -> V_35 [ V_29 ] , V_33 [ V_29 ] ) ;
}
return 0 ;
}
static int F_14 ( struct V_22 * V_23 ,
struct V_36 * V_37 ,
unsigned int V_3 , bool V_38 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
unsigned int V_6 = V_3 % V_7 ;
unsigned int V_8 = V_3 / V_7 ;
F_9 ( V_23 -> V_12 , L_3 ,
'A' + V_8 , V_6 , V_38 ? L_4 : L_5 ) ;
if ( V_2 -> V_13 >= V_14 ) {
F_1 ( V_2 , V_3 , V_15 , false ) ;
F_1 ( V_2 , V_3 , V_16 , true ) ;
F_1 ( V_2 , V_3 , V_17 , V_38 ) ;
} else {
F_1 ( V_2 , V_3 , V_21 , false ) ;
F_1 ( V_2 , V_3 , V_39 , V_38 ) ;
F_1 ( V_2 , V_3 , V_19 , false ) ;
}
return 0 ;
}
static int F_15 ( struct V_22 * V_23 ,
unsigned int V_3 , unsigned long * V_40 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
enum V_41 V_42 = F_16 ( * V_40 ) ;
unsigned int V_6 = V_3 % V_7 ;
unsigned int V_8 = V_3 / V_7 ;
bool V_43 ;
if ( V_2 -> V_13 >= V_14 )
V_43 = ! F_6 ( V_2 , V_3 , V_44 ) ;
else
V_43 = ! F_6 ( V_2 , V_3 , V_45 ) ;
switch ( V_42 ) {
case V_46 :
if ( V_43 )
return - V_30 ;
break;
case V_47 :
if ( ! V_43 || ! ( V_2 -> V_48 -> V_49 [ V_8 ] & F_5 ( V_6 ) ) )
return - V_30 ;
break;
case V_50 :
if ( ! V_43 || ! ( V_2 -> V_48 -> V_51 [ V_8 ] & F_5 ( V_6 ) ) )
return - V_30 ;
break;
default:
return - V_52 ;
}
* V_40 = F_17 ( V_42 , 1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_3 , bool V_53 )
{
if ( V_2 -> V_13 >= V_14 )
F_1 ( V_2 , V_3 , V_44 , ! V_53 ) ;
else
F_1 ( V_2 , V_3 , V_45 , ! V_53 ) ;
}
static int F_19 ( struct V_22 * V_23 , unsigned int V_3 ,
unsigned long * V_54 , unsigned int V_55 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
unsigned int V_6 = V_3 % V_7 ;
unsigned int V_8 = V_3 / V_7 ;
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
switch ( F_16 ( V_54 [ V_56 ] ) ) {
case V_46 :
case V_47 :
case V_50 :
continue;
default:
return - V_52 ;
}
}
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
switch ( F_16 ( V_54 [ V_56 ] ) ) {
case V_46 :
F_9 ( V_2 -> V_12 , L_6 ,
'A' + V_8 , V_6 ) ;
F_18 ( V_2 , V_3 , false ) ;
break;
case V_47 :
if ( ! ( V_2 -> V_48 -> V_49 [ V_8 ] & F_5 ( V_6 ) ) )
return - V_30 ;
F_9 ( V_2 -> V_12 , L_7 ,
'A' + V_8 , V_6 ) ;
F_18 ( V_2 , V_3 , true ) ;
break;
case V_50 :
if ( ! ( V_2 -> V_48 -> V_51 [ V_8 ] & F_5 ( V_6 ) ) )
return - V_30 ;
F_9 ( V_2 -> V_12 , L_8 ,
'A' + V_8 , V_6 ) ;
F_18 ( V_2 , V_3 , true ) ;
break;
default:
F_20 () ;
}
}
return 0 ;
}
static int F_21 ( struct V_22 * V_23 ,
unsigned int V_25 , unsigned long * V_40 )
{
const unsigned int * V_35 ;
unsigned int V_29 , V_57 , V_58 = 0 ;
int V_59 ;
V_59 = F_22 ( V_23 , V_25 , & V_35 , & V_57 ) ;
if ( V_59 )
return V_59 ;
for ( V_29 = 0 ; V_29 < V_57 ; V_29 ++ ) {
if ( F_15 ( V_23 , V_35 [ V_29 ] , V_40 ) )
return - V_52 ;
if ( V_29 && ( V_58 != * V_40 ) )
return - V_52 ;
V_58 = * V_40 ;
}
return 0 ;
}
static int F_23 ( struct V_22 * V_23 ,
unsigned int V_25 , unsigned long * V_54 ,
unsigned int V_55 )
{
const unsigned int * V_35 ;
unsigned int V_29 , V_57 ;
int V_59 ;
V_59 = F_22 ( V_23 , V_25 , & V_35 , & V_57 ) ;
if ( V_59 )
return V_59 ;
for ( V_29 = 0 ; V_29 < V_57 ; V_29 ++ ) {
V_59 = F_19 ( V_23 ,
V_35 [ V_29 ] , V_54 , V_55 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
int F_24 ( struct V_60 * V_61 )
{
struct V_62 * V_12 = & V_61 -> V_12 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
void T_2 * V_65 ;
const struct V_66 * V_67 = F_25 ( V_61 ) ;
const struct V_68 * V_69 = F_26 (
V_70 , V_12 ) ;
const struct V_71 * V_72 ;
unsigned int V_29 ;
int V_73 ;
V_2 = F_27 ( V_12 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_65 = F_28 ( V_12 ,
F_29 ( V_61 , V_76 , 0 ) ) ;
if ( F_30 ( V_65 ) ) {
F_31 ( V_12 , L_9 ) ;
return F_32 ( V_65 ) ;
}
V_2 -> V_9 = F_33 ( V_12 , V_65 ,
& V_77 ) ;
if ( F_30 ( V_2 -> V_9 ) ) {
F_31 ( V_12 , L_10 ) ;
return F_32 ( V_2 -> V_9 ) ;
}
V_2 -> V_12 = V_12 ;
if ( V_69 )
V_2 -> V_13 = (enum V_78 ) V_69 -> V_34 ;
else
V_2 -> V_13 = (enum V_78 ) V_67 -> V_79 ;
if ( V_2 -> V_13 >= V_14 )
V_72 = & V_80 ;
else
V_72 = & V_81 ;
V_2 -> V_48 = V_72 ;
V_64 = F_27 ( & V_61 -> V_12 , sizeof( * V_64 ) , V_74 ) ;
if ( ! V_64 )
return - V_75 ;
V_64 -> V_31 = F_34 ( V_12 ) ;
V_64 -> V_82 = V_83 ;
V_64 -> V_84 = & V_85 ;
V_64 -> V_86 = & V_87 ;
V_64 -> V_88 = & V_89 ;
V_64 -> V_57 = V_72 -> V_90 * V_7 ;
V_64 -> V_35 = V_2 -> V_91 = F_27 ( & V_61 -> V_12 ,
sizeof( * V_2 -> V_91 ) * V_64 -> V_57 , V_74 ) ;
if ( ! V_2 -> V_91 )
return - V_75 ;
for ( V_29 = 0 ; V_29 < V_64 -> V_57 ; V_29 ++ ) {
V_2 -> V_91 [ V_29 ] . V_92 = V_29 ;
V_2 -> V_91 [ V_29 ] . V_31 = F_35 ( V_74 , L_11 ,
'A' + ( V_29 / V_7 ) ,
V_29 % V_7 ) ;
}
V_2 -> V_93 = F_36 ( V_12 , V_64 , V_2 ) ;
if ( F_30 ( V_2 -> V_93 ) ) {
F_31 ( V_12 , L_12 ) ;
return F_32 ( V_2 -> V_93 ) ;
}
for ( V_29 = 0 ; V_29 < V_72 -> V_94 ; V_29 ++ ) {
const struct V_27 * V_25 = & V_72 -> V_95 [ V_29 ] ;
V_73 = F_37 ( V_2 -> V_93 , V_25 -> V_31 ,
V_25 -> V_35 , V_25 -> V_32 , V_25 -> V_34 ) ;
if ( V_73 ) {
F_31 ( V_12 , L_13 ,
V_25 -> V_31 ) ;
return V_73 ;
}
}
for ( V_29 = 0 ; V_29 < V_72 -> V_96 ; V_29 ++ ) {
const struct V_26 * V_11 = & V_72 -> V_97 [ V_29 ] ;
V_73 = F_38 ( V_2 -> V_93 , V_11 -> V_31 ,
V_11 -> V_98 , V_11 -> V_99 ,
V_11 -> V_34 ) ;
if ( V_73 ) {
F_31 ( V_12 , L_14 ,
V_11 -> V_31 ) ;
return V_73 ;
}
}
F_39 ( V_12 , V_2 -> V_9 ) ;
if ( V_12 -> V_100 ) {
V_73 = F_40 ( V_12 -> V_100 , NULL , NULL , V_12 ) ;
if ( V_73 ) {
F_31 ( V_12 , L_15 ) ;
return V_73 ;
}
}
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_101 ) ;
}
