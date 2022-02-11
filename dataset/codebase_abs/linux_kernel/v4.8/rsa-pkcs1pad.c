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
int V_11 ;
V_10 -> V_12 = 0 ;
V_11 = F_4 ( V_10 -> V_13 , V_7 , V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 > V_14 )
return - V_15 ;
V_10 -> V_12 = V_11 ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , const void * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_11 ;
V_10 -> V_12 = 0 ;
V_11 = F_7 ( V_10 -> V_13 , V_7 , V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 > V_14 )
return - V_15 ;
V_10 -> V_12 = V_11 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
return V_10 -> V_12 ? : - V_16 ;
}
static void F_9 ( struct V_17 * V_18 , void * V_19 , T_1 V_20 ,
struct V_17 * V_21 )
{
int V_22 = V_21 ? 2 : 1 ;
F_10 ( V_18 , V_22 ) ;
F_11 ( V_18 , V_19 , V_20 ) ;
if ( V_21 )
F_12 ( V_18 , V_22 , V_21 ) ;
}
static int F_13 ( struct V_23 * V_24 , int V_11 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
unsigned int V_27 ;
unsigned int V_20 ;
T_2 * V_28 ;
if ( V_11 )
goto V_29;
V_20 = V_26 -> V_30 . V_31 ;
V_27 = V_10 -> V_12 - V_20 ;
if ( F_16 ( ! V_27 ) )
goto V_29;
V_28 = F_17 ( V_10 -> V_12 , V_32 ) ;
V_11 = - V_33 ;
if ( ! V_28 )
goto V_29;
F_18 ( V_24 -> V_34 , F_19 ( V_24 -> V_34 , V_20 ) ,
V_28 + V_27 , V_20 ) ;
F_20 ( V_24 -> V_34 ,
F_19 ( V_24 -> V_34 , V_10 -> V_12 ) ,
V_28 , V_10 -> V_12 ) ;
F_21 ( V_28 ) ;
V_29:
V_24 -> V_31 = V_10 -> V_12 ;
F_22 ( V_26 -> V_35 ) ;
return V_11 ;
}
static void F_23 (
struct V_36 * V_37 , int V_11 )
{
struct V_23 * V_24 = V_37 -> V_38 ;
struct V_36 V_39 ;
if ( V_11 == - V_40 )
return;
V_39 . V_38 = V_24 -> V_41 . V_38 ;
V_39 . V_6 = F_24 ( F_14 ( V_24 ) ) ;
V_39 . V_42 = V_37 -> V_42 ;
V_24 -> V_41 . V_43 ( & V_39 ,
F_13 ( V_24 , V_11 ) ) ;
}
static int F_25 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
int V_11 ;
unsigned int V_44 , V_45 ;
if ( ! V_10 -> V_12 )
return - V_16 ;
if ( V_24 -> V_46 > V_10 -> V_12 - 11 )
return - V_47 ;
if ( V_24 -> V_31 < V_10 -> V_12 ) {
V_24 -> V_31 = V_10 -> V_12 ;
return - V_47 ;
}
V_26 -> V_35 = F_26 ( V_10 -> V_12 - 1 - V_24 -> V_46 ,
V_48 ) ;
if ( ! V_26 -> V_35 )
return - V_33 ;
V_45 = V_10 -> V_12 - V_24 -> V_46 - 2 ;
V_26 -> V_35 [ 0 ] = 0x02 ;
for ( V_44 = 1 ; V_44 < V_45 ; V_44 ++ )
V_26 -> V_35 [ V_44 ] = 1 + F_27 ( 255 ) ;
V_26 -> V_35 [ V_45 ] = 0x00 ;
F_9 ( V_26 -> V_49 , V_26 -> V_35 ,
V_10 -> V_12 - 1 - V_24 -> V_46 , V_24 -> V_50 ) ;
V_26 -> V_28 = F_26 ( V_10 -> V_12 , V_48 ) ;
if ( ! V_26 -> V_28 ) {
F_22 ( V_26 -> V_35 ) ;
return - V_33 ;
}
F_9 ( V_26 -> V_51 , V_26 -> V_28 ,
V_10 -> V_12 , NULL ) ;
F_28 ( & V_26 -> V_30 , V_10 -> V_13 ) ;
F_29 ( & V_26 -> V_30 , V_24 -> V_41 . V_42 ,
F_23 , V_24 ) ;
F_30 ( & V_26 -> V_30 , V_26 -> V_49 ,
V_24 -> V_34 , V_10 -> V_12 - 1 , V_24 -> V_31 ) ;
V_11 = F_31 ( & V_26 -> V_30 ) ;
if ( V_11 != - V_40 &&
( V_11 != - V_52 ||
! ( V_24 -> V_41 . V_42 & V_53 ) ) )
return F_13 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_32 ( struct V_23 * V_24 , int V_11 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
unsigned int V_31 ;
unsigned int V_54 ;
T_2 * V_28 ;
if ( V_11 )
goto V_55;
V_11 = - V_16 ;
V_31 = V_26 -> V_30 . V_31 ;
if ( V_31 < V_10 -> V_12 - 1 )
goto V_55;
V_28 = V_26 -> V_28 ;
if ( V_31 == V_10 -> V_12 ) {
if ( V_28 [ 0 ] != 0x00 )
goto V_55;
V_31 -- ;
V_28 ++ ;
}
if ( V_28 [ 0 ] != 0x02 )
goto V_55;
for ( V_54 = 1 ; V_54 < V_31 ; V_54 ++ )
if ( V_28 [ V_54 ] == 0x00 )
break;
if ( V_54 < 9 || V_54 == V_31 )
goto V_55;
V_54 ++ ;
V_11 = 0 ;
if ( V_24 -> V_31 < V_31 - V_54 )
V_11 = - V_47 ;
V_24 -> V_31 = V_31 - V_54 ;
if ( ! V_11 )
F_20 ( V_24 -> V_34 ,
F_19 ( V_24 -> V_34 , V_24 -> V_31 ) ,
V_28 + V_54 , V_24 -> V_31 ) ;
V_55:
F_21 ( V_26 -> V_28 ) ;
return V_11 ;
}
static void F_33 (
struct V_36 * V_37 , int V_11 )
{
struct V_23 * V_24 = V_37 -> V_38 ;
struct V_36 V_39 ;
if ( V_11 == - V_40 )
return;
V_39 . V_38 = V_24 -> V_41 . V_38 ;
V_39 . V_6 = F_24 ( F_14 ( V_24 ) ) ;
V_39 . V_42 = V_37 -> V_42 ;
V_24 -> V_41 . V_43 ( & V_39 , F_32 ( V_24 , V_11 ) ) ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
int V_11 ;
if ( ! V_10 -> V_12 || V_24 -> V_46 != V_10 -> V_12 )
return - V_16 ;
V_26 -> V_28 = F_26 ( V_10 -> V_12 , V_48 ) ;
if ( ! V_26 -> V_28 )
return - V_33 ;
F_9 ( V_26 -> V_51 , V_26 -> V_28 ,
V_10 -> V_12 , NULL ) ;
F_28 ( & V_26 -> V_30 , V_10 -> V_13 ) ;
F_29 ( & V_26 -> V_30 , V_24 -> V_41 . V_42 ,
F_33 , V_24 ) ;
F_30 ( & V_26 -> V_30 , V_24 -> V_50 ,
V_26 -> V_51 , V_24 -> V_46 ,
V_10 -> V_12 ) ;
V_11 = F_35 ( & V_26 -> V_30 ) ;
if ( V_11 != - V_40 &&
( V_11 != - V_52 ||
! ( V_24 -> V_41 . V_42 & V_53 ) ) )
return F_32 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_36 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
struct V_56 * V_57 = F_37 ( V_6 ) ;
struct V_58 * V_59 = F_38 ( V_57 ) ;
const struct V_1 * V_60 = V_59 -> V_60 ;
int V_11 ;
unsigned int V_45 , V_61 = 0 ;
if ( ! V_10 -> V_12 )
return - V_16 ;
V_61 = V_60 -> V_62 ;
if ( V_24 -> V_46 + V_61 > V_10 -> V_12 - 11 )
return - V_47 ;
if ( V_24 -> V_31 < V_10 -> V_12 ) {
V_24 -> V_31 = V_10 -> V_12 ;
return - V_47 ;
}
V_26 -> V_35 = F_26 ( V_10 -> V_12 - 1 - V_24 -> V_46 ,
V_48 ) ;
if ( ! V_26 -> V_35 )
return - V_33 ;
V_45 = V_10 -> V_12 - V_61 - V_24 -> V_46 - 2 ;
V_26 -> V_35 [ 0 ] = 0x01 ;
memset ( V_26 -> V_35 + 1 , 0xff , V_45 - 1 ) ;
V_26 -> V_35 [ V_45 ] = 0x00 ;
memcpy ( V_26 -> V_35 + V_45 + 1 , V_60 -> V_38 ,
V_60 -> V_62 ) ;
F_9 ( V_26 -> V_49 , V_26 -> V_35 ,
V_10 -> V_12 - 1 - V_24 -> V_46 , V_24 -> V_50 ) ;
F_28 ( & V_26 -> V_30 , V_10 -> V_13 ) ;
F_29 ( & V_26 -> V_30 , V_24 -> V_41 . V_42 ,
F_23 , V_24 ) ;
F_30 ( & V_26 -> V_30 , V_26 -> V_49 ,
V_24 -> V_34 , V_10 -> V_12 - 1 , V_24 -> V_31 ) ;
V_11 = F_39 ( & V_26 -> V_30 ) ;
if ( V_11 != - V_40 &&
( V_11 != - V_52 ||
! ( V_24 -> V_41 . V_42 & V_53 ) ) )
return F_13 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_40 ( struct V_23 * V_24 , int V_11 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
struct V_56 * V_57 = F_37 ( V_6 ) ;
struct V_58 * V_59 = F_38 ( V_57 ) ;
const struct V_1 * V_60 = V_59 -> V_60 ;
unsigned int V_31 ;
unsigned int V_54 ;
T_2 * V_28 ;
if ( V_11 )
goto V_55;
V_11 = - V_16 ;
V_31 = V_26 -> V_30 . V_31 ;
if ( V_31 < V_10 -> V_12 - 1 )
goto V_55;
V_28 = V_26 -> V_28 ;
if ( V_31 == V_10 -> V_12 ) {
if ( V_28 [ 0 ] != 0x00 )
goto V_55;
V_31 -- ;
V_28 ++ ;
}
V_11 = - V_63 ;
if ( V_28 [ 0 ] != 0x01 )
goto V_55;
for ( V_54 = 1 ; V_54 < V_31 ; V_54 ++ )
if ( V_28 [ V_54 ] != 0xff )
break;
if ( V_54 < 9 || V_54 == V_31 || V_28 [ V_54 ] != 0x00 )
goto V_55;
V_54 ++ ;
if ( memcmp ( V_28 + V_54 , V_60 -> V_38 , V_60 -> V_62 ) )
goto V_55;
V_54 += V_60 -> V_62 ;
V_11 = 0 ;
if ( V_24 -> V_31 < V_31 - V_54 )
V_11 = - V_47 ;
V_24 -> V_31 = V_31 - V_54 ;
if ( ! V_11 )
F_20 ( V_24 -> V_34 ,
F_19 ( V_24 -> V_34 , V_24 -> V_31 ) ,
V_28 + V_54 , V_24 -> V_31 ) ;
V_55:
F_21 ( V_26 -> V_28 ) ;
return V_11 ;
}
static void F_41 (
struct V_36 * V_37 , int V_11 )
{
struct V_23 * V_24 = V_37 -> V_38 ;
struct V_36 V_39 ;
if ( V_11 == - V_40 )
return;
V_39 . V_38 = V_24 -> V_41 . V_38 ;
V_39 . V_6 = F_24 ( F_14 ( V_24 ) ) ;
V_39 . V_42 = V_37 -> V_42 ;
V_24 -> V_41 . V_43 ( & V_39 , F_40 ( V_24 , V_11 ) ) ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_14 ( V_24 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_25 * V_26 = F_15 ( V_24 ) ;
int V_11 ;
if ( ! V_10 -> V_12 || V_24 -> V_46 < V_10 -> V_12 )
return - V_16 ;
V_26 -> V_28 = F_26 ( V_10 -> V_12 , V_48 ) ;
if ( ! V_26 -> V_28 )
return - V_33 ;
F_9 ( V_26 -> V_51 , V_26 -> V_28 ,
V_10 -> V_12 , NULL ) ;
F_28 ( & V_26 -> V_30 , V_10 -> V_13 ) ;
F_29 ( & V_26 -> V_30 , V_24 -> V_41 . V_42 ,
F_41 , V_24 ) ;
F_30 ( & V_26 -> V_30 , V_24 -> V_50 ,
V_26 -> V_51 , V_24 -> V_46 ,
V_10 -> V_12 ) ;
V_11 = F_43 ( & V_26 -> V_30 ) ;
if ( V_11 != - V_40 &&
( V_11 != - V_52 ||
! ( V_24 -> V_41 . V_42 & V_53 ) ) )
return F_40 ( V_24 , V_11 ) ;
return V_11 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = F_37 ( V_6 ) ;
struct V_58 * V_59 = F_38 ( V_57 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_5 * V_64 ;
V_64 = F_45 ( & V_59 -> V_65 ) ;
if ( F_46 ( V_64 ) )
return F_47 ( V_64 ) ;
V_10 -> V_13 = V_64 ;
return 0 ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
F_49 ( V_10 -> V_13 ) ;
}
static void F_50 ( struct V_56 * V_57 )
{
struct V_58 * V_10 = F_38 ( V_57 ) ;
struct V_66 * V_65 = & V_10 -> V_65 ;
F_51 ( V_65 ) ;
F_22 ( V_57 ) ;
}
static int F_52 ( struct V_67 * V_68 , struct V_69 * * V_70 )
{
const struct V_1 * V_60 ;
struct V_71 * V_72 ;
struct V_56 * V_57 ;
struct V_58 * V_10 ;
struct V_66 * V_65 ;
struct V_73 * V_74 ;
const char * V_75 ;
const char * V_76 ;
int V_11 ;
V_72 = F_53 ( V_70 ) ;
if ( F_46 ( V_72 ) )
return F_47 ( V_72 ) ;
if ( ( V_72 -> type ^ V_77 ) & V_72 -> V_78 )
return - V_16 ;
V_75 = F_54 ( V_70 [ 1 ] ) ;
if ( F_46 ( V_75 ) )
return F_47 ( V_75 ) ;
V_76 = F_54 ( V_70 [ 2 ] ) ;
if ( F_46 ( V_76 ) )
return F_47 ( V_76 ) ;
V_60 = F_1 ( V_76 ) ;
if ( ! V_60 )
return - V_16 ;
V_57 = F_17 ( sizeof( * V_57 ) + sizeof( * V_10 ) , V_48 ) ;
if ( ! V_57 )
return - V_33 ;
V_10 = F_38 ( V_57 ) ;
V_65 = & V_10 -> V_65 ;
V_10 -> V_60 = V_60 ;
F_55 ( & V_65 -> V_41 , F_56 ( V_57 ) ) ;
V_11 = F_57 ( V_65 , V_75 , 0 ,
F_58 ( V_72 -> type , V_72 -> V_78 ) ) ;
if ( V_11 )
goto V_79;
V_74 = F_59 ( V_65 ) ;
V_11 = - V_80 ;
if ( snprintf ( V_57 -> V_81 . V_41 . V_82 , V_83 ,
L_1 , V_74 -> V_41 . V_82 , V_76 ) >=
V_83 ||
snprintf ( V_57 -> V_81 . V_41 . V_84 , V_83 ,
L_1 ,
V_74 -> V_41 . V_84 , V_76 ) >=
V_83 )
goto V_85;
V_57 -> V_81 . V_41 . V_86 = V_74 -> V_41 . V_86 & V_87 ;
V_57 -> V_81 . V_41 . V_88 = V_74 -> V_41 . V_88 ;
V_57 -> V_81 . V_41 . V_89 = sizeof( struct V_9 ) ;
V_57 -> V_81 . V_90 = F_44 ;
V_57 -> V_81 . exit = F_48 ;
V_57 -> V_81 . V_91 = F_25 ;
V_57 -> V_81 . V_92 = F_34 ;
V_57 -> V_81 . V_93 = F_36 ;
V_57 -> V_81 . V_94 = F_42 ;
V_57 -> V_81 . V_95 = F_2 ;
V_57 -> V_81 . V_96 = F_6 ;
V_57 -> V_81 . V_97 = F_8 ;
V_57 -> V_81 . V_98 = sizeof( struct V_25 ) + V_74 -> V_98 ;
V_57 -> free = F_50 ;
V_11 = F_60 ( V_68 , V_57 ) ;
if ( V_11 )
goto V_85;
return 0 ;
V_85:
F_51 ( V_65 ) ;
V_79:
F_22 ( V_57 ) ;
return V_11 ;
}
