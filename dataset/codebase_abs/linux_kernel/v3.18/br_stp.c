void F_1 ( const struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ,
V_7 [ V_2 -> V_8 ] ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_8 )
{
V_2 -> V_8 = V_8 ;
}
struct V_1 * F_4 ( struct V_9 * V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
F_5 (p, &br->port_list, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static int F_6 ( const struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_9 * V_3 ;
struct V_1 * V_11 ;
int V_12 ;
V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 == V_13 ||
F_7 ( V_2 ) )
return 0 ;
if ( memcmp ( & V_3 -> V_14 , & V_2 -> V_15 , 8 ) <= 0 )
return 0 ;
if ( ! V_10 )
return 1 ;
V_11 = F_4 ( V_3 , V_10 ) ;
V_12 = memcmp ( & V_2 -> V_15 , & V_11 -> V_15 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_2 -> V_16 + V_2 -> V_17 <
V_11 -> V_16 + V_11 -> V_17 )
return 1 ;
else if ( V_2 -> V_16 + V_2 -> V_17 >
V_11 -> V_16 + V_11 -> V_17 )
return 0 ;
V_12 = memcmp ( & V_2 -> V_18 , & V_11 -> V_18 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_2 -> V_19 < V_11 -> V_19 )
return 1 ;
else if ( V_2 -> V_19 > V_11 -> V_19 )
return 0 ;
if ( V_2 -> V_20 < V_11 -> V_20 )
return 1 ;
return 0 ;
}
static void F_8 ( const struct V_9 * V_3 ,
struct V_1 * V_2 )
{
F_9 ( V_3 , L_2 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 , V_21 ) ;
F_1 ( V_2 ) ;
F_10 ( V_22 , V_2 ) ;
if ( V_3 -> V_23 > 0 )
F_11 ( & V_2 -> V_24 , V_25 + V_3 -> V_23 ) ;
}
static void F_12 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
T_1 V_10 = 0 ;
F_13 (p, &br->port_list, list) {
if ( ! F_6 ( V_2 , V_10 ) )
continue;
if ( V_2 -> V_26 & V_27 )
F_8 ( V_3 , V_2 ) ;
else
V_10 = V_2 -> V_4 ;
}
V_3 -> V_10 = V_10 ;
if ( ! V_10 ) {
V_3 -> V_15 = V_3 -> V_14 ;
V_3 -> V_28 = 0 ;
} else {
V_2 = F_4 ( V_3 , V_10 ) ;
V_3 -> V_15 = V_2 -> V_15 ;
V_3 -> V_28 = V_2 -> V_16 + V_2 -> V_17 ;
}
}
void F_14 ( struct V_9 * V_3 )
{
V_3 -> V_29 = V_3 -> V_30 ;
V_3 -> V_31 = V_3 -> V_32 ;
V_3 -> V_23 = V_3 -> V_33 ;
F_15 ( V_3 ) ;
F_16 ( & V_3 -> V_34 ) ;
if ( V_3 -> V_5 -> V_26 & V_35 ) {
F_17 ( V_3 ) ;
F_11 ( & V_3 -> V_36 , V_25 + V_3 -> V_31 ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_37 V_38 ;
struct V_9 * V_3 ;
if ( F_19 ( & V_2 -> V_39 ) ) {
V_2 -> V_40 = 1 ;
return;
}
V_3 = V_2 -> V_3 ;
V_38 . V_41 = V_3 -> V_41 ;
V_38 . V_42 = V_2 -> V_42 ;
V_38 . V_43 = V_3 -> V_15 ;
V_38 . V_28 = V_3 -> V_28 ;
V_38 . V_14 = V_3 -> V_14 ;
V_38 . V_20 = V_2 -> V_20 ;
if ( F_20 ( V_3 ) )
V_38 . V_44 = 0 ;
else {
struct V_1 * V_43
= F_4 ( V_3 , V_3 -> V_10 ) ;
V_38 . V_44 = ( V_25 - V_43 -> V_45 )
+ V_46 ;
}
V_38 . V_29 = V_3 -> V_29 ;
V_38 . V_31 = V_3 -> V_31 ;
V_38 . V_23 = V_3 -> V_23 ;
if ( V_38 . V_44 < V_3 -> V_29 ) {
F_21 ( V_2 , & V_38 ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_40 = 0 ;
F_11 ( & V_2 -> V_39 ,
F_22 ( V_25 + V_47 ) ) ;
}
}
static void F_23 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
V_2 -> V_15 = V_38 -> V_43 ;
V_2 -> V_16 = V_38 -> V_28 ;
V_2 -> V_18 = V_38 -> V_14 ;
V_2 -> V_19 = V_38 -> V_20 ;
V_2 -> V_45 = V_25 - V_38 -> V_44 ;
F_11 ( & V_2 -> V_48 , V_25
+ ( V_38 -> V_29 - V_38 -> V_44 ) ) ;
}
static void F_24 ( struct V_9 * V_3 ,
const struct V_37 * V_38 )
{
V_3 -> V_29 = V_38 -> V_29 ;
V_3 -> V_31 = V_38 -> V_31 ;
V_3 -> V_23 = V_38 -> V_23 ;
V_3 -> V_41 = V_38 -> V_41 ;
}
void F_25 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_3 , V_3 -> V_10 ) ;
if ( V_2 )
F_26 ( V_2 ) ;
else
F_9 ( V_3 , L_3 ,
V_3 -> V_10 ) ;
}
static int F_27 ( const struct V_1 * V_2 )
{
struct V_9 * V_3 ;
int V_12 ;
V_3 = V_2 -> V_3 ;
if ( F_7 ( V_2 ) )
return 1 ;
if ( memcmp ( & V_2 -> V_15 , & V_3 -> V_15 , 8 ) )
return 1 ;
if ( V_3 -> V_28 < V_2 -> V_16 )
return 1 ;
else if ( V_3 -> V_28 > V_2 -> V_16 )
return 0 ;
V_12 = memcmp ( & V_3 -> V_14 , & V_2 -> V_18 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_2 -> V_20 < V_2 -> V_19 )
return 1 ;
return 0 ;
}
static void F_28 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
F_13 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_13 &&
F_27 ( V_2 ) )
F_29 ( V_2 ) ;
}
}
static int F_30 ( const struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
int V_12 ;
V_12 = memcmp ( & V_38 -> V_43 , & V_2 -> V_15 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( V_38 -> V_28 < V_2 -> V_16 )
return 1 ;
else if ( V_38 -> V_28 > V_2 -> V_16 )
return 0 ;
V_12 = memcmp ( & V_38 -> V_14 , & V_2 -> V_18 , 8 ) ;
if ( V_12 < 0 )
return 1 ;
else if ( V_12 > 0 )
return 0 ;
if ( memcmp ( & V_38 -> V_14 , & V_2 -> V_3 -> V_14 , 8 ) )
return 1 ;
if ( V_38 -> V_20 <= V_2 -> V_19 )
return 1 ;
return 0 ;
}
static void F_31 ( struct V_9 * V_3 )
{
V_3 -> V_49 = 0 ;
F_16 ( & V_3 -> V_34 ) ;
}
void F_15 ( struct V_9 * V_3 )
{
int V_50 = F_20 ( V_3 ) ;
if ( V_3 -> V_51 != V_52 )
return;
F_2 ( V_3 , L_4 ,
V_50 ? L_5 : L_6 ) ;
if ( V_50 ) {
V_3 -> V_41 = 1 ;
F_11 ( & V_3 -> V_53 , V_25
+ V_3 -> V_33 + V_3 -> V_30 ) ;
} else if ( ! V_3 -> V_49 ) {
F_25 ( V_3 ) ;
F_11 ( & V_3 -> V_34 , V_25 + V_3 -> V_32 ) ;
}
V_3 -> V_49 = 1 ;
}
void F_17 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
F_13 (p, &br->port_list, list) {
if ( V_2 -> V_8 != V_13 &&
F_7 ( V_2 ) )
F_18 ( V_2 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
}
void F_33 ( struct V_9 * V_3 )
{
F_12 ( V_3 ) ;
F_28 ( V_3 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_9 * V_3 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_15 = V_3 -> V_15 ;
V_2 -> V_16 = V_3 -> V_28 ;
V_2 -> V_18 = V_3 -> V_14 ;
V_2 -> V_19 = V_2 -> V_20 ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_13 &&
V_2 -> V_8 != V_54 ) {
if ( V_2 -> V_8 == V_55 ||
V_2 -> V_8 == V_56 )
F_15 ( V_2 -> V_3 ) ;
F_3 ( V_2 , V_54 ) ;
F_1 ( V_2 ) ;
F_10 ( V_22 , V_2 ) ;
F_16 ( & V_2 -> V_24 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_8 != V_54 )
return;
if ( V_3 -> V_51 == V_57 || V_3 -> V_23 == 0 ) {
F_3 ( V_2 , V_55 ) ;
F_15 ( V_3 ) ;
F_16 ( & V_2 -> V_24 ) ;
} else if ( V_3 -> V_51 == V_52 )
F_3 ( V_2 , V_21 ) ;
else
F_3 ( V_2 , V_56 ) ;
F_36 ( V_2 ) ;
F_1 ( V_2 ) ;
F_10 ( V_22 , V_2 ) ;
if ( V_3 -> V_23 != 0 )
F_11 ( & V_2 -> V_24 , V_25 + V_3 -> V_23 ) ;
}
void F_37 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
unsigned int V_58 = 0 ;
F_13 (p, &br->port_list, list) {
if ( V_2 -> V_8 == V_13 )
continue;
if ( V_3 -> V_51 != V_59 ) {
if ( V_2 -> V_4 == V_3 -> V_10 ) {
V_2 -> V_40 = 0 ;
V_2 -> V_42 = 0 ;
F_35 ( V_2 ) ;
} else if ( F_7 ( V_2 ) ) {
F_16 ( & V_2 -> V_48 ) ;
F_35 ( V_2 ) ;
} else {
V_2 -> V_40 = 0 ;
V_2 -> V_42 = 0 ;
F_34 ( V_2 ) ;
}
}
if ( V_2 -> V_8 == V_55 )
++ V_58 ;
}
if ( V_58 == 0 )
F_38 ( V_3 -> V_5 ) ;
else
F_39 ( V_3 -> V_5 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_42 = 1 ;
F_18 ( V_2 ) ;
}
void F_41 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
struct V_9 * V_3 ;
int V_60 ;
V_3 = V_2 -> V_3 ;
V_60 = F_20 ( V_3 ) ;
if ( F_30 ( V_2 , V_38 ) ) {
F_23 ( V_2 , V_38 ) ;
F_33 ( V_3 ) ;
F_37 ( V_3 ) ;
if ( ! F_20 ( V_3 ) && V_60 ) {
F_16 ( & V_3 -> V_36 ) ;
if ( V_3 -> V_49 ) {
F_16 ( & V_3 -> V_53 ) ;
F_25 ( V_3 ) ;
F_11 ( & V_3 -> V_34 ,
V_25 + V_3 -> V_32 ) ;
}
}
if ( V_2 -> V_4 == V_3 -> V_10 ) {
F_24 ( V_3 , V_38 ) ;
F_17 ( V_3 ) ;
if ( V_38 -> V_42 )
F_31 ( V_3 ) ;
}
} else if ( F_7 ( V_2 ) ) {
F_32 ( V_2 ) ;
}
}
void F_42 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_2 ( V_2 -> V_3 , L_7 ,
( unsigned int ) V_2 -> V_4 , V_2 -> V_5 -> V_6 ) ;
F_15 ( V_2 -> V_3 ) ;
F_40 ( V_2 ) ;
}
}
int F_43 ( struct V_9 * V_3 , unsigned long V_61 )
{
unsigned long V_12 = F_44 ( V_61 ) ;
if ( V_12 < V_62 || V_12 > V_63 )
return - V_64 ;
F_45 ( & V_3 -> V_65 ) ;
V_3 -> V_32 = V_12 ;
if ( F_20 ( V_3 ) )
V_3 -> V_31 = V_3 -> V_32 ;
F_46 ( & V_3 -> V_65 ) ;
return 0 ;
}
int F_47 ( struct V_9 * V_3 , unsigned long V_61 )
{
unsigned long V_12 = F_44 ( V_61 ) ;
if ( V_12 < V_66 || V_12 > V_67 )
return - V_64 ;
F_45 ( & V_3 -> V_65 ) ;
V_3 -> V_30 = V_12 ;
if ( F_20 ( V_3 ) )
V_3 -> V_29 = V_3 -> V_30 ;
F_46 ( & V_3 -> V_65 ) ;
return 0 ;
}
void F_48 ( struct V_9 * V_3 , unsigned long V_12 )
{
V_3 -> V_33 = V_12 ;
if ( F_20 ( V_3 ) )
V_3 -> V_23 = V_3 -> V_33 ;
}
int F_49 ( struct V_9 * V_3 , unsigned long V_61 )
{
unsigned long V_12 = F_44 ( V_61 ) ;
int V_68 = - V_64 ;
F_45 ( & V_3 -> V_65 ) ;
if ( V_3 -> V_51 != V_57 &&
( V_12 < V_69 || V_12 > V_70 ) )
goto V_71;
F_48 ( V_3 , V_12 ) ;
V_68 = 0 ;
V_71:
F_46 ( & V_3 -> V_65 ) ;
return V_68 ;
}
