static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 * 4 ) ) ;
}
static T_1 F_3 ( const struct V_5 * V_6 , int V_3 )
{
return F_2 ( V_6 -> V_7 + ( V_3 * 4 ) ) ;
}
static void F_4 ( const struct V_5 * V_6 ,
int V_3 , T_1 V_8 )
{
F_5 ( V_8 , V_6 -> V_7 + ( V_3 * 4 ) ) ;
}
static void F_6 ( const struct V_5 * V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_6 -> V_6 ;
F_7 ( V_9 | V_10 ,
V_2 -> V_11 + V_12 ) ;
}
static T_1 F_8 ( const struct V_5 * V_6 , int V_3 )
{
return F_2 ( V_6 -> V_7 + V_3 ) ;
}
static void F_9 ( const struct V_5 * V_6 ,
int V_3 , T_1 V_8 )
{
F_5 ( V_8 , V_6 -> V_7 + V_3 ) ;
}
static void F_10 ( const struct V_5 * V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_6 -> V_6 ;
F_7 ( V_13 , V_2 -> V_11 + V_14 ) ;
}
static inline int F_11 ( const struct V_5 * V_6 )
{
unsigned char V_15 ;
V_6 -> V_16 ( V_6 , V_17 , 1 ) ;
V_6 -> V_16 ( V_6 , V_18 , V_19 ) ;
V_15 = V_6 -> V_20 ( V_6 , V_18 ) ;
if ( V_15 == V_19 )
return 1 ;
return 0 ;
}
static void F_12 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_23 * V_24 ;
int V_25 = 0 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_26 ; V_25 ++ ) {
V_24 = V_2 -> V_27 [ V_25 ] ;
if ( ! V_24 )
continue;
F_14 ( & V_22 -> V_24 , L_1 , V_24 -> V_28 ) ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
}
if ( V_2 -> V_4 != NULL )
F_17 ( V_2 -> V_21 , V_2 -> V_4 ) ;
if ( V_2 -> V_11 != NULL )
F_17 ( V_2 -> V_21 , V_2 -> V_11 ) ;
F_18 ( V_2 ) ;
F_19 ( V_22 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_5 ( 0 , V_2 -> V_4 ) ;
}
static int F_21 ( struct V_21 * V_22 ,
const struct V_29 * V_30 )
{
struct V_5 * V_6 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
int V_31 , V_32 , V_33 ;
int V_34 , V_25 ;
if ( F_22 ( V_22 ) < 0 ) {
F_23 ( & V_22 -> V_24 , L_2 ) ;
return - V_35 ;
}
V_2 = F_24 ( sizeof( struct V_1 ) , V_36 ) ;
if ( V_2 == NULL ) {
F_19 ( V_22 ) ;
return - V_37 ;
}
F_25 ( V_22 , V_2 ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_26 = 0 ;
if ( V_22 -> V_38 == V_39 ) {
V_2 -> V_40 = 2 ;
V_31 = V_41 ;
V_33 = V_42 ;
V_32 = V_43 ;
} else {
V_2 -> V_40 = 1 ;
V_31 = V_44 ;
V_33 = V_45 ;
V_32 = V_46 ;
}
V_2 -> V_11 = F_26 ( V_22 , 0 , V_32 ) ;
if ( V_2 -> V_11 == NULL ) {
V_34 = - V_37 ;
goto V_47;
}
V_2 -> V_4 = F_26 ( V_22 , V_33 , V_48 ) ;
if ( V_2 -> V_4 == NULL ) {
V_34 = - V_37 ;
goto V_47;
}
if ( V_2 -> V_40 == 1 ) {
F_7 ( V_49 , V_2 -> V_11 + V_50 ) ;
if ( F_1 ( V_2 , 0 ) != 0x55 ||
F_1 ( V_2 , 1 ) != 0xAA ||
F_1 ( V_2 , 2 ) != 0x01 ||
F_1 ( V_2 , 3 ) != 0xCB ||
F_1 ( V_2 , 4 ) != 0x11 ) {
F_23 ( & V_22 -> V_24 ,
L_3 ) ;
V_34 = - V_35 ;
goto V_47;
}
}
F_20 ( V_2 ) ;
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ ) {
V_24 = F_27 ( 0 ) ;
if ( V_24 == NULL ) {
V_34 = - V_37 ;
goto V_47;
}
V_2 -> V_27 [ V_25 ] = V_24 ;
V_6 = F_28 ( V_24 ) ;
V_6 -> V_6 = V_2 ;
V_6 -> V_51 = V_52 ;
V_24 -> V_53 = V_22 -> V_53 ;
V_6 -> V_7 = V_2 -> V_4 + V_54
+ ( V_25 * V_55 ) ;
if ( V_2 -> V_40 == 1 ) {
V_6 -> V_20 = F_3 ;
V_6 -> V_16 = F_4 ;
V_6 -> V_56 = F_6 ;
} else {
V_6 -> V_20 = F_8 ;
V_6 -> V_16 = F_9 ;
V_6 -> V_56 = F_10 ;
}
if ( F_11 ( V_6 ) ) {
V_6 -> V_57 . clock . V_58 = V_59 ;
V_6 -> V_60 = V_61 ;
V_6 -> V_62 = V_63 ;
F_29 ( V_24 , & V_22 -> V_24 ) ;
V_24 -> V_64 = V_25 ;
if ( V_2 -> V_40 == 1 )
F_7 ( V_9 | V_10 ,
V_2 -> V_11 + V_12 ) ;
else
F_7 ( V_13 ,
V_2 -> V_11 + V_14 ) ;
V_34 = F_30 ( V_24 ) ;
if ( V_34 ) {
F_23 ( & V_22 -> V_24 , L_4
L_5 , V_34 ) ;
F_16 ( V_24 ) ;
goto V_47;
}
V_2 -> V_26 ++ ;
F_14 ( & V_22 -> V_24 , L_6 ,
V_25 + 1 , V_6 -> V_7 , V_24 -> V_53 ) ;
} else {
F_16 ( V_24 ) ;
}
}
return 0 ;
V_47:
F_23 ( & V_22 -> V_24 , L_7 , V_34 ) ;
F_12 ( V_22 ) ;
return V_34 ;
}
