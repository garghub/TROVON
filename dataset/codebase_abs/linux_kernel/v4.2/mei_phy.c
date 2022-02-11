static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 = NULL ;
struct F_1 * V_7 ;
T_1 V_8 ;
int V_9 , V_10 ;
F_2 ( L_1 , V_11 ) ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_12 . V_4 = V_13 ;
V_4 . V_12 . V_14 = 1 ;
V_4 . V_15 = V_16 ;
F_3 ( L_2 , & V_4 . V_12 ) ;
V_10 = F_4 ( V_2 -> V_17 , ( V_18 * ) & V_4 , sizeof( struct V_3 ) ) ;
if ( V_10 < 0 ) {
F_5 ( L_3 ) ;
return V_10 ;
}
V_8 = sizeof( struct V_5 ) +
sizeof( struct F_1 ) ;
V_6 = F_6 ( V_8 , V_19 ) ;
if ( ! V_6 )
return - V_20 ;
V_9 = F_7 ( V_2 -> V_17 , ( V_18 * ) V_6 , V_8 ) ;
if ( V_9 < 0 || V_9 < sizeof( struct V_5 ) ) {
F_5 ( L_4 ) ;
V_10 = - V_21 ;
goto V_22;
}
V_7 = (struct F_1 * ) V_6 -> V_23 ;
V_2 -> V_24 = V_7 -> V_24 ;
V_2 -> V_25 = V_7 -> V_25 ;
V_2 -> V_26 = V_7 -> V_26 ;
V_22:
F_8 ( V_6 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_6 ;
struct F_9 * V_27 ;
struct V_28 * V_29 ;
T_1 V_30 , V_31 ;
int V_9 , V_10 ;
F_2 ( L_1 , V_11 ) ;
V_30 = sizeof( struct V_3 ) +
sizeof( struct F_9 ) ;
V_31 = sizeof( struct V_3 ) +
sizeof( struct V_28 ) ;
V_4 = F_6 ( V_30 , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_27 = (struct F_9 * ) V_4 -> V_23 ;
V_6 = F_6 ( V_31 , V_19 ) ;
if ( ! V_6 ) {
F_8 ( V_4 ) ;
return - V_20 ;
}
V_29 = (struct V_28 * ) V_6 -> V_23 ;
V_4 -> V_12 . V_4 = V_13 ;
V_4 -> V_12 . V_14 = 3 ;
V_4 -> V_15 = V_32 ;
V_27 -> V_24 = V_2 -> V_24 ;
V_27 -> V_25 = V_2 -> V_25 ;
F_3 ( L_5 , & V_4 -> V_12 ) ;
V_10 = F_4 ( V_2 -> V_17 , ( V_18 * ) V_4 , V_30 ) ;
if ( V_10 < 0 ) {
F_5 ( L_6 , V_10 ) ;
goto V_22;
}
V_9 = F_7 ( V_2 -> V_17 , ( V_18 * ) V_6 , V_31 ) ;
if ( V_9 < 0 ) {
V_10 = V_9 ;
F_5 ( L_7 , V_10 ) ;
goto V_22;
}
F_3 ( L_8 , & V_6 -> V_12 ) ;
F_2 ( L_9 ,
V_29 -> V_24 , V_29 -> V_25 ) ;
F_2 ( L_10 ,
V_29 -> V_33 , V_29 -> V_34 ,
V_29 -> V_35 , V_29 -> V_36 ) ;
V_10 = 0 ;
V_22:
F_8 ( V_6 ) ;
F_8 ( V_4 ) ;
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , V_18 * V_37 , T_1 V_38 )
{
struct V_39 * V_12 ;
V_18 * V_40 ;
int V_22 ;
V_22 = - V_20 ;
V_40 = F_6 ( V_38 + V_41 , V_19 ) ;
if ( ! V_40 )
goto V_42;
V_12 = (struct V_39 * ) V_40 ;
V_12 -> V_4 = V_43 ;
V_12 -> V_44 = 0 ;
V_12 -> V_45 = V_2 -> V_45 ;
V_12 -> V_46 = 0 ;
V_12 -> V_14 = V_38 ;
F_3 ( L_11 , V_12 ) ;
memcpy ( V_40 + V_41 , V_37 , V_38 ) ;
V_22 = F_4 ( V_2 -> V_17 , V_40 , V_38 + V_41 ) ;
if ( V_22 < 0 )
goto V_42;
if ( ! F_11 ( V_2 -> V_47 ,
V_2 -> V_48 == V_2 -> V_45 , V_49 ) ) {
F_5 ( L_12 ) ;
V_22 = - V_50 ;
} else {
V_2 -> V_45 ++ ;
}
V_42:
F_8 ( V_40 ) ;
return V_22 ;
}
static int F_12 ( void * V_51 , struct V_52 * V_53 )
{
struct V_1 * V_2 = V_51 ;
int V_10 ;
F_13 ( L_13 , V_53 ) ;
V_10 = F_10 ( V_2 , V_53 -> V_23 , V_53 -> V_54 ) ;
if ( V_10 > 0 )
V_10 = 0 ;
return V_10 ;
}
static int F_14 ( struct V_1 * V_2 , V_18 * V_37 , T_1 V_38 )
{
struct V_39 * V_12 ;
int V_55 ;
V_55 = F_7 ( V_2 -> V_17 , V_37 , V_38 ) ;
if ( V_55 < 0 )
return V_55 ;
V_12 = (struct V_39 * ) V_37 ;
F_3 ( L_14 , V_12 ) ;
if ( V_12 -> V_4 == V_43 ) {
V_2 -> V_48 = V_12 -> V_45 ;
F_15 ( & V_2 -> V_47 ) ;
return 0 ;
}
return V_55 ;
}
static void F_16 ( struct V_56 * V_17 , T_2 V_57 ,
void * V_58 )
{
struct V_1 * V_2 = V_58 ;
if ( V_2 -> V_59 != 0 )
return;
if ( V_57 & F_17 ( V_60 ) ) {
struct V_52 * V_53 ;
int V_61 ;
V_53 = F_18 ( V_62 , V_19 ) ;
if ( ! V_53 )
return;
V_61 = F_14 ( V_2 , V_53 -> V_23 , V_62 ) ;
if ( V_61 < V_41 ) {
F_19 ( V_53 ) ;
return;
}
F_20 ( V_53 , V_61 ) ;
F_21 ( V_53 , V_41 ) ;
F_22 ( L_15 , V_53 ) ;
F_23 ( V_2 -> V_63 , V_53 ) ;
}
}
static int F_24 ( void * V_51 )
{
int V_10 ;
struct V_1 * V_2 = V_51 ;
F_2 ( L_1 , V_11 ) ;
if ( V_2 -> V_64 == 1 )
return 0 ;
V_10 = F_25 ( V_2 -> V_17 ) ;
if ( V_10 < 0 ) {
F_5 ( L_16 , V_10 ) ;
return V_10 ;
}
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 ) {
F_5 ( L_16 , V_10 ) ;
goto V_22;
}
V_10 = F_9 ( V_2 ) ;
if ( V_10 < 0 ) {
F_5 ( L_17 , V_10 ) ;
goto V_22;
}
V_10 = F_26 ( V_2 -> V_17 , F_16 , V_2 ) ;
if ( V_10 ) {
F_5 ( L_18 , V_10 ) ;
goto V_22;
}
V_2 -> V_64 = 1 ;
return 0 ;
V_22:
V_2 -> V_64 = 0 ;
F_27 ( V_2 -> V_17 ) ;
return V_10 ;
}
static void F_28 ( void * V_51 )
{
struct V_1 * V_2 = V_51 ;
F_2 ( L_1 , V_11 ) ;
F_27 ( V_2 -> V_17 ) ;
V_2 -> V_64 = 0 ;
}
struct V_1 * F_29 ( struct V_56 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_17 = V_17 ;
F_30 ( & V_2 -> V_47 ) ;
F_31 ( V_17 , V_2 ) ;
return V_2 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_27 ( V_2 -> V_17 ) ;
F_8 ( V_2 ) ;
}
