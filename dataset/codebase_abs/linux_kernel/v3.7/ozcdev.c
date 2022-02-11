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
F_7 ( L_1 ) ;
F_8 ( V_4 ) ;
}
}
int F_9 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
F_7 ( L_2 ) ;
F_7 ( L_3 , F_10 ( V_9 ) , F_11 ( V_9 ) ) ;
V_13 = F_12 ( V_9 -> V_14 , struct V_12 , V_15 ) ;
V_11 -> V_16 = V_13 ;
return 0 ;
}
int F_13 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
F_7 ( L_4 ) ;
return 0 ;
}
T_1 F_14 ( struct V_10 * V_11 , char T_2 * V_17 , T_3 V_18 ,
T_4 * V_19 )
{
int V_20 ;
int V_21 ;
struct V_2 * V_3 ;
struct V_1 * V_4 = 0 ;
F_2 ( & V_22 . V_23 ) ;
V_3 = V_22 . V_24 ;
if ( V_3 )
F_15 ( V_3 ) ;
F_4 ( & V_22 . V_23 ) ;
if ( V_3 == NULL )
return - 1 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
goto V_25;
V_20 = V_4 -> V_26 - V_4 -> V_27 ;
if ( V_20 < 0 )
V_20 += V_28 ;
if ( V_18 > V_20 )
V_18 = V_20 ;
V_21 = V_4 -> V_27 ;
V_20 = V_28 - V_21 ;
if ( V_20 > V_18 )
V_20 = V_18 ;
if ( F_16 ( V_17 , & V_4 -> V_29 [ V_21 ] , V_20 ) ) {
V_18 = 0 ;
goto V_30;
}
V_21 += V_20 ;
if ( V_21 == V_28 )
V_21 = 0 ;
if ( V_20 < V_18 ) {
if ( F_16 ( & V_17 [ V_20 ] , V_4 -> V_29 , V_18 - V_20 ) ) {
V_18 = 0 ;
goto V_30;
}
V_21 = V_18 - V_20 ;
}
V_4 -> V_27 = V_21 ;
V_30:
F_5 ( V_4 ) ;
V_25:
F_17 ( V_3 ) ;
return V_18 ;
}
T_1 F_18 ( struct V_10 * V_11 , const char T_2 * V_17 , T_3 V_18 ,
T_4 * V_19 )
{
struct V_2 * V_3 ;
struct V_31 * V_32 ;
struct V_33 * V_34 = 0 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_1 * V_4 ;
F_2 ( & V_22 . V_23 ) ;
V_3 = V_22 . V_24 ;
if ( V_3 )
F_15 ( V_3 ) ;
F_4 ( & V_22 . V_23 ) ;
if ( V_3 == NULL )
return - 1 ;
V_32 = & V_3 -> V_39 ;
V_34 = F_19 ( V_32 ) ;
if ( V_34 == NULL ) {
V_18 = 0 ;
goto V_40;
}
V_36 = (struct V_35 * ) V_34 -> V_41 ;
V_38 = (struct V_37 * ) ( V_36 + 1 ) ;
V_36 -> V_42 = sizeof( struct V_37 ) + V_18 ;
V_36 -> type = V_43 ;
V_34 -> V_44 = V_6 ;
V_34 -> V_42 = V_36 -> V_42 + sizeof( struct V_35 ) ;
V_38 -> V_44 = V_6 ;
if ( F_20 ( V_38 + 1 , V_17 , V_18 ) )
goto V_40;
F_2 ( & V_3 -> V_5 [ V_45 - 1 ] ) ;
V_4 = (struct V_1 * ) V_3 -> V_7 [ V_6 - 1 ] ;
if ( V_4 ) {
V_38 -> V_46 = V_4 -> V_47 ++ ;
if ( V_4 -> V_47 == 0 )
V_4 -> V_47 = 1 ;
F_21 ( & V_32 -> V_23 ) ;
if ( F_22 ( V_32 , 0 , 0 , V_34 ) == 0 )
V_34 = 0 ;
F_23 ( & V_32 -> V_23 ) ;
}
F_4 ( & V_3 -> V_5 [ V_45 - 1 ] ) ;
V_40:
if ( V_34 ) {
V_18 = 0 ;
F_2 ( & V_32 -> V_23 ) ;
F_24 ( V_32 , V_34 ) ;
F_4 ( & V_32 -> V_23 ) ;
}
F_17 ( V_3 ) ;
return V_18 ;
}
static int F_25 ( T_5 * V_48 )
{
int V_49 = 0 ;
struct V_2 * V_3 ;
struct V_2 * V_50 ;
V_3 = F_26 ( V_48 ) ;
if ( V_3 ) {
F_2 ( & V_22 . V_23 ) ;
memcpy ( V_22 . V_51 , V_48 , V_52 ) ;
V_50 = V_22 . V_24 ;
V_22 . V_24 = V_3 ;
F_4 ( & V_22 . V_23 ) ;
if ( V_50 )
F_17 ( V_50 ) ;
} else {
if ( F_27 ( V_48 ) ) {
F_2 ( & V_22 . V_23 ) ;
V_3 = V_22 . V_24 ;
V_22 . V_24 = 0 ;
memset ( V_22 . V_51 , 0 ,
sizeof( V_22 . V_51 ) ) ;
F_4 ( & V_22 . V_23 ) ;
if ( V_3 )
F_17 ( V_3 ) ;
} else {
V_49 = - 1 ;
}
}
return V_49 ;
}
long F_28 ( struct V_10 * V_11 , unsigned int V_53 , unsigned long V_54 )
{
int V_49 = 0 ;
if ( F_29 ( V_53 ) != V_55 )
return - V_56 ;
if ( F_30 ( V_53 ) > V_57 )
return - V_56 ;
if ( F_31 ( V_53 ) & V_58 )
V_49 = ! F_32 ( V_59 , ( void T_2 * ) V_54 ,
F_33 ( V_53 ) ) ;
else if ( F_31 ( V_53 ) & V_60 )
V_49 = ! F_32 ( V_61 , ( void T_2 * ) V_54 ,
F_33 ( V_53 ) ) ;
if ( V_49 )
return - V_62 ;
switch ( V_53 ) {
case V_63 : {
struct V_64 V_65 ;
F_7 ( L_5 ) ;
V_65 . V_18 = F_34 ( V_65 . V_48 , V_66 ) ;
if ( F_16 ( ( void T_2 * ) V_54 , & V_65 ,
sizeof( V_65 ) ) )
return - V_62 ;
}
break;
case V_67 : {
T_5 V_48 [ V_52 ] ;
F_7 ( L_6 ) ;
if ( F_20 ( V_48 , ( void T_2 * ) V_54 , V_52 ) )
return - V_62 ;
V_49 = F_25 ( V_48 ) ;
}
break;
case V_68 : {
T_5 V_48 [ V_52 ] ;
F_7 ( L_7 ) ;
F_2 ( & V_22 . V_23 ) ;
memcpy ( V_48 , V_22 . V_51 , V_52 ) ;
F_4 ( & V_22 . V_23 ) ;
if ( F_16 ( ( void T_2 * ) V_54 , V_48 , V_52 ) )
return - V_62 ;
}
break;
case V_69 :
case V_70 : {
struct V_71 V_72 ;
if ( F_20 ( & V_72 , ( void T_2 * ) V_54 ,
sizeof( struct V_71 ) ) ) {
return - V_62 ;
}
V_72 . V_73 [ V_74 - 1 ] = 0 ;
if ( V_53 == V_69 )
F_35 ( V_72 . V_73 ) ;
else
F_36 ( V_72 . V_73 ) ;
}
break;
}
return V_49 ;
}
unsigned int F_37 ( struct V_10 * V_11 , T_6 * V_75 )
{
unsigned int V_76 = 0 ;
struct V_12 * V_13 = V_11 -> V_16 ;
F_7 ( L_8 , V_75 ) ;
F_2 ( & V_13 -> V_23 ) ;
if ( V_13 -> V_24 ) {
struct V_1 * V_4 = F_1 ( V_13 -> V_24 ) ;
if ( V_4 ) {
if ( V_4 -> V_26 != V_4 -> V_27 )
V_76 |= V_77 | V_78 ;
F_5 ( V_4 ) ;
}
}
F_4 ( & V_13 -> V_23 ) ;
if ( V_75 )
F_38 ( V_11 , & V_13 -> V_79 , V_75 ) ;
return V_76 ;
}
int F_39 ( void )
{
int V_80 ;
struct V_81 * V_13 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_80 = F_40 ( & V_22 . V_82 , 0 , 1 , L_9 ) ;
if ( V_80 < 0 )
goto V_83;
F_7 ( L_10 , F_41 ( V_22 . V_82 ) ,
F_42 ( V_22 . V_82 ) ) ;
F_43 ( & V_22 . V_15 , & V_84 ) ;
V_22 . V_15 . V_85 = V_86 ;
V_22 . V_15 . V_87 = & V_84 ;
F_44 ( & V_22 . V_23 ) ;
F_45 ( & V_22 . V_79 ) ;
V_80 = F_46 ( & V_22 . V_15 , V_22 . V_82 , 1 ) ;
if ( V_80 < 0 ) {
F_7 ( L_11 ) ;
goto V_25;
}
V_88 = F_47 ( V_86 , L_12 ) ;
if ( F_48 ( V_88 ) ) {
F_7 ( L_13 ) ;
goto V_30;
}
V_13 = F_49 ( V_88 , NULL , V_22 . V_82 , NULL , L_9 ) ;
if ( F_48 ( V_13 ) ) {
F_7 ( L_14 ) ;
goto V_30;
}
return 0 ;
V_30:
F_50 ( & V_22 . V_15 ) ;
V_25:
F_51 ( V_22 . V_82 , 1 ) ;
V_83:
return V_80 ;
}
int F_52 ( void )
{
F_50 ( & V_22 . V_15 ) ;
F_51 ( V_22 . V_82 , 1 ) ;
if ( V_88 ) {
F_53 ( V_88 , V_22 . V_82 ) ;
F_54 ( V_88 ) ;
}
return 0 ;
}
int F_55 ( void )
{
F_56 ( V_89 , 1 , V_6 , 0 , 0 ) ;
F_57 ( V_6 , 1 ) ;
return 0 ;
}
void F_58 ( void )
{
F_56 ( V_89 , 2 , V_6 , 0 , 0 ) ;
F_57 ( V_6 , 0 ) ;
}
int F_59 ( struct V_2 * V_3 , int V_90 )
{
struct V_1 * V_4 ;
struct V_1 * V_91 = 0 ;
F_56 ( V_89 , 3 , V_6 , 0 , V_90 ) ;
if ( V_90 ) {
F_7 ( L_15 ) ;
return 0 ;
}
V_4 = F_60 ( sizeof( struct V_1 ) , V_92 ) ;
if ( V_4 == NULL )
return - V_93 ;
F_61 ( & V_4 -> V_8 , 1 ) ;
V_4 -> V_47 = 1 ;
F_2 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
V_91 = V_3 -> V_7 [ V_6 - 1 ] ;
if ( V_91 ) {
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
F_8 ( V_4 ) ;
} else {
V_3 -> V_7 [ V_6 - 1 ] = V_4 ;
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
}
F_21 ( & V_22 . V_23 ) ;
if ( ( V_22 . V_24 == NULL ) &&
( memcmp ( V_3 -> V_94 , V_22 . V_51 , V_52 ) == 0 ) ) {
F_15 ( V_3 ) ;
V_22 . V_24 = V_3 ;
F_7 ( L_16 ) ;
}
F_23 ( & V_22 . V_23 ) ;
F_7 ( L_17 ) ;
return 0 ;
}
void F_62 ( struct V_2 * V_3 , int V_95 )
{
struct V_1 * V_4 ;
F_56 ( V_89 , 4 , V_6 , 0 , V_95 ) ;
if ( V_95 ) {
F_7 ( L_18 ) ;
return;
}
F_2 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
V_4 = (struct V_1 * ) V_3 -> V_7 [ V_6 - 1 ] ;
V_3 -> V_7 [ V_6 - 1 ] = 0 ;
F_4 ( & V_3 -> V_5 [ V_6 - 1 ] ) ;
if ( V_4 )
F_5 ( V_4 ) ;
F_21 ( & V_22 . V_23 ) ;
if ( V_3 == V_22 . V_24 )
V_22 . V_24 = 0 ;
else
V_3 = 0 ;
F_23 ( & V_22 . V_23 ) ;
if ( V_3 ) {
F_17 ( V_3 ) ;
F_7 ( L_19 ) ;
}
F_7 ( L_20 ) ;
}
void F_63 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
struct V_1 * V_4 ;
struct V_37 * V_38 ;
T_5 * V_41 ;
int V_96 ;
int V_97 ;
int V_98 ;
int V_21 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
F_7 ( L_21 ) ;
return;
}
V_38 = (struct V_37 * ) ( V_36 + 1 ) ;
if ( V_38 -> V_46 != 0 ) {
if ( ( ( V_4 -> V_99 - V_38 -> V_46 ) & 0x80 ) == 0 ) {
F_7 ( L_22 ,
V_38 -> V_46 , V_4 -> V_99 ) ;
goto V_40;
}
}
V_4 -> V_99 = V_38 -> V_46 ;
V_96 = V_36 -> V_42 - sizeof( struct V_37 ) ;
V_41 = ( ( T_5 * ) ( V_36 + 1 ) ) + sizeof( struct V_37 ) ;
if ( V_96 <= 0 )
goto V_40;
V_97 = V_4 -> V_27 - V_4 -> V_26 - 1 ;
if ( V_97 < 0 )
V_97 += V_28 ;
if ( V_96 > V_97 ) {
F_7 ( L_23 , V_96 , V_97 ) ;
V_96 = V_97 ;
}
V_21 = V_4 -> V_26 ;
V_98 = V_28 - V_21 ;
if ( V_98 > V_96 )
V_98 = V_96 ;
memcpy ( & V_4 -> V_29 [ V_21 ] , V_41 , V_98 ) ;
V_96 -= V_98 ;
V_21 += V_98 ;
if ( V_21 == V_28 )
V_21 = 0 ;
if ( V_96 ) {
memcpy ( V_4 -> V_29 , V_41 + V_98 , V_96 ) ;
V_21 = V_96 ;
}
V_4 -> V_26 = V_21 ;
F_64 ( & V_22 . V_79 ) ;
V_40:
F_5 ( V_4 ) ;
}
void F_65 ( struct V_2 * V_3 )
{
}
