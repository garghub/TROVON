void F_1 ( const struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ,
V_7 [ V_2 -> V_8 ] ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_8 )
{
struct V_9 V_10 = {
. V_11 = V_12 ,
. V_13 = V_14 ,
. V_15 . V_16 = V_8 ,
} ;
int V_17 ;
V_2 -> V_8 = V_8 ;
V_17 = F_4 ( V_2 -> V_5 , & V_10 ) ;
if ( V_17 && V_17 != - V_18 )
F_5 ( V_2 -> V_3 , L_2 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
}
struct V_1 * F_6 ( struct V_19 * V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
F_7 (p, &br->port_list, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static int F_8 ( const struct V_1 * V_2 ,
T_1 V_20 )
{
struct V_19 * V_3 ;
struct V_1 * V_21 ;
int V_22 ;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 == V_23 ||
F_9 ( V_2 ) )
return 0 ;
if ( memcmp ( & V_3 -> V_24 , & V_2 -> V_25 , 8 ) <= 0 )
return 0 ;
if ( ! V_20 )
return 1 ;
V_21 = F_6 ( V_3 , V_20 ) ;
V_22 = memcmp ( & V_2 -> V_25 , & V_21 -> V_25 , 8 ) ;
if ( V_22 < 0 )
return 1 ;
else if ( V_22 > 0 )
return 0 ;
if ( V_2 -> V_26 + V_2 -> V_27 <
V_21 -> V_26 + V_21 -> V_27 )
return 1 ;
else if ( V_2 -> V_26 + V_2 -> V_27 >
V_21 -> V_26 + V_21 -> V_27 )
return 0 ;
V_22 = memcmp ( & V_2 -> V_28 , & V_21 -> V_28 , 8 ) ;
if ( V_22 < 0 )
return 1 ;
else if ( V_22 > 0 )
return 0 ;
if ( V_2 -> V_29 < V_21 -> V_29 )
return 1 ;
else if ( V_2 -> V_29 > V_21 -> V_29 )
return 0 ;
if ( V_2 -> V_30 < V_21 -> V_30 )
return 1 ;
return 0 ;
}
static void F_10 ( const struct V_19 * V_3 ,
struct V_1 * V_2 )
{
F_11 ( V_3 , L_3 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 , V_31 ) ;
F_1 ( V_2 ) ;
F_12 ( V_32 , V_2 ) ;
if ( V_3 -> V_33 > 0 )
F_13 ( & V_2 -> V_34 , V_35 + V_3 -> V_33 ) ;
}
static void F_14 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
T_1 V_20 = 0 ;
F_15 (p, &br->port_list, list) {
if ( ! F_8 ( V_2 , V_20 ) )
continue;
if ( V_2 -> V_13 & V_36 )
F_10 ( V_3 , V_2 ) ;
else
V_20 = V_2 -> V_4 ;
}
V_3 -> V_20 = V_20 ;
if ( ! V_20 ) {
V_3 -> V_25 = V_3 -> V_24 ;
V_3 -> V_37 = 0 ;
} else {
V_2 = F_6 ( V_3 , V_20 ) ;
V_3 -> V_25 = V_2 -> V_25 ;
V_3 -> V_37 = V_2 -> V_26 + V_2 -> V_27 ;
}
}
void F_16 ( struct V_19 * V_3 )
{
V_3 -> V_38 = V_3 -> V_39 ;
V_3 -> V_40 = V_3 -> V_41 ;
V_3 -> V_33 = V_3 -> V_42 ;
F_17 ( V_3 ) ;
F_18 ( & V_3 -> V_43 ) ;
if ( V_3 -> V_5 -> V_13 & V_44 ) {
F_19 ( V_3 ) ;
F_13 ( & V_3 -> V_45 , V_35 + V_3 -> V_40 ) ;
}
}
void F_20 ( struct V_1 * V_2 )
{
struct V_46 V_47 ;
struct V_19 * V_3 ;
if ( F_21 ( & V_2 -> V_48 ) ) {
V_2 -> V_49 = 1 ;
return;
}
V_3 = V_2 -> V_3 ;
V_47 . V_50 = V_3 -> V_50 ;
V_47 . V_51 = V_2 -> V_51 ;
V_47 . V_52 = V_3 -> V_25 ;
V_47 . V_37 = V_3 -> V_37 ;
V_47 . V_24 = V_3 -> V_24 ;
V_47 . V_30 = V_2 -> V_30 ;
if ( F_22 ( V_3 ) )
V_47 . V_53 = 0 ;
else {
struct V_1 * V_52
= F_6 ( V_3 , V_3 -> V_20 ) ;
V_47 . V_53 = ( V_35 - V_52 -> V_54 )
+ V_55 ;
}
V_47 . V_38 = V_3 -> V_38 ;
V_47 . V_40 = V_3 -> V_40 ;
V_47 . V_33 = V_3 -> V_33 ;
if ( V_47 . V_53 < V_3 -> V_38 ) {
F_23 ( V_2 , & V_47 ) ;
V_2 -> V_51 = 0 ;
V_2 -> V_49 = 0 ;
if ( V_2 -> V_3 -> V_56 == V_57 )
F_13 ( & V_2 -> V_48 ,
F_24 ( V_35 + V_58 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
V_2 -> V_25 = V_47 -> V_52 ;
V_2 -> V_26 = V_47 -> V_37 ;
V_2 -> V_28 = V_47 -> V_24 ;
V_2 -> V_29 = V_47 -> V_30 ;
V_2 -> V_54 = V_35 - V_47 -> V_53 ;
F_13 ( & V_2 -> V_59 , V_35
+ ( V_47 -> V_38 - V_47 -> V_53 ) ) ;
}
static void F_26 ( struct V_19 * V_3 ,
const struct V_46 * V_47 )
{
V_3 -> V_38 = V_47 -> V_38 ;
V_3 -> V_40 = V_47 -> V_40 ;
V_3 -> V_33 = V_47 -> V_33 ;
V_3 -> V_50 = V_47 -> V_50 ;
}
void F_27 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_3 , V_3 -> V_20 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
else
F_11 ( V_3 , L_4 ,
V_3 -> V_20 ) ;
}
static int F_29 ( const struct V_1 * V_2 )
{
struct V_19 * V_3 ;
int V_22 ;
V_3 = V_2 -> V_3 ;
if ( F_9 ( V_2 ) )
return 1 ;
if ( memcmp ( & V_2 -> V_25 , & V_3 -> V_25 , 8 ) )
return 1 ;
if ( V_3 -> V_37 < V_2 -> V_26 )
return 1 ;
else if ( V_3 -> V_37 > V_2 -> V_26 )
return 0 ;
V_22 = memcmp ( & V_3 -> V_24 , & V_2 -> V_28 , 8 ) ;
if ( V_22 < 0 )
return 1 ;
else if ( V_22 > 0 )
return 0 ;
if ( V_2 -> V_30 < V_2 -> V_29 )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_23 &&
F_29 ( V_2 ) )
F_31 ( V_2 ) ;
}
}
static int F_32 ( const struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
int V_22 ;
V_22 = memcmp ( & V_47 -> V_52 , & V_2 -> V_25 , 8 ) ;
if ( V_22 < 0 )
return 1 ;
else if ( V_22 > 0 )
return 0 ;
if ( V_47 -> V_37 < V_2 -> V_26 )
return 1 ;
else if ( V_47 -> V_37 > V_2 -> V_26 )
return 0 ;
V_22 = memcmp ( & V_47 -> V_24 , & V_2 -> V_28 , 8 ) ;
if ( V_22 < 0 )
return 1 ;
else if ( V_22 > 0 )
return 0 ;
if ( memcmp ( & V_47 -> V_24 , & V_2 -> V_3 -> V_24 , 8 ) )
return 1 ;
if ( V_47 -> V_30 <= V_2 -> V_29 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_19 * V_3 )
{
V_3 -> V_60 = 0 ;
F_18 ( & V_3 -> V_43 ) ;
}
void F_17 ( struct V_19 * V_3 )
{
int V_61 = F_22 ( V_3 ) ;
if ( V_3 -> V_56 != V_57 )
return;
F_2 ( V_3 , L_5 ,
V_61 ? L_6 : L_7 ) ;
if ( V_61 ) {
V_3 -> V_50 = 1 ;
F_13 ( & V_3 -> V_62 , V_35
+ V_3 -> V_42 + V_3 -> V_39 ) ;
} else if ( ! V_3 -> V_60 ) {
F_27 ( V_3 ) ;
F_13 ( & V_3 -> V_43 , V_35 + V_3 -> V_41 ) ;
}
V_3 -> V_60 = 1 ;
}
void F_19 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_23 &&
F_9 ( V_2 ) )
F_20 ( V_2 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
void F_35 ( struct V_19 * V_3 )
{
F_14 ( V_3 ) ;
F_30 ( V_3 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_19 * V_3 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_25 = V_3 -> V_25 ;
V_2 -> V_26 = V_3 -> V_37 ;
V_2 -> V_28 = V_3 -> V_24 ;
V_2 -> V_29 = V_2 -> V_30 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_23 &&
V_2 -> V_8 != V_63 ) {
if ( V_2 -> V_8 == V_64 ||
V_2 -> V_8 == V_65 )
F_17 ( V_2 -> V_3 ) ;
F_3 ( V_2 , V_63 ) ;
F_1 ( V_2 ) ;
F_12 ( V_32 , V_2 ) ;
F_18 ( & V_2 -> V_34 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_19 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 != V_63 )
return;
if ( V_3 -> V_56 == V_66 || V_3 -> V_33 == 0 ) {
F_3 ( V_2 , V_64 ) ;
F_17 ( V_3 ) ;
F_18 ( & V_2 -> V_34 ) ;
} else if ( V_3 -> V_56 == V_57 )
F_3 ( V_2 , V_31 ) ;
else
F_3 ( V_2 , V_65 ) ;
F_1 ( V_2 ) ;
F_12 ( V_32 , V_2 ) ;
if ( V_3 -> V_33 != 0 )
F_13 ( & V_2 -> V_34 , V_35 + V_3 -> V_33 ) ;
}
void F_38 ( struct V_19 * V_3 )
{
struct V_1 * V_2 ;
unsigned int V_67 = 0 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 == V_23 )
continue;
if ( V_3 -> V_56 != V_68 ) {
if ( V_2 -> V_4 == V_3 -> V_20 ) {
V_2 -> V_49 = 0 ;
V_2 -> V_51 = 0 ;
F_37 ( V_2 ) ;
} else if ( F_9 ( V_2 ) ) {
F_18 ( & V_2 -> V_59 ) ;
F_37 ( V_2 ) ;
} else {
V_2 -> V_49 = 0 ;
V_2 -> V_51 = 0 ;
F_36 ( V_2 ) ;
}
}
if ( V_2 -> V_8 != V_63 )
F_39 ( V_2 ) ;
if ( V_2 -> V_8 == V_64 )
++ V_67 ;
}
if ( V_67 == 0 )
F_40 ( V_3 -> V_5 ) ;
else
F_41 ( V_3 -> V_5 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_51 = 1 ;
F_20 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_19 * V_3 ;
int V_69 ;
V_3 = V_2 -> V_3 ;
V_69 = F_22 ( V_3 ) ;
if ( F_32 ( V_2 , V_47 ) ) {
F_25 ( V_2 , V_47 ) ;
F_35 ( V_3 ) ;
F_38 ( V_3 ) ;
if ( ! F_22 ( V_3 ) && V_69 ) {
F_18 ( & V_3 -> V_45 ) ;
if ( V_3 -> V_60 ) {
F_18 ( & V_3 -> V_62 ) ;
F_27 ( V_3 ) ;
F_13 ( & V_3 -> V_43 ,
V_35 + V_3 -> V_41 ) ;
}
}
if ( V_2 -> V_4 == V_3 -> V_20 ) {
F_26 ( V_3 , V_47 ) ;
F_19 ( V_3 ) ;
if ( V_47 -> V_51 )
F_33 ( V_3 ) ;
}
} else if ( F_9 ( V_2 ) ) {
F_34 ( V_2 ) ;
}
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) ) {
F_2 ( V_2 -> V_3 , L_8 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_17 ( V_2 -> V_3 ) ;
F_42 ( V_2 ) ;
}
}
int F_45 ( struct V_19 * V_3 , unsigned long V_70 )
{
unsigned long V_22 = F_46 ( V_70 ) ;
if ( V_22 < V_71 || V_22 > V_72 )
return - V_73 ;
F_47 ( & V_3 -> V_74 ) ;
V_3 -> V_41 = V_22 ;
if ( F_22 ( V_3 ) )
V_3 -> V_40 = V_3 -> V_41 ;
F_48 ( & V_3 -> V_74 ) ;
return 0 ;
}
int F_49 ( struct V_19 * V_3 , unsigned long V_70 )
{
unsigned long V_22 = F_46 ( V_70 ) ;
if ( V_22 < V_75 || V_22 > V_76 )
return - V_73 ;
F_47 ( & V_3 -> V_74 ) ;
V_3 -> V_39 = V_22 ;
if ( F_22 ( V_3 ) )
V_3 -> V_38 = V_3 -> V_39 ;
F_48 ( & V_3 -> V_74 ) ;
return 0 ;
}
int F_50 ( struct V_19 * V_3 , T_2 V_77 )
{
struct V_9 V_10 = {
. V_11 = V_78 ,
. V_13 = V_79 ,
. V_15 . V_77 = V_77 ,
} ;
unsigned long V_22 = F_46 ( V_77 ) ;
int V_17 ;
if ( V_22 < V_80 || V_22 > V_81 )
return - V_73 ;
V_17 = F_4 ( V_3 -> V_5 , & V_10 ) ;
if ( V_17 )
return V_17 ;
V_3 -> V_77 = V_22 ;
F_13 ( & V_3 -> V_82 , V_35 ) ;
return 0 ;
}
void F_51 ( struct V_19 * V_3 , unsigned long V_22 )
{
V_3 -> V_42 = V_22 ;
if ( F_22 ( V_3 ) )
V_3 -> V_33 = V_3 -> V_42 ;
}
int F_52 ( struct V_19 * V_3 , unsigned long V_70 )
{
unsigned long V_22 = F_46 ( V_70 ) ;
int V_17 = - V_73 ;
F_47 ( & V_3 -> V_74 ) ;
if ( V_3 -> V_56 != V_66 &&
( V_22 < V_83 || V_22 > V_84 ) )
goto V_85;
F_51 ( V_3 , V_22 ) ;
V_17 = 0 ;
V_85:
F_48 ( & V_3 -> V_74 ) ;
return V_17 ;
}
