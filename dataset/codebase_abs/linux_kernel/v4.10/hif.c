static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
T_1 * V_4 ;
int V_5 ;
V_4 = V_2 -> V_6 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_7 ; V_5 ++ ) {
if ( V_3 )
memcpy ( V_2 -> V_8 [ V_5 ] . V_4 , V_4 ,
V_2 -> V_8 [ V_5 ] . V_9 ) ;
else
memcpy ( V_4 , V_2 -> V_8 [ V_5 ] . V_4 ,
V_2 -> V_8 [ V_5 ] . V_9 ) ;
V_4 += V_2 -> V_8 [ V_5 ] . V_9 ;
}
return 0 ;
}
int F_2 ( void * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 ;
F_3 ( V_14 , L_1 ,
V_13 , V_11 ) ;
V_13 -> V_11 = V_11 ;
V_13 -> V_15 ( V_13 -> V_10 , V_13 ) ;
return 0 ;
}
static void F_4 ( struct V_16 * V_17 )
{
T_2 V_18 [ V_19 ] ;
T_3 V_5 , V_20 , V_21 = 0 ;
int V_22 ;
V_20 = F_5 ( V_17 , F_6 ( V_23 ) ) ;
V_20 = F_7 ( V_17 -> V_24 , V_20 ) ;
V_22 = F_8 ( V_17 , V_20 , & V_21 ) ;
if ( V_22 || ! V_21 ) {
F_9 ( L_2 ,
V_22 ) ;
return;
}
F_3 ( V_25 , L_3 ,
V_21 ) ;
V_21 = F_7 ( V_17 -> V_24 , V_21 ) ;
V_22 = F_10 ( V_17 , V_21 , ( T_1 * ) & V_18 [ 0 ] ,
V_26 * ( sizeof( T_3 ) ) ) ;
if ( V_22 ) {
F_9 ( L_4 , V_22 ) ;
return;
}
F_11 ( L_5 ) ;
F_11 ( L_6 , V_17 -> V_27 -> V_28 ,
V_17 -> V_27 -> V_29 ) ;
F_12 ( V_26 % 4 ) ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 += 4 ) {
F_11 ( L_7 ,
V_5 ,
F_13 ( V_18 [ V_5 ] ) ,
F_13 ( V_18 [ V_5 + 1 ] ) ,
F_13 ( V_18 [ V_5 + 2 ] ) ,
F_13 ( V_18 [ V_5 + 3 ] ) ) ;
}
}
static int F_14 ( struct V_30 * V_31 )
{
T_3 V_32 ;
int V_22 ;
F_9 ( L_8 ) ;
V_22 = F_15 ( V_31 -> V_17 , V_33 ,
( T_1 * ) & V_32 , 4 , V_34 ) ;
if ( V_22 )
F_9 ( L_9 , V_22 ) ;
F_4 ( V_31 -> V_17 ) ;
F_16 ( V_31 -> V_17 ) ;
F_17 ( V_31 -> V_17 , V_35 ) ;
return V_22 ;
}
int F_18 ( struct V_30 * V_31 , T_3 * V_36 ,
int V_37 )
{
struct V_38 * V_39 ;
int V_11 = 0 , V_5 ;
T_1 V_40 = 1 << V_41 ;
for ( V_5 = V_37 / V_42 ; V_5 > 0 ; V_5 -- ) {
V_11 = F_15 ( V_31 -> V_17 , V_43 ,
( T_1 * ) & V_31 -> V_44 ,
sizeof( V_31 -> V_44 ) ,
V_34 ) ;
if ( V_11 ) {
F_19 ( L_10 ) ;
return V_11 ;
}
if ( V_31 -> V_44 . V_45 & V_40 ) {
if ( V_31 -> V_44 . V_46 &
V_40 ) {
V_39 = & V_31 -> V_44 ;
* V_36 =
F_13 ( V_39 -> V_47 [ V_41 ] ) ;
break;
}
}
F_20 ( V_42 ) ;
F_3 ( V_14 , L_11 , V_5 ) ;
}
if ( V_5 == 0 ) {
F_19 ( L_12 ) ;
V_11 = - V_48 ;
if ( V_31 -> V_44 . V_49 &
V_50 )
F_14 ( V_31 ) ;
}
return V_11 ;
}
int F_21 ( struct V_30 * V_31 , bool V_51 )
{
struct V_52 V_53 ;
int V_11 = 0 ;
F_3 ( V_14 , L_13 ,
V_51 ? L_14 : L_15 ) ;
F_22 ( & V_31 -> V_54 ) ;
if ( V_51 )
V_31 -> V_55 . V_56 |=
F_23 ( V_57 , 0x01 ) ;
else
V_31 -> V_55 . V_56 &=
~ F_23 ( V_57 , 0x01 ) ;
memcpy ( & V_53 , & V_31 -> V_55 , sizeof( V_53 ) ) ;
F_24 ( & V_31 -> V_54 ) ;
V_11 = F_15 ( V_31 -> V_17 , V_58 ,
& V_53 . V_56 ,
sizeof( struct V_52 ) ,
V_59 ) ;
return V_11 ;
}
int F_25 ( struct V_30 * V_31 ,
struct V_1 * V_60 , bool V_61 )
{
int V_11 = 0 ;
if ( V_61 ) {
V_60 -> V_2 = V_62 ;
V_60 -> V_63 = V_31 -> V_17 -> V_64 . V_65 ;
} else {
V_60 -> V_2 = V_66 ;
V_60 -> V_63 =
( V_60 -> V_9 > V_67 ) ?
V_31 -> V_17 -> V_64 . V_68 :
V_31 -> V_17 -> V_64 . V_65 ;
}
F_3 ( V_14 ,
L_16 ,
V_60 -> V_7 , V_60 -> V_9 ,
V_60 -> V_63 , ! V_61 ? L_17 : L_18 ,
( V_61 ) ? L_19 : L_20 ) ;
if ( ! V_61 && V_60 -> V_69 ) {
V_11 = F_1 ( V_60 , false ) ;
if ( V_11 ) {
V_60 -> V_11 = V_11 ;
V_60 -> V_70 ( V_31 -> V_17 -> V_71 , V_60 ) ;
return 0 ;
}
}
V_11 = F_26 ( V_31 -> V_17 , V_60 ) ;
if ( V_61 ) {
V_60 -> V_11 = V_11 ;
if ( ! V_11 && V_60 -> V_69 )
V_60 -> V_11 =
F_1 ( V_60 , true ) ;
}
return V_11 ;
}
static int F_27 ( struct V_30 * V_31 )
{
T_1 V_49 ;
F_3 ( V_25 , L_21 ) ;
V_49 = V_31 -> V_44 . V_49 &
V_31 -> V_55 . V_72 ;
F_3 ( V_25 ,
L_22 ,
V_49 ) ;
if ( V_49 & V_50 )
return F_14 ( V_31 ) ;
return 0 ;
}
static int F_28 ( struct V_30 * V_31 )
{
int V_11 ;
T_1 V_73 ;
T_1 V_74 [ 4 ] ;
F_3 ( V_25 , L_23 ) ;
V_73 = V_31 -> V_44 . V_73 & 0x0F ;
if ( ! V_73 ) {
F_29 ( 1 ) ;
return - V_75 ;
}
F_3 ( V_25 ,
L_24 ,
V_73 ) ;
if ( F_30 ( V_76 , V_73 ) )
F_3 ( V_25 , L_25 ) ;
if ( F_30 ( V_77 , V_73 ) )
F_19 ( L_26 ) ;
if ( F_30 ( V_78 , V_73 ) )
F_19 ( L_27 ) ;
V_31 -> V_44 . V_73 &= ~ V_73 ;
V_74 [ 0 ] = V_73 ;
V_74 [ 1 ] = 0 ;
V_74 [ 2 ] = 0 ;
V_74 [ 3 ] = 0 ;
V_11 = F_15 ( V_31 -> V_17 , V_79 ,
V_74 , 4 , V_80 ) ;
F_29 ( V_11 ) ;
return V_11 ;
}
static int F_31 ( struct V_30 * V_31 )
{
int V_11 ;
T_1 V_81 ;
T_1 V_74 [ 4 ] ;
F_3 ( V_25 , L_28 ) ;
V_81 = V_31 -> V_44 . V_81 &
V_31 -> V_55 . V_82 ;
if ( ! V_81 ) {
F_29 ( 1 ) ;
return - V_75 ;
}
F_3 ( V_25 ,
L_29 ,
V_81 ) ;
V_31 -> V_44 . V_81 &= ~ V_81 ;
V_74 [ 0 ] = V_81 ;
V_74 [ 1 ] = 0 ;
V_74 [ 2 ] = 0 ;
V_74 [ 3 ] = 0 ;
V_11 = F_15 ( V_31 -> V_17 , V_83 ,
V_74 , 4 , V_80 ) ;
F_29 ( V_11 ) ;
return V_11 ;
}
static int F_32 ( struct V_30 * V_31 , bool * V_84 )
{
struct V_38 * V_39 ;
int V_11 = 0 ;
T_1 V_45 = 0 ;
T_3 V_36 = 0 ;
T_1 V_40 = 1 << V_41 ;
F_3 ( V_25 , L_30 , V_31 ) ;
if ( V_31 -> V_55 . V_56 ) {
V_11 = F_15 ( V_31 -> V_17 , V_43 ,
( T_1 * ) & V_31 -> V_44 ,
sizeof( V_31 -> V_44 ) ,
V_34 ) ;
if ( V_11 )
goto V_85;
F_33 ( V_31 , & V_31 -> V_44 ,
& V_31 -> V_55 ) ;
F_34 ( & V_31 -> V_55 ,
sizeof( V_31 -> V_55 ) ) ;
V_45 = V_31 -> V_44 . V_45 &
V_31 -> V_55 . V_56 ;
if ( V_45 & V_40 ) {
V_45 &= ~ V_40 ;
if ( V_31 -> V_44 . V_46 &
V_40 ) {
V_39 = & V_31 -> V_44 ;
V_36 = F_13 ( V_39 -> V_47 [ V_41 ] ) ;
if ( ! V_36 )
F_19 ( L_31 ) ;
}
}
}
if ( ! V_45 && ! V_36 ) {
* V_84 = true ;
goto V_85;
}
if ( V_36 ) {
int V_86 = 0 ;
F_3 ( V_25 ,
L_32 , V_36 ) ;
V_11 = F_35 ( V_31 -> V_87 ,
V_36 , & V_86 ) ;
if ( V_11 )
goto V_85;
if ( ! V_86 )
V_31 -> V_87 -> V_88 = 0 ;
}
F_3 ( V_25 ,
L_33 ,
V_45 ) ;
if ( F_30 ( V_89 , V_45 ) ) {
V_11 = F_31 ( V_31 ) ;
if ( V_11 )
goto V_85;
}
if ( F_30 ( V_90 , V_45 ) ) {
V_11 = F_28 ( V_31 ) ;
if ( V_11 )
goto V_85;
}
if ( F_30 ( V_91 , V_45 ) )
V_11 = F_27 ( V_31 ) ;
V_85:
F_3 ( V_25 ,
L_34 ) ;
if ( ! V_31 -> V_87 -> V_88 )
* V_84 = true ;
F_3 ( V_25 ,
L_35 , * V_84 , V_11 ) ;
return V_11 ;
}
int F_36 ( struct V_16 * V_17 )
{
struct V_30 * V_31 = V_17 -> V_71 -> V_31 ;
unsigned long V_37 ;
int V_11 = 0 ;
bool V_84 = false ;
V_31 -> V_87 -> V_88 = 0 ;
V_37 = V_92 + F_37 ( V_93 ) ;
while ( F_38 ( V_92 , V_37 ) && ! V_84 ) {
V_11 = F_32 ( V_31 , & V_84 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_39 ( struct V_30 * V_31 )
{
struct V_52 V_53 ;
int V_11 ;
F_22 ( & V_31 -> V_54 ) ;
V_31 -> V_55 . V_56 =
F_23 ( V_94 , 0x01 ) |
F_23 ( V_95 , 0x01 ) |
F_23 ( V_96 , 0x01 ) ;
V_31 -> V_55 . V_56 |= F_23 ( V_57 , 0x01 ) ;
V_31 -> V_55 . V_82 = 0 ;
V_31 -> V_55 . V_97 =
F_23 ( V_98 , 0x01 ) |
F_23 ( V_99 , 0x1 ) ;
V_31 -> V_55 . V_72 = F_23 ( V_100 ,
V_50 ) ;
memcpy ( & V_53 , & V_31 -> V_55 , sizeof( V_53 ) ) ;
F_24 ( & V_31 -> V_54 ) ;
V_11 = F_15 ( V_31 -> V_17 , V_58 ,
& V_53 . V_56 , sizeof( V_53 ) ,
V_59 ) ;
if ( V_11 )
F_19 ( L_36 ,
V_11 ) ;
return V_11 ;
}
int F_40 ( struct V_30 * V_31 )
{
struct V_52 V_53 ;
F_22 ( & V_31 -> V_54 ) ;
V_31 -> V_55 . V_56 = 0 ;
V_31 -> V_55 . V_82 = 0 ;
V_31 -> V_55 . V_97 = 0 ;
V_31 -> V_55 . V_72 = 0 ;
memcpy ( & V_53 , & V_31 -> V_55 , sizeof( V_53 ) ) ;
F_24 ( & V_31 -> V_54 ) ;
return F_15 ( V_31 -> V_17 , V_58 ,
& V_53 . V_56 , sizeof( V_53 ) ,
V_59 ) ;
}
int F_41 ( struct V_30 * V_31 )
{
int V_11 = 0 ;
F_40 ( V_31 ) ;
F_42 ( V_31 -> V_17 ) ;
V_11 = F_39 ( V_31 ) ;
return V_11 ;
}
int F_43 ( struct V_30 * V_31 )
{
F_44 ( V_31 -> V_17 ) ;
return F_40 ( V_31 ) ;
}
int F_45 ( struct V_30 * V_31 )
{
int V_11 = 0 ;
F_46 ( & V_31 -> V_54 ) ;
V_31 -> V_87 -> V_101 = V_31 -> V_17 -> V_64 . V_102 ;
if ( ( V_31 -> V_87 -> V_101 & ( V_31 -> V_87 -> V_101 - 1 ) ) != 0 ) {
F_29 ( 1 ) ;
V_11 = - V_103 ;
goto V_104;
}
V_31 -> V_87 -> V_105 = V_31 -> V_87 -> V_101 - 1 ;
F_3 ( V_14 , L_37 ,
V_31 -> V_87 -> V_101 , V_31 -> V_17 -> V_64 . V_65 ) ;
V_11 = F_40 ( V_31 ) ;
V_104:
return V_11 ;
}
