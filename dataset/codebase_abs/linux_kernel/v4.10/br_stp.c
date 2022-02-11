void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 V_5 = {
. V_6 = V_2 -> V_7 ,
. V_8 = V_9 ,
. V_10 = V_11 ,
. V_12 . V_13 = V_3 ,
} ;
int V_14 ;
V_2 -> V_3 = V_3 ;
V_14 = F_2 ( V_2 -> V_7 , & V_5 ) ;
if ( V_14 && V_14 != - V_15 )
F_3 ( V_2 -> V_16 , L_1 ,
( unsigned int ) V_2 -> V_17 , V_2 -> V_7 -> V_18 ) ;
else
F_4 ( V_2 -> V_16 , L_2 ,
( unsigned int ) V_2 -> V_17 , V_2 -> V_7 -> V_18 ,
V_19 [ V_2 -> V_3 ] ) ;
}
struct V_1 * F_5 ( struct V_20 * V_16 , T_1 V_17 )
{
struct V_1 * V_2 ;
F_6 (p, &br->port_list, list) {
if ( V_2 -> V_17 == V_17 )
return V_2 ;
}
return NULL ;
}
static int F_7 ( const struct V_1 * V_2 ,
T_1 V_21 )
{
struct V_20 * V_16 ;
struct V_1 * V_22 ;
int V_23 ;
V_16 = V_2 -> V_16 ;
if ( V_2 -> V_3 == V_24 ||
F_8 ( V_2 ) )
return 0 ;
if ( memcmp ( & V_16 -> V_25 , & V_2 -> V_26 , 8 ) <= 0 )
return 0 ;
if ( ! V_21 )
return 1 ;
V_22 = F_5 ( V_16 , V_21 ) ;
V_23 = memcmp ( & V_2 -> V_26 , & V_22 -> V_26 , 8 ) ;
if ( V_23 < 0 )
return 1 ;
else if ( V_23 > 0 )
return 0 ;
if ( V_2 -> V_27 + V_2 -> V_28 <
V_22 -> V_27 + V_22 -> V_28 )
return 1 ;
else if ( V_2 -> V_27 + V_2 -> V_28 >
V_22 -> V_27 + V_22 -> V_28 )
return 0 ;
V_23 = memcmp ( & V_2 -> V_29 , & V_22 -> V_29 , 8 ) ;
if ( V_23 < 0 )
return 1 ;
else if ( V_23 > 0 )
return 0 ;
if ( V_2 -> V_30 < V_22 -> V_30 )
return 1 ;
else if ( V_2 -> V_30 > V_22 -> V_30 )
return 0 ;
if ( V_2 -> V_31 < V_22 -> V_31 )
return 1 ;
return 0 ;
}
static void F_9 ( const struct V_20 * V_16 ,
struct V_1 * V_2 )
{
F_10 ( V_16 , L_3 ,
( unsigned int ) V_2 -> V_17 , V_2 -> V_7 -> V_18 ) ;
F_1 ( V_2 , V_32 ) ;
F_11 ( V_33 , V_2 ) ;
if ( V_16 -> V_34 > 0 )
F_12 ( & V_2 -> V_35 , V_36 + V_16 -> V_34 ) ;
}
static void F_13 ( struct V_20 * V_16 )
{
struct V_1 * V_2 ;
T_1 V_21 = 0 ;
F_14 (p, &br->port_list, list) {
if ( ! F_7 ( V_2 , V_21 ) )
continue;
if ( V_2 -> V_10 & V_37 )
F_9 ( V_16 , V_2 ) ;
else
V_21 = V_2 -> V_17 ;
}
V_16 -> V_21 = V_21 ;
if ( ! V_21 ) {
V_16 -> V_26 = V_16 -> V_25 ;
V_16 -> V_38 = 0 ;
} else {
V_2 = F_5 ( V_16 , V_21 ) ;
V_16 -> V_26 = V_2 -> V_26 ;
V_16 -> V_38 = V_2 -> V_27 + V_2 -> V_28 ;
}
}
void F_15 ( struct V_20 * V_16 )
{
V_16 -> V_39 = V_16 -> V_40 ;
V_16 -> V_41 = V_16 -> V_42 ;
V_16 -> V_34 = V_16 -> V_43 ;
F_16 ( V_16 ) ;
F_17 ( & V_16 -> V_44 ) ;
if ( V_16 -> V_7 -> V_10 & V_45 ) {
F_18 ( V_16 ) ;
F_12 ( & V_16 -> V_46 , V_36 + V_16 -> V_41 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
struct V_47 V_48 ;
struct V_20 * V_16 ;
if ( F_20 ( & V_2 -> V_49 ) ) {
V_2 -> V_50 = 1 ;
return;
}
V_16 = V_2 -> V_16 ;
V_48 . V_51 = V_16 -> V_51 ;
V_48 . V_52 = V_2 -> V_52 ;
V_48 . V_53 = V_16 -> V_26 ;
V_48 . V_38 = V_16 -> V_38 ;
V_48 . V_25 = V_16 -> V_25 ;
V_48 . V_31 = V_2 -> V_31 ;
if ( F_21 ( V_16 ) )
V_48 . V_54 = 0 ;
else {
struct V_1 * V_53
= F_5 ( V_16 , V_16 -> V_21 ) ;
V_48 . V_54 = ( V_36 - V_53 -> V_55 )
+ V_56 ;
}
V_48 . V_39 = V_16 -> V_39 ;
V_48 . V_41 = V_16 -> V_41 ;
V_48 . V_34 = V_16 -> V_34 ;
if ( V_48 . V_54 < V_16 -> V_39 ) {
F_22 ( V_2 , & V_48 ) ;
V_2 -> V_52 = 0 ;
V_2 -> V_50 = 0 ;
if ( V_2 -> V_16 -> V_57 == V_58 )
F_12 ( & V_2 -> V_49 ,
F_23 ( V_36 + V_59 ) ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
V_2 -> V_26 = V_48 -> V_53 ;
V_2 -> V_27 = V_48 -> V_38 ;
V_2 -> V_29 = V_48 -> V_25 ;
V_2 -> V_30 = V_48 -> V_31 ;
V_2 -> V_55 = V_36 - V_48 -> V_54 ;
F_12 ( & V_2 -> V_60 , V_36
+ ( V_48 -> V_39 - V_48 -> V_54 ) ) ;
}
static void F_25 ( struct V_20 * V_16 ,
const struct V_47 * V_48 )
{
V_16 -> V_39 = V_48 -> V_39 ;
V_16 -> V_41 = V_48 -> V_41 ;
V_16 -> V_34 = V_48 -> V_34 ;
F_26 ( V_16 , V_48 -> V_51 ) ;
}
void F_27 ( struct V_20 * V_16 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_16 , V_16 -> V_21 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
else
F_10 ( V_16 , L_4 ,
V_16 -> V_21 ) ;
}
static int F_29 ( const struct V_1 * V_2 )
{
struct V_20 * V_16 ;
int V_23 ;
V_16 = V_2 -> V_16 ;
if ( F_8 ( V_2 ) )
return 1 ;
if ( memcmp ( & V_2 -> V_26 , & V_16 -> V_26 , 8 ) )
return 1 ;
if ( V_16 -> V_38 < V_2 -> V_27 )
return 1 ;
else if ( V_16 -> V_38 > V_2 -> V_27 )
return 0 ;
V_23 = memcmp ( & V_16 -> V_25 , & V_2 -> V_29 , 8 ) ;
if ( V_23 < 0 )
return 1 ;
else if ( V_23 > 0 )
return 0 ;
if ( V_2 -> V_31 < V_2 -> V_30 )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_20 * V_16 )
{
struct V_1 * V_2 ;
F_14 (p, &br->port_list, list) {
if ( V_2 -> V_3 != V_24 &&
F_29 ( V_2 ) )
F_31 ( V_2 ) ;
}
}
static int F_32 ( const struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
int V_23 ;
V_23 = memcmp ( & V_48 -> V_53 , & V_2 -> V_26 , 8 ) ;
if ( V_23 < 0 )
return 1 ;
else if ( V_23 > 0 )
return 0 ;
if ( V_48 -> V_38 < V_2 -> V_27 )
return 1 ;
else if ( V_48 -> V_38 > V_2 -> V_27 )
return 0 ;
V_23 = memcmp ( & V_48 -> V_25 , & V_2 -> V_29 , 8 ) ;
if ( V_23 < 0 )
return 1 ;
else if ( V_23 > 0 )
return 0 ;
if ( memcmp ( & V_48 -> V_25 , & V_2 -> V_16 -> V_25 , 8 ) )
return 1 ;
if ( V_48 -> V_31 <= V_2 -> V_30 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_20 * V_16 )
{
V_16 -> V_61 = 0 ;
F_17 ( & V_16 -> V_44 ) ;
}
void F_16 ( struct V_20 * V_16 )
{
int V_62 = F_21 ( V_16 ) ;
if ( V_16 -> V_57 != V_58 )
return;
F_4 ( V_16 , L_5 ,
V_62 ? L_6 : L_7 ) ;
if ( V_62 ) {
F_26 ( V_16 , 1 ) ;
F_12 ( & V_16 -> V_63 , V_36
+ V_16 -> V_43 + V_16 -> V_40 ) ;
} else if ( ! V_16 -> V_61 ) {
F_27 ( V_16 ) ;
F_12 ( & V_16 -> V_44 , V_36 + V_16 -> V_42 ) ;
}
V_16 -> V_61 = 1 ;
}
void F_18 ( struct V_20 * V_16 )
{
struct V_1 * V_2 ;
F_14 (p, &br->port_list, list) {
if ( V_2 -> V_3 != V_24 &&
F_8 ( V_2 ) )
F_19 ( V_2 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
void F_35 ( struct V_20 * V_16 )
{
F_13 ( V_16 ) ;
F_30 ( V_16 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_20 * V_16 ;
V_16 = V_2 -> V_16 ;
V_2 -> V_26 = V_16 -> V_26 ;
V_2 -> V_27 = V_16 -> V_38 ;
V_2 -> V_29 = V_16 -> V_25 ;
V_2 -> V_30 = V_2 -> V_31 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_24 &&
V_2 -> V_3 != V_64 ) {
if ( V_2 -> V_3 == V_65 ||
V_2 -> V_3 == V_66 )
F_16 ( V_2 -> V_16 ) ;
F_1 ( V_2 , V_64 ) ;
F_11 ( V_33 , V_2 ) ;
F_17 ( & V_2 -> V_35 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_20 * V_16 = V_2 -> V_16 ;
if ( V_2 -> V_3 != V_64 )
return;
if ( V_16 -> V_57 == V_67 || V_16 -> V_34 == 0 ) {
F_1 ( V_2 , V_65 ) ;
F_16 ( V_16 ) ;
F_17 ( & V_2 -> V_35 ) ;
} else if ( V_16 -> V_57 == V_58 )
F_1 ( V_2 , V_32 ) ;
else
F_1 ( V_2 , V_66 ) ;
F_11 ( V_33 , V_2 ) ;
if ( V_16 -> V_34 != 0 )
F_12 ( & V_2 -> V_35 , V_36 + V_16 -> V_34 ) ;
}
void F_38 ( struct V_20 * V_16 )
{
struct V_1 * V_2 ;
unsigned int V_68 = 0 ;
F_14 (p, &br->port_list, list) {
if ( V_2 -> V_3 == V_24 )
continue;
if ( V_16 -> V_57 != V_69 ) {
if ( V_2 -> V_17 == V_16 -> V_21 ) {
V_2 -> V_50 = 0 ;
V_2 -> V_52 = 0 ;
F_37 ( V_2 ) ;
} else if ( F_8 ( V_2 ) ) {
F_17 ( & V_2 -> V_60 ) ;
F_37 ( V_2 ) ;
} else {
V_2 -> V_50 = 0 ;
V_2 -> V_52 = 0 ;
F_36 ( V_2 ) ;
}
}
if ( V_2 -> V_3 != V_64 )
F_39 ( V_2 ) ;
if ( V_2 -> V_3 == V_65 )
++ V_68 ;
}
if ( V_68 == 0 )
F_40 ( V_16 -> V_7 ) ;
else
F_41 ( V_16 -> V_7 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_52 = 1 ;
F_19 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
struct V_20 * V_16 ;
int V_70 ;
V_16 = V_2 -> V_16 ;
V_70 = F_21 ( V_16 ) ;
if ( F_32 ( V_2 , V_48 ) ) {
F_24 ( V_2 , V_48 ) ;
F_35 ( V_16 ) ;
F_38 ( V_16 ) ;
if ( ! F_21 ( V_16 ) && V_70 ) {
F_17 ( & V_16 -> V_46 ) ;
if ( V_16 -> V_61 ) {
F_17 ( & V_16 -> V_63 ) ;
F_27 ( V_16 ) ;
F_12 ( & V_16 -> V_44 ,
V_36 + V_16 -> V_42 ) ;
}
}
if ( V_2 -> V_17 == V_16 -> V_21 ) {
F_25 ( V_16 , V_48 ) ;
F_18 ( V_16 ) ;
if ( V_48 -> V_52 )
F_33 ( V_16 ) ;
}
} else if ( F_8 ( V_2 ) ) {
F_34 ( V_2 ) ;
}
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_4 ( V_2 -> V_16 , L_8 ,
( unsigned int ) V_2 -> V_17 , V_2 -> V_7 -> V_18 ) ;
F_16 ( V_2 -> V_16 ) ;
F_42 ( V_2 ) ;
}
}
int F_45 ( struct V_20 * V_16 , unsigned long V_71 )
{
unsigned long V_23 = F_46 ( V_71 ) ;
if ( V_23 < V_72 || V_23 > V_73 )
return - V_74 ;
F_47 ( & V_16 -> V_75 ) ;
V_16 -> V_42 = V_23 ;
if ( F_21 ( V_16 ) )
V_16 -> V_41 = V_16 -> V_42 ;
F_48 ( & V_16 -> V_75 ) ;
return 0 ;
}
int F_49 ( struct V_20 * V_16 , unsigned long V_71 )
{
unsigned long V_23 = F_46 ( V_71 ) ;
if ( V_23 < V_76 || V_23 > V_77 )
return - V_74 ;
F_47 ( & V_16 -> V_75 ) ;
V_16 -> V_40 = V_23 ;
if ( F_21 ( V_16 ) )
V_16 -> V_39 = V_16 -> V_40 ;
F_48 ( & V_16 -> V_75 ) ;
return 0 ;
}
int F_50 ( struct V_78 * V_7 , unsigned long V_23 )
{
struct V_4 V_5 = {
. V_6 = V_7 ,
. V_8 = V_79 ,
. V_10 = V_80 | V_11 ,
. V_12 . V_81 = F_51 ( V_23 ) ,
} ;
int V_14 ;
V_14 = F_2 ( V_7 , & V_5 ) ;
if ( V_14 && V_14 != - V_15 )
return V_14 ;
return 0 ;
}
int F_52 ( struct V_20 * V_16 , T_2 V_81 )
{
unsigned long V_23 = F_46 ( V_81 ) ;
int V_14 ;
V_14 = F_50 ( V_16 -> V_7 , V_23 ) ;
if ( V_14 )
return V_14 ;
F_47 ( & V_16 -> V_75 ) ;
V_16 -> V_82 = V_23 ;
V_16 -> V_81 = V_23 ;
F_48 ( & V_16 -> V_75 ) ;
F_12 ( & V_16 -> V_83 , V_36 ) ;
return 0 ;
}
void F_26 ( struct V_20 * V_16 , unsigned char V_71 )
{
unsigned long V_23 ;
int V_14 ;
if ( V_16 -> V_57 == V_58 && V_16 -> V_51 != V_71 ) {
if ( V_71 ) {
V_23 = 2 * V_16 -> V_34 ;
F_53 ( V_16 , L_9 , V_23 ) ;
} else {
V_23 = V_16 -> V_82 ;
F_53 ( V_16 , L_10 , V_23 ) ;
}
V_14 = F_50 ( V_16 -> V_7 , V_23 ) ;
if ( V_14 )
F_3 ( V_16 , L_11 ) ;
else
V_16 -> V_81 = V_23 ;
}
V_16 -> V_51 = V_71 ;
}
void F_54 ( struct V_20 * V_16 , unsigned long V_23 )
{
V_16 -> V_43 = V_23 ;
if ( F_21 ( V_16 ) )
V_16 -> V_34 = V_16 -> V_43 ;
}
int F_55 ( struct V_20 * V_16 , unsigned long V_71 )
{
unsigned long V_23 = F_46 ( V_71 ) ;
int V_14 = - V_74 ;
F_47 ( & V_16 -> V_75 ) ;
if ( V_16 -> V_57 != V_67 &&
( V_23 < V_84 || V_23 > V_85 ) )
goto V_86;
F_54 ( V_16 , V_23 ) ;
V_14 = 0 ;
V_86:
F_48 ( & V_16 -> V_75 ) ;
return V_14 ;
}
