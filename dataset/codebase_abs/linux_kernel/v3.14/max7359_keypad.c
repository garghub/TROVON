static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 ,
V_7 , V_3 , V_4 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_2 ,
V_7 , V_3 , V_5 ) ;
return V_5 ;
}
static void F_6 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_12 * V_12 = V_9 -> V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_11 -> V_14 ; V_13 ++ ) {
unsigned int V_15 = V_11 -> V_16 [ V_13 ] ;
unsigned int V_17 = F_7 ( V_15 ) ;
unsigned int V_18 = F_8 ( V_15 ) ;
unsigned int V_19 = F_9 ( V_17 , V_18 ,
V_20 ) ;
unsigned short V_21 = F_10 ( V_15 ) ;
V_9 -> V_22 [ V_19 ] = V_21 ;
F_11 ( V_21 , V_12 -> V_23 ) ;
}
F_12 ( V_24 , V_12 -> V_23 ) ;
}
static T_2 F_13 ( int V_25 , void * V_26 )
{
struct V_8 * V_9 = V_26 ;
struct V_12 * V_12 = V_9 -> V_12 ;
int V_4 , V_17 , V_18 , V_27 , V_28 ;
V_4 = F_4 ( V_9 -> V_2 , V_29 ) ;
V_17 = V_4 & 0x7 ;
V_18 = ( V_4 >> 3 ) & 0x7 ;
V_27 = V_4 & 0x40 ;
V_28 = F_9 ( V_17 , V_18 , V_20 ) ;
F_14 ( & V_9 -> V_2 -> V_6 ,
L_3 , V_17 , V_18 , V_27 ? L_4 : L_5 ) ;
F_15 ( V_12 , V_30 , V_31 , V_28 ) ;
F_16 ( V_12 , V_9 -> V_22 [ V_28 ] , ! V_27 ) ;
F_17 ( V_12 ) ;
return V_32 ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_33 , V_34 ) ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_33 , V_35 ) ;
}
static int F_20 ( struct V_12 * V_6 )
{
struct V_8 * V_9 = F_21 ( V_6 ) ;
F_19 ( V_9 -> V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_12 * V_6 )
{
struct V_8 * V_9 = F_21 ( V_6 ) ;
F_18 ( V_9 -> V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_36 ,
V_37 |
V_38 |
V_39 ) ;
F_1 ( V_2 , V_40 , 0x1F ) ;
F_1 ( V_2 , V_41 , 0x01 ) ;
F_18 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_42 * V_43 )
{
const struct V_10 * V_11 =
F_25 ( & V_2 -> V_6 ) ;
struct V_8 * V_9 ;
struct V_12 * V_12 ;
int V_5 ;
int error ;
if ( ! V_2 -> V_25 ) {
F_3 ( & V_2 -> V_6 , L_6 ) ;
return - V_44 ;
}
V_5 = F_4 ( V_2 , V_29 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return - V_45 ;
}
F_14 ( & V_2 -> V_6 , L_8 , V_5 ) ;
V_9 = F_26 ( sizeof( struct V_8 ) , V_46 ) ;
V_12 = F_27 () ;
if ( ! V_9 || ! V_12 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
error = - V_47 ;
goto V_48;
}
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = V_12 ;
V_12 -> V_49 = V_2 -> V_49 ;
V_12 -> V_43 . V_50 = V_51 ;
V_12 -> V_52 = F_20 ;
V_12 -> V_53 = F_22 ;
V_12 -> V_6 . V_54 = & V_2 -> V_6 ;
V_12 -> V_55 [ 0 ] = F_28 ( V_56 ) | F_28 ( V_57 ) ;
V_12 -> V_58 = sizeof( V_9 -> V_22 [ 0 ] ) ;
V_12 -> V_59 = F_29 ( V_9 -> V_22 ) ;
V_12 -> V_21 = V_9 -> V_22 ;
F_30 ( V_12 , V_30 , V_31 ) ;
F_31 ( V_12 , V_9 ) ;
F_6 ( V_9 , V_11 ) ;
error = F_32 ( V_2 -> V_25 , NULL , F_13 ,
V_60 | V_61 ,
V_2 -> V_49 , V_9 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 , L_10 ) ;
goto V_48;
}
error = F_33 ( V_12 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 , L_11 ) ;
goto V_62;
}
F_23 ( V_2 ) ;
F_34 ( V_2 , V_9 ) ;
F_35 ( & V_2 -> V_6 , 1 ) ;
return 0 ;
V_62:
F_36 ( V_2 -> V_25 , V_9 ) ;
V_48:
F_37 ( V_12 ) ;
F_38 ( V_9 ) ;
return error ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_40 ( V_2 ) ;
F_36 ( V_2 -> V_25 , V_9 ) ;
F_41 ( V_9 -> V_12 ) ;
F_38 ( V_9 ) ;
return 0 ;
}
static int F_42 ( struct V_63 * V_6 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
F_18 ( V_2 ) ;
if ( F_44 ( & V_2 -> V_6 ) )
F_45 ( V_2 -> V_25 ) ;
return 0 ;
}
static int F_46 ( struct V_63 * V_6 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
if ( F_44 ( & V_2 -> V_6 ) )
F_47 ( V_2 -> V_25 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
