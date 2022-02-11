static int F_1 ( struct V_1 * V_2 ,
struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = F_2 ( V_11 , V_4 , V_5 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = F_4 ( V_11 , V_4 , V_5 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned short V_17 ,
char V_18 , T_2 V_19 ,
int V_20 , union V_21 * V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = V_11 -> V_23 -> V_24 ( V_11 , V_16 , V_17 ,
V_18 , V_19 , V_20 , V_22 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_16 , unsigned short V_17 ,
char V_18 , T_2 V_19 ,
int V_20 , union V_21 * V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_11 ;
int V_12 ;
V_12 = V_10 -> V_13 ( V_10 , V_7 -> V_14 ) ;
if ( V_12 >= 0 )
V_12 = F_7 ( V_11 , V_16 , V_17 ,
V_18 , V_19 , V_20 , V_22 ) ;
if ( V_10 -> V_15 )
V_10 -> V_15 ( V_10 , V_7 -> V_14 ) ;
return V_12 ;
}
static T_3 F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
return V_11 -> V_23 -> V_25 ( V_11 ) ;
}
static unsigned int F_9 ( struct V_1 * V_11 )
{
unsigned int V_26 = 0 ;
do {
V_26 |= V_11 -> V_26 ;
V_11 = F_10 ( V_11 ) ;
} while ( V_11 );
return V_26 ;
}
static void F_11 ( struct V_1 * V_27 , unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
F_12 ( & V_11 -> V_28 ) ;
if ( ! ( V_17 & V_29 ) )
return;
F_13 ( V_11 , V_17 ) ;
}
static int F_14 ( struct V_1 * V_27 , unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
if ( ! F_15 ( & V_11 -> V_28 ) )
return 0 ;
if ( ! ( V_17 & V_29 ) )
return 1 ;
if ( F_16 ( V_11 , V_17 ) )
return 1 ;
F_17 ( & V_11 -> V_28 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_27 , unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
if ( V_17 & V_29 )
F_19 ( V_11 , V_17 ) ;
F_17 ( & V_11 -> V_28 ) ;
}
static void F_20 ( struct V_1 * V_27 ,
unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
F_12 ( & V_11 -> V_28 ) ;
F_13 ( V_11 , V_17 ) ;
}
static int F_21 ( struct V_1 * V_27 ,
unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
if ( ! F_15 ( & V_11 -> V_28 ) )
return 0 ;
if ( F_16 ( V_11 , V_17 ) )
return 1 ;
F_17 ( & V_11 -> V_28 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_27 ,
unsigned int V_17 )
{
struct V_6 * V_7 = V_27 -> V_8 ;
struct V_1 * V_11 = V_7 -> V_10 -> V_11 ;
F_19 ( V_11 , V_17 ) ;
F_17 ( & V_11 -> V_28 ) ;
}
struct V_1 * F_23 ( struct V_30 * V_31 )
{
struct V_30 * V_32 ;
struct V_1 * V_33 ;
for ( V_32 = V_31 ; V_32 ; V_32 = V_32 -> V_11 ) {
if ( V_32 -> type == & V_34 )
break;
}
if ( ! V_32 )
return NULL ;
V_33 = F_24 ( V_32 ) ;
while ( F_10 ( V_33 ) )
V_33 = F_10 ( V_33 ) ;
return V_33 ;
}
struct V_9 * F_25 ( struct V_1 * V_11 ,
struct V_30 * V_31 , int V_35 ,
int V_36 , T_3 V_17 ,
int (* V_13)( struct V_9 * , T_3 ) ,
int (* V_15)( struct V_9 * , T_3 ) )
{
struct V_9 * V_10 ;
V_10 = F_26 ( V_31 , sizeof( * V_10 )
+ V_35 * sizeof( V_10 -> V_27 [ 0 ] )
+ V_36 , V_37 ) ;
if ( ! V_10 )
return NULL ;
if ( V_36 )
V_10 -> V_7 = & V_10 -> V_27 [ V_35 ] ;
V_10 -> V_11 = V_11 ;
V_10 -> V_31 = V_31 ;
if ( V_17 & V_38 )
V_10 -> V_39 = true ;
if ( V_17 & V_40 )
V_10 -> V_41 = true ;
if ( V_17 & V_42 )
V_10 -> V_43 = true ;
V_10 -> V_13 = V_13 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_35 = V_35 ;
return V_10 ;
}
int F_27 ( struct V_9 * V_10 ,
T_3 V_44 , T_3 V_14 ,
unsigned int V_26 )
{
struct V_1 * V_11 = V_10 -> V_11 ;
struct V_6 * V_7 ;
char V_45 [ 20 ] ;
int V_12 ;
if ( V_10 -> V_46 >= V_10 -> V_35 ) {
F_28 ( V_10 -> V_31 , L_1 ) ;
return - V_47 ;
}
V_7 = F_29 ( sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return - V_48 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_14 = V_14 ;
if ( V_11 -> V_23 -> V_49 ) {
if ( V_10 -> V_39 )
V_7 -> V_23 . V_49 = F_3 ;
else
V_7 -> V_23 . V_49 = F_1 ;
}
if ( V_11 -> V_23 -> V_24 ) {
if ( V_10 -> V_39 )
V_7 -> V_23 . V_24 = F_6 ;
else
V_7 -> V_23 . V_24 = F_5 ;
}
V_7 -> V_23 . V_25 = F_8 ;
snprintf ( V_7 -> V_2 . V_50 , sizeof( V_7 -> V_2 . V_50 ) ,
L_2 , F_30 ( V_11 ) , V_14 ) ;
V_7 -> V_2 . V_51 = V_52 ;
V_7 -> V_2 . V_23 = & V_7 -> V_23 ;
V_7 -> V_2 . V_8 = V_7 ;
V_7 -> V_2 . V_31 . V_11 = & V_11 -> V_31 ;
V_7 -> V_2 . V_53 = V_11 -> V_53 ;
V_7 -> V_2 . V_54 = V_11 -> V_54 ;
V_7 -> V_2 . V_55 = V_11 -> V_55 ;
if ( V_10 -> V_39 )
V_7 -> V_2 . V_56 = & V_57 ;
else
V_7 -> V_2 . V_56 = & V_58 ;
if ( F_9 ( V_11 ) & V_26 )
F_28 ( & V_11 -> V_31 ,
L_3 ,
V_14 ) ;
else
V_7 -> V_2 . V_26 = V_26 ;
if ( V_10 -> V_31 -> V_59 ) {
struct V_60 * V_61 = V_10 -> V_31 -> V_59 ;
struct V_60 * V_62 , * V_63 = NULL ;
T_3 V_64 ;
if ( V_10 -> V_41 )
V_62 = F_31 ( V_61 , L_4 ) ;
else if ( V_10 -> V_43 )
V_62 = F_31 ( V_61 , L_5 ) ;
else
V_62 = F_31 ( V_61 , L_6 ) ;
if ( V_62 ) {
if ( ! F_32 ( V_62 , L_7 , & V_64 ) ) {
F_33 ( V_62 ) ;
V_62 = NULL ;
}
}
if ( ! V_62 )
V_62 = F_34 ( V_61 ) ;
else if ( V_10 -> V_41 || V_10 -> V_43 )
V_63 = F_34 ( V_62 ) ;
if ( ! V_63 ) {
F_35 (mux_node, child) {
V_12 = F_32 ( V_63 , L_7 , & V_64 ) ;
if ( V_12 )
continue;
if ( V_14 == V_64 )
break;
}
}
V_7 -> V_2 . V_31 . V_59 = V_63 ;
F_33 ( V_62 ) ;
}
if ( F_36 ( V_10 -> V_31 ) )
F_37 ( & V_7 -> V_2 . V_31 ,
F_38 ( V_10 -> V_31 ) ,
V_14 ) ;
if ( V_44 ) {
V_7 -> V_2 . V_65 = V_44 ;
V_12 = F_39 ( & V_7 -> V_2 ) ;
if ( V_12 < 0 ) {
F_28 ( & V_11 -> V_31 ,
L_8 ,
V_14 , V_44 , V_12 ) ;
goto V_66;
}
} else {
V_12 = F_40 ( & V_7 -> V_2 ) ;
if ( V_12 < 0 ) {
F_28 ( & V_11 -> V_31 ,
L_9 ,
V_14 , V_12 ) ;
goto V_66;
}
}
F_41 ( F_42 ( & V_7 -> V_2 . V_31 . V_67 , & V_10 -> V_31 -> V_67 ,
L_10 ) ,
L_11 ) ;
snprintf ( V_45 , sizeof( V_45 ) , L_12 , V_14 ) ;
F_41 ( F_42 ( & V_10 -> V_31 -> V_67 , & V_7 -> V_2 . V_31 . V_67 ,
V_45 ) ,
L_13 , V_14 ) ;
F_43 ( & V_11 -> V_31 , L_14 ,
F_30 ( & V_7 -> V_2 ) ) ;
V_10 -> V_27 [ V_10 -> V_46 ++ ] = & V_7 -> V_2 ;
return 0 ;
V_66:
F_44 ( V_7 ) ;
return V_12 ;
}
void F_45 ( struct V_9 * V_10 )
{
char V_45 [ 20 ] ;
while ( V_10 -> V_46 ) {
struct V_1 * V_2 = V_10 -> V_27 [ -- V_10 -> V_46 ] ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_60 * V_68 = V_2 -> V_31 . V_59 ;
V_10 -> V_27 [ V_10 -> V_46 ] = NULL ;
snprintf ( V_45 , sizeof( V_45 ) ,
L_12 , V_7 -> V_14 ) ;
F_46 ( & V_10 -> V_31 -> V_67 , V_45 ) ;
F_46 ( & V_7 -> V_2 . V_31 . V_67 , L_10 ) ;
F_47 ( V_2 ) ;
F_33 ( V_68 ) ;
F_44 ( V_7 ) ;
}
}
