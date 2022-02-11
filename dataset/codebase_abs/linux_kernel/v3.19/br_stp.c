void F_1 ( const struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ,
V_7 [ V_2 -> V_8 ] ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_8 )
{
int V_9 ;
V_2 -> V_8 = V_8 ;
V_9 = F_4 ( V_2 -> V_5 , V_8 ) ;
if ( V_9 && V_9 != - V_10 )
F_5 ( V_2 -> V_3 , L_2 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
}
struct V_1 * F_6 ( struct V_11 * V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
F_7 (p, &br->port_list, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static int F_8 ( const struct V_1 * V_2 ,
T_1 V_12 )
{
struct V_11 * V_3 ;
struct V_1 * V_13 ;
int V_14 ;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 == V_15 ||
F_9 ( V_2 ) )
return 0 ;
if ( memcmp ( & V_3 -> V_16 , & V_2 -> V_17 , 8 ) <= 0 )
return 0 ;
if ( ! V_12 )
return 1 ;
V_13 = F_6 ( V_3 , V_12 ) ;
V_14 = memcmp ( & V_2 -> V_17 , & V_13 -> V_17 , 8 ) ;
if ( V_14 < 0 )
return 1 ;
else if ( V_14 > 0 )
return 0 ;
if ( V_2 -> V_18 + V_2 -> V_19 <
V_13 -> V_18 + V_13 -> V_19 )
return 1 ;
else if ( V_2 -> V_18 + V_2 -> V_19 >
V_13 -> V_18 + V_13 -> V_19 )
return 0 ;
V_14 = memcmp ( & V_2 -> V_20 , & V_13 -> V_20 , 8 ) ;
if ( V_14 < 0 )
return 1 ;
else if ( V_14 > 0 )
return 0 ;
if ( V_2 -> V_21 < V_13 -> V_21 )
return 1 ;
else if ( V_2 -> V_21 > V_13 -> V_21 )
return 0 ;
if ( V_2 -> V_22 < V_13 -> V_22 )
return 1 ;
return 0 ;
}
static void F_10 ( const struct V_11 * V_3 ,
struct V_1 * V_2 )
{
F_11 ( V_3 , L_3 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 , V_23 ) ;
F_1 ( V_2 ) ;
F_12 ( V_24 , V_2 ) ;
if ( V_3 -> V_25 > 0 )
F_13 ( & V_2 -> V_26 , V_27 + V_3 -> V_25 ) ;
}
static void F_14 ( struct V_11 * V_3 )
{
struct V_1 * V_2 ;
T_1 V_12 = 0 ;
F_15 (p, &br->port_list, list) {
if ( ! F_8 ( V_2 , V_12 ) )
continue;
if ( V_2 -> V_28 & V_29 )
F_10 ( V_3 , V_2 ) ;
else
V_12 = V_2 -> V_4 ;
}
V_3 -> V_12 = V_12 ;
if ( ! V_12 ) {
V_3 -> V_17 = V_3 -> V_16 ;
V_3 -> V_30 = 0 ;
} else {
V_2 = F_6 ( V_3 , V_12 ) ;
V_3 -> V_17 = V_2 -> V_17 ;
V_3 -> V_30 = V_2 -> V_18 + V_2 -> V_19 ;
}
}
void F_16 ( struct V_11 * V_3 )
{
V_3 -> V_31 = V_3 -> V_32 ;
V_3 -> V_33 = V_3 -> V_34 ;
V_3 -> V_25 = V_3 -> V_35 ;
F_17 ( V_3 ) ;
F_18 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_5 -> V_28 & V_37 ) {
F_19 ( V_3 ) ;
F_13 ( & V_3 -> V_38 , V_27 + V_3 -> V_33 ) ;
}
}
void F_20 ( struct V_1 * V_2 )
{
struct V_39 V_40 ;
struct V_11 * V_3 ;
if ( F_21 ( & V_2 -> V_41 ) ) {
V_2 -> V_42 = 1 ;
return;
}
V_3 = V_2 -> V_3 ;
V_40 . V_43 = V_3 -> V_43 ;
V_40 . V_44 = V_2 -> V_44 ;
V_40 . V_45 = V_3 -> V_17 ;
V_40 . V_30 = V_3 -> V_30 ;
V_40 . V_16 = V_3 -> V_16 ;
V_40 . V_22 = V_2 -> V_22 ;
if ( F_22 ( V_3 ) )
V_40 . V_46 = 0 ;
else {
struct V_1 * V_45
= F_6 ( V_3 , V_3 -> V_12 ) ;
V_40 . V_46 = ( V_27 - V_45 -> V_47 )
+ V_48 ;
}
V_40 . V_31 = V_3 -> V_31 ;
V_40 . V_33 = V_3 -> V_33 ;
V_40 . V_25 = V_3 -> V_25 ;
if ( V_40 . V_46 < V_3 -> V_31 ) {
F_23 ( V_2 , & V_40 ) ;
V_2 -> V_44 = 0 ;
V_2 -> V_42 = 0 ;
F_13 ( & V_2 -> V_41 ,
F_24 ( V_27 + V_49 ) ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
V_2 -> V_17 = V_40 -> V_45 ;
V_2 -> V_18 = V_40 -> V_30 ;
V_2 -> V_20 = V_40 -> V_16 ;
V_2 -> V_21 = V_40 -> V_22 ;
V_2 -> V_47 = V_27 - V_40 -> V_46 ;
F_13 ( & V_2 -> V_50 , V_27
+ ( V_40 -> V_31 - V_40 -> V_46 ) ) ;
}
static void F_26 ( struct V_11 * V_3 ,
const struct V_39 * V_40 )
{
V_3 -> V_31 = V_40 -> V_31 ;
V_3 -> V_33 = V_40 -> V_33 ;
V_3 -> V_25 = V_40 -> V_25 ;
V_3 -> V_43 = V_40 -> V_43 ;
}
void F_27 ( struct V_11 * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_3 , V_3 -> V_12 ) ;
if ( V_2 )
F_28 ( V_2 ) ;
else
F_11 ( V_3 , L_4 ,
V_3 -> V_12 ) ;
}
static int F_29 ( const struct V_1 * V_2 )
{
struct V_11 * V_3 ;
int V_14 ;
V_3 = V_2 -> V_3 ;
if ( F_9 ( V_2 ) )
return 1 ;
if ( memcmp ( & V_2 -> V_17 , & V_3 -> V_17 , 8 ) )
return 1 ;
if ( V_3 -> V_30 < V_2 -> V_18 )
return 1 ;
else if ( V_3 -> V_30 > V_2 -> V_18 )
return 0 ;
V_14 = memcmp ( & V_3 -> V_16 , & V_2 -> V_20 , 8 ) ;
if ( V_14 < 0 )
return 1 ;
else if ( V_14 > 0 )
return 0 ;
if ( V_2 -> V_22 < V_2 -> V_21 )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_11 * V_3 )
{
struct V_1 * V_2 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_15 &&
F_29 ( V_2 ) )
F_31 ( V_2 ) ;
}
}
static int F_32 ( const struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
int V_14 ;
V_14 = memcmp ( & V_40 -> V_45 , & V_2 -> V_17 , 8 ) ;
if ( V_14 < 0 )
return 1 ;
else if ( V_14 > 0 )
return 0 ;
if ( V_40 -> V_30 < V_2 -> V_18 )
return 1 ;
else if ( V_40 -> V_30 > V_2 -> V_18 )
return 0 ;
V_14 = memcmp ( & V_40 -> V_16 , & V_2 -> V_20 , 8 ) ;
if ( V_14 < 0 )
return 1 ;
else if ( V_14 > 0 )
return 0 ;
if ( memcmp ( & V_40 -> V_16 , & V_2 -> V_3 -> V_16 , 8 ) )
return 1 ;
if ( V_40 -> V_22 <= V_2 -> V_21 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_11 * V_3 )
{
V_3 -> V_51 = 0 ;
F_18 ( & V_3 -> V_36 ) ;
}
void F_17 ( struct V_11 * V_3 )
{
int V_52 = F_22 ( V_3 ) ;
if ( V_3 -> V_53 != V_54 )
return;
F_2 ( V_3 , L_5 ,
V_52 ? L_6 : L_7 ) ;
if ( V_52 ) {
V_3 -> V_43 = 1 ;
F_13 ( & V_3 -> V_55 , V_27
+ V_3 -> V_35 + V_3 -> V_32 ) ;
} else if ( ! V_3 -> V_51 ) {
F_27 ( V_3 ) ;
F_13 ( & V_3 -> V_36 , V_27 + V_3 -> V_34 ) ;
}
V_3 -> V_51 = 1 ;
}
void F_19 ( struct V_11 * V_3 )
{
struct V_1 * V_2 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_15 &&
F_9 ( V_2 ) )
F_20 ( V_2 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
void F_35 ( struct V_11 * V_3 )
{
F_14 ( V_3 ) ;
F_30 ( V_3 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_11 * V_3 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_17 = V_3 -> V_17 ;
V_2 -> V_18 = V_3 -> V_30 ;
V_2 -> V_20 = V_3 -> V_16 ;
V_2 -> V_21 = V_2 -> V_22 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_15 &&
V_2 -> V_8 != V_56 ) {
if ( V_2 -> V_8 == V_57 ||
V_2 -> V_8 == V_58 )
F_17 ( V_2 -> V_3 ) ;
F_3 ( V_2 , V_56 ) ;
F_1 ( V_2 ) ;
F_12 ( V_24 , V_2 ) ;
F_18 ( & V_2 -> V_26 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 != V_56 )
return;
if ( V_3 -> V_53 == V_59 || V_3 -> V_25 == 0 ) {
F_3 ( V_2 , V_57 ) ;
F_17 ( V_3 ) ;
F_18 ( & V_2 -> V_26 ) ;
} else if ( V_3 -> V_53 == V_54 )
F_3 ( V_2 , V_23 ) ;
else
F_3 ( V_2 , V_58 ) ;
F_38 ( V_2 ) ;
F_1 ( V_2 ) ;
F_12 ( V_24 , V_2 ) ;
if ( V_3 -> V_25 != 0 )
F_13 ( & V_2 -> V_26 , V_27 + V_3 -> V_25 ) ;
}
void F_39 ( struct V_11 * V_3 )
{
struct V_1 * V_2 ;
unsigned int V_60 = 0 ;
F_15 (p, &br->port_list, list) {
if ( V_2 -> V_8 == V_15 )
continue;
if ( V_3 -> V_53 != V_61 ) {
if ( V_2 -> V_4 == V_3 -> V_12 ) {
V_2 -> V_42 = 0 ;
V_2 -> V_44 = 0 ;
F_37 ( V_2 ) ;
} else if ( F_9 ( V_2 ) ) {
F_18 ( & V_2 -> V_50 ) ;
F_37 ( V_2 ) ;
} else {
V_2 -> V_42 = 0 ;
V_2 -> V_44 = 0 ;
F_36 ( V_2 ) ;
}
}
if ( V_2 -> V_8 == V_57 )
++ V_60 ;
}
if ( V_60 == 0 )
F_40 ( V_3 -> V_5 ) ;
else
F_41 ( V_3 -> V_5 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_44 = 1 ;
F_20 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
struct V_11 * V_3 ;
int V_62 ;
V_3 = V_2 -> V_3 ;
V_62 = F_22 ( V_3 ) ;
if ( F_32 ( V_2 , V_40 ) ) {
F_25 ( V_2 , V_40 ) ;
F_35 ( V_3 ) ;
F_39 ( V_3 ) ;
if ( ! F_22 ( V_3 ) && V_62 ) {
F_18 ( & V_3 -> V_38 ) ;
if ( V_3 -> V_51 ) {
F_18 ( & V_3 -> V_55 ) ;
F_27 ( V_3 ) ;
F_13 ( & V_3 -> V_36 ,
V_27 + V_3 -> V_34 ) ;
}
}
if ( V_2 -> V_4 == V_3 -> V_12 ) {
F_26 ( V_3 , V_40 ) ;
F_19 ( V_3 ) ;
if ( V_40 -> V_44 )
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
int F_45 ( struct V_11 * V_3 , unsigned long V_63 )
{
unsigned long V_14 = F_46 ( V_63 ) ;
if ( V_14 < V_64 || V_14 > V_65 )
return - V_66 ;
F_47 ( & V_3 -> V_67 ) ;
V_3 -> V_34 = V_14 ;
if ( F_22 ( V_3 ) )
V_3 -> V_33 = V_3 -> V_34 ;
F_48 ( & V_3 -> V_67 ) ;
return 0 ;
}
int F_49 ( struct V_11 * V_3 , unsigned long V_63 )
{
unsigned long V_14 = F_46 ( V_63 ) ;
if ( V_14 < V_68 || V_14 > V_69 )
return - V_66 ;
F_47 ( & V_3 -> V_67 ) ;
V_3 -> V_32 = V_14 ;
if ( F_22 ( V_3 ) )
V_3 -> V_31 = V_3 -> V_32 ;
F_48 ( & V_3 -> V_67 ) ;
return 0 ;
}
void F_50 ( struct V_11 * V_3 , unsigned long V_14 )
{
V_3 -> V_35 = V_14 ;
if ( F_22 ( V_3 ) )
V_3 -> V_25 = V_3 -> V_35 ;
}
int F_51 ( struct V_11 * V_3 , unsigned long V_63 )
{
unsigned long V_14 = F_46 ( V_63 ) ;
int V_9 = - V_66 ;
F_47 ( & V_3 -> V_67 ) ;
if ( V_3 -> V_53 != V_59 &&
( V_14 < V_70 || V_14 > V_71 ) )
goto V_72;
F_50 ( V_3 , V_14 ) ;
V_9 = 0 ;
V_72:
F_48 ( & V_3 -> V_67 ) ;
return V_9 ;
}
