static inline int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
return F_2 ( V_2 -> V_5 , V_6 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
int V_7 ;
F_4 ( V_2 -> V_5 ) ;
V_7 = F_1 ( V_2 , V_3 , V_4 ) ;
F_5 ( V_2 -> V_5 ) ;
return V_7 ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_7 ( V_9 , struct V_1 , V_10 ) ;
F_8 ( V_2 , V_11 , L_1 ) ;
V_7 = F_9 ( V_2 -> V_5 -> V_12 . V_13 ) ;
if ( V_7 < 0 )
F_8 ( V_2 , V_14 , L_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_16 -> V_17 . V_18 ) {
case V_19 :
F_8 ( V_2 , V_11 , L_3 ) ;
F_11 ( & V_2 -> V_10 ) ;
break;
default:
F_8 ( V_2 , V_11 , L_4 ,
V_16 -> V_17 . V_18 ) ;
break;
}
}
static void F_12 ( struct V_1 * V_2 , T_1 * V_20 , int V_21 )
{
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) V_20 ;
if ( V_16 -> V_17 . type != V_22 ) {
F_13 ( V_2 , V_11 ,
L_5 ,
V_16 -> V_17 . type ) ;
return;
}
if ( V_21 < sizeof( V_16 -> V_17 ) ) {
F_13 ( V_2 , V_11 ,
L_6
L_7 ,
V_21 , sizeof( V_16 -> V_17 ) ) ;
return;
}
if ( V_21 < F_14 ( V_16 -> V_17 . V_23 ) + sizeof( V_16 -> V_17 ) ) {
F_13 ( V_2 , V_11 ,
L_8
L_9 ,
V_21 , F_14 ( V_16 -> V_17 . V_23 ) ) ;
return;
}
switch ( V_16 -> V_17 . V_24 ) {
case V_25 :
F_10 ( V_2 , (struct V_15 * ) V_20 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
F_15 ( V_2 , V_20 , V_21 ) ;
break;
default:
F_13 ( V_2 , V_11 ,
L_10 ,
V_16 -> V_17 . V_24 ) ;
break;
}
}
int F_16 ( struct V_1 * V_2 , T_1 * V_29 , T_2 V_21 )
{
int V_7 ;
T_1 * V_20 ;
F_17 ( V_2 , V_11 , L_11 ) ;
( (struct V_15 * ) V_29 ) -> V_17 . V_30 |= V_31 ;
F_18 ( V_11 , V_29 , V_21 ) ;
if ( V_21 > V_32 ) {
F_13 ( V_2 , V_11 , L_12 ,
V_21 , V_32 ) ;
return - 1 ;
}
V_20 = F_19 ( V_32 , V_33 ) ;
if ( ! V_20 ) {
F_13 ( V_2 , V_11 , L_13 ,
V_32 ) ;
return - 1 ;
}
memcpy ( V_20 , V_29 , V_21 ) ;
V_7 = F_3 ( V_2 , V_20 , V_32 ) ;
F_20 ( V_20 ) ;
return V_7 ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_3 * V_20 = NULL ;
int V_7 ;
int V_36 ;
T_4 V_37 ;
bool V_38 ;
V_2 = F_7 ( V_9 , struct V_1 , V_39 ) ;
F_17 ( V_2 , V_40 , L_14 , V_9 ) ;
F_4 ( V_2 -> V_5 ) ;
if ( F_22 ( & V_2 -> V_41 ) ) {
F_13 ( V_2 , V_40 , L_15 ) ;
goto V_42;
}
V_35 = F_23 ( V_2 -> V_41 . V_43 ,
struct V_34 , V_44 ) ;
F_24 ( & V_35 -> V_44 ) ;
V_36 = V_35 -> V_36 ;
F_20 ( V_35 ) ;
V_20 = F_19 ( V_36 , V_33 ) ;
if ( ! V_20 ) {
F_13 ( V_2 , V_40 , L_13 , V_36 ) ;
goto V_42;
}
F_8 ( V_2 , V_40 , L_16 ,
V_36 , V_20 , V_2 -> V_5 -> V_45 ) ;
V_7 = F_25 ( V_2 -> V_5 , V_20 , V_6 , V_36 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_40 , L_17 , V_7 ) ;
goto V_42;
}
F_18 ( V_40 , ( T_1 * ) V_20 , V_36 ) ;
V_37 = F_26 ( V_20 [ 0 ] ) ;
if ( V_37 == V_46 ||
( V_37 & V_47 ) == V_48 ) {
V_38 = ( V_20 [ 1 ] == V_20 [ 0 ] ) &&
( V_20 [ 2 ] == V_20 [ 0 ] ) &&
( V_20 [ 3 ] == V_20 [ 0 ] ) ;
if ( ! V_38 ) {
F_27 ( V_2 , V_40 ,
L_18
L_19 ,
F_26 ( V_20 [ 0 ] ) , F_26 ( V_20 [ 1 ] ) ,
F_26 ( V_20 [ 2 ] ) , F_26 ( V_20 [ 3 ] ) ) ;
}
} else {
V_38 = false ;
}
if ( ! V_38 ) {
F_5 ( V_2 -> V_5 ) ;
F_12 ( V_2 , ( T_1 * ) V_20 , V_36 ) ;
goto exit;
} else if ( V_37 == V_46 ) {
if ( F_28 ( & V_2 -> V_49 ) == 0 ) {
F_13 ( V_2 , V_40 ,
L_20 ) ;
goto V_42;
}
F_29 ( & V_2 -> V_49 , 0 ) ;
F_8 ( V_2 , V_40 , L_21
L_22 ) ;
} else {
F_8 ( V_2 , V_40 , L_23 , V_37 ) ;
V_2 -> V_37 = V_37 ;
if ( V_37 & V_50 ) {
V_7 = F_1 ( V_2 , V_20 , V_36 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_40 ,
L_24 , V_7 ) ;
goto V_42;
}
F_8 ( V_2 , V_40 , L_25 ) ;
F_29 ( & V_2 -> V_49 , 1 ) ;
goto V_42;
}
F_8 ( V_2 , V_40 , L_26
L_22 ) ;
}
F_5 ( V_2 -> V_5 ) ;
if ( V_2 -> V_51 . V_52 )
F_30 ( V_2 ) ;
else
F_13 ( V_2 , V_40 , L_27 ) ;
goto exit;
V_42:
F_5 ( V_2 -> V_5 ) ;
exit:
F_20 ( V_20 ) ;
F_17 ( V_2 , V_40 , L_28 ) ;
}
static void F_31 ( struct V_53 * V_5 )
{
struct V_1 * V_2 ;
int V_54 , V_7 ;
int V_36 ;
int V_55 = V_56 ;
struct V_34 * V_35 ;
V_2 = F_32 ( V_5 ) ;
F_17 ( V_2 , V_40 , L_29 ) ;
V_54 = F_33 ( V_5 , V_57 , & V_7 ) ;
F_17 ( V_2 , V_40 , L_30 , V_54 , V_7 ) ;
if ( ! V_54 ) {
F_13 ( V_2 , V_40 , L_31 ) ;
goto V_58;
}
V_54 = F_33 ( V_2 -> V_5 , V_55 ++ , & V_7 ) ;
V_36 = V_54 ;
V_54 = F_33 ( V_2 -> V_5 , V_55 ++ , & V_7 ) ;
V_36 += V_54 << 8 ;
F_8 ( V_2 , V_40 , L_32 , V_36 ) ;
if ( V_36 == 0 ) {
F_13 ( V_2 , V_40 , L_33 , V_36 ) ;
goto V_58;
}
V_35 = F_19 ( sizeof( struct V_34 ) , V_33 ) ;
if ( ! V_35 ) {
F_13 ( V_2 , V_40 , L_34 ) ;
goto V_58;
}
F_34 ( & V_35 -> V_44 ) ;
V_35 -> V_36 = V_36 ;
F_35 ( & V_2 -> V_41 , & V_35 -> V_44 ) ;
F_36 ( V_5 , 1 , V_59 , & V_7 ) ;
F_11 ( & V_2 -> V_39 ) ;
F_17 ( V_2 , V_40 , L_35 ) ;
return;
V_58:
F_36 ( V_5 , 1 , V_59 , & V_7 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
#ifdef F_38
int V_60 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
F_39 ( & V_2 -> V_5 -> V_12 , L_36 ,
V_60 , V_62 [ V_60 ] ) ;
F_40 ( ( V_62 [ V_60 ] >> 8 ) & 0xFF ,
V_62 [ V_60 ] & 0xFF ) ;
}
for ( V_60 = 0 ; V_60 < V_63 ; V_60 ++ ) {
F_39 ( & V_2 -> V_5 -> V_12 , L_37 ,
V_60 , V_64 [ V_60 ] ) ;
F_41 ( ( V_64 [ V_60 ] >> 8 ) & 0xFF ,
V_64 [ V_60 ] & 0xFF ) ;
}
#endif
V_2 -> V_51 . V_65 = V_65 ;
F_8 ( V_2 , V_14 , L_38 , V_65 ) ;
V_2 -> V_51 . V_66 = ( bool ) V_66 ;
F_8 ( V_2 , V_14 , L_39 , V_66 ) ;
V_2 -> V_51 . V_67 = ( bool ) V_67 ;
F_8 ( V_2 , V_14 , L_40 , V_67 ) ;
V_2 -> V_51 . V_68 = ( bool ) V_68 ;
F_8 ( V_2 , V_14 , L_41 , V_68 ) ;
V_2 -> V_51 . V_69 = ( bool ) V_69 ;
F_8 ( V_2 , V_14 , L_42 , V_69 ) ;
V_2 -> V_51 . V_52 = ( bool ) V_52 ;
F_8 ( V_2 , V_14 , L_43 , V_52 ) ;
V_2 -> V_51 . V_70 = V_70 ;
F_8 ( V_2 , V_14 , L_44 , V_70 ) ;
V_2 -> V_51 . V_71 = V_71 ;
F_8 ( V_2 , V_14 , L_45 , V_71 ) ;
}
static T_5 F_42 ( struct V_72 * V_73 ,
struct V_74 * V_75 , char * V_20 )
{
struct V_1 * V_2 = F_43 ( V_73 ) ;
return sprintf ( V_20 , L_46 , V_2 -> V_51 . V_76 ) ;
}
static int F_44 ( struct V_53 * V_5 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 ;
int V_7 ;
int V_54 = 1 ;
int V_55 = V_79 ;
F_45 ( & V_5 -> V_12 , L_47 ) ;
F_45 ( & V_5 -> V_12 , L_48 ,
F_46 ( 2147483647 ) , V_80 ) ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_2 ) {
F_47 ( & V_5 -> V_12 , L_49 ) ;
return - V_81 ;
}
V_2 -> V_5 = V_5 ;
F_48 ( V_5 , V_2 ) ;
F_49 ( & V_2 -> V_10 , F_6 ) ;
F_49 ( & V_2 -> V_39 , F_21 ) ;
F_50 ( & V_2 -> V_82 ) ;
F_4 ( V_5 ) ;
V_5 -> V_83 = 10 ;
V_7 = F_51 ( V_5 , V_2 -> V_51 . V_70 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_14 ,
L_50 , V_7 ) ;
goto V_84;
}
V_7 = F_52 ( V_5 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_14 , L_51 , V_7 ) ;
goto V_84;
}
F_29 ( & V_2 -> V_85 , 0 ) ;
F_29 ( & V_2 -> V_49 , 0 ) ;
F_34 ( & V_2 -> V_41 ) ;
F_37 ( V_2 ) ;
V_7 = F_53 ( & V_5 -> V_12 . V_86 , & V_87 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_14 , L_52
L_53 ) ;
goto V_88;
}
F_54 ( V_2 , V_89 ) ;
if ( ! V_2 -> V_51 . V_68 && V_2 -> V_51 . V_71 > 8 ) {
F_8 ( V_2 , V_14 ,
L_54 ,
V_2 -> V_51 . V_71 ) ;
V_2 -> V_51 . V_71 = 8 ;
}
V_2 -> V_90 = V_2 -> V_51 . V_71 * V_2 -> V_51 . V_70 ;
F_8 ( V_2 , V_14 , L_55 , V_2 -> V_90 ) ;
V_7 = F_55 ( V_5 , F_31 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_14 , L_56 , V_7 ) ;
goto V_91;
}
F_36 ( V_2 -> V_5 , V_54 , V_55 , & V_7 ) ;
if ( V_7 ) {
F_13 ( V_2 , V_14 , L_57
L_58 , V_55 , V_7 ) ;
goto V_92;
}
F_5 ( V_5 ) ;
F_8 ( V_2 , V_14 , L_59 ) ;
return V_7 ;
V_92:
F_56 ( V_5 ) ;
V_91:
F_57 ( V_5 ) ;
V_88:
F_58 ( V_2 -> V_93 ) ;
F_59 ( & V_5 -> V_12 . V_86 , & V_87 ) ;
V_84:
F_5 ( V_5 ) ;
return V_7 ;
}
static void F_60 ( struct V_53 * V_5 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 = F_32 ( V_5 ) ;
F_8 ( V_2 , V_14 , L_60 ) ;
F_4 ( V_5 ) ;
F_56 ( V_5 ) ;
F_5 ( V_5 ) ;
F_61 ( & V_2 -> V_10 ) ;
F_61 ( & V_2 -> V_39 ) ;
F_4 ( V_5 ) ;
F_57 ( V_5 ) ;
F_59 ( & V_5 -> V_12 . V_86 , & V_87 ) ;
F_58 ( V_2 -> V_93 ) ;
F_5 ( V_5 ) ;
while ( ! F_22 ( & V_2 -> V_41 ) ) {
V_35 = F_23 ( V_2 -> V_41 . V_43 ,
struct V_34 , V_44 ) ;
F_24 ( & V_35 -> V_44 ) ;
F_20 ( V_35 ) ;
}
F_20 ( V_2 ) ;
}
static int T_6 F_62 ( void )
{
int V_94 ;
F_40 ( V_95 , V_96 ) ;
F_40 ( V_97 , V_98 ) ;
F_41 ( V_95 , V_99 ) ;
V_94 = F_63 ( & V_100 ) ;
return V_94 ;
}
static void T_7 F_64 ( void )
{
F_65 ( & V_100 ) ;
}
