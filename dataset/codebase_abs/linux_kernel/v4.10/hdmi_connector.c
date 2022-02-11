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
static int F_13 ( struct V_25 * V_25 )
{
struct V_1 * V_1 = V_25 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
T_1 V_26 ;
int V_15 , V_14 ;
unsigned long V_27 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_28 ; V_15 ++ ) {
V_14 = F_14 ( V_1 -> V_29 [ V_15 ] ) ;
if ( V_14 ) {
F_7 ( V_10 , L_4 ,
V_13 -> V_30 [ V_15 ] , V_14 ) ;
goto V_31;
}
}
V_14 = F_15 ( V_10 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_5 , V_14 ) ;
goto V_31;
}
V_14 = F_5 ( V_1 , true ) ;
if ( V_14 ) {
F_7 ( V_10 , L_6 , V_14 ) ;
goto V_31;
}
for ( V_15 = 0 ; V_15 < V_13 -> V_32 ; V_15 ++ ) {
if ( V_13 -> V_33 && V_13 -> V_33 [ V_15 ] ) {
V_14 = F_16 ( V_1 -> V_34 [ V_15 ] ,
V_13 -> V_33 [ V_15 ] ) ;
if ( V_14 )
F_17 ( V_10 , L_7 ,
V_13 -> V_35 [ V_15 ] , V_14 ) ;
}
V_14 = F_18 ( V_1 -> V_34 [ V_15 ] ) ;
if ( V_14 ) {
F_7 ( V_10 , L_8 ,
V_13 -> V_35 [ V_15 ] , V_14 ) ;
goto V_31;
}
}
F_19 ( V_1 , false ) ;
F_1 ( V_1 ) ;
F_19 ( V_1 , true ) ;
F_3 ( V_1 , V_36 , 0x0001001b ) ;
F_3 ( V_1 , V_37 ,
V_38 |
V_39 ) ;
F_20 ( & V_1 -> V_40 , V_27 ) ;
V_26 = F_2 ( V_1 , V_41 ) ;
V_26 |= F_21 ( 0x1fff ) ;
F_3 ( V_1 , V_41 ,
~ V_42 & V_26 ) ;
F_3 ( V_1 , V_41 ,
V_42 | V_26 ) ;
F_22 ( & V_1 -> V_40 , V_27 ) ;
return 0 ;
V_31:
return V_14 ;
}
static void F_23 ( struct V_25 * V_25 )
{
struct V_1 * V_1 = V_25 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
int V_15 , V_14 = 0 ;
F_3 ( V_1 , V_37 , 0 ) ;
F_19 ( V_1 , false ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_32 ; V_15 ++ )
F_24 ( V_1 -> V_34 [ V_15 ] ) ;
V_14 = F_5 ( V_1 , false ) ;
if ( V_14 )
F_17 ( V_10 , L_9 , V_14 ) ;
V_14 = F_25 ( V_10 ) ;
if ( V_14 )
F_17 ( V_10 , L_5 , V_14 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_28 ; V_15 ++ ) {
V_14 = F_26 ( V_1 -> V_29 [ V_15 ] ) ;
if ( V_14 )
F_17 ( V_10 , L_10 ,
V_13 -> V_30 [ V_15 ] , V_14 ) ;
}
}
static void
F_27 ( struct V_43 * V_44 )
{
struct V_25 * V_25 =
F_28 ( V_44 , struct V_25 , V_45 ) ;
struct V_46 * V_47 = & V_25 -> V_48 ;
F_29 ( V_47 -> V_10 ) ;
}
void F_30 ( struct V_46 * V_47 )
{
struct V_25 * V_25 = F_31 ( V_47 ) ;
struct V_1 * V_1 = V_25 -> V_1 ;
T_1 V_49 , V_50 ;
V_49 = F_2 ( V_1 , V_51 ) ;
V_50 = F_2 ( V_1 , V_37 ) ;
if ( ( V_50 & V_39 ) &&
( V_49 & V_52 ) ) {
bool V_53 = ! ! ( V_49 & V_54 ) ;
F_3 ( V_1 , V_37 ,
V_55 ) ;
F_11 ( L_11 , V_49 , V_50 ) ;
V_50 = V_39 ;
if ( ! V_53 )
V_50 |= V_38 ;
F_3 ( V_1 , V_37 , V_50 ) ;
F_32 ( V_1 -> V_56 , & V_25 -> V_45 ) ;
}
}
static enum V_57 F_33 ( struct V_1 * V_1 )
{
T_1 V_49 = F_2 ( V_1 , V_51 ) ;
return ( V_49 & V_54 ) ?
V_58 : V_59 ;
}
static enum V_57 F_34 ( struct V_1 * V_1 )
{
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_17 V_60 = V_13 -> V_19 [ V_61 ] ;
return F_35 ( V_60 . V_20 ) ?
V_58 :
V_59 ;
}
static enum V_57 F_36 (
struct V_46 * V_47 , bool V_62 )
{
struct V_25 * V_25 = F_31 ( V_47 ) ;
struct V_1 * V_1 = V_25 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_17 V_60 = V_13 -> V_19 [ V_61 ] ;
enum V_57 V_63 , V_64 ;
int V_65 = 20 ;
if ( V_60 . V_20 == - 1 )
return F_33 ( V_1 ) ;
do {
V_63 = F_34 ( V_1 ) ;
V_64 = F_33 ( V_1 ) ;
if ( V_63 == V_64 )
break;
F_37 ( 10 ) ;
} while ( -- V_65 );
if ( V_63 != V_64 ) {
F_11 ( L_12 , V_64 ) ;
F_11 ( L_13 , V_63 ) ;
}
return V_63 ;
}
static void F_38 ( struct V_46 * V_47 )
{
struct V_25 * V_25 = F_31 ( V_47 ) ;
F_23 ( V_25 ) ;
F_39 ( V_47 ) ;
F_40 ( V_25 ) ;
}
static int F_41 ( struct V_46 * V_47 )
{
struct V_25 * V_25 = F_31 ( V_47 ) ;
struct V_1 * V_1 = V_25 -> V_1 ;
struct V_66 * V_66 ;
T_1 V_67 ;
int V_14 = 0 ;
V_67 = F_2 ( V_1 , V_68 ) ;
F_3 ( V_1 , V_68 , V_67 | V_69 ) ;
V_66 = F_42 ( V_47 , V_1 -> V_70 ) ;
F_3 ( V_1 , V_68 , V_67 ) ;
V_1 -> V_71 = F_43 ( V_66 ) ;
F_44 ( V_47 , V_66 ) ;
if ( V_66 ) {
V_14 = F_45 ( V_47 , V_66 ) ;
F_40 ( V_66 ) ;
}
return V_14 ;
}
static int F_46 ( struct V_46 * V_47 ,
struct V_72 * V_73 )
{
struct V_25 * V_25 = F_31 ( V_47 ) ;
struct V_1 * V_1 = V_25 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_74 * V_75 = V_47 -> V_10 -> V_76 ;
struct V_77 * V_78 = V_75 -> V_78 ;
long V_79 , V_80 ;
V_80 = 1000 * V_73 -> clock ;
V_79 = V_78 -> V_81 -> V_82 ( V_78 ,
V_80 , V_25 -> V_1 -> V_83 ) ;
if ( V_13 -> V_84 > 0 )
V_79 = F_47 ( V_1 -> V_85 [ 0 ] , V_79 ) ;
F_11 ( L_14 , V_80 , V_79 ) ;
if ( V_79 != V_80 )
return V_86 ;
return 0 ;
}
struct V_46 * F_48 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = NULL ;
struct V_25 * V_25 ;
int V_14 ;
V_25 = F_49 ( sizeof( * V_25 ) , V_87 ) ;
if ( ! V_25 )
return F_50 ( - V_88 ) ;
V_25 -> V_1 = V_1 ;
F_51 ( & V_25 -> V_45 , F_27 ) ;
V_47 = & V_25 -> V_48 ;
F_52 ( V_1 -> V_10 , V_47 , & V_89 ,
V_90 ) ;
F_53 ( V_47 , & V_91 ) ;
V_47 -> V_92 = V_93 |
V_94 ;
V_47 -> V_95 = 0 ;
V_47 -> V_96 = 0 ;
V_14 = F_13 ( V_25 ) ;
if ( V_14 ) {
F_7 ( & V_1 -> V_11 -> V_10 , L_15 , V_14 ) ;
return F_50 ( V_14 ) ;
}
F_54 ( V_47 , V_1 -> V_83 ) ;
return V_47 ;
}
