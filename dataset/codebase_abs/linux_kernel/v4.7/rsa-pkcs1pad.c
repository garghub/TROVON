static const struct V_1 * F_1 ( const char * V_2 )
{
const struct V_1 * V_3 ;
for ( V_3 = V_4 ; V_3 -> V_2 ; V_3 ++ )
if ( strcmp ( V_2 , V_3 -> V_2 ) == 0 )
return V_3 ;
return NULL ;
}
static int F_2 ( struct V_5 * V_6 , const void * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_11 , V_12 ;
V_11 = F_4 ( V_10 -> V_13 , V_7 , V_8 ) ;
if ( ! V_11 ) {
V_12 = F_5 ( V_10 -> V_13 ) ;
V_10 -> V_14 = V_12 > 0 ? V_12 : 0 ;
if ( V_12 <= 0 )
V_11 = V_12 ;
}
return V_11 ;
}
static int F_6 ( struct V_5 * V_6 , const void * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_11 , V_12 ;
V_11 = F_7 ( V_10 -> V_13 , V_7 , V_8 ) ;
if ( ! V_11 ) {
V_12 = F_5 ( V_10 -> V_13 ) ;
V_10 -> V_14 = V_12 > 0 ? V_12 : 0 ;
if ( V_12 <= 0 )
V_11 = V_12 ;
}
return V_11 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
return V_10 -> V_14 ? : - V_15 ;
}
static void F_9 ( struct V_16 * V_17 , void * V_18 , T_1 V_19 ,
struct V_16 * V_20 )
{
int V_21 = V_20 ? 1 : 0 ;
if ( F_10 ( V_18 ) + V_19 <= V_22 ) {
V_21 += 1 ;
F_11 ( V_17 , V_21 ) ;
F_12 ( V_17 , V_18 , V_19 ) ;
} else {
V_21 += 2 ;
F_11 ( V_17 , V_21 ) ;
F_12 ( V_17 + 0 , V_18 , V_22 - F_10 ( V_18 ) ) ;
F_12 ( V_17 + 1 , V_18 + V_22 - F_10 ( V_18 ) ,
F_10 ( V_18 ) + V_19 - V_22 ) ;
}
if ( V_20 )
F_13 ( V_17 , V_21 , V_20 ) ;
}
static int F_14 ( struct V_23 * V_24 , int V_11 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
T_1 V_27 = V_10 -> V_14 - V_26 -> V_28 . V_29 ;
T_1 V_30 , V_31 ;
struct V_32 V_33 ;
if ( ! V_11 ) {
if ( V_27 ) {
F_17 ( & V_33 , V_24 -> V_34 ,
F_18 ( V_24 -> V_34 , V_27 ) ,
V_35 | V_36 ) ;
V_31 = V_27 ;
while ( V_31 ) {
F_19 ( & V_33 ) ;
V_30 = F_20 ( V_33 . V_37 , V_31 ) ;
memset ( V_33 . V_38 , 0 , V_30 ) ;
V_31 -= V_30 ;
}
F_21 ( & V_33 ) ;
}
F_22 ( V_24 -> V_34 ,
F_18 ( V_24 -> V_34 , V_10 -> V_14 ) ,
V_26 -> V_39 , V_26 -> V_28 . V_29 ,
V_27 ) ;
}
V_24 -> V_29 = V_10 -> V_14 ;
F_23 ( V_26 -> V_40 ) ;
F_24 ( V_26 -> V_39 ) ;
return V_11 ;
}
static void F_25 (
struct V_41 * V_42 , int V_11 )
{
struct V_23 * V_24 = V_42 -> V_43 ;
struct V_41 V_44 ;
if ( V_11 == - V_45 )
return;
V_44 . V_43 = V_24 -> V_46 . V_43 ;
V_44 . V_6 = F_26 ( F_15 ( V_24 ) ) ;
V_44 . V_47 = V_42 -> V_47 ;
V_24 -> V_46 . V_48 ( & V_44 ,
F_14 ( V_24 , V_11 ) ) ;
}
static int F_27 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
int V_11 ;
unsigned int V_49 , V_50 ;
if ( ! V_10 -> V_14 )
return - V_15 ;
if ( V_24 -> V_51 > V_10 -> V_14 - 11 )
return - V_52 ;
if ( V_24 -> V_29 < V_10 -> V_14 ) {
V_24 -> V_29 = V_10 -> V_14 ;
return - V_52 ;
}
if ( V_10 -> V_14 > V_22 )
return - V_53 ;
V_26 -> V_28 . V_54 = V_26 -> V_55 ;
V_26 -> V_28 . V_51 = V_10 -> V_14 - 1 ;
V_26 -> V_28 . V_34 = V_26 -> V_56 ;
V_26 -> V_28 . V_29 = V_10 -> V_14 ;
V_26 -> V_40 = F_28 ( V_10 -> V_14 - 1 - V_24 -> V_51 ,
( V_24 -> V_46 . V_47 & V_57 ) ?
V_58 : V_59 ) ;
if ( ! V_26 -> V_40 )
return - V_60 ;
V_50 = V_10 -> V_14 - V_24 -> V_51 - 2 ;
V_26 -> V_40 [ 0 ] = 0x02 ;
for ( V_49 = 1 ; V_49 < V_50 ; V_49 ++ )
V_26 -> V_40 [ V_49 ] = 1 + F_29 ( 255 ) ;
V_26 -> V_40 [ V_50 ] = 0x00 ;
F_9 ( V_26 -> V_55 , V_26 -> V_40 ,
V_10 -> V_14 - 1 - V_24 -> V_51 , V_24 -> V_54 ) ;
V_26 -> V_39 = F_28 ( V_10 -> V_14 ,
( V_24 -> V_46 . V_47 & V_57 ) ?
V_58 : V_59 ) ;
if ( ! V_26 -> V_39 ) {
F_23 ( V_26 -> V_40 ) ;
return - V_60 ;
}
F_9 ( V_26 -> V_56 , V_26 -> V_39 ,
V_10 -> V_14 , NULL ) ;
F_30 ( & V_26 -> V_28 , V_10 -> V_13 ) ;
F_31 ( & V_26 -> V_28 , V_24 -> V_46 . V_47 ,
F_25 , V_24 ) ;
V_11 = F_32 ( & V_26 -> V_28 ) ;
if ( V_11 != - V_45 &&
( V_11 != - V_61 ||
! ( V_24 -> V_46 . V_47 & V_62 ) ) )
return F_14 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_33 ( struct V_23 * V_24 , int V_11 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
unsigned int V_63 ;
if ( V_11 == - V_52 )
V_11 = - V_15 ;
if ( V_11 )
goto V_64;
if ( V_26 -> V_28 . V_29 != V_10 -> V_14 - 1 ) {
V_11 = - V_15 ;
goto V_64;
}
if ( V_26 -> V_39 [ 0 ] != 0x02 ) {
V_11 = - V_15 ;
goto V_64;
}
for ( V_63 = 1 ; V_63 < V_26 -> V_28 . V_29 ; V_63 ++ )
if ( V_26 -> V_39 [ V_63 ] == 0x00 )
break;
if ( V_63 < 9 || V_63 == V_26 -> V_28 . V_29 ) {
V_11 = - V_15 ;
goto V_64;
}
V_63 ++ ;
if ( V_24 -> V_29 < V_26 -> V_28 . V_29 - V_63 )
V_11 = - V_52 ;
V_24 -> V_29 = V_26 -> V_28 . V_29 - V_63 ;
if ( ! V_11 )
F_34 ( V_24 -> V_34 ,
F_18 ( V_24 -> V_34 , V_24 -> V_29 ) ,
V_26 -> V_39 + V_63 , V_24 -> V_29 ) ;
V_64:
F_24 ( V_26 -> V_39 ) ;
return V_11 ;
}
static void F_35 (
struct V_41 * V_42 , int V_11 )
{
struct V_23 * V_24 = V_42 -> V_43 ;
struct V_41 V_44 ;
if ( V_11 == - V_45 )
return;
V_44 . V_43 = V_24 -> V_46 . V_43 ;
V_44 . V_6 = F_26 ( F_15 ( V_24 ) ) ;
V_44 . V_47 = V_42 -> V_47 ;
V_24 -> V_46 . V_48 ( & V_44 , F_33 ( V_24 , V_11 ) ) ;
}
static int F_36 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
int V_11 ;
if ( ! V_10 -> V_14 || V_24 -> V_51 != V_10 -> V_14 )
return - V_15 ;
if ( V_10 -> V_14 > V_22 )
return - V_53 ;
V_26 -> V_28 . V_54 = V_24 -> V_54 ;
V_26 -> V_28 . V_51 = V_24 -> V_51 ;
V_26 -> V_28 . V_34 = V_26 -> V_56 ;
V_26 -> V_28 . V_29 = V_10 -> V_14 ;
V_26 -> V_39 = F_28 ( V_10 -> V_14 ,
( V_24 -> V_46 . V_47 & V_57 ) ?
V_58 : V_59 ) ;
if ( ! V_26 -> V_39 )
return - V_60 ;
F_9 ( V_26 -> V_56 , V_26 -> V_39 ,
V_10 -> V_14 , NULL ) ;
F_30 ( & V_26 -> V_28 , V_10 -> V_13 ) ;
F_31 ( & V_26 -> V_28 , V_24 -> V_46 . V_47 ,
F_35 , V_24 ) ;
V_11 = F_37 ( & V_26 -> V_28 ) ;
if ( V_11 != - V_45 &&
( V_11 != - V_61 ||
! ( V_24 -> V_46 . V_47 & V_62 ) ) )
return F_33 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_38 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
const struct V_1 * V_65 = NULL ;
int V_11 ;
unsigned int V_50 , V_66 = 0 ;
if ( ! V_10 -> V_14 )
return - V_15 ;
if ( V_10 -> V_67 ) {
V_65 = F_1 ( V_10 -> V_67 ) ;
if ( ! V_65 )
return - V_15 ;
V_66 = V_65 -> V_12 ;
}
if ( V_24 -> V_51 + V_66 > V_10 -> V_14 - 11 )
return - V_52 ;
if ( V_24 -> V_29 < V_10 -> V_14 ) {
V_24 -> V_29 = V_10 -> V_14 ;
return - V_52 ;
}
if ( V_10 -> V_14 > V_22 )
return - V_53 ;
V_26 -> V_28 . V_54 = V_26 -> V_55 ;
V_26 -> V_28 . V_51 = V_10 -> V_14 - 1 ;
V_26 -> V_28 . V_34 = V_26 -> V_56 ;
V_26 -> V_28 . V_29 = V_10 -> V_14 ;
V_26 -> V_40 = F_28 ( V_10 -> V_14 - 1 - V_24 -> V_51 ,
( V_24 -> V_46 . V_47 & V_57 ) ?
V_58 : V_59 ) ;
if ( ! V_26 -> V_40 )
return - V_60 ;
V_50 = V_10 -> V_14 - V_66 - V_24 -> V_51 - 2 ;
V_26 -> V_40 [ 0 ] = 0x01 ;
memset ( V_26 -> V_40 + 1 , 0xff , V_50 - 1 ) ;
V_26 -> V_40 [ V_50 ] = 0x00 ;
if ( V_65 ) {
memcpy ( V_26 -> V_40 + V_50 + 1 , V_65 -> V_43 ,
V_65 -> V_12 ) ;
}
F_9 ( V_26 -> V_55 , V_26 -> V_40 ,
V_10 -> V_14 - 1 - V_24 -> V_51 , V_24 -> V_54 ) ;
V_26 -> V_39 = F_28 ( V_10 -> V_14 ,
( V_24 -> V_46 . V_47 & V_57 ) ?
V_58 : V_59 ) ;
if ( ! V_26 -> V_39 ) {
F_23 ( V_26 -> V_40 ) ;
return - V_60 ;
}
F_9 ( V_26 -> V_56 , V_26 -> V_39 ,
V_10 -> V_14 , NULL ) ;
F_30 ( & V_26 -> V_28 , V_10 -> V_13 ) ;
F_31 ( & V_26 -> V_28 , V_24 -> V_46 . V_47 ,
F_25 , V_24 ) ;
V_11 = F_39 ( & V_26 -> V_28 ) ;
if ( V_11 != - V_45 &&
( V_11 != - V_61 ||
! ( V_24 -> V_46 . V_47 & V_62 ) ) )
return F_14 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_40 ( struct V_23 * V_24 , int V_11 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
const struct V_1 * V_65 ;
unsigned int V_63 ;
if ( V_11 == - V_52 )
V_11 = - V_15 ;
if ( V_11 )
goto V_64;
if ( V_26 -> V_28 . V_29 != V_10 -> V_14 - 1 ) {
V_11 = - V_15 ;
goto V_64;
}
V_11 = - V_68 ;
if ( V_26 -> V_39 [ 0 ] != 0x01 )
goto V_64;
for ( V_63 = 1 ; V_63 < V_26 -> V_28 . V_29 ; V_63 ++ )
if ( V_26 -> V_39 [ V_63 ] != 0xff )
break;
if ( V_63 < 9 || V_63 == V_26 -> V_28 . V_29 ||
V_26 -> V_39 [ V_63 ] != 0x00 )
goto V_64;
V_63 ++ ;
if ( V_10 -> V_67 ) {
V_65 = F_1 ( V_10 -> V_67 ) ;
if ( ! V_65 )
goto V_64;
if ( memcmp ( V_26 -> V_39 + V_63 , V_65 -> V_43 ,
V_65 -> V_12 ) )
goto V_64;
V_63 += V_65 -> V_12 ;
}
V_11 = 0 ;
if ( V_24 -> V_29 < V_26 -> V_28 . V_29 - V_63 )
V_11 = - V_52 ;
V_24 -> V_29 = V_26 -> V_28 . V_29 - V_63 ;
if ( ! V_11 )
F_34 ( V_24 -> V_34 ,
F_18 ( V_24 -> V_34 , V_24 -> V_29 ) ,
V_26 -> V_39 + V_63 , V_24 -> V_29 ) ;
V_64:
F_24 ( V_26 -> V_39 ) ;
return V_11 ;
}
static void F_41 (
struct V_41 * V_42 , int V_11 )
{
struct V_23 * V_24 = V_42 -> V_43 ;
struct V_41 V_44 ;
if ( V_11 == - V_45 )
return;
V_44 . V_43 = V_24 -> V_46 . V_43 ;
V_44 . V_6 = F_26 ( F_15 ( V_24 ) ) ;
V_44 . V_47 = V_42 -> V_47 ;
V_24 -> V_46 . V_48 ( & V_44 , F_40 ( V_24 , V_11 ) ) ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_15 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_16 ( V_24 ) ;
int V_11 ;
if ( ! V_10 -> V_14 || V_24 -> V_51 < V_10 -> V_14 )
return - V_15 ;
if ( V_10 -> V_14 > V_22 )
return - V_53 ;
V_26 -> V_28 . V_54 = V_24 -> V_54 ;
V_26 -> V_28 . V_51 = V_24 -> V_51 ;
V_26 -> V_28 . V_34 = V_26 -> V_56 ;
V_26 -> V_28 . V_29 = V_10 -> V_14 ;
V_26 -> V_39 = F_28 ( V_10 -> V_14 ,
( V_24 -> V_46 . V_47 & V_57 ) ?
V_58 : V_59 ) ;
if ( ! V_26 -> V_39 )
return - V_60 ;
F_9 ( V_26 -> V_56 , V_26 -> V_39 ,
V_10 -> V_14 , NULL ) ;
F_30 ( & V_26 -> V_28 , V_10 -> V_13 ) ;
F_31 ( & V_26 -> V_28 , V_24 -> V_46 . V_47 ,
F_41 , V_24 ) ;
V_11 = F_43 ( & V_26 -> V_28 ) ;
if ( V_11 != - V_45 &&
( V_11 != - V_61 ||
! ( V_24 -> V_46 . V_47 & V_62 ) ) )
return F_40 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_45 ( V_6 ) ;
struct V_71 * V_72 = F_46 ( V_70 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_5 * V_73 ;
V_73 = F_47 ( F_46 ( V_70 ) ) ;
if ( F_48 ( V_73 ) )
return F_49 ( V_73 ) ;
V_10 -> V_13 = V_73 ;
V_10 -> V_67 = V_72 -> V_67 ;
return 0 ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
F_51 ( V_10 -> V_13 ) ;
}
static void F_52 ( struct V_69 * V_70 )
{
struct V_71 * V_10 = F_46 ( V_70 ) ;
struct V_74 * V_75 = & V_10 -> V_75 ;
F_53 ( V_75 ) ;
F_23 ( V_10 -> V_67 ) ;
F_23 ( V_70 ) ;
}
static int F_54 ( struct V_76 * V_77 , struct V_78 * * V_79 )
{
struct V_80 * V_81 ;
struct V_69 * V_70 ;
struct V_71 * V_10 ;
struct V_74 * V_75 ;
struct V_82 * V_83 ;
const char * V_84 ;
const char * V_67 ;
int V_11 ;
V_81 = F_55 ( V_79 ) ;
if ( F_48 ( V_81 ) )
return F_49 ( V_81 ) ;
if ( ( V_81 -> type ^ V_85 ) & V_81 -> V_86 )
return - V_15 ;
V_84 = F_56 ( V_79 [ 1 ] ) ;
if ( F_48 ( V_84 ) )
return F_49 ( V_84 ) ;
V_67 = F_56 ( V_79 [ 2 ] ) ;
if ( F_48 ( V_67 ) )
V_67 = NULL ;
V_70 = F_57 ( sizeof( * V_70 ) + sizeof( * V_10 ) , V_58 ) ;
if ( ! V_70 )
return - V_60 ;
V_10 = F_46 ( V_70 ) ;
V_75 = & V_10 -> V_75 ;
V_10 -> V_67 = V_67 ? F_58 ( V_67 , V_58 ) : NULL ;
F_59 ( & V_75 -> V_46 , F_60 ( V_70 ) ) ;
V_11 = F_61 ( V_75 , V_84 , 0 ,
F_62 ( V_81 -> type , V_81 -> V_86 ) ) ;
if ( V_11 )
goto V_87;
V_83 = F_63 ( V_75 ) ;
V_11 = - V_88 ;
if ( ! V_67 ) {
if ( snprintf ( V_70 -> V_89 . V_46 . V_90 ,
V_91 , L_1 ,
V_83 -> V_46 . V_90 ) >=
V_91 ||
snprintf ( V_70 -> V_89 . V_46 . V_92 ,
V_91 , L_1 ,
V_83 -> V_46 . V_92 ) >=
V_91 )
goto V_93;
} else {
if ( snprintf ( V_70 -> V_89 . V_46 . V_90 ,
V_91 , L_2 ,
V_83 -> V_46 . V_90 , V_67 ) >=
V_91 ||
snprintf ( V_70 -> V_89 . V_46 . V_92 ,
V_91 , L_2 ,
V_83 -> V_46 . V_92 , V_67 ) >=
V_91 )
goto V_94;
}
V_70 -> V_89 . V_46 . V_95 = V_83 -> V_46 . V_95 & V_96 ;
V_70 -> V_89 . V_46 . V_97 = V_83 -> V_46 . V_97 ;
V_70 -> V_89 . V_46 . V_98 = sizeof( struct V_9 ) ;
V_70 -> V_89 . V_99 = F_44 ;
V_70 -> V_89 . exit = F_50 ;
V_70 -> V_89 . V_100 = F_27 ;
V_70 -> V_89 . V_101 = F_36 ;
V_70 -> V_89 . V_102 = F_38 ;
V_70 -> V_89 . V_103 = F_42 ;
V_70 -> V_89 . V_104 = F_2 ;
V_70 -> V_89 . V_105 = F_6 ;
V_70 -> V_89 . V_106 = F_8 ;
V_70 -> V_89 . V_107 = sizeof( struct V_25 ) + V_83 -> V_107 ;
V_70 -> free = F_52 ;
V_11 = F_64 ( V_77 , V_70 ) ;
if ( V_11 )
goto V_94;
return 0 ;
V_94:
F_23 ( V_10 -> V_67 ) ;
V_93:
F_53 ( V_75 ) ;
V_87:
F_23 ( V_70 ) ;
return V_11 ;
}
