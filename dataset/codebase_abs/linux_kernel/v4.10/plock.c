static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ 0 ] = V_4 ;
V_2 -> V_3 [ 1 ] = V_5 ;
V_2 -> V_3 [ 2 ] = V_6 ;
}
static int F_2 ( struct V_1 * V_2 )
{
if ( ( V_4 != V_2 -> V_3 [ 0 ] ) ||
( V_5 < V_2 -> V_3 [ 1 ] ) ) {
F_3 ( L_1
L_2 ,
V_4 ,
V_5 ,
V_6 ,
V_2 -> V_3 [ 0 ] ,
V_2 -> V_3 [ 1 ] ,
V_2 -> V_3 [ 2 ] ) ;
return - V_7 ;
}
return 0 ;
}
static void F_4 ( struct V_8 * V_9 )
{
F_1 ( & V_9 -> V_2 ) ;
F_5 ( & V_9 -> V_10 ) ;
F_6 ( & V_11 ) ;
F_7 ( & V_9 -> V_10 , & V_12 ) ;
F_8 ( & V_11 ) ;
F_9 ( & V_13 ) ;
}
static void F_10 ( struct V_14 * V_15 , T_1 V_16 ,
struct V_17 * V_17 , struct V_18 * V_19 )
{
struct V_8 * V_9 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 )
return;
V_9 -> V_2 . V_21 = V_22 ;
V_9 -> V_2 . V_23 = V_19 -> V_24 ;
V_9 -> V_2 . V_25 = V_15 -> V_26 ;
V_9 -> V_2 . V_16 = V_16 ;
V_9 -> V_2 . V_27 = 0 ;
V_9 -> V_2 . V_28 = V_29 ;
if ( V_19 -> V_30 && V_19 -> V_30 -> V_31 )
V_9 -> V_2 . V_32 = ( V_33 ) V_19 -> V_24 ;
else
V_9 -> V_2 . V_32 = ( V_33 ) ( long ) V_19 -> V_34 ;
V_9 -> V_2 . V_35 |= V_36 ;
F_4 ( V_9 ) ;
}
int F_12 ( T_2 * V_37 , T_1 V_16 , struct V_17 * V_17 ,
int V_38 , struct V_18 * V_19 )
{
struct V_14 * V_15 ;
struct V_8 * V_9 ;
struct V_39 * V_40 ;
int V_41 ;
V_15 = F_13 ( V_37 ) ;
if ( ! V_15 )
return - V_7 ;
V_40 = F_11 ( sizeof( * V_40 ) , V_20 ) ;
if ( ! V_40 ) {
V_41 = - V_42 ;
goto V_43;
}
V_9 = & V_40 -> V_40 ;
V_9 -> V_2 . V_21 = V_44 ;
V_9 -> V_2 . V_23 = V_19 -> V_24 ;
V_9 -> V_2 . V_45 = ( V_19 -> V_46 == V_47 ) ;
V_9 -> V_2 . V_48 = F_14 ( V_38 ) ;
V_9 -> V_2 . V_25 = V_15 -> V_26 ;
V_9 -> V_2 . V_16 = V_16 ;
V_9 -> V_2 . V_27 = V_19 -> V_49 ;
V_9 -> V_2 . V_28 = V_19 -> V_50 ;
if ( V_19 -> V_30 && V_19 -> V_30 -> V_31 ) {
V_9 -> V_2 . V_32 = ( V_33 ) V_19 -> V_24 ;
V_40 -> V_51 = V_19 -> V_30 -> V_31 ;
F_15 ( & V_40 -> V_52 ) ;
F_16 ( & V_40 -> V_52 , V_19 ) ;
V_40 -> V_19 = V_19 ;
V_40 -> V_17 = V_17 ;
} else {
V_9 -> V_2 . V_32 = ( V_33 ) ( long ) V_19 -> V_34 ;
V_40 -> V_51 = NULL ;
}
F_4 ( V_9 ) ;
if ( V_40 -> V_51 == NULL ) {
V_41 = F_17 ( V_53 , ( V_9 -> V_54 != 0 ) ) ;
if ( V_41 == - V_55 ) {
F_18 ( V_15 , L_3 ,
( unsigned long long ) V_16 ) ;
F_6 ( & V_11 ) ;
F_19 ( & V_9 -> V_10 ) ;
F_8 ( & V_11 ) ;
F_20 ( V_40 ) ;
F_10 ( V_15 , V_16 , V_17 , V_19 ) ;
goto V_43;
}
} else {
V_41 = V_56 ;
goto V_43;
}
F_6 ( & V_11 ) ;
if ( ! F_21 ( & V_9 -> V_10 ) ) {
F_22 ( V_15 , L_4 ,
( unsigned long long ) V_16 ) ;
F_19 ( & V_9 -> V_10 ) ;
}
F_8 ( & V_11 ) ;
V_41 = V_9 -> V_2 . V_41 ;
if ( ! V_41 ) {
if ( F_23 ( V_17 , V_19 ) < 0 )
F_22 ( V_15 , L_5 ,
( unsigned long long ) V_16 ) ;
}
F_20 ( V_40 ) ;
V_43:
F_24 ( V_15 ) ;
return V_41 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_17 * V_17 ;
struct V_18 * V_19 ;
struct V_18 * V_52 ;
int (* F_26)( struct V_18 * V_19 , int V_57 ) = NULL ;
struct V_39 * V_40 = (struct V_39 * ) V_9 ;
int V_41 = 0 ;
F_6 ( & V_11 ) ;
if ( ! F_21 ( & V_9 -> V_10 ) ) {
F_3 ( L_6 ,
( unsigned long long ) V_9 -> V_2 . V_16 ) ;
F_19 ( & V_9 -> V_10 ) ;
}
F_8 ( & V_11 ) ;
V_17 = V_40 -> V_17 ;
V_52 = & V_40 -> V_52 ;
V_19 = V_40 -> V_19 ;
F_26 = V_40 -> V_51 ;
if ( V_9 -> V_2 . V_41 ) {
F_26 ( V_19 , V_9 -> V_2 . V_41 ) ;
goto V_43;
}
V_52 -> V_58 &= ~ V_59 ;
if ( F_27 ( V_17 , V_52 , NULL ) ) {
F_3 ( L_7 ,
( unsigned long long ) V_9 -> V_2 . V_16 , V_17 , V_19 ) ;
}
V_41 = F_26 ( V_19 , 0 ) ;
if ( V_41 ) {
F_3 ( L_8
L_9 ) ;
goto V_43;
}
V_43:
F_20 ( V_40 ) ;
return V_41 ;
}
int F_28 ( T_2 * V_37 , T_1 V_16 , struct V_17 * V_17 ,
struct V_18 * V_19 )
{
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_41 ;
unsigned char V_58 = V_19 -> V_58 ;
V_15 = F_13 ( V_37 ) ;
if ( ! V_15 )
return - V_7 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 ) {
V_41 = - V_42 ;
goto V_43;
}
V_19 -> V_58 |= V_60 ;
V_41 = F_23 ( V_17 , V_19 ) ;
if ( V_41 == - V_61 ) {
V_41 = 0 ;
goto V_62;
}
if ( V_41 < 0 ) {
F_22 ( V_15 , L_10 ,
V_41 , ( unsigned long long ) V_16 ) ;
}
V_9 -> V_2 . V_21 = V_22 ;
V_9 -> V_2 . V_23 = V_19 -> V_24 ;
V_9 -> V_2 . V_25 = V_15 -> V_26 ;
V_9 -> V_2 . V_16 = V_16 ;
V_9 -> V_2 . V_27 = V_19 -> V_49 ;
V_9 -> V_2 . V_28 = V_19 -> V_50 ;
if ( V_19 -> V_30 && V_19 -> V_30 -> V_31 )
V_9 -> V_2 . V_32 = ( V_33 ) V_19 -> V_24 ;
else
V_9 -> V_2 . V_32 = ( V_33 ) ( long ) V_19 -> V_34 ;
if ( V_19 -> V_58 & V_63 ) {
V_9 -> V_2 . V_35 |= V_36 ;
F_4 ( V_9 ) ;
V_41 = 0 ;
goto V_43;
}
F_4 ( V_9 ) ;
F_29 ( V_53 , ( V_9 -> V_54 != 0 ) ) ;
F_6 ( & V_11 ) ;
if ( ! F_21 ( & V_9 -> V_10 ) ) {
F_22 ( V_15 , L_11 ,
( unsigned long long ) V_16 ) ;
F_19 ( & V_9 -> V_10 ) ;
}
F_8 ( & V_11 ) ;
V_41 = V_9 -> V_2 . V_41 ;
if ( V_41 == - V_61 )
V_41 = 0 ;
V_62:
F_20 ( V_9 ) ;
V_43:
F_24 ( V_15 ) ;
V_19 -> V_58 = V_58 ;
return V_41 ;
}
int F_30 ( T_2 * V_37 , T_1 V_16 , struct V_17 * V_17 ,
struct V_18 * V_19 )
{
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_41 ;
V_15 = F_13 ( V_37 ) ;
if ( ! V_15 )
return - V_7 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 ) {
V_41 = - V_42 ;
goto V_43;
}
V_9 -> V_2 . V_21 = V_64 ;
V_9 -> V_2 . V_23 = V_19 -> V_24 ;
V_9 -> V_2 . V_45 = ( V_19 -> V_46 == V_47 ) ;
V_9 -> V_2 . V_25 = V_15 -> V_26 ;
V_9 -> V_2 . V_16 = V_16 ;
V_9 -> V_2 . V_27 = V_19 -> V_49 ;
V_9 -> V_2 . V_28 = V_19 -> V_50 ;
if ( V_19 -> V_30 && V_19 -> V_30 -> V_31 )
V_9 -> V_2 . V_32 = ( V_33 ) V_19 -> V_24 ;
else
V_9 -> V_2 . V_32 = ( V_33 ) ( long ) V_19 -> V_34 ;
F_4 ( V_9 ) ;
F_29 ( V_53 , ( V_9 -> V_54 != 0 ) ) ;
F_6 ( & V_11 ) ;
if ( ! F_21 ( & V_9 -> V_10 ) ) {
F_22 ( V_15 , L_12 ,
( unsigned long long ) V_16 ) ;
F_19 ( & V_9 -> V_10 ) ;
}
F_8 ( & V_11 ) ;
V_41 = V_9 -> V_2 . V_41 ;
V_19 -> V_46 = V_65 ;
if ( V_41 == - V_61 )
V_41 = 0 ;
else if ( V_41 > 0 ) {
F_15 ( V_19 ) ;
V_19 -> V_46 = ( V_9 -> V_2 . V_45 ) ? V_47 : V_66 ;
V_19 -> V_58 = V_67 ;
V_19 -> V_24 = V_9 -> V_2 . V_23 ;
V_19 -> V_49 = V_9 -> V_2 . V_27 ;
V_19 -> V_50 = V_9 -> V_2 . V_28 ;
V_41 = 0 ;
}
F_20 ( V_9 ) ;
V_43:
F_24 ( V_15 ) ;
return V_41 ;
}
static T_3 F_31 ( struct V_17 * V_17 , char T_4 * V_68 , T_5 V_69 ,
T_6 * V_70 )
{
struct V_1 V_2 ;
struct V_8 * V_9 = NULL ;
if ( V_69 < sizeof( V_2 ) )
return - V_7 ;
F_6 ( & V_11 ) ;
if ( ! F_21 ( & V_12 ) ) {
V_9 = F_32 ( V_12 . V_71 , struct V_8 , V_10 ) ;
if ( V_9 -> V_2 . V_35 & V_36 )
F_19 ( & V_9 -> V_10 ) ;
else
F_33 ( & V_9 -> V_10 , & V_72 ) ;
memcpy ( & V_2 , & V_9 -> V_2 , sizeof( V_2 ) ) ;
}
F_8 ( & V_11 ) ;
if ( ! V_9 )
return - V_73 ;
if ( V_9 -> V_2 . V_35 & V_36 )
F_20 ( V_9 ) ;
if ( F_34 ( V_68 , & V_2 , sizeof( V_2 ) ) )
return - V_74 ;
return sizeof( V_2 ) ;
}
static T_3 F_35 ( struct V_17 * V_17 , const char T_4 * V_68 , T_5 V_69 ,
T_6 * V_70 )
{
struct V_1 V_2 ;
struct V_8 * V_9 ;
int V_75 = 0 , V_76 = 0 ;
if ( V_69 != sizeof( V_2 ) )
return - V_7 ;
if ( F_36 ( & V_2 , V_68 , sizeof( V_2 ) ) )
return - V_74 ;
if ( F_2 ( & V_2 ) )
return - V_7 ;
F_6 ( & V_11 ) ;
F_37 (op, &recv_list, list) {
if ( V_9 -> V_2 . V_25 == V_2 . V_25 &&
V_9 -> V_2 . V_16 == V_2 . V_16 &&
V_9 -> V_2 . V_32 == V_2 . V_32 ) {
struct V_39 * V_40 = (struct V_39 * ) V_9 ;
F_38 ( & V_9 -> V_10 ) ;
memcpy ( & V_9 -> V_2 , & V_2 , sizeof( V_2 ) ) ;
if ( V_40 -> V_51 )
V_76 = 1 ;
else
V_9 -> V_54 = 1 ;
V_75 = 1 ;
break;
}
}
F_8 ( & V_11 ) ;
if ( V_75 ) {
if ( V_76 )
F_25 ( V_9 ) ;
else
F_9 ( & V_53 ) ;
} else
F_3 ( L_13 , V_2 . V_25 ,
( unsigned long long ) V_2 . V_16 ) ;
return V_69 ;
}
static unsigned int F_39 ( struct V_17 * V_17 , T_7 * V_48 )
{
unsigned int V_77 = 0 ;
F_40 ( V_17 , & V_13 , V_48 ) ;
F_6 ( & V_11 ) ;
if ( ! F_21 ( & V_12 ) )
V_77 = V_78 | V_79 ;
F_8 ( & V_11 ) ;
return V_77 ;
}
int F_41 ( void )
{
int V_41 ;
F_42 ( & V_11 ) ;
F_5 ( & V_12 ) ;
F_5 ( & V_72 ) ;
F_43 ( & V_13 ) ;
F_43 ( & V_53 ) ;
V_41 = F_44 ( & V_80 ) ;
if ( V_41 )
F_3 ( L_14 , V_41 ) ;
return V_41 ;
}
void F_45 ( void )
{
F_46 ( & V_80 ) ;
}
