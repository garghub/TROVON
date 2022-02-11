static void F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 , V_3 ) ;
if ( V_2 & V_4 ) {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_5 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 | V_5 ) ;
}
if ( V_2 & V_6 ) {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_7 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 | V_7 ) ;
}
F_4 ( 100 ) ;
if ( V_2 & V_4 ) {
F_3 ( V_1 , V_3 ,
V_2 | V_5 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_5 ) ;
}
if ( V_2 & V_6 ) {
F_3 ( V_1 , V_3 ,
V_2 | V_7 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_7 ) ;
}
}
static int F_5 ( struct V_1 * V_1 , bool V_8 )
{
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
int V_14 , V_15 ;
if ( V_8 ) {
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
struct V_17 V_18 = V_13 -> V_19 [ V_15 ] ;
if ( V_18 . V_20 != - 1 ) {
V_14 = F_6 ( V_18 . V_20 , V_18 . V_21 ) ;
if ( V_14 ) {
F_7 ( V_10 ,
L_1 ,
V_18 . V_21 , V_18 . V_20 , V_14 ) ;
goto V_22;
}
if ( V_18 . V_23 ) {
F_8 ( V_18 . V_20 ,
V_18 . V_24 ) ;
} else {
F_9 ( V_18 . V_20 ) ;
F_10 ( V_18 . V_20 ,
V_18 . V_24 ) ;
}
}
}
F_11 ( L_2 ) ;
} else {
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
struct V_17 V_18 = V_13 -> V_19 [ V_15 ] ;
if ( V_18 . V_20 == - 1 )
continue;
if ( V_18 . V_23 ) {
int V_24 = V_18 . V_24 ? 0 : 1 ;
F_10 ( V_18 . V_20 , V_24 ) ;
}
F_12 ( V_18 . V_20 ) ;
} ;
F_11 ( L_3 ) ;
}
return 0 ;
V_22:
while ( V_15 -- ) {
if ( V_13 -> V_19 [ V_15 ] . V_20 != - 1 )
F_12 ( V_13 -> V_19 [ V_15 ] . V_20 ) ;
}
return V_14 ;
}
static void F_13 ( struct V_1 * V_1 , bool V_25 )
{
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
int V_15 , V_14 ;
if ( V_25 ) {
for ( V_15 = 0 ; V_15 < V_13 -> V_26 ; V_15 ++ ) {
if ( V_13 -> V_27 && V_13 -> V_27 [ V_15 ] ) {
V_14 = F_14 ( V_1 -> V_28 [ V_15 ] ,
V_13 -> V_27 [ V_15 ] ) ;
if ( V_14 )
F_15 ( V_10 ,
L_4 ,
V_13 -> V_29 [ V_15 ] , V_14 ) ;
}
V_14 = F_16 ( V_1 -> V_28 [ V_15 ] ) ;
if ( V_14 ) {
F_7 ( V_10 ,
L_5 ,
V_13 -> V_29 [ V_15 ] , V_14 ) ;
}
}
} else {
for ( V_15 = V_13 -> V_26 - 1 ; V_15 >= 0 ; V_15 -- )
F_17 ( V_1 -> V_28 [ V_15 ] ) ;
}
}
static int F_18 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
T_1 V_31 ;
int V_15 , V_14 ;
unsigned long V_32 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_33 ; V_15 ++ ) {
V_14 = F_19 ( V_1 -> V_34 [ V_15 ] ) ;
if ( V_14 ) {
F_7 ( V_10 , L_6 ,
V_13 -> V_35 [ V_15 ] , V_14 ) ;
goto V_36;
}
}
V_14 = F_20 ( V_10 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_7 , V_14 ) ;
goto V_36;
}
V_14 = F_5 ( V_1 , true ) ;
if ( V_14 ) {
F_7 ( V_10 , L_8 , V_14 ) ;
goto V_36;
}
F_21 ( V_10 ) ;
F_13 ( V_1 , true ) ;
F_22 ( V_1 , false ) ;
F_1 ( V_1 ) ;
F_22 ( V_1 , true ) ;
F_3 ( V_1 , V_37 , 0x0001001b ) ;
F_3 ( V_1 , V_38 ,
V_39 |
V_40 ) ;
F_23 ( & V_1 -> V_41 , V_32 ) ;
V_31 = F_2 ( V_1 , V_42 ) ;
V_31 |= F_24 ( 0x1fff ) ;
F_3 ( V_1 , V_42 ,
~ V_43 & V_31 ) ;
F_3 ( V_1 , V_42 ,
V_43 | V_31 ) ;
F_25 ( & V_1 -> V_41 , V_32 ) ;
return 0 ;
V_36:
return V_14 ;
}
static void F_26 ( struct V_30 * V_30 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
int V_15 , V_14 = 0 ;
F_3 ( V_1 , V_38 , 0 ) ;
F_22 ( V_1 , false ) ;
F_13 ( V_1 , false ) ;
F_27 ( V_10 ) ;
V_14 = F_5 ( V_1 , false ) ;
if ( V_14 )
F_15 ( V_10 , L_9 , V_14 ) ;
V_14 = F_28 ( V_10 ) ;
if ( V_14 )
F_15 ( V_10 , L_7 , V_14 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_33 ; V_15 ++ ) {
V_14 = F_29 ( V_1 -> V_34 [ V_15 ] ) ;
if ( V_14 )
F_15 ( V_10 , L_10 ,
V_13 -> V_35 [ V_15 ] , V_14 ) ;
}
}
static void
F_30 ( struct V_44 * V_45 )
{
struct V_30 * V_30 =
F_31 ( V_45 , struct V_30 , V_46 ) ;
struct V_47 * V_48 = & V_30 -> V_49 ;
F_32 ( V_48 -> V_10 ) ;
}
void F_33 ( struct V_47 * V_48 )
{
struct V_30 * V_30 = F_34 ( V_48 ) ;
struct V_1 * V_1 = V_30 -> V_1 ;
T_1 V_50 , V_51 ;
V_50 = F_2 ( V_1 , V_52 ) ;
V_51 = F_2 ( V_1 , V_38 ) ;
if ( ( V_51 & V_40 ) &&
( V_50 & V_53 ) ) {
bool V_54 = ! ! ( V_50 & V_55 ) ;
F_3 ( V_1 , V_38 ,
V_56 ) ;
F_11 ( L_11 , V_50 , V_51 ) ;
V_51 = V_40 ;
if ( ! V_54 )
V_51 |= V_39 ;
F_3 ( V_1 , V_38 , V_51 ) ;
F_35 ( V_1 -> V_57 , & V_30 -> V_46 ) ;
}
}
static enum V_58 F_36 ( struct V_1 * V_1 )
{
T_1 V_50 ;
F_21 ( & V_1 -> V_11 -> V_10 ) ;
F_13 ( V_1 , true ) ;
V_50 = F_2 ( V_1 , V_52 ) ;
F_13 ( V_1 , false ) ;
F_27 ( & V_1 -> V_11 -> V_10 ) ;
return ( V_50 & V_55 ) ?
V_59 : V_60 ;
}
static enum V_58 F_37 ( struct V_1 * V_1 )
{
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_17 V_61 = V_13 -> V_19 [ V_62 ] ;
return F_38 ( V_61 . V_20 ) ?
V_59 :
V_60 ;
}
static enum V_58 F_39 (
struct V_47 * V_48 , bool V_63 )
{
struct V_30 * V_30 = F_34 ( V_48 ) ;
struct V_1 * V_1 = V_30 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_17 V_61 = V_13 -> V_19 [ V_62 ] ;
enum V_58 V_64 , V_65 ;
int V_66 = 20 ;
if ( V_61 . V_20 == - 1 )
return F_36 ( V_1 ) ;
do {
V_64 = F_37 ( V_1 ) ;
V_65 = F_36 ( V_1 ) ;
if ( V_64 == V_65 )
break;
F_40 ( 10 ) ;
} while ( -- V_66 );
if ( V_64 != V_65 ) {
F_11 ( L_12 , V_65 ) ;
F_11 ( L_13 , V_64 ) ;
}
return V_64 ;
}
static void F_41 ( struct V_47 * V_48 )
{
struct V_30 * V_30 = F_34 ( V_48 ) ;
F_26 ( V_30 ) ;
F_42 ( V_48 ) ;
F_43 ( V_30 ) ;
}
static int F_44 ( struct V_47 * V_48 )
{
struct V_30 * V_30 = F_34 ( V_48 ) ;
struct V_1 * V_1 = V_30 -> V_1 ;
struct V_67 * V_67 ;
T_1 V_68 ;
int V_14 = 0 ;
V_68 = F_2 ( V_1 , V_69 ) ;
F_3 ( V_1 , V_69 , V_68 | V_70 ) ;
V_67 = F_45 ( V_48 , V_1 -> V_71 ) ;
F_3 ( V_1 , V_69 , V_68 ) ;
V_1 -> V_72 = F_46 ( V_67 ) ;
F_47 ( V_48 , V_67 ) ;
if ( V_67 ) {
V_14 = F_48 ( V_48 , V_67 ) ;
F_43 ( V_67 ) ;
}
return V_14 ;
}
static int F_49 ( struct V_47 * V_48 ,
struct V_73 * V_74 )
{
struct V_30 * V_30 = F_34 ( V_48 ) ;
struct V_1 * V_1 = V_30 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_75 * V_76 = V_48 -> V_10 -> V_77 ;
struct V_78 * V_79 = V_76 -> V_79 ;
long V_80 , V_81 ;
V_81 = 1000 * V_74 -> clock ;
V_80 = V_79 -> V_82 -> V_83 ( V_79 ,
V_81 , V_30 -> V_1 -> V_84 ) ;
if ( V_13 -> V_85 > 0 )
V_80 = F_50 ( V_1 -> V_86 [ 0 ] , V_80 ) ;
F_11 ( L_14 , V_81 , V_80 ) ;
if ( V_80 != V_81 )
return V_87 ;
return 0 ;
}
struct V_47 * F_51 ( struct V_1 * V_1 )
{
struct V_47 * V_48 = NULL ;
struct V_30 * V_30 ;
int V_14 ;
V_30 = F_52 ( sizeof( * V_30 ) , V_88 ) ;
if ( ! V_30 )
return F_53 ( - V_89 ) ;
V_30 -> V_1 = V_1 ;
F_54 ( & V_30 -> V_46 , F_30 ) ;
V_48 = & V_30 -> V_49 ;
F_55 ( V_1 -> V_10 , V_48 , & V_90 ,
V_91 ) ;
F_56 ( V_48 , & V_92 ) ;
V_48 -> V_93 = V_94 |
V_95 ;
V_48 -> V_96 = 0 ;
V_48 -> V_97 = 0 ;
V_14 = F_18 ( V_30 ) ;
if ( V_14 ) {
F_7 ( & V_1 -> V_11 -> V_10 , L_15 , V_14 ) ;
return F_53 ( V_14 ) ;
}
F_57 ( V_48 , V_1 -> V_84 ) ;
return V_48 ;
}
