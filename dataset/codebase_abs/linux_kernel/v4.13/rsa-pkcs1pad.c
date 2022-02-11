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
if ( V_11 > V_14 )
return - V_15 ;
V_10 -> V_12 = V_11 ;
return 0 ;
}
static unsigned int F_8 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
return V_10 -> V_12 ;
}
static void F_9 ( struct V_16 * V_17 , void * V_18 , T_1 V_19 ,
struct V_16 * V_20 )
{
int V_21 = V_20 ? 2 : 1 ;
F_10 ( V_17 , V_21 ) ;
F_11 ( V_17 , V_18 , V_19 ) ;
if ( V_20 )
F_12 ( V_17 , V_21 , V_20 ) ;
}
static int F_13 ( struct V_22 * V_23 , int V_11 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
unsigned int V_26 ;
unsigned int V_19 ;
T_2 * V_27 ;
if ( V_11 )
goto V_28;
V_19 = V_25 -> V_29 . V_30 ;
V_26 = V_10 -> V_12 - V_19 ;
if ( F_16 ( ! V_26 ) )
goto V_28;
V_27 = F_17 ( V_10 -> V_12 , V_31 ) ;
V_11 = - V_32 ;
if ( ! V_27 )
goto V_28;
F_18 ( V_23 -> V_33 , F_19 ( V_23 -> V_33 , V_19 ) ,
V_27 + V_26 , V_19 ) ;
F_20 ( V_23 -> V_33 ,
F_19 ( V_23 -> V_33 , V_10 -> V_12 ) ,
V_27 , V_10 -> V_12 ) ;
F_21 ( V_27 ) ;
V_28:
V_23 -> V_30 = V_10 -> V_12 ;
F_22 ( V_25 -> V_34 ) ;
return V_11 ;
}
static void F_23 (
struct V_35 * V_36 , int V_11 )
{
struct V_22 * V_23 = V_36 -> V_37 ;
struct V_35 V_38 ;
if ( V_11 == - V_39 )
return;
V_38 . V_37 = V_23 -> V_40 . V_37 ;
V_38 . V_6 = F_24 ( F_14 ( V_23 ) ) ;
V_38 . V_41 = V_36 -> V_41 ;
V_23 -> V_40 . V_42 ( & V_38 ,
F_13 ( V_23 , V_11 ) ) ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
int V_11 ;
unsigned int V_43 , V_44 ;
if ( ! V_10 -> V_12 )
return - V_45 ;
if ( V_23 -> V_46 > V_10 -> V_12 - 11 )
return - V_47 ;
if ( V_23 -> V_30 < V_10 -> V_12 ) {
V_23 -> V_30 = V_10 -> V_12 ;
return - V_47 ;
}
V_25 -> V_34 = F_26 ( V_10 -> V_12 - 1 - V_23 -> V_46 ,
V_48 ) ;
if ( ! V_25 -> V_34 )
return - V_32 ;
V_44 = V_10 -> V_12 - V_23 -> V_46 - 2 ;
V_25 -> V_34 [ 0 ] = 0x02 ;
for ( V_43 = 1 ; V_43 < V_44 ; V_43 ++ )
V_25 -> V_34 [ V_43 ] = 1 + F_27 ( 255 ) ;
V_25 -> V_34 [ V_44 ] = 0x00 ;
F_9 ( V_25 -> V_49 , V_25 -> V_34 ,
V_10 -> V_12 - 1 - V_23 -> V_46 , V_23 -> V_50 ) ;
V_25 -> V_27 = F_26 ( V_10 -> V_12 , V_48 ) ;
if ( ! V_25 -> V_27 ) {
F_22 ( V_25 -> V_34 ) ;
return - V_32 ;
}
F_9 ( V_25 -> V_51 , V_25 -> V_27 ,
V_10 -> V_12 , NULL ) ;
F_28 ( & V_25 -> V_29 , V_10 -> V_13 ) ;
F_29 ( & V_25 -> V_29 , V_23 -> V_40 . V_41 ,
F_23 , V_23 ) ;
F_30 ( & V_25 -> V_29 , V_25 -> V_49 ,
V_23 -> V_33 , V_10 -> V_12 - 1 , V_23 -> V_30 ) ;
V_11 = F_31 ( & V_25 -> V_29 ) ;
if ( V_11 != - V_39 &&
( V_11 != - V_52 ||
! ( V_23 -> V_40 . V_41 & V_53 ) ) )
return F_13 ( V_23 , V_11 ) ;
return V_11 ;
}
static int F_32 ( struct V_22 * V_23 , int V_11 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
unsigned int V_30 ;
unsigned int V_54 ;
T_2 * V_27 ;
if ( V_11 )
goto V_55;
V_11 = - V_45 ;
V_30 = V_25 -> V_29 . V_30 ;
if ( V_30 < V_10 -> V_12 - 1 )
goto V_55;
V_27 = V_25 -> V_27 ;
if ( V_30 == V_10 -> V_12 ) {
if ( V_27 [ 0 ] != 0x00 )
goto V_55;
V_30 -- ;
V_27 ++ ;
}
if ( V_27 [ 0 ] != 0x02 )
goto V_55;
for ( V_54 = 1 ; V_54 < V_30 ; V_54 ++ )
if ( V_27 [ V_54 ] == 0x00 )
break;
if ( V_54 < 9 || V_54 == V_30 )
goto V_55;
V_54 ++ ;
V_11 = 0 ;
if ( V_23 -> V_30 < V_30 - V_54 )
V_11 = - V_47 ;
V_23 -> V_30 = V_30 - V_54 ;
if ( ! V_11 )
F_20 ( V_23 -> V_33 ,
F_19 ( V_23 -> V_33 , V_23 -> V_30 ) ,
V_27 + V_54 , V_23 -> V_30 ) ;
V_55:
F_21 ( V_25 -> V_27 ) ;
return V_11 ;
}
static void F_33 (
struct V_35 * V_36 , int V_11 )
{
struct V_22 * V_23 = V_36 -> V_37 ;
struct V_35 V_38 ;
if ( V_11 == - V_39 )
return;
V_38 . V_37 = V_23 -> V_40 . V_37 ;
V_38 . V_6 = F_24 ( F_14 ( V_23 ) ) ;
V_38 . V_41 = V_36 -> V_41 ;
V_23 -> V_40 . V_42 ( & V_38 , F_32 ( V_23 , V_11 ) ) ;
}
static int F_34 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
int V_11 ;
if ( ! V_10 -> V_12 || V_23 -> V_46 != V_10 -> V_12 )
return - V_45 ;
V_25 -> V_27 = F_26 ( V_10 -> V_12 , V_48 ) ;
if ( ! V_25 -> V_27 )
return - V_32 ;
F_9 ( V_25 -> V_51 , V_25 -> V_27 ,
V_10 -> V_12 , NULL ) ;
F_28 ( & V_25 -> V_29 , V_10 -> V_13 ) ;
F_29 ( & V_25 -> V_29 , V_23 -> V_40 . V_41 ,
F_33 , V_23 ) ;
F_30 ( & V_25 -> V_29 , V_23 -> V_50 ,
V_25 -> V_51 , V_23 -> V_46 ,
V_10 -> V_12 ) ;
V_11 = F_35 ( & V_25 -> V_29 ) ;
if ( V_11 != - V_39 &&
( V_11 != - V_52 ||
! ( V_23 -> V_40 . V_41 & V_53 ) ) )
return F_32 ( V_23 , V_11 ) ;
return V_11 ;
}
static int F_36 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
struct V_56 * V_57 = F_37 ( V_6 ) ;
struct V_58 * V_59 = F_38 ( V_57 ) ;
const struct V_1 * V_60 = V_59 -> V_60 ;
int V_11 ;
unsigned int V_44 , V_61 = 0 ;
if ( ! V_10 -> V_12 )
return - V_45 ;
V_61 = V_60 -> V_62 ;
if ( V_23 -> V_46 + V_61 > V_10 -> V_12 - 11 )
return - V_47 ;
if ( V_23 -> V_30 < V_10 -> V_12 ) {
V_23 -> V_30 = V_10 -> V_12 ;
return - V_47 ;
}
V_25 -> V_34 = F_26 ( V_10 -> V_12 - 1 - V_23 -> V_46 ,
V_48 ) ;
if ( ! V_25 -> V_34 )
return - V_32 ;
V_44 = V_10 -> V_12 - V_61 - V_23 -> V_46 - 2 ;
V_25 -> V_34 [ 0 ] = 0x01 ;
memset ( V_25 -> V_34 + 1 , 0xff , V_44 - 1 ) ;
V_25 -> V_34 [ V_44 ] = 0x00 ;
memcpy ( V_25 -> V_34 + V_44 + 1 , V_60 -> V_37 ,
V_60 -> V_62 ) ;
F_9 ( V_25 -> V_49 , V_25 -> V_34 ,
V_10 -> V_12 - 1 - V_23 -> V_46 , V_23 -> V_50 ) ;
F_28 ( & V_25 -> V_29 , V_10 -> V_13 ) ;
F_29 ( & V_25 -> V_29 , V_23 -> V_40 . V_41 ,
F_23 , V_23 ) ;
F_30 ( & V_25 -> V_29 , V_25 -> V_49 ,
V_23 -> V_33 , V_10 -> V_12 - 1 , V_23 -> V_30 ) ;
V_11 = F_39 ( & V_25 -> V_29 ) ;
if ( V_11 != - V_39 &&
( V_11 != - V_52 ||
! ( V_23 -> V_40 . V_41 & V_53 ) ) )
return F_13 ( V_23 , V_11 ) ;
return V_11 ;
}
static int F_40 ( struct V_22 * V_23 , int V_11 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
struct V_56 * V_57 = F_37 ( V_6 ) ;
struct V_58 * V_59 = F_38 ( V_57 ) ;
const struct V_1 * V_60 = V_59 -> V_60 ;
unsigned int V_30 ;
unsigned int V_54 ;
T_2 * V_27 ;
if ( V_11 )
goto V_55;
V_11 = - V_45 ;
V_30 = V_25 -> V_29 . V_30 ;
if ( V_30 < V_10 -> V_12 - 1 )
goto V_55;
V_27 = V_25 -> V_27 ;
if ( V_30 == V_10 -> V_12 ) {
if ( V_27 [ 0 ] != 0x00 )
goto V_55;
V_30 -- ;
V_27 ++ ;
}
V_11 = - V_63 ;
if ( V_27 [ 0 ] != 0x01 )
goto V_55;
for ( V_54 = 1 ; V_54 < V_30 ; V_54 ++ )
if ( V_27 [ V_54 ] != 0xff )
break;
if ( V_54 < 9 || V_54 == V_30 || V_27 [ V_54 ] != 0x00 )
goto V_55;
V_54 ++ ;
if ( F_41 ( V_27 + V_54 , V_60 -> V_37 , V_60 -> V_62 ) )
goto V_55;
V_54 += V_60 -> V_62 ;
V_11 = 0 ;
if ( V_23 -> V_30 < V_30 - V_54 )
V_11 = - V_47 ;
V_23 -> V_30 = V_30 - V_54 ;
if ( ! V_11 )
F_20 ( V_23 -> V_33 ,
F_19 ( V_23 -> V_33 , V_23 -> V_30 ) ,
V_27 + V_54 , V_23 -> V_30 ) ;
V_55:
F_21 ( V_25 -> V_27 ) ;
return V_11 ;
}
static void F_42 (
struct V_35 * V_36 , int V_11 )
{
struct V_22 * V_23 = V_36 -> V_37 ;
struct V_35 V_38 ;
if ( V_11 == - V_39 )
return;
V_38 . V_37 = V_23 -> V_40 . V_37 ;
V_38 . V_6 = F_24 ( F_14 ( V_23 ) ) ;
V_38 . V_41 = V_36 -> V_41 ;
V_23 -> V_40 . V_42 ( & V_38 , F_40 ( V_23 , V_11 ) ) ;
}
static int F_43 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_24 * V_25 = F_15 ( V_23 ) ;
int V_11 ;
if ( ! V_10 -> V_12 || V_23 -> V_46 < V_10 -> V_12 )
return - V_45 ;
V_25 -> V_27 = F_26 ( V_10 -> V_12 , V_48 ) ;
if ( ! V_25 -> V_27 )
return - V_32 ;
F_9 ( V_25 -> V_51 , V_25 -> V_27 ,
V_10 -> V_12 , NULL ) ;
F_28 ( & V_25 -> V_29 , V_10 -> V_13 ) ;
F_29 ( & V_25 -> V_29 , V_23 -> V_40 . V_41 ,
F_42 , V_23 ) ;
F_30 ( & V_25 -> V_29 , V_23 -> V_50 ,
V_25 -> V_51 , V_23 -> V_46 ,
V_10 -> V_12 ) ;
V_11 = F_44 ( & V_25 -> V_29 ) ;
if ( V_11 != - V_39 &&
( V_11 != - V_52 ||
! ( V_23 -> V_40 . V_41 & V_53 ) ) )
return F_40 ( V_23 , V_11 ) ;
return V_11 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = F_37 ( V_6 ) ;
struct V_58 * V_59 = F_38 ( V_57 ) ;
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_5 * V_64 ;
V_64 = F_46 ( & V_59 -> V_65 ) ;
if ( F_47 ( V_64 ) )
return F_48 ( V_64 ) ;
V_10 -> V_13 = V_64 ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
F_50 ( V_10 -> V_13 ) ;
}
static void F_51 ( struct V_56 * V_57 )
{
struct V_58 * V_10 = F_38 ( V_57 ) ;
struct V_66 * V_65 = & V_10 -> V_65 ;
F_52 ( V_65 ) ;
F_22 ( V_57 ) ;
}
static int F_53 ( struct V_67 * V_68 , struct V_69 * * V_70 )
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
V_72 = F_54 ( V_70 ) ;
if ( F_47 ( V_72 ) )
return F_48 ( V_72 ) ;
if ( ( V_72 -> type ^ V_77 ) & V_72 -> V_78 )
return - V_45 ;
V_75 = F_55 ( V_70 [ 1 ] ) ;
if ( F_47 ( V_75 ) )
return F_48 ( V_75 ) ;
V_76 = F_55 ( V_70 [ 2 ] ) ;
if ( F_47 ( V_76 ) )
return F_48 ( V_76 ) ;
V_60 = F_1 ( V_76 ) ;
if ( ! V_60 )
return - V_45 ;
V_57 = F_17 ( sizeof( * V_57 ) + sizeof( * V_10 ) , V_48 ) ;
if ( ! V_57 )
return - V_32 ;
V_10 = F_38 ( V_57 ) ;
V_65 = & V_10 -> V_65 ;
V_10 -> V_60 = V_60 ;
F_56 ( & V_65 -> V_40 , F_57 ( V_57 ) ) ;
V_11 = F_58 ( V_65 , V_75 , 0 ,
F_59 ( V_72 -> type , V_72 -> V_78 ) ) ;
if ( V_11 )
goto V_79;
V_74 = F_60 ( V_65 ) ;
V_11 = - V_80 ;
if ( snprintf ( V_57 -> V_81 . V_40 . V_82 , V_83 ,
L_1 , V_74 -> V_40 . V_82 , V_76 ) >=
V_83 ||
snprintf ( V_57 -> V_81 . V_40 . V_84 , V_83 ,
L_1 ,
V_74 -> V_40 . V_84 , V_76 ) >=
V_83 )
goto V_85;
V_57 -> V_81 . V_40 . V_86 = V_74 -> V_40 . V_86 & V_87 ;
V_57 -> V_81 . V_40 . V_88 = V_74 -> V_40 . V_88 ;
V_57 -> V_81 . V_40 . V_89 = sizeof( struct V_9 ) ;
V_57 -> V_81 . V_90 = F_45 ;
V_57 -> V_81 . exit = F_49 ;
V_57 -> V_81 . V_91 = F_25 ;
V_57 -> V_81 . V_92 = F_34 ;
V_57 -> V_81 . V_93 = F_36 ;
V_57 -> V_81 . V_94 = F_43 ;
V_57 -> V_81 . V_95 = F_2 ;
V_57 -> V_81 . V_96 = F_6 ;
V_57 -> V_81 . V_97 = F_8 ;
V_57 -> V_81 . V_98 = sizeof( struct V_24 ) + V_74 -> V_98 ;
V_57 -> free = F_51 ;
V_11 = F_61 ( V_68 , V_57 ) ;
if ( V_11 )
goto V_85;
return 0 ;
V_85:
F_52 ( V_65 ) ;
V_79:
F_22 ( V_57 ) ;
return V_11 ;
}
