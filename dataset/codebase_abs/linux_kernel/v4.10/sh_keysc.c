static unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_3 ( V_2 , V_9 , 0 ) ;
F_3 ( V_2 , V_10 , V_11 | ( V_6 << 8 ) ) ;
if ( V_8 -> V_12 )
F_6 ( V_8 -> V_12 ) ;
}
static void F_7 ( struct V_13 * V_14 , unsigned long * V_15 ,
const char * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < F_8 ( V_18 ) ; V_17 ++ )
F_9 ( V_14 , L_1 , V_16 , V_17 , V_15 [ V_17 ] ) ;
}
static T_1 F_10 ( int V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
struct V_1 * V_23 = F_11 ( V_22 ) ;
struct V_7 * V_8 = & V_23 -> V_8 ;
int V_24 = V_25 [ V_8 -> V_26 ] . V_27 ;
int V_28 = V_25 [ V_8 -> V_26 ] . V_29 ;
F_12 ( V_30 , V_18 ) ;
F_12 ( V_31 , V_18 ) ;
F_12 ( V_32 , V_18 ) ;
unsigned char V_33 , V_34 ;
int V_35 , V_17 , V_36 ;
F_9 ( & V_22 -> V_14 , L_2 ) ;
F_13 ( V_32 , V_18 ) ;
F_14 ( V_31 , V_18 ) ;
do {
F_14 ( V_30 , V_18 ) ;
V_33 = 0 ;
F_3 ( V_23 , V_10 , V_37 ) ;
for ( V_35 = 0 ; V_35 < V_24 ; V_35 ++ ) {
V_36 = V_28 * V_35 ;
F_3 ( V_23 , V_9 , 0xffff ^ ( 3 << ( V_35 * 2 ) ) ) ;
F_6 ( V_8 -> V_38 ) ;
V_34 = F_1 ( V_23 , V_39 ) ;
for ( V_17 = 0 ; V_17 < V_28 ; V_17 ++ ) {
if ( V_34 & ( 1 << V_17 ) )
F_15 ( V_36 + V_17 , V_30 ) ;
}
V_33 |= V_34 ^ ( ( 1 << V_28 ) - 1 ) ;
}
F_5 ( V_23 , V_33 ) ;
F_16 ( V_30 , V_30 , V_18 ) ;
F_17 ( V_32 , V_32 , V_30 , V_18 ) ;
F_18 ( V_31 , V_31 , V_30 , V_18 ) ;
F_7 ( & V_22 -> V_14 , V_30 , L_3 ) ;
} while ( F_1 ( V_23 , V_10 ) & 0x01 );
F_7 ( & V_22 -> V_14 , V_23 -> V_40 , L_4 ) ;
F_7 ( & V_22 -> V_14 , V_31 , L_5 ) ;
F_7 ( & V_22 -> V_14 , V_32 , L_6 ) ;
for ( V_35 = 0 ; V_35 < V_18 ; V_35 ++ ) {
V_17 = V_8 -> V_41 [ V_35 ] ;
if ( ! V_17 )
continue;
if ( F_19 ( V_35 , V_31 ) == F_19 ( V_35 , V_23 -> V_40 ) )
continue;
if ( F_19 ( V_35 , V_32 ) || F_19 ( V_35 , V_31 ) ) {
F_20 ( V_23 -> V_42 , V_43 , V_17 , 1 ) ;
F_15 ( V_35 , V_23 -> V_40 ) ;
}
if ( ! F_19 ( V_35 , V_32 ) ) {
F_20 ( V_23 -> V_42 , V_43 , V_17 , 0 ) ;
F_21 ( V_35 , V_23 -> V_40 ) ;
}
}
F_22 ( V_23 -> V_42 ) ;
return V_44 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_23 ;
struct V_7 * V_8 ;
struct V_45 * V_46 ;
struct V_47 * V_42 ;
int V_35 ;
int V_19 , error ;
if ( ! F_24 ( & V_22 -> V_14 ) ) {
F_25 ( & V_22 -> V_14 , L_7 ) ;
error = - V_48 ;
goto V_49;
}
error = - V_50 ;
V_46 = F_26 ( V_22 , V_51 , 0 ) ;
if ( V_46 == NULL ) {
F_25 ( & V_22 -> V_14 , L_8 ) ;
goto V_49;
}
V_19 = F_27 ( V_22 , 0 ) ;
if ( V_19 < 0 ) {
F_25 ( & V_22 -> V_14 , L_9 ) ;
goto V_49;
}
V_23 = F_28 ( sizeof( * V_23 ) , V_52 ) ;
if ( V_23 == NULL ) {
F_25 ( & V_22 -> V_14 , L_10 ) ;
error = - V_53 ;
goto V_49;
}
F_29 ( V_22 , V_23 ) ;
memcpy ( & V_23 -> V_8 , F_24 ( & V_22 -> V_14 ) , sizeof( V_23 -> V_8 ) ) ;
V_8 = & V_23 -> V_8 ;
V_23 -> V_4 = F_30 ( V_46 -> V_54 , F_31 ( V_46 ) ) ;
if ( V_23 -> V_4 == NULL ) {
F_25 ( & V_22 -> V_14 , L_11 ) ;
error = - V_50 ;
goto V_55;
}
V_23 -> V_42 = F_32 () ;
if ( ! V_23 -> V_42 ) {
F_25 ( & V_22 -> V_14 , L_12 ) ;
error = - V_53 ;
goto V_56;
}
V_42 = V_23 -> V_42 ;
V_42 -> V_57 [ 0 ] = F_33 ( V_43 ) ;
V_42 -> V_58 = V_22 -> V_58 ;
V_42 -> V_59 = L_13 ;
V_42 -> V_14 . V_60 = & V_22 -> V_14 ;
V_42 -> V_61 . V_62 = V_63 ;
V_42 -> V_61 . V_64 = 0x0001 ;
V_42 -> V_61 . V_65 = 0x0001 ;
V_42 -> V_61 . V_66 = 0x0100 ;
V_42 -> V_67 = V_8 -> V_41 ;
V_42 -> V_68 = sizeof( V_8 -> V_41 [ 0 ] ) ;
V_42 -> V_69 = F_34 ( V_8 -> V_41 ) ;
error = F_35 ( V_19 , NULL , F_10 , V_70 ,
F_36 ( & V_22 -> V_14 ) , V_22 ) ;
if ( error ) {
F_25 ( & V_22 -> V_14 , L_14 ) ;
goto V_71;
}
for ( V_35 = 0 ; V_35 < V_18 ; V_35 ++ )
F_15 ( V_8 -> V_41 [ V_35 ] , V_42 -> V_72 ) ;
F_21 ( V_73 , V_42 -> V_72 ) ;
error = F_37 ( V_42 ) ;
if ( error ) {
F_25 ( & V_22 -> V_14 , L_15 ) ;
goto V_74;
}
F_38 ( & V_22 -> V_14 ) ;
F_39 ( & V_22 -> V_14 ) ;
F_3 ( V_23 , V_75 , ( V_25 [ V_8 -> V_26 ] . V_76 << 8 ) |
V_8 -> V_77 ) ;
F_5 ( V_23 , 0 ) ;
F_40 ( & V_22 -> V_14 , 1 ) ;
return 0 ;
V_74:
F_41 ( V_19 , V_22 ) ;
V_71:
F_42 ( V_42 ) ;
V_56:
F_43 ( V_23 -> V_4 ) ;
V_55:
F_44 ( V_23 ) ;
V_49:
return error ;
}
static int F_45 ( struct V_21 * V_22 )
{
struct V_1 * V_23 = F_11 ( V_22 ) ;
F_3 ( V_23 , V_10 , V_37 ) ;
F_46 ( V_23 -> V_42 ) ;
F_41 ( F_27 ( V_22 , 0 ) , V_22 ) ;
F_43 ( V_23 -> V_4 ) ;
F_47 ( & V_22 -> V_14 ) ;
F_48 ( & V_22 -> V_14 ) ;
F_44 ( V_23 ) ;
return 0 ;
}
static int F_49 ( struct V_13 * V_14 )
{
struct V_21 * V_22 = F_50 ( V_14 ) ;
struct V_1 * V_23 = F_11 ( V_22 ) ;
int V_19 = F_27 ( V_22 , 0 ) ;
unsigned short V_5 ;
V_5 = F_1 ( V_23 , V_75 ) ;
if ( F_51 ( V_14 ) ) {
F_3 ( V_23 , V_75 , V_5 | 0x80 ) ;
F_52 ( V_19 ) ;
} else {
F_3 ( V_23 , V_75 , V_5 & ~ 0x80 ) ;
F_47 ( V_14 ) ;
}
return 0 ;
}
static int F_53 ( struct V_13 * V_14 )
{
struct V_21 * V_22 = F_50 ( V_14 ) ;
int V_19 = F_27 ( V_22 , 0 ) ;
if ( F_51 ( V_14 ) )
F_54 ( V_19 ) ;
else
F_39 ( V_14 ) ;
return 0 ;
}
