static int F_1 ( struct V_1 * V_2 , const void * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 ;
V_7 = F_3 ( V_6 -> V_9 , V_3 , V_4 ) ;
if ( ! V_7 ) {
V_8 = F_4 ( V_6 -> V_9 ) ;
V_6 -> V_10 = V_8 > 0 ? V_8 : 0 ;
if ( V_8 <= 0 )
V_7 = V_8 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , const void * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 ;
V_7 = F_6 ( V_6 -> V_9 , V_3 , V_4 ) ;
if ( ! V_7 ) {
V_8 = F_4 ( V_6 -> V_9 ) ;
V_6 -> V_10 = V_8 > 0 ? V_8 : 0 ;
if ( V_8 <= 0 )
V_7 = V_8 ;
}
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_10 ? : - V_11 ;
}
static void F_8 ( struct V_12 * V_13 , void * V_14 , T_1 V_15 ,
struct V_12 * V_16 )
{
int V_17 = V_16 ? 1 : 0 ;
if ( F_9 ( V_14 ) + V_15 <= V_18 ) {
V_17 += 1 ;
F_10 ( V_13 , V_17 ) ;
F_11 ( V_13 , V_14 , V_15 ) ;
} else {
V_17 += 2 ;
F_10 ( V_13 , V_17 ) ;
F_11 ( V_13 + 0 , V_14 , V_18 - F_9 ( V_14 ) ) ;
F_11 ( V_13 + 1 , V_14 + V_18 - F_9 ( V_14 ) ,
F_9 ( V_14 ) + V_15 - V_18 ) ;
}
if ( V_16 )
F_12 ( V_13 , V_17 , V_16 ) ;
}
static int F_13 ( struct V_19 * V_20 , int V_7 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
T_1 V_23 = V_6 -> V_10 - V_22 -> V_24 . V_25 ;
T_1 V_26 , V_27 ;
struct V_28 V_29 ;
if ( ! V_7 ) {
if ( V_23 ) {
F_16 ( & V_29 , V_20 -> V_30 ,
F_17 ( V_20 -> V_30 , V_23 ) ,
V_31 | V_32 ) ;
V_27 = V_23 ;
while ( V_27 ) {
F_18 ( & V_29 ) ;
V_26 = F_19 ( V_29 . V_33 , V_27 ) ;
memset ( V_29 . V_34 , 0 , V_26 ) ;
V_27 -= V_26 ;
}
F_20 ( & V_29 ) ;
}
F_21 ( V_20 -> V_30 ,
F_17 ( V_20 -> V_30 , V_6 -> V_10 ) ,
V_22 -> V_35 , V_22 -> V_24 . V_25 ,
V_23 ) ;
}
V_20 -> V_25 = V_6 -> V_10 ;
F_22 ( V_22 -> V_36 ) ;
F_23 ( V_22 -> V_35 ) ;
return V_7 ;
}
static void F_24 (
struct V_37 * V_38 , int V_7 )
{
struct V_19 * V_20 = V_38 -> V_39 ;
struct V_37 V_40 ;
if ( V_7 == - V_41 )
return;
V_40 . V_39 = V_20 -> V_42 . V_39 ;
V_40 . V_2 = F_25 ( F_14 ( V_20 ) ) ;
V_40 . V_43 = V_38 -> V_43 ;
V_20 -> V_42 . V_44 ( & V_40 ,
F_13 ( V_20 , V_7 ) ) ;
}
static int F_26 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
int V_7 ;
unsigned int V_45 , V_46 ;
if ( ! V_6 -> V_10 )
return - V_11 ;
if ( V_20 -> V_47 > V_6 -> V_10 - 11 )
return - V_48 ;
if ( V_20 -> V_25 < V_6 -> V_10 ) {
V_20 -> V_25 = V_6 -> V_10 ;
return - V_48 ;
}
if ( V_6 -> V_10 > V_18 )
return - V_49 ;
V_22 -> V_24 . V_50 = V_22 -> V_51 ;
V_22 -> V_24 . V_47 = V_6 -> V_10 - 1 ;
V_22 -> V_24 . V_30 = V_22 -> V_52 ;
V_22 -> V_24 . V_25 = V_6 -> V_10 ;
V_22 -> V_36 = F_27 ( V_6 -> V_10 - 1 - V_20 -> V_47 ,
( V_20 -> V_42 . V_43 & V_53 ) ?
V_54 : V_55 ) ;
if ( ! V_22 -> V_36 )
return - V_56 ;
V_46 = V_6 -> V_10 - V_20 -> V_47 - 2 ;
V_22 -> V_36 [ 0 ] = 0x02 ;
for ( V_45 = 1 ; V_45 < V_46 ; V_45 ++ )
V_22 -> V_36 [ V_45 ] = 1 + F_28 ( 255 ) ;
V_22 -> V_36 [ V_46 ] = 0x00 ;
F_8 ( V_22 -> V_51 , V_22 -> V_36 ,
V_6 -> V_10 - 1 - V_20 -> V_47 , V_20 -> V_50 ) ;
V_22 -> V_35 = F_27 ( V_6 -> V_10 ,
( V_20 -> V_42 . V_43 & V_53 ) ?
V_54 : V_55 ) ;
if ( ! V_22 -> V_35 ) {
F_22 ( V_22 -> V_36 ) ;
return - V_56 ;
}
F_8 ( V_22 -> V_52 , V_22 -> V_35 ,
V_6 -> V_10 , NULL ) ;
F_29 ( & V_22 -> V_24 , V_6 -> V_9 ) ;
F_30 ( & V_22 -> V_24 , V_20 -> V_42 . V_43 ,
F_24 , V_20 ) ;
V_7 = F_31 ( & V_22 -> V_24 ) ;
if ( V_7 != - V_41 &&
( V_7 != - V_57 ||
! ( V_20 -> V_42 . V_43 & V_58 ) ) )
return F_13 ( V_20 , V_7 ) ;
return V_7 ;
}
static int F_32 ( struct V_19 * V_20 , int V_7 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
unsigned int V_59 ;
if ( V_7 == - V_48 )
V_7 = - V_11 ;
if ( V_7 )
goto V_60;
if ( V_22 -> V_24 . V_25 != V_6 -> V_10 - 1 ) {
V_7 = - V_11 ;
goto V_60;
}
if ( V_22 -> V_35 [ 0 ] != 0x02 ) {
V_7 = - V_11 ;
goto V_60;
}
for ( V_59 = 1 ; V_59 < V_22 -> V_24 . V_25 ; V_59 ++ )
if ( V_22 -> V_35 [ V_59 ] == 0x00 )
break;
if ( V_59 < 9 || V_59 == V_22 -> V_24 . V_25 ) {
V_7 = - V_11 ;
goto V_60;
}
V_59 ++ ;
if ( V_20 -> V_25 < V_22 -> V_24 . V_25 - V_59 )
V_7 = - V_48 ;
V_20 -> V_25 = V_22 -> V_24 . V_25 - V_59 ;
if ( ! V_7 )
F_33 ( V_20 -> V_30 ,
F_17 ( V_20 -> V_30 , V_20 -> V_25 ) ,
V_22 -> V_35 + V_59 , V_20 -> V_25 ) ;
V_60:
F_23 ( V_22 -> V_35 ) ;
return V_7 ;
}
static void F_34 (
struct V_37 * V_38 , int V_7 )
{
struct V_19 * V_20 = V_38 -> V_39 ;
struct V_37 V_40 ;
if ( V_7 == - V_41 )
return;
V_40 . V_39 = V_20 -> V_42 . V_39 ;
V_40 . V_2 = F_25 ( F_14 ( V_20 ) ) ;
V_40 . V_43 = V_38 -> V_43 ;
V_20 -> V_42 . V_44 ( & V_40 , F_32 ( V_20 , V_7 ) ) ;
}
static int F_35 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
int V_7 ;
if ( ! V_6 -> V_10 || V_20 -> V_47 != V_6 -> V_10 )
return - V_11 ;
if ( V_6 -> V_10 > V_18 )
return - V_49 ;
V_22 -> V_24 . V_50 = V_20 -> V_50 ;
V_22 -> V_24 . V_47 = V_20 -> V_47 ;
V_22 -> V_24 . V_30 = V_22 -> V_52 ;
V_22 -> V_24 . V_25 = V_6 -> V_10 - 1 ;
V_22 -> V_35 = F_27 ( V_6 -> V_10 - 1 ,
( V_20 -> V_42 . V_43 & V_53 ) ?
V_54 : V_55 ) ;
if ( ! V_22 -> V_35 )
return - V_56 ;
F_8 ( V_22 -> V_52 , V_22 -> V_35 ,
V_6 -> V_10 - 1 , NULL ) ;
F_29 ( & V_22 -> V_24 , V_6 -> V_9 ) ;
F_30 ( & V_22 -> V_24 , V_20 -> V_42 . V_43 ,
F_34 , V_20 ) ;
V_7 = F_36 ( & V_22 -> V_24 ) ;
if ( V_7 != - V_41 &&
( V_7 != - V_57 ||
! ( V_20 -> V_42 . V_43 & V_58 ) ) )
return F_32 ( V_20 , V_7 ) ;
return V_7 ;
}
static int F_37 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
int V_7 ;
unsigned int V_46 ;
if ( ! V_6 -> V_10 )
return - V_11 ;
if ( V_20 -> V_47 > V_6 -> V_10 - 11 )
return - V_48 ;
if ( V_20 -> V_25 < V_6 -> V_10 ) {
V_20 -> V_25 = V_6 -> V_10 ;
return - V_48 ;
}
if ( V_6 -> V_10 > V_18 )
return - V_49 ;
V_22 -> V_24 . V_50 = V_22 -> V_51 ;
V_22 -> V_24 . V_47 = V_6 -> V_10 - 1 ;
V_22 -> V_24 . V_30 = V_22 -> V_52 ;
V_22 -> V_24 . V_25 = V_6 -> V_10 ;
V_22 -> V_36 = F_27 ( V_6 -> V_10 - 1 - V_20 -> V_47 ,
( V_20 -> V_42 . V_43 & V_53 ) ?
V_54 : V_55 ) ;
if ( ! V_22 -> V_36 )
return - V_56 ;
V_46 = V_6 -> V_10 - V_20 -> V_47 - 2 ;
V_22 -> V_36 [ 0 ] = 0x01 ;
memset ( V_22 -> V_36 + 1 , 0xff , V_46 - 1 ) ;
V_22 -> V_36 [ V_46 ] = 0x00 ;
F_8 ( V_22 -> V_51 , V_22 -> V_36 ,
V_6 -> V_10 - 1 - V_20 -> V_47 , V_20 -> V_50 ) ;
V_22 -> V_35 = F_27 ( V_6 -> V_10 ,
( V_20 -> V_42 . V_43 & V_53 ) ?
V_54 : V_55 ) ;
if ( ! V_22 -> V_35 ) {
F_22 ( V_22 -> V_36 ) ;
return - V_56 ;
}
F_8 ( V_22 -> V_52 , V_22 -> V_35 ,
V_6 -> V_10 , NULL ) ;
F_29 ( & V_22 -> V_24 , V_6 -> V_9 ) ;
F_30 ( & V_22 -> V_24 , V_20 -> V_42 . V_43 ,
F_24 , V_20 ) ;
V_7 = F_38 ( & V_22 -> V_24 ) ;
if ( V_7 != - V_41 &&
( V_7 != - V_57 ||
! ( V_20 -> V_42 . V_43 & V_58 ) ) )
return F_13 ( V_20 , V_7 ) ;
return V_7 ;
}
static int F_39 ( struct V_19 * V_20 , int V_7 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
unsigned int V_59 ;
if ( V_7 == - V_48 )
V_7 = - V_11 ;
if ( V_7 )
goto V_60;
if ( V_22 -> V_24 . V_25 != V_6 -> V_10 - 1 ) {
V_7 = - V_11 ;
goto V_60;
}
if ( V_22 -> V_35 [ 0 ] != 0x01 ) {
V_7 = - V_11 ;
goto V_60;
}
for ( V_59 = 1 ; V_59 < V_22 -> V_24 . V_25 ; V_59 ++ )
if ( V_22 -> V_35 [ V_59 ] != 0xff )
break;
if ( V_59 < 9 || V_59 == V_22 -> V_24 . V_25 ||
V_22 -> V_35 [ V_59 ] != 0x00 ) {
V_7 = - V_11 ;
goto V_60;
}
V_59 ++ ;
if ( V_20 -> V_25 < V_22 -> V_24 . V_25 - V_59 )
V_7 = - V_48 ;
V_20 -> V_25 = V_22 -> V_24 . V_25 - V_59 ;
if ( ! V_7 )
F_33 ( V_20 -> V_30 ,
F_17 ( V_20 -> V_30 , V_20 -> V_25 ) ,
V_22 -> V_35 + V_59 , V_20 -> V_25 ) ;
V_60:
F_23 ( V_22 -> V_35 ) ;
return V_7 ;
}
static void F_40 (
struct V_37 * V_38 , int V_7 )
{
struct V_19 * V_20 = V_38 -> V_39 ;
struct V_37 V_40 ;
if ( V_7 == - V_41 )
return;
V_40 . V_39 = V_20 -> V_42 . V_39 ;
V_40 . V_2 = F_25 ( F_14 ( V_20 ) ) ;
V_40 . V_43 = V_38 -> V_43 ;
V_20 -> V_42 . V_44 ( & V_40 , F_39 ( V_20 , V_7 ) ) ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_15 ( V_20 ) ;
int V_7 ;
if ( ! V_6 -> V_10 || V_20 -> V_47 != V_6 -> V_10 )
return - V_11 ;
if ( V_6 -> V_10 > V_18 )
return - V_49 ;
V_22 -> V_24 . V_50 = V_20 -> V_50 ;
V_22 -> V_24 . V_47 = V_20 -> V_47 ;
V_22 -> V_24 . V_30 = V_22 -> V_52 ;
V_22 -> V_24 . V_25 = V_6 -> V_10 - 1 ;
V_22 -> V_35 = F_27 ( V_6 -> V_10 - 1 ,
( V_20 -> V_42 . V_43 & V_53 ) ?
V_54 : V_55 ) ;
if ( ! V_22 -> V_35 )
return - V_56 ;
F_8 ( V_22 -> V_52 , V_22 -> V_35 ,
V_6 -> V_10 - 1 , NULL ) ;
F_29 ( & V_22 -> V_24 , V_6 -> V_9 ) ;
F_30 ( & V_22 -> V_24 , V_20 -> V_42 . V_43 ,
F_40 , V_20 ) ;
V_7 = F_42 ( & V_22 -> V_24 ) ;
if ( V_7 != - V_41 &&
( V_7 != - V_57 ||
! ( V_20 -> V_42 . V_43 & V_58 ) ) )
return F_39 ( V_20 , V_7 ) ;
return V_7 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_44 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_63 ;
V_63 = F_45 ( F_46 ( V_62 ) ) ;
if ( F_47 ( V_63 ) )
return F_48 ( V_63 ) ;
V_6 -> V_9 = V_63 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_50 ( V_6 -> V_9 ) ;
}
static void F_51 ( struct V_61 * V_62 )
{
struct V_64 * V_65 = F_46 ( V_62 ) ;
F_52 ( V_65 ) ;
F_22 ( V_62 ) ;
}
static int F_53 ( struct V_66 * V_67 , struct V_68 * * V_69 )
{
struct V_70 * V_71 ;
struct V_61 * V_62 ;
struct V_64 * V_65 ;
struct V_72 * V_73 ;
const char * V_74 ;
int V_7 ;
V_71 = F_54 ( V_69 ) ;
if ( F_47 ( V_71 ) )
return F_48 ( V_71 ) ;
if ( ( V_71 -> type ^ V_75 ) & V_71 -> V_76 )
return - V_11 ;
V_74 = F_55 ( V_69 [ 1 ] ) ;
if ( F_47 ( V_74 ) )
return F_48 ( V_74 ) ;
V_62 = F_56 ( sizeof( * V_62 ) + sizeof( * V_65 ) , V_54 ) ;
if ( ! V_62 )
return - V_56 ;
V_65 = F_46 ( V_62 ) ;
F_57 ( & V_65 -> V_42 , F_58 ( V_62 ) ) ;
V_7 = F_59 ( V_65 , V_74 , 0 ,
F_60 ( V_71 -> type , V_71 -> V_76 ) ) ;
if ( V_7 )
goto V_77;
V_73 = F_61 ( V_65 ) ;
V_7 = - V_78 ;
if ( snprintf ( V_62 -> V_79 . V_42 . V_80 ,
V_81 , L_1 ,
V_73 -> V_42 . V_80 ) >=
V_81 ||
snprintf ( V_62 -> V_79 . V_42 . V_82 ,
V_81 , L_1 ,
V_73 -> V_42 . V_82 ) >=
V_81 )
goto V_83;
V_62 -> V_79 . V_42 . V_84 = V_73 -> V_42 . V_84 & V_85 ;
V_62 -> V_79 . V_42 . V_86 = V_73 -> V_42 . V_86 ;
V_62 -> V_79 . V_42 . V_87 = sizeof( struct V_5 ) ;
V_62 -> V_79 . V_88 = F_43 ;
V_62 -> V_79 . exit = F_49 ;
V_62 -> V_79 . V_89 = F_26 ;
V_62 -> V_79 . V_90 = F_35 ;
V_62 -> V_79 . V_91 = F_37 ;
V_62 -> V_79 . V_92 = F_41 ;
V_62 -> V_79 . V_93 = F_1 ;
V_62 -> V_79 . V_94 = F_5 ;
V_62 -> V_79 . V_95 = F_7 ;
V_62 -> V_79 . V_96 = sizeof( struct V_21 ) + V_73 -> V_96 ;
V_62 -> free = F_51 ;
V_7 = F_62 ( V_67 , V_62 ) ;
if ( V_7 )
goto V_83;
return 0 ;
V_83:
F_52 ( V_65 ) ;
V_77:
F_22 ( V_62 ) ;
return V_7 ;
}
