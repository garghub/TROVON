static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
V_4 = (struct V_1 * ) V_3 -> V_7 [ V_6 - 1 ] ;
if ( V_4 )
F_3 ( & V_4 -> V_8 ) ;
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 )
{
if ( F_6 ( & V_4 -> V_8 ) ) {
F_7 ( V_9 , L_1 ) ;
F_8 ( V_4 ) ;
}
}
static int F_9 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
struct V_13 * V_14 = F_10 ( V_10 -> V_15 , struct V_13 , V_16 ) ;
F_7 ( V_9 , L_2 , F_11 ( V_10 ) , F_12 ( V_10 ) ) ;
V_12 -> V_17 = V_14 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
return 0 ;
}
static T_1 F_14 ( struct V_11 * V_12 , char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
int V_21 ;
int V_22 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_2 ( & V_23 . V_24 ) ;
V_3 = V_23 . V_25 ;
if ( V_3 )
F_15 ( V_3 ) ;
F_4 ( & V_23 . V_24 ) ;
if ( V_3 == NULL )
return - 1 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_26;
V_21 = V_4 -> V_27 - V_4 -> V_28 ;
if ( V_21 < 0 )
V_21 += V_29 ;
if ( V_19 > V_21 )
V_19 = V_21 ;
V_22 = V_4 -> V_28 ;
V_21 = V_29 - V_22 ;
if ( V_21 > V_19 )
V_21 = V_19 ;
if ( F_16 ( V_18 , & V_4 -> V_30 [ V_22 ] , V_21 ) ) {
V_19 = 0 ;
goto V_31;
}
V_22 += V_21 ;
if ( V_22 == V_29 )
V_22 = 0 ;
if ( V_21 < V_19 ) {
if ( F_16 ( & V_18 [ V_21 ] , V_4 -> V_30 , V_19 - V_21 ) ) {
V_19 = 0 ;
goto V_31;
}
V_22 = V_19 - V_21 ;
}
V_4 -> V_28 = V_22 ;
V_31:
F_5 ( V_4 ) ;
V_26:
F_17 ( V_3 ) ;
return V_19 ;
}
static T_1 F_18 ( struct V_11 * V_12 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_4 ;
if ( V_19 > sizeof( V_35 -> V_40 ) - sizeof( * V_37 ) - sizeof( * V_39 ) )
return - V_41 ;
F_2 ( & V_23 . V_24 ) ;
V_3 = V_23 . V_25 ;
if ( V_3 )
F_15 ( V_3 ) ;
F_4 ( & V_23 . V_24 ) ;
if ( V_3 == NULL )
return - V_42 ;
if ( ! ( V_3 -> V_43 & V_44 ) )
return - V_45 ;
V_33 = & V_3 -> V_46 ;
V_35 = F_19 ( V_33 ) ;
if ( V_35 == NULL ) {
V_19 = 0 ;
goto V_47;
}
V_37 = (struct V_36 * ) V_35 -> V_40 ;
V_39 = (struct V_38 * ) ( V_37 + 1 ) ;
V_37 -> V_48 = sizeof( struct V_38 ) + V_19 ;
V_37 -> type = V_49 ;
V_35 -> V_50 = V_6 ;
V_35 -> V_48 = V_37 -> V_48 + sizeof( struct V_36 ) ;
V_39 -> V_50 = V_6 ;
if ( F_20 ( V_39 + 1 , V_18 , V_19 ) )
goto V_47;
F_2 ( & V_3 -> V_5 [ V_51 - 1 ] ) ;
V_4 = (struct V_1 * ) V_3 -> V_7 [ V_6 - 1 ] ;
if ( V_4 ) {
V_39 -> V_52 = V_4 -> V_53 ++ ;
if ( V_4 -> V_53 == 0 )
V_4 -> V_53 = 1 ;
F_21 ( & V_33 -> V_24 ) ;
if ( F_22 ( V_33 , 0 , 0 , V_35 ) == 0 )
V_35 = NULL ;
F_23 ( & V_33 -> V_24 ) ;
}
F_4 ( & V_3 -> V_5 [ V_51 - 1 ] ) ;
V_47:
if ( V_35 ) {
V_19 = 0 ;
F_2 ( & V_33 -> V_24 ) ;
F_24 ( V_33 , V_35 ) ;
F_4 ( & V_33 -> V_24 ) ;
}
F_17 ( V_3 ) ;
return V_19 ;
}
static int F_25 ( const T_5 * V_54 )
{
int V_55 = 0 ;
struct V_2 * V_3 ;
struct V_2 * V_56 ;
V_3 = F_26 ( V_54 ) ;
if ( V_3 ) {
F_2 ( & V_23 . V_24 ) ;
memcpy ( V_23 . V_57 , V_54 , V_58 ) ;
V_56 = V_23 . V_25 ;
V_23 . V_25 = V_3 ;
F_4 ( & V_23 . V_24 ) ;
if ( V_56 )
F_17 ( V_56 ) ;
} else {
if ( F_27 ( V_54 ) ) {
F_2 ( & V_23 . V_24 ) ;
V_3 = V_23 . V_25 ;
V_23 . V_25 = NULL ;
memset ( V_23 . V_57 , 0 ,
sizeof( V_23 . V_57 ) ) ;
F_4 ( & V_23 . V_24 ) ;
if ( V_3 )
F_17 ( V_3 ) ;
} else {
V_55 = - 1 ;
}
}
return V_55 ;
}
static long F_28 ( struct V_11 * V_12 , unsigned int V_59 ,
unsigned long V_60 )
{
int V_55 = 0 ;
if ( F_29 ( V_59 ) != V_61 )
return - V_62 ;
if ( F_30 ( V_59 ) > V_63 )
return - V_62 ;
if ( F_31 ( V_59 ) & V_64 )
V_55 = ! F_32 ( V_65 , ( void T_2 * ) V_60 ,
F_33 ( V_59 ) ) ;
else if ( F_31 ( V_59 ) & V_66 )
V_55 = ! F_32 ( V_67 , ( void T_2 * ) V_60 ,
F_33 ( V_59 ) ) ;
if ( V_55 )
return - V_68 ;
switch ( V_59 ) {
case V_69 : {
struct V_70 V_71 ;
F_7 ( V_9 , L_3 ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_19 = F_34 ( V_71 . V_54 , V_72 ) ;
if ( F_16 ( ( void T_2 * ) V_60 , & V_71 ,
sizeof( V_71 ) ) )
return - V_68 ;
}
break;
case V_73 : {
T_5 V_54 [ V_58 ] ;
F_7 ( V_9 , L_4 ) ;
if ( F_20 ( V_54 , ( void T_2 * ) V_60 , V_58 ) )
return - V_68 ;
V_55 = F_25 ( V_54 ) ;
}
break;
case V_74 : {
T_5 V_54 [ V_58 ] ;
F_7 ( V_9 , L_5 ) ;
F_2 ( & V_23 . V_24 ) ;
memcpy ( V_54 , V_23 . V_57 , V_58 ) ;
F_4 ( & V_23 . V_24 ) ;
if ( F_16 ( ( void T_2 * ) V_60 , V_54 , V_58 ) )
return - V_68 ;
}
break;
case V_75 :
case V_76 : {
struct V_77 V_78 ;
if ( F_20 ( & V_78 , ( void T_2 * ) V_60 ,
sizeof( struct V_77 ) ) ) {
return - V_68 ;
}
V_78 . V_79 [ V_80 - 1 ] = 0 ;
if ( V_59 == V_75 )
F_35 ( V_78 . V_79 ) ;
else
F_36 ( V_78 . V_79 ) ;
}
break;
}
return V_55 ;
}
static unsigned int F_37 ( struct V_11 * V_12 , T_6 * V_81 )
{
unsigned int V_82 = 0 ;
struct V_13 * V_14 = V_12 -> V_17 ;
F_7 ( V_9 , L_6 , V_81 ) ;
F_2 ( & V_14 -> V_24 ) ;
if ( V_14 -> V_25 ) {
struct V_1 * V_4 = F_1 ( V_14 -> V_25 ) ;
if ( V_4 ) {
if ( V_4 -> V_27 != V_4 -> V_28 )
V_82 |= V_83 | V_84 ;
F_5 ( V_4 ) ;
}
}
F_4 ( & V_14 -> V_24 ) ;
if ( V_81 )
F_38 ( V_12 , & V_14 -> V_85 , V_81 ) ;
return V_82 ;
}
int F_39 ( void )
{
int V_86 ;
struct V_87 * V_14 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_86 = F_40 ( & V_23 . V_88 , 0 , 1 , L_7 ) ;
if ( V_86 < 0 )
return V_86 ;
F_7 ( V_9 , L_8 ,
F_41 ( V_23 . V_88 ) , F_42 ( V_23 . V_88 ) ) ;
F_43 ( & V_23 . V_16 , & V_89 ) ;
V_23 . V_16 . V_90 = V_91 ;
V_23 . V_16 . V_92 = & V_89 ;
F_44 ( & V_23 . V_24 ) ;
F_45 ( & V_23 . V_85 ) ;
V_86 = F_46 ( & V_23 . V_16 , V_23 . V_88 , 1 ) ;
if ( V_86 < 0 ) {
F_7 ( V_9 , L_9 ) ;
goto V_93;
}
V_94 = F_47 ( V_91 , L_10 ) ;
if ( F_48 ( V_94 ) ) {
F_7 ( V_9 , L_11 ) ;
V_86 = F_49 ( V_94 ) ;
goto V_95;
}
V_14 = F_50 ( V_94 , NULL , V_23 . V_88 , NULL , L_7 ) ;
if ( F_48 ( V_14 ) ) {
F_7 ( V_9 , L_12 ) ;
V_86 = F_49 ( V_14 ) ;
goto V_95;
}
return 0 ;
V_95:
F_51 ( & V_23 . V_16 ) ;
V_93:
F_52 ( V_23 . V_88 , 1 ) ;
return V_86 ;
}
int F_53 ( void )
{
F_51 ( & V_23 . V_16 ) ;
F_52 ( V_23 . V_88 , 1 ) ;
if ( V_94 ) {
F_54 ( V_94 , V_23 . V_88 ) ;
F_55 ( V_94 ) ;
}
return 0 ;
}
int F_56 ( void )
{
F_57 ( V_6 , 1 ) ;
return 0 ;
}
void F_58 ( void )
{
F_57 ( V_6 , 0 ) ;
}
int F_59 ( struct V_2 * V_3 , int V_96 )
{
struct V_1 * V_4 ;
struct V_1 * V_97 ;
if ( V_96 ) {
F_7 ( V_9 , L_13 ) ;
return 0 ;
}
V_4 = F_60 ( sizeof( struct V_1 ) , V_98 ) ;
if ( V_4 == NULL )
return - V_99 ;
F_61 ( & V_4 -> V_8 , 1 ) ;
V_4 -> V_53 = 1 ;
F_2 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
V_97 = V_3 -> V_7 [ V_6 - 1 ] ;
if ( V_97 ) {
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
F_8 ( V_4 ) ;
} else {
V_3 -> V_7 [ V_6 - 1 ] = V_4 ;
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
}
F_21 ( & V_23 . V_24 ) ;
if ( ( V_23 . V_25 == NULL ) &&
( memcmp ( V_3 -> V_100 , V_23 . V_57 , V_58 ) == 0 ) ) {
F_15 ( V_3 ) ;
V_23 . V_25 = V_3 ;
F_7 ( V_9 , L_14 ) ;
}
F_23 ( & V_23 . V_24 ) ;
F_7 ( V_9 , L_15 ) ;
return 0 ;
}
void F_62 ( struct V_2 * V_3 , int V_101 )
{
struct V_1 * V_4 ;
if ( V_101 ) {
F_7 ( V_9 , L_16 ) ;
return;
}
F_2 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
V_4 = (struct V_1 * ) V_3 -> V_7 [ V_6 - 1 ] ;
V_3 -> V_7 [ V_6 - 1 ] = NULL ;
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
if ( V_4 )
F_5 ( V_4 ) ;
F_21 ( & V_23 . V_24 ) ;
if ( V_3 == V_23 . V_25 )
V_23 . V_25 = NULL ;
else
V_3 = NULL ;
F_23 ( & V_23 . V_24 ) ;
if ( V_3 ) {
F_17 ( V_3 ) ;
F_7 ( V_9 , L_17 ) ;
}
F_7 ( V_9 , L_18 ) ;
}
void F_63 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
struct V_1 * V_4 ;
struct V_38 * V_39 ;
T_5 * V_40 ;
int V_102 ;
int V_103 ;
int V_104 ;
int V_22 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
F_7 ( V_9 , L_19 ) ;
return;
}
V_39 = (struct V_38 * ) ( V_37 + 1 ) ;
if ( V_39 -> V_52 != 0 ) {
if ( ( ( V_4 -> V_105 - V_39 -> V_52 ) & 0x80 ) == 0 ) {
F_7 ( V_9 , L_20 ,
V_39 -> V_52 , V_4 -> V_105 ) ;
goto V_47;
}
}
V_4 -> V_105 = V_39 -> V_52 ;
V_102 = V_37 -> V_48 - sizeof( struct V_38 ) ;
V_40 = ( ( T_5 * ) ( V_37 + 1 ) ) + sizeof( struct V_38 ) ;
if ( V_102 <= 0 )
goto V_47;
V_103 = V_4 -> V_28 - V_4 -> V_27 - 1 ;
if ( V_103 < 0 )
V_103 += V_29 ;
if ( V_102 > V_103 ) {
F_7 ( V_9 , L_21 , V_102 , V_103 ) ;
V_102 = V_103 ;
}
V_22 = V_4 -> V_27 ;
V_104 = V_29 - V_22 ;
if ( V_104 > V_102 )
V_104 = V_102 ;
memcpy ( & V_4 -> V_30 [ V_22 ] , V_40 , V_104 ) ;
V_102 -= V_104 ;
V_22 += V_104 ;
if ( V_22 == V_29 )
V_22 = 0 ;
if ( V_102 ) {
memcpy ( V_4 -> V_30 , V_40 + V_104 , V_102 ) ;
V_22 = V_102 ;
}
V_4 -> V_27 = V_22 ;
F_64 ( & V_23 . V_85 ) ;
V_47:
F_5 ( V_4 ) ;
}
