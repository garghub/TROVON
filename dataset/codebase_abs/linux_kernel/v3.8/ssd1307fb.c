static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 * V_3 , T_2 V_4 )
{
T_1 * V_5 ;
int V_6 = 0 ;
V_5 = F_2 ( V_4 + 1 , V_7 ) ;
if ( ! V_5 ) {
F_3 ( & V_2 -> V_8 , L_1 ) ;
return - V_9 ;
}
V_5 [ 0 ] = type ;
memcpy ( V_5 + 1 , V_3 , V_4 ) ;
V_6 = F_4 ( V_2 , V_5 , V_4 + 1 ) ;
if ( V_6 != V_4 + 1 ) {
F_3 ( & V_2 -> V_8 , L_2 ) ;
goto error;
}
error:
F_5 ( V_5 ) ;
return V_6 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_10 , V_3 , V_4 ) ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 , & V_3 , 1 ) ;
}
static inline int F_8 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_11 , V_3 , V_4 ) ;
}
static inline int F_9 ( struct V_1 * V_2 , T_1 V_12 )
{
return F_8 ( V_2 , & V_12 , 1 ) ;
}
static void F_10 ( struct V_13 * V_14 )
{
T_1 * V_15 = V_14 -> V_16 -> V_17 ;
int V_18 , V_19 , V_20 ;
for ( V_18 = 0 ; V_18 < ( V_21 / 8 ) ; V_18 ++ ) {
F_7 ( V_14 -> V_2 , V_22 + ( V_18 + 1 ) ) ;
F_7 ( V_14 -> V_2 , 0x00 ) ;
F_7 ( V_14 -> V_2 , 0x10 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
T_1 V_5 = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
T_2 V_24 = V_23 * V_18 ;
T_2 V_25 = V_24 + ( V_23 * V_20 + V_19 ) / 8 ;
T_1 V_26 = * ( V_15 + V_25 ) ;
T_1 V_27 = V_26 & ( 1 << ( V_19 % 8 ) ) ;
V_27 = V_27 >> ( V_19 % 8 ) ;
V_5 |= V_27 << V_20 ;
}
F_9 ( V_14 -> V_2 , V_5 ) ;
}
}
}
static T_3 F_11 ( struct V_28 * V_16 , const char T_4 * V_5 ,
T_5 V_29 , T_6 * V_30 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
unsigned long V_31 ;
unsigned long V_32 = * V_30 ;
T_1 T_7 * V_33 ;
V_31 = V_16 -> V_34 . V_35 ;
if ( V_32 > V_31 )
return - V_36 ;
if ( V_29 + V_32 > V_31 )
V_29 = V_31 - V_32 ;
if ( ! V_29 )
return - V_36 ;
V_33 = ( void V_37 * ) ( V_16 -> V_17 + V_32 ) ;
if ( F_12 ( V_33 , V_5 , V_29 ) )
return - V_38 ;
F_10 ( V_14 ) ;
* V_30 += V_29 ;
return V_29 ;
}
static void F_13 ( struct V_28 * V_16 , const struct V_39 * V_40 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_14 ( V_16 , V_40 ) ;
F_10 ( V_14 ) ;
}
static void F_15 ( struct V_28 * V_16 , const struct V_41 * V_42 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_16 ( V_16 , V_42 ) ;
F_10 ( V_14 ) ;
}
static void F_17 ( struct V_28 * V_16 , const struct V_43 * V_44 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_18 ( V_16 , V_44 ) ;
F_10 ( V_14 ) ;
}
static void F_19 ( struct V_28 * V_16 ,
struct V_45 * V_46 )
{
F_10 ( V_16 -> V_14 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
struct V_28 * V_16 ;
T_2 V_49 = V_23 * V_21 / 8 ;
struct V_13 * V_14 ;
T_1 * V_15 ;
int V_6 ;
if ( ! V_2 -> V_8 . V_50 ) {
F_3 ( & V_2 -> V_8 , L_3 ) ;
return - V_36 ;
}
V_16 = F_21 ( sizeof( struct V_13 ) , & V_2 -> V_8 ) ;
if ( ! V_16 ) {
F_3 ( & V_2 -> V_8 , L_4 ) ;
return - V_9 ;
}
V_15 = F_22 ( & V_2 -> V_8 , V_49 , V_7 ) ;
if ( ! V_15 ) {
F_3 ( & V_2 -> V_8 , L_5 ) ;
V_6 = - V_9 ;
goto V_51;
}
V_16 -> V_52 = & V_53 ;
V_16 -> V_34 = V_54 ;
V_16 -> V_55 = & V_56 ;
V_16 -> V_57 = V_58 ;
V_16 -> V_57 . V_59 . V_60 = 1 ;
V_16 -> V_57 . V_59 . V_61 = 0 ;
V_16 -> V_57 . V_62 . V_60 = 1 ;
V_16 -> V_57 . V_62 . V_61 = 0 ;
V_16 -> V_57 . V_63 . V_60 = 1 ;
V_16 -> V_57 . V_63 . V_61 = 0 ;
V_16 -> V_17 = ( T_1 V_37 T_7 * ) V_15 ;
V_16 -> V_34 . V_64 = ( unsigned long ) V_15 ;
V_16 -> V_34 . V_35 = V_49 ;
F_23 ( V_16 ) ;
V_14 = V_16 -> V_14 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_2 = V_2 ;
V_14 -> V_65 = F_24 ( V_2 -> V_8 . V_50 ,
L_6 , 0 ) ;
if ( ! F_25 ( V_14 -> V_65 ) ) {
V_6 = - V_36 ;
goto V_66;
}
V_6 = F_26 ( & V_2 -> V_8 , V_14 -> V_65 ,
V_67 ,
L_7 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 ,
L_8 ,
V_14 -> V_65 , V_6 ) ;
goto V_66;
}
V_14 -> V_68 = F_27 ( & V_2 -> V_8 , NULL ) ;
if ( F_28 ( V_14 -> V_68 ) ) {
F_3 ( & V_2 -> V_8 , L_9 ) ;
V_6 = F_29 ( V_14 -> V_68 ) ;
goto V_69;
}
V_14 -> V_70 = F_30 ( V_14 -> V_68 ) ;
F_31 ( & V_2 -> V_8 , L_10 , V_14 -> V_68 -> V_68 , V_14 -> V_70 ) ;
V_6 = F_32 ( V_16 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_8 , L_11 ) ;
goto V_71;
}
F_33 ( V_2 , V_16 ) ;
F_34 ( V_14 -> V_65 , 0 ) ;
F_35 ( 4 ) ;
F_34 ( V_14 -> V_65 , 1 ) ;
F_35 ( 4 ) ;
F_36 ( V_14 -> V_68 , V_14 -> V_70 / 2 , V_14 -> V_70 ) ;
F_37 ( V_14 -> V_68 ) ;
V_6 = F_7 ( V_2 , V_72 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_8 , L_12 ) ;
goto V_73;
}
V_6 = F_7 ( V_2 , V_74 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_8 , L_13 ) ;
goto V_73;
}
F_38 ( & V_2 -> V_8 , L_14 , V_16 -> V_75 , V_16 -> V_34 . V_48 , V_49 ) ;
return 0 ;
V_73:
F_39 ( V_16 ) ;
F_40 ( V_14 -> V_68 ) ;
V_71:
F_41 ( V_14 -> V_68 ) ;
V_69:
V_66:
F_42 ( V_16 ) ;
V_51:
F_43 ( V_16 ) ;
return V_6 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_28 * V_16 = F_45 ( V_2 ) ;
struct V_13 * V_14 = V_16 -> V_14 ;
F_39 ( V_16 ) ;
F_40 ( V_14 -> V_68 ) ;
F_41 ( V_14 -> V_68 ) ;
F_42 ( V_16 ) ;
F_43 ( V_16 ) ;
return 0 ;
}
